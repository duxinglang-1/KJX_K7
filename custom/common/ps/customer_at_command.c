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
 * Filename:
 * ---------
 * Custom_at_command.c
 *
 * Description:
 * ------------
 *   This file is intends for Customer to implement and parse its own defined AT commands
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
*****************************************************************************/
//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
#include "stdio.h"
#include "string.h"
//#include "stack_config.h"	

#include "kal_general_types.h"
#include "kal_internal_api.h"
#include "ata_external.h"
#if (defined(__COMPOSITE_WEBCAM__))
#include "cal_api.h"
#include "cal_comm_def.h"
#endif
#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#if defined(__PLMN_LIST_WITH_CELL_INFO__)
#include "ps_public_struct.h"
#endif

#if defined(__KJX_AT_APP__)
#include "MMI_features.h"
#include "MMIDataType.h"
#include "TimerEvents.h"
#include "Uart_sw.h"
#include "Nvram_common_defs.h"
#include "Mmi_frm_nvram_gprot.h"
#include "Stack_msgs.h"
#include "QueueGprot_Int.h"
#include "kjx_at_command.h"
#include "kjx_sms_command.h"
#include <math.h>
#endif
extern void kal_monitor_buffer(kal_uint32 index);
extern kal_bool twomicnr_command_hdlr(char *full_cmd_string);

/*****************************************************************************
* CUSTOM_SYMBOL:
*	customer can modify this symbol.
*     Every command begin with this symbol will be recognized as a customer-defined command
*	and passed to custom_command_hdlr().
*     For example: if CUSTOM_SYMBOL is set to '^', 
*				then AT^AAAA, AT^BBBB will be customer-defined command.
*   	NOTE:  '+'  and '/' and ' \ 'is not allowed since they might be standard command format
*****************************************************************************/
#define CUSTOM_SYMBOL  '^'	 // '+'  and '/' and ' \ 'is NOT allowed   

/*****************************************************************************
* MAX_UART_LEN = 128 bytes.
*	when you write a lot of data to UART at the same time, 
*	UART's buffer might be full and cannot handle.
*     so the safer way is to seperate the long data, each time only write data length <= 128
*****************************************************************************/
#define MAX_UART_LEN	128  
#if defined(__KJX_AT_APP__)
typedef unsigned char    U8;
typedef unsigned short	U16;
typedef signed int S32;
typedef signed short S16;

#define KJX_AT_CMD	"GT_CM"	//xb add 2017-05-04 避免跟A1项目一样的指令GT_CM
#define MAX_CMD_LEN  100   //命令码最大长度
#define MAX_CMD_DATA_LEN 512
#define MAX_GROUP_NUM 20/*用于分组功能*/
#define GROUP_DATA_LEN 50
#define CUST_AT_CMD_MAX_LEN 16
#define TRUE 1
#define FALSE 0
#define MAX_CMD_BUF_SIZE 10 //用于存放待发命令缓冲区大小
#define MAX_RESNED_TIMES 3  //最大重发次数
#define RESEND_OVERTIME  300 //重发的超时时间
/*****************************************************************************
* Typedef  Enum
*****************************************************************************/
//解析AT指令所需的相关变量
typedef enum
{
    GENERAL_CMD,		//常规命令AT^CMD
    PARAM_CMD,			//有参数的命令AT^CMD xxx
    EVALUATE_CMD		//赋值命令AT^CMD = xxx
} at_cmd_type;

/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/
typedef struct
{
    at_cmd_type cmd_type;
    char cmd_code[MAX_CMD_LEN];
    kal_int8 cmd_data[MAX_CMD_DATA_LEN];
    kal_uint16 data_len;
} custom_at_cmd;

typedef struct
{
    kal_uint8 init_flag;
    kal_uint8 cur_cmd_index; //当前已发送命令的索引
    kal_uint8 cur_cmd_send_times; //当前命令发送次数
    kal_bool cmd_flag[MAX_CMD_BUF_SIZE]; //当前命令标志 0:无效 1:有效
    kal_uint16 delay_time[MAX_CMD_BUF_SIZE];//延时发送时间
    char cmd[MAX_CMD_BUF_SIZE][MAX_CMD_LEN];
} custom_send_cmd;

typedef struct
{
    char at_cmd_name[CUST_AT_CMD_MAX_LEN];
    kal_int16 index;
} at_cmd_index_struct;

typedef void (*FuncPtr) (void);

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static custom_send_cmd Send_Cmd;
static char data_group[MAX_GROUP_NUM][GROUP_DATA_LEN+1];

/****************************************************************************
* Global Variable -             全局变量
*****************************************************************************/
#if 1 //xb add 2017-01-11
void pmu_drv_keypad_blink(kal_bool flag){};

#endif

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern RECEIVED_DATA_STRUCT received_data;
extern AT_DATA_STRUCT DATA_SET;

/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
extern kal_uint8 custom_get_atcmd_symbol(void);
extern void custom_cmd_resend(void);
extern void custom_cmd_delaysend(void);
extern void l4c_send_to_wap(msg_type msgid, void* data_ptr);
extern U16 AnsiiToUnicodeString(S8 *pOutBuffer, S8 *pInBuffer);
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff);
extern void StartTimer(U16 timerid, U32 delay, FuncPtr funcPtr);

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
static void custom_make_upper(char* buf);
static void custom_clear_splace(kal_int8* buf, kal_uint16 len);
static kal_bool custom_cmd_parse(custom_at_cmd* cmd);
static void custom_cmd_send_next(void);

