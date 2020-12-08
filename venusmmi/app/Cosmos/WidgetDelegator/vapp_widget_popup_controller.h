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
 *   vapp_popup_controller.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/


/*****************************************************************************
 * Class Declaration
 *****************************************************************************/
 
typedef void (*cb_func)(VfxId, void*);

class VcpWidgetConfirmPopup : public VcpConfirmPopup
{
    VFX_DECLARE_CLASS(VcpWidgetConfirmPopup);
public:
    // Default constructor    
    VcpWidgetConfirmPopup();

public:
    // Handle key input events
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event          // [IN] The key event to be handled
    );
};
 
class VappWidgetPopupController : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetPopupController);

// Constructor / Destructor 
public:
    // Default constructor    
    VappWidgetPopupController();

// Override
protected:
    // Deinit function
    virtual void onDeinit();     

// Implementation
public:
    // Get parent object by widget id
    static VfxObject *getParentObjById(VfxS32 widgetId);

    // Get parent object
    static VfxObject *getParentObj();

    // Show popup with ok button
    void showPopupWithOk(
        VfxObject *parentObj,
        const VfxWString &text);

    // Show popup with yes/no button
    void showPopupWithYesNo(
        VfxObject *parentObj,
        const VfxWString &text);

    // Show query popup with yes/no button
    void showQueryPopupWithYesNo(
        VfxObject *parentObj,
        const VfxWString &text);

    // Show popup with parameters
    void showPopup(
        VfxObject *parentObj,
        VcpPopupTypeEnum type,              
        VcpConfirmPopupButtonSetEnum buttonSet, 
        const VfxWString &text);

    // Handle popup button clicked events
    void onPopupButtonClicked(VfxObject *sender, VfxId id);

    // Set callbck function
    void setCallback(cb_func cb, void *userData);

// Variable
public:
    static VfxBool m_isPopup;

private:
    // Widget confirm popup 
    VcpWidgetConfirmPopup *m_confirmPopup;

    // Callback function pointer
    cb_func m_callback;

    // Callback function user data
    void *m_userData;

    // Is callback executing
    VfxBool m_isCalling;

    // Popup clicked button id
    VfxId m_id;
};


