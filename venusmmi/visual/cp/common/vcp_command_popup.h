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
 *  vcp_command_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Command popup
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
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_COMMAND_POPUP_H__
#define __VCP_COMMAND_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_uc_include.h"
#include "vcp_frame_effect.h"
#include "vcp_button.h"
#include "vcp_text_editor.h"
#include "vcp_scrollable.h"
#include "vcp_popup_data_type.h"

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_CommandPopup_Macro&Enum_Macro>
    // Maximum number of buttons on command popup.
    #define VCP_COMMAND_POPUP_BUTTON_MAX_COUNT      (7)
#else
    #define VCP_COMMAND_POPUP_BUTTON_MAX_COUNT      (6)
#endif

#if defined(__MMI_MAINLCD_480X800__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_COMMAND_POPUP_WIDTH                         (480)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (800)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (37)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (4)
    
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (623)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (332)
    
        #define VCP_COMMAND_POPUP_ICON_X                        (57)
        #define VCP_COMMAND_POPUP_ICON_Y                        (68)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
    
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (19)
        #define VCP_COMMAND_POPUP_TEXT_X                        (16)    
        #define VCP_COMMAND_POPUP_TEXT_Y                        (31)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT                   (33)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (448)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (768)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (448)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (768)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (30)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (18)
    
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (10)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (20)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (10)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (440)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (768)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (70)
    #else
        #define VCP_COMMAND_POPUP_WIDTH                         (480)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (800)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (37)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (4)
    
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (623)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (332)
    
        #define VCP_COMMAND_POPUP_ICON_X                        (57)
        #define VCP_COMMAND_POPUP_ICON_Y                        (68)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
    
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (19)
        #define VCP_COMMAND_POPUP_TEXT_X                        (16)    
        #define VCP_COMMAND_POPUP_TEXT_Y                        (31)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT                   (33)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (448)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (768)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (448)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (768)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (30)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (18)
    
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (10)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (20)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (10)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (440)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (768)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (70)
    #endif
#elif defined(__MMI_MAINLCD_320X480__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_COMMAND_POPUP_WIDTH                         (320)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (480)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (23)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (15)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (359)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (203)
    
        #define VCP_COMMAND_POPUP_ICON_X                        (48)
        #define VCP_COMMAND_POPUP_ICON_Y                        (40)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (12)
        #define VCP_COMMAND_POPUP_TEXT_X                        (13)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (23)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT                   (20)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (295)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (455)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (295)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (455)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (18)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (10)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (15)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (13)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (5)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (295)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (455)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (47)
    #else
        #define VCP_COMMAND_POPUP_WIDTH                         (278)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (250)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (32)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (22)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (359)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (255)
        
        #define VCP_COMMAND_POPUP_ICON_X                        (48)
        #define VCP_COMMAND_POPUP_ICON_Y                        (40)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (41)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (41)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (82)
        #define VCP_COMMAND_POPUP_TEXT_X                        (15)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (21)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT			        (18)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (183)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (455)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (250)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (455)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (18)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (10)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (15)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (15)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (7)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (4)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (250)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (455)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (45)
    #endif
#elif defined(__MMI_MAINLCD_240X400__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_COMMAND_POPUP_WIDTH                         (240)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (400)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (17)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (10)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (368)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (180)
    
        #define VCP_COMMAND_POPUP_ICON_X                        (32)
        #define VCP_COMMAND_POPUP_ICON_Y                        (29)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (7)
        #define VCP_COMMAND_POPUP_TEXT_X                        (8)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (17)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT			        (18)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (224)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (384)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (224)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (384)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (16)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (8)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (8)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (8)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (5)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (224)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (384)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (40)
    #else
        #define VCP_COMMAND_POPUP_WIDTH                         (230)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (400)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (32)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (19)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (359)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (203)

        #define VCP_COMMAND_POPUP_ICON_X                        (40)
        #define VCP_COMMAND_POPUP_ICON_Y                        (38)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (34)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (34)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (67)
        #define VCP_COMMAND_POPUP_TEXT_X                        (23)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (21)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT			        (20)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (139)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (355)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (196)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (355)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (18)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (10)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (15)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (15)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (5)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (1)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (202)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (355)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (45)
    #endif
