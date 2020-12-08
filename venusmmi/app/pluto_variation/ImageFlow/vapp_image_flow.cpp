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
 *  vapp_image_flow.cpp
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "MMI_features.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "meta_tag_api.h"
#include "PlstSrvGprot.h"
#include "GlobalResDef.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
}
//#include "vadp_mmi_frm.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "vcp_image_flow.h"
#include "vapp_image_flow.h"
#include "ImageFlow\vadp_v2p_image_flow.h"
#include "vcp_app_scr.h"
#include "mmi_core\vfx_app_cat_scr.h"
#include "vfx_cpp_base.h"
#include "ui_core\pme\vfx_object.h"
#include "vfx_sys_memory.h"
#include "ui_core\pme\vfx_class_info.h"
#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vcp_button.h"
#include "ui_core\mvc\vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "ui_core\pme\vfx_signal.h"
#include "ui_core\mvc\vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_string.h"
#include "ui_core\mvc\vfx_input_event.h"
#include "ui_core\mvc\vfx_keypad.h"
#include "ui_core\mvc\vfx_frame.h"
#include "kal_trace.h"
#include "ui_core\pme\vfx_async_signal.h"
#include "ui_core\mvc\vfx_control.h"
    
//extern "C" 
//{
//    #include "med_utility.h" // TODO: remove this after using VRT memory API //lry - what's mean?
//}

#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
//#define __VTST_RT_IMAGE_FLOW_USE_SS__  (1)
#define __VTST_RT_IMAGE_FLOW_USE_WHEEL__ (1)


/***************************************************************************** 
* Variable Definition
*****************************************************************************/
static vapp_imgflow_skin_struct* g_imgflow_skin = &g_image_flow_skin_layout;
static VcpAppScr *g_vapp_image_flow_ptr;
#define VAPP_IMAGE_FLOW_TEST             0

VFX_IMPLEMENT_CLASS("VappImageFlow", VappImageFlow, VcpAppScr);


/***************************************************************************** 
 * Function Define
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
    static VfxU16  g_imgflow_grp_id;
    static VfxU16  g_imgflow_scr_id;
    static VfxBool g_imgflow_has_start;

    extern void mmi_frm_scrn_close_active_id(void);
    /*extern MMI_ID mmi_popup_display_simple(
                    WCHAR* title, 
                    mmi_event_notify_enum event_type, 
                    MMI_ID parent_id,
                    void * user_tag);*/
    extern VfxS32 vapp_image_flow_startup(VfxU16 grp_id, VfxU16 scr_id);
    extern mmi_ret  mmi_medply_listui_imgfl_delete_callback(mmi_event_struct *param);


#ifdef __cplusplus
}
#endif

void vapp_image_flow_exit(void)
{    
    VFX_OBJ_CLOSE(g_vapp_image_flow_ptr);  

    if (g_imgflow_has_start)
    {
        VcpAppScr::deinitalize();
    }
    g_imgflow_has_start = VFX_FALSE;
    vadp_v2p_imgflow_deinit();
}


