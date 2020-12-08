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
 *  vapp_launcher_key.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the interface of the key launcher.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_app_cat_scr.h"
#include "vapp_launcher_key_director.h"
#include "vapp_launcher_key_def.h"
#include "vapp_launcher_key.h"
#include "vapp_launcher_key_gprot.h"

extern "C"
{
#include "MMI_include.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "app_mem.h"
#include "IdleGprot.h"
}


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static VappKeyLauncherDirector *s_vapp_launcher_key = NULL;


/*****************************************************************************
 * Function
 *****************************************************************************/

/* For the detail information, please refer to the vapp_launcher_key_gprot.h */
void vapp_launcher_key_create(MMI_ID group_id)
{
    VFX_ASSERT(s_vapp_launcher_key == NULL);	

	void *ptr;	
	ptr = mmi_frm_asm_alloc_r(group_id, VAPP_KEYLAUNCHER_MAX_CNTX_MEM_SIZE);
	VfxAppCatScr::initalizeWithMem(ptr, VAPP_KEYLAUNCHER_MAX_CNTX_MEM_SIZE);

    VFX_OBJ_CREATE_EX(
        s_vapp_launcher_key,
        VappKeyLauncherDirector,
        VfxAppCatScr::getContext(),
		(mmi_frm_group_get_top_parent_group_id(group_id)));
	s_vapp_launcher_key->m_groupId = group_id;
}


/* For the detail information, please refer to the vapp_launcher_key_gprot.h */
void vapp_launcher_key_release(void)
{
	MMI_ID group_id = s_vapp_launcher_key->m_groupId;
    void *ptr = VfxAppCatScr::getContext()->getBuf();
	
    VFX_OBJ_CLOSE(s_vapp_launcher_key);
    VfxAppCatScr::deinitalize();
	mmi_frm_asm_free_r(group_id, ptr);
	
}


/* For the detail information, please refer to the vapp_launcher_key_gprot.h */
MMI_ID vapp_launcher_key_launch(void *param, U32 param_size)
{
    return GRP_ID_INVALID;
}


/* For the detail information, please refer to the vapp_launcher_key_gprot.h */
void vapp_launcher_key_on_before_idle_display(void)
{
    if (VappKeyLauncherDirector::s_currentPage == VappKeyLauncherDirector::MAINMENU_PAGE)
    {
		VappKeyLauncherDirector::s_currentPage = VappKeyLauncherDirector::s_perviousPage;
		VappKeyLauncherDirector::s_perviousPage = VappKeyLauncherDirector::NULL_PAGE;
    }
}


#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */


