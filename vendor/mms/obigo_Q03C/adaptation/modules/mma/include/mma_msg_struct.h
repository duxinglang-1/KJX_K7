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
 *   mma_msg_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file declares MMS message structure definition used during creation and parsing
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
 *==============================================================================
 *******************************************************************************/

#ifndef _MMA_MSG_STRUCT_H
#define _MMA_MSG_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "mmsadp.h"
#include "mms_if.h"
/*
#include "sls_cfg.h"
#include "sls_def.h"
#include "sls_if.h"*/
//#include "mma_smil.h"
#include "mma_api.h"
#include "app_mine.h"
#include "mms_api.h"

#define MMA_SUPPORTED_CHARSET {                 \
    {MMS_US_ASCII,      "us-ascii"},            \
    {MMS_UTF8,          "utf-8"},               \
    {MMS_ISO_8859_1,    "iso-8859-1"},          \
    {MMS_ISO_8859_1,    "latin1"},              \
    {MMS_UCS2,          "iso-10646-ucs-2"},     \
    {MMS_UTF16BE,       "utf-16be"},            \
    {MMS_UTF16LE,       "utf-16le"},            \
    {MMS_UTF16,         "utf-16"},              \
                                                \
    /* The last entry must be present */        \
    {MMS_UNKNOWN_CHARSET, ""}}


#define MMA_MAX_SLIDE_TIMING  99999   /*To put limit on the slide timing variables 
                                        (begin/end/dur/ slide duration) Max 5 chars*/


/******************************************************************************
 * Macro definition
 *****************************************************************************/
typedef enum
{
    MMA_DRM_METHOD_NONE,
    MMA_DRM_METHOD_FORWARD_LOCK,
    MMA_DRM_METHOD_COMBINED_DELIVERY,
    MMA_DRM_METHOD_SEPARATE_DELIVERY
} mma_drm_method_enum;

typedef enum
{
    MMA_PLAIN_TEXT,         /* !< The message is of type plain text */
    MMA_SMIL,               /* !< The message is of type SMIL */
    MMA_MULTIPART_MIXED,    /* !< The message is of type Multipart/mixed */
    MMA_UNSUPPORTED         /* !< The message type is not supported */
} mma_mms_multipart_enum;

/******************************************************************************
 * Structure definition
 *****************************************************************************/
typedef struct
{
    const MSF_UINT32 mmsCharset;    /* !< The MMS charset definition */
    const char *charsetStr;         /* !< The MSF charset definition */
} mma_charset_item;

typedef struct
{
    union
    {
        MmsGetHeader *g_header;         /* used when parsing */
        MmsSetHeader *s_header;         /* used when creating */
        MmsNotification *notif;         /* used when parsing */
        MmaReport *report;              /* used when parsing */
    } header;
    kal_uint32 body_no;     /* nEntries should not be used ?! */
    MmsVersion s_version;   /* used when creating */
    mma_mms_multipart_enum multipart_type;
} mma_header_struct;

/*
typedef struct mma_object_struct_t
{
    kal_uint32 size;
    kal_uint32 offset;
    kal_uint32 id;      
    char *file_path;    
    char *file_name;   
    char *mime_type;    
    char *content_id;       
    char *content_location; 
    kal_uint16 xml_id;              
    MmsCharset charset; 
    kal_bool is_attachment;
    kal_bool is_virtual_file;
    kal_bool is_restricted;
    kal_bool is_mixed_obj; 
    mma_drm_type_for_process_enum drm_type;
    struct mma_object_struct_t *next;
#ifdef __DRM_SUPPORT__
    char *drm_mime_type;
    mma_drm_type_enum xml_drm_type; 
#endif 
} mma_object_struct;

typedef struct mma_slide_object_struct_t
{
    mma_object_struct *obj;
    SlsRegion *region;  
    kal_uint32 bg_color;    
    kal_uint32 fg_color;    
    kal_uint32 begin;   
    kal_uint32 end;    
    char *alt;
    struct mma_slide_object_struct_t *next;
    kal_uint16 xml_id;  
    SlsMediaObjectType type;
    mma_text_style_enum text_style;
    mma_text_size_enum text_size;
} mma_slide_object_struct;

typedef struct mma_slide_struct_t
{
    mma_slide_object_struct *slide_objs;
    struct mma_slide_struct_t *next;
    mma_slide_object_struct *ref_item_list;
    kal_uint32 duration;    

    kal_uint16 xml_id;  
} mma_slide_struct;

typedef struct mma_unref_list_struct_t
{
    mma_object_struct *attachment;
    struct mma_unref_list_struct_t *next;
} mma_unref_list_struct;

typedef struct mma_sls_region_list_t
{
    SlsRegion *region;
    char *name;
    kal_uint32 id;
    struct mma_sls_region_list_t *next;
} mma_sls_region_list;

typedef struct
{
    SlsRootLayout root_layout;
    mma_sls_region_list *regions;       
    kal_uint32 slide_no;
    mma_slide_struct *slides;
    mma_object_struct *objects;
    mma_slide_struct *current_slide;
    mma_object_struct *current_object;
    mma_unref_list_struct *unref_list; 
    mma_slide_layout_enum layout;
} mma_body_struct;
*/
typedef struct
{
    char *text_name;
    mma_text_size_enum text_size;
} mma_text_size_parse_struct;

