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
 *   w32_winmain.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main function of PC simulator
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdafx.h "
#include "resource.h "
#include <stdio.h>
#include <shlobj.h>
#include <process.h>
#include "lcd_sw_inc.h"
#include "kal_release.h"
#include "kal_internal_api.h"
#include "kal_debug.h"
#include "w32_dspl.h"
#include <windows.h> 
#include <conio.h>    
#include "stack_ltlcom.h"
#include "syscomp_config.h"     /* SEND_ILM */
#include "task_config.h"
#include "mmi_msg_struct.h"

#if defined(__COSMOS_MMI_PACKAGE__) || defined( __PLUTO_MMI_PACKAGE__)
#include "GlobalConstants.h"
#endif

#ifdef __P2P_SUPPORT__
#include "p2p_main.h"
#endif

extern void fatal_error_handler( kal_uint8 *err_msg_ptr, kal_int32 err_code, kal_int32 os_err_code);
extern unsigned int g_osc_system_initialized; 

#if defined(EMPTY_MMI) || defined(EXTERNAL_MMI)

int __stdcall  MtkWinMainStart(void *argv)
{
	char				ui_wd[256];
	char				os_wd[256];
	HANDLE mutex_handle;
    HINSTANCE hInstance = GetModuleHandle(NULL);

	//Avoid run multi-instance MoDIS
	mutex_handle = CreateMutex(NULL, 0, _T("MTK_Simulator"));
	if(ERROR_ALREADY_EXISTS == GetLastError() && mutex_handle!=NULL )
	{
		if( !SetConsoleTitle("MediaTek Console(Multi-instance of MoDIS is not supported)") )
			kal_print("SetConsoleTitle failed (%d)\n", GetLastError());
		kal_print("Warnning... Another instance of this MoDIS.exe has already been opened!\n");
		CloseHandle( mutex_handle ) ;
		return 0 ;
	}

	/* get the working directory for UI */
	GetCurrentDirectory(256, ui_wd);

	/* Register display handler */
	kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

	/* Register stack fatal error handler */
	kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);
	
    kal_print("System > Initializing system memory...\n");
	kal_initialize_mem();
   
	/* Initializing the Buffer Pool Information */	
	stack_init_buff_pool_info();
   
	/* Create buffer pools */
	kal_print("System > Creating buffer pool...\n");
	stack_resources_init();   

	/* Initialize KAL resources */
	kal_print("System > Initializing KAL resource...\n");
	kal_initialize();	
	
    mainp();

    g_osc_system_initialized = 1;

    kal_print("System > System initialization done!\n");

    // power on
    w32_key_detect_ind(1, 24);

	return 1;
}

void w32_WaitAnotherMoDISClose(void) {}
void w32_CloseAndCreateMoDIS(void) {}
int w32_GetMoDisUICaption(LPTSTR lpString, int nMaxCount)
{
	if(NULL != lpString && nMaxCount > 0)
	{
		_tcscpy_s(lpString, nMaxCount, _T("MTK_Simulator"));
		return 1;
	}
	else
		return -1;
}

#else

//////////////////////////////////////////////////////////////////
// Resource defination
//////////////////////////////////////////////////////////////////
#define NVRAM_FILENAME "..\\..\\fs\\flash_device.img"
#define BACKUP_NVRAM_FILENAME "..\\..\\fs\\flash_device.bak"
#define NVRAM_SIZE (16*1024*1024)
//////////////////////////////////////////////////////////////////
// Global variable
//////////////////////////////////////////////////////////////////
#define MAX_LOADSTRING 100

HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];	
static HWND mhwnd;
static long timer_count = 0;

#define WIN_START_POSX   0
#define WIN_START_POSY   0
static char szCnfgPath[MAX_PATH];
static char currentPath[MAX_PATH];
char skin_size[20];
HANDLE mutex_handle ;
// The title bar text
// Foward declarations of functions included in this code module:
ATOM                w32_RegisterClass(HINSTANCE hInstance);
BOOL                w32_InitInstance(HINSTANCE, int);
BOOL                AUTO_POWER=FALSE;
BOOL                AUTO_TEST=FALSE;

BOOL				bIsPowerOn = FALSE;
BOOL				bIsInPowerOff = FALSE;

BOOL                g_DisableTouchScreenCalibration = FALSE;
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
extern BYTE *pResizeData;
extern T_W32_SCREEN_DEVICE				device;
extern BOOL g_bLockPaint;
extern unsigned __stdcall TTYInit(void *i1);

extern BOOL g_bSlider /*= TRUE*/;

