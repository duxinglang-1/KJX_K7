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
 *  vtst_rt_image_flow.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for VcpImageFlow
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vcp_frame_effect.h"
#include "vcp_image_flow.h"
#include "vcp_frame_effect.h"

extern "C" 
{
    #include "med_utility.h" // TODO: remove this after using VRT memory API
    #include "med_smalloc.h"
    #include "gdi_include.h"
    #include "gdi_const.h"
    #include "MMIDataType.h"
    #include "gdi_datatype.h"
}

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_text_frame.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vcp_frame_effect_type.h"
#include "vfx_input_event.h"
#include "vfx_app_cat_scr.h"


//#define __VTST_RT_IMAGE_FLOW_USE_SS__  (1)
#define __VTST_RT_IMAGE_FLOW_USE_WHEEL__ (1)
#if 0
#if defined(__MTK_TARGET__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MTK_TARGET__)
/* under construction !*/
#endif
/* under construction !*/
#endif
/***************************************************************************** 
 * ImageFlow Test Implementation
 *****************************************************************************/

class VtstRtImageFlow : public VtstRtScr
{
// Class
    class ImageFlowData : public VfxObject, public IVcpImageFlowContentProvider
    {
    public:
        ImageFlowData(){};
        virtual ~ImageFlowData(){};

        virtual VfxImageSrc& getImageContent(VfxS32 index)
        {
            //return NULL;
            return m_Image[index];
            //return m_Image[0];
        };

    protected:
        virtual void onInit()
        {
            VfxObject::onInit();

            VfxS32 i;
            VfxWString temp;
            
            for (i = 0; i < 15; i++)
            {
                // allocate memory
                image1[i] = (VfxU8 *)med_alloc_ext_mem(120 * 150 * 2);
       
                gdi_layer_create_using_outside_memory(
                    0,				
                    0,				
                    120,			
                    150,		
                    &image1handle[i],			
                    image1[i],			
                    120*150*2			
                    );
                

                gdi_layer_push_and_set_active(image1handle[i]);
                temp.format("E:\\120x120\\IF%05d.jpg", i);
                gdi_image_draw_file(0,0,temp.getBuf());
                gdi_layer_pop_and_restore_active();

               // VFX_OBJ_CREATE(m_Image[i], VfxImage, this);
               // m_Image[i]->setLayerHandle((void *)image1handle[i]);
				m_Image[i] = VfxImageSrc(temp);
            }
        };
        virtual void onDeinit()
        {
            VfxS32 i;
            for (i = 0; i < 15; i++)
            {
                gdi_layer_free(image1handle[i]);
                med_free_ext_mem((void **)&(image1[i]));
            }
            VfxObject::onDeinit();
        };

    private:
        VfxImageSrc m_Image[20];
        gdi_handle image1handle[20];
        VfxU8 *image1[20];
        
    };
    
// Variable
public:
    #ifdef __VTST_RT_IMAGE_FLOW_USE_WHEEL__
    VcpImageFlowWheel *m_imageFlow;
    #else
    VcpImageFlow *m_imageFlow;
    #endif
    VfxTextFrame *m_controlText;

    ImageFlowData *m_imageFlowData;
    VfxImageSrc m_FoxImage;
    VfxImageSrc m_optionImage;
    VfxFrame *m_option;
    VcpFrameEffect *m_effect1;
    VcpFrameEffect *m_effect2;
    VfxFrame*  m_focusFrame;
    VfxS32 m_state;
// Constructor / Destructor
public:
    VtstRtImageFlow() :
        m_imageFlow(NULL),
        m_controlText(NULL),
        m_focusFrame(NULL),
        m_state(0)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        
        setBgColor(VRT_COLOR_AQUA);
    #ifdef __VTST_RT_IMAGE_FLOW_USE_WHEEL__
        VFX_OBJ_CREATE(m_imageFlow, VcpImageFlowWheel, this);
    #else
        VFX_OBJ_CREATE(m_imageFlow, VcpImageFlow, this);
    #endif
        VfxRect screen_bounds       = getBounds();
        //m_imageFlow->setPos(VfxPoint(10, 120));
        
        //m_imageFlow->setBounds(VfxRect(0, 0, 220, 200));
        #if defined(__MMI_MAINLCD_240X400__) 
        m_imageFlow->setPos(VfxPoint(20, 20));
        m_imageFlow->setBounds(VfxRect(0, 0, 360, 200));

    #ifdef __VTST_RT_IMAGE_FLOW_USE_SS__
        m_imageFlow->setRotateAngle(80);
    #else
        m_imageFlow->setRotateAngle(0);
        m_imageFlow->setUpShift(20);
    #endif
        
