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
 *  MmsXMLTagsSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Messsage Content XML Tags
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMS_XMLTags__SRV_H__
#define __MMS_XMLTags__SRV_H__
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

/* Elements */
#define SRV_MMS_XML_ELEMENT_MMS "mms"
#define SRV_MMS_XML_ELEMENT_HEADER "header"
#define SRV_MMS_XML_ELEMENT_TO "to"
#define SRV_MMS_XML_ELEMENT_CC "cc"
#define SRV_MMS_XML_ELEMENT_BCC "bcc"
#define SRV_MMS_XML_ELEMENT_FROM "from"
#define SRV_MMS_XML_ELEMENT_SUBJECT "subject"
#define SRV_MMS_XML_ELEMENT_REPORTED_SUBJECT "reported_msg_sub"
#define SRV_MMS_XML_ELEMENT_READ_REPORT "rr"
#define SRV_MMS_XML_ELEMENT_DELIVERY_REPORT "dr"
#define SRV_MMS_XML_ELEMENT_PRIORITY "prio"
#define SRV_MMS_XML_ELEMENT_EXPIRY "expiry"
#define SRV_MMS_XML_ELEMENT_DELIVERY_TIME "delivery"
#define SRV_MMS_XML_ELEMENT_VISIBLE "visible"
#define SRV_MMS_XML_ELEMENT_BODY "body"
#define SRV_MMS_XML_ELEMENT_SLIDE "slide"
#define SRV_MMS_XML_ELEMENT_TEXT "text"
#define SRV_MMS_XML_ELEMENT_IMAGE "img"
#define SRV_MMS_XML_ELEMENT_AUDIO "audio"
#define SRV_MMS_XML_ELEMENT_VIDEO "video"
#define SRV_MMS_XML_ELEMENT_OBJECT "obj"
#define SRV_MMS_XML_ELEMENT_NAME "name"
#define SRV_MMS_XML_ELEMENT_FILE_PATH "filepath"
#define SRV_MMS_XML_ELEMENT_VERSION "mms_version"
#define SRV_MMS_XML_ELEMENT_DATE "date"
#define SRV_MMS_XML_ELEMENT_MSG_CLASS "msgclass"
#define SRV_MMS_XML_ELEMENT_MSG_SIZE  "msgsize"
#define SRV_MMS_XML_ELEMENT_DL_SIZE    "dl_size"
#define SRV_MMS_XML_ELEMENT_REPORT_MSG_ID "reported_msg"
#define SRV_MMS_XML_ELEMENT_MSG_STATUS "msgStatus"
#define SRV_MMS_XML_ELEMENT_JAVA_APP_ID "app_id"
#define SRV_MMS_XML_ELEMENT_JAVA_REPLY_APP_ID "reply_app_id"
#define SRV_MMS_XML_ELEMENT_CONTENT_ID "cnt_id"
#define SRV_MMS_XML_ELEMENT_CONTENT_LOCATION "cnt_loc"
#define SRV_MMS_XML_ELEMENT_MIME_TYPE "mime"
#define SRV_MMS_XML_ELEMENT_STATUS "status"
#define SRV_MMS_XML_ELEMENT_REF_ID "ref"
#define SRV_MMS_XML_ELEMENT_REGION "region"

/* Attributes */
#define SRV_MMS_XML_ATTR_TYPE "type"
#define SRV_MMS_XML_ATTR_POHNE_NUMBER "P"
#define SRV_MMS_XML_ATTR_EMAIL_ADDR "E"
#define SRV_MMS_XML_ATTR_IP4_ADDR "IP4"
#define SRV_MMS_XML_ATTR_BGCOLOR "bgColor"
#define SRV_MMS_XML_ATTR_FGCOLOR "fgColor"
#define SRV_MMS_XML_ATTR_SLIDE_NUM "slideNum"
#define SRV_MMS_XML_ATTR_OBJ_NUM "objNum"
#define SRV_MMS_XML_ATTR_LAYOUT "layout"
#define SRV_MMS_XML_ATTR_INDEX "index"
#define SRV_MMS_XML_ATTR_DURATION "dur"
#define SRV_MMS_XML_ATTR_ID "id"
#define SRV_MMS_XML_ATTR_BEGIN "begin"
#define SRV_MMS_XML_ATTR_END "end"
#define SRV_MMS_XML_ATTR_ATTACH "attach"
#define SRV_MMS_XML_ATTR_VIRTUAL_FILE "vf"
#define SRV_MMS_XML_ATTR_DRM "drm"
#define SRV_MMS_XML_ATTR_SIZE "size"
#define SRV_MMS_XML_ATTR_OFFSET "offset"
#define SRV_MMS_XML_ATTR_TEXT_STYLE   "txtStyle"
#define SRV_MMS_XML_ATTR_TEXT_SIZE    "txtSize"
#define SRV_MMS_XML_ATRR_ALT_STR "alt"
#define SRV_MMS_XML_ATTR_ENCODING_SCHEME "encoding"
#define SRV_MMS_XML_ATTR_TOP "top"
#define SRV_MMS_XML_ATTR_LEFT "left"
#define SRV_MMS_XML_ATTR_WIDTH "width"
#define SRV_MMS_XML_ATTR_HEIGHT "height"
#define SRV_MMS_XML_ATTR_FIT "fit"
#define SRV_MMS_XML_ATTR_REGION "region"

#endif /* __MMI_MMS_2__ */ 
#endif /* __MMS_XMLTags__SRV_H__ */ 

