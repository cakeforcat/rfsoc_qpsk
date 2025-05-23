# CoRSoC fork of the QPSK transceiver project
This repository is a fork of the project, as used for baseband modulation and demodulation inside the [CoRSoC](https://github.com/cakeforcat/CoRSoC) project.
The main additions include:
* an updated `iprepo` directory, with additional shims and IPs built with Vitis Model Composer
* modified overlay driver for the ZCU111, with higher default frequencies for NCOs and samplers
* port of the tx IP to VMC from SysGen
* missing interpolation and decimation filters extracted from the built IPI, ported to the filter gen script

It is not recommended to use this repository as is. It was used as a support repository for the CoRSoC project
<img src="strathsdr_banner.png" width="100%">

<table border="0" align="center">
    <tr border="0">
        <td align="center" width="50%" border="0">
            <img src="https://www.rfsocbook.com/wp-content/uploads/2022/12/RFSoC3D_v4-1433x1536.png" alt="oscthumb" style="width: 60%" border="0"/>
        </td>
        <td align="center" width="50%" border="0">
            <font size=7><b>Available Now!</b></font size> <br> <font size=5>Software Defined Radio with Zynq® UltraScale+ RFSoC</font size> <br> <font size=4><a href="https://rfsocbook.com/">Free Download</a> <br><a href="https://www.amazon.com/Software-Defined-Radio-Ultrascale-RFSoC/dp/1739588606?keywords=zynq+rfsoc&qid=1673452844&sprefix=%2Caps%2C137&sr=8-1&linkCode=ll1&tag=thzybo-20&linkId=0bf245a543fd4af4625086df4c190928&language=en_US&ref_=as_li_ss_tl">Printed Edition</a></font size>
        </td>
    </tr>
</table>

# RFSoC QPSK Transceiver
This repository is only compatible with [PYNQ images v2.7](https://github.com/Xilinx/PYNQ/releases) and greater for the following RFSoC development boards:
* [ZCU208](https://www.xilinx.com/products/boards-and-kits/zcu208.html),
* [ZCU216](https://www.xilinx.com/products/boards-and-kits/zcu216.html),
* [ZCU111](https://www.xilinx.com/products/boards-and-kits/zcu111.html),
* [RFSoC4x2](http://rfsoc-pynq.io/), 
* [RFSoC2x2](http://rfsoc-pynq.io/).

## Introduction
This repo contains all the files needed to build and run the RFSoC QPSK demonstrator that was published in [IEEE Access](https://ieeexplore.ieee.org/document/9139483) and was presented at both [FPL](https://fpl2018.org/) and [XDF](http://www.xilinx.com/xdf) conferences in 2018. The design is a full QPSK transceiver, which transmits and receives randomly-generated pulse-shaped symbols with full carrier and timing synchronisation. [PYNQ](https://github.com/xilinx/pynq) is used to visualise the data at both the DAC and ADC side of the RFSoC data converters, as well as visualising various DSP stages throughout the transmit and receive signal path.

<p align="center">
  <img src="demonstration.gif" />
<p/>

## Quick Start
Follow the instructions below to install the QPSK demonstrator on your development board. **You will need to give your board access to the internet**.
* Power on your RFSoC development board with an SD Card containing a fresh PYNQ v2.7 image or greater.
* Navigate to Jupyter Labs by opening a browser (preferably Chrome) and connecting to `http://<board_ip_address>:9090/lab`.
* We need to open a terminal in Jupyter Lab. Firstly, open a launcher window as shown in the figure below:

<p align="center">
  <img src="../master/open_jupyter_launcher.jpg" width="50%" height="50%" />
<p/>

* Now open a terminal in Jupyter as illustrated below:

<p align="center">
  <img src="../master/open_terminal_window.jpg" width="50%" height="50%" />
<p/>

* Now simply install the QPSK demonstrator through PIP by executing the following command in the terminal:

```sh
pip3 install https://github.com/strath-sdr/rfsoc_qpsk/releases/download/v1.4.5/rfsoc_qpsk.tar.gz
python -m rfsoc_qpsk install
```

Once installation has complete, you will find the QPSK demonstrator notebooks located in the jupyter home workspace in the `rfsoc_qpsk` folder.

This repository uses Voila to create simple web applications using Jupyter notebooks. Your RFSoC development board should already be preinstalled with a version of Voila and no further setup is required.

## Using the Project Files
The following software is required to use the project files in this repository.
- Vivado Design Suite 2020.2
- System Generator for DSP
- MATLAB R2020a

### System Generator
The Tx and Rx IPs are in separate directories in `rfsoc_qpsk/boards/ip/sysgen/` that can be opened using the appropriate System Generator dialogue. Due to the large amount of decimation and interpolation in both IPs, simulating the output can take an extraordinarily long time. A less extreme multirate system would simulate much faster! 

### Vivado
This project can be built with Vivado from the command line. Open Vivado 2020.2 and execute the following into the tcl console:

```sh
cd /<repository-location>/boards/<board-name>/rfsoc_qpsk/
```

Now that we have moved into the correct directory, make the Vivado project by running the make commands below sequentially.

```sh
make block_design
make bitstream
```

Alternatively, you can run the entire project build by executing the following into the tcl console:
```sh
make all
```

## License 
[BSD 3-Clause](../../blob/master/LICENSE)
