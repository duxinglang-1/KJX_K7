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
 *   w32_keys.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   keypad dummy functions for WIN32 environment
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>
#include "kal_release.h"
#include "kal_debug.h"
#include "stack_ltlcom.h"
#include "w32_keys.h"

/***************************************************************************** 
* Local Variable
*****************************************************************************/

kbd_buffer_struct_modis kbd_buffer; 

/* already power on or not */
static kal_uint8 is_key_poweron = KAL_FALSE;
#if defined(KBD_TIMER_USE_KAL_SERVICE)
   static kal_timerid timerID; /* Note: sharing among threads ? */
	#define timer_QWERTY_MAX_NUM 5 
	static kal_timerid timerID_QWERTY[timer_QWERTY_MAX_NUM];
	static BOOL timer_QWERTY_available[timer_QWERTY_MAX_NUM];
	static int timer_QWERTY_KeyRecord[timer_QWERTY_MAX_NUM];
#else
#endif

static CRITICAL_SECTION	keyBuf_cs;
static CRITICAL_SECTION	timer_cs;
static BOOL g_bKeyupFlag = FALSE;

static const char *KeyMappingName[MAX_KEY_SUPPORT_NUM] =
{
		"DEVICE_KEY_0",		  
		"DEVICE_KEY_1",		  
		"DEVICE_KEY_2",		  
		"DEVICE_KEY_3",		  
		"DEVICE_KEY_4",		  
		"DEVICE_KEY_5",		  
		"DEVICE_KEY_6",		  
		"DEVICE_KEY_7",		  
		"DEVICE_KEY_8",		  
		"DEVICE_KEY_9",		  
		"DEVICE_KEY_STAR",
		"DEVICE_KEY_HASH",	  
		"DEVICE_KEY_VOL_UP",	  
		"DEVICE_KEY_VOL_DOWN",   
		"DEVICE_KEY_UP",		  
		"DEVICE_KEY_DOWN", 	  
		"DEVICE_KEY_LEFT", 	  
		"DEVICE_KEY_RIGHT",	  
		"DEVICE_KEY_MENU", 	  
		"DEVICE_KEY_FUNCTION",   
		"DEVICE_KEY_SK_LEFT",  
		"DEVICE_KEY_SK_RIGHT",   
		"DEVICE_KEY_SEND", 	  
		"DEVICE_KEY_END",		  
		"DEVICE_KEY_POWER",	  
		"DEVICE_KEY_CLEAR",	  
		"DEVICE_KEY_EXT_FUNC1",  
		"DEVICE_KEY_EXT_FUNC2",  
		"DEVICE_KEY_MP3_PLAY_STOP",
		"DEVICE_KEY_MP3_FWD",	  
		"DEVICE_KEY_MP3_BACK",   
		"DEVICE_KEY_EXT_A",	  
		"DEVICE_KEY_EXT_B",	  
		"DEVICE_KEY_A",		  
		"DEVICE_KEY_B",		  
		"DEVICE_KEY_C",		  
		"DEVICE_KEY_D",		  
		"DEVICE_KEY_E",		  
		"DEVICE_KEY_F",		  
		"DEVICE_KEY_G",		  
		"DEVICE_KEY_H",		  
		"DEVICE_KEY_I",		  
		"DEVICE_KEY_J",		  
		"DEVICE_KEY_K",		  
		"DEVICE_KEY_L",		  
		"DEVICE_KEY_M",		  
		"DEVICE_KEY_N",		  
		"DEVICE_KEY_O",		  
		"DEVICE_KEY_P",		  
		"DEVICE_KEY_Q",		  
		"DEVICE_KEY_R",		  
		"DEVICE_KEY_S",		  
		"DEVICE_KEY_T",		  
		"DEVICE_KEY_U",		  
		"DEVICE_KEY_V",		  
		"DEVICE_KEY_W",		  
		"DEVICE_KEY_X",		  
		"DEVICE_KEY_Y",		  
		"DEVICE_KEY_Z",		  
		"DEVICE_KEY_ENTER",	  
		"DEVICE_KEY_SPACE",	  
		"DEVICE_KEY_TAB",		  
		"DEVICE_KEY_DEL",		  
		"DEVICE_KEY_ALT",		  
		"DEVICE_KEY_CTRL", 	  
		"DEVICE_KEY_WIN",		  
		"DEVICE_KEY_SHIFT",	  
		"DEVICE_KEY_QUESTION",   
		"DEVICE_KEY_PERIOD",	  
		"DEVICE_KEY_COMMA",	  
		"DEVICE_KEY_EXCLAMATION",
		"DEVICE_KEY_APOSTROPHE", 
		"DEVICE_KEY_AT",		  
		"DEVICE_KEY_SEND2",	//73
		
		"DEVICE_KEY_BACKQUOTE",       /* ` */ 
		"DEVICE_KEY_DASH",            /* - */ 
		"DEVICE_KEY_EQUAL",           /* = */ 
		"DEVICE_KEY_BACKSPACE",       /* <-*/
		"DEVICE_KEY_OPEN_PARENS",     /* ( */ 
		"DEVICE_KEY_CLOSE_PARENS",    /* ) */ 
		"DEVICE_KEY_OPEN_SQUARE",     /* [ */ 
		"DEVICE_KEY_CLOSE_SQUARE",    /* ] */ 
		"DEVICE_KEY_OPEN_BRACE",      /* { */ 
		"DEVICE_KEY_CLOSE_BRACE",     /* } */ 
		"DEVICE_KEY_BACKSLASH",       /* \ */ 
		"DEVICE_KEY_SEMICOLON",       /* ; */ 
		"DEVICE_KEY_SLASH",           /* / */ 
		"DEVICE_KEY_DOLLAR",          /* $ */ 
		"DEVICE_KEY_PERCENT",         /* % */ 
		"DEVICE_KEY_CARET",           /* ^ */ 
		"DEVICE_KEY_AND",             /* & */ 
		"DEVICE_KEY_QUOTE",           /* " */ 
		"DEVICE_KEY_PLUS",            /* + */ 
		"DEVICE_KEY_LESS_THAN",       /* < */ 
		"DEVICE_KEY_GREAT_THAN",      /* > */ 
		"DEVICE_KEY_UNDERSCORE",      /* _ */ 
		"DEVICE_KEY_PIPE",            /* | */ 
		"DEVICE_KEY_TILDE",           /* ~ */ 
		"DEVICE_KEY_CAPS_LOCK", 	//98
		"DEVICE_KEY_NUM_LOCK", //99
		"DEVICE_KEY_FN",  //100     
		"DEVICE_KEY_SYMBOL",      
		"DEVICE_KEY_EMAIL",       
		"DEVICE_KEY_MESSAGE",     
		"DEVICE_KEY_CAMERA",      
		"DEVICE_KEY_ESC",   //105 
		"DEVICE_KEY_QWERTY_MENU", //106
		"DEVICE_KEY_OK", //107
		" ", //108
		" ", //109
		" ", //110		
		"DEVICE_KEY_F1",    //111      
		"DEVICE_KEY_F2",          
		"DEVICE_KEY_F3",          
		"DEVICE_KEY_F4",          
		"DEVICE_KEY_F5",          
		"DEVICE_KEY_F6",          
		"DEVICE_KEY_F7",          
		"DEVICE_KEY_F8",          
		"DEVICE_KEY_F9",          
		"DEVICE_KEY_F10",         
		"DEVICE_KEY_F11",         
		"DEVICE_KEY_F12",  
		"DEVICE_KEY_BACK",
		"DEVICE_KEY_HOME",	//124

		"MAX_DEVICE_KEYS", //125
		"DEVICE_KEY_NONE"	
};

