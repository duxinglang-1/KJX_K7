extern "C"
{
    #include "mmi_features.h"
    #include "MMIDatatype.h"
    #include "Wgui_categories_util.h"
    #include "NotificationGprot.h"
    #include "NotificationSettingSrvGprot.h"
    #include "gui_typedef.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_frm_events_gprot.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_categories_text_viewer.h"
    #include "Wgui_categories.h"
}
#include "vfx_config.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_app_launcher.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "vtst_rt_nmgr.h"
#include "vtst_rt_main.h"
#include "vcp_info_balloon.h"
#include "vapp_nmgr_gprot.h"
#include "mmi_rp_vapp_msg_def.h"

#if  defined(__AFX_RT_TEST__) && defined(__COSMOS_MMI_PACKAGE__)

VFX_IMPLEMENT_CLASS("VtstNmgr", VtstNmgr, VfxApp);
VFX_IMPLEMENT_CLASS("VtstNmgrScreen", VtstNmgrScreen, VfxMainScr);
VFX_IMPLEMENT_CLASS("VtstNmgrPage", VtstNmgrPage, VfxPage);

static NMGR_HANDLE g_nmgr_handle = 0;

#define MNGR_TEST_CASE_BEGING \
class VtstNmgrTestCase nmgrTestCase[] =\
{

#define NMGR_TEST_CASE_END \
};\

#define NMGR_TS(str, f)  {VFX_WSTR(str), (f)}

#define FILL_IN_ALERT_INFO(_alert_type, _status_bar_type, _popup_type) do {\
    alert_info.app_id = VAPP_EMAIL;\
    alert_info.scen_id = MMI_SCENARIO_ID_MESSAGE_WAITING;\
    alert_info.event_type = MMI_EVENT_SIM1_NEW_MSG_WAITING_VOICEMAIL;\
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;\
    alert_info.behavior_mask = _alert_type;\
    alert_info.status_bar_para.status_bar_type = _status_bar_type;\
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;\
    alert_info.status_bar_para.image.id = IMG_SI_UNREAD_VOICE;\
    alert_info.status_bar_para.display_string = (WCHAR *)preview_msg.getBuf();\
    alert_info.popup_para.popup_type = _popup_type;\
    alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;\
    alert_info.popup_para.image.id = IMG_ID_VAPP_MSG_MAIN;\
    alert_info.popup_para.popup_string = (WCHAR *)popup_msg.getBuf();\
    alert_info.popup_para.popup_button_string = (WCHAR *)button_msg.getBuf();\
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_UNREAD_VOICE;\
    }while(0)


void showPlutoScreen(const WCHAR *str, void( *f)(void *), MMI_BOOL has_status_icon);

void showUpperBalloonwithTypeinfo(void *arg);
void showUpperBalloonwithTypefailure(void *arg);
void showUpperBalloonwithTypewarning(void *arg);
void showUpperBalloonwithTypesuccess(void *arg);
void showUpperBalloonwithTypeprogress(void *arg);

void showLowerBalloonwithTypeinfo(void *arg);
void showLowerBalloonwithTypefailure(void *arg);
void showLowerBalloonwithTypewarning(void *arg);
void showLowerBalloonwithTypesuccess(void *arg);
void showLowerBalloonwithTypeprogress(void *arg);

void showSinglePreview(void *arg);
void cancelSinglePreviewStatusIcon(void *arg);
void showMultiPreview(void *arg);
extern "C" void fto_nmgr_test(void);
void previewLogicTest(void *arg);

void showLowerMultiBalloon(void *arg);
void showUpperMultiBalloon(void *arg);
void showLowerandUpperBalloon(void *arg);

void previewWithLongString(void *arg);

void balloonWithLongString(void *arg);

void previewInPlutoScreenwithOutStatusIcon(void *arg);
void previewInPlutoScreenwithStatusIcon(void *arg);

void balloonInPlutoScreenwithOutStatusIcon(void *arg);
void balloonInPlutoScreenwithStatusIcon(void *arg);

void singlePreviewBlinkicon(void *arg);
void blinkIcon(void *arg);
void balloon_position_test(void *arg);
void status_icon_get_area_test(void *arg);

void status_icon_area_test(void *arg);

void test_upper_balloon_position_change_remove(void *arg);

void test_hide_status_icon_balloon(void *arg);
void test_upper_balloon_position_change_add(void *arg);

