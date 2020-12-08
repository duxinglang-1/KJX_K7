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
 *   pmg_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions for module initialization and termination.
 *   Some utility functions are also included.
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
#include "msf_cfg.h"
#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_pipe.h"
#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"
//#include "msf_chrt.h"

#include "msf_def.h"
//#include "msf_lib.h"
//#include "msf_wid.h"

#include "pmg_if.h"
#include "pmg_vrsn.h"
#include "pmg_main.h"
#include "pmg_phs.h"
#include "pmg_msg.h"
#include "pmg_inbox.h"
#include "pmg_um.h"
#include "pmg_dl.h"
#include "phs_cfg.h"
#include "Conversions.h"
#include "app_addr.h"

//suggested add
    #include "kal_general_types.h"
    #include "kal_release.h"
    #include "pmg_fs.h"
   // #include "wps_trc.h"
    #include "setjmp.h"
    #include "string.h"
    #include "pmg_struct.h"
    #include "msf_cmmn.h"
    #include "MMIDataType.h"
    #include "kal_public_api.h"

#define PMG_STATE_NOT_ACTIVE        0
#define PMG_STATE_STARTED           1
#define PMG_STATE_CLOSING_DOWN      2
#define PMG_STATE_TERMINATED        3

static void pmg_memory_exception_handler(void);

extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);

extern kal_uint16 applib_addr_bcd_byte_len(char *str, kal_uint16 n);

extern void applib_addr_string_2_bcd(char *src, kal_uint16 src_size, kal_uint8 *dst, kal_uint16 dst_size);

mtk_jmpbuf pmg_jmp_buf;
int pmg_inside_run;

typedef struct pmg_main_context_st
{
    int pmg_module_state;
    MSF_UINT16 pmg_init_state;
}pmg_main_context_t;

static pmg_main_context_t g_pmg_main_cntx = {0};

/*****************************************************************************
 * FUNCTION
 *  pmg_init
 * DESCRIPTION
 *  PMG initalisation function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_MEM_INIT(MSF_MODID_PMG, pmg_memory_exception_handler
#ifdef __OBIGO_FRMW2__   
		, FALSE
#endif
		);
#ifdef __OBIGO_FRMW2__
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_PMG, pmg_convert, pmg_destruct);
#endif /*__OBIGO_FRMW2__ */  
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_PMG);
    MSF_MODULE_IS_CREATED(MSF_MODID_PMG, PMG_VERSION);

    g_pmg_main_cntx.pmg_module_state = PMG_STATE_NOT_ACTIVE;
    g_pmg_main_cntx.pmg_init_state = 0;
    pmg_start_init(PMG_INIT_FS | PMG_INIT_MSG | PMG_INIT_PHS | PMG_INIT_INBOX | PMG_INIT_UM);

    pmg_fs_init();
    pmg_msg_init();
    pmg_phs_init();
    pmg_inbox_init();
    pmg_um_init();

    pmg_inbox_send_wps_pmg_ready_ind();

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_MAIN_84CCB710D8405616929571F1EAF438F4,
                       "PMG: Initialized\n"));
}


/*****************************************************************************
 * FUNCTION
 *  pmg_start_init
 * DESCRIPTION
 *  register PMG component initialisation
 * PARAMETERS
 *  component               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_start_init(MSF_UINT16 component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmg_main_cntx.pmg_init_state |= component;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_init_done
 * DESCRIPTION
 *  PMG component initialisation completes
 * PARAMETERS
 *  component               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_init_done(MSF_UINT16 component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmg_main_cntx.pmg_init_state &= ~component;
    if (g_pmg_main_cntx.pmg_module_state == PMG_STATE_NOT_ACTIVE && !g_pmg_main_cntx.pmg_init_state )
    {
        MSF_MODULE_IS_ACTIVE(MSF_MODID_PMG);
        g_pmg_main_cntx.pmg_module_state = PMG_STATE_STARTED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_terminate
 * DESCRIPTION
 *  PMG termination handler
 * PARAMETERS
 *  p            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_terminate(msf_module_terminate_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_um_terminate();
    pmg_inbox_terminate();
	g_pmg_main_cntx.pmg_module_state = PMG_STATE_CLOSING_DOWN;
  //  MSF_MODULE_IS_SHUTTING_DOWN(MSF_MODID_PMG);

    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_PMG);
    MSF_MEM_FREE_ALL(MSF_MODID_PMG);
    MSF_FILE_CLOSE_ALL(MSF_MODID_PMG);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_PMG);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_LOW, MSF_MODID_PMG, PMG_MAIN_7D20272EE594537891C9077F2A48F488,
                       "PMG: Terminated\n"));
    MSF_KILL_TASK(MSF_MODID_PMG);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_memory_exception_handler
 * DESCRIPTION
 *  PMG exception handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_memory_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_PMG, PMG_MAIN_587CEDC56F3AF151701D5E9F2950347E,
                      "PMG: pmg_memory_exception_handler(), inside_run:%d\n", pmg_inside_run));
    if (pmg_inside_run)
    {
        longjmp(pmg_jmp_buf, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_check_is_ascii_string
 * DESCRIPTION
 *  check whether the string is an ASCII string
 * PARAMETERS
 *  str             [in]
 * RETURNS
 *  0: not ASCII, 1: ASCII
 *****************************************************************************/
