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
 * UcXmlSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements .......... Unified Composer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifndef _UNIFIED_COMPOSER_XML_SRV_C
#define _UNIFIED_COMPOSER_XML_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

#include "app_oppostcard.h"
#include "Conversions.h"
//#include "UmGprot.h"
#include "UcSrvGProt.h"
#include "UcSrvIprot.h"
#include "UcSrv.h"
#include "FileMgrGProt.h"
//suggested add
    #include "fs_type.h"
    #include "MMIDataType.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_mem_gprot.h"
    //#include "kal_public_api.h"
    #include "string.h"
    //#include "kal_general_types.h"
    #include "fs_errcode.h"
    #include "fs_func.h"
    #include "FileMgrSrvGProt.h"
    #include "MMI_features.h"
    #include "DebugInitDef_Int.h"
    #include "stdio.h"
    #include "mma_api.h"
    //#include "MMI_common_app_trc.h"
    #include "kal_trace.h"
    //#include "mmi_common_app_trc.h"
    #include "xml_def.h"
    #include "stdlib.h"
    #include "mma_struct.h"
    #include "UmSrvDefs.h"
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
static void srv_uc_xml_data_address_hdlr(
        U32 instance,
        U8 *utf8_addr,
        S32 addr_len,
        srv_uc_address_type_enum addr_type,
        srv_uc_address_group_type_enum addr_group_type);

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_usc2_to_utf8_to_base64
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_data_usc2_to_utf8_to_base64(FS_HANDLE fh, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *utf8_data;
    U32 utf8_data_len = mmi_ucs2strlen((S8*) data) * 3 + 1;
    S32 result;
    U32 utf8_data_actual_len = 0;
    U32 base64_data_len = 0;
    U8 *base64_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_data = OslMalloc(utf8_data_len);
    memset(utf8_data, 0, utf8_data_len);

    utf8_data_actual_len = mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, utf8_data_len, (kal_uint8*) data);

    base64_data_len = utf8_data_actual_len * 3;

    base64_data = OslMalloc(base64_data_len + 1);
    memset(base64_data, 0, base64_data_len + 1);

    applib_base64_encode((S8*) utf8_data, utf8_data_actual_len, (S8*) base64_data, base64_data_len);

    result = srv_uc_create_xml_data(fh, base64_data);

    OslMfree(base64_data);
    OslMfree(utf8_data);

    return result;
}
#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__
/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_addr_from_tag
 * DESCRIPTION
 *  Create the mms xml description file
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_addr_from_tag(U32 instance, FS_HANDLE fh)
{
  U8 *attr_list[3]; 
  S32 result;
  U8 *xml_addr_type = NULL;
  U8 arr[MMI_PHB_NUMBER_PLUS_LENGTH+1] = {0,};
  mmi_ucs2_to_asc((CHAR*)arr,(CHAR*)g_srv_uc_p[instance]->msg.owner);
  xml_addr_type = (U8*) SRV_UC_XML_ELEMENT_FROM;
  
  attr_list[0] = (U8*) SRV_UC_XML_ATTR_TYPE;
  attr_list[1] = (U8*) SRV_UC_XML_ATTR_POHNE_NUMBER;
  attr_list[2] = NULL;
   if ((result = srv_uc_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
      {
        return result;
      }
   if ((result = srv_uc_create_xml_data(fh,arr)) != FS_NO_ERROR)
       {
        return result;
       }
  if ((result = srv_uc_create_xml_element_end(fh, xml_addr_type)) != FS_NO_ERROR)
      {
       return result;
      }
  if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
      {
       return result;
      }
}
 void srv_uc_get_owner_num(U32 instance, U16* owner_num)
 {
  g_srv_uc_p[instance]->msg.owner=owner_num;
 }
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_mms_xml_description_file
 * DESCRIPTION
 *  Create the mms xml description file
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_mms_xml_description_file(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_path[SRV_UC_MAX_TEMP_FILE_LEN];
    FS_HANDLE fh;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_uc_update_object_id(instance);

    /* Make sure every object name is unique. */
    /* Need not for MMS V02 and rest are not supported now */
    srv_uc_replace_duplicate_object_file_name(instance);

    memset(file_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_MMS_XML_FILE_PATH(file_path, 0, instance);

#ifdef __MMI_MMS_POSTCARD__
    if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        MMI_ASSERT(g_srv_uc_p[instance]->msg.current_slide);
        if (g_srv_uc_p[instance]->msg.current_slide->txt.object != NULL)
        {
            g_srv_uc_p[instance]->msg.greeting_exist_flag = MMI_TRUE;
        }
        else
        {
            g_srv_uc_p[instance]->msg.greeting_exist_flag = MMI_FALSE;
        }
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
    /* Open the file to write, overwrite if already exists. */
    fh = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh > 0)
    {
        /* <mms> */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_MMS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* <header> */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_HEADER, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* To address */
        if (g_srv_uc_p[instance]->msg.to_num)
        {
            if ((result = srv_uc_create_xml_addr(instance, fh, SRV_UC_ADDRESS_GROUP_TYPE_TO)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_addr(instance, fh, SRV_UC_ADDRESS_GROUP_TYPE_CC)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_addr(instance, fh, SRV_UC_ADDRESS_GROUP_TYPE_BCC)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* subject */
        if (mmi_ucs2strlen((S8*) g_srv_uc_p[instance]->msg.subject))
        {
            if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_SUBJECT, NULL)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_data_usc2_to_utf8_to_base64(
                            fh,
                            (U8*) g_srv_uc_p[instance]->msg.subject)) !=
                FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_SUBJECT)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* Read Report */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_READ_REPORT, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, g_srv_uc_p[instance]->msg.read_report)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_READ_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Delivery Report */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_REPORT, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, g_srv_uc_p[instance]->msg.delivery_report)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_REPORT)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Priority */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_PRIORITY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, g_srv_uc_p[instance]->msg.priority)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_PRIORITY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Expiry time */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_EXPIRY, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(
                        fh,
                        srv_uc_convert_to_mms_expiry_time(g_srv_uc_p[instance]->msg.expiry_time))) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_EXPIRY)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Delivery time */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_TIME, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(
                        fh,
                        srv_uc_convert_to_mms_delivery_time(g_srv_uc_p[instance]->msg.delivery_time))) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_DELIVERY_TIME)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        /* Sender visibility */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_VISIBLE, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, !g_srv_uc_p[instance]->msg.hide_sender)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_VISIBLE)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
    #ifdef OMA13_CON_739_SUPPORT_TEMP_TEST_CODE
        /* msg class */
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_CLASS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, g_srv_uc_p[instance]->msg.msg_class)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_CLASS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
    #endif /* OMA13_CON_739_SUPPORT_TEMP_TEST_CODE */ 

