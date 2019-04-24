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

-- TODO manage underflow for exotic values of wE/wF


library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

package pkg_fp_log is

  function min ( x, y : integer )
    return integer;

  function max ( x, y : integer )
    return integer;
  
  function intlog2 ( x : positive )
    return integer;
 
end package;









package body pkg_fp_log is


  function min ( x, y : integer ) return integer is
  begin
    if x <= y then
      return x;
    else
      return y;
    end if;
  end function;

  
  function max ( x, y : integer ) return integer is
  begin
    if x >= y then
      return x;
    else
      return y;
    end if;
  end function;

  
  function intlog2 ( x : positive ) return integer is
    variable n : natural := 0;
    variable p2 : natural := 1;
  begin
    while x >= p2 loop
      n := n+1;
      p2:=p2*2;
    end loop;
    return n;
  end function;



end package body;






-------------------------------------------------------------------------------
-- Leading-zero/one counter
--
-- Generics:
--   - w : width of the input operand
--   - n : number of LZC and shifting stages (width of the signal zo)
--
-- Ports:
--   - i [in]  : input signal
--   - ozb[in] : what to count (zeroes or ones)
--   - zo [out] : number of leading zeros
--
-- Recursive structure with n stages. At most 2^n-1 leading zeros are counted.
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.pkg_fp_log.all;

  entity lzoc is
    generic ( w : positive;
              n : positive );
    port ( i : in  std_logic_vector(w-1 downto 0);
         ozb : in std_logic;
          zo : out std_logic_vector(n-1 downto 0) );
  end entity;

  architecture arch of lzoc is
  component lzoc is
    generic ( w : positive;
              n : positive );
    port ( i : in  std_logic_vector(w-1 downto 0);
         ozb : in std_logic;
          zo : out std_logic_vector(n-1 downto 0) );
  end component;
  signal z0 : std_logic;
  signal o0 : std_logic_vector(w-1 downto 0);
begin
---------------------------------------------- Test 2^(n-1) leading zeros

  z0 <= '1' when i(w-1 downto w-2**(n-1)) = (w-1 downto w-2**(n-1) => ozb ) else
        '0';

  o0 <= i                                                    when z0 = '0' else
        i(w-2**(n-1)-1 downto 0) & (2**(n-1)-1 downto 0 => '0');

  zo(n-1) <= z0;
  

  ------------------------------------------------------------- Recursive stage

  recursive : if n > 1 generate
    lzoc0 : lzoc
      generic map ( w => w,
                    n => n-1 )
      port map (  i => o0,
                  ozb=>ozb,
                  zo => zo(n-2 downto 0)         );
  end generate;


end architecture; -------------------------------------------------------------






-------------------------------------------------------------------------------
-- Left barrel shifter
--
-- Generics:
--   - w : width of the input operand
--   - n : number of shifting stages (width of the signal s)
--
-- Ports:
--   - i [in]  : input signal
--   - s [in]  : shift by s
--   - o [out] :  output
--
-- Recursive structure with n stages.
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.pkg_fp_log.all;

entity lshift is
  generic ( w : positive;
            n : positive );
  port ( i  : in  std_logic_vector(w-1 downto 0);
         s  : in std_logic_vector(n-1 downto 0);
         o  : out std_logic_vector(w-1 downto 0));
end entity;

architecture arch of lshift is
  component lshift is
  generic ( w : positive;
            n : positive );
  port ( i  : in  std_logic_vector(w-1 downto 0);
         s  : in std_logic_vector(n-1 downto 0);
         o  : out std_logic_vector(w-1 downto 0));
  end component;
  signal o0 : std_logic_vector(w-1 downto 0);
