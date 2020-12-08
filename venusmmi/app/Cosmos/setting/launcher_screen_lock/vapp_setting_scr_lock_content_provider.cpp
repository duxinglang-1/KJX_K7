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
 *  vapp_setting_scr_lock_content_provider.cpp
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
#include "vapp_setting_scr_lock_content_provider.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_gprot.h"
#include "GlobalResDef.h"
#include "FileMgrSrvGprot.h"
#include "vapp_setting_dlui_image_content_mgr.h"
/*****************************************************************************
 * Setting Provider
 *****************************************************************************/
VappScrLockContentProvider::VappScrLockContentProvider()
{
    VFX_OBJ_CREATE(m_scrLockMgr, DluiImgBufMgr, this);
    _getAllCounts();
    _getAllScrLockIds();

    VappScreenLockSettingProvider* provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);        
    m_defaultId = provider->getDefaultScreenLock();
}

VappScrLockContentProvider::~VappScrLockContentProvider()
{
    for (VfxS32 i = 0; i<VAPP_SCREEN_LOCK_SRC_TOTAL; ++i)
    {
        VfxU32 totalNum = m_scrLockCount[i];
        if (totalNum)
        {
            VappScreenLockId::deleteArray(m_ppScreenLockId[i], totalNum);
        }            
    }
}

void VappScrLockContentProvider::exit()
{
    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}

    void VappScrLockContentProvider::setScreenShotContext(VfxContext* cntx)
    {
        m_ScrnshotCntx = cntx;
    }

	// return DLUI thumb according to (g, p)
VfxBool VappScrLockContentProvider::getDLUIThumb(VfxS32 group, VfxS32 pos, VfxImageSrc& image)
{       
    VfxFrame * imgFrame = NULL;
    VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);
    VappScreenLockId** ppScrLockId = m_ppScreenLockId[group];
    imgFrame = kit->createIcon(*(ppScrLockId[pos]), this);

	if (NULL != imgFrame)
	{
	    image = imgFrame->getImgContent();
	    VFX_OBJ_CLOSE(imgFrame);
        return VFX_TRUE;
	}
    return VFX_FALSE;
}   
	
	// return DLUI screen shot according to (g, p)
VfxFrame* VappScrLockContentProvider::getDLUIScreenShot(VfxS32 group, VfxS32 pos)
{
        VfxFrame ** pImgFrame = NULL;
        VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);
        pImgFrame = kit->createScreenshot(*m_ppScreenLockId[group][pos], m_ScrnshotCntx);
        
        if (NULL != pImgFrame)
        {    
            m_scrLockMgr->addShotFrame(group, pos, pImgFrame);
        return *pImgFrame;
        }
        else
        {   // if the ppFrame is NULL, then set it empty.
            VfxTextFrame* textFrame = NULL;
            VFX_OBJ_CREATE(textFrame, VfxTextFrame, m_ScrnshotCntx);
            textFrame->setString(VFX_WSTR_RES(STR_GLOBAL_EMPTY));
        return textFrame;
        }
}   
	
VfxBool VappScrLockContentProvider::freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg)
{
    VfxFrame ** pImgFrame = m_scrLockMgr->getShotForFree(group, pos);

    if (pImgFrame)
    {
        VfxS32 screenNum = 0;
        VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit); 

        screenNum = kit->getScreenshotNum(*m_ppScreenLockId[group][pos]);
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
const VfxWString VappScrLockContentProvider::getDLUIName(VfxS32 group, VfxS32 pos)
{        
    VfxWChar temp[SRV_FMGR_PATH_MAX_LEN + 1];
        
    VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);  
    VappScreenLockId** ppScrLockId = m_ppScreenLockId[group];
    kit->getName(*(ppScrLockId[pos]), temp, SRV_FMGR_PATH_MAX_LEN+1);
    temp[SRV_FMGR_PATH_MAX_LEN] = 0;

    return VFX_WSTR_MEM(temp);
}   
	
	// return DLUI group count.
