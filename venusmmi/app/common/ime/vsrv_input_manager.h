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
 *  vsrv_input_manager.h
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *  Venus input method manager
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
#ifndef __VSRV_INPUT_MANAGER_H__
#define __VSRV_INPUT_MANAGER_H__

extern "C"
{
	#include "ImeGprotEnums.h"
}   

#include "Vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_control.h"

//#define __MRE_SDK__

#include "vsrv_input_method_interface.h"


#ifdef __MRE_SDK__
#include "gs_id.h"
#include "gs_base.h"

#define GS_C_INTERFACE
#include "gs_srv_ime_interface_def.h"
#endif

/*
 * Input method manager class
 */
 
class VsrvInputManager : public VfxObject, public VsrvInputMethodInterface 
{
    VFX_DECLARE_CLASS(VsrvInputManager);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VsrvInputManager);
    
//Method
// Override
protected:
    virtual vrt_allocator_handle getAllocator();

public:

    VsrvInputManager();

    virtual ~VsrvInputManager();

    virtual VfxBool bindInput(VsrvInputBinding *binding);

    virtual VsrvInputBinding *getBinding(); 

    virtual VfxBool unbindInput(VsrvInputBinding *binding); 
    
    virtual VfxBool activateInput(); 

    virtual VfxBool deactivateInput(); 

    virtual VfxBool dispatchKeyEvent(VfxKeyEvent &event); 

    virtual VfxBool dispatchPenEvent(VfxPenEvent &event);  

    virtual void disableSymbolPicker(); 

    
    virtual void override_autocap(); // set autocap to off temprarily.

    virtual void enableSymbolPicker(); 

    virtual VfxBool getCharInfor(VfxWChar code, VfxWChar *inforBuf, VfxU32 bufSize, mmi_imm_input_mode_enum mode) const;

    virtual VfxBool isIMEState() const; 

    virtual void addNewWordsFromText(VfxWChar *text); 

    virtual mmi_imm_input_mode_enum getCurrInputMode() const; 

    virtual mmi_imm_input_type_enum getCurrInputType() const; 

    virtual mmi_imm_input_mode_enum *getCurrrUserSpecificInputModeList() ; 

    virtual void setInputModeSwitchable(VfxBool isSwitchable); 

    virtual VfxU32 getInputMethodHistorySize() const;

    virtual void getInputMethodHistory(void *historyAddress);

    virtual void setInputMethodHistory(void *historyAddress);

    virtual void enableAutoCapInHistory(void *historyAddress);
    
    virtual void showSoftInput();

    virtual void hideSoftInput();

    virtual VfxBool isSoftInputVisible();

    virtual VfxS32 isValidInputString(VfxWChar *string, VfxS32 len); 


    
    virtual VfxBool isValidInputStringForPaste(VfxWChar *string, VfxS32 len); 

    virtual void cursorPosChanged(VfxRect &cursorRect);
    
    virtual VfxBool isInputMethodUIControl(VfxControl *control);

    virtual void rotate();

    virtual void beforeRotate();
    
    virtual void setSpecialEnterKey(VfxBool isEnabled);

    virtual void resetIMEState();
    
protected:

    virtual void onInit();
    virtual void onDeinit();

private:

#ifdef __MRE_SDK__
    IImeService *m_mreServiceInstance;
#else
    VsrvInputMethodInterface *m_currInputServer;
#endif    

    VsrvInputBinding *m_currInputBinding;

private:

#ifdef __MRE_SDK__
    static VfxU32 inputConnectionMsgProc(ImeServiceInputConnectionProxyMsgIDEnum msgID, VfxU32 *args, VfxU32 argSize);
#endif

#ifdef  __MRE_SDK__
public:
    IImeService* getMreService(); 
#endif  //  __MRE_SDK__
};

#endif /* __VSRV_INPUT_MANAGER_H__ */

