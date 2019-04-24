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
 
entity fp_log_11_52 is 
  generic ( wE : positive := 11;
            wF : positive := 52);
  port ( fpX : in  std_logic_vector(2+wE+wF downto 0);
         fpR : out std_logic_vector(2+wE+wF downto 0)  );
end entity;
architecture arch of fp_log_11_52 is 

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
            Y0 : in  std_logic_vector(53 downto 0);
            A  : in std_logic_vector(4 downto 0);
            Z  : out std_logic_vector(54 downto 0);
    almostLog  : out std_logic_vector(82 downto 0)  );
  end component;
  constant g   : positive := 5;
  constant a0 : positive := 5;
  constant log2wF : positive := 6;
  constant targetprec : positive := 83;
  constant sfinal : positive := 55;
  constant pfinal : positive := 28;
  signal log2 : std_logic_vector(wF+g-1 downto 0) := "101100010111001000010111111101111101000111001111011110011";
  signal E0offset : std_logic_vector(wE-1 downto 0) := "10000001001"; -- E0 + wE 
  signal pfinal_s : std_logic_vector(log2wF -1 downto 0) := "011100";
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
          Y0 : in  std_logic_vector(53 downto 0);
          A  : in std_logic_vector(4 downto 0);
          Z  : out std_logic_vector(54 downto 0);
  almostLog  : out std_logic_vector(82 downto 0)  );
end entity;

