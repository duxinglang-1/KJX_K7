/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cube_scr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  3d cube screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

#include "vfx_uc_include.h"
#include "vapp_cube_scr.h"
#include "vapp_cube_res.h"
#include "vapp_hs_res.h"
#include "CubeAppGProt.h"
#include "CubeAppProt.h"
#include "vcp_status_icon_bar.h"
#include "CubeApp\vadp_v2p_cube.h"
#include "CubeApp\Vadp_p2v_cube.h"
#include "trc\vadp_app_trc.h"

#include "MMIDataType.h"
#include "vfx_cpp_base.h"
#include "vfx_app_cat_scr.h"
#include "kal_trace.h"
#include "vfx_system.h"
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vrt_system.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vapp_hs_cp.h"
#include "vapp_hs_shortcut_panel.h"
#include "vfx_timer.h"
#include "vfx_control.h"
#include "vfx_object_list.h"
#include "vfx_input_event.h"
 
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "limits.h"
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif
    extern void GoBackHistory(void);
    extern pBOOL mmi_shutdown_is_in_power_off_period(void);
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * VappCubeScr
 *****************************************************************************/

VappCubeScr::VappCubeScr() :
    m_timer(NULL),
    m_old_cube_frame(NULL),
    m_select_action(0),
    m_do_change_page(VFX_TRUE),
    m_free_mode(VFX_FALSE),
    m_shortcutPanel(NULL),
    m_bgPanel(NULL)
{

}
    

void VappCubeScr::initalize()
{
    VfxAppCatScr::initalize();
}


void VappCubeScr::deinitalize()
{

    VfxAppCatScr::deinitalize();

#ifdef __MMI_VUI_3D_CUBE_APP__
    VfxU8 idx;
   
   // if the screen is exited by cube app itself, we need to 
   // check whether we need to store current gdi layer to buffer
    if (mmi_cube_vapp_is_self_exited() == MMI_CUBE_OK &&
    	!mmi_shutdown_is_in_power_off_period())
    {
    #if defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
        if (vadp_p2v_cube_vapp_get_cur_scr_idx((U8 *)&idx) >= 0)
        {
            vadp_v2p_cube_vapp_save_cur_layer_to_buffer(idx);
        }
    #else /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
        if (vadp_p2v_cube_vapp_get_cur_scr_idx((U8 *)&idx) >= 0)
        {
            // if it is small cube, we need to save current layer to 
            // buffer before we enter small cube
            if (vadp_p2v_cube_vapp_is_small())
            {
            #if defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
                if (vadp_v2p_cube_vapp_save_cur_scr_snapshot(idx) < 0)
                {
                    VFX_LOG(VFX_ERROR, VAPP_CUBE_CANNOT_GET_SNAPSHOT);
                }
            #endif /* __MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__ */
            }
            else
            {
                vadp_v2p_cube_vapp_save_cur_layer_to_buffer(idx);
            }
        }
    #endif /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */
    }
    else
    {
        // if cube is not exited by cube itself, we need to 
        // free whatever resources we grapped
        if (mmi_shutdown_is_in_power_off_period() &&
            vadp_p2v_cube_vapp_get_cur_scr_idx((U8 *)&idx) >= 0)
        {
            vadp_v2p_cube_vapp_save_cur_layer_to_buffer(idx);
        }
        vadp_v2p_cube_vapp_save_cur_layer();
        vadp_v2p_cube_vapp_free_layer();
    }
#endif /* __MMI_VUI_3D_CUBE_APP__ */

}


