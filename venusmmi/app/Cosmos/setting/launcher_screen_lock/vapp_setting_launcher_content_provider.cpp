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
 *  vapp_setting_launcher_content_provider.cpp
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

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "mmi_rp_vapp_launcher_setting_def.h"
#include "vfx_app_launcher.h"
#include "vapp_setting_launcher_content_provider.h"
#include "vapp_launcher.h"
#include "GlobalResDef.h"
#include "FileMgrSrvGprot.h"
#include "vapp_setting_dlui_image_content_mgr.h"
/*****************************************************************************
 * Setting Provider
 *****************************************************************************/
VappLauncherContentProvider::VappLauncherContentProvider()
{
    VFX_OBJ_CREATE(m_launcherMgr, DluiImgBufMgr, this);
    _getAllCounts();
    _getAllLauncherIds();
    
    VappLauncherSettingProvider* provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);        
    m_defaultId = provider->getDefaultLauncher();
}

VappLauncherContentProvider::~VappLauncherContentProvider()
{
    for (VfxS32 i = 0; i<VAPP_LAUNCHER_SRC_TOTAL; ++i)
    {
        VfxU32 totalNum = m_lchCount[i];
        if (totalNum)
        {
            VappLauncherId::deleteArray(m_ppLauncherId[i], totalNum);
        }            
    }
}

void VappLauncherContentProvider::setScreenShotContext(VfxContext* cntx)
{
    m_ScrnshotCntx = cntx;
}

void VappLauncherContentProvider::exit()
{
    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}

VfxBool VappLauncherContentProvider::getDLUIThumb(VfxS32 group, VfxS32 pos, VfxImageSrc& image)
{
    VfxFrame * imgFrame = NULL;

    VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);
    VappLauncherId** ppLchId = m_ppLauncherId[group];
    imgFrame = kit->createIcon(*(ppLchId[pos]), this);

	if (NULL != imgFrame)
	{
	    image = imgFrame->getImgContent();
	    VFX_OBJ_CLOSE(imgFrame);
        return VFX_TRUE;
	}
    return VFX_FALSE;

}

	// return DLUI screen shot according to (g, p)
VfxFrame*  VappLauncherContentProvider::getDLUIScreenShot(VfxS32 group, VfxS32 pos)
{
    VfxFrame ** pImgFrame = NULL;
    
    VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);
    pImgFrame = kit->createScreenshot(*m_ppLauncherId[group][pos], m_ScrnshotCntx);
    
    if (NULL != pImgFrame)
    {    
        m_launcherMgr->addShotFrame(group, pos, pImgFrame);
        return *pImgFrame;
    }
    else
    {   // if the ppFrame is NULL, then set it empty.
		VfxTextFrame* textFrame = NULL;
		VFX_OBJ_CREATE(textFrame, VfxTextFrame, m_ScrnshotCntx);
		textFrame->setString(STR_GLOBAL_EMPTY);
        return textFrame;
    }
}   
	
VfxBool VappLauncherContentProvider::freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg)
{
    VfxFrame ** pImgFrame = m_launcherMgr->getShotForFree(group, pos);

    // If the launcher preview image has content.
    if (pImgFrame)
    {
        VfxS32 screenNum = 0;
        VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

        screenNum = kit->getScreenshotNum(*m_ppLauncherId[group][pos]);
        kit->releaseScreenshot(pImgFrame, screenNum);
        pImgFrame = NULL;
    }
    // If the launcher preivew image has not content.
    else if(previewImg)
    {
        VFX_OBJ_CLOSE(previewImg);
    }

    return VFX_TRUE;
}   

	// return DLUI name according to (g, p)
const VfxWString VappLauncherContentProvider::getDLUIName(VfxS32 group, VfxS32 pos)
{
    VfxWChar temp[SRV_FMGR_PATH_MAX_LEN + 1];
    
    VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);          
    kit->getName(*(m_ppLauncherId[group][pos]), temp, SRV_FMGR_PATH_MAX_LEN+1);
    temp[SRV_FMGR_PATH_MAX_LEN ] = 0;
    return VFX_WSTR_MEM(temp);
}   
	
	// return DLUI group count.
VfxS32 VappLauncherContentProvider::getDLUIGroupCount() const
{
        VfxS32 groupCount = 0;
        
        for(VfxS32 i=0; i<VAPP_LAUNCHER_SRC_TOTAL; ++i)
        {
            if (getDLUIItemCount(i))
            {
                ++groupCount;
            }
            else
            {
                break;
            }
        }
        return groupCount;

}   
	
	// return DLUI name according to wallpaper id (enum)
VfxS32 VappLauncherContentProvider::getDLUIItemCount(VfxS32 group) const
{
    return m_lchCount[group];
}   

	// return default DLUI menu pos
