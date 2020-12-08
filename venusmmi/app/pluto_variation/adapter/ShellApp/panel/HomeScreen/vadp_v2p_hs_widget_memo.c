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
 *  vadp_v2p_hs_widget_memo.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of memo widget from Venus MMI to PlutoMMI.
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
 *============================================================================
 ****************************************************************************/

/**********************************************************************
 * Include
 **********************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_MEMO__

/* Pluto headers: */
#include "nvram_common_defs.h"
#include "FSEditorCuiGprot.h"
#include "gui_effect_oem.h"

/* Venus headers: */

#include "MMIDataType.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_venus_homescreen_wg_memo_def.h"
#include "ImeGprot.h"
#include "vfx_datatype.h"

/**********************************************************************
 * Define
 **********************************************************************/
#define MAX_MEMO_BUF      NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE


/**********************************************************************
 * Global variables
 **********************************************************************/
static U8 g_vadp_v2p_hs_widget_memo_buffer[MAX_MEMO_BUF] = {0};



/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_save_nvram
 * DESCRIPTION
 *  save buffer data to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_memo_save_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID,
        1,
        g_vadp_v2p_hs_widget_memo_buffer,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_read_nvram
 * DESCRIPTION
 *  read data to buffer from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_memo_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID, 
        1, 
        g_vadp_v2p_hs_widget_memo_buffer, 
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE, 
        &error);

    // force null terminated
    g_vadp_v2p_hs_widget_memo_buffer[MAX_MEMO_BUF - 1] = g_vadp_v2p_hs_widget_memo_buffer[MAX_MEMO_BUF - 2] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_proc
 * DESCRIPTION
 *  proc function of memo widget
 * PARAMETERS
 *  evt	[IN] event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret vadp_v2p_hs_memo_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(editor_evt->evt_id)
    {
		case EVT_ID_CUI_FSEDITOR_SUBMMIT:
			cui_fseditor_get_text(editor_evt->sender_id, (WCHAR *)g_vadp_v2p_hs_widget_memo_buffer, MAX_MEMO_BUF);
			vadp_v2p_hs_memo_save_nvram();
		case EVT_ID_CUI_FSEDITOR_ABORT:
			cui_fseditor_close(editor_evt->sender_id);
			break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_entry_setting_int
 * DESCRIPTION
 *  entry full screen edit for memo content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_memo_entry_setting_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id grp_id, sub_grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vadp_v2p_hs_memo_proc, NULL);
	if (grp_id != GRP_ID_INVALID)
	{
		mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
		sub_grp =  cui_fseditor_create(grp_id);
		if (sub_grp != GRP_ID_INVALID)
		{
			cui_fseditor_set_title(sub_grp, VAPP_HS_STR_WG_MEMO_EDIT_TITLE, VAPP_HS_IMG_WG_MEMO_EDIT_TITLE);
			cui_fseditor_set_text(sub_grp, (WCHAR*) g_vadp_v2p_hs_widget_memo_buffer, MAX_MEMO_BUF, (MAX_MEMO_BUF/ENCODING_LENGTH) - 1);
			cui_fseditor_set_input_method(sub_grp, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
			cui_fseditor_run(sub_grp);
		}
		else
		{
			mmi_frm_group_close(grp_id);
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_entry_setting
 * DESCRIPTION
 *  entry full screen edit for memo content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_memo_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    vadp_v2p_hs_memo_entry_setting_int();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_memo_get_text
 * DESCRIPTION
 *  get text of memo widget
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxWChar*
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_memo_get_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_hs_memo_read_nvram();

    return (VfxWChar*)g_vadp_v2p_hs_widget_memo_buffer;
}

#endif /* __MMI_VUI_HOMESCREEN_MEMO__ */

