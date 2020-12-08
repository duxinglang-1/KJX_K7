/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSXMLDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * XML Related Defines
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#ifndef __MMI_MMSXMLDEF_H__
#define __MMI_MMSXMLDEF_H__
#include "kal_general_types.h"
//#include "fmt_struct.h"
//#include "FileMgr.h"
//#include "FileManagerGprot.h"
//#include "mmsadp.h"
#include "xml_def.h"
#include "Drm_Def.h"
// #include "app_usedetails.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "FileMgrSrvGProt.h"
#include "app_mine.h"
#include "wgui_inputs.h"
#include "mma_api.h"
#include "mma_struct.h"
/************For Parser Gport.h****/
#define   UMMS_MMS_DEFAULT_SYS_DRIVE                SRV_FMGR_SYSTEM_DRV
#define   UMMS_MMS_DEFAULT_PUBLIC_DRIVE             SRV_FMGR_PUBLIC_DRV

#define SRV_MMS_TXT_BUF_UCS2_SIZE (40960)
#define SRV_MMS_MAX_UTF8_TXT_SLIDE_LEN (20480)
#define SRV_MMS_XML_MAX_ADDR_LEN (312)
#define SRV_MMS_XML_MAX_SUBJECT_LEN (40)
#define SRV_MMS_MAX_XML_SIZE_IN_PEER_BUFFER 2000
#define SRV_MMS_XML_TEMP_STR_LEN (1024)
#define SRV_MMS_XML_INVALID_VALUE (0xFF)
#define SRV_MMS_VERSION_LEN (8)
#define SRV_MMS_MAX_ALT_STR_LEN (20)
#define SRV_MMS_VIEWER_UNBLOCK_TIME (50)
#define SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR ((FS_GenVFN_SIZE/ENCODING_LENGTH) + 1 + SRV_FMGR_PATH_MAX_FILE_EXT_LEN )
#define SRV_MMS_VIEWER_MAIN_TXT_BUFFER_SIZE (2280)
typedef void *(*srv_mms_alloc_mem) (U32 size);
typedef void (*srv_mms_free_mem) (void *pmem);
typedef void (*srv_mms_rights_expiry_notify_cb) (void *);

#if !defined(__MMI_MMS_MMA_DRM_ENCODING__)
#define __MMI_MMS_WRAP_DRM_FL_CD__
#endif 

typedef enum
{
    SRV_MMS_VIEWER_OK,
    SRV_MMS_VIEWER_FILE_ERROR,
    SRV_MMS_VIEWER_ASM_ERROR,
    SRV_MMS_VIEWER_OUT_OF_MEM,
    SRV_MMS_VIEWER_NOT_ENOUGH_MEMORY,
    SRV_MMS_VIEWER_PARSER_ERROR,
    SRV_MMS_VIEWER_OBJ_LIMIT_REACHED,
    SRV_MMS_VIEWER_ROOT_DIR_FULL,
    SRV_MMS_VIEWER_PARSE_FAIL,
    SRV_MMS_VIEWER_CORRUPT_MMS,
    SRV_MMS_VIEWER_UNSUPPORT_MMS,
    SRV_MMS_VIEWER_PARSE_BLOCK,
    SRV_MMS_VIEWER_PARSE_SUCCESS
}
srv_mms_viewer_result_enum;

typedef enum
{
    WGUI_MV_VIEW_NONE,
    WGUI_MV_VIEW_ONLY,
    WGUI_MV_VIEW_PREVIEW,
    WGUI_MV_VIEW_MAX
} wgui_mv_view_style_enum;

typedef enum
{
    SRV_MMS_XML_PARSE_NONE,
    SRV_MMS_XML_PARSE_HEADER_ONLY,
    SRV_MMS_XML_PARSE_BODY_ONLY,
    SRV_MMS_XML_PARSE_COMPLETE
} srv_mms_xml_parse_mode_enum;

