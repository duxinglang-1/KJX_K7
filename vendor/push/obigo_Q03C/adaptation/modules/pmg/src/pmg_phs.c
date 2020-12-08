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
 *   pmg_phs.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions for PHS-related request handling 
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
#include "msf_dcvt.h"
#include "msf_log.h"
//#include "msf_pipe.h"
//#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"

#include "pmg_main.h"
#include "pmg_fs.h"
#include "pmg_msg.h"
#include "pmg_if.h"
#include "pmg_inbox.h"
//#include "pmg_um.h"
#include "pmg_phs.h"
#include "phs_cfg.h"
//#include "stdio.h"
#include "string.h"
//#include "fat_fs.h"

//suggested add
    #include "msf_def.h"
    #include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "pmg_struct.h"
    #include "kal_public_api.h"
    #include "msf_cmmn.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "kal_trace.h"
    #include "wps_trc.h"
    #include "MMI_features.h"
    #include "fs_errcode.h"

#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
extern MSF_UINT32 pmg_msg_count_all_messages(void);
extern int pmg_msg_delete_oldest_message(int *msgID, MSF_UINT8 *msgType);
#endif

typedef enum
{
    PMG_PHS_RECV_CONFIG =    0x01,

#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
    PMG_PHS_RECV_WHITELIST = 0x02,
#else
    PMG_PHS_RECV_WHITELIST = 0x00,
#endif

#ifdef PHS_CFG_PUSH_BLACKLIST_SUPPORT
    PMG_PHS_RECV_BLACKLIST = 0x04,
#else
	PMG_PHS_RECV_BLACKLIST = 0x00,
#endif

    PMG_PHS_RECV_ALL =      0x07
} pmg_phs_recv_enum;

typedef struct
{
    int msgID;
    MSF_UINT8 msgType;
    MSF_UINT8 inUse;
    char *attr;
} pmg_msg_deleted_msg_t;

typedef struct pmg_phs_context_st
{
    pmg_msg_deleted_msg_t pmg_msg_deleted_state;
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
    MSF_UINT32 max_trust_addr_no;
    MSF_UINT32 max_black_addr_no;
    int pmg_trust_addr_sizes[3]; /* indexed by PMG_ADDR_PHONE, PMG_ADDR_IP, PMG_ADDR_TEXT */
    int pmg_black_addr_sizes[3]; /* indexed by PMG_ADDR_PHONE, PMG_ADDR_IP, PMG_ADDR_TEXT */
#endif
    kal_uint8 recv_setting;      /* PMG_PHS_RECV_xxx */
} pmg_phs_context_t;


#define DEFAULT_NET_ACC_ID 0

static void pmg_phs_set_default_connection(MSF_UINT16 net_id, MSF_UINT32 type);


static void pmg_phs_set_config_data (MSF_UINT16 security_level,MSF_UINT16 support_SIR, MSF_UINT16 support_SL, 
									 MSF_UINT16 whitelist_behavior, MSF_UINT16 blacklist_enable, MSF_UINT16 whitelist_disable);

static void pmg_phs_file_write (char*, char*, char*, int, int, pmg_auth_list_type);

static void pmg_phs_file_operation (int size_remain, int file_handle, int bytes_written, char* data, int segment);

static void pmg_phs_send_data_list_ind (MSF_UINT8* file_name, MSF_UINT8 list_type);