void test_upper_balloon_disappearwith_icon(void *arg);
void test_upper_balloon_first_position(void *arg);
void test_vapp_nmgr_global_popup_show_confirm_one_button_id(void *para);
void test_vapp_nmgr_global_popup_show_confirm_two_button_id(void *para);
void test_vapp_nmgr_global_popup_show_command_id(void *para);
void test_vapp_nmgr_global_popup_show_confirm_one_button_str(void *para);
void test_vapp_nmgr_global_popup_show_confirm_two_button_str(void *para);
void test_vapp_nmgr_global_popup_show_command_str(void *para);
void MAUI_03079353_1(void *para);
void MAUI_03079353_2(void *para);
void MAUI_03079353_3(void *para);
void MAUI_03079353_4(void *para);
void test_nss_show_one_button_popup(void *arg);
void test_nss_show_two_button_popup(void *arg);
void test_nss_show_text_preivew(void *arg);
void test_nss_show_balloon(void *arg);
void test_nss_show_none(void *arg);
void test_nss_cancel(void *arg);
void test_nss_popup_launch_app(void *arg);
void test_nss_text_preview_launch_app(void *arg);
void test_nss_show_icon(void *arg);
void test_nss_cancel_icon(void *arg);
void test_nss_force_text_preview(void *arg);

MNGR_TEST_CASE_BEGING
NMGR_TS("Issue[Balloon] pluto rotate 270",      MAUI_03079353_1),
NMGR_TS("Issue[Balloon] pluto rotate 180",      MAUI_03079353_2),
NMGR_TS("Issue[Balloon] pluto rotate 90",      MAUI_03079353_3),
NMGR_TS("Issue[Balloon] pluto rotate 0",      MAUI_03079353_4),
NMGR_TS("1[Balloon] upper, failure",      showUpperBalloonwithTypefailure),
NMGR_TS("2[Balloon] upper, info",         showUpperBalloonwithTypeinfo),
NMGR_TS("3[Balloon] upper, warning",      showUpperBalloonwithTypewarning),
NMGR_TS("4[Balloon] upper, success",      showUpperBalloonwithTypesuccess),
NMGR_TS("5[Balloon] upper, progress",     showUpperBalloonwithTypeprogress),


NMGR_TS("6[Balloon] lower, failure",      showLowerBalloonwithTypefailure),
NMGR_TS("7[Balloon] lower, info",         showLowerBalloonwithTypeinfo),
NMGR_TS("8[Balloon] lower, warning",      showLowerBalloonwithTypewarning),
NMGR_TS("9[Balloon] lower, success",      showLowerBalloonwithTypesuccess),
NMGR_TS("10[Balloon] lower, progress",    showLowerBalloonwithTypeprogress),

NMGR_TS("11[Preview], code logic",        previewLogicTest),
NMGR_TS("12[Preview], single",            showSinglePreview),
NMGR_TS("13[Preview], cancel",            cancelSinglePreviewStatusIcon),
NMGR_TS("14[Preview], multi",             showMultiPreview),

NMGR_TS("15[Balloon], lower multi",       showLowerMultiBalloon),
NMGR_TS("16[Balloon], upper multi",       showUpperMultiBalloon),
NMGR_TS("17[Balloon], lower & uppper",    showLowerandUpperBalloon),
NMGR_TS("18[Preview], long text",         previewWithLongString),
NMGR_TS("19[Balloon], long text",         balloonWithLongString),
NMGR_TS("20[Preview], pluto no statusicon",    previewInPlutoScreenwithOutStatusIcon),
NMGR_TS("21[Preview], pluto with statusicon",  previewInPlutoScreenwithStatusIcon),

NMGR_TS("22[Balloon], pluto no statusicon",    balloonInPlutoScreenwithOutStatusIcon),
NMGR_TS("23[Balloon], pluto with statusicon",  balloonInPlutoScreenwithStatusIcon),

NMGR_TS("24[Preview], single blink",      singlePreviewBlinkicon),

NMGR_TS("25[STATUS] blink icon", blinkIcon),

NMGR_TS("26[Balloon], upper balloon postion test", balloon_position_test),

NMGR_TS("27[Status Icon], get area test", status_icon_get_area_test),
NMGR_TS("28[Balloon], move arrow remove icon", test_upper_balloon_position_change_remove),
NMGR_TS("29[Balloon], get hide icon balloon", test_hide_status_icon_balloon),
NMGR_TS("30[Balloon], move arrow add icon", test_upper_balloon_position_change_add),
NMGR_TS("31[Balloon], disappear with icon", test_upper_balloon_disappearwith_icon),
NMGR_TS("32[Balloon], balloon first position", test_upper_balloon_first_position),
NMGR_TS("33[Global popup], one button id", test_vapp_nmgr_global_popup_show_confirm_one_button_id),
NMGR_TS("34[Global popup], two button id", test_vapp_nmgr_global_popup_show_confirm_two_button_id),
NMGR_TS("35[Global popup], comomand id", test_vapp_nmgr_global_popup_show_command_id),

