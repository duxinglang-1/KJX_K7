
#if !defined(KJX_SMS_TOUR_H)
#define KJX_SMS_TOUR_H

#if defined(CUSTOMER_NAME_TOUR)

#include 	"kjx_include.h"
#include	"kjx_main_tour.h"

#include	"SSCStringTable.h"
#include	"FontRes.h"
#include	"FontDcl.h"
#include	"mmi_rp_srv_general_setting_def.h"
#include	"mmi_frm_nvram_gprot.h"

#define ABS(x) ((x) > 0 ? (x) : -(x))

#define SMS_TOUR_DEBUG

extern sLanguageDetails gLanguageArray[MAX_LANGUAGES];
extern U16 gCurrLangIndex;
extern U8 kjxImei[SRV_MAX_IMSI_LEN];

float kjxsettime = 0;

extern kjx_tour_struct g_kjx_tour_struct;
extern kjxNetInfo g_kjxNetInfo;

U8 monitor_out_state = 0;
kal_bool unknown_call = MMI_TRUE;

typedef enum
{
	SL_CMD_CODE_SOS,
	SL_CMD_CODE_PSW,
	SL_CMD_CODE_MONITOR,
	SL_CMD_CODE_LOCATION,
	SL_CMD_CODE_COORDINATE,
	SL_CMD_CODE_VER,
	SL_CMD_CODE_IMEI,
	SL_CMD_CODE_FACTORY,
	SL_CMD_CODE_LANGUAGE,
	SL_CMD_CODE_SOS_STRING,
	SL_CMD_CODE_URL,
	SL_CMD_CODE_RESTART,
	SL_CMD_CODE_MOVE,
	SL_CMD_CODE_ADMIN,
	SL_CMD_CODE_TIMEZONE,
	SL_CMD_CODE_WRITE_IMEI,
	SL_CMD_CODE_DOMAIN,
	SL_CMD_CODE_APN,
	
	SL_CMD_CODE_MAX
}cmdcode;

typedef enum
{
	SET_SOS_SUC,
	SET_SOS_NUMBER,
	SET_MONITOR_SUC,
	SET_LANGUAGE_SUC,
	SET_TZONE_SUC,
	SET_TZONE_FAIL,
	SET_SOS_STRING_SUC,
	SET_MOVE_SUC,
	SET_FACTORY,
	SET_IMEI_SUC,
	SET_PSW_SUC,
	SET_WRITE_IMEI_SUC,
	SET_DOMAIN,
	SET_APN,
	SET_ERROR
}set_cmd;



typedef struct _cmd_tbl
{
	char cmdCode;
	char cmdString[20];
}cmd_tbl;

typedef struct _set_info
{
	char cmdCode;
	unsigned short cmdString[20];
}set_info;


cmd_tbl g_sl_cmd_tb[]=
{
	{SL_CMD_CODE_SOS, ",SOS,\0"},		/* */
	{SL_CMD_CODE_PSW, ",PSW,\0"},		/* */
	{SL_CMD_CODE_MONITOR, "SL,MONITOR,\0"},		/* */
	{SL_CMD_CODE_LOCATION, "SL,LOCATION#\0"},		/* */
	{SL_CMD_CODE_COORDINATE, "SL,COORDINATE#\0"},		/* */
	{SL_CMD_CODE_VER, "SL,VERNO#\0"},		/* */
	{SL_CMD_CODE_IMEI, "SL,IMEI#\0"},		/* */
	{SL_CMD_CODE_FACTORY, "SL,FACTORY#\0"},		/* */
	{SL_CMD_CODE_LANGUAGE, "SL,LANGUAGE,\0"},		/* */
	{SL_CMD_CODE_SOS_STRING, "SL,STRING,\0"},		/* */
	{SL_CMD_CODE_URL, "SL,URL#\0"},		/* */
	{SL_CMD_CODE_RESTART, "SL,RESTART#\0"},		/* */
	{SL_CMD_CODE_MOVE, "SL,MOVE,\0"},		/* */
	{SL_CMD_CODE_ADMIN, ",FACTORY,0086#\0"},		/* */
	{SL_CMD_CODE_TIMEZONE, "SL,TIMEZONE,\0"},		/* */
	{SL_CMD_CODE_WRITE_IMEI,"SL,WRITEIMEI,\0"},
	{SL_CMD_CODE_DOMAIN,"SL,DOMAIN,\0"},
	{SL_CMD_CODE_APN,"SL,APN,\0"},
	
	{SL_CMD_CODE_MAX, "err\0"},			      /* ´íÎó´úÂë */
};