extern void	w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern void	w32_charger_inout(void);
extern void	w32_incoming_call(void);
extern void	w32_screen_init(HWND hWnd, HINSTANCE hInstance);
extern void	mouse_lbutton_down(HWND, int, int, int, int);
extern void	mouse_lbutton_up(HWND,int ,int, int);
extern void	w32_keydown_by_shortcut(HWND, int);
extern void w32_keyup_by_shortcut(HWND, unsigned int);
extern void	mouse_move(HWND, int, int, int, int);
extern void	w32_draw_main_bitmap(HDC);
extern void w32_vibrate_by_move(kal_uint8);
extern void	w32_update_screen(void);
extern void	w32_TASK_Initialization(void);
extern void	w32_ResetKeyMemory(void);
extern const char *w32_GetProfileName();
extern void	w32_ReadKeyProfile(char path[], HWND hwnd);
extern void	w32_dspl_init(void);
extern int w32_push_input_into_editor_component(char *szItemInput, int szItemInputLen);
//extern void CALLBACK RTC_TCintr(HWND hwnd,UINT uMsg,UINT idEvent, DWORD dwTime); 
//extern void RTC_TCintr(void); 
extern void QueryUARTStatus(void);
extern void w32_send_multi_sms(void);
extern void w32_post_data(void);
extern void w32_set_channel(void);
extern void w32_send_single_sms(void);
extern void w32_send_multi_sms(void);
extern void w32_send_single_binary_sms(void);
extern kal_bool stack_resources_init(void);
extern void stack_init_buff_pool_info(void);
extern void w32_gsm_timealarm(void);
extern void w32_download(void);
extern int mainp(void);

extern void w32_lcd_protection_init();
extern void w32_lcd_protection_deinit();
extern void w32_Audio_OnTimer();
extern void w32_Video_OnTimer();

#ifdef PLUTO_MMI
//extern mmi_bootup_is_searching_or_idle_reached(void);//kal_bool mmi_bootup_is_idle_screen_reached(void);
//extern mmi_shutdown_is_in_power_off_period(void);
extern void (*w32_mmi_mte_api(int api_index))(void);
extern void (*mmi_res_otf_update(int param))(void);
#elif defined(NEPTUNE_MMI)
extern mmi_bootup_is_searching_or_idle_reached(void);//kal_bool mmi_bootup_is_idle_screen_reached(void);
//extern mmi_shutdown_is_in_power_off_period(void);
void (*w32_mmi_mte_api(int api_index))(void);
void (*w32_mmi_mte_api(int api_index))(void){return NULL;}
void (*mmi_res_otf_update(int param))(void);
void (*mmi_res_otf_update(int param))(void){return NULL;}
#else
void (*w32_mmi_mte_api(int api_index))(void);
void (*w32_mmi_mte_api(int api_index))(void){return NULL;}
void (*mmi_res_otf_update(int param))(void);
void (*mmi_res_otf_update(int param))(void){return NULL;}
#endif

int __stdcall  MtkWinMainStart ( void * argv);



extern __declspec(dllimport)
void modislog(BOOL poweron);
extern __declspec(dllimport)
void MoDisUIDllStart(
	void (*w32_key_detect_ind_callback)(unsigned char, unsigned char),
	void (*w32_screen_init_callback)(HWND, HINSTANCE),
	void (*w32_keydown_by_mouse_callback)(HWND, int, int,int,int),
	void (*w32_keyup_by_mouse_callback)(HWND,int, int, int),
	void (*w32_keydown_by_shortcut_callback)(HWND, int),
	void (*w32_keyup_by_shortcut_callback)(HWND, unsigned int),
	void (*w32_mouse_move_enable_callback)(HWND, int, int, int, int),
	int	 (*w32_push_input_into_editor_component)(char *, int),
	void (*w32_draw_main_bitmap_callback)(HDC),
	void (*w32_update_screen_callback)(void),
	void (*w32_TASK_Initialization_callback)(void),
	void (*w32_ReadKeyProfile_callback)(char [], HWND hwnd),
	void (*w32_ResetKeyMemory_callback)(void),
	void (*w32_dspl_init_callback)(void),
	void (*w32_timer_callback)(int),
	BOOL (*w32_msg_pretranslate_callback)(MSG*),
	void (*w32_vibrate_by_move_callback)(kal_uint8),
	char* (*w32_exec_func_callback)(unsigned int), //1,implies get version,2 implies set idle screen
	void  (*(*w32_mmi_mte_api)(int))(void),
	void  (*mmi_res_otf_update)(int),
	void (*w32_osc_activate_isr)(int)
);
extern __declspec(dllimport)
void MoDisUIDllClose(void);
extern __declspec(dllimport)
void MoDISTargetIsGoingToClose(void);
extern __declspec(dllimport)
void MoDisUISetCaption(LPTSTR lpString);

