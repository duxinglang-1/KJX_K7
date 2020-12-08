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
 * OppSrv.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
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
#ifndef __SRV_BIP_GPROT_H__
#define __SRV_BIP_GPROT_H__

#include "MMI_features.h"
#ifdef __MMI_BIP_SUPPORT__

#include "bluetooth_struct.h"
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "kal_general_types.h"

/*bip service return result, it indicates the service can use*/
#define SRV_BIP_RESULT_OK       0

/*bip service return result, it indicates the mmi use the handle is invalid*/
#define SRV_BIP_RESULT_INVALID_HANDLE  -1

/*bip service return result, it indicates user set the parameter not right*/
#define SRV_BIP_RESULT_INVALID_PARAM   -2

/*bip service return result, it indicates service currently is busy*/
#define SRV_BIP_RESULT_STATE_BUSY  -3

/*max file name used in bip*/
#define BIP_MAX_FILE_NAME_LEN      BT_BIP_MAX_IMG_NAME_LEN

/*max device name, the name is display on when authorize ind received*/
#define MAX_DEV_NAME  80

/*default object name, if tranfered the obj does not name, will use it*/
#define BIP_SND_DEFAULT_OBJNAME L"Noname"

/*bip service event: if want to know bip register message, it should care this event*/
#define SRV_BIP_EVENT_START     0x00000001

/*bip service event: if want to know bip deregister message, it should care this event*/
#define SRV_BIP_EVENT_STOP      0x00000002

/*bip service event: if want to know bip connect result, it should care this event*/
#define SRV_BIP_EVENT_CONN_NOTIFY   0x00000004

/*bip service event: if want to know bip get capability result, it should care this event*/
#define SRV_BIP_EVENT_GET_CAPABILITY_NOTIFY  0x00000008

/*bip service event: if want to know bip send result, it should care this event*/
#define SRV_BIP_EVENT_SND_NOTIFY    0x000000010

/*bip service event: if want to know bip disconnect result, it should care this event*/
#define SRV_BIP_EVENT_DISCONN_NOTIFY   0x00000020

/*bip service event: if want to know bip authorizes event, it should care this event*/
#define SRV_BIP_EVENT_AUTHORIZE_NOTIFY  0x00000040

/*bip service event: if want to know bip received event, it should care this event*/
#define SRV_BIP_EVENT_RECV_NOTIFY   0x00000080

/*bip service event: when generate thumbnail, server do not memory to put it, so memory get from mmi*/
#define SRV_BIP_EVENT_GET_MEMORY_NOTIFY   0x00000100

/***************************************************************************** 
* enum
*****************************************************************************/

/*****************************************************************************
 *  bip role enum: bip has initiator and responder role
*****************************************************************************/
typedef enum
{
    SRV_BIP_INITIATOR_ROLE = 0x01,    /*initiator role*/
    SRV_BIP_RESPONDER_ROLE = 0x02     /*responder role*/
} srv_bip_role_enum;


/*****************************************************************************
 *  bip responder received file error type
*****************************************************************************/
typedef enum
{
    SRV_BIP_PUT_TYPE,        /* put type*/
    SRV_BIP_DRM,             /* DRM protected file*/
    SRV_BIP_DISK_FULL,       /* disk full*/
    SRV_BIP_ROOT_DIR_FULL,   /* root dir full*/
    SRV_BIP_DEVICE_BUSY,     /* device busy*/
    SRV_BIP_MEDIA_CHANGED,   /* memeory card removed*/
    SRV_BIP_WRITE_PROTECT,   /* disk write protected*/
    SRV_BIP_WRITE_FAIL,      /* other reason*/
    SRV_BIP_ALL_ERR_END
} srv_bip_err_enum;


/*****************************************************************************
 *  bip initator connect result type
*****************************************************************************/
typedef enum
{
    SRV_BIP_CONN_SUCC,       /* connect success*/
    SRV_BIP_CONN_FAILED,     /* conn failed maybe some reason exclude user abort */
    SRV_BIP_CONN_SCO_REJECT, /*because SCO exist result in connection failed*/
    SRV_BIP_CONN_END
} srv_bip_conn_type_enum;

/*****************************************************************************
 *  bip initator send file result type
*****************************************************************************/
typedef enum
{
    SRV_BIP_SND_READY,           /*when connect success, will notify mmi*/
    SRV_BIP_SND_SUCC,            /*when send success, will notify mmi*/
    SRV_BIP_SND_FAIL,            /*when send failed, will notify mmi*/
    SRV_BIP_SND_FAIL_BY_SERVER,  /*when send failed by server reject, will notify mmi*/
    SRV_BIP_SND_PERSENT,         /*when send file begin, will notify mmi, mmi need update progress*/
    SRV_BIP_SND_PARTIAL_CONTENT, /*when send thumbnail, will notify mmi*/
    SRV_BIP_SND_DONE,            /*when send finished, will notify mmi*/
    SRV_BIP_SND_END
} srv_bip_snd_type_enum;