NMGR_TS("36[Global popup], one button str", test_vapp_nmgr_global_popup_show_confirm_one_button_str),
NMGR_TS("37[Global popup], two button str", test_vapp_nmgr_global_popup_show_confirm_two_button_str),
NMGR_TS("38[Global popup], comomand str", test_vapp_nmgr_global_popup_show_command_str),
NMGR_TS("39[Alert], NSS - popup(one button)", test_nss_show_one_button_popup),
NMGR_TS("40[Alert], NSS - popup(two button)", test_nss_show_two_button_popup),
NMGR_TS("41[Alert], NSS - status bar(text preview)", test_nss_show_text_preivew),
NMGR_TS("42[Alert], NSS - status bar(balloon)", test_nss_show_balloon),
NMGR_TS("43[Alert], NSS - none", test_nss_show_none),
NMGR_TS("43[Alert], NSS - cancel", test_nss_cancel),
NMGR_TS("44[Alert], NSS - popup launch", test_nss_popup_launch_app),
NMGR_TS("45[Alert], NSS - text preview launch", test_nss_text_preview_launch_app),
NMGR_TS("46[Alert], NSS - status icon", test_nss_show_icon),
NMGR_TS("47[Alert], NSS - status icon cancel", test_nss_cancel_icon),
NMGR_TS("48[Alert], NSS - Force status icon in NSS setting popup",    test_nss_force_text_preview),

NMGR_TEST_CASE_END


static MMI_RET tst_scrn_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_SCRN_ACTIVE:
		{
			mmi_frm_scrn_active_evt_struct *p = (mmi_frm_scrn_active_evt_struct *)evt;
			if (p->scrn_id == 1000 && p->user_data == (void *)0x03079353)
			{
				mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
			}
			else if (p->scrn_id == 2000 && p->user_data == (void *)0x03079353)
			{
				mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_180);
			}
			else if (p->scrn_id == 3000 && p->user_data == (void *)0x03079353)
			{
				mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_90);
			}
			
			ShowCategory74Screen(
				0,
				0,
				0,
				0,
				STR_GLOBAL_BACK,
				0,
				(U8 *)L"Hello World",
				mmi_ucs2strlen((CHAR*) L"Hello World"),
				(U8 *)p->gui_buffer);
			break;
		}

	#if defined (__COSMOS_MMI_PACKAGE__)
		case EVT_ID_ON_KEY:
		{
			mmi_frm_key_evt_struct *key = (mmi_frm_key_evt_struct *)evt;
			if (key->key_code == KEY_BACK && key->key_type == KEY_EVENT_DOWN)
			{
				mmi_frm_scrn_close_active_id();
				return MMI_RET_KEY_HANDLED;
			}
			break;
		}
	#endif
	}
	return MMI_RET_OK;
}


void MAUI_03079353_1(void *para)
{
	mmi_frm_scrn_create(GRP_ID_ROOT, 1000, tst_scrn_proc, (void *)0x03079353);
	showLowerBalloonwithTypeinfo(NULL);
	showUpperBalloonwithTypeinfo(NULL);
}
void MAUI_03079353_2(void *para)
{
	mmi_frm_scrn_create(GRP_ID_ROOT, 2000, tst_scrn_proc, (void *)0x03079353);
	showLowerBalloonwithTypeinfo(NULL);
	showUpperBalloonwithTypeinfo(NULL);
}

void MAUI_03079353_3(void *para)
{
	mmi_frm_scrn_create(GRP_ID_ROOT, 3000, tst_scrn_proc, (void *)0x03079353);
	showLowerBalloonwithTypeinfo(NULL);
	showUpperBalloonwithTypeinfo(NULL);
}

void MAUI_03079353_4(void *para)
{
	mmi_frm_scrn_create(GRP_ID_ROOT, 4000, tst_scrn_proc, (void *)0x03079353);
	showLowerBalloonwithTypeinfo(NULL);
	showUpperBalloonwithTypeinfo(NULL);
}

//-------------------------------------------------------------------
void callBackOneBtnId(VfxId id, void  *userData)
{
	switch (id)
	{
         case VCP_CONFIRM_POPUP_BUTTON_USER_1:
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

		 case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }	   
	}
	mmi_mfree(userData);
}


void test_vapp_nmgr_global_popup_show_confirm_one_button_id(void *para)
{
	 void *arg = mmi_malloc(10);
     vapp_nmgr_global_popup_show_confirm_one_button_id(
         MMI_SCENARIO_ID_DEFAULT,
         VCP_POPUP_TYPE_FAILURE, 
         STR_GLOBAL_ABORT,
         STR_GLOBAL_OK,
         VCP_POPUP_BUTTON_TYPE_NORMAL,
         callBackOneBtnId,
         arg);

}

