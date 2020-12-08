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
*  
*
* Project:
* --------
*  MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_LIB_MULTI_LANG__

#include "string.h"
#include "vmsys.h"
#include "vmmullang.h"
#include "vmres.h"
#include "vmtlv.h"

#include "vmgraph.h"

#include "vmstdlib.h"
#include "vmchset.h"

static	VMINT	current_lang;

extern VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/*****************************************************************************
 * FUNCTION
 *  vm_mul_lang_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMCHAR * vm_mul_lang_init( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMUINT8 *	tag_buf;
	VMINT		tag_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	tag_buf = vm_load_resource( MUL_LANG_RES_NAME, &tag_len );
	if( tag_buf == NULL || tag_len == 0 )
		return 0;

	current_lang = VM_LANG_ENG;

	return (VMCHAR *)tag_buf;
}


/*****************************************************************************
 * FUNCTION
 *  vm_mul_lang_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mul_lang_handle     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_mul_lang_deinit( VMCHAR *	mul_lang_handle )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( mul_lang_handle )
		vm_free( (VMCHAR *)mul_lang_handle );

	return;
}



/*****************************************************************************
 * FUNCTION
 *  vm_mul_lang_get_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_buf        [?]         
 *  res_id          [IN]        
 *  lang_id         [IN]        
 *  str_buf         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_mul_lang_get_string( VMCHAR * lang_buf, VMINT res_id, VMINT lang_id, VMCHAR ** str_buf )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMCHAR *	res_buf = NULL;
	VMINT		res_len = 0, lang_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( lang_buf == NULL || str_buf == NULL )
		return 0;

	res_len = SearchTagByID( res_id, lang_buf, &res_buf );
	if( res_buf && res_len )
	{
		lang_len = SearchTagByID( lang_id, res_buf, str_buf );
		if( str_buf && lang_len )
			return lang_len;
		else
			return 0;
	}

	str_buf = NULL;

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_mul_lang_set_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_mul_lang_set_lang( VMINT	lang_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( lang_id < VM_LANG_ID_START || lang_id > VM_LANG_ID_END )
		return 0;

	current_lang = lang_id;

	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_mul_lang_get_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_mul_lang_get_lang( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return current_lang;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_get_string_width_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang_buf        [?]         
 *  res_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_graphic_get_string_width_by_id( VMCHAR * lang_buf, VMINT res_id )
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT	lang_id = 0, string_length = 0, string_width = 0;
	VMCHAR * string_buffer = NULL, * s_ch = NULL;
	VMWCHAR *	s_w = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( lang_buf == NULL )
		return VM_GDI_ERR_WRONG_PARAM;
	
	lang_id = vm_mul_lang_get_lang();
	
	string_length = vm_mul_lang_get_string( lang_buf, res_id, lang_id, &string_buffer );
	if( string_length )
	{
		s_ch = (VMCHAR *)vm_malloc(string_length+2);
		if( s_ch == NULL )
			return VM_GDI_ERR_MALLOC_FAILED;
			
		s_w = (VMWCHAR *)vm_malloc( (string_length+2) * sizeof(VMWCHAR) );
		if( s_w == NULL )
		{
			vm_free( s_ch );
			
			return VM_GDI_ERR_MALLOC_FAILED;
		}

		memset( s_ch, 0x00, string_length + 2 );
		memset( s_w, 0x00, (string_length + 2) * sizeof(VMWCHAR) );
		
		memcpy( s_ch, string_buffer, string_length );
		
		//vm_gb2312_to_ucs2( s_w, (string_length+2)*sizeof(VMWCHAR), s_ch );
		vm_default_to_ucs2( s_w, (string_length+2)*sizeof(VMWCHAR), s_ch );
		
		vm_free( s_ch );
		
		string_width = vm_graphic_get_string_width( s_w );
		
		vm_free( s_w );
	}
	
	return string_width;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_textout_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  disp_buf        [?]         
 *  x               [IN]        
 *  y               [IN]        
 *  lang_buf        [?]         
 *  res_id          [IN]        
 *  color           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_textout_by_id( VMUINT8* disp_buf, VMINT x, VMINT y, VMCHAR * lang_buf, VMINT res_id, VMUINT16 color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT lang_id = 0, string_length = 0;   /* , string_width = 0; */
	VMCHAR * string_buffer = NULL, * s_ch = NULL;
	VMWCHAR *	s_w = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if( lang_buf == NULL )
		return;
	
	lang_id = vm_mul_lang_get_lang();
	
	string_length = vm_mul_lang_get_string( lang_buf, res_id, lang_id, &string_buffer );
	if( string_length )
	{
		s_ch = (VMCHAR *)vm_malloc(string_length+2);
		if( s_ch == NULL )
			return;
			
		s_w = (VMWCHAR *)vm_malloc( (string_length+2) * sizeof(VMWCHAR) );
		if( s_w == NULL )
		{
			vm_free( s_ch );
			
			return;
		}

		memset( s_ch, 0x00, string_length + 2 );
		memset( s_w, 0x00, (string_length + 2) * sizeof(VMWCHAR) );
		
		memcpy( s_ch, string_buffer, string_length );

		//vm_gb2312_to_ucs2( s_w, (string_length+2)*sizeof(VMWCHAR), s_ch );
		vm_default_to_ucs2( s_w, (string_length+2)*sizeof(VMWCHAR), s_ch );
		
		vm_free( s_ch );

		//vm_graphic_get_string_width( s_w );
		vm_graphic_textout( disp_buf, x, y, s_w, vm_wstrlen(s_w), color );
		
		vm_free( s_w );
	}
}

#endif /* __MRE_LIB_MULTI_LANG__ */ 

