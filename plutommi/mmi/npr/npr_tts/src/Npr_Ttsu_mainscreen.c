/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of Shenzhen Newpolar Technology co.,Ltd. (C) 2010
*
*  --------------------
*******************************************************************************
 * Filename:
 * ---------
 *  npr_ttsu_mainscreen.c
 *
 * Author:
 * -------
 * huyucheng
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is record changes history! 
 * 
 * DATE                     EDIT       DESCRIPTION
 *2012/4/11          hyc       创建文件
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __NPR_TTS_UI__
#include "MMI_include.h"
#include "ConnectivityResDef.h"
#include "SettingProfile.h"
#include "IdleAppResDef.h"
#include "IdleAppDef.h"
#include "FileManagerGProt.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "GlobalMenuItems.h"
#include "ProfilesAppGprot.h"
#include "custom_phb_config.h"

#include "inlinecuigprot.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"
#include "CommonScreens.h"

#include "Npr_Ttsu_gprot.h"
#include "Npr_Ttsu_mainscreen.h"

#include "Mmi_rp_app_npr_tts_def.h"

#ifdef __NPR_SIRI_TTS__
#include "Mmi_rp_app_npr_aitalk_def.h "
#endif
static MMI_ID gActiveNprTTsGroup;
static MMI_ID gActiveNprTTsScreen;

#if 1
NPR_TTS_read_flag Npr_Tts_flag_cntx;
#endif  //hyc
MMI_BOOL g_npr_msdc_present = MMI_FALSE;

extern const U16 gIndexIconsImageList[];
extern U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];


#ifdef __MMI_MAINLCD_240X320__
NPR_AITALK_AREA npr_tts_playtime_tip = {18, 189, 222, 269};
NPR_AITALK_TXT npr_tts_playtime_info = {28, 190, 183};
#elif defined ( __MMI_MAINLCD_320X480__)
NPR_AITALK_AREA npr_tts_playtime_tip = {29, 285, 299, 400};
NPR_AITALK_TXT npr_tts_playtime_info = {41, 299, 220};
#elif defined ( __MMI_MAINLCD_320X240__)
NPR_AITALK_AREA npr_tts_playtime_tip = {29, 115, 299, 213};
NPR_AITALK_TXT npr_tts_playtime_info = {41, 299, 220};
#elif defined (__MMI_MAINLCD_240X400__)
NPR_AITALK_AREA npr_tts_playtime_tip = {18, 241, 222,334 };
NPR_AITALK_TXT npr_tts_playtime_info = {28, 190, 183};
#elif defined (__MMI_MAINLCD_176X220__)
NPR_AITALK_AREA npr_tts_playtime_tip = {18, 189, 222, 269};
NPR_AITALK_TXT npr_tts_playtime_info = {28, 190, 183};
#else
NPR_AITALK_AREA npr_tts_playtime_tip = {18, 189, 222, 269};
NPR_AITALK_TXT npr_tts_playtime_info = {28, 190, 183};
#endif

extern void redraw_softkey(WGUI_SOFTKEY_ENUM key);

void NPR_TTS_MenuScrenHighlight(void);
void NPR_TTS_ChangeIncomingCall(void);
void NPR_TTS_ChangeKeyPlay(void);
void NPR_TTS_ChangeAutoPlayTime(void);
void NPR_TTS_SmsAutoHighlight(void);
void NPR_TTS_SmsRecvHighlight(void);
void NPR_TTS_HandPlayTimeHighlight(void);
void NPR_TTS_AutoPlayTimeHighlight(void);


#ifdef __NPR_DIALECT_TTS__
U8 NPR_TTS_GetVoiceSel(void);
#endif
U8 NPR_TTS_GetVolume(void);
U8 NRR_TTS_get_read_nv(void);

//extern void NPR_TTS_UseInit(void);



MMI_BOOL NPR_msdc_is_present(void)
{
    return g_npr_msdc_present;
}
void Npr_msdc_init(void)
{

       if(FS_NO_ERROR == FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1,
        FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM))
        g_npr_msdc_present = MMI_TRUE;
	  else
	  g_npr_msdc_present = MMI_FALSE;
	
}


extern void IFLYTEK_TTSInit(void);

void NPR_TTS_init_nvdata(void)
{
   Npr_Tts_flag_cntx.read_flag= NRR_TTS_get_read_nv();		
   Npr_Tts_flag_cntx.vollevel  = NPR_TTS_GetVolume();
   #ifdef __NPR_DIALECT_TTS__
   Npr_Tts_flag_cntx.voicesel = NPR_TTS_GetVoiceSel();
   #endif
   Npr_Tts_set_vol_lev(Npr_Tts_flag_cntx.vollevel);
   Npr_msdc_init();
   //IFLYTEK_TTSInit();
   //NPR_TTS_UseInit();  //hyc.debug
}