extern kal_uint16 app_ucs2_str_to_asc_str(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
char *whitelist_ip;
char *whitelist_smsc;
char *blacklist_ip;
char *blacklist_smsc;
char *whitelist_domain;
#endif
/***************/

static pmg_phs_context_t g_pmg_phs_cntx = {0};




/*****************************************************************************
 * FUNCTION
 *  pmg_phs_init
 * DESCRIPTION
 *  initialise PMG's PHS interface component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  void *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&g_pmg_phs_cntx.pmg_msg_deleted_state, 0, sizeof(pmg_msg_deleted_msg_t));
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
    g_pmg_phs_cntx.max_trust_addr_no = 0;
    g_pmg_phs_cntx.max_black_addr_no = 0;


    whitelist_ip = NULL;
	whitelist_smsc = NULL;
	whitelist_domain = NULL;
	blacklist_ip = NULL;
	blacklist_smsc = NULL;
#endif
	g_pmg_phs_cntx.recv_setting = (PMG_PHS_RECV_CONFIG | PMG_PHS_RECV_WHITELIST | PMG_PHS_RECV_BLACKLIST);
    pmg_phs_set_default_connection (DEFAULT_NET_ACC_ID, PMG_PHS_SMS_UDP_CONNECTIONS);
    pmg_phs_config(WAP_PMG_RETR_ACCEPT_ALL, TRUE, WAP_PMG_WL_DISABLED, WAP_PMG_BL_DISABLED, 0, 0);
    pmg_init_done(PMG_INIT_PHS);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_init_recv
 * DESCRIPTION
 *  initialise PMG's PHS interface component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_init_recv(pmg_phs_recv_enum item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pmg_phs_cntx.recv_setting &= ~item;
    if (!g_pmg_phs_cntx.recv_setting)
    {
        pmg_init_done(PMG_INIT_PHS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_config
 * DESCRIPTION
 *  config PHS registry
 * PARAMETERS
 *  wapPushEnabled              [in]
 *  slEnabled                   [in]
 *  trustSetting                [in]
 *  blackListEnabled            [in]
 *  maxTrustAddrNo              [in]
 *  maxBlackAddrNo              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_config(
    wps_pmg_retrieval_enum wapPushEnabled, 
    MSF_UINT8 slEnabled, 
    wps_pmg_white_list_action_enum trustSetting,
    wps_pmg_black_list_action_enum blackListEnabled,
    MSF_UINT32 maxTrustAddrNo,
    MSF_UINT32 maxBlackAddrNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
	MSF_UINT16     security_level = 0;
	MSF_UINT16     support_SIR = 1;
	MSF_UINT16     support_SL = 1;
	MSF_UINT16     whitelist_disable = 1;
	MSF_UINT16     blacklist_enable = 0;
	MSF_UINT16     whitelist_behavior = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    switch (wapPushEnabled)
    {
    case WAP_PMG_RETR_DISABLED:
        /* disable all WAP-PUSH messages but still enable non-WAP push message, eg, prov, mms..etc */
        security_level = 2;
	    support_SIR = 0;
        break;
    case WAP_PMG_RETR_ACCEPT_AUTH_OR_TRUSTED:
        /* enable all WAP-PUSH messages */
		security_level = 1;
	    support_SIR = 1;
        break;
    case WAP_PMG_RETR_ACCEPT_ALL:
        /* enable all WAP-PUSH messages */
		security_level = 0;
	    support_SIR = 1;  
        break;
    default:
        ASSERT(0);
        break;
    }

    if (slEnabled)
    {
        /* enable SL messages */
		support_SL = 1;	
    }
    else
    {
        /* disable SL messages */
		support_SL = 0;
    }
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
     switch (trustSetting)
    {
    case WAP_PMG_WL_DISABLED:
        /* disable trust setting */
         whitelist_disable = 1;
         break;
    case WAP_PMG_WL_ACTION_NOTIFY:
    case WAP_PMG_WL_ACTION_DISCARD:
        /* enable trust setting */
         whitelist_disable = 0;
        break;
    default:
        ASSERT(0);
        break;
    }
#else
	 /* disable trust setting */
	 whitelist_disable = 1;
#endif

#ifdef PHS_CFG_PUSH_BLACKLIST_SUPPORT
    switch (blackListEnabled)
    {
    case WAP_PMG_BL_DISABLED:
        /* disable black list setting */
		blacklist_enable = 0;
        break;
    case WAP_PMG_BL_ACTION_NOTIFY:
        /* enable black list setting */
		blacklist_enable = 1;
        break;
    default:
        ASSERT(0);
        break;
    }
#else
	/* disable black list setting */
	blacklist_enable = 0;
#endif

#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
    if (trustSetting == WAP_PMG_WL_ACTION_DISCARD ||
        (trustSetting == WAP_PMG_WL_DISABLED && blackListEnabled == WAP_PMG_BL_DISABLED))  /* meaningless */
    {
        whitelist_behavior = 0;
    }
    else if (trustSetting == WAP_PMG_WL_ACTION_NOTIFY ||
        (trustSetting == WAP_PMG_WL_DISABLED && blackListEnabled == WAP_PMG_BL_ACTION_NOTIFY))
    {
        whitelist_behavior = 1;
    }
#else
	   whitelist_behavior = 0;
#endif
  	pmg_phs_set_config_data (security_level, support_SIR, support_SL, whitelist_behavior, blacklist_enable, whitelist_disable); 
    pmg_phs_init_recv(PMG_PHS_RECV_CONFIG);
 }

