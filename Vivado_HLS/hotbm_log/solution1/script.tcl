############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hotbm_log
set_top logd
add_files bambu_macros.h -cflags "-IC:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master"
add_files hotbm_logd.c -cflags "-IC:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master"
open_solution "solution1"
set_part {xc7vx690tffg1761-2}
create_clock -period 10 -name default
config_compile -no_signed_zeros=0 -unsafe_math_optimizations=0
config_sdx -optimization_level none -target none
config_schedule -effort medium -relax_ii_for_timing=0
#source "./hotbm_log/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