begin

  check1: if 2**(n-1)>=w generate
    o0 <=      i                      when s(n-1) = '0'
          else (w-1 downto 0 => '0');
  end generate;
  check2: if 2**(n-1)<w generate
    o0 <= i   when s(n-1) = '0' else
          i(w-2**(n-1)-1 downto 0) & (2**(n-1)-1 downto 0 => '0');
  end generate;
  
  ------------------------------------------------------------- Recursive stage

  recursive : if n > 1 generate
    shift0 : lshift
      generic map ( w => w,
                    n => n-1 )
      port map (  i => o0,
                  s => s(n-2 downto 0),
                  o => o   );
  end generate;

  ----------------------------------------------------------------- Final stage
  single : if n = 1 generate
    o <= o0;
  end generate;

end architecture; -------------------------------------------------------------








-------------------------------------------------------------------------------
-- Right barrel shifter
--
-- Generics:
--   - w : width of the input operand
--   - n : number of shifting stages (width of the signal s)
--
-- Ports:
--   - i [in]  : input signal
--   - s [in]  : shift by s
--   - o [out] :  output
--
-- Recursive structure with n stages.
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.pkg_fp_log.all;

entity rshift is
  generic ( w : positive;
            n : positive );
  port ( i  : in  std_logic_vector(w-1 downto 0);
         s  : in std_logic_vector(n-1 downto 0);
         o  : out std_logic_vector(w-1 downto 0));
end entity;

  architecture arch of rshift is
  component rshift is
  generic ( w : positive;
            n : positive );
  port ( i  : in  std_logic_vector(w-1 downto 0);
         s  : in std_logic_vector(n-1 downto 0);
         o  : out std_logic_vector(w-1 downto 0));
  end component;
  signal o0 : std_logic_vector(w-1 downto 0);
begin

  check1: if 2**(n-1)>=w generate
    o0 <= i   when s(n-1) = '0' else
     (w-1 downto 0 => '0');
  end generate;
  check2: if 2**(n-1)<w generate
  o0 <= i   when s(n-1) = '0' else
           (w-1 downto w-2**(n-1) => '0')  &  i(w-1 downto 2**(n-1));
  end generate;
  
  ------------------------------------------------------------- Recursive stage

  recursive : if n > 1 generate
    shift0 : rshift
      generic map ( w => w,
                    n => n-1 )
      port map (  i => o0,
                  s => s(n-2 downto 0),
                  o => o   );
  end generate;

  ----------------------------------------------------------------- Final stage
  single : if n = 1 generate
    o <= o0;
  end generate;

end architecture; -------------------------------------------------------------






-------------------------------------------------------------------------------
-- Leading-zero counter and normalization
--
-- Generics:
--   - w : width of the input operand
--   - n : number of LZC and shifting stages (width of the signal z)
--
-- Ports:
--   - i [in]  : input signal
--   - z [out] : number of leading zeros
--   - o [out] : normalized signal
--
-- Recursive structure with n stages. At most 2^n-1 leading zeros are counted.
-------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.pkg_fp_log.all;

entity lzc_norm is
    generic ( w : positive;
              n : positive );
    port ( i : in  std_logic_vector(w-1 downto 0);
           z : out std_logic_vector(n-1 downto 0);
           o : out std_logic_vector(w-1 downto 0) );
end entity;

architecture arch of lzc_norm is
  component lzc_norm is
    generic ( w : positive;
              n : positive );
    port ( i : in  std_logic_vector(w-1 downto 0);
           z : out std_logic_vector(n-1 downto 0);
           o : out std_logic_vector(w-1 downto 0) );
  end component;

  signal z0 : std_logic;
  signal o0 : std_logic_vector(w-1 downto 0);
begin ---------------------------------------------- Test 2^(n-1) leading zeros
  z0 <= '1' when i(w-1 downto w-2**(n-1)) = (w-1 downto w-2**(n-1) => '0') else
        '0';

  o0 <= i                                                    when z0 = '0' else
        i(w-2**(n-1)-1 downto 0) & (2**(n-1)-1 downto 0 => '0');
   z(n-1) <= z0;
    ----------------------------------------------------------------- Final stage
  single : if n = 1 generate
    o <= o0;
  end generate;
  ------------------------------------------------------------- Recursive stage
  recursive : if n > 1 generate
    lzc_norm0 : lzc_norm
      generic map ( w => w,
                    n => n-1 )
      port map ( i => o0,
                 z => z(n-2 downto 0),
                 o => o );
  end generate;

