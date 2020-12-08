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
 *  vapp_screen_lock_mre_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE factory of the screen lock.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)
/*****************************************************************************
 * Include
 *****************************************************************************/
extern "C"
{
#include "MREAppMgrSrvGprot.h"
#include "SafeModeSrvGprot.h"
}

#include "vfx_uc_include.h"
#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_mre_factory.h"
#include "vapp_screen_lock_mre.h"
#include "vapp_screen_lock_kit.h"


/*****************************************************************************
 * MRE Screen Lock Factory
 *****************************************************************************/

VAPP_SCREEN_LOCK_SYS_PUBLISH_FACTORY(
    VappScreenLockMreFactory,
    VappScreenLockMreFactoryPublisher);

VAPP_SCREEN_LOCK_FACTORY_IMPLEMENT_CLASS(VappScreenLockMreFactory);


VappScreenLockMreFactory::VappScreenLockMreFactory()
{
    // Do nothing.
}


VfxS32 VappScreenLockMreFactory::getTotalNum() const
{
    if (srv_safe_mode_is_active())
    {
        return 0;
    }

    return srv_mre_appmgr_get_app_num(
            SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE);
}


VfxS32 VappScreenLockMreFactory::getAllId(
    VappScreenLockId **id,
    VfxS32 size) const
{
    if (srv_safe_mode_is_active())
    {
        return 0;
    }

    VfxS32 totalNum = getTotalNum();

    if (!id || size < totalNum || totalNum <= 0)
    {
        return 0; // Fail. Cannot get the IDs.
    }

    mmi_app_package_name_struct *package;

    VFX_SYS_ALLOC_MEM(package, totalNum * sizeof(mmi_app_package_name_struct));

    mmi_ret ret = srv_mre_appmgr_get_app_list(
                    SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE,
                    package,
                    totalNum);

    VFX_ASSERT(ret == MMI_RET_OK);

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        id[i]->assignWith(VAPP_SCREEN_LOCK_SRC_MRE, package[i]);
    }

    VFX_SYS_FREE_MEM(package);

    return totalNum;
}


VappScreenLock *VappScreenLockMreFactory::createScreenLock(
    const VappScreenLockId &id,
    VfxObject *parentObj)
{
    if (srv_safe_mode_is_active() ||
        id.getSource() != VAPP_SCREEN_LOCK_SRC_MRE ||
        id.getTypeKind() != VappScreenLockId::TYPE_KIND_STRING)
    {
        return NULL;
    }

    VappScreenLockMre *scrnLock;

    VFX_OBJ_CREATE(scrnLock, VappScreenLockMre, parentObj);

    scrnLock->setId(id);

    return scrnLock;
}

#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */
