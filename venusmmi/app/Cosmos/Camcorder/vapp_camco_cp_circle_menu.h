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
#include "vcp_wheel_menu.h"
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "ui_core\base\vfx_basic_type.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_osd.h"

extern vapp_camco_osd_skin g_vapp_camco_skin;
class VappCamcoCpCircleMenu;

#define VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT  20
#define VAPP_CAMCO_CP_CIRCLE_MENU_SHOWN_COUNT 5
#define VAPP_CAMCO_CP_CIRCLE_MENU_RECOVER_DUR 350


class VappCamcoCpCircleMenuCell : public VfxControl
{

    VfxImageFrame      *m_img;
    VfxBool             m_highlight;
    VfxBool             m_isVerticalMode;   

public:

    virtual void onInit();
    virtual void onDeinit();

    virtual void onUpdate(){}
    void setPos(VfxS32 x, VfxS32 y);
    void setMode(VfxBool isVerticalMode);
    void setImg(VfxImageSrc img);  
    void setRot(VfxTransform t);
    
    void unclick(void);
    void click(void);

    VfxU16 getOffsetX(void);
    VfxU16 getOffsetY(void);
    VappCamcoCpCircleMenu* getMenu();
    VfxS32 getMenuPos();
    VfxS32 getCelledge();
    
    void updateLayout(void);

};

class VappCamcoCpCircleMenu : public VcpWheelMenu
{
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
    #define TEXT_SPACE 10
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
    #define TEXT_SPACE 15
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
    #define TEXT_SPACE 8    
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
    #define TEXT_SPACE 8        
#else
    #define TEXT_SPACE 10
#endif    
    typedef VappCamcoCpCircleMenu       Self;
    typedef VcpWheelMenu                Super;

    struct CircleMenuUserData
    {
        VfxBool verticalMode;
        VfxU16  loc_offset_x;        
        VfxU16  loc_offset_y;                
    };    

// Constructor / Destructor
public:
    VappCamcoCpCircleMenu(){}
    virtual ~VappCamcoCpCircleMenu(){}

// Override
    virtual void onInit();


    void onBoundUpdate(VfxFrame * f, const VfxRect & R);

    void onBack(VfxObject* sender, VfxId id);

    void onTextEffectTimerTick(VfxTimer *source);

    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);

    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);
    
    void setFocus(VfxS32 index, VfxMsec animTime = -1);

    virtual void onDragStart();

    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt);

    void setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror);

    void setCellRot(VappCamcoCpCircleMenuCell* cell);

    void setVerticalMode(VfxBool v);

    virtual VfxS32 getCount();

    virtual VfxS32 getBehindCount();

    virtual VfxS32 getAheadCount();

    static vrt_render_dirty_type_enum myFrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

    virtual void onStateChangeFinished(VcpWheelMenuState finishedstate);

    void updateFocus(VfxU32 i);

    void updateText(void);

    void reset(void);
        
    void setCount(VfxS32 count);

    void setSettingImg(VcpStateImage imglist);

    virtual VfxBool onPenInput(VfxPenEvent & event);

    void setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist, const VfxWString & value);

    virtual void setHidden(VfxBool value);

    void recoverEffect(void);

    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    VfxU32 getRecoverEffectDur(void);

    VfxBool isAnimating(void);
    
// Variable
protected:
    VfxS32                              m_count;
    VfxBool                             m_isVerticalMode;   
    VcpStateImage                       m_imglist[VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT];
    VfxWString                          m_text[VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT];    
    VfxU32                              m_ID[VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT];    
    VfxBool                             m_cellDataSet[VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT];    
    VcpImageButton                     *m_back;
    VfxImageFrame                      *m_circle;
    VfxImageFrame                      *m_indicator;    
    VfxTextFrame                       *m_indicatortext;
    VfxImageFrame                      *m_indicatortextBg;    
    VfxBool                             m_isAnimating;    
    VfxBool                             m_isOnExitAnim;
    VfxTimer                           *m_textEffectTimer;
    
    VfxBool                             m_isHorzUI;   
    VfxBool                             m_isMirrorUI;
    VfxBool                             m_isHorzFW;         
    
public:
    VfxFrame                           *m_movingFrame;
    VfxPoint                            m_focusPos2;
    
    VfxSignal1 <
        VfxU32                      // ID
    > m_signalItemSelected;

    VfxSignal1 <
        VfxU32                      // ID
    > m_signalItemSet;

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalMenuMoved;    

    VfxSignal2 <VfxObject*, VfxId>      m_signalClicked;

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalEnterEffectStart;    

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalLeaveEffectDone;        


};



#endif