    #if defined(__VTST_RT_IMAGE_FLOW_USE_WHEEL__) || defined(__VTST_RT_IMAGE_FLOW_USE_SS__)
        m_imageFlow->setCellParameter(15,120,150,60,30,128);
    #else
        m_imageFlow->setCellParameter(15,120,150,120,120,150);
    #endif
        //m_imageFlow->setCellParameter(8,120,120,20,20,90);
        #elif defined(__MMI_MAINLCD_240X320__)
        m_imageFlow->setPos(VfxPoint(10, 20));
        m_imageFlow->setBounds(VfxRect(0, 0, 300, 200));
        m_imageFlow->setCellParameter(15,120,150,36,36,105);
        #else
        m_imageFlow->setPos(VfxPoint(20, 20));
        m_imageFlow->setBounds(VfxRect(0, 0, 360, 200));
        m_imageFlow->setCellParameter(15,120,150,60,30,128);
        #endif
        //m_imageFlow->setBackDistance(20);
        m_imageFlow->setBgColor(VFX_COLOR_BLACK);
        

        VFX_OBJ_CREATE(m_imageFlowData, ImageFlowData, this);
        m_imageFlow->setContentProvider(m_imageFlowData);
        
        m_imageFlow->setFocusIndex(2);
 
        m_imageFlow->m_signalSelected.connect(this, &VtstRtImageFlow::onSelected);
        
       // VFX_OBJ_CREATE(m_FoxImage, VfxImage, this);
        //m_FoxImage->setSrc(VFX_WSTR("E:\\120x120\\IF00.jpg"));
		m_FoxImage = VfxImageSrc(VFX_WSTR("E:\\120x120\\IF00.jpg"));

       // VFX_OBJ_CREATE(m_optionImage, VfxImage, this);
       // m_optionImage->setSrc(VFX_WSTR("E:\\120x120\\option.bmp"));
		m_optionImage = VfxImageSrc(VFX_WSTR("E:\\120x120\\option.bmp"));

        VFX_OBJ_CREATE(m_option, VfxFrame, this);
        //m_option->setPos(VfxPoint(60, 120));
        m_option->setPos(VfxPoint(60, 20));
        m_option->setBounds(VfxRect(0, 0, 120, 120));
        m_option->setBgColor(VFX_COLOR_WHITE);
        m_option->setImgContent(m_optionImage);
        m_option->setIsCached(VFX_TRUE);
        m_option->setIsOpaque(VFX_TRUE);
        m_option->setHidden(VFX_TRUE);


        VFX_OBJ_CREATE(m_effect1, VcpFrameEffect, this);
        VFX_OBJ_CREATE(m_effect2, VcpFrameEffect, this);
        m_effect1->m_signalFinished.connect(this, &VtstRtImageFlow::onUndoFinished);

        // Create a text
        VFX_OBJ_CREATE(m_controlText, VfxTextFrame, this);
        //m_controlText->setPos(VfxPoint(10, 80));
        m_controlText->setPos(VfxPoint(10, 10));
        m_controlText->setColor(VFX_COLOR_BLACK);
        m_controlText->setBgColor(VFX_COLOR_GREY);
        m_controlText->setAutoAnimate(VFX_TRUE);
        m_controlText->setString(VFX_WSTR("Hello ImageFlow"));
    }

#ifdef __VTST_RT_IMAGE_FLOW_USE_WHEEL__
    void onSelected(VcpImageFlowWheel *imageflow,VfxFrame* focusFrame, VfxS32 index)
#else
    void onSelected(VcpImageFlow *imageflow,VfxFrame* focusFrame, VfxS32 index)
#endif
    {
        //imageflow->switchTo(m_option, VCP_EFFECT_FLIP, 2000);
        m_option->setHidden(VFX_FALSE);
        m_focusFrame = focusFrame;
        m_effect1->applyEffect(m_option, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT);   
        m_effect2->applyEffect(focusFrame, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_LEFT,VFX_TRUE);
        m_state = 1;
    }


    void onUndoFinished(VfxFrame *frame, VfxBool isComplete)
    {
        if (m_state == 0)
        {
            frame->setHidden(VFX_TRUE);
        }
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        VfxWString temp;
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            switch(event.keyCode)
            {
                case VFX_KEY_CODE_1:
                    m_imageFlow->updateImageContent(m_imageFlow->getFocusIndex(), m_FoxImage);
                    return VFX_TRUE;
                case VFX_KEY_CODE_2:
                    return VFX_TRUE;
                case VFX_KEY_CODE_3:
                    //m_imageFlow->undoSwitch();
                    if (m_state == 1)
                    {
                        m_effect1->applyEffect(m_option, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_RIGHT, VFX_TRUE);
                        m_effect2->applyEffect(m_focusFrame, VCP_EFFECT_FLIP, 500, VCP_EFFECT_DIRECTION_FROM_RIGHT);
                        m_state = 0;
                    }
                    return VFX_TRUE;
                case VFX_KEY_CODE_4:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_5:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_6:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_7:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_8:
                    return VFX_TRUE;
                case VFX_KEY_CODE_9:
                    
                    return VFX_TRUE;
                case VFX_KEY_CODE_0:
                    
                    return VFX_TRUE;
            }
        }
        return VtstRtScr::onKeyInput(event);
    }


    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);
        confirm(VFX_WSTR("Does it work?"));
        return -1;
    }
};

VtstTestResultEnum vtst_rt_image_flow(VfxU32 param)
{
    VTST_START_SCRN_ROTATE(VtstRtImageFlow);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

