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
 * mma_mime.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMA mime table for specific handling.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_MIME_C
#define _MMA_MIME_C

#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"

#include "MMI_features.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "wapadp.h"
#include "mmsadp.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

/* APPLIB */
#include "app_mine.h"

/* MSF */
#include "msf_cmmn.h"
#include "msf_mem.h"
#include "msf_int.h"    /*for the msf storage enum */

/* MMS */
#include "mms_def.h"

/* MMA */
#include "mma_def.h"
#include "mma_utilities.h"

char *g_mma_image_mime_string = NULL;
char *g_mma_audio_mime_string = NULL;
char *g_mma_video_mime_string = NULL;

/**********************************************************************
 * Media type definition (base on g_applib_mime_tbl in app_mime.c)
 **********************************************************************/
const applib_mime_type_struct g_mma_usage_exception_tbl[] = 
{
    {"text/css", "css", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSS, MIME_MMI_TYPE},
    {"text/html", "html", MIME_TYPE_APPLICATION, MIME_SUBTYPE_HTML, MIME_MMI_TYPE},
    {"text/vnd.wap.connectivity-xml", "otext", MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_PROV_XML, MIME_MMI_TYPE},
    {"text/vnd.wap.wml", "wml", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WML, MIME_MMI_TYPE},
    {"text/vnd.wap.wmlscript", "wmls", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WMLSCRIPT, MIME_MMI_TYPE},
    {"application/vnd.wap.wmlc", "wmlc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WMLC, MIME_MMI_TYPE},
    {"application/vnd.wap.wmlscriptc", "wmlsc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WMLSC, MIME_MMI_TYPE},
    {"audio/vm", "vm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VM, MIME_MMI_TYPE},
};


/*****************************************************************************
 * FUNCTION
 *  mma_mime_clean_context
 * DESCRIPTION
 *  The function is used to clean context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mime_clean_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_image_mime_string = NULL;
    g_mma_audio_mime_string = NULL;
    g_mma_video_mime_string = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_specified_type_callback
 * DESCRIPTION
 *  The function is used as callback function for applib_mime_traverse
 * PARAMETERS
 *  type_str        [OUT]
 *  type            [IN]
 *  entry           [IN]      
 * RETURNS
 *  KAL_TRUE
 *****************************************************************************/
kal_bool mma_get_mms_specified_type_callback(void *type_str, kal_int32 type, const applib_mime_type_struct *entry)
{
    int e_tbl_size = 0, j = 0;

    e_tbl_size = sizeof(g_mma_usage_exception_tbl) / sizeof(applib_mime_type_struct);

    if (entry->mime_type == (applib_mime_type_enum)type)
    {
        kal_bool exception = KAL_FALSE;

        for (j = 0; j < e_tbl_size; j++)
        {
            if (msf_cmmn_strcmp_nc(g_mma_usage_exception_tbl[j].mime_string, entry->mime_string) == 0)
            {
                exception = KAL_TRUE;
                break;
            }
        }

        if (exception == KAL_FALSE)
        {
            char *old_str = *((char**)type_str);

            *((char**)type_str) = msf_cmmn_str3cat(MSF_MODID_MMA, *((char**)type_str), ",", entry->mime_string);
            MMA_FREE(old_str);
        }
    }
    return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_specified_type
 * DESCRIPTION
 *  The function is used to get MMS image mime type list
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
static char *mma_get_mms_specified_type(applib_mime_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int e_tbl_size = 0, j = 0;
    char *type_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    e_tbl_size = sizeof(g_mma_usage_exception_tbl) / sizeof(applib_mime_type_struct);

    /* Check applib table */
    applib_mime_traverse((void*)&type_str, type, mma_get_mms_specified_type_callback);

    /* Check exception table */
    for (j = 0; j < e_tbl_size; j++)
    {
        if (g_mma_usage_exception_tbl[j].mime_type == type)
        {
            char *old_str = type_str;

            type_str = msf_cmmn_str3cat(MSF_MODID_MMA, type_str, ",", g_mma_usage_exception_tbl[j].mime_string);
            MMA_FREE(old_str);
        }
    }

    return type_str;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_text_type
 * DESCRIPTION
 *  The function is used to get MMS text mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mms_text_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return "text/plain,application/text";
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_image_type
 * DESCRIPTION
 *  The function is used to get MMS image mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mms_image_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_image_mime_string == NULL)
    {
        g_mma_image_mime_string = mma_get_mms_specified_type(MIME_TYPE_IMAGE);
    }
    return g_mma_image_mime_string;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_audio_type
 * DESCRIPTION
 *  The function is used to get MMS image mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mms_audio_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_audio_mime_string == NULL)
    {
        g_mma_audio_mime_string = mma_get_mms_specified_type(MIME_TYPE_AUDIO);
    }
    return g_mma_audio_mime_string;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_video_type
 * DESCRIPTION
 *  The function is used to get MMS video mime type list
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mms_video_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_video_mime_string == NULL)
    {
        g_mma_video_mime_string = mma_get_mms_specified_type(MIME_TYPE_VIDEO);
    }
    return g_mma_video_mime_string;
}
#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_vcard_type
 * DESCRIPTION
 *  The function is used to get MMS vcard mime type
 * PARAMETERS
 *  void
 * RETURNS
 *  mime type string
 *****************************************************************************/

const char *mma_get_mms_vcard_type(void)
{
    return "text/x-vcard";
}
#endif //__MMI_VCARD__

/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_group_from_mime_type
 * DESCRIPTION
 *  Get mime type group from mime type string by referencing APPLIB mime table
 *  (app_mime.c) and MMA exception usage mime table (mma_cfg.h)
 * PARAMETERS
 *  mime_type       [IN]        
 * RETURNS
 *  applib_mime_type_enum
 *****************************************************************************/
applib_mime_type_enum mma_get_mime_group_from_mime_type(char *mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int e_tbl_size = 0, i = 0;
    applib_mime_type_struct *entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mime_type == NULL)
    {
        return MIME_TYPE_NONE;
    }

    e_tbl_size = sizeof(g_mma_usage_exception_tbl) / sizeof(applib_mime_type_struct);
    for (i = 0; i < e_tbl_size; i++)
    {
        if (msf_cmmn_strcmp_nc(g_mma_usage_exception_tbl[i].mime_string, mime_type) == 0)
        {
            return g_mma_usage_exception_tbl[i].mime_type;
        }
    }

    if ((entry = applib_mime_type_look_up((kal_char*) mime_type, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE)) != NULL)
    {
        return entry->mime_type;
    }
    else
    {
        return MIME_TYPE_UNKNOWN;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_mime_init_context
 * DESCRIPTION
 *  The function is used to init context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mime_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_get_mms_image_type();
    mma_get_mms_audio_type();
    mma_get_mms_video_type();

}
#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_MIME_C */ 

