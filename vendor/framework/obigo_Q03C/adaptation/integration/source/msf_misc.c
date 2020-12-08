#ifdef Q03C_IND_MOD_ARCH_SUPPORT
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * msf_misc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for miscellaneous adapter functions of Mobile Suite Framework
 *   , including memory management, logging, time information, WTAI function etc.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#define _FILE_CODE_  _MSF_MISC_C_

#include "kal_public_api.h"        /* Basic data type */

#include "kal_public_defs.h"
#include "stack_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

#include "kal_public_api.h"
#include "stack_buff_alloc.h"

#include "kal_trace.h"
#include "gv.h"
#include "tst_def.h"

#include "dcl.h"
#include "dcl_rtc.h"
#include "app_datetime.h"

#include <stdarg.h>
#include <time.h>

#include "msf_int.h"
#include "msf_lib.h"
#include "msf_cfg.h"
#include "msf_act.h"
#include "msf_env.h"
#include "msm_int.h"
#include "msm_env.h"
#include "stk_if.h"
#include "WguiCategoryGprot.h"
#include "PhoneBookgprot.h"
#include "msf_log.h"
#include "msf_url.h"

#ifdef __MTK_TARGET__
#define  HDI_MSG_LOG
#endif 

typedef float FLOAT;
typedef unsigned char U8;
extern FLOAT GetTimeZone(U8 cityIndex);
extern U8 PhnsetGetHomeCity(void);

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
#define PRINTVALUE_HEAD (0xbbbbbbbb)
#define PRINTVALUE_TAIL (0xcccccccc)
#define PRINTVALUE_HEAD_FREED (0xdddddddd)
#define PRINTVALUE_TAIL_FREED (0xeeeeeeee)
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 