////////////////////////////////////////////////////////////////////
/// function declaration
////////////////////////////////////////////////////////////////////
static int w32_SaveWinPos(void);
static int w32_ReadWinPos(POINT* pPt);
static void process_command(HWND hwnd,WORD command);

extern void w32_copy_java_file(void);
//extern void w32_timer_init(void);
extern void w32_screen_init(HWND hWnd,HINSTANCE hInstance);

extern BOOL w32_touch_screen_button_down(int,int);
extern BOOL w32_touch_screen_button_move(int,int);
extern BOOL w32_touch_screen_button_up(int,int);
static char version[1024];
static void w32_CopyNvram(const char *src_filename,const char *dest_filename);
void w32_CloseAndCreateMoDIS(void);
void w32_WaitAnotherMoDISClose(void);
extern __declspec(dllimport)
void CloseAndCreateMoDIS(void);

extern int w32_IsMemoryCardSupported();
extern void w32_PlugInMemoryCard(void);
extern void w32_PlugOutMemoryCard(void);


/////////////////////////////////////////////////////////////////////
void w32_WaitAnotherMoDISClose(void)
{
	HWND hInstance1 =	FindWindow( NULL,"MTK Simulator" );
	char path[1024],boot[20],tempbuf[1024];
	char *name;
	memset(tempbuf, 0, sizeof(tempbuf));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return ;
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);
	GetPrivateProfileString("AutoTest", "MoDIS", "DEFAULT", boot, sizeof(boot), path);
	if(boot[0]=='R')//mean "Reboot"
	{
	if(hInstance1!=NULL)
	{
	   while(hInstance1!=NULL)
       {  
		   Sleep(1000);	
		   hInstance1 =	FindWindow( NULL,"MTK Simulator" );
	   }
	}
	}
}
void w32_CloseAndCreateMoDIS(void)
{
	CloseAndCreateMoDIS();
}
BOOL w32_msg_pretranslate_callback(MSG *pMsg)
{
    /* return TRUE means u want to intercept this message */

    return FALSE;
}


void w32_pc_simulator_init(void)
{
	GetCurrentDirectory(sizeof(currentPath), currentPath);
	if(stricmp(currentPath+ strlen(currentPath)-strlen("debug"),"debug")!=0)
	{
		strcat(currentPath,"\\debug");
		SetCurrentDirectory(currentPath);
	}
}

void w32_modis_poweron_log(BOOL powerok)
{
	modislog(powerok);
}


void w32_TASK_Initialization(void)
{
   //t9_support_menuitem();
   //w32_timer_init();
}

extern void InitializeResourceVariables(void);

// Called by MoDIS_UI DLL per 100 ms
void w32_timer_callback(int id)
{
    QueryUARTStatus();
    w32_Audio_OnTimer();
    w32_Video_OnTimer();
}

extern HBITMAP get_mainlcd_hbitmap(void);

extern char* release_verno();
extern char* release_hw_ver();
extern void mmi_netset_inject_network_attachment();

void slider_switch_set_gpio(BOOL bOn)
{
	/*Send message to GPIO*/
	ilm_struct *ilm_ptr = NULL;
	mmi_eq_gpio_detect_ind_struct* pMmiEqGpioDetectInd = NULL;

	pMmiEqGpioDetectInd = 
		(mmi_eq_gpio_detect_ind_struct *)construct_local_para(sizeof(mmi_eq_gpio_detect_ind_struct), TD_CTRL);
	if(bOn)
		pMmiEqGpioDetectInd->gpio_device = EXT_DEV_CLAM_OPEN;
	else
		pMmiEqGpioDetectInd->gpio_device = EXT_DEV_CLAM_CLOSE;

	ilm_ptr = allocate_ilm(MOD_DRVKBD);
	ilm_ptr->dest_mod_id = MOD_MMI;
	ilm_ptr->msg_id = MSG_ID_MMI_EQ_GPIO_DETECT_IND;
	ilm_ptr->local_para_ptr = (local_para_struct *) pMmiEqGpioDetectInd;
	ilm_ptr->peer_buff_ptr = NULL;
	SEND_ILM( MOD_DRVKBD, MOD_MMI, DRIVER_PS_SAP, ilm_ptr);
}

