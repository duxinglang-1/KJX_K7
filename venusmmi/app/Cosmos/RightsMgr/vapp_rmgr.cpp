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
 *  Vapp_rmgr.cpp
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Sweep screen of Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/


extern "C"
{
#include "MMI_features.h" 
}

#ifdef __MMI_RMGR__

#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_app_scr.h"
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vcp_menu_popup.h"
extern "C"
{

#include "stack_msgs.h"/*
#include "med_smalloc.h"
#include "med_api.h"
#include "med_utility.h"
*/
#include "stack_common.h"
//#include "SimDetectionGprot.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "FileMgrGProt.h"
#include "drm_errcode.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
//#include "mmi_rp_app_rmgr_def.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "fs_func.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "gui_typedef.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "kal_internal_api.h"
#include "string.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "browser_api.h"
#include "mmi_frm_history_gprot.h"
#include "MMI_features.h"
#include "ProfilesSrvGprot.h"
#include "gui_data_types.h"
#include "wgui_categories_text_viewer.h"
#include "app_ltlcom.h"
//#include "CommonScreens.h"
#include "GlobalDefs.h"
#include "RightsMgrProt.h"
#include "RightsMgrGProt.h"
#include "Drm_errcode.h"
#include "Drm_def.h"
#include "FileMgrSrvGprot.h"
#include "App_str.h"
#include "Vapp_rmgr_cntx.h"

#include "ProtocolEvents.h" /* PRT_EQ_USB_DETECT_IND */
#include "AlarmFrameworkProt.h" /* AlmDeInit */
#include "SettingResDef.h" /* STR_SETTING_NOTICE_SUCCESS_REBOOT_TEXT */
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */

#include "Vapp_rmgr_service.h"
#include "Vapp_rmgr_cntx.h"

#include "Vapp_rmgr_cntx.h"
#include "mmi_rp_vapp_rmgr_def.h"

}


#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"
#include "vtst_rt_main.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vcp_form.h"
#include "vapp_rmgr_util.h"
#include "Vapp_rmgr_adv.h"
#include "App_str.h"
#include "vcp_global_popup.h"
#include "vfx_adp_device.h"
//extern "C" kal_int32 DRM_get_ro_num(kal_uint8 *serial, drm_general_callback callback);
extern "C" void set_rmgr_list_index(VfxU32 itemIndex);
extern "C" void vapp_rmgr_list_ro_delete_all_entry();
extern "C" int get_fmgr_result();
extern "C" mmi_str_id  srv_fmgr_fs_error_get_string(S32 fs_error);
extern "C" void mmi_rmgr_reboot_ms(void *msg);
extern "C" kal_bool DRM_consume_table_is_in_use(void);
extern "C" void mmi_rmgr_send_rights_request(void);

extern "C" void mmi_rmgr_highlight_main(void);

extern "C" void mmi_rmgr_highlight_list_ro(void);

extern "C" void mmi_rmgr_highlight_info(void);

extern "C" void mmi_rmgr_highlight_db_proc(void);




U32 id;
static U8 g_flag=0;

typedef enum 
{
	RMGR_ENTRY_MENU,
	RMGR_ENTRY_FORMAT,
	RMGR_ENTRY_FORMAT_CALLBACK,
    RMGR_ENTRY_FORMAT_CALLBACK_ABORTED,
	RMGR_ENTRY_FORMAT_CALLBACK_ABORTED_GETERR,
	RMGR_SWEEP_ENTRY_DONE,
    RMGR_SWEEP_ABORTED,
	RMGR_SWEEP_GETERRSTR,
	RMGR_SWEEP_CLOSEPROG,
	RMGR_REQUEST_RIGHTS_ERROR,
	RMGR_REQUEST_RIGHTS_GET_ERROR,
	RMGR_ENTRY_REQUEST_RIGHTS_CONFIRM,
	RMGR_REQUEST_RIGHTS_DRM_PROH,
	RMGR_ENTRY_SHOW_PROCESS_INFO_SUCCESS,
	RMGR_ENTRY_SHOW_PROCESS_INFO_FAILURE,
	RMGR_ENTRY_DB_CONFIRM
}Vapp_rmgr_entry_enum;


typedef struct
{
    U16 eventID;
    MMI_BOOL slave;
    FuncPtr callback;
} mmi_rmgr_reboot_callback_struct;





UI_string_type glb[42][42]={0};

//static U8 counter_of_reboot = 0;

VfxS8 arr_indx[MAX_LIC]={0};
VcpIndicatorPopup *m_popup;

VcpIndicatorPopup *del_popupind;

VcpIndicatorPopup *sweep_prog;



	/****test 01/11****/

/*************17/11******************/

/************17/11******************************/


class VappRmgrServiceInterface
{
public:
	static void getROnumhdlr(kal_uint8 , kal_int32 );
	static VfxSignal2<kal_uint8 *,kal_int32 > m_getROnumCallback; 
};

