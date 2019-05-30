# 1 "hotbm_logd.c"
# 1 "hotbm_logd.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "C:/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 300 "C:/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "hotbm_logd.c" 2
# 1 "./bambu_macros.h" 1
# 46 "./bambu_macros.h"
# 1 "./boost/preprocessor/arithmetic/inc.hpp" 1
# 17 "./boost/preprocessor/arithmetic/inc.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "./boost/preprocessor/arithmetic/inc.hpp" 2
# 46 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/arithmetic/mod.hpp" 1
# 17 "./boost/preprocessor/arithmetic/mod.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/inc.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/dec.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/dec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/dec.hpp" 2
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 2
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2








# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 2
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 2
# 41 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/expr_iif.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/expr_iif.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/expr_iif.hpp" 2
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/is_binary.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/is_binary.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/is_binary.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/check.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/check.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/check.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/check.hpp" 2
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/is_binary.hpp" 2
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/adt.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_left.hpp" 2
# 42 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 2
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 2
# 37 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_right.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_right.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_right.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/reverse.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/reverse.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/reverse.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_left.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/reverse.hpp" 2
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/detail/fold_right.hpp" 2
# 38 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/list/fold_right.hpp" 2
# 23 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp" 2
# 24 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 48 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/detail/while.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/detail/while.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/detail/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 2
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/detail/while.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/detail/while.hpp" 2
# 49 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/overload.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/overload.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/overload.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/size.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/size.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/size.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/size.hpp" 2
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/overload.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/overload.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 2
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/elem.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/elem.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/elem.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/variadic/elem.hpp" 2
# 23 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 2
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 2
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 1
# 23 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 1
# 24 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/detail/div_base.hpp" 2
# 18 "./boost/preprocessor/arithmetic/mod.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "./boost/preprocessor/arithmetic/mod.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 1
# 20 "./boost/preprocessor/arithmetic/mod.hpp" 2
# 47 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/arithmetic/sub.hpp" 1
# 48 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/equal.hpp" 1
# 17 "./boost/preprocessor/comparison/equal.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp" 2
# 18 "./boost/preprocessor/comparison/equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "./boost/preprocessor/comparison/equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp" 1
# 20 "./boost/preprocessor/comparison/equal.hpp" 2
# 49 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/greater_equal.hpp" 1
# 17 "./boost/preprocessor/comparison/greater_equal.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 1
# 18 "./boost/preprocessor/comparison/greater_equal.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "./boost/preprocessor/comparison/greater_equal.hpp" 2
# 50 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/greater.hpp" 1
# 17 "./boost/preprocessor/comparison/greater.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less_equal.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/not_equal.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp" 1
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 23 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/comparison/less.hpp" 2
# 18 "./boost/preprocessor/comparison/greater.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "./boost/preprocessor/comparison/greater.hpp" 2
# 51 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/less_equal.hpp" 1
# 52 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/less.hpp" 1
# 53 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/comparison/not_equal.hpp" 1
# 54 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/debug/assert.hpp" 1
# 17 "./boost/preprocessor/debug/assert.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "./boost/preprocessor/debug/assert.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/expr_iif.hpp" 1
# 19 "./boost/preprocessor/debug/assert.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 20 "./boost/preprocessor/debug/assert.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 1
# 21 "./boost/preprocessor/debug/assert.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 22 "./boost/preprocessor/debug/assert.hpp" 2
# 55 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/empty.hpp" 1
# 15 "./boost/preprocessor/empty.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/facilities/empty.hpp" 1
# 16 "./boost/preprocessor/empty.hpp" 2
# 56 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/if.hpp" 1
# 15 "./boost/preprocessor/if.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/if.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/if.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/if.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/if.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/if.hpp" 2
# 16 "./boost/preprocessor/if.hpp" 2
# 57 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/logical.hpp" 1
# 17 "./boost/preprocessor/logical.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/and.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/and.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/and.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/and.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/and.hpp" 2
# 18 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitand.hpp" 1
# 19 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitnor.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitnor.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitnor.hpp" 2
# 20 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitor.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitor.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitor.hpp" 2
# 21 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitxor.hpp" 1
# 15 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitxor.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 16 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitxor.hpp" 2
# 22 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 23 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/compl.hpp" 1
# 24 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/nor.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/nor.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/nor.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/nor.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitnor.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/nor.hpp" 2
# 25 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/not.hpp" 1
# 26 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/or.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/or.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/or.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/or.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitor.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/or.hpp" 2
# 27 "./boost/preprocessor/logical.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/xor.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/xor.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/xor.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/xor.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bitxor.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/xor.hpp" 2
# 28 "./boost/preprocessor/logical.hpp" 2
# 58 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/repetition/for.hpp" 1
# 17 "./boost/preprocessor/repetition/for.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 18 "./boost/preprocessor/repetition/for.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 19 "./boost/preprocessor/repetition/for.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 20 "./boost/preprocessor/repetition/for.hpp" 2
# 42 "./boost/preprocessor/repetition/for.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/expr_iif.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/iif.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/logical/bool.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/detail/for.hpp" 2
# 43 "./boost/preprocessor/repetition/for.hpp" 2
# 59 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/repetition/repeat_from_to.hpp" 1
# 17 "./boost/preprocessor/repetition/repeat_from_to.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/dec.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/inc.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 1
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/add.hpp" 2
# 18 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/arithmetic/sub.hpp" 1
# 19 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 20 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 21 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/control/while.hpp" 1
# 22 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 23 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 24 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 1
# 17 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/cat.hpp" 1
# 18 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 19 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/debug/error.hpp" 1
# 20 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 1
# 12 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp"
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost\\preprocessor\\config\\config.hpp" 1
# 13 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/detail/auto_rec.hpp" 2
# 21 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/eat.hpp" 1
# 22 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/repetition/repeat.hpp" 2
# 25 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/elem.hpp" 1
# 26 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 1 "C:/Users/caner/Desktop/hotbm_log/Boost-Preprocessor-master\\boost/preprocessor/tuple/rem.hpp" 1
# 27 "./boost/preprocessor/repetition/repeat_from_to.hpp" 2
# 60 "./bambu_macros.h" 2

# 1 "./boost/preprocessor/tuple/elem.hpp" 1
# 61 "./bambu_macros.h" 2
# 2 "hotbm_logd.c" 2
# 30 "hotbm_logd.c"
typedef union{
 unsigned long long int b;
 double f;
} double_uint_converter;
# 52 "hotbm_logd.c"
static inline
void range_red(unsigned char A, unsigned long long int Y0, unsigned long long int* Zfinal, unsigned long long int* almostLog_H, unsigned long long int* almostLog_L)
{

 static const unsigned char invtable0[] = { 32,32,31,30,29,28,27,27,26,25,25,24,24,23,23,22,43,42,41,41,40,39,38,38,37,36,36,35,35,34,34,33 };
_ssdm_SpecConstant(invtable0);
# 56 "hotbm_logd.c"

 static const unsigned long long int logtable0_1[] = { 0,0,266327,541388,825775,1120142,1425216,1425216,1741805,2070812,2070812,2413252,2413252,2770268,2770268,3143156,5910074,6107462,6309607,6309607,6516744,6729125,6947023,6947023,7170733,7400572,7400572,7636886,7636886,7880051,7880051,8130476 };
_ssdm_SpecConstant(logtable0_1);
# 57 "hotbm_logd.c"

 static const unsigned long long int logtable1_1[] = { 0,16400,49296,82322,115479,148767,182188,215742,232570,266327,300220,334251,368421,402730,437180,471772 };
_ssdm_SpecConstant(logtable1_1);
# 58 "hotbm_logd.c"

 static const unsigned long long int logtable2_1[] = { 0,2048,6146,10246,14348,18452,22558,26666,30776,34888,39002,43118,47236,51356,55479,59603 };
_ssdm_SpecConstant(logtable2_1);
# 59 "hotbm_logd.c"

 static const unsigned long long int logtable3_1[] = { 0,256,768,1280,1792,2304,2816,3328,3840,4353,4865,5377,5890,6402,6914,7427 };
_ssdm_SpecConstant(logtable3_1);
# 60 "hotbm_logd.c"

 static const unsigned long long int logtable4_1[] = {0,32,96,160,224,288,352,416,480,544,608,672,736,800,864,928};
_ssdm_SpecConstant(logtable4_1);
# 61 "hotbm_logd.c"

 static const unsigned long long int logtable5_1[] = { 0,4,12,20,28,36,44,52,60,68,76,84,92,100,108,116 };
_ssdm_SpecConstant(logtable5_1);
# 62 "hotbm_logd.c"


 static const unsigned long long int logtable0_0[] = {0, 0, 443495784957107441, 408967542716309484, 210202761557502709, 586169748105148596, 483367143421258030, 483367143421258030, 272658672494231207, 489550094456689689, 489550094456689689, 154982152445328750, 154982152445328750, 65043238028969363, 65043238028969363, 539027481613361078, 622583452284905181, 759572586635749126, 660371207705242522, 660371207705242522, 253985390270980735, 446061511024831737, 645570292658782688, 645570292658782688, 35466593504830009, 328384990975929281, 328384990975929281, 840155138376129331, 840155138376129331, 936672260909567195, 936672260909567195, 712430320143961608};
_ssdm_SpecConstant(logtable0_0);
# 64 "hotbm_logd.c"

 static const unsigned long long int logtable1_0[] = {0, 24054437449941404, 651381705105933614, 718720183519062944, 253546689982371970, 450311980697035046, 211900181597358425, 761543230352098123, 421132014018166394, 443495784957107441, 918228965153013894, 815353360150571272, 273403381874430950, 599681119542337355, 811752134397187310, 1096475649311993935};
_ssdm_SpecConstant(logtable1_0);
# 65 "hotbm_logd.c"

 static const unsigned long long int logtable2_0[] = {0, 288277297239442841, 289497709739546985, 294099812123855996, 304342014990976339, 322486043632438145, 350796944522549847, 391543091824143748, 446996193910259219, 519431299901810434, 611126806221285649, 724364463162525236, 861429381476625838, 1024610038974018153, 63276782535919071, 285567853176287860};
_ssdm_SpecConstant(logtable2_0);
# 66 "hotbm_logd.c"

 static const unsigned long long int logtable3_0[] = {0, 4503691255436680, 40534870717378714, 112601445241265087, 220707814484637524, 364858378910835840, 545057539789194721, 761309699195240573, 1013619260010888437, 149069121317791972, 473506696824928394, 834014887227713707, 77676594028740779, 510339233358517480, 979085708334582096, 330998922882241584};
_ssdm_SpecConstant(logtable3_0);
# 67 "hotbm_logd.c"

 static const unsigned long long int logtable4_0[] = {0, 70368923135146, 633323529478656, 1759240974382938, 3448129848175812, 5699998741381724, 8514856244721744, 11892710949113582, 15833571445671586, 20337446325706751, 25404344180726727, 31034273602435821, 37227243182735006, 43983261513721926, 51302337187690902, 59184478797132936};
_ssdm_SpecConstant(logtable4_0);
# 68 "hotbm_logd.c"

 static const unsigned long long int logtable5_0[] = {0, 1099511977301, 9895614087178, 27487834385144, 53876189648513, 89060696654644, 133041372180944, 185818233004871, 247391295903928, 317760577655666, 396926095037687, 484887864827638, 581645903803215, 687200228742161, 801550856422270, 924697803621381};
_ssdm_SpecConstant(logtable5_0);
# 69 "hotbm_logd.c"


 static const unsigned long long int logtable6[] = {0 ,576460769483293354ULL,1729382411529111552ULL, 2882304191013932373ULL, 4035226107937788586ULL, 5188148162300712960ULL, 6341070354102738261ULL, 7493992683343897259ULL, 8646915150024222721ULL, 9799837754143747415ULL, 10952760495702504110ULL, 12105683374700525573ULL, 13258606391137844573ULL, 14411529545014493878ULL, 15564452836330506256ULL, 16717376265085914474ULL};
_ssdm_SpecConstant(logtable6);
# 71 "hotbm_logd.c"

 static const unsigned long long int logtable7[] = {0,72057594306363393,216172784529702948,360287976900526246,504403171418833353,648518368084624332,792633566897899246,936748767858658161,1080863970966901140,1224979176222628246,1369094383625839545,1513209593176535100,1657324804874714974,1801440018720379233,1945555234713527940,2089670452854161158};
_ssdm_SpecConstant(logtable7);
# 72 "hotbm_logd.c"

 static const unsigned long long int logtable8[] = {0,9007199258935296,27021597801971712,45035996378562560,63050394988707840,81064793632407553,99079192309661699,117093591020470277,135107989764833288,153122388542750732,171136787354222609,189151186199248920,207165585077829663,225179983989964840,243194382935654451,261208781914898495};
_ssdm_SpecConstant(logtable8);
# 73 "hotbm_logd.c"



 unsigned char A0, A1, A2, A3, A4, A5, A6, A7, A8;
 unsigned long long int B1, B2, B3_0, B4_0, B5_0, B6, B7, B8;
 unsigned long long int B3_1, B4_1, B5_1;
 unsigned long long int P0, P1, P2_0, P3_0, P4_0, P5, P6, P7, P8;
 unsigned int P2_1, P3_1, P4_1;
 unsigned long long int ZM1, ZM2, ZM3, ZM4, ZM5, ZM6, ZM7, ZM8;
 unsigned long long int epsZ1, epsZ2_0, epsZ3_0, epsZ4_0, epsZ5_0, epsZ6_0, epsZ7_0, epsZ8_0;
 unsigned long int epsZ2_1, epsZ3_1, epsZ4_1, epsZ5_1, epsZ6_1, epsZ7_1, epsZ8_1;
 unsigned long long int Z, Z3_0, Z4_0, Z5_0, Z6_0, Z7_0, Z8_0, Z9;
 unsigned long int Z3_1, Z4_1, Z5_1, Z6_1;
 unsigned long long int Z1_d, Z2_d, Z3_d_0, Z4_d_0, Z5_d_0, Z6_d, Z7_d, Z8_d;
 unsigned long int Z3_d_1, Z4_d_1, Z5_d_1;
 unsigned char InvA0;

 A0 = A;
 InvA0 = invtable0[A0];
 P0 = InvA0 * Y0;

 Z1_d = ((unsigned long long) (((((unsigned long long)(P0))>>(0))&((unsigned long long)(18014398509481984ULL -1)))));

 A1 = ((unsigned long long) (((((unsigned long long)(Z1_d))>>(50))&((unsigned long long)(16ULL -1)))));
 B1 = ((unsigned long long) (((((unsigned long long)(Z1_d))>>(0))&((unsigned long long)(1125899906842624ULL -1)))));
 ZM1 = Z1_d;
 P1 = A1 * ZM1;






 epsZ1 = A1 == 0 ? 0 : (((unsigned long long)1 << 58) | Z1_d);
 epsZ1 = (((A1)>>(3))&1) == 0 ? epsZ1 : epsZ1 << 1;

 Z2_d = (B1<<9) - (P1<<1) + epsZ1;

 A2 = ((unsigned long long) (((((unsigned long long)(Z2_d))>>(56))&((unsigned long long)(16ULL -1)))));
 B2 = ((unsigned long long) (((((unsigned long long)(Z2_d))>>(0))&((unsigned long long)(72057594037927936ULL -1)))));
 ZM2 = Z2_d;


 P2_0=ZM2*A2;
 P2_1 = ((unsigned long long) (((((unsigned long long)(P2_0))>>(60))&((unsigned long long)(16ULL -1)))));
 P2_0=((unsigned long long) (((P2_0)&((unsigned long long)(1152921504606846976ULL -1)))));
 epsZ2_0 = A2==0 ? 0 : Z2_d;
 epsZ2_1 = A2==0 ? 0 : 1<<7;
 Z3_0 = ((unsigned long long) (((((unsigned long long)(epsZ2_0))>>(0))&((unsigned long long)(1152921504606846976ULL -1))))) + (((unsigned long long) (((((unsigned long long)(B2))>>(0))&((unsigned long long)(281474976710656ULL -1)))))<<12) - (((unsigned long long) (((((unsigned long long)(P2_0))>>(0))&((unsigned long long)(576460752303423488ULL -1)))))<<1);
 Z3_1 = ((unsigned long long) (((((unsigned long long)(epsZ2_1))>>(0))&((unsigned long long)(512ULL -1))))) + ((unsigned long long) (((((unsigned long long)(B2))>>(48))&((unsigned long long)(256ULL -1))))) - (((P2_0)>>(59))&1) - ((unsigned long long)P2_1<<1);
 Z3_1 = ((unsigned long long) (((((unsigned long long)(Z3_0))>>(60))&((unsigned long long)(16ULL -1))))) == 0b1111 ? Z3_1 - 1 : Z3_1 + (((Z3_0)>>(60))&1);
 Z3_0=((unsigned long long) (((Z3_0)&((unsigned long long)(1152921504606846976ULL -1)))));
 Z3_1=((unsigned long long) (((Z3_1)&((unsigned long long)(512ULL -1)))));

 Z3_d_0 = Z3_0;
 Z3_d_1 = Z3_1;

 A3 = ((unsigned long long) (((((unsigned long long)(Z3_d_1))>>(5))&((unsigned long long)(16ULL -1)))));
 B3_1 = ((unsigned long long) (((((unsigned long long)(Z3_d_1))>>(0))&((unsigned long long)(32ULL -1)))));
 B3_0 = Z3_d_0;
 ZM3 = (((unsigned long long) (((((unsigned long long)(Z3_d_1))>>(0))&((unsigned long long)(512ULL -1)))))<<54) | ((unsigned long long) (((((unsigned long long)(Z3_d_0))>>(6))&((unsigned long long)(18014398509481984ULL -1)))));
 P3_0 = ((unsigned long long) (((((unsigned long long)(ZM3))>>(0))&((unsigned long long)(1152921504606846976ULL -1))))) * A3;
 P3_1 = ((unsigned long long) (((((unsigned long long)(ZM3))>>(60))&((unsigned long long)(8ULL -1))))) * A3 + ((unsigned long long) (((((unsigned long long)(P3_0))>>(60))&((unsigned long long)(16ULL -1)))));
 P3_0=((unsigned long long) (((P3_0)&((unsigned long long)(1152921504606846976ULL -1)))));
 epsZ3_0 = A3 == 0 ? 0 : Z3_d_0;
 epsZ3_1 = A3 == 0 ? 0 : (1 << 19) | Z3_d_1;
 Z4_0 = (((unsigned long long) (((((unsigned long long)(B3_0))>>(0))&((unsigned long long)(72057594037927936ULL -1)))))<<4)
   + ((unsigned long long) (((((unsigned long long)(epsZ3_0))>>(11))&((unsigned long long)(562949953421312ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ3_1))>>(0))&((unsigned long long)(2048ULL -1)))))<<49)
   - ((unsigned long long) (((((unsigned long long)(P3_0))>>(4))&((unsigned long long)(72057594037927936ULL -1))))) - (((unsigned long long) (((((unsigned long long)(P3_1))>>(0))&((unsigned long long)(16ULL -1)))))<<56);
 Z4_1 = ((unsigned long long) (((((unsigned long long)(B3_0))>>(56))&((unsigned long long)(16ULL -1))))) + (B3_1 << 4)
  + ((unsigned long long) (((((unsigned long long)(epsZ3_1))>>(11))&((unsigned long long)(1024ULL -1)))))
  - ((unsigned long long) (((((unsigned long long)(P3_1))>>(4))&((unsigned long long)(8ULL -1)))));
 Z4_1 = ((unsigned long long) (((((unsigned long long)(Z4_0))>>(60))&((unsigned long long)(16ULL -1))))) == 0b1111 ? Z4_1 - 1 : Z4_1 + (((Z4_0)>>(60))&1);
 Z4_0=((unsigned long long) (((Z4_0)&((unsigned long long)(1152921504606846976ULL -1)))));

 Z4_d_0 = Z4_0;
 Z4_d_1 = Z4_1;

 A4 = ((unsigned long long) (((((unsigned long long)(Z4_d_1))>>(6))&((unsigned long long)(16ULL -1)))));
 B4_1 = ((unsigned long long) (((((unsigned long long)(Z4_d_1))>>(0))&((unsigned long long)(64ULL -1)))));
 B4_0 = Z4_d_0;
 ZM4 = (((unsigned long long) (((((unsigned long long)(Z4_d_1))>>(0))&((unsigned long long)(1024ULL -1))))) << 47) | ((unsigned long long) (((((unsigned long long)(Z4_d_0))>>(13))&((unsigned long long)(140737488355328ULL -1)))));
 P4_0 = ZM4 * A4;
 P4_1 = (((P4_0)>>(60))&1);
 P4_0=((unsigned long long) (((P4_0)&((unsigned long long)(1152921504606846976ULL -1)))));
 epsZ4_0 = A4 == 0 ? 0 : Z4_d_0;
 epsZ4_1 = A4 == 0 ? 0 : (1 << 23) | Z4_d_1;
 Z5_0 = B4_0
   + ((unsigned long long) (((((unsigned long long)(epsZ4_0))>>(18))&((unsigned long long)(4398046511104ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ4_1))>>(0))&((unsigned long long)(262144ULL -1)))))<<42)
   - ((unsigned long long) (((((unsigned long long)(P4_0))>>(4))&((unsigned long long)(72057594037927936ULL -1))))) - ((unsigned long long)(((P4_1)>>(0))&1)<<56);
 Z5_1 = B4_1 + ((unsigned long long) (((((unsigned long long)(epsZ4_1))>>(18))&((unsigned long long)(128ULL -1)))));
 Z5_1 = ((unsigned long long) (((((unsigned long long)(Z5_0))>>(60))&((unsigned long long)(16ULL -1))))) == 0b1111 ? Z5_1 - 1 : Z5_1 + (((Z5_0)>>(60))&1);
 Z5_0=((unsigned long long) (((Z5_0)&((unsigned long long)(1152921504606846976ULL -1)))));

 Z5_d_0 = Z5_0;
 Z5_d_1 = Z5_1;

 A5 = ((unsigned long long) (((((unsigned long long)(Z5_d_1))>>(3))&((unsigned long long)(16ULL -1)))));
 B5_1 = ((unsigned long long) (((((unsigned long long)(Z5_d_1))>>(0))&((unsigned long long)(8ULL -1)))));
 B5_0 = Z5_d_0;
 ZM5 = (((unsigned long long) (((((unsigned long long)(Z5_d_1))>>(0))&((unsigned long long)(128ULL -1))))) << 44) | ((unsigned long long) (((((unsigned long long)(Z5_d_0))>>(16))&((unsigned long long)(17592186044416ULL -1)))));
 P5 = ZM5 * A5;
 epsZ5_0 = A5 == 0 ? 0 : Z5_d_0;
 epsZ5_1 = A5 == 0 ? 0 : (1 << 23) | Z5_d_1;
 Z6_0 = B5_0 + ((unsigned long long) (((((unsigned long long)(epsZ5_0))>>(21))&((unsigned long long)(549755813888ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ5_1))>>(0))&((unsigned long long)(2097152ULL -1)))))<<39) - ((unsigned long long) (((((unsigned long long)(P5))>>(4))&((unsigned long long)(2251799813685248ULL -1)))));
 Z6_1 = B5_1 + ((unsigned long long) (((((unsigned long long)(epsZ5_1))>>(21))&((unsigned long long)(16ULL -1))))) ;
 Z6_1 = ((unsigned long long) (((((unsigned long long)(Z6_0))>>(60))&((unsigned long long)(16ULL -1))))) == 0b1111 ? Z6_1 - 1 : Z6_1 + (((Z6_0)>>(60))&1);
 Z6_0=((unsigned long long) (((Z6_0)&((unsigned long long)(1152921504606846976ULL -1)))));
 Z6_d = (((unsigned long long) (((((unsigned long long)(Z6_1))>>(0))&((unsigned long long)(16ULL -1))))) << 60) | Z6_0;

 A6 = ((unsigned long long) (((((unsigned long long)(Z6_d))>>(60))&((unsigned long long)(16ULL -1)))));
 B6 = ((unsigned long long) (((((unsigned long long)(Z6_d))>>(0))&((unsigned long long)(1152921504606846976ULL -1)))));
 ZM6 = ((unsigned long long) (((((unsigned long long)(Z6_d))>>(19))&((unsigned long long)(35184372088832ULL -1)))));
 P6 = A6 * ZM6;
 epsZ6_0 = A6 == 0 ? 0 : ((unsigned long long) (((((unsigned long long)(Z6_d))>>(0))&((unsigned long long)(1152921504606846976ULL -1)))));
 epsZ6_1 = A6 == 0 ? 0 : (1 << 23) | ((unsigned long long) (((((unsigned long long)(Z6_d))>>(60))&((unsigned long long)(16ULL -1)))));
 Z7_0 = B6 + ((unsigned long long) (((((unsigned long long)(epsZ6_0))>>(24))&((unsigned long long)(68719476736ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ6_1))>>(0))&((unsigned long long)(33554432ULL -1)))))<<36) - ((unsigned long long) (((((unsigned long long)(P6))>>(4))&((unsigned long long)(35184372088832ULL -1)))));
 Z7_0=((unsigned long long) (((Z7_0)&((unsigned long long)(2305843009213693952ULL -1)))));



 Z7_d = Z7_0;


 A7 = ((unsigned long long) (((((unsigned long long)(Z7_d))>>(57))&((unsigned long long)(16ULL -1)))));
 B7 = ((unsigned long long) (((((unsigned long long)(Z7_d))>>(0))&((unsigned long long)(144115188075855872ULL -1)))));
 ZM7 = ((unsigned long long) (((((unsigned long long)(Z7_d))>>(22))&((unsigned long long)(549755813888ULL -1)))));
 P7 = A7 * ZM7;
 epsZ7_0 = A7 == 0 ? 0 : ((unsigned long long) (((((unsigned long long)(Z7_d))>>(0))&((unsigned long long)(1152921504606846976ULL -1)))));
 epsZ7_1 = A7 == 0 ? 0 : (1 << 23) | (((Z7_d)>>(60))&1);
 Z8_0 = B7 + ((unsigned long long) (((((unsigned long long)(epsZ7_0))>>(27))&((unsigned long long)(8589934592ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ7_1))>>(0))&((unsigned long long)(33554432ULL -1)))))<<33) - ((unsigned long long) (((((unsigned long long)(P7))>>(4))&((unsigned long long)(549755813888ULL -1)))));

 Z8_d = Z8_0;

 A8 = ((unsigned long long) (((((unsigned long long)(Z8_d))>>(54))&((unsigned long long)(16ULL -1)))));
 B8 = ((unsigned long long) (((((unsigned long long)(Z8_d))>>(0))&((unsigned long long)(18014398509481984ULL -1)))));
 ZM8 = ((unsigned long long) (((((unsigned long long)(Z8_d))>>(25))&((unsigned long long)(8589934592ULL -1)))));
 P8 = A8 * ZM8;
 epsZ8_0 = A8 == 0 ? 0 : Z8_d;
 epsZ8_1 = A8 == 0 ? 0 : (1 << 23);
 Z9 = B8 + ((unsigned long long) (((((unsigned long long)(epsZ8_0))>>(30))&((unsigned long long)(1073741824ULL -1))))) + (((unsigned long long) (((((unsigned long long)(epsZ8_1))>>(0))&((unsigned long long)(33554432ULL -1)))))<<30) - ((unsigned long long) (((((unsigned long long)(P8))>>(4))&((unsigned long long)(8589934592ULL -1)))));

 Z = Z9;





 unsigned long long int L0_0, L1_0, L2_0, L3_0, L4_0, L5_0, L6, L7, L8;
 unsigned long int L0_1, L1_1, L2_1, L3_1, L4_1, L5_1;
 unsigned long long int SUM_LS;
 unsigned long int SUM_MS;
 L0_1 = logtable0_1[A0];
 L1_1 = logtable1_1[A1];
 L2_1 = logtable2_1[A2];
 L3_1 = logtable3_1[A3];
 L4_1 = logtable4_1[A4];
 L5_1 = logtable5_1[A5];


 L0_0 = logtable0_0[A0];
 L1_0 = logtable1_0[A1];
 L2_0 = logtable2_0[A2];
 L3_0 = logtable3_0[A3];
 L4_0 = logtable4_0[A4];
 L5_0 = logtable5_0[A5];
 L6 = logtable6[A6];
 L7 = logtable7[A7];
 L8 = logtable8[A8];

 SUM_LS = L8 + ((unsigned long long) (((((unsigned long long)(L7))>>(0))&((unsigned long long)(1152921504606846976ULL -1))))) + ((unsigned long long) (((((unsigned long long)(L6))>>(0))&((unsigned long long)(1152921504606846976ULL -1))))) + L5_0 + L4_0 + L3_0 + L2_0 + L1_0 + L0_0;
 SUM_MS = ((unsigned long long) (((((unsigned long long)(SUM_LS))>>(60))&((unsigned long long)(16ULL -1))))) + ((unsigned long long) (((((unsigned long long)(L7))>>(60))&((unsigned long long)(16ULL -1))))) + ((unsigned long long) (((((unsigned long long)(L6))>>(60))&((unsigned long long)(16ULL -1))))) + L5_1 + L4_1 + L3_1 + L2_1 + L1_1 + L0_1;
 SUM_LS=((unsigned long long) (((SUM_LS)&((unsigned long long)(1152921504606846976ULL -1)))));

 *Zfinal = Z;
 *almostLog_H = SUM_MS;
 *almostLog_L = SUM_LS;
}



