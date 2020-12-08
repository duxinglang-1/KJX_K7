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
 * Filename: 
 * --------- 
 *  DebugInit.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : DebugInit.c

   PURPOSE     : To put all trace related functionality in common place

   REMARKS     : nil

   AUTHOR      : Vijay Vaidya

   DATE     : Sep' 4, 2002

**************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/
//#include "MMI_include.h"
#include "MMI_trc.h"
//#include "gv.h"

//RHR Add
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_config.h"
//#include "kal_active_module.h"
#include "kal_trace.h"
#include "stdarg.h"
#include "mmi_frm_gprot.h"
#include "kal_public_api.h"
#include "stdio.h"
#include "DebugInitDef_Int.h"
#include "mmi_fw_trc.h"
#include "Unicodexdcl.h"
#include "mmi_common_app_trc.h"
#include "mmi_media_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "mmi_inet_app_trc.h"
#include "mmi_trc.h"

/*****************************************************************************
* Global Variable
*****************************************************************************/
kal_mutexid mmi_mutex_trace;

/*****************************************************************************
* Extern Global Variable
*****************************************************************************/
extern kal_bool  tst_ft_mode;
extern kal_uint8 tst_module_filter_g[];
extern kal_uint8 tst_trace_filter_g[];

/*****************************************************************************
* Define
*****************************************************************************/
#define TRACE_MUTEX_BEGIN        kal_take_mutex(mmi_mutex_trace);
#define TRACE_MUTEX_END          kal_give_mutex(mmi_mutex_trace);


/*****************************************************************************
 * FUNCTION
 *  DebugInit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DebugInit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  kal_disable_trace
 * DESCRIPTION
 *  To display/print to the debug trace window/file
 * PARAMETERS
 *  mod_id          [IN]        
 *  trc_class       [IN]        
 *  Variable(?)     [IN]        Arguments with format being the first one
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL kal_disable_trace(module_type mod_id, trace_class_enum trc_class)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tmp_filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tst_ft_mode == KAL_TRUE)
    {
        return MMI_TRUE;
    }

    if ((tst_module_filter_g[mod_id / 8] & (0x01 << (mod_id % 8))) == 0)
    {
        return MMI_TRUE;
    }

    tmp_filter = (tst_trace_filter_g[mod_id * 2]) + (tst_trace_filter_g[mod_id * 2 + 1] << 8);

    if ((tmp_filter & (0x01 << trc_class)) == 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  Trace2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void Trace2(U32 fmt, S8 *arg_type, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  Trace3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Trace3(U32 fmt, U32 arg_type, ...)
{
}


/*****************************************************************************
 * FUNCTION
 *  Trace
 * DESCRIPTION
 *  To display/print to the debug trace window/file
 * PARAMETERS
 *  fmt             [?]         
 *  Variable(?)     [IN]        Arguments with format being the first one
 * RETURNS
 *  void
 *****************************************************************************/
void Trace(S8 *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  Trace_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt             [IN]        
 *  arg_type        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_print_trace(module_type mod_id, U32 trc_group, S8 *arg_type, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wprintf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mod_id          [IN]        
 *  fmt             [IN]        
 *  wstr            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wprintf(module_type mod_id, U32 fmt, WCHAR *wstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * MMI_FW_BUFFER_TRACE, MMI_COMMON_APP_BUFFER_TRACE, MMI_MEDIA_APP_BUFFER_TRACE, ...
     * will expand to xxxxx__enum, xxxxx_size when compile the C files
     */
    switch (mod_id)
    {
    case MOD_MMI_FW:
        kal_buffer_trace((trace_class_enum)fmt, MMI_FW_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_COMMON_APP:
        kal_buffer_trace((trace_class_enum)fmt, MMI_COMMON_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_MEDIA_APP:
        kal_buffer_trace((trace_class_enum)fmt, MMI_MEDIA_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_CONN_APP:
        kal_buffer_trace((trace_class_enum)fmt, MMI_CONN_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    case MOD_MMI_INET_APP:
        kal_buffer_trace((trace_class_enum)fmt, MMI_INET_APP_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
        break;
    default:
        kal_buffer_trace((trace_class_enum)fmt, MMI_BUFFER_TRACE, (mmi_ucs2strlen((S8 *)wstr)+1)*ENCODING_LENGTH, (kal_uint8*)wstr);
    }
}

