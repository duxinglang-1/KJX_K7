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
 *  CcaSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
 *
 *  This is the one and only file to be included for accessing CCA APIs.
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
#ifndef SRV_CCA_GPROT_H
#define SRV_CCA_GPROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"

#include "MMIDataType.h"
#include "mmi_res_range_def.h"

#ifdef __MMI_CCA_SUPPORT__


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/* Max childs of one node in CCA Doc */
#define SRV_CCA_TREE_MAX_CHILDS                     (20)
/* Max chars can be input on PIN Input screen */
#define SRV_CCA_MAX_PIN_CHARS                       (40)
/* Max applications can be configured by one provisioning message */
#define SRV_CCA_MAX_APPS                            (20)


/* Current profile in using, only use for operations on currently activated profile */
#define SRV_CCA_PROF_CURRENT                        (-1)

/* Max bytes of the has value generated by srv_cca_generate_hash_value */
#define SRV_CCA_HASH_VALUE_MAX_BYTES                (16)

/* Invalid provisioning message id, only use for ProvisioningInbox feature */
#define SRV_CCA_INVALID_MSG_ID                      (0)

/* Indicate if the factory profile can be updatable, use for SRV_CCA_PROV_TYPE_OTA_PROV, only use for target application */
#define SRV_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE (0x0001)

/* use fro SRV_CCA_PROV_TYPE_SIM_PROV */
/* Indicate if need to show SIM1 profile when to support SIM provisioning feature, not supported on Gemini+ projects */
#define SRV_CCA_PROV_FLAG_SHOW_SIM1_PROFILE         (0x0010)
/* Indicate if need to show SIM2 profile when to support SIM provisioning feature, not supported on Gemini+ projects */
#define SRV_CCA_PROV_FLAG_SHOW_SIM2_PROFILE         (0x0020)
/* Indicate if need to activate SIM1 profile when to support SIM provisioning feature, not supported on Gemini+ projects */
#define SRV_CCA_PROV_FLAG_ACTIVATE_SIM1_PROFILE     (0x0040)
/* Indicate if need to activate SIM2 profile when to support SIM provisioning feature, not supported on Gemini+ projects */
#define SRV_CCA_PROV_FLAG_ACTIVATE_SIM2_PROFILE     (0x0080)

/* Indicate if PIN code is verified, only use for configuration source */
#define SRV_CCA_PROV_FLAG_PIN_VERIFIED              (0x0001)   



/* Spec id: xxxx 0000 0000 0000
   Spec ID / Application ID / Configuration ID
   Each ID = 2 bytes const (16 bits)
   Spec ID = high byte = 256 specs --> { ssss cccc }
            where ssss = higher 4 bits = spec ID
                  cccc = lower 4 bits = category ID
  App ID = low byte = 256 applications
 */
typedef enum
{
    SRV_CCA_SPEC_NULL = 0x0000,                 /* Default NULL */
    SRV_CCA_SPEC_OMA = 0x1000,                  /* OMA spec */
    SRV_CCA_SPEC_MAX_ITEM                       /* Max item */
}srv_cca_spec_enum;

/* Get spec id from configuration id */
#define SRV_CCA_GET_SPEC(x)                         (x & 0xF000)    
/* 0000 xxxx 0000 0000, Default category */
#define SRV_CCA_CATE_NULL                           (0x0000)        
/* DMP Category */
#define SRV_CCA_CATE_DMP                            (0x0100)

/* To get category from configuration id */
#define SRV_CCA_GET_CATE(x)                         (x & 0x0F00)    

/* Test source id */
#define SRV_CCA_SOURCE_TEST                         (0x0001)       
/* PRS source id */
#define SRV_CCA_SOURCE_WAP                          (0x0002)        
/* DM source id */
#define SRV_CCA_SOURCE_DM                           (0x0003)        
/* SPA source id */
#define SRV_CCA_SOURCE_SPA                          (0x0004)        
/* ProvBox source id */
#define SRV_CCA_SOURCE_PROVBOX                      (0x0005)           
/* ProvBoxUI source id */
#define SRV_CCA_SOURCE_PROVBOXUI                    (0x0006)        

/* 0000 0000 xxxx xxxx,  Invalid application id */
#define SRV_CCA_APP_INVALID                         (0x0000)        
/* Test application id */
#define SRV_CCA_APP_TEST                            (0x0001)        
/* Data account application id */
#define SRV_CCA_APP_DTACCT                          (0x0002)        
/* WLAN application id */
#define SRV_CCA_APP_WLAN                            (0x0003)        
/* Browser application id */
#define SRV_CCA_APP_BROWSER                         (0x0004)        
/* MMS application id */
#define SRV_CCA_APP_MMS                             (0x0005)        
/* VoIP SIP application id */
#define SRV_CCA_APP_SIP                             (0x0006)        
/* IMPS application id */
#define SRV_CCA_APP_IMPS                            (0x0007)        
/* Email application id */
#define SRV_CCA_APP_EMAIL                           (0x0008)        
/* SyncML-DS application id */
#define SRV_CCA_APP_SYNCMLDS                        (0x0009)        
/* SyncML-DM application id */
#define SRV_CCA_APP_SYNCMLDM                        (0x000A)        
/* Push White list application id */
#define SRV_CCA_APP_PUSH                            (0x000B)        
/* RTSP streaming application id  */
#define SRV_CCA_APP_RTSP                            (0x000C)        
/* SUPL AGPS application id  */
#define SRV_CCA_APP_SUPL                            (0x000D)        

/* Get application id from configuration id */
#define SRV_CCA_GET_APP(x)                          (x & 0x00FF)    

/* Invalid configuration id */
#define SRV_CCA_CONFIG_INVALID                      (0)                                                             
/* Test configuration id */
#define SRV_CCA_CONFIG_TEST                         (SRV_CCA_APP_TEST    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* Data account configuration id */    
#define SRV_CCA_CONFIG_DTACCT                       (SRV_CCA_APP_DTACCT  | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* WLAN configuration id */
#define SRV_CCA_CONFIG_WLAN                         (SRV_CCA_APP_WLAN    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* Browser configuration id */
#define SRV_CCA_CONFIG_BROWSER                      (SRV_CCA_APP_BROWSER | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* MMS configuration id */
#define SRV_CCA_CONFIG_MMS                          (SRV_CCA_APP_MMS     | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* VoIP SIP configuration id */
#define SRV_CCA_CONFIG_SIP                          (SRV_CCA_APP_SIP     | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* IMPS configuration id */
#define SRV_CCA_CONFIG_IMPS                         (SRV_CCA_APP_IMPS    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* Email configuration id */
#define SRV_CCA_CONFIG_EMAIL                        (SRV_CCA_APP_EMAIL   | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* SyncML-DS configuration id */
#define SRV_CCA_CONFIG_SYNCMLDS                     (SRV_CCA_APP_SYNCMLDS| SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* SyncML-DM configuration id */
#define SRV_CCA_CONFIG_SYNCMLDM                     (SRV_CCA_APP_SYNCMLDM| SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* Push White list configuration id */
#define SRV_CCA_CONFIG_PUSH                         (SRV_CCA_APP_PUSH    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* RTSP streaming configuration id */ 
#define SRV_CCA_CONFIG_RTSP                         (SRV_CCA_APP_RTSP    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    
/* SUPL AGPS configuration id  */
#define SRV_CCA_CONFIG_SUPL                         (SRV_CCA_APP_SUPL    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_NULL)    

/* WLAN DMP configuration id */
#define SRV_CCA_CONFIG_WLAN_DMP                     (SRV_CCA_APP_WLAN    | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_DMP )    
/* VoIP SIP DMP configuration id */
#define SRV_CCA_CONFIG_SIP_DMP                      (SRV_CCA_APP_SIP     | SRV_CCA_SPEC_OMA | SRV_CCA_CATE_DMP )    



/***** Namespace Convension
 * Each symbol = 2 bytes const (16 bits)
 * Namespace ID = higher 6 bits = 64 namespaces (inc all specs + apps)
 * Symbol ID = lower 10 bits = 1024 symbols in each namespace
 */
/* xxxx xx00 0000 0000 */
#define SRV_CCA_NS_TEST                             (0x0000)    /* Name space for test */
#define SRV_CCA_NS_CCA                              (0x0400)    /* Name space for CCA */
#define SRV_CCA_NS_VAL                              (0x0800)    /* Name space for value */
#define SRV_CCA_NS_OMA                              (0x0C00)    /* Name space for OMA spec */
#define SRV_CCA_NS_OMADMP                           (0x1C00)    /* Name space for OMADMP spec */

#define SRV_CCA_NS__NULL                            (0xFFFF)    /* SRV_CCA_NS__NULL if no oma_node_id */
#define SRV_CCA_NS_CLEARNS                          (0x03FF)    /* Unused now */

/***** OMA Client Provisioning Value Symbols Section
 * Each value symbol = lower 10 bits of a symbol identifier
 * to clearly distinguish between values in various nodes (especially between offical and proprietary spec)
 * value symbols section is further divided into 2 parts:
 *     Namespace ID = upper 6 bits = 64 namespaces
 *     Value Section ID = mid 4 bits = 16 value sections
 *     Value Symbol ID = lower 6 bits = 64 value symbols per section
 * shall 64 symbols not sufficient for a particular value section
 * a second value section may be declared to store the remaining value symbols of that section.
 */
/* 0000 00xx xx00 0000 */
#define SRV_CCA_NS_VAL__SECTION_NULL                (0x0040 | SRV_CCA_NS_VAL)   /* Value section for default use */
#define SRV_CCA_NS_VAL__SECTION_OMA                 (0x0080 | SRV_CCA_NS_VAL)   /* Value section for OMA spec */
#define SRV_CCA_NS_VAL__SECTION_OMADMP              (0x01C0 | SRV_CCA_NS_VAL)   /* Value section for OMADMP spec */


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
/* Please note, 
   To support Gemini+, the following srv_cca_sim_id_enum is phase out,
   please use mmi_sim_enum directly to remove so many sim_id defines in different APs.
*/

/* To be phase out */
typedef enum
{
    SRV_CCA_SIM_ID_DEFAULT = MMI_SIM_NONE,
    SRV_CCA_SIM_ID_SIM1 = MMI_SIM1,
    SRV_CCA_SIM_ID_SIM2 = MMI_SIM2,
    SRV_CCA_SIM_ID_DUAL_SIM = MMI_SIM1 | MMI_SIM2,
//  SRV_CCA_SIM_ID_SIM3 = MMI_SIM3,
//  SRV_CCA_SIM_ID_SIM4 = MMI_SIM4,
    SRV_CCA_SIM_ID_MAX_ITEM
} srv_cca_sim_id_enum;

/* Provisioning type */
typedef enum
{
    SRV_CCA_PROV_TYPE_OTA_PROV,                 /* Provisioning received Over The Air (OTA)*/
    SRV_CCA_PROV_TYPE_SIM_PROV,                 /* Provisioning from SIM card */   
    SRV_CCA_PROV_TYPE_MAX_ITEM                  /* Max item */
} srv_cca_prov_type_enum;

/* Security type */
typedef enum
{
    SRV_CCA_SEC_TYPE_NONE,                      /* Security is not needed */
    SRV_CCA_SEC_TYPE_USERPIN,                   /* USERPIN */    
    SRV_CCA_SEC_TYPE_NETWPIN,                   /* NETWPIN */
    SRV_CCA_SEC_TYPE_USERNETWIN,                /* USERNETWIN */
    SRV_CCA_SEC_TYPE_USERPINMAC,                /* USERPINMAC */    
    SRV_CCA_SEC_TYPE_UNKNOWN,                   /* Unknown */
    SRV_CCA_SEC_TYPE_MAX_ITEM                   /* Max item */
} srv_cca_sec_type_enum;

/* Status code or result code */
typedef enum
{
    SRV_CCA_STATUS_OK,                              /* Ok or configured success */
    SRV_CCA_STATUS_FAIL,                            /* Fail */

    SRV_CCA_STATUS_INVALID_SETTING,                 /* Invalid setting */
    SRV_CCA_STATUS_SETTING_UPDATED,                 /* Profiles are updated */
    SRV_CCA_STATUS_SETTING_SKIPPED,                 /* Profiles are skipped */
    SRV_CCA_STATUS_ENDKEY_PRESSED,                  /* End key is pressed */
    SRV_CCA_STATUS_ENDKEY_SETTING_UPDATED,          /* End key is pressed after some profiles are updated */
    SRV_CCA_STATUS_ENDKEY_SETTING_INSTALLED,        /* End key is pressed after some profiles are installed */    
    SRV_CCA_STATUS_ENDKEY_SETTING_SKIPPED,          /* End key is pressed after some profiles are skipped */
    SRV_CCA_STATUS_ENDKEY_INVALID_SETTING,          /* End key is pressed and current setting is invalid */
    SRV_CCA_STATUS_SETTING_NOT_INSTALLED,           /* Setting is not insalled */

    SRV_CCA_STATUS_ABORT,                           /* Abort */
    SRV_CCA_STATUS_ENDLIST,                         /* Reach the end of one iterate list */
    SRV_CCA_STATUS_MEMFULL,                         /* Memory is full */
    SRV_CCA_STATUS_NOT_FOUND,                       /* Not found */
    SRV_CCA_STATUS_TYPE_MISMATCHED,                 /* Not matched */
    SRV_CCA_STATUS_INVALID_ITER,                    /* Invalid iterator */
    SRV_CCA_STATUS_INVALID_HANDLE,                  /* Invalid handler */
    SRV_CCA_STATUS_INVALID_PARAM,                   /* Invalid parameter */

    SRV_CCA_STATUS_UNSUPPORTED_SETTING,             /* Unsupported setting */
    SRV_CCA_STATUS_CORRUPTED_SETTING,               /* Corrupted setting */
    SRV_CCA_STATUS_MISSING_DATA,                    /* Missing data */
    SRV_CCA_STATUS_SETTING_NOAPP,                   /* No application is found */

    SRV_CCA_STATUS_OUT_OF_RANGE,                    /* Out of range */
    SRV_CCA_STATUS_CCA_BUSY,                        /* CCA is busy */
    SRV_CCA_STATUS_CCA_READY,                       /* CCA is ready */

    SRV_CCA_STATUS_AUTH_FAILED,                     /* Authrization failed */
    SRV_CCA_STATUS_GET_MSG_FAILED,                  /* Get message info failed */

    SRV_CCA_STATUS_MAX_ITEM                         /* Max item */
} srv_cca_status_enum;

/* Session type */
typedef enum
{
    SRV_CCA_SESSION_TYPE_DM,                    /* DM session type */
    SRV_CCA_SESSION_TYPE_MAX_ITEM               /* Max item */
} srv_cca_session_type_enum;

/* Data type of the value in CoreData */
typedef enum
{
    SRV_CCA_DATA_TYPE_INT,                      /* Interger data type */
    SRV_CCA_DATA_TYPE_STR,                      /* String data type */
    SRV_CCA_DATA_TYPE_MAX_ITEM                  /* Max item */
} srv_cca_data_type_enum;


/* will not export after split */
typedef enum
{
    SRV_CCA_TR_LIST,  /* To traverse the List structure, which may be node list, node chain list or data list */
    SRV_CCA_TR_PREORDER,    /* To traverse the tree which can be CCA doc only, return the h_node which is doc base element */
    SRV_CCA_TR_MAX_ITEM
} srv_cca_traverse_type_enum;

/*
 * NODELIST:  current: srv_cca_doc_nodelist_struct;
 *   ------  ------  ------  ------
 *   |Next|--|Next|--|Next|--|Next|---0
 *   |Node|  |Node|  |Node|  |Node|
 *   ------  ------  ------  ------
 *
 * NODECHAIN:       Not support now srv_cca_doc_node_struct;
 *   ------  ------  ------  ------
 *   |Node|--|Node|--|Node|--|Node|---0
 *   ------  ------  ------  ------
 *
 * DATALIST:  srv_cca_doc_node_datalist_struct
 *   ------  ------  ------  ------
 *   |Next|--|Next|--|Next|--|Next|---0
 *   |Data|  |Data|  |Data|  |Data|
 *   ------  ------  ------  ------
 */

/* will not export after split */
typedef enum
{
    SRV_CCA_IT_NODELIST,
    SRV_CCA_IT_NODECHAIN,
    SRV_CCA_IT_DATALIST,
    SRV_CCA_IT_DOC,
    SRV_CCA_IT_MAX_ITEM
} srv_cca_iter_type_enum;


/*----------------------------------------------------------------------------*/
/* Symbol Begin                                                               */
/*----------------------------------------------------------------------------*/

/* CCA Proprietary Symbols */
typedef enum
{
    SRV_CCA_NS__START = (0x0000 | SRV_CCA_NS_CCA),

    SRV_CCA_NS_DOCROOT,                             /* 401 */
    SRV_CCA_NS_NODEID,                              /* 402 */
    SRV_CCA_NS_DATAACCTID,                          /* 403 */
    SRV_CCA_NS_L1NODEID,                            /* 404 */  //Not export after split
    SRV_CCA_NS_TRIGNODE,                            /* 405 */
    SRV_CCA_NS_TRIGPARM,                            /* 406 */

    SRV_CCA_NS__LAST
} srv_cca_symbols_enum;



/* CCA Proprietary Value Symbols */
typedef enum
{
    SRV_CCA_NS_VAL__START = (0x0000 | SRV_CCA_NS_VAL__SECTION_NULL),

    SRV_CCA_NS_VAL__EMPTY,                          /* 841 */
    SRV_CCA_NS_VAL__INVALID,                        /* 842 */

    SRV_CCA_NS_VAL__LAST
} srv_cca_values_enum;