#ifndef __MTK_TARGET__
static kal_uint16 log_mod_mask = 0xffff;
#else 
static kal_uint16 log_mod_mask = 0x0000;
#endif 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/**********************************************************************
 * HDI Misc
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_telMakeCall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_telMakeCall(MSF_UINT8 modId, MSF_UINT16 telId, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    BRAif_telMakeCall(modId, telId, number);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_telSendDtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  telId       [IN]        
 *  dtmf        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_telSendDtmf(MSF_UINT8 modId, MSF_UINT16 telId, const char *dtmf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //BRAif_telSendDtmf(modId, telId, dtmf);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_pbAddEntry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  pbId        [IN]        
 *  name        [IN]        
 *  number      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_pbAddEntry(MSF_UINT8 modId, MSF_UINT16 pbId, const char *name, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef MSF_MODID_BRA
    if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM) >= srv_phb_get_total_contact(PHB_STORAGE_NVRAM))
    {
        HDIc_pbAddEntryResponse(modId, pbId, HDI_PB_ERROR_PHONE_BOOK_IS_FULL);
        BRAif_showDialog(MsfFailure, BRA_STR_ERR_PHONEBOOK_FULL);
        return;
    }
    BRAif_pbAddEntry(modId, pbId, name, number);
#endif
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_TARGET__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  HDIa_timeLocalToUTC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_time      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT32 HDIa_timeLocalToUTC(MSF_UINT32 local_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_dt_sec_local_to_utc(local_time);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef WAP_USE_ASM
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MSF_LOG_MEMORY
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef WAP_USE_ASM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAP_USE_ASM */ 
/* under construction !*/
#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
/* under construction !*/
#endif 
/* under construction !*/
#ifdef WAP_USE_ASM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAP_USE_ASM */ 
#ifdef MMS_V01_USE_ASM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*MMS_V01_USE_ASM*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef WPS_TASK_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* WPS_TASK_SUPPORT */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef WAP_USE_ASM
/* under construction !*/
    #endif 
/* under construction !*/
#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK) */ 
/* under construction !*/
#ifdef WAP_USE_ASM
/* under construction !*/
/* under construction !*/
    #ifndef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
    #ifndef __MTK_TARGET__
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif /* WAP_USE_ASM */ 
#ifdef MMS_V01_USE_ASM
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*MMS_V01_USE_ASM*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MSF_LOG_MEM_ALLOC
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MSF_LOG_MEM_ALLOC
/* under construction !*/
#else
/* under construction !*/
#endif    
/* under construction !*/
#endif
#ifdef MSF_CONFIG_INTERNAL_MALLOC


/*****************************************************************************
 * FUNCTION
 *  HDIa_memInternalInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void *HDIa_memInternalInit(MSF_UINT8 modId, MSF_UINT32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;
}
#endif /* MSF_CONFIG_INTERNAL_MALLOC */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __WAP_PUSH_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  set_log_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inject_str      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void set_log_filter(tst_inject_string_struct *inject_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr((const char*)inject_str->string, "MSM"))
    {
        mask |= (0x0001 << MSF_MODID_MSM);
    }
    if (strstr((const char*)inject_str->string, "STK"))
    {
        mask |= (0x0001 << MSF_MODID_STK);
    }
#ifdef BROWSER_SUPPORT    
    if (strstr((const char*)inject_str->string, "BRS"))
    {
        mask |= (0x0001 << MSF_MODID_BRS);
    }
#endif	    
   /* if (strstr((const char*)inject_str->string, "BRA"))
    {
        mask |= (0x0001 << MSF_MODID_BRA);
    }*/
   #ifdef __WAP_PUSH_SUPPORT__
    if (strstr((const char*)inject_str->string, "PHS"))
    {
        mask |= (0x0001 << MSF_MODID_PHS);
    }
   #endif 
	/*
    if (strstr((const char*)inject_str->string, "UIS"))
    {
        mask |= (0x0001 << MSF_MODID_UIS);
    }
	*/
#ifdef MSF_MODID_PRS
    if (strstr((const char*)inject_str->string, "PRS"))
    {
        mask |= (0x0001 << MSF_MODID_PRS);
    }
#endif
#ifdef WAP_SEC_SUPPORT
    if (strstr((const char*)inject_str->string, "SEC"))
    {
        mask |= (0x0001 << MSF_MODID_SEC);
    }
#endif /* WAP_SEC_SUPPORT */ 
#ifdef OBIGO_Q03C_MMS_V01
    if (strstr((const char*)inject_str->string, "MMS"))
    {
        mask |= (0x0001 << MSF_MODID_MMS);
    }
    if (strstr((const char*)inject_str->string, "MEA"))
    {
        mask |= (0x0001 << MSF_MODID_MEA);
    }
    if (strstr((const char*)inject_str->string, "SLS"))
    {
        mask |= (0x0001 << MSF_MODID_SLS);
    }
    if (strstr((const char*)inject_str->string, "SMA"))
    {
        mask |= (0x0001 << MSF_MODID_SMA);
    }
#endif /* OBIGO_Q03C_MMS_V01 */ 
    if (strstr((const char*)inject_str->string, "MIB"))
    {
        mask |= (0x0001 << MSF_MODID_MSM)
            | (0x0001 << MSF_MODID_STK)
		#ifdef BROWSER_SUPPORT            
            | (0x0001 << MSF_MODID_BRS)
		#endif            
            //| (0x0001 << MSF_MODID_BRA)
          //  | (0x0001 << MSF_MODID_PHS) | (0x0001 << MSF_MODID_UIS)
    #ifdef MSF_MODID_PRS
            | (0x0001 << MSF_MODID_PRS)
    #endif
    #ifdef WAP_SEC_SUPPORT
            | (0x0001 << MSF_MODID_SEC)
    #endif 
            ;
    }
#ifdef OBIGO_Q03C_MMS_V01
    if (strstr((const char*)inject_str->string, "MM"))
    {
        mask |= (0x0001 << MSF_MODID_MSM)
            | (0x0001 << MSF_MODID_STK)
    #ifdef MSF_MODID_PRS
            | (0x0001 << MSF_MODID_PRS)
    #endif
    #ifdef WAP_SEC_SUPPORT
            | (0x0001 << MSF_MODID_SEC)
    #endif 
            | (0x0001 << MSF_MODID_MMS)
            | (0x0001 << MSF_MODID_MEA) | (0x0001 << MSF_MODID_SLS) | (0x0001 << MSF_MODID_SMA);
    }
#endif /* OBIGO_Q03C_MMS_V01 */ 
    if (strstr((const char*)inject_str->string, "ALL"))
    {
        mask = 0xffff;
    }

    /* reset */
    if (inject_str->index == 0)
    {
        mask = ~mask;
        log_mod_mask &= mask;
    }
    else
    {
        log_mod_mask |= mask;
    }
}

#if 0
#ifdef __MTK_TARGET__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WAP_MEM_DEBUG_SUPPORT
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef WAP_MEM_DEBUG_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAP_MEM_DEBUG_SUPPORT */ 
/* under construction !*/
#ifdef HDI_MSG_LOG
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WAP_MEM_DEBUG_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* WAP_MEM_DEBUG_SUPPORT */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 1
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/**********************************************************************
 * Object Actions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_objectAction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  action_cmd          [IN]        
 *  mime_type           [IN]        
 *  data_type           [IN]        
 *  data                [IN]        
 *  data_len            [IN]        
 *  src_path            [IN]        
 *  default_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_objectAction(
        const char *action_cmd,
        const char *mime_type,
        MsfResourceType data_type,
        const unsigned char *data,
        MSF_INT32 data_len,
        const char *src_path,
        const char *default_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/**********************************************************************
 * Mime Action table customizable section
 **********************************************************************/
#ifdef MSF_AFI_ETC_ON
const int extern_nbr_of_mime_actions = 1;

const msf_act_mime_action_t msf_act_mime_action_table[] = 
{
  { "*/*",
    MSF_PACKET_OPERATION_ID_SAS,
    0,
    MSF_STR_ID_MIME_ACTION_SAVE,
    MSF_MIME_ACTION_TYPE_PACKET,
    -1,
    MSF_PERMISSION_NONE_BLOCKED
  }
};
#endif /*MSF_AFI_ETC_ON*/

msf_error_display_fp_t msf_error_display_fp = NULL;

void msf_register_error_display_function(msf_error_display_fp_t fp)
{
    if(!msf_error_display_fp)
        msf_error_display_fp = fp;
}

void msf_display_error(void)
{
    if(msf_error_display_fp)
        msf_error_display_fp();
}


#ifdef MSF_CFG_TRANSCODING_SUPPORT

/*
 * Define URL Filtering ruel:
 * 1. Proper matching of domain.
 * 2. match string in domain name.
 */

#define URL_FILTERING_RULE       2


#if URL_FILTERING_RULE == 1
char* transcoding_domain_black_list = 
{
    "google.com",
    "yahoo.com",
    NULL /*Should be the last entry in this array.*/
}
#elif URL_FILTERING_RULE == 2
char* transcoding_domain_black_list[] = 
{
    MSF_TRANSCODING_URL_BLACK_LIST,
    NULL /*Should be the last entry in this array.*/
};
#endif

MSF_BOOL msf_is_transcoding_allowed(MSF_UINT8 module, const char *url)
#if URL_FILTERING_RULE == 1
{
    int i = 0;
    msf_url_t urlParts;
    int curr_domain_len;
    char *host = NULL;
    int host_len;
    MSF_BOOL ret = TRUE;

    host = msf_url_get_host (module, url);

    if (host == NULL)
	{
      goto END;
    }

    host_len = strlen(host);

    i = 0;
    while(transcoding_domain_black_list[i])
    {
        curr_domain_len = strlen(transcoding_domain_black_list[i]);

        if(curr_domain_len > host_len)
        {
            continue;
        }

        if(msf_cmmn_strncmp_nc(transcoding_domain_black_list[i], host+(host_len-curr_domain_len), curr_domain_len))
        {/*Not Equal*/
            continue;
        }

        if((curr_domain_len == host_len) ||
           (host[host_len-curr_domain_len-1] == '.'))
        {
            ret = FALSE;
            goto END;
        }
    }

END:
    return ret;
}
#elif URL_FILTERING_RULE == 2
{
    char *host = NULL;
    int i;
    MSF_BOOL ret = TRUE;
    char *dmn = NULL;
    char *dmn_start = NULL;
    int dmn_len, host_len;
    int dmn_start_pos, dmn_end_pos;

    
    host = msf_url_get_host (module, url);
    host_len = strlen(host);

    i = 0;
    while(transcoding_domain_black_list[i])
    {
        dmn = transcoding_domain_black_list[i];
        i++;
        dmn_len = strlen(dmn);

        dmn_start = host;

        while(dmn_start)
        {
            dmn_start = strstr(dmn_start, dmn);

            if(dmn_start)
            {
                dmn_start_pos = dmn_start - host;
                dmn_end_pos = dmn_start_pos + dmn_len - 1;
                
                if(dmn_start_pos > 0)
                {
                    if(host[dmn_start_pos - 1] != '.')
                    {
                        dmn_start++;
                        continue;
                    }
                }

                if(dmn_end_pos < host_len-1)
                {
                    if(host[dmn_end_pos + 1] != '.')
                    {
                        dmn_start++;
                        continue;
                    }
                }

                return FALSE;
            }
            else
            {
                break;
            }
        }
    }

    return TRUE;
}
#endif
#endif /*MSF_CFG_TRANSCODING_SUPPORT*/

#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
