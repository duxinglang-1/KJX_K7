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
 *  vapp_setting_dlui_content_provider.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SETTING_DLUI_CONTENT_PROVIDER_H
#define VAPP_SETTING_DLUI_CONTENT_PROVIDER_H

#include "MMI_features.h"

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"

/*****************************************************************************
 * Setting Provider
 *****************************************************************************/
class IVappDLUISettingProvider
{
public:
	//virtual ~IVappDLUISettingProvider() = 0;
	virtual void exit() = 0;
	// Method
	public:
		// return DLUI thumb according to (g, p)
		virtual VfxBool getDLUIThumb(VfxS32 group, VfxS32 pos, VfxImageSrc& image) = 0;
		
		// return DLUI screen shot according to (g, p)
		virtual VfxFrame* getDLUIScreenShot(VfxS32 group, VfxS32 pos) = 0;		
		
		// free screen shot VfxImageSrc mem according to (g, p)
		virtual VfxBool freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg) = 0;
		
		// return DLUI name according to (g, p)
		virtual const VfxWString getDLUIName(VfxS32 group, VfxS32 pos) = 0; 	
		
		// return DLUI group count.
		virtual VfxS32 getDLUIGroupCount() const = 0;
		
		// return DLUI name according to wallpaper id (enum)
		virtual VfxS32 getDLUIItemCount(VfxS32 group) const = 0;
		
		virtual VfxBool getDefaultDLUI(VfxS32& group, VfxS32& pos) = 0;
		
		// set current DLUI
		virtual void setDefaultDLUI(VfxS32 group, VfxS32 pos) = 0;

                // check if current pos cell is default one
		virtual VfxBool isCurUIDefault(VfxS32 group, VfxS32 pos) const = 0;

    // set the context of screen shot
    virtual void setScreenShotContext(VfxContext* cntx){}

	// check if the dlui is existed
	virtual VfxBool checkDluiValidate(VfxS32 group, VfxS32 pos, VfxWString& ErrStr){return VFX_TRUE;}
public:
	VfxSignal2<VfxObject*, VfxBool> m_signalSetSuccess;
    VfxSignal0  m_signalReleaseAllScrnshot;
    VfxSignal0  m_signalUpdateScrnshot;
};
#endif /* VAPP_SETTING_DLUI_CONTENT_PROVIDER_H */

