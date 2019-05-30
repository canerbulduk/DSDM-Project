// ==============================================================
// File generated on Thu May 30 06:13:48 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablmb6_H__
#define __range_red_logtablmb6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablmb6_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 50;
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


   SC_CTOR(range_red_logtablmb6_ram) {
        ram[0] = "0b00000000000000000000000000000000000000000000000000";
        ram[1] = "0b00000000010000000000000000000001010101010101010101";
        ram[2] = "0b00000010010000000000000000100100000000000000001010";
        ram[3] = "0b00000110010000000000000010100110101010101011111000";
        ram[4] = "0b00001100010000000000000111001001010101011010000001";
        ram[5] = "0b00010100010000000000001111001100000000001100110100";
        ram[6] = "0b00011110010000000000011011101110101011000111010000";
        ram[7] = "0b00101010010000000000101101110001010110001101000111";
        ram[8] = "0b00111000010000000001000110010100000001100010111000";
        ram[9] = "0b01001000010000000001100110010110101101001101110010";
        ram[10] = "0b01011010010000000010001110111001011001010011110111";
        ram[11] = "0b01101110010000000011000000111100000101111011110110";
        ram[12] = "0b10000100010000000011111101011110110011001101001111";
        ram[13] = "0b10011100010000000101000101100001100001010000010001";
        ram[14] = "0b10110110010000000110011010000100010000001101111110";
        ram[15] = "0b11010010010000000111111100000111000000010000000101";


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


SC_MODULE(range_red_logtablmb6) {


static const unsigned DataWidth = 50;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablmb6_ram* meminst;


SC_CTOR(range_red_logtablmb6) {
meminst = new range_red_logtablmb6_ram("range_red_logtablmb6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablmb6() {
    delete meminst;
}


};//endmodule
#endif
