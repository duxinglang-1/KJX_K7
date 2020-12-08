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
 *  vapp_bt_adap.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "MMI_features.h" 
#include "MmiDataType.h"
#include "GlobalResDef.h"
#include "ModeSwitchSrvGprot.h"
}

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_bt_main.h"
#include "vapp_bt_send.h"
#include "vapp_bt_send_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern "C" VfxU8 g_enable_pts_test=0;

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C"
void mmi_bt_suppress_popup(VfxBool suppress_switch, VfxU32 supress_level)
{
}

extern "C"
void HighlightEmBTSetLimitedDiscoverabeMode()
{
}

extern "C"
void mmi_bt_main_hilight_handler()
{
}

extern "C"
void mmi_bt_permission_setting_hilight_hdlr()
{
}

extern "C"
void mmi_bt_permission_setting_hint_hdlr(VfxU16 index)
{
}

extern "C"
void mmi_bt_remote_control_menu_hilight_handler()
{
}

extern "C"
void mmi_bt_remote_control_menu_hint_handler(VfxU16 index)
{
}

extern "C"
MMI_BOOL mmi_bt_is_to_display_bt_menu()
{
    return MMI_TRUE;
}

extern "C"
void cui_bt_device_select_screen_close(mmi_id cui_gid)
{
}

extern "C"
mmi_id cui_bt_device_select_screen_create(mmi_id parent_gid)
{
    return 0;
}

extern "C"
mmi_ret cui_bt_device_select_screen_run(mmi_id cui_id)
{
    return MMI_RET_OK;
}

extern "C"
void cui_bt_device_select_screen_set_mask(mmi_id cui_id, VfxU32 cod_bit_mask, VfxU32 service_id)
{
}

extern "C"
void cui_bt_device_select_screen_set_option_flag(mmi_id cui_id, VfxU32 flag)
{
}

extern "C"
mmi_id cui_bt_power_on_create(mmi_id parent_gid)
{
    return 0;
}

extern "C"
void cui_bt_power_on_close(mmi_id cui_gid)
{
}

extern "C"
mmi_ret cui_bt_power_on_run(mmi_id cui_id)
{
    return MMI_RET_OK;
}

extern "C"
VfxBool mmi_bt_is_permission(VfxBool is_popup)
{
    return VFX_FALSE;
}

extern "C"
void mmi_bt_popup_operation_not_allowed()
{
}

extern "C"
void mmi_bt_popup_prohibited_by_blocked_device()
{
}

extern "C"
void mmi_bt_popup_prohibited_by_simap()
{
}

extern "C"
void mmi_bt_suppress_profile_popup(VfxU32 profile_id, VfxBool suppress_switch)
{
}

extern "C"
void cui_bt_sending_launch(MMI_ID parent_id, const VfxU32 *para)
{
}

extern "C"
MMI_ID cui_bt_sending_create(MMI_ID parent_id)
{
    return 0;
}

extern "C"
void cui_bt_sending_run(MMI_ID id, const VfxU32 *para)
{
}

extern "C"
void cui_bt_sending_continue(MMI_ID id, const VfxU32 *obj)
{
}

extern "C"
void cui_bt_sending_close(MMI_ID id)
{
}

extern "C"
void mmi_bt_enable_receiving()
{
}

extern "C"
void mmi_bt_disable_receiving()
{
}

extern "C"
VfxBool mmi_bt_is_receiving()
{
    return VFX_FALSE;
}

extern "C"
void mmi_bt_sco_far_end_loopback_test(VfxU32 lap, VfxU8 uap, VfxU16 nap, VfxU8 *pin_code, VfxU8 size_of_pin)
{
}

extern "C"
void mmi_bt_sco_far_end_loopback_cancel_test()
{
}

extern "C"
void mmi_bt_connect_last_headset()
{
}

extern "C"
VfxBool mmi_bt_switch_voice_path_incall(VfxBool is_on)
{
    return VFX_FALSE;
}

extern "C"
VfxU32 bpp_pixel_to_mm(VfxU32 px)
{
    return 0;
}

extern "C"
void *bpp_xhtml_open(const CHAR *version, VfxU32 *output)
{
    return NULL;
}

extern "C"
VfxU32 bpp_xhtml_close(void *xhtml)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_style_begin(void *xhtml, const VfxChar *type)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_style_rule(void *xhtml, const VfxU32 *rules, U32 count)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_rule_begin(void *xhtml, const VfxU32 *rule)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_rule_end(void *xhtml)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_style_end(void *xhtml)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_element_begin(void *xhtml, const VfxChar *name, VfxU32 *attrs, VfxU32 count)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_element_data(void *xhtml, const VfxChar *data)
{
    return 0;
}

