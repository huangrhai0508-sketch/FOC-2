#include "currentloop.h"
#include "rtwtypes.h"
#include <math.h>
#include "currentloop_private.h"
void idkqe0cpzy_prot ( eecdzbdy4h_prot * localDW ) { localDW ->
jtjulypkvn_prot = 1.0F ; } void hfht11bpny_prot ( real32_T * ablfaupoa1_prot
, real32_T * c4055nm4ha_prot , real32_T * anjodj4p10_prot , eecdzbdy4h_prot *
localDW ) { if ( localDW -> agrp4pznno_prot ) { * ablfaupoa1_prot = 0.0F ; *
c4055nm4ha_prot = 0.0F ; * anjodj4p10_prot = 0.0F ; localDW ->
agrp4pznno_prot = false ; } } void currentloop ( const boolean_T *
dx5twtfaj1_prot , const real32_T * g0kc3lf3k2_prot , const real32_T *
lhdml3qurj_prot , const real32_T * phajihi5pl_prot , const real32_T *
curvlprlty_prot , const real32_T * ipulsorr5k_prot , const real32_T *
kn0nyw5rqu_prot , const real32_T * j1e5ahzrxt_prot , const real32_T *
grdf2hyssv_prot , const real32_T * dv5ah5hnr3_prot , const real32_T *
af3fdld3p1_prot , const real32_T * hmysd4buyu_prot , const real32_T *
lagofzuydb_prot , const real32_T * outkdzut0o_prot , const real32_T *
hlgxepltlp_prot , const real32_T * pbu5rgpeio_prot , const real32_T *
efiw2l4h5s_prot , real32_T * ablfaupoa1_prot , real32_T * c4055nm4ha_prot ,
real32_T * anjodj4p10_prot , real32_T * fpcygfl5hi_prot , real32_T *
ep4bto1myn_prot , eecdzbdy4h_prot * localDW ) { if ( * dx5twtfaj1_prot ) {
real32_T dbey34uwhv_prot ; real32_T fuqnuu3wuf_prot ; real32_T
fwbq4us1i4_prot ; real32_T gojwrpcjqi_prot ; real32_T ilqhubgjyb_prot ;
real32_T iwyydactx4_prot ; real32_T kjp05vro0g_prot ; real32_T
lxlzb0zl2t_prot ; real32_T mmkz0k012h_prot ; real32_T nio3dtxygv_prot ;
real32_T ogmu4wrfjf_prot ; real32_T okjwilq2t2_prot ; if ( ! localDW ->
agrp4pznno_prot ) { localDW -> m1cz2fh5j0_prot = 0.0F ; localDW ->
nbi250g3j3_prot = 0.0F ; localDW -> jtjulypkvn_prot = 1.0F ; localDW ->
kpbvd3h3nq_prot = 0.0F ; localDW -> frb3snwchp_prot = 0.0F ; localDW ->
agrp4pznno_prot = true ; } gojwrpcjqi_prot = - ( * phajihi5pl_prot ) ;
nio3dtxygv_prot = ( ( ( * j1e5ahzrxt_prot ) * gojwrpcjqi_prot ) * ( *
dv5ah5hnr3_prot ) ) * ( * pbu5rgpeio_prot ) ; mmkz0k012h_prot = fmaxf ( 10.0F
, * kn0nyw5rqu_prot ) ; gojwrpcjqi_prot = mmkz0k012h_prot ; fwbq4us1i4_prot =
( 1.73205078F * nio3dtxygv_prot ) / mmkz0k012h_prot ; nio3dtxygv_prot =
1.73205078F * ( * af3fdld3p1_prot ) ; dbey34uwhv_prot = nio3dtxygv_prot /
mmkz0k012h_prot ; fuqnuu3wuf_prot = ( ( dbey34uwhv_prot * ( * lagofzuydb_prot
) ) * ( * j1e5ahzrxt_prot ) ) * ( * ipulsorr5k_prot ) ; iwyydactx4_prot = ( *
phajihi5pl_prot ) - ( * curvlprlty_prot ) ; ilqhubgjyb_prot = ( *
g0kc3lf3k2_prot ) - ( * lhdml3qurj_prot ) ; nio3dtxygv_prot = 1.73205078F * (
* hmysd4buyu_prot ) ; kjp05vro0g_prot = ( nio3dtxygv_prot * ( *
ipulsorr5k_prot ) ) / mmkz0k012h_prot ; switch ( ( ( localDW ->
m1cz2fh5j0_prot <= ( - 1.085F - fwbq4us1i4_prot ) ) << 1 ) + ( localDW ->
m1cz2fh5j0_prot >= ( 1.085F - fwbq4us1i4_prot ) ) ) { case 0 :
okjwilq2t2_prot = ( - ( fuqnuu3wuf_prot * iwyydactx4_prot ) ) + (
ilqhubgjyb_prot * kjp05vro0g_prot ) ; break ; case 1 : okjwilq2t2_prot =
fminf ( 0.0F , ( - ( fuqnuu3wuf_prot * iwyydactx4_prot ) ) + (
ilqhubgjyb_prot * kjp05vro0g_prot ) ) ; break ; default : okjwilq2t2_prot =
fmaxf ( 0.0F , ( - ( fuqnuu3wuf_prot * iwyydactx4_prot ) ) + (
ilqhubgjyb_prot * kjp05vro0g_prot ) ) ; break ; } mmkz0k012h_prot =
okjwilq2t2_prot + localDW -> nbi250g3j3_prot ; if ( mmkz0k012h_prot > (
1.085F - fwbq4us1i4_prot ) ) { okjwilq2t2_prot = 1.085F - fwbq4us1i4_prot ; }
else if ( mmkz0k012h_prot < ( - 1.085F - fwbq4us1i4_prot ) ) {
okjwilq2t2_prot = - 1.085F - fwbq4us1i4_prot ; } else { okjwilq2t2_prot =
mmkz0k012h_prot ; } nio3dtxygv_prot = ( ilqhubgjyb_prot * dbey34uwhv_prot ) +
okjwilq2t2_prot ; if ( nio3dtxygv_prot > ( 1.085F - fwbq4us1i4_prot ) ) { *
fpcygfl5hi_prot = 1.085F - fwbq4us1i4_prot ; } else if ( nio3dtxygv_prot < (
- 1.085F - fwbq4us1i4_prot ) ) { * fpcygfl5hi_prot = - 1.085F -
fwbq4us1i4_prot ; } else { * fpcygfl5hi_prot = nio3dtxygv_prot ; } *
ablfaupoa1_prot = ( * fpcygfl5hi_prot ) + fwbq4us1i4_prot ; fwbq4us1i4_prot =
( sqrtf ( fmaxf ( 0.0F , 1.19028115F - ( ( * ablfaupoa1_prot ) * ( *
ablfaupoa1_prot ) ) ) ) * 0.1F ) + ( localDW -> jtjulypkvn_prot * 0.9F ) ;
okjwilq2t2_prot = fminf ( * outkdzut0o_prot , fwbq4us1i4_prot ) ;
ogmu4wrfjf_prot = ( ( ( * j1e5ahzrxt_prot ) * ( * grdf2hyssv_prot ) ) * ( *
g0kc3lf3k2_prot ) ) * ( * pbu5rgpeio_prot ) ; lxlzb0zl2t_prot = ( ( *
j1e5ahzrxt_prot ) * ( * hlgxepltlp_prot ) ) * ( * efiw2l4h5s_prot ) ;
gojwrpcjqi_prot = ( ( ( 1.41421354F * lxlzb0zl2t_prot ) + ogmu4wrfjf_prot ) *
1.73205078F ) / gojwrpcjqi_prot ; ogmu4wrfjf_prot = okjwilq2t2_prot -
gojwrpcjqi_prot ; lxlzb0zl2t_prot = ( - okjwilq2t2_prot ) - gojwrpcjqi_prot ;
switch ( ( ( localDW -> kpbvd3h3nq_prot <= lxlzb0zl2t_prot ) << 1 ) + (
localDW -> kpbvd3h3nq_prot >= ogmu4wrfjf_prot ) ) { case 0 : okjwilq2t2_prot
= ( ilqhubgjyb_prot * fuqnuu3wuf_prot ) + ( iwyydactx4_prot * kjp05vro0g_prot
) ; break ; case 1 : okjwilq2t2_prot = fminf ( 0.0F , ( ilqhubgjyb_prot *
fuqnuu3wuf_prot ) + ( iwyydactx4_prot * kjp05vro0g_prot ) ) ; break ; default
: okjwilq2t2_prot = fmaxf ( 0.0F , ( ilqhubgjyb_prot * fuqnuu3wuf_prot ) + (
iwyydactx4_prot * kjp05vro0g_prot ) ) ; break ; } fuqnuu3wuf_prot =
okjwilq2t2_prot + localDW -> frb3snwchp_prot ; if ( fuqnuu3wuf_prot >
ogmu4wrfjf_prot ) { okjwilq2t2_prot = ogmu4wrfjf_prot ; } else if (
fuqnuu3wuf_prot < lxlzb0zl2t_prot ) { okjwilq2t2_prot = lxlzb0zl2t_prot ; }
else { okjwilq2t2_prot = fuqnuu3wuf_prot ; } dbey34uwhv_prot = (
iwyydactx4_prot * dbey34uwhv_prot ) + okjwilq2t2_prot ; if ( dbey34uwhv_prot
> ogmu4wrfjf_prot ) { * ep4bto1myn_prot = ogmu4wrfjf_prot ; } else if (
dbey34uwhv_prot < lxlzb0zl2t_prot ) { * ep4bto1myn_prot = lxlzb0zl2t_prot ; }
else { * ep4bto1myn_prot = dbey34uwhv_prot ; } * c4055nm4ha_prot = ( *
ep4bto1myn_prot ) + gojwrpcjqi_prot ; * anjodj4p10_prot = 0.707106769F * ( *
g0kc3lf3k2_prot ) ; localDW -> m1cz2fh5j0_prot = nio3dtxygv_prot ; localDW ->
nbi250g3j3_prot = mmkz0k012h_prot ; localDW -> jtjulypkvn_prot =
fwbq4us1i4_prot ; localDW -> kpbvd3h3nq_prot = dbey34uwhv_prot ; localDW ->
frb3snwchp_prot = fuqnuu3wuf_prot ; } else if ( localDW -> agrp4pznno_prot )
{ * ablfaupoa1_prot = 0.0F ; * c4055nm4ha_prot = 0.0F ; * anjodj4p10_prot =
0.0F ; localDW -> agrp4pznno_prot = false ; } } void nxhg2dhc0l_prot ( const
char_T * * rt_errorStatus , odvbsqiqaa_prot * const lb4zsx2vov_prot ) {
rtmSetErrorStatusPointer ( lb4zsx2vov_prot , rt_errorStatus ) ; }
