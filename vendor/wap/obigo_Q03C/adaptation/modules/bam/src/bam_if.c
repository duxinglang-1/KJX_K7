/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_if.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   BAM interfaces
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "StdC.h"       /* For STD_C and Osl Memory functions */

#include "msf_def.h"
#include "msf_int.h"
#include "msf_chrs.h"
//#include "msf_chrt.h"
#include "msf_core.h"
#include "msf_dcvt.h"
#include "msf_env.h"
#include "msf_mem.h"
#include "msf_url.h"
#include "msf_xchr.h"

#include "bam_cmn.h"
#include "bam_if.h"
#include "bam_lib.h"
#include "bam_msg.h"
#include "bam_registry.h"
#include "bam_win.h"
#include "bam_main.h"
#include "msf_log.h"

#include "bam_sif.h"    /* For bam_get_brs_security_id() */
#if 0
/* under construction !*/
#endif
#include "widget.h"
#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#endif

#ifdef MTK_TMP_PATCH /* TR34722, TR34686: Loading large web page and MT call comes */
#include "WguiCategoryGprot.h"
#include "UcmSrvGprot.h"
#endif /* MTK_TMP_PATCH */

#include "EngineerModeInetAppGprot.h"

#include "mmi_features.h" /* For the compile options of charsets */
#include "kal_release.h"
#include "kal_public_defs.h"
#include "gpiosrvgprot.h"
#include "app_ua.h"
#ifdef OBIGO_Q03C_BROWSER
 /**********************************************************************
 * API invoked from other modules
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  BAMif_startInterface
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_startInterface(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_startInterface)
    MSF_LOG_FC_PRE_IMPL
  //MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_BAM, bam_convert, bam_destruct);

    MSF_LOG_FC_END
}

/**********************************************************************
 * Conversion routines for all signal parameter structs
 **********************************************************************/

#ifdef MSF_CVT_MOD
/*****************************************************************************
 * FUNCTION
 *  bam_cvt_create_instance
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_create_instance(msf_dcvt_t *obj, bam_create_instance_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_bool(obj, &(p->is_full_screen)) ||
        !msf_dcvt_int32(obj, &(p->window_position_x)) || !msf_dcvt_int32(obj, &(p->window_position_y)) ||
        !msf_dcvt_int32(obj, &(p->window_size_height)) || !msf_dcvt_int32(obj, &(p->window_size_width)) ||
        !msf_dcvt_int32(obj, &(p->category_lyr_a_hndl)) || !msf_dcvt_int32(obj, &(p->category_lyr_b_hndl)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_instance
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_instance(msf_dcvt_t *obj, bam_delete_instance_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_load_url
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_load_url(msf_dcvt_t *obj, bam_load_url_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->options)) ||
        !msf_dcvt_int32(obj, &(p->charset)) || !msf_dcvt_string(obj, &(p->url)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_load_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_load_data(msf_dcvt_t *obj, bam_load_data_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->options)) ||
        !msf_dcvt_int32(obj, &(p->charset)) || !msf_dcvt_string(obj, &(p->content_path)))
    {
        return FALSE;
    }

    return TRUE;
}


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/*****************************************************************************
 * FUNCTION
 *  bam_cvt_activate_do_element
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_activate_do_element(msf_dcvt_t *obj, bam_activate_do_element_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->element_id)))
    {
        return FALSE;
    }

    return TRUE;
}
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_move(msf_dcvt_t *obj, bam_move_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint8(obj, &(p->direction)) ||
        !msf_dcvt_uint8(obj, &(p->steps)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_reload
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_reload(msf_dcvt_t *obj, bam_reload_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_stop(msf_dcvt_t *obj, bam_stop_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_navigation_change
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_navigation_change(msf_dcvt_t *obj, bam_navigation_change_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int16(obj, &(p->elements)))
    {
        return FALSE;
    }

    return TRUE;
}


#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_cvt_save_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_save_page(msf_dcvt_t *obj, bam_save_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->overwrite)) ||
        !msf_dcvt_string(obj, &(p->label)) || !msf_dcvt_string(obj, &(p->url)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_saved_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_saved_page(msf_dcvt_t *obj, bam_get_saved_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_load_saved_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_load_saved_page(msf_dcvt_t *obj, bam_load_saved_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_saved_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_saved_page(msf_dcvt_t *obj, bam_delete_saved_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_n_saved_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_n_saved_page(msf_dcvt_t *obj, bam_delete_n_saved_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->count)) || !msf_dcvt_array(
            obj,
            sizeof(MSF_INT32),
            p->count,
            (void **)&p->index_array,
            (msf_dcvt_element_t*) msf_dcvt_int32))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_all_saved_pages
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_all_saved_pages(msf_dcvt_t *obj, bam_delete_all_saved_pages_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_saved_pages_list_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_saved_pages_list_start(msf_dcvt_t *obj, bam_get_saved_pages_list_start_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_saved_pages_list_continue
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_saved_pages_list_continue(msf_dcvt_t *obj, bam_get_saved_pages_list_continue_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->start_index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_saved_pages_list_end
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_saved_pages_list_end(msf_dcvt_t *obj, bam_get_saved_pages_list_end_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * int
 * bam_cvt_navigate_to_hotspot (msf_dcvt_t *obj, bam_navigate_to_hotspot_req_struct *p)
 * {
 * if (!msf_dcvt_int32 (obj, &(p->instance_id))
 * || !msf_dcvt_int32 (obj, &(p->direction)))
 * {
 * return FALSE;
 * }
 *
 * return TRUE;
 * }
 */

