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
 *  vapp_nmgr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *    This file is used to provide C-style function for PLUTO NMGR
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
 * removed!
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
#include "vapp_nmgr_gprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/

#define GLOBAL_POPUP_STRUCT_BASE        \
    PopupCallBackPtr       callBack;    \
    void                   *userData;   \
    GpTypeEnum             gpType;      \
    MMI_ID                 parentID;    \
    mmi_scenario_id        scenID;

/***************************************************************************** 
* Type
*****************************************************************************/

// Global poup type
typedef enum
{
    CONFIRM_ONE_BUTTON_ID,
    CONFIRM_TWO_BUTTON_ID,
    COMMAND_BUTTON_ID,

    CONFIRM_ONE_BUTTON_STR,
    CONFIRM_TWO_BUTTON_STR,
    COMMAND_BUTTON_STR,

} GpTypeEnum;

typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
} GpCommonStruct;

typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VcpPopupTypeEnum       type; 
    VfxResId               textResId;
    VfxResId               btnText1ResId; 
    VcpPopupButtonTypeEnum type1;
    
} CfmOneButtonId;

typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VcpPopupTypeEnum       type; 
    VfxWChar               *text;
    VfxWChar               *btnText1; 
    VcpPopupButtonTypeEnum type1;
    
} CfmOneButtonStr;


typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VcpPopupTypeEnum       type; 
    VfxResId               textResId;
    VfxResId               btnText1ResId;
    VfxResId               btnText2ResId;
    VcpPopupButtonTypeEnum type1;
    VcpPopupButtonTypeEnum type2;    
} CfmTwoButtonId;


typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VcpPopupTypeEnum       type; 
    VfxWChar               *text;
    VfxWChar               *btnText1;
    VfxWChar               *btnText2;
    VcpPopupButtonTypeEnum type1;
    VcpPopupButtonTypeEnum type2;    
} CfmTwoButtonStr;



typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VfxResId               textResId;
    PopupEnterCallBackPtr  enterFunc;
} CmdButtonId;


typedef struct
{
    GLOBAL_POPUP_STRUCT_BASE
    VfxWChar               *text;
    PopupEnterCallBackPtr enterFunc;
} CmdButtonStr;



static MMI_BOOL vapp_nmgr_global_popup_defer_callback(mmi_scenario_id scen_id, void *arg)
{
    GpCommonStruct *p = (GpCommonStruct *)arg;
	mmi_frm_group_enter(p->parentID, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (p->gpType == CONFIRM_ONE_BUTTON_ID)
    {
        CfmOneButtonId *cntx = (CfmOneButtonId *)arg;
        vcp_global_popup_show_confirm_one_button_id(
            cntx->parentID,
            cntx->type,
            cntx->textResId,
            cntx->btnText1ResId,
            cntx->type1,
            cntx->callBack,
            cntx->userData);
    }
    else if (p->gpType == CONFIRM_TWO_BUTTON_ID)
    {
        CfmTwoButtonId *cntx = (CfmTwoButtonId *)arg;
        vcp_global_popup_show_confirm_two_button_id(
            cntx->parentID,
            cntx->type, 
            cntx->textResId, 
            cntx->btnText1ResId, 
            cntx->btnText2ResId,
            cntx->type1,
            cntx->type2,
            cntx->callBack,
            cntx->userData);
    }
    else if (p->gpType == COMMAND_BUTTON_ID)
    {
        VfxS32 handle;
        CmdButtonId *cntx = (CmdButtonId *)arg;
        handle = vcp_global_popup_show_command_create_id(
                    cntx->parentID,
                    cntx->textResId,
                    cntx->callBack,
                    cntx->userData);
        MMI_ASSERT(cntx->enterFunc);
        cntx->enterFunc(handle, cntx->userData);
        vcp_global_popup_show_command_show_id(handle);
    }
    else if (p->gpType == CONFIRM_ONE_BUTTON_STR)
    {
        CfmOneButtonStr *cntx = (CfmOneButtonStr *)arg;

        VfxWString text;
        text.loadFromMem(cntx->text);
        VfxWString btnText1;
        btnText1.loadFromMem(cntx->btnText1);
        vcp_global_popup_show_confirm_one_button_str(
            cntx->parentID,
            cntx->type, 
            text, 
            btnText1, 
            cntx->type1,
            cntx->callBack,
            cntx->userData
            ); 
        mmi_frm_asm_free_anonymous(cntx->text);
        mmi_frm_asm_free_anonymous(cntx->btnText1);
    }
    else if (p->gpType == CONFIRM_TWO_BUTTON_STR)
    {
        CfmTwoButtonStr *cntx = (CfmTwoButtonStr *)arg;

        VfxWString text;
        text.loadFromMem(cntx->text);
        VfxWString btnText1;
        btnText1.loadFromMem(cntx->btnText1);
        VfxWString btnText2;
        btnText2.loadFromMem(cntx->btnText2);
        
        vcp_global_popup_show_confirm_two_button_str(
            cntx->parentID,
            cntx->type, 
            text, 
            btnText1, 
            btnText2,
            cntx->type1,
            cntx->type2,
            cntx->callBack,
            cntx->userData
            ); 
        mmi_frm_asm_free_anonymous(cntx->text);
        mmi_frm_asm_free_anonymous(cntx->btnText1);
        mmi_frm_asm_free_anonymous(cntx->btnText2);
    }
    else if (p->gpType == COMMAND_BUTTON_STR)
    {
        CmdButtonStr *cntx = (CmdButtonStr *)arg;
        VfxWString text;
        text.loadFromMem(cntx->text);
        VfxS32 handle = vcp_global_popup_show_command_create_str(
            cntx->parentID,
            text,
            cntx->callBack,
            cntx->userData);
        mmi_frm_asm_free_anonymous(cntx->text);
        MMI_ASSERT(cntx->enterFunc);
        cntx->enterFunc(handle, cntx->userData);
        vcp_global_popup_show_command_show_str(handle);
    }
         
    return MMI_TRUE;
}


static mmi_ret vapp_nmgr_global_popup_proc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        GpCommonStruct * p = (GpCommonStruct *)evt->user_data;
        mmi_scenario_evt_struct *q = (mmi_scenario_evt_struct *)evt;
        
        if (mmi_frm_nmgr_is_scenario_deferred(p->scenID, vapp_nmgr_global_popup_defer_callback, evt->user_data))
        {
            if (p->callBack)
            {
                p->callBack(VCP_POPUP_BUTTON_NO_PRESSED, p->userData);
            }
			mmi_frm_nmgr_cancel_deferred_scenario(
				p->scenID, 
				vapp_nmgr_global_popup_defer_callback,
				evt->user_data);
        }
		else
		{
			
		}

        mmi_mfree(evt->user_data);
    }
	else if (evt->evt_id == EVT_ID_DELETE_DANGLE_GROUP_REQ)
	{
		return MMI_RET_ERR;
	}
	else if (evt->evt_id == EVT_ID_GROUP_ACTIVE)
	{
	    GpCommonStruct * p = (GpCommonStruct *)evt->user_data;
	    mmi_frm_start_scenario(p->scenID);
	}
	else if (evt->evt_id == EVT_ID_GROUP_INACTIVE)
	{
	    GpCommonStruct * p = (GpCommonStruct *)evt->user_data;
	    mmi_frm_end_scenario(p->scenID);
	}

    return MMI_RET_OK;
}

static VfxS32 vapp_nmgr_global_popup_common(mmi_scenario_id scenID, MMI_ID parentID, VcpPopupTypeEnum type, void *arg)
{
    VfxS32 id;
    id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, vapp_nmgr_global_popup_proc, (void *)arg);
    

    mmi_event_notify_enum  evtType;
    if (type == VCP_POPUP_TYPE_FAILURE)
    {
        evtType = MMI_EVENT_FAILURE;
    }
    else if (type == VCP_POPUP_TYPE_WARNING)
    {
        evtType = MMI_EVENT_FAILURE;
    }
    else
    {
        evtType = MMI_EVENT_NON_TONE;
    }
	GpCommonStruct *p = (GpCommonStruct *)arg;
	p->parentID = id;
    mmi_frm_nmgr_notify_by_app(
        scenID,
        evtType,
        vapp_nmgr_global_popup_defer_callback,
        (void *)arg);
	return id;
}



VfxS32 vapp_nmgr_global_popup_show_confirm_one_button_id(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callBack,
        void *userData)
{
    
    CfmOneButtonId *arg = (CfmOneButtonId *)mmi_malloc(sizeof(CfmOneButtonId));
    arg->gpType = CONFIRM_ONE_BUTTON_ID;
    arg->scenID = scenID;
    arg->type = type;
    arg->textResId = textResId;
    arg->btnText1ResId = btnText1ResId;
    arg->type1 = type1;
    arg->callBack = callBack;
    arg->userData = userData;
    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, type, arg); 
    return id;
}


VfxS32 vapp_nmgr_global_popup_show_confirm_two_button_id(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        VfxResId textResId, 
        VfxResId btnText1ResId, 
        VfxResId btnText2ResId,
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callBack,
        void *userData)
{
    CfmTwoButtonId *arg = (CfmTwoButtonId *)mmi_malloc(sizeof(CfmTwoButtonId));
    arg->gpType = CONFIRM_TWO_BUTTON_ID;
    arg->scenID = scenID;
    arg->type = type;
    arg->textResId = textResId;
    arg->btnText1ResId = btnText1ResId;
    arg->btnText2ResId = btnText2ResId;
    arg->type1 = type1;
    arg->type2 = type2;
    arg->callBack = callBack;
    arg->userData = userData;
    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, type, arg);
    return id;
}


VfxS32 vapp_nmgr_global_popup_show_command_id(
        mmi_scenario_id scenID,
        VfxResId textResId, 
        PopupCallBackPtr callBack,
        PopupEnterCallBackPtr enterFunc,
        void *userData)
{
    CmdButtonId *arg = (CmdButtonId *)mmi_malloc(sizeof(CmdButtonId));
    arg->gpType = COMMAND_BUTTON_ID;
    arg->scenID = scenID;
    arg->callBack = callBack;
    arg->userData = userData;
    arg->textResId = textResId;
    arg->enterFunc = enterFunc;
    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, VCP_POPUP_TYPE_INFO, arg);
    return id;    
}


VfxS32 vapp_nmgr_global_popup_show_confirm_one_button_str(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        VcpPopupButtonTypeEnum type1,
        PopupCallBackPtr callBack,
        void *userData)
{
    CfmOneButtonStr *arg = (CfmOneButtonStr *)mmi_malloc(sizeof(CfmOneButtonStr));
    arg->gpType = CONFIRM_ONE_BUTTON_STR;
    arg->scenID = scenID;
    arg->type = type;
    arg->type1 = type1;
    arg->callBack = callBack;
    arg->userData = userData;
    arg->text = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((text.getLength() + 1) * sizeof(VfxWChar));
	if (arg->text == NULL)
	{
		mmi_mfree(arg);
		return 0;
	}
    
    memcpy(arg->text, text.getBuf(), (text.getLength() + 1) * sizeof(VfxWChar));
    
	arg->btnText1 = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((btnText1.getLength() + 1) * sizeof(VfxWChar));
	if (arg->btnText1 == NULL)
	{
		mmi_mfree(arg);
		mmi_frm_asm_free_anonymous(arg->text);
		return 0;
	}
    memcpy(arg->btnText1, btnText1.getBuf(), (btnText1.getLength() + 1) * sizeof(VfxWChar));
    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, type, arg);
    return id;    
}


VfxS32 vapp_nmgr_global_popup_show_confirm_two_button_str(
        mmi_scenario_id scenID,
        VcpPopupTypeEnum type, 
        const VfxWString &text, 
        const VfxWString &btnText1, 
        const VfxWString &btnText2, 
        VcpPopupButtonTypeEnum type1,
        VcpPopupButtonTypeEnum type2,
        PopupCallBackPtr callBack,
        void *userData)
{
    CfmTwoButtonStr *arg = (CfmTwoButtonStr *)mmi_malloc(sizeof(CfmTwoButtonStr));
    arg->gpType = CONFIRM_TWO_BUTTON_STR;
    arg->scenID = scenID;
    arg->type = type;
    arg->type1 = type1;
    arg->type2 = type2;
    arg->callBack = callBack;
    arg->userData = userData;
    
    arg->text = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((text.getLength() + 1) * sizeof(VfxWChar));
	if (arg->text == NULL)
	{
		mmi_mfree(arg);
		return 0;
	}
    memcpy(arg->text, text.getBuf(), (text.getLength() + 1) * sizeof(VfxWChar));
    
    arg->btnText1 = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((btnText1.getLength() + 1) * sizeof(VfxWChar));
	if (arg->btnText1 == NULL)
	{
		mmi_mfree(arg);
		mmi_frm_asm_free_anonymous(arg->text);
		return 0;
	}
    memcpy(arg->btnText1, btnText1.getBuf(), (btnText1.getLength() + 1) * sizeof(VfxWChar));

    arg->btnText2 = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((btnText2.getLength() + 1) * sizeof(VfxWChar));
	if (arg->btnText2 == NULL)
	{
		mmi_mfree(arg);
		mmi_frm_asm_free_anonymous(arg->text);
		mmi_frm_asm_free_anonymous(arg->btnText2);
		return 0;
	}
    memcpy(arg->btnText2, btnText2.getBuf(), (btnText2.getLength() + 1) * sizeof(VfxWChar));    
    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, type, arg);
    return id;    
}


VfxS32 vapp_nmgr_global_popup_show_command_str(
        mmi_scenario_id scenID,
        const VfxWString &text, 
        PopupCallBackPtr callBack,
        PopupEnterCallBackPtr enterFunc,
        void *userData)
{
    CmdButtonStr *arg = (CmdButtonStr *)mmi_malloc(sizeof(CmdButtonStr));
    arg->gpType = COMMAND_BUTTON_STR;
    arg->scenID = scenID;
    arg->callBack = callBack;
    arg->userData = userData;
    arg->enterFunc = enterFunc;
    arg->text = (VfxWChar *)mmi_frm_asm_alloc_anonymous_sw((text.getLength() + 1) * sizeof(VfxWChar));
	if (arg->text == NULL)
	{
		mmi_mfree(arg);
		return 0;
	}
    memcpy(arg->text, text.getBuf(), (text.getLength() + 1) * sizeof(VfxWChar));

    VfxS32 id = vapp_nmgr_global_popup_common(scenID, GRP_ID_ROOT, VCP_POPUP_TYPE_INFO, arg);
    return id;    
}


void vapp_nmgr_global_popup_cancel(VfxS32 handle)
{
    mmi_frm_group_close(handle);
}