double logd(double x)
{
 static unsigned char wE = 11;
 static unsigned char wF = 52;
 static unsigned char g = 5;
 static unsigned char a0 = 5;
 static unsigned char log2wF = 6;
 static unsigned char targetprec = 83;
 static unsigned char sfinal = 55;
 static unsigned char pfinal = 28;
 static unsigned long long int log2 = 0b101100010111001000010111111101111101000111001111011110011;
 static unsigned short int E0offset = 0b10000001001;
 static unsigned char pfinal_s = 0b011100;
 static unsigned char lzc_size = 6;
 double_uint_converter func_in;
 unsigned long long int fpX;
 _Bool s, FirstBit, sR, small, doRR, ufl, sticky, round;
 unsigned long long int Y0, Log_small_normd, Log_g, EFR, Zfinal, Log1p_normal, Z2o2_full, Log_small, Z_small, Z2o2_small, ER, squarerIn, Z2o2_small_s, Z2o2;
 unsigned short int E, absE, E_small, E_normal, lzo, shiftval, E_normal_H, E_normal_L;
 unsigned int absZ0, absZ0s;
 unsigned char E0_sub;
 unsigned int absELog2_H;
 unsigned long long int absELog2_L;
 unsigned long long int Log_normal_normd_H, Log_normal_normd_L;
 unsigned long long int almostLog_H, almostLog_L,
       absELog2_pad_H, absELog2_pad_L,
       LogF_normal_H, LogF_normal_L,
       LogF_normal_pad_H, LogF_normal_pad_L,
       Log_normal_H, Log_normal_L;

 func_in.f = x;
 fpX = func_in.b;

 s = (((fpX)>>(63))&1);
 FirstBit = (((fpX)>>(51))&1);

 Y0 = FirstBit == 0 ? (((((unsigned long long)1) << (int)52) | ((unsigned long long) (((((unsigned long long)(fpX))>>(0))&((unsigned long long)(4503599627370496ULL -1)))))) << 1) : (((unsigned long long)1 << 52) | ((unsigned long long) (((((unsigned long long)(fpX))>>(0))&((unsigned long long)(4503599627370496ULL -1))))));
 E = ((unsigned long long) (((((unsigned long long)(fpX))>>(52))&((unsigned long long)(2048ULL -1))))) - ((0b111111111 << 1) | !FirstBit);
 E=((unsigned long long) (((E)&((unsigned long long)(2048ULL -1)))));
 sR = ((unsigned long long) (((((unsigned long long)(fpX))>>(52))&((unsigned long long)(2048ULL -1))))) == 0b1111111111 ? 0 : !(((fpX)>>(62))&1);
 absE = sR == 1 ? -E : E;
 absE=((unsigned long long) (((absE)&((unsigned long long)(2048ULL -1)))));


    if ((fpX & 0x7fffffffffffffff) == 0) return -__builtin_inf();



    if (fpX == 0x7FF0000000000000) return __builtin_inf();
    if (fpX == 0xFFF0000000000000) return __builtin_nan("");
    if (E==2047)
    {
        func_in.b |= ( 0xFFF << 51 );
        return func_in.f;
    }
    if (s==1) return __builtin_nan("");
    if(fpX == 0x3FF0000000000000) return 0;




 unsigned long int m1 = (log2 >> 49) * absE;
 unsigned long long int m0 = (log2 & ((1ULL << (49)) - 1)) * absE + ((m1 & ((1ULL << (11)) - 1)) << 49);
 absELog2_H = (unsigned int)(m1 >> 11) + (unsigned int)(m0 >> 60);
 absELog2_L = m0 & ((1ULL << (60)) - 1);


 if(FirstBit){ { _Bool _result_5=0; _Bool _result_4, _result_3, _result_2, _result_1, _result_0; unsigned long long _val4, _val8; unsigned long long _result=0; unsigned long long MAN_IN; if(52<=32) { MAN_IN = ((unsigned long long)0xffffffffffffff & ~((unsigned long long) (((((unsigned long long)(Y0))>>(1))&((unsigned long long)(4503599627370496ULL -1)))))) << 0; MAN_IN=((unsigned long long) (((MAN_IN)&((unsigned long long)(4294967296ULL -1))))); } else { MAN_IN = ((unsigned long long)0xffffffffffffff & ~((unsigned long long) (((((unsigned long long)(Y0))>>(1))&((unsigned long long)(4503599627370496ULL -1)))))) << 12; } _result_5 = 52<=32 || ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(4294967296ULL -1))))) == 0; _result_4 = (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(65536ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(65536ULL -1)))))) == 0; _result_3 = (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))) == 0; _result_2 = (_result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(4))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(36))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(20))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(52))&((unsigned long long)(16ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(12))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(44))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(28))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(60))&((unsigned long long)(16ULL -1)))))))) == 0; _val8 = _result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(0))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(256ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))); _val4 = _result_2 ? _val8&15 : (_val8>>4)&15; _result_1 = _val4 >> 2 == 0; _result_0 = _result_1 ? (~((_val4 & 2)>>1))&1 : (~((_val4&8)>>3))&1; if(52<=32) { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); lzo = _result; } else { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); _result = _result | (((unsigned long long)(_result_5)) << 5); lzo = _result; } lzo=((unsigned long long) (((lzo)&((unsigned long long)(64ULL -1)))));}; }
 else if (!FirstBit) { { _Bool _result_5=0; _Bool _result_4, _result_3, _result_2, _result_1, _result_0; unsigned long long _val4, _val8; unsigned long long _result=0; unsigned long long MAN_IN; if(52<=32) { MAN_IN = ((unsigned long long)((unsigned long long) (((((unsigned long long)(Y0))>>(1))&((unsigned long long)(4503599627370496ULL -1)))))) << 0; MAN_IN=((unsigned long long) (((MAN_IN)&((unsigned long long)(4294967296ULL -1))))); } else { MAN_IN = ((unsigned long long)((unsigned long long) (((((unsigned long long)(Y0))>>(1))&((unsigned long long)(4503599627370496ULL -1)))))) << 12; } _result_5 = 52<=32 || ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(4294967296ULL -1))))) == 0; _result_4 = (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(65536ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(65536ULL -1)))))) == 0; _result_3 = (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))) == 0; _result_2 = (_result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(4))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(36))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(20))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(52))&((unsigned long long)(16ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(12))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(44))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(28))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(60))&((unsigned long long)(16ULL -1)))))))) == 0; _val8 = _result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(0))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(256ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))); _val4 = _result_2 ? _val8&15 : (_val8>>4)&15; _result_1 = _val4 >> 2 == 0; _result_0 = _result_1 ? (~((_val4 & 2)>>1))&1 : (~((_val4&8)>>3))&1; if(52<=32) { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); lzo = _result; } else { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); _result = _result | (((unsigned long long)(_result_5)) << 5); lzo = _result; } lzo=((unsigned long long) (((lzo)&((unsigned long long)(64ULL -1)))));}; }
 lzo=((unsigned long long) (((lzo)&((unsigned long long)(64ULL -1)))));

    shiftval = lzo - pfinal_s;
    doRR = (((shiftval)>>(log2wF))&1);
    small = ((E==0) & (doRR==0)) ? 1 : 0;
    absZ0 = sR==0 ? ((unsigned long long) (((((unsigned long long)(Y0))>>(0))&((unsigned long long)(67108864ULL -1))))) : (0-((unsigned long long) (((((unsigned long long)(Y0))>>(0))&((unsigned long long)(67108864ULL -1))))));
 absZ0=((unsigned long long) (((absZ0)&((unsigned long long)(67108864ULL -1)))));


 unsigned char A = ((unsigned long long) (((((unsigned long long)(fpX))>>(47))&((unsigned long long)(32ULL -1)))));
 range_red(A, Y0, &Zfinal, &almostLog_H, &almostLog_L);


 shiftval=((unsigned long long) (((shiftval)&((unsigned long long)(128ULL -1)))));
 absZ0s = (unsigned long long)absZ0 << (shiftval);
 absZ0s=((unsigned long long) (((absZ0s)&((unsigned long long)(33554432ULL -1)))));
 squarerIn = doRR == 1 ? ((unsigned long long) (((((unsigned long long)(Zfinal))>>(28))&((unsigned long long)(134217728ULL -1))))) :(unsigned long long) absZ0s<<1;
 squarerIn=((unsigned long long) (((squarerIn)&((unsigned long long)(134217728ULL -1)))));
    Z2o2_full = squarerIn * squarerIn;
    Z2o2 = ((unsigned long long) (((((unsigned long long)(Z2o2_full))>>(26))&((unsigned long long)(268435456ULL -1)))));

    Log1p_normal = Zfinal - ((unsigned long long) (((((unsigned long long)(Z2o2))>>(2))&((unsigned long long)(67108864ULL -1)))));
 Log1p_normal=((unsigned long long) (((Log1p_normal)&((unsigned long long)(36028797018963968ULL -1)))));

   LogF_normal_L = almostLog_L + Log1p_normal;
 LogF_normal_H = almostLog_H + (((LogF_normal_L)>>(60))&1);
 LogF_normal_L=((unsigned long long) (((LogF_normal_L)&((unsigned long long)(1152921504606846976ULL -1)))));

 absELog2_pad_H = ((unsigned long long)absELog2_H << 26) | (((unsigned long long) (((((unsigned long long)(absELog2_L))>>(34))&((unsigned long long)(67108864ULL -1))))));
 absELog2_pad_L = ((unsigned long long) (((((unsigned long long)(absELog2_L))>>(0))&((unsigned long long)(17179869184ULL -1)))))<<26;

    LogF_normal_pad_L = LogF_normal_L;
 LogF_normal_pad_H = (((LogF_normal_H)>>(22))&1) ? ((unsigned long long)(0b11111111111)<<23) | LogF_normal_H : LogF_normal_H;

 Log_normal_L = sR == 0 ? (absELog2_pad_L + LogF_normal_pad_L) : absELog2_pad_L - LogF_normal_pad_L;
 Log_normal_H = sR == 0 ? (absELog2_pad_H + LogF_normal_pad_H + (((Log_normal_L)>>(60))&1)) : absELog2_pad_H - LogF_normal_pad_H - (((Log_normal_L)>>(60))&1);
 Log_normal_L=((unsigned long long) (((Log_normal_L)&((unsigned long long)(1152921504606846976ULL -1)))));


 { _Bool _result_5=0; _Bool _result_4, _result_3, _result_2, _result_1, _result_0; unsigned long long _val4, _val8; unsigned long long _result=0; unsigned long long MAN_IN; if(60<=32) { MAN_IN = ((unsigned long long)Log_normal_L) << 0; MAN_IN=((unsigned long long) (((MAN_IN)&((unsigned long long)(4294967296ULL -1))))); } else { MAN_IN = ((unsigned long long)Log_normal_L) << 4; } _result_5 = 60<=32 || ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(4294967296ULL -1))))) == 0; _result_4 = (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(65536ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(65536ULL -1)))))) == 0; _result_3 = (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))) == 0; _result_2 = (_result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(4))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(36))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(20))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(52))&((unsigned long long)(16ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(12))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(44))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(28))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(60))&((unsigned long long)(16ULL -1)))))))) == 0; _val8 = _result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(0))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(256ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))); _val4 = _result_2 ? _val8&15 : (_val8>>4)&15; _result_1 = _val4 >> 2 == 0; _result_0 = _result_1 ? (~((_val4 & 2)>>1))&1 : (~((_val4&8)>>3))&1; if(60<=32) { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); E_normal_L = _result; } else { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); _result = _result | (((unsigned long long)(_result_5)) << 5); E_normal_L = _result; } E_normal_L=((unsigned long long) (((E_normal_L)&((unsigned long long)(64ULL -1)))));};
 { _Bool _result_5=0; _Bool _result_4, _result_3, _result_2, _result_1, _result_0; unsigned long long _val4, _val8; unsigned long long _result=0; unsigned long long MAN_IN; if(34<=32) { MAN_IN = ((unsigned long long)Log_normal_H) << 0; MAN_IN=((unsigned long long) (((MAN_IN)&((unsigned long long)(4294967296ULL -1))))); } else { MAN_IN = ((unsigned long long)Log_normal_H) << 30; } _result_5 = 34<=32 || ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(4294967296ULL -1))))) == 0; _result_4 = (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(65536ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(65536ULL -1)))))) == 0; _result_3 = (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))) == 0; _result_2 = (_result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(4))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(36))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(20))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(52))&((unsigned long long)(16ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(12))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(44))&((unsigned long long)(16ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(28))&((unsigned long long)(16ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(60))&((unsigned long long)(16ULL -1)))))))) == 0; _val8 = _result_3 ? (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(0))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(32))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(16))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(48))&((unsigned long long)(256ULL -1))))))) : (_result_4 ? (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(8))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(40))&((unsigned long long)(256ULL -1)))))) : (_result_5 ? ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(24))&((unsigned long long)(256ULL -1))))) : ((unsigned long long) (((((unsigned long long)(MAN_IN))>>(56))&((unsigned long long)(256ULL -1))))))); _val4 = _result_2 ? _val8&15 : (_val8>>4)&15; _result_1 = _val4 >> 2 == 0; _result_0 = _result_1 ? (~((_val4 & 2)>>1))&1 : (~((_val4&8)>>3))&1; if(34<=32) { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); E_normal_H = _result; } else { _result = _result | (((unsigned long long)(_result_0)) << 0); _result = _result | (((unsigned long long)(_result_1)) << 1); _result = _result | (((unsigned long long)(_result_2)) << 2); _result = _result | (((unsigned long long)(_result_3)) << 3); _result = _result | (((unsigned long long)(_result_4)) << 4); _result = _result | (((unsigned long long)(_result_5)) << 5); E_normal_H = _result; } E_normal_H=((unsigned long long) (((E_normal_H)&((unsigned long long)(64ULL -1)))));};
 E_normal = E_normal_H > 33 ? E_normal_L + 34 : E_normal_H;
 Log_normal_normd_H = E_normal < 34 ? (Log_normal_H << E_normal)| ((unsigned long long)Log_normal_L>>(60-E_normal)) : (Log_normal_L>>(60-E_normal));
 Log_normal_normd_H=((unsigned long long) (((Log_normal_normd_H)&((unsigned long long)(17179869184ULL -1)))));
 Log_normal_normd_L = E_normal < 34 ? Log_normal_L << (E_normal) : (Log_normal_L<<E_normal);
 Log_normal_normd_L=((unsigned long long) (((Log_normal_normd_L)&((unsigned long long)(1152921504606846976ULL -1)))));



 Z2o2_small_s = shiftval>58 ? 0 : Z2o2 >> ((unsigned char) shiftval);
 Z2o2_small_s=((unsigned long long) (((Z2o2_small_s)&((unsigned long long)(268435456ULL -1)))));


 Z2o2_small = ((unsigned long long)Z2o2_small_s) <<3;


 Z_small = ((unsigned long long)absZ0s) << 33;
    Log_small = sR==0 ? (Z_small - Z2o2_small) : (Z_small + Z2o2_small);
 Log_small=((unsigned long long) (((Log_small)&((unsigned long long)(576460752303423488ULL -1)))));



    if ((((Log_small)>>((wF+g+1)))&1)==1)
    {
      E0_sub = 0b11;
    }
    else if(((((Log_small)>>((wF+g+1)))&1)==0) & ((((Log_small)>>((wF+g)))&1)==1) )
    {
      E0_sub=0b10;
    }
    else
    {
      E0_sub=0b01;
    }

    E_small = ((0b11111111<<2)|E0_sub) - lzo;
 E_small=((unsigned long long) (((E_small)&((unsigned long long)(2048ULL -1)))));


    if((((Log_small)>>((wF+g+1)))&1)==1)
    {
  Log_small_normd = ((unsigned long long) (((((unsigned long long)(Log_small))>>(2))&((unsigned long long)(144115188075855872ULL -1)))));
    }
    else if((((Log_small)>>((wF+g)))&1)==1)
    {
  Log_small_normd = ((unsigned long long) (((((unsigned long long)(Log_small))>>(1))&((unsigned long long)(144115188075855872ULL -1)))));
    }
    else
    {
  Log_small_normd = ((unsigned long long) (((((unsigned long long)(Log_small))>>(0))&((unsigned long long)(144115188075855872ULL -1)))));
    }

    ER = small==1 ? E_small : (E0offset-E_normal);

 Log_g = small == 1 ? ((unsigned long long) (((((unsigned long long)(Log_small_normd))>>(0))&((unsigned long long)(72057594037927936ULL -1))))) << 1 : (((unsigned long long) (((((unsigned long long)(Log_normal_normd_H))>>(0))&((unsigned long long)(8589934592ULL -1))))) << 24) | (((unsigned long long) (((((unsigned long long)(Log_normal_normd_L))>>(36))&((unsigned long long)(16777216ULL -1))))));
 sticky = ((unsigned long long) (((((unsigned long long)(Log_g))>>(0))&((unsigned long long)(16ULL -1))))) == 0 ? 0b0 : 0b1;
    round = (((Log_g)>>((g-1)))&1)&((((Log_g)>>(g))&1)|sticky);
 ufl = 0;

 EFR = ((ER << 52) | ((unsigned long long) (((((unsigned long long)(Log_g))>>(5))&((unsigned long long)(4503599627370496ULL -1)))))) + round;


 double_uint_converter res_fp;
 res_fp.b = ((unsigned long long)sR<<63)|EFR;

 return res_fp.f;
}
