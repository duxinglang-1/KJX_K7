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
 *   bam_offline.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Handle stored pages.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_offline.c
 *
 * Handle stored pages.
 *
 */

#include "bam_cfg.h"
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#include "bam_offline.h"
#endif
#include "bam_cmn.h"
#include "bam_msg.h"
#include "bam_pipe.h"
#include "bam_sif.h"
#include "bam_win.h"
#include "bam_struct.h"
#include "bam_if.h"
#include "bam_file.h"
#include "bam_req.h"
#include "bam_main.h"

#include "msf_int.h"
#include "msf_lib.h" 
#include "msf_file.h"
#include "msf_core.h"
#include "msf_cmmn.h"
#include "msf_wid.h"
#ifdef WAP_SUPPORT
#include "widget_extension.h"
#endif

/************************************************************
 * Constants
 ************************************************************/

/************************************************************
 * Type definitions
 ************************************************************/

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef BAM_CFG_STORE_PAGE_BUSY_DIALOG
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* BAM_CFG_STORE_PAGE_BUSY_DIALOG */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef BAM_CFG_STORE_PAGE_BUSY_DIALOG
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* BAM_CFG_STORE_PAGE_BUSY_DIALOG */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/*****************************************************************************
 * Local Defines
 *****************************************************************************/
#define BAM_OFFLINE_MAX_FILE_SIZE   31000 
#define BAM_OFFLINE_INITIAL_SIZE    3000
#define BAM_OFFLINE_DEFRAG_LIMIT    5000
#define BAM_OFFLINE_SIZE_INCREMENT  2000
#define BAM_OFFLINE_PAGE_FILE_PATH   "/bam/offline.dat"
#define BAM_MAX_NBR_OFFLINE_PAGES 10

#define BAM_OFFLINE_HEADERS_LENGTH   7   /*5 = 1 byte title length + 2 bytes url 
                                           length + 4 bytes sort index*/

/*****************************************************************************
 * Local Types
 *****************************************************************************/

typedef struct {
	MsfStringHandle	title;
	char	*url;
} bam_offline_addr_t;

typedef struct {
  MSF_UINT32   sort_idx;   /*Created time to be used as sorting value*/
  char *title;
  char *url;
}bam_offline_file_item_t;

typedef struct bam_offline_item_to_delete{
    char  *url;
    struct bam_offline_item_to_delete *next;
}bam_offline_item_to_delete_t;

/*****************************************************************************
 * Function prototypes
 *****************************************************************************/

static void 
bam_offline_load_ofln_response (void *handle, unsigned char* block, int size);

extern pBOOL mmi_usb_is_in_mass_storage_mode(void);

/*****************************************************************************
 * Variables
 *****************************************************************************/

static bam_offline_state_t    bam_offline_state;
static bam_offline_item_t     *bam_offline_list;              /*-List of offline page titles*/ 
static bam_offline_item_to_delete_t    *bam_offline_list_toDelete;     /*-List of offline pages to be deleted*/ 
static int                 bam_offline_n_items;           /*-Number of offlien pages    */                
static void                *bam_offline_file_handle = NULL;
static int                 bam_offline_mode = 0;
/* MAUI_01071590 starts */
static int                 bam_offline_num_of_del_req = 0;
/* MAUI_01071590 End */
static bam_offline_addr_t     *bam_offline_addr;
static bam_delete_n_saved_page_req_struct bam_offline_copy_delete_saved_page_req;
static int bam_offline_delete_request_send_count = 0;
static MSF_INT16 bam_offline_page_delete_count = 0;
static MSF_INT32 bam_offline_page_delete_count_total;
                                              
/*
 * The following variables are used to identify the "add offline page" and 
 * "manage offline page" menu items when an item in the menu have been selected
 */
                 
/*****************************************************************************
 * Functions
 *****************************************************************************/

/*
 *  Adds a offline page item to list
 *
 *  Retruns 1 if ok, else 0
 *
 */