architecture arch of  range_red is 

  component invtable0_11_52 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(5 downto 0) );
  end component;

  component logtable0_11_52 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(82 downto 0) );
  end component;

  component logtable1_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(78 downto 0) );
  end component;

  component logtable2_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(75 downto 0) );
  end component;

  component logtable3_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(72 downto 0) );
  end component;

  component logtable4_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(69 downto 0) );
  end component;

  component logtable5_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(66 downto 0) );
  end component;

  component logtable6_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(63 downto 0) );
  end component;

  component logtable7_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(60 downto 0) );
  end component;

  component logtable8_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(57 downto 0) );
  end component;

   signal       A0:  std_logic_vector(4 downto 0);
   signal       A1:  std_logic_vector(3 downto 0);
   signal       A2:  std_logic_vector(3 downto 0);
   signal       A3:  std_logic_vector(3 downto 0);
   signal       A4:  std_logic_vector(3 downto 0);
   signal       A5:  std_logic_vector(3 downto 0);
   signal       A6:  std_logic_vector(3 downto 0);
   signal       A7:  std_logic_vector(3 downto 0);
   signal       A8:  std_logic_vector(3 downto 0);
   signal       B1:  std_logic_vector(49 downto 0);
   signal       B2:  std_logic_vector(55 downto 0);
   signal       B3:  std_logic_vector(64 downto 0);
   signal       B4:  std_logic_vector(65 downto 0);
   signal       B5:  std_logic_vector(62 downto 0);
   signal       B6:  std_logic_vector(59 downto 0);
   signal       B7:  std_logic_vector(56 downto 0);
   signal       B8:  std_logic_vector(53 downto 0);
   signal Z0, Z0_d:  std_logic_vector(53 downto 0);
   signal Z1, Z1_d:  std_logic_vector(53 downto 0);
   signal Z2, Z2_d:  std_logic_vector(59 downto 0);
   signal Z3, Z3_d:  std_logic_vector(68 downto 0);
   signal Z4, Z4_d:  std_logic_vector(69 downto 0);
   signal Z5, Z5_d:  std_logic_vector(66 downto 0);
   signal Z6, Z6_d:  std_logic_vector(63 downto 0);
   signal Z7, Z7_d:  std_logic_vector(60 downto 0);
   signal Z8, Z8_d:  std_logic_vector(57 downto 0);
   signal Z9, Z9_d:  std_logic_vector(54 downto 0);
   signal    epsZ1:  std_logic_vector(59 downto 0);
   signal    epsZ2:  std_logic_vector(68 downto 0);
   signal    epsZ3:  std_logic_vector(80 downto 0);
   signal    epsZ4:  std_logic_vector(84 downto 0);
   signal    epsZ5:  std_logic_vector(84 downto 0);
   signal    epsZ6:  std_logic_vector(84 downto 0);
   signal    epsZ7:  std_logic_vector(84 downto 0);
   signal    epsZ8:  std_logic_vector(84 downto 0);
   signal      ZM1:  std_logic_vector(53 downto 0);
   signal      ZM2:  std_logic_vector(59 downto 0);
   signal      ZM3:  std_logic_vector(62 downto 0);
   signal      ZM4:  std_logic_vector(56 downto 0);
   signal      ZM5:  std_logic_vector(50 downto 0);
   signal      ZM6:  std_logic_vector(44 downto 0);
   signal      ZM7:  std_logic_vector(38 downto 0);
   signal      ZM8:  std_logic_vector(32 downto 0);
   signal       P0:  std_logic_vector(59 downto 0);
   signal       P1:  std_logic_vector(57 downto 0);
   signal       P2:  std_logic_vector(63 downto 0);
   signal       P3:  std_logic_vector(66 downto 0);
   signal       P4:  std_logic_vector(60 downto 0);
   signal       P5:  std_logic_vector(54 downto 0);
   signal       P6:  std_logic_vector(48 downto 0);
   signal       P7:  std_logic_vector(42 downto 0);
   signal       P8:  std_logic_vector(36 downto 0);
   signal       L0:  std_logic_vector(82 downto 0);
   signal       L1:  std_logic_vector(78 downto 0);
   signal       L2:  std_logic_vector(75 downto 0);
   signal       L3:  std_logic_vector(72 downto 0);
   signal       L4:  std_logic_vector(69 downto 0);
   signal       L5:  std_logic_vector(66 downto 0);
   signal       L6:  std_logic_vector(63 downto 0);
   signal       L7:  std_logic_vector(60 downto 0);
   signal       L8:  std_logic_vector(57 downto 0);
   signal S1, S1_d:  std_logic_vector(82 downto 0);
   signal S2, S2_d:  std_logic_vector(82 downto 0);
   signal S3, S3_d:  std_logic_vector(82 downto 0);
   signal S4, S4_d:  std_logic_vector(82 downto 0);
   signal S5, S5_d:  std_logic_vector(82 downto 0);
   signal S6, S6_d:  std_logic_vector(82 downto 0);
   signal S7, S7_d:  std_logic_vector(82 downto 0);
   signal S8, S8_d:  std_logic_vector(82 downto 0);
   signal S9, S9_d:  std_logic_vector(82 downto 0);
   signal    InvA0:  std_logic_vector(5 downto 0);
