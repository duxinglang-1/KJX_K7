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

#include "MMI_features.h"
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#include "ConnectivityResDef.h"

#ifdef __PLUTO_MMI_PACKAGE__ 
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_bluetooth_def.h"
#ifdef __TCPIP__
#include "mmi_rp_app_dataaccount_def.h"
#endif
#ifdef __MMI_CBM_CONNECTION_MANAGER__
#include "mmi_rp_app_connectmanage_def.h"
#endif
#endif




/***************************************************************************************************/
/*** Infrared Resource  ***/
/***************************************************************************************************/
#ifdef __MMI_IRDA_SUPPORT__

void PopulateExtDevIrDARes(void)
{
      /* String Resource */
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_TITLE,   "Infrared Setting","Infrared Setting title");
     ADD_APPLICATION_STRING2(STR_IRDA_MENU_OPEN,    "Open","Infrared Open");
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_PERIOD, "Open 10 Minutes","Infrared Open a certain period");

#if defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card support
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_STORAGE, "Storage Location","Infrared Data Storage Location");
	ADD_APPLICATION_STRING2(STR_IRDA_MENU_ACTIVATION, "Activation Menu","Infrared Activation Menu");
	ADD_APPLICATION_STRING2(STR_IRDA_STORAGE_CARD, "Memory Card","Infrared Data Storage is External Card");
	ADD_APPLICATION_STRING2(STR_IRDA_NO_CARD_ERROR, "No External Card Inserted","Infrared Data Storage can't be External Card");
	ADD_APPLICATION_STRING2(STR_IRDA_FILE_RECEIVED, "Infrared File(s) Received","Infrared files received");
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support

	ADD_APPLICATION_STRING2(STR_IRDA_RECV_DISK_FULL, "Disk Full, IrDA Receive Fail","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_RECV_ROOT_DIR_FULL, "Root Directory Full, IrDA Receive Fail","Root Directory Full");
	ADD_APPLICATION_STRING2(STR_IRDA_RECV_FILE_IND, "File stored at '\Received' folder","Received file");

	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_BROWSE, "Browse","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_HED, "Received","Received file");
	ADD_APPLICATION_STRING2(STR_IRDA_NOTY_RECV_FILE_TIL, "Files","Received file");

	ADD_APPLICATION_STRING2(STR_IRDA_DEV_BUSY, "IR Device Busy","Device Busy");
	ADD_APPLICATION_STRING2(STR_IRDA_SEND, "Sending","IR Device Sending");
	ADD_APPLICATION_STRING2(STR_IRDA_WRITE_FILE_FAIL, "Write File Failed","FS write failed");
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__ 
	/* shantanu -for DLT */
	ADD_APPLICATION_STRING2(STR_IRDA_THEME_FILE_RECV, "Received Theme File","Received File message");
	ADD_APPLICATION_STRING2(STR_ID_DLT_DO_YOU_WANT_TO_ACTIVATE, "Do you want to Activate Theme?","Do you want to message");
	/* shantanu -for DLT */
#endif

      /* Image Resource */
      /* Status icon is populate in Res_Gui.c */
	//ADD_APPLICATION_IMAGE2(IMG_IRDA_ICON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_IR.bmp","IrDA active icon");
	ADD_APPLICATION_IMAGE2(IMG_IRDA_MENU_TITLE, CUST_IMG_PATH"\\\\MAINLCD\\\\Irda\\\\SB_IR.bmp","IrDA menu icon");

      /*Menu Items*/
#if defined( __MMI_IRDA_SUPPORT__ )

#if !defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card Support
#if ((defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_12MATRIX__) ||defined(__MMI_OP02_MAINMENU_9MATRIX__)) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MENU_ID_CONNECTIVITY, 3,	
#else
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MAIN_MENU_EXTRA_MENUID, 3,
#endif
                                                         MENU_CONN_IRDA_OPEN,
                                                         MENU_CONN_IRDA_CLOSE,
                                                         MENU_CONN_IRDA_PERIOD,
	                                                    SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_TITLE, IMG_IRDA_MENU_TITLE ));
#else //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
#if ((defined(__MMI_OP01_MENU_9MATRIX__)|| defined(__MMI_OP01_MENU_12MATRIX__)) && (defined(__IRDA_SUPPORT__) || defined(__MMI_BT_SUPPORT__)))
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MENU_ID_CONNECTIVITY, 2,
#else
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_MAIN, MAIN_MENU_EXTRA_MENUID, 2,
#endif
                                                         MENU_CONN_IRDA_ACTIVATION,
														 MENU_CONN_IRDA_STORAGE,
	                                                    SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_TITLE, IMG_IRDA_MENU_TITLE ));
#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_CONN_IRDA_MAIN, mmi_irda_setup_highlight_handler);

#if !defined(__MMI_IRDA_CARD_SUPPORT__) //Priyesh - Memory Card Support
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_OPEN, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_OPEN, IMG_IRDA_MENU_OPEN  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_CLOSE, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_GLOBAL_CLOSE, IMG_IRDA_MENU_CLOSE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_PERIOD, MENU_CONN_IRDA_MAIN, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_PERIOD, IMG_IRDA_MENU_PERIOD  ));
#else //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support
	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_ACTIVATION, MENU_CONN_IRDA_MAIN, 3,
                                                         MENU_CONN_IRDA_OPEN,
                                                         MENU_CONN_IRDA_CLOSE,
                                                         MENU_CONN_IRDA_PERIOD,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_ACTIVATION, IMG_IRDA_MENU_ACTIVATION ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_OPEN, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_OPEN, IMG_IRDA_MENU_OPEN  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_CLOSE, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_GLOBAL_CLOSE, IMG_IRDA_MENU_CLOSE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_PERIOD, MENU_CONN_IRDA_ACTIVATION, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_PERIOD, IMG_IRDA_MENU_PERIOD  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE, MENU_CONN_IRDA_MAIN, 2,
                                                         MENU_CONN_IRDA_STORAGE_PHONE,
                                                         MENU_CONN_IRDA_STORAGE_CARD,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_MENU_STORAGE, IMG_IRDA_MENU_STORAGE ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE_PHONE, MENU_CONN_IRDA_STORAGE, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_GLOBAL_PHONE, IMG_IRDA_STORAGE_PHONE  ));

	ADD_APPLICATION_MENUITEM((MENU_CONN_IRDA_STORAGE_CARD, MENU_CONN_IRDA_STORAGE, 0,
	                                                    SHOW,MOVEABLEWITHINPARENT,DISP_LIST,
		                                               STR_IRDA_STORAGE_CARD, IMG_IRDA_STORAGE_CARD  ));
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_CONN_IRDA_STORAGE, HighlightIrdaStorageHandler);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_CONN_IRDA_ACTIVATION, HighlightIrdaActivationHandler);
    ADD_APPLICATION_MENUITEM_HINT_HANDLER(MENU_CONN_IRDA_ACTIVATION, HintIrdaActivation);
    ADD_APPLICATION_MENUITEM_HINT_HANDLER(MENU_CONN_IRDA_STORAGE, HintIrdaStorageLocation);

#endif //__MMI_IRDA_CARD_SUPPORT__ //Priyesh - Memory Card Support


#endif
}

#endif /* __MMI_IRDA_SUPPORT__ */

#endif /* DEVELOPER_BUILD_FIRST_PASS */