void VappCubeScr::onInit()
{
    VFX_LOG(VFX_STATE, VAPP_CUBE_ON_INIT_MSG);
    
    VfxAppCatScr::onInit();
   
    // check whether we need free any layer resource 
    // we grapped between cube transition
#ifdef __MMI_VUI_3D_CUBE_APP__
    vadp_v2p_cube_vapp_free_layer();
#endif

    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(
        &main_screen_size, 
        &main_screen_color_format);

    // Todo: the way to change the parent frame is too ugly.
    // we add m_bgPanel back to it original parent because
    // the onAddChild method has been overwitten by cube itself
    VFX_OBJ_CREATE(m_bgPanel, VfxFrame, getContext());
    VfxAppCatScr::onAddChild(m_bgPanel);
    
    m_bgPanel->setPos(VfxPoint(0, 0));
    m_bgPanel->setBgColor(VFX_COLOR_BLACK);
    m_bgPanel->setBounds(VfxRect(0, 0, 
                                 main_screen_size.width, 
                                 main_screen_size.height));

    // Common outlook: Create status bar
    VappHsStatusIcon    *icon_bar;
    VFX_OBJ_CREATE(icon_bar, VappHsStatusIcon, this);
    // Todo: the way to change the parent frame is too ugly
    VfxAppCatScr::onAddChild(icon_bar);
    // get icon bounds
    m_icon_bounds = icon_bar->getBounds();

    VFX_OBJ_CREATE(m_shortcutPanel, VappHsShortcutPanel, this);
    VfxAppCatScr::onAddChild(m_shortcutPanel);

#ifdef __MMI_VUI_3D_CUBE_APP__
    VfxControl *ptr;
  
    // to avoid shortcut has the same gesture as cube page action
    // we need to deregister its page action behavior at first
    for (ptr = m_shortcutPanel->getFirstShortcut();
         ptr != NULL;
         ptr = m_shortcutPanel->getNextShortcut())
    {
        deregDefaultPageAct(ptr);
    }
         
#if !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    VfxU8 scr_idx;
    
    // check whether we need to make an animation transition 
    // between original and real screen 
    if (vadp_v2p_cube_vapp_get_screen_effect_transition())
    {
        if (vadp_p2v_cube_vapp_get_cur_scr_idx((U8 *)&scr_idx) >= 0)
        {
            VFX_OBJ_CREATE(m_old_cube_frame, VfxImageFrame, this);
            m_old_cube_frame->setResId(VAPP_CUBE_IMG_BG_SCR_ONE+scr_idx);
            m_old_cube_frame->setOpacity(1.0f);
            m_old_cube_frame->setAutoAnimate(VFX_TRUE);
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDuration(DEFAULT_CUBE_EFFECT_TIME);
            m_old_cube_frame->setOpacity(0.0f);
            VfxAutoAnimate::commit();
		    VfxAppCatScr::onAddChild(m_old_cube_frame);
                
                
            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
            m_timer->setStartDelay(0);
            m_timer->setDuration(DEFAULT_CUBE_EFFECT_TIME);
            m_timer->m_signalTick.connect(this, &VappCubeScr::onCubeEffectTimerExpir);
            m_timer->start();
        }
    }
    vadp_v2p_cube_vapp_set_screen_effect_transition(0);
#endif /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
#endif /* __MMI_VUI_3D_CUBE_APP__ */
}


void VappCubeScr::onDeinit()
{
    VFX_LOG(VFX_STATE, VAPP_CUBE_ON_DEINIT_MSG);

#if defined(__MMI_VUI_3D_CUBE_APP__) && !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    if (m_timer)
    {
        m_timer->stop();
    }

    VFX_OBJ_CLOSE(m_timer);
    VFX_OBJ_CLOSE(m_old_cube_frame);
#endif /* defined(__MMI_VUI_3D_CUBE_APP__) && !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
    
    VFX_OBJ_CLOSE(m_bgPanel);

#if defined(__MMI_VUI_3D_CUBE_APP__)
    // close current category
    mmi_cube_vapp_close_hs_category();
#endif

    VfxAppCatScr::onDeinit();
}


void VappCubeScr::onCubeEffectTimerExpir(VfxTimer *timer)
{
#if defined(__MMI_VUI_3D_CUBE_APP__) && !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    VFX_OBJ_CLOSE(m_timer);
    VFX_OBJ_CLOSE(m_old_cube_frame);
#endif /* defined(__MMI_VUI_3D_CUBE_APP__) && !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
}


void VappCubeScr::regDefaultPageAct(VfxControl  *obj)
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    VFX_OBJ_ASSERT_VALID(obj);

    VFX_LOG(VFX_INFO, VAPP_CUBE_REG_DEF_PAGE_ACT, obj);
    m_cube_exp_list.removeOne(obj);
#endif /* __MMI_VUI_3D_CUBE_APP__ */
}