VfxSignal2<kal_uint8 *,kal_int32 > VappRmgrServiceInterface::m_getROnumCallback;

void VappRmgrServiceInterface :: getROnumhdlr(kal_uint8 serial, kal_int32 result)    
{                                                                                              
    m_getROnumCallback.emit(&serial, result); 
}                                                                                              
      
const VfxWChar* strLic[] = 
{
    (const VfxWChar*)L"License 1",
    (const VfxWChar*)L"Licencse 2",
	(const VfxWChar*)L"License 3",
	(const VfxWChar*)L"License 4"
};

/************************ Added for checking CUI behaviour ***************************************/

class VappRightsMgr:public VfxCui
{
	VFX_DECLARE_CLASS(VappRightsMgr);
public:
	void onRun(void* args, VfxU32 argSize);
};




class VappRightsMgr1:public VfxApp
{
	VFX_DECLARE_CLASS(VappRightsMgr1);
public:
	virtual void onRun(void* args, VfxU32 argSize);
};

class VfxRightsMgrScr1:public VfxMainScr
{
	VFX_DECLARE_CLASS(VfxRightsMgrScr1);
public:
	virtual void on1stReady(void);
	virtual void on2ndReady(void);
	static void onConfirmClicked(VfxId id, void *userData);
	
    static void onCommandCallClick(VfxId id, void *userData);
   // void onConfirmClicked(VfxId id, void *userData);
/**now**/
	VfxRightsMgrScr1(void* para)
	{
		args = (VfxU32)*((U32*)para);
//	args= (VfxU32)(*(*para));
	}
    VfxRightsMgrScr1()
	{
		setIsSmallScreen();
	}
private:
	VfxU32 args;
	 VfxPage *page;

};



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
#endif


class VappRmgrServInterfaceSame 
{
public:
	static void delROhdlr(kal_uint8 , kal_int32);
    static VfxSignal2<kal_uint8 ,kal_int32 > delROCallback; 
};
VfxSignal2<kal_uint8 ,kal_int32 > VappRmgrServInterfaceSame::delROCallback;

void VappRmgrServInterfaceSame::delROhdlr(kal_uint8 index , kal_int32 result)
{  
	VfxU32 i=get_rmgr_list_index();
	delROCallback.emit(index, result);

}

//VFX_IMPLEMENT_CLASS("VfxRmgrPageFormat", VfxRmgrPageFormat, VfxPage);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif


class VfxRmgrPageFormatCbAbt: public VfxPage
{
	VFX_DECLARE_CLASS(VfxRmgrPageFormatCbAbt);
protected:
	virtual void onInit();

};


VFX_IMPLEMENT_CLASS("VfxRmgrPageFormatCbAbt", VfxRmgrPageFormatCbAbt, VfxPage);

