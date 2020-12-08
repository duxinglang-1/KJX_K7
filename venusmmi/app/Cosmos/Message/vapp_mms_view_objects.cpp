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
 *  vapp_mms_viewer.cpp
 *
 * Project:
 * --------
 *  MMS Viewer
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
 *------------------------------------------------------------------------------*/

// This include is for proc call
#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "mmi_rp_vapp_mms_def.h"
extern "C"
{
#include "MMIDatatype.h"
#include "GlobalDefs.h"
#include "SettingProfileEnum.h"
#include "MmsXMLDefSrv.h"
#include "MmsSrvGprot.h"
#include "MmsMemoryManagerSrv.h"
#include "MMSAppCommonGprot.h"
#include "ebrsrvgprot.h"
#ifdef __MMI_EBOOK_READER__
	#include "mmi_rp_app_ebook_def.h"
#endif
#include "Imageviewcuigprot.h"
#include "vcui_gallery_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_inet_app_trc.h"
}
#include "vcui_music_player_gprot.h"
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vapp_mms_data.h"
#include "vapp_mms_viewer.h"
#include "vapp_mms_view_objects.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"

#ifdef __MMI_EBOOK_READER__
	extern "C" void mmi_fmgr_ebook_option_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
#endif

VFX_IMPLEMENT_CLASS("VappMmsViewObjectsPage", VappMmsViewObjectsPage, VfxPage);
void VappMmsViewObjectsPage::onInit()
{
	VfxPage::onInit();
	srv_mms_viewer_attachment_info_struct *attach_list = NULL;
	srv_mms_viewer_get_attachment_list(&attach_list, &m_attachment_count);
	VfxXmlLoader::loadBegin(this, VENUS_MMS_LAYOUT_MMS_VIEW_OBJECTS);
	m_list = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("ViewObjectsList")), VcpGroupListMenu);
	m_list->setContentProvider(this);
	m_list->m_signalFocusChanged.connect(this, &VappMmsViewObjectsPage::OnListFocused);
	m_list->m_signalItemTapped.connect(this, &VappMmsViewObjectsPage::onObjectTapped);
	m_list->setSize(getSize());
	m_list->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);
	VfxXmlLoader::loadEnd();
}

void VappMmsViewObjectsPage::onDeinit(void)
{
	VfxPage::onDeinit();
	txt_not_present = VFX_FALSE;
	grp_pos = -1;
}

void VappMmsViewObjectsPage::OnListFocused(VcpGroupListMenu * sender, // Sender
        VcpMenuPos new_pos,        // Current focus list item index
        VcpMenuPos old_pos        // Previous focus list item index
		)
{
	if(sender == m_list)
	{
		if(new_pos.pos!=0xffffffff)
		{
			VfxWString text;
			//m_list->getItemTextIfPresent(new_pos,VCP_LIST_MENU_FIELD_TEXT,text);
		}
	}
}

 VfxBool VappMmsViewObjectsPage::getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        ) 
 {
	srv_mms_viewer_object_struct *obj = getObjectFromPos(pos);
	VfxU32 img_id = IMG_ID_VENUS_MMS_UNKNOWN_FILE;
	switch(obj->type)
	{
		case SRV_MMS_OBJECT_TYPE_TEXT:
			img_id = IMG_ID_VENUS_MMS_TEXT_FILES;
			break;
		case SRV_MMS_OBJECT_TYPE_IMAGE:
			img_id = IMG_ID_VENUS_MMS_IMAGE_FILES;
			break;
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__        
		case  SRV_MMS_OBJECT_TYPE_VIDEO:
			img_id = IMG_ID_VENUS_MMS_VIDEO_FILE;
			break;
    #endif        
		case SRV_MMS_OBJECT_TYPE_AUDIO:
			img_id = IMG_ID_VENUS_MMS_AUDIO_FILE;
			break;
		case SRV_MMS_OBJECT_TYPE_ATTACHMENT:
			{
             #ifdef __MMI_VCARD__ 
				S8 vcf_ext[] = {'v',0,'c',0,'f',0,0,0};
             #endif
             #ifdef __MMI_VCALENDAR__ 
				S8 vcs_ext[] = {'v',0,'c',0,'s',0,0,0};
             #endif
				VfxU16 *file_name = getFileName(obj, this);
				 U16 *file_ext = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) file_name);
				 if(file_ext)
				 {
                 #ifdef __MMI_VCARD__ 
					 if(mmi_ucs2icmp((S8 *)file_ext, (S8 *)vcf_ext) == 0)
					 {
						img_id = IMG_ID_VENUS_MMS_VCARD_FILE;
					 }
                 #endif
                 #ifdef __MMI_VCALENDAR__ 
					 if(mmi_ucs2icmp((S8 *)file_ext, (S8 *)vcs_ext) == 0)
					 {
						img_id = IMG_ID_VENUS_MMS_VCALENDAR_FILE;
					 }
                 #endif
                 #if !defined(__MMI_VCALENDAR__) &&  !defined(__MMI_VCARD__)
                        img_id = IMG_ID_VENUS_MMS_UNKNOWN_FILE;
                 #endif                    
				   }
				   else
				  {
				    	img_id = IMG_ID_VENUS_MMS_UNKNOWN_FILE;
				   }
				 VFX_FREE_MEM(file_name);
			}
			break;
		default:
			img_id = IMG_ID_VENUS_MMS_UNKNOWN_FILE;
	}
	 image.setResId(img_id);
	 return VFX_TRUE;
 }

