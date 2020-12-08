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
 *  vapp_soundrec.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#include "vapp_soundrec.h"
#include "vapp_soundrec_util.h"
#include "mmi_rp_vapp_soundrec_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "../xml/vfx_xml_loader.h"
#include "mmi_rp_app_cosmos_global_def.h" // For cosmos theme color

#include "vcp_menu_popup.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif

#include "vfx_adp_device.h" // For touch feedback

#include "vapp_ncenter_gprot.h"
#include "vapp_screen_lock_gprot.h"

/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_prof_def.h"
#include "mdi_audio.h"
#include "app_str.h"
#include "FileMgrSrvGProt.h"
#include "Fs_gprot.h"
#include "SoundRecSrvGProt.h"
#include "AppMgrSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "UcmSrvGprot.h"
#ifdef __MMI_SOUNDREC_CUI__        
#include "vcui_soundrec_gprot.h"
#endif
#include "vapp_uc_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "Wgui_categories_util.h"
#ifdef __MMI_OPP_SUPPORT__
#include "Vapp_bt_send_gprot.h"
#endif
#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif
#include "UcmSrvGprot.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" mmi_id vapp_soundrec_launch_app(void)
{
    return VfxAppLauncher::launch( 
                    VAPP_SOUNDREC,
                    VFX_OBJ_CLASS_INFO(VappSoundRecorderApp),
                    GRP_ID_ROOT);
}

extern "C" MMI_ID vapp_soundrec_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = GRP_ID_INVALID;

#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return GRP_ID_INVALID;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_soundrec_launch_app();
    }
    else
    {
        switch (param->cat)
        {
            case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
            app_id = vapp_soundrec_launch_app();
            break;
        }
    }
    return app_id;
}


extern "C" mmi_ret vapp_soundrec_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

VappSoundRecorderFileList::VappSoundRecorderFileList():
m_fl_hdl(NULL),
m_fl_index(0),
m_fl_total(0),
m_fl_buf(NULL),
m_fl_need_refresh(VFX_TRUE),
m_fl_storage_change(VFX_TRUE)
{
}

VappSoundRecorderFileList::~VappSoundRecorderFileList()
{
    closeList();
}

void VappSoundRecorderFileList::onLoadedCallback(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;;

    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
            if(evt->result < 0)
            {
                m_fl_total = 0;
                break;
            }
            m_fl_need_refresh = VFX_FALSE;
            m_fl_total = srv_fmgr_filelist_count(m_fl_hdl);

            /* Support maximum 20000 entries */
            if (m_fl_total > FS_SORT_MAX_ENTRY)
            {
                m_fl_total = FS_SORT_MAX_ENTRY;
            }
        }
            break;
        default:
            break;
    }
}

VfxS32 VappSoundRecorderFileList::createList(mmi_ret (*callback)(mmi_event_struct *param), void* user_data)
{
    FMGR_FILTER filter;
	VfxS32 ret;
    VfxWChar record_folder[VAPP_SNDREC_FOLDER_LEN + 1];

    vadp_soundrec_util_filter_set(&filter);

    /* Check if storage changed */
    if(m_fl_storage_change)
    {
        closeList();
        m_fl_storage_change = VFX_FALSE;
    }

    /* Create file list */
    if(m_fl_hdl == NULL)
    {
        /* Check if disk exists and create it */
        ret = vapp_soundrec_util_check_record_folder();
        if(ret < FS_NO_ERROR)
        {
            return ret;
        }
    
        /* Get file list buffer from app heap and pass to fmgr service */
        VFX_ALLOC_MEM(m_fl_buf, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE, this);

		#ifdef __LOW_COST_SUPPORT_COMMON__
			kal_wsprintf(record_folder, "%c:\\%w", srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE), RECORD_DOWNLOAD_FOLDER_NAME);
		#else
        	kal_wsprintf(record_folder, "%c:\\%w", srv_soundrec_get_storage(), RECORD_DOWNLOAD_FOLDER_NAME);
		#endif
		
		ret = srv_fmgr_folder_filelist_create((WCHAR*)record_folder, &filter, FS_SORT_TIME, m_fl_buf, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE, &m_fl_hdl);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_FILELIST_CREATE, ret);
        if(ret < FS_NO_ERROR)
        {
            return ret;
        }
    }

    /* Async refresh */
    ret = srv_fmgr_filelist_refresh(m_fl_hdl, NULL, 0, 0, callback, user_data);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_FILELIST_CREATE_1, ret);
    if(ret < FS_NO_ERROR)
    {
		closeList();
    }

	return ret;
}

void VappSoundRecorderFileList::closeList(void)
{
    if(m_fl_hdl != NULL)
    {
        srv_fmgr_filelist_destroy(m_fl_hdl);
        m_fl_hdl = NULL;
    }

    if(m_fl_buf != NULL)
    {
        VFX_FREE_MEM(m_fl_buf);
    }
}

VfxBool VappSoundRecorderFileList::needReload(void)
{
    if(m_fl_hdl == NULL || m_fl_need_refresh || m_fl_storage_change)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxS32 VappSoundRecorderFileList::getCurrentIndex(void)
{
    return m_fl_index;
}

VfxU16 VappSoundRecorderFileList::setCurrentIndex(VfxS32 index)
{
    /* Check if file list initialized */
    if(needReload())
    {
        return VFX_FALSE;
    }    

    m_fl_index = index;
    return VFX_TRUE;
}


VfxU16 VappSoundRecorderFileList::setCurrentIndexFromFile(VfxWChar *rec_filename)
{
    VfxU16 result = 0;
    VfxS32 ret;
    VfxS32 find_index;
    WCHAR  get_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN];

    /* Check if file list initialized */
    if(needReload())
    {
        return VFX_FALSE;
    }

    /* Find the index from file name*/
    for (find_index = 0 ; find_index < m_fl_total ; find_index++)
    {
        ret = srv_fmgr_filelist_get_filename(
                m_fl_hdl,
                find_index,
                (WCHAR*) get_filename,
                sizeof(get_filename));
	
        if (FS_NO_ERROR == ret)
        {	
            if (0 == mmi_ucs2cmp((const CHAR *) rec_filename, (const CHAR *) get_filename))
            {	
                m_fl_index = find_index;
                result = 1;
                break; 
            }
        }
    }

    return result;
}

void VappSoundRecorderFileList::setDirty(void)
{
    m_fl_need_refresh = VFX_TRUE;
}

void VappSoundRecorderFileList::setStorageChange(void)
{
    m_fl_storage_change = VFX_TRUE;
}

VfxBool VappSoundRecorderFileList::getCurrentFile(VfxWChar *filename, VfxU16 buffer_size)
{
    S32 ret = 0;

    if(needReload())
    {
        return VFX_FALSE;
    }

    if (m_fl_index == -1 || m_fl_total <= 0)
    {
        return VFX_FALSE;
    }

    ret = srv_fmgr_filelist_get_filepath(m_fl_hdl, m_fl_index, (WCHAR*) filename, buffer_size);

    if (FS_NO_ERROR == ret)
    {
        return VFX_TRUE;
    }   
    return VFX_FALSE; 
}

VfxBool VappSoundRecorderFileList::getNextFile(VfxWChar *filename, VfxU16 buffer_size, VfxBool is_next)
{
    S32 ret = 0;

    if(needReload())
    {
        return VFX_FALSE;
    }

    if (m_fl_index == -1 || m_fl_total <= 0)
    {
        return VFX_FALSE;
    }

    if(is_next)
    {
        if (++m_fl_index >= m_fl_total)
        {
            m_fl_index = 0; 
        }
    }
    else
    {
        if (--m_fl_index < 0)
        {
            m_fl_index = m_fl_total - 1; 
        }    
    }

    ret = srv_fmgr_filelist_get_filepath(m_fl_hdl, m_fl_index, (WCHAR*) filename, buffer_size);

    if (FS_NO_ERROR == ret)
    {
        return VFX_TRUE;
    }   
    return VFX_FALSE; 
}


VfxBool VappSoundRecorderFileList::isFirstFile(void)
{
    if (m_fl_index == 0)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappSoundRecorderFileList::isLastFile(void)
{
    if ((m_fl_index + 1) == m_fl_total)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappSoundRecorderFileList::isNextExceedBoundary(VfxBool is_next)
{
    if(is_next)
    {
        if ((m_fl_index + 1) >= m_fl_total)
        {
            return VFX_TRUE;
        }
    }
    else
    {
        if ((m_fl_index - 1) < 0)
        {
            return VFX_TRUE;
        }    
    }
    return VFX_FALSE;
}

VfxBool VappSoundRecorderFileList::isLoading(void)
{
    srv_fmgr_filelist_state_enum state = SRV_FMGR_FILELIST_STATE_INIT;
    VfxBool result = VFX_FALSE;

    if(m_fl_hdl != NULL)
    {
        state = srv_fmgr_filelist_get_state(m_fl_hdl);
        if(SRV_FMGR_FILELIST_STATE_REFRESHING == state)
        {
            result = VFX_TRUE;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_FILELIST_IS_LOADING, m_fl_hdl, state);
    return result;
}

VfxS32 VappSoundRecorderFileList::getCount(void)
{
    if(m_fl_hdl != NULL)
    {
        return m_fl_total;
    }
    return 0;
}

/***************************************************************************** 
 * Class VappSoundRecorderApp implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSoundRecorderApp", VappSoundRecorderApp, VfxApp);

void VappSoundRecorderApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    /* Create a file list object and use in the whole application */
    VFX_OBJ_CREATE(m_file_list, VappSoundRecorderFileList, this);

    /* create and display main screen */
    VFX_OBJ_CREATE(scr, VappSoundRecorderScreen, this);
    scr->show();
}

void VappSoundRecorderApp::onInit()
{
    VfxApp::onInit();

    /*Register event handler when APP running */
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappSoundRecorderApp::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappSoundRecorderApp::eventHandler, this);

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappSoundRecorderApp::eventHandler, this);
#endif
}

void VappSoundRecorderApp::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappSoundRecorderApp::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappSoundRecorderApp::eventHandler, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappSoundRecorderApp::eventHandler, this);
#endif

    VfxApp::onDeinit();
}

mmi_ret VappSoundRecorderApp::eventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    VappSoundRecorderApp* app = (VappSoundRecorderApp*) evt->user_data;

    switch (evt->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            /* Exit application */
            app->exit();
            break;
        }
    #endif
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            app->scr->notifyTopPage(evt);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
			#ifndef __LOW_COST_SUPPORT_COMMON__
				VfxU8 drive = srv_soundrec_get_storage();
	            if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
			#endif
	            {
	                app->m_file_list->closeList();
	            }
            app->scr->notifyTopPage(evt);
            break;
        }
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VappSoundRecorderScreen implementation
 *****************************************************************************/
void VappSoundRecorderScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    /* create and display first page */
    VappSoundRecorderRecordPage *page;
    VFX_OBJ_CREATE_EX(page, VappSoundRecorderRecordPage, this, (VappSoundRecorderRecordPage::RECORD_MODE_APP));
    pushPage(0, page);
}

void VappSoundRecorderScreen::notifyTopPage(mmi_event_struct *evt)
{
    VfxPage *topPage = getPage(0);
    if(topPage != NULL)
    {
        topPage->processProc(evt);
    }
}


#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
/*****************************************************************************
 * VappSoundRecorderGestureTranslator Implementation
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSoundRecorderGestureTranslator", VappSoundRecorderGestureTranslator, VfxObject);
VappSoundRecorderGestureTranslator::VappSoundRecorderGestureTranslator():
    m_prevTimeStamp(0),
    m_prevX(0),
    m_draggingMode(VFX_FALSE),
	m_delayedTap(VFX_FALSE),
    m_tapTimer(NULL)
{
}

void VappSoundRecorderGestureTranslator::onInit()
{
    VfxObject::onInit();
    VFX_OBJ_CREATE(m_tapTimer, VfxTimer, this);
    m_tapTimer->m_signalTick.connect(this, &VappSoundRecorderGestureTranslator::onTapTimer);
    m_tapTimer->setStartDelay(DOUBLE_TAP_INTERVAL);
}

void VappSoundRecorderGestureTranslator::onTapTimer(VfxTimer *sender)
{
    // signal TAP event
    m_delayedTap = VFX_FALSE;
    m_signalGestureRecognized.emit(this, VG_TAP);
}

const VfxPenEvent& VappSoundRecorderGestureTranslator::getLastPenEvent()
{
    return m_lastPenEvent;
}

void VappSoundRecorderGestureTranslator::processPenEvent(VfxFrame *component, const VfxPenEvent &e)
{
    const VfxS32 cpWidth = component->getSize().width;
    m_lastPenEvent = e;

    if(VFX_PEN_EVENT_TYPE_DOWN == e.type)
    {
        m_prevTimeStamp = e.timeStamp;
        m_prevX = e.downPos.x;
        m_draggingMode = VFX_FALSE;
    }
    else if(VFX_PEN_EVENT_TYPE_UP == e.type)
    {
        VappSoundRecorderGesture gesture = VG_NONE;
        do
        {   
            // if swipe very quickly, treat as a GO NEXT/PREV gesture
            const VfxS32 swipeDist = vfxAbs(e.pos.x - m_prevX);
            if(0 == swipeDist)
            {
                break;
            }
            const VfxFloat swipeSpeed = swipeDist * MSEC_PER_SEC * 1.0f /
                                        (e.timeStamp - m_prevTimeStamp);
            const VfxFloat SWIPE_SPEED_THRESHOLD = cpWidth / 20.0f;
            const VfxS32 SWIPE_DISTANCE_THRESHOLD = cpWidth / 20;
            if(swipeSpeed >= SWIPE_SPEED_THRESHOLD &&
               swipeDist >= SWIPE_DISTANCE_THRESHOLD)
            {
                gesture = e.pos.x > m_prevX ? VG_GO_PREV : VG_GO_NEXT;
                break;
            }
        } while(0);

        // clear swipe info
        m_prevTimeStamp = 0;
        m_prevX = 0;
        if(VG_NONE != gesture)
        {
            m_signalGestureRecognized.emit(this, gesture);
        }

        if(m_draggingMode)
        {
            m_draggingMode = VFX_FALSE;
            m_signalGestureRecognized.emit(this, VG_DRAG_END);
        }
    }
    else if(VFX_PEN_EVENT_TYPE_MOVE == e.type)
    {
        // maintain swipe info
        //if(m_prevX != e.pos.x)
        //{
        //    m_prevTimeStamp = e.timeStamp;
        //    m_prevX = e.pos.x;
        //}
    }
}

#endif

/***************************************************************************** 
 * Class VappSoundRecorderCassetteFrame implementation
 *****************************************************************************/
VappSoundRecorderCassetteFrame::VappSoundRecorderCassetteFrame() :
    m_total_time(10),
    m_current_time(0)
{
}

void VappSoundRecorderCassetteFrame::onInit()
{
    VfxControl::onInit();

    m_is_first_rotate = VFX_TRUE;

    /*---------------------------- Load components from XML - BEGIN --------------------------------*/
    /* Create common page loader */
    VfxXmlLoader *loader;
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    loader->loadXml(VAPP_SOUNDREC_LAYOUT_CASSETTE_FRAME);

    /* Background color of center cassette area */
    loader->findObj(VFX_WSTR("block_color"));

    /* Create left tape image */
    m_image_tape_left = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("left_tape")), VfxImageFrame);
    m_image_tape_left->setResId(IMG_ID_VAPP_SNDREC_TAPE);
    m_image_tape_left->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    /* Create right tape image */
    m_image_tape_right = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("right_tape")), VfxImageFrame);
    m_image_tape_right->setResId(IMG_ID_VAPP_SNDREC_TAPE);
    m_image_tape_right->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    /* Create left roller axis */
    m_image_roll_left_axis = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("left_tape_axis")), VfxImageFrame);
    m_image_roll_left_axis->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    /* Create right roller axis */
    m_image_roll_right_axis = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("right_tape_axis")), VfxImageFrame);
    m_image_roll_right_axis->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    /* Create left roller center */
    m_image_roll_left = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("left_tape_center")), VfxImageFrame);
    m_image_roll_left->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    /* Create right roller center */
    m_image_roll_right = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("right_tape_center")), VfxImageFrame);
    m_image_roll_right->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);

    /* Draw cassette cover */
    m_image_cassette = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("cassette")), VfxImageFrame);
    m_image_cassette->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT);

    /* Create display name text object */
    m_text_displayname = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("display_name")), VfxTextFrame);

    m_text_displayname->setAutoResized(VFX_FALSE);
    m_text_displayname->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_text_displayname->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_text_displayname->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_CASETTE_TITLE)));  
    m_text_displayname->setHidden(VFX_TRUE);

    /* Close loader */
    VFX_OBJ_CLOSE(loader);
    /*---------------------------- Load components from XML - END ----------------------------------*/


    /* Set inital tape scale */
    VfxTransform sizeTransform;
    sizeTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
    sizeTransform.data.affine.sx = SNDREC_MIN_TAPE_SCALE;
    sizeTransform.data.affine.sy = SNDREC_MIN_TAPE_SCALE;

    m_image_tape_right->setTransform(sizeTransform);

    /* Create left roller rotate timeline */
    VfxTransform tempTransform;
    tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;

    VFX_OBJ_CREATE(m_timeline_rotate_left, VfxTransformTimeline, this);

    m_timeline_rotate_left->setTarget(m_image_roll_left);
    m_timeline_rotate_left->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_timeline_rotate_left->setDurationTime(3000);
    m_timeline_rotate_left->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(0);
    m_timeline_rotate_left->setFromValue(tempTransform);
	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(360);
    m_timeline_rotate_left->setToValue(tempTransform);
    m_timeline_rotate_left->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);

    /* Create right roller rotate timeline */
    /* Set inital roller angle */
    VfxTransform rotateTransform;
    rotateTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
	rotateTransform.data.affine.rz = VFX_DEG_TO_RAD(SNDREC_INIT_ROLLER_ANGLE);
    m_image_roll_right->setTransform(rotateTransform);

    VFX_OBJ_CREATE(m_timeline_rotate_right, VfxTransformTimeline, this);

	m_timeline_rotate_right->setTarget(m_image_roll_right);
    m_timeline_rotate_right->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_timeline_rotate_right->setDurationTime(3000);
    m_timeline_rotate_right->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(SNDREC_INIT_ROLLER_ANGLE);
    m_timeline_rotate_right->setFromValue(tempTransform);
	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(SNDREC_INIT_ROLLER_ANGLE + 360);
    m_timeline_rotate_right->setToValue(tempTransform);
    m_timeline_rotate_right->setIsFromCurrent(VFX_TRUE);
    m_timeline_rotate_right->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);

#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    /* setup gesture recognizer */ 
    VFX_OBJ_CREATE(m_gesture_trans, VappSoundRecorderGestureTranslator, this);
    m_gesture_trans->m_signalGestureRecognized.connect(this, &VappSoundRecorderCassetteFrame::onGesture);
#endif

    /* Set size of this frame (Using the cassette size as bounds) */
    setRect(0, 0, m_image_cassette->getSize().width, m_image_cassette->getSize().height);

}

void VappSoundRecorderCassetteFrame::onDeinit()
{
    VfxControl::onDeinit();
}

#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
VfxBool VappSoundRecorderCassetteFrame::onPenInput(VfxPenEvent &event)
{
    /* feed pen event to gesture recognizer */
    m_gesture_trans->processPenEvent(this, event);
    return VFX_TRUE;
}

void VappSoundRecorderCassetteFrame::onGesture(VappSoundRecorderGestureTranslator *sender, VappSoundRecorderGesture gesture)
{
    /* process gesture */
    switch(gesture)
    {
        case VG_GO_NEXT:
        case VG_GO_PREV:
            m_signalGestureRecognized.emit(gesture);
            break;
    }
}
#endif

void VappSoundRecorderCassetteFrame::updateTapeScale(void)
{
    VfxTransform sizeTransform_right, sizeTransform_left;
    VfxFloat roller_scale = 1.0f;

    if(m_total_time > 0)
    {
        roller_scale = static_cast<VfxFloat>(m_current_time) / static_cast<VfxFloat>(m_total_time);

        if(roller_scale > 1)
        {
            roller_scale = 1;
        }
    }
    roller_scale = roller_scale*(1.0f - SNDREC_MIN_TAPE_SCALE);

    /* Enlarge right tape */
    sizeTransform_right.type = VFX_TRANSFORM_TYPE_AFFINE;
    sizeTransform_right.data.affine.sx = SNDREC_MIN_TAPE_SCALE + roller_scale;
    sizeTransform_right.data.affine.sy = SNDREC_MIN_TAPE_SCALE + roller_scale;

    m_image_tape_right->setTransform(sizeTransform_right);

    /* Reduce left tape */
    sizeTransform_left.type = VFX_TRANSFORM_TYPE_AFFINE;
    sizeTransform_left.data.affine.sx = 1.0f - roller_scale;
    sizeTransform_left.data.affine.sy = 1.0f - roller_scale;

    m_image_tape_left->setTransform(sizeTransform_left);
}