void vapp_image_flow_enter(void)
{
    mmi_event_notify_enum event_type;
    MMI_BOOL entry_ret;
    VfxS32 ret;

    if (!g_imgflow_has_start)
    {
        ret = vadp_v2p_imgflow_init();
        if (VAPP_IMGFLOW_ERR_NONE != ret)
        {
            vadp_v2p_imgflow_popup_error(g_imgflow_grp_id, ret);
            /*mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, g_imgflow_grp_id, NULL);*/
            vadp_v2p_imgflow_deinit();            
            g_imgflow_has_start = VFX_FALSE;
            return;
        }
    }

    g_imgflow_has_start = VFX_TRUE;
    entry_ret = mmi_frm_scrn_enter(g_imgflow_grp_id, g_imgflow_scr_id, 
                                   vapp_image_flow_exit, 
                                   vapp_image_flow_enter, 
                                   MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(g_imgflow_grp_id, 
                                g_imgflow_scr_id, 
                                mmi_medply_listui_imgfl_delete_callback);
	
    #ifdef __MMI_MAINLCD_320X240__	
    vrt_sys_set_screen_rotation(VRT_SYS_SCREEN_ROTATE_0); 
    #else
    vrt_sys_set_screen_rotation(VRT_SYS_SCREEN_ROTATE_270);
    #endif
    VcpAppScr::initalize();

    /*
     * Enter the screen
     */
    VFX_OBJ_CREATE(
        g_vapp_image_flow_ptr, 
        VappImageFlow, 
        VcpAppScr::getContext());
}


extern VfxS32 vapp_image_flow_startup(VfxU16 grp_id, VfxU16 scr_id)
{
    mmi_event_notify_enum event_type;
    VfxS32 ret;
    g_imgflow_grp_id = grp_id;
    g_imgflow_scr_id = scr_id;
    
    ret = vadp_v2p_imgflow_init();
    if (VAPP_IMGFLOW_ERR_NONE != ret)
    {
        vadp_v2p_imgflow_popup_error(g_imgflow_grp_id, ret);
        vadp_v2p_imgflow_deinit();
        /*mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, g_imgflow_grp_id, NULL);*/
        g_imgflow_has_start = VFX_FALSE;
        return -1;
    }
    g_imgflow_has_start = VFX_TRUE;
    vapp_image_flow_enter();
    return 0;
}


void vapp_image_flow_shutdown(void)
{
    g_imgflow_has_start = VFX_FALSE;
    /*
     * Leave the screen
     */
    VFX_OBJ_CLOSE(g_vapp_image_flow_ptr);    
    VcpAppScr::deinitalize();

    vadp_v2p_imgflow_deinit();
}
/***************************************************************************** 
 * VappImageFlowButton Implementation
 *****************************************************************************/
VappImageFlowButton::VappImageFlowButton()
{
}

void VappImageFlowButton::onInit()
{
    VcpButtonInternal::onInit();
}

void VappImageFlowButton::onDeinit()
{
    VcpButtonInternal::onDeinit();
}


void VappImageFlowButton::buttonMoveIn()
{
    VcpButtonInternal::buttonMoveIn();
    m_eventMoveIn.emit();
}

void VappImageFlowButton::buttonMoveOut()
{
    VcpButtonInternal::buttonMoveOut();
    m_eventMoveOut.emit();
      
}


/***************************************************************************** 
 * VappImageFlow Implementation
 *****************************************************************************/
VappImageFlowCP::VappImageFlowCP()
{
}

void VappImageFlowCP::onInit()
{
    VcpImageFlowWheel::onInit();
}

void VappImageFlowCP::onDeinit()
{
    VcpImageFlowWheel::onDeinit();
}


void VappImageFlowCP::onDragStart()
{
    vadp_v2p_imgflow_cachesrv_pause();
    VcpImageFlowWheel::onDragStart();
}

void VappImageFlowCP::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    vadp_v2p_imgflow_cachesrv_resume();
    VcpImageFlowWheel::onDragEnd(xspeed, yspeed);    
}


/***************************************************************************** 
 * VappImageFlow Implementation
 *****************************************************************************/
VappImageFlow::VappImageFlow():
    m_imageFlow(NULL),
    m_buttonBack(NULL),
    m_buttonPlay(NULL),
    m_textTitle(NULL),
    m_nSelectButton(0)
{
}
    