//Enable Special + Normal key combination ?
static BOOL gSpecial_Normal_Key_Combination_Enable = TRUE ;
//Change the gSpecial_Normal_Key_Combination_Enable when all keys are up
static BOOL gReady_To_Change_Special_Normal_Key_Combination_Status = FALSE ;
static unsigned char KeyMode = 1 ; //Key mode
static int KeyStatus[ MAX_KEY_SUPPORT_NUM ] ; 
static int KeyPressNum = 0 ;
int gReady_To_Change_Key_Mode = 0 ;

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void kbd_long_detect(void *timer_param);
static void kbd_repeat_detect(void *timer_param);
static void kbd_send_msg_to_uem(msg_type msg_name, unsigned int para, unsigned int para2);

///////////////////////////////////////////////////////////
//Check if all keys are up
static BOOL CheckIfAllKeyStatusAreUp()
{
	/*
	int i ;
	for( i = 0 ; i < MAX_KEY_SUPPORT_NUM ; ++i ) 
	{
		if( KeyStatus[ i ] == DRV_KEY_DOWN )
			return FALSE ;
	}
	return TRUE ;
	*/
	if( KeyPressNum == 0 )
		return TRUE ;
	return FALSE ;
}

///////////////////////////////////////////////////////////
static int HowManyKeysArePressed()
{
	/*
	int i, num ;
	for( i = 0, num = 0 ; i < MAX_KEY_SUPPORT_NUM ; ++i ) 
	{
		if( KeyStatus[ i ] == DRV_KEY_DOWN )
			num++ ;
	}
	return num ;
	*/
	return KeyPressNum ;
}

