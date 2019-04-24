-- Copyright 2003-2006 Jérémie Detrey, Florent de Dinechin
--
-- This file is part of FPLibrary
--
-- FPLibrary is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- FPLibrary is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with FPLibrary; if not, write to the Free Software
-- Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

package pkg_fp_lib is

  function fp_log_latency (wE, wF : positive)
    return positive;

  component fp_log is
    generic ( wE : positive := 6;
              wF : positive := 13 );
    port ( fpX : in  std_logic_vector(2+wE+wF downto 0);
           fpR : out std_logic_vector(2+wE+wF downto 0) );
  end component;

  component fp_log_clk is
    generic ( wE : positive := 6;
              wF : positive := 13 );
    port ( fpX : in  std_logic_vector(2+wE+wF downto 0);
           fpR : out std_logic_vector(2+wE+wF downto 0);
           clk : in  std_logic );
  end component;

end package;

package body pkg_fp_lib is
  
  function fp_log_latency ( wE, wF : positive ) return positive is
    constant g     : positive := fp_log_log_g(wF+1);
    constant latD0 : positive := max(1 + mult_latency(wE, wF+3, 0, 2), fp_log_log_latency(wF+1) + mult_latency(wF+1, wF+g+2, 0, 2));
  begin
    return latD0 + 2;
  end function;
              
end package body;
