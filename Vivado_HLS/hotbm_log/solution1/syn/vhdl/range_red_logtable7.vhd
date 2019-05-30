-- ==============================================================
-- File generated on Thu May 30 19:18:47 +0200 2019
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity range_red_logtable7_rom is 
    generic(
             DWIDTH     : integer := 61; 
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


architecture rtl of range_red_logtable7_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "0000000000000000000000000000000000000000000000000000000000000", 
    1 => "0000100000000000000000000000000010000000000000000000000000001", 
    2 => "0001100000000000000000000000010010000000000000000000000100100", 
    3 => "0010100000000000000000000000110010000000000000000000010100110", 
    4 => "0011100000000000000000000001100010000000000000000000111001001", 
    5 => "0100100000000000000000000010100010000000000000000001111001100", 
    6 => "0101100000000000000000000011110010000000000000000011011101110", 
    7 => "0110100000000000000000000101010010000000000000000101101110001", 
    8 => "0111100000000000000000000111000010000000000000001000110010100", 
    9 => "1000100000000000000000001001000010000000000000001100110010110", 
    10 => "1001100000000000000000001011010010000000000000010001110111001", 
    11 => "1010100000000000000000001101110010000000000000011000000111100", 
    12 => "1011100000000000000000010000100010000000000000011111101011110", 
    13 => "1100100000000000000000010011100010000000000000101000101100001", 
    14 => "1101100000000000000000010110110010000000000000110011010000100", 
    15 => "1110100000000000000000011010010010000000000000111111100000110" );

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

entity range_red_logtable7 is
    generic (
        DataWidth : INTEGER := 61;
        AddressRange : INTEGER := 16;
        AddressWidth : INTEGER := 4);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of range_red_logtable7 is
    component range_red_logtable7_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    range_red_logtable7_rom_U :  component range_red_logtable7_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


