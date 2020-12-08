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
 *  vapp_widget_message.cpp
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

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_message.h"
#include "mmi_rp_vapp_widget_message_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "Vapp_msg_data_provider.h"
#include "phbsrvgprot.h"
#include "GlobalResDef.h"
extern "C"
{
    #include "MsgViewerCui.h"
    #include "umsrvgprot.h"
    #ifdef __MMI_USB_SUPPORT__
    #include "USBSrvGprot.h"
    #endif
    #include "MMSAppInterfaceGprot.h"
}

VFX_IMPLEMENT_CLASS("VappWidgetMsgMenuCell", VappWidgetMsgMenuCell, VfxFrame);
VappWidgetMsgMenuCell::VappWidgetMsgMenuCell(VappMsgDataProvider *dataProvider, srv_um_msg_node_struct *list, VfxS32 index, VfxU16 msgCount):
    m_status(VFX_TRUE),
    m_name(NULL),
    m_number(NULL),
    m_callerPic(NULL),
    m_messageType(NULL),
    m_time(NULL),
    m_content(NULL),
    m_subject(NULL),
    m_indicator(NULL)
{
    m_list = list;
    m_index = index;
    m_msgCount = msgCount;
    m_data = dataProvider;
}
void VappWidgetMsgMenuCell::onInit()
{
    VfxFrame::onInit();
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    if (m_index == ((VappWidgetMsgMenu*)getParentFrame())->getHighlightIndex())
    {
        setHighlight(VFX_FALSE);
    }
    else
    {
        setNormal(VFX_FALSE);
    }
    VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_number, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_callerPic, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_messageType, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_thumbnail, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_time, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_content, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_subject, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_counter, VfxTextFrame, this);
    m_data->m_signalGetMsgInfoFinished.connect(this, &VappWidgetMsgMenuCell::onGetMsgInfoFinished);
    m_data->m_signalExtInfoUpdated.connect(this, &VappWidgetMsgMenuCell::onExtInfoUpdated);
    if (m_msgCount != 0)
    {
        VfxWString counter;
        counter.format("%d / %d", m_index + 1, m_msgCount);
        m_counter->setString(counter);
        m_counter->setFont(VfxFontDesc(CELL_COUNTER_FONT_SIZE));
        m_counter->setAnchor(0.5, 1.0);
        m_counter->setPos(CELL_COUNTER_POS);
        updateCellInfo();
        if (m_status == VFX_FALSE)
        {
            VFX_OBJ_CREATE(m_indicator, VcpWaitingIcon, this);
            m_indicator->setAnchor(0.5, 0.5);
            m_indicator->setPos(WIDGET_MESSAGE_CELL_WIDTH >> 1, WIDGET_MESSAGE_CELL_HEIGHT >> 1);
            m_indicator->start();
        }
    }
    else
    {
        showEmpty();
    }

}

void VappWidgetMsgMenuCell::showEmpty()
{
    setSize(WIDGET_MESSAGE_CELL_WIDTH, WIDGET_MESSAGE_CELL_HEIGHT);
    m_bg->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG);
    m_bg->setSize(WIDGET_MESSAGE_CELL_WIDTH, WIDGET_MESSAGE_CELL_HEIGHT);
    m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_name->setString(VfxWString(STR_ID_VAPP_WIDGET_MESSAGE_NO_MESSAGE));
    m_name->setFont(VfxFontDesc(CELL_EMPTY_FONT_SIZE));
    m_name->setAnchor(0.5,0.5);
    m_name->setPos(WIDGET_MESSAGE_CELL_WIDTH >> 1, WIDGET_MESSAGE_CELL_HEIGHT >> 1);
}


void VappWidgetMsgMenuCell::onGetMsgInfoFinished(srv_um_get_msg_info_result result)
{
    if (result.error == SRV_UM_RESULT_OK)
    {
        updateCellInfo();
        if (m_indicator != NULL && m_indicator->isAnimating() == VFX_TRUE && m_status == VFX_TRUE)
        {
            m_indicator->stop();
            VFX_OBJ_CLOSE(m_indicator);
            m_data->m_signalGetMsgInfoFinished.disconnect(this, &VappWidgetMsgMenuCell::onGetMsgInfoFinished);
            m_data->m_signalExtInfoUpdated.disconnect(this, &VappWidgetMsgMenuCell::onExtInfoUpdated);
        }
    }
}