//-------------------------------------------------------------------------
void callBackTwoBtnId(VfxId id, void *userData)
{
    switch (id)
    {
         case VCP_CONFIRM_POPUP_BUTTON_USER_1:
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_CONFIRM_POPUP_BUTTON_USER_2:
         {
             //TO DO: handle button2 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }
    }
    //free the resource if the user data is dynamically allocated.
    mmi_mfree(userData);     
}


void test_nss_show_one_button_popup(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Fail!!, it must be popup");
    VfxWString popup_msg = VFX_WSTR("Success to show one button popup");
    VfxWString button_msg = VFX_WSTR("Fail");

    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_POPUP, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= NULL;
    alert_info.app_proc_para.user_data= NULL;		
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_POPUP;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}

void test_nss_show_two_button_popup(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Fail!!, it must be popup");
    VfxWString popup_msg = VFX_WSTR("Success to show two button popup");
    VfxWString button_msg = VFX_WSTR("Suc");
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_POPUP, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= NULL;
    alert_info.app_proc_para.user_data= NULL;		
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_POPUP;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}
void test_nss_show_text_preivew(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Suc to show text preview");
    VfxWString popup_msg = VFX_WSTR("Fail!!, it must be text preview");
    VfxWString button_msg = VFX_WSTR("Fail");
    
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_STATUS_BAR, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= NULL;
    alert_info.app_proc_para.user_data= NULL;		
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_STATUS_BAR;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}
void test_nss_show_balloon(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Suc to show balloon");
    VfxWString popup_msg = VFX_WSTR("Fail!!, it must be balloon");
    VfxWString button_msg = VFX_WSTR("Fail");
        
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_STATUS_BAR, 
        MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= NULL;
    alert_info.app_proc_para.user_data= NULL;		
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_STATUS_BAR;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}
void test_nss_show_none(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Fail!it must be none");
    VfxWString popup_msg = VFX_WSTR("Fail!it must be none");
    VfxWString button_msg = VFX_WSTR("Fail");
        
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        FORCE_ICON_ONLY, 
        MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= NULL;
    alert_info.app_proc_para.user_data= NULL;		
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_NONE;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}
void test_nss_cancel(void *arg)
{
    mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
}

static mmi_ret nmgr_alert_test_callback (mmi_event_struct *param)
{
    U32 data = *(U32*)param->user_data;
    if(param->evt_id == EVT_ID_NMGR_ALERT_END)
    {
        VfxWString string = VFX_WSTR("Cancel app launch");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());

    }
    else
    {
        VfxWString string = VFX_WSTR("App launch");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
    }
        
    return MMI_OK;    
}


void test_nss_popup_launch_app(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Fail!it must be popup");
    VfxWString popup_msg = VFX_WSTR("Success to show two button popup");
    VfxWString button_msg = VFX_WSTR("Launch");
    mmi_frm_nmgr_alert_struct alert_info;
    U32 user_data =100; 
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_POPUP, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= &nmgr_alert_test_callback;
    alert_info.app_proc_para.user_data= &user_data;
    alert_info.app_proc_para.data_size= sizeof(user_data);
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_POPUP;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
alert_info.event_type = MMI_EVENT_FAILURE;
user_data = 200;
g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
alert_info.event_type = MMI_EVENT_INFO;
user_data = 300;
g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
alert_info.event_type = MMI_EVENT_WARNING;
user_data = 400;
g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
alert_info.event_type = MMI_EVENT_SUCCESS;
user_data = 500;
g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
alert_info.event_type = MMI_EVENT_PROGRESS;
user_data = 600;
g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);


}
void test_nss_text_preview_launch_app(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Suc to show text preview");
    VfxWString popup_msg = VFX_WSTR("Fail!!, it must be text preview");
    VfxWString button_msg = VFX_WSTR("Fail");
   U32 user_data =100; 
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        PREFER_STATUS_BAR, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);

    alert_info.app_proc_para.scrn_group_proc= &nmgr_alert_test_callback;
    alert_info.app_proc_para.user_data= &user_data;       
    alert_info.app_proc_para.data_size = sizeof(user_data);       
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_STATUS_BAR;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);

}
void test_nss_show_icon(void *arg)
{
    mmi_frm_nmgr_alert_struct alert_info;
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   
    alert_info.app_id = VAPP_EMAIL;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
    alert_info.behavior_mask = FORCE_ICON_ONLY;    
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_UNREAD_VOICE; 
    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
}

void test_nss_cancel_icon(void *arg)
{
    mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
}

void test_nss_force_text_preview(void *arg)
{
    VfxWString preview_msg = VFX_WSTR("Suc to show text preview");
    VfxWString popup_msg = VFX_WSTR("Fail!!, it must be text preview");
    VfxWString button_msg = VFX_WSTR("Fail");
   
    mmi_frm_nmgr_alert_struct alert_info;
    U16 notification_setting_value;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));   

    FILL_IN_ALERT_INFO(
        FORCE_ICON_ONLY, 
        MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE, 
        MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE);
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
    alert_info.app_proc_para.scrn_group_proc= &nmgr_alert_test_callback;
    alert_info.app_proc_para.user_data= NULL;       
    
