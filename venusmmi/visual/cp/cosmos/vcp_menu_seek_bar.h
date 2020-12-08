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
 *  vcp_menu_seek_bar.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Menu Seek Bar component
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================ 
 * HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_MENU_SEEK_BAR_H__
#define __VCP_MENU_SEEK_BAR_H__
 
/***************************************************************************** 
 * Include
*****************************************************************************/
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_object_list.h"
#include "vfx_text_frame.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

#if defined(__MMI_VUI_COSMOS_CP__) 
/***************************************************************************** 
 * Define
*****************************************************************************/

#define VCP_MENU_SEEK_BAR_MAX_ITEM_COUNT (28)


#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_REL_HINT_POSITION  (30) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_REL_HINT_POSITION  (64)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_REL_HINT_POSITION  (17)
#else
    #define VCP_MENU_SEEK_BAR_REL_HINT_POSITION  (17) 
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_HINT_FONT_SIZE    (60) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_HINT_FONT_SIZE    (90)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_HINT_FONT_SIZE    (45)
#else
    #define VCP_MENU_SEEK_BAR_HINT_FONT_SIZE    (45) 
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_HINT_SIZE    (90) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_HINT_SIZE    (132)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_HINT_SIZE    (66)     
#else
    #define VCP_MENU_SEEK_BAR_HINT_SIZE    (66) 
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN    (10) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN    (14)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN    (5) 
#else
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN    (5) 
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TT_MARGIN    (14) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TT_MARGIN    (16)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TT_MARGIN    (10)
#else
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TT_MARGIN    (10) 
#endif

#if defined(__MMI_MAINLCD_320X480__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TB_MARGIN    (6) 
#elif defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TB_MARGIN    (4)
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TB_MARGIN    (2)
#else
    #define VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TB_MARGIN    (2) 
#endif

#if defined(__MMI_MAINLCD_480X800__)
    #define VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE    (80)
#else
    #define VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE    (40)
#endif


enum VcpMenuSeekBarEnum
{
    VCP_MENUSEEKBAR_STATE_NORMAL,            // normal state
    VCP_MENUSEEKBAR_STATE_PRESSED,           // pressed state

    VCP_MENUSEEKBAR_STATE_END_OF_ENUM        // end of the enum
};

enum VcpMenuSeekBarWidthEnum 
{
#if defined(__MMI_MAINLCD_320X480__)
        VCP_MENU_SEEK_BAR_DEFAULT_WIDTH = 6,
#elif defined(__MMI_MAINLCD_480X800__)
        VCP_MENU_SEEK_BAR_DEFAULT_WIDTH = 8,
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        VCP_MENU_SEEK_BAR_DEFAULT_WIDTH = 6,
#else 
        VCP_MENU_SEEK_BAR_DEFAULT_WIDTH = 6 
#endif
};    



/***************************************************************************** 
 * Class VcpMenuSeekBarItem
*****************************************************************************/
class VcpMenuSeekBarItem : public VfxObject
{
   // VFX_DECLARE_CLASS(VcpMenuSeekBarItem);
    // Public or protected inside nested class?
    public:
        // <group DOM_MenuSeekBar_VcpMenuSeekBarItem_Constructor/Destructor>
        // Default constructor
        VcpMenuSeekBarItem();
        // <group DOM_MenuSeekBar_VcpMenuSeekBarItem_Property>
        // String for MenuSeekBarItem 
        VfxWString m_string_item;  
        // <group DOM_MenuSeekBar_VcpMenuSeekBarItem_Property>
        // Image Src for MenuSeekBarItem
        VfxImageSrc m_image_item;
        // <group DOM_MenuSeekBar_VcpMenuSeekBarItem_Property>
        // Identifier for MenuSeekBarItem
        VfxId id;
};



/***************************************************************************** 
 * Class VcpMenuSeekBar
 *****************************************************************************/
