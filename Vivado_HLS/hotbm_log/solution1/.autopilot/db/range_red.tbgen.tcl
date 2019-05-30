set moduleName range_red
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {range_red}
set C_modelType { int 192 }
set C_modelArgList {
	{ A uint 5 regular  }
	{ Y0 int 54 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "A", "interface" : "wire", "bitwidth" : 5, "direction" : "READONLY"} , 
 	{ "Name" : "Y0", "interface" : "wire", "bitwidth" : 54, "direction" : "READONLY"} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 192} ]}
# RTL Port declarations: 
set portNum 11
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ A sc_in sc_lv 5 signal 0 } 
	{ Y0 sc_in sc_lv 54 signal 1 } 
	{ ap_return_0 sc_out sc_lv 64 signal -1 } 
	{ ap_return_1 sc_out sc_lv 64 signal -1 } 
	{ ap_return_2 sc_out sc_lv 64 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "A", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "A", "role": "default" }} , 
 	{ "name": "Y0", "direction": "in", "datatype": "sc_lv", "bitwidth":54, "type": "signal", "bundle":{"name": "Y0", "role": "default" }} , 
 	{ "name": "ap_return_0", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ap_return_0", "role": "default" }} , 
 	{ "name": "ap_return_1", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ap_return_1", "role": "default" }} , 
 	{ "name": "ap_return_2", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ap_return_2", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17"],
		"CDFG" : "range_red",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "18", "EstimateLatencyMax" : "18",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "A", "Type" : "None", "Direction" : "I"},
			{"Name" : "Y0", "Type" : "None", "Direction" : "I"},
			{"Name" : "invtable0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable0_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable1_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable2_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable3_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable4_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable5_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable0_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable2_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable3_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable4_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable5_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "logtable8", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.invtable0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable0_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable1_1_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable2_1_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable3_1_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable4_1_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable5_1_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable0_0_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable1_0_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable2_0_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable3_0_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable4_0_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable5_0_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable6_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable7_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logtable8_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logd_mac_muladd_4ncg_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	range_red {
		A {Type I LastRead 0 FirstWrite -1}
		Y0 {Type I LastRead 2 FirstWrite -1}
		invtable0 {Type I LastRead -1 FirstWrite -1}
		logtable0_1 {Type I LastRead -1 FirstWrite -1}
		logtable1_1 {Type I LastRead -1 FirstWrite -1}
		logtable2_1 {Type I LastRead -1 FirstWrite -1}
		logtable3_1 {Type I LastRead -1 FirstWrite -1}
		logtable4_1 {Type I LastRead -1 FirstWrite -1}
		logtable5_1 {Type I LastRead -1 FirstWrite -1}
		logtable0_0 {Type I LastRead -1 FirstWrite -1}
		logtable1_0 {Type I LastRead -1 FirstWrite -1}
		logtable2_0 {Type I LastRead -1 FirstWrite -1}
		logtable3_0 {Type I LastRead -1 FirstWrite -1}
		logtable4_0 {Type I LastRead -1 FirstWrite -1}
		logtable5_0 {Type I LastRead -1 FirstWrite -1}
		logtable6 {Type I LastRead -1 FirstWrite -1}
		logtable7 {Type I LastRead -1 FirstWrite -1}
		logtable8 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "18", "Max" : "18"}
	, {"Name" : "Interval", "Min" : "18", "Max" : "18"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	A { ap_none {  { A in_data 0 5 } } }
	Y0 { ap_none {  { Y0 in_data 0 54 } } }
}