void VfxRmgrPageFormatCbAbt::onInit()
{
	VfxPage::onInit();
	VcpConfirmPopup* fcb_popup;

	VFX_OBJ_CREATE(fcb_popup, VcpConfirmPopup, this);
	
    VFX_OBJ_CREATE(fcb_popup, VcpConfirmPopup, this);
	     fcb_popup->setInfoType(VCP_POPUP_TYPE_WARNING);
		 fcb_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		 fcb_popup->setText(VFX_WSTR_RES(FMGR_FS_ABORTED_ERROR_TEXT));
		 fcb_popup->setAutoDestory(VFX_TRUE);
         fcb_popup->show(VFX_TRUE);
    //f_popup->m_signalButtonClicked.connect(this, &VappShellIVPanel::onDlelteMenuButtonClicked);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


class VfxRmgrPageGetRightsErr: public VfxPage
{
	VFX_DECLARE_CLASS(VfxRmgrPageGetRightsErr);
protected:
	virtual void onInit();

};

VFX_IMPLEMENT_CLASS("VfxRmgrPageGetRightsErr", VfxRmgrPageGetRightsErr, VfxPage);

void VfxRmgrPageGetRightsErr::onInit()
{
	VfxPage::onInit();
	
	VcpCommandPopup *g_pop;
	VFX_OBJ_CREATE(g_pop, VcpCommandPopup, this);
	 g_pop->addItem(1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    
    g_pop->setAutoDestory(VFX_TRUE);
    g_pop->show(VFX_TRUE);


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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




// class to handle the api shared with dlagent
class VfxRmgrPageProcInfoSuc: public VfxPage
{
	VFX_DECLARE_CLASS(VfxRmgrPageProcInfoSuc);
public:
    U16 str;
	
protected:
	virtual void onInit();
	
};



VFX_IMPLEMENT_CLASS("VfxRmgrPageProcInfoSuc",VfxRmgrPageProcInfoSuc, VfxPage);

void VfxRmgrPageProcInfoSuc::onInit()
{
    U16 str;
	VcpCommandPopup *c_pop;
	VFX_OBJ_CREATE(c_pop, VcpCommandPopup, this);
	str=get_rmgr_str_id();
	str = STR_GLOBAL_ERROR;
	c_pop->setText(VFX_WSTR_RES(str));
	c_pop->setAutoDestory(VFX_TRUE);

	
// TO DO
//    c_pop->addItem(1, VFX_WSTR(WCHAR*)GetString(str), VCP_POPUP_BUTTON_TYPE_CANCEL);
	c_pop->show(VFX_TRUE);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


class VfxRmgrPageDBEntry: public VfxPage
{
	VFX_DECLARE_CLASS(VfxRmgrPageDBEntry);
protected:
	virtual void onInit();
};

VFX_IMPLEMENT_CLASS("VfxRmgrPageDBEntry", VfxRmgrPageDBEntry, VfxPage);

void VfxRmgrPageDBEntry::onInit()
{

	VcpCommandPopup *d_pop;

	VFX_OBJ_CREATE(d_pop, VcpCommandPopup, this);
    d_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
    d_pop->setText(VFX_WSTR("License space is low"));

    d_pop->setAutoDestory(VFX_TRUE);

	d_pop->show(VFX_TRUE);
}	

/********************** from rightsmgrsweep.c***********************/

/************************ from rightsmgrsweep.c*************************************************/






VFX_IMPLEMENT_CLASS("VfxRmgrPage1", VfxRmgrPage1, VfxPage);



void VfxRmgrPage1:: onBack()
{
  getMainScr()->popPage();
}



void VfxRmgrPage1::vapp_rmgr_sweep_entry_progress()
{
	if (!DRM_consume_table_is_in_use())
    {
        rmgr_process_db_cntx.reboot_type = DRM_PROCESS_DATABASE_SWEEP + 1;
        VFX_OBJ_CREATE(sweep_prog,VcpIndicatorPopup,this);
        sweep_prog->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        sweep_prog->setText(VFX_WSTR_RES(STR_GLOBAL_DRM_PROCESSING));
	    sweep_prog->setAutoDestory(VFX_TRUE);
        sweep_prog->show(VFX_TRUE);
    

	rmgr_process_db_cntx.serial = 0xFF;
    rmgr_process_db_cntx.can_cancel = MMI_FALSE;
    rmgr_process_db_cntx.cancel_when_exit =(kal_bool) NULL;
	rmgr_process_db_cntx.str_id = STR_ID_RMGR_PROCESSING;

        mmi_rmgr_reboot_ms(NULL);
    }
    else
    {
		VcpConfirmPopup *pop;
		VFX_OBJ_CREATE(pop, VcpConfirmPopup, this);
		pop->setInfoType(VCP_POPUP_TYPE_WARNING);
		pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    	pop->setText(VFX_WSTR("Locked by App"));
		pop->setAutoDestory(VFX_TRUE);
        pop->show(VFX_TRUE);

   }
}

/**************** 13/11*****************/

void VfxRmgrPage1::VappRmgrDeleteAllconfirm(VfxObject*obj, VfxId id)
{
	switch(id)
	{
	case VCP_CONFIRM_POPUP_BUTTON_USER_1:
		vapp_rmgr_sweep_entry_progress();
		break;
	
	}
}

/*
void VfxRmgrPage1::onEnter(VfxBool isback)
{

}
*/


/******01/11/10**********************/

S32 VfxRmgrPage1::mmi_rmgr_get_alias_item(S32 item_index, UI_string_type str_buff)
{
 
	kal_wchar *ptr;
    kal_int32 result;
   
    
    result = DRM_get_ro_list(item_index, (char *)&ro_alias[0], SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,DRM_DB_GET_ALL);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    //*img_buff_p = get_image(IMG_ID_RMGR_UNLOCK);

    mmi_ucs2ncpy((S8 *)str_buff, (const S8 *)&ro_alias[0], MAX_SUBMENU_CHARACTERS);

    ptr = app_ucs2_strstr(str_buff + (app_ucs2_strlen((kal_int8 *)str_buff) - 4), (kal_wchar *)L".mp3");

    if (ptr)
    {
        *ptr = 0;
    }

    ptr = app_ucs2_strstr(str_buff + (app_ucs2_strlen((kal_int8 *)str_buff) - 4), (kal_wchar *)L".mp2");

    if (ptr)
    {
        *ptr = 0;
    }

/******test 01/11 *************/
	//glb[item_index]=str_buff;



/******test 01/11 *************/
    return result;
}



S32 VfxRmgrPage1::mmi_rmgr_get_alias_item_same(S32 item_index, UI_string_type str_buff)
{
 
	kal_wchar *ptr;
    kal_int32 result;
   
    
    result = DRM_get_ro_list(item_index, (char *)&ro_alias[0], SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,DRM_DB_GET_ALL);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    //*img_buff_p = get_image(IMG_ID_RMGR_UNLOCK);

    mmi_ucs2ncpy((S8 *)str_buff, (const S8 *)&ro_alias[0], 80);

    ptr = app_ucs2_strstr(str_buff + (app_ucs2_strlen((kal_int8 *)str_buff) - 4), (kal_wchar *)L".mp3");

    if (ptr)
    {
        *ptr = 0;
    }

    ptr = app_ucs2_strstr(str_buff + (app_ucs2_strlen((kal_int8 *)str_buff) - 4), (kal_wchar *)L".mp2");

    if (ptr)
    {
        *ptr = 0;
    }

/******test 01/11 *************/
	//glb[item_index]=str_buff;



/******test 01/11 *************/
    return result;
}
/************************ 01/11/10**********************/

void VfxRmgrPage1::mmi_rmgr_list_ro_get_num_callback(kal_uint8* serial, kal_int32 result)
{
  //S32 i;
  //rmgr_vfx_list_ro_cntx = result;
  //kal_uint8 serl;
  VcpConfirmPopup *pop;
  set_licence_count(result);
  //kal_wchar subject[41];  
 // str_buff=(UI_string_type)"license List";
  if (g_flag==0)
  {
  if(result > 0)
	  toolbar->setDisableItem(1, VFX_FALSE);
  VappRmgrServiceInterface::m_getROnumCallback.connect(this , &VfxRmgrPage1::mmi_rmgr_list_ro_get_num_callback);
	DRM_get_ro_num(serial,(&VappRmgrServiceInterface::getROnumhdlr),DRM_DB_GET_ALL);
	g_flag++;
	//rmgr_vfx_list_ro_cntx = result;

	return;
   //DRM_get_ro_num(&serl, (drm_general_callback)mmi_rmgr_list_ro_get_num_callback,DRM_DB_GET_INVALID);
  }
    if (result < DRM_RESULT_OK)
    {

        if (result == DRM_RESULT_CANCELED)
        {
			VFX_OBJ_CREATE(pop, VcpConfirmPopup, this);
			pop->setInfoType(VCP_POPUP_TYPE_WARNING);
			pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
					 pop->setText(VFX_WSTR_RES(STR_ID_RMGR_CANCELLED));
					 pop->setAutoDestory(VFX_TRUE);
               		 pop->show(VFX_TRUE);
   		}
        else
        {
        
			VFX_OBJ_CREATE(pop, VcpConfirmPopup, this);
			pop->setInfoType(VCP_POPUP_TYPE_WARNING);
			pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);

				pop->setText(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(result)));
				pop->setAutoDestory(VFX_TRUE);
               	pop->show(VFX_TRUE);
		}

    }
	    
	VFX_OBJ_CLOSE(m_popup);
	m_popup = NULL;

	//for(i=0;i<rmgr_vfx_list_ro_cntx;i++)
     		//	VfxRmgrPage1::mmi_rmgr_get_alias_item(i, subject);
 	 VFX_OBJ_CREATE(list, VcpListMenu, this);
	   list->setContentProvider(this);
	   list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
	   list->m_signalItemTapped.connect(this, &VfxRmgrPage1::onTapItem);
	   list->m_signalItemLongTapped.connect(this,&VfxRmgrPage1::onLongTapItem);

       list->setPos(VfxPoint(0, 0));
       list->setSize(getSize());
	   list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        //m_popup->hide(VFX_TRUE);
       
  
        return;
}



void VfxRmgrPage1::onEnter(VfxBool isBackward)
	{
	
if(!isBackward)
{
//	VFX_OBJ_CREATE(m_popup,VcpIndicatorPopup,this);
 //       m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
  //      m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_DRM_PROCESSING));
//	    m_popup->setAutoDestory(VFX_TRUE);
 //       m_popup->show(VFX_TRUE);
//	VappRmgrServiceInterface::m_getROnumCallback.connect(this , &VfxRmgrPage1::mmi_rmgr_list_ro_get_num_callback);
//	DRM_get_ro_num(&serial,(&VappRmgrServiceInterface::getROnumhdlr),DRM_DB_GET_INVALID);
}
else
{
		if(list == NULL)
		{
			VFX_OBJ_CREATE(list, VcpListMenu, this);
			list->setContentProvider(this);
			list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
			list->m_signalItemTapped.connect(this, &VfxRmgrPage1::onTapItem);
			list->m_signalItemLongTapped.connect(this,&VfxRmgrPage1::onLongTapItem);
	
			list->setPos(VfxPoint(0, 0));
			list->setSize(getSize());
			list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
		}
		else
		{
	list->resetAllItems(VFX_TRUE);
		}
	if(vapp_rmgr_get_del_item())
	{
		toolbar->setDisableItem(1, VFX_TRUE);
		vapp_rmgr_set_del_item(VFX_FALSE);
	}
}



}


void VfxRmgrPage1:: onInit()
	{
		g_flag=0;
	    VcpTitleBar *m_title;
		VfxPage::onInit(); 
		    VFX_OBJ_CREATE(m_title, VcpTitleBar, this);
	    m_title->setPos(VfxPoint(VAPP_RMGR_POS_TITLE_X,VAPP_RMGR_POS_TITLE_X));
	    m_title->setTitle(VFX_WSTR_RES(STR_ID_RMGR_VAPP));
	    m_title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
	    setTopBar(m_title);
		//setBgColor(VFX_COLOR_WHITE);


      VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    
	  setBottomBar(toolbar); 
	toolbar->addItem(1, VFX_WSTR_RES(STR_ID_DELETE_EXPIRED),VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE );       // add tool bar "save" button
    toolbar->addItem(2, VFX_WSTR_RES(STR_ID_RMGR_ADVANCED),  VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING); // add tool bar "cancel" button
    toolbar->setDisableItem(1, VFX_TRUE);
    toolbar->m_signalButtonTap.connect(this, &VfxRmgrPage1::eventHandler);          // connect tool bar signal


	
	
	
	/**
	for(i=0;i<rmgr_vfx_list_ro_cntx;i++)
     	VfxRmgrPage1::mmi_rmgr_get_alias_item(i,str_buff);
	**/
	}

VfxBool VfxRmgrPage1::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
	kal_wchar subject[41]; 
    S32 valid_flag=0;
    valid_flag=VfxRmgrPage1::mmi_rmgr_get_alias_item(index, subject);
    if(fieldType==VCP_LIST_MENU_FIELD_TEXT)
	{
		text.loadFromMem((VfxWChar*)subject);
		
	}
	if(fieldType==VCP_LIST_MENU_FIELD_SUB_TEXT1)
	{
		if(valid_flag)
		{	
			text=VFX_WSTR_RES(STR_ID_RMGR_VALID);
		    arr_indx[index]=1;
		}    
		else
			{
            text=VFX_WSTR_RES(STR_ID_RMGR_EXPIRED);
		    arr_indx[index]=-1;
			toolbar->setDisableItem(1, VFX_FALSE);
			//toolbar->setDisableItem(CANCEL_BUTTON, VFX_FALSE); ;
			} 
	}
	return VFX_TRUE;
           
}

/******** tool bar tap handler***************/

void VfxRmgrPage1::eventHandler(VfxObject* obj, VfxId id)
{	
	 VcpConfirmPopup *d_pop;
	switch(id)
    { 
	case 1:
    VFX_OBJ_CREATE(d_pop, VcpConfirmPopup, this);
    d_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
    d_pop->setText(VFX_WSTR_RES(STR_ID_RMGR_DEL_ALL_EXP));
    //d_pop->addItem(100, VFX_WSTR("Delete and then reboot"));
    //d_pop->addItem(200, VFX_WSTR("Cancel"));
    d_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	d_pop->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    d_pop->setAutoDestory(VFX_TRUE);
	d_pop->m_signalButtonClicked.connect(this,&VfxRmgrPage1::VappRmgrDeleteAllconfirm);
	d_pop->show(VFX_TRUE);
		break;

	case 2:
         VfxAdvPage *d_page;
	VFX_OBJ_CREATE(d_page, VfxAdvPage, getMainScr());
	getMainScr()->pushPage(VFX_ID_NULL, d_page);
	getMainScr()->show();
			 break;

			 default:
		getMainScr()->popPage();
		break;
	}
}





/********************* tool bar tap handler*******************/

void VfxRmgrPage1::onLongTapItem(VcpListMenu *listMenu, VfxU32 itemIndex)
{
  //VfxDetailPage *d_page;
  kal_wchar detail_item[100];
  VfxU32 i=itemIndex;
  set_rmgr_list_index_longtap(i);
 // VFX_OBJ_CREATE(d_page, VfxDetailPage, this);
  //d_page->eventHandler(NULL, 0);
  vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
  VfxRmgrPage1::mmi_rmgr_get_alias_item(itemIndex, detail_item);
  

  VcpMenuPopup *context;
	VfxWString title1;
    VFX_OBJ_CREATE(context, VcpMenuPopup, this);
	title1.loadFromMem((VfxWChar*)detail_item);
	context->setTitle(title1);
	context->addItem(1, VFX_WSTR_RES(STR_GLOBAL_DELETE));
	//context->m_signalMenuCallback.connect(this, &VappNotesPage::VappNotesOptionPopup_cntx);
	 context->showMenu();
     context->m_signalMenuCallback.connect(this, &VfxRmgrPage1::VappRmgrLongTapDelete);
}


void VfxRmgrPage1::mmi_vfx_rmgr_list_ro_del_callback_same(kal_uint8 serial, kal_int32 result)
{
	

	

	VcpConfirmPopup *d_popup;
 if(result==DRM_RESULT_OK)
		{
	U16 count =  get_licence_count();
        set_licence_count(--count);
        toolbar->setDisableItem(1, VFX_TRUE);
	 }
else
{
	if(result==DRM_RESULT_CANCELED)
	{
	  VFX_OBJ_CREATE(d_popup, VcpConfirmPopup, this);
	     d_popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
		 d_popup->setText(VFX_WSTR_RES(STR_GLOBAL_ABORT));
		 d_popup->setAutoDestory(VFX_TRUE);
         d_popup->show(VFX_TRUE);
	}
	else 
	{
		VcpConfirmPopup *m_confirmPopup;
        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setText(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(result)));
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        m_confirmPopup->setAutoDestory(VFX_TRUE);
        m_confirmPopup->show(VFX_TRUE);
	}

}
if(del_popupind != NULL)
	{
	del_popupind->exit(VFX_TRUE);
	}
list->resetAllItems(VFX_TRUE);


    
}


