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
typedef struct { real_T B_6_0_0 ; real_T B_6_2_0 ; real_T B_6_5_0 ; real_T
B_6_7_0 ; real_T B_6_9_0 ; real_T B_6_11_0 ; real_T B_6_14_0 ; real_T
B_6_16_0 ; real_T B_6_18_0 ; real_T B_6_20_0 ; real_T B_6_23_0 ; real_T
B_6_25_0 ; real_T B_6_27_0 ; real_T B_6_29_0 ; real_T B_6_32_0 ; real_T
B_6_34_0 ; real_T B_6_36_0 ; real_T B_6_38_0 ; real_T B_6_41_0 ; real_T
B_6_43_0 ; real_T B_6_45_0 ; real_T B_6_47_0 ; real_T B_6_50_0 ; real_T
B_6_52_0 ; real_T B_6_54_0 ; real_T B_6_56_0 ; real_T B_6_58_0 ; real_T
B_6_60_0 ; real_T B_6_62_0 ; real_T B_6_64_0 ; real_T B_6_66_0 ; real_T
B_6_68_0 ; real_T B_6_70_0 ; real_T B_6_73_0 ; real_T B_6_81_0 ; real_T
B_6_86_0 ; real_T B_6_87_0 ; real_T B_6_88_0 ; real_T B_6_89_0 ; real_T
B_6_90_0 ; real_T B_6_91_0 ; real_T B_6_92_0 ; real_T B_6_93_0 ; real_T
B_6_94_0 ; real_T B_6_95_0 ; real_T B_6_96_0 ; real_T B_6_97_0 ; real_T
B_6_98_0 ; real_T B_6_99_0 ; real_T B_6_100_0 ; real_T B_6_101_0 ; real_T
B_6_102_0 ; real_T B_6_103_0 ; real_T B_6_104_0 ; real_T B_6_106_0 ; real_T
B_6_107_0 ; real_T B_6_108_0 ; real_T B_6_109_0 ; real_T B_6_110_0 ; real_T
B_6_111_0 ; real_T B_6_112_0 ; real_T B_6_113_0 ; real_T B_6_114_0 ; real_T
B_6_115_0 ; real_T B_6_116_0 ; real_T B_6_117_0 ; real_T B_6_118_0 ; real_T
B_6_119_0 ; real_T B_6_120_0 ; real_T B_6_121_0 ; real_T B_6_122_0 ; real_T
B_6_123_0 ; real_T B_6_124_0 ; real_T B_6_126_0 ; real_T B_6_127_0 ; real_T
B_6_128_0 ; real_T B_6_129_0 ; real_T B_6_130_0 ; real_T B_6_131_0 ; real_T
B_6_132_0 ; real_T B_6_133_0 ; real_T B_6_134_0 ; real_T B_6_135_0 ; real_T
B_6_136_0 ; real_T B_6_137_0 ; real_T B_6_138_0 ; real_T B_6_139_0 ; real_T
B_6_140_0 ; real_T B_6_141_0 ; real_T B_6_142_0 ; real_T B_6_143_0 ; real_T
B_6_144_0 ; real_T B_6_145_0 ; real_T B_6_146_0 ; real_T B_6_147_0 ; real_T
B_6_150_0 ; real_T B_6_151_0 ; real_T B_6_152_0 ; } B_fuelCycle_T ; typedef
struct { real_T Memory_PreviousInput ; real_T Memory_PreviousInput_o ; real_T
Memory_PreviousInput_b ; real_T Memory_PreviousInput_c ; real_T
Memory_PreviousInput_i ; real_T Memory_PreviousInput_e ; real_T nextTime ;
real_T nextTime_l ; real_T nextTime_i ; real_T nextTime_o ; real_T nextTime_f
; int64_T numCompleteCycles ; int64_T numCompleteCycles_l ; int64_T
numCompleteCycles_e ; int64_T numCompleteCycles_lt ; int64_T
numCompleteCycles_p ; struct { real_T modelTStart ; } TransportDelay_RWORK ;
struct { real_T modelTStart ; } TransportDelay_RWORK_f ; struct { real_T
modelTStart ; } TransportDelay_RWORK_k ; struct { real_T modelTStart ; }
TransportDelay_RWORK_n ; struct { real_T modelTStart ; }
TransportDelay_RWORK_i ; struct { real_T modelTStart ; }
TransportDelay_RWORK_f1 ; void * Scope_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK ; void * Scope1_PWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_g ; void * Scope2_PWORK ; struct
{ void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_c ; void * Scope3_PWORK
; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_l ; void *
Scope4_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK_b
; void * Scope6_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_p ; void * Scope7_PWORK ; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK ; struct { void * AQHandles
; } TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK ; struct { void
* AQHandles ; } TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace1_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace2_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace3_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace4_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace5_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace6_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace7_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace8_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace9_PWORK ; struct { void *
AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK_f ; struct { void *
AQHandles ; } TAQSigLogging_InsertedFor_Model_at_outport_0_PWORK ; struct {
void * AQHandles ; } TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK ;
struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK ; int32_T
justEnabled ; int32_T currentValue ; int32_T justEnabled_e ; int32_T
currentValue_o ; int32_T justEnabled_d ; int32_T currentValue_f ; int32_T
justEnabled_i ; int32_T currentValue_b ; int32_T justEnabled_f ; int32_T
currentValue_k ; int32_T TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; int32_T
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
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_c ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_cs ; } DW_fuelCycle_T ; typedef struct
{ real_T Integrator_CSTATE ; real_T integrator_CSTATE ; real_T
integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j
; real_T integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T
Integrator_CSTATE_m ; real_T Integrator_CSTATE_f ; real_T
Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; } X_fuelCycle_T ; typedef
struct { real_T Integrator_CSTATE ; real_T integrator_CSTATE ; real_T
integrator_CSTATE_p ; real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j
; real_T integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T
Integrator_CSTATE_m ; real_T Integrator_CSTATE_f ; real_T
Integrator_CSTATE_mr ; real_T Integrator_CSTATE_g ; real_T
Integrator_CSTATE_p ; real_T Integrator_CSTATE_gw ; real_T
Integrator_CSTATE_c ; real_T Integrator_CSTATE_e ; real_T
Integrator_CSTATE_gf ; real_T Integrator_CSTATE_l ; } XDot_fuelCycle_T ;
typedef struct { boolean_T Integrator_CSTATE ; boolean_T integrator_CSTATE ;
boolean_T integrator_CSTATE_p ; boolean_T integrator_CSTATE_f ; boolean_T
integrator_CSTATE_j ; boolean_T integrator_CSTATE_l ; boolean_T
integrator_CSTATE_h ; boolean_T Integrator_CSTATE_m ; boolean_T
Integrator_CSTATE_f ; boolean_T Integrator_CSTATE_mr ; boolean_T
Integrator_CSTATE_g ; boolean_T Integrator_CSTATE_p ; boolean_T
Integrator_CSTATE_gw ; boolean_T Integrator_CSTATE_c ; boolean_T
Integrator_CSTATE_e ; boolean_T Integrator_CSTATE_gf ; boolean_T
Integrator_CSTATE_l ; } XDis_fuelCycle_T ; typedef struct { real_T
Integrator_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_p ;
real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T Integrator_CSTATE_m
; real_T Integrator_CSTATE_f ; real_T Integrator_CSTATE_mr ; real_T
Integrator_CSTATE_g ; real_T Integrator_CSTATE_p ; real_T
Integrator_CSTATE_gw ; real_T Integrator_CSTATE_c ; real_T
Integrator_CSTATE_e ; real_T Integrator_CSTATE_gf ; real_T
Integrator_CSTATE_l ; } CStateAbsTol_fuelCycle_T ; typedef struct { real_T
Integrator_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_p ;
real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T Integrator_CSTATE_m
; real_T Integrator_CSTATE_f ; real_T Integrator_CSTATE_mr ; real_T
Integrator_CSTATE_g ; real_T Integrator_CSTATE_p ; real_T
Integrator_CSTATE_gw ; real_T Integrator_CSTATE_c ; real_T
Integrator_CSTATE_e ; real_T Integrator_CSTATE_gf ; real_T
Integrator_CSTATE_l ; } CXPtMin_fuelCycle_T ; typedef struct { real_T
Integrator_CSTATE ; real_T integrator_CSTATE ; real_T integrator_CSTATE_p ;
real_T integrator_CSTATE_f ; real_T integrator_CSTATE_j ; real_T
integrator_CSTATE_l ; real_T integrator_CSTATE_h ; real_T Integrator_CSTATE_m
; real_T Integrator_CSTATE_f ; real_T Integrator_CSTATE_mr ; real_T
Integrator_CSTATE_g ; real_T Integrator_CSTATE_p ; real_T
Integrator_CSTATE_gw ; real_T Integrator_CSTATE_c ; real_T
Integrator_CSTATE_e ; real_T Integrator_CSTATE_gf ; real_T
Integrator_CSTATE_l ; } CXPtMax_fuelCycle_T ; struct P_fuelCycle_T_ { real_T
P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ; real_T P_4 ; real_T P_5 ; real_T
P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11 ;
real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ; real_T
P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T P_21 ; real_T P_22 ;
real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ; real_T P_27 ; real_T
P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T P_32 ; real_T P_33 ;
real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ; real_T P_38 ; real_T
P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; real_T P_43 ; real_T P_44 ;
real_T P_45 ; real_T P_46 ; real_T P_47 ; real_T P_48 ; real_T P_49 ; real_T
P_50 ; real_T P_51 ; real_T P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ;
real_T P_56 ; real_T P_57 ; real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T
P_61 ; real_T P_62 ; real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ;
real_T P_67 ; real_T P_68 ; real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T
P_72 ; real_T P_73 ; real_T P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ;
real_T P_78 ; real_T P_79 ; real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T
P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ;
real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ; real_T P_93 ; real_T
P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ;
real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ;
real_T P_105 ; real_T P_106 ; real_T P_107 ; } ; extern P_fuelCycle_T
fuelCycle_rtDefaultP ;
#endif
