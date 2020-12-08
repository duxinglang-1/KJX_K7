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
 * vmxml.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * xml
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
#ifdef __MRE_LIB_XML__
#include "MMIDataType.h"
#include "xml_def.h"
#include "vmsys.h"
#include "vmchset.h"
#include "vmxml.h"
#include "vmpromng.h"
#include "vmresmng.h"


#include "vmlog.h"

typedef struct _vm_xml_struct{
	VM_XML_PARSER_STRUCT * vm_parser;
	XML_PARSER_STRUCT * mtk_parser;
} vm_xml_struct;

extern VMINT mre_running;

static XML_PARSER_STRUCT mtk_xml_parser ;

static VMINT current_handle = -1;

   
static void xml_doctype_start_handler( void *data,
										const VMCHAR *doctypeName,
										const VMCHAR **sysid, 
										const VMCHAR **pubid,
										VMINT internal_subset,
										VMINT error)
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (mre_running == FALSE)
	       return;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_130 , current_handle);
	       return;
	}

	xml_struct->vm_parser->start_doctype_hdlr(data, doctypeName, sysid, pubid, internal_subset, error);
	
}


static void xml_doctype_end_handler(void *data, VMINT error)
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (mre_running == FALSE)
	       return;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_154 , current_handle);
	       return;
	}

	xml_struct->vm_parser->end_doctype_hdlr(data, error);

}

static void xml_elem_start_handler( void *data, 
									const VMCHAR *el, 
									const VMCHAR **attr, 
									VMINT error)
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (mre_running == FALSE)
	       return;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_181 , current_handle);
	       return;
	}

	xml_struct->vm_parser->start_elem_hdlr(data, el, attr, error);

}

static void xml_elem_end_handler(void *data, const VMCHAR *el, VMINT error)
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (mre_running == FALSE)
	       return;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_205 , current_handle);
	       return;
	}

	xml_struct->vm_parser->end_elem_hdlr(data, el, error);

}

static void xml_data_handler(
							void *resv, 
							const VMCHAR *el, 
							const VMCHAR *data, 
							VMINT len, 
							VMINT error)
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (mre_running == FALSE)
	       return;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_234 ,current_handle);
	       return;
	}

	xml_struct->vm_parser->data_hdlr(resv, el, data, len, error);

}


VMINT vm_xml_new_parser(VM_XML_PARSER_STRUCT *parser)
{
	int ret = XML_RESULT_FAIL;
	
	if (NULL != parser)
	{
		parser->start_doctype_hdlr = xml_doctype_start_handler;
		parser->end_doctype_hdlr = xml_doctype_end_handler;
		parser->start_elem_hdlr = xml_elem_start_handler;
		parser->end_elem_hdlr = xml_elem_end_handler;
		parser->data_hdlr = xml_data_handler;
		
		ret = XML_RESULT_OK;
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_262 );
	}
	return ret;
}

void vm_xml_set_doctype_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr)
{
	if (NULL != parser)
	{
		parser->start_doctype_hdlr = (NULL==start_hdlr) ? xml_doctype_start_handler : start_hdlr;
		parser->end_doctype_hdlr = (NULL==end_hdlr) ? xml_doctype_end_handler : end_hdlr;
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_278 );
	}
}
void vm_xml_set_element_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr)
{
	if (NULL != parser)
	{
		parser->start_elem_hdlr = (NULL==start_hdlr) ? xml_elem_start_handler : start_hdlr;
		parser->end_elem_hdlr = (NULL==end_hdlr) ? xml_elem_end_handler : end_hdlr;
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_294 );
	}
}

void vm_xml_set_data_handler(
	VM_XML_PARSER_STRUCT *parser, 
	XML_data_hdlr data_hdlr)
{
	if (NULL != parser)
	{
		parser->data_hdlr = (NULL==data_hdlr) ? xml_data_handler : data_hdlr;
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_318 );
	}
}

VMINT vm_xml_parse(
	VM_XML_PARSER_STRUCT *parser,
	const VMCHAR *xmlsource,
	VMINT length)
{
	int ret = VM_XML_RESULT_FAIL;

	ret = xml_new_parser(&mtk_xml_parser);

	if (XML_RESULT_OK != ret)
	{
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMXML_336 , ret);
		xml_close_parser(&mtk_xml_parser);
		return -1;
	}
	
	xml_configure_memory(&mtk_xml_parser, vm_malloc, vm_free);

		
    xml_register_doctype_handler(
	   	&mtk_xml_parser, 
	   	parser->start_doctype_hdlr, 
	   	parser->end_doctype_hdlr);
	   
    xml_register_element_handler(
	   	&mtk_xml_parser, 
	   	parser->start_elem_hdlr, 
	   	parser->end_elem_hdlr);
	   
    xml_register_data_handler(
	   	&mtk_xml_parser, 
	   	parser->data_hdlr);
	   
	if(0 == length)
	{
		ret = xml_parse(&mtk_xml_parser, (VMUWSTR)vm_ucs2_string_by_ascii((VMSTR)xmlsource));
	}
	else
	{
		ret = xml_parse_buffer(&mtk_xml_parser, xmlsource, length);
	}

	xml_close_parser(&mtk_xml_parser);

	if (XML_RESULT_OK!= ret)
	{
 		return -1;
	}

	return VM_XML_RESULT_OK;
}

VMCHAR* vm_xml_get_error()
{
	return xml_get_err_string(&mtk_xml_parser);
}

#endif	

