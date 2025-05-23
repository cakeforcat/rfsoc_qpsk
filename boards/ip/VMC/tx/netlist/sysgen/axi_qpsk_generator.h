#ifndef AXI_QPSK_GENERATOR__H
#define AXI_QPSK_GENERATOR__H
#ifdef __cplusplus
extern "C" {
#endif
/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "axi_qpsk_generator_hw.h"
/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 axi_qpsk_generator_BaseAddress;
} axi_qpsk_generator_Config;
#endif
/**
* The axi_qpsk_generator driver instance data. The user is required to
* allocate a variable of this type for every axi_qpsk_generator device in the system.
* A pointer to a variable of this type is then passed to the driver
* API functions.
*/
typedef struct {
    u32 axi_qpsk_generator_BaseAddress;
    u32 IsReady;
} axi_qpsk_generator;
/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define axi_qpsk_generator_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define axi_qpsk_generator_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define axi_qpsk_generator_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define axi_qpsk_generator_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif
/************************** Function Prototypes *****************************/
#ifndef __linux__
int axi_qpsk_generator_Initialize(axi_qpsk_generator *InstancePtr, u16 DeviceId);
axi_qpsk_generator_Config* axi_qpsk_generator_LookupConfig(u16 DeviceId);
int axi_qpsk_generator_CfgInitialize(axi_qpsk_generator *InstancePtr, axi_qpsk_generator_Config *ConfigPtr);
#else
int axi_qpsk_generator_Initialize(axi_qpsk_generator *InstancePtr, const char* InstanceName);
int axi_qpsk_generator_Release(axi_qpsk_generator *InstancePtr);
#endif
/**
* Write to rf_ch_sel gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the rf_ch_sel instance to operate on.
* @param	Data is value to be written to gateway rf_ch_sel.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_rf_ch_sel_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from rf_ch_sel gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the rf_ch_sel instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_rf_ch_sel_read(axi_qpsk_generator *InstancePtr);
/**
* Write to transfertime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transfertime instance to operate on.
* @param	Data is value to be written to gateway transfertime.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_transfertime_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from transfertime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transfertime instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_transfertime_read(axi_qpsk_generator *InstancePtr);
/**
* Write to transfersymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transfersymbol instance to operate on.
* @param	Data is value to be written to gateway transfersymbol.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_transfersymbol_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from transfersymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transfersymbol instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_transfersymbol_read(axi_qpsk_generator *InstancePtr);
/**
* Write to transferfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transferfft instance to operate on.
* @param	Data is value to be written to gateway transferfft.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_transferfft_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from transferfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the transferfft instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_transferfft_read(axi_qpsk_generator *InstancePtr);
/**
* Write to simulateinterface gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the simulateinterface instance to operate on.
* @param	Data is value to be written to gateway simulateinterface.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_simulateinterface_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from simulateinterface gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the simulateinterface instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_simulateinterface_read(axi_qpsk_generator *InstancePtr);
/**
* Write to resettime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resettime instance to operate on.
* @param	Data is value to be written to gateway resettime.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_resettime_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from resettime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resettime instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_resettime_read(axi_qpsk_generator *InstancePtr);
/**
* Write to resetsymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resetsymbol instance to operate on.
* @param	Data is value to be written to gateway resetsymbol.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_resetsymbol_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from resetsymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resetsymbol instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_resetsymbol_read(axi_qpsk_generator *InstancePtr);
/**
* Write to resetfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resetfft instance to operate on.
* @param	Data is value to be written to gateway resetfft.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_resetfft_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from resetfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the resetfft instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_resetfft_read(axi_qpsk_generator *InstancePtr);
/**
* Write to packetsizetime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizetime instance to operate on.
* @param	Data is value to be written to gateway packetsizetime.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_packetsizetime_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from packetsizetime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizetime instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_packetsizetime_read(axi_qpsk_generator *InstancePtr);
/**
* Write to packetsizesymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizesymbol instance to operate on.
* @param	Data is value to be written to gateway packetsizesymbol.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_packetsizesymbol_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from packetsizesymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizesymbol instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_packetsizesymbol_read(axi_qpsk_generator *InstancePtr);
/**
* Write to packetsizerf gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizerf instance to operate on.
* @param	Data is value to be written to gateway packetsizerf.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_packetsizerf_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from packetsizerf gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizerf instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_packetsizerf_read(axi_qpsk_generator *InstancePtr);
/**
* Write to packetsizefft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizefft instance to operate on.
* @param	Data is value to be written to gateway packetsizefft.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_packetsizefft_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from packetsizefft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the packetsizefft instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_packetsizefft_read(axi_qpsk_generator *InstancePtr);
/**
* Write to outputgain gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the outputgain instance to operate on.
* @param	Data is value to be written to gateway outputgain.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_outputgain_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from outputgain gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the outputgain instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_outputgain_read(axi_qpsk_generator *InstancePtr);
/**
* Write to lfsr_rst gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the lfsr_rst instance to operate on.
* @param	Data is value to be written to gateway lfsr_rst.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_lfsr_rst_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from lfsr_rst gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the lfsr_rst instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_lfsr_rst_read(axi_qpsk_generator *InstancePtr);
/**
* Write to enable gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the enable instance to operate on.
* @param	Data is value to be written to gateway enable.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_enable_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from enable gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the enable instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_enable_read(axi_qpsk_generator *InstancePtr);
/**
* Write to bypassgain gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the bypassgain instance to operate on.
* @param	Data is value to be written to gateway bypassgain.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_bypassgain_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from bypassgain gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the bypassgain instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_bypassgain_read(axi_qpsk_generator *InstancePtr);
/**
* Write to autorestarttime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestarttime instance to operate on.
* @param	Data is value to be written to gateway autorestarttime.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_autorestarttime_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from autorestarttime gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestarttime instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_autorestarttime_read(axi_qpsk_generator *InstancePtr);
/**
* Write to autorestartsymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestartsymbol instance to operate on.
* @param	Data is value to be written to gateway autorestartsymbol.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_autorestartsymbol_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from autorestartsymbol gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestartsymbol instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_autorestartsymbol_read(axi_qpsk_generator *InstancePtr);
/**
* Write to autorestartfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestartfft instance to operate on.
* @param	Data is value to be written to gateway autorestartfft.
*
* @return	None.
*
* @note    .
*
*/
void axi_qpsk_generator_autorestartfft_write(axi_qpsk_generator *InstancePtr, u32 Data);
/**
* Read from autorestartfft gateway of axi_qpsk_generator. Assignments are LSB-justified.
*
* @param	InstancePtr is the autorestartfft instance to operate on.
*
* @return	u32
*
* @note    .
*
*/
u32 axi_qpsk_generator_autorestartfft_read(axi_qpsk_generator *InstancePtr);
#ifdef __cplusplus
}
#endif
#endif
