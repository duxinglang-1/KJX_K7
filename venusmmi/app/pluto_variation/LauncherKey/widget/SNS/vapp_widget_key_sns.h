/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_key_sns.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the sns widget for KeyLaucher project.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_WIDGET_KEY_SNS_H
#define VAPP_WIDGET_KEY_SNS_H
#include "vapp_widget.h"
#include "vcp_var_height_menu.h"
#include "vcp_waiting_icon.h"
#include "MMIDataType.h"

extern "C"
{
    #include "snssrvgprot.h"
}


/*const*/
#define WIDGET_SNS_MENU_WIDTH              LCD_WIDTH
#define WIDGET_SNS_MENU_HEIGHT             (WIDGET_SNS_CELL_DEFAULT_HEIGHT + WIDGET_SNS_CELL_HIGHLIGHT_HEIGHT)
#define WIDGET_SNS_WAITING_ICON_SIZE       VfxSize(50, 50)

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
//QVGA&WQVGA
#define WIDGET_SNS_CELL_DEFAULT_WIDTH      185
#define WIDGET_SNS_CELL_DEFAULT_HEIGHT     100
#define WIDGET_SNS_CELL_HIGHLIGHT_WIDTH    185
#define WIDGET_SNS_CELL_HIGHLIGHT_HEIGHT   110
#define WIDGET_SNS_CELL_EMPTY_WIDTH        154
#define WIDGET_SNS_CELL_EMPTY_HEIGHT       87
#define WIDGET_SNS_WARNING_TEXT_WIDTH      WIDGET_SNS_CELL_EMPTY_WIDTH - 14 - 14
#define WIDGET_SNS_WARNING_TEXT_HEIGHT     50
#define WIDGET_SNS_WARNING_TEXT_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(11)
#define SNS_CELL_NICK_NAME_FONT_SIZE       VFX_FONT_DESC_VF_SIZE(15)
#define SNS_CELL_NICK_NAME_POS             VfxPoint(52, 13)
#define SNS_CELL_NICK_NAME_SIZE            VfxSize(87, 15)
#define SNS_CELL_HEAD_PORTRAIT_POS         VfxPoint(18, 13)
#define SNS_CELL_HEAD_PORTRAIT_SIZE        VfxSize(30, 30)
#define SNS_CELL_PROVIDER_ICON_POS_Y       15
#define SNS_CELL_PROVIDER_ICON_POS_X       18//distance from right
#define SNS_CELL_PROVIDER_ICON_SIZE        VfxSize(24, 24)
#define SNS_CELL_CONTENT_LINE              3
#define SNS_CELL_CONTENT_POS               VfxPoint(11, 43)
#define SNS_CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(10)
#define SNS_CELL_CONTENT_WIDTH             13//distance from side
#define SNS_CELL_CONTENT_HEIGHT            15
#define SNS_CELL_ATTACHMENT_SIZE           VfxSize(46, 36)
#define SNS_CELL_ATTACHMENT_POS_Y          55
#define SNS_CELL_TIME_POS                  VfxPoint(52, 32)
#define SNS_CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(10)

#elif defined(__MMI_MAINLCD_320X240__)
//LQVGA
#define WIDGET_SNS_CELL_DEFAULT_WIDTH      185
#define WIDGET_SNS_CELL_DEFAULT_HEIGHT     77
#define WIDGET_SNS_CELL_HIGHLIGHT_WIDTH    185
#define WIDGET_SNS_CELL_HIGHLIGHT_HEIGHT   79
#define WIDGET_SNS_CELL_EMPTY_WIDTH        154
#define WIDGET_SNS_CELL_EMPTY_HEIGHT       87
#define WIDGET_SNS_WARNING_TEXT_WIDTH      WIDGET_SNS_CELL_EMPTY_WIDTH - 14 - 14
#define WIDGET_SNS_WARNING_TEXT_HEIGHT     50
#define WIDGET_SNS_WARNING_TEXT_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(11)
#define SNS_CELL_NICK_NAME_FONT_SIZE       VFX_FONT_DESC_VF_SIZE(15)
#define SNS_CELL_NICK_NAME_POS             VfxPoint(52, 13)
#define SNS_CELL_NICK_NAME_SIZE            VfxSize(87, 15)
#define SNS_CELL_HEAD_PORTRAIT_POS         VfxPoint(18, 13)
#define SNS_CELL_HEAD_PORTRAIT_SIZE        VfxSize(30, 30)
#define SNS_CELL_PROVIDER_ICON_POS_Y       17
#define SNS_CELL_PROVIDER_ICON_POS_X       18//distance from right
#define SNS_CELL_PROVIDER_ICON_SIZE        VfxSize(24, 24)
#define SNS_CELL_CONTENT_LINE              2
#define SNS_CELL_CONTENT_POS               VfxPoint(18, 43)
#define SNS_CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(10)
#define SNS_CELL_CONTENT_WIDTH             18//distance from side
#define SNS_CELL_CONTENT_HEIGHT            15
#define SNS_CELL_ATTACHMENT_SIZE           VfxSize(20, 15)
#define SNS_CELL_ATTACHMENT_POS_Y          55
#define SNS_CELL_TIME_POS                  VfxPoint(52, 32)
#define SNS_CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(10)

