#include "fuelCycle_acc.h"
#include "mwmathutil.h"
#include <float.h>
#include "rtwtypes.h"
#include "fuelCycle_acc_private.h"
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
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr ,
int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay ,
real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay ,
int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T
bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = (
NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf
= * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 )
: 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
fuelCycle_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart ,
real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T
newIdx , real_T initOutput , boolean_T discrete , boolean_T
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
mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_6_3_0 ; real_T B_6_12_0 ;
real_T B_6_21_0 ; real_T B_6_30_0 ; real_T B_6_39_0 ; real_T B_6_48_0 ;
B_fuelCycle_T * _rtB ; DW_fuelCycle_T * _rtDW ; P_fuelCycle_T * _rtP ;
X_fuelCycle_T * _rtX ; real_T ratio ; real_T taskTimeV ; int32_T isHit ;
uint32_T numCycles ; boolean_T rtb_B_6_6_0 ; _rtDW = ( ( DW_fuelCycle_T * )
ssGetRootDWork ( S ) ) ; _rtX = ( ( X_fuelCycle_T * ) ssGetContStates ( S ) )
; _rtP = ( ( P_fuelCycle_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_fuelCycle_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_6_0_0 = _rtX ->
Integrator_CSTATE ; ssCallAccelRunBlock ( S , 6 , 1 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_6_2_0 = _rtX -> integrator_CSTATE ; { real_T * * uBuffer = ( real_T
* * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_8 ; B_6_3_0 =
fuelCycle_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK . CircularBufSize , & _rtDW -> TransportDelay_IWORK .
Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW -> TransportDelay_IWORK .
Head , _rtP -> P_9 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] == ssGetT ( S ) ) ) ) ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_5_0 = _rtP -> P_10 ; }
rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_5_0 ) ; isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_7_0 = _rtDW ->
Memory_PreviousInput ; } if ( rtb_B_6_6_0 ) { _rtB -> B_6_9_0 = ( _rtB ->
B_6_2_0 - B_6_3_0 ) * _rtP -> P_0 ; } else { _rtB -> B_6_9_0 = _rtB ->
B_6_7_0 ; } ssCallAccelRunBlock ( S , 6 , 10 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_6_11_0 = _rtX -> integrator_CSTATE_p ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_13 ; B_6_12_0 =
fuelCycle_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK_h . CircularBufSize , & _rtDW -> TransportDelay_IWORK_h
. Last , _rtDW -> TransportDelay_IWORK_h . Tail , _rtDW ->
TransportDelay_IWORK_h . Head , _rtP -> P_14 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_h .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_h . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_14_0 = _rtP -> P_15 ; } rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_14_0
) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_16_0 = _rtDW -> Memory_PreviousInput_o ; } if ( rtb_B_6_6_0 ) { _rtB ->
B_6_18_0 = ( _rtB -> B_6_11_0 - B_6_12_0 ) * _rtP -> P_2 ; } else { _rtB ->
B_6_18_0 = _rtB -> B_6_16_0 ; } ssCallAccelRunBlock ( S , 6 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_6_20_0 = _rtX -> integrator_CSTATE_f ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_c .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_18 ; B_6_21_0 = fuelCycle_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_p .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_p . Last , _rtDW ->
TransportDelay_IWORK_p . Tail , _rtDW -> TransportDelay_IWORK_p . Head , _rtP
-> P_19 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer +
_rtDW -> TransportDelay_IWORK_p . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] == ssGetT ( S ) ) ) ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_23_0 = _rtP ->
P_20 ; } rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_23_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_25_0 = _rtDW ->
Memory_PreviousInput_b ; } if ( rtb_B_6_6_0 ) { _rtB -> B_6_27_0 = ( _rtB ->
B_6_20_0 - B_6_21_0 ) * _rtP -> P_4 ; } else { _rtB -> B_6_27_0 = _rtB ->
B_6_25_0 ; } ssCallAccelRunBlock ( S , 6 , 28 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_6_29_0 = _rtX -> integrator_CSTATE_j ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_l . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_23 ; B_6_30_0 =
fuelCycle_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK_j . CircularBufSize , & _rtDW -> TransportDelay_IWORK_j
. Last , _rtDW -> TransportDelay_IWORK_j . Tail , _rtDW ->
TransportDelay_IWORK_j . Head , _rtP -> P_24 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_j .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_j . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_32_0 = _rtP -> P_25 ; } rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_32_0
) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_34_0 = _rtDW -> Memory_PreviousInput_c ; } if ( rtb_B_6_6_0 ) { _rtB ->
B_6_36_0 = ( _rtB -> B_6_29_0 - B_6_30_0 ) * _rtP -> P_3 ; } else { _rtB ->
B_6_36_0 = _rtB -> B_6_34_0 ; } ssCallAccelRunBlock ( S , 6 , 37 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_6_38_0 = _rtX -> integrator_CSTATE_l ; {
real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK_b .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay =
simTime - _rtP -> P_28 ; B_6_39_0 = fuelCycle_acc_rt_TDelayInterpolate (
tMinusDelay , 0.0 , * uBuffer , _rtDW -> TransportDelay_IWORK_c .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_c . Last , _rtDW ->
TransportDelay_IWORK_c . Tail , _rtDW -> TransportDelay_IWORK_c . Head , _rtP
-> P_29 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( * uBuffer +
_rtDW -> TransportDelay_IWORK_c . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] == ssGetT ( S ) ) ) ) ; } isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_41_0 = _rtP ->
P_30 ; } rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_41_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_6_43_0 = _rtDW ->
Memory_PreviousInput_i ; } if ( rtb_B_6_6_0 ) { _rtB -> B_6_45_0 = ( _rtB ->
B_6_38_0 - B_6_39_0 ) * _rtP -> P_5 ; } else { _rtB -> B_6_45_0 = _rtB ->
B_6_43_0 ; } ssCallAccelRunBlock ( S , 6 , 46 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> B_6_47_0 = _rtX -> integrator_CSTATE_h ; { real_T * * uBuffer = ( real_T *
* ) & _rtDW -> TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_33 ; B_6_48_0 =
fuelCycle_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK_cs . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cs . Last , _rtDW -> TransportDelay_IWORK_cs . Tail ,
_rtDW -> TransportDelay_IWORK_cs . Head , _rtP -> P_34 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_50_0 = _rtP -> P_35 ; } rtb_B_6_6_0 = ( ssGetT ( S ) >= _rtB -> B_6_50_0
) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_6_52_0 = _rtDW -> Memory_PreviousInput_e ; } if ( rtb_B_6_6_0 ) { _rtB ->
B_6_54_0 = ( _rtB -> B_6_47_0 - B_6_48_0 ) * _rtP -> P_1 ; } else { _rtB ->
B_6_54_0 = _rtB -> B_6_52_0 ; } ssCallAccelRunBlock ( S , 6 , 55 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_6_56_0 = _rtX -> Integrator_CSTATE_m ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Div_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_6_56_0 + 0 ) ; } } } _rtB -> B_6_58_0 =
_rtX -> Integrator_CSTATE_f ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_FW_at_outport_0_PWORK . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_6_58_0 + 0 ) ; } } } _rtB -> B_6_60_0 = _rtX
-> Integrator_CSTATE_mr ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { { if ( _rtDW -> TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_HX_at_outport_0_PWORK . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_6_60_0 + 0 ) ; } } } _rtB -> B_6_62_0 = _rtX
-> Integrator_CSTATE_g ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { { if ( _rtDW -> TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK .
AQHandles && ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_ISS_9_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_62_0 + 0 ) ; } } } _rtB ->
B_6_64_0 = _rtX -> Integrator_CSTATE_p ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_TES_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_6_64_0 + 0 ) ; } } } _rtB -> B_6_66_0 =
_rtX -> Integrator_CSTATE_gw ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_breedingZone_1_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_66_0 + 0 ) ; } } } _rtB ->
B_6_68_0 = _rtX -> Integrator_CSTATE_c ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_fuelCleanup_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_68_0 + 0 ) ; } } } _rtB ->
B_6_70_0 = _rtX -> Integrator_CSTATE_e ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_membrane_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_70_0 + 0 ) ; } } { if (
_rtDW -> TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK . AQHandles
&& ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_storage_10_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_0_0 + 0 ) ; } } } _rtB ->
B_6_73_0 = _rtX -> Integrator_CSTATE_gf ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_vacuumPump_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_73_0 + 0 ) ; } } } { if (
_rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_6_0_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace1_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_6_62_0 + 0 ) ; }
} { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace2_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace2_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_6_66_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace3_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace3_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_6_64_0 + 0 ) ; }
} { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace4_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace4_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_6_58_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace5_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace5_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_6_56_0 + 0 ) ; }
} _rtB -> B_6_81_0 = _rtX -> Integrator_CSTATE_l ; { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace6_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace6_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_6_81_0 + 0 ) ; }
} { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace7_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace7_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_6_73_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace8_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace8_PWORK .
AQHandles , ssGetTaskTime ( S , 0 ) , ( char * ) & _rtB -> B_6_60_0 + 0 ) ; }
} { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace9_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace9_PWORK . AQHandles , ssGetTaskTime ( S ,
0 ) , ( char * ) & _rtB -> B_6_68_0 + 0 ) ; } } isHit = ssIsSampleHit ( S , 4
, 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 4 ) ; if (
ssGetTNextWasAdjusted ( S , 4 ) != 0 ) { _rtDW -> nextTime =
_ssGetVarNextHitTime ( S , 2 ) ; } if ( _rtDW -> justEnabled != 0 ) { _rtDW
-> justEnabled = 0 ; if ( taskTimeV >= _rtP -> P_50 ) { ratio = ( taskTimeV -
_rtP -> P_50 ) / _rtP -> P_48 ; numCycles = ( uint32_T ) muDoubleScalarFloor
( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio )
< DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW -> numCompleteCycles =
numCycles ; ratio = ( ( real_T ) numCycles * _rtP -> P_48 + _rtP -> P_50 ) +
_rtP -> P_49 * _rtP -> P_48 / 100.0 ; if ( taskTimeV < ratio ) { _rtDW ->
currentValue = 1 ; _rtDW -> nextTime = ratio ; } else { _rtDW -> currentValue
= 0 ; _rtDW -> nextTime = ( real_T ) ( numCycles + 1U ) * _rtP -> P_48 + _rtP
-> P_50 ; } } else { _rtDW -> numCompleteCycles = _rtP -> P_50 != 0.0 ? - 1 :
0 ; _rtDW -> currentValue = 0 ; _rtDW -> nextTime = _rtP -> P_50 ; } } else
if ( _rtDW -> nextTime <= taskTimeV ) { if ( _rtDW -> currentValue == 1 ) {
_rtDW -> currentValue = 0 ; _rtDW -> nextTime = ( real_T ) ( _rtDW ->
numCompleteCycles + 1LL ) * _rtP -> P_48 + _rtP -> P_50 ; } else { _rtDW ->
numCompleteCycles ++ ; _rtDW -> currentValue = 1 ; _rtDW -> nextTime = ( _rtP
-> P_49 * _rtP -> P_48 * 0.01 + ( real_T ) _rtDW -> numCompleteCycles * _rtP
-> P_48 ) + _rtP -> P_50 ; } } _ssSetVarNextHitTime ( S , 2 , _rtDW ->
nextTime ) ; if ( _rtDW -> currentValue == 1 ) { _rtB -> B_6_86_0 = _rtP ->
P_47 ; } else { _rtB -> B_6_86_0 = 0.0 ; } } _rtB -> B_6_87_0 = _rtP -> P_51
* _rtB -> B_6_60_0 ; _rtB -> B_6_88_0 = _rtP -> P_52 * _rtB -> B_6_56_0 ;
_rtB -> B_6_89_0 = ( _rtB -> B_6_86_0 + _rtB -> B_6_87_0 ) - _rtB -> B_6_88_0
; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) { taskTimeV =
ssGetTaskTime ( S , 3 ) ; if ( ssGetTNextWasAdjusted ( S , 3 ) != 0 ) { _rtDW
-> nextTime_l = _ssGetVarNextHitTime ( S , 1 ) ; } if ( _rtDW ->
justEnabled_e != 0 ) { _rtDW -> justEnabled_e = 0 ; if ( taskTimeV >= _rtP ->
P_56 ) { ratio = ( taskTimeV - _rtP -> P_56 ) / _rtP -> P_54 ; numCycles = (
uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T
) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; }
_rtDW -> numCompleteCycles_l = numCycles ; ratio = ( ( real_T ) numCycles *
_rtP -> P_54 + _rtP -> P_56 ) + _rtP -> P_55 * _rtP -> P_54 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_l =
ratio ; } else { _rtDW -> currentValue_o = 0 ; _rtDW -> nextTime_l = ( real_T
) ( numCycles + 1U ) * _rtP -> P_54 + _rtP -> P_56 ; } } else { _rtDW ->
numCompleteCycles_l = _rtP -> P_56 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue_o
= 0 ; _rtDW -> nextTime_l = _rtP -> P_56 ; } } else if ( _rtDW -> nextTime_l
<= taskTimeV ) { if ( _rtDW -> currentValue_o == 1 ) { _rtDW ->
currentValue_o = 0 ; _rtDW -> nextTime_l = ( real_T ) ( _rtDW ->
numCompleteCycles_l + 1LL ) * _rtP -> P_54 + _rtP -> P_56 ; } else { _rtDW ->
numCompleteCycles_l ++ ; _rtDW -> currentValue_o = 1 ; _rtDW -> nextTime_l =
( _rtP -> P_55 * _rtP -> P_54 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_l * _rtP -> P_54 ) + _rtP -> P_56 ; } }
_ssSetVarNextHitTime ( S , 1 , _rtDW -> nextTime_l ) ; if ( _rtDW ->
currentValue_o == 1 ) { _rtB -> B_6_90_0 = _rtP -> P_53 ; } else { _rtB ->
B_6_90_0 = 0.0 ; } } _rtB -> B_6_91_0 = _rtP -> P_57 * _rtB -> B_6_60_0 ;
_rtB -> B_6_92_0 = _rtP -> P_58 * _rtB -> B_6_58_0 ; _rtB -> B_6_93_0 = (
_rtB -> B_6_90_0 + _rtB -> B_6_91_0 ) - _rtB -> B_6_92_0 ; _rtB -> B_6_94_0 =
_rtP -> P_59 * _rtB -> B_6_64_0 ; _rtB -> B_6_95_0 = _rtP -> P_60 * _rtB ->
B_6_60_0 ; _rtB -> B_6_96_0 = _rtB -> B_6_94_0 - _rtB -> B_6_95_0 ; _rtB ->
B_6_97_0 = _rtP -> P_61 * _rtB -> B_6_68_0 ; _rtB -> B_6_98_0 = _rtP -> P_62
* _rtB -> B_6_81_0 ; _rtB -> B_6_99_0 = _rtP -> P_63 * _rtB -> B_6_62_0 ;
_rtB -> B_6_100_0 = ( _rtB -> B_6_97_0 + _rtB -> B_6_98_0 ) - _rtB ->
B_6_99_0 ; _rtB -> B_6_101_0 = _rtP -> P_64 * _rtB -> B_6_66_0 ; _rtB ->
B_6_102_0 = _rtP -> P_65 * _rtB -> B_6_64_0 ; _rtB -> B_6_103_0 = _rtB ->
B_6_101_0 - _rtB -> B_6_102_0 ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 2 ) ; if (
ssGetTNextWasAdjusted ( S , 2 ) != 0 ) { _rtDW -> nextTime_i =
_ssGetVarNextHitTime ( S , 0 ) ; } if ( _rtDW -> justEnabled_d != 0 ) { _rtDW
-> justEnabled_d = 0 ; if ( taskTimeV >= _rtP -> P_69 ) { ratio = ( taskTimeV
- _rtP -> P_69 ) / _rtP -> P_67 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_e = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_67 + _rtP -> P_69 ) + _rtP -> P_68 * _rtP -> P_67 / 100.0 ; if ( taskTimeV
< ratio ) { _rtDW -> currentValue_f = 1 ; _rtDW -> nextTime_i = ratio ; }
else { _rtDW -> currentValue_f = 0 ; _rtDW -> nextTime_i = ( real_T ) (
numCycles + 1U ) * _rtP -> P_67 + _rtP -> P_69 ; } } else { _rtDW ->
numCompleteCycles_e = _rtP -> P_69 != 0.0 ? - 1 : 0 ; _rtDW -> currentValue_f
= 0 ; _rtDW -> nextTime_i = _rtP -> P_69 ; } } else if ( _rtDW -> nextTime_i
<= taskTimeV ) { if ( _rtDW -> currentValue_f == 1 ) { _rtDW ->
currentValue_f = 0 ; _rtDW -> nextTime_i = ( real_T ) ( _rtDW ->
numCompleteCycles_e + 1LL ) * _rtP -> P_67 + _rtP -> P_69 ; } else { _rtDW ->
numCompleteCycles_e ++ ; _rtDW -> currentValue_f = 1 ; _rtDW -> nextTime_i =
( _rtP -> P_68 * _rtP -> P_67 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_e * _rtP -> P_67 ) + _rtP -> P_69 ; } }
_ssSetVarNextHitTime ( S , 0 , _rtDW -> nextTime_i ) ; if ( _rtDW ->
currentValue_f == 1 ) { _rtB -> B_6_104_0 = _rtP -> P_66 ; } else { _rtB ->
B_6_104_0 = 0.0 ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK_f . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_f . AQHandles , ssGetTaskTime ( S
, 1 ) , ( char * ) & _rtB -> B_6_104_0 + 0 ) ; } } } _rtB -> B_6_106_0 = _rtP
-> P_70 * _rtB -> B_6_66_0 ; _rtB -> B_6_107_0 = _rtP -> P_71 * _rtB ->
B_6_60_0 ; _rtB -> B_6_108_0 = _rtP -> P_72 * _rtB -> B_6_58_0 ; _rtB ->
B_6_109_0 = _rtP -> P_73 * _rtB -> B_6_56_0 ; _rtB -> B_6_110_0 = ( ( ( _rtB
-> B_6_107_0 - _rtB -> B_6_106_0 ) + _rtB -> B_6_104_0 ) + _rtB -> B_6_108_0
) + _rtB -> B_6_109_0 ; _rtB -> B_6_111_0 = _rtP -> P_74 * _rtB -> B_6_66_0 ;
_rtB -> B_6_112_0 = _rtP -> P_75 * _rtB -> B_6_64_0 ; _rtB -> B_6_113_0 =
_rtB -> B_6_111_0 - _rtB -> B_6_112_0 ; _rtB -> B_6_114_0 = _rtP -> P_76 *
_rtB -> B_6_60_0 ; _rtB -> B_6_115_0 = _rtP -> P_77 * _rtB -> B_6_56_0 ; _rtB
-> B_6_116_0 = _rtB -> B_6_114_0 - _rtB -> B_6_115_0 ; _rtB -> B_6_117_0 =
_rtP -> P_78 * _rtB -> B_6_60_0 ; _rtB -> B_6_118_0 = _rtP -> P_79 * _rtB ->
B_6_62_0 ; _rtB -> B_6_119_0 = _rtP -> P_80 * _rtB -> B_6_81_0 ; _rtB ->
B_6_120_0 = ( _rtB -> B_6_117_0 + _rtB -> B_6_118_0 ) - _rtB -> B_6_119_0 ;
_rtB -> B_6_121_0 = _rtP -> P_81 * _rtB -> B_6_68_0 ; _rtB -> B_6_122_0 =
_rtP -> P_82 * _rtB -> B_6_81_0 ; _rtB -> B_6_123_0 = _rtP -> P_83 * _rtB ->
B_6_62_0 ; _rtB -> B_6_124_0 = ( _rtB -> B_6_121_0 + _rtB -> B_6_122_0 ) -
_rtB -> B_6_123_0 ; _rtB -> B_6_125_0 = _rtP -> P_84 * _rtB -> B_6_73_0 ;
_rtB -> B_6_126_0 = _rtP -> P_85 * _rtB -> B_6_68_0 ; _rtB -> B_6_127_0 =
_rtB -> B_6_125_0 - _rtB -> B_6_126_0 ; _rtB -> B_6_128_0 = _rtP -> P_86 *
_rtB -> B_6_64_0 ; _rtB -> B_6_129_0 = _rtP -> P_87 * _rtB -> B_6_60_0 ; _rtB
-> B_6_130_0 = _rtB -> B_6_128_0 - _rtB -> B_6_129_0 ; _rtB -> B_6_131_0 =
_rtP -> P_88 * _rtB -> B_6_60_0 ; _rtB -> B_6_132_0 = _rtP -> P_89 * _rtB ->
B_6_62_0 ; _rtB -> B_6_133_0 = _rtP -> P_90 * _rtB -> B_6_81_0 ; _rtB ->
B_6_134_0 = ( _rtB -> B_6_131_0 + _rtB -> B_6_132_0 ) - _rtB -> B_6_133_0 ;
_rtB -> B_6_135_0 = _rtP -> P_91 * _rtB -> B_6_73_0 ; _rtB -> B_6_136_0 =
_rtP -> P_92 * _rtB -> B_6_68_0 ; _rtB -> B_6_137_0 = _rtB -> B_6_135_0 -
_rtB -> B_6_136_0 ; _rtB -> B_6_138_0 = _rtP -> P_93 * _rtB -> B_6_64_0 ;
_rtB -> B_6_139_0 = _rtP -> P_94 * _rtB -> B_6_70_0 ; _rtB -> B_6_140_0 =
_rtB -> B_6_138_0 - _rtB -> B_6_139_0 ; _rtB -> B_6_141_0 = _rtP -> P_95 *
_rtB -> B_6_73_0 ; _rtB -> B_6_142_0 = _rtP -> P_96 * _rtB -> B_6_62_0 ; _rtB
-> B_6_143_0 = _rtP -> P_97 * _rtB -> B_6_70_0 ; isHit = ssIsSampleHit ( S ,
6 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime ( S , 6 ) ; if (
ssGetTNextWasAdjusted ( S , 6 ) != 0 ) { _rtDW -> nextTime_o =
_ssGetVarNextHitTime ( S , 4 ) ; } if ( _rtDW -> justEnabled_i != 0 ) { _rtDW
-> justEnabled_i = 0 ; if ( taskTimeV >= _rtP -> P_101 ) { ratio = (
taskTimeV - _rtP -> P_101 ) / _rtP -> P_99 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_lt = numCycles ; ratio = ( ( real_T ) numCycles * _rtP
-> P_99 + _rtP -> P_101 ) + _rtP -> P_100 * _rtP -> P_99 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue_b = 1 ; _rtDW -> nextTime_o =
ratio ; } else { _rtDW -> currentValue_b = 0 ; _rtDW -> nextTime_o = ( real_T
) ( numCycles + 1U ) * _rtP -> P_99 + _rtP -> P_101 ; } } else { _rtDW ->
numCompleteCycles_lt = _rtP -> P_101 != 0.0 ? - 1 : 0 ; _rtDW ->
currentValue_b = 0 ; _rtDW -> nextTime_o = _rtP -> P_101 ; } } else if (
_rtDW -> nextTime_o <= taskTimeV ) { if ( _rtDW -> currentValue_b == 1 ) {
_rtDW -> currentValue_b = 0 ; _rtDW -> nextTime_o = ( real_T ) ( _rtDW ->
numCompleteCycles_lt + 1LL ) * _rtP -> P_99 + _rtP -> P_101 ; } else { _rtDW
-> numCompleteCycles_lt ++ ; _rtDW -> currentValue_b = 1 ; _rtDW ->
nextTime_o = ( _rtP -> P_100 * _rtP -> P_99 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_lt * _rtP -> P_99 ) + _rtP -> P_101 ; } }
_ssSetVarNextHitTime ( S , 4 , _rtDW -> nextTime_o ) ; if ( _rtDW ->
currentValue_b == 1 ) { _rtB -> B_6_144_0 = _rtP -> P_98 ; } else { _rtB ->
B_6_144_0 = 0.0 ; } } _rtB -> B_6_145_0 = _rtP -> P_102 * _rtB -> B_6_0_0 ;
_rtB -> B_6_146_0 = ( ( ( _rtB -> B_6_141_0 + _rtB -> B_6_142_0 ) + _rtB ->
B_6_143_0 ) - _rtB -> B_6_144_0 ) - _rtB -> B_6_145_0 ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Add_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_6_146_0 + 0 ) ; } } { if ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_PulseGenerator_at_outport_0_PWORK . AQHandles ,
ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_6_144_0 + 0 ) ; } } } isHit
= ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { taskTimeV = ssGetTaskTime
( S , 5 ) ; if ( ssGetTNextWasAdjusted ( S , 5 ) != 0 ) { _rtDW -> nextTime_f
= _ssGetVarNextHitTime ( S , 3 ) ; } if ( _rtDW -> justEnabled_f != 0 ) {
_rtDW -> justEnabled_f = 0 ; if ( taskTimeV >= _rtP -> P_106 ) { ratio = (
taskTimeV - _rtP -> P_106 ) / _rtP -> P_104 ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } _rtDW
-> numCompleteCycles_p = numCycles ; ratio = ( ( real_T ) numCycles * _rtP ->
P_104 + _rtP -> P_106 ) + _rtP -> P_105 * _rtP -> P_104 / 100.0 ; if (
taskTimeV < ratio ) { _rtDW -> currentValue_k = 1 ; _rtDW -> nextTime_f =
ratio ; } else { _rtDW -> currentValue_k = 0 ; _rtDW -> nextTime_f = ( real_T
) ( numCycles + 1U ) * _rtP -> P_104 + _rtP -> P_106 ; } } else { _rtDW ->
numCompleteCycles_p = _rtP -> P_106 != 0.0 ? - 1 : 0 ; _rtDW ->
currentValue_k = 0 ; _rtDW -> nextTime_f = _rtP -> P_106 ; } } else if (
_rtDW -> nextTime_f <= taskTimeV ) { if ( _rtDW -> currentValue_k == 1 ) {
_rtDW -> currentValue_k = 0 ; _rtDW -> nextTime_f = ( real_T ) ( _rtDW ->
numCompleteCycles_p + 1LL ) * _rtP -> P_104 + _rtP -> P_106 ; } else { _rtDW
-> numCompleteCycles_p ++ ; _rtDW -> currentValue_k = 1 ; _rtDW -> nextTime_f
= ( _rtP -> P_105 * _rtP -> P_104 * 0.01 + ( real_T ) _rtDW ->
numCompleteCycles_p * _rtP -> P_104 ) + _rtP -> P_106 ; } }
_ssSetVarNextHitTime ( S , 3 , _rtDW -> nextTime_f ) ; if ( _rtDW ->
currentValue_k == 1 ) { _rtB -> B_6_149_0 = _rtP -> P_103 ; } else { _rtB ->
B_6_149_0 = 0.0 ; } } _rtB -> B_6_150_0 = _rtP -> P_107 * _rtB -> B_6_73_0 ;
_rtB -> B_6_151_0 = _rtB -> B_6_149_0 - _rtB -> B_6_150_0 ; UNUSED_PARAMETER
( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_fuelCycle_T * _rtB ;
DW_fuelCycle_T * _rtDW ; P_fuelCycle_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_fuelCycle_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_fuelCycle_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_fuelCycle_T * ) _ssGetModelBlockIO ( S )
) ; { real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK . Head < (
_rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay_IWORK
. CircularBufSize , & _rtDW -> TransportDelay_IWORK . Tail , & _rtDW ->
TransportDelay_IWORK . Head , & _rtDW -> TransportDelay_IWORK . Last ,
simTime - _rtP -> P_8 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] =
_rtB -> B_6_2_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> Memory_PreviousInput = _rtB -> B_6_9_0 ; } { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK_g . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_h . Head = ( ( _rtDW
-> TransportDelay_IWORK_h . Head < ( _rtDW -> TransportDelay_IWORK_h .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_h . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_h . Head == _rtDW ->
TransportDelay_IWORK_h . Tail ) { if ( !
fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_h . CircularBufSize , & _rtDW -> TransportDelay_IWORK_h
. Tail , & _rtDW -> TransportDelay_IWORK_h . Head , & _rtDW ->
TransportDelay_IWORK_h . Last , simTime - _rtP -> P_13 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_h . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_h . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_h . Head ] = _rtB -> B_6_11_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_o = _rtB ->
B_6_18_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_c . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_p . Head = ( ( _rtDW -> TransportDelay_IWORK_p
. Head < ( _rtDW -> TransportDelay_IWORK_p . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_p . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_p . Head == _rtDW -> TransportDelay_IWORK_p . Tail ) {
if ( ! fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_p . CircularBufSize , & _rtDW -> TransportDelay_IWORK_p
. Tail , & _rtDW -> TransportDelay_IWORK_p . Head , & _rtDW ->
TransportDelay_IWORK_p . Last , simTime - _rtP -> P_18 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_p . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_p . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_p . Head ] = _rtB -> B_6_20_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_b = _rtB ->
B_6_27_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_l . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_j . Head = ( ( _rtDW -> TransportDelay_IWORK_j
. Head < ( _rtDW -> TransportDelay_IWORK_j . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_j . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_j . Head == _rtDW -> TransportDelay_IWORK_j . Tail ) {
if ( ! fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_j . CircularBufSize , & _rtDW -> TransportDelay_IWORK_j
. Tail , & _rtDW -> TransportDelay_IWORK_j . Head , & _rtDW ->
TransportDelay_IWORK_j . Last , simTime - _rtP -> P_23 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_j . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_j . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_j . Head ] = _rtB -> B_6_29_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_c = _rtB ->
B_6_36_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_b . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_c . Head = ( ( _rtDW -> TransportDelay_IWORK_c
. Head < ( _rtDW -> TransportDelay_IWORK_c . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_c . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_c . Head == _rtDW -> TransportDelay_IWORK_c . Tail ) {
if ( ! fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_c . CircularBufSize , & _rtDW -> TransportDelay_IWORK_c
. Tail , & _rtDW -> TransportDelay_IWORK_c . Head , & _rtDW ->
TransportDelay_IWORK_c . Last , simTime - _rtP -> P_28 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_c . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_c . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_c . Head ] = _rtB -> B_6_38_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_i = _rtB ->
B_6_45_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_cs . Head = ( ( _rtDW ->
TransportDelay_IWORK_cs . Head < ( _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_cs . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_cs . Head == _rtDW ->
TransportDelay_IWORK_cs . Tail ) { if ( !
fuelCycle_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_cs . CircularBufSize , & _rtDW ->
TransportDelay_IWORK_cs . Tail , & _rtDW -> TransportDelay_IWORK_cs . Head ,
& _rtDW -> TransportDelay_IWORK_cs . Last , simTime - _rtP -> P_33 , uBuffer
, ( boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_cs .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "tdelay memory allocation error" )
; return ; } } ( * uBuffer + _rtDW -> TransportDelay_IWORK_cs .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> TransportDelay_IWORK_cs . Head ] = _rtB -> B_6_47_0 ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW ->
Memory_PreviousInput_e = _rtB -> B_6_54_0 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_fuelCycle_T * _rtB ;
XDot_fuelCycle_T * _rtXdot ; _rtXdot = ( ( XDot_fuelCycle_T * ) ssGetdX ( S )
) ; _rtB = ( ( B_fuelCycle_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
Integrator_CSTATE = _rtB -> B_6_146_0 ; _rtXdot -> integrator_CSTATE = _rtB
-> B_6_113_0 ; _rtXdot -> integrator_CSTATE_p = _rtB -> B_6_120_0 ; _rtXdot
-> integrator_CSTATE_f = _rtB -> B_6_127_0 ; _rtXdot -> integrator_CSTATE_j =
_rtB -> B_6_124_0 ; _rtXdot -> integrator_CSTATE_l = _rtB -> B_6_130_0 ;
_rtXdot -> integrator_CSTATE_h = _rtB -> B_6_116_0 ; _rtXdot ->
Integrator_CSTATE_m = _rtB -> B_6_89_0 ; _rtXdot -> Integrator_CSTATE_f =
_rtB -> B_6_93_0 ; _rtXdot -> Integrator_CSTATE_mr = _rtB -> B_6_96_0 ;
_rtXdot -> Integrator_CSTATE_g = _rtB -> B_6_100_0 ; _rtXdot ->
Integrator_CSTATE_p = _rtB -> B_6_103_0 ; _rtXdot -> Integrator_CSTATE_gw =
_rtB -> B_6_110_0 ; _rtXdot -> Integrator_CSTATE_c = _rtB -> B_6_137_0 ;
_rtXdot -> Integrator_CSTATE_e = _rtB -> B_6_140_0 ; _rtXdot ->
Integrator_CSTATE_gf = _rtB -> B_6_151_0 ; _rtXdot -> Integrator_CSTATE_l =
_rtB -> B_6_134_0 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 260279713U ) ; ssSetChecksumVal ( S , 1 ,
1894016086U ) ; ssSetChecksumVal ( S , 2 , 1100594852U ) ; ssSetChecksumVal (
S , 3 , 174612852U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.6" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != ( SLSize )
sizeof ( DW_fuelCycle_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof ( DW_fuelCycle_T ) ) ;
ssSetErrorStatus ( S , msg ) ; } if ( ssGetSizeofGlobalBlockIO ( S ) != (
SLSize ) sizeof ( B_fuelCycle_T ) ) { static char msg [ 256 ] ; sprintf ( msg
, "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof ( B_fuelCycle_T ) )
; ssSetErrorStatus ( S , msg ) ; } { int ssSizeofParams ; ssGetSizeofParams (
S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof ( P_fuelCycle_T ) ) {
static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_fuelCycle_T ) ) ; ssSetErrorStatus ( S , msg ) ; }
} _ssSetModelRtp ( S , ( real_T * ) & fuelCycle_rtDefaultP ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