void VappSoundRecorderCassetteFrame::setDisplayName(const VfxWString &value)
{
    m_text_displayname->setString(value);
    m_text_displayname->setHidden(VFX_FALSE);
}

void VappSoundRecorderCassetteFrame::setTotalTime(VfxU64 total_time)
{
    m_total_time = total_time;
}

void VappSoundRecorderCassetteFrame::setCurrentTime(VfxU64 current_time)
{
    m_current_time = current_time;
    updateTapeScale();
}

void VappSoundRecorderCassetteFrame::startRotate(void)
{
    if(m_is_first_rotate)
    {
        m_is_first_rotate = VFX_FALSE;
    }
    else
    {
        /* Get current transform position */
        
        VfxU16 left_degree = VRT_RAD_TO_DEG(m_image_roll_left->forceGetTransform().data.affine.rz);
        VfxU16 right_degree = VRT_RAD_TO_DEG(m_image_roll_right->forceGetTransform().data.affine.rz);        

        VfxTransform tempTransform;
        tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;

    	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(left_degree);
        m_timeline_rotate_left->setFromValue(tempTransform);
    	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(left_degree + 360);
        m_timeline_rotate_left->setToValue(tempTransform);

    	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(right_degree);
        m_timeline_rotate_right->setFromValue(tempTransform);
    	tempTransform.data.affine.rz = VFX_DEG_TO_RAD(right_degree + 360);
        m_timeline_rotate_right->setToValue(tempTransform);
    }
    
	m_timeline_rotate_left->start();
	m_timeline_rotate_right->start();
}
void VappSoundRecorderCassetteFrame::stopRotate(void)
{
    m_timeline_rotate_left->stop();
    m_timeline_rotate_right->stop();
}

void VappSoundRecorderCassetteFrame::startMoveOut(VfxBool is_next)
{
    VfxS32Timeline *tempTimeline;
    VFX_OBJ_CREATE(tempTimeline, VfxS32Timeline, this);

    tempTimeline->setTarget(this);
    tempTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    tempTimeline->setDurationTime(250);
    tempTimeline->setIsFromCurrent(VFX_TRUE);
    if(is_next)
    {
        tempTimeline->setToValue(-LCD_WIDTH);
    }
    else
    {
        tempTimeline->setToValue(LCD_WIDTH*2);
    }

    tempTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
	tempTimeline->m_signalStopped.connect(this, &VappSoundRecorderCassetteFrame::startMoveOutDone);
	tempTimeline->start();
}

void VappSoundRecorderCassetteFrame::startMoveOutDone(VfxBaseTimeline *timeline, VfxBool stopped)
{
    VappSoundRecorderCassetteFrame *_this = this;

    VFX_OBJ_CLOSE(_this);
}

void VappSoundRecorderCassetteFrame::startMoveIn(VfxS32 start_pos_x)
{
    VfxS32Timeline *tempTimeline;
    VFX_OBJ_CREATE(tempTimeline, VfxS32Timeline, this);

    tempTimeline->setTarget(this);
    tempTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    tempTimeline->setDurationTime(250);
    tempTimeline->setIsFromCurrent(VFX_FALSE);
    tempTimeline->setFromValue(start_pos_x);
    tempTimeline->setToValue(0);
    tempTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    tempTimeline->m_signalStopped.connect(this, &VappSoundRecorderCassetteFrame::startMoveInDone);
    tempTimeline->start();
}

void VappSoundRecorderCassetteFrame::startMoveInDone(VfxBaseTimeline *timeline, VfxBool stopped)
{
    VFX_OBJ_CLOSE(timeline);
}


/***************************************************************************** 
 * Class VappSoundRecorderSettingRadioMenuItem implementation
 *****************************************************************************/
class VappSoundRecorderSettingRadioMenuItem : public VfxBase
{
public:
    VfxId      m_id;
    VfxWString m_text;
    VfxBool    m_isSelect;
    VfxBool    m_isDisable;    
};


/***************************************************************************** 
 * Class VappSoundRecorderSettingRadioMenu implementation
 *****************************************************************************/
class VappSoundRecorderSettingRadioMenu : public VcpListMenu, public IVcpListMenuContentProvider
{
// Constructor / Destructor
public:
    VappSoundRecorderSettingRadioMenu() : 
        m_data(NULL),
        m_dataCount(0),
        m_bufferCount(0)
        {}

// Override
protected:
    //virtual void onInit();
    virtual void onDeinit()
    {
        if (m_data)
        {
            for (VfxS32 i = 0; i < m_dataCount; i++)
            {
                VFX_DELETE(m_data[i]);
            }
            VFX_FREE_MEM(m_data);
        }
        VcpListMenu::onDeinit();
    }
    virtual void onUpdate()
    {   
        setContentProvider(this);
        setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);

        VcpListMenu::onUpdate();
    }

    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            )
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text = m_data[index]->m_text;
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }

        return VFX_TRUE;
    }

    virtual VfxU32 getCount() const
    {
        return m_dataCount;   
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
    {
        if (m_data[index]->m_isSelect)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const
    {
        return m_data[index]->m_isDisable;
    }

// Method
public:
    void addItem(const VappSoundRecorderSettingRadioMenuItem& item)
    {
        if (0 == m_bufferCount)
        {
            m_bufferCount += 4;
            
            VFX_ALLOC_MEM(m_data, m_bufferCount * sizeof(VappSoundRecorderSettingRadioMenuItem *), this);
        }    
        
        VFX_ALLOC_NEW(m_data[m_dataCount], VappSoundRecorderSettingRadioMenuItem, this);
        m_data[m_dataCount]->m_id = item.m_id;
        m_data[m_dataCount]->m_text = item.m_text;
        m_data[m_dataCount]->m_isSelect = item.m_isSelect;
        m_data[m_dataCount]->m_isDisable = item.m_isDisable;

        m_dataCount++;

        ASSERT(m_dataCount<=4); /* Allow maximim 4 items for now */
        checkUpdate();
    }

    void disableItem(VfxS32 index, VfxBool isDisable)
    {
        m_data[index]->m_isDisable = isDisable;
    }

// Variable
private:

    VappSoundRecorderSettingRadioMenuItem **m_data;
    VfxS32 m_dataCount;
    VfxS32 m_bufferCount;

};

/***************************************************************************** 
 * Class VappSoundRecorderSettingRadioPage implementation
 *****************************************************************************/
class VappSoundRecorderSettingRadioPage : public VfxPage
{
public:
    VappSoundRecorderSettingRadioPage() : m_index(0)
    {};
    VappSoundRecorderSettingRadioPage(VfxS32 index, VfxS32 selectIndex) : 
        m_index(index), 
        m_selectIndex(selectIndex)
    {};

protected:
    virtual void onInit()
    {
        VfxPage::onInit();

        /* Add Title */
        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);

		#ifndef __LOW_COST_SUPPORT_COMMON__
	        if (m_index == 0)
	        {
	            bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_STORAGE));
	        }
        	else
		#endif
	        {
	            bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_QUALITY));
	        }
        setTopBar(bar);

        VFX_OBJ_CREATE(radioMenu, VappSoundRecorderSettingRadioMenu, this);
        radioMenu->setBounds(VfxRect(0,0,getSize().width,getSize().height));

		#ifndef __LOW_COST_SUPPORT_COMMON__
			if (m_index == 0)
	        {
	            /* Add list item 1*/
	            VappSoundRecorderSettingRadioMenuItem tempItem;
	            tempItem.m_id = 0;
	            tempItem.m_text = VFX_WSTR_RES(STR_GLOBAL_PHONE);
	            if (m_selectIndex == 0)
	            {
	                tempItem.m_isSelect = VFX_TRUE;
	            }
	            else
	            {
	                tempItem.m_isSelect = VFX_FALSE;
	            }
	            tempItem.m_isDisable = VFX_FALSE;            
	            radioMenu->addItem(tempItem);

	            /* Add list item 2*/
	            tempItem.m_id = 1;
	            tempItem.m_text = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
	            if (m_selectIndex == 1)
	            {
	                tempItem.m_isSelect = VFX_TRUE;
	            }
	            else
	            {
	                tempItem.m_isSelect = VFX_FALSE;
	            }

	            /* Check is memory card accessable */
	            if(srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
	            {
	                tempItem.m_isDisable = VFX_FALSE;
	            }
	            else
	            {
	                tempItem.m_isDisable = VFX_TRUE;
	            }
	            radioMenu->addItem(tempItem);

	            radioMenu->m_signalItemTapped.connect(this, &VappSoundRecorderSettingRadioPage::onSelectionChanged);
	        }
	        else
		#endif
	        {
	            /* Add list item 1*/
	            VappSoundRecorderSettingRadioMenuItem tempItem;
	            tempItem.m_id = 0;
	            tempItem.m_text = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_NORMAL);
	            if (m_selectIndex == 0)
	            {
	                tempItem.m_isSelect = VFX_TRUE;
	            }
	            else
	            {
	                tempItem.m_isSelect = VFX_FALSE;
	            }
	            tempItem.m_isDisable = VFX_FALSE;            
	            radioMenu->addItem(tempItem);

	            /* Add list item 2*/
	            tempItem.m_id = 1;
	            tempItem.m_text = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_HIGH);
	            if (m_selectIndex == 1)
	            {
	                tempItem.m_isSelect = VFX_TRUE;
	            }
	            else
	            {
	                tempItem.m_isSelect = VFX_FALSE;
	            }
	            tempItem.m_isDisable = VFX_FALSE;            
	            radioMenu->addItem(tempItem);
	            radioMenu->m_signalItemTapped.connect(this, &VappSoundRecorderSettingRadioPage::onSelectionChanged);
	        }
    }

#ifndef __LOW_COST_SUPPORT_COMMON__
    virtual mmi_ret onProc(mmi_event_struct *evt)
    {
        switch (evt->evt_id)
        {
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
                if (m_index == 0)
                {
                    radioMenu->disableItem(1, VFX_FALSE);
                    radioMenu->updateAllItems();
                }
                break;
            case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
                if (m_index == 0)
                {
                    radioMenu->disableItem(1, VFX_TRUE);
                    radioMenu->updateAllItems();                    
                }
                break;
            default:
                return VfxPage::onProc(evt);
        }
        return MMI_RET_OK;
    }
#endif

    void onSelectionChanged(VcpListMenu *menu, VfxU32 index)
    {    
        /* Change storage from phone to card, check if card exists */
        if(index != m_selectIndex)
        {
			#ifndef __LOW_COST_SUPPORT_COMMON__
            if(0 == m_index && 1 == index)
            {
                VfxWChar record_drive[10];
                kal_wsprintf(record_drive, "%c:\\", srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
                S32 result;

                if((result = FS_Open(record_drive, FS_READ_ONLY)) < FS_NO_ERROR)
                {
                    if((FS_DRIVE_NOT_FOUND == result || FS_MEDIA_CHANGED == result))
                    {
                        VcpConfirmPopup *m_confirmPopup;
                        VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
                    	m_confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                    	m_confirmPopup->setText(VFX_WSTR_RES(STR_GLOBAL_NO_MEMORY_CARD));
                        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                        m_confirmPopup->m_signalButtonClicked.connect(this, &VappSoundRecorderSettingRadioPage::onConfirmClicked);                        
                        m_confirmPopup->setAutoDestory(VFX_TRUE);
                        m_confirmPopup->show(VFX_TRUE);
                        return;
                    }
                }
                else
                {
                    FS_Close(result);
                }
            }
			#endif

            m_signalSelectNewItem.emit(m_index, index);
        }
        getMainScr()->popPage();
    }

#ifndef __LOW_COST_SUPPORT_COMMON__
    void onConfirmClicked(VfxObject* vfx_obj, VfxId id)
    {
        getMainScr()->popPage();
    }
#endif

    /* Variable */
    VappSoundRecorderSettingRadioMenu *radioMenu;
    VfxS32 m_index;
    VfxS32 m_selectIndex;

public:
    VfxSignal2 <VfxS32, VfxS32> m_signalSelectNewItem;
};


#ifndef __LOW_COST_SUPPORT_COMMON__

/***************************************************************************** 
 * Class VappSoundRecorderSettingPage implementation
 *****************************************************************************/
void VappSoundRecorderSettingPage::onInit()
{
    VfxPage::onInit();

    /* Get setting from parent app */
    VfxU8 drive = srv_soundrec_get_storage();
    VfxU8 quality = srv_soundrec_get_quality();

    /* Create title bar */
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(VCP_STR_TOOL_BAR_SETTINGS));
    setTopBar(bar);

    /* Create Form */
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    
    /* Add item - storate */
	VFX_OBJ_CREATE(m_setting[0], VcpFormItemLauncherCell, m_form);
	m_setting[0]->setMainText(VFX_WSTR_RES(STR_GLOBAL_STORAGE));
    if(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE) == drive)
    {
    	m_setting[0]->setHintText(VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD));
        m_radioSelectIndex1 = 1;
    }
    else
    {
    	m_setting[0]->setHintText(VFX_WSTR_RES(STR_GLOBAL_PHONE));
        m_radioSelectIndex1 = 0;
    }
	m_setting[0]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_setting[0]->m_signalTap.connect(this, &VappSoundRecorderSettingPage::onItemTapped);
    m_setting[0]->setId(0);
    m_form->addItem(m_setting[0], 0);

    /* Add item - quality */
    VFX_OBJ_CREATE(m_setting[1], VcpFormItemLauncherCell, m_form);
	m_setting[1]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_QUALITY));
	if(quality == SRV_SOUNDREC_QUALITY_HIGH)
	{
    	m_setting[1]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_HIGH));
        m_radioSelectIndex2 = 1;
	}
	else
	{
    	m_setting[1]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_NORMAL));
        m_radioSelectIndex2 = 0;
	}
	m_setting[1]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_setting[1]->m_signalTap.connect(this, &VappSoundRecorderSettingPage::onItemTapped);
    m_setting[1]->setId(1);
    m_form->addItem(m_setting[1], 1);

}


void VappSoundRecorderSettingPage::onItemTapped(VcpFormItemCell* sender, VfxId Id)
{
    if (Id == 0 || Id == 1)
    {
        VappSoundRecorderSettingRadioPage *page;
        if (Id == 0)
        {
            VFX_OBJ_CREATE_EX(page, VappSoundRecorderSettingRadioPage, getMainScr(), (Id, m_radioSelectIndex1));
        }
        else
        {
            VFX_OBJ_CREATE_EX(page, VappSoundRecorderSettingRadioPage, getMainScr(), (Id, m_radioSelectIndex2));
        }
        page->m_signalSelectNewItem.connect(this,  &VappSoundRecorderSettingPage::onSelectNewItem);
        getMainScr()->pushPage(VFX_ID_NULL, page);
    }
}

void VappSoundRecorderSettingPage::onSelectNewItem(VfxS32 itemId, VfxS32 subItemId)
{
    if (itemId == 0)
    {
        m_radioSelectIndex1  = subItemId;
        if (subItemId == 0)
        {
            m_setting[0]->setHintText(VFX_WSTR_RES(STR_GLOBAL_PHONE));
            srv_soundrec_set_storage(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE));
        }
        else
        {
            m_setting[0]->setHintText(VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD));
            srv_soundrec_set_storage(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
        }

        /* Need to reload list in list screen */
        VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();
        obj->m_file_list->setStorageChange();
    }
    else
    {
        m_radioSelectIndex2  = subItemId;
        if (subItemId == 0)
        {
            m_setting[1]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_NORMAL));
            srv_soundrec_set_quality(SRV_SOUNDREC_QUALITY_NORMAL);
        }
        else if (subItemId == 1)
        {
            m_setting[1]->setHintText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SETTING_HIGH));
            srv_soundrec_set_quality(SRV_SOUNDREC_QUALITY_HIGH);
        }
        
    }
}

#endif

/***************************************************************************** 
 * Class VappSoundRecorderListPage implementation
 *****************************************************************************/
void VappSoundRecorderListPage::onInit()
{
    VfxPage::onInit();

    /* Init variables */
    m_mode = LIST_MODE_BROWSE;
    m_select_state = NULL;
    m_play_page_change_list = VFX_FALSE;
    m_indicator = NULL;

    VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();
    m_file_list = obj->m_file_list;

    /* Set page background to white */
    this->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    /* Create title bar */
    VFX_OBJ_CREATE(m_bar, VcpTitleBar, this);
    m_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECLIST));
    setTopBar(m_bar);

    /* Create tool bar */
    VFX_OBJ_CREATE(m_toolbar_delete, VcpToolBar, this);
    m_toolbar_delete->addItem(TOOLBAR_DELETE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolbar_delete->m_signalButtonTap.connect(this, &VappSoundRecorderListPage::onListModeButtonClicked);
	m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);    
	setBottomBar(m_toolbar_delete);

    /* Create list */
    VFX_OBJ_CREATE(m_list_menu, VcpListMenu, this);
    m_list_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT);
    m_list_menu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL,VFX_FALSE);
    m_list_menu->m_signalItemTapped.connect(this, &VappSoundRecorderListPage::onListItemTapped);
    m_list_menu->m_signalItemLongTapped.connect(this, &VappSoundRecorderListPage::onListItemLongTapped);            
    m_list_menu->setContentProvider(this);
    m_list_menu->setRect(getRect());
    m_list_menu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list_menu->setHidden(VFX_TRUE); 
    
}


void VappSoundRecorderListPage::onDeinit()
{
    if(m_select_state != NULL)
    {
        VFX_FREE_MEM(m_select_state);
        m_select_state = NULL;
    }

    VfxPage::onDeinit();
}

mmi_ret VappSoundRecorderListPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
		#ifndef __LOW_COST_SUPPORT_COMMON__
            VfxU8 drive = srv_soundrec_get_storage();
            if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
        #endif
            {
                loadFileListMenu();
            }
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
		#ifndef __LOW_COST_SUPPORT_COMMON__
            VfxU8 drive = srv_soundrec_get_storage();
            if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
		#endif
			{
                stopLoading();            
                showFileListMenu();
                /* Clear all popup when memory card plug out */
                getMainScr()->clearPopupStack();
            }
            break;
        }        
        default:
            return VfxPage::onProc(evt);
    }
    return MMI_RET_OK;
}

void VappSoundRecorderListPage::onEnter(VfxBool isBackward)
{
    if(m_file_list != NULL)
    {
        /* (1) The list does not mark as dirty, check fmgr service if it is dirty
           (2) The list is modified by play page */
        if((!m_file_list->needReload() && srv_fmgr_filelist_is_dirty(m_file_list->m_fl_hdl)) ||
           (isBackward && m_play_page_change_list))
        {
            m_file_list->setDirty();
            m_list_menu->setHidden(VFX_TRUE); 
        }
    }

    m_is_backward = isBackward;
}

void VappSoundRecorderListPage::onEntered()
{
    /* Load list menu */
    if(!m_is_backward ||
       (m_is_backward && m_file_list->needReload()))
    {
        m_play_page_change_list = VFX_FALSE;

        /* Clear all popup since the list need reload */
        getMainScr()->clearPopupStack();

        if(LIST_MODE_DELETE == m_mode)
        {
            /* Refresh list and change mode back to browse mode */
            m_list_need_refresh = VFX_TRUE;
            changeListMode(LIST_MODE_BROWSE);
        }
        else
        {
            loadFileListMenu();
        }
    }
}

void VappSoundRecorderListPage::onExit(VfxBool isBackward)
{
    /* Abort delete provess when exit */
    m_delete_abort = VFX_TRUE;

    if(m_file_list->isLoading())
    {
    	srv_fmgr_filelist_abort(m_file_list->m_fl_hdl);
		m_file_list->setDirty();
    }
}

void VappSoundRecorderListPage::onBack()
{
    if(LIST_MODE_DELETE == m_mode)
    {
        changeListMode(LIST_MODE_BROWSE);
    }
    else
    {
        VfxPage::onBack();
    }
}

