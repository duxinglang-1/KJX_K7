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
 *  vapp_image_flow.h
 *
 * Project:
 * --------
 *  Image flow app in media player- auto category
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#define __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__

#include "MMI_Features.h"
#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__

#ifndef __VAPP_IMAGE_FLOW_H__
#define __VAPP_IMAGE_FLOW_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
//#include "vfx_uc_include.h"
//#include "vcp_include.h"
#include "vcp_button.h"
#include "ui_core\pme\vfx_signal.h"
#include "vcp_image_flow.h"
#include "ui_core\pme\vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_image_src.h"
#include "vcp_app_scr.h"
#include "mmi_core\vfx_app_cat_scr.h"
#include "ui_core\pme\vfx_class_info.h"
#include "ui_core\mvc\vfx_frame.h"
#include "ui_core\mvc\vfx_input_event.h"
#include "ui_core\mvc\vfx_control.h"
#include "ui_core\mvc\vfx_text_frame.h"
#include "ui_core\mvc\vfx_primitive_frame.h"

#include "ImageFlow\vadp_v2p_image_flow.h"

/***************************************************************************** 
 * Macro define
 *****************************************************************************/

/***************************************************************************** 
 * Type define
 *****************************************************************************/

/***************************************************************************** 
 * Declear
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

extern void vapp_image_flow_entry(void);
extern void vapp_image_flow_leave(void);

#ifdef __cplusplus
} /* extern "C"*/
#endif 

/***************************************************************************** 
 * class VappImageFlowButton
 *****************************************************************************/
class VappImageFlowButton : public VcpButtonInternal
{
public:
    VappImageFlowButton();
     // Overridable
protected:

    virtual void onInit();
    virtual void onDeinit();
    virtual void buttonMoveIn();
    virtual void buttonMoveOut();

public:
    VfxSignal0  m_eventMoveIn;
    VfxSignal0  m_eventMoveOut;

};


/***************************************************************************** 
 * class VappImageFlowData
 *****************************************************************************/
class VappImageFlowData : public VfxObject, public IVcpImageFlowContentProvider
{
public:
    VappImageFlowData(){};
    virtual ~VappImageFlowData(){};
 
    virtual VfxImageSrc& getImageContent(VfxS32 index);
    virtual void closeImageContent(VfxS32 index);
    VfxS32  getIndex(VfxS32 i);
    VfxImageSrc& reGetImage(VfxS32 i);
    VfxBool isNeedUpdate(VfxS32 index, VfxImageSrc& image);
      
protected:
    virtual void onInit();     
    virtual void onDeinit();
 
private:
    VfxImageBuffer  m_imgBuff[VAPP_IMGFLOW_MAX_CELL_NUM];    
    VfxImageSrc     m_Image[VAPP_IMGFLOW_MAX_CELL_NUM];
    VfxS32          m_nBuff[VAPP_IMGFLOW_MAX_CELL_NUM];

    VfxImageBuffer  m_DefImgBuff;
    VfxImageSrc     m_DefImage;
    
};


/***************************************************************************** 
 * class VappImageFlowCP
 *****************************************************************************/

class VappImageFlowCP : public VcpImageFlowWheel
{
public:
    VappImageFlowCP();

public:
    virtual void onDragStart();
    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

protected:
    virtual void onInit();
    virtual void onDeinit();    
};


/***************************************************************************** 
 * class VappImageFlow
 *****************************************************************************/
class VappImageFlow : public VcpAppScr
{
    VFX_DECLARE_CLASS(VappImageFlow);
    enum
    {
        IMGFLOW_SELECT_BUTTON_NULL,
        IMGFLOW_SELECT_BUTTON_LSK,
        IMGFLOW_SELECT_BUTTON_RSK
    };

public:
    VappImageFlow();

public:
    static void updateCell(void* user_data, VfxS32 index);
    void onGoBack(void *data);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    
    void onSelected(VcpImageFlowWheel *imageflow,VfxFrame *focusFrame,VfxS32 index);//*imageflow maybe VcpImageFlow or VcpImageFlowWheel
    void onFucusChange(VcpImageFlowWheel *imageflow, VfxS32 index);  
    void onCellClosed(VcpImageFlowWheel *imageflow, VfxS32 index);
    VfxBool onKeyInput(VfxKeyEvent &event);

private:
    void onPenInput(VfxControl *cp, VfxPenEvent& event, VfxBool& ret);
    void onLskDown();
    void onLskUp();
    void onLskMoveIn();
    void onLskMoveOut();
    void onRskDown();
    void onRskUp();
    void onRskMoveIn();
    void onRskMoveOut();
    
private:
#if 1//#ifdef 1 //__VTST_RT_IMAGE_FLOW_USE_WHEEL__
    //VcpImageFlowWheel *m_imageFlow;
    VappImageFlowCP *m_imageFlow;
#else
/* under construction !*/
#endif
    VfxTextFrame*   m_textTitle;
	VfxTextFrame*	m_textArtist;
    // VfxWeakPtr<VappImageFlowData> m_imageFlowData;
    VappImageFlowData *m_imageFlowData;
  
    VfxFrame *m_focusFrame;

    VappImageFlowButton* m_buttonPlay;
    VappImageFlowButton* m_buttonBack;
    VfxImageSrc       m_imgPlay;
    VfxImageSrc       m_imgBack;
    VfxImageFrame*  m_hlFrame;
    VfxImageSrc       m_imgHiLit;
    
    VfxImageFrame*  m_bgFrame;
    VfxImageSrc       m_imgBackground;

    VfxS32   m_nAlbums;
    VfxS32   m_nSelectButton;
};

#endif /* __VAPP_IMAGE_FLOW_H__ */
#endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