/******************************************************************************
 *  Function    -  custom_cmd_send
 *
 *  Purpose     -  发送命令到串口
 *
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void custom_cmd_send(char* cmd, kal_bool bCheckRes, kal_uint16 delay_time)
{
    kal_uint8 i, full_flag = TRUE;
    kal_uint16 DataLen = 0;

    if(!strlen(cmd))
    {
        return;
    }
    if(!bCheckRes)
    {
        if(strlen(cmd) > MAX_CMD_LEN)
        {
            DataLen = MAX_CMD_LEN;
        }
        else if((strlen(cmd) > 0) && (strlen(cmd) < MAX_CMD_LEN))
        {
            DataLen = strlen(cmd);
        }
        rmmi_write_to_uart((kal_uint8*)cmd, DataLen, KAL_TRUE);
    }
    else
    {
        if(Send_Cmd.init_flag != 1)
        {
            memset(&Send_Cmd, 0x00, sizeof(custom_send_cmd));
            Send_Cmd.init_flag = 1;
        }
        if(!Send_Cmd.cmd_flag[Send_Cmd.cur_cmd_index])    //当前命令无效
        {
            strcpy((char*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index], cmd);
            Send_Cmd.cmd_flag[Send_Cmd.cur_cmd_index] = 1;
            Send_Cmd.delay_time[Send_Cmd.cur_cmd_index] = delay_time;
            if(!delay_time)
            {
                Send_Cmd.cur_cmd_send_times++;
                rmmi_write_to_uart((kal_uint8*)cmd, strlen(cmd), KAL_TRUE);
                StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, RESEND_OVERTIME, custom_cmd_resend);
            }
            else
            {
                StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, delay_time, custom_cmd_delaysend);
            }
        }
        else //当前命令有效，直接放到空的缓冲区中
        {
            for(i = Send_Cmd.cur_cmd_index + 1; i < MAX_CMD_BUF_SIZE; i++)
            {
                if(!Send_Cmd.cmd_flag[i])
                {
                    strcpy((char*)Send_Cmd.cmd[i], cmd);
                    Send_Cmd.cmd_flag[i] = 1;
                    Send_Cmd.delay_time[i] = delay_time;
                    full_flag = FALSE;
                    break;
                }
            }
            if(i >= MAX_CMD_BUF_SIZE && Send_Cmd.cur_cmd_index)
            {
                for(i = 0; i < Send_Cmd.cur_cmd_index; i++)
                {
                    if(!Send_Cmd.cmd_flag[i])
                    {
                        strcpy((char*)Send_Cmd.cmd[i], cmd);
                        Send_Cmd.cmd_flag[i] = 1;
                        Send_Cmd.delay_time[i] = delay_time;
                        full_flag = FALSE;
                        break;
                    }
                }
            }

            if(full_flag)  //如果缓冲区满的话，覆盖最后一个
            {
                if(!Send_Cmd.cur_cmd_index)
                {
                    strcpy((char*)Send_Cmd.cmd[MAX_CMD_BUF_SIZE - 1], cmd);
                    Send_Cmd.cmd_flag[MAX_CMD_BUF_SIZE - 1] = 1;
                }
                else
                {
                    strcpy((char*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index - 1], cmd);
                    Send_Cmd.cmd_flag[Send_Cmd.cur_cmd_index - 1] = 1;
                }
            }
        }
    }
}
#endif/*__KJX_AT_APP__*/

kal_uint8 custom_get_atcmd_symbol(void);
kal_bool custom_command_hdlr(char *full_cmd_string);

/*****************************************************************************
* FUNCTION
*  	rmmi_write_to_uart()
* DESCRIPTION
*   	This function extern L4C RMMI function,
*     is to write data to UART
* PARAMETERS
*   	kal_uint8 * buffer 	- the data to be written
*	kal_uint16 length 	- the length of data to be written
*     kal_bool stuff 		- KAL_TRUE : <CR><LF> will be added at the beginning and end. (eg.<CR><LF>OK<CR><LF>)
*					   KAL_FALSE: no <CR><LF> is added
* RETURNS
*	none
*****************************************************************************/
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 

#ifdef __GATI_ENABLE__
extern kal_bool gati_command_hdlr(kal_uint8* cmd_string, kal_uint8* full_string);

module_type gati_mod_table[] = 
{
    MOD_PHB,
    MOD_L4C,
    MOD_L4C,
    MOD_L4C, 
    MOD_NIL         /* Need to be the last one */
};

kal_char *gati_cmd_table[] = 
{
    "CPBBA",
    "CPBBR",
    "CPBBS",
    "CPBB"
};

#endif

#ifdef __GAS_SUPPORT__
extern kal_bool gas_command_hdlr(kal_uint8* cmd_string, kal_uint8* full_string);

module_type gas_mod_table[] = 
{
#ifdef __TCPIP__
    MOD_ABM,
#endif
    MOD_L4C,
    MOD_CSM,
#if defined(__BTMTK__)
    MOD_BT,
#endif
    MOD_NIL         /* Need to be the last one */
};

kal_char *gas_cmd_table[] = 
{
#ifdef __TCPIP__
    "EWIFI",
#endif
    "CL4C",
    "CCSM"
#if defined(__BTMTK__)
    ,"EBTAT"
#endif
};
#endif


typedef struct
{
	char *commandString;
	custom_rsp_type_enum (*commandFunc)(custom_cmdLine *commandBuffer_p);
} custom_atcmd;

custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line);

custom_rsp_type_enum custom_test_func(custom_cmdLine *commandBuffer_p)
{
    custom_cmd_mode_enum result;
    custom_rsp_type_enum ret_value  = CUSTOM_RSP_ERROR;

    result = custom_find_cmd_mode(commandBuffer_p);		
    switch (result)
    {
        case CUSTOM_READ_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_ACTIVE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_SET_OR_EXECUTE_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;
        case CUSTOM_TEST_MODE:
            ret_value = CUSTOM_RSP_OK;
            break;    
        default:
            ret_value = CUSTOM_RSP_ERROR;
            break;
	}
    return ret_value;
}

#if defined(__KJX_AT_APP__)
typedef unsigned char U8;

kal_bool is_factory_test_mode;
kal_bool is_vibrator_test_on =KAL_FALSE;
kal_bool is_speaker_test_on =KAL_FALSE;
extern void mmi_fm_vibrator_test(void);
extern void mmi_fm_gps_power_on(void);
extern void KKS_Set_GPS_Test_Flag(void);
#ifndef WIN32
void led_light_factory_test(void){};
#else
extern void led_light_factory_test(void);
#endif
extern void FM_SendPlayAudioReq(U8 index);
extern void FM_SendStopAudioReq(U8 index);
#endif

/********************************
* The following table is used for the customer
* They can defined their own command and 
* corresponding handler function here
* Note that the last line {NULL, NULL} should not be removed
* since it is the terminator indicator
*********************************/
#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__) && defined(__YML_NVRAM_WITH_BACKUP_PARTITION__)
extern custom_rsp_type_enum ata_set_sds(custom_cmdLine *commandBuffer_p);
#endif
const custom_atcmd custom_cmd_table[ ] =
{    
    {"AT%CUSTOM",custom_test_func},
#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__) && defined(__YML_NVRAM_WITH_BACKUP_PARTITION__)
    {"AT+ESDS",ata_set_sds},			//备份升级
#endif

#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__)
#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO)
	{"AT^MSDC",ata_t_card_hdlr_v1}, 		  //T Card
#endif

	{"AT+EMVI",ata_vibrator_hdlr_v1},			  //Vibrator

#if (defined(FM_RADIO_ENABLE))	
	{"AT+EMFM",ata_fm_hdlr_v1}, 			  //FM
#endif

#if defined(TOUCH_PANEL_SUPPORT) && defined(TOUCH_PANEL_INTERNAL)
	{"AT+ETPID",ata_tp_hdlr_v1},			  //TouchPanel
#endif

#if defined(ISP_SUPPORT)
	{"AT+ECMFP",ata_camera_hdlr_v1},		  //camera
#endif

#if defined(__ATV_SUPPORT__)
	{"AT+EMATV",ata_matv_hdlr_v1},				//Matv
	{"AT+EMATVP",ata_matv_video_hdlr_v1},				//Matv video	
#endif

#if defined(__CUST_NEW__)
	{"AT+EKPT",ata_kpt_hdlr_v1},			  //Keypad Test
#endif

	{"AT+EMAUDIO",ata_audio_hdlr_v1},			  //Audio
	{"AT+ELED",ata_led_hdlr},			   //LED
	{"AT+ELCM",ata_lcm_hdlr},			   //LCM
	{"AT+EMBKL",ata_bkl_hdlr},			   //Backlight
#endif/*__ATA_SUPPORT__ && __MTK_TARGET__*/

    {NULL, NULL}  // this lind should not be removed, it will be treat as 
};