/*initialize mms class as informational in lemei mms.*/
  if(g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
    {
        /* msg class informational */
        g_srv_uc_p[instance]->msg.msg_class=MMA_MSG_CLASS_INFORMATIONAL;
        if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_CLASS, NULL)) != FS_NO_ERROR)
        {
            FS_Close(fh);
           
			return result;
        }
        if ((result = srv_uc_create_xml_data_numeric_to_char(fh, g_srv_uc_p[instance]->msg.msg_class)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_CLASS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
   }
      
 /* </header> */
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_HEADER)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        if (((g_srv_uc_p[instance]->main.state != SRV_UC_STATE_FORWARD
              && g_srv_uc_p[instance]->main.mode != SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
             && (g_srv_uc_p[instance]->main.state != SRV_UC_STATE_SEND
            #ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
              && g_srv_uc_p[instance]->main.mode != SRV_UC_SEND_WITHOUT_EDIT_MODE
            #endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
                )) ||
            ((g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD ||
              g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND) &&
             (g_srv_uc_p[instance]->send_info.existed_msg_type != SRV_UC_MSG_TYPE_MMS_PREFER)))
        {
            /* <body> */
            {
                U16 str_len = SRV_UC_XML_STR_LEN;   /* size of slide_num, obj_num, layout, bg_color and fg_color */
                U16 attr_num = 7;                   /* size of arrt_list would be attr_num * 2 + 1 */
                U8 bg_color[SRV_UC_XML_STR_LEN];
                U8 fg_color[SRV_UC_XML_STR_LEN];
                U8 slide_num[SRV_UC_XML_STR_LEN];
                U8 obj_num[SRV_UC_XML_STR_LEN];
                U8 layout[SRV_UC_XML_STR_LEN];
                U8 txt_fit[SRV_UC_XML_STR_LEN];
                U8 img_fit[SRV_UC_XML_STR_LEN];
                U8 *attr_list[7 * 2 + 1];           /* 7= bg_color....img_fit */
                U8 i = 0;

                memset(bg_color, 0, str_len);
                sprintf((char*)bg_color, "0x%06x", g_srv_uc_p[instance]->msg.msg_body.bgColor);
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BGCOLOR;
                attr_list[i++] = bg_color;

                memset(fg_color, 0, str_len);
                sprintf((char*)fg_color, "0x%06x", g_srv_uc_p[instance]->msg.msg_body.fgColor);
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_FGCOLOR;
                attr_list[i++] = fg_color;

                /* If only attachments and one slide without any content, do not send slide info. */
                /* reference phone behavior */
                memset(slide_num, 0, str_len);
                if (srv_uc_check_only_attachment() && g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW)
                {
                    sprintf((char*)slide_num, "%d", 0);
                }
                else
                {
                    sprintf((char*)slide_num, "%d", g_srv_uc_p[instance]->msg.msg_body.slide_no);
                }
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_SLIDE_NUM;
                attr_list[i++] = slide_num;

                memset(obj_num, 0, str_len);
            #ifdef __MMI_MMS_POSTCARD__
                if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS &&
                    MMI_FALSE == g_srv_uc_p[instance]->msg.greeting_exist_flag)
                {
                    sprintf((char*)obj_num, "%d", g_srv_uc_p[instance]->msg.msg_body.obj_no + 1);
                }
                else
            #endif /* __MMI_MMS_POSTCARD__ */ 
                {
                    sprintf((char*)obj_num, "%d", g_srv_uc_p[instance]->msg.msg_body.obj_no);
                }
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_OBJ_NUM;
                attr_list[i++] = obj_num;

                memset(layout, 0, str_len);
                sprintf((char*)layout, "%d", srv_uc_convert_to_mms_layout_type(g_srv_uc_p[instance]->msg.msg_body.layout));
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_LAYOUT;
                attr_list[i++] = layout;
                memset(img_fit, 0, str_len);
                sprintf((char*)img_fit, "%d", MMA_REGION_FIT_MEET);    /* Always set to MEET for img, because current mms can not support other type */
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_IMGFIT;
                attr_list[i++] = img_fit;

                memset(txt_fit, 0, str_len);
                sprintf((char*)txt_fit, "%d", MMA_REGION_FIT_SCROLL);  /* Always set to SCROLL for text, because current mms can not support other type */
                attr_list[i++] = (U8*) SRV_UC_XML_ATTR_TXTFIT;
                attr_list[i++] = txt_fit;

                attr_list[i++] = NULL;

                MMI_ASSERT(i == (attr_num * 2 + 1));

                if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_BODY, attr_list)) != FS_NO_ERROR)
                {
                    FS_Close(fh);
                    return result;
                }
                if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
                {
                    FS_Close(fh);
                    return result;
                }
            }

            /* Slide */
            if (srv_uc_check_only_attachment() && g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW)
            {
                /* If only attachments and one slide without any content, do not send slide info. */
                /* reference phone behavior */
            }
            else
            {
                if (g_srv_uc_p[instance]->msg.msg_body.slide_no)
                {
                    mma_mms_slide_struct *slide = g_srv_uc_p[instance]->msg.msg_body.slides;
                    U16 i = 0;

                    while (i < g_srv_uc_p[instance]->msg.msg_body.slide_no)
                    {
                        MMI_ASSERT(slide);
                        /* in srv_uc_create_xml_slide : if there is no greeting, need to craete a new txt file -- for create slide xml */
                        if ((result = srv_uc_create_xml_slide(instance, fh, slide)) != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            return result;
                        }
                        slide = slide->next;
                        i++;
                    }
                }
            }

            /* Object */
            if (g_srv_uc_p[instance]->msg.msg_body.obj_no)
            {
                mma_mms_object_struct *object = g_srv_uc_p[instance]->msg.msg_body.objects;
                U16 i = 0;

            #ifdef __MMI_MMS_POSTCARD__
                applib_oppostcard_mem_func_struct *mem_func;

                mem_func = (*g_srv_uc_p[instance]->alloc) (sizeof(applib_oppostcard_mem_func_struct), g_srv_uc_p[instance]->user_data);
                mem_func->alloc_fn = g_srv_uc_p[instance]->alloc;
                mem_func->free_fn = g_srv_uc_p[instance]->free;
                mem_func->user_data = g_srv_uc_p[instance]->user_data;

                if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS   /* && 
                                                                                                           g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW */ )
                {
                    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.obj_no > 0); /* because at least one image in postcard */
					if(!(g_srv_uc_p[instance]->msg.msg_body.obj_no > 0))
					{
					MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
					}
                    /* if there is no greeting, need to craete a new txt file -- for create obj xml */
                    if (!g_srv_uc_p[instance]->msg.greeting_exist_flag)
                    {
                        U8 srv_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                        mma_mms_object_struct *greeting_object = NULL;

                        greeting_object = (*g_srv_uc_p[instance]->alloc) (sizeof(mma_mms_object_struct), g_srv_uc_p[instance]->user_data);
                        MMI_ASSERT(greeting_object);
                        /* fill file path and file name before calling srv_uc_fill_obj_info_for_postcard_without_greeting() */
                        memset(srv_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                        SRV_UC_MAKE_TEXT_FILE_PATH(srv_uc_text_path, 1, instance);
                        greeting_object->file_path_ucs = (U16*) srv_uc_text_path;
                        greeting_object->file_name_ucs = (U16*) srv_uc_text_path;

                        result = srv_uc_fill_obj_info_for_postcard_without_greeting(instance, greeting_object);
                        if (result != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                            (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
                            return result;
                        }
                        if ((result = srv_uc_create_xml_object(fh, greeting_object)) != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                            (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
                            return result;
                        }

                        (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                    }
                }

            #endif /* __MMI_MMS_POSTCARD__ */ 
                while (i < g_srv_uc_p[instance]->msg.msg_body.obj_no)
                {
                    MMI_ASSERT(object);
                    /* for postcard, add recipients info to txt file */
                #ifdef __MMI_MMS_POSTCARD__
                    if ((g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS) &&
                        (object->type ==
                         SRV_UC_OBJECT_TYPE_TEXT)
                        /* && (g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW) */ )
                    {
                        srv_postcard_recipient_struct wanted_recipient_list;

                        MMI_ASSERT(g_srv_uc_p[instance]->msg.greeting_exist_flag == MMI_TRUE);
						if(!(g_srv_uc_p[instance]->msg.greeting_exist_flag == MMI_TRUE))
						{
						MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
						}
                        if (g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_SEND_IN_BACKGROUND &&
                            g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_SAVE &&
                            g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_SAVE_IN_BACKGROUND &&
                            g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW)
                        {
                            MMI_ASSERT(0);
							MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
						}
                        /* Should send a mms for each recipient */
                        if (g_srv_uc_p[instance]->send_info.action == SRV_UC_ACTION_SEND_IN_BACKGROUND)
                        {
                            srv_postcard_fill_recipient_info(
                                instance,
                                &wanted_recipient_list,
                                (U8) g_srv_uc_p[instance]->send_info.curr_send_number);
                            result = applib_oppostcard_encode_text_content(
                                        mem_func,
                                        object->file_path_ucs,
                                        (const kal_char*)g_srv_uc_p[instance]->main.text_buffer,
                                        &wanted_recipient_list);
							if (result == MMI_FALSE)
							{
								FS_Close(fh);
								(*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
								return FS_DISK_FULL;
							}
                        }
                        else
                        {
                           result = applib_oppostcard_encode_text_content(
                                        mem_func,
                                        object->file_path_ucs,
                                        (const kal_char*)g_srv_uc_p[instance]->main.text_buffer,
                                        g_srv_uc_p[instance]->msg.postcard_recipient_info.recipient_head);
						   if (result == MMI_FALSE)
							{
								FS_Close(fh);
								(*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
								return FS_DISK_FULL;
							}

                        }
                        object->size = applib_get_file_size((kal_wchar*) object->file_path_ucs);
                    }
                #endif /* __MMI_MMS_POSTCARD__ */ 
                    if ((result = srv_uc_create_xml_object(fh, object)) != FS_NO_ERROR)
                    {
                        FS_Close(fh);
                        return result;
                    }
                    object = object->next;
                    i++;
                }
            #ifdef __MMI_MMS_POSTCARD__
                (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
            #endif 
            }
            /* it possible that the case happens: no object, but user press end key, Uc will save postcard in background, 
               still need to create a empty postcard text object */
        #ifdef __MMI_MMS_POSTCARD__
            else
            {

                applib_oppostcard_mem_func_struct *mem_func;

                mem_func = (*g_srv_uc_p[instance]->alloc) (sizeof(applib_oppostcard_mem_func_struct), g_srv_uc_p[instance]->user_data);
                mem_func->alloc_fn = g_srv_uc_p[instance]->alloc;
                mem_func->free_fn = g_srv_uc_p[instance]->free;
                mem_func->user_data = g_srv_uc_p[instance]->user_data;
                /* create a new text file for postcard */
                if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS   /* && 
                                                                                                           g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_PREVIEW */ )
                {

                    /* if there is no greeting, need to craete a new txt file -- for create obj xml */
                    if (!g_srv_uc_p[instance]->msg.greeting_exist_flag)
                    {
                        U8 srv_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                        mma_mms_object_struct *greeting_object = NULL;

                        greeting_object = (*g_srv_uc_p[instance]->alloc) (sizeof(mma_mms_object_struct), g_srv_uc_p[instance]->user_data);
                        MMI_ASSERT(greeting_object);
                        /* fill file path and file name before calling srv_uc_fill_obj_info_for_postcard_without_greeting() */
                        memset(srv_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                        SRV_UC_MAKE_TEXT_FILE_PATH(srv_uc_text_path, 1, instance);
                        greeting_object->file_path_ucs = (U16*) srv_uc_text_path;
                        greeting_object->file_name_ucs = (U16*) srv_uc_text_path;

                        result = srv_uc_fill_obj_info_for_postcard_without_greeting(instance, greeting_object);
                        if (result != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                            (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
                            return result;
                        }
                        if ((result = srv_uc_create_xml_object(fh, greeting_object)) != FS_NO_ERROR)
                        {
                            FS_Close(fh);
                            (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                            (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);
                            return result;
                        }

                        (*g_srv_uc_p[instance]->free) (greeting_object, g_srv_uc_p[instance]->user_data);
                    }
                }

                (*g_srv_uc_p[instance]->free) (mem_func, g_srv_uc_p[instance]->user_data);

            }
        #endif /* __MMI_MMS_POSTCARD__ */ 

            /* </body> */
            if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_BODY)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
            if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                FS_Close(fh);
                return result;
            }
        }

        /* </mms> */
        if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_MMS)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }
        if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
        {
            FS_Close(fh);
            return result;
        }

        FS_Close(fh);
    }
    else
    {
        result = (S32) fh;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CREATE_MMS_DESC_FILE_FAIL_P1, result);
    }
	if(g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
	{
     g_srv_uc_p[instance]->msg_type.MMS_edit_mode = SRV_UC_MMS_EDIT_MODE_NORMAL_MMS;
	}
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_start
 * DESCRIPTION
 *  Create the xml start element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_element_start(FS_HANDLE fh, U8 *element_name, U8 **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str = OslMalloc(SRV_UC_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str, 0, SRV_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s", XML_TAG_ELEMENT_START, element_name);
    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)temp_str + offset, " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str + offset), "%s", XML_TAG_GENERAL_END);
    MMI_ASSERT(offset < SRV_UC_XML_TEMP_STR_LEN);
	if(!(offset < SRV_UC_XML_TEMP_STR_LEN))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    result = FS_Write(fh, temp_str, offset, &write_len);
    OslMfree(temp_str);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_end
 * DESCRIPTION
 *  Create the xml end element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_element_end(FS_HANDLE fh, U8 *element_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str = OslMalloc(SRV_UC_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str, 0, SRV_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s%s", XML_TAG_ELEMENT_END, element_name, XML_TAG_GENERAL_END);

    MMI_ASSERT(offset < SRV_UC_XML_TEMP_STR_LEN);
	if(!(offset < SRV_UC_XML_TEMP_STR_LEN))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}

    result = FS_Write(fh, temp_str, offset, &write_len);

    OslMfree(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_new_line
 * DESCRIPTION
 *  Insert new line
 * PARAMETERS
 *  fh      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_new_line(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str = OslMalloc(SRV_UC_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str, 0, SRV_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "\n");

    result = FS_Write(fh, temp_str, offset, &write_len);

    OslMfree(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_data(FS_HANDLE fh, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = strlen((char*)data);

    result = FS_Write(fh, data, offset, &write_len);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_usc2_to_utf8
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh          [IN]        
 *  data        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_data_usc2_to_utf8(FS_HANDLE fh, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *utf8_data;
    U32 utf8_data_len = mmi_ucs2strlen((S8*) data) * 3 + 1;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_data = OslMalloc(utf8_data_len);
    memset(utf8_data, 0, utf8_data_len);

    mmi_chset_ucs2_to_utf8_string((kal_uint8*) utf8_data, utf8_data_len, (kal_uint8*) data);

    result = srv_uc_create_xml_data(fh, utf8_data);

    OslMfree(utf8_data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_data_numeric_to_char
 * DESCRIPTION
 *  Add numeric data
 * PARAMETERS
 *  fh          [IN]        
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_data_numeric_to_char(FS_HANDLE fh, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data;
    U32 data_len = 10;
    S32 result;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = OslMalloc(data_len);
    memset(data, 0, data_len);

    offset += sprintf((char*)data, "%d", value);

    result = srv_uc_create_xml_data(fh, data);

    OslMfree(data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_addr
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  instance        [IN]        
 *  fh              [IN]        
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_addr(U32 instance, FS_HANDLE fh, srv_uc_address_group_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 i = 0;
    srv_uc_addr_struct *addr = NULL;
    U8 *attr_list[3];
    U8 *xml_addr_type = NULL;
    U32 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr = g_srv_uc_p[instance]->msg.to_head;
    total = g_srv_uc_p[instance]->msg.to_num;
    switch (type)
    {
        case SRV_UC_ADDRESS_GROUP_TYPE_TO:
        {
            xml_addr_type = (U8*) SRV_UC_XML_ELEMENT_TO;
        }
            break;

        case SRV_UC_ADDRESS_GROUP_TYPE_CC:
        {
            xml_addr_type = (U8*) SRV_UC_XML_ELEMENT_CC;
        }
            break;

        case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            xml_addr_type = (U8*) SRV_UC_XML_ELEMENT_BCC;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    attr_list[0] = (U8*) SRV_UC_XML_ATTR_TYPE;
    attr_list[2] = NULL;
    while (i < total)
    {
        MMI_ASSERT(addr);

        if (addr->group == type)
        {
            if (addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
            {
                attr_list[1] = (U8*) SRV_UC_XML_ATTR_POHNE_NUMBER;
                if ((result = srv_uc_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
                {
                    return result;
                }

                if ((result = srv_uc_create_xml_data(fh, addr->addr)) != FS_NO_ERROR)
                {
                    return result;
                }
            }
            else if (addr->type == SRV_UC_ADDRESS_TYPE_EMAIL)
            {
                attr_list[1] = (U8*) SRV_UC_XML_ATTR_EMAIL_ADDR;

                if ((result = srv_uc_create_xml_element_start(fh, xml_addr_type, attr_list)) != FS_NO_ERROR)
                {
                    return result;
                }
                if ((result = srv_uc_create_xml_data_usc2_to_utf8(fh, addr->addr)) != FS_NO_ERROR)
                {
                    return result;
                }
            }
            else if (addr->type == SRV_UC_ADDRESS_TYPE_IP)
            {
                /* Skip do nothing */
            }
            else
            {
                MMI_ASSERT(0);
            }

            if ((result = srv_uc_create_xml_element_end(fh, xml_addr_type)) != FS_NO_ERROR)
            {
                return result;
            }
            if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
            {
                return result;
            }
        }

        addr = addr->next;
        i++;
    }
    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_slide
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  instance        [IN]        
 *  fh              [IN]        
 *  slide           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_slide(U32 instance, FS_HANDLE fh, mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 str_len = SRV_UC_XML_STR_LEN;   /* size of index and duration */
    U16 attr_num = 2;                   /* size of attr_list would be attr_num * 2 + 1 */
    U8 index[SRV_UC_XML_STR_LEN];
    U8 duration[SRV_UC_XML_STR_LEN];
    U8 *attr_list[2 * 2 + 1];
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide);

    memset(index, 0, str_len);
    sprintf((char*)index, "%d", (slide->slide_num));
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_INDEX;
    attr_list[j++] = index;

    memset(duration, 0, str_len);
    sprintf((char*)duration, "%d", slide->duration);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_DURATION;
    attr_list[j++] = duration;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));
	if(!(j == (attr_num * 2 + 1)))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_SLIDE, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }
    /* text */
    if (slide->txt.object)
    {
        if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, NULL, SRV_UC_OBJECT_TYPE_TEXT)) != FS_NO_ERROR)
        {
            return result;
        }
    }
#ifdef __MMI_MMS_POSTCARD__
    else if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        MMI_ASSERT(!g_srv_uc_p[instance]->msg.greeting_exist_flag);
        /* if there is no greeting, need to craete a new txt file -- for create obj xml */
        if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, NULL, SRV_UC_OBJECT_TYPE_TEXT)) != FS_NO_ERROR)
        {
            return result;
        }
    }

#endif /* __MMI_MMS_POSTCARD__ */ 

    /* image */
    if (slide->img.object)
    {
        if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, NULL, SRV_UC_OBJECT_TYPE_IMAGE)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* audio */
    if (slide->aud.object)
    {
        if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, NULL, SRV_UC_OBJECT_TYPE_AUDIO)) != FS_NO_ERROR)
        {
            return result;
        }
    }
    /* video */
    if (slide->vid.object)
    {
        if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, NULL, SRV_UC_OBJECT_TYPE_VIDEO)) != FS_NO_ERROR)
        {
            return result;
        }
    }

    /* ref */

    {
        mma_mms_slide_ref_object_struct *cur_ref = slide->ref_items;

        while (cur_ref)
        {
            if ((result = srv_uc_create_xml_slide_object(instance, fh, slide, cur_ref, SRV_UC_OBJECT_TYPE_REF)) != FS_NO_ERROR)
            {
                return result;
            }
            cur_ref = cur_ref->next;
        }
    }

    if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_SLIDE)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_slide_object
 * DESCRIPTION
 *  create xml file for object (ref_obj_info is used only when obj_type = SRV_UC_OBJECT_TYPE_REF)
 * PARAMETERS
 *  instance            [IN]        
 *  fh                  [IN]        
 *  slide               [?]         
 *  ref_obj_info        [?]         
 *  obj_type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_slide_object(
        U32 instance,
        FS_HANDLE fh,
        mma_mms_slide_struct *slide,
        mma_mms_slide_ref_object_struct *ref_obj_info,
        srv_uc_object_type obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 bg_color = 0;
    U32 fg_color = 0;
    U32 begin = 0;
    U32 end = 0;
    U16 str_len = SRV_UC_XML_STR_LEN;   /* size of id_str , start_str, end_str, bg_color_str and fg_color_str */
    U16 attr_num = 5;                   /* size of attr_list would be attr_num * 2 + 1 */
    U32 id = 0;
    U8 bg_color_str[SRV_UC_XML_STR_LEN];
    U8 fg_color_str[SRV_UC_XML_STR_LEN];
    U8 id_str[SRV_UC_XML_STR_LEN];
    U8 start_str[SRV_UC_XML_STR_LEN];
    U8 end_str[SRV_UC_XML_STR_LEN];
    U8 *attr_list[5 * 2 + 1];
    U8 i = 0;
    U8 *obj_xml_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide);

    switch (obj_type)
    {
        case SRV_UC_OBJECT_TYPE_TEXT:
        {
        #ifdef __MMI_MMS_POSTCARD__
            if ((g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS) &&
                (g_srv_uc_p[instance]->msg.greeting_exist_flag == MMI_FALSE))
            {
                /* if there is no greeting */
                fg_color = g_srv_uc_p[instance]->msg.msg_body.fgColor;
                bg_color = g_srv_uc_p[instance]->msg.msg_body.bgColor;
                /* because before create msg, already assgin each obj's id-- srv_uc_update_object_id
                   Here, we have to create a new obj for postcard's recipient when there is not greeting */
                id = g_srv_uc_p[instance]->msg.msg_body.obj_no + 1;
                begin = 0;
                end = slide->duration;
            }
            else
        #endif /* __MMI_MMS_POSTCARD__ */ 
            {
                MMI_ASSERT(slide->txt.object);
	#ifdef __MMI_MMS_2__
                /* Because currently, not support setting text bgcolor or fgcolor, therefore if glbal bgcolor exist, will use it */
                if ((slide->txt.fg_color == SRV_UC_DEFAULT_FG_COLOR) &&
                    (g_srv_uc_p[instance]->msg.msg_body.fgColor != SRV_UC_DEFAULT_FG_COLOR))
                {
                    fg_color = g_srv_uc_p[instance]->msg.msg_body.fgColor;
                }
                else
                {
                    fg_color = slide->txt.fg_color;
                }
                if ((slide->txt.bg_color == SRV_UC_DEFAULT_BG_COLOR) &&
                    (g_srv_uc_p[instance]->msg.msg_body.bgColor != SRV_UC_DEFAULT_BG_COLOR))
                {
                    bg_color = g_srv_uc_p[instance]->msg.msg_body.bgColor;
                }
                else
                {
                    bg_color = slide->txt.bg_color;
                }
	#else
                fg_color = g_srv_uc_p[instance]->msg.msg_body.fgColor;
                bg_color = g_srv_uc_p[instance]->msg.msg_body.bgColor;
	#endif

                id = slide->txt.object->id;

                if ((SRV_UC_INVALID_VALUE == slide->txt.begin) || (SRV_UC_INVALID_VALUE == slide->txt.end))
                {
                    begin = 0;
                    end = slide->duration;
                }
                else
                {
                    begin = slide->txt.begin;
                    end = slide->txt.end;
                }
            }
            obj_xml_type = (U8*) SRV_UC_XML_ELEMENT_TEXT;
        }
            break;

        case SRV_UC_OBJECT_TYPE_IMAGE:
        {
            MMI_ASSERT(slide->img.object);
            id = slide->img.object->id;
            if ((SRV_UC_INVALID_VALUE == slide->img.begin) || (SRV_UC_INVALID_VALUE == slide->img.end))
            {
                begin = 0;
                end = slide->duration;
            }
            else
            {
                begin = slide->img.begin;
                end = slide->img.end;
            }
            obj_xml_type = (U8*) SRV_UC_XML_ELEMENT_IMAGE;
        }
            break;

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            MMI_ASSERT(slide->aud.object);
            id = slide->aud.object->id;
            if ((SRV_UC_INVALID_VALUE == slide->aud.begin) || (SRV_UC_INVALID_VALUE == slide->aud.end))
            {
                begin = 0;
                end = slide->duration;
            }
            else
            {
                begin = slide->aud.begin;
                end = slide->aud.end;
            }
            obj_xml_type = (U8*) SRV_UC_XML_ELEMENT_AUDIO;
        }
            break;

        case SRV_UC_OBJECT_TYPE_VIDEO:
        {
            MMI_ASSERT(slide->vid.object);
            id = slide->vid.object->id;
            if ((SRV_UC_INVALID_VALUE == slide->vid.begin) || (SRV_UC_INVALID_VALUE == slide->vid.end))
            {
                begin = 0;
                end = slide->duration;
            }
            else
            {
                begin = slide->vid.begin;
                end = slide->vid.end;
            }

            obj_xml_type = (U8*) SRV_UC_XML_ELEMENT_VIDEO;
        }
            break;

        case SRV_UC_OBJECT_TYPE_REF:
        {
            MMI_ASSERT(ref_obj_info);
            MMI_ASSERT(ref_obj_info->object);

            id = ref_obj_info->object->id;
            if ((SRV_UC_INVALID_VALUE == ref_obj_info->begin) || (SRV_UC_INVALID_VALUE == ref_obj_info->end))
            {
                begin = 0;
                end = slide->duration;
            }
            else
            {
                begin = ref_obj_info->begin;
                end = ref_obj_info->end;
            }

            obj_xml_type = (U8*) SRV_UC_XML_ELEMENT_REF;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    if (obj_type == SRV_UC_OBJECT_TYPE_TEXT)
    {
        memset(bg_color_str, 0, str_len);
        sprintf((char*)bg_color_str, "0x%06x", bg_color);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BGCOLOR;
        attr_list[i++] = bg_color_str;

        memset(fg_color_str, 0, str_len);
        sprintf((char*)fg_color_str, "0x%06x", fg_color);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_FGCOLOR;
        attr_list[i++] = fg_color_str;
    }

    memset(id_str, 0, str_len);
    sprintf((char*)id_str, "%d", id);
    attr_list[i++] = (U8*) SRV_UC_XML_ATTR_ID;
    attr_list[i++] = id_str;

    if (begin != SRV_UC_INVALID_VALUE && end != SRV_UC_INVALID_VALUE)
    {
        memset(start_str, 0, str_len);
        sprintf((char*)start_str, "%d", begin);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_BEGIN;
        attr_list[i++] = start_str;

        memset(end_str, 0, str_len);
        sprintf((char*)end_str, "%d", end);
        attr_list[i++] = (U8*) SRV_UC_XML_ATTR_END;
        attr_list[i++] = end_str;
    }

    attr_list[i] = NULL;

    MMI_ASSERT(i <= (attr_num * 2 + 1));
	if(!(i <= (attr_num * 2 + 1)))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    if ((result = srv_uc_create_xml_element_single(fh, obj_xml_type, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_element_single
 * DESCRIPTION
 *  Create the xml single element
 * PARAMETERS
 *  fh                  [IN]        
 *  element_name        [?]         
 *  attr_list           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_element_single(FS_HANDLE fh, U8 *element_name, U8 **attr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str = OslMalloc(SRV_UC_XML_TEMP_STR_LEN);
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;
    U32 i = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_str, 0, SRV_UC_XML_TEMP_STR_LEN);
    offset += sprintf((char*)temp_str, "%s%s", XML_TAG_ELEMENT_START, element_name);

    if (attr_list)
    {
        while (attr_list[i])
        {
            offset += sprintf((char*)(temp_str + offset), " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }

    offset += sprintf((char*)(temp_str + offset), "%s", XML_TAG_SINGLE_END);

    MMI_ASSERT(offset < SRV_UC_XML_TEMP_STR_LEN);
	if(!(offset < SRV_UC_XML_TEMP_STR_LEN))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    result = FS_Write(fh, temp_str, offset, &write_len);

    OslMfree(temp_str);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create_xml_object
 * DESCRIPTION
 *  Add data
 * PARAMETERS
 *  fh      [IN]        
 *  obj     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_create_xml_object(FS_HANDLE fh, mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 str_len = SRV_UC_XML_STR_LEN;   /* size of id, attach, vf, and drm, size, offset */
    U16 attr_num = 7;                   /* size of attr_list would be attr_num * 2 + 1 */
    U8 id[SRV_UC_XML_STR_LEN];
    U8 attach[SRV_UC_XML_STR_LEN];
    U8 vf[SRV_UC_XML_STR_LEN];
    U8 drm[SRV_UC_XML_STR_LEN];
    U8 size[SRV_UC_XML_STR_LEN];
    U8 offset[SRV_UC_XML_STR_LEN];
    U8 encoding[SRV_UC_XML_STR_LEN];
    U8 *attr_list[7 * 2 + 1];           /* 7:id,attach, vf,drm,size,offset,encoding */
    U8 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    memset(id, 0, str_len);
    sprintf((char*)id, "%d", obj->id);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_ID;
    attr_list[j++] = id;

    memset(attach, 0, str_len);
    if (obj->type == SRV_UC_OBJECT_TYPE_ATTACHMENT)
    {
        sprintf((char*)attach, "%d", 1);
    }
    else
    {
        sprintf((char*)attach, "%d", 0);
    }
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_ATTACH;
    attr_list[j++] = attach;

    memset(vf, 0, str_len);
    sprintf((char*)vf, "%d", obj->is_virtual_file);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_VIRTUAL_FILE;
    attr_list[j++] = vf;

    memset(drm, 0, str_len);
    sprintf((char*)drm, "%d", obj->drm_type);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_DRM;
    attr_list[j++] = drm;

    memset(size, 0, str_len);
    sprintf((char*)size, "%d", obj->size);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_SIZE;
    attr_list[j++] = size;

    memset(offset, 0, str_len);
    sprintf((char*)offset, "%d", obj->offset);
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_OFFSET;
    attr_list[j++] = offset;

    memset(encoding, 0, str_len);
    if (SRV_UC_OBJECT_TYPE_TEXT == obj->type)
    {
        sprintf((char*)encoding, "%d", MMA_CHARSET_UTF8);
    }
    else
    {
        sprintf((char*)encoding, "%d", obj->encoding);
    }
    attr_list[j++] = (U8*) SRV_UC_XML_ATTR_ENCODING;
    attr_list[j++] = encoding;

    attr_list[j++] = NULL;

    MMI_ASSERT(j == (attr_num * 2 + 1));
	if(!(j == (attr_num * 2 + 1)))
	{
	MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
	}
    /* <obj> */
    if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_OBJECT, attr_list)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* name */
    if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_NAME, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_data(fh, (U8*) obj->file_name)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_NAME)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* file path */
    if ((result = srv_uc_create_xml_element_start(fh, (U8*) SRV_UC_XML_ELEMENT_FILE_PATH, NULL)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_data_usc2_to_utf8(fh, (U8*) obj->file_path_ucs)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_FILE_PATH)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    /* </obj> */
    if ((result = srv_uc_create_xml_element_end(fh, (U8*) SRV_UC_XML_ELEMENT_OBJECT)) != FS_NO_ERROR)
    {
        return result;
    }
    if ((result = srv_uc_create_xml_new_line(fh)) != FS_NO_ERROR)
    {
        return result;
    }

    return FS_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_xml_start_element_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  instance        [IN]        
 *  data            [?]         
 *  el              [IN]        
 *  attr            [IN]        
 *  error           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_xml_start_element_hdlr(U32 instance, void *data, const char *el, const char **attr, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!strcmp(SRV_UC_XML_ELEMENT_TO, el)) ||
        (!strcmp(SRV_UC_XML_ELEMENT_CC, el)) ||
        (!strcmp(SRV_UC_XML_ELEMENT_BCC, el)) || (!strcmp(SRV_UC_XML_ELEMENT_FROM, el)))
    {
        if (!strcmp(SRV_UC_XML_ATTR_TYPE, attr[0]))
        {
            if (!strcmp(SRV_UC_XML_ATTR_POHNE_NUMBER, attr[1]))
            {
                g_srv_uc_p[instance]->xml.addr_type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
            else if (!strcmp(SRV_UC_XML_ATTR_EMAIL_ADDR, attr[1]))
            {
                g_srv_uc_p[instance]->xml.addr_type = SRV_UC_ADDRESS_TYPE_EMAIL;
            }
            else if (!strcmp(SRV_UC_XML_ATTR_IP_ADDR, attr[1]))
            {
                g_srv_uc_p[instance]->xml.addr_type = SRV_UC_ADDRESS_TYPE_IP;
            }
            else
            {
                MMI_ASSERT(0);
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_START_ELEMENT_HDLR_ADDR_ERR);

                g_srv_uc_p[instance]->xml.addr_type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_BODY, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_BGCOLOR, attr[i]))
            {
                g_srv_uc_p[instance]->msg.msg_body.bgColor = srv_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_FGCOLOR, attr[i]))
            {
                g_srv_uc_p[instance]->msg.msg_body.fgColor = srv_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_SLIDE_NUM, attr[i]))
            {
                /* updated in srv_uc_insert_slide_by_number */
                /* g_srv_uc_p[instance]->msg.msg_body.slide_no = atoi((S8*) attr[i + 1]); */
            }
            else if (!strcmp(SRV_UC_XML_ATTR_OBJ_NUM, attr[i]))
            {
                /* updated in srv_uc_insert_object_to_list_tail() */
                /* g_srv_uc_p[instance]->msg.msg_body.obj_no = atoi((S8*) attr[i + 1]); */
            }
            else if (!strcmp(SRV_UC_XML_ATTR_LAYOUT, attr[i]))
            {
                g_srv_uc_p[instance]->msg.msg_body.layout = srv_uc_convert_mms_layout_type_to_uc((U8) atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_IMGFIT, attr[i]))
            {
                g_srv_uc_p[instance]->msg.msg_body.image_fit = srv_uc_convert_mms_region_fit_enum_to_uc((U8) atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_TXTFIT, attr[i]))
            {
                g_srv_uc_p[instance]->msg.msg_body.text_fit = srv_uc_convert_mms_region_fit_enum_to_uc((U8) atoi((S8*) attr[i + 1]));
            }

        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_SLIDE, el))
    {
        U8 slide_number = 0;
        U32 duration = g_srv_uc_p[instance]->mms_info.sliding_time.value;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_INDEX, attr[i]))
            {
                slide_number = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_DURATION, attr[i]))
            {
                duration = atoi((S8*) attr[i + 1]);
            }
        }

        if (slide_number)
        {
            g_srv_uc_p[instance]->xml.slide = srv_uc_insert_slide_by_number(instance, slide_number);

            if (g_srv_uc_p[instance]->xml.slide)
            {
                MMI_ASSERT(g_srv_uc_p[instance]->xml.slide->slide_num == slide_number);
				if(!(g_srv_uc_p[instance]->xml.slide->slide_num == slide_number))
				{
				MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
				}
                /* Check slide duration boundary */
                if ((duration > g_srv_uc_p[instance]->mms_info.sliding_time.max) &&
                    (!g_srv_uc_p[instance]->mms_info.best_page_duration))
                {
                    duration = g_srv_uc_p[instance]->mms_info.sliding_time.max;
                }
                /* keep the duration value as we received --for case: min=1, duration =0 */
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* 0 */ 
                g_srv_uc_p[instance]->xml.slide->duration = duration;
            }
            else
            {
                MMI_ASSERT(0);
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_START_ELEMENT_HDLR_SLIDE_ERR);
            }
        }
        else
        {
            MMI_ASSERT(0);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_START_ELEMENT_HDLR_SLIDE_NUM_ERR);
        }
    }
	#ifdef __MMI_MMS_2__
    else if (!strcmp(SRV_UC_XML_ELEMENT_TEXT, el))
    {
        g_srv_uc_p[instance]->xml.slide->txt.bg_color = SRV_UC_DEFAULT_BG_COLOR;
        g_srv_uc_p[instance]->xml.slide->txt.fg_color = SRV_UC_DEFAULT_FG_COLOR;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->txt.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_BEGIN, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->txt.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_END, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->txt.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_BGCOLOR, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->txt.bg_color = srv_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_FGCOLOR, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->txt.fg_color = srv_uc_convert_ascii_hex_to_dec((U8*) attr[i + 1]);
            }
        }
    }
	#endif
    else if (!strcmp(SRV_UC_XML_ELEMENT_IMAGE, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->img.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_BEGIN, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->img.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_END, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->img.end = atoi((S8*) attr[i + 1]);
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_AUDIO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->aud.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_BEGIN, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->aud.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_END, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->aud.end = atoi((S8*) attr[i + 1]);
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_VIDEO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->vid.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_BEGIN, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->vid.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(SRV_UC_XML_ATTR_END, attr[i]))
            {
                g_srv_uc_p[instance]->xml.slide->vid.end = atoi((S8*) attr[i + 1]);
            }
        }
    }
