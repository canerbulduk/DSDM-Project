// ==============================================================
// File generated on Thu May 30 06:13:47 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtabljbC_H__
#define __range_red_logtabljbC_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtabljbC_ram : public sc_core::sc_module {

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


   SC_CTOR(range_red_logtabljbC_ram) {
        ram[0] = "0b000000000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b010000000000001010101010110010101010110001000100010110011001";
        ram[2] = "0b010000000100100000001010001000011000010100001001100101101001";
        ram[3] = "0b010000010100110110100011100010001110001001101100110001111100";
        ram[4] = "0b010000111001001111010111001100111101110000111000010101010011";
        ram[5] = "0b010001111001101100110101100100011011101110111000101110000001";
        ram[6] = "0b010011011110010001111111011001100010100011110001101001010111";
        ram[7] = "0b010101101111000010100101111000010110011011111010110110000100";
        ram[8] = "0b011000110100000011001010101110001001111110001111111000010011";
        ram[9] = "0b011100110101011001000000001111100011110111011110011100000010";
        ram[10] = "0b100001111011001010001001011110100101100010011110100100010001";
        ram[11] = "0b101000001101011101011010010000110010101110000000011000110100";
        ram[12] = "0b101111110100011010010111010101011001111111111010110110101110";
        ram[13] = "0b111000111000001001010110011011011110010110000111001001101001";
        ram[14] = "0b000011100000110011011110011000000001100101010100010111011111";
        ram[15] = "0b001111110110100010100111001100001111110101111111001001110100";


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


SC_MODULE(range_red_logtabljbC) {


static const unsigned DataWidth = 60;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtabljbC_ram* meminst;


SC_CTOR(range_red_logtabljbC) {
meminst = new range_red_logtabljbC_ram("range_red_logtabljbC_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtabljbC() {
    delete meminst;
}


};//endmodule
#endif