void VfxRmgrPage1::VappRmgrDeleteconfirm(VfxObject*obj, VfxId id)
{
	VfxU32 i;
	
	switch(id)
	{
	case VCP_CONFIRM_POPUP_BUTTON_USER_1 :
	if (!DRM_consume_table_is_in_use())
 		{
		vapp_rmgr_set_del_item(1);
        VFX_OBJ_CREATE(del_popupind,VcpIndicatorPopup,this);
        del_popupind->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        del_popupind->setText(VFX_WSTR_RES(STR_GLOBAL_DELETING));
	  	  del_popupind->setAutoDestory(VFX_TRUE);
        del_popupind->show(VFX_TRUE); 
        i=get_rmgr_list_index_longtap();
		VappRmgrServInterfaceSame::delROCallback.connect(this , &VfxRmgrPage1::mmi_vfx_rmgr_list_ro_del_callback_same);
		 DRM_process_database(
            DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_ALL,
            i,
            NULL,
            NULL,
            (&VappRmgrServInterfaceSame::delROhdlr));
	 	}
	 else
	 	{
			 	VcpConfirmPopup *locked_pop;
				VFX_OBJ_CREATE(locked_pop, VcpConfirmPopup, this);
				locked_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
			    locked_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
		        locked_pop->setText(VFX_WSTR_RES(STR_ID_RMGR_LOCKED_BY_APP));
		        locked_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		        locked_pop->setAutoDestory(VFX_TRUE);
		        locked_pop->show(VFX_TRUE);
	 	}
        

       break;

	


	   }
}


