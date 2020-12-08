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
 *  jwa_internal.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JWA_INTERNAL_H
#define _JWA_INTERNAL_H

extern char j2me_sms_smsc_addr[];
extern kal_char j2me_mms_mmsc_addr[];
extern pBOOL mmi_bootup_is_sim_valid(void);

typedef struct
{
    kal_uint8 priority; /* WAP_MMS_PRIORITY_LOW:0,  WAP_MMS_PRIORITY_MED: 1, WAP_MMS_PRIORITY_HIGH: 2 */
    kal_uint8 from_addr_no;
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint64 date;
    kal_uint8 start_cnt_id_len;
    kal_uint8 *start_cnt_id;
    kal_uint8 reply_app_id_len;
    kal_uint8 *reply_app_id;
    kal_uint16 peer_buffer_len;
    kal_uint8 *peer_buffer;
} J2me_mms_recv_struct;

typedef struct
{
    kal_uint8 encoding_scheme;
    kal_uint8 content_type_len;
    kal_uint8 *content_type;
    kal_uint8 content_id_len;
    kal_uint8 *content_id;
    kal_uint8 content_location_len;
    kal_uint8 *content_location;
    kal_uint8 filepath_len;
    kal_wchar *filepath;
    kal_uint32 file_size;
} J2me_mms_recv_part_struct;

typedef struct
{
    kal_int32 serial_number;
    kal_uint8 app_id_len;
    kal_uint8 *app_id;
} J2me_mms_registered_appid_struct;

typedef struct
{
    kal_uint8 number_len;
    kal_uint8 *number;
} J2me_mms_local_address_struct;

extern kal_uint64 J2ME_mms_get_message_sent_time(void);

extern void J2ME_mms_response_handler(ilm_struct *ilm_ptr);
extern void finalizeMms(void);
#if (MAX_VM_INSTANCE_NUM > 1)
extern void finalizeMmsByVM(int vm_id);
#endif
extern BOOL is_mms_activated(void);
extern void J2ME_mms_process_pending_task_by_controller(void);
extern kal_int32 jwa_mms_initialize_vm(kal_int32 vm_id);
extern kal_int32 jwa_mms_finalize_vm(kal_int32 vm_id);

/* ////////////////////////////////////////////////////////////////////////// */
typedef struct
{
    kal_uint16 port;
    kal_uint16 number;
} J2me_sms_recv_num_struct;
extern int j2me_check_push_register_port(int port, int type, int vm_id);
extern void* push_process_recvd_sms_ind(int port);
extern void* j2me_process_recvd_sms_ind(ilm_struct *ilm_ptr);
extern void* j2me_process_recvd_mms_ind(ilm_struct *ilm_ptr);
extern void* push_process_recvd_mms_ind(char *application_id);
extern void J2ME_sms_free_data(void);
extern void finalizeSms(void);
#if (MAX_VM_INSTANCE_NUM > 1)
extern void finalizeSmsByVM(int vm_id);
#endif
extern void J2ME_sms_response_handler(ilm_struct *ilm_ptr);
extern int J2ME_sms_register(long portNumber, int type);
extern int J2ME_sms_unregister(long portNumber, int type);
extern int J2ME_sms_unregister_by_push(long portNumber, int type);
extern void J2ME_sms_unregister_all(void);
extern int J2ME_sms_unregister_by_resource_manager(int portNumber);
extern void *j2me_process_recvd_sms_ind(ilm_struct *ilm_ptr);
extern unsigned short *J2ME_sms_getHostAddr(int *len);
extern void jwa_sms_set_state(int state);
extern kal_bool is_sms_activated(void);
extern void jwa_sms_get_smsc_addr_handler(ilm_struct *ilm_ptr);
extern void J2ME_sms_init(void);
extern void J2ME_sms_process_pending_task_by_controller(void);
extern kal_int32 jwa_sms_initialize_vm(kal_int32 vm_id);
extern kal_int32 jwa_sms_finalize_vm(kal_int32 vm_id);

#endif /* _JWA_INTERNAL_H */ 

