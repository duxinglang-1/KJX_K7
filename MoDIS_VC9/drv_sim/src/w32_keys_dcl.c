/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   w32_keys_dcl.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   keypad DCLH and DCLS dummy functions for WIN32 environment
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"
#include "dcl.h"
#include "w32_keys.h"

extern kbd_buffer_struct_modis kbd_buffer; 

/************************************************************************/
/*         HAL: DclHKBD_XXX interface                                                             */
/************************************************************************/
KBDH_EVENT_FUNC DclHKBD_Event_cb = NULL;
DCL_STATUS DclHKBD_Initialize(void)
{
	DclHKBD_Event_cb =NULL;
	return STATUS_OK;
}

DCL_HANDLE DclHKBD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if((DCL_KBD != dev) )
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}
	return (DCL_HANDLE)DCL_HKBD_MAGIC_NUM; 
}

DCL_STATUS DclHKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	switch (cmd)
	{
	case HKBD_CMD_GET_KEY_NUMBER:
		{
		}
	default:
		break;
	}
	return STATUS_OK;
}

DCL_STATUS DclHKBD_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}

DCL_STATUS DclHKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, KBDH_EVENT_FUNC callback)
{
	if(event >= DCL_EVENT_HKBD_MAX)
	{
		return STATUS_FAIL;
	}

	if(DCL_EVENT_HKBD_STATUS_CHANGE == event)
		DclHKBD_Event_cb = callback;
	else
		return STATUS_INVALID_EVENT;

	return STATUS_OK;
}

/************************************************************************/
/*         DCL: DclSKBD_XXX interface                                                             */
/************************************************************************/
//Internal:
/*
* FUNCTION                                                            
*	CopyData
*
* DESCRIPTION                                                           
*   This function is to copy from MAUI keypad struct to DCL SW keypad struct.
*
* CALLS  
*	It is called to copy
*
* PARAMETERS 
*   STS_CTRL_GET_T        - source
*   TouchPanelEventStruct - destination
*
* RETURNS
*
* GLOBALS AFFECTED
*   external_global
*/
static void CopyData(SKBD_CTRL_KEYDATA_T* GKD, kbd_data *kd)
{

#ifdef TWO_KEY_ENABLE
	GKD->Keydata[0] = kd->Keydata[0];
	GKD->Keydata[1] = kd->Keydata[1];
#else /*!TWO_KEY_ENABLE*/
	GKD->Keydata[0] = kd->Keydata[0];
#endif   /*TWO_KEY_ENABLE*/

	switch(kd->Keyevent)
	{
	case kbd_onekey_press:
		GKD->Keyevent = DCL_kbd_onekey_press;
		break;
	case kbd_onekey_release:
		GKD->Keyevent = DCL_kbd_onekey_release;
		break;
#ifdef TWO_KEY_ENABLE
	case kbd_twokey_press:
		GKD->Keyevent = DCL_kbd_twokey_press;
		break;
	case kbd_twokey_release:
		GKD->Keyevent = DCL_kbd_twokey_release;
		break;
#endif   /*TWO_KEY_ENABLE*/
	case kbd_onekey_longpress:
		GKD->Keyevent = DCL_kbd_onekey_longpress;
		break;
	case kbd_onekey_repeated:
		GKD->Keyevent = DCL_kbd_onekey_repeated;
		break;
	case kbd_onekey_fullpress:
		GKD->Keyevent = DCL_kbd_onekey_fullpress;
		break;
	case kbd_twokey_detection_enable:
		GKD->Keyevent = DCL_kbd_twokey_detection_enable;
		break;
	case kbd_threekey_detection_enable:
		GKD->Keyevent = DCL_kbd_threekey_detection_enable;
		break;
	case kbd_multikey_detection_disable:
		GKD->Keyevent = DCL_kbd_multikey_detection_disable;
		break;
	default:
		break;
	}
}

DCL_STATUS DclSKBD_Initialize(void)
{
	return STATUS_OK;
}

DCL_HANDLE DclSKBD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if( ( dev != DCL_KBD ))
		ASSERT(0);

	return (DCL_HKBD_MAGIC_NUM |flags);
}

DCL_STATUS DclSKBD_Close(DCL_HANDLE handle)
{
	return STATUS_OK;
}

DCL_STATUS DclSKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	switch (cmd)
	{
	case KBD_CMD_SET_DETECTION_MODE:
		{
			SKBD_CTRL_MODE_T* prCtrlMode;
			prCtrlMode = &(data->rKBDCtrMode);
			prCtrlMode->bFlag = w32_key_det_mode_switch(prCtrlMode->Det_Mode);
			break;
		}
	case KBD_CMD_GET_DETECTION_MODE:
		{
			SKBD_CTRL_MODE_T* prCtrlMode1;
			prCtrlMode1 = &(data->rKBDCtrMode);
			prCtrlMode1->Det_Mode = (DCL_UINT8)gReady_To_Change_Key_Mode;
			break;
		}
	case KBD_CMD_GET_KEY_DATA:
		{
			kal_bool fg ;
			kbd_data keydata;
			SKBD_CTRL_KEYDATA_T* prCtrlData ;
			prCtrlData = &(data->rKBDCtrGetData);
			//fg = Kbd_GetKeyDatas(&keydata);
			fg = _Kbd_GetKeyData((kbd_data_struct*)(&keydata));

			if(KAL_FALSE == fg)
				return STATUS_BUFFER_EMPTY;

			CopyData(prCtrlData, &keydata);
			break;
		}
	case KBD_CMD_PEEK_KEY_DATA:
		{
			kal_bool fg;
			kbd_data keydata;
			SKBD_CTRL_PEEKDATA_T* prCtrlData1;
			prCtrlData1 = &(data->rKBDCtrPeekData);
			fg = _Kbd_PeekBuffer(&keydata, prCtrlData1->specify_read, prCtrlData1->read_pointer, prCtrlData1->current_read_pointer);
			if(KAL_FALSE == fg)
				return STATUS_BUFFER_EMPTY;

			CopyData(prCtrlData1->keydata,&keydata);

			break;
		}
	case KBD_CMD_CTRL_KEY_SUPPORT:
		{
			SKBD_CTRL_KEYSUPPORT_T* pCtrl = &(data->rKBDCtrlKeySupport);
			pCtrl->fgIKBS =  kbd_IsKeyButtonSupported((kal_uint8)pCtrl->uKey);
			break;
		}
	case KBD_CMD_CTRL_KEY_MULTIPLE:
		{
			break;
		}
	case KBD_CMD_GET_KEY_EVENT_CNT:
		{
			SKBD_CTRL_KEY_CNT_T* pCtrl = &(data->rKBDCtrkeyCnt);
			pCtrl->keycnt = kbd_buffer.sum;
			break;
		}
	default:
		return STATUS_UNSUPPORTED ;
	}
	return STATUS_OK;
}

DCL_STATUS DclSKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event,PFN_DCL_CALLBACK callback)
{
	return STATUS_OK;
}