void VappSoundRecorderListPage::onListModeButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case TOOLBAR_DELETE:
            changeListMode(LIST_MODE_DELETE);
            break;

        default:
            break;
    }
}

void VappSoundRecorderListPage::onDeleteModeButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case TOOLBAR_SELECT_ALL:
            onListMarkAll(VFX_TRUE);
            break;
            
        case TOOLBAR_DELETE:
            showMultiDeleteConfirm();
            break;

        case TOOLBAR_CANCEL:
            changeListMode(LIST_MODE_BROWSE);
            break;

        default:
            break;
    }
}

void VappSoundRecorderListPage::onListItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VfxS32 ret;
    VfxWChar file_path[SRV_FMGR_PATH_MAX_LEN+1];

    /* Get current file path from index */
    ret = srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, index, (WCHAR*) file_path, sizeof(file_path));

    if(ret >= FS_NO_ERROR)
    {
        /* Set the select file to the current index */
        m_file_list->setCurrentIndex(index);
    
        /* Go to playback screen */
        VappSoundRecorderPlayPage *page_play;
        VFX_OBJ_CREATE_EX(page_play, VappSoundRecorderPlayPage, getMainScr(), (VFX_WSTR_MEM(file_path), VappSoundRecorderPlayPage::PLAYBACK_MODE_APP, VFX_TRUE));
        page_play->m_playPageListChange.connect(this, &VappSoundRecorderListPage::onPlayPageListChanged);
        getMainScr()->pushPage(0, page_play);
    }
}

void VappSoundRecorderListPage::onListItemLongTapped(VcpListMenu *menu, VfxU32 index)
{
    VfxWChar file_path[SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1];

    /* Do not act for long press in multi select mode */
    if(LIST_MODE_DELETE == m_mode)
    {
        return;
    }

    /* Get current file path from index */
    srv_fmgr_filelist_get_filename(m_file_list->m_fl_hdl, index, (WCHAR*) file_path, sizeof(file_path));

    m_long_tap_index = index;
    
    /* Show ling tap option menu */
    VcpMenuPopup *m_menu_popup;
    VFX_OBJ_CREATE(m_menu_popup, VcpMenuPopup, this);

    m_menu_popup->setTitle(VFX_WSTR_MEM(file_path));

    m_menu_popup->addItem(LTAP_RENAME, VFX_WSTR_RES(STR_GLOBAL_RENAME));
    m_menu_popup->addItem(LTAP_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE));
    m_menu_popup->m_signalMenuCallback.connect(this, &VappSoundRecorderListPage::onListItemLongTappedOptionCallback);

    m_menu_popup->show(VFX_TRUE);

    // Touch feedback for long press
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

}

void VappSoundRecorderListPage::onListItemLongTappedOptionCallback(
								VcpMenuPopup* menu, 
								VcpMenuPopupEventEnum event, 
								VcpMenuPopupItem* item)
{
    if(VCP_MENU_POPUP_EVENT_ITEM_SELECTED == event)
    {
        switch(item->getId())
        {
            case LTAP_DELETE:
                showLongTapDeleteConfirm();
                break;
            case LTAP_RENAME:
                showLongTapRenamePopup();
                break;
            default:
                break;
        }
    }
}
								
void VappSoundRecorderListPage::onListSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if(newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        m_select_num--;
        m_select_state[index] = VFX_FALSE;

        if(m_select_num != m_file_list->getCount())
        {
            onListMarkAll(VFX_FALSE);
        }
    }
    else if(newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_select_num++;
        m_select_state[index] = VFX_TRUE;

        if(m_file_list->getCount() == m_select_num)
        {
            onListMarkAll(VFX_FALSE);
        }
    }

    if(m_select_num == 0)
    {
        m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);
    }
    else
    {
        m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_FALSE);
    }

}


void VappSoundRecorderListPage::onListMarkAll(VfxBool reload_list)
{
    VfxU16 count;
    VfxU16 i;
    VfxBool status;

    if(m_file_list->m_fl_hdl != NULL)
    {

        if(reload_list)
        {
            count = m_file_list->getCount();

            if(m_show_select_all)
            {
                status = VFX_TRUE;
                m_select_num = count;
            }
            else
            {
                status = VFX_FALSE;
                m_select_num = 0;
            }

            for(i = 0 ; i < count ; i++)
            {
                m_select_state[i] = status;
            }

            /* Ask list menu to update without emit m_signalItemSelectionStateChanged */
            m_list_menu->resetAllItems(VFX_TRUE);
        }


        /* Update local status */
        if(m_select_num == m_file_list->getCount())
        {
            m_toolbar_delete->changeItem(TOOLBAR_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_UNSELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_FALSE);
            m_show_select_all = VFX_FALSE;
		}
        else
        {
            m_toolbar_delete->changeItem(TOOLBAR_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);
            m_show_select_all = VFX_TRUE;
		}
    }
}

void VappSoundRecorderListPage::onPlayPageListChanged(void)
{
    m_play_page_change_list = VFX_TRUE;
}

void VappSoundRecorderListPage::showMultiDeleteConfirm(void)
{
    VcpConfirmPopup *m_confirmPopup;
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);

    VfxWString tempString;
    tempString.format(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_DELETE_MULTI), m_select_num);
   
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setText(tempString);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->setAutoDestory(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappSoundRecorderListPage::onMultiDeleteClicked);
}

void VappSoundRecorderListPage::onMultiDeleteClicked(VfxObject* vfx_obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_file_list->setDirty();
        m_list_need_refresh = VFX_TRUE;

        m_next_del_index = 0;
        m_delete_abort = VFX_FALSE;
        if(deleteFileAsync())
        {
            showMultiDeleteProcessing();
        }
        else
        {
            changeListMode(LIST_MODE_BROWSE);            
        }
    }
}

void VappSoundRecorderListPage::showMultiDeleteProcessing(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_SHOW_MULTI_DEL_PROCESSING);

    /* Show deleting */
    VFX_OBJ_CREATE(m_deleting_popup, VcpIndicatorPopup, this);

    /* Sets the position and width of indicator bar. */
    m_deleting_popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
    m_deleting_popup->setText(VFX_WSTR_RES(STR_GLOBAL_DELETING));
    m_deleting_popup->m_signalCanceled.connect(this, &VappSoundRecorderListPage::onMultiDeleteCancel);
    m_deleting_popup->setAutoDestory(VFX_FALSE); // Not auto close when cancel
    m_deleting_popup->show(VFX_TRUE);

    /* Disable toolbar function */
    m_toolbar_delete->setDisableItem(TOOLBAR_SELECT_ALL, VFX_TRUE);
    m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);
    m_toolbar_delete->setDisableItem(TOOLBAR_CANCEL, VFX_TRUE);
}

void VappSoundRecorderListPage::stopMultiDeleteProcessing(void)
{
    VFX_OBJ_CLOSE(m_deleting_popup);
    changeListMode(LIST_MODE_BROWSE);
}

void VappSoundRecorderListPage::onMultiDeleteCancel(VfxObject* obj, VfxFloat processing)
{
    MMI_BOOL result;

    m_delete_abort = VFX_TRUE;
    result = srv_fmgr_async_abort(m_fmgr_job_id, MMI_FALSE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_ON_MULTI_DEL_CANCEL, result, m_fmgr_job_id);
}

void VappSoundRecorderListPage::showLongTapDeleteConfirm(void)
{
    VfxWChar file_path[SRV_FMGR_PATH_MAX_FILE_NAME_LEN+1];

    /* Get current file path from index */
    srv_fmgr_filelist_get_filename(m_file_list->m_fl_hdl, m_long_tap_index, (WCHAR*) file_path, sizeof(file_path));

    VfxWString temp_str = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_DELETE_RECORD);

    /* Show confirm popup */
    VcpConfirmPopup *m_confirmPopup;
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setText(temp_str);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->setAutoDestory(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappSoundRecorderListPage::onLongTapDeleteClicked);
}

void VappSoundRecorderListPage::onLongTapDeleteClicked(VfxObject* vfx_obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        if(m_file_list != NULL)
        {
            VfxWChar file_path[SRV_FMGR_PATH_MAX_LEN+1];
            VfxS32 ret;

            /* Get current file path from index */
            ret = srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, m_long_tap_index, (WCHAR*) file_path, sizeof(file_path));

            if(ret >= FS_NO_ERROR)
            {
                /* Delete file */
				ret = srv_fmgr_async_delete(file_path, 
                        	SRV_FMGR_ASYNC_FLAG_PRIORITY_FG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                        	onLongTapDeleteCallback,
                        	getObjHandle());

                if(ret >= FS_NO_ERROR)
                {
                    /* Set file list dirty and refresh it */
                    m_file_list->setDirty();
                    loadFileListMenu();
                }
                else
                {
            		mmi_frm_nmgr_balloon(
            			MMI_SCENARIO_ID_DEFAULT,
            			MMI_EVENT_INFO_BALLOON,
            			MMI_NMGR_BALLOON_TYPE_FAILURE,
            			(WCHAR *)VFX_WSTR_RES(srv_fmgr_fs_error_get_string(ret)).getBuf());
                }
            }
        }
    }
}

mmi_ret VappSoundRecorderListPage::onLongTapDeleteCallback(mmi_event_struct *param)
{
	return MMI_RET_OK;
}

void VappSoundRecorderListPage::showLongTapRenamePopup(void)
{
    VfxWChar file_path[SRV_FMGR_PATH_MAX_LEN+1];

    /* Get current file path from index */
    srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, m_long_tap_index, (WCHAR*) file_path, sizeof(file_path));
    VfxWString tempFilePath = VFX_WSTR_MEM(file_path);

    /* Display input popup */
    VappFileNameEditorPopup *m_rename_popup;
    VFX_OBJ_CREATE(m_rename_popup, VappFileNameEditorPopup, this);
    m_rename_popup->setTitle(VFX_WSTR_RES(STR_GLOBAL_RENAME));

    /* Get filename without extension */
    VfxU16 temp_len = tempFilePath.getLength();
    VfxWChar *temp_buf;
    VFX_ALLOC_MEM(temp_buf, (temp_len+1)*sizeof(VfxWChar), this);
    kal_wstrncpy(temp_buf, tempFilePath.getBuf(), temp_len);
    VfxU16 temp_ext = srv_fmgr_path_get_extension_pos(temp_buf);
    temp_buf[temp_ext-1] = 0;
    m_rename_popup->setText(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(temp_buf)), (SRV_FMGR_PATH_MAX_LEN - VAPP_SNDREC_FOLDER_LEN - 4), VFX_FALSE);
    VFX_FREE_MEM(temp_buf);

    /* Set file extension */
    VfxS8 ext_name[(SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    kal_wstrncpy(reinterpret_cast<VfxWChar*>(ext_name), srv_fmgr_path_get_extension_const_ptr(tempFilePath.getBuf()), SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1);
    m_rename_popup->setExt(ext_name);

    /* Set highlight for whole text */
    m_rename_popup->getInputbox()->setHighlight(0, m_rename_popup->getText().getLength());

    /* Set input method and show popup */
    m_rename_popup->setIME(IMM_INPUT_TYPE_SENTENCE);
    m_rename_popup->m_signalButtonClicked.connect(this, &VappSoundRecorderListPage::onLongTapRenameClicked);
    m_rename_popup->setAutoDestory(VFX_TRUE);
    m_rename_popup->show(VFX_TRUE);

}

void VappSoundRecorderListPage::onLongTapRenameClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    VappFileNameEditorPopup *m_rename_popup = (VappFileNameEditorPopup*)sender;

    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
		{
            if(m_rename_popup->isValidFilePath() >= FS_NO_ERROR)
            {
                VfxWChar file_path[SRV_FMGR_PATH_MAX_LEN+1];

                /* Get current file path from index */
                srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, m_long_tap_index, (WCHAR*) file_path, sizeof(file_path));
                VfxWString tempFilePath = VFX_WSTR_MEM(file_path);
            
                /* Get new file path */
                VfxU16 temp_len = tempFilePath.getLength();
                VfxWChar *temp_buf;
                VFX_ALLOC_MEM(temp_buf, (temp_len+1)*sizeof(VfxWChar), this);
                kal_wstrncpy(temp_buf, tempFilePath.getBuf(), temp_len);
                VfxWString new_path = VFX_WSTR_MEM(reinterpret_cast<const VfxWChar*>(srv_fmgr_path_remove_filename(temp_buf)));
                VFX_FREE_MEM(temp_buf);
                
                new_path += m_rename_popup->getText();
                new_path += VFX_WSTR(".");
                new_path += VFX_WSTR_MEM(reinterpret_cast<const VfxWChar*>(srv_fmgr_path_get_extension_const_ptr(tempFilePath.getBuf())));

				S32 result;
                if((result = FS_Open(new_path, FS_READ_ONLY)) >= FS_NO_ERROR)
                {
					if (app_ucs2_strncmp((const kal_int8*)tempFilePath.getBuf(), (const kal_int8*)new_path.getBuf(), (SRV_FMGR_PATH_MAX_LEN+1)) == 0)
					{
						/* Filename is the original one */
                        VFX_OBJ_CLOSE(m_rename_popup);
						FS_Close(result);
						return;
					}
					
                    /* Check if new name and original name are different with some lower or upper case char */
                    VfxS8 *lw_buff_o = NULL, *lw_buff_n = NULL;
                    VFX_ALLOC_MEM(lw_buff_o, SRV_FMGR_PATH_MAX_LEN, this);
                    memset(lw_buff_o, 0, SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_o, (const kal_int8*)tempFilePath.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_o);
                    VFX_ALLOC_MEM(lw_buff_n, SRV_FMGR_PATH_MAX_LEN, this);
                    memset(lw_buff_n, 0, SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_n, (const kal_int8*)new_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_n);

                    if (app_ucs2_strncmp((const kal_int8*)lw_buff_o, (const kal_int8*)lw_buff_n, (SRV_FMGR_PATH_MAX_LEN + 1)) != 0)
					{
						/* Filename is not the original one */
						m_rename_popup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_FILENAME_ALREADY_EXISTS));
                        VFX_FREE_MEM(lw_buff_o);
                        VFX_FREE_MEM(lw_buff_n);
						FS_Close(result);
						return;
					}

                    VFX_FREE_MEM(lw_buff_o);
                    VFX_FREE_MEM(lw_buff_n);
                }

				VFX_OBJ_CLOSE(m_rename_popup);
				FS_Close(result);

				result = FS_Rename(tempFilePath.getBuf(), new_path.getBuf());

				if(result >= FS_NO_ERROR)
				{
					/* Set file list dirty and refresh later */
					m_file_list->setDirty();
					loadFileListMenu();
				}
				else
				{
					mmi_frm_nmgr_balloon(
						MMI_SCENARIO_ID_DEFAULT,
						MMI_EVENT_INFO_BALLOON,
						MMI_NMGR_BALLOON_TYPE_FAILURE,
						(WCHAR *)VFX_WSTR_RES(srv_fmgr_fs_error_get_string(result)).getBuf());					  
				}

			}
			else
			{
                m_rename_popup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_INVALID_FILENAME));
			}
			break;
        }
        case VCP_INPUT_POPUP_BTN_CANCEL:
            VFX_OBJ_CLOSE(m_rename_popup);
            break;
        default:
            break;
    }
}

void VappSoundRecorderListPage::showListErrorConfirm(const VfxWString &text, VfxBool exit_page)
{
    VcpConfirmPopup *m_error_popup;
    VFX_OBJ_CREATE(m_error_popup, VcpConfirmPopup, this);

    if(exit_page)
    {
        m_error_popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    }
    else
    {
        m_error_popup->setInfoType(VCP_POPUP_TYPE_INFO);
    }

    m_error_popup->setText(text);
    m_error_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    m_error_popup->show(VFX_TRUE);
    m_error_popup->setAutoDestory(VFX_TRUE);
    if(exit_page)
    {
        m_error_popup->m_signalButtonClicked.connect(this, &VappSoundRecorderListPage::onListErrorClicked);
    }
}

void VappSoundRecorderListPage::onListErrorClicked(VfxObject* vfx_obj, VfxId id)
{
    getMainScr()->popPage();    
}

VfxBool VappSoundRecorderListPage::showFileListMenu(void)
{
    VfxU32 file_count;

    file_count = m_file_list->getCount();
    if(file_count > 0)
    {
        /* Enable tool bar */
		m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_FALSE);    
        setToolBarMode(m_mode);
    }
    else
    {
        /* Change to browse mode if no item */
        changeListMode(LIST_MODE_BROWSE);

        /* No items, not able to delete */
        m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);    
    }

    /* Update */
    m_list_menu->setHidden(VFX_FALSE);     
    m_list_menu->resetAllItems(VFX_TRUE);

    return VFX_TRUE;
}

VfxBool VappSoundRecorderListPage::deleteFileAsync(void)
{
    VfxU16 count;
    VfxU16 i;
    WCHAR file_path[SRV_FMGR_PATH_MAX_LEN+1];

    count = m_file_list->getCount();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_DEL_FILE_ASYNC_1, m_next_del_index, count);
    
    for(i = m_next_del_index ; i < count; i++)
    {
        if(m_select_state[i])
        {
            srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, i, file_path, (SRV_FMGR_PATH_MAX_LEN+1)*sizeof(WCHAR));
            m_fmgr_job_id = srv_fmgr_async_delete(file_path, 
                                        SRV_FMGR_ASYNC_FLAG_PRIORITY_FG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                                        onListDeleteCallback,
                                        getObjHandle());

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_DEL_FILE_ASYNC_2, i, m_fmgr_job_id);

            if(m_fmgr_job_id < FS_NO_ERROR)
            {
            	mmi_frm_nmgr_balloon(
            			MMI_SCENARIO_ID_DEFAULT,
            			MMI_EVENT_INFO_BALLOON,
            			MMI_NMGR_BALLOON_TYPE_FAILURE,
            			(WCHAR *)VFX_WSTR_RES(srv_fmgr_fs_error_get_string(m_fmgr_job_id)).getBuf());
                return VFX_FALSE;
            }
            m_next_del_index = i + 1;
			// Next will be deleted in onListDeleteCallback
			break;
        }
    }

    /* No more item to delete */
    if(i == count)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

mmi_ret VappSoundRecorderListPage::onListDeleteCallback(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;

	VappSoundRecorderListPage *list_obj = (VappSoundRecorderListPage*)handleToObject((VfxObjHandle)param->user_data);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_ON_LIST_DEL_CALLBACK, param->evt_id);

    /* Check if list page object exist and still in delete mode */
    if(list_obj != NULL)
    {
        switch(param->evt_id)
        {
            /* Async delete done */
            case EVT_ID_SRV_FMGR_ASYNC_DONE:

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_ON_LIST_DEL_CALLBACK_DONE, evt->result, list_obj->m_delete_abort);
                if(evt->result < 0)
                {
                    list_obj->stopMultiDeleteProcessing();
                    list_obj->showListErrorConfirm(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(evt->result)), VFX_TRUE);
                }
                else
                {
                    /* Check if abort by exit screen */
                    if(list_obj->m_delete_abort)
                    {
                        list_obj->stopMultiDeleteProcessing();
                        list_obj->showListErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_DEL_ABORT), VFX_FALSE);
                    }
                    /* Check if have more item to delete */
                    else if(!list_obj->deleteFileAsync())
                    {
                        list_obj->stopMultiDeleteProcessing();
                    }
                }
                break;

            /* Async delete aborted, shall stop delete the following files */
            case EVT_ID_SRV_FMGR_ASYNC_ABORTING:
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_ON_LIST_DEL_CALLBACK_ABORT, evt->result);
                
                list_obj->stopMultiDeleteProcessing();

                if(evt->result < 0)
                {
                    /* Fail */
                    list_obj->showListErrorConfirm(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(evt->result)), VFX_TRUE);
                }
                else
                {
                    list_obj->showListErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_DEL_ABORT), VFX_FALSE);
                }
                break;
                
            default:
                break;
        }
    }

    return MMI_RET_OK;
}