/*****************************************************************************
 * FUNCTION
 *  pmg_phs_config_auth_addrs
 * DESCRIPTION
 *  set all trust addresses to PHS registry
 * PARAMETERS
 *  type                [in]
 *  addrs               [in]
 *  segment             [in]
 *  size                [in]
 *	total_segment		[in]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT

void pmg_phs_config_auth_addrs(pmg_auth_list_type type, pmg_addr_t *addrs, int segment, int size, int total_segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, file_handle;
	MSF_UINT8 *file_name = NULL;
	char *del_mem = NULL;
	int file_size_req = 0;


	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	if (type == PMG_AUTH_LIST_TYPE_WHITE)
	{
		for (i = 0; i < size; i++)
		{   
			if (addrs[i].addrType == PMG_ADDR_IP) /* FOR IP ADDRESS*/
			{
				if (whitelist_ip == NULL)
					whitelist_ip = msf_cmmn_str3cat (MSF_MODID_PMG, "01", (const char *)addrs[i].addr, ";");
				else
				{
					del_mem = whitelist_ip;
					whitelist_ip = msf_cmmn_str3cat (MSF_MODID_PMG, whitelist_ip, "01", (char *)addrs[i].addr);
					PMG_MEM_FREE(del_mem);

					del_mem = whitelist_ip;
					whitelist_ip = msf_cmmn_strcat (MSF_MODID_PMG, whitelist_ip, ";");
					PMG_MEM_FREE(del_mem);
				}
			}
			else if (addrs[i].addrType == PMG_ADDR_PHONE) /* FOR SMSC*/
			{
				if (whitelist_smsc == NULL)
					whitelist_smsc = msf_cmmn_str3cat (MSF_MODID_PMG, "00", (const char *)addrs[i].addr, ";");
				else
				{
				   	del_mem = whitelist_smsc;
					whitelist_smsc = msf_cmmn_str3cat (MSF_MODID_PMG, whitelist_smsc, "00", (char *)addrs[i].addr);
					PMG_MEM_FREE(del_mem);

					del_mem = whitelist_smsc;
					whitelist_smsc = msf_cmmn_strcat (MSF_MODID_PMG, whitelist_smsc, ";");
					PMG_MEM_FREE(del_mem);
				}
			}
			else if (addrs[i].addrType == PMG_ADDR_TEXT)
			{
				if (whitelist_domain == NULL)
					whitelist_domain = msf_cmmn_str3cat (MSF_MODID_PMG, "10", (const char *)addrs[i].addr, ";");
				else
				{
				   	del_mem = whitelist_domain;
					whitelist_domain = msf_cmmn_str3cat (MSF_MODID_PMG, whitelist_smsc, "10", (char *)addrs[i].addr);
					PMG_MEM_FREE(del_mem);
					
					del_mem = whitelist_domain;
					whitelist_domain = msf_cmmn_strcat (MSF_MODID_PMG, whitelist_smsc, ";");
					PMG_MEM_FREE(del_mem);
				}
			}
		}

		if (whitelist_smsc != NULL)
			file_size_req +=  strlen(whitelist_smsc);
		if (whitelist_ip != NULL)
			file_size_req +=  strlen(whitelist_ip);

		if (segment == 0)
		{
			file_name = pmg_get_push_location(0, "wlist", file_size_req);
			file_handle = FS_Open((WCHAR*) file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
			if (file_handle <= 0)
			{
				// add looging here 
				ASSERT(0);
			}
		}
		else
		{
			file_name = pmg_get_push_location(0, "wlist", file_size_req);
			file_handle = FS_Open((WCHAR*) file_name, FS_CREATE | FS_READ_WRITE | FS_OPEN_SHARED);
			if (file_handle <= 0)
			{
				// add looging here 
				ASSERT(0);
			}
		}
	
		
		/* dump into the file */
		pmg_phs_file_write (whitelist_ip, whitelist_smsc, whitelist_domain, file_handle, segment, type);		
		
	
	}