void VappImageFlow::onInit()
{
    VcpAppScr::onInit();        
    //setBgColor(VFX_COLOR_BLACK);
    
    //create bg frame
    VFX_OBJ_CREATE(m_bgFrame, VfxImageFrame, this);

    #ifdef __MMI_MAINLCD_320X240__
    m_bgFrame->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
    #else
    m_bgFrame->setBounds(VfxRect(0, 0, LCD_HEIGHT, LCD_WIDTH));
    #endif

    m_bgFrame->setBgColor(VFX_COLOR_BLACK);
    m_bgFrame->setIsOpaque(VFX_TRUE);
    m_bgFrame->setIsCached(VFX_TRUE);
#ifndef VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    m_bgFrame->setResId(g_imgflow_skin->bg_img_id);
#endif
    //prepare image flow cp    
    VfxS32 focus_idx = vadp_v2p_imgflow_get_focus_index();
    m_nAlbums = vadp_v2p_imgflow_get_album_number();
    VFX_ASSERT(0 != m_nAlbums);
    VFX_ASSERT(focus_idx < m_nAlbums);
    VFX_OBJ_CREATE(m_imageFlow, VappImageFlowCP, this);
    m_imageFlow->setPos(VfxPoint(g_imgflow_skin->cp_x, g_imgflow_skin->cp_y));
    m_imageFlow->setBounds(VfxRect(0, 0, g_imgflow_skin->cp_w, g_imgflow_skin->cp_h));
    m_imageFlow->setRotateAngle((VfxFloat)g_imgflow_skin->cp_angle);
    m_imageFlow->setUpShift((VfxFloat)g_imgflow_skin->cp_upshift);
    m_imageFlow->setFocusUpShift(g_imgflow_skin->cp_focus_upshift);
#ifdef VAPP_IMAGE_FLOW_REFLECTED_ENABLE
    m_imgBackground.setResId(g_imgflow_skin->bg_img_id);
    m_imageFlow->setImgContent(m_imgBackground);
#endif
    m_imageFlow->setCachedCellNumber(0);
    m_imageFlow->setIsOpaque(VFX_FALSE);
    m_imageFlow->setBgColor(VFX_COLOR_BLACK);
    m_imageFlow->setCellParameter(m_nAlbums,
                                  g_imgflow_skin->cell_focus_w,
                                  g_imgflow_skin->cell_focus_h,
                                  g_imgflow_skin->cell_second_w,
                                  g_imgflow_skin->cell_other_w,
                                  g_imgflow_skin->cell_other_h
                                  );

    VFX_OBJ_CREATE(m_imageFlowData, VappImageFlowData, this);
    m_imageFlow->setContentProvider(m_imageFlowData);
    
    m_imageFlow->m_signalSelected.connect(this, &VappImageFlow::onSelected);
    m_imageFlow->m_signalFocusChanged.connect(this,&VappImageFlow::onFucusChange);
    m_imageFlow->m_signalCellClosed.connect(this, &VappImageFlow::onCellClosed);

    //rsk
    VFX_OBJ_CREATE(m_buttonBack, VappImageFlowButton, this);
    m_buttonBack->m_eventDown.connect(this, &VappImageFlow::onRskDown);
    m_buttonBack->m_eventUp.connect(this, &VappImageFlow::onRskUp);
    m_buttonBack->m_eventMoveIn.connect(this, &VappImageFlow::onRskMoveIn);
    m_buttonBack->m_eventMoveOut.connect(this, &VappImageFlow::onRskMoveOut);
    m_buttonBack->setBounds(VfxRect(0, 0, g_imgflow_skin->rsk_w, g_imgflow_skin->rsk_h));
    m_buttonBack->setPos(VfxPoint(g_imgflow_skin->rsk_x, g_imgflow_skin->rsk_y));    

    m_imgBack.setResId(g_imgflow_skin->rsk_img_id);
    m_buttonBack->setBackgroundUp(m_imgBack, MMI_TRUE);
    m_buttonBack->setBackgroundDown(m_imgBack, MMI_TRUE);

    //lsk
    VFX_OBJ_CREATE(m_buttonPlay, VappImageFlowButton, this);
    m_buttonPlay->m_eventDown.connect(this, &VappImageFlow::onLskDown);
    m_buttonPlay->m_eventUp.connect(this, &VappImageFlow::onLskUp);
    m_buttonPlay->m_eventMoveIn.connect(this, &VappImageFlow::onLskMoveIn);
    m_buttonPlay->m_eventMoveOut.connect(this, &VappImageFlow::onLskMoveOut);
    m_buttonPlay->setBounds(VfxRect(0, 0, g_imgflow_skin->lsk_w, g_imgflow_skin->lsk_h));
    m_buttonPlay->setPos(VfxPoint(g_imgflow_skin->lsk_x, g_imgflow_skin->lsk_y));
    
    m_imgPlay.setResId(g_imgflow_skin->lsk_img_id);
    m_buttonPlay->setBackgroundUp(m_imgPlay, MMI_TRUE);
    m_buttonPlay->setBackgroundDown(m_imgPlay, MMI_TRUE);

    //title area
    VFX_OBJ_CREATE(m_textTitle, VfxTextFrame, this);
    m_textTitle->setPos(VfxPoint(g_imgflow_skin->title_x, g_imgflow_skin->title_y));
    m_textTitle->setBounds(VfxRect(0, 0, g_imgflow_skin->title_w, g_imgflow_skin->title_h));
    m_textTitle->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textTitle->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textTitle->setFont(VFX_FONT_DESC_MEDIUM);
    m_textTitle->setColor(VfxColor(VFX_COLOR_WHITE));
    m_textTitle->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_BOTTOM);

    //artist artist
    VFX_OBJ_CREATE(m_textArtist, VfxTextFrame, this);
    m_textArtist->setPos(VfxPoint(g_imgflow_skin->artist_x, g_imgflow_skin->artist_y));
    m_textArtist->setBounds(VfxRect(0, 0, g_imgflow_skin->artist_w, g_imgflow_skin->artist_h));
    m_textArtist->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textArtist->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