begin
   A0 <= A;
   it0:invtable0_11_52 port map (x=>A0, y=>InvA0);
   lt0:logtable0_11_52 port map (x=>A0, y=>L0);
   P0 <= InvA0 * Y0;

   Z1_d <= P0(53 downto 0);
   S1_d <= L0;

   A1 <= Z1_d(53 downto 50);
   B1 <= Z1_d(49 downto 0 );
   lt1:logtable1_11_52 port map (x=>A1, y=>L1);
   ZM1 <= Z1_d;
   P1 <= A1*ZM1;
   epsZ1 <= (59 downto 0 => '0')      when  A1 = (3 downto 0 => '0')
       else ("01" & (3 downto 0 => '0') & Z1_d )  when ((A1(3)='0') and (A1(2 downto 0) /= (2 downto 0 => '0')))
       else ("1" & (3 downto 0 => '0') & Z1_d  & "0") ;
   Z2 <=   ("0" & B1 & (8 downto 0 => '0') )
         - ( (0 downto 0 => '0') & P1 & (0 downto 0 => '0')  )
         + epsZ1(59 downto 0);
   S2 <=   S1_d + ((82 downto 79 =>'0') & L1);

   Z2_d <=   Z2;
   S2_d <=   S2;


   A2 <= Z2_d(59 downto 56);
   B2 <= Z2_d(55 downto 0 );
   lt2:logtable2_11_52 port map (x=>A2, y=>L2);
   ZM2 <= Z2_d;
   P2 <= A2*ZM2;
   epsZ2 <=  (68 downto 0 => '0')      when  A2 = (3 downto 0 => '0')
     else    ("01" & (6 downto 0 => '0') & Z2_d);
   Z3 <=   ("0" & B2 & (11 downto 0 => '0') )
         - ( (3 downto 0 => '0') & P2 & (0 downto 0 => '0')  )
         + epsZ2(68 downto 0);
   S3 <=   S2_d + ((82 downto 76 =>'0') & L2);

   Z3_d <=   Z3;
   S3_d <=   S3;


   A3 <= Z3_d(68 downto 65);
   B3 <= Z3_d(64 downto 0 );
   lt3:logtable3_11_52 port map (x=>A3, y=>L3);
   ZM3 <= Z3_d(68 downto 6);
   P3 <= A3*ZM3;
   epsZ3 <=  (80 downto 0 => '0')      when  A3 = (3 downto 0 => '0')
     else    ("01" & (9 downto 0 => '0') & Z3_d);
   Z4 <=   ("0" & B3 & (3 downto 0 => '0') )
         - ( (6 downto 0 => '0') & P3(66 downto 4 )  )
         + epsZ3(80 downto 11);
   S4 <=   S3_d + ((82 downto 73 =>'0') & L3);

   Z4_d <=   Z4;
   S4_d <=   S4;


   A4 <= Z4_d(69 downto 66);
   B4 <= Z4_d(65 downto 0 );
   lt4:logtable4_11_52 port map (x=>A4, y=>L4);
   ZM4 <= Z4_d(69 downto 13);
   P4 <= A4*ZM4;
   epsZ4 <=  (84 downto 0 => '0')      when  A4 = (3 downto 0 => '0')
     else    ("01" & (12 downto 0 => '0') & Z4_d);
   Z5 <=   ("0" & B4)
         - ( (9 downto 0 => '0') & P4(60 downto 4 )  )
         + epsZ4(84 downto 18);
   S5 <=   S4_d + ((82 downto 70 =>'0') & L4);

   Z5_d <=   Z5;
   S5_d <=   S5;


   A5 <= Z5_d(66 downto 63);
   B5 <= Z5_d(62 downto 0 );
   lt5:logtable5_11_52 port map (x=>A5, y=>L5);
   ZM5 <= Z5_d(66 downto 16);
   P5 <= A5*ZM5;
   epsZ5 <=  (84 downto 0 => '0')      when  A5 = (3 downto 0 => '0')
     else    ("01" & (15 downto 0 => '0') & Z5_d);
   Z6 <=   ("0" & B5)
         - ( (12 downto 0 => '0') & P5(54 downto 4 )  )
         + epsZ5(84 downto 21);
   S6 <=   S5_d + ((82 downto 67 =>'0') & L5);

   Z6_d <=   Z6;
   S6_d <=   S6;


   A6 <= Z6_d(63 downto 60);
   B6 <= Z6_d(59 downto 0 );
   lt6:logtable6_11_52 port map (x=>A6, y=>L6);
   ZM6 <= Z6_d(63 downto 19);
   P6 <= A6*ZM6;
   epsZ6 <=  (84 downto 0 => '0')      when  A6 = (3 downto 0 => '0')
     else    ("01" & (18 downto 0 => '0') & Z6_d);
   Z7 <=   ("0" & B6)
         - ( (15 downto 0 => '0') & P6(48 downto 4 )  )
         + epsZ6(84 downto 24);
   S7 <=   S6_d + ((82 downto 64 =>'0') & L6);

   Z7_d <=   Z7;
   S7_d <=   S7;


   A7 <= Z7_d(60 downto 57);
   B7 <= Z7_d(56 downto 0 );
   lt7:logtable7_11_52 port map (x=>A7, y=>L7);
   ZM7 <= Z7_d(60 downto 22);
   P7 <= A7*ZM7;
   epsZ7 <=  (84 downto 0 => '0')      when  A7 = (3 downto 0 => '0')
     else    ("01" & (21 downto 0 => '0') & Z7_d);
   Z8 <=   ("0" & B7)
         - ( (18 downto 0 => '0') & P7(42 downto 4 )  )
         + epsZ7(84 downto 27);
   S8 <=   S7_d + ((82 downto 61 =>'0') & L7);

   Z8_d <=   Z8;
   S8_d <=   S8;


   A8 <= Z8_d(57 downto 54);
   B8 <= Z8_d(53 downto 0 );
   lt8:logtable8_11_52 port map (x=>A8, y=>L8);
   ZM8 <= Z8_d(57 downto 25);
   P8 <= A8*ZM8;
   epsZ8 <=  (84 downto 0 => '0')      when  A8 = (3 downto 0 => '0')
     else    ("01" & (24 downto 0 => '0') & Z8_d);
   Z9 <=   ("0" & B8)
         - ( (21 downto 0 => '0') & P8(36 downto 4 )  )
         + epsZ8(84 downto 30);
   S9 <=   S8_d + ((82 downto 58 =>'0') & L8);

   Z9_d <=   Z9;
   S9_d <=   S9;

   Z <= Z9_d;
   almostLog <= S9_d;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  invtable0_11_52 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(5 downto 0) );
