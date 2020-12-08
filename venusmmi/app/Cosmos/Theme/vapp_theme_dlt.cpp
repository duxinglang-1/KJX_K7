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
 *  vapp_theme_dlt.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Downloadable theme support
 *	dlt theme from phone and card are merge sorted togther, 
 *	the actived theme file will be listed at first postion
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#include "MMIDataType.h"
#include "CustVenusThemeRes.h"
#include "GlobalResDef.h"
#include "nvram_common_defs.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "fs_type.h"

#include "FileMgrSrvGprot.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_theme_def.h"
#include "vfx_app_launcher.h"
#include "vcp_confirm_popup.h"
#include "vapp_theme_dlt.h"

extern "C"
{
#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define JOB_FLAG(_folder) (1 << (_folder))

/***************************************************************************** 
 * VappThemeDltCntx
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappThemeDltCntx);

VfxWChar VappThemeDltCntx::s_buff[NVRAM_EF_DLT_THEME_SIZE];
VappThemeDltCntx::VappThemeDltCntx()
{
}

VfxWChar *VappThemeDltCntx::getCachePath(void)
{
	return (VfxWChar *)L"Z:\\@Settings\\ThemeCache.med"; 
}
VfxWChar *VappThemeDltCntx::getCacheBackupPath(void)
{
	return (VfxWChar *)L"Z:\\@Settings\\ThemeCacheB.med";
}
VfxS16 VappThemeDltCntx::active(const VfxWChar *path)
{
	deactive();
	
	return (VfxS16)mmi_res_set_dlt_theme(path);
}

void VappThemeDltCntx::getActivePath(VfxWChar *path, VfxS32 size)
{
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("tga", SA_start);
#endif
	if (VappThemeDltCntx::s_buff[0] == 0 && VappThemeDltCntx::s_buff[1] == 0)
	{
		VfxS16 errCode;
		ReadRecord(NVRAM_EF_DLT_THEME_LID, 1, path, NVRAM_EF_DLT_THEME_SIZE, &errCode);

		vfx_sys_wcscpy(VappThemeDltCntx::s_buff, path);
	}
	else
	{
		vfx_sys_wcscpy(path, VappThemeDltCntx::s_buff);
	}
	
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("tga", SA_stop);
#endif
}

void VappThemeDltCntx::setActivePath(const VfxWChar *path, VfxS32 size)
{
	VfxS16 errCode;
	WriteRecord(NVRAM_EF_DLT_THEME_LID, 1, (void *)path, NVRAM_EF_DLT_THEME_SIZE, &errCode);

	vfx_sys_wcscpy(VappThemeDltCntx::s_buff, path);

	setIsDltActive(VFX_TRUE);
}

/***************************************************************************** 
 * VappThemeDltData
 *****************************************************************************/
VfxBool VappThemeDltData::isActivatedFile(VappThemeDltCntx *cntx, const VfxWChar *path)
{
	VfxWChar *buffer;

	VfxBool bActivated = VFX_FALSE;
	
	buffer = (VfxWChar *)OslMalloc(sizeof(VfxWChar) *SRV_FMGR_PATH_BUFFER_SIZE);
	if (getActiveThemePath(cntx, buffer, NVRAM_EF_DLT_THEME_SIZE))
	{
		if (vfx_sys_wcscmp(path, buffer) == 0)
		{
			bActivated = VFX_TRUE;
		}
	}
	OslMfree(buffer);

	return bActivated;
}

VfxBool VappThemeDltData::activeDltCache(VappThemeDltCntx *cntx, const VfxWChar *path)
{
	VfxS32 fsRet = srv_fmgr_fs_path_exist(path);
	if (fsRet < 0)
	{
		/*
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)GetString(srv_fmgr_fs_error_get_string(fsRet))); */
		MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_ACTIVE_FAIL, fsRet);
		
		return VFX_FALSE;
	}

	cntx->deactive();

	//
	// Slim project hasn't system driver, so activate it directly.
	//
#ifndef __LOW_COST_SUPPORT_COMMON__
	// always active dlt theme from cache.
	if (path != cntx->getCachePath())
	{
		fsRet = srv_fmgr_fs_copy(path, cntx->getCacheBackupPath());
		if (fsRet != FS_NO_ERROR)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				(WCHAR *)GetString(srv_fmgr_fs_error_get_string(fsRet)));
			
			return VFX_FALSE;
		}

		fsRet = srv_fmgr_fs_delete(cntx->getCachePath());
		fsRet = srv_fmgr_fs_move(cntx->getCacheBackupPath(), cntx->getCachePath());
		fsRet = srv_fmgr_fs_delete(cntx->getCacheBackupPath());
	}

	VfxS16 ret = cntx->active(cntx->getCachePath());
	if (ret < 0)
	{
		fsRet = srv_fmgr_fs_delete(cntx->getCachePath());
	}