typedef enum {
    NULL_CB = 0,
    GET_MODIS_MAUI_VERSION,
    SET_IDLE_SCREEN,
    SET_AUTO_POWER_TRUE,
    GET_MMI_VERSION,
    COPY_MAIN_LCD_SCREEN,
    GET_MMI_SKIN_SIZE,
    CREATE_LCD_BUFFER,
    IF_MODIS_BOOT_IDLE,
    DISABLE_TOUCH_SCREEN_CALIBRATION,
    GET_PROFILE_NAME,
    IS_MEMORY_CARD_SUPPORTED,
    PLUG_IN_MEMORY_CARD,
    PLUG_OUT_MEMORY_CARD,
    GET_MAUI_VERSION_FOR_SLT,
    MTE_ENABLED_BY_COMPILER_OPT,
	MTE_WARNING_ENABLED_BY_COMPILER_OPT,
	IF_MODIS_BOOT_OFF,
	SET_AUTO_TEST_TRUE,
	GET_MAX_SIM_NUM,
	IS_CMCC_FWT
} MODIS_CB_FUNC;

char* w32_exec_func_callback(unsigned int func_num)
{	
	switch(func_num){
		case GET_MODIS_MAUI_VERSION:
		{
			char *swver,*hwver;
			swver = release_verno();
			hwver = release_hw_ver();
			
			//strcat(hwver,swver);
		
			sprintf(version,"%s %s", hwver,swver);
			return version;
		}
        case GET_MAUI_VERSION_FOR_SLT:
        {
#ifdef __MTK_INTERNAL__
/* under construction !*/
#else
            sprintf(version, "%s %s", release_hw_ver(), release_verno());
#endif
            return version;
        }
		case SET_IDLE_SCREEN:
		{
//			mmi_netset_inject_network_attachment();
			return "DUMMY";
		}
		case SET_AUTO_POWER_TRUE:
		{
			AUTO_POWER=TRUE;
			return "DUMMY";
		}
		case SET_AUTO_TEST_TRUE:
		{
			AUTO_TEST=TRUE;
			return "DUMMY";
		}
		case GET_MMI_VERSION:
			{
				#ifdef __COSMOS_MMI__
					return "__COSMOS_MMI__";
				#elif defined PLUTO_MMI
					return "PLUTO_MMI";
				#else
					return "LC_MMI";
				#endif
			}
        case COPY_MAIN_LCD_SCREEN:
        {   /* get main lcd bitmap */
            return (char*)get_mainlcd_hbitmap();        	       
		}
		case GET_MMI_SKIN_SIZE:
		{
			
			sprintf(skin_size, "%dx%d",LCD_WIDTH,LCD_HEIGHT );
			
			return skin_size;
			//return "176x220";
		}
		case CREATE_LCD_BUFFER:
		{
			int loop = 0;
			while(g_bLockPaint)
			{
				if (loop++>20000000)
				{
					break ;
				}
			}
			if(pResizeData!=NULL)
				free(pResizeData);
			pResizeData = (BYTE *) malloc(device.main_lcd_width*device.main_lcd_height*sizeof(BYTE)*4);
			kal_print("device.main_lcd_width*device.main_lcd_height=%d,%d",device.main_lcd_width,device.main_lcd_height);
			return "DUMMY";
		}
		case IF_MODIS_BOOT_IDLE:
		{
			#ifdef PLUTO_MMI
				if(bIsPowerOn)
					return "Y";
				else 
					return "N";
			#elif defined(NEPTUNE_MMI)
				if(bIsPowerOn)
					return "Y";
				else 
					return "N";			
			#else
				return "N";
			#endif
		}
		case IF_MODIS_BOOT_OFF:
		{
			#ifdef PLUTO_MMI
				if(bIsInPowerOff)
					return "Y";
				else 
					return "N";
			#elif defined(NEPTUNE_MMI)
				if(bIsInPowerOff)
					return "Y";
				else 
					return "N";				
			#else
				return "N";
			#endif
		
		}
        case DISABLE_TOUCH_SCREEN_CALIBRATION:
            g_DisableTouchScreenCalibration = TRUE;
			AUTO_TEST = TRUE;
            return "DUMMY";

        case GET_PROFILE_NAME:
            return (char *) w32_GetProfileName();

        case IS_MEMORY_CARD_SUPPORTED:
            return w32_IsMemoryCardSupported() ? "Y" : "N";

        case PLUG_IN_MEMORY_CARD:
            w32_PlugInMemoryCard();
            return "DUMMY";

        case PLUG_OUT_MEMORY_CARD:
            w32_PlugOutMemoryCard();
            return "DUMMY";
        case MTE_ENABLED_BY_COMPILER_OPT:
            #ifdef DISABLE_MODIS_THEME_EDITOR           
                return "N" ;
            #else
                return "Y" ;
            #endif

		case MTE_WARNING_ENABLED_BY_COMPILER_OPT:
			#ifdef __THEME_EDITOR_POPUP_WARNING_ENABLE__
				return "Y";
			#else
				return "N" ;
			#endif
		case GET_MAX_SIM_NUM:
			#if(GEMINI_PLUS == 2)
						return "2";
			#elif(GEMINI_PLUS == 3)
						return "3";
			#elif(GEMINI_PLUS == 4)
						return "4";
			#else
						return "1";
			#endif
		case IS_CMCC_FWT:
			#if(defined(__OP01_FWPBW__))
						return "Y";	
			#else
						return "N";	
			#endif
		default:
			return "DUMMY";
	}
}

