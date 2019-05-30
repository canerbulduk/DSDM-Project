// ==============================================================
// File generated on Thu May 30 19:18:47 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablkbM_H__
#define __range_red_logtablkbM_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablkbM_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 60;
  static const unsigned AddressRange = 16;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(range_red_logtablkbM_ram) {
        ram[0] = "0b000000000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b000000010000000000000001010101010101011101010101010110001000";
        ram[2] = "0b000010010000000000100100000000001010001000000011000010011010";
        ram[3] = "0b000110010000000010100110101011111000110011010001101110111111";
        ram[4] = "0b001100010000000111001001011010000001100000100111011101010100";
        ram[5] = "0b010100010000001111001100001100110100010011100010010010000000";
        ram[6] = "0b011110010000011011101111000111010001010010001000010111100001";
        ram[7] = "0b101010010000101101110010001101001000100101111000000001111101";
        ram[8] = "0b111000010001000110010101100010111010011100010111110011110101";
        ram[9] = "0b001000010001100110011001001101110111001000000110100011100100";
        ram[10] = "0b011010010010001110111101010011111111000001001011100010001010";
        ram[11] = "0b101110010011000001000001111100000010100110000110100010101011";
        ram[12] = "0b000100010011111101100111001101100010011100100000000010101011";
        ram[13] = "0b011100010101000101101101010000101111010001111001010011101000";
        ram[14] = "0b110110010110011010010100001110101001111100011100100101010000";
        ram[15] = "0b010010010111111100011100010001000011011011101101010000110000";


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


SC_MODULE(range_red_logtablkbM) {


static const unsigned DataWidth = 60;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablkbM_ram* meminst;


SC_CTOR(range_red_logtablkbM) {
meminst = new range_red_logtablkbM_ram("range_red_logtablkbM_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablkbM() {
    delete meminst;
}


};//endmodule
#endif