static int 
bam_offline_add_ofln_item (MSF_UINT32 sort_idx, int idx, MSF_INT32 title, char* url)
{
  bam_offline_item_t *ofln_item;
  bam_offline_item_t *p;
  bam_offline_item_t *prev;

  ofln_item = BAM_ALLOCTYPE(bam_offline_item_t);

  if(ofln_item == NULL)
    return 0;

  ofln_item->sort_idx = sort_idx;
  ofln_item->idx = idx;
  ofln_item->title = title;
  ofln_item->url = url;
  ofln_item->next = NULL;

  /*Increase number of offline pages*/
  bam_offline_n_items++;

  p = bam_offline_list;
  prev = bam_offline_list;

  if(p != NULL)
  {
    while (p != NULL)
    {
      if(p->sort_idx < ofln_item->sort_idx)
      {
        prev = p;
        p = p->next;
        continue;
      }

      if (p == bam_offline_list)
      {
        ofln_item->next = bam_offline_list;
        bam_offline_list  = ofln_item;
      }
      else
      {
        prev->next = ofln_item;
        ofln_item->next = p;
      }
      return 1;
    }
    prev->next = ofln_item;
  }
  else
  {
    bam_offline_list = ofln_item;
  }

  return 1;
}

static bam_offline_item_t *
bam_offline_remove_item(int idx)
{
  bam_offline_item_t *remove;
  bam_offline_item_t *previous;
  int i = 0;

  if(bam_offline_list == NULL)
    return NULL; 
  
  /*Decrease number of offline pages*/
  bam_offline_n_items--;

  remove   = bam_offline_list;
  previous = bam_offline_list;
 
  while (remove != NULL)
  {
    if (i++ == idx)
    {
      if (remove == bam_offline_list)
        bam_offline_list = remove->next;
      else
        previous->next = remove->next;

      return remove;
    }
    previous = remove;
    remove = remove->next;
  }

  return NULL;
}

static bam_offline_item_t *
bam_offline_get_item (int idx)
{  
  int i = 0;
  bam_offline_item_t *ofln_item;

  ofln_item = bam_offline_list;
  
  while ((i++ < idx) && (ofln_item != NULL))
  {
    ofln_item = ofln_item->next;
  }

  return ofln_item;
}

static bam_offline_item_t *
bam_offline_search_item_by_url (char* url)
{  
  bam_offline_item_t *ofln_item;

  ofln_item = bam_offline_list;
  
  while (ofln_item != NULL)
  {
    if(strcmp(ofln_item->url, url) == 0)
      return ofln_item;
    ofln_item = ofln_item->next;
  }

  return NULL;
}

static void
bam_offline_destroy_list()
{
  bam_offline_item_t *remove;

  remove = bam_offline_list;
  
  while (remove != NULL)
  {
    bam_offline_list = remove->next;
    MSF_WIDGET_RELEASE  (remove->title);
    BAM_FREE (remove->url);
    BAM_FREE (remove);
    remove = bam_offline_list;
  }
  
  bam_offline_n_items = 0;

}
/* offlien page url/title file format
 *
 * All offline pages are saved in one file. The file name is as defined by BAM_OFFLINE_FILE_NAME. 
 * The offlien pages are saved as a sequence of bytes were each offline page is saved as follows:
 *
 * Field                Bytes       Comment
 *
 * Sort Index           4           Time of creation to be used as sort index
 * Length of title      1           BYTE (unsigned char)
 * Title                0 - 0xFF    Lenth as specified by the above element 
 * Length of url        2           INT16 (short). Most significant byte first
 * Url                  0 - 0x7FFF  Lenth as specified by the above element
 *
 * Note: Title and url is not null terminated in the file.
 *
 * At start-up, BAM_OFFLINE_BUFFER_SIZE bytes are read from file and all titles + the possition 
 * of the corresponding url is read into a list. This is repeated untill all offline pages have
 * been read. The bam module will not call MSF_MODULE_IS_ACTIVE untill this is complete.
 *
 * 
 */
static unsigned char*
bam_offline_create_buffer(MSF_UINT32 sort_idx, char *title, char* url, int *buf_len)
{
  unsigned char* buffer;
  int   l_title;
  int   l_url;

  l_title = strlen (title);
  l_url   = strlen (url);
  
  *buf_len = l_title + l_url + BAM_OFFLINE_HEADERS_LENGTH;

  buffer = BAM_ALLOC (*buf_len); 

  buffer[0] = (unsigned char)(sort_idx >> 24);
  buffer[1] = (unsigned char)((sort_idx & 0x00FF0000) >> 16);
  buffer[2] = (unsigned char)((sort_idx & 0x0000FF00) >> 8);
  buffer[3] = (unsigned char)(sort_idx  & 0x000000FF);

  buffer[4] = (unsigned char)l_title;

  memcpy (&buffer[5], title, l_title);

  buffer[l_title + 5] = (unsigned char)(l_url >> 8);     /*Most significant byte first*/
  buffer[l_title + 6] = (unsigned char)(l_url & 0xFF);

  memcpy (&buffer[l_title + 7], url, l_url);

  return buffer;

}

static int 
bam_offline_parse_ofln_item (unsigned char *buffer, int size, bam_offline_file_item_t* p)
{
  int   idx = 0;
  int   title_len;
  int   url_len;
 
  if (size < BAM_OFFLINE_HEADERS_LENGTH)
    return -1;

  p->sort_idx =  (buffer[idx] << 24);
  idx++;
  p->sort_idx += (buffer[idx] << 16);
  idx++;
  p->sort_idx += (buffer[idx] << 8);
  idx++;
  p->sort_idx += (buffer[idx]);
  idx++;

  /*Get Title length*/
  title_len =  buffer[idx++];
  
  /*Check that title length is not longer than buffer*/
  if((title_len < 0) || (title_len > (size - idx)))
    return -1;
  
  /*Copy title*/
  p->title = BAM_ALLOC(title_len + 1);    
  memcpy(p->title, &buffer[idx], title_len);   
  p->title[title_len] = '\0'; 
  
  /*Step idx*/
  idx = idx + title_len;
  
  /*Get URL length*/
  url_len  = (buffer[idx++] << 8);
  url_len +=  buffer[idx++];
  
  /*Check that title length is not longer than buffer*/
  if((url_len < 0) || (url_len > (size - idx)))
  {
    BAM_FREE(p->title);
    return -1; /*tile length, title, and url length*/
  }
  
  /*Copy url*/
  p->url = BAM_ALLOC(url_len + 1);    
  memcpy(p->url, &buffer[idx], url_len);   
  p->url[url_len] = '\0'; 
  
  idx += url_len;
  
  return idx;

}


static void 
bam_offline_delete_ofln (int idx, bam_file_op_callback_t callback)
{
  bam_offline_item_t *item;

  item = bam_offline_remove_item (idx);

  if(item == NULL)
    return;

  bam_offline_state = BAM_OFFLINE_STATE_DELETE_REQUEST;
  bam_file_read_block (bam_offline_file_handle, item->idx, bam_offline_load_ofln_response);

  bam_file_delete_block (bam_offline_file_handle, item->idx , callback);

  MSF_WIDGET_RELEASE (item->title);
  BAM_FREE (item->url);
  BAM_FREE (item);

}


static void 
bam_offline_load_ofln_response (void *handle, unsigned char* block, int size)
{
  bam_offline_file_item_t p;

  handle = handle;
  
  bam_offline_parse_ofln_item (block, size, &p);
  
  if (bam_offline_state == BAM_OFFLINE_STATE_LOAD_REQUEST)
  {
    bam_send_request(p.url);    
    /* reset bam_offline_state to NULL until end of transaction */
  }
  else if(bam_offline_state == BAM_OFFLINE_STATE_DELETE_REQUEST)
  {
    if (bam_sif_get_brs_status() != BAM_SIF_BRS_READY)
    {
        bam_offline_item_to_delete_t *deleteItem;
        bam_sif_start_brs ();

        deleteItem = BAM_ALLOCTYPE(bam_offline_item_to_delete_t);
        deleteItem->url = msf_cmmn_strdup(MSF_MODID_BAM, p.url);
        deleteItem->next = bam_offline_list_toDelete;
        bam_offline_list_toDelete = deleteItem;
        return;
    }
/* MAUI_01071590 starts */
    bam_offline_num_of_del_req++;
/* MAUI_01071590 Ends */
    #ifdef MTK_TMP_PATCH    
    BRSif_deleteOfflinePage(MSF_MODID_BAM, bam_sif_get_brs_id(), p.url);
    #else
    BRSif_deleteOfflinePage(MSF_MODID_BAM, p.url);
    #endif
    bam_offline_state = BAM_OFFLINE_STATE_NULL;
  }  

  BAM_FREE (p.url);
  BAM_FREE (p.title);

  BAM_FREE (block);
}