//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
/*****************************************************************************
 * FUNCTION
 *  bam_cvt_change_setting_value
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_change_setting_value(msf_dcvt_t *obj, bam_change_setting_value_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint8(obj, &(p->type)) ||
        !msf_dcvt_int32(obj, &(p->setting_id)) || !msf_dcvt_int32(obj, &(p->value_i)) ||
        !msf_dcvt_string(obj, &(p->value_bv)))
    {
        return FALSE;
    }

    return TRUE;
}
//#endif

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
int bam_cvt_wmls_create_dialogue_rsp(msf_dcvt_t *obj, bam_wmls_create_dialogue_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->dialup_type)) ||
		!msf_dcvt_bool(obj, &(p->result)) ||
		!msf_dcvt_string(obj, &(p->msg)))
    {
        return FALSE;
    }

    return TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  bam_cvt_set_profile
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_set_profile(msf_dcvt_t *obj, bam_set_profile_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint8(obj, &(p->request_id)) || !msf_dcvt_uint8(obj, &(p->setting_id)) ||
        !msf_dcvt_array(
            obj,
            sizeof(MSF_INT32),
            BAM_SETTING_ID_TOTAL,
            (void **)&p->int_value_table,
            (msf_dcvt_element_t*) msf_dcvt_int32) ||
        !msf_dcvt_array(
            obj,
            sizeof(char*),
            BAM_SETTING_ID_TOTAL,
            (void **)&p->str_value_table,
            (msf_dcvt_element_t*) msf_dcvt_string))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_recent_pages_list_start
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_recent_pages_list_start(msf_dcvt_t *obj, bam_get_recent_pages_list_start_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->sort_option)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_recent_pages_list_continue
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_recent_pages_list_continue(msf_dcvt_t *obj, bam_get_recent_pages_list_continue_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->start_index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_recent_pages_list_end
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_recent_pages_list_end(msf_dcvt_t *obj, bam_get_recent_pages_list_end_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_get_recent_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_get_recent_page(msf_dcvt_t *obj, bam_get_recent_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_load_recent_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_load_recent_page(msf_dcvt_t *obj, bam_load_recent_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->charset)) ||
        !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_recent_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_recent_page(msf_dcvt_t *obj, bam_delete_recent_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->index)))
    {
        return FALSE;
    }

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_n_recent_page
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_n_recent_page(msf_dcvt_t *obj, bam_delete_n_recent_page_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->count)) || !msf_dcvt_array(
            obj,
            sizeof(MSF_UINT32),
            p->count,
            (void **)&p->index_array,
            (msf_dcvt_element_t*) msf_dcvt_uint32))
    {
        return FALSE;
    }

    return TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  bam_cvt_delete_all_recent_pages
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_delete_all_recent_pages(msf_dcvt_t *obj, bam_delete_all_recent_pages_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_register_keypad_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_register_keypad_handler(msf_dcvt_t *obj, bam_register_keypad_handler_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)))
    {
        return FALSE;
    }

    return TRUE;
}

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_notify_screen_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_notify_screen_info(msf_dcvt_t *obj, bam_notify_screen_info_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_uint32(obj, &(p->x)) || 
        !msf_dcvt_uint32(obj, &(p->y)) ||!msf_dcvt_uint32(obj, &(p->w)) || !msf_dcvt_uint32(obj, &(p->h)) ||
        !msf_dcvt_int32(obj, &(p->category_lyr_a_hndl)) || !msf_dcvt_int32(obj, &(p->category_lyr_b_hndl)))
    {
        return FALSE;
    }

    return TRUE;
}

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_cvt_select_file_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_select_file_rsp(msf_dcvt_t *obj, bam_select_file_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int16(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->request_id)) ||
        !msf_dcvt_int16(obj, &(p->error_code)) || !msf_dcvt_string(obj, &(p->filename)))
    {
        return FALSE;
    }

    return TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  bam_cvt_wtai_tel_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_wtai_tel_rsp(msf_dcvt_t *obj, bam_wtai_tel_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint16(obj, &(p->request_id)) || !msf_dcvt_uint16(obj, &(p->operation)) ||
		!msf_dcvt_uint16(obj, &(p->error_code)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_wtai_pb_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_wtai_pb_rsp(msf_dcvt_t *obj, bam_wtai_pb_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint16(obj, &(p->request_id)) || !msf_dcvt_uint16(obj, &(p->error_code)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_uri_request_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_uri_request_rsp(msf_dcvt_t *obj, bam_uri_request_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint16(obj, &(p->request_id)) || !msf_dcvt_uint16(obj, &(p->error_code)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_user_action_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_user_action_ind(msf_dcvt_t *obj, bam_wait_user_action_ind_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || 
        !msf_dcvt_bool(obj, &(p->enable_positive_sk)) ||
        !msf_dcvt_bool(obj, &(p->enable_negative_sk)) ||
        !msf_dcvt_int32(obj, &(p->positive_label_len)) ||
        !msf_dcvt_int32(obj, &(p->negative_label_len)) ||
        !msf_dcvt_string(obj, &(p->positive_label)) ||
        !msf_dcvt_string(obj, &(p->negative_label)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_user_action_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_user_action_rsp(msf_dcvt_t *obj, bam_wait_user_action_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_bool(obj, &(p->press_positive_sk)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_object_action
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_object_action(msf_dcvt_t *obj, bam_object_action_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int16(obj, &(p->type)))
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cvt_show_auth_dialog_rsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  obj     [?]
 *  p       [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_cvt_show_auth_dialog_rsp(msf_dcvt_t *obj, bam_show_auth_dialog_rsp_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, &(p->instance_id)) || !msf_dcvt_int32(obj, &(p->request_id)) ||
        !msf_dcvt_uint16(obj, &(p->options)) || !msf_dcvt_string(obj, &(p->username)) ||
        !msf_dcvt_string(obj, &(p->password)))
    {
        return FALSE;
    }

    return TRUE;
}


#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
int bam_cvt_delete_offline_page_rsp(msf_dcvt_t *cvt_obj, bam_delete_offline_page_rsp_struct *p)
{
  if (!msf_dcvt_int16(cvt_obj, &(p->instanceId)) ||
      !msf_dcvt_string(cvt_obj, &(p->url)) ||
      !msf_dcvt_int16(cvt_obj, &(p->result)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}
#endif

int bam_cvt_em_setting_changed_ind(msf_dcvt_t *cvt_obj, bam_em_setting_changed_ind_struct *p)
{
  if (!msf_dcvt_uint8(cvt_obj, &(p->opt)) ||
      !msf_dcvt_uint32(cvt_obj, &(p->value_int)) ||
      !msf_dcvt_string(cvt_obj, &(p->value_str)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}

int bam_cvt_close_connection_by_netid(msf_dcvt_t *cvt_obj, bam_close_connection_by_netid_struct *p)
{
  if (!msf_dcvt_uint32(cvt_obj, &(p->net_id)))
  {
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}
#endif /* end cvt mod*/
/**********************************************************************
 * Signal-sending functions
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  BAMif_createInstance
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id               [IN]
 *  window_position_x       [IN]
 *  window_position_y       [IN]
 *  window_size_height      [IN]
 *  window_size_width       [IN]
 *  category_lyr_a_hndl     [IN]
 *  category_lyr_b_hndl     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_createInstance(
    MSF_UINT8 source_id,
    MSF_BOOL is_full_screen,
    MSF_INT32 window_position_x,
    MSF_INT32 window_position_y,
    MSF_INT32 window_size_height,
    MSF_INT32 window_size_width,
    MSF_INT32 category_lyr_a_hndl,
    MSF_INT32 category_lyr_b_hndl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_create_instance_req_struct *param;
    //msf_dcvt_t cvt_obj;
    //MSF_UINT16 length;
    //void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_createInstance)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(window_position_x, NULL)
    MSF_LOG_FC_INT(window_position_y, NULL)
    MSF_LOG_FC_INT(window_size_height, NULL)
    MSF_LOG_FC_INT(window_size_width, NULL)
    MSF_LOG_FC_INT(category_lyr_a_hndl, NULL)
    MSF_LOG_FC_INT(category_lyr_b_hndl, NULL)
    MSF_LOG_FC_PRE_IMPL

    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_create_instance_req_struct));
	memset(param, 0, sizeof(bam_create_instance_req_struct));

    param->is_full_screen= (MSF_BOOL) is_full_screen;
    param->window_position_x = (MSF_INT32) window_position_x;
    param->window_position_y = (MSF_INT32) window_position_y;
    param->window_size_height = (MSF_INT32) window_size_height;
    param->window_size_width = (MSF_INT32) window_size_width;
    param->window_size_height = (MSF_INT32) category_lyr_a_hndl;
    param->window_size_width = (MSF_INT32) category_lyr_a_hndl;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_CREATE_INSTANCE_REQ,param);

    //BAM_SEND_SIGNAL(bam_cvt_create_instance, BAM_SIG_CREATE_INSTANCE_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_deleteInstance
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_deleteInstance(MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_instance_req_struct *param;
    //msf_dcvt_t cvt_obj;
    //MSF_UINT16 length;
    //void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_deleteInstance)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_instance_req_struct));
	memset(param, 0, sizeof(bam_delete_instance_req_struct));

    param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(MSF_MODID_BAM,MSF_MODID_BAM,BAM_SIG_DELETE_INSTANCE_REQ,param);

    //BAM_SEND_SIGNAL(bam_cvt_delete_instance, BAM_SIG_DELETE_INSTANCE_REQ, MSF_MODID_BAM /* src */ , MSF_MODID_BAM);

    MSF_LOG_FC_END
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  BAMif_loadUrl
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  options         [IN]
 *  charset         [IN]
 *  url             [?]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_loadUrl(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 options, MSF_INT32 charset, char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_load_url_req_struct *param;
    //msf_dcvt_t cvt_obj;
    //MSF_UINT16 length;
    //void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_loadUrl)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_INT(options, NULL)
    MSF_LOG_FC_INT(charset, NULL)
    MSF_LOG_FC_STRING(url, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_load_url_req_struct));
	memset(param, 0, sizeof(bam_load_url_req_struct));
	

    param->instance_id = (MSF_INT32) instance_id;
    param->options = (MSF_INT32) options;
    param->charset = (MSF_INT32) charset;
    param->url = msf_cmmn_strdup(MSF_MODID_BAM,url);

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_LOAD_URL_REQ,param);

   // BAM_SEND_SIGNAL(bam_cvt_load_url, BAM_SIG_LOAD_URL_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_loadData
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id           [IN]
 *  instance_id         [IN]
 *  options             [IN]
 *  charset             [IN]
 *  content_path        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_loadData(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 options, MSF_INT32 charset, char *content_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_load_data_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_loadData)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_INT(options, NULL)
    MSF_LOG_FC_INT(charset, NULL)
    MSF_LOG_FC_STRING(content_path, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_load_data_req_struct));
	memset(param, 0, sizeof(bam_load_data_req_struct));


	

    param->instance_id = (MSF_INT32) instance_id;
    param->options = (MSF_INT32) options;
    param->charset = (MSF_INT32) charset;
    param->content_path = msf_cmmn_strdup(MSF_MODID_BAM,content_path);

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_LOAD_DATA_REQ,param);

   // BAM_SEND_SIGNAL(bam_cvt_load_data, BAM_SIG_LOAD_DATA_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/*****************************************************************************
 * FUNCTION
 *  BAMif_activateDoElement
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  element_id      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_activateDoElement(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 element_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_activate_do_element_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_activateDoElement)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_INT(element_id, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_activate_do_element_req_struct));
	memset(param, 0, sizeof(bam_activate_do_element_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
    param->element_id = (MSF_UINT32) element_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_ACTIVATE_DO_ELEMENT_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_activate_do_element, BAM_SIG_ACTIVATE_DO_ELEMENT_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */


/*****************************************************************************
 * FUNCTION
 *  BAMif_move
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  direction       [IN]
 *  steps           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_move(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT8 direction, MSF_UINT8 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_move_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_move)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_UINT8(direction, NULL)
    MSF_LOG_FC_UINT8(steps, NULL)
    MSF_LOG_FC_PRE_IMPL

    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_move_req_struct));
	memset(param, 0, sizeof(bam_move_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
    param->direction = (MSF_UINT8) direction;
    param->steps = (MSF_UINT8) steps;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_MOVE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_move, BAM_SIG_MOVE_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_reload
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_reload(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_reload_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  // MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_reload)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_reload_req_struct));
	memset(param, 0, sizeof(bam_reload_req_struct));

    param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_RELOAD_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_reload, BAM_SIG_RELOAD_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_stop(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_stop_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_stop)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_stop_req_struct));
	memset(param, 0, sizeof(bam_stop_req_struct));

    param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_STOP_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_stop, BAM_SIG_STOP_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_navigationChange
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  elements        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_navigationChange(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT16 elements)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_navigation_change_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_FC_BEGIN(BAMif_navigationChange)
    MSF_LOG_FC_UINT8(source_id, NULL)
    MSF_LOG_FC_INT(instance_id, NULL)
    MSF_LOG_FC_INT16(elements, NULL)
    MSF_LOG_FC_PRE_IMPL

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_navigation_change_req_struct));
	memset(param, 0, sizeof(bam_navigation_change_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
    param->elements = elements;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_NAVIGATION_CHANGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_navigation_change, BAM_SIG_NAVIGATION_CHANGE_REQ, source_id, MSF_MODID_BAM);

    MSF_LOG_FC_END
}


#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  BAMif_savePage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  overwrite       [IN]
 *  label           [?]
 *  url             [?]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_savePage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 overwrite, char *label, char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_save_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_save_page_req_struct));
	memset(param, 0, sizeof(bam_save_page_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
    param->label = msf_cmmn_strdup(MSF_MODID_BAM,label);
    param->url = msf_cmmn_strdup(MSF_MODID_BAM,url);
    param->overwrite = (MSF_INT32) overwrite;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_SAVE_PAGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_save_page, BAM_SIG_SAVE_PAGE_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getSavedPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_saved_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_saved_page_req_struct));
	memset(param, 0, sizeof(bam_get_saved_page_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_SAVED_PAGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_get_saved_page, BAM_SIG_GET_SAVED_PAGE_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_loadSavedPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_loadSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_load_saved_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_load_saved_page_req_struct));
	memset(param, 0, sizeof(bam_load_saved_page_req_struct));

	
    param->instance_id = (MSF_INT32) instance_id;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_LOAD_SAVED_PAGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_load_saved_page, BAM_SIG_LOAD_SAVED_PAGE_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_deleteSavedPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_deleteSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_saved_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_saved_page_req_struct));
	memset(param, 0, sizeof(bam_delete_saved_page_req_struct));

	
    param->instance_id = (MSF_INT32) instance_id;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_SAVED_PAGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_delete_saved_page, BAM_SIG_DELETE_SAVED_PAGE_REQ, source_id, MSF_MODID_BAM);
}


void BAMif_deleteNSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 *index_array,MSF_UINT32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_n_saved_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_n_saved_page_req_struct));
	memset(param, 0, sizeof(bam_delete_n_saved_page_req_struct));

    param->instance_id = (MSF_INT32) instance_id;
	param->index_array = (MSF_UINT32*)msf_cmmn_memndup (MSF_MODID_BAM,index_array,count*sizeof(MSF_UINT32));
    //param->index_array=index_array;
    param->count=(MSF_UINT32) count;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_N_SAVED_PAGE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_delete_n_saved_page, BAM_SIG_DELETE_N_SAVED_PAGE_REQ, source_id, MSF_MODID_BAM);
}

/*****************************************************************************
 * FUNCTION
 *  BAMif_deleteAllSavedPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_deleteAllSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_all_saved_pages_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_all_saved_pages_req_struct));
	memset(param, 0, sizeof(bam_delete_all_saved_pages_req_struct));

	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_delete_all_saved_pages, BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ, source_id, MSF_MODID_BAM);
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  BAMif_getSavedPagesListStart
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getSavedPagesListStart(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_saved_pages_list_start_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_saved_pages_list_start_req_struct));
	memset(param, 0, sizeof(bam_get_saved_pages_list_start_req_struct));

	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ,param);

   /* BAM_SEND_SIGNAL(
        bam_cvt_get_saved_pages_list_start,
        BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ,
        source_id,
        MSF_MODID_BAM);*/
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getSavedPagesListContinue
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  start_index     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getSavedPagesListContinue(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_saved_pages_list_continue_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_saved_pages_list_continue_req_struct));
	memset(param, 0, sizeof(bam_get_saved_pages_list_continue_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->start_index = (MSF_UINT32) start_index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ,param);

  /*  BAM_SEND_SIGNAL(
        bam_cvt_get_saved_pages_list_continue,
        BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ,
        source_id,
        MSF_MODID_BAM);*/
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getSavedPagesListEnd
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getSavedPagesListEnd(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_saved_pages_list_end_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_saved_pages_list_end_req_struct));
	memset(param, 0, sizeof(bam_get_saved_pages_list_end_req_struct));

	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_get_saved_pages_list_end, BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ, source_id, MSF_MODID_BAM);
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * void
 * BAMif_navigateToHotspot (MSF_UINT8  source_id,
 * MSF_INT32   instance_id,
 * MSF_INT32   direction)
 * {
 *
 * }
 */

