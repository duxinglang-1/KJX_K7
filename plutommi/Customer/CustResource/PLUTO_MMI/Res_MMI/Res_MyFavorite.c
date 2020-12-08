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
 *  Res_MyFavorite.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Resource population.
 *
 *  Author:
 * -------
 *  Jie Hao
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"   /* add if you use any compile options defined in MMI_features.h */

#ifdef __MMI_MY_FAVORITE__old
#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "PopulateRes.h"
#include "FileManagerResDef.h"
#include "FunAndGamesResDef.h"
#include "MyFavoriteResDef.h"   /* for resource ID */


/*****************************************************************************
 * FUNCTION
 *  PopulateMyFavoriteRes
 * DESCRIPTION
 *  populate all resource fo MyFavorite
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateMyFavoriteRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resource ID check */
    if ((SCR_ID_MY_FAVORITE_END > MY_FAVORITE_BASE_MAX) ||
        (STR_ID_MY_FAVORITE_END > MY_FAVORITE_BASE_MAX) ||
        (IMG_ID_MY_FAVORITE_END > MY_FAVORITE_BASE_MAX))
    {
        RESOURCE_ID_OUT_OF_RANGE_HANDLER();
    }
    

	/************************************************************/
	/*															*/
	/*			Highlight Handler								*/
	/*															*/
	/************************************************************/
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_OPEN, mmi_my_favorite_highlight_folder_open);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_CREAT_FOLDER, mmi_my_favorite_highlight_creat_folder);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_MEMORY_CARD_FORMAT, mmi_my_favorite_highlight_memorycard_format);
#ifdef __J2ME__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN, mmi_my_favorite_highlight_javabox_open);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS_OPEN, mmi_my_favorite_highlight_gplusgame_open);

    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING, mmi_my_favorite_highlight_javabox_setting);
    #ifdef OGDR_SECURITY_SETTING
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY, mmi_my_favorite_highlight_javabox_security);
    #endif
#endif /* __J2ME__ */ 
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_EDITOR_DONE, mmi_my_favorite_highlight_creat_done);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_MY_FAVORITE_INPUT_METHOD, mmi_my_favorite_highlight_input_method);
    
	/************************************************************/
	/*															*/
	/*			Strings											*/
	/*															*/
	/************************************************************/
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_MAIN, "My Favorite", "Title of MyFavorite" );

#if defined(__MMI_MY_FAVORITE_IMAGES__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_IMAGES, "Images", "Images folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_AUDIO__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_AUDIO, "Audio", "Audio folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_VIDEO__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_VIDEO, "Video", "Video folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_JAVABOX__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_JAVABOX, "Java Box", "Java Box folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_SWFLASH__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_SWFLASH, "SWflash", "SWflash folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_OTHERS__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_OTHERS, "Others", "Others folder shown string" );
#endif
//#if defined(__MMI_MY_FAVORITE_MEMORYCARD__)
//   ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_MEMORY_CARD, "MemoryCard", "MemoryCard folder shown string" );
//#endif
#if defined(__MMI_MY_FAVORITE_MMSBOX__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_MMSBOX, "MMS Box", "MMS Box folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_THEME__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_THEME, "Themes", "Themes folder shown string" );
#endif
#if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_FOLDER_GPLUSGAME, "G+ Game", "G+ Game folder shown string" );
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_GPLUSGAME, "G+ Game download", "G+ Game download string" );
#endif

	/************************************************************/
    /*	Hyperlink String   									    */
	/************************************************************/
#if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_IMAGES, "Image download", "Java download string" );
#endif
#if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_AUDIO, "Audio download", "Flash download string" );
#endif
#if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_VIDEO, "Video download", "Java download string" );
#endif
#if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_MMSBOX, "MMS download", "Flash download string" );
#endif
#if defined(__MMI_MY_FAVORITE_JAVA_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_JAVA, "Java download", "Java download string" );
#endif
#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_SWFLASH, "Flash download", "Flash download string" );
#endif
#if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_THEME, "Theme download", "Java download string" );
#endif
#if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
    ADD_APPLICATION_STRING2(STR_ID_MY_FAVORITE_WAP_OTHERS, "Others download", "Flash download string" );
#endif
 
	/************************************************************/
	/*															*/
	/*			Images											*/
	/*															*/
	/************************************************************/

	/************************************************************/
    /*	Title Icon          									*/
	/************************************************************/
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_MAIN,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF.PNG", "Title icon" );
#if defined(__MMI_MY_FAVORITE_IMAGES__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_IMAGES,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_IM.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_AUDIO__)
    ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_AUDIO,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_AU.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_VIDEO__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_VIDEO,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_VI.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_MMSBOX__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_MMSBOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_MM.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_JAVABOX__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_JAVABOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_JA.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_GPLUSGAME,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_GP.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_SWFLASH__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_SWFLASH,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_SW.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_THEME__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_THEME,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_TH.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_OTHERS__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_OTHERS,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_OT.PNG", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_MEMORYCARD__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_TITLE_MEMORY_CARD,
		CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_MF_MC.PNG", "Title icon" );
#endif

	/************************************************************/
    /*	Menu Icon          									    */
	/************************************************************/