BOOL MoDISCtrlHandler( DWORD fdwCtrlType ) 
{ 
	switch( fdwCtrlType ) 
	{ 
		case CTRL_C_EVENT:	// Handle the CTRL-C signal. 
		case CTRL_CLOSE_EVENT:	// CTRL-CLOSE: confirm that the user wants to exit. 
		case CTRL_BREAK_EVENT: 
			exit(0);
	    default: 
			return FALSE; 
	} 
} 

void MoDIS_atexit_HookFunction(void) 
{ 
	MoDisUIDllClose(); 

	CloseHandle( mutex_handle ) ;
	if(NULL != device.main_bitmap)
		DeleteDC(device.main_bitmap);
	if(NULL != device.main_bitmap_down)
		DeleteDC(device.main_bitmap_down);
	
} 


/************************************************************************/
/*    
		Make sure each MoDIS UI has a single title, 
		such as MTK Simulator_1, MTK Simulator_2, ...
/************************************************************************/
UINT g_arrayModisTitleUsedInfo[50];
TCHAR g_tszModisUIDialogCaption[32] = _T("");
TCHAR g_tszModisConsoleCaption[32] = _T("");
typedef struct WndCharacter
{
	char classname[128];
	char wndText[128];
}WNDChara;
BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lParam)
{  
	char buf[128];  
	ZeroMemory(buf, sizeof(buf));
	GetClassName(hwnd, buf, sizeof(buf));   
	if(strcmp(buf,((WNDChara *)lParam)->classname) == 0)
	{
		GetWindowText(hwnd, buf, sizeof(buf)); 
		if(strstr(buf,((WNDChara *)lParam)->wndText))
		{
			char* pos = strstr(buf, "MTK_Simulator");
			if(pos = pos+13)
				g_arrayModisTitleUsedInfo[atoi(++pos)] = TRUE;
			else
				g_arrayModisTitleUsedInfo[1] = TRUE;
			return 1;
		}
	}   
	return 1;  
} 

void DetermineModisUIDialogCaption()
{
	INT uiIndex;
	INT uiArraySize;
	WNDChara wc;

	uiArraySize = sizeof(g_arrayModisTitleUsedInfo) / sizeof(g_arrayModisTitleUsedInfo[0]);
	for(uiIndex = 1; uiIndex < uiArraySize; uiIndex++)
		g_arrayModisTitleUsedInfo[uiIndex] = FALSE;
	
	ZeroMemory(&wc, sizeof(wc));
	//::GetClassNameA(m_hWnd, wc.classname, 128);
	strncpy(wc.classname, "#32770", 6);
	strncpy(wc.wndText, "MTK_Simulator", 13);
	EnumWindows(&EnumWindowsProc, (LPARAM)&wc);
	for(uiIndex = 1; uiIndex < uiArraySize; uiIndex++)
	{
		if(FALSE == g_arrayModisTitleUsedInfo[uiIndex])
		{
			_stprintf(g_tszModisUIDialogCaption, _T("MTK_Simulator_%d"), uiIndex);
			_stprintf(g_tszModisConsoleCaption, _T("MediaTek_Console_%d"), uiIndex);
			MoDisUISetCaption(g_tszModisUIDialogCaption);
			SetConsoleTitle(g_tszModisConsoleCaption);
			return;
		}
	}
}

void OnBeforeUIStarted()
{
	/*Do some actions before UI started*/
	BOOL bResult = TRUE;
	
	/*Support screen rotate or not*/
	#ifdef __MMI_SCREEN_ROTATE__
		bResult = WritePrivateProfileString(SEC_INTEGRATE, KEY_MMI_SCREEN_ROTATE_SUPPORT, VAL_MMI_SCREEN_ROTATE_TRUE, PATH_MODIS_INI);
	#else
		bResult = WritePrivateProfileString(SEC_INTEGRATE, KEY_MMI_SCREEN_ROTATE_SUPPORT, VAL_MMI_SCREEN_ROTATE_FALSE, PATH_MODIS_INI);
	#endif
	if(!bResult)
		kal_print("Error: Set mmi screen rotate flag into modis.ini failed!\n");
	
}

