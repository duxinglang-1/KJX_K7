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
 *  vapp_screen_lock_msg_card.h
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

#ifndef __VAPP_SCREEN_LOCK_COSMOS_MSG_CARD_H__
#define __VAPP_SCREEN_LOCK_COSMOS_MSG_CARD_H__

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_screen_lock_cosmos_card.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    
#include "UmSrvGprot.h"
    
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET              25  
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_Y_OFFSET                18 
#define VAPP_SCREEN_LOCK_CARD_TEXT_NUM_Y_OFFSET                 0

#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET              10  
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_Y_OFFSET                 4 
#define VAPP_SCREEN_LOCK_CARD_TEXT_NUM_Y_OFFSET                 0

#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
#define VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET              10    // 17 -7
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_Y_OFFSET                 8    // 29-19  
#define VAPP_SCREEN_LOCK_CARD_TEXT_NUM_Y_OFFSET                 2

#else 
#define VAPP_SCREEN_LOCK_CARD_ICON_ARROW_Y_OFFSET              22  
#define VAPP_SCREEN_LOCK_CARD_ICON_DOT_Y_OFFSET                 5 
#define VAPP_SCREEN_LOCK_CARD_TEXT_NUM_Y_OFFSET                 0

#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappScreenLockMsgCard : public VappScreenLockCard
{
    VAPP_SCREEN_LOCK_UNLOCK_ITEM_DECLARE_CLASS(VappScreenLockMsgCard);

public:
    VappScreenLockMsgCard();

// Overridable
protected:
    virtual void onClicked();
    virtual void onReleased();
    virtual void onUnlocked();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public:
    static mmi_ret eventHandler(mmi_event_struct *event); 

private:
    VfxBool updateMsgNum();
    VfxU32 getUnreadMsgNum();
    void setMissNum(VfxU32 num);

// Variable
private:
    VfxS32 m_missNum;
    VfxSize oriDotSize;
};
#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
#endif /* __VAPP_SCREEN_LOCK_COSMOS_MSG_CARD_H__ */