#ifdef __MMI_NSS_SUPPORT__
    if(mmi_srv_nss_get_setting(alert_info.app_id, NSS_SETTING_ALERT, &notification_setting_value) == MMI_RET_OK)
    {
        notification_setting_value = ALERT_TYPE_POPUP;
        mmi_srv_nss_set_setting(alert_info.app_id, NSS_SETTING_ALERT,notification_setting_value);
    }
#endif

    g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);

}


void test_vapp_nmgr_global_popup_show_confirm_two_button_id(void *para)
{    
	void *arg = mmi_malloc(10);
    vapp_nmgr_global_popup_show_confirm_two_button_id(
         MMI_SCENARIO_ID_DEFAULT,
         VCP_POPUP_TYPE_FAILURE, 
         STR_GLOBAL_ABORT,
         STR_GLOBAL_OK,
         STR_GLOBAL_CANCEL,
         VCP_POPUP_BUTTON_TYPE_NORMAL,
         VCP_POPUP_BUTTON_TYPE_NORMAL,
  		 callBackTwoBtnId,
         arg);
}

//--------------------------------------------------------------------
void enterFuncCmdId(VfxS32 handle, void *userData)
{
    vcp_global_popup_show_command_add_id(handle, 'BUT1', STR_GLOBAL_1, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(handle, 'BUT2', STR_GLOBAL_2, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(handle, 'BUT3', STR_GLOBAL_3, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_id(handle, 'BUT4', STR_GLOBAL_4, VCP_POPUP_BUTTON_TYPE_NORMAL);
}

void callBackCmdBtnId(VfxId id, void *userData)
{
    switch (id)
    {
         case 'BUT1':
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT2':
         {
             //TO DO: handle button2 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT3':
         {
             //TO DO: handle button3 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT4':
         {
             //TO DO: handle button4 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }
    }
    //free the resource if the user data is dynamically allocated.
    mmi_mfree(userData);     
}
void test_vapp_nmgr_global_popup_show_command_id(void *para)
{
    void *arg = mmi_malloc(10);
	vapp_nmgr_global_popup_show_command_id(
        MMI_SCENARIO_ID_DEFAULT,
        STR_GLOBAL_ABORT,
        callBackCmdBtnId,
		enterFuncCmdId,
        arg);
}

//----------------------------------------------------------
void callBackOneBtnStr(VfxId id, void  *userData)
{
	switch (id)
	{
         case VCP_CONFIRM_POPUP_BUTTON_USER_1:
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

		 case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }	   
	}
	mmi_mfree(userData);
}

void test_vapp_nmgr_global_popup_show_confirm_one_button_str(void *para)
{
    void *arg = mmi_malloc(10);
    VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
    VfxWString btnText(VFX_WSTR_RES(STR_GLOBAL_OK));
  
    vapp_nmgr_global_popup_show_confirm_one_button_str(
         MMI_SCENARIO_ID_DEFAULT,
         VCP_POPUP_TYPE_FAILURE, 
         title,
         btnText,
         VCP_POPUP_BUTTON_TYPE_NORMAL,
         callBackOneBtnStr,
         arg);
}
//-----------------------------------------------------------------------

void callBackTwoBtnStr(VfxId id, void *userData)
{
    switch (id)
    {
         case VCP_CONFIRM_POPUP_BUTTON_USER_1:
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_CONFIRM_POPUP_BUTTON_USER_2:
         {
             //TO DO: handle button2 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }
    }
    //free the resource if the user data is dynamically allocated.
    mmi_mfree(userData);     
}


void test_vapp_nmgr_global_popup_show_confirm_two_button_str(void *para)
{
	void *arg = mmi_malloc(10);
	VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
	VfxWString btnText1(VFX_WSTR_RES(STR_GLOBAL_OK));
	VfxWString btnText2(VFX_WSTR_RES(STR_GLOBAL_CANCEL));

	vapp_nmgr_global_popup_show_confirm_two_button_str(
		MMI_SCENARIO_ID_DEFAULT,
		VCP_POPUP_TYPE_FAILURE, 
		title,
		btnText1,
		btnText2,
		VCP_POPUP_BUTTON_TYPE_NORMAL,
		VCP_POPUP_BUTTON_TYPE_NORMAL,
		callBackTwoBtnStr,
		arg);
}

//---------------------------------------------------------------------
void enterFuncCmdStr(VfxS32 handle, void *userData)
{
    VfxWString btn1Text(VFX_WSTR_RES(STR_GLOBAL_1));
    VfxWString btn2Text(VFX_WSTR_RES(STR_GLOBAL_2));
    VfxWString btn3Text(VFX_WSTR_RES(STR_GLOBAL_3));
    VfxWString btn4Text(VFX_WSTR_RES(STR_GLOBAL_4));
    vcp_global_popup_show_command_add_str(handle, 'BUT1', btn1Text, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_str(handle, 'BUT2', btn2Text, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_str(handle, 'BUT3', btn3Text, VCP_POPUP_BUTTON_TYPE_NORMAL);
    vcp_global_popup_show_command_add_str(handle, 'BUT4', btn4Text, VCP_POPUP_BUTTON_TYPE_NORMAL);
}

void callBackCmdBtnStr(VfxId id, void *userData)
{
    switch (id)
    {
         case 'BUT1':
         {
             //TO DO: handle button1 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT2':
         {
             //TO DO: handle button2 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT3':
         {
             //TO DO: handle button3 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case 'BUT4':
         {
             //TO DO: handle button4 click here
			 VfxS32 i = 0;
			 ++i;
             break;
         }

         case VCP_POPUP_BUTTON_NO_PRESSED:
         {
             //TO DO: handle the case for back key, end key
             //and someone invoke vapp_nmgr_global_popup_cancel
			 VfxS32 i = 0;
			 ++i;
             break;
         }
    }
    //free the resource if the user data is dynamically allocated.
    mmi_mfree(userData);     
}

void test_vapp_nmgr_global_popup_show_command_str(void *para)
{
	void *arg = mmi_malloc(10);
	VfxWString title(VFX_WSTR_RES(STR_GLOBAL_ABORT));
	vapp_nmgr_global_popup_show_command_str(
	     MMI_SCENARIO_ID_DEFAULT,
	     title,
	     callBackCmdBtnStr,
		 enterFuncCmdStr,
	     arg);
}

//----------------------------------------------------------------------------------
//status icon test
//status icon test
void blinkIcon(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_blink_icon(STATUS_ICON_UNREAD_EMAIL);
}

void status_icon_get_area_test(void *arg)
{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
	static int i = 0;
	S32 icons[] = {
		STATUS_ICON_UNREAD_EMAIL, 
		STATUS_ICON_MISSED_CALL,
		STATUS_ICON_ALARM,
		STATUS_ICON_MMS_UNREAD,
	    STATUS_ICON_SMS_SENDING,
	    STATUS_ICON_MESSAGE_UNREAD};
	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
	{
		wgui_status_icon_bar_set_icon_display(icons[j]);
		wgui_status_icon_bar_update();
	}
	wgui_status_icon_bar_get_icon_area(icons[i], &x1, &y1, &x2, &y2);


    VfxWString string = VFX_WSTR("Hello World");
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    S32 y = MMI_STATUS_BAR_HEIGHT;
    static S32 x = 0;
    x = x1 + (x2 - x1) / 2;
    VfxPoint point(x, y);
    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, string, point);
	i++;
	if (i == sizeof(icons)/sizeof(icons[0]))
	{
		i = 0;
	}    
}

//----------------------------------------------------------------------------------
void test_upper_balloon_first_position(void *arg)
{

    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
	wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}
void showUpperBalloonwithTypeinfo(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}
void showUpperBalloonwithTypefailure(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        string.getBuf());
}
void showUpperBalloonwithTypewarning(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_WARNING,
        string.getBuf());
}
void showUpperBalloonwithTypesuccess(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_SUCCESS,
        string.getBuf());
}
void showUpperBalloonwithTypeprogress(void *arg)
{
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_ALARM);
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    wgui_status_icon_bar_update();
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
}

void balloon_callback_remove(void)
{
	wgui_status_icon_bar_hide_icon(STATUS_ICON_MISSED_CALL);
}

void balloon_callback_add(void)
{
	wgui_status_icon_bar_show_icon(STATUS_ICON_MESSAGE_SENDING);
}

void test_upper_balloon_position_change_add(void *arg)
{
    
    S32 icons[] = {
		STATUS_ICON_UNREAD_EMAIL, 
		STATUS_ICON_MISSED_CALL,
	    STATUS_ICON_MESSAGE_SEND_FAIL,
	    STATUS_ICON_MESSAGE_UNREAD};
	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
	{
		wgui_status_icon_bar_set_icon_display(icons[j]);
		wgui_status_icon_bar_update();
	}
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
	gui_start_timer(500, balloon_callback_add);
    
}

void test_upper_balloon_position_change_remove(void *arg)
{
    
    S32 icons[] = {
		STATUS_ICON_UNREAD_EMAIL, 
		STATUS_ICON_MISSED_CALL,
	    STATUS_ICON_MESSAGE_SEND_FAIL,
	    STATUS_ICON_MESSAGE_UNREAD};
	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
	{
		wgui_status_icon_bar_set_icon_display(icons[j]);
		wgui_status_icon_bar_update();
	}
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
	gui_start_timer(500, balloon_callback_remove);
    
}

void balloon_callback_remove_this(void)
{
    wgui_status_icon_bar_hide_icon(STATUS_ICON_UNREAD_EMAIL);
}
void test_upper_balloon_disappearwith_icon(void *arg)
{
    S32 icons[] = {
		STATUS_ICON_UNREAD_EMAIL, 
		STATUS_ICON_MISSED_CALL,
	    STATUS_ICON_MESSAGE_SEND_FAIL,
	    STATUS_ICON_MESSAGE_UNREAD};
	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
	{
		wgui_status_icon_bar_set_icon_display(icons[j]);
		wgui_status_icon_bar_update();
	}
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
	gui_start_timer(500, balloon_callback_remove_this);
}
void test_hide_status_icon_balloon(void *arg)
{
    S32 icons[] = {
        STATUS_ICON_UNREAD_EMAIL,
        STATUS_ICON_SMS_FULL,
		STATUS_ICON_MISSED_CALL,
		STATUS_ICON_ALARM,
		STATUS_ICON_MMS_UNREAD,
	    STATUS_ICON_SMS_SENDING,
	    STATUS_ICON_MESSAGE_SEND_FAIL,
	    STATUS_ICON_MESSAGE_UNREAD,
	    };
	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
	{
		wgui_status_icon_bar_set_icon_display(icons[j]);
		wgui_status_icon_bar_update();
	}
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
}
//--------------------------------------------------------------------------
void showLowerBalloonwithTypeinfo(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}
void showLowerBalloonwithTypefailure(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        string.getBuf());
}
void showLowerBalloonwithTypewarning(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_WARNING,
        string.getBuf());
}
void showLowerBalloonwithTypesuccess(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_SUCCESS,
        string.getBuf());
}
void showLowerBalloonwithTypeprogress(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
}

void showLowerMultiBalloon(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());

	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}

void showUpperMultiBalloon(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_update();
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());

	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}

void showLowerandUpperBalloon(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_update();
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
}

void balloonWithLongString(void *arg)
{
    VfxWString string = VFX_WSTR("qwertyuiopasdfghjklzxcvbnm_qwertyuiopasdfghjklzxcvbnm_qwertyuiopasdfghjklzxcvbnm");
    wgui_status_icon_bar_set_icon_display(STATUS_ICON_UNREAD_EMAIL);
    wgui_status_icon_bar_update();
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_EMAIL,
        MMI_NMGR_BALLOON_TYPE_INFO,
        string.getBuf());
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_PROGRESS,
        string.getBuf());
}
void balloon_position_test(void *arg)
{
    VfxWString string = VFX_WSTR("Hello World");
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    S32 y = MMI_STATUS_BAR_HEIGHT;
    static S32 x = 0;
    VfxPoint point(x, y);
    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, string, point);
    x = x + 10;
    if (x > UI_DEVICE_WIDTH)
    {
        x = 0;
    }
}
void balloonInPlutoScreenwithOutStatusIcon(void *arg)
{
    VfxWString text = VFX_WSTR("Do you see the balloon?" );
	showPlutoScreen(text.getBuf(), showLowerandUpperBalloon, MMI_FALSE);
}
void balloonInPlutoScreenwithStatusIcon(void *arg)
{
    VfxWString text = VFX_WSTR("Do you see the balloon?" );
	showPlutoScreen(text.getBuf(), showLowerandUpperBalloon, MMI_TRUE);
}
//-------------------------------------------------------------------------
void previewLogicTest(void *arg)
{
#if 0
/* under construction !*/
#endif
    VfxWString string = VFX_WSTR("Success");
	mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_SUCCESS,
        string.getBuf());    
}