class VcpMenuSeekBar : public VfxControl
{
    VFX_DECLARE_CLASS(VcpMenuSeekBar);

// Constructor / Destructor
public:
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Constructor/Destructor>
    // Default constructor.
    VcpMenuSeekBar();

// Event
public:
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Event>
    // This signal is invoked when menu seek bar is touched (on pen event down or move)
    // void YourClass::onSeekBarTouched(VfxId id)    
    VfxSignal1 <VfxId> m_signalMenuSeekBarTouch;
// Overridable
public:
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Add one Text item    
    virtual void addTextItem (
        VfxId id,                       // [IN] menu seek bar item ID
        const VfxWString &text          // [IN] text
    );
    
    virtual void addTextItem(
        VfxId id,
        VfxResId resId);
    
    virtual void addTextItem(
        VfxId id,
        const VfxWChar *text);
    
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Insert one Text item before a particular item
    virtual void insertTextItem (
        VfxId id,                       // [IN] menu seek bar item ID
        VfxResId resId,         // [IN] text 
        VfxId beforeId);                   // [IN] before menu seek bar item ID

    virtual void insertTextItem (
        VfxId id,                       // [IN] menu seek bar item ID
        const VfxWChar *text,         // [IN] text 
        VfxId beforeId);                   // [IN] before menu seek bar item ID
   
    virtual void insertTextItem (
        VfxId id,                       // [IN] menu seek bar item ID
        const VfxWString &text,         // [IN] text 
        VfxId beforeId                   // [IN] before menu seek bar item ID
    ); 
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Add one Image Item.
    virtual void addImageItem (
        VfxId id,                       // [IN] menu seek bar item ID
        const VfxImageSrc &img          // [IN] image
    );
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Insert one Image item before a particular item
    virtual void insertImageItem (
        VfxId id,                       // [IN] menu seek bar item ID
        const VfxImageSrc &img,         // [IN] image 
        VfxId beforeId                   // [IN] before menu seek bar item ID
    ); 

    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Deletes a seek bar Item
    virtual void deleteItem (
        VfxId id                        // [IN] menu seek bar item ID
    );
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Clears all seek bar items
    virtual void clearAllItems ();
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Gets maximum number of seek bar items supported
    // RETURNS: VfxS32
    virtual VfxS32 getMaxItemCount(void);
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Overridable>
    // Sets height of the menu seek bar control
    virtual void setHeight(VfxS32 height );
	
// Override
protected:
    //<group DOM_MenuSeekBar_VcpMenuSeekBar_Override>
    // On init
    virtual void onInit();
    //<group DOM_MenuSeekBar_VcpMenuSeekBar_Override>
    // On update
    virtual void onUpdate();
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Override>
    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );
	
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Override>
    // Checks if the frame contains the specified point
    // RETURNS: VFX_TRUE if the clip bound of the frame contains the point

    virtual VfxBool onContainPoint(const VfxPoint &point) const;

// Implementation
private:
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // List of item
    VfxObjList m_list;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Number of items
    VfxS32 m_count;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Max. height of an item 
    VfxS32 m_maxItemHeight;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Hilighted item   
    VfxId m_highlightedId;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Text frame for seek bar hint 
    VfxTextFrame *m_textFrame;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Image frame for seek bar hint 
    VfxFrame * m_imageFrame;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // state of menu seek bar
    VcpMenuSeekBarEnum m_state;
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // update while bounds change
    void onBoundsChanged (VfxFrame *frame, const VfxRect &old) 
    {
        checkUpdate();
    }
    
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Converts y coordinate of pen input to MenuSeekBarItem Index
    VfxS32 convertYToIndex(VfxS32 y);
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Get the MenuSeekBarItem at the given index in the MenuSeekBar
    VcpMenuSeekBarItem* getItemFromMenuSeekBar(VfxS32 index);

    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Resets button state
    void resetMenuSeekBarState();
    // <group DOM_MenuSeekBar_VcpMenuSeekBar_Implementation>
    // Sets the MenuSeekBarItem's String or Image in the Hint of MenuSeekBar
    void setItemToHint(VcpMenuSeekBarItem * item, VfxS32 y);
	void insertItemInt(VcpMenuSeekBarItem *item, VfxId beforeId);
};


#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */
#endif /* __VCP_MENU_SEEK_BAR_H__ */

