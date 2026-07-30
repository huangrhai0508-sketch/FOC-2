#ifndef _DSMIFC_H
#define _DSMIFC_H

#include "dsm.h"

extern void SetDFC(bool inh, bool xactive,uint16 idx, uint32 debounceTime);
extern void ClrDFC(uint16 idx);
extern bool Fid_xActive(uint16 idx);
extern void XxxDiag_Test_10ms_proc(void);

#endif