#ifdef __MMI_MAINLCD_240X320__
    m_textArtist->setFont(VFX_FONT_DESC_MEDIUM);
#else
    m_textArtist->setFont(VFX_FONT_DESC_SMALL);
#endif
    m_textArtist->setColor(VfxColor(VFX_COLOR_WHITE));
    m_textArtist->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP);

    //Init title string
    VfxWString str;
    VfxWChar strTmp[SRV_PLST_META_INFO_MAX_LEN + 1];
    if (VAPP_IMGFLOW_ERR_NONE == vadp_v2p_imgflow_get_album_info(focus_idx, VAPP_IMGFLOW_INFO_TITLE, strTmp))
    {
        m_textTitle->setString((str.loadFromMem(strTmp)));
    }
    else
    {
        m_textTitle->setString((str.loadFromRes(STR_GLOBAL_ERROR)));
    }
	if (VAPP_IMGFLOW_ERR_NONE == vadp_v2p_imgflow_get_album_info(focus_idx, VAPP_IMGFLOW_INFO_ARTIST, strTmp))
    {
        m_textArtist->setString(str.loadFromMem(strTmp));
    }
    else
    {
        m_textArtist->setString((str.loadFromRes(STR_GLOBAL_ERROR)));
    }

    VfxKeypad::registerHandler(VFX_KEY_CODE_SPECIAL_ALL_SOFT_KEYS, this);    
    vadp_v2p_imgflow_reg_callback((void*)this, updateCell);
    vadp_v2p_imgflow_run();
    m_imageFlow->setFocusIndex(focus_idx);
}


void VappImageFlow::onDeinit()
{
    vadp_v2p_imgflow_stop();
    VcpAppScr::onDeinit();
}


void VappImageFlow::onQueryRotateEx(VfxScreenRotateParam &param)
{
    #ifdef __MMI_MAINLCD_320X240__
    param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
    #else
    param.rotateTo = VFX_SCR_ROTATE_TYPE_LANDSCAPE;
    #endif
}


