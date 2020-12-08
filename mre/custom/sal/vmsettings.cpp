extern "C"
{
#include "vmswitch.h"
#include "vmsettings.h"
#include "vmpromng.h"
#include "ProfilesSrvGprot.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "ViewSettingCommonProt.h"
#endif
#include "mmi_phnset_dispchar.h"
#include "GeneralSettingSrvGprot.h"
}

#ifdef __MRE_SAL_SETTINGS__

#ifndef __COSMOS_MMI_PACKAGE__

typedef struct
{
    VM_P_HANDLE                         pHandle;
    vm_settings_set_wallpaper_callback  callback;
    void*                               user_data;
}vm_settings_set_wallpaper_data;

#else //__COSMOS_MMI_PACKAGE__

#include "vapp_wallpaper_setting_method_gprot.h" 

class vmWallpaperCB : public VfxObject
{
public:
    VM_P_HANDLE                         m_pHandle;
    vm_settings_set_wallpaper_callback  m_callback;
    void*                               m_userdata;
    void*                               m_buffer;
    void callback(VfxU8 param);
};

#endif

static const srv_prof_settings_enum type_map[]={
    SRV_PROF_SETTINGS_POWER_ON_TONE,            
    SRV_PROF_SETTINGS_POWER_OFF_TONE,           
    SRV_PROF_SETTINGS_POWER_ON_OFF_TONE,        
    SRV_PROF_SETTINGS_COVER_OPEN_TONE,          
    SRV_PROF_SETTINGS_COVER_CLOSE_TONE,         
    SRV_PROF_SETTINGS_SMS_TONE,
    SRV_PROF_SETTINGS_SMS_CARD2_TONE,     
    SRV_PROF_SETTINGS_SMS_CARD3_TONE,       
    SRV_PROF_SETTINGS_SMS_CARD4_TONE, 
    SRV_PROF_SETTINGS_MMS_TONE,                 
    SRV_PROF_SETTINGS_MMS_CARD2_TONE,           
    SRV_PROF_SETTINGS_MMS_CARD3_TONE,           
    SRV_PROF_SETTINGS_MMS_CARD4_TONE,           
    SRV_PROF_SETTINGS_EMAIL_TONE,               
    SRV_PROF_SETTINGS_EMAIL_CARD2_TONE,         
    SRV_PROF_SETTINGS_EMAIL_CARD3_TONE,         
    SRV_PROF_SETTINGS_EMAIL_CARD4_TONE,         
    SRV_PROF_SETTINGS_VOICE_TONE,               
    SRV_PROF_SETTINGS_VOICE_CARD2_TONE,         
    SRV_PROF_SETTINGS_VOICE_CARD3_TONE,         
    SRV_PROF_SETTINGS_VOICE_CARD4_TONE,         
    SRV_PROF_SETTINGS_MT_CALL_TONE,             
    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,       
    SRV_PROF_SETTINGS_MT_CALL_CARD3_TONE,       
    SRV_PROF_SETTINGS_MT_CALL_CARD4_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_TONE,             
    SRV_PROF_SETTINGS_VT_CALL_CARD2_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_CARD3_TONE,       
    SRV_PROF_SETTINGS_VT_CALL_CARD4_TONE,
};


extern "C" VMINT vm_settings_set_tone(vm_settings_tone_enum type, VMWCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_prof_ret ret = VM_SETTINGS_RET_FAIL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type <0 || type >= VM_SETTINGS_TONE_END)
    {
        return VM_SETTINGS_RET_PARAM_ERR;
    }
    
    ret =  srv_prof_set_current_profile_tone_with_file_path(type_map[(VMINT)type],(WCHAR*)path);

    switch (ret)
    {
    case SRV_PROF_RET_SUCCESS:
        ret = VM_SETTINGS_RET_OK;
        break;
    case SRV_PROF_RET_FAIL:
        ret = VM_SETTINGS_RET_FAIL;
        break;
    case SRV_PROF_RET_SETTING_NOT_SUPPORTED:
        ret = VM_SETTINGS_RET_NOT_SUPPORT;
        break;
    default:
        if ( ret >= 0)
        {
            ret = VM_SETTINGS_RET_OK;
        }
        else
        {
            ret = VM_SETTINGS_RET_FAIL;
        }
        break;
    }
    return ret;
}


