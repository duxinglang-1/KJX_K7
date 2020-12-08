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
*  MREAppMgrSrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  MRE AppMgr Service implement file.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/****************************************************************************
* Include
****************************************************************************/
#include "MMI_features.h" 
#include "MMIDataType.h"
#include "kal_release.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#include "app_mem_med.h"
#include "Conversions.h"
#include "PixcomFontEngine.h"
#include "AppMgrSrvGProt.h"
#include "AppMgrSrvProt.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "DLAgentSrvMREProts.h"
#include "mmi_rp_app_mre_appmgr_def.h"
#include "mmi_rp_app_mre_def.h"
#include "MMI_mre_trc.h"
#include "USBSrvGProt.h"

#include "MRESrvGprot.h"
#include "MREAppMgrSrvGprot.h"
#include "MRESrvDownloadGprot.h"
#include "vmswitch.h"
#include "vmmullang.h"

#include "vmlog.h"

#include "vmcert.h"
#include "vmdl.h"
#include "vmgettag.h"
#include "vmres.h"

#include "NotificationSettingSrvGprot.h"
#include "vmpn.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "PhoneSetupGprots.h"


#include "gdi_features.h"

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


/* Close the download feature on MP branch */
#undef __MMI_MRE_SUPPORT_UPDATE__
#undef __MMI_MRE_SHORTCUT_QQ__
#undef __MMI_MRE_SHORTCUT_OPERA__
#ifndef __MMI_MRE_DISABLE_FMGR__
/****************************************************************************
* Define
****************************************************************************/
static const srv_mre_appmgr_app_package_name_prefix mre_app_package_name_prefix[]=
{
    {L"z:\\@mre\\app\\",L"mre.vxp.",SRV_MRE_APPMGR_APP_TYPE_VXP},
    {L"z:\\@mre\\app\\",L"mre.vsp.",SRV_MRE_APPMGR_APP_TYPE_SERVICE},
    {L"z:\\@mre\\widget\\",L"mre.widget.",SRV_MRE_APPMGR_APP_TYPE_WIDGET},
    {L"z:\\@mre\\wallpaper\\",L"mre.wallpaper.",SRV_MRE_APPMGR_APP_TYPE_WALLPAPER},
    {L"z:\\@mre\\launcher\\",L"mre.laucher.",SRV_MRE_APPMGR_APP_TYPE_LAUNCHER},
    {L"z:\\@mre\\scrlock\\",L"mre.scrlock.",SRV_MRE_APPMGR_APP_TYPE_SCRLOCK},
    {L"z:\\@mre\\others\\",L"mre.others.",SRV_MRE_APPMGR_APP_TYPE_OTHERS}
};
#define VM_PNS_NOTIFY_SWITCH_MASK 0x10000000
#define VM_PNS_NOTIFY_STYLE_MASK  0x11111111


#define SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE_BEGIN       (0x8000) /* 
mre vpp begin*/
#define SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE_NUM          (4)


//#define MRE_APPMGR_TEST

/****************************************************************************
* Typedef
****************************************************************************/

#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
typedef enum 
{  
    StartState,    
    SectionLabelState,  
    KeyState,  
    ValueState,    
    CommentState  
}mmi_mre_appmgr_parse_state; 
#endif
static MMI_ID srv_mre_appmgr_launch_int(
                                        srv_appfactory_launch_type_enum type,
                                        mmi_app_package_char *app_name,
                                        void *param,
                                        U32 param_size);

//#ifdef __MMI_APP_MANAGER_SUPPORT__
void srv_mre_appmgr_app_uninstall_ex(
                                     mmi_app_package_char *app_name, 
                                     srv_appmgr_uninstall_cb cb_fct, 
                                     void* user_data);
//#endif

/****************************************************************************
* Global variable
****************************************************************************/
srv_appfactory_func_table_struct mre_appfactory_func_table = 
{
    SRV_APP_FACTORY_MRE_TYPE,
    (appfactory_get_reg_app_num)srv_mre_appmgr_get_app_num,
    (appfactory_get_reg_app_list)srv_mre_appmgr_get_app_list,
    (appfactory_get_name)srv_mre_appmgr_get_app_name,
    (appfactory_get_image)srv_mre_appmgr_get_app_image,
    (appfactory_get_info)srv_mre_appmgr_get_app_info,
    (appfacotry_launch)srv_mre_appmgr_launch_int,
    (appfactory_uninstall)srv_mre_appmgr_app_uninstall_ex,
    (appfactory_get_reg_id_list)srv_mre_appmgr_get_unique_app_id_list,
    (appfactory_get_app_name_by_id)srv_mre_appmgr_get_package_name_by_unique_id,
    (appfactory_get_id_by_app_name)srv_mre_appmgr_get_unique_app_id
};

/* Shortcut app list */
extern srv_mre_appmgr_shortcut_info_struct g_shortcut_info_list[];

#ifdef MRE_APPMGR_TEST
static U32 g_dl_app_id;
#endif

//static mmi_app_package_name_struct g_cache_name;
//static srv_mre_appmgr_installed_info_struct g_cache_info;

srv_mre_appmgr_map_table g_mre_appmgr_maptable[SRV_MRE_APPMGR_INSTALLED_APP_MAX];
extern MMI_BOOL mre_push_usb_ms_mode;
extern MMI_BOOL mre_push_dev_plug_out;
static MMI_BOOL g_mre_is_register_nss_setting_change = MMI_FALSE;
#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
srv_mre_appmgr_t_card_install_strut g_mre_appmgr_restore_factory_mode;
#endif
/****************************************************************************
* Functions
****************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_mre_app_launch(CHAR *appName);
extern void vapp_mre_app_install(WCHAR *appPtah);
#endif
#ifdef __MRE_SAL_PN__
extern mmi_ret srv_mre_push_receiver_install_app(U16 *app_path,srv_mre_appmgr_app_type_enum app_type,mmi_app_package_char *app_name,U32 app_unique_id);
extern mmi_ret srv_mre_push_receiver_uninstall(WCHAR *app_name);
extern void vm_pmng_set_push_app_flag(U32 index);
extern mmi_ret srv_mre_appmgr_get_app_badge(mmi_app_package_char *app_name, void *badge);
extern MMI_BOOL srv_mre_appmgr_get_push_installed_info(U16 *app_name, srv_mre_appmgr_push_installed_info_struct *info);
extern mmi_ret srv_mre_push_receiver_file_write(U32 AppId,srv_mre_appmgr_push_installed_info_struct* write_info,MMI_BOOL flag);

#ifdef __MMI_NSS_SUPPORT__
void srv_mre_appmgr_listen_setting_change(U16 app_id, U32 changed_setting, U16* alias_id);
#endif//__MMI_NSS_SUPPORT__
#endif//__MRE_SAL_PN__
extern GDI_RESULT gdi_image_device_bmp_encode_file(
            WCHAR *filepath,
            kal_uint8 *image,
            gdi_color_format cf,
            kal_uint32 width,
            kal_uint32 height);
extern S32 vm_nvram_set_firstflag(void);
extern  mmi_ret srv_mre_appmgr_get_app_list_internal(S32 flag, void *name_array, U32 num,MMI_BOOL list_type);
extern int vm_ucs2_to_ascii(char * dst, int size, short * src);

#ifdef __MMI_USB_SUPPORT__
extern void mmi_usb_app_unavailable_popup(U16 stringId);
#endif /* __USB_IN_NORMAL_MODE__ */
#ifndef __COSMOS_MMI_PACKAGE__
extern MMI_BOOL mmi_am_launch_app_by_path(U16 *app_path);
#endif
/*static MMI_BOOL srv_mre_appmgr_check_cache(mmi_app_package_char *app_name, 
srv_mre_appmgr_installed_info_struct *info)
{
if (!app_name || !info)
{
return MMI_FALSE;
}

if (0 == strcmp((char*)app_name,(char*)g_cache_name))
{
memcpy(info,&g_cache_info,sizeof(srv_mre_appmgr_installed_info_struct));
return MMI_TRUE;
}
return MMI_FALSE;
}

static void srv_mre_appmgr_set_cache(mmi_app_package_char *app_name,
srv_mre_appmgr_installed_info_struct *info)
{
if (app_name && info)
{
strcpy(g_cache_name,app_name);
memcpy(&g_cache_info,info,sizeof(srv_mre_appmgr_installed_info_struct));
}
}

static void srv_mre_appmgr_clear_cache(void)
{
memset(&g_cache_name,0,sizeof(g_cache_name));
memset(&g_cache_info,0,sizeof(g_cache_info));
}*/

S32 srv_mre_appmgr_get_file_type(WCHAR *path)
{
    if (0 == mmi_ucs2icmp((CHAR *)(path + kal_wstrlen(path)-4), (CHAR *)L".vxp")||
        0 == mmi_ucs2icmp((CHAR *)(path + kal_wstrlen(path)-4), (CHAR *)L".rom"))
    {
        return SRV_MRE_APPMGR_APP_TYPE_VXP;
    }
    else if (0 == mmi_ucs2icmp((CHAR *)(path + kal_wstrlen(path)-4), (CHAR *)L".vsp"))
    {
        return SRV_MRE_APPMGR_APP_TYPE_SERVICE;
    }    
    else
    {
        U32 type;
        if (srv_mre_get_app_type(path,&type))
        {
            switch (type)
            {
            case 1:
                return (S32)SRV_MRE_APPMGR_APP_TYPE_WIDGET;
            case 2:
                return (S32)SRV_MRE_APPMGR_APP_TYPE_WALLPAPER;
            case 3:
                return (S32)SRV_MRE_APPMGR_APP_TYPE_LAUNCHER;
            case 4:
                return (S32)SRV_MRE_APPMGR_APP_TYPE_SCRLOCK;
            }
        }
        return (S32)SRV_MRE_APPMGR_APP_TYPE_OTHERS;
    }
}

srv_mre_appmgr_app_type_enum srv_mre_appmgr_get_file_type_ex(U16 *app_name)
{
    U32 index=0;
    for(;index<sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix);index++)
    {
        if (0 == kal_wstrncmp(app_name, mre_app_package_name_prefix[index].app_package_name_prefix, kal_wstrlen(mre_app_package_name_prefix[index].app_package_name_prefix)))
        {
            return (mre_app_package_name_prefix[index].app_type);
        }
    }
    return SRV_MRE_APPMGR_APP_TYPE_VXP;
}

static U32 srv_mre_appmgr_get_sc_num()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (!(g_shortcut_info_list[i].app_id == (U32)-1 &&
        g_shortcut_info_list[i].icon_id == (U16)-1 &&
        g_shortcut_info_list[i].name_id == (U16)-1))
    {
        i++;
    }
    return i;
}


MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
    {
        if (app_id == g_shortcut_info_list[i].app_id)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_mre_app
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/

static MMI_BOOL srv_mre_appmgr_is_mre_app(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_name == NULL)
    {
        return MMI_FALSE;
    }

    if (mmi_wcsncmp((const WCHAR*)app_name, (const WCHAR*)SRV_MRE_APPMGR_ID_PREFIX, 4) == 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

static void srv_mre_appmgr_get_app_folder(U16* app_name, U16* app_folder)
{
    U32 index = 0;
    U32 find = 0;
    for(;index<sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix);index++)
    {
        if (0 == kal_wstrncmp(app_name, mre_app_package_name_prefix[index].app_package_name_prefix, kal_wstrlen(mre_app_package_name_prefix[index].app_package_name_prefix)))
        {
            kal_wsprintf(app_folder,"%w",mre_app_package_name_prefix[index].app_folder);
            find = 1;
            break;
        }
    }
    if(find==0)
    {
        kal_wsprintf(app_folder,"%w",mre_app_package_name_prefix[0].app_folder);
    }
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_generate_identification
* DESCRIPTION
*  Generate identification (app name).
* PARAMETERS
*  app_path:[IN] application file path.
*  app_name : [OUT] the application identification.
* RETURN VALUES
*  MMI_TRUE: If successful.
*  MMI_FALSE: If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_generate_identification(U16 *app_path, U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_app_id;
    U16 temp_developer[30];
    U16 developer[SRV_MRE_APPMGR_DEVELOPER_NAME_LEN+1];
    U32 developer_size;
    U16 temp_name[100];
    U16 name[SRV_MRE_APPMGR_APP_NAME_LEN+1];
    U32 name_size;
    U16 temp_app_name[MMI_APP_NAME_MAX_LEN];
    S32 type;
    U32 app_name_len = 0;
    U32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL || app_name == NULL)
    {
        return MMI_FALSE;
    }

    /* Check whether the application is shortcut or not. */
    /* Get app id */
    srv_mre_get_app_id(app_path, &temp_app_id);

    if (srv_mre_appmgr_is_shortcut_app_by_id(temp_app_id))
    {
        U32 i;

        for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
        {
            if (temp_app_id == g_shortcut_info_list[i].app_id)
            {
                kal_wsprintf((WCHAR*) app_name,"mre.shortcut.%d",g_shortcut_info_list[i].app_id);
                return MMI_TRUE;
            }
        }
        return MMI_FALSE;
    }
    /* Get developer string */
    if (!srv_mre_get_app_developer(app_path, temp_developer, &developer_size))
    {
        //mmi_wcscpy(developer, SRV_MRE_APPMGR_DEFAULT_DEVELOPER);
        kal_wsprintf(developer,"unknown");
    }
    else
    {
        mmi_wcsncpy(developer, temp_developer, SRV_MRE_APPMGR_DEVELOPER_NAME_LEN);
    }

    /* Get app name */
    if (!srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, temp_name, &name_size, VM_LANG_ENG))
    {
        if (!srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, temp_name, &name_size, VM_LANG_CHS))
        {
            return MMI_FALSE;
        }
    }

    type = srv_mre_appmgr_get_file_type((WCHAR*)app_path);
    mmi_wcsncpy(name, temp_name, SRV_MRE_APPMGR_APP_NAME_LEN);
    for(;index<sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix);index++)
    {
        if (mre_app_package_name_prefix[index].app_type == type)
        {
            //kal_wsprintf(temp_app_name,"%w",mre_app_package_name_prefix[index].app_package_name_prefix);
            break;
        }
    }
    if(index >= sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix))
        index--;
    kal_wsprintf(temp_app_name,"%w%w.%w",mre_app_package_name_prefix[index].app_package_name_prefix,developer,name);
    mmi_wcscpy((U16*) app_name, temp_app_name);
    app_name_len = mmi_wcslen(app_name);
    for(index=0;index<app_name_len;index++)
    {
        if(app_name[index]==0xFFFF)
            app_name[index]=L'_';
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_info
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info            [OUT]     
* RETURNS
*  
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_installed_info(
    U16 *app_name,
    srv_mre_appmgr_installed_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    CHAR tmp_app_name[MMI_APP_NAME_MAX_LEN];
    FS_HANDLE file_hdl;
    U32 read;
    //S32 type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8,(char *)app_name, (char *)tmp_app_name, MMI_APP_NAME_MAX_LEN);

    /* if (srv_mre_appmgr_check_cache(tmp_app_name,info))
    {
    return MMI_TRUE;
    }*/
    /* Check parameter */
    if (info == NULL || !srv_mre_appmgr_is_mre_app(app_name))
    {
        return MMI_FALSE;
    }

    srv_mre_appmgr_get_app_folder(app_name,info_path);

    mmi_wcscat(info_path, (const WCHAR*)app_name);
    file_hdl = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        if ((FS_Read(file_hdl, info, sizeof(srv_mre_appmgr_installed_info_struct), &read) >= FS_NO_ERROR) &&
            (read == sizeof(srv_mre_appmgr_installed_info_struct)))
        {
            ret = MMI_TRUE;
        }
        FS_Close(file_hdl);
        return ret;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_file_path
* DESCRIPTION
*  Get file path of the application.
* PARAMETERS
*  app_name : [IN] the application package identification.
*  filepath : [OUT] get the application file path.
* RETURN VALUES
*  MMI_RET_OK: If successful.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_file_path(mmi_app_package_char *app_name, U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_appmgr_installed_info_struct installed_info;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (filepath == NULL || !srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        mmi_wcscpy(filepath, installed_info.app_path);
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
        ret = MMI_TRUE;
    }

    return ret;
}
U32 srv_mre_appmgr_get_autostart(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 autostart = 0;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return 0;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        autostart = installed_info.autostart;
    }

    return autostart;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_appid
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/
U32 srv_mre_appmgr_get_appid(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 app_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name))
    {
        return 0;
    }

    if (srv_mre_appmgr_get_installed_info(app_name, &installed_info))
    {
        app_id = installed_info.app_id;
    }

    return app_id;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_installed_time
* DESCRIPTION
*  Get the install time.
* PARAMETERS
*  app_name : [IN] the application identification.
*  install_time : [OUT] install time
* RETURN VALUES
*  MMI_TRUE: Get install time successfully.
*  MMI_FALSE: Get install time failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_app_installed_time(mmi_app_package_char *app_name, applib_time_struct *install_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_appmgr_installed_info_struct installed_info;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (install_time == NULL || !srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        memcpy(install_time, &installed_info.installed_time, sizeof(applib_time_struct));

        //srv_mre_appmgr_set_cache(app_name,&installed_info);
        ret = MMI_TRUE;
    }

    return ret;
}

//flag is for need to get new unique appid flag
//badge is to only store badge number, and need to do nothing
static MMI_BOOL srv_mre_appmgr_write_maptable(void)
{
    FS_HANDLE tab_hdl     = -1;
    U32 write_size = 0;
    WCHAR mre_path[SRV_MRE_APPMGR_PATH_SIZE];
    srv_mre_appmgr_format_check format_check;
    memcpy(format_check.mre,CURRENT_MRE_VERSION,sizeof(CURRENT_MRE_VERSION));
    format_check.mreappmgr_id = SRV_MRE_APPMGR_ID_BASE;
    mmi_wcscpy(mre_path, SRV_MRE_APPMGR_MAP_FILE);
    tab_hdl = FS_Open(mre_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if(tab_hdl >= FS_NO_ERROR)
    {
        FS_Write(tab_hdl,&format_check,sizeof(format_check),&write_size);
        if(FS_Write(tab_hdl, g_mre_appmgr_maptable, sizeof(g_mre_appmgr_maptable),&write_size)
            <FS_NO_ERROR|| (write_size!= sizeof(g_mre_appmgr_maptable)))
        {
            FS_Close(tab_hdl);
            return MMI_FALSE;
        }
    }
    else
    {
        FS_Close(tab_hdl);
        return MMI_FALSE;
    }
    FS_Close(tab_hdl);        
    return MMI_TRUE;
}
#ifdef __LOW_COST_SUPPORT_COMMON__
U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1, U16 *rom_path,U16 badge,U32 app_id)
#else
U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1, U16* appname2,U16 *rom_path,U16 badge,U32 app_id)
#endif
{
    U32 i = 0;
    if(flag==0)
    {
        for(;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
        {
            if(g_mre_appmgr_maptable[i].unique_appid==0)
            {
                g_mre_appmgr_maptable[i].unique_appid= 1;
                g_mre_appmgr_maptable[i].app_install_type = app_type;
                g_mre_appmgr_maptable[i].app_id = app_id;
                mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)app_name,(char*)(g_mre_appmgr_maptable[i].app_install_name),MMI_APP_NAME_MAX_LEN);
                if(appname0!=NULL)
                {
                    mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[i].app_name)[0],appname0,SRV_MRE_APPMGR_APP_NAME_LEN-1);
                    mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[i].app_name)[1],appname1,SRV_MRE_APPMGR_APP_NAME_LEN-1);