void VappWidgetMsgMenuCell::onExtInfoUpdated()
{
    updateCellInfo();
    if (m_indicator != NULL && m_indicator->isAnimating() == VFX_TRUE && m_status == VFX_TRUE)
    {
        m_indicator->stop();
        VFX_OBJ_CLOSE(m_indicator);
        m_data->m_signalGetMsgInfoFinished.disconnect(this, &VappWidgetMsgMenuCell::onGetMsgInfoFinished);
        m_data->m_signalExtInfoUpdated.disconnect(this, &VappWidgetMsgMenuCell::onExtInfoUpdated);
    }
}

void VappWidgetMsgMenuCell::updateCellInfo()
{
    m_status = VFX_TRUE;
    VfxWString content;
    VfxS32 result = m_data->getMsgInfo(
                        m_list,
                        m_msgCount,
                        m_index,
                        1,
                        &m_msgInfo);
    if (result == SRV_UM_RESULT_OK)
    { 
        VfxWString number;
        number.loadFromMem(m_msgInfo->address);
        m_number->setString(number);
        m_number->setFont(VfxFontDesc(CELL_NUMBER_FONT_SIZE));
        m_number->setPos(CELL_NUMBER_POS);
        m_number->setSize(CELL_NUMBER_SIZE);
        m_number->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        m_number->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        VfxU16 storeIndex;
        VfxWString nameStr;
        m_callerPic->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_DEFAULT_HEADPORTRAIT);
        if (srv_phb_get_store_index_by_number((U16*)m_msgInfo->address, &storeIndex) == MMI_TRUE)
        {
            srv_phb_contact contact = srv_phb_read_contact(storeIndex, NULL, NULL);
            VfxWChar *name = srv_phb_contact_get_name(contact);
            if (name != NULL)
            {
                nameStr.loadFromMem(name);
            }
            else
            {
                nameStr.loadFromRes(STR_GLOBAL_UNNAMED);
            }
            srv_phb_res_struct * pic = srv_phb_contact_get_image(contact);
            if (pic != NULL
                #ifdef __MMI_USB_SUPPORT__
                && srv_usb_is_in_mass_storage_mode() == MMI_FALSE
                #endif
                )
            {
                if (pic->res_path[0])
                {
                    if (srv_fmgr_fs_path_exist(pic->res_path) == 0)
                    {
                        VfxWString resPath;
                        resPath.loadFromMem(pic->res_path);
                        m_callerPic->setPath(resPath);
                    }
                }
                else if (!(pic->res_id & 0x8000))
                {
                    m_callerPic->setResId(pic->res_id);
                }
            }
            srv_phb_free_contact(contact);
        }
        else
        {
            nameStr.loadFromRes(STR_ID_VAPP_WIDGET_MESSAGE_UNSAVED);
        }
    
        m_name->setString(nameStr);
        m_name->setAnchor(0.0, 0.0);
        m_name->setPos(CELL_NAME_POS);
        m_name->setFont(VfxFontDesc(CELL_NAME_FONT_SIZE));
        m_name->setSize(CELL_NAME_SIZE);
        m_name->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
        m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_callerPic->setSize(CELL_PIC_SIZE);
        m_callerPic->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_callerPic->setPos(CELL_PIC_POS);
        if (m_msgInfo->subject[0] != 0)
        {
            if (m_list[m_index].msg_type != SRV_UM_MSG_SMS)
            {
                content += VFX_WSTR_RES(STR_GLOBAL_SUBJECT);
                content += VFX_WSTR(": ");
            }
            content += VFX_WSTR_MEM(m_msgInfo->subject);
        }
        applib_time_struct myTime;
        applib_time_struct today;
        applib_dt_get_date_time(&today);
        mmi_dt_utc_sec_2_mytime(applib_dt_sec_utc_to_local(m_msgInfo->timestamp), &myTime, MMI_FALSE);
        VfxDateTime time;
        time.setDateTime(&myTime);
        if (myTime.nDay == today.nDay)
        {
            m_time->setString(time.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE));
        }
        else
        {
            m_time->setString(time.getDateTimeString(VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY));
        }
        m_time->setFont(VfxFontDesc(CELL_TIME_FONE_SIZE));
        m_time->setAnchor(1.0, 0.0);
        m_time->setPos(CELL_TIME_POS);
    }
    else
    {
        m_status = VFX_FALSE;
    }
    showMessgeType(m_list[m_index].msg_type);
    const VfxWChar* contentBuf = m_data->getMsgContent(m_list + m_index);
    if (contentBuf != NULL)
    {
        if (contentBuf[0] != 0)
        {
            content.loadFromMem(contentBuf);
        }
    }
    else
    {
        m_status = VFX_FALSE;
        
    }
    if (!content.isEmpty())
    {
        VfxS32 line = 2;
        VfxTextFrame::LineModeEnum lineMode = VfxTextFrame::LINE_MODE_MULTI;
        if (m_list[m_index].msg_type == SRV_UM_MSG_MMS)
        {
            line = 1;
            lineMode = VfxTextFrame::LINE_MODE_SINGLE;
        }
        m_content->setString(content);
        m_content->setFont(VfxFontDesc(CELL_CONTENT_FONT_SIZE));
        m_content->setAutoResized(VFX_FALSE);
        m_content->setSize(CELL_CONTENT_WIDTH, line * CELL_CONTENT_HEIGHT);
        m_content->setLineMode(lineMode);
        m_content->setLineGap(1);
        m_content->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_content->setColor(VFX_COLOR_WHITE);
        m_content->setPos(CELL_CONTENT_POS);
    }
    if (m_list[m_index].msg_type == SRV_UM_MSG_MMS)
    {
        VfxWChar *thumbnail = NULL;
        VappMsgWidgetExtInfoThumbnailResult thumbResult = m_data->getMsgThumbnail(m_list + m_index, (void**)&thumbnail);
        if (thumbResult != VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_PROCESSING)
        {
            if (thumbResult != VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_FAIL && thumbResult != VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_NO_THUMBNAIL)
            {
    		    if(thumbnail)
    		    {
    		        VfxWString path;
                    path.loadFromMem(thumbnail);
                    m_thumbnail->setPath(path);
        		}
                else if (thumbResult == VAPP_MSG_WIDGET_EXT_THUMBNAIL_RESULT_VIDEO)
                {
                    m_thumbnail->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_ICON_VIDEO);
                }
                else
                {
                    m_thumbnail->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_ICON_DEFAULT);
                }
                m_thumbnail->setSize(CELL_THUMBNAIL_SIZE);
                m_thumbnail->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                m_thumbnail->setAnchor(0.5, 0.0);
                m_thumbnail->setPos(CELL_THUMBNAIL_POS);
            }
		}
        else
        {
            m_status = VFX_FALSE;
        }
    }
    const VappMsgReadStatus* readStatus =  m_data->getMsgReadStatus(m_list + m_index);
    if (readStatus != NULL)
    {
        if (*readStatus == VAPP_MSG_READ_STATUS_UNREAD)
        {
            VfxFontDesc textFont;
            textFont.size = CELL_NAME_FONT_SIZE;
            textFont.attr |= VFX_FONT_DESC_ATTR_BOLD;
            m_name->setFont(textFont);
            textFont.size = CELL_NUMBER_FONT_SIZE;
            m_number->setFont(textFont);
        }            
    }
    else
    {
        m_status = VFX_FALSE;
    } 
}