extern "C"
S32 bpp_xhtml_element_end(void *xhtml, const VfxChar *name)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_image_element(void *xhtml, VfxU32 *attr)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_object_element(void *xhtml, VfxU32 *attr)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_inline_element(void *, const VfxChar *, VfxU32 *, VfxU32, VfxChar *)
{
    return 0;
}

extern "C"
VfxS32 bpp_xhtml_empty_element(void *xhtml, const VfxChar *name, VfxU32 *attrs, VfxU32 count)
{
    return 0;
}

extern "C"
VfxU32 cui_bt_printing_launch(MMI_ID parent, VfxU32 type, VfxU32 *data, VfxU32 option)
{
    return 0;
}

extern "C"
void cui_bt_printing_set_data(VfxU32 inst, VfxU32 *data)
{
}

extern "C"
VfxS32 cui_bt_printing_style_rules(VfxU32 inst, void *xhtml)
{
    return 0;
}

extern "C"
VfxChar *cui_bt_printing_xhtml_version(VfxU32 inst)
{
    return NULL;
}

extern "C"
mmi_ret mmi_bpp_card_plug_out_hdlr(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

extern "C"
mmi_ret mmi_bt_power_off_pre_process(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C"
MMI_RET mmi_bt_setting_storage_fmgr_notify_hdlr(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

extern "C"
MMI_RET mmi_ftp_enter_usb_ms_callback(mmi_event_struct *param)
{
    return MMI_RET_OK;
}

extern "C"
mmi_ret  mmi_opp_usb_plugin_hdlr(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

extern "C"
VfxBool mmi_bt_is_power_on(VfxBool is_popup)
{
    return VFX_FALSE;
}

extern "C"
VfxBool mmi_bt_is_power_on_with_power_on_confirm(VfxBool is_popup, void (*power_on_cb_func_ptr) (VfxBool))
{
    return VFX_FALSE;
}

extern "C"
VfxS32 mmi_bt_get_active_signal_connection_id(VfxU32 profile_uuid)
{
    return 0;
}

extern "C"
void mmi_bt_panic_ind_post_process()
{
}

extern "C"
VfxBool mmi_bt_reject_passkey_ind(VfxU32 lap, VfxU8 uap, VfxU16 nap)
{
    return VFX_FALSE;
}

extern "C"
void mmi_bt_entry_idle_notify_scr()
{
}

extern "C"
VfxU8 mmi_bt_recv_files_exist()
{
    return 0;
}

extern "C"
void mmi_bt_reset_hw_off()
{
    srv_mode_switch_update_cb_func(); 
}

extern "C"
void mmi_bt_reset_hw_on()
{
    srv_mode_switch_update_cb_func(); 
}

extern "C"
void mmi_bt_entry_main_menu()
{
}

extern "C"
void mmi_bt_disable_pts_test()
{
}

extern "C"
void mmi_bt_enable_pts_test()
{
}

#ifdef __MMI_OPP_SUPPORT__
extern "C"
void mmi_fmgr_forward_bt_send_enabler(mmi_menu_id item_id, const VfxWChar* filepath, const VfxU32* fileinfo)
{
}

extern "C"
void mmi_fmgr_to_bt_hdlr(mmi_menu_id item_id, const VfxWChar * filepath, const VfxU32* fileinfo)
{
	VappBTSendingPara sendingPara;
    mmi_id group_id;
    sendingPara.m_appData = NULL;
    sendingPara.m_callback = NULL;
    sendingPara.m_option = VAPP_BT_SEND_NONE;
    sendingPara.m_total = 1;
    sendingPara.m_nameArray = (VfxWChar**)(&filepath);
    
    group_id = VfxAppLauncher::createCui(
        VCUI_BT_SEND_PREPARE, 
        VFX_OBJ_CLASS_INFO(VappBTSendPreApp),
        GRP_ID_ROOT,
        &sendingPara,
        sizeof(sendingPara));
    VfxAppLauncher::runCui(group_id);
    
}
#endif // __MMI_OPP_SUPPORT__

extern "C"
void mmi_bt_convert_name_utf8_to_ucs2(VfxU8 *utf8_name, VfxU16 *ucs2_name)
{
}

extern "C"
VfxBool mmi_bt_is_dev_cod_match(VfxU32 device_cod, VfxU32 specific_cod)
{
    return VFX_FALSE;
}
extern "C"
VfxU32 mmi_bt_send_object(void* obj,void* app,void* prof,void* option)
{
    return 0;
}