U8 NRR_TTS_get_read_nv(void)
{
    S16 error;
    U8 r = 0;
    ReadValue(NVRAM_NPR_TTS_FLAG,&r,DS_BYTE,&error);
    if(0xFF == r)
    {
          r = 0x7F;
    }
    return r;	
}

void NPR_TTS_set_flag(NPR_TTS_type type, MMI_BOOL value)
{
    S16 error;
    if(type < NPR_TTS_FLAG_MAX && value != ((Npr_Tts_flag_cntx.read_flag >> type) & 1))
    {
        Npr_Tts_flag_cntx.read_flag &= ~(1 << type);
       if(value)
           Npr_Tts_flag_cntx.read_flag |= value << type;
    }

    WriteValue(NVRAM_NPR_TTS_FLAG,&Npr_Tts_flag_cntx.read_flag,DS_BYTE,&error);
	
}
MMI_BOOL NPR_TTS_get_read_flag(NPR_TTS_type type)
{
	return   (Npr_Tts_flag_cntx.read_flag >> type) &0x01;
}

static void NPR_TTS_RedrawScreen(void)
{
	gdi_handle handle;
	gui_cancel_timer(NPR_TTS_RedrawScreen);
	gdi_layer_lock_frame_buffer();
	gdi_layer_get_base_handle(&handle); 
	gdi_layer_push_and_set_active(handle);
	gui_draw_rectangle(npr_tts_playtime_tip.x1, npr_tts_playtime_tip.y1, npr_tts_playtime_tip.x2, npr_tts_playtime_tip.y2, gui_color(143, 138, 138));
	gui_fill_rectangle(npr_tts_playtime_tip.x1 + 1, npr_tts_playtime_tip.y1 + 1, npr_tts_playtime_tip.x2 - 1, npr_tts_playtime_tip.y2 - 1, gui_color(56, 50, 50));
	//hyc.debug  NPR_Pub_ShowLimitLineText(npr_tts_playtime_info.x, npr_tts_playtime_info.y, npr_tts_playtime_info.w, gui_color(255,255,255), (UI_string_type)GetString(STR_ID_TTS_TIME_READ_TIPS), FALSE);
	gdi_layer_pop_and_restore_active();
	gdi_layer_unlock_frame_buffer();
	gui_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
}

static void NPR_TTS_ExecuteCurrHiliteHandler(S32 hiliteid)
{
	U32 i = 0;
	ExecuteCurrHiliteHandler(hiliteid);
	gui_start_timer(300,NPR_TTS_RedrawScreen);
}

void NPR_TTS_ExitMainScreen(void)
{

}

void NPR_TTS_EntryMainScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *ItemType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */

    EntryNewScreen(SCR_ID_TTS_SETTING_MIAN, NPR_TTS_ExitMainScreen, NPR_TTS_EntryMainScreen, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_TTS_SETTING_MIAN);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_TTS_SETTING);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_TTS_SETTING);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU_ID_TTS_SETTING, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_TTS_SETTING);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_ID_TTS_SETTING, ItemType);

#ifdef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    if (!guiBuffer)
    {
        mmi_phnset_2line_read_setting();
    }
    is_inline_menu_exist = 1;
    wgui_set_pfn_to_get_display_style(mmi_phnset_2line_get_display_style);
    wgui_set_pfn_to_get_current_menu_item_properties(mmi_phnset_2line_get_menuitem_properties);
#endif /* __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__ */ 

    ShowCategory52Screen(
        //  STR_ID_NPR_TTS_MENU2,
        STR_ID_TTS_SETTING_MENU_TEXT,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        ItemType,
        0,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifndef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif 

}

void NPR_TTS_MainScreenHighlight(void)
{
        SetLeftSoftkeyFunction(NPR_TTS_EntryMainScreen, KEY_EVENT_UP);
        SetKeyHandler(NPR_TTS_EntryMainScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

void NPR_TTS_MenuStatus_Hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_MENU))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_MenuChangeStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    if (NPR_TTS_get_read_flag(NPR_TTS_MENU ))
    {
    NPR_TTS_set_flag(NPR_TTS_MENU,MMI_FALSE);
    }
    else
    {
     NPR_TTS_set_flag(NPR_TTS_MENU,MMI_TRUE);
    }
    if (NPR_TTS_get_read_flag(NPR_TTS_MENU))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
   
    RedrawCategoryFunction();
    NPR_TTS_MenuScrenHighlight();
}

void NPR_TTS_MenuScrenHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_MENU))
    {
    	mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_MenuChangeStatus, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

U8 NPR_TTS_GetVolume(void)
{
        S16 error;
        U8 r = 0;
        ReadValue(NVRAM_TTS_VOL_LEVEL,&r,DS_BYTE,&error);

        if(0xFF == r)
        {
                r = 6;
        }
        return r;
}

void NPR_TTS_WriteVolumeNV(U8 r)
{
	S16 error;
	
       WriteValue(NVRAM_TTS_VOL_LEVEL,&r,DS_BYTE,&error);
	 Npr_Tts_set_vol_lev(r);
}



#ifdef __NPR_DIALECT_TTS__
U8 NPR_TTS_GetVoiceSel(void)
{
        S16 error;
        U8 r = 0;
        ReadValue(NVRAM_TTS_VOICE_SEL,&r,DS_BYTE,&error);
	 if(0xFF == r)
        {
                r = 0;
        }
        return r;
}

void NPR_TTS_WriteVolumeSelNV(U8 value)
{
       S16 error;
       WriteValue(NVRAM_TTS_VOICE_SEL,&value,DS_BYTE,&error);
}
#endif

void NPR_TTS_IncomingCallHint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_INCOMING_CALL))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_IncomingCallHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_INCOMING_CALL))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeIncomingCall, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void NPR_TTS_ChangeIncomingCall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (NPR_TTS_get_read_flag(NPR_TTS_INCOMING_CALL))
    {
         NPR_TTS_set_flag(NPR_TTS_INCOMING_CALL, MMI_FALSE);
    }
     else
     {
         NPR_TTS_set_flag(NPR_TTS_INCOMING_CALL, MMI_TRUE);
     }
	
    if (NPR_TTS_get_read_flag(NPR_TTS_INCOMING_CALL))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
    NPR_TTS_IncomingCallHighlight();
}

void NPR_TTS_KeyplayHint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_KEYPAD ))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}


void NPR_TTS_KeyplayHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_KEYPAD ))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeKeyPlay, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void NPR_TTS_ChangeKeyPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();
    if (NPR_TTS_get_read_flag(NPR_TTS_KEYPAD ))
    {
    NPR_TTS_set_flag(NPR_TTS_KEYPAD, MMI_FALSE);
    }
    else
    {
    NPR_TTS_set_flag(NPR_TTS_KEYPAD, MMI_TRUE);
    }

    /* Store the updated Value */
    if (NPR_TTS_get_read_flag(NPR_TTS_KEYPAD ))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
   NPR_TTS_KeyplayHighlight();
}

void NPR_TTS_AutoPlayTimeHint(U16 index)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_AUTO))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_AutoPlayTimeHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_AUTO))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        Category52ChangeItemDescription(index, hintData[index]);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    //NPR_TTS_RedrawScreen();	

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeAutoPlayTime, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

void NPR_TTS_ChangeAutoPlayTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_AUTO))
    {
    NPR_TTS_set_flag(NPR_TTS_TIME_AUTO, MMI_FALSE);
    }
     else
    {
        NPR_TTS_set_flag(NPR_TTS_TIME_AUTO, MMI_TRUE);
    }
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_AUTO))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
    NPR_TTS_AutoPlayTimeHighlight();
}


void NPR_TTS_AboutScreenEntry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
	U8 *guiBuffer; 
	MMI_BOOL entry_ret = MMI_FALSE;
void * ptr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_TTS_ABOUT, NULL, NPR_TTS_AboutScreenEntry, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_TTS_ABOUT);
	
    buffer = GetString(STR_ID_NPR_TTS_ABOUT_INFO);
    bufferSize = mmi_ucs2strlen(buffer);

    ShowCategory74Screen(
        STR_ID_NPR_TTS_ABOUT,
        NULL,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) buffer,
        bufferSize,
        guiBuffer);

    /* go back to game menu */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
