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
#include "vcp_list_menu.h"
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "ui_core\base\vfx_basic_type.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_osd.h"

extern vapp_camco_osd_skin g_vapp_camco_skin;
class VappCamcoCpAdvanceMenu;

#define VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT  20
#define VAPP_CAMCO_CP_ADVANCE_MENU_SHOWN_COUNT 5
#define VAPP_CAMCO_CP_ADVANCE_MENU_RECOVER_DUR 500

static VcpListMenuThemeStruct m_menu_theme = {
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_GREY,
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_MAKE(255, 255, 255, 255),
    VRT_COLOR_GREY,
    VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND,
    VCP_IMG_LIST_MENU_CHECK_BOX_ON,
    VCP_IMG_LIST_MENU_CHECK_BOX_OFF,
    VCP_IMG_LIST_MENU_RADIO_BUTTON_ON,
    VCP_IMG_LIST_MENU_RADIO_BUTTON_OFF,
    VCP_IMG_LIST_MENU_GROUP_HEADER_BG,
    VCP_IMG_LIST_MENU_CHECK_MARK
};
class VappCamcoCpMenuCusItemMark : public VcpListMenuCheckMark
{
public:
    VappCamcoCpMenuCusItemMark():
        VcpListMenuCheckMark(VFX_FALSE)
    {
    }    
    VappCamcoCpMenuCusItemMark(VfxBool isMultiSelect):
        VcpListMenuCheckMark(isMultiSelect)
    {
    }
    virtual ~VappCamcoCpMenuCusItemMark(){}

    VfxImageFrame* m_imageFrame;
};

class VappCamcoCpItemContentProvider : public VfxFrame, public IVcpListMenuContentProvider 
{
    #define VAPP_CAMCO_CP_ITEM_MENU_MAX_COUNT 50

public:
    VappCamcoCpItemContentProvider(){}
    virtual ~VappCamcoCpItemContentProvider(){}

    virtual void onInit();
    
    void setCount(VfxU32 count);

    virtual VfxU32 getCount() const;

    void setItemText(VfxU32 index, VfxU32 content, VfxU32 icon);
    
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);

    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);

    virtual VcpListMenuCellBaseControl* getItemCustomControl(
        VfxU32 index,                                    // [IN] index of the item
        VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
        VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
        );

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const ;

    virtual VfxBool getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame * frame);

    virtual VfxBool swapItem(
        VfxU32 index1, 
        VfxU32 index2 
        ); 
        
    virtual void closeItemCustomContentFrame(
        VfxU32 index,  
        VcpListMenuCellClientBaseFrame *cell 
        ){};

    void setSelectedIdx(VfxU32 idx);

private:
    VfxU32 m_count;
    VfxU32 m_textContent[VAPP_CAMCO_CP_ITEM_MENU_MAX_COUNT];
    VfxU32 m_imgID[VAPP_CAMCO_CP_ITEM_MENU_MAX_COUNT];    
    VfxU32 m_selected_idx;   
    

};

class VappCamcoCpAdvanceMenuCell : public VfxControl
{
    VfxImageFrame      *m_img;
    VfxBool             m_highlight;   

public:

    VappCamcoCpAdvanceMenu* getMenu();

    VfxS32 getMenuPos();

    virtual void onInit();

    virtual void onDeinit();

    virtual void onUpdate(){};
    
    void onBoundUpdate(VfxFrame * f, const VfxRect & R);
    
    void unclick(void);

    void click(void);

    void setImg(VfxImageSrc img);

    
};

class VappCamcoCpAdvanceMenuSubCell : public VfxControl
{
    VfxTextFrame       *m_text;    
    VfxBool             m_highlight;   
    VfxU32              m_lengLimitX;

public:

    VappCamcoCpAdvanceMenu* getMenu();

    VfxS32 getMenuPos();

    virtual void onInit();

    virtual void onDeinit();

    virtual void onUpdate(){};

    void onBoundUpdate(VfxFrame * f, const VfxRect & R);
    
    void unclick(void);

    void click(void);

    void setText(const VfxWString & value);

};

class VappCamcoCpAdvanceMenu : public VcpWheelMenu
{
    typedef VappCamcoCpAdvanceMenu     Self;
    typedef VcpWheelMenu            Super;

    struct MyWheelMenuUserData
    {
        VfxS32 extendMode;
        VfxU32 limitLength;
    };    



// Constructor / Destructor
public:
    VappCamcoCpAdvanceMenu(){}
    virtual ~VappCamcoCpAdvanceMenu(){}

// Override
    virtual void onInit();
    virtual void onDeinit();


    void onBack(VfxObject* sender, VfxId id);

    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);

    void onBoundUpdate(VfxFrame * f, const VfxRect & R);

    virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell);
    
    virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame);

    virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame);
    
    virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem);

    virtual void onDragStart();

    virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed);

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    virtual void onTap(VfxPoint pt);

    virtual VfxBool onPenInput(VfxPenEvent & event);

    void updateFocus(VfxU32 i);

    virtual VfxS32 getCount();

    virtual VfxS32 getSubCellCount();

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

    void setRot(VfxBool isEnvHorz, VfxBool isCPHorz, VfxBool isCPMirror);

    void setSettingImg(VcpStateImage imglist);
    
    void setCount(VfxS32 count);

    void setMenuitemRatio(VfxFloat L1Ratio);

    void setCellData(VfxU32 idx, VfxU32 ID, VcpStateImage imglist, const VfxWString & value);

    void setitemData(VfxU32 idx, VfxU32 ID, VfxU32 icon, VfxU32 str_id);

    void setitemCount(VfxU32 count);
    
    void setItemFocus(VfxU32 idx);

    void updateItem(void);

    void reset(void);

    virtual void setHidden(VfxBool value);

    void onEffect(VfxTimer *source);
    
    void onEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void onRecoverEffectTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void recoverEffect(void);
    
    void onEndOfTimeline(VfxBaseTimeline *timeline, VfxBool isCompleted);

    VfxU32 getRecoverEffectDur(void);

    VfxBool isAnimating(void);

    VfxFloat checkFocusIdx(VfxFloat idx);

// Variable
protected:
    VfxS32              m_count;
public:
    VfxFrame           *m_movingFrame;
    VfxPoint            m_focusPos2;
    
    VfxSignal2 <
        VfxU32,                     // setting        
        VfxU32                      // value
    > m_signalItemSelected;

    VfxSignal1 <
        VfxU32                      // ID
    > m_signalTraversed;


    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalMenuMoved;    

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalEnterEffectStart;    

    VfxSignal1 <
        VfxU32                      // dummy
    > m_signalLeaveEffectDone;  

    VfxSignal2 <VfxObject*, VfxId>      m_signalClicked;    
private:    
    VcpStateImage                   m_imglist[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT];
    VfxWString                      m_text[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT];    
    VfxU32                          m_ID[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT];    
    VfxU32                          m_itemID[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT];        
    VfxBool                         m_cellDataSet[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CAOUNT];    
    VcpImageButton                 *m_back;    
    VcpListMenu                    *m_itemMenu;
    VappCamcoCpItemContentProvider *m_itemMenuContentProvider;

    VfxFloat                        m_menuLeftPartRatio;

    VfxImageFrame                  *m_circle;
    VfxImageFrame                  *m_indicator;   
    VfxFrame                       *m_background;

    VfxU32                          m_effectStep;
    VfxU32                          m_recoverEffectStep;    

    VfxTimer                       *m_effectTimer;

    static VfxU32                   m_menuHeight;

    VfxBool                         m_isHorzUI;     
    VfxBool                         m_isMirrorUI;    
    VfxBool                         m_isHorzFW;      

    VfxBool                         m_isItemTap;          
};


#endif
