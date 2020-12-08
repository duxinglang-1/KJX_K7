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
 *  EmailSrvUtil.c
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
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "che_api.h"
#include "Conversions.h"
#include "emlst_miscell.h"
#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "app_datetime.h"
#include "gui_data_types.h"
#include "app_str.h"
#include "Ctype.h"    // toupper
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"

#define SRV_EMAIL_CHECKSUM_START        (0xffff)
#define srv_email_checksum_fcs(fcs, c)  ((fcs >> 8) ^ email_stor_fcstab[(fcs ^ c) & 0x00ff])

#define SRV_EMAIL_TMP_CTRLBUF_SIZE      (2048)


const kal_int8 Index_hex_ext[128] = 
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

const kal_int8 Index_64_ext[128] = 
{
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
        52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
        -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
        -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1
};
/* Header Encoding Macros (RFC 2047) */
#define email_hexval_ext(c) Index_hex_ext[(kal_uint32)(c)]
#define email_base64val_ext(c) Index_64_ext[(kal_uint32)(c)]

/* FCS tab, for calculate CHECKSUM */
static const unsigned short email_stor_fcstab[256] = 
{
    0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf, 0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5,
    0xe97e, 0xf8f7, 0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e, 0x9cc9, 0x8d40, 0xbfdb, 0xae52,
    0xdaed, 0xcb64, 0xf9ff, 0xe876, 0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd, 0xad4a, 0xbcc3,
    0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5, 0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
    0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974, 0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9,
    0x2732, 0x36bb, 0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3, 0x5285, 0x430c, 0x7197, 0x601e,
    0x14a1, 0x0528, 0x37b3, 0x263a, 0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72, 0x6306, 0x728f,
    0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9, 0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
    0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738, 0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862,
    0x9af9, 0x8b70, 0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7, 0x0840, 0x19c9, 0x2b52, 0x3adb,
    0x4e64, 0x5fed, 0x6d76, 0x7cff, 0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036, 0x18c1, 0x0948,
    0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e, 0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
    0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd, 0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226,
    0xd0bd, 0xc134, 0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c, 0xc60c, 0xd785, 0xe51e, 0xf497,
    0x8028, 0x91a1, 0xa33a, 0xb2b3, 0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb, 0xd68d, 0xc704,
    0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232, 0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
    0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1, 0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb,
    0x0e70, 0x1ff9, 0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330, 0x7bc7, 0x6a4e, 0x58d5, 0x495c,
    0x3de3, 0x2c6a, 0x1ef1, 0x0f78
};

/*****************************************************************************
 * FUNCTION
 *  srv_email_checksum_compute_by_hd
 * DESCRIPTION
 *  Compute a file's checksum by FS handle
 * PARAMETERS
 *  hd                  [IN]        FS handle
 *  position            [IN]        
 *  start_offset(?)     [IN]        Start offset
 * RETURNS
 *  checksum
 *****************************************************************************/