void VfxRmgrPage1::VappRmgrLongTapDelete(VcpMenuPopup * menu,  VcpMenuPopupEventEnum event, VcpMenuPopupItem * item)
{
	//VfxU32 i;
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		VcpConfirmPopup *d_pop;
		VFX_OBJ_CREATE(d_pop, VcpConfirmPopup, this);
    d_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
    d_pop->setText(VFX_WSTR_RES(STR_ID_RMGR_DEL_VALID_LIC));
  //  d_pop->addItem('Righ', VFX_WSTR("Delete"));
  //  d_pop->addItem('Left', VFX_WSTR("Cancel"));
    d_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	d_pop->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL) ,  VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL); 
	
    d_pop->setAutoDestory(VFX_TRUE);
	d_pop->m_signalButtonClicked.connect(this,&VfxRmgrPage1::VappRmgrDeleteconfirm);
	d_pop->show(VFX_TRUE);
	}

}


void VfxRmgrPage1::onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex)
{
	kal_wchar detail_item[100]={0,};
	//U32 i = (U32)itemIndex;
	set_rmgr_list_index(itemIndex);
	//getMainScr()->popPage();
	VfxDetailPage *d_page;
	memset(detail_item,0,100);
	DRM_get_object_method_by_ref(itemIndex, DRM_DB_GET_ALL);
	VfxRmgrPage1::mmi_rmgr_get_alias_item_same(itemIndex, detail_item);
	//if(VfxRmgrPage1::mmi_rmgr_get_alias_item_same(itemIndex, detail_item))
	//{
	//	arr_indx[itemIndex] = 1;
	//}
	//else
	//{
	//	arr_indx[itemIndex] = -1;
	//}
	set_detail_item_name(detail_item);
	VFX_OBJ_CREATE(d_page, VfxDetailPage, getMainScr());

	//VfxDetailPage::mmi_vfx_rmgr_populate_info(DRM_PERMISSION_ALL,info,sizeof(subMenuData),itemIndex);
	
	//getMainScr()->popPage();
	//scr->show();
	
	getMainScr()->pushPage(VFX_ID_NULL, d_page);
	getMainScr()->show();


}

