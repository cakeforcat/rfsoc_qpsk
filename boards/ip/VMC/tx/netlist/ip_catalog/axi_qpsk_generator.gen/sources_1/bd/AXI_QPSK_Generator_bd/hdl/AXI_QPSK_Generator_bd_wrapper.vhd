--Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
--Copyright 2022-2024 Advanced Micro Devices, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2024.1 (win64) Build 5076996 Wed May 22 18:37:14 MDT 2024
--Date        : Wed Feb 19 17:06:32 2025
--Host        : Laptopiszcze running 64-bit major release  (build 9200)
--Command     : generate_target AXI_QPSK_Generator_bd_wrapper.bd
--Design      : AXI_QPSK_Generator_bd_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity AXI_QPSK_Generator_bd_wrapper is
  port (
    CLK_IN1_D_clk_n : in STD_LOGIC;
    CLK_IN1_D_clk_p : in STD_LOGIC;
    m_fft_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_fft_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_fft_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_fft_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf0_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf1_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf2_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf3_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tdata : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_symbol_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_time_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    reset_rtl : in STD_LOGIC
  );
end AXI_QPSK_Generator_bd_wrapper;

architecture STRUCTURE of AXI_QPSK_Generator_bd_wrapper is
  component AXI_QPSK_Generator_bd is
  port (
    CLK_IN1_D_clk_n : in STD_LOGIC;
    CLK_IN1_D_clk_p : in STD_LOGIC;
    reset_rtl : in STD_LOGIC;
    m_fft_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_fft_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_fft_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_fft_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf0_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf0_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf1_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf1_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf2_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf2_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_rf3_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_rf3_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tdata : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_symbol_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_symbol_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tdata : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_time_axis_tlast : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tvalid : out STD_LOGIC_VECTOR ( 0 to 0 );
    m_time_axis_tready : in STD_LOGIC_VECTOR ( 0 to 0 )
  );
  end component AXI_QPSK_Generator_bd;
begin
AXI_QPSK_Generator_bd_i: component AXI_QPSK_Generator_bd
     port map (
      CLK_IN1_D_clk_n => CLK_IN1_D_clk_n,
      CLK_IN1_D_clk_p => CLK_IN1_D_clk_p,
      m_fft_axis_tdata(31 downto 0) => m_fft_axis_tdata(31 downto 0),
      m_fft_axis_tlast(0) => m_fft_axis_tlast(0),
      m_fft_axis_tready(0) => m_fft_axis_tready(0),
      m_fft_axis_tvalid(0) => m_fft_axis_tvalid(0),
      m_rf0_axis_tdata(31 downto 0) => m_rf0_axis_tdata(31 downto 0),
      m_rf0_axis_tlast(0) => m_rf0_axis_tlast(0),
      m_rf0_axis_tready(0) => m_rf0_axis_tready(0),
      m_rf0_axis_tvalid(0) => m_rf0_axis_tvalid(0),
      m_rf1_axis_tdata(31 downto 0) => m_rf1_axis_tdata(31 downto 0),
      m_rf1_axis_tlast(0) => m_rf1_axis_tlast(0),
      m_rf1_axis_tready(0) => m_rf1_axis_tready(0),
      m_rf1_axis_tvalid(0) => m_rf1_axis_tvalid(0),
      m_rf2_axis_tdata(31 downto 0) => m_rf2_axis_tdata(31 downto 0),
      m_rf2_axis_tlast(0) => m_rf2_axis_tlast(0),
      m_rf2_axis_tready(0) => m_rf2_axis_tready(0),
      m_rf2_axis_tvalid(0) => m_rf2_axis_tvalid(0),
      m_rf3_axis_tdata(31 downto 0) => m_rf3_axis_tdata(31 downto 0),
      m_rf3_axis_tlast(0) => m_rf3_axis_tlast(0),
      m_rf3_axis_tready(0) => m_rf3_axis_tready(0),
      m_rf3_axis_tvalid(0) => m_rf3_axis_tvalid(0),
      m_symbol_axis_tdata(7 downto 0) => m_symbol_axis_tdata(7 downto 0),
      m_symbol_axis_tlast(0) => m_symbol_axis_tlast(0),
      m_symbol_axis_tready(0) => m_symbol_axis_tready(0),
      m_symbol_axis_tvalid(0) => m_symbol_axis_tvalid(0),
      m_time_axis_tdata(31 downto 0) => m_time_axis_tdata(31 downto 0),
      m_time_axis_tlast(0) => m_time_axis_tlast(0),
      m_time_axis_tready(0) => m_time_axis_tready(0),
      m_time_axis_tvalid(0) => m_time_axis_tvalid(0),
      reset_rtl => reset_rtl
    );
end STRUCTURE;