/* OMA Client Provisioning v1.1 Symbols */
typedef enum
{
    SRV_CCA_NS_OMA__START = (0x0000 | SRV_CCA_NS_OMA),

    SRV_CCA_NS_OMA_PROXY,                           /* C01 */
    SRV_CCA_NS_OMA_PROXY_ID,                        /* C02 */
    SRV_CCA_NS_OMA_PROXY_PW,                        /* C03 */
    SRV_CCA_NS_OMA_PPGAUTH_TYPE,                    /* C04 */
    SRV_CCA_NS_OMA_PROXY_PROVIDER_ID,               /* C05 */
    SRV_CCA_NS_OMA_NAME,                            /* C06 */
    SRV_CCA_NS_OMA_DOMAIN,                          /* C07 */
    SRV_CCA_NS_OMA_TRUST,                           /* C08 */
    SRV_CCA_NS_OMA_MASTER,                          /* C09 */
    SRV_CCA_NS_OMA_STARTPAGE,                       /* C0A */
    SRV_CCA_NS_OMA_BASAUTH_ID,                      /* C0B */
    SRV_CCA_NS_OMA_BASAUTH_PW,                      /* C0C */
    SRV_CCA_NS_OMA_WSP_VERSION,                     /* C0D */
    SRV_CCA_NS_OMA_PUSHENABLED,                     /* C0E */
    SRV_CCA_NS_OMA_PULLENABLED,                     /* C0F */

    SRV_CCA_NS_OMA_PXAUTHINFO,                      /* C10 */
    SRV_CCA_NS_OMA_PXAUTH_TYPE,                     /* C11 */
    SRV_CCA_NS_OMA_PXAUTH_ID,                       /* C12 */
    SRV_CCA_NS_OMA_PXAUTH_PW,                       /* C13 */
    SRV_CCA_NS_OMA_PORT,                            /* C14 */
    SRV_CCA_NS_OMA_PORTNBR,                         /* C15 */
    SRV_CCA_NS_OMA_SERVICE,                         /* C16 */
    SRV_CCA_NS_OMA_PHYSICAL_PROXY_ID,               /* C17 */
    SRV_CCA_NS_OMA_PXADDR,                          /* C18 */
    SRV_CCA_NS_OMA_PXADDRTYPE,                      /* C19 */
    SRV_CCA_NS_OMA_PXADDR_FQDN,                     /* C1A */
    SRV_CCA_NS_OMA_TO_NAPID,                        /* C1B */
    SRV_CCA_NS_OMA_NAPDEF,                          /* C1C */
    SRV_CCA_NS_OMA_NAPID,                           /* C1D */
    SRV_CCA_NS_OMA_BEARER,                          /* C1E */
    SRV_CCA_NS_OMA_INTERNET,                        /* C1F */

    SRV_CCA_NS_OMA_NAP_ADDRESS,                     /* C20 */
    SRV_CCA_NS_OMA_NAP_ADDRTYPE,                    /* C21 */
    SRV_CCA_NS_OMA_DNS_ADDR,                        /* C22 */
    SRV_CCA_NS_OMA_CALLTYPE,                        /* C23 */
    SRV_CCA_NS_OMA_LOCAL_ADDR,                      /* C24 */
    SRV_CCA_NS_OMA_LOCAL_ADDRTYPE,                  /* C25 */
    SRV_CCA_NS_OMA_LINKSPEED,                       /* C26 */
    SRV_CCA_NS_OMA_DNLINKSPEED,                     /* C27 */
    SRV_CCA_NS_OMA_LINGER,                          /* C28 */
    SRV_CCA_NS_OMA_DELIVERY_ERR_SDU,                /* C29 */              
    SRV_CCA_NS_OMA_DELIVERY_ORDER,                  /* C2A */
    SRV_CCA_NS_OMA_TRAFFIC_CLASS,                   /* C2B */
    SRV_CCA_NS_OMA_MAX_SDU_SIZE,                    /* C2C */
    SRV_CCA_NS_OMA_MAX_BITRATE_UPLINK,              /* C2D */
    SRV_CCA_NS_OMA_MAX_BITRATE_DNLINK,              /* C2E */
    SRV_CCA_NS_OMA_RESIDUAL_BER,                    /* C2F */

    SRV_CCA_NS_OMA_SDU_ERROR_RATIO,                 /* C30 */
    SRV_CCA_NS_OMA_TRAFFIC_HANDL_PRIO,              /* C31 */
    SRV_CCA_NS_OMA_TRANSFER_DELAY,                  /* C32 */
    SRV_CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK,       /* C33 */
    SRV_CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK,       /* C34 */
    SRV_CCA_NS_OMA_MAX_NUM_RETRY,                   /* C35 */
    SRV_CCA_NS_OMA_FIRST_RETRY_TIMEOUT,             /* C36 */
    SRV_CCA_NS_OMA_REREG_THRESHOLD,                 /* C37 */
    SRV_CCA_NS_OMA_T_BIT,                           /* C38 */
    SRV_CCA_NS_OMA_NAPAUTHINFO,                     /* C39 */
    SRV_CCA_NS_OMA_AUTHTYPE,                        /* C3A */
    SRV_CCA_NS_OMA_AUTHNAME,                        /* C3B */
    SRV_CCA_NS_OMA_AUTHSECRET,                      /* C3C */
    SRV_CCA_NS_OMA_AUTH_ENTITY,                     /* C3D */
    SRV_CCA_NS_OMA_SPI,                             /* C3E */
    SRV_CCA_NS_OMA_VALIDITY,                        /* C3F */

    SRV_CCA_NS_OMA_COUNTRY,                         /* C40 */
    SRV_CCA_NS_OMA_NETWORK,                         /* C41 */
    SRV_CCA_NS_OMA_SID,                             /* C42 */
    SRV_CCA_NS_OMA_SOC,                             /* C43 */
    SRV_CCA_NS_OMA_VALIDUNTIL,                      /* C44 */
    SRV_CCA_NS_OMA_BOOTSTRAP,                       /* C45 */
    SRV_CCA_NS_OMA_PROVURL,                         /* C46 */
    SRV_CCA_NS_OMA_CONTEXT_ALLOW,                   /* C47 */
    SRV_CCA_NS_OMA_CLIENTIDENTITY,                  /* C48 */
    SRV_CCA_NS_OMA_CLIENT_ID,                       /* C49 */
    SRV_CCA_NS_OMA_VENDORCONFIG,                    /* C4A */
    SRV_CCA_NS_OMA_APPLICATION,                     /* C4B */
    SRV_CCA_NS_OMA_APPID,                           /* C4C */
    SRV_CCA_NS_OMA_PROVIDER_ID,                     /* C4D */
    SRV_CCA_NS_OMA_AACCEPT,                         /* C4E */
    SRV_CCA_NS_OMA_APROTOCOL,                       /* C4F */

    SRV_CCA_NS_OMA_TO_PROXY,                        /* C50 */
    SRV_CCA_NS_OMA_ADDR,                            /* C51 */
    SRV_CCA_NS_OMA_CM,                              /* C52 */   /* MMS Creation Mode */
    SRV_CCA_NS_OMA_RM,                              /* C53 */   /* MMS Re-submission Mode */
    SRV_CCA_NS_OMA_MS,                              /* C54 */   /* MMS Max Authorized MM Size */
    SRV_CCA_NS_OMA_PC_ADDR,                         /* C55 */   /* MMS Address for Post Service */
    SRV_CCA_NS_OMA_MA,                              /* C56 */   /* MMS MMSA Interface */
    SRV_CCA_NS_OMA_APPADDR,                         /* C57 */
    SRV_CCA_NS_OMA_ADDRTYPE,                        /* C58 */
    SRV_CCA_NS_OMA_APPAUTH,                         /* C59 */
    SRV_CCA_NS_OMA_AAUTHLEVEL,                      /* C5A */
    SRV_CCA_NS_OMA_AAUTHTYPE,                       /* C5B */
    SRV_CCA_NS_OMA_AAUTHNAME,                       /* C5C */
    SRV_CCA_NS_OMA_AAUTHSECRET,                     /* C5D */
    SRV_CCA_NS_OMA_AAUTHDATA,                       /* C5E */
    SRV_CCA_NS_OMA_RESOURCE,                        /* C5F */

    SRV_CCA_NS_OMA_URI,                             /* C60 */
    SRV_CCA_NS_OMA_ACCESS,                          /* C61 */
    SRV_CCA_NS_OMA_RULE,                            /* C62 */
    SRV_CCA_NS_OMA_LOGINTYPE,                       /* C63 */   /* Conversion from Nokia OTA Spec */
    SRV_CCA_NS_OMA_FROM,                            /* C64 */   /* SMTP */
    SRV_CCA_NS_OMA_RT_ADDR,                         /* C65 */   /* SMTP */
    SRV_CCA_NS_OMA_SERVICES,                        /* C66 */   /* IMPS */
    SRV_CCA_NS_OMA_CIDPREFIX,                       /* C67 */   /* IMPS */
    SRV_CCA_NS_OMA_CLIURI,                          /* C68 */   /* SyncML-DS */
    SRV_CCA_NS_OMA_SYNCTYPE,                        /* C69 */   /* SyncML-DS */
    SRV_CCA_NS_OMA_INIT,                            /* C6A */   /* SyncML-DM */

    /* OMA Extension */
    /* OMA Client Provisioning Extension WLAN Symbols */
    SRV_CCA_NS_OMA_WLAN,                            /* C6B */
    SRV_CCA_NS_OMA_PRI_SSID,                        /* C6C */
    SRV_CCA_NS_OMA_PRI_U_SSID,                      /* C6D */
    SRV_CCA_NS_OMA_PRI_H_SSID,                      /* C6E */
    SRV_CCA_NS_OMA_SEC_SSID,                        /* C6F */

    SRV_CCA_NS_OMA_S_SSID,                          /* C70 */
    SRV_CCA_NS_OMA_S_U_SSID,                        /* C71 */
    SRV_CCA_NS_OMA_NETMODE,                         /* C72 */
    SRV_CCA_NS_OMA_SECMODE,                         /* C73 */
    SRV_CCA_NS_OMA_EAP,                             /* C74 */
    SRV_CCA_NS_OMA_EAPTYPE,                         /* C75 */
    SRV_CCA_NS_OMA_USERNAME,                        /* C76 */
    SRV_CCA_NS_OMA_PASSWORD,                        /* C77 */
    SRV_CCA_NS_OMA_REALM,                           /* C78 */
    SRV_CCA_NS_OMA_USE_PSEUD,                       /* C79 */
    SRV_CCA_NS_OMA_MAXAUTHS,                        /* C7A */
    SRV_CCA_NS_OMA_ENCAPS,                          /* C7B */
    SRV_CCA_NS_OMA_VER_SER_REALM,                   /* C7C */
    SRV_CCA_NS_OMA_CLIENT_AUTH,                     /* C7D */
    SRV_CCA_NS_OMA_SES_VAL_TIME,                    /* C7E */
    SRV_CCA_NS_OMA_CIP_SUIT,                        /* C7F */

    SRV_CCA_NS_OMA_PEAP_V0,                         /* C80 */
    SRV_CCA_NS_OMA_PEAP_V1,                         /* C81 */
    SRV_CCA_NS_OMA_PEAP_V2,                         /* C82 */
    SRV_CCA_NS_OMA_CERT,                            /* C83 */
    SRV_CCA_NS_OMA_ISS_NAME,                        /* C84 */
    SRV_CCA_NS_OMA_SUB_NAME,                        /* C85 */
    SRV_CCA_NS_OMA_CERT_TYPE,                       /* C86 */
    SRV_CCA_NS_OMA_SER_NUM,                         /* C87 */
    SRV_CCA_NS_OMA_SUB_KEY_ID,                      /* C88 */
    SRV_CCA_NS_OMA_THUMBPRINT,                      /* C89 */
    SRV_CCA_NS_OMA_WPA_PRES_KEY_ASC,                /* C8A */
    SRV_CCA_NS_OMA_WPA_PRES_KEY_HEX,                /* C8B */
    SRV_CCA_NS_OMA_WEPKEYIND,                       /* C8C */
    SRV_CCA_NS_OMA_WEPAUTHMODE,                     /* C8D */
    SRV_CCA_NS_OMA_WEPKEY,                          /* C8E */
    SRV_CCA_NS_OMA_LENGTH,                          /* C8F */

    SRV_CCA_NS_OMA_INDEX,                           /* C90 */
    SRV_CCA_NS_OMA_DATA,                            /* C91 */
    SRV_CCA_NS_OMA_WLANHAND,                        /* C92 */
    SRV_CCA_NS_OMA_EDIT_SET,                        /* C93 */
    SRV_CCA_NS_OMA_VIEW_SET,                        /* C94 */
    SRV_CCA_NS_OMA_FORW_SET,                        /* C95 */

    /* SIM MMS profile: EFmmicp */
    SRV_CCA_NS_OMA_IMPL,                            /* C96 */

    /* RTSP application-specific parameters */  
    SRV_CCA_NS_OMA_MAX_BANDWIDTH,                   /* C97 */
    SRV_CCA_NS_OMA_NETINFO,                         /* C98 */
    SRV_CCA_NS_OMA_MIN_UDP_PORT,                    /* C99 */
    SRV_CCA_NS_OMA_MAX_UDP_PORT,                    /* C9A */
    
    SRV_CCA_NS_OMA__LAST
} srv_cca_oma_symbols_enum;

/* DMP Spec */
/* OMA Client Provisioning Extension Proprietary Symbols */
typedef enum
{
    SRV_CCA_NS_OMADMP__START = (0x0000 | SRV_CCA_NS_OMADMP),

    /* SIP */
    SRV_CCA_NS_OMADMP_PX_SIP,                       /* 1C01 */
    SRV_CCA_NS_OMADMP_NAME,                         /* 1C02 */
    SRV_CCA_NS_OMADMP_USER_NAME,                    /* 1C03 */
    SRV_CCA_NS_OMADMP_AUTH_NAME,                    /* 1C04 */
    SRV_CCA_NS_OMADMP_AUTH_PASSWD,                  /* 1C05 */
    SRV_CCA_NS_OMADMP_DOMAIN,                       /* 1C06 */
    SRV_CCA_NS_OMADMP_LOCAL_PORT,                   /* 1C07 */
    SRV_CCA_NS_OMADMP_PREFER_CODEC,                 /* 1C08 */
    SRV_CCA_NS_OMADMP_PXSRV_ADDR,                   /* 1C09 */
    SRV_CCA_NS_OMADMP_PXSRV_ADDRTYPE,               /* 1C0A */
    SRV_CCA_NS_OMADMP_PXSRV_PORT,                   /* 1C0B */
    SRV_CCA_NS_OMADMP_REGSRV_ADDR,                  /* 1C0C */
    SRV_CCA_NS_OMADMP_REGSRV_ADDRTYPE,              /* 1C0D */
    SRV_CCA_NS_OMADMP_REGSRV_PORT,                  /* 1C0E */
    SRV_CCA_NS_OMADMP_REGSRV_REGPERIOD,             /* 1C0F */

    SRV_CCA_NS_OMADMP_OUTPXSRV_ADDR,                /* 1C10 */
    SRV_CCA_NS_OMADMP_OUTPXSRV_ADDRTYPE,            /* 1C11 */
    SRV_CCA_NS_OMADMP_OUTPXSRV_PORT,                /* 1C12 */
    SRV_CCA_NS_OMADMP_RTP_AUDIO_PORT,               /* 1C13 */
    SRV_CCA_NS_OMADMP_RTP_PACKET_PERIOD,            /* 1C14 */
    SRV_CCA_NS_OMADMP_NAT_RPORT_ENABLED,            /* 1C15 */
    SRV_CCA_NS_OMADMP_NAT_STUN_ENABLED,             /* 1C16 */
    SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDR,             /* 1C17 */
    SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDRTYPE,         /* 1C18 */
    SRV_CCA_NS_OMADMP_NAT_STUNSRV_PORT,             /* 1C19 */
    SRV_CCA_NS_OMADMP_NAT_STUNSRV_REFRESH_PERIOD,   /* 1C1A */

    /* WIFI */
    SRV_CCA_NS_OMADMP_WIFI,                         /* 1C1B */
    SRV_CCA_NS_OMADMP_ACCESS_POINT,                 /* 1C1C */
    SRV_CCA_NS_OMADMP_PROFILE,                      /* 1C1D */
    SRV_CCA_NS_OMADMP_SSID,                         /* 1C1E */
    SRV_CCA_NS_OMADMP_ADHOC,                        /* 1C1F */

    SRV_CCA_NS_OMADMP_AUTHENTICATION,               /* 1C20 */
    SRV_CCA_NS_OMADMP_ENCRYPTION,                   /* 1C21 */
    SRV_CCA_NS_OMADMP_KEYPROVIDED,                  /* 1C22 */
    SRV_CCA_NS_OMADMP_NETWORKKEY,                   /* 1C23 */
    SRV_CCA_NS_OMADMP_KEYINDEX,                     /* 1C24 */
    SRV_CCA_NS_OMADMP_USE8021X,                     /* 1C25 */
    SRV_CCA_NS_OMADMP_EAPTYPE,                      /* 1C26 */
    SRV_CCA_NS_OMADMP_AD_HOC,                       /* 1C27 */

    SRV_CCA_NS_OMADMP__LAST
} srv_cca_omadmp_symbols_enum;

typedef enum
{
    SRV_CCA_NS_VAL__OMA_START = (0x0000 | SRV_CCA_NS_VAL__SECTION_OMA),

    /* PROXY: PPGAUTH-TYPE */
    /* PROXY/PXAUTHINFO: PXAUTH-TYPE */
    /* APPLICATION/APPAUTH: AAUTHTYPE(official) */
    /* APPLICATION/RESOURCE: AAUTHTYPE */
    SRV_CCA_NS_VAL_HTTP_BASIC,                      /* 881 */
    SRV_CCA_NS_VAL_HTTP_DIGEST,                     /* 882 */
    SRV_CCA_NS_VAL_WTLS_SS,                         /* 883 */
    SRV_CCA_NS_VAL_BASIC,                           /* 884 */
    SRV_CCA_NS_VAL_DIGEST,                          /* 885 */

    /* APPLICATION/APPAUTH: AAUTHTYPE */
    SRV_CCA_NS_VAL_CRAM_MD5,                        /* 886 */
    SRV_CCA_NS_VAL_DIGEST_MD5,                      /* 887 */
    SRV_CCA_NS_VAL_LOGIN,                           /* 888 */
    SRV_CCA_NS_VAL_PLAIN,                           /* 889 */
    SRV_CCA_NS_VAL_APOP,                            /* 88A */
    SRV_CCA_NS_VAL_GSSAPI,                          /* 88B */
    SRV_CCA_NS_VAL_KERBEROS_V4,                     /* 88C */
    SRV_CCA_NS_VAL_SKEY,                            /* 88D */
    SRV_CCA_NS_VAL_CLIENT,                          /* 88E */
    SRV_CCA_NS_VAL_X509,                            /* 88F */

    SRV_CCA_NS_VAL_SECURID,                         /* 890 */
    SRV_CCA_NS_VAL_SAFEWORD,                        /* 891 */
    SRV_CCA_NS_VAL_DIGIPASS,                        /* 892 */
    SRV_CCA_NS_VAL_HMAC,                            /* 893 */

    /* PROXY: PXADDRTYPE */
    /* NAPDEF: NAP-ADDRTYPE */
    /* NAPDEF: LOCAL-ADDRTYPE */
    /* APPLICATION/APPADDR: ADDRTYPE */
    SRV_CCA_NS_VAL_IPV4,                            /* 894 */
    SRV_CCA_NS_VAL_IPV6,                            /* 895 */
    SRV_CCA_NS_VAL_E164,                            /* 896 */
    SRV_CCA_NS_VAL_ALPHA,                           /* 897 */
    SRV_CCA_NS_VAL_APN,                             /* 898 */
    SRV_CCA_NS_VAL_SCODE,                           /* 899 */
    SRV_CCA_NS_VAL_TETRA_ITSI,                      /* 89A */
    SRV_CCA_NS_VAL_MAN,                             /* 89B */
    SRV_CCA_NS_VAL_FQDN,                            /* 89C */   /* only SUPL used now */ 
    
    /* PROXY: PUSHENABLED/PULLENABLED */
    SRV_CCA_NS_VAL_ENABLED,                         /* 89D */
    SRV_CCA_NS_VAL_DISABLED,                        /* 89E */

    /* PROXY/PORT: SERVICE */
    SRV_CCA_NS_VAL_CL_WSP,                          /* 89F */

    SRV_CCA_NS_VAL_CO_WSP,                          /* 8A0 */
    SRV_CCA_NS_VAL_CL_SEC_WSP,                      /* 8A1 */
    SRV_CCA_NS_VAL_CO_SEC_WSP,                      /* 8A2 */
    SRV_CCA_NS_VAL_CO_SEC_WTA,                      /* 8A3 */
    SRV_CCA_NS_VAL_CL_SEC_WTA,                      /* 8A4 */
    SRV_CCA_NS_VAL_OTA_HTTP_TO,                     /* 8A5 */
    SRV_CCA_NS_VAL_OTA_HTTP_TLS_TO,                 /* 8A6 */
    SRV_CCA_NS_VAL_OTA_HTTP_PO,                     /* 8A7 */
    SRV_CCA_NS_VAL_OTA_HTTP_TLS_PO,                 /* 8A8 */
    SRV_CCA_NS_VAL_STARTTLS,                        /* 8A9 */

    /* NAPDEF: BEARER */
    SRV_CCA_NS_VAL_GSM_CSD,                         /* 8AA */
    SRV_CCA_NS_VAL_GSM_GPRS,                        /* 8AB */
    SRV_CCA_NS_VAL_GSM_USSD,                        /* 8AC */
    SRV_CCA_NS_VAL_GSM_SMS,                         /* 8AD */
    SRV_CCA_NS_VAL_CDMA_SMS,                        /* 8AE */
    SRV_CCA_NS_VAL_CDMA_CSD,                        /* 8AF */

    SRV_CCA_NS_VAL_CDMA_PACKET,                     /* 8B0 */
    SRV_CCA_NS_VAL_ANSI_136_GUTS,                   /* 8B1 */
    SRV_CCA_NS_VAL_ANSI_136_CSD,                    /* 8B2 */
    SRV_CCA_NS_VAL_ANSI_136_GPRS,                   /* 8B3 */
    SRV_CCA_NS_VAL_ANSI_136_GHOST,                  /* 8B4 */
    SRV_CCA_NS_VAL_AMPS_CDPD,                       /* 8B5 */
    SRV_CCA_NS_VAL_PDC_CSD,                         /* 8B6 */
    SRV_CCA_NS_VAL_PDC_PACKET,                      /* 8B7 */
    SRV_CCA_NS_VAL_IDEN_SMS,                        /* 8B8 */
    SRV_CCA_NS_VAL_IDEN_CSD,                        /* 8B9 */
    SRV_CCA_NS_VAL_IDEN_PACKET,                     /* 8BA */
    SRV_CCA_NS_VAL_FLEX_REFLEX,                     /* 8BB */
    SRV_CCA_NS_VAL_PHS_SMS,                         /* 8BC */
    SRV_CCA_NS_VAL_PHS_CSD,                         /* 8BD */
    SRV_CCA_NS_VAL_TETRA_SDS,                       /* 8BE */
    SRV_CCA_NS_VAL_TETRA_PACKET,                    /* 8BF */
    SRV_CCA_NS_VAL_MOBITEX_MPAK,                    /* 8C0 */
    SRV_CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP,           /* 8C1 */
    SRV_CCA_NS_VAL_CDMA2000_1X_MOBILE_IP,           /* 8C2 */
    SRV_CCA_NS_VAL_WLAN,    /* OMA Extension */

    /* NAPDEF: CALLTYPE */
    SRV_CCA_NS_VAL_ANALOG_MODEM,                    /* 8C3 */
    SRV_CCA_NS_VAL_V120,                            /* 8C4 */
    SRV_CCA_NS_VAL_V110,                            /* 8C5 */
    SRV_CCA_NS_VAL_X31,                             /* 8C6 */
    SRV_CCA_NS_VAL_BIT_TRANSPARENT,                 /* 8C7 */
    SRV_CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE,       /* 8C8 */

    /* NAPDEF: LINKSPEED */
    /* NAPDEF: DNLINKSPEED */
    SRV_CCA_NS_VAL_AUTOBAUDING,                     /* 8C9 */

    /* NAPDEF/NAPAUTHINFO: AUTHTYPE */
    SRV_CCA_NS_VAL_PAP,                             /* 8CA */
    SRV_CCA_NS_VAL_CHAP,                            /* 8CB */
    SRV_CCA_NS_VAL_MD5,                             /* 8CC */

    /* NAPDEF/NAPAUTHINFO: AUTH-ENTITY */
    SRV_CCA_NS_VAL_AAA,                             /* 8CD */
    SRV_CCA_NS_VAL_HA,                              /* 8CE */

    /* APPLICATION */
    SRV_CCA_NS_VAL_RESTRICTED,                      /* 8CF */
    SRV_CCA_NS_VAL_WARNING,                         /* 8D0 */
    SRV_CCA_NS_VAL_FREE,                            /* 8D1 */
    SRV_CCA_NS_VAL_ENABLE,                          /* 8D2 */
    SRV_CCA_NS_VAL_DISABLE,                         /* 8D3 */
    SRV_CCA_NS_VAL_LOCKED,                          /* 8D4 */

    /* APPLICATION/APPAUTH: AAUTHLEVEL */
    SRV_CCA_NS_VAL_APPSRV,                          /* 8D5 */
    SRV_CCA_NS_VAL_OBEX,                            /* 8D6 */

    /* Conversion from Nokia OTA Spec */
    /* PROXY: LOGINTYPE */
    /* NAPDEF: LOGINTYPE */
    SRV_CCA_NS_VAL_AUTOMATIC,                       /* 8D7 */
    SRV_CCA_NS_VAL_MANUAL,                          /* 8D8 */

    /* OMA Extension */
    /* WLAN: NETMODE */
    SRV_CCA_NS_VAL_INFRA,                           /* 8D9 */
    SRV_CCA_NS_VAL_ADHOC,                           /* 8DA */

    /* WLAN: SECMODE */
    SRV_CCA_NS_VAL_WEP,                             /* 8DB */
    SRV_CCA_NS_VAL_8021X,                           /* 8DC */
    SRV_CCA_NS_VAL_WPA,                             /* 8DD */
    SRV_CCA_NS_VAL_WPA_PRESHARED_KEY,               /* 8DE */
    SRV_CCA_NS_VAL_WPA2,                            /* 8DF */
    SRV_CCA_NS_VAL_WPA2_PRESHARED_KEY,              /* 8E0 */

    /* WLAN: WEPAUTHMODE */
    SRV_CCA_NS_VAL_OPEN,                            /* 8E1 */
    SRV_CCA_NS_VAL_SHARED,                          /* 8E2 */

    /* WLAN: EAP-TYPE */
    SRV_CCA_NS_VAL_EAP_SIM,                         /* 8E3 */
    SRV_CCA_NS_VAL_EAP_AKA,                         /* 8E4 */
    SRV_CCA_NS_VAL_EAP_TLS,                         /* 8E5 */
    SRV_CCA_NS_VAL_EAP_PEAP,                        /* 8E6 */
    SRV_CCA_NS_VAL_EAP_TTLS,                        /* 8E7 */
    SRV_CCA_NS_VAL_EAP_LEAP,                        /* 8E8 */
    SRV_CCA_NS_VAL_EAP_MSCHAPV2,                    /* 8E9 */
    SRV_CCA_NS_VAL_EAP_GTC,                         /* 8EA */

    /* WLAN: CERT-TYPE */
    SRV_CCA_NS_VAL_USER,                            /* 8EB */
    SRV_CCA_NS_VAL_CA,                              /* 8EC */

    /* SIM MMS Profile : EFmmicp */
    SRV_CCA_NS_VAL_IMPL_WAP,                        /* 8ED */
    SRV_CCA_NS_VAL_IMPL_UNKNOWN,                    /* 8EE */
    SRV_CCA_NS_VAL__OMA_LAST
} srv_cca_oma_values_enum;

/* DMP Spec */
typedef enum
{
    SRV_CCA_NS_VAL__OMADMP_START = (0x0000 | SRV_CCA_NS_VAL__SECTION_OMADMP),

    /* SIP: PREFER-CODEC */
    SRV_CCA_NS_VAL_G711A,                           /* 9C1 */
    SRV_CCA_NS_VAL_G711U,                           /* 9C2 */
    SRV_CCA_NS_VAL_G726_16,                         /* 9C3 */
    SRV_CCA_NS_VAL_G726_24,                         /* 9C4 */
    SRV_CCA_NS_VAL_G726_32,                         /* 9C5 */
    SRV_CCA_NS_VAL_G726_40,                         /* 9C6 */

    /* SIP - PXSRV-ADDRTYPE */
    //SRV_CCA_NS_VAL_IPV4,
    //SRV_CCA_NS_VAL_IPV6,
    //SRV_CCA_NS_VAL_ALPHA,

    /* SIP - REGSRV-ADDRTYPE */
    //SRV_CCA_NS_VAL_IPV4,
    //SRV_CCA_NS_VAL_IPV6,
    //SRV_CCA_NS_VAL_ALPHA,

    /* SIP - OUTPXSRV-ADDRTYPE */
    //SRV_CCA_NS_VAL_IPV4,
    //SRV_CCA_NS_VAL_IPV6,
    //SRV_CCA_NS_VAL_ALPHA,

    /* SIP - NAT-RPORT-ENABLED */
    //SRV_CCA_NS_VAL_ENABLED,
    //SRV_CCA_NS_VAL_DISABLED,

    /* SIP - NAT-STUN-ENABLED */
    //SRV_CCA_NS_VAL_ENABLED,
    //SRV_CCA_NS_VAL_DISABLED,

    /* SIP - NAT-STUNSRV-ADDRTYPE */
    //SRV_CCA_NS_VAL_IPV4,
    //SRV_CCA_NS_VAL_IPV6,
    //SRV_CCA_NS_VAL_ALPHA,

    SRV_CCA_NS_VAL__OMADMP_LAST
} srv_cca_omadmp_values_enum;


#ifdef __BUILD_DOM__
/* Primitive used in CCA architecture*/
typedef enum
{
    MSG_ID_SRV_CCA_APP_CONFIGURE_IND,               /*CCA sends this primitive to target application to configuration this applicaiton */
    MSG_ID_SRV_CCA_APP_CONFIGURE_RSP,               /* Target application sends the primitive to CCA to return the configuration result */
    MSG_ID_SRV_CCA_SOURCE_NEW_DOC_IND,              /* Configuration source sends this primitive to CCA to indicate a new CCA doc is parsed */
    MSG_ID_SRV_CCA_SOURCE_NEW_DOC_RSP,              /* CCA sends this primitive to configuration source to indicate this result ot this configuration */
    MSG_ID_SRV_CCA_SOURCE_UI_INVALID_SETTING_IND,   /* Configuration source sends this primitive to CCA to indicate an invalid message is received */
    MSG_ID_SRV_CCA_SOURCE_UI_NEW_SETTING_IND,       /* Configuration source sends this primitive to CCA to indicate a new message is received */
    MSG_ID_SRV_CCA_SOURCE_UI_NEW_SETTING_RSP,       /* CCA sends this primitive to configuration source to indicate that CCA is ready to process this message */
    MSG_ID_SRV_CCA_SOURCE_UI_AUTH_IND,              /* Configuration source sends this primitive to CCA to indicate that this message new authorization */
    MSG_ID_SRV_CCA_SOURCE_UI_AUTH_RSP,              /* CCA sends this primitive to configuration source the user authrozation input for verification */
    MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND,            /* CCA sends this primitive to itsef to start a sync process */
    MSG_ID_SRV_CCA_GET_PROF_IND,                    /* DM sends this primitive to CCA to get some application's profile information */
    MSG_ID_SRV_CCA_GET_PROF_RSP,                    /* CCA sends this primitive to DM to feedback the application's profile information */
    MSG_ID_SRV_CCA_APP_GET_PROF_IND,                /* CCA sends this primitive to target application to get its profile information */
    MSG_ID_SRV_CCA_APP_GET_PROF_RSP,                /* Target application sends this primitive to CCA to feedback its profile information */
    MSG_ID_SRV_CCA_UPDATE_PROF_IND,                 /* DM sends this primitive to CCA to update some application's profile information */
    MSG_ID_SRV_CCA_UPDATE_PROF_RSP,                 /* CCA sends this primitive to DM to feedback the result of updating target application's profile information */
    MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND,             /* CCA sends this primitive to target application to update its profile information */
    MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP,             /* Target application sends this primitive to CCA to feedback the result of updating its profile information */
    MSG_ID_SRV_CCA_SOURCE_SIM_PROFILE_STATUS_IND,   /* SPA sends this primitive to CCA to indicate the SIM profile status */
    MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND,      /* CCA sends this primitive to target application to indicate the SIM profile status */
    MSG_ID_SRV_CCA_SOURCE_CCA_READY_IND,            /* CCA sends this primitive to configuration source and target application to indicate CCA is ready */
    MSG_ID_SRV_CCA_SESSION_BEGIN_IND,               /* DM sends this primitive to CCA to start a DM session */    
    MSG_ID_SRV_CCA_SESSION_BEGIN_RSP,               /* CCA sends this primitive to DM with result of if agree to start this DM session */
    MSG_ID_SRV_CCA_SESSION_END_IND,                 /* DM sends this primitive to CCA to end current DM session */
    MSG_ID_SRV_CCA_SESSION_END_RSP,                 /* CCA sends this primitive to agree end current DM session */
    MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ,            /* ProvBox sends this primitive to CCA to process one provisioning message */
    MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF,            /* CCA sends this process result back to ProvBox */
    MSG_ID_SRV_CCA_SOURCE_INSTALL_PROV_MSG_REQ,     /* CCA sends this primitive to configuration source to parse one provisisioning message */
    MSG_ID_SRV_CCA_SOURCE_INSTALL_PROV_MSG_CNF,     /* Configuraiton source sends this primitive to CCA with the CCA doc parsed generated */
    
}msg_id_srv_cca_enum;
#endif /* __BUILD_DOM__ */


/*----------------------------------------------------------------------------*/
/* Symbol End                                                                 */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Typedef in Structure                                                       */
/*----------------------------------------------------------------------------*/
typedef S32                                     SRV_CCA_HANDLE;
#define SRV_CCA_INVALID_HANDLE                  (0)

typedef struct cca_core_data_st						srv_cca_core_data_struct;
typedef struct cca_iterator_st						srv_cca_iterator_struct;

typedef srv_cca_status_enum(*SRV_CCA_FP_APP_CHECK) (U16 config_id, S32 hConfig, srv_cca_iterator_struct *iter_datalist);

typedef srv_cca_status_enum(*SRV_CCA_FP_PARAM_PROC) (S32 hConfig,
                                             U16 param_symbol, srv_cca_core_data_struct *data, void *user_data);

typedef srv_cca_status_enum(*SRV_CCA_FP_NODE_PROC) (S32 hConfig,
                                            S32 hNode,
                                            U16 node_symbol, srv_cca_iterator_struct *iter_datalist, void *user_data);


/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* primitive structures                                           */
/*----------------------------------------------------------------*/

/* Application configuration result, the result can be skipped, updated, configured, invalid settings... */
typedef struct
{
    U16 config_id;                              /* Config id of one application */
    srv_cca_status_enum result;                 /* Configuration result of one application */
} srv_cca_app_config_result_struct;


/* Structure of the primitive of MSG_ID_SRV_CCA_APP_CONFIGURE_IND,
 to indicate some applications needs to be configurated by this provisioning message,
 CCA sends this primitvie to each applications to be configured by this message one by one, 
 each application should sents the related response primitive once handles its profiles as any time */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    srv_cca_prov_type_enum prov_type;           /* Provisioning message type */
    U32 prov_flag;                              /* Provisioning message flags, to indicate some status or actions */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum, to indicate from which SIM card to receive this messages */
    U16 config_id;                              /* Configuration id */
    S32 hConfig;                                /* Handle of CCA Doc */
    S32 num_symbols;                            /* The number of Level 1 symbols in this messsage or how many "CHARACTISTIC" in this provisining XML file */
    U16 l1symbols[SRV_CCA_TREE_MAX_CHILDS];     /* The Level 1 symbols, it's real number is stored in num_symbols fields */
    S32 l1symbols_count[SRV_CCA_TREE_MAX_CHILDS]; /* The count of each Level 1 symbols */
} srv_cca_app_configure_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_APP_CONFIGURE_RSP,
  to indicate the result of current application's configuration, 
  this primitive should be sent to  CCA at any time once current applicaiton processs its profiles done */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 config_id;                              /* Configuration id */
    S32 hConfig;                                /* Handle of CCA doc */
    srv_cca_status_enum status;                 /* the result status of this configuraiton of current application */
} srv_cca_app_configure_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_NEW_DOC_IND,
   it's used by configuration sources such as PRS, SPA, DM to indicate a new CCA doc is generated and to be parsed by CCA. */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning message type */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 spec_id;                                /* Spec id */
    srv_cca_sec_type_enum sec_type;             /* Security type */
    S32 hConfig;                                /* handle of CCA doc */
    U32 prov_flag;                              /* Provisioning message flags */
} srv_cca_src_new_doc_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP,
   it's used by CCA to indicate configuration source that current CCA doc is processed done */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning typoe */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 spec_id;                                /* Spec id */
    srv_cca_app_config_result_struct app_config_result[SRV_CCA_MAX_APPS];   /* Configuration results of those applicaitons configured by this message */
    U8 config_num;                              /* The number of applications configured by this message */
    srv_cca_status_enum msg_config_result;      /* The configuration result of this message wholely */
    srv_cca_status_enum status;                 /* Result of this configuration */
} srv_cca_src_new_doc_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND,
  it's used by Configuration source to indicate CCA that an invalid provisioning message is received or current provisioninging messsage is invalid,
  CcaApp may should invalid message popup or indication to end user. */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    S32 trans_id;                               /* Transaction id, to indicate one transaction */
    U32 msg_id;                                 /* provisioning message id */
    srv_cca_status_enum status;                 /* the reason to cause it's invalid, may be memory full, corrupt data, not support format and so on */
} srv_cca_src_invalid_setting_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND,
   it's used by configuration source to indicate CCA that there is a new provisioning messasge is received,
   CcaApp may notify NMGR to show new messsage indication and play new message tone */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    S32 trans_id;                               /* Transation id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum, to indicate from which SIM card to receive this message  */
    U16 spec_id;                                /* Spec id */
    S32 num_apps;                               /* Number of applications to be configured by this new message */
    U16 app_ids[SRV_CCA_MAX_APPS];              /* Applications to be configured by this new message */
} srv_cca_src_new_setting_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP,
 it's usd by CCA to indicate configuration source that CCA starts to process this new message and 
  please Configuration source to parse the WBXML original message data and generate CCA doc then send it to CCA for further parsing */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioninging message */
    S32 trans_id;                               /* Transation id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    srv_cca_status_enum response;               /* The result of this action, may be ABORT to discard this messasge handling */
} srv_cca_src_new_setting_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_AUTH_IND,
  it's used by Configuration source to indicate CCA that this message need PIN verification or PIN verification is no ok */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning message type */
    S32 trans_id;                               /* Transaction id */
    U16 spec_id;                                /* Spec id */
    S32 max_attempts;                           /* Max attempts to input the PIN code, if more that this attempts, may be discard this messsage or cancel current installation */
    srv_cca_status_enum status;                 /* The status of current PIN verification */
} srv_cca_src_auth_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_AUTH_RSP,
   it's used by CCA to send the PIN code to configuration source for verication */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */     
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    S32 trans_id;                               /* Transation id */
    CHAR pin[SRV_CCA_MAX_PIN_CHARS + 1];          /* PIN code input now */
    srv_cca_status_enum status;                 /* The result of current PIN input, such as canceled or more that the max attempts */
} srv_cca_src_auth_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_SIM_PRIFLE_STATUS_IND,
  it belongs to SIM provisioning feature, to let SPA indicate CCA about the SIM profile status when SIM changed */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 spec_id;                                /* Spec id */
    U32 prov_flag;                              /* Provisioning message flag */
} srv_cca_src_sim_profile_status_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND, 
it belongs to SIM provisioning feature, to let CCA transfer the SIM profile status to the proper APs when SIM changed */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 config_id;                              /* Configuration id */
    U16 spec_id;                                /* Spec id */
    U32 prov_flag;                              /* Provisioning flag */
} srv_cca_app_sim_profile_status_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_READY_IND, 
  to indicate CCA is ready when power on */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    srv_cca_status_enum status;                 /* Status */
} srv_cca_ready_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ,
   it belongs to Provisioniong Inbox feature, ProvBoxUI sends this primitive to CCA to install one provisioning message */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 msg_id;                                 /* Message id */
    S32 trans_id;                               /* Transaction id */
} srv_cca_process_prov_msg_req_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF,
   it belongs to Provisioning Inbox feature, CCA sends this primitive back to ProvBoxUI to sync the installation result */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 msg_id;                                 /* Message id */
    S32 trans_id;                               /* Transation id */
    srv_cca_status_enum status;                 /* Process result status */
} srv_cca_process_prov_msg_cnf_struct;

/* Structure for MSG_ID_SRV_CCA_SRV_INSTALL_PROV_MSG_REQ, 
 it belongs to Provisioning Inbox feature, CCA sends this primtive to PRS, PRS will get message data from inbox and parse it to CCA doc later */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 msg_id;                                 /* Message id */
    S32 trans_id;                               /* Transaction id */
    U16 source_id;                              /* Configuration source id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    U32 prov_flag;                              /* Provisioning flag */
} srv_cca_src_install_prov_msg_req_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF,
  it belongs to Provisioning Inbox feature,  PRS sends this primitive to CCA to indicate the installation of CCA/PRS end is done */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U32 msg_id;                                 /* Message id */
    S32 trans_id;                               /* Transaction id */
    U16 source_id;                              /* Configuration source id */    
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    srv_cca_prov_type_enum prov_type;           /* Provisioning type */
    U32 prov_flag;                              /* Provisioning type */
    srv_cca_status_enum status;                 /* Installation result */
} srv_cca_src_install_prov_msg_cnf_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_GET_PROF_IND,
  it belongs to DM session feature,  DM sends this message to CCA to get some AP's profile */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS... */
    S32 prof_id;                                /* Profile id to retrieve, can be SRV_CCA_PROF_CURRENT or >=0 values, to get current actived profile or the profile with specific profile id */
} srv_cca_get_prof_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_GET_PROF_RSP, 
   it belongs to DM session feature, CCA send the get profile response to DM with CCA document */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS... */
    S32 prof_id;                                /* Profile id to retrieve, can be SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;                                /* Handle of CCA doc with the info of the profile to operate on */
    srv_cca_status_enum result;                 /* Operation result, can be SRV_CCA_STATUS_OK, SRV_CCA_STATUS_FAIL, SRV_CCA_STATUS_MEMFULL and so on */
} srv_cca_get_prof_rsp_struct;

/* Strucure for the primitive of MSG_ID_SRV_CCA_APP_GET_PROF_IND,
   it belongs to DM session feature, CCA transfer DM get profile request to some application */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, can be SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS... */
    S32 prof_id;                                /* Profile id to retrieve, can be SRV_CCA_PROF_CURRENT or >=0 values */
} srv_cca_app_get_prof_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_APP_GET_PROF_RSP,
  it belongs to DM session feature,  Target application sends the result of getting profile to CCA with profile information in CCA doc */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, can be SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS and so on */
    S32 prof_id;                                /* Profile id to retrieve, can be SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;                                /* Handle of CCA doc */
    srv_cca_status_enum result;                 /* Operation result, can be SRV_CCA_STATUS_OK, SRV_CCA_STATUS_FAIL, SRV_CCA_STATUS_MEMFULL and so on */
} srv_cca_app_get_prof_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_UPDATE_PROF_IND, 
  it belongs to DM session feature,  DM sends the request of updating profile to CCA by this primitive */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS and so on */
    S32 prof_id;                                /* Profile id to update, can be SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;
} srv_cca_update_prof_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_UPDATE_PROF_RSP,
  it belongs to DM session feature,  CCA sends the response of updating profile from target application to DM via this primitive */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS and so on */
    S32 prof_id;                                /* Profile id to update, such as SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;                                /* Handle of CCA doc */
    srv_cca_status_enum result;                 /* Operation result */
} srv_cca_update_prof_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND,
  it belongs to DM session feature, CCA transfer DM's updating profile request to target application via this primitive */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id, such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS and so on */
    S32 prof_id;                                /* Profile id to update, can be SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;                                /* handle of CCA doc */
} srv_cca_app_update_prof_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP,
  it belongs to DM session feature, Target application sends the response of updating profile to CCA via this primitive */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 app_id;                                 /* Target application id , such as SRV_CCA_APP_DTACCT, SRV_CCA_APP_BROWSER, SRV_CCA_APP_MMS and so on */
    S32 prof_id;                                /* Profile id to update, sucha as SRV_CCA_PROF_CURRENT or >=0 values */
    S32 hConfig;                                /* Handle of CCA doc */    
    srv_cca_status_enum result;                 /* Operation result, can be SRV_CCA_STATUS_OK, SRV_CCA_STATUS_FAIL, SRV_CCA_STATUS_MEMFULL and so on */
} srv_cca_app_update_prof_rsp_struct;


/* Structure for the primitive of MSG_ID_SRV_CCA_SESSION_BEGIN_IND,
  it belongs to DM session feature, DM sends this to CCA to indicate a session is started */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 session_id;                             /* Session id */
    srv_cca_session_type_enum session_type;     /* Session type */
} srv_cca_session_begin_ind_struct;             

/* Structure for the primitive of MSG_ID_SRV_CCA_SESSION_BEGING_RSP,
  it belongs to DM session feature, CCA send this response of sesion begging to DM */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 session_id;                             /* Session id */
    srv_cca_session_type_enum session_type;     /* Session type */
    srv_cca_status_enum result;                 /* Operation result */
} srv_cca_session_begin_rsp_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SESSION_END_IND, 
   it belongs to DM session feature, DM send this primitive to end a session */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 session_id;                             /* Session id */
    srv_cca_session_type_enum session_type;     /* Session type */
} srv_cca_session_end_ind_struct;

/* Structure for the primitive of MSG_ID_SRV_CCA_SESSION_END_RSP,
  it belongs to DM session feature, CCA sends this response of session ending to DM */
typedef struct
{
    LOCAL_PARA_HDR                              /* Local parameter head */
    U16 source_id;                              /* Configuration source id */
    U16 sim_id;                                 /* SIM id, refer to mmi_sim_enum */
    U16 session_id;                             /* Session id */
    srv_cca_session_type_enum session_type;     /* Session type */
    srv_cca_status_enum result;                 /* Operation result */
} srv_cca_session_end_rsp_struct;



/*----------------------------------------------------------------*/
/* CCA document structures                                        */
/*----------------------------------------------------------------*/
typedef struct cca_core_data_st
{
    union
    {
        S32 *i;
        CHAR **s;
    } values;
    U16 id;
    S8 size; //S8 is ok now.
    U8 type; //srv_cca_data_type_enum type;
} srv_cca_core_data_struct;


/* Will not export after split */
typedef struct cca_generic_ptr_st
{
    struct cca_generic_ptr_st *next;
    struct cca_generic_ptr_st *parent;
    struct cca_generic_ptr_st *child;
} srv_cca_generic_ptr_struct;


/* Will not export after split, please use SRV_CCA_HANDLE h_iterator */
typedef struct cca_iterator_st
{
    srv_cca_generic_ptr_struct *current;
    srv_cca_generic_ptr_struct *head_node;
    srv_cca_generic_ptr_struct *prev_node;
    srv_cca_traverse_type_enum traverse_type;
    srv_cca_iter_type_enum iter_type;
    U8 deep_delete; /* 0: false, 1: true */
    S8 crt_level;  /* The recursion level*/
} srv_cca_iterator_struct;

typedef struct
{
    U16 config_id;
    U8 num_appids;
    U8 num_l1node_symbols;
    const CHAR **appids;
    const U16 *l1node_symbols;
    SRV_CCA_FP_APP_CHECK app_check_doc_hdlr;
    MMI_BOOL support_sim_prov;
} srv_cca_app_config_struct;


typedef struct
{
    SRV_CCA_HANDLE h_config;
    CHAR *nap_node_id;
    CHAR *proxy_node_id;
    S32 dtcnt_id;
}srv_cca_dtcnt_id_para_struct;

/*----------------------------------------------------------------*/
/* Event and structures                                           */
/*----------------------------------------------------------------*/

typedef enum
{
	EVT_ID_SRV_CCA_READY = SRV_CCA_BASE + 1,
    EVT_ID_SRV_CCA_CHECK_APP_CONFIG,            //to replace cca_app_config_g

    
    EVT_ID_SRV_CCA_MAX_ITEM
} evt_id_srv_cca_enum;


typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CCA_HANDLE h_cca;                       /* Handle of CCA */
    srv_cca_status_enum status;                 /* Status code */
}srv_cca_evt_ready_struct;

/* It's a sync event in send mode, APP should return a const app_config info */
typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    SRV_CCA_HANDLE h_cca;                       /* Handle of CCA */
    U16 config_id;                              /* Configuration id */    

    /* The following info is filled by AP */
    SRV_CCA_FP_APP_CHECK App_check_doc_hdlr;    /* Application's callback to check the CCA doc, APP check doc to see if it's interesting with this message */
    const CHAR **appids;
    S32 num_appids;                             
    const U16 *l1node_symbols;
    S32 num_l1node_symbols;
    MMI_BOOL support_sim_prov;
}srv_cca_evt_check_app_config_struct;




