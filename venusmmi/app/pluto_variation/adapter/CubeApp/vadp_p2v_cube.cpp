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
 *  vadp_p2v_cube.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus 3D cube plutommi to venus adaption layer
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
}

#ifdef __MMI_VUI_HOMESCREEN__

#include "CubeAppProt.h"
#include "CubeAppGprot.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "HomeScreen\vapp_hs_shortcut_panel.h"
#include "CubeApp\vadp_p2v_cube.h"

#ifdef __MMI_VUI_3D_CUBE_APP__
 
#include "CubeApp\vapp_cube_scr.h"
#include "CubeApp\vadp_v2p_cube.h"
#include "trc\vadp_app_trc.h"


/**********************************************************************
 * Structure Definitions:
 **********************************************************************/
typedef struct
{
    VappCube    *c;
    VfxBool         is_small_cube;
    VfxBool         cube_effect;
    VfxBool         is_free_mode;
    mmi_cube_vapp_dir_enum action;
    VfxU8           cur_scr_idx;
} vadp_p2v_shell_context_struct;


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static VfxPoint g_cat_cur_pos;
static VfxFPoint g_cat_anchor_pos;
static VfxBool  g_is_cat_created = VFX_FALSE;

static vadp_p2v_shell_context_struct g_shell_app_history;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
 
/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_init
 * DESCRIPTION
 *  This function is used to init shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_p2v_cube_vapp_init(MMI_BOOL cube_effect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VcpAppScr::initalize();

    VFX_OBJ_CREATE_EX(g_shell_app_history.c, VappCube, VfxAppCatScr::getContext(),
                   ((VfxBool)g_shell_app_history.is_small_cube, 
                    (VfxBool)g_shell_app_history.is_free_mode,
                    (VfxBool)cube_effect,
                    (VfxU8)g_shell_app_history.cur_scr_idx,
                    g_shell_app_history.action));
    return;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_deinit
 * DESCRIPTION
 *  This function is used to deinit shell app
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
void vadp_p2v_cube_vapp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Leave the screen, we need to finialize current screen at first 
     */
    g_shell_app_history.c->getHistory(&g_shell_app_history.is_small_cube);
    g_shell_app_history.c->getCurrentScrIndex(
                           (VfxU8 *)&g_shell_app_history.cur_scr_idx);

    VFX_OBJ_CLOSE(g_shell_app_history.c);
    VcpAppScr::deinitalize();
    return;
}



/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_set_small_mode
 * DESCRIPTION
 *  This function is enter small cube
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_set_small_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shell_app_history.is_small_cube = VFX_TRUE;
    g_shell_app_history.action = MMI_CUBE_VAPP_DIR_NONE;
}

/*****************************************************************************
 * FUNCTION
 * vadp_p2v_shell_is_cube_effect_running
 * DESCRIPTION
 *  This function is enter small cube
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_set_effect(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shell_app_history.cube_effect = enable;
}

/*****************************************************************************
 * FUNCTION
 * vadp_p2v_shell_is_cube_effect_running
 * DESCRIPTION
 *  This function is enter small cube
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_p2v_cube_vapp_get_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)g_shell_app_history.cube_effect;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_is_small
 * DESCRIPTION
 *  This function is enter small cube
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_p2v_cube_vapp_is_small(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_INFO, VAPP_CUBE_IS_SMALL, g_shell_app_history.is_small_cube);
    return (MMI_BOOL)g_shell_app_history.is_small_cube;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_set_action
 * DESCRIPTION
 *  This function is to set shell's action
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_set_action(mmi_cube_vapp_dir_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shell_app_history.is_small_cube = VFX_FALSE;
    g_shell_app_history.action = action;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_set_action
 * DESCRIPTION
 *  This function is to set shell's action
 *  buffer.
 * PARAMETERS
 *  action         : [IN]      action
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_set_free_mode(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_shell_app_history.is_free_mode =enable;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_fold_all
 * DESCRIPTION
 *  This function folds the widget bar and the shortcut pool.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_fold_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappCubeScr *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (VappCubeScr *)(mmi_cube_vapp_get_hs_category(
          (U8)g_shell_app_history.cur_scr_idx));
    if (obj)
    {
        obj->foldAll();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_is_fold
 * DESCRIPTION
 *  This function checks if both widget bar and shortcut pool are folded.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL vadp_p2v_cube_vapp_is_fold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappCubeScr *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (VappCubeScr *)(mmi_cube_vapp_get_hs_category(
          (U8)g_shell_app_history.cur_scr_idx));
    if (obj)
    {
        if (obj->isAllFold())
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE; /* not fold all or unknown */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_is_active
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_p2v_cube_vapp_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappCubeScr *obj = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (VappCubeScr *)(mmi_cube_vapp_get_hs_category(
          (U8)g_shell_app_history.cur_scr_idx));
    
    return obj != NULL ? MMI_TRUE: MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_get_cur_scr_idx
 * DESCRIPTION
 *  This function is used to get current screen index
 *  buffer.
 * PARAMETERS
 *  idx         : [IN]      screen index
 * RETURNS
 *  S8
 *****************************************************************************/
S8 vadp_p2v_cube_vapp_get_cur_scr_idx(U8 *idx)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx)
    {
        *idx = g_shell_app_history.cur_scr_idx;
        return 0;
    }

    return -1;
}
#endif /* __MMI_VUI_3D_CUBE_APP__ */


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_cube_vapp_fold_all_by_buffer
 * DESCRIPTION
 *  This function folds the widget bar and the shortcut pool in the history
 *  buffer.
 * PARAMETERS
 *  buf         : [IN]      History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_cube_vapp_fold_all_by_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappHsShortcutPanel::foldState();
    return;
}

#endif /* __MMI_VUI_HOMESCREEN__ */