void VappSoundRecorderListPage::loadFileListMenu(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_LOAD_FILE_LIST);

    /* If file list is still loading, return */
    if(m_file_list->isLoading())
    {
        return;
    }

    /* Disable List menu first, show after list loaded */
    m_list_menu->setHidden(VFX_TRUE); 

    /* Create file */
    if(m_file_list->needReload())
    {
        /* Change back to browser mode if need reload */
        m_mode =  LIST_MODE_BROWSE;
        
        /* Load list asynchronuous */
    	if(m_file_list->createList(onListLoadedCallback, getObjHandle()) < FS_NO_ERROR)
    	{
    	    showFileListMenu();
    	    return;
    	}

        /* Show waiting popup */
        showLoading();
    }
    else
    {
        /* Show list directly */
        showFileListMenu();
    }

}


mmi_ret VappSoundRecorderListPage::onListLoadedCallback(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;
	VappSoundRecorderListPage *list_obj = (VappSoundRecorderListPage*)handleToObject((VfxObjHandle)param->user_data);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_LOAD_CALLBACK);

    if(list_obj != NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_LOAD_CALLBACK_1, param->evt_id, evt->result);

        switch(param->evt_id)
        {
            case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            {
                /* Stop loading */
                list_obj->stopLoading();

                /* Call app to update parameter after refresh */
                list_obj->m_file_list->onLoadedCallback(param);

                if(evt->result < 0)
                {
                    list_obj->showListErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_LOAD_LIST), VFX_TRUE);
                    return MMI_RET_OK;
                }

                list_obj->showFileListMenu();
            }
                break;
            default:
                break;
        }
    }

    return MMI_RET_OK;
}

void VappSoundRecorderListPage::setToolBarMode(VfxU8 mode)
{
	if(LIST_MODE_DELETE == mode)
	{
		/* Change tool bar - no item selected, so disalbe delete and enable select all */
		m_toolbar_delete->removeItem(TOOLBAR_DELETE);
		m_toolbar_delete->addItem(TOOLBAR_SELECT_ALL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SELECT_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    	m_toolbar_delete->addItem(TOOLBAR_DELETE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    	m_toolbar_delete->addItem(TOOLBAR_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
		m_toolbar_delete->m_signalButtonTap.disconnect(this, &VappSoundRecorderListPage::onListModeButtonClicked);
    	m_toolbar_delete->m_signalButtonTap.connect(this, &VappSoundRecorderListPage::onDeleteModeButtonClicked);
		
        m_toolbar_delete->setDisableItem(TOOLBAR_SELECT_ALL, VFX_FALSE);
        m_toolbar_delete->setDisableItem(TOOLBAR_DELETE, VFX_TRUE);
        m_toolbar_delete->setDisableItem(TOOLBAR_CANCEL, VFX_FALSE);
	}
	else
	{
		m_toolbar_delete->removeItem(TOOLBAR_SELECT_ALL);
		m_toolbar_delete->removeItem(TOOLBAR_DELETE);
		m_toolbar_delete->removeItem(TOOLBAR_CANCEL);

    	m_toolbar_delete->addItem(TOOLBAR_DELETE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
		m_toolbar_delete->m_signalButtonTap.disconnect(this, &VappSoundRecorderListPage::onDeleteModeButtonClicked);
    	m_toolbar_delete->m_signalButtonTap.connect(this, &VappSoundRecorderListPage::onListModeButtonClicked);
	}
}

void VappSoundRecorderListPage::changeListMode(VfxU8 mode)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_CHANGE_LIST_MODE, m_mode, mode, m_list_need_refresh);

    m_mode = mode;

    if(LIST_MODE_DELETE == mode)
    {
        m_show_select_all = VFX_TRUE;
        m_select_num = 0;
        m_list_need_refresh = VFX_FALSE;

        /* Allocate memory from heap memory to log select state */
        if(m_select_state == NULL)
        {
            VfxS32 file_count = m_file_list->getCount();

            /* Should not go to this section, but add protection */
            if(file_count == 0)
            {
                mode = LIST_MODE_BROWSE;
                return;
            }

            VFX_ALLOC_MEM(m_select_state, sizeof(VfxBool)*file_count, this);
            kal_mem_set(m_select_state, 0, sizeof(VfxBool)*file_count);
        }

        /* Chage title bar string */
        m_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_DELETE_TITLE));

		setToolBarMode(mode);
        /* Change list to delete mode */
        m_list_menu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
        m_list_menu->m_signalItemTapped.disconnect(this, &VappSoundRecorderListPage::onListItemTapped);
        m_list_menu->m_signalItemSelectionStateChanged.connect(this, &VappSoundRecorderListPage::onListSelectionChanged);
    }
    else
    {
        if(m_select_state != NULL)
        {
            VFX_FREE_MEM(m_select_state);
            m_select_state = NULL;
        }
    
        /* Chage title bar string */
        m_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECLIST));

        /* Change list to browse mode */
        m_list_menu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_list_menu->m_signalItemTapped.connect(this, &VappSoundRecorderListPage::onListItemTapped);
        m_list_menu->m_signalItemSelectionStateChanged.disconnect(this, &VappSoundRecorderListPage::onListSelectionChanged);
        
        if(m_list_need_refresh)
        {
            loadFileListMenu();
            m_list_need_refresh = VFX_FALSE;
        }
        else
        {
            /* Change tool bar */
            setToolBarMode(mode);
        }
    }
}

void VappSoundRecorderListPage::showLoading(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_LOAD_SHOW_LOADING);
    if(NULL == m_indicator)
    {
        VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);
        m_indicator->setPos((getSize().width / 2) - (m_indicator->getSize().width / 2), (getSize().height / 2) - (m_indicator->getSize().height / 2));
        m_indicator->start();
    }
}

void VappSoundRecorderListPage::stopLoading(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_LISTPAGE_LOAD_STOP_LOADING);

    if(m_indicator != NULL)
    {
        VFX_OBJ_CLOSE(m_indicator);
        m_indicator = NULL;
    }
}

VfxBool VappSoundRecorderListPage::getItemText(
    VfxU32 index,                   
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,        
    VcpListMenuTextColorEnum &color)
{
    VfxS32 ret;
    VfxU32 duration = 0;    
    VfxWChar get_filename[SRV_FMGR_PATH_MAX_LEN+1];
    srv_fmgr_fileinfo_struct file_info;

    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        ret = srv_fmgr_filelist_get_filename(m_file_list->m_fl_hdl, index, (WCHAR*) get_filename, sizeof(get_filename));
        if(ret >= FS_NO_ERROR)
        {
            text = VFX_WSTR_MEM(get_filename);
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
        else
        {
            text = VFX_WSTR("");
        }
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        ret =  srv_fmgr_filelist_get_fileinfo(m_file_list->m_fl_hdl, index, &file_info);
    
        if(ret >= FS_NO_ERROR)
        {
            text = VfxWString().format("%d-%d-%d %02d:%02d:%02d", 
                                        file_info.datetime.nYear,file_info.datetime.nMonth, file_info.datetime.nDay,
                                        file_info.datetime.nHour,file_info.datetime.nMin, file_info.datetime.nSec);
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
        else
        {
            text = VFX_WSTR("");
        }    
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
    {
        ret = srv_fmgr_filelist_get_filepath(m_file_list->m_fl_hdl, index, (WCHAR*) get_filename, sizeof(get_filename));

        if(mdi_audio_get_duration((void*)get_filename, &duration) == MDI_AUDIO_SUCCESS)
        {
            VfxWString tempString;
            text = vapp_soundrec_util_get_format_time(tempString, duration);
        }
    #ifndef __LOW_COST_SUPPORT_COMMON__
        else
        {
            text = VFX_WSTR("00:00:00");
        }
    #endif

        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
    }
    else
    {
        return VFX_FALSE;
    }
    
    return VFX_TRUE;
}

VfxU32 VappSoundRecorderListPage::getCount(void) const
{

    if(m_file_list->m_fl_hdl != NULL)
    {
        return m_file_list->getCount();
    }

    return 0;
}

VcpListMenuItemStateEnum VappSoundRecorderListPage::getItemState(VfxU32 index) const
{
    if(m_select_state[index])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

VfxBool VappSoundRecorderListPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    text = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECLIST_EMPTY);
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappSoundRecorderRecordPage implementation
 *****************************************************************************/
VappSoundRecorderRecordPage::VappSoundRecorderRecordPage() :
m_confirmPopup(NULL),
m_indicator(NULL),
m_mode(RECORD_MODE_NONE),
m_specify_quality(SNDREC_QUALITY_BY_SETTING),	
m_record_time_limit(0),
m_record_size_limit(0)
{
}

VappSoundRecorderRecordPage::VappSoundRecorderRecordPage(VfxU8 mode) :
m_confirmPopup(NULL),
m_indicator(NULL),
m_mode(mode),
m_specify_quality(SNDREC_QUALITY_BY_SETTING),
m_record_time_limit(0),
m_record_size_limit(0)
{
}

void VappSoundRecorderRecordPage::onInit()
{
    VfxPage::onInit();

    /* Init variables */
    m_state = SNDREC_STATE_IDLE;
    m_current_time = 0;
    m_check_remain_timer_dur = 0;

    if(RECORD_MODE_APP & m_mode)
    {
        VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();
        m_file_list = obj->m_file_list;
    }
#ifdef __MMI_SOUNDREC_CUI__        	
    else
    {
        m_file_list = NULL;
    }
#endif

    /* Create page components */
    createScreenComponent();

    mmi_frm_cb_reg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, &VappSoundRecorderRecordPage::eventHandler, this);
}

void VappSoundRecorderRecordPage::onDeinit()
{
    /* Force stop and show info ballon to inform user when exit app */
    if(SNDREC_STATE_IDLE != m_state)
    {
        recordStop(VFX_TRUE);
        
        if(RECORD_MODE_APP & m_mode)
        {
            mmi_frm_nmgr_balloon(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_INFO_BALLOON,
                MMI_NMGR_BALLOON_TYPE_INFO,
                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECORD_SAVED).getBuf());
        }    
    }

    VfxPage::onDeinit();

    mmi_frm_cb_dereg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, &VappSoundRecorderRecordPage::eventHandler, this);
}

void VappSoundRecorderRecordPage::onEnter(VfxBool isBackward)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_TRUE);
}

void VappSoundRecorderRecordPage::onExit(VfxBool isBackward)
{
    /* Always turn off now since Ogg can not resume interrupted record */
#ifdef __COSMOS_SOUNDREC_INTERRUPT_SUPPORT__
    if(SNDREC_STATE_RECORD == m_state || SNDREC_STATE_PAUSE == m_state)
    {
        recordStop(VFX_FALSE);
    }
#else
    stopRecordAndExit(VFX_FALSE);
#endif

    /* If finding path, stop it when exit screen */
    m_timer_find_name->stop();
    stopLoading();

	m_timer_error_check->stop();
}


mmi_ret VappSoundRecorderRecordPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
		#ifndef __LOW_COST_SUPPORT_COMMON__
            VfxU8 drive = srv_soundrec_get_storage();
            if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
		#endif
			{
				if(m_timer_find_name->getIsEnabled())
				{
					m_timer_find_name->stop();
					stopLoading();
				}

	            updateRemainTimeText(VFX_TRUE);
	            if(SNDREC_STATE_IDLE != m_state)
	            {
	                recordStop(VFX_TRUE);
	                showConfirmPopup(VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED));
	            }
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
            updateRemainTimeText(VFX_TRUE);
            break;

        case EVT_ID_VAPP_NCENTER_DRAG:
            if(m_state != SNDREC_STATE_IDLE)
            {
                /* Disable NCenter drag down to avoid exit sound recorder */
                return MMI_RET_ERR;
            }
            else
            {
                return VfxPage::onProc(evt);
            }

        default:
            return VfxPage::onProc(evt);
    }
    return MMI_RET_OK;
}

mmi_ret VappSoundRecorderRecordPage::eventHandler(mmi_event_struct *evt)
{
    VappSoundRecorderRecordPage* page = (VappSoundRecorderRecordPage*) evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
            if(SNDREC_STATE_RECORD == page->m_state || SNDREC_STATE_PAUSE == page->m_state)
            {
                return MMI_RET_ERR;
            }
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}

void VappSoundRecorderRecordPage::onButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case SNDREC_BTN_TOOL_REC_LIST:
        {
            VappSoundRecorderListPage *page_list;
            VFX_OBJ_CREATE(page_list, VappSoundRecorderListPage, getMainScr());
            getMainScr()->pushPage(0, page_list);
            break;
        }

	#ifdef __LOW_COST_SUPPORT_COMMON__
		case SNDREC_BTN_TOOL_QUALITY:
		{
			VfxS32 radioSelectIndex2;
			if(srv_soundrec_get_quality() == SRV_SOUNDREC_QUALITY_HIGH)
			{
        		radioSelectIndex2 = 1;
			}
			else
			{
		        radioSelectIndex2 = 0;
			}
			VappSoundRecorderSettingRadioPage *page_quality;
			VFX_OBJ_CREATE_EX(page_quality, VappSoundRecorderSettingRadioPage, getMainScr(), (1, radioSelectIndex2));
			page_quality->m_signalSelectNewItem.connect(this,  &VappSoundRecorderRecordPage::onQualitySelectNewItem);
			getMainScr()->pushPage(VFX_ID_NULL, page_quality);
			break;
		}
	#else            
        case SNDREC_BTN_TOOL_SETTING:
        {
            VappSoundRecorderSettingPage *page_setting;
            VFX_OBJ_CREATE(page_setting, VappSoundRecorderSettingPage, getMainScr());
            getMainScr()->pushPage(0, page_setting);
            break;
        }
	#endif

        case SNDREC_BTN_REC:
        {
            if(m_state == SNDREC_STATE_IDLE)
            {
                if(findRecordPath())
                {
                    recordStart();
                }
            }
            else if(m_state == SNDREC_STATE_INTERRUPTED)
            {
                recordStart();
            }
            else if(m_state == SNDREC_STATE_RECORD)
            {
                recordPause();
            }
            else if(m_state == SNDREC_STATE_PAUSE)
            {
                recordResume();
            }
            break;
        }
        case SNDREC_BTN_STOP:

            stopRecordAndExit(VFX_TRUE);

            /* If still in finding record path path process, stop it when user press stop */
            if(m_timer_find_name->getIsEnabled())
            {
                m_timer_find_name->stop();
                stopLoading();
            }
            break;
        default:
            break;
    }
}

#ifdef __LOW_COST_SUPPORT_COMMON__
void VappSoundRecorderRecordPage::onQualitySelectNewItem(VfxS32 itemId, VfxS32 subItemId)
{
	if (subItemId == 0)
	{
		srv_soundrec_set_quality(SRV_SOUNDREC_QUALITY_NORMAL);
	}
	else if (subItemId == 1)
	{
		srv_soundrec_set_quality(SRV_SOUNDREC_QUALITY_HIGH);
	}
}
#endif

void VappSoundRecorderRecordPage::onUpdateTimerExpir(VfxTimer *timer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_RECPAGE_UPDATE_TIMER, m_state);
    
    if(m_state == SNDREC_STATE_RECORD)
    {
    #ifdef __MTK_TARGET__
        m_current_time = mdi_audio_get_record_time() + m_accumulate_time;
    #else
        m_current_time = (m_current_time/1000 + 1)*1000;
    #endif

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_RECPAGE_UPDATE_TIMER_GET_TIME, static_cast<VfxS32>(m_current_time));
        updateTimeText(m_text_record_time, m_current_time);
    }

    m_frame_cassette->setCurrentTime(m_current_time);
}

void VappSoundRecorderRecordPage::onCheckRemainTimerExpir(VfxTimer *timer)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_FALSE);
}

void VappSoundRecorderRecordPage::onErrorCheckTimerExpir(VfxTimer *timer)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_TRUE);
}


void VappSoundRecorderRecordPage::onFindPathTimerExpir(VfxTimer *timer)
{
    // TODO: Add trace here

    if(findRecordPathLoop())
    {
        /* Write to NVRAM after record success */
        stopLoading();
        recordStart();
    }
    else
    {
        /* Can't find record path, show error*/
        if(m_last_seq == m_stop_seq)
        {
            /* Check for stop sequence again to avoid last seq unchecked */
            if(findRecordPathLoop())
            {
                /* Write to NVRAM after record success */
                stopLoading();
                recordStart();
            }
            else
            {
                stopLoading();
                showConfirmPopup(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_MAX_SEQ));
            }
        }
        else
        {
            /* Continue to find */
            m_timer_find_name->start();
        }
    }
}

void VappSoundRecorderRecordPage::createScreenComponent(void)
{
    /* Create tool bar */
    if(RECORD_MODE_APP & m_mode)
    {
        VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
        toolbar->addItem(SNDREC_BTN_TOOL_REC_LIST, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECLIST), VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST);
		#ifdef __LOW_COST_SUPPORT_COMMON__
			toolbar->addItem(SNDREC_BTN_TOOL_QUALITY, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_QUALITY), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
		#else
        	toolbar->addItem(SNDREC_BTN_TOOL_SETTING, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SETTINGS), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
		#endif
        toolbar->m_signalButtonTap.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);
        setBottomBar(toolbar);
    }

    /*---------------------------- Load components from XML - BEGIN --------------------------------*/
    /* Create common page loader */
    VfxXmlLoader *loader;
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    loader->loadXml(VAPP_SOUNDREC_LAYOUT_COMMON_PAGE);

    /* Draw background image */
    VfxImageFrame *m_image_bg;
    m_image_bg = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("background")), VfxImageFrame);
    m_image_bg->setResId(IMG_ID_VAPP_SNDREC_BACKGROUND);
    m_image_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_image_bg->setSize(LCD_WIDTH, m_image_bg->getSize().height);

    /* Draw tape background image */
    VfxImageFrame *m_image_tape_bg;
    m_image_tape_bg = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("cassette_background")), VfxImageFrame);
    VfxSize tempSize = m_image_tape_bg->getSize();
    m_image_tape_bg->setResId(IMG_ID_VAPP_SNDREC_TAPE_BACKGROUND);
    m_image_tape_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_image_tape_bg->setSize(tempSize);

    /*Create cassette */
    VfxControl *tempControlObj;
    tempControlObj = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("cassette_frame")), VfxControl);
    VfxPoint tempPos = tempControlObj->getPos();
    VFX_OBJ_CLOSE(tempControlObj);

    VFX_OBJ_CREATE(m_frame_cassette, VappSoundRecorderCassetteFrame, this);
    m_frame_cassette->setPos(tempPos);

    /* Close loader */
    VFX_OBJ_CLOSE(loader);

    /* Create record page loader */
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    if(RECORD_MODE_APP & m_mode)
    {    
        loader->loadXml(VAPP_SOUNDREC_LAYOUT_RECORD_PAGE_APP);
    }
#ifdef __MMI_SOUNDREC_CUI__        
    else
    {
        loader->loadXml(VAPP_SOUNDREC_LAYOUT_RECORD_PAGE_CUI);
    }
#endif

    /* Create record time text */
    m_text_record_time = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("record_time")), VfxTextFrame);
    m_text_record_time->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_REC_LARGE);
    font.effect |= VFX_FE1_1;
    m_text_record_time->setFont(font);

    /* Create remaining time text */
    m_text_remain_time = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("remain_time")), VfxTextFrame);
    m_text_remain_time->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_text_remain_time_color = m_text_remain_time->getColor();

    VfxFontDesc font1;
    font1.size = VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_REC_SMALL);
    font1.effect |= VFX_FE1_9;
    m_text_remain_time->setFont(font1);

    /* Create record button */
    m_image_btn_rec = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_record")), VcpButton);
    m_image_btn_rec->setId(SNDREC_BTN_REC);
	m_image_btn_rec->setMargin(0,0,0,0);
	m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC_D,0));
	m_image_btn_rec->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG1_N,IMG_ID_VAPP_SNDREC_BTN_BG1_P,IMG_ID_VAPP_SNDREC_BTN_BG1_N,0));
	m_image_btn_rec->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_image_btn_rec->m_signalClicked.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);

    /* Create stop button */
    m_image_btn_stop = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_stop")), VcpButton);
    m_image_btn_stop->setId(SNDREC_BTN_STOP);
	m_image_btn_stop->setMargin(0,0,0,0);
	m_image_btn_stop->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_STOP,IMG_ID_VAPP_SNDREC_BTN_STOP,IMG_ID_VAPP_SNDREC_BTN_STOP_D,0));
	m_image_btn_stop->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG1_N,IMG_ID_VAPP_SNDREC_BTN_BG1_P,IMG_ID_VAPP_SNDREC_BTN_BG1_N,0));
	m_image_btn_stop->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_image_btn_stop->m_signalClicked.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);
    m_image_btn_stop->setIsDisabled(VFX_TRUE);

#ifdef __MMI_SOUNDREC_CUI__        
    /* If no pause mode, hide stop button at beginning and put both button in the center */
    if(RECORD_MODE_CUI_NO_PAUSE & m_mode)
    {
        VfxPoint btn_pos;
        btn_pos = m_image_btn_rec->getPos();
        btn_pos.x = LCD_WIDTH / 2;

        m_image_btn_rec->setAnchor(0.5f, 0.0f);
        m_image_btn_rec->setPos(btn_pos);
        m_image_btn_stop->setAnchor(0.5f, 0.0f);
        m_image_btn_stop->setPos(btn_pos);
        
        m_image_btn_stop->setHidden(VFX_TRUE);
    }
#endif

    /* Close loader */
    VFX_OBJ_CLOSE(loader);
    /*---------------------------- Load components from XML - END ----------------------------------*/

    /* Create screen update timer for recording */
    VFX_OBJ_CREATE(m_timer_update, VfxTimer, this);
    m_timer_update->setStartDelay(0);
    m_timer_update->setDuration(TIMER_UPDATE_CURRENT_TIME);
    m_timer_update->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onUpdateTimerExpir);

    VFX_OBJ_CREATE(m_timer_check_remain, VfxTimer, this);
    m_timer_check_remain->setStartDelay(TIMER_CHECK_REMAIN_TIME);
    m_timer_check_remain->setDuration(TIMER_CHECK_REMAIN_TIME);
    m_timer_check_remain->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onCheckRemainTimerExpir);

    VFX_OBJ_CREATE(m_timer_error_check, VfxTimer, this);
    m_timer_error_check->setStartDelay(TIMER_CHECK_REMAIN_TIME);
    m_timer_error_check->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onErrorCheckTimerExpir);

    VFX_OBJ_CREATE(m_timer_find_name, VfxTimer, this);
    m_timer_find_name->setStartDelay(TIMER_FIND_NAME);
    m_timer_find_name->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onFindPathTimerExpir);

}

VfxU64 VappSoundRecorderRecordPage::updateRemainTimeText(VfxBool forceUpdate)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_RECPAGE_UPDATE_REMAIN_TIME, forceUpdate);

    /* Check if memory card exists, only update when force update called */
    if(forceUpdate)
    {
    #ifndef __LOW_COST_SUPPORT_COMMON__
        VfxU8 m_drive = srv_soundrec_get_storage();
        if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(m_drive))
	#endif
		{
            VfxWChar record_drive[10];
            S32 fs_handle;

            kal_wsprintf(record_drive, "%c:\\", srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
            if((fs_handle = FS_Open(record_drive, FS_READ_ONLY)) < FS_NO_ERROR)
            {
                m_text_remain_time->setColor(m_text_remain_time_color);            
                if((FS_DRIVE_NOT_FOUND == fs_handle || FS_MEDIA_CHANGED == fs_handle))
                {
	                #ifndef __LOW_COST_SUPPORT_COMMON__
	                    m_text_remain_time->setString(VFX_WSTR_RES(STR_GLOBAL_NO_MEMORY_CARD));
					#else
						m_text_remain_time->setString(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD));
					#endif
					m_timer_check_remain->stop();
                }
                else
                {
                    m_text_remain_time->setString(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(fs_handle)));
					m_timer_error_check->start();
				}
                return 0;
            }
            else
            {
                FS_Close(fs_handle);
            }
        }
    }
#ifdef __MMI_SOUNDREC_CUI__        
    /* Display the record limitation time or disk free space time */
    if(RECORD_MODE_CUI_DISPLAY_REC_LIMIT & m_mode)
    {
        return updateLimitTimeText(forceUpdate);
    }
    else
#endif		
    {
        return updateFreeSpaceTimeText(forceUpdate);
    }
}

VfxU64 VappSoundRecorderRecordPage::updateFreeSpaceTimeText(VfxBool forceUpdate)
{
    VfxS32 record_rate;
    VfxU64 remain_time = 0, new_timer_dur;
	vapp_soundrec_check_size_result check_result;

    /* Get record bitrate */
    mdi_audio_rec_param_struct rec_param;
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, srv_soundrec_get_mdi_quality(), &rec_param);

    record_rate = rec_param.byte_rate;
    
    /* Get disk size */
    check_result = vapp_soundrec_util_get_record_drv_free_space();

    /* Caculate remain time (in seconds) */
    if(record_rate > 0)
    {
        remain_time = (U64) (check_result.disk_size / record_rate);
    }
	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_RECPAGE_UPDATE_FREE_SPACE, static_cast<VfxS32>(remain_time));
	
    /* Show text */
    VfxU32 hour, minute;
    
    if(remain_time > 3600)
    {
        hour = remain_time / 3600;

        VfxWString temp_str;
        temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
        temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER);
        temp_str += VfxWString().format(" %d ", hour);
        if(hour == 1)
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_HOUR);
        }
        else
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_HOURS);
        }

        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(temp_str);
        new_timer_dur = 300000; /* Check remain storage every 5 minutes */
    }
    else if(remain_time > 60)
    {
        minute = remain_time / 60;

        VfxWString temp_str;
        temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
        temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER);
        temp_str += VfxWString().format(" %d ", minute);
        if(minute == 1)
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_MIN);
            new_timer_dur = (remain_time - 60) * 1000; /* Check remain again when time < 1 min */
        }
        else
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_MINS);
            new_timer_dur = 10000; /* Check remain storage every 10 seconds */
        }

        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(temp_str);
    }
    else if(remain_time == 0)
    {
		if(check_result.ret >= 0)
		{
        	m_text_remain_time->setString(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
		}
		else
		{
			m_text_remain_time->setString(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(check_result.ret)));
			m_timer_error_check->start();
		}
        m_text_remain_time->setColor(VFX_COLOR_RED);
        m_timer_check_remain->stop();

        /* Disable record button when memory full */
        m_image_btn_rec->setIsDisabled(VFX_TRUE);
        return 0;
    }
    else if(remain_time <= 60)
    {
        /* Only update remain time for 60, 55, 50, 45, ... for last minutes */
        if(forceUpdate || 
          (remain_time % 5 == 0) ||
          (m_last_update_remain_time == 0) ||
          (m_last_update_remain_time >= remain_time + 5))
        {
            VfxWString temp_str;
            temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
            temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_IS);
            temp_str += VfxWString().format(" %d ", remain_time);
            if(remain_time == 1)
            {
                temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_SEC);
            }
            else
            {
                temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_SECS);
            }

            m_text_remain_time->setColor(VFX_COLOR_RED);            
            m_text_remain_time->setString(temp_str);
            m_last_update_remain_time = remain_time;
        }
        
        if(remain_time % 5 == 0)
        {
            new_timer_dur = 5000;
        }
        else
        {
            new_timer_dur = (remain_time%5) * 1000;
        }
    }
    else
    {
        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_CHECK_REMAIN_TIME));
        m_timer_check_remain->stop();
        return 0;
    }

    m_image_btn_rec->setIsDisabled(VFX_FALSE);

    if(new_timer_dur != m_check_remain_timer_dur)
    {
        m_check_remain_timer_dur = new_timer_dur;
        m_timer_check_remain->stop();

        m_timer_check_remain->setStartDelay(m_check_remain_timer_dur);
        m_timer_check_remain->setDuration(m_check_remain_timer_dur);

        // If update by timer expire, restart again
        if(!forceUpdate)
        {
            m_timer_check_remain->start();
        }
    }

    return remain_time;
}

VfxU64 VappSoundRecorderRecordPage::updateLimitTimeText(VfxBool forceUpdate)
{
    VfxU32 minute, second;

    minute = (m_record_time_limit %3600)/60;
    second = (m_record_time_limit %3600)%60;

    VfxWString temp_str;
    temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
    temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_IS);
    temp_str += VfxWString().format(" %02d:%02d", minute, second);

    m_text_remain_time->setColor(m_text_remain_time_color);
    m_text_remain_time->setString(temp_str);

    return m_record_time_limit;
}

void VappSoundRecorderRecordPage::updateRecButtonState(VfxBool is_pause)
{
#ifdef __MMI_SOUNDREC_CUI__        
    /* No pause icon, show stop button directly */
    if(RECORD_MODE_CUI_NO_PAUSE & m_mode)
    {
        if(is_pause)
        {
            m_image_btn_rec->setHidden(VFX_TRUE);
            m_image_btn_stop->setHidden(VFX_FALSE);
        }
        else
        {
            m_image_btn_rec->setHidden(VFX_FALSE);
            m_image_btn_stop->setHidden(VFX_TRUE);
        }
    }
    else
#endif		
    {
        if(is_pause)
        {
            m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PAUSE,IMG_ID_VAPP_SNDREC_BTN_PAUSE,IMG_ID_VAPP_SNDREC_BTN_REC_D,0));
        }
        else
        {
            m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC_D,0));
        }
    }
}


void VappSoundRecorderRecordPage::updateTimeText(VfxTextFrame *text, VfxU64 display_time)
{
    VfxWChar str_buf[12];
    VfxU32 hour, minute, second;

    display_time = display_time / 1000;

    hour = display_time / 3600;
    minute = (display_time %3600)/60;
    second = (display_time %3600)%60;

    kal_wsprintf(str_buf, "%02d:%02d:%02d", hour, minute, second);

    text->setString(VFX_WSTR_MEM(str_buf));
}

VfxBool VappSoundRecorderRecordPage::findRecordPath(void)
{
    FMGR_FILTER filter;
    S16 error;
    S32 result;    
    VfxU16 last_seq = 1;

	/* Check if in background call*/
	//#ifdef __MMI_BACKGROUND_CALL__
		if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				(WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
			return VFX_FALSE;
		}
	//#endif
	

	#ifdef __LOW_COST_SUPPORT_COMMON__
		VfxU8 m_drive = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	#else
	    VfxU8 m_drive = srv_soundrec_get_storage();
	#endif
		kal_wsprintf(m_record_path, "%c:\\%w", m_drive, RECORD_DOWNLOAD_FOLDER_NAME);
	
    /* Check and create folder */
    if((result = srv_fmgr_fs_create_folder(m_record_path)) < FS_NO_ERROR)
    {
        /* Check if user wants to apply to default storage */
        if((FS_DRIVE_NOT_FOUND == result || FS_MEDIA_CHANGED == result) &&
           (SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(m_drive)))
        {
			#ifdef __LOW_COST_SUPPORT_COMMON__
	            mmi_frm_nmgr_balloon(
	                MMI_SCENARIO_ID_DEFAULT,
	                MMI_EVENT_INFO_BALLOON,
	                MMI_NMGR_BALLOON_TYPE_INFO,
	                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD).getBuf());
			#else
            	showDefaultStoragePopup();
			#endif
        }
        else
        {
            showConfirmPopup(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(result)));
        }
        return VFX_FALSE;
    }

    /* Check if folder empty. if empty, reset the max file sequence */
    vadp_soundrec_util_filter_set(&filter);
    if(srv_fmgr_fs_path_is_not_empty(m_record_path, &filter) == 0)
    {
        WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
    }
    else
    {
        /* Get last max sequence number */
        ReadValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
        if(last_seq > VAPP_SNDREC_MAX_SEQUENCE)
        {
            last_seq = 1;
            WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
        }
    }

    m_last_seq = last_seq;
    if(last_seq == 1)
    {
        m_stop_seq = VAPP_SNDREC_MAX_SEQUENCE;
    }
    else
    {
        m_stop_seq = last_seq - 1;
    }

    if(findRecordPathLoop())
    {
        return VFX_TRUE;
    }
    else
    {
        /* If can't find file name, start a timer and find again later */
        showLoading();
        m_timer_find_name->start();
        return VFX_FALSE;
    }
}

VfxBool VappSoundRecorderRecordPage::findRecordPathLoop(void)
{
    VfxU16 start_index, stop_index, result_index;

    // TODO: Add trace here
    start_index = m_last_seq;

    if(m_last_seq > m_stop_seq)
    {
        if( (start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1) <= VAPP_SNDREC_MAX_SEQUENCE)
        {
            stop_index = start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1;
        }
        else
        {
            stop_index = VAPP_SNDREC_MAX_SEQUENCE;
        }
    }
    else
    {
        if( (start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1) <= m_stop_seq)
        {
            stop_index = start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1;
        }
        else 
        {
            stop_index = m_stop_seq;
        }
    }

    /* Check if use quality in setting */
    VfxBool is_default = VFX_TRUE;
    VfxU8 quality = 0;
    if(SNDREC_QUALITY_NORMAL == m_specify_quality)
    {
        is_default = VFX_FALSE;
        quality = MDI_AUDIO_REC_QUALITY_LOW;
    }
    else if (SNDREC_QUALITY_HIGH == m_specify_quality)
    {
        is_default = VFX_FALSE;
        quality = MDI_AUDIO_REC_QUALITY_HIGH;
    }

    /* Get file name */
    if(!vapp_soundrec_util_get_record_file_path(start_index, stop_index, &result_index, m_record_path, ((VAPP_SNDREC_FILEPATH_LEN + 1)*sizeof(VfxWChar)), is_default, quality))
    {
        /* Something wrong */
        if(result_index == 0xFFFF)
        {
        	stopLoading();
            showConfirmPopup(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_CREATE_PATH));
        }
        else
        {
            if(result_index == m_stop_seq)
            {
                m_last_seq = m_stop_seq;
            }
            else
            {
                if(result_index >= VAPP_SNDREC_MAX_SEQUENCE)
                {
                    m_last_seq = 1;
                }
                else
                {
                    m_last_seq = result_index + 1;
                }
            }
        }
        return VFX_FALSE;
    }
    else
    {
        if(result_index < VAPP_SNDREC_MAX_SEQUENCE)
        {
            m_last_seq = result_index + 1;
        }
        else
        {
            result_index = VAPP_SNDREC_MAX_SEQUENCE;
        }

        /* Write  m_last_seqto NVRAM after record success */
        return VFX_TRUE;
    }
}

void VappSoundRecorderRecordPage::recordErrorHdlr(mdi_result result)
{
	VfxResId string = STR_GLOBAL_ERROR;
	
    if(result == MDI_AUDIO_DISC_FULL)
    {
    	string = STR_GLOBAL_MEMORY_FULL;
    }
	
    showConfirmPopup(VFX_WSTR_RES(string));
}

void VappSoundRecorderRecordPage::recordCallbackHdlr(mdi_result result)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_RECPAGE_RECCALLBACK, result);
    
    switch (result)
    {
        /* Interrupted */
        case MDI_AUDIO_TERMINATED:
            recordStop(VFX_FALSE);
            break;
        /* Reach record limit */
        case MDI_AUDIO_SUCCESS:
		#ifdef __MMI_SOUNDREC_CUI__        			
            if(RECORD_MODE_CUI & m_mode)
            {
                VfxWString tempString = VFX_WSTR_RES(STR_ID_VAPP_SNDREC_REACH_LIMIT);
        		mmi_frm_nmgr_balloon(
        			MMI_SCENARIO_ID_DEFAULT,
        			MMI_EVENT_INFO_BALLOON,
        			MMI_NMGR_BALLOON_TYPE_INFO,
        			(WCHAR *)tempString.getBuf());
            }
		#endif
            onButtonClicked(this, SNDREC_BTN_STOP);
            break;
        /* Disc full */
        case MDI_AUDIO_DISC_FULL:
            if(RECORD_MODE_APP & m_mode)
            {
                recordStop(VFX_TRUE);
                showConfirmPopup(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
                updateRemainTimeText(VFX_TRUE);
            }
		#ifdef __MMI_SOUNDREC_CUI__        
            else
            {
                VfxWString tempString = VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL);
        		mmi_frm_nmgr_balloon(
        			MMI_SCENARIO_ID_DEFAULT,
        			MMI_EVENT_INFO_BALLOON,
        			MMI_NMGR_BALLOON_TYPE_INFO,
        			(WCHAR *)tempString.getBuf());

                onButtonClicked(this, SNDREC_BTN_STOP);
            }
		#endif
            break;
        default:
            break;
    }
}


void VappSoundRecorderRecordPage::recordStart(void)
{
    mdi_result result;
    VfxU64 remain_time;
    VfxS16 error;   

    /* Check if in background call*/
//#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
        return;
    }
//#endif

    /* Set start time to 0, if it is a new record */
    if(SNDREC_STATE_IDLE == m_state)
    {
        m_current_time = 0;
        m_accumulate_time = 0;
    }
    else if(SNDREC_STATE_INTERRUPTED == m_state)
    {
        m_current_time = m_accumulate_time;
    }

    /* Terminate background play */
    mdi_audio_terminate_background_play();

    /* update remain time */
    m_last_update_remain_time = 0;
    remain_time = updateRemainTimeText(VFX_TRUE);
    
    /* Start record */
    VfxBool is_default = VFX_TRUE;
    VfxU8 quality = 0;
    if(SNDREC_QUALITY_NORMAL == m_specify_quality)
    {
        is_default = VFX_FALSE;
        quality = MDI_AUDIO_REC_QUALITY_LOW;
    }
    else if (SNDREC_QUALITY_HIGH == m_specify_quality)
    {
        is_default = VFX_FALSE;
        quality = MDI_AUDIO_REC_QUALITY_HIGH;
    }
    result = vadp_soundrec_rec_start(m_record_path, this, m_record_size_limit, m_record_time_limit, is_default, quality);

    if(result == MDI_AUDIO_SUCCESS)
    {
        /* Write last seq number after record success */
        WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &m_last_seq, DS_SHORT, &error);

        /* Change state */
        m_state = SNDREC_STATE_RECORD;
        m_image_btn_stop->setIsDisabled(VFX_FALSE);
        wgui_status_icon_bar_show_icon(STATUS_ICON_VOICE_RECORD); 
    }
	else
	{
		recordErrorHdlr(result);
		return;
	}

    /* Show record file name */
    m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(m_record_path)));
    m_frame_cassette->setTotalTime(remain_time*1000);
    m_frame_cassette->setCurrentTime(m_current_time);
    m_frame_cassette->startRotate();

    /* Start timer to update duration and remain time */
    m_timer_update->start();
    m_timer_check_remain->start();

    /* Change button to pause icon */
    updateRecButtonState(VFX_TRUE);

    /* Disable toolbar */
    if(RECORD_MODE_APP & m_mode)
    {
        toolbar->setDisableItem(SNDREC_BTN_TOOL_REC_LIST, VFX_TRUE);
	#ifdef __LOW_COST_SUPPORT_COMMON__
		toolbar->setDisableItem(SNDREC_BTN_TOOL_QUALITY, VFX_TRUE);
	#else
		toolbar->setDisableItem(SNDREC_BTN_TOOL_SETTING, VFX_TRUE);
	#endif
        
    }
}

void VappSoundRecorderRecordPage::recordPause(void)
{
    mdi_result result;
    
    /* Pause record */
    result = vadp_soundrec_rec_pause(this);
    if(result != MDI_AUDIO_SUCCESS)
    {
		recordStop(VFX_TRUE);
    	recordErrorHdlr(result);
		updateRemainTimeText(VFX_TRUE);
		return;
    }

    /* Change state */
    m_state = SNDREC_STATE_PAUSE;
    wgui_status_icon_bar_hide_icon(STATUS_ICON_VOICE_RECORD); 

    /* Stop rotation */
    m_frame_cassette->stopRotate();

    /* Stop update duration */
    m_timer_update->stop();
    m_timer_check_remain->stop();

    /* update remaining time */
    //updateRemainTimeText(VFX_TRUE);

    /* Change button to record state */
    updateRecButtonState(VFX_FALSE);
}

void VappSoundRecorderRecordPage::recordResume(void)
{
    mdi_result result;

    result = vadp_soundrec_rec_resume(this);
    if(result != MDI_AUDIO_SUCCESS)
    {
		recordStop(VFX_TRUE);
    	recordErrorHdlr(result);
		updateRemainTimeText(VFX_TRUE);
		return;
    }

    /* Change state */
    m_state = SNDREC_STATE_RECORD;
    wgui_status_icon_bar_show_icon(STATUS_ICON_VOICE_RECORD); 

    /* Start rotation */
    m_frame_cassette->startRotate();

    /* Start update duration */
    m_timer_update->start();
    m_timer_check_remain->start();

    /* Change button to pause state */
    updateRecButtonState(VFX_TRUE);
}