/*****************************************************************************
* FUNCTION
*     custom_find_cmd_mode()
* DESCRIPTION
*     This function is used to parsing the command mode for the customer
*     The input position of the cmd_line should stay at the character right after the command name
* PARAMETERS
*     cmd_line      the custom_cmdLine which contains the command string and its current parsing position
* RETURNS
*     custom_cmd_mode_enum
*****************************************************************************/
custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line)
{
    custom_cmd_mode_enum result;

    if (cmd_line->position < cmd_line->length - 1)
    {
        switch (cmd_line->character[cmd_line->position])
        {
            case '?':  /* AT+...? */
            {
                cmd_line->position++;
                result = CUSTOM_READ_MODE;
                break;
            }
            case '=':  /* AT+...= */
            {
                cmd_line->position++;
                if ((cmd_line->position < cmd_line->length - 1 ) &&
                    (cmd_line->character[cmd_line->position] == '?'))
                {
                    cmd_line->position++;
                    result = CUSTOM_TEST_MODE;
                }
                else
                {
                    result = CUSTOM_SET_OR_EXECUTE_MODE;
                }
                break;
            }
            default:  /* AT+... */
            {
                result = CUSTOM_ACTIVE_MODE;
                break;
            }
        }
    }
    else
    {
        result = CUSTOM_ACTIVE_MODE;
    }
    return (result);
}


#if defined(__KJX_AT_APP__)
#include "MMI_features.h" 
#include "Nvram_common_defs.h" 
#include "Mmi_frm_nvram_gprot.h" 
#include "Stack_msgs.h" 
#include "QueueGprot_Int.h" 
#include "gpiosrvgprot.h"

#include "mdi_audio.h"
#include "med_api.h"
#include "med_struct.h"
#include "l1audio.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"

#include "common_nvram_editor_data_item.h"

#include "kjx_sms_command.h"

kal_uint8 at_received_data[200];
#if defined(__KJX_AT_APP__) 
void print_uart(char *str);
#endif
/******************************************************************************
 *  Function    -  l4c_sendmsg_to_mmi
 *
 *  Purpose     -  l4层向mii发送消息
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void l4c_sendmsg_to_mmi(void* data_ptr)
{
    MYQUEUE Message;

    Message.oslMsgId = MSG_ID_MMI_AT_COMMAND_SET_REQ;
    Message.oslDataPtr = (oslParaType*)data_ptr;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSapId = MMI_L4C_SAP;
    Message.oslSrcId = MOD_L4C  ;
    Message.oslDestId = MOD_MMI;
    Message.sap_id = MMI_L4C_SAP;
    OslMsgSendExtQueue(&Message);

} 

void At_Vibrateor(void)
{  
   char buffer[MAX_UART_LEN+1];

    is_vibrator_test_on =!is_vibrator_test_on;
    if(is_vibrator_test_on)
    {
    	srv_vibrator_on();
		sprintf(buffer, "Vibrator ON");
    }
	else
	{
		srv_vibrator_off();
		sprintf(buffer, "Vibrator OFF");
	}
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
}

void At_Speaker(void)
{
   char buffer[MAX_UART_LEN+1];

	is_speaker_test_on =!is_speaker_test_on;
	if(is_speaker_test_on)
	{
		//FM_SendPlayAudioReq(0);		    	
		srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, AUD_ID_PROF_TONE1,SRV_PROF_RING_TYPE_REPEAT,NULL);
		sprintf(buffer, "Speaker ON");
	}
	else
	{
		//FM_SendStopAudioReq(0);	
		srv_profiles_stop_tone(SRV_PROF_TONE_ALARM);
		sprintf(buffer, "Speaker OFF");
	}
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
}

/******************************************************************************
 *  Function    -  custom_make_upper
 *
 *  Purpose     -  将字符串转换成大写
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void custom_make_upper(char* buf)
{
    kal_uint16  i;
    for(i = 0; i < strlen(buf); i++)
    {
        if(buf[i] >= 0x61 && buf[i] <= 0x7a)
        {
            buf[i] -= 0x20;
        }
    }
}

/******************************************************************************
 *  Function    -  custom_cmd_resend
 *
 *  Purpose     -  重发处理函数
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void custom_cmd_resend(void)
{
    if(!Send_Cmd.cmd_flag[Send_Cmd.cur_cmd_index])  //当前命令无效，停止重发
    {
        StopTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND);
    }
    else
    {
        if(Send_Cmd.cur_cmd_send_times >= MAX_RESNED_TIMES)  //超过最大最发次数
        {
            StopTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND);
            memset(&Send_Cmd.cmd[Send_Cmd.cur_cmd_index], 0x00, MAX_CMD_LEN);
            Send_Cmd.cmd_flag[Send_Cmd.cur_cmd_index] = 0;
            Send_Cmd.cur_cmd_send_times = 0;

            custom_cmd_send_next();
        }
        else//继续重发
        {
            Send_Cmd.cur_cmd_send_times++;
            rmmi_write_to_uart((kal_uint8*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index], strlen((char*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index]), KAL_TRUE);
            StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, RESEND_OVERTIME, custom_cmd_resend);
        }
    }
}


/******************************************************************************
 *  Function    -  custom_clear_splace
 *
 *  Purpose     -  去掉串口接收到数据的字符串两边的空格
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void custom_clear_splace(kal_int8* buf, kal_uint16 len)
{
    kal_uint16  i, num = 0;

    //去掉字符串左边的空格
    for(i = 0; i < len; i++)
    {
        if(buf[i] == 0x20)
        {
            num ++;
        }
        else
        {
            break;
        }
    }
    if(num)
    {
        memcpy(buf, &buf[num], len - num);
        memset(&buf[len - num], 0x00, num);
        len -= num;
    }
    //去掉字符串右边的空格
    for(i = len - 1; i ; i--)
    {
        if(buf[i] == 0x20)
        {
            buf[i] = 0x00;
        }
        else
        {
            break;
        }
    }
}


/******************************************************************************
 *  Function    -  custom_apart_data
 *
 *  Purpose     - 串口字符串根据分隔符对数据进行分组
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
U8 custom_apart_data(char apart_char, U8 group_num, char* buf)
{
    U8 start = 0, cur, num = 0;

    if(apart_char == NULL || group_num == 0 || buf == NULL) return 0;
    if(group_num >= MAX_GROUP_NUM) group_num = MAX_GROUP_NUM;
    memset(data_group, 0x00, sizeof(data_group));
    for(cur = 0; cur < strlen(buf); cur ++)
    {
        if(buf[cur] == apart_char)
        {
            strncpy(data_group[num], &buf[start], cur - start);
            start = cur + 1;
            num ++;
            if(num == group_num) return num;
        }
    }

    if(start < cur && num < group_num)
    {
        strncpy(data_group[num], &buf[start], cur - start);
        num ++;
    }
    return num;
}



/******************************************************************************
 *  Function    -  custom_cmd_send_next
 *
 *  Purpose     -  发送一条串口指令之后继续发送一条命令
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void custom_cmd_send_next(void)
{
    kal_uint8 i;

    for(i = Send_Cmd.cur_cmd_index + 1; i < MAX_CMD_BUF_SIZE; i++)
    {
        if(Send_Cmd.cmd_flag[i])
        {
            Send_Cmd.cur_cmd_index = i;
            if(!Send_Cmd.delay_time[i])
            {
                Send_Cmd.cur_cmd_send_times = 1;
                rmmi_write_to_uart((kal_uint8*)Send_Cmd.cmd[i], strlen((char*)Send_Cmd.cmd[i]), KAL_TRUE);
                StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, RESEND_OVERTIME, custom_cmd_resend);
            }
            else
            {
                StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, Send_Cmd.delay_time[i], custom_cmd_delaysend);
            }
            break;
        }
    }

    if(i >= MAX_CMD_BUF_SIZE && (Send_Cmd.cur_cmd_index + 1) == MAX_CMD_BUF_SIZE)
    {
        for(i = 0; i < Send_Cmd.cur_cmd_index; i++)
        {
            if(Send_Cmd.cmd_flag[i])
            {
                Send_Cmd.cur_cmd_index = i;
                if(!Send_Cmd.delay_time[i])
                {
                    Send_Cmd.cur_cmd_send_times = 1;
                    rmmi_write_to_uart((kal_uint8*)Send_Cmd.cmd[i], strlen((char*)Send_Cmd.cmd[i]), KAL_TRUE);
                    StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, RESEND_OVERTIME, custom_cmd_resend);
                }
                else
                {
                    StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, Send_Cmd.delay_time[i], custom_cmd_delaysend);
                }
                break;
            }
        }
    }
}



/******************************************************************************
 *  Function    -  custom_cmd_delaysend
 *
 *  Purpose     -  延时发送处理函数
 *
 *  Description -
 *
 * modification history
 ******************************************************************************/