void NPR_TTS_AboutScreenHighlight(void)
{
    SetLeftSoftkeyFunction(NPR_TTS_AboutScreenEntry, KEY_EVENT_UP);
    SetKeyHandler(NPR_TTS_AboutScreenEntry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}

typedef enum
{
    NPR_TTS_VOL_SETTING_CAPTION,
    NPR_TTS_VOL_SETTING_SELECTOR,
    NPR_TTS_VOL_SETTING_COUNT
} npr_tts_vol_setting_enum;

static const U16 npr_tts_vol_setting_str[] =
{
        STR_GLOBAL_1,
        STR_GLOBAL_2,
        STR_GLOBAL_3,
        STR_GLOBAL_4,
        STR_GLOBAL_5,
        STR_GLOBAL_6,
        STR_GLOBAL_7,
        STR_GLOBAL_8,
        STR_GLOBAL_9
};

static const cui_inline_item_caption_struct mmi_npr_tts_vol_setting_caption = 
{
    STR_GLOBAL_VOLUME
};
static const cui_inline_item_select_struct mmi_npr_tts_vol_setting_selector = 
{
    7, 0, (U16 *)&npr_tts_vol_setting_str[0]
};

static const cui_inline_set_item_struct mmi_npr_tts_setting_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + NPR_TTS_VOL_SETTING_CAPTION,	    CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + NPR_TTS_VOL_SETTING_CAPTION,   (void*)&mmi_npr_tts_vol_setting_caption},
    {CUI_INLINE_ITEM_ID_BASE + NPR_TTS_VOL_SETTING_SELECTOR,	    CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                   (void*)&mmi_npr_tts_vol_setting_selector}
};

static const cui_inline_struct mmi_motion_aitalk_vol_setting_inline_cntx = 
{
    NPR_TTS_VOL_SETTING_COUNT,
    STR_ID_NPR_TTS_VOL,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_npr_tts_setting_inline_item 
};
static MMI_ID NPR_TTS_display_popup(mmi_id gid, UI_string_type string, mmi_event_notify_enum type, S32 user_data)
{
    MMI_ID result;
    mmi_group_node_struct node_info;
    mmi_popup_property_struct property;

    mmi_frm_group_get_info (gid, &node_info);
    mmi_popup_property_init(&property);
    
    property.user_tag = (void*)user_data;
    property.parent_id = gid;
    property.callback = (mmi_proc_func)node_info.proc;
    
    result = mmi_popup_display(string, type, &property);

    return result;
}

typedef enum
{
    NPR_TTS_POPUP_RESULT_ACTION_NONE = 0,
    NPR_TTS_POPUP_RESULT_ACTION_CLOSE_EDIT_GROUP,
    NPR_TTS_POPUP_RESULT_ACTION_CLOSE_VOL_GROUP,
    NPR_TTS_POPUP_RESULT_ACTION_ALL
} npr_tts_popup_result_action_enum;

