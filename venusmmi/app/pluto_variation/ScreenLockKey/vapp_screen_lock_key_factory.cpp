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
 *  vapp_screen_lock_key_factory.cpp
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_factory.h"
#include "vapp_screen_lock_key_unlock.h"
#include "vapp_screen_lock_key_unlockitem.h"
#include "vapp_screen_lock_key_unlock_centry.h"
#include "vapp_screen_lock_key_unlock_default.h" 
#include "vapp_screen_lock_key_unlock_calllog.h"
#include "vapp_screen_lock_key_unlock_msg.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Macro to add a unlock item .
 */
#define VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_ADD(_id, _class)   		\
    VappScreenLockKeyFactory::CreateUnlockEntity(      			\
        _id,                                                \
        _class::createUnlockCard)

#define VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_END()              		\
    VappScreenLockKeyFactory::CreateUnlockEntity(      			\
        VAPP_SCREEN_LOCK_KEY_UNLOCK_INVALID,          			\
        NULL)

/*****************************************************************************
 * Function
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockKeyFactory", VappScreenLockKeyFactory, VfxObject);


/*----------------------------------------------------------------*/
/* unlock card config table                                       */
/*----------------------------------------------------------------*/

const VappScreenLockKeyFactory::CreateUnlockEntity VappScreenLockKeyFactory::s_unlockTbl[] = 
{
	VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_ADD(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_LOCK,
		VappScreenLockKeyUnlockCentry),

	VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_ADD(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_DEFAULT,
		VappScreenLockKeyUnlockDefault),

	VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_ADD(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_CALL_LOG,
		VappScreenLockKeyUnlockCallLog),

	VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_ADD(
		VAPP_SCREEN_LOCK_KEY_UNLOCK_MESSAGE,
		VappScreenLockKeyUnlockMsg),
		
	VAPP_SCREEN_LOCK_KEY_UNLOCK_CFG_END()
};


VappScreenLockKeyUnlockItem* VappScreenLockKeyFactory::getUnlock(VappKLScrlockUnlockTypeEnum unlockId, VfxObject *pParent)
{
	if (unlockId >= VAPP_SCREEN_LOCK_KEY_UNLOCK_END)
		return NULL;

	VfxS32 i;

	for(i = 0; i < VAPP_SCREEN_LOCK_KEY_UNLOCK_END; i++)
	{
		if (unlockId == s_unlockTbl[i].m_type)
			break;
	}

	VFX_ASSERT(s_unlockTbl[i].m_create);

    return (VappScreenLockKeyUnlockItem *)s_unlockTbl[i].m_create(pParent);
}


#endif

