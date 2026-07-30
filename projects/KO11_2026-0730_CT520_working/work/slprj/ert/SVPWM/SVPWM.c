#include "SVPWM.h"
#include "rtwtypes.h"
#include "SVPWM_types.h"
#include <string.h>
#include <math.h>
#include "SVPWM_private.h"
#include "look1_iflf_pbinlca.h"
void kxj4bmtjtf_prot ( Duty * mnr0dzkazo_prot , naznc13ph2_prot * localDW ) {
if ( localDW -> bdaxwpwnni_prot ) { memset ( mnr0dzkazo_prot , 0 , sizeof (
Duty ) ) ; localDW -> bdaxwpwnni_prot = false ; } } void SVPWM ( const
boolean_T * dhgvp1s5vg_prot , const real32_T * jhpssbao2p_prot , const
real32_T * fqb2ggdc3a_prot , const uint16_T * h02v2jwzw3_prot , const
uint16_T * mda52bhutz_prot , Duty * mnr0dzkazo_prot , real32_T *
bnsvj5idlz_prot , real32_T * cgldeb23l4_prot , real32_T * bqycvnd5k0_prot ,
naznc13ph2_prot * localDW ) { if ( * dhgvp1s5vg_prot ) { int32_T
avsneesujh_prot ; real32_T hjyximx2vj_prot ; real32_T jt21qdqxjs_prot ;
real32_T klijse321x_prot ; real32_T ogismvpvhk_prot ; uint16_T
hm41j0aqg0_prot ; uint16_T lqp1paytes_prot ; localDW -> bdaxwpwnni_prot =
true ; klijse321x_prot = ( * fqb2ggdc3a_prot ) * ( * fqb2ggdc3a_prot ) ;
hjyximx2vj_prot = ( * jhpssbao2p_prot ) * ( * jhpssbao2p_prot ) ;
jt21qdqxjs_prot = * fqb2ggdc3a_prot ; ogismvpvhk_prot = * jhpssbao2p_prot ;
lqp1paytes_prot = ( uint16_T ) ( ( ( uint32_T ) ( ( uint16_T ) ( ( int16_T )
floorf ( 10430.3779F * atan2f ( jt21qdqxjs_prot , ogismvpvhk_prot ) ) ) ) ) +
( * h02v2jwzw3_prot ) ) ; hm41j0aqg0_prot = ( uint16_T ) ( lqp1paytes_prot /
10923U ) ; avsneesujh_prot = ( uint16_T ) ( lqp1paytes_prot - ( 10923U *
hm41j0aqg0_prot ) ) ; hjyximx2vj_prot = fminf ( sqrtf ( klijse321x_prot +
hjyximx2vj_prot ) , 1.1F ) ; if ( hjyximx2vj_prot > 1.04897058F ) {
klijse321x_prot = 9.58738E-5F * ( ( real32_T ) avsneesujh_prot ) ;
jt21qdqxjs_prot = look1_iflf_pbinlca ( hjyximx2vj_prot , lh1z2bl0vq_prot .
lrednyufpy_prot , lh1z2bl0vq_prot . dvolktf12c_prot , & localDW ->
lz1au2gg5h_prot , 55U ) ; switch ( ( ( klijse321x_prot <= jt21qdqxjs_prot )
<< 1 ) + ( klijse321x_prot >= ( 1.04719758F - jt21qdqxjs_prot ) ) ) { case 0
: klijse321x_prot = ( ( klijse321x_prot - jt21qdqxjs_prot ) * 0.52359879F ) /
( 0.52359879F - jt21qdqxjs_prot ) ; break ; case 1 : klijse321x_prot =
1.04719758F ; break ; default : klijse321x_prot = 0.0F ; break ; } if (
klijse321x_prot > 1.04719758F ) { klijse321x_prot = 1.04719758F ; } else if (
klijse321x_prot < 0.0F ) { klijse321x_prot = 0.0F ; } jt21qdqxjs_prot =
10430.3779F * klijse321x_prot ; } else { jt21qdqxjs_prot = ( real32_T )
avsneesujh_prot ; } if ( hjyximx2vj_prot > 1.0F ) { hjyximx2vj_prot =
look1_iflf_pbinlca ( hjyximx2vj_prot , lh1z2bl0vq_prot . lcsru3ykfm_prot ,
lh1z2bl0vq_prot . lncqiwd3yw_prot , & localDW -> ok50tsgxad_prot , 97U ) ; }
klijse321x_prot = sinf ( 9.58738E-5F * jt21qdqxjs_prot ) * hjyximx2vj_prot ;
hjyximx2vj_prot *= sinf ( ( ( real32_T ) ( ( uint16_T ) ( 10923U - ( (
uint16_T ) jt21qdqxjs_prot ) ) ) ) * 9.58738E-5F ) ; jt21qdqxjs_prot =
klijse321x_prot + hjyximx2vj_prot ; if ( jt21qdqxjs_prot <= 1.0F ) {
ogismvpvhk_prot = 1.0F - jt21qdqxjs_prot ; } else { ogismvpvhk_prot = 0.0F ;
klijse321x_prot /= jt21qdqxjs_prot ; hjyximx2vj_prot /= jt21qdqxjs_prot ; }
switch ( hm41j0aqg0_prot ) { case 0 : jt21qdqxjs_prot = 1.0F - ( 0.5F *
ogismvpvhk_prot ) ; * bnsvj5idlz_prot = jt21qdqxjs_prot ; jt21qdqxjs_prot -=
hjyximx2vj_prot ; * cgldeb23l4_prot = jt21qdqxjs_prot ; * bqycvnd5k0_prot =
jt21qdqxjs_prot - klijse321x_prot ; break ; case 1 : jt21qdqxjs_prot = 1.0F -
( 0.5F * ogismvpvhk_prot ) ; klijse321x_prot = jt21qdqxjs_prot -
klijse321x_prot ; * bnsvj5idlz_prot = klijse321x_prot ; * cgldeb23l4_prot =
jt21qdqxjs_prot ; * bqycvnd5k0_prot = klijse321x_prot - hjyximx2vj_prot ;
break ; case 2 : jt21qdqxjs_prot = 1.0F - ( 0.5F * ogismvpvhk_prot ) ; *
cgldeb23l4_prot = jt21qdqxjs_prot ; jt21qdqxjs_prot -= hjyximx2vj_prot ; *
bqycvnd5k0_prot = jt21qdqxjs_prot ; * bnsvj5idlz_prot = jt21qdqxjs_prot -
klijse321x_prot ; break ; case 3 : jt21qdqxjs_prot = 1.0F - ( 0.5F *
ogismvpvhk_prot ) ; klijse321x_prot = jt21qdqxjs_prot - klijse321x_prot ; *
cgldeb23l4_prot = klijse321x_prot ; * bqycvnd5k0_prot = jt21qdqxjs_prot ; *
bnsvj5idlz_prot = klijse321x_prot - hjyximx2vj_prot ; break ; case 4 :
jt21qdqxjs_prot = 1.0F - ( 0.5F * ogismvpvhk_prot ) ; hjyximx2vj_prot =
jt21qdqxjs_prot - hjyximx2vj_prot ; * bnsvj5idlz_prot = hjyximx2vj_prot ; *
bqycvnd5k0_prot = jt21qdqxjs_prot ; * cgldeb23l4_prot = hjyximx2vj_prot -
klijse321x_prot ; break ; default : jt21qdqxjs_prot = 1.0F - ( 0.5F *
ogismvpvhk_prot ) ; * bnsvj5idlz_prot = jt21qdqxjs_prot ; jt21qdqxjs_prot -=
klijse321x_prot ; * bqycvnd5k0_prot = jt21qdqxjs_prot ; * cgldeb23l4_prot =
jt21qdqxjs_prot - hjyximx2vj_prot ; break ; } hjyximx2vj_prot = fminf ( 1.0F
, * bqycvnd5k0_prot ) ; if ( ( * mda52bhutz_prot ) > 0 ) { klijse321x_prot =
fminf ( 1.0F , * cgldeb23l4_prot ) ; } else { klijse321x_prot =
hjyximx2vj_prot ; hjyximx2vj_prot = fminf ( 1.0F , * cgldeb23l4_prot ) ; }
jt21qdqxjs_prot = fminf ( 1.0F , * bnsvj5idlz_prot ) ; if ( jt21qdqxjs_prot <
0.0F ) { mnr0dzkazo_prot -> f32_DutyUon = 0.0F ; } else { mnr0dzkazo_prot ->
f32_DutyUon = jt21qdqxjs_prot ; } if ( klijse321x_prot < 0.0F ) {
mnr0dzkazo_prot -> f32_DutyVon = 0.0F ; } else { mnr0dzkazo_prot ->
f32_DutyVon = klijse321x_prot ; } if ( hjyximx2vj_prot < 0.0F ) {
mnr0dzkazo_prot -> f32_DutyWon = 0.0F ; } else { mnr0dzkazo_prot ->
f32_DutyWon = hjyximx2vj_prot ; } } else if ( localDW -> bdaxwpwnni_prot ) {
memset ( mnr0dzkazo_prot , 0 , sizeof ( Duty ) ) ; localDW -> bdaxwpwnni_prot
= false ; } } void bcegzfkptw_prot ( const char_T * * rt_errorStatus ,
i10oedhb1z_prot * const fp14zyuwlg_prot ) { rtmSetErrorStatusPointer (
fp14zyuwlg_prot , rt_errorStatus ) ; }