void custom_cmd_delaysend(void)
{
    Send_Cmd.cur_cmd_send_times++;
    rmmi_write_to_uart((kal_uint8*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index],
	strlen((char*)Send_Cmd.cmd[Send_Cmd.cur_cmd_index]), KAL_TRUE);
    StartTimer(KJX_TIMER_ID_CUSTOM_CMD_SEND, RESEND_OVERTIME, custom_cmd_resend);
}

/******************************************************************************
 *  Function    -  custom_cmd_parse
 *
 *  Purpose     -  对串口字符串进行解析
 *
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool custom_cmd_parse(custom_at_cmd* cmd)
{
    U8 num;

    memset(&DATA_SET, 0x00, sizeof(DATA_SET));
    //开始用construct_local_para分配内存发多了死机
    if(cmd->cmd_type == EVALUATE_CMD)	//如果是赋值命令AT^CMD = xxx
    {
        if((strcmp(cmd->cmd_code, KJX_AT_CMD) == 0))
        {
            num = custom_apart_data(',', 10, (char*)cmd->cmd_data);	//将字符串分段 cjt 增加2段
            strcpy((char*)(DATA_SET.param0), data_group[1]);		//将分段了的字符串存储到p_DATA_SET内
            strcpy((char*)(DATA_SET.param1), data_group[2]);
            strcpy((char*)(DATA_SET.param2), data_group[3]);
            strcpy((char*)(DATA_SET.param3), data_group[4]);
            strcpy((char*)(DATA_SET.param4), data_group[5]);
            strcpy((char*)(DATA_SET.param5), data_group[6]);
            strcpy((char*)(DATA_SET.param6), data_group[7]);
            strcpy((char*)(DATA_SET.param7), data_group[8]);
            strcpy((char*)(DATA_SET.param8), data_group[9]);
            strcpy((char*)(DATA_SET.main_string), (char*)data_group[0]);
            DATA_SET.part = num - 1;
			
			//发送一个消息给mmi并将数据传送过去
			l4c_sendmsg_to_mmi(NULL);
			return KAL_TRUE;
        }
    }
    else if(cmd->cmd_type == GENERAL_CMD)
    {
		return KAL_FALSE;
    }
    else
    {
		return KAL_FALSE;
    }

    return KAL_TRUE;
}
#endif/*__KJX_AT_APP__*/


/*****************************************************************************
* FUNCTION
*  	custom_command_hdlr()
* DESCRIPTION
*   	This function should parse the custom AT command and do correspondent action.
*     Customer should maintain and modify the code.
* PARAMETERS
*   	kal_uint8 * cmd_string
* RETURNS
*    KAL_TRUE : the command is handled by the customer
*    KAL_FALSE: the command is not handled by the customer
*****************************************************************************/
#ifdef __MMI_SUPPORT_GPS_CONTROL__
extern void KKS_Set_GPS_Test_Flag(void);
#endif

#if defined(__KJX_AT_APP__)    //guojie
#if defined(__WDT_USE_I2C__)
extern kal_uint8 I2CTest;
#endif
void print_uart(char *str)
{
   char buffer[200];

   strcpy(buffer, str);
   rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
}

