/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_main.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for module initialization, termination and utility usage
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
 *==============================================================================
 *******************************************************************************/
#ifndef _pmg_main_h
#define _pmg_main_h

//#include <clib.h>

#ifndef _msf_def_h
#include "msf_def.h"
#endif 

#ifndef _msf_lib_h
#include "msf_lib.h"
#endif 

#ifndef _msf_wid_h
#include "msf_wid.h"
#endif 
#include "mmi_features.h"

//#include "msf_log.h"
//suggested add
   #include "msf_def.h"
    #include "msf_mem.h"
    #include "msf_cfg.h"
    #include "kal_release.h"
    #include "msf_core.h"

#define PMG_MEM_ALLOC(x)      MSF_MEM_ALLOC (MSF_MODID_PMG, (x))
#define PMG_MEM_ALLOCTYPE(x)  MSF_MEM_ALLOCTYPE (MSF_MODID_PMG, x)
#define PMG_MEM_FREE(x)       MSF_MEM_FREE (MSF_MODID_PMG, (x))

#define PMG_INIT_MSG    0x0001
#define PMG_INIT_FS     0x0002
#define PMG_INIT_PHS    0x0004
#define PMG_INIT_INBOX  0x0008
#define PMG_INIT_UM     0x0010

/* new code start */
#define PMG_DEFAULT_FILENAME     "filename"
#define PMG_DL_BUFFER_SIZE		  2048
#ifdef __MMI_UM_CONVERSATION_BOX__ 
#define WPS_PMG_CONVERSATION_BOX
#endif /* __MMI_UM_CONVERSATION_BOX__  */


#ifdef WPS_PMG_CONVERSATION_BOX
void set_msg_id_with_num(MSF_UINT8 entry, MSF_UINT8 index);
#endif /* WPS_PMG_CONVERSATION_BOX */

/*
typedef struct pmg_job_t
{
    struct pmg_job_t *next;
    MSF_UINT8 mod_id;
    MSF_INT32 id;
    MSF_INT32 cause;
    MSF_UINT8 status;
    char *mime_type;
    char *url;
    char *header;
    char *pipe_name;
    char *file_name;
    MSF_UINT32 download_size;
    MSF_UINT32 total_size;
    int pipe_handle;
    int file_handle;
    int indication_sent;
    char buffer[PMG_DL_BUFFER_SIZE];
    MSF_UINT32 buffer_tail;
    MSF_UINT32 seq_num;
    MSF_INT32 network_account_id;
    MSF_INT32 attr_len;
    unsigned char *attr_string;
} pmg_job_t; */

typedef struct pmg_job_t
{
    struct pmg_job_t *next;
    MSF_UINT8 mod_id;
	MSF_UINT8 status;
    MSF_INT32 id;
    MSF_INT32 cause;
    char *mime_type;
    char *url;
    char *header;
    char *pipe_name;
    char *file_name;
    MSF_UINT32 download_size;
    MSF_UINT32 total_size;
    int pipe_handle;
    int file_handle;
    int indication_sent;
    char buffer[PMG_DL_BUFFER_SIZE];
    MSF_UINT32 buffer_tail;
    MSF_UINT32 seq_num;
    MSF_INT32 network_account_id;
    MSF_INT32 attr_len;
    unsigned char *attr_string;
} pmg_job_t;


static int job_count;
/* new code ends*/

extern int pmg_inside_run;
extern mtk_jmpbuf pmg_jmp_buf;

void pmg_init(void);

void pmg_start_init(MSF_UINT16 component);

void pmg_init_done(MSF_UINT16 component);

void pmg_terminate(msf_module_terminate_t *p);

int pmg_check_is_ascii_string(const char *str);

int pmg_handle_pipe_notify(int handle, int event_type);

MSF_UINT32 pmg_get_current_sys_utc_time(void);

MSF_UINT32 pmg_check_num_digits(const MSF_UINT8 b);

char *pmg_utf8_strndup(const char *str, int maxChars);

void pmg_msg_convert_addr_to_string(char **destAddr, const char *addr, MSF_INT16 addrLen, MSF_UINT8 addrType, MSF_UINT8 has_num_plan);

MSF_INT16 pmg_msg_convert_string_to_addr(char **destAddr, const char *str, MSF_UINT8 addrType);

void * pmg_mem_alloc (MSF_UINT32 size);

#endif /* _pmg_main_h */ 

