proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "axi_qpsk_generator" "NUM_INSTANCES" "DEVICE_ID" "C_AXI_QPSK_GENERATOR_S_AXI_BASEADDR" "C_AXI_QPSK_GENERATOR_S_AXI_HIGHADDR" 
    xdefine_config_file $drv_handle "axi_qpsk_generator_g.c" "axi_qpsk_generator" "DEVICE_ID" "C_AXI_QPSK_GENERATOR_S_AXI_BASEADDR" 
    xdefine_canonical_xpars $drv_handle "xparameters.h" "axi_qpsk_generator" "DEVICE_ID" "C_AXI_QPSK_GENERATOR_S_AXI_BASEADDR" "C_AXI_QPSK_GENERATOR_S_AXI_HIGHADDR" 

}