typedef struct
{
    char *text_name;
    mma_text_style_enum text_style;
} mma_text_style_parse_struct;

/******************************************************************************
 * Extern functions
 *****************************************************************************/
extern mma_result_enum translate_fs_result_to_mma(int result);
extern mma_result_enum translate_mms_result_to_mma(MmsResult result);
//extern mma_result_enum translate_sls_result_to_mma(SlsResult result);
extern mma_priority_enum translate_mms_priority_to_mma(MmsPriority prio);
extern MmsPriority translate_mma_priority_to_mms(mma_priority_enum prio);
extern mma_expiry_time_enum translate_mms_expiry_to_mma(MmsTimeType type, MmsTimeSec expiry, MmsTimeSec then);
extern void translate_mma_expiry_to_mms(
                mma_expiry_time_enum expiry,
                MmsTimeSec now,
                MmsTimeType *type,
                MmsTimeSec *sec);
extern mma_delivery_time_enum translate_mms_delivery_to_mma(MmsTimeType type, MmsTimeSec delivery, MmsTimeSec then);
extern void translate_mma_delivery_to_mms(
                mma_delivery_time_enum delivery,
                MmsTimeSec now,
                MmsTimeType *type,
                MmsTimeSec *sec);
extern mma_version_enum translate_mms_version_to_mma(MmsVersion version);
extern MmsVersion translate_mma_version_to_mms(mma_version_enum version);
extern MmsVersion mma_get_mms_version_from_em(void);
extern mma_msg_class_enum translate_mms_class_to_mma(MmsClassIdentifier version);
extern MmsClassIdentifier translate_mma_class_to_mms(mma_msg_class_enum classidentifier);
extern mma_addr_type_enum translate_mms_address_type_to_mma(MmsAddressType type);
extern MmsAddressType translate_mma_address_type_to_mms(mma_addr_type_enum type);
extern mma_msg_type_enum translate_mms_msg_type_to_mma(MmsFileType type);
//extern mma_region_fit_enum translate_sls_fit_to_mma(SlsFit fit);
//extern SlsFit translate_mma_fit_to_sls(mma_region_fit_enum fit);
extern mma_charset_enum translate_mms_charset_to_mma(MmsCharset charset);
extern MmsCharset translate_mma_charset_to_mms(mma_charset_enum charset);
extern mma_folder_enum translate_mms_folder_to_mma(MmsFolderType box);
extern MmsFolderType translate_mma_folder_to_mms(mma_folder_enum box);
extern MmsTimeType trnslate_mma_type_to_mms(mma_mms_time_type_enum type);
extern mma_media_msg_enum mma_get_message_media_type(mma_mms_description_body_struct *body);

extern char *mma_ucs2_to_utf8_string(const kal_wchar *ucs2_str);
extern kal_wchar* mma_str_trnslt_utf8_to_ucs2(kal_uint8 mod_id, const char *src_str);

extern kal_uint8 mma_get_value_length_bytes(kal_uint32 n);
extern mma_mms_multipart_enum mma_get_multipart_type(MmsBodyInfoList *bodyInfoList);
extern const char *mma_get_mime_type_from_mmsContentType(const MmsContentType *contentType);
extern const char *mma_get_mime_type_from_filename_and_mime_string(const char *filename, char * mime_string);
extern const char *mma_get_mime_type_from_filename_and_type(const char *filename, applib_mime_type_enum type);
extern MSF_INT32 mma_get_mmsKnownMediaType_from_mime_type(const char *mime);