///////////////////////////////////////////////////////////
static void kbd_QWERTY_repeat_detect(void *timer_param)
{
	unsigned char key_code = (unsigned char)timer_param;
	unsigned char key_status = (unsigned char)KEY_REPEATED;
	int i ;
	for( i = 0 ; i < timer_QWERTY_MAX_NUM ; ++i )
	{
		if( timer_QWERTY_available[ i ] == FALSE &&
			timer_QWERTY_KeyRecord[ i ] == key_code )
		{
			if (TRUE == kbd_write_buffer(key_code, key_status))
			{ 
				kal_printf("SendKey(Repeat): %s(%2d) Down\n", KeyMappingName[key_code], key_code);
				kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);
				kal_cancel_timer(timerID_QWERTY[i]);
				kal_set_timer(timerID_QWERTY[i], 
							  (kal_timer_func_ptr)kbd_QWERTY_repeat_detect, 
							  (void*)key_code, 
							  (kal_uint32)KBD_TIMER_REPEAT_TICKS, 
							  0);				
				return ;
			}
		}
		
	}
}

///////////////////////////////////////////////////////////
static void kbd_QWERTY_longpress_detect(void *timer_param)
{
	unsigned char key_code = (unsigned char)timer_param;
	unsigned char key_status = (unsigned char)KEY_LONGPRESS;	
	int i ;
	for( i = 0 ; i < timer_QWERTY_MAX_NUM ; ++i )
	{
		if( timer_QWERTY_available[ i ] == FALSE &&
			timer_QWERTY_KeyRecord[ i ] == key_code )
		{
			if (TRUE == kbd_write_buffer(key_code, key_status))
			{ 
				kal_printf("SendKey(Long Press): %s(%2d) Down\n", KeyMappingName[key_code], key_code);
				kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);
				kal_cancel_timer(timerID_QWERTY[i]);
				kal_set_timer(timerID_QWERTY[i], 
							  (kal_timer_func_ptr)kbd_QWERTY_repeat_detect, 
							  (void*)key_code, 
							  (kal_uint32)KBD_TIMER_REPEAT_TICKS, 
							  0);				
				return ;
			}
		}
		
	}
}

///////////////////////////////////////////////////////////
static void InitQWERTYTimer()
{
#if defined(KBD_TIMER_USE_KAL_SERVICE)	
	int i ;
	char tmp[50];
	for( i = 0 ; i < timer_QWERTY_MAX_NUM ; ++i )
	{
		sprintf( tmp, "KbdTimer%d", i ) ;
		timerID_QWERTY[ i ] = kal_create_timer(tmp);
		timer_QWERTY_available[ i ] = TRUE ;
		timer_QWERTY_KeyRecord[ i ] = ( MAX_KEY_SUPPORT_NUM + 1 );
	}
#else
#endif		
}

///////////////////////////////////////////////////////////
static void SetQWERTYTimerKeyDown(unsigned char cur_key_code)
{
#if defined(KBD_TIMER_USE_KAL_SERVICE)	
	int i ;
	for( i = 0 ; i < timer_QWERTY_MAX_NUM ; ++i )
	{
		if( timer_QWERTY_available[ i ] == TRUE )
		{	
			kal_cancel_timer(timerID_QWERTY[i]);
			kal_set_timer(timerID_QWERTY[i], 
						  (kal_timer_func_ptr)kbd_QWERTY_longpress_detect, 
						  (void*)cur_key_code, 
						  (kal_uint32)KBD_TIMER_LONGPRESS_TICKS, 
						  0);	
			timer_QWERTY_available[ i ] = FALSE ;
			timer_QWERTY_KeyRecord[ i ] = cur_key_code ;
			return ;
		}
	}
#else
#endif	
}

///////////////////////////////////////////////////////////
static void SetQWERTYTimerKeyUp(unsigned char cur_key_code)
{
#if defined(KBD_TIMER_USE_KAL_SERVICE)
	int i ;
	for( i = 0 ; i < timer_QWERTY_MAX_NUM ; ++i )
	{
		if( timer_QWERTY_available[ i ] == FALSE &&
			timer_QWERTY_KeyRecord[ i ] == cur_key_code )
		{
		  	kal_cancel_timer(timerID_QWERTY[i]);
			timer_QWERTY_available[ i ] = TRUE ;
			timer_QWERTY_KeyRecord[ i ] = ( MAX_KEY_SUPPORT_NUM + 1 );
			return ;
		}
	}	
#else
#endif		
}