#if defined(__MMI_MY_FAVORITE_IMAGES__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_IMAGES,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_AUDIO__)
    ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_AUDIO,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_VIDEO__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_VIDEO,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_MMSBOX__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_MMSBOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS.bmp", "Title icon" );
#endif
#if defined(__MMI_MY_FAVORITE_JAVABOX__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_JAVABOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Javabox.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_SWFLASH__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_SWFLASH,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWflash.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_THEME__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_THEME,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_OTHERS__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_OTHERS,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_MEMORYCARD__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_MEMORY_CARD,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MemoryCard.bmp", "folder icon" );
#endif
#if defined(__MMI_MY_FAVORITE_GPLUSGAME__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_FOLDER_GPLUSGAME,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_GPlusGame.bmp", "folder icon" );

	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_GPLUSGAME,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_GPlusGame_Url.bmp", "URL icon" );
#endif

	/************************************************************/
    /*	Hyperlink icon     									    */
	/************************************************************/
#if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_IMAGES,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_IMAGES_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Images_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_AUDIO,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_AUDIO_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Audio_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_VIDEO,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_VIDEO_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Video_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_MMSBOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_MMSBOX_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_MMS_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_JAVA_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_JAVABOX,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_JavaBox_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_JAVABOX_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_JavaBox_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_SWFLASH,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWFlash_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_SWFLASH_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_SWFlash_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_THEME,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_THEME_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Theme_Url_Large.bmp", "Large URL icon" );
#endif
#if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_OTHERS,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other_Url.bmp", "URL icon" );
	ADD_APPLICATION_IMAGE2(IMG_ID_MY_FAVORITE_WAP_OTHERS_LARGE,
		CUST_IMG_PATH"\\\\MainLCD\\\\MyFavorite\\\\My_Favorite_Other_Url_Large.bmp", "Large URL icon" );
#endif

	/************************************************************/
	/*															*/
	/*			Folder Option									*/
	/*															*/
	/************************************************************/

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS,0,2,
       	MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_OPEN, 
   	    MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_CREAT_FOLDER,
    	SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_MY_FAVORITE_MEMORY_CARD_OPTIONS,0,
            MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_OPEN, 
            MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_CREAT_FOLDER, 
  //          MENU_ID_MY_FAVORITE_MEMORY_CARD_FORMAT,
            MENU_ITEM_END,
            SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

#if defined(__J2ME__)
       ADD_APPLICATION_MENUITEM2((MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS,0,
            MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN, 
            MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING, 
    #ifdef OGDR_SECURITY_SETTING
            MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY,
    #endif
            MENU_ITEM_END,
            SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

       ADD_APPLICATION_MENUITEM2((MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS,0,
            MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS_OPEN, 
            MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING, 
    #ifdef OGDR_SECURITY_SETTING
            MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY,
    #endif
            MENU_ITEM_END,
            SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

#endif

	/************************************************************/
	/*															*/
	/*			Folder Option Item Detail						*/
	/*															*/
	/************************************************************/

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_OPEN,MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS,0,
   		SHOW, NONMOVEABLE, DEFAULT, STR_GLOBAL_OPEN,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_FOLDER_OPTIONS_CREAT_FOLDER,MENU_ID_MY_FAVORITE_CUSTOMIZED_FOLDER_OPTIONS,0,
		SHOW, NONMOVEABLE, DEFAULT, STR_FMGR_FOLDER_CREATE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_MEMORY_CARD_FORMAT,MENU_ID_MY_FAVORITE_MEMORY_CARD_OPTIONS,0,
        SHOW, NONMOVEABLE, DEFAULT, STR_FMGR_FORMAT,0));

#if defined(__J2ME__)
    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_OPEN,MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS,0,
        SHOW, NONMOVEABLE, DEFAULT, STR_GLOBAL_OPEN,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS_OPEN,MENU_ID_MY_FAVORITE_GPLUSGAME_OPTIONS,0,
        SHOW, NONMOVEABLE, DEFAULT, STR_GLOBAL_OPEN,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SETTING,MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS,0,
        SHOW, NONMOVEABLE, DEFAULT, STR_ID_FNG_SETTING_JAVA,0));

  #ifdef OGDR_SECURITY_SETTING
    ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS_SECURITY,MENU_ID_MY_FAVORITE_JAVABOX_OPTIONS,0,
        SHOW, NONMOVEABLE, DEFAULT, STR_ID_FNG_SECURITY_JAVA,0));
  #endif

#endif

	/************************************************************/
	/*															*/
	/*			Editor Option									*/
	/*															*/
	/************************************************************/
	ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_EDITOR_OPTION,0,2,
		MENU_ID_MY_FAVORITE_EDITOR_DONE,
		MENU_ID_MY_FAVORITE_INPUT_METHOD,
		SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST,STR_GLOBAL_OPTIONS,IMG_GLOBAL_OPTIONS));

	ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_EDITOR_DONE,MENU_ID_MY_FAVORITE_EDITOR_OPTION,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_DONE,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_MY_FAVORITE_INPUT_METHOD,MENU_ID_MY_FAVORITE_EDITOR_OPTION,0,
		SHOW, MOVEABLEWITHINPARENT, DISP_LIST,STR_GLOBAL_INPUT_METHOD,0));


}

#endif /* __MMI_MY_FAVORITE__ */