kal_bool custom_command_hdlr(char *full_cmd_string)
{
    kal_uint16 findindex = 3; // we start parsing index after the CUSTOM_SYMBOL
    kal_uint16 tmp_idx = 0;
    kal_uint8 curdata_type = 0;
    kal_bool pre_is_space = KAL_FALSE;
    char result[2][10] = {"OK", "ERROR 0"};
    custom_at_cmd cmd;
    char *pbeg;
    char buffer[MAX_UART_LEN+1]; //MAUI_02377056
    char *cmd_name, *cmdString;
    kal_uint8 index = 0; 
    kal_uint16 length;
    kal_uint16 i;
    custom_cmdLine command_line;
	U16 at_len;
    
    cmd.cmd_type = GENERAL_CMD;
    pbeg = full_cmd_string;
    if((strlen((char *)pbeg)==2)&&(strncmp(pbeg, (char*)"AT", 2) == 0))
    {
        sprintf(buffer,"OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);        
        return KAL_TRUE;
    }    
    pbeg += 3;
    
    memset(&cmd, 0x00, sizeof(custom_at_cmd));

    //IMEI比对工具  cjt  使用pc工具版本1.0.0.5
	if((strncmp(pbeg, (char*)"GT_CM=VERSION_PC", 16) == 0)||(strncmp(pbeg, (char*)"GT_CM=version_pc", 16) == 0))
    	{
		sprintf(buffer, "[VERSION]%s",release_verno());
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}

#ifdef __WHITE_PHONEBOOK__
   	{
   	   if (is_whitebook_set_cmd(pbeg)) //   WN&&..... 白名单相关指令
   	   	{
   	   	   Tracker_White_Phonebook_Parse_AT(pbeg);  //白名单处理
   	   	   return KAL_TRUE;
   	   	}
   	}
#endif
	
    if(strncmp(pbeg, (char*)KJX_AT_CMD, strlen(KJX_AT_CMD)) == 0)
    {
        while(1)
        {
            if(full_cmd_string[findindex] == '=')
            {
                pre_is_space = KAL_FALSE;
                if(curdata_type != 1)
                {
                    cmd.cmd_type = EVALUATE_CMD;   //赋值命令AT^CMD = xxx
                    curdata_type = 1;
                    findindex ++;
                    tmp_idx = 0;
                    continue;
                }
            }
            else if(full_cmd_string[findindex] == '?')
            {
                pre_is_space = KAL_FALSE;
                if(curdata_type != 1)
                {
                    cmd.cmd_type = PARAM_CMD;   //有参数的命令AT^CMD xxx
                    curdata_type = 1;
                    tmp_idx = 0;
                }
            }
            else if(full_cmd_string[findindex] == 0x20)
            {
                if(curdata_type != 1)
                {
                    pre_is_space = KAL_TRUE;
                    findindex ++;
                    continue;
                }
            }
            else if(full_cmd_string[findindex] == 0x0D)
            {
                break;
            }
            else
            {
                if(pre_is_space && curdata_type != 1)
                {
                    cmd.cmd_type = PARAM_CMD;//有参数的命令AT^CMD xxx
                    curdata_type = 1;
                    tmp_idx = 0;
                }
            }

            if(curdata_type == 0)
            {
                if(tmp_idx >= MAX_CMD_LEN)
                {
                    break;
                }
                cmd.cmd_code[tmp_idx] = full_cmd_string[findindex];
            }
            else
            {
                if(tmp_idx >= MAX_CMD_DATA_LEN)
                {
                    break;
                }
                cmd.cmd_data[tmp_idx] = full_cmd_string[findindex];
            }
            findindex ++;
            tmp_idx ++;
        }

        if(curdata_type)
        {
            cmd.data_len = tmp_idx;
        }
        else
        {
            cmd.data_len = 0;
        }

        custom_clear_splace((kal_int8*)cmd.cmd_code, strlen(cmd.cmd_code));
        custom_clear_splace((kal_int8*)cmd.cmd_data, cmd.data_len);
        custom_make_upper((char*)cmd.cmd_code);

        if(!strlen(cmd.cmd_code) || (cmd.cmd_type == EVALUATE_CMD && !cmd.data_len))
        {       
            return KAL_TRUE;
        }
        else
        {
            custom_cmd_parse(&cmd);
            return KAL_TRUE;
        }       
    }

    cmd_name = full_cmd_string;
    for(i = 0 ; custom_cmd_table[i].commandString != NULL; i++)
    {
        cmdString = custom_cmd_table[i].commandString;
        if (strcmp(cmd_name, cmdString) == 0 )
        {
            strncpy(command_line.character, full_cmd_string, COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH);
            command_line.character[COMMAND_LINE_SIZE] = '\0';
            command_line.length = strlen(command_line.character);
            command_line.position = index;
            if (custom_cmd_table[i].commandFunc(&command_line) == CUSTOM_RSP_OK) 
            {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            else
            {
                sprintf(buffer, "ERROR 1");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            return KAL_TRUE;
        }
    }    

    /* just a very basic example : customer can implement their own */
	if (strlen(cmd_name)<=3 || cmd_name[2] !='^')
	{
		return KAL_FALSE;
	}

	// AT^指令
    cmd_name += 3;
	at_len = strlen(cmd_name);

	if (cmd_name[at_len-1] == 0x0D ||cmd_name[at_len-1] == 0x0A)
	{
		cmd_name[at_len-1]=0x00; //斩断
	}

#if defined(__BOSCH_BMP280_PRESSURE__)
	if((strcmp(cmd_name, "BMP280_INI") == 0)||(strcmp(cmd_name, "bmp280_ini") == 0))
	{
		kal_int8 com_rslt;

		bmp280_set_soft_rst();
		bmp280_i2c_udelay(50);
		com_rslt = BMP280_Begin();
		sprintf(buffer, "BMP280 :%d", com_rslt);
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);   

		kal_prompt_trace(MOD_WAP,  "BMP280 :%d", com_rslt);

		return KAL_TRUE;
	}
	else if((strcmp(cmd_name, "BMP280_DATA") == 0)||(strcmp(cmd_name, "bmp280_data") == 0))
	{
		kal_int32 v_actual_temp;
		kal_uint32 v_actual_press;
		float press_float, temp_float;
		float altitude=0, seaLevelhPa=0, mmHg=0;
		double result;
		
		v_actual_temp = BMP280_ReadTemperature();
		v_actual_press = BMP280_ReadPressure();

		temp_float = (float)v_actual_temp;
		press_float = (float)v_actual_press;
		
		mmHg = press_float/133.321995;
		seaLevelhPa = 101325.0f;

		result = (double)pow(press_float/seaLevelhPa, (float)(1.0/5255.0));
		sprintf(buffer, "temp_float:%f, press_float:%f, seaLevelhPa:%F, result:%f, %.2fmmHg\n", temp_float, press_float, seaLevelhPa, result, mmHg);
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		
		altitude = 44330000*(1.0 - result);

		sprintf(buffer, "Temperature: %d.%dC; Pressure:%d Pa; altitude:%.2f\n", v_actual_temp/100, v_actual_temp%100, v_actual_press, altitude);

		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);	
		kal_prompt_trace(MOD_WAP,  "%s", buffer);

		return KAL_TRUE;
	}
#endif

#if defined(__MOTION_SENSOR_MC3451_SUPPORT__) 
	if ((strcmp(cmd_name, "MOTION_INI") == 0)||(strcmp(cmd_name, "motion_ini") == 0))
	{
		extern void acc_sensor_init(void);

		acc_sensor_init();             
		return KAL_TRUE;
	}
	else if ((strcmp(cmd_name, "MOTION_REG") == 0)||(strcmp(cmd_name, "motion_reg") == 0))
	{
		extern void is_motion_sensor_shake(void);
		
		is_motion_sensor_shake();
		return KAL_TRUE;
	}		
	else if ((strcmp(cmd_name, "MOTION_GET") == 0)||(strcmp(cmd_name, "motion_get") == 0))
	{
		kal_uint16 acc_x,acc_y,acc_z;
		extern void mc3451_sensor_get_data(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
		
		mc3451_sensor_get_data(&acc_x,&acc_y,&acc_z);
		return KAL_TRUE;
	}
	else if ((strcmp(cmd_name, "MOTION_PEDO") == 0)||(strcmp(cmd_name, "motion_pedo") == 0))
	{
		extern void mmi_mc3451_pedometer_start_timer(void);
		mmi_mc3451_pedometer_start_timer();
		return KAL_TRUE;
	}
	else if ((strcmp(cmd_name, "MOTION_RESET") == 0)||(strcmp(cmd_name, "motion_reset") == 0))
	{
		extern void motion_acc_sensor_reset_pedometer(void);
		motion_acc_sensor_reset_pedometer();
		return KAL_TRUE;
	}
#endif

#if defined(__BLE_MODULE_SUPPORT__)
	if((strncmp(cmd_name, "BLE_POWER",9) == 0)||(strncmp(cmd_name, "ble_power",9) == 0))
	{
		if((strncmp(cmd_name+9, "ON",2) == 0)||(strncmp(cmd_name+9, "on",2) == 0))
		{
			ble_mod_power_on();
			sprintf(buffer, "ble poweron");
		}
		else if((strncmp(cmd_name+9, "OFF",3) == 0)||(strncmp(cmd_name+9, "off",3) == 0))
		{
			ble_mod_power_off();
			sprintf(buffer, "ble poweroff");            
		}
		else
		{
			sprintf(buffer, "ble power cmd error");            
		}         
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);   

		kal_prompt_trace(MOD_WAP,  "ble :%s", cmd_name+9);

		return KAL_TRUE;
	}		
#endif

    if (strcmp(cmd_name, "EXAMPLE") == 0)
    {		
        /* BEGIN: do the following parsing and correspondent action */
        /*  												    */
        /*  												    */
        /*  												    */
        /* END: do the following parsing and correspondent action    */

        /* generate final result code: "OK" or "ERROR" */
        if(KAL_TRUE)    // if operation is success
        {
            sprintf(buffer, "OK");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        else if (KAL_FALSE) // if operation is fail
        {
            sprintf(buffer, "ERROR 2");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        return KAL_TRUE;
    }
#if defined(__KJX_AT_APP__)          //songwh  0509
    else if ((strcmp(cmd_name, "I2CTEST") == 0)||(strcmp(cmd_name, "i2ctest") == 0))
	{    	   
	#if defined(__WDT_USE_I2C__)
		I2CTest=3;
		print_uart("I2CTest=3");
	#endif
	}
#if defined(__WATCH_DOG_SPI__)
	else if(strcmp(cmd_name, "WATCHDOGINIT") == 0)
	{
		WDT_SystemOn_Init();
		sprintf(buffer, "Watchdog init");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}
	else if(strcmp(cmd_name, "WATCHDOGWRITE") == 0)
	{
		Watchdog_write_Spi_Data();
		sprintf(buffer, "Watchdog write");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}
	else if((strncmp(cmd_name, "WATCHDOGAT",10) == 0)||(strncmp(cmd_name, "watchdogat",10) == 0))   
	{
		kal_uint8 cmd=0;
		cmd =atoi(cmd_name+10);	
		Watchdog_write_Spi_cmd(cmd);
		sprintf(buffer, "Watchdog AT %d",cmd);
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}
	else if((strcmp(cmd_name, "WATCHDOGDISABLE") == 0)||(strcmp(cmd_name, "watchdogdisable") == 0))   
	{
		Watch_Dog_Disable();
		sprintf(buffer, "Watchdog disable");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}
	else if((strcmp(cmd_name, "WATCHDOGENABLE") == 0)||(strcmp(cmd_name, "watchdogenable") == 0))   
	{
		Watch_Dog_Enable();
		sprintf(buffer, "Watchdog enable");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;
	}
#endif
	else if((strcmp(cmd_name, "LIGHTON") == 0)||(strcmp(cmd_name, "lighton") == 0))
	{
		pmu_drv_keypad_blink(KAL_TRUE);
		rmmi_write_to_uart((kal_uint8*)"ON", strlen("ON"), KAL_TRUE); 
		return KAL_TRUE;
	}
	else if((strcmp(cmd_name, "LIGHTOFF") == 0)||(strcmp(cmd_name, "lightoff") == 0))
	{
		pmu_drv_keypad_blink(KAL_FALSE);
		rmmi_write_to_uart((kal_uint8*)"OFF", strlen("OFF"), KAL_TRUE); 
		return KAL_TRUE;
	}
	else if ((strcmp(cmd_name, "LIGHTTEST") == 0)||(strcmp(cmd_name, "lighttest") == 0))
	{
		is_factory_test_mode =!is_factory_test_mode;
		led_light_factory_test();
		if(is_factory_test_mode)
		{
			sprintf(buffer, "Factory Test!");
		}
		else
		{
			sprintf(buffer, "Factory Test close!");
		}			
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return KAL_TRUE;	
	}
	else if ((strcmp(cmd_name, "TEST") == 0)||(strcmp(cmd_name, "test") == 0))
	{
	#if defined(__WDT_USE_I2C__)
		I2CTest=3;
	#endif
		is_factory_test_mode =!is_factory_test_mode;
		led_light_factory_test();
		if(is_factory_test_mode)
		{
			sprintf(buffer, "Factory Test!");
		}
		else
		{			
			sprintf(buffer, "Factory Test close!");
		}			
		
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);			
		return KAL_TRUE;	
	}
	else if ((strcmp(cmd_name, "VIBRATOR") == 0)||(strcmp(cmd_name, "vibrator") == 0))
		{
		   At_Vibrateor();
		   return KAL_TRUE;
		}
	else if ((strcmp(cmd_name, "SPEAKER") == 0)||(strcmp(cmd_name, "speaker") == 0))
	{		
	    At_Speaker();
		return KAL_TRUE;	
	}
	else if((strcmp(cmd_name, "CALLTEST") == 0)||(strcmp(cmd_name, "calltest") == 0))	//xb add 2014-9-22
	{
	#ifndef WIN32
		BOOL PhoneCallOK;
	#else
		extern BOOL PhoneCallOK;
	#endif

		if(PhoneCallOK)
		{
			sprintf(buffer, "CALLINOK");
		}
		else
		{
			sprintf(buffer, "WAITCALL");
		}
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);			
		return KAL_TRUE;
	}
#if defined(__GPS_SUPPORT__)
	else if ((strcmp(cmd_name, "GPSTEST") == 0)||(strcmp(cmd_name, "gpstest") == 0))
	{
		KKS_Set_GPS_Test_Flag();
		mmi_fm_gps_power_on();
		sprintf(buffer, "GPS,ON!");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);			
		return KAL_TRUE;
	}
#endif
#endif/*__KJX_AT_APP__*/
#if !defined(__MMI_FMI__) || defined(WISDOM_MMI)
    else if (strcmp(cmd_name, "buffer") == 0)
    {		
        kal_print("Buffer Monitor enabled!");
        kal_monitor_buffer(0xffffffff);		
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        return KAL_TRUE;
    }	
#endif	
#ifdef __TWOMICNR_SUPPORT__ 
    else if (twomicnr_command_hdlr(full_cmd_string) == KAL_TRUE)
    {
		return KAL_TRUE;
    }
#endif
#if (defined(__COMPOSITE_WEBCAM__)) 
    else if (strcmp(cmd_name, "SENSOR") == 0)
    {
        CAL_FEATURE_CTRL_STRUCT CalInPara;
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_TUNING_SENSOR;
        CalInPara.FeatureSetValue = (kal_uint32)(full_cmd_string);
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        return KAL_TRUE;
    }
#endif
    else
    {
	#ifdef __GAS_SUPPORT__
        if( gas_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }
	#endif 
    #ifdef __GATI_ENABLE__ 
        /* Judge if the command string is a GATI command*/
        if( gati_command_hdlr( (kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string)==KAL_TRUE )
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }		 	
    #endif
    }	
		 
    /* unrecognized command */
    /* we should return KAL_FALSE to let ATCI judge if the it can handle the command */
	//print_uart("Step END");
    return KAL_FALSE;
	
}