VfxBool VappLauncherContentProvider::getDefaultDLUI(VfxS32& group, VfxS32& pos)
{
    for (VfxS32 g=0; g<VAPP_LAUNCHER_SRC_TOTAL; ++g)
    {
        for (VfxS32 p=0; p<m_lchCount[g]; ++p)
        {
            if (m_defaultId == *m_ppLauncherId[g][p])
            {
                group = g;
                pos = p;
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}   
	
	// set current DLUI
void VappLauncherContentProvider::setDefaultDLUI(VfxS32 group, VfxS32 pos)
{
        m_focusId = *m_ppLauncherId[group][pos];
        
        if (_isConfigurationSupported(m_focusId))
        {
            _launcheConfiguration(m_focusId);
        }           
        else
        {
            _setLauncherSuccess(m_focusId);
        }
}   

VfxBool VappLauncherContentProvider::isCurUIDefault(VfxS32 group, VfxS32 pos) const
{
    return (m_defaultId == *m_ppLauncherId[group][pos]? VFX_TRUE : VFX_FALSE);
}

VfxBool VappLauncherContentProvider::checkDluiValidate(VfxS32 group, VfxS32 pos, VfxWString& ErrStr)
{
    VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    VappLauncher *launcher = kit->createLauncher(*m_ppLauncherId[group][pos], getParent());

    VfxBool ret = launcher->checkAvailable(ErrStr);

    VFX_OBJ_CLOSE(launcher);

    return ret;    
}

void VappLauncherContentProvider::_getAllCounts()
{
    VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    for (VfxS32 i = 0; i<VAPP_LAUNCHER_SRC_TOTAL; ++i)
    {
        VappLauncherKitFilter filter(VFX_FALSE);
        filter.permit((VappLauncherSrcEnum)i);            
        VfxS32 count = kit->getTotalNum(&filter);
        m_lchCount[i] = count>0? count:0;
    }
}

void VappLauncherContentProvider::_getAllLauncherIds()
{
    VappLauncherKit* kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    for (VfxS32 i = 0; i<VAPP_LAUNCHER_SRC_TOTAL; ++i)
    {
        VfxU32 totalNum = m_lchCount[i];
        if (totalNum)
        {
            VappLauncherKitFilter filter(VFX_FALSE);
            filter.permit((VappLauncherSrcEnum)i);            
            m_ppLauncherId[i] = VappLauncherId::newArray(totalNum,this);
            kit->getAllId(m_ppLauncherId[i], totalNum, &filter);
        }            
    }
}

// Use this function to decide if the "Setting" button should appear
VfxBool VappLauncherContentProvider::_isConfigurationSupported(const VappLauncherId &id)
{
    VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    VappLauncher *launcher = kit->createLauncher(id, getParent());

    VfxBool ret = launcher->isConfigurationSupported();

    VFX_OBJ_CLOSE(launcher);

    return ret;
}

// If the "Setting" button appear, when the user clicks the button, use this
// function to launch the launcher's configuration page.
void VappLauncherContentProvider::_launcheConfiguration(const VappLauncherId &id)
{
    VappLauncherKit *kit = VFX_OBJ_GET_INSTANCE(VappLauncherKit);

    VappLauncher *launcher = kit->createLauncher(id, getParent());

    // This signal will be emitted when the launcher finishes its setting.
    launcher->m_signalConfigurationCompleted.connect(this, &VappLauncherContentProvider::onLauncherConfigurationCompleted);

    launcher->createConfiguration();
}


// When the launcher finishes its settings, we need to close it.
void VappLauncherContentProvider::onLauncherConfigurationCompleted(VappLauncher *launcher, VfxBool result)
{
    VFX_OBJ_CLOSE(launcher);
    if (result)
    {
        _setLauncherSuccess(m_focusId);
    }
}

void VappLauncherContentProvider::_setLauncherSuccess(const VappLauncherId &id)
{
    VappLauncherId *idPtr;
    VFX_NEW_EX(idPtr, VappLauncherId, (id));
  
    VappThemeSwitchDesc desc;
    desc.m_switchingId = STR_ID_VAPP_SETTING_LAUNCHER_SWITCHING;
    desc.m_changedId = STR_ID_VAPP_SETTING_LAUNCHER_CHANGED;
    desc.u.usr_data = (void *)idPtr;

    VfxAppLauncher::launch(
            VCUI_THEME_SWITCH,
            VFX_OBJ_CLASS_INFO(VcuiSettingSwitchLauncher),
            GRP_ID_ROOT,
            &desc,
            sizeof(VappThemeSwitchDesc));
}

VFX_IMPLEMENT_CLASS("VcuiSettingSwitchLauncher", VcuiSettingSwitchLauncher, VappThemeSwitchCui);
VfxBool VcuiSettingSwitchLauncher::active(void)
{
    VappLauncherId *id = (VappLauncherId *)m_switchDesc.u.usr_data;
        
    VappLauncherSettingProvider* provider = VFX_OBJ_GET_INSTANCE(VappLauncherSettingProvider);        
    provider->setDefaultLauncher(*id);

    return VFX_TRUE;
}

void VcuiSettingSwitchLauncher::onDeinit()
{
    VappLauncherId *idPtr = (VappLauncherId *)m_switchDesc.u.usr_data;
    
    VFX_DELETE(idPtr);
}