#else
	VfxS16 ret = cntx->active(path);
#endif
	
	return (ret >= 0 ? VFX_TRUE : VFX_FALSE);
}

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
const VfxResId VappThemeDltData::s_errStr[VappThemeDltData::TOTAL_ERROR] =
{
	STR_GLOBAL_INVALID_FORMAT,
	STR_GLOBAL_NOT_ENOUGH_MEMORY,
	STR_ID_VAPP_THEME_DLT_ERROR_PROJECT,
	STR_ID_VAPP_THEME_DLT_ERROR_VERSION,
	STR_ID_VAPP_THEME_DLT_ERROR_RESOLUTION
};

const VfxS32 VappThemeDltData::s_errCode[VappThemeDltData::TOTAL_ERROR] = 
{
	MMI_RES_THEME_RET_INVALID,
	MMI_RES_THEME_BUF_NOT_ENOUGH,
	MMI_RES_THEME_RET_PROJECT_NOT_MATCH,
	MMI_RES_THEME_RET_VERSION_NOT_MATCH,
	MMI_RES_THEME_RET_RESOLUTION_NOT_MATCH
};


VfxResId VappThemeDltData::getErrRes(const VfxS32 &errCode)
{
	for (VfxS32 i = 0; i < VappThemeDltData::TOTAL_ERROR; i++)
	{
		if (s_errCode[i] == errCode)
		{
			return s_errStr[i];
		}
	}

	return STR_GLOBAL_ERROR;
}

VfxBool VappThemeDltData::initTheme(VappThemeDltCntx *cntx)
{
	VfxBool ret = VFX_FALSE;
	
	if (cntx->isDltActive())
	{
		VfxWChar *buffer = NULL;
	#ifndef __LOW_COST_SUPPORT_COMMON__
		if (activeDltCache(cntx, cntx->getCachePath()))
	#else
		
		VFX_SYS_ALLOC_MEM(buffer, SRV_FMGR_PATH_BUFFER_SIZE);
		if (VappThemeDltData::getActiveThemePath(cntx, buffer, NVRAM_EF_DLT_THEME_SIZE) &&
			activeDltCache(cntx, buffer))
	#endif
		{
			ret = VFX_TRUE;
		}

		VFX_SYS_FREE_MEM(buffer);
	}

	return ret;
}

VappThemeDltData::VappThemeDltData() :
	m_adjustCnt(0),
	m_waitingJob(0),
	m_workingBuffer(NULL),
	m_nameBuffer(NULL),
	m_fileItems(NULL)
{
	m_activeFileItem.handle = 0;
	
	for (VfxU32 i = FOLDER_TOTAL; i != 0; i--)
	{
		m_lstHandle[i - 1] = m_lstFileCnt[i - 1] = 0;
	}

	m_drvList[FOLDER_PHONE] = SRV_FMGR_DRV_PHONE_TYPE;
	m_drvList[FOLDER_CARD] = SRV_FMGR_DRV_CARD_TYPE;
}

void VappThemeDltData::onInit(void)
{
	VappThemeData::onInit();

	VFX_ALLOC_MEM(m_workingBuffer, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE * FOLDER_TOTAL, this);	
	VFX_ALLOC_MEM(m_nameBuffer, SRV_FMGR_PATH_BUFFER_SIZE * sizeof(VfxWChar) * 2, this);
	m_nameBuffer[0] = m_nameBuffer[1] = 0;

	createFolderLst();
	refresh(0);

	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, VappThemeDltData::onProc, getObjHandle());
}

void VappThemeDltData::onDeinit(void)
{
	mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VappThemeDltData::onProc, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappThemeDltData::onProc, getObjHandle());
	
	reset();
	
	VFX_FREE_MEM(m_nameBuffer);
	VFX_FREE_MEM(m_workingBuffer);
	
	VappThemeData::onDeinit();
}

VfxBool VappThemeDltData::isActivated(VfxS32 pos)
{
	VFX_ASSERT((VfxU32)pos < getCount());

	if (!isActive())
	{
		return VFX_FALSE;
	}

	VfxBool bRet = VFX_FALSE;
	// active theme is not in theme folder.
	if (m_fileItems[pos].handle == INVALID_HANDLE)
	{
		return ((pos == 0) ? VFX_TRUE : VFX_FALSE);
	}
	else
	{
		if (srv_fmgr_filelist_get_filepath(
					m_fileItems[pos].handle,
					m_fileItems[pos].index, 
					m_nameBuffer,
					SRV_FMGR_PATH_BUFFER_SIZE) == 0)
		{
			bRet = VappThemeDltData::isActivatedFile(getCntx(), m_nameBuffer);
		}
	}

	return bRet;
}

void VappThemeDltData::genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos)
{
	VFX_ASSERT((VfxU32)pos < getCount());

	VappThemeData::genSwitchDesc(desc, pos);	
	desc.type = VappThemeData::THEME_TYPE_DLT;	
	
	VfxWChar *buffer;
	buffer = (VfxWChar *)OslMalloc(sizeof(VfxWChar) * SRV_FMGR_PATH_BUFFER_SIZE);

	if (getFilePath(buffer, SRV_FMGR_PATH_BUFFER_SIZE, pos))
	{
		desc.u.path = buffer;
	}
	else
	{
		OslMfree(buffer);
	}
}

VfxClassInfo *VappThemeDltData::getCuiClassInfo(void)
{
	return VFX_OBJ_CLASS_INFO(VappThemeDltSwitchCui);
}

VfxWString VappThemeDltData::getFolderName(void)
{
	return VFX_WSTR("Theme");
}

VfxU16 VappThemeDltData::getFiletype(void)
{
	return (VfxU16)FMGR_TYPE_THEME;
}

VappThemeDltCntx *VappThemeDltData::getCntx(void)
{
	return VFX_OBJ_GET_INSTANCE(VappThemeDltCntx);
}

VfxBool VappThemeDltData::isValid(VfxS32 pos)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tvd", SA_start);
#endif

	m_nameBuffer[0] = m_nameBuffer[1] = 0;

	mmi_res_theme_ret_enum ret;
	if (getFilePath(m_nameBuffer, SRV_FMGR_PATH_BUFFER_SIZE, pos))
	{
		ret = mmi_res_is_dlt_theme_valid((const WCHAR *)m_nameBuffer);
	}
	else
	{
		ret = MMI_RES_THEME_RET_INVALID;
	}

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tvd", SA_stop);
#endif

	return (ret >= MMI_RES_THEME_RET_NO_ERROR);
}

void VappThemeDltData::createFolderLst(void)
{
	FMGR_FILTER filter;
	FMGR_FILTER_INIT(&filter);
	FMGR_FILTER_SET(&filter, (filetypes_file_type_enum)getFiletype());

	VfxWString strPath;
	S32 ret;
	
	for (VfxU32 i = 0; i < FOLDER_TOTAL; i++)
	{
		strPath = getPath((srv_fmgr_drv_type_enum)m_drvList[i]);
		ret = srv_fmgr_folder_filelist_create(
					(const WCHAR *)strPath.getBuf(), 
					&filter, 
					FS_SORT_NAME, 
					m_workingBuffer + (i * SRV_FMGR_FOLDER_FILELIST_MEM_SIZE),
					SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
					&m_lstHandle[i]);

		VFX_ASSERT(ret == 0);
	}
}