end architecture; -------------------------------------------------------------












library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

-- Entity fp_log defined here
 
entity fp_log_8_23 is 
  generic ( wE : positive := 8;
            wF : positive := 23);
  port ( fpX : in  std_logic_vector(2+wE+wF downto 0);
         fpR : out std_logic_vector(2+wE+wF downto 0)  );
end entity;
architecture arch of fp_log_8_23 is 

  component lzoc is
    generic ( w : positive;
              n : positive );
    port ( i   : in  std_logic_vector(w-1 downto 0);
           ozb : in std_logic;
           zo  : out std_logic_vector(n-1 downto 0) );
  end component;

  component lshift is
    generic ( w : positive;
              n : positive );
    port ( i  : in  std_logic_vector(w-1 downto 0);
           s  : in std_logic_vector(n-1 downto 0);
           o  : out std_logic_vector(w-1 downto 0) );
  end component;

  component rshift is
    generic ( w : positive;
              n : positive );
    port ( i  : in  std_logic_vector(w-1 downto 0);
           s  : in std_logic_vector(n-1 downto 0);
           o  : out std_logic_vector(w-1 downto 0) );
  end component;

  component lzc_norm is
    generic ( w : positive;
              n : positive );
    port ( i : in  std_logic_vector(w-1 downto 0);
           z : out std_logic_vector(n-1 downto 0);
           o : out std_logic_vector(w-1 downto 0) );
  end component;

  -- def of component range_red, and many constants and signals,  here
  component range_red is port (
            Y0 : in  std_logic_vector(24 downto 0);
            A  : in std_logic_vector(4 downto 0);
            Z  : out std_logic_vector(25 downto 0);
    almostLog  : out std_logic_vector(38 downto 0)  );
  end component;
  constant g   : positive := 4;
  constant a0 : positive := 5;
  constant log2wF : positive := 5;
  constant targetprec : positive := 39;
  constant sfinal : positive := 26;
  constant pfinal : positive := 13;
  signal log2 : std_logic_vector(wF+g-1 downto 0) := "101100010111001000011000000";
  signal E0offset : std_logic_vector(wE-1 downto 0) := "10000110"; -- E0 + wE 
  signal pfinal_s : std_logic_vector(log2wF -1 downto 0) := "01101";
  constant lzc_size : positive := max(log2wF, intlog2(wE+pfinal+1));
  signal FirstBit : std_logic;
  signal Y0 : std_logic_vector(wF+1 downto 0);
  signal E  : std_logic_vector(wE-1 downto 0);
  signal absE  : std_logic_vector(wE-1 downto 0);
  signal absELog2  : std_logic_vector(wF+wE+g-1 downto 0);
  signal absELog2_pad, LogF_normal_pad, Log_normal, Log_normal_normd  : std_logic_vector(wE+targetprec-1 downto 0);
  signal E_small,ER  : std_logic_vector(wE-1 downto 0);
  signal E_normal  : std_logic_vector(lzc_size-1 downto 0);
  signal Log_small_normd, Log_g  : std_logic_vector(wF+g-1 downto 0);
  signal EFR  : std_logic_vector(wE+wF-1 downto 0);
  signal lzo : std_logic_vector(log2wF-1 downto 0);
  signal shiftval : std_logic_vector(log2wF downto 0);
  signal absZ0, absZ0s : std_logic_vector(wF-pfinal+1 downto 0);
  signal Zfinal, Log1p_normal : std_logic_vector(sfinal-1 downto 0);
  signal Z2o2_full: std_logic_vector(2*(sfinal-pfinal) -1 downto 0);
  signal squarerIn: std_logic_vector(sfinal-pfinal-1 downto 0);
  signal Z2o2_small_s, Z2o2: std_logic_vector(sfinal-pfinal downto 0);
  signal Log_small, Z_small, Z2o2_small: std_logic_vector(wF+g+1 downto 0);  
  signal almostLog, logF_normal : std_logic_vector(targetprec-1 downto 0);
  signal E0_sub : std_logic_vector(1 downto 0);
  signal sR, small, doRR, ufl, sticky, round: std_logic;