typedef enum
{
    SRV_MMS_VIEWER_STYLE_NORMAL,
    SRV_MMS_VIEWER_STYLE_ITALIC,
    SRV_MMS_VIEWER_STYLE_BOLD,
    SRV_MMS_VIEWER_STYLE_MAX
} srv_mms_viewer_font_style_enum;
typedef enum
{
    SRV_MMS_ADDRESS_GROUP_TYPE_TO,
    SRV_MMS_ADDRESS_GROUP_TYPE_CC,
    SRV_MMS_ADDRESS_GROUP_TYPE_BCC,
    SRV_MMS_ADDRESS_GROUP_TYPE_FROM,
    SRV_MMS_ADDRESS_GROUP_TYPE_TOTAL_NUM
} srv_mms_address_group_type_enum;

typedef enum
{
    SRV_MMS_ADDRESS_TYPE_PHONE_NUMBER,
    SRV_MMS_ADDRESS_TYPE_EMAIL,
    SRV_MMS_ADDRESS_TYPE_TOTAL_NUM
} srv_mms_address_type_enum;

typedef struct srv_mms_addr_struct_t
{
    struct srv_mms_addr_struct_t *next;
    struct srv_mms_addr_struct_t *previous;

    kal_uint8 *addr;    /* ascii for phone number while ucs2 for email address. NULL terminator is needed */
    srv_mms_address_type_enum type;
    srv_mms_address_group_type_enum group;
} srv_mms_addr_struct;

typedef enum
{
    SRV_MMS_OBJECT_TYPE_IMAGE,
    SRV_MMS_OBJECT_TYPE_AUDIO,
    SRV_MMS_OBJECT_TYPE_VIDEO,
    SRV_MMS_OBJECT_TYPE_TEXT,
    SRV_MMS_OBJECT_TYPE_ATTACHMENT,
    SRV_MMS_OBJECT_TYPE_UNKNOWN,
    SRV_MMS_OBJECT_TYPE_MAX
} srv_mms_viewer_object_type_enum;

typedef enum
{
    SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_TOP,
    SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_BOTTOM,
    SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_LEFT,
    SRV_MMS_VIEWER_DRAWABLE_MEDIA_ON_RIGHT,
    SRV_MMS_VIEWER_DRAWABLE_MEDIA_LAYOUT_MAX
} srv_mms_viewer_slide_layout_enum;

/* After XML Removal this structure should not be used anywhere */
#if(0)
typedef struct
{
    /* WARNING:: sizeof(mmi_mv_object_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    U32 consume_id;
    U32 offset;
    U32 size;       /* file size for non-text object. UTF8 size for text object */
    U32 drm_offset;
    U32 drm_size;
    U32 id;         /* For Syncing between umms xml and viewer xml structures */
    U16 drm_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN ];
	U16 reference_count;
    U16 *file_path; /* NULL terminator is needed. */
    U16 *file_name;
#ifdef __DRM_SUPPORT__
    drm_cid_struct *cid;
#endif 

    srv_mms_viewer_object_type_enum type;
#ifdef __DRM_SUPPORT__
    applib_mime_type_enum mime_type;
#endif 
    U8 drm_type;            /* mma_drm_type_enum */
    U8 encoding_scheme;
    U8 *mime_type_ext;      /* For Syncing between umms xml and viewer xml structures */
    U8 *content_id;         /* For Syncing between umms xml and viewer xml structures */
    U8 *content_location;   /* For Syncing between umms xml and viewer xml structures */
    MMI_BOOL consume_only_timed;
    MMI_BOOL rights_expired;
    MMI_BOOL is_drm_processed;
    MMI_BOOL is_virtual_file;
    /* WARNING:: sizeof(mmi_mv_object_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
} srv_mms_viewer_object_struct;
#endif /* (0) */ 

