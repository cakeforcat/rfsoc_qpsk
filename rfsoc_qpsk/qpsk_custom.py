from pynq import DefaultIP
from pynq import DefaultHierarchy
from pynq import allocate
import numpy as np


class QPSKcustom(DefaultHierarchy):
    def __init__(self, description):
        """Driver for our QPSK custom IP hierarchy

        This encompasses the qpsk custom logic and the DMAs for data
        transfer of exposed signals.
        """

        super().__init__(description)

        self.buf_stft = allocate(shape=(2048, ), dtype=np.int32)
        self.buf_finn = allocate(shape=(1048, ), dtype=np.uint16)

    def get_shaped_stft(self):
        """Get a single buffer of STFT data from the pulse shaped signal
        """
        def conv(raw):
            return raw / (2 ** 24)
        self.axi_dma_1.recvchannel.transfer(self.buf_stft)
        self.axi_dma_1.recvchannel.wait()
        raw = np.array(self.buf_stft)
        return np.array([conv(e) for e in raw])

    def get_shaped_finn(self):
        """Get a single buffer of time domain data from the finn??
        """
        self.axi_dma.recvchannel.transfer(self.buf_time)
        self.axi_dma.recvchannel.wait()
        return np.array(self.buf_finn)


    def get_many_stft(self, N=10):
        """Get N buffers of stft frames
        """
        return np.concatenate([self.get_shaped_stft() for i in range(N)])

    @staticmethod
    def checkhierarchy(description):
        if 'dma_tx_fft' in description['ip'] \
           and 'axi_dma' in description['ip'] \
           and 'axi_dma_1' in description['ip']:
            return True
        return False

class QPSKFINNCore(DefaultIP):
    """Driver for FINN IP
    """

    def __init__(self, description):
        super().__init__(description=description)

    bindto = ['CoRSoC:VMC:tlast_counter:1.0']

class QPSKSTFTCore(DefaultIP):
    """Driver for STFT
    """

    def __init__(self, description):
        super().__init__(description=description)

    bindto = ['CoRSoC:VMC:STFT:1.0']