void VappWidgetMsgMenuCell::setHighlight(VfxBool isAnim)
{
    setSize(WIDGET_MESSAGE_CELL_WIDTH_H, WIDGET_MESSAGE_CELL_HEIGHT_H);
    if (isAnim == VFX_FALSE)// not support animation now
    {
        if (m_index % 2 == 0)
        {
            m_bg->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_HL);
        }
        else
        {
            m_bg->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_HR);
        }
        m_bg->setSize(WIDGET_MESSAGE_CELL_WIDTH_H, WIDGET_MESSAGE_CELL_HEIGHT_H);
        m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }
}

void VappWidgetMsgMenuCell::setNormal(VfxBool isAnim)
{
    setSize(WIDGET_MESSAGE_CELL_WIDTH, WIDGET_MESSAGE_CELL_HEIGHT);
    if (isAnim == VFX_FALSE)// not support animation now
    {
        if (m_index % 2 == 0)
        {
            m_bg->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_NL);
        }
        else
        {
            m_bg->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_NR);
        }
        m_bg->setSize(WIDGET_MESSAGE_CELL_WIDTH, WIDGET_MESSAGE_CELL_HEIGHT);
        m_bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }
}

void VappWidgetMsgMenuCell::showMessgeType(srv_um_msg_enum msgType)
{
    VfxBool isShow = VFX_FALSE;
    switch (msgType)
    {
        case SRV_UM_MSG_MMS:
            m_messageType->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_MMS);
            isShow = VFX_TRUE;
            break;
        case SRV_UM_MSG_WAP_PUSH:
            m_messageType->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_WAP);
            isShow = VFX_TRUE;
            break;
        case SRV_UM_MSG_PROV:
            m_messageType->setResId(IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_PRO);
            isShow = VFX_TRUE;
            break;
    }
    if (isShow == VFX_TRUE)
    {
        m_messageType->setSize(CELL_MESSAGE_TYPE_ICON_SIZE);
        m_messageType->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_messageType->setPos(CELL_MESSAGE_TYPE_ICON_POS);
    }
}

