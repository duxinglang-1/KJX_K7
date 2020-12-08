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
 * vapp_prov_base.h
 *
 * Project:
 * --------
 * Venus
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox app utility procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_PROV_BASE_H
#define __VAPP_PROV_BASE_H

#ifdef __cplusplus
extern "C" 
#endif
{
#include "MMIDataType.h"
}

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define VAPP_PROV_ADDR_MAX_LEN             (60)

#define VAPP_PROV_DATE_TIME_MAX_LEN        (14)
#define VAPP_PROV_DATE_TIME_BUF_SIZE       ((VAPP_PROV_DATE_TIME_MAX_LEN + 1) * ENCODING_LENGTH)


#define VAPP_PROV_IP_MAX_LEN               (15)
#define VAPP_PROV_IP_MAX_SEG_VAL           (255)
#define VAPP_PROV_IP_DOT                   L'.'
#define VAPP_PROV_UCS2_SPACE               (L" ")
#define VAPP_PROV_IP_MAX_SEG_LEN           (3)
#define VAPP_PROV_IP_MAX_SEG_NUM           (4)

#define VAPP_PROV_ENCODING_LEN             (2)
#define VAPP_PROV_DATA_TIME_MAX_LEN        (14)
#define VAPP_PROV_DATA_TIME_BUF_SIZE       ((VAPP_PROV_DATA_TIME_MAX_LEN + 1) * VAPP_PROV_ENCODING_LEN)

#define VAPP_PROV_MSG_SEND_ADDR_MAX_LEN     SRV_PROVBOX_ADDR_MAX_CHAR_LEN
#define VAPP_PROV_MSG_SEND_ADDR_BUF_SIZE    ((VAPP_PROV_MSG_SEND_ADDR_MAX_LEN + 1) * ENCODING_LENGTH)

#define VAPP_PROV_ADDR_MAX_LEN              (60)


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    VAPP_PROV_MSG_ADDR_TYPE_NONE = 0,
    VAPP_PROV_MSG_ADDR_TYPE_NUM,
    VAPP_PROV_MSG_ADDR_TYPE_STR,
    VAPP_PROV_MSG_ADDR_TYPE_TOTAL
} vapp_prov_msg_addr_type_enum;

typedef enum
{
    VAPP_PROV_TRANS_ID_NULL = 0,
    VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG,
    VAPP_PROV_TRANS_ID_CCA_PROCESS_MSG_EXT,
    VAPP_PROV_TRANS_ID_MAX_ITEM
} vapp_prov_trans_id_enum;

enum
{
#ifdef __MMI_MAINLCD_320X480__

   VAPP_PROV_TITLE_FONT_SIZE = 16,
   VAPP_PROV_SIZE_FONT_SIZE  = 14,
   VAPP_PROV_TIME_FONT_SIZE  = 13,
   VAPP_PROV_BUTTON_FONT_SIZE = 16,
  
   /* Lite viewer */  
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE    = 14,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET = 0,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH    = 88,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT   = 40,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET = 2,
   
   /* Full viewer */
   VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET = 10,
   VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET = 10,
   VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET = 2,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET = 10,

#elif __MMI_MAINLCD_480X800__

   VAPP_PROV_TITLE_FONT_SIZE = 30,
   VAPP_PROV_SIZE_FONT_SIZE  = 21,
   VAPP_PROV_TIME_FONT_SIZE  = 21,
   VAPP_PROV_BUTTON_FONT_SIZE = 28,
   
   /* Lite viewer */  
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE    = 14,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET = 0,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH    = 175,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT   = 70,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET = 0,
   
   /* Full viewer */
   VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET = 14,
   VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET = 14,
   VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET = 10,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET = 14,
   
#elif __MMI_MAINLCD_240X320__
   VAPP_PROV_TITLE_FONT_SIZE = 14,
   VAPP_PROV_SIZE_FONT_SIZE  = 12,
   VAPP_PROV_TIME_FONT_SIZE  = 11,
   VAPP_PROV_BUTTON_FONT_SIZE = 14,
   
   /* Lite viewer */  
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE    = 14,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET = 0,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH    = 83,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT   = 38,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET = 2,
   
   /* Full viewer */
   VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET = 5,
   VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET = 5,
   VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET = 1,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET = 5,

#elif __MMI_MAINLCD_240X400__
   VAPP_PROV_TITLE_FONT_SIZE = 14,
   VAPP_PROV_SIZE_FONT_SIZE  = 12,
   VAPP_PROV_TIME_FONT_SIZE  = 11,
   VAPP_PROV_BUTTON_FONT_SIZE = 14,
   
   /* Lite viewer */  
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE    = 14,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET = 0,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH    = 83,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT   = 38,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET = 2,
   
   /* Full viewer */
   VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET = 5,
   VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET = 5,
   VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET = 1,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET = 5,
   
#else

   VAPP_PROV_TITLE_FONT_SIZE = 32,
   VAPP_PROV_SIZE_FONT_SIZE  = 26,
   VAPP_PROV_TIME_FONT_SIZE  = 23,
   VAPP_PROV_BUTTON_FONT_SIZE = 32,
   
   /* Lite viewer */  
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_SPACE    = 14,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_Y_OFFSET = 0,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_WIDTH    = 88,
   VAPP_PROV_VIEW_LITE_INSTALL_BTN_HEIGHT   = 40,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TITLE_OFFSET = 0,
   
   /* Full viewer */
   VAPP_PROV_VIEW_FULL_TEXT_X_OFFSET = 14,
   VAPP_PROV_VIEW_FULL_TEXT_Y_OFFSET = 18,
   VAPP_PROV_VIEW_FULL_SIZE_Y_OFFSET = 10,
   VAPP_PROV_VIEW_FULL_SIZE_AND_TIME_OFFSET = 14,
   
#endif
   
   
   ENCODING_LEN          = 2,
   DATA_TIME_MAX_LEN     = 14,
   DATA_TIME_BUF_SIZE    = ((DATA_TIME_MAX_LEN + 1) * ENCODING_LEN),
    
   DETAIL_DATA_MAX_LEN   = 35,
   DETAIL_DATA_BUF_SIZE  = ((DETAIL_DATA_MAX_LEN + 1) * ENCODING_LEN)
};

#endif /* __VAPP_PROV_BASE_H */
