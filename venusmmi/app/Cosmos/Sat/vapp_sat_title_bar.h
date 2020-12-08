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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_sat_title_bar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SAT Title bar Class header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SAT_TITLE_BAR_H__
#define __VAPP_SAT_TITLE_BAR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"


/*****************************************************************************
  * Class VappSatBaseTitleBar
  *****************************************************************************/

class VappSatBaseTitleBar : public VfxPageBar
{
    //VFX_DECLARE_CLASS(VappSatBaseTitleBar);

// Constructor / Destructor
public: 
    VappSatBaseTitleBar();
    virtual ~VappSatBaseTitleBar(){};

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

public:
    void setIconAndString(const VfxImageSrc &imgScr, const VfxWString &string);

private:
    void setShodow();
    void setMarquee();
    void updateBackground();
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    void updateImageFrame();
#endif //__SAT_DISABLE_ICON_SUPPORT__
    void onBoundsChanged(VfxFrame *frame, const VfxRect &old);

private:
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VfxImageSrc getIcon() const;
#endif
    VfxWString getString() const;

private:
    VfxImageFrame *m_background;

    VfxImageSrc m_icon;
    VfxWString  m_string;

    VfxImageFrame   *m_imageFrame;
    VcpMarquee      *m_marquee;

    VfxS32  m_xPos;
    VfxS32  m_yPos;
    VfxS32  m_textWidth;
    VfxS32  m_dispWidth;

private:
    enum
    {
    #if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_HEIGHT = 50, 
    #elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_HEIGHT = 85,
    #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        DEFAULT_HEIGHT = 50,
    #else
        DEFAULT_HEIGHT = 50,
    #endif
        SIDE_MARGIN = 50
    };
};

#endif /* __VAPP_SAT_TITLE_BAR_H__ */
