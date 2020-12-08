/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  NtpSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement NTP service functions.
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
// NTP header
#include "NtpSrvGprot.h"
#include "mmi2ntpd_struct.h"
#include "custom_ntp_config.h"

// frm header
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "app_datetime.h"
#include "DateTimeGprot.h"
#include "TimerEvents.h"

#include "FileMgrSrvGprot.h"

#include "cbm_api.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"

#include "NwInfoSrvGprot.h"
#include "RestoreSrvGprot.h"
#include "ModeSwitchSrvGProt.h"

// trace header
#include "MMI_trc_Int.h"
#include "mmi_conn_app_trc.h"

#include "mmi_rp_srv_ntp_def.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_setting_def.h"
#include "vapp_worldclock_gprot.h"
#else
#include "mmi_rp_app_ntp_def.h"
#include "Mmi_rp_app_worldclock_def.h"
#endif

/*
 * NTP config file version no, if structure modified, please change this No.
 * please refer to {srv_ntp_config_fs_struct}
 */
#define SRV_NTP_CONFIG_VERNO ((MMI_SIM_TOTAL) * 100 + 0)

typedef struct
{
    S16 verno;                      // refer to {SRV_NTP_CONFIG_VERNO}
    S8  dummy;                      // no use, structure
    S8  is_available;               // the setting is on/off
    U32 data_acct[MMI_SIM_TOTAL];   // data account id
} srv_ntp_config_fs_struct;

typedef struct
{
    srv_ntp_config_fs_struct config;
    CHAR drive;
    U8 app_id;

    MMI_BOOL ignored_1st_nw_evt;
    MMI_BOOL sync_is_running;
    MMI_BOOL flight_mode_changed;
    ntpd_sync_cb _callback;
    void*        _userdata;
} srv_ntp_struct;

typedef enum
{
    SRV_NTP_FS_READ  = 0,
    SRV_NTP_FS_WRITE = 1
} srv_ntp_read_write_enum;

static srv_ntp_struct g_ntp;
static srv_ntp_struct *ntp = &g_ntp;

static void srv_ntp_sys_drive_init(void);
static void srv_ntp_app_id_init(void);
static void srv_ntp_config_init(void);
static void srv_ntp_config_reset(void);
static void srv_ntp_config_file_get_path(WCHAR* path, S32 buffer_len);
static void srv_ntp_auto_sync_result_proc(S32 res, S64 offset, void*user_data);
static void srv_ntp_auto_sync_timer_proc(void);
static void srv_ntp_auto_sync_timer_start(void);
static void srv_ntp_auto_sync_for_first_time(void);
static S32 srv_ntp_config_read_write(srv_ntp_read_write_enum fs_type);
static S32 srv_ntp_data_acct_delete_proc(mmi_event_struct* param);
static S32 srv_ntp_data_acct_update_proc(mmi_event_struct* param);

/* init ntp srv context */
void srv_ntp_init(void)
{
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_INIT, 0);

    memset(ntp, 0, sizeof(*ntp));

    srv_ntp_sys_drive_init();
    srv_ntp_app_id_init();
    srv_ntp_config_init();
    srv_ntp_auto_sync_for_first_time();

    /* register data account events handler */
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND,
        srv_ntp_data_acct_delete_proc, NULL);

    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND,
        srv_ntp_data_acct_update_proc, NULL);

    mmi_frm_cb_reg_event(EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED,
        srv_ntp_evt_hdlr, NULL);
    
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND,
        srv_ntp_evt_hdlr, NULL);

    // restore factory notification
    mmi_frm_cb_reg_event(EVT_ID_SRV_RESTORE_START_NOTIFY,
        srv_ntp_evt_hdlr, NULL);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_INIT, 1);
}

/* auto sync result proc function */
void srv_ntp_auto_sync_result_proc(S32 result, S64 offset, void*user_data)
{
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_AUTO_SYNC_RESULT_PROC, result, (S32)(offset/1000));

    if (result == 0)
    {
        /* for SUCCESS, update phone's time */
        srv_ntp_update_time_to_phone(offset, NULL, NULL);
    }
}

/* auto sync timer hander */
void srv_ntp_auto_sync_timer_proc(void)
{
    if (!srv_ntp_availability_get())
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_AUTO_SYNC_TIMER_PROC);
    srv_ntp_sync(srv_ntp_auto_sync_result_proc, NULL);
    srv_ntp_auto_sync_timer_start();
}

