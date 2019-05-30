// ==============================================================
// File generated on Thu May 30 19:18:46 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_invtable0_H__
#define __range_red_invtable0_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_invtable0_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 6;
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


   SC_CTOR(range_red_invtable0_ram) {
        ram[0] = "0b100000";
        ram[1] = "0b100000";
        ram[2] = "0b011111";
        ram[3] = "0b011110";
        ram[4] = "0b011101";
        ram[5] = "0b011100";
        ram[6] = "0b011011";
        ram[7] = "0b011011";
        ram[8] = "0b011010";
        ram[9] = "0b011001";
        ram[10] = "0b011001";
        ram[11] = "0b011000";
        ram[12] = "0b011000";
        ram[13] = "0b010111";
        ram[14] = "0b010111";
        ram[15] = "0b010110";
        ram[16] = "0b101011";
        ram[17] = "0b101010";
        ram[18] = "0b101001";
        ram[19] = "0b101001";
        ram[20] = "0b101000";
        ram[21] = "0b100111";
        ram[22] = "0b100110";
        ram[23] = "0b100110";
        ram[24] = "0b100101";
        ram[25] = "0b100100";
        ram[26] = "0b100100";
        ram[27] = "0b100011";
        ram[28] = "0b100011";
        ram[29] = "0b100010";
        ram[30] = "0b100010";
        ram[31] = "0b100001";


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


SC_MODULE(range_red_invtable0) {


static const unsigned DataWidth = 6;
static const unsigned AddressRange = 32;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_invtable0_ram* meminst;


SC_CTOR(range_red_invtable0) {
meminst = new range_red_invtable0_ram("range_red_invtable0_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_invtable0() {
    delete meminst;
}


};//endmodule
#endif
