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
 *  RightsMgrSweep.c
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
 *
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
#include "Drm_gprot.h"
#include "Drm_def.h"
#include "GlobalConstants.h"
#include "RightsMgrProt.h"
#include "Vapp_rmgr_cntx.h"
#include "Drm_memory.h"
#include "TimerEvents.h"
#include "Wgui_categories_util.h"
#include "DateTimeGProt.h"
}

#include "MMI_features.h" 
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
#include "mmi_rp_vapp_rmgr_def.h"
#include "Mmi_rp_app_cosmos_global_def.h"
#include "FileMgrGProt.h"
#ifdef __MMI_RMGR__




VcpIndicatorPopup *del_popup;

extern "C"  kal_uint8 DRM_get_object_method_by_ref(kal_int32 ro_index, drm_proc_db_ro_count_flag_enum flag);
extern "C" int get_rmgr_list_index();
extern "C" S8 *mmi_vfx_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize);
extern "C" void mmi_rmgr_list_ro_entry_detail();
extern "C" S8 *mmi_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize);
extern VfxS8 arr_indx[];
/*********** 12/11 ******************/
class VappRmgrServInterface 
{
public:
	static void delROhdlr(kal_uint8 , kal_int32);
    static VfxSignal2<kal_uint8 ,kal_int32 > delROCallback; 
};
VfxSignal2<kal_uint8 ,kal_int32 > VappRmgrServInterface::delROCallback;

void VappRmgrServInterface::delROhdlr(kal_uint8 index , kal_int32 result)
{  
	VfxU32 i=get_rmgr_list_index();
	delROCallback.emit(index, result);

}

/************ 12/11 ************************************/


VFX_IMPLEMENT_CLASS("VfxDetailpage", VfxDetailPage, VfxPage);

/************** 12/11************************/

void VfxDetailPage::mmi_vfx_rmgr_list_ro_del_callback(kal_uint8 serial, kal_int32 result)
{
VcpConfirmPopup *d_popup;
 if(result==DRM_RESULT_OK)
		{
				U16 count =  get_licence_count();
				set_licence_count(--count);
	 }
else
{
	if(result==DRM_RESULT_CANCELED)
	{
		VFX_OBJ_CREATE(d_popup, VcpConfirmPopup, this);
		d_popup->setInfoType(VCP_POPUP_TYPE_WARNING);
		d_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		 d_popup->setText(VFX_WSTR_RES(STR_GLOBAL_ABORT));
		 d_popup->setAutoDestory(VFX_TRUE);
         d_popup->show(VFX_TRUE);
         del_popup->hide(VFX_TRUE);
         return;
         
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
        del_popup->exit(VFX_TRUE);
        return;
	}

}
 del_popup->exit(VFX_TRUE);
 getMainScr()->popPage();
    
}




/***************** 12/11 ****************/ 

	  




void VfxDetailPage::VappRmgrDeleteconfirm(VfxObject*obj, VfxId id)
{
	VfxU32 i;
	
	switch(id)
	{
	case VCP_CONFIRM_POPUP_BUTTON_USER_1 :
		vapp_rmgr_set_del_item(1);
        VFX_OBJ_CREATE(del_popup,VcpIndicatorPopup,this);
        del_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
        del_popup->setText(VFX_WSTR_RES(STR_GLOBAL_DELETING));
	    del_popup->setAutoDestory(VFX_TRUE);
        del_popup->show(VFX_TRUE); 
        i=get_rmgr_list_index();
		VappRmgrServInterface::delROCallback.connect(this , &VfxDetailPage::mmi_vfx_rmgr_list_ro_del_callback);
		 DRM_process_database(
            DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_ALL,
            i,
            NULL,
            NULL,
            (&VappRmgrServInterface::delROhdlr));
        


/****		 
    VfxPage *page;
    VFX_OBJ_CREATE(page, VfxRmgrPage1, this);
    pushPage(50, page);
***/
       //getMainScr()->popPage();
       break;

	


	   }
}


/**************** 12/11 *********************/