void 
bam_offline_load_selected_ofln(int idx, bam_offline_state_t state)
{
  bam_offline_item_t *ofln_item;

  ofln_item = bam_offline_get_item(idx);

  if (ofln_item == NULL)
    return;

  bam_offline_state = state;

  bam_file_read_block (bam_offline_file_handle, ofln_item->idx, bam_offline_load_ofln_response);
}


/*
 * This function initializes the offline page list stored in ram.
 * 
 *
 * Parameters:
 *
 * file_handle    : handle to file opened for reading
 *
 * Return a positive value when finished.
 */

static void 
bam_offline_initialize_offline_pages (int idx, int eof, void* block, int size)
{
  bam_offline_file_item_t p;
  MsfStringHandle title;

  if (eof == 0)
  {
    if (bam_offline_parse_ofln_item ((unsigned char *)block, size, &p) < 0)
      return;

    if ((p.title != NULL) && (*p.title != '\0'))
    {
      title = BAM_STRCONV (p.title);
    }
    else
    {
      title = BAM_STRCONV (p.url);
    }

    bam_offline_add_ofln_item (p.sort_idx, idx, title, p.url);

    BAM_FREE (p.title);
  }
}

void
bam_offline_free_addr(void)
{
  MSF_WIDGET_RELEASE (bam_offline_addr->title);
  bam_offline_addr->title = 0;

  BAM_FREE (bam_offline_addr->url);
  bam_offline_addr->url = NULL;

  BAM_FREE(bam_offline_addr);
  bam_offline_addr = NULL;
}

void bam_offline_init_addr(char *title, char *url)
{
  if(bam_offline_addr != NULL)
      bam_offline_free_addr();
  bam_offline_addr = BAM_ALLOCTYPE(bam_offline_addr_t);
  bam_offline_addr->title = BAM_STRCONV (title);/*OK*/

  bam_offline_addr->url   = BAM_ALLOC (strlen(BAM_CMN_HNV(url)) + 1);
  strcpy(bam_offline_addr->url, BAM_CMN_HNV(url));
}

/*
 * This function initializes the offline page manager and reads the 
 * saved offine pages url from file.
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bam_offline_init (void)
{

  if(bam_offline_file_handle)
      return;
  bam_offline_list = NULL;
  bam_offline_state = BAM_OFFLINE_STATE_NULL;
  bam_offline_n_items = 0;  
  bam_offline_list_toDelete = NULL;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        
  bam_file_init (BAM_OFFLINE_PAGE_FILE_PATH, 
                 &bam_offline_file_handle, 
                 BAM_OFFLINE_MAX_FILE_SIZE, 
                 BAM_OFFLINE_INITIAL_SIZE, 
                 BAM_OFFLINE_DEFRAG_LIMIT, 
                 BAM_OFFLINE_SIZE_INCREMENT,
                 bam_offline_initialize_offline_pages);

}

/*
 * Thsi function terminates the offline page manager and releases all 
 * resources allocated
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void 
bam_offline_destroy(void)
{
  if(bam_offline_file_handle == NULL)
      return;
  bam_offline_destroy_list();
  bam_file_close (bam_offline_file_handle);
  bam_offline_file_handle = NULL;
  if(bam_offline_addr != NULL)
      bam_offline_free_addr();

}


/*
 * This function adds a new offline page to the list of offline page.
 *
 * PARAMETERS
 *
 * title     : Title of new offline
 * url       : Url of new offline
 *
 * RETURN    : 1 if successful, else 0
 */
static int 
bam_offline_add_new_ofln (char* title, char* url)
{
  unsigned char *buffer;
  char *label;
  int   buf_len;
  MSF_UINT32 sort_idx;
  int  idx;
  MsfStringHandle str;

  if((title == NULL) || (url == NULL))
    return 0;

  /*Not both the title and url can be null att the same time*/
  if((*title == '\0') && (*url == '\0'))
    return 0;  
      
  sort_idx = MSF_TIME_GET_CURRENT();
  buffer = bam_offline_create_buffer(sort_idx, title, url, &buf_len);
   
  /*Update menu*/
  if (*title != '\0')
  {
    label = title;
  }
  else
  {
    label = url;
  }

  str = BAM_STRCONV (label);/*This handle is stored in list and removed later*/

 
  /*save offline page*/
  idx = bam_file_write_block (bam_offline_file_handle, 
                              buffer, 
                              buf_len, 
                              NULL);
  BAM_FREE (buffer);
  
  /*Add to ram list*/
  bam_offline_add_ofln_item (sort_idx, idx, str, url);
    

  return 1;
}

