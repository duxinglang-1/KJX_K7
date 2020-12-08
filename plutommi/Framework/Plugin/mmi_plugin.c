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

/*******************************************************************************
 * Filename:
 * ---------
 *  OTFRes.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MoDIS plugin for MMI, MoDIS only.
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
 ****************************************************************************/

#ifndef __MTK_TARGET__
#ifdef __MODIS_PLUGIN__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "windows.h"
#include "mmi_include.h"
#include "mmiapi.h"
#include "plugin.h"
#include "plugin_hlpr.h"

/*****************************************************************************
 * Type Definition
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    mmi_plug_in_msg_struct* param;
} mmi_plugin_msg_struct;

/*****************************************************************************
 * Global Variable
 *****************************************************************************/
//extern void mte_hisr(void);
//MTE used
extern void (*w32_mmi_mte_api(int api_index))(void);
extern char* release_verno();
extern char* release_hw_ver();
HANDLE g_hMteEvent = NULL;
UINT g_bMoDISMMIIsGoingToClose = 0;	//It's useless, maybe
UINT g_bMoDISUIClosedByMMI = 0;
extern int	skin_lcd_width;
extern int	skin_lcd_height;


/*****************************************************************************
 * Local Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  infomonitor_hisr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mte_hisr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	SMHandle hSMHandle = NULL;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	hSMHandle = CreateShareMem(PLUGIN_NAME_MTE, sizeof(mte_data_struct));
	if(NULL != hSMHandle)
	{
		mte_data_struct data;
		memset(&data, 0, sizeof(data));
		if(Read(hSMHandle, (void*)(&data), sizeof(data)))
		{	
			switch (data.cmd)
			{
			case MTE_CMD_GET_LCD_SIZE:
				{
					int* pData = (int*)&data.data;
					pData[0] = skin_lcd_width;
					pData[1] = skin_lcd_height;
					data.nDataLength = sizeof(int)*2;
					Write(hSMHandle, (void*)(&data), sizeof(data));
				}
				break;
			case MTE_CMD_GET_MAUI_VERSION:
				{
					char* pszVersion = malloc(64);
					char *swver,*hwver;
					memset(pszVersion, 0, 64);
					swver = release_verno();
					hwver = release_hw_ver();				
					sprintf(pszVersion,"%s %s", hwver,swver);
					memcpy(data.data, pszVersion, 64);
					data.nDataLength = 64;
					free(pszVersion);
					Write(hSMHandle, (void*)(&data), sizeof(data));
				}
				break;
			case MTE_CMD_GET_API:
				{
					int* pData = (int*)&data.data;
					pData[0] = (int)w32_mmi_mte_api;
					data.nDataLength = 4;
					Write(hSMHandle, (void*)(&data), sizeof(data));
				}
				break;
			case MTE_CMD_GET_MMI_CLOSE_FLAG:
				{
					int* pData = (int*)&data.data;
					pData[0] = (int)(&g_bMoDISMMIIsGoingToClose);
					pData[1] = (int)(&g_bMoDISUIClosedByMMI);
					data.nDataLength = 8;
					Write(hSMHandle, (void*)(&data), sizeof(data));
				}
				break;
			case MTE_CMD_IS_DISABLED:
				{
					int* pData = (int*)&data.data;
					int bIsDisabled = 0;

					#ifdef DISABLE_MODIS_THEME_EDITOR           
						bIsDisabled = 1;
					#endif
					pData[0] = bIsDisabled;
					data.nDataLength = 8;
					Write(hSMHandle, (void*)(&data), sizeof(data));
				}
				break;
			default:
				break;
			}
		}
	
	}
	if(NULL == g_hMteEvent)
		g_hMteEvent = CreateEvent(NULL, TRUE, FALSE, PLUGIN_EVENT_MTE);
	if(NULL != g_hMteEvent)
		SetEvent(g_hMteEvent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_plug_in_msg_handler
 * DESCRIPTION
 *  Message handler for events from MoDIS UI
 * PARAMETERS
 *  msg     [IN] message 
 * RETURNS
 *  whether handle the event
 *****************************************************************************/
static U8 mmi_plug_in_msg_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mmi_plugin_msg_struct* pdata = (mmi_plugin_msg_struct*)msg;
	//mmi_plug_in_msg_struct* argv = (mmi_plug_in_msg_struct*)(pdata->param);
	mmi_plug_in_msg_struct* argv = (mmi_plug_in_msg_struct*)(msg);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (argv->info.emMsgID)
	{
	case PLUG_IN_MSG_MTE:
		mte_hisr();
		break;
	/*Add more message handler here*/
		//case MMI_PLUG_IN_MSG_XXX:
		//...
		//break;
	default:
		break;
	}

	//Free the resource
	//Reverse action of "NEW_LOCAL_PTR"

    return MMI_FALSE;
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_init
 * DESCRIPTION
 *  Init OTF resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_plug_in_init(void)
{
    // MSG_ID_PLUG_IN_IND was defined in .\interface\mmi\mmiapi_sap.h line926
	mmi_frm_set_protocol_event_handler(
		MSG_ID_MMI_PLUG_IN_IND, 
		mmi_plug_in_msg_handler, 
		MMI_TRUE);

}

#endif /* __MODIS_PLUGIN__ */
#endif /* __MTK_TARGET__ */

