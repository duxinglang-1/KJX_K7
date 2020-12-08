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
 * UcSrv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements .......... Unified Composer.
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
#ifndef _UNIFIED_COMPOSER_SRV_H
#define _UNIFIED_COMPOSER_SRV_H
 #include "MMI_features.h"
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
//suggested add
    #include "UcSrvGprot.h"
    #include "MMIDataType.h"
    #include "kal_public_defs.h"
    #include "Conversions.h"
 //   #include "kal_general_types.h"
   

/* UC xml tag MMS. */
#define SRV_UC_XML_ELEMENT_MMS "mms"
/* UC xml tag header. */
#define SRV_UC_XML_ELEMENT_HEADER "header"
/* UC xml tag to. */
#define SRV_UC_XML_ELEMENT_TO "to"
/* UC xml tag cc. */
#define SRV_UC_XML_ELEMENT_CC "cc"
/* UC xml tag bcc. */
#define SRV_UC_XML_ELEMENT_BCC "bcc"
/* UC xml tag from. */
#define SRV_UC_XML_ELEMENT_FROM "from"
/* UC xml tag type. */
#define SRV_UC_XML_ATTR_TYPE "type"
/* UC xml tag phonenumber. */
#define SRV_UC_XML_ATTR_POHNE_NUMBER "P"
/* UC xml tag email. */
#define SRV_UC_XML_ATTR_EMAIL_ADDR "E"
/* UC xml tag IP4 address. */
#define SRV_UC_XML_ATTR_IP_ADDR "IP4"
/* UC xml tag subject. */
#define SRV_UC_XML_ELEMENT_SUBJECT "subject"
/* UC xml tag read report. */
#define SRV_UC_XML_ELEMENT_READ_REPORT "rr"
/* UC xml tag delivery report. */
#define SRV_UC_XML_ELEMENT_DELIVERY_REPORT "dr"
/* UC xml tag priority. */
#define SRV_UC_XML_ELEMENT_PRIORITY "prio"
/* UC xml tag expiry. */
#define SRV_UC_XML_ELEMENT_EXPIRY "expiry"
/* UC xml tag delivery. */
#define SRV_UC_XML_ELEMENT_DELIVERY_TIME "delivery"
/* UC xml tag visible. */
#define SRV_UC_XML_ELEMENT_VISIBLE "visible"
/* UC xml tag class. */
#define SRV_UC_XML_ELEMENT_CLASS "class"
/* UC xml tag body. */
#define SRV_UC_XML_ELEMENT_BODY "body"
/* UC xml tag bgcolor. */
#define SRV_UC_XML_ATTR_BGCOLOR "bgColor"
/* UC xml tag fgcolor. */
#define SRV_UC_XML_ATTR_FGCOLOR "fgColor"
/* UC xml tag total slide number. */
#define SRV_UC_XML_ATTR_SLIDE_NUM "slideNum"
/* UC xml tag total object number. */
#define SRV_UC_XML_ATTR_OBJ_NUM "objNum"
/* UC xml tag layout. */
#define SRV_UC_XML_ATTR_LAYOUT "layout"
/* UC xml tag text fit. */
#define SRV_UC_XML_ATTR_TXTFIT "txtFit"
/* UC xml tag imagefit. */
#define SRV_UC_XML_ATTR_IMGFIT "imgFit"
/* UC xml tag slide. */
#define SRV_UC_XML_ELEMENT_SLIDE "slide"
/* UC xml tag index. */
#define SRV_UC_XML_ATTR_INDEX "index"
/* UC xml tag duration. */
#define SRV_UC_XML_ATTR_DURATION "dur"
/* UC xml tag id. */
#define SRV_UC_XML_ATTR_ID "id"
/* UC xml tag begin. */
#define SRV_UC_XML_ATTR_BEGIN "begin"
/* UC xml tag end. */
#define SRV_UC_XML_ATTR_END "end"
/* UC xml tag text. */
#define SRV_UC_XML_ELEMENT_TEXT "text"
/* UC xml tag image. */
#define SRV_UC_XML_ELEMENT_IMAGE "img"
/* UC xml tag audio. */
#define SRV_UC_XML_ELEMENT_AUDIO "audio"
/* UC xml tag video. */
#define SRV_UC_XML_ELEMENT_VIDEO "video"
/* UC xml tag ref. */
#define SRV_UC_XML_ELEMENT_REF "ref"
/* UC xml tag attach. */
#define SRV_UC_XML_ATTR_ATTACH "attach"
/* UC xml tag virtual file. */
#define SRV_UC_XML_ATTR_VIRTUAL_FILE "vf"
/* UC xml tag drm. */
#define SRV_UC_XML_ATTR_DRM "drm"
/* UC xml tag size. */
#define SRV_UC_XML_ATTR_SIZE "size"
/* UC xml tag offset. */
#define SRV_UC_XML_ATTR_OFFSET "offset"
/* UC xml tag encoding. */
#define SRV_UC_XML_ATTR_ENCODING "encoding"
/* UC xml tag object. */
#define SRV_UC_XML_ELEMENT_OBJECT "obj"
/* UC xml tag name. */
#define SRV_UC_XML_ELEMENT_NAME "name"
/* UC xml tag filepath. */
#define SRV_UC_XML_ELEMENT_FILE_PATH "filepath"

