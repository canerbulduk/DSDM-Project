-- ==============================================================
-- File generated on Thu May 30 06:13:48 +0200 2019
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity range_red_logtablkbM_rom is 
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


architecture rtl of range_red_logtablkbM_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "000000000000000000000000000000000000000000000000000000000000", 
    1 => "000000010000000000000001010101010101011101010101010110001000", 
    2 => "000010010000000000100100000000001010001000000011000010011010", 
    3 => "000110010000000010100110101011111000110011010001101110111111", 
    4 => "001100010000000111001001011010000001100000100111011101010100", 
    5 => "010100010000001111001100001100110100010011100010010010000000", 
    6 => "011110010000011011101111000111010001010010001000010111100001", 
    7 => "101010010000101101110010001101001000100101111000000001111101", 
    8 => "111000010001000110010101100010111010011100010111110011110101", 
    9 => "001000010001100110011001001101110111001000000110100011100100", 
    10 => "011010010010001110111101010011111111000001001011100010001010", 
    11 => "101110010011000001000001111100000010100110000110100010101011", 
    12 => "000100010011111101100111001101100010011100100000000010101011", 
    13 => "011100010101000101101101010000101111010001111001010011101000", 
    14 => "110110010110011010010100001110101001111100011100100101010000", 
    15 => "010010010111111100011100010001000011011011101101010000110000" );

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

entity range_red_logtablkbM is
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

architecture arch of range_red_logtablkbM is
    component range_red_logtablkbM_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    range_red_logtablkbM_rom_U :  component range_red_logtablkbM_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


