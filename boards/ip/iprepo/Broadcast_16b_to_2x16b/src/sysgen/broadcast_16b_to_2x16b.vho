  sysgen_dut : entity xil_defaultlib.broadcast_16b_to_2x16b 
  port map (
    m_0_axis_tready => m_0_axis_tready,
    m_1_axis_tready => m_1_axis_tready,
    s_axis_tdata => s_axis_tdata,
    s_axis_tvalid => s_axis_tvalid,
    clk => clk,
    m_0_axis_tdata => m_0_axis_tdata,
    m_0_axis_tvalid => m_0_axis_tvalid,
    m_1_axis_tdata => m_1_axis_tdata,
    m_1_axis_tvalid => m_1_axis_tvalid,
    s_axis_tready => s_axis_tready
  );