//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
/*****************************************************************************
 * FUNCTION
 *  BAMif_changeSettingValue
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  type            [IN]
 *  setting_id      [IN]
 *  value_i         [IN]
 *  value_bv        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_changeSettingValue(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_UINT8 type,
    MSF_INT32 setting_id,
    MSF_INT32 value_i,
    char *value_bv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_change_setting_value_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_change_setting_value_req_struct));
	memset(param, 0, sizeof(bam_change_setting_value_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->type = (MSF_UINT8) type;
    param->setting_id = (MSF_INT32) setting_id;
    param->value_i = (MSF_INT32) value_i;
    param->value_bv = msf_cmmn_strdup (MSF_MODID_BAM,value_bv);

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_CHANGE_SETTING_VALUE_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_change_setting_value, BAM_SIG_CHANGE_SETTING_VALUE_REQ, source_id, MSF_MODID_BAM);
}
//#endif


/*****************************************************************************
 * FUNCTION
 *  BAMif_setProfile
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  request_id      [IN]
 *  profile         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_setProfile(
        MSF_UINT8 source_id,
        MSF_INT32 instance_id,
        MSF_UINT8 request_id,
        MSF_UINT8 setting_id,
		bam_set_profile_option_enum type,
        bam_profile_setting_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_set_profile_req_struct *param;
	int i;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_set_profile_req_struct));
	memset(param, 0, sizeof(bam_set_profile_req_struct));
	

	param->instance_id = (MSF_INT32) instance_id;
    param->request_id = (MSF_UINT8) request_id;
    param->setting_id = (MSF_UINT8) setting_id;
	param->type=(bam_set_profile_option_enum) type;
    param->int_value_table = (MSF_UINT32*)msf_cmmn_memndup (MSF_MODID_BAM,(void *)profile->int_value_table,BAM_SETTING_ID_TOTAL*(sizeof(MSF_INT32)));
    param->str_value_table = (char**)msf_cmmn_memndup (MSF_MODID_BAM,(void *)profile->str_value_table,BAM_SETTING_ID_TOTAL*(sizeof(MSF_INT32)));
	for (i = 0; i < BAM_SETTING_ID_TOTAL; i++)
    {
        if (profile->str_value_table[i] != NULL)
        {   
			param->str_value_table[i] = (char*)msf_cmmn_memndup (MSF_MODID_BAM,(void *)profile->str_value_table[i],(strlen(profile->str_value_table[i])+1));
        }
    }

    

    MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_SET_PROFILE_REQ,param);
  //BAM_SEND_SIGNAL(bam_cvt_set_profile, BAM_SIG_SET_PROFILE_REQ, source_id, MSF_MODID_BAM);
}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  BAMif_getRecentPagesListStart
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  sort_option     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getRecentPagesListStart(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_recent_pages_list_start_req_struct *param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_recent_pages_list_start_req_struct));
	memset(param, 0, sizeof(bam_get_recent_pages_list_start_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->sort_option = (MSF_INT32) sort_option;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ,param);

   /* BAM_SEND_SIGNAL(
        bam_cvt_get_recent_pages_list_start,
        BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ,
        source_id,
        MSF_MODID_BAM);*/
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getRecentPagesListContinue
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  start_index     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getRecentPagesListContinue(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_recent_pages_list_continue_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_recent_pages_list_continue_req_struct));
	memset(param, 0, sizeof(bam_get_recent_pages_list_continue_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->start_index = (MSF_UINT32) start_index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ,param);

   /* BAM_SEND_SIGNAL(
        bam_cvt_get_recent_pages_list_continue,
        BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ,
        source_id,
        MSF_MODID_BAM);*/
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getRecentPagesListEnd
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getRecentPagesListEnd(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_recent_pages_list_end_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_recent_pages_list_end_req_struct));
	memset(param, 0, sizeof(bam_get_recent_pages_list_end_req_struct));

	
	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ,param);   

  //  BAM_SEND_SIGNAL(bam_cvt_get_recent_pages_list_end, BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_getRecentPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_getRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_get_recent_page_req_struct *param;
 //   msf_dcvt_t cvt_obj;
 //   MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_get_recent_page_req_struct));
	memset(param, 0, sizeof(bam_get_recent_page_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_GET_RECENT_PAGE_REQ,param);   

  //  BAM_SEND_SIGNAL(bam_cvt_get_recent_page, BAM_SIG_GET_RECENT_PAGE_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_loadRecentPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  charset         [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_loadRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 charset, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_load_recent_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_load_recent_page_req_struct));
	memset(param, 0, sizeof(bam_load_recent_page_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->charset = (MSF_INT32) charset;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_LOAD_RECENT_PAGE_REQ,param);   

  //  BAM_SEND_SIGNAL(bam_cvt_load_recent_page, BAM_SIG_LOAD_RECENT_PAGE_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_deleteRecentPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  index           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_deleteRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_recent_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_recent_page_req_struct));
	memset(param, 0, sizeof(bam_delete_recent_page_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->index = (MSF_UINT32) index;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_RECENT_PAGE_REQ,param); 

  //  BAM_SEND_SIGNAL(bam_cvt_delete_recent_page, BAM_SIG_DELETE_RECENT_PAGE_REQ, source_id, MSF_MODID_BAM);
}


void BAMif_deleteNRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 *index_array,MSF_UINT32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_n_recent_page_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_n_recent_page_req_struct));
	memset(param, 0, sizeof(bam_delete_n_recent_page_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->index_array = (MSF_UINT32*)msf_cmmn_memndup (MSF_MODID_BAM,(void *)index_array,count*sizeof(int));
    param->count=(MSF_UINT32) count;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_N_RECENT_PAGE_REQ,param); 

  //  BAM_SEND_SIGNAL(bam_cvt_delete_n_recent_page, BAM_SIG_DELETE_N_RECENT_PAGE_REQ, source_id, MSF_MODID_BAM);
}