begin

  FirstBit <=  fpX(wF-1);
  Y0 <=      "1"  & fpX(wF-1 downto 0) & "0" when FirstBit = '0'
        else "01" & fpX(wF-1 downto 0);

  E  <= (fpX(wE+wF-1 downto wF)) - ("0" & (wE-2 downto 1 => '1') & (not FirstBit));

  sR <= '0'   when    fpX(wE+wF-1 downto wF)   =   '0' &(wE-2 downto 0 => '1')  -- binade [1..2)
        else not fpX(wE+wF-1);                -- MSB of exponent

  absE <= ((wE-1 downto 0 => '0') - E)   when sR = '1'
          else E;

  absELog2 <= absE * log2;
  
  lzoc1 : lzoc
    generic map (w => wF,  n => log2wF)
    port map (  i => Y0(wF downto 1), ozb => FirstBit,  zo => lzo);

  shiftval <= ('0' & lzo) - ('0' & pfinal_s); 

  doRR <= shiftval(log2wF);             -- sign of the result

  small <= '1' when ((E=(wE-1 downto 0 => '0')) and (doRR='0'))
          else '0';

-- The range reduction instance
  rr: range_red
     port map ( A => fpX(wF-1 downto wF-a0), Y0 => Y0,
                Z => Zfinal, almostLog => almostLog);
  absZ0 <=   Y0(wF-pfinal+1 downto 0)          when (sR='0') else
             ((wF-pfinal+1 downto 0 => '0') - Y0(wF-pfinal+1 downto 0));

--  absZ0 <=   Y0(wF-pfinal downto 0)   xor (wF-pfinal downto 0 => sR);

  lshiftsmall: lshift          
    generic map (w => wF-pfinal+2,  n => log2wF)    
    port map (  i => absZ0, s => shiftval(log2wF-1 downto 0), o => absZ0s );

  -- Z2o2 will be of size sfinal-pfinal, set squarer input size to that
  sqintest: if sfinal > wf+2 generate
    squarerIn <= Zfinal(sfinal-1 downto pfinal) when doRR='1'
                 else (absZ0s &  (sfinal-wF-3 downto 0 => '0'));  
  end generate sqintest;
  sqintest2: if sfinal <= wf+2 generate
    squarerIn <= Zfinal(sfinal-1 downto pfinal) when doRR='1'
                 else absZ0s(wF-pfinal+1 downto wf+2-sfinal);  
  end generate sqintest2;

  -- Z2o2 will be of size sfinal - pfinal -1, set squarer input size to that
