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

/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */







/*******************************************************************************
 *
 * Filename:
 * ---------
 * mconfig.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MCONFIG_H
#define _MCONFIG_H



typedef enum
{
    


    MMS_CFG_FROM_ADDRESS_INSERT_TYPE,






    MMS_CFG_RETRIEVAL_MODE,

    


    MMS_CFG_PORT,

    


    MMS_CFG_REPORT_ALLOWED,

    
    MMS_CFG_FROM_ADDRESS_TYPE,




    MMS_CFG_MAX_RETRIEVAL_SIZE,

    


    MMS_CFG_ROAMING_MODE, 





    MMS_CFG_CLASS_PERSONAL, 
    
    





    MMS_CFG_CLASS_ADVERTISEMENT, 

    





    MMS_CFG_CLASS_INFORMATIONAL, 
    
    





    MMS_CFG_CLASS_AUTO, 

    



    MMS_CFG_ANONYMOUS_SENDER,
 




    MMS_CFG_DISCONNECT_ON_IDLE,
 
    

    MMS_CFG_TREAT_AS_DELAYED_RETRIEVAL,

    

    MMS_CFG_PROXY_RELAY_VERSION,

    

    MMS_CFG_STK_CONNECTION_TYPE,



    
    MMS_CFG_NETWORK_ACCOUNT,

    


    MMS_CFG_NOTIF_MATCH_TO_MMSC,

    
    MMS_CFG_GW_SECURE_PORT,

    
    MMS_CFG_GW_HTTP_PORT,


    MMS_CFG_TOTAL_INT
} MmsConfigInt;



typedef enum
{
    


    MMS_CFG_FROM_ADDRESS,

    



    MMS_CFG_IMMEDIATE_RETRIEVAL_SERVER,

    


    MMS_CFG_POST_URI,

    


    MMS_CFG_PROXY_RELAY,

    

    MMS_CFG_PROXY_RELAY_SCHEME,

    

    MMS_CFG_FROM_NAME,
    
    

    MMS_CFG_TEXT_YOUR_MSG,
    
    

    MMS_CFG_TEXT_FROM,
    
    

    MMS_CFG_TEXT_TO,
    
    

    MMS_CFG_TEXT_READ,
    
    

    MMS_CFG_TEXT_MSGID,
    
    

    MMS_CFG_TEXT_SENT,
    
    


    MMS_CFG_TEXT_WAS_READ,

    
    

    MMS_CFG_TEXT_SUBJECT,

    
    MMS_CFG_GW_ADDRESS,

    
    MMS_CFG_GW_PASSWORD,

    
    MMS_CFG_GW_REALM,



    MMS_CFG_CLIENT_HTTP_HEADER,
    
    
    MMS_CFG_GW_USERNAME,

    
    MMS_CFG_CLIENT_USER_AGENT,

    MMS_CFG_CLIENT_USER_AGENT_PROFILE,


    MMS_CFG_TOTAL_STR
} MmsConfigStr;


extern char * mmsa_getProfileStrParam(MSF_UINT8 param, MSF_UINT8 simId);
extern MSF_UINT32 mmsa_getProfileIntParam(MSF_UINT8 param, MSF_UINT8 simId);
extern char * mmsa_getSettingStrParam(MSF_UINT8 param);
extern MSF_UINT32 mmsa_getSettingIntParam(MSF_UINT8 param);
extern MSF_UINT32 mmsa_getGeneralIntParam(MSF_UINT8 param);
extern char * mmsa_getReadReportStrParam(MSF_UINT8 param);


#endif 