static void NPR_TTS_vol_setting_done_hdlr(U32 gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 mmi_popup_property_struct callback_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   NPR_TTS_WriteVolumeNV(Npr_Tts_flag_cntx.vollevel);
   NPR_TTS_display_popup(NULL, (UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NPR_TTS_POPUP_RESULT_ACTION_NONE);
   mmi_frm_group_close(SCR_ID_TTS_VOLUME_SET); 	 
}

static void NPR_TTS_vol_setting_change_item_content(cui_event_inline_notify_struct *notify)
{
    switch(notify->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    case NPR_TTS_VOL_SETTING_SELECTOR:
        Npr_Tts_flag_cntx.vollevel = notify->param;
        break;
    }
}
static mmi_ret NPR_TTS_vol_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        /**********************Inline CUI event*************************/
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
            if (notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                NPR_TTS_vol_setting_change_item_content(notify);
            }
        }
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        break;
        
    case EVT_ID_CUI_INLINE_SET_KEY:
        break;
        
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            NPR_TTS_vol_setting_done_hdlr(SCR_ID_TTS_VOLUME_SET);
        }
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
	    Npr_Tts_flag_cntx.vollevel = NPR_TTS_GetVolume();			
            cui_inline_close(inline_evt->sender_id);	
        }
        break;
    
    case EVT_ID_POPUP_QUIT:
        if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)NPR_TTS_POPUP_RESULT_ACTION_CLOSE_VOL_GROUP)
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            mmi_frm_group_close(SCR_ID_TTS_VOLUME_SET);
        }
        break;
    }

    return MMI_RET_OK;
}
static void NPR_TTS_vol_setting_init_inline_item_value(MMI_ID inline_id)
{
   	S32 temp_num =0 ;
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + NPR_TTS_VOL_SETTING_SELECTOR, 
        (void *)Npr_Tts_flag_cntx.vollevel);
}
void NPR_TTS_VolumeScreenEntry(void)
{
    MMI_ID inline_id = GRP_ID_INVALID;
    Npr_Tts_flag_cntx.vollevel = NPR_TTS_GetVolume();
    mmi_frm_group_create(GRP_ID_ROOT, SCR_ID_TTS_VOLUME_SET, NPR_TTS_vol_setting_group_proc, (void*)NULL); 
    mmi_frm_group_enter(SCR_ID_TTS_VOLUME_SET, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(SCR_ID_TTS_VOLUME_SET, &mmi_motion_aitalk_vol_setting_inline_cntx);
    NPR_TTS_vol_setting_init_inline_item_value(inline_id);
    cui_inline_set_title_icon(inline_id, NULL);
    cui_inline_run(inline_id);
}

void NPR_TTS_VolumeScreenHighlight(void)
{
    SetLeftSoftkeyFunction(NPR_TTS_VolumeScreenEntry, KEY_EVENT_UP);
    SetKeyHandler(NPR_TTS_VolumeScreenEntry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


static void NPR_TTS_SaveScreen()
{
   gActiveNprTTsGroup = mmi_frm_group_get_active_id() ;
   gActiveNprTTsScreen = mmi_frm_scrn_get_active_id() ; 
}

static mmi_ret NPR_TTS_PopupCallback(mmi_event_struct *param)
{    
	 return mmi_frm_scrn_close(gActiveNprTTsGroup, gActiveNprTTsScreen);
}
#if defined ( __MMI_DUAL_SIM_SINGLE_CALL__)&&defined (__NPR_SIRI_TTS__)
#include "NwInfoSrvGprot.h"
static U8 s_CurrSimSelectIndex = 0;

U8 NPR_TTS_ReadSIMSelFromNV(void)
{
	S16 error;
	byte r = 0;
	ReadValue(NVRAM_NPR_SIMSEL,&r,DS_BYTE,&error);

	if(0xFF == r)
	{
	        r = 0;
	}
	return r;
}

void NPR_TTS_WriteSIMSelFromNV(byte r)
{
	S16 error;	
	WriteValue(NVRAM_NPR_SIMSEL,&r,DS_BYTE,&error);
}

void NPR_TTS_SIMSelectIndex(S32 index)
{
	s_CurrSimSelectIndex = (U8) index;
	return;
}

void NPR_TTS_SIMSelectHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data;
    S16 error;
    U16 index;
    mmi_popup_property_struct callback_popup;
	 U16 StringId = STR_GLOBAL_DONE;
	 UI_character_type notice[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(s_CurrSimSelectIndex == 0)	
	{
		if(srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
		{
			s_CurrSimSelectIndex = 1;
			//卡1 目前不能用				            
	              kal_wsprintf(notice, "%w%w", (UI_string_type)GetString(STR_ID_NPR_TTS_SIM1), (UI_string_type)GetString(STR_ID_NPR_TTS_FORBID_USE));			
		}
		else
		{
		    StringId = STR_ID_NPR_TTS_SIM1;	
		    //JD_PUB_eCtrlSimID(jdFALSE,JD_PUB_SIM_ID_1);	
		}
	}
	else
	{
		if(srv_nw_info_get_service_availability(MMI_SIM2) != SRV_NW_INFO_SA_FULL_SERVICE)
		{
			s_CurrSimSelectIndex = 0;
			//卡2 目前不能用
			StringId = STR_GLOBAL_DONE;
			kal_wsprintf(notice, "%w%w", (UI_string_type)GetString(STR_ID_NPR_TTS_SIM2), (UI_string_type)GetString(STR_ID_NPR_TTS_FORBID_USE));
		}
		else
		{
		    StringId = STR_ID_NPR_TTS_SIM2;	
		    //JD_PUB_eCtrlSimID(jdFALSE,JD_PUB_SIM_ID_2);	
		}
	}

    NPR_TTS_SaveScreen();
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = NPR_TTS_PopupCallback;

    if(StringId != STR_GLOBAL_DONE)
    {    	
	   NPR_TTS_WriteSIMSelFromNV(s_CurrSimSelectIndex);	
       mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
    }
    else
	  mmi_popup_display((WCHAR*)notice, MMI_EVENT_WARNING, &callback_popup);	
}

 U8  NPR_TTS_CheckSim(void)
{
	U8 selSim = NPR_TTS_ReadSIMSelFromNV();

	if(selSim == 0 && srv_nw_info_get_service_availability(MMI_SIM1) != SRV_NW_INFO_SA_FULL_SERVICE)
	{
		if(srv_nw_info_get_service_availability(MMI_SIM2) == SRV_NW_INFO_SA_FULL_SERVICE)
		{
			NPR_TTS_WriteSIMSelFromNV(1);
			selSim = 1;
		}
	}
	else if(selSim == 1 && srv_nw_info_get_service_availability(MMI_SIM2) != SRV_NW_INFO_SA_FULL_SERVICE)
	{
		if(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE)
		{
			NPR_TTS_WriteSIMSelFromNV(0);
			selSim = 0;
		}
	}

	return selSim;
}

void  NPR_TTS_SIMSelectScreen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 *pGuiBuffer;
	U8 *volumeSelectList[IV_TTS_RESPACK_NUM]; /* have to keep it here for memory reduction */ 
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_frm_scrn_enter(SCR_ID_NPR_AITAKL_SET, SCR_ID_NPR_AITALK_SIM_SEL, NULL, NPR_TTS_SIMSelectScreen, 0);
	pGuiBuffer = mmi_frm_scrn_get_gui_buf(SCR_ID_NPR_AITAKL_SET, SCR_ID_NPR_AITALK_SIM_SEL);
	RegisterHighlightHandler(NPR_TTS_SIMSelectIndex);   

	NPR_TTS_CheckSim();

	s_CurrSimSelectIndex = NPR_TTS_ReadSIMSelFromNV();		

	volumeSelectList[0] = (U8*)GetString(STR_ID_NPR_TTS_SIM1);
	volumeSelectList[1] = (U8*)GetString(STR_ID_NPR_TTS_SIM2);

	ShowCategory36Screen(
		STR_ID_NPR_TTS_SET_SIM,
		0,
		STR_GLOBAL_OK,
		IMG_GLOBAL_OK,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		2,
		(U8 **) volumeSelectList,
		s_CurrSimSelectIndex,
		pGuiBuffer);

	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetLeftSoftkeyFunction(NPR_TTS_SIMSelectHandler, KEY_EVENT_UP);
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(NPR_TTS_SIMSelectHandler, KEY_EVENT_UP);
	register_center_softkey_to_enter_key();
	//redraw_softkey(MMI_CENTER_SOFTKEY);	
	return;
}

static mmi_ret NPR_TTS_EntrySIMSelectProc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

void NPR_TTS_EntrySIMSelect(void)
{
    mmi_frm_group_create(GRP_ID_ROOT, SCR_ID_NPR_AITAKL_SET, NPR_TTS_EntrySIMSelectProc, NULL);
    mmi_frm_group_enter(SCR_ID_NPR_AITAKL_SET, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        SCR_ID_NPR_AITAKL_SET, 
        SCR_ID_NPR_AITALK_SIM_SEL,
        NPR_TTS_SIMSelectScreen,
        NULL);
}

void NPR_TTS_SIMSelect(void)
{
    SetLeftSoftkeyFunction(NPR_TTS_EntrySIMSelect, KEY_EVENT_UP);
    SetKeyHandler(NPR_TTS_EntrySIMSelect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    
}
#else
void NPR_TTS_SIMSelect(void)
{}
#endif

#ifdef __NPR_DIALECT_TTS__
extern void NPR_AiTalk_CheckNotice(void);/*yaoshifei add for down res 12/04/25*/

void NPR_TTS_VoiceSelectIndex(S32 index)
{
	Npr_Tts_flag_cntx.voicesel = (U8) index;
	return;
}

void NPR_TTS_VoiceSelectHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 data;
    S16 error;
    U16 index;
    mmi_popup_property_struct callback_popup;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    NPR_TTS_WriteVolumeSelNV(Npr_Tts_flag_cntx.voicesel);
 //NPR_TTS_SetVolumeResSelect(Npr_Tts_flag_cntx.voicesel);  //hyc.debug
    NPR_TTS_SaveScreen();
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = NPR_TTS_PopupCallback;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
	NPR_AiTalk_CheckNotice();/*yaoshifei add for down res 12/04/25*/
}

void  NPR_TTS_VoiceSelectScreen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 *pGuiBuffer;
	U8 *volumeSelectList[IV_TTS_RESPACK_NUM]; /* have to keep it here for memory reduction */ 

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_frm_scrn_enter(SCR_ID_TTS_SETTING_MIAN, SCR_ID_TTS_VOICE_SEL, NULL, NPR_TTS_VoiceSelectScreen, 0);
	pGuiBuffer = mmi_frm_scrn_get_gui_buf(SCR_ID_TTS_SETTING_MIAN, SCR_ID_TTS_VOICE_SEL);
	RegisterHighlightHandler(NPR_TTS_VoiceSelectIndex);   

	/* go back to game menu */
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

	Npr_Tts_flag_cntx.voicesel = NPR_TTS_GetVoiceSel();		

	volumeSelectList[0] = (U8*)GetString(STR_ID_NPR_TTS_FEMALE);
	volumeSelectList[1] = (U8*)GetString(STR_ID_NPR_TTS_GD);
	volumeSelectList[2] = (U8*)GetString(STR_ID_NPR_TTS_SC);
	volumeSelectList[3] = (U8*)GetString(STR_ID_NPR_TTS_DB);
	volumeSelectList[4] = (U8*)GetString(STR_ID_NPR_TTS_MALE);
	volumeSelectList[5] = (U8*)GetString(STR_ID_NPR_TTS_CHILDREN);	
	ShowCategory36Screen(
		STR_ID_NPR_TTS_VOLSEL,
		0,
		STR_GLOBAL_OK,
		IMG_GLOBAL_OK,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		IV_TTS_RESPACK_NUM,
		(U8 **) volumeSelectList,
		Npr_Tts_flag_cntx.voicesel,
		pGuiBuffer);
	
	SetLeftSoftkeyFunction(NPR_TTS_VoiceSelectHandler, KEY_EVENT_UP);
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(NPR_TTS_VoiceSelectHandler, KEY_EVENT_UP);
	register_center_softkey_to_enter_key();
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	//redraw_softkey(MMI_CENTER_SOFTKEY);	
	return;
}

static mmi_ret NPR_TTS_EntryVoiceSelectProc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

void NPR_TTS_VoiceSelectEntry(void)
{
    mmi_frm_group_create(GRP_ID_ROOT, SCR_ID_TTS_SETTING_MIAN, NPR_TTS_EntryVoiceSelectProc, NULL);
    mmi_frm_group_enter(SCR_ID_TTS_SETTING_MIAN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_first_enter(
        SCR_ID_TTS_SETTING_MIAN, 
        SCR_ID_TTS_VOICE_SEL,
        NPR_TTS_VoiceSelectScreen,
        NULL);
}

void NPR_TTS_VoiceSelectHighlight(void)
{
    SetLeftSoftkeyFunction(NPR_TTS_VoiceSelectEntry, KEY_EVENT_UP);
    SetKeyHandler(NPR_TTS_VoiceSelectEntry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    
}
#endif

void NPR_TTS_EntrySmsReadSettingScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *ItemType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_TTS_SMS_READ_SET, NULL, NPR_TTS_EntrySmsReadSettingScreen, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_TTS_SMS_READ_SET);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_TTS_SMS_READ_SET);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_TTS_SMS_READ_SET);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU_ID_TTS_SMS_READ_SET, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_TTS_SMS_READ_SET);

    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_ID_TTS_SMS_READ_SET, ItemType);

