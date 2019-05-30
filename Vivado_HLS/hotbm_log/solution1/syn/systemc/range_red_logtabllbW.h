// ==============================================================
// File generated on Thu May 30 06:13:48 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtabllbW_H__
#define __range_red_logtabllbW_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtabllbW_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 56;
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


   SC_CTOR(range_red_logtabllbW_ram) {
        ram[0] = "0b00000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b00000000010000000000000000001010101010101010110010101010";
        ram[2] = "0b00000010010000000000000100100000000000001010001000000000";
        ram[3] = "0b00000110010000000000010100110101010110100011011101011010";
        ram[4] = "0b00001100010000000000111001001010101111010110110011000100";
        ram[5] = "0b00010100010000000001111001100000001100110100001001011100";
        ram[6] = "0b00011110010000000011011101110101110001111011100001010000";
        ram[7] = "0b00101010010000000101101110001011100010011100111011101110";
        ram[8] = "0b00111000010000001000110010100001100010111000011010100010";
        ram[9] = "0b01001000010000001100110010110111111000011101111111111111";
        ram[10] = "0b01011010010000010001110111001110101001001101101111000111";
        ram[11] = "0b01101110010000011000000111100101111011110111101011101101";
        ram[12] = "0b10000100010000011111101011111101110111111011111010011110";
        ram[13] = "0b10011100010000101000101100010110100101101010100001000110";
        ram[14] = "0b10110110010000110011010000110000001110000011100110010110";
        ram[15] = "0b11010010010000111111100001001010111010110111010010001000";


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


SC_MODULE(range_red_logtabllbW) {


static const unsigned DataWidth = 56;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtabllbW_ram* meminst;


SC_CTOR(range_red_logtabllbW) {
meminst = new range_red_logtabllbW_ram("range_red_logtabllbW_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtabllbW() {
    delete meminst;
}


};//endmodule
#endif