/* After XML Removal this structure should not be used anywhere */
#if(0)
typedef struct srv_mms_viewer_attachment_info_struct_t
{
    /* WARNING:: sizeof(mmi_mv_attachment_info_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    struct srv_mms_viewer_attachment_info_struct_t *next;
    struct srv_mms_viewer_attachment_info_struct_t *previous;
    srv_mms_viewer_object_struct *object;
    /* WARNING:: sizeof(mmi_mv_attachment_info_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
} srv_mms_viewer_attachment_info_struct;
#endif /* (0) */ 

typedef struct _srv_mms_viewer_use_details_list
{
    S32 offset;                                     /* offset to the highlighted text from beginning */
    S32 len;                                        /* length of the highlighted text, if -1, marker for head or tail */
    void *item;                                     /* only for application usage */
    struct _srv_mms_viewer_use_details_list *prev;  /* pointer to the previous highlighted text */
    struct _srv_mms_viewer_use_details_list *next;  /* pointer to the next highlighted text */
} srv_mms_viewer_use_details_list;

/* category 630 object area info structure */
/* After XML Removal this structure should not be used anywhere */
#if(0)
typedef struct
{
    S32 x;  /* preview x offset */
    S32 y;  /* preview y offset */
    S32 w;  /* preview width */
    S32 h;  /* preview height */
} srv_mms_viewer_object_area_struct;
#endif /* (0) */ 

/* All new typedefined due to XML Removal Activity */
typedef mma_mms_attachment_info_struct srv_mms_viewer_attachment_info_struct;
typedef mma_mms_object_area_struct srv_mms_viewer_object_area_struct;
typedef mma_mms_object_struct srv_mms_viewer_object_struct;
typedef mma_mms_slide_object_struct srv_mms_viewer_object_info_struct;
typedef mma_mms_slide_text_object_struct srv_mms_viewer_text_object_info_struct;
typedef mma_mms_slide_struct srv_mms_viewer_slide_struct;

/* After XML Removal this structure should not be used anywhere */
#if(0)
typedef struct
{
    U32 id; /* fill zero */
    U32 background_color;
    U32 foreground_color;
    PU16 alt_str;

    srv_mms_viewer_object_area_struct *area;

    U16 str_id;

    U16 begin;
    U16 end;
    srv_mms_viewer_font_style_enum txtStyle;
    U16 txtSize;
} srv_mms_viewer_text_object_info_struct;

typedef struct
{
    PU16 alt_str;
    U32 id;

    srv_mms_viewer_object_area_struct *area;

    U16 begin;
    U16 end;
} srv_mms_viewer_object_info_struct;


typedef struct srv_mms_viewer_slide_struct_t
{
/* WARNING:: sizeof(wgui_mv_slide_struct) affects MMI_MV_MMS_OBJECT_STRUCT_SIZE */
    struct srv_mms_viewer_slide_struct_t *next;
    struct srv_mms_viewer_slide_struct_t *previous;
    srv_mms_viewer_text_object_info_struct text;
    srv_mms_viewer_object_info_struct image;
    srv_mms_viewer_object_info_struct audio;
    srv_mms_viewer_object_info_struct video;
	U16 duration;
    U16 slide_num;
	MMI_BOOL show_attachment_icon;
} srv_mms_viewer_slide_struct;
#endif /* (0) */ 

typedef struct
{
    mma_mms_slide_struct *slide_head;
    mma_mms_slide_struct **current_slide;
    U64 msg_size;
    U32 background_color;
    U32 foreground_color;

    U16 slide_timing;

    U16 current_slide_num;
    U16 total_slide_num;
    MMI_BOOL show_attachment_icon;
    MMI_BOOL is_best_paging;
    srv_mms_viewer_slide_layout_enum layout;
} srv_mms_viewer_xml_msg_struct;
typedef struct
{
    srv_mms_addr_struct *to_head;           /* MMA structure//recheck */
    srv_mms_addr_struct *cc_head;
    srv_mms_addr_struct *bcc_head;
    srv_mms_addr_struct *from;
    mma_mms_slide_struct *slide_head;
    mma_mms_slide_struct *current_slide;
    mma_mms_object_struct **object_head;    /* single object structure */
    mma_mms_attachment_info_struct *attachment_head;
    U32 background_color;
    U32 foreground_color;
    U32 date;
    U32 msgsize;
    U32 download_size;
    U32 reported_msg_id;
    U32 delivery_time;                      /* mma_delivery_time_enum + java uses it for time in secs */
    U8 java_app_id[100 *ENCODING_LENGTH];
    U8 java_reply_app_id[100 *ENCODING_LENGTH];

    U16 subject[SRV_MMS_XML_MAX_SUBJECT_LEN + 1];
    U16 reported_subject[SRV_MMS_XML_MAX_SUBJECT_LEN + 1];
    U16 slide_timing;
    U16 email_num;
    U16 ph_num;
    U8 mms_version[SRV_MMS_VERSION_LEN];
    U8 to_num;
    U8 cc_num;
    U8 bcc_num;
    U8 priority;    /* mma_priority_enum */
    U8 expiry_time; /* mma_expiry_time_enum */
    U8 msgStatus;   /* mma_msg_status_enum */
    U8 msgclass;    /* mma_msg_class_enum */
    U8 total_slide_num;
    U8 current_slide_num;
    U8 total_object_num;
    U8 total_attachment_num;
    U8 total_addresses;
    U8 status;
    BOOL sender_visibility;
    BOOL read_report;
    BOOL delivery_report;
    /* mma_slide_layout_enum */ U8 layout;
} srv_mms_xml_msg_header_struct;

typedef struct
{
    U32 obj_iterator;
    srv_mms_viewer_attachment_info_struct *attachment_head;
    U16 total_object_num;       /* Number actually found */
    U16 reported_object_num;    /* Number reported by MMA used to allocate array of pointer for objs: srv_mms_viewer_object */
    U16 total_attachment_num;
} srv_mms_xml_msg_viewer_data_struct;

#ifdef __MMI_MV_SUPPORT_REF_ID__
#define MMI_MV_MAX_REF_ID_PER_SLIDE (5)
typedef struct _ref_id_list
{
    struct _ref_id_list *next;
    U32 ref_id;
    U32 background_color;
    U32 foreground_color;
    PU16 alt_str;

    U16 str_id;

    U16 begin;
    U16 end;
    srv_mms_viewer_font_style_enum txtStyle;
    U16 txtSize;
#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
    srv_mms_viewer_object_area_struct *region_area;
#endif 
} ref_id_list;

typedef ref_id_list *ref_id_list_pointer;
#endif /* __MMI_MV_SUPPORT_REF_ID__ */ 

typedef struct
{
    PU8 slide_txt_buffer;   /* final buffer with UCS2 encoding */
    PU8 src_buffer;         /* buffer with source encoding */
    PU8 inputbox_buffer;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    PU8 use_detail_buffer;
#endif 
    U32 ptxtbuffersize;
} srv_mms_xml_parser_context_struct;

#ifdef __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__
typedef struct _region_id_list_structure
{
    struct _region_id_list_structure *next;
    U16 region_id;
    srv_mms_viewer_object_area_struct *region_area;
} region_id_list_structure;
#endif /* __MMI_MMS_MV_SUPPORT_PARAM_OF_REGION__ */ 

typedef enum
{
    SRV_MMS_VIEWER_CHARSET_UNKNOWN,
    SRV_MMS_VIEWER_CHARSET_ASCII,
    SRV_MMS_VIEWER_CHARSET_ISO_8859_1,
    SRV_MMS_VIEWER_CHARSET_UTF8,
    SRV_MMS_VIEWER_CHARSET_UCS2,
    SRV_MMS_VIEWER_CHARSET_UTF16BE,
    SRV_MMS_VIEWER_CHARSET_UTF16LE,
    SRV_MMS_VIEWER_CHARSET_UTF16,
    SRV_MMS_VIEWER_CHARSET_GB2312,
    SRV_MMS_VIEWER_CHARSET_BIG5
} srv_mms_viewer_charset_enum;

typedef struct
{

    U32 req_id;
    S32 vf_handle;                                  /* parent file handle for any vf used */
    U16 vfname[SRV_MMS_VIEWER_VFN_NUM_OF_WCHAR];    /* VF Filename */
    U8 serial;                                      /* current serial from DRM Engine: can use to cancel */
} srv_mms_drm_process_cntx_struct;

typedef srv_mms_viewer_object_struct *p_srv_mms_viewer_object;

typedef struct
{
    mma_mms_slide_struct *slide;
    U32 obj_count;
} srv_mms_viewer_obj_container_struct;

/* This enum defines the mode of xml parsing is required in srv_mms_parse_xml */

//extern S32 mmi_umms_jsr_add_object_in_xml(mmi_umms_object_struct *object, FS_HANDLE fh);
//extern S32 mmi_umms_jsr_create_mms_xml_header(mmi_umms_xml_msg_struct *umms_msg, FS_HANDLE fh);
#endif /* __MMI_MMSXMLDEF_H__ */ 
#endif /* __MMI_MMS_2__ */ 