#ifndef __LOW_COST_SUPPORT_COMMON__
                    mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[i].app_name)[2],appname2,SRV_MRE_APPMGR_APP_NAME_LEN-1);
#endif
                }
                if(rom_path!=NULL)
                {
                    mmi_wcsncpy(g_mre_appmgr_maptable[i].rom_app_path,rom_path,SRV_MRE_APPMGR_MAX_ROM_PATH_LEN-1);
                }
                srv_mre_appmgr_write_maptable();
                return SRV_MRE_APPMGR_ID_BASE+i;
            }
        }
    }
    else
    {
        U32 index = 0;
        index = flag-SRV_MRE_APPMGR_ID_BASE;
        if(appname0!=NULL)
        {
            mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[index].app_name)[0],appname0,SRV_MRE_APPMGR_APP_NAME_LEN-1);
            mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[index].app_name)[1],appname1,SRV_MRE_APPMGR_APP_NAME_LEN-1);
#ifndef __LOW_COST_SUPPORT_COMMON__
            mmi_wcsncpy((WCHAR *)(g_mre_appmgr_maptable[i].app_name)[2],appname2,SRV_MRE_APPMGR_APP_NAME_LEN-1);
#endif

            //mmi_wcscpy((WCHAR *)(g_mre_appmgr_maptable[index].app_name)[2],appname2);
            //if(rom_path == NULL)
            //memset(g_mre_appmgr_maptable[index].rom_app_path,0,15*2);
            if(app_type!=0)
            {
                g_mre_appmgr_maptable[index].app_install_type = app_type;
            }
        }
        else
        {
            if(app_type!=0)
            {
                g_mre_appmgr_maptable[index].app_install_type = app_type;
            }
            g_mre_appmgr_maptable[index].badge = badge;

        }
        srv_mre_appmgr_write_maptable();
    }
    return 0;    
}

static MMI_BOOL srv_mre_appmgr_save_app_icon_to_pbm_file(U8* img_file_ptr, U32 img_file_size, WCHAR *image_path, U16 img_type, gdi_color_format color_format, U8* img_buffer, U32 img_buffer_size, S32 img_width, S32 img_height, MMI_BOOL resized_flag)
{
    MMI_BOOL ret = MMI_FALSE;
    GDI_RESULT gdi_ret;        
    gdi_handle layer_handle;

    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPF_INFO, img_type, color_format, img_width, img_height, resized_flag); 

    gdi_ret = gdi_layer_create_cf_using_outside_memory(color_format, 0, 0, img_width, img_height, &layer_handle, img_buffer, img_buffer_size);
    if ( gdi_ret == GDI_SUCCEED )
    {
        gdi_layer_push_and_set_active(layer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        do
        {
            if (resized_flag == MMI_TRUE)    // just for resize large -> small, otherwise use resizer 
                gdi_ret = gdi_image_draw_resized_mem(0, 0, img_width, img_height, img_file_ptr, img_type, img_file_size);
            else
                gdi_ret = gdi_image_draw_mem(0, 0, img_file_ptr, img_type, img_file_size);
            if ( gdi_ret != GDI_SUCCEED )
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPF_DRAW_IMG_FAIL, gdi_ret);
                ret = MMI_FALSE;
                break;
            }
            gdi_ret = gdi_image_device_bmp_encode_file(image_path, img_buffer, color_format, img_width, img_height);
            if ( gdi_ret != GDI_SUCCEED )
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPF_BMP_ENCODE_FAIL, gdi_ret);
                ret = MMI_FALSE;
                break;
            }

            ret = MMI_TRUE;
        }
        while (0);

        gdi_layer_pop_and_restore_active();
        gdi_layer_free(layer_handle);        
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPE_CREATE_IMG_LAYER_FAIL, gdi_ret);    
        ret = MMI_FALSE;
    }

    return ret;
}

static MMI_BOOL srv_mre_appmgr_save_app_icon_to_pbm_file_by_resizer(U8* img_file_ptr, U32 img_file_size, WCHAR *image_path, U16 img_type, gdi_color_format color_format, U8* img_buffer, U32 img_buffer_size, S32 img_width, S32 img_height, U8* resized_img_buffer, U32 resized_img_buffer_size, S32 resized_img_width, S32 resized_img_height)
{
    MMI_BOOL ret = MMI_FALSE;
    GDI_RESULT gdi_ret;        
    gdi_handle layer_handle;    
    gdi_handle resized_layer_handle;

    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPFBR_INFO, img_type, color_format, img_width, img_height, resized_img_width, resized_img_height); 

    gdi_ret = gdi_layer_create_cf_using_outside_memory(color_format, 0, 0, img_width, img_height, &layer_handle, img_buffer, img_buffer_size);
    if ( gdi_ret == GDI_SUCCEED )
    {
        gdi_layer_push_and_set_active(layer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        do
        {
            gdi_ret = gdi_image_draw_mem(0, 0, img_file_ptr, img_type, img_file_size);
            if ( gdi_ret != GDI_SUCCEED )
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPFBR_DRAW_IMG_FAIL, gdi_ret);
                ret = MMI_FALSE;
                break;
            }
            gdi_ret = gdi_layer_create_cf_using_outside_memory(color_format, 0, 0, resized_img_width, resized_img_height, &resized_layer_handle, resized_img_buffer, resized_img_buffer_size);
            if ( gdi_ret == GDI_SUCCEED )
            {
                gdi_layer_push_and_set_active(resized_layer_handle);
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);

                do
                {
                    gdi_ret = gdi_bitblt_resized_with_resizer(
                        layer_handle,
                        0, 0, img_width - 1, img_height - 1,
                        0, 0, resized_img_width - 1, resized_img_height - 1,
                        GDI_RESIZER_DEFAULT);                                            
                    if ( gdi_ret != GDI_SUCCEED )
                    {
                        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPEBR_BITBLT_RESIZER_FAIL, gdi_ret);
                        ret = MMI_FALSE;
                        break;
                    }

                    gdi_ret = gdi_image_device_bmp_encode_file(image_path, resized_img_buffer, color_format, resized_img_width, resized_img_height);
                    if ( gdi_ret != GDI_SUCCEED )
                    {
                        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPFBR_BMP_ENCODE_FAIL, gdi_ret);
                        ret = MMI_FALSE;
                        break;
                    }

                    ret = MMI_TRUE;
                } 
                while (0);

                gdi_layer_pop_and_restore_active();
                gdi_layer_free(resized_layer_handle);        
            }
            else
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPEBR_CREATE_RESIZED_IMG_LAYER_FAIL, gdi_ret);    
                ret = MMI_FALSE;
                break;
            }
        }
        while (0);                            

        gdi_layer_pop_and_restore_active();
        gdi_layer_free(layer_handle);        
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAITPEBR_CREATE_IMG_LAYER_FAIL, gdi_ret);    
        ret = MMI_FALSE;
    }

    return ret;
}

static MMI_BOOL srv_mre_appmgr_save_app_icon( U8* img_file_ptr, U32 img_file_size, WCHAR *image_path, U16 img_type, srv_mre_appmgr_app_icon_type_enum *icon_type)
{
    MMI_BOOL ret = MMI_FALSE;
    //GDI_RESULT gdi_ret;    
    S32 img_width, img_height;
    U8* img_buffer;
    U32 img_buffer_size;
    S32 resized_img_width, resized_img_height;
    U8* resized_img_buffer;
    U32 resized_img_buffer_size;
    gdi_color_format color_format;
    U8 img_path_len = mmi_wcslen(image_path);


#if defined(__PLUTO_MMI_PACKAGE__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAVE_APP_ICON_FOR_PLUTO);
    if (img_type == GDI_IMAGE_TYPE_AB2)
    {
        mmi_wcscat(image_path, SRV_MRE_APPMGR_AB2_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_AB2;
        return MMI_TRUE;
    }
    else
    {
        mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_IMG;
        return MMI_TRUE;
    }
#endif

    if (img_type == GDI_IMAGE_TYPE_GIF || img_type == GDI_IMAGE_TYPE_PNG || img_type == GDI_IMAGE_TYPE_JPG || img_type == GDI_IMAGE_TYPE_BMP)
    {
        mmi_wcscat(image_path, SRV_MRE_APPMGR_PBM_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_PBM;
    }
    else if (img_type == GDI_IMAGE_TYPE_AB2)
    {
        mmi_wcscat(image_path, SRV_MRE_APPMGR_AB2_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_AB2;
        return MMI_TRUE;
    }
    else
    {
        mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_IMG;
        return MMI_TRUE;
    }

    gdi_image_get_dimension_mem(img_type, img_file_ptr, img_file_size, &img_width, &img_height);        


#if defined(__PLUTO_MMI_PACKAGE__) && !defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINMENU_SPREAD_SUPPORT__)

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) 
    {
        resized_img_width = 38;
        resized_img_height = 38;
    }
#else
    {
        resized_img_width = img_width;
        resized_img_height = img_height;
    }
#endif

#else

#if defined(__MMI_MAINLCD_480X800__)
    if (img_width < 72 || img_height < 72)
    {
        resized_img_width = 72;
        resized_img_height = 72;
    }
    else if (img_width > 96 || img_height > 96)
    {
        resized_img_width = 96;
        resized_img_height = 96;
    }
    else
    {
        resized_img_width = img_width;
        resized_img_height = img_height;
    }
#elif defined(__MMI_MAINLCD_320X480__)
    if (img_width < 48 || img_height < 48 )
    {
        resized_img_width = 48 ;
        resized_img_height = 48 ;
    }
    else if (img_width > 57 || img_height > 57)
    {
        resized_img_width = 57;
        resized_img_height = 57;
    }
    else
    {
        resized_img_width = img_width;
        resized_img_height = img_height;
    }
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
    if (img_width < 38 || img_height < 38)
    {
        resized_img_width = 38;
        resized_img_height = 38;
    }
    else if (img_width > 45 || img_height > 45)
    {
        resized_img_width = 45;
        resized_img_height = 45;
    }
    else
    {
        resized_img_width = img_width;
        resized_img_height = img_height;
    }    
#else
    {
        resized_img_width = img_width;
        resized_img_height = img_height;
    }
#endif
#endif

    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAVE_APP_ICON_IMG_RESIZE_INFO, img_width, img_height, resized_img_width, resized_img_height);

    img_buffer_size = img_width * img_height * 4;
    resized_img_buffer_size = resized_img_width * resized_img_height * 4;
    color_format = GDI_COLOR_FORMAT_32_PARGB;

    if (img_width < resized_img_width || img_height < resized_img_height)
    {
        img_buffer = (U8*) vm_malloc_nc(img_buffer_size);
        if (img_buffer)
        {
            resized_img_buffer = (U8*) vm_malloc_nc(resized_img_buffer_size);
            if (resized_img_buffer)
            {
                ret = srv_mre_appmgr_save_app_icon_to_pbm_file_by_resizer(img_file_ptr, img_file_size, image_path, img_type, color_format, img_buffer, img_buffer_size, img_width, img_height, resized_img_buffer, resized_img_buffer_size, resized_img_width, resized_img_height);                
                vm_free(resized_img_buffer);
            }
            else
            {
                resized_img_buffer = (U8*) applib_asm_alloc_anonymous_nc(resized_img_buffer_size);
                if (resized_img_buffer)
                {
                    ret = srv_mre_appmgr_save_app_icon_to_pbm_file_by_resizer(img_file_ptr, img_file_size, image_path, img_type, color_format, img_buffer, img_buffer_size, img_width, img_height, resized_img_buffer, resized_img_buffer_size, resized_img_width, resized_img_height);             
                    applib_asm_free_anonymous(resized_img_buffer);
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_RESIZED_IMG_MEM_FROM_ASM_FAIL, resized_img_buffer_size);
                    ret = MMI_FALSE;
                }
            }
            vm_free(img_buffer);
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_IMG_MEM_FROM_CORE_FAIL, img_buffer_size);

            img_buffer = (U8*) applib_asm_alloc_anonymous_nc(img_buffer_size);
            if (img_buffer)
            {
                resized_img_buffer = (U8*) applib_asm_alloc_anonymous_nc(resized_img_buffer_size);
                if (resized_img_buffer)
                {
                    ret = srv_mre_appmgr_save_app_icon_to_pbm_file_by_resizer(img_file_ptr, img_file_size, image_path, img_type, color_format, img_buffer, img_buffer_size, img_width, img_height, resized_img_buffer, resized_img_buffer_size, resized_img_width, resized_img_height);             
                    applib_asm_free_anonymous(resized_img_buffer);
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_RESIZED_IMG_MEM_FROM_ASM_FAIL, resized_img_buffer_size);
                    ret = MMI_FALSE;
                }
                applib_asm_free_anonymous(img_buffer);
            }
            else
            {            
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_IMG_MEM_FROM_ASM_FAIL, img_buffer_size);
                ret = MMI_FALSE;
            }
        }
    }
    else if (img_width > resized_img_width || img_height > resized_img_height)
    {
        resized_img_buffer = (U8*) vm_malloc_nc(resized_img_buffer_size);
        if (resized_img_buffer)
        {
            ret = srv_mre_appmgr_save_app_icon_to_pbm_file(img_file_ptr, img_file_size, image_path, img_type, color_format, resized_img_buffer, resized_img_buffer_size, resized_img_width, resized_img_height, MMI_TRUE);
            vm_free(resized_img_buffer);
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_RESIZED_MEM_FROM_CORE_FAIL, resized_img_buffer_size);

            resized_img_buffer = (U8*) applib_asm_alloc_anonymous_nc(resized_img_buffer_size);
            if (resized_img_buffer)
            {
                ret = srv_mre_appmgr_save_app_icon_to_pbm_file(img_file_ptr, img_file_size, image_path, img_type, color_format, resized_img_buffer, resized_img_buffer_size, resized_img_width, resized_img_height, MMI_TRUE);
                applib_asm_free_anonymous(resized_img_buffer);
            }
            else
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_RESIZED_IMG_MEM_FROM_ASM_FAIL, resized_img_buffer_size);
                ret = MMI_FALSE;
            }
        }
    }
    else
    {
        img_buffer = (U8*) vm_malloc_nc(img_buffer_size);
        if (img_buffer)
        {
            ret = srv_mre_appmgr_save_app_icon_to_pbm_file(img_file_ptr, img_file_size, image_path, img_type, color_format, img_buffer, img_buffer_size, img_width, img_height, MMI_FALSE);
            vm_free(img_buffer);
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_IMG_MEM_FROM_CORE_FAIL, img_buffer_size);
            img_buffer = (U8*) applib_asm_alloc_anonymous_nc(img_buffer_size);
            if (img_buffer)
            {
                ret = srv_mre_appmgr_save_app_icon_to_pbm_file(img_file_ptr, img_file_size, image_path, img_type, color_format, img_buffer, img_buffer_size, img_width, img_height, MMI_FALSE);
                applib_asm_free_anonymous(img_buffer);
            }
            else
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_ALLOC_IMG_MEM_FROM_ASM_FAIL, img_buffer_size);
                ret = MMI_FALSE;
            }
        }
    }

    if (ret == MMI_FALSE)
    {
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_SAI_SAVE_IMG);    
        image_path[img_path_len] = 0x0000;
        mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_POSTFIX);
        *icon_type = SRV_MRE_APPMGR_ICON_IMG;
    }

    return MMI_TRUE;
}