VfxBool VappMmsViewObjectsPage::getItemText(
    VcpMenuPos pos,                    // // [IN] the position of item
    VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
    VfxWString &text,                  // [OUT] the text resource
    VcpListMenuTextColorEnum &color   // [OUT] the text color
    )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT || fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        srv_mms_viewer_object_struct *obj = NULL;
        VfxU16 *file_name = NULL;
        obj = getObjectFromPos(pos);
        if(obj)
        {
            file_name = getFileName(obj, this);
        }
        if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text.loadFromMem(file_name);
        }
        else
        {
            char buffer[52];
            VfxU16 ucs[100];
            int size = obj->size / VIEW_OBJECT_SIZE_CONVERTOR, size3;
            float size2 = (float)obj->size / VIEW_OBJECT_SIZE_CONVERTOR - size;
            size3 = (int) size2 * 10;
            memset(buffer, 0, sizeof(VfxS8) * 50);
            if(size || size3)
            {
                sprintf(buffer, "%d.%d", size, size3);
            }
            else
            {
                sprintf(buffer, "%d", obj->size);
            }
            mmi_asc_n_to_wcs(ucs, (char *)buffer, 6);
            text.loadFromMem(ucs);
            if(size || size3)
            {
                text += VFX_WSTR(" KB");
            }
            else
            {
                text += VFX_WSTR(" B");
            }
        }
        VFX_FREE_MEM(file_name);
        m_hilited_index = pos;
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
    {
        VfxU16 tempbuffer[VIEW_OBJECT_SLIDE_STR_SIZE] = {0,};
        VfxWString txt1, txt2;
        if(m_attachment_count && pos.group == getGroupCount() - 1)
        {
            text = VFX_WSTR_RES(STR_GLOBAL_ATTACHMENT);
        }
        else
        {
            text = VFX_WSTR_RES(STR_ID_VAPP_MMS_SLIDE);
            kal_wsprintf(tempbuffer, " %d", 1 + pos.group);
            text += txt1.loadFromMem(tempbuffer);
        }
    }
    color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
    return VFX_TRUE;
}
srv_mms_viewer_object_struct * VappMmsViewObjectsPage::getObjectFromPos(VcpMenuPos pos)
{
    srv_mms_viewer_object_struct *obj = NULL;
    grp_pos = pos.group;
    srv_mms_viewer_slide_struct *slide = srv_mms_viewer_get_slide_by_index(pos.group);
    if(m_attachment_count && pos.group == getGroupCount() - 1)
    {
        srv_mms_viewer_attachment_info_struct *attach_list = NULL;
        VfxU32 num_attach = 0, count = 0;
        srv_mms_viewer_get_attachment_list(&attach_list, &num_attach);
        while(attach_list != NULL && count != pos.pos)
        {
            attach_list = attach_list->next;
            count++;
        }
        obj = attach_list->object;
    }
    else
    {
        if(slide->txt.id)
        {
            txt_not_present = VFX_FALSE;
        }
        else
        {
            txt_not_present = VFX_TRUE;
        }
        switch(pos.pos)
        {
            case 0:
                if(slide->txt.id)
                {
                    obj = slide->txt.object;
                    grp_pos = -1;
                    break;
                }
                else
                {
                    grp_pos = pos.group;
                }
            case 1:
                if(slide->img.id && !(txt_not_present == VFX_TRUE && pos.pos == 1 && grp_pos == pos.group) )
                {
                    obj = slide->img.object;
                    break;
                }
                else if( slide->vid.id && !(txt_not_present == VFX_TRUE && pos.pos == 1 && grp_pos == pos.group))
                {
                    obj = slide->vid.object;
                    break;
                }
            case 2:
            if(slide->aud.id )
            {
                obj = slide->aud.object;
                break;
            }
            else if( slide->vid.id)
            {
                obj = slide->vid.object;
                break;
            }
        }
    }
    return obj;
}
VfxU16 *VappMmsViewObjectsPage::getFileName(srv_mms_viewer_object_struct *object_info, VfxObject *obj_mem)
{
    U32 len;
    U16 *file_ext;              /* file of object info file name */
    U16 *set_name = NULL;       /* if file name is large then set name by truncating */
    BOOL extRemoved = FALSE;
    S8 mp3_ext[] = { 'm', 0, 'p', 0, '3', 0, 0, 0};
    S8 mp2_ext[] = { 'm', 0, 'p', 0, '2', 0, 0, 0};
    len = mmi_ucs2strlen((PS8) object_info->file_name_ucs);
    file_ext = (U16*) srv_fmgr_path_get_extension_ptr((WCHAR*) object_info->file_name_ucs);
    if (file_ext != NULL)
    {
    #if((!defined(__MMI_SHOW_FILE_EXT__)))
        extRemoved = TRUE;
        srv_fmgr_path_hide_extension((WCHAR*) object_info->file_name_ucs);
    #elif(!defined(__MMI_SHOW_DAF_FILE_EXT__))
        if ((mmi_ucs2icmp((S8*) file_ext, (S8*) mp3_ext) == 0) || (mmi_ucs2icmp((S8*) file_ext, (S8*) mp2_ext) == 0))
        {
            extRemoved = TRUE;
            srv_fmgr_path_hide_extension((WCHAR*) object_info->file_name_ucs);
        }
    #endif/*__MMI_SHOW_FILE_EXT__*/ 
    }
    if (len <= (SRV_FMGR_PATH_MAX_FILE_NAME_LEN))
    {
        VFX_ALLOC_MEM(set_name, ENCODING_LENGTH +
                     (ENCODING_LENGTH * mmi_ucs2strlen((PS8) object_info->file_name_ucs)), obj_mem);       
        ASSERT(set_name);
        mmi_ucs2cpy((PS8) set_name, (PS8) object_info->file_name_ucs);
    }
    else
    {
        VFX_ALLOC_MEM(set_name, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, obj_mem);
        ASSERT(set_name);
        memset(set_name, 0, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
                        (S8*) set_name,
                        (S8*) object_info->file_name_ucs,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN));
    }
    if (extRemoved == TRUE)
    {
        srv_mms_make_file_name((S8*) object_info->file_name_ucs, (S8*) file_ext);
    }
    extRemoved = FALSE; 
    return set_name;
}
// Get the item count of the a group
VfxU32 VappMmsViewObjectsPage::getCount(VfxU32 group) const
{
	VfxU32 total;
    if(m_attachment_count && group == getGroupCount() - 1)
	{
		 total = m_attachment_count;
	}
	else
	{
		total = srv_mms_viewer_get_slide_obj_count(group);
	}
	return total;
}