void VfxDetailPage::eventHandler(VfxObject* obj, VfxId id)
{	
	VcpConfirmPopup *d_pop;
	
 switch(id)
    { 
	case DETAIL_TOOLBAR_CANCEL:
         VFX_OBJ_CREATE(d_pop, VcpConfirmPopup, this);
    d_pop->setInfoType(VCP_POPUP_TYPE_WARNING);
    d_pop->setText(VFX_WSTR_RES(STR_ID_RMGR_DEL_VALID_LIC));
  //  d_pop->addItem('Righ', VFX_WSTR("Delete"));
  //  d_pop->addItem('Left', VFX_WSTR("Cancel"));
    d_pop->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	d_pop->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL) ,  VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL); 
	
    d_pop->setAutoDestory(VFX_TRUE);
	d_pop->m_signalButtonClicked.connect(this,&VfxDetailPage::VappRmgrDeleteconfirm);
	d_pop->show(VFX_TRUE);
	
		break;


    default:
		getMainScr()->popPage();
		break;
	}
}



void VfxDetailPage ::rmgr_detail()
{
	VcpForm *m_form;
    //VcpFormItemSwitchCell* m_switchTypeSetting;
	//VcpAlertPopup *m_alertPopup;
	//kal_int32 i;
	VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(320, 480);
    //m_form->setStyle(VCPFORM_TOTAL_STYLES);
  // i=DRM_get_version();
    

}





