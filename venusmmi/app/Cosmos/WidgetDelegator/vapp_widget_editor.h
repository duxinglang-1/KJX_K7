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
 *  
 *
 * Project:
 * --------
 *  Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
     
#ifdef __MMI_GADGET_SUPPORT__

#include "..\mmi_core\vfx_page.h"
#include "widget_adp_struct.h"
#include "vapp_widget_adp.h"


/***************************************************************************** 
 * Declare external function 
 *****************************************************************************/ 
extern void vapp_widget_handle_enter_text_ind(void *param);
extern int vapp_widget_close_editor_by_id(int instance_id);

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define TEXT_VIEW_GAP_VERTICAL      7
#define TEXT_VIEW_GAP_HORIZONTAL    4

#define TEXT_DEFAULT_INPUT_LEN  100
#define TEXT_MAX_INPUT_LEN      (255 + 1)

// Used when cosmos keypad support is defined
#if defined(__MMI_MAINLCD_480X800__)
    #define TEXT_EDITOR_VIEW_MARGIN         15
    #define TEXT_EDITOR_LINE_GAP            60
#elif defined(__MMI_MAINLCD_320X480__)
    #define TEXT_EDITOR_VIEW_MARGIN         15
    #define TEXT_EDITOR_LINE_GAP            36
#elif defined(__MMI_MAINLCD_240X400__)
    #define TEXT_EDITOR_VIEW_MARGIN         10
    #define TEXT_EDITOR_LINE_GAP            32
#elif defined(__MMI_MAINLCD_240X320__)
    #define TEXT_EDITOR_VIEW_MARGIN         10
    #define TEXT_EDITOR_LINE_GAP            32
#endif

// Used when cosmos keypad support is NOT defined
#if defined(__MMI_MAINLCD_480X800__)
    #define TEXT_EDITOR_SINGLE_HEIGHT       65
    #define TEXT_EDITOR_MULTILINE_HEIGHT    90
    #define TEXT_EDITOR_BUTTON_W            65
    #define TEXT_EDITOR_BUTTON_H            65
#elif defined(__MMI_MAINLCD_320X480__)
    #define TEXT_EDITOR_SINGLE_HEIGHT		40
    #define TEXT_EDITOR_MULTILINE_HEIGHT    60
    #define TEXT_EDITOR_BUTTON_W			40
    #define TEXT_EDITOR_BUTTON_H			40        
#elif defined(__MMI_MAINLCD_240X400__)
    #define TEXT_EDITOR_SINGLE_HEIGHT		40
    #define TEXT_EDITOR_MULTILINE_HEIGHT    60
    #define TEXT_EDITOR_BUTTON_W			40
    #define TEXT_EDITOR_BUTTON_H			40
#elif defined(__MMI_MAINLCD_240X320__)
    #define TEXT_EDITOR_SINGLE_HEIGHT		40
    #define TEXT_EDITOR_MULTILINE_HEIGHT    60
    #define TEXT_EDITOR_BUTTON_W			40
    #define TEXT_EDITOR_BUTTON_H			40
#endif

#define LCD_INITIAL_X   0
#define LCD_INITIAL_Y   0

/***************************************************************************** 
 * Class VappWidgetEditor 
 *****************************************************************************/
class VappWidgetEditor : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetEditor);
    
// Constructor / Destructor
public:
    // Default constructor
    VappWidgetEditor();

    // Default constructor with paramenters
    VappWidgetEditor(
        VfxS32 editorType, 
        VfxWChar *str, 
        VfxS32 len, 
        VfxU64 inputType, 
        VfxU32 inputSetting, 
        VfxBool isDetailsView);

// Enum
public:
    // Enum for button type
    enum ButtonType
    {
        BUTTON_TYPE_SAVE,
        BUTTON_TYPE_CANCEL,
        BUTTON_TYPE_END_OF_ENUM
    };

// Signal
public:
    // Indicate the text editor is closed
    VfxSignal1 <VcpButton *> m_signalClosed;

// Method
    // Get the edited string
    VfxWChar *getInputText();
    
// Override
protected:
    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();

    // Handle pen input events
    virtual VfxBool onPenInput(VfxPenEvent & event);

    // Handle key input events
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

    // Handler object notify event
    virtual void onObjectNotify(VfxId id, void *userData);

    // Get IME mode. Used for adjust editor position automatically.
    VfxFrameImeModeEnum getImeMode() 
    {
        return VFX_FRAME_IME_MODE_SHIFT;
    };

    // Adjust IME position
    void adjustImeShift (const VfxPoint &pos, VfxFrame *focusFrame);


// Implementation
private:
    // Called when button is clicked
    void onButtonClicked(VfxObject *sender, VfxId id);

// Variable
private:
    // Text editor position
    VfxPoint m_pos;
    
    // Test editor size
    VfxSize m_size;
    
    // Record the height needed to align
    VfxS32 m_alignH;
    
    // Limitation of string length
    VfxS32 m_stringLength;
    
    // String buffer for user to edit
    VfxWChar *m_stringBuffer;
    
    // Input type
    VfxU64 m_inputType;
    
    // Input setting
    VfxS32 m_inputSetting;
    
    // Multiline text editor 
    VcpTextEditor *m_multilineEditor;

    // Text editor initial height
    VfxS32 m_initHeight;
    
    // The button for saving edited string
    VcpButton *m_saveButton;

    // The button for saving edited string
    VfxImageFrame *m_bgImage;

    // Editor type
    VfxS8 m_editorType;

    // Is details view flag
    VfxBool m_isDetailsView;

};


/***************************************************************************** 
 * Class VappWidgetEditorManager
 *****************************************************************************/
class VappWidgetEditorManager : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetEditorManager);
    
// Constructor / Destructor
public:
    // Default constructor
    VappWidgetEditorManager();

// Method
public:
    // Transform input method
    VfxU32 transformMethod(VfxS32 type,VfxS16 pwd);
    
    // Create text editor component
    void createTextEditor(void *param, VfxObject *parentObj, VfxBool isDetailsView);
    
    // Close text editor
    void closeTextEditor();
    
    // Bind close handler
    void bindHandler();
    
    // Free input buffer
    void freeInputBuffer();
    
    // Pen input
    virtual VfxBool onPenInput(VfxPenEvent &event);

    // Set allow closed flag
    static void setNeedClosed(VfxBool needClose)
    {
        m_needClosed = needClose;
    }

private:
    // Text editor handler
    void textEditorHandler(VcpButton *sender);

// Variable
public:
    // Input buffer pointer
    static VfxWChar m_inputBuffer[TEXT_MAX_INPUT_LEN + 1];

    // Allow closed flag
    static VfxBool m_needClosed;
    
    // Widget text editor component
    VfxWeakPtr <VappWidgetEditor> m_textEditor; 

// Implementation
private:
    // Widget id
    VfxS32 m_instanceId;
    
    // Input buffer length
    VfxS32 m_bufferLen;
    
    // Widget view handle
    void *m_viewHandle;
    
    // Password type
    VfxS16 m_passwordField;
};


/***************************************************************************** 
 * Class VappWidgetEditorPage
 *****************************************************************************/
class VappWidgetEditorPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWidgetEditorPage);

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetEditorPage();

// Method
public:
    // Transform input method
    VfxU32 transformMethod(VfxS32 type,VfxS16 pwd);

    // Create editor component
    void createEditor(widget_enter_text_ind_struct *param);

    // Handle tool bar tapped events
    void onToolBarTapped(VfxObject *obj, VfxId id);

// Override
protected:

    // Init function
    virtual void onInit();

    // Deinit function
    virtual void onDeinit();
    
public:
    // Input buffer pointer
    static VfxWChar m_inputBuffer[TEXT_MAX_INPUT_LEN + 1];

// Implementation
private:
    enum {
        OK_BUTTON = 1,
        CANCEL_BUTTON
    };
    
    // Widget id
    VfxS32 m_instanceId;
    
    // Input buffer length
    VfxS32 m_bufferLen;
    
    // Widget view handle
    void *m_viewHandle;
    
    // Password type
    VfxS16 m_passwordField;

// Variable
private:
    // Title bar
    VfxWeakPtr <VcpTitleBar> m_titleBar;

    // Tool bar
    VfxWeakPtr <VcpToolBar> m_toolBar;    

    // Text editor 
    VfxWeakPtr <VcpTextEditor> m_textEditor;   

    // Function bar
    VfxWeakPtr <VcpFunctionBar> m_FunctionBar;      

    // Allow closed flag
    VfxWChar *m_widgetName;

};

#endif


