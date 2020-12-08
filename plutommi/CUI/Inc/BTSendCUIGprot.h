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
 * btsendcuigprot.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_SEND_CUI_GPROT_H__
#define __BT_SEND_CUI_GPROT_H__

#include "MMI_features.h"
#include "BtcmSrvGprot.h"
/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR add end */
/* sending mode enum, now we only support CUI_BT_SENDIND_USE_FILE */
typedef enum
{
    CUI_BT_SENDIND_USE_BUFF,                        /* send a block of buffer, now we do not support */
    CUI_BT_SENDIND_USE_FILE                         /* send an object, now we only support this kind of sending  */
} cui_bt_sending_obj_enum;

/* sending option enum */
typedef enum
{
    CUI_BT_SENDIND_OPT_NORMAL,                      /* it means we should select a device to send */
    CUI_BT_SENDIND_OPT_DEFAULT_DEVICE,              /* it means to send the object to the default device */
    CUI_BT_SENDIND_OPT_SPECIFIC_DEVICE,             /* it means to send the object to the specific device */
    CUI_BT_SENDIND_OPT_END                          /* enum ending, means nothing */
} cui_bt_sending_opt_enum;

/* sending cui event, for single sending, there is no EVT_ID_CUI_BT_SENDING_DONE event */
typedef enum {
	EVT_ID_CUI_BT_SENDING_SUCC = OPP_BASE+1,        /* When the object is sent successfully, BT sending CUI will post this event to AP's screen group */
	EVT_ID_CUI_BT_SENDING_FAIL,                     /*The object fail to be sent, AP will get this event */
	EVT_ID_CUI_BT_SENDING_DONE                      /* When sending ends, AP will get this event, and it should close BT Sending CUI */
} cui_bt_sending_evt_enum;

/* object type struct */
typedef struct
{
    U8 mime_type;                                   /* mime type */
    U16 mime_subtype;                               /* mime subtype */
    CHAR *mime_string;                              /* mime string */
} cui_bt_sending_obj_type_struct;

/* buffer struct, it is not be used now */
typedef struct {
    void* addr;                                     /* buffer's address */
    U32 length;                                     /* buffer's length */
} cui_bt_sending_obj_buff_struct;

/* file struct */
typedef struct {
    WCHAR* path;                                    /* file path, AP must give the path of the file to be sent, it can not be NULL */
    MMI_BOOL is_sfn;                                /* if short name, MMI_TRUE for short name */
} cui_bt_sending_obj_file_struct;  

/* file or buffer union */
typedef union {
    cui_bt_sending_obj_buff_struct buff;            /* send buffer, now we do not support */
    cui_bt_sending_obj_file_struct file;            /* send a file */
                               
} cui_bt_sending_obj_data_union;

/* object detail struct */
typedef struct
{
    cui_bt_sending_obj_enum obj_type;               /* object type */
    cui_bt_sending_obj_data_union u;                /* file or buffer */

} cui_bt_sending_obj_data_struct;

/* sending object struct */
typedef struct
{
    WCHAR *name;                                    /* object name, we do not use it now */
    cui_bt_sending_obj_type_struct type;            /* optional, if absent, file extension will be used to parse mime type */
    cui_bt_sending_obj_data_struct data;            /* object detail, it is the most important info of the sending object */
} cui_bt_sending_obj_struct;

/* sending para */
typedef struct {
    U16 total;                                      /* total sending objects count */
    cui_bt_sending_opt_enum option;                 /* It shows which device the object will be sent */
    srv_bt_cm_bt_addr addr;                         /* device address, when option is SPECIFIC DEVICE, this addr will be used */
    cui_bt_sending_obj_struct *obj;                 /* sending object, can not be NULL */
} cui_bt_sending_para_struct;

/* cui event struct */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    S32 data;                                      /* data for ap, now it is not used */
} cui_bt_sending_evt_struct;