/*****************************************************************************
 * FUNCTION
 *  BAMif_deleteAllRecentPage
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_deleteAllRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_delete_all_recent_pages_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_all_recent_pages_req_struct));
	memset(param, 0, sizeof(bam_delete_all_recent_pages_req_struct));

	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ,param);

   // BAM_SEND_SIGNAL(bam_cvt_delete_all_recent_pages, BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ, source_id, MSF_MODID_BAM);
}

#endif /* recent page*/
/*****************************************************************************
 * FUNCTION
 *  BAMif_registerKeypadHandler
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_registerKeypadHandler(MSF_UINT8 source_id, MSF_INT32 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_register_keypad_handler_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_register_keypad_handler_req_struct));
	memset(param, 0, sizeof(bam_register_keypad_handler_req_struct));
	
	
	param->instance_id = (MSF_INT32) instance_id;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_register_keypad_handler, BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ, source_id, MSF_MODID_BAM);
}

void BAMif_BearerOpenRsp(MSF_UINT8 source_id, MSF_INT16 error_code, MSF_INT32 instance_id)
{
    bam_bearer_open_rsp_struct *param;

    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_bearer_open_rsp_struct));
	memset(param, 0, sizeof(bam_bearer_open_rsp_struct));

	param->instance_id=instance_id;
	param->error_code=error_code;
    
    MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM, BAM_SIG_BEARER_OPEN_RSP,param);
}



#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/*****************************************************************************
 * FUNCTION
 *  bam_handle_pen_event_ext
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  pos_x           [IN]
 *  pos_y           [IN]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_handle_pen_event_ext(int instance_id, int pos_x, int pos_y, int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_handle_pen_event_req_struct param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param.instance_id = (MSF_INT32) instance_id;
    param.pos_x = (MSF_INT16) pos_x;
    param.pos_y = (MSF_INT16) pos_y;
    param.type = (MSF_INT32) type;

    bam_handle_pen_event_req_hdlr(&param);
    
 }
#endif
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  BAMif_notifyScreenInfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id               [IN]
 *  instance_id             [IN]
 *  x                       [IN]
 *  y                       [IN]
 *  w                       [IN]
 *  h                       [IN]
 *  category_lyr_a_hndl     [IN]
 *  category_lyr_b_hndl     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_notifyScreenInfo(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_UINT32 x,
    MSF_UINT32 y,
    MSF_UINT32 w,
    MSF_UINT32 h,
    MSF_INT32 category_lyr_a_hndl,
    MSF_INT32 category_lyr_b_hndl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_notify_screen_info_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_notify_screen_info_req_struct));
	memset(param, 0, sizeof(bam_notify_screen_info_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->x = (MSF_INT32) x;
    param->y = (MSF_INT32) y;
    param->w = (MSF_INT32) w;
    param->h = (MSF_INT32) h;
    param->category_lyr_a_hndl = (MSF_INT32) category_lyr_a_hndl;
    param->category_lyr_b_hndl = (MSF_INT32) category_lyr_b_hndl;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_NOTIFY_SCREEN_INFO_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_notify_screen_info, BAM_SIG_NOTIFY_SCREEN_INFO_REQ, source_id, MSF_MODID_BAM);
}

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  BAMif_selectFileRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  request_id      [IN]
 *  error_code      [IN]
 *  filename	    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_selectFileRsp(MSF_UINT8 source_id, MSF_INT16 instance_id, MSF_INT32 request_id, MSF_INT16 error_code, char *filename)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_select_file_rsp_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_select_file_rsp_struct));
	memset(param, 0, sizeof(bam_select_file_rsp_struct));
	
	param->instance_id = (MSF_INT16) instance_id;
    param->request_id = (MSF_INT32) request_id;
    param->error_code = (MSF_INT16) error_code;
    param->filename = msf_cmmn_strdup (MSF_MODID_BAM, filename); 

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_SELECT_FILE_RSP,param);
	
  //  BAM_SEND_SIGNAL(bam_cvt_select_file_rsp, BAM_SIG_SELECT_FILE_RSP, source_id, MSF_MODID_BAM);
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  BAMif_uriRequestRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  request_id      [IN]
 *  error_code      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_uriRequestRsp(MSF_UINT8 source_id, MSF_UINT16 request_id, MSF_UINT16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_uri_request_rsp_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_uri_request_rsp_struct));
	memset(param, 0, sizeof(bam_uri_request_rsp_struct));

	param->request_id = (MSF_UINT16) request_id;
    param->error_code = (MSF_UINT16) error_code;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_URI_REQUEST_RSP,param);

  //  BAM_SEND_SIGNAL(bam_cvt_uri_request_rsp, BAM_SIG_URI_REQUEST_RSP, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_waitUserActionRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id               [IN]
 *  instance_id             [IN]
 *  press_positive_sk       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_waitUserActionRsp(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_BOOL press_positive_sk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_wait_user_action_rsp_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_wait_user_action_rsp_struct));
	memset(param, 0, sizeof(bam_wait_user_action_rsp_struct));
	
	param->instance_id = (MSF_INT32) instance_id;
    param->press_positive_sk = (MSF_BOOL) press_positive_sk;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_WAIT_USER_ACTION_RSP,param);

  //  BAM_SEND_SIGNAL(bam_cvt_user_action_rsp, BAM_SIG_WAIT_USER_ACTION_RSP, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_objectAction
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_objectAction(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_object_action_req_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_object_action_req_struct));
	memset(param, 0, sizeof(bam_object_action_req_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->type = (MSF_INT16) type;

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_OBJECT_ACTION_REQ,param);

  //  BAM_SEND_SIGNAL(bam_cvt_object_action, BAM_SIG_OBJECT_ACTION_REQ, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_showAuthDialogRsp
 * DESCRIPTION
 *
 * PARAMETERS
 *  source_id       [IN]
 *  instance_id     [IN]
 *  request_id      [IN]
 *  options         [IN]
 *  username        [?]
 *  password        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_showAuthDialogRsp(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_INT32 request_id,
    MSF_UINT16 options,
    char *username,
    char *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_show_auth_dialog_rsp_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_show_auth_dialog_rsp_struct));
	memset(param, 0, sizeof(bam_show_auth_dialog_rsp_struct));

	param->instance_id = (MSF_INT32) instance_id;
    param->request_id = (MSF_INT32) request_id;
    param->options = (MSF_UINT16) options;
    param->username = msf_cmmn_strdup (MSF_MODID_BAM,username); 
    param->password = msf_cmmn_strdup (MSF_MODID_BAM,password);

	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_SHOW_AUTH_DIALOG_RSP,param);

  //  BAM_SEND_SIGNAL(bam_cvt_show_auth_dialog_rsp, BAM_SIG_SHOW_AUTH_DIALOG_RSP, source_id, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_showAuthDialog
 * DESCRIPTION
 *
 * PARAMETERS
 *  request_id      [IN]
 *  auth_type       [IN]
 *  realm           [IN]
 *  username        [IN]
 *  password        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
BAMif_showAuthDialog(
    MSF_INT32 request_id,
    MSF_INT32 auth_type,
    const char *realm,
    const char *username,
    const char *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_show_auth_dialog_ind(request_id, auth_type, realm, username, password);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_sendErrorInd
 * DESCRIPTION
 *
 * PARAMETERS
 *  error_code      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_sendErrorInd(MSF_INT16 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_error_ind(0, error_code);
}


/*****************************************************************************
 * FUNCTION
 *  BAMif_selectFileInd
 * DESCRIPTION
 *
 * PARAMETERS
 *  instance_id     [IN]
 *  request_id	    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void BAMif_selectFileInd(MSF_INT16 instance_id, MSF_INT32 request_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C_BROWSER
#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
    if(bam_sif_brs_is_idle())
        bam_msg_select_file_ind(instance_id, request_id);
#endif
#endif
}

/*
void BAMif_sendWtaiTelInd (MSF_UINT16 request_id, MSF_UINT16 operation, const char* param)
{
	bam_msg_wtai_tel_ind(request_id, operation,	param, ((param) ? strlen(param) : 0));
}


void BAMif_sendWtaiPbInd (MSF_UINT16 request_id, const char* name, const char* number)
{
	bam_msg_wtai_pb_ind(request_id,	name, ((name) ? strlen(name) : 0), number, ((number) ? strlen(number) : 0));
}

*/
void BAMif_sendURIreq (MSF_UINT16 request_id, const char* scheme, const char* param)
{
	bam_msg_uri_request_ind(request_id,	scheme,	((scheme) ? strlen(scheme) : 0), param,	((param) ? strlen(param) : 0));
}