/* start auto sync timer */
void srv_ntp_auto_sync_for_first_time(void)
{
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_AUTO_SYNC_TIMER_START);

    StartTimer(NTP_SYNC_TIMER,
               SRV_NTP_AUTO_SYNC_FOR_1ST_TIME * 1000,
               srv_ntp_auto_sync_timer_proc);
}

/* start auto sync timer */
void srv_ntp_auto_sync_timer_start(void)
{
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_AUTO_SYNC_TIMER_START);

    StartTimer(NTP_SYNC_TIMER,
               SRV_NTP_AUTO_SYNC_INTERVAL_SEC * 1000,
               srv_ntp_auto_sync_timer_proc);
}

/* init system drive */
void srv_ntp_sys_drive_init(void)
{
    ntp->drive = (CHAR)FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_SYS_DRIVE_INIT, ntp->drive);
}

/* init app id */
void srv_ntp_app_id_init(void)
{
    cbm_app_info_struct app_info;

    app_info.app_type = DTCNT_APPTYPE_NTP;
    app_info.app_str_id = STR_ID_NTP_APP;
    app_info.app_icon_id = IMG_ID_NTP_ICON;
    cbm_register_app_id_with_app_info(&app_info, &ntp->app_id);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_APP_ID_INIT, ntp->app_id);
}

/* init config struct */
void srv_ntp_config_init(void)
{
    S32 ret, i;
    
    ret = srv_ntp_config_read_write(SRV_NTP_FS_READ);
    if (ret != FS_NO_ERROR || ntp->config.verno != SRV_NTP_CONFIG_VERNO)
    {
        srv_ntp_config_reset();
        srv_ntp_config_read_write(SRV_NTP_FS_WRITE);
    }

    // set app id to data account id
    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {   
        ntp->config.data_acct[i] = cbm_set_app_id(ntp->config.data_acct[i],
                                                  ntp->app_id);
    }

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_CONFIG_INIT, ret);
}

/* reset config buffer */
void srv_ntp_config_reset(void)
{
    S32 i;

    memset(&ntp->config, 0xFFFFFFFF, sizeof(ntp->config));
    ntp->config.verno = SRV_NTP_CONFIG_VERNO;
    ntp->config.is_available = 0;
    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {    
        ntp->config.data_acct[i] = cbm_encode_data_account_id(
                                    CBM_DEFAULT_ACCT_ID,
                                    (cbm_sim_id_enum)(CBM_SIM_ID_SIM1 + i),
                                    ntp->app_id,
                                    MMI_FALSE);
    }

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              SRV_NTP_CONFIG_RESET,
              MMI_SIM_TOTAL,
              ntp->config.data_acct[0],
              ntp->config.data_acct[1],
              ntp->config.data_acct[2],
              ntp->config.data_acct[3]);
}

/* make config file path */
void srv_ntp_config_file_get_path(WCHAR* path, S32 buffer_len)
{
    kal_wsprintf(path, "%c:\\ntp.conf", ntp->drive);
}

/* read config file content, return fs error code */
S32 srv_ntp_config_read_write(srv_ntp_read_write_enum fs_type)
{
    S32 ret = 0;
    S32 size;
    U32 rw;
    WCHAR *path;
    FS_HANDLE fs_handle;

    size = (SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(WCHAR);
    path = (WCHAR*)OslMalloc(size);

    srv_ntp_config_file_get_path(path, size);

    if (fs_type == SRV_NTP_FS_READ)
    {
        fs_handle = FS_Open(path, FS_READ_ONLY);
    }
    else
    {
        fs_handle = FS_Open(path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    }

    if (fs_handle < FS_NO_ERROR)
    {
        OslMfree(path);
        MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
                  SRV_NTP_CONFIG_READ_WRITE,
                  fs_type,
                  ret);
        return fs_handle;
    }

    size = sizeof(ntp->config);
    if (fs_type == SRV_NTP_FS_READ)
    {
        ret = FS_Read(fs_handle, &ntp->config, size, &rw);
    }
    else
    {
        ret = FS_Write(fs_handle, &ntp->config, size, &rw);
    }

    if (ret < FS_NO_ERROR || rw != size)
    {
        if (ret == FS_NO_ERROR)
        {
            ret = -1;
        }
    }
    FS_Close(fs_handle);
    OslMfree(path);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              SRV_NTP_CONFIG_READ_WRITE,
              fs_type,
              ret);
    return ret;
}

