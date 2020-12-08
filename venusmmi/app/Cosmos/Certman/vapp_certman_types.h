/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_certman_types.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CERTMAN_TYPES_H__
#define __VAPP_CERTMAN_TYPES_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__  

#ifdef __cplusplus
extern "C"{
#endif
#include "certman_api.h"
#ifdef __cplusplus
}
#endif

typedef enum
{
    VAPP_CERTMAN_INVALID_CERT_INSTALL = 0,
    VAPP_CERTMAN_INVALID_CERT_ACCEPT,
    VAPP_CERTMAN_INVALID_CERT_DENY
} vapp_certman_invalid_certificate_action_enum;


typedef enum
{
    VAPP_CERTMAN_ACTION_OPEN,
    VAPP_CERTMAN_ACTION_CANCEL
}vapp_certman_action_enum;


typedef enum
{
    VAPP_CERTMAN_KP_SERVER_AUTH = CERTMAN_KP_SERVER_AUTH,
    VAPP_CERTMAN_KP_CLIENT_AUTH = CERTMAN_KP_CLIENT_AUTH,
    VAPP_CERTMAN_KP_CODE_SIGNING = CERTMAN_KP_CODE_SIGNING,
    VAPP_CERTMAN_KP_EMAIL_PROTECTION = CERTMAN_KP_EMAIL_PROTECTION,
    VAPP_CERTMAN_KP_IPSEC_ENDSYSTEM = CERTMAN_KP_IPSEC_ENDSYSTEM,
    VPP_CERTMAN_KP_IPSEC_TUNNEL = CERTMAN_KP_IPSEC_TUNNEL,
    VAPP_CERTMAN_KP_IPSEC_USER = CERTMAN_KP_IPSEC_USER,
    VAPP_CERTMAN_KP_TIME_STAMPING = CERTMAN_KP_TIME_STAMPING,
    VAPP_CERTMAN_KP_OCSP_SIGNING = CERTMAN_KP_OCSP_SIGNING,
    /*To match the enums with core. So update TOTAL_KEY_USAGE manually if a new key usage is added*/
    VAPP_CERTMAN_TOTAL_KEY_USAGE = 9 
}vapp_certman_keypurpose_enum;


typedef enum
{
    VAPP_CERTMAN_CERT_GROUP_ALL = CERTMAN_CERTGRP_NONE,
    VAPP_CERTMAN_CERT_GROUP_ROOT_CA = CERTMAN_CERTGRP_ROOTCA,
    VAPP_CERTMAN_CERT_GROUP_INTERMEDIATE_CA = CERTMAN_CERTGRP_CA,
    VAPP_CERTMAN_CERT_GROUP_AUTHORITY = CERTMAN_CERTGRP_ROOTCA | CERTMAN_CERTGRP_CA,
    VAPP_CERTMAN_CERT_GROUP_OTHER_USER = CERTMAN_CERTGRP_OTHERUSER,
    VAPP_CERTMAN_CERT_GROUP_PERSONAL= CERTMAN_CERTGRP_PERSONAL,
    VAPP_CERTMAN_CERT_GROUP_USER = CERTMAN_CERTGRP_OTHERUSER | CERTMAN_CERTGRP_PERSONAL
} vapp_certman_cert_group_enum;


typedef enum
{
    VAPP_CERTMAN_PUBKEY_TYPE_RSA_SIGN = CERTMAN_PUBKEY_RSA,
    VAPP_CERTMAN_PUBKEY_TYPE_DSA_SIGN = CERTMAN_PUBKEY_DSA,
    VAPP_CERTMAN_PUBKEY_TYPE_DH_ANSI_SIGN = CERTMAN_PUBKEY_DH_ANSI,
    VAPP_CERTMAN_PUBKEY_TYPE_DH_PKCS3_SIGN = CERTMAN_PUBKEY_DH_PKCS3,
    VAPP_CERTMAN_PUBKEY_TYPE_EC_SIGN = CERTMAN_PUBKEY_EC,
    VAPP_CERTMAN_PUBKEY_TYPE_ALL =  CERTMAN_PUBKEY_RSA
                                |CERTMAN_PUBKEY_DSA
                                |CERTMAN_PUBKEY_DH_ANSI
                                |CERTMAN_PUBKEY_DH_PKCS3
                                |CERTMAN_PUBKEY_EC
} vapp_certman_cert_key_type_enum;

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_TYPES_H__ */
