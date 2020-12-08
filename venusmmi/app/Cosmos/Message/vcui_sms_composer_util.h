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
 *  vcui_sms_composer_util.h
 *
 * Project:
 * --------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SMS_COMPOSER_UTIL_H__
#define __VCUI_SMS_COMPOSER_UTIL_H__

/*****************************************************************************
 * Include
 *****************************************************************************/ 
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"    
#include "vfx_page.h"
#include "vfx_object.h"
#include "Vapp_sim_setting_gprot.h"
#include "vcui_sms_composer_core.h"
#include "vcui_sms_composer_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "Conversions.h"
#include "app_url.h"
#include "app_str.h"
#include "ModeSwitchSrvGprot.h"
#include "GeneralSettingSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vcui_sms_composer_def.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/******************************************************************************/
/*                          Class VcuiSmsComposerUtility                             */
/******************************************************************************/
class VcuiSmsComposerUtility : public VfxBase
{
// Method
public:

    static VfxBool checkIsAsciiString(const VfxU8 *ucs2_str);
    static VfxBool checkIsPhoneNum(VfxU8 *strNumber);
    static VfxBool checkIsFlightMode(void);
   
    static VfxS32 getMaxRecipientCount(void);   
    static VfxS32 getMaxContentTextCount(void);
    
    static VfxBool getSimNameStr(mmi_sim_enum sim, WCHAR* text_buffer);
    static void getSwitchSimStr(VfxU16 *text_buffer, mmi_sim_enum send_sim_id); 
    static void getTitleBarStr(VfxU16 *text_buffer, mmi_sim_enum send_sim_id);
    static void getSendButtonStr(VfxU16 *text_buffer, mmi_sim_enum send_sim_id);
    static void getHintTextStr(VfxS32 remain, VfxS32 current,  VfxS32 maxSize, VfxChar *text_buffer);
    static void getSwapSimStr(VfxU16 *text_buffer, mmi_sim_enum send_sim_id);   
    static VfxId getErrorStrId(VcuiSmsComposerResultEnum error);
    
    static VfxU32 getValidSim(void);  
    static VfxU32 getBlockedSim(void);
    static VfxU32 getClosedSim(void);
    static VfxU32 getInvalidSim(void);
    static mmi_sim_enum getValidSimToSend(void) ; 
    
    static VfxS32 getCurrValidSimCount(void) ;   
    static VfxS32 getAllSimCount(void);
    static mmi_sim_enum getCurrSim(void);

    static VfxU32 convertSwitchModeToSmscSim(VfxU32 swith_mode);   

// member variables
public:
    static VfxU32 valid_sim;
    static VfxU32 blocked_sim ;
    static VfxU32 closed_sim ;
};


#ifdef __cplusplus
extern "C"
{
#endif

// extern API
mmi_ret vcuiSmsComposerSimStatusInfoHdlr(mmi_event_struct *evt);

#ifdef __cplusplus
}
#endif

#endif /* __VCUI_SMS_COMPOSER_UTIL_H__ */