static MMI_BOOL srv_mre_appmgr_install_app_internal(
    U16 *app_path,
    srv_mre_appmgr_app_type_enum app_type,
    mmi_app_package_char *app_name,
    MMI_BOOL install_flag)   //0:install; 1:update install
{
    MMI_BOOL ret = MMI_FALSE;//ok
    MMI_BOOL is_shortcut = MMI_FALSE;
    U16 unique_app_type = 0;
    U32 temp_app_id = 0,temp_app_id1=0;//ok
    U32 autostart = 0;
    S32 autostart_size = 4;
    //mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN];
    U16 temp_app_name[MMI_APP_NAME_MAX_LEN];//ok
    WCHAR image_path[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];//ok
    srv_mre_appmgr_installed_info_struct *installed_info = NULL;
    U8 *img_ptr = NULL;
    U32 img_size, name_size;
    MMI_BOOL get_img_ret = MMI_FALSE, get_name_ret = MMI_FALSE;
    FS_HANDLE file_hdl,image_hdl;
    S32 file_result;
    U32 developer_size;

    srv_mre_appmgr_app_icon_type_enum icon_type;
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_S, app_path, app_type,install_flag);
    /* Check parameter */
    if (app_path == NULL)
    {
        return MMI_FALSE;
    }
    if(install_flag==0)
    {
        MMI_BOOL able_to_install_ret = MMI_FALSE;
        able_to_install_ret = srv_mre_appmgr_is_able_to_install(app_path);    
        /* Check whether the number of installed app reached maximum. */
        if (able_to_install_ret==MMI_FALSE)
        {
            MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_MAX_NUM);
            return MMI_FALSE;
        }
    }
    if (!srv_mre_appmgr_generate_identification(app_path, temp_app_name))
    {
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_E2);
        //srv_mre_unload_core(SRV_MRE_CALLER_AM);
        return MMI_FALSE;
    }
    installed_info = (srv_mre_appmgr_installed_info_struct*) vm_calloc(sizeof(srv_mre_appmgr_installed_info_struct));
    if (installed_info == NULL)
    {
        //srv_mre_unload_core(SRV_MRE_CALLER_AM);
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_E3);
        return MMI_FALSE;
    }

    srv_mre_appmgr_get_app_folder(temp_app_name,info_path);
    mmi_wcscat(info_path, (const WCHAR*)temp_app_name);
    srv_mre_get_app_id(app_path, &temp_app_id);
    if(install_flag==1)
    {
        if (!srv_mre_appmgr_get_installed_info(temp_app_name, installed_info))
        {
            vm_free(installed_info);
            return srv_mre_appmgr_install_app(app_path,SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,NULL);
        }
    }
    else
    {

        is_shortcut = srv_mre_appmgr_is_shortcut_app_by_id(temp_app_id);
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_APP_ID, temp_app_id,is_shortcut);
        if (is_shortcut)
        {
            if (srv_mre_appmgr_get_installed_info(temp_app_name, installed_info))
            {
                if (installed_info->app_size > 0)
                {
                    vm_free(installed_info);
                    return MMI_FALSE;
                }
            }
            else
            {
                vm_free(installed_info);
                return MMI_FALSE;
            }

        }
        else
        {
            /* Check whether the app is installed */
            file_hdl = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
            if (file_hdl >= FS_NO_ERROR)
            {
                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_E4);
                FS_Close(file_hdl);
                vm_free(installed_info);
                //srv_mre_unload_core(SRV_MRE_CALLER_AM);
                return MMI_FALSE;
            }
        }
    }
    temp_app_id1 = installed_info->app_unique_id;
    if(SRV_MRE_APPMGR_APP_TYPE_ROM==app_type)
    {
        get_img_ret = MMI_TRUE;
    }
    else
    {
        /* Get app image from vxp file */
        if ((srv_mre_get_app_image_ex(app_path, NULL, &img_size)) && (img_size > 0))
        {
            if (srv_mre_get_app_image_ex(app_path, &img_ptr, &img_size))
            {
                get_img_ret = MMI_TRUE;
            }
        }
    }

    /* Get app name, including Eng, CHS, CHT */
    if (srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, installed_info->app_name[0], &name_size, VM_LANG_ENG))
    {
        if('\r' == installed_info->app_name[1][0]  &&  '\n' == installed_info->app_name[1][1])
        {
            //ASSERT(0);
        }
        get_name_ret = MMI_TRUE;
    }
    if (srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, installed_info->app_name[1], &name_size, VM_LANG_CHS))
    {
        if('\r' == installed_info->app_name[1][0]  &&  '\n' == installed_info->app_name[1][1])
        {
            mmi_wcscpy(installed_info->app_name[1],installed_info->app_name[0]);
        }
        get_name_ret = MMI_TRUE;
    }
    if (srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, installed_info->app_name[2], &name_size, VM_LANG_CHT))
    {
        if('\r' == installed_info->app_name[2][0]  &&  '\n' == installed_info->app_name[2][1])
        {
            mmi_wcscpy(installed_info->app_name[2],installed_info->app_name[0]);
        }
        get_name_ret = MMI_TRUE;
    }
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_APP_GET_IMAGE,get_img_ret,get_name_ret);
    if(get_img_ret==MMI_FALSE || get_name_ret==MMI_FALSE)
    	return MMI_FALSE;
    if(install_flag==1)
    {
        if (SRV_MRE_APPMGR_APP_TYPE_ROM == installed_info->app_type ||
            SRV_MRE_APPMGR_APP_TYPE_SHORTCUT == installed_info->app_type)
        {
            installed_info->app_type |= SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL;
        }
        if(installed_info->app_type ==SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL)
        {
            installed_info->app_type = srv_mre_appmgr_get_file_type_ex(temp_app_name);
        }
#ifdef __LOW_COST_SUPPORT_COMMON__
        srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info->app_type),(U16)(installed_info->app_unique_id),installed_info->app_name[0],installed_info->app_name[1],NULL,0,temp_app_id);
#else
        srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info->app_type),(U16)(installed_info->app_unique_id),installed_info->app_name[0],installed_info->app_name[1], installed_info->app_name[2],NULL,0,temp_app_id);
