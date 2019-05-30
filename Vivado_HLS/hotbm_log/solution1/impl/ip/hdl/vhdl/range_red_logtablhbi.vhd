-- ==============================================================
-- File generated on Thu May 30 19:18:46 +0200 2019
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity range_red_logtablhbi_rom is 
    generic(
             DWIDTH     : integer := 60; 
             AWIDTH     : integer := 5; 
             MEM_SIZE    : integer := 32
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of range_red_logtablhbi_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 1=> "000000000000000000000000000000000000000000000000000000000000", 
    2 => "011000100111100111010001000100010001110000000101110011110001", 
    3 => "010110101100111100011101000000110100010001010001111111101100", 
    4 => "001011101010110010100100110001000101011100001110101011110101", 
    5 => "100000100010011111100100011110111101111000110011100010110100", 
    6 to 7=> "011010110101010000111101101100011111101110000010100100101110", 
    8 => "001111001000101011011001111000110110111100101011111010100111", 
    9 to 10=> "011011001011001110110011011110010111110110011001010000011001", 
    11 to 12=> "001000100110100110110111001001001111000001110111110101101110", 
    13 to 14=> "000011100111000101000111101011111001110000100000010110010011", 
    15 => "011101111011000000101010001101111101101111001101111110110110", 
    16 => "100010100011110111000101100111101100011110100110011011011101", 
    17 => "101010001010100010110011111000111111100011000110011100000110", 
    18 to 19=> "100100101010000111000001110101010111001010101010101110011010", 
    20 => "001110000110010101100101110111100101001111011010001001111111", 
    21 => "011000110000101110101001010010111000100110111110110011111001", 
    22 to 23=> "100011110101100001101100001011000011011110001100000111100000", 
    24 => "000001111110000000001010110111001011001111111010001000111001", 
    25 to 26=> "010010001110101010000110100011010000101100001010101111000001", 
    27 to 28=> "101110101000110101001010010110100011001000001101101100110011", 
    29 to 30=> "110011111111101110100111010101100110011110100000110011011011", 
    31 => "100111100011000011111001100111111111011001100000111000001000" );


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

entity range_red_logtablhbi is
    generic (
        DataWidth : INTEGER := 60;
        AddressRange : INTEGER := 32;
        AddressWidth : INTEGER := 5);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of range_red_logtablhbi is
    component range_red_logtablhbi_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    range_red_logtablhbi_rom_U :  component range_red_logtablhbi_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