void VappSoundRecorderRecordPage::recordStop(VfxBool is_finish)
{
    if(m_state == SNDREC_STATE_RECORD || m_state == SNDREC_STATE_PAUSE)
    {
        if(is_finish)
        {
            /* Change state */
            m_state = SNDREC_STATE_IDLE;
            m_image_btn_stop->setIsDisabled(VFX_TRUE);

            /* Clear file name and path if record finish */
            m_text_record_time->setString(VFX_WSTR("00:00:00"));
            m_frame_cassette->setDisplayName(VFX_WSTR(""));
        }
        else
        {
            /* Keep total record time for interrupt case */
            m_accumulate_time = m_current_time;
            m_state = SNDREC_STATE_INTERRUPTED;
        }

        /* Stop record */
        vadp_soundrec_rec_stop();

        wgui_status_icon_bar_hide_icon(STATUS_ICON_VOICE_RECORD); 

        /* Stop rotation */
        m_frame_cassette->stopRotate();

        /* Stop update duration */
        m_timer_update->stop();
        m_timer_check_remain->stop();

        /* update remaining time */
        updateRemainTimeText(VFX_TRUE);

        /* Change button to record state */
        updateRecButtonState(VFX_FALSE);
    }
    else if (SNDREC_STATE_INTERRUPTED == m_state)
    {
        if(is_finish)
        {
            /* Change state */
            m_state = SNDREC_STATE_IDLE;
            m_image_btn_stop->setIsDisabled(VFX_TRUE);            

            /* Clear file name and path if record finish */
            m_text_record_time->setString(VFX_WSTR("00:00:00"));
            m_frame_cassette->setDisplayName(VFX_WSTR(""));
        }
    }

    /* Enable toolbar */
    if((RECORD_MODE_APP & m_mode) && is_finish)
    {
        toolbar->setDisableItem(SNDREC_BTN_TOOL_REC_LIST, VFX_FALSE);
	#ifdef __LOW_COST_SUPPORT_COMMON__
		toolbar->setDisableItem(SNDREC_BTN_TOOL_QUALITY, VFX_FALSE);
	#else
        toolbar->setDisableItem(SNDREC_BTN_TOOL_SETTING, VFX_FALSE);
	#endif
    }
}

void VappSoundRecorderRecordPage::stopRecordAndExit(VfxBool user_stop)
{
    /* Force stop and show info ballon to inform user when exit app */
    if(SNDREC_STATE_IDLE != m_state)
    {
        recordStop(VFX_TRUE);

        /* Will use file list in playback app mode */
        if(m_file_list != NULL)
        {
            m_file_list->setDirty();
        }

        /* For app mode, remain in record screen */
        if(RECORD_MODE_APP & m_mode)
        {
    		mmi_frm_nmgr_balloon(
    			MMI_SCENARIO_ID_DEFAULT,
    			MMI_EVENT_INFO_BALLOON,
    			MMI_NMGR_BALLOON_TYPE_INFO,
    			(WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECORD_SAVED).getBuf());
        }
	#ifdef __MMI_SOUNDREC_CUI__ 	   		
        else
        {
            if(RECORD_MODE_CUI_NO_PREVIEW & m_mode)
            {
                /* If no preview, go back to app directly */
                vcui_soundrec_evt_struct evt;

                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_SOUNDREC_RESULT, getApp()->getGroupId());

                if(user_stop)
                	evt.result = 1;
				else
					evt.result = 0;
				
                evt.file_path = m_record_path;

                VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
                app->postToCaller((mmi_group_event_struct*)&evt);                        
            }
            else /* RECORD_MODE_CUI */
            {
                /* For CUI mode, goes to playback mode to let user preview and insert */
                VappSoundRecorderPlayPage *page_play;
                VFX_OBJ_CREATE_EX(page_play, VappSoundRecorderPlayPage, getMainScr(), (VFX_WSTR_MEM(m_record_path), VappSoundRecorderPlayPage::PLAYBACK_MODE_CUI, VFX_FALSE));
                getMainScr()->pushPage(0, page_play);
            }
        }   
	#endif			
    }
}

void VappSoundRecorderRecordPage::onCpopupButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        case VCP_CONFIRM_BUTTON_SET_OK:
        {
            break;
        }
    }
	VFX_OBJ_CLOSE(m_confirmPopup);
}


void VappSoundRecorderRecordPage::showConfirmPopup(const VfxWString &text)
{
	if(m_confirmPopup == NULL)
	{
		VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
		m_confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
		m_confirmPopup->setText(text);
		
		m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		m_confirmPopup->setAutoDestory(VFX_FALSE);
		m_confirmPopup->m_signalButtonClicked.connect(this, &VappSoundRecorderRecordPage::onCpopupButtonClicked);
		m_confirmPopup->show(VFX_TRUE);
	}
}

#ifndef __LOW_COST_SUPPORT_COMMON__
void VappSoundRecorderRecordPage::showDefaultStoragePopup(void)
{
    /* Show confirm popup */
    VcpConfirmPopup *storagePopup;
    VFX_OBJ_CREATE(storagePopup, VcpConfirmPopup, this);
    storagePopup->setInfoType(VCP_POPUP_TYPE_QUESTION);

    storagePopup->setText(VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE));
    storagePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    storagePopup->m_signalButtonClicked.connect(this, &VappSoundRecorderRecordPage::onDefaultStorageConfirm);
    storagePopup->setAutoDestory(VFX_TRUE);
    storagePopup->show(VFX_TRUE);
}

void VappSoundRecorderRecordPage::onDefaultStorageConfirm(VfxObject* vfx_obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
        srv_soundrec_set_storage(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_PHONE_TYPE));

        /* Need to reload list in list screen */
        if(RECORD_MODE_APP & m_mode)
        {
            VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();
            obj->m_file_list->setStorageChange();    
        }

		updateRemainTimeText(VFX_TRUE);

        /* Start record*/
        if(m_state == SNDREC_STATE_IDLE)
        {
            if(findRecordPath())
            {
                recordStart();
            }
        }
    }
}
#endif

void VappSoundRecorderRecordPage::showLoading(void)
{
    /* Show loading */
    if(m_indicator == NULL)
    {
        VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);

        /* Sets the position and width of indicator bar. */

        m_indicator->setPos(getSize().width / 2, POPUP_Y);
		m_indicator->setAnchor(0.5, 0.5);
		m_indicator->start();
    }
}

void VappSoundRecorderRecordPage::stopLoading(void)
{
    if(m_indicator != NULL)
    {
        VFX_OBJ_CLOSE(m_indicator);
        m_indicator = NULL;
    }
}
void VappSoundRecorderRecordPage::setRecordParam(VfxU8 param, VfxU32 value)
 {
    if(SNDREC_PARAM_SIZE == param)
    {
        m_record_size_limit = value;
    }
    else if(SNDREC_PARAM_TIME == param)
    {
        m_record_time_limit = value;
    }
    else if(SNDREC_PARAM_QUALITY == param)
    {
        m_specify_quality = value;
    }
}


/***************************************************************************** 
 * Class VappSoundRecorderPlayPage implementation
 *****************************************************************************/
VappSoundRecorderPlayPage::VappSoundRecorderPlayPage() :
m_mode(PLAYBACK_MODE_APP),
m_auto_play(VFX_FALSE)
{
}

VappSoundRecorderPlayPage::VappSoundRecorderPlayPage(const VfxWString &file_path, vapp_sound_play_mode_enum mode, VfxBool auto_play):
m_filepath(file_path),
m_mode(mode),
m_auto_play(auto_play)
{
}

void VappSoundRecorderPlayPage::onInit()
{
    VfxPage::onInit();

    /* Init variables */
    m_state = SNDREC_STATE_IDLE;
	m_seek_state = SNDREC_SEEK_IDLE;
    m_duration = 0;
    m_current_time = 0;
    m_indicator = NULL;
	m_cacheTable = NULL;
	m_display_hour = 100;
	m_reset_seek_state = VFX_FALSE;

    if(PLAYBACK_MODE_APP == m_mode)
    {
        VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();

        m_file_list = obj->m_file_list;
    }
#ifdef __MMI_SOUNDREC_CUI__        
    else
    {
        m_file_list = NULL;
    }
#endif

    /* Create page components */
    createScreenComponent();

    /* Register for volume control page */
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VappSoundRecorderPlayPage::onStaticProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappSoundRecorderPlayPage::onStaticProc, this);

}

void VappSoundRecorderPlayPage::onDeinit()
{
	if(m_state != SNDREC_STATE_IDLE)
	{
	    playStop();
	    playClose();
	}

	m_reset_seek_state = VFX_FALSE;

    /* De-register when exit this page */
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VappSoundRecorderPlayPage::onStaticProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_PROF_IS_PLAYING, &VappSoundRecorderPlayPage::onStaticProc, this);

    VfxPage::onDeinit();
}

void VappSoundRecorderPlayPage::onEnter(VfxBool isBackward)
{
    /* Check fmgr service if it is dirty when come back */
    if(isBackward && (m_file_list != NULL))
    {
        if(srv_fmgr_filelist_is_dirty(m_file_list->m_fl_hdl))
        {
            m_file_list->setDirty();

            showErrorConfirm(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_LIST_DIRTY),VFX_TRUE);
        }
    }
}

void VappSoundRecorderPlayPage::onEntered()
{
    /* Auto start play for first time enter */
    if(m_auto_play)
    {
        playOpen();
        /* Open success */
        if(SNDREC_STATE_STOP == m_state)
        {
            playStart();
        }
        m_auto_play = VFX_FALSE;
    }
}

void VappSoundRecorderPlayPage::onExit(VfxBool isBackward)
{
	if(m_seek_state == SNDREC_SEEK_SEEKING)
	{
		seekStop();
		m_reset_seek_state = VFX_TRUE;
	}
}

mmi_ret VappSoundRecorderPlayPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        /* For Memory card */
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            {
			#ifndef __LOW_COST_SUPPORT_COMMON__
                VfxU8 drive = srv_soundrec_get_storage();
                if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
			#endif
				{
                    getMainScr()->popPage();
                }
                return MMI_RET_OK;
            }

        /* For background call end, update duration */
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
            {
                if(SNDREC_STATE_IDLE == m_state)
                {
                    playOpen();
                }
            }
            break;

	#ifdef __MMI_SOUNDREC_CUI__        
        /* FOR UC CUI events, do nothing now */
        case EVT_ID_CUI_UC_SMS_SENT:
            break;
        case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
            break;
        case EVT_ID_CUI_UC_EMAILCOMPOSER_CLOSE:
            break;
	#endif	
	
        default:
            break;
    }

    return VfxPage::onProc(evt);
}

mmi_ret VappSoundRecorderPlayPage::onStaticProc(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
        {
            VfxBool adjust_vol = VFX_FALSE;
            VappSoundRecorderPlayPage* page = (VappSoundRecorderPlayPage*) evt->user_data;
            VappSoundRecorderApp *app = (VappSoundRecorderApp*)page->getApp();

            if(app->isGroupTopActive())
            {
                adjust_vol = VFX_TRUE;
            }
            else
            {
                if(vadp_soundrec_is_playing())
                {
                    adjust_vol = VFX_TRUE;
                }
            }
        
            vapp_vol_dialog_evt_struct *vol_evt = (vapp_vol_dialog_evt_struct*) evt;
            if(adjust_vol && vol_evt->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
                return !MMI_RET_OK;
            }
            break;
        }
		
        case EVT_ID_SRV_PROF_IS_PLAYING:
		{
			if(vadp_soundrec_is_playing())
			{
				return !MMI_RET_OK;
			}
			break;
		}
    }

    return MMI_RET_OK;
}

void VappSoundRecorderPlayPage::onButtonClicked(VfxObject* obj, VfxId id)
{
    /* If in showing EOF process, ignore button action */
    if(m_timer_eof->getIsEnabled())
    {
        return;
    }

    if(m_file_list != NULL)
	{
	    if(m_file_list->isLoading())
	    {
	        return;
	    }
	}
	
    switch(id)
    {
         case SNDREC_BTN_PLAY:
            /* Stop play next delay timer if user press play directly */
            m_timer_play_next->stop();
			if((m_seek_state == SNDREC_SEEK_STOP)&&(m_current_time != 0))
			{
				m_timer_seek->start();
			}
			else
			{
				playReq();
			}
            break;

        case SNDREC_BTN_PREV:
            /* Keep current state, if press very quick, keep first press state */
            if(!m_timer_play_next->getIsEnabled() && m_seek_state != SNDREC_SEEK_SEEKING)
            {
                m_prev_state = m_state;
            }
            m_is_next = VFX_FALSE;
            pickNext();
            break;
        case SNDREC_BTN_NEXT:
            if(!m_timer_play_next->getIsEnabled() && m_seek_state != SNDREC_SEEK_SEEKING)
            {
                m_prev_state = m_state;
            }
            m_is_next = VFX_TRUE;
            pickNext();
            break;

        default:
            break;
    }
}

#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
void VappSoundRecorderPlayPage::onGesture(VappSoundRecorderGesture gesture)
{
    /* process gesture */
    switch(gesture)
    {
        case VG_GO_PREV:
            /* Keep current state, if press very quick, keep first press state */
            if(!m_timer_play_next->getIsEnabled() && m_seek_state != SNDREC_SEEK_SEEKING)
            {
                m_prev_state = m_state;
            }
            m_is_next = VFX_FALSE;
            pickNext();
            break;

        case VG_GO_NEXT:
            if(!m_timer_play_next->getIsEnabled() && m_seek_state != SNDREC_SEEK_SEEKING)
            {
                m_prev_state = m_state;
            }
            m_is_next = VFX_TRUE;
            pickNext();        
            break;
    }
}
#endif

void VappSoundRecorderPlayPage::onAppToolbarButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case SNDREC_BTN_TOOL_NEW_RECORD:
		{
            /* Enter playback mode form record list in app mode, go back two pages */
            getMainScr()->popPage();
            getMainScr()->popPage();

            break;
        }
        case SNDREC_BTN_TOOL_DELETE:
            deleteFilePopup();
            break;

        case SNDREC_BTN_TOOL_RENAME:
            renameFilePopup();
            break;
	#ifdef __MMI_SET_AS_RINGTONE_POPUP__
        case SNDREC_BTN_TOOL_SET_AS:
            launchSetRingtone();
            break;
	#endif
        case SNDREC_BTN_TOOL_SHARE:
            shareFilePopup();
            break;
        default:
            break;
    }

}

#ifdef __MMI_SOUNDREC_CUI__        
void VappSoundRecorderPlayPage::onCuiToolbarButtonClicked(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case SNDREC_BTN_TOOL_RE_RECORD:
            getMainScr()->popPage();
            break;
        case SNDREC_BTN_TOOL_INSERT:
        {
            vcui_soundrec_evt_struct evt;

            MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_SOUNDREC_RESULT, getApp()->getGroupId());

            evt.result = 1;
            evt.file_path = m_filepath.getBuf();

            VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
            app->postToCaller((mmi_group_event_struct*)&evt);
        }
            break;

        case SNDREC_BTN_TOOL_CANCEL:
        {
            vcui_soundrec_evt_struct evt;

            MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_SOUNDREC_RESULT, getApp()->getGroupId());

            evt.result = 0;

            VfxCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
            app->postToCaller((mmi_group_event_struct*)&evt);
            
        }
            break;
        default:
            break;
    }
}
#endif

void VappSoundRecorderPlayPage::onSliderPressed(VcpSlider* slider, VfxFloat val)
{
    m_is_slider_pressed = VFX_TRUE;
	
	if(!m_timer_play_next->getIsEnabled() && 
		!m_timer_seek->getIsEnabled() && m_seek_state != SNDREC_SEEK_SEEKING)
	{
    	m_prev_state = m_state;
	}

	m_timer_play_next->stop();

	if(m_seek_state == SNDREC_SEEK_SEEKING)
	{
		seekStop();
	}

    /* Stop EOF timer if user press slider when EOF */
    m_timer_eof->stop();

    if((m_state == SNDREC_STATE_PLAY) || (m_state == SNDREC_STATE_PAUSE))
    {
		playStop();
    }
}

void VappSoundRecorderPlayPage::onSliderValueChange(VcpSlider* slider, VfxFloat val)
{
    m_current_time = val;

    updateTimeText(m_text_current_time, m_current_time); 
}

void VappSoundRecorderPlayPage::onSliderReleased(VcpSlider* slider, VfxFloat val)
{
    m_is_slider_pressed = VFX_FALSE;
    m_current_time = val;
	//seekStart();
	m_timer_seek->start();
}

void VappSoundRecorderPlayPage::seekStart()
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_PLAYPAGE_SEEKSTART, m_state);

    if(m_state == SNDREC_STATE_IDLE)
    {
    	playOpen();
    }

	if(m_state == SNDREC_STATE_STOP && m_seek_state != SNDREC_SEEK_SEEKING)
	{		
		mdi_audio_start_seek(reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filepath.getBuf())), 
			m_cacheTable, 
			MDI_CACHE_SIZE, 
			m_current_time, 
			vadp_soundrec_seekcallback, 
			this
			);
		
		m_seek_state = SNDREC_SEEK_SEEKING;
		toolbar->setIsDisabled(VFX_TRUE);
		m_image_btn_play->setIsDisabled(VFX_TRUE);
		showLoading();
	}	
}

void VappSoundRecorderPlayPage::seekStop()
{
    if(m_timer_seek->getIsEnabled())
	{
		m_timer_seek->stop();
	}

	stopLoading();
	vadp_soundrec_seekStop();
	
	m_seek_state = SNDREC_SEEK_STOP;
	m_image_btn_play->setIsDisabled(VFX_FALSE);
	toolbar->setIsDisabled(VFX_FALSE);
}

void VappSoundRecorderPlayPage::onUpdateTimerExpir(VfxTimer *timer)
{
    VfxU32 curr_time;

    if (m_state == SNDREC_STATE_PLAY && !m_is_slider_pressed)
    {
        if(vadp_soundrec_get_current_time(&curr_time))
        {
            m_current_time = curr_time;
            updateCurrentTime();

            if(m_current_time > m_duration)
            {
                m_duration = m_current_time;
                updateDuration();
            }
        }
    }
}

void VappSoundRecorderPlayPage::onPlayNextTimerExpir(VfxTimer *timer)
{
    playOpen();
    if((SNDREC_STATE_PLAY == m_prev_state) && (SNDREC_STATE_STOP == m_state))
    {
        playStart();
    }
}

void VappSoundRecorderPlayPage::onEOFTimerExpir(VfxTimer *timer)
{
    playStop();
    playClose();

    /* Start a short timer to stop and close, so update prev state if rename keep prev state */
    m_prev_state = m_state;

    /* reset screen state */
    m_current_time = 0;
    updateCurrentTime();
}

void VappSoundRecorderPlayPage::onSeekTimerExpir(VfxTimer *timer)
{
	seekStart();
}

void VappSoundRecorderPlayPage::createScreenComponent(void)
{
    /* Create tool bar */
    if(PLAYBACK_MODE_APP == m_mode)
    {
        VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
        toolbar->addItem(SNDREC_BTN_TOOL_NEW_RECORD, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_NEW_RECORD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD_FILE);
        toolbar->addItem(SNDREC_BTN_TOOL_DELETE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        toolbar->addItem(SNDREC_BTN_TOOL_RENAME, VFX_WSTR_RES(STR_GLOBAL_RENAME), VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
	
	#ifdef __MMI_SET_AS_RINGTONE_POPUP__
        toolbar->addItem(SNDREC_BTN_TOOL_SET_AS, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SET_AS_RINGTONE), VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD);
	#endif
        toolbar->addItem(SNDREC_BTN_TOOL_SHARE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SHARE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
        toolbar->m_signalButtonTap.connect(this, &VappSoundRecorderPlayPage::onAppToolbarButtonClicked);
        setBottomBar(toolbar);
    }
#ifdef __MMI_SOUNDREC_CUI__        
    else
    {
        VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
        toolbar->addItem(SNDREC_BTN_TOOL_RE_RECORD, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RE_RECORD), VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD_FILE);
        toolbar->addItem(SNDREC_BTN_TOOL_INSERT, VFX_WSTR_RES(VCP_STR_TOOL_BAR_INSERT), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSERT);
        toolbar->addItem(SNDREC_BTN_TOOL_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        toolbar->m_signalButtonTap.connect(this, &VappSoundRecorderPlayPage::onCuiToolbarButtonClicked);
        setBottomBar(toolbar);    
    }
#endif
	toolbar->setIsDisabled(VFX_FALSE);

    /*---------------------------- Load components from XML - BEGIN --------------------------------*/
    /* Create common page loader */
    VfxXmlLoader *loader;
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    loader->loadXml(VAPP_SOUNDREC_LAYOUT_COMMON_PAGE);

    /* Draw background image */
    VfxImageFrame *m_image_bg;
    m_image_bg = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("background")), VfxImageFrame);
    m_image_bg->setResId(IMG_ID_VAPP_SNDREC_BACKGROUND);
    m_image_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_image_bg->setSize(LCD_WIDTH, m_image_bg->getSize().height);

    /* Draw tape background image */
    VfxImageFrame *m_image_tape_bg;
    m_image_tape_bg = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("cassette_background")), VfxImageFrame);
    VfxSize tempSize = m_image_tape_bg->getSize();
    m_image_tape_bg->setResId(IMG_ID_VAPP_SNDREC_TAPE_BACKGROUND);
    m_image_tape_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_image_tape_bg->setSize(tempSize);

    /*Create cassette */
    VfxControl *tempControlObj;
    tempControlObj = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("cassette_frame")), VfxControl);
    m_cassette_pos = tempControlObj->getPos();
    VFX_OBJ_CLOSE(tempControlObj);

    VFX_OBJ_CREATE(m_frame_cassette, VappSoundRecorderCassetteFrame, this);
    m_frame_cassette->setPos(m_cassette_pos);
    m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr( const_cast<VfxWChar *>(m_filepath.getBuf()) )));
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
	m_frame_cassette->m_signalGestureRecognized.connect(this, &VappSoundRecorderPlayPage::onGesture);