/* return whether NTP is on/off */
MMI_BOOL srv_ntp_availability_get(void)
{
    ASSERT(ntp->config.is_available == 1 || ntp->config.is_available == 0);
    return ntp->config.is_available == 1 ? MMI_TRUE : MMI_FALSE;
}

/* turn on/off NTP, if error happen, return FS code */
S32 srv_ntp_availability_set(MMI_BOOL is_available)
{
    S32 ret = 0;

    if (ntp->config.is_available != is_available)
    {
        ntp->config.is_available = is_available;
        ret = srv_ntp_config_read_write(SRV_NTP_FS_WRITE);
    }

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              SRV_NTP_AVAILABILITY_SET,
              is_available,
              ret);
    return ret;
}

/* set data account, if error happen, return FS code */
S32 srv_ntp_data_acct_set(U32 data_acct, U32 sim_index)
{
    S32 ret;
    if (ntp->config.data_acct[sim_index] == data_acct)
    {
        return 0;
    }

    ntp->config.data_acct[sim_index] = data_acct;
    ret = srv_ntp_config_read_write(SRV_NTP_FS_WRITE);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              SRV_NTP_DATA_ACCT_SET,
              data_acct,
              sim_index,
              ret);
    return ret;
}

/* get data account value */
U32 srv_ntp_data_acct_get(U32 sim_index)
{
    return ntp->config.data_acct[sim_index];
}

/* get app id */
U8 srv_ntp_data_acct_app_id_get(void)
{
    return ntp->app_id;
}

/* handle data account delete event */
S32 srv_ntp_data_acct_delete_proc(mmi_event_struct* param)
{
    srv_dtcnt_acct_delete_ind_evt_struct *dt_acct;
    MMI_BOOL acct_info_changed = MMI_FALSE;
    cbm_account_info_struct acctInfo;
    U32 i, j;

    dt_acct = (srv_dtcnt_acct_delete_ind_evt_struct*)param;

    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        cbm_decode_data_account_id_ext(ntp->config.data_acct[i], &acctInfo);

        if (acctInfo.acct_num == 1 &&
            !acctInfo.account[0].is_always_ask)
        {
            MMI_BOOL matched = MMI_FALSE;

            for (j = 0; j < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; ++j)
            {
                if (acctInfo.account[0].account_id == dt_acct->acc_id[i])
                {
                    matched = MMI_TRUE;
                    break;
                }
            }

            if (matched)
            {
                acct_info_changed = MMI_TRUE;
                acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
                cbm_encode_data_account_id_ext(
                    ntp->config.data_acct[i],
                    &ntp->config.data_acct[i],
                    &acctInfo);
            }
        }
    }

    if (acct_info_changed)
    {
        srv_ntp_config_read_write(SRV_NTP_FS_WRITE);
    }
    return MMI_RET_OK;
}

/* handle data account update event */
S32 srv_ntp_data_acct_update_proc(mmi_event_struct* param)
{
    srv_dtcnt_acct_update_ind_evt_struct *dt_acct;
    MMI_BOOL acct_info_changed = MMI_FALSE;
    cbm_account_info_struct acctInfo;
    U32 i;

    dt_acct = (srv_dtcnt_acct_update_ind_evt_struct*)param;
    
    for (i = 0; i < MMI_SIM_TOTAL; ++i)
    {
        cbm_decode_data_account_id_ext(ntp->config.data_acct[i], &acctInfo);

        if (acctInfo.acct_num == 1 &&
            acctInfo.account[0].account_id == dt_acct->acc_id &&
            !acctInfo.account[0].is_always_ask)
        {
            acct_info_changed = MMI_TRUE;
            acctInfo.account[0].account_id = CBM_DEFAULT_ACCT_ID;
            cbm_encode_data_account_id_ext(ntp->config.data_acct[i],
                                           &ntp->config.data_acct[i],
                                           &acctInfo);
        }
    }

    if (acct_info_changed)
    {
        srv_ntp_config_read_write(SRV_NTP_FS_WRITE);
    }
    return MMI_RET_OK;
}

/* check whether there's already one sync instance running */
MMI_BOOL srv_ntp_state_sync_is_running(void)
{
    return ntp->sync_is_running;
}