#ifdef __DRM_SUPPORT__
extern kal_bool mma_drm_check_right(const char *filename);
extern mma_drm_type_enum mma_drm_check_right_vf(
                            mma_drm_type_for_process_enum type,
                            const char *filename,
                            int offset,
                            int size,
                            kal_uint8 storage);
extern mma_drm_method_enum mma_drm_get_method_type(kal_int32 fh, const char *filename, kal_uint8 storage);
extern mma_drm_method_enum mma_um_drm_get_method_type(kal_int32 fh, const char *filepath);
#endif /* __DRM_SUPPORT__ */ 

extern kal_uint8 mma_get_uintvar_length_bytes(kal_uint32 n);
extern kal_uint32 mma_get_value_digit_number(kal_uint32 n);

extern kal_uint32 mma_get_total_item_count(mma_mms_description_body_struct *body);
extern char *mma_get_app_id_from_params(const MmsAllParams *params);
extern char *mma_get_reply_app_id_from_params(const MmsAllParams *params);
extern char *mma_get_presentation_from_params(const MmsAllParams *param);
extern const char *mma_get_name_from_path(char *path);
extern mma_mms_object_struct *mma_get_object_by_name(mma_mms_description_body_struct *body, const char *name);
extern MsfSize mma_get_screen_size(void);
extern kal_uint32 mma_get_user_element_size(mma_header_struct *header, MmsBodyInfoList *skeleton);

extern void mma_add_param_string(
                MmsAllParams **all_params,
                MmsParam param,
                const char *str_key_value,
                const char *str_value);

extern MmsBodyParams *mma_create_body_params(
                        MmsKnownMediaType media_type,
                        char *media_string,
                        char *name,
                        char *cnt_id,
                        char *cnt_loc,
                        MmsCharset charset);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
extern char *mma_create_name_from_nonascii_name(const char *name, int counter);
#else
extern char *mma_create_name_from_nonascii_name(const char *name, kal_bool with_random_suffix);
#endif
extern mma_mms_object_struct *mma_create_object_from_mo(kal_uint8 modid,
                            mma_app_mode_enum mode,
                            kal_uint32 msg_id,
                            MmsFileType suffix,
                            MmsBodyInfoList *mo);
extern SlsMediaObject *mma_create_sls_object_from_mma_slide_object(
                        SlsMediaObjectType type,
                        const mma_mms_slide_struct *slide);
extern SlsMediaObject *mma_create_sls_object_list_from_mma_slide_object(
						SlsMediaObjectType type, 
    					const mma_mms_slide_struct *slide);


//extern void mma_copy_attachment_info(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, SlsOpenSmilRsp *rsp, mma_app_mode_enum mode, kal_uint8 *ref_attach_count, kal_uint8 *content_truncate_info);
extern void mma_copy_sls_root_layout(const SlsRootLayout *source, SlsRootLayout *dest, mma_mms_description_body_struct *body);
//extern void mma_copy_slide_info(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, const SlsSlideInfo *slsInfo, SlsRootLayout *root_layout);
void mma_insert_addr_to_list(MmsAddressList **list, MmsAddressType addr_type, char *name, char *address);
extern mma_mms_slide_struct *mma_insert_slide(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, kal_uint32 duration);
extern mma_mms_object_struct *mma_insert_object_to_tail(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *obj);
extern mma_mms_attachment_info_struct *mma_insert_unref_item_to_tail(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *obj);
extern mma_mms_slide_ref_object_struct *mma_insert_slide_obj(MSF_UINT8 mod_id, 
                                    applib_mime_type_enum g_type,
                                    mma_mms_slide_struct *slide,
                                    mma_mms_object_struct *obj);

extern kal_int32 mma_unicode_to_utf8_len(kal_wchar *ucs2);
extern kal_bool mma_is_ascii_string(const char *str);
extern kal_bool mma_is_ascii_file(const char *filepath);
extern kal_bool mma_is_drm_message(mma_mms_description_body_struct *body);
extern kal_bool mma_is_follow_content_class(mma_mms_description_body_struct *body);
extern kal_bool mma_is_restricted_type_vf(
                    mms_content_class_enum class,
                    const char *filename,
                    const char *mime,
                    kal_uint32 offset,
                    kal_uint32 size,
                    kal_uint8 storage);