void VappImageFlow::updateCell(void* user_data, VfxS32 index)
{
    VfxImageSrc image;    
    VappImageFlow* this_ptr = (VappImageFlow*) user_data;
    
    ASSERT(index >= 0);

    VfxFrame* cl = this_ptr->m_imageFlow->getCellIfPresent(index);
    if (cl)
    {
        if (this_ptr->m_imageFlowData->isNeedUpdate(index, image))
        {
            this_ptr->m_imageFlow->updateImageContent(index, image);                   
        }
        return;
    }
}


void VappImageFlow::onFucusChange(VcpImageFlowWheel *imageflow,VfxS32 index) //lry -- need modify
{
    ASSERT(index >= 0 && index < m_imageFlow->getCellNumber());
    vadp_v2p_imgflow_set_focus_index(index);
    
    VfxWString str;
    VfxWChar strTmp[SRV_PLST_META_INFO_MAX_LEN + 1];
    if (VAPP_IMGFLOW_ERR_NONE == vadp_v2p_imgflow_get_album_info(index, VAPP_IMGFLOW_INFO_TITLE, strTmp))
    {
        m_textTitle->setString((str.loadFromMem(strTmp)));
    }
    else
    {
        m_textTitle->setString((str.loadFromRes(STR_GLOBAL_ERROR)));
    }
	if (VAPP_IMGFLOW_ERR_NONE == vadp_v2p_imgflow_get_album_info(index, VAPP_IMGFLOW_INFO_ARTIST, strTmp))
    {
        m_textArtist->setString(str.loadFromMem(strTmp));
    }
    else
    {
        m_textArtist->setString((str.loadFromRes(STR_GLOBAL_ERROR)));
    }
}


void VappImageFlow::onSelected(VcpImageFlowWheel *imageflow,VfxFrame* focusFrame, VfxS32 index)
{
    //IMGFLOW_TRACE1("[IMGFL][VUI]onSelected. index: %d.\n", index);
    vadp_v2p_imgflow_play_album(index);
}


void VappImageFlow::onCellClosed(VcpImageFlowWheel *imageflow,VfxS32 index)
{
    if (m_imageFlowData->isValid())
    //if (m_imageFlowData.get())
    {
        m_imageFlowData->closeImageContent(index);
    }    
}


void VappImageFlow::onLskDown()
{
    VfxPoint pos;
    VfxS32 x = ((g_imgflow_skin->lsk_w - g_imgflow_skin->hl_w) / 2) + g_imgflow_skin->lsk_x;
    VfxS32 y = ((g_imgflow_skin->lsk_h - g_imgflow_skin->hl_h) / 2) + g_imgflow_skin->lsk_y;

    VFX_OBJ_CREATE(m_hlFrame, VfxImageFrame, this);
    m_hlFrame->setResId(g_imgflow_skin->hl_img_id);
    m_hlFrame->setIsOpaque(VFX_FALSE);
    m_hlFrame->setBounds(VfxRect(0, 0, g_imgflow_skin->hl_w, g_imgflow_skin->hl_h));
    m_hlFrame->setPos(VfxPoint(x, y));
    m_nSelectButton = IMGFLOW_SELECT_BUTTON_LSK;
}


void VappImageFlow::onLskUp()
{
    VFX_OBJ_CLOSE(m_hlFrame);
    VfxS32 idx = vadp_v2p_imgflow_get_focus_index();
    vadp_v2p_imgflow_play_album(idx);
    m_nSelectButton = IMGFLOW_SELECT_BUTTON_NULL;
}


void VappImageFlow::onLskMoveIn()
{
    if (IMGFLOW_SELECT_BUTTON_LSK == m_nSelectButton)
    {
        onLskDown();
    }
}


void VappImageFlow::onLskMoveOut()
{
    if (IMGFLOW_SELECT_BUTTON_LSK == m_nSelectButton)
    {
        VFX_OBJ_CLOSE(m_hlFrame);
    }
}


