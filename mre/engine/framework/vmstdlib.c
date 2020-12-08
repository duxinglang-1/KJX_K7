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
*  vmstdlib.c
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
*  
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
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_LIB_C__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vmstdlib.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmdl.h"
#include "vmsys.h"
#include "vmopt.h"
#include "Unicodexdcl.h"

int vm_is_leap_year(int year);
int vm_days_of_month(int year, int month);
extern int isdigit(int);
extern int isspace(int c);
/*****************************************************************************
 * FUNCTION
 *  htoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int htoi(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= '0') && (ch <= '9'))
        return ch - '0';

    if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;

    if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  dtoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int dtoi(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= '0') && (ch <= '9'))
        return ch - '0';

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  strtoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [?]     
 * RETURNS
 *  
 *****************************************************************************/
int strtoi(char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int v, t, i, hex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; s[i] != 0; i++)
        if (((s[i] >= 'a') && (s[i] <= 'f')) || ((s[i] >= 'A') && (s[i] <= 'F'))) {
            hex = 1;
            break;
        }

        for (i = 0, v = 0; s[i] != 0; i++) {
            if (hex) {
                if ((t = htoi(s[i])) == -1)
                    return -1;
                v = (v << 4) + t;
            }
            else {
                if ((t = dtoi(s[i])) == -1)
                    return -1;
                v = v * 10 + t;
            }
        }

        return v;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]        
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_get_filename(VMWSTR path, VMWSTR filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path == NULL) || (vm_wstrlen(path) == 0)) {
        filename[0] = 0;
        return ;
    }

    p = -1;
    for (i = 0; path[i] != 0; i++)
        if (path[i] == '\\')
            p = i;

    if (p > 0) {
        for (i = p + 1; path[i] != 0; i++)
            filename[i - p - 1] = path[i];
        filename[i - p - 1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullpath        [IN]        
 *  path            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_path(VMWSTR fullpath, VMWSTR path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((fullpath == NULL) || (vm_wstrlen(fullpath) == 0)) {
        return -1;
    }

    for (p = -1, i = 0; fullpath[i] != 0; i++)
        if (fullpath[i] == '\\')
            p = i;

    if (p == -1)
        return -1;

    wstrncpy(path, fullpath, p + 1);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrlen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstrlen(VMWSTR s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (s == NULL)
        return 0;

    for (i = 0; s[i] != 0; i++);

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [IN]        
 *  src     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstrcpy(VMWSTR dst, const VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((dst == 0) || (src == 0))
        return 0;

    for (i = 0; src[i] != 0; i++)
        dst[i] = src[i];
    dst[i] = 0;
    //dst[i + 1] = 0;

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrcat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [IN]        
 *  src     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstrcat(VMWSTR dst, const VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMWSTR p = dst;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (*p++ != 0);

    --p;
    for (i = 0; src[i] != 0; i++)
        p[i] = src[i];
    p[i] = 0;
    //p[i + 1] = 0;

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrncpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  src         [IN]        
 *  length      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstrncpy(VMWSTR dst, const VMWSTR src, VMINT length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((src[0] == 0) || (length <= 0)) {
        dst[0] = 0;
        return 0;
    }

    for (i = 0; (i < length) && (src[i] != 0); i++) {
        dst[i] = src[i];
    }
    dst[i] = 0;
    //dst[i + 1] = 0;

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  vm_memcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [?]         
 *  src         [?]         
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_memcpy(void *dst, void *src, VMINT count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //VMUINT8 *d, *s;
    VMINT i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < count; i++)
        ((VMUINT8*)dst)[i] = ((VMUINT8*)src)[i];
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrcmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [IN]        
 *  src     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstrcmp(VMWSTR dst, VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, dst_len, src_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dst == NULL && src == NULL)
        return 0;
    if (dst == NULL)
        return -1;
    if (src == NULL)
        return 1;

    dst_len = vm_wstrlen(dst);
    src_len = vm_wstrlen(src);
    if (dst_len < src_len)
        return -1;
    if (dst_len > src_len)
        return 1;

    for (i = 0; ((dst[i] != 0) || (src[i] != 0)); i++) {
        if (dst[i] < src[i])
            return -1;
        else if (dst[i] > src[i])
            return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstrcmp_ignore_case
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_1       [IN]        
 *  str_2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 
extern S32 mmi_wcsicmp(const U16 *str_src, const U16 *str_dst);
VMINT vm_wstrcmp_ignore_case(VMWSTR str_1, VMWSTR str_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 1
    return (VMINT)mmi_wcsicmp((const U16*)str_1, (const U16*)str_2);
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
 *  get_today_from_2000
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT get_today_from_2000(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, nday = -1;
    vm_time_t time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (vm_get_time(&time) != 0){
        return nday;
    }

    if (time.year >= 2000) {
        nday = 0;
        for (i = 2000; i < time.year; i++) 
            nday += vm_is_leap_year(i) ? 366 : 365;

        for (i = 1; i < time.mon; i++)
            nday += vm_days_of_month(time.year, i);

        nday += time.day;
    }

    return nday;
}


/*****************************************************************************
 * FUNCTION
 *  vm_is_leap_year
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int vm_is_leap_year(int year)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((year % 4 == 0) && (year % 100 != 0))
        return 1;
    else if ((year % 100 == 0) && (year % 400 == 0))
        return 1;
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_days_of_month
 * DESCRIPTION
 *  
 * PARAMETERS
 *  year        [IN]        
 *  month       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int vm_days_of_month(int year, int month)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int days_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (month >= 1 && month <= 12) {
        days = days_month[month - 1];
        if (month == 2)
            if (vm_is_leap_year(year))
                days = 29;
    }

    return days;
}


/*****************************************************************************
 * FUNCTION
 *  vm_upper_case
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_upper_case(char *dst, char *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst == NULL || src == NULL)
        return ;

    while (src[i] != 0) {
        ch = src[i];
        if ((ch >= 'a') && (ch <= 'z'))
            ch &= 0xDF;
        dst[i] = ch;
        i++;
    }
    dst[i] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_lower_case
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_lower_case(char *dst, char *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dst == NULL || src == NULL)
        return ;

    while (src[i] != 0) {
        ch = src[i];
        if ((ch >= 'A') && (ch <= 'Z'))
            ch |= 0x20;
        dst[i] = ch;
        i++;
    }
    dst[i] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_string_equals_ignore_case
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1      [IN]        
 *  s2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern kal_int32 app_stricmp(kal_char *s, kal_char *t);
VMINT vm_string_equals_ignore_case(const char *s1, const char *s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, matchs = 0;

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    return app_stricmp((kal_char*)s1, (kal_char*)s2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vm_write_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cache       [?]         
 *  buf         [?]         
 *  buf_len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_write_cache(vm_cache_t *cache, void *buf, VMINT buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int nread = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cache->eof)
        return 0;

    if (cache->count > 0) {
        memmove(cache->buf, cache->buf + cache->count, cache->avail - cache->count);
        cache->avail -= cache->count;
        cache->count = 0;
    }

    if (buf_len <= 0) {
        cache->eof = TRUE;
        return 0;
    }

    if (cache->avail < VM_CACHE_SIZE) {
        len = buf_len;
        if ((VM_CACHE_SIZE - cache->avail) < len)
            len = VM_CACHE_SIZE - cache->avail;

        memcpy(cache->buf + cache->avail, buf, len);
        cache->avail += len;
        nread = len;
    }

    return nread;
}


/*****************************************************************************
 * FUNCTION
 *  vm_read_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cache           [?]         
 *  buf             [?]         
 *  buf_size        [IN]        
 *  len             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_read_cache(vm_cache_t *cache, void *buf, VMINT buf_size, VMINT len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int l = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cache->eof)
        return 0;

    if ((cache->avail - cache->count) > 0) {
        l = len;
        if (l > buf_size)
            l = buf_size;
        if ((cache->avail - cache->count) < l)
            l = cache->avail - cache->count;

        memcpy(buf, cache->buf + cache->count, l);
        cache->count += l;
    }

    return l;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cache_read_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cache       [?]     
 *  ch          [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_cache_read_char(vm_cache_t *cache, char *ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_read_cache(cache, ch, 1, 1) == 1 ? 0 : -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_cache_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cache       [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_cache_free_space(vm_cache_t *cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cache->eof)
        return 0;
    else
        return VM_CACHE_SIZE - cache->avail;
}


/*****************************************************************************
 * FUNCTION
 *  vm_read_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  line        [?]         
 *  size        [IN]        
 *  cache       [?]         
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_read_line(char *line, VMINT size, vm_cache_t *cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count, found = 0;
    VMUINT8* buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cache->eof && (cache->count == cache->avail))
        return -1;

    memset(line, 0, size);
    count = cache->count;
    buf = cache->buf;
    while ((count < cache->avail) && ((count - cache->count) < (size - 1))) {
        if (buf[count] == '\r') {
            count++;
            continue;
        }
        else if (buf[count] == '\n') {
            count++;
            found = 1;
            break;
        }
        else {
            if ((count - cache->count) < (size - 1)) {
                line[count - cache->count] = buf[count];
            }
        }
        count++;
    }

    if (found) {
        cache->count = count;
    }
    else {
        if (cache->eof && (count == cache->avail) && 
            ((count - cache->count) < (size - 1))) {
                cache->count = count;
                found = TRUE;
        }
    }

    return found ? 0 : -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_create_dyn_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_size       [IN]        
 *  inc_size        [IN]        
 *  block_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
vm_dyn_array_t *vm_create_dyn_array(VMINT init_size, VMINT inc_size, VMINT block_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_dyn_array_t *array = vm_malloc(sizeof(vm_dyn_array_t));

    if (array != NULL) {
        array->init_size = init_size;
        array->inc_size = inc_size;
        array->block_size = block_size;
        array->count = 0;
        array->capacity = init_size;

        if ((array->ptr = vm_malloc(block_size * init_size)) == NULL) {
            vm_free(array);
            array = NULL;
        }
    }

    return array;
}


/*****************************************************************************
 * FUNCTION
 *  vm_dyn_array_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  array       [?]     
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_dyn_array_add(vm_dyn_array_t *array, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * ptr = array->ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (array->count < array->capacity) {
        memcpy((VMUINT8*)ptr + (array->block_size * array->count),
            data, array->block_size);
        array->count++;
    }
    else {
        if ((ptr = vm_realloc(ptr, array->block_size * (
            array->capacity + array->inc_size))) == NULL)
            return -1;
        array->capacity += array->inc_size;

        memcpy((VMUINT8*)ptr + (array->block_size * array->count),
            data, array->block_size);
        array->count++;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_dyn_array_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  array       [?]         
 *  idx         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_dyn_array_del(vm_dyn_array_t *array, VMINT idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void * ptr = array->ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx >= array->count || idx < 0)
        return -1;

    if (idx == array->count - 1)
        array->count--;
    else {
        memcpy((VMUINT8*)ptr + idx * array->block_size,
            (VMUINT8*)ptr + (idx + 1) * array->block_size,
            (array->count - idx) * array->block_size);
        array->count--;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_dyn_array_del_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  array       [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_dyn_array_del_all(vm_dyn_array_t *array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    array->count = 0;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_free_dyn_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  array       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_free_dyn_array(vm_dyn_array_t *array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (array != NULL) {
        if (array->ptr != NULL)
            vm_free(array->ptr);
        vm_free(array);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_ends_with
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1      [IN]        
 *  s2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ends_with(const char *s1, const char *s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, s1l, s2l;
    char *p1, *p2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (s1 == NULL || s2 == NULL)
        return -1;

    s1l = strlen(s1);
    s2l = strlen(s2);

    if (s1l < s2l || s1l == 0 || s2l == 0)
        return -1;

    for (p1 = (char*)((VMINT)s1 + (s1l - 1)), p2 = (char*)((VMINT)s2 + (s2l - 1)), i = 0; i < s2l; i++, p1--, p2--)
        if (*p1 != *p2)
            return -1;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wends_with
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s1      [IN]        
 *  s2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wends_with(const VMWSTR s1, const VMWSTR s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, s1l, s2l;
    VMWCHAR *p1, *p2;
    VMINT a1, a2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (s1 == NULL || s2 == NULL)
        return -1;

    s1l = vm_wstrlen(s1);
    s2l = vm_wstrlen(s2);

    if (s1l < s2l || s1l == 0 || s2l == 0)
        return -1;

    a1 = (VMINT)s1;
    a2 = (VMINT)s2;
    for (p1 = (VMWSTR)a1 + (s1l - 1), p2 = (VMWSTR)a2 + (s2l - 1), i = 0; i < s2l; i++, p1--, p2--)
        if (*p1 != *p2)
            return -1;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_tmp_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prefix          [?]     
 *  filename        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_tmp_filename(char *prefix, char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_time_t time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vm_get_time(&time);
    srand((unsigned int)time.sec);

    sprintf(filename, "%s%d%d%d.tmp", (prefix == NULL ? "" : prefix), 
        time.min, time.sec, rand());
}


/*****************************************************************************
 * FUNCTION
 *  vm_safe_wstrcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_safe_wstrcpy(VMWSTR dest, VMINT size, VMWSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dest == NULL || src == NULL)
        return 0;

    len = vm_wstrlen(src);
    if (len >= size)
        len = size - 1;
    memcpy(dest, src, len * 2);
    dest[len] = 0;

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  vm_wstarts_with
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        
 *  b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_wstarts_with(VMWSTR a, VMWSTR b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT yes = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (*b != 0) {
        if (*a == 0) {
            yes = FALSE;
            break;
        }
        if ((yes &= (*a == *b)) == FALSE)
            break;
        a++;
        b++;
    }

    return yes ? 0 : -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_url_encode_gb2312
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMUINT vm_url_encode_gb2312(VMSTR dst, VMUINT size, const VMSTR src) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT i = 0, j = 0;
    VMCHAR tmp[4] = {0, 0, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (size != 0 && src != NULL && dst != NULL)
    {
        for (i = 0, j = 0; i < size && src[j] != 0; j++)
        {
            if ((src[j] >= 'a' && src[j] <= 'z') || (src[j] >= 'A' && src[j]<= 'Z'))
            {
                dst[i++] = src[j];
            }
            else if (src[j] >= '0' && src[j] <= '9')
            {
                dst[i++] = src[j];
            }
            else if (src[j] == '-' || src[j] == '_'  || src[j] == '.' || src[j] == '*')
            {
                dst[i++] = src[j];
            }
            else if (src[j] == 0x20)
            {
                dst[i++] = '+';
            }
            else
            {
                if (i + 3 <= size)
                {
                    dst[i++] = '%';

                    sprintf(tmp, "%x%x", (char)((src[j] & 0xF0) >> 4), (char)(src[j] & 0x0F));
                    dst[i++] = tmp[0];
                    dst[i++] = tmp[1];
                    continue;
                }

                break;
            }
        }

        if (i <= size - 1)
            dst[i] = 0;
    }

    return i;
}

#define HEXTOOCT(x)			(x >= 'a' && x <= 'f') ? ((x - 'a') + 10) : ((x >= 'A' && x <= 'F') ? ((x - 'A') + 10) : x)


/*****************************************************************************
 * FUNCTION
 *  vm_url_decode_gb2312
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [IN]        
 *  size        [IN]        
 *  src         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMUINT vm_url_decode_gb2312(VMSTR dst, VMUINT size, const VMSTR src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dst != NULL && size != 0 && src != NULL)
    {
        const VMUINT srcLen = strlen(src);

        for (i =0, j = 0; i < size && j < srcLen;)
        {
            if (src[j] == '%')
            {
                if (j + 2 <= srcLen)
                {
                    dst[i++] = ((HEXTOOCT(src[j + 1]) & 0x0F) << 4) | (HEXTOOCT(src[j + 2]) & 0x0F);

                    j += 3;
                    continue;
                }

                break;
            }
            else if (src[j] == '+')
            {
                dst[i++] = 0x20;
                j++;
            }
            else
            {
                dst[i++] = src[j++];
            }
        }

        if (i <= size - 1)
            dst[i] = 0;

    }

    return i;
}


__int64 vm_atoi64(const char *nptr)
{
    int c;              /* current char */
    __int64 total;      /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
    while (isspace((int)(unsigned char)*nptr))
    {
        ++nptr;
    }

    c = (int)(unsigned char)*nptr++;
    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
    {
        c = (int)(unsigned char)*nptr++;    /* skip sign */
    }

    total = 0;

    while (isdigit(c))
    {
        total = 10 * total + (c - '0');     /* accumulate digit */
        c = (int)(unsigned char)*nptr++;    /* get next char */
    }

    if (sign == '-')
    {
        return -total;
    }
    else
    {
        return total;   /* return result, negated if necessary */
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_get_execrom_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wfilename       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 * vm_get_execrom_ptr(VMWSTR wfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 * rom_ptr = NULL;
    VMCHAR * fn1 = NULL;

    VMCHAR s[16];

    VMCHAR * ch_ptr = NULL;
    VMINT c = 0;

    VMINT len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (wfilename == NULL)
        return NULL;
    len = vm_wstrlen(wfilename);
    if (len == 0 || len > MAX_APP_NAME_LEN)
        return NULL;	

    if (vm_parse_exec_format(wfilename) == VM_EXEC_ROM)
    {
        fn1 = (VMCHAR *)vm_malloc(MAX_APP_NAME_LEN * sizeof(VMCHAR));
        if (fn1 == NULL)
        {
            return NULL;
        }
        //vm_ucs2_to_gb2312(fn1, MAX_APP_NAME_LEN, wfilename);
        vm_ucs2_to_ascii(fn1, MAX_APP_NAME_LEN, wfilename);

        c = 0;
        ch_ptr = strstr(fn1, ".rom");
        ch_ptr--;
        while ((*ch_ptr) != '\\')
        {
            ch_ptr--;
            c++;
        }
        if (c > 16)
        {
            vm_free(fn1);
            return NULL;
        }
        memset(s, 0x00, 16);
        memcpy(s, ++ch_ptr, c);
        vm_free(fn1);
//        rom_ptr = (VMUINT8 * )(atoi(s)+4);		
        rom_ptr = (VMUINT8 * )((VMINT)vm_atoi64(s)+4);      // for MAUI_02932436 
    }
    return rom_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_execrom_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rom_ptr     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_execrom_size(VMUINT8 * rom_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT size = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rom_ptr != NULL)
    {
        memcpy((VMUINT8 * )&size, (VMUINT8 *)rom_ptr, 4 * sizeof(VMUINT8));
    }
    else
    {
        size = 0;
    }
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  vm_parse_exec_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wfilename       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
typedef struct 
{
    vm_exec_format_enum type;
    VMWSTR              suffix;
}vm_exec_format_map;

vm_exec_format_enum vm_parse_exec_format(VMWSTR wfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT length = 0;
    VMINT i = 0;
    CHAR* name_suffix = NULL;
    static vm_exec_format_map format_map[]={{VM_EXEC_VXP,(VMWSTR)L".vxp"},
                                     {VM_EXEC_VXP,(VMWSTR)L".vpp"},
                                     {VM_EXEC_VXP,(VMWSTR)L".vsp"},
                                     {VM_EXEC_AXF,(VMWSTR)L".axf"},
                                     {VM_EXEC_ROM,(VMWSTR)L".rom"},
                                     {VM_EXEC_VSO,(VMWSTR)L".vso"},
                                     {VM_EXEC_DLL,(VMWSTR)L".dll"},
                                     //end
                                     {VM_EXEC_NO_FORMAT,(VMWSTR)NULL}};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wfilename)
        return VM_EXEC_NO_FORMAT;
        
    length = kal_wstrlen((const WCHAR *)wfilename);
    if (length <= 4)
        return VM_EXEC_NO_FORMAT;

    length -= 4;

    name_suffix = (CHAR*)(wfilename+length);
    
    while (format_map[i].suffix != NULL)
    {
        if (0 == mmi_ucs2icmp(name_suffix,(CHAR*)format_map[i].suffix))
        {
            return format_map[i].type;
        }
        i++;
    }
    
    return VM_EXEC_NO_FORMAT;
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_segment_from_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wfilename               [IN]        
 *  file_index              [IN]        
 *  wexec_filename          [IN]        
 *  wexec_filename_len      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_segment_from_filename(VMWSTR wfilename, VMINT file_index, VMWSTR wexec_filename, VMINT wexec_filename_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMWCHAR* ptr = NULL;
    VMINT i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!wexec_filename || (file_index != 0 && file_index != 1) 
        || !wfilename || wexec_filename_len <= 0)
        return FALSE;

    if (file_index == 0)
    {
        for (i = 0, ptr = wfilename; *ptr != 0 && *ptr != L'?'; i++, ptr++)
        {
            if (i >= wexec_filename_len)
                return FALSE;

            *(wexec_filename + i) = *ptr;
        }

        if (i < wexec_filename_len)
            *(wexec_filename + i) = 0;

        return TRUE;
    }
    else
    {
        for (ptr = wfilename; *ptr != 0 && *ptr != L'?'; ptr++);

        if (*ptr == L'?')
        {
            ptr++;

            for (i = 0; *ptr != 0; i++)
            {
                if (i >= wexec_filename_len)
                    return FALSE;

                *(wexec_filename + i) = *ptr;
            }

            if (i < wexec_filename_len)
                *(wexec_filename + i) = 0;

            return TRUE;
        }
        else
            return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  vm_is_redirection_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  exec_filename       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_is_redirection_filename(VMWSTR exec_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (exec_filename)
    {
        VMINT i = 0;

        for (i = 0; i < (MAX_APP_NAME_LEN + 1) && exec_filename[i] != 0; i++)
        {
            if (exec_filename[i] == REDIRECT_APPNAME_SEPARATOR)
                return TRUE;
        }
    }

    return FALSE;
}

VMINT vm_vwsprintf(VMWSTR outstr, VMINT size, const VMWSTR fmt, va_list args)
{
    VMINT ret = 0;
    vswprintf((wchar_t *)outstr, size, (const wchar_t *)fmt, args);
    return ret;
}

VMINT vm_get_base_sym(VMCHAR* func_name )
{
	return 0;
}

#endif /* __MRE_LIB_C__ */
