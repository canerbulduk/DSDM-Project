# ==============================================================
# File generated on Thu May 30 19:18:50 +0200 2019
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files hotbm_logd.c -cflags -IC:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master
add_files bambu_macros.h -cflags -IC:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master
set_part xc7vx690tffg1761-2
create_clock -name default -period 10
set_clock_uncertainty 12.5% default
config_compile -no_signed_zeros=0
config_compile -unsafe_math_optimizations=0
config_sdx -optimization_level=none
config_sdx -target=none
config_schedule -effort=medium
config_schedule -relax_ii_for_timing=0
config_bind -effort=medium