#endif
    }
    else
    {
        if(!is_shortcut)
        {
            if(app_type ==SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL)
            {
                unique_app_type = (U16)(srv_mre_appmgr_get_file_type_ex(temp_app_name));
            }
            else if(app_type == SRV_MRE_APPMGR_APP_TYPE_ROM)
            {
                U32 type_internal = 0;
                if (srv_mre_get_app_type(app_path,&type_internal))
                {
                    switch (type_internal)
                    {
                    case 1:
                        unique_app_type = (U16)(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WIDGET);
                        break;
                    case 2:
                        unique_app_type = (U16)(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WALLPAPER);
                        break;
                    case 3:
                        unique_app_type = (U16)(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_LAUNCHER);
                        break;
                    case 4:
                        unique_app_type = (U16)(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_SCRLOCK);
                        break;
                    default:
                        unique_app_type = (U16)app_type;
                        break;
                    }
                }
                else
                {
                    unique_app_type = (U16)app_type;
                }
            }
            else
            {
                unique_app_type = app_type;
            }
            if(unique_app_type ==SRV_MRE_APPMGR_APP_TYPE_ROM || (unique_app_type & SRV_MRE_APPMGR_APP_TYPE_ROM_VPP))
            {
#ifdef __LOW_COST_SUPPORT_COMMON__
                temp_app_id1 = srv_mre_appmgr_get_avaible_unique_id(temp_app_name,(U16)unique_app_type,0,installed_info->app_name[0],installed_info->app_name[1],app_path,0,temp_app_id);
#else
                temp_app_id1 = srv_mre_appmgr_get_avaible_unique_id(temp_app_name,(U16)unique_app_type,0,installed_info->app_name[0],installed_info->app_name[1],installed_info->app_name[2],app_path,0,temp_app_id);
#endif
            }
            else
            {
#ifdef __LOW_COST_SUPPORT_COMMON__
                temp_app_id1 = srv_mre_appmgr_get_avaible_unique_id(temp_app_name,(U16)unique_app_type,0,installed_info->app_name[0],installed_info->app_name[1],NULL,0,temp_app_id);
#else
                temp_app_id1 = srv_mre_appmgr_get_avaible_unique_id(temp_app_name,(U16)unique_app_type,0,installed_info->app_name[0],installed_info->app_name[1],installed_info->app_name[2],NULL,0,temp_app_id);
#endif
            }
            installed_info->app_unique_id = temp_app_id1;
            installed_info->app_type = app_type;
        }
    }
    srv_mre_get_app_developer(app_path, installed_info->developer, &developer_size);

    /* Get tel number */
    srv_mre_get_app_tel(app_path, installed_info->tel);

    vm_get_vm_tag((short *)app_path,VM_CE_INFO_AUTO_START,&autostart,&autostart_size);

    /* Get app id */
    if(install_flag==0)
    {
        installed_info->app_id = temp_app_id;
    }

    installed_info->autostart = autostart;
    installed_info->child_unique_id = 0;

    /* Get app size */
    file_hdl = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        file_result = FS_GetFileSize(file_hdl, &installed_info->app_size);
        if (file_result != FS_NO_ERROR)
        {
            installed_info->app_size = 0;
        }
        FS_Close(file_hdl);
    }

    /* Get app storage position */
        /* Get app storage position */
    /* Get app storage position */
    if (app_type == SRV_MRE_APPMGR_APP_TYPE_ROM)
    {
        installed_info->store_pos = SRV_MRE_APPMGR_APP_POSITION_ROM;
    }
    else
    {
        CHAR sysDriver = (CHAR)FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
        CHAR fileDriver = (CHAR)(*app_path);
        
        // convert them to upper case first
        if (sysDriver >= 'a' && sysDriver <= 'z') {
            sysDriver -= ('a' - 'A');
        }
        if (fileDriver >= 'a' && fileDriver <= 'z') {
            fileDriver -= ('a' - 'A');
        }
        
        if (sysDriver==fileDriver)
        {
            installed_info->store_pos = SRV_MRE_APPMGR_APP_POSITION_PHONE;
        }
        else
        {   
            sysDriver = (CHAR) FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
                    // convert them to upper case first
            if (sysDriver >= 'a' && sysDriver <= 'z') 
            {
                sysDriver -= ('a' - 'A');
            }
            if(sysDriver==fileDriver)
            {
                installed_info->store_pos = SRV_MRE_APPMGR_APP_POSITION_CARD;
            }
        }
    }

    //#if (defined(__PLUTO_MMI_PACKAGE__))&&(  !defined(__MMI_FTE_SUPPORT__))
    if( installed_info->store_pos == SRV_MRE_APPMGR_APP_POSITION_PHONE)
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PHONE_DRV);
    }
    else
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    }
    mmi_wcscat(image_path,SRV_MRE_APPMGR_IMG_FIRST_FOLDER);
    image_hdl = FS_Open(image_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (image_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        FS_CreateDir(image_path); // create image folder
    }
    FS_Close(image_hdl);
    if( installed_info->store_pos == SRV_MRE_APPMGR_APP_POSITION_PHONE)
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PHONE_DRV);
    }
    else
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    }
    mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_FOLDER);
    image_hdl = FS_Open(image_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (image_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        FS_CreateDir(image_path); // create image folder
    }
    FS_Close(image_hdl);
    mmi_wcscat(image_path, (const WCHAR*)temp_app_name);
    /* Get installed time */
    applib_dt_get_rtc_time(&installed_info->installed_time);

    /* Get app path */
    mmi_wcscpy(installed_info->app_path, app_path);

    //MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_GET_RET, get_img_ret, get_name_ret);

    /*Get app resolution*/
    srv_mre_get_app_resolution(app_path,&installed_info->width,&installed_info->height);
    {
        FS_HANDLE img_hdl, info_hdl;
        U32 img_size_written, info_size_written;
        /* Save app installed info */
        info_hdl = FS_Open(info_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (info_hdl >= FS_NO_ERROR)
        {
            if(SRV_MRE_APPMGR_APP_TYPE_ROM==app_type)
            {
                if ((FS_Write(info_hdl, installed_info, sizeof(srv_mre_appmgr_installed_info_struct),
                    &info_size_written) >= FS_NO_ERROR) &&
                    (info_size_written == sizeof(srv_mre_appmgr_installed_info_struct)))
                {
                    FS_Close(info_hdl);
                    ret = MMI_TRUE;
                }
                else
                {
                    FS_Close(info_hdl);
                    //FS_Delete(info_path);
                    //memset(&g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE],0,sizeof(srv_mre_appmgr_map_table));
                    //srv_mre_appmgr_write_maptable();
                    ret = MMI_FALSE;
                }
            }
            else
            {
                if((install_flag==0)&&is_shortcut)
                {
                    installed_info->app_type |= SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL;
                }
                if ((FS_Write(info_hdl, installed_info, sizeof(srv_mre_appmgr_installed_info_struct),
                    &info_size_written) >= FS_NO_ERROR) &&
                    (info_size_written == sizeof(srv_mre_appmgr_installed_info_struct)))
                {
                    FS_Close(info_hdl);
                    /* Install app successfully */
                    //MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SUC);
                    // ret = MMI_TRUE;
                    if (app_type != SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD)
                    {
                        if ((install_flag==0)&&is_shortcut)
                        {  
#ifdef __LOW_COST_SUPPORT_COMMON__
                            srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info->app_type),(U16)(temp_app_id1),installed_info->app_name[0],installed_info->app_name[1],NULL,0,temp_app_id);
#else
                            srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info->app_type),(U16)(temp_app_id1),installed_info->app_name[0],installed_info->app_name[1],installed_info->app_name[2],NULL,0,temp_app_id);
#endif
                        }
                    }                
                    //save app icon
                    if(SRV_MRE_APPMGR_APP_TYPE_ROM!=app_type)
                    {
                        /* Save app image */
                        U8* img_file_ptr;
                        U32 img_file_size;
                        U16 img_type;
                        S32 tag_size = 4;
                        U8  tag_buf[4];
                        memset(tag_buf, 0, 4);

                        /* Check does it have 8 byte header */
                        if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_ADV_ICON, &tag_buf, &tag_size) != GET_TAG_TRUE)
                        {
                            tag_buf[0] = 0;
                        }
                        if (tag_buf[0] == 1)
                        {
                            /* Other image need to jump header */
                            img_file_ptr = img_ptr + 8;
                            img_file_size = img_size - 8;
                            if( img_ptr[0] == 0x34 )
                                img_type = GDI_IMAGE_TYPE_AB2;
                            else
                                img_type = gdi_image_get_type_from_mem((char *)img_file_ptr);                    
                        }
                        else
                        {
                            img_file_ptr = img_ptr;
                            img_file_size = img_size;
                            img_type = gdi_image_get_type_from_mem((char *)img_file_ptr);            
                        }
                        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SAVE_IMG_INFO, tag_buf[0], img_type);
                        srv_mre_appmgr_save_app_icon(img_file_ptr, img_file_size, image_path, img_type, &icon_type);
                        //if (MMI_FALSE == srv_mre_appmgr_save_app_icon(img_file_ptr, img_file_size, image_path, img_type, &icon_type))
                        //{
                            //FS_Delete(image_path);
                            //if(!is_shortcut)
                            //{
                                //FS_Delete(info_path);
                               // memset(&g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE],0,sizeof(srv_mre_appmgr_map_table));
                               // srv_mre_appmgr_write_maptable();
                            //}
                            //ret = MMI_FALSE;
                           // MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SAVE_APP_ICON_FAIL);
                        //}
                        //else
                        //{
                        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SAVE_APP_ICON_SUCC, icon_type);
                        if (icon_type == SRV_MRE_APPMGR_ICON_PBM)
                        {
                            g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].has_image_in_tcard = MMI_TRUE;
                            g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].icon_type = icon_type;
                            if( installed_info->store_pos == SRV_MRE_APPMGR_APP_POSITION_PHONE)
                            {//add flag for judge
                                g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].image_position = MMI_TRUE;
                            }
                            else
                            {
                                g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].image_position = MMI_FALSE;
                            }
                            srv_mre_appmgr_write_maptable();
                            ret = MMI_TRUE;
                        }
                        else
                        {
                            img_hdl = FS_Open(image_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
                            if (img_hdl >= FS_NO_ERROR)
                            { 
                                if ((FS_Write(img_hdl, img_file_ptr, img_file_size, &img_size_written) >= FS_NO_ERROR) &&
                                    (img_size_written == img_file_size))
                                {
                                    FS_Close(img_hdl);
                                    g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].has_image_in_tcard = MMI_TRUE;
                                    g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].icon_type = icon_type;

                                    if( installed_info->store_pos == SRV_MRE_APPMGR_APP_POSITION_PHONE)
                                    {//add flag for judge
                                        g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].image_position = MMI_TRUE;
                                    }
                                    else
                                    {
                                        g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE].image_position = MMI_FALSE;
                                    }
                                    srv_mre_appmgr_write_maptable();
                                        /* Install app successfully */
                                    ret = MMI_TRUE;
                                }
                                else
                                {
                                    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SAVE_INFO_FAIL);
                                        /* Delete image file and info file */
                                    //FS_Delete(image_path);
                                    //if(!is_shortcut)
                                    //{
                                       // FS_Delete(info_path);
                                        //memset(&g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE],0,sizeof(srv_mre_appmgr_map_table));
                                       // srv_mre_appmgr_write_maptable();
                                    //}
                                    ret = MMI_FALSE;
                                }
                            }
                        }
                        //}
                    }
                }
                else
                {               
                    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_SAVE_IMG_FAIL);
                    FS_Close(info_hdl);
                    /* Delete info file */
                    //FS_Delete(info_path);
                    //if(!is_shortcut)
                    //{
                        //FS_Delete(info_path);
                        //memset(&g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE],0,sizeof(srv_mre_appmgr_map_table));
                        //srv_mre_appmgr_write_maptable();
                    //}
                    ret  = MMI_FALSE;
                }


            }
        }
        if(ret==MMI_FALSE&&!is_shortcut)
        {
            //if(!is_shortcut)
            //{
            FS_Delete(info_path);
            FS_Delete(image_path);
            memset(&g_mre_appmgr_maptable[temp_app_id1-SRV_MRE_APPMGR_ID_BASE],0,sizeof(srv_mre_appmgr_map_table));
            srv_mre_appmgr_write_maptable();
            //}
            //ret = MMI_FALSE;
        }
    }
    if (img_ptr != NULL)
    {
        if (MMI_FALSE ==srv_mre_free_app_image_ex(img_ptr))
        {
            MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_FREE_IMG_FAIL);
        }
    }
    if(ret == MMI_TRUE)
    {
#ifdef __MRE_SAL_PN__
        srv_mre_push_receiver_install_app(app_path,app_type,app_name,temp_app_id1);
#endif
    }
    if(srv_mre_appmgr_get_file_type(app_path)==SRV_MRE_APPMGR_APP_TYPE_SERVICE)
    {
        U16 w_app_name_internal[MMI_APP_NAME_MAX_LEN];
        U32 size;
        mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2, (char *)app_name, (char *)w_app_name_internal, MMI_APP_NAME_MAX_LEN*2);
        srv_mre_appmgr_get_app_folder(w_app_name_internal,info_path);
        mmi_wcscat(info_path, (const WCHAR*)w_app_name_internal);
        file_hdl = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_WRITE);
        if (file_hdl >= FS_NO_ERROR)
        {
            FS_Read(file_hdl,installed_info,sizeof(srv_mre_appmgr_installed_info_struct),&size);
            FS_Seek(file_hdl, 0, FS_FILE_BEGIN);
            installed_info->child_unique_id = temp_app_id1;
            FS_Write(file_hdl,installed_info,sizeof(srv_mre_appmgr_installed_info_struct),&size);
            FS_Close(file_hdl);
        }
    }
    if (installed_info != NULL)
    {
        vm_free(installed_info);
    }
    if(ret == MMI_TRUE)
    { 
    	  U8 set_shortcut[4] = {0};
    	  U32 shortcut_size = 4;
    	  vm_get_vm_tag(app_path, VM_CE_INFO_IDLE_SHORTCUT, set_shortcut, &shortcut_size);
        if (app_name != NULL)
        {
            //mmi_wcscpy((WCHAR*) app_name, (WCHAR*) temp_app_name);
            mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)temp_app_name, (char *)app_name, MMI_APP_NAME_MAX_LEN);
            if(install_flag==1)
            {
                //srv_appmgr_update_app_info(app_name, EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE);
                srv_appmgr_update_app_info_ex(app_name,EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,&set_shortcut[0],sizeof(set_shortcut[0]));
            }
            else
            {
                //srv_appmgr_update_app_info(app_name, EVT_ID_SRV_APPMGR_INSTALL_PACKAGE);
                srv_appmgr_update_app_info_ex(app_name,EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,&set_shortcut[0],sizeof(set_shortcut[0]));
            }
        }
        else
        {
            char app_name_internal[MMI_APP_NAME_MAX_LEN];
            mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)temp_app_name, (char *)app_name_internal, MMI_APP_NAME_MAX_LEN);
            if(install_flag==1)
            {
                //srv_appmgr_update_app_info(app_name_internal, EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE);
                srv_appmgr_update_app_info_ex(app_name_internal,EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,&(set_shortcut[0]),sizeof(set_shortcut[0]));
            }
            else
            {
               // srv_appmgr_update_app_info(app_name_internal, EVT_ID_SRV_APPMGR_INSTALL_PACKAGE);
               srv_appmgr_update_app_info_ex(app_name_internal,EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,&(set_shortcut[0]),sizeof(set_shortcut[0]));
            }
        }    
    }
    //srv_mre_appmgr_clear_cache();
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_E5, ret);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_install_app
* DESCRIPTION
*  Install an application.
* PARAMETERS
*  app_path : [IN] the application path.
*  app_type : [IN] the application type.
*  app_name : [OUT] the application identification.
* RETURN VALUES
*  MMI_TRUE: If successful.
*  MMI_FALSE: If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_install_app(
                                    U16 *app_path,
                                    srv_mre_appmgr_app_type_enum app_type,
                                    mmi_app_package_char *app_name)
{
    return srv_mre_appmgr_install_app_internal(app_path,app_type,app_name,MMI_FALSE);   //0:install; 1:update install
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_type
* DESCRIPTION
*  Get application type.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app type.
*****************************************************************************/
srv_mre_appmgr_app_type_enum srv_mre_appmgr_get_app_type(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    srv_mre_appmgr_app_type_enum app_type = SRV_MRE_APPMGR_APP_TYPE_UNKNOWN;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return SRV_MRE_APPMGR_APP_TYPE_UNKNOWN;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        app_type = installed_info.app_type;
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
    }

    return app_type;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_storage_position
* DESCRIPTION
*  Get application storage position.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app storage position.
*****************************************************************************/
srv_mre_appmgr_app_storage_position_enum srv_mre_appmgr_get_app_storage_position(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    srv_mre_appmgr_app_storage_position_enum position = SRV_MRE_APPMGR_APP_POSITION_UNKNOWN;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return SRV_MRE_APPMGR_APP_POSITION_UNKNOWN;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        position = installed_info.store_pos;
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
    }

    return position;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_description
* DESCRIPTION
*  Get the description of a MRE application. If p_desc is NULL, then return the description size by desc_size.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_desc : [OUT] Pointer to app description buffer.
*  desc_size : [OUT] Size of app description.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_app_description(mmi_app_package_char *app_name, U16 *p_desc, U32 *desc_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (srv_mre_appmgr_get_file_path(app_name, filepath))
    {
        if (srv_mre_get_app_description(filepath, p_desc, desc_size))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_size
* DESCRIPTION
*  Get application size.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app size.
*****************************************************************************/
U32 srv_mre_appmgr_get_app_size(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 size = 0;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return 0;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        size = installed_info.app_size;
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
    }

    return size;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_developer
* DESCRIPTION
*  Get the developer name of a MRE application. If p_developer is NULL, then return the name size by developer_size.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_developer : [OUT] Pointer to developer name buffer, and the length of number less than 10.
*  developer_size : [OUT] Size of developer name.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_app_developer(mmi_app_package_char *app_name, U16 *p_developer, U32 *developer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!developer_size)
    {
        return MMI_FALSE;
    }

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (p_developer == NULL)
    {
        *developer_size = SRV_MRE_APPMGR_DEVELOPER_NAME_LEN;
        return MMI_TRUE;
    }
    else if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        mmi_wcsncpy(p_developer, installed_info.developer, SRV_MRE_APPMGR_DEVELOPER_NAME_LEN);
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_tel
* DESCRIPTION
*  Get the telephone number of the developer.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_tel : [OUT] Pointer to telephone number buffer, and the length of number less than 20.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_app_tel(mmi_app_package_char *app_name, U16 *p_tel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_installed_info_struct installed_info;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        mmi_wcsncpy(p_tel, installed_info.tel, SRV_MRE_APPMGR_TEL_NUM_LEN);
        //srv_mre_appmgr_set_cache(app_name,&installed_info);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_support_uninstall
* DESCRIPTION
*  Check if the application support uninstall.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If support uninstall.
*  MMI_FALSE : If not support uninstall.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_support_uninstall(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_appmgr_app_type_enum app_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_type = srv_mre_appmgr_get_app_type(app_name);
    if (app_type == SRV_MRE_APPMGR_APP_TYPE_ROM || app_type == SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

//#ifdef __MMI_APP_MANAGER_SUPPORT__  
void srv_mre_appmgr_app_uninstall_ex(mmi_app_package_char *app_name, srv_appmgr_uninstall_cb cb_fct, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = srv_mre_appmgr_app_uninstall(app_name);
    if(MMI_TRUE == result)
    {
        cb_fct(SRV_APPMGR_CB_EVENT_DONE,user_data);
    }
    else
    {
        cb_fct(SRV_APPMGR_CB_EVENT_ERROR,user_data);
    }
}

static void srv_mre_appmgr_get_image_full_path(U32 index,WCHAR *app_name_w,WCHAR *image_path)
{
    if(g_mre_appmgr_maptable[index].image_position== 1)
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PHONE_DRV);
    }
    else
    {
        kal_wsprintf(image_path, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    }
    mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_FOLDER);

    mmi_wcscat(image_path, (const WCHAR*)app_name_w);//app_name_w is app_package_name

    //mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_POSTFIX);

    if (g_mre_appmgr_maptable[index].icon_type == 1)
        mmi_wcscat(image_path, L".pbm");
    else if (g_mre_appmgr_maptable[index].icon_type == 2)
        mmi_wcscat(image_path, L".ab2");
    else
        mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_POSTFIX);
}


static void srv_mre_appmgr_app_uninstall_vsp(U32 app_unique_id)
{
    //S32 type;
    U32 index = 0;
    WCHAR image_path[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    index = app_unique_id - SRV_MRE_APPMGR_ID_BASE;
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)(g_mre_appmgr_maptable[index].app_install_name), (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);
    srv_mre_appmgr_get_image_full_path(index,app_name_w,image_path);    
    FS_Delete(image_path);
    //update g_maptable
    memset(&g_mre_appmgr_maptable[index],0,sizeof(srv_mre_appmgr_map_table));
    srv_mre_appmgr_write_maptable();

    /* remove app installed info file */
    srv_mre_appmgr_get_app_folder(app_name_w,info_path);
    mmi_wcscat(info_path, (const WCHAR*)app_name_w);
    FS_Delete(info_path);
}
//#endif

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_app_uninstall
* DESCRIPTION
*  Uninstall an application.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If uninstall successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_app_uninstall(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR image_path[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 app_name_strlen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || !srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        return MMI_FALSE;
    }
    app_name_strlen = mmi_wcslen(app_name_w);
    while(app_name_w[app_name_strlen-1]==L' ')
    {
        app_name_w[app_name_strlen-1]=L'\0';
        app_name_strlen = mmi_wcslen(app_name_w);
    }


    if (installed_info.app_type & SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
    {

        U32 temp_app_id;
        U32 temp_unique_id;
        U32 i;
        U32 info_size_written;
        FS_HANDLE info_hdl;
        U32 index;
        U32 child_id=0;

        /* Check whether the app is installed */
        if (installed_info.app_size <= 0)
        {
            return MMI_FALSE;
        }
        //#if (defined(__PLUTO_MMI_PACKAGE__))&&(  !defined(__MMI_FTE_SUPPORT__))

        index = installed_info.app_unique_id - SRV_MRE_APPMGR_ID_BASE;
        srv_mre_appmgr_get_image_full_path(index,app_name_w,image_path);

        FS_Delete(image_path);
        child_id = installed_info.child_unique_id;
        temp_app_id = installed_info.app_id;
        temp_unique_id = installed_info.app_unique_id;
        memset(&installed_info, 0, sizeof(srv_mre_appmgr_installed_info_struct));
        installed_info.app_id = temp_app_id;
        installed_info.app_unique_id = temp_unique_id;
        installed_info.app_type = SRV_MRE_APPMGR_APP_TYPE_SHORTCUT;
        installed_info.child_unique_id = 0;

        mmi_wcscpy(info_path,mre_app_package_name_prefix[0].app_folder);
        for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
        {
            if (temp_app_id == g_shortcut_info_list[i].app_id)
            {

                kal_wsprintf(installed_info.app_path,"@:\\");
                kal_wstrcat(installed_info.app_path,(WCHAR*)GetString(g_shortcut_info_list[i].name_id));
                kal_wsprintf(installed_info.app_path+kal_wstrlen(installed_info.app_path),"_%d.sht",g_shortcut_info_list[i].app_id);
                mmi_wcscat((WCHAR*) info_path, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX);
                kal_wsprintf((WCHAR*) info_path+mmi_wcslen(info_path),"%d",g_shortcut_info_list[i].app_id);
                break;
            }
        }
        FS_Delete(info_path);   /* Firstly delete the info file, then create a new */
        info_hdl = FS_Open(info_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (info_hdl >= FS_NO_ERROR)
        {
            if ((FS_Write(info_hdl, &installed_info, sizeof(srv_mre_appmgr_installed_info_struct), &info_size_written) <
                FS_NO_ERROR) || (info_size_written != sizeof(srv_mre_appmgr_installed_info_struct)))
            {
                FS_Close(info_hdl);
                FS_Delete(info_path);
                return MMI_FALSE;   /* Write app info failed */
            }
            FS_Close(info_hdl);
#ifdef __LOW_COST_SUPPORT_COMMON__
            srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info.app_type),(U16)(installed_info.app_unique_id),NULL,NULL,NULL,0,0);
#else
            srv_mre_appmgr_get_avaible_unique_id(NULL,(U16)(installed_info.app_type),(U16)(installed_info.app_unique_id),NULL,NULL,NULL,NULL,0,0);
#endif
#ifdef __MRE_SAL_PN__        
            srv_mre_push_receiver_uninstall(app_name_w);
            /* remove app push info file */
#endif        
            if(child_id>0)
            {
                srv_mre_appmgr_app_uninstall_vsp(child_id);
            }
            /* notify to AppMgr */
            {
                //vapp_mainmenu_app_state_notify(VAPP_MAINMENU_NOTIFY_APP_CHANGE, app_name);
                srv_appmgr_update_app_info(app_name, EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE);
            }

        }
        else
        {
            return MMI_FALSE;   /* Create info file failed */
        }
    }
    else
    {
        //S32 type;
        U32 index;
        index = installed_info.app_unique_id - SRV_MRE_APPMGR_ID_BASE;
        srv_mre_appmgr_get_image_full_path(index,app_name_w,image_path);
        FS_Delete(image_path);
        memset(&g_mre_appmgr_maptable[index],0,sizeof(srv_mre_appmgr_map_table));
        srv_mre_appmgr_write_maptable();

        /* remove app installed info file */
        srv_mre_appmgr_get_app_folder(app_name_w,info_path);
        mmi_wcscat(info_path, (const WCHAR*)app_name_w);
        FS_Delete(info_path);
#ifdef __MRE_SAL_PN__        
        srv_mre_push_receiver_uninstall(app_name_w);
#endif        
        if(installed_info.child_unique_id>0)
        {
            srv_mre_appmgr_app_uninstall_vsp(installed_info.child_unique_id);
        }

        if (installed_info.app_type & SRV_MRE_APPMGR_APP_TYPE_ROM)
        {
            U16* p = installed_info.app_path+kal_wstrlen(installed_info.app_path)-1;
            while (*p != (U16)'\\')
            {
                p--;
            }
            info_path[0] = (U16)'@';
            info_path[1] = (U16)':';
            info_path[2] = 0; 
            kal_wstrcat(info_path,p);
            memset(info_path+kal_wstrlen(info_path)-4, 0, 2);
            kal_wstrcat(info_path,L".rom");
            srv_mre_appmgr_install_app(info_path,SRV_MRE_APPMGR_APP_TYPE_ROM,NULL);
        }    
    }

    //srv_mre_appmgr_clear_cache();
    /* notify to AppMgr */
    //    vapp_mainmenu_app_state_notify(VAPP_MAINMENU_NOTIFY_APP_CHANGE, app_name);
    if (!(installed_info.app_type & SRV_MRE_APPMGR_APP_TYPE_SHORTCUT))
    {
        srv_appmgr_update_app_info(app_name, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE);
    }
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_downloading
* DESCRIPTION
*  Check if the application is downloading in background.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If downloading in background.
*  MMI_FALSE : If not downloading in background.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_bg_downloading(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
    U32 appid;
    S32 status;
    #endif
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef MMI_DLA_MRE_SUPPORT
    /* get appid */
    appid = srv_mre_appmgr_get_appid(app_name_w);
#ifdef __MMI_DOWNLOAD_AGENT__
    status = srv_da_mre_get_download_status(appid);
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_APPMGR_IS_BG_DOWNLOADING, appid, status);
    if ((status == SRV_DA_MRE_DOWNLOAD_INITIALIZING) ||
        (status == SRV_DA_MRE_DOWNLOAD_DOWNLOADING) ||
        (status == SRV_DA_MRE_DOWNLOAD_PAUSED) ||
        (status == SRV_DA_MRE_DOWNLOAD_WAITING) ||
        (status == SRV_DA_MRE_DOWNLOAD_FAILED))
    {
        return MMI_TRUE;
    }
#endif
#endif /* MMI_DLA_MRE_SUPPORT */
#endif

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_downloading_by_path
* DESCRIPTION
*  Check if the application is downloading in background.
* PARAMETERS
*  app_path : [IN] the application file path.
* RETURN VALUES
*  MMI_TRUE : If downloading in background.
*  MMI_FALSE : If not downloading in background.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_bg_downloading_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
    U32 appid;
    S32 status;
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return MMI_FALSE;
    }

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef MMI_DLA_MRE_SUPPORT

    /* get appid */
    if (srv_mre_get_app_id(app_path, &appid))
    {
        status = srv_da_mre_get_download_status(appid);
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_APPMGR_IS_BG_DOWNLOADING_BY_PATH, appid, status);
        if ((status == SRV_DA_MRE_DOWNLOAD_INITIALIZING) ||
            (status == SRV_DA_MRE_DOWNLOAD_DOWNLOADING) ||
            (status == SRV_DA_MRE_DOWNLOAD_PAUSED) ||
            (status == SRV_DA_MRE_DOWNLOAD_WAITING) ||
            (status == SRV_DA_MRE_DOWNLOAD_FAILED))
        {
            return MMI_TRUE;
        }
    }
#endif /* MMI_DLA_MRE_SUPPORT */  
#endif
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed_by_develop_and_name
* DESCRIPTION
*  by app_name and app develop name to determine a mre app is installed or not.
* PARAMETERS
*  app_name ,app_dev: [IN] the application identification. [OUT]app_package_name
* RETURN VALUES
*  void
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_app_installed_by_develop_and_name(S32 app_type, U16 *app_name,U16* app_dev,U16 *app_package_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 temp_app_name[MMI_APP_NAME_MAX_LEN];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    FS_HANDLE file_hdl;
    U32 index=0;
    U32 find = 0;
    // S32 file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_name == NULL||app_dev == NULL)
    {
        return MMI_FALSE;
    }

    /* Generate app id */
    for(;index<sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix);index++)
    {
        if (mre_app_package_name_prefix[index].app_type == app_type)
        {
            //kal_wsprintf(temp_app_name,"%w",mre_app_package_name_prefix[index].app_package_name_prefix);
            find = 1;
            break;
        }
    }
    if(find==0)
    {
        index--;
    }
    kal_wsprintf(temp_app_name,"%w%w.%w",mre_app_package_name_prefix[index].app_package_name_prefix,app_dev,app_name);
    srv_mre_appmgr_get_app_folder( temp_app_name,info_path);

    mmi_wcscat(info_path, (const WCHAR*)temp_app_name);
    if(app_package_name!=NULL)
    {
        U32 app_name_len=0;
        U32 index = 0;
        app_name_len = mmi_wcslen(app_name);
        for(index=0;index<app_name_len;index++)
        {
            if(app_name[index]==0xFFFF)
                app_name[index]=L'_';
        }
        mmi_wcscpy(app_package_name,temp_app_name);
    }

    /* Check whether the app is installed */
    file_hdl = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        FS_Close(file_hdl);

        /* Check whether the app is shortcut app */
        if (mmi_wcsnicmp((const WCHAR*)temp_app_name, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX, 13) == 0)
        {
            srv_mre_appmgr_installed_info_struct installed_info;
            if (srv_mre_appmgr_get_installed_info(temp_app_name, &installed_info) && installed_info.app_size != 0)
            {
                ret = MMI_TRUE;
            }
        }
        else
        {
            ret = MMI_TRUE;
        }
    }

    return ret;

}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_download
* DESCRIPTION
*  Download a shortcut application from main menu.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  void
*****************************************************************************/
void srv_mre_appmgr_download(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
    U32 appid;
    #endif
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return;
    }

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef MMI_DLA_MRE_SUPPORT
    /* get appid */
    appid = srv_mre_appmgr_get_appid(app_name_w);
    if (srv_mre_appmgr_is_bg_downloading(app_name))
    {
        srv_da_mre_enter_download_list(appid); // TODO: verify this point
    }
    else
    {
        srv_da_mre_start_new_download(appid); // TODO: verify this point
    }