void BAMif_sendExternalObjectStatusInd(MSF_INT16 status, MSF_INT16 transaction_id)
{
    if (status == BAM_STATUS_EXTERNAL_OBJECT_START_TRANSACTION || 
		status == BAM_STATUS_EXTERNAL_OBJECT_END_TRANSACTION)
    {
		bam_msg_external_object_status_ind(status, transaction_id);		
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT	
void
BAMif_deleteOfflinePageResponse(MSF_UINT8 src, MSF_INT16 instanceId, char* url, MSF_INT16 result)
{
#ifdef OBIGO_Q03C_BROWSER
//  MSF_UINT16                        length;
//  msf_dcvt_t                        cvt_obj;
//  void                              *user_data;
//  void                              *signal_buffer;  
  bam_delete_offline_page_rsp_struct   *param;

  param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_delete_offline_page_rsp_struct));
  memset(param, 0, sizeof(bam_delete_offline_page_rsp_struct));
  
  param->instanceId = instanceId;
  param->url = msf_cmmn_strdup (MSF_MODID_BAM,url);
  param->result = result;
  
  MSF_SIGNAL_SEND(src,MSF_MODID_BAM,BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE,param);
  
  /*msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bam_cvt_delete_offline_page_rsp(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE,
    0, MSF_MODID_BAM, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bam_cvt_delete_offline_page_rsp(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }*/
#endif
}
#endif



void BAMif_wmls_create_dialogue_req(MSF_INT32 instance_id, MSF_INT32 dialup_type,const char *msg,const char *prompt_msg,const char *lsk,const char *rsk)
{
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
#ifdef OBIGO_Q03C_BROWSER
	bam_msg_wmls_create_dialogue_req(instance_id,
		                             dialup_type,
									 msg,
									 prompt_msg,
									 lsk,
									 rsk);
#endif
#endif
}

void BAMif_RenderPageClearKeys(void)
{
#ifdef OBIGO_Q03C_BROWSER
	extern void mmi_brw_ren_page_clear_keys(void);
	mmi_brw_ren_page_clear_keys();
#endif
}

MSF_BOOL BAMif_IsRenderedPageActive(void)
{
#ifdef OBIGO_Q03C_BROWSER
	extern MMI_BOOL mmi_brw_is_rendered_page_active(void);
	return (mmi_brw_is_rendered_page_active());
#else
    return 0;
#endif
}
#ifdef OBIGO_Q03C_BROWSER

void
BAMif_EmSettingChangedInd(MSF_UINT8 opt, MSF_UINT32 value_int, char* value_str)
{
//  MSF_UINT16                        length;
//  msf_dcvt_t                        cvt_obj;
//  void                              *user_data;
//  void                              *signal_buffer;  
  bam_em_setting_changed_ind_struct   *param;
  
  param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_em_setting_changed_ind_struct));
  memset(param, 0, sizeof(bam_em_setting_changed_ind_struct));
  
  param->opt = opt;
  param->value_int = value_int;
  param->value_str = msf_cmmn_strdup (MSF_MODID_BAM,value_str);
  
  MSF_SIGNAL_SEND(MSF_MODID_BAM,MSF_MODID_BAM,BAM_SIG_EM_SETTING_CHANGED_IND,param);
  
 /* msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bam_cvt_em_setting_changed_ind(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BAM_SIG_EM_SETTING_CHANGED_IND,
    0, MSF_MODID_BAM, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bam_cvt_em_setting_changed_ind(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }*/
}

#endif

void
BAMif_handleChannelConfigNotify(void)
{
#ifdef OBIGO_Q03C_BROWSER
 // void *signal_buffer;  
    MSF_SIGNAL_SEND(MSF_MODID_BAM,MSF_MODID_BAM,BAM_SIG_CHANNEL_CONFIG_NOTIFY_IND,NULL);
 // signal_buffer = MSF_SIGNAL_CREATE (BAM_SIG_CHANNEL_CONFIG_NOTIFY_IND, 0, MSF_MODID_BAM, 0);
 // if (signal_buffer != NULL) 
 //   MSF_SIGNAL_SEND (signal_buffer);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  bam_get_max_wap_conn_msg_size
 * DESCRIPTION
 *  Get the maximum total message size for WAP connection
 * PARAMETERS
 *  void
 * RETURNS
 *  maximum total message size.
 *****************************************************************************/
long bam_get_max_wap_conn_msg_size(void)
{
#ifdef OBIGO_Q03C_BROWSER
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return BAM_MAX_WAP_CONN_MSG_SIZE;
#endif
}

#ifdef OBIGO_Q03C_BROWSER

void
BAMif_closeConnectionByNetId(MSF_UINT32 net_id)
{
 // MSF_UINT16                        length;
 // msf_dcvt_t                        cvt_obj;
 // void                              *user_data;
 // void                              *signal_buffer;  
  bam_close_connection_by_netid_struct   *param;
  
  param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_close_connection_by_netid_struct));
  memset(param, 0, sizeof(bam_close_connection_by_netid_struct));
  
  param->net_id = net_id;
  
  MSF_SIGNAL_SEND(MSF_MODID_BAM,MSF_MODID_BAM,BAM_SIG_CLOSE_CONNECTION_BY_NETID,param);
  
  /*msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
  bam_cvt_close_connection_by_netid(&cvt_obj, &param);
  length = (MSF_UINT16)cvt_obj.pos;
  signal_buffer = MSF_SIGNAL_CREATE (BAM_SIG_CLOSE_CONNECTION_BY_NETID,
    0, MSF_MODID_BAM, length);
  if (signal_buffer != NULL) 
  {
    user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
    bam_cvt_close_connection_by_netid(&cvt_obj, &param);
    MSF_SIGNAL_SEND (signal_buffer);
  }*/
}



#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
void BAMif_wmls_create_dialogue_rsp(MSF_INT32 source_id, MSF_INT32 instance_id, MSF_INT32 dialup_type, MSF_BOOL result,const char *msg )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_wmls_create_dialogue_rsp_struct *param;
  //  msf_dcvt_t cvt_obj;
  //  MSF_UINT16 length;
  //  void *signal_buffer, *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_wmls_create_dialogue_rsp_struct));
    memset(param, 0, sizeof(bam_wmls_create_dialogue_rsp_struct));

	param->source_id = (MSF_INT32) source_id;
    param->instance_id = (MSF_INT32) instance_id;
    param->dialup_type = (MSF_UINT32) dialup_type;
	param->result = (MSF_BOOL) result;
    param->msg = msf_cmmn_strdup (MSF_MODID_BAM,msg); 
	
	MSF_SIGNAL_SEND(source_id,MSF_MODID_BAM,BAM_SIG_WMLS_CREATE_DIALOGUE_RSP,param);

 //   BAM_SEND_SIGNAL(bam_cvt_wmls_create_dialogue_rsp, BAM_SIG_WMLS_CREATE_DIALOGUE_RSP, source_id, MSF_MODID_BAM);
}
#endif

#ifdef MSF_CVT_MOD
/*****************************************************************************
 * FUNCTION
 *  bam_convert
 * DESCRIPTION
 *  Convert signals owned by this module from memory buffer to signal
 *  struct.
 *  Every module that defines external signals must have this function.
 *  This function should not be called directly by another module, it is
 *  called by MSF. (It is not necessary to have this function if you are not
 *  having your signals.)
 * PARAMETERS
 *  module      [IN]
 *  signal      [IN]
 *  buffer      [?]
 * RETURNS
 *  void
 *****************************************************************************/