#endif

    /* Close loader */
    VFX_OBJ_CLOSE(loader);

    /* Create play page loader */
    VFX_OBJ_CREATE(loader, VfxXmlLoader, this);
    loader->loadXml(VAPP_SOUNDREC_LAYOUT_PLAY_PAGE);

    /* Create current time text */
    m_text_current_time = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("current_time")), VfxTextFrame);
    m_text_current_time->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_text_current_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_PLAY_LARGE)));

    /* Create total duration text */
    m_text_duration = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("duration_time")), VfxTextFrame);
    m_text_duration->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_text_duration->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_PLAY_SMALL)));

	/*Create total text frame > 100*/
    VFX_OBJ_CREATE(m_text_total_time, VfxTextFrame, this);
	m_text_total_time->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_text_total_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_PLAY_SLASH)));
	m_text_total_time->setHidden(VFX_TRUE);
	m_text_total_time->setAnchor(0.5, 0.0);
    VfxPoint tempPos = m_text_duration->getPos();
    m_text_total_time->setPos(GDI_LCD_WIDTH/2, tempPos.y);
	
    /* Create slash text */
    m_text_slash = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("slash")), VfxTextFrame);
    m_text_slash->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_text_slash->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SNDREC_FONT_PLAY_SLASH)));

#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_240X400__))

    VfxS16 w1 = m_text_current_time->getSize().width ;
    VfxS16 w2 = m_text_slash->getSize().width ;
    VfxS16 w3 = m_text_duration->getSize().width ;
    VfxS16 W = (w1 + w2 + w3)/2 + VappSoundRecorderPlayPage::TEXT_X_GAP;

	//kal_prompt_trace(MOD_MMI_MEDIA_APP, "[SOUNDREC]w1=%d, w2=%d, w3=%d ", w1, w2, w3);

	//#if (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_240X400__))

	VfxS16 w1_x = GDI_LCD_WIDTH/2 - W;
    VfxS16 w2_x = w1_x + w1 + VappSoundRecorderPlayPage::TEXT_X_GAP;
    VfxS16 w3_x = w2_x + w2 + VappSoundRecorderPlayPage::TEXT_X_GAP;

	tempPos = m_text_current_time->getPos();
	m_text_current_time->setPos(w1_x, tempPos.y);

	tempPos = m_text_slash->getPos();
    m_text_slash->setPos(w2_x, tempPos.y);

	tempPos = m_text_duration->getPos();
	m_text_duration->setPos(w3_x, tempPos.y);
	
#endif

    /* Create play button */
    m_image_btn_play = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_play")), VcpButton);
    m_image_btn_play->setId(SNDREC_BTN_PLAY);
	m_image_btn_play->setMargin(0,0,0,0);
	m_image_btn_play->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PLAY,IMG_ID_VAPP_SNDREC_BTN_PLAY,0,0));
	m_image_btn_play->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG1_N,IMG_ID_VAPP_SNDREC_BTN_BG1_P,0,0));
	m_image_btn_play->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_image_btn_play->m_signalClicked.connect(this, &VappSoundRecorderPlayPage::onButtonClicked);

    /* Create prev button */
    m_image_btn_prev = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_prev")), VcpButton);
	m_image_btn_prev->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PRE,IMG_ID_VAPP_SNDREC_BTN_PRE,IMG_ID_VAPP_SNDREC_BTN_PRE_D,0));
	m_image_btn_prev->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG2_N,IMG_ID_VAPP_SNDREC_BTN_BG2_P,IMG_ID_VAPP_SNDREC_BTN_BG2_N,0));
	m_image_btn_prev->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_image_btn_prev->setId(SNDREC_BTN_PREV);
	m_image_btn_prev->setMargin(0,0,0,0);
	m_image_btn_prev->m_signalClicked.connect(this, &VappSoundRecorderPlayPage::onButtonClicked);

    /* Create next button */
    m_image_btn_next = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("btn_next")), VcpButton);
	m_image_btn_next->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_NEXT,IMG_ID_VAPP_SNDREC_BTN_NEXT,IMG_ID_VAPP_SNDREC_BTN_NEXT_D,0));
	m_image_btn_next->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG2_N,IMG_ID_VAPP_SNDREC_BTN_BG2_P,IMG_ID_VAPP_SNDREC_BTN_BG2_N,0));
	m_image_btn_next->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_image_btn_next->setId(SNDREC_BTN_NEXT);
	m_image_btn_next->setMargin(0,0,0,0);
    m_image_btn_next->m_signalClicked.connect(this, &VappSoundRecorderPlayPage::onButtonClicked);

    if(PLAYBACK_MODE_APP == m_mode)
    {
        if(m_file_list != NULL)
        {
            if(m_file_list->isFirstFile())
            {
                m_image_btn_prev->setIsDisabled(VFX_TRUE);
            }
            if(m_file_list->isLastFile())
            {
                m_image_btn_next->setIsDisabled(VFX_TRUE);
            }
        }
    }
#ifdef __MMI_SOUNDREC_CUI__        
    else
    {
        m_image_btn_prev->setIsDisabled(VFX_TRUE);
        m_image_btn_next->setIsDisabled(VFX_TRUE);
    }
#endif

    /* Create slider progress bar */
    m_slider_progress = VFX_OBJ_DYNAMIC_CAST(loader->findObj(VFX_WSTR("progress_bar")), VcpSlider);
    m_slider_progress->m_signalThumbPressed.connect(this, &VappSoundRecorderPlayPage::onSliderPressed);
    m_slider_progress->m_signalThumbDrag.connect(this, &VappSoundRecorderPlayPage::onSliderValueChange);    
    m_slider_progress->m_signalThumbReleased.connect(this, &VappSoundRecorderPlayPage::onSliderReleased);

    /* Close loader */
    VFX_OBJ_CLOSE(loader);
    /*---------------------------- Load components from XML - END ----------------------------------*/

    /* Create update screen timer */
    VFX_OBJ_CREATE(m_timer_update, VfxTimer, this);
    m_timer_update->setStartDelay(0);   /* Infinite repeat */
    m_timer_update->m_signalTick.connect(this, &VappSoundRecorderPlayPage::onUpdateTimerExpir);

    /* Create play next delay timer */
    VFX_OBJ_CREATE(m_timer_play_next, VfxTimer, this);
    m_timer_play_next->setStartDelay(TIMER_PLAY_NEXT); /* Repeate Once */
    m_timer_play_next->m_signalTick.connect(this, &VappSoundRecorderPlayPage::onPlayNextTimerExpir);

    /* Create play next delay timer */
    VFX_OBJ_CREATE(m_timer_eof, VfxTimer, this);
    m_timer_eof->setStartDelay(TIMER_EOF); /* Repeate Once */
    m_timer_eof->m_signalTick.connect(this, &VappSoundRecorderPlayPage::onEOFTimerExpir);

	/* Create seek loading timer */
	VFX_OBJ_CREATE(m_timer_seek, VfxTimer, this);
    m_timer_seek->setStartDelay(250);
    m_timer_seek->m_signalTick.connect(this, &VappSoundRecorderPlayPage::onSeekTimerExpir);
	
    /* Create update screen timer */
    VFX_OBJ_CREATE(m_timer_play_manager, VfxTimer, this);
    m_timer_play_manager->setStartDelay(1);   /* Infinite repeat */
	m_timer_play_manager->m_signalTick.connect(this, &VappSoundRecorderPlayPage::playResume);

    /* Create update screen timer */
    VFX_OBJ_CREATE(m_timer_pause_manager, VfxTimer, this);
    m_timer_pause_manager->setStartDelay(1);   /* Infinite repeat */
	m_timer_pause_manager->m_signalTick.connect(this, &VappSoundRecorderPlayPage::playPause);

	/* Create resume update time 0 timer */
	VFX_OBJ_CREATE(m_timer_endfile_time_update, VfxTimer, this);
	m_timer_endfile_time_update->setStartDelay(0);
	m_timer_endfile_time_update->m_signalTick.connect(this, &VappSoundRecorderPlayPage::updateEndTime);
}


void VappSoundRecorderPlayPage::updatePlayButtonState(VfxBool show_pause)
{
    if(show_pause)
    {
		m_image_btn_play->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PAUSE,IMG_ID_VAPP_SNDREC_BTN_PAUSE,0,0));
    }
    else
    {
		m_image_btn_play->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PLAY,IMG_ID_VAPP_SNDREC_BTN_PLAY,0,0));
    }
}

void VappSoundRecorderPlayPage::updateTimeText(VfxTextFrame *text, VfxU64 display_time)
{
    VfxWChar str_buf[12];
    VfxU32 hour, minute, second;

    display_time = display_time / 1000;

    hour = display_time / 3600;
    minute = (display_time %3600)/60;
    second = (display_time %3600)%60;

	if(hour >= m_display_hour)
	{
        VfxWString temp_str;
        temp_str.loadFromRes(STR_ID_VAPP_SNDREC_PLAY_TIME);
        temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER);
        temp_str += VfxWString().format(" %d ", hour);
        temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_HOURS);
		text->setString(temp_str);
    }
	else
	{
		kal_wsprintf(str_buf, "%02d:%02d:%02d", hour, minute, second);
    	text->setString(VFX_WSTR_MEM(str_buf));
	}
}

void VappSoundRecorderPlayPage::updateEndTime(VfxTimer *timer)
{
	updateCurrentTime();
}

void VappSoundRecorderPlayPage::updateCurrentTime(void)
{
    updateTimeText(m_text_current_time, m_current_time);

    m_slider_progress->setCurrentValue(m_current_time);
    m_frame_cassette->setCurrentTime(m_current_time);
}

void VappSoundRecorderPlayPage::updateDuration(void)
{
	VfxU32 hour;
	VfxU64 display_time;

    display_time = m_duration / 1000;
    hour = display_time / 3600;
	
	if(hour >= m_display_hour)
	{
		m_text_duration->setHidden(VFX_TRUE);
		m_text_current_time->setHidden(VFX_TRUE);
		m_text_slash->setHidden(VFX_TRUE);
		m_text_total_time->setHidden(VFX_FALSE);
		
		updateTimeText(m_text_total_time, m_duration);
	}
	else
	{
		m_text_duration->setHidden(VFX_FALSE);
		m_text_current_time->setHidden(VFX_FALSE);
		m_text_slash->setHidden(VFX_FALSE);
		m_text_total_time->setHidden(VFX_TRUE);
		
		updateTimeText(m_text_duration, m_duration);
	}
	m_slider_progress->setMaxValue(m_duration);
    m_frame_cassette->setTotalTime(m_duration);
}

void VappSoundRecorderPlayPage::showChangeTapeAnimate(void)
{
    m_frame_cassette->startMoveOut(m_is_next);


    /*Create cassette and init display name */
    VFX_OBJ_CREATE(m_frame_cassette, VappSoundRecorderCassetteFrame, this);
    m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr( const_cast<VfxWChar *>(m_filepath.getBuf()) )));
#ifndef __MMI_SOUNDREC_GESTURE_CUT_DOWN__
    m_frame_cassette->m_signalGestureRecognized.connect(this, &VappSoundRecorderPlayPage::onGesture);
#endif
    m_frame_cassette->setPos(m_cassette_pos);

    if(m_is_next)
    {
        m_frame_cassette->startMoveIn(LCD_WIDTH*2);
    }
    else
    {
        m_frame_cassette->startMoveIn(-LCD_WIDTH);
    }
}

void VappSoundRecorderPlayPage::playReq(void)
{
    if(m_state == SNDREC_STATE_IDLE)
    {
        playOpen();
        /* Open success */
        if(SNDREC_STATE_STOP == m_state)
        {
            playStart();
        }
    }
    else if(m_state == SNDREC_STATE_STOP)
    {
        playStart();
    }
    else if(m_state == SNDREC_STATE_PLAY)
    {
    	updatePlayButtonState(VFX_FALSE);
		m_timer_update->stop();
        m_timer_pause_manager->start();
    }
    else if(m_state == SNDREC_STATE_PAUSE)
    {
	    updatePlayButtonState(VFX_TRUE);
		m_timer_update->start();
		m_timer_play_manager->start();
    }
}

void VappSoundRecorderPlayPage::playCallbackHdlr(kal_int32 result)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_PLAYPAGE_PLAYCALLBACK, result);

    switch (result)
    {
        case MDI_AUDIO_END_OF_FILE:
			m_timer_update->stop();
            m_current_time = m_duration;
            updateCurrentTime();
            m_timer_eof->start();
            break;

        case MDI_AUDIO_TERMINATED:
			
			if(m_seek_state == SNDREC_SEEK_SEEKING)
			{
				m_reset_seek_state = VFX_TRUE;
			}
            playStop();
            playClose();
            /* Do not resume play action after interrupt */
            m_prev_state = SNDREC_STATE_IDLE;

			if(m_reset_seek_state)
			{
				m_seek_state = SNDREC_SEEK_STOP;
				m_prev_state = SNDREC_STATE_PLAY;
			}
			m_reset_seek_state = VFX_FALSE;
            break;

        case MDI_AUDIO_DUR_UPDATED:
            mdi_audio_get_duration( reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filepath.getBuf())),  &m_duration);

            if(m_current_time > m_duration)
            {
                m_duration = m_current_time;
            }
            
            updateDuration();
            break;
		default:
            playStop();
            playClose();		

            /* reset screen state */
            m_current_time = 0;
            updateCurrentTime();

            mmi_event_notify_enum popup_type;
    		mmi_frm_nmgr_balloon(
    			MMI_SCENARIO_ID_DEFAULT,
    			MMI_EVENT_INFO_BALLOON,
    			MMI_NMGR_BALLOON_TYPE_FAILURE,
    			(WCHAR *)VFX_WSTR_RES(mdi_audio_get_error_info(result, &popup_type)).getBuf());
		
            break;
    }
}

void VappSoundRecorderPlayPage::seekCallbackHdlr(kal_int32 result)
{
	stopLoading();
	m_seek_state = SNDREC_SEEK_IDLE;
	m_image_btn_play->setIsDisabled(VFX_FALSE);
	toolbar->setIsDisabled(VFX_FALSE);
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_PLAYPAGE_SEEKCALLBACK, m_prev_state, result);

	if(result != AUD_SEEK_REASON_DONE)
	{
		/* Tap play button can resume seek */
		m_seek_state = SNDREC_SEEK_STOP;
		return;
	}
	
	if(m_prev_state == SNDREC_STATE_PLAY)
	{
		playReq();
	}
}

void VappSoundRecorderPlayPage::playOpen(void)
{
    mdi_result result;
	
	m_image_btn_play->setIsDisabled(VFX_FALSE);
	toolbar->setIsDisabled(VFX_FALSE);

    /* Check if in background call*/
//#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
        return;
    }
//#endif

    /* Terminate background play */
    mdi_audio_terminate_background_play();

    /* Open the file */
    result = vadp_soundrec_open(this, m_filepath.getBuf());
    if(result == MDI_AUDIO_SUCCESS)
    {
        m_state = SNDREC_STATE_STOP;
        
        /* Get duratuin of the file */
        mdi_audio_get_duration( reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filepath.getBuf())),  &m_duration);

        updateDuration();
        m_is_slider_pressed = VFX_FALSE;
    }
    else
    {
        m_duration = 0;
        
        mmi_event_notify_enum popup_type;
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)VFX_WSTR_RES(mdi_audio_get_error_info(result, &popup_type)).getBuf());

        return;
    }
}

void VappSoundRecorderPlayPage::playStart(void)
{
    mdi_result result;
    srv_prof_volume_level volume;

    /* Get volume from sound setting and set to MDI */
    volume = srv_prof_get_media_vol();
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, volume);

    /* Set current time and start to play */
    vadp_soundrec_set_current_time(m_current_time);
    result = vadp_soundrec_play();

    if(result == MDI_AUDIO_END_OF_FILE)
    {
        playStop();

		m_slider_progress->setCurrentValue(m_duration); 		
		m_current_time = 0;
		m_timer_endfile_time_update->start();
        return;
    }
    else if(result != MDI_AUDIO_SUCCESS)
    {
        m_state = SNDREC_STATE_STOP;

        mmi_event_notify_enum popup_type;
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)VFX_WSTR_RES(mdi_audio_get_error_info(result, &popup_type)).getBuf());

        return;
    }

    m_state = SNDREC_STATE_PLAY;

    /* Start timer to update duration */
    VfxU32 interval = 0;
    if(m_duration >= UPDATE_DURATION_NORMAL || m_duration == 0)
    {
        interval = TIMER_UPDATE_DUR_NORMAL;
    }
    else if(m_duration >= UPDATE_DURATION_FAST)
    {
        interval = TIMER_UPDATE_DUR_FAST;
    }
    else if(m_duration > 0)
    {
        interval = TIMER_UPDATE_DUR_FASTEST;
    }

    if(interval > 0)
    {
        m_timer_update->setDuration(interval);
    	m_timer_update->start();
	}

    m_frame_cassette->setCurrentTime(m_current_time);
    m_frame_cassette->startRotate();

    updatePlayButtonState(VFX_TRUE);
}

void VappSoundRecorderPlayPage::playPause(VfxTimer *timer)
{
    mdi_result result;
	
	/*must seek stop first*/
	if(m_seek_state == SNDREC_SEEK_SEEKING)
	{
		seekStop();
	}
    result = vadp_soundrec_pause();

    if(result != MDI_AUDIO_SUCCESS)
    {
        playStop();

        if(MDI_AUDIO_END_OF_FILE == result)
        {
            m_current_time = 0;
            updateCurrentTime();
        }
        return;
    }

    m_state = SNDREC_STATE_PAUSE;

    /* Stop timer update */
    m_frame_cassette->stopRotate();
}

void VappSoundRecorderPlayPage::playResume(VfxTimer *timer)
{
    mdi_result result;

    result = vadp_soundrec_resume();

    if(result != MDI_AUDIO_SUCCESS)
    {
        playStop();

        if(MDI_AUDIO_END_OF_FILE == result)
        {
			m_slider_progress->setCurrentValue(m_duration);			
            m_current_time = 0;
			m_timer_endfile_time_update->start();
        }
		
		m_timer_update->stop();
	    updatePlayButtonState(VFX_FALSE);
		
        return;
    }

    m_state = SNDREC_STATE_PLAY;

    /* Start timer to update duration */
    m_frame_cassette->startRotate();
}

void VappSoundRecorderPlayPage::playStop(void)
{
	/*must seek stop first*/
	if(m_seek_state == SNDREC_SEEK_SEEKING)
	{
		seekStop();
	}
    vadp_soundrec_stop();
    m_state = SNDREC_STATE_STOP;

    /* Stop timer update */
    m_timer_update->stop();
    m_frame_cassette->stopRotate();

    updatePlayButtonState(VFX_FALSE);
}

