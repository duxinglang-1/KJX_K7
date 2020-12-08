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
 *  vcui_cal_list.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  use to insert a calendar or task item from other app
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
#include "vfx_cui.h"
#ifdef __MMI_VCALENDAR__
#include "vcui_cal_list_gprot.h"
#include "vcui_cal_list.h"
#include "mmi_rp_vcui_cal_list_def.h"
#include "vapp_cal_group_list.h"
#include "vapp_task_all_list.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

extern "C"
{

    mmi_id vcui_cal_list_create(mmi_id parent_id, vcui_cal_list_type_enum type)
    {

        vcui_cal_list_type_enum ptr_type; 

        ptr_type = type;

        mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_CAL_LIST, 
                                        VFX_OBJ_CLASS_INFO(VcuiCalListCui), 
                                        parent_id, 
                                        &ptr_type, 
                                        sizeof(vcui_cal_list_type_enum));

        return cui_id;
    }

    void vcui_cal_list_run(mmi_id cui_id)
    {
        VfxAppLauncher::runCui(cui_id);
    }

    void vcui_cal_list_close(mmi_id cui_id)
    {
        VfxAppLauncher::terminate(cui_id);
    }

}

VFX_IMPLEMENT_CLASS("VcuiCalListCui", VcuiCalListCui, VfxCui);
void VcuiCalListCui::onRun(void* args, VfxU32 argSize)  
{
    VfxCui::onRun(args, argSize);

    m_type = *(vcui_cal_list_type_enum *)args;

    VcuiCalListScr *scr;
    VFX_OBJ_CREATE(scr, VcuiCalListScr, this);
    scr->show();
}

VFX_IMPLEMENT_CLASS("VcuiCalListScr", VcuiCalListScr, VfxMainScr);
void VcuiCalListScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VcuiCalListCui *myCui = (VcuiCalListCui*)getApp();

    if (myCui->m_type == VCUI_CAL_LIST_CALENDAR)
    {
        VappCalGroupListPage *page;
        VFX_OBJ_CREATE_EX(page, VappCalGroupListPage, this, (VAPP_CAL_G_LIST_ENTRY_UC));
        pushPage(0, page);
    }
    else if (myCui->m_type == VCUI_CAL_LIST_TASK)
    {   
        VappTaskAllListPage *page;
        VFX_OBJ_CREATE_EX(page, VappTaskAllListPage, this, (VAPP_TASK_ALL_ENTRY_UC));
        pushPage(0, page);
    }
}
#endif /*__MMI_VCALENDAR__*/