void *bam_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;
    void *user_data;
    MSF_UINT16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return NULL;
    }

    user_data = MSF_SIGNAL_GET_USER_DATA(buffer, &length);

    if ((user_data == NULL) || (length == 0))
    {
        return NULL;
    }

    msf_dcvt_init(&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);

    switch (signal)
    {
        case BAM_SIG_CREATE_INSTANCE_REQ:
        {
            bam_create_instance_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_create_instance_req_struct);
            (void)bam_cvt_create_instance(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_DELETE_INSTANCE_REQ:
        {
            bam_delete_instance_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_instance_req_struct);
            (void)bam_cvt_delete_instance(&cvt_obj, p);
            return (void*)p;
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case BAM_SIG_LOAD_URL_REQ:
        {
            bam_load_url_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_load_url_req_struct);
            (void)bam_cvt_load_url(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_LOAD_DATA_REQ:
        {
            bam_load_data_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_load_data_req_struct);
            (void)bam_cvt_load_data(&cvt_obj, p);
            return (void*)p;
        }

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BAM_SIG_ACTIVATE_DO_ELEMENT_REQ:
        {
            bam_activate_do_element_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_activate_do_element_req_struct);
            (void)bam_cvt_activate_do_element(&cvt_obj, p);
            return (void*)p;
        }
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

        case BAM_SIG_MOVE_REQ:
        {
            bam_move_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_move_req_struct);
            (void)bam_cvt_move(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_RELOAD_REQ:
        {
            bam_reload_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_reload_req_struct);
            (void)bam_cvt_reload(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_STOP_REQ:
        {
            bam_stop_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_stop_req_struct);
            (void)bam_cvt_stop(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_NAVIGATION_CHANGE_REQ:
        {
            bam_navigation_change_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_navigation_change_req_struct);
            (void)bam_cvt_navigation_change(&cvt_obj, p);
            return (void*)p;
        }

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_SAVE_PAGE_REQ:
        {
            bam_save_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_save_page_req_struct);
            (void)bam_cvt_save_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_SAVED_PAGE_REQ:
        {
            bam_get_saved_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_saved_page_req_struct);
            (void)bam_cvt_get_saved_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_LOAD_SAVED_PAGE_REQ:
        {
            bam_load_saved_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_load_saved_page_req_struct);
            (void)bam_cvt_load_saved_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_DELETE_SAVED_PAGE_REQ:
        {
            bam_delete_saved_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_saved_page_req_struct);
            (void)bam_cvt_delete_saved_page(&cvt_obj, p);
            return (void*)p;
        }

		case BAM_SIG_DELETE_N_SAVED_PAGE_REQ:
        {
            bam_delete_n_saved_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_n_saved_page_req_struct);
            (void)bam_cvt_delete_n_saved_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ:
        {
            bam_delete_all_saved_pages_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_all_saved_pages_req_struct);
            (void)bam_cvt_delete_all_saved_pages(&cvt_obj, p);
            return (void*)p;
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ:
        {
            bam_get_saved_pages_list_start_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_saved_pages_list_start_req_struct);
            (void)bam_cvt_get_saved_pages_list_start(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ:
        {
            bam_get_saved_pages_list_continue_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_saved_pages_list_continue_req_struct);
            (void)bam_cvt_get_saved_pages_list_continue(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ:
        {
            bam_get_saved_pages_list_end_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_saved_pages_list_end_req_struct);
            (void)bam_cvt_get_saved_pages_list_end(&cvt_obj, p);
            return (void*)p;
        }
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        /*
         * case BAM_SIG_NAVIGATE_TO_HOTSPOT_REQ:
         * {
         * bam_navigate_to_hotspot_req_struct *p;
         *
         * p = MSF_MEM_ALLOCTYPE (module, bam_navigate_to_hotspot_req_struct);
         * (void) bam_cvt_navigate_to_hotspot (&cvt_obj, p);
         * return (void *)p;
         * }
         */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        case BAM_SIG_CHANGE_SETTING_VALUE_REQ:
        {
            bam_change_setting_value_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_change_setting_value_req_struct);
            (void)bam_cvt_change_setting_value(&cvt_obj, p);
            return (void*)p;
        }
//#endif




#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
		case BAM_SIG_WMLS_CREATE_DIALOGUE_RSP:
		{
			bam_wmls_create_dialogue_rsp_struct *p;

			p = MSF_MEM_ALLOCTYPE(module, bam_wmls_create_dialogue_rsp_struct);
            (void)bam_cvt_wmls_create_dialogue_rsp(&cvt_obj, p);
            return (void*)p;
        }

#endif
        case BAM_SIG_SET_PROFILE_REQ:
        {
            bam_set_profile_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_set_profile_req_struct);
            (void)bam_cvt_set_profile(&cvt_obj, p);
            return (void*)p;
        }
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
        case BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ:
        {
            bam_get_recent_pages_list_start_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_recent_pages_list_start_req_struct);
            (void)bam_cvt_get_recent_pages_list_start(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ:
        {
            bam_get_recent_pages_list_continue_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_recent_pages_list_continue_req_struct);
            (void)bam_cvt_get_recent_pages_list_continue(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ:
        {
            bam_get_recent_pages_list_end_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_recent_pages_list_end_req_struct);
            (void)bam_cvt_get_recent_pages_list_end(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_GET_RECENT_PAGE_REQ:
        {
            bam_get_recent_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_get_recent_page_req_struct);
            (void)bam_cvt_get_recent_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_LOAD_RECENT_PAGE_REQ:
        {
            bam_load_recent_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_load_recent_page_req_struct);
            (void)bam_cvt_load_recent_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_DELETE_RECENT_PAGE_REQ:
        {
            bam_delete_recent_page_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_recent_page_req_struct);
            (void)bam_cvt_delete_recent_page(&cvt_obj, p);
            return (void*)p;
        }

		case BAM_SIG_DELETE_N_RECENT_PAGE_REQ:
        {
            bam_delete_n_recent_page_req_struct *p;

            p = (bam_delete_n_recent_page_req_struct*)MSF_MEM_ALLOCTYPE(module, bam_delete_n_recent_page_req_struct);
            (void)bam_cvt_delete_n_recent_page(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ:
        {
            bam_delete_all_recent_pages_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_all_recent_pages_req_struct);
            (void)bam_cvt_delete_all_recent_pages(&cvt_obj, p);
            return (void*)p;
        }
#endif
        case BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ:
        {
            bam_register_keypad_handler_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_register_keypad_handler_req_struct);
            (void)bam_cvt_register_keypad_handler(&cvt_obj, p);
            return (void*)p;
        }

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_NOTIFY_SCREEN_INFO_REQ:
        {
            bam_notify_screen_info_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_notify_screen_info_req_struct);
            (void)bam_cvt_notify_screen_info(&cvt_obj, p);
            return (void*)p;
        }

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
        case BAM_SIG_SELECT_FILE_RSP:
        {
            bam_select_file_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_select_file_rsp_struct);
            (void)bam_cvt_select_file_rsp(&cvt_obj, p);
            return (void*)p;
        }
#endif

        case BAM_SIG_WTAI_TEL_RSP:
        {
            bam_wtai_tel_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_wtai_tel_rsp_struct);
            (void)bam_cvt_wtai_tel_rsp(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_WTAI_PB_RSP:
        {
            bam_wtai_pb_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_wtai_pb_rsp_struct);
            (void)bam_cvt_wtai_pb_rsp(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_URI_REQUEST_RSP:
        {
            bam_uri_request_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_uri_request_rsp_struct);
            (void)bam_cvt_uri_request_rsp(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_WAIT_USER_ACTION_IND:
        {
            bam_wait_user_action_ind_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_wait_user_action_ind_struct);
            (void)bam_cvt_user_action_ind(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_WAIT_USER_ACTION_RSP:
        {
            bam_wait_user_action_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_wait_user_action_rsp_struct);
            (void)bam_cvt_user_action_rsp(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_OBJECT_ACTION_REQ:
        {
            bam_object_action_req_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_object_action_req_struct);
            (void)bam_cvt_object_action(&cvt_obj, p);
            return (void*)p;
        }

        case BAM_SIG_SHOW_AUTH_DIALOG_RSP:
        {
            bam_show_auth_dialog_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_show_auth_dialog_rsp_struct);
            (void)bam_cvt_show_auth_dialog_rsp(&cvt_obj, p);
            return (void*)p;
        }
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE:
        {
            bam_delete_offline_page_rsp_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_delete_offline_page_rsp_struct);
            (void)bam_cvt_delete_offline_page_rsp(&cvt_obj, p);
            return (void*)p;
        }
#endif
        case BAM_SIG_EM_SETTING_CHANGED_IND:
        {
            bam_em_setting_changed_ind_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_em_setting_changed_ind_struct);
            (void)bam_cvt_em_setting_changed_ind(&cvt_obj, p);
            return (void*)p;
        }
        case BAM_SIG_CLOSE_CONNECTION_BY_NETID:
        {
            bam_close_connection_by_netid_struct *p;

            p = MSF_MEM_ALLOCTYPE(module, bam_close_connection_by_netid_struct);
            (void)bam_cvt_close_connection_by_netid(&cvt_obj, p);
            return (void*)p;
        }
    }

    return NULL;
}

#endif /* MSF_CVT_MOD */

