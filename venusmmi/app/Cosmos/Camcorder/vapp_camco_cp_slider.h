/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_app_scr.h"
#include "vcp_include.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_osd.h"

extern vapp_camco_osd_skin g_vapp_camco_skin;

class VappCamcoCpSlider : public VfxControl
{
#define VAPP_CAMCO_CP_SUPPORT_QUICK_MOVE  (0)
#define VAPP_CAMCO_CP_SLIDER_SPACE        (11)
#define VAPP_CAMCO_CP_SLIDER_V_SPACE        (3)

public:
    VappCamcoCpSlider(){}
    virtual ~VappCamcoCpSlider(){}

    virtual void onInit();

    void setVertical(VfxBool isVertical);
    void setInverse(VfxBool isInverse);    
    void setCurveR(VfxU32 r = 0);    
    void setCpImage(VfxImageSrc minimg, VfxImageSrc maximg, VfxImageSrc indimg, VfxImageSrc barimg);
    void setValueRange(VfxS32 min, VfxS32 max);
    void setCurrentValue(VfxS32 value);

    VfxS32 getCurrentValue(void);
  
    void onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds);

    void setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror);

    virtual VfxBool onPenInput(VfxPenEvent & event);

    VfxSignal1 <
        VfxU32                      // value
    > m_signalValueChanged;    
    
private:
    VfxImageFrame      *m_maxImg;
    VfxImageFrame      *m_minImg;    
    VfxImageFrame      *m_indImg;        
    VfxImageFrame      *m_barImg;
    VfxS32              m_minValue;    
    VfxS32              m_maxValue;
    VfxU32              m_range;
    VfxS32              m_minPos;    
    VfxS32              m_maxPos;    
    VfxU32              m_length; 
    VfxS32              m_currentValue;        
    VfxS32              m_curveR;    
    VfxBool             m_isVerticalMode;
    VfxBool             m_isInverseMode;    
    VfxBool             m_isMoving;        
    VfxBool             m_isHorzUI;            
    VfxBool             m_isHorzFW;        
};
#endif