/******** SELECT OFFLINE MANAGE MENU FUNCTIONS ********/


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


/******** END OFFLINE PAGE MAIN MENU FUNCTIONS ********/

/*
 * This function is used to set the offile mode
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bam_offline_set_offline_mode(MSF_BOOL b)
{
  if(b == TRUE)
  {
    BRSif_setOfflineMode(MSF_MODID_BAM, bam_sif_get_brs_id(), TRUE);
    bam_offline_mode = 1;
  }
  else 
  {
    BRSif_setOfflineMode(MSF_MODID_BAM, bam_sif_get_brs_id(), FALSE);
    bam_offline_mode = 0;
  }
}

#ifdef MTK_TMP_PATCH
/*
 * This function is used for offline backword navigation, 
 * to set the BAM offline mode from BRS
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bam_offline_set_offline_mode_from_brs(MSF_BOOL b)
{
  if(b == TRUE)
  {
      bam_offline_mode = 1;
  }
  else
  {
      bam_offline_mode = 0;
  }
}
#endif

/*
 * This function return if the offline mode is true or not
 *
 * PARAMETERS
 *
 * RETURN    : void
 */

int 
bam_offline_get_offline_mode(void)
{
  return bam_offline_mode;
}

/*
 * This function is used to reset the offile state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bam_offline_reset_offline_state(void)
{
  bam_offline_state = BAM_OFFLINE_STATE_NULL;
}

/*
 * This function return if it is in loading offline page state
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
int
bam_offline_loading_offline_page(void)
{
  return (bam_offline_state == BAM_OFFLINE_STATE_LOAD_REQUEST);
}

void
/* MAUI_02454764 starts */
/* bam_offline_saving_offline_done(MSF_BOOL success) */
bam_offline_saving_offline_done(int result)
/* MAUI_02454764 ends */
{
  char *s, *t;
  int  len;

/*  if(success == TRUE && bam_offline_state == BAM_OFFLINE_STATE_SAVE_REQUEST) MAUI_02454764 */
  if(result == BRS_STATUS_OFFLINE_PAGE_SAVE_OK && bam_offline_state == BAM_OFFLINE_STATE_SAVE_REQUEST) /* MAUI_02454764 */
  {
    len = MSF_WIDGET_STRING_GET_LENGTH(bam_offline_addr->title, 1, MsfUtf8);
    s = BAM_ALLOC(len+1);
    MSF_WIDGET_STRING_GET_DATA (bam_offline_addr->title, s, MsfUtf8);
    t = BAM_ALLOC(strlen(bam_offline_addr->url)+1);
    strcpy(t, bam_offline_addr->url);

    bam_offline_add_new_ofln(s, t);    
    bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_OK, s, bam_offline_addr->url);
    BAM_FREE(s);
  }
/*  else if(success == TRUE && bam_offline_state == BAM_OFFLINE_STATE_UPDATE_REQUEST) MAUI_02454764 */
  else if(result == BRS_STATUS_OFFLINE_PAGE_SAVE_OK && bam_offline_state == BAM_OFFLINE_STATE_UPDATE_REQUEST) /* MAUI_02454764 */
  {
    len = MSF_WIDGET_STRING_GET_LENGTH(bam_offline_addr->title, 1, MsfUtf8);
    s = BAM_ALLOC(len+1);
    MSF_WIDGET_STRING_GET_DATA (bam_offline_addr->title, s, MsfUtf8);
    bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_OK, s, bam_offline_addr->url);
    BAM_FREE(s);
  }
  else
  {
/* MAUI_02454764 starts */
    if(result == BRS_STATUS_OFFLINE_PAGE_EXISTS)
    {
        bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_ERR_EXISTS, NULL, NULL);
    }
    else
/* MAUI_02454764 ends */
    bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_ERR_FAILED, NULL, NULL);
  }
  
  bam_offline_state = BAM_OFFLINE_STATE_NULL;
  bam_offline_free_addr();
}

/*
 * This function called when brs not found the offline page
 *
 * PARAMETERS
 *
 * RETURN    : void
 */