#ifdef MSF_CVT_MOD
/*****************************************************************************
 * FUNCTION
 *  bam_destruct
 * DESCRIPTION
 *  Released a signal structure to a signal owned by this module.
 *  Every module that defines external signals must have this function.
 *  This function should not be called directly by another module.
 * PARAMETERS
 *  module      [IN]
 *  signal      [IN]
 *  p           [?]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
    {
        return;
    }

    msf_dcvt_init(&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);

    switch (signal)
    {
        case BAM_SIG_CREATE_INSTANCE_REQ:
            (void)bam_cvt_create_instance(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_INSTANCE_REQ:
            (void)bam_cvt_delete_instance(&cvt_obj, p);
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_LOAD_URL_REQ:
            (void)bam_cvt_load_url(&cvt_obj, p);
            break;

        case BAM_SIG_LOAD_DATA_REQ:
            (void)bam_cvt_load_data(&cvt_obj, p);
            break;

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
        case BAM_SIG_ACTIVATE_DO_ELEMENT_REQ:
            (void)bam_cvt_activate_do_element(&cvt_obj, p);
            break;
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

        case BAM_SIG_MOVE_REQ:
            (void)bam_cvt_move(&cvt_obj, p);
            break;

        case BAM_SIG_RELOAD_REQ:
            (void)bam_cvt_reload(&cvt_obj, p);
            break;

        case BAM_SIG_STOP_REQ:
            (void)bam_cvt_stop(&cvt_obj, p);
            break;

        case BAM_SIG_NAVIGATION_CHANGE_REQ:
            (void)bam_cvt_navigation_change(&cvt_obj, p);
            break;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_SAVE_PAGE_REQ:
            (void)bam_cvt_save_page(&cvt_obj, p);
            break;

        case BAM_SIG_GET_SAVED_PAGE_REQ:
            (void)bam_cvt_get_saved_page(&cvt_obj, p);
            break;

        case BAM_SIG_LOAD_SAVED_PAGE_REQ:
            (void)bam_cvt_load_saved_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_SAVED_PAGE_REQ:
            (void)bam_cvt_delete_saved_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_N_SAVED_PAGE_REQ:
            (void)bam_cvt_delete_n_saved_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ:
            (void)bam_cvt_delete_all_saved_pages(&cvt_obj, p);
            break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ:
            (void)bam_cvt_get_saved_pages_list_start(&cvt_obj, p);
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ:
            (void)bam_cvt_get_saved_pages_list_continue(&cvt_obj, p);
            break;

        case BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ:
            (void)bam_cvt_get_saved_pages_list_end(&cvt_obj, p);
            break;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        /*
         * case BAM_SIG_NAVIGATE_TO_HOTSPOT_REQ:
         * (void) bam_cvt_navigate_to_hotspot (&cvt_obj, p);
         * break;
         */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
        case BAM_SIG_CHANGE_SETTING_VALUE_REQ:
            (void)bam_cvt_change_setting_value(&cvt_obj, p);
            break;
//#endif



#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
        case BAM_SIG_WMLS_CREATE_DIALOGUE_RSP:
             (void)bam_cvt_wmls_create_dialogue_rsp(&cvt_obj, p);
            break;
#endif
        case BAM_SIG_SET_PROFILE_REQ:
            (void)bam_cvt_set_profile(&cvt_obj, p);
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ:
            (void)bam_cvt_get_recent_pages_list_start(&cvt_obj, p);
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ:
            (void)bam_cvt_get_recent_pages_list_continue(&cvt_obj, p);
            break;

        case BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ:
            (void)bam_cvt_get_recent_pages_list_end(&cvt_obj, p);
            break;

        case BAM_SIG_GET_RECENT_PAGE_REQ:
            (void)bam_cvt_get_recent_page(&cvt_obj, p);
            break;

        case BAM_SIG_LOAD_RECENT_PAGE_REQ:
            (void)bam_cvt_load_recent_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_RECENT_PAGE_REQ:
            (void)bam_cvt_delete_recent_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_N_RECENT_PAGE_REQ:
            (void)bam_cvt_delete_n_recent_page(&cvt_obj, p);
            break;

        case BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ:
            (void)bam_cvt_delete_all_recent_pages(&cvt_obj, p);
            break;

        case BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ:
            (void)bam_cvt_register_keypad_handler(&cvt_obj, p);
            break;
#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        case BAM_SIG_NOTIFY_SCREEN_INFO_REQ:
            (void)bam_cvt_notify_screen_info(&cvt_obj, p);
            break;

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
        case BAM_SIG_SELECT_FILE_RSP:
            (void)bam_cvt_select_file_rsp(&cvt_obj, p);
            break;
#endif

        case BAM_SIG_WTAI_TEL_RSP:
            (void)bam_cvt_wtai_tel_rsp(&cvt_obj, p);
            break;

        case BAM_SIG_WTAI_PB_RSP:
            (void)bam_cvt_wtai_pb_rsp(&cvt_obj, p);
            break;

        case BAM_SIG_URI_REQUEST_RSP:
            (void)bam_cvt_uri_request_rsp(&cvt_obj, p);
            break;

        case BAM_SIG_WAIT_USER_ACTION_IND:
            (void)bam_cvt_user_action_ind(&cvt_obj, p);
            break;

        case BAM_SIG_WAIT_USER_ACTION_RSP:
            (void)bam_cvt_user_action_rsp(&cvt_obj, p);
            break;

        case BAM_SIG_OBJECT_ACTION_REQ:
            (void)bam_cvt_object_action(&cvt_obj, p);
            break;

        case BAM_SIG_SHOW_AUTH_DIALOG_RSP:
            (void)bam_cvt_show_auth_dialog_rsp(&cvt_obj, p);
            break;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
        case BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE:
            (void)bam_cvt_delete_offline_page_rsp(&cvt_obj, p);
            break;
#endif
        case BAM_SIG_EM_SETTING_CHANGED_IND:
            (void)bam_cvt_em_setting_changed_ind(&cvt_obj, p);
            break;
        case BAM_SIG_CLOSE_CONNECTION_BY_NETID:
            (void)bam_cvt_close_connection_by_netid(&cvt_obj, p);
            break;
    }

    MSF_MEM_FREE(module, p);
}
#endif  /* MSF_CVT_MOD */
/* For STK */


/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_security_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
int bam_get_brs_security_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_sif_get_brs_security_id();
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
int bam_get_brs_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_sif_get_brs_id();
}

/* For WPS */


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* For OWL */


/*****************************************************************************
 * FUNCTION
 *  bam_wait_user_action_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  enable_positive_sk      [IN]
 *  positive_label          [IN]
 *  enable_negative_sk      [IN]
 *  negative_label          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
bam_wait_user_action_ind(
    int enable_positive_sk,
    const char *positive_label,
    int positive_label_len,
    int enable_negative_sk,
    const char *negative_label,
    int negative_label_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bam_wait_user_action_ind_struct *param;
 //   msf_dcvt_t cvt_obj;
 //	  MSF_UINT16 length;
 //   void *signal_buffer, *user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param= MSF_MEM_ALLOC(MSF_MODID_BAM, sizeof(bam_wait_user_action_ind_struct));
    memset(param, 0, sizeof(bam_wait_user_action_ind_struct));

	param->instance_id = (MSF_INT32) bam_sif_get_brs_id();
    param->enable_negative_sk = (MSF_BOOL)enable_positive_sk;
    param->enable_negative_sk = (MSF_BOOL)enable_negative_sk;
    param->positive_label_len = (MSF_INT32)positive_label_len;
    param->negative_label_len = (MSF_INT32)negative_label_len;
    param->positive_label = msf_cmmn_strdup (MSF_MODID_BAM,positive_label);
    param->negative_label= (msf_cmmn_strdup (MSF_MODID_BAM,negative_label));

	MSF_SIGNAL_SEND(MSF_MODID_BAM,MSF_MODID_BAM,BAM_SIG_WAIT_USER_ACTION_IND,param);

  //  BAM_SEND_SIGNAL(bam_cvt_user_action_ind, BAM_SIG_WAIT_USER_ACTION_IND, MSF_MODID_BAM, MSF_MODID_BAM);
}


/*****************************************************************************
 * FUNCTION
 *  bam_brs_is_idle
 * DESCRIPTION
 *  Indicate whether BRS is ready and idle
 * PARAMETERS
 *  void
 * RETURNS
 *  1 for idle, otherwise 0.
 *****************************************************************************/
int bam_brs_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (int)bam_sif_brs_is_idle();
}

/*****************************************************************************
 * FUNCTION
 *  bam_get_brs_paintbox
 * DESCRIPTION
 *  This function is used to get the paintbox previously returned in
 *  a request to instantiate the BRS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long bam_get_brs_paintbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (unsigned long)bam_sif_get_brs_paintbox();
}


/* For BrowserAPP */


