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
 *  MMSJSRSrvSndRcv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the constants & function prototypes used in sending Java mms
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JSR_SNDRCV_H
#define _JSR_SNDRCV_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "MMIDataType.h"        /* Use MMI_TRUE/MMI_FALSE in place of TRUE/FALSE respectively */
#include "MmsXMLDefSrv.h"
#include "mmc_struct.h"

// #define MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER    (2000)
#define SRV_MMS_JSR_DEFAULT_BG_COLOR               (mma_get_default_smil_bg_color())
#define SRV_MMS_JSR_DEFAULT_FG_COLOR               (mma_get_default_smil_fg_color())
#define SRV_MMS_JSR_DEFAULT_READ_REPORT_DURING_SENDING         MMI_FALSE
#define SRV_MMS_JSR_DEFAULT_DELIVERY_REPORT_DURING_SENDING     MMI_FALSE
#define SRV_MMS_JSR_DEFAULT_EXPIRY_TIME                     MMA_EXPIRY_MAX
#define SRV_MMS_JSR_DEFAULT_SENDER_VISIBILTY             MMI_TRUE
//#define SRV_MMS_JSR_DEFAULT_DELIVERY_TIME                MMA_DELIVERY_IMMEDIATE
//#define SRV_MMS_JSR_DEFAULT_SLIDE_DURATION                  5000

#define SRV_MMS_JSR_MAX_SUBJECT_LEN             (40)

#define SRV_MMS_JSR_SUBJECT_ENCODED_VALUE           106

//#define MMI_UMMS_MAKE_MMS_XML_FILE_PATH(x, d)   \
   //kal_wsprintf( (kal_uint16 *)x, "%c:\\_UC\\template.xml",SRV_FMGR_PUBLIC_DRV);

extern U8 srv_mms_jsr_insert_slide(srv_mms_viewer_object_struct *obj, srv_mms_viewer_object_type_enum type);
extern U8 srv_mms_jsr_add_address_in_addresse_list(
            S8 *address,
            srv_mms_address_type_enum type,
            srv_mms_address_group_type_enum group);

extern U8 srv_mms_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message);
extern U8 srv_mms_jsr_insert_text_object(wap_mmc_post_appmms_msg_part_res_struct *message, U8 *media_buffer_p);
extern U8 srv_mms_jsr_insert_object(
            wap_mmc_post_appmms_msg_part_res_struct *message,
            srv_mms_viewer_object_type_enum type);
extern U8 srv_mms_jsr_insert_slide(srv_mms_viewer_object_struct *obj, srv_mms_viewer_object_type_enum type);

/* extern void srv_mms_jsr_reset_msg(void); */
extern void srv_mms_jsr_reset_xml_struct_msg(void);
extern void srv_mms_jsr_create_mms_req(void);

/* extern void srv_mms_jsr_send_mms_req(U16 msg_id); */
extern U8 srv_mms_jsr_fill_text_data(U16 *file_path, U16 *subject);
extern void srv_mms_jsr_create_for_send_mms_rsp(void *inMsg);

/* S32 mmi_umms_create_mms_xml_description_file(mmi_umms_xml_msg_struct *umms_msg, U8* file_path); */
extern void srv_mms_jsr_get_msg_content_req(void);
extern mmc_result_enum srv_mms_jsr_decode_mms_header(wap_mmc_send_appmms_req_struct *message, U8 *buffer);
extern void srv_mms_jsr_reset_get_content_struct_mem(void);

#endif /* __MMI_MMS_2__ */ 
#endif /* _JSR_SNDRCV_H */ 

