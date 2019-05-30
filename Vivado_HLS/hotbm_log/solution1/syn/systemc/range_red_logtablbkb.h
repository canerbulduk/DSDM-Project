// ==============================================================
// File generated on Thu May 30 06:13:47 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablbkb_H__
#define __range_red_logtablbkb_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablbkb_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 23;
  static const unsigned AddressRange = 32;
  static const unsigned AddressWidth = 5;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(range_red_logtablbkb_ram) {
        ram[0] = "0b00000000000000000000000";
        ram[1] = "0b00000000000000000000000";
        ram[2] = "0b00001000001000001010111";
        ram[3] = "0b00010000100001011001100";
        ram[4] = "0b00011001001100110101111";
        ram[5] = "0b00100010001011110001110";
        ram[6] = "0b00101011011111101000000";
        ram[7] = "0b00101011011111101000000";
        ram[8] = "0b00110101001001111101101";
        ram[9] = "0b00111111001100100011100";
        ram[10] = "0b00111111001100100011100";
        ram[11] = "0b01001001101001011000100";
        ram[12] = "0b01001001101001011000100";
        ram[13] = "0b01010100100010101011100";
        ram[14] = "0b01010100100010101011100";
        ram[15] = "0b01011111111010111110100";
        ram[16] = "0b10110100010111000111010";
        ram[17] = "0b10111010011000101000110";
        ram[18] = "0b11000000100011011100111";
        ram[19] = "0b11000000100011011100111";
        ram[20] = "0b11000110111000000001000";
        ram[21] = "0b11001101010110110100101";
        ram[22] = "0b11010100000000011001111";
        ram[23] = "0b11010100000000011001111";
        ram[24] = "0b11011010110101010101101";
        ram[25] = "0b11100001110110001111100";
        ram[26] = "0b11100001110110001111100";
        ram[27] = "0b11101001000011110010110";
        ram[28] = "0b11101001000011110010110";
        ram[29] = "0b11110000011110101110011";
        ram[30] = "0b11110000011110101110011";
        ram[31] = "0b11111000000111110101100";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(range_red_logtablbkb) {


static const unsigned DataWidth = 23;
static const unsigned AddressRange = 32;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablbkb_ram* meminst;


SC_CTOR(range_red_logtablbkb) {
meminst = new range_red_logtablbkb_ram("range_red_logtablbkb_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablbkb() {
    delete meminst;
}


};//endmodule
#endif