/* Max number of instances of the context that UC servce supports. */
#ifdef __COSMOS_MMI_PACKAGE__
	#define SRV_MAX_UC_INSTANCES 5
#else
	#define SRV_MAX_UC_INSTANCES 1
#endif /*__COSMOS_MMI_PACKAGE__*/

extern srv_uc_context_struct *g_srv_uc_p[];
extern srv_uc_context_struct g_srv_uc_cntx[];

/*extern void srv_uc_xml_data_address_hdlr(
                U32 instance,
                U8 *utf8_addr,
                S32 addr_len,
                srv_uc_address_type_enum addr_type,
                srv_uc_address_group_type_enum addr_group_type); */
extern mma_mms_slide_struct *srv_uc_get_end_slide(U32 instance);
extern mma_mms_object_struct *srv_uc_check_duplicate_object_by_filename(
                                U32 instance,
                                U16 *file_name,
                                mma_mms_object_struct *start_obj);
extern mma_mms_slide_struct *srv_uc_insert_slide_by_number(U32 instance, U8 slide_number);
extern mma_mms_object_struct *srv_uc_insert_object_to_list_tail(U32 instance);
extern U16 *srv_uc_get_file_name(U16 *filePath);
extern BOOL srv_uc_check_only_attachment(void);
extern void srv_uc_send_message_ext_queue(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
extern U32 srv_uc_convert_to_mms_layout_type(mma_slide_layout_enum layout_type);
extern U32 srv_uc_convert_mms_layout_type_to_uc(U8 layout_type);
extern U8 srv_uc_convert_mms_region_fit_enum_to_uc(U8 region_fit);
extern void srv_uc_replace_duplicate_object_file_name(U32 instance);
extern mmi_chset_enum srv_uc_convert_encoding_type_to_chset(U32 encoding);
extern MMI_BOOL srv_uc_update_object_id(U32 instance);
extern srv_uc_object_type srv_uc_convert_mms_insert_type_to_uc(U32 object_type);
extern U32 srv_uc_convert_ascii_hex_to_dec(U8 *character);
extern void srv_uc_update_text_object_path(U32 instance, mma_mms_slide_struct *slide);
extern U32 srv_uc_convert_to_mms_expiry_time(srv_uc_expiry_time_enum uc_expiry_time);
extern U32 srv_uc_convert_to_mms_delivery_time(srv_uc_delivery_time_enum uc_delivery_time);

#ifdef __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__
extern void srv_uc_fit_text_for_gb_length_to_subject(U32 instance);
#endif /* __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__ */

#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
extern void srv_uc_fit_text_for_ut8_length_to_subject(U32 instance);
#endif /* __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__ */

#ifdef __MMI_MMS_POSTCARD__
extern void srv_postcard_fill_recipient_info(U32 instance, srv_postcard_recipient_struct *wanted_recipient, U8 index);
extern S32 srv_uc_fill_obj_info_for_postcard_without_greeting(U32 instance, mma_mms_object_struct *obj);
#endif /* __MMI_MMS_POSTCARD__ */

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_SRV_H */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */
