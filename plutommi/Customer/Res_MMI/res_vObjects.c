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
 * Res_vObjects.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for populating resource of vObjects.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _RES_VOBJECTS_C
#define _RES_VOBJECTS_C
#include "MMI_features.h"

#include "CustomCfg.h"
#include "vObjectsResDef.h"
#include "PhoneBookResDef.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif


#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#ifdef __MMI_DUAL_SIM_MASTER__
//#include "MTPNP_AD_resdef.h"
#endif	/* __MMI_DUAL_SIM_MASTER__ */
/*****************************************************************************
* FUNCTION
*  PopulatevObjectRes
* DESCRIPTION
*   Populate resource data for vobjects.
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void PopulatevObjectRes(void)
{
#if 0
#ifdef __MMI_VCARD__
/* under construction !*/
#endif	
#ifdef __MMI_VCALENDAR__
/* under construction !*/
#endif	
#ifdef __MMI_VBOOKMARK__
/* under construction !*/
#endif /* __MMI_VBOOKMARK__ */	
/* under construction !*/
/* under construction !*/
#ifdef __MMI_FILE_MANAGER__
/* under construction !*/
/* under construction !*/
#endif	
#ifdef __MMI_FILE_MANAGER__
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VCARD__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_VCALENDAR__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_VBOOKMARK__
/* under construction !*/
#endif /* __MMI_VBOOKMARK__ */
#endif
}

/*****************************************************************************
* FUNCTION
*  PopulatevCardRes
* DESCRIPTION
*   Populate resource data for vcard.
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#ifdef __MMI_VCARD__
void PopulatevCardRes(void)
{
#if 0
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
#endif
#if defined(__MMI_MMS__)
/* under construction !*/
#endif
#if  defined(__MMI_EMAIL__)
/* under construction !*/
#endif	
#if  defined(__MMI_IRDA_SUPPORT__)	 
/* under construction !*/
#endif		
#ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_MMS__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if 0 // defined(__MMI_IRDA_SUPPORT__)	 
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if  defined(__MMI_EMAIL__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_OPP_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #endif
    #if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
            #else
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FILE_MANAGER__) */
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
#endif 
#if defined(__MMI_MMS__)
/* under construction !*/
#endif 
#if defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
#endif 
#if defined(__MMI_EMAIL__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_OPP_SUPPORT__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FILE_MANAGER__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
#endif 
/* under construction !*/
#endif    
}
#endif

/*****************************************************************************
* FUNCTION
*  PopulatevCalendarRes
* DESCRIPTION
*   Populate resource data for vcalendar.
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#ifdef __MMI_VCALENDAR__
void PopulatevCalendarRes(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)	
/* under construction !*/
#endif
#if defined(__MMI_MMS__)
/* under construction !*/
#endif
#if  defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
#endif	
#if  defined(__MMI_EMAIL__)
/* under construction !*/
#endif	
#if  defined(__MMI_OPP_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)	
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_MMS__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if 0//  defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if  defined(__MMI_EMAIL__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if  defined(__MMI_OPP_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if  defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
#endif		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_MMS__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_IRDA_SUPPORT__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_OPP_SUPPORT__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_EMAIL__)
/* under construction !*/
#endif 
/* under construction !*/
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FILE_MANAGER__) */ 
/* under construction !*/
#endif
}
#endif  // #ifdef __MMI_VCALENDAR__


/*****************************************************************************
* FUNCTION
*  PopulatevBookmarkRes
* DESCRIPTION
*   Populate resource data for vbookmark
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
#ifdef __MMI_VBOOKMARK__
void PopulatevBookmarkRes(void)
{
#if 0
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
    #if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
    #endif /* (__MMI_FILE_MANAGER__) */
    #endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FILE_MANAGER__) */
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
/* under construction !*/
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
#if defined(__MMI_FILE_MANAGER__)
/* under construction !*/
#endif /* defined(__MMI_FILE_MANAGER__) */
#endif /* __MMI_BRW_BOOKMARK_IN_FMGR__ */
/* under construction !*/
#endif    
}
#endif /* __MMI_VBOOKMARK__ */

#endif

#endif /*END #ifndef _RES_VOBJECTS_C*/