static void IncreaseKeyPressNumByOne()
{
	EnterCriticalSection(&keyBuf_cs); 
	KeyPressNum++;	
	LeaveCriticalSection(&keyBuf_cs);
}

static void DecreaseKeyPressNumByOne()
{
	EnterCriticalSection(&keyBuf_cs); 
	assert(KeyPressNum!=0);
	KeyPressNum--;	
	LeaveCriticalSection(&keyBuf_cs);
}

//SendKey for normal (One/Two KeyMode)
static void SendKey(int cur_key_status, unsigned char cur_key_code) 
{
	if( KeyMode == 1 )
	{
		if(cur_key_status == DRV_KEY_UP )
		{
#if defined(KBD_TIMER_USE_KAL_SERVICE)
			EnterCriticalSection(&timer_cs);
			g_bKeyupFlag = TRUE;
			kal_cancel_timer(timerID);
			LeaveCriticalSection(&timer_cs);
#else
#endif
		}
		else if(cur_key_status == DRV_KEY_DOWN) 
		{
#if defined(KBD_TIMER_USE_KAL_SERVICE)
			EnterCriticalSection(&timer_cs);
			g_bKeyupFlag = FALSE;
			kal_cancel_timer(timerID);
			kal_set_timer(timerID, (kal_timer_func_ptr)kbd_long_detect, (void*)cur_key_code, (kal_uint32)KBD_TIMER_LONGPRESS_TICKS, 0);
			LeaveCriticalSection(&timer_cs);
#else
#endif
		}
	}
	else if( KeyMode == 2 )
	{
		if(cur_key_status == DRV_KEY_UP )
			SetQWERTYTimerKeyUp(cur_key_code);
		else
			SetQWERTYTimerKeyDown(cur_key_code);
	}
	
	if (TRUE == kbd_write_buffer(cur_key_code, (unsigned char)cur_key_status))
	{
		if( cur_key_status == DRV_KEY_DOWN)
		{
			IncreaseKeyPressNumByOne();
			kal_printf("SendKey: %s(%2d) Down\n", KeyMappingName[cur_key_code], cur_key_code);
		}
		else
		{
			DecreaseKeyPressNumByOne();
			kal_printf("SendKey: %s(%2d) Up\n", KeyMappingName[cur_key_code], cur_key_code);
		}
		kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)cur_key_code, (unsigned int)cur_key_status);
	}
	else
	{
		kal_printf("KBD Buffer is full!\n");
	}
}

///////////////////////////////////////////////////////////
static int GetLastKeyDownType()
{	
	int i;
	//We assume there's only one key pressed at most!
	for( i = 0; i < MAX_KEY_SUPPORT_NUM ; ++i ) 
	{
		if( KeyStatus[ i ] == DRV_KEY_DOWN )
		{
			if( i == DEVICE_KEY_ALT || 
				i == DEVICE_KEY_CTRL ||
				i == DEVICE_KEY_SHIFT )
			{
				return DRV_SPECIAL_KEY ;
			}
			else
			{
				return DRV_NORMAL_KEY ;
			}
		}
	}
	//Never reach here!
	assert(0);
	return 0 ;
}

///////////////////////////////////////////////////////////
static int GetCurrentKeyDownType(unsigned char cur_key_code) 
{
	if( cur_key_code == DEVICE_KEY_ALT || 
		cur_key_code == DEVICE_KEY_CTRL ||
		cur_key_code == DEVICE_KEY_SHIFT )
	{
		return DRV_SPECIAL_KEY ;
	}	
	return DRV_NORMAL_KEY ;
}

//For One-Key-Mode
static void NormalKeyModeHandle(unsigned char cur_key_status, unsigned char cur_key_code) 
{
	if( cur_key_status == DRV_KEY_DOWN )
	{
		int keys_are_pressed = HowManyKeysArePressed() ;
		switch( keys_are_pressed )
		{
		case 0 :
			SendKey( DRV_KEY_DOWN, cur_key_code ) ;	
			KeyStatus[ cur_key_code ] = DRV_KEY_DOWN ;
			return ;
		default:
			return ;
		}
	}
	else
	{
		//Last keystatus is down
		if( KeyStatus[ cur_key_code ] == DRV_KEY_DOWN )
		{
			// Send KeyUp
			SendKey( DRV_KEY_UP , cur_key_code ) ;	
			KeyStatus[ cur_key_code ] = DRV_KEY_UP ;
		}
	}

}