void
bam_offline_page_not_found(void *p)
{
#if 0
/* under construction !*/
#else
  bam_msg_error_ind(bam_sif_get_brs_id(), WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND);
#endif
}

int
bam_offline_page_has_page_to_delete(void)
{
    return (bam_offline_list_toDelete != NULL);
}

void
bam_offline_page_delete_pending_page(void)
{
    while (bam_offline_list_toDelete)
    {
        /* MAUI_01071590 starts */
        bam_offline_num_of_del_req++;
        /* MAUI_01071590 Ends */
        #ifdef MTK_TMP_PATCH        
        BRSif_deleteOfflinePage(MSF_MODID_BAM, bam_sif_get_brs_id(), bam_offline_list_toDelete->url);
        #else
        BRSif_deleteOfflinePage(MSF_MODID_BAM, bam_offline_list_toDelete->url);
        #endif
        bam_offline_list_toDelete = bam_offline_list_toDelete->next;
    }
}

/* MAUI_01071590 starts */
void bam_offline_delete_pending_page_start(bam_delete_n_saved_page_req_struct *delete_saved_page_req)
{
    MSF_UINT32 i,count_copy;
	count_copy=bam_offline_delete_request_send_count;

    for(i = 0; i < count_copy ; i++ )                                
    {   
		//bam_offline_delete_request_send_count=count_copy;
        if(bam_offline_page_delete_count<4)
        {
            bam_offline_page_delete_count++;
            bam_offline_delete_request_send_count--;
            bam_offline_delete((delete_saved_page_req->index_array[bam_offline_page_delete_count_total]-bam_offline_page_delete_count_total));
			bam_offline_page_delete_count_total++;
        }
    }
}


void
bam_offline_handle_delete_response (void)
{
    bam_offline_num_of_del_req--;
    bam_offline_page_delete_count--;
    if(bam_offline_delete_request_send_count)
	{
        bam_offline_delete_pending_page_start(&bam_offline_copy_delete_saved_page_req);
	    return;
	}
    bam_offline_copy_delete_saved_page_req.instance_id=0;
	//BAM_FREE(bam_offline_copy_delete_saved_page_req.index_array);
	//OslMfree(bam_offline_copy_delete_saved_page_req.index_array);
    bam_offline_copy_delete_saved_page_req.index_array=NULL;
    bam_offline_copy_delete_saved_page_req.count=0;
    
    if((!bam_offline_num_of_del_req) && !bam_offline_delete_request_send_count)
        bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_DELETE_OK, NULL, NULL);
}
/* MAUI_01071590 End */

/*****************************************************************************
 * FUNCTION
 *  bam_offline_pack_list_item_from_index
 * DESCRIPTION
 *
 * PARAMETERS
 *  p                   [?]
 *  aval_size           [IN]
 *  start_idx           [IN]
 *  packed_items        [?]
 * RETURNS
 *
 *****************************************************************************/