#ifdef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    if (!guiBuffer)
    {
        mmi_phnset_2line_read_setting();
    }
    is_inline_menu_exist = 1;
    wgui_set_pfn_to_get_display_style(mmi_phnset_2line_get_display_style);
    wgui_set_pfn_to_get_current_menu_item_properties(mmi_phnset_2line_get_menuitem_properties);
#endif /* __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__ */ 

    ShowCategory52Screen(
        STR_ID_NPR_TTS_SMS_NOTICE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        ItemType,
        0,
        0,
        guiBuffer);

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifndef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif 

}


void NPR_TTS_SmsReadSetingHighlight(void)
{

        SetLeftSoftkeyFunction(NPR_TTS_EntrySmsReadSettingScreen, KEY_EVENT_UP);
        SetKeyHandler(NPR_TTS_EntrySmsReadSettingScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

}


void NPR_TTS_SmsRecvHint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_RECV_SMS))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_ChangeSmsRecv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if(NPR_TTS_get_read_flag(NPR_TTS_RECV_SMS ))
    {
    NPR_TTS_set_flag(NPR_TTS_RECV_SMS , MMI_FALSE);
    }
    else
    {
     NPR_TTS_set_flag(NPR_TTS_RECV_SMS , MMI_TRUE);
    }

    if (NPR_TTS_get_read_flag(NPR_TTS_RECV_SMS))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
    NPR_TTS_SmsRecvHighlight();
}