int __stdcall  MtkWinMainStart ( void * argv)
{
	char	 ui_wd[256];
	char	 os_wd[256];
	int i ;
	TCHAR tszModulePath[MAX_PATH];

    /*
	Create Mutex for preventing user open multi-MoDIS instance of one and the same execution file:
		1. We use the current module's name as the mutex name, in order to avoid run multi-Modis of one and the same modis.exe
		2. Because "\" is not supported in mutex name, so we replace it with "/"
		*/
	GetModuleFileName(NULL, tszModulePath, MAX_PATH);	
	for(i = _tcslen(tszModulePath) - 1; i > 0; i--)
	{
		if(tszModulePath[i] == '\\' )
			tszModulePath[i] = '/' ;
	}
    mutex_handle = CreateMutex(NULL, 0, tszModulePath);
    if(ERROR_ALREADY_EXISTS == GetLastError() && mutex_handle!=NULL )
    {
		if( !SetConsoleTitle("MediaTek Console(Multi-instance of one and the same MoDIS is not supported)") )
			kal_print("SetConsoleTitle failed (%d)\n", GetLastError());

        kal_print("Warnning... Another instance of this MoDIS.exe has already been opened!\n");
		kal_print("(You can copy this MoDIS to another place to support multi-MoDIS running!)\n");
		CloseHandle( mutex_handle ) ;
        return 0 ;
    }

	/*Determine the name of UI Dialog to be opened*/
	DetermineModisUIDialogCaption();

	atexit(MoDIS_atexit_HookFunction);     

	if( !SetConsoleCtrlHandler( (PHANDLER_ROUTINE) MoDISCtrlHandler, TRUE ) ) 
		printf( "ERROR: Could not set control handler!\n");

	/* get the working directory for UI */
	GetModuleFileNameA(NULL, ui_wd, 256);
	for( i = strlen(ui_wd) - 1 ; i > 0  ; i-- )
	{
		if( ui_wd[ i ] == '\\' )
		{
			ui_wd[ i ] = '\0' ;
			break;
		}
	}

	/* Register display handler */
	kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

	/* Register stack fatal error handler */
	kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);
	
    kal_print("System > Initializing system memory...\n");
	kal_initialize_mem();
   
	/* Initializing the Buffer Pool Information */	
	stack_init_buff_pool_info();
   
	/* Create buffer pools */
	kal_print("System > Creating buffer pool...\n");
	stack_resources_init();   

	/* Initialize KAL resources */
	kal_print("System > Initializing KAL resource...\n");
	kal_initialize();	
	
	InitializeResourceVariables();

    mainp();

    g_osc_system_initialized = 1;

    kal_print("System > System initialization done!\n");
 
	/* get the working directory for OS */
	GetCurrentDirectory(256, os_wd);
	
	/* set the working directory to what UI needs */
	SetCurrentDirectory(ui_wd);

    w32_lcd_protection_init();

	OnBeforeUIStarted();

#ifdef __P2P_SUPPORT__
    printf("P2P initialization starting...\n");

    /* start MoDis UI */
    MoDisUIDllStart(
        w32_key_detect_ind,
        w32_screen_init,
        mouse_lbutton_down,
        mouse_lbutton_up, 
        w32_keydown_by_shortcut,
        w32_keyup_by_shortcut,
        mouse_move,
        w32_push_input_into_editor_component,
        w32_draw_main_bitmap,
        w32_update_screen,
        /* Eric Hsieh: Replace the task initialization procedure. */
        p2p_TASK_Initialization,
        w32_ReadKeyProfile,
        w32_ResetKeyMemory,
        w32_dspl_init,
        w32_timer_callback,
        /* Eric Hsieh: Replace the msg callback function handler. */
        p2p_msg_pretranslate_callback,
        w32_vibrate_by_move,
        w32_exec_func_callback,
        w32_mmi_mte_api, // GLORY
		mmi_res_otf_update
    );

    printf("P2P initialization done...\n");
#else

	/* start MoDis UI */
	MoDisUIDllStart(
		w32_key_detect_ind,
		w32_screen_init,
		mouse_lbutton_down,
		mouse_lbutton_up, 
		w32_keydown_by_shortcut,
		w32_keyup_by_shortcut,
		mouse_move,
		w32_push_input_into_editor_component,
		w32_draw_main_bitmap,
		w32_update_screen,
		w32_TASK_Initialization,
		w32_ReadKeyProfile,
		w32_ResetKeyMemory,
		w32_dspl_init,
		w32_timer_callback,
		w32_msg_pretranslate_callback,
		w32_vibrate_by_move,
		w32_exec_func_callback,
        w32_mmi_mte_api, // GLORY
		mmi_res_otf_update,
		OSC_Activate_ISR
	);