#endif /* #ifdef MMI_DLA_MRE_SUPPORT */
#endif
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_running
* DESCRIPTION
*  Check if the application is running in background.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If running in background.
*  MMI_FALSE : If not running in background.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_bg_running(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
    //S32 file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_mre_appmgr_get_file_path(app_name, filepath))
    {     
        return srv_mre_is_app_bg_running(filepath);
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_exist
* DESCRIPTION
*  Check if the application exist or not.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If app exists.
*  MMI_FALSE : If app not exist.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_app_exist(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
    MMI_BOOL ret = MMI_FALSE;
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mre_appmgr_get_file_path(app_name, filepath))
    {
        // add start for MAUI_02932436 
        // In COSMOS,we can not start preinstall app,so I change here.
        U8 tmp_filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
        vm_ucs2_to_ascii((char *)tmp_filepath, SRV_MRE_APPMGR_FILEPATH_LEN,(short *)filepath);
        if((strstr((const mmi_app_package_char *)tmp_filepath,".rom"))||(strstr((const mmi_app_package_char *)tmp_filepath,".ROM")))
        {
            return MMI_TRUE;
        }
        // add end for MAUI_02932436
        fd = FS_Open(filepath, FS_OPEN_NO_DIR | FS_READ_ONLY);
        if (fd < FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
        FS_Close(fd);
        ret = MMI_TRUE;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_shortcut_app
* DESCRIPTION
*  Check if the application is shortcut app.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If it is shortcut app.
*  MMI_FALSE : If it is not shortcut app.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_shortcut_app(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (mmi_wcsnicmp((const WCHAR*)app_name_w, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX, 13) == 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed
* DESCRIPTION
*  Check if the application is installed.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If the app is installed.
*  MMI_FALSE : If the app is not installed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_app_installed(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    FS_HANDLE fd1;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    //S32 file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    srv_mre_appmgr_get_app_folder(app_name_w,info_path);

    /* Shortcut app will not image file in image folder, so do not check image folder */
    mmi_wcscat(info_path, (const WCHAR*)app_name_w);
    fd1 = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (fd1 >= FS_NO_ERROR)
    {
        if (srv_mre_appmgr_is_shortcut_app(app_name) && srv_mre_appmgr_get_app_size(app_name) == 0)
        {
            ret = MMI_FALSE;    /* uninstalled shortcut app */
        }
        else
        {
            ret = MMI_TRUE;
        }
        FS_Close(fd1);
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed_by_path
* DESCRIPTION
*  Check if the application is installed by app path.
* PARAMETERS
*  app_path : [IN] the application path.
* RETURN VALUES
*  MMI_TRUE : If the app is installed.
*  MMI_FALSE : If the app is not installed.
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_is_app_installed_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 temp_app_name[MMI_APP_NAME_MAX_LEN];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    FS_HANDLE file_hdl;
    //S32 file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return MMI_FALSE;
    }

    /* Generate app id */
    memset(temp_app_name, 0, sizeof(temp_app_name));
    if (!srv_mre_appmgr_generate_identification(app_path, temp_app_name))
    {
        return MMI_FALSE;
    }

    srv_mre_appmgr_get_app_folder(temp_app_name,info_path);

    mmi_wcscat(info_path, (const WCHAR*)temp_app_name);

    /* Check whether the app is installed */
    file_hdl = FS_Open(info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        FS_Close(file_hdl);

        /* Check whether the app is shortcut app */
        if (mmi_wcsnicmp((const WCHAR*)temp_app_name, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX, 13) == 0)
        {
            srv_mre_appmgr_installed_info_struct installed_info;
            if (srv_mre_appmgr_get_installed_info(temp_app_name, &installed_info) && installed_info.app_size != 0)
            {
                ret = MMI_TRUE;
            }
        }
        else
        {
            ret = MMI_TRUE;
        }
    }

    return ret;
}
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_num
* DESCRIPTION
*  Get the number of the MRE applications according to the flag.
* PARAMETERS
*  flag : [IN] application manager service flag.
* RETURNS
*  return the number of all application package
*****************************************************************************/
U32 srv_mre_appmgr_get_app_num(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR filename[SRV_MRE_APPMGR_PATH_SIZE];
    //S32 app_num = 0;
    //U32 pre_app_num = 0;
    U32 return_num = 0;
    U32 i;
    //mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN];
    //U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    U32 vxp_num = 0,widget_num = 0,wallpaper_num = 0;
    U32 launcher_num = 0,scrlock_num = 0;
    U32 rom_num = 0,shortcut_num = 0;
    U32 vsp_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("MJ1");
    for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
    {
        if(g_mre_appmgr_maptable[i].unique_appid)
        {
            switch(g_mre_appmgr_maptable[i].app_install_type)
            {
            case SRV_MRE_APPMGR_APP_TYPE_VXP:
            case SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD:
            case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_SHORTCUT):
            case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_ROM):
                vxp_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
            case (SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WIDGET):
                widget_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
            case (SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WALLPAPER):
                wallpaper_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
            case (SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_LAUNCHER):
                launcher_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
            case (SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_SCRLOCK):
                scrlock_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_ROM:
                rom_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_SHORTCUT:
                shortcut_num ++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_SERVICE:
                vsp_num++;
                break;
            case SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL:// this case not have
                break;
            default:break;

            }
        }
    }

    switch(flag)
    {
    case SRV_APPMGR_INSTALLED_WIDGET_PACKAGE_FLAG_TYPE:
        return_num = widget_num;
        break;
    case SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE:
        return_num = wallpaper_num;
        break;
    case SRV_APPMGR_INSTALLED_LAUNCHER_PACKAGE_FLAG_TYPE:
        return_num = launcher_num;
        break;
    case SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE:
        return_num = scrlock_num;
        break;
    case SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE:
        return_num = widget_num+wallpaper_num+launcher_num+scrlock_num;
        break;
    case SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE:
        //case SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE:
        return_num = shortcut_num;
        break;
    case SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE:
    case SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE:
        return_num = vxp_num + rom_num;
        break;
    case SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE:
        return_num = vxp_num;
        break;
    case SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE:
        return_num = vsp_num;
        break;
    default:break;
    }
    MRE_SWLA_STOP("MJ1");
    MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_APP_NUM,flag,return_num);
    return return_num;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_app_num
* DESCRIPTION
*  Get the number of the installed applications, 
*   including build-in applications. But not include shortcut applications.
* PARAMETERS
*  void
* RETURNS
*  return the number of all application package
*****************************************************************************/
U32 srv_mre_appmgr_get_installed_app_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //    return srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    int x = 0;
    x = srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
    return x;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_unique_id_list
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application id of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_unique_app_id_list(S32 flag, U32 *unique_id_array, U32 num)
{

    return srv_mre_appmgr_get_app_list_internal(flag,unique_id_array,num,MMI_FALSE);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_unique_app_id
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/
U32 srv_mre_appmgr_get_unique_app_id(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 app_id = 0;
    U32 i=0;
    MRE_SWLA_START("MJ7");
    for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
    {
        if (0 == strcmp(app_name, g_mre_appmgr_maptable[i].app_install_name))
        {
            app_id = i+SRV_MRE_APPMGR_ID_BASE;
            break;
        }
    }
    MRE_SWLA_STOP("MJ7");
    return app_id;
}
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_package_name_by_unique_id
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_package_name_by_unique_id(U32 id,mmi_app_package_char *app_name)
{
    S32  index = id-SRV_MRE_APPMGR_ID_BASE;
    MRE_SWLA_START("MJ6");
    if(index>=0&&index<SRV_MRE_APPMGR_INSTALLED_APP_MAX&&g_mre_appmgr_maptable[index].unique_appid)
    {
        memcpy(app_name, g_mre_appmgr_maptable[index].app_install_name,MMI_APP_NAME_MAX_LEN);
    }
    else 
    {
        MRE_SWLA_STOP("MJ6");
        return MMI_RET_ERR;
    }
    MRE_SWLA_STOP("MJ6");
    return MMI_RET_OK;

}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_list_internal
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
static mmi_ret srv_mre_appmgr_get_app_list_internal(S32 flag, void *name_array, U32 num,MMI_BOOL list_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    // WCHAR filename[SRV_MRE_APPMGR_PATH_SIZE];
    //WCHAR app_name_w[MMI_APP_NAME_MAX_LEN];
    //S32 search_hdl = 0, search_ret = FS_NO_ERROR;
    //FS_DOSDirEntry de;
    U32 i = 0,j=0;
    U32 * name_array_int = NULL;
    mmi_app_package_name_struct * name_array_char = NULL;
    MRE_SWLA_START("MJ5");
    if(list_type)
    {
        name_array_char = (mmi_app_package_name_struct *)name_array;
    }
    else
    {
        name_array_int = (U32 *)name_array;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(flag)
    {
    case SRV_APPMGR_INSTALLED_WIDGET_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&((g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_WIDGET)||
                    (g_mre_appmgr_maptable[i].app_install_type==(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WIDGET))))
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&((g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_WALLPAPER)||
                    (g_mre_appmgr_maptable[i].app_install_type==(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WALLPAPER))))
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_LAUNCHER_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&((g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_LAUNCHER)||
                    (g_mre_appmgr_maptable[i].app_install_type==(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_LAUNCHER))))
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&((g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_SCRLOCK)||
                    (g_mre_appmgr_maptable[i].app_install_type==(SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_SCRLOCK))))
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid)    
                {
                    switch(g_mre_appmgr_maptable[i].app_install_type)
                    {
                    case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
                    case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
                    case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
                    case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
                    case SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WIDGET:
                    case SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
                    case SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
                    case SRV_MRE_APPMGR_APP_TYPE_ROM_VPP|SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
                        if(list_type)
                        {
                            memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                        }
                        else
                        {
                            name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                        }
                        j++;
                        break;
                    default:break;
                    }
                }
            }
        }
        break;
    case SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE:
        //  case SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
        break;
    case SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE:
    case SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid)    
                {
                    switch(g_mre_appmgr_maptable[i].app_install_type)
                    {
                    case SRV_MRE_APPMGR_APP_TYPE_VXP:
                    case SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD:
                    case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_SHORTCUT):
                    case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_ROM):
                    case SRV_MRE_APPMGR_APP_TYPE_ROM:
                        if(list_type)
                        {
                            memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                        }
                        else
                        {
                            name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                        }
                        j++;
                        break;
                    default:break;
                    }
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid)    
                {
                    switch(g_mre_appmgr_maptable[i].app_install_type)
                    {
                    case SRV_MRE_APPMGR_APP_TYPE_VXP:
                    case SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD:
                    case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_SHORTCUT):
                    case (SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL|SRV_MRE_APPMGR_APP_TYPE_ROM):
                        if(list_type)
                        {
                            memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                        }
                        else
                        {
                            name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                        }
                        j++;
                        break;
                    default:break;
                    }
                }
            }
        }
        break;
    case SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE:
        {
            for(i=0;i<SRV_MRE_APPMGR_INSTALLED_APP_MAX;i++)
            {
                if(g_mre_appmgr_maptable[i].unique_appid
                    &&g_mre_appmgr_maptable[i].app_install_type==SRV_MRE_APPMGR_APP_TYPE_SERVICE)
                {
                    if(list_type)
                    {
                        memcpy(name_array_char[j], g_mre_appmgr_maptable[i].app_install_name,MMI_APP_NAME_MAX_LEN);
                    }
                    else
                    {
                        name_array_int[j]= i+SRV_MRE_APPMGR_ID_BASE;
                    }
                    j++;
                }
            }
        }
    default:break;
    }
    MRE_SWLA_STOP("MJ5");
    return ret;
}
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_list
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_list(S32 flag, mmi_app_package_name_struct *name_array, U32 num)
{
    return srv_mre_appmgr_get_app_list_internal(flag,name_array,num,MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_app_list
* DESCRIPTION
*  Get the application identifications, not include shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_installed_app_list(mmi_app_package_name_struct *name_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (num < srv_mre_appmgr_get_installed_app_num())
    {
        return MMI_RET_ERR;
    }
    //    return srv_mre_appmgr_get_app_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, name_array, num);
    return srv_mre_appmgr_get_app_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, name_array, num);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_name
* DESCRIPTION
*  Get the name of application.
* PARAMETERS
*  app_name  : [IN] the application package identification.
*  string    : [OUT] the application name.
* RETURN VALUES
*  MMI_RET_OK: Get the application name successfully.
*  MMI_RET_ERR: Get the application name fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_name(mmi_app_package_char *app_name, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_mre_appmgr_installed_info_struct installed_info;
    U8 *lang = NULL;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    U32 unique_app_id = 0;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("MJ2");
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || string == 0)
    {
        return MMI_RET_ERR;
    }

    unique_app_id = srv_mre_appmgr_get_unique_app_id(app_name);
    index = unique_app_id - SRV_MRE_APPMGR_ID_BASE;
    if(unique_app_id!=0&&index>=0)
    {
        if (!(g_mre_appmgr_maptable[index].app_install_type & SRV_MRE_APPMGR_APP_TYPE_VPP)&& (g_mre_appmgr_maptable[index].app_install_type& SRV_MRE_APPMGR_APP_TYPE_SHORTCUT))        /* shortcut app */
        {
            U32 i;
            U32 temp_app_id = g_mre_appmgr_maptable[index].app_id;
            /* Get app id */
            for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
            {
                if (temp_app_id == g_shortcut_info_list[i].app_id)
                {
                    mmi_wcscpy(string, (const WCHAR*)GetString(g_shortcut_info_list[i].name_id));
                    break;
                }
            }
        }
        else
        {
            lang = Get_Current_Lang_CountryCode();
            if (strcmp((PS8) lang, "en-US") == 0)   /* means English */
            {
                mmi_wcsncpy(string,(WCHAR *)(g_mre_appmgr_maptable[index].app_name)[0],SRV_MRE_APPMGR_APP_NAME_LEN-1);
            }
            else if (strcmp((PS8) lang, "zh-CN") == 0)
            {
                mmi_wcsncpy(string,(WCHAR *)(g_mre_appmgr_maptable[index].app_name)[1],SRV_MRE_APPMGR_APP_NAME_LEN-1);            
            }
            else if (strcmp((PS8) lang, "zh-TW") == 0)
            {
#ifdef __LOW_COST_SUPPORT_COMMON__
                mmi_wcsncpy(string, g_mre_appmgr_maptable[index].app_name[1],MMI_APP_NAME_MAX_LEN - 1);
#else
                mmi_wcsncpy(string, g_mre_appmgr_maptable[index].app_name[2],MMI_APP_NAME_MAX_LEN - 1);
#endif
            }
            else    /* default English */
            {
                mmi_wcsncpy(string,(WCHAR *)(g_mre_appmgr_maptable[index].app_name)[0],SRV_MRE_APPMGR_APP_NAME_LEN-1);                
            }
        }
        MRE_SWLA_STOP("MJ2");
        return MMI_RET_OK;
    }
    MRE_SWLA_STOP("MJ2");
    return MMI_RET_ERR;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_image
* DESCRIPTION
*  Get the image of application.
* PARAMETERS
*  app_name  : [IN] the application identification.
*  image     : [OUT] the application image.
* RETURN VALUES
*  MMI_RET_OK: Get the application image successfully.
*  MMI_RET_ERR: Get the application image fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_image(mmi_app_package_char *app_name, mmi_image_src_struct *image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[SRV_MRE_APPMGR_PATH_SIZE];
    //FS_HANDLE fd = -1;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    U32 unique_app_id = 0;
    S32 index = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("MJ3");
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || image == NULL)
    {
        return MMI_RET_ERR;
    }

    /* Check app type, if the app is shortcut app, return resid */
    unique_app_id = srv_mre_appmgr_get_unique_app_id(app_name);
    index = unique_app_id - SRV_MRE_APPMGR_ID_BASE;
    /* Check app type, if the app is shortcut app, return resid */
    if(unique_app_id!=0&&index>=0)
    {
        if (g_mre_appmgr_maptable[index].app_install_type == SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
        {
            U32 i;
            U32 temp_app_id;

            /* Get app id */
            temp_app_id = g_mre_appmgr_maptable[index].app_id;;
            image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
            for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
            {
                if (temp_app_id == g_shortcut_info_list[i].app_id)
                {
#if defined(__MMI_VUI_LAUNCHER__) && defined(__MMI_VUI_LAUNCHER_KEY__) 
                    if (MMI_PHNSET_LAUNCHER_KEY == mmi_phnset_launcher_get_launcher_type())
                    {
                        image->data.res_id = g_shortcut_info_list[i].icon_id + 1;
                    }
                    else
                    {
                        image->data.res_id = g_shortcut_info_list[i].icon_id;
                    }
#else
                    image->data.res_id = g_shortcut_info_list[i].icon_id;
#endif
                    break;
                }
            }
            MRE_SWLA_STOP("MJ3");
            return MMI_RET_OK;
        }
        if((g_mre_appmgr_maptable[index].app_install_type != SRV_MRE_APPMGR_APP_TYPE_ROM)&&(!(g_mre_appmgr_maptable[index].app_install_type&SRV_MRE_APPMGR_APP_TYPE_ROM_VPP)))
        {
            if(g_mre_appmgr_maptable[index].image_position&&g_mre_appmgr_maptable[index].has_image_in_tcard)
            {
                srv_mre_appmgr_get_image_full_path(index,app_name_w,filename);
                if(mre_push_usb_ms_mode)
                {
                    image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
                    image->data.res_id = IMG_ID_AM_APP_MRE_DEFAULT;
                }
                else
                {
                    image->type = MMI_IMAGE_SRC_TYPE_PATH;
                    mmi_wcscpy((WCHAR*) image->data.path, filename);
                }
                return MMI_RET_OK;
            }
            if(mre_push_usb_ms_mode||mre_push_dev_plug_out)
            {
                image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
                image->data.res_id = IMG_ID_AM_APP_MRE_DEFAULT;
                return MMI_RET_OK;
            }
            if(g_mre_appmgr_maptable[index].has_image_in_tcard)
            {
                srv_mre_appmgr_get_image_full_path(index,app_name_w,filename);
                if(srv_fmgr_drv_is_accessible((U8)filename[0])==MMI_FALSE)
                {
                    image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
                    image->data.res_id = IMG_ID_AM_APP_MRE_DEFAULT;
                    return MMI_RET_OK;
                }
                image->type = MMI_IMAGE_SRC_TYPE_PATH;
                mmi_wcscpy((WCHAR*) image->data.path, filename);

                MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_GET_IMG_INFO, g_mre_appmgr_maptable[index].icon_type, image->type);

                return MMI_RET_OK;
            }
            else
            {
                image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
                image->data.res_id = IMG_ID_AM_APP_MRE_DEFAULT;
                return MMI_RET_OK;
            }
        }
        else    /* reutrn default image */
        {
            if((g_mre_appmgr_maptable[index].app_install_type == SRV_MRE_APPMGR_APP_TYPE_ROM )||(g_mre_appmgr_maptable[index].app_install_type&SRV_MRE_APPMGR_APP_TYPE_ROM_VPP))
            {

               // srv_mre_load_core_result_enum load_mre_core_ret;
                U16 * app_path =NULL;
                U32 resoffset = 0;
                U8* ptr = NULL;
                S32 chset_type_size;
                U32 img_size = 0;
                app_path = g_mre_appmgr_maptable[index].rom_app_path;
                ptr = vm_get_execrom_ptr((short *)app_path);
                resoffset= vm_get_resource_offset_from_file((S16 *)app_path,SRV_MRE_APP_AB2_LOGO);
                if (resoffset == 0)
                {
                    if (vm_get_vm_tag((PS16)app_path, VM_CE_INFO_CHARSET, NULL, &chset_type_size) == GET_TAG_TRUE)
                    {
                        resoffset= vm_get_resource_offset_from_file((S16 *)app_path,SRV_MRE_APP_NEW_LOGO);
                        //resoffset +=sizeof(SRV_MRE_APP_NEW_LOGO);
                    }
                    else
                    {
                        resoffset =vm_get_resource_offset_from_file((S16 *)app_path,SRV_MRE_APP_LOGO);
                        //resoffset +=sizeof(SRV_MRE_APP_LOGO);
                    }
                }
                //}
                //}
                //srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
                if(resoffset)
                {
                    S32 tag_size = 4;
                    U8  tag_buf[4];
                    U32 header_size = 0;

                    memset(tag_buf, 0, 4);

                    /* Check does it have 8 byte header */
                    if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_ADV_ICON, &tag_buf, &tag_size) != GET_TAG_TRUE)
                    {
                        tag_buf[0] = 0;
                    }

                    if (tag_buf[0] == 1)
                    {
                        header_size = 8;
                    }


                    image->data.image.image_ptr = ptr+resoffset+13+10+header_size;
                    img_size = *(ptr+resoffset + 13 + 6+header_size) +
                        ((*(ptr+resoffset+ 13 + 7 + header_size)) << 8) + ((*(ptr+resoffset + 13 + 8 + header_size)) << 16) + ((*(ptr+resoffset + 13 + 9 + header_size)) << 24);
                    image->type = MMI_IMAGE_SRC_TYPE_ROM_MEMORY;
                    image->data.image.image_len = img_size;
                    MRE_SWLA_STOP("MJ3");
                    return MMI_RET_OK;
                }

            }
            image->type = MMI_IMAGE_SRC_TYPE_RES_ID;
            image->data.res_id = IMG_ID_AM_APP_MRE_DEFAULT;
        } 
    }


    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_info
