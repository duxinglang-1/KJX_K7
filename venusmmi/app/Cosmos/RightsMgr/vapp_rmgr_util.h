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
 *  Vapp_rmgr_util.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Vapp_rmgr_util.h
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/


extern "C"
{
//#include "CommonScreens.h"
#include "GlobalDefs.h"
//#include "Drm_gprot.h"
#include "FileMgrSrvGProt.h"
#include "App_str.h"
}

#include "MMI_features.h" 
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"

#ifdef __MMI_RMGR__
#include "mmi_rp_vapp_rmgr_def.h"
#define MAX_LIC 256

/**
 struct
	{
		S32 ro_num;
        VfxBool refresh;
	}mmi_vfx_list_ro_cntx_stuct;
*****/



class VfxRmgrPage1: public VfxPage,public IVcpListMenuContentProvider
{
	VFX_DECLARE_CLASS(VfxRmgrPage1);
public:
	static VfxSignal2<kal_uint8 * ,kal_int32 >m_getROnumCallback;
	VfxRmgrPage1()
	{
		toolbar = NULL;
	}
	VcpToolBar* toolbar; 


	void mmi_rmgr_list_ro_get_num_callback(kal_uint8 *serial, kal_int32 result);

protected:
	virtual void onInit();
	virtual void onEnter(VfxBool isback);
    virtual void onBack();	
    virtual void onDeinit();
    virtual void onTapItem(VcpListMenu *listMenu, VfxU32 itemIndex);
    void VappRmgrLongTapDelete(VcpMenuPopup * menu,  VcpMenuPopupEventEnum event, VcpMenuPopupItem * item);
    virtual void onLongTapItem(VcpListMenu *listMenu, VfxU32 itemIndex);
    void VappRmgrDeleteAllconfirm(VfxObject*obj, VfxId id);
   //void mmi_rmgr_reboot_ms(void *msg);
   virtual VfxU32 getCount(void) const;
   virtual VfxBool getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    );
   VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
	toolbar->setDisableItem(1, VFX_TRUE);
        text.loadFromRes(STR_ID_RMGR_NO_LIC);
        return VFX_TRUE;
    }

    
	S32 mmi_rmgr_get_alias_item(S32 index, UI_string_type str_buff);
	S32 mmi_rmgr_get_alias_item_same(S32 index, UI_string_type str_buff);
	void vapp_rmgr_sweep_entry_progress();
	void VfxRmgrPage1::mmi_vfx_rmgr_process_database_callback(kal_uint8 serial, kal_int32 result);
	void VfxRmgrPage1::mmi_vfx_rmgr_list_ro_del_callback_same(kal_uint8 serial, kal_int32 result);
	void VfxRmgrPage1::VappRmgrDeleteconfirm(VfxObject*obj, VfxId id);
	
   /* virtual VfxPage *onCreateTabPage(VfxId tabId)
	{
		VfxPage *page;

		switch(tabId)
		{
		case 1:
		case 2:
			VFX_OBJ_CREATE(licencepage,VfxRmgrPage1,this);
                    page = licencepage;
             break;
		default:
			break;
		}
		return page;
	}
public:
	VfxBool getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    
    text.loadFromMem(strLicenses[index]);

	return VFX_TRUE;
           
}*/

private:
	void eventHandler(VfxObject* obj, VfxId id);
	VfxRmgrPage1*licencepage;
	VcpListMenu *list;
	VcpForm* form;
	VfxU8 flag;
    kal_int32 rmgr_vfx_list_ro_cntx;
	UI_string_type str_buff;
	S8 ro_alias[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH];
 
	 enum
    {
        ID_TOOLBAR_SAVE,
        ID_TOOLBAR_CANCEL,
		ID_ADD_IM
    };
	   enum
    {
       
        BUTTON_W    = 305,
        BUTTON_H    = 45,
        TEXT_W      = 320,
        TEXT_H      = 25
    };

	  enum
    {
        ITEM_WIDTH  = 320,
        ITEM_HEIGHT = 84,
        GAP         = 9,
        TXT_Y       = 18,
        TXT_Y_GAP   = 6
    };
};


class VfxDetailPage: public VfxPage
{
	VFX_DECLARE_CLASS(VfxDetailPage);
	//static mmi_vfx_list_ro_cntx_struct mmi_vfx_list_ro_cntx;
    //static void mmi_vfx_rmgr_get_num_callback(kal_uint8 serial, kal_int32 result, VfxDetailPage*obj);


	public:
	 void eventHandler(VfxObject* obj, VfxId id);
		//VfxDetailPage();       //constructor for the details page
        //void VfxGetDetail(VcpListMenu *listMenu, VfxU32 itemIndex);
	    //void mmi_vfx_rmgr_get_num_ro_callback(kal_uint8 serial, kal_int32 result);
          //void mmi_vfx_rmgr_populate_info(U8 app_perm, U8 *data, S32 buf_size, S32 ref);

	private:
		VfxChar ro_alias[510];
		VcpForm *d_form;
		  enum
    {
		DETAIL_TOOLBAR_CANCEL,
        ID_TOOLBAR_SAVE,
        ID_TOOLBAR_CANCEL,
        ID_ADD_NUMBER,
        ID_ADD_EMAIL,
        ID_ADD_SNS,
        ID_ADD_IM,
        ID_ADD_ADDRESS,
        ID_NUM_BASE
    };
	protected:
		virtual void onInit();
		 void rmgr_detail();
		
		 void VappRmgrDeleteconfirm(VfxObject*obj, VfxId id);
		 void mmi_vfx_rmgr_list_ro_del_callback(kal_uint8 serial, kal_int32 result);
		// pBOOL mmi_rmgr_get_alias_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
	    //void mmi_vfx_rmgr_populate_drm_info(U8 app_perm,U8* data, S32 buf_size, S32 ref);


};



#endif /*#ifdef __MMI_RMGR__*/

