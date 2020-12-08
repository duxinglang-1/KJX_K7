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
 *  vapp_desktop.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the interface of the desktop launcher.
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

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_desktop_director.h"
#include "vapp_desktop_def.h"
#include "vapp_desktop.h"
#include "vapp_desktop_gprot.h"
#include "mmi_rp_vapp_desktop_def.h"

extern "C"
{
#include "MMI_include.h"
#include "IdleGprot.h"
}


/*****************************************************************************
 * Global Variable
 *****************************************************************************/

static VappDesktopDirector *s_vapp_desktop = NULL;


/*****************************************************************************
 * Function
 *****************************************************************************/

/* For the detail information, please refer to the vapp_desktop_gprot.h */
void vapp_desktop_create(MMI_ID group_id)
{
    void *ptr;
    
    VFX_ASSERT(s_vapp_desktop == NULL);
    ptr = mmi_frm_asm_alloc_r(group_id, VAPP_DESKTOP_MAX_CNTX_MEM_SIZE);
    VfxAppCatScr::initalizeWithMem(ptr, VAPP_DESKTOP_MAX_CNTX_MEM_SIZE);

    VFX_OBJ_CREATE(
        s_vapp_desktop,
        VappDesktopDirector,
        VfxAppCatScr::getContext());
    s_vapp_desktop->m_groupId = group_id;
}


/* For the detail information, please refer to the vapp_desktop_gprot.h */
void vapp_desktop_release(void)
{
    MMI_ID group_id = s_vapp_desktop->m_groupId;
    void *ptr = VfxAppCatScr::getContext()->getBuf();
    VFX_OBJ_CLOSE(s_vapp_desktop);
    VfxAppCatScr::deinitalize();
    mmi_frm_asm_free_r(group_id, ptr);    
}


/* For the detail information, please refer to the vapp_desktop_gprot.h */
MMI_ID vapp_desktop_launch(void *param, U32 param_size)
{
    return GRP_ID_INVALID;
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */

