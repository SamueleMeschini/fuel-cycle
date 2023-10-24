#ifndef RTW_HEADER_fuelCycle_acc_h_
#define RTW_HEADER_fuelCycle_acc_h_
#ifndef fuelCycle_acc_COMMON_INCLUDES_
#define fuelCycle_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "fuelCycle_acc_types.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_7_0_0 ; real_T B_7_1_8 ; real_T B_7_2_16 ; real_T
B_7_3_24 ; real_T B_7_4_32 ; real_T B_7_5_40 ; real_T B_7_6_48 ; real_T
B_7_7_56 ; real_T B_7_8_64 ; real_T B_7_9_72 ; real_T B_7_10_80 ; real_T
B_7_11_88 ; real_T B_7_12_96 ; real_T B_7_13_104 ; real_T B_7_14_112 ; real_T
B_7_15_120 ; real_T B_7_16_128 ; real_T B_7_17_136 ; real_T B_7_18_144 ;
real_T B_7_19_152 ; real_T B_7_20_160 ; real_T B_7_21_168 ; real_T B_7_22_176
; real_T B_7_23_184 ; real_T B_7_24_192 ; real_T B_7_25_200 ; real_T
B_7_26_208 ; real_T B_7_27_216 ; real_T B_7_28_224 ; real_T B_7_29_232 ;
real_T B_7_30_240 ; real_T B_7_31_248 ; real_T B_7_32_256 ; real_T B_7_33_264
; real_T B_7_34_272 ; real_T B_7_35_280 ; real_T B_7_36_288 ; real_T
B_7_37_296 ; real_T B_7_38_304 ; real_T B_7_39_312 ; real_T B_7_40_320 ;
real_T B_7_41_328 ; real_T B_7_42_336 ; real_T B_7_43_344 ; real_T B_7_44_352
; real_T B_7_45_360 ; real_T B_7_46_368 ; real_T B_7_47_376 ; real_T
B_7_48_384 ; real_T B_7_49_392 ; real_T B_7_50_400 ; real_T B_7_51_408 ;
real_T B_7_52_416 ; real_T B_7_53_424 ; real_T B_7_54_432 ; real_T B_7_55_440
; real_T B_7_56_448 ; real_T B_7_57_456 ; real_T B_7_58_464 ; real_T
B_7_59_472 ; real_T B_7_60_480 ; real_T B_7_61_488 ; real_T B_7_62_496 ;
real_T B_7_63_504 ; real_T B_7_64_512 ; real_T B_7_65_520 ; real_T B_7_66_528
; real_T B_7_67_536 ; real_T B_7_68_544 ; real_T B_7_69_552 ; real_T
B_7_70_560 ; real_T B_7_71_568 ; real_T B_7_72_576 ; real_T B_7_73_584 ;
real_T B_7_74_592 ; real_T B_7_75_600 ; real_T B_7_76_608 ; real_T B_7_77_616
; real_T B_7_78_624 ; real_T B_7_79_632 ; real_T B_7_80_640 ; real_T
B_7_81_648 ; real_T B_7_82_656 ; real_T B_7_83_664 ; real_T B_7_84_672 ;
real_T B_7_85_680 ; real_T B_7_86_688 ; real_T B_7_87_696 ; real_T B_7_88_704
; real_T B_7_89_712 ; real_T B_7_90_720 ; real_T B_7_91_728 ; real_T
B_7_92_736 ; real_T B_7_93_744 ; real_T B_7_94_752 ; real_T B_7_95_760 ;
real_T B_7_96_768 ; real_T B_7_97_776 ; real_T B_7_98_784 ; real_T B_7_99_792
; real_T B_7_100_800 ; real_T B_7_101_808 ; real_T B_7_102_816 ; real_T
B_7_103_824 ; real_T B_7_104_832 ; real_T B_7_105_840 ; real_T B_7_106_848 ;
real_T B_7_107_856 ; } B_fuelCycle_T ; typedef struct { real_T
Memory_PreviousInput ; real_T Memory_PreviousInput_o ; real_T
Memory_PreviousInput_b ; real_T Memory_PreviousInput_c ; real_T
Memory_PreviousInput_i ; real_T Memory_PreviousInput_iz ; real_T
Memory_PreviousInput_e ; real_T nextTime ; real_T nextTime_l ; real_T
nextTime_i ; real_T nextTime_if ; real_T nextTime_o ; real_T nextTime_f ;
int64_T numCompleteCycles ; int64_T numCompleteCycles_l ; int64_T
numCompleteCycles_e ; int64_T numCompleteCycles_f ; int64_T
numCompleteCycles_lt ; int64_T numCompleteCycles_p ; struct { real_T
modelTStart ; } TransportDelay_RWORK ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f ; struct { real_T modelTStart ; }
TransportDelay_RWORK_k ; struct { real_T modelTStart ; }
TransportDelay_RWORK_n ; struct { real_T modelTStart ; }
TransportDelay_RWORK_h ; struct { real_T modelTStart ; }
TransportDelay_RWORK_i ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f1 ; void * Scope_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK ; void * Scope1_PWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_g ; void * Scope2_PWORK ; struct
{ void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_c ; void * Scope3_PWORK
; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_l ; void *
Scope4_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_cv
; void * Scope5_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_b ; void * Scope6_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK_p ; void * Scope7_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK ; struct
{ void * AQHandles ; } TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK ; struct {
void * AQHandles ; }
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace1_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace10_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace2_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace3_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace4_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace5_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace6_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace7_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace8_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace9_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK_f ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK_c ; int32_T
justEnabled ; int32_T currentValue ; int32_T justEnabled_e ; int32_T
currentValue_o ; int32_T justEnabled_d ; int32_T currentValue_f ; int32_T
justEnabled_m ; int32_T currentValue_d ; int32_T justEnabled_i ; int32_T
currentValue_b ; int32_T justEnabled_f ; int32_T currentValue_k ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_l ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_n ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_d ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_m ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_e ; int32_T
TmpAtomicSubsysAtSwitchInport1_sysIdxToRun_g ; struct { int_T Tail ; int_T
Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_h ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_p ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_j ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_n ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_c ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay_IWORK_cs ; } DW_fuelCycle_T ; typedef struct { real_T
Integrator_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_p ;
real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_l ; real_T integrator_CSTATE_h
; real_T Integrator_CSTATE_m ; real_T Integrator_CSTATE_f ; real_T
Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; } X_fuelCycle_T ; typedef
struct { real_T Integrator_CSTATE ; real_T integrator_CSTATE ; real_T
integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j
; real_T integrator_CSTATE_o ; real_T integrator_CSTATE_l ; real_T
integrator_CSTATE_h ; real_T Integrator_CSTATE_m ; real_T Integrator_CSTATE_f
; real_T Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; } XDot_fuelCycle_T ;
typedef struct { boolean_T Integrator_CSTATE ; boolean_T integrator_CSTATE ;
boolean_T integrator_CSTATE_p ; boolean_T integrator_CSTATE_f ; boolean_T
integrator_CSTATE_j ; boolean_T integrator_CSTATE_o ; boolean_T
integrator_CSTATE_l ; boolean_T integrator_CSTATE_h ; boolean_T
Integrator_CSTATE_m ; boolean_T Integrator_CSTATE_f ; boolean_T
Integrator_CSTATE_mr ; boolean_T Integrator_CSTATE_g ; boolean_T
Integrator_CSTATE_p ; boolean_T Integrator_CSTATE_gw ; boolean_T
Integrator_CSTATE_c ; boolean_T Integrator_CSTATE_e ; boolean_T
Integrator_CSTATE_gf ; boolean_T Integrator_CSTATE_l ; } XDis_fuelCycle_T ;
typedef struct { real_T Integrator_CSTATE ; real_T integrator_CSTATE ; real_T
integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j
; real_T integrator_CSTATE_o ; real_T integrator_CSTATE_l ; real_T
integrator_CSTATE_h ; real_T Integrator_CSTATE_m ; real_T Integrator_CSTATE_f
; real_T Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; }
CStateAbsTol_fuelCycle_T ; typedef struct { real_T Integrator_CSTATE ; real_T
integrator_CSTATE ; real_T integrator_CSTATE_p ; real_T integrator_CSTATE_f ;
real_T integrator_CSTATE_j ; real_T integrator_CSTATE_o ; real_T
integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T Integrator_CSTATE_m
; real_T Integrator_CSTATE_f ; real_T Integrator_CSTATE_mr ; real_T
Integrator_CSTATE_g ; real_T Integrator_CSTATE_p ; real_T
Integrator_CSTATE_gw ; real_T Integrator_CSTATE_c ; real_T
Integrator_CSTATE_e ; real_T Integrator_CSTATE_gf ; real_T
Integrator_CSTATE_l ; } CXPtMin_fuelCycle_T ; typedef struct { real_T
Integrator_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_p ;
real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_o ; real_T integrator_CSTATE_l ; real_T integrator_CSTATE_h
; real_T Integrator_CSTATE_m ; real_T Integrator_CSTATE_f ; real_T
Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; } CXPtMax_fuelCycle_T ;
struct P_fuelCycle_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ;
real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T
P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ;
real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T
P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ;
real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T
P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ;
real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T
P_70 ; real_T P_71 ; real_T P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ;
real_T P_76 ; real_T P_77 ; real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T
P_81 ; real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ;
real_T P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T
P_92 ; real_T P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ;
real_T P_98 ; real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ;
real_T P_103 ; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ;
real_T P_108 ; real_T P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ;
real_T P_113 ; real_T P_114 ; real_T P_115 ; real_T P_116 ; real_T P_117 ;
real_T P_118 ; real_T P_119 ; real_T P_120 ; real_T P_121 ; } ; extern
P_fuelCycle_T fuelCycle_rtDefaultP ;
#endif