#else
kal_bool custom_command_hdlr(char *full_cmd_string)
{
    char buffer[MAX_UART_LEN+1];
    char *cmd_name, *cmdString;
    kal_uint8 index = 0;
    kal_uint16 length;
    kal_uint16 i;
    custom_cmdLine command_line;
#if defined(__MMI_SUPPORT_GPS_CONTROL__)//wnq
    char *pbeg;
#endif/*__MMI_SUPPORT_GPS_CONTROL__*/

    cmd_name = buffer;

    length = strlen(full_cmd_string);
    length = length > MAX_UART_LEN ? MAX_UART_LEN : length;
    while((full_cmd_string[index] != '=') &&    //might be TEST command or EXE command
            (full_cmd_string[index] != '?') &&  // might be READ command
            (full_cmd_string[index] != 13) &&  //carriage return
            index < length)
    {
        cmd_name[index] = full_cmd_string[index] ;
        index ++;
    }
    cmd_name[index] = '\0' ;

#if defined(__MMI_SUPPORT_GPS_CONTROL__)//wnq   //AT^TEST 
    pbeg = full_cmd_string;
    pbeg += 3;
    if(strncmp(pbeg, (char*)"TEST", 4) == 0)
    {
        KKS_Set_GPS_Test_Flag();
        Entry_Show_GPS_SCR();
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        return KAL_TRUE;
    }
#endif/*__MMI_SUPPORT_GPS_CONTROL__*/

    for(i = 0 ; custom_cmd_table[i].commandString != NULL; i++)
    {
        cmdString = custom_cmd_table[i].commandString;
        if(strcmp(cmd_name, cmdString) == 0)
        {
            strncpy(command_line.character, full_cmd_string, COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH);
            command_line.length = strlen(command_line.character);
            command_line.position = index;
            if(custom_cmd_table[i].commandFunc(&command_line) == CUSTOM_RSP_OK)
            {
                sprintf(buffer, "OK");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            else
            {
                sprintf(buffer, "ERROR 3");
                rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
            }
            return KAL_TRUE;
        }
    }

    if(index <= 2)
        return KAL_FALSE;

    /* just a very basic example : customer can implement their own */
    cmd_name += 3;
    if(strcmp(cmd_name, "EXAMPLE") == 0)
    {
        /* BEGIN: do the following parsing and correspondent action */
        /*  												    */
        /*  												    */
        /*  												    */
        /* END: do the following parsing and correspondent action    */

        /* generate final result code: "OK" or "ERROR" */
        if(KAL_TRUE)    // if operation is success
        {
            sprintf(buffer, "OK");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        else if(KAL_FALSE)  // if operation is fail
        {
            sprintf(buffer, "ERROR 4");
            rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
        }
        return KAL_TRUE;
    }
#if !defined(__MMI_FMI__) || defined(WISDOM_MMI)
    else if(strcmp(cmd_name, "buffer") == 0)
    {
        kal_print("Buffer Monitor enabled!");
        kal_monitor_buffer(0xffffffff);
        sprintf(buffer, "OK");
        rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

        return KAL_TRUE;
    }
#endif
#ifdef __TWOMICNR_SUPPORT__
    else if(twomicnr_command_hdlr(full_cmd_string) == KAL_TRUE)
    {
        return KAL_TRUE;
    }
#endif
#if (defined(__COMPOSITE_WEBCAM__))
    else if(strcmp(cmd_name, "SENSOR") == 0)
    {
        CAL_FEATURE_CTRL_STRUCT CalInPara;
        CalInPara.FeatureId = CAL_FEATURE_CAMERA_TUNING_SENSOR;
        CalInPara.FeatureSetValue = (kal_uint32)(full_cmd_string);
        CalCtrl(CAL_FEATURE_CTRL, (void*)&CalInPara, NULL, 0, NULL);
        return KAL_TRUE;
    }
#endif
    else
    {
	#ifdef __GATI_ENABLE__
        /* Judge if the command string is a GATI command*/
        if(gati_command_hdlr((kal_uint8*)cmd_name, (kal_uint8*)full_cmd_string) == KAL_TRUE)
        {
            // it is a gati command and we will send the command to the appropriate module
            return KAL_TRUE;
        }
	#endif
    }

    /* unrecognized command */
    /* we should return KAL_FALSE to let ATCI judge if the it can handle the command */
    return KAL_FALSE;
}
#endif/*__KJX_AT_APP__*/

/*****************************************************************************
* FUNCTION
*  	custom_get_atcmd_symbol()
* DESCRIPTION
*   	This function returns special symbol for customer-defined AT command, 
*   	so AT parser can recognize its a custom command and forward the string to custom_command_handler().
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_atcmd_symbol(void)
{
	return (CUSTOM_SYMBOL);
}

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for data mode (CSD/GPRS dialup)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE (1)

/*****************************************************************************
* USER DEFINE CONSTANT
*  	RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE
* DESCRIPTION
* 	1. This value defines the control DCD value for AT command mode (Normal/Escaped AT)
*   2. CUSTOMER CAN modify this value accroding to its TE requirement
*****************************************************************************/
#define RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE (0)

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_data_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for data state
*
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_data_state(void)
{
    return (kal_uint8) RMMI_CUSTOM_DCD_VALUE_IN_DATA_STATE;
}

/*****************************************************************************
* FUNCTION
*  	custom_get_dcd_value_for_cmd_state()
* DESCRIPTION
*   	This function returns the user-defined DCD value for command state
*       It shall be inverted value of custom_get_dcd_value_for_data_state()
*     CUSTOMER DOES NOT need to modify this function.
* PARAMETERS
*   	none
* RETURNS
*     kal_uint8 
*****************************************************************************/
kal_uint8 custom_get_dcd_value_for_cmd_state(void)
{
    return (kal_uint8)RMMI_CUSTOM_DCD_VALUE_IN_CMD_STATE;
}

#ifdef __MOD_TCM__
/*****************************************************************************
* FUNCTION
*  	custom_get_gprs_dialup_connect_post_string()
* DESCRIPTION
*   This function returns the post string right after CONNECT in gprs dialup.
*
*   The return string length must be less than 64
*
*   If post_string is XXXXXX, 
*   then MS sends "<cr><lf>CONNECT XXXXXX<cr><lf>" when GPRS dialup
*   Ex.1 if post_string=" 230400", 
*        then entire output string is "<cr><lf>CONNECT 230400<cr><lf>"
*   Ex.2 if post_string=" 56000 V42bis", 
*        then entire output string is "<cr><lf>CONNECT 56000 V42bis<cr><lf>"
*    
* PARAMETERS
*   kal_uint8 act, ACcess Technology, 
                   This field value can be referred to TS27.007
                   0,   GSM
                   1,   GSM Compact
                   2,   UTRAN
                   3,   GSM w/EGPRS
                   4,   UTRAN w/HSDPA
                   5,   UTRAN w/HSUPA
                   6,   UTRAN w/HSDPA and HSUPA
* RETURNS
*     kal_uint8* post_string
*****************************************************************************/
const kal_uint8* custom_get_gprs_dialup_connect_post_string(kal_uint8 act)
{
    /* Note: The return string length must be less than 64!!! */
#ifdef __TC01__
    #if defined(__HSDPA_SUPPORT__)
/* under construction !*/
	#elif defined(__EGPRS_MODE__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#elif defined(__PS_DIALUP_CONNECT_STRING_BY_ACT__)
    static kal_uint8 temp_string[64];
    const kal_uint8* post_string = temp_string;    
    if ((act == 0) || (act == 1) || (act == 3))
    {
        strcpy(temp_string, " 236800");
    }
    else
    {
        strcpy(temp_string, " 7200000");
    }    
#else
  //Note: user MUST prepare a space before the speed number
  #if defined(__HSDPA_SUPPORT__) && defined(__UMTS_FDD_MODE__)
	static const kal_uint8 post_string[] = " 7200000"; //7.2Mbps
  #elif defined(__HSDPA_SUPPORT__) && defined(__UMTS_TDD128_MODE__)
  	static const kal_uint8 post_string[] = " 2624000"; //2.6Mbps
  #elif defined(__UMTS_FDD_MODE__) || defined(__UMTS_TDD128_MODE__)
    static const kal_uint8 post_string[] =  " 384000"; //384kbps
  #elif defined(__EGPRS_MODE__)
    static const kal_uint8 post_string[] =  " 473600"; //473.6kbps
  #else
    static const kal_uint8 post_string[] =   " 80000"; //80kbps  
  #endif
#endif
    return (const kal_uint8*) post_string;
} // MAUI_02386357, mtk02285, MAUI_02825172
#endif /* __MOD_TCM__ */

/*****************************************************************************
* FUNCTION
*  	custom_is_edit_mode_command()
* DESCRIPTION
*   This function is used to let customer judge if the input command is needed to enter 
* editor mode or not. If true, we will output "> " and wait for 
*       ctrl+z character to execute the whole command string
*       ESC character to cancel the command
*    
* PARAMETERS
*   	data    [IN]    input command string header, maximum length : 10
* RETURNS
*     KAL_TRUE or KAL_FALSE
*****************************************************************************/
kal_bool custom_is_edit_mode_command(kal_uint8 *data)
{
    /*if (strncmp(data, "AT%EDIT", 7) == 0)
        return KAL_TRUE;
    else*/
        return KAL_FALSE;
}

#if defined(__PLMN_LIST_WITH_CELL_INFO__)
kal_uint32 custom_at_posi_get_ndssign(kal_char *buffer, kal_uint32 buf_len, kal_uint8 plmn_num, l4c_rat_plmn_info_struct *list)
{
    /* buf_len: MAX size of the 'buffer' please do not cruppt
       string_length: Indicates how many bytes writes into 'buffer'
    */
    
   /* Prototype of l4c_rat_plmn_info_struct
            #ifdef __PLMN_LIST_WITH_CELL_INFO__
                #define MAX_NUM_CELL_PER_PLMN  10
            #endif 
            
            #if defined(__PLMN_LIST_WITH_CELL_INFO__)
            typedef struct {
                kal_uint16       arfcn;
                kal_int16        rxlev;
                kal_uint8        bsic;
                kal_uint8        la_code[2];
                kal_uint16       cell_id;
                }l4c_location_cell_info_struct;
            #endif
            
            typedef struct {
               kal_uint8   plmn_id[7];
               kal_uint8   status;
               kal_uint8 rat;
               #if defined(__PLMN_LIST_WITH_CELL_INFO__)
               l4c_location_cell_info_struct cell_list[MAX_NUM_CELL_PER_PLMN];
               #endif
            } l4c_rat_plmn_info_struct;
      */
     /* sample code, judge how many PLMN and cell info in the parameter 'list'
          kal_uint8 i;
          kal_uint8 j;
          kal_uint8 ended;
          kal_uint16 temp_lac;
          kal_uint16 temp_lac_2;
          
          for (i = 0; i < plmn_num; i++)
            {
                for(j = 0; j < MAX_NUM_CELL_PER_PLMN; j++)
                {
                    temp_lac = list[i].cell_list[j].la_code[0];
                    temp_lac = (temp_lac << 8) | (list[i].cell_list[j].la_code[1]);

                    if((temp_lac == 0) && (list[i].cell_list[j].cell_id == 0))
                    {
                        break;
                    }

                    // Judge if this is the last cell info 
                    if((i == (plmn_num - 1)) && (j == (MAX_NUM_CELL_PER_PLMN - 1)))
                    {
                        ended = 1;
                    }
                    else if(i == (plmn_num - 1))
                    {
                        temp_lac_2 = list[i].cell_list[j+1].la_code[0];
                        temp_lac_2 = (temp_lac_2 << 8) | (list[i].cell_list[j+1].la_code[1]);

                        if((temp_lac_2 == 0) && (list[i].cell_list[j+1].cell_id == 0))
                        {
                            ended = 1;
                        }
                    }
                 }
             }
    */
    kal_uint32 string_length = 0;
    
    /* Replace the line after thie comment, calculate NDSSIGN and write into buffer */
    string_length = kal_sprintf(buffer, "\"NDSSIGN\"");

    
    /* It's recommended that do not remove the codes after this line! */
    if(string_length > buf_len)
    {
        /* Add length check, void memory curruption */
        ASSERT(0);
    }
    return string_length;
}

kal_bool custom_process_at_posi()
{
	  // customer code
    return KAL_FALSE;
}
#endif
