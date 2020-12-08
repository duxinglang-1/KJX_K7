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
 * mma_xml.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions which are used for XML interfacing.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_XML_C
#define _MMA_XML_C

#if defined(MMS_SUPPORT)
#include <stdio.h>
#include <stdlib.h>

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h" 

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "custom_wap_config.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"

/* WAPADP */
#include "wapadp.h"
#include "mmsadp.h"

/* MSF */
#include "msf_def.h"
#include "msf_int.h"
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_cmmn.h"   /* MSF: String operation */
#include "msf_chrs.h"   /* MSF: character API */
#include "msf_log.h"    /* MSF: Signal logging */

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mmsl_if.h"
/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_msg_struct.h"
#include "mma_parse.h"
#include "mma_create.h"
#include "mma_xml.h"
#include "mma_utilities.h"
#include "mma_msgmgr.h"
#include "mma_mime.h"

/* Misc */
#include "fs_type.h"
#include "xml_def.h"
#include "Conversions.h"
#include "FileMgrGprot.h"

/*vender MMS macro wrapp*/
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))

#define MMA_XML_TEMP_STR_LEN (1024)
#define MMA_XML_TEMP_SHORT_STR_LEN (8)
#define MMA_XML_TEMP_NORMAL_STR_LEN (12)
#define MMA_XML_TEMP_COLOR_STR_LEN (12)

/***************************************************************************** 
* Define
*****************************************************************************/
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/
static mma_xml_parser_info_struct *prs_info = NULL;

/***************************************************************************** 
* Local Function
*****************************************************************************/