#else
//HVGA
#define WIDGET_SNS_CELL_DEFAULT_WIDTH      244
#define WIDGET_SNS_CELL_DEFAULT_HEIGHT     148
#define WIDGET_SNS_CELL_HIGHLIGHT_WIDTH    258
#define WIDGET_SNS_CELL_HIGHLIGHT_HEIGHT   160
#define WIDGET_SNS_CELL_EMPTY_WIDTH        246
#define WIDGET_SNS_CELL_EMPTY_HEIGHT       111
#define WIDGET_SNS_WARNING_TEXT_WIDTH      220
#define WIDGET_SNS_WARNING_TEXT_HEIGHT     100
#define WIDGET_SNS_WARNING_TEXT_FONT_SIZE  VFX_FONT_DESC_VF_SIZE(20)
#define SNS_CELL_NICK_NAME_FONT_SIZE       VFX_FONT_DESC_VF_SIZE(20)
#define SNS_CELL_NICK_NAME_POS             VfxPoint(59, 19)
#define SNS_CELL_NICK_NAME_SIZE            VfxSize(115, 20)
#define SNS_CELL_HEAD_PORTRAIT_POS         VfxPoint(19, 19)
#define SNS_CELL_HEAD_PORTRAIT_SIZE        VfxSize(35, 35)
#define SNS_CELL_PROVIDER_ICON_POS_Y       18
#define SNS_CELL_PROVIDER_ICON_POS_X       18//distance from right
#define SNS_CELL_PROVIDER_ICON_SIZE        VfxSize(35, 35)
#define SNS_CELL_CONTENT_LINE              5
#define SNS_CELL_CONTENT_POS               VfxPoint(18, 58)
#define SNS_CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(14)
#define SNS_CELL_CONTENT_WIDTH             18//distance from side
#define SNS_CELL_CONTENT_HEIGHT            15
#define SNS_CELL_ATTACHMENT_SIZE           VfxSize(80, 60)
#define SNS_CELL_ATTACHMENT_POS_Y          73
#define SNS_CELL_TIME_POS                  VfxPoint(59, 44)
#define SNS_CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(10)

#endif

/*sns Cell*/
class VappWidgetSNSMenuCell: public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetSNSMenuCell);
public:
    enum CellStatusEnum
    {
        WIDGET_SNS_CELL_STATUS_NO_ACCOUNT,
        WIDGET_SNS_CELL_STATUS_NO_RECENT,
        WIDGET_SNS_CELL_STATUS_NOT_READY,
        WIDGET_SNS_CELL_STATUS_LOAD_FAIL,
        WIDGET_SNS_CELL_STATUS_MASS_MODE,
        WIDGET_SNS_CELL_STATUS_MEMORY_FULL,
        WIDGET_SNS_CELL_STATUS_NO_CARD,
        WIDGET_SNS_CELL_STATUS_NORMAL,
        WIDGET_SNS_CELL_STATUS_TOTAL        
    };
public:
    VappWidgetSNSMenuCell(){}
    VappWidgetSNSMenuCell(VfxS32 list, VfxU16 index, CellStatusEnum status);
public:
    void onInit();
    void onDeinit();
    void setNormal(VfxBool isAnim);
    void setHighlight(VfxBool isAnim);
    CellStatusEnum getCellStatus()
    {
        return m_status;
    }
    void updateHeadPortrait(VfxWChar *path);
    void updateAttachment(VfxWChar *path);
private:
    void setNoMemoryCard();
    void setMemoryFull();
    void setMassMode();
    void setNoAccount();
    void setNoRecent();
    void setNotReady();
    void setLoadFail();
    void setEmpty();
    void updateCell();
private:
    VfxS32 m_listId;
    VfxU16 m_index;
    CellStatusEnum m_status;
    VfxTextFrame *m_nickName;
    VfxTextFrame *m_content;
    VfxTextFrame *m_time;
    VfxImageFrame *m_headPortrait;
    VfxImageFrame *m_attachment;
    VfxImageFrame * m_providerIcon;
    VfxImageFrame *m_bg;
};

/*layout*/
class VappWidgetSNSMenuLayout: public VcpVarHeightMenuLayout
{
public:
    VappWidgetSNSMenuLayout(VcpVarHeightMenu *menu);
public:
    void onInit();
    void onDeinit();
    VfxS32 getGroupCount()
    {
        return 1;
    }
    VfxS32 getContentLength();
    VfxRect queryCellRect(VcpMenuPos pos);
    VcpMenuPos queryPosByPt(VfxS32 y);
private:
    VfxU32 m_cellCount;
    VfxU32 m_cellHeight;
};

/*sns widget menu*/
class VappWidgetSNSMenu : public VcpVarHeightMenu
{
    VFX_DECLARE_CLASS(VappWidgetSNSMenu);
public:
    VappWidgetSNSMenu(){}
public:
    VfxSignal0 m_signalSetAccount;
    VfxSignal1 <
        VfxS32
        > m_signalViewRecent;
public:
    void onInit();
    void onDeinit();
    static mmi_ret onListLoaded(mmi_event_struct *param);
    VcpBaseMenuLayout * createLayout();
    VfxFrame * createCell(VfxS32 group, VfxS32 pos);
    void onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame);
    void onUpdateCell(
        const VfxRect &rect,
        VfxS32 group,
        VfxS32 pos,
        VfxFrame* cell,
        VfxU32 flag
    );
    void onTouchCell(
        VcpMenuPos          cellPos,
        CellTouchTypeEnum   touchType,
        VfxPoint            pt,
        VfxFrame            *cell
    );
    void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem);
    VfxBool onKeyInput(VfxKeyEvent & event);
    void onViewScrollEnd();
    void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    VfxS32 getHighlightIndex()
    {
        return m_highlightIndex;
    }
    void updateCellInfo(VfxS32 list_id, VfxS16 index, srv_sns_pic_enum pic_type, VfxWChar *path);
public :
    static mmi_ret onItemUpdated(mmi_event_struct *evt);
private :
    void updateList(VfxS32 result, VfxU16 cellCount);
    void onSetAccount();
    void onViewRecent(VfxS32 index);
    void loadList(VfxS32 listId, VfxS16 startIndex);
    void loadList();
    void preLoadList();
    void reloadList();
    void onTime(VfxTimer *pTimer);

private :
    static mmi_id m_groupId;
    static VfxS32 m_highlightIndex;
    static VfxS32 m_list;
    static VfxRect m_viewBounds;
    static VfxObjHandle m_menuHandle;
    VfxBool m_releaseList;
    VfxBool m_tapFlag;
    VappWidgetSNSMenuCell::CellStatusEnum m_status;
    VfxS32 m_itemCount;
    VcpBaseMenuLayout::NavDirEnum m_navDir;
    VcpWaitingIcon *m_indicator;
};


/**/
class VappWidgetSNS: public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetSNS);
public :
    VappWidgetSNS(){}
    ~VappWidgetSNS(){}

public :
    void onCreateView();
    void onReleaseView();
    VfxFrame* createIcon(VfxObject *parentObj);
    VfxS32 getName(VfxWChar *string, VfxS32 size)const;
    VappWidgetId getId() const;
    VfxSize getMaxSize() const;
    void setHidden(VfxBool value);
    void createMenu();
    static mmi_ret onSnsSrvReady(mmi_event_struct *evt);
    static mmi_ret onMsModeExit(mmi_event_struct *evt);
private :
    VappWidgetSNSMenu *m_menu;
};
#endif
