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
 *  PictbridgeCUIGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Pictbridge CUI exported APIs.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PICT_CUI_GPROT_H_
#define _PICT_CUI_GPROT_H_

#include "filemgrsrvgprot.h"
/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
 #include "kal_general_types.h"
/* RHR add end*/
/****************************************************************************
* Define
*****************************************************************************/

/* 
  * enumeration of pictbridge print result 
  */
typedef enum
{    
    CUI_PICT_RESULT_OK,        /* print successfully */
    CUI_PICT_RESULT_ERROR,     /* print error */
    CUI_PICT_RESULT_CANCEL,    /* user cancel */
    CUI_PICT_RESULT_BUSY,      /* printing */
    CUI_PICT_RESULT_NOT_READY, /* not find printer or printer configured */
                                                                   
    CUI_PICT_RESULT_TOTAL
} cui_pict_result_enum;

/*
 *  Here are events that "Pictbridge CUI" will notify to caller.
 */
typedef enum
{
    EVT_ID_CUI_PICT_BEGIN = PICT_BRIDGE_BASE,
    
    EVT_ID_CUI_PICT_RESULT, /* This event indicate the result of pictbridge print.
                               refer to cui_pict_result_enum and cui_pict_result_event_struct.
                            */
                                         
    EVT_ID_CUI_PICT_GET_FILE_INFO, /* when caller received this event, it need to call 
                                      cui_pict_set_file_info() to set next printed file.                                      
                                   */    
    EVT_ID_CUI_PICT_TOTAL    
} cui_pict_event_enum;


/*  
 *  event structure of EVT_ID_CUI_PICT_RESULT
 */
typedef struct 
{
    MMI_EVT_GROUP_PARAM_HEADER
    
    S32     result;         /* refer to cui_pict_result_enum */       
} cui_pict_result_event_struct;


/* 
  * structure of file information for print 
  */
typedef struct
{
    const WCHAR *full_path;              /* the full path of file */
    const srv_fmgr_fileinfo_struct *info;   /* detail information of file */
    S32 index;                      /* the index of file */
} cui_pict_file_info_struct;


/*
 * DESCRIPTION
 *  Set information of file to be printed.
 * PARAMETERS
 *  cui_id  : [IN]  cui id of pictbridge. 
 *  info    : [IN]  information of file to be printed. 
 * RETURNS
 *  return the result of set file information
 */
void cui_pict_print_next_file(mmi_id cui_id, const cui_pict_file_info_struct *info, S32 result);


/* 
 * DESCRIPTION
 *  Launch Pictbridge CUI.
 * PARAMETERS
 *  parent_gid      [IN]       App's Group ID
 *  is_multi_sel    [IN]       Identify whether print multiple files selected or not.
 *  total_count     [IN]       The count of files to be printed.
 *  info            [IN]       The information of the first file to be printed.
 * RETURNS
 *  return id of the new created CUI
 */
mmi_id cui_pict_print_launch(mmi_id parent_gid, MMI_BOOL is_multi_sel, U8 total_count, 
                     const cui_pict_file_info_struct *info);



#endif

