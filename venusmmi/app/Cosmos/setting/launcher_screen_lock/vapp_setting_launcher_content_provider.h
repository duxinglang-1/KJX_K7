/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_setting_launcher_content_provider.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the dlui provider.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SETTING_LAUNCHER_CONTENT_PROVIDER_H
#define VAPP_SETTING_LAUNCHER_CONTENT_PROVIDER_H

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vapp_setting_dlui_content_provider.h"

#include "vapp_launcher_kit.h"
#include "vapp_launcher_setting_provider.h"
#include "vapp_theme.h"

/*****************************************************************************
 * Setting Provider
 *****************************************************************************/
class VappLauncherId;
class VappLauncher;
class DluiImgBufMgr;

class VappLauncherContentProvider: public VfxObject,  public IVappDLUISettingProvider
{
	// constructor & destructor
public:
	VappLauncherContentProvider();
	virtual ~VappLauncherContentProvider();
	virtual void exit();
// Method
public:
	// return DLUI thumb according to (g, p)
	virtual VfxBool getDLUIThumb(VfxS32 group, VfxS32 pos, VfxImageSrc& image);
	
	// return DLUI screen shot according to (g, p)
    virtual VfxFrame*  getDLUIScreenShot(VfxS32 group, VfxS32 pos);
	
	// free DLUI screen shot memory according to (g, p)
	virtual VfxBool freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg);

	// return DLUI name according to (g, p)
	virtual const VfxWString getDLUIName(VfxS32 group, VfxS32 pos);		
	
	// return DLUI group count.
	virtual VfxS32 getDLUIGroupCount() const;
	
	// return DLUI name according to wallpaper id (enum)
	virtual VfxS32 getDLUIItemCount(VfxS32 group) const;
	
	virtual VfxBool getDefaultDLUI(VfxS32& group, VfxS32& pos);
	
	// set current DLUI
	virtual void setDefaultDLUI(VfxS32 group, VfxS32 pos);
	
	virtual VfxBool isCurUIDefault(VfxS32 group, VfxS32 pos) const;
	
	virtual VfxBool checkDluiValidate(VfxS32 group, VfxS32 pos, VfxWString& ErrStr);
	
public:
	void onLauncherConfigurationCompleted(VappLauncher *launcher, VfxBool result);

    virtual void setScreenShotContext(VfxContext* cntx);
private:
	void _getAllCounts();
	void _getAllLauncherIds();
	void _launcheConfiguration(const VappLauncherId &id);
	void _setLauncherSuccess(const VappLauncherId &id);
	VfxBool _isConfigurationSupported(const VappLauncherId &id);

	VfxS32 m_lchCount[VAPP_LAUNCHER_SRC_TOTAL];
	VappLauncherId   m_defaultId;
	VappLauncherId   m_focusId;
	VappLauncherId** m_ppLauncherId[VAPP_LAUNCHER_SRC_TOTAL];	
    DluiImgBufMgr*	m_launcherMgr;
    VfxContext* m_ScrnshotCntx;
};

#ifdef __MMI_THEMES_APPLICATION__
class VcuiSettingSwitchLauncher : public VappThemeSwitchCui
{
    VFX_DECLARE_CLASS(VcuiSettingSwitchLauncher);    

protected:
	virtual void onDeinit();
	virtual VfxBool active(void);
};
#endif 
#endif /* VAPP_SETTING_LAUNCHER_CONTENT_PROVIDER_H */

