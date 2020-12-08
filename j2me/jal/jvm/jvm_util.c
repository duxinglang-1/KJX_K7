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
 *   jvm_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements jvm utilities
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "jal.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_internal.h"
#include "FS_func.h"
// #include "FS_kal.h"
#include "app_str.h"
#include "drm_gprot.h"
#include "drm_def.h"
#include "FileMgrGProt.h"
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)

#define BITS_FOR_SECOND 5
#define BITS_FOR_MINITES 6
#define BITS_FOR_HOURS 5
#define BITS_FOR_DAY 5
#define BITS_FOR_MONTH 4
#define BITS_FOR_YEAR 7
#define MASK_4 0x0f
#define MASK_5 0x1f
#define MASK_6 0x3f
#define MASK_7 0x7f

#define MAX_PATH_LEN 50
#define MAX_FILE_NAME_SIZE 50
#define MAX_FILE_NUM 5
#define MAX_DIR_NUM 5

#define RUN_PER_RECEIVE_QUEUE 5



const static kal_char midlet_msg_file_maker[4] = {0x04, 0x03, 0x4b, 0x50};
const static kal_char midlet_msg_dir_maker[4] = {0x02, 0x01, 0x4b, 0x50};
const static kal_char midlet_msg_trailer_maker[4] = {0x06, 0x05, 0x4b, 0x50};
const static kal_char midlet_msg_ZI[12] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#define TEMP_DECODED_FILE_PREFIX "midlet_msg_temp_file_"
#define TEMP_DECODED_FILE_POSTFIX ".z"
#define MIDLET_MESSAGE_FOLDER  L"C:\\@java\\MidletMessage\\"

typedef struct
{
    kal_uint32 hours;
    kal_uint32 minutes;
    kal_uint32 seconds;

} jvm_util_time_struct;

typedef struct
{
    kal_uint32 year;
    kal_uint32 month;
    kal_uint32 day;

} jvm_util_date_struct;

typedef struct
{
    kal_uint16 LastModTime;
    kal_uint16 LastModDate;
    kal_uint32 CRC32;
    kal_uint32 SizeCompressed;
    kal_uint32 SizeUncompressed;
    kal_uint16 PathnameLength;
    kal_char *Pathname;

} jvm_util_zip_file_struct;

typedef struct
{
    kal_uint16 LastModTime;
    kal_uint16 LastModDate;
    kal_uint32 CRC32;
    kal_uint32 SizeCompressed;
    kal_uint32 SizeUncompressed;
    kal_uint16 PathnameLength;
    kal_uint32 Offset;
    kal_char *Pathname;

} jvm_util_zip_dir_struct;

/*****************************************************************************************/
/*                    Start of Queue                                                     */
/*****************************************************************************************/

#define Q_MAX 10
typedef struct
{
    kal_wchar full_path[MAX_WCHAR_FILENAME_LEN];
    kal_wchar related_path[15]; /* /META-INF/ is the max str length currently */

} jvm_util_queue_element_struct;

typedef struct
{
    jvm_util_queue_element_struct *element[Q_MAX];
    kal_uint32 front;
    kal_uint32 rear;

} jvm_util_queue_struct;

static jvm_util_queue_struct jvm_midlet_msg_parse_Q;
kal_int32 g_jam_741_index = 0;


/*****************************************************************************
 * FUNCTION
 *  jvm_util_queue_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Q           [?]         
 *  ele         [IN]        
 *  full        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_util_queue_insert(jvm_util_queue_struct *Q, jvm_util_queue_element_struct ele, kal_bool *full)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*full) = KAL_FALSE;
    Q->rear = (Q->rear + 1) % Q_MAX;
    if (Q->rear == Q->front)
    {
        (*full) = KAL_TRUE;
        return;
    }
    Q->element[Q->rear] = (jvm_util_queue_element_struct*) jam_listmem_malloc(sizeof(jvm_util_queue_element_struct));
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
    memcpy((Q->element[Q->rear]), &ele, sizeof(jvm_util_queue_element_struct));
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_queue_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Q           [?]     
 *  ele         [?]     
 *  empty       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_util_queue_delete(jvm_util_queue_struct *Q, jvm_util_queue_element_struct *ele, kal_bool *empty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*empty) = KAL_FALSE;
    if (Q->front == Q->rear)
    {
        (*empty) = KAL_TRUE;
        return;
    }
    Q->front = (Q->front + 1) % Q_MAX;
    memcpy(ele, (Q->element[Q->front]), sizeof(jvm_util_queue_element_struct));
    jam_listmem_free(Q->element[Q->front]);
    Q->element[Q->front] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_queue_is_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Q       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_queue_is_full(jvm_util_queue_struct *Q)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 rear = (Q->rear + 1) % Q_MAX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rear == Q->front)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_queue_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Q       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_queue_is_empty(jvm_util_queue_struct *Q)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Q->rear == Q->front)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************************/
/*                    Endo of Queue                                                      */
/*****************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  jvm_util_time_to_short
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 jvm_util_time_to_short(jvm_util_time_struct time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((time.hours >> BITS_FOR_HOURS) == 0);
    ASSERT((time.minutes >> BITS_FOR_MINITES) == 0);
    ASSERT((time.seconds >> BITS_FOR_SECOND) == 0);

    ret = time.seconds;
    ret <<= BITS_FOR_MINITES;
    ret |= time.minutes;
    ret <<= BITS_FOR_HOURS;
    ret |= time.hours;

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_short_to_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jvm_util_time_struct jvm_util_short_to_time(kal_uint16 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_util_time_struct ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret.hours = (kal_uint32) input & MASK_5;
    input >>= BITS_FOR_HOURS;
    ret.minutes = (kal_uint32) input & MASK_6;
    input >>= BITS_FOR_MINITES;
    ret.seconds = (kal_uint32) input & MASK_5;

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_date_to_short
 * DESCRIPTION
 *  
 * PARAMETERS
 *  date        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 jvm_util_date_to_short(jvm_util_date_struct date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((date.year >> BITS_FOR_YEAR) == 0);
    ASSERT((date.month >> BITS_FOR_MONTH) == 0);
    ASSERT((date.day >> BITS_FOR_DAY) == 0);

    ret = date.day;
    ret <<= BITS_FOR_MONTH;
    ret |= date.month;
    ret <<= BITS_FOR_YEAR;
    ret |= date.year;

    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_short_to_date
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jvm_util_date_struct jvm_util_short_to_date(kal_uint16 input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_util_date_struct ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret.year = (kal_uint32) input & MASK_7;
    input >>= BITS_FOR_YEAR;
    ret.month = (kal_uint32) input & MASK_4;
    input >>= BITS_FOR_MONTH;
    ret.day = (kal_uint32) input & MASK_5;

    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_crc32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jvm_util_crc32(kal_wchar *path, kal_bool decJar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 jar_file_hdlr;
    kal_uint32 crc;
    kal_uint32 file_size;
    kal_uint32 scan_off = 0;
    kal_int32 read_bytes;
    kal_char *buffer = NULL;
    kal_int32 path_len;
    kal_int32 run = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path_len = get_ucs2_len(path);
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
#endif
    {
        jar_file_hdlr = jvm_file_open_as_normal_file(path, FS_READ_ONLY);
    }
    
    if (jar_file_hdlr == -1)
    {
        /* error */
        return (0);
    }
    buffer = jam_listmem_malloc(1024);

    if (buffer == NULL)
    {
        /* error */
        jvm_file_close(jar_file_hdlr);
        return (0);
    }
    
    if( jvm_file_getsize(jar_file_hdlr, &file_size) != 1)
    {
        jam_listmem_free(buffer);
        jvm_file_close(jar_file_hdlr);
        /* error */
        return (0);
    }
        
    crc = 0;

    while (scan_off < file_size)
    {
        if (run == 0)
        {
            if (J2ME_GET_NEXT_EVENT_ABORT==clean_event())
        	{
        		jam_listmem_free(buffer);
                jvm_file_close(jar_file_hdlr);
                /* error */
                return (0);
            }
        } 
        read_bytes = jvm_file_read(jar_file_hdlr, buffer, 1024);
        if( read_bytes == -1)
        {
            jam_listmem_free(buffer);
            jvm_file_close(jar_file_hdlr);
            /* error */
            return (0);
        }

        crc = jvm_util_update_crc(crc, buffer, read_bytes);
        
        scan_off += 1024;
        run ++;
        run %= RUN_PER_RECEIVE_QUEUE;
    }  
    
    jam_listmem_free(buffer);
    jvm_file_close(jar_file_hdlr);
    return crc;
}