int pmg_check_is_ascii_string(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (str[i])
        if ((unsigned char)str[i++] > (unsigned char)0x7F)
            return 0;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_get_current_sys_utc_time
 * DESCRIPTION
 *  get current system time in UTC
 * PARAMETERS
 *  void
 * RETURNS
 *  system time in UTC
 *****************************************************************************/
MSF_UINT32 pmg_get_current_sys_utc_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 t;
    MSF_INT16 time_zone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = MSF_TIME_GET_CURRENT();
    time_zone = MSF_TIME_GET_TIME_ZONE();
    if (time_zone != HDI_TIME_ZONE_UNKNOWN)
        t -= (time_zone * 60);

    return t;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_utf8_strndup
 * DESCRIPTION
 *  truncate UTF8 string to "maxChars"
 * PARAMETERS
 *  str                     [in]
 *  maxChars                [in]
 * RETURNS
 *  truncated string
 *****************************************************************************/
char *pmg_utf8_strndup(const char *str, int maxChars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *strout;
    int ucs2bytes;
    char *ucs2str;
    int utf8bytes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2bytes = mmi_charset_utf8_to_ucs2_length_in_bytes((const kal_uint8*)str);
    ucs2str = pmg_mem_alloc((maxChars + 1) * 2);
    memset(ucs2str, 0, (maxChars + 1) * 2);
    mmi_chset_utf8_to_ucs2_string((kal_uint8*) ucs2str, (kal_int32) ((maxChars + 1) * 2), (kal_uint8*) str);

    utf8bytes = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)ucs2str);
    strout = pmg_mem_alloc(utf8bytes + 1);
    memset(strout, 0, utf8bytes + 1);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) strout, (kal_int32) (utf8bytes + 1), (kal_uint8*) ucs2str);

    PMG_MEM_FREE(ucs2str);

    return strout;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_convert_addr_to_string
 * DESCRIPTION
 *  convert address to text string
 * PARAMETERS
 *  destAddr                [out]
 *  addr                    [in]
 *  addrLen                 [in]
 *  addrType                [in]
 *  has_num_plan            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_convert_addr_to_string(char **destAddr, const char *addr, MSF_INT16 addrLen, MSF_UINT8 addrType, MSF_UINT8 has_num_plan)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT16 newAddrLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_MAIN_EF9060FCE9271C96617E1CA292A8BE9C,
                      "PMG: pmg_msg_convert_addr_to_string(destAddr:0x%X, addrLen:%d, addrType:%d)\n", destAddr,
                       addrLen, addrType));

    if ((*destAddr))
        PMG_MEM_FREE((*destAddr));

    *destAddr = 0;
    if (addr)
    {
        switch (addrType)
        {
            case PMG_ADDR_TEXT:
                if (addrLen <= PMG_MAX_ADDR_CHARS)
                    *destAddr = msf_cmmn_strdup(MSF_MODID_PMG, addr);
                else
                    *destAddr = msf_cmmn_strndup(MSF_MODID_PMG, addr, PMG_MAX_MSG_SIID_CHARS);
                break;

            case PMG_ADDR_IP:
                newAddrLen = applib_addr_ipv4_strlen((kal_uint8 *)addr, 4);
                *destAddr = pmg_mem_alloc(newAddrLen + 1);
                applib_addr_ipv4_2_string((kal_uint8*)addr, (kal_uint16)4, *destAddr, (kal_uint16)(newAddrLen + 1));
                break;

            case PMG_ADDR_PHONE:
                newAddrLen = applib_addr_number_strlen((kal_uint8 *)addr, (kal_uint16)(addrLen));
                *destAddr = pmg_mem_alloc(newAddrLen + 1);
                memset(*destAddr, 0, newAddrLen + 1);
                applib_addr_number_2_string((kal_uint8 *)addr, (kal_uint16)addrLen, *destAddr, (kal_uint16)(newAddrLen + 1));
                break;
        }
        MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, 
                      PMG_MAIN_65E13AD9046A9B54661822403A6F490A, "PMG: pmg_msg_convert_addr_to_string: %s, %d\n", destAddr, newAddrLen));
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_convert_string_to_addr
 * DESCRIPTION
 *  convert address text string to address binary bytes
 * PARAMETERS
 *  destAddr                [out]
 *  str                     [in]
 *  addrType                [in]
 * RETURNS
 *  number of valid bytes
 *****************************************************************************/
