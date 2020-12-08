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
 *  vapp_phb_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
#include "MMI_features.h"

#ifndef __PB_GPROT_H__
#define __PB_GPROT_H__

#include "MMIDataType.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define VAPP_PHB_ENTER_REQ_NO (VAPP_CONTACT + 1)

/* phb app event id enum */
typedef enum
{
    EVT_ID_VAPP_PHB_APP_ENTER = VAPP_CONTACT + 1,
    EVT_ID_VAPP_PHB_TOTAL
} vapp_phb_event_id_enum;


/* launch app type */
typedef enum
{
    VAPP_PHB_SUB_APP_DIAL = 1,                          /* dialer */
    VAPP_PHB_SUB_APP_CLOG,                              /* call log */
    VAPP_PHB_SUB_APP_CONTACT,                           /* contact */
    VAPP_PHB_SUB_APP_SNS,                               /* sns */
    VAPP_PHB_SUB_APP_PIM_MANAGER,                       /* phonebook manager */
    VAPP_PHB_SUB_APP_TYPE_TOTAL                         /* enum tail*/
} vapp_phb_sub_app_type_enum;


typedef struct
{
    MMI_EVT_PARAM_HEADER

    vapp_phb_sub_app_type_enum sub_app_id;
    void* sub_app_data;
} vapp_phb_app_enter_req_struct;


/* launcher struct */
typedef struct
{
    vapp_phb_sub_app_type_enum sub_app;                 /* launch app type */
    void* user_data;                                    /* user data */
} vapp_phb_sub_app_launch_struct;


/* vcard field type */
typedef enum
{
    VAPP_VCARD_NAME_FIELD,
    VAPP_VCARD_NUMBER_FIELD,
    VAPP_VCARD_EMAIL_FIELD,
    VAPP_VCARD_BIRTHDAY_FIELD,
    VAPP_VCARD_NOTE_FIELD,
    VAPP_VCARD_ADDRESS_FIELD,
    VAPP_VCARD_TITLE_FIELD,
    VAPP_VCARD_COMPANY_FIELD,
    VAPP_VCARD_END_FIELD
} VappVcardFieldEnum;


/* vcard address type */
typedef enum
{
    VAPP_VCARD_ADDRESS_POST_OFFICE,               /* Post Office Address */
    VAPP_VCARD_ADDRESS_EXTEND_ADDRESS,            /* Extented Address */
    VAPP_VCARD_ADDRESS_STREET,                    /* Street */
    VAPP_VCARD_ADDRESS_LOCALITY,                  /* Locality */
    VAPP_VCARD_ADDRESS_REGION,                    /* Region */
    VAPP_VCARD_ADDRESS_POSTAL_CODE,               /* Postal Code */
    VAPP_VCARD_ADDRESS_COUNTRY,                   /* Country */
    VAPP_VCARD_ADDRESS_ADDRESS_FIELD_END
} VappVcardAddressFieldEnum;


/*****************************************************************************
 * FUNCTION
 *  vapp_phb_launch
 * DESCRIPTION
 *  Contact launch: it will launch sub app by the args
 * PARAMETERS
 *  args                  :         [IN]       vapp_phb_sub_app_launch_struct
 *  argSize               :         [IN]       size of args
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID vapp_phb_launch(void* args, U32 argSize);


/*****************************************************************************
 * FUNCTION
 *  vapp_phb_init
 * DESCRIPTION
 *  Contact init: to init task...
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_phb_init(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_phb_check_ready
 * DESCRIPTION
 *  check Contact ready or busy in something
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL vapp_phb_check_ready(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_phb_check_processing
 * DESCRIPTION
 *  check Contact processing or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL vapp_phb_check_processing(void);


/*****************************************************************************
 * FUNCTION
 *  vapp_phb_unsaved_number_to_phb
 * DESCRIPTION
 *  save the unsaved number to phonebook.
 *  [NOTICE] the caller should make sure it is proper to create new screen
 * PARAMETERS
 *  number              [IN]        data
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_phb_unsaved_number_to_phb(WCHAR* number);

#include "FileMgrType.h"
#include "FileMgrSrvGprot.h"
/*****************************************************************************
 * FUNCTION
 *  vapp_phb_get_head_portrait_filter
 * DESCRIPTION
 *  get contact support head portrait filter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void vapp_phb_get_head_portrait_filter(FMGR_FILTER *filter);

/*****************************************************************************
 * FUNCTION
 *  vapp_phb_get_head_portrait_type
 * DESCRIPTION
 *  query contact support head portrait type
 * PARAMETERS
 *  mmi_fmgr_filetype_enum
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL vapp_phb_query_head_portrait_type(mmi_fmgr_filetype_enum type);
MMI_BOOL vapp_phb_query_head_portrait_need_thumbnail(S8*filePath);
#ifdef __MMI_CONTACT_SLIM__
	#undef __MMI_PHB_MARK_MESSAGE__
#else
 	#define __MMI_PHB_MARK_MESSAGE__
#endif

#ifdef __MMI_CONTACT_SLIM__
	#undef  __MMI_PHB_MYCARD__
#else
	#define __MMI_PHB_MYCARD__ 
#endif

#ifdef __MMI_CONTACT_SLIM__ 
	#undef __MMI_PHB_VIEW_CALLOG__
#else
	#define __MMI_PHB_VIEW_CALLOG__
#endif

#if defined (__MMI_PHB_VIEW_CALLOG__ )||defined( __MMI_PHB_TCARD_STORAGE_SUPPORT__)
#undef __MMI_PHB_NEED_SERIALZE__
#else 
#define __MMI_PHB_NEED_SERIALZE__
#endif

#ifdef __cplusplus
}
#endif
S32 vapp_phb_imggallery_is_file_support(const WCHAR *path);

#endif /* __PB_GPROT_H__ */