VfxWString VappThemeDltData::getPath(VfxU16 drv)
{
	VfxWString strPath;
	VfxWChar *path;

	path = (VfxWChar *)srv_fmgr_drv_get_path_by_type((srv_fmgr_drv_type_enum)drv);
	VFX_ASSERT(path != NULL);
	strPath.loadFromMem(path);
	strPath += getFolderName();

	return strPath;
}

void VappThemeDltData::reset(void)
{
	m_activeFileItem.handle = 0;
	
	for (VfxU32 i = FOLDER_TOTAL; i != 0; i--)
	{
		if (m_waitingJob & JOB_FLAG(i - 1))
		{
			srv_fmgr_filelist_abort(m_lstHandle[i - 1]);
		}
		
		srv_fmgr_filelist_destroy(m_lstHandle[i - 1]);

		m_lstHandle[i - 1] = m_lstFileCnt[i - 1] = 0;
	}

	VFX_FREE_MEM(m_fileItems);
	m_adjustCnt = 0;
	m_waitingJob = 0;
}

VfxS32 VappThemeDltData::sortByName(const FileItem *item1, const FileItem *item2)
{
	VfxWChar *buffer1, *buffer2;

	buffer1 = m_nameBuffer;
	buffer2 = m_nameBuffer + (SRV_FMGR_PATH_MAX_FILE_NAME_LEN * sizeof(VfxWChar));

	buffer1[0] = buffer1[1] = 0;
	buffer2[0] = buffer2[1] = 0;
	if (srv_fmgr_filelist_get_filename(item1->handle, item1->index, buffer1, SRV_FMGR_PATH_MAX_FILE_NAME_LEN) == 0)
	{
		if (srv_fmgr_filelist_get_filename(item2->handle, item2->index, buffer2, SRV_FMGR_PATH_MAX_FILE_NAME_LEN) == 0)
		{
			return mmi_ucs2cmp((const CHAR *)buffer1, (const CHAR *)buffer2);
		}
	}

	return 0;
}

VfxS32 VappThemeDltData::sortByTime(const FileItem *item1, const FileItem *item2)
{
	return 0;
}

void VappThemeDltData::mergeSort(cmpFuncPtr cmp)
{
	FileItem *itr = m_fileItems;

	VfxU32 curr[FOLDER_TOTAL];

	// Only support two folders right now
	curr[FOLDER_PHONE] = curr[FOLDER_CARD] = 0;

	FileItem item[FOLDER_TOTAL];
	
	do
	{
		if (curr[FOLDER_PHONE] >= m_lstFileCnt[FOLDER_PHONE] ||
			curr[FOLDER_CARD] >= m_lstFileCnt[FOLDER_CARD])
		{
			break;
		}
	
		item[FOLDER_PHONE].handle = m_lstHandle[FOLDER_PHONE];
		item[FOLDER_PHONE].index = curr[FOLDER_PHONE];

		item[FOLDER_CARD].handle = m_lstHandle[FOLDER_CARD];
		item[FOLDER_CARD].index = curr[FOLDER_CARD];

		if ((this->*cmp)(&item[FOLDER_PHONE], &item[FOLDER_CARD]) <= 0)
		{
			*itr = item[FOLDER_PHONE];
			curr[FOLDER_PHONE]++;
		}
		else
		{
			*itr = item[FOLDER_CARD];
			curr[FOLDER_CARD]++;
		}

		++itr;
	}while(VFX_TRUE);

	// Copy the remaining data.
	for (VfxU32 i = 0; i < FOLDER_TOTAL; i++)
	{
		for (VfxU32 j = curr[i]; j < m_lstFileCnt[i]; j++)
		{
			itr->handle = m_lstHandle[i];
			itr->index = j;

			++itr;
		}
	}
}


