// ==============================================================
// File generated on Thu May 30 19:18:46 +0200 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __range_red_logtablfYi_H__
#define __range_red_logtablfYi_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct range_red_logtablfYi_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 10;
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


   SC_CTOR(range_red_logtablfYi_ram) {
        ram[0] = "0b0000000000";
        ram[1] = "0b0000100000";
        ram[2] = "0b0001100000";
        ram[3] = "0b0010100000";
        ram[4] = "0b0011100000";
        ram[5] = "0b0100100000";
        ram[6] = "0b0101100000";
        ram[7] = "0b0110100000";
        ram[8] = "0b0111100000";
        ram[9] = "0b1000100000";
        ram[10] = "0b1001100000";
        ram[11] = "0b1010100000";
        ram[12] = "0b1011100000";
        ram[13] = "0b1100100000";
        ram[14] = "0b1101100000";
        ram[15] = "0b1110100000";


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


SC_MODULE(range_red_logtablfYi) {


static const unsigned DataWidth = 10;
static const unsigned AddressRange = 16;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


range_red_logtablfYi_ram* meminst;


SC_CTOR(range_red_logtablfYi) {
meminst = new range_red_logtablfYi_ram("range_red_logtablfYi_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~range_red_logtablfYi() {
    delete meminst;
}


};//endmodule
#endif