#ifdef PHS_CFG_PUSH_BLACKLIST_SUPPORT

	if (type == PMG_AUTH_LIST_TYPE_BLACK)
	{		
		for (i = 0; i < size; i++)
		{   
			if (addrs[i].addrType == PMG_ADDR_IP) /* FOR IP ADDRESS*/
			{
				if (blacklist_ip == NULL)
					blacklist_ip = msf_cmmn_str3cat (MSF_MODID_PMG, "01", (const char *)addrs[i].addr, ";");
				else
				{
					del_mem = blacklist_ip;
					blacklist_ip = msf_cmmn_str3cat (MSF_MODID_PMG, blacklist_ip, "01", (char *)addrs[i].addr);
					PMG_MEM_FREE(del_mem);

					del_mem = blacklist_ip;
					blacklist_ip = msf_cmmn_strcat (MSF_MODID_PMG, blacklist_ip, ";");
					PMG_MEM_FREE(del_mem);
				}
			}
			else if (addrs[i].addrType == PMG_ADDR_PHONE) /* FOR SMSC*/
			{
				if (blacklist_smsc == NULL)
					blacklist_smsc = msf_cmmn_str3cat (MSF_MODID_PMG, "00", (const char *)addrs[i].addr, ";");
				else
				{
					del_mem = blacklist_smsc;
					blacklist_smsc = msf_cmmn_str3cat (MSF_MODID_PMG, blacklist_smsc, "00", (char *)addrs[i].addr);
					PMG_MEM_FREE(del_mem);

					del_mem = blacklist_smsc;
					blacklist_smsc = msf_cmmn_strcat (MSF_MODID_PMG, blacklist_smsc, ";");
					PMG_MEM_FREE(del_mem);
				}
			}
			else if (addrs[i].addrType == PMG_ADDR_TEXT)
			{
				/* not supported */
			}
		}
		/* dump into the file */
	
		
		if (blacklist_smsc != NULL)
			file_size_req +=  strlen(blacklist_smsc);
		if (blacklist_ip != NULL)
			file_size_req +=  strlen(blacklist_ip);

		if (segment == 0)
		{
			file_name = pmg_get_push_location(0, "blist", file_size_req);
			file_handle = FS_Open((WCHAR*) file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
			if (file_handle <= 0)
			{
				MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_FILE_HANDLE_RESPONSE,
                               "PMG: File_handle is negative, Error in file name\n"));
				ASSERT(0);
			}
		}
		else
		{
			file_name = pmg_get_push_location(0, "blist", file_size_req);
			file_handle = FS_Open((WCHAR*) file_name, FS_CREATE | FS_READ_WRITE | FS_OPEN_SHARED);
			if (file_handle <= 0)
			{
				MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_FILE_HANDLE_RESPONSE,
                               "PMG: File_handle is negative, Error in file name\n"));
				ASSERT(0);
			}
		}

		pmg_phs_file_write (blacklist_ip, blacklist_smsc, NULL, file_handle, segment, type);
	}
#endif /* PHS_CFG_PUSH_BLACKLIST_SUPPORT */
    if (g_pmg_phs_cntx.max_trust_addr_no > 0 && g_pmg_phs_cntx.max_black_addr_no > 0)
    {
        if ((g_pmg_phs_cntx.pmg_trust_addr_sizes[PMG_ADDR_PHONE - 1] + 
            g_pmg_phs_cntx.pmg_trust_addr_sizes[PMG_ADDR_IP - 1] + 
            g_pmg_phs_cntx.pmg_trust_addr_sizes[PMG_ADDR_TEXT - 1] > g_pmg_phs_cntx.max_trust_addr_no) ||
            (g_pmg_phs_cntx.pmg_black_addr_sizes[PMG_ADDR_PHONE - 1] + 
            g_pmg_phs_cntx.pmg_black_addr_sizes[PMG_ADDR_IP - 1] + 
            g_pmg_phs_cntx.pmg_black_addr_sizes[PMG_ADDR_TEXT - 1] > g_pmg_phs_cntx.max_black_addr_no))
        {
            ASSERT(0);
        }
    }

    if (type == PMG_AUTH_LIST_TYPE_WHITE)
    {
        pmg_phs_init_recv(PMG_PHS_RECV_WHITELIST);
		/*if segment is 1 then file is done for white list send ind to PHS for white list */
		if (segment == total_segment)
		{			
			pmg_phs_send_data_list_ind (file_name, (MSF_UINT8) PMG_AUTH_LIST_TYPE_WHITE);
		}
		
    }

#ifdef PHS_CFG_PUSH_BLACKLIST_SUPPORT
    if (type == PMG_AUTH_LIST_TYPE_BLACK)
    {
        pmg_phs_init_recv(PMG_PHS_RECV_BLACKLIST);
		/*if segment is 1 then file is done for bl list send ind to PHS for black list */
		if (segment == total_segment)
		{
			pmg_phs_send_data_list_ind (file_name, (MSF_UINT8) PMG_AUTH_LIST_TYPE_BLACK);
		}
    }
#endif/* PHS_CFG_PUSH_BLACKLIST_SUPPORT */
	PMG_MEM_FREE(file_name);
}
#endif /* PHS_CFG_PUSH_WHITELIST_SUPPORT */
/*****************************************************************************
 * FUNCTION
 *  pmg_phs_reset_deleted_msg_state
 * DESCRIPTION
 *  reset deleted message state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_phs_reset_deleted_msg_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmg_phs_cntx.pmg_msg_deleted_state.attr)
        PMG_MEM_FREE(g_pmg_phs_cntx.pmg_msg_deleted_state.attr);

    memset(&g_pmg_phs_cntx.pmg_msg_deleted_state, 0, sizeof(pmg_msg_deleted_msg_t));
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_send_get_msg_by_attribute_reply
 * DESCRIPTION
 *  send PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY signal to PMG
 * PARAMETERS
 *  destMod             [in]
 *  transID             [in]
 *  result              [in]
 *  msg                 [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void
pmg_phs_send_get_msg_by_attribute_reply(MSF_UINT8 destMod, MSF_UINT16 transID, MSF_UINT8 result, pmg_full_msg_t *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_get_msg_by_attribute_reply_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_get_msg_by_attribute_reply_t *param;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.result = result;
    param.msg = (MSF_UINT32) msg;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_6D690AE43DC9C9EA9307F959E3ED3BE2,
                      "PMG: pmg_phs_send_get_msg_by_attribute_reply(%d, %d, 0x%X)\n", transID, result, msg));
    PMG_SEND_SIGNAL(pmg_cvt_get_msg_by_attribute_reply, PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY, MSF_MODID_PMG, destMod);
#else
	param = MSF_MEM_ALLOC(destMod, sizeof(pmg_get_msg_by_attribute_reply_t));
	memset(param, 0, sizeof(pmg_get_msg_by_attribute_reply_t)); // recommended if signal has internal pointers.

	//param->msg =(MSF_UINT32) msf_cmmn_strdup (destMod,(void*) msg); // copies string in destination
	param->msg =(MSF_UINT32)msg;
    param->transID = transID;
    param->result = result;


    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_6D690AE43DC9C9EA9307F959E3ED3BE2,
                      "PMG: pmg_phs_send_get_msg_by_attribute_reply(%d, %d, 0x%X)\n", transID, result, msg));
    MSF_SIGNAL_SEND (MSF_MODID_PMG, destMod, PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY, param);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_handle_get_msg_by_attribute
 * DESCRIPTION
 *  handle PMG_SIG_GET_MSG_BY_ATTRIBUTE signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  p                   [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_handle_get_msg_by_attribute(MSF_UINT8 modid, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_get_msg_by_attribute_t *param = (pmg_get_msg_by_attribute_t*) p;
    pmg_msg_elem_t *elem;
    pmg_full_msg_t *msg;
    char *truncAttr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->msgType == PMG_MSGTYPE_SI)
    {
        truncAttr = msf_cmmn_strndup(MSF_MODID_PMG, param->attribute, PMG_MAX_MSG_SIID_CHARS);
        elem = pmg_msg_find_elem_by_siid(truncAttr);
    }
    else
    {
        truncAttr = msf_cmmn_strndup(MSF_MODID_PMG, param->attribute, PMG_MAX_MSG_HREF_CHARS);
        elem = pmg_msg_find_elem_by_href(truncAttr);
    }
    PMG_MEM_FREE(truncAttr);

    if (elem)
    {
        msg = pmg_msg_retrieve_full_message(elem->msgID);
        if (modid != -1)
            pmg_phs_send_get_msg_by_attribute_reply(modid, param->transID, 1, msg);
    }
    else
    {
        if (modid != -1)
            pmg_phs_send_get_msg_by_attribute_reply(modid, param->transID, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_handle_delete_msg
 * DESCRIPTION
 *  handle PMG_SIG_DELETE_MSG signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  p                   [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_handle_delete_msg(MSF_UINT8 modid, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_delete_msg_t *param = (pmg_delete_msg_t*) p;
    pmg_msg_elem_t *elem;
    MSF_UINT8 msgType;
    char *attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* need to store msgType+siid temporarily because delete_message() frees elem obj */
    elem = pmg_msg_find_elem_by_id(param->msgID);
    if (!elem)
        return;

    msgType = elem->type;
    if (msgType == PMG_MSGTYPE_SI)
        attr = msf_cmmn_strdup(MSF_MODID_PMG, elem->siid);
    else
        attr = msf_cmmn_strdup(MSF_MODID_PMG, elem->href);

    if (pmg_msg_delete_message(param->msgID))
    {
        if (param->isReplace)
        {
            ASSERT(!(g_pmg_phs_cntx.pmg_msg_deleted_state.inUse));
            g_pmg_phs_cntx.pmg_msg_deleted_state.inUse = 1;
            g_pmg_phs_cntx.pmg_msg_deleted_state.msgID = param->msgID;
            g_pmg_phs_cntx.pmg_msg_deleted_state.msgType = msgType;
            g_pmg_phs_cntx.pmg_msg_deleted_state.attr = attr;

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_753A8C0C816A8350817E4A82936CC2D6,
                            "PMG: pmg_phs_handle_delete_msg() start check replace timer\n"));
        }
        else
        {
        #ifdef __MMI_PUSH_IN_UM__
            /* Unified Message */
            /* pmg_um_send_um_refresh_ind(); */
            /* Service Inbox */
            pmg_inbox_send_wps_pmg_delete_ind(param->msgID, msgType);
        #else
            /* Service Inbox */
            pmg_inbox_send_wps_pmg_delete_ind(param->msgID, msgType);
        #endif /* __MMI_PUSH_IN_UM__ */
            pmg_phs_reset_deleted_msg_state();
            PMG_MEM_FREE(attr);
        }
    }
    else
        PMG_MEM_FREE(attr);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_handle_create_msg
 * DESCRIPTION
 *  handle PMG_SIG_CREATE_MSG signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  p                   [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_phs_handle_create_msg(MSF_UINT8 modid, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_msg_file_data_t *msg = (pmg_fs_msg_file_data_t*) (((pmg_create_msg_t*) p)->msg);
    int isReplace;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#endif

    isReplace = 0;
    if (g_pmg_phs_cntx.pmg_msg_deleted_state.inUse) // && pmg_msg_deleted_state.msgType == msg->msgType)
    {
	    ASSERT(g_pmg_phs_cntx.pmg_msg_deleted_state.msgType == msg->msgType);
        if (g_pmg_phs_cntx.pmg_msg_deleted_state.attr &&
            ((g_pmg_phs_cntx.pmg_msg_deleted_state.msgType == PMG_MSGTYPE_SI &&
              msg->siid &&
              strcmp(g_pmg_phs_cntx.pmg_msg_deleted_state.attr, msg->siid) == 0) ||
             (g_pmg_phs_cntx.pmg_msg_deleted_state.msgType == PMG_MSGTYPE_SL &&
              msg->href && strcmp(g_pmg_phs_cntx.pmg_msg_deleted_state.attr, msg->href) == 0)))
        {

            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_PHS_7C57E56A7983BD18A21CD22CD24934C9,
                               "PMG: pmg_phs_handle_create_msg() check replace timer stopped\n"));
            isReplace = 1;
            msg->msgID = g_pmg_phs_cntx.pmg_msg_deleted_state.msgID;
            pmg_phs_reset_deleted_msg_state();
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        isReplace = 0;
    }
#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
    if (pmg_msg_count_all_messages() >= PMG_MAX_PUSH_MESSAGES)
    {
        int msgID = 0, delete_result = 0;
        MSF_UINT8 msgType = PMG_MSGTYPE_NULL;

        delete_result = pmg_msg_delete_oldest_message(&msgID, &msgType);
        pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind(msgID, msgType);
    }
#endif /*__MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__*/
    
	if (!pmg_msg_add_new_message(msg))
    {
#ifdef  __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__     
		pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind(0, 0);
#else
		pmg_inbox_send_wps_pmg_dlg_push_storage_full_ind();
#endif/*__MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__*/
        return;
    }

    if (!isReplace)
        pmg_inbox_send_wps_pmg_new_msg_ind((void*)msg);
    else
    {
    #ifdef __MMI_PUSH_IN_UM__
        /* Unified Message */
        /* pmg_um_send_um_refresh_ind(); */
        /* Service Inbox */
        pmg_inbox_send_wps_pmg_replace_ind((void*)msg);
    #else 
        /* Service Inbox */
        pmg_inbox_send_wps_pmg_replace_ind((void*)msg);
    #endif /* __MMI_PUSH_IN_UM__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  pmg_phs_set_default_connection
 * DESCRIPTION
 *  send signal PMG_SIG_SET_DEF_CONN signal to PHS
 * PARAMETERS
 *  net_id               [in]
 * RETURNS
 *  void
 *****************************************************************************/

static void pmg_phs_set_default_connection(MSF_UINT16 net_id, MSF_UINT32 type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
	pmg_phs_def_con			  send_con;
	msf_dcvt_t                cvt_obj;
	MSF_UINT16                length;
	void                     *signal_buffer, *user_data;
#else

	pmg_phs_def_con			  *send_con;
#endif
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
	send_con.net_id = net_id;
	send_con.type = type;
	
	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
	pmg_cvt_set_def_con (&cvt_obj, &send_con);
	length = (MSF_UINT16)cvt_obj.pos;

    signal_buffer = MSF_SIGNAL_CREATE (PMG_SIG_SET_DEF_CONN, MSF_MODID_PMG,
                                     MSF_MODID_PHS, length);
    if (signal_buffer != NULL) 
	{
		user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
		msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
		pmg_cvt_set_def_con (&cvt_obj, &send_con);
		MSF_SIGNAL_SEND (signal_buffer);
	}
#else
	send_con = MSF_MEM_ALLOC(MSF_MODID_PHS, sizeof(pmg_phs_def_con)); 

	send_con->net_id = net_id;
	send_con->type = type;
	
	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PHS, PMG_SIG_SET_DEF_CONN, send_con);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  pmg_phs_set_config_data
 * DESCRIPTION
 *  send signal PMG_SIG_SET_DATA_TO_SETTING_REQ signal to PHS
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_phs_set_config_data (MSF_UINT16 security_level, MSF_UINT16 support_SIR, MSF_UINT16 support_SL, 
									 MSF_UINT16 whitelist_behavior, MSF_UINT16 blacklist_enable, MSF_UINT16 whitelist_disable)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
	pmg_phs_setting_data_t	  setting_data;
	msf_dcvt_t                cvt_obj;
	MSF_UINT16                length;
	void                     *signal_buffer, *user_data;
#else
	pmg_phs_setting_data_t *setting_data;
#endif

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
	setting_data.security_level = security_level;
	setting_data.support_SIR = support_SIR;
	setting_data.support_SL = support_SL;
	setting_data.whitelist_behavior = whitelist_behavior;
	setting_data.whitelist_disable = whitelist_disable;
	setting_data.blacklist_enable = blacklist_enable;
	
	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
	pmg_cvt_set_data_to_phs_setting (&cvt_obj, &setting_data);
	length = (MSF_UINT16)cvt_obj.pos;
	signal_buffer = MSF_SIGNAL_CREATE (PMG_SIG_SET_DATA_TO_SETTING_REQ, MSF_MODID_PMG,
										MSF_MODID_PHS, length);
	if (signal_buffer != NULL) 
	{
		user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
		msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
		pmg_cvt_set_data_to_phs_setting (&cvt_obj, &setting_data);
		MSF_SIGNAL_SEND (signal_buffer);
	}
#else
	setting_data = MSF_MEM_ALLOC(MSF_MODID_PHS, sizeof(pmg_phs_setting_data_t)); 

	setting_data->security_level = security_level;
	setting_data->support_SIR = support_SIR;
	setting_data->support_SL = support_SL;
	setting_data->whitelist_behavior = whitelist_behavior;
	setting_data->whitelist_disable = whitelist_disable;
	setting_data->blacklist_enable = blacklist_enable;
	
	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PHS, PMG_SIG_SET_DATA_TO_SETTING_REQ, setting_data);
#endif
}
#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
static void pmg_phs_file_write (char* ip, char* smsc, char* domain, int file_handle, int segment, pmg_auth_list_type type)
{
	
    int size_remain;
  
/* For IP */
	if (ip != NULL)
		size_remain = strlen(ip);
	else
		size_remain = 0;
	pmg_phs_file_operation (size_remain, file_handle, 0, ip, segment);

/* For SMSC */
	if (smsc != NULL)
		size_remain = strlen(smsc);
	else
		size_remain = 0;
	pmg_phs_file_operation (size_remain, file_handle, 0, smsc, segment);
/* For Domain */
	if (domain != NULL)
		size_remain = strlen(domain);
	else
		size_remain = 0;
	pmg_phs_file_operation (size_remain, file_handle, 0, domain, segment);
	
	if (type == PMG_AUTH_LIST_TYPE_WHITE)
	{
              if (whitelist_ip != NULL)
			PMG_MEM_FREE (whitelist_ip);
		if (whitelist_smsc != NULL)
			PMG_MEM_FREE (whitelist_smsc);
		if (whitelist_domain != NULL)
			PMG_MEM_FREE (whitelist_domain);

		whitelist_ip = NULL;
		whitelist_smsc = NULL;
		whitelist_domain = NULL;		
	}
	else if (type == PMG_AUTH_LIST_TYPE_BLACK)
	{
		if (blacklist_ip!= NULL)
			PMG_MEM_FREE (blacklist_ip);
		if (blacklist_smsc != NULL)
			PMG_MEM_FREE (blacklist_smsc);

		blacklist_ip = NULL;
		blacklist_smsc = NULL;	
	}
	FS_Close(file_handle);
}

