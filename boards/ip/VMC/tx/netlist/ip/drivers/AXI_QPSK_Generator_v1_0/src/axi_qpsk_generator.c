#include "axi_qpsk_generator.h"
#ifndef __linux__
int axi_qpsk_generator_CfgInitialize(axi_qpsk_generator *InstancePtr, axi_qpsk_generator_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->axi_qpsk_generator_BaseAddress = ConfigPtr->axi_qpsk_generator_BaseAddress;

    InstancePtr->IsReady = 1;
    return XST_SUCCESS;
}
#endif
void axi_qpsk_generator_rf_ch_sel_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 72, Data);
}
u32 axi_qpsk_generator_rf_ch_sel_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 72);
    return Data;
}
void axi_qpsk_generator_transfertime_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 60, Data);
}
u32 axi_qpsk_generator_transfertime_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 60);
    return Data;
}
void axi_qpsk_generator_transfersymbol_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 0, Data);
}
u32 axi_qpsk_generator_transfersymbol_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 0);
    return Data;
}
void axi_qpsk_generator_transferfft_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 4, Data);
}
u32 axi_qpsk_generator_transferfft_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 4);
    return Data;
}
void axi_qpsk_generator_simulateinterface_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 64, Data);
}
u32 axi_qpsk_generator_simulateinterface_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 64);
    return Data;
}
void axi_qpsk_generator_resettime_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 48, Data);
}
u32 axi_qpsk_generator_resettime_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 48);
    return Data;
}
void axi_qpsk_generator_resetsymbol_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 8, Data);
}
u32 axi_qpsk_generator_resetsymbol_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 8);
    return Data;
}
void axi_qpsk_generator_resetfft_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 12, Data);
}
u32 axi_qpsk_generator_resetfft_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 12);
    return Data;
}
void axi_qpsk_generator_packetsizetime_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 52, Data);
}
u32 axi_qpsk_generator_packetsizetime_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 52);
    return Data;
}
void axi_qpsk_generator_packetsizesymbol_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 16, Data);
}
u32 axi_qpsk_generator_packetsizesymbol_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 16);
    return Data;
}
void axi_qpsk_generator_packetsizerf_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 20, Data);
}
u32 axi_qpsk_generator_packetsizerf_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 20);
    return Data;
}
void axi_qpsk_generator_packetsizefft_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 24, Data);
}
u32 axi_qpsk_generator_packetsizefft_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 24);
    return Data;
}
void axi_qpsk_generator_outputgain_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 44, Data);
}
u32 axi_qpsk_generator_outputgain_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 44);
    return Data;
}
void axi_qpsk_generator_lfsr_rst_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 28, Data);
}
u32 axi_qpsk_generator_lfsr_rst_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 28);
    return Data;
}
void axi_qpsk_generator_enable_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 32, Data);
}
u32 axi_qpsk_generator_enable_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 32);
    return Data;
}
void axi_qpsk_generator_bypassgain_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 68, Data);
}
u32 axi_qpsk_generator_bypassgain_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 68);
    return Data;
}
void axi_qpsk_generator_autorestarttime_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 56, Data);
}
u32 axi_qpsk_generator_autorestarttime_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 56);
    return Data;
}
void axi_qpsk_generator_autorestartsymbol_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 36, Data);
}
u32 axi_qpsk_generator_autorestartsymbol_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 36);
    return Data;
}
void axi_qpsk_generator_autorestartfft_write(axi_qpsk_generator *InstancePtr, u32 Data) {

    Xil_AssertVoid(InstancePtr != NULL);

    axi_qpsk_generator_WriteReg(InstancePtr->axi_qpsk_generator_BaseAddress, 40, Data);
}
u32 axi_qpsk_generator_autorestartfft_read(axi_qpsk_generator *InstancePtr) {

    u32 Data;
    Xil_AssertVoid(InstancePtr != NULL);

    Data = axi_qpsk_generator_ReadReg(InstancePtr->axi_qpsk_generator_BaseAddress, 40);
    return Data;
}
