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
 *  vapp_pen_calibration.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_PEN_CALIBRATION_H__
#define __VAPP_PEN_CALIBRATION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcui_pen_calibration_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_CALIBRATION_POINT (3)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_PEN_CALIBRATION_WELCOME_PAGE,
    VAPP_PEN_CALIBRATION_POINT1_PAGE,
    VAPP_PEN_CALIBRATION_POINT2_PAGE,
    VAPP_PEN_CALIBRATION_POINT3_PAGE,

    VAPP_PEN_CALIBRATION_PAGE_ENUM_END
} VappPenCalibrationPageEnum;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappPenCalibrationControl : public VfxControl
{
    VFX_DECLARE_CLASS(VappPenCalibrationControl);    
    // Overrides
    protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);    

    // Varialbes
    public:
    VfxSignal0 m_signalTap;
};

class VappPenCalibrationPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappPenCalibrationPage);

    // Overrides
    public:
    virtual void onInit();
    protected:
//    virtual void onBack() {};
    virtual void onEnter(VfxBool isBackward);
    protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);    

    // Methods
    public:    
    VappPenCalibrationPage() {};
    void setAttribute(cui_pen_calibration_attribute_enum attribute) {m_attribute = attribute;};
    void setState(VappPenCalibrationPageEnum state) {m_state = state; drawPage();};
    
    protected:
    void drawPage();
    void onTap() {m_signalTap.emit();};

    
    // Varialbes:
    public:
    VfxSignal0 m_signalTap;
    VfxSignal0 m_signalCancel;
    VfxSignal0 m_signalRestart;
    
    protected:
    VappPenCalibrationPageEnum m_state;
    VappPenCalibrationControl *m_backgroundFrame;
    VfxTextFrame *m_textFrame;
    VfxAnimImageFrame *m_imageFrame;
    cui_pen_calibration_attribute_enum m_attribute;
};

class VappPenCalibrationCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappPenCalibrationCui);

    // Overrides
    protected:
    virtual void onRun(
        void* args,         // [IN] The startup parameters
        VfxU32 argSize      // [IN] The size of startup parameters
    ) ;    
    virtual void onDeinit();

	using VfxCui::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    // Methods
    public:
    void setAttribute(cui_pen_calibration_attribute_enum attribute);
    static VfxBool isAvailable() {return !m_cuiIsLaunched;};
    // Internal
    public:
    VappPenCalibrationCui() : m_calibrationDone(MMI_FALSE),
                                    m_currPage(NULL), 
                                    m_pageState(VAPP_PEN_CALIBRATION_WELCOME_PAGE),
                                    m_userData(NULL),
                                    m_attribute(CUI_PEN_CALIBRATION_NORMAL_CALIBRATION) 
    {
        ASSERT(m_cuiIsLaunched == VFX_FALSE);
        m_cuiIsLaunched = VFX_TRUE;
    };

    static mmi_ret CalibrationProc(mmi_event_struct *evt);
    
    protected:
    void onCancel();        
    void onPenTapped();
    void onPenCalibrationRsp(VfxBool result);
    void onCalibrationDone();
    void onRestart();
    void restartCalibration();
    
    // Variables
    protected:
    VfxBool                 m_calibrationDone;
    VfxMainScr             *m_mainScr;
    VappPenCalibrationPage *m_currPage;
    VappPenCalibrationPageEnum m_pageState;    
    void                   *m_userData;
    cui_pen_calibration_attribute_enum m_attribute;
    static VfxBool          m_cuiIsLaunched;
};
#endif /* __VAPP_PEN_CALIBRATION_H__ */
 
