/*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vcui_sms_composer_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Keyu Xiang
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_SMS_COMPOSER__

#include "vcui_sms_composer_gprot.h"
#include "vcui_sms_composer_core.h"
#include "vcui_sms_composer_scrn.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_app_cosmos_global_def.h"

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
 * Macro Implementation
 *****************************************************************************/


/***************************************************************************** 
* Function
*****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

mmi_id vcui_sms_composer_create(mmi_id parent_grp_id)
{
    mmi_id cuiId = 0;
    
    cuiId =  VfxAppLauncher::createCui( 
                    VCUI_SMS_COMPOSER,
                    VFX_OBJ_CLASS_INFO(VcuiSmsComposer),
                    parent_grp_id);
                    
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_MAIN_CREATE_CUI, cuiId);
    
    return cuiId;
}

void vcui_sms_composer_run(mmi_id cui_id)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_MAIN_RUN_CUI, cui_id);

    VfxAppLauncher::runCui(cui_id);
}

void vcui_sms_composer_close(mmi_id cui_id)
{
    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_MAIN_CLOSE_CUI, cui_id);

    VfxAppLauncher::terminate(cui_id);
}

void vcui_sms_composer_set_entry_data (mmi_id cui_id, 
                                       VcuiSmsComposerEntryStruct *entryData)
{
    VcuiSmsComposer *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSmsComposer);

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_MAIN_SET_ENTRY_DATA, cui_id, NULL != entryData);

    if(NULL != cui)
    {
        cui->setEntryData(entryData);
    }
}

void vcui_sms_composer_set_rotate(mmi_id cui_id, VfxBool isSupportRotate)
{
    VcuiSmsComposer *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSmsComposer);

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_MAIN_SET_ROTATE, cui_id, isSupportRotate);

    if(NULL != cui)
    {
        cui->setRotate(isSupportRotate);
    }
}
#ifdef __cplusplus
}
#endif

#endif /* __MMI_SMS_COMPOSER__ */