set_info set_cb_info[]=
{
	{SET_SOS_SUC,{0x0053,0x004F,0x0053,0x53F7,0x7801,0x8BBE,0x7F6E,0x6210,0x529F,0xFF01,0x0000}},
	{SET_SOS_NUMBER,{0x5F00,0x542F,0x9632,0x76D7,0x62A5,0x8B66,0x4E4B,0x524D,0xFF0C,0x8BF7,0x8BBE,0x7F6E,0x0053,0x004F,0x0053,0x53F7,0x7801,0xFF01,0x0000}},
	{SET_MONITOR_SUC,{0x8BBE,0x5907,0x76D1,0x542C,0x72B6,0x6001,0x8BBE,0x7F6E,0x6210,0x529F,0xFF01,0x0000}},
	{SET_LANGUAGE_SUC,{0x4FEE,0x6539,0x8BBE,0x5907,0x8BED,0x8A00,0x6210,0x529F,0xFF01,0x0000}},
	{SET_TZONE_SUC,{0x65F6,0x533A,0x8BBE,0x7F6E,0x6210,0x529F,0xFF01,0x0000}},
	{SET_TZONE_FAIL,{0x8BF7,0x641C,0x5230,0x0047,0x0050,0x0053,0x4FE1,0x53F7,0x540E,0x518D,0x8BBE,0x7F6E,0x65F6,0x533A,0xFF01,0x0000}},
	{SET_SOS_STRING_SUC,{0x8BBE,0x7F6E,0x62A5,0x8B66,0x77ED,0x4FE1,0x5185,0x5BB9,0x6210,0x529F,0xFF01,0x0000}},
	{SET_MOVE_SUC,{0x7535,0x5B50,0x56F4,0x680F,0x8BBE,0x7F6E,0x6210,0x529F,0xFF01,0x0000}},
	{SET_FACTORY,{0x6062,0x590D,0x51FA,0x5382,0x8BBE,0x7F6E,0x6210,0x529F,0xFF01,0x0000}},
	{SET_IMEI_SUC,{0x0049,0x004D,0x0045,0x0049,0x003A,0x0000}},
	{SET_PSW_SUC,{0x8BBE,0x5907,0x5BC6,0x7801,0x4FEE,0x6539,0x6210,0x529F,0xFF01,0x0000}},
	{SET_WRITE_IMEI_SUC,{0x0049,0x004D,0x0045,0x0049,0x5199,0x5165,0x6210,0x529F,0xFF01,0x0000}},
	{SET_DOMAIN,{0x4FEE,0x6539,0x57DF,0x540D,0x6210,0x529F,0xFF01,0x0000}},
	{SET_APN,{0x0041,0x0050,0x004E,0x8BBE,0x7F6E,0x6210,0x529F,0x0000}},
	
	{SET_ERROR, {0x0000}},
};

//extern
extern void kjx_sms_send_sms(char* pAsciiDstNumber, unsigned short * pSMSContent, smsal_dcs_enum contentDcs, PsFuncPtr callback);
extern kal_bool kjx_check_number_different(char* src_num,char* dst_num);
extern void kjx_tour_send_call_area_alarm(void);
extern void kjx_tour_send_sms_out_area_alarm(void);
extern void kjx_tour_send_sms_in_area_alarm(void);
#endif
#endif