void VappCubeScr::deregDefaultPageAct(VfxControl  *obj)
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    VFX_OBJ_ASSERT_VALID(obj);

    if (vadp_v2p_cube_vapp_is_in_transition())
        return;
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_DEREG_DEF_PAGE_ACT, obj);
    
    if (!m_cube_exp_list.contains(obj))
    {
        m_cube_exp_list.append(obj);
    }
#endif /* __MMI_VUI_3D_CUBE_APP__ */
}


void VappCubeScr::cancelDefaultPageAct()
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    // cancel page action
    VFX_LOG(VFX_INFO, VAPP_CUBE_CANCEL_PAGE_ACT);
    m_do_change_page = VFX_FALSE;
#endif /* __MMI_VUI_3D_CUBE_APP__ */
}


void VappCubeScr::onAddChild(VfxObject *child)
{
    // redirect child frame to background panel frame
    if (m_bgPanel)
    {
		VfxFrame *childFrame = VFX_OBJ_DYNAMIC_CAST(child, VfxFrame);
        
		if (childFrame != NULL)
		{
			m_bgPanel->addChild(childFrame);
			return;
		}
    }
	VfxAppCatScr::onAddChild(child);
}


VfxRect VappCubeScr::getAppBounds() const
{
    vrt_size_struct main_screen_size;
    VfxColorTypeEnum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(
        &main_screen_size, 
        &main_screen_color_format);

    VfxSize size = VfxSize(main_screen_size.width, 
                           main_screen_size.height - m_icon_bounds.getHeight() - 
                           VappHsShortcutPanel::SHORTCUT_BAR_HEIGHT);
    VfxPoint pos = VfxPoint(0, m_icon_bounds.getHeight());
    
    return VfxRect(pos, size);
}


VfxBool VappCubeScr::noDefaultPageAction(VfxObjList &relObjList) const
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    VfxObjListEntry *i;
    
    // foreach item in list
    for (i = relObjList.getValidHead(); i != NULL; i = i->getValidNext())
    {
        VfxControl *control = (VfxControl *)i->get();

        if (m_cube_exp_list.contains((VfxObject *)control))
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_ON_EXP_LIST, control);
            return VFX_TRUE;
        }
    }
#endif /* __MMI_VUI_3D_CUBE_APP__ */

    return VFX_FALSE;
}


VfxBool VappCubeScr::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxBool VappCubeScr::onKeyInput(VfxKeyEvent &event)
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    if ((event.keyCode == VFX_KEY_CODE_ARROW_RIGHT ||
         event.keyCode == VFX_KEY_CODE_ARROW_LEFT) &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (!m_shortcutPanel->isHidden())
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
            {
                // change to next page
                m_select_action = MMI_CUBE_VAPP_DIR_NEXT;    
            }
            else
            {
                // change to previous page
                m_select_action = MMI_CUBE_VAPP_DIR_PREV;
            }
            m_free_mode = VFX_FALSE;
            vfxPostInvoke(this, &VappCubeScr::entryCubeApp);
        
            return VFX_TRUE;
        }
    }
#endif /* __MMI_VUI_3D_CUBE_APP__ */
 
    return VfxAppCatScr::onKeyInput(event);
}


VfxBool VappCubeScr::onPreviewPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO2, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 0, event.pos.x, event.pos.y);

    m_shortcutPanel->cancelShortcutDrop();
    
    // Shortcut Todo: If some shortcut is during the dropping animation, drop it immediately
    // such that the state of the shortcut DnD mechanism can be reset.
