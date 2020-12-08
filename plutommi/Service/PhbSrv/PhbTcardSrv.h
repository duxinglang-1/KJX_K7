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
 *  PhbTcardSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  for Tcard contacts
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __PHB_TCARD_SRV_H__
#define __PHB_TCARD_SRV_H__

#include "custom_phb_config.h"

#define MMI_PHB_TCARD_NUMBER_COUNT 4
#define MMI_PHB_TCARD_EMAIL_COUNT 2
#define MMI_PHB_TCARD_GROUP_COUNT 20

typedef struct
{
    kal_uint16 image_path[SRV_FMGR_PATH_MAX_LEN];
    kal_uint16 ring_path[SRV_FMGR_PATH_MAX_LEN];
    kal_uint16 video_path[SRV_FMGR_PATH_MAX_LEN];
} srv_phb_tcard_res_path_struct;

typedef struct
{
    kal_uint16 res_type;
    kal_uint16 image_id;
    kal_uint16 ringtone_id;
    kal_uint16 video_id;
} srv_phb_tcard_res_struct;

typedef struct
{
    kal_uint32 field_mask;
    kal_uint16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];                  /* name field */
    kal_uint16 l_name[MMI_PHB_NAME_FIELD_LENGTH + 1];                /* last name field */
    mmi_phb_asc_num_struct num[MMI_PHB_TCARD_NUMBER_COUNT];          /* number field */
    mmi_phb_email_struct email[MMI_PHB_TCARD_EMAIL_COUNT];           /* email address */
    srv_phb_tcard_res_struct res_field;
} srv_phb_tcard_data_struct;

typedef struct
{
    kal_uint32 group;
    kal_uint16 company[MMI_PHB_COMPANY_LENGTH + 1];                  /* USC2 company name */
    kal_uint16 title[MMI_PHB_TITLE_LENGTH + 1];                      /* title field */
    kal_uint16 note[MMI_PHB_NOTE_LENGTH + 1];                        /* note field */
    kal_uint8  url[MMI_PHB_URL_LENGTH + 1];                          /* url field */
    mmi_phb_address_struct address;                                  /* address field */
    mmi_phb_bday_struct bday;                                        /* bday field */
} srv_phb_tcard_info_struct;

typedef struct
{
    U16 group_name[MMI_PHB_GROUP_NAME_LENGTH + 1];                   /*group name*/
    U16 res_type;                                                    /*res type*/
    U16 image_id;
    U16 image_path[SRV_FMGR_PATH_MAX_LEN + 1];                       /*image file path*/
    U16 ringtone_id;
    U16 ringtone_path[SRV_FMGR_PATH_MAX_LEN + 1];                    /*ringtone file path*/
    U16 video_id;
    U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1];                       /*video path*/
} srv_phb_tcard_group_struct;

#endif
