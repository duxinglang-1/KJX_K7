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
 *  vcp_waiting_icon.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Waiting icon component header
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

#ifndef __VCP_WAITING_ICON_H__
#define __VCP_WAITING_ICON_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpWaitingIcon
 *****************************************************************************/
class VcpWaitingIconShell : public VfxControl
{
    enum
    {        
        WIDTH           = 50,
        HEIGHT          = 50,
        BALL_NUM        = 8,
        REPEAT_DURATION = 2000,
        BALL_TIME       = REPEAT_DURATION / BALL_NUM
    };
public:
    enum
    {
        TYPE_NORMAL = 0,
        TYPE_HIGHLIGHT
    };
// Constructor / Destructor
public:
     VcpWaitingIconShell()
     {
        for (VfxS32 i = 0; i < BALL_NUM; i++)
        {
            m_ball[i] = NULL;
            m_ballTl[i * 2] = NULL;
            m_ballTl[i * 2 + 1] = NULL;        
        }  
     }
     void     onPlay(VfxS32 visualType);
protected:
    virtual void        onInit();
private:
    VfxImageFrame           *m_ball[BALL_NUM];
    VfxTransformTimeline    *m_ballTl[BALL_NUM * 2];

    void onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);        
};

class VcpWaitingIcon : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Constructor/Destructor>
    VcpWaitingIcon() : 
        m_isAnimating(VFX_FALSE),
        m_isHiddenWhenStopped(VFX_TRUE),
        m_image(NULL)
    {
    }

// Method
public:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Method>
    // start animation
    void start();

    // <group DOM_WaitingIcon_VcpWaitingIcon_Method>
    // stop animation    
    void stop();

    // <group DOM_WaitingIcon_VcpWaitingIcon_Method>
    // Returns whether animation is running
    // RETURNS: VFX_TRUE if animation is running, otherwise VFX_FALSE
    VfxBool isAnimating()
    {
        return m_isAnimating;
    }

    // <group DOM_WaitingIcon_VcpWaitingIcon_Method>
    // Gets hidden when stopped flag
    // RETURNS: hidden when stopped flag
    VfxBool getHiddenWhenStopped() const
    {
        return m_isHiddenWhenStopped;
    }

    // <group DOM_WaitingIcon_VcpWaitingIcon_Method>
    // Sets auto hidden when stopped
    void setHiddenWhenStopped(
        VfxBool isHiddenWhenStopped     // [IN] hidden when stopped flag
    )
    {
        m_isHiddenWhenStopped = isHiddenWhenStopped;
    }

// Overridable:
public:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Overridable>
    virtual void setBounds(const VfxRect &value);

// Overridable
protected:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Overridable>
    virtual void onInit();

// Implementation
private:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Implementation>
    void onSize(const VfxRect &bounds);

// Variable
private:
    // <group DOM_WaitingIcon_VcpWaitingIcon_Variable>
    VfxBool m_isAnimating;
    // <group DOM_WaitingIcon_VcpWaitingIcon_Variable>
    VfxBool m_isHiddenWhenStopped;

    // <group DOM_WaitingIcon_VcpWaitingIcon_Variable>
    VcpWaitingIconShell *m_image;
};


#endif /* __VCP_WAITING_ICON_H__ */


