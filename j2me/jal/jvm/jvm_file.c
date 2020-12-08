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
 *   jvm_file.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *    This file implements file APIs which support both virtual file on flash and 
 * general file on storage device.
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
 *
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
* Include header files
*************************************************************************/
#include "jal.h"
#include "jvm_internal.h"
#include "stdio.h"
#include "app_buff_alloc.h"
#include "jvm_adaptor.h"
#include "jvm_internal.h"
#include "j2me_custom.h"
#include "jam_internal.h"
#include "jam_msg_util.h"
#include "jam_msg_handler.h"
#include "drm_gprot.h"
#include "drm_def.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "app_str.h"
#include "jvm_file.h"
#include "jvm_trace_interface.h"
#include "jvm_resource_manager.h"

#if defined( __NEMO_VM__)
#include "thread_stack_switch.h"
#endif
#define __ENCRYPT_OPTIMIZE__ 
#define ENCRYPT_BUFFER_SIZE 2048
/*************************************************************************
* Global Definition
*************************************************************************/
////#define JVM_FILE_DEBUG_SUPPORT  

kal_char *work_dir_path;
kal_char *work_sys_dir_path;
j2me_custom_file_info_struct* work_info_ptr;

/* Default Java database folder, which drive can ben changed in j2me_custom_resource.c */
kal_char j2me_tck_dir_path[] = "Z:\\@Java\\TCK";
kal_char j2me_sys_dir_path[] = "C:\\@Java";

#ifdef SUPPORT_MUSICWAV
kal_char musicwav_sys_dir_path[] = "C:\\@MusicWav";
#endif /* SUPPORT_MUSICWAV */

/* JSR75's FILE API */
disk_info_struct disk_info[25];  //should move to jvm
kal_bool disk_changed = KAL_FALSE;

WCHAR WCHARFilename[MAX_WCHAR_FILENAME_LEN];
WCHAR WCHARFilename_JAM[MAX_WCHAR_FILENAME_LEN];
char CHARFilename[MAX_WCHAR_FILENAME_LEN];
static int KVM_FindFilehandle;


static kal_wchar jvm_file_name_buffer_w[MAX_WCHAR_FILENAME_LEN];
static kal_char jvm_file_name_buffer[MAX_WCHAR_FILENAME_LEN];
static kal_bool jvm_find_file_is_java_dir[MAX_VM_INSTANCE_NUM];
static kal_bool jvm_find_file_from_virtual_file[MAX_VM_INSTANCE_NUM];
static kal_uint32 jvm_find_file_virtual_file_id[MAX_VM_INSTANCE_NUM];
static kal_char * jvm_find_file_name_pattern[MAX_VM_INSTANCE_NUM];
static kal_int32 jvm_find_file_handle_2_index[MAX_VM_INSTANCE_NUM]; 

static jvm_file_cache_data_struct  * jvm_file_cache_data  = NULL;
#ifdef __JVM_FILE_CACHE_SUPPORT__
static kal_bool jvm_file_cache_enabled = KAL_FALSE;
#endif
//static kal_bool find_file_is_java_dir = KAL_FALSE;
//static kal_uint32 find_file_vitual_file_id = 0;
//static kal_bool find_file_from_vitual_file = KAL_FALSE;
//static char *findString;
static unsigned short disk_access_name[] = { 'A', ':', '\\', 0};

kal_int32 g_jvm_card_plugin_event = 0;

extern kal_bool disk_changed;
extern kal_uint32 java_total_used_space;
extern kal_char *_jvm_get_dir_path(void);
extern kal_bool g_jam_stopFS;

/* JSR-75 connect FileMgr */
kal_uint8 drv_array[SRV_FMGR_DRV_TOTAL];
//kal_wchar *g_jvm_file_alias_name = NULL;

jvm_file_aliasTable_node_struct *g_jvm_file_aliasTable_node_start = NULL;
static kal_int32 g_jvm_file_error_code;
static kal_int32 g_jvm_cluster_size;
static void (*jvm_file_disk_changed_callback)(void) = NULL;

/*************************************************************************
* Function Definition
*************************************************************************/

#ifdef ENCRYPT_JAR_FILE
#include <reg_base.h>
#include <stdlib.h>
#define KEY_FILE_NAME "ENCRKEY"
#ifdef __MTK_TARGET__
//James modified start11
//#define TDMA_TQCNT         (volatile kal_uint16 *)(TDMA_base+0x00)
//#define TDMA_WRAP          (volatile kal_uint16 *)(TDMA_base+0x04)
//James modified end11
/* extern kal_uint32 L1I_GetTimeStamp(void); */
#endif /* __MTK_TARGET__ */ /* ifdef __MTK_TARGET__ */

static kal_uint32 encrypt_table[256];
static kal_uint8 decrypt_table[256];
static kal_bool jvm_file_initailized = KAL_FALSE;
static kal_int32 encrypt_code;

#ifdef __MTK_TARGET__
static kal_long64 multiplier = 0x5DEECE66DLL;
static kal_long64 addend = 0xBL;
static kal_long64 Random_mask = (1LL << 48) - 1;
#else /* __MTK_TARGET__ */ 
static kal_long64 multiplier = 0x5DEECE66DL;
static kal_long64 addend = 0xBL;
static kal_long64 Random_mask = (1 << 48) - 1;
#endif /* __MTK_TARGET__ */ 
static kal_long64 result_seed;


/*****************************************************************************
 * FUNCTION
 *  setSeed
 * DESCRIPTION
 *  , next_rand
 *  The two functions can be used to generate psudo-random number.
 * PARAMETERS
 *  seed        [IN]        Random number seed
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void setSeed(kal_int32 seed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_seed = (seed ^ multiplier) & Random_mask;
}


/*****************************************************************************
 * FUNCTION
 *  next_rand
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static kal_int32 next_rand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_long64 nextseed = (result_seed * multiplier + addend) & Random_mask; // 20090409: Changed

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_seed = nextseed;
    return (kal_int32) (((kal_ulong64) nextseed) >> (16)); // 20090409: Changed
}


/*****************************************************************************
 * FUNCTION
 *  get_encryption_key
 * DESCRIPTION
 *  This function is used to create
 * PARAMETERS
 *  type                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 get_encryption_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_uint32 key;
    kal_uint32 dummy;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(WCHARFilename, "%s\\%s", _jvm_get_dir_path(), KEY_FILE_NAME);
    handle = FS_Open(WCHARFilename, FS_OPEN_SHARED | FS_READ_ONLY);
    if (handle < 0)
    {
    #ifdef __MTK_TARGET__
    //James modified start11
        //encrypt_code = (kal_uint32) (*TDMA_TQCNT) + (((kal_uint32) (*TDMA_WRAP)) << 16);
        encrypt_code = rand();
     //James modified end11
        /* key = L1I_GetTimeStamp(); */
        key = jvm_get_currenttime_ms();
    #else /* __MTK_TARGET__ */ 
        encrypt_code = 0x12345678;
        key = 0x4567890a;
    #endif /* __MTK_TARGET__ */ 
        handle = FS_Open(WCHARFilename, FS_OPEN_SHARED | FS_READ_WRITE | FS_CREATE);
        FS_Write(handle, (kal_char*) & key, 4, &dummy);
        FS_Write(handle, (kal_char*) & encrypt_code, 4, &dummy);
    }
    else
    {
        FS_Read(handle, (kal_char*) & key, 4, &dummy);
        FS_Read(handle, (kal_char*) & encrypt_code, 4, &dummy);
    }
    FS_Close(handle);
    return key;
}


/*****************************************************************************
 * FUNCTION
 *  make_encrypt_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void make_encrypt_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 count, key, random_num, temp_value;
    kal_int32 offset;
    kal_uint8 *encrypt_temp = (kal_uint8*) encrypt_table;
    kal_uint8 *decrypt_temp = (kal_uint8*) decrypt_table;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key = get_encryption_key();
    setSeed(key);
    memset(encrypt_table, 0, 256 * 4);
    for (offset = 3; offset >= 0; offset--)
    {
        kal_uint8 *encrypt_temp_off = encrypt_temp + offset;
        kal_uint8 *decrypt_temp_off = decrypt_temp;

        memset(decrypt_table, 0, 256);
        count = 0;
        random_num = (((unsigned int)next_rand()) << 24) >> 24;
        do
        {
            encrypt_temp_off[count << 2] = random_num;
            decrypt_temp_off[random_num] = count;
            count++;
            do
            {
                random_num = (((unsigned int)next_rand()) << 24) >> 24;
                temp_value = (unsigned int)decrypt_temp_off[random_num];
            } while (encrypt_temp_off[temp_value << 2] == random_num);
        } while (count < 255);

        encrypt_temp_off[count << 2] = random_num;
        decrypt_temp_off[random_num] = count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_org_encrypt_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos             [IN]        
 *  value           [IN]        
 *  base_value      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline kal_uint32 get_org_encrypt_value(kal_uint32 pos, kal_uint32 value, kal_uint32 base_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = encrypt_table[(base_value ^ pos) >> 24] ^ (base_value >> 8);
    c = encrypt_table[((c ^ pos) << 8) >> 24] ^ (c >> 8);
    c = encrypt_table[((c ^ pos) << 16) >> 24] ^ (c >> 8);
    c = encrypt_table[((c ^ pos) << 24) >> 24] ^ (c >> 8);
    c = encrypt_table[((c ^ value) << 24) >> 24] ^ (c >> 8);

    return c;
}


/*****************************************************************************
 * FUNCTION
 *  encrypt_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos             [IN]        
 *  base_value      [IN]        
 *  value           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline kal_uint32 encrypt_value(kal_uint32 pos, kal_uint32 base_value, kal_uint32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 c;
    kal_uint32 temp_c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c = encrypt_table[(base_value ^ pos) >> 24] ^ (base_value >> 8);
    c = encrypt_table[((c ^ pos) << 8) >> 24] ^ (c >> 8);
    c = encrypt_table[((c ^ pos) << 16) >> 24] ^ (c >> 8);
    c = encrypt_table[((c ^ pos) << 24) >> 24] ^ (c >> 8);
    temp_c = (((c >> 8) ^ value) << 24) >> 24;
    return ((c ^ decrypt_table[temp_c]) << 24) >> 24;
}


/*****************************************************************************
 * FUNCTION
 *  get_base_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 get_base_code(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 c = encrypt_code;
#ifndef __ENCRYPT_OPTIMIZE__        
    kal_uint8 temp_buffer[1];
#endif
    kal_uint32 real_count;
    kal_int32 file_size = FS_Seek(handle, 0, SEEK_END);
    kal_int32 scan_pos = 0;
    #ifdef __ENCRYPT_OPTIMIZE__
    kal_int32 i;//,value = 0;
    kal_uint8 *encrypt_buffer;
    kal_int32 encrypt_length = 0;
    #endif /* __ENCRYPT_OPTIMIZE__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_size != 0)
    {
        #ifdef __ENCRYPT_OPTIMIZE__    
     
        if(file_size > ENCRYPT_BUFFER_SIZE)
            encrypt_length = ENCRYPT_BUFFER_SIZE;
        else
            encrypt_length = ENCRYPT_BUFFER_SIZE - file_size;

        if(encrypt_length%2 != 0) encrypt_length -=1;
     
        encrypt_buffer = (kal_uint8*) jvm_malloc(encrypt_length);
        
        FS_Seek(handle, scan_pos, SEEK_SET);
        FS_Read(handle, (void*)encrypt_buffer, encrypt_length, &real_count);        
        
        for(i=0;i<real_count; i+= 2)
        {
            c = encrypt_table[((encrypt_buffer[i] ^ c) << 24) >> 24] ^ (c >> 8);
        }
        jvm_free(encrypt_buffer);
        #else  /* __ENCRYPT_OPTIMIZE__ */ 
        while (scan_pos < file_size)
        {
            FS_Seek(handle, scan_pos, SEEK_SET);
            FS_Read(handle, (void*)temp_buffer, 1, &real_count);
            c = encrypt_table[((c ^ temp_buffer[0]) << 24) >> 24] ^ (c >> 8);
            scan_pos += ENCRYPT_BUFFER_SIZE;
        }
        #endif /* __ENCRYPT_OPTIMIZE__ */
        
        FS_Seek(handle, 0, SEEK_SET);        
        return c;
    }
    else
    {
        return 0xFA;
    }
}


/*****************************************************************************
 * FUNCTION
 *  encrypt_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 encrypt_file(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 file_size = FS_Seek(handle, 0, SEEK_END);
    kal_uint32 scan_pos = 0;
    kal_uint32 base_code = encrypt_code;    
    kal_uint32 real_count;
    kal_int32 return_code = J2ME_NO_ERROR;    
    kal_uint8 *encrypt_buffer = (kal_uint8*) jvm_malloc(ENCRYPT_BUFFER_SIZE);
    kal_int32 i;
    #ifdef __ENCRYPT_OPTIMIZE__
    kal_int32 scan_length = 0; 
    kal_bool first_time = KAL_TRUE;        
    #else /*  __ENCRYPT_OPTIMIZE__ */    
    kal_int32 scan_length = 1023;
    kal_uint8 temp_buffer[1];
    #endif      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (encrypt_buffer == NULL)
    {
        ASSERT(0);
    }

    if (file_size < 0)
    {
        return_code = J2ME_ACTION_FAILE;
        goto encrypt_fail;
    }
#ifdef __ENCRYPT_OPTIMIZE__
    FS_Seek(handle, 0, SEEK_SET);
    while (scan_pos < file_size && !g_jam_stopFS)
    {  

        if (scan_pos + scan_length > file_size)
        {
            scan_length = file_size - scan_pos;
        }    
        
        if(first_time == KAL_TRUE)
        {
            if(file_size > ENCRYPT_BUFFER_SIZE)
                scan_length = ENCRYPT_BUFFER_SIZE;
            else
                scan_length = ENCRYPT_BUFFER_SIZE - file_size;

            if(scan_length%2 != 0) scan_length -=1;
        }
        
        FS_Read(handle, (void*)encrypt_buffer, scan_length, &real_count);

        if(first_time == KAL_TRUE)
        {     
             for(i=0;i<real_count; i+= 2)
             {            
                encrypt_buffer[i] = encrypt_value(i, encrypt_code, encrypt_buffer[i]);
                base_code = encrypt_table[((encrypt_buffer[i] ^ base_code) << 24) >> 24] ^ (base_code >> 8);            
             }
            i = real_count -1;
            do
            {
                encrypt_buffer[i] = encrypt_value(scan_pos + i, base_code, encrypt_buffer[i]);
                i-=2;
            } while(i>=0);         

            first_time = KAL_FALSE;
        }else
        {     
            i = real_count-1;
            do
            {
                encrypt_buffer[i] = encrypt_value(scan_pos + i, base_code, encrypt_buffer[i]);
                i--;
            } while (i >= 0);             
        }
        FS_Seek(handle, scan_pos, SEEK_SET);
        FS_Write(handle, (void*)encrypt_buffer, scan_length, &real_count);

        scan_pos += scan_length;
        scan_length = ENCRYPT_BUFFER_SIZE;
    }

    if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
    {
        return_code = J2ME_USER_CANCEL;
        goto encrypt_fail;
    }

#else  /* __ENCRYPT_OPTIMIZE__ */
    while (scan_pos < file_size && !g_jam_stopFS)
    {
        FS_Seek(handle, scan_pos, SEEK_SET);
        FS_Read(handle, (void*)temp_buffer, 1, &real_count);
        temp_buffer[0] = encrypt_value(scan_pos, encrypt_code, temp_buffer[0]);
        base_code = encrypt_table[((temp_buffer[0] ^ base_code) << 24) >> 24] ^ (base_code >> 8);
        FS_Seek(handle, scan_pos, SEEK_SET);
        FS_Write(handle, (void*)temp_buffer, 1, &real_count);
        scan_pos += ENCRYPT_BUFFER_SIZE;
    }
    if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
    {
        return_code = J2ME_USER_CANCEL;
        goto encrypt_fail;
    }
    scan_pos = 1;
    do
    {
        if (scan_pos + scan_length > file_size)
        {
            scan_length = file_size - scan_pos;
        }
        if (FS_Seek(handle, scan_pos, SEEK_SET) < 0)
        {
            return_code = J2ME_ACTION_FAILE;
            goto encrypt_fail;
        }
        FS_Read(handle, encrypt_buffer, scan_length, &real_count);
        if (real_count != scan_length)
        {
            return_code = J2ME_ACTION_FAILE;
            goto encrypt_fail;
        }
        i = real_count - 1;
        do
        {
            encrypt_buffer[i] = encrypt_value(scan_pos + i, base_code, encrypt_buffer[i]);
            i--;
        } while (i >= 0);
        if (FS_Seek(handle, scan_pos, SEEK_SET) < 0)
        {
            return_code = J2ME_ACTION_FAILE;
            goto encrypt_fail;
        }
        FS_Write(handle, encrypt_buffer, scan_length, &real_count);
        if (real_count != scan_length)
        {
            return_code = J2ME_ACTION_FAILE;
            goto encrypt_fail;
        }

        if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
        {
            return_code = J2ME_USER_CANCEL;
            goto encrypt_fail;
        }
        scan_pos += scan_length + 1;
    } while (scan_pos < file_size);
#endif /* __ENCRYPT_OPTIMIZE__ */ 
  encrypt_fail:
     if(encrypt_buffer)
     {
           jvm_free(encrypt_buffer);
        encrypt_buffer =NULL;
     }
    return return_code;
}


/*****************************************************************************
 * FUNCTION
 *  decrypt_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf             [?] 
 *  base_code       [IN]        
 *  pos             [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __ENCRYPT_OPTIMIZE__  
kal_bool decrypt_buffer(kal_uint8 *buf, kal_uint32 base_code, kal_uint32 pos, kal_int32 len, kal_int32 file_size)
#else
kal_bool decrypt_buffer(kal_uint8 *buf, kal_uint32 base_code, kal_uint32 pos, kal_int32 len)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 scan_pos = 0;
    kal_int32   encrypt_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __ENCRYPT_OPTIMIZE__ 
    if(file_size > ENCRYPT_BUFFER_SIZE)
        encrypt_length = ENCRYPT_BUFFER_SIZE;
    else
        encrypt_length = ENCRYPT_BUFFER_SIZE - file_size;

    if(encrypt_length%2 != 0) encrypt_length -=1;
    #endif /*  #ifdef __ENCRYPT_OPTIMIZE__  */

    while (scan_pos < len)
    {
         #ifdef __ENCRYPT_OPTIMIZE__  
         if((scan_pos + pos) < encrypt_length)
         {        
            if ((scan_pos + pos) % 2 == 0)
                {
                    buf[scan_pos] = (get_org_encrypt_value(scan_pos + pos, buf[scan_pos], encrypt_code) << 24) >> 24;
                }
                else
                {
                         buf[scan_pos] = (get_org_encrypt_value(scan_pos + pos, buf[scan_pos], base_code) << 24) >> 24;
                }  
              }else
                buf[scan_pos] = (get_org_encrypt_value(scan_pos + pos, buf[scan_pos], base_code) << 24) >> 24;
        #else /* __ENCRYPT_OPTIMIZE__ */
        if (((scan_pos + pos << 22) >> 22) != 0)
        {
            buf[scan_pos] = (get_org_encrypt_value(scan_pos + pos, buf[scan_pos], base_code) << 24) >> 24;
        }
        else
        {
            buf[scan_pos] = (get_org_encrypt_value(scan_pos + pos, buf[scan_pos], encrypt_code) << 24) >> 24;
        }
        #endif    /* __ENCRYPT_OPTIMIZE__ */
        scan_pos++;
    }
    return KAL_TRUE;
}

#endif /* ENCRYPT_JAR_FILE */ 


/*****************************************************************************
 * FUNCTION
 *  jvm_file_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 attribute;
    kal_char *dir_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* initialize mvm file */
    jvm_mvm_file_initialize();
    
    /* Check whether the directory exists? */
    dir_path = _jvm_get_dir_path();
    kal_wsprintf(WCHARFilename, "%s", dir_path);
    attribute = FS_GetAttributes(WCHARFilename);

    g_jvm_file_error_code = FS_NO_ERROR;
    if (attribute > 0)
    {
        /* this directory maybe exists */
        if ((attribute & FS_ATTR_DIR) != FS_ATTR_DIR)
        {
            return -1;
        }
    }
    else
    {
        /* this directory doesn't exist. Create this directory */
        if (FS_CreateDir(WCHARFilename) != FS_NO_ERROR)
        {
            return -1;
        }
    }

#ifdef ENCRYPT_JAR_FILE
    if (!jvm_file_initailized)
    {
        jvm_file_initailized = KAL_TRUE;
        make_encrypt_table();
    }
#endif /* ENCRYPT_JAR_FILE */ 

    /* Successfully initialized */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_finalize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