/*****************************************************************************
 * FUNCTION
 *  bam_register_keypad_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_register_keypad_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    widget_paintboxV2_register_keys();
}


/*****************************************************************************
 * FUNCTION
 *  bam_suspend_browser_rendering
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_suspend_browser_rendering(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtResumeRendering(0);
}


/*****************************************************************************
 * FUNCTION
 *  bam_resume_browser_rendering
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_resume_browser_rendering(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtResumeRendering(1);
    
}


/*****************************************************************************
 * FUNCTION
 *  bam_notify_screen_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  w                       [IN]        
 *  h                       [IN]        
 *  category_lyr_a_hndl     [IN]        
 *  category_lyr_b_hndl     [IN]        
 *  is_refresh              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void bam_notify_screen_info(
        U32 x,
        U32 y,
        U32 w,
        U32 h,
        int category_lyr_a_hndl,
        int category_lyr_b_hndl,
        int is_refresh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify OWL of the current category screen information, including layer
       handle used and what area to draw. */
   HDIa_widgetDeviceSetProperties(
								x,
								y,
								w,
								h,
								category_lyr_a_hndl,
								category_lyr_b_hndl);

}


void bam_widget_key_ind_handler(void)
{
    widget_key_ind_handler(KEY_SEND, KEY_EVENT_UP);
    bam_main_set_activate_browser_input_status(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  bam_activate_browser_input
 * DESCRIPTION
 *  Notify OWL to handle form/link elements.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_activate_browser_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(bam_main_get_activate_browser_input_status() == FALSE)
    {
        widget_execute_WAP_p((func_ptr)bam_widget_key_ind_handler, (void*)NULL, KAL_FALSE);
        bam_main_set_activate_browser_input_status(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_get_bits
 * DESCRIPTION
 *
 * PARAMETERS
 *  data        [?]
 *  numbits     [IN]
 * RETURNS
 *
 *****************************************************************************/
unsigned int bam_get_bits(char *data, int numbits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (unsigned int)bam_cmn_get_bits((MSF_INT8*) data, numbits);
}



typedef enum
{
#ifdef __MMI_CHSET_CEURO_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN2,
#endif
#ifdef __MMI_CHSET_SEURO_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN3,
#endif
#ifdef __MMI_CHSET_BALTIC_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN4,
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#ifdef __MMI_CHSET_ARABIC_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_ARABIC,
#endif
#ifdef __MMI_CHSET_GREEK_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_GREEK,
#endif
#ifdef __MMI_CHSET_HEBREW_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_HEBREW,
#endif
#ifdef __MMI_CHSET_TURKISH_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN5,
#endif
#ifdef __MMI_CHSET_NORDIC_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN6,
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#ifdef __MMI_CHSET_EUCKR_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_EUC_KR,
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#ifdef __MMI_CHSET_LATIN_ISO__
	BAM_ADDITIONAL_CHARSET_ENUM_LATIN9,
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#ifdef __MMI_CHSET_GB18030__
	BAM_ADDITIONAL_CHARSET_ENUM_GB18030,
#endif
#ifdef __MMI_CHSET_GB2312__
	BAM_ADDITIONAL_CHARSET_ENUM_GB2312,
#endif
#ifdef __MMI_CHSET_BIG5__
	BAM_ADDITIONAL_CHARSET_ENUM_BIG5,
#endif
#ifdef __MMI_CHSET_HKSCS__
	BAM_ADDITIONAL_CHARSET_ENUM_HKSCS,
#endif
#if 0 /* Not support */
/* under construction !*/
#endif
#ifdef __MMI_CHSET_WESTERN_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN1252,
#endif
#ifdef __MMI_CHSET_GREEK_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN1253,
#endif
#ifdef __MMI_CHSET_TURKISH_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN1254,
#endif
#ifdef __MMI_CHSET_HEBREW_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN1255,
#endif
#ifdef __MMI_CHSET_ARABIC_WIN__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN1256,
#endif
#ifdef __MMI_CHSET_THAI_WINDOWS__
	BAM_ADDITIONAL_CHARSET_ENUM_WIN874,
#endif
	BAM_ADDITIONAL_CHARSET_ENUM_NUM
} bam_additional_charset_enum;


#if 0
/* under construction !*/
#ifdef __MMI_CHSET_CEURO_ISO__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_SEURO_ISO__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_BALTIC_ISO__ 
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_ARABIC_ISO__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_GREEK_ISO__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_HEBREW_ISO__ 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CHSET_NORDIC_ISO__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_EUCKR_WIN__ 
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#if 0 /* Not support */ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_LATIN_ISO__ 
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#if 0 /* Not support */ 
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_BIG5__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_HKSCS__ 
/* under construction !*/
#endif 
#if 0 /* Not support */
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_WESTERN_WIN__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_GREEK_WIN__ 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CHSET_HEBREW_WIN__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_ARABIC_WIN__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_THAI_WINDOWS__ 
/* under construction !*/
#endif 
#ifdef __MMI_CHSET_GB2312__ 
/* under construction !*/
#endif  
#ifdef __MMI_CHSET_GB18030__ 
/* under construction !*/
#endif  
/* under construction !*/
/* under construction !*/
#endif


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#if 0   /* This function should be replaced with the URL validation function in MMI */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __SUPPORT_INFUSIO__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SUPPORT_INFUSIO__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  bam_get_net_acc_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
int bam_get_net_acc_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_registry_get_net_acc_id();
}

/* For Framework */




/* For BRS plugin */

unsigned char bam_get_num_of_registered_schemes(void)
{
#ifdef __MMI_URI_AGENT__
	return (unsigned char)srv_uriagent_get_num_of_registered_schemes();
#else
	return 0;
#endif
}

const char *bam_get_registered_scheme_by_index(unsigned char index)
{
#ifdef __MMI_URI_AGENT__
	return srv_uriagent_get_registered_scheme_by_index((unsigned char)index);
#else
	return NULL;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  bam_get_no_continue_iterations
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
#ifdef MTK_TMP_PATCH /* TR34746, TR34686: Loading large web page and MT call comes */

#define BAM_BRW_TASK_MSG_SAFE_BUFFER	8

int bam_is_brw_task_busy(void)
{
#ifdef __MTK_TARGET__
	if ((bam_msg_get_num_of_msg_brw_task() + 8) > bam_msg_get_max_num_of_msg_brw_task())
	{
		return TRUE;
	}
#endif
	return FALSE;
}
 
//extern pBOOL IsBacklightOn(void);

int bam_get_no_continue_iterations(void)
{
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 || 
        srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 || 
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 || 
        bam_is_brw_task_busy())
	{
		/* Handset is in Busy state */
		return 1;
	}
	else if (srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == FALSE)
	{
		/* Handset is in idle state */
		return 300;
	}
	else
	{
		return 200;
	}
}

void bam_get_system_time_tick(unsigned int *ticks_ptr)
{
	kal_get_time((kal_uint32 *)ticks_ptr);
}

int bam_get_system_time_ticks_1_sec(void)
{
	return KAL_TICKS_1_SEC;
}

#endif /* MTK_TMP_PATCH */

/*****************************************************************************
 * FUNCTION
 *  bam_is_nav_mode_scrolling
 * DESCRIPTION
 *  Check whether the browser navigation mode is scrolling
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns 0 if it is not scrolling mode; otherwise, returns 1.
 *****************************************************************************/
int bam_is_nav_mode_scrolling(void)
{
    return (bam_registry_get_int(BAM_SETTING_ID_NAVIGATION) == bam_setting_val_nav_scroll);
}

#if defined(BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT) || defined(MSF_CFG_FILE_UPLOAD_SUPPORT)
void bam_received_transaction_status(void)
{
    bam_main_set_received_transaction_status(FALSE);
}
#endif

void
bam_registry_em_setting_changed_callback(applib_inet_option_enum opt, applib_inet_setting_struct *new_setting)
{
    BAMif_EmSettingChangedInd((MSF_UINT8) opt, (MSF_UINT32) new_setting->value_int, (char*) new_setting->value_str);
    widget_send_update_event_to_wap();
}


/*****************************************************************************
 * FUNCTION
 *  bam_url_escape_string
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
char* bam_url_escape_string(const char* s, wap_bam_alloc_func malloc_func)
{
    return msf_url_escape_string_for_browser(s, (msf_alloc_func)malloc_func);
}

#endif /*OBIGO_Q03C_BROWSER*/
int bam_wmls_dlg_support()
{
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
	return TRUE;
#else
	return FALSE;
#endif

}
/*****************************************************************************
 * FUNCTION
 *  bam_send_out_of_memory_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_send_out_of_memory_ind(void)
{
#ifdef OBIGO_Q03C_BROWSER
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_msg_out_of_memory_ind();
#endif
}


extern void brs_set_bearer_status(int status);
/*****************************************************************************
 * FUNCTION
 *  bam_reset_open_bearer_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_reset_open_bearer_status(void)
{
#ifdef OBIGO_Q03C_BROWSER
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    brs_set_bearer_status(0);
#endif
}


void BAMif_bearerOpenInd(MSF_INT32 instance_id)
{
#ifdef OBIGO_Q03C_BROWSER
    bam_msg_bearer_open_ind(instance_id);
#endif
}


int BAMif_fileUploadEnabled(void)
{
#ifdef OBIGO_Q03C_BROWSER
#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
    return 1;
#else
    return 0;
#endif
#else
    return 0;
#endif
}
