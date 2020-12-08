/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_mms_setting_prot.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_MMSSETTING_PROT_H__
#define __VAPP_MMSSETTING_PROT_H__

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
/***************************************************************************** 
 * Include
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
	enum 
	{
		VAPP_LIST_HEADER_OPEN_GROUP,
		VAPP_LIST_HEADER_COMPOSE_SETTING,
		VAPP_LIST_HEADER_SENDNG_SETTING,
		VAPP_LIST_HEADER_RETRIEVAL_SETTING,
		VAPP_LIST_HEADER_MAX
	};

	enum 
	{
	
	#ifdef __MMI_MMS_SETTING_COMPOSE_SLIDE__
		VAPP_LIST_COMPOSE_SLIDE_TIME_SETTING,
	#endif
	
	#ifdef __MMI_MMS_SETTING_COMPOSE_CREATION__
		VAPP_LIST_COMPOSE_CREATION_SETTING,
	#endif
	
	#ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__
		VAPP_LIST_COMPOSE_PICTURE_RESIZING_SETTING,
	#endif
		VAPP_LIST_COMPOSE_MAX
	};

	enum 
	{
	
	#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
		VAPP_LIST_SENDING_DELIVERY_REPORT,
		VAPP_LIST_SENDING_READ_REPORT,
	#endif		
	#ifdef __MMI_MMS_SETTING_SENDING_PRIORITY__
		VAPP_LIST_SENDING_PRIORITY,
	#endif
	#ifdef __MMI_MMS_SETTING_SENDING_VALIDITY__				  
		VAPP_LIST_SENDING_VALIDITY_PERIOD,
	#endif
	#ifdef __MMI_MMS_SETTING_DELIVERY_TIME__				
		VAPP_LIST_SENDING_DELIVERY_TIME,
	#endif
		VAPP_LIST_SENDING_MAX
	};

	enum 
	{
	
#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
		VAPP_LIST_RETRIEVAL_DELIVERY_REPORT,
		VAPP_LIST_RETRIEVAL_READ_REPORT,
#endif		
	#ifdef __MMI_MMS_SETTING_ADVERTISEMENT__
		VAPP_LIST_RETRIEVAL_ALLOW_ADVERTISEMENT,
	#endif
	#ifdef __MMI_MMS_SETTING_ANONYMOUS__
		VAPP_LIST_RETRIEVAL_ALLOW_ANONYMOUS,
	#endif
	#ifdef __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__				 
		VAPP_LIST_RETRIEVAL_HOME_NETWORK,
	#endif
	#ifdef __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__				
		VAPP_LIST_RETRIEVAL_ROAMING_NETWORK,
	#endif
		VAPP_LIST_RETRIEVAL_MAX
	};

	enum 
	{
	#ifndef __COSMOS_NO_USER_DRIVE__
		VAPP_LIST_OPEN_DEFAULT_STORAGE,
	#endif		
	#ifdef __MMI_MMS_SETTING_DATA_ACCOUNT__
		VAPP_LIST_OPEN_DATA_ACCOUNT,
	#endif
	#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__	
		VAPP_LIST_OPEN_MSG_FILTER,
	#endif	
		VAPP_LIST_OPEN_MAX
	};

	enum 
	{
		VAPP_LIST_COMPOSE_CREATION_FREE,
		VAPP_LIST_COMPOSE_CREATION_WARNING,
		VAPP_LIST_COMPOSE_CREATION_RESTRICTED,
		VAPP_LIST_COMPOSE_CREATION_MAX
	};

	enum 
	{
		VAPP_LIST_SLIDE_TIME_3,
		VAPP_LIST_SLIDE_TIME_5,
		VAPP_LIST_SLIDE_TIME_8,
		VAPP_LIST_SLIDE_TIME_15,
		VAPP_LIST_SLIDE_TIME_20,
		VAPP_LIST_SLIDE_TIME_30,
		VAPP_LIST_SLIDE_TIME_60,
		VAPP_LIST_SLIDE_TIME_USER,
		VAPP_LIST_SLIDE_TIME_MAX
	};

	enum
	{
		VAPP_LIST_COMPOSE_PICTURE_RESIZE_10KB,
		VAPP_LIST_COMPOSE_PICTURE_RESIZE_50KB,
		VAPP_LIST_COMPOSE_PICTURE_RESIZE_100KB,
		VAPP_LIST_COMPOSE_PICTURE_RESIZE_OFF,
		VAPP_LIST_COMPOSE_PICTURE_RESIZE_MAX
	};

	enum
	{
		VAPP_LIST_RETVL_HOME_IMMED,
		VAPP_LIST_RETVL_HOME_DEFER,
		VAPP_LIST_RETVL_HOME_REJECT,
		VAPP_LIST_RETVL_HOME_MAX
	};
#ifndef __MMI_MMS_2_RETRIVAL_MODE_SETTING__
	enum
	{
		VAPP_LIST_RETVL_ROAM_AS_HOME,
		VAPP_LIST_RETVL_ROAM_IMMED,
		VAPP_LIST_RETVL_ROAM_DEFER,
		VAPP_LIST_RETVL_ROAM_REJECT,
		VAPP_LIST_RETVL_ROAM_MAX
	};
#else
    enum
	{
		VAPP_LIST_RETVL_ROAM_NO,
		VAPP_LIST_RETVL_ROAM_YES,
		VAPP_LIST_RETVL_ROAM_MAX
	};
#endif
	enum
	{
		VAPP_LIST_SENDING_VALID_1HR,
		VAPP_LIST_SENDING_VALID_6HR,
		VAPP_LIST_SENDING_VALID_12HR,
		VAPP_LIST_SENDING_VALID_1DAY,
		VAPP_LIST_SENDING_VALID_1WEEK,
		VAPP_LIST_SENDING_VALID_MAXIMUM,
		VAPP_LIST_SENDING_VALID_MAX
	};

	enum
	{
		VAPP_LIST_SENDING_DELIVERY_IMMED,
		VAPP_LIST_SENDING_DELIVERY_1HR,
		VAPP_LIST_SENDING_DELIVERY_2HR,
		VAPP_LIST_SENDING_DELIVERY_12HR,
		VAPP_LIST_SENDING_DELIVERY_24HR,
		VAPP_LIST_SENDING_DELIVERY_MAX
	};

	enum
	{
		VAPP_LIST_SENDING_PRIO_LOW,
		VAPP_LIST_SENDING_PRIO_NORMAL,
		VAPP_LIST_SENDING_PRIO_HIGH,
		VAPP_LIST_SENDING_PRIO_MAX
	};


	enum
	{
		VAPP_LIST_SETTING_PREF_PHONE,
		VAPP_LIST_SETTING_PREF_MEMORY_CARD,
		VAPP_LIST_SETTING_PREF_MAX
	};
	enum
	{
		VAPP_LIST_SETTING_FILTER_PHONE,
		VAPP_LIST_SETTING_FILTER_MEMORY_CARD,
		VAPP_LIST_SETTING_FILTER_MAX
	};


	enum
	{
		VAPP_LIST_SETTING_DATA_ACCOUNT_SIM1,
		VAPP_LIST_SETTING_DATA_ACCOUNT_SIM2,
		VAPP_LIST_SETTING_DATA_ACCOUNT_MAX
	};

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/


#endif /* __MMI_MMS_2__ */
#endif /* __VAPP_MMSSETTING_PROT_H__ */

