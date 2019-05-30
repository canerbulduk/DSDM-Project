-- ==============================================================
-- File generated on Thu May 30 06:13:47 +0200 2019
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity range_red_logtabljbC_rom is 
    generic(
             DWIDTH     : integer := 60; 
             AWIDTH     : integer := 4; 
             MEM_SIZE    : integer := 16
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of range_red_logtabljbC_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "000000000000000000000000000000000000000000000000000000000000", 
    1 => "010000000000001010101010110010101010110001000100010110011001", 
    2 => "010000000100100000001010001000011000010100001001100101101001", 
    3 => "010000010100110110100011100010001110001001101100110001111100", 
    4 => "010000111001001111010111001100111101110000111000010101010011", 
    5 => "010001111001101100110101100100011011101110111000101110000001", 
    6 => "010011011110010001111111011001100010100011110001101001010111", 
    7 => "010101101111000010100101111000010110011011111010110110000100", 
    8 => "011000110100000011001010101110001001111110001111111000010011", 
    9 => "011100110101011001000000001111100011110111011110011100000010", 
    10 => "100001111011001010001001011110100101100010011110100100010001", 
    11 => "101000001101011101011010010000110010101110000000011000110100", 
    12 => "101111110100011010010111010101011001111111111010110110101110", 
    13 => "111000111000001001010110011011011110010110000111001001101001", 
    14 => "000011100000110011011110011000000001100101010100010111011111", 
    15 => "001111110110100010100111001100001111110101111111001001110100" );

attribute syn_rom_style : string;
attribute syn_rom_style of mem : signal is "select_rom";
attribute ROM_STYLE : string;
attribute ROM_STYLE of mem : signal is "distributed";

begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity range_red_logtabljbC is
    generic (
        DataWidth : INTEGER := 60;
        AddressRange : INTEGER := 16;
        AddressWidth : INTEGER := 4);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of range_red_logtabljbC is
    component range_red_logtabljbC_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    range_red_logtabljbC_rom_U :  component range_red_logtabljbC_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