int bam_offline_pack_list_item_from_index(void *p, int aval_size, int start_idx, int *packed_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *packed_items = 0;

    if (bam_offline_n_items == 0 || start_idx < 0 || start_idx >= bam_offline_n_items)
    {
        return BAM_ERROR_SAVED_PAGES_NOT_FOUND;
    }
    else if (p)
    {
        int i;
        MSF_UINT32 title_len;
        char *s;
        MSF_INT8 *start_p = (MSF_INT8*) p;
        bam_offline_item_t *offline_ptr = bam_offline_list;

        for (i = start_idx; i < bam_offline_n_items; i++)
        {
            /* Check that title length should be limited to BAM_MAX_TITLE_LABEL_LEN (40) */
            title_len = (offline_ptr->title != 0) ? MIN(MSF_WIDGET_STRING_GET_LENGTH(offline_ptr->title, 1, MsfUtf8), BAM_MAX_TITLE_LABEL_LEN) : 0;

            if (title_len == 0)
            {
                return BAM_ERROR_SAVED_PAGES_FAILED;
            }

            if ((title_len + sizeof(MSF_UINT32)) < (MSF_UINT32)aval_size)
            {
                bam_cmn_set_bits(start_p, sizeof(MSF_UINT32) * 8, title_len);
                start_p += sizeof(MSF_UINT32);
                aval_size -= sizeof(MSF_UINT32);

                s = BAM_ALLOC(title_len+1);
                MSF_WIDGET_STRING_GET_DATA (offline_ptr->title, s, MsfUtf8);
                memcpy((char*)start_p, s, title_len);
                start_p += title_len;
                aval_size -= title_len;

                (*packed_items) += 1;
                BAM_FREE(s);
            }
            else
            {
                break;
            }
            offline_ptr = offline_ptr->next;
        }

        *start_p = '\0';
        return 0;   /* Success */
    }

    return BAM_ERROR_SAVED_PAGES_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  bam_offline_handle_get_saved_page_req
 * DESCRIPTION
 *
 * PARAMETERS
 *  index       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_offline_handle_get_saved_page_req(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bam_offline_n_items == 0 || index < 0 || index >= bam_offline_n_items)
    {
        bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_ERR_NOT_FOUND, NULL, NULL);
    }
    else
    {
        bam_offline_item_t *ofln_item;

        ofln_item = bam_offline_get_item(index);

        if (ofln_item)
        {
            MSF_UINT32 len;
            char *s;
            len = MSF_WIDGET_STRING_GET_LENGTH(ofln_item->title, 1, MsfUtf8);
            s = BAM_ALLOC(len+1);
            MSF_WIDGET_STRING_GET_DATA (ofln_item->title, s, MsfUtf8);
            bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_GET_OK, s, ofln_item->url);
            BAM_FREE(s);
        }
        else
        {
            bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_ERR_INTERNAL, NULL, NULL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  bam_offline_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  label           [IN]
 *  overwrite       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_offline_save(const char *title, const char *url, int overwrite)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
    bam_offline_init();
    bam_offline_init_addr((char*)title, (char*)url);
    if (bam_offline_search_item_by_url((char*)url) != NULL)
    {
        if(!overwrite)
        {
            bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_ERR_EXISTS, (char*)title, (char*)url);
            bam_offline_free_addr();
        }
        else
        {
            bam_offline_state = BAM_OFFLINE_STATE_UPDATE_REQUEST;
            BRSif_savePageOffline(MSF_MODID_BAM, bam_sif_get_brs_id(), /*addr->*/url, NULL);
        }
    }
    /*Add Offline Page*/
    else if (bam_offline_n_items >= BAM_MAX_NBR_OFFLINE_PAGES)
    {
        bam_msg_save_page_cnf(BAM_OFFLINE_STATUS_SAVE_ERR_LIMIT, (char*)title, (char*)url);
        bam_offline_free_addr();
        return;
    }
    else
    {
        bam_offline_state = BAM_OFFLINE_STATE_SAVE_REQUEST;
        BRSif_savePageOffline(MSF_MODID_BAM, bam_sif_get_brs_id(), /*addr->*/url, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  bam_offline_delete
 * DESCRIPTION
 *  Delete page
 * PARAMETERS
 *  label       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void bam_offline_delete(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_offline_delete_ofln(index, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  bam_offline_delete_all
 * DESCRIPTION
 *  Delete all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_offline_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        MSF_INT8 i, total = bam_offline_n_items;

        for(i = total - 1; i >= 0 ; i--)
        {
            bam_offline_delete_ofln(i, NULL);
        }
}

int bam_offline_get_num_saved_pages(void)
{
    return bam_offline_n_items;
}

void bam_offline_delete_pending_page(bam_delete_n_saved_page_req_struct *delete_saved_page_req)
{   
	bam_offline_page_delete_count_total=0;
    bam_offline_copy_delete_saved_page_req.instance_id = delete_saved_page_req->instance_id;
    bam_offline_copy_delete_saved_page_req.count = delete_saved_page_req->count;
    bam_offline_copy_delete_saved_page_req.index_array = BAM_ALLOC((bam_offline_copy_delete_saved_page_req.count+1) * sizeof(MSF_UINT32));
    memcpy(bam_offline_copy_delete_saved_page_req.index_array, delete_saved_page_req->index_array, (bam_offline_copy_delete_saved_page_req.count * sizeof(MSF_UINT32)));
//  bam_offline_copy_delete_saved_page_req.index_array=delete_saved_page_req->index_array;
    bam_offline_delete_request_send_count=(delete_saved_page_req->count);
    bam_offline_delete_pending_page_start(&bam_offline_copy_delete_saved_page_req);
}

#endif
#endif
#endif /*OBIGO_Q03C_BROWSER*/