/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/* Core Data */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_check
 * DESCRIPTION
 *  To check if a core data handle is valid
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_coredata_check(SRV_CCA_HANDLE h_coredata);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_data_type
 * DESCRIPTION
 *  To get the data type of this core data
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern S32 srv_cca_doc_coredata_get_data_type(SRV_CCA_HANDLE h_coredata);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_param_id
 * DESCRIPTION
 *  To get the param id of this core data
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern S32 srv_cca_doc_coredata_get_param_id(SRV_CCA_HANDLE h_coredata);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_num
 * DESCRIPTION
 *  To get the value number of this core data
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern S32 srv_cca_doc_coredata_get_num(SRV_CCA_HANDLE h_coredata);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_int
 * DESCRIPTION
 *  To get the integer value of this core data by index
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *  index :              [IN]   The index of the value to get
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern S32 srv_cca_doc_coredata_get_int(SRV_CCA_HANDLE h_coredata, S32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_str
 * DESCRIPTION
 *  To get the string value of this core data by index
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *  index :              [IN]   The index of the value to get
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern CHAR *srv_cca_doc_coredata_get_str(SRV_CCA_HANDLE h_coredata, S32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_ints
 * DESCRIPTION
 *  To get all the integer values of this core data
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_coredata_get_ints(SRV_CCA_HANDLE h_coredata, S32 **values, S32 *num);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_strs
 * DESCRIPTION
 *  To get all the string values of the core data
 * PARAMETERS
 *  h_coredata :         [IN]   Handle of core data
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_coredata_get_strs(SRV_CCA_HANDLE h_coredata, CHAR **values, S32 *num);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_update_int
 * DESCRIPTION
 *  To update the coredata value by index, if index < 0, just replace all old values with specified new value
 * PARAMETERS
 *  h_coredata :         [IN]  Handle of coredata
 *  value :         [IN]   Integer value
 *
 * RETURNS
 *  h_node
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_coredata_update_int(SRV_CCA_HANDLE h_coredata, S32 index, S32 value);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_update_str
 * DESCRIPTION
 *  To update the coredata value by index, if index < 0, just replace all old values with specified new value
 * PARAMETERS
 *  h_coredata :         [IN]  Handle of coredata
 *  value :         [IN]   String value
 *
 * RETURNS
 *  h_node
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_coredata_update_str(SRV_CCA_HANDLE h_coredata, S32 index, const CHAR *value);


/* Node */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_new_ex
 * DESCRIPTION
 *  To generate the node with specified node symbol and assign it a parent node
 * PARAMETERS
 *  h_parent_node :         [IN]   The parent node of this new node, if it's NULL, node_symbol should be SRV_CCA_NS_DOCROOT
 *  node_symbol :         [IN]   Node symbol
 *
 * RETURNS
 *  h_node
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern SRV_CCA_HANDLE srv_cca_doc_node_create(U16 node_symbol, SRV_CCA_HANDLE h_parent_node);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_duplicate_ex
 * DESCRIPTION
 *  To duplicate the node with specified node symbol and assign it a parent node
 * PARAMETERS
 *  h_parent_node :         [IN]   The parent node of this new node, if it's NULL, node_symbol should be SRV_CCA_NS_DOCROOT
 *  node_symbol :         [IN]   Node symbol
 *
 * RETURNS
 *  h_node
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern SRV_CCA_HANDLE srv_cca_doc_node_clone(U16 node_symbol, SRV_CCA_HANDLE h_parent_node);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_destroy
 * DESCRIPTION
 *  To destroy a node recursively, all sub-mode will be release accordingly
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern void srv_cca_doc_node_destroy(SRV_CCA_HANDLE h_node);

/* Node Data */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_add_int
 * DESCRIPTION
 * To add an integer value to the core data with specified param id of this node 
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *  param_id :         [IN]   Param id
 *  value :         [IN]   Value to add
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_node_add_int(SRV_CCA_HANDLE h_node, U16 param_id, S32 value);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_add_str
 * DESCRIPTION
 * To add a string value to the core data with specified param id of this node 
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *  param_id :         [IN]   Param id
 *  value :         [IN]   Value to add
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_node_add_str(SRV_CCA_HANDLE h_node, U16 param_id, const CHAR *value);

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_get_data
 * DESCRIPTION
 * To get the handle of the core data with specified param id 
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *  param_id :         [IN]   Param id
 *  value :         [IN]   Value to add
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_node_get_data(SRV_CCA_HANDLE h_node, U16 param_id, SRV_CCA_HANDLE *h_coredata);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_update_int
 * DESCRIPTION
 * To update the integer value 
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *  param_id :         [IN]   Param id
 *  value :         [IN]   Value to add
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_nodedata_update_int(SRV_CCA_HANDLE h_node, U16 param_id, S32 value);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_update_str
 * DESCRIPTION
 * To update the string value 
 * PARAMETERS
 *  h_node :         [IN]   Handler of node
 *  param_id :         [IN]   Param id
 *  value :         [IN]   Value to add
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_nodedata_update_str(SRV_CCA_HANDLE h_node, U16 param_id, const CHAR *value);


/* Iterator */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iterator_new
 * DESCRIPTION
 *  To new the iterator handler
 * PARAMETERS
 *  
 *
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/

/*
typedef struct
{
    srv_cca_traverse_type_enum traverse_type;
    srv_cca_iter_type_enum  iter_type;
    SRV_CCA_HANDLE h_head;
    srv_cca_iter_head_type_enum iter_head_type;
    U32 flags;
}srv_cca_doc_iterator_para_struct;


extern SRV_CCA_HANDLE srv_cca_doc_iterator_new(void);
*/


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  To restart the iterator
 * PARAMETERS
 *  h_iter :         [IN]   Handler of iterator
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern SRV_CCA_HANDLE srv_cca_doc_iterator_restart(SRV_CCA_HANDLE h_iter);

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  To iterate next elment
 * PARAMETERS
 *  h_iter :         [IN]   Handler of iterator
 *  h_obj :          [IN]   Handler of object encapsulated in the element of current iterator position
 * RETURNS
 *  return the element of current iterator postion
 * RETURN VALUES
 *
 * Warning:  The h_obj is unused now.
 *
 *****************************************************************************/
extern SRV_CCA_HANDLE srv_cca_doc_iterator_next(SRV_CCA_HANDLE h_iter, SRV_CCA_HANDLE *h_obj);



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iterator_create_node_iter
 * DESCRIPTION
 *  To create the node list iterator from the CCA documents, should destroy it via srv_cca_iterator_destroy
 * PARAMETERS
 *  h_config :         [IN]   CCA documents
 *  node_symbol :         [IN]   Node symbol
 *  h_iter_nodelist :         [IN]   The iterator of the node list with spefied node symbol
 *  size :         [IN]   Size of the node list
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_iterator_create_node_iter(
                        SRV_CCA_HANDLE h_config,
                        U16 node_symbol,
                        SRV_CCA_HANDLE *h_iter_nodelist,
                        S32 *size);



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iterator_create_nodedata_iter
 * DESCRIPTION
 *  To create the iterator of the data list from the iterator of the node list,
 *  should destroy it via srv_cca_iterator_destro
 * PARAMETERS
 *  h_iter_nodelist :         [IN]   The iterator of the node list with spefied node symbol
 *  h_iter_datalist :         [IN]   The iterator of the core data list got
 *  size :         [IN]   Size of the data list
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_iterator_create_nodedata_iter(
                        SRV_CCA_HANDLE h_iter_nodelist,
                        SRV_CCA_HANDLE *h_iter_datalist,
                        S32 *size);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iterator_destroy
 * DESCRIPTION
 *  To free the iterator handler
 * PARAMETERS
 *  h_iter :         [IN]   Handler of iterator
 *
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern void srv_cca_doc_iterator_destroy(SRV_CCA_HANDLE h_iter);




/* Doc */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_new
 * DESCRIPTION
 *  To new the cca document with the specified root node.
 * PARAMETERS
 *  h_root_node :         [IN]   Handler of the root node
 *
 * RETURNS
 * h_config  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_create(srv_cca_spec_enum spec_type, 
                                              SRV_CCA_HANDLE h_root_node, SRV_CCA_HANDLE *h_config);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_destroy
 * DESCRIPTION
 *  To free a CCA doc
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern void srv_cca_doc_destroy(SRV_CCA_HANDLE h_config);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_process
 * DESCRIPTION
 *  To parse a CCA docm, this API is called by one AP who want to parse the CCA doc.
 *  the mapping table is used as a filter to filter which node or param is interested 
 *  by this AP.  this AP first to parse the mapping table to generate a filter, then
 *  to parse the CCA doc tree, it will call param_proc to parse this param when find
 *  a param or call node_proc to parse this node when find a node which is interested
 *  by this AP via the filter table. 
 *  
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 * RETURN VALUES
 *
 *
 *
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_doc_process(
                        SRV_CCA_HANDLE h_config,
                        const U16 *mapping_table,
                        S32 tbl_size,
                        SRV_CCA_FP_PARAM_PROC param_proc,
                        SRV_CCA_FP_NODE_PROC node_proc,
                        void *user_data);


/* OMA */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_make_new_node_id
 * DESCRIPTION
 *  To generate a new node id.
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern CHAR *srv_cca_oma_make_new_node_id(void); //(srv_cca_id_type_enum id_type, void *data, S32 data_size)?


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_free_id
 * DESCRIPTION
 *  To free an node id
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern void srv_cca_oma_free_id(CHAR *cca_id);  /* use to free node_id or proxy_id generated by CCA */



/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_generate_virtual_proxy_node
 * DESCRIPTION
 *  To generate a virtual proxy node. In Provisioning message, an APPLICATION
 * node can refer to a NAPDEF (data account node)node directly without any proxy
 * node between them which means no proxy is needed here, but to unified the 
 * installation process,  CCA will generate a virtual proxy node and insert it
 * between the APPLICATION and NAPDEF node. this API is to do this work.
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern S32 srv_cca_oma_generate_virtual_proxy_node(
            const CHAR *tonapid,
            const CHAR *vrpxy_cca_node_id,
            CHAR **out_new_pxy_id);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_oma_is_virtual_proxy
 * DESCRIPTION
 *  To check if a proxy node is virtual and generated by CCA.
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_BOOL srv_cca_oma_is_virtual_proxy(SRV_CCA_HANDLE h_node);


/*****************************************************************************
 * FUNCTION
 *  srv_cca_add_dtcnt_id
 * DESCRIPTION
 *  To add a data account id which is only used for Data account Service only
 *  Data account service will call this API to add the new data account id just
 * after it intalls one data account profile. by this way, CCA can pass the data
 * account id to each application who use it such as browser, mms, email and so on.
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_add_dtcnt_id(srv_cca_dtcnt_id_para_struct *dtcnt_id_para);

/* Misc */
/*****************************************************************************
 * FUNCTION
 *  srv_cca_generate_hash_value
 * DESCRIPTION
 *  To generate a hash value with fixed length,  Target application can use this 
 * hash value to unique identity one profile in history river forever.
 * PARAMETERS
 *  
 *
 * RETURNS
 *  
 *****************************************************************************/
extern srv_cca_status_enum srv_cca_generate_hash_value(const CHAR *src_string, U8 *dst_buf, S32 buf_len);


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* APIs to be phase out after split,                                          */
/*----------------------------------------------------------------------------*/

#define SRV_CCA_API_PHASE_OUT_AFTER_SPLIT

extern srv_cca_status_enum srv_cca_doc_update_coredata_int(srv_cca_core_data_struct *data_obj, S32 value);
extern srv_cca_status_enum srv_cca_doc_update_coredata_str(srv_cca_core_data_struct *data_obj, const CHAR *value);

extern void srv_cca_doc_node_free(SRV_CCA_HANDLE h_node);

extern SRV_CCA_HANDLE srv_cca_doc_node_new(U16 node_symbol);
extern SRV_CCA_HANDLE srv_cca_doc_node_duplicate(SRV_CCA_HANDLE h_node);

extern srv_cca_status_enum srv_cca_doc_node_attach(S32 hNode, S32 hParentNode);
extern S32 srv_cca_doc_node_new_and_attach(U16 node_symbol, S32 hParentNode);
extern srv_cca_status_enum srv_cca_doc_add_node_to_parent(S32 hNode, S32 hParentNode);

extern void srv_cca_doc_node_detach(S32 hNode);

extern srv_cca_status_enum srv_cca_doc_nodedata_int_first(S32 hNode, U16 param_id, S32 *value);
extern srv_cca_status_enum srv_cca_doc_nodedata_str_first(S32 hNode, U16 param_id, CHAR **value);
extern srv_cca_status_enum srv_cca_doc_nodedata_ints(S32 hNode, U16 param_id, S32 **values, S32 *size);
extern srv_cca_status_enum srv_cca_doc_nodedata_strs(S32 hNode, U16 param_id, CHAR ***values, S32 *size);

extern srv_cca_status_enum srv_cca_doc_nodedata_by_param(S32 hNode, U16 param_id, srv_cca_core_data_struct **data_obj);

extern srv_cca_status_enum srv_cca_doc_nodedata_add_int(S32 hNode, U16 param_id, S32 value);
extern srv_cca_status_enum srv_cca_doc_nodedata_add_str(S32 hNode, U16 param_id, const CHAR *value);

extern srv_cca_status_enum srv_cca_doc_update_nodedata_int(S32 hNode, U16 param_id, S32 value);
extern srv_cca_status_enum srv_cca_doc_update_nodedata_str(S32 hNode, U16 param_id, const CHAR *value);


/* Iterator */
extern void srv_cca_iterator_release(srv_cca_iterator_struct *iter);
extern void *srv_cca_iterator_next(srv_cca_iterator_struct *iter);
extern void srv_cca_iterator_restart(srv_cca_iterator_struct *iter);

/* create node list iterator */
srv_cca_status_enum srv_cca_doc_get_nodes(S32 hConfig, U16 node_symbol, srv_cca_iterator_struct **iter_nodelist, S32 *size);

/* Create data list iterator of one node */
extern srv_cca_status_enum srv_cca_doc_get_nodedata(
                        srv_cca_iterator_struct *iter_nodelist,
                        srv_cca_iterator_struct **iter_datalist,
                        S32 *size);

/* iterator each core data of one data list */
extern srv_cca_status_enum srv_cca_doc_nodedata_next(srv_cca_iterator_struct *iter_datalist, srv_cca_core_data_struct **data_obj);

extern srv_cca_status_enum srv_cca_doc_get_nodedata_int_first(srv_cca_iterator_struct *iter, U16 param_id, S32 *value);
extern srv_cca_status_enum srv_cca_doc_get_nodedata_str_first(srv_cca_iterator_struct *iter, U16 param_id, CHAR **value);
extern srv_cca_status_enum srv_cca_doc_get_nodedata_ints(
                        srv_cca_iterator_struct *iter,
                        U16 param_id,
                        S32 **values,
                        S32 *size);
extern srv_cca_status_enum srv_cca_doc_get_nodedata_strs(
                        srv_cca_iterator_struct *iter,
                        U16 param_id,
                        CHAR ***values,
                        S32 *size);



extern S32 srv_cca_oma_fix_doc(S32 hRoot);
extern S32 srv_cca_oma_generate_deprel_node(S32 hRoot);
extern void srv_cca_oma_sort_new_doc(S32 hRoot);
extern S32 srv_cca_doc_new(S32 hRootNode);

extern srv_cca_status_enum srv_cca_oma_add_dataacctid(S32 hConfig, CHAR *nap_node_id, S32 dataacctid);





/*----------------------------------------------------------------------------*/
/* Adaptor Layer : Should be remove after split is done                       */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

#define CCA_TREE_MAX_CHILDS                             SRV_CCA_TREE_MAX_CHILDS
//#define CCA_TREE_MAX_LEVELS                             SRV_CCA_TREE_MAX_LEVELS
#define CCA_MAX_PIN_CHARS                               SRV_CCA_MAX_PIN_CHARS

//#define CCA_MAX_REF_BY_ENTRIES                          SRV_CCA_MAX_REF_BY_ENTRIES
#define CCA_MAX_APPS                                    SRV_CCA_MAX_APPS

/* for operations on currently activated profile */
#define CCA_PROF_CURRENT                                SRV_CCA_PROF_CURRENT

#define CCA_HASH_VALUE_MAX_BYTES                        SRV_CCA_HASH_VALUE_MAX_BYTES

/* only use for ProvBox */
#define MMI_CCA_INVALID_MSG_ID                          SRV_CCA_INVALID_MSG_ID

/* use for SRV_CCA_PROV_TYPE_OTA_PROV */
#define MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE     SRV_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE

/* use fro SRV_CCA_PROV_TYPE_SIM_PROV */
#define MMI_CCA_PROV_FLAG_SHOW_SIM1_PROFILE             SRV_CCA_PROV_FLAG_SHOW_SIM1_PROFILE
#define MMI_CCA_PROV_FLAG_SHOW_SIM2_PROFILE             SRV_CCA_PROV_FLAG_SHOW_SIM2_PROFILE
#define MMI_CCA_PROV_FLAG_ACTIVATE_SIM1_PROFILE         SRV_CCA_PROV_FLAG_ACTIVATE_SIM1_PROFILE
#define MMI_CCA_PROV_FLAG_ACTIVATE_SIM2_PROFILE         SRV_CCA_PROV_FLAG_ACTIVATE_SIM2_PROFILE

#define MMI_CCA_PROV_FLAG_PIN_VERIFIED                  SRV_CCA_PROV_FLAG_PIN_VERIFIED

/* CCA Node Flag, use internally */

#define MMI_CCA_NODE_FLAG_VIRTUAL_PROXY_NODE            SRV_CCA_NODE_FLAG_VIRTUAL_PROXY_NODE
#define MMI_CCA_NODE_FLAG_VIRTUAL_APPLICATION_NODE      SRV_CCA_NODE_FLAG_VIRTUAL_APPLICATION_NODE

/* Job flag on every phase of job processing */

//#define CCA_JOB_FLAG_ALREADY_IN_LIST                    SRV_CCA_JOB_FLAG_ALREADY_IN_LIST


/*----------------------------------------------------------------------------*/
/* Primitive                                                                  */
/*----------------------------------------------------------------------------*/



/* Old CCA events */
/*
#define PRT_MMI_CCA_APP_CONFIGURE_IND                   MSG_ID_SRV_CCA_APP_CONFIGURE_IND
#define PRT_MMI_CCA_APP_CONFIGURE_RSP                   MSG_ID_SRV_CCA_APP_CONFIGURE_RSP
#define PRT_MMI_CCA_SOURCE_NEW_DOC_IND                  MSG_ID_SRV_CCA_SRC_NEW_DOC_IND
#define PRT_MMI_CCA_SOURCE_NEW_DOC_RSP                  MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP
#define PRT_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND       MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND
#define PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_IND           MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND
#define PRT_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP           MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP
#define PRT_MMI_CCA_SOURCE_UI_AUTH_IND                  MSG_ID_SRV_CCA_SRC_AUTH_IND
#define PRT_MMI_CCA_SOURCE_UI_AUTH_RSP                  MSG_ID_SRV_CCA_SRC_AUTH_RSP
#define PRT_MMI_CCA_NEW_DOC_CONTINUE_IND                MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND
#define PRT_MMI_CCA_GET_PROF_IND                        MSG_ID_SRV_CCA_GET_PROF_IND
#define PRT_MMI_CCA_GET_PROF_RSP                        MSG_ID_SRV_CCA_GET_PROF_RSP
#define PRT_MMI_CCA_APP_GET_PROF_IND                    MSG_ID_SRV_CCA_APP_GET_PROF_IND
#define PRT_MMI_CCA_APP_GET_PROF_RSP                    MSG_ID_SRV_CCA_APP_GET_PROF_RSP
#define PRT_MMI_CCA_UPDATE_PROF_IND                     MSG_ID_SRV_CCA_UPDATE_PROF_IND
#define PRT_MMI_CCA_UPDATE_PROF_RSP                     MSG_ID_SRV_CCA_UPDATE_PROF_RSP
#define PRT_MMI_CCA_APP_UPDATE_PROF_IND                 MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND
#define PRT_MMI_CCA_APP_UPDATE_PROF_RSP                 MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP
#define PRT_MMI_CCA_SOURCE_SIM_PROFILE_STATUS_IND       MSG_ID_SRV_CCA_SRC_SIM_PROFILE_STATUS_IND
#define PRT_MMI_CCA_APP_SIM_PROFILE_STATUS_IND          MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND
#define PRT_MMI_CCA_SOURCE_CCA_READY_IND                MSG_ID_SRV_CCA_SRC_CCA_READY_IND
#define PRT_MMI_CCA_SESSION_BEGIN_IND                   MSG_ID_SRV_CCA_SESSION_BEGIN_IND
#define PRT_MMI_CCA_SESSION_BEGIN_RSP                   MSG_ID_SRV_CCA_SESSION_BEGIN_RSP
#define PRT_MMI_CCA_SESSION_END_IND                     MSG_ID_SRV_CCA_SESSION_END_IND
#define PRT_MMI_CCA_SESSION_END_RSP                     MSG_ID_SRV_CCA_SESSION_END_RSP
#define PRT_MMI_CCA_PROCESS_PROV_MSG_REQ                MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ
#define PRT_MMI_CCA_PROCESS_PROV_MSG_CNF                MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF    
#define PRT_MMI_CCA_SOURCE_INSTALL_PROV_MSG_REQ         MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_REQ 
#define PRT_MMI_CCA_SOURCE_INSTALL_PROV_MSG_CNF         MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF 
*/

/* Old CCA primitive */
/*
#define MSG_ID_MMI_CCA_APP_CONFIGURE_IND                MSG_ID_SRV_CCA_APP_CONFIGURE_IND
#define MSG_ID_MMI_CCA_APP_CONFIGURE_RSP                MSG_ID_SRV_CCA_APP_CONFIGURE_RSP
#define MSG_ID_MMI_CCA_SOURCE_NEW_DOC_IND               MSG_ID_SRV_CCA_SRC_NEW_DOC_IND
#define MSG_ID_MMI_CCA_SOURCE_NEW_DOC_RSP               MSG_ID_SRV_CCA_SRC_NEW_DOC_RSP
#define MSG_ID_MMI_CCA_SOURCE_UI_INVALID_SETTING_IND    MSG_ID_SRV_CCA_SRC_INVALID_SETTING_IND
#define MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_IND        MSG_ID_SRV_CCA_SRC_NEW_SETTING_IND
#define MSG_ID_MMI_CCA_SOURCE_UI_NEW_SETTING_RSP        MSG_ID_SRV_CCA_SRC_NEW_SETTING_RSP
#define MSG_ID_MMI_CCA_SOURCE_UI_AUTH_IND               MSG_ID_SRV_CCA_SRC_AUTH_IND
#define MSG_ID_MMI_CCA_SOURCE_UI_AUTH_RSP               MSG_ID_SRV_CCA_SRC_AUTH_RSP
#define MSG_ID_MMI_CCA_NEW_DOC_CONTINUE_IND             MSG_ID_SRV_CCA_NEW_DOC_CONTINUE_IND
#define MSG_ID_MMI_CCA_GET_PROF_IND                     MSG_ID_SRV_CCA_GET_PROF_IND
#define MSG_ID_MMI_CCA_GET_PROF_RSP                     MSG_ID_SRV_CCA_GET_PROF_RSP
#define MSG_ID_MMI_CCA_APP_GET_PROF_IND                 MSG_ID_SRV_CCA_APP_GET_PROF_IND
#define MSG_ID_MMI_CCA_APP_GET_PROF_RSP                 MSG_ID_SRV_CCA_APP_GET_PROF_RSP
#define MSG_ID_MMI_CCA_UPDATE_PROF_IND                  MSG_ID_SRV_CCA_UPDATE_PROF_IND
#define MSG_ID_MMI_CCA_UPDATE_PROF_RSP                  MSG_ID_SRV_CCA_UPDATE_PROF_RSP
#define MSG_ID_MMI_CCA_APP_UPDATE_PROF_IND              MSG_ID_SRV_CCA_APP_UPDATE_PROF_IND
#define MSG_ID_MMI_CCA_APP_UPDATE_PROF_RSP              MSG_ID_SRV_CCA_APP_UPDATE_PROF_RSP
#define MSG_ID_MMI_CCA_SOURCE_SIM_PROFILE_STATUS_IND    MSG_ID_SRV_CCA_SRC_SIM_PROFILE_STATUS_IND
#define MSG_ID_MMI_CCA_APP_SIM_PROFILE_STATUS_IND       MSG_ID_SRV_CCA_APP_SIM_PROFILE_STATUS_IND
#define MSG_ID_MMI_CCA_SOURCE_CCA_READY_IND             MSG_ID_SRV_CCA_SRC_CCA_READY_IND
#define MSG_ID_MMI_CCA_SESSION_BEGIN_IND                MSG_ID_SRV_CCA_SESSION_BEGIN_IND
#define MSG_ID_MMI_CCA_SESSION_BEGIN_RSP                MSG_ID_SRV_CCA_SESSION_BEGIN_RSP
#define MSG_ID_MMI_CCA_SESSION_END_IND                  MSG_ID_SRV_CCA_SESSION_END_IND
#define MSG_ID_MMI_CCA_SESSION_END_RSP                  MSG_ID_SRV_CCA_SESSION_END_RSP
#define MSG_ID_MMI_CCA_PROCESS_PROV_MSG_REQ             MSG_ID_SRV_CCA_PROCESS_PROV_MSG_REQ
#define MSG_ID_MMI_CCA_PROCESS_PROV_MSG_CNF             MSG_ID_SRV_CCA_PROCESS_PROV_MSG_CNF    
#define MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_REQ      MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_REQ 
#define MSG_ID_MMI_CCA_SOURCE_INSTALL_PROV_MSG_CNF      MSG_ID_SRV_CCA_SRC_INSTALL_PROV_MSG_CNF 
*/


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef srv_cca_sim_id_enum                             mmi_cca_sim_id_enum;

#define MMI_CCA_SIM_ID_DEFAULT                          SRV_CCA_SIM_ID_DEFAULT
#define MMI_CCA_SIM_ID_SIM1                             SRV_CCA_SIM_ID_SIM1
#define MMI_CCA_SIM_ID_SIM2                             SRV_CCA_SIM_ID_SIM2
#define MMI_CCA_SIM_ID_DUAL_SIM                         SRV_CCA_SIM_ID_DUAL_SIM
#define MMI_CCA_SIM_ID_MAX_ITEM                         SRV_CCA_SIM_ID_MAX_ITEM

typedef srv_cca_prov_type_enum                          mmi_cca_prov_type_enum;

#define MMI_CCA_PROV_TYPE_OTA_PROV                      SRV_CCA_PROV_TYPE_OTA_PROV
#define MMI_CCA_PROV_TYPE_SIM_PROV                      SRV_CCA_PROV_TYPE_SIM_PROV
#define MMI_CCA_PROV_TYPE_MAX_ITEM                      SRV_CCA_PROV_TYPE_MAX_ITEM

typedef srv_cca_sec_type_enum                           mmi_cca_sec_type_enum;

#define MMI_CCA_SEC_TYPE_NONE                           SRV_CCA_SEC_TYPE_NONE
#define MMI_CCA_SEC_TYPE_USERPIN                        SRV_CCA_SEC_TYPE_USERPIN
#define MMI_CCA_SEC_TYPE_NETWPIN                        SRV_CCA_SEC_TYPE_NETWPIN
#define MMI_CCA_SEC_TYPE_USERNETWIN                     SRV_CCA_SEC_TYPE_USERNETWIN
#define MMI_CCA_SEC_TYPE_USERPINMAC                     SRV_CCA_SEC_TYPE_USERPINMAC
#define MMI_CCA_SEC_TYPE_UNKNOWN                        SRV_CCA_SEC_TYPE_UNKNOWN
#define MMI_CCA_SEC_TYPE_MAX_ITEM                       SRV_CCA_SEC_TYPE_MAX_ITEM

typedef srv_cca_status_enum                             cca_status_enum;

#define CCA_STATUS_OK                                   SRV_CCA_STATUS_OK
#define CCA_STATUS_FAIL                                 SRV_CCA_STATUS_FAIL

#define CCA_STATUS_INVALID_SETTING                      SRV_CCA_STATUS_INVALID_SETTING
#define CCA_STATUS_SETTING_UPDATED                      SRV_CCA_STATUS_SETTING_UPDATED
#define CCA_STATUS_SETTING_SKIPPED                      SRV_CCA_STATUS_SETTING_SKIPPED
#define CCA_STATUS_ENDKEY_PRESSED                       SRV_CCA_STATUS_ENDKEY_PRESSED
#define CCA_STATUS_ENDKEY_SETTING_UPDATED               SRV_CCA_STATUS_ENDKEY_SETTING_UPDATED
#define CCA_STATUS_ENDKEY_SETTING_INSTALLED             SRV_CCA_STATUS_ENDKEY_SETTING_INSTALLED
#define CCA_STATUS_ENDKEY_SETTING_SKIPPED               SRV_CCA_STATUS_ENDKEY_SETTING_SKIPPED
#define CCA_STATUS_ENDKEY_INVALID_SETTING               SRV_CCA_STATUS_ENDKEY_INVALID_SETTING
#define CCA_STATUS_SETTING_NOT_INSTALLED                SRV_CCA_STATUS_SETTING_NOT_INSTALLED

#define CCA_STATUS_ABORT                                SRV_CCA_STATUS_ABORT
#define CCA_STATUS_ENDLIST                              SRV_CCA_STATUS_ENDLIST
#define CCA_STATUS_MEMFULL                              SRV_CCA_STATUS_MEMFULL
#define CCA_STATUS_NOT_FOUND                            SRV_CCA_STATUS_NOT_FOUND
#define CCA_STATUS_TYPE_MISMATCHED                      SRV_CCA_STATUS_TYPE_MISMATCHED
#define CCA_STATUS_INVALID_ITER                         SRV_CCA_STATUS_INVALID_ITER
#define CCA_STATUS_INVALID_HANDLE                       SRV_CCA_STATUS_INVALID_HANDLE

#define CCA_STATUS_UNSUPPORTED_SETTING                  SRV_CCA_STATUS_UNSUPPORTED_SETTING
#define CCA_STATUS_CORRUPTED_SETTING                    SRV_CCA_STATUS_CORRUPTED_SETTING
#define CCA_STATUS_MISSING_DATA                         SRV_CCA_STATUS_MISSING_DATA
#define CCA_STATUS_SETTING_NOAPP                        SRV_CCA_STATUS_SETTING_NOAPP

#define CCA_STATUS_OUT_OF_RANGE                         SRV_CCA_STATUS_OUT_OF_RANGE
#define CCA_STATUS_CCA_BUSY                             SRV_CCA_STATUS_CCA_BUSY
#define CCA_STATUS_CCA_READY                            SRV_CCA_STATUS_CCA_READY

#define CCA_STATUS_AUTH_FAILED                          SRV_CCA_STATUS_AUTH_FAILED
#define CCA_STATUS_GET_MSG_FAILED                       SRV_CCA_STATUS_GET_MSG_FAILED
#define CCA_STATUS_LAST                                 SRV_CCA_STATUS_MAX_ITEM

typedef srv_cca_session_type_enum                       cca_session_type_enum;

#define MMI_CCA_SESSION_TYPE_DM                         SRV_CCA_SESSION_TYPE_DM
#define MMI_CCA_SESSION_TYPE_LAST                       SRV_CCA_SESSION_TYPE_MAX_ITEM

/*
typedef srv_cca_flag_enum                               cca_flag_enum;

#define CCA_FL_STSCHILD                                 SRV_CCA_FL_STSCHILD
#define CCA_FL_STSPARENT                                SRV_CCA_FL_STSPARENT
#define CCA_FL_LAST                                     SRV_CCA_FL_LAST
*/


typedef srv_cca_traverse_type_enum                      cca_traverse_type_enum;

#define CCA_TR_LIST                                     SRV_CCA_TR_LIST
#define CCA_TR_PREORDER                                 SRV_CCA_TR_PREORDER


typedef srv_cca_iter_type_enum                          cca_iter_type_enum;

#define CCA_IT_NODELIST                                 SRV_CCA_IT_NODELIST
#define CCA_IT_NODECHAIN                                SRV_CCA_IT_NODECHAIN
#define CCA_IT_DATALIST                                 SRV_CCA_IT_DATALIST
#define CCA_IT_DOC                                      SRV_CCA_IT_DOC


typedef srv_cca_data_type_enum                          cca_data_type_enum;

#define CCA_DT_INT                                      SRV_CCA_DATA_TYPE_INT
#define CCA_DT_STR                                      SRV_CCA_DATA_TYPE_STR

/*
typedef srv_cca_memfull_cb_id_enum                      cca_memfull_cb_id_enum;

#define CCA_MFID_WITHIN_APP_CONFIGURE                   SRV_CCA_MFID_WITHIN_APP_CONFIGURE
#define CCA_MFID_SIZE                                   SRV_CCA_MFID_SIZE
*/



/*---- ID--------------------------------------------------------------*/
#define CCA_SPEC_NULL                                   SRV_CCA_SPEC_NULL
#define CCA_SPEC_OMA                                    SRV_CCA_SPEC_OMA
#define CCA_GET_SPEC                                    SRV_CCA_GET_SPEC

#define CCA_CATE_NULL                                   SRV_CCA_CATE_NULL

//#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
#define CCA_CATE_DMP                                    SRV_CCA_CATE_DMP
//#endif 

#define CCA_GET_CATE                                    SRV_CCA_GET_CATE

#define CCA_SOURCE_TEST                                 SRV_CCA_SOURCE_TEST
#define CCA_SOURCE_WAP                                  SRV_CCA_SOURCE_WAP
#define CCA_SOURCE_DM                                   SRV_CCA_SOURCE_DM
#define CCA_SOURCE_SPA                                  SRV_CCA_SOURCE_SPA
#define CCA_SOURCE_PROVBOX                              SRV_CCA_SOURCE_PROVBOX
#define CCA_SOURCE_PROVBOXUI                            SRV_CCA_SOURCE_PROVBOXUI

#define CCA_APP_INVALID                                 SRV_CCA_APP_INVALID
#define CCA_APP_TEST                                    SRV_CCA_APP_TEST
#define CCA_APP_DTACCT                                  SRV_CCA_APP_DTACCT
#define CCA_APP_WLAN                                    SRV_CCA_APP_WLAN
#define CCA_APP_BROWSER                                 SRV_CCA_APP_BROWSER
#define CCA_APP_MMS                                     SRV_CCA_APP_MMS
#define CCA_APP_SIP                                     SRV_CCA_APP_SIP
#define CCA_APP_IMPS                                    SRV_CCA_APP_IMPS
#define CCA_APP_EMAIL                                   SRV_CCA_APP_EMAIL
#define CCA_APP_SYNCMLDS                                SRV_CCA_APP_SYNCMLDS
#define CCA_APP_SYNCMLDM                                SRV_CCA_APP_SYNCMLDM
#define CCA_APP_PUSH                                    SRV_CCA_APP_PUSH
#define CCA_APP_RTSP                                    SRV_CCA_APP_RTSP
#define CCA_APP_SUPL                                    SRV_CCA_APP_SUPL

#define CCA_GET_APP                                     SRV_CCA_GET_APP

#define CCA_CONFIG_INVALID                              SRV_CCA_CONFIG_INVALID
#define CCA_CONFIG_TEST                                 SRV_CCA_CONFIG_TEST
#define CCA_CONFIG_DTACCT                               SRV_CCA_CONFIG_DTACCT
#define CCA_CONFIG_WLAN                                 SRV_CCA_CONFIG_WLAN
#define CCA_CONFIG_BROWSER                              SRV_CCA_CONFIG_BROWSER
#define CCA_CONFIG_MMS                                  SRV_CCA_CONFIG_MMS
#define CCA_CONFIG_SIP                                  SRV_CCA_CONFIG_SIP
#define CCA_CONFIG_IMPS                                 SRV_CCA_CONFIG_IMPS
#define CCA_CONFIG_EMAIL                                SRV_CCA_CONFIG_EMAIL
#define CCA_CONFIG_SYNCMLDS                             SRV_CCA_CONFIG_SYNCMLDS
#define CCA_CONFIG_SYNCMLDM                             SRV_CCA_CONFIG_SYNCMLDM
#define CCA_CONFIG_PUSH                                 SRV_CCA_CONFIG_PUSH
#define CCA_CONFIG_RTSP                                 SRV_CCA_CONFIG_RTSP
#define CCA_CONFIG_SUPL                                 SRV_CCA_CONFIG_SUPL

//#ifdef __MMI_WLAN_OTAP_DMP__    /* DMP Spec -- WLAN */
#define CCA_CONFIG_WLAN_DMP                             SRV_CCA_CONFIG_WLAN_DMP
//#endif 

//#ifdef __MMI_VOIP_OTAP_DMP__    /* DMP Spec -- SIP */
#define CCA_CONFIG_SIP_DMP                              SRV_CCA_CONFIG_SIP_DMP
//#endif 

#define   CCA_NS_TEST                                   SRV_CCA_NS_TEST
#define    CCA_NS_CCA                                   SRV_CCA_NS_CCA
#define   CCA_NS_VAL                                    SRV_CCA_NS_VAL
#define   CCA_NS_OMA                                    SRV_CCA_NS_OMA

//#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
#define  CCA_NS_OMADMP                                  SRV_CCA_NS_OMADMP
//#endif 

#define   CCA_NS__NULL                                  SRV_CCA_NS__NULL
#define   CCA_NS_CLEARNS                                SRV_CCA_NS_CLEARNS

#define   CCA_NS_VAL__SECTION_NULL                      SRV_CCA_NS_VAL__SECTION_NULL
#define   CCA_NS_VAL__SECTION_OMA                       SRV_CCA_NS_VAL__SECTION_OMA

//#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
#define   CCA_NS_VAL__SECTION_OMADMP                    SRV_CCA_NS_VAL__SECTION_OMADMP
//#endif 

/*---- Symbols---------------------------------------------------------*/
typedef srv_cca_symbols_enum cca_symbols_enum;

#define CCA_NS__START                                   SRV_CCA_NS__START

#define CCA_NS_DOCROOT                                  SRV_CCA_NS_DOCROOT
#define CCA_NS_NODEID                                   SRV_CCA_NS_NODEID
#define CCA_NS_DATAACCTID                               SRV_CCA_NS_DATAACCTID
#define CCA_NS_L1NODEID                                 SRV_CCA_NS_L1NODEID
#define CCA_NS_DEPREL                                   SRV_CCA_NS_DEPREL
#define CCA_NS_DEP_PROXY                                SRV_CCA_NS_DEP_PROXY
#define CCA_NS_DEP_APPLICATION                          SRV_CCA_NS_DEP_APPLICATION
#define CCA_NS_DEP_BOOTSTRAP                            SRV_CCA_NS_DEP_BOOTSTRAP
#define CCA_NS_DEP_ACCESS                               SRV_CCA_NS_DEP_ACCESS
#define CCA_NS_DEP_NAPDEF                               SRV_CCA_NS_DEP_NAPDEF
#define CCA_NS_HSRCNODE                                 SRV_CCA_NS_HSRCNODE
#define CCA_NS_REFNAPID                                 SRV_CCA_NS_REFNAPID
#define CCA_NS_REFPXID                                  SRV_CCA_NS_REFPXID
#define CCA_NS_DEP_DATAACCT                             SRV_CCA_NS_DEP_DATAACCT
#define CCA_NS_ISUSED                                   SRV_CCA_NS_ISUSED
#define CCA_NS_TRIGNODE                                 SRV_CCA_NS_TRIGNODE
#define CCA_NS_TRIGPARM                                 SRV_CCA_NS_TRIGPARM
#define CCA_NS_INAPPCONTEXT                             SRV_CCA_NS_INAPPCONTEXT
#define CCA_NS_NODEFLAG                                 SRV_CCA_NS_NODEFLAG

#define CCA_NS__LAST                                    SRV_CCA_NS__LAST

/* CCA Proprietary Value Symbols */
typedef srv_cca_values_enum cca_value_enum;

#define CCA_NS_VAL__START                               SRV_CCA_NS_VAL__START

#define CCA_NS_VAL__EMPTY                               SRV_CCA_NS_VAL__EMPTY
#define CCA_NS_VAL__INVALID                             SRV_CCA_NS_VAL__INVALID

#define CCA_NS_VAL__LAST                                SRV_CCA_NS_VAL__LAST

/* OMA Client Provisioning v1.1 Symbols */
typedef srv_cca_oma_symbols_enum cca_oma_symbols_enum;

#define CCA_NS_OMA__START                               SRV_CCA_NS_OMA__START

#define CCA_NS_OMA_PROXY                                SRV_CCA_NS_OMA_PROXY
#define CCA_NS_OMA_PROXY_ID                             SRV_CCA_NS_OMA_PROXY_ID
#define CCA_NS_OMA_PROXY_PW                             SRV_CCA_NS_OMA_PROXY_PW
#define CCA_NS_OMA_PPGAUTH_TYPE                         SRV_CCA_NS_OMA_PPGAUTH_TYPE
#define CCA_NS_OMA_PROXY_PROVIDER_ID                    SRV_CCA_NS_OMA_PROXY_PROVIDER_ID
#define CCA_NS_OMA_NAME                                 SRV_CCA_NS_OMA_NAME
#define CCA_NS_OMA_DOMAIN                               SRV_CCA_NS_OMA_DOMAIN
#define CCA_NS_OMA_TRUST                                SRV_CCA_NS_OMA_TRUST
#define CCA_NS_OMA_MASTER                               SRV_CCA_NS_OMA_MASTER
#define CCA_NS_OMA_STARTPAGE                            SRV_CCA_NS_OMA_STARTPAGE
#define CCA_NS_OMA_BASAUTH_ID                           SRV_CCA_NS_OMA_BASAUTH_ID
#define CCA_NS_OMA_BASAUTH_PW                           SRV_CCA_NS_OMA_BASAUTH_PW
#define CCA_NS_OMA_WSP_VERSION                          SRV_CCA_NS_OMA_WSP_VERSION
#define CCA_NS_OMA_PUSHENABLED                          SRV_CCA_NS_OMA_PUSHENABLED
#define CCA_NS_OMA_PULLENABLED                          SRV_CCA_NS_OMA_PULLENABLED

#define CCA_NS_OMA_PXAUTHINFO                           SRV_CCA_NS_OMA_PXAUTHINFO
#define CCA_NS_OMA_PXAUTH_TYPE                          SRV_CCA_NS_OMA_PXAUTH_TYPE
#define CCA_NS_OMA_PXAUTH_ID                            SRV_CCA_NS_OMA_PXAUTH_ID
#define CCA_NS_OMA_PXAUTH_PW                            SRV_CCA_NS_OMA_PXAUTH_PW
#define CCA_NS_OMA_PORT                                 SRV_CCA_NS_OMA_PORT
#define CCA_NS_OMA_PORTNBR                              SRV_CCA_NS_OMA_PORTNBR
#define CCA_NS_OMA_SERVICE                              SRV_CCA_NS_OMA_SERVICE
#define CCA_NS_OMA_PHYSICAL_PROXY_ID                    SRV_CCA_NS_OMA_PHYSICAL_PROXY_ID
#define CCA_NS_OMA_PXADDR                               SRV_CCA_NS_OMA_PXADDR
#define CCA_NS_OMA_PXADDRTYPE                           SRV_CCA_NS_OMA_PXADDRTYPE
#define CCA_NS_OMA_PXADDR_FQDN                          SRV_CCA_NS_OMA_PXADDR_FQDN
#define CCA_NS_OMA_TO_NAPID                             SRV_CCA_NS_OMA_TO_NAPID
#define CCA_NS_OMA_NAPDEF                               SRV_CCA_NS_OMA_NAPDEF
#define CCA_NS_OMA_NAPID                                SRV_CCA_NS_OMA_NAPID
#define CCA_NS_OMA_BEARER                               SRV_CCA_NS_OMA_BEARER
#define CCA_NS_OMA_INTERNET                             SRV_CCA_NS_OMA_INTERNET
#define CCA_NS_OMA_NAP_ADDRESS                          SRV_CCA_NS_OMA_NAP_ADDRESS
#define CCA_NS_OMA_NAP_ADDRTYPE                         SRV_CCA_NS_OMA_NAP_ADDRTYPE
#define CCA_NS_OMA_DNS_ADDR                             SRV_CCA_NS_OMA_DNS_ADDR
#define CCA_NS_OMA_CALLTYPE                             SRV_CCA_NS_OMA_CALLTYPE
#define CCA_NS_OMA_LOCAL_ADDR                           SRV_CCA_NS_OMA_LOCAL_ADDR
#define CCA_NS_OMA_LOCAL_ADDRTYPE                       SRV_CCA_NS_OMA_LOCAL_ADDRTYPE
#define CCA_NS_OMA_LINKSPEED                            SRV_CCA_NS_OMA_LINKSPEED
#define CCA_NS_OMA_DNLINKSPEED                          SRV_CCA_NS_OMA_DNLINKSPEED
#define CCA_NS_OMA_LINGER                               SRV_CCA_NS_OMA_LINGER
#define CCA_NS_OMA_DELIVERY_ERR_SDU                     SRV_CCA_NS_OMA_DELIVERY_ERR_SDU
#define CCA_NS_OMA_DELIVERY_ORDER                       SRV_CCA_NS_OMA_DELIVERY_ORDER
#define CCA_NS_OMA_TRAFFIC_CLASS                        SRV_CCA_NS_OMA_TRAFFIC_CLASS
#define CCA_NS_OMA_MAX_SDU_SIZE                         SRV_CCA_NS_OMA_MAX_SDU_SIZE
#define CCA_NS_OMA_MAX_BITRATE_UPLINK                   SRV_CCA_NS_OMA_MAX_BITRATE_UPLINK
#define CCA_NS_OMA_MAX_BITRATE_DNLINK                   SRV_CCA_NS_OMA_MAX_BITRATE_DNLINK
#define CCA_NS_OMA_RESIDUAL_BER                         SRV_CCA_NS_OMA_RESIDUAL_BER
#define CCA_NS_OMA_SDU_ERROR_RATIO                      SRV_CCA_NS_OMA_SDU_ERROR_RATIO
#define CCA_NS_OMA_TRAFFIC_HANDL_PRIO                   SRV_CCA_NS_OMA_TRAFFIC_HANDL_PRIO
#define CCA_NS_OMA_TRANSFER_DELAY                       SRV_CCA_NS_OMA_TRANSFER_DELAY
#define CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK            SRV_CCA_NS_OMA_GUARANTEED_BITRATE_UPLINK
#define CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK            SRV_CCA_NS_OMA_GUARANTEED_BITRATE_DNLINK
#define CCA_NS_OMA_MAX_NUM_RETRY                        SRV_CCA_NS_OMA_MAX_NUM_RETRY
#define CCA_NS_OMA_FIRST_RETRY_TIMEOUT                  SRV_CCA_NS_OMA_FIRST_RETRY_TIMEOUT
#define CCA_NS_OMA_REREG_THRESHOLD                      SRV_CCA_NS_OMA_REREG_THRESHOLD
#define CCA_NS_OMA_T_BIT                                SRV_CCA_NS_OMA_T_BIT
#define CCA_NS_OMA_NAPAUTHINFO                          SRV_CCA_NS_OMA_NAPAUTHINFO
#define CCA_NS_OMA_AUTHTYPE                             SRV_CCA_NS_OMA_AUTHTYPE
#define CCA_NS_OMA_AUTHNAME                             SRV_CCA_NS_OMA_AUTHNAME
#define CCA_NS_OMA_AUTHSECRET                           SRV_CCA_NS_OMA_AUTHSECRET
#define CCA_NS_OMA_AUTH_ENTITY                          SRV_CCA_NS_OMA_AUTH_ENTITY
#define CCA_NS_OMA_SPI                                  SRV_CCA_NS_OMA_SPI
#define CCA_NS_OMA_VALIDITY                             SRV_CCA_NS_OMA_VALIDITY
#define CCA_NS_OMA_COUNTRY                              SRV_CCA_NS_OMA_COUNTRY
#define CCA_NS_OMA_NETWORK                              SRV_CCA_NS_OMA_NETWORK
#define CCA_NS_OMA_SID                                  SRV_CCA_NS_OMA_SID
#define CCA_NS_OMA_SOC                                  SRV_CCA_NS_OMA_SOC
#define CCA_NS_OMA_VALIDUNTIL                           SRV_CCA_NS_OMA_VALIDUNTIL
#define CCA_NS_OMA_BOOTSTRAP                            SRV_CCA_NS_OMA_BOOTSTRAP
#define CCA_NS_OMA_PROVURL                              SRV_CCA_NS_OMA_PROVURL
#define CCA_NS_OMA_CONTEXT_ALLOW                        SRV_CCA_NS_OMA_CONTEXT_ALLOW
#define CCA_NS_OMA_CLIENTIDENTITY                       SRV_CCA_NS_OMA_CLIENTIDENTITY
#define CCA_NS_OMA_CLIENT_ID                            SRV_CCA_NS_OMA_CLIENT_ID
#define CCA_NS_OMA_VENDORCONFIG                         SRV_CCA_NS_OMA_VENDORCONFIG
#define CCA_NS_OMA_APPLICATION                          SRV_CCA_NS_OMA_APPLICATION
#define CCA_NS_OMA_APPID                                SRV_CCA_NS_OMA_APPID
#define CCA_NS_OMA_PROVIDER_ID                          SRV_CCA_NS_OMA_PROVIDER_ID
#define CCA_NS_OMA_AACCEPT                              SRV_CCA_NS_OMA_AACCEPT
#define CCA_NS_OMA_APROTOCOL                            SRV_CCA_NS_OMA_APROTOCOL
#define CCA_NS_OMA_TO_PROXY                             SRV_CCA_NS_OMA_TO_PROXY
#define CCA_NS_OMA_ADDR                                 SRV_CCA_NS_OMA_ADDR
#define CCA_NS_OMA_CM                                   SRV_CCA_NS_OMA_CM
#define CCA_NS_OMA_RM                                   SRV_CCA_NS_OMA_RM
#define CCA_NS_OMA_MS                                   SRV_CCA_NS_OMA_MS
#define CCA_NS_OMA_PC_ADDR                              SRV_CCA_NS_OMA_PC_ADDR
#define CCA_NS_OMA_MA                                   SRV_CCA_NS_OMA_MA
#define CCA_NS_OMA_APPADDR                              SRV_CCA_NS_OMA_APPADDR
#define CCA_NS_OMA_ADDRTYPE                             SRV_CCA_NS_OMA_ADDRTYPE
#define CCA_NS_OMA_APPAUTH                              SRV_CCA_NS_OMA_APPAUTH
#define CCA_NS_OMA_AAUTHLEVEL                           SRV_CCA_NS_OMA_AAUTHLEVEL
#define CCA_NS_OMA_AAUTHTYPE                            SRV_CCA_NS_OMA_AAUTHTYPE
#define CCA_NS_OMA_AAUTHNAME                            SRV_CCA_NS_OMA_AAUTHNAME
#define CCA_NS_OMA_AAUTHSECRET                          SRV_CCA_NS_OMA_AAUTHSECRET
#define CCA_NS_OMA_AAUTHDATA                            SRV_CCA_NS_OMA_AAUTHDATA
#define CCA_NS_OMA_RESOURCE                             SRV_CCA_NS_OMA_RESOURCE
#define CCA_NS_OMA_URI                                  SRV_CCA_NS_OMA_URI
#define CCA_NS_OMA_ACCESS                               SRV_CCA_NS_OMA_ACCESS
#define CCA_NS_OMA_RULE                                 SRV_CCA_NS_OMA_RULE
#define CCA_NS_OMA_LOGINTYPE                            SRV_CCA_NS_OMA_LOGINTYPE     /* Conversion from Nokia OTA Spec */
#define CCA_NS_OMA_FROM                                 SRV_CCA_NS_OMA_FROM  /* SMTP */
#define CCA_NS_OMA_RT_ADDR                              SRV_CCA_NS_OMA_RT_ADDR       /* SMTP */
#define CCA_NS_OMA_SERVICES                             SRV_CCA_NS_OMA_SERVICES       /* IMPS */
#define CCA_NS_OMA_CIDPREFIX                            SRV_CCA_NS_OMA_CIDPREFIX      /* IMPS */
#define CCA_NS_OMA_CLIURI                               SRV_CCA_NS_OMA_CLIURI /* SyncML-DS */
#define CCA_NS_OMA_SYNCTYPE                             SRV_CCA_NS_OMA_SYNCTYPE       /* SyncML-DS */
#define CCA_NS_OMA_INIT                                 SRV_CCA_NS_OMA_INIT   /* SyncML-DM */

/* OMA Extension */
/* OMA Client Provisioning Extension WLAN Symbols */
#define CCA_NS_OMA_WLAN                                 SRV_CCA_NS_OMA_WLAN
#define CCA_NS_OMA_PRI_SSID                             SRV_CCA_NS_OMA_PRI_SSID
#define CCA_NS_OMA_PRI_U_SSID                           SRV_CCA_NS_OMA_PRI_U_SSID
#define CCA_NS_OMA_PRI_H_SSID                           SRV_CCA_NS_OMA_PRI_H_SSID
#define CCA_NS_OMA_SEC_SSID                             SRV_CCA_NS_OMA_SEC_SSID
#define CCA_NS_OMA_S_SSID                               SRV_CCA_NS_OMA_S_SSID
#define CCA_NS_OMA_S_U_SSID                             SRV_CCA_NS_OMA_S_U_SSID
#define CCA_NS_OMA_NETMODE                              SRV_CCA_NS_OMA_NETMODE
#define CCA_NS_OMA_SECMODE                              SRV_CCA_NS_OMA_SECMODE
#define CCA_NS_OMA_EAP                                  SRV_CCA_NS_OMA_EAP
#define CCA_NS_OMA_EAPTYPE                              SRV_CCA_NS_OMA_EAPTYPE
#define CCA_NS_OMA_USERNAME                             SRV_CCA_NS_OMA_USERNAME
#define CCA_NS_OMA_PASSWORD                             SRV_CCA_NS_OMA_PASSWORD
#define CCA_NS_OMA_REALM                                SRV_CCA_NS_OMA_REALM
#define CCA_NS_OMA_USE_PSEUD                            SRV_CCA_NS_OMA_USE_PSEUD
#define CCA_NS_OMA_MAXAUTHS                             SRV_CCA_NS_OMA_MAXAUTHS
#define CCA_NS_OMA_ENCAPS                               SRV_CCA_NS_OMA_ENCAPS
#define CCA_NS_OMA_VER_SER_REALM                        SRV_CCA_NS_OMA_VER_SER_REALM
#define CCA_NS_OMA_CLIENT_AUTH                          SRV_CCA_NS_OMA_CLIENT_AUTH
#define CCA_NS_OMA_SES_VAL_TIME                         SRV_CCA_NS_OMA_SES_VAL_TIME
#define CCA_NS_OMA_CIP_SUIT                             SRV_CCA_NS_OMA_CIP_SUIT
#define CCA_NS_OMA_PEAP_V0                              SRV_CCA_NS_OMA_PEAP_V0
#define CCA_NS_OMA_PEAP_V1                              SRV_CCA_NS_OMA_PEAP_V1
#define CCA_NS_OMA_PEAP_V2                              SRV_CCA_NS_OMA_PEAP_V2
#define CCA_NS_OMA_CERT                                 SRV_CCA_NS_OMA_CERT
#define CCA_NS_OMA_ISS_NAME                             SRV_CCA_NS_OMA_ISS_NAME
#define CCA_NS_OMA_SUB_NAME                             SRV_CCA_NS_OMA_SUB_NAME
#define CCA_NS_OMA_CERT_TYPE                            SRV_CCA_NS_OMA_CERT_TYPE
#define CCA_NS_OMA_SER_NUM                              SRV_CCA_NS_OMA_SER_NUM
#define CCA_NS_OMA_SUB_KEY_ID                           SRV_CCA_NS_OMA_SUB_KEY_ID
#define CCA_NS_OMA_THUMBPRINT                           SRV_CCA_NS_OMA_THUMBPRINT
#define CCA_NS_OMA_WPA_PRES_KEY_ASC                     SRV_CCA_NS_OMA_WPA_PRES_KEY_ASC
#define CCA_NS_OMA_WPA_PRES_KEY_HEX                     SRV_CCA_NS_OMA_WPA_PRES_KEY_HEX
#define CCA_NS_OMA_WEPKEYIND                            SRV_CCA_NS_OMA_WEPKEYIND
#define CCA_NS_OMA_WEPAUTHMODE                          SRV_CCA_NS_OMA_WEPAUTHMODE
#define CCA_NS_OMA_WEPKEY                               SRV_CCA_NS_OMA_WEPKEY
#define CCA_NS_OMA_LENGTH                               SRV_CCA_NS_OMA_LENGTH
#define CCA_NS_OMA_INDEX                                SRV_CCA_NS_OMA_INDEX
#define CCA_NS_OMA_DATA                                 SRV_CCA_NS_OMA_DATA
#define CCA_NS_OMA_WLANHAND                             SRV_CCA_NS_OMA_WLANHAND
#define CCA_NS_OMA_EDIT_SET                             SRV_CCA_NS_OMA_EDIT_SET
#define CCA_NS_OMA_VIEW_SET                             SRV_CCA_NS_OMA_VIEW_SET
#define CCA_NS_OMA_FORW_SET                             SRV_CCA_NS_OMA_FORW_SET

/* SIM MMS profile: EFmmicp */
#define CCA_NS_OMA_IMPL                                 SRV_CCA_NS_OMA_IMPL

/* RTSP application-specific parameters */
#define CCA_NS_OMA_MAX_BANDWIDTH                        SRV_CCA_NS_OMA_MAX_BANDWIDTH
#define CCA_NS_OMA_NETINFO                              SRV_CCA_NS_OMA_NETINFO
#define CCA_NS_OMA_MIN_UDP_PORT                         SRV_CCA_NS_OMA_MIN_UDP_PORT
#define CCA_NS_OMA_MAX_UDP_PORT                         SRV_CCA_NS_OMA_MAX_UDP_PORT

#define CCA_NS_OMA__LAST                                SRV_CCA_NS_OMA__LAST

//#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
                      /* DMP Spec *//* DMP Spec */
                                                                   /* OMA Client Provisioning Extension Proprietary Symbols *//* OMA Client Provisioning Extension Proprietary Symbols */
typedef srv_cca_omadmp_symbols_enum cca_omadmp_symbols_enum;

#define CCA_NS_OMADMP__START                            SRV_CCA_NS_OMADMP__START

/* SIP */
#define CCA_NS_OMADMP_PX_SIP                            SRV_CCA_NS_OMADMP_PX_SIP
#define CCA_NS_OMADMP_NAME                              SRV_CCA_NS_OMADMP_NAME
#define CCA_NS_OMADMP_USER_NAME                         SRV_CCA_NS_OMADMP_USER_NAME
#define CCA_NS_OMADMP_AUTH_NAME                         SRV_CCA_NS_OMADMP_AUTH_NAME
#define CCA_NS_OMADMP_AUTH_PASSWD                       SRV_CCA_NS_OMADMP_AUTH_PASSWD
#define CCA_NS_OMADMP_DOMAIN                            SRV_CCA_NS_OMADMP_DOMAIN
#define CCA_NS_OMADMP_LOCAL_PORT                        SRV_CCA_NS_OMADMP_LOCAL_PORT
#define CCA_NS_OMADMP_PREFER_CODEC                      SRV_CCA_NS_OMADMP_PREFER_CODEC
#define CCA_NS_OMADMP_PXSRV_ADDR                        SRV_CCA_NS_OMADMP_PXSRV_ADDR
#define CCA_NS_OMADMP_PXSRV_ADDRTYPE                    SRV_CCA_NS_OMADMP_PXSRV_ADDRTYPE
#define CCA_NS_OMADMP_PXSRV_PORT                        SRV_CCA_NS_OMADMP_PXSRV_PORT
#define CCA_NS_OMADMP_REGSRV_ADDR                       SRV_CCA_NS_OMADMP_REGSRV_ADDR
#define CCA_NS_OMADMP_REGSRV_ADDRTYPE                   SRV_CCA_NS_OMADMP_REGSRV_ADDRTYPE
#define CCA_NS_OMADMP_REGSRV_PORT                       SRV_CCA_NS_OMADMP_REGSRV_PORT
#define CCA_NS_OMADMP_REGSRV_REGPERIOD                  SRV_CCA_NS_OMADMP_REGSRV_REGPERIOD
#define CCA_NS_OMADMP_OUTPXSRV_ADDR                     SRV_CCA_NS_OMADMP_OUTPXSRV_ADDR
#define CCA_NS_OMADMP_OUTPXSRV_ADDRTYPE                 SRV_CCA_NS_OMADMP_OUTPXSRV_ADDRTYPE
#define CCA_NS_OMADMP_OUTPXSRV_PORT                     SRV_CCA_NS_OMADMP_OUTPXSRV_PORT
#define CCA_NS_OMADMP_RTP_AUDIO_PORT                    SRV_CCA_NS_OMADMP_RTP_AUDIO_PORT
#define CCA_NS_OMADMP_RTP_PACKET_PERIOD                 SRV_CCA_NS_OMADMP_RTP_PACKET_PERIOD
#define CCA_NS_OMADMP_NAT_RPORT_ENABLED                 SRV_CCA_NS_OMADMP_NAT_RPORT_ENABLED
#define CCA_NS_OMADMP_NAT_STUN_ENABLED                  SRV_CCA_NS_OMADMP_NAT_STUN_ENABLED
#define CCA_NS_OMADMP_NAT_STUNSRV_ADDR                  SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDR
#define CCA_NS_OMADMP_NAT_STUNSRV_ADDRTYPE              SRV_CCA_NS_OMADMP_NAT_STUNSRV_ADDRTYPE
#define CCA_NS_OMADMP_NAT_STUNSRV_PORT                  SRV_CCA_NS_OMADMP_NAT_STUNSRV_PORT
#define CCA_NS_OMADMP_NAT_STUNSRV_REFRESH_PERIOD        SRV_CCA_NS_OMADMP_NAT_STUNSRV_REFRESH_PERIOD

/* WIFI */
#define CCA_NS_OMADMP_WIFI                              SRV_CCA_NS_OMADMP_WIFI
#define CCA_NS_OMADMP_ACCESS_POINT                      SRV_CCA_NS_OMADMP_ACCESS_POINT
#define CCA_NS_OMADMP_PROFILE                           SRV_CCA_NS_OMADMP_PROFILE
#define CCA_NS_OMADMP_SSID                              SRV_CCA_NS_OMADMP_SSID
#define CCA_NS_OMADMP_ADHOC                             SRV_CCA_NS_OMADMP_ADHOC
#define CCA_NS_OMADMP_AUTHENTICATION                    SRV_CCA_NS_OMADMP_AUTHENTICATION
#define CCA_NS_OMADMP_ENCRYPTION                        SRV_CCA_NS_OMADMP_ENCRYPTION
#define CCA_NS_OMADMP_KEYPROVIDED                       SRV_CCA_NS_OMADMP_KEYPROVIDED
#define CCA_NS_OMADMP_NETWORKKEY                        SRV_CCA_NS_OMADMP_NETWORKKEY
#define CCA_NS_OMADMP_KEYINDEX                          SRV_CCA_NS_OMADMP_KEYINDEX
#define CCA_NS_OMADMP_USE8021X                          SRV_CCA_NS_OMADMP_USE8021X
#define CCA_NS_OMADMP_EAPTYPE                           SRV_CCA_NS_OMADMP_EAPTYPE
#define CCA_NS_OMADMP_AD_HOC                            SRV_CCA_NS_OMADMP_AD_HOC

#define CCA_NS_OMADMP__LAST                             SRV_CCA_NS_OMADMP__LAST
//#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */ 

typedef srv_cca_oma_values_enum cca_oma_values_enum;

#define CCA_NS_VAL__OMA_START                           SRV_CCA_NS_VAL__OMA_START

/* PROXY: PPGAUTH-TYPE */
/* PROXY/PXAUTHINFO: PXAUTH-TYPE */
/* APPLICATION/APPAUTH: AAUTHTYPE(official) */
/* APPLICATION/RESOURCE: AAUTHTYPE */
#define CCA_NS_VAL_HTTP_BASIC                           SRV_CCA_NS_VAL_HTTP_BASIC
#define CCA_NS_VAL_HTTP_DIGEST                          SRV_CCA_NS_VAL_HTTP_DIGEST
#define CCA_NS_VAL_WTLS_SS                              SRV_CCA_NS_VAL_WTLS_SS
#define CCA_NS_VAL_BASIC                                SRV_CCA_NS_VAL_BASIC
#define CCA_NS_VAL_DIGEST                               SRV_CCA_NS_VAL_DIGEST

/* APPLICATION/APPAUTH: AAUTHTYPE */
#define CCA_NS_VAL_CRAM_MD5                             SRV_CCA_NS_VAL_CRAM_MD5
#define CCA_NS_VAL_DIGEST_MD5                           SRV_CCA_NS_VAL_DIGEST_MD5
#define CCA_NS_VAL_LOGIN                                SRV_CCA_NS_VAL_LOGIN
#define CCA_NS_VAL_PLAIN                                SRV_CCA_NS_VAL_PLAIN
#define CCA_NS_VAL_APOP                                 SRV_CCA_NS_VAL_APOP
#define CCA_NS_VAL_GSSAPI                               SRV_CCA_NS_VAL_GSSAPI
#define CCA_NS_VAL_KERBEROS_V4                          SRV_CCA_NS_VAL_KERBEROS_V4
#define CCA_NS_VAL_SKEY                                 SRV_CCA_NS_VAL_SKEY
#define CCA_NS_VAL_CLIENT                               SRV_CCA_NS_VAL_CLIENT
#define CCA_NS_VAL_X509                                 SRV_CCA_NS_VAL_X509
#define CCA_NS_VAL_SECURID                              SRV_CCA_NS_VAL_SECURID
#define CCA_NS_VAL_SAFEWORD                             SRV_CCA_NS_VAL_SAFEWORD
#define CCA_NS_VAL_DIGIPASS                             SRV_CCA_NS_VAL_DIGIPASS
#define CCA_NS_VAL_HMAC                                 SRV_CCA_NS_VAL_HMAC

/* PROXY: PXADDRTYPE */
/* NAPDEF: NAP-ADDRTYPE */
/* NAPDEF: LOCAL-ADDRTYPE */
/* APPLICATION/APPADDR: ADDRTYPE */
#define CCA_NS_VAL_IPV4                                 SRV_CCA_NS_VAL_IPV4
#define CCA_NS_VAL_IPV6                                 SRV_CCA_NS_VAL_IPV6
#define CCA_NS_VAL_E164                                 SRV_CCA_NS_VAL_E164
#define CCA_NS_VAL_ALPHA                                SRV_CCA_NS_VAL_ALPHA
#define CCA_NS_VAL_APN                                  SRV_CCA_NS_VAL_APN
#define CCA_NS_VAL_SCODE                                SRV_CCA_NS_VAL_SCODE
#define CCA_NS_VAL_TETRA_ITSI                           SRV_CCA_NS_VAL_TETRA_ITSI
#define CCA_NS_VAL_MAN                                  SRV_CCA_NS_VAL_MAN
#define CCA_NS_VAL_FQDN                                 SRV_CCA_NS_VAL_FQDN        /* only SUPL used now */

/* PROXY: PUSHENABLED/PULLENABLED */
#define CCA_NS_VAL_ENABLED                              SRV_CCA_NS_VAL_ENABLED
#define CCA_NS_VAL_DISABLED                             SRV_CCA_NS_VAL_DISABLED

/* PROXY/PORT: SERVICE */
#define CCA_NS_VAL_CL_WSP                               SRV_CCA_NS_VAL_CL_WSP
#define CCA_NS_VAL_CO_WSP                               SRV_CCA_NS_VAL_CO_WSP
#define CCA_NS_VAL_CL_SEC_WSP                           SRV_CCA_NS_VAL_CL_SEC_WSP
#define CCA_NS_VAL_CO_SEC_WSP                           SRV_CCA_NS_VAL_CO_SEC_WSP
#define CCA_NS_VAL_CO_SEC_WTA                           SRV_CCA_NS_VAL_CO_SEC_WTA
#define CCA_NS_VAL_CL_SEC_WTA                           SRV_CCA_NS_VAL_CL_SEC_WTA
#define CCA_NS_VAL_OTA_HTTP_TO                          SRV_CCA_NS_VAL_OTA_HTTP_TO
#define CCA_NS_VAL_OTA_HTTP_TLS_TO                      SRV_CCA_NS_VAL_OTA_HTTP_TLS_TO
#define CCA_NS_VAL_OTA_HTTP_PO                          SRV_CCA_NS_VAL_OTA_HTTP_PO
#define CCA_NS_VAL_OTA_HTTP_TLS_PO                      SRV_CCA_NS_VAL_OTA_HTTP_TLS_PO
#define CCA_NS_VAL_STARTTLS                             SRV_CCA_NS_VAL_STARTTLS

/* NAPDEF: BEARER */
#define CCA_NS_VAL_GSM_CSD                              SRV_CCA_NS_VAL_GSM_CSD
#define CCA_NS_VAL_GSM_GPRS                             SRV_CCA_NS_VAL_GSM_GPRS
#define CCA_NS_VAL_GSM_USSD                             SRV_CCA_NS_VAL_GSM_USSD
#define CCA_NS_VAL_GSM_SMS                              SRV_CCA_NS_VAL_GSM_SMS
#define CCA_NS_VAL_CDMA_SMS                             SRV_CCA_NS_VAL_CDMA_SMS
#define CCA_NS_VAL_CDMA_CSD                             SRV_CCA_NS_VAL_CDMA_CSD
#define CCA_NS_VAL_CDMA_PACKET                          SRV_CCA_NS_VAL_CDMA_PACKET
#define CCA_NS_VAL_ANSI_136_GUTS                        SRV_CCA_NS_VAL_ANSI_136_GUTS
#define CCA_NS_VAL_ANSI_136_CSD                         SRV_CCA_NS_VAL_ANSI_136_CSD
#define CCA_NS_VAL_ANSI_136_GPRS                        SRV_CCA_NS_VAL_ANSI_136_GPRS
#define CCA_NS_VAL_ANSI_136_GHOST                       SRV_CCA_NS_VAL_ANSI_136_GHOST
#define CCA_NS_VAL_AMPS_CDPD                            SRV_CCA_NS_VAL_AMPS_CDPD
#define CCA_NS_VAL_PDC_CSD                              SRV_CCA_NS_VAL_PDC_CSD
#define CCA_NS_VAL_PDC_PACKET                           SRV_CCA_NS_VAL_PDC_PACKET
#define CCA_NS_VAL_IDEN_SMS                             SRV_CCA_NS_VAL_IDEN_SMS
#define CCA_NS_VAL_IDEN_CSD                             SRV_CCA_NS_VAL_IDEN_CSD
#define CCA_NS_VAL_IDEN_PACKET                          SRV_CCA_NS_VAL_IDEN_PACKET
#define CCA_NS_VAL_FLEX_REFLEX                          SRV_CCA_NS_VAL_FLEX_REFLEX
#define CCA_NS_VAL_PHS_SMS                              SRV_CCA_NS_VAL_PHS_SMS
#define CCA_NS_VAL_PHS_CSD                              SRV_CCA_NS_VAL_PHS_CSD
#define CCA_NS_VAL_TETRA_SDS                            SRV_CCA_NS_VAL_TETRA_SDS
#define CCA_NS_VAL_TETRA_PACKET                         SRV_CCA_NS_VAL_TETRA_PACKET
#define CCA_NS_VAL_MOBITEX_MPAK                         SRV_CCA_NS_VAL_MOBITEX_MPAK
#define CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP                SRV_CCA_NS_VAL_CDMA2000_1X_SIMPLE_IP
#define CCA_NS_VAL_CDMA2000_1X_MOBILE_IP                SRV_CCA_NS_VAL_CDMA2000_1X_MOBILE_IP
#define CCA_NS_VAL_WLAN                                 SRV_CCA_NS_VAL_WLAN      /* OMA Extension */

/* NAPDEF: CALLTYPE */
#define CCA_NS_VAL_ANALOG_MODEM                         SRV_CCA_NS_VAL_ANALOG_MODEM
#define CCA_NS_VAL_V120                                 SRV_CCA_NS_VAL_V120
#define CCA_NS_VAL_V110                                 SRV_CCA_NS_VAL_V110
#define CCA_NS_VAL_X31                                  SRV_CCA_NS_VAL_X31
#define CCA_NS_VAL_BIT_TRANSPARENT                      SRV_CCA_NS_VAL_BIT_TRANSPARENT
#define CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE            SRV_CCA_NS_VAL_DIRECT_ASYNC_DATA_SERVICE

/* NAPDEF: LINKSPEED */
/* NAPDEF: DNLINKSPEED */
#define CCA_NS_VAL_AUTOBAUDING                          SRV_CCA_NS_VAL_AUTOBAUDING

/* NAPDEF/NAPAUTHINFO: AUTHTYPE */
#define CCA_NS_VAL_PAP                                  SRV_CCA_NS_VAL_PAP
#define CCA_NS_VAL_CHAP                                 SRV_CCA_NS_VAL_CHAP
#define CCA_NS_VAL_MD5                                  SRV_CCA_NS_VAL_MD5

/* NAPDEF/NAPAUTHINFO: AUTH-ENTITY */
#define CCA_NS_VAL_AAA                                  SRV_CCA_NS_VAL_AAA
#define CCA_NS_VAL_HA                                   SRV_CCA_NS_VAL_HA

/* APPLICATION */
#define CCA_NS_VAL_RESTRICTED                           SRV_CCA_NS_VAL_RESTRICTED
#define CCA_NS_VAL_WARNING                              SRV_CCA_NS_VAL_WARNING
#define CCA_NS_VAL_FREE                                 SRV_CCA_NS_VAL_FREE
#define CCA_NS_VAL_ENABLE                               SRV_CCA_NS_VAL_ENABLE
#define CCA_NS_VAL_DISABLE                              SRV_CCA_NS_VAL_DISABLE
#define CCA_NS_VAL_LOCKED                               SRV_CCA_NS_VAL_LOCKED

/* APPLICATION/APPAUTH: AAUTHLEVEL */
#define CCA_NS_VAL_APPSRV                               SRV_CCA_NS_VAL_APPSRV
#define CCA_NS_VAL_OBEX                                 SRV_CCA_NS_VAL_OBEX

/* Conversion from Nokia OTA Spec */
/* PROXY: LOGINTYPE */
/* NAPDEF: LOGINTYPE */
#define CCA_NS_VAL_AUTOMATIC                            SRV_CCA_NS_VAL_AUTOMATIC
#define CCA_NS_VAL_MANUAL                               SRV_CCA_NS_VAL_MANUAL

/* OMA Extension */
/* WLAN: NETMODE */
#define CCA_NS_VAL_INFRA                                SRV_CCA_NS_VAL_INFRA
#define CCA_NS_VAL_ADHOC                                SRV_CCA_NS_VAL_ADHOC

/* WLAN: SECMODE */
#define CCA_NS_VAL_WEP                                  SRV_CCA_NS_VAL_WEP
#define CCA_NS_VAL_8021X                                SRV_CCA_NS_VAL_8021X
#define CCA_NS_VAL_WPA                                  SRV_CCA_NS_VAL_WPA
#define CCA_NS_VAL_WPA_PRESHARED_KEY                    SRV_CCA_NS_VAL_WPA_PRESHARED_KEY
#define CCA_NS_VAL_WPA2                                 SRV_CCA_NS_VAL_WPA2
#define CCA_NS_VAL_WPA2_PRESHARED_KEY                   SRV_CCA_NS_VAL_WPA2_PRESHARED_KEY

/* WLAN: WEPAUTHMODE */
#define CCA_NS_VAL_OPEN                                 SRV_CCA_NS_VAL_OPEN
#define CCA_NS_VAL_SHARED                               SRV_CCA_NS_VAL_SHARED

/* WLAN: EAP-TYPE */
#define CCA_NS_VAL_EAP_SIM                              SRV_CCA_NS_VAL_EAP_SIM
#define CCA_NS_VAL_EAP_AKA                              SRV_CCA_NS_VAL_EAP_AKA
#define CCA_NS_VAL_EAP_TLS                              SRV_CCA_NS_VAL_EAP_TLS
#define CCA_NS_VAL_EAP_PEAP                             SRV_CCA_NS_VAL_EAP_PEAP
#define CCA_NS_VAL_EAP_TTLS                             SRV_CCA_NS_VAL_EAP_TTLS
#define CCA_NS_VAL_EAP_LEAP                             SRV_CCA_NS_VAL_EAP_LEAP
#define CCA_NS_VAL_EAP_MSCHAPV2                         SRV_CCA_NS_VAL_EAP_MSCHAPV2
#define CCA_NS_VAL_EAP_GTC                              SRV_CCA_NS_VAL_EAP_GTC

/* WLAN: CERT-TYPE */
#define CCA_NS_VAL_USER                                 SRV_CCA_NS_VAL_USER
#define CCA_NS_VAL_CA                                   SRV_CCA_NS_VAL_CA

/* SIM MMS Profile : EFmmicp */
#define CCA_NS_VAL_IMPL_WAP                             SRV_CCA_NS_VAL_IMPL_WAP
#define CCA_NS_VAL_IMPL_UNKNOWN                         SRV_CCA_NS_VAL_IMPL_UNKNOWN
#define CCA_NS_VAL__OMA_LAST                            SRV_CCA_NS_VAL__OMA_LAST

//#if defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__)
                      /* DMP Spec *//* DMP Spec */
typedef srv_cca_omadmp_values_enum cca_omadmp_values_enum;

#define CCA_NS_VAL__OMADMP_START                        SRV_CCA_NS_VAL__OMADMP_START

    /* SIP: PREFER-CODEC */
#define CCA_NS_VAL_G711A                                SRV_CCA_NS_VAL_G711A
#define CCA_NS_VAL_G711U                                SRV_CCA_NS_VAL_G711U
#define CCA_NS_VAL_G726_16                              SRV_CCA_NS_VAL_G726_16
#define CCA_NS_VAL_G726_24                              SRV_CCA_NS_VAL_G726_24
#define CCA_NS_VAL_G726_32                              SRV_CCA_NS_VAL_G726_32
#define CCA_NS_VAL_G726_40                              SRV_CCA_NS_VAL_G726_40

#define CCA_NS_VAL__OMADMP_LAST                         SRV_CCA_NS_VAL__OMADMP_LAST

//#endif /* defined(__MMI_VOIP_OTAP_DMP__) || defined(__MMI_WLAN_OTAP_DMP__) */ 

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef SRV_CCA_FP_PARAM_PROC                       CCA_FP_PARAM_PROC;
typedef SRV_CCA_FP_NODE_PROC                        CCA_FP_NODE_PROC;
typedef SRV_CCA_FP_APP_CHECK                        CCA_FP_APP_CHECK;

//typedef SRV_CCA_FP_MEMFULL_CB                           CCA_FP_MEMFULL_CB;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef srv_cca_app_config_result_struct                mmi_cca_app_config_result_struct;
typedef srv_cca_app_configure_ind_struct                mmi_cca_app_configure_ind_struct;
typedef srv_cca_app_configure_rsp_struct                mmi_cca_app_configure_rsp_struct;

typedef srv_cca_src_new_doc_ind_struct                  mmi_cca_source_new_doc_ind_struct;
typedef srv_cca_src_new_doc_rsp_struct                  mmi_cca_source_new_doc_rsp_struct;

typedef srv_cca_src_invalid_setting_ind_struct          mmi_cca_source_ui_invalid_setting_ind_struct;
typedef srv_cca_src_new_setting_ind_struct              mmi_cca_source_ui_new_setting_ind_struct;
typedef srv_cca_src_new_setting_rsp_struct              mmi_cca_source_ui_new_setting_rsp_struct;

typedef srv_cca_src_auth_ind_struct                     mmi_cca_source_ui_auth_ind_struct;
typedef srv_cca_src_auth_rsp_struct                     mmi_cca_source_ui_auth_rsp_struct;

typedef srv_cca_src_sim_profile_status_ind_struct       mmi_cca_source_sim_profile_status_ind_struct;
typedef srv_cca_app_sim_profile_status_ind_struct       mmi_cca_app_sim_profile_status_ind_struct;

typedef srv_cca_ready_ind_struct                mmi_cca_source_cca_ready_ind_struct;

typedef srv_cca_process_prov_msg_req_struct             mmi_cca_process_prov_msg_req_struct;
typedef srv_cca_process_prov_msg_cnf_struct             mmi_cca_process_prov_msg_cnf_struct;

typedef srv_cca_src_install_prov_msg_req_struct         mmi_cca_source_install_prov_msg_req_struct;
typedef srv_cca_src_install_prov_msg_cnf_struct         mmi_cca_source_install_prov_msg_cnf_struct;

typedef srv_cca_get_prof_ind_struct                     mmi_cca_get_prof_ind_struct;
typedef srv_cca_get_prof_rsp_struct                     mmi_cca_get_prof_rsp_struct;
typedef srv_cca_app_get_prof_ind_struct                 mmi_cca_app_get_prof_ind_struct;
typedef srv_cca_app_get_prof_rsp_struct                 mmi_cca_app_get_prof_rsp_struct;
typedef srv_cca_update_prof_ind_struct                  mmi_cca_update_prof_ind_struct;
typedef srv_cca_update_prof_rsp_struct                  mmi_cca_update_prof_rsp_struct;
typedef srv_cca_app_update_prof_ind_struct              mmi_cca_app_update_prof_ind_struct;
typedef srv_cca_app_update_prof_rsp_struct              mmi_cca_app_update_prof_rsp_struct;

typedef srv_cca_session_begin_ind_struct                mmi_cca_session_begin_ind_struct;
typedef srv_cca_session_begin_rsp_struct                mmi_cca_session_begin_rsp_struct;
typedef srv_cca_session_end_ind_struct                  mmi_cca_session_end_ind_struct;
typedef srv_cca_session_end_rsp_struct                  mmi_cca_session_end_rsp_struct;

/*----CCA document structure--------------------------------------------------*/
//typedef SRV_CCA_HANDLE                                  cca_core_data_struct*
typedef srv_cca_core_data_struct                        cca_core_data_struct;
typedef srv_cca_generic_ptr_struct                      cca_generic_ptr_struct;
typedef srv_cca_iterator_struct                         cca_iterator_struct;
//typedef srv_cca_app_config_struct                       cca_app_config_struct;

/*----------------------------------------------------------------------------*/
/* API declarations                                                           */
/*----------------------------------------------------------------------------*/

/* Node */
#define mmi_cca_doc_new_node                            srv_cca_doc_node_new
#define mmi_cca_doc_new_rootnode()                      srv_cca_doc_node_new(SRV_CCA_NS_DOCROOT)
#define mmi_cca_doc_node_release_all                    srv_cca_doc_node_free
#define mmi_cca_docroot_release                         srv_cca_doc_node_free

#define mmi_cca_doc_attach_node_to_parent               srv_cca_doc_node_attach
#define mmi_cca_doc_node_detach                         srv_cca_doc_node_detach

#define mmi_cca_doc_new_node_and_attach                 srv_cca_doc_node_new_and_attach
#define mmi_doc_duplicate_node                          srv_cca_doc_node_duplicate
#define mmi_cca_doc_add_node_to_parent                  srv_cca_doc_add_node_to_parent             \


#define mmi_cca_doc_add_nodedata_int                    srv_cca_doc_nodedata_add_int
#define mmi_cca_doc_add_nodedata_str                    srv_cca_doc_nodedata_add_str


#define mmi_cca_oma_make_new_node_id                    srv_cca_oma_make_new_node_id
//#define mmi_cca_oma_make_virtual_proxy_id               srv_cca_oma_make_virtual_proxy_id
#define mmi_cca_oma_free_id                             srv_cca_oma_free_id

//#define mmi_cca_oma_generate_virtual_application_node   srv_cca_oma_generate_virtual_application_node

#define mmi_cca_oma_generate_virtual_proxy_node         srv_cca_oma_generate_virtual_proxy_node

//#define mmi_cca_oma_is_virtual_application              srv_cca_oma_is_virtual_application
#define mmi_cca_oma_is_virtual_proxy(h_proxy)           ((U8)srv_cca_oma_is_virtual_proxy(h_proxy))


#define mmi_cca_doc_new                                 srv_cca_doc_new
#define mmi_cca_doc_release                             srv_cca_doc_destroy
#define mmi_cca_doc_process                             srv_cca_doc_process

#define mmi_cca_oma_fix_doc                             srv_cca_oma_fix_doc
#define mmi_cca_oma_generate_deprel_node                srv_cca_oma_generate_deprel_node
#define mmi_cca_oma_sort_new_doc                        srv_cca_oma_sort_new_doc


#define mmi_cca_doc_nodedata_next                       srv_cca_doc_nodedata_next//.





//#define mmi_cca_doc_add_nodedata_strs                   srv_cca_doc_add_nodedata_strs

#define mmi_cca_doc_get_nodes                           srv_cca_doc_get_nodes//.

#define mmi_cca_doc_get_nodedata                        srv_cca_doc_get_nodedata//.

//#define mmi_cca_doc_get_nodedata_by_param               srv_cca_doc_get_nodedata_by_param//.

#define mmi_cca_doc_get_nodedata_int_first              srv_cca_doc_get_nodedata_int_first//.
#define mmi_cca_doc_get_nodedata_str_first              srv_cca_doc_get_nodedata_str_first//.
#define mmi_cca_doc_get_nodedata_ints                   srv_cca_doc_get_nodedata_ints//.

#define mmi_cca_doc_get_nodedata_strs                   srv_cca_doc_get_nodedata_strs//.

#define mmi_cca_doc_nodedata_by_param                   srv_cca_doc_nodedata_by_param//.
#define mmi_cca_doc_nodedata_int_first                  srv_cca_doc_nodedata_int_first
#define mmi_cca_doc_nodedata_str_first                  srv_cca_doc_nodedata_str_first
#define mmi_cca_doc_nodedata_ints                       srv_cca_doc_nodedata_ints
#define mmi_cca_doc_nodedata_strs                       srv_cca_doc_nodedata_strs

#define mmi_cca_doc_update_coredata_int                 srv_cca_doc_update_coredata_int
#define mmi_cca_doc_update_coredata_str                 srv_cca_doc_update_coredata_str
//#define mmi_cca_doc_update_coredata_ints                srv_cca_doc_update_coredata_ints//.
//#define mmi_cca_doc_update_coredata_strs                srv_cca_doc_update_coredata_strs//.

#define mmi_cca_doc_update_nodedata_int                 srv_cca_doc_update_nodedata_int
#define mmi_cca_doc_update_nodedata_str                 srv_cca_doc_update_nodedata_str
//#define mmi_cca_doc_update_nodedata_ints                srv_cca_doc_update_nodedata_ints
//#define mmi_cca_doc_update_nodedata_strs                srv_cca_doc_update_nodedata_strs

//#define mmi_cca_doc_coredata_remove_value               srv_cca_doc_coredata_remove_value//.
//#define mmi_cca_doc_remove_nodedata                     srv_cca_doc_remove_nodedata

//#define mmi_cca_doc_node_has_param_value                srv_cca_doc_node_has_param_value
//#define mmi_cca_doc_coredata_exists_int                 srv_cca_doc_coredata_exists_int//.
//#define mmi_cca_doc_coredata_exists_str                 srv_cca_doc_coredata_exists_str//.
//#define mmi_cca_doc_coredata_is_equal                   srv_cca_doc_coredata_is_equal//.
//#define mmi_cca_doc_node_check_equal_content            srv_cca_doc_node_check_equal_content

/* APP layer */
//#define mmi_cca_ui_common_cancel                        mmi_cca_cmn_cancel//.

/* should be phase out but not change the name. */
//#define mmi_cca_is_ascii_string                         srv_cca_is_ascii_string
//#define mmi_cca_register_memfull_notify                 srv_cca_register_memfull_notify
//#define mmi_cca_deregister_memfull_notify               srv_cca_deregister_memfull_notify

#define mmi_cca_iterator_next                           srv_cca_iterator_next//.
#define mmi_cca_iterator_release                        srv_cca_iterator_release//.
#define mmi_cca_iterator_restart                        srv_cca_iterator_restart//.

//#define mmi_cca_oma_add_deprel                          srv_cca_oma_add_deprel
#define mmi_cca_oma_add_dataacctid                      srv_cca_oma_add_dataacctid

#define mmi_cca_generate_hash_value                     srv_cca_generate_hash_value

/* should ask UPP to revise it. */
//#define mmi_cca_send_cca_app_update_prof_rsp            srv_cca_send_cca_app_update_prof_rsp
//#define mmi_cca_send_cca_app_get_prof_rsp               srv_cca_send_cca_app_get_prof_rsp


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif 
#endif

#endif /* SRV_CCA_GPROT_H */