void VfxRmgrPage1::onDeinit()
   {
	   VfxPage::onDeinit();
   }


VfxU32 VfxRmgrPage1::getCount(void) const
{
	
	//return rmgr_vfx_list_ro_cntx;
	return get_licence_count();
}

/******************************** Added for checking CUI behaviour ****************************************/

VFX_IMPLEMENT_CLASS("VappRightsMgr", VappRightsMgr, VfxCui);

void VappRightsMgr::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
	//U32 *data;
	//data = args;
    
    VfxRightsMgrScr1 *scr;
    VFX_OBJ_CREATE_EX(scr, VfxRightsMgrScr1, this, (args));
    scr->show();
}

/******************************** Added for checking CUI behaviour ************************************/


VFX_IMPLEMENT_CLASS("VappRightsMgr1", VappRightsMgr1, VfxApp);

void VappRightsMgr1::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
	//U32 *data;
	//data = args;
    
    VfxRightsMgrScr1 *scr;
    VFX_OBJ_CREATE_EX(scr, VfxRightsMgrScr1, this, (args));
    scr->show();
}


VFX_IMPLEMENT_CLASS("VfxRightsMgrScr1", VfxRightsMgrScr1, VfxMainScr);


void VfxRightsMgrScr1::onConfirmClicked(VfxId id, void *userData)
{
switch(id)
 {
 case VCP_CONFIRM_POPUP_BUTTON_USER_1:
    vapp_rmgr_list_ro_delete_all_entry();
	break;
 }
}