void showSinglePreview(void *arg)
{
    mmi_frm_notification_para_struct noti;
    noti.option = 0;
    VfxWString text = VFX_WSTR("Hello World");
    noti.text = text.getBuf();
    mmi_frm_nmgr_notify(MMI_SCENARIO_ID_NEW_EMAIL, MMI_EVENT_EMAIL, &noti);
}

void cancelSinglePreviewStatusIcon(void *arg)
{
    mmi_frm_nmgr_cancel(MMI_EVENT_EMAIL);
}

void timer_cb_preview()
{
    mmi_frm_notification_para_struct noti;
    noti.option = 0;
	static VfxS32 i = 0;
    VfxWString text;
    noti.text = text.format("Hello Wolrd [%d]", i).getBuf();
    mmi_frm_nmgr_notify(MMI_SCENARIO_ID_NEW_EMAIL, MMI_EVENT_EMAIL, &noti);
	i++;

	if (i < 50)
	{
		gui_start_timer(0, timer_cb_preview);
	}
	else
	{
		i = 0;
	}
}

void showMultiPreview(void *arg)
{
	gui_start_timer(0, timer_cb_preview);
}

void previewWithLongString(void *arg)
{
    mmi_frm_notification_para_struct noti;
    noti.option = 0;
    VfxWString text = VFX_WSTR("qwertyuiopasdfghjklzxcvbnm_qwertyuiopasdfghjklzxcvbnm_qwertyuiopasdfghjklzxcvbnm");
    noti.text = text.getBuf();
    mmi_frm_nmgr_notify(MMI_SCENARIO_ID_NEW_EMAIL, MMI_EVENT_EMAIL, &noti);
}

