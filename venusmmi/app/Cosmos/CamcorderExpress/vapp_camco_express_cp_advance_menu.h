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

#ifndef __VAPP_CAMCO_EXPRESS_ADVANCE_MENU__
#define __VAPP_CAMCO_EXPRESS_ADVANCE_MENU__

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
#include "mmi_rp_srv_venus_component_button_def.h" // for get theme infomation

#ifdef __VAPP_CAMCO_EXPRESS__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_express_osd.h"

extern vapp_camco_osd_skin g_vapp_camco_skin;
class VappCamcoCpAdvanceMenu;

#define VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT         (15)
#define VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT    (15)
#if( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS    (120)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE  (4)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT  (40)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN (24)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV    (24)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV    (10)
#elif ( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS    (80)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE  (4)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT  (36)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN (20)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV    (20)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV    (10)
#elif ( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS    (60)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE  (4)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT  (30)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV    (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV    (8)
#elif ( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS    (60)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE  (4)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT  (30)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV    (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV    (8)
#else
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS    (60)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE  (4)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT  (30)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV    (12)
#define VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV    (8)
#endif

// this is for telling OSD menu has been traverse but not tap any tiem
#define VAPP_CAMCO_CP_ADVANCE_MENU_DUMMY_SETTING           (65536)

typedef enum
{
    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_NORMAL,
    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_TEXT,
    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SLIDER,
    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SWITCHER,
    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_ITEM,

    VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_END
}vapp_camco_cp_advance_menu_cell_type_enum;

typedef enum
{
    VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT,
    VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY,

    VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_END
}vapp_camco_cp_advance_menu_btn_list_type_enum;

typedef struct
{
    vapp_camco_cp_advance_menu_cell_type_enum   type;
    VfxU32                                      ID;
    VfxResId                                    img;
    VfxWString                                  text;
}vapp_camco_cp_advance_menu_cell_struct;

typedef struct
{
    VfxU32                                      ID;
    VfxBool                                     isSettingEnable;
    VfxBool                                     isItemSelected;
    VfxBool                                     isItemEnable;
}vapp_camco_cp_advance_menu_cell_status_struct;

class VappCamcoCpAdvanceMenuBtnList : public VcpScrollable
{
public:
    void setListType(vapp_camco_cp_advance_menu_btn_list_type_enum type);
    vapp_camco_cp_advance_menu_btn_list_type_enum getListType(void){return list_type;};

    void setListData(VfxU32 idx, VfxControl* btn, VfxTextFrame *text);

    void setEnable(VfxU32 idx);
    void setDisable(VfxU32 idx);
    void setHilite(VfxU32 idx);

    void setContentSize(const VfxSize &size);

    virtual VfxBool onContainPoint(const VfxPoint &point) const;

private:
    virtual void onInit();
    virtual void onDeinit();

    void notifyScrollStart(VcpScrollable *s);
    void notifyScrollStop(VcpScrollable *s);

public:
    vapp_camco_cp_advance_menu_btn_list_type_enum list_type;

private:
    VfxControl     *m_btn[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT];
    VfxTextFrame   *m_text[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT];
    VfxFrame       *m_Hilite[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT];
    VfxImageFrame  *m_leftArrow;
    VfxImageFrame  *m_rightArrow;
};

class VappCamcoCpAdvanceMenuSlider : public VfxControl
{
    virtual void onInit();
    virtual void onDeinit();
    void onBoundUpdate(VfxFrame * f, const VfxRect & R);
    virtual VfxBool onContainPoint(const VfxPoint &point) const;
    virtual VfxBool onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason);

public:
    VfxImageFrame *m_maxValue;
    VcpSlider     *m_slider;
};

class VappCamcoCpAdvanceMenu : public VfxControl
{
    typedef VappCamcoCpAdvanceMenu    Self;
    typedef VfxControl                Super;

// Constructor / Destructor
public:
    VappCamcoCpAdvanceMenu(){}
    virtual ~VappCamcoCpAdvanceMenu(){}

    void setCount(VfxS32 count);

    VfxU32 getCount();

    void setItemCount(VfxU32 idx, VfxU32 Count);

    VfxU32 getItemCount(VfxU32 idx);

    void setSettingData(VfxU32 idx, const vapp_camco_cp_advance_menu_cell_struct &data);

    void setItemData(VfxU32 idx, VfxU32 subIdx, const vapp_camco_cp_advance_menu_cell_struct &data);

    void updateSettingData(VfxU32 idx, VfxU32 subIdx, const vapp_camco_cp_advance_menu_cell_status_struct &data, VfxBool isUpdateView = VFX_FALSE);

private:

    virtual void onInit();
    virtual void onDeinit();

    void onBoundUpdate(VfxFrame * f, const VfxRect & R);

    void notifyScrollStart(VcpScrollable* sender);

    void onSettingBtnClicked(VfxObject* obj, VfxId id);

    void onSliderMove(VcpSlider *slider, VfxFloat value);

    void onSwitchChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);

public:

    VfxSignal2 <
        VfxU32,                     // setting
        VfxU32                      // value
    > m_signalItemSelected;


private:
    VfxS32                                  m_settingCount;
    VfxU32                                  m_itemCount[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT];

    vapp_camco_cp_advance_menu_cell_struct  m_settingList[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT];
    vapp_camco_cp_advance_menu_cell_struct  m_itemList[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT][VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT];

    VcpForm                                *m_form;
    VfxFrame                               *m_shadow[4];
    VcpFormItemCustomFrame                 *m_cell[VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT];
};

#endif /*__VAPP_CAMCO_EXPRESS__*/
#endif /*__VAPP_CAMCO_EXPRESS_ADVANCE_MENU__*/
