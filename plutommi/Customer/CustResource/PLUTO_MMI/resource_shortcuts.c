
#include "MMI_features.h"
#ifndef __DISABLE_SHORTCUTS_IMPL__

#include "GlobalMenuItems.h"
#include "MMIDataType.h"
#include "ShortcutsDefs.h"

#include "mmi_rp_all_defs.h"


/*Default List*/
#ifndef __OP12__
const MMI_MENU_ID g_mmi_shct_quick_menu_default_list[]=
{
    MENU_ID_UM_WRITE_MSG,
    MAIN_MENU_MESSAGES_MENUID,
    MITEM102_PBOOK_NEW_ENTRY,
#ifndef LOW_COST_SUPPORT                
    MITEM105_PBOOK_OWNER_NUMBER,
#endif    
    MENU_VOLUME_LEVEL,
    ORGANIZER_ALARM_MENU
};
#else
const MMI_MENU_ID g_mmi_shct_quick_menu_default_list[]=
{       
#ifdef __MMI_OP12_TOOLBAR__
    MAIN_MENU_FOR_SHORTCUTS,
#endif
    ORGANIZER_ALARM_MENU,
    ORGANIZER_CALENDER_MENU
};
#endif
const U8 g_mmi_shct_quick_menu_default_list_num = sizeof(g_mmi_shct_quick_menu_default_list)/sizeof(g_mmi_shct_quick_menu_default_list[0]);

/*Dedicated List*/
#if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
#ifdef __OP01_FWPBW__
const MMI_MENU_ID g_mmi_shct_nav_key_default_list[]=
{
    MENU_ID_UM_WRITE_MSG,
    ORGANIZER_ALARM_MENU,
    MAIN_MENU_PROFILES_MENUID,
    MITEM102_PBOOK_NEW_ENTRY
};
#elif defined(__OP12__)
const MMI_MENU_ID g_mmi_shct_nav_key_default_list[]=
{
    MAIN_MENU_PROFILES_MENUID,
    MAIN_MENU_PHONEBOOK_MENUID,
    MENU_ID_UM_WRITE_MSG,
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#else
    ORGANIZER_ALARM_MENU
#endif
};
#else
const MMI_MENU_ID g_mmi_shct_nav_key_default_list[]=
{
#ifdef __MMI_MEDIA_PLAYER__
    MENU_ID_MEDPLY_MAIN,
#elif defined(__MMI_VIDEO_PLAYER__)
    MENU_ID_VDOPLY_APP,
#else
    0,
#endif
    ORGANIZER_ALARM_MENU,
    MAIN_MENU_PROFILES_MENUID,
    MAIN_MENU_MESSAGES_MENUID
};
#endif /* __OP12__ */
#endif /*__MMI_DEDICATED_KEY_SHORTCUTS__ */
#endif /* __DISABLE_SHORTCUTS_IMPL__ */