/*****************************************************************************
 * FUNCTION
 *  jvm_util_check_zero_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff        [?]         
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_check_zero_buff(kal_char *buff, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < size; i++)
    {
        if (buff[i] != 0)
            return KAL_FALSE;
    }
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_enc_midlet_msg_write_file_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_entry_header       [IN]        
 *  idx                     [IN]        
 *  mids_msg_name           [?]         
 *  file_path               [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_util_enc_midlet_msg_write_file_entry(
            jvm_util_zip_file_struct file_entry_header,
            kal_uint32 idx,
            kal_wchar *mids_msg_name,
            kal_wchar *file_path,
            kal_bool decJar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 midlet_msg_file_hdlr = 0;
    kal_int32 jar_file_hdlr = 0;
    kal_uint8 *buffer = NULL;
    kal_uint32 write_bytes, read_bytes;
    kal_uint32 total_jar_write_bytes = 0;
    kal_int32 scan_off = 0;
    kal_uint32 file_size;
    kal_int32 file_path_len;
    kal_int32 result = PACKAGE_FAIL;
    kal_int32 run = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_ENC_MIDLET_MSG_WRITE_FILE_ENTRY,g_jam_741_index);
    if (!idx)   /* the first entry */
    {
        midlet_msg_file_hdlr = FS_Open((const WCHAR*)mids_msg_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    }
    else
    {
        midlet_msg_file_hdlr = FS_Open((const WCHAR*)mids_msg_name, FS_READ_WRITE);
    }
    if(midlet_msg_file_hdlr ==FS_ROOT_DIR_FULL){
        result = ROOT_DIR_FULL;
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_ENC_MIDLET_MSG_WRITE_FILE_ENTRY,g_jam_741_index);
        goto write_file_enrty_error;
    }

    FS_Seek(midlet_msg_file_hdlr, 0, FS_FILE_END);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_file_maker, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 6, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.LastModTime, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.LastModDate, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.CRC32, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.SizeCompressed, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.SizeUncompressed, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_header.PathnameLength, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)file_entry_header.Pathname, file_entry_header.PathnameLength, &write_bytes);

    buffer = jam_listmem_malloc(1024);
	if(buffer == NULL)
	{
	    goto write_file_enrty_error;
	}
    file_path_len = get_ucs2_len(file_path);
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
#endif
    {
        jar_file_hdlr = jvm_file_open_as_normal_file(file_path, FS_READ_ONLY);
    }
    if (jar_file_hdlr == -1)
    {
        goto write_file_enrty_error;
    }

    if( jvm_file_getsize(jar_file_hdlr, &file_size) != 1)
    {
        goto write_file_enrty_error;
    }
    
    while (scan_off < file_entry_header.SizeCompressed)
    {
        /* to detect if user press cancel */
        if (run == 0)
        {
            if (J2ME_GET_NEXT_EVENT_ABORT==clean_event())
        	{
        	    result = USER_CANCEL;
        		goto write_file_enrty_error;
            }
        }       
        read_bytes = jvm_file_read(jar_file_hdlr, buffer, 1024);
        if( read_bytes == -1)
        {
            goto write_file_enrty_error;
        }
        if(FS_Write(midlet_msg_file_hdlr, (void*)buffer, read_bytes, &write_bytes) != FS_NO_ERROR)
        {
            goto write_file_enrty_error;
        }
        scan_off += 1024;
        total_jar_write_bytes += write_bytes; 
        run ++;
        run %= RUN_PER_RECEIVE_QUEUE;
    } 
    ASSERT(total_jar_write_bytes == file_entry_header.SizeCompressed);
    result = J2ME_NO_ERROR;

write_file_enrty_error:
    if (buffer)
    {
        jam_listmem_free(buffer);
    }
    if (jar_file_hdlr != -1)
    {
        jvm_file_close(jar_file_hdlr);
    }
    if (midlet_msg_file_hdlr > 0)
    {
        FS_Close(midlet_msg_file_hdlr);
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_enc_midlet_msg_write_dir_enrty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_entry           [IN]        
 *  mids_msg_name       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_enc_midlet_msg_write_dir_enrty(jvm_util_zip_dir_struct dir_entry, kal_wchar *mids_msg_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 midlet_msg_file_hdlr;
    kal_uint32 write_bytes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_ENC_MIDLET_MSG_WRITE_DIR_ENTRY,g_jam_741_index);
    midlet_msg_file_hdlr = FS_Open((const WCHAR*)mids_msg_name, FS_READ_WRITE);

    FS_Seek(midlet_msg_file_hdlr, 0, FS_FILE_END);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_dir_maker, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 8, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.LastModTime, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.LastModDate, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.CRC32, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.SizeCompressed, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.SizeUncompressed, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.PathnameLength, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 12, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry.Offset, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)dir_entry.Pathname, dir_entry.PathnameLength, &write_bytes);
    FS_Close(midlet_msg_file_hdlr);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_enc_midlet_msg_write_dir_trailer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_no              [IN]        
 *  dir_entry_size      [IN]        
 *  file_entry_size     [IN]        
 *  mids_msg_name       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_enc_midlet_msg_write_dir_trailer(
            kal_uint32 dir_no,
            kal_uint32 dir_entry_size,
            kal_uint32 file_entry_size,
            kal_wchar *mids_msg_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 midlet_msg_file_hdlr;
    kal_uint32 write_bytes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_ENC_MIDLET_MSG_WRITE_DIR_TRAILER,g_jam_741_index);
    midlet_msg_file_hdlr = FS_Open((const WCHAR*)mids_msg_name, FS_READ_WRITE);

    FS_Seek(midlet_msg_file_hdlr, 0, FS_FILE_END);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_trailer_maker, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_no, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_no, 2, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&dir_entry_size, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)&file_entry_size, 4, &write_bytes);
    FS_Write(midlet_msg_file_hdlr, (void*)midlet_msg_ZI, 2, &write_bytes);

    FS_Close(midlet_msg_file_hdlr);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_midlet_msg_encode_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix_root         [?]     
 *  root                [?]     
 *  mids_msg_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_util_midlet_msg_encode_internal(kal_wchar *mids_msg_name, kal_bool decJar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_util_zip_file_struct file_entry_header;
    jvm_util_zip_dir_struct *dir_list[MAX_DIR_NUM] = {0};
    kal_uint32 dir_number = 0;

    kal_wchar *filename = NULL;
    FS_DOSDirEntry info = {0};
    jvm_util_queue_element_struct pth;
    
    kal_bool isEmpty = KAL_FALSE;
    kal_uint32 total_file_entry_size = 0;
    kal_uint32 total_dir_entry_size = 0;

    kal_wchar *related_path_for_file = NULL;
    kal_wchar *full_path_for_file = NULL;
    kal_wchar *related_path_for_dir= NULL;
    
    kal_int32 f_hdlr;
    kal_uint16 i;
    kal_uint16 full_path_len;
    jvm_util_time_struct ftime;
    jvm_util_date_struct fdate;

    kal_int32 result = PACKAGE_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_ENCODE_INTERNAL,g_jam_741_index);
    while (!jvm_util_queue_is_empty(&jvm_midlet_msg_parse_Q))
    {

        jvm_util_queue_delete(&jvm_midlet_msg_parse_Q, &pth, &isEmpty);

        full_path_for_file = jam_listmem_malloc((get_ucs2_len(pth.full_path)+1)<<1);
        if (full_path_for_file == NULL)
        {
            goto midlet_msg_encode_internal_error;
        }
        app_ucs2_wcscpy((kal_wchar*) full_path_for_file, (kal_wchar*) pth.full_path);

        related_path_for_dir = jam_listmem_malloc((get_ucs2_len(pth.related_path)+1)<<1);
        if (related_path_for_dir == NULL)
        {
            goto midlet_msg_encode_internal_error;
        }
        app_ucs2_wcscpy((kal_wchar*) related_path_for_dir, (kal_wchar*) pth.related_path);

        full_path_len = get_ucs2_len(pth.full_path);
        for (i = full_path_len; i > 0 ; i--)
        {
            if (pth.full_path[i] == '\\')
            {
                break;
            }
        }
        filename = (kal_wchar *)jam_listmem_malloc((full_path_len - i + 1)<<1);
        if (filename == NULL)
        {
            goto midlet_msg_encode_internal_error;
        }
        app_ucs2_wcscpy((kal_wchar*) filename, (kal_wchar*) &pth.full_path[i+1]);

        related_path_for_file = (kal_wchar *)jam_listmem_malloc((get_ucs2_len(related_path_for_dir) + get_ucs2_len(filename) +1)<<1);
        if (related_path_for_file == NULL)
        {
            goto midlet_msg_encode_internal_error;
        }
        app_ucs2_wcscpy((kal_wchar*) related_path_for_file, (kal_wchar*) related_path_for_dir);
        app_ucs2_wcscat((kal_wchar*) related_path_for_file, (kal_wchar*) filename);
        jam_listmem_free(filename);
        filename = NULL;

        ftime.hours = info.DateTime.Hour;
        ftime.minutes = info.DateTime.Minute;
        ftime.seconds = info.DateTime.Second2;
        file_entry_header.LastModTime = jvm_util_time_to_short(ftime);

        fdate.year = info.DateTime.Year1980;
        fdate.month = info.DateTime.Month;
        fdate.day = info.DateTime.Day;
        file_entry_header.LastModDate = jvm_util_date_to_short(fdate);

        file_entry_header.CRC32 = jvm_util_crc32(full_path_for_file,decJar);

        if (file_entry_header.CRC32 == 0)
        {
            /* user cancel */
            g_jam_741_index++;
            kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_ENCODE_INTERNAL_1,g_jam_741_index);
            return USER_CANCEL;
        }

        if ((f_hdlr = FS_Open(full_path_for_file, FS_READ_ONLY)) < 0)
        {
            /* file does not exist */
            g_jam_741_index++;
            kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_ENCODE_INTERNAL_2, f_hdlr,g_jam_741_index);
            return PACKAGE_FAIL;
        }
        FS_GetFileSize(f_hdlr, &(file_entry_header.SizeCompressed));
        FS_Close(f_hdlr);
        file_entry_header.SizeUncompressed = file_entry_header.SizeCompressed;

        file_entry_header.PathnameLength = app_ucs2_wcslen((kal_wchar*) related_path_for_file);
        file_entry_header.Pathname = (kal_char*) jam_listmem_malloc(file_entry_header.PathnameLength + 1);
        
        trans_ucs2_to_utf8(file_entry_header.Pathname, related_path_for_file);

        dir_list[dir_number] = (jvm_util_zip_dir_struct*) jam_listmem_malloc(sizeof(jvm_util_zip_dir_struct));
        dir_list[dir_number]->LastModTime = file_entry_header.LastModTime;
        dir_list[dir_number]->LastModDate = file_entry_header.LastModDate;
        dir_list[dir_number]->CRC32 = file_entry_header.CRC32;
        dir_list[dir_number]->SizeCompressed = file_entry_header.SizeCompressed;
        dir_list[dir_number]->SizeUncompressed = file_entry_header.SizeUncompressed;

        dir_list[dir_number]->PathnameLength = app_ucs2_wcslen((kal_wchar*) related_path_for_dir);
        dir_list[dir_number]->Pathname = (kal_char*) jam_listmem_malloc(dir_list[dir_number]->PathnameLength + 1);
        
        trans_ucs2_to_utf8(dir_list[dir_number]->Pathname, related_path_for_dir);
        result =jvm_util_enc_midlet_msg_write_file_entry(
           file_entry_header,
           dir_number,
           mids_msg_name,
           full_path_for_file,
           decJar);
        if (result != J2ME_NO_ERROR)
        {
            g_jam_741_index++;
            kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_ENCODE_INTERNAL_3, result,g_jam_741_index);
            goto midlet_msg_encode_internal_error;
        }

        jam_listmem_free(related_path_for_file);
        related_path_for_file = NULL;
        jam_listmem_free(full_path_for_file);
        full_path_for_file = NULL;
        jam_listmem_free(related_path_for_dir);
        related_path_for_dir = NULL;
        jam_listmem_free(file_entry_header.Pathname);
        file_entry_header.Pathname = NULL;
        if (dir_number == 0)
        {
            dir_list[dir_number]->Offset = 0;
        }
        else
        {
            dir_list[dir_number]->Offset = dir_list[dir_number - 1]->Offset + 30 +      /* fixed part of entry */
               file_entry_header.PathnameLength + file_entry_header.SizeCompressed;
        }

        dir_number++;
    
    }
    total_file_entry_size = dir_list[dir_number - 1]->Offset + 30 +     /* fixed part of entry */
        file_entry_header.PathnameLength + file_entry_header.SizeCompressed;

    total_dir_entry_size = 0;
    for (i = 0; i < dir_number; i++)
    {
        jvm_util_enc_midlet_msg_write_dir_enrty((*dir_list[i]), mids_msg_name);
        total_dir_entry_size += (46 + dir_list[i]->PathnameLength);

    }
    jvm_util_enc_midlet_msg_write_dir_trailer(dir_number, total_dir_entry_size, total_file_entry_size, mids_msg_name);

    result = J2ME_NO_ERROR;