* DESCRIPTION
*  Get the information of application.
* PARAMETERS
*  app_name  : [IN] the application identification.
*  info      : [OUT] the application information.
* RETURN VALUES
*  MMI_RET_OK: Get the application information successfully.
*  MMI_RET_ERR: Get the application information fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_info(mmi_app_package_char *app_name, srv_app_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("MJ4");
#if defined( __MMI_NSS_SUPPORT__)&&defined(__MRE_SAL_PN__) 
    if(g_mre_is_register_nss_setting_change==MMI_FALSE)
    {
        mmi_srv_nss_register_listener(NSS_MASK_BADGE_ICON,srv_mre_appmgr_listen_setting_change);
        g_mre_is_register_nss_setting_change = MMI_TRUE;
    }
#endif

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || info == NULL)
    {
        return MMI_RET_ERR;
    }

    ret = srv_mre_appmgr_get_app_name(app_name, info->string);
    srv_mre_appmgr_get_app_image(app_name, &(info->image));
#ifdef __MRE_SAL_PN__
    srv_mre_appmgr_get_app_badge(app_name, &(info->badge));
#endif    
    MRE_SWLA_STOP("MJ4");
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_resolution
* DESCRIPTION
*  Get the resolution of application.
* PARAMETERS
*  app_name  : [IN] the application package identification.
*  width    : [OUT] width.
*  height    : [OUT] height. 
* RETURN VALUES
*  MMI_RET_OK: Get the application resolution successfully.
*  MMI_RET_ERR: Get the application resolution fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_resolution(mmi_app_package_char *app_name, U32 *width, U32 *height)
{
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_appmgr_installed_info_struct installed_info;
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (width == NULL || height == NULL || !srv_mre_appmgr_is_mre_app(app_name_w))
    {
        return MMI_FALSE;
    }

    if (srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        *width = installed_info.width;
        *height = installed_info.height;
        // srv_mre_appmgr_set_cache(app_name,&installed_info);
        ret = MMI_TRUE;
    }

    return ret;
}
void vapp_mre_shortcut_install(CHAR* appName,U32 size);
void mmi_mre_shortcut_download(CHAR * appName);

static MMI_ID srv_mre_appmgr_launch_int(
                                        srv_appfactory_launch_type_enum type,
                                        mmi_app_package_char *app_name,
                                        void *param,
                                        U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ////

#ifdef __MRE_SAL_PN__
    {            
        U32 push_num = 0;
        U16 filename[SRV_MRE_APPMGR_PATH_SIZE];
        U16 app_name_w[MMI_APP_NAME_MAX_LEN];
        char app_change_char_name[MMI_APP_NAME_MAX_LEN];
        //CHAR  app_name[MMI_APP_NAME_MAX_LEN] = {'0'};
        S32     search_hdl = -1;
        S32     search_ret  = FS_NO_ERROR;
        FS_DOSDirEntry de;
        U32 i = 0;
        srv_mre_appmgr_push_installed_info_struct push_installed_info;
        push_num = srv_mre_appmgr_get_push_app_num();
        //mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
        //mmi_wcscat(filename, L"*");
        kal_wsprintf(filename,"z:\\@mre\\push\\*");
        search_hdl = FS_FindFirst(filename, 0, FS_ATTR_DIR, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
        if (search_hdl >= 0)
        {
            for(;i<push_num;i++)
            {
                if((search_ret >= FS_NO_ERROR)&&srv_mre_appmgr_get_push_installed_info(app_name_w, &push_installed_info)&& (NULL !=push_installed_info.app_path))
                {
                    mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)(push_installed_info.app_install_name),(char*)app_change_char_name,sizeof(app_change_char_name));
                    if(0 == strncmp(app_name, app_change_char_name, strlen(app_change_char_name)))
                    {
                        if(push_installed_info._badge==0)
                        {
                            (push_installed_info.click_rate.normal_launch_count)++;
                        }
                        else
                        {
                            (push_installed_info.click_rate.badge_launch_count)++;
                        }
                        srv_mre_push_receiver_file_write(push_installed_info.app_id, &push_installed_info,MMI_FALSE);
                        vm_pmng_set_push_app_flag(0);//for send VM_MSG_PUSH message.
                        break;
                    }
                }
                search_ret =  FS_FindNext(search_hdl, &de, app_name_w, MMI_APP_NAME_MAX_LEN * 2);
            }
            FS_FindClose(search_hdl);
        }
    }
#endif

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, can't use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return 0;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    /* Check if it is not downloaded shortcut app */
    if (srv_mre_appmgr_is_shortcut_app(app_name) && !srv_mre_appmgr_is_app_installed(app_name))
    {
#ifdef __COSMOS_MMI_PACKAGE__

        vapp_mre_shortcut_install(app_name,strlen(app_name)+1);
#else
        mmi_mre_shortcut_download(app_name);
#endif
        return 0;
    }

    switch (type)
    {
    case SRV_APP_FACTORY_APP_LAUNCH_TYPE:
#ifdef __COSMOS_MMI_PACKAGE__
        vapp_mre_app_launch(app_name);

#else
        {
            U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
            //U16 app_name_w[MMI_APP_NAME_MAX_LEN];
            //memset(filepath,0,sizeof(filepath));
            //memset(app_name_w,0,sizeof(app_name_w));
            srv_mre_appmgr_get_file_path(app_name, filepath);
            mmi_am_launch_app_by_path(filepath);
        }
#endif
        break;

    case SRV_APP_FACTORY_SETTING_LAUNCH_TYPE:
        // TODO: start mre settings screen from settings center
        break;

    case SRV_APP_FACTORY_SHORTCUT_LAUNCH_TYPE:
        break;

    default:
        return 0;
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_launch
* DESCRIPTION
*  Launch the application
* PARAMETERS
*  app_name : [IN] the application identification.
*  param : [IN] the launch parameter.
*  param_size : [IN] the parameter size.
* RETURNS
*  return the application instance id. You could use the application instance
*  id to communicate between the different running applications.
*****************************************************************************/
MMI_ID srv_mre_appmgr_launch(mmi_app_package_char *app_name, void *param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mre_appmgr_launch_int(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, param, param_size);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_launch_by_filepath
* DESCRIPTION
*  Launch an application by file path.
* PARAMETERS
*  app_path : [IN] the application path.
* RETURNS
*  
*****************************************************************************/
MMI_ID srv_mre_appmgr_launch_by_filepath(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    vapp_mre_app_install(app_path);
#endif
    return 0;
}

// add T-card preinstall code//

#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__

static MMI_BOOL mmi_mre_appmgr_is_alphabet(CHAR ch)
{  
    if (ch >= 'a' && ch <= 'z' ||  
        ch >= 'A' && ch <= 'Z' ||  
        ch>= '0' && ch <= '9')  
        return MMI_TRUE;  
    else  
        return MMI_FALSE;  
}  
static MMI_BOOL mmi_mre_appmgr_is_comment_start(CHAR ch) 
{  
    if (ch == ';' || ch == '#')
    {  
        return MMI_TRUE;  
    } 
    else 
    {  
        return MMI_FALSE;  
    }  
}  
static MMI_BOOL mmi_mre_appmgr_is_sectionlabel_start(CHAR ch) 
{  
    if (ch == '[') 
    {  
        return MMI_TRUE;  
    } 
    else
    {  
        return MMI_FALSE;  
    }  
}  
static MMI_BOOL mmi_mre_appmgr_is_sectionlabel_end(CHAR ch) 
{  
    if (ch == ']') 
    {  
        return MMI_TRUE;  
    } 
    else 
    {  
        return MMI_FALSE;  
    }  
}  
static MMI_BOOL mmi_mre_appmgr_is_key_end(CHAR ch) 
{  
    if (ch == '=') 
    {  
        return MMI_TRUE;  
    } 
    else 
    {  
        return MMI_FALSE;  
    }  
}  
static MMI_BOOL mmi_mre_appmgr_is_value_end(CHAR ch) 
{  
    if (ch == '\n') 
    {  
        return MMI_TRUE;  
    } 
    else
    {  
        return MMI_FALSE;  
    }  
}  
static MMI_BOOL mmi_mre_appmgr_is_comment_end(CHAR ch) 
{  
    if (ch == '\n') 
    {  
        return MMI_TRUE;  
    } 
    else 
    {  
        return MMI_FALSE;  
    }  
} 
static MMI_BOOL srv_mre_appmgr_write_restore_file()
{
    FS_HANDLE tab_hdl     = -1;
    U32 write_size = 0;
    U32 ret = MMI_FALSE;
    WCHAR mre_path[SRV_MRE_APPMGR_PATH_SIZE];
    mmi_wcscpy(mre_path, SRV_MRE_APPMGR_RESTORE_FACTORY_FILE);    
    tab_hdl = FS_Open(mre_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if(tab_hdl >= FS_NO_ERROR)
    {
        if(FS_Write(tab_hdl,&g_mre_appmgr_restore_factory_mode,sizeof(g_mre_appmgr_restore_factory_mode),&write_size) >= FS_NO_ERROR)
        {
            ret = MMI_TRUE;
        }

    }
    FS_Close(tab_hdl);
    return ret;

}
static void srv_mre_appmgr_preinstall_t_card(FS_HANDLE t_preintall_hdl,char *key_value,WCHAR *app_name_w,U32 offset,U32 start_offset,MMI_BOOL flag,MMI_BOOL save_flag)
{
    MMI_BOOL  install_ret = MMI_FALSE;
    U32 app_name_w_len = mmi_wcslen(app_name_w);
    U32 write_size = 0;
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)key_value, (char *)(app_name_w+app_name_w_len), ((SRV_MRE_APPMGR_FILEPATH_LEN-app_name_w_len)*2));
    if(flag==MMI_FALSE)
    {
        srv_mre_launch_app_result_enum result = srv_mre_launch_app_check_cert(app_name_w);

        if(result==SRV_MRE_LAUNCH_APP_SUCCESS)
        {
            install_ret = srv_mre_appmgr_install_app(app_name_w, SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL, NULL);
        }
        else
        {
            install_ret = MMI_FALSE;
        }
        if(save_flag)
        {
            FS_Write(t_preintall_hdl,key_value,offset - start_offset,&write_size);
            if(install_ret == MMI_TRUE)
            {
                FS_Write(t_preintall_hdl,"        :  Install Success\r\n",sizeof("        :  Install Success\r\n"),&write_size);
            }
            else
            {
                FS_Write(t_preintall_hdl,"        :  Install Fail\r\n",sizeof("        :  Install Fail\r\n"),&write_size);
            }
        }
    }
    else //flag == MMI_TRUE //uninstall
    {
        U16 app_package_name_w[MMI_APP_NAME_MAX_LEN];
        U8 app_package_name[MMI_APP_NAME_MAX_LEN];
        MMI_BOOL gen_result = MMI_FALSE;
        gen_result = srv_mre_appmgr_generate_identification(app_name_w,app_package_name_w);
        if(gen_result)
        {
            mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char *)app_package_name_w, (char *)app_package_name, MMI_APP_NAME_MAX_LEN);
            srv_mre_appmgr_app_uninstall(app_package_name);
        }
    }

}

