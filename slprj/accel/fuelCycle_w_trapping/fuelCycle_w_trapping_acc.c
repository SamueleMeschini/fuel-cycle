#include "fuelCycle_w_trapping_acc.h"
#include "fuelCycle_w_trapping_acc_types.h"
#include "mwmathutil.h"
#include <float.h>
#include "rtwtypes.h"
#include "fuelCycle_w_trapping_acc_private.h"
#include "multiword_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T *
bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T
tMinusDelay , real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ;
real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) {
numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz -
1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && !
isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T * tempX = (
NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024 ; if (
newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU = (
real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if ( tempU
== ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * uBufPtr = tempU ; } else { * tailPtr =
testIdx ; } return ( true ) ; } real_T
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T
tStart , real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx ,
int_T newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } static void
mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_7_123_984 ; real_T
B_7_125_1000 ; real_T B_7_127_1016 ; real_T B_7_129_1032 ; real_T
B_7_131_1048 ; real_T B_7_133_1064 ; real_T B_7_135_1080 ;
B_fuelCycle_w_trapping_T * _rtB ; DW_fuelCycle_w_trapping_T * _rtDW ;
P_fuelCycle_w_trapping_T * _rtP ; X_fuelCycle_w_trapping_T * _rtX ; real_T
ratio ; real_T taskTimeV ; int32_T isHit ; uint32_T numCycles ; boolean_T
rtb_B_7_151_1208 ; _rtDW = ( ( DW_fuelCycle_w_trapping_T * ) ssGetRootDWork (
S ) ) ; _rtX = ( ( X_fuelCycle_w_trapping_T * ) ssGetContStates ( S ) ) ;
_rtP = ( ( P_fuelCycle_w_trapping_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_fuelCycle_w_trapping_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_7_0_0 =
_rtX -> Integrator_CSTATE ; ssCallAccelRunBlock ( S , 7 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_1_8 = _rtX -> integrator_CSTATE ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_9 ; B_7_123_984 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW ->
TransportDelay_IWORK . Head , _rtP -> P_10 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK . Head ] == ssGetT ( S ) )
) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_2_16 = _rtP -> P_11 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_2_16 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_3_24 = _rtDW -> Memory_PreviousInput ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_4_32 = ( _rtB -> B_7_1_8 - B_7_123_984 ) * _rtP -> P_0 ; } else {
_rtB -> B_7_4_32 = _rtB -> B_7_3_24 ; } ssCallAccelRunBlock ( S , 7 , 10 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_5_40 = _rtX -> integrator_CSTATE_p ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_g .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_14 ; B_7_125_1000 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_h . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_h . Last , _rtDW -> TransportDelay_IWORK_h . Tail ,
_rtDW -> TransportDelay_IWORK_h . Head , _rtP -> P_15 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_h .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_h . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_6_48 = _rtP -> P_16 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_6_48 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_7_56 = _rtDW -> Memory_PreviousInput_o ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_8_64 = ( _rtB -> B_7_5_40 - B_7_125_1000 ) * _rtP -> P_2 ; } else
{ _rtB -> B_7_8_64 = _rtB -> B_7_7_56 ; } ssCallAccelRunBlock ( S , 7 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_9_72 = _rtX -> integrator_CSTATE_f ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_c .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_19 ; B_7_127_1016 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_p . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_p . Last , _rtDW -> TransportDelay_IWORK_p . Tail ,
_rtDW -> TransportDelay_IWORK_p . Head , _rtP -> P_20 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_p .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_p . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_10_80 = _rtP -> P_21 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_10_80 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_11_88 = _rtDW -> Memory_PreviousInput_b ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_12_96 = ( _rtB -> B_7_9_72 - B_7_127_1016 ) * _rtP -> P_4 ; }
else { _rtB -> B_7_12_96 = _rtB -> B_7_11_88 ; } ssCallAccelRunBlock ( S , 7
, 28 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_13_104 = _rtX ->
integrator_CSTATE_j ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_l . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_24 ; B_7_129_1032 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_j . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_j . Last , _rtDW -> TransportDelay_IWORK_j . Tail ,
_rtDW -> TransportDelay_IWORK_j . Head , _rtP -> P_25 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_j .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_j . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_14_112 = _rtP -> P_26 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_14_112 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_15_120 = _rtDW -> Memory_PreviousInput_c ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_16_128 = ( _rtB -> B_7_13_104 - B_7_129_1032 ) * _rtP -> P_3 ; }
else { _rtB -> B_7_16_128 = _rtB -> B_7_15_120 ; } ssCallAccelRunBlock ( S ,
7 , 37 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_17_136 = _rtX ->
integrator_CSTATE_o ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_cv . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S )
; real_T tMinusDelay = simTime - _rtP -> P_29 ; B_7_131_1048 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_n . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_n . Last , _rtDW -> TransportDelay_IWORK_n . Tail ,
_rtDW -> TransportDelay_IWORK_n . Head , _rtP -> P_30 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_n .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_n . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_18_144 = _rtP -> P_31 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_18_144 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_19_152 = _rtDW -> Memory_PreviousInput_i ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_20_160 = ( _rtB -> B_7_17_136 - B_7_131_1048 ) * _rtP -> P_6 ; }
else { _rtB -> B_7_20_160 = _rtB -> B_7_19_152 ; } ssCallAccelRunBlock ( S ,
7 , 46 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_21_168 = _rtX ->
integrator_CSTATE_l ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_34 ; B_7_133_1064 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_c . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_c . Last , _rtDW -> TransportDelay_IWORK_c . Tail ,
_rtDW -> TransportDelay_IWORK_c . Head , _rtP -> P_35 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_c .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_c . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_22_176 = _rtP -> P_36 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_22_176 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_23_184 = _rtDW -> Memory_PreviousInput_iz ; } if ( rtb_B_7_151_1208 )
{ _rtB -> B_7_24_192 = ( _rtB -> B_7_21_168 - B_7_133_1064 ) * _rtP -> P_5 ;
} else { _rtB -> B_7_24_192 = _rtB -> B_7_23_184 ; } ssCallAccelRunBlock ( S
, 7 , 55 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_25_200 = _rtX ->
integrator_CSTATE_h ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_39 ; B_7_135_1080 =
fuelCycle_w_trapping_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer
, _rtDW -> TransportDelay_IWORK_cs . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cs . Last , _rtDW -> TransportDelay_IWORK_cs . Tail ,
_rtDW -> TransportDelay_IWORK_cs . Head , _rtP -> P_40 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_7_26_208 = _rtP -> P_41 ; } rtb_B_7_151_1208 = ( ssGetT ( S ) >= _rtB ->
B_7_26_208 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB
-> B_7_27_216 = _rtDW -> Memory_PreviousInput_e ; } if ( rtb_B_7_151_1208 ) {
_rtB -> B_7_28_224 = ( _rtB -> B_7_25_200 - B_7_135_1080 ) * _rtP -> P_1 ; }
else { _rtB -> B_7_28_224 = _rtB -> B_7_27_216 ; } ssCallAccelRunBlock ( S ,
7 , 64 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_7_29_232 = _rtX ->
Integrator_CSTATE_m ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ { if ( _rtDW -> TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_7_29_232 + 0 ) ; } } } _rtB -> B_7_30_240
= _rtX -> Integrator_CSTATE_f ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_7_30_240 + 0 ) ; } } } _rtB -> B_7_31_248 =
_rtX -> Integrator_CSTATE_mr ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_7_31_248 + 0 ) ; } } } _rtB -> B_7_32_256 =
_rtX -> Integrator_CSTATE_g ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_32_256 + 0 ) ; } } } _rtB
-> B_7_33_264 = _rtX -> Integrator_CSTATE_p ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_7_33_264 + 0 ) ; } } } _rtB -> B_7_34_272
= _rtX -> Integrator_CSTATE_gw ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_34_272 + 0 ) ; } } } _rtB
-> B_7_35_280 = _rtX -> Integrator_CSTATE_c ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_35_280 + 0 ) ; } } } _rtB
-> B_7_36_288 = _rtX -> Integrator_CSTATE_e ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_36_288 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_0_0 + 0 ) ; } } } _rtB ->
B_7_37_296 = _rtX -> Integrator_CSTATE_gf ; isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_37_296 + 0 ) ; } } } { if
( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_7_0_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace1_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_7_32_256 + 0 ) ;
} } { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace10_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace10_PWORK . AQHandles , ssGetTaskTime ( S
, 0 ) , ( char * ) & _rtB -> B_7_36_288 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace2_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace2_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_7_34_272 + 0 ) ;
} } { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace3_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace3_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_7_33_264 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace4_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace4_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_7_30_240 + 0 ) ;
} } { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace5_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace5_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_7_29_232 + 0 ) ; } } _rtB -> B_7_38_304 = _rtX
-> Integrator_CSTATE_l ; { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace6_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace6_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_7_38_304 + 0 ) ;
} } { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace7_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace7_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_7_37_296 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace8_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace8_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_7_31_248 + 0 ) ;
} } { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace9_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace9_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_7_35_280 + 0 ) ; } } isHit = ssIsSampleHit ( S ,
4 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 4 ) ; if (
ssGetTNextWasAdjusted ( S , 4 ) != 0 ) { _rtDW -> nextTime =
_ssGetVarNextHitTime ( S , 2 ) ; } if ( _rtDW -> justEnabled != 0 ) { _rtDW
-> justEnabled = 0 ; if ( taskTimeV >= _rtP -> P_56 ) { ratio = ( taskTimeV -
_rtP -> P_56 ) / _rtP -> P_54 ; numCycles = ( uint32_T ) muDoubleScalarFloor
( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio )
< DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW -> numCompleteCycles =
numCycles ; ratio = ( ( real_T ) numCycles * _rtP -> P_54 + _rtP -> P_56 ) +
_rtP -> P_55 * _rtP -> P_54 / 100.0 ; if ( taskTimeV < ratio ) { _rtDW ->
currentValue = 1 ; _rtDW -> nextTime = ratio ; } else { _rtDW -> currentValue
= 0 ; _rtDW -> nextTime = ( real_T ) ( numCycles + 1U ) * _rtP -> P_54 + _rtP
-> P_56 ; } } else { _rtDW -> numCompleteCycles = _rtP -> P_56 != 0.0 ? - 1 :
0 ; _rtDW -> currentValue = 0 ; _rtDW -> nextTime = _rtP -> P_56 ; } } else
if ( _rtDW -> nextTime <= taskTimeV ) { if ( _rtDW -> currentValue == 1 ) {
_rtDW -> currentValue = 0 ; _rtDW -> nextTime = ( real_T ) ( _rtDW ->
numCompleteCycles + 1LL ) * _rtP -> P_54 + _rtP -> P_56 ; } else { _rtDW ->
numCompleteCycles ++ ; _rtDW -> currentValue = 1 ; _rtDW -> nextTime = ( _rtP
-> P_55 * _rtP -> P_54 * 0.01 + ( real_T ) _rtDW -> numCompleteCycles * _rtP
-> P_54 ) + _rtP -> P_56 ; } } _ssSetVarNextHitTime ( S , 2 , _rtDW ->
nextTime ) ; if ( _rtDW -> currentValue == 1 ) { _rtB -> B_7_39_312 = _rtP ->
P_53 ; } else { _rtB -> B_7_39_312 = 0.0 ; } } _rtB -> B_7_40_320 = _rtP ->
P_57 * _rtB -> B_7_31_248 ; _rtB -> B_7_41_328 = _rtP -> P_58 * _rtB ->
B_7_29_232 ; _rtB -> B_7_42_336 = ( _rtB -> B_7_39_312 + _rtB -> B_7_40_320 )
- _rtB -> B_7_41_328 ; _rtB -> B_7_43_344 = _rtP -> P_59 * _rtB -> B_7_30_240
; _rtB -> B_7_44_352 = _rtX -> Integrator1_CSTATE ; _rtB -> B_7_45_360 = _rtP
-> P_61 * _rtB -> B_7_44_352 ; _rtB -> B_7_46_368 = _rtB -> B_7_121_968 -
_rtB -> B_7_45_360 ; _rtB -> B_7_47_376 = _rtB -> B_7_43_344 * _rtB ->
B_7_46_368 ; _rtB -> B_7_48_384 = _rtP -> P_62 * _rtB -> B_7_44_352 ; _rtB ->
B_7_49_392 = _rtB -> B_7_47_376 - _rtB -> B_7_48_384 ; { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_n . AQHandles && ssGetLogOutput (
S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_n . AQHandles , ssGetTaskTime ( S
, 0 ) , ( char * ) & _rtB -> B_7_49_392 + 0 ) ; } } isHit = ssIsSampleHit ( S
, 3 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 3 ) ; if (
ssGetTNextWasAdjusted ( S , 3 ) != 0 ) { _rtDW -> nextTime_l =
_ssGetVarNextHitTime ( S , 1 ) ; } if ( _rtDW -> justEnabled_e != 0 ) { _rtDW
-> justEnabled_e = 0 ; if ( taskTimeV >= _rtP -> P_66 ) { ratio = ( taskTimeV
- _rtP -> P_66 ) / _rtP -> P_64 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_l = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_64 + _rtP -> P_66 ) + _rtP -> P_65 * _rtP -> P_64 / 100.0 ; if ( taskTimeV
< ratio ) { _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_l = ratio ; }
else { _rtDW -> currentValue_o = 0 ; _rtDW -> nextTime_l = ( real_T ) (
numCycles + 1U ) * _rtP -> P_64 + _rtP -> P_66 ; } } else { _rtDW ->
numCompleteCycles_l = _rtP -> P_66 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue_o
= 0 ; _rtDW -> nextTime_l = _rtP -> P_66 ; } } else if ( _rtDW -> nextTime_l
<= taskTimeV ) { if ( _rtDW -> currentValue_o == 1 ) { _rtDW ->
currentValue_o = 0 ; _rtDW -> nextTime_l = ( real_T ) ( _rtDW ->
numCompleteCycles_l + 1LL ) * _rtP -> P_64 + _rtP -> P_66 ; } else { _rtDW ->
numCompleteCycles_l ++ ; _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_l =
( _rtP -> P_65 * _rtP -> P_64 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_l * _rtP -> P_64 ) + _rtP -> P_66 ; } }
_ssSetVarNextHitTime ( S , 1 , _rtDW -> nextTime_l ) ; if ( _rtDW ->
currentValue_o == 1 ) { _rtB -> B_7_50_400 = _rtP -> P_63 ; } else { _rtB ->
B_7_50_400 = 0.0 ; } } _rtB -> B_7_51_408 = _rtP -> P_67 * _rtB -> B_7_31_248
; _rtB -> B_7_52_416 = _rtP -> P_68 * _rtB -> B_7_30_240 ; _rtB -> B_7_53_424
= ( ( _rtB -> B_7_50_400 + _rtB -> B_7_51_408 ) - _rtB -> B_7_52_416 ) - _rtB
-> B_7_49_392 ; _rtB -> B_7_54_432 = _rtP -> P_69 * _rtB -> B_7_44_352 ; _rtB
-> B_7_55_440 = _rtB -> B_7_122_976 - _rtB -> B_7_54_432 ; _rtB -> B_7_56_448
= _rtP -> P_70 * _rtB -> B_7_30_240 ; _rtB -> B_7_57_456 = _rtB -> B_7_56_448
* _rtB -> B_7_55_440 ; _rtB -> B_7_58_464 = _rtP -> P_71 * _rtB -> B_7_44_352
; _rtB -> B_7_59_472 = _rtB -> B_7_57_456 - _rtB -> B_7_58_464 ; _rtB ->
B_7_60_480 = _rtP -> P_72 * _rtB -> B_7_33_264 ; _rtB -> B_7_61_488 = _rtP ->
P_73 * _rtB -> B_7_31_248 ; _rtB -> B_7_62_496 = _rtB -> B_7_60_480 - _rtB ->
B_7_61_488 ; _rtB -> B_7_63_504 = _rtP -> P_74 * _rtB -> B_7_35_280 ; _rtB ->
B_7_64_512 = _rtP -> P_75 * _rtB -> B_7_38_304 ; _rtB -> B_7_65_520 = _rtP ->
P_76 * _rtB -> B_7_32_256 ; _rtB -> B_7_66_528 = ( _rtB -> B_7_63_504 + _rtB
-> B_7_64_512 ) - _rtB -> B_7_65_520 ; _rtB -> B_7_67_536 = _rtP -> P_77 *
_rtB -> B_7_34_272 ; _rtB -> B_7_68_544 = _rtP -> P_78 * _rtB -> B_7_33_264 ;
_rtB -> B_7_69_552 = _rtB -> B_7_67_536 - _rtB -> B_7_68_544 ; isHit =
ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime (
S , 2 ) ; if ( ssGetTNextWasAdjusted ( S , 2 ) != 0 ) { _rtDW -> nextTime_i =
_ssGetVarNextHitTime ( S , 0 ) ; } if ( _rtDW -> justEnabled_d != 0 ) { _rtDW
-> justEnabled_d = 0 ; if ( taskTimeV >= _rtP -> P_82 ) { ratio = ( taskTimeV
- _rtP -> P_82 ) / _rtP -> P_80 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_e = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_80 + _rtP -> P_82 ) + _rtP -> P_81 * _rtP -> P_80 / 100.0 ; if ( taskTimeV
< ratio ) { _rtDW -> currentValue_f = 1 ; _rtDW -> nextTime_i = ratio ; }
else { _rtDW -> currentValue_f = 0 ; _rtDW -> nextTime_i = ( real_T ) (
numCycles + 1U ) * _rtP -> P_80 + _rtP -> P_82 ; } } else { _rtDW ->
numCompleteCycles_e = _rtP -> P_82 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue_f
= 0 ; _rtDW -> nextTime_i = _rtP -> P_82 ; } } else if ( _rtDW -> nextTime_i
<= taskTimeV ) { if ( _rtDW -> currentValue_f == 1 ) { _rtDW ->
currentValue_f = 0 ; _rtDW -> nextTime_i = ( real_T ) ( _rtDW ->
numCompleteCycles_e + 1LL ) * _rtP -> P_80 + _rtP -> P_82 ; } else { _rtDW ->
numCompleteCycles_e ++ ; _rtDW -> currentValue_f = 1 ; _rtDW -> nextTime_i =
( _rtP -> P_81 * _rtP -> P_80 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_e * _rtP -> P_80 ) + _rtP -> P_82 ; } }
_ssSetVarNextHitTime ( S , 0 , _rtDW -> nextTime_i ) ; if ( _rtDW ->
currentValue_f == 1 ) { _rtB -> B_7_70_560 = _rtP -> P_79 ; } else { _rtB ->
B_7_70_560 = 0.0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK_f . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_f . AQHandles , ssGetTaskTime ( S
, 1 ) , ( char * ) & _rtB -> B_7_70_560 + 0 ) ; } } } _rtB -> B_7_71_568 =
_rtP -> P_83 * _rtB -> B_7_34_272 ; _rtB -> B_7_72_576 = _rtP -> P_84 * _rtB
-> B_7_31_248 ; _rtB -> B_7_73_584 = _rtP -> P_85 * _rtB -> B_7_30_240 ; _rtB
-> B_7_74_592 = _rtP -> P_86 * _rtB -> B_7_29_232 ; _rtB -> B_7_75_600 = ( (
( _rtB -> B_7_72_576 - _rtB -> B_7_71_568 ) + _rtB -> B_7_70_560 ) + _rtB ->
B_7_73_584 ) + _rtB -> B_7_74_592 ; _rtB -> B_7_76_608 = _rtP -> P_87 * _rtB
-> B_7_34_272 ; _rtB -> B_7_77_616 = _rtP -> P_88 * _rtB -> B_7_33_264 ; _rtB
-> B_7_78_624 = _rtB -> B_7_76_608 - _rtB -> B_7_77_616 ; _rtB -> B_7_79_632
= _rtP -> P_89 * _rtB -> B_7_31_248 ; _rtB -> B_7_80_640 = _rtP -> P_90 *
_rtB -> B_7_29_232 ; _rtB -> B_7_81_648 = _rtB -> B_7_79_632 - _rtB ->
B_7_80_640 ; _rtB -> B_7_82_656 = _rtP -> P_91 * _rtB -> B_7_31_248 ; _rtB ->
B_7_83_664 = _rtP -> P_92 * _rtB -> B_7_32_256 ; _rtB -> B_7_84_672 = _rtP ->
P_93 * _rtB -> B_7_38_304 ; _rtB -> B_7_85_680 = ( _rtB -> B_7_82_656 + _rtB
-> B_7_83_664 ) - _rtB -> B_7_84_672 ; _rtB -> B_7_86_688 = _rtP -> P_94 *
_rtB -> B_7_35_280 ; _rtB -> B_7_87_696 = _rtP -> P_95 * _rtB -> B_7_38_304 ;
_rtB -> B_7_88_704 = _rtP -> P_96 * _rtB -> B_7_32_256 ; _rtB -> B_7_89_712 =
( _rtB -> B_7_86_688 + _rtB -> B_7_87_696 ) - _rtB -> B_7_88_704 ; _rtB ->
B_7_90_720 = _rtP -> P_97 * _rtB -> B_7_37_296 ; _rtB -> B_7_91_728 = _rtP ->
P_98 * _rtB -> B_7_35_280 ; _rtB -> B_7_92_736 = _rtB -> B_7_90_720 - _rtB ->
B_7_91_728 ; _rtB -> B_7_93_744 = _rtP -> P_99 * _rtB -> B_7_33_264 ; _rtB ->
B_7_94_752 = _rtP -> P_100 * _rtB -> B_7_31_248 ; _rtB -> B_7_95_760 = _rtB
-> B_7_93_744 - _rtB -> B_7_94_752 ; isHit = ssIsSampleHit ( S , 7 , 0 ) ; if
( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 7 ) ; if (
ssGetTNextWasAdjusted ( S , 7 ) != 0 ) { _rtDW -> nextTime_if =
_ssGetVarNextHitTime ( S , 5 ) ; } if ( _rtDW -> justEnabled_m != 0 ) { _rtDW
-> justEnabled_m = 0 ; if ( taskTimeV >= _rtP -> P_104 ) { ratio = (
taskTimeV - _rtP -> P_104 ) / _rtP -> P_102 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_f = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_102 + _rtP -> P_104 ) + _rtP -> P_103 * _rtP -> P_102 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue_d = 1 ; _rtDW -> nextTime_if =
ratio ; } else { _rtDW -> currentValue_d = 0 ; _rtDW -> nextTime_if = (
real_T ) ( numCycles + 1U ) * _rtP -> P_102 + _rtP -> P_104 ; } } else {
_rtDW -> numCompleteCycles_f = _rtP -> P_104 != 0.0 ? - 1 : 0 ; _rtDW ->
currentValue_d = 0 ; _rtDW -> nextTime_if = _rtP -> P_104 ; } } else if (
_rtDW -> nextTime_if <= taskTimeV ) { if ( _rtDW -> currentValue_d == 1 ) {
_rtDW -> currentValue_d = 0 ; _rtDW -> nextTime_if = ( real_T ) ( _rtDW ->
numCompleteCycles_f + 1LL ) * _rtP -> P_102 + _rtP -> P_104 ; } else { _rtDW
-> numCompleteCycles_f ++ ; _rtDW -> currentValue_d = 1 ; _rtDW ->
nextTime_if = ( _rtP -> P_103 * _rtP -> P_102 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_f * _rtP -> P_102 ) + _rtP -> P_104 ; } }
_ssSetVarNextHitTime ( S , 5 , _rtDW -> nextTime_if ) ; if ( _rtDW ->
currentValue_d == 1 ) { _rtB -> B_7_96_768 = _rtP -> P_101 ; } else { _rtB ->
B_7_96_768 = 0.0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_96_768 + 0 ) ; } } } _rtB
-> B_7_97_776 = _rtP -> P_105 * _rtB -> B_7_37_296 ; _rtB -> B_7_98_784 =
_rtP -> P_106 * _rtB -> B_7_32_256 ; _rtB -> B_7_99_792 = _rtP -> P_107 *
_rtB -> B_7_36_288 ; _rtB -> B_7_100_800 = _rtP -> P_108 * _rtB -> B_7_0_0 ;
_rtB -> B_7_101_808 = ( ( ( _rtB -> B_7_97_776 + _rtB -> B_7_98_784 ) + _rtB
-> B_7_99_792 ) - _rtB -> B_7_96_768 ) - _rtB -> B_7_100_800 ; _rtB ->
B_7_102_816 = _rtP -> P_109 * _rtB -> B_7_31_248 ; _rtB -> B_7_103_824 = _rtP
-> P_110 * _rtB -> B_7_32_256 ; _rtB -> B_7_104_832 = _rtP -> P_111 * _rtB ->
B_7_38_304 ; _rtB -> B_7_105_840 = ( _rtB -> B_7_102_816 + _rtB ->
B_7_103_824 ) - _rtB -> B_7_104_832 ; _rtB -> B_7_106_848 = _rtP -> P_112 *
_rtB -> B_7_37_296 ; _rtB -> B_7_107_856 = _rtP -> P_113 * _rtB -> B_7_35_280
; _rtB -> B_7_108_864 = _rtB -> B_7_106_848 - _rtB -> B_7_107_856 ; _rtB ->
B_7_109_872 = _rtP -> P_114 * _rtB -> B_7_33_264 ; _rtB -> B_7_110_880 = _rtP
-> P_115 * _rtB -> B_7_36_288 ; _rtB -> B_7_111_888 = _rtB -> B_7_109_872 -
_rtB -> B_7_110_880 ; _rtB -> B_7_112_896 = _rtP -> P_116 * _rtB ->
B_7_37_296 ; _rtB -> B_7_113_904 = _rtP -> P_117 * _rtB -> B_7_32_256 ; _rtB
-> B_7_114_912 = _rtP -> P_118 * _rtB -> B_7_36_288 ; isHit = ssIsSampleHit (
S , 6 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 6 ) ; if (
ssGetTNextWasAdjusted ( S , 6 ) != 0 ) { _rtDW -> nextTime_o =
_ssGetVarNextHitTime ( S , 4 ) ; } if ( _rtDW -> justEnabled_i != 0 ) { _rtDW
-> justEnabled_i = 0 ; if ( taskTimeV >= _rtP -> P_122 ) { ratio = (
taskTimeV - _rtP -> P_122 ) / _rtP -> P_120 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_lt = numCycles ; ratio = ( ( real_T ) numCycles * _rtP
-> P_120 + _rtP -> P_122 ) + _rtP -> P_121 * _rtP -> P_120 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue_b = 1 ; _rtDW -> nextTime_o =
ratio ; } else { _rtDW -> currentValue_b = 0 ; _rtDW -> nextTime_o = ( real_T
) ( numCycles + 1U ) * _rtP -> P_120 + _rtP -> P_122 ; } } else { _rtDW ->
numCompleteCycles_lt = _rtP -> P_122 != 0.0 ? - 1 : 0 ; _rtDW ->
currentValue_b = 0 ; _rtDW -> nextTime_o = _rtP -> P_122 ; } } else if (
_rtDW -> nextTime_o <= taskTimeV ) { if ( _rtDW -> currentValue_b == 1 ) {
_rtDW -> currentValue_b = 0 ; _rtDW -> nextTime_o = ( real_T ) ( _rtDW ->
numCompleteCycles_lt + 1LL ) * _rtP -> P_120 + _rtP -> P_122 ; } else { _rtDW
-> numCompleteCycles_lt ++ ; _rtDW -> currentValue_b = 1 ; _rtDW ->
nextTime_o = ( _rtP -> P_121 * _rtP -> P_120 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_lt * _rtP -> P_120 ) + _rtP -> P_122 ; } }
_ssSetVarNextHitTime ( S , 4 , _rtDW -> nextTime_o ) ; if ( _rtDW ->
currentValue_b == 1 ) { _rtB -> B_7_115_920 = _rtP -> P_119 ; } else { _rtB
-> B_7_115_920 = 0.0 ; } } _rtB -> B_7_116_928 = _rtP -> P_123 * _rtB ->
B_7_0_0 ; _rtB -> B_7_117_936 = ( ( ( _rtB -> B_7_112_896 + _rtB ->
B_7_113_904 ) + _rtB -> B_7_114_912 ) - _rtB -> B_7_115_920 ) - _rtB ->
B_7_116_928 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if
( _rtDW -> TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_7_117_936 + 0 ) ; } } { if ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK_c . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK_c . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_7_115_920 + 0 ) ; } } }
isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { taskTimeV =
ssGetTaskTime ( S , 5 ) ; if ( ssGetTNextWasAdjusted ( S , 5 ) != 0 ) { _rtDW
-> nextTime_f = _ssGetVarNextHitTime ( S , 3 ) ; } if ( _rtDW ->
justEnabled_f != 0 ) { _rtDW -> justEnabled_f = 0 ; if ( taskTimeV >= _rtP ->
P_127 ) { ratio = ( taskTimeV - _rtP -> P_127 ) / _rtP -> P_125 ; numCycles =
( uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( (
real_T ) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++
; } _rtDW -> numCompleteCycles_p = numCycles ; ratio = ( ( real_T ) numCycles
* _rtP -> P_125 + _rtP -> P_127 ) + _rtP -> P_126 * _rtP -> P_125 / 100.0 ;
if ( taskTimeV < ratio ) { _rtDW -> currentValue_k = 1 ; _rtDW -> nextTime_f
= ratio ; } else { _rtDW -> currentValue_k = 0 ; _rtDW -> nextTime_f = (
real_T ) ( numCycles + 1U ) * _rtP -> P_125 + _rtP -> P_127 ; } } else {
_rtDW -> numCompleteCycles_p = _rtP -> P_127 != 0.0 ? - 1 : 0 ; _rtDW ->
currentValue_k = 0 ; _rtDW -> nextTime_f = _rtP -> P_127 ; } } else if (
_rtDW -> nextTime_f <= taskTimeV ) { if ( _rtDW -> currentValue_k == 1 ) {
_rtDW -> currentValue_k = 0 ; _rtDW -> nextTime_f = ( real_T ) ( _rtDW ->
numCompleteCycles_p + 1LL ) * _rtP -> P_125 + _rtP -> P_127 ; } else { _rtDW
-> numCompleteCycles_p ++ ; _rtDW -> currentValue_k = 1 ; _rtDW -> nextTime_f
= ( _rtP -> P_126 * _rtP -> P_125 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_p * _rtP -> P_125 ) + _rtP -> P_127 ; } }
_ssSetVarNextHitTime ( S , 3 , _rtDW -> nextTime_f ) ; if ( _rtDW ->
currentValue_k == 1 ) { _rtB -> B_7_118_944 = _rtP -> P_124 ; } else { _rtB
-> B_7_118_944 = 0.0 ; } } _rtB -> B_7_119_952 = _rtP -> P_128 * _rtB ->
B_7_37_296 ; _rtB -> B_7_120_960 = _rtB -> B_7_118_944 - _rtB -> B_7_119_952
; UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID8 ( SimStruct * S ,
int_T tid ) { B_fuelCycle_w_trapping_T * _rtB ; P_fuelCycle_w_trapping_T *
_rtP ; _rtP = ( ( P_fuelCycle_w_trapping_T * ) ssGetModelRtp ( S ) ) ; _rtB =
( ( B_fuelCycle_w_trapping_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB ->
B_7_121_968 = _rtP -> P_129 ; _rtB -> B_7_122_976 = _rtP -> P_130 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) {
B_fuelCycle_w_trapping_T * _rtB ; DW_fuelCycle_w_trapping_T * _rtDW ;
P_fuelCycle_w_trapping_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_fuelCycle_w_trapping_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_fuelCycle_w_trapping_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_fuelCycle_w_trapping_T * ) _ssGetModelBlockIO ( S ) ) ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head = ( (
_rtDW -> TransportDelay_IWORK . Head < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay_IWORK . Head == _rtDW -> TransportDelay_IWORK
. Tail ) { if ( ! fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Tail , & _rtDW -> TransportDelay_IWORK . Head , &
_rtDW -> TransportDelay_IWORK . Last , simTime - _rtP -> P_9 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_7_1_8 ; } isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput = _rtB ->
B_7_4_32 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_h . Head = ( ( _rtDW -> TransportDelay_IWORK_h
. Head < ( _rtDW -> TransportDelay_IWORK_h . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_h . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_h . Head == _rtDW -> TransportDelay_IWORK_h . Tail ) {
if ( ! fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_h . CircularBufSize , & _rtDW -> TransportDelay_IWORK_h
. Tail , & _rtDW -> TransportDelay_IWORK_h . Head , & _rtDW ->
TransportDelay_IWORK_h . Last , simTime - _rtP -> P_14 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_h . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_h . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = _rtB -> B_7_5_40 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_o = _rtB ->
B_7_8_64 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_c . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_p . Head = ( ( _rtDW -> TransportDelay_IWORK_p
. Head < ( _rtDW -> TransportDelay_IWORK_p . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_p . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_p . Head == _rtDW -> TransportDelay_IWORK_p . Tail ) {
if ( ! fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_p . CircularBufSize , & _rtDW -> TransportDelay_IWORK_p
. Tail , & _rtDW -> TransportDelay_IWORK_p . Head , & _rtDW ->
TransportDelay_IWORK_p . Last , simTime - _rtP -> P_19 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_p . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_p . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = _rtB -> B_7_9_72 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_b = _rtB ->
B_7_12_96 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_l . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_j . Head = ( ( _rtDW -> TransportDelay_IWORK_j
. Head < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_j . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_j . Head == _rtDW -> TransportDelay_IWORK_j . Tail ) {
if ( ! fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize , & _rtDW -> TransportDelay_IWORK_j
. Tail , & _rtDW -> TransportDelay_IWORK_j . Head , & _rtDW ->
TransportDelay_IWORK_j . Last , simTime - _rtP -> P_24 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_j . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_j . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = _rtB -> B_7_13_104 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_c = _rtB -> B_7_16_128 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_cv . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_n . Head = ( ( _rtDW
-> TransportDelay_IWORK_n . Head < ( _rtDW -> TransportDelay_IWORK_n .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_n . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_n . Head == _rtDW ->
TransportDelay_IWORK_n . Tail ) { if ( !
fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_n . CircularBufSize , & _rtDW -> TransportDelay_IWORK_n
. Tail , & _rtDW -> TransportDelay_IWORK_n . Head , & _rtDW ->
TransportDelay_IWORK_n . Last , simTime - _rtP -> P_29 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_n . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_n . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_n . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_n . Head ] = _rtB -> B_7_17_136 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_i = _rtB -> B_7_20_160 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_c . Head = ( ( _rtDW
-> TransportDelay_IWORK_c . Head < ( _rtDW -> TransportDelay_IWORK_c .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_c . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_c . Head == _rtDW ->
TransportDelay_IWORK_c . Tail ) { if ( !
fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_c . CircularBufSize , & _rtDW -> TransportDelay_IWORK_c
. Tail , & _rtDW -> TransportDelay_IWORK_c . Head , & _rtDW ->
TransportDelay_IWORK_c . Last , simTime - _rtP -> P_34 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_c . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_c . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = _rtB -> B_7_21_168 ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_iz = _rtB -> B_7_24_192 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_cs . Head = ( ( _rtDW
-> TransportDelay_IWORK_cs . Head < ( _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_cs . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_cs . Head == _rtDW ->
TransportDelay_IWORK_cs . Tail ) { if ( !
fuelCycle_w_trapping_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_cs . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cs . Tail , & _rtDW -> TransportDelay_IWORK_cs . Head ,
& _rtDW -> TransportDelay_IWORK_cs . Last , simTime - _rtP -> P_39 , uBuffer
, ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_cs .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] = _rtB -> B_7_25_200 ;
} isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_e = _rtB -> B_7_28_224 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID8 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_fuelCycle_w_trapping_T *
_rtB ; XDot_fuelCycle_w_trapping_T * _rtXdot ; _rtXdot = ( (
XDot_fuelCycle_w_trapping_T * ) ssGetdX ( S ) ) ; _rtB = ( (
B_fuelCycle_w_trapping_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
Integrator_CSTATE = _rtB -> B_7_117_936 ; _rtXdot -> integrator_CSTATE = _rtB
-> B_7_78_624 ; _rtXdot -> integrator_CSTATE_p = _rtB -> B_7_85_680 ; _rtXdot
-> integrator_CSTATE_f = _rtB -> B_7_92_736 ; _rtXdot -> integrator_CSTATE_j
= _rtB -> B_7_89_712 ; _rtXdot -> integrator_CSTATE_o = _rtB -> B_7_101_808 ;
_rtXdot -> integrator_CSTATE_l = _rtB -> B_7_95_760 ; _rtXdot ->
integrator_CSTATE_h = _rtB -> B_7_81_648 ; _rtXdot -> Integrator_CSTATE_m =
_rtB -> B_7_42_336 ; _rtXdot -> Integrator_CSTATE_f = _rtB -> B_7_53_424 ;
_rtXdot -> Integrator_CSTATE_mr = _rtB -> B_7_62_496 ; _rtXdot ->
Integrator_CSTATE_g = _rtB -> B_7_66_528 ; _rtXdot -> Integrator_CSTATE_p =
_rtB -> B_7_69_552 ; _rtXdot -> Integrator_CSTATE_gw = _rtB -> B_7_75_600 ;
_rtXdot -> Integrator_CSTATE_c = _rtB -> B_7_108_864 ; _rtXdot ->
Integrator_CSTATE_e = _rtB -> B_7_111_888 ; _rtXdot -> Integrator_CSTATE_gf =
_rtB -> B_7_120_960 ; _rtXdot -> Integrator_CSTATE_l = _rtB -> B_7_105_840 ;
_rtXdot -> Integrator1_CSTATE = _rtB -> B_7_59_472 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 2593444736U
) ; ssSetChecksumVal ( S , 1 , 257547990U ) ; ssSetChecksumVal ( S , 2 ,
3080307579U ) ; ssSetChecksumVal ( S , 3 , 3731632910U ) ; { mxArray *
slVerStructMat = ( NULL ) ; mxArray * slStrMat = mxCreateString ( "simulink"
) ; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat
, 1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == ( NULL ) ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "23.2" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != ( SLSize ) sizeof ( DW_fuelCycle_w_trapping_T ) ) { static char msg [
256 ] ; snprintf ( msg , 256 , "Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof ( DW_fuelCycle_w_trapping_T
) ) ; ssSetErrorStatus ( S , msg ) ; } if ( ssGetSizeofGlobalBlockIO ( S ) !=
( SLSize ) sizeof ( B_fuelCycle_w_trapping_T ) ) { static char msg [ 256 ] ;
snprintf ( msg , 256 , "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof (
B_fuelCycle_w_trapping_T ) ) ; ssSetErrorStatus ( S , msg ) ; } { int
ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( P_fuelCycle_w_trapping_T ) ) { static char msg [
256 ] ; snprintf ( msg , 256 ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_fuelCycle_w_trapping_T ) ) ; ssSetErrorStatus ( S
, msg ) ; } } _ssSetModelRtp ( S , ( real_T * ) &
fuelCycle_w_trapping_rtDefaultP ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID8 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