end entity;

architecture arch of invtable0_11_52 is
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

entity  logtable0_11_52 is
    port ( x : in  std_logic_vector(4 downto 0);
           y : out std_logic_vector(82 downto 0) );
end entity;

architecture arch of logtable0_11_52 is
begin
  with x select
    y <= "00000000000000000000000000000000000000000000000000000000000000000000000000000000000" when "00000",
         "00000000000000000000000000000000000000000000000000000000000000000000000000000000000" when "00001",
         "00001000001000001010111011000100111100111010001000100010001110000000101110011110001" when "00010",
         "00010000100001011001100010110101100111100011101000000110100010001010001111111101100" when "00011",
         "00011001001100110101111001011101010110010100100110001000101011100001110101011110101" when "00100",
         "00100010001011110001110100000100010011111100100011110111101111000110011100010110100" when "00101",
         "00101011011111101000000011010110101010000111101101100011111101110000010100100101110" when "00110",
         "00101011011111101000000011010110101010000111101101100011111101110000010100100101110" when "00111",
         "00110101001001111101101001111001000101011011001111000110110111100101011111010100111" when "01000",
         "00111111001100100011100011011001011001110110011011110010111110110011001010000011001" when "01001",
         "00111111001100100011100011011001011001110110011011110010111110110011001010000011001" when "01010",
         "01001001101001011000100001000100110100110110111001001001111000001110111110101101110" when "01011",
         "01001001101001011000100001000100110100110110111001001001111000001110111110101101110" when "01100",
         "01010100100010101011100000011100111000101000111101011111001110000100000010110010011" when "01101",
         "01010100100010101011100000011100111000101000111101011111001110000100000010110010011" when "01110",
         "01011111111010111110100011101111011000000101010001101111101101111001101111110110110" when "01111",
         "10110100010111000111010100010100011110111000101100111101100011110100110011011011101" when "10000",
         "10111010011000101000110101010001010100010110011111000111111100011000110011100000110" when "10001",
         "11000000100011011100111100100101010000111000001110101010111001010101010101110011010" when "10010",
         "11000000100011011100111100100101010000111000001110101010111001010101010101110011010" when "10011",
         "11000110111000000001000001110000110010101100101110111100101001111011010001001111111" when "10100",
         "11001101010110110100101011000110000101110101001010010111000100110111110110011111001" when "10101",
         "11010100000000011001111100011110101100001101100001011000011011110001100000111100000" when "10110",
         "11010100000000011001111100011110101100001101100001011000011011110001100000111100000" when "10111",
         "11011010110101010101101000001111110000000001010110111001011001111111010001000111001" when "11000",
         "11100001110110001111100010010001110101010000110100011010000101100001010101111000001" when "11001",
         "11100001110110001111100010010001110101010000110100011010000101100001010101111000001" when "11010",
         "11101001000011110010110101110101000110101001010010110100011001000001101101100110011" when "11011",
         "11101001000011110010110101110101000110101001010010110100011001000001101101100110011" when "11100",
         "11110000011110101110011110011111111101110100111010101100110011110100000110011011011" when "11101",
         "11110000011110101110011110011111111101110100111010101100110011110100000110011011011" when "11110",
         "11111000000111110101100100111100011000011111001100111111111011001100000111000001000" when "11111",
         "-----------------------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable1_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(78 downto 0) );
