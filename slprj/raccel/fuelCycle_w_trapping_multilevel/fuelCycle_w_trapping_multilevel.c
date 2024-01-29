#include "fuelCycle_w_trapping_multilevel.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include <float.h>
#include "fuelCycle_w_trapping_multilevel_private.h"
#include "rt_logging_mmi.h"
#include "fuelCycle_w_trapping_multilevel_capi.h"
#include "zero_crossing_types.h"
#include "fuelCycle_w_trapping_multilevel_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 7 , &
stopRequested ) ; } rtExtModeShutdown ( 7 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 8 ; const char_T
* gbl_raccel_Version = "23.2 (R2023b) 01-Aug-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct *
S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { rtX .
htgrh0jjqu = rtP . I_s_0 ; rtX . co1jdeau2v = rtP . Integrator_IC ; rtX .
lvqzai4v0g = rtP . Integrator_IC_gjn51xvom5 ; rtX . mnxe4thxfk = rtP .
Integrator_IC_mry3mue1xt ; rtX . mnuyjgz25d = rtP . Integrator_IC_lv4yux4fd2
; rtX . czr1kbthty = rtP . Integrator_IC_gsmhqvj2p2 ; rtX . dh4mqtfbta = rtP
. Integrator_IC_guilf0dsxs ; rtX . eopdaaoigp = rtP .
Integrator_IC_aoe5ma2bpt ; rtX . is4kh5d04r = rtP . Integrator_IC_ln32mnhczm
; rtX . i2yisk5ira = rtP . Integrator_IC_pzvlozo2nc ; rtX . dq5vg1pwin = rtP
. Integrator_IC_fznpj504vt ; rtX . ivth0fq3lc = rtP . Integrator1_IC ; rtX .
prie45bad0 = rtP . Integrator1_IC_bjh1younxk ; rtX . l2buheggo3 = rtP .
Integrator1_IC_luy00dmifv ; rtX . bz1y1deorv = rtP .
Integrator1_IC_hfd0yebv3k ; rtX . cjaogzvsz3 = rtP .
Integrator1_IC_apqnwc35ax ; rtX . gscw5qlois = rtP . Integrator_IC_kcrxo3wege
; rtX . n4ml13agdg = rtP . Integrator_IC_iauzmgwt3b ; rtX . lfdbokqx32 = rtP
. Integrator_IC_bfdxoyeb45 ; rtX . e330kkmdyz = rtP .
Integrator_IC_hsgeimv2ra ; rtX . cmqztgmaxh = rtP . Integrator1_IC_i02smi320p
; rtX . j4fspsirju = rtP . Integrator1_IC_nfzhle1k50 ; rtX . pd0yv0rpqx = rtP
. Integrator1_IC_p02hk220lo ; rtX . n00f3b3n5z = rtP .
Integrator1_IC_oqtjqencln ; rtX . ktyas5zdkb = rtP .
Integrator1_IC_lccyfk1lmn ; rtX . jslb3nmhpu = rtP . Integrator_IC_p0pugwgzsn
; rtX . nc0rcorjsb = rtP . Integrator_IC_lmncc23ueu ; rtX . aiyvnvjr41 = rtP
. Integrator_IC_nchr54klbk ; rtX . jgw5jvtnel = rtP .
Integrator_IC_jrf030n4yu ; rtX . jlkgfmapfz = rtP . Integrator1_IC_caj4cloteg
; rtX . mm0isfzekn = rtP . Integrator_IC_prbytjhtp3 ; rtX . h121gcp0ue = rtP
. Integrator1_IC_m4ot5s3dkq ; } void MdlEnable ( void ) { rtDW . gjpvvsicgx =
1 ; _ssSetSampleHit ( rtS , 4 , 1 ) ; _ssSetTaskTime ( rtS , 4 , ssGetT ( rtS
) ) ; _ssSetVarNextHitTime ( rtS , 2 , ssGetT ( rtS ) ) ; ; rtDW . lk33nb0dif
= 1 ; _ssSetSampleHit ( rtS , 3 , 1 ) ; _ssSetTaskTime ( rtS , 3 , ssGetT (
rtS ) ) ; _ssSetVarNextHitTime ( rtS , 1 , ssGetT ( rtS ) ) ; ; rtDW .
basopanm0u = 1 ; _ssSetSampleHit ( rtS , 2 , 1 ) ; _ssSetTaskTime ( rtS , 2 ,
ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS , 0 , ssGetT ( rtS ) ) ; ; rtDW
. az3nbubu5p = 1 ; _ssSetSampleHit ( rtS , 6 , 1 ) ; _ssSetTaskTime ( rtS , 6
, ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS , 4 , ssGetT ( rtS ) ) ; ;
rtDW . hyxofhb30f = 1 ; _ssSetSampleHit ( rtS , 5 , 1 ) ; _ssSetTaskTime (
rtS , 5 , ssGetT ( rtS ) ) ; _ssSetVarNextHitTime ( rtS , 3 , ssGetT ( rtS )
) ; ; } void MdlStart ( void ) { { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/Div" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bpvydpjffg . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "7347c669-bfdd-4079-a603-e431e7bcdc4e" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bpvydpjffg . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bpvydpjffg . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bpvydpjffg . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bpvydpjffg .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bpvydpjffg . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bpvydpjffg . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bpvydpjffg . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/FW" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bfgk1czl4m . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "ea159ae3-c17c-4303-922e-7379b6491e1b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bfgk1czl4m . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bfgk1czl4m . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bfgk1czl4m . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bfgk1czl4m .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bfgk1czl4m . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bfgk1czl4m . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bfgk1czl4m . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/HX" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ja1ege25yh . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "5a29594d-5223-4b5c-b46b-8c4acf7e5f07" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . ja1ege25yh . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . ja1ege25yh . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . ja1ege25yh . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . ja1ege25yh .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ja1ege25yh . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
ja1ege25yh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
ja1ege25yh . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/ISS_9" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . dn0qqupwms . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "cf5d930e-1b10-4c50-8605-c3c7839d6cb2" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . dn0qqupwms . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . dn0qqupwms . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . dn0qqupwms . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . dn0qqupwms .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . dn0qqupwms . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
dn0qqupwms . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
dn0qqupwms . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/TES" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . in2jxpqlzw . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "e86166e0-ebe7-4323-b31c-49081a57d87e" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . in2jxpqlzw . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . in2jxpqlzw . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . in2jxpqlzw . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . in2jxpqlzw .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . in2jxpqlzw . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
in2jxpqlzw . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
in2jxpqlzw . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/breedingZone_1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . phht5zmf24 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "abfbfae9-27b2-4e00-ae34-47f9684a48ba" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . phht5zmf24 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . phht5zmf24 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . phht5zmf24 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . phht5zmf24 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . phht5zmf24 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
phht5zmf24 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
phht5zmf24 . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/fuelCleanup" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . g1upx2ora0 . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "0795d978-e3ef-4dd9-ae54-037888f5a2ed" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . g1upx2ora0 . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . g1upx2ora0 . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . g1upx2ora0 . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . g1upx2ora0 .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . g1upx2ora0 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
g1upx2ora0 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
g1upx2ora0 . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/membrane" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . gb53i5u3uk . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "78f310a6-1a7e-4480-843a-c0b36d4803e1" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . gb53i5u3uk . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . gb53i5u3uk . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . gb53i5u3uk . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . gb53i5u3uk .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gb53i5u3uk . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
gb53i5u3uk . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
gb53i5u3uk . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/storage_10" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . e0iok5rpsx . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "f320544e-2c23-419e-a43c-3701d07323c6" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . e0iok5rpsx . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . e0iok5rpsx . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . e0iok5rpsx . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . e0iok5rpsx .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . e0iok5rpsx . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
e0iok5rpsx . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
e0iok5rpsx . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/vacuumPump" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bvdj0li5qv . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "087da583-7f6e-412c-b00d-d67dc92b5cf2" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bvdj0li5qv . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bvdj0li5qv . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bvdj0li5qv . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bvdj0li5qv .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bvdj0li5qv . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bvdj0li5qv . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bvdj0li5qv . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "storage_10" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "storage_10" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "storage_10" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. ohawovjfhh . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"ad94b85c-cdbf-470f-9cd6-9d6a7c009ecd" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . ohawovjfhh . AQHandles , hDT , & srcInfo ) ; if ( rtDW . ohawovjfhh .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ohawovjfhh . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
ohawovjfhh . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ohawovjfhh .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . ohawovjfhh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . ohawovjfhh . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ohawovjfhh . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_11" ) ; sdiRegisterWksVariable ( rtDW . ohawovjfhh . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "ISS_9" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "ISS_9" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "fuelCycle_w_trapping_multilevel/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "ISS_9" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ofgcg2rwnf . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "70bde8be-beba-4c94-9520-69d217bdd102" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . ofgcg2rwnf . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . ofgcg2rwnf . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . ofgcg2rwnf . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . ofgcg2rwnf .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ofgcg2rwnf . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
ofgcg2rwnf . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
ofgcg2rwnf . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ofgcg2rwnf . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_9" ) ; sdiRegisterWksVariable ( rtDW . ofgcg2rwnf . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "membrane" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "membrane" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace10" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "membrane" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. lxy40zsik3 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"6d3d5694-b9a5-4b9c-a533-f8568ce08108" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . lxy40zsik3 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . lxy40zsik3 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . lxy40zsik3 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
lxy40zsik3 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . lxy40zsik3 .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . lxy40zsik3 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . lxy40zsik3 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . lxy40zsik3 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_12" ) ; sdiRegisterWksVariable ( rtDW . lxy40zsik3 . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "breedingZone_1" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "breedingZone_1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace2" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "breedingZone_1" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. lr5q5utmxh . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"fe46c148-deab-47c6-a710-8cf44d152d95" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . lr5q5utmxh . AQHandles , hDT , & srcInfo ) ; if ( rtDW . lr5q5utmxh .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . lr5q5utmxh . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
lr5q5utmxh . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . lr5q5utmxh .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . lr5q5utmxh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . lr5q5utmxh . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . lr5q5utmxh . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_1" ) ; sdiRegisterWksVariable ( rtDW . lr5q5utmxh . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "TES" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"TES" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/To Workspace3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "TES" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ojaixcrugo . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "9fb9d46e-ea94-46ac-9170-fc27592cb86f" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . ojaixcrugo . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . ojaixcrugo . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . ojaixcrugo . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . ojaixcrugo .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . ojaixcrugo . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
ojaixcrugo . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
ojaixcrugo . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . ojaixcrugo . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_2" ) ; sdiRegisterWksVariable ( rtDW . ojaixcrugo . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "FW" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"FW" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/To Workspace4" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "FW" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . jhnokpp1dp . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "580a4485-4d99-4307-a962-2320443d047b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . jhnokpp1dp . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . jhnokpp1dp . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . jhnokpp1dp . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . jhnokpp1dp .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . jhnokpp1dp . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
jhnokpp1dp . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
jhnokpp1dp . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . jhnokpp1dp . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_3" ) ; sdiRegisterWksVariable ( rtDW . jhnokpp1dp . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Div" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"Div" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/To Workspace5" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Div" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . iohckarwzg . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "e8ab253e-0e24-4151-b289-3b1fd90e7ac6" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . iohckarwzg . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . iohckarwzg . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . iohckarwzg . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . iohckarwzg .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . iohckarwzg . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
iohckarwzg . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
iohckarwzg . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . iohckarwzg . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_4" ) ; sdiRegisterWksVariable ( rtDW . iohckarwzg . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "exhaust_DS_6" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "exhaust_DS_6" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace6" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "exhaust_DS_6" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. je2kiqe4dx . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"d9deafbf-1177-4a49-b87a-d8529cafac5a" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . je2kiqe4dx . AQHandles , hDT , & srcInfo ) ; if ( rtDW . je2kiqe4dx .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . je2kiqe4dx . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
je2kiqe4dx . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . je2kiqe4dx .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . je2kiqe4dx . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . je2kiqe4dx . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . je2kiqe4dx . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_6" ) ; sdiRegisterWksVariable ( rtDW . je2kiqe4dx . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "vacuumPump" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "vacuumPump" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace7" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "vacuumPump" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. njvgyvffo2 . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"221c9fcd-c18b-4c0e-b0ea-c2b345905e14" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . njvgyvffo2 . AQHandles , hDT , & srcInfo ) ; if ( rtDW . njvgyvffo2 .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . njvgyvffo2 . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
njvgyvffo2 . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . njvgyvffo2 .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . njvgyvffo2 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . njvgyvffo2 . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . njvgyvffo2 . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_7" ) ; sdiRegisterWksVariable ( rtDW . njvgyvffo2 . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "HX" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"HX" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/To Workspace8" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "HX" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . diar2azokk . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "01143577-63dc-43c5-8990-f32a369e4827" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . diar2azokk . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . diar2azokk . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . diar2azokk . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . diar2azokk .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . diar2azokk . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
diar2azokk . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
diar2azokk . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . diar2azokk . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_5" ) ; sdiRegisterWksVariable ( rtDW . diar2azokk . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "fuelCleanup" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "fuelCleanup" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/To Workspace9" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "fuelCleanup" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. a0s45dbdod . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"88290ed5-7a72-4eea-87ee-ad9e7197ccbe" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . a0s45dbdod . AQHandles , hDT , & srcInfo ) ; if ( rtDW . a0s45dbdod .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . a0s45dbdod . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
a0s45dbdod . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . a0s45dbdod .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . a0s45dbdod . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . a0s45dbdod . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . a0s45dbdod . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_8" ) ; sdiRegisterWksVariable ( rtDW . a0s45dbdod . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "fuelCycle_w_trapping_multilevel/Div/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Add2" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . n2tu4152xd . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "a3b5013c-333d-410a-8a12-fcad06872f35" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . n2tu4152xd . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . n2tu4152xd . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . n2tu4152xd . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . n2tu4152xd .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . n2tu4152xd . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
n2tu4152xd . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
n2tu4152xd . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . n2tu4152xd . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_4_trapped" ) ; sdiRegisterWksVariable ( rtDW . n2tu4152xd . AQHandles ,
varName , "array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars (
"Trapped_Inventory_singleblock4:1" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars (
"Trapped_Inventory_singleblock4:1" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "fuelCycle_w_trapping_multilevel/Div/To Workspace1" )
; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Trapped_Inventory_singleblock4:1" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . favhxcmqok . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "1dce8225-e643-4f36-930a-5a2d44f9251c" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . favhxcmqok . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . favhxcmqok . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . favhxcmqok . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . favhxcmqok .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . favhxcmqok . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
favhxcmqok . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
favhxcmqok . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . favhxcmqok . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"trap" ) ; sdiRegisterWksVariable ( rtDW . favhxcmqok . AQHandles , varName ,
"array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "fuelCycle_w_trapping_multilevel/FW/To Workspace" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Add2" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bni3utz05a . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "44c5efd9-f95b-4393-b3aa-4b225deb887a" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bni3utz05a . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bni3utz05a . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bni3utz05a . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bni3utz05a .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bni3utz05a . AQHandles ,
ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bni3utz05a . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bni3utz05a . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . bni3utz05a . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_3_trapped" ) ; sdiRegisterWksVariable ( rtDW . bni3utz05a . AQHandles ,
varName , "array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Pulse\nGenerator" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Pulse\nGenerator" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/breedingZone_1/To Workspace" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Pulse\nGenerator" ) ; sdiAsyncRepoDataTypeHandle hDT
= sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. lumyjs23ja . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"332921a9-97c5-44f6-a743-cac8e373d869" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . lumyjs23ja . AQHandles , hDT , & srcInfo ) ; if ( rtDW . lumyjs23ja .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . lumyjs23ja . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
lumyjs23ja . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . lumyjs23ja .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . lumyjs23ja . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . lumyjs23ja . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . lumyjs23ja . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"T_generation" ) ; sdiRegisterWksVariable ( rtDW . lumyjs23ja . AQHandles ,
varName , "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "Add2" ) ; sdiLabelU blockPath = sdiGetLabelFromChars
( "fuelCycle_w_trapping_multilevel/breedingZone_1/To Workspace1" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "Add2" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. bk4jfotvgv . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"6d015248-f9ea-4f90-884e-9b9bb62da9cc" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . bk4jfotvgv . AQHandles , hDT , & srcInfo ) ; if ( rtDW . bk4jfotvgv .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . bk4jfotvgv . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
bk4jfotvgv . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bk4jfotvgv .
AQHandles , ssGetTaskTime ( rtS , 0 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . bk4jfotvgv . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . bk4jfotvgv . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . bk4jfotvgv . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"I_1_trapped" ) ; sdiRegisterWksVariable ( rtDW . bk4jfotvgv . AQHandles ,
varName , "array" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "I_dot" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "I_dot" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/storage_10/Add" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "I_dot" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . l0q4q2mauq . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "3f80a943-f6ee-4894-9bdf-338b60724705" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . l0q4q2mauq . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . l0q4q2mauq . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . l0q4q2mauq . AQHandles , "Continuous" ,
0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . l0q4q2mauq .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . l0q4q2mauq . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
l0q4q2mauq . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
l0q4q2mauq . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU propName = sdiGetLabelFromChars ( ""
) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"fuelCycle_w_trapping_multilevel/storage_10/Pulse Generator" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. expqsi0g3r . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"4016df69-3c8d-46b4-900f-fd4754336353" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . expqsi0g3r . AQHandles , hDT , & srcInfo ) ; if ( rtDW . expqsi0g3r .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . expqsi0g3r . AQHandles ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
expqsi0g3r . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . expqsi0g3r .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . expqsi0g3r . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . expqsi0g3r . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { } } } } MdlInitialize ( ) ; MdlEnable ( ) ;
} void MdlOutputs ( int_T tid ) { real_T hipf51rmyh ; real_T ratio ; uint32_T
numCycles ; boolean_T xHasBeenChanged ; ZCEventType zcEvent ; rtB .
iiiwxuggrg = rtX . htgrh0jjqu ; rtB . nf4zcvrrw1 = rtX . co1jdeau2v ; rtB .
fvf3nbzioe = rtX . lvqzai4v0g ; rtB . k4b4lf14vj = rtX . mnxe4thxfk ; rtB .
etvkdwnkpj = rtX . mnuyjgz25d ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . bpvydpjffg . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . bpvydpjffg . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. etvkdwnkpj + 0 ) ; } } } rtB . psuxlzsuxz = rtX . czr1kbthty ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . bfgk1czl4m . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bfgk1czl4m . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . psuxlzsuxz + 0 ) ; } } } rtB .
ebk01qyesg = rtX . dh4mqtfbta ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . ja1ege25yh . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . ja1ege25yh . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. ebk01qyesg + 0 ) ; } } } rtB . idcpjxrtqy = rtX . eopdaaoigp ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . dn0qqupwms . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . dn0qqupwms . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . idcpjxrtqy + 0 ) ; } } { if (
rtDW . in2jxpqlzw . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . in2jxpqlzw . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. fvf3nbzioe + 0 ) ; } } { if ( rtDW . phht5zmf24 . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . phht5zmf24 . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . nf4zcvrrw1 + 0 ) ; } } } rtB .
iajp4d0mcl = rtX . is4kh5d04r ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . g1upx2ora0 . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . g1upx2ora0 . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. iajp4d0mcl + 0 ) ; } } } rtB . osbfg4zlct = rtX . i2yisk5ira ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . gb53i5u3uk . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . gb53i5u3uk . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . osbfg4zlct + 0 ) ; } } { if (
rtDW . e0iok5rpsx . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . e0iok5rpsx . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. iiiwxuggrg + 0 ) ; } } { if ( rtDW . bvdj0li5qv . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bvdj0li5qv . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . k4b4lf14vj + 0 ) ; } } } { if
( rtDW . ohawovjfhh . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal
( rtDW . ohawovjfhh . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) &
rtB . iiiwxuggrg + 0 ) ; } } { if ( rtDW . ofgcg2rwnf . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . ofgcg2rwnf . AQHandles ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . idcpjxrtqy + 0 ) ; } } { if (
rtDW . lxy40zsik3 . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . lxy40zsik3 . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB
. osbfg4zlct + 0 ) ; } } { if ( rtDW . lr5q5utmxh . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . lr5q5utmxh . AQHandles ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . nf4zcvrrw1 + 0 ) ; } } { if (
rtDW . ojaixcrugo . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . ojaixcrugo . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB
. fvf3nbzioe + 0 ) ; } } { if ( rtDW . jhnokpp1dp . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . jhnokpp1dp . AQHandles ,
ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB . psuxlzsuxz + 0 ) ; } } { if (
rtDW . iohckarwzg . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . iohckarwzg . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB
. etvkdwnkpj + 0 ) ; } } rtB . eqaeyezh1s = rtX . dq5vg1pwin ; { if ( rtDW .
je2kiqe4dx . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
je2kiqe4dx . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
eqaeyezh1s + 0 ) ; } } { if ( rtDW . njvgyvffo2 . AQHandles && ssGetLogOutput
( rtS ) ) { sdiWriteSignal ( rtDW . njvgyvffo2 . AQHandles , ssGetTaskTime (
rtS , 0 ) , ( char * ) & rtB . k4b4lf14vj + 0 ) ; } } { if ( rtDW .
diar2azokk . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW .
diar2azokk . AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & rtB .
ebk01qyesg + 0 ) ; } } { if ( rtDW . a0s45dbdod . AQHandles && ssGetLogOutput
( rtS ) ) { sdiWriteSignal ( rtDW . a0s45dbdod . AQHandles , ssGetTaskTime (
rtS , 0 ) , ( char * ) & rtB . iajp4d0mcl + 0 ) ; } } rtB . csnrgnegvo =
muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if (
ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn ( FALLING_ZERO_CROSSING
, & rtPrevZCX . e0m41s4pce , ( rtB . csnrgnegvo ) ) ; if ( zcEvent !=
NO_ZCEVENT ) { xHasBeenChanged = ( rtX . ivth0fq3lc != rtP . Integrator1_IC )
; rtX . ivth0fq3lc = rtP . Integrator1_IC ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . b2vzo0hy2s =
rtX . ivth0fq3lc ; } else { rtB . b2vzo0hy2s = rtX . ivth0fq3lc ; } rtB .
eqm2qb1xmg = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . f1pzzmnmrz , ( rtB . eqm2qb1xmg ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . prie45bad0 != rtP .
Integrator1_IC_bjh1younxk ) ; rtX . prie45bad0 = rtP .
Integrator1_IC_bjh1younxk ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . osty4w0h40 =
rtX . prie45bad0 ; } else { rtB . osty4w0h40 = rtX . prie45bad0 ; } rtB .
hpv03qx2eh = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . lwvvm1bu31 , ( rtB . hpv03qx2eh ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . l2buheggo3 != rtP .
Integrator1_IC_luy00dmifv ) ; rtX . l2buheggo3 = rtP .
Integrator1_IC_luy00dmifv ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . owkrxvvxqg =
rtX . l2buheggo3 ; } else { rtB . owkrxvvxqg = rtX . l2buheggo3 ; } rtB .
oee1351fty = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . mkv1qjpzdz , ( rtB . oee1351fty ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . bz1y1deorv != rtP .
Integrator1_IC_hfd0yebv3k ) ; rtX . bz1y1deorv = rtP .
Integrator1_IC_hfd0yebv3k ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . lrc5riqsm0 =
rtX . bz1y1deorv ; } else { rtB . lrc5riqsm0 = rtX . bz1y1deorv ; } rtB .
gti1d5wxoc = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . ezwnrlce0c , ( rtB . gti1d5wxoc ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . cjaogzvsz3 != rtP .
Integrator1_IC_apqnwc35ax ) ; rtX . cjaogzvsz3 = rtP .
Integrator1_IC_apqnwc35ax ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . bohvfvgygo =
rtX . cjaogzvsz3 ; } else { rtB . bohvfvgygo = rtX . cjaogzvsz3 ; }
hipf51rmyh = ( ( ( rtB . b2vzo0hy2s + rtB . owkrxvvxqg ) + rtB . lrc5riqsm0 )
+ rtB . bohvfvgygo ) + rtB . osty4w0h40 ; { if ( rtDW . n2tu4152xd .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . n2tu4152xd .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & hipf51rmyh + 0 ) ; } } {
if ( rtDW . favhxcmqok . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . favhxcmqok . AQHandles , ssGetTaskTime ( rtS , 0 ) ,
( char * ) & rtB . osty4w0h40 + 0 ) ; } } if ( ssIsSampleHit ( rtS , 4 , 0 )
) { hipf51rmyh = ssGetTaskTime ( rtS , 4 ) ; if ( ssGetTNextWasAdjusted ( rtS
, 4 ) ) { rtDW . jbfemjfqdu = _ssGetVarNextHitTime ( rtS , 2 ) ; } if ( rtDW
. gjpvvsicgx != 0 ) { rtDW . gjpvvsicgx = 0 ; if ( hipf51rmyh >= rtP .
PulseGenerator_PhaseDelay ) { ratio = ( hipf51rmyh - rtP .
PulseGenerator_PhaseDelay ) / rtP . PulseGenerator_Period ; numCycles = (
uint32_T ) muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T
) ( numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; }
rtDW . b0dld00fnu = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
PulseGenerator_Period + rtP . PulseGenerator_PhaseDelay ) + rtP . AF * rtP .
PulseGenerator_Period / 100.0 ; if ( hipf51rmyh < ratio ) { rtDW . ivnf1ct5mk
= 1 ; rtDW . jbfemjfqdu = ratio ; } else { rtDW . ivnf1ct5mk = 0 ; rtDW .
jbfemjfqdu = ( real_T ) ( numCycles + 1U ) * rtP . PulseGenerator_Period +
rtP . PulseGenerator_PhaseDelay ; } } else { rtDW . b0dld00fnu = rtP .
PulseGenerator_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW . ivnf1ct5mk = 0 ; rtDW .
jbfemjfqdu = rtP . PulseGenerator_PhaseDelay ; } } else if ( rtDW .
jbfemjfqdu <= hipf51rmyh ) { if ( rtDW . ivnf1ct5mk == 1 ) { rtDW .
ivnf1ct5mk = 0 ; rtDW . jbfemjfqdu = ( real_T ) ( rtDW . b0dld00fnu + 1L ) *
rtP . PulseGenerator_Period + rtP . PulseGenerator_PhaseDelay ; } else { rtDW
. b0dld00fnu ++ ; rtDW . ivnf1ct5mk = 1 ; rtDW . jbfemjfqdu = ( rtP . AF *
rtP . PulseGenerator_Period * 0.01 + ( real_T ) rtDW . b0dld00fnu * rtP .
PulseGenerator_Period ) + rtP . PulseGenerator_PhaseDelay ; } }
_ssSetVarNextHitTime ( rtS , 2 , rtDW . jbfemjfqdu ) ; if ( rtDW . ivnf1ct5mk
== 1 ) { rtB . cg5lpoodm2 = rtP . fp4 * rtP . N_dot / rtP . TBE ; } else {
rtB . cg5lpoodm2 = 0.0 ; } } rtB . niogfz3nzj = rtP . f54 / rtP . tau5 * rtB
. ebk01qyesg ; rtB . cpciqgvd1i = 1.0 / rtP . T4 * rtB . etvkdwnkpj ; rtB .
ixhq3mtynq = 1.0 / rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB .
etvkdwnkpj ; rtB . aciokmkyoi = rtP . PM_tungsten / rtP . PM_tritium / rtP .
M_tungsten * rtB . b2vzo0hy2s ; rtB . fgstkpld00 = rtB . lgyyr12kek - rtB .
aciokmkyoi ; rtB . c2macncjx1 = rtB . ixhq3mtynq * rtB . fgstkpld00 ; rtB .
gvzulll142 = 1.0 / rtP . tau_detrap_tungsten [ 0 ] * rtB . b2vzo0hy2s ; rtB .
dzzfskofco = rtB . c2macncjx1 - rtB . gvzulll142 ; rtB . hdb3kkl1an = 1.0 /
rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB . etvkdwnkpj ; rtB .
hdfhl1b201 = rtX . gscw5qlois ; rtB . jyxotbfmiy = rtP . PM_tungsten / rtP .
PM_tritium / rtP . M_tungsten * rtB . owkrxvvxqg ; rtB . fni551xrky = rtB .
hdfhl1b201 - rtB . jyxotbfmiy ; rtB . i5gekqrszk = rtB . hdb3kkl1an * rtB .
fni551xrky ; rtB . opvsbdmt4f = 1.0 / rtP . tau_detrap_tungsten [ 1 ] * rtB .
owkrxvvxqg ; rtB . f4qjawxtxc = rtB . i5gekqrszk - rtB . opvsbdmt4f ; rtB .
b4o0mwd5s1 = 1.0 / rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB .
etvkdwnkpj ; rtB . ibntl0qzrn = rtX . n4ml13agdg ; rtB . eoyhxc3y5c = rtP .
PM_tungsten / rtP . PM_tritium / rtP . M_tungsten * rtB . lrc5riqsm0 ; rtB .
fqf2ig4ozo = rtB . ibntl0qzrn - rtB . eoyhxc3y5c ; rtB . pylqoentdj = rtB .
b4o0mwd5s1 * rtB . fqf2ig4ozo ; rtB . cph5fceo1k = 1.0 / rtP .
tau_detrap_tungsten [ 2 ] * rtB . lrc5riqsm0 ; rtB . dqaeumpfwq = rtB .
pylqoentdj - rtB . cph5fceo1k ; rtB . oz2ioyl1d1 = 1.0 / rtP .
tau_trap_tungsten / rtP . n_solute_tungsten * rtB . etvkdwnkpj ; rtB .
kldtvssa3v = rtX . lfdbokqx32 ; rtB . dssu0124ca = rtP . PM_tungsten / rtP .
PM_tritium / rtP . M_tungsten * rtB . bohvfvgygo ; rtB . jubael0s5t = rtB .
kldtvssa3v - rtB . dssu0124ca ; rtB . imvzvxfth1 = rtB . oz2ioyl1d1 * rtB .
jubael0s5t ; rtB . hhlfdxq4tq = 1.0 / rtP . tau_detrap_tungsten [ 3 ] * rtB .
bohvfvgygo ; rtB . lv3saiokkc = rtB . imvzvxfth1 - rtB . hhlfdxq4tq ; rtB .
mmzzdny3gv = 1.0 / rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB .
etvkdwnkpj ; rtB . bxhcn03bs3 = rtX . e330kkmdyz ; rtB . jw1mkvjqxd = rtP .
PM_tungsten / rtP . PM_tritium / rtP . M_tungsten * rtB . osty4w0h40 ; rtB .
ap4ejq14cx = rtB . bxhcn03bs3 - rtB . jw1mkvjqxd ; rtB . d11crs30zx = rtB .
mmzzdny3gv * rtB . ap4ejq14cx ; rtB . pkusgmygp4 = 1.0 / rtP .
tau_detrap_tungsten [ 4 ] * rtB . osty4w0h40 ; rtB . o3mlawuzsu = rtB .
d11crs30zx - rtB . pkusgmygp4 ; rtB . klulqzlxhy = ( ( ( rtB . dzzfskofco +
rtB . f4qjawxtxc ) + rtB . dqaeumpfwq ) + rtB . lv3saiokkc ) + rtB .
o3mlawuzsu ; rtB . mg2xxgovdn = ( ( rtB . cg5lpoodm2 + rtB . niogfz3nzj ) -
rtB . cpciqgvd1i ) - rtB . klulqzlxhy ; rtB . nh1yusewyx = 1.0 / rtP .
n_tungsten_max [ 1 ] * rtB . ibntl0qzrn ; rtB . mq55kovd3p = rtB . fkwpmfy3ic
* rtB . nh1yusewyx ; rtB . ffijpdjagp = rtB . ibntl0qzrn * rtB . ohvaeydtca ;
rtB . clohbn4dfr = ( rtB . fkwpmfy3ic - rtB . mq55kovd3p ) - rtB . ffijpdjagp
; rtB . jtu2fng3ej = 1.0 / rtP . n_tungsten_max [ 2 ] * rtB . kldtvssa3v ;
rtB . fybyalbgb2 = rtB . bmkrxgfo2l * rtB . jtu2fng3ej ; rtB . k3yjc0yg3g =
rtB . kldtvssa3v * rtB . ojyufdjynv ; rtB . p2krjfpfgh = ( rtB . bmkrxgfo2l -
rtB . fybyalbgb2 ) - rtB . k3yjc0yg3g ; rtB . gtcb3jdxp3 = 1.0 / rtP .
n_tungsten_max [ 3 ] * rtB . bxhcn03bs3 ; rtB . l0llkpzm13 = rtB . gcmv4lfn4n
* rtB . gtcb3jdxp3 ; rtB . ciffbyucrp = rtB . bxhcn03bs3 * rtB . m2fionkrn0 ;
rtB . mtsxpijwck = ( rtB . gcmv4lfn4n - rtB . l0llkpzm13 ) - rtB . ciffbyucrp
; rtB . kab2nly4jj = 1.0 / rtP . n_tungsten_max [ 0 ] * rtB . hdfhl1b201 ;
rtB . ow3uqqg2aj = rtB . fgkaot3e42 * rtB . kab2nly4jj ; rtB . ciw3n3wmul =
rtB . hdfhl1b201 * rtB . kdkynqxxwq ; rtB . jjs4ssptlk = ( rtB . fgkaot3e42 -
rtB . ow3uqqg2aj ) - rtB . ciw3n3wmul ; rtB . mug54mzksq = muDoubleScalarMod
( ssGetT ( rtS ) , rtP . T_replacement ) ; if ( ssIsModeUpdateTimeStep ( rtS
) ) { zcEvent = rt_ZCFcn ( FALLING_ZERO_CROSSING , & rtPrevZCX . ehgnzb15jz ,
( rtB . mug54mzksq ) ) ; if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = (
rtX . cmqztgmaxh != rtP . Integrator1_IC_i02smi320p ) ; rtX . cmqztgmaxh =
rtP . Integrator1_IC_i02smi320p ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . cpkkbsqjby =
rtX . cmqztgmaxh ; } else { rtB . cpkkbsqjby = rtX . cmqztgmaxh ; } rtB .
h1pesm521l = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . g4kyl2al0w , ( rtB . h1pesm521l ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . j4fspsirju != rtP .
Integrator1_IC_nfzhle1k50 ) ; rtX . j4fspsirju = rtP .
Integrator1_IC_nfzhle1k50 ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . mrg2inxnui =
rtX . j4fspsirju ; } else { rtB . mrg2inxnui = rtX . j4fspsirju ; } rtB .
f3bngaj4zp = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . kccjtmusvi , ( rtB . f3bngaj4zp ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . pd0yv0rpqx != rtP .
Integrator1_IC_p02hk220lo ) ; rtX . pd0yv0rpqx = rtP .
Integrator1_IC_p02hk220lo ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . ees2bp2bzh =
rtX . pd0yv0rpqx ; } else { rtB . ees2bp2bzh = rtX . pd0yv0rpqx ; } rtB .
m34nqp4n5z = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . lxhainymwv , ( rtB . m34nqp4n5z ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . n00f3b3n5z != rtP .
Integrator1_IC_oqtjqencln ) ; rtX . n00f3b3n5z = rtP .
Integrator1_IC_oqtjqencln ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . ky32tdgwev =
rtX . n00f3b3n5z ; } else { rtB . ky32tdgwev = rtX . n00f3b3n5z ; } rtB .
icsnarysuk = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . dv0chgctwn , ( rtB . icsnarysuk ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . ktyas5zdkb != rtP .
Integrator1_IC_lccyfk1lmn ) ; rtX . ktyas5zdkb = rtP .
Integrator1_IC_lccyfk1lmn ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . l1mbg2lxtf =
rtX . ktyas5zdkb ; } else { rtB . l1mbg2lxtf = rtX . ktyas5zdkb ; }
hipf51rmyh = ( ( ( rtB . cpkkbsqjby + rtB . mrg2inxnui ) + rtB . ees2bp2bzh )
+ rtB . ky32tdgwev ) + rtB . l1mbg2lxtf ; { if ( rtDW . bni3utz05a .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bni3utz05a .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & hipf51rmyh + 0 ) ; } }
if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { hipf51rmyh = ssGetTaskTime ( rtS , 3 )
; if ( ssGetTNextWasAdjusted ( rtS , 3 ) ) { rtDW . h2l1jz22tz =
_ssGetVarNextHitTime ( rtS , 1 ) ; } if ( rtDW . lk33nb0dif != 0 ) { rtDW .
lk33nb0dif = 0 ; if ( hipf51rmyh >= rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u ) { ratio = ( hipf51rmyh - rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u ) / rtP .
PulseGenerator_Period_mwqel1dvmq ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW .
hmy2bsk3ta = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
PulseGenerator_Period_mwqel1dvmq + rtP . PulseGenerator_PhaseDelay_k0s5cgqn5u
) + rtP . AF * rtP . PulseGenerator_Period_mwqel1dvmq / 100.0 ; if (
hipf51rmyh < ratio ) { rtDW . lxjgrndv13 = 1 ; rtDW . h2l1jz22tz = ratio ; }
else { rtDW . lxjgrndv13 = 0 ; rtDW . h2l1jz22tz = ( real_T ) ( numCycles +
1U ) * rtP . PulseGenerator_Period_mwqel1dvmq + rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u ; } } else { rtDW . hmy2bsk3ta = rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u != 0.0 ? - 1 : 0 ; rtDW . lxjgrndv13 = 0
; rtDW . h2l1jz22tz = rtP . PulseGenerator_PhaseDelay_k0s5cgqn5u ; } } else
if ( rtDW . h2l1jz22tz <= hipf51rmyh ) { if ( rtDW . lxjgrndv13 == 1 ) { rtDW
. lxjgrndv13 = 0 ; rtDW . h2l1jz22tz = ( real_T ) ( rtDW . hmy2bsk3ta + 1L )
* rtP . PulseGenerator_Period_mwqel1dvmq + rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u ; } else { rtDW . hmy2bsk3ta ++ ; rtDW .
lxjgrndv13 = 1 ; rtDW . h2l1jz22tz = ( rtP . AF * rtP .
PulseGenerator_Period_mwqel1dvmq * 0.01 + ( real_T ) rtDW . hmy2bsk3ta * rtP
. PulseGenerator_Period_mwqel1dvmq ) + rtP .
PulseGenerator_PhaseDelay_k0s5cgqn5u ; } } _ssSetVarNextHitTime ( rtS , 1 ,
rtDW . h2l1jz22tz ) ; if ( rtDW . lxjgrndv13 == 1 ) { rtB . jjz3f2w1ww = rtP
. fp3 * rtP . N_dot / rtP . TBE ; } else { rtB . jjz3f2w1ww = 0.0 ; } } rtB .
ebsdotywiy = rtP . f53 / rtP . tau5 * rtB . ebk01qyesg ; rtB . kmllksrcpg =
1.0 / rtP . T3 * rtB . psuxlzsuxz ; rtB . dlpsaa4wne = 1.0 / rtP .
tau_trap_tungsten / rtP . n_solute_tungsten * rtB . psuxlzsuxz ; rtB .
ew51x2a0pq = rtP . PM_tungsten / rtP . PM_tritium / rtP . M_tungsten * rtB .
cpkkbsqjby ; rtB . h0g0vscc5a = rtB . mwmx0yzb4f - rtB . ew51x2a0pq ; rtB .
emvjgmkgqb = rtB . dlpsaa4wne * rtB . h0g0vscc5a ; rtB . f2htpqh3ht = 1.0 /
rtP . tau_detrap_tungsten [ 0 ] * rtB . cpkkbsqjby ; rtB . nh2mkz0gux = rtB .
emvjgmkgqb - rtB . f2htpqh3ht ; rtB . mklt5qpuqz = 1.0 / rtP .
tau_trap_tungsten / rtP . n_solute_tungsten * rtB . psuxlzsuxz ; rtB .
iip1ojxipj = rtX . jslb3nmhpu ; rtB . hirm4x5pho = rtP . PM_tungsten / rtP .
PM_tritium / rtP . M_tungsten * rtB . mrg2inxnui ; rtB . h0nudpvspr = rtB .
iip1ojxipj - rtB . hirm4x5pho ; rtB . jofuuncwgf = rtB . mklt5qpuqz * rtB .
h0nudpvspr ; rtB . mfsnnr03g3 = 1.0 / rtP . tau_detrap_tungsten [ 1 ] * rtB .
mrg2inxnui ; rtB . ax2athfpkk = rtB . jofuuncwgf - rtB . mfsnnr03g3 ; rtB .
hyj42o3iuz = 1.0 / rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB .
psuxlzsuxz ; rtB . kkb5zwrqmi = rtX . nc0rcorjsb ; rtB . ehw2zbw0iw = rtP .
PM_tungsten / rtP . PM_tritium / rtP . M_tungsten * rtB . ees2bp2bzh ; rtB .
jpn42chgkq = rtB . kkb5zwrqmi - rtB . ehw2zbw0iw ; rtB . bzgkngokio = rtB .
hyj42o3iuz * rtB . jpn42chgkq ; rtB . noa4ncpcn2 = 1.0 / rtP .
tau_detrap_tungsten [ 2 ] * rtB . ees2bp2bzh ; rtB . d5nn4kjojo = rtB .
bzgkngokio - rtB . noa4ncpcn2 ; rtB . h2up4wt3zu = 1.0 / rtP .
tau_trap_tungsten / rtP . n_solute_tungsten * rtB . psuxlzsuxz ; rtB .
dxfhrl5haj = rtX . aiyvnvjr41 ; rtB . k1rudquzn3 = rtP . PM_tungsten / rtP .
PM_tritium / rtP . M_tungsten * rtB . ky32tdgwev ; rtB . ntb3nynmn0 = rtB .
dxfhrl5haj - rtB . k1rudquzn3 ; rtB . ocbiqwo1jy = rtB . h2up4wt3zu * rtB .
ntb3nynmn0 ; rtB . bc0o2qz0ty = 1.0 / rtP . tau_detrap_tungsten [ 3 ] * rtB .
ky32tdgwev ; rtB . koz3fa4yyj = rtB . ocbiqwo1jy - rtB . bc0o2qz0ty ; rtB .
eja2c4jp5c = 1.0 / rtP . tau_trap_tungsten / rtP . n_solute_tungsten * rtB .
psuxlzsuxz ; rtB . cidmzevvxk = rtX . jgw5jvtnel ; rtB . guydscbpbh = rtP .
PM_tungsten / rtP . PM_tritium / rtP . M_tungsten * rtB . l1mbg2lxtf ; rtB .
dktkpw1bhi = rtB . cidmzevvxk - rtB . guydscbpbh ; rtB . kgob5xrqph = rtB .
eja2c4jp5c * rtB . dktkpw1bhi ; rtB . fkha0sace3 = 1.0 / rtP .
tau_detrap_tungsten [ 4 ] * rtB . l1mbg2lxtf ; rtB . jivx3sbmm4 = rtB .
kgob5xrqph - rtB . fkha0sace3 ; rtB . ftazg5c0fu = ( ( ( rtB . nh2mkz0gux +
rtB . ax2athfpkk ) + rtB . d5nn4kjojo ) + rtB . koz3fa4yyj ) + rtB .
jivx3sbmm4 ; rtB . mzhqvdifiz = ( ( rtB . jjz3f2w1ww + rtB . ebsdotywiy ) -
rtB . kmllksrcpg ) - rtB . ftazg5c0fu ; rtB . edivwoqmoy = 1.0 / rtP .
n_tungsten_max [ 1 ] * rtB . kkb5zwrqmi ; rtB . fd5fpby1xt = rtB . cy3t3xxpoy
* rtB . edivwoqmoy ; rtB . ochdwrnmss = rtB . kkb5zwrqmi * rtB . ogv1c0tddw ;
rtB . dzeqvdtusv = ( rtB . cy3t3xxpoy - rtB . fd5fpby1xt ) - rtB . ochdwrnmss
; rtB . cpbzlxsa4z = 1.0 / rtP . n_tungsten_max [ 2 ] * rtB . dxfhrl5haj ;
rtB . pn0u52zpkg = rtB . dxel3zbjrm * rtB . cpbzlxsa4z ; rtB . kk4oglgrgt =
rtB . dxfhrl5haj * rtB . a3i0ozq14p ; rtB . d3fgwuvnry = ( rtB . dxel3zbjrm -
rtB . pn0u52zpkg ) - rtB . kk4oglgrgt ; rtB . kwpcxbpmca = 1.0 / rtP .
n_tungsten_max [ 3 ] * rtB . cidmzevvxk ; rtB . cu0edalrlz = rtB . cmf1wo0hiz
* rtB . kwpcxbpmca ; rtB . eycob2wxh3 = rtB . cidmzevvxk * rtB . opybz520jx ;
rtB . exrud042ox = ( rtB . cmf1wo0hiz - rtB . cu0edalrlz ) - rtB . eycob2wxh3
; rtB . bzj35bjr4u = 1.0 / rtP . n_tungsten_max [ 0 ] * rtB . iip1ojxipj ;
rtB . dna4jmsata = rtB . h1j1ahvfhl * rtB . bzj35bjr4u ; rtB . gnyiwna5cn =
rtB . iip1ojxipj * rtB . jsvjvkl4fq ; rtB . eu0tusin0r = ( rtB . h1j1ahvfhl -
rtB . dna4jmsata ) - rtB . gnyiwna5cn ; rtB . oyn54nojeb = ( 1.0 - rtP . eta2
) / rtP . tau2 * rtB . fvf3nbzioe ; rtB . efehig0u42 = 1.0 / rtP . T5 * rtB .
ebk01qyesg ; rtB . btsm5i54nc = rtB . oyn54nojeb - rtB . efehig0u42 ; rtB .
mrdniw23zs = 1.0 / rtP . tau8 * rtB . iajp4d0mcl ; rtB . bg3da3n0wb = 1.0 /
rtP . tau6 * rtB . eqaeyezh1s ; rtB . k0hgu4xe0f = 1.0 / rtP . T9 * rtB .
idcpjxrtqy ; rtB . d1yia3o3xe = ( rtB . mrdniw23zs + rtB . bg3da3n0wb ) - rtB
. k0hgu4xe0f ; rtB . hepvlmbt4i = 1.0 / rtP . tau1 * rtB . nf4zcvrrw1 ; rtB .
hbyxmtmphz = 1.0 / rtP . T2 * rtB . fvf3nbzioe ; rtB . pnzergluua = rtB .
hepvlmbt4i - rtB . hbyxmtmphz ; rtB . knfus34vwq = 1.0 / rtP .
tau_trap_structural / rtP . n_solute_structural * rtB . nf4zcvrrw1 ; rtB .
pmgkqaam2i = muDoubleScalarMod ( ssGetT ( rtS ) , rtP . T_replacement ) ; if
( ssIsModeUpdateTimeStep ( rtS ) ) { zcEvent = rt_ZCFcn (
FALLING_ZERO_CROSSING , & rtPrevZCX . padts4xd31 , ( rtB . pmgkqaam2i ) ) ;
if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX . jlkgfmapfz != rtP .
Integrator1_IC_caj4cloteg ) ; rtX . jlkgfmapfz = rtP .
Integrator1_IC_caj4cloteg ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . lwmqjnrld0 =
rtX . jlkgfmapfz ; } else { rtB . lwmqjnrld0 = rtX . jlkgfmapfz ; } rtB .
jc55rsew1w = rtP . PM_structural / rtP . PM_tritium / rtP . M_structural *
rtB . lwmqjnrld0 ; rtB . k5203dxgbx = rtB . ae20paxfcr - rtB . jc55rsew1w ;
rtB . nj0umut5gp = rtB . knfus34vwq * rtB . k5203dxgbx ; rtB . fo1qcnd3al =
1.0 / rtP . tau_detrap_structural * rtB . lwmqjnrld0 ; rtB . i5zgf04o3x = rtB
. nj0umut5gp - rtB . fo1qcnd3al ; rtB . d04wog3ps1 = 1.0 / rtP .
tau_trap_structural / rtP . n_solute_structural * rtB . nf4zcvrrw1 ; rtB .
grykhheeys = rtX . mm0isfzekn ; rtB . krfvi4cflh = muDoubleScalarMod ( ssGetT
( rtS ) , rtP . T_replacement ) ; if ( ssIsModeUpdateTimeStep ( rtS ) ) {
zcEvent = rt_ZCFcn ( FALLING_ZERO_CROSSING , & rtPrevZCX . edscqmn54a , ( rtB
. krfvi4cflh ) ) ; if ( zcEvent != NO_ZCEVENT ) { xHasBeenChanged = ( rtX .
h121gcp0ue != rtP . Integrator1_IC_m4ot5s3dkq ) ; rtX . h121gcp0ue = rtP .
Integrator1_IC_m4ot5s3dkq ; if ( xHasBeenChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } rtB . gqgfxwccv4 =
rtX . h121gcp0ue ; } else { rtB . gqgfxwccv4 = rtX . h121gcp0ue ; } rtB .
lel3phg0r1 = rtP . PM_structural / rtP . PM_tritium / rtP . M_structural *
rtB . gqgfxwccv4 ; rtB . jsspycell1 = rtB . grykhheeys - rtB . lel3phg0r1 ;
rtB . pfdj2j3kbo = rtB . d04wog3ps1 * rtB . jsspycell1 ; rtB . ateto3w1pm =
1.0 / rtP . tau_detrap_tungsten [ 2 ] * rtB . gqgfxwccv4 ; rtB . mb335ejyey =
rtB . pfdj2j3kbo - rtB . ateto3w1pm ; rtB . lteedkhhy3 = rtB . i5zgf04o3x +
rtB . mb335ejyey ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { hipf51rmyh =
ssGetTaskTime ( rtS , 2 ) ; if ( ssGetTNextWasAdjusted ( rtS , 2 ) ) { rtDW .
pqedya33bp = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . basopanm0u != 0
) { rtDW . basopanm0u = 0 ; if ( hipf51rmyh >= rtP .
PulseGenerator_PhaseDelay_emic4rw15d ) { ratio = ( hipf51rmyh - rtP .
PulseGenerator_PhaseDelay_emic4rw15d ) / rtP .
PulseGenerator_Period_mpnlrkwdty ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW .
lhoaby1ffk = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
PulseGenerator_Period_mpnlrkwdty + rtP . PulseGenerator_PhaseDelay_emic4rw15d
) + rtP . AF * rtP . PulseGenerator_Period_mpnlrkwdty / 100.0 ; if (
hipf51rmyh < ratio ) { rtDW . gdlhm5czey = 1 ; rtDW . pqedya33bp = ratio ; }
else { rtDW . gdlhm5czey = 0 ; rtDW . pqedya33bp = ( real_T ) ( numCycles +
1U ) * rtP . PulseGenerator_Period_mpnlrkwdty + rtP .
PulseGenerator_PhaseDelay_emic4rw15d ; } } else { rtDW . lhoaby1ffk = rtP .
PulseGenerator_PhaseDelay_emic4rw15d != 0.0 ? - 1 : 0 ; rtDW . gdlhm5czey = 0
; rtDW . pqedya33bp = rtP . PulseGenerator_PhaseDelay_emic4rw15d ; } } else
if ( rtDW . pqedya33bp <= hipf51rmyh ) { if ( rtDW . gdlhm5czey == 1 ) { rtDW
. gdlhm5czey = 0 ; rtDW . pqedya33bp = ( real_T ) ( rtDW . lhoaby1ffk + 1L )
* rtP . PulseGenerator_Period_mpnlrkwdty + rtP .
PulseGenerator_PhaseDelay_emic4rw15d ; } else { rtDW . lhoaby1ffk ++ ; rtDW .
gdlhm5czey = 1 ; rtDW . pqedya33bp = ( rtP . AF * rtP .
PulseGenerator_Period_mpnlrkwdty * 0.01 + ( real_T ) rtDW . lhoaby1ffk * rtP
. PulseGenerator_Period_mpnlrkwdty ) + rtP .
PulseGenerator_PhaseDelay_emic4rw15d ; } } _ssSetVarNextHitTime ( rtS , 0 ,
rtDW . pqedya33bp ) ; if ( rtDW . gdlhm5czey == 1 ) { rtB . oa1gustxiq = rtP
. N_dot * rtP . TBR ; } else { rtB . oa1gustxiq = 0.0 ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . lumyjs23ja . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . lumyjs23ja . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . oa1gustxiq + 0 ) ; } } }
hipf51rmyh = rtB . lwmqjnrld0 + rtB . gqgfxwccv4 ; { if ( rtDW . bk4jfotvgv .
AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . bk4jfotvgv .
AQHandles , ssGetTaskTime ( rtS , 0 ) , ( char * ) & hipf51rmyh + 0 ) ; } }
rtB . fruoe5r5t3 = 1.0 / rtP . T1 * rtB . nf4zcvrrw1 ; rtB . ixcgdfbffk = rtP
. f51 / rtP . tau5 * rtB . ebk01qyesg ; rtB . jzmkioa5k1 = 1.0 / rtP . tau3 *
rtB . psuxlzsuxz ; rtB . miby44ssmo = 1.0 / rtP . tau4 * rtB . etvkdwnkpj ;
rtB . dozduzanyp = ( ( ( ( rtB . ixcgdfbffk - rtB . fruoe5r5t3 ) + rtB .
oa1gustxiq ) + rtB . jzmkioa5k1 ) + rtB . miby44ssmo ) - rtB . lteedkhhy3 ;
rtB . cetoh1esws = 1.0 / rtP . trap_density_n_max * rtB . grykhheeys ; rtB .
ffp2uq1eay = rtB . n4io0wcopq * rtB . cetoh1esws ; rtB . kyfaz2mb1x = rtB .
grykhheeys * rtB . iayqmj4rue ; rtB . ku24anqdmm = ( rtB . n4io0wcopq - rtB .
ffp2uq1eay ) - rtB . kyfaz2mb1x ; rtB . ozrmr5adg2 = rtP . f56 / rtP . tau5 *
rtB . ebk01qyesg ; rtB . iqsukc15fj = rtP . f96 / rtP . tau9 * rtB .
idcpjxrtqy ; rtB . kl5lj4yyqc = 1.0 / rtP . T6 * rtB . eqaeyezh1s ; rtB .
ghlblpxsfm = ( rtB . ozrmr5adg2 + rtB . iqsukc15fj ) - rtB . kl5lj4yyqc ; rtB
. ennagfiv25 = ( 1.0 - rtP . f_dir ) / rtP . tau7 * rtB . k4b4lf14vj ; rtB .
cj00le33zn = 1.0 / rtP . T8 * rtB . iajp4d0mcl ; rtB . dj24yjdkk0 = rtB .
ennagfiv25 - rtB . cj00le33zn ; rtB . enuxhkywvm = rtP . eta2 / rtP . tau2 *
rtB . fvf3nbzioe ; rtB . gvsnodzuaj = 1.0 / rtP . T12 * rtB . osbfg4zlct ;
rtB . ki5rpihgmh = rtB . enuxhkywvm - rtB . gvsnodzuaj ; rtB . fs1oeicixp =
rtP . f_dir / rtP . tau7 * rtB . k4b4lf14vj ; rtB . cszo5vy5h3 = ( 1.0 - rtP
. f96 ) / rtP . tau9 * rtB . idcpjxrtqy ; rtB . cqrhrhc1sq = 1.0 / rtP .
tau12 * rtB . osbfg4zlct ; if ( ssIsSampleHit ( rtS , 6 , 0 ) ) { hipf51rmyh
= ssGetTaskTime ( rtS , 6 ) ; if ( ssGetTNextWasAdjusted ( rtS , 6 ) ) { rtDW
. dmxo1ux3qp = _ssGetVarNextHitTime ( rtS , 4 ) ; } if ( rtDW . az3nbubu5p !=
0 ) { rtDW . az3nbubu5p = 0 ; if ( hipf51rmyh >= rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs ) { ratio = ( hipf51rmyh - rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs ) / rtP .
PulseGenerator_Period_d0fefccnsl ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW .
c5wtluimqm = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
PulseGenerator_Period_d0fefccnsl + rtP . PulseGenerator_PhaseDelay_dcsuc5mmvs
) + rtP . AF * rtP . PulseGenerator_Period_d0fefccnsl / 100.0 ; if (
hipf51rmyh < ratio ) { rtDW . faseuqsse1 = 1 ; rtDW . dmxo1ux3qp = ratio ; }
else { rtDW . faseuqsse1 = 0 ; rtDW . dmxo1ux3qp = ( real_T ) ( numCycles +
1U ) * rtP . PulseGenerator_Period_d0fefccnsl + rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs ; } } else { rtDW . c5wtluimqm = rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs != 0.0 ? - 1 : 0 ; rtDW . faseuqsse1 = 0
; rtDW . dmxo1ux3qp = rtP . PulseGenerator_PhaseDelay_dcsuc5mmvs ; } } else
if ( rtDW . dmxo1ux3qp <= hipf51rmyh ) { if ( rtDW . faseuqsse1 == 1 ) { rtDW
. faseuqsse1 = 0 ; rtDW . dmxo1ux3qp = ( real_T ) ( rtDW . c5wtluimqm + 1L )
* rtP . PulseGenerator_Period_d0fefccnsl + rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs ; } else { rtDW . c5wtluimqm ++ ; rtDW .
faseuqsse1 = 1 ; rtDW . dmxo1ux3qp = ( rtP . AF * rtP .
PulseGenerator_Period_d0fefccnsl * 0.01 + ( real_T ) rtDW . c5wtluimqm * rtP
. PulseGenerator_Period_d0fefccnsl ) + rtP .
PulseGenerator_PhaseDelay_dcsuc5mmvs ; } } _ssSetVarNextHitTime ( rtS , 4 ,
rtDW . dmxo1ux3qp ) ; if ( rtDW . faseuqsse1 == 1 ) { rtB . je4cbmtlt4 = rtP
. N_dot / rtP . TBE ; } else { rtB . je4cbmtlt4 = 0.0 ; } } rtB . brlwqytyds
= rtP . lambda * rtB . iiiwxuggrg ; rtB . mhjkxa1meq = ( ( ( rtB . fs1oeicixp
+ rtB . cszo5vy5h3 ) + rtB . cqrhrhc1sq ) - rtB . je4cbmtlt4 ) - rtB .
brlwqytyds ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . l0q4q2mauq
. AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . l0q4q2mauq
. AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . mhjkxa1meq + 0 )
; } } { if ( rtDW . expqsi0g3r . AQHandles && ssGetLogOutput ( rtS ) ) {
sdiWriteSignal ( rtDW . expqsi0g3r . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( char * ) & rtB . je4cbmtlt4 + 0 ) ; } } } if ( ssIsSampleHit ( rtS , 5 , 0
) ) { hipf51rmyh = ssGetTaskTime ( rtS , 5 ) ; if ( ssGetTNextWasAdjusted (
rtS , 5 ) ) { rtDW . ffcbwyd3ut = _ssGetVarNextHitTime ( rtS , 3 ) ; } if (
rtDW . hyxofhb30f != 0 ) { rtDW . hyxofhb30f = 0 ; if ( hipf51rmyh >= rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 ) { ratio = ( hipf51rmyh - rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 ) / rtP .
PulseGenerator_Period_f2wfzoa3qm ; numCycles = ( uint32_T )
muDoubleScalarFloor ( ratio ) ; if ( muDoubleScalarAbs ( ( real_T ) (
numCycles + 1U ) - ratio ) < DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW .
olc1lgjia0 = numCycles ; ratio = ( ( real_T ) numCycles * rtP .
PulseGenerator_Period_f2wfzoa3qm + rtP . PulseGenerator_PhaseDelay_oegmxwaov1
) + rtP . AF * rtP . PulseGenerator_Period_f2wfzoa3qm / 100.0 ; if (
hipf51rmyh < ratio ) { rtDW . b0palefbsp = 1 ; rtDW . ffcbwyd3ut = ratio ; }
else { rtDW . b0palefbsp = 0 ; rtDW . ffcbwyd3ut = ( real_T ) ( numCycles +
1U ) * rtP . PulseGenerator_Period_f2wfzoa3qm + rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 ; } } else { rtDW . olc1lgjia0 = rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 != 0.0 ? - 1 : 0 ; rtDW . b0palefbsp = 0
; rtDW . ffcbwyd3ut = rtP . PulseGenerator_PhaseDelay_oegmxwaov1 ; } } else
if ( rtDW . ffcbwyd3ut <= hipf51rmyh ) { if ( rtDW . b0palefbsp == 1 ) { rtDW
. b0palefbsp = 0 ; rtDW . ffcbwyd3ut = ( real_T ) ( rtDW . olc1lgjia0 + 1L )
* rtP . PulseGenerator_Period_f2wfzoa3qm + rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 ; } else { rtDW . olc1lgjia0 ++ ; rtDW .
b0palefbsp = 1 ; rtDW . ffcbwyd3ut = ( rtP . AF * rtP .
PulseGenerator_Period_f2wfzoa3qm * 0.01 + ( real_T ) rtDW . olc1lgjia0 * rtP
. PulseGenerator_Period_f2wfzoa3qm ) + rtP .
PulseGenerator_PhaseDelay_oegmxwaov1 ; } } _ssSetVarNextHitTime ( rtS , 3 ,
rtDW . ffcbwyd3ut ) ; if ( rtDW . b0palefbsp == 1 ) { rtB . ooku50enka = ( (
( 1.0 - rtP . TBE ) - rtP . fp3 ) - rtP . fp4 ) * rtP . N_dot / rtP . TBE ; }
else { rtB . ooku50enka = 0.0 ; } } rtB . iirvitebr2 = 1.0 / rtP . T7 * rtB .
k4b4lf14vj ; rtB . ki4tl0rbga = rtB . ooku50enka - rtB . iirvitebr2 ;
UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID7 ( int_T tid ) { rtB .
lgyyr12kek = rtP . n_trap_tungsten_intrinsic ; rtB . ohvaeydtca =
muDoubleScalarExp ( - 1.0 / ( rtP . k_B * rtP . T_tungsten ) * rtP .
E_annealing ) * rtP . A_0 ; rtB . fkwpmfy3ic = rtP . damage_rate * rtP .
trap_creation_factor_W [ 1 ] ; rtB . ojyufdjynv = muDoubleScalarExp ( - 1.0 /
( rtP . k_B * rtP . T_tungsten ) * rtP . E_annealing ) * rtP . A_0 ; rtB .
bmkrxgfo2l = rtP . damage_rate * rtP . trap_creation_factor_W [ 2 ] ; rtB .
m2fionkrn0 = muDoubleScalarExp ( - 1.0 / ( rtP . k_B * rtP . T_tungsten ) *
rtP . E_annealing ) * rtP . A_0 ; rtB . gcmv4lfn4n = rtP . damage_rate * rtP
. trap_creation_factor_W [ 3 ] ; rtB . kdkynqxxwq = muDoubleScalarExp ( - 1.0
/ ( rtP . k_B * rtP . T_tungsten ) * rtP . E_annealing ) * rtP . A_0 ; rtB .
fgkaot3e42 = rtP . damage_rate * rtP . trap_creation_factor_W [ 0 ] ; rtB .
mwmx0yzb4f = rtP . n_trap_tungsten_intrinsic ; rtB . ogv1c0tddw =
muDoubleScalarExp ( - 1.0 / ( rtP . k_B * rtP . T_tungsten ) * rtP .
E_annealing ) * rtP . A_0 ; rtB . cy3t3xxpoy = rtP . damage_rate * rtP .
trap_creation_factor_W [ 1 ] ; rtB . a3i0ozq14p = muDoubleScalarExp ( - 1.0 /
( rtP . k_B * rtP . T_tungsten ) * rtP . E_annealing ) * rtP . A_0 ; rtB .
dxel3zbjrm = rtP . damage_rate * rtP . trap_creation_factor_W [ 2 ] ; rtB .
opybz520jx = muDoubleScalarExp ( - 1.0 / ( rtP . k_B * rtP . T_tungsten ) *
rtP . E_annealing ) * rtP . A_0 ; rtB . cmf1wo0hiz = rtP . damage_rate * rtP
. trap_creation_factor_W [ 3 ] ; rtB . jsvjvkl4fq = muDoubleScalarExp ( - 1.0
/ ( rtP . k_B * rtP . T_tungsten ) * rtP . E_annealing ) * rtP . A_0 ; rtB .
h1j1ahvfhl = rtP . damage_rate * rtP . trap_creation_factor_W [ 0 ] ; rtB .
ae20paxfcr = rtP . n_trap_structural ; rtB . iayqmj4rue = muDoubleScalarExp (
- 1.0 / ( rtP . k_B * rtP . trap_density_T_material ) * rtP .
trap_density_E_annealing ) * rtP . trap_density_A_0 ; rtB . n4io0wcopq =
1.0E+28 / rtP . n_tungsten * rtP . trap_density_damage_rate ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER
( tid ) ; } void MdlUpdateTID7 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
void MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * )
ssGetdX ( rtS ) ) ; _rtXdot -> htgrh0jjqu = rtB . mhjkxa1meq ; _rtXdot ->
co1jdeau2v = rtB . dozduzanyp ; _rtXdot -> lvqzai4v0g = rtB . pnzergluua ;
_rtXdot -> mnxe4thxfk = rtB . ki4tl0rbga ; _rtXdot -> mnuyjgz25d = rtB .
mg2xxgovdn ; _rtXdot -> czr1kbthty = rtB . mzhqvdifiz ; _rtXdot -> dh4mqtfbta
= rtB . btsm5i54nc ; _rtXdot -> eopdaaoigp = rtB . d1yia3o3xe ; _rtXdot ->
is4kh5d04r = rtB . dj24yjdkk0 ; _rtXdot -> i2yisk5ira = rtB . ki5rpihgmh ;
_rtXdot -> dq5vg1pwin = rtB . ghlblpxsfm ; _rtXdot -> ivth0fq3lc = rtB .
dzzfskofco ; _rtXdot -> prie45bad0 = rtB . o3mlawuzsu ; _rtXdot -> l2buheggo3
= rtB . f4qjawxtxc ; _rtXdot -> bz1y1deorv = rtB . dqaeumpfwq ; _rtXdot ->
cjaogzvsz3 = rtB . lv3saiokkc ; _rtXdot -> gscw5qlois = rtB . jjs4ssptlk ;
_rtXdot -> n4ml13agdg = rtB . clohbn4dfr ; _rtXdot -> lfdbokqx32 = rtB .
p2krjfpfgh ; _rtXdot -> e330kkmdyz = rtB . mtsxpijwck ; _rtXdot -> cmqztgmaxh
= rtB . nh2mkz0gux ; _rtXdot -> j4fspsirju = rtB . ax2athfpkk ; _rtXdot ->
pd0yv0rpqx = rtB . d5nn4kjojo ; _rtXdot -> n00f3b3n5z = rtB . koz3fa4yyj ;
_rtXdot -> ktyas5zdkb = rtB . jivx3sbmm4 ; _rtXdot -> jslb3nmhpu = rtB .
eu0tusin0r ; _rtXdot -> nc0rcorjsb = rtB . dzeqvdtusv ; _rtXdot -> aiyvnvjr41
= rtB . d3fgwuvnry ; _rtXdot -> jgw5jvtnel = rtB . exrud042ox ; _rtXdot ->
jlkgfmapfz = rtB . i5zgf04o3x ; _rtXdot -> mm0isfzekn = rtB . ku24anqdmm ;
_rtXdot -> h121gcp0ue = rtB . mb335ejyey ; } void MdlProjection ( void ) { }
void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> gz3rqrrgks = rtB .
csnrgnegvo ; _rtZCSV -> cmsfzg0lyf = rtB . eqm2qb1xmg ; _rtZCSV -> fmvr4gqqkf
= rtB . hpv03qx2eh ; _rtZCSV -> gclmbx3vit = rtB . oee1351fty ; _rtZCSV ->
pchkpwpesn = rtB . gti1d5wxoc ; _rtZCSV -> lzqnw1gobb = rtB . mug54mzksq ;
_rtZCSV -> cuf22dtmzc = rtB . h1pesm521l ; _rtZCSV -> ihyj2mi3kc = rtB .
f3bngaj4zp ; _rtZCSV -> cfwzwblkvz = rtB . m34nqp4n5z ; _rtZCSV -> eirfm23vmw
= rtB . icsnarysuk ; _rtZCSV -> errnkrpops = rtB . pmgkqaam2i ; _rtZCSV ->
mte15kt3pl = rtB . krfvi4cflh ; } void MdlTerminate ( void ) { { if ( rtDW .
bpvydpjffg . AQHandles ) { sdiTerminateStreaming ( & rtDW . bpvydpjffg .
AQHandles ) ; } } { if ( rtDW . bfgk1czl4m . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bfgk1czl4m . AQHandles ) ; } } { if ( rtDW .
ja1ege25yh . AQHandles ) { sdiTerminateStreaming ( & rtDW . ja1ege25yh .
AQHandles ) ; } } { if ( rtDW . dn0qqupwms . AQHandles ) {
sdiTerminateStreaming ( & rtDW . dn0qqupwms . AQHandles ) ; } } { if ( rtDW .
in2jxpqlzw . AQHandles ) { sdiTerminateStreaming ( & rtDW . in2jxpqlzw .
AQHandles ) ; } } { if ( rtDW . phht5zmf24 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . phht5zmf24 . AQHandles ) ; } } { if ( rtDW .
g1upx2ora0 . AQHandles ) { sdiTerminateStreaming ( & rtDW . g1upx2ora0 .
AQHandles ) ; } } { if ( rtDW . gb53i5u3uk . AQHandles ) {
sdiTerminateStreaming ( & rtDW . gb53i5u3uk . AQHandles ) ; } } { if ( rtDW .
e0iok5rpsx . AQHandles ) { sdiTerminateStreaming ( & rtDW . e0iok5rpsx .
AQHandles ) ; } } { if ( rtDW . bvdj0li5qv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bvdj0li5qv . AQHandles ) ; } } { if ( rtDW .
ohawovjfhh . AQHandles ) { sdiTerminateStreaming ( & rtDW . ohawovjfhh .
AQHandles ) ; } } { if ( rtDW . ofgcg2rwnf . AQHandles ) {
sdiTerminateStreaming ( & rtDW . ofgcg2rwnf . AQHandles ) ; } } { if ( rtDW .
lxy40zsik3 . AQHandles ) { sdiTerminateStreaming ( & rtDW . lxy40zsik3 .
AQHandles ) ; } } { if ( rtDW . lr5q5utmxh . AQHandles ) {
sdiTerminateStreaming ( & rtDW . lr5q5utmxh . AQHandles ) ; } } { if ( rtDW .
ojaixcrugo . AQHandles ) { sdiTerminateStreaming ( & rtDW . ojaixcrugo .
AQHandles ) ; } } { if ( rtDW . jhnokpp1dp . AQHandles ) {
sdiTerminateStreaming ( & rtDW . jhnokpp1dp . AQHandles ) ; } } { if ( rtDW .
iohckarwzg . AQHandles ) { sdiTerminateStreaming ( & rtDW . iohckarwzg .
AQHandles ) ; } } { if ( rtDW . je2kiqe4dx . AQHandles ) {
sdiTerminateStreaming ( & rtDW . je2kiqe4dx . AQHandles ) ; } } { if ( rtDW .
njvgyvffo2 . AQHandles ) { sdiTerminateStreaming ( & rtDW . njvgyvffo2 .
AQHandles ) ; } } { if ( rtDW . diar2azokk . AQHandles ) {
sdiTerminateStreaming ( & rtDW . diar2azokk . AQHandles ) ; } } { if ( rtDW .
a0s45dbdod . AQHandles ) { sdiTerminateStreaming ( & rtDW . a0s45dbdod .
AQHandles ) ; } } { if ( rtDW . n2tu4152xd . AQHandles ) {
sdiTerminateStreaming ( & rtDW . n2tu4152xd . AQHandles ) ; } } { if ( rtDW .
favhxcmqok . AQHandles ) { sdiTerminateStreaming ( & rtDW . favhxcmqok .
AQHandles ) ; } } { if ( rtDW . bni3utz05a . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bni3utz05a . AQHandles ) ; } } { if ( rtDW .
lumyjs23ja . AQHandles ) { sdiTerminateStreaming ( & rtDW . lumyjs23ja .
AQHandles ) ; } } { if ( rtDW . bk4jfotvgv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bk4jfotvgv . AQHandles ) ; } } { if ( rtDW .
l0q4q2mauq . AQHandles ) { sdiTerminateStreaming ( & rtDW . l0q4q2mauq .
AQHandles ) ; } } { if ( rtDW . expqsi0g3r . AQHandles ) {
sdiTerminateStreaming ( & rtDW . expqsi0g3r . AQHandles ) ; } } } static void
mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) ; static void
mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray ( mxArray * destArray ,
mwIndex i , int j , const void * srcData , size_t numBytes ) { mxArray *
newArray = mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes ,
mxUINT8_CLASS , mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , (
const uint8_T * ) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i ,
j , newArray ) ; } static void
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) {
memcpy ( ( uint8_T * ) destData , ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) , numBytes ) ; } static void
mr_fuelCycle_w_trapping_multilevel_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_fuelCycle_w_trapping_multilevel_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) { mxSetFieldByNumber (
destArray , i , j , mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static
uint_T mr_fuelCycle_w_trapping_multilevel_extractBitFieldFromMxArray ( const
mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_fuelCycle_w_trapping_multilevel_extractBitFieldFromMxArray ( const mxArray
* srcArray , mwIndex i , int j , uint_T numBits ) { const uint_T varVal = (
uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return
varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_fuelCycle_w_trapping_multilevel_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) ; static void
mr_fuelCycle_w_trapping_multilevel_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) ; static void
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArrayWithOffset ( void *
destData , const mxArray * srcArray , mwIndex i , int j , mwIndex offset ,
size_t numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_fuelCycle_w_trapping_multilevel_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
; static void
mr_fuelCycle_w_trapping_multilevel_cacheBitFieldToCellArrayWithOffset (
mxArray * destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal )
{ mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_fuelCycle_w_trapping_multilevel_extractBitFieldFromCellArrayWithOffset (
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) ; static uint_T
mr_fuelCycle_w_trapping_multilevel_extractBitFieldFromCellArrayWithOffset (
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T
numBits ) { const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray *
mr_fuelCycle_w_trapping_multilevel_GetDWork ( ) { static const char_T *
ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "rtPrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray ( ssDW , 0 , 0 , (
const void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char_T *
rtdwDataFieldNames [ 20 ] = { "rtDW.jbfemjfqdu" , "rtDW.h2l1jz22tz" ,
"rtDW.pqedya33bp" , "rtDW.dmxo1ux3qp" , "rtDW.ffcbwyd3ut" , "rtDW.b0dld00fnu"
, "rtDW.hmy2bsk3ta" , "rtDW.lhoaby1ffk" , "rtDW.c5wtluimqm" ,
"rtDW.olc1lgjia0" , "rtDW.gjpvvsicgx" , "rtDW.ivnf1ct5mk" , "rtDW.lk33nb0dif"
, "rtDW.lxjgrndv13" , "rtDW.basopanm0u" , "rtDW.gdlhm5czey" ,
"rtDW.az3nbubu5p" , "rtDW.faseuqsse1" , "rtDW.hyxofhb30f" , "rtDW.b0palefbsp"
, } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 20 ,
rtdwDataFieldNames ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray
( rtdwData , 0 , 0 , ( const void * ) & ( rtDW . jbfemjfqdu ) , sizeof ( rtDW
. jbfemjfqdu ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . h2l1jz22tz ) , sizeof ( rtDW .
h2l1jz22tz ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 2 , ( const void * ) & ( rtDW . pqedya33bp ) , sizeof ( rtDW .
pqedya33bp ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 3 , ( const void * ) & ( rtDW . dmxo1ux3qp ) , sizeof ( rtDW .
dmxo1ux3qp ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 4 , ( const void * ) & ( rtDW . ffcbwyd3ut ) , sizeof ( rtDW .
ffcbwyd3ut ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 5 , ( const void * ) & ( rtDW . b0dld00fnu ) , sizeof ( rtDW .
b0dld00fnu ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 6 , ( const void * ) & ( rtDW . hmy2bsk3ta ) , sizeof ( rtDW .
hmy2bsk3ta ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 7 , ( const void * ) & ( rtDW . lhoaby1ffk ) , sizeof ( rtDW .
lhoaby1ffk ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 8 , ( const void * ) & ( rtDW . c5wtluimqm ) , sizeof ( rtDW .
c5wtluimqm ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 9 , ( const void * ) & ( rtDW . olc1lgjia0 ) , sizeof ( rtDW .
olc1lgjia0 ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 10 , ( const void * ) & ( rtDW . gjpvvsicgx ) , sizeof ( rtDW
. gjpvvsicgx ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 11 , ( const void * ) & ( rtDW . ivnf1ct5mk ) , sizeof ( rtDW
. ivnf1ct5mk ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 12 , ( const void * ) & ( rtDW . lk33nb0dif ) , sizeof ( rtDW
. lk33nb0dif ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 13 , ( const void * ) & ( rtDW . lxjgrndv13 ) , sizeof ( rtDW
. lxjgrndv13 ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 14 , ( const void * ) & ( rtDW . basopanm0u ) , sizeof ( rtDW
. basopanm0u ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 15 , ( const void * ) & ( rtDW . gdlhm5czey ) , sizeof ( rtDW
. gdlhm5czey ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 16 , ( const void * ) & ( rtDW . az3nbubu5p ) , sizeof ( rtDW
. az3nbubu5p ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 17 , ( const void * ) & ( rtDW . faseuqsse1 ) , sizeof ( rtDW
. faseuqsse1 ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 18 , ( const void * ) & ( rtDW . hyxofhb30f ) , sizeof ( rtDW
. hyxofhb30f ) ) ; mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray (
rtdwData , 0 , 19 , ( const void * ) & ( rtDW . b0palefbsp ) , sizeof ( rtDW
. b0palefbsp ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; }
mr_fuelCycle_w_trapping_multilevel_cacheDataAsMxArray ( ssDW , 0 , 2 , (
const void * ) & ( rtPrevZCX ) , sizeof ( rtPrevZCX ) ) ; return ssDW ; }
void mr_fuelCycle_w_trapping_multilevel_SetDWork ( const mxArray * ssDW ) { (
void ) ssDW ; mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( (
void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray *
rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . jbfemjfqdu ) , rtdwData , 0 , 0 , sizeof ( rtDW . jbfemjfqdu ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . h2l1jz22tz ) , rtdwData , 0 , 1 , sizeof ( rtDW . h2l1jz22tz ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . pqedya33bp ) , rtdwData , 0 , 2 , sizeof ( rtDW . pqedya33bp ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . dmxo1ux3qp ) , rtdwData , 0 , 3 , sizeof ( rtDW . dmxo1ux3qp ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . ffcbwyd3ut ) , rtdwData , 0 , 4 , sizeof ( rtDW . ffcbwyd3ut ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . b0dld00fnu ) , rtdwData , 0 , 5 , sizeof ( rtDW . b0dld00fnu ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . hmy2bsk3ta ) , rtdwData , 0 , 6 , sizeof ( rtDW . hmy2bsk3ta ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . lhoaby1ffk ) , rtdwData , 0 , 7 , sizeof ( rtDW . lhoaby1ffk ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . c5wtluimqm ) , rtdwData , 0 , 8 , sizeof ( rtDW . c5wtluimqm ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . olc1lgjia0 ) , rtdwData , 0 , 9 , sizeof ( rtDW . olc1lgjia0 ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . gjpvvsicgx ) , rtdwData , 0 , 10 , sizeof ( rtDW . gjpvvsicgx ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . ivnf1ct5mk ) , rtdwData , 0 , 11 , sizeof ( rtDW . ivnf1ct5mk ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . lk33nb0dif ) , rtdwData , 0 , 12 , sizeof ( rtDW . lk33nb0dif ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . lxjgrndv13 ) , rtdwData , 0 , 13 , sizeof ( rtDW . lxjgrndv13 ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . basopanm0u ) , rtdwData , 0 , 14 , sizeof ( rtDW . basopanm0u ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . gdlhm5czey ) , rtdwData , 0 , 15 , sizeof ( rtDW . gdlhm5czey ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . az3nbubu5p ) , rtdwData , 0 , 16 , sizeof ( rtDW . az3nbubu5p ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . faseuqsse1 ) , rtdwData , 0 , 17 , sizeof ( rtDW . faseuqsse1 ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . hyxofhb30f ) , rtdwData , 0 , 18 , sizeof ( rtDW . hyxofhb30f ) ) ;
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtDW . b0palefbsp ) , rtdwData , 0 , 19 , sizeof ( rtDW . b0palefbsp ) ) ; }
mr_fuelCycle_w_trapping_multilevel_restoreDataFromMxArray ( ( void * ) & (
rtPrevZCX ) , ssDW , 0 , 2 , sizeof ( rtPrevZCX ) ) ; } mxArray *
mr_fuelCycle_w_trapping_multilevel_GetSimStateDisallowedBlocks ( ) { mxArray
* data = mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; {
static const char_T * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "Scope" , } ;
static const char_T * blockPath [ 10 ] = {
"fuelCycle_w_trapping_multilevel/Scope" ,
"fuelCycle_w_trapping_multilevel/Scope1" ,
"fuelCycle_w_trapping_multilevel/Scope2" ,
"fuelCycle_w_trapping_multilevel/Scope3" ,
"fuelCycle_w_trapping_multilevel/Div/Scope4" ,
"fuelCycle_w_trapping_multilevel/Div/Scope8" ,
 "fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_ion/Trap_detrap_ml2/Scope"
,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_n1/Trap_detrap_ml2/Scope"
,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_n2/Trap_detrap_ml2/Scope"
,
 "fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_singleblock4/Trap_detrap_ml2/Scope"
, } ; static const int reason [ 10 ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 10 ; ++ ( subs [ 0 ] ) ) { subs [
1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell (
data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] =
1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
32 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 7 ) ; ssSetNumBlocks ( rtS , 342 ) ;
ssSetNumBlockIO ( rtS , 219 ) ; ssSetNumBlockParams ( rtS , 113 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , - 2.0 ) ;
ssSetSampleTime ( rtS , 3 , - 2.0 ) ; ssSetSampleTime ( rtS , 4 , - 2.0 ) ;
ssSetSampleTime ( rtS , 5 , - 2.0 ) ; ssSetSampleTime ( rtS , 6 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 1.0 ) ;
ssSetOffsetTime ( rtS , 4 , 2.0 ) ; ssSetOffsetTime ( rtS , 5 , 3.0 ) ;
ssSetOffsetTime ( rtS , 6 , 4.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1424953456U ) ; ssSetChecksumVal ( rtS , 1 ,
2663102336U ) ; ssSetChecksumVal ( rtS , 2 , 103002778U ) ; ssSetChecksumVal
( rtS , 3 , 3508950546U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
fuelCycle_w_trapping_multilevel_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"fuelCycle_w_trapping_multilevel" ) ; ssSetPath ( rtS ,
"fuelCycle_w_trapping_multilevel" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 6.3072E+7 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] =
{ 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 } ; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs
[ ] = { ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" }
; static const char_T * rt_LoggedStateBlockNames [ ] = {
"fuelCycle_w_trapping_multilevel/storage_10/Integrator" ,
"fuelCycle_w_trapping_multilevel/breedingZone_1/Integrator" ,
"fuelCycle_w_trapping_multilevel/TES/Integrator" ,
"fuelCycle_w_trapping_multilevel/vacuumPump/Integrator" ,
"fuelCycle_w_trapping_multilevel/Div/Integrator" ,
"fuelCycle_w_trapping_multilevel/FW/Integrator" ,
"fuelCycle_w_trapping_multilevel/HX/Integrator" ,
"fuelCycle_w_trapping_multilevel/ISS_9/Integrator" ,
"fuelCycle_w_trapping_multilevel/fuelCleanup/Integrator" ,
"fuelCycle_w_trapping_multilevel/membrane/Integrator" ,
"fuelCycle_w_trapping_multilevel/exhaust_DS_6/Integrator" ,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_Intrinsic/Integrator1"
,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_singleblock4/Integrator1"
, "fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_ion/Integrator1" ,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_n1/Integrator1" ,
"fuelCycle_w_trapping_multilevel/Div/Trapped_Inventory_n2/Integrator1" ,
"fuelCycle_w_trapping_multilevel/Div/trap_density3/Integrator" ,
"fuelCycle_w_trapping_multilevel/Div/trap_density/Integrator" ,
"fuelCycle_w_trapping_multilevel/Div/trap_density1/Integrator" ,
"fuelCycle_w_trapping_multilevel/Div/trap_density2/Integrator" ,
"fuelCycle_w_trapping_multilevel/FW/Trapped_Inventory_Intrinsic/Integrator1"
, "fuelCycle_w_trapping_multilevel/FW/Trapped_Inventory_ion/Integrator1" ,
"fuelCycle_w_trapping_multilevel/FW/Trapped_Inventory_n1/Integrator1" ,
"fuelCycle_w_trapping_multilevel/FW/Trapped_Inventory_n2/Integrator1" ,
"fuelCycle_w_trapping_multilevel/FW/Trapped_Inventory_singleblock4/Integrator1"
, "fuelCycle_w_trapping_multilevel/FW/trap_density3/Integrator" ,
"fuelCycle_w_trapping_multilevel/FW/trap_density/Integrator" ,
"fuelCycle_w_trapping_multilevel/FW/trap_density1/Integrator" ,
"fuelCycle_w_trapping_multilevel/FW/trap_density2/Integrator" ,
"fuelCycle_w_trapping_multilevel/breedingZone_1/Trapped_Inventory/Integrator1"
, "fuelCycle_w_trapping_multilevel/breedingZone_1/trap_density/Integrator" ,
 "fuelCycle_w_trapping_multilevel/breedingZone_1/Trapped_Inventory_n1/Integrator1"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , ""
, "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" ,
"" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" , "" } ; static
boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] =
{ { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11
, 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 ,
27 , 28 , 29 , 30 , 31 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo =
{ 32 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) ,
rt_LoggingStatePreprocessingFcnPtrs , { rt_LoggedStateLabels } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 32 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . htgrh0jjqu ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . co1jdeau2v ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . lvqzai4v0g ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . mnxe4thxfk ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . mnuyjgz25d ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . czr1kbthty ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . dh4mqtfbta ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . eopdaaoigp ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtX . is4kh5d04r ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtX . i2yisk5ira ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtX . dq5vg1pwin ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtX . ivth0fq3lc ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) & rtX . prie45bad0 ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtX . l2buheggo3 ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtX . bz1y1deorv ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) & rtX . cjaogzvsz3 ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtX . gscw5qlois ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtX . n4ml13agdg ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtX . lfdbokqx32 ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtX . e330kkmdyz ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtX . cmqztgmaxh ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtX . j4fspsirju ;
rt_LoggedStateSignalPtrs [ 22 ] = ( void * ) & rtX . pd0yv0rpqx ;
rt_LoggedStateSignalPtrs [ 23 ] = ( void * ) & rtX . n00f3b3n5z ;
rt_LoggedStateSignalPtrs [ 24 ] = ( void * ) & rtX . ktyas5zdkb ;
rt_LoggedStateSignalPtrs [ 25 ] = ( void * ) & rtX . jslb3nmhpu ;
rt_LoggedStateSignalPtrs [ 26 ] = ( void * ) & rtX . nc0rcorjsb ;
rt_LoggedStateSignalPtrs [ 27 ] = ( void * ) & rtX . aiyvnvjr41 ;
rt_LoggedStateSignalPtrs [ 28 ] = ( void * ) & rtX . jgw5jvtnel ;
rt_LoggedStateSignalPtrs [ 29 ] = ( void * ) & rtX . jlkgfmapfz ;
rt_LoggedStateSignalPtrs [ 30 ] = ( void * ) & rtX . mm0isfzekn ;
rt_LoggedStateSignalPtrs [ 31 ] = ( void * ) & rtX . h121gcp0ue ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 32 ] ;
static real_T absTol [ 32 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 32 ] = { 0U , 0U
, 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ;
static real_T contStateJacPerturbBoundMinVec [ 32 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 32 ] ; static uint8_T zcAttributes [ 12 ] =
{ ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 |
ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) ,
( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 |
ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) ,
( 0x80 | ZC_EVENT_ALL_DN ) , ( 0x80 | ZC_EVENT_ALL_DN ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 5 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . ooku50enka ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . je4cbmtlt4 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . oa1gustxiq ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . jjz3f2w1ww ) , ( NULL ) } , { 1 * sizeof ( real_T ) , (
char * ) ( & rtB . cg5lpoodm2 ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i <
32 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ] = 0 ;
contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } } ssSetSolverRelTol (
rtS , 0.01 ) ; ssSetStepSize ( rtS , 5.0E-5 ) ; ssSetMinStepSize ( rtS ,
5.0E-5 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError (
rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.26144E+6 ) ; ssSetSolverMaxOrder ( rtS
, 5 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL
) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
5 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode15s" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 1 ) ;
ssSetSolverRobustResetMethod ( rtS , 1 ) ; ssSetAbsTolVector ( rtS , absTol )
; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 12 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverZcThreshold ( rtS , 0.01 ) ; ssSetSolverMaxConsecutiveMinStep (
rtS , 100000 ) ; ssSetSolverShapePreserveControl ( rtS , 1 ) ; ssSetTNextTid
( rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 12 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 100000 ) ; }
{ ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS
, zc ) ; } { rtPrevZCX . e0m41s4pce = UNINITIALIZED_ZCSIG ; rtPrevZCX .
f1pzzmnmrz = UNINITIALIZED_ZCSIG ; rtPrevZCX . lwvvm1bu31 =
UNINITIALIZED_ZCSIG ; rtPrevZCX . mkv1qjpzdz = UNINITIALIZED_ZCSIG ;
rtPrevZCX . ezwnrlce0c = UNINITIALIZED_ZCSIG ; rtPrevZCX . ehgnzb15jz =
UNINITIALIZED_ZCSIG ; rtPrevZCX . g4kyl2al0w = UNINITIALIZED_ZCSIG ;
rtPrevZCX . kccjtmusvi = UNINITIALIZED_ZCSIG ; rtPrevZCX . lxhainymwv =
UNINITIALIZED_ZCSIG ; rtPrevZCX . dv0chgctwn = UNINITIALIZED_ZCSIG ;
rtPrevZCX . padts4xd31 = UNINITIALIZED_ZCSIG ; rtPrevZCX . edscqmn54a =
UNINITIALIZED_ZCSIG ; } ssSetChecksumVal ( rtS , 0 , 1424953456U ) ;
ssSetChecksumVal ( rtS , 1 , 2663102336U ) ; ssSetChecksumVal ( rtS , 2 ,
103002778U ) ; ssSetChecksumVal ( rtS , 3 , 3508950546U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_fuelCycle_w_trapping_multilevel_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_fuelCycle_w_trapping_multilevel_GetDWork ) ; slsaSetWorkFcnForSimTargetOP
( rtS , mr_fuelCycle_w_trapping_multilevel_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID7 ( tid ) ; }