//James modified start1
void jvm_file_attachfilepath(module_type mod_id, const char *Input_filename, const char *Output_filename, kal_bool IsSaveToGloablVar)
{        
     if(IsSaveToGloablVar)
     {
          if(mod_id == MOD_JAM) 
          {
                if (is_system_file((char*)Input_filename))
                {
                    kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, Input_filename);
                 kal_sprintf(jvm_file_name_buffer,"%s\\%s",work_sys_dir_path,Input_filename);
                }
                else
                {
                    kal_wsprintf(WCHARFilename, "%s\\%s", work_dir_path, Input_filename);
                 kal_sprintf(jvm_file_name_buffer,"%s\\%s",work_dir_path,Input_filename);
                }
        }else
        {
                if (is_system_file((char*)Input_filename))
                {
                    kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, Input_filename);
                 kal_sprintf(jvm_file_name_buffer,"%s\\%s",work_sys_dir_path,Input_filename);
                }
                else
                {
                    kal_wsprintf(WCHARFilename, "%s\\%s", work_dir_path, Input_filename);
                 kal_sprintf(jvm_file_name_buffer,"%s\\%s",work_dir_path,Input_filename);
                }
        }
            
     }else
     {
         if(Output_filename ==NULL) return;
            if (is_system_file((char*)Input_filename))
            {
                kal_wsprintf((unsigned short *)Output_filename, "%s\\%s", work_sys_dir_path, Input_filename);
                kal_sprintf((kal_char *)Output_filename,"%s\\%s",work_dir_path, Input_filename);
            }
            else
            {
                kal_wsprintf((unsigned short *)Output_filename, "%s\\%s", work_dir_path, Input_filename);
                kal_sprintf((kal_char *)Output_filename,"%s\\%s",work_dir_path, Input_filename);
            }
         //return newFilename;
     }

}

void jvm_file_attachfilepath_ucs(module_type mod_id, unsigned short *Input_filename, const char *Output_filename, kal_bool IsSaveToGloablVar)
{        
        //unsigned short *temp_filename = NULL;
	 //temp_filename = Input_filename;

     if(IsSaveToGloablVar)
     {    
           if(mod_id == MOD_JAM)
           {
               if (Input_filename[1] == 58 || Input_filename[0] == 92) /* ":" or "\" */
                {
                    mmi_ucs2cpy((S8*)WCHARFilename_JAM,(S8*)Input_filename);
                }else if (is_system_file_ucs(Input_filename))
              {
                  //kal_wsprintf(WCHARFilename_JAM, "%s\\%s", work_sys_dir_path, Input_filename);
                    kal_wsprintf(WCHARFilename_JAM, "%s\\\0", work_sys_dir_path);
                    mmi_ucs2cat((S8*)WCHARFilename_JAM,(S8*)Input_filename);              
              }
              else
              {
                  //kal_wsprintf(WCHARFilename_JAM, "%s\\%s", work_dir_path, Input_filename);
                    kal_wsprintf(WCHARFilename_JAM, "%s\\\0", work_dir_path);
                    mmi_ucs2cat((S8*)WCHARFilename_JAM,(S8*)Input_filename);              
              }    
           }else
           {

               if (Input_filename[1] == 58 || Input_filename[0] == 92) /* ":" or "\" */
                {
                    mmi_ucs2cpy((S8*)WCHARFilename,(S8*)Input_filename);
                }else  if (is_system_file_ucs(Input_filename))
                {
                    //kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, Input_filename);
                    kal_wsprintf(WCHARFilename, "%s\\\0", work_sys_dir_path);
                    mmi_ucs2cat((S8*)WCHARFilename,(S8*)Input_filename);                
                }
                else
                {
                    //kal_wsprintf(WCHARFilename, "%s\\%s", work_dir_path, Input_filename);
                    kal_wsprintf(WCHARFilename, "%s\\\0", work_dir_path);
                    mmi_ucs2cat((S8*)WCHARFilename,(S8*)Input_filename);                
                }

           }
     }else
     {
         if(Output_filename ==NULL) return;
            if (is_system_file_ucs(Input_filename))
            {
                kal_wsprintf((unsigned short *)Output_filename, "%s\\%s", work_sys_dir_path, Input_filename);
                //kal_sprintf((kal_char *)filename,"%s\\%s",work_dir_path, filename);
            }
            else
            {
                kal_wsprintf((unsigned short *)Output_filename, "%s\\%s", work_dir_path, Input_filename);
                //kal_sprintf((kal_char *)filename,"%s\\%s",work_dir_path, filename);
            }
         //return newFilename;
     }

}
//James modified end1
/*****************************************************************************
 * FUNCTION
 *  jvm_file_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_delete(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_int32 err;
    module_type active_module_id = kal_get_active_module_id();    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_DELETE);
    MMI_PRINT(MOD_JAM,TRACE_GROUP_9,"[file name = %s]",(char * )filename);

#ifndef __NEMO_VM__

    if (active_module_id == MOD_JAM)
    {    
        if (is_system_file((char*)filename))
        {
            kal_wsprintf(WCHARFilename_JAM, "%s\\%s", work_sys_dir_path, filename);
        }
        else
        {
            kal_wsprintf(WCHARFilename_JAM, "%s\\%s", work_dir_path, filename);
        }
    

        /* this is to prevent removing a read only file */
        FS_SetAttributes(WCHARFilename_JAM, 0);
        if ((err = FS_Delete(WCHARFilename_JAM)) == FS_NO_ERROR)
        {
            return 0;
        }
        else
        {
            g_jvm_file_error_code = err;
            return -1;
        }
    }        
    else
    {
        if (is_system_file((char*)filename))
        {
            kal_wsprintf(WCHARFilename, "%s\\%s", work_sys_dir_path, filename);
        }
        else
        {
            kal_wsprintf(WCHARFilename, "%s\\%s", work_dir_path, filename);
        }

        /* this is to prevent removing a read only file */
        FS_SetAttributes(WCHARFilename, 0);
        if ((err = FS_Delete(WCHARFilename)) == FS_NO_ERROR)
        {
            return 0;
        }
        else
        {
            g_jvm_file_error_code = err;
            return -1;
        }
            
    }        
#else /* __NEMO_VM__ */
//James modified start1
	 jvm_file_attachfilepath(active_module_id,filename,NULL,KAL_TRUE);
        return jvm_mvm_file_delete(jvm_file_name_buffer);
//James modified start1
#endif /*__NEMO_VM__  */

}

/*****************************************************************************
 * FUNCTION
 *  jvm_file_delete_ucs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 #if defined( __NEMO_VM__)  || defined( __IJET_VM__)
int jvm_file_delete_ucs(unsigned short *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 err;
    module_type active_module_id = kal_get_active_module_id();
    WCHAR temp_Filename[MAX_WCHAR_FILENAME_LEN]; //James modified start1
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_DELETE);
    MMI_PRINT(MOD_JAM,TRACE_GROUP_9,"[file name = %s]",(char * )filename);

//James modified start1
	 jvm_file_attachfilepath_ucs(active_module_id,/*(const char *) */filename,NULL,KAL_TRUE); //_fatman
     memset(temp_Filename, 0 , MAX_WCHAR_FILENAME_LEN);
        /* this is to prevent removing a read only file */
        if (active_module_id == MOD_JAM)
        {
        memcpy(temp_Filename, WCHARFilename_JAM, MAX_WCHAR_FILENAME_LEN);
        }else
        {
        memcpy(temp_Filename, WCHARFilename, MAX_WCHAR_FILENAME_LEN);
        }
        FS_SetAttributes(temp_Filename, 0);
        if ((err = FS_Delete(temp_Filename)) == FS_NO_ERROR)
        {
            return 0;
        }
        else
        {
            g_jvm_file_error_code = err;        
            return -1;
        }
//James modified end1
}
#endif /* defined(__NEMO_VM__) || defined(__IJET_VM__) */ /* __NEMO_VM__ or __IJET_VM__ */


/*****************************************************************************
 * FUNCTION
 *  jvm_file_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  oldfilename     [IN]        
 *  newfilename     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_rename(const char *oldfilename, const char *newfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //James modified start1
    //WCHAR newFilename[MAX_WCHAR_FILENAME_LEN];
    char newFilename[MAX_FILENAME_LEN];
    //James modified end1
    //int i, file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    //kal_int32 err;
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* a real file should not overwrite a pre-install file */
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_RENAME);
    /*
     * for (i = 0; i < file_count; i++)
     * {
     * if (strcmp(newfilename, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
     * {
     * return -1;
     * }
    */
//James modified start1
	jvm_file_attachfilepath(active_module_id,oldfilename,NULL,KAL_TRUE); // old file name save to jvm_file_name_buffer
	jvm_file_attachfilepath(active_module_id,newfilename,newFilename,KAL_FALSE); // new file name save to newFilename

        return jvm_mvm_file_rename((const kal_char *)jvm_file_name_buffer,(const kal_char *)newFilename);
//James modified end1
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_rename_with_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  oldfilename     [IN]        
 *  newfilename     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_rename_with_path(const char *oldfilename, const char *newfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //James modified start1
    //WCHAR newFilename[MAX_WCHAR_FILENAME_LEN];
    char newFilename[MAX_FILENAME_LEN];
    WCHAR temp_Filename[MAX_WCHAR_FILENAME_LEN];
    //James modified end1
    int i, file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    kal_int32 err;
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* a real file should not overwrite a pre-install file */
    for (i = 0; i < file_count; i++)
    {
        if (strcmp(newfilename, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
        {
            return -1;
        }
    }

//James modified start1
    jvm_file_attachfilepath(active_module_id,newfilename, newFilename, KAL_FALSE);
     memset(temp_Filename, 0 , MAX_WCHAR_FILENAME_LEN);
        /* this is to prevent removing a read only file */
    if (active_module_id == MOD_JAM)
    {     
        memcpy(temp_Filename, WCHARFilename_JAM, MAX_WCHAR_FILENAME_LEN);
        }else
        {
        memcpy(temp_Filename, WCHARFilename, MAX_WCHAR_FILENAME_LEN);
        }
        
        if ((err = FS_Move(temp_Filename, (const WCHAR * )newFilename, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0)) == FS_NO_ERROR)
        {
            return 0;
        }
        else
        {
            g_jvm_file_error_code = err;    
            return -1;
        }
//James modified end1
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_open_newsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_open_newsp(const char *filename, int flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //int handle;
    //int file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    //int i;
    //jvm_file_struct * file;
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_OPEN, flags);
    MMI_PRINT(MOD_JAM,TRACE_GROUP_9,"[file name = %s]",(char * )filename);

    /* to avoid jam/jvm task use the same WCHARFilename */
    memset(jvm_file_name_buffer,0x00,MAX_WCHAR_FILENAME_LEN);
    memset(jvm_file_name_buffer_w,0x00,MAX_WCHAR_FILENAME_LEN*2);
//James modified start1
	jvm_file_attachfilepath(active_module_id,filename, NULL, KAL_TRUE);
    return jvm_mvm_file_open((const char *)jvm_file_name_buffer, flags);
//James modified end1
}

/*****************************************************************************
 * FUNCTION
 *  jvm_file_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_open(const char *filename, int flags)
{
    module_type module_id = kal_get_active_module_id();

    if (module_id == MOD_J2ME || module_id == MOD_J2ME_D)
    {
#ifdef USE_NEWSP_LOADJNI

    return excuteFunInNewSP(filename,flags);

#endif
    }

    return jvm_file_open_newsp(filename,flags);


}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_open_with_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_open_with_path(unsigned short *filename, int flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int handle;
    int file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    int i;
    jvm_file_struct *  file;
    char *tempfilename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//James modified start1
	jvm_file_attachfilepath_ucs(MOD_JAM,filename,NULL,KAL_TRUE);    
//James modified end1
    handle = DRM_open_file(WCHARFilename_JAM, flags, DRM_PERMISSION_EXECUTE);

    if (handle < 0)
    {
        g_jvm_file_error_code = handle;
        tempfilename = get_ctrl_buffer((get_ucs2_len(filename)+1)<<1);
        trans_ucs2_to_utf8(tempfilename,filename);
        for (i = 0; i < file_count; i++)
        {
            if (strcmp(tempfilename, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
            {
                file = (jvm_file_struct * ) get_ctrl_buffer(sizeof(jvm_file_struct));

                file->type = JVM_FILE_TYPE_VRITUAL;
                file->position = 0;
                file->size = work_info_ptr->virtual_file_info.virtual_file_size[i];
                file->data = (kal_uint8*) work_info_ptr->virtual_file_info.virtual_file_data[i];
                return (int)file;
            }
        }
        free_ctrl_buffer(tempfilename);

        /* the file is neigher in real file system nor virtual file system */
        return -1;
    }

    file = (jvm_file_struct * ) get_ctrl_buffer(sizeof(jvm_file_struct));
    file->type = JVM_FILE_TYPE_NORMAL;
    file->handle = handle;

#if defined(__DRM_SUPPORT__)
    if (file->type == JVM_FILE_TYPE_NORMAL&& DRM_get_object_method(handle, NULL) != DRM_METHOD_NONE)
    {
        file->type = JVM_FILE_TYPE_DRM;
    }
#endif /* defined(__DRM_SUPPORT__) */ 
    return (int)file;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_open_as_normal_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_open_as_normal_file(unsigned short *filename, int flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int handle;
    int file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    int i;
    jvm_file_struct *  file;
    char *tempfilename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//James modified start1
	jvm_file_attachfilepath_ucs(END_OF_MOD_ID,filename,NULL,KAL_TRUE);    
//James modified end1
    handle = FS_Open(WCHARFilename, flags);

    if (handle < 0)
    {
        g_jvm_file_error_code = handle;
        tempfilename = get_ctrl_buffer((get_ucs2_len(filename)+1)<<1);
        trans_ucs2_to_utf8(tempfilename,filename);
        for (i = 0; i < file_count; i++)
        {
            if (strcmp(tempfilename, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
            {
                file = (jvm_file_struct * ) get_ctrl_buffer(sizeof(jvm_file_struct));

                file->type = JVM_FILE_TYPE_VRITUAL;
                file->position = 0;
                file->size = work_info_ptr->virtual_file_info.virtual_file_size[i];
                file->data = (kal_uint8*) work_info_ptr->virtual_file_info.virtual_file_data[i];
                return (int)file;
            }
        }
        free_ctrl_buffer(tempfilename);

        /* the file is neigher in real file system nor virtual file system */
        return -1;
    }

    file = (jvm_file_struct * ) get_ctrl_buffer(sizeof(jvm_file_struct));
    file->type = JVM_FILE_TYPE_NORMAL;
    file->handle = handle;

    return (int)file;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_close(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_CLOSE);
    return jvm_mvm_file_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_commit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]           
 * RETURNS
 *  kal_int32   return value of FS_Commit() or (-1) if incorrect input handle
 *****************************************************************************/
kal_int32 jvm_file_commit(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jvm_mvm_file_commit(handle);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?] 
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_read(int handle, void *buf, int count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jvm_mvm_file_read(handle,buf,count);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [IN]        
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_write(int handle, const void *buf, int count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_WRITE);    
    
    return jvm_mvm_file_write(handle,buf,count);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_lseek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  offset      [IN]        
 *  whence      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_lseek(int handle, int offset, int whence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK, offset, whence);       

    return jvm_mvm_file_lseek(handle,offset,whence);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_getc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_getc(int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_GETC);      

    return jvm_mvm_file_getc(handle);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_truncate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_truncate(int handle, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_TRUNCATE, length);      
    return jvm_mvm_file_truncate( handle, length);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_getsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  sz_ptr      [?] 
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_getsize(int handle, kal_uint32 *sz_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_GETSIZE);
    return jvm_mvm_file_getsize(handle, sz_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_findfirst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [?] 
 * RETURNS
 *  
 *****************************************************************************/
// 20101229: [MAUI_02731591] Changed
char *jvm_file_findfirst(char *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FS_DOSDirEntry info;
///    WCHAR name_pattern[MAX_WCHAR_FILENAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_FIND_FIRST); 

    kal_sprintf(jvm_file_name_buffer, "%s\\%s", work_dir_path, string);
    memset(CHARFilename,0x00,MAX_WCHAR_FILENAME_LEN*sizeof(char));
    KVM_FindFilehandle = jvm_mvm_file_findfirst(jvm_file_name_buffer,CHARFilename,MAX_WCHAR_FILENAME_LEN, 0);
    if(KVM_FindFilehandle > 0)
        return CHARFilename;
    else
        return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_findnext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
// 20101229: [MAUI_02731591] Changed
char *jvm_file_findnext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FS_DOSDirEntry info;
    //int file_count = work_info_ptr->virtual_file_info.virtual_file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_FIND_NEXT); 
    if(jvm_mvm_file_findnext(CHARFilename,MAX_WCHAR_FILENAME_LEN, 0) == FS_NO_ERROR)
        return CHARFilename;
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_get_last_errcode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  filename        [?](?)
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_get_last_errcode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jvm_file_error_code;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_isexist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?] 
 * RETURNS
 *  
 *****************************************************************************/
int jvm_file_isexist(char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type active_module_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* system files are files except .db(.rss), .jar files */
      //James modified start1    
	 jvm_file_attachfilepath(active_module_id,filename, NULL, KAL_TRUE);
     return jvm_mvm_file_isexist((const char *)jvm_file_name_buffer);     
    //James modified end1
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_isexist_ucs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?] 
 * RETURNS
 *  
 *****************************************************************************/
#if defined( __NEMO_VM__)  || defined( __IJET_VM__)
int jvm_file_isexist_ucs(unsigned short *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char* tempfilename = NULL;
    module_type active_module_id = kal_get_active_module_id();    
    WCHAR temp_filename[MAX_WCHAR_FILENAME_LEN]; //James modified start1
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* system files are files except .db(.rss), .jar files */
//James modified start1
	jvm_file_attachfilepath_ucs(active_module_id,filename,NULL,KAL_TRUE);   
        
       memset(temp_filename,0, sizeof(temp_filename));

        if(active_module_id == MOD_JAM)        
        memcpy(temp_filename,WCHARFilename_JAM, sizeof(temp_filename));
        else
        memcpy(temp_filename,WCHARFilename, sizeof(temp_filename));            
        
     if (FS_GetAttributes(temp_filename) < 0)
        {
            int i, file_count = work_info_ptr->virtual_file_info.virtual_file_count;

            tempfilename = get_ctrl_buffer((get_ucs2_len(filename)+1)<<1);
            trans_ucs2_to_utf8(tempfilename,filename);

            /* if didn't find that, try virtual files */
            for (i = 0; i < file_count; i++)
            {
                if (strcmp(tempfilename, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
                {
                    free_ctrl_buffer(tempfilename);
                    return 1;
                }
            }
            free_ctrl_buffer(tempfilename);
            return 0;
        }
        else
        {
            return 1;
        }    
//James modified end1
}
#endif /* defined(__NEMO_VM__) || defined(__IJET_VM__) */ /* __NEMO_VM__ or __IJET_VM__ */


/*****************************************************************************
 * FUNCTION
 *  jvm_file_get_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_letter     [kal_char] 
 * RETURNS
 *  void
 *****************************************************************************/
kal_int64 jvm_file_get_free_space(kal_char drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    kal_int64 disk_free_space;
    kal_int32 fs_ret;
    kal_wchar path[10];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    g_jvm_cluster_size = disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    
    if (fs_ret < 0)
    {
        return -1;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
                          
        return (disk_free_space - disk_info.BytesPerSector);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_get_cluster_size
 * DESCRIPTION
 *  get cluster size of drv_letter which is input of jvm_file_get_free_space,
 *  It is used for saving calculating time. Therefore, Be sure to use 
 *  jvm_file_get_free_space first, then call jvm_file_get_cluster_size.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jvm_file_get_cluster_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jvm_cluster_size;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_file_device_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?] 
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_device_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_FMT_MMI_CARD_PLUG_IN_IND:

            /*
             * if the Java task has been paused, we don't have to handle the message.
             * * The disk info will be retrieved again on resume. 
             */
            if (jam_mvm_has_work_instance() && jam_vm_is_busy())
            {
                int i;

                for (i = 0; i < 25; i++)
                {
                    if ((disk_info[i].drive_type == FS_DRIVE_V_REMOVABLE) && (disk_info[i].serial == 1))
                    {
                        disk_info[i].is_mounted = KAL_TRUE;
                        disk_changed = KAL_TRUE;
                        jvm_file_disk_changed_callback_handler();
                    }
                }
            }
            /* If JVM is waiting for message to wakeup, send the message */
            if (g_jvm_keypad_need_notify)
            {
                g_jvm_keypad_need_notify = KAL_FALSE;
                java_send_msg_from_active_mod(MOD_J2ME,MMI_J2ME_SAP,MSG_ID_JAVA_KEYPAD_NOTIFY_IND,NULL);
            }

            /*
             * pause VM for a while, let FMT task can complete drive checking.
             * * XXX, the mechanism should apply to other VM solution, too.
             */
            g_jvm_card_plugin_event = 10;
            kal_sleep_task(40);

            break;
        case MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND:
            /*
             * if the Java task has been paused, we don't have to handle the message.
             * * The disk info will be retrieved again on resume.
             */
            if (jam_mvm_has_work_instance() && jam_vm_is_busy())
            {
                int i;

                for (i = 0; i < 25; i++)
                {
                    if ((disk_info[i].drive_type == FS_DRIVE_V_REMOVABLE) && (disk_info[i].serial == 1))
                    {
                        disk_info[i].is_mounted = KAL_FALSE;
                        disk_changed = KAL_TRUE;
                        jvm_file_disk_changed_callback_handler();
                    }
                }
            }

            /* If JVM is waiting for message to wakeup, send the message */
            if (g_jvm_keypad_need_notify)
            {
                g_jvm_keypad_need_notify = KAL_FALSE;
                java_send_msg_from_active_mod(MOD_J2ME,MMI_J2ME_SAP,MSG_ID_JAVA_KEYPAD_NOTIFY_IND,NULL);
            }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _jvm_file_is_disk_avialable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool _jvm_file_is_disk_avialable(char drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE temp_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disk_access_name[0] = drive + 'A';
    temp_handle = FS_Open(disk_access_name, FS_OPEN_DIR | FS_READ_ONLY);
    if (temp_handle >= 0)
    {
        FS_Close(temp_handle);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_update_diskinfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_update_diskinfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    int drive_num;
    int temp_id;
    kal_wchar *temp_name;
#if 0
/* under construction !*/
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* drive_type 0 means invalid type. */
    for (i = 0; i < 25; i++)
    {
        disk_info[i].drive_type = 0;
    }

    drive_num = jvm_initDrvTable();


    for (i = 0; i < drive_num; i++)
    {
        temp_id = drv_array[i] - 'A';
        disk_info[temp_id].is_mounted = KAL_TRUE;
        disk_info[temp_id].drive_type = FS_DRIVE_V_REMOVABLE; /* just pass following check */
        disk_info[temp_id].serial = 1;
        temp_name = jvm_getAliasDrive(i);
        jvm_free(temp_name);
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

}


/*****************************************************************************
 * FUNCTION
 *  check_and_create_hidden_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder      [?] 
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 check_and_create_hidden_folder(kal_wchar *folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 attribute = FS_GetAttributes(folder);
    kal_int32 return_code = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (attribute > 0)
    {
        /* this directory maybe exists */
        if ((attribute & FS_ATTR_DIR) == FS_ATTR_DIR)
        {
            /* add hidden attribute */
            if ((attribute & FS_ATTR_HIDDEN) != FS_ATTR_HIDDEN)
            {
                FS_SetAttributes(folder, (BYTE) (attribute | FS_ATTR_HIDDEN));
            }
            return return_code;
        }
        else
        {   /* This is a file. The file should not be there */
            FS_Delete(folder);
        }
    }
    /* this directory doesn't exist. Create the directory */
    return_code = FS_CreateDir(folder);
    if (return_code != FS_NO_ERROR)
    {
        return return_code;
    }
    FS_SetAttributes(folder, (BYTE) (attribute | FS_ATTR_HIDDEN));
    return return_code;
}

/* Dennis Shih */
extern j2me_custom_resource_info_struct g_jvm_resource_info;


/*****************************************************************************
 * FUNCTION
 *  getAliasDrive
 * DESCRIPTION
 *  Get the alias drive from j2me_custom_resource_info_struct by index.
 * PARAMETERS
 *  idx     [IN]        The index of the alias drive in the structure.
 * RETURNS
 *  The alias drive name.
 *****************************************************************************/
kal_char *getAliasDrive(int idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *aliasname = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aliasname = g_jvm_resource_info.alias_drive[idx];
    return aliasname;
}

/* Dennis Shih */


/*****************************************************************************
 * FUNCTION
 *  getAliasDriveType
 * DESCRIPTION
 *  Get the alias drive type from j2me_custom_resource_info_struct by index.
 * PARAMETERS
 *  idx     [IN]        The index of the alias drive in the structure.
 * RETURNS
 *  The alias drive type.
 *****************************************************************************/
kal_int32 getAliasDriveType(int idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < 0)
        return -1;
    return g_jvm_resource_info.alias_drive_type[idx];
}

/* Dennis Shih */


/*****************************************************************************
 * FUNCTION
 *  getRealDrive
 * DESCRIPTION
 *  Get the real drive name by FS_GetDrive().
 * PARAMETERS
 *  type        [IN]        The type of the drive.
 * RETURNS
 *  The real drive name.
 *****************************************************************************/
kal_int32 getRealDrive(int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int realdrive = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == FS_DRIVE_V_NORMAL)
    {
        realdrive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    }
    else
    {
        realdrive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    }
    realdrive -= 'A';
    return realdrive;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_initDrvTable
 * DESCRIPTION
 *  Get the real drive name by FS_GetDrive().
 * PARAMETERS
 *  type        [IN]        The type of the drive.
 * RETURNS
 *  The real drive name.
 *****************************************************************************/
kal_int32 jvm_initDrvTable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char drv_num = 0;
    int i = 0;
        SRV_FMGR_DRVLIST_HANDLE handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);

        drv_num = srv_fmgr_drivelist_count(handle);

        for (; i < drv_num; i++)
        {
            drv_array[i] = srv_fmgr_drivelist_get_drv_letter(handle, i);
        }

        srv_fmgr_drivelist_destroy(handle);
    
    return (kal_int32)drv_num;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_getAliasDrive
 * DESCRIPTION
 *  Get the real drive name by FS_GetDrive().
 * PARAMETERS
 *  type        [IN]        The type of the drive.
 * RETURNS
 *  The real drive name.
 *****************************************************************************/

kal_wchar* jvm_getAliasDrive(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *AliasName;
    //kal_char *AliasName_utf8;
    //kal_int32 str_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AliasName = jvm_malloc((SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);
    if(AliasName == NULL)
        return AliasName;
    srv_fmgr_drv_get_name((U8)drv_array[index], (WCHAR*)AliasName, (SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);

    //str_len = get_ucs2_len(AliasName);
    //AliasName_utf8 = jvm_malloc(str_len + 1);
    
    //trans_ucs2_to_utf8(AliasName_utf8,AliasName);
    //jvm_free(AliasName);
    return AliasName;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_getRealDrive
 * DESCRIPTION
 *  Get the real drive name by FS_GetDrive().
 * PARAMETERS
 *  type        [IN]        The type of the drive.
 * RETURNS
 *  The real drive name.
 *****************************************************************************/
kal_int32 jvm_getRealDrive(kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 return_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_value = (kal_int32) (drv_array[index] - 'A');
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_need_backup_AliasTable
 * DESCRIPTION
 *  check if need to backup Alias table
 * PARAMETERS
 *  void       
 * RETURNS
 *  The real drive name.
 *****************************************************************************/
kal_int32 jvm_file_need_backup_AliasTable()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_aliasTable_node_struct *prev_node = NULL;
    jvm_file_aliasTable_node_struct *temp_node = g_jvm_file_aliasTable_node_start;
    int temp_id = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE);
    kal_wchar *AliasName;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* we use phoneDisk as keyword to query if need backup AliasTable */
    AliasName = jvm_malloc((SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);
    if(AliasName==NULL)
        return -1;
    srv_fmgr_drv_get_name((U8)temp_id, (WCHAR*)AliasName, (SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH);
    while (temp_node)
    {
        if (mmi_ucs2cmp((S8*)temp_node->alias_name,(S8*)AliasName) == 0)
        {
              jvm_free(AliasName);
            return (0);
        }
        prev_node = temp_node;
        temp_node = temp_node->next;
    }
    /* do not mapping, add to link list */
    temp_node = (jvm_file_aliasTable_node_struct*)jvm_malloc(sizeof(jvm_file_aliasTable_node_struct));
    temp_node->next = NULL;
    temp_node->alias_name = (kal_wchar*)jvm_malloc((get_ucs2_len(AliasName)+1)<<1);
    mmi_ucs2cpy((S8*)temp_node->alias_name,(S8*)AliasName);
    jvm_free(AliasName);
    if (prev_node == NULL)
    {
        g_jvm_file_aliasTable_node_start = temp_node;
    }
    else
    {
        prev_node->next = temp_node;
    }
    return (1);

}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_finalize_aliasTable_node
 * DESCRIPTION
 *  finalize Alias table node
 * PARAMETERS
 *  void       
 * RETURNS
 *  The real drive name.
 *****************************************************************************/
void jvm_file_finalize_aliasTable_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_aliasTable_node_struct *temp_node = g_jvm_file_aliasTable_node_start;
    jvm_file_aliasTable_node_struct *next_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (temp_node)
    {
        next_node = temp_node->next;
        jvm_free(temp_node->alias_name);
        jvm_free(temp_node);
        temp_node = next_node;
    }
    g_jvm_file_aliasTable_node_start = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_create_recursive
 * DESCRIPTION
 *  Checks whether every part of the given path exists (directories)
 *  and creates them if they do not exist.
 * PARAMETERS
 *  path        [IN]        The null-terminated, UCS2 encoded
 * RETURNS
 *****************************************************************************/
kal_int32 jvm_file_create_recursive(const kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *wpath, *ptr;
    kal_int32 error = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!path)
    {
        return -1;
    }

    wpath = (kal_wchar*) get_ctrl_buffer((app_ucs2_strlen((kal_int8*)path) + 1) * 2);
    app_ucs2_strcpy((kal_int8*)wpath, (kal_int8*)path);

    ptr = wpath;
    while ((ptr = kal_wstrchr(ptr, L'\\')) != NULL)
    {
        if (*(ptr - 1) != L':')
        {
            *ptr = L'\0';
            error = FS_CreateDir(wpath);
            *ptr = L'\\';
        }
        ptr++;
    }

    error = FS_CreateDir(wpath);

    free_ctrl_buffer(wpath);

    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_file_create_recursive, error_code=%d",error);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_convert_fs_handle
 * DESCRIPTION
 *  Added for covert j9 file to jvm file handle
 * PARAMETERS
 *  fsHandle        [IN]        file handle
 * RETURNS
 *****************************************************************************/
kal_int32 jvm_convert_fs_handle(kal_int32 fsHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct *  file = (jvm_file_struct * ) get_ctrl_buffer(sizeof(jvm_file_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file->type = JVM_FILE_TYPE_NORMAL;
    file->handle = fsHandle;

    return(kal_int32)file;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_register_disk_changed_callback
 * DESCRIPTION
 *  register the callback function for retrieve disk plug in and plug out indication.
 * PARAMETERS
 *  callback_ptr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_register_disk_changed_callback(void (*callback_ptr)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_file_disk_changed_callback = callback_ptr;
      return;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_deregister_disk_changed_callback
 * DESCRIPTION
 *  deregister the callback function for retrieve disk plug in and plug out indication.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_deregister_disk_changed_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_file_disk_changed_callback = NULL;
      return;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_file_disk_changed_callback_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_file_disk_changed_callback_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jvm_file_disk_changed_callback != NULL)
    {
        (*jvm_file_disk_changed_callback)();
    }
}
//James modified start1
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
#ifdef JVM_FILE_DEBUG_SUPPORT    
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
#ifdef JVM_FILE_DEBUG_SUPPORT 
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
#ifdef __DRM_SUPPORT__
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
#endif /* __DRM_SUPPORT__ */ 
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
//James modified end1

/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_mvm_file_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_J2ME_JVM_FILE_INITIALIZE);

    for( index = 0 ; index < MAX_VM_INSTANCE_NUM ;index++)
    {
        kal_trace(TRACE_GROUP_9, JVM_FIND_FILE_HANDLE_2_INDEX, index, jvm_find_file_handle_2_index[index]);
        jvm_find_file_handle_2_index[index] = - 1;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_open(const kal_char * file_path ,int flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_int32 file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    kal_int32 i;
    #ifdef JVM_FILE_DEBUG_SUPPORT
    kal_int32 file_name_length = 0;
    #endif
    kal_char * file_name;
    jvm_file_struct * file;
    kal_wchar * file_path_w = jvm_file_name_buffer_w;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //James modified start1
    #ifdef __JVM_FILE_CACHE_SUPPORT__
    file = jvm_mvm_file_get_cached_file(file_path);
    #else
        file = NULL;
    #endif /* __JVM_FILE_CACHE_SUPPORT__ */
    //James modified end1
    if(file != NULL)
    {
        return (int)file;
    }
    
    kal_wsprintf(file_path_w,"%s",file_path);
    handle = DRM_open_file(file_path_w, flags, DRM_PERMISSION_EXECUTE);

#ifdef JVM_FILE_DEBUG_SUPPORT   
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_open,file_path=%s,handle=%d",file_path,handle);
#endif     
    if (handle < 0)
    {
        g_jvm_file_error_code = handle;  
        file_name = jvm_mvm_file_get_file_name(file_path);
        if(file_name != NULL)
        {
            for (i = 0; i < file_count; i++)
            {
                if (strcmp(file_name, work_info_ptr->virtual_file_info.virtual_file_name[i]) == 0)
                {
                    file = (jvm_file_struct *) get_ctrl_buffer(sizeof(jvm_file_struct));
                    ASSERT(file != NULL);
                    memset(file,0x00,sizeof(jvm_file_struct));
                    file->type = JVM_FILE_TYPE_VRITUAL;
                    file->position = 0;
                    file->size = work_info_ptr->virtual_file_info.virtual_file_size[i];
                    file->data = (kal_uint8*) work_info_ptr->virtual_file_info.virtual_file_data[i];
                    jvm_trace_time("[Performane][TIME] get vritual file",JVM_TRACE_TYPE_DEBUG);
                    return (int)file;
                }
            }
        }
        
        /* the file is neigher in real file system nor virtual file system */
        return -1;
    }
     //James modified start1
     #ifdef __JVM_FILE_CACHE_SUPPORT__
    if(jvm_mvm_file_is_cached_enabled() && strcmp((file_path + strlen(file_path) - 4), ".jar") == 0)
    {
        file = (jvm_file_struct *)jvm_mvm_file_cached_open(file_path,handle);
        if(file != NULL)
            return (int)file;
    }
    #endif /* __JVM_FILE_CACHE_SUPPORT__ */
    //James modified end1
    file = (jvm_file_struct *) get_ctrl_buffer(sizeof(jvm_file_struct));
    ASSERT(file != NULL);
    file->type = JVM_FILE_TYPE_NORMAL;
    file->handle = handle;

#ifdef JVM_FILE_DEBUG_SUPPORT
    memset(file->filename,0x00,10);
    file_name_length = strlen(file_path);

    if(file_name_length < 10)
    {
        memcpy(file->filename,file_path,file_name_length);
    }
    else
    {
        memcpy(file->filename,file_path + file_name_length - 10,10);
    }
    
#endif /* JVM_FILE_DEBUG_SUPPORT */
    
#if defined(__DRM_SUPPORT__)
    if (file->type == JVM_FILE_TYPE_NORMAL && DRM_get_object_method(handle, NULL) != DRM_METHOD_NONE)
    {
        file->type = JVM_FILE_TYPE_DRM;
    }
#endif /* defined(__DRM_SUPPORT__) */ 
    
#if defined(ENCRYPT_JAR_FILE)
    if (file->type == JVM_FILE_TYPE_NORMAL && strcmp((file_path + strlen(file_path) - 4), ".jar") == 0)
    {
        file->encrypt_code = get_base_code(handle);
        file->type = JVM_FILE_TYPE_ENCRYPTED_JAR;
    }
#endif /* defined(ENCRYPT_JAR_FILE) */ 

#ifdef JVM_FILE_DEBUG_SUPPORT 
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_open,file_handle=%d",file);
#endif

    
    ////if(jam_mvm_get_current_vm_id() >= 0 )
    ////    jvm_resource_mgr_register(jam_mvm_get_current_vm_id(),JAVA_SYS_FILE_DEVICE, (kal_int32)file, NULL, NULL, &jvm_mvm_file_finalize_callback);
    return (kal_int32)file;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_close(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * jvm_file_handle = (jvm_file_struct *) handle;
    kal_int32 file_handle;
    kal_int32 result;
    kal_int32 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef JVM_FILE_DEBUG_SUPPORT    
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_close,handle=%d",handle);
#endif 

    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;
        return -1;
    }

    file_handle = jvm_file_handle->handle;
    
    if (jvm_file_handle->type == JVM_FILE_TYPE_NORMAL|| jvm_file_handle->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
    {
        if ((err = FS_Close(file_handle)) == FS_NO_ERROR)
        {
#ifdef JVM_FILE_DEBUG_SUPPORT 
            kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_close,file handle=%d",file_handle);
#endif
            result = 0;

            jvm_file_handle->handle = -1;
        }
        else
        {
            g_jvm_file_error_code = err;
            result = -1;
        }
    }
    
#ifdef __DRM_SUPPORT__
    else if (jvm_file_handle->type == JVM_FILE_TYPE_DRM)
    {
        if ((err = DRM_close_file(file_handle)) == FS_NO_ERROR)
        {
            result = 0;

            jvm_file_handle->handle = -1;
        }
        else
        {
            g_jvm_file_error_code = err;        
            result = -1;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    else if (jvm_file_handle->type == JVM_FILE_TYPE_VRITUAL)
    {
        result = 0;
    }
    else
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;
        result = -1;
    }

    if (  (jvm_file_handle->type == JVM_FILE_TYPE_NORMAL) 
        ||(jvm_file_handle->type == JVM_FILE_TYPE_VRITUAL)
        ||(jvm_file_handle->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
        ||(jvm_file_handle->type == JVM_FILE_TYPE_DRM)
       )
    {
        jvm_file_handle->type = 0;
        memset(jvm_file_handle,0x00,sizeof(jvm_file_struct));
        free_ctrl_buffer((unsigned char*)jvm_file_handle);
    }
    else if(jvm_file_handle->type == JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR)
    {
        jvm_file_handle->type = 0;

        memset(jvm_file_handle,0x00,sizeof(jvm_file_struct));
        jvm_free(jvm_file_handle);

        if (jvm_file_cache_data != NULL)
        {
            jvm_file_cache_data->ref_count--;
        }

    }

    ////if(jam_mvm_get_current_vm_id() >= 0 )
    ////    jvm_resource_mgr_deregister(jam_mvm_get_current_vm_id(),JAVA_SYS_FILE_DEVICE, (kal_int32)jvm_file_handle);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]            
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_delete(const kal_char *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 err;  
    kal_wchar * file_path_w = jvm_file_name_buffer_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT 
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_delete,handle=%s",file_path);
#endif

    kal_wsprintf(file_path_w,"%s",file_path);
    /* this is to prevent removing a read only file */
    FS_SetAttributes(file_path_w, 0);
    if ((err = FS_Delete(file_path_w)) == FS_NO_ERROR)
    {
        return 0;
    }
    else
    {
        g_jvm_file_error_code = err;
        return -1;
    }
       
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_commit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]           
 * RETURNS
 *  kal_int32   return value of FS_Commit() or (-1) if incorrect input handle
 *****************************************************************************/
kal_int32 jvm_mvm_file_commit(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * jvm_file = (jvm_file_struct *) handle;
    kal_int32 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_commit,handle=%d",handle);
#endif 

    if (handle < 0)
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;
        return (-1);
    }
    if (jvm_file->type == JVM_FILE_TYPE_NORMAL)   
    {
        err = FS_Commit(jvm_file->handle);
        g_jvm_file_error_code = err;
        return err;
    }
    else
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;
        return (-1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [?] 
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_read(kal_int32 handle, void *buf, kal_int32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * file = (jvm_file_struct *) handle;
    jvm_file_cache_data_struct * jvm_file_cache_data ;
    kal_int32 err;
    kal_uint8 * data = NULL;
    kal_int32 data_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_read,handle=%d,buf=%d,count=%d",handle,buf,count);
#endif 

    ASSERT(buf!=NULL);
    
    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;    
        return -1;
    }

    if (file->type == JVM_FILE_TYPE_NORMAL)
    {
        kal_uint32 real_count = 0;

    #if DATACACHE_FBBR_ON
        /* this function is only workable when DATACACHE_FBBR_ON is 1 */
        buf = (char*)FBBR_invalid_l1_cache(buf, count);
    #endif /* DATACACHE_FBBR_ON */ 
        if ((err = FS_Read(file->handle, buf, count, &real_count)) == FS_NO_ERROR)
        {
            return real_count;
        }
        else
        {
            g_jvm_file_error_code = err;        
            return -1;
        }
    }
#ifdef __DRM_SUPPORT__
    else if (file->type == JVM_FILE_TYPE_DRM)
    {
        kal_uint32 real_count = 0;

    #if DATACACHE_FBBR_ON
        /* this function is only workable when DATACACHE_FBBR_ON is 1 */
        buf = (char*)FBBR_invalid_l1_cache(buf, count);
    #endif /* DATACACHE_FBBR_ON */ 
        if ((err = DRM_read_file(file->handle, buf, count, &real_count)) == FS_NO_ERROR)
        {
            return real_count;
        }
        else
        {
            g_jvm_file_error_code = err;        
            return -1;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

#ifdef ENCRYPT_JAR_FILE
    else if (file->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
    {
        kal_uint32 real_count = 0;
        kal_uint32 pos = FS_Seek(file->handle, 0, SEEK_CUR);

    #if DATACACHE_FBBR_ON
        /* this function is only workable when DATACACHE_FBBR_ON is 1 */
        buf = (char*)FBBR_invalid_l1_cache(buf, count);
    #endif /* DATACACHE_FBBR_ON */ 
        if ((err = FS_Read(file->handle, buf, count, &real_count)) == FS_NO_ERROR)
        {
            #ifdef __ENCRYPT_OPTIMIZE__  
            kal_int32 file_size=0;
            FS_GetFileSize(file->handle,&file_size);
            decrypt_buffer(buf, file->encrypt_code, pos, real_count, file_size);
            #else
            decrypt_buffer(buf, file->encrypt_code, pos, real_count);
            #endif
            return real_count;
        }
        else
        {
            g_jvm_file_error_code = err;        
            return -1;
        }
    }
#endif /* ENCRYPT_JAR_FILE */    
    else if(file->type == JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR)
    {
        if (file->size < file->position)
        {
            g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;            
            return -1;
        }

        if (file->size < file->position + count)
        {
            count = file->size - file->position;
        }
        
        jvm_file_cache_data = (jvm_file_cache_data_struct *)(file->data);

        if(jvm_file_cache_data  != NULL)
        {
            data = jvm_file_cache_data->data;
            data_size = jvm_file_cache_data->data_size;
        }
        
        if(data != NULL && data_size > 0 && jvm_file_cache_data->file_handle == file->handle)
        {
            if(file->position >= jvm_file_cache_data->start_index && (file->position + count) <= jvm_file_cache_data->end_index)
            {
                data += (file->position - jvm_file_cache_data->start_index);
            }
            else if(count <= data_size)
            {
                kal_uint32 real_count = 0;
                kal_uint32 pos = 0;

                ////jvm_trace_time("[Performance][TIME] before read",JVM_TRACE_TYPE_DEBUG);
                pos = FS_Seek(file->handle, file->position, SEEK_SET);
#if DATACACHE_FBBR_ON
                /* this function is only workable when DATACACHE_FBBR_ON is 1 */
                buf = (char*)FBBR_invalid_l1_cache(buf, count);
#endif /* DATACACHE_FBBR_ON */ 

                if ((err = FS_Read(file->handle, data, data_size, &real_count)) == FS_NO_ERROR)
                {
                    #ifdef __ENCRYPT_OPTIMIZE__  
                    kal_int32 file_size=0;
                    FS_GetFileSize(file->handle,&file_size);
                    decrypt_buffer(buf, file->encrypt_code, pos, real_count, file_size);
                    #else                
                    decrypt_buffer(data, file->encrypt_code, pos, real_count);
                    #endif
                    jvm_file_cache_data->start_index = pos;
                    jvm_file_cache_data->end_index = pos + real_count;
                }
                else
                {
                    jvm_file_cache_data->start_index = -1;
                    jvm_file_cache_data->end_index = -1;
                    g_jvm_file_error_code = err;        
                    return -1;
                }
                ////jvm_trace_time("[Performance][TIME] read end",JVM_TRACE_TYPE_DEBUG);            
            }   
            else
            {
                kal_uint32 real_count = 0;
                kal_uint32 pos = FS_Seek(file->handle, file->position, SEEK_SET);

#if DATACACHE_FBBR_ON
                /* this function is only workable when DATACACHE_FBBR_ON is 1 */
                buf = (char*)FBBR_invalid_l1_cache(buf, count);
#endif /* DATACACHE_FBBR_ON */ 
                if ((err = FS_Read(file->handle, buf, count, &real_count)) == FS_NO_ERROR)
                {
                    #ifdef __ENCRYPT_OPTIMIZE__  
                    kal_int32 file_size=0;
                    FS_GetFileSize(file->handle,&file_size);
                    decrypt_buffer(buf, file->encrypt_code, pos, real_count, file_size);
                    #else                
                    decrypt_buffer(buf, file->encrypt_code, pos, real_count);
                    #endif
             
                    file->position = pos + real_count;
                    return real_count;
                }
                else
                {
                    g_jvm_file_error_code = err;        
                    return -1;
                }            
            }

            file->position += count;
            memcpy(buf, data, count);
            return count;
        }
        else
        {
            kal_uint32 real_count = 0;
            kal_uint32 pos = FS_Seek(file->handle, file->position, SEEK_SET);

#if DATACACHE_FBBR_ON
            /* this function is only workable when DATACACHE_FBBR_ON is 1 */
            buf = (char*)FBBR_invalid_l1_cache(buf, count);
#endif /* DATACACHE_FBBR_ON */ 
            if ((err = FS_Read(file->handle, buf, count, &real_count)) == FS_NO_ERROR)
            {
                #ifdef __ENCRYPT_OPTIMIZE__  
                kal_int32 file_size=0;
                FS_GetFileSize(file->handle,&file_size);
                decrypt_buffer(buf, file->encrypt_code, pos, real_count, file_size);
                #else             
                decrypt_buffer(buf, file->encrypt_code, pos, real_count);
                #endif
                file->position = pos + real_count;
                return real_count;
            }
            else
            {
                g_jvm_file_error_code = err;        
                return -1;
            }              
        }
    }
    else if (file->type == JVM_FILE_TYPE_VRITUAL)
    {
        kal_int32 file_size = file->size;
        kal_int32 position = file->position;
        kal_uint8 *file_data = file->data + position;

        if (file_size < position)
        {
            g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;            
            return -1;
        }

        if (file_size < position + count)
        {
            count = file_size - position;
        }
        file->position += count;
        memcpy(buf, file_data, count);
        return count;
    }
    else
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;        
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  buf         [IN]        
 *  count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_write(kal_int32 handle, const void *buf, kal_int32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 real_count = 0;
    jvm_file_struct * file = (jvm_file_struct *) handle;
    kal_int32 err; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT 
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_write,handle=%d,buf=%d,count=%d",handle,buf,count);
#endif

    ASSERT(buf!=NULL);
    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_WRITE_FAIL, 0);  
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;    
        return -1;
    }

    if ((file->type == JVM_FILE_TYPE_NORMAL))
    {
    #if DATACACHE_FBBR_ON

        /* this function is only workable when DATACACHE_FBBR_ON is 1 */
        buf = (const void*)FBBR_invalid_l1_cache((void*)buf, count);
    #endif /* DATACACHE_FBBR_ON */ 
        if ((err = FS_Write(file->handle, (void*)buf, count, &real_count)) == FS_NO_ERROR)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_WRITE_COUNT, real_count);        
            return real_count;
        }
        else
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_WRITE_FAIL, 1);                
            g_jvm_file_error_code = err;                
            return -1;
        }
    }
    
#ifdef ENCRYPT_JAR_FILE
    else if (file->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
    {
#ifdef JVM_FILE_DEBUG_SUPPORT
        jvm_trace_error("[JVM_FILE]can't write jar file,name=%s\n",file->filename);
#endif /* JVM_FILE_DEBUG_SUPPORT */
        ASSERT(0);
    }
#endif /* ENCRYPT_JAR_FILE */ 

    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_WRITE_FAIL, 2);   
    g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;    
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_getc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_getc(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char buffer;
    kal_int32 read_bytes = jvm_mvm_file_read(handle, (void*)&buffer, 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT 
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_getc,handle=%d",handle);
#endif

    if (read_bytes != 1)
    {
        g_jvm_file_error_code = read_bytes;    
        return (-1);
    }
    else
    {
        return ((kal_int32)buffer);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_lseek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  offset      [IN]        
 *  whence      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_lseek(kal_int32 handle, kal_int32 offset, kal_int32 whence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * file = (jvm_file_struct *) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_lseek,handle=%d,offset=%d,whence=%d",handle,offset,whence);
#endif

    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_FAIL, 0);      
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;            
        return -1;
    }

    if (file->type == JVM_FILE_TYPE_NORMAL|| file->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
    {
        int result = FS_Seek(file->handle, offset, whence);

        if (result < 0)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_FAIL, 1);          
            g_jvm_file_error_code = result;    
            return -1;
        }
        else
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_POSITION, result);          
            return result;
        }
    }
    
#ifdef __DRM_SUPPORT__
    else if (file->type == JVM_FILE_TYPE_DRM)
    {
        int result = DRM_seek_file(file->handle, offset, (kal_uint8) whence);

        if (result < 0)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_FAIL, 2);          
            g_jvm_file_error_code = result;    
            return -1;
        }
        else
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_POSITION, result);          
            return result;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    else if (file->type == JVM_FILE_TYPE_VRITUAL
          || file->type == JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR)
    {
        int position = file->position;

        switch (whence)
        {
            case SEEK_SET:
                position = offset;
                break;
            case SEEK_CUR:
                position += offset;
                break;
            case SEEK_END:
                position = file->size + offset;
                break;
            default:
                g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;    
                return -1;
                //break;
        }

        if (position < 0 || position > file->size)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_POSITION, -1);          
            return EOF;
        }
        file->position = position;
        kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_POSITION, position);  
        return position;
    }
    kal_trace(TRACE_GROUP_9, FUNC_JVM_FILE_LSEEK_FAIL, 3);  
    g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;        
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_truncate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_truncate(kal_int32 handle, kal_int32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * file = (jvm_file_struct *) handle;
    kal_int32 err = FS_MINIMUM_ERROR_CODE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_truncate,handle=%d,length=%d",handle,length);
#endif

    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;        
        return -1;
    }

    if ((file->type == JVM_FILE_TYPE_NORMAL))
    {
        if ((err = FS_Seek(file->handle, length, FS_FILE_BEGIN)) >= 0)
        {
            if ((err = FS_Truncate(file->handle)) == FS_NO_ERROR)
            {
                return handle;
            }
        }
    }
    g_jvm_file_error_code = err;    
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_getsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  sz_ptr      [?] 
 * RETURNS
 *  
 *****************************************************************************/
// 20101229: [MAUI_02731591] Changed
kal_int32 jvm_mvm_file_getsize(kal_int32 handle, kal_uint32 *sz_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct * file = (jvm_file_struct *) handle;
    kal_int32 err = FS_MINIMUM_ERROR_CODE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_getsize,handle=%d",handle);
#endif

    if ((handle == -1) || ((jvm_file_struct *)handle)->handle < 0)
    {
        g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;        
        return -1;
    }

    if (file->type == JVM_FILE_TYPE_NORMAL|| file->type == JVM_FILE_TYPE_ENCRYPTED_JAR)
    {
        if ((err = FS_GetFileSize(file->handle, sz_ptr)) == FS_NO_ERROR)
        {
            return 1;
        }
        else
        {
            g_jvm_file_error_code = err;    
            return 0;
        }
    }
#ifdef __DRM_SUPPORT__
    else if (file->type == JVM_FILE_TYPE_DRM)
    {
        if ((err = DRM_file_size(file->handle, sz_ptr)) == FS_NO_ERROR || *sz_ptr != 0)
        {
            return 1;
        }
        else
        {
            g_jvm_file_error_code = err;    
            return 0;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    else if (file->type == JVM_FILE_TYPE_VRITUAL|| file->type == JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR)
    {
        *sz_ptr = (kal_uint32) file->size;
        return 1;
    }
    g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;    
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_findfirst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name_pattern            [?]         
 *  firstFileName           [?]         
 *  name_buffer_length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
// 20101229: [MAUI_02731591] Changed
kal_int32 jvm_mvm_file_findfirst(const kal_char * name_pattern,kal_char * firstFileName,kal_int32 name_buffer_length, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry info;
    kal_wchar name_pattern_w[MAX_WCHAR_FILENAME_LEN];
    kal_int32 handle;
    kal_char * file_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef JVM_FILE_DEBUG_SUPPORT  
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_findfirst,name_pattern=%s vm_id=%d",name_pattern, vm_id);
 #endif       

    kal_wsprintf(name_pattern_w, "%s*", name_pattern);
    ASSERT(name_buffer_length > 0 && name_buffer_length <= 2 * MAX_WCHAR_FILENAME_LEN);
    handle = FS_FindFirst(name_pattern_w, 0, 0, &info, WCHARFilename, name_buffer_length);

    if (handle > 0 && (vm_id >= 0 && vm_id < MAX_VM_INSTANCE_NUM))
    {
        kal_dchar2char(WCHARFilename, firstFileName);

        jvm_find_file_handle_2_index[vm_id] = handle;

        file_name = jvm_mvm_file_get_file_name(name_pattern);
        
        if (file_name== NULL ||  file_name[0] == 0)
        {
            jvm_find_file_is_java_dir[vm_id] = KAL_TRUE;
        }
        else
        {
            jvm_find_file_is_java_dir[vm_id] = KAL_FALSE;
        }

        jvm_find_file_virtual_file_id[vm_id] = KAL_FALSE;
        jvm_find_file_from_virtual_file[vm_id] = KAL_FALSE;
        jvm_find_file_name_pattern[vm_id] = (kal_char *)name_pattern;
    }
    else
    {
        firstFileName[0] = 0;
        g_jvm_file_error_code = handle;
    }
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_findnext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  file_name       [?]         
 *  name_length     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
// 20101229: [MAUI_02731591] Changed
kal_int32 jvm_mvm_file_findnext(kal_char * file_name,kal_int32 name_length, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    FS_DOSDirEntry info;
    kal_int32 file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    //kal_int32 result;
    kal_char * temp_buff;
    kal_int32 temp_buff_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef JVM_FILE_DEBUG_SUPPORT    
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_findnext, handle=%d vm_id=%d",handle, vm_id);
 #endif   

    if (vm_id < 0 || vm_id >= MAX_VM_INSTANCE_NUM)
    {
        return FS_PARAM_ERROR;
    }

    handle = jvm_find_file_handle_2_index[vm_id];
    
    if (!jvm_find_file_from_virtual_file[vm_id])
    {
        ASSERT(file_name != NULL);
        ASSERT(name_length > 0 && name_length <= 2 * MAX_WCHAR_FILENAME_LEN);
        if ((FS_FindNext(handle, &info, WCHARFilename, 2 * MAX_WCHAR_FILENAME_LEN)) == FS_NO_ERROR)
        {
            kal_dchar2char(WCHARFilename, file_name);
            return FS_NO_ERROR;
        }
        else
        {
            jvm_find_file_from_virtual_file[vm_id] = KAL_TRUE;
            if (handle > 0)
            {
                FS_FindClose(handle);
            }
        }
    }

    if (jvm_find_file_is_java_dir[vm_id])
    {
        if (jvm_find_file_virtual_file_id[vm_id] < (kal_uint32) file_count)
        {
            temp_buff =
                (char*)work_info_ptr->virtual_file_info.virtual_file_name[jvm_find_file_virtual_file_id[vm_id]++];
            temp_buff_length = strlen(temp_buff);
            memcpy(file_name,temp_buff,temp_buff_length>name_length?name_length:temp_buff_length);
            return FS_NO_ERROR;
        }
        else
        {
            g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE; 
            jvm_find_file_handle_2_index[vm_id] = -1;
            return g_jvm_file_error_code;
        }
    }
    else
    {
        while (jvm_find_file_virtual_file_id[vm_id] < (kal_uint32) file_count)
        {
            if (strncmp
                (jvm_find_file_name_pattern[vm_id],
                 work_info_ptr->virtual_file_info.virtual_file_name[jvm_find_file_virtual_file_id[vm_id]],
                 strlen(jvm_find_file_name_pattern[vm_id])) == 0)
            {
                temp_buff =
                    (char*)work_info_ptr->virtual_file_info.virtual_file_name[jvm_find_file_virtual_file_id[vm_id]++];
                temp_buff_length = strlen(temp_buff);
                memcpy(file_name,temp_buff,temp_buff_length>name_length?name_length:temp_buff_length);

                return FS_NO_ERROR;
            }
            else
            {
                jvm_find_file_virtual_file_id[vm_id]++;
            }
        }
    }
    g_jvm_file_error_code = FS_MINIMUM_ERROR_CODE;     
    jvm_find_file_handle_2_index[vm_id] = -1;
    return g_jvm_file_error_code;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_isexist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_mvm_file_isexist(const kal_char * file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char * file_name;
    kal_int32 index;
    kal_int32 virtual_file_count;
    kal_wchar * file_path_w = jvm_file_name_buffer_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef JVM_FILE_DEBUG_SUPPORT    
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_isexist,file_path=%s",file_path);
 #endif
 
    if(file_path == NULL)
        return KAL_FALSE;
    
    file_name = jvm_mvm_file_get_file_name(file_path);
    if(file_name == NULL)
        return KAL_FALSE;

    kal_wsprintf(file_path_w,"%s",file_path);
    if (FS_GetAttributes(file_path_w) < 0)
    {
        virtual_file_count = work_info_ptr->virtual_file_info.virtual_file_count;

        /* if didn't find that, try virtual files */
        for (index = 0; index < virtual_file_count; index++)
        {
            if (strcmp(file_name, work_info_ptr->virtual_file_info.virtual_file_name[index]) == 0)
            {
                return KAL_TRUE;
            }
        }
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_char * jvm_mvm_file_get_file_name( const kal_char * file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_char * file_name;
    kal_int32  file_path_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(file_path == NULL)
        return NULL;

    file_path_length = strlen(file_path);

    if(file_path_length < 2)
        return NULL;
    
    while(file_path[file_path_length-1] != '\\')
    {
        file_path_length --;
    }
    return (kal_char *)(file_path+file_path_length);
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old_file_path       [IN]        
 *  new_file_path       [IN]               
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_rename(const char *old_file_path, const char *new_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //James modified start1
    //kal_int32 index;
    //kal_int32 file_count = work_info_ptr->virtual_file_info.virtual_file_count;
    //James modified end1
    kal_int32 err;
    kal_char * new_file_name;
    kal_wchar * old_file_path_w = jvm_file_name_buffer_w;
    kal_wchar new_file_path_w[MAX_WCHAR_FILENAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* a real file should not overwrite a pre-install file */
#ifdef JVM_FILE_DEBUG_SUPPORT     
    kal_prompt_trace(MOD_J2ME,"[JVM_FILE]jvm_mvm_file_rename,old_file_path=%s,new_file_path",old_file_path,new_file_path);
#endif    

    new_file_name = jvm_mvm_file_get_file_name(new_file_path);

    if(new_file_name == NULL)
    {
        g_jvm_file_error_code = -1;
        return -1;
    }

    /**  //removed for MAUI_02724396
    for (index = 0; index < file_count; index++)
    {
        if (strcmp(new_file_name, work_info_ptr->virtual_file_info.virtual_file_name[index]) == 0)
        {
            return -1;
        }
    }
    */

    kal_wsprintf(old_file_path_w,"%s",old_file_path);
    kal_wsprintf(new_file_path_w,"%s",new_file_path);
    if ((err = FS_Move(old_file_path_w, new_file_path_w, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0)) == FS_NO_ERROR)
    {
        return 0;
    }
    else
    {
        g_jvm_file_error_code = err;
        return -1;
    }
          
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_set_cache_enabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enabled             [IN]          
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_mvm_file_set_cache_enabled(kal_bool enabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //jvm_file_cache_enabled = /*enabled*/ KAL_FALSE;
}
//James modified start1
#ifdef __JVM_FILE_CACHE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_is_cached_enabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jvm_mvm_file_is_cached_enabled()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jvm_file_cache_enabled;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_get_cached_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
jvm_file_struct *jvm_mvm_file_get_cached_file(const kal_char *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jvm_file_cache_enabled || jvm_file_cache_data == NULL)
        return NULL;

    if (strcmp(file_name, jvm_file_cache_data->file_name) == 0)
    {
        return jvm_mvm_file_cached_open(file_name, jvm_file_cache_data->file_handle);
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_cached_data_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
jvm_file_cache_data_struct *jvm_mvm_file_cached_data_create()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_cache_data_struct *cache_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cache_data = (jvm_file_cache_data_struct*) jvm_malloc(sizeof(jvm_file_cache_data_struct));
    if (cache_data == NULL)
        return NULL;
    memset(cache_data, 0x00, sizeof(jvm_file_cache_data_struct));
    cache_data->data_size = 4096;
    cache_data->data = (kal_uint8*) jvm_malloc(cache_data->data_size);

    if(cache_data->data == NULL)
    {
        jvm_free(cache_data);
        cache_data = NULL;
    }
    return cache_data;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_cached_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  file_handle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jvm_mvm_file_cached_close_callback(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if(handle >= 0)
        FS_Close(handle);

    if (jvm_file_cache_data != NULL)
    {
        jvm_file_cache_data->ref_count--;

        if(jvm_file_cache_data->ref_count<=0)
        {
            if (jvm_file_cache_data->data != NULL)
            {
                jvm_free(jvm_file_cache_data->data);
            }
            memset(jvm_file_cache_data,0x00,sizeof(jvm_file_cache_data_struct));
            jvm_free(jvm_file_cache_data);
            jvm_file_cache_data = NULL;
        }
    }



    return RESOUCE_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  jvm_mvm_file_cached_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [IN]        
 *  file_handle     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
jvm_file_struct *jvm_mvm_file_cached_open(const kal_char *file_path, kal_int32 file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jvm_file_struct *jvm_file = NULL;
    kal_int32 file_path_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_time("[Performane][TIME] enter test\n", JVM_TRACE_TYPE_DEBUG);

    jvm_file = (jvm_file_struct*) jvm_malloc(sizeof(jvm_file_struct));
    if (jvm_file == NULL)
        goto out_of_memory;

    memset(jvm_file, 0x00, sizeof(jvm_file_struct));

    jvm_file->handle = file_handle;
    jvm_file->position = 0;
    jvm_file->type = JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR;

    if (jvm_file_cache_data == NULL)
    {
        jvm_file_cache_data = jvm_mvm_file_cached_data_create();

        if(jvm_file_cache_data == NULL)
            goto out_of_memory;
    }

    if (strcmp(file_path, jvm_file_cache_data->file_name) != 0)
    {
        file_path_length = strlen(file_path);
        memcpy(jvm_file_cache_data->file_name, file_path, file_path_length);
        jvm_file_cache_data->file_name[file_path_length] = 0;

        jvm_file_cache_data->start_index = -1;
        jvm_file_cache_data->end_index = -1;

        jvm_file_cache_data->encrypt_code = get_base_code(file_handle);
        jvm_file_cache_data->file_size = FS_Seek(file_handle, 0, FS_FILE_END);
        jvm_file_cache_data->file_handle = file_handle;
        FS_Seek(file_handle, 0, FS_FILE_BEGIN);

        jvm_resource_mgr_register((jam_mvm_get_current_vm_id() < 0 ? JVM_RESOURCE_MGR_INVALIDE_VM_ID : jam_mvm_get_current_vm_id()),JAVA_SYS_FILE_DEVICE, file_handle, NULL, NULL, &jvm_mvm_file_cached_close_callback);

    }

    jvm_file->encrypt_code = jvm_file_cache_data->encrypt_code;
    jvm_file->size = jvm_file_cache_data->file_size;
        
    jvm_file->data = (kal_uint8*) jvm_file_cache_data;
    jvm_file_cache_data->ref_count ++;
    jvm_trace_debug("[Performance][TIME],fileSize=%d\n", jvm_file->size);
    jvm_trace_time("[Performane][TIME] enter test,end\n", JVM_TRACE_TYPE_DEBUG);

    return jvm_file;

  out_of_memory:
    if(jvm_file != NULL)
    {
        jvm_free(jvm_file);
        jvm_file = NULL;
    }

    return NULL;

}
#endif /* __JVM_FILE_CACHE_SUPPORT__ */
//James modified end1