void NPR_TTS_SmsRecvHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_RECV_SMS))
    {
    	mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
    mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeSmsRecv, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


void NPR_TTS_SmsAutoReadHint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_SMS_AUTO))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_ChangeSmsAuto(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (NPR_TTS_get_read_flag(NPR_TTS_SMS_AUTO))
    {
    NPR_TTS_set_flag(NPR_TTS_SMS_AUTO, MMI_FALSE);
    }
    else
    {
        NPR_TTS_set_flag(NPR_TTS_SMS_AUTO, MMI_TRUE);
    }

    /* Store the updated Value */
    if (NPR_TTS_get_read_flag(NPR_TTS_SMS_AUTO))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
    NPR_TTS_SmsAutoHighlight();
}
#if defined(__NPR_TTS_UI__)//&& ( !defined(__NPR_SIRI_TTS__))
void NPR_TTS_ExitPlayTimeScreen(void)
{
	gui_cancel_timer(NPR_TTS_RedrawScreen);
}
void NPR_TTS_PlayTimeScreenEntry(void)
{
#if 0
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];    /* Stores the strings id of submenus returned */
    U16 nNumofItem;                     /* Stores no of children in the submenu */
    U16 nDispAttribute;                 /* Stores display attribue */
    U8 *guiBuffer;                      /* Buffer holding history data */
    U8 *ItemType[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    EntryNewScreen(SCR_ID_TTS_TIME_READ_SET, NPR_TTS_ExitPlayTimeScreen, NPR_TTS_PlayTimeScreenEntry, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = GetCurrGuiBuffer(SCR_ID_TTS_TIME_READ_SET);

    /* 3. Retrieve no of child of menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    nNumofItem = GetNumOfChild_Ext(MENU_ID_TTS_TIME_READ_SET);

    /* 4. Get attribute of menu to be displayed */
    nDispAttribute = GetDispAttributeOfItem(MENU_ID_TTS_TIME_READ_SET);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* diamond, 2005/07/01 add _Ext to menu item functions */
    GetSequenceStringIds_Ext(MENU_ID_TTS_TIME_READ_SET, nStrItemList);

    /* 6 Set current parent id */
    SetParentHandler(MENU_ID_TTS_TIME_READ_SET);


    /* 7 Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(NPR_TTS_ExecuteCurrHiliteHandler);		

    /* 8 Construct the Hints List */
    ConstructHintsList(MENU_ID_TTS_TIME_READ_SET, ItemType);

#ifdef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    if (!guiBuffer)
    {
        mmi_phnset_2line_read_setting();
    }
    is_inline_menu_exist = 1;
    wgui_set_pfn_to_get_display_style(mmi_phnset_2line_get_display_style);
    wgui_set_pfn_to_get_current_menu_item_properties(mmi_phnset_2line_get_menuitem_properties);
#endif /* __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__ */ 

    ShowCategory52Screen(
        STR_ID_TTS_TIME_READ_SET,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        ItemType,
        0,
        0,
        guiBuffer);

	NPR_TTS_RedrawScreen();

    /* 9.Register function with right softkey */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifndef __MMI_PHNSET_TWO_LINE_MENUITEM_DISPLAY__
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif 
#endif
}

void NPR_TTS_PlayTimeScreenHighlight(void)
{
        SetLeftSoftkeyFunction(NPR_TTS_PlayTimeScreenEntry, KEY_EVENT_UP);
        SetKeyHandler(NPR_TTS_PlayTimeScreenEntry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif
void NPR_TTS_SmsAutoHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_SMS_AUTO))
    {
    	mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeSmsAuto, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void NPR_TTS_HandPlayTimeHint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_HAND))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
    }
}