#ifdef __MMI_VUI_3D_CUBE_APP__
    // Shortcut Todo: If shortcut us unhide, we can change page. Otherwise, 
    // we cannot change page
    if (!m_shortcutPanel->isHidden())
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 2, event.pos.x, event.pos.y);
            if (noDefaultPageAction(event.relObjList))
                m_do_change_page = VFX_FALSE;
            else
                m_do_change_page = VFX_TRUE;
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_MOVE ||
                 event.type == VFX_PEN_EVENT_TYPE_UP)
        {
            if (m_do_change_page)
            {
                if (noDefaultPageAction(event.relObjList))
                {
                    m_do_change_page = VFX_FALSE;
                    return VFX_FALSE;
                }
                
                VfxS32   x_moved_distance;
               
                x_moved_distance = (VfxU32)(event.pos.x - event.downPos.x);
    
                if (VFX_ABS(x_moved_distance) >= APP_ACTION_X_DISTANCE)
                {
                    VFX_LOG(VFX_INFO, VAPP_CUBE_ON_PREVIEW_PEN_INPUT, 3, 
                            event.pos.x, event.pos.y);
                
                    if (x_moved_distance > 0)
                    {
                        // change to previous page
                        m_select_action = MMI_CUBE_VAPP_DIR_PREV;    
                    }
                    else
                    {
                        // change to next page
                        m_select_action = MMI_CUBE_VAPP_DIR_NEXT;
                    }
                 #ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
                    m_free_mode = VFX_TRUE;
                    vadp_v2p_cube_vapp_set_down_pos(event.pos.x, event.pos.y);
                 #endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
                 
                    vfxPostInvoke(this, &VappCubeScr::entryCubeApp);   
                }
            }
        
        }    
    }
#endif /* __MMI_VUI_3D_CUBE_APP__ */

    return VFX_FALSE;
}


void VappCubeScr::entryCubeApp(void *data)
{
#ifdef __MMI_VUI_3D_CUBE_APP__
    VFX_LOG(VFX_INFO, VAPP_CUBE_ON_ENTRY_CUBE_APP, 0);

    // Entry shell application
    EntryCubeVappByDir((MMI_BOOL)VFX_FALSE, 
                       (MMI_BOOL)m_free_mode,
                       (mmi_cube_vapp_dir_enum)m_select_action);
    return;
#endif /* __MMI_VUI_3D_CUBE_APP__ */
}


void VappCubeScr::foldAll()
{
    // fold shortcut pool
    onFoldAll();
}


void VappCubeScr::onFoldAll()
{
    m_shortcutPanel->fold();
}


VfxBool VappCubeScr::isAllFold()
{
    return onCheckFold();
}