VfxS32 VappScrLockContentProvider::getDLUIGroupCount() const
{
    VfxS32 groupCount = 0;

	for(VfxS32 i=0; i<VAPP_SCREEN_LOCK_SRC_TOTAL; ++i)
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
VfxS32 VappScrLockContentProvider::getDLUIItemCount(VfxS32 group) const
{
        return m_scrLockCount[group];
}   

	// return default DLUI menu pos
VfxBool VappScrLockContentProvider::getDefaultDLUI(VfxS32& group, VfxS32& pos)
{
    for (VfxS32 g=0; g<VAPP_SCREEN_LOCK_SRC_TOTAL; ++g)
    {
        for (VfxS32 p=0; p<m_scrLockCount[g]; ++p)
        {
            if (m_defaultId == *m_ppScreenLockId[g][p])
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
void VappScrLockContentProvider::setDefaultDLUI(VfxS32 group, VfxS32 pos)
{
    m_focusId = *m_ppScreenLockId[group][pos];

    if (_isConfigurationSupported(m_focusId))
    {
        _launcheConfiguration(m_focusId);
    }           
    else
    {
        _setScreenLockSuccess(m_focusId);
    }
}

VfxBool VappScrLockContentProvider::isCurUIDefault(VfxS32 group, VfxS32 pos) const
{
    return (m_defaultId == *m_ppScreenLockId[group][pos]? VFX_TRUE : VFX_FALSE);
}

VfxBool VappScrLockContentProvider::checkDluiValidate(VfxS32 group, VfxS32 pos, VfxWString& ErrStr)
{
    VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    VappScreenLock *scrLock = kit->createScreenLock(*m_ppScreenLockId[group][pos], getParent());

    VfxBool ret = scrLock->checkAvailable(ErrStr);

    VFX_OBJ_CLOSE(scrLock);

    return ret;
}


void VappScrLockContentProvider::_getAllCounts()
{
    VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    for (VfxS32 i = 0; i<VAPP_SCREEN_LOCK_SRC_TOTAL; ++i)
    {
        VappScreenLockKitFilter filter(VFX_FALSE);
        filter.permit((VappScreenLockSrcEnum)i);            
        VfxS32 count = kit->getTotalNum(&filter);
        m_scrLockCount[i] = count>0? count:0;
    }
}

void VappScrLockContentProvider::_getAllScrLockIds()
{
    VappScreenLockKit* kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    for (VfxS32 i = 0; i<VAPP_SCREEN_LOCK_SRC_TOTAL; ++i)
    {
        VfxU32 totalNum = m_scrLockCount[i];
        if (totalNum)
        {
            VappScreenLockKitFilter filter(VFX_FALSE);
            filter.permit((VappScreenLockSrcEnum)i);            
            m_ppScreenLockId[i] = VappScreenLockId::newArray(totalNum,this);
            kit->getAllId(m_ppScreenLockId[i], totalNum, &filter);
        }            
    }
}


VfxBool VappScrLockContentProvider::_isConfigurationSupported(const VappScreenLockId &id)
{
    VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    VappScreenLock *scrLock = kit->createScreenLock(id, getParent());

    VfxBool ret = scrLock->isConfigurationSupported();

    VFX_OBJ_CLOSE(scrLock);

    return ret;
}

void VappScrLockContentProvider::_launcheConfiguration(const VappScreenLockId &id)
{
    VappScreenLockKit *kit = VFX_OBJ_GET_INSTANCE(VappScreenLockKit);

    VappScreenLock *scrLock = kit->createScreenLock(id, getParent());

    // This signal will be emitted when the launcher finishes its setting.
    scrLock->m_signalConfigurationCompleted.connect(this, &VappScrLockContentProvider::onScrLockConfigurationCompleted);

    scrLock->createConfiguration();
}

void VappScrLockContentProvider::onScrLockConfigurationCompleted(VappScreenLock *scrLock, VfxBool result)
{
    VFX_OBJ_CLOSE(scrLock);
    if (result)
    {        
        m_signalSetSuccess.emit(this, VFX_TRUE);
    }
}

void VappScrLockContentProvider::_setScreenLockSuccess(const VappScreenLockId& scrLockId)
{    
    VappScreenLockSettingProvider* provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);        
    provider->setDefaultScreenLock(scrLockId);

    vapp_screen_lock_launch();
    m_signalSetSuccess.emit(this, VFX_TRUE);
}
