#ifndef RTW_HEADER_fuelCycle_w_trapping_multilevel_h_
#define RTW_HEADER_fuelCycle_w_trapping_multilevel_h_
#ifndef fuelCycle_w_trapping_multilevel_COMMON_INCLUDES_
#define fuelCycle_w_trapping_multilevel_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "fuelCycle_w_trapping_multilevel_types.h"
#include "rt_zcfcn.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#define MODEL_NAME fuelCycle_w_trapping_multilevel
#define NSAMPLE_TIMES (8) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (219) 
#define NUM_ZC_EVENTS (12) 
#ifndef NCSTATES
#define NCSTATES (32)   
#elif NCSTATES != 32
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
typedef struct { real_T iiiwxuggrg ; real_T nf4zcvrrw1 ; real_T fvf3nbzioe ;
real_T k4b4lf14vj ; real_T etvkdwnkpj ; real_T psuxlzsuxz ; real_T ebk01qyesg
; real_T idcpjxrtqy ; real_T iajp4d0mcl ; real_T osbfg4zlct ; real_T
eqaeyezh1s ; real_T csnrgnegvo ; real_T b2vzo0hy2s ; real_T eqm2qb1xmg ;
real_T osty4w0h40 ; real_T hpv03qx2eh ; real_T owkrxvvxqg ; real_T oee1351fty
; real_T lrc5riqsm0 ; real_T gti1d5wxoc ; real_T bohvfvgygo ; real_T
cg5lpoodm2 ; real_T niogfz3nzj ; real_T cpciqgvd1i ; real_T ixhq3mtynq ;
real_T aciokmkyoi ; real_T fgstkpld00 ; real_T c2macncjx1 ; real_T gvzulll142
; real_T dzzfskofco ; real_T hdb3kkl1an ; real_T hdfhl1b201 ; real_T
jyxotbfmiy ; real_T fni551xrky ; real_T i5gekqrszk ; real_T opvsbdmt4f ;
real_T f4qjawxtxc ; real_T b4o0mwd5s1 ; real_T ibntl0qzrn ; real_T eoyhxc3y5c
; real_T fqf2ig4ozo ; real_T pylqoentdj ; real_T cph5fceo1k ; real_T
dqaeumpfwq ; real_T oz2ioyl1d1 ; real_T kldtvssa3v ; real_T dssu0124ca ;
real_T jubael0s5t ; real_T imvzvxfth1 ; real_T hhlfdxq4tq ; real_T lv3saiokkc
; real_T mmzzdny3gv ; real_T bxhcn03bs3 ; real_T jw1mkvjqxd ; real_T
ap4ejq14cx ; real_T d11crs30zx ; real_T pkusgmygp4 ; real_T o3mlawuzsu ;
real_T klulqzlxhy ; real_T mg2xxgovdn ; real_T nh1yusewyx ; real_T mq55kovd3p
; real_T ffijpdjagp ; real_T clohbn4dfr ; real_T jtu2fng3ej ; real_T
fybyalbgb2 ; real_T k3yjc0yg3g ; real_T p2krjfpfgh ; real_T gtcb3jdxp3 ;
real_T l0llkpzm13 ; real_T ciffbyucrp ; real_T mtsxpijwck ; real_T kab2nly4jj
; real_T ow3uqqg2aj ; real_T ciw3n3wmul ; real_T jjs4ssptlk ; real_T
mug54mzksq ; real_T cpkkbsqjby ; real_T h1pesm521l ; real_T mrg2inxnui ;
real_T f3bngaj4zp ; real_T ees2bp2bzh ; real_T m34nqp4n5z ; real_T ky32tdgwev
; real_T icsnarysuk ; real_T l1mbg2lxtf ; real_T jjz3f2w1ww ; real_T
ebsdotywiy ; real_T kmllksrcpg ; real_T dlpsaa4wne ; real_T ew51x2a0pq ;
real_T h0g0vscc5a ; real_T emvjgmkgqb ; real_T f2htpqh3ht ; real_T nh2mkz0gux
; real_T mklt5qpuqz ; real_T iip1ojxipj ; real_T hirm4x5pho ; real_T
h0nudpvspr ; real_T jofuuncwgf ; real_T mfsnnr03g3 ; real_T ax2athfpkk ;
real_T hyj42o3iuz ; real_T kkb5zwrqmi ; real_T ehw2zbw0iw ; real_T jpn42chgkq
; real_T bzgkngokio ; real_T noa4ncpcn2 ; real_T d5nn4kjojo ; real_T
h2up4wt3zu ; real_T dxfhrl5haj ; real_T k1rudquzn3 ; real_T ntb3nynmn0 ;
real_T ocbiqwo1jy ; real_T bc0o2qz0ty ; real_T koz3fa4yyj ; real_T eja2c4jp5c
; real_T cidmzevvxk ; real_T guydscbpbh ; real_T dktkpw1bhi ; real_T
kgob5xrqph ; real_T fkha0sace3 ; real_T jivx3sbmm4 ; real_T ftazg5c0fu ;
real_T mzhqvdifiz ; real_T edivwoqmoy ; real_T fd5fpby1xt ; real_T ochdwrnmss
; real_T dzeqvdtusv ; real_T cpbzlxsa4z ; real_T pn0u52zpkg ; real_T
kk4oglgrgt ; real_T d3fgwuvnry ; real_T kwpcxbpmca ; real_T cu0edalrlz ;
real_T eycob2wxh3 ; real_T exrud042ox ; real_T bzj35bjr4u ; real_T dna4jmsata
; real_T gnyiwna5cn ; real_T eu0tusin0r ; real_T oyn54nojeb ; real_T
efehig0u42 ; real_T btsm5i54nc ; real_T mrdniw23zs ; real_T bg3da3n0wb ;
real_T k0hgu4xe0f ; real_T d1yia3o3xe ; real_T hepvlmbt4i ; real_T hbyxmtmphz
; real_T pnzergluua ; real_T knfus34vwq ; real_T pmgkqaam2i ; real_T
lwmqjnrld0 ; real_T jc55rsew1w ; real_T k5203dxgbx ; real_T nj0umut5gp ;
real_T fo1qcnd3al ; real_T i5zgf04o3x ; real_T d04wog3ps1 ; real_T grykhheeys
; real_T krfvi4cflh ; real_T gqgfxwccv4 ; real_T lel3phg0r1 ; real_T
jsspycell1 ; real_T pfdj2j3kbo ; real_T ateto3w1pm ; real_T mb335ejyey ;
real_T lteedkhhy3 ; real_T oa1gustxiq ; real_T fruoe5r5t3 ; real_T ixcgdfbffk
; real_T jzmkioa5k1 ; real_T miby44ssmo ; real_T dozduzanyp ; real_T
cetoh1esws ; real_T ffp2uq1eay ; real_T kyfaz2mb1x ; real_T ku24anqdmm ;
real_T ozrmr5adg2 ; real_T iqsukc15fj ; real_T kl5lj4yyqc ; real_T ghlblpxsfm
; real_T ennagfiv25 ; real_T cj00le33zn ; real_T dj24yjdkk0 ; real_T
enuxhkywvm ; real_T gvsnodzuaj ; real_T ki5rpihgmh ; real_T fs1oeicixp ;
real_T cszo5vy5h3 ; real_T cqrhrhc1sq ; real_T je4cbmtlt4 ; real_T brlwqytyds
; real_T mhjkxa1meq ; real_T ooku50enka ; real_T iirvitebr2 ; real_T
ki4tl0rbga ; real_T lgyyr12kek ; real_T ohvaeydtca ; real_T fkwpmfy3ic ;
real_T ojyufdjynv ; real_T bmkrxgfo2l ; real_T m2fionkrn0 ; real_T gcmv4lfn4n
; real_T kdkynqxxwq ; real_T fgkaot3e42 ; real_T mwmx0yzb4f ; real_T
ogv1c0tddw ; real_T cy3t3xxpoy ; real_T a3i0ozq14p ; real_T dxel3zbjrm ;
real_T opybz520jx ; real_T cmf1wo0hiz ; real_T jsvjvkl4fq ; real_T h1j1ahvfhl
; real_T ae20paxfcr ; real_T iayqmj4rue ; real_T n4io0wcopq ; } B ; typedef
struct { real_T jbfemjfqdu ; real_T h2l1jz22tz ; real_T pqedya33bp ; real_T
dmxo1ux3qp ; real_T ffcbwyd3ut ; int64_T b0dld00fnu ; int64_T hmy2bsk3ta ;
int64_T lhoaby1ffk ; int64_T c5wtluimqm ; int64_T olc1lgjia0 ; struct { void
* LoggedData ; } jxsf3xpnit ; struct { void * LoggedData ; } cmbe2a5ker ;
struct { void * LoggedData ; } gt130sbvyf ; struct { void * LoggedData ; }
m0ivdqq1ds ; struct { void * AQHandles ; } bpvydpjffg ; struct { void *
AQHandles ; } bfgk1czl4m ; struct { void * AQHandles ; } ja1ege25yh ; struct
{ void * AQHandles ; } dn0qqupwms ; struct { void * AQHandles ; } in2jxpqlzw
; struct { void * AQHandles ; } phht5zmf24 ; struct { void * AQHandles ; }
g1upx2ora0 ; struct { void * AQHandles ; } gb53i5u3uk ; struct { void *
AQHandles ; } e0iok5rpsx ; struct { void * AQHandles ; } bvdj0li5qv ; struct
{ void * AQHandles ; } ohawovjfhh ; struct { void * AQHandles ; } ofgcg2rwnf
; struct { void * AQHandles ; } lxy40zsik3 ; struct { void * AQHandles ; }
lr5q5utmxh ; struct { void * AQHandles ; } ojaixcrugo ; struct { void *
AQHandles ; } jhnokpp1dp ; struct { void * AQHandles ; } iohckarwzg ; struct
{ void * AQHandles ; } je2kiqe4dx ; struct { void * AQHandles ; } njvgyvffo2
; struct { void * AQHandles ; } diar2azokk ; struct { void * AQHandles ; }
a0s45dbdod ; struct { void * LoggedData ; } jgrlhmdnhu ; struct { void *
LoggedData ; } fgazjk5423 ; struct { void * AQHandles ; } n2tu4152xd ; struct
{ void * AQHandles ; } favhxcmqok ; struct { void * LoggedData ; } cfsxur0ivk
; struct { void * LoggedData ; } obnnkkxer4 ; struct { void * LoggedData ; }
e5hnmu1lyf ; struct { void * LoggedData ; } fs1etcfe3q ; struct { void *
AQHandles ; } bni3utz05a ; struct { void * LoggedData ; } lwx4ofpmhf ; struct
{ void * LoggedData ; } k30bdvjxid ; struct { void * LoggedData ; }
mwiuydgnkh ; struct { void * LoggedData ; } pnoevo4udr ; struct { void *
LoggedData ; } ghgxdsveji ; struct { void * LoggedData ; } o3jmjepwte ;
struct { void * LoggedData ; } mshmkcmhdt ; struct { void * LoggedData ; }
dbut54doru ; struct { void * AQHandles ; } lumyjs23ja ; struct { void *
AQHandles ; } bk4jfotvgv ; struct { void * LoggedData ; } dycpvmyaei ; struct
{ void * LoggedData ; } akyms3mka4 ; struct { void * AQHandles ; } l0q4q2mauq
; struct { void * AQHandles ; } expqsi0g3r ; struct { void * LoggedData ; }
ibsnvtyivb ; struct { void * LoggedData ; } h5y21eaq2h ; struct { void *
LoggedData ; } ib0h0blurd ; int32_T gjpvvsicgx ; int32_T ivnf1ct5mk ; int32_T
lk33nb0dif ; int32_T lxjgrndv13 ; int32_T basopanm0u ; int32_T gdlhm5czey ;
int32_T az3nbubu5p ; int32_T faseuqsse1 ; int32_T hyxofhb30f ; int32_T
b0palefbsp ; } DW ; typedef struct { real_T htgrh0jjqu ; real_T co1jdeau2v ;
real_T lvqzai4v0g ; real_T mnxe4thxfk ; real_T mnuyjgz25d ; real_T czr1kbthty
; real_T dh4mqtfbta ; real_T eopdaaoigp ; real_T is4kh5d04r ; real_T
i2yisk5ira ; real_T dq5vg1pwin ; real_T ivth0fq3lc ; real_T prie45bad0 ;
real_T l2buheggo3 ; real_T bz1y1deorv ; real_T cjaogzvsz3 ; real_T gscw5qlois
; real_T n4ml13agdg ; real_T lfdbokqx32 ; real_T e330kkmdyz ; real_T
cmqztgmaxh ; real_T j4fspsirju ; real_T pd0yv0rpqx ; real_T n00f3b3n5z ;
real_T ktyas5zdkb ; real_T jslb3nmhpu ; real_T nc0rcorjsb ; real_T aiyvnvjr41
; real_T jgw5jvtnel ; real_T jlkgfmapfz ; real_T mm0isfzekn ; real_T
h121gcp0ue ; } X ; typedef struct { real_T htgrh0jjqu ; real_T co1jdeau2v ;
real_T lvqzai4v0g ; real_T mnxe4thxfk ; real_T mnuyjgz25d ; real_T czr1kbthty
; real_T dh4mqtfbta ; real_T eopdaaoigp ; real_T is4kh5d04r ; real_T
i2yisk5ira ; real_T dq5vg1pwin ; real_T ivth0fq3lc ; real_T prie45bad0 ;
real_T l2buheggo3 ; real_T bz1y1deorv ; real_T cjaogzvsz3 ; real_T gscw5qlois
; real_T n4ml13agdg ; real_T lfdbokqx32 ; real_T e330kkmdyz ; real_T
cmqztgmaxh ; real_T j4fspsirju ; real_T pd0yv0rpqx ; real_T n00f3b3n5z ;
real_T ktyas5zdkb ; real_T jslb3nmhpu ; real_T nc0rcorjsb ; real_T aiyvnvjr41
; real_T jgw5jvtnel ; real_T jlkgfmapfz ; real_T mm0isfzekn ; real_T
h121gcp0ue ; } XDot ; typedef struct { boolean_T htgrh0jjqu ; boolean_T
co1jdeau2v ; boolean_T lvqzai4v0g ; boolean_T mnxe4thxfk ; boolean_T
mnuyjgz25d ; boolean_T czr1kbthty ; boolean_T dh4mqtfbta ; boolean_T
eopdaaoigp ; boolean_T is4kh5d04r ; boolean_T i2yisk5ira ; boolean_T
dq5vg1pwin ; boolean_T ivth0fq3lc ; boolean_T prie45bad0 ; boolean_T
l2buheggo3 ; boolean_T bz1y1deorv ; boolean_T cjaogzvsz3 ; boolean_T
gscw5qlois ; boolean_T n4ml13agdg ; boolean_T lfdbokqx32 ; boolean_T
e330kkmdyz ; boolean_T cmqztgmaxh ; boolean_T j4fspsirju ; boolean_T
pd0yv0rpqx ; boolean_T n00f3b3n5z ; boolean_T ktyas5zdkb ; boolean_T
jslb3nmhpu ; boolean_T nc0rcorjsb ; boolean_T aiyvnvjr41 ; boolean_T
jgw5jvtnel ; boolean_T jlkgfmapfz ; boolean_T mm0isfzekn ; boolean_T
h121gcp0ue ; } XDis ; typedef struct { real_T htgrh0jjqu ; real_T co1jdeau2v
; real_T lvqzai4v0g ; real_T mnxe4thxfk ; real_T mnuyjgz25d ; real_T
czr1kbthty ; real_T dh4mqtfbta ; real_T eopdaaoigp ; real_T is4kh5d04r ;
real_T i2yisk5ira ; real_T dq5vg1pwin ; real_T ivth0fq3lc ; real_T prie45bad0
; real_T l2buheggo3 ; real_T bz1y1deorv ; real_T cjaogzvsz3 ; real_T
gscw5qlois ; real_T n4ml13agdg ; real_T lfdbokqx32 ; real_T e330kkmdyz ;
real_T cmqztgmaxh ; real_T j4fspsirju ; real_T pd0yv0rpqx ; real_T n00f3b3n5z
; real_T ktyas5zdkb ; real_T jslb3nmhpu ; real_T nc0rcorjsb ; real_T
aiyvnvjr41 ; real_T jgw5jvtnel ; real_T jlkgfmapfz ; real_T mm0isfzekn ;
real_T h121gcp0ue ; } CStateAbsTol ; typedef struct { real_T htgrh0jjqu ;
real_T co1jdeau2v ; real_T lvqzai4v0g ; real_T mnxe4thxfk ; real_T mnuyjgz25d
; real_T czr1kbthty ; real_T dh4mqtfbta ; real_T eopdaaoigp ; real_T
is4kh5d04r ; real_T i2yisk5ira ; real_T dq5vg1pwin ; real_T ivth0fq3lc ;
real_T prie45bad0 ; real_T l2buheggo3 ; real_T bz1y1deorv ; real_T cjaogzvsz3
; real_T gscw5qlois ; real_T n4ml13agdg ; real_T lfdbokqx32 ; real_T
e330kkmdyz ; real_T cmqztgmaxh ; real_T j4fspsirju ; real_T pd0yv0rpqx ;
real_T n00f3b3n5z ; real_T ktyas5zdkb ; real_T jslb3nmhpu ; real_T nc0rcorjsb
; real_T aiyvnvjr41 ; real_T jgw5jvtnel ; real_T jlkgfmapfz ; real_T
mm0isfzekn ; real_T h121gcp0ue ; } CXPtMin ; typedef struct { real_T
htgrh0jjqu ; real_T co1jdeau2v ; real_T lvqzai4v0g ; real_T mnxe4thxfk ;
real_T mnuyjgz25d ; real_T czr1kbthty ; real_T dh4mqtfbta ; real_T eopdaaoigp
; real_T is4kh5d04r ; real_T i2yisk5ira ; real_T dq5vg1pwin ; real_T
ivth0fq3lc ; real_T prie45bad0 ; real_T l2buheggo3 ; real_T bz1y1deorv ;
real_T cjaogzvsz3 ; real_T gscw5qlois ; real_T n4ml13agdg ; real_T lfdbokqx32
; real_T e330kkmdyz ; real_T cmqztgmaxh ; real_T j4fspsirju ; real_T
pd0yv0rpqx ; real_T n00f3b3n5z ; real_T ktyas5zdkb ; real_T jslb3nmhpu ;
real_T nc0rcorjsb ; real_T aiyvnvjr41 ; real_T jgw5jvtnel ; real_T jlkgfmapfz
; real_T mm0isfzekn ; real_T h121gcp0ue ; } CXPtMax ; typedef struct { real_T
gz3rqrrgks ; real_T cmsfzg0lyf ; real_T fmvr4gqqkf ; real_T gclmbx3vit ;
real_T pchkpwpesn ; real_T lzqnw1gobb ; real_T cuf22dtmzc ; real_T ihyj2mi3kc
; real_T cfwzwblkvz ; real_T eirfm23vmw ; real_T errnkrpops ; real_T
mte15kt3pl ; } ZCV ; typedef struct { ZCSigState e0m41s4pce ; ZCSigState
f1pzzmnmrz ; ZCSigState lwvvm1bu31 ; ZCSigState mkv1qjpzdz ; ZCSigState
ezwnrlce0c ; ZCSigState ehgnzb15jz ; ZCSigState g4kyl2al0w ; ZCSigState
kccjtmusvi ; ZCSigState lxhainymwv ; ZCSigState dv0chgctwn ; ZCSigState
padts4xd31 ; ZCSigState edscqmn54a ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T AF ; real_T
A_0 ; real_T E_annealing ; real_T I_s_0 ; real_T M_structural ; real_T
M_tungsten ; real_T N_dot ; real_T PM_structural ; real_T PM_tritium ; real_T
PM_tungsten ; real_T T1 ; real_T T12 ; real_T T2 ; real_T T3 ; real_T T4 ;
real_T T5 ; real_T T6 ; real_T T7 ; real_T T8 ; real_T T9 ; real_T TBE ;
real_T TBR ; real_T T_replacement ; real_T T_tungsten ; real_T damage_rate ;
real_T eta2 ; real_T f51 ; real_T f53 ; real_T f54 ; real_T f56 ; real_T f96
; real_T f_dir ; real_T fp3 ; real_T fp4 ; real_T k_B ; real_T lambda ;
real_T n_solute_structural ; real_T n_solute_tungsten ; real_T
n_trap_structural ; real_T n_trap_tungsten_intrinsic ; real_T n_tungsten ;
real_T n_tungsten_max [ 4 ] ; real_T tau1 ; real_T tau12 ; real_T tau2 ;
real_T tau3 ; real_T tau4 ; real_T tau5 ; real_T tau6 ; real_T tau7 ; real_T
tau8 ; real_T tau9 ; real_T tau_detrap_structural ; real_T
tau_detrap_tungsten [ 5 ] ; real_T tau_trap_structural ; real_T
tau_trap_tungsten ; real_T trap_creation_factor_W [ 4 ] ; real_T
trap_density_A_0 ; real_T trap_density_E_annealing ; real_T
trap_density_T_material ; real_T trap_density_damage_rate ; real_T
trap_density_n_max ; real_T Integrator_IC ; real_T Integrator_IC_gjn51xvom5 ;
real_T Integrator_IC_mry3mue1xt ; real_T Integrator_IC_lv4yux4fd2 ; real_T
Integrator_IC_gsmhqvj2p2 ; real_T Integrator_IC_guilf0dsxs ; real_T
Integrator_IC_aoe5ma2bpt ; real_T Integrator_IC_ln32mnhczm ; real_T
Integrator_IC_pzvlozo2nc ; real_T Integrator_IC_fznpj504vt ; real_T
Integrator1_IC ; real_T Integrator1_IC_bjh1younxk ; real_T
Integrator1_IC_luy00dmifv ; real_T Integrator1_IC_hfd0yebv3k ; real_T
Integrator1_IC_apqnwc35ax ; real_T PulseGenerator_Period ; real_T
PulseGenerator_PhaseDelay ; real_T Integrator_IC_kcrxo3wege ; real_T
Integrator_IC_iauzmgwt3b ; real_T Integrator_IC_bfdxoyeb45 ; real_T
Integrator_IC_hsgeimv2ra ; real_T Integrator1_IC_i02smi320p ; real_T
Integrator1_IC_nfzhle1k50 ; real_T Integrator1_IC_p02hk220lo ; real_T
Integrator1_IC_oqtjqencln ; real_T Integrator1_IC_lccyfk1lmn ; real_T
PulseGenerator_Period_mwqel1dvmq ; real_T
PulseGenerator_PhaseDelay_k0s5cgqn5u ; real_T Integrator_IC_p0pugwgzsn ;
real_T Integrator_IC_lmncc23ueu ; real_T Integrator_IC_nchr54klbk ; real_T
Integrator_IC_jrf030n4yu ; real_T Integrator1_IC_caj4cloteg ; real_T
Integrator_IC_prbytjhtp3 ; real_T Integrator1_IC_m4ot5s3dkq ; real_T
PulseGenerator_Period_mpnlrkwdty ; real_T
PulseGenerator_PhaseDelay_emic4rw15d ; real_T
PulseGenerator_Period_d0fefccnsl ; real_T
PulseGenerator_PhaseDelay_dcsuc5mmvs ; real_T
PulseGenerator_Period_f2wfzoa3qm ; real_T
PulseGenerator_PhaseDelay_oegmxwaov1 ; } ; extern const char_T *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern mxArray *
mr_fuelCycle_w_trapping_multilevel_GetDWork ( ) ; extern void
mr_fuelCycle_w_trapping_multilevel_SetDWork ( const mxArray * ssDW ) ; extern
mxArray * mr_fuelCycle_w_trapping_multilevel_GetSimStateDisallowedBlocks ( )
; extern const rtwCAPI_ModelMappingStaticInfo *
fuelCycle_w_trapping_multilevel_GetCAPIStaticMap ( void ) ; extern SimStruct
* const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