void VappSoundRecorderPlayPage::playClose(void)
{
    vadp_soundrec_close(this);
    m_state = SNDREC_STATE_IDLE;
	m_seek_state = SNDREC_SEEK_IDLE;
	
	m_image_btn_play->setIsDisabled(VFX_FALSE);
	toolbar->setIsDisabled(VFX_FALSE);

    /* Stop timer update */
    m_timer_update->stop();
    m_frame_cassette->stopRotate();
}

void VappSoundRecorderPlayPage::playNext(void)
{
    WCHAR get_filename[SRV_FMGR_PATH_MAX_LEN+1];

    /* Pick next song */
    if(m_file_list != NULL)
    {
        if(m_file_list->getNextFile(get_filename, (SRV_FMGR_PATH_MAX_LEN+1)*sizeof(WCHAR), m_is_next))
        {
            /* show change tape animation */
            showChangeTapeAnimate();
            
            /* Set file path and display name */    
            m_filepath = VFX_WSTR_MEM(get_filename);
            m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr( const_cast<VfxWChar *>(m_filepath.getBuf()) )));
            m_current_time = 0;
            updateCurrentTime();
            mdi_audio_get_duration( reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filepath.getBuf())),  &m_duration);
            updateDuration();
        }

        /* Enable/Disable prev/next button */
        if(m_file_list->isFirstFile())
        {
            m_image_btn_prev->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_image_btn_prev->setIsDisabled(VFX_FALSE);
        }
        
        if(m_file_list->isLastFile())
        {
            m_image_btn_next->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_image_btn_next->setIsDisabled(VFX_FALSE);
        }
    }

    /* Start a short timer to play next song */
    m_timer_play_next->stop();
    m_timer_play_next->start();    
}

void VappSoundRecorderPlayPage::pickNext(void)
{
    if(m_file_list == NULL)
    {
        return;
    }

    /* If already first or last file do not go prev/next */
    if(m_file_list->isFirstFile() && !m_is_next)
    {
        return;
    }

    if(m_file_list->isLastFile() && m_is_next)
    {
        return;
    }

    /* Stop current playing */
    if(m_state != SNDREC_STATE_IDLE)
    {
        playStop();
        playClose();
    }
    m_current_time = 0;

    if(m_file_list->needReload())
    {
        loadList(VFX_TRUE, VFX_TRUE, VFX_TRUE);
    }
    else
    {
        playNext();
    }
}

void VappSoundRecorderPlayPage::showCurrentFile(VfxBool is_animate)
{
    WCHAR get_filename[SRV_FMGR_PATH_MAX_LEN+1];

    if(m_file_list != NULL)
    {
        if(m_file_list->getCurrentFile(get_filename, (SRV_FMGR_PATH_MAX_LEN+1)*sizeof(WCHAR)))
        {
            /* show change tape animation */
            if(is_animate)
            {
                showChangeTapeAnimate();
            }

            /* Set file path and display name */    
            m_filepath = VFX_WSTR_MEM(get_filename);
            m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr( const_cast<VfxWChar *>(m_filepath.getBuf()) )));
            m_current_time = 0;
            updateCurrentTime();
            mdi_audio_get_duration( reinterpret_cast<void*>(const_cast<VfxWChar*>(m_filepath.getBuf())),  &m_duration);
            updateDuration();        
        }
        else
        {
               getMainScr()->popPage();
        }

        /* Enable/Disable prev/next button */
        if(m_file_list->isFirstFile())
        {
            m_image_btn_prev->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_image_btn_prev->setIsDisabled(VFX_FALSE);
        }
        
        if(m_file_list->isLastFile())
        {
            m_image_btn_next->setIsDisabled(VFX_TRUE);
        }
        else
        {
            m_image_btn_next->setIsDisabled(VFX_FALSE);
        }
    }
}

void VappSoundRecorderPlayPage::loadList(VfxBool need_find_index, VfxBool pick_next, VfxBool is_animate)
{
    if(m_file_list != NULL)
    {
        m_load_find_index = need_find_index;
        m_load_pick_next = pick_next;
        m_load_show_animate = is_animate;
        
    	m_file_list->createList(onListLoadedCallback, getObjHandle());
        showLoading();
    }
}

mmi_ret VappSoundRecorderPlayPage::onListLoadedCallback(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;
	VappSoundRecorderPlayPage *page_obj = (VappSoundRecorderPlayPage*)handleToObject((VfxObjHandle)param->user_data);
	
    if(page_obj != NULL)
    {
        if(page_obj->m_file_list == NULL)
        {
            return MMI_RET_OK;
        }

        /* Call app to update parameter after refresh */
        page_obj->m_file_list->onLoadedCallback(param);
        page_obj->m_playPageListChange.emit();

        switch(param->evt_id)
        {
            case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            {
                if(evt->result < 0)
                {
                    /* Load list error */
                    page_obj->getMainScr()->popPage();
                    break;
                }

                /* If list is empty, exit player */
                if((page_obj->m_file_list != NULL) && (page_obj->m_file_list->getCount() == 0))
                {
                    page_obj->getMainScr()->popPage();
                }
                else
                {
                    /* Find the current file list index from file */
                    if(page_obj->m_load_find_index)
                    {
                        page_obj->findCurrentFileIndex();
                    }
                    
                    /* Stop loading */
                    page_obj->stopLoading();

                    /* Check pick next file after down load or show it directly */
                    if(page_obj->m_load_pick_next)
                    {
                        page_obj->playNext(); 
                    }
                    else
                    {
                        page_obj->showCurrentFile(page_obj->m_load_show_animate);
                    }
                }
            }
                break;
            default:
                break;
        }
    }

    return MMI_RET_OK;
}

void VappSoundRecorderPlayPage::findCurrentFileIndex(void)
{
    /* Set the current file index */
    // TODO: if not find in first round, need to show loading and continue to search
    m_file_list->setCurrentIndexFromFile(srv_fmgr_path_get_filename_ptr(const_cast<VfxWChar*>(m_filepath.getBuf())));
}

void VappSoundRecorderPlayPage::showLoading(void)
{
    /* Show loading */
    if(m_indicator == NULL)
    {
   		MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_PLAYPAGE_SHOW_LOADING);
        VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);

        /* Sets the position and width of indicator bar. */

        m_indicator->setPos(getSize().width / 2, POPUP_Y);
		m_indicator->setAnchor(0.5, 0.5);
		m_indicator->start();
    }
	toolbar->setIsDisabled(VFX_TRUE);
}

void VappSoundRecorderPlayPage::stopLoading(void)
{
    if(m_indicator != NULL)
    {
        VFX_OBJ_CLOSE(m_indicator);
        m_indicator = NULL;
    }
	toolbar->setIsDisabled(VFX_FALSE);
}

void VappSoundRecorderPlayPage::showErrorConfirm(const VfxWString &text, VfxBool exit_page)
{
    VcpConfirmPopup *m_error_popup;
    VFX_OBJ_CREATE(m_error_popup, VcpConfirmPopup, this);

    if(exit_page)
    {
        m_error_popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    }
    else
    {
        m_error_popup->setInfoType(VCP_POPUP_TYPE_INFO);
    }

    m_error_popup->setText(text);
    m_error_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    m_error_popup->show(VFX_TRUE);
    m_error_popup->setAutoDestory(VFX_TRUE);
    if(exit_page)
    {
        m_error_popup->m_signalButtonClicked.connect(this, &VappSoundRecorderPlayPage::onErrorConfirmClicked);
    }
}

void VappSoundRecorderPlayPage::onErrorConfirmClicked(VfxObject* vfx_obj, VfxId id)
{
    getMainScr()->popPage();    
}

void VappSoundRecorderPlayPage::deleteFilePopup(void)
{
    /* Keep current state */
    m_prev_state = m_state;

    /* Stop playing before delete */
    if(m_state == SNDREC_STATE_PLAY)
    {
        playStop();
    }

    /* Show confirm popup */
    VFX_OBJ_CREATE(m_delete_popup, VcpConfirmPopup, this);
    
    m_delete_popup->setInfoType(VCP_POPUP_TYPE_WARNING);

    VfxWString temp_str = VFX_WSTR_RES(STR_GLOBAL_DELETE);
    temp_str += VFX_WSTR(" ");
    temp_str += VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(const_cast<VfxWChar*>(m_filepath.getBuf())));
    temp_str += VFX_WSTR("?");

    m_delete_popup->setText(temp_str);
    m_delete_popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_delete_popup->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE) , VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_delete_popup->m_signalButtonClicked.connect(this, &VappSoundRecorderPlayPage::onDeleteFileClicked);
    m_delete_popup->show(VFX_TRUE);
}

void VappSoundRecorderPlayPage::onDeleteFileClicked(VfxObject* vfx_obj, VfxId id)
{
    VfxS32 file_index;

    if (VCP_CONFIRM_POPUP_BUTTON_USER_1 == id)
    {
        /* Close current file */
        if(m_state != SNDREC_STATE_IDLE)
        {
            playStop();
            playClose();
        }
        m_current_time = 0;

        /* Set file list dirty and refresh later */
        if(m_file_list != NULL)
        {
            file_index = m_file_list->getCurrentIndex();

            /* Set next file index after delete */
            if ((file_index + 1) >= m_file_list->getCount())
            {
                m_file_list->setCurrentIndex((file_index - 1));
                m_is_next = VFX_FALSE;
            }
            else
            {
                m_is_next = VFX_TRUE;
            }
            
            /* Set list dirty and pic next */
        	m_file_list->setDirty();
        }

        /* Delete file */
		VfxS32 ret;

		ret = srv_fmgr_async_delete(m_filepath.getBuf(), 
                        SRV_FMGR_ASYNC_FLAG_PRIORITY_FG | SRV_FMGR_ASYNC_FLAG_NO_PROGRESS,
                        onDeleteFileCallback,
                        getObjHandle());
		
		if(ret < FS_NO_ERROR)
		{
			mmi_frm_nmgr_balloon(
					MMI_SCENARIO_ID_DEFAULT,
					MMI_EVENT_INFO_BALLOON,
					MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR *)VFX_WSTR_RES(srv_fmgr_fs_error_get_string(ret)).getBuf());
		}

		loadList(VFX_FALSE, VFX_FALSE, VFX_TRUE);

    }
    else if(VCP_CONFIRM_POPUP_BUTTON_CANCEL == id || VCP_CONFIRM_POPUP_BUTTON_USER_2 == id)
    {
        if(m_prev_state == SNDREC_STATE_PLAY)
        {
            playReq();
        }
    }

}

mmi_ret VappSoundRecorderPlayPage::onDeleteFileCallback(mmi_event_struct *param)
{
	return MMI_RET_OK;
}
void VappSoundRecorderPlayPage::renameFilePopup(void)
{
    /* Keep current state */
    m_prev_state = m_state;

    /* Stop playing before delete */
    if(m_state == SNDREC_STATE_PLAY)
    {
        playStop();
    }

    /* Display input popup */
    VFX_OBJ_CREATE(m_rename_popup, VappFileNameEditorPopup, this);
    m_rename_popup->setTitle(VFX_WSTR_RES(STR_GLOBAL_RENAME));

    /* Get filename without extension */
    VfxU16 temp_len = m_filepath.getLength();
    VfxWChar *temp_buf;
    VFX_ALLOC_MEM(temp_buf, (temp_len+1)*sizeof(VfxWChar), this);
    kal_wstrncpy(temp_buf, m_filepath.getBuf(), temp_len);
    VfxU16 temp_ext = srv_fmgr_path_get_extension_pos(temp_buf);
    temp_buf[temp_ext-1] = 0;
    m_rename_popup->setText(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(temp_buf)), (SRV_FMGR_PATH_MAX_LEN - VAPP_SNDREC_FOLDER_LEN - 4), VFX_FALSE);
    VFX_FREE_MEM(temp_buf);

    /* Set file extension */
    VfxS8 ext_name[(SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1)*ENCODING_LENGTH];
    kal_wstrncpy(reinterpret_cast<VfxWChar*>(ext_name), srv_fmgr_path_get_extension_const_ptr(m_filepath.getBuf()), SRV_FMGR_PATH_MAX_FILE_EXT_LEN+1);
    m_rename_popup->setExt(ext_name);

    /* Set highlight for whole text */
    m_rename_popup->getInputbox()->setHighlight(0, m_rename_popup->getText().getLength());

    m_rename_popup->setIME(IMM_INPUT_TYPE_SENTENCE);
    m_rename_popup->m_signalButtonClicked.connect(this, &VappSoundRecorderPlayPage::onRenameFileClicked);
    m_rename_popup->show(VFX_TRUE);

}

void VappSoundRecorderPlayPage::onRenameFileClicked(VfxObject* sender, VcpInputPopupButtonEnum id)
{
    switch (id)
    {
        case VCP_INPUT_POPUP_BTN_OK:
            if(m_rename_popup->isValidFilePath() >= FS_NO_ERROR)
            {
                /* Get new file path */
                VfxU16 temp_len = m_filepath.getLength();
                VfxWChar *temp_buf;
                VFX_ALLOC_MEM(temp_buf, (temp_len+1)*sizeof(VfxWChar), this);
                kal_wstrncpy(temp_buf, m_filepath.getBuf(), temp_len);
                VfxWString new_path = VFX_WSTR_MEM(reinterpret_cast<const VfxWChar*>(srv_fmgr_path_remove_filename(temp_buf)));
                VFX_FREE_MEM(temp_buf);
                
                new_path += m_rename_popup->getText();
                new_path += VFX_WSTR(".");
                new_path += VFX_WSTR_MEM(reinterpret_cast<const VfxWChar*>(srv_fmgr_path_get_extension_const_ptr(m_filepath.getBuf())));

                S32 fs_handle;
				if((fs_handle = FS_Open(new_path, FS_READ_ONLY)) >= FS_NO_ERROR)
				{
					if (app_ucs2_strncmp((const kal_int8*)m_filepath.getBuf(), (const kal_int8*)new_path.getBuf(), (SRV_FMGR_PATH_MAX_LEN+1)) == 0)
					{
						/* Filename is the original one */
                        VFX_OBJ_CLOSE(m_rename_popup);
						FS_Close(fs_handle);
						
                        if(m_prev_state == SNDREC_STATE_PLAY)
                        {
                            playReq();
                        }                    
						return;
					}
					
                    /* Check if new name and original name are different with some lower or upper case char */
                    VfxS8 *lw_buff_o = NULL, *lw_buff_n = NULL;
                    VFX_ALLOC_MEM(lw_buff_o, SRV_FMGR_PATH_MAX_LEN, this);
                    memset(lw_buff_o, 0, SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_o, (const kal_int8*)m_filepath.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_o);
                    VFX_ALLOC_MEM(lw_buff_n, SRV_FMGR_PATH_MAX_LEN, this);
                    memset(lw_buff_n, 0, SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strncpy((kal_int8*)lw_buff_n, (const kal_int8*)new_path.getBuf(), SRV_FMGR_PATH_MAX_LEN);
                    app_ucs2_strlwr((kal_int8*)lw_buff_n);

                    if (app_ucs2_strncmp((const kal_int8*)lw_buff_o, (const kal_int8*)lw_buff_n, (SRV_FMGR_PATH_MAX_LEN + 1)) != 0)
					{
						/* Filename is not the original one */
						m_rename_popup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_FILENAME_ALREADY_EXISTS));

						FS_Close(fs_handle);
						VFX_FREE_MEM(lw_buff_o);
                        VFX_FREE_MEM(lw_buff_n);
						return;
					}

                    VFX_FREE_MEM(lw_buff_o);
                    VFX_FREE_MEM(lw_buff_n);
				}
				
				FS_Close(fs_handle);
				
                /* Close current file */
                if(m_state != SNDREC_STATE_IDLE)
                {
                    playStop();
                    playClose();
                }
                m_current_time = 0;
            
                /* Rename file */                
                fs_handle = FS_Rename(m_filepath.getBuf(), new_path.getBuf());
                VFX_OBJ_CLOSE(m_rename_popup);

                if(fs_handle >= FS_NO_ERROR)
                {
                    m_filepath = new_path;
                    m_frame_cassette->setDisplayName(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr( const_cast<VfxWChar *>(m_filepath.getBuf()) )));

                    /* Set file list dirty and reload */
                    if(m_file_list != NULL)
                    {
                        loadList(VFX_FALSE,VFX_FALSE, VFX_FALSE);
                    }
                }
                else
                {
                    mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_FAILURE,
                        (WCHAR *)VFX_WSTR_RES(srv_fmgr_fs_error_get_string(fs_handle)).getBuf());                     
                }
            }
            else
            {
                m_rename_popup->setErrorText(VFX_WSTR_RES(STR_GLOBAL_INVALID_FILENAME));
            }
        
            break;
        case VCP_INPUT_POPUP_BTN_CANCEL:
            VFX_OBJ_CLOSE(m_rename_popup);
            
            if(m_prev_state == SNDREC_STATE_PLAY)
            {
                playReq();
            }        
            break;
        default:
            break;
    }
}

void VappSoundRecorderPlayPage::shareFilePopup(void)
{
        VcpCommandPopup *m_popupMenu;
        VFX_OBJ_CREATE(m_popupMenu, VcpCommandPopup, this);
        m_popupMenu->setText(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SHARE_RECORDING));
        m_popupMenu->setImage(VFX_IMAGE_SRC_NULL);
        m_popupMenu->addItem(OPTION_SHARE_MMS, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SHARE_BY_MMS), VCP_POPUP_BUTTON_TYPE_NORMAL);        
    #ifdef __MMI_EMAIL__
        m_popupMenu->addItem(OPTION_SHARE_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SHARE_BY_EMAIL), VCP_POPUP_BUTTON_TYPE_NORMAL);
    #endif
    #ifdef __MMI_OPP_SUPPORT__
        m_popupMenu->addItem(OPTION_SHARE_BLUETOOTH, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_SHARE_BY_BT), VCP_POPUP_BUTTON_TYPE_NORMAL);
    #endif
        m_popupMenu->addItem(OPTION_MENU_ID_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        m_popupMenu->setAutoDestory(VFX_TRUE);
        m_popupMenu->show(VFX_TRUE);
        m_popupMenu->m_signalButtonClicked.connect(this, &VappSoundRecorderPlayPage::onShareFileClicked);  
}

void VappSoundRecorderPlayPage::onShareFileClicked(VfxObject* sender, VfxId buttonId)
{
    switch(buttonId)
    {
        case OPTION_SHARE_MMS:
            launchUnifiedComposer();
            break;
        case OPTION_SHARE_BLUETOOTH:
            launchBluetooth();
            break;
        case OPTION_SHARE_EMAIL:
            launchEmail();
            break;
        default:
            break;
    }
}

#ifdef __MMI_SET_AS_RINGTONE_POPUP__
void VappSoundRecorderPlayPage::launchSetRingtone(void)
{
    VFX_OBJ_CREATE_EX(m_set_as_ring_tone_popup, VappSetAsRingToneCommandPopup, this, (m_filepath.getBuf()));
    m_set_as_ring_tone_popup->showCommandPopup();
}
#endif

void VappSoundRecorderPlayPage::launchUnifiedComposer(void)
{
    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));

    VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();

    data.app_id = obj->getGroupId();
    data.media_num = 1;
    data.file_path = (VfxU8*)m_filepath.getBuf();
    data.info_type = SRV_UC_INFO_TYPE_MMS;
    
    //vappUcAppLauncher(&data);
    mmi_id cui_id;
    cui_id = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
    if(cui_id != GRP_ID_INVALID)
    {
        vfxSetCuiCallerScr(cui_id, getMainScr());
        vcui_unifiedcomposer_run(cui_id);
    }

}

void VappSoundRecorderPlayPage::launchBluetooth(void)
{
#ifdef __MMI_OPP_SUPPORT__
    vapp_bt_send_app_info app_info;
    memset(&app_info, 0, sizeof(vapp_bt_send_app_info));

    VappSoundRecorderApp *obj = (VappSoundRecorderApp*)getApp();
    
    app_info.group_id = obj->getGroupId();

    VfxWChar* wArray[1] = {0};
    wArray[0] = (VfxWChar*)m_filepath.getBuf();
    
    vapp_bt_send_obj(
                &app_info, 
                VAPP_BT_SEND_NONE, 
                1, 
                (WCHAR**)wArray);
#endif /*__MMI_OPP_SUPPORT__*/
}

void VappSoundRecorderPlayPage::launchEmail(void)
{
#ifdef __MMI_EMAIL__
    mmi_email_app_send_attch((const CHAR*)m_filepath.getBuf());
#endif
}

