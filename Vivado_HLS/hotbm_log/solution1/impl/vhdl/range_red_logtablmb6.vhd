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

entity range_red_logtablmb6_rom is 
    generic(
             DWIDTH     : integer := 50; 
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


architecture rtl of range_red_logtablmb6_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "00000000000000000000000000000000000000000000000000", 
    1 => "00000000010000000000000000000001010101010101010101", 
    2 => "00000010010000000000000000100100000000000000001010", 
    3 => "00000110010000000000000010100110101010101011111000", 
    4 => "00001100010000000000000111001001010101011010000001", 
    5 => "00010100010000000000001111001100000000001100110100", 
    6 => "00011110010000000000011011101110101011000111010000", 
    7 => "00101010010000000000101101110001010110001101000111", 
    8 => "00111000010000000001000110010100000001100010111000", 
    9 => "01001000010000000001100110010110101101001101110010", 
    10 => "01011010010000000010001110111001011001010011110111", 
    11 => "01101110010000000011000000111100000101111011110110", 
    12 => "10000100010000000011111101011110110011001101001111", 
    13 => "10011100010000000101000101100001100001010000010001", 
    14 => "10110110010000000110011010000100010000001101111110", 
    15 => "11010010010000000111111100000111000000010000000101" );

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

entity range_red_logtablmb6 is
    generic (
        DataWidth : INTEGER := 50;
        AddressRange : INTEGER := 16;
        AddressWidth : INTEGER := 4);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of range_red_logtablmb6 is
    component range_red_logtablmb6_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    range_red_logtablmb6_rom_U :  component range_red_logtablmb6_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


