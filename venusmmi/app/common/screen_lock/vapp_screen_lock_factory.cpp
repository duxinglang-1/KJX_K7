/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_screen_lock_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the base class of the screen lock factory.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_screen_lock_def.h"
#include "vapp_screen_lock_factory.h"


/*****************************************************************************
 * screen_lock Factory Base Class
 *****************************************************************************/

VFX_IMPLEMENT_VIRTUAL_CLASS("VappScreenLockFactory", VappScreenLockFactory, VfxObject);


VappScreenLockFactory::VappScreenLockFactory()
{
    // Do nothing.
}


VappScreenLockFactory::~VappScreenLockFactory()
{
    // Do nothing.
}


VfxBool VappScreenLockFactory::isValid(const VappScreenLockId &id)
{
    VappScreenLockId **allId;
    VfxS32 totalNum, obtainedNum;
    VfxBool isValid = VFX_FALSE;

    totalNum = getTotalNum();
    if (totalNum <= 0)
    {
        return VFX_FALSE;
    }

    // This array is for temp usage. Free it before we leave this function.
    allId = VappScreenLockId::newArray(totalNum, VFX_SYS_GLOBAL_CONTEXT);

    obtainedNum = getAllId(allId, totalNum);
    VFX_ASSERT(obtainedNum == totalNum);

    for (VfxS32 i = 0; i < obtainedNum; i++)
    {
        if (allId[i]->compareWith(id))
        {
            isValid = VFX_TRUE;
            break;
        }
    }

    VappScreenLockId::deleteArray(allId, totalNum); // Free the temp array.

    return isValid;
}


VfxS32 VappScreenLockFactory::getName(
    const VappScreenLockId &id,
    VfxWChar *string,
    VfxS32 size)
{
    VappScreenLock *screenLock;
    VfxS32 length;

    // This object is for temp usage. Close it before we leave this function.
    screenLock = createScreenLock(id, VFX_SYS_GLOBAL_CONTEXT);
    if (!screenLock)
    {
        return 0;
    }

    length = screenLock->getName(string, size);

    VFX_OBJ_CLOSE(screenLock); // Close the temp object.

    return length;
}


VfxFrame *VappScreenLockFactory::createIcon(
    const VappScreenLockId &id,
    VfxObject *parentObj)
{
    VappScreenLock *screenLock;
    VfxFrame *icon;

    screenLock = createScreenLock(id, parentObj);
    if (!screenLock)
    {
        return NULL;
    }

    icon = screenLock->createIcon(parentObj);

    VFX_OBJ_CLOSE(screenLock);

    return icon;
}


VfxS32 VappScreenLockFactory::getScreenshotNum(const VappScreenLockId &id)
{
    VappScreenLock *screenLock;
    VfxS32 numSnapshot;

    // This object is for temp usage. Close it before we leave this function.
    screenLock = createScreenLock(id, VFX_SYS_GLOBAL_CONTEXT);
    if (!screenLock)
    {
        return 0;
    }

    numSnapshot = screenLock->getScreenshotNum();

    VFX_OBJ_CLOSE(screenLock); // Close the temp object.

    return numSnapshot;
}


VfxFrame **VappScreenLockFactory::createScreenshot(
    const VappScreenLockId &id,
    VfxObject *parentObj)
{
    VappScreenLock *screenLock;

    screenLock = createScreenLock(id, parentObj);
    if (!screenLock)
    {
        return NULL;
    }

    VfxFrame **snapshot;
    snapshot = screenLock->createScreenshot(parentObj);

    VFX_OBJ_CLOSE(screenLock);

    return snapshot;
}

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) */