void VappWidgetMsgMenuCell::onDeinit()
{
    VFX_OBJ_CLOSE(m_name);
    VFX_OBJ_CLOSE(m_number);
    VFX_OBJ_CLOSE(m_callerPic);
    VFX_OBJ_CLOSE(m_messageType);
    VFX_OBJ_CLOSE(m_thumbnail);
    VFX_OBJ_CLOSE(m_bg);
    VFX_OBJ_CLOSE(m_time);
    VFX_OBJ_CLOSE(m_content);
    VFX_OBJ_CLOSE(m_subject);
    VFX_OBJ_CLOSE(m_counter);
    VfxFrame::onDeinit();
}

VappWidgetMsgMenuLayout::VappWidgetMsgMenuLayout(VcpVarHeightMenu *menu):
     VcpVarHeightMenuLayout(menu)
 {
 }

void VappWidgetMsgMenuLayout::onInit()
{
    VcpVarHeightMenuLayout::onInit();
    m_hasNoMSG = VFX_TRUE;
    m_cellHeight = WIDGET_MESSAGE_CELL_HEIGHT;
}

void VappWidgetMsgMenuLayout::onDeinit()
{
    VcpVarHeightMenuLayout::onDeinit();
}

VfxS32 VappWidgetMsgMenuLayout::getContentLength()
{
    if (m_hasNoMSG == VFX_FALSE)
    {
        return (getVarHeightMenu()->getCellCount() - 1) * m_cellHeight + WIDGET_MESSAGE_CELL_HEIGHT_H;
    }
    return m_cellHeight;
}

VfxRect VappWidgetMsgMenuLayout::queryCellRect(VcpMenuPos pos)
{
    VfxS32 x = 0;
    VfxS32 y = pos.pos * WIDGET_MESSAGE_CELL_HEIGHT;
    VfxS32 width = WIDGET_MESSAGE_CELL_WIDTH;
    VfxS32 height = WIDGET_MESSAGE_CELL_HEIGHT;
    if (pos.pos % 2 != 0)
    {
        x = WIDGET_MESSAGE_MENU_WIDTH - 1;
    }
    VcpMenuPos focusPos = getVarHeightMenu()->getFocusItem();
    if (focusPos.isValid() && m_hasNoMSG == VFX_FALSE)
    {
        if (focusPos == pos)
        {
            width = WIDGET_MESSAGE_CELL_WIDTH_H;
            height = WIDGET_MESSAGE_CELL_HEIGHT_H;
        }
        else if (pos.pos > focusPos.pos)
        {
            y += WIDGET_MESSAGE_CELL_HEIGHT_H - WIDGET_MESSAGE_CELL_HEIGHT;
        }
    }
    return VfxRect(x, y, width, height);
}

VcpMenuPos VappWidgetMsgMenuLayout::queryPosByPt(VfxS32 y)
{
     return VcpVarHeightMenuLayout::queryPosByPt(y);
}


VFX_IMPLEMENT_CLASS("VappWidgetMsgMenu", VappWidgetMsgMenu, VcpVarHeightMenu);
VfxS32 VappWidgetMsgMenu::m_highlightIndex = 0;
VfxRect VappWidgetMsgMenu::m_viewBounds = VfxRect(0, 0, 0, 0);

srv_um_msg_node_struct VappWidgetMsgMenu::m_highlightMsg = {SRV_UM_MSG_NONE, 0};

void VappWidgetMsgMenu::onInit()
{
    VcpVarHeightMenu::onInit();
    m_itemCount = 0;
    m_listCntx = NULL;
    m_listId = -1;
    m_navDir = VcpBaseMenuLayout::NAV_DIR_NONE;
    m_tapFlag = VFX_FALSE;
    VfxKeypad::registerHandler(VFX_KEY_CODE_CSK, this);
    m_signalViewMessage.connect(this, &VappWidgetMsgMenu::viewMsg);
    setPos(0, 0);
    VFX_OBJ_CREATE(m_data, VappMsgDataProvider, this);
    m_msgBox.msg_box_type = SRV_UM_MSG_BOX_INBOX;
    m_msgBox.msg_type = SRV_UM_MSG_ALL;
    m_msgBox.sim_id = SRV_UM_SIM_ALL;
	memset(&m_listFilter, 0, sizeof(m_listFilter));
    m_data->m_signalGetMsgListFinished.connect(this,&VappWidgetMsgMenu::onGetMsgListFinished);
    VfxS32 result = m_data->getMsgList(
                        m_msgBox,
                        m_listFilter,
                        &VappWidgetMsgMenu::getMsgListCB,
                        (VfxS32)getObjHandle(),
                        m_listCntx);
    if (result < SRV_UM_RESULT_OK)
    {
        setSize(50, 50);
        VFX_OBJ_CREATE(m_indicator, VcpWaitingIcon, this);
        m_indicator->setHiddenWhenStopped(VFX_TRUE);
        m_indicator->setAnchor(0.5, 0.5);
        m_indicator->setPos((getParentFrame())->getSize().width >> 1, (getParentFrame())->getSize().height >> 1);
        m_indicator->start();
    }
    else
    {
        m_listId = result;
        updateMenu(m_listCntx->msg_number);
    } 
    setDefaultHeight(WIDGET_MESSAGE_CELL_HEIGHT);
}

void VappWidgetMsgMenu::getMsgListCB(VfxS32 event, VfxS32 listCid, VfxS32 userData)
{
    VappWidgetMsgMenu *self = (VappWidgetMsgMenu *)VfxObject::handleToObject((VfxObjHandle)userData);
    if (self->isValid() && self->m_listId == listCid && event == SRV_UM_NOTIFY_LIST_RELEASED_IND)
    {
        self->m_listId = -1;
    }
}

void VappWidgetMsgMenu::onGetMsgListFinished(srv_um_get_msg_list_result result)
{
    VfxS32 getMsgResult = m_data->getMsgList(
                        m_msgBox,
                        m_listFilter,
                        &VappWidgetMsgMenu::getMsgListCB,
                        (VfxS32)getObjHandle(),
                        m_listCntx);
	if (getMsgResult > SRV_UM_RESULT_OK)
	{
	    m_listId = getMsgResult;
	    updateMenu(m_listCntx->msg_number);
        if (m_indicator->isAnimating() == VFX_TRUE)
        {
            m_indicator->stop();
            VFX_OBJ_CLOSE(m_indicator);
        }
        updateLayout();
        VappWidgetMsgMenuLayout *layout = (VappWidgetMsgMenuLayout *)getLayout();
        VfxPoint origin = layout->queryCellRect(getFocusItem()).origin;
        if (m_viewBounds.contains(origin) && (m_viewBounds.origin.y + m_viewBounds.getHeight() - origin.y) > (WIDGET_MESSAGE_CELL_HEIGHT_H - WIDGET_MESSAGE_CELL_HEIGHT))
        {
            makeVisible(m_viewBounds, VFX_TRUE);
        }
        else
        {
            makeVisible(getFocusItem(), VFX_TRUE);
        }
	}
    else
    {
        m_listId = -1;
    }
}

srv_um_msg_enum VappWidgetMsgMenu::getMsgType(VfxU32 index)
{
    srv_um_msg_node_struct *list = (srv_um_msg_node_struct *)(m_listCntx->list);
    return list[index].msg_type;
}

VfxU32 VappWidgetMsgMenu::getMsgId(VfxU32 index)
{
    srv_um_msg_node_struct *list = (srv_um_msg_node_struct *)(m_listCntx->list);
    return list[index].msg_id;
}

VfxU16 VappWidgetMsgMenu::getMsgNum()
{
    return (m_listCntx->msg_number);
}

VfxS32 VappWidgetMsgMenu::getMsgIndex(srv_um_msg_enum msgType, U32 msgId)
{
    VfxS32 index;
    srv_um_msg_node_struct *list = (srv_um_msg_node_struct *)(m_listCntx->list);
    for (index = 0; index < getMsgNum(); index ++)
    {            
        if (list[index].msg_id == msgId && list[index].msg_type == msgType)
        {
            return index;
        }
    }
    return -1;
}

void VappWidgetMsgMenu::viewMsg(VfxS32 index, VfxBool isCsk)
{
    mmi_id group_id;
    mmi_id parent_group_id;
    VfxU32 msgId = getMsgId(index);
    srv_um_msg_enum msgType = getMsgType(index);
    if (SRV_UM_MSG_MMS == msgType)
    {
        if (isCsk)
        {
            if (!mmi_umms_if_cui_launch_from_widjet(msgId , CUI_MSG_VIEWER_TYPE_CSK_KEY))
            {
                return;
            }
        }
        else
        {
            if (!mmi_umms_if_cui_launch_from_widjet(msgId , CUI_MSG_VIEWER_TYPE_INTUITIVE_CMD))
            {
                return;
            }
        }
    }
    parent_group_id = mmi_frm_group_create(
                   GRP_ID_ROOT,
                   GRP_ID_AUTO_GEN,
                   NULL,
                   NULL);
    mmi_frm_group_enter(parent_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    group_id = cui_msg_viewer_create(parent_group_id, msgId, msgType, 0);
    if (GRP_ID_INVALID != group_id)
    {
        if (isCsk == VFX_TRUE)
        {
            cui_msg_viewer_set_widget_csk_invoke(group_id);
        }
        else
        {
            cui_msg_viewer_set_widget_tap_invoke(group_id);
        }
        cui_msg_viewer_run(group_id);
    }
    else
    {
        mmi_frm_group_close(parent_group_id);
    }
}

void VappWidgetMsgMenu::updateMenu(VfxU16 msgCount)
{
    m_itemCount = msgCount;
    VfxS32 width = WIDGET_MESSAGE_MENU_WIDTH;
    VfxS32 height = 0;
    if (m_itemCount == 0)
    {
        m_highlightIndex = 0;
        m_itemCount = 1;
        width = WIDGET_MESSAGE_CELL_WIDTH;
    }
    else
    {
        VfxS32 highlight = getMsgIndex(m_highlightMsg.msg_type, m_highlightMsg.msg_id);
        if (highlight >= 0)
        {
            m_highlightIndex = highlight;
        }
        else
        {
            m_highlightIndex = 0;
        }
        height = WIDGET_MESSAGE_CELL_HEIGHT_H - WIDGET_MESSAGE_CELL_HEIGHT;
        VappWidgetMsgMenuLayout *layout = (VappWidgetMsgMenuLayout *)getLayout();
        layout->setHasNoMsg(VFX_FALSE);
    }
	setFocusItem(VcpMenuPos(0, m_highlightIndex), VFX_TRUE);
    setCount(m_itemCount);
    height += WIDGET_MESSAGE_CELL_HEIGHT * m_itemCount;
    if (height > WIDGET_MESSAGE_MENU_HEIGHT)
    {
        height = WIDGET_MESSAGE_MENU_HEIGHT;
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);    
    setPos(0, 0);
    setSize(width, height);
    ((VappWidgetMsg*) getParent())->setSize(width, height);
    VfxAutoAnimate::commit();
}

void VappWidgetMsgMenu::setHighlight(VfxS32 index)
{
    m_highlightIndex = index;
    m_highlightMsg.msg_type = getMsgType(index);
    m_highlightMsg.msg_id = getMsgId(index);
    m_viewBounds = getViewBounds();
    setFocusItem(VcpMenuPos(0, index), VFX_TRUE);
}

void VappWidgetMsgMenu::onDeinit()
{
    if (m_listId > SRV_UM_RESULT_OK)
    {
        srv_um_release_list(m_listId, MMI_TRUE);
    }
    VFX_OBJ_CLOSE(m_data);
	VcpVarHeightMenu::onDeinit();
}

VcpBaseMenuLayout * VappWidgetMsgMenu:: createLayout()
{
    VappWidgetMsgMenuLayout *layout;
    VFX_OBJ_CREATE_EX(layout, VappWidgetMsgMenuLayout, this, (this));
    VcpMenuPos focus;
    focus.group = 0;
    focus.pos = getHighlightIndex();
    layout->setFocusItem(focus, VFX_TRUE);
    return layout;
}

VfxFrame * VappWidgetMsgMenu::createCell(VfxS32 group, VfxS32 pos)
{
    VappWidgetMsgMenuCell *cell;
    VFX_OBJ_CREATE_EX(cell, VappWidgetMsgMenuCell, this, (m_data, (srv_um_msg_node_struct *)(m_listCntx->list), pos, m_listCntx->msg_number));
    setItemHeight(pos, cell->getSize().height);
    return cell;
}

void VappWidgetMsgMenu::onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}

 void VappWidgetMsgMenu::onTouchCell(
        VcpMenuPos          cellPos,
        CellTouchTypeEnum   touchType,
        VfxPoint            pt,
        VfxFrame            *cell
    )
{
    if (touchType == VcpBaseMenu::TouchTap)
    {
        m_tapFlag = VFX_TRUE;
        setHighlight(cellPos.pos);
    }
    else if (touchType == VcpBaseMenu::TouchUp && cellPos.pos == m_highlightIndex && m_tapFlag == VFX_TRUE)
    {
        m_tapFlag = VFX_FALSE;
        if (getMsgNum() != 0 && cellPos.pos < getMsgNum())
        {
            m_signalViewMessage.postEmit(cellPos.pos, VFX_FALSE);
        }
    }
}