end entity;

architecture arch of logtable1_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000010000000001010101011101010110001000100111011110011100000110011100" when "0001",
         "0001100000010010000100100001010001011000011010110101010000001110000010100101110" when "0010",
         "0010100000110010010100111111001011010000011001011101111100011101010101110100000" when "0011",
         "0011100001100010111001110000100110001110101111100000110011000000001100010000010" when "0100",
         "0100100010100011111011000111111110101000101110001001111100011001010000100100110" when "0101",
         "0101100011110101100001011110000110100100001011110101011111100111000100101011001" when "0110",
         "0110100101010111110101010010001100010111000100001111110001111011000001101001011" when "0111",
         "0111000110001111010010111011000001010010101010111100011000110001111111001111010" when "1000",
         "1000001000001010111011000100111100111010001000100010001110000000101110011110001" when "1001",
         "1001001010010111100110010111110001101000110000011111010011010111000000010000110" when "1010",
         "1010001100110101011101101010000101101111000111110100110001100100010100100001000" when "1011",
         "1011001111100100101001111001011010100101110110101100001000001000001001111100110" when "1100",
         "1100010010100101010100001010010011111101100110100001100110101000101111101001011" when "1101",
         "1101010101110111100101101000011111011000100001111110000011010001101010011101110" when "1110",
         "1110011001011011100111100110111011101101100101100101110000110110111000001001111" when "1111",
         "-------------------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable2_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(75 downto 0) );
end entity;

architecture arch of logtable2_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000010000000000001010101010110010101010110001000100010110011001" when "0001",
         "0001100000000010010000000100100000001010001000011000010100001001100101101001" when "0010",
         "0010100000000110010000010100110110100011100010001110001001101100110001111100" when "0011",
         "0011100000001100010000111001001111010111001100111101110000111000010101010011" when "0100",
         "0100100000010100010001111001101100110101100100011011101110111000101110000001" when "0101",
         "0101100000011110010011011110010001111111011001100010100011110001101001010111" when "0110",
         "0110100000101010010101101111000010100101111000010110011011111010110110000100" when "0111",
         "0111100000111000011000110100000011001010101110001001111110001111111000010011" when "1000",
         "1000100001001000011100110101011001000000001111100011110111011110011100000010" when "1001",
         "1001100001011010100001111011001010001001011110100101100010011110100100010001" when "1010",
         "1010100001101110101000001101011101011010010000110010101110000000011000110100" when "1011",
         "1011100010000100101111110100011010010111010101011001111111111010110110101110" when "1100",
         "1100100010011100111000111000001001010110011011011110010110000111001001101001" when "1101",
         "1101100010110111000011100000110011011110011000000001100101010100010111011111" when "1110",
         "1110100011010011001111110110100010100111001100001111110101111111001001110100" when "1111",
         "----------------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable3_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(72 downto 0) );
end entity;

architecture arch of logtable3_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000010000000000000001010101010101011101010101010110001000" when "0001",
         "0001100000000000010010000000000100100000000001010001000000011000010011010" when "0010",
         "0010100000000000110010000000010100110101011111000110011010001101110111111" when "0011",
         "0011100000000001100010000000111001001011010000001100000100111011101010100" when "0100",
         "0100100000000010100010000001111001100001100110100010011100010010010000000" when "0101",
         "0101100000000011110010000011011101111000111010001010010001000010111100001" when "0110",
         "0110100000000101010010000101101110010001101001000100101111000000001111101" when "0111",
         "0111100000000111000010001000110010101100010111010011100010111110011110101" when "1000",
         "1000100000001001000010001100110011001001101110111001000000110100011100100" when "1001",
         "1001100000001011010010010001110111101010011111111000001001011100010001010" when "1010",
         "1010100000001101110010011000001000001111100000010100110000110100010101011" when "1011",
         "1011100000010000100010011111101100111001101100010011100100000000010101011" when "1100",
         "1100100000010011100010101000101101101010000101111010001111001010011101000" when "1101",
         "1101100000010110110010110011010010100001110101001111100011100100101010000" when "1110",
         "1110100000011010010010111111100011100010001000011011011101101010000110000" when "1111",
         "-------------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable4_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(69 downto 0) );
end entity;

architecture arch of logtable4_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000000010000000000000000001010101010101010110010101010" when "0001",
         "0001100000000000000010010000000000000100100000000000001010001000000000" when "0010",
         "0010100000000000000110010000000000010100110101010110100011011101011010" when "0011",
         "0011100000000000001100010000000000111001001010101111010110110011000100" when "0100",
         "0100100000000000010100010000000001111001100000001100110100001001011100" when "0101",
         "0101100000000000011110010000000011011101110101110001111011100001010000" when "0110",
         "0110100000000000101010010000000101101110001011100010011100111011101110" when "0111",
         "0111100000000000111000010000001000110010100001100010111000011010100010" when "1000",
         "1000100000000001001000010000001100110010110111111000011101111111111111" when "1001",
         "1001100000000001011010010000010001110111001110101001001101101111000111" when "1010",
         "1010100000000001101110010000011000000111100101111011110111101011101101" when "1011",
         "1011100000000010000100010000011111101011111101110111111011111010011110" when "1100",
         "1100100000000010011100010000101000101100010110100101101010100001000110" when "1101",
         "1101100000000010110110010000110011010000110000001110000011100110010110" when "1110",
         "1110100000000011010010010000111111100001001010111010110111010010001000" when "1111",
         "----------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable5_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(66 downto 0) );
end entity;

architecture arch of logtable5_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000000000010000000000000000000001010101010101010101" when "0001",
         "0001100000000000000000010010000000000000000100100000000000000001010" when "0010",
         "0010100000000000000000110010000000000000010100110101010101011111000" when "0011",
         "0011100000000000000001100010000000000000111001001010101011010000001" when "0100",
         "0100100000000000000010100010000000000001111001100000000001100110100" when "0101",
         "0101100000000000000011110010000000000011011101110101011000111010000" when "0110",
         "0110100000000000000101010010000000000101101110001010110001101000111" when "0111",
         "0111100000000000000111000010000000001000110010100000001100010111000" when "1000",
         "1000100000000000001001000010000000001100110010110101101001101110010" when "1001",
         "1001100000000000001011010010000000010001110111001011001010011110111" when "1010",
         "1010100000000000001101110010000000011000000111100000101111011110110" when "1011",
         "1011100000000000010000100010000000011111101011110110011001101001111" when "1100",
         "1100100000000000010011100010000000101000101100001100001010000010001" when "1101",
         "1101100000000000010110110010000000110011010000100010000001101111110" when "1110",
         "1110100000000000011010010010000000111111100000111000000010000000101" when "1111",
         "-------------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable6_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(63 downto 0) );
end entity;