///////////////////////////////////////////////////////////
//For Two-Key-Mode
static void TwoKeyModeHandle(unsigned char cur_key_status, unsigned char cur_key_code) 
{
	assert( KeyMode == 2 );
	
	//If this key is pressed before, and you're pressing it
	if( KeyStatus[ cur_key_code ] == DRV_KEY_DOWN &&
		cur_key_status == DRV_KEY_DOWN )
	{
		return ;
	}

	if( cur_key_status == DRV_KEY_DOWN )
	{
		int keys_are_pressed = HowManyKeysArePressed() ;
		switch( keys_are_pressed )
		{
		case 0 :
			SendKey( DRV_KEY_DOWN, cur_key_code ) ;	
			KeyStatus[ cur_key_code ] = DRV_KEY_DOWN ;
			return ;
		case 1:
			SendKey( DRV_KEY_DOWN, cur_key_code ) ;	
			KeyStatus[ cur_key_code ] = DRV_KEY_DOWN ;
			return ;
		default:
			return ;
		}
	}
	else
	{
		//Last keystatus is down
		if( KeyStatus[ cur_key_code ] == DRV_KEY_DOWN )
		{
			// Send KeyUp
			SendKey( DRV_KEY_UP , cur_key_code ) ;	
			KeyStatus[ cur_key_code ] = DRV_KEY_UP ;
		}
	}

}

static void SendChangeKeyModeMessage()
{
	//kbd_twokey_detection_enable,
	//kbd_threekey_detection_enable,
	//kbd_multikey_detection_disable
	switch( KeyMode )
	{
	case 1 :
		if (TRUE == kbd_write_buffer(0, kbd_multikey_detection_disable))
		{
			kal_printf("Send kbd_multikey_detection_disable\n");
			kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, 0, kbd_multikey_detection_disable);
		}
		break ;
	case 2 :
		if (TRUE == kbd_write_buffer(0, kbd_twokey_detection_enable))
		{
			kal_printf("Send kbd_twokey_detection_enable\n");
			kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, 0, kbd_twokey_detection_enable);
		}
		break ;		
	default : 
		return ;
	}
}

/*****************************************************************************
* FUNCTION
*   kbd_send_msg_to_uem
* DESCRIPTION
*   send kbd msg to UEM for necessary cases
* PARAMETERS
*   msg_name    IN    kbd relating msg name
*   para        IN    paramter 1, msg dependant.
*   para2       IN   paramter 2, msg dependant.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_send_msg_to_uem(msg_type msg_name, unsigned int para, unsigned int para2)
{
	kal_bool ret_val = KAL_FALSE;
	ilm_struct *ilm_ptr = NULL;
	uemdrv_keypad_ind_struct *l_keypad_data;

   switch (msg_name)
   {
   case MSG_ID_DRVUEM_KEYPAD_IND:
      /* only send when buffer raising edge. If not, do nothing */
      EnterCriticalSection(&keyBuf_cs);
	   if(kbd_buffer.sum > 1)
      {
         LeaveCriticalSection(&keyBuf_cs);
         return;
      }
      LeaveCriticalSection(&keyBuf_cs);

      /* prepare to send */
      ilm_ptr = allocate_ilm( MOD_DRVKBD );
      ilm_ptr->msg_id = (kal_uint16) msg_name;
      ilm_ptr->peer_buff_ptr = NULL;

		l_keypad_data =  (uemdrv_keypad_ind_struct *) 
         construct_local_para( sizeof(uemdrv_keypad_ind_struct), TD_CTRL );

		l_keypad_data ->keypad_code = (unsigned char) para;
		l_keypad_data ->keypad_status = (unsigned char) para2;
      
		ilm_ptr->local_para_ptr = (local_para_struct *) l_keypad_data;
		ret_val = KAL_TRUE;
		break;

	case MSG_ID_DRVUEM_POWER_ON_IND:
      {
		   drvuem_power_on_ind_struct *p = (drvuem_power_on_ind_struct*)
						   construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_CTRL);

		   ilm_ptr = allocate_ilm( MOD_DRVKBD );
		   ilm_ptr->msg_id = (kal_uint16) msg_name;
		   ilm_ptr->peer_buff_ptr = NULL;

		   p->power_on = PWRKEYPWRON;
		   p->poweron_time_left = 0;
		   ilm_ptr->local_para_ptr = (local_para_struct *) p;
		   ret_val = KAL_TRUE;
      }
      break;

	default :
		break;
   }
   
	/* Send the message to the UEM module */
	if (ret_val == KAL_TRUE)
	{
		SEND_ILM( MOD_DRVKBD, MOD_UEM, DRIVER_PS_SAP, ilm_ptr);
	}
	return;
}

/*****************************************************************************
* FUNCTION
*   kbd_init
* DESCRIPTION
*   init kbd driver module
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_init(void) 
{
	UINT uiIndex;
	/* system object */
	#if defined(KBD_TIMER_USE_KAL_SERVICE)
		timerID = kal_create_timer("KbdTimer");
	#else
	#endif
	InitializeCriticalSection(&keyBuf_cs);
	InitializeCriticalSection(&timer_cs);
	KeyPressNum = 0 ;

	for(uiIndex = 0; uiIndex < MAX_KEY_SUPPORT_NUM; uiIndex++)
		KeyStatus[uiIndex] = DRV_KEY_UP;

	/* buffer */
	EnterCriticalSection(&keyBuf_cs);
	kbd_buffer.kbd_data_buffer_rindex = kbd_buffer.kbd_data_buffer_windex  = kbd_buffer.sum = 0;    
	LeaveCriticalSection(&keyBuf_cs);
	return;
}

/*****************************************************************************
* FUNCTION
*   kbd_uninit
* DESCRIPTION
*   uninit kbd driver module
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_uninit(void) 
{
   /* system object */
#if defined(KBD_TIMER_USE_KAL_SERVICE)
   kal_cancel_timer(timerID);
#else
#endif
   DeleteCriticalSection(&keyBuf_cs);
	DeleteCriticalSection(&timer_cs);
   return;
}

/*****************************************************************************
* FUNCTION
*   kbd_long_detect
* DESCRIPTION
*   deal with key longpress detected
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_long_detect(void *timer_param)
{
	unsigned char key_code; 
	unsigned char key_status;

	if(g_bKeyupFlag)
		return;

	EnterCriticalSection(&timer_cs);
	key_code = (unsigned char)timer_param;
	key_status = KEY_LONGPRESS;
#if defined(KBD_UNIT_DEBUG)
   kal_printf("kbd_long_detect\n");
#endif
   if (TRUE == kbd_write_buffer(key_code, key_status))
   { 
	   kal_printf("SendKey(Long Press): %s(%2d) Down\n", KeyMappingName[key_code], key_code);
        kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);
   }

   /* whether need to issue repeat event later */
   kal_cancel_timer(timerID);
   kal_set_timer(timerID, (kal_timer_func_ptr)kbd_repeat_detect, (void*)key_code, (kal_uint32)KBD_TIMER_REPEAT_TICKS, 0);

	LeaveCriticalSection(&timer_cs);
}

/*****************************************************************************
* FUNCTION
*   kbd_repeat_detect
* DESCRIPTION
*   deal with key repeat detected
* PARAMETERS
*   None.
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static void kbd_repeat_detect(void *timer_param)
{
	unsigned char key_code;
	unsigned char key_status;

	if(g_bKeyupFlag)
		return;
	EnterCriticalSection(&timer_cs);
	key_code = (unsigned char)timer_param;
	key_status = KEY_REPEATED;
#if defined(KBD_UNIT_DEBUG)
   kal_printf("kbd_repeat_detect\n");
#endif
   if (TRUE == kbd_write_buffer(key_code, key_status))
   {
	   kal_printf("SendKey(Repeat): %s(%2d) Down\n", KeyMappingName[key_code], key_code);
      kbd_send_msg_to_uem(MSG_ID_DRVUEM_KEYPAD_IND, (unsigned int)key_code, (unsigned int)key_status);
   }

   /* whether need to issue repeat event later */
   kal_cancel_timer(timerID);
   kal_set_timer(timerID, (kal_timer_func_ptr)kbd_repeat_detect, (void*)key_code, (kal_uint32)KBD_TIMER_REPEAT_TICKS, 0);
	LeaveCriticalSection(&timer_cs);
}

/*****************************************************************************
* FUNCTION
*   kbd_write_buffer
* DESCRIPTION
*   write to kbd buffer
* PARAMETERS
*   key_status     IN    key status
*   key_code     IN    key code
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
static BOOL kbd_write_buffer(unsigned char key_code, unsigned char key_status)
{
   BOOL write = FALSE;

#if defined(KBD_UNIT_DEBUG)
   /* for debugging multi-thread program */
   kal_uint16 sum = kbd_buffer.sum;
	kal_uint16 size = DRV_KBD_BUFFER_SIZE;
