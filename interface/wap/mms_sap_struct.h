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
 *	mms_sap_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about MMS sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------*/


#ifndef _MMS_SAP_STRUCT_H
#define _MMS_SAP_STRUCT_H 

#include "kal_general_types.h"
#include "app_ltlcom.h"

#define MMS_VENDOR_MAX_INTERNAL_FILENAME_LENGTH	100

typedef enum
{
    MMI_MMS_VENDOR_TYPE_SMIL_MMS = 0,
    MMI_MMS_VENDOR_TYPE_MIXED_MMS,
    MMI_MMS_VENDOR_TYPE_TOTAL
}mmi_mms_vendor_type_enum;

typedef enum
{
    MMI_MMS_VENDOR_SIM_ID_SIM1 = 1,
    MMI_MMS_VENDOR_SIM_ID_SIM2,
    MMI_MMS_VENDOR_SIM_ID_TOTAL
}mmi_mms_vendor_sim_id_enum;

typedef enum
{
    MMA_APP_ID_UC = 0,
    MMA_APP_ID_UM = MMA_APP_ID_UC,
    MMA_APP_ID_TEMPLATE,
    MMA_APP_ID_MMS_APP,
    MMA_APP_ID_JSR,
    MMA_APP_ID_VIEWER,
    MMA_APP_ID_SETTING,
    MMA_APP_ID_HOME_SCREEN,
    MMA_APP_ID_HOME_SCREEN_RECENT_EVENT,
    MMA_APP_ID_MMS_APP_MARK_SEVERAL,
    MMA_APP_ID_MMS_APP_NMGR,
    MMA_APP_ID_TOOL_BAR,
    MMA_APP_ID_MMS_NOTIFICATION_EVENT,
    MMA_APP_ID_BGSR,
    MMI_MMS_VENDOR_CVM_APP_ID,
    MMA_APP_ID_MMS_LAWMO
} MMA_APP;

typedef enum
{
    MMI_MMS_VENDOR_FAIL,
    MMI_MMS_VENDOR_PASS,
    MMI_MMS_VENDOR_BUSY,
    MMI_MMS_VENDOR_USER_CANCEL,
    MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH,
    MMI_MMS_VENDOR_RESULT_TOTAL
}mmi_mms_vendor_result_enum;


typedef struct
{
	LOCAL_PARA_HDR
    kal_uint8 app_id; /* MMA_APP */
    kal_uint32  xml_size;        
    kal_wchar   xml_filepath[MMS_VENDOR_MAX_INTERNAL_FILENAME_LENGTH];
    kal_uint8   mms_type;       /* mmi_mms_vendor_type_enum */
    kal_uint8   sim_id;     /* mmi_mms_vendor_sim_id_enum */
}mmi_mms_vendor_create_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* MMA_APP */
    kal_uint32  msg_id;
    kal_uint8 result; /* mmi_mms_vendor_result_enum */
}mmi_mms_vendor_create_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    app_id; /* MMA_APP */
    kal_uint32  msg_id;
}mmi_mms_vendor_delete_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* MMA_APP */
    kal_uint32  msg_id;
    kal_uint8 result;   /* mmi_mms_vendor_result_enum */
}mmi_mms_vendor_delete_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    app_id; /* MMA_APP */
    kal_uint32  msg_id;
    kal_uint8   sim_id; /* mmi_mms_vendor_sim_id_enum */
}mmi_mms_vendor_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 app_id; /* MMA_APP */
    kal_uint32  msg_id;
    kal_bool result;  /*  mmi_mms_vendor_result_enum  */
}mmi_mms_vendor_send_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    app_id; /* MMA_APP */
    kal_uint32  msg_id;
}mmi_mms_vendor_cancel_send_req_struct;


/* This structure is used by local parameter of MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;         /* Request id */
   // kal_uint32  pool_size;		/* Required Pool size to allocated through ASM*/
}mmi_mms_get_asm_pool_req_struct;

/* This structure is used by local parameter of MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
	kal_uint8  *asm_pool_ptr;									/* Pointer to ASM pool*/
    kal_uint8   result;                                         /* mma_result_enum */
}mmi_mms_get_asm_pool_rsp_struct;

/* This structure is used by local parameter of MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_REQ. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint32  req_id;                                         /* Request id */
}mmi_mms_get_deinit_asm_pool_req_struct;

/* This structure is used by local parameter of MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_RSP. */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    //kal_uint32  req_id;                                         /* Request id */
	kal_uint8   result;                                         /* mma_result_enum */
}mmi_mms_get_deinit_asm_pool_rsp_struct;


#endif  /* End of _MMS_SAP_STRUCT_H */