VfxBool VappCubeScr::onCheckFold()
{
    // check whether shortcut bar is fold
    if (m_shortcutPanel->isUnFold())
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappCubeScr::hideShortcutBar(VfxBool isHide)
{
    // hide shortcut bar
    m_shortcutPanel->hide(isHide);
}


VappHsShortcutPanel *VappCubeScr::getShortcutPanel()
{
    //return shortcut panel 
    return m_shortcutPanel;
}


/***************************************************************************** 
 * VappCube
 *****************************************************************************/

#ifdef __MMI_VUI_3D_CUBE_APP__

VappCube::VappCube(VfxBool is_small_cube, VfxBool is_free_mode, VfxBool cube_effect, 
                   VfxU8 cur_scr_idx, mmi_cube_vapp_dir_enum scr_dir) :
    m_cube(NULL),
    m_penSrv(NULL)
{
    for (VfxU32 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
    {
        m_cubeImage[i] = NULL;
    }

    m_small_cube = is_small_cube;
    m_free_mode = is_free_mode;
    m_cube_effect = cube_effect;
    m_cur_scr_idx = cur_scr_idx;
    m_action = scr_dir;
}

void VappCube::onInit()
{
    VFX_LOG(VFX_FUNC, VAPP_CUBE_INIT);
    
    VfxAppCatScr::onInit();

    VFX_OBJ_CREATE(m_cube, VcpCube, this);
    
#if defined(__MMI_VUI_3D_CUBE_FREE_MODE__)
    VfxWString path;

    // create cube four surface outlook
    for (VfxU8 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
    {
        VFX_OBJ_CREATE(m_cubeImage[i], VfxImage, this);
        VfxU8 *buff_ptr;
        VfxS32 width, height;
        
        if ((buff_ptr = vadp_v2p_cube_vapp_get_layer_buf_from_file(i, &width, &height)) != NULL)
        {
            VfxImageBuffer imgBuf;
            imgBuf.ptr 			= buff_ptr;
            imgBuf.pitchBytes 	= width * 2;
            imgBuf.width		= width;
            imgBuf.height		= height;
            imgBuf.colorFormat	= VRT_COLOR_TYPE_RGB565;

            m_cubeImage[i]->setImageBuf(imgBuf);
        }
        else
        {
            m_cubeImage[i]->setResId(VAPP_CUBE_IMG_BG_SCR_ONE+i);
        }
        m_cube->setSurfaceImage(i, m_cubeImage[i]);
    }

    // enable free mode
    m_cube->setFreeModeEnable(m_free_mode);
    
#else /* defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */
#if defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    if (m_small_cube)
    {
        VfxWString path;

        // read four screen outlook from jpeg file
        for (VfxU8 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
        {
            VFX_OBJ_CREATE(m_cubeImage[i], VfxImage, this);
            
            if (vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 1, VFX_TRUE) > 0)
            {
                path.format("%c:\\Shell\\scr%d.jpg", 
                vadp_v2p_cube_vapp_get_cur_active_drv(VFX_TRUE), i+1);
				m_cubeImage[i]->setSrc(path);
            }
            else if (vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 1, VFX_FALSE) > 0)
            {
                path.format("%c:\\@Shell\\scr%d.jpg", 
                vadp_v2p_cube_vapp_get_cur_active_drv(VFX_FALSE), i+1);
				m_cubeImage[i]->setSrc(path);
            }
            else
            {
                VfxResId img_res_id = VAPP_CUBE_IMG_BG_SCR_ONE + i;                
                m_cubeImage[i]->setResId(img_res_id);
            }
            
            m_cube->setSurfaceImage(i, m_cubeImage[i]);
        }
    }
    else
#else /* defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
    if (m_small_cube)
    {
        // use default resource outlook
        for (VfxU8 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
        {
            VFX_OBJ_CREATE(m_cubeImage[i], VfxImage, this);
            m_cubeImage[i]->setResId(VAPP_CUBE_IMG_BG_SCR_ONE+i);
            m_cube->setSurfaceImage(i, m_cubeImage[i]);
        }
    }
    else
#endif /* !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
    {
        VfxWString path;
        VfxU8 *buff_ptr;
        VfxS32 *width, height;

        // set cube outlook by layer handle
        for (VfxU8 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
        {
            VFX_OBJ_CREATE(m_cubeImage[i], VfxImage, this);

            if ((buff_ptr = vadp_v2p_cube_vapp_get_cube_layer_buf(i, &width, &height)) 
                != NULL)
            {
                VfxImageBuffer imgBuf;
                imgBuf.ptr 			= buff_ptr;
                imgBuf.pitchBytes 	= width * 2;
                imgBuf.width		= width;
                imgBuf.height		= height;
                imgBuf.colorFormat	= VRT_COLOR_TYPE_RGB565;
                m_cubeImage[i]->setImageBuf(imgBuf);
            }
            m_cube->setSurfaceImage(i, m_cubeImage[i]);
        }
    }
#endif /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__) */

    VfxRect screen_bounds       = getBounds();
    m_cube->setPos(VFX_POINT_ZERO);
    m_cube->setBounds(VfxRect(VFX_POINT_ZERO, screen_bounds.size));
    m_cube->setCurrentIndex(m_cur_scr_idx);
    m_cube->m_signalSelected.connect(this, &VappCube::onCubeFinish);

    if (!m_cube_effect)
    {
        // no cube animation effect
        m_cube->setEnterEffect(VCP_CUBE_EFFECT_NONE);
    }
    
    // Enter small cube
    if (m_small_cube)
    {
        VfxU16 title_str_id[SHELL_APP_CUBE_SURFACE_NUM];

        // Set title string
        for (VfxU8 j = 0; j < SHELL_APP_CUBE_SURFACE_NUM; j++)
        {
            mmi_cube_vapp_get_title(j, (U16 *)&title_str_id[j]);
            m_cube->setTitle(j,VFX_WSTR_RES(title_str_id[j]));       
        }
        
        // Set background image
        VfxImage *cubeBKImage;
        VFX_OBJ_CREATE(cubeBKImage, VfxImage, this);
        cubeBKImage->setResId(VAPP_CUBE_IMG_CUBE_BACKGROUND);
        m_cube->setBackgroundImage(cubeBKImage);

        VfxImage *cubeBKShadow;
        VFX_OBJ_CREATE(cubeBKShadow, VfxImage, this);
        cubeBKShadow->setResId(VAPP_CUBE_IMG_CUBE_SHADOW);
        m_cube->setFakeShadowImage(cubeBKShadow);
        
        VFX_LOG(VFX_INFO2, VAPP_CUBE_SHOW_SMALL_CUBE);
        m_cube->enterSelectMode();
    }
    else
    {
        if (m_action == MMI_CUBE_VAPP_DIR_NEXT)
        {
            m_cube->setStartAngle(VCP_CUBE_BIG_ROTATE_START_RIGHT_ANGLE);
            if (m_free_mode == VFX_FALSE)
            {    
                m_cube->switchNext();
            }
        }
        else
        {
            m_cube->setStartAngle(VCP_CUBE_BIG_ROTATE_START_LEFT_ANGLE);
            if (m_free_mode == VFX_FALSE)
            {
                m_cube->switchPrevious();
            }
        }

    #ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
        // add one pen down event for free mode
        VfxPoint pos;
        vadp_v2p_cube_vapp_get_down_pos(&pos.x, &pos.y);

        VfxPenDeviceInfo info;
        info.timeStamp 	= VfxTimer::getCurrentTime();
        info.pos 				= VfxPoint(pos.x, pos.y);
        info.eventType 	= VFX_PEN_EVENT_TYPE_DOWN;
			
        m_penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        m_penSrv->processPenInput(info); 
    #endif /* __MMI_VUI_3D_CUBE_FREE_MODE__ */
    
    }
}


void VappCube::onDeinit()
{
    VFX_OBJ_CLOSE(m_cube);

    for (VfxU8 i = 0; i < SHELL_APP_CUBE_SURFACE_NUM; i++)
    {
        VFX_OBJ_CLOSE(m_cubeImage[i]);
    }
    VfxAppCatScr::onDeinit();
}


void VappCube::getHistory(VfxBool *small_cube)
{
    if (small_cube)
    {
        if (m_cube->isLeavingSelectMode())
        {
            m_small_cube = VFX_FALSE;
        }
        
        *small_cube = m_small_cube;
        
    }
    
    VFX_LOG(VFX_INFO, VAPP_CUBE_GET_CUBE_HISTORY, m_small_cube, m_cur_scr_idx);
}


void VappCube::getCurrentScrIndex(VfxU8 *index)
{
    if (index != NULL)
    {
        if (m_cube)
        {
            *index = (VfxU8)m_cube->getNearestIndex();
            VFX_LOG(VFX_INFO, VAPP_CUBE_GET_CUR_SCR_IDX, *index);
            if (*index >= SHELL_APP_CUBE_SURFACE_NUM)
            {
                // it should not happen
                VFX_ASSERT(0);
            }
        }
        else
        {
            // error !!! It's impossible!!
            VFX_ASSERT(0);
        }
    }
}


void VappCube::onCubeFinish(VfxS32 index)
{
    VFX_LOG(VFX_INFO, VAPP_CUBE_FINISH, index);
    
#if !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    if (m_small_cube)
    {
        vadp_v2p_cube_vapp_set_screen_effect_transition(1);
    }
#endif /* !defined(__MMI_VUI_3D_CUBE_FREE_MODE__)&& !defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
    MMI_VS_CUBE_START_LOGGING("CB1"); 
    m_cur_scr_idx = (VfxU8)(index);
    m_small_cube = VFX_FALSE;
    m_action = MMI_CUBE_VAPP_DIR_NONE;
    // call application's registered callback function based on index
    vfxPostInvoke(this, &VappCube::entryAppScreen);
    MMI_VS_CUBE_STOP_LOGGING("CB1");
}


void VappCube::entryAppScreen(void *data)
{
    MMI_VS_CUBE_START_LOGGING("CB1"); 
    VFX_LOG(VFX_INFO2, VAPP_CUBE_ENTRY_APP_SCR);
    MMI_VS_CUBE_STOP_LOGGING("CB1");
    GoBackHistory();
    return;
}


#endif /* __MMI_VUI_3D_CUBE_APP__ */

#endif /* __MMI_VUI_HOMESCREEN__ */

