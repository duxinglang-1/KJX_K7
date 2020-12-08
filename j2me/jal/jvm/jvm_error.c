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
 *   jvm_error.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements general VM error messages
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include header files
 ****************************************************************************/
#include "kal_release.h"
#include "jal.h"

 /* MIDP Success */
const char *midp_success_msg[] = 
{
    "MIDP success"
};

/* MIDP Persistent Storage Error */
const char *midp_storage_error_msg[] = 
{
    "MIDP filename too long",
    "MIDP storageOpen() failed",
    "MIDP storageClose() failed",
    "MIDP storageRead() failed",
    "MIDP storageWrite() failed",
    "MIDP storage full",
    "MIDP storagePosition() failed",
    "MIDP storageSizeOf() failed",
    "MIDP storageTruncate() failed",
    "MIDP storageDeleteFile() failed",
    "MIDP renamed file does not exist",
    "MIDP storageRenameFile() failed"
};

/* MIDP Comm Protocol Error */
const char *midp_commprotocol_error_msg[] = 
{
    "MIDP open comm port failed",
    "MIDP write comm port failed",
    "MIDP read comm port failed"
};

/* MIDP Connection Exception */
const char *midp_connect_error_msg[] = 
{
    "javax/microedition/io/ConnectionNotFoundException",
    "java/io/IOException",
    "java/lang/IllegalArgumentException"
};

/* Invalid Error Message */
const char *midp_invalid_error_msg[] = 
{
    "MIDP invalid msg"
};

const char **midp_error_msg[] = 
{
    midp_success_msg,
    midp_storage_error_msg,
    midp_commprotocol_error_msg,
    midp_connect_error_msg,
    midp_invalid_error_msg
};


/*****************************************************************************
 * FUNCTION
 *  getErrorMsg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  major_code      [IN]        
 *  minor_code      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *getErrorMsg(midp_error_code major_code, midp_error_code minor_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_trace(TRACE_INFO, J2ME_MSG3, major_code, minor_code); */
    return (char*)midp_error_msg[major_code >> 16][minor_code - major_code];
}