#ifdef __MMI_MMS_2__
    else if (!strcmp(SRV_UC_XML_ELEMENT_REF, el))
    {
        U32 ref_id = SRV_UC_INVALID_VALUE;
        U32 ref_begin = 0;
        U32 ref_end = 0;
        mma_mms_slide_ref_object_struct *new_ref_obj_info;

        if (g_srv_uc_p[instance]->msg.msg_body.total_attach_no < SRV_UC_MAX_ATTACHMENT_NUM)
        {
            for (i = 0; attr[i]; i = i + 2)
            {
                if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
                {
                    ref_id = (atoi((S8*) attr[i + 1]));
                }
                else if (!strcmp(SRV_UC_XML_ATTR_BEGIN, attr[i]))
                {
                    ref_begin = atoi((S8*) attr[i + 1]);
                }
                else if (!strcmp(SRV_UC_XML_ATTR_END, attr[i]))
                {
                    ref_end = atoi((S8*) attr[i + 1]);
                }
            }
            MMI_ASSERT(ref_id != SRV_UC_INVALID_VALUE);
            MMI_ASSERT(g_srv_uc_p[instance]->xml.slide);
			if((!(ref_id != SRV_UC_INVALID_VALUE)) || (!(g_srv_uc_p[instance]->xml.slide)))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}
            new_ref_obj_info = srv_uc_insert_ref_obj_info_to_tail(
                                instance,
                                g_srv_uc_p[instance]->xml.slide,
                                ref_id,
                                ref_begin,
                                ref_end);
            MMI_ASSERT(new_ref_obj_info);
			if(!(new_ref_obj_info))
			{
			MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
			}
        }   /* only keep SRV_UC_MAX_ATTACHMENT_NUM ref object */
    }
#endif

    else if (!strcmp(SRV_UC_XML_ELEMENT_OBJECT, el))
    {
        g_srv_uc_p[instance]->xml.object = srv_uc_insert_object_to_list_tail(instance);

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(SRV_UC_XML_ATTR_ID, attr[i]))
            {
                g_srv_uc_p[instance]->xml.object->id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(SRV_UC_XML_ATTR_ATTACH, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
                }
            }
            else if (!strcmp(SRV_UC_XML_ATTR_VIRTUAL_FILE, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->is_virtual_file = MMI_TRUE;
                }
                else
                {
                    g_srv_uc_p[instance]->xml.object->is_virtual_file = MMI_FALSE;
                }
            }
            else if (!strcmp(SRV_UC_XML_ATTR_DRM, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->drm_type = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(SRV_UC_XML_ATTR_SIZE, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->size = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(SRV_UC_XML_ATTR_OFFSET, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->offset = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(SRV_UC_XML_ATTR_ENCODING, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_srv_uc_p[instance]->xml.object->encoding = (atoi((S8*) attr[i + 1]));
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_xml_end_element_hdlr
 * DESCRIPTION
 *  end element handler
 * PARAMETERS
 *  instance        [IN]        
 *  data            [?]         
 *  el              [IN]        
 *  error           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_xml_end_element_hdlr(U32 instance, void *data, const char *el, S32 error)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(SRV_UC_XML_ELEMENT_OBJECT, el))
    {
        if (g_srv_uc_p[instance]->xml.object->type == SRV_UC_OBJECT_TYPE_ATTACHMENT)
        {
            if (g_srv_uc_p[instance]->msg.msg_body.total_attach_no < SRV_UC_MAX_ATTACHMENT_NUM)
            {
                mma_mms_attachment_info_struct *att;

                att = srv_uc_insert_attachment(instance);
                srv_uc_insert_object_to_attachment(g_srv_uc_p[instance]->xml.object, att);
            }
            /* because mms will remove attachemnt objs if num > SRV_UC_MAX_ATTACHMENT_NUM
               but when enable ref feature, UC will treat ref as attachment, but mms still treat them differently */
            else
            {
                srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->xml.object);
            }
        }
    }
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_xml_data_hdlr
 * DESCRIPTION
 *  Start element handler
 * PARAMETERS
 *  instance        [IN]        
 *  data            [?]         
 *  el              [IN]        
 *  value           [IN]        
 *  len             [IN]        
 *  error           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_xml_data_hdlr(U32 instance, void *data, const char *el, const char *value, int len, S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(SRV_UC_XML_ELEMENT_TO, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD
            || g_srv_uc_p[instance]->main.mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            /* Do nothing */
        }
        else
        {
            srv_uc_xml_data_address_hdlr(
                instance,
                (U8*) value,
                len,
                g_srv_uc_p[instance]->xml.addr_type,
                SRV_UC_ADDRESS_GROUP_TYPE_TO);
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_CC, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD ||
            g_srv_uc_p[instance]->main.mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            /* Do nothing */
        }
        else
        {
            srv_uc_xml_data_address_hdlr(
                instance,
                (U8*) value,
                len,
                g_srv_uc_p[instance]->xml.addr_type,
                SRV_UC_ADDRESS_GROUP_TYPE_CC);
        }

    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_BCC, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD
            || g_srv_uc_p[instance]->main.mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            /* Do nothing */
        }
        else
        {
            srv_uc_xml_data_address_hdlr(
                instance,
                (U8*) value,
                len,
                g_srv_uc_p[instance]->xml.addr_type,
                SRV_UC_ADDRESS_GROUP_TYPE_BCC);
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_FROM, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL)
        {
            srv_uc_xml_data_address_hdlr(
                instance,
                (U8*) value,
                len,
                g_srv_uc_p[instance]->xml.addr_type,
                SRV_UC_ADDRESS_GROUP_TYPE_TO);
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_SUBJECT, el))
    {
        U8 *utf8_data = NULL;
        U32 base64_len = strlen((S8*) value);
        U32 utf8_len = 0;

        memset(g_srv_uc_p[instance]->msg.subject, 0, sizeof(g_srv_uc_p[instance]->msg.subject));

        utf8_len = applib_base64_decode_len((S8*) value, base64_len);
        utf8_data = OslMalloc(utf8_len + 1);
        memset(utf8_data, 0, utf8_len + 1);

        applib_base64_decode((S8*) value, base64_len, (S8*) utf8_data, utf8_len);

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_srv_uc_p[instance]->msg.subject,
            (SRV_UC_MAX_SUBJECT_LEN + 1) * ENCODING_LENGTH,
            (kal_uint8*) utf8_data);
        {
        #if defined(__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__)
            srv_uc_fit_text_for_ut8_length_to_subject(instance);
        #elif defined (__MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__)
            srv_uc_fit_text_for_gb_length_to_subject(instance);
        #endif 
        }

        OslMfree(utf8_data);
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_READ_REPORT, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD)
        {
            /* Use current setting value */
        }
        else
        {
            if (atoi((S8*) value))
            {
                g_srv_uc_p[instance]->msg.read_report = MMI_TRUE;
            }
            else
            {
                g_srv_uc_p[instance]->msg.read_report = MMI_FALSE;
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_DELIVERY_REPORT, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD)
        {
            /* Use current setting value */
        }
        else
        {
            if (atoi((S8*) value))
            {
                g_srv_uc_p[instance]->msg.delivery_report = MMI_TRUE;
            }
            else
            {
                g_srv_uc_p[instance]->msg.delivery_report = MMI_FALSE;
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_PRIORITY, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG
             && g_srv_uc_p[instance]->main.mode == SRV_UC_NORMAL_EDIT_MODE) ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND
            /* || g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD */ )
        {
            /* Use current setting value */
        }
        else
        {
            g_srv_uc_p[instance]->msg.priority = atoi((S8*) value);
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_EXPIRY, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD)
        {
            /* Use current setting value */
        }
        else
        {
            g_srv_uc_p[instance]->msg.expiry_time = srv_uc_convert_mms_expiry_time_to_uc(atoi((S8*) value));
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_DELIVERY_TIME, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD)
        {
            /* Use current setting value */
        }
        else
        {
            g_srv_uc_p[instance]->msg.delivery_time = srv_uc_convert_mms_delivery_time_to_uc(atoi((S8*) value));
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_VISIBLE, el))
    {
        if (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_REPLY_ALL ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND ||
            g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD)
        {
            /* Use current setting value */
        }
        else
        {
            if (atoi((S8*) value))
            {
                g_srv_uc_p[instance]->msg.hide_sender = MMI_FALSE;
            }
            else
            {
                g_srv_uc_p[instance]->msg.hide_sender = MMI_TRUE;
            }
        }
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_NAME, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_srv_uc_p[instance]->xml.object);
        MMI_ASSERT(g_srv_uc_p[instance]->xml.object->file_name_ucs == NULL);

        g_srv_uc_p[instance]->xml.object->file_name_ucs = (*g_srv_uc_p[instance]->alloc) (ucs2_len, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(g_srv_uc_p[instance]->xml.object->file_name_ucs);
        memset(g_srv_uc_p[instance]->xml.object->file_name_ucs, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_srv_uc_p[instance]->xml.object->file_name_ucs,
            ucs2_len,
            (kal_uint8*) value);
    }
    else if (!strcmp(SRV_UC_XML_ELEMENT_FILE_PATH, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        MMI_ASSERT(g_srv_uc_p[instance]->xml.object);
        MMI_ASSERT(g_srv_uc_p[instance]->xml.object->file_path_ucs == NULL);

        g_srv_uc_p[instance]->xml.object->file_path_ucs = (*g_srv_uc_p[instance]->alloc) (ucs2_len, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(g_srv_uc_p[instance]->xml.object->file_path_ucs);
        memset(g_srv_uc_p[instance]->xml.object->file_path_ucs, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) g_srv_uc_p[instance]->xml.object->file_path_ucs,
            ucs2_len,
            (kal_uint8*) value);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_xml_data_address_hdlr
 * DESCRIPTION
 *  Add address
 * PARAMETERS
 *  instance            [IN]        
 *  utf8_addr           [?]         
 *  addr_len            [IN]        
 *  addr_type           [IN]        
 *  addr_group_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_uc_xml_data_address_hdlr(
        U32 instance,
        U8 *utf8_addr,
        S32 addr_len,
        srv_uc_address_type_enum addr_type,
        srv_uc_address_group_type_enum addr_group_type)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2;
    U32 ucs2_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_type == SRV_UC_ADDRESS_TYPE_IP)
    {
        /* Skip do nothing. */
        return;
    }
    if (addr_group_type == SRV_UC_ADDRESS_GROUP_TYPE_TO ||
        addr_group_type == SRV_UC_ADDRESS_GROUP_TYPE_CC || addr_group_type == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
    {
        if ((g_srv_uc_p[instance]->msg.to_num) >= SRV_UC_MAX_ADDRESS_NUM)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_DATA_ADDR_HDLR_ADDR_NO_EXCEED);
            return;
        }
    }

    ucs2_len = (addr_len + 1) * ENCODING_LENGTH;
    ucs2 = OslMalloc(ucs2_len);
    memset(ucs2, 0, ucs2_len);

    mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, utf8_addr);

    if (addr_type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER || addr_type == SRV_UC_ADDRESS_TYPE_EMAIL)
    {
        srv_uc_add_address(instance, ucs2, addr_type, addr_group_type);
    }
    else
    {
        MMI_ASSERT(0);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_XML_DATA_ADDR_HDLR_ADDR_TYPE_ERR);
    }
    OslMfree(ucs2);
#endif
}
#endif /*__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__*/
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_XML_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */
