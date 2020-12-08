/******************************************************************* 
* Copyright (c) 2011 by Hesine Technologies, Inc. 
* All rights reserved. 
* 
* This file is proprietary and confidential to Hesine Technologies. 
* No part of this file may be reproduced, stored, transmitted, 
* disclosed or used in any form or by any means other than as 
* expressly provided by the written permission from Jianhui Tao 
* 
*******************************************************************/

#ifndef _hpns_util_header_
#define _hpns_util_header_

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "pns_trc.h"

int  hpnsInitLog(void); 
void nprintf (char *format,...);
void hpnsdump(char *msg, int len);
int hpnsByteArrayToHexStr(char bytes[], int bytesLen);

#define HPNS_TRACE0(tr)                  kal_trace(TRACE_GROUP_7, tr)
#define HPNS_TRACE1(tr, a1)              kal_trace(TRACE_GROUP_7, tr, a1)
#define HPNS_TRACE2(tr, a1, a2)          kal_trace(TRACE_GROUP_7, tr, a1, a2)
#define HPNS_TRACE3(tr, a1, a2, a3)      kal_trace(TRACE_GROUP_7, tr, a1, a2, a3)
#define HPNS_TRACE4(tr, a1, a2, a3, a4)  kal_trace(TRACE_GROUP_7, tr, a1, a2, a3, a4)
#define HPNS_TRACE5(tr, a1, a2, a3, a4, a5)  kal_trace(TRACE_GROUP_7, tr, a1, a2, a3, a4, a5)
#define HPNS_TRACE6(tr, a1, a2, a3, a4, a5, a6)  kal_trace(TRACE_GROUP_7, tr, a1, a2, a3, a4, a5, a6)


#endif

