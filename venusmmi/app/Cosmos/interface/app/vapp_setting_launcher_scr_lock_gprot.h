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
 *  vapp_setting_launcher_gprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SETTING_LAUNCHER_SCR_LOCK_GPROT_H__
#define __VAPP_SETTING_LAUNCHER_SCR_LOCK_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

/*****************************************************************************
 *  Define
 ****************************************************************************/ 
#if defined(__MMI_MAINLCD_480X800__)
        enum
        {
            PREVIEW_BLANCK_GAP  = 63,
            PREVIEW_IMG_V_GAP = 18,
            PREVIEW_IMG_H_GAP   = 18,
            
            PREVIEW_BG_WIDTH    = 344,
            PREVIEW_BG_HEIGHT   = 552,
            PREVIEW_IMG_WIDTH   = 312,
            PREVIEW_IMG_HEIGHT  = 520,
            
            PREVIEW_SHADOW_T    = 4,
            PREVIEW_SHADOW_B    = 14,
            
            PREVIEW_TEXT_SIZE   = 30,
            PREVIEW_TXT_POS     = 640 + 38 //- STATUS_BAR_HEIGHT
        };
#elif defined(__MMI_MAINLCD_320X480__)
        enum
        {
            PREVIEW_BLANCK_GAP  = 36,
            PREVIEW_IMG_V_GAP = 8,
            PREVIEW_IMG_H_GAP   = 8,
            
            PREVIEW_BG_WIDTH    = 240,
            PREVIEW_BG_HEIGHT   = 344,
            PREVIEW_IMG_WIDTH   = 208,
            PREVIEW_IMG_HEIGHT  = 312,
            
            PREVIEW_SHADOW_T    = 4,
            PREVIEW_SHADOW_B    = 14,
            
            PREVIEW_TEXT_SIZE   = 20,
            PREVIEW_TXT_POS     = 384 + 24//- STATUS_BAR_HEIGHT
        };
#elif defined(__MMI_MAINLCD_240X400__)
        enum
        {
            PREVIEW_BLANCK_GAP  = 33,
            PREVIEW_IMG_V_GAP = 16,
            PREVIEW_IMG_H_GAP   = 6,
            
            PREVIEW_BG_WIDTH    = 168,
            PREVIEW_BG_HEIGHT   = 261,
            PREVIEW_IMG_WIDTH   = 140,
            PREVIEW_IMG_HEIGHT  = 233,
            
            PREVIEW_SHADOW_T    = 4,
            PREVIEW_SHADOW_B    = 14,
        
            PREVIEW_TEXT_SIZE   = 14,
            PREVIEW_TXT_POS     = 328 //- STATUS_BAR_HEIGHT
        };
#else
        enum
        {
            PREVIEW_BLANCK_GAP  = 33,
            PREVIEW_IMG_V_GAP = 6,
            PREVIEW_IMG_H_GAP   = 6,
            
            PREVIEW_BG_WIDTH    = 168,
            PREVIEW_BG_HEIGHT   = 215,
            PREVIEW_IMG_WIDTH   = 140,
            PREVIEW_IMG_HEIGHT  = 187,
            
            PREVIEW_SHADOW_T    = 4,
            PREVIEW_SHADOW_B    = 14,            
            
            PREVIEW_TEXT_SIZE   = 14,
            PREVIEW_TXT_POS     = 258 //- STATUS_BAR_HEIGHT
        };
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
extern "C"
{

    extern mmi_id vapp_launcher_setting_launch(mmi_id parentId);
    extern mmi_id vapp_scr_lock_setting_launch(mmi_id parentId);    
    extern void vapp_dlui_setting_run(mmi_id cuiId);
    extern void vapp_dlui_setting_close(mmi_id cuiId);

}

#if defined (__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
/***************************************************************************** 
 * Class VappLauncherSettingCell
 *****************************************************************************/
class VappSettingLauncherSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSettingLauncherSettingCell);
    
    // Override
    protected:
        virtual void onInit();
    
    // Methods
    protected:
        void onTap(VcpFormItemCell* sender, VfxId senderId);
};
#endif // #if defined (__MMI_VUI_SETTING_LAUNCHER_SELECTION__)

#if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
/***************************************************************************** 
 * Class VappScreenLockSettingCell
 *****************************************************************************/
class VappSettingScreenLockSettingCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappSettingScreenLockSettingCell);
    
    // Override
    protected:
        virtual void onInit();
    
    // Methods
    protected:
        void onTap(VcpFormItemCell* sender, VfxId senderId);
};
#endif // #if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)

#endif /*__VAPP_SETTING_LAUNCHER_SCR_LOCK_GPROT_H__*/