extern kal_uint32 mma_get_mmi_file_size(kal_int32 file_handle, const kal_wchar *filepath);
extern void mma_remove_invalid_address(MSF_UINT8 mod_id, MmsGetHeader *header, mma_app_mode_enum mode);
/*extern void mma_remove_slide_by_index(mma_body_struct *body, kal_uint32 index);*/
extern void mma_remove_object_in_slide(mma_mms_slide_struct *list, mma_mms_object_struct *obj);

extern void mma_update_address_list(MSF_UINT8 mod_id , MmsGetHeader *header);
extern void mma_update_subject_text(MSF_UINT8 mod_id, MmsEncodedText *subject);
extern void mma_update_unref_list(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_app_mode_enum mode, kal_uint8 *ref_attach_count, kal_uint8 *content_truncate_info);

extern void mma_free_sls_media_object(SlsMediaObject **object);
extern void mma_free_sls_media_object_list(SlsMediaObject **list);
extern void mma_mms_free_slide_list(MSF_UINT8 mod_id, mma_mms_slide_struct **slides);
void mma_mms_free_unref_list(MSF_UINT8 mod_id, mma_mms_attachment_info_struct **list);
extern void mma_free_body_params(MmsBodyParams **body_params);
extern void mma_convert_size_to_uintvar(MSF_UINT32 data_size, void *buf);
extern kal_uint32 mma_get_recipient_num(MmsGetHeader *header);
extern void mma_trim_utf8_string(char *str);
extern void mma_transform_illegal_name(char *name);

kal_bool mma_mms_convert_visibility_enum_value_to_bool(mma_mms_sender_visibility_enum hide_sender);
extern mma_slide_layout_enum mma_get_slide_layout(mma_mms_slide_struct *slide);
extern kal_uint32 mma_get_mms_slide_count(mma_mms_description_body_struct *body);
extern void mma_mms_free_object_list(MSF_UINT8 mod_id, mma_mms_object_struct **obj);
extern void mma_mms_free_object(MSF_UINT8 mod_id, mma_mms_object_struct **obj);
extern void mma_free_app_mms_header(kal_uint8 mod_id, mma_mms_header_struct *header);
extern void mma_mms_free_mms_descriptor(kal_uint8 mod_id, mma_mms_description_struct *mms_dsr);
extern char *mma_replace_file_ext_with_input(MSF_UINT8 mod_Id, char *filename, const char *mime_string);
extern mma_result_enum mma_copy_app_to_mms_header(mma_mms_header_struct *source, mma_header_struct *dest);
extern void mma_copy_create_address_info(mma_mms_addr_list_struct *addr_list, MmsSetHeader *header);
extern mma_result_enum mma_copy_mms_to_app_header(kal_uint8 mod_id, mma_header_struct *src_header, mma_mms_header_struct *dest, mma_app_mode_enum mode, MmsFileType suffix, mma_msg_type_enum msg_type, kal_uint32 msg_id);
extern void mma_copy_parse_address_info(kal_uint8 mod_id, MmsAddressList *addr_list, mma_address_group_type_enum group, mma_mms_header_struct *dest);
extern void mma_append_addr_to_list(kal_uint8 mod_id, mma_mms_addr_list_struct **list, mma_addr_type_enum addr_type, char *name, char *address, mma_address_group_type_enum group);
extern void mma_update_object_list(kal_uint8 mod_id, mma_mms_description_body_struct *body, kal_uint8 storage);
extern void mma_assign_slide_index(mma_mms_description_body_struct *body);
extern MSF_BOOL mma_is_slide_object(const SmilMediaObject *mediaObj, const mma_mms_object_struct *obj);
extern void mma_generate_slide_info(mma_mms_slide_struct *slide, SmilMediaObject *mobj, mma_mms_object_struct *obj, mma_mms_description_body_struct *body, InstanceData *ctx);
extern void mma_populate_unref_item_list(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *attach_obj, mma_app_mode_enum mode, kal_uint8 *ref_attach_count, kal_uint8 *content_truncate_info);
extern MSF_BOOL mma_is_presentation_part(char *param,  MmsEntryHeader *eHeader);
void mma_trace_mms_content_info(mma_mms_description_struct *content_info);

#endif /* _MMA_MSG_STRUCT_H */ 