VfxS32 VappThemeDltData::getHdlrIndex(const VfxU32 &handle) const
{
	VfxU32 i = 0;
	
	do
	{
		if (handle == m_lstHandle[i])
		{
			return i;
		}
		
	}while (++i < FOLDER_TOTAL);

	return -1;
}

VfxBool VappThemeDltData::isActive(void)
{
	return getCntx()->isDltActive();
}

VfxBool VappThemeDltData::isActiveInThemeFolder(void) const
{
	return (m_activeFileItem.handle != INVALID_HANDLE);
}

VfxBool VappThemeDltData::isActiveThemeFileExit(void)
{
	m_nameBuffer[0] = m_nameBuffer[1] = 0;
	
	return VappThemeDltData::getActiveThemePath(getCntx(), m_nameBuffer, NVRAM_EF_DLT_THEME_SIZE);
}

void VappThemeDltData::refresh(const VfxU32 &curr)
{
	if (curr < FOLDER_TOTAL)
	{
		VfxWChar *pattern = NULL;
		
		if (isActive() && !isActiveInThemeFolder())
		{
			m_nameBuffer[0] = m_nameBuffer[1] = 0;
			if (VappThemeDltData::getActiveThemePath(getCntx(), m_nameBuffer, NVRAM_EF_DLT_THEME_SIZE))
			{
				VfxWString strPath;
				VfxBool isMatch = VFX_FALSE;
				
				for (VfxU32 i = 0; i < FOLDER_TOTAL; i++)
				{
					strPath = getPath((srv_fmgr_drv_type_enum)m_drvList[i]);
					if (strPath.getLength() < vfx_sys_wcslen(m_nameBuffer))
					{
						if (vfx_sys_wcsncmp(strPath.getBuf(), m_nameBuffer, strPath.getLength()) == 0)
						{
							isMatch = VFX_TRUE;
						}
					}
				}

				// If the activated theme file is not in the theme folder, don't pattern it in theme folder
				//	to avoid the issue that there is the same file name in the theme folder
				if (isMatch)
				{
					pattern = srv_fmgr_path_get_filename_ptr(m_nameBuffer);
				}
			}				
		}

		
		VfxS32 ret = srv_fmgr_filelist_refresh(
						m_lstHandle[curr], 
						pattern,
						0,
						0,	// No process event
						VappThemeDltData::onProc, 
						getObjHandle());
		if (ret == 0)
		{
			m_waitingJob |= JOB_FLAG(curr);
		}
	}
}

VfxBool VappThemeDltData::getActiveThemePath(VappThemeDltCntx *cntx, VfxWChar *buffer, VfxU32 size)
{
	if (size < NVRAM_EF_DLT_THEME_SIZE)
	{
		return VFX_FALSE;
	}

	cntx->getActivePath(buffer, size);
	
	if (srv_fmgr_fs_path_exist(buffer) < 0)
	{
		return VFX_FALSE;
	}

	return VFX_TRUE;
}

void VappThemeDltData::checkActiveTheme(void)
{
	if (!isActive())
	{
		return;
	}

	if (isActiveInThemeFolder())
	{
		// Insert the active item to the fist position.
		FileItem *itr = m_fileItems;
		VfxU32 i;
		
		for (i = 0; i < getCount(); i++, itr++)
		{
			if (itr->handle == m_activeFileItem.handle &&
				itr->index == m_activeFileItem.index)
			{
				break;
			}
		}

		for (VfxU32 j = i; j != 0; j--)
		{
			m_fileItems[j] = m_fileItems[j - 1];
		}

		// place the active item at the first index
		m_fileItems[0] = m_activeFileItem;
	}
	else
	{
		if (isActiveThemeFileExit())
		{
			for (VfxU32 i = getCount() - 1; i != 0; i--)
			{
				m_fileItems[i] = m_fileItems[i - 1];
			}

			m_fileItems[0].handle = INVALID_HANDLE;
		}
	}
}