midlet_msg_encode_internal_error:

    if (filename)
    {
        jam_listmem_free(filename);
    }
    if (related_path_for_file)
    {
        jam_listmem_free(related_path_for_file);
    }
    if (full_path_for_file)
    {
        jam_listmem_free(full_path_for_file);
    }
    if (related_path_for_dir)
    {
        jam_listmem_free(related_path_for_dir);
    }
    for (i = 0; i < Q_MAX; i++)
    {
        if (jvm_midlet_msg_parse_Q.element[i])
        {
            jam_listmem_free(jvm_midlet_msg_parse_Q.element[i]);
        }
        jvm_midlet_msg_parse_Q.element[i] = NULL;
        jvm_midlet_msg_parse_Q.front = 0;
        jvm_midlet_msg_parse_Q.rear = 0;
    }

    for (i = 0; i < MAX_DIR_NUM; i++)
    {
        if (dir_list[i])
        {
            if (dir_list[i]->Pathname)
            {
                jam_listmem_free(dir_list[i]->Pathname);
            }
            jam_listmem_free(dir_list[i]);
            dir_list[i] = NULL;
        }
    }
    if (file_entry_header.Pathname)
    {
        jam_listmem_free(file_entry_header.Pathname);
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_midlet_msg_encode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix_root         [?]     
 *  root                [?]     
 *  mids_msg_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_util_midlet_msg_encode(
            kal_wchar *manifest_path, 
            kal_wchar *jad_path, 
            kal_wchar *jar_path,
            kal_wchar *mids_msg_name,
            kal_bool decJar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_util_queue_element_struct pth;
    kal_bool isFull = KAL_FALSE;
    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_ENCODE,g_jam_741_index);
    if (manifest_path == NULL || jad_path == NULL || jar_path == NULL || mids_msg_name == NULL)
    {
        ASSERT(0);
    }
    /* clear Queue to prevent error */
    for (i = 0; i < Q_MAX; i++)
    {
        if (jvm_midlet_msg_parse_Q.element[i])
        {
            jam_listmem_free(jvm_midlet_msg_parse_Q.element[i]);
        }
        jvm_midlet_msg_parse_Q.element[i] = NULL;
        jvm_midlet_msg_parse_Q.front = 0;
        jvm_midlet_msg_parse_Q.rear = 0;
    }
    
    app_ucs2_wcscpy((kal_wchar*) pth.full_path, (kal_wchar*) manifest_path);
    kal_wsprintf(pth.related_path,"/META-INF/");
    jvm_util_queue_insert(&jvm_midlet_msg_parse_Q, pth, &isFull);
    if (isFull)
    {
        ASSERT(0);
    }

    app_ucs2_wcscpy((kal_wchar*) pth.full_path, (kal_wchar*) jad_path);
    kal_wsprintf(pth.related_path,"/");
    jvm_util_queue_insert(&jvm_midlet_msg_parse_Q, pth, &isFull);
    if (isFull)
    {
        ASSERT(0);
    }
    
    app_ucs2_wcscpy((kal_wchar*) pth.full_path, (kal_wchar*) jar_path);
    kal_wsprintf(pth.related_path,"/");
    jvm_util_queue_insert(&jvm_midlet_msg_parse_Q, pth, &isFull);
    if (isFull)
    {
        ASSERT(0);
    }
    return jvm_util_midlet_msg_encode_internal(mids_msg_name,decJar);
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_package_midlet_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  jad_path                [?]     
 *  jar_path                [?]     
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar* jvm_util_package_midlet_message(kal_wchar* jad_path, kal_wchar* jar_path, kal_wchar* output_dir, kal_bool decJar, kal_int32 *error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_wchar* mids_name;
    kal_wchar* manifest_name = L"Manifest.mf";
    kal_wchar* manifest_path = NULL;
    kal_wchar* midlet_message_path = NULL;
    kal_int32 path_len;
    kal_uint32 written_len;
    kal_int32 jad_scanPos;
    kal_int32 jar_scanPos;
    kal_wchar* jar_name = L".jar";
    kal_char* temp_path_utf8;
    kal_int32 temp_len;
    kal_wchar* midlet_message_dir = output_dir;
    kal_int64 free_space;
    kal_uint32 jad_size;
    kal_uint32 jar_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE,g_jam_741_index);
    /* we do not support decJar = KAL_TRUE */
    ASSERT(decJar == KAL_FALSE);
    /* check space is enough */
    if (output_dir[0] == '\0')
    {
        free_space = jvm_file_get_free_space(jar_path[0]);
    }
    else
    {
        free_space = jvm_file_get_free_space(output_dir[0]);
    }
    handle = FS_Open(jad_path, FS_READ_ONLY); 
    FS_GetFileSize(handle, &jad_size);
    FS_Close(handle);
    handle = FS_Open(jar_path, FS_READ_ONLY); 
    FS_GetFileSize(handle, &jar_size);
    FS_Close(handle);
    if (free_space < jad_size + jar_size + 3* 2048)
    {
        *error = INSUFFICIENT_STORAGE;
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_1, free_space, jad_size, jar_size, g_jam_741_index);
        return NULL;
    }
    
    mids_name = jam_get_mids_name(jad_path,SRV_FMGR_PATH_MAX_FILE_NAME_LEN - 4); /* .jar length = 4 */
    if (mids_name == NULL)
    {
        /* invalid jad */
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_2,g_jam_741_index);
        return NULL;
    }
    if (output_dir == NULL)
    {
        midlet_message_dir = MIDLET_MESSAGE_FOLDER;
    }
    path_len = get_ucs2_len(midlet_message_dir) + get_ucs2_len(mids_name) + 6; /* "\\" + ".jar" + "\0" */ 
    midlet_message_path = jam_listmem_malloc(path_len<<1);
    if (midlet_message_path == NULL)
    {
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_3,g_jam_741_index);
        return NULL; 
    }
    mmi_ucs2cpy((S8*)midlet_message_path, (S8*)midlet_message_dir);
    
    if (output_dir == NULL)
    {
        /* we put midlet message to the same driver's @java */
        midlet_message_path[0] = jar_path[0];
        if (check_and_create_hidden_folder(midlet_message_path) != FS_NO_ERROR)
        {
            /* if create fail, it usually insufficient storage */
            *error = INSUFFICIENT_STORAGE;
            g_jam_741_index++;
            kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_4,g_jam_741_index);
            return NULL;
        }
    }
    //mmi_ucs2cat((S8*)midlet_message_path,(S8*)L"\\");
    mmi_ucs2cat((S8*)midlet_message_path,(S8*)mids_name);
    mmi_ucs2cat((S8*)midlet_message_path,(S8*)jar_name);
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
#endif
    path_len = strlen(work_sys_dir_path) + get_ucs2_len(manifest_name) + 2;
    manifest_path = jam_listmem_malloc(path_len<<1);
    if (manifest_path == NULL)
    {
        jam_listmem_free(midlet_message_path);
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_3,g_jam_741_index);
        return NULL; 
    } 
    kal_wsprintf(manifest_path, "%s\\\0", work_sys_dir_path);
    mmi_ucs2cat((S8*)manifest_path,(S8*)manifest_name);
    handle = FS_Open(manifest_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (handle < 0)
    {
        jam_listmem_free(manifest_path);
        jam_listmem_free(midlet_message_path);
        g_jam_741_index++;
        kal_trace(TRACE_FUNC, JVM_UTIL_PACKAGE_MIDLET_MESSAGE_5, handle,g_jam_741_index);
        return NULL;
    }
    FS_Write(handle, "Distribution-Package: 1.0\n", 26, &written_len);
    FS_Write(handle, "Distribution-Descriptor-Filename: ", 34, &written_len);
    /* change to Mids name need ?*/
    jad_scanPos = get_ucs2_len(jad_path);
    while (jad_path[jad_scanPos] != '/' && jad_path[jad_scanPos] != '\\' &&  jad_scanPos > 0)
    {
         jad_scanPos--;
    }
    temp_len = get_ucs2_len(&jad_path[jad_scanPos+1]);
    temp_path_utf8 = jam_listmem_malloc(temp_len+1);
    trans_ucs2_to_utf8(temp_path_utf8, &jad_path[jad_scanPos+1]);

    FS_Write(handle, temp_path_utf8, temp_len, &written_len);
    FS_Write(handle, "\n", 1, &written_len);
    jam_listmem_free(temp_path_utf8); 

    FS_Write(handle, "Distribution-Content-Filename: ", 31, &written_len);

    jar_scanPos = get_ucs2_len(jar_path);
    while (jar_path[jar_scanPos] != '/' && jar_path[jar_scanPos] != '\\' &&  jar_scanPos > 0)
    {
         jar_scanPos--;
    }

    temp_len = get_ucs2_len(&jar_path[jar_scanPos+1]);
    temp_path_utf8 = jam_listmem_malloc(temp_len+1);
    trans_ucs2_to_utf8(temp_path_utf8, &jar_path[jar_scanPos+1]);
    
    FS_Write(handle,temp_path_utf8, temp_len, &written_len);
    FS_Write(handle, "\n", 1, &written_len);
    jam_listmem_free(temp_path_utf8);
    
    FS_Close(handle);
    *error = jvm_util_midlet_msg_encode(manifest_path,jad_path,jar_path,midlet_message_path,decJar);
    if (*error != J2ME_NO_ERROR)
    {
        jam_listmem_free(manifest_path);
        jam_listmem_free(midlet_message_path);
        return NULL;
    }
    jam_listmem_free(manifest_path);
    return midlet_message_path;
    
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_path_to_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]         
 *  folder      [?]         
 *  count       [?]         
 *  limit       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_path_to_folder(
            kal_wchar *path,
            kal_wchar folder[MAX_DIR_NUM][MAX_FILE_NAME_SIZE],
            kal_uint32 *count,
            kal_uint32 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *start_ptr = path;
    kal_wchar *end_ptr = path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*count) = 0;

    if (limit == 0)
    {
        return KAL_TRUE;
    }

    /* last char must be '\' */
    ASSERT(path[app_ucs2_wcslen((const kal_wchar*)path) - 1] == L'\\');

    while (*end_ptr != L'\0')
    {
        if (*end_ptr == L'\\')
        {
            kal_uint32 len = (kal_uint32) (end_ptr - start_ptr);

            /* don't allow contain "\\" patern */
            ASSERT(len != 0);

            app_ucs2_wcsncpy((kal_wchar*) folder[(*count)], (const kal_wchar*)start_ptr, len);
            (*count)++;

            /* start_ptr = end_ptr; */

            if ((*count) >= limit)
            {
                return KAL_FALSE;
            }
        }
        end_ptr++;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_dec_midlet_msg_get_next_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_hdlr               [IN]        
 *  isFile                  [?]         
 *  dir_entry_header        [?]         
 *  file_entry_header       [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_dec_midlet_msg_get_next_entry(
            kal_int32 file_hdlr,
            kal_bool *isFile,
            kal_bool *discard,
            jvm_util_zip_dir_struct *dir_entry_header,
            jvm_util_zip_file_struct *file_entry_header,
            midlet_message_content_type_enum specify_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buf[12]; /* maxium check buffer is 12 */
    kal_uint32 read_bytes;
    kal_wchar *fileType = NULL;
    kal_wchar *ucs2_file_name = NULL;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*discard) = KAL_FALSE;
    FS_Read(file_hdlr, (void*)buf, 4, &read_bytes);

    if (!strncmp(midlet_msg_file_maker, buf, 4))
    {
        FS_Read(file_hdlr, (void*)buf, 6, &read_bytes);
        if (!jvm_util_check_zero_buff(buf, 6))
        {
            return KAL_FALSE;
        }
        FS_Read(file_hdlr, (void*)&(file_entry_header->LastModTime), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)&(file_entry_header->LastModDate), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)&(file_entry_header->CRC32), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(file_entry_header->SizeCompressed), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(file_entry_header->SizeUncompressed), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(file_entry_header->PathnameLength), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)buf, 2, &read_bytes);
        if (!jvm_util_check_zero_buff(buf, 2))
        {
            return KAL_FALSE;
        }
        file_entry_header->Pathname = (kal_char*) jam_listmem_malloc(file_entry_header->PathnameLength+1);
        if (file_entry_header->Pathname == NULL)
        {
            ASSERT(0);
        }
        FS_Read(file_hdlr, (void*)file_entry_header->Pathname, (file_entry_header->PathnameLength), &read_bytes);
        file_entry_header->Pathname[file_entry_header->PathnameLength] = '\0';

        ucs2_file_name = jam_listmem_malloc((file_entry_header->PathnameLength+1)<<1);
        if (ucs2_file_name == NULL)
        {
            return KAL_FALSE;
        }
        trans_utf8_to_ucs2(ucs2_file_name, file_entry_header->Pathname);
        (*isFile) = KAL_TRUE;
        if (specify_type)
        {
            for (i = file_entry_header->PathnameLength-1; i >= 0; i--)
            {
                if (ucs2_file_name[i] == L'.')
                {
                    break;
                }
            }
            if (i == -1)
            {
                jam_listmem_free(ucs2_file_name);
                return KAL_FALSE;
            }

            fileType = jam_listmem_malloc((file_entry_header->PathnameLength-i+1)<<1);
            if (fileType == NULL)
            {
                jam_listmem_free(ucs2_file_name);
                return KAL_FALSE;
            }

            app_ucs2_wcscpy(fileType,&ucs2_file_name[i+1]);

            switch (specify_type)
            {
                case JVM_MIDLET_MESSAGE_JAD:
                    if (!(app_ucs2_wcscmp(fileType,L"jad") == 0 || app_ucs2_wcscmp(fileType,L"JAD") == 0))
                    {
                        *discard = KAL_TRUE; 
                    }
                    break;
                case JVM_MIDLET_MESSAGE_JAR:
                    if (!(app_ucs2_wcscmp(fileType,L"jar") == 0 || 
                            app_ucs2_wcscmp(fileType,L"JAR") == 0 ||
                            app_ucs2_wcscmp(fileType,L"dcf") == 0 ||
                            app_ucs2_wcscmp(fileType,L"DCF") == 0))
                    {
                        *discard = KAL_TRUE; 
                    }
                    break;
                case JVM_MIDLET_MESSAGE_MANIFEST:
                    if (!(app_ucs2_wcscmp(fileType,L"mf") == 0 || app_ucs2_wcscmp(fileType,L"MF") == 0))
                    {
                        *discard = KAL_TRUE;
                    }
                    break;
                default:
                    ASSERT(0);                         
            }
            jam_listmem_free(ucs2_file_name);
            jam_listmem_free(fileType);    
        }
        return KAL_TRUE;
    }
    else if (!strncmp(midlet_msg_dir_maker, buf, 4))
    {
        FS_Read(file_hdlr, (void*)buf, 8, &read_bytes);
        if (!jvm_util_check_zero_buff(buf, 8))
        {
            return KAL_FALSE;
        }
        FS_Read(file_hdlr, (void*)&(dir_entry_header->LastModTime), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)&(dir_entry_header->LastModDate), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)&(dir_entry_header->CRC32), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(dir_entry_header->SizeCompressed), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(dir_entry_header->SizeUncompressed), 4, &read_bytes);
        FS_Read(file_hdlr, (void*)&(dir_entry_header->PathnameLength), 2, &read_bytes);
        FS_Read(file_hdlr, (void*)buf, 12, &read_bytes);
        if (!jvm_util_check_zero_buff(buf, 12))
        {
            return KAL_FALSE;
        }
        FS_Read(file_hdlr, (void*)&(dir_entry_header->Offset), 4, &read_bytes);
        dir_entry_header->Pathname = (kal_char*) jam_listmem_malloc(dir_entry_header->PathnameLength + 1);
        if (dir_entry_header->Pathname == NULL)
        {
            ASSERT(0);
        }
        FS_Read(file_hdlr, (void*)(dir_entry_header->Pathname), (dir_entry_header->PathnameLength), &read_bytes);
        dir_entry_header->Pathname[dir_entry_header->PathnameLength] = L'\0';
        (*isFile) = KAL_FALSE;
       
        return KAL_TRUE;
    }
    else if (!strncmp(midlet_msg_trailer_maker, buf, 4))
    {
        return KAL_FALSE;
    }
    
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_dec_midlet_msg_wrtie_to_temp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_hdlr       [IN]        
 *  size            [IN]        
 *  id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_util_dec_midlet_msg_wrtie_to_temp_file(
            kal_int32 file_hdlr, 
            kal_uint32 size, 
            kal_uint32 id , 
            kal_wchar *specify_file_name,
            kal_uint32 CRC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 temp_file_hdlr = -1;
    kal_char *buffer;
    kal_uint32 read_bytes;
    kal_int32 scan_off = 0;
    kal_int32 read_size;
    kal_uint32 CRC_check = 0;
    kal_int32 result = DISK_OPERATION_FAIL;
    kal_int32 run = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_DEC_MIDLET_MSG_WRITE_TO_TEMP_FILE,g_jam_741_index);
    if (specify_file_name)
    {
        //trans_ucs2_to_utf8(temp_file_name, specify_file_name);
        temp_file_hdlr = jvm_file_open_with_path(specify_file_name, O_CREAT | O_TRUNC | O_WRONLY);
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
#endif
    buffer = jam_listmem_malloc(1024);
	if(buffer == NULL)
	{
        goto wrtie_to_temp_file_error;
    }
    
    while (scan_off < size)
    {
        if (run == 0)
        {
            if (J2ME_GET_NEXT_EVENT_ABORT==clean_event())
        	{
        	    result = USER_CANCEL;
        		goto wrtie_to_temp_file_error;
            }
        } 
        if (size - scan_off < 1024)
        {
            read_size = size - scan_off;
        }
        else
        {
            read_size = 1024;
        }
        if (FS_Read(file_hdlr, (void*)buffer, read_size, &read_bytes) != FS_NO_ERROR)
        {
            goto wrtie_to_temp_file_error;
        }
        if( jvm_file_write(temp_file_hdlr, buffer, read_bytes) == -1)
        {
            goto wrtie_to_temp_file_error;
        }
        scan_off += 1024;
        run ++;
        run %= RUN_PER_RECEIVE_QUEUE;
    } 
    jvm_file_close(temp_file_hdlr);

    /* check CRC */
    /* because we never use the case of non-specify_file_name, it can be implement later */
    if (specify_file_name)
    {
        CRC_check = jvm_util_crc32(specify_file_name, KAL_FALSE);
        if (CRC_check != CRC)
        {
            g_jam_741_index++;
            kal_trace(TRACE_FUNC, JVM_UTIL_DEC_MIDLET_MSG_WRITE_TO_TEMP_FILE_1,g_jam_741_index);
            goto wrtie_to_temp_file_error;
        }
    }
    result = J2ME_NO_ERROR;
wrtie_to_temp_file_error:
    if (buffer)
    {
        jam_listmem_free(buffer);
    }
    if (temp_file_hdlr != -1)
    {
        jvm_file_close(temp_file_hdlr);
    }
    
    return result;

}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_dec_midlet_msg_build_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix      [?]     
 *  path        [?]     
 * RETURNS
 *  
 *****************************************************************************/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  jvm_util_dec_midlet_msg_check_trailer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_hdlr           [IN]        
 *  entry_num           [?]         
 *  dir_entry_size      [?]         
 *  file_size           [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_dec_midlet_msg_check_trailer(
            kal_int32 file_hdlr,
            kal_uint16 *entry_num,
            kal_uint32 *dir_entry_size,
            kal_uint32 *file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buf[4];
    kal_uint32 read_bytes;
    kal_uint16 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_DEC_MIDLET_MSG_CHECK_TRAILER,g_jam_741_index);
    FS_Read(file_hdlr, (void*)buf, 4, &read_bytes);
    if (!jvm_util_check_zero_buff(buf, 4))
    {
        return KAL_FALSE;
    }

    FS_Read(file_hdlr, (void*)entry_num, 2, &read_bytes);
    FS_Read(file_hdlr, (void*)&temp, 2, &read_bytes);
    if (temp != (*entry_num))
    {
        return KAL_FALSE;
    }
    FS_Read(file_hdlr, (void*)dir_entry_size, 4, &read_bytes);
    FS_Read(file_hdlr, (void*)file_size, 4, &read_bytes);

    FS_Read(file_hdlr, (void*)buf, 2, &read_bytes);
    if (!jvm_util_check_zero_buff(buf, 2))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_dec_midlet_msg_copy_to_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix          [?]         
 *  target_file     [?]         
 *  id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
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
#endif
/*****************************************************************************
 * FUNCTION
 *  jvm_util_midlet_msg_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  decoded_file_path       [?]     
 *  midlet_msg_path         [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_util_midlet_msg_decode(
            kal_wchar *decoded_file_path, 
            kal_wchar *midlet_msg_path, 
            midlet_message_content_type_enum specfiy_type)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_util_zip_file_struct file_entry_header;
    jvm_util_zip_dir_struct dir_entry_header;

    kal_bool isFile;
    kal_bool discard;
    kal_int32 midlet_msg_file_hdlr;
    kal_uint32 i;
    kal_wchar *file_name[MAX_FILE_NUM];
    //kal_uint32 file_offset[MAX_FILE_NUM];

    kal_uint32 file_entry_number = 0;

    kal_uint32 file_size;
    kal_uint16 file_number;
    kal_uint32 dir_entry_size;
    kal_int32 len;
    kal_wchar *specify_file_name = NULL;
    kal_wchar *decoded_file_path2;
    kal_int32 result = DISK_OPERATION_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_MIDLET_MSG_DECODE, specfiy_type,g_jam_741_index);
    /* if decoded_file_path is not a folder, we think it is specify file name */
    len = get_ucs2_len(decoded_file_path);
    decoded_file_path2 = jam_listmem_malloc((len+1)<<1);
    if (decoded_file_path2 == NULL)
    {
        ASSERT(0);
    }
    memcpy(decoded_file_path2,decoded_file_path,(len+1)<<1);
    
    if (decoded_file_path2[len-1] != L'\\')
    {
        specify_file_name = jam_listmem_malloc((len+1)<<1);
        memcpy(specify_file_name,decoded_file_path,(len+1)<<1);
        
        for (i = len-1; i > 0; i--)
        {
            if (decoded_file_path2[i] == L'\\')
            {
                decoded_file_path2[i+1] = L'\0';
                break;
            }
        }
    }
    midlet_msg_file_hdlr = FS_Open((const WCHAR*)midlet_msg_path, FS_READ_ONLY);

    while (jvm_util_dec_midlet_msg_get_next_entry(
              midlet_msg_file_hdlr, 
              &isFile, 
              &discard, 
              &dir_entry_header, 
              &file_entry_header,specfiy_type))
    {
        if (!discard)
        {
            if (isFile)
            {
                result = jvm_util_dec_midlet_msg_wrtie_to_temp_file(
                    midlet_msg_file_hdlr,
                    file_entry_header.SizeCompressed,
                    file_entry_number,
                    specify_file_name,
                    file_entry_header.CRC32);
                if(result != J2ME_NO_ERROR)
                {
                    break;
                }
                /* we don't need build folder now */
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
            }
            else
            {   
                /* we don't need build folder now */
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
            }
        }
        else
        {
            if (isFile)
            {
                FS_Seek(midlet_msg_file_hdlr,file_entry_header.SizeCompressed,FS_FILE_CURRENT);
            }
        }
    }
    for (i = 0; i < file_entry_number; i++)
    {
        if (file_name[i])
        {
            jam_listmem_free(file_name[i]);
            file_name[i] = NULL;
        }
    }
    jam_listmem_free(decoded_file_path2);
    if (specify_file_name)
    {
        jam_listmem_free(specify_file_name);
        specify_file_name = NULL;
    }
    if (result == USER_CANCEL || !jvm_util_dec_midlet_msg_check_trailer(midlet_msg_file_hdlr, &file_number, &dir_entry_size, &file_size))
    {
        FS_Close(midlet_msg_file_hdlr);
        return result;
    }

    /* check size and offset */

    /* jvm_util_dec_midlet_msg_check_file_end(); */

    FS_Close(midlet_msg_file_hdlr);
    result = J2ME_NO_ERROR;
    return result;
#else
    return DISK_OPERATION_FAIL;
#endif
}
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
/*****************************************************************************
 * FUNCTION
 *  jvm_util_midlet_msg_decode_JAR
 * DESCRIPTION
 *  
 * PARAMETERS
 *  decoded_file_path       [?]     
 *  midlet_msg_path         [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_util_is_midlet_msg_file(kal_wchar *midlet_msg_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 midlet_msg_file_hdlr;
    kal_char *context = NULL;
    jvm_util_zip_file_struct file_entry_header;
    jvm_util_zip_dir_struct dir_entry_header;
    kal_bool isFile;
    kal_bool discard;
    kal_uint32 read_bytes;
    kal_char *verno = NULL;
    kal_bool result = KAL_FALSE;
    kal_bool entry_found = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (midlet_msg_path == NULL)
    {
        return result;
    }
    g_jam_741_index++;
    kal_trace(TRACE_FUNC, JVM_UTIL_IS_MIDLET_MSG_FILE,g_jam_741_index);
    midlet_msg_file_hdlr = FS_Open((const WCHAR*)midlet_msg_path, FS_READ_ONLY);

    if (midlet_msg_file_hdlr < 0)
    {
        goto is_midlet_msg_file_error;
    }

    while (jvm_util_dec_midlet_msg_get_next_entry(
              midlet_msg_file_hdlr, &isFile, 
              &discard, 
              &dir_entry_header, 
              &file_entry_header,
              JVM_MIDLET_MESSAGE_MANIFEST))
    {
        if (!discard && isFile)
        {
            context = jam_listmem_malloc(file_entry_header.SizeCompressed);
            if (context == NULL)
            {
                goto is_midlet_msg_file_error;
            }

            if (FS_Read(midlet_msg_file_hdlr, (void*)context, file_entry_header.SizeCompressed, &read_bytes) != FS_NO_ERROR)
            {
                goto is_midlet_msg_file_error;
            }
            else
            {
                entry_found = KAL_TRUE;
                break;
            }
        }
        else
        {
            if (isFile)
            {
                FS_Seek(midlet_msg_file_hdlr,file_entry_header.SizeCompressed,FS_FILE_CURRENT);
            }
        }
    }

    if (!entry_found)
    {
        goto is_midlet_msg_file_error;
    }

    verno = jam_parse_header_value(context, file_entry_header.SizeCompressed, "Distribution-Package");

    if (verno == NULL)
    {
        goto is_midlet_msg_file_error;
    }

    if (strcmp(verno,"1.0") == 0)
    {
        result = KAL_TRUE;
    }
    jam_listmem_free(verno);
    
is_midlet_msg_file_error:

    if (context)
    {
        jam_listmem_free(context);
    }
    if (midlet_msg_file_hdlr > 0)
    {
        FS_Close (midlet_msg_file_hdlr);
    }
    return result;
    
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_copy_and_rename_jar
 * DESCRIPTION
 *  Copy file to Recieved fold and rename.
 * PARAMETERS
 *    new_name          [IN] new file name
 *    file_path         [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_wchar* jvm_util_copy_and_rename_jar(kal_wchar* new_name, kal_wchar* file_path, kal_wchar* output_dir, kal_int32 *error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_wchar *filename = NULL;
    kal_int32 jar_file_hdlr = -1;
    kal_uint32 file_size;
    kal_wchar *output_name;
    kal_int32 output_name_len;
    kal_int32 output_name_hdlr = -1;
    kal_int32 scan_off = 0;
    kal_int32 read_bytes;
    kal_uint32 write_bytes;
    kal_char *buffer = NULL;
    kal_wchar* result = NULL;
    kal_int32 file_path_len;
    kal_wchar* midlet_message_dir = output_dir;
    kal_int32 new_name_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *error = PACKAGE_FAIL;
    file_path_len = get_ucs2_len(file_path);
    for (i = file_path_len; i > 0 ; i--)
    {
        if (file_path[i] == '\\')
        {
            break;
        }
    }
    filename = jam_listmem_malloc((file_path_len-i+1)<<1);
    if (filename == NULL)
    {
        goto copy_and_rename_jar_error;
    }
    app_ucs2_wcscpy((kal_wchar*) filename, (kal_wchar*) &file_path[i+1]);

    if (output_dir == NULL)
    {
        midlet_message_dir = MIDLET_MESSAGE_FOLDER;
    }
    
    new_name_length = get_ucs2_len(new_name);
    if (new_name_length > SRV_FMGR_PATH_MAX_FILE_NAME_LEN - 4)
    {
        new_name_length = SRV_FMGR_PATH_MAX_FILE_NAME_LEN - 4;
    }

    output_name_len = (get_ucs2_len(new_name) + get_ucs2_len(midlet_message_dir)+ 6) <<1;
    output_name = jam_listmem_malloc(output_name_len);
    if (output_name == NULL)
    {
        goto copy_and_rename_jar_error;
    }    
    mmi_ucs2cpy((S8*)output_name, (S8*)midlet_message_dir);

    if (output_dir == NULL)
    {
        /* we put midlet message to the same driver's @java */
        output_name[0] = file_path[0];
        if (check_and_create_hidden_folder(output_name) != FS_NO_ERROR)
        {
            goto copy_and_rename_jar_error;
        }
    }
    app_ucs2_wcsncat((kal_wchar*) output_name, (kal_wchar*) new_name,new_name_length);
    app_ucs2_wcscat((kal_wchar*) output_name, (kal_wchar*) L".jar");

    output_name_hdlr = FS_Open((const WCHAR*)output_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    
    /* find out file name */
    if (DRM_is_drm_file(NULL, file_path))
    {
        jar_file_hdlr = jvm_file_open_as_normal_file(file_path, FS_READ_ONLY);
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
#endif
    if (jar_file_hdlr == -1)
    {
        goto copy_and_rename_jar_error;
    }

    if( jvm_file_getsize(jar_file_hdlr, &file_size) != 1)
    {
        goto copy_and_rename_jar_error;
    }

    buffer = jam_listmem_malloc(1024);
    if (buffer == NULL)
    {
        goto copy_and_rename_jar_error;
    }
    
    while (scan_off < file_size)
    {
        read_bytes = jvm_file_read(jar_file_hdlr, buffer, 1024);
        if( read_bytes == -1)
        {
            goto copy_and_rename_jar_error;
        }
        if(FS_Write(output_name_hdlr, (void*)buffer, read_bytes, &write_bytes) != FS_NO_ERROR)
        {
            goto copy_and_rename_jar_error;
        }
        scan_off += 1024;
    } 
    result = output_name;
    *error = J2ME_NO_ERROR;

copy_and_rename_jar_error:
    if (buffer)
    {
        jam_listmem_free(buffer);
    }
    if (filename)
    {
        jam_listmem_free(filename);
    }
    if (jar_file_hdlr != -1)
    {
        jvm_file_close(jar_file_hdlr);
    }
    if (output_name_hdlr > 0)
    {
        FS_Close(output_name_hdlr);
    } 
    
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_get_work_sys_dir_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_char* jvm_util_get_work_sys_dir_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return work_sys_dir_path;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_util_get_work_sys_dir_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void jvm_util_delete_midlet_msg_temp_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char test_drive;
    kal_wchar *temp_folder = NULL;
    kal_int32  fs_result;
    //kal_int32 attribute;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_folder = jam_listmem_malloc((get_ucs2_len(MIDLET_MESSAGE_FOLDER)+1)<<1);
    if (temp_folder != NULL)
    {
        mmi_ucs2cpy((S8*)temp_folder,(S8*)MIDLET_MESSAGE_FOLDER);
        for (test_drive = 'A'; test_drive < 'Z'; test_drive++)
        {
            temp_folder[0] = test_drive;

            fs_result = FS_XDelete(temp_folder, FS_DIR_TYPE|FS_FILE_TYPE|FS_RECURSIVE_TYPE, NULL, 0);
        }
    }
    jam_listmem_free(temp_folder);
}
#endif
#if defined(__OP01__ )&& defined(J2ME_SUPPORT_BACKGROUND)
jvm_util_OP01_ret_enum jvm_util_OP01_check_Keep_Background(kal_int32 vm_id)
{

    kal_wchar value_buf[10];
    kal_uint8 ret;

    
    if (jam_mvm_get_storage_name_by_vm_id(vm_id))
    {

        ret = jam_call_back_functions.jam_get_mids_app_property(jam_mvm_get_storage_name_by_vm_id(vm_id),
                                                                0,                               /*get from jad*/
                                                                "CMCC-Keep-Background",
                                                                value_buf,
                                                                10);
        if(!ret)
        {
            return JVM_UTIL_FAIL;            
        }
        else if(!mmi_ucs2cmp((const S8 *) value_buf, (const S8 *) L"yes"))
        {     
            
            return JVM_UTIL_SUCCESS;
        } 
        else
        {
            return JVM_UTIL_FAIL;
        }
    }        
    else
    {
        return JVM_UTIL_MISS_INFO;
    }        
    
}
kal_bool jvm_util_OP01_is_Keep_Background(kal_int32 vm_id)
{   
    kal_char* storage_name = jam_mvm_get_storage_name_by_vm_id(vm_id);
    if((jam_call_back_functions.jam_get_running_midlet_domain(storage_name)!= 2 ) ||
       (jvm_util_OP01_check_Keep_Background(vm_id) != JVM_UTIL_SUCCESS) || 
       (mmi_java_is_in_voice_call())
	)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }	
}	
#endif                
/*****************************************************************************
 * CRC function
 *****************************************************************************/
