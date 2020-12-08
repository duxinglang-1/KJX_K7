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
 *  PhoneBookPBAP.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_PBAPC_H__
#define __SRV_PBAPC_H__

#include "MMI_features.h"
  
#ifdef __MMI_BT_SUPPORT__

#ifdef __BT_PBAP_CLIENT__ 

#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "bluetooth_struct.h"
#include "fs_type.h"
#include "custom_phb_config.h"
#include "BtcmSrvGprot.h"
#include "PbapSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "xml_def.h"


#define SRV_PBAPC_MAX_HANDLE_NUM  2
#define MMI_PBAPC_INVALID_REQ_ID   0xFF
#define MMI_PBAPC_INVALID_CONN_ID  0xFF
#define SRV_PBAPC_SEND_FAIL -1

typedef enum
{
    SRV_PBAPC_STATE_IDLE,
	  SRV_PBAPC_STATE_ENABLE,
    SRV_PBAPC_STATE_OPEN,      
    SRV_PBAPC_STATE_AUTHORISE,               
    SRV_PBAPC_STATE_AUTHORIZED,				
    SRV_PBAPC_STATE_CONNECTING1,
    SRV_PBAPC_STATE_CONNECTING2,
    SRV_PBAPC_STATE_CONNECTED,
    SRV_PBAPC_STATE_SETTING_PATH,
    SRV_PBAPC_STATE_PATH_SET,  			
    SRV_PBAPC_STATE_READ_FOLDER,                        
    SRV_PBAPC_STATE_READ_ENTRY,           
    SRV_PBAPC_STATE_READ_LIST,               
    SRV_PBAPC_STATE_DISCONECTTING, 
    SRV_PBAPC_STATE_DISCONECTED,  
    SRV_PBAPC_STATE_CLOSE
} srv_pbapc_state_enum;

 

#define SRV_PBAPC_LOG(x)                                                             \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);                                             \
   }
#define SRV_PBAPC_LOG1(x, x1)                                                        \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);                                         \
   }
#define SRV_PBAPC_LOG2(x, x1, x2)                                                    \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);                                     \
   }
#define SRV_PBAPC_LOG3(x, x1, x2, x3)                                                \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);                                 \
   }
#define SRV_PBAPC_LOG4(x, x1, x2, x3, x4)                                            \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4);                             \
   }
#define SRV_PBAPC_LOG6(x, x1, x2, x3, x4, x5, x6)                                    \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6);                     \
   }
#define SRV_PBAPC_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                                \
   {                                                                                \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6, x7);                 \
   }


#define MMI_PBAPC_AUTH_UI_BUFF_SIZE       (102)   /* "Password Exchange("device_name"):" + NULL = 50*2 + 2 */
#define MMI_PBAPC_AUTH_INPUT_BUFF_SIZE    (34)    /* (GOEP_MAX_PASSWD_SIZE + 1)*2 */

typedef struct {
	U16 username[MMI_PBAPC_AUTH_INPUT_BUFF_SIZE];
	U16 pasword[MMI_PBAPC_AUTH_INPUT_BUFF_SIZE];
}btpbap_client_auth_struct;



typedef struct {

	btpbap_client_auth_struct* auth_struct;  //For authetication if PSE demands
	int result  ;         //Result to trturn to PHBSRV
	srv_bt_cm_bt_addr addr;//Bt Address
} bt_pbap_client_cntx_struct ;

typedef struct {
	U8 goep_conn_id;    //Returned after connect request
	srv_pbapc_state_enum state;  //state
	srv_bt_cm_bt_addr bt_device; //Device Address for connect request
	U32 cm_conn_id;    //From Connection Manager
	U8 set_path;
	int phb_srv_hd;		 //Service handler to PHBSRV 
	bt_pbap_client_callback bt_pbap_callback_func;  //Callback Function
}srv_pbapc_cntx_struct;

extern void srv_pbapc_readlist_cnf_hdlr(void * ilm_ptr);

typedef struct {
	srv_pbapc_cntx_struct pbapc_cntx;
}srv_pbapc_context_struct;

extern srv_pbapc_context_struct *srv_pbap_c;

#define SRV_PBAPC_STATE_TRANS(x)      srv_pbap_c->pbapc_cntx.state = (x)   

/*XML PARSING Contexts*********************************************************/

#define PBAP_XML_ELEMNT_VCARD 		  "card"
#define PBAP_XML_ELEMNT_VCARD_VERSION "vCard-listing"
#define PBAP_XML_ELEMNT_HANDLE 		  "handle"
#define PBAP_XML_ELEMNT_NAME		  "name"



#define PBAP_XML_PARSE_MAX_NUM 	 100
#define PBAP_XML_PARSE_INCREMENT 10

#define PCE_DEFINED

/*pbap service return result, it indicates the service can use
*/
#define SRV_PBAP_RESULT_OK            0
/*pbap service return result, it indicates the service currently can not used*/
#define SRV_PBAP_RESULT_INVALID_HANDLE  -1

/*pbap service return result, it indicates user set the parameter not right*/
#define SRV_PBAP_RESULT_INVALID_PARAMETERS        -2

/*pbap service return result, it indicates service currently is busy*/
#define SRV_PBAP_RESULT_BUSY        -3

/*pbap service event: if want to know pbap register message, it should care this event*/
#define SRV_PBAP_EVENT_START    0x0001

/*pbap service event: if want to know pbap deregister message, it should care this event*/
#define SRV_PBAP_EVENT_STOP    0x0002

/*pbap service event: if want to know pbap authorize message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHORIZE_NOTIFY  0x0004

/*pbap service event: if want to know pbap authentication message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY    0x0008

/*pbap service event: if want to know pbap connect message, it should care this event*/
#define SRV_PBAP_EVENT_CONN_NOTIFY   0x0010

/*pbap service event: if want to know pbap disconnect message, it should care this event*/
#define SRV_PBAP_EVENT_DISCONN_NOTIFY   0x0020



/*pbap service return result, it indicates the service can use*/
#define SRV_PBAPC_RESULT_OK            0

#define SRV_PBAPC_OPEN  1

/*pbap service return result, it indicates the service currently can not used*/
#define SRV_PBAPC_RESULT_INVALID_HANDLE  -1

/*pbap service return result, it indicates user set the parameter not right*/
#define SRV_PBAPC_RESULT_INVALID_PARAMETERS        -2

/*pbap service return result, it indicates service currently is busy*/
#define SRV_PBAPC_RESULT_BUSY        -3


void srv_pbapc_cntx_init(void);
void srv_pbapc_enable_req(void);
void srv_pbapc_disable_req(void);
void srv_pbapc_disconnect_req(U32 conn_id);
void srv_pbapc_abort_req(pbap_set_folder_type_enum folder_type,U16 * name);
void srv_pbapc_close(S32 srv_hd);
void srv_pbapc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error);
void srv_pbapc_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error);
void srv_pbabc_xml_end_element_hdlr(void *data, const char *el, int error);
MMI_BOOL srv_pbapc_parse_xml_file(kal_wchar *filename);

S32 srv_pbapc_send_begin(int sv_hd , srv_bt_cm_bt_addr *addr);



 //#define PBAPC_BUF_TRACE

#endif /* defined(__BT_PBAP_CLIENT__) */
#endif /* __MMI_BT_SUPPORT__ */

#endif /* __SRV_PBAPC_H__ */ 

