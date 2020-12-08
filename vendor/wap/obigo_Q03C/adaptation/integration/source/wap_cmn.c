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
 *
 * Filename:
 * ---------
 * wap_cmn.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   common APIs
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 10 2010 tarkeswar.roy
 * removed!
 * Production release removal check in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Q03C_IND_MOD_ARCH_SUPPORT
 *
 * removed!
 * removed!
 * Browser V02 checkin!
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Checkin for restore factory enhancement changes!
 *
 * removed!
 * removed!
 * MAUI_00049208, make back up for uis folder
 *
 * removed!
 * removed!
 * Fix bookmark title encoding cuspack issue
 *
 * removed!
 * removed!
 * Fixed push date time info.
 *
 * removed!
 * removed!
 * Checkin changes for EM in Q03C.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Changed for supporting MTK MMS
 *
 * removed!
 * removed!
 * Backup and Restore MMS system folder when restoring factory settings.
 *
 * removed!
 * removed!
 * Backup and Restore MMS system folder when restoring factory settings.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "stdio.h"

#include "kal_release.h"        /* Basic data type */
#include "fat_fs.h"         /* file system */

#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msm_env.h"
#include "msf_file.h"

#include "wap_cmn.h"

#ifdef OBIGO_Q03C_MMS_V01
#include "mea_cfg.h"    /* MEA_FOLDER_PATH */
#endif /* OBIGO_Q03C_MMS_V01 */


/*************************************************************************
* Some helper function for DEBUG_FILE_WITH_INJECTION
*************************************************************************/


//./#ifdef DEBUG_FILE_WITH_INJECTION
/* Justin */
/* from char to \xAB */

/*****************************************************************************
 * FUNCTION
 *  utf8_modify_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]         
 *  src     [?]         
 *  len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void utf8_modify_name(unsigned char *dst, unsigned char *src, int len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < len - 5 && *src)
    {
        if (*src <= 127)
        {
            *dst++ = *src++;
            count++;
        }
        else
        {
            sprintf((char*)dst, "\\x%02x", (int)*src++);
            count += 4;
            dst += 4;
        }
    }
    *dst = 0;
}


/*****************************************************************************
 * FUNCTION
 *  chr_hex_to_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static unsigned char chr_hex_to_num(unsigned char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c >= 'a')
    {
        return c - 'a' + 10;
    }
    if (c >= 'A')
    {
        return c - 'A' + 10;
    }
    return c - '0';
}


/*****************************************************************************
 * FUNCTION
 *  utf8_modify_name_backward
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  src         [?]         
 *  dst_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void utf8_modify_name_backward(unsigned char *dst, unsigned char *src, int dst_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* I'm not sure if UTF-8 contains backslash */
    while (count < dst_len - 2 && *src)
    {
        if (*src == '\\' && *(src + 1) == 'x')
        {
            /* FIXME no error checking here */
            unsigned char byte1 = chr_hex_to_num(*(src + 2));
            unsigned char byte2 = chr_hex_to_num(*(src + 3));

            *dst++ = (unsigned char)(byte1 * 16 + byte2);
            src += 4;
        }
        else
        {
            *dst++ = *src++;
        }
        count++;
    }
    *dst = 0;
}


//./#endif /* DEBUG_FILE_WITH_INJECTION */ 




/*****************************************************************************
 * FUNCTION
 *  wap_reserve_file
 * DESCRIPTION
 *  This function is used to reserve file space for a specified file
 * CALLS
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  filesize        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_reserve_file(const char *filename, kal_uint16 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fd;
    char s[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = MSF_FILE_OPEN(MSF_MODID_MSM, filename, HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING, 0 );

    if (fd < 0)
    {
        fd = MSF_FILE_OPEN(
                MSF_MODID_MSM,
                filename,
                HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                0);
        if (fd < 0)
            ASSERT(0);
                MSF_FILE_SETSIZE(fd, filesize);
        sprintf(s, "%c%c%c", 0xfe, ((filesize - 3) & 0xff00) >> 8, ((filesize - 3) & 0x00ff));
        MSF_FILE_WRITE(fd, s, strlen(s));
        MSF_FILE_CLOSE(fd);
    }
    else
    {
        MSF_FILE_SETSIZE(fd, filesize);
        MSF_FILE_CLOSE(fd);
    }
}


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  wap_delete_all_files
 * DESCRIPTION
 *  This function is used to remove all WAP related files
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_delete_all_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
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
#else
    FS_CreateDir(L"z:\\@wap_bak");
    
	if (FS_GetAttributes(L"z:\\@wap\\msm\\secchksum.dat") >= 0)
    {
        FS_Move(L"z:\\@wap\\msm\\secchksum.dat", L"z:\\@wap_bak\\secchksum.dat",	FS_MOVE_OVERWRITE |	FS_MOVE_COPY, 0, NULL, 0);
    }
	if (FS_GetAttributes(L"z:\\@wap\\msm\\idxchksum.dat") >= 0)
    {
        FS_Move(L"z:\\@wap\\msm\\idxchksum.dat", L"z:\\@wap_bak\\idxchksum.dat",	FS_MOVE_OVERWRITE |	FS_MOVE_COPY, 0, NULL, 0);
    }

    FS_XDelete(L"z:\\@wap\\msm", FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
#if 0
/* under construction !*/
/* under construction !*/
#endif
    FS_XDelete(L"z:\\@wap\\mea", FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    FS_XDelete(L"z:\\@wap\\temp", FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
#endif

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wap_utf8_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcLen      [IN]        
 *  srcStr      [?]         
 *  dstStr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_utf8_to_ucs2(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *tempStr;
    long tempLen = 500, utf8Len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8Len = (long)srcLen;
    tempStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memset(tempStr, 0, tempLen);
    msf_charset_utf8_to_ucs2le((const char*)srcStr, &utf8Len, tempStr, &tempLen);
    *dstStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memcpy(*dstStr, tempStr, tempLen);
    MSF_MEM_FREE(MSF_MODID_MSM, tempStr);
    return (kal_uint16) tempLen;
}


/*****************************************************************************
 * FUNCTION
 *  wap_ucs2_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srcLen      [IN]        
 *  srcStr      [?]         
 *  dstStr      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_ucs2_to_utf8(kal_uint16 srcLen, kal_uint8 *srcStr, char **dstStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *tempStr;
    long tempLen = 500, ucs2Len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2Len = (long)srcLen;
    tempStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen);
    memset(tempStr, 0, tempLen);
    msf_charset_ucs2le_to_utf8((const char*)srcStr, &ucs2Len, tempStr, &tempLen);
    *dstStr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM, tempLen + 1);
    strcpy(*dstStr, tempStr);
    MSF_MEM_FREE(MSF_MODID_MSM, tempStr);
    return (kal_uint16) tempLen;
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_ascii_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL wap_is_ascii_string(const kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for ( ; *str != '\0'; ++str)
    {
        if (*str > 0x7F) {
            return FALSE;
        }
    }
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fix_push_time
 * DESCRIPTION
 *  This function is used by PUSH module in both Obigo & Jataayu to fix invalid push time
 *      datetime[0] = year
 *      datetime[1] = month (1-12)
 *      datetime[2] = day  (1-31)
 *      datetime[3] = hour (0-23)
 *      datetime[4] = min (0-59)
 *      datetime[5] = sec (0-59)
 * PARAMETERS
 *  datetime        [in/out]
 * RETURNS
 *  0       datetime remains unchanged
 *  1       datetime modified
 *****************************************************************************/
int wap_fix_push_time (kal_uint32 datetime[6])
{
    kal_uint32 monthdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int modified = 0;
    
    if (datetime[0] > 2100)
    {
        datetime[0] = 2100;
        datetime[1] = 12;
        datetime[2] = 31;
        modified = 1;
    }
    else if (datetime[0] < 1970)
    {
        datetime[0] = 1970;
        datetime[1] = 12;
        datetime[2] = 31;
        modified = 1;
    }
    if (datetime[1] > 12 || datetime[1] < 1)
    {
        datetime[1] = 12;
        modified = 1;
    }
    monthdays[1] += (!(datetime[0]%400) || (datetime[0]%100 && !(datetime[0]%4)));
    if (datetime[2] > monthdays[datetime[1]-1] || datetime[2] < 1)
    {
        datetime[2] = monthdays[datetime[1]-1];
        modified = 1;
    }

    if (datetime[3] > 23)
    {
        datetime[3] = 0;
        modified = 1;
    }
    if (datetime[4] > 59)
    {
        datetime[4] = 0;
        modified = 1;
    }
    if (datetime[5] > 59)
    {
        datetime[5] = 0;
        modified = 1;
    }

    return modified;
}


