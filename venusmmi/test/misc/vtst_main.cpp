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
 *  vtst_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus test application.
 *  A temp porting Venus UI Core to PlutoMMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vtst_main.h"

#include "vtst_hello.h"
#include "vtst_string.h"
#include "vtst_frame_anchor.h"
#include "vtst_frame_filter.h"
#include "vtst_test_button.h"
#include "vtst_test_control.h"
#include "vtst_auto_animate.h"
#include "vtst_network_info.h"
#include "vtst_drag.h"

#include "vfx_app_cat_scr.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"

extern "C"
{
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VTST_MAIN_SCR_DUMMY             0

#define VTST_MAIN_CATEGORY_NAME         VtstHelloScr
//#define VTST_MAIN_CATEGORY_NAME         VtstStringScr
//#define VTST_MAIN_CATEGORY_NAME         VtstFrameAnchorScr
//#define VTST_MAIN_CATEGORY_NAME         VtstFrameFilterScr
//#define VTST_MAIN_CATEGORY_NAME         VtstTestControlScr
//#define VTST_MAIN_CATEGORY_NAME         VtstAutoAnimateScr
//#define VTST_MAIN_CATEGORY_NAME         VtstNetworkInfoScr
//#define VTST_MAIN_CATEGORY_NAME         VtstDragScr


/***************************************************************************** 
 * Static Variable
 *****************************************************************************/

static VfxAppCatScr *g_vtst_main_screen_ptr;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vtst_main_entry
 * DESCRIPTION
 *  Venus application test screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vtst_main_entry(void)
{
    EntryNewScreen(VTST_MAIN_SCR_DUMMY, vtst_main_leave, NULL, NULL);

    /* Register volumn up key to dump debug information */
    SetKeyHandler(vtst_main_dump, KEY_VOL_UP, KEY_EVENT_DOWN);

    /* Enter the APP category screen */
    VfxAppCatScr::initalize();
    
    VFX_OBJ_CREATE(
        g_vtst_main_screen_ptr, 
        VTST_MAIN_CATEGORY_NAME, 
        VfxAppCatScr::getContext());
}


/*****************************************************************************
 * FUNCTION
 *  vtst_main_leave
 * DESCRIPTION
 *  Venus application test screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vtst_main_leave(void)
{
    /* Leave the APP category screen */
    VFX_OBJ_CLOSE(g_vtst_main_screen_ptr);
    
    VfxAppCatScr::deinitalize();
}


/*****************************************************************************
 * FUNCTION
 *  vtst_main_dump
 * DESCRIPTION
 *  Dump memory debug information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vtst_main_dump(void)
{
#ifdef VFX_TRACE_ENABLE
    VFX_TRACE(("===== Debug =====\n"));

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->debugDump();
    
    VFX_TRACE(("===== End =====\n\n"));
#endif
}

