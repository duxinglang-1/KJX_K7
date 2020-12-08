#ifdef OBIGO_Q03C_BROWSER
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
 *   bam_hist.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code for managing the access history.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_hist.h
 *
 * This file contains code for managing the access history.
 *
 */

#ifndef _bam_hist_h

#define _bam_hist_h

#include "bam_cfg.h"
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT

#include "msf_int.h"

typedef void *bam_hist_select_list_h;
typedef void *bam_hist_element_h;

#define BAM_HIST_MIN_TIME_NO_LIMIT 0
#define BAM_HIST_MAX_TIME_NO_LIMIT 0xffffffffu

typedef enum
{
    BAM_HIST_SELECTION_ALL,
    BAM_HIST_SELECTION_HOST_TIME,
    BAM_HIST_SELECTION_SINGLE_HOST_TIME /* Only one element per host */
} bam_hist_selection_enum;

typedef enum
{
    BAM_HIST_SORT_TITLE,
    BAM_HIST_SORT_HOST,
    BAM_HIST_SORT_LAST,
    BAM_HIST_SORT_FREQUENT
} bam_hist_sort_enum;

typedef enum
{
    BAM_HIST_ERROR_OK,
    BAM_HIST_ERROR_NOT_FOUND,
    BAM_HIST_ERROR_FAIL
} bam_hist_error_enum;

/*
 * Initializes the access history functionality.
 */
extern void bam_hist_init(void);

/*
 * Terminates the access history functionality.
 *
 * Returns FALSE if delayed.
 */
extern void bam_hist_terminate(void);

/*
 * Adds an item to the access history.
 */
extern void bam_hist_add_item(const char *url, const char *title);

/*
 * Removes all items in the access history.
 */
extern void bam_hist_clear(void);

/*
 * Update history size to the value of the
 * registry key bam_registry_key_id_history.
 */
extern void bam_hist_resize(void);

extern int bam_hist_get_list_size(void);

extern bam_hist_select_list_h *bam_hist_select(
                                bam_hist_selection_enum select,
                                const char *host,
                                MSF_UINT32 min_time,
                                MSF_UINT32 max_time);

extern void bam_hist_clear_selection(bam_hist_select_list_h *select_list);

extern int bam_hist_get_select_list_size(bam_hist_select_list_h *select_list);

extern void bam_hist_sort_selection(bam_hist_select_list_h *select_list, bam_hist_sort_enum sort_method);

extern bam_hist_element_h *bam_hist_get_element(bam_hist_select_list_h *select_list, int index);

extern bam_hist_element_h *bam_hist_get_next_element(bam_hist_element_h *element);

extern char *bam_hist_get_element_title(bam_hist_element_h *element);

extern char *bam_hist_get_element_url(bam_hist_element_h *element);

/* NOTE: Use only for elements in a "single host" select list. I.e. created with
   BAM_HIST_SELECTION_SINGLE_HOST_TIME. */
extern char *bam_hist_get_element_host(bam_hist_element_h *element);

extern void bam_hist_delete_element(bam_hist_element_h *element);

extern void bam_hist_delete(char *host, MSF_UINT32 min_time, MSF_UINT32 max_time);

extern MSF_BOOL bam_hist_date_exits(MSF_UINT32 min_time, MSF_UINT32 max_time);

extern void bam_hist_async_save_to_file(void);

typedef struct
{
    char *title;
    char *url;
    MSF_UINT32 url_hash;
    MSF_UINT16 hits;
    MSF_UINT32 timestamp;
} bam_hist_ui_item_struct;

extern void bam_hist_ui_create_list(bam_hist_sort_enum sort_method);

extern void bam_hist_ui_destroy_list(void);

extern int bam_hist_ui_get_sel_list_size(void);

extern bam_hist_error_enum bam_hist_ui_pack_list_item_from_index(
                            void *p,
                            int aval_size,
                            int start_idx,
                            int *packed_items);

extern void bam_hist_ui_handle_get_recent_page_req(MSF_UINT32 index);

extern void bam_hist_ui_handle_load_recent_page_req(MSF_UINT32 index);

extern void bam_hist_ui_handle_delete_recent_page_req(MSF_UINT32 index);

extern void bam_hist_ui_handle_delete_n_recent_page_req(MSF_UINT32 *index_array,int count);

extern void bam_hist_ui_handle_delete_all_recent_page_req(void);

#endif
#endif /* _bam_hist_h */ 

#endif /*OBIGO_Q03C_BROWSER*/
