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
 *  vapp_theme_appicon_dlt.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_THEME_APPICON_DLT_H__
#define __VAPP_THEME_APPICON_DLT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"

#include "vapp_theme_dlt.h"


/***************************************************************************** 
 * Class VappThemeDltData
 *****************************************************************************/
class VappThemeDltAppIconCntx : public VappThemeDltCntx
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VappThemeDltAppIconCntx);
	
private:
	VappThemeDltAppIconCntx();
	
public:
	VfxU32 getActiveIndex(void);
	VfxBool setActiveIndex(VfxU32 index);
	
	VfxWChar *getCachePath(void);
	VfxWChar *getCacheBackupPath(void);
	VfxS16 active(const VfxWChar *path);
	VfxS16 active(VfxU32 index);
	VfxS16 deactive(void);

	void setIsDltActive(VfxBool isDlt, VfxU32 index = 0);
	void getActivePath(VfxWChar *path, VfxS32 size);
	void setActivePath(const VfxWChar *path, VfxS32 size);

	void onLauncherChange(void);
	VfxBool checkActive(void);

	VfxU32 restoreAppicon(void);
protected:
	void onInit();
	virtual vrt_allocator_handle getAllocator() { return m_selfMem->getAllocator(); }
	
private:	
	void printMemState(void);
	
protected:
	VfxS32 m_hdlr;
	VfxContext *m_selfMem;
	
private:
	static VfxU8 s_cntxBuffer[2048];
	
public:
	static VfxWChar s_buff[NVRAM_EF_DLT_THEME_SIZE];

};


/***************************************************************************** 
 * Class VappThemeAppIconDltSwitchCui
 *****************************************************************************/
class VappThemeAppIconDltSwitchCui : public VappThemeDltSwitchCui
{
    VFX_DECLARE_CLASS(VappThemeAppIconDltSwitchCui);  
public:
	VappThemeAppIconDltSwitchCui(){}
	
// Overrides
protected:
	VappThemeDltCntx *getCntx(void);
    VfxBool active(void);
};

/***************************************************************************** 
 * Class VappThemeAppIconDltData
 *****************************************************************************/
class VappThemeAppIconDltData : public VappThemeDltData
{
public:
	VappThemeAppIconDltData(){};

	VfxClassInfo *getCuiClassInfo(void)
	{
		return VFX_OBJ_CLASS_INFO(VappThemeAppIconDltSwitchCui);
	}
	
	VfxWString getFolderName(void)
	{
		return VFX_WSTR("AppIcon");
	}
	VfxU16 getFiletype(void);
	
	VappThemeDltCntx *getCntx(void)
	{
		return VFX_OBJ_GET_INSTANCE(VappThemeDltAppIconCntx);
	}
	
	VfxBool getTypeStr(VfxWString &typeName);
	void genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos);
	static void initAppIcon(void);
};

#endif /* __VAPP_THEME_APPICON_DLT_H__ */