mmi_ret VappThemeDltData::onProc(mmi_event_struct *param)
{
	VappThemeDltData *thiz = (VappThemeDltData *)handleToObject((VfxObjHandle)param->user_data);

	if (thiz != NULL)
	{
		return thiz->onFileMgrProc(param);
	}

	return MMI_RET_OK;
}

mmi_ret VappThemeDltData::onFileMgrProc(mmi_event_struct *param)
{    
    switch(param->evt_id) 
    {
	    case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
        {
			srv_fmgr_filelist_refresh_result_event_struct *evt;
			evt = (srv_fmgr_filelist_refresh_result_event_struct *)param;
			
            if (evt->result >= 0)
            {
            	m_lstFileCnt[getHdlrIndex(evt->handle)] = srv_fmgr_filelist_count(evt->handle);

				// Find the location of actived theme file
				if (evt->search_index >= 0)
				{
					m_activeFileItem.handle = evt->handle;
					m_activeFileItem.index = evt->search_index;
				}
            }

			m_waitingJob &= ~(JOB_FLAG(getHdlrIndex(evt->handle)));

			// next folder
			refresh(getHdlrIndex(evt->handle) + 1);

			if (m_waitingJob == 0)
			{
				if (isActive() && !isActiveInThemeFolder() && isActiveThemeFileExit())
				{
					m_adjustCnt = 1;
				}
				
				VFX_ALLOC_MEM(m_fileItems, sizeof(FileItem) * getCount(), this);
				
				mergeSort(&VappThemeDltData::sortByName);
				checkActiveTheme();
				
				m_signalNeedReset.postEmit(getCount() != 0);
			}			
			
			break;
        }

		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		case EVT_ID_USB_ENTER_MS_MODE:
		case EVT_ID_USB_EXIT_MS_MODE:
		{
			reset();
			m_signalNeedReset.postEmit(getCount() != 0);
			createFolderLst();
			refresh(0);
			break;
		}
		
		default:
			break;
    }

	return MMI_RET_OK;
}

VfxBool VappThemeDltData::getTypeStr(VfxWString &typeName)
{
	VfxResId resId;
	
	if (m_waitingJob != 0)
	{
		resId = STR_ID_VAPP_THEME_LOADING_DLT;
	}
	else
	{
		if (getCount() != 0)
		{
			resId = STR_ID_VAPP_THEME_DLT;
		}
		else
		{
			resId = STR_ID_VAPP_THEME_NO_DLT;
		}		
	}

	typeName.loadFromRes(resId);
	
	return VFX_TRUE;
}


VfxBool VappThemeDltData::activeDltTheme(VappThemeDltCntx *cntx, const VfxWChar *path)
{
	if (activeDltCache(cntx, path))
	{
		cntx->setActivePath(path, NVRAM_EF_DLT_THEME_SIZE);
		
		return VFX_TRUE;
	}

	return VFX_FALSE;
}


VfxU32 VappThemeDltData::getCount(void) const
{
	if (m_waitingJob == 0)
	{
		VfxU32 count = 0;

		for (VfxU32 i = 0; i < FOLDER_TOTAL; i++)
		{
			count += m_lstFileCnt[i];
		}

		return (count + m_adjustCnt);
	}

	return 0;
}

VfxBool VappThemeDltData::getFilePath(VfxWChar *buffer, VfxU32 size, VfxS32 pos)
{
	if (size < SRV_FMGR_PATH_BUFFER_SIZE || buffer == NULL)
	{
		return VFX_FALSE;
	}
	
	VfxBool checkActive = ((pos == 0) && isActive());

	VfxS32 newPos = pos;
	
	if (checkActive && !isActiveInThemeFolder())
	{
		// The active theme file is not in Theme folder.
		if (VappThemeDltData::getActiveThemePath(getCntx(), buffer, NVRAM_EF_DLT_THEME_SIZE))
		{
			return VFX_TRUE;
		}
	}

	VfxS32 fmgrRet = srv_fmgr_filelist_get_filepath(
						m_fileItems[newPos].handle, 
						m_fileItems[newPos].index,
						buffer,
						SRV_FMGR_PATH_BUFFER_SIZE);

	return (fmgrRet == 0);
}


VfxImageSrc VappThemeDltData::getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tpv", SA_start);
#endif

	VfxWChar *path;
	VFX_ALLOC_MEM(path, (SRV_FMGR_PATH_BUFFER_SIZE), this);

	mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;
	if (getFilePath(path, SRV_FMGR_PATH_BUFFER_SIZE, pos) && (buffer != NULL))
	{
		ret = mmi_res_get_dlt_theme_preview((const WCHAR *)path, (S8 *)buffer, size);
	}

	VFX_FREE_MEM(path);
	
	VfxImageSrc imgSrc;
	
	if (ret == MMI_RES_THEME_RET_NO_ERROR)
	{
		imgSrc.setMem(buffer);
	}
	else
	{
		imgSrc.setResId(IMG_ID_VAPP_THEME_INVALID);
	}

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tpv", SA_stop);
#endif
	
	return imgSrc;
}


VfxImageSrc VappThemeDltData::getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tpt", SA_start);
#endif

	VFX_ASSERT(pos >= 0);

	m_nameBuffer[0] = m_nameBuffer[1] = 0;

	VfxImageSrc imgSrc;
	mmi_res_theme_ret_enum ret = MMI_RES_THEME_RET_INVALID;
	
	if (getFilePath(m_nameBuffer, SRV_FMGR_PATH_BUFFER_SIZE, pos) && (buffer != NULL))
	{
		// image buffer has the same life cycle with item, so buffer should be from list item.
		ret = mmi_res_get_dlt_theme_thumbnail((const WCHAR *)m_nameBuffer, (S8 *)buffer, size);
	}	

	if (ret == MMI_RES_THEME_RET_NO_ERROR)
	{
		imgSrc.setMem(buffer);
	}
	else
	{
		imgSrc.setResId(IMG_ID_VAPP_THEME_DLT_DEFAULT_THUMBNAIL);
	}

#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("tpt", SA_stop);
#endif

	return imgSrc;
}


VfxWString VappThemeDltData::getText(VfxS32 pos)
{
	VFX_ASSERT(pos >= 0);

	VfxWChar *buffer;
	
	m_nameBuffer[0] = m_nameBuffer[1] = 0;

	if (getFilePath(m_nameBuffer, SRV_FMGR_PATH_BUFFER_SIZE, pos))
	{
		buffer = srv_fmgr_path_get_filename_ptr(m_nameBuffer);
	}
	else
	{
		buffer = NULL;
	}

	if (buffer != NULL)
	{
		VfxWChar *extPos = srv_fmgr_path_get_extension_ptr(buffer);
		*(extPos - 1) = 0;
	}
	
	return VFX_WSTR_MEM(buffer);	
}


/***************************************************************************** 
 * Class VappThemeDltSwitchCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeDltSwitchCui", VappThemeDltSwitchCui, VappThemeSwitchCui);
void VappThemeDltSwitchCui::onInit(void)
{
	VappThemeSwitchCui::onInit();

	registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
	registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
}

void VappThemeDltSwitchCui::onDeinit(void)
{
	registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
	registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);

	//VFX_SYS_FREE_MEM(m_switchDesc.u.path);
	if (m_switchDesc.u.path != NULL)
	{
		OslMfree(m_switchDesc.u.path);
	}
	
	VappThemeSwitchCui::onDeinit();
}

mmi_ret VappThemeDltSwitchCui::onProc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT ||
		evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
	{
		exit();

		return MMI_RET_OK;
	}

	return VappThemeSwitchCui::onProc(evt);
}

VfxBool VappThemeDltSwitchCui::active(void)
{
	return VappThemeDltData::activeDltTheme(getCntx(), m_switchDesc.u.path);
}

VappThemeDltCntx *VappThemeDltSwitchCui::getCntx()
{
	return VFX_OBJ_GET_INSTANCE(VappThemeDltCntx);
}

VfxS32 VappThemeDltSwitchCui::checkValid(void)
{
	mmi_res_theme_ret_enum ret = mmi_res_is_dlt_theme_valid((const WCHAR *)m_switchDesc.u.path);
	
	return (VfxS32)ret;
}

/***************************************************************************** 
 * Helper Function
 *****************************************************************************/
void vapp_theme_fmgr_check_hdlr(const WCHAR* filepath, 
										VappThemeDltCntx *cntx,
										VfxClassInfo *switchClsInfo,
										VappThemeSwitchDesc &desc)
{
	if (cntx->isDltActive() &&
		VappThemeDltData::isActivatedFile(cntx, (const VfxWChar *)filepath))
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)GetString(STR_GLOBAL_ACTIVATED));
		
		return;
	}
	
	//VFX_SYS_ALLOC_MEM(desc.u.path, SRV_FMGR_PATH_BUFFER_SIZE);
	desc.u.path = (VfxWChar *)OslMalloc(sizeof(VfxWChar) * SRV_FMGR_PATH_BUFFER_SIZE);
	vfx_sys_wcscpy(desc.u.path, filepath);
	
	mmi_id curId = VfxAppLauncher::launch(
		VCUI_THEME_SWITCH,
		switchClsInfo,
		GRP_ID_ROOT,
		&desc,
		sizeof(VappThemeSwitchDesc));

}

mmi_ret vapp_theme_fmgr_evt_hdlr(mmi_event_struct *evt, VappThemeDltCntx *cntx)
{
    srv_fmgr_notification_adv_action_event_struct *adv_action;

	adv_action = (srv_fmgr_notification_adv_action_event_struct*)evt;

	VfxWChar *buffer = NULL;
	if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_QUERY &&
	   adv_action->action != SRV_FMGR_NOTIFICATION_ACTION_COPY)
	{
		if (!cntx->isDltActive())
		{
			return MMI_RET_OK;
		}
		
		//VFX_SYS_ALLOC_MEM(buffer, SRV_FMGR_PATH_BUFFER_SIZE);
		buffer = (VfxWChar *)OslMalloc(sizeof(VfxWChar) * SRV_FMGR_PATH_BUFFER_SIZE);

		VfxBool bRet = VappThemeDltData::getActiveThemePath(cntx, buffer, SRV_FMGR_PATH_BUFFER_SIZE);
		if (!bRet)
		{
			OslMfree(buffer);			
			return MMI_RET_OK;
		}

		// rename or delete file
		if(!(adv_action->src_fileinfo.attribute & FS_ATTR_DIR))
		{
			if (vfx_sys_wcscmp((VfxWChar *)adv_action->src_filepath, buffer) == 0)
			{
				OslMfree(buffer);
				return MMI_RET_ERR;
			}
		}
		// rename or delete the folder
		else
		{			
			if (vfx_sys_wcsncmp((VfxWChar *)adv_action->src_filepath,
								 buffer, 
								 vfx_sys_wcslen((VfxWChar *)adv_action->src_filepath)) == 0)
			{
				OslMfree(buffer);
				return MMI_RET_ERR;
			}
		}
		OslMfree(buffer);
	}

	return MMI_RET_OK;
}

extern "C" 
void vapp_theme_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
}

extern "C" 
void vapp_theme_fmgr_use_handler(mmi_menu_id item_id, 
										  const WCHAR* filepath, 
										  const srv_fmgr_fileinfo_struct* fileinfo)
{
	VappThemeSwitchDesc desc;
	desc.initRes();	
	desc.type = VappThemeData::THEME_TYPE_DLT;

	vapp_theme_fmgr_check_hdlr(
		filepath, 
		VFX_OBJ_GET_INSTANCE(VappThemeDltCntx),
		VFX_OBJ_CLASS_INFO(VappThemeDltSwitchCui),
		desc);
}

extern "C"
mmi_ret vapp_theme_evt_handlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
		case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
			return vapp_theme_fmgr_evt_hdlr(evt, VFX_OBJ_GET_INSTANCE(VappThemeDltCntx));
			
		default:
			break;
    }
	
    return MMI_RET_OK;
}

