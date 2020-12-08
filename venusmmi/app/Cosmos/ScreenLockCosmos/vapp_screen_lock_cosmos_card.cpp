/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  vapp_screen_lock_card.cpp
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

#include "MMI_features.h" 

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

#include "vapp_screen_lock_cosmos_card.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"


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
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockCard", VappScreenLockCard, VappScreenLockUnlockItem);


VappScreenLockCard::VappScreenLockCard():
    m_unlockHint(0),
    m_imgPress(NULL),
    m_imgUnpress(NULL),
    m_imgIcon(NULL),
    m_imgIconDot(NULL),
    m_imgIconArrow(NULL),
    m_textMissNum(NULL),
    m_missNum(NULL)
{  
}

void VappScreenLockCard::setClicked()
{
    m_imgPress->setOpacity(1);
    m_imgUnpress->setOpacity(0);

    onClicked();
}

void VappScreenLockCard::setReleased()
{
    m_imgPress->setOpacity(0);
    m_imgUnpress->setOpacity(1);

    onReleased();
}

void VappScreenLockCard::setUnlocked()
{
    onUnlocked();
}

void VappScreenLockCard::onClicked()
{
}

void VappScreenLockCard::onReleased()
{
}

void VappScreenLockCard::onUnlocked()
{
}


void VappScreenLockCard::onInit()
{
    VfxControl::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);

    VFX_OBJ_CREATE(m_imgUnpress, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imgPress, VfxImageFrame, this);

    m_imgPress->setResId(IMG_ID_VAPP_SCREEN_LOCK_CLICKED_CARD);
    m_imgPress->setOpacity(0); 

    m_imgPress->setAutoAnimate(VFX_TRUE);
    m_imgUnpress->setAutoAnimate(VFX_TRUE);  

    setSize(m_imgPress->getSize());

    VFX_OBJ_CREATE(m_imgIconArrow, VfxImageFrame, this);
    m_imgIconArrow->setResId(IMG_ID_VAPP_SCREEN_LOCK_CARD_ICON_ARROW);
    m_imgIconArrow->setAnchor(0.5, 0); 
    m_imgIconArrow->setPos(getSize().width/2, VAPP_SCREEN_LOCK_CARD_MINI_ARROW_Y); 

    setCacheMode(VFX_CACHE_MODE_FORCE);
}

void VappScreenLockCard::onDeinit()
{
    VfxControl::onDeinit();

}

#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