--  sqintest: if sfinal >= wf+3 generate
--    squarerIn <= Zfinal(sfinal-1 downto pfinal+1) when doRR='1'
--                 else (absZ0s &  (sfinal-wF-4 downto 0 => '0'));  
--  end generate sqintest;
--  sqintest2: if sfinal < wf+3 generate
--    squarerIn <= Zfinal(sfinal-1 downto pfinal+1) when doRR='1'
--                 else absZ0s(wF-pfinal+1 downto wf+3-sfinal);  
--  end generate sqintest2;
 
  Z2o2_full <= (squarerIn * squarerIn);
  Z2o2 <= Z2o2_full (2*(sfinal-pfinal)-1  downto sfinal-pfinal-1);

  Log1p_normal  <=   Zfinal  -  ((sfinal-1 downto sfinal-pfinal-1  => '0') & (Z2o2(sfinal-pfinal downto 2)));

  LogF_normal <=   almostLog + ((targetprec-1 downto sfinal => '0') & Log1p_normal);

  absELog2_pad <=   absELog2 & (targetprec-wF-g-1 downto 0 => '0');       
  LogF_normal_pad <= (wE-1  downto 0 => LogF_normal(targetprec-1))  & LogF_normal;
  
  Log_normal <=  absELog2_pad  + LogF_normal_pad when sR='0'  
                else absELog2_pad - LogF_normal_pad;

  lzc_norm_0 : lzc_norm
    generic map (w => wE+targetprec, n => lzc_size)
    port map (i => Log_normal, z => E_normal, o => Log_normal_normd);


  rshiftsmall: rshift
    generic map (w => sfinal-pfinal+1,  n => log2wF) 
    port map (i => Z2o2,
              s => shiftval(log2wF-1 downto 0),
              o => Z2o2_small_s);

  -- send the MSB to position pfinal
  Z2o2_small <=  (pfinal-1 downto 0  => '0') & Z2o2_small_s & (wF+g-sfinal downto 0  => '0') ;

  -- mantissa will be either Y0-z^2/2  or  -Y0+z^2/2,  depending on sR  

  Z_small <= (absZ0s & (pfinal+g-1 downto 0 => '0'));
  Log_small  <=       Z_small -  Z2o2_small when (sR='0')
                else  Z_small +  Z2o2_small;

  -- Possibly subtract 1 or 2 to the exponent, depending on the LZC of Log_small
  E0_sub <=      "11" when Log_small(wF+g+1) = '1'
            else "10" when Log_small(wF+g+1 downto wF+g) = "01"
            else "01" ;

  E_small <=  "0" & (wE-2 downto 2 => '1') & E0_sub
               - ((wE-1 downto log2wF => '0') & lzo) ;

  Log_small_normd <= Log_small(wF+g+1 downto 2) when Log_small(wF+g+1)='1'
             else Log_small(wF+g downto 1)  when Log_small(wF+g)='1'  -- remove the first zero
             else Log_small(wF+g-1 downto 0)  ; -- remove two zeroes (extremely rare, 001000000 only)
                                               
  ER <= E_small when small='1'
        else E0offset - ((wE-1 downto lzc_size => '0') & E_normal);
  -- works only if wE > lzc_size approx log2wF, OK for usual exp/prec

  Log_g  <=  Log_small_normd (wF+g-2 downto 0) & "0" when small='1'           -- remove implicit 1
        else Log_normal_normd(wE+targetprec-2 downto wE+targetprec-wF-g-1 );  -- remove implicit 1

  sticky <= '0' when Log_g(g-2 downto 0) = (g-2 downto 0 => '0') else
            '1';
  round <= Log_g(g-1) and (Log_g(g) or sticky);

  -- use a trick: if round leads to a change of binade, the carry propagation
  -- magically updates both mantissa and exponent
  EFR <= (ER & Log_g(wF+g-1 downto g)) + ((wE+wF-1 downto 1 => '0') & round); 


  -- The smallest log will be log(1+2^{-wF}) \approx 2^{-wF}
  -- The smallest representable number is 2^{-2^(wE-1)} 
  -- Therefore, if 
--    underflow : if max(wE, log2(wF)+1) > wE generate
--      ufl <=      '1' when (eR2(wE0-1) = '1') or (eR = (wE-1 downto 0 => '0'))
--             else '0';
--    end generate;

--    no_underflow : if max(wE, log2(wE+wF)+2) = wE generate
      ufl <= '0';
--    end generate;

  fpR(wE+wF+2 downto wE+wF) <= "110" when ((fpX(wE+wF+2) and (fpX(wE+wF+1) or fpX(wE+wF))) or (fpX(wE+wF+1) and fpX(wE+wF))) = '1' else
                               "101" when fpX(wE+wF+2 downto wE+wF+1) = "00"                                                       else
                               "100" when fpX(wE+wF+2 downto wE+wF+1) = "10"                                                       else
                               "00" & sR when (((Log_normal_normd(wE+targetprec-1)='0') and (small='0')) or ( (Log_small_normd (wF+g-1)='0') and (small='1'))) or (ufl = '1') else
                               "01" & sR;

  fpR(wE+wF-1 downto 0) <=  EFR;

end architecture;











-------------------------------------------------------------------------------
-- Range Reduction box
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;



entity range_red is port (
          Y0 : in  std_logic_vector(24 downto 0);
          A  : in std_logic_vector(4 downto 0);
          Z  : out std_logic_vector(25 downto 0);
  almostLog  : out std_logic_vector(38 downto 0)  );
end entity;

architecture arch of  range_red is 

  component invtable0_8_23 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(5 downto 0) );
  end component;

  component logtable0_8_23 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(38 downto 0) );
  end component;

  component logtable1_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(34 downto 0) );
  end component;

  component logtable2_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(31 downto 0) );
  end component;

  component logtable3_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(28 downto 0) );
  end component;

   signal       A0:  std_logic_vector(4 downto 0);
   signal       A1:  std_logic_vector(3 downto 0);
   signal       A2:  std_logic_vector(3 downto 0);
   signal       A3:  std_logic_vector(3 downto 0);
   signal       B1:  std_logic_vector(20 downto 0);
   signal       B2:  std_logic_vector(26 downto 0);
   signal       B3:  std_logic_vector(24 downto 0);
   signal Z0, Z0_d:  std_logic_vector(24 downto 0);
   signal Z1, Z1_d:  std_logic_vector(24 downto 0);
   signal Z2, Z2_d:  std_logic_vector(30 downto 0);
   signal Z3, Z3_d:  std_logic_vector(28 downto 0);
   signal Z4, Z4_d:  std_logic_vector(25 downto 0);
   signal    epsZ1:  std_logic_vector(30 downto 0);
   signal    epsZ2:  std_logic_vector(39 downto 0);
   signal    epsZ3:  std_logic_vector(40 downto 0);
   signal      ZM1:  std_logic_vector(24 downto 0);
   signal      ZM2:  std_logic_vector(24 downto 0);
   signal      ZM3:  std_logic_vector(18 downto 0);
   signal       P0:  std_logic_vector(30 downto 0);
   signal       P1:  std_logic_vector(28 downto 0);
   signal       P2:  std_logic_vector(28 downto 0);
   signal       P3:  std_logic_vector(22 downto 0);
   signal       L0:  std_logic_vector(38 downto 0);
   signal       L1:  std_logic_vector(34 downto 0);
   signal       L2:  std_logic_vector(31 downto 0);
   signal       L3:  std_logic_vector(28 downto 0);
   signal S1, S1_d:  std_logic_vector(38 downto 0);
   signal S2, S2_d:  std_logic_vector(38 downto 0);
   signal S3, S3_d:  std_logic_vector(38 downto 0);
   signal S4, S4_d:  std_logic_vector(38 downto 0);
   signal    InvA0:  std_logic_vector(5 downto 0);