void NPR_TTS_ChangeHandPlayTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_HAND))
    {
        NPR_TTS_set_flag(NPR_TTS_TIME_HAND, MMI_FALSE);
    }
    else
    {
    NPR_TTS_set_flag(NPR_TTS_TIME_HAND, MMI_TRUE);
    }
	
    /* Store the updated Value */
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_HAND))
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    
    RedrawCategoryFunction();
    NPR_TTS_HandPlayTimeHighlight();
}

void NPR_TTS_HandPlayTimeHighlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* Set the LSK to Off when Auto Update is ON */
    if (NPR_TTS_get_read_flag(NPR_TTS_TIME_HAND))
    {
    	 mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(index, hintData[index]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }

    /* Change right soft key icon and label */
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* Change left soft key icon and label */
    SetKeyHandler(0, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    NPR_TTS_RedrawScreen();	

    /* Register function for left soft key */
    SetLeftSoftkeyFunction(NPR_TTS_ChangeHandPlayTime, KEY_EVENT_UP);

    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void NPR_TTS_SetHandPlayTimeKey(void)
{
     ClearKeyHandler(KEY_DOWN_ARROW,KEY_LONG_PRESS);
     SetKeyHandler(NPR_TTS_PlayAnyTime, KEY_DOWN_ARROW, KEY_LONG_PRESS);	
}
#ifdef  __NPR_SIRI_TTS__ //yaoshifei add  for 
extern void NPR_AiTalk_CreatFile(void);
extern  void NPR_AiTalk_DownRes(void);

void NPR_TTS_ResourcesDown()
{
	NPR_AiTalk_CreatFile();
	NPR_AiTalk_DownRes();	
}
void NPR_TTS_ResourcesDownHighlight()//ysfeagle add 12/07/11
{

       SetLeftSoftkeyFunction(NPR_TTS_ResourcesDown, KEY_EVENT_UP);
}
#endif
#endif

