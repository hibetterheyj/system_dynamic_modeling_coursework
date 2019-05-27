#include "__cf_MPM_v2.h"
#ifndef RTW_HEADER_MPM_v2_h_
#define RTW_HEADER_MPM_v2_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef MPM_v2_COMMON_INCLUDES_
#define MPM_v2_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "MPM_v2_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_matrixlib.h"
#define MODEL_NAME MPM_v2
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (4)     
#define NBLOCKIO (50) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (8)   
#elif NCSTATES != 8
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T h3d1qzugu1 ; real_T iakte2o4ts ; real_T nn1kizecsx ;
real_T ct4aj1i22g ; real_T fh5z2grr52 ; real_T kpi30xvfiu ; real_T nzcxbzdnso
; real_T kxwixj4c51 ; real_T malshm1fve ; real_T go0f21vibp ; real_T
juohughovu ; real_T lmc1epifk1 ; real_T kz5i2lnko4 ; real_T oimfja435f ;
real_T nl0np0e4l4 ; real_T ktdrpqs0t0 ; real_T mjmns3sals ; real_T b4y3btq4n5
; real_T l1th1wbd2w ; real_T e5b3l0m5gn ; real_T hgpegle5am ; real_T
ksfp11otbx ; real_T m2xuwblrer ; real_T bjgawnuptj ; real_T f42mwwwgtp ;
real_T mww525kbat ; real_T bz0bj2udsb ; real_T gq3omqys2l ; real_T khaher5rfa
; real_T h0di4ig34m ; real_T l3qgocpfxm ; real_T asqwvo0hvy ; real_T
kriuq3sgjr ; real_T p1rob5cavs ; real_T mur1024azz ; real_T ins4oahfqa ;
real_T oaajcod1yg ; real_T gz42pg1re1 ; real_T oxk2iicbr0 ; real_T p0lyi54e5t
; real_T nrjbntpae3 ; real_T gujjpbrpc5 ; real_T b1i3w43yil ; real_T
e24wxy4f1i ; real_T o0ouurxc0c ; real_T ejzou0u5ll ; real_T jid1bzahmd ;
real_T cqvlft4i00 ; real_T pkjkyjr3mw ; real_T jqvj0mure4 ; } B ; typedef
struct { struct { void * AQHandles ; void * SlioLTF ; } pkwbje3ged ; struct {
void * AQHandles ; void * SlioLTF ; } evtweumn1g ; struct { void * AQHandles
; void * SlioLTF ; } fk1unc20lv ; struct { void * AQHandles ; void * SlioLTF
; } ovwwnm5nh4 ; struct { void * LoggedData ; } jsmyt5h3g5 ; struct { void *
LoggedData ; } kjf2ktbrti ; struct { void * LoggedData ; } nrwdv0035m ;
struct { void * LoggedData ; } krtghk1lfu ; } DW ; typedef struct { real_T
iaxxo1tqla ; real_T crtph0zthp ; real_T jagx4udcua ; real_T oxuba1sl5f ;
real_T jpkubvr5os ; real_T gy0xejxop3 ; real_T mcpxexzhkw ; real_T fzssasrf03
; } X ; typedef struct { real_T iaxxo1tqla ; real_T crtph0zthp ; real_T
jagx4udcua ; real_T oxuba1sl5f ; real_T jpkubvr5os ; real_T gy0xejxop3 ;
real_T mcpxexzhkw ; real_T fzssasrf03 ; } XDot ; typedef struct { boolean_T
iaxxo1tqla ; boolean_T crtph0zthp ; boolean_T jagx4udcua ; boolean_T
oxuba1sl5f ; boolean_T jpkubvr5os ; boolean_T gy0xejxop3 ; boolean_T
mcpxexzhkw ; boolean_T fzssasrf03 ; } XDis ; typedef struct { real_T
d0lgsmdfu4 ; real_T gjm1nbk0j5 ; real_T aw04k1evdb ; real_T dws5rzbxlp ; }
ExtY ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T xAxBu_Cw ; real_T xAxBu_Cwc ; real_T yCx_Jt ; real_T xAxBu_Jt ;
real_T yCx_Jw ; real_T xAxBu_Jw ; real_T yCx_Mt ; real_T xAxBu_Mt ; real_T
xAxBu_Rg ; real_T xAxBu_Rw ; real_T xAxBu_Rwc ; real_T xAxBu_r ; real_T
Integrator_IC ; real_T Saturation4_UpperSat ; real_T Saturation4_LowerSat ;
real_T Integrator7_IC ; real_T Saturation3_UpperSat ; real_T
Saturation3_LowerSat ; real_T Integrator3_IC ; real_T Saturation1_UpperSat ;
real_T Saturation1_LowerSat ; real_T Integrator4_IC ; real_T
Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T tau_l_Value ;
real_T tau_r_Value ; real_T Integrator2_IC ; real_T Integrator1_IC ; real_T
Integrator5_IC ; real_T Integrator6_IC ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Saturation1_UpperSat_cp4qzqeylc ; real_T
Saturation1_LowerSat_hy1zn0mr5r ; real_T Saturation2_UpperSat_b3hyjyjkr4 ;
real_T Saturation2_LowerSat_pvj3cm1vm3 ; real_T
Saturation3_UpperSat_gpj2xd5pbc ; real_T Saturation3_LowerSat_efftzx1ry1 ;
real_T Saturation4_UpperSat_caq3ilgnu3 ; real_T
Saturation4_LowerSat_gzgavadirn ; real_T Saturation5_UpperSat ; real_T
Saturation5_LowerSat ; real_T Saturation6_UpperSat ; real_T
Saturation6_LowerSat ; real_T Saturation7_UpperSat ; real_T
Saturation7_LowerSat ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern ExtY rtY ; extern P rtP
; extern const rtwCAPI_ModelMappingStaticInfo * MPM_v2_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
