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
 *  vapp_fmgr_cui_prot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FMGR_CUI_PROT_H__
#define __VAPP_FMGR_CUI_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_fmgr.h"
#include "vapp_fmgr_table.h"

class VappFmgrCui : public VappFmgrApp
{
    VFX_DECLARE_CLASS(VappFmgrCui);    

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onGroupActive();
    virtual void onGroupInactive();
    virtual mmi_ret onProc(mmi_event_struct *evt);

};

class VappFmgrCUIInstance : public VappFmgrInstance
{
    VFX_DECLARE_CLASS(VappFmgrCUIInstance);

protected:
    VfxS32 m_select_index;
    VcpMenuPos m_select_pos;

public:
    /* CUI common API */
    void   set_title(mmi_id cui_id, vapp_fmgri_type_enum type, U16 string, U16 icon);
    void   set_userdata(mmi_id cui_id, vapp_fmgri_type_enum type, U32 userdata);
    U32    get_userdata(mmi_id cui_id, vapp_fmgri_type_enum type);
    VfxS32 get_selected_filepath(mmi_id cui_id, vapp_fmgri_type_enum type, srv_fmgr_fileinfo_struct* info, VfxWChar* path_buffer, VfxS32 path_size);
    const WCHAR* get_folder(mmi_id cui_id, vapp_fmgri_type_enum type);
    // For media picker
    VfxS32 getPickedNum();
    VfxS32 getPickedPathes(mmi_id cui_id, vapp_fmgri_type_enum type, void* pathArray, U32 picked_num);
private:
    VfxS32 getPickedMultiPath(void* pathArray, U32 picked_num);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state);
};

class VappFmgrFileSelectorCUI : public VappFmgrCUIInstance
{
    VFX_DECLARE_CLASS(VappFmgrFileSelectorCUI);

private:
    VcpMenuPos m_stop_audio_pos;
    VfxS32 m_stop_audio_index;
    VcpMenuPos m_playing_audio_pos;
    VfxS32 m_playing_audio_index;
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *param);

    virtual void onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    virtual void onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickUpButton(VfxObject* obj, VfxId button_id);
    virtual void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    
    virtual void setMenu(VcpListMenu *listmenu);
    virtual void setMenu(VcpGroupListMenu *listmenu);           

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        ); 

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );

    virtual VcpListMenuCellBaseControl *getItemCustomControl(VfxU32 index,VcpListMenuCellControlLocationTypeEnum location,VfxFrame * parentFrame);
    virtual VcpListMenuCellBaseControl *getItemCustomControl(VcpMenuPos pos,VcpListMenuCellControlLocationTypeEnum location,VfxFrame * parentFrame);

    virtual VfxBool isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);
    
    void releaseListMenu(void);    

    void callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result);

    void leaveFolder(S32 result);

    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);

    void stopPreviewAudio(void);
    VfxBool startPreviewAudio(VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxU16 *string_id);
    void resetPreviewAudioStopInfo(void);
private:
    void handleClickCmdButton(VfxS32 playing_index, VfxS32 cur_index, VfxS32 group = -1);
public:       
    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    void stopPreviewAudioEx(void);
    void resetPreviewAudioStopInfoEx(void);
    void setPreviewAudioStopInfo(void);
    void leaveFolderEx(S32 result);
    /* for event, signal and notification */            

    virtual mmi_ret callProc(mmi_event_struct *param);
};

class VappFmgrFolderSelectorCUI : public VappFmgrCUIInstance
{
    VFX_DECLARE_CLASS(VappFmgrFolderSelectorCUI);
    
protected:
    virtual void onInit();
    virtual mmi_ret onProc(mmi_event_struct *param);

    virtual void onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    virtual void onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index);        
    virtual void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    
    virtual void setMenu(VcpListMenu *listmenu);
    virtual void setMenu(VcpGroupListMenu *listmenu);
    
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );    

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    
    void releaseListMenu(void);    

    void callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result);

    void leaveFolder(S32 result);

    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);
    
private:
    void handleClickCmdButton(VfxS32 index, VfxS32 group = -1);
    void handleTapListMenuItem(VfxS32 index, VfxS32 group = -1);
public:       
    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    
    virtual mmi_ret callProc(mmi_event_struct *param);

    virtual void onActionRsp(VfxObject* obj, VfxS32 error_code, VfxBool no_on_confirm);

    void leaveFolderEx(S32 result);

    virtual VfxBool isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);

    void setStyle(vcui_folder_selector_style_enum style);
private:
    vcui_folder_selector_style_enum m_style;
};

class VappFmgrFolderBrowserLaunch: public VappFmgrMain
{
    VFX_DECLARE_CLASS(VappFmgrFolderBrowserLaunch);
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *param);

    virtual void setMenu(VcpListMenu *listmenu);

    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color);
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );    

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the image resource for the image fields of list cell    
    
    void releaseListMenu(void);    

    void callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result);

    void leaveFolder(S32 result);

    void closeMySelf(void);
        
    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);
public:       
    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    
    /* for event, signal and notification */           

    virtual mmi_ret callProc(mmi_event_struct *param);

    void leaveFolderEx(S32 result);
};

// For media picker
class VappFmgrMediaPickerCUI : public VappFmgrCUIInstance
{
    VFX_DECLARE_CLASS(VappFmgrMediaPickerCUI);

public:
    virtual void onClickToolBarButton(VfxObject* obj, VfxId button_id);
    virtual void getOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
    
    virtual mmi_ret callProc(mmi_event_struct *param);

    void leaveFolderEx(S32 result);

    virtual VfxBool isMenuItemDisable(VfxU32 page_id, VfxU16 &opt_menu_id);

    void setStyle(vcui_fmgr_media_picker_style_enum style);

	void closeMarkSeveral(void);

protected:
    virtual void onInit();
    virtual mmi_ret onProc(mmi_event_struct *param);

    virtual void onTapGroupListMenuItem(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    virtual void onTapListMenuItem(VcpListMenu *listmenu, VfxU32 index);        
    virtual void onClickCmdButton(VcpListMenu *listmenu, VfxU32 index);
    virtual void onClickGroupCmdButton(VcpGroupListMenu *listmenu, VcpMenuPos pos);
    
    virtual void setMenu(VcpListMenu *listmenu);
    virtual void setMenu(VcpGroupListMenu *listmenu);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );    

    // <group DOM_ListMenu_IVcpGroupListMenuContentProvider_Overridable>
    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        );
    
    void releaseListMenu(void);    

    void callbackApp(VappFmgrInstance* instance, VAPP_FMGR_FILE_INFO_STRUCT *file_info, VfxS32 result);

    void leaveFolder(S32 result);

    virtual VfxBool error_handler(VfxS32 error_code, VfxS32 line = __LINE__);
	virtual void onClickConfirmButton(VfxObject* obj, VfxId id);
    
private:
    void handleClickCmdButton(VfxS32 index, VfxS32 group = -1);
    void handleTapListMenuItem(VfxS32 index, VfxS32 group = -1); 
	void onClickMarkToolbarButton(VfxObject* obj, VfxId button_id);
	void onClickViewToolbarButton(VfxObject* obj, VfxId button_id);
	void getMarkOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
	void getViewOptionItem(VfxU32 page_id, VfxU16 &opt_menu_id, VfxU16 &opt_menu_num);
private:
    vcui_fmgr_media_picker_style_enum m_style;
	VfxU16 m_curMenuId;
};

#endif /* __VAPP_FMGR_CUI_PROT_H__ */