MSF_INT16 pmg_msg_convert_string_to_addr(char **destAddr, const char *str, MSF_UINT8 addrType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT16 newAddrLen, scStrLen, oaStrLen, oaLen, scLen;
    char *sc, *oa;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, 
                      PMG_MAIN_DFE1B2D7D04B66CD6167389A88F12F28, "PMG: pmg_msg_convert_string_to_addr(0x%X, %s, addrType:%d)\n", destAddr,
                      str, addrType));

    if ((*destAddr))
        PMG_MEM_FREE((*destAddr));

    *destAddr = 0;
    switch (addrType)
    {
        case PMG_ADDR_TEXT:
            *destAddr = msf_cmmn_strdup(MSF_MODID_PMG, str);
            return (MSF_INT16) strlen(*destAddr);

        case PMG_ADDR_IP:
            *destAddr = pmg_mem_alloc(4);
            applib_addr_string_2_ipv4((char *)str, (kal_uint8 *)*destAddr, 4);
            return 4;

        case PMG_ADDR_PHONE:
#ifndef __MMI_BRW_EXT_PUSH_VALIDATE__
            /* input addr string format: {SC} */
            /* PHS expected addr format: {OA, 0xFF, SC, 0xFF} */
            scStrLen = strlen(str);
            newAddrLen = applib_addr_bcd_byte_len((char *)str, scStrLen);
            sc = pmg_mem_alloc(newAddrLen + 2); /* for the additional 2 0xFF */
            *sc = (char)0xFF;
            applib_addr_string_2_bcd((char *)str, scStrLen, (kal_uint8 *)(sc + 1), newAddrLen);
            *(sc + newAddrLen + 1) = (char)0xFF;
            *destAddr = sc;
            return (newAddrLen + 2);
#else
            /* input addr string format: {OA, WAP_PMG_ADDR_PHONE_SEP, SC, WAP_PMG_ADDR_PHONE_SEP} */
            /* PHS expected addr format: {OA, 0xFF, SC, 0xFF} */
            oa = (char *)str;
            sc = strchr(str, WAP_PMG_ADDR_PHONE_SEP) + 1;
            oaStrLen = sc - oa - 1;  /* oa len */
            scStrLen = strchr(sc, WAP_PMG_ADDR_PHONE_SEP) - sc;  /* sc len */
            oaLen = applib_addr_bcd_byte_len((char *)oa, oaStrLen);
            scLen = applib_addr_bcd_byte_len((char *)sc, scStrLen);
            newAddrLen = oaLen + scLen + 2;   /* for the additional 2 0xFF */
            *destAddr = pmg_mem_alloc(newAddrLen);
            applib_addr_string_2_bcd((char *)oa, oaStrLen, (kal_uint8 *)*destAddr, oaLen);
            *(*destAddr + oaLen) = (char)0xFF;
            applib_addr_string_2_bcd((char *)sc, scStrLen, (kal_uint8 *)(*destAddr + oaLen + 1), scLen);
            *(*destAddr + newAddrLen - 1) = (char)0xFF;
            return newAddrLen;
#endif

        default:
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_MAIN_496745330BCA5A4700704C274324EEB9,
                               "PMG: pmg_msg_convert_string_to_addr() incorret type\n"));
            *destAddr = msf_cmmn_strdup(MSF_MODID_PMG, str);
            return (MSF_INT16) strlen(*destAddr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_handle_pipe_notify
 * DESCRIPTION
 *  this function will receive msf system pipe notify and receive data.
 *  and write those data into file.
 * CALLS
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int pmg_handle_pipe_notify(int handle, int event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_job_t *job;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = pmg_find_job_by_pipe_handle(handle);

    if (!job)
    {
        return FALSE;
    }

    switch (event_type)
    {
        case MSF_PIPE_EVENT_READ:
        case MSF_PIPE_EVENT_CLOSED:
            ret = pmg_read_push_pipe_data(job);
            break;
        default:
            pmg_abort_download(job, PMG_ERR_CONNECTION_ABORT);
            pmg_delete_job(job);
            return TRUE;
    }
    return ret;
}

void * pmg_mem_alloc (MSF_UINT32 size)
{
	void * memory = NULL;
	memory = PMG_MEM_ALLOC(size);
	if (memory == NULL)
	{
		ASSERT(0);
	}
	return memory;
}