MMI_BOOL mmi_mre_appmgr_parse_init(MMI_BOOL flag) 
{  
    U32 offset = 0;  
    U32 start_offset = 0;
    mmi_mre_appmgr_parse_state parse_state = StartState;
    MMI_BOOL save_flag = MMI_TRUE;
    CHAR  section_name[15]; /* [****any]*/
    CHAR key_name[15]; /* begin with number or alpher: end with any. */
    CHAR key_value[SRV_MRE_APPMGR_FILEPATH_LEN]; /*value:begin with any,end with \n */
    WCHAR *app_name_w = NULL;
    FS_HANDLE t_preintall_hdl = -1;
    WCHAR t_preinstall_file[SRV_MRE_APPMGR_PATH_SIZE];
    U32 size = 0;
    CHAR *buffer = NULL;
    kal_wsprintf(t_preinstall_file, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    mmi_wcscat(t_preinstall_file, SRV_MRE_APPMGR_PRELOAD_FOLDER);
    mmi_wcscat(t_preinstall_file, SRV_MRE_APPMGR_PRELOAD_FILE);
    t_preintall_hdl = FS_Open(t_preinstall_file, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if(t_preintall_hdl>=FS_NO_ERROR)
    {
        U32 read_size = 0;
        FS_GetFileSize(t_preintall_hdl,&size);
        buffer = (CHAR *)_vm_kernel_malloc(size+1);
        if(buffer==NULL)
            return MMI_FALSE;
        if(FS_Read(t_preintall_hdl,buffer,size,&read_size) <FS_NO_ERROR)
        {
            FS_Close(t_preintall_hdl);
            return MMI_FALSE;
        }
        if(flag==MMI_FALSE)
        {
            g_mre_appmgr_restore_factory_mode.t_card_has_install = 1;
            srv_mre_appmgr_write_restore_file();
        }
        FS_Close(t_preintall_hdl);
    }
    else
    {
        return  MMI_FALSE;
    }
    app_name_w = (WCHAR *)_vm_kernel_malloc(SRV_MRE_APPMGR_FILEPATH_LEN * sizeof(WCHAR));
    if(app_name_w==NULL)
        return MMI_FALSE;

    kal_wsprintf(app_name_w, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    mmi_wcscat(app_name_w, SRV_MRE_APPMGR_PRELOAD_FOLDER);

    memset(section_name,0,sizeof(section_name));
    memset(key_name,0,sizeof(key_name));
    memset(key_value,0,sizeof(key_value));

    kal_wsprintf(t_preinstall_file, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
    mmi_wcscat(t_preinstall_file, SRV_MRE_APPMGR_PRELOAD_FOLDER);
    mmi_wcscat(t_preinstall_file, SRV_MRE_APPMGR_PRELOAD_FILE_RESULT);
    FS_Delete(t_preinstall_file);
    if(flag==MMI_FALSE)
    {
        t_preintall_hdl = FS_Open(t_preinstall_file, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if(t_preintall_hdl<FS_NO_ERROR)
        {
            save_flag = MMI_FALSE;
        }
    }

    while (offset<size) 
    {  
        switch (parse_state) 
        {  
        case StartState:  
            if (mmi_mre_appmgr_is_sectionlabel_start(buffer[offset])) 
            {  
                parse_state = SectionLabelState;  
                break;  
            }  
            if (mmi_mre_appmgr_is_alphabet(buffer[offset])) 
            {  
                parse_state = KeyState;  /*after get the sectionlable, if the first is a-z,A-Z,0-9,this is a key*/
                start_offset = offset;  
                break;
            }  
            if(mmi_mre_appmgr_is_key_end(buffer[offset]))
            {
                parse_state = ValueState;  
                memcpy(key_name,&(buffer[start_offset]),(offset - start_offset)>15?15:(offset - start_offset));
                start_offset = offset + 1; 
                while(buffer[start_offset]==' ')
                {
                    start_offset++;
                }
                offset = start_offset-1;
                memset(key_name,0,sizeof(key_name));
                break;
            }
            if (mmi_mre_appmgr_is_comment_start(buffer[offset])) 
            {  
                parse_state = CommentState;
                break;
            }          
            break;  
        case SectionLabelState:  
            if (mmi_mre_appmgr_is_sectionlabel_end(buffer[offset])) 
            {  
                parse_state = StartState;  
            }  
            break;  
        case KeyState:  
            if (mmi_mre_appmgr_is_key_end(buffer[offset])) 
            {  
                parse_state = ValueState;  
                memcpy(key_name,&(buffer[start_offset]),(offset - start_offset)>15?15:(offset - start_offset));
                start_offset = offset + 1; 
                while(buffer[start_offset]==' ')
                {
                    start_offset++;
                }
                offset = start_offset-1;
                memset(key_name,0,sizeof(key_name));
            }
            break;  
        case ValueState: 
            {
                //MMI_BOOL  install_ret = MMI_FALSE;
                //U32 write_size = 0;
                //U32 app_name_w_len = mmi_wcslen(app_name_w);
                if (mmi_mre_appmgr_is_value_end(buffer[offset])) 
                {  
                    parse_state = StartState;  
                    if(buffer[offset-1]=='\r')
                        buffer[offset-1]='\0';
                    memcpy(key_value,&(buffer[start_offset]),offset - start_offset);
                    srv_mre_appmgr_preinstall_t_card(t_preintall_hdl,key_value,app_name_w,offset,start_offset,flag,save_flag);

                    memset(key_value,0,sizeof(key_value));
                    memset(app_name_w,0,sizeof(app_name_w));
                    kal_wsprintf(app_name_w, "%c", SRV_MRE_APPMGR_PRELOAD_DRV);
                    mmi_wcscat(app_name_w, SRV_MRE_APPMGR_PRELOAD_FOLDER);
                }
                break; 
            }
            break;  
        case CommentState:  
            if (mmi_mre_appmgr_is_comment_end(buffer[offset])) 
            {  
                parse_state = StartState;  
            }  
            break;  
        default:  
            break;  
        }  
        offset++;  
    }
    if (parse_state == ValueState) 
    {  
        //MMI_BOOL install_ret = MMI_FALSE;
        //U32 write_size = 0;
        //U32 app_name_w_len = mmi_wcslen(app_name_w);
        memcpy(key_value,&(buffer[start_offset]),offset - start_offset +1);
        if(key_value[offset - start_offset]=='\r')
        {
            key_value[offset - start_offset]='\0';
        }
        if(key_value[offset - start_offset-1]=='\r')
        {
            key_value[offset - start_offset-1]='\0';
        }
        srv_mre_appmgr_preinstall_t_card(t_preintall_hdl,key_value,app_name_w,offset,start_offset,flag,save_flag);
    }
    FS_Close(t_preintall_hdl);
    if(buffer)
    {
        _vm_kernel_free(buffer);
    }
    if(app_name_w)
    {
        _vm_kernel_free(app_name_w);
    }

}

void srv_mre_appmgr_preinstall_tcard_app_uninstall(void)
{
    g_mre_appmgr_restore_factory_mode.restore_to_factory_mode= 1;
    g_mre_appmgr_restore_factory_mode.t_card_has_install= 0;
    if(srv_mre_appmgr_write_restore_file())
    {
        mmi_mre_appmgr_parse_init(MMI_TRUE);
    }

}
#endif //__MMI_MRE_PREINSTALL_TCARD_PACKAGE__ 

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_preinstall_app
* DESCRIPTION
*  Pre install application when handset power on.
* PARAMETERS
*  void
* RETURN VALUES
*  MMI_TRUE : If install all the applications successfully.
*  MMI_FALSE : If install failed.
*****************************************************************************/
static MMI_BOOL srv_mre_appmgr_preinstall_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR mre_path[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR image_path[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];

    // MRE PUSH SERVICE-MPR  <20120320.Zhibo Tong> START
#ifdef __MRE_SAL_PN__    
    //WCHAR push_path[SRV_MRE_APPMGR_PATH_SIZE];
    FS_HANDLE    push_hdl = -1;
    //FS_HANDLE push_crt_hdl = FS_NO_ERROR;
#endif    
    // MRE PUSH SERVICE-MPR  <20120320.Zhibo Tong> END
    FS_HANDLE mre_hdl = -1, 
        img_hdl = -1, 
        info_hdl = -1;
    FS_HANDLE mre_crt_hdl = FS_NO_ERROR, 
        //img_crt_hdl = FS_NO_ERROR, 
        info_crt_hdl = FS_NO_ERROR;

    WCHAR search_filename[SRV_MRE_APPMGR_PATH_SIZE];
    //S32 search_hdl = -1, search_ret = -1;
    //FS_DOSDirEntry de;

    // WCHAR install_filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
    U32 i;

    U32 buildin_app_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create MRE install app folder 
    //  create L"z:\\@mre" */
    mmi_wcscpy(mre_path, SRV_MRE_APPMGR_MRE_FOLDER); 
    FS_XDelete(mre_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);      /* Delete all the installed file firstly */
    mre_hdl = FS_Open(mre_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (mre_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        mre_crt_hdl = FS_CreateDir(mre_path);
    }
    FS_Close(mre_hdl);
    //#if (defined(__PLUTO_MMI_PACKAGE__))&&(  !defined(__MMI_FTE_SUPPORT__))
    kal_wsprintf(image_path, "%c%w", SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FIRST_FOLDER);
    //mmi_wcscat(image_path,SRV_MRE_APPMGR_IMG_FIRST_FOLDER);
    img_hdl = FS_Open(image_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (img_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        FS_CreateDir(image_path); // create image folder
    }
    FS_Close(img_hdl);

    kal_wsprintf(image_path, "%c%w", SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FOLDER);
    //mmi_wcscat(image_path, SRV_MRE_APPMGR_IMG_FOLDER);
    img_hdl = FS_Open(image_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (img_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        FS_CreateDir(image_path); // create image folder
    }
    FS_Close(img_hdl);
    //#else
    //  mmi_wcscpy(image_path, SRV_MRE_APPMGR_IMG_FOLDER);
    //   img_hdl = FS_Open(image_path, FS_OPEN_DIR | FS_READ_ONLY);
    //   if (img_hdl < FS_NO_ERROR)  /* folder not exist */
    //   {
    //      img_crt_hdl = FS_CreateDir(image_path);
    //  }
    //  FS_Close(img_hdl);
    //#endif
    // create L"z:\\@mre\\app\\"
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
    {
        U32 index = 0;
        for(;index<sizeof(mre_app_package_name_prefix)/sizeof(srv_mre_appmgr_app_package_name_prefix);index++)
        {
            mmi_wcscpy(info_path, mre_app_package_name_prefix[index].app_folder);    
            info_hdl = FS_Open(info_path, FS_OPEN_DIR | FS_READ_ONLY);
            if (info_hdl < FS_NO_ERROR) /* folder not exist */
            {
                info_crt_hdl = FS_CreateDir(info_path); // create app folder
            }
            FS_Close(info_hdl);
        }
    }
    mmi_wcscpy(info_path, SRV_MRE_APPMGR_MAP_FOLDER);
    info_hdl = FS_Open(info_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (info_hdl < FS_NO_ERROR) /* folder not exist */
    {
        info_crt_hdl = FS_CreateDir(info_path);
    }
    FS_Close(info_hdl);

    // MRE PUSH SERVICE-MPR  <20120320.Zhibo Tong> START
#ifdef __MRE_SAL_PN__    
    // create L"z:\\@mre\\push\\"
    mmi_wcscpy(search_filename, SRV_MRE_APPMGR_PUSH_FOLDER);    
    push_hdl = FS_Open(search_filename, FS_OPEN_DIR | FS_READ_ONLY);
    if (push_hdl < FS_NO_ERROR) /* folder not exist */
    {
        FS_CreateDir(search_filename);
    }
    else
        FS_Close(push_hdl);
#endif    
    // MRE PUSH SERVICE-MPR  <20120320.Zhibo Tong> END

    if (mre_crt_hdl != FS_NO_ERROR  || info_crt_hdl != FS_NO_ERROR)
    {
        return MMI_FALSE;   /* Create folder failed */
    }
    //mmi_wcscpy(mre_path, SRV_MRE_APPMGR_MAP_FILE);        
    //mre_hdl = FS_Open(mre_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    memset(g_mre_appmgr_maptable,0,sizeof(g_mre_appmgr_maptable));
    if(!srv_mre_appmgr_write_maptable())
    {
        return MMI_FALSE;
    }
    /*if(mre_hdl >= FS_NO_ERROR)
    {
    srv_mre_appmgr_format_check format_check;
    memcpy(format_check.mre,CURRENT_MRE_VERSION,sizeof(CURRENT_MRE_VERSION));
    format_check.mreappmgr_id = SRV_MRE_APPMGR_ID_BASE;
    FS_Write(mre_hdl,&format_check,sizeof(format_check),&i);
    if(FS_Write(mre_hdl, g_mre_appmgr_maptable, sizeof(g_mre_appmgr_maptable),&i)
    <FS_NO_ERROR|| (i != sizeof(g_mre_appmgr_maptable)))
    {
    FS_Close(mre_hdl);
    return MMI_FALSE;
    }
    FS_Close(mre_hdl);
    }
    else
    {
    FS_Close(mre_hdl);
    return MMI_FALSE;
    }*/


    /* Create info file for all the shortcut app */
    /* waiting for download */
    for (i = 1; i < srv_mre_appmgr_get_sc_num()&&i<=SRV_MRE_APPMGR_INSTALLED_APP_MAX; i++)
    {
        /* Generate identification */
        mmi_app_package_char app_identification[MMI_APP_NAME_MAX_LEN << 1];
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_PREINSTALL_APP_SHORTCUT, i);
        mmi_wcscpy((WCHAR*) app_identification, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX);
        kal_wsprintf((WCHAR*) app_identification+mmi_wcslen((WCHAR*)app_identification),"%d",g_shortcut_info_list[i].app_id);

        /* Save info file */
        memset(info_path, 0, sizeof(info_path));
        mmi_wcscpy(info_path, mre_app_package_name_prefix[0].app_folder);
        mmi_wcscat(info_path, (const WCHAR*)app_identification);

        info_hdl = FS_Open(info_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (info_hdl >= FS_NO_ERROR)
        {
            srv_mre_appmgr_installed_info_struct installed_info;
            U32 info_size_written;

            memset(&installed_info, 0, sizeof(srv_mre_appmgr_installed_info_struct));
            installed_info.app_id = g_shortcut_info_list[i].app_id;
            installed_info.app_type = SRV_MRE_APPMGR_APP_TYPE_SHORTCUT;
#ifdef __LOW_COST_SUPPORT_COMMON__
            installed_info.app_unique_id = srv_mre_appmgr_get_avaible_unique_id((U16 *)app_identification,(U16)SRV_MRE_APPMGR_APP_TYPE_SHORTCUT,0,NULL,NULL,NULL,0,installed_info.app_id);
#else
            installed_info.app_unique_id = srv_mre_appmgr_get_avaible_unique_id((U16 *)app_identification,(U16)SRV_MRE_APPMGR_APP_TYPE_SHORTCUT,0,NULL,NULL,NULL,NULL,0,installed_info.app_id);
#endif
            if(installed_info.app_unique_id==0)
            {
            	  FS_Close(info_hdl);
                FS_Delete(info_path);
                return MMI_FALSE;
                
            }        
            kal_wsprintf(installed_info.app_path,"@:\\");
            kal_wstrcat(installed_info.app_path,(WCHAR*)GetString(g_shortcut_info_list[i].name_id));
            kal_wsprintf(installed_info.app_path+kal_wstrlen(installed_info.app_path),"_%d.sht",g_shortcut_info_list[i].app_id);
            if ((FS_Write(info_hdl, &installed_info, sizeof(srv_mre_appmgr_installed_info_struct), &info_size_written) <
                FS_NO_ERROR) || (info_size_written != sizeof(srv_mre_appmgr_installed_info_struct)))
            {
                FS_Close(info_hdl);
                FS_Delete(info_path);
                return MMI_FALSE;   /* Write app info failed */
            }
            FS_Close(info_hdl);
        }
        else
        {
            return MMI_FALSE;   /* Create shortcut app info failed */
        }
    }
    if(i>SRV_MRE_APPMGR_INSTALLED_APP_MAX)
    {
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_PREINSTALL_APP_MAX_SHORTCUT, i);    
    }
    /* Install all the buildin app */
    if (srv_mre_get_buildin_app_list(NULL, &buildin_app_num) > 0)
    {
        U16 *app_path_list[32] = {0};
        for (i = 0; i < buildin_app_num; i++)
        {
            app_path_list[i] = mmi_malloc(SRV_MRE_APPMGR_PATH_SIZE);
        }
        srv_mre_get_buildin_app_list(app_path_list, &buildin_app_num);

        /* Install app and free memory */
        for (i = 0; i < buildin_app_num&&i<SRV_MRE_APPMGR_INSTALLED_APP_MAX; i++)
        {
            //MMI_BOOL install_ret = MMI_TRUE;
            srv_mre_appmgr_install_app(app_path_list[i], SRV_MRE_APPMGR_APP_TYPE_ROM, NULL);
            mmi_mfree(app_path_list[i]);
        }
    }

#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
    /* Install all the app in the preload folder */
    mmi_mre_appmgr_parse_init(MMI_FALSE);
#endif
    return MMI_TRUE;
}

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
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_able_to_install
* DESCRIPTION
*  check the app,vpp can be installed or not.
* PARAMETERS
*  app_path, the vxp file path
* RETURN VALUES
*  
*****************************************************************************/

MMI_BOOL srv_mre_appmgr_is_able_to_install(U16 *app_path)
{  
    MMI_BOOL ret=MMI_TRUE;
    MMI_BOOL is_shortcut;
    S32 flag= srv_mre_appmgr_get_file_type((WCHAR*)app_path);
    U32 all_installed = 0;
    U32 temp_app_id = 0;
#ifdef __MRE_SAL_PN__
    S32 bufSize = 4;
    U32 is_support_push=0;
#endif
    srv_mre_get_app_id(app_path, &temp_app_id);
    //MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, MMI_MRE_TRC_G2_APPMGR_INSTALL_APP_ID, temp_app_id);
    is_shortcut = srv_mre_appmgr_is_shortcut_app_by_id(temp_app_id);
    if(is_shortcut)
    {
        return MMI_TRUE;
    }
    //all_installed = srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE)+srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE);
    //all_installed += srv_mre_appmgr_get_app_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    //if(all_installed>=SRV_MRE_APPMGR_INSTALLED_APP_MAX)
    //{
    //return MMI_FALSE;
    //}
    //else
    //{
    switch (flag)
    {
    case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
        if ((S32)(srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_WIDGET_PACKAGE_FLAG_TYPE)) >= SRV_MRE_APPMGR_INSTALLED_WIDGET_MAX)
        {
            ret= MMI_FALSE;//unable to install widget
        }
        break;
    case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
        if ((S32)(srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE)) >= SRV_MRE_APPMGR_INSTALLED_WALLPAPER_MAX)
        {
            ret= MMI_FALSE;//unable to install wallpaper
        }
        break;
    case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
        if ((S32)(srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_LAUNCHER_PACKAGE_FLAG_TYPE)) >= SRV_MRE_APPMGR_INSTALLED_LAUNCHER_MAX)
        {
            ret= MMI_FALSE;//unable to install launcher
        }
        break;
    case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
        if ((S32)(srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE)) >= SRV_MRE_APPMGR_INSTALLED_SCREEN_LOCK_MAX)
        {
            ret= MMI_FALSE;//unable to install scrlock
        }
        break;
    case SRV_MRE_APPMGR_APP_TYPE_VXP:
    case SRV_MRE_APPMGR_APP_TYPE_SERVICE:
        all_installed = srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE)+ srv_mre_appmgr_get_app_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
        if(all_installed>=__MRE_CONTENT_NUMBER__)
        {
            ret = MMI_FALSE;
        }
#ifdef __MRE_SAL_PN__
        if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_PUSH, &is_support_push, &bufSize) == GET_TAG_TRUE && is_support_push == 1)
        {
            if (srv_mre_appmgr_get_push_app_num() >= SRV_MRE_APPMGR_INSTALLED_PUSH_MAX)
            {
                ret= MMI_FALSE;//unable to install app
            }
        }
#endif

        break;
    default:
        ret = MMI_TRUE;
        break;
    }
    //}
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_init
* DESCRIPTION
*  Initialize MRE AppMgr service.
* PARAMETERS
*  evt : [IN] Event struct
* RETURN VALUES
*  
*****************************************************************************/
mmi_ret srv_mre_appmgr_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_appmgr_format_check format_check;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    {
        FS_HANDLE tab_hdl     = -1;
        U32 read_size = 0;
        WCHAR mre_path[SRV_MRE_APPMGR_PATH_SIZE];
        mmi_wcscpy(mre_path, SRV_MRE_APPMGR_MAP_FILE);    
        tab_hdl = FS_Open(mre_path, FS_READ_ONLY);
        if(tab_hdl >= FS_NO_ERROR)
        {
            if(FS_Read(tab_hdl,&format_check,sizeof(format_check),&read_size) >= FS_NO_ERROR)
            {
                if(0 == strcmp(format_check.mre,CURRENT_MRE_VERSION))
                {
                    if(format_check.mreappmgr_id != SRV_MRE_APPMGR_ID_BASE)
                    {
                        FS_Close(tab_hdl);
                        ret = srv_mre_appmgr_preinstall_app();
                        return ret;        
                    }
                }
                else
                {
                    FS_Close(tab_hdl);
                    ret = srv_mre_appmgr_preinstall_app();
                    return ret;
                }
            }
            if ((FS_Read(tab_hdl, g_mre_appmgr_maptable, sizeof(g_mre_appmgr_maptable), &read_size) >= FS_NO_ERROR)
                &&(read_size == sizeof(g_mre_appmgr_maptable)))
            {
                ret = MMI_TRUE;
            }
            FS_Close(tab_hdl);
        }
    }
    // if((!srv_mre_is_first_load_core())&&(MMI_FALSE == srv_mre_appmgr_preinstall_app_address_check())) // address has been changed,should be install again
    //{
    //    ret = srv_mre_appmgr_preinstall_app();
    //}  
    if (srv_mre_is_first_load_core())
    {
        //ret = srv_mre_appmgr_preinstall_app_address_check();        
        //if(MMI_FALSE == ret) // address has been changed,should be install again
        //{
        ret = srv_mre_appmgr_preinstall_app();
        vm_nvram_set_firstflag();
        //}    
        MMI_TRACE(MMI_MRE_TRC_G2_APPMGR_SRV, TRC_MRE_APPMGR_INIT, ret);
    }    
#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
    else
    {
        FS_HANDLE tab_hdl     = -1;
        U32 read_size = 0;
        WCHAR mre_path[SRV_MRE_APPMGR_PATH_SIZE];
        mmi_wcscpy(mre_path, SRV_MRE_APPMGR_RESTORE_FACTORY_FILE);    
        tab_hdl = FS_Open(mre_path, FS_READ_WRITE);
        if(tab_hdl >= FS_NO_ERROR)
        {
            if(FS_Read(tab_hdl,&g_mre_appmgr_restore_factory_mode,sizeof(g_mre_appmgr_restore_factory_mode),&read_size) >= FS_NO_ERROR)
            {
                if((g_mre_appmgr_restore_factory_mode.restore_to_factory_mode==1)||(g_mre_appmgr_restore_factory_mode.t_card_has_install==0))
                {    
                    /* Install all the app in the preload folder */
                    FS_Close(tab_hdl);
                    mmi_mre_appmgr_parse_init(MMI_FALSE);
                    if(g_mre_appmgr_restore_factory_mode.restore_to_factory_mode==1)
                    {
                        tab_hdl = FS_Open(mre_path, FS_READ_WRITE);
                        g_mre_appmgr_restore_factory_mode.restore_to_factory_mode= 0;
                        FS_Write(tab_hdl,&g_mre_appmgr_restore_factory_mode,sizeof(g_mre_appmgr_restore_factory_mode),&read_size);
                    }
                }
            }
        }
        FS_Close(tab_hdl);
    }
#endif

    return ret;
}

MMI_BOOL srv_mre_appmgr_update_install(U16 *app_path)
{
    return srv_mre_appmgr_install_app_internal(app_path,(srv_mre_appmgr_app_type_enum)0,NULL,MMI_TRUE);   //0:install; 1:update install 
}
S32 srv_mre_appmgr_get_shortcut_app_info(mmi_app_package_char *app_name,srv_mre_appmgr_shortcut_info_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!info)
    {
        return -1;
    }

    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);


    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || !srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        return MMI_FALSE;
    }

    if (installed_info.app_type & SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
    {
        for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
        {
            if (installed_info.app_id == g_shortcut_info_list[i].app_id)
            {
                memcpy(info,&g_shortcut_info_list[i],sizeof(srv_mre_appmgr_shortcut_info_struct));
                return 0;
            }
        }
    }
    return NULL;
}