// Get the group count of the lis menu
VfxU32 VappMmsViewObjectsPage::getGroupCount() const
{
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
	VfxU32 total = desc->body->slide_no;
	if(m_attachment_count) 
	{
		return ++total;
	}
	return total;
}

VfxBool VappMmsViewObjectsPage::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (event.keyCode == VFX_KEY_CODE_2)
        {
            getMainScr()->popPage();
            return VFX_TRUE;
        }
    }
    return VfxPage::onKeyInput(event);
}

VfxBool VappMmsViewObjectsPage::hasGroupHeader(VfxS32 group) const
{
    mma_mms_description_struct *desc = srv_mms_get_desc_pointer();
    VfxU32 total;
    if(m_attachment_count && group == getGroupCount() - 1)
	{
		 total = m_attachment_count;
	}
	else
	{
		total = srv_mms_viewer_get_slide_obj_count(group);
	}
	
	if(total == 0)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


void VappMmsViewObjectsPage::onObjectTapped(VcpGroupListMenu *listmenu, VcpMenuPos pos)
{
	srv_mms_viewer_object_struct *obj = NULL;
	VfxU16 *file_name = NULL;
	obj = getObjectFromPos(pos);
	if(obj)
	{
		file_name = getFileName(obj, this);
		if(file_name == NULL)
		{
			return;
		}
	}
	else
	{
		return;
	}
	VcpCommandPopup *m_commandPopup;
	VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
    m_commandPopup->setAutoDestory(VFX_TRUE);
	VfxWString title1;
	title1.loadFromMem(file_name);
	VfxFrame *childFrame = getLastChildFrame();
	while(childFrame != NULL)
	{
		if(childFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewObjectsHandler)))
		{
			VFX_OBJ_CLOSE(childFrame);
			break;
		}
		childFrame = childFrame->getPrevFrame();
	}
	VappMmsViewObjectsHandler *objHndl;
	VFX_OBJ_CREATE_EX(objHndl, VappMmsViewObjectsHandler, this, (obj, pos.group));
	m_commandPopup->addItem(VAPP_MMS_VIEW_OBJECT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE));
	if(obj->type != SRV_MMS_OBJECT_TYPE_ATTACHMENT
#ifndef __MMI_EBOOK_READER__
		&& obj->type != SRV_MMS_OBJECT_TYPE_TEXT
#endif/*__MMI_EBOOK_READER__*/
#ifdef __MMI_MMS_COSMOS_VIDEO_SLIM__
        && obj->type != SRV_MMS_OBJECT_TYPE_VIDEO
#endif        
		)
	{
		m_commandPopup->addItem(VAPP_MMS_VIEW_OBJECT_VIEW, VFX_WSTR_RES(STR_GLOBAL_PREVIEW));
	}
	m_commandPopup->setInfoType(VCP_POPUP_TYPE_INFO);
    m_commandPopup->setText(title1);
	m_commandPopup->m_signalButtonClicked.connect(objHndl,&VappMmsViewObjectsHandler::VappMmsViewObjectsCb);
	m_commandPopup->addItem(VAPP_MMS_VIEW_OBJECT_MAX, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
	m_commandPopup->setAutoDestory(VFX_TRUE);
	m_commandPopup->show(VFX_TRUE);
	VFX_FREE_MEM(file_name);
}

void VappMmsViewObjectsPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);
	if(isBackward)
	{
		VcpMenuPos pos;
		//m_list->setVisibleMenuRegion(pos, m_hilited_index, VFX_FALSE);
		VfxFrame *childFrame = getLastChildFrame();
		while(childFrame != NULL)
		{
			if(childFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewObjectsHandler)))
			{
				((VappMmsViewObjectsHandler *)childFrame)->deleteProgressBar();
				break;
			}
			childFrame = childFrame->getPrevFrame();
		}
		srv_mms_mem_mgr_copy_pools(m_srv_index, APPLIB_MEM_AP_ID_MMS_VIEWER); 
	}
}
void VappMmsViewObjectsPage::onRotate(const VfxScreenRotateParam &param)
{
	VcpMenuPos pos;
	//m_list->setVisibleMenuRegion(pos, m_hilited_index, VFX_FALSE);
}
VFX_IMPLEMENT_CLASS("VappMmsViewObjectsHandler", VappMmsViewObjectsHandler, VfxFrame);
void VappMmsViewObjectsHandler::VappMmsViewObjectsCb(VfxObject *obj, VfxId id)
{
	switch(id)
	{
		case VAPP_MMS_VIEW_OBJECT_SAVE:
			save();
			break;
		case VAPP_MMS_VIEW_OBJECT_VIEW:
			preview();
			break;
	}
}
void VappMmsViewObjectsHandler::save(void)
{
	srv_mms_save_obj_req_struct obj_req;
	memset(&obj_req, 0, sizeof(srv_mms_save_obj_req_struct));
	obj_req.user_data = (void *)getObjHandle();
	obj_req.save_obj_fn = VappMmsViewObjectsHandler::saveRspFrmSrv;
	//show progress
	VFX_OBJ_CREATE(m_progress,VcpIndicatorPopup,getParent());
	// Activity Indicator Popup without Cancel Button
	m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
	VfxWString txt(STR_GLOBAL_PLEASE_WAIT);
	m_progress->setText(txt);
	m_progress->setAutoDestory(VFX_FALSE);
	m_progress->show(VFX_TRUE);
	mmi_umms_app_core_save_object(m_object, (void *)&obj_req);
}

