// ==============================================================
// File generated on Thu May 30 19:18:46 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablhbi_H__
#define __range_red_logtablhbi_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablhbi_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 60;
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


   SC_CTOR(range_red_logtablhbi_ram) {
        ram[0] = "0b000000000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b000000000000000000000000000000000000000000000000000000000000";
        ram[2] = "0b011000100111100111010001000100010001110000000101110011110001";
        ram[3] = "0b010110101100111100011101000000110100010001010001111111101100";
        ram[4] = "0b001011101010110010100100110001000101011100001110101011110101";
        ram[5] = "0b100000100010011111100100011110111101111000110011100010110100";
        ram[6] = "0b011010110101010000111101101100011111101110000010100100101110";
        ram[7] = "0b011010110101010000111101101100011111101110000010100100101110";
        ram[8] = "0b001111001000101011011001111000110110111100101011111010100111";
        ram[9] = "0b011011001011001110110011011110010111110110011001010000011001";
        ram[10] = "0b011011001011001110110011011110010111110110011001010000011001";
        ram[11] = "0b001000100110100110110111001001001111000001110111110101101110";
        ram[12] = "0b001000100110100110110111001001001111000001110111110101101110";
        ram[13] = "0b000011100111000101000111101011111001110000100000010110010011";
        ram[14] = "0b000011100111000101000111101011111001110000100000010110010011";
        ram[15] = "0b011101111011000000101010001101111101101111001101111110110110";
        ram[16] = "0b100010100011110111000101100111101100011110100110011011011101";
        ram[17] = "0b101010001010100010110011111000111111100011000110011100000110";
        ram[18] = "0b100100101010000111000001110101010111001010101010101110011010";
        ram[19] = "0b100100101010000111000001110101010111001010101010101110011010";
        ram[20] = "0b001110000110010101100101110111100101001111011010001001111111";
        ram[21] = "0b011000110000101110101001010010111000100110111110110011111001";
        ram[22] = "0b100011110101100001101100001011000011011110001100000111100000";
        ram[23] = "0b100011110101100001101100001011000011011110001100000111100000";
        ram[24] = "0b000001111110000000001010110111001011001111111010001000111001";
        ram[25] = "0b010010001110101010000110100011010000101100001010101111000001";
        ram[26] = "0b010010001110101010000110100011010000101100001010101111000001";
        ram[27] = "0b101110101000110101001010010110100011001000001101101100110011";
        ram[28] = "0b101110101000110101001010010110100011001000001101101100110011";
        ram[29] = "0b110011111111101110100111010101100110011110100000110011011011";
        ram[30] = "0b110011111111101110100111010101100110011110100000110011011011";
        ram[31] = "0b100111100011000011111001100111111111011001100000111000001000";


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


SC_MODULE(range_red_logtablhbi) {


static const unsigned DataWidth = 60;
static const unsigned AddressRange = 32;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablhbi_ram* meminst;


SC_CTOR(range_red_logtablhbi) {
meminst = new range_red_logtablhbi_ram("range_red_logtablhbi_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablhbi() {
    delete meminst;
}


};//endmodule
#endif
