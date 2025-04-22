  sysgen_dut : entity xil_defaultlib.finn_convert 
  port map (
    m_axis_tready => m_axis_tready,
    s_i_axis_tdata => s_i_axis_tdata,
    s_i_axis_tvalid => s_i_axis_tvalid,
    s_q_axis_tdata => s_q_axis_tdata,
    s_q_axis_tvalid => s_q_axis_tvalid,
    m_full_axis_tready => m_full_axis_tready,
    clk => clk,
    m_axis_tdata => m_axis_tdata,
    m_axis_tvalid => m_axis_tvalid,
    s_i_axis_tready => s_i_axis_tready,
    s_q_axis_tready => s_q_axis_tready,
    m_full_axis_tdata => m_full_axis_tdata,
    m_full_axis_tvalid => m_full_axis_tvalid
  );