void VappWidgetMsgMenu::onUpdateCell(
        const VfxRect &rect,
        VfxS32 group,
        VfxS32 pos,
        VfxFrame* cell,
        VfxU32 flag
)
{
    if (pos % 2 == 0)
    {
        cell->setAnchor(0.0, 0.0);
    }
    else
    {
        cell->setAnchor(1.0, 0.0);
    }
    cell->setPos(rect.origin.x, rect.origin.y);
}

void VappWidgetMsgMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem)
{
    if (focusItem.pos < 0 || focusItem.pos > m_itemCount)
    {
        return;
    }
    VappWidgetMsgMenuCell *cell = (VappWidgetMsgMenuCell *)getCellIfPresent(focusItem.group, focusItem.pos);
    if (cell != NULL)
    {
        cell->setHighlight(VFX_FALSE);
        setItemHeight(focusItem.pos, WIDGET_MESSAGE_CELL_HEIGHT_H);
    }
    VappWidgetMsgMenuCell *preCell = (VappWidgetMsgMenuCell *)getCellIfPresent(preFocusItem.group, preFocusItem.pos);
    if (preCell != NULL)
    {
        preCell->setNormal(VFX_FALSE);
        setItemHeight(preFocusItem.pos, WIDGET_MESSAGE_CELL_HEIGHT);
    }
}

VfxBool VappWidgetMsgMenu::onKeyInput(VfxKeyEvent & event)
{
    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ARROW_UP:
            if (event.type == VFX_KEY_EVENT_TYPE_UP ||
                event.type == VFX_KEY_EVENT_TYPE_REPEAT ||
                event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if (m_highlightIndex > 0 && m_listCntx != NULL)
                {
                    m_navDir = VcpBaseMenuLayout::NAV_DIR_UP;
                    setHighlight(m_highlightIndex - 1);
                }
            }
            break;
        case VFX_KEY_CODE_ARROW_DOWN:
            if (event.type == VFX_KEY_EVENT_TYPE_UP ||
                event.type == VFX_KEY_EVENT_TYPE_REPEAT ||
                event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
            {
                if (m_highlightIndex < m_itemCount - 1)
                {
                    m_navDir = VcpBaseMenuLayout::NAV_DIR_DOWN;
                    setHighlight(m_highlightIndex + 1);
                }
            }
            break;
        case VFX_KEY_CODE_CSK:
            if (event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                if (m_listCntx != NULL && m_highlightIndex >= 0 && m_highlightIndex < getMsgNum())
                {
                    setHighlight(m_highlightIndex);
                    viewMsg(m_highlightIndex, VFX_TRUE);
                }
            }
            break;
    }
    return VFX_TRUE;
}