void VfxDetailPage::onInit()
{
	//S32 dest_size= MAX_SUB_MENUS * MAX_SUB_MENU_SIZE;
	//U8 *info;
	//VfxU16 viewText[1000] = {' A', 'm', 'i', 't'} ;
	kal_wchar* p=NULL;

/* varibles for function aux */
	U8 app_perm= DRM_PERMISSION_ALL;
	S32 cons_ret = DRM_RESULT_NON_DRM;
	//MMI_BOOL result = MMI_FALSE, flag = MMI_TRUE;
	U8 permission;
    drm_method_enum method;
	//MMI_BOOL is_installable;
	//MMI_BOOL is_printable;




	U32 i;
	//U8* data;
	VfxPage::onInit();
	//kal_uint8 serial;
    //VcpForm *m_form;
    //VcpFormItemSwitchCell* m_switchTypeSetting;
	VcpTitleBar *m_title;
	VFX_OBJ_CREATE(m_title, VcpTitleBar, this);
	p=get_detail_item_name();
	m_title->setTitle(VFX_WSTR_RES(STR_ID_RMGR_LIC_DETAILS));
	m_title->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
	setTopBar(m_title);
    
	
	VcpToolBar *toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    
	setBottomBar(toolbar); 
    toolbar->addItem(DETAIL_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_DELETE), IMG_ID_VAPP_RMGR_DELETE); // add tool bar "cancel" button
    toolbar->m_signalButtonTap.connect(this, &VfxDetailPage::eventHandler);          // connect tool bar signal

	
	
	setBgColor(VFX_COLOR_WHITE);
	
	i=get_rmgr_list_index();
	U8 ref= i;
	//m_text->setText((VfxWChar*)(info), VFX_TRUE, NULL);
	//m_text->setPos(0, m_title->getRect().getMaxY() + 25 + 1);
    VfxChar valid_flag = 0;
    valid_flag = DRM_get_ro_list(i, (char *)&ro_alias[0], SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,DRM_DB_GET_ALL);
	
    if(!valid_flag)
	{
		VfxTextFrame *text_frame;
		VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
		VfxWString page_hint;
		page_hint = VFX_WSTR_RES(STR_ID_RMGR_EXP_LIC);
		text_frame->setString(page_hint);
		text_frame->setAnchor(0.5,0.5);
		text_frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		text_frame->setPos(this->getSize().width/2,this->getSize().height/2);
		text_frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
		text_frame->setColor(VFX_COLOR_BLACK);
	}
	else
	{
	VcpForm *myForm = NULL;
	VFX_OBJ_CREATE(myForm, VcpForm, this);
	myForm->setPos(getPos());
	myForm->setSize(getSize());

	VcpFormItemCustomFrame *cust_frm_rmgr;
	VFX_OBJ_CREATE(cust_frm_rmgr, VcpFormItemCustomFrame, myForm);
    cust_frm_rmgr->setPos(myForm->getPos());

    VfxTextFrame *txt_frm;
	VFX_OBJ_CREATE(txt_frm, VfxTextFrame, cust_frm_rmgr);
	txt_frm->setString(VFX_WSTR_RES(STR_ID_RMGR_NAME));
	txt_frm->setBorderColor(VFX_COLOR_WHITE);
	txt_frm->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	txt_frm->setFont(VfxFontDesc(VFX_FONT_DESC_MEDIUM));
	cust_frm_rmgr->attachCustomFrame(txt_frm);
    myForm->addItem(cust_frm_rmgr, 1);

VfxU32 text_width = txt_frm->getSize().width;

VfxU32 text_height = txt_frm->getSize().height;
    VcpFormItemCustomFrame *cust_frm_rmgr1;
	VFX_OBJ_CREATE(cust_frm_rmgr1, VcpFormItemCustomFrame, myForm);
    cust_frm_rmgr1->setHeight(100);
	 VfxTextFrame *txt_frm_nm;
	VFX_OBJ_CREATE(txt_frm_nm, VfxTextFrame, myForm);
	VfxWString str;
	txt_frm_nm->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
	
	txt_frm_nm->setSize(getSize());
	
	//txt_frm_nm->setMaxLines(2);
	txt_frm_nm->setString(str.loadFromMem(p));
    
	txt_frm_nm->setFont(VfxFontDesc(VFX_FONT_DESC_SMALL));
	txt_frm_nm->setColor(VFX_COLOR_GREY);
	cust_frm_rmgr1->setHeight(txt_frm_nm->getSize().height);
    cust_frm_rmgr1->attachCustomFrame(txt_frm_nm);
	myForm->addItem(cust_frm_rmgr1, 2);
   


	DRM_MEM_START_EVAL

    method = (drm_method_enum)DRM_get_object_method_by_ref(ref, DRM_DB_GET_ALL);
	
	if (method == DRM_METHOD_FORWARD_LOCK)
    {
        drm_constraint_struct cons;
		DRM_get_constraint_by_ref(ref, DRM_PERMISSION_PLAY, &cons);
		VfxTextFrame *txt_frm1;
		/************ to do ******************/
		VFX_OBJ_CREATE(txt_frm1, VfxTextFrame, cust_frm_rmgr);
		txt_frm1->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_UNLIMITED));
        /************************************/

		 if (cons.status == DRM_STATUS_RIGHTS_PRESENT)
		 {
			 VFX_OBJ_CREATE(txt_frm1, VfxTextFrame, cust_frm_rmgr);
			 txt_frm1->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_UNLIMITED));
			 
		 }
		 else
		 {
			 VFX_OBJ_CREATE(txt_frm1, VfxTextFrame, cust_frm_rmgr);
		     txt_frm1->setString(VFX_WSTR_RES(STR_GLOBAL_INVALID));
	}

		 cust_frm_rmgr->attachCustomFrame(txt_frm1);
		 myForm->addItem(cust_frm_rmgr, 1);
		 goto final;
	}
	



	permission = DRM_PERMISSION_PLAY;
    //is_installable = is_printable = MMI_FALSE;

	do
	{

	 if (permission &
            (DRM_PERMISSION_PLAY | DRM_PERMISSION_DISPLAY | DRM_PERMISSION_EXECUTE | DRM_PERMISSION_PRINT |
             DRM_PERMISSION_EXPORT))
        {
            drm_constraint_struct cons;
            memset(&cons, 0, sizeof(drm_constraint_struct));
			cons_ret = DRM_get_constraint_by_ref(ref, permission, &cons);

          if (cons_ret >= DRM_RESULT_OK &&
		 (cons.status == DRM_STATUS_RIGHTS_PRESENT ||
			cons.status == DRM_STATUS_UNTRUSTED_TIME || cons.status == DRM_STATUS_RIGHTS_IN_FUTURE))
         
		  {

			  drm_constraint_struct *constraint=&cons;
				//U8 permission= (U8)permission;


				S16 tmp[64]; /* For 10^10 <count> constraint */
				//applib_time_struct t;
				S32 start = 0, end = 0;
				//U8 *buff = data;

				if (constraint->status != DRM_STATUS_RIGHTS_PRESENT &&
					 constraint->status != DRM_STATUS_UNTRUSTED_TIME &&
					 constraint->status != DRM_STATUS_RIGHTS_IN_FUTURE)
				{
					 // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
                        
					//  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

					  //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
					
					//  return;
}

if (constraint->type & DRM_CONSTRAINT_DATETIME)
    {
        /* two constraint
            |-------------------|
                      |----------------|
            A         B         C      D
            We should show B ~ C  */

        if ((constraint->type & DRM_CONSTRAINT_INTERVAL) && constraint->start_intv != 0)
        {
            if (constraint->start_time <= constraint->start_intv)
            {
                start = constraint->start_intv;
            }
            else
            {
                start = constraint->start_time;
            }

            /* there is a limitation time in end_time, or we just use the end_intv */
            if (constraint->end_time <= constraint->end_intv && constraint->end_time!=0)
            {
                end = constraint->end_time;
            }
            else
            {
                end = constraint->end_intv;
            }
        }
        else
        {
            start = constraint->start_time;
            end = constraint->end_time;
        }
    }
    else if (constraint->type & DRM_CONSTRAINT_INTERVAL)
    {
        if (constraint->interval <= 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            start = constraint->start_intv;
            end = constraint->end_intv;
        }
    }

	switch(permission)
        {
            case DRM_PERMISSION_PLAY:
                //myForm->insertSeparator(2);
	            myForm->addCaption(VFX_WSTR_RES(STR_ID_VAPP_DRM_PLAY));
                break;
            case DRM_PERMISSION_DISPLAY:
                //myForm->insertSeparator(2);
				myForm->addCaption(VFX_WSTR_RES(STR_ID_VAPP_DRM_DISPLAY));
                break;
            case DRM_PERMISSION_EXECUTE:
                //myForm->insertSeparator(2);
				myForm->addCaption(VFX_WSTR_RES(STR_ID_VAPP_DRM_EXECUTE));
                break;
            case DRM_PERMISSION_PRINT:
                //myForm->insertSeparator(2);
			    myForm->addCaption(VFX_WSTR_RES(STR_ID_VAPP_DRM_PRINT));
                break;
            default:
                break;
        }




	{

			
            if (constraint->type != DRM_CONSTRAINT_NONE)
            {
                if (constraint->type & DRM_CONSTRAINT_COUNT)
                {
	           // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_COUNT), buf_size);
                    if (constraint->total_count > 0xFFFFFFFF)
                    {
                        if (constraint->used_count > 0xFFFFFFFF)
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u%09u/%u%09u",
                                (kal_uint32) (constraint->used_count / 1000000000),
                                (kal_uint32) (constraint->used_count % 1000000000),
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }
                        else
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u/%u%09u",
                                (kal_uint32)constraint->used_count,
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }

                    }
                    else
                    {
                        kal_wsprintf(
                            (WCHAR*) tmp,
                            "\n%u/%u",
                            (kal_uint32) constraint->used_count,
                            (kal_uint32) constraint->total_count);
                    }

            
    VcpFormItemCustomFrame *cust_frm_rmgr3;
	VFX_OBJ_CREATE(cust_frm_rmgr3, VcpFormItemCustomFrame, myForm);
	VfxTextFrame *txt_frm_usgcnt;
	VFX_OBJ_CREATE(txt_frm_usgcnt, VfxTextFrame, cust_frm_rmgr3);
	VfxWString str1;
	txt_frm_usgcnt->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
	txt_frm_usgcnt->setMaxLines(2);
	txt_frm_usgcnt->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_COUNT_COSMOS));
    txt_frm_usgcnt->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	cust_frm_rmgr3->attachCustomFrame(txt_frm_usgcnt);
	myForm->addItem(cust_frm_rmgr3,4);

    VcpFormItemCustomFrame *cust_frm_rmgr2;
	VFX_OBJ_CREATE(cust_frm_rmgr2, VcpFormItemCustomFrame, myForm);
	VfxTextFrame *txt_frm_count;
	VFX_OBJ_CREATE(txt_frm_count, VfxTextFrame,cust_frm_rmgr2 );
	VfxWString str;
	txt_frm_count->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
	
	txt_frm_count->setMaxLines(2);
	txt_frm_count->setFont(VfxFontDesc(VFX_FONT_DESC_SMALL));
	txt_frm_count->setString(str.loadFromMem((VfxWChar*)tmp));
	txt_frm_count->setColor(VFX_COLOR_GREY);
    cust_frm_rmgr2->attachCustomFrame(txt_frm_count);
	myForm->addItem(cust_frm_rmgr2, 3);


  } //end of contraint->type & DRM....?



                if (start > 0)
                {
					//VfxU32 len;
					WCHAR *str_buf, *str_buf_time, *str_buf_space;
					MYTIME time;    //calender_time;
					//FLOAT time_zone;
					str_buf = (WCHAR *)OslMalloc(100);
					str_buf_time = (WCHAR *)OslMalloc(20);
					str_buf_space = (WCHAR *)OslMalloc(20);
					VcpFormItemCustomFrame *cust_frm_rmgr4;
					VFX_OBJ_CREATE(cust_frm_rmgr4, VcpFormItemCustomFrame, myForm);
					//cust_frm_rmgr4->setPos(0, 180+10);     /************/
					VfxTextFrame *txt_frm_time1;
					VFX_OBJ_CREATE(txt_frm_time1, VfxTextFrame, cust_frm_rmgr4);
					VfxWString str2;
					txt_frm_time1->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
					txt_frm_time1->setMaxLines(2);
					txt_frm_time1->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_START_COSMOS));
					txt_frm_time1->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
					cust_frm_rmgr4->attachCustomFrame(txt_frm_time1);
					//time_zone= mmi_dt_get_tz();
					myForm->addItem(cust_frm_rmgr4,5);
                    mmi_dt_utc_sec_2_mytime(start, &time, MMI_FALSE);
					//mmi_dt_utc_to_rtc(time_zone, time, calender_time);
					date_string(&time, (UI_string_type)str_buf, DT_IDLE_SCREEN);
					/*Akhil time*/

					 
				    mmi_rmgr_ucs2cat_secure((PS8) str_buf, (PS8) L"      ", 50);

					time_string(&time, (UI_string_type)str_buf_time, DT_IDLE_SCREEN);

					mmi_rmgr_ucs2cat_secure((PS8) str_buf, (PS8) str_buf_time, 50);
                    
					VfxWString title1;
					title1.loadFromMem((VfxWChar*)str_buf);
					VcpFormItemCustomFrame *cust_frm_rmgr5;
					VFX_OBJ_CREATE(cust_frm_rmgr5, VcpFormItemCustomFrame, myForm);
					VfxTextFrame *txt_frm_date;
					VFX_OBJ_CREATE(txt_frm_date, VfxTextFrame, this);
					
					txt_frm_date->setString(title1);
					txt_frm_date->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
					txt_frm_date->setMaxLines(2);
					txt_frm_date->setFont(VfxFontDesc(VFX_FONT_DESC_SMALL));
					txt_frm_date->setColor(VFX_COLOR_GREY);
					cust_frm_rmgr5->attachCustomFrame(txt_frm_date);
					myForm->addItem(cust_frm_rmgr5, 5);
	


					VcpFormItemCustomFrame *cust_spc_frm;
					VFX_OBJ_CREATE(cust_spc_frm, VcpFormItemCustomFrame, myForm);
					VfxTextFrame *txt_spc;
					VFX_OBJ_CREATE(txt_spc, VfxTextFrame, this);
					memset(str_buf_space,0, sizeof(str_buf_space));
					mmi_rmgr_ucs2cat_secure((PS8) str_buf_space, (PS8) L"\n", 10);
					VfxWString line_space1;
					line_space1.loadFromMem((VfxWChar*)str_buf_space);
					txt_spc->setString(line_space1);
					txt_spc->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
					cust_spc_frm->attachCustomFrame(txt_spc);
					myForm->addItem(cust_spc_frm, 6);


                                        OslMfree(str_buf);
                                        OslMfree(str_buf_time);
					OslMfree(str_buf_space);
                    
                   
                }

                if (end > 0)
                {
					//VfxU32 len;
					WCHAR *str_buf, *str_buf_time;
					MYTIME time;   //, calender_time;
					//FLOAT time_zone;
					str_buf = (WCHAR *)OslMalloc(50);
					str_buf_time = (WCHAR *)OslMalloc(20);
					VcpFormItemCustomFrame *cust_frm_rmgr5;
					VFX_OBJ_CREATE(cust_frm_rmgr5, VcpFormItemCustomFrame, myForm);

					VfxTextFrame *txt_frm_time1;
					VFX_OBJ_CREATE(txt_frm_time1, VfxTextFrame, cust_frm_rmgr5);
					VfxWString str2;
					txt_frm_time1->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
					txt_frm_time1->setMaxLines(2);
					txt_frm_time1->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_END_COSMOS));
					txt_frm_time1->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
					cust_frm_rmgr5->attachCustomFrame(txt_frm_time1);
					//time_zone= mmi_dt_get_tz();
					myForm->addItem(cust_frm_rmgr5,5);
                    mmi_dt_utc_sec_2_mytime(end, &time, MMI_FALSE);
					//mmi_dt_utc_to_rtc(0, time, calender_time);
					//date_string(&calender_time, (UI_string_type)str_buf, DT_IDLE_SCREEN);
					date_string(&time, (UI_string_type)str_buf, DT_IDLE_SCREEN);

                    mmi_rmgr_ucs2cat_secure((PS8) str_buf, (PS8) L"      ", 50);

					time_string(&time, (UI_string_type)str_buf_time, DT_IDLE_SCREEN);
                    
					mmi_rmgr_ucs2cat_secure((PS8) str_buf, (PS8) str_buf_time, 50);


					VfxWString title1;
					title1.loadFromMem((VfxWChar*)str_buf);
					VcpFormItemCustomFrame *cust_frm_rmgr6;
					VFX_OBJ_CREATE(cust_frm_rmgr6, VcpFormItemCustomFrame, myForm);
					VfxTextFrame *txt_frm_date;
					VFX_OBJ_CREATE(txt_frm_date, VfxTextFrame, this);
					txt_frm_date->setString(title1);
					txt_frm_date->setFont(VfxFontDesc(VFX_FONT_DESC_SMALL));
					txt_frm_date->setColor(VFX_COLOR_GREY);
					cust_frm_rmgr6->attachCustomFrame(txt_frm_date);
					myForm->addItem(cust_frm_rmgr6, 6);

				   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_END), buf_size);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                   // mmi_dt_utc_sec_2_mytime(end, &t, MMI_FALSE);
                    //date_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                   // time_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                  //  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }
             
			} // end of constraint_type->!=DRM_CONSTRAINT_NONE
			 else
            {
                
				VcpFormItemCustomFrame *cust_frm_rmgr7;
					VFX_OBJ_CREATE(cust_frm_rmgr7, VcpFormItemCustomFrame, myForm);
					VfxTextFrame *txt_frm_unlimited;
					VFX_OBJ_CREATE(txt_frm_unlimited, VfxTextFrame, this);
					txt_frm_unlimited->setString(VFX_WSTR_RES(STR_ID_RMGR_DETAIL_UNLIMITED));
					txt_frm_unlimited->setFont(VfxFontDesc(VFX_FONT_DESC_MEDIUM));
					txt_frm_unlimited->setColor(VFX_COLOR_GREY);
					cust_frm_rmgr7->attachCustomFrame(txt_frm_unlimited);
					myForm->addItem(cust_frm_rmgr7, 7);
            }
         }
	  }
         //flag=KAL_FALSE;
		 permission = permission << 1;
	}

}
while(permission < DRM_PERMISSION_EXPORT && permission <= app_perm);
final:
	{
        DRM_free_ro_detail();
    }
	DRM_MEM_END_EVAL
}



}
#endif /*  __MMI_RMGR__ */

	

