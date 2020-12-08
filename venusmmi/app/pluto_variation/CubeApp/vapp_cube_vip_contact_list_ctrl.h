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
 *  vapp_shell_listctrl.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  vip contact screen
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CUBE_VIP_CONTACT_LIST_CTRL_H__
#define __VAPP_CUBE_VIP_CONTACT_LIST_CTRL_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
    #include "vcp_scrollable.h"
    #include "vfx_frame.h"
    #include "vfx_control.h"
    #include "vfx_object.h"
    #include "vfx_class_info.h"
    #include "vfx_datatype.h"
    #include "vfx_string.h"
    #include "vfx_font_desc.h"
    #include "vfx_cpp_base.h"
    #include "vfx_input_event.h"
    #include "vfx_signal.h"
    #include "vfx_primitive_frame.h"
    #include "vfx_text_frame.h"
    #include "vfx_basic_type.h"
    #include "vfx_animation.h"

/*
 * VappScrollCtrl is a simple scrollable view inherited from VcpScrollable
 *
 * EXAMPLE:
 * <code>
 *   VFX_OBJ_CREATE(m_scrollable, VappScrollCtrl, this);
 *   m_scrollable->setPos(VfxPoint(MAIN_POS_X, MAIN_POS_Y));
 *   m_scrollable->setBounds(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT));
 *   m_scrollable->setContentSize(VfxSize(MAIN_WIDTH, NUM_OF_ALM * VappHsWidgetAlarmItem::HEIGHT));
 *   m_scrollable->setViewRect(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT)); 
 * </code>
 */
class VappScrollCtrl : public VcpScrollable
{
public:
    VappScrollCtrl();

public:
    virtual VfxFrame *getFirstItem();
    virtual VfxFrame *getLastItem();
};


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappListCtrlItem : public VfxControl
{
    VFX_DECLARE_CLASS(VappListCtrlItem);

public:

    enum{
        TEXT_POS_X = 30
        };
    
    VappListCtrlItem();
    void setContent(
            const VfxS32 &imgId,    //[IN] image id for this list item
            const VfxWString &text  //[IN] text on this list item
            );
    void getText(
            VfxWString &text        //[OUT] text on this item
            ) const;
    
    void setData(
            void* data              //[IN] user data
            );
    void* getData(void) const;

    void setFont(const VfxFontDesc &font);
    void setTextStartPos(const VfxS32 &x);
    
//Override
protected:
    virtual void onInit(void);
    virtual VfxBool onPenInput(VfxPenEvent & event);
    
    void update(VfxS32 margin);

public:
    VfxSignal1<void *> m_signalSel;
    
private:
    
    VfxImageFrame *m_frmImage;
    VfxTextFrame  *m_frmText;  
    void          *m_pUserData;
    VfxS32         m_nTxtStart;
};


/***************************************************************************** 
 * Class VappListCtrl
 *****************************************************************************/
class VappListCtrl : public VfxControl
{
// enum
public:
    enum{
        SCROLL_WIDTH = 6,
        X_SHIFT = 2,
        Y_SHIFT = 2,
        MARGIN = 5
    };
//typedef
public:
 
    typedef struct{
        VfxS8 flag;
        VfxS8 iItem;
        VfxS8 iItemHeight;
        VfxS8 iImageWidth;
        VfxS32 imgId;
        VfxWString string;
        void *userData;
    }LC_ITEM;
// Constructor / Destructor
public:
    VappListCtrl(const VfxBool &scroll = VFX_FALSE);
// Method
public:
    VfxU16 insertItem(
            const LC_ITEM &item     //[IN] item struct
            );

    VfxS8 getCurrSel(void) const;
    void  setCurrSel(
        const VfxU8 &pos        //[IN] the current position
        );
    void clearAll(void);
    void setTextColor(const VfxColor &color);
    void setFont(const VfxFontDesc &font);
    void setHighlightRes(const VfxS32 &resId);
    
private:
    // Shift the list item, to make press-down effect
    void shiftItem(
        VfxFrame *target,       //[IN] the target frame who will be shifted
        const VfxS32 &xOffset,  //[IN] x offset
        const VfxS32 &yOffset   //[IN] y offset
        );
    void onBoundsValueChange(
        VfxFrame *source,
        const VfxRect &oldBounds
        );
    void onTimelineStop(
        VfxBaseTimeline *source,//[IN] time line pointer
        VfxBool stop            //[IN] whether stopped
        );
    
    VfxFrame * hitTestChild(const VfxPoint &point) const;
    
    void onItemSel(void *usrData);
// Override
protected:
    virtual void onInit();
    virtual void onAddChild(VfxObject * objChild);
    virtual void onDeinit();
    virtual VfxBool onPenInput(
                VfxPenEvent &event  //[IN] pen event
                );

// Signal
public:
    VfxSignal1<void*> m_signalSelChange;

// Variable
private:

    VappScrollCtrl   *m_cpScroll;   // scroll container for all list item
    VfxPointTimeline *m_tlPoint;    // time line for shift item
    VfxFrame         *m_frmCurr;    // current highlight item
    VfxFrame         *m_frmHilite;  // highlight frame
    VfxImage         *m_imgBg;      // backgournd image

    VfxU16           m_uCount;
    VfxBool          m_bShifting;   // if TRUE, the highlihgt frame is moving
    VfxFontDesc      m_itemFont;
    VfxColor         m_clrTxt;
    VfxBool          m_bScroll;
};

#endif /* __VAPP_CUBE_VIP_CONTACT_LIST_CTRL_H__ */