void VappWidgetMsgMenu::onViewScrollEnd()
{
    VcpVarHeightMenu::onViewScrollEnd();
    VappWidgetMsgMenuLayout *layout = (VappWidgetMsgMenuLayout *)getLayout();
    VcpMenuPos highlightPos, focusItem = getFocusItem();
    VcpMenuRegion visibleRegion = layout->queryRegion(getViewBounds());
    if (visibleRegion.begin == visibleRegion.end)
    {
        return;
    }
    if (focusItem.isValid())
    {
        if (visibleRegion.isWithin(focusItem))
        {
            if (m_highlightIndex == focusItem.pos)
            {
                return;
            }
        }
        else
        {
            highlightPos = layout->queryPosByPt(getViewBounds().origin.y);
            if (!highlightPos.isValid() ||
                (m_navDir == VcpBaseMenuLayout::NAV_DIR_UP && highlightPos >= focusItem) ||
                (m_navDir == VcpBaseMenuLayout::NAV_DIR_DOWN && highlightPos <= focusItem))
            {
                m_navDir = VcpBaseMenuLayout::NAV_DIR_NONE;
                return;
            }
        }
    }
    else
    {
        highlightPos = visibleRegion.begin;
    }
    m_highlightIndex = highlightPos.pos;
    m_highlightMsg.msg_type = getMsgType(highlightPos.pos);
    m_highlightMsg.msg_id = getMsgId(highlightPos.pos);
	m_viewBounds = m_view->getBounds();
}

void VappWidgetMsgMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    m_navDir = VcpBaseMenuLayout::NAV_DIR_NONE;
}



VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetMsg,
    VAPP_WIDGET_TYPE_MESSAGE,
    VappWidgetMessagePublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetMsg, VappWidget);
VappWidgetId VappWidgetMsg::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_MESSAGE);
}

void VappWidgetMsg::onCreateView()
{
    VappWidget::onCreateView();
    VFX_OBJ_CREATE(m_menu, VappWidgetMsgMenu, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappWidgetMsg::onUmSrvReady, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappWidgetMsg::onUmListRefresh, this);
}

void VappWidgetMsg::onReleaseView()
{
    VFX_OBJ_CLOSE(m_menu);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappWidgetMsg::onUmSrvReady, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappWidgetMsg::onUmListRefresh, this);
}

VfxSize VappWidgetMsg::getMaxSize()const
{
    return VfxSize(50, 50);
}

VfxS32 VappWidgetMsg::getName(VfxWChar *string, VfxS32 size)const
{
    const VfxWChar *str = vfxSysResGetStr(MAIN_MENU_MESSAGES_TEXT);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}

VfxFrame* VappWidgetMsg::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_MESSAGE);
    return icon;
}

void VappWidgetMsg::setHidden(VfxBool value)
{
    VappWidget::setHidden(value);
    if (m_menu)
    {
        m_menu->setHidden(value);
    }
}

mmi_ret VappWidgetMsg::onUmSrvReady(mmi_event_struct *evt)
{
    VappWidgetMsg *widget = (VappWidgetMsg *)evt->user_data;
    widget->resetWidget();
    return MMI_RET_OK;    
}

mmi_ret VappWidgetMsg::onUmListRefresh(mmi_event_struct *evt)
{
    srv_um_notify_refresh_evt_struct *event = (srv_um_notify_refresh_evt_struct*)evt;
    
    VappWidgetMsg *widget = (VappWidgetMsg *)event->user_data;
    if (event->refresh_type != SRV_UM_REFRESH_MSG_STATUS_CHANGED 
        && (event->msg_box_type & SRV_UM_MSG_BOX_INBOX))
    {
        
        widget->resetWidget();
    }
    else
    {
        if (event->msg_box_type & SRV_UM_MSG_BOX_INBOX)
        {
            (widget->m_menu)->reset();
        }
    }
    return MMI_RET_OK;
}

void VappWidgetMsg::resetWidget()
{
    VFX_OBJ_CLOSE(m_menu);
    VFX_OBJ_CREATE(m_menu, VappWidgetMsgMenu, this);
}