/* update phone's system date time */
void srv_ntp_update_time_to_phone(S64 offset,
                                  srv_ntp_set_time_funcptr callback,
                                  void *userdata)
{
    U32 utcSec;
    S32 offset_sec = (S32)(offset/1000);
    applib_time_struct updateTime;
    applib_dt_get_rtc_time(&updateTime);

    utcSec = applib_dt_mytime_2_utc_sec(&updateTime, MMI_FALSE);
    utcSec += offset_sec;

    applib_dt_utc_sec_2_mytime(utcSec, &updateTime, MMI_FALSE);

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD,
              SRV_NTP_UPDATE_TIME_TO_PHONE,
              updateTime.nYear,
              updateTime.nMonth,
              updateTime.nDay,
              updateTime.nHour,
              updateTime.nMin,
              updateTime.nSec);

    mmi_dt_set_dt((const MYTIME*)&updateTime, callback, userdata);
}

/* ntp sync callback function */
static void srv_ntp_sync_callback(S32 result, S64 offset, void *usr_data)
{
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_SYNC_CALLBACK, result, offset);

    if (ntp->_callback != NULL)
    {
        ntp->_callback(result, offset, usr_data);
    }
    ntp->sync_is_running = MMI_FALSE;
    ntpd_close();
}

/* get prefer data account */
static U32 srv_ntp_data_acct_get_prefer(void)
{
    U32 sim_index = 0;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_NONE;

    srv_dtcnt_get_sim_preference(&sim_type);

    if (sim_type != SRV_DTCNT_SIM_TYPE_NONE)
    {
        sim_index = (U32)(sim_type - SRV_DTCNT_SIM_TYPE_1);
    }

    return srv_ntp_data_acct_get(sim_index);
}

/* parse server file */
S32 srv_ntp_fs_server_parse(CHAR *content, mmi_ntpd_config_struct *config)
{
    S32 i;
    CHAR *trail;

    for (i = 0; i < NTPD_SERVER_NUM && i < NTP_SERVER_NUM;)
    {
        while (*content == 0x0D || *content == 0x0A)
        {
            ++content;
        }

        if (*content == '\0')
        {
            break;
        }

        trail = content;
        while (*trail != 0x0D && *trail != 0x0A && *trail != '\0')
        {
            ++trail;
        }

        if (*trail == '\0')
        {
            strncpy(config->server[i++], content, NTPD_MAX_NAME_LEN);
            break;
        }
        else
        {
            *trail = '\0';
            strncpy(config->server[i++], content, NTPD_MAX_NAME_LEN);
        }
        content = (++trail);
    }

    return i;
}

/* used to support config server lsit in a text file */
S32 srv_ntp_fs_server_read(mmi_ntpd_config_struct *config)
{
    S32 ret, rw;
    FS_HANDLE fs_handle;
    WCHAR path[] = L"D:\\ntp_server_list.txt";
    CHAR *content;
    U32 real_num = 0;
    U32 file_size = 0;

    path[0] = (WCHAR)FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM);
    fs_handle = FS_Open(path, FS_READ_ONLY);
    if (fs_handle < FS_NO_ERROR)
    {
        return fs_handle;
    }

    if ((ret = FS_GetFileSize(fs_handle, &file_size)) < FS_NO_ERROR)
    {
        FS_Close(fs_handle);
        return ret;
    }

    // size should be in limited rage
    if (file_size < 512)
    {
        content = OslMalloc(file_size + 1);
        ret = FS_Read(fs_handle, content, file_size, &rw);
        if (ret >= FS_NO_ERROR && rw == file_size)
        {
            content[file_size] = '\0';
            real_num = srv_ntp_fs_server_parse(content, config);
        }
        OslMfree(content);
    }

    FS_Close(fs_handle);

    return real_num;
}

MMI_BOOL srv_ntp_is_background_sync_running(void)
{
    return ntp->sync_is_running;
}

