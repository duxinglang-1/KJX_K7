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
 *  vapp_screen_lock_card.h
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

#ifndef __VAPP_SCREEN_LOCK_COSMOS_CARD_H__
#define __VAPP_SCREEN_LOCK_COSMOS_CARD_H__

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vapp_screen_lock_unlock_item.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SCREEN_LOCK_CARD_MINI_ARROW_Y                     55  // 20 + 35(upper space of card img)
#define VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD     35
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_WIDTH                   65
#define VAPP_SCREEN_LOCK_MISS_NUM_STR_SIZE                     23
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_SCREEN_LOCK_CARD_MINI_ARROW_Y                     28  // 10 + 18(upper space of card img)
#define VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD     18 
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_WIDTH                   42
#define VAPP_SCREEN_LOCK_MISS_NUM_STR_SIZE                     15
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_SCREEN_LOCK_CARD_MINI_ARROW_Y                     23
#define VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD     20
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_WIDTH                   34
#define VAPP_SCREEN_LOCK_MISS_NUM_STR_SIZE                     12
#else
#define VAPP_SCREEN_LOCK_CARD_MINI_ARROW_Y                     40  // 10 + 30(upper space of card img)
#define VAPP_SCREEN_LOCK_CARD_OFFSET_BTW_IMG_AND_REAL_CARD     15
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_WIDTH                   34
#define VAPP_SCREEN_LOCK_MISS_NUM_STR_SIZE                     12
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappScreenLockCard : public VappScreenLockUnlockItem
{
    VFX_DECLARE_CLASS(VappScreenLockCard);

public:
    VappScreenLockCard();

// Method
public:
    void setClicked();
    void setReleased();
    void setUnlocked();

// Overridable
protected:
    virtual void onClicked();
    virtual void onReleased();
    virtual void onUnlocked();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Variable
public:

    // hint string id
    MMI_STR_ID    m_unlockHint;
        
protected:
    VfxImageFrame *m_imgUnpress;
    VfxImageFrame *m_imgPress;

    // app icon
    VfxImageFrame *m_imgIcon;

    // small arrow on card
    VfxImageFrame *m_imgIconArrow;

    // miss number
    VfxImageFrame *m_imgIconDot;
    VfxTextFrame *m_textMissNum;
    VfxS32 m_missNum; 
};

#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
#endif /* __VAPP_SCREEN_LOCK_COSMOS_CARD_H__ */

