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
 * Copyright (C) Obigo AB, 2002-2006.
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
 * sec_wtls.h
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

#ifndef _sec_wtls_h
#define _sec_wtls_h

#ifndef _sec_lib_h
#include "sec_lib.h"
#endif
#ifndef _msf_def_h
#include "msf_def.h"
#endif

int 
SEC_wtlsCheckLengthAndFormat(const unsigned char *wtlscert, MSF_UINT16 *certLen);

int 
SEC_wtlsParse(const unsigned char *wtlscert, 
              MSF_UINT16 *certLen, sec_certificate_t *sp_cert);

int 
SEC_wtlsGetVersion(const unsigned char *wtlscert, MSF_UINT8 *ver);

int 
SEC_wtlsGetSignatureAlgorithm(const unsigned char *wtlscert, MSF_UINT8 *signAlg);

int 
SEC_wtlsGetIssuer(const unsigned char *wtlscert, MSF_UINT8  *issuerIdentifierType,
                  MSF_UINT16 *issuercharacterSet, 
                  MSF_UINT8  *issuerLen, unsigned char  **issuer);

int 
SEC_wtlsGetIssuerAttributes(MSF_UINT8 modId, const unsigned char *issuer, 
                            MSF_UINT16 issuerLen, 
                            MSF_UINT8 *nbrIssuerAttributes,                                
                            sec_name_attribute_t *issuerA);

int 
SEC_wtlsGetValidity(const unsigned char *wtlscert,
                    MSF_UINT32 *valid_not_before, MSF_UINT32 *valid_not_after);

int 
SEC_wtlsGetSubject(const unsigned char *wtlscert,
                   MSF_UINT8 *subjectIdentifierType,
                   MSF_UINT16 *subjectcharacterSet,
                   MSF_UINT8 *subjectLen, unsigned char **subject);

int 
SEC_wtlsGetPublicKeyType(const unsigned char *wtlscert, MSF_UINT8 *public_key_type);

int 
SEC_wtlsGetParameterSpecifier(const unsigned char *wtlscert, 
                              MSF_UINT8 *parameter_index);

int 
SEC_wtlsGetPublicKey(const unsigned char *wtlscert,
                     MSF_UINT16 *expLen, unsigned char** rsa_exponent,
                     MSF_UINT16 *modLen, unsigned char** rsa_modulus);

int 
SEC_wtlsGetSignature(const unsigned char *wtlscert,
                     unsigned char **signature, MSF_UINT16 *signatureLen);


int 
SEC_wtlsComposeCert(unsigned char **cert, MSF_UINT16 *certLen, 
                    unsigned char *pubkey, MSF_UINT16 pubkeyLen);







#endif
