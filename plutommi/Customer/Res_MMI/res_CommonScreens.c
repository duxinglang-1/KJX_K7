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

/**************************************************************

	FILENAME	: Res_.c

  	PURPOSE		: Populate Resource for

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-11-2003

**************************************************************/
#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */
    
#include "MMIDataType.h"    /* for resource base */
    
#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "CommonScreensResDef.h" /* for resource ID */
#include "CommonScreensProt.h"

void PopulateCommonScreensResData(void)
{

    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_DONE_OPTION_ID, mmi_frm_highlight_inline_generic_done);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_INPUT_METHOD_OPTION_ID, mmi_frm_highlight_input_method_generic);
    ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 2,
                                MENU_DONE_OPTION_ID,
                                MENU_INPUT_METHOD_OPTION_ID,
                                SHOW, NONMOVEABLE, DISP_LIST,
                                STR_GLOBAL_OPTIONS, 0));
                                ADD_APPLICATION_MENUITEM ((MENU_DONE_OPTION_ID,
                                MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 
                                SHOW, NONMOVEABLE, DISP_LIST,
                                STR_GLOBAL_DONE, 0));
                                ADD_APPLICATION_MENUITEM ((MENU_INPUT_METHOD_OPTION_ID,
                                MENU_INPUT_METHOD_AND_DONE_OPTION_ID, 0, 
                                SHOW, NONMOVEABLE, DISP_LIST,
                                STR_GLOBAL_INPUT_METHOD, 0));

}



