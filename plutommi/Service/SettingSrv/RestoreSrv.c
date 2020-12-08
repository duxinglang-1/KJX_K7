/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  RestoreSrv.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_include.h"
#include "MMIDataType.h"
#include "RestoreSrvGprot.h"
#include "mmi_rp_srv_restore_def.h"
//#include "mmi_frm_events_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
static srv_restore_callback_func g_srv_restore_callback;
static srv_restore_table_struct*g_srv_restore_table;
static U16 g_srv_restore_process_id;
static void srv_restore_process(void);
static void srv_restore_error_rsp(void);
/***************************************************************************** 
 * Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_restore_start
 * DESCRIPTION
 *  Perform factory restore according to the input table 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_restore_start(srv_restore_table_struct *table, srv_restore_callback_func callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[RestoreSrv.c] srv_restore_start()");
    if (callback)
	{
	    g_srv_restore_callback = callback;
	}
    if (table)
	{
        mmi_event_struct evt;
	    g_srv_restore_table = table;
        g_srv_restore_process_id = 0;
    	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_RESTORE_START_NOTIFY);
    	MMI_FRM_CB_EMIT_EVENT(&evt);

        srv_restore_process();
	}
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_restore_process
 * DESCRIPTION
 *  Process restore according to id and table 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_restore_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_srv_restore_table);
    while (g_srv_restore_table[g_srv_restore_process_id].process_func != NULL)
	{
	    switch (g_srv_restore_table[g_srv_restore_process_id].process_func())
	    {
	    case SRV_RESTORE_HOLD:         
                MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[RestoreSrv.c] srv_restore_process() id %d hold", g_srv_restore_process_id);
                return;

            case SRV_RESTORE_ERROR:
                srv_restore_error_rsp();
                return;

	    case SRV_RESTORE_OK:
	    default:
		g_srv_restore_process_id++;
                break;
	    }
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_restore_error_rsp
 * DESCRIPTION
 *  If there is error, the input callback will be called 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_restore_error_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[RestoreSrv.c] srv_restore_error_rsp()");
    if (g_srv_restore_callback)
	{
	    (*g_srv_restore_callback)(MMI_FALSE);
        g_srv_restore_callback = NULL;        
        g_srv_restore_table = NULL;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_restore_process_callback
 * DESCRIPTION
 *  When the APP finish its a-sync restore operation, this API should be 
 *  called to notify the restore service to continue factory restore 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_restore_process_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[RestoreSrv.c] srv_restore_process_callback() id %d", g_srv_restore_process_id);
    g_srv_restore_process_id++;
    srv_restore_process();
} 