#endif
    //w32_AV_Uninitialize();
    w32_lcd_protection_deinit();

	/* restore to the working directory that OS needs */
	SetCurrentDirectory(os_wd);
	
	return 1;
}

ATOM w32_RegisterClass
(
 HINSTANCE hInstance
 )
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_L_MTK);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_MTK_SIMULATOR;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_S_MTK);

	return RegisterClassEx(&wcex);
}


BOOL w32_InitInstance
(
 HINSTANCE hInstance, 
 int nCmdShow
 )
{
   HWND hWnd;

   POINT xyWinPos;
   int   simulator_w,simulator_h;

   hInst = hInstance; // Store instance handle in our global variable

   memset( &xyWinPos, 0x0, sizeof(xyWinPos) );
   memset( szCnfgPath, 0x0, sizeof(szCnfgPath) );
   GetCurrentDirectory(sizeof(szCnfgPath), szCnfgPath);
   sprintf(szCnfgPath, "%s%s", szCnfgPath, "\\mtk.cfg");

   if ( !w32_ReadWinPos(&xyWinPos) )
   {
       /* fault: read positon from config file  */
       xyWinPos.x= WIN_START_POSX;
       xyWinPos.y= WIN_START_POSY;
   }
   simulator_w = 10+(LCD_WIDTH> 154 ? LCD_WIDTH: 154);
   simulator_h = 50+(LCD_HEIGHT + 10 + 261);
   #ifdef DUAL_LCD
   simulator_h += SUBLCD_HEIGHT;
   #endif

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      xyWinPos.x, xyWinPos.y, simulator_w, simulator_h, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   mhwnd=hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	static HBITMAP main_bmp,key_bmp ;
	static int     cxClient, cyClient, cxSource, cySource,xPos,yPos;
	static HINSTANCE      hInstance ;
	static RECT device_lcd;
			  
	void *i1=NULL;
	extern void QueryUARTStatus();
	
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	switch (message) 
	{
	case WM_CREATE:
		OleInitialize(NULL);
	        hInstance = ((LPCREATESTRUCT) lParam)->hInstance ;
		w32_screen_init(hWnd,hInstance);
		
        return 0 ;

	case WM_LBUTTONDOWN:
			
		/*
			if (!w32_touch_screen_button_down(1,1))
			{
				 xPos = LOWORD(lParam);  // horizontal position of cursor 
				 yPos = HIWORD(lParam);  // vertical position of cursor
				 w32_keydown_by_mouse(hWnd,xPos,yPos);	
			 }*/
			
			 return 0;
	case WM_LBUTTONUP:
			
		/*	
		if (!w32_touch_screen_button_up())
			{
				 w32_keyup_by_mouse(hWnd);
			}
*/
			 return 0;

	case WM_KEYDOWN:	 

			w32_keydown_by_shortcut(hWnd,(int)wParam);	

			return 0;
	case WM_KEYUP:

//			w32_keyup_by_mouse(hWnd);

			return 0;
	case WM_MOUSEMOVE:
/*
			if (!w32_touch_screen_button_move())
			{
				 xPos = LOWORD(lParam);  // horizontal position of cursor 
				 yPos = HIWORD(lParam);  // vertical position of cursor
				 w32_mouse_move_enable(hWnd,xPos,yPos);	
			}*/

         return 1;
	case WM_TIMER:
	     if(wParam == 101)
	        QueryUARTStatus();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		w32_draw_main_bitmap(hdc); 
	        w32_update_screen();
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
	         w32_SaveWinPos(); /* _wwf_901008_add for storing simulator position */
       	  PostQuitMessage(0);
			break;
	case WM_COMMAND:

		process_command(hWnd,LOWORD(wParam));
		break;
	default:

		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
static void process_command(HWND hwnd,WORD command) 
{
	switch(command)
	{
	case ID_GSM_TIMEALARM:
		w32_gsm_timealarm();
		break;
	case IDM_WIN_POS_STORE:
		w32_SaveWinPos();
		break;
	case ID_BACKUP_NVRAM:
		w32_CopyNvram(NVRAM_FILENAME,BACKUP_NVRAM_FILENAME);
		break;
	case ID_RESTORE_NVRAM:
		w32_CopyNvram(BACKUP_NVRAM_FILENAME,NVRAM_FILENAME);
		break;
	case ID_CHARGER_IN:
		w32_charger_inout();
		break;
	case ID_DOWNLOAD:
		w32_download();
		break;
	case ID_GSM_INCOMINGCALLRING:
		w32_incoming_call();
		break;
	case ID_POST_DATA:
		w32_post_data();
		break;
	case ID_SET_CHANNEL:
		w32_set_channel();
		break;
	case ID_SEND_SMS:
		w32_send_single_sms();
		break;
	case ID_SEND_SMS_MULTI:
		w32_send_multi_sms();
		break;
	case ID_JAS_SENDSMS_BINARY:
		w32_send_single_binary_sms();
		break;
	}
}

extern int mmi_get_current_editor_style();
extern int mmi_send_direct_input_req(unsigned short* input, int editor_style);

int w32_push_input_into_editor_component(char *szItemInput, int szItemInputLen)
{
	int		style = 0, ret = 0;
	DWORD	err = 0;
	WCHAR	wszInput[1000]={0};

	/* 1. Check the current screen accept the input */
	style = mmi_get_current_editor_style();
	if (style < 0 || style == 7)
	{
		/* current screen doesn't support input directly */
		return -1;
	}

	/* 2. check if the input is valid  */
	if (ret < 0 || szItemInputLen >= 1000)
	{
		/* input content is invalid or too large */
		return 0;
	}

	/* 3. convert the input to Unicode format */
	ret = MultiByteToWideChar( CP_ACP, 0, szItemInput,
					   		   szItemInputLen, wszInput,   
							   sizeof(wszInput)/sizeof(wszInput[0]) );
	if (ret == 0)
	{
		err = GetLastError();
	}

	/* 4. send the message to ask MMI push the data in UI editor component */
	//#ifdef PLUTO_MMI
		ret = mmi_send_direct_input_req((unsigned short*)wszInput, style);
	//#endif
	return ret;
}


// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

static int w32_ReadWinPos(POINT* pPt)
{
    FILE    *fCnfg;

    if (!pPt) return (int)0;

    fCnfg= fopen( szCnfgPath, "r");
    if (fCnfg)
    {
        fscanf(fCnfg, "%d\n", &pPt->x);
        fscanf(fCnfg, "%d\n", &pPt->y);
        fclose(fCnfg);

        return (int)1; /* return successful*/
    }

    return (int)0; /* return fault */
}

static int w32_SaveWinPos(void)
{
    FILE    *fCnfg;
    RECT    rectWin;

    fCnfg= fopen( szCnfgPath, "w");
    if (fCnfg)
    {
        if (GetWindowRect(mhwnd, &rectWin))
        {
            fprintf(fCnfg, "%d\n", rectWin.left);
            fprintf(fCnfg, "%d\n", rectWin.top);
        }
        fclose(fCnfg);

        return (int)1; /* return successful */
    }

    return 0; /* return fault */
}
static void w32_CopyNvram(const char *src_filename,const char *dest_filename)
{
	int nvram_size=0;
//	int i;

	FILE *src,*dest;

	src = fopen(src_filename,"rb");
	dest = fopen(dest_filename,"w+b");

	if(src && dest)
	{
		char buffer[512];
		while(1)
		{
			int read_size = fread(buffer,1,sizeof(buffer),src);
			if(read_size>0)
				fwrite(buffer,1,read_size,dest);
			else
				break;
		}
		fclose(src);
		fclose(dest);
	}
}

static void  w32_charger_inout(void)
{
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
#endif
}

void w32_target_is_going_to_power_off()
{
	MoDISTargetIsGoingToClose();
}

int w32_GetMoDisUICaption(LPTSTR lpString, int nMaxCount)
{
	if(NULL != lpString && nMaxCount > 0)
	{
		_tcscpy_s(lpString, nMaxCount, g_tszModisUIDialogCaption);
		return 1;
	}
	else
		return -1;
}

void w32_set_mmi_is_idle_reached(kal_bool bIdleReached)
{
	if(bIdleReached)
		bIsPowerOn = TRUE;
	else
		bIsPowerOn = FALSE;

	//MMI power on succeed
	if(w32_modis_is_autotest() || w32_modis_is_autopower()) 
		w32_modis_poweron_log(TRUE);

	return;
}
void w32_set_mmi_is_in_power_off_period(kal_bool bInPowerOff)
{
	if(bInPowerOff)
	{
		bIsInPowerOff = TRUE;
		w32_target_is_going_to_power_off();
	}
	else
		bIsInPowerOff = FALSE;

	return;
}
kal_bool w32_modis_is_autotest()
{	
	if(AUTO_TEST)
		return KAL_TRUE;
	else
		return KAL_FALSE;
}
kal_bool w32_modis_is_autopower()
{
	if(AUTO_POWER)
		return KAL_TRUE;
	else
		return KAL_FALSE;


}
kal_bool w32_modis_is_disable_touchscreencalibration()
{
	if(g_DisableTouchScreenCalibration)
		return KAL_TRUE;
	else
		return KAL_FALSE;

}
#endif // defined(EMPTY_MMI) || defined(EXTERNAL_MMI)