void previewInPlutoScreenwithOutStatusIcon(void *arg)
{
    VfxWString text = VFX_WSTR("Do you see the preview? if No, please press back key then test single preview again");
	showPlutoScreen(text.getBuf(), showSinglePreview, MMI_FALSE);
}

void previewInPlutoScreenwithStatusIcon(void *arg)
{
    VfxWString text = VFX_WSTR("Do you see the preview? if No, please press back key then test single preview again");
	showPlutoScreen(text.getBuf(), showSinglePreview, MMI_TRUE);
}

void singlePreviewBlinkicon(void *arg)
{
    mmi_frm_notification_para_struct noti;
    noti.option = MMI_FRM_NMGR_ICON_BLINKING;
    VfxWString text = VFX_WSTR("Hello World");
    noti.text = text.getBuf();
    mmi_frm_nmgr_notify(MMI_SCENARIO_ID_NEW_EMAIL, MMI_EVENT_EMAIL, &noti);
}
//--------------------------------------------------------------------------------
void showPlutoScreen(const WCHAR *str, void (*f)(void *), MMI_BOOL has_status_icon_bar)
{
    MMI_BOOL ret;
    ret = mmi_frm_scrn_enter(GRP_ID_ROOT, 250, NULL, MMI_dummy_function, MMI_FRM_FG_ONLY_SCRN);
    if (ret == MMI_TRUE)
    {
        if (has_status_icon_bar == MMI_FALSE)
        {
		    ShowCategory61Screen((PU8)str, IMG_GLOBAL_EMPTY, NULL);
		    SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(GoBackHistory, KEY_BACK, KEY_EVENT_UP);
        } else
        {
            ShowCategory152Screen(
                STR_GLOBAL_PHONE,
                0, 
                0, 
                0, 
                STR_GLOBAL_BACK,
                0,
                (PU8)str,
                NULL);
            SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        }
        if (f)
        {
            f(NULL);
        }
    }
}