void VappImageFlow::onRskDown()
{
    VfxPoint pos;
    VfxS32 x = ((g_imgflow_skin->rsk_w - g_imgflow_skin->hl_w) / 2) + g_imgflow_skin->rsk_x;
    VfxS32 y = ((g_imgflow_skin->rsk_h - g_imgflow_skin->hl_h) / 2) + g_imgflow_skin->rsk_y;
    
    VFX_OBJ_CREATE(m_hlFrame, VfxImageFrame, this);
    m_hlFrame->setResId(g_imgflow_skin->hl_img_id);
    m_hlFrame->setIsOpaque(VFX_FALSE);
    m_hlFrame->setBounds(VfxRect(0, 0, g_imgflow_skin->hl_w, g_imgflow_skin->hl_h));
    m_hlFrame->setPos(VfxPoint(x, y));
    m_nSelectButton = IMGFLOW_SELECT_BUTTON_RSK;
}


void VappImageFlow::onRskUp()
{
    VFX_OBJ_CLOSE(m_hlFrame);
    vfxPostInvoke(this, &VappImageFlow::onGoBack, NULL);
    m_nSelectButton = IMGFLOW_SELECT_BUTTON_NULL;
}


void VappImageFlow::onRskMoveIn()
{
    if (IMGFLOW_SELECT_BUTTON_RSK == m_nSelectButton)
    {
        onRskDown();
    }
}


void VappImageFlow::onRskMoveOut()
{
    if (IMGFLOW_SELECT_BUTTON_RSK == m_nSelectButton)
    {
        VFX_OBJ_CLOSE(m_hlFrame);
    }
}


void VappImageFlow::onGoBack(void *data)
{
    mmi_frm_scrn_close_active_id();
}

void VappImageFlow::onPenInput(VfxControl *cp, VfxPenEvent& event, VfxBool& ret)
{
    VFX_UNUSED(cp);
    VfxPoint pos(event.getRelPos(this));
    ret = VFX_FALSE;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        break;
    case VFX_PEN_EVENT_TYPE_UP:
        break;
    default:
        break;
    }   
}


VfxBool VappImageFlow::onKeyInput(VfxKeyEvent &event)
{
    VfxWString temp;
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch(event.keyCode)
        {
        case VFX_KEY_CODE_LSK:
        case VFX_KEY_CODE_CSK:
            onLskDown();
            return VFX_TRUE;
        case VFX_KEY_CODE_RSK:
            onRskDown();
            return VFX_TRUE;
        default:
            break;
        }
    }
    else if (event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        switch(event.keyCode)
        {
        case VFX_KEY_CODE_LSK:
        case VFX_KEY_CODE_CSK:
            onLskUp();
            return VFX_TRUE;
        case VFX_KEY_CODE_RSK:
            onRskUp();
            return VFX_TRUE;
        default:
            break;
        }
    }
    return VcpAppScr::onKeyInput(event);
}


/***************************************************************************** 
 * VappImageFlowData Implementation
 *****************************************************************************/