#ifndef __COSMOS_MMI_PACKAGE__ //PLUTO
static mmi_ret _vm_settings_set_wallpaper_cb(mmi_event_struct *param)
{
    vm_settings_set_wallpaper_data* data = (vm_settings_set_wallpaper_data*)param;
    if (data && data->callback && VM_PMNG_UNLOAD != vm_pmng_state(data->pHandle))
    {
        vm_pmng_set_ctx(data->pHandle);
        data->callback(data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx();
    }
    
    return 0;
}
#else
void vmWallpaperCB::callback(VfxU8 param)
{
    if (this->m_callback && VM_PMNG_UNLOAD != vm_pmng_state(this->m_pHandle))
    {
        vm_pmng_set_ctx(this->m_pHandle);
        this->m_callback(this->m_userdata);        
        vm_free(this->m_buffer);
        vm_pmng_reset_ctx();
    }    
}

#endif

extern "C" VMINT vm_settings_set_wallpaper(vm_setttings_wallpaper_enum type, 
                                            VMWCHAR* path,vm_settings_set_wallpaper_callback callback, void* user_data)
{
#ifndef __COSMOS_MMI_PACKAGE__ //PLUTO

    vm_settings_set_wallpaper_data* data = NULL;

    if (callback)
    {
        data = (vm_settings_set_wallpaper_data*)vm_malloc(sizeof(vm_settings_set_wallpaper_data));
        if (!data)
        {
            return VM_SETTINGS_RET_NO_MEM;
        }
        
        data->pHandle = vm_pmng_get_current_handle();
        data->callback = callback;
        data->user_data = user_data;
    }

    if (type != VM_SETTINGS_HOME_PAPER)
    {
        return VM_SETTINGS_RET_NOT_SUPPORT;
    }
    
    mmi_phnset_view_setting_set_by_file(MMI_PHNSET_TYPE_WP,(const WCHAR* )path,(mmi_proc_func)_vm_settings_set_wallpaper_cb,(void*)data);
    return VM_SETTINGS_RET_OK;
#else //__COSMOS_MMI_PACKAGE__

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
/* under construction !*/
/* under construction !*/
#endif
    return VM_SETTINGS_RET_OK;
    
#endif //__COSMOS_MMI_PACKAGE__
    
}



extern "C"
{
/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_time_format
 * DESCRIPTION
 *  Get system time format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_time_format_enum
 *****************************************************************************/
VMINT vm_setting_get_time_format(void)
{
    srv_setting_time_format_enum format;

    format = srv_setting_get_time_format();
    switch(format)
    {
        case SETTING_TIME_FORMAT_12_HOURS:
            return VM_SETTING_TIME_FORMAT_12_HOURS;

        case SETTING_TIME_FORMAT_24_HOURS:
            return VM_SETTING_TIME_FORMAT_24_HOURS;
    }
    return -2;
}


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_format
 * DESCRIPTION
 *  Get system date format 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_format_enum
 *****************************************************************************/
VMINT vm_setting_get_date_format(void)
{
    srv_setting_date_format_enum format;

    format = srv_setting_get_date_format();
    switch(format)
    {
        case SETTING_DATE_FORMAT_DD_MM_YYYY:
            return VM_SETTING_DATE_FORMAT_DD_MM_YYYY;

        case SETTING_DATE_FORMAT_MM_DD_YYYY:
            return VM_SETTING_DATE_FORMAT_MM_DD_YYYY;

        case SETTING_DATE_FORMAT_YYYY_MM_DD:
            return VM_SETTING_DATE_FORMAT_YYYY_MM_DD;
    }
    return -2;    
}


/*****************************************************************************
 * FUNCTION
 *  vm_setting_get_date_seperator
 * DESCRIPTION
 *  Get system date seperator 
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_setting_date_seperator_enum
 *****************************************************************************/
VMINT vm_setting_get_date_seperator(void)
{
    srv_setting_date_seperator_enum seperator;

    seperator = srv_setting_get_date_seperator();
    switch(seperator)
    {
        case SETTING_DATE_SEPERATOR_DOT:
            return VM_SETTING_DATE_SEPERATOR_DOT;

        case SETTING_DATE_SEPERATOR_COLON:
            return VM_SETTING_DATE_SEPERATOR_COLON;

        case SETTING_DATE_SEPERATOR_SLOPE:
            return VM_SETTING_DATE_SEPERATOR_SLOPE;

        case SETTING_DATE_SEPERATOR_LINE:
            return VM_SETTING_DATE_SEPERATOR_LINE;
    }
    return -2;      
}

} /* extern "C" */
#endif //__MRE_SAL_SETTINGS__