/*****************************************************************************
 *  bip initator get capability result type
*****************************************************************************/
typedef enum
{
    SRV_BIP_CAPABILITY_SUPPORT,         /*if server support this format image*/
    SRV_BIP_CAPABILITY_UNSUPPORT,       /*if server unsupport this format image*/
    SRV_BIP_CAPABILITY_FAIL,            /*client get capability failed*/
    SRV_BIP_CAPABILITY_END
}srv_bip_capability_enum;

/*****************************************************************************
 *  bip responder receive file result type
*****************************************************************************/
typedef enum
{
    SRV_BIP_RECV_READY,            /*received push thumbnail ind  */
    SRV_BIP_RECV_BEGIN,            /*received push image ind*/
    SRV_BIP_RECV_SUCCESS,          /*received file success*/
    SRV_BIP_RECV_FAIL,             /*received file fail*/
    SRV_BIP_RECV_END
} srv_bip_recv_type_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/

/*****************************************************************************
 *  bip image sent information struct:
*****************************************************************************/
typedef struct
{
    U32 total_obj_size;        /*object total size*/
    U32 sent_size;             /*already sent size*/
} srv_bip_img_info_struct;

/*****************************************************************************
 *  bip image detail information struct:
*****************************************************************************/
typedef struct
{
    U32 total_len;                           /*image total len*/
    U16 name[BT_BIP_MAX_IMG_NAME_LEN];       /*image name*/
    U8 encoding;                             /*image encoding*/
}srv_bip_obj_detail_struct;

/*****************************************************************************
 *  bip initiator connect struct:
*****************************************************************************/
typedef struct
{
    U8 type;                      /*connect result*/
    U32 conn_id;                  /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;    /* server UI used to notify cm, */
    //U8 dev_name[MAX_DEV_NAME];  /* server UI used, if not paired device, ui use the it */
} srv_bip_conn_notify_struct;

/*****************************************************************************
 *  bip initiator disconnect struct:
*****************************************************************************/
typedef struct
{
    U32 conn_id;                  /*cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;    /*disconnect bt address*/
} srv_bip_disconn_notify_struct;

/*****************************************************************************
 *  bip initiator send struct:
*****************************************************************************/
typedef struct
{
    U8 type;                            /*send result*/
    S32 err_code;                       /*send fail reason*/
    union
    {
        srv_bip_img_info_struct info;
    }u;
} srv_bip_snd_notify_struct;

/*****************************************************************************
 *  bip initiator get capability struct:
*****************************************************************************/
typedef struct
{
    U8 type;                /*get capability result type*/
}srv_bip_capability_notify_struct;

/*****************************************************************************
 *  bip initiator authorize  struct:
*****************************************************************************/
typedef struct
{
    U32 conn_id;                /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;
    U8 dev_name[MAX_DEV_NAME];  /* server UI used, if not paired device, ui use the it */
} srv_bip_authorize_notify_struct;

/*****************************************************************************
 *  bip initiator received struct:
*****************************************************************************/
typedef struct
{
    U8 type;                     /*received type, success or failed reason*/
    U32 conn_id;                 /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;    /* bt address */
    union
    {
        srv_bip_obj_detail_struct detail;
        S32 err_code;
    }u;
}srv_bip_recv_notify_struct;

/*****************************************************************************
 *  bip initiator generate thumbnail , but not memory, so memory is get from mmi:
*****************************************************************************/
typedef struct
{
    U32 buf_size;             /*memory size*/
}srv_bip_get_memory_notify_struct;

/*****************************************************************************
 *  notify callback, when service happened some event,and will use the callback
 *  to notify the user who care the events
 *    srv_hd:  [in] it indicates who register the callback, it is sole
 *    event: [in] it indicates the app care what event
 *    para: [in] if mmi does not want to record some data, it can send to service,
 *               when service finished one event, will give the data to mmi also.
 *
*****************************************************************************/
typedef S32(*bt_notify) (S32 srv_hd, U32 event_id, void *para);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_bip_init
 * DESCRIPTION
 *  init bip service, it will initialize variable
 * PARAMETERS
 *  vaoid      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bip_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_deinit
 * DESCRIPTION
 *  deinit bip, when bt power off, will deinit it
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bip_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_open
 * DESCRIPTION
 *  open a bip service
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  srv_hd : return a hanlder to record who open the pbap
 *****************************************************************************/
extern S32 srv_bip_open(U8 role);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_close
 * DESCRIPTION
 *  close bip service
 * PARAMETERS
 *  srv_hd      : [IN] which want to close pbap
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_bip_close(S32 srv_hd);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_set_notify
 * DESCRIPTION
 *  mmi set owner callback and event to service
 * PARAMETERS
 *  srv_hd      : [IN]record who use the pbap
 *  event_mask  : [IN] MMI care the event
 *  notifier    : [IN] MMI register callback
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern S32 srv_bip_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_cancel
 * DESCRIPTION
 *  when client send file process, if mmi want to cancel the send, use it,
 *  now it used by usb mass storage
 * PARAMETERS
 *  flag      : [IN] which reason cancel the send
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_bip_send_cancel(U32 flag);

/* client external API */

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_send_begin
 * DESCRIPTION
 *  when connection not exit, and client want to send file, will use it, 
 *  first it will setup connection 
 * PARAMETERS
 *  srv_hd      : [IN] who use the service
 *  bd_addr     : [IN] which device to received the file
 *  bip_service : [IN] initiator or responder to send
 * RETURNS
 *  S32       : [OUT] indicate the result
 *****************************************************************************/
extern S32 srv_bipi_send_begin(S32 srv_hd, srv_bt_cm_bt_addr *bd_addr, bt_bip_service_enum bip_service);

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_send_img
 * DESCRIPTION
 *  when connection setup, will use it to send the image to responder
 * PARAMETERS
 *  srv_hd      : [IN] who use the service
 *  path        : [IN] the full path of the sent file, it used to get file data
 *  name        : [IN] maybe the name is longer than service buffer, so truncated it
 * RETURNS
 *  S32         : [OUT] return the function current state
 *****************************************************************************/
extern S32 srv_bipi_send_img(S32 srv_hd, U16 *path, U16 *name);

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_send_end
 * DESCRIPTION
 *  when client send file end, it use to disconnect the connection 
 *  between initiator and responder
 * PARAMETERS
 *  srv_hd      : [IN] who send end
 * RETURNS
 *  S32         : [OUT] currently the service state
 *****************************************************************************/
extern S32 srv_bipi_send_end(S32 srv_hd); 


/* server external API */

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_activate
 * DESCRIPTION
 *  activate the bip server
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern void srv_bipr_activate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_deactivate
 * DESCRIPTION
 *  deactivate the bip, if deactive, pbab server will not be used
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern void srv_bipr_deactivate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_accept
 * DESCRIPTION
 *  bip server accept connection from pbap client
 * PARAMETERS
 *  app_id      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_bipr_accept(S32 srv_hd, U32 conn_id, U16 *path);

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_reject
 * DESCRIPTION
 *  bip server reject connection from pbap client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_bipr_reject(S32 srv_hd, U32 conn_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_disconn_client
 * DESCRIPTION
 *  bip server disconnect client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 *  conn_id     : [IN] pbap server disconnect client
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_bipr_disconn_client(U32 srv_hd, U32 conn_id);


/* query status func */

/*****************************************************************************
 * FUNCTION
 *  srv_bip_is_run
 * DESCRIPTION
 *  bip responder state more than authorize, initiator send the file, it also bip run
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  MMI_BOOL  : [OUT] bip is run return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bip_is_run(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_is_receiving
 * DESCRIPTION
 *  bip responder is receiving image or initiator is sending image
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  MMI_BOOL  : [OUT] bip is receiving return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bip_is_receiving(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_is_idle
 * DESCRIPTION
 *  bip state whether in idle
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  MMI_BOOL  : [OUT] bip is in idle return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bipi_is_idle(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_is_sending
 * DESCRIPTION
 *  bip initiator to send file, including connecting and get capability
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  MMI_BOOL  : [OUT] bip is sending return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bipi_is_sending(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_is_working
 * DESCRIPTION
 *  bip responder state not in idle
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  MMI_BOOL  : [OUT] bip responder is doing things return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bipr_is_working(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_get_obj_info
 * DESCRIPTION
 *  this function can get image sending information
 * PARAMETERS
 *  obj_info      :  [OUT] object send info will write the buffer 
 * RETURNS
 *  void  : 
 *****************************************************************************/
extern void srv_bipi_get_obj_info(srv_bip_img_info_struct *obj_info);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_is_imagefile
 * DESCRIPTION
 *  justify whether the sending file is image or not, if Yes, will send by BIP
 * PARAMETERS
 *  obj_name      :  [IN] Object name used to justify the object type
 * RETURNS
 *  MMI_BOOL  : [OUT] if image return MMI_TRUE, otherwise return MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_bip_send_is_imagefile(void * obj_name);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_image_type_from_cntx
 * DESCRIPTION
 *  through file content to get the image type
 * PARAMETERS
 *  pathfileName      :  [IN]file full path
 * RETURNS
 *  bt_bip_img_format_enum  : [OUT] image format like jpeg, gif, bmp
 *****************************************************************************/
extern bt_bip_img_format_enum srv_bip_get_image_type_from_cntx(U16 *pathfileName);

/*****************************************************************************
 * FUNCTION
 *  srv_bip_truncate_obj_name
 * DESCRIPTION
 *  maybe the src_name is longer than buffer, so need truncate it
 * PARAMETERS
 *  dst_name      : [OUT] truncated name
 *  src_name      : [IN] source name
 *  max_dst_len   : [IN] destination name length
 *  convert_flag  : [IN] whether need convert the byte endian
 * RETURNS
 *  void  : 
 *****************************************************************************/
extern void srv_bip_truncate_obj_name(U16 *dst_name, U16 *src_name, U16 max_dst_len, MMI_BOOL convert_flag);
#ifdef __cplusplus
}
#endif



#endif /* __SRV_OPP_GPROT_H__ */ /* __SRV_OPP_GPROTS_H__ */
#endif /* __MMI_OPP_SUPPORT__ */ 

