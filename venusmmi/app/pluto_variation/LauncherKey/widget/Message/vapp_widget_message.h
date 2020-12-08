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
 *  vapp_widget_message.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the message widget for KeyLaucher project.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_WIDGET_MESSAGE_H
#define VAPP_WIDGET_MESSAGE_H
#include "vapp_widget.h"
#include "vcp_var_height_menu.h"
#include "vapp_msg_data_provider.h"
#include "vcp_waiting_icon.h"

/*const*/
#define WIDGET_MESSAGE_MENU_WIDTH      LCD_WIDTH
#define WIDGET_MESSAGE_MENU_HEIGHT     (WIDGET_MESSAGE_CELL_HEIGHT * (WIDGET_MESSAGE_CELL_COUNT - 1) + WIDGET_MESSAGE_CELL_HEIGHT_H)
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
//QVGA & WQVGA
#ifdef __MMI_MAINLCD_240X320__
#define WIDGET_MESSAGE_CELL_COUNT      2
#else
#define WIDGET_MESSAGE_CELL_COUNT      3
#endif

#define WIDGET_MESSAGE_CELL_WIDTH      191
#define WIDGET_MESSAGE_CELL_HEIGHT     91
#define WIDGET_MESSAGE_CELL_WIDTH_H    191
#define WIDGET_MESSAGE_CELL_HEIGHT_H   99
#define CELL_NAME_FONT_SIZE            VFX_FONT_DESC_VF_SIZE(15)
#define CELL_NAME_POS                  VfxPoint(46, 12)
#define CELL_NAME_SIZE                 VfxSize(100, 15)
#define CELL_PIC_POS                   VfxPoint(15, 14)
#define CELL_PIC_SIZE                  VfxSize(24, 24)
#define CELL_MESSAGE_TYPE_ICON_POS     VfxPoint(23, 24)
#define CELL_MESSAGE_TYPE_ICON_SIZE    VfxSize(14, 15)
#define CELL_EMPTY_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(11)
#define CELL_NUMBER_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(10)
#define CELL_NUMBER_POS                VfxPoint(46, 29)
#define CELL_NUMBER_SIZE               VfxSize(97, 10)
#define CELL_TIME_POS                  VfxPoint(WIDGET_MESSAGE_CELL_WIDTH - 10, 23) //align right
#define CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(8)
#define CELL_COUNTER_POS               VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, WIDGET_MESSAGE_CELL_HEIGHT - 8)
#define CELL_COUNTER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(8)
#define CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(10)
#define CELL_CONTENT_POS               VfxPoint(15, 39)
#define CELL_CONTENT_WIDTH             (WIDGET_MESSAGE_CELL_WIDTH - 15 - 10)//left 15 px, right 10 px
#define CELL_CONTENT_HEIGHT            10 + 2
#define CELL_THUMBNAIL_SIZE            VfxSize(20, 20)
#define CELL_THUMBNAIL_POS             VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, 54)

#elif defined(__MMI_MAINLCD_320X240__)
//LQVGA
#define WIDGET_MESSAGE_CELL_COUNT      2
#define WIDGET_MESSAGE_CELL_WIDTH      191
#define WIDGET_MESSAGE_CELL_HEIGHT     77
#define WIDGET_MESSAGE_CELL_WIDTH_H    191
#define WIDGET_MESSAGE_CELL_HEIGHT_H   79
#define CELL_NAME_FONT_SIZE            VFX_FONT_DESC_VF_SIZE(15)
#define CELL_NAME_POS                  VfxPoint(46, 8)
#define CELL_NAME_SIZE                 VfxSize(100, 15)
#define CELL_PIC_POS                   VfxPoint(12, 10)
#define CELL_PIC_SIZE                  VfxSize(24, 24)
#define CELL_MESSAGE_TYPE_ICON_POS     VfxPoint(23, 20)
#define CELL_MESSAGE_TYPE_ICON_SIZE    VfxSize(14, 15)
#define CELL_EMPTY_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(11)
#define CELL_NUMBER_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(10)
#define CELL_NUMBER_POS                VfxPoint(46, 23)
#define CELL_NUMBER_SIZE               VfxSize(97, 10)
#define CELL_TIME_POS                  VfxPoint(WIDGET_MESSAGE_CELL_WIDTH - 10, 20) //align right
#define CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(8)
#define CELL_COUNTER_POS               VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, WIDGET_MESSAGE_CELL_HEIGHT - 5)
#define CELL_COUNTER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(8)
#define CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(10)
#define CELL_CONTENT_POS               VfxPoint(15, 34)
#define CELL_CONTENT_WIDTH             (WIDGET_MESSAGE_CELL_WIDTH - 15 - 10)//left 16 px, right 16 px
#define CELL_CONTENT_HEIGHT            12 + 2
#define CELL_THUMBNAIL_SIZE            VfxSize(17, 17)
#define CELL_THUMBNAIL_POS             VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, 45)

#else
//HVGA
#define WIDGET_MESSAGE_CELL_COUNT      3
#define WIDGET_MESSAGE_CELL_WIDTH      244
#define WIDGET_MESSAGE_CELL_HEIGHT     110
#define WIDGET_MESSAGE_CELL_WIDTH_H    259
#define WIDGET_MESSAGE_CELL_HEIGHT_H   120
#define CELL_NAME_FONT_SIZE            VFX_FONT_DESC_VF_SIZE(20)
#define CELL_NAME_POS                  VfxPoint(60, 14)
#define CELL_NAME_SIZE                 VfxSize(170, 14)
#define CELL_PIC_POS                   VfxPoint(21, 16)
#define CELL_PIC_SIZE                  VfxSize(35, 35)
#define CELL_MESSAGE_TYPE_ICON_POS     VfxPoint(43, 36)
#define CELL_MESSAGE_TYPE_ICON_SIZE    VfxSize(14, 15)
#define CELL_EMPTY_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(20)
#define CELL_NUMBER_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(14)
#define CELL_NUMBER_POS                VfxPoint(60, 36)
#define CELL_NUMBER_SIZE               VfxSize(120, 14)
#define CELL_TIME_POS                  VfxPoint(WIDGET_MESSAGE_CELL_WIDTH - 15, 37) //align right
#define CELL_TIME_FONE_SIZE            VFX_FONT_DESC_VF_SIZE(10)
#define CELL_COUNTER_POS               VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, WIDGET_MESSAGE_CELL_HEIGHT - 12)
#define CELL_COUNTER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(10)
#define CELL_CONTENT_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(14)
#define CELL_CONTENT_POS               VfxPoint(16, 51)
#define CELL_CONTENT_WIDTH             (WIDGET_MESSAGE_CELL_WIDTH - 16 - 16)//left 16 px, right 16 px
#define CELL_CONTENT_HEIGHT            16 + 2
#define CELL_THUMBNAIL_SIZE            VfxSize(22, 22)
#define CELL_THUMBNAIL_POS             VfxPoint(WIDGET_MESSAGE_CELL_WIDTH >> 1, 66)

#endif


/*message Cell*/
class VappWidgetMsgMenuCell: public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetMsgMenuCell);
public:
    VappWidgetMsgMenuCell(){}
    VappWidgetMsgMenuCell(VappMsgDataProvider * dataProvider, srv_um_msg_node_struct *list, VfxS32 index, VfxU16 msgCount);
public:
    void onInit();
    void onDeinit();
    void setHighlight(VfxBool isAnim);
    void setNormal(VfxBool isAnim);
    void onGetMsgInfoFinished(srv_um_get_msg_info_result result);
    void onExtInfoUpdated();

private:
    void showEmpty();
    void updateCellInfo();
    void showMessgeType(srv_um_msg_enum msgType);

private:
    VfxBool m_isFromFile;
    VfxBool m_status;
    VfxU16 m_resId;
    VfxU16 m_index;
    VfxU16 m_msgCount;
    VfxWString m_contactName;
    VfxWString m_contactNumber;
    VfxWString m_resPath;
    VfxTextFrame *m_name;
    VfxTextFrame *m_number;
    VfxTextFrame *m_time;
    VfxImageFrame *m_callerPic;
    VfxImageFrame *m_messageType;
    VfxImageFrame *m_thumbnail;
    VfxImageFrame *m_bg;
    VfxTextFrame *m_content;
    VfxTextFrame *m_subject;
    VfxTextFrame *m_counter;
    VcpWaitingIcon *m_indicator;
    VappMsgDataProvider *m_data;
    srv_um_msg_info_struct *m_msgInfo;
    srv_um_msg_node_struct *m_list;
};

/*layout*/
class VappWidgetMsgMenuLayout: public VcpVarHeightMenuLayout
{
public:
    VappWidgetMsgMenuLayout(VcpVarHeightMenu *menu);
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
    void setHasNoMsg(VfxBool isListEmpty)
    {
        m_hasNoMSG = isListEmpty;
    }
private:
    VfxU32 m_cellCount;
    VfxU32 m_cellHeight;
    VfxBool m_hasNoMSG;
};

class VappWidgetMsgMenu : public VcpVarHeightMenu
{
    VFX_DECLARE_CLASS(VappWidgetMsgMenu);
public:
    VappWidgetMsgMenu(){	}
public:
    void onInit();
    void onDeinit();
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
public:
    VfxSignal2 <
        VfxS32,
        VfxBool
        > m_signalViewMessage;


private:
    static void getMsgListCB(
                    VfxS32 event,
                    VfxS32 list_cid,
                    VfxS32 user_data);
    void onGetMsgListFinished(srv_um_get_msg_list_result result);
    srv_um_msg_enum getMsgType(VfxU32 index);
    VfxU32 getMsgId(VfxU32 index);
    VfxU16 getMsgNum();
    VfxS32 getMsgIndex(srv_um_msg_enum msgType, U32 msgId);
    void viewMsg(VfxS32 index, VfxBool isCsk);
    void updateMenu(VfxU16 msgCount);
    void setHighlight(VfxS32 index);
        
private:
    static VfxS32 m_highlightIndex;
    static VfxRect m_viewBounds;
    static srv_um_msg_node_struct m_highlightMsg;
private:
    VfxS32 m_itemCount;
    VfxS32 m_listId;
    VfxBool m_tapFlag;
    VcpBaseMenuLayout::NavDirEnum m_navDir;
    VappMsgDataProvider *m_data;
    srv_um_box_identity_struct m_msgBox;
    srv_um_list_filter_struct m_listFilter;
    srv_um_list_cntx_struct * m_listCntx;
    VcpWaitingIcon *m_indicator;
};


/**/
class VappWidgetMsg: public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetMsg);
public :
    VappWidgetMsg(){}
    ~VappWidgetMsg(){}
public :
    static mmi_ret onUmSrvReady(mmi_event_struct * evt);
    static mmi_ret onUmListRefresh(mmi_event_struct * evt);
public :
    void onCreateView();
    void onReleaseView();
    VfxFrame* createIcon(VfxObject *parentObj);
    VfxS32 getName(VfxWChar *string, VfxS32 size)const;
    VappWidgetId getId() const;
    VfxSize getMaxSize() const;
    void setHidden(VfxBool value);
private :
    void resetWidget();
private :
    VappWidgetMsgMenu *m_menu;
};
#endif
