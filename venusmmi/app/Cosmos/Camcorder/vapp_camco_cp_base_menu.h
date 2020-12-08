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

class VappCamcoCpBaseMenu;

#define VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT  20
#define VAPP_CAMCO_CP_BASE_MENU_SHOWN_COUNT 5
#define VAPP_CAMCO_CP_BASE_MENU_RECOVER_DUR 400
#if defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
#define VAPP_CAMCO_CP_BASE_MENU_FUZZY_SIZE 10 
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
#define VAPP_CAMCO_CP_BASE_MENU_FUZZY_SIZE 25 
#elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
#define VAPP_CAMCO_CP_BASE_MENU_FUZZY_SIZE 10 
#elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
#define VAPP_CAMCO_CP_BASE_MENU_FUZZY_SIZE 10 
#else
#define VAPP_CAMCO_CP_BASE_MENU_FUZZY_SIZE 10
#endif
#define VAPP_CAMCO_CP_BASE_MENU_NO_ANIMATE 0

#define CAMCO_SAMPLE_MENU_1_CELL_WIDTH            (55)
#define CAMCO_SAMPLE_MENU_1_CELL_HEIGHT           (55)


typedef enum
{
    VAPP_CAMCO_CP_BM_MODE_IS_NONE = 0,
    VAPP_CAMCO_CP_BM_MODE_IS_VERTICAL = 1,
    VAPP_CAMCO_CP_BM_MODE_IS_SEPARATED = 2,        
    VAPP_CAMCO_CP_BM_MODE_END
    
}vapp_camco_cp_base_menu_mode_enum;

class VappCamcoCpBaseMenuCell : public VfxControl
{
    VfxImageFrame      *m_img;
    VfxImageFrame      *m_subImg;
    VfxBool             m_highlight;
    VfxU32              m_mode;
public:

    VappCamcoCpBaseMenu* getMenu();
    VfxS32 getMenuPos();

    virtual void onInit();

    virtual void onDeinit();

    virtual void onUpdate(){};

    virtual void setBounds(const VfxRect &value);

    void unclick(void);
    void click(void);

    void setImg(VfxImageSrc img, VfxU32 fixedDimSize);
    
    void setMode(VfxU32 mode);

    const VfxImageSrc &getImg(void);

    void setImageHidden(VfxBool ishidden);
   
};

class VappCamcoCpBaseMenu : public VcpWheelMenu
{
    typedef VappCamcoCpBaseMenu     Self;
    typedef VcpWheelMenu            Super;
   
    struct MyWheelMenuUserData
    {
        VfxBool verticalMode;
		VfxU32	count;
    };    

// Constructor / Destructor
public:
    VappCamcoCpBaseMenu(){}
    virtual ~VappCamcoCpBaseMenu(){}

// Override
public:
    virtual void onInit();
    
    void onBoundUpdate(VfxFrame * f, const VfxRect & R);

    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);

    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);

    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);

    virtual void onDragStart() ;

    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    // Notify when the menu is tapped
    virtual void onTap(VfxPoint pt);

    virtual void onStateChangeFinished(VcpWheelMenuState finishedstate);

    void onEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onRecoverEffectTimeline(VfxBaseTimeline *prevTimeline, VfxBool isCompleted);
 
    void recoverEffect(void);
    
    VfxU32 getRecoverEffectDur(void);

    VappCamcoCpBaseMenuCell* getCell(VfxU32 n);

    VfxU32 getCellID(VfxU32 i);

    virtual VfxS32 getTapThreshold();

    virtual VfxS32 getCount();

    virtual VfxS32 getBehindCount();

    virtual VfxS32 getAheadCount();

    VfxS32 getPrevFocus();

    VfxS32 getPostFocus();

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
    static VfxU8 m_isleftmoving;  

    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

    void setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror);

    void setCellRot(VfxImageFrame* cell);

    void searchFocusItem(VfxMsec animTime);

    void setFocus(VfxS32 focus, VfxMsec animTime);

    void setFocusOnCenter(void);

    void setFocusandCheck(VfxU32 f);  

    void setCount(VfxS32 count);
    
    void setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist);

    void setMode(VfxU32 mode, VfxSize newSize);

    virtual void setHidden(VfxBool value);

    void reset(void);

    VfxBool isAnimating(void);

    VfxU32 checkFocusIdx(VfxS32 idx);

    VfxFloat checkFocusIdx2(VfxFloat idx);    
    
// Variable
protected:
    VfxS32                          m_count;
    VfxU32                          m_mode;
    
    VcpStateImage                   m_imglist[VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT];
    VfxU32                          m_ID[VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT];    
    VfxBool                         m_cellDataSet[VAPP_CAMCO_CP_BASE_MENU_MAX_CAOUNT];    

    VfxU32                          m_recoverEffectStep;     
    VfxU32                          m_effectStep;    
    
    VfxU32                          m_nextFocus;    
    VfxU32                          m_prevFocus;        

    VfxWeakPtr <VappCamcoCpBaseMenuCell> m_focusedItem;
    VfxImageFrame                  *m_effectImageFrame;
    VfxImageFrame                  *m_bgFrame;

    VfxBool                         m_isHorzUI;    
    VfxBool                         m_isMirrorUI;    
    VfxBool                         m_isHorzFW;       
    
public:
    VfxFrame                       *m_movingFrame;
    VfxPoint                        m_focusPos2;
    
    VfxSignal1 <
        VfxU32                      // ID
    > m_signalItemSelected;

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalMenuMoved;    

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalEnterEffectStart;    

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalLeaveEffectDone;        
    
private:    

};

#endif
