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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vcui_bookmark.cpp
 *
 * Project:
 * -------- 
 *  Bookmark CUI
 *
 * Description:
 * ------------
 *  This file contains bookmark CUI for no browser solution enabled.
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

#if (defined(__COSMOS_MMI_PACKAGE__) && !defined(BROWSER_SUPPORT))

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "GlobalResDef.h"

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern "C"
{

mmi_id vcui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    return GRP_ID_INVALID;
}

void vcui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    return;
}

void vcui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    return;
}

mmi_id vcui_bkm_add_bkm_create(mmi_id parent_gid)
{
    return GRP_ID_INVALID;
}

void vcui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url)
{
    return;
}

void vcui_bkm_add_bkm_close(mmi_id cui_gid)
{
    return;
}

#define DUMMY_FUNCTION_FOR_OLD_PLUTOMMI_INTERFACE

mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    return GRP_ID_INVALID;
}

void cui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    return;
}

void cui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    return;
}

mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid)
{
    return GRP_ID_INVALID;
}

void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url)
{
    return;
}

void cui_bkm_add_bkm_close(mmi_id cui_gid)
{
    return;
}

}

#endif /* defined(__COSMOS_MMI_PACKAGE__) && !defined(BROWSER_SUPPORT) */