architecture arch of logtable6_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000000000000010000000000000000000000001010101010" when "0001",
         "0001100000000000000000000010010000000000000000000100100000000000" when "0010",
         "0010100000000000000000000110010000000000000000010100110101010101" when "0011",
         "0011100000000000000000001100010000000000000000111001001010101010" when "0100",
         "0100100000000000000000010100010000000000000001111001100000000000" when "0101",
         "0101100000000000000000011110010000000000000011011101110101010101" when "0110",
         "0110100000000000000000101010010000000000000101101110001010101011" when "0111",
         "0111100000000000000000111000010000000000001000110010100000000001" when "1000",
         "1000100000000000000001001000010000000000001100110010110101010111" when "1001",
         "1001100000000000000001011010010000000000010001110111001010101110" when "1010",
         "1010100000000000000001101110010000000000011000000111100000000101" when "1011",
         "1011100000000000000010000100010000000000011111101011110101011101" when "1100",
         "1100100000000000000010011100010000000000101000101100001010110110" when "1101",
         "1101100000000000000010110110010000000000110011010000100000010000" when "1110",
         "1110100000000000000011010010010000000000111111100000110101101010" when "1111",
         "----------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable7_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(60 downto 0) );
end entity;

architecture arch of logtable7_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000000000000000010000000000000000000000000001" when "0001",
         "0001100000000000000000000000010010000000000000000000000100100" when "0010",
         "0010100000000000000000000000110010000000000000000000010100110" when "0011",
         "0011100000000000000000000001100010000000000000000000111001001" when "0100",
         "0100100000000000000000000010100010000000000000000001111001100" when "0101",
         "0101100000000000000000000011110010000000000000000011011101110" when "0110",
         "0110100000000000000000000101010010000000000000000101101110001" when "0111",
         "0111100000000000000000000111000010000000000000001000110010100" when "1000",
         "1000100000000000000000001001000010000000000000001100110010110" when "1001",
         "1001100000000000000000001011010010000000000000010001110111001" when "1010",
         "1010100000000000000000001101110010000000000000011000000111100" when "1011",
         "1011100000000000000000010000100010000000000000011111101011110" when "1100",
         "1100100000000000000000010011100010000000000000101000101100001" when "1101",
         "1101100000000000000000010110110010000000000000110011010000100" when "1110",
         "1110100000000000000000011010010010000000000000111111100000110" when "1111",
         "-------------------------------------------------------------" when others;
end architecture;

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
library work;
use work.pkg_fp_log.all;

entity  logtable8_11_52 is
    port ( x : in  std_logic_vector(3 downto 0);
           y : out std_logic_vector(57 downto 0) );
end entity;

architecture arch of logtable8_11_52 is
begin
  with x select
    y <= "0000000000000000000000000000000000000000000000000000000000" when "0000",
         "0000100000000000000000000000000000010000000000000000000000" when "0001",
         "0001100000000000000000000000000010010000000000000000000000" when "0010",
         "0010100000000000000000000000000110010000000000000000000000" when "0011",
         "0011100000000000000000000000001100010000000000000000000000" when "0100",
         "0100100000000000000000000000010100010000000000000000000001" when "0101",
         "0101100000000000000000000000011110010000000000000000000011" when "0110",
         "0110100000000000000000000000101010010000000000000000000101" when "0111",
         "0111100000000000000000000000111000010000000000000000001000" when "1000",
         "1000100000000000000000000001001000010000000000000000001100" when "1001",
         "1001100000000000000000000001011010010000000000000000010001" when "1010",
         "1010100000000000000000000001101110010000000000000000011000" when "1011",
         "1011100000000000000000000010000100010000000000000000011111" when "1100",
         "1100100000000000000000000010011100010000000000000000101000" when "1101",
         "1101100000000000000000000010110110010000000000000000110011" when "1110",
         "1110100000000000000000000011010010010000000000000000111111" when "1111",
         "----------------------------------------------------------" when others;
end architecture;