/* Table of CRCs of all 8-bit messages.  */
static unsigned long g_java_crc_table[256];
/* Flag: has the table been computed? Initially false. */
static int g_java_crc_table_computed = 0;

/*****************************************************************************
 * FUNCTION
 *  jam_np_make_crc_table
 * DESCRIPTION
 *  Make the table for a fast CRC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jvm_util_make_crc_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 c;
    kal_uint16 n, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (n = 0; n < 256; n++)
    {
        c = (unsigned long)n;
        for (k = 0; k < 8; k++)
        {
            if (c & 1)
            {
                c = 0xedb88320L ^ (c >> 1); /* crc base */
            }
            else
            {
                c = c >> 1;
            }
        }
        g_java_crc_table[n] = c;
    }
    g_java_crc_table_computed = 1;
}


/*****************************************************************************
 * FUNCTION
 *  jam_np_update_crc
 * DESCRIPTION
 *  Make the table for a fast CRC.
 * PARAMETERS
 *  crc     [IN]        [kal_uint32]   current crc code
 *  buf     [?]         [kal_char*]    next coded buffer
 *  len     [IN]        [kal_uint32]   coded buffer length
 * RETURNS
 *  kal_uint32            next crc code
 *****************************************************************************/
kal_uint32 jvm_util_update_crc(kal_uint32 crc, kal_char *buf, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 c = crc;
    kal_uint32 n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_java_crc_table_computed)
    {
        jvm_util_make_crc_table();
    }

    for (n = 0; n < len; n++)
    {
        c = g_java_crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
    }

    return c;
}
/*****************************************************************************
 * FUNCTION
 *  jvm_util_atoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 jvm_util_atoi(kal_char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 num = 0;
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < strlen(s); i++)
    {
        num += (kal_uint32) (s[i] - '0');
        if (i < (strlen(s) - 1))
        {
            num *= 10;
        }
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_util_itoa
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [?]         
 *  n           [IN]        
 *  limit       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_util_itoa(kal_char *s, kal_int32 n, kal_uint32 limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ptr = s;
    kal_uint32 inv_n = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!n)
    {
        (*(ptr)) = '0';
        (*(ptr + 1)) = '\0';
        return;
    }

    if (n < 0)
    {
        (*ptr) = '-';
        n = n * (-1);
        ptr++;
    }

    while (n)
    {
        kal_uint8 last_n = (n % 10);

        inv_n += last_n;
        inv_n *= 10;
        n /= 10;
    }

    while (inv_n)
    {
        kal_uint8 last_inv_n = (inv_n % 10);

        (*ptr) = (kal_char) (last_inv_n + '0');
        ptr++;
        inv_n /= 10;
    }

    (*ptr) = '\0';

}