#endif

   EnterCriticalSection(&keyBuf_cs);

   /* flow control to avoid key buffer full */
   if ((kbd_buffer.sum + 1) > (DRV_KBD_BUFFER_SIZE - 1))
   {
      /* ingore it */
      write = FALSE;
   }
   else if ((kbd_buffer.sum + 1) > (DRV_KBD_BUFFER_SIZE - 2))
   {
      if (key_status == KEY_RELEASED) 
         write = TRUE;
      else
         write = FALSE;
   }
   else
   {
      write = TRUE;
   }

   if (write == TRUE)
   {
		kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key_code;
	 	kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = key_status;
		kbd_buffer.kbd_data_buffer_windex ++;
		kbd_buffer.kbd_data_buffer_windex &= (DRV_KBD_BUFFER_SIZE-1);
		kbd_buffer.sum ++;
   }
   LeaveCriticalSection(&keyBuf_cs);
   return write;
}


/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*   _Kbd_GetKeyData
* DESCRIPTION
*   kbd data buffer reader function
* PARAMETERS
*   keydata     OUT    key data
* RETURNS
*   Success or not
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
kal_bool _Kbd_GetKeyData(kbd_data_struct *keydata)
{
	kal_bool result;

	EnterCriticalSection(&keyBuf_cs);

	if (kbd_buffer.sum > 0)
	{
		keydata->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];
		keydata->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;
		kbd_buffer.kbd_data_buffer_rindex ++;
		kbd_buffer.kbd_data_buffer_rindex &= (DRV_KBD_BUFFER_SIZE-1);
		kbd_buffer.sum --;
		result = KAL_TRUE;
	}
	else
		result = KAL_FALSE;

	LeaveCriticalSection(&keyBuf_cs);

#if defined(KBD_UNIT_DEBUG)
	kal_printf("_Kbd_GetKeyData() status:%d code:%d return:%d\n", keydata->Keyevent, keydata->Keydata[0], result);
#endif
	return result;
}


/*****************************************************************************
* FUNCTION
*   _Kbd_PeekBuffer
* DESCRIPTION
*   This function implements to peek a key event from the buffer.
* 
* PARAMETERS
*   keydata     OUT    key data
* RETURNS
*  KAL_TRUE  - get the key event sucessfully.
* KAL_FALSE - there is no key event in the buffer
*
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
kal_bool _Kbd_PeekBuffer(kbd_data *keydata, kal_bool specify_read, 
						kal_uint32 read_pointer,kal_uint32* current_read_pointer)
{
	kal_bool result;

	EnterCriticalSection(&keyBuf_cs);

	if (kbd_buffer.sum > 0)
	{
		if(!specify_read)
		{
			keydata->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];
			keydata->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;

			*current_read_pointer = kbd_buffer.kbd_data_buffer_rindex;
		}
		else
		{
			keydata->Keydata[0] = kbd_buffer.kbd_data_buffer[read_pointer%DRV_KBD_BUFFER_SIZE].Keydata[0];
			keydata->Keyevent = kbd_buffer.kbd_data_buffer[read_pointer%DRV_KBD_BUFFER_SIZE].Keyevent;

			*current_read_pointer = kbd_buffer.kbd_data_buffer_rindex;
		}  

		result = KAL_TRUE;

	}
	else
		result = KAL_FALSE;

	LeaveCriticalSection(&keyBuf_cs);

#if defined(KBD_UNIT_DEBUG)
	kal_printf("_Kbd_PeekBuffer() status:%d code:%d return:%d\n", keydata->Keyevent, keydata->Keydata[0], result);
#endif
	return result;
}

/*****************************************************************************
* FUNCTION
*   w32_key_det_mode_switch
* DESCRIPTION
*   switch key mode ( one-key, two key, three key)
* PARAMETERS
*   keymode_num_to_switch     IN    which key mode number we want to switch to
* RETURNS
*  KAL_TRUE   - Enable or disable two key dection mode successfully.
*  KAL_FALSE  - Already in the mode. No need to set. 
* GLOBALS AFFECTED
*   KeyMode.
*****************************************************************************/
kal_bool w32_key_det_mode_switch( unsigned char keymode_num_to_switch )
{  

#ifdef __TWO_KEY_DETECTION_SWITCHABLE__
	if (keymode_num_to_switch > 2)
		return KAL_FALSE;
#endif
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__
	if (keymode_num_to_switch > 3)
		return KAL_FALSE;
#endif


	if( keymode_num_to_switch == KeyMode ) //Keymode is the same as previous one
	{   
		return KAL_FALSE ;        
	}
	else
	{
		switch ( keymode_num_to_switch )
		{
		case 1: ;
		case 2: ;
			gReady_To_Change_Key_Mode = keymode_num_to_switch ; 
			return KAL_TRUE ;
		default :
			return KAL_FALSE ;
		}
	}
}

