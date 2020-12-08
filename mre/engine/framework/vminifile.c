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
 * vminifile.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * inifile
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_LIB_LOG__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vmsys.h"
#include "vmio.h"
#include "vmchset.h"
#include "vminifile.h"
#include "vmlog.h"

extern int isspace(int c);

#ifdef __cplusplus
extern "C"
{
#endif

extern VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/*****************************************************************************
 * FUNCTION
 *  vm_load_ini_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file            [?]     
 *  buf             [?]     
 *  file_size       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static int vm_load_ini_file(char *file, char *buf,int *file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMWCHAR wfilename[100];
    unsigned int size = 0;
    VMFILE inifile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /* vm_gb2312_to_ucs2((VMWSTR)wfilename, 100, file); */
    vm_default_to_ucs2((VMWSTR)wfilename, 100, file);

    if ((inifile = vm_file_open((VMWSTR)wfilename, MODE_READ, FALSE)) < 0) 
        return 0;

    if(vm_file_read(inifile,buf,MAX_FILE_SIZE-1,&size)>=0)
    {
        if(size == MAX_FILE_SIZE -1)
            buf[MAX_FILE_SIZE-1] = '\0';

        *file_size = size;
        vm_file_close(inifile);
        return 1;
    }
    else
    {
        vm_file_close(inifile);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  new_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int new_line(char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ('\n' == c ||  '\r' == c )? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  end_of_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int end_of_string(char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return '\0'==c? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  is_left_barce
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int is_left_barce(char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return INI_SECTION_LEFT_BRACE == c? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  is_right_brace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int is_right_brace(char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return INI_SECTION_RIGHT_BRACE == c? 1 : 0;
}

/*分析指定的section、key及value在buf中的起止位置*/


/*****************************************************************************
 * FUNCTION
 *  parse_ini_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  section     [?]     
 *  key         [?]     
 *  buf         [?]     
 *  sec_s       [?]     
 *  sec_e       [?]     
 *  key_s       [?]     
 *  key_e       [?]     
 *  value_s     [?]     
 *  value_e     [?]     
 * RETURNS
 *  
 *****************************************************************************/
    static int parse_ini_file(
                char *section,
                char *key,
                char *buf,
                int *sec_s,
                int *sec_e,
                int *key_s,
                int *key_e,
                int *value_s,
                int *value_e)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p = buf;
    int i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if (buf == NULL)
            return 0;
        if (section == NULL || strlen(section) == 0)
            return 0;
        if (key == NULL || strlen(key) == 0)
            return 0;

    *sec_e = *sec_s = *key_e = *key_s = *value_s = *value_e = -1;

    while( !end_of_string(p[i]) ) {
        //find the section
        if( ( 0==i ||  new_line(p[i-1]) ) && is_left_barce(p[i]) )
        {
            int section_start=i+1;

            //find the ']'
            do {
                i++;
            } while( !is_right_brace(p[i]) && !end_of_string(p[i]));

            if( 0 == strncmp(p+section_start,section, i-section_start)) {
                int newline_start=0;

                i++;

                //Skip over space char after ']'
                while(isspace(p[i])) {
                    i++;
                }

                //find the section
                *sec_s = section_start;
                *sec_e = i;

                while( ! (new_line(p[i-1]) && is_left_barce(p[i])) 
                && !end_of_string(p[i]) ) {
                    int j=0;
                    //get a new line
                    newline_start = i;

                    while( !new_line(p[i]) &&  !end_of_string(p[i]) ) {
                        i++;
                    }
                    
                    //now i  is equal to end of the line
                    j = newline_start;

                    if(';' != p[j]) //skip over comment
                    {
                        while(j < i && p[j]!='=') {
                            j++;
                            if('=' == p[j]) {
                                if(strncmp(key,p+newline_start,j-newline_start)==0)
                                {
                                    //find the key ok
                                    *key_s = newline_start;
                                    *key_e = j-1;

                                    *value_s = j+1;
                                    *value_e = i;

                                    return 1;
                                }
                            }
                        }
                    }

                    i++;
                }
            }
        }
        else
        {
            i++;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_read_profile_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  section             [?]         
 *  key                 [?]         
 *  value               [?]         
 *  size                [IN]        
 *  default_value       [?]         
 *  file                [?]         
 * RETURNS
 *  
 *****************************************************************************/
    int vm_read_profile_string(char *section, char *key, char *value, int size, char *default_value, char *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[MAX_FILE_SIZE]={0};
    int file_size = 0;
    int sec_s,sec_e,key_s,key_e, value_s, value_e;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check parameters */
    if(section == NULL || strlen(section) == 0) 
        return 0;

    if(key == NULL || strlen(key) == 0) 
        return 0;

    if(value == NULL) 
        return 0;

    if(size <= 0) 
        return 0;

    if(file ==NULL || strlen(key) ==0) 
        return 0;
    
    /* load ini file. */
    if(!vm_load_ini_file(file, buf, &file_size))
    {
        if(default_value!=NULL)
            sprintf(value,"%s",default_value);
        return 0;
    }

    if(!parse_ini_file(section, key, buf, &sec_s, &sec_e, 
        &key_s, &key_e, &value_s, &value_e))
    {
        if(default_value != NULL)
            sprintf(value, "%s", default_value);

        return 0;
    }
    else
    {
        int cpcount = value_e - value_s;

        if( size - 1 < cpcount)
            cpcount =  size-1;
    
        memset(value, 0, size);
        memcpy(value, buf + value_s, cpcount);
        value[cpcount] = '\0';

        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_read_profile_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  section             [?]         
 *  key                 [?]         
 *  default_value       [IN]        
 *  file                [?]         
 * RETURNS
 *  
 *****************************************************************************/
    int vm_read_profile_int(char *section, char *key, int default_value, char *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char value[32] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!vm_read_profile_string(section, key, value, sizeof(value), NULL, file))
        return default_value;
    else
        return atoi(value);
}

/*****************************************************************************
 * FUNCTION
 *  vm_write_profile_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  section     [?]     
 *  key         [?]     
 *  value       [?]     
 *  file        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int vm_write_profile_string(char *section, char *key,
                    char *value, char *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMWCHAR wfilename[100];
    char buf[MAX_FILE_SIZE]={0};
    char w_buf[MAX_FILE_SIZE]={0};
    int sec_s,sec_e,key_s,key_e, value_s, value_e;
    int value_len;
    int file_size = 0;
    int new_size = 0;
    unsigned int writesize;
    VMFILE outfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //check parameters
    if(section == NULL || strlen(section)==0) return 0;
    if(key == NULL || strlen(key)==0) return 0;
    if(value == NULL) return 0;
    if(file ==NULL ||strlen(key)==0) return 0;

    value_len = strlen(value);

    //vm_gb2312_to_ucs2((VMWSTR)wfilename, 100, file);
    vm_default_to_ucs2((VMWSTR)wfilename, 100, file);

    if(!vm_load_ini_file(file,buf,&file_size))
    {
        sec_s = -1;
    }
    else
    {
        parse_ini_file(section,key,buf,&sec_s,&sec_e,&key_s,&key_e,&value_s,&value_e);
    }

    if( -1 == sec_s)
    {
        if(0==file_size)
        {
            sprintf(w_buf+file_size,"[%s]\n%s=%s\n",section,key,value);
            new_size = strlen(section)+5+strlen(key)+value_len;
        }
        else
        {
            //not find the section, then add the new section at end of the file
            memcpy(w_buf,buf,file_size);
            sprintf(w_buf+file_size,"\n[%s]\n%s=%s\n",section,key,value);
            new_size = file_size + 6 + strlen(section)+strlen(key)+value_len;
        }
    }
    else if(-1 == key_s)
    {
        //not find the key, then add the new key=value at end of the section
        memcpy(w_buf,buf,sec_e);
        sprintf(w_buf+sec_e,"%s=%s\n",key,value);
        sprintf(w_buf+sec_e+strlen(key)+strlen(value)+2,buf+sec_e, file_size - sec_e);
        new_size = file_size + 2 + strlen(key)+value_len;
    }
    else
    {
        //update value with new value
        memcpy(w_buf,buf,value_s);
        memcpy(w_buf+value_s,value, value_len);
        memcpy(w_buf+value_s+value_len, buf+value_e, file_size - value_e);
        new_size = file_size - (value_e-value_s) + value_len;
    }
    
    if ((outfile = vm_file_open((VMWSTR)wfilename, MODE_CREATE_ALWAYS_WRITE, FALSE)) < 0) {
        return 0;
    }

    if(vm_file_write(outfile, w_buf, new_size, &writesize)<0){
        vm_file_close(outfile);
        return 0;
    }

    vm_file_commit(outfile);
    vm_file_close(outfile);
    return 1;
}


#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif /* __MRE_LIB_INI__ */ 