/*****************************************************************************
 * FUNCTION
 *  mma_xml_get_object_by_xml_id
 * DESCRIPTION
 *  Get object pointer by object id
 * PARAMETERS
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_mms_object_struct *mma_xml_get_object_by_xml_id(kal_uint16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = prs_info->info->mms_dsr->body->objects;
    kal_uint32 object_num = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object == NULL)
    {
        return NULL;
    }
    for (; object != NULL; object = object->next, object_num++)
    {
        /*Earlier the object IDs from the UC come in sequence,
		But in postcard case they are like (2, 1) so commenting the assert.*/

		//ASSERT(object_num <= prs_info->info->header->body_no);
        if (object->id == id)
        {
            return object;
        }
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_insert_slide_by_xml_id
 * DESCRIPTION
 *  Insert slide by slide index
 * PARAMETERS
 *  index         [IN]
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
static mma_mms_slide_struct* mma_xml_insert_slide_by_xml_id(mma_mms_description_body_struct *body, kal_uint8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = NULL;
   // mma_setting_struct sliding;

    slide = (mma_mms_slide_struct*)MMA_CALLOC(sizeof(mma_mms_slide_struct));
    ASSERT(body != NULL && slide != NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide->slide_num = index;
    if (index == 1)
    {
        if(body->slides != NULL)
        {
            slide->next = body->slides;
    }
        body->slides = slide;
}
    else
    {
        mma_mms_slide_struct* cur_slide = body->slides;
        mma_mms_slide_struct* pre_slide = cur_slide;
        while (cur_slide && (cur_slide->slide_num < index))
        {
            pre_slide = cur_slide;
            cur_slide = cur_slide->next;
    }
        slide->next = cur_slide;
        pre_slide->next = slide;
}

  //  mma_conf_get_sliding_time(&sliding);
  //  slide->duration = sliding.value;

//    body->slide_no++;
    body->curr_slide = slide;
    return slide;
}




/*****************************************************************************
 * FUNCTION
 *  mma_xml_data_address_hdlr
 * DESCRIPTION
 *  Add address
 * PARAMETERS
 *  utf8_addr       [IN]        
 *  addr_len        [IN]        
 *  addr_type       [IN]        
 *  group           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_data_address_hdlr(
        const char *utf8_addr,
        int addr_len,
        MmsAddressType addr_type,
        mma_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_type == MMS_PLMN || addr_type == MMS_EMAIL)
{
        MmsAddressList **list = NULL;

        switch (group)
    {
        case MMA_ADDRESS_GROUP_TYPE_TO:
                list = &prs_info->info->header->header.s_header->to;
            break;

        case MMA_ADDRESS_GROUP_TYPE_CC:
                list = &prs_info->info->header->header.s_header->cc;
            break;

        case MMA_ADDRESS_GROUP_TYPE_BCC:
                list = &prs_info->info->header->header.s_header->bcc;
            break;

        case MMA_ADDRESS_GROUP_TYPE_FROM:
				 prs_info->info->header->header.s_header->fromType = MMS_FROM_ADDRESS_PRESENT;
				 prs_info->info->header->header.s_header->from.addrType = MMS_PLMN;
	  		    /* if (addr_type == MMS_EMAIL && name != NULL)
        {
				          prs_info->info->header->header.s_header->from.name.charset = mma_is_ascii_string(name) ? MMS_US_ASCII : MMS_UTF8;
						  item->current.name.size = strlen(name); 
					      prs_info->info->header->header.s_header->from.name.text = msf_cmmn_strdup(MSF_MODID_MMA, name);
				     }*/
				 prs_info->info->header->header.s_header->from.address = msf_cmmn_strdup(MSF_MODID_MMA, utf8_addr); 
                return;

        default:
        {
            ASSERT(0);
        }
            break;
    }

        mma_insert_addr_to_list(list, addr_type, NULL, (char*)utf8_addr);
    }
    else
    {
        ASSERT(0);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mma_xml_associate_object_id
 * DESCRIPTION
 *  Associate object id after parsing xml file
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 Decimal value.(?)
 *****************************************************************************/
void mma_xml_associate_object_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = NULL;
    mma_mms_slide_struct *slide = prs_info->info->mms_dsr->body->slides;
	mma_mms_slide_ref_object_struct *ref_items = NULL, *temp = NULL, *prev = NULL;
    kal_uint32 slide_num = 0;
    const char *mime = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide != NULL)
    {
        for (; slide != NULL; slide = slide->next, slide_num++)
        {


					/*text*/      
                    object = mma_xml_get_object_by_xml_id(slide->txt.id);
    //                ASSERT(object != NULL);
					if(object)
{
#ifdef __DRM_SUPPORT__
                    if (object->drm_type == MMA_DRM_NONE)
#endif
    {
                    mime = mma_get_mime_type_from_filename_and_type(object->file_name, MIME_TYPE_TEXT);
					 if (mime != NULL && msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime) != 0)
        {
                            object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
        }
    }
					slide->txt.object = object;
}
					else
{
						slide->txt.id = 0;
						slide->txt.object = NULL;

    }
					/*image*/      
                    object = mma_xml_get_object_by_xml_id(slide->img.id);
					if(object)
    {
#ifdef __DRM_SUPPORT__
                    if (object->drm_type == MMA_DRM_NONE)
#endif
        {
                    mime = mma_get_mime_type_from_filename_and_type(object->file_name, MIME_TYPE_IMAGE);
					 if (mime != NULL && msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime) != 0)
        {
                            object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
        }
        }
					slide->img.object = object;
        }
        else
        {
						slide->img.id = 0;
						slide->img.object = NULL;

            }

					/*video*/      
                    object = mma_xml_get_object_by_xml_id(slide->vid.id);
                    if(object)
            {
#ifdef __DRM_SUPPORT__
                    if (object->drm_type == MMA_DRM_NONE)
#endif
            {
                    mime = mma_get_mime_type_from_filename_and_type(object->file_name, MIME_TYPE_VIDEO);
					 if (mime != NULL && msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime) != 0)
            {
                            object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
            }
        }
					slide->vid.object = object;
            }
            else
            {
						slide->vid.id = 0;
						slide->vid.object = NULL;

        }

					/*audio*/      
                    object = mma_xml_get_object_by_xml_id(slide->aud.id);
					if(object)
        {
#ifdef __DRM_SUPPORT__
                    if (object->drm_type == MMA_DRM_NONE)
#endif
        {
                    mime = mma_get_mime_type_from_filename_and_type(object->file_name, MIME_TYPE_AUDIO);
					 if (mime != NULL && msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime) != 0)
    {
                            object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
    }
    }
					slide->aud.object = object;
    }
					else
    {
						slide->aud.id = 0;
						slide->aud.object = NULL;

    }

					ref_items = prs_info->info->mms_dsr->body->slides->ref_items;
					while(ref_items)
    {
						object = mma_xml_get_object_by_xml_id(ref_items->id);
	                    if(object)
    {
						#ifdef __DRM_SUPPORT__
							if (object->drm_type == MMA_DRM_NONE)
						#endif
    {
							mime = mma_get_mime_type_from_filename_and_type(object->file_name, MIME_TYPE_NONE);
							if (mime != NULL && msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime) != 0)
    {
							  object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, mime);
    }
    }
						ref_items->object = object;
    }
						else
    {
							/* remove the ref object from list */
							temp = prs_info->info->mms_dsr->body->slides->ref_items;
							if (ref_items == prs_info->info->mms_dsr->body->slides->ref_items)
        {
									prs_info->info->mms_dsr->body->slides->ref_items = prs_info->info->mms_dsr->body->slides->ref_items->next;									
        }
							else
        {
									while(temp != ref_items)
        {
										prev = temp;
										temp = temp->next;
        }
									prev->next = temp->next;
    }

}

					ref_items = ref_items->next;					
    }
    }
    }
    ASSERT(slide_num == prs_info->info->mms_dsr->body->slide_no);
    }

    



/*****************************************************************************
 * FUNCTION
 *  mma_xml_process_parsed_info
 * DESCRIPTION
 *  Associate object id after parsing xml file
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 Decimal value.(?)
 *****************************************************************************/
void mma_xml_process_parsed_info(void)
    {

    }





/*****************************************************************************
 * FUNCTION
 *  mma_xml_data_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  data        [IN]         
 *  el          [IN]        
 *  attr        [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(MMA_XML_ELEMENT_TO, el))
        {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_TO);
        }
    else if (!strcmp(MMA_XML_ELEMENT_CC, el))
            {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_CC);
            }
    else if (!strcmp(MMA_XML_ELEMENT_BCC, el))
            {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_BCC);
        }
    else if (!strcmp(MMA_XML_ELEMENT_FROM, el))
            {
        mma_xml_data_address_hdlr(value, len, prs_info->addr_type, MMA_ADDRESS_GROUP_TYPE_FROM);
            }
    else if (!strcmp(MMA_XML_ELEMENT_SUBJECT, el))
            {
        prs_info->info->header->header.s_header->subject.charset = MMS_UTF8;
        if (len > 0)
{
            int size = msf_cmmn_base64_decode_len(value, len) + 1;

            prs_info->info->header->header.s_header->subject.text = (char*)MMA_CALLOC(size);
            msf_cmmn_base64_decode(value, len, prs_info->info->header->header.s_header->subject.text, &size);
        }
        else
        {
            prs_info->info->header->header.s_header->subject.text = NULL;
        }
    }
	 else if (!strcmp(MMA_XML_ELEMENT_READ_REPORT, el))
    {
        if (atoi((char*)value))
        {
            prs_info->info->header->header.s_header->readReply = MMS_READ_REPLY_YES;
        }
        else
        {
            prs_info->info->header->header.s_header->readReply = MMS_READ_REPLY_NO;
    }
}
    else if (!strcmp(MMA_XML_ELEMENT_DELIVERY_REPORT, el))
{
        if (atoi((char*)value))
    {
            prs_info->info->header->header.s_header->deliveryReport = MMS_DELIVERY_REPORT_YES;
    }
    else
    {
            prs_info->info->header->header.s_header->deliveryReport = MMS_DELIVERY_REPORT_NO;
}
}
    else if (!strcmp(MMA_XML_ELEMENT_PRIORITY, el))
    {
       prs_info->info->header->header.s_header->priority = translate_mma_priority_to_mms((mma_priority_enum)atoi((char*)value));
}
    else if (!strcmp(MMA_XML_ELEMENT_EXPIRY, el))
{
        translate_mma_expiry_to_mms(
            (mma_expiry_time_enum)atoi((char*)value),
            prs_info->info->header->header.s_header->date,
            (MmsTimeType*)&prs_info->info->header->header.s_header->expiryTimeType,
            &prs_info->info->header->header.s_header->expiryTime);
}
    else if (!strcmp(MMA_XML_ELEMENT_DELIVERY_TIME, el))
        {
        translate_mma_delivery_to_mms(
            (mma_delivery_time_enum)atoi((char*)value),
            prs_info->info->header->header.s_header->date,
            (MmsTimeType*)&prs_info->info->header->header.s_header->deliveryTimeType,
            &prs_info->info->header->header.s_header->deliveryTime);
    }
    else if (!strcmp(MMA_XML_ELEMENT_VISIBLE, el))
    {
        if (atoi((char*)value) == FALSE)
        {
            prs_info->info->header->header.s_header->visibility = MMS_SENDER_HIDE;
}
    }
    else if (!strcmp(MMA_XML_ELEMENT_APP_ID, el))
        {
        mma_add_param_string(
            (MmsAllParams**)&prs_info->info->header->header.s_header->contentType->params,
            MMS_TEXT_KEY,
            MMA_HEADER_APPLICATION_ID_STR,
            value);
}
    else if (!strcmp(MMA_XML_ELEMENT_REPLY_APP_ID, el))
                        {
        mma_add_param_string(
            (MmsAllParams**)&prs_info->info->header->header.s_header->contentType->params,
            MMS_TEXT_KEY,
            MMA_HEADER_REPLY_APPLICATION_ID_STR,
            value);
                        }
    else if (!strcmp(MMA_XML_ELEMENT_VERSION, el))
                        {
        prs_info->info->header->s_version = translate_mma_version_to_mms((mma_version_enum)atoi((char*)value));
}
    else if (!strcmp(MMA_XML_ELEMENT_CLASS, el))
                    {
        /* Set Class Identifier */
           prs_info->info->header->header.s_header->msgClass.classIdentifier = 
                                translate_mma_class_to_mms((mma_msg_class_enum)atoi((char*)value));
            }
    else if (!strcmp(MMA_XML_ELEMENT_PRESENTATION, el))
            {
        mma_add_param_string((MmsAllParams**)&prs_info->info->header->header.s_header->contentType->params, MMS_START_REL, NULL, value);
        mma_add_param_string(
            (MmsAllParams**)&prs_info->info->header->header.s_header->contentType->params,
            MMS_TYPE_REL,
            NULL,
            MMS_MEDIA_TYPE_STRING_SMIL);
            }
    else if (!strcmp(MMA_XML_ELEMENT_NAME, el))
                {
        prs_info->object->file_name = msf_cmmn_strdup(MSF_MODID_MMA, value);
                }
    else if (!strcmp(MMA_XML_ELEMENT_MIME, el))
                    {
        prs_info->object->mime_str = msf_cmmn_strdup(MSF_MODID_MMA, value);
                }
    else if (!strcmp(MMA_XML_ELEMENT_CONTENT_ID, el))
            {
        prs_info->object->content_id = msf_cmmn_strdup(MSF_MODID_MMA, value);
            }
    else if (!strcmp(MMA_XML_ELEMENT_CONTENT_LOCATION, el))
            {
        prs_info->object->content_location = msf_cmmn_strdup(MSF_MODID_MMA, value);
            }
    else if (!strcmp(MMA_XML_ELEMENT_FILE_PATH, el))
            {
        prs_info->object->file_path = msf_cmmn_strdup(MSF_MODID_MMA, value);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mma_xml_start_element_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  data        [IN]         
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!strcmp(MMA_XML_ELEMENT_TO, el)) || (!strcmp(MMA_XML_ELEMENT_CC, el)) ||
        (!strcmp(MMA_XML_ELEMENT_BCC, el)) || (!strcmp(MMA_XML_ELEMENT_FROM, el)))
    {
        if (!strcmp(MMA_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(MMA_XML_ATTR_POHNE_NUMBER, attr[1]))
            {
                prs_info->addr_type = MMS_PLMN;
            }
            else if (!strcmp(MMA_XML_ATTR_EMAIL_ADDR, attr[1]))
            {
                prs_info->addr_type = MMS_EMAIL;
            }
            else if (!strcmp(MMA_XML_ATTR_IPV4_ADDR, attr[1]))
            {
                prs_info->addr_type = MMS_IPV4;
            }
            else
            {
                ASSERT(0);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_EXPIRY, el))
    {
        if (attr[0] == NULL)
        {
            prs_info->info->header->header.s_header->expiryTimeType = MMS_TIME_RELATIVE;
        }
        else if (!strcmp(MMA_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(MMA_XML_ATTR_TIME_ABSOLUTE, attr[1]))
            {
                prs_info->info->header->header.s_header->expiryTimeType = MMS_TIME_ABSOLUTE;
            }
            else if (!strcmp(MMA_XML_ATTR_TIME_RELATIVE, attr[1]))
            {
                prs_info->info->header->header.s_header->expiryTimeType = MMS_TIME_RELATIVE;
            }
            else
            {
                ASSERT(0);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_DELIVERY_TIME, el))
    {
        if (attr[0] == NULL)
        {
            prs_info->info->header->header.s_header->deliveryTimeType = MMS_TIME_RELATIVE;
        }
        else if (!strcmp(MMA_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(MMA_XML_ATTR_TIME_ABSOLUTE, attr[1]))
            {
                prs_info->info->header->header.s_header->deliveryTimeType = MMS_TIME_ABSOLUTE;
            }
            else if (!strcmp(MMA_XML_ATTR_TIME_RELATIVE, attr[1]))
            {
                prs_info->info->header->header.s_header->deliveryTimeType = MMS_TIME_RELATIVE;
            }
            else
            {
                ASSERT(0);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_BODY, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_BGCOLOR, attr[i]))
            {
                prs_info->info->root_layout.bgColor = msf_cmmn_hex2int((const char*)attr[i + 1] + 2);
            }
            else if (!strcmp(MMA_XML_ATTR_FGCOLOR, attr[i]))
            {
                /* body fgcolor not supported 
                   g_uc_p->msg.foreground_color = msf_cmmn_hex2int((U8*) attr[i + 1] + 2); */
            }
            else if (!strcmp(MMA_XML_ATTR_SLIDE_NUM, attr[i]))
            {
                prs_info->info->mms_dsr->body->slide_no = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_OBJ_NUM, attr[i]))
            {
                prs_info->info->header->body_no = atoi((char*)attr[i + 1]);
				prs_info->info->mms_dsr->body->obj_no =  prs_info->info->header->body_no;
            }
            else if (!strcmp(MMA_XML_ATTR_LAYOUT, attr[i]))
            {
                prs_info->info->mms_dsr->body->layout = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_IMG_FIT, attr[i]))
            {
                prs_info->info->mms_dsr->body->image_fit = atoi((char*)attr[i + 1]);

        /*        mma_insert_region(MSF_MODID_MMA, 
                    &prs_info->info->body->regions,
                    MMA_CFG_IMAGE_REGION_NAME,
                    fit,
                    NULL,
                    MMA_SUBMODULE_MSG_CREATE);*/
            }
            else if (!strcmp(MMA_XML_ATTR_TXT_FIT, attr[i]))
            {
                prs_info->info->mms_dsr->body->text_fit = atoi((char*)attr[i + 1]);

             /*   mma_insert_region(MSF_MODID_MMA, 
                    &prs_info->info->body->regions,
                    MMA_CFG_TEXT_REGION_NAME,
                    fit,
                    NULL,
                    MMA_SUBMODULE_MSG_CREATE);*/
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_SLIDE, el))
    {
        kal_uint8 index = 0;
        kal_uint32 duration = 0;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_INDEX, attr[i]))
            {
                index = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_DURATION, attr[i]))
            {
                duration = atoi((char*)attr[i + 1]);
            }
        }

        if (index)
        {
            prs_info->slide = mma_xml_insert_slide_by_xml_id(prs_info->info->mms_dsr->body, index);

            if (prs_info->slide)
            {
                ASSERT(prs_info->slide->slide_num == index);
                prs_info->slide->duration = duration;
            }
            else
            {
                ASSERT(0);
            }
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_TEXT, el))
    {
    //    mma_slide_object_struct *s_obj = mma_insert_slide_obj_old(MSF_MODID_MMA, MIME_TYPE_TEXT, prs_info->slide, NULL);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
               prs_info->slide->txt.id = (atoi((char*)attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN, attr[i]))
            {
                 prs_info->slide->txt.begin = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END, attr[i]))
            {
                 prs_info->slide->txt.end = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_BGCOLOR, attr[i]))
            {
                /* text background color not supported
                   prs_info->slide->text->background_color = msf_cmmn_hex2int((char *) attr[i + 1] + 2); */
            }
            else if (!strcmp(MMA_XML_ATTR_FGCOLOR, attr[i]))
            {
                prs_info->slide->txt.fg_color = msf_cmmn_hex2int((char*)attr[i + 1] + 2);
                if ((SLS_COLOR_NOT_USED | prs_info->slide->txt.fg_color) == SLS_COLOR_NOT_USED)
                {
                   prs_info->slide->txt.fg_color = SLS_COLOR_NOT_USED;
                }
            }
            else if (!strcmp(MMA_XML_ATTR_TXT_STYLE, attr[i]))
            {
                 prs_info->slide->txt.text_style = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_TXT_SIZE, attr[i]))
            {
                 prs_info->slide->txt.text_size = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ALT, attr[i]))    /* maybe should use base64 en/decoding */
            {
                 prs_info->slide->txt.alt = msf_cmmn_strdup(MSF_MODID_MMA, attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_IMAGE, el))
    {
     //   mma_slide_object_struct *s_obj = mma_insert_slide_obj_old(MSF_MODID_MMA, MIME_TYPE_IMAGE, prs_info->slide, NULL);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
             prs_info->slide->img.id = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN, attr[i]))
            {
                prs_info->slide->img.begin = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END, attr[i]))
            {
               prs_info->slide->img.end = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ALT, attr[i]))    /* maybe should use base64 en/decoding */
            {
                prs_info->slide->img.alt = msf_cmmn_strdup(MSF_MODID_MMA, attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_AUDIO, el))
    {
       // mma_slide_object_struct *s_obj = mma_insert_slide_obj_old(MSF_MODID_MMA, MIME_TYPE_AUDIO, prs_info->slide, NULL);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
               prs_info->slide->aud.id = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN, attr[i]))
            {
                 prs_info->slide->aud.begin = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END, attr[i]))
            {
                prs_info->slide->aud.end = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ALT, attr[i]))    /* maybe should use base64 en/decoding */
            {
                 prs_info->slide->aud.alt = msf_cmmn_strdup(MSF_MODID_MMA, attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_VIDEO, el))
    {
    //    mma_slide_object_struct *s_obj = mma_insert_slide_obj_old(MSF_MODID_MMA, MIME_TYPE_VIDEO, prs_info->slide, NULL);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
                 prs_info->slide->vid.id = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN, attr[i]))
            {
                 prs_info->slide->vid.begin = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END, attr[i]))
            {
                 prs_info->slide->vid.end = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ALT, attr[i]))    /* maybe should use base64 en/decoding */
            {
                prs_info->slide->vid.alt = msf_cmmn_strdup(MSF_MODID_MMA, attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_REF, el))
    {
        mma_mms_slide_ref_object_struct *s_obj = mma_insert_slide_obj(MSF_MODID_MMA, MIME_TYPE_APPLICATION, prs_info->slide, NULL);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
                s_obj->id = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_BEGIN, attr[i]))
            {
                s_obj->begin = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_END, attr[i]))
            {
                s_obj->end = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ALT, attr[i]))    /* maybe should use base64 en/decoding */
            {
                s_obj->alt = msf_cmmn_strdup(MSF_MODID_MMA, attr[i + 1]);
            }
        }
    }
    else if (!strcmp(MMA_XML_ELEMENT_OBJECT, el))
    {
        prs_info->object = mma_insert_object_to_tail(MSF_MODID_MMA, prs_info->info->mms_dsr->body, NULL);
        /* prs_info->info->header->body_no++; */

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMA_XML_ATTR_ID, attr[i]))
            {
                prs_info->object->id = (atoi((char*)attr[i + 1]));
            }
            else if (!strcmp(MMA_XML_ATTR_ATTACH, attr[i]))
            {
                prs_info->object->is_attachment = (kal_bool)atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_VIRTUAL_FILE, attr[i]))
            {
                prs_info->object->is_virtual_file = (kal_bool)atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_DRM, attr[i]))
            {
            #ifdef __DRM_SUPPORT__
                prs_info->object->drm_type = atoi((char*)attr[i + 1]);
            #endif 
            }
            else if (!strcmp(MMA_XML_ATTR_SIZE, attr[i]))
            {
                prs_info->object->size = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_OFFSET, attr[i]))
            {
                prs_info->object->offset = atoi((char*)attr[i + 1]);
            }
            else if (!strcmp(MMA_XML_ATTR_ENCODING, attr[i]))
            {
                prs_info->object->charset = translate_mma_charset_to_mms((mma_charset_enum)atoi((char*)attr[i + 1]));
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_xml_end_element_hdlr
 * DESCRIPTION
 *  end element handler
 * PARAMETERS
 *  data        [IN]         
 *  el          [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_xml_end_element_hdlr(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(MMA_XML_ELEMENT_OBJECT, el))
    {
        if (prs_info->object->is_attachment)
        {
            mma_insert_unref_item_to_tail(MSF_MODID_MMA, prs_info->info->mms_dsr->body, prs_info->object);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mma_xml_parse_mms_description_file
 * DESCRIPTION
 *  Pare mms xml description file
 * PARAMETERS
 *  info        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
mma_result_enum mma_xml_parse_mms_description_file(mma_create_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    XML_PARSER_STRUCT *xml_parser = NULL;

    xml_parser = (XML_PARSER_STRUCT*) MMA_CALLOC(sizeof(XML_PARSER_STRUCT));
    result = xml_new_parser(xml_parser);
    if (result)
    {
        xml_close_parser(xml_parser);
        MMA_FREE(xml_parser);
        xml_parser = NULL;
        return MMA_RESULT_FAIL_PARSE;
    }

    ASSERT(prs_info == NULL);
    prs_info = (mma_xml_parser_info_struct*) MMA_CALLOC(sizeof(mma_xml_parser_info_struct));
    prs_info->info = info;

    xml_register_element_handler(xml_parser, mma_xml_start_element_hdlr, mma_xml_end_element_hdlr);
    xml_register_data_handler(xml_parser, mma_xml_data_hdlr);
    result = xml_parse(xml_parser, info->xml_filepath);
    xml_close_parser(xml_parser);

    MMA_FREE(xml_parser);
    xml_parser = NULL;

    if (result == XML_RESULT_OK)
    {
        mma_xml_associate_object_id();
        mma_create_process_mms_info(prs_info->info);
        result = MMA_RESULT_OK;
    }
    else
    {
        result = MMA_RESULT_FAIL_PARSE;
    }

    prs_info->info = NULL;
    prs_info->object = NULL;
    prs_info->slide = NULL;
    MMA_FREE(prs_info);
    prs_info = NULL;

    return (mma_result_enum)result;
}

#endif
#endif	/* MMS_SUPPORT */
#endif /* _MMA_XML_C */ 