CHAR* srv_mre_appmgr_get_app_url(mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //WCHAR info_path[SRV_MRE_APPMGR_PATH_SIZE];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    srv_mre_appmgr_installed_info_struct installed_info;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char *)app_name, (char *)app_name_w, MMI_APP_NAME_MAX_LEN*2);

    /* Check parameter */
    if (!srv_mre_appmgr_is_mre_app(app_name_w) || !srv_mre_appmgr_get_installed_info(app_name_w, &installed_info))
    {
        return MMI_FALSE;
    }

    if (installed_info.app_type & SRV_MRE_APPMGR_APP_TYPE_SHORTCUT)
    {
        for (i = 1; i < srv_mre_appmgr_get_sc_num(); i++)
        {
            if (installed_info.app_id == g_shortcut_info_list[i].app_id)
            {
                return g_shortcut_info_list[i].url;
            }
        }
    }
    return NULL;
}
S32 srv_mre_appmgr_get_shortcut_app_name_package(U32 app_id, mmi_app_package_char *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 1;
    WCHAR app_name_w[MMI_APP_NAME_MAX_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_name)
    {
        return -2;
    }
    while (!(g_shortcut_info_list[i].app_id == (U32)-1 &&
        g_shortcut_info_list[i].icon_id == (U16)-1 &&
        g_shortcut_info_list[i].name_id == (U16)-1))
    {
        if (g_shortcut_info_list[i].app_id == app_id)
        {
            mmi_wcscpy((WCHAR*) app_name_w, SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX);
            kal_wsprintf((WCHAR*) app_name_w+mmi_wcslen(app_name_w),"%d",g_shortcut_info_list[i].app_id);
            mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8, (char *)app_name_w, (char *)app_name, MMI_APP_NAME_MAX_LEN);
        }
        i++;
    }
    return 0;
}
#if 0
#ifdef MMI_DLA_MRE_SUPPORT
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
#ifndef MRE_APPMGR_TEST
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef MRE_APPMGR_TEST
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
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MRE_APPMGR_TEST
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
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef MRE_APPMGR_TEST
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_MRE_SUPPORT_UPDATE__  /* Currently WVGA can not support update */
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef MRE_APPMGR_TEST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __COSMOS_MMI_PACKAGE__
/* under construction !*/
/* under construction !*/
#ifdef MMI_DLA_MRE_SUPPORT
/* under construction !*/
#endif /* MMI_DLA_MRE_SUPPORT */
/* under construction !*/
#else
/* under construction !*/
#endif
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
#ifdef MRE_APPMGR_TEST
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef MRE_APPMGR_TEST
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __COSMOS_MMI_PACKAGE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#else /* MMI_DLA_MRE_SUPPORT */
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
/* under construction !*/
/* under construction !*/
#endif /* MMI_DLA_MRE_SUPPORT */
#endif
#else
MMI_BOOL srv_mre_appmgr_install_app(
                                    U16 *app_path,
                                    srv_mre_appmgr_app_type_enum app_type,
                                    mmi_app_package_char *app_name)
{
    return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_is_app_installed_by_path(U16 *app_path)
{
	 return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_app_uninstall(mmi_app_package_char *app_name)
{
	return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_generate_identification(U16 *app_path, U16 *app_name)
{
	return MMI_FALSE;
}
mmi_ret srv_mre_appmgr_get_app_list(S32 flag, mmi_app_package_name_struct *name_array, U32 num)
{
	return 0;
}
mmi_ret srv_mre_appmgr_get_app_name(mmi_app_package_char *app_name, WCHAR *string)
{
	return 0;
}
U32 srv_mre_appmgr_get_app_num(S32 flag)
{
	return 0;
}
MMI_BOOL srv_mre_appmgr_get_installed_info(
    U16 *app_name,
    srv_mre_appmgr_installed_info_struct *info)
{
		return MMI_FALSE;
}
S32 srv_mre_appmgr_get_file_type(WCHAR *path)
{
	return 0;
}
MMI_ID srv_mre_appmgr_launch_by_filepath(U16 *app_path)
{
	return 0;
}
CHAR* srv_mre_appmgr_get_app_url(mmi_app_package_char *app_name)
{
	return NULL;
}
U32 srv_mre_appmgr_get_appid(U16 *app_name)
{
	return 0;
}
MMI_BOOL srv_mre_appmgr_get_file_path(mmi_app_package_char *app_name, U16 *filepath)
{
	return MMI_FALSE;
}
S32 srv_mre_appmgr_get_shortcut_app_name_package(U32 app_id, mmi_app_package_char *app_name)
{
	return 0;
}
MMI_BOOL srv_mre_appmgr_is_app_exist(mmi_app_package_char *app_name)
{
	return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_is_app_installed(mmi_app_package_char *app_name)
{
	return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_is_bg_running(mmi_app_package_char *app_name)
{
	return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_is_shortcut_app(mmi_app_package_char *app_name)
{
	return MMI_FALSE;
}
MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id)
{
	return MMI_FALSE;
}
MMI_ID srv_mre_appmgr_launch(mmi_app_package_char *app_name, void *param, U32 param_size)
{
	return 0;
}
U32 srv_mre_appmgr_get_unique_app_id(mmi_app_package_char *app_name)
{
	return 0;
}
MMI_BOOL srv_mre_appmgr_update_install(U16 *app_path)
{
	return MMI_FALSE;
}
U32 srv_mre_appmgr_get_autostart(mmi_app_package_char *app_name)
{
	return 0;
}
#ifdef __LOW_COST_SUPPORT_COMMON__
U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1, U16 *rom_path,U16 badge,U32 app_id)
#else
U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1, U16* appname2,U16 *rom_path,U16 badge,U32 app_id)
#endif
{
	return 0;
}
mmi_ret srv_mre_appmgr_get_app_image(mmi_app_package_char *app_name, mmi_image_src_struct *image)
{
	return 0;
}
srv_mre_appmgr_app_type_enum srv_mre_appmgr_get_app_type(mmi_app_package_char *app_name)
{
	return SRV_MRE_APPMGR_APP_TYPE_UNKNOWN;
}
#endif

