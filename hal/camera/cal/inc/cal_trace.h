/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cal_trace.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   CAL Trace interface
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _CAL_TRACE_H
#define _CAL_TRACE_H

#include <stdarg.h>
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "kal_trace.h"
#include "drv_trc.h"
#include "cal_api.h"
#include "cal_drv_features.h"

#define  CAL_TRACE_ERROR    TRACE_GROUP_1
#define  CAL_TRACE_FLOW     TRACE_GROUP_2
#define  CAL_TRACE_CBF      TRACE_GROUP_3
#define  CAL_TRACE_REQUEST  TRACE_GROUP_4
#define  CAL_TRACE_WEBCAM   TRACE_GROUP_5

#ifdef __CAL_TRACE_ENABLE__
#define CAL_TRACE_ERROR_ENUM 	MM_ERROR_CODE_ENUM

#define CAL_TRACE_CBF_ENUM 		CAL_CALLBACK_ID_ENUM

typedef enum
{
    CAL_TRACE_FLOW_NONE		=	0,
    CAL_TRACE_FLOW_INIT,
    CAL_TRACE_FLOW_OPEN,
   	CAL_TRACE_FLOW_CTRL,
   	CAL_TRACE_FLOW_CLOSE,
   	CAL_TRACE_FLOW_DEINIT,
   	CAL_TRACE_FLOW_ALL		= 0xFFFF
}CAL_TRACE_FLOW_ENUM;

typedef enum
{
    CAL_TRACE_REQUEST_NONE			=	0,
    CAL_TRACE_REQUEST_DUMP,
    CAL_TRACE_REQUEST_STATE,
    CAL_TRACE_REQUEST_PROFILING,
   	CAL_TRACE_REQUEST_ENABLE,
   	CAL_TRACE_REQUEST_DISABLE,
   	CAL_TRACE_REQUEST_MAX
}CAL_TRACE_ONDEMAND_ENUM;

#define CalTrace0(TraceClass,MsgIndex,fmt)	\
{\
if(kal_if_hisr())\
  {\
    kal_dev_trace(TraceClass,MsgIndex,fmt);\
  }\
  else\
  {\
    kal_trace(TraceClass,MsgIndex,fmt);\
  }\
}

#define CalTrace(TraceClass,MsgIndex,fmt,...)	\
{\
if(kal_if_hisr())\
  {\
    kal_dev_trace(TraceClass,MsgIndex,fmt,##__VA_ARGS__);\
  }\
  else\
  {\
    kal_trace(TraceClass,MsgIndex,fmt,##__VA_ARGS__);\
  }\
}

void CalOnDemandTrace(kal_uint32 TraceFeatureId,kal_uint32 TraceFeatureCode);		//Do trace in the request

#define CalErrorTrace(Errorcode)\
	if (MM_ERROR_NONE != Errorcode) CalTrace(CAL_TRACE_ERROR,CAL_ERROR,Errorcode);

#else
#define CalTrace0(TraceClass,MsgIndex,fmt) 
#define CalTrace(TraceClass,MsgIndex,fmt,...) 
#define CalErrorTrace(Errorcode) 
void CalOnDemandTrace(kal_uint32 TraceFeatureId,kal_uint32 TraceFeatureCode);
#endif
#endif /* _CAL_TRACE_H */