#include "look1_iflf_pbinlca.h"
#include "rtwtypes.h"
real32_T look1_iflf_pbinlca ( real32_T u0_prot , const real32_T bp0_prot [ ]
, const real32_T table_prot [ ] , uint32_T prevIndex_prot [ ] , uint32_T
maxIndex_prot ) { real32_T frac_prot ; real32_T y_prot ; uint32_T bpIdx_prot
; if ( u0_prot <= bp0_prot [ 0U ] ) { bpIdx_prot = 0U ; frac_prot = 0.0F ; }
else if ( u0_prot < bp0_prot [ maxIndex_prot ] ) { uint32_T found_prot ;
uint32_T iLeft_prot ; uint32_T iRght_prot ; bpIdx_prot = prevIndex_prot [ 0U
] ; iLeft_prot = 0U ; iRght_prot = maxIndex_prot ; found_prot = 0U ; while (
found_prot == 0U ) { if ( u0_prot < bp0_prot [ bpIdx_prot ] ) { iRght_prot =
bpIdx_prot - 1U ; bpIdx_prot = ( ( ( bpIdx_prot + iLeft_prot ) - 1U ) >> 1U )
; } else if ( u0_prot < bp0_prot [ bpIdx_prot + 1U ] ) { found_prot = 1U ; }
else { iLeft_prot = bpIdx_prot + 1U ; bpIdx_prot = ( ( ( bpIdx_prot +
iRght_prot ) + 1U ) >> 1U ) ; } } frac_prot = ( u0_prot - bp0_prot [
bpIdx_prot ] ) / ( bp0_prot [ bpIdx_prot + 1U ] - bp0_prot [ bpIdx_prot ] ) ;
} else { bpIdx_prot = maxIndex_prot ; frac_prot = 0.0F ; } prevIndex_prot [
0U ] = bpIdx_prot ; if ( bpIdx_prot == maxIndex_prot ) { y_prot = table_prot
[ bpIdx_prot ] ; } else { real32_T yL_0d0_prot ; yL_0d0_prot = table_prot [
bpIdx_prot ] ; y_prot = ( ( table_prot [ bpIdx_prot + 1U ] - yL_0d0_prot ) *
frac_prot ) + yL_0d0_prot ; } return y_prot ; }