begin
   A0 <= A;
   it0:invtable0_8_23 port map (x=>A0, y=>InvA0);
   lt0:logtable0_8_23 port map (x=>A0, y=>L0);
   P0 <= InvA0 * Y0;

   Z1_d <= P0(24 downto 0);
   S1_d <= L0;

   A1 <= Z1_d(24 downto 21);
   B1 <= Z1_d(20 downto 0 );
   lt1:logtable1_8_23 port map (x=>A1, y=>L1);
   ZM1 <= Z1_d;
   P1 <= A1*ZM1;
   epsZ1 <= (30 downto 0 => '0')      when  A1 = (3 downto 0 => '0')
       else ("01" & (3 downto 0 => '0') & Z1_d )  when ((A1(3)='0') and (A1(2 downto 0) /= (2 downto 0 => '0')))
       else ("1" & (3 downto 0 => '0') & Z1_d  & "0") ;
   Z2 <=   ("0" & B1 & (8 downto 0 => '0') )
         - ( (0 downto 0 => '0') & P1 & (0 downto 0 => '0')  )
         + epsZ1(30 downto 0);
   S2 <=   S1_d + ((38 downto 35 =>'0') & L1);

   Z2_d <=   Z2;
   S2_d <=   S2;


   A2 <= Z2_d(30 downto 27);
   B2 <= Z2_d(26 downto 0 );
   lt2:logtable2_8_23 port map (x=>A2, y=>L2);
   ZM2 <= Z2_d(30 downto 6);
   P2 <= A2*ZM2;
   epsZ2 <=  (39 downto 0 => '0')      when  A2 = (3 downto 0 => '0')
     else    ("01" & (6 downto 0 => '0') & Z2_d);
   Z3 <=   ("0" & B2 & (0 downto 0 => '0') )
         - ( (3 downto 0 => '0') & P2(28 downto 4 )  )
         + epsZ2(39 downto 11);
   S3 <=   S2_d + ((38 downto 32 =>'0') & L2);

   Z3_d <=   Z3;
   S3_d <=   S3;


   A3 <= Z3_d(28 downto 25);
   B3 <= Z3_d(24 downto 0 );
   lt3:logtable3_8_23 port map (x=>A3, y=>L3);
   ZM3 <= Z3_d(28 downto 10);
   P3 <= A3*ZM3;
   epsZ3 <=  (40 downto 0 => '0')      when  A3 = (3 downto 0 => '0')
     else    ("01" & (9 downto 0 => '0') & Z3_d);
   Z4 <=   ("0" & B3)
         - ( (6 downto 0 => '0') & P3(22 downto 4 )  )
         + epsZ3(40 downto 15);
   S4 <=   S3_d + ((38 downto 29 =>'0') & L3);

   Z4_d <=   Z4;
   S4_d <=   S4;

   Z <= Z4_d;
   almostLog <= S4_d;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  invtable0_8_23 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(5 downto 0) );
end entity;

architecture arch of invtable0_8_23 is
begin
  with x select
    y <= "100000" when "00000",
         "100000" when "00001",
         "011111" when "00010",
         "011110" when "00011",
         "011101" when "00100",
         "011100" when "00101",
         "011011" when "00110",
         "011011" when "00111",
         "011010" when "01000",
         "011001" when "01001",
         "011001" when "01010",
         "011000" when "01011",
         "011000" when "01100",
         "010111" when "01101",
         "010111" when "01110",
         "010110" when "01111",
         "101011" when "10000",
         "101010" when "10001",
         "101001" when "10010",
         "101001" when "10011",
         "101000" when "10100",
         "100111" when "10101",
         "100110" when "10110",
         "100110" when "10111",
         "100101" when "11000",
         "100100" when "11001",
         "100100" when "11010",
         "100011" when "11011",
         "100011" when "11100",
         "100010" when "11101",
         "100010" when "11110",
         "100001" when "11111",
         "------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable0_8_23 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(38 downto 0) );
end entity;