#ifdef __MMI_OPP_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  cui_bt_send_create
 * DESCRIPTION
 *  Normal BT sending CUI API. 
 *  It is mainly used for multiple sending, it can also used for single sending.
 *  It must be used together with cui_bt_sending_run, cui_bt_sending_continue and cui_bt_sending_close.
 *  It is used to create a BT sending CUI with AP's screen group ID. 
 *  When AP begin to perform sending, this API must be invoked. 
 *  It will return the handle sending cui.
 * PARAMETERS
 *  parent_id:              [IN]  ap's screen group id, it is the parent id of BT sending CUI
 * RETURNS
 *  bt sending cui group id
 *****************************************************************************/
extern MMI_ID cui_bt_sending_create(MMI_ID parent_id);


/*****************************************************************************
 * FUNCTION
 *  cui_bt_send_run
 * DESCRIPTION
 *  Normal BT sending CUI API. 
 *  It is mainly used for multiple sending, it can also used for single sending.
 *  It must be used together with cui_bt_sending_create, cui_bt_sending_continue and cui_bt_sending_close.
 *  It should be invoked after cui_bt_sending_create function returning a positive number.
 *  It is used to start sending cui and send the first object. 
 *  It has no return value, but after AP calls this API, AP's screen group will receive EVT_ID_CUI_BT_SEND_SUCC or EVT_ID_CUI_BT_SEND_FAIL event.
 * PARAMETERS
 *  id:                      [IN]  CUI's handle, it comes from sender_id of every event posted by sending CUI 
 *  para:                   [IN]  sending cui para including object count, addr, option and object info, it can not be NULL.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_bt_sending_run(MMI_ID id, const cui_bt_sending_para_struct *para);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_continue
 * DESCRIPTION
 *  Normal BT sending CUI API. 
 *  It is mainly used for multiple sending, it can also used for single sending.
 *  It must be used together with cui_bt_sending_create, cui_bt_sending_run and cui_bt_sending_close.
 *  It is used when AP need to send more than one object. 
 *  It should be invoked when AP's screen group received EVT_ID_CUI_BT_SEND_SUCC or EVT_ID_CUI_BT_SEND_FAIL event to send next object. 
 *  But when AP there is no mort object to be sent, it can ignore EVT_ID_CUI_BT_SEND_SUCC or EVT_ID_CUI_BT_SEND_FAIL event. 
 * PARAMETERS
 *  id:                     [IN]  CUI's handle, it comes from sender_id of every event posted by sending CUI 
 *  obj:                   [IN]  Sending Object information:like object path object length etc.
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_bt_sending_continue(MMI_ID id, const cui_bt_sending_obj_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_close
 * DESCRIPTION
 *  Normal BT sending CUI API. 
 *  It is mainly used for multiple sending, it can also used for single sending.
 *  It must be used together with cui_bt_sending_create, cui_bt_sending_run and cui_bt_sending_continue.
 *  It is used to close BT sending CUI. 
 *  AP must call this function when receiving EVT_ID_CUI_BT_SEND_DONE event.
 *  AP also can call this function when an exception occurs to quit sending.
 * PARAMETERS
 *  id:                    [IN]  CUI's handle, it comes from sender_id of every event posted by sending CUI 
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_bt_sending_close(MMI_ID id);

/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_launch
 * DESCRIPTION
 *  Launch BT sending CUI API. 
 *  It is used for single sending.
 *  It is the unique API of single sending, there are no create, run and close APIs. 
 *  When sending ends, the EVT_ID_CUI_BT_SEND_SUCC or EVT_ID_CUI_BT_SEND_FAIL event will be posted to tell AP whether the object has successfully been sent.
 *  AP can also ignore these events.
 * PARAMETERS
 *  parent_id:          [IN]  ap's screen group id, it is the parent id of BT sending CUI
 *  para:                 [IN]  sending cui para including object count, addr, option and object info
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_bt_sending_launch(MMI_ID parent_id, const cui_bt_sending_para_struct *para);

#endif /*__MMI_OPP_SUPPORT__*/
#endif /* __BT_MMI_OBEX_GPROTS_H__ */ 

