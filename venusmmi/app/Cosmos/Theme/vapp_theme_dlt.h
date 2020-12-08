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
 *  vapp_theme_dlt.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Support downloadable theme
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VAPP_THEME_DLT_H__
#define __VAPP_THEME_DLT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "nvram_common_defs.h"
}
#include "vfx_datatype.h"

#include "vapp_theme.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * VappThemeDltCntx
 *****************************************************************************/
class VappThemeDltCntx : public VappThemeCntx
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VappThemeDltCntx);
	
protected:
	VappThemeDltCntx();

// Overridable
public:
	virtual VfxWChar *getCachePath(void);
	virtual VfxWChar *getCacheBackupPath(void);
	virtual VfxS16 active(const VfxWChar *path);
	virtual VfxS16 active(VfxU32 index){ return -1; }
	virtual void getActivePath(VfxWChar *path, VfxS32 size);
	virtual void setActivePath(const VfxWChar *path, VfxS32 size);

private:
	static VfxWChar s_buff[NVRAM_EF_DLT_THEME_SIZE];
};


/***************************************************************************** 
 * Class VappThemeDltData
 *****************************************************************************/
class VappThemeDltData : public VappThemeData
{
public:
	VappThemeDltData();
	
	VfxBool getTypeStr(VfxWString &typeName);
	VfxU32 getCount(void) const;	
	VfxImageSrc getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	VfxImageSrc getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	VfxWString getText(VfxS32 pos);
	VfxBool isActivated(VfxS32 pos);

	mmi_ret onFileMgrProc(mmi_event_struct *param);
	virtual VfxClassInfo *getCuiClassInfo(void);
	
	static mmi_ret onProc(mmi_event_struct *param);
	static VfxBool activeDltTheme(VappThemeDltCntx *cntx, const VfxWChar *path);
	static VfxBool activeDltCache(VappThemeDltCntx *cntx, const VfxWChar *path);
	static VfxBool getActiveThemePath(VappThemeDltCntx *cntx, VfxWChar *buffer, VfxU32 size);
	static VfxBool initTheme(VappThemeDltCntx *cntx);
	static VfxResId getErrRes(const VfxS32 &errCode);
	static VfxBool isActivatedFile(VappThemeDltCntx *cntx, const VfxWChar *path);
	
	typedef struct
	{
		VfxU32 handle;
		VfxU32 index;
	}FileItem;

	enum
	{
		IMG_BUFFER_LEN = 4095,
		TOTAL_ERROR = 5
	};
	
	typedef  VfxS32 (VappThemeDltData::*cmpFuncPtr)(const FileItem *, const FileItem *);

// Override
protected:
	void onInit(void);
	void onDeinit(void);
	virtual void genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos);
	virtual VfxWString getFolderName(void);
	virtual VfxU16 getFiletype(void);
	virtual VappThemeDltCntx *getCntx(void);
	virtual VfxBool isValid(VfxS32 pos);
	
private:
	
	void createFolderLst(void);
	void reset(void);
	VfxS32 getHdlrIndex(const VfxU32 &handle) const;
	void mergeSort(cmpFuncPtr cmp);
	void refresh(const VfxU32 &curr);
	VfxS32 sortByName(const FileItem *item1, const FileItem *item2);
	VfxS32 sortByTime(const FileItem *item1, const FileItem *item2);
	VfxBool isValidItem(const FileItem *item) { return (item->handle != INVALID_HANDLE); }
	VfxBool isActive(void);

	//User can active a theme which is not in theme folder
	VfxBool isActiveInThemeFolder(void) const;
	VfxBool isActiveThemeFileExit(void);
	void checkActiveTheme(void);

	VfxWString getPath(VfxU16 drv);
	VfxBool getFilePath(VfxWChar *buffer, VfxU32 size, VfxS32 pos);
	
protected:
	VfxU8  m_waitingJob;
	
private:
	enum
	{
		FOLDER_PHONE,
		FOLDER_CARD,
		FOLDER_TOTAL
	};

	enum
	{
		JOB_SEARCHING_PHONE,
		JOB_SEARCHING_CARD,
		JOB_SORT,
		JOB_TOTAL
	};

	enum 
	{ 
		INVALID_HANDLE = 0,
		IMG_BUFFER_SIZE = 45*1024
	};

	VfxU32 m_lstHandle[FOLDER_TOTAL];
	VfxU32 m_lstFileCnt[FOLDER_TOTAL];
	VfxU16 m_drvList[FOLDER_TOTAL];
	VfxU32 m_adjustCnt;
	VfxChar *m_workingBuffer;
	VfxWChar *m_nameBuffer;
	FileItem *m_fileItems;
	FileItem m_activeFileItem;
	
	static const VfxResId s_errStr[VappThemeDltData::TOTAL_ERROR];
	static const VfxS32 s_errCode[VappThemeDltData::TOTAL_ERROR];
};


/***************************************************************************** 
 * Class VappThemeDltSwitchCui
 *****************************************************************************/
class VappThemeDltSwitchCui : public VappThemeSwitchCui
{
    VFX_DECLARE_CLASS(VappThemeDltSwitchCui);    
public:
	VappThemeDltSwitchCui(){}
	
// Overrides
protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	mmi_ret onProc(mmi_event_struct *evt); 
	virtual VfxBool active(void);
	virtual VappThemeDltCntx *getCntx();
	virtual VfxS32 checkValid(void);
};


extern mmi_ret vapp_theme_fmgr_evt_hdlr(mmi_event_struct *evt, VappThemeDltCntx *cntx);
extern void vapp_theme_fmgr_check_hdlr(const WCHAR* filepath, 
										  VappThemeDltCntx *cntx,
										  VfxClassInfo *switchClsInfo,
										  VappThemeSwitchDesc &desc);
#endif /* __VAPP_THEME_DLT_H__ */