/*****************************************************************************
* FUNCTION
*   w32_key_detect_ind
* DESCRIPTION
*   key event handling function for native system
* PARAMETERS
*   key_status     IN    physical key status, either KEY_PRESSED or KEY_RELEASED
*   key_code     IN    physical key code. Please refer to win32_ext_key_enum
* RETURNS
*   None.
* GLOBALS AFFECTED
*   None.
*****************************************************************************/
void w32_key_detect_ind(unsigned char cur_key_status, unsigned char cur_key_code)
{
	//Filter out is_key_poweron == KAL_FALSE && cur_key_code == DEVICE_KEY_POWER
	if( is_key_poweron == KAL_FALSE || cur_key_code == DEVICE_KEY_POWER )
	{
		//PowerOn MoDIS
		if( is_key_poweron == KAL_FALSE && 
			cur_key_code == DEVICE_KEY_POWER && 
			cur_key_status == DRV_KEY_UP )
		{
			//initial KeyStatus to DRV_KEY_UP
			is_key_poweron = KAL_TRUE;
			memset( KeyStatus, DRV_KEY_UP , MAX_KEY_SUPPORT_NUM * sizeof(int) ) ;
			kbd_init();
			kbd_send_msg_to_uem(MSG_ID_DRVUEM_POWER_ON_IND, (unsigned int)NULL, (unsigned int)NULL);
			#ifdef QWERTY_KEYPAD
			InitQWERTYTimer();		    			
			#endif		    			
		}
		return ;
	}

	if( gReady_To_Change_Key_Mode != 0 &&
		CheckIfAllKeyStatusAreUp() == TRUE )
	{	
		KeyMode = gReady_To_Change_Key_Mode;
		gReady_To_Change_Key_Mode = 0 ;
		SendChangeKeyModeMessage() ;
	}

	//Enable Normal + Special Key
	switch( KeyMode )
	{
	case 1 :	//one-Key
		NormalKeyModeHandle( cur_key_status, cur_key_code ) ;
		break ;
	case 2 :	//Two-Key
		TwoKeyModeHandle(cur_key_status, cur_key_code ) ;
		break ;
	default :
		assert(0);
	}

	//Do it again!
	if( gReady_To_Change_Key_Mode != 0 &&
		CheckIfAllKeyStatusAreUp() == TRUE )
	{	
		KeyMode = gReady_To_Change_Key_Mode;
		gReady_To_Change_Key_Mode = 0 ;
		SendChangeKeyModeMessage() ;
	}
}

/*****************************************************************************
* FUNCTION
*   kbd_find_2step
* DESCRIPTION
*   legancy function (TBD)
* PARAMETERS
* RETURNS
* GLOBALS AFFECTED
*****************************************************************************/
void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step) 
{
	/* null function */
}

/*************************************************************************
* FUNCTION                                                            
*	kbd_two_key_detection_switch
*
* DESCRIPTION                                                           
*	(Fake function to pass linking)
*	This function is to enable/disable the two key detction mode.
*
* PARAMETERS
*  KAL_TRUE   - To enable the two key detction mode.
*  KAL_FALSE  - To disable the two key detction mode.
*
* RETURNS
*  KAL_TRUE   - Enable or disable two key dection mode successfully.
*  KAL_FALSE  - Already in the mode. No need to set. 
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_two_key_detection_switch(kal_bool enable)
{
    /* MoDIS Not support */
    return KAL_FALSE;
}

kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode)
{
    /* MoDIS Not support */
    return KAL_FALSE;
}

/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyButtonSupported
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is supported or NOT
*
* PARAMETERS
*  key        - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is supported in this phone
*  KAL_FALSE  - The specific key is NOT supported in this phone
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_IsKeyButtonSupported(kal_uint8 key)
{
	kal_uint32 num_key, i;
	kal_bool ret = KAL_FALSE;
	num_key = sizeof(keypad_custom_def.keypad)/sizeof(kal_uint8);
	for (i=0;i<num_key;i++){
		if ( key == keypad_custom_def.keypad[i] ){
			return KAL_TRUE;
		}
	}
	
	return ret;
}
