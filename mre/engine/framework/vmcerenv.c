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
 * vmcerenv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * cerenv
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_CORE_SAFETY__

#include "vmstdlib.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmcert.h"

#include "vmcerenv.h"
#include "vmcerter.h"

#include "vmmd5.h"
#include "vmsha1.h"

#include "vmlog.h"
#include "vmmem.h"

#include "string.h"


static	MRECertHead *		CertBuf = NULL;
static	MRECertHead_Ex*		CertBuf_Ex = NULL;

static  VMINT		digestype = 0;

extern void* vm_get_vm_tag_ptr_and_size(VMWSTR filename, VMINT* tag_size);

VMFILE vm_ce_open_file(VMWSTR filename)
{	
    return vm_file_open( filename, MODE_READ, TRUE );
}

void vm_ce_close_file(VMFILE handle)
{
    if( CertBuf )
        _vm_kernel_free( CertBuf );
        
	if( CertBuf_Ex)
		_vm_kernel_free( CertBuf_Ex );

    CertBuf = NULL;
	CertBuf_Ex = NULL;

    vm_file_close( handle );
}

VMINT vm_ce_read_cert(VMFILE handle, VMUINT8* buf, VMINT buf_size, VMINT * type)
{
    VMINT		res = 0;
    VMUINT		nRead = 0;
    VMUCHAR		tag[CERT_HEAD_LEN+1];
    VMINT size;
	void* certPtr = NULL;

    if( handle < 0)
        return VM_CE_READ_CERT_BAD_PARAM;

    memset( tag, 0x00, CERT_HEAD_LEN+1 );

	if(buf_size == RSA_LEN)
	{
		size = sizeof(MRECertHead);
		certPtr = CertBuf;
	}
	else
	{
		size = sizeof(MRECertHead_Ex);
		certPtr = CertBuf_Ex;
	}
	
	if(certPtr != NULL)
		return VM_CE_READ_CERT_BAD_PARAM;
	
	res = vm_file_seek( handle, 0-(VMINT)(size+CERT_HEAD_LEN), BASE_END );
	
	if( res < 0 )
		return VM_CE_READ_CERT_FILE_OP_ERROR;
	
	certPtr= (void *)_vm_kernel_malloc(size);
	
	if( certPtr == NULL )
		return VM_CE_READ_CERT_MEM_ERROR;

	if( vm_file_read( handle, (VMUCHAR *)tag, CERT_HEAD_LEN, &nRead ) == 0 )
	{
		_vm_kernel_free( certPtr );
		certPtr = NULL;

		return VM_CE_READ_CERT_TAG_READ_ERROR;
	}
	else
	{
		if( nRead != CERT_HEAD_LEN )
		{
			_vm_kernel_free( certPtr );
			certPtr = NULL;

			return VM_CE_READ_CERT_TAG_READ_ERROR;
		}
	}
		
	if( tag[0]!=0xb4 || strcmp((char*)(tag+1), "VDE10" ) != 0 )
	{			
		_vm_kernel_free( certPtr );
		certPtr = NULL;

		return VM_CE_READ_CERT_TAG_ERROR;
	}
	
	if( vm_file_read( handle, (VMUCHAR *)certPtr, size, &nRead ) == 0 )
	{	
		_vm_kernel_free( certPtr );
		certPtr = NULL;

		return VM_CE_READ_CERT_READ_CERT_ERROR; 
	}
	else
	{
		if( nRead != size)
		{
			_vm_kernel_free( certPtr );
			certPtr = NULL;

			return VM_CE_READ_CERT_READ_CERT_ERROR;
		}
	}

	
	if( buf_size == RSA_LEN*2 )
	{
		CertBuf_Ex = (MRECertHead_Ex*)certPtr;
		memcpy( buf, CertBuf_Ex->signature, RSA_LEN*2 );	
		*type = CertBuf_Ex->digestype;	
		digestype = CertBuf_Ex->digestype;
		return VM_CE_READ_CERT_OK;
	}

	if(buf_size == RSA_LEN)
	{
		CertBuf = (MRECertHead*)certPtr;
		memcpy( buf, CertBuf->signature, RSA_LEN );
		*type = CertBuf->digestype;
		digestype = CertBuf->digestype;
		return VM_CE_READ_CERT_OK;
	}

	_vm_kernel_free( certPtr );
	return VM_CE_READ_CERT_LOAD_SIGN_ERROR;
}

void vm_ce_get_cert_digest( VMWSTR filename, VMUCHAR* digest_buf)
{
	VMINT tag_size = 0;
	void* tag_ptr = vm_get_vm_tag_ptr_and_size(filename, &tag_size);
		
	if(tag_ptr == NULL || tag_size < 0)
		return;

#ifdef __MRE_SAL_CHE_MD5__
	if( digestype == CERT_DIGEST_TYPE_MD5 )
	{
		md5_state_t* certmd5 = (md5_state_t	*)_vm_kernel_malloc( sizeof(md5_state_t) );

		if( certmd5 == NULL )
			return ;
		
		md5_init( certmd5 );
        md5_append( certmd5, tag_ptr, tag_size );
		md5_finish( certmd5, digest_buf );
		_vm_kernel_free( certmd5 );
	}
#endif
#ifdef __MRE_SAL_CHE_SHA1__
	if( digestype == CERT_DIGEST_TYPE_SHA )
	{
		SHA1Context* certsha = (SHA1Context *)_vm_kernel_malloc( sizeof(SHA1Context) );

		if( certsha == NULL )
			return ;

		vm_sha1_reset( certsha );
        vm_sha1_input( certsha, tag_ptr, tag_size);
		vm_sha1_result( certsha );
		memcpy( digest_buf, (VMUCHAR *)&(certsha->Message_Digest[0]), DIG_SHA_LEN );
		_vm_kernel_free( certsha );
	}
#endif	    
	digestype = 0;
}

#endif

