set moduleName logd
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
set C_modelName {logd}
set C_modelType { double 64 }
set C_modelArgList {
	{ x double 64 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "x", "interface" : "wire", "bitwidth" : 64, "direction" : "READONLY", "bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "x","cData": "double","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "ap_return", "interface" : "wire", "bitwidth" : 64,"bitSlice":[{"low":0,"up":63,"cElement": [{"cName": "return","cData": "double","bit_use": { "low": 0,"up": 63},"cArray": [{"low" : 0,"up" : 1,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 8
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ x sc_in sc_lv 64 signal 0 } 
	{ ap_return sc_out sc_lv 64 signal -1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "x", "direction": "in", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "x", "role": "default" }} , 
 	{ "name": "ap_return", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "ap_return", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "19"],
		"CDFG" : "logd",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "25",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_range_red_fu_446"}],
		"Port" : [
			{"Name" : "x", "Type" : "None", "Direction" : "I"},
			{"Name" : "invtable0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "invtable0"}]},
			{"Name" : "logtable0_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable0_1"}]},
			{"Name" : "logtable1_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable1_1"}]},
			{"Name" : "logtable2_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable2_1"}]},
			{"Name" : "logtable3_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable3_1"}]},
			{"Name" : "logtable4_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable4_1"}]},
			{"Name" : "logtable5_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable5_1"}]},
			{"Name" : "logtable0_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable0_0"}]},
			{"Name" : "logtable1_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable1_0"}]},
			{"Name" : "logtable2_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable2_0"}]},
			{"Name" : "logtable3_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable3_0"}]},
			{"Name" : "logtable4_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable4_0"}]},
			{"Name" : "logtable5_0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable5_0"}]},
			{"Name" : "logtable6", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable6"}]},
			{"Name" : "logtable7", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable7"}]},
			{"Name" : "logtable8", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_range_red_fu_446", "Port" : "logtable8"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446", "Parent" : "0", "Child" : ["2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18"],
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
	{"ID" : "2", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.invtable0_U", "Parent" : "1"},
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable0_1_U", "Parent" : "1"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable1_1_U", "Parent" : "1"},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable2_1_U", "Parent" : "1"},
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable3_1_U", "Parent" : "1"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable4_1_U", "Parent" : "1"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable5_1_U", "Parent" : "1"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable0_0_U", "Parent" : "1"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable1_0_U", "Parent" : "1"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable2_0_U", "Parent" : "1"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable3_0_U", "Parent" : "1"},
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable4_0_U", "Parent" : "1"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable5_0_U", "Parent" : "1"},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable6_U", "Parent" : "1"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable7_U", "Parent" : "1"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logtable8_U", "Parent" : "1"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_range_red_fu_446.logd_mac_muladd_4ncg_U1", "Parent" : "1"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.logd_mul_mul_9ns_ocq_U21", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	logd {
		x {Type I LastRead 0 FirstWrite -1}
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
		logtable8 {Type I LastRead -1 FirstWrite -1}}
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
	{"Name" : "Latency", "Min" : "1", "Max" : "25"}
	, {"Name" : "Interval", "Min" : "2", "Max" : "26"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	x { ap_none {  { x in_data 0 64 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