architecture arch of logtable0_8_23 is
begin
  with x select
    y <= "000000000000000000000000000000000000000" when "00000",
         "000000000000000000000000000000000000000" when "00001",
         "000010000010000010101110110001001111001" when "00010",
         "000100001000010110011000101101011001111" when "00011",
         "000110010011001101011110010111010101100" when "00100",
         "001000100010111100011101000001000100111" when "00101",
         "001010110111111010000000110101101010100" when "00110",
         "001010110111111010000000110101101010100" when "00111",
         "001101010010011111011010011110010001010" when "01000",
         "001111110011001000111000110110010110011" when "01001",
         "001111110011001000111000110110010110011" when "01010",
         "010010011010010110001000010001001101001" when "01011",
         "010010011010010110001000010001001101001" when "01100",
         "010101001000101010111000000111001110001" when "01101",
         "010101001000101010111000000111001110001" when "01110",
         "010111111110101111101000111011110110000" when "01111",
         "101101000101110001110101000101000111110" when "10000",
         "101110100110001010001101010100010101001" when "10001",
         "110000001000110111001111001001010100010" when "10010",
         "110000001000110111001111001001010100010" when "10011",
         "110001101110000000010000011100001100110" when "10100",
         "110011010101101101001010110001100001100" when "10101",
         "110101000000000110011111000111101011001" when "10110",
         "110101000000000110011111000111101011001" when "10111",
         "110110101101010101011010000011111100001" when "11000",
         "111000011101100011111000100100011101011" when "11001",
         "111000011101100011111000100100011101011" when "11010",
         "111010010000111100101101011101010001110" when "11011",
         "111010010000111100101101011101010001110" when "11100",
         "111100000111101011100111100111111111100" when "11101",
         "111100000111101011100111100111111111100" when "11110",
         "111110000001111101011001001111000110001" when "11111",
         "---------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable1_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(34 downto 0) );
end entity;

architecture arch of logtable1_8_23 is
begin
  with x select
    y <= "00000000000000000000000000000000000" when "0000",
         "00001000000000100000000010101010111" when "0001",
         "00011000000100100001001000010100010" when "0010",
         "00101000001100100101001111110010110" when "0011",
         "00111000011000101110011100001001100" when "0100",
         "01001000101000111110110001111111101" when "0101",
         "01011000111101011000010111100001101" when "0110",
         "01101001010101111101010100100011000" when "0111",
         "01110001100011110100101110110000010" when "1000",
         "10000010000010101110110001001111001" when "1001",
         "10010010100101111001100101111100011" when "1010",
         "10100011001101010111011010100001011" when "1011",
         "10110011111001001010011110010110101" when "1100",
         "11000100101001010101000010100100111" when "1101",
         "11010101011101111001011010000111110" when "1110",
         "11100110010110111001111001101110111" when "1111",
         "-----------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable2_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(31 downto 0) );
end entity;

architecture arch of logtable2_8_23 is
begin
  with x select
    y <= "00000000000000000000000000000000" when "0000",
         "00001000000000000100000000000010" when "0001",
         "00011000000000100100000001001000" when "0010",
         "00101000000001100100000101001101" when "0011",
         "00111000000011000100001110010011" when "0100",
         "01001000000101000100011110011011" when "0101",
         "01011000000111100100110111100100" when "0110",
         "01101000001010100101011011110000" when "0111",
         "01111000001110000110001101000000" when "1000",
         "10001000010010000111001101010110" when "1001",
         "10011000010110101000011110110010" when "1010",
         "10101000011011101010000011010111" when "1011",
         "10111000100001001011111101000110" when "1100",
         "11001000100111001110001110000010" when "1101",
         "11011000101101110000111000001100" when "1110",
         "11101000110100110011111101101000" when "1111",
         "--------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable3_8_23 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(28 downto 0) );
end entity;

architecture arch of logtable3_8_23 is
begin
  with x select
    y <= "00000000000000000000000000000" when "0000",
         "00001000000000000000100000000" when "0001",
         "00011000000000000100100000000" when "0010",
         "00101000000000001100100000000" when "0011",
         "00111000000000011000100000001" when "0100",
         "01001000000000101000100000011" when "0101",
         "01011000000000111100100000110" when "0110",
         "01101000000001010100100001011" when "0111",
         "01111000000001110000100010001" when "1000",
         "10001000000010010000100011001" when "1001",
         "10011000000010110100100100011" when "1010",
         "10101000000011011100100110000" when "1011",
         "10111000000100001000100111111" when "1100",
         "11001000000100111000101010001" when "1101",
         "11011000000101101100101100110" when "1110",
         "11101000000110100100101111111" when "1111",
         "-----------------------------" when others;
end architecture;