void VappImageFlowData::onInit()
{
    VfxObject::onInit();
    
    VfxS32 i;

    for (i = 0; i < VAPP_IMGFLOW_MAX_CELL_NUM; i++)
    {
        m_nBuff[i] = -1;
        m_imgBuff[i].ptr = (VfxU8 *)NULL;
        m_imgBuff[i].pitchBytes = 0;
        m_imgBuff[i].width = 0;
        m_imgBuff[i].height = 0;
        m_imgBuff[i].colorFormat = VRT_COLOR_TYPE_UNKNOWN;
    #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }

    /*create default cover image*/
    m_DefImgBuff.ptr = vadp_v2p_imgflow_get_def_cover();
    m_DefImgBuff.pitchBytes = g_imgflow_skin->cell_focus_w * 2;
    m_DefImgBuff.width = g_imgflow_skin->cell_focus_w;
    m_DefImgBuff.height = g_imgflow_skin->cell_focus_h;
    m_DefImgBuff.colorFormat = VRT_COLOR_TYPE_RGB565;
    m_DefImage.setImageBuffer(m_DefImgBuff);
};


void VappImageFlowData::onDeinit()
{
    VfxS32 i;
    for (i = 0; i < VAPP_IMGFLOW_MAX_CELL_NUM; i++)
    {
        m_imgBuff[i].ptr = (VfxU8 *)NULL;
    }
    
    VfxObject::onDeinit();
};


VfxImageSrc& VappImageFlowData::getImageContent(VfxS32 index)
{
    VfxS32 i, ret, w, h;
    VfxWString temp;

    for (i = 0; i< VAPP_IMGFLOW_MAX_CELL_NUM ; i++ )
    {
        if (m_nBuff[i] == index)
        {
            return m_Image[i];        
        }
    }

    for (i = 0; i < VAPP_IMGFLOW_MAX_CELL_NUM; i++)
    {
        if (m_nBuff[i] == -1)
        {            
            //ret = vadp_v2p_imgflow_get_album_cover(index, (U8*)m_imgeBuff[i].ptr, 1);
            ret = vadp_v2p_imgflow_lock_image_buffer(index, (void**)&m_imgBuff[i].ptr, &w, &h);
            if (VAPP_IMGFLOW_ERR_NONE == ret)
            {
                ASSERT(NULL != m_imgBuff[i].ptr);
                m_imgBuff[i].pitchBytes = w * 2;
                m_imgBuff[i].width = w;
                m_imgBuff[i].height = h;
                m_imgBuff[i].colorFormat = VRT_COLOR_TYPE_RGB565;
                m_Image[i].setImageBuffer(m_imgBuff[i]);
                m_nBuff[i] = index;
                return m_Image[i];
            }               
        }
    }
    return m_DefImage;
}


VfxBool VappImageFlowData::isNeedUpdate(VfxS32 index, VfxImageSrc& image)
{
    VfxS32 i, ret, w, h;
    for (i = 0; i< VAPP_IMGFLOW_MAX_CELL_NUM ; i++ )
    {
        if (m_nBuff[i] == index)
        {
            return VFX_FALSE;        
        }
    }

    for (i = 0; i < VAPP_IMGFLOW_MAX_CELL_NUM; i++)
    {
        if (m_nBuff[i] == -1)
        {            
            //ret = vadp_v2p_imgflow_get_album_cover(index, (U8*)m_imgeBuff[i].ptr, 1);
            ret = vadp_v2p_imgflow_lock_image_buffer(index, (void**)&m_imgBuff[i].ptr, &w, &h);
            if (VAPP_IMGFLOW_ERR_NONE == ret)
            {
                ASSERT(NULL != m_imgBuff[i].ptr);
                m_imgBuff[i].pitchBytes = w * 2;
                m_imgBuff[i].width = w;
                m_imgBuff[i].height = h;
                m_imgBuff[i].colorFormat = VRT_COLOR_TYPE_RGB565;
                m_Image[i].setImageBuffer(m_imgBuff[i]);
                m_nBuff[i] = index;
                image = m_Image[i];
                return VFX_TRUE;
            }               
        }
    }
    return VFX_FALSE;
}


void VappImageFlowData::closeImageContent(VfxS32 index)
{
    VfxS32 i;
    for (i = 0; i < VAPP_IMGFLOW_MAX_CELL_NUM; i++)
    {
        if (m_nBuff[i] == index)
        {
            vadp_v2p_imgflow_unlock_image_buffer(index, (void*)m_imgBuff[i].ptr);
            m_nBuff[i] = -1;
            return;
        }
    }
}


VfxS32 VappImageFlowData::getIndex(VfxS32 i)
{
    return m_nBuff[i];
}


VfxImageSrc& VappImageFlowData::reGetImage(VfxS32 i)
{
    return m_Image[i];
}

#endif // __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__