static void pmg_phs_file_operation (int size_remain, int file_handle, int bytes_written, char* data, int segment)
{
	int size;
    int ret;
	int fs_ret = -1, file_size = 0;
	if (size_remain != 0)
	{
		if (segment == 1)
		{
			fs_ret = FS_GetFileSize(file_handle,(UINT*)&file_size);
			if (fs_ret < 0)
			{
				MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG,
                   PMG_PHS_REQ_FILE_SIZE, "PMG: Requested File Size: %d", (MSF_INT32)file_size));
				ASSERT(0);	
			}
			else
			{
			FS_Seek(file_handle, file_size, FS_FILE_BEGIN);
		}
		}
		while (size_remain > 0)
		{
			ret = FS_Write(file_handle, (void*)(data + bytes_written), size_remain, (U32*) & size);
			if (ret != FS_NO_ERROR)
			{
				//pmg_display_error(ret); show error
				FS_Close(file_handle);
			}
			if (size <= 0)
			{
				break;
			}
			bytes_written += size;
			size_remain -= size;
		}		
	}
	FS_Commit(file_handle);
}

static void pmg_phs_send_data_list_ind (MSF_UINT8 *file_name, MSF_UINT8 list_type)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
#ifdef __OBIGO_FRMW2__
	pmg_phs_list_data_t		  list;
	msf_dcvt_t                cvt_obj;
	MSF_UINT16                length;
	void                     *signal_buffer, *user_data;
    char *temp ;
    MSF_UINT16 len;