/* ntp sync main function */
S32 srv_ntp_sync(srv_ntp_sync_cb callback, void*userdata)
{
    S32 i, ret = 0, real_server_num = 0;
    mmi_ntpd_config_struct config;

    if (ntp->sync_is_running)
    {
        return SRV_NTP_ERROR_SYNC_BACKGROUND;
    }

    if (!srv_ntp_availability_get())
    {
        return SRV_NTP_ERROR_SYNC_BACKGROUND + 1;
    }

    memset(&config, 0, sizeof(config));

    real_server_num = srv_ntp_fs_server_read(&config);
    if (real_server_num <= 0)
    {
        for (i = 0; i < NTPD_SERVER_NUM && i < NTP_SERVER_NUM; ++i)
        {
            strncpy(config.server[i], g_ntp_servers[i], NTPD_MAX_NAME_LEN);
        }
        real_server_num = i;
    }

    for (i = 0; i < real_server_num; ++i)
    {
        config.port[i] = NTP_PROTOCAL_PORT;
    }

    config.server_num   = (U16)real_server_num;
    config.account_id   = srv_ntp_data_acct_get_prefer();
    config.samples      = NTP_SAMPLES_NUM;
    config.timeout      = NTP_TIME_OUT_SECONDS;
    config.auth         = 0;

    ret = ntpd_open(&config);
    if (ret != NTPD_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_SYNC, ret, __LINE__);
        ntpd_close();
        return ret;
    }

    ret = ntpd_sync((ntpd_sync_cb)srv_ntp_sync_callback, userdata);
    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_SYNC, ret, __LINE__);
    if (ret == NTPD_SUCCESS)
    {
        ntp->_callback = callback;
        ntp->_userdata = userdata;
        ntp->sync_is_running = MMI_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_SYNC, ret, __LINE__);
    return ret;
}

/* abort sync */
void srv_ntp_abort(void)
{
    ntp->_callback = NULL;
    ntp->_userdata = NULL;
    ntp->sync_is_running = MMI_FALSE;

    ntpd_close();
}

/* get whether daylight saving is on */
MMI_BOOL srv_ntp_get_daylight_saving(void)
{
#ifndef __COSMOS_MMI_PACKAGE__
    S16 error;
#endif
    U8 daylight_saving = 0;

#ifdef __COSMOS_MMI_PACKAGE__
    daylight_saving = mmi_wc_get_home_dst();
#else
    ReadValue(NVRAM_SETTING_DT_DST, &daylight_saving, DS_BYTE, &error);
#endif
    return daylight_saving ? MMI_TRUE : MMI_FALSE;
}

/* handle system event */
mmi_ret srv_ntp_evt_hdlr(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
        case EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED:
        {
            srv_nw_info_service_availability_changed_evt_struct *availability_evt = 
                (srv_nw_info_service_availability_changed_evt_struct*)event;

            if (availability_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE)
            {
                U32 tick;

                kal_get_time(&tick);
                if (!ntp->ignored_1st_nw_evt || tick < KAL_TICKS_5_SEC * 2)
                {
                    ntp->ignored_1st_nw_evt = MMI_TRUE;
                    MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_EVT_HDLR, __LINE__);
                    return MMI_RET_OK;
                }

                if (ntp->flight_mode_changed)
                {
                    ntp->flight_mode_changed = MMI_FALSE;
                }

                MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_EVT_HDLR, __LINE__);
                srv_ntp_sync(srv_ntp_auto_sync_result_proc, NULL);
            }
        }
        break;

        case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
        {
            srv_dtcnt_wlan_init_res_ind_evt_struct *wlan_evt;
            wlan_evt = (srv_dtcnt_wlan_init_res_ind_evt_struct *)event;
            if (wlan_evt->res == SRV_DTCNT_WLAN_REQ_RES_DONE)
            {
                MMI_TRACE(MMI_CONN_TRC_G9_NTPD, SRV_NTP_EVT_HDLR, __LINE__);
                if (ntp->flight_mode_changed)
                {
                    ntp->flight_mode_changed = MMI_FALSE;
                srv_ntp_sync(srv_ntp_auto_sync_result_proc, NULL);
            }
        }
        }
        break;

        case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
        {
            srv_mode_switch_notify_struct *switch_notify;
            switch_notify = (srv_mode_switch_notify_struct*)event;
            if (switch_notify->curr_flight_mode == SRV_MODE_SWITCH_ON &&
                switch_notify->select_flight_mode == SRV_MODE_SWITCH_OFF)
            {
                ntp->flight_mode_changed = MMI_TRUE;
            }
        }
        break;

        case EVT_ID_SRV_RESTORE_START_NOTIFY:
        {
            srv_ntp_availability_set(MMI_FALSE);
        }
        break;
    }

    return MMI_RET_OK;
}

void srv_ntp_restore_notify(void)
{
    srv_ntp_availability_set(MMI_FALSE);
}