void VfxRightsMgrScr1::onCommandCallClick(VfxId id, void *userData)
{
	S32 popup_indx =0;
	switch(id)
	{
     case VCP_CONFIRM_POPUP_BUTTON_USER_1:
		  mmi_rmgr_send_rights_request();
		  vapp_rmgr_set_is_dl_popup(0);
		  break;
     case VCP_CONFIRM_POPUP_BUTTON_USER_2:
        mmi_rmgr_wipe_unlock_session();
		vapp_rmgr_set_is_dl_popup(0);
		break;
	 case VCP_POPUP_BUTTON_NO_PRESSED:
		 popup_indx = vapp_rmgr_get_is_dl_popup();
		 vcp_global_popup_cancel(popup_indx);
		 vapp_rmgr_set_is_dl_popup(0);
         mmi_rmgr_wipe_unlock_session();
		 break;
	 default:
		 popup_indx = vapp_rmgr_get_is_dl_popup();
		 vcp_global_popup_cancel(popup_indx);
		 vapp_rmgr_set_is_dl_popup(0);
         mmi_rmgr_wipe_unlock_session();
		break;
    }

}

void VfxRightsMgrScr1::on1stReady()
{
    VfxMainScr::on1stReady();
    
   
	if(args==RMGR_ENTRY_MENU)
	{
		VFX_OBJ_CREATE(page, VfxRmgrPage1, this);
		pushPage(0, page);
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
#endif
	if(args==RMGR_ENTRY_FORMAT_CALLBACK_ABORTED)
	{
     VFX_OBJ_CREATE(page, VfxRmgrPageFormatCbAbt, this);
	  pushPage(0, page);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
	if(args==RMGR_REQUEST_RIGHTS_ERROR)
	{
		VFX_OBJ_CREATE(page, VfxRmgrPageGetRightsErr,this);
		pushPage(0, page);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
	if(args==RMGR_ENTRY_DB_CONFIRM)
	{
		VFX_OBJ_CREATE(page, VfxRmgrPageDBEntry, this);
		pushPage(0,page);
	}

}


void VfxRightsMgrScr1::on2ndReady()
{
	kal_uint8 serial;
	VfxRmgrPage1 *view = VFX_OBJ_DYNAMIC_CAST(page, VfxRmgrPage1);
	if (view)
	{
		VFX_OBJ_CREATE(m_popup, VcpIndicatorPopup, view);
		m_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
		m_popup->setText(VFX_WSTR_RES(STR_GLOBAL_DRM_PROCESSING));
		m_popup->setAutoDestory(VFX_TRUE);
		m_popup->show(VFX_TRUE);
		VappRmgrServiceInterface::m_getROnumCallback.connect(view , &VfxRmgrPage1::mmi_rmgr_list_ro_get_num_callback);
		DRM_get_ro_num(&serial,(&VappRmgrServiceInterface::getROnumhdlr),DRM_DB_GET_INVALID);
}
}

extern "C" void vtst_rmgr_list_entry(VfxMainScr *scr)
{ 
	
	/*VfxAppLauncher::launchWithAsmSize(
        APP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr1),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);*/
/*
	id=RMGR_ENTRY_MENU;
	VfxAppLauncher::launch( 
        VAPP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr),
        GRP_ID_ROOT,&id,(sizeof(id)));
*/
	id=RMGR_ENTRY_MENU;
	mmi_id groupId = VfxAppLauncher::createCui(
        VAPP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr),
        scr->getGroupId(), &id, (sizeof(id)));

    VfxAppLauncher::runCui(groupId);

	return;
}





extern "C" void vtst_rmgr_list_entry_format(void)
{ 
	
	/*VfxAppLauncher::launchWithAsmSize(
        APP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr1),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);*/
   /* id=RMGR_ENTRY_FORMAT;
	VfxAppLauncher::launch( 
        VAPP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr1),
        GRP_ID_ROOT, &id, (sizeof(id)));
*/

	vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_WARNING, 
        STR_ID_RMGR_DELETE_ALL_QUERY, 
        STR_GLOBAL_DELETE, 
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        &VfxRightsMgrScr1::onConfirmClicked,
        NULL
        );

	return;
}
static MMI_BOOL vapp_rmgr_format_failure_popup(mmi_scenario_id scen_id, void *arg)
{
	S32 *temp=(S32 *)arg;

	vcp_global_popup_show_confirm_one_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_FAILURE,
            srv_fmgr_fs_error_get_string(*temp),
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
	return MMI_TRUE;
}

static MMI_BOOL vapp_rmgr_request_failure_popup(mmi_scenario_id scen_id, void *arg)
{
	 vcp_global_popup_show_confirm_one_button_id(
                        GRP_ID_ROOT,
                        VCP_POPUP_TYPE_FAILURE, 
                        STR_GLOBAL_DRM_PROHIBITED, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,  
                        NULL,
                        NULL);
	 return MMI_TRUE;
	 
}


static MMI_BOOL vapp_rmgr_request_default_popup(mmi_scenario_id scen_id, void *args)
{
	  S32 *i = (S32 *)args;
	  vcp_global_popup_show_confirm_one_button_id(
                        GRP_ID_ROOT,
                        VCP_POPUP_TYPE_FAILURE, 
                        srv_fmgr_fs_error_get_string(*i), 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,  
                        NULL,
                        NULL);
                        
    return MMI_TRUE;                    
	
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
#endif

extern "C" void vtst_rmgr_list_entry_format_cb(S32 result)
{ 
	

	if(result==DRM_RESULT_OK)
	{
			vcp_global_popup_show_confirm_one_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_SUCCESS,
            STR_GLOBAL_DELETED,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
	}
    else
    {
		if(result==DRM_RESULT_CANCELED)
		{
			id=RMGR_ENTRY_FORMAT_CALLBACK_ABORTED;
			VfxAppLauncher::launch( 
    	    VAPP_RMGR,
        	VFX_OBJ_CLASS_INFO(VappRightsMgr1),
	        GRP_ID_ROOT, &id, (sizeof(id)));
			return;
		}
		else
		{
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, vapp_rmgr_format_failure_popup, (void *)&result);

            			
		}
    }
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


extern "C" void vtst_request_rights_confirm_ext(U32 i)
{
 
	switch(i)
	{

	case 1: 
        id=RMGR_REQUEST_RIGHTS_ERROR;
		VfxAppLauncher::launch( 
        VAPP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr1),
        GRP_ID_ROOT, &id, (sizeof(id)));
        break;
	
	case 2:
		              mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, vapp_rmgr_request_failure_popup, NULL);
                      
        break;

	default:
	     mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, vapp_rmgr_request_default_popup, &i);
		break;
	}
}



