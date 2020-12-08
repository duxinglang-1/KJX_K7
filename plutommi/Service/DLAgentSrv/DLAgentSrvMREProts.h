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
 * DLAgentMREProts.h
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#ifndef DOWNLOAD_AGENT_MRE_PROT_H
#define DOWNLOAD_AGENT_MRE_PROT_H

#ifdef __COSMOS_MMI_PACKAGE__
#include "MMIDataType.h"

#ifndef DOWNLOAD_AGENT_DEF_H
#include "DLAgentSrvDef.h"
#endif

#define SRV_DA_MAX_NUM_MRE_DOWNLOAD     4

typedef enum
{
    SRV_DA_MRE_DOWNLOAD_INITIALIZING,   /* Download is not started YET. MAY be DLAgent querying information about downloading Item */
    SRV_DA_MRE_DOWNLOAD_DOWNLOADING,    /* Download in progress, APP need to call enter download list if required */
    SRV_DA_MRE_DOWNLOAD_PAUSED,         /* Download in PAUSED state. User may resume after some-time. Do not free downloading context */
	SRV_DA_MRE_DOWNLOAD_WAITING,        /* Download is in waiting state, some other download may be on-going. APP need to call enter download list if required */
    SRV_DA_MRE_DOWNLOAD_COMPLETED,      /* Download have already been completed at MRE service */
    SRV_DA_MRE_DOWNLOAD_FAILED,         /* Downloading failed */
	SRV_DA_MRE_DOWNLOAD_NOT_FOUND,      /* There is no any such item in DLAgent list */
   
    SRV_DA_MRE_DOWNLOAD_END_OF_ENUM
} srv_da_mre_download_enum;


typedef enum
{
    SRV_DA_MRE_ERROR_OK = 0,                   /* Action or request completed successfully */
    SRV_DA_MRE_ERROR_ALREADY_EXISTS = -1,      /* returned if a download exists in DLAgent list and MRE requested the same to download again */
    SRV_DA_MRE_ERROR_DOWNLOAD_CANNOT_PROCEED,  /* Returned if background download request and DLAgent failed to process */
    SRV_DA_MRE_ERROR_REQUEST_FAILED,           /* Returned if a request to DLAgent failed */
	SRV_DA_MRE_ERROR_MAX_DOWNLOAD_EXCEEDS,     /* Returned if DLAgent cannot process new download request (Including Background download) As it already have maximum number of download in it's download list*/
    SRV_DA_MRE_ERROR_UNKNOWN,                  /* Returned if any unknown error happend to Download */
   
    SRV_DA_MRE_ERROR_END_OF_ENUM
} srv_da_mre_error_enum;


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_get_download_status
 * DESCRIPTION
 *  To query status of a MRE download in DLAgent
 * PARAMETERS
 *  app_id       : [IN]  applicatiion ID: unique id of every MRE download. provided by MRE APP when download start first time.
 * RETURNS
 *  values in enum srv_da_mre_state_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
extern S32 srv_da_mre_get_download_status (U32 app_id);


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_start_new_download
 * DESCRIPTION
 *  To start a new MRE download.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be download: unique id of every MRE download.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
extern S32 srv_da_mre_start_new_download (U32 app_id);



/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_start_bg_download
 * DESCRIPTION
 *  To start a new MRE download in background.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be download: unique id of every MRE download.
 *  filepath     : [IN]  Path to store the downloaded file.
 *  filename     : [IN]  FIlename to finally save application with.
 *  filesize     : [IN]  filesize.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
extern S32 srv_da_mre_start_bg_download (U32 app_id, U16 *filepath, U16 *filename, U32 filesize);


/*****************************************************************************
 * FUNCTION
 *  srv_da_mre_enter_download_list
 * DESCRIPTION
 *  To open list of all downloading items with provided ID highlighted.
 * PARAMETERS
 *  app_id       : [IN]  ID of the application that required to be focused in Download list: unique id of every MRE download.
 * RETURNS
 *  values in enum srv_da_mre_error_enum. Please see description in srv_da_mre_state_enum.
 *****************************************************************************/
extern S32 srv_da_mre_enter_download_list (U32 app_id);
#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* DOWNLOAD_AGENT_MRE_PROT_H */