#else

	pmg_phs_list_data_t		  *list;

    char *temp ;
#endif    

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__

    temp = pmg_mem_alloc(256); 
    len = app_ucs2_str_to_asc_str ((kal_int8*)temp, (kal_int8*) file_name);  

	list.file_name = (char *)temp;
	list.list_type = list_type;

	msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
	pmg_cvt_data_list (&cvt_obj, &list);
	length = (MSF_UINT16)cvt_obj.pos;
	signal_buffer = MSF_SIGNAL_CREATE (PMG_SIG_SET_LIST_DATA_IND, MSF_MODID_PMG,
										MSF_MODID_PHS, length);
	if (signal_buffer != NULL) 
	{
		user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);
		msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, 0);
		pmg_cvt_data_list (&cvt_obj, &list);
		MSF_SIGNAL_SEND (signal_buffer);
	}

	PMG_MEM_FREE(temp);

#else
	list = MSF_MEM_ALLOC(MSF_MODID_PHS, sizeof(pmg_phs_list_data_t));

	memset(list, 0, sizeof(pmg_phs_list_data_t)); // recommended if signal has internal pointers.
    temp = pmg_mem_alloc(256); 
    app_ucs2_str_to_asc_str ((kal_int8*)temp, (kal_int8*) file_name);  

	//list->file_name = (char *)temp;
	list->list_type = list_type;
	list->file_name = msf_cmmn_strdup (MSF_MODID_PHS, (char *)temp); // copies string in destination.

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PHS, PMG_SIG_SET_LIST_DATA_IND, list);

	PMG_MEM_FREE(temp);
#endif
}

#endif