void VappMmsViewObjectsHandler::saveRspFrmSrv(void *user_data, mmi_id evt_type, void *rsp_err)
{
	VappMmsViewObjectsHandler *my_object = (VappMmsViewObjectsHandler *)VfxObject::handleToObject((VfxObjHandle)user_data);
	if(my_object && my_object->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewObjectsHandler)) )
	{
		my_object->saveRspFrmSrvHdlr(evt_type, rsp_err);
	}
}

void VappMmsViewObjectsHandler::deleteProgressBar(void)
{
	if(m_progress)
	{
		VFX_OBJ_CLOSE(m_progress);
		m_progress = NULL;
	}
}
void VappMmsViewObjectsHandler::saveRspFrmSrvHdlr(mmi_id evt_type, void *rsp_err)
{
	switch(evt_type)
	{
		case EVT_ID_SRV_SAVE_OBJECT_COPY_RESULT_HDL:
			if(m_progress)
			{
				VFX_OBJ_CLOSE(m_progress);
				m_progress = NULL;
			}
			if(m_is_preview)
			{
				srv_fmgr_fileinfo_struct            fileinfo;
				S32                                 fs_ret; 
				U16 *media_file_path = NULL;
				media_file_path = srv_mms_get_media_file_path();
				srv_mms_get_src_file_name();
				fs_ret = srv_fmgr_fs_path_get_fileinfo(media_file_path, &fileinfo);
				if(fs_ret < 0)
				{
					//error handle
				}
		#ifdef __MMI_EBOOK_READER__
				mmi_fmgr_ebook_option_hdlr(MENU_ID_FMGR_EBOOK_OPTION_OPEN_NEW, media_file_path, &fileinfo);
		#endif /*__MMI_EBOOK_READER__*/
			}
			else
			{
				
			}
			break;
		case EVT_ID_SRV_SAVE_OBJECTS_ERROR:
			{
				srv_mms_save_object_event_data_struct *data = (srv_mms_save_object_event_data_struct *)rsp_err;
				U16 error_id;
				error_id = data->error_id;
				VappMmsPopup m_popup(error_id, VCP_POPUP_TYPE_FAILURE, getParent());           
				m_popup.displayPopup();
				if(m_progress)
				{
					VFX_OBJ_CLOSE(m_progress);
					m_progress = NULL;
				}
			}
			break;
		case EVT_ID_SRV_TEMPLATE_ERROR:
			{
				S32 *fs_error = (S32 *)(rsp_err);
				if(fs_error != NULL)
				{
					VappMmsPopup m_popup(srv_fmgr_fs_error_get_string(*fs_error), VCP_POPUP_TYPE_FAILURE, getParent());           
					m_popup.displayPopup();
				}
				if(m_progress)
				{
					VFX_OBJ_CLOSE(m_progress);
					m_progress = NULL;
				}
			}
			break;
		case EVT_ID_SRV_CHECK_AND_DELETE_PROGRESS:
			{
				if(m_progress)
				{
					VFX_OBJ_CLOSE(m_progress);
					m_progress = NULL;
				}
			}
			break;
		default:
			break;
	}
}
void VappMmsViewObjectsHandler::preview(void)
{
	m_is_preview = VFX_TRUE;
	if(m_object->type == SRV_MMS_OBJECT_TYPE_TEXT)
	{
		srv_mms_save_obj_req_struct obj_req;
		memset(&obj_req, 0, sizeof(srv_mms_save_obj_req_struct));
		obj_req.user_data = (void *)getObjHandle();
		obj_req.save_obj_fn = VappMmsViewObjectsHandler::saveRspFrmSrv;
		obj_req.is_preview = MMI_TRUE;
		mmi_umms_app_core_save_object(m_object, (void *)&obj_req);
		//show progress
		VFX_OBJ_CREATE(m_progress,VcpIndicatorPopup,getParent());
		// Activity Indicator Popup without Cancel Button
		m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
		VfxWString txt(STR_GLOBAL_PLEASE_WAIT);
		m_progress->setText(txt);
		m_progress->setAutoDestory(VFX_FALSE);
		m_progress->show(VFX_TRUE);
	}
	else
	{
		usePreviewCui();
	}
}
void VappMmsViewObjectsHandler::usePreviewCui(void)
{
	srv_mms_viewer_slide_struct *current_slide = srv_mms_viewer_get_slide_by_index(m_slide_num);
	PU16 file_path = NULL;
	U16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];
	VfxU16 *file_name = VappMmsViewObjectsPage::getFileName(m_object, this);
	mmi_id grpId = VfxMainScr::findMainScr((VfxFrame *)getParent())->getApp()->getGroupId();
	switch(m_object->type)
	{
	case SRV_MMS_OBJECT_TYPE_IMAGE:
		{
			srv_mms_get_filename_by_id(&(current_slide->img), vfname, &file_path, &m_parent_fh);
			if(file_path != NULL)
			{
				m_cuiId = vcui_gallery_image_viewer_create(grpId, file_path);
			}
			if(m_cuiId != GRP_ID_INVALID)
			{
				vcui_gallery_set_title_str_ptr(m_cuiId, file_name);
				vcui_gallery_run(m_cuiId);
			}
			VFX_FREE_MEM(file_name);
		}
		break;
	case SRV_MMS_OBJECT_TYPE_AUDIO:
		{
			srv_mms_get_filename_by_id(&(current_slide->aud), vfname, &file_path, &m_parent_fh);
			if(file_path != NULL)
			{
				m_cuiId = vcui_music_player_create(grpId, (VfxWChar *)file_path);
			}
			vcui_music_player_run(m_cuiId);
			vcui_music_player_set_title(m_cuiId, (VfxWChar *)file_name);
			VFX_FREE_MEM(file_name);
		}
		break;
        
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
	case SRV_MMS_OBJECT_TYPE_VIDEO:
		{
			srv_mms_get_filename_by_id(&(current_slide->vid), vfname, &file_path, &m_parent_fh);
			if(file_path != NULL)
			{
				m_cuiId = vcui_gallery_video_player_create(grpId, (VfxWChar *)file_path);
			}
			if(m_cuiId != GRP_ID_INVALID)
			{
				vcui_gallery_set_title_str_ptr(m_cuiId, file_name);
				vcui_gallery_run(m_cuiId);
			}
			VFX_FREE_MEM(file_name);
		}
		break;
#endif
	default:
		VFX_FREE_MEM(file_name);
		break;
	}
	if(m_cuiId != GRP_ID_INVALID)
	{
		mmi_frm_group_set_caller_proc(m_cuiId, &VappMmsViewObjectsHandler::previewCuiProc, (void*)getObjHandle());
	}

}
mmi_ret VappMmsViewObjectsHandler::previewCuiProc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VappMmsViewObjectsHandler *my = (VappMmsViewObjectsHandler *)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
	mmi_group_event_struct *p_event = (mmi_group_event_struct *)evt;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(evt->evt_id)
	{
		case EVT_ID_VCUI_GALLERY_CLOSE_GID:
		{
			vcui_gallery_close(p_event->sender_id);
		}
		break;
		case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:
			{
				vcui_music_player_close(p_event->sender_id);
			}
			break;
		default:
			break;
	}
	if(my && my->isKindOf(VFX_OBJ_CLASS_INFO(VappMmsViewObjectsHandler)) )
	{
	return my->previewCuiProcInt(evt);
}
	return MMI_RET_OK;
}
mmi_ret VappMmsViewObjectsHandler::previewCuiProcInt(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_VCUI_GALLERY_CLOSE_GID:
		{
			if (m_parent_fh)
			{
				FS_Close(m_parent_fh);
			}
			m_parent_fh = 0;
		}
		break;
		case EVT_ID_VCUI_MUSIC_PLAYER_CLOSE:
			{
				if (m_parent_fh)
				{
					FS_Close(m_parent_fh);
				}
				m_parent_fh = 0;
			}
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

void VappMmsViewObjectsHandler::onDeinit(void)
{
	VfxFrame::onDeinit();
	if(m_progress)
	{
		srv_mms_abort_file_copy();
	}
}
void VappMmsViewObjectsPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
	//return param.rotateTo;
}
#endif /* __MMI_MMS_2__ */