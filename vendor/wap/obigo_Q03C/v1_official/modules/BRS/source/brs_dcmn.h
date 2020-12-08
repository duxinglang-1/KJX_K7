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

/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */


/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_dcmn.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/













#ifndef _brs_dcmn_h
#define _brs_dcmn_h

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif




typedef struct brs_d_object_select_event_st  brs_d_object_select_event_t;
typedef struct brs_d_doc_st                  brs_d_doc_t;
typedef struct brs_dt_tree_node_st           brs_dt_tree_node_t;
typedef struct brs_dt_element_st             brs_dt_element_t;
typedef struct brs_dt_tree_walker_st         brs_dt_tree_walker_t;
typedef struct brs_dt_node_iterator_st       brs_dt_node_iterator_t;
typedef struct brs_d_work_item_st            brs_d_work_item_t;
typedef struct brs_d_link_ref_st             brs_d_link_ref_t;
typedef struct brs_d_le_obj_ref_st           brs_d_le_obj_ref_t;
typedef struct brs_d_obj_ref_st              brs_d_obj_ref_t;
typedef struct brs_d_sas_priv_data_st        brs_d_sas_priv_data_t;
typedef void   brs_d_node_action_function_t (brs_d_doc_t *d, brs_dt_tree_node_t *n, int is_entry);
typedef struct brs_d_list_index_st           brs_d_list_index_t;
typedef struct brs_d_image_map_st            brs_d_image_map_t;
typedef struct brs_d_area_def_st             brs_d_area_def_t;
typedef struct brs_d_client_image_map_st     brs_d_client_image_map_t;
typedef struct brs_d_server_image_map_st     brs_d_server_image_map_t;
typedef struct brs_d_file_upload_st          brs_d_file_upload_t;



typedef enum
{
	INPUT_ERR_GENERAL,
	INPUT_ERR_EMPTY,
	INPUT_ERR_LENGTH,
	INPUT_ERR_NUMERIC,
	INPUT_ERR_UPPER,
	INPUT_ERR_LOWER,
	INPUT_ERR_NUMERIC_PUNCT,
	INPUT_ERR_UPPER_PUNCT,
	INPUT_ERR_LOWER_PUNCT
} brs_input_validation_error_t;

#ifdef BRS_CONFIG_WML
typedef struct brs_d_wml_template_do_st      brs_d_wml_do_t;
#endif


#endif
