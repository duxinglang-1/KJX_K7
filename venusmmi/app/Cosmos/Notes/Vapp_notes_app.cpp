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
 *  Vapp_notes_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Source file for the class definition for the Notes application class
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


#ifndef __VAPP_NOTES_APP_CPP__
#define __VAPP_NOTES_APP_CPP__

#include "MMI_features.h" 
#ifdef __MMI_NOTE_APP__
#include "vcp_include.h"
extern "C" 
{
	#include "GlobalResDef.h"
}
#include "Vapp_notes_app.h"
#include "Vapp_notes_list.h"
#include "vadp_mmi_frm.h"
#include "Vapp_notes_struct.h"


extern "C" void mmi_note_set_color_selected_from_category_screen(U16 color);
extern "C" void vapp_notes_set_searched_count(U8 count);
extern "C" void vapp_notes_search_mode_reset(void);
/*code segment*/
VfxId page_id;

extern "C" void vapp_notes_app_launch(void)
{
	VfxApp *app = NULL;
	app = VfxAppLauncher::findApp(
							VAPP_NOTES,
							VFX_OBJ_CLASS_INFO(VappNotesApp),
							VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
							
	if (app)
    {
        VfxAppLauncher::terminate(app->getGroupId());
    }
	
    VfxAppLauncher::launch( 
        VAPP_NOTES,
        VFX_OBJ_CLASS_INFO(VappNotesApp),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappNotesApp", VappNotesApp, VfxApp);

void VappNotesApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappNotesScreen *scr;
    VFX_OBJ_CREATE(scr, VappNotesScreen, this);	 			
    scr->show();
}

VFX_IMPLEMENT_CLASS("VappNotesScreen", VappNotesScreen, VfxMainScr);

void VappNotesScreen::on1stReady()
{
   VfxMainScr::on1stReady();
		
   mmi_note_set_color_selected_from_category_screen(0);
   vapp_notes_set_searched_count(0);
	vapp_notes_search_mode_reset();

   VappNotesPage *page;
   VFX_OBJ_CREATE(page, VappNotesPage, this);
	page_id = pushPage(VFX_ID_NULL, page);	
}

#endif  /* __MMI_NOTE_APP__*/
#endif /* __VAPP_NOTES_APP_CPP__ */
