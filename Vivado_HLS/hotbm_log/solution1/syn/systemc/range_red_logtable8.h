// ==============================================================
// File generated on Thu May 30 19:18:47 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtable8_H__
#define __range_red_logtable8_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtable8_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 58;
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


   SC_CTOR(range_red_logtable8_ram) {
        ram[0] = "0b0000000000000000000000000000000000000000000000000000000000";
        ram[1] = "0b0000100000000000000000000000000000010000000000000000000000";
        ram[2] = "0b0001100000000000000000000000000010010000000000000000000000";
        ram[3] = "0b0010100000000000000000000000000110010000000000000000000000";
        ram[4] = "0b0011100000000000000000000000001100010000000000000000000000";
        ram[5] = "0b0100100000000000000000000000010100010000000000000000000001";
        ram[6] = "0b0101100000000000000000000000011110010000000000000000000011";
        ram[7] = "0b0110100000000000000000000000101010010000000000000000000101";
        ram[8] = "0b0111100000000000000000000000111000010000000000000000001000";
        ram[9] = "0b1000100000000000000000000001001000010000000000000000001100";
        ram[10] = "0b1001100000000000000000000001011010010000000000000000010001";
        ram[11] = "0b1010100000000000000000000001101110010000000000000000011000";
        ram[12] = "0b1011100000000000000000000010000100010000000000000000011111";
        ram[13] = "0b1100100000000000000000000010011100010000000000000000101000";
        ram[14] = "0b1101100000000000000000000010110110010000000000000000110011";
        ram[15] = "0b1110100000000000000000000011010010010000000000000000111111";


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


SC_MODULE(range_red_logtable8) {


static const unsigned DataWidth = 58;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtable8_ram* meminst;


SC_CTOR(range_red_logtable8) {
meminst = new range_red_logtable8_ram("range_red_logtable8_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtable8() {
    delete meminst;
}


};//endmodule
#endif