//--------------------------------------------------------------------------------------
VtstTestResultEnum vtst_rt_nmgr(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        VAPP_MSG, 
        VFX_OBJ_CLASS_INFO(VtstNmgr),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}


void VtstNmgr::onRun(void * args,VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    m_testCaseCount = sizeof(nmgrTestCase) / sizeof(nmgrTestCase[0]);

    // create and display main screen
    VtstNmgrScreen *scr;
    VFX_OBJ_CREATE(scr, VtstNmgrScreen, this);
    scr->show();
}

void VtstNmgrScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VtstNmgrPage *page;
    VFX_OBJ_CREATE(page, VtstNmgrPage, this);
    pushPage(0, page);
}




VfxBool VtstNmgrPage::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        )
{
    text = nmgrTestCase[index].name;
    return VFX_TRUE;
}
void VtstNmgrPage::onInit()
{
    VfxPage::onInit();
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setContentProvider(this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setPos(VfxPoint(0,0));
    m_listMenu->setSize(this->getSize());
    m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE,
                                 VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->m_signalItemTapped.connect(this, &VtstNmgrPage::onItemTap);
}
void VtstNmgrPage::onItemTap(VcpListMenu *list, VfxU32 index)
{
    if (nmgrTestCase[index].f)
    {
        nmgrTestCase[index].f(this);
    }
}

VfxBool VtstNmgrPage::onKeyInput(VfxKeyEvent & event)
{
    if (event.keyCode == VFX_KEY_CODE_CAMERA 
        && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        S32 icons[] = {
    		STATUS_ICON_UNREAD_EMAIL, 
    		STATUS_ICON_MISSED_CALL,
    		STATUS_ICON_ALARM,
    		STATUS_ICON_MMS_UNREAD,
    	    STATUS_ICON_SMS_SENDING,
    	    STATUS_ICON_MESSAGE_UNREAD,
    	    STATUS_ICON_SMS_FULL,
    	    STATUS_ICON_MESSAGE_SEND_FAIL,
    	    STATUS_ICON_MESSAGE_SENDING,
    	    STATUS_ICON_MUTE,
    	    STATUS_ICON_MEDPLY};
    	for (S32 j = 0; j < sizeof(icons)/sizeof(icons[0]); j++)
    	{
    		wgui_status_icon_bar_hide_icon(icons[j]);
    	}
        return VFX_TRUE;
    }
    return VfxPage::onKeyInput(event);
}
extern "C" void test_nmgr(void)
{
	vtst_rt_nmgr(0);
}

#endif /* __AFX_RT_TEST__ */