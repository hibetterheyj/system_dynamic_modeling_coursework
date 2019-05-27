#include "__cf_MPM_v2.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "MPM_v2_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "MPM_v2.h"
#include "MPM_v2_capi.h"
#include "MPM_v2_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain10" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 3 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain12" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain15" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 5 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain16" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain17" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 7 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain18" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain19" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 9 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain20" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 11 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain21" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 13 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 15 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain6" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Gain7" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 17 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Gain8" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator" ) , TARGET_STRING ( "p2" ) , 0 , 0 , 0 , 0 ,
0 } , { 19 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator1" ) ,
TARGET_STRING ( "q6" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator2" ) , TARGET_STRING ( "q11" ) , 0 , 0 , 0 , 0
, 0 } , { 21 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator3" ) ,
TARGET_STRING ( "p2" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator4" ) , TARGET_STRING ( "p2" ) , 0 , 0 , 0 , 0
, 0 } , { 23 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator5" ) ,
TARGET_STRING ( "q20" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator6" ) , TARGET_STRING ( "q25" ) , 0 , 0 , 0 , 0
, 0 } , { 25 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator7" ) ,
TARGET_STRING ( "p2" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 27 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 29 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 31 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 33 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation7" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Add" ) , TARGET_STRING ( "p2'" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 35 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Add1" ) , TARGET_STRING (
"q6'" ) , 0 , 0 , 0 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Add2" ) , TARGET_STRING ( "q11'" ) , 0 , 0 , 0 , 0 , 0 }
, { 37 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Add3" ) , TARGET_STRING (
"p14'" ) , 0 , 0 , 0 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Add4" ) , TARGET_STRING ( "p17'" ) , 0 , 0 , 0 , 0 , 0 }
, { 39 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Add5" ) , TARGET_STRING (
"q20'" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Add6" ) , TARGET_STRING ( "q25'" ) , 0 , 0 , 0 , 0 , 0 }
, { 41 , 0 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Add7" ) , TARGET_STRING (
"p29'" ) , 0 , 0 , 0 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"MPM_v2/y=[C]x/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 43 ,
0 , TARGET_STRING ( "MPM_v2/y=[C]x/Gain1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 44 , 0 , TARGET_STRING ( "MPM_v2/y=[C]x/Gain2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
"MPM_v2/y=[C]x/Gain3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 ,
0 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 47 , 0 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation2" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"MPM_v2/y=[C]x/Saturation3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 49 , 0 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation4" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 }
} ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 50 ,
TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING ( "Rg" ) , 0 , 0 , 0
} , { 51 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING ( "Jw" ) ,
0 , 0 , 0 } , { 52 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING
( "Cwc" ) , 0 , 0 , 0 } , { 53 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) ,
TARGET_STRING ( "Rwc" ) , 0 , 0 , 0 } , { 54 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING ( "Cw" ) , 0 , 0 , 0 } , { 55 ,
TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING ( "Rw" ) , 0 , 0 , 0
} , { 56 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING ( "Jt" ) ,
0 , 0 , 0 } , { 57 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) , TARGET_STRING
( "Mt" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u" ) ,
TARGET_STRING ( "r" ) , 0 , 0 , 0 } , { 59 , TARGET_STRING ( "MPM_v2/y=[C]x"
) , TARGET_STRING ( "Jw" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"MPM_v2/y=[C]x" ) , TARGET_STRING ( "Mt" ) , 0 , 0 , 0 } , { 61 ,
TARGET_STRING ( "MPM_v2/y=[C]x" ) , TARGET_STRING ( "Jt" ) , 0 , 0 , 0 } , {
62 , TARGET_STRING ( "MPM_v2/tau_l" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 63 , TARGET_STRING ( "MPM_v2/tau_r" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 64 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 66 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 67 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 68 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator4" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 69 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator5" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 70 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Integrator6" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 71 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Integrator7" ) , TARGET_STRING ( "InitialCondition" ) ,
0 , 0 , 0 } , { 72 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 73 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 ,
0 } , { 74 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 75 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 76 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 77 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation2" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 78 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation3" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 79 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation3" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 80 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation4" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 81 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation4" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 82 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation5" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 83 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation5" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 84 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation6" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 85 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation6" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 86 , TARGET_STRING ( "MPM_v2/x'=[A]x+[B]u/Saturation7" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 0 , 0 } , { 87 , TARGET_STRING (
"MPM_v2/x'=[A]x+[B]u/Saturation7" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0
, 0 } , { 88 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation1" ) , TARGET_STRING
( "UpperLimit" ) , 0 , 0 , 0 } , { 89 , TARGET_STRING (
"MPM_v2/y=[C]x/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 90 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation2" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 91 , TARGET_STRING (
"MPM_v2/y=[C]x/Saturation2" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 92 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation3" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 93 , TARGET_STRING (
"MPM_v2/y=[C]x/Saturation3" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 94 , TARGET_STRING ( "MPM_v2/y=[C]x/Saturation4" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"MPM_v2/y=[C]x/Saturation4" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 }
, { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . kz5i2lnko4 , & rtB . l1th1wbd2w ,
& rtB . kriuq3sgjr , & rtB . gq3omqys2l , & rtB . asqwvo0hvy , & rtB .
oaajcod1yg , & rtB . oxk2iicbr0 , & rtB . p0lyi54e5t , & rtB . nrjbntpae3 , &
rtB . e5b3l0m5gn , & rtB . mur1024azz , & rtB . l3qgocpfxm , & rtB .
ksfp11otbx , & rtB . m2xuwblrer , & rtB . nl0np0e4l4 , & rtB . mjmns3sals , &
rtB . mww525kbat , & rtB . bjgawnuptj , & rtB . h3d1qzugu1 , & rtB .
ktdrpqs0t0 , & rtB . oimfja435f , & rtB . nzcxbzdnso , & rtB . go0f21vibp , &
rtB . bz0bj2udsb , & rtB . ins4oahfqa , & rtB . ct4aj1i22g , & rtB .
b1i3w43yil , & rtB . e24wxy4f1i , & rtB . o0ouurxc0c , & rtB . ejzou0u5ll , &
rtB . jid1bzahmd , & rtB . cqvlft4i00 , & rtB . pkjkyjr3mw , & rtB .
jqvj0mure4 , & rtB . b4y3btq4n5 , & rtB . hgpegle5am , & rtB . f42mwwwgtp , &
rtB . khaher5rfa , & rtB . h0di4ig34m , & rtB . p1rob5cavs , & rtB .
gz42pg1re1 , & rtB . gujjpbrpc5 , & rtB . iakte2o4ts , & rtB . kxwixj4c51 , &
rtB . juohughovu , & rtB . fh5z2grr52 , & rtB . malshm1fve , & rtB .
lmc1epifk1 , & rtB . kpi30xvfiu , & rtB . nn1kizecsx , & rtP . xAxBu_Rg , &
rtP . xAxBu_Jw , & rtP . xAxBu_Cwc , & rtP . xAxBu_Rwc , & rtP . xAxBu_Cw , &
rtP . xAxBu_Rw , & rtP . xAxBu_Jt , & rtP . xAxBu_Mt , & rtP . xAxBu_r , &
rtP . yCx_Jw , & rtP . yCx_Mt , & rtP . yCx_Jt , & rtP . tau_l_Value , & rtP
. tau_r_Value , & rtP . Integrator_IC , & rtP . Integrator1_IC , & rtP .
Integrator2_IC , & rtP . Integrator3_IC , & rtP . Integrator4_IC , & rtP .
Integrator5_IC , & rtP . Integrator6_IC , & rtP . Integrator7_IC , & rtP .
Saturation_UpperSat , & rtP . Saturation_LowerSat , & rtP .
Saturation1_UpperSat_cp4qzqeylc , & rtP . Saturation1_LowerSat_hy1zn0mr5r , &
rtP . Saturation2_UpperSat_b3hyjyjkr4 , & rtP .
Saturation2_LowerSat_pvj3cm1vm3 , & rtP . Saturation3_UpperSat_gpj2xd5pbc , &
rtP . Saturation3_LowerSat_efftzx1ry1 , & rtP .
Saturation4_UpperSat_caq3ilgnu3 , & rtP . Saturation4_LowerSat_gzgavadirn , &
rtP . Saturation5_UpperSat , & rtP . Saturation5_LowerSat , & rtP .
Saturation6_UpperSat , & rtP . Saturation6_LowerSat , & rtP .
Saturation7_UpperSat , & rtP . Saturation7_LowerSat , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
Saturation3_UpperSat , & rtP . Saturation3_LowerSat , & rtP .
Saturation4_UpperSat , & rtP . Saturation4_LowerSat , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 50 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 46 , rtModelParameters , 0 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 3757926976U , 183422155U
, 3475240299U , 751166279U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * MPM_v2_GetCAPIStaticMap ( void ) { return &
mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void MPM_v2_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void MPM_v2_host_InitializeDataMapInfo ( MPM_v2_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
