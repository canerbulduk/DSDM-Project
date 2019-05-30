// ==============================================================
// File generated on Thu May 30 19:18:46 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablibs_H__
#define __range_red_logtablibs_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablibs_ram : public sc_core::sc_module {

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


   SC_CTOR(range_red_logtablibs_ram) {
        ram[0] = "0b000000000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b000001010101011101010110001000100111011110011100000110011100";
        ram[2] = "0b100100001010001011000011010110101010000001110000010100101110";
        ram[3] = "0b100111111001011010000011001011101111100011101010101110100000";
        ram[4] = "0b001110000100110001110101111100000110011000000001100010000010";
        ram[5] = "0b011000111111110101000101110001001111100011001010000100100110";
        ram[6] = "0b001011110000110100100001011110101011111100111000100101011001";
        ram[7] = "0b101010010001100010111000100001111110001111011000001101001011";
        ram[8] = "0b010111011000001010010101010111100011000110001111111001111010";
        ram[9] = "0b011000100111100111010001000100010001110000000101110011110001";
        ram[10] = "0b110010111110001101000110000011111010011010111000000010000110";
        ram[11] = "0b101101010000101101111000111110100110001100100010100100001000";
        ram[12] = "0b001111001011010100101110110101100001000001000001001111100110";
        ram[13] = "0b100001010010011111101100110100001100110101000101111101001011";
        ram[14] = "0b101101000011111011000100001111110000011010001101010011101110";
        ram[15] = "0b111100110111011101101100101100101110000110110111000001001111";


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


SC_MODULE(range_red_logtablibs) {


static const unsigned DataWidth = 60;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablibs_ram* meminst;


SC_CTOR(range_red_logtablibs) {
meminst = new range_red_logtablibs_ram("range_red_logtablibs_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablibs() {
    delete meminst;
}


};//endmodule
#endif
