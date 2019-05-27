#include "__cf_MPM_v2.h"
#include "rt_logging_mmi.h"
#include "MPM_v2_capi.h"
#include <math.h>
#include "MPM_v2.h"
#include "MPM_v2_private.h"
#include "MPM_v2_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.0 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\MPM_v2\\MPM_v2_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; ExtY rtY ; static SimStruct model_S ; SimStruct *
const rtS = & model_S ; void MdlInitialize ( void ) { rtX . iaxxo1tqla = rtP
. Integrator_IC ; rtX . crtph0zthp = rtP . Integrator7_IC ; rtX . jagx4udcua
= rtP . Integrator3_IC ; rtX . oxuba1sl5f = rtP . Integrator4_IC ; rtX .
jpkubvr5os = rtP . Integrator2_IC ; rtX . gy0xejxop3 = rtP . Integrator1_IC ;
rtX . mcpxexzhkw = rtP . Integrator5_IC ; rtX . fzssasrf03 = rtP .
Integrator6_IC ; } void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "MPM_v2/f4 wL" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . pkwbje3ged . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "87df0da4-498d-4948-9b47-5c6ccc31e046" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. pkwbje3ged . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . pkwbje3ged
. AQHandles , "0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW
. pkwbje3ged . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . pkwbje3ged . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . pkwbje3ged . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . pkwbje3ged . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . pkwbje3ged . AQHandles , 1 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
pkwbje3ged . SlioLTF = ( NULL ) ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "MPM_v2/f27 wR" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . evtweumn1g . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "7523cba8-4621-49c4-8f55-a4ad10d9524b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. evtweumn1g . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . evtweumn1g
. AQHandles , "0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW
. evtweumn1g . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . evtweumn1g . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . evtweumn1g . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . evtweumn1g . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . evtweumn1g . AQHandles , 2 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
evtweumn1g . SlioLTF = ( NULL ) ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "MPM_v2/f14 V_CG" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . fk1unc20lv . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "18f28f64-310a-41d4-987a-610f53fde561" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. fk1unc20lv . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . fk1unc20lv
. AQHandles , "0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW
. fk1unc20lv . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . fk1unc20lv . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . fk1unc20lv . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . fk1unc20lv . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . fk1unc20lv . AQHandles , 3 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
fk1unc20lv . SlioLTF = ( NULL ) ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "MPM_v2/f17 theta_CG" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ovwwnm5nh4 . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "96df0a2c-80df-4c56-a05f-b216fac7f97b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. ovwwnm5nh4 . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ovwwnm5nh4
. AQHandles , "0.1" , 0.1 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW
. ovwwnm5nh4 . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . ovwwnm5nh4 . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . ovwwnm5nh4 . AQHandles ,
loggedName , origSigName , propName ) ; sdiAsyncRepoSetSignalDomainType (
rtDW . ovwwnm5nh4 . AQHandles , "outport" ) ;
sdiAsyncRepoSetSignalExportOrder ( rtDW . ovwwnm5nh4 . AQHandles , 4 ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
ovwwnm5nh4 . SlioLTF = ( NULL ) ; } MdlInitialize ( ) ; } void MdlOutputs (
int_T tid ) { real_T aszsnodcor ; real_T mguixufx0q ; real_T ilg1oria22 ; rtB
. h3d1qzugu1 = rtX . iaxxo1tqla ; rtB . iakte2o4ts = 1.0 / rtP . yCx_Jw * rtB
. h3d1qzugu1 ; if ( rtB . iakte2o4ts > rtP . Saturation4_UpperSat ) { rtB .
nn1kizecsx = rtP . Saturation4_UpperSat ; } else if ( rtB . iakte2o4ts < rtP
. Saturation4_LowerSat ) { rtB . nn1kizecsx = rtP . Saturation4_LowerSat ; }
else { rtB . nn1kizecsx = rtB . iakte2o4ts ; } rtY . d0lgsmdfu4 = rtB .
nn1kizecsx ; rtB . ct4aj1i22g = rtX . crtph0zthp ; rtB . fh5z2grr52 = 1.0 /
rtP . yCx_Jw * rtB . ct4aj1i22g ; if ( rtB . fh5z2grr52 > rtP .
Saturation3_UpperSat ) { rtB . kpi30xvfiu = rtP . Saturation3_UpperSat ; }
else if ( rtB . fh5z2grr52 < rtP . Saturation3_LowerSat ) { rtB . kpi30xvfiu
= rtP . Saturation3_LowerSat ; } else { rtB . kpi30xvfiu = rtB . fh5z2grr52 ;
} rtY . gjm1nbk0j5 = rtB . kpi30xvfiu ; rtB . nzcxbzdnso = rtX . jagx4udcua ;
rtB . kxwixj4c51 = 1.0 / rtP . yCx_Mt * rtB . nzcxbzdnso ; if ( rtB .
kxwixj4c51 > rtP . Saturation1_UpperSat ) { rtB . malshm1fve = rtP .
Saturation1_UpperSat ; } else if ( rtB . kxwixj4c51 < rtP .
Saturation1_LowerSat ) { rtB . malshm1fve = rtP . Saturation1_LowerSat ; }
else { rtB . malshm1fve = rtB . kxwixj4c51 ; } rtY . aw04k1evdb = rtB .
malshm1fve ; rtB . go0f21vibp = rtX . oxuba1sl5f ; rtB . juohughovu = 1.0 /
rtP . yCx_Jt * rtB . go0f21vibp ; if ( rtB . juohughovu > rtP .
Saturation2_UpperSat ) { rtB . lmc1epifk1 = rtP . Saturation2_UpperSat ; }
else if ( rtB . juohughovu < rtP . Saturation2_LowerSat ) { rtB . lmc1epifk1
= rtP . Saturation2_LowerSat ; } else { rtB . lmc1epifk1 = rtB . juohughovu ;
} rtY . dws5rzbxlp = rtB . lmc1epifk1 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ { if ( ( rtDW . pkwbje3ged . AQHandles || rtDW . pkwbje3ged . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . pkwbje3ged .
AQHandles , rtDW . pkwbje3ged . SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , (
void * ) & rtB . nn1kizecsx ) ; } } { if ( ( rtDW . evtweumn1g . AQHandles ||
rtDW . evtweumn1g . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . evtweumn1g . AQHandles , rtDW . evtweumn1g .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( void * ) & rtB . kpi30xvfiu ) ; }
} { if ( ( rtDW . fk1unc20lv . AQHandles || rtDW . fk1unc20lv . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . fk1unc20lv .
AQHandles , rtDW . fk1unc20lv . SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , (
void * ) & rtB . malshm1fve ) ; } } { if ( ( rtDW . ovwwnm5nh4 . AQHandles ||
rtDW . ovwwnm5nh4 . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . ovwwnm5nh4 . AQHandles , rtDW . ovwwnm5nh4 .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( void * ) & rtB . lmc1epifk1 ) ; }
} } if ( rtB . nn1kizecsx > rtB . kpi30xvfiu ) { aszsnodcor = 0.8 *
muDoubleScalarMax ( rtB . nn1kizecsx , rtB . kpi30xvfiu ) / muDoubleScalarAbs
( rtB . nn1kizecsx - rtB . kpi30xvfiu ) ; ilg1oria22 = 0.8 *
muDoubleScalarMin ( rtB . nn1kizecsx , rtB . kpi30xvfiu ) / muDoubleScalarAbs
( rtB . nn1kizecsx - rtB . kpi30xvfiu ) ; } else if ( rtB . kpi30xvfiu > rtB
. nn1kizecsx ) { ilg1oria22 = 0.8 * muDoubleScalarMax ( rtB . nn1kizecsx ,
rtB . kpi30xvfiu ) / muDoubleScalarAbs ( rtB . nn1kizecsx - rtB . kpi30xvfiu
) ; aszsnodcor = 0.8 * muDoubleScalarMin ( rtB . nn1kizecsx , rtB .
kpi30xvfiu ) / muDoubleScalarAbs ( rtB . nn1kizecsx - rtB . kpi30xvfiu ) ; }
else { aszsnodcor = ( rtInf ) ; ilg1oria22 = ( rtInf ) ; } rtB . kz5i2lnko4 =
rtP . xAxBu_Rg / rtP . xAxBu_Jw * rtB . h3d1qzugu1 ; rtB . oimfja435f = rtX .
jpkubvr5os ; rtB . nl0np0e4l4 = rtP . xAxBu_r / rtP . xAxBu_Cwc * rtB .
oimfja435f ; rtB . ktdrpqs0t0 = rtX . gy0xejxop3 ; rtB . mjmns3sals = 1.0 /
rtP . xAxBu_Cw * rtB . ktdrpqs0t0 ; rtB . b4y3btq4n5 = ( ( aszsnodcor - rtB .
kz5i2lnko4 ) - rtB . nl0np0e4l4 ) - rtB . mjmns3sals ; rtB . l1th1wbd2w = 1.0
/ rtP . xAxBu_Jw * rtB . h3d1qzugu1 ; rtB . e5b3l0m5gn = 1.0 / ( rtP .
xAxBu_Cw * rtP . xAxBu_Rw ) * rtB . ktdrpqs0t0 ; rtB . hgpegle5am = rtB .
l1th1wbd2w - rtB . e5b3l0m5gn ; rtB . ksfp11otbx = rtP . xAxBu_r / rtP .
xAxBu_Jw * rtB . h3d1qzugu1 ; rtB . m2xuwblrer = 1.0 / ( rtP . xAxBu_Rwc *
rtP . xAxBu_Cwc ) * rtB . oimfja435f ; if ( rtP . tau_l_Value == ( rtInf ) )
{ aszsnodcor = 0.0 ; } else { aszsnodcor = rtB . go0f21vibp / ( rtP .
xAxBu_Jt * rtP . tau_l_Value ) ; } rtB . bjgawnuptj = 1.0 / rtP . xAxBu_Mt *
rtB . nzcxbzdnso ; rtB . f42mwwwgtp = ( ( rtB . ksfp11otbx - rtB . m2xuwblrer
) - aszsnodcor ) - rtB . bjgawnuptj ; rtB . mww525kbat = 1.0 / rtP .
xAxBu_Cwc * rtB . oimfja435f ; rtB . bz0bj2udsb = rtX . mcpxexzhkw ; rtB .
gq3omqys2l = 1.0 / rtP . xAxBu_Cwc * rtB . bz0bj2udsb ; rtB . khaher5rfa =
rtB . mww525kbat + rtB . gq3omqys2l ; if ( rtP . tau_l_Value == ( rtInf ) ) {
aszsnodcor = 0.0 ; } else { aszsnodcor = rtB . oimfja435f / ( rtP . xAxBu_Cw
* rtP . tau_l_Value ) ; } if ( rtP . tau_r_Value == ( rtInf ) ) { mguixufx0q
= 0.0 ; } else { mguixufx0q = rtB . bz0bj2udsb / ( rtP . xAxBu_Cw * rtP .
tau_r_Value ) ; } rtB . h0di4ig34m = mguixufx0q - aszsnodcor ; rtB .
l3qgocpfxm = rtP . xAxBu_r / rtP . xAxBu_Jw * rtB . ct4aj1i22g ; rtB .
asqwvo0hvy = 1.0 / rtP . xAxBu_Mt * rtB . nzcxbzdnso ; if ( rtP . tau_r_Value
== ( rtInf ) ) { aszsnodcor = 0.0 ; } else { aszsnodcor = rtB . go0f21vibp /
( rtP . xAxBu_Jt * rtP . tau_r_Value ) ; } rtB . kriuq3sgjr = 1.0 / ( rtP .
xAxBu_Rwc * rtP . xAxBu_Cwc ) * rtB . bz0bj2udsb ; rtB . p1rob5cavs = ( ( rtB
. l3qgocpfxm - rtB . asqwvo0hvy ) - aszsnodcor ) - rtB . kriuq3sgjr ; rtB .
mur1024azz = 1.0 / rtP . xAxBu_Jw * rtB . ct4aj1i22g ; rtB . ins4oahfqa = rtX
. fzssasrf03 ; rtB . oaajcod1yg = 1.0 / ( rtP . xAxBu_Rw * rtP . xAxBu_Cw ) *
rtB . ins4oahfqa ; rtB . gz42pg1re1 = rtB . mur1024azz - rtB . oaajcod1yg ;
rtB . oxk2iicbr0 = rtP . xAxBu_Rg / rtP . xAxBu_Jw * rtB . ct4aj1i22g ; rtB .
p0lyi54e5t = rtP . xAxBu_r / rtP . xAxBu_Cwc * rtB . bz0bj2udsb ; rtB .
nrjbntpae3 = 1.0 / rtP . xAxBu_Cw * rtB . ins4oahfqa ; rtB . gujjpbrpc5 = ( (
ilg1oria22 - rtB . oxk2iicbr0 ) - rtB . p0lyi54e5t ) - rtB . nrjbntpae3 ; if
( rtB . b4y3btq4n5 > rtP . Saturation_UpperSat ) { rtB . b1i3w43yil = rtP .
Saturation_UpperSat ; } else if ( rtB . b4y3btq4n5 < rtP .
Saturation_LowerSat ) { rtB . b1i3w43yil = rtP . Saturation_LowerSat ; } else
{ rtB . b1i3w43yil = rtB . b4y3btq4n5 ; } if ( rtB . h0di4ig34m > rtP .
Saturation1_UpperSat_cp4qzqeylc ) { rtB . e24wxy4f1i = rtP .
Saturation1_UpperSat_cp4qzqeylc ; } else if ( rtB . h0di4ig34m < rtP .
Saturation1_LowerSat_hy1zn0mr5r ) { rtB . e24wxy4f1i = rtP .
Saturation1_LowerSat_hy1zn0mr5r ; } else { rtB . e24wxy4f1i = rtB .
h0di4ig34m ; } if ( rtB . khaher5rfa > rtP . Saturation2_UpperSat_b3hyjyjkr4
) { rtB . o0ouurxc0c = rtP . Saturation2_UpperSat_b3hyjyjkr4 ; } else if (
rtB . khaher5rfa < rtP . Saturation2_LowerSat_pvj3cm1vm3 ) { rtB . o0ouurxc0c
= rtP . Saturation2_LowerSat_pvj3cm1vm3 ; } else { rtB . o0ouurxc0c = rtB .
khaher5rfa ; } if ( rtB . f42mwwwgtp > rtP . Saturation3_UpperSat_gpj2xd5pbc
) { rtB . ejzou0u5ll = rtP . Saturation3_UpperSat_gpj2xd5pbc ; } else if (
rtB . f42mwwwgtp < rtP . Saturation3_LowerSat_efftzx1ry1 ) { rtB . ejzou0u5ll
= rtP . Saturation3_LowerSat_efftzx1ry1 ; } else { rtB . ejzou0u5ll = rtB .
f42mwwwgtp ; } if ( rtB . hgpegle5am > rtP . Saturation4_UpperSat_caq3ilgnu3
) { rtB . jid1bzahmd = rtP . Saturation4_UpperSat_caq3ilgnu3 ; } else if (
rtB . hgpegle5am < rtP . Saturation4_LowerSat_gzgavadirn ) { rtB . jid1bzahmd
= rtP . Saturation4_LowerSat_gzgavadirn ; } else { rtB . jid1bzahmd = rtB .
hgpegle5am ; } if ( rtB . p1rob5cavs > rtP . Saturation5_UpperSat ) { rtB .
cqvlft4i00 = rtP . Saturation5_UpperSat ; } else if ( rtB . p1rob5cavs < rtP
. Saturation5_LowerSat ) { rtB . cqvlft4i00 = rtP . Saturation5_LowerSat ; }
else { rtB . cqvlft4i00 = rtB . p1rob5cavs ; } if ( rtB . gz42pg1re1 > rtP .
Saturation6_UpperSat ) { rtB . pkjkyjr3mw = rtP . Saturation6_UpperSat ; }
else if ( rtB . gz42pg1re1 < rtP . Saturation6_LowerSat ) { rtB . pkjkyjr3mw
= rtP . Saturation6_LowerSat ; } else { rtB . pkjkyjr3mw = rtB . gz42pg1re1 ;
} if ( rtB . gujjpbrpc5 > rtP . Saturation7_UpperSat ) { rtB . jqvj0mure4 =
rtP . Saturation7_UpperSat ; } else if ( rtB . gujjpbrpc5 < rtP .
Saturation7_LowerSat ) { rtB . jqvj0mure4 = rtP . Saturation7_LowerSat ; }
else { rtB . jqvj0mure4 = rtB . gujjpbrpc5 ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> iaxxo1tqla = rtB . b1i3w43yil ; _rtXdot -> crtph0zthp =
rtB . jqvj0mure4 ; _rtXdot -> jagx4udcua = rtB . o0ouurxc0c ; _rtXdot ->
oxuba1sl5f = rtB . e24wxy4f1i ; _rtXdot -> jpkubvr5os = rtB . ejzou0u5ll ;
_rtXdot -> gy0xejxop3 = rtB . jid1bzahmd ; _rtXdot -> mcpxexzhkw = rtB .
cqvlft4i00 ; _rtXdot -> fzssasrf03 = rtB . pkjkyjr3mw ; } void MdlProjection
( void ) { } void MdlTerminate ( void ) { { if ( rtDW . pkwbje3ged .
AQHandles ) { sdiTerminateStreaming ( & rtDW . pkwbje3ged . AQHandles ) ; }
if ( rtDW . pkwbje3ged . SlioLTF ) { rtwDestructAccessorPointer ( rtDW .
pkwbje3ged . SlioLTF ) ; } } { if ( rtDW . evtweumn1g . AQHandles ) {
sdiTerminateStreaming ( & rtDW . evtweumn1g . AQHandles ) ; } if ( rtDW .
evtweumn1g . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . evtweumn1g .
SlioLTF ) ; } } { if ( rtDW . fk1unc20lv . AQHandles ) {
sdiTerminateStreaming ( & rtDW . fk1unc20lv . AQHandles ) ; } if ( rtDW .
fk1unc20lv . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . fk1unc20lv .
SlioLTF ) ; } } { if ( rtDW . ovwwnm5nh4 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . ovwwnm5nh4 . AQHandles ) ; } if ( rtDW .
ovwwnm5nh4 . SlioLTF ) { rtwDestructAccessorPointer ( rtDW . ovwwnm5nh4 .
SlioLTF ) ; } } if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 8 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 4 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 76 ) ; ssSetNumBlockIO ( rtS , 50 ) ;
ssSetNumBlockParams ( rtS , 46 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.1 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3757926976U ) ;
ssSetChecksumVal ( rtS , 1 , 183422155U ) ; ssSetChecksumVal ( rtS , 2 ,
3475240299U ) ; ssSetChecksumVal ( rtS , 3 , 751166279U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
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
( B ) ) ; } { ssSetY ( rtS , & rtY ) ; ( void ) memset ( ( void * ) & rtY , 0
, sizeof ( ExtY ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates (
rtS , x ) ; ( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void *
dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset
( dwork , 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void
) memset ( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ;
ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo . numDataTypes = 14 ;
dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = &
rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = & rtBTransTable ; dtInfo .
PTransTable = & rtPTransTable ; dtInfo . dataTypeInfoTable =
rtDataTypeInfoTable ; } MPM_v2_InitializeDataMapInfo ( ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"MPM_v2" ) ; ssSetPath ( rtS , "MPM_v2" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 5.0 ) ; ssSetStepSize ( rtS , 0.1 ) ; ssSetFixedStepSize
( rtS , 0.1 ) ; ssSetSolverExtrapolationOrder ( rtS , 4 ) ;
ssSetSolverNumberNewtonIterations ( rtS , 1 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = NULL ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT ( ssGetRTWLogInfo ( rtS )
, "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal
( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 4 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; { static void *
rt_LoggedOutputSignalPtrs [ ] = { & rtY . d0lgsmdfu4 , & rtY . gjm1nbk0j5 , &
rtY . aw04k1evdb , & rtY . dws5rzbxlp } ; rtliSetLogYSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( ( LogSignalPtrsType ) rt_LoggedOutputSignalPtrs )
) ; } { static int_T rt_LoggedOutputWidths [ ] = { 1 , 1 , 1 , 1 } ; static
int_T rt_LoggedOutputNumDimensions [ ] = { 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedOutputDimensions [ ] = { 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedOutputIsVarDims [ ] = { 0 , 0 , 0 , 0 } ; static void *
rt_LoggedCurrentSignalDimensions [ ] = { ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) } ; static int_T rt_LoggedCurrentSignalDimensionsSize [ ] = { 4 , 4 ,
4 , 4 } ; static BuiltInDTypeId rt_LoggedOutputDataTypeIds [ ] = { SS_DOUBLE
, SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedOutputComplexSignals [ ] = { 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingPreprocessingFcnPtrs [ ] = { ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedOutputLabels
[ ] = { "" , "" , "" , "" } ; static const char_T * rt_LoggedOutputBlockNames
[ ] = { "MPM_v2/f4 wL" , "MPM_v2/f27 wR" , "MPM_v2/f14 V_CG" ,
"MPM_v2/f17 theta_CG" } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo
rt_LoggedOutputSignalInfo [ ] = { { 4 , rt_LoggedOutputWidths ,
rt_LoggedOutputNumDimensions , rt_LoggedOutputDimensions ,
rt_LoggedOutputIsVarDims , rt_LoggedCurrentSignalDimensions ,
rt_LoggedCurrentSignalDimensionsSize , rt_LoggedOutputDataTypeIds ,
rt_LoggedOutputComplexSignals , ( NULL ) , rt_LoggingPreprocessingFcnPtrs , {
rt_LoggedOutputLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedOutputBlockNames } , { ( NULL ) } , ( NULL ) ,
rt_RTWLogDataTypeConvert } } ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS
) , rt_LoggedOutputSignalInfo ) ; rt_LoggedCurrentSignalDimensions [ 0 ] = &
rt_LoggedOutputWidths [ 0 ] ; rt_LoggedCurrentSignalDimensions [ 1 ] = &
rt_LoggedOutputWidths [ 1 ] ; rt_LoggedCurrentSignalDimensions [ 2 ] = &
rt_LoggedOutputWidths [ 2 ] ; rt_LoggedCurrentSignalDimensions [ 3 ] = &
rt_LoggedOutputWidths [ 3 ] ; } rtliSetLogY ( ssGetRTWLogInfo ( rtS ) ,
"yout" ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 (
rtS , & statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 8 ] ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode14x" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 3757926976U ) ; ssSetChecksumVal ( rtS , 1 ,
183422155U ) ; ssSetChecksumVal ( rtS , 2 , 3475240299U ) ; ssSetChecksumVal
( rtS , 3 , 751166279U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 6 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