extern "C"  void vapp_rmgr_request_rights_confr()
{

	S32 index;
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
#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


index =	vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_QUESTION, 
        STR_ID_RMGR_DL_LICENSE, 
        STR_GLOBAL_DOWNLOAD, 
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        &VfxRightsMgrScr1::onCommandCallClick,
        NULL
        );

vapp_rmgr_set_is_dl_popup(index);
	return;
}


extern "C" mmi_ret vapp_rmgr_show_process_info(mmi_event_struct *evt)
{
	
mmi_rmgr_dlagent_evt_struct	*evt_struct = (mmi_rmgr_dlagent_evt_struct *) evt;
	//S32 res;
    //U16 str;
switch(evt_struct->evt_type)
	{
	case MMI_EVENT_SUCCESS:
        //str=get_rmgr_str_id();
        vcp_global_popup_show_confirm_one_button_id(
                        GRP_ID_ROOT,
                        VCP_POPUP_TYPE_SUCCESS, 
                        evt_struct->str_id, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,  
                        NULL,
                        NULL);
		break;

	case MMI_EVENT_FAILURE:
		 	   vcp_global_popup_show_confirm_one_button_id(
                        GRP_ID_ROOT,
                        VCP_POPUP_TYPE_FAILURE, 
                        evt_struct->str_id, 
                        STR_GLOBAL_OK, 
                        VCP_POPUP_BUTTON_TYPE_NORMAL,  
                        NULL,
                        NULL);
		break;
	
	default:
		break;
     }   
	
return MMI_RET_OK;
}

extern "C" void vapp_rmgr_db_entry_check()
{

		id=RMGR_ENTRY_DB_CONFIRM;
		VfxAppLauncher::launch( 
        VAPP_RMGR,
        VFX_OBJ_CLASS_INFO(VappRightsMgr1),
        GRP_ID_ROOT, &id, (sizeof(id)));
   
		return;
}



extern "C" void mmi_rmgr_highlight_db_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //   SetKeyHandler(mmi_rmgr_entry_db, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 //   SetLeftSoftkeyFunction(mmi_rmgr_entry_db, KEY_EVENT_UP);
}




extern "C" void mmi_rmgr_highlight_list_ro(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_rmgr_set_execute_key_hdlr(mmi_rmgr_list_ro_entry_main);
}

extern "C" void mmi_rmgr_highlight_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set default white list url index as 0 */
#if 0
#ifdef __DRM_V02__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


extern "C" void mmi_rmgr_highlight_info(void)
{


}






#endif /*__DRM_SUPPORT_*/