#elif defined(__MMI_MAINLCD_240X320__)
    #if defined(__MMI_VUI_COSMOS_CP__)
        #define VCP_COMMAND_POPUP_WIDTH                         (240)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (320)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (17)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (10)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (278)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (180)
    
        #define VCP_COMMAND_POPUP_ICON_X                        (32)
        #define VCP_COMMAND_POPUP_ICON_Y                        (29)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (7)
        #define VCP_COMMAND_POPUP_TEXT_X                        (8)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (17)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT                   (18)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (224)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (304)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (224)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (304)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (16)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (8)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (8)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (8)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (5)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (224)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (304)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (40)
    #else
        #define VCP_COMMAND_POPUP_WIDTH                         (230)
        #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (320)
        #define VCP_COMMAND_POPUP_UP_HEIGHT                     (32)
        #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (19)
        
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (280)
        #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (203)

        #define VCP_COMMAND_POPUP_ICON_X                        (40)
        #define VCP_COMMAND_POPUP_ICON_Y                        (38)
        #define VCP_COMMAND_POPUP_ICON_WIDTH                    (34)
        #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (34)
         
        #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (67)
        #define VCP_COMMAND_POPUP_TEXT_X                        (23)
        #define VCP_COMMAND_POPUP_TEXT_Y                        (21)
        #define VCP_COMMAND_POPUP_TEXT_HEIGHT			        (18)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (139)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (235)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (196)
        #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (235)
        #define VCP_COMMAND_POPUP_TEXT_SIZE                     (18)
        #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (10)
        
        #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (15)
        #define VCP_COMMAND_POPUP_BUTTON_X                      (15)
        #define VCP_COMMAND_POPUP_BUTTON_Y                      (5)
        #define VCP_COMMAND_POPUP_BUTTON_GAP                    (1)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (202)
        #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (235)
        #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (45)
    #endif
#else
    #define VCP_COMMAND_POPUP_WIDTH                         (240)
    #define VCP_COMMAND_POPUP_WIDTH_LANDSCAPE               (320)
    #define VCP_COMMAND_POPUP_UP_HEIGHT                     (17)
    #define VCP_COMMAND_POPUP_BOTTOM_HEIGHT                 (10)
    
    #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (278)
    #define VCP_COMMAND_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE    (180)

    #define VCP_COMMAND_POPUP_ICON_X                        (32)
    #define VCP_COMMAND_POPUP_ICON_Y                        (29)
    #define VCP_COMMAND_POPUP_ICON_WIDTH                    (0)
    #define VCP_COMMAND_POPUP_ICON_HEIGHT                   (0)
     
    #define VCP_COMMAND_POPUP_TEXT_X_ICON                   (7)
    #define VCP_COMMAND_POPUP_TEXT_X                        (8)
    #define VCP_COMMAND_POPUP_TEXT_Y                        (17)
    #define VCP_COMMAND_POPUP_TEXT_HEIGHT                   (18)
    #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON               (224)
    #define VCP_COMMAND_POPUP_TEXT_WIDTH_ICON_LANDSCAPE     (304)
    #define VCP_COMMAND_POPUP_TEXT_WIDTH                    (224)
    #define VCP_COMMAND_POPUP_TEXT_WIDTH_LANDSCAPE          (304)
    #define VCP_COMMAND_POPUP_TEXT_SIZE                     (16)
    #define VCP_COMMAND_POPUP_TEXT_LEFT_MARGIN              (8)
    
    #define VCP_COMMAND_POPUP_BUTTON_Y_SHIFT                (8)
    #define VCP_COMMAND_POPUP_BUTTON_X                      (8)
    #define VCP_COMMAND_POPUP_BUTTON_Y                      (0)
    #define VCP_COMMAND_POPUP_BUTTON_GAP                    (5)
    #define VCP_COMMAND_POPUP_BUTTON_WIDTH                  (224)
    #define VCP_COMMAND_POPUP_BUTTON_WIDTH_LANDSCAPE        (304)
    #define VCP_COMMAND_POPUP_BUTTON_HEIGHT                 (40)
#endif


/*****************************************************************************
 * Class VcpCommandPopup
 *  VcpCommandPopup show command popup. user can set its infoType to show different
 *  kinds of command popup. The infoType is the same as plutommi. it decide the 
 *  warning tone, image icon. User can also change those propertis by calling 
 *  correspond API. User can use addItem to add a new button.
 *
 * EXAMPLE
 * <code>
 *  VcpCommandPopup *m_commandPopup;
 *  VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
 *  m_commandPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
 *  m_commandPopup->setText(VFX_WSTR("You are FAIL!"));
 *  m_commandPopup->addItem('appl', VFX_WSTR("Apple"));
 *  m_commandPopup->addItem('bird', VFX_WSTR("Bird"));
 *  m_commandPopup->show(VFX_TRUE);
 * </code>
 *****************************************************************************/
