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
 * MmsMsgParseSrv.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_SRV_PRSE_H
#define MMS_SRV_PRSE_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "kal_general_types.h"
//#include "fmt_struct.h"
//#include "FileMgr.h"
//#include "FileManagerGprot.h"
//#include "mmsadp.h"
//#include "xml_def.h"
//#include "WguiCategoryGprot.h"
//#include "Drm_Def.h"
#include "MmsSrvGprot.h"
// #include "MmsXMLDefSrv.h"
#include "MMIDataType.h"
#include "app_usedetails.h"
#include "wgui_categories_MMS_viewer.h"
#include "MmsSrvProt.h"
#include "mma_api.h"
#define SRV_MMS_VIEWER_MAX_ALT_STR_LEN (20)
// #define SRV_MMS_VIEWER_SLIDE_SWITCH_TIME (750)

#define SRV_MMS_USE_DETAILS_UNBLOCK_TIME (50)
#define SRV_MMS_MAX_USE_DETAILS_PER_SLIDE (15)
#define MMI_MV_MAX_USE_DETAILS (45)
#define SRV_MMS_USE_DETAIL_FOLDER L"@usedetail"
#define SRV_MMS_USE_DETAIL_FILE_NAME   L"\\use.bin"
#define SRV_MMS_USE_DETAIL_FILE_PATH 24
#define SRV_MMS_VIEWER_MSG_PARSER_DO_BEST_FIT 0x00000001
#define SRV_MMS_PARSE_ADDRESSES_BY_TYPE    0x00000001
#define SRV_MMS_MSG_PARSER_IGNORE_SLIDES   0x00000002
#define SRV_MMS_PARSING_LIMIT 60
#define SRV_MMS_UNBLOCK_TIME 50
#define SRV_MMS_VIEWER_DEFAULT_BG_COLOR (mma_get_default_smil_bg_color())
#define SRV_MMS_VIEWER_DEFAULT_FG_COLOR (mma_get_default_smil_fg_color())
#define SRV_MMS_VIEWER_DEFAULT_IMAGE_LAYOUT    (MMA_LAYOUT_IMAGE_ON_TOP)
/*******************************/
/* Object & Attachment Related */
/*******************************/

/*****************USE DETAIL RELATED***************************/

typedef struct
{
    PU8 p_ucs2_buffer;
    PU16 file_path;
    S16 *header;
    U32 process_id;
    U32 number_count;
    U32 email_count;
    U32 url_count;
    U32 ucs2_buffer_len;
    S32 fail_reason;
    S32 number_total_count;
    S32 email_total_count;
    S32 url_total_count;
    S32 file_handle;
    S32 current_count;
    MMI_BOOL slide_not_parsed;
    applib_address_node_struct *applib_phnum_list;
    applib_address_node_struct *applib_email_list;
    applib_address_node_struct *applib_url_list;
    srv_mms_viewer_use_details_list *flat_details_list;
    mma_mms_slide_struct *current_slide;
    mma_mms_slide_struct *parsed_slide;
    mma_mms_slide_struct *first_slide;
    U16 count;
    U16 total_count;
    srv_mms_get_use_details_rsp_struct use_detail_rsp;
} srv_mms_use_details_struct;

typedef struct srv_mms_container_struct_t
{
    MMI_BOOL used;
    U32 uid;
#ifdef __MMI_MV_SUPPORT_REF_ID__
    ref_id_list_pointer *ref_id_table;
#endif 
    p_srv_mms_viewer_object *object_data;
    mma_mms_slide_struct *current_rsp_slide;
    srv_mms_viewer_obj_container_struct *obj_contaner;
#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
    region_id_list_structure *region_id_list;
#endif 
    srv_mms_free_mem free_func;
    srv_mms_alloc_mem alloc_func;
    mma_mms_description_struct description;
    srv_mms_xml_parser_context_struct data;
    srv_mms_xml_msg_viewer_data_struct viewer_data;
    srv_mms_drm_process_cntx_struct drm_cntx;
    srv_mms_use_details_struct use_detail_data;
} srv_mms_container_struct;

/************USE DETAIL RELATED*********************/

extern MMI_BOOL srv_mms_get_use_details_for_slide_ext(
                    srv_mms_process_data_struct *process,
                    srv_mms_get_use_details_viewer_req_struct *req);
extern S32 srv_mms_get_use_details_for_slide(void *para);

typedef struct
{
    U32 index;
    MMI_BOOL is_used;
    delete_instance_callback delete_cb;
    void *user_data;
    srv_mms_container_struct view_container;
    srv_mms_mem_mgr_get_asm_alloc_struct viewer_cntx;
    srv_mms_mem_mgr_get_asm_alloc_struct app_cntx;
} srv_mms_instance_context_struct;

extern srv_mms_instance_context_struct *srv_mms_get_instance(U32 index);
extern srv_mms_container_struct *srv_mms_initialize_with_instance(U32 index);

extern srv_mms_viewer_slide_layout_enum srv_mms_viewer_convert_mms_layout_type(U8 layout_type);
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_SRV_PRSE_H */ 

