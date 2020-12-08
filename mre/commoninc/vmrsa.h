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
 * vmrsa.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * rsa
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef	_VM_RSA_H_
#define _VM_RSA_H_
#include "vmswitch.h"

#ifdef __MRE_CORE_SAFETY__
#include "vmsys.h"

#define		KEY_LEN			64

typedef struct _VMKey{
		VMINT		id;
		VMINT		modlen;
		VMINT		keylen;
		VMUCHAR		mod[KEY_LEN];
		VMUCHAR		key[KEY_LEN];
} VMKey;

typedef struct _VMKey_Ex{
		VMINT		id;
		VMINT		modlen;
		VMINT		keylen;
		VMUCHAR		mod[KEY_LEN*2];
		VMUCHAR		key[24];
} VMKey_Ex;

typedef VMKey		VMPUBKey;
typedef	VMKey		VMPRIKey;

enum{
	VM_RSA_BN_INDEX_IN = 0,
	VM_RSA_BN_INDEX_MOD,
	VM_RSA_BN_INDEX_KEY,

	VM_RSA_BN_INDEX_RES,
	VM_RSA_BN_INDEX_TOTAL
};

VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len );

VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );

VMINT vm_rsa_sign( VMUCHAR * content, VMINT cont_len, VMKey * key, VMUCHAR * signature, VMINT * sign_len, VMINT type );

VMINT vm_rsa_sign_by_id( VMUCHAR * content, VMINT cont_len, VMINT id, VMUCHAR * signature, VMINT * sign_len, VMINT type );


#endif

#endif