class VcpCommandPopup : public VfxBasePopup
{
VFX_DECLARE_CLASS(VcpCommandPopup);
// Constructor / Destructor
public:
    // <group DOM_CommandPopup_VcpCommandPopup_Constructor/Destructor>
    // Constructor block.    
    VcpCommandPopup(); 

// Method
public:
    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWString &text          // [IN] text
        );
    
	/* vaib mem reduction*/
	// <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets popup text.
    void setText(
        VfxResId text_id          // [IN] text
        );

	/* vaib mem reduction*/
	// <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets popup text.
    void setText(
        const VfxWChar* text_buf          // [IN] text
        );
    
    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets font for popup text.
    void setTextFont(
        const VfxFontDesc &font // [IN] text font description
        );
    
    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets info type to choose waring tone.
    void setInfoType(
        VcpPopupTypeEnum type           // [IN] information type
        );

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Adds a new button. User can add 7 buttons at most in FTO(6 in Shell).
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWString &text,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Adds a new button. User can add 7 buttons at most in FTO(6 in Shell).
    void addItem(
        VfxId id,                       // [IN] button id 
        VfxResId text_id,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

	/* vaib mem reduction*/
	// <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Adds a new button. User can add 7 buttons at most in FTO(6 in Shell).
    void addItem(
        VfxId id,                       // [IN] button id 
        const VfxWChar* text_buf,         // [IN] button text
        VcpPopupButtonTypeEnum type = VCP_POPUP_BUTTON_TYPE_NORMAL // [IN] button type
        );

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Enables a button.
    void enableItem(
        VfxId id                        // [IN] button id 
        );

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Disables a button.
    void disableItem(
        VfxId id                        // [IN] button id 
        );

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Gets popup text.
    // RETURNS :
    // Popup text string.
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Gets text font.
    // RETURNS :
    // Popup text font.
    const VfxFontDesc &getTextFont()
    {
        return m_textFrame->getFont();
    }
    
    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Gets popup info type.
    // RETURNS :
    // Info type enum.
    VcpPopupTypeEnum getInfoType()
    {
        return m_infoType;
    }

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets icon image.
    void setImage(
        const VfxImageSrc &imgScr         // [IN] image
        );

    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Sets text alignment mode.
    void setTextAlignMode(
        VfxTextFrame::AlignModeEnum value // [IN] text Alignment mode
        );

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_CommandPopup_VcpCommandPopup_Method>
    // Enables/disables the tone play. Only used by global popup.
    void setIsPlayTone(
        VfxBool option                          // [IN] Whether to play the tone or not
        );
#endif

// Override
protected:
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Initialize block.
    virtual void onInit();
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Update block.
    virtual void onUpdate();

    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Override key inputs.
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Called from base popup when popup is entering.
    virtual void onEnter();
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Called from base popup when popup is exiting.
    virtual void onExit();
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Called from base popup when popup is popped from the popup stack.
    virtual void onLeaveStack();
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Override rotate event.
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );
    
    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Called from base popup when playing Tone starts.
    virtual void onPlayTone();

    // <group DOM_CommandPopup_VcpCommandPopup_Override>
    // Called from base popup when playing Tone stops.
    virtual void onStopTone();

// Implenmention
private:
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    void resetButton();
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    void onButtonClick(VfxObject* sender, VfxId id);

// Signal
public:
    // <group DOM_CommandPopup_VcpCommandPopup_Event>
    // This singal is invoked when button is clicked.
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable    
protected:
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Top frame for background.
    VfxFrame                        *m_backgroundTop;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Bottom frame for background.
    VfxFrame                        *m_backgroundBottom;

#if defined(__MMI_VUI_COSMOS_CP__) 
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Bottom image frame for background.
    VfxFrame                        *m_backgroundBottomImage;
#endif

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Scrollable button panel.
    VcpScrollable                     *m_buttonPanel;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Icon image frame.
    VfxFrame                        *m_icon;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Text frame.
    VfxTextFrame                    *m_textFrame;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Info type enum.
    VcpPopupTypeEnum                m_infoType;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Button array.
    VcpButton                       *m_button[VCP_COMMAND_POPUP_BUTTON_MAX_COUNT];

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Current button count.
    VfxS32                          m_buttonCount;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Button width (changed while rotating).
    VfxS32                          m_buttonWidth;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Flag to check Title string.
    VfxBool                         m_hasTitle;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Flag to check Icon image.
    VfxBool                         m_hasIcon;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Text height for multiline text content.
    VfxS32                          m_textHeight;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Button panel height.
    VfxS32                          m_panelHeight;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Top frame's height.
    VfxS32                          m_upRegionHeight;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Bottom frame's height.
    VfxS32                          m_bottomRegionHeight;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Index of cancel button.
    VfxS32                         m_cancelButtonIndex;

#if defined(__MMI_VUI_COSMOS_CP__)
    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Flag to play tone.
    VfxBool                         m_isPlayTone;

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Stores whether the rotation occurs.
    VfxBool                         m_needToRotate; 
#endif

    // <group DOM_CommandPopup_VcpCommandPopup_Implementation>
    // Button pressed state.
    VfxBool                         m_buttonPressed;    
};

#endif /* __VCP_COMMAND_POPUP_H__ */

