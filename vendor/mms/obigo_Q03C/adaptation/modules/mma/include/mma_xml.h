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
 *   mma_xml.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains function prototypes, constant/macro/structure definition 
 *   for XML interfacing functionality
 *
 * Author:
 * -------
 * -------
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
 *==============================================================================
 *******************************************************************************/

#ifndef _MMA_XML_H
#define _MMA_XML_H

#include "kal_general_types.h"
#include "mma_api.h"

/**********************************************************************
 * Macro definition
 **********************************************************************/
#define MMA_XML_ELEMENT_MMS "mms"
#define MMA_XML_ELEMENT_HEADER "header"
#define MMA_XML_ELEMENT_TO "to"
#define MMA_XML_ELEMENT_CC "cc"
#define MMA_XML_ELEMENT_BCC "bcc"
#define MMA_XML_ELEMENT_FROM "from"
#define MMA_XML_ATTR_TYPE "type"
#define MMA_XML_ATTR_POHNE_NUMBER "P"
#define MMA_XML_ATTR_EMAIL_ADDR "E"
#define MMA_XML_ATTR_IPV4_ADDR "IP4"
#define MMA_XML_ATTR_TIME_ABSOLUTE "A"
#define MMA_XML_ATTR_TIME_RELATIVE "R"
#define MMA_XML_ELEMENT_SUBJECT "subject"
#define MMA_XML_ELEMENT_READ_REPORT "rr"
#define MMA_XML_ELEMENT_DELIVERY_REPORT "dr"
#define MMA_XML_ELEMENT_PRIORITY "prio"
#define MMA_XML_ELEMENT_EXPIRY "expiry"
#define MMA_XML_ELEMENT_DELIVERY_TIME "delivery"
#define MMA_XML_ELEMENT_VISIBLE "visible"
#define MMA_XML_ELEMENT_VERSION "version"
#define MMA_XML_ELEMENT_DATE "date"
#define MMA_XML_ELEMENT_CLASS "class"
#define MMA_XML_ELEMENT_APP_ID "app_id"
#define MMA_XML_ELEMENT_REPLY_APP_ID "reply_app_id"
#define MMA_XML_ELEMENT_DOWNLOAD_SIZE "dl_size"
#define MMA_XML_ELEMENT_DOWNLOAD_URL "dl_url"
#define MMA_XML_ELEMENT_STATUS "status"
#define MMA_XML_ELEMENT_REPORTED_MSG "reported_msg"
#define MMA_XML_ELEMENT_REPORTED_MSG_SUB "reported_msg_sub"
#define MMA_XML_ELEMENT_PRESENTATION "presentation"
#define MMA_XML_ELEMENT_LAYOUT "layout"
#define MMA_XML_ATTR_WIDTH "width"
#define MMA_XML_ATTR_HEIGHT "height"
#define MMA_XML_ELEMENT_REGION "region"
#define MMA_XML_ATTR_TOP "top"
#define MMA_XML_ATTR_LEFT "left"
#define MMA_XML_ATTR_FIT "fit"
#define MMA_XML_ELEMENT_BODY "body"
#define MMA_XML_ATTR_BGCOLOR "bgColor"
#define MMA_XML_ATTR_FGCOLOR "fgColor"
#define MMA_XML_ATTR_SLIDE_NUM "slideNum"
#define MMA_XML_ATTR_OBJ_NUM "objNum"
#define MMA_XML_ATTR_LAYOUT "layout"
#define MMA_XML_ATTR_IMG_FIT "imgFit"
#define MMA_XML_ATTR_TXT_FIT "txtFit"
#define MMA_XML_ATTR_TXT_STYLE "txtStyle"
#define MMA_XML_ATTR_TXT_SIZE "txtSize"
#define MMA_XML_ELEMENT_SLIDE "slide"
#define MMA_XML_ATTR_INDEX "index"
#define MMA_XML_ATTR_DURATION "dur"
#define MMA_XML_ATTR_ID "id"
#define MMA_XML_ATTR_BEGIN "begin"
#define MMA_XML_ATTR_END "end"
#define MMA_XML_ATTR_ALT "alt"
#define MMA_XML_ATTR_REGION "region"
#define MMA_XML_ELEMENT_TEXT "text"
#define MMA_XML_ELEMENT_IMAGE "img"
#define MMA_XML_ELEMENT_AUDIO "audio"
#define MMA_XML_ELEMENT_VIDEO "video"
#define MMA_XML_ELEMENT_REF "ref"
#define MMA_XML_ATTR_ATTACH "attach"
#define MMA_XML_ATTR_VIRTUAL_FILE "vf"
#define MMA_XML_ATTR_DRM "drm"
#define MMA_XML_ATTR_SIZE "size"
#define MMA_XML_ATTR_OFFSET "offset"
#define MMA_XML_ATTR_ENCODING "encoding"
#define MMA_XML_ELEMENT_OBJECT "obj"
#define MMA_XML_ELEMENT_NAME "name"
#define MMA_XML_ELEMENT_MIME "mime"
#define MMA_XML_ELEMENT_CONTENT_ID "cnt_id"
#define MMA_XML_ELEMENT_CONTENT_LOCATION "cnt_loc"
#define MMA_XML_ELEMENT_FILE_PATH "filepath"


/**********************************************************************
 * Structure definition
 **********************************************************************/

/**********************************************************************
 * Function prototype
 **********************************************************************/
extern mma_result_enum mma_xml_parse_mms_description_file(mma_create_info_struct *info);
extern long mma_xml_create_mms_description_file(mma_parse_info_struct *info);



#endif /* _MMA_XML_H */ 

