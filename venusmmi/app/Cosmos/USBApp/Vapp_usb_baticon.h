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
 *  vapp_usb_baticon.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_USB_BATICON_H__
#define __VAPP_USB_BATICON_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_usbmmi_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __USB_MMI_DEBUG__
#ifndef __MTK_TARGET__

#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct
{
    MMI_IMG_ID imgId;
    VfxS32      x;
    VfxS32      y;
    VfxS32      width;
    VfxS32      height;
} LevelInfoStruct;

typedef struct
{
    VfxU8 block[3];
} LevelBlinkMapStruct;

static const LevelInfoStruct m_levelInfo[] = 
{
#if defined(__MMI_MAINLCD_320X480__)
    {IMG_ID_VAPP_USB_BATTERY_LEVEL1, 6, 4, 34, 45},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL2, 41, 4, 34, 45},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL3, 76, 4, 34, 45}
#elif defined(__MMI_MAINLCD_480X800__)
    {IMG_ID_VAPP_USB_BATTERY_LEVEL1, 13, 10, 57, 74},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL2, 71, 10, 58, 74},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL3, 130, 10, 57, 74}
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
    {IMG_ID_VAPP_USB_BATTERY_LEVEL1, 6, 5, 25, 30},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL2, 32, 5, 25, 30},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL3, 58, 5, 25, 30}
#else
    {IMG_ID_VAPP_USB_BATTERY_LEVEL1, 6, 4, 34, 45},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL2, 41, 4, 34, 45},
    {IMG_ID_VAPP_USB_BATTERY_LEVEL3, 76, 4, 34, 45}
#endif
};

static const LevelBlinkMapStruct level1BlinkMap[] = 
{
    {0, 0, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 1},
    {255, 1, 1}
};

static const LevelBlinkMapStruct level2BlinkMap[] = 
{
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 1},
    {255, 1, 1}
};

static const LevelBlinkMapStruct level3BlinkMap[] = 
{
    {1, 1, 0},
    {1, 1, 1},
    {255, 1, 1}
};

static const LevelBlinkMapStruct *levelBlinkMap[] = 
{
    level1BlinkMap,
    level2BlinkMap,
    level3BlinkMap
};

class VappUSBBatIcon : public VfxFrame
{

public:
    typedef enum
    {
        STATE_STATIC = 0,
        STATE_BLINK,
        STATE_MAX
    } StateEnum;

    typedef enum
    {
        LEVEL_0 = 0,
        LEVEL_1,
        LEVEL_2,
        LEVEL_3,
        LEVEL_COUNT = LEVEL_3,
        LEVEL_MAX_ITEM
    } LevelEnum;

private:
    

    #define BORDER_POS_X    0
    #define BORDER_POS_Y    0
#if defined(__MMI_MAINLCD_320X480__)
    #define BORDER_POS_WIDTH    121
    #define BORDER_POS_HEIGHT   57
#elif defined(__MMI_MAINLCD_480X800__)
    #define BORDER_POS_WIDTH    205
    #define BORDER_POS_HEIGHT   100
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
    #define BORDER_POS_WIDTH    93
    #define BORDER_POS_HEIGHT   45
#else
    #define BORDER_POS_WIDTH    121
    #define BORDER_POS_HEIGHT   57
#endif

    
public:
    VappUSBBatIcon()
    {
        m_border = NULL;
        m_timer = NULL;
        m_state = STATE_STATIC;
        m_level = LEVEL_0;
        m_blinkIndex = 0;
        for(S32 i = 0; i < LEVEL_COUNT; i++)
        {
            m_block[i] = NULL;
        }
    }
    virtual ~VappUSBBatIcon()
    {
    }

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    //virtual void onDraw(VfxDrawContext &dc);

public:
    void update(StateEnum state, LevelEnum level);
    VfxBool updateLevel(LevelEnum level, VfxBool blink);
    VfxU8 getLevelCount(void);
    StateEnum getCurState(void);
    LevelEnum getCurLevel(void);

private:
    void createTimer(void);
    void closeTimer(void);
    void startTimer(void);
    void stopTimer(void);
    void stopBlink(void);
    void startBlink(void);
    void createBlock(LevelEnum level);
    void deleteBlock(LevelEnum level);
    void createBorder(void);
    void onTimer(VfxTimer *source);
        
    inline VfxS32 getX(LevelEnum level)
    {
        return m_levelInfo[level].x;
    }
    inline VfxS32 getY(LevelEnum level)
    {
        return m_levelInfo[level].y;
    }
    inline VfxS32 getWidth(LevelEnum level)
    {
        return m_levelInfo[level].width;
    }
    inline VfxS32 getHeight(LevelEnum level)
    {
        return m_levelInfo[level].height;
    }
    inline MMI_IMG_ID getLevelImgId(LevelEnum level)
    {
        return m_levelInfo[level].imgId;
    }
    
private:
    VfxFrame *m_border;
    VfxFrame *m_block[LEVEL_COUNT];
    VfxTimer      *m_timer;
    StateEnum     m_state;
    LevelEnum     m_level;
    VfxU8            m_blinkIndex;
    static const VfxU16   m_blinkDur = 500;
};

#endif /* __VAPP_USB_BATICON_H__*/