EMAIL_CHECKSUM srv_email_checksum_compute_by_hd(FS_HANDLE hd, U32 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_CHECKSUM checksum = SRV_EMAIL_CHECKSUM_START;
    U8 *buf = NULL;
    U32 i, read;
    S32 retval;
    U32 alloc_size = SRV_EMAIL_TMP_CTRLBUF_SIZE * 6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (alloc_size = SRV_EMAIL_TMP_CTRLBUF_SIZE * 10;
         alloc_size > 0 && buf == NULL;
         alloc_size -= SRV_EMAIL_TMP_CTRLBUF_SIZE)
    {
        buf = srv_email_mem_alloc(alloc_size);
    }
    ASSERT(buf != NULL);

    //kal_prompt_trace("[EmailSrvUtil] checksum buffer size:%d", alloc_size);
    //buf = (U8*) get_ctrl_buffer(SRV_EMAIL_TMP_CTRLBUF_SIZE);
    FS_Seek(hd, position, FS_FILE_BEGIN);

    while (MMI_TRUE)
    {
        retval = FS_Read(hd, buf, alloc_size, &read);
        if (retval < FS_NO_ERROR || read == 0)
        {
            break;
        }

        for (i = 0; i < read; i++)
        {
            checksum = (EMAIL_CHECKSUM) srv_email_checksum_fcs(checksum, buf[i]);
        }
    }

    //free_ctrl_buffer((void*)buf);
    srv_email_mem_free(buf);
    return checksum;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_checksum_compute_by_buffer
 * DESCRIPTION
 *  Compute checksum by buffer
 * PARAMETERS
 *  buf                 [IN]        buffer
 *  len                 [IN]        length of buffer
 * RETURNS
 *  checksum
 *****************************************************************************/
EMAIL_CHECKSUM srv_email_checksum_compute_by_buffer(const U8* buf, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    EMAIL_CHECKSUM checksum = SRV_EMAIL_CHECKSUM_START;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; ++i)
    {
        checksum = (EMAIL_CHECKSUM)srv_email_checksum_fcs(checksum, buf[i]);
    }

    return checksum;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_checksum_read_by_hd
 * DESCRIPTION
 *  Read checksum by FS handle
 * PARAMETERS
 *  hd              [IN]        FS handle
 *  position        [IN]        
 *  checksum        [OUT]       Checksum
 *  offset(?)       [IN]        MSG offset
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_checksum_read_by_hd(FS_HANDLE hd, U32 position, EMAIL_CHECKSUM *checksum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Seek(hd, position, FS_FILE_BEGIN);
    FS_Read(hd, checksum, sizeof(EMAIL_CHECKSUM), &read);
    if (read != sizeof(EMAIL_CHECKSUM))
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_checksum_write_by_hd
 * DESCRIPTION
 *  Write checksum to file by FS handle
 * PARAMETERS
 *  hd              [IN]        Handle
 *  position        [IN]        
 *  checksum        [IN]        Checksum
 *  offset(?)       [IN]        MSG offset
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_checksum_write_by_hd(FS_HANDLE hd, U32 position, EMAIL_CHECKSUM checksum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 written = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Seek(hd, position, FS_FILE_BEGIN);
    FS_Write(hd, &checksum, sizeof(EMAIL_CHECKSUM), &written);
    if (written != sizeof(EMAIL_CHECKSUM))
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_file_chset_convert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  The message handle.
 ****************************************************************************/
srv_email_result_enum srv_email_file_chset_convert(
    const WCHAR *src_path, const CHAR *src_chset_s,
    const WCHAR *dst_path, const CHAR *dst_chset_s,
    S32 *minor_errno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE src_file_handle;
    FS_HANDLE dst_file_handle;
    CHAR *src_buff = NULL;
    CHAR *dst_buff = NULL;
    CHAR *temp_pos = NULL;
    S32 result;
    U32 read, write, len, convert_len;
    U32 end_pos = 0;
    U32 src_len = 0;
    mmi_chset_enum src_chset;
    mmi_chset_enum dst_chset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_path == NULL || dst_path == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    src_file_handle = FS_Open(src_path, FS_READ_ONLY);
    if (src_file_handle < 0)
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    dst_file_handle = FS_Open(dst_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (dst_file_handle < 0)
    {
        FS_Close(src_file_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    src_buff = (CHAR*)get_ctrl_buffer(1024 + 2);
    if (src_buff == NULL)
    {
        FS_Close(src_file_handle);
        FS_Close(dst_file_handle);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    dst_buff = (CHAR*)get_ctrl_buffer(1024 + 2);
    if (dst_buff == NULL)
    {
        free_ctrl_buffer(src_buff);
        FS_Close(src_file_handle);
        FS_Close(dst_file_handle);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(src_buff, 0, 1024 + 2);
    src_chset = (mmi_chset_enum)email_get_charset_enum((kal_int8*)src_chset_s);
    dst_chset = (mmi_chset_enum)email_get_charset_enum((kal_int8*)dst_chset_s);
    temp_pos = src_buff;
    len = 1024;
    while (1)
    {
        result = FS_Read(src_file_handle, temp_pos, len, &read);
        src_len += read;
        if (result != FS_NO_ERROR)
        {
            free_ctrl_buffer(src_buff);
            free_ctrl_buffer(dst_buff);
            FS_Close(src_file_handle);
            FS_Close(dst_file_handle);
			*minor_errno = result;
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        memset(dst_buff, 0, 1024 + 2);
        convert_len = mmi_chset_convert_ex(
						src_chset,
						dst_chset,
            src_buff,
            dst_buff,
            1024,
            &end_pos);
		if (dst_chset == CHSET_UCS2 && dst_buff[convert_len-1] == 0 && dst_buff[convert_len-2] == 0)
		{
			convert_len -= 2; // remove the null terminal \0
		} 
        else if (dst_buff[convert_len-1] == 0)
		{
			--convert_len;
		}

        result = FS_Write(dst_file_handle, dst_buff, convert_len, &write);
        if (result != FS_NO_ERROR || write != convert_len)
        {
            free_ctrl_buffer(src_buff);
            free_ctrl_buffer(dst_buff);
            FS_Close(src_file_handle);
            FS_Close(dst_file_handle);
			*minor_errno = result;
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        temp_pos = src_buff;

        // move the left buffer from the tail to the head
        while (end_pos - (U32)src_buff < src_len)
        {
            *temp_pos = *((CHAR*)end_pos);
            temp_pos++;
            (end_pos)++;
        }

        // calculate the left buffer
        src_len = (U32)(temp_pos - src_buff);
        if ((src_len == 0 && len != read) || read == 0)
        {
            // in the tail, some buffer cannot be converted, so just write them...
            if (src_len != 0)
            {
                FS_Write(dst_file_handle, src_buff, src_len, &write);
            }

            free_ctrl_buffer(src_buff);
            free_ctrl_buffer(dst_buff);
            FS_Close(src_file_handle);
            FS_Close(dst_file_handle);
            return SRV_EMAIL_RESULT_SUCC; /* reach the end */
        }

        len = 1024 - ((U32)temp_pos - (U32)src_buff);
        memset(temp_pos, 0, len);
    }
    //return  SRV_EMAIL_RESULT_SUCC;
}

typedef struct
{
    FS_HANDLE src_file_handle;
    FS_HANDLE dst_file_handle;
    CHAR src_buff[1024 + 2];
    CHAR dst_buff[1024 + 2];
    U32 len;
    S32 chset;
    U32 end_pos;
    CHAR *temp_pos;
    U32 src_len;
    S32 *minor_errno;
    S32 aborted;
    EMAIL_REQ_ID schdl_job_id;

    mmi_proc_func callback;
    void* userdata;
} srv_email_file_chset_cvt_async_struct;

void srv_email_file_convert_run(void *userdata);

srv_email_result_enum srv_email_file_chset_convert_async(
                        WCHAR *src_path,
                        CHAR *src_chset,
                        WCHAR *dst_path,
                        mmi_proc_func callback,
                        void* userdata,
                        U32 *convert_handle,
                        S32 *minor_errno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_file_chset_cvt_async_struct* convert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(src_path != NULL && dst_path != NULL);

    convert = srv_email_mem_alloc(sizeof(*convert));
    if (convert == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(convert, 0, sizeof(*convert));

    convert->src_file_handle = FS_Open(src_path, FS_READ_ONLY);
    if (convert->src_file_handle < 0)
    {
        *minor_errno = convert->src_file_handle;
        srv_email_mem_free(convert);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    convert->dst_file_handle = FS_Open(dst_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (convert->dst_file_handle < 0)
    {
        *minor_errno = convert->src_file_handle;
        FS_Close(convert->src_file_handle);
        srv_email_mem_free(convert);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    convert->chset = email_get_charset_enum((kal_int8 *)src_chset);
    convert->temp_pos = convert->src_buff;
    convert->len = 1024;
    convert->callback = callback;
    convert->userdata = userdata;

    *convert_handle = (U32)convert;

    convert->schdl_job_id = srv_email_schdl_start_job(
                                srv_email_file_convert_run, convert);
    
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

void srv_email_file_convert_abort(U32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_file_chset_cvt_async_struct* convert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    convert = (srv_email_file_chset_cvt_async_struct*)handle;

    ASSERT(convert->aborted == 0);
    convert->aborted = 1;
    if (convert->src_file_handle != FS_INVALID_HANDLE)
    {
        FS_Close(convert->src_file_handle);
    }
    if (convert->dst_file_handle != FS_INVALID_HANDLE)
    {
        FS_Close(convert->dst_file_handle);
    }

    srv_email_schdl_stop_job(convert->schdl_job_id);

    srv_email_mem_free(convert);
}

void srv_email_file_convert_run(void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 read;
    U32 write;
    srv_email_file_chset_cvt_async_struct* convert;
    U32 start_tick;
    U32 end_tick;
    srv_email_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    convert = (srv_email_file_chset_cvt_async_struct*)userdata;

    ASSERT(convert->aborted == 0);

    kal_get_time(&start_tick);

    while (1)
    {
        result = FS_Read(convert->src_file_handle, convert->temp_pos,
                                  convert->len, &read);
        convert->src_len += read;
        if (result != FS_NO_ERROR)
        {
            ret = SRV_EMAIL_RESULT_FS_ERROR;
            goto EXIT;
        }
        mmi_chset_convert_ex(
            (mmi_chset_enum)convert->chset,
            CHSET_UTF8,
            convert->src_buff,
            convert->dst_buff,
            1024,
            &convert->end_pos);
        result = FS_Write(convert->dst_file_handle,
                         convert->dst_buff, strlen(convert->dst_buff), &write);
        if (result != FS_NO_ERROR || write != strlen(convert->dst_buff))
        {
            ret = SRV_EMAIL_RESULT_FS_ERROR;
            goto EXIT;
        }
        convert->temp_pos = convert->src_buff;
        while (convert->end_pos - (U32)convert->src_buff < convert->src_len)
        {
            *(convert->temp_pos) = *((CHAR*)convert->end_pos);
            convert->temp_pos++;
            (convert->end_pos)++;
        }
        convert->src_len = (U32)(convert->temp_pos - convert->src_buff);
        if (convert->len != read || read == 0)
        {
            ret = SRV_EMAIL_RESULT_SUCC;
            goto EXIT;
        }
        convert->len = 1024 - ((U32)convert->temp_pos - (U32)convert->src_buff);
        memset(convert->temp_pos, 0, convert->len);

        kal_get_time(&end_tick);

        if (end_tick - start_tick >= KAL_TICKS_100_MSEC * 2)
        {
            convert->schdl_job_id = srv_email_schdl_start_job(
                                srv_email_file_convert_run, convert);
            return;
        }
    }

EXIT:
    FS_Close(convert->src_file_handle);
    convert->src_file_handle = FS_INVALID_HANDLE;
    FS_Close(convert->dst_file_handle);
    convert->dst_file_handle = FS_INVALID_HANDLE;
    convert->aborted = 1;
    if (convert->callback != NULL)
    {
        srv_email_file_chset_cvt_async_event_struct param;
        param.result = ret;
        param.error_code = result;
        param.user_data = convert->userdata;
        param.evt_id = (U16)EVT_ID_SRV_EMAIL_FILE_CONVERT_DONE;
        convert->callback((mmi_event_struct*)&param);
    }
    srv_email_mem_free(convert);
}

void srv_email_compute_md5(const CHAR *input, S32 input_len, U8* digest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static STCHE che_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    che_init(&che_cntx, CHE_MD5);
    che_process(
        &che_cntx,
        CHE_MD5,
        CHE_MODE_NULL,
        CHE_HASH,
        (U8*)input,
        digest,
        input_len,
        KAL_TRUE);
    che_deinit(&che_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_util_dir_exist
 * DESCRIPTION
 *  To check whether this directory exist
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
S32 srv_email_util_dir_exist(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (hd == FS_FILE_NOT_FOUND)
    {
        return 0;
    }
    if (hd >= FS_NO_ERROR)
    {
    FS_Close(hd);
        return 1;
    }
    return hd;  /* it's FS's error, eg. FS_FAT_ALLOC_ERROR */
}


S32 srv_email_util_file_exist_ext(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = FS_Open(path, FS_READ_ONLY);
    if (hd == FS_FILE_NOT_FOUND)
    {
        return 0;
    }
    if (hd >= FS_NO_ERROR)
    {
        FS_Close(hd);
        return 1;
    }
    return hd;  /* it's FS's error, eg. FS_FAT_ALLOC_ERROR */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_util_file_exist
 * DESCRIPTION
 *  To check whether file exist
 * PARAMETERS
 *  path        [IN]        Path
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_email_util_file_exist(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((hd = FS_Open(path, FS_READ_ONLY)) < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }
    FS_Close(hd);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_is_date_time_valid
 * DESCRIPTION
 *  This function is used to check if the date and time are valid or not.
 * PARAMETERS
 *  date_time_p     [IN]        The pointer point to the date and time
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_email_is_date_time_valid(applib_time_struct *date_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!date_time_p ||
        date_time_p->nYear == 0 ||
        date_time_p->nMonth == 0 ||
        date_time_p->nMonth > 12 ||
        date_time_p->nDay == 0 ||
        date_time_p->nDay > 31 ||
        date_time_p->nHour > 23 ||
        date_time_p->nMin > 59 ||
        date_time_p->nSec > 59)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_set_default_date_time
 * DESCRIPTION
 *  This function is used to set the date and time to default value.
 * PARAMETERS
 *  date_time_p     [OUT]       The pointer point to the date and time
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_set_default_date_time(applib_time_struct *date_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (date_time_p)
    {
        date_time_p->nYear = 2000;
        date_time_p->nMonth = 1;
        date_time_p->nDay = 1;
        date_time_p->nHour = 0;
        date_time_p->nMin = 0;
        date_time_p->nSec = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_revise_date_time
 * DESCRIPTION
 *  This function is used to revise the date and time.
 * PARAMETERS
 *  date_time_p     [IN/OUT]    The pointer point to the date and time
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_revise_date_time(applib_time_struct *date_time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (date_time_p)
    {
        if (date_time_p->nYear > 2030)
        {
            date_time_p->nYear = 2030;
            date_time_p->nMonth = 12;
            date_time_p->nDay = 31;
            date_time_p->nHour = 23;
            date_time_p->nMin = 59;
            date_time_p->nSec = 59;
        }
        if (date_time_p->nYear < 1970)
        {
            date_time_p->nYear = 1970;
            date_time_p->nMonth = 1;
            date_time_p->nDay = 1;
            date_time_p->nHour = 0;
            date_time_p->nMin = 0;
            date_time_p->nSec = 0;
        }
    }
}


S32 srv_email_util_check_space_is_enough(CHAR drv_letter, S32 req_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((WCHAR*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret < 0)
    {
        return fs_ret;  /* FS_ERROR */
    }

    disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
    {
        return 1;   /* free space is enough */
    }

    return 0;       /* NO enough free space */
}


void srv_email_string_decode(WCHAR *src_str, WCHAR *dst_str, S32 *str_len, S32 *str_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 charset = -1;
    kal_int32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_str == NULL || dst_str == NULL || str_len == NULL)
    {
        return;
    }
    if (strlen((char*)src_str) > 0)
    {
        if (strstr((char*)src_str, "=?") != NULL)
        {
            email_rfc2047_decode_ext((kal_uint8**)&src_str, &charset);
            if (charset < 0)
            {
                charset = CHSET_ASCII;
            }
        }
        else
        {
            charset = CHSET_ASCII;
        }

        if (str_charset)
        {
            *str_charset = (S32)charset;
        }

        if (charset > CHSET_BASE && charset < CHSET_TOTAL)
        {
            mmi_chset_convert((mmi_chset_enum)charset,
                              MMI_CHSET_UCS2,
                              (CHAR*)src_str,
                              (CHAR*)dst_str,
                              *str_len);
            *str_len = mmi_wcslen(dst_str);
        }
        else
        {
            len = strlen((char*)src_str);
            if (len <= *str_len - 2)
            {
                memcpy(dst_str, src_str, len);
                ((CHAR*)dst_str)[len] = 0;
                ((CHAR*)dst_str)[len + 1] = 0;
                *str_len = mmi_wcslen(dst_str);
            }
            else
            {
                memcpy(dst_str, src_str, *str_len - 2);
                ((CHAR*)dst_str)[*str_len - 1] = 0;
                ((CHAR*)dst_str)[*str_len - 2] = 0;
                *str_len = mmi_wcslen(dst_str);
            }
        }
    }
    else
    {
        if (str_len)
        {
            *str_len = 0;
        }
        strcpy((char*)dst_str, "");
        if (str_charset)
        {
            *str_charset = CHSET_ASCII;
        }
    }
    dst_str[*str_len] = 0;
    return;
}


void email_rfc2047_decode_ext(kal_uint8 **pd, kal_int32 *w_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *e_word1, *e_word2;
    U32 n;
    kal_int32 found_encoded = 0;
    kal_uint8 *d_word, *dptr;
    const kal_uint8 *s = *pd;
    U32 dlen;
    U32 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *w_charset = -1;
    if (!s || !*s)
    {
        return;
    }
    dlen = 4 * strlen((CHAR*)s);   /* should be enough */
    dptr = d_word = srv_email_mem_alloc((kal_uint16)(dlen + 1));
    if (dptr == NULL)
    {
        return;
    }
    while (*s && dlen > 0)
    {
        e_word1 = (const kal_uint8*)email_find_encoded_word((kal_char*)s, (const kal_char**)&e_word2);
        if (!e_word1)
        {
            /* no encoded words */
            strncpy((CHAR*)dptr, (CHAR*)s, dlen);
            dptr += dlen;
            break;
        }
        if (e_word1 != s)
        {
            n = (U32)(e_word1 - s);
            /* ignore spaces between encoded words */
            if (!found_encoded || strspn((CHAR*)s, " \t\r\n") != n)
            {
                if (n > dlen)
                {
                    n = dlen;
                }
                memcpy(dptr, s, n);
                dptr += n;
                dlen -= n;
                str_len += n;
            }
        }
        email_rfc2047_decode_word_ext((kal_int8*)dptr, (kal_int8*)e_word1, dlen, w_charset);
        found_encoded = 1;
        s = e_word2;
        n = strlen((CHAR*)dptr);
        dlen -= n;
        dptr += n;
        str_len += n;
    }

    memcpy(*pd, d_word, strlen((CHAR*)d_word));
    (*pd)[strlen((CHAR*)d_word)] = 0;
    srv_email_mem_free(d_word);
}


kal_int32 email_rfc2047_decode_word_ext(kal_int8 *d, const kal_int8 *s, U32 len, kal_int32 *w_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_int8 *pp = s, *pp1;
    kal_int8 *dptr, *d_word1;
    const kal_int8 *t, *t1;
    kal_int32 enc = 0, count = 0, c1, c2, c3, c4;
    kal_int8 *charset = NULL;

    U32 d_len;
    kal_uint16 s_len = strlen((CHAR*)s);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dptr = d_word1 = (kal_int8*)srv_email_mem_alloc(s_len);
    pp = s;
    while (1)
    {
        if (count >= 4)
        {
            break;
        }
        pp1 = (kal_int8*)strchr((CHAR*)pp, '?');
        if (!pp1)
        {
            break;
        }
        count++;
        switch (count)
        {
            case 2:
                /* ignore language specification a la RFC 2231 */
                t = pp1;
                t1 = memchr(pp, '*', t - pp);
                if (t1)
                {
                    t = t1;
                }
                charset = (kal_int8*)srv_email_mem_alloc((kal_uint16)(t - pp + 1));
                memcpy(charset, pp, t - pp);
                charset[t - pp] = '\0';
                break;
            case 3:
                if (toupper(*pp) == 'Q')
                {
                    enc = EMAIL_MIME_ENCQUOTPRINT;
                }
                else if (toupper(*pp) == 'B')
                {
                    enc = EMAIL_MIME_ENCBASE64;
                }
                else
                {
                    srv_email_mem_free(charset);
                    srv_email_mem_free(d_word1);
                    return (-1);
                }
                break;
            case 4:
                if (enc == EMAIL_MIME_ENCQUOTPRINT)
                {
                    while (pp < pp1 && len > 0)
                    {
                        if (*pp == '_')
                        {
                            *dptr++ = ' ';
                            len--;
                        }
                        else if (*pp == '=')
                        {
                            if (pp[1] == 0 || pp[2] == 0)
                            {
                                break;  /* something wrong */
                            }
                            *dptr++ = (email_hexval_ext(pp[1]) << 4) | email_hexval_ext(pp[2]);
                            len--;
                            pp += 2;
                        }
                        else
                        {
                            *dptr++ = *pp;
                            len--;
                        }
                        pp++;
                    }
                    *dptr = 0;
                }
                else if (enc == EMAIL_MIME_ENCBASE64)
                {
                    while (pp < pp1 && len > 0)
                    {
                        if (pp[0] == '=' || pp[1] == 0 || pp[1] == '=')
                        {
                            break;  /* something wrong */
                        }
                        c1 = email_base64val_ext(pp[0]);
                        c2 = email_base64val_ext(pp[1]);
                        *dptr++ = (c1 << 2) | ((c2 >> 4) & 0x3);
                        if (--len == 0)
                        {
                            break;
                        }

                        if (pp[2] == 0 || pp[2] == '=')
                        {
                            break;
                        }

                        c3 = email_base64val_ext(pp[2]);
                        *dptr++ = ((c2 & 0xf) << 4) | ((c3 >> 2) & 0xf);
                        if (--len == 0)
                        {
                            break;
                        }
                        if (pp[3] == 0 || pp[3] == '=')
                        {
                            break;
                        }
                        c4 = email_base64val_ext(pp[3]);
                        *dptr++ = ((c3 & 0x3) << 6) | c4;
                        if (--len == 0)
                        {
                            break;
                        }
                        pp += 4;
                    }
                    *dptr = 0;
                }
                break;
        }   /* switch */
        pp = pp1 + 1;
    }       /* while */
    d_len = strlen((CHAR*)d_word1);
    if (d_len > len)
    {
        srv_email_mem_free(charset);
        srv_email_mem_free(d_word1);
        return -1;
    }
    memcpy(d, d_word1, d_len);
    d[d_len] = '\0';
    if (*w_charset == -1)
    {
        *w_charset = email_get_charset_enum(charset);
    }
    srv_email_mem_free(charset);
    srv_email_mem_free(d_word1);
    return 0;
}

/*
  Example:
  in:           abcd.jpg
  out:          ab.jpg
  limit_len:    5
*/
void srv_email_handle_file_name(WCHAR* out, WCHAR* in, U32 limit_len)
{
    U32 ext_len;
    U32 name_len;
    S32 ext_pos;

    name_len = mmi_wcslen(in);

    if (name_len <= limit_len)
    {
        mmi_wcscpy(out, in);
        return;
    }

    ext_pos = srv_fmgr_path_get_extension_pos(in);

    // not extension
    if (ext_pos < 0)
    {
        mmi_wcsncpy(out, in, limit_len);
        return;
    }

    // + 1 for '.'
    ext_len = name_len - ext_pos + 1;

    // copy the first part of file name
    mmi_wcsncpy(out, in, limit_len - ext_len);

    // attach the extension
    mmi_wcscat(out, in + name_len - ext_len);
}

const CHAR * srv_email_util_get_mime_type_str(chset_enum charset)
{
    const kal_int8 *charset_str = chset_get_preferred_mime_name(charset);

    if (charset_str == NULL)
    {
        return "unspported";
    }

    return (CHAR *)charset_str;
}
