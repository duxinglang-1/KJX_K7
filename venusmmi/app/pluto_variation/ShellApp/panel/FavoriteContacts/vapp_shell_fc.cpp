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
 *  Vapp_shell_fc.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell favorite contact list
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_FAV_CONTACT__    
#include "Vapp_shell_fc.h"

#include "vapp_shell_recent_calls.h"

#include "trc/vadp_app_trc.h"

#include "vrt_datatype.h"
#include "vcp_list_menu.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_date_time.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_system.h"
#include "vfx_signal.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_image_src.h"
#include "vapp_shell_panel.h"
#include "vfx_basic_type.h"
#include "vrt_system.h"
#include "vfx_primitive_frame.h"
#include "vcp_waiting_icon.h"
#include "vcp_wheel_menu.h"
#include "vcp_segment_button.h"
#include "vcp_state_image.h"
#include "vfx_timer.h"
#include "vcp_popup.h"
#include "vfx_base_popup.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_transform.h"
#include "vfx_control.h"
#include "vcp_frame_effect.h"
#include "vcp_frame_effect_type.h"
#include "vcp_button.h"
#include "vcp_tab_bar.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_auto_animate.h"
#include "vapp_msg_data_provider.h"
#include "vdat_systime.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_rp_app_venus_shell_fc_def.h"
#include "mmi_rp_app_shellapp_base_def.h"
#include "mmi_rp_app_venus_shell_recent_calls_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

#include "App_datetime.h"
#include "DateTimeType.h"
#include "PhbSrvGprot.h"
#include "PhonebookResDef.h"
#include "PhbCuiGprot.h"
#include "PhoneBookGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#ifdef __MMI_MMS_2__
#include "MMSAppInterfaceGprot.h"
#endif

#include "SmsAppGprot.h"
#include "UcmGprot.h"

#include "MsgViewerCuiGprot.h"    

#include "UcmGprot.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#include "MessagesMiscell.h"    /* for IsMessagesReEntering */

#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "customer_email_num.h"
#include "kal_trace.h"
#include "mmi_cb_mgr_gprot.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "kal_release.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "l4c2phb_enums.h"
#include "mmi_rp_app_phonebook_def.h"
#include "UmSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "UmSrvDefs.h"
#include "string.h"
#include "UcmSrvGprot.h"
#include "UcSrvGprot.h"
#include "Unicodexdcl.h"

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */

#include "ModeSwitchSrvGprot.h"
#include "simctrlsrvgprot.h"

#ifdef __cplusplus
}
#endif

static const vrt_matrix3x3_struct g_transformArray[7] =
{
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__

#if defined(__MMI_MAINLCD_320X480__)

    {0.40246f, -0.35245f, 140.0f,
     0.08867f, 0.40489f, -120.0f,
     -0.00008f, -0.00123f, 1.0f
    },

    {0.78697f, -0.14457f, 97.25f,
    -0.19742f, 0.64456f, -120.75f,
     0.00087f, -0.00194f, 1.0f
    },

    {0.64633f, -0.38102f, 61.0f,
     0.15242f, 0.58189f, -85.75f,
     -0.00044f, -0.00129f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.61301f, -0.34185f, 28.75f,
     0.03277f, 0.32862f, 101.0f,
     -0.00061f, -0.00135f, 1.0f
    },

    {0.61514f, 0.08878f,-23.75f,
     -0.04122f,0.00849f, 206.0f,
     0.00042f,-0.00197f,1.0f
    },
    
    {0.45893f,-0.10566f,-25.0f,
    0.09169f,0.07210f,227.0f,
    0.00004f,-0.00100f, 1.0f
    }

#elif defined(__MMI_MAINLCD_240X400__)

    {0.47043f, -0.36178f, 137.0f,
     0.06987f, 0.43272f, -132.0f,
     -0.000110f, -0.00154f, 1.0f
    },

    {0.72834f, -0.17216f, 90.75f,
    -0.17098f, 0.58933f, -88.5f,
     0.00096f, -0.00232f, 1.0f
    },

    {0.58163f, -0.36558f, 62.75f,
     0.13293f, 0.54836f, -66.0f,
     -0.00054f, -0.00141f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.55405f, -0.33864f, 34.5f,
     0.02819f, 0.30858f, 84.25f,
     -0.00069f, -0.00152f, 1.0f
    },

    {0.57217f, 0.03116f,0.75f,
     -0.04194f,0.01219f, 165.0f,
     0.00045f,-0.00227f,1.0f
    },
    
    {0.49825f,-0.18155f,7.0f,
    0.17504f,0.03352f,226.0f,
    0.00021f,-0.00115f, 1.0f
    }
#elif defined(__MMI_MAINLCD_240X320__)

    {0.46930f, 0.0f, 61.0f,
     0.0f, 0.63208f, -106.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.64912f, 0.0f, 43.0f,
     0.0f, 0.71698f, -74.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.82895f, 0.0f, 19.0f,
     0.0f, 0.80189f, -34.0f,
     0.0f, 0.0f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.82895f, 0.0f, 19.0f,
     0.0f, 0.80189f, 52.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.64912f, 0.0f,43.0f,
     0.0f,0.71698f, 100.0f,
     0.0f,0.0f,1.0f
    },
    
    {0.46930f,0.0f,61.0f,
    0.0f,0.63208f,143.0f,
    0.0f,0.0f, 1.0f
    }

#endif

#else

#if defined(__MMI_MAINLCD_320X480__)

    {0.39528f, -0.40865f, 203.0f,
     0.06676f, 0.41097f, -175.0f,
     -0.00020f, -0.00119f, 1.0f
    },

    {0.73286f, -0.15902f, 129.0f,
    -0.15709f, 0.55976f, -102.5f,
     0.00062f, -0.00154f, 1.0f
    },

    {0.60954f, -0.35955f, 81.75f,
     0.13271f, 0.54331f, -78.0f,
     -0.00037f, -0.00100f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.59046f, -0.32061f, 29.0f,
     0.03648f, 0.32490f, 114.0f,
     -0.00048f, -0.00109f, 1.0f
    },

    {0.56519f, 0.06111f,-15.25f,
     -0.08170f,0.05860f, 219.0f,
     0.00019f,-0.00152f,1.0f
    },
    
    {0.50363f,-0.14951f,-7.0f,
    0.11526f,0.08666f,287.0f,
    0.00003f,-0.00071f, 1.0f
    }

#elif defined(__MMI_MAINLCD_240X400__)

    {0.47043f, -0.36178f, 137.0f,
     0.06987f, 0.43272f, -132.0f,
     -0.000110f, -0.00154f, 1.0f
    },

    {0.72834f, -0.17216f, 90.75f,
    -0.17098f, 0.58933f, -88.5f,
     0.00096f, -0.00232f, 1.0f
    },

    {0.58163f, -0.36558f, 62.75f,
     0.13293f, 0.54836f, -66.0f,
     -0.00054f, -0.00141f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.55405f, -0.33864f, 34.5f,
     0.02819f, 0.30858f, 84.25f,
     -0.00069f, -0.00152f, 1.0f
    },

    {0.57217f, 0.03116f,0.75f,
     -0.04194f,0.01219f, 165.0f,
     0.00045f,-0.00227f,1.0f
    },
    
    {0.49825f,-0.18155f,7.0f,
    0.17504f,0.03352f,226.0f,
    0.00021f,-0.00115f, 1.0f
    }

#elif defined(__MMI_MAINLCD_240X320__)

    {0.46930f, 0.0f, 61.0f,
     0.0f, 0.63208f, -106.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.64912f, 0.0f, 43.0f,
     0.0f, 0.71698f, -74.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.82895f, 0.0f, 19.0f,
     0.0f, 0.80189f, -34.0f,
     0.0f, 0.0f, 1.0f
    },
    
    {1.0f, 0, 0,
    0, 1.0f, 0, 
    0, 0, 1.0f},
    

    {0.82895f, 0.0f, 19.0f,
     0.0f, 0.80189f, 52.0f,
     0.0f, 0.0f, 1.0f
    },

    {0.64912f, 0.0f,43.0f,
     0.0f,0.71698f, 100.0f,
     0.0f,0.0f,1.0f
    },
    
    {0.46930f,0.0f,61.0f,
    0.0f,0.63208f,143.0f,
    0.0f,0.0f, 1.0f
    }

#endif
#endif
};


static VcpListMenuThemeStruct g_fc_list_menu_theme = {
    VRT_COLOR_MAKE(166, 0, 0, 0),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_GREY,
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_GREY,
    VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND,
    0,
    0,
    0,
    0,
    0,
    0
};

// list history data
VappShellFCDetailScr::ListHistory VappShellFCDetailScr::m_history;


static void timestamp2String(VfxWString &strTime, VfxU32 timestamp, VfxU32 flags)
{
    VfxU32 local_sec = 0;
    applib_time_struct time;
    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);

    VfxDateTime tempTime;
    tempTime.setDateTime(&time);

	VfxDateTime currTime;
	currTime.setCurrentTime();

    if (flags == (VfxU32)(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY))
    {
        if (tempTime.getYear() == currTime.getYear()&&
            tempTime.getMonth() == currTime.getMonth() &&
            tempTime.getDay() == currTime.getDay())
        {
            strTime.loadFromRes(VAPP_SHELL_STR_RC_TODAY);
        }
        else if (tempTime.getYear() == currTime.getYear())
        {
            VfxWChar buf[20];
            tempTime.getDateTimeString(
                VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY,
                buf,
                sizeof(buf));
            strTime.loadFromMem(buf);
        }
        else
        {
            strTime.format("%d", tempTime.getYear());
        }
    }
    else if (flags == (VfxU32)(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE))
    {
        if (tempTime.getYear() != currTime.getYear())
		{
            strTime.setNull();
		}
        else
        {
            VfxWChar buf[20];
            tempTime.getDateTimeString(
                VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE,
                buf,
                sizeof(buf));
            strTime.loadFromMem(buf);
        }
    }
}


static void durationToString(U32 duration, VfxWString &strDuration)
{
    U32 val;
    applib_time_struct time = {0};
        
    /* app_time->nDay = duration / (XLG_HOUR_PER_DAY * XLG_MIN_PER_HOUR * XLG_SEC_PER_MIN); */
    val = duration % (24 * 60 * 60);
    time.nHour = (val / (60 * 60)) % 255;
    val = val % (60 * 60);
    time.nMin = val / 60;
    time.nSec = val % 60;

    if (time.nHour > 0)
    {
        strDuration.format("%02d:%02d:%02d", time.nHour, time.nMin, time.nSec);
    }
    else
    {
        strDuration.format("%02d:%02d", time.nMin, time.nSec);
    }
}


/***************************************************************************** 
 * ContactCache
 *****************************************************************************/
VfxU16   ContactCache::m_storeIndex = 0xffff;
VfxWChar ContactCache::name[MMI_PHB_NAME_LENGTH + 1];
VfxWChar ContactCache::number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
VfxWChar ContactCache::homeNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
VfxWChar ContactCache::officeNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
VfxWChar ContactCache::faxNumber[MMI_PHB_NUMBER_LENGTH + 1 + 1];
VfxWChar ContactCache::email1[MMI_PHB_EMAIL_LENGTH + 1];
VfxWChar ContactCache::email2[MMI_PHB_EMAIL_LENGTH + 1];
VfxWChar ContactCache::title[MMI_PHB_TITLE_LENGTH + 1];


void ContactCache::init()
{
    m_storeIndex = 0xffff;
    name[0] = 0;
    number[0] = 0;
    homeNumber[0] = 0;
    officeNumber[0] = 0;
    faxNumber[0] = 0;
    email1[0] = 0;
    email2[0] = 0;
    title[0] = 0;
}


void ContactCache::init(VfxU16 storeIndex)
{
    if (m_storeIndex == storeIndex)
    {
        init();
    }
}


VfxWChar* ContactCache::getInfo(VfxU16 storeIndex, mmi_phb_num_type_enum infoType, VfxU32 infoId)
{
    VfxBool isCached = VFX_TRUE;

    // if current contact is invalid, then initlize the cache
    if (storeIndex != m_storeIndex)
    {
        init();
        m_storeIndex = storeIndex;

        isCached = VFX_FALSE;
    }

    switch (infoId)
    {
        case SRV_PHB_ENTRY_FIELD_NAME:
        {
            if (!isCached || name[0] == 0)
            {
                srv_phb_get_name(m_storeIndex, name, MMI_PHB_NAME_LENGTH);
            }

            return name;
        }
        case SRV_PHB_ENTRY_FIELD_NUMBER:
        {
            if (!isCached || number[0] == 0)
            {
                srv_phb_get_number(m_storeIndex, number, MMI_PHB_NUMBER_LENGTH + 1);
            }

            return number;
        }            
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
        {
            if (!isCached || homeNumber[0] == 0)
            {
                srv_phb_get_optional_number(m_storeIndex, infoId, homeNumber, NULL, MMI_PHB_NUMBER_LENGTH + 1);
            }

            return homeNumber;
        }            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
        {
            if (!isCached || officeNumber[0] == 0)
            {
                srv_phb_get_optional_number(m_storeIndex, infoId, officeNumber, NULL, MMI_PHB_NUMBER_LENGTH + 1);
            }

            return officeNumber;
        }            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
        {
            if (!isCached || faxNumber[0] == 0)
            {
                srv_phb_get_optional_number(m_storeIndex, infoId, faxNumber, NULL, MMI_PHB_NUMBER_LENGTH + 1);
            }

            return faxNumber;
        }            
        case SRV_PHB_ENTRY_FIELD_EMAIL1:
        {
            if (!isCached || email1[0] == 0)
            {
                srv_phb_get_email_address(m_storeIndex, email1, MMI_PHB_EMAIL_LENGTH);
            }

            return email1;
        }            
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__    
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
        {
            if (!isCached || email2[0] == 0)
            {
                srv_phb_get_email_address2(m_storeIndex, email2, MMI_PHB_EMAIL_LENGTH);
            }

            return email2;
        }
    #endif
    #endif
    #if defined(__MMI_PHB_INFO_FIELD__)        
        case SRV_PHB_ENTRY_FIELD_TITLE:
        {
            if (!isCached || title[0] == 0)
            {
                srv_phb_contact_info_struct contact_info;
                contact_info.field_mask = SRV_PHB_ENTRY_FIELD_TITLE;
                contact_info.field_data.title = title;

                srv_phb_oplib_get_contact_info(m_storeIndex, &contact_info);
            }
            return title;
        }
    #endif
          
        default:
            break;
    }

    // return empty string for refrence
    return NULL;
}

    
/***************************************************************************** 
 * VappShellFCList
 *****************************************************************************/
// favorite contact will always be alive
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappShellFCList);


VappShellFCList::VappShellFCList()
{
    m_isReady = VFX_FALSE;
}


VfxBool VappShellFCList::isReady() const
{
    return m_isReady;
}


void VappShellFCList::setReady(VfxBool ready)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_SET_READY, ready);
    
    m_isReady = ready;
}


void VappShellFCList::onInit()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_ONINIT);
    
    VfxObject::onInit();
    
	build();
    ContactCache::init();

    regLisener();
}


void VappShellFCList::onDeinit()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_ONDEINIT);
    
    deregLisener();

    VfxObject::onDeinit();
}


void VappShellFCList::regLisener()
{
    mmi_frm_cb_reg_event(EVT_ID_PHB_ADD_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_UPD_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_DEL_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_reg_event(EVT_ID_PHB_READY, VappShellFCList::lisener, NULL);
}


void VappShellFCList::deregLisener()
{
    mmi_frm_cb_dereg_event(EVT_ID_PHB_ADD_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_UPD_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_DEL_CONTACT, VappShellFCList::lisener, NULL);
    mmi_frm_cb_dereg_event(EVT_ID_PHB_READY, VappShellFCList::lisener, NULL);
}


void VappShellFCList::build()
{
    vapp_shell_fc_id_struct fc;

    VfxS16 pError;
    ReadRecord(
        NVRAM_EF_SHELL_FC_LID,
        1,
        &fc,
        sizeof(vapp_shell_fc_id_struct),
        &pError);

    if (fc.focus_id >= 8)
    {
        m_focusID = 0;
    }
    else
    {
	    m_focusID = fc.focus_id;
    }

    if (srv_phb_startup_is_phb_ready())
    {
        VfxU8 id;
    	for (id = 0; id < SHELL_FC_COUNT; id++)
    	{
    		m_FC[id].set(fc.store_index[id], id);
    	}
        // set ready flag
        setReady(VFX_TRUE);
    }
    else
    {
      	VfxU8 id;
        for (id = 0; id < SHELL_FC_COUNT; id++)
    	{
    		m_FC[id].set(0xffff, id);
    	}

        // set ready flag
        setReady(VFX_FALSE);
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_BUILD, m_focusID);
    
    // build cache
    buildCache();
}


void VappShellFCList::buildCache()
{
    // build image cache

    // build other part
}


void VappShellFCList::initCache()
{
    ContactCache::init();
}



VfxU16 VappShellFCList::getCount()
{
    return SHELL_FC_COUNT;
}


VappShellFC* VappShellFCList::getFC(VfxU8 id)
{
	VFX_ASSERT(id < SHELL_FC_COUNT);
	
	return &m_FC[id];
}


VfxS32 VappShellFCList::exist(VfxU16 storeIndex)
{
    VfxU8 id;
    for (id = 0; id < SHELL_FC_COUNT; id++)
    {
        if (m_FC[id].getStoreIndex() == storeIndex)
        {
            return id;
        }
    }

    return -1;
}


void VappShellFCList::lisenerCb(S32 result, U16 store_index, void* user_data)
{
}


mmi_ret VappShellFCList::lisener(mmi_event_struct* param)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_LISENER, param->evt_id);
    
    // get contact manager instance
    VappShellFCList* FCList = VappShellFCList::getInstance();

    switch (param->evt_id)
    {
        case EVT_ID_PHB_ADD_CONTACT:
            // nothing to do, now
            break;
        case EVT_ID_PHB_UPD_CONTACT:
        {
            srv_phb_op_evt_struct* data = (srv_phb_op_evt_struct*)param;

            VfxS32 id = FCList->exist(data->store_index);
            if (id >= 0)
            {
                VappShellFC* fc = FCList->getFC((VfxU8)id);
                fc->initCache();
                fc->set(data->store_index);

                FCList->m_signalFCContent.emit(FCList, param);            
            }

            break;
        }
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct* data = (srv_phb_op_evt_struct*)param;

            VfxS32 id = FCList->exist(data->store_index);
            if (id >= 0)
            {
                VappShellFC* fc = FCList->getFC((VfxU8)id);
                fc->initCache();
                fc->set(0xffff);

                FCList->m_signalFCContent.emit(FCList, param);
            }

            break;
        }
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) param;

            if (ready->phb_ready)
            {
                // since the focusID maybe changed by user, so should keep it.
                VfxU8 preFocusID = FCList->getFocusID();
                
                FCList->initCache();
                FCList->build();
                FCList->setFocusID(preFocusID);
            }

            FCList->m_signalFCContent.emit(FCList, param);
            break;
        }
        case EVT_ID_PHB_SELECT_CONTACT:
        {
            cui_phb_select_contact_result_struct *result = (cui_phb_select_contact_result_struct *) param;
            if (FCList->exist(result->store_index) >= 0)
            {
                mmi_popup_display_simple(
                    (UI_string_type) GetString(VAPP_SHELL_FC_STR_CONTACT_SELECTED),
                    MMI_EVENT_FAILURE,
                    result->sender_id,
                    NULL);
            }
            else
            {
                VappShellFC* fc = (VappShellFC*) param->user_data;
                fc->set(result->store_index);

                // save latest changes to NVRAM
                FCList->save();
                
        		// post the favorite contact info changed event out
    			FCList->m_signalFCContent.emit(FCList, param);
                mmi_frm_group_close(result->sender_id);
            }
            break;
        }
            
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
        {
            cui_phb_select_contact_result_struct *result = (cui_phb_select_contact_result_struct *) param;
            mmi_frm_group_close(result->sender_id);
            break;
        }

    #if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)
        case EVT_ID_PHB_SELECT_IMAGE:
        {
            cui_phb_select_image_struct *data = (cui_phb_select_image_struct*) param;

            if (data->result)
            {
                srv_phb_contact_info_struct contact_info;
                contact_info.field_mask = SRV_PHB_ENTRY_FIELD_PIC;
                contact_info.field_data.image_id = 0x8000;
                contact_info.field_data.image_path = data->path;
                contact_info.field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_FILE;
                
                VappShellFC *fc = (VappShellFC*) param->user_data;
                
                srv_phb_oplib_update_contact(
                    fc->getStoreIndex(),
                    &contact_info,
                    VappShellFCList::lisenerCb,
                    NULL);

            }

            // post the favorite contact info changed event out
	    FCList->m_signalFCContent.emit(FCList, param);

            cui_phb_select_image_close(data->sender_id);
            break;
        }
    #endif

        default:
            break;
    }
    return MMI_RET_OK;
}


void VappShellFCList::save()
{
	vapp_shell_fc_id_struct fc;
	fc.focus_id = m_focusID;

	VfxU8 id;
	for (id = 0; id < SHELL_FC_COUNT; id++)
	{
		fc.store_index[id] = m_FC[id].getStoreIndex();
	}

    VfxS16 pError;
	WriteRecord(
        NVRAM_EF_SHELL_FC_LID,
        1,
        &fc,
        sizeof(vapp_shell_fc_id_struct),
        &pError);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_LIST_SAVE, m_focusID);
}


void VappShellFCList::add(VappShellFC * fc)
{
    if (mmi_phb_check_ready(MMI_TRUE))
	{
        MMI_ID sg_id, cui_id;
        sg_id = mmi_frm_group_create(
                    GRP_ID_ROOT,
                    GRP_ID_AUTO_GEN,
                    VappShellFCList::lisener,
                    fc);

        mmi_frm_group_enter(sg_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        
        cui_id = cui_phb_list_select_contact_create(sg_id);

        cui_phb_list_select_contact_set_storage(cui_id, PHB_STORAGE_NVRAM);
        cui_phb_list_select_contact_run(cui_id);
	}
}


void VappShellFCList::remove(VappShellFC * fc)
{
    fc->set(0xFFFF);
    save();
}


void VappShellFCList::remove()
{
    m_FC[m_focusID].set(0xFFFF);
    save();
}


VappShellFC* VappShellFCList::getFocusFC()
{
    return &m_FC[m_focusID];
}


VfxU8 VappShellFCList::getFocusID()
{
    return m_focusID;
}


void VappShellFCList::setFocusID(VfxU8 focusID)
{
    m_focusID = focusID;
}


/***************************************************************************** 
 * Class VappShellFC
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellFC", VappShellFC, VfxObject);

void VappShellFC::initCache()
{
    ContactCache::init(m_storeIndex);
}


void VappShellFC::set(VfxU16 storeIndex, VfxU8 id)
{
    m_storeIndex = storeIndex;
    m_ID = id;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_SET, storeIndex, id);
    
    setImg();

    // initalize number cache
    m_number.m_numCnt = 0;
    for (VfxU8 i = 0; i < SHELL_FC_NUM_COUNT; i++)
    {
        m_number.m_numId[i] = 0;
        m_number.m_numType[i] = MMI_PHB_NUM_TYPE_TOTAL;
    }

    // build number type cache
    if (isFCValid())
    {
        VfxU32 filedFlag = getFieldFlag();
    	U16 temp[2];
		srv_phb_get_number(m_storeIndex, temp, 1);
        if (temp[0])
        {
            m_number.m_numType[m_number.m_numCnt] = MMI_PHB_NUM_TYPE_MOBILE;
            m_number.m_numId[m_number.m_numCnt++] = SRV_PHB_ENTRY_FIELD_NUMBER;
        }
        
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
	    mmi_phb_num_type_enum type;
        for (VfxU8 index = 0; index < MMI_PHB_OPT_NUM_COUNT; index++)
        {
        	srv_phb_get_number_ex(m_storeIndex, (U8)(index + 1), temp, (U8*)&type, 1);
            if (temp[0])
            {
                m_number.m_numId[m_number.m_numCnt] =  (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << index);
                m_number.m_numType[m_number.m_numCnt++] = type;
            }
        }
    #endif
    }
}


void VappShellFC::set(VfxU16 storeIndex)
{
    set(storeIndex, m_ID);
}


VfxU16 VappShellFC::getStoreIndex()
{
    return m_storeIndex;
}


VfxBool VappShellFC::isFCValid()
{
    if (srv_phb_check_entry_exist(m_storeIndex))
    {
        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxU8 VappShellFC::getId()
{
    return m_ID;
}


void VappShellFC::removeImg()
{
    srv_phb_contact_info_struct contact_info;

    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_PIC;
    contact_info.field_data.image_id = 0;
    contact_info.field_data.image_path = NULL;
    contact_info.field_data.res_type = 0;
    
    srv_phb_oplib_update_contact(
        m_storeIndex,
        &contact_info,
        VappShellFCList::lisenerCb,
        NULL);
}


void VappShellFC::addImg()
{
    MMI_ID sg_id, parent_id;

    parent_id = mmi_frm_group_create(
                    GRP_ID_ROOT,
                    GRP_ID_AUTO_GEN,
                    VappShellFCList::lisener,
                    this);
    
    mmi_frm_group_enter(parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    sg_id = cui_phb_select_image_create(parent_id, CUI_PHB_SELECT_IMG_FROM_FILE);
    cui_phb_select_image_run(sg_id);
}


void VappShellFC::takeImg()
{
    MMI_ID sg_id, parent_id;

    parent_id = mmi_frm_group_create(
                    GRP_ID_ROOT,
                    GRP_ID_AUTO_GEN,
                    VappShellFCList::lisener,
                    this);

    mmi_frm_group_enter(parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    sg_id = cui_phb_select_image_create(parent_id, CUI_PHB_SELECT_IMG_CAMERA);
    cui_phb_select_image_run(sg_id);
}

// getFieldFlag
VfxU32 VappShellFC::getFieldFlag()
{
    VfxU32 field;
    srv_phb_get_field(m_storeIndex, &field);

    return field;
}

// get mobile number counts
VfxU8 VappShellFC::getMobileNumberCount()
{
    VfxU8 count = 0;

    for (VfxU8 index = 0; index < SHELL_FC_NUM_COUNT; index++)
    {
        if (m_number.m_numType[index] == MMI_PHB_NUM_TYPE_MOBILE)
        {
            count++;
        }
    }

    return count;
}


// get number counts
VfxU8 VappShellFC::getNumberCount()
{
    return srv_phb_get_num_count(m_storeIndex);
}

// get email counts
VfxU8 VappShellFC::getEmailCount()
{
    return srv_phb_get_num_count(m_storeIndex);
}
    

VfxBool VappShellFC::hasNumber()
{
    if (getNumberCount())
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU8 VappShellFC::getNumber()
{
    // reset temp index
    m_getNumberIndex = 0;
	
	return srv_phb_get_num_count(m_storeIndex);
}

// get number
VfxWString& VappShellFC::getNextNumber(mmi_phb_num_type_enum *numType, VfxU32 *numId)
{
    if (m_getNumberIndex < m_number.m_numCnt)
    {
        *numType = m_number.m_numType[m_getNumberIndex];
        *numId = m_number.m_numId[m_getNumberIndex];
         m_getNumberIndex++;
    }
    else
    {
        *numId = 0;
        *numType = MMI_PHB_NUM_TYPE_TOTAL;
    }
    
    return m_buf.loadFromMem(ContactCache::getInfo(m_storeIndex, *numType, *numId));
}


VfxBool VappShellFC::hasImg()
{
    if (m_img.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        if (m_img.getResId() == VAPP_SHELL_FC_IMG_DEFAULT)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}


void VappShellFC::setImg()
{
    VfxU16 id = 0;
    VfxU16 res_type = 0;
    VfxU16 *path;
    VFX_SYS_ALLOC_MEM(path, sizeof(VfxU16) * 261);

    // get contact's picture
    srv_phb_get_image(m_storeIndex, &id, path, &res_type);
    if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        m_img.setPath(VfxWString().loadFromMem(path));
    }
    else
    {
        //id = id & 0x7fff;
        if (id == IMG_PHB_DEFAULT || id == 0)
        {
            m_img.setResId(VAPP_SHELL_FC_IMG_DEFAULT);
        }
        else
        {
            m_img.setResId(id);
        }  
    }
    VFX_SYS_FREE_MEM(path);
}


void VappShellFC::setImg(VfxWString& path)
{
    m_img.setPath(path);
}


const VfxImageSrc& VappShellFC::getImg() const
{
    return m_img;
}


VfxWString& VappShellFC::getInfo(mmi_phb_num_type_enum infoType, VfxU32 infoId)
{
    return m_buf.loadFromMem(ContactCache::getInfo(m_storeIndex, infoType, infoId));
}


VfxS32 VappShellFC::getEmail()
{
    m_getEmailIndex = 0;
	return srv_phb_get_email_count(m_storeIndex);
}


VfxWString& VappShellFC::getNextEmail(mmi_phb_num_type_enum *numType, VfxU32 *numId)
{
    // get contact field flag
    VfxWChar temp[2] = {0};
    VfxU32 tempID = 0;

    switch (m_getEmailIndex)
    {
        case 0:
        {
			srv_phb_get_email_address(m_storeIndex, temp, 1);
            if (temp[0])
            {
                tempID = SRV_PHB_ENTRY_FIELD_EMAIL1;
            }
		#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
            else
            {
            	srv_phb_get_email_address2(m_storeIndex, temp, 1);
				if (temp[0])
				{
					tempID = SRV_PHB_ENTRY_FIELD_EMAIL2;
				}
            }
		#endif
            break;
        }
        case SRV_PHB_ENTRY_FIELD_EMAIL1:
        {
		#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
			srv_phb_get_email_address2(m_storeIndex, temp, 1);
			if (temp[0])
			{
				tempID = SRV_PHB_ENTRY_FIELD_EMAIL2;
			}
		#endif
            break;
        }
        case SRV_PHB_ENTRY_FIELD_EMAIL2:
            break;
        default:
            break;
    }

    if (tempID == 0)
    {
        *numType = MMI_PHB_NUM_TYPE_TOTAL;
        *numId = 0;
    }
    else
    {
        *numType = MMI_PHB_NUM_TYPE_TOTAL;
        *numId = tempID;
        m_getEmailIndex = tempID;
    }

    return m_buf.loadFromMem(ContactCache::getInfo(m_storeIndex, *numType, *numId));
}


/***************************************************************************** 
 * VappShellFCFrame
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellFCFrame", VappShellFCFrame, VappShellPanel);

VappShellFCFrame::VappShellFCFrame():
    m_activeScr(VAPP_SHELL_FC_SCR_MENU),
    m_FCList(NULL),
    m_FC3DScr(NULL),
    m_FCDetailScr(NULL),
    m_bg(NULL),
    m_info(NULL)
{
}
        
void VappShellFCFrame::onInit()
{
    VappShellPanel::onInit();
    
    // build contact manager, single instance
    m_FCList = VFX_OBJ_GET_INSTANCE(VappShellFCList);

    // connect update event
    m_FCList->m_signalFCContent.connect(this, &VappShellFCFrame::onUpdateContent);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_INIT);
}


void VappShellFCFrame::onDeinit()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_DEINIT);
    
    // save the fc id list to NVRAM
    m_FCList->save();

    // close single instance
    m_FCList->closeInstance();
    
    VappShellPanel::onDeinit();
}


void VappShellFCFrame::onInitView()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_INIT_VIEW, getState());
    
    // Init parent
    VappShellPanel::onInitView();
    
    // Get frame bounds
    VfxRect bounds = VappShellPanel::getAppBounds();

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    setBounds(0, 0, main_screen_size.width, main_screen_size.height);
    setIsOpaque(VFX_TRUE);

    // back group image
    VFX_OBJ_CREATE(m_bg, VfxImageFrame, this);
    m_bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    m_bg->setBgColor(VFX_COLOR_BLACK);
    m_bg->setIsOpaque(VFX_TRUE);

    // create 3D screen child frame
    VFX_OBJ_CREATE_EX(m_FC3DScr, VappShellFC3DScr, this, (m_FCList));

    m_FC3DScr->setPos(bounds.origin);
    m_FC3DScr->setBounds(0, 0, bounds.getWidth(), bounds.getHeight());
    m_FC3DScr->onInitView();
    
    // create detail info screen child frame
    VFX_OBJ_CREATE(m_FCDetailScr, VappShellFCDetailScr, this);

    m_FCDetailScr->setPos(bounds.origin);
    m_FCDetailScr->setBounds(0, 0, main_screen_size.width, main_screen_size.height - bounds.origin.y);
    
    // check screen active info
    stateConfig();
    
    m_FCDetailScr->onInitView();
}


void VappShellFCFrame::onDeinitView()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_DEINIT_VIEW, getState());
    
    // call child frames' onDeinitView to release resource
    m_FC3DScr->onDeinitView();
    m_FCDetailScr->onDeinitView();

    // close child frames
    VFX_OBJ_CLOSE(m_FC3DScr);
    VFX_OBJ_CLOSE(m_FCDetailScr);
    VFX_OBJ_CLOSE(m_bg);
    VFX_OBJ_CLOSE(m_info);

    VappShellPanel::onDeinitView();
}


void VappShellFCFrame::onEnterView()
{
    VappShellPanel::onEnterView();

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_ENTER_VIEW, getState(), m_FCList->isReady());
    
    if (!m_FCList->isReady())
    {
        if (m_info == NULL)
        {
            VFX_OBJ_CREATE(m_info, VcpWaitingIcon, this);
        }

        // using panel bounds to set waiting icon
        VfxRect rect = VappShellPanel::getAppBounds();

        m_info->setAnchor(0.5f, 0.5f);
        m_info->setPos(rect.getWidth()/2, rect.getHeight()/2);
        m_info->setHiddenWhenStopped(VFX_TRUE);

        m_info->start();
        return;
    }

    stateConfig();
    
    if (getState() == VAPP_SHELL_FC_SCR_DETAIL)
    {
        // hide short cut bar
        hideShortcutBar(VFX_TRUE);
/*
        // resize frame
        VfxRect bounds = VappShellPanel::getAppBounds();

        setPos(bounds.origin);
    	setBounds(VfxRect(VFX_POINT_ZERO, bounds.size));

        // resize detail frame
        m_FCDetailScr->setPos(VFX_POINT_ZERO);
        m_FCDetailScr->setBounds(VfxRect(VFX_POINT_ZERO, bounds.size));
*/
        m_FCDetailScr->onEnterView();
    }
    else
    {
        m_FC3DScr->onEnterView();
    }

    // connect signal
    m_FC3DScr->m_signalTap.connect(this, &VappShellFCFrame::onTapMenuCell);
    m_FCDetailScr->m_signalBack.connect(this, &VappShellFCFrame::onBackDetailScr);
}


void VappShellFCFrame::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_FRAME_EXIT_VIEW, getState(), cause);

    // close the waiting icon
    if (m_info)
    {
        VFX_OBJ_CLOSE(m_info);
    }

    // unhide short cut bar
    hideShortcutBar(VFX_FALSE);

    VfxBool keepData = VFX_FALSE;
    if (cause == APP_SHELL_SCREEN_EXIT)
    {
        keepData = VFX_TRUE;
    }
    
    // call child frame exit view function
    if (getState() == VAPP_SHELL_FC_SCR_MENU)
    {
        m_FC3DScr->onExitView(keepData);
        // always call detail screen exit hdlr to make sure dereg cb hdlr    
        m_FCDetailScr->onExitView(VFX_FALSE);
    }
    else if (getState() == VAPP_SHELL_FC_SCR_DETAIL)
    {
        m_FCDetailScr->onExitView(keepData);
    }

    // reset shell screen history info
    if (cause != APP_SHELL_SCREEN_EXIT)
    {
        setState(VAPP_SHELL_FC_SCR_MENU);
    }

    // disconnect signal
    m_FC3DScr->m_signalTap.disconnect(this, &VappShellFCFrame::onTapMenuCell);
    m_FCDetailScr->m_signalBack.disconnect(this, &VappShellFCFrame::onBackDetailScr);
    
    VappShellPanel::onExitView(cause);
}


void VappShellFCFrame::onEnterDetailView()
{
    // hide short cut bar
    hideShortcutBar(VFX_TRUE);

    // set screen state
    setState(VAPP_SHELL_FC_SCR_DETAIL);

/*    
    // resize frame
    VfxRect bounds = VappShellPanel::getAppBounds();

    setPos(bounds.origin);
	setBounds(VfxRect(VFX_POINT_ZERO, bounds.size));

    // resize detail frame
    m_FCDetailScr->setPos(VFX_POINT_ZERO);
    m_FCDetailScr->setBounds(VfxRect(VFX_POINT_ZERO, bounds.size));
*/

    m_FCDetailScr->setFC(m_FCList->getFocusFC());

    m_FC3DScr->onExitViewEffect();
    m_FCDetailScr->onEnterViewEffect();
}


void VappShellFCFrame::onExitDetailView()
{
    // unhide short cut bar
    hideShortcutBar(VFX_FALSE);

    // reset state
    setState(VAPP_SHELL_FC_SCR_MENU);

/*    
    // resize frame
    VfxRect bounds = VappShellPanel::getAppBounds();

    setPos(bounds.origin);
	setBounds(VfxRect(VFX_POINT_ZERO, bounds.size));
*/

    m_FCDetailScr->onExitViewEffect();
    m_FC3DScr->onEnterViewEffect();
}


void VappShellFCFrame::onUpdateContent(VappShellFCList* FCList, mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;

            if (ready->phb_ready)
            {
                if (m_info)
                {
                    VFX_OBJ_CLOSE(m_info);
                }
            }
            if (getPanelState() == APP_SHELL_ENTER_VIEW)
            {
                onEnterView();
            }
            break;
        }
        case EVT_ID_PHB_DEL_CONTACT:
        {
            if (getPanelState() == APP_SHELL_ENTER_VIEW)
            {
                if (getState() == VAPP_SHELL_FC_SCR_DETAIL)
                {
                    setState(VAPP_SHELL_FC_SCR_MENU);

                    // hide short cut bar
                    hideShortcutBar(VFX_FALSE);

                    m_FCDetailScr->onExitView(VFX_FALSE);
                }
                
                // refresh screen
                mmi_popup_display_simple(
                    (UI_string_type) GetString(STR_GLOBAL_DONE),
                    MMI_EVENT_INFO,
                    GRP_ID_ROOT,
                    NULL);     
            }
            
            break;
        }

        case EVT_ID_PHB_UPD_CONTACT:
        {
            if (getPanelState() == APP_SHELL_ENTER_VIEW)
            {
                srv_phb_op_evt_struct* data = (srv_phb_op_evt_struct*)evt;

                if (data->update_field != MMI_PHB_CONTACT_FIELD_IMAGE)
                {
                    // refresh screen
                    mmi_popup_display_simple(
                        (UI_string_type) GetString(STR_GLOBAL_DONE),
                        MMI_EVENT_INFO,
                        GRP_ID_ROOT,
                        NULL);
                }
                else
                {
                    // As 3D menu screen exist always, so update always
                    m_FC3DScr->onUpdateContent(FCList, evt);

                    if (getState() == VAPP_SHELL_FC_SCR_DETAIL)
                    {
                        m_FCDetailScr->onUpdateContent(FCList, evt);
                    }

                }
            }
            break;
        }

        default:
        {
            if (getPanelState() == APP_SHELL_ENTER_VIEW)
            {
                // As 3D menu screen exist always, so update always
                m_FC3DScr->onUpdateContent(FCList, evt);

                if (getState() == VAPP_SHELL_FC_SCR_DETAIL)
                {
                    m_FCDetailScr->onUpdateContent(FCList, evt);
                }
            }
            break;
        }
    }
}


void VappShellFCFrame::onTapMenuCell(VappShellFC3DScr* scr, VappShellFC* fc)
{
    VFX_UNUSED(scr);

    if (!m_FCList->isReady())
    {
        return;
    }
    
    // go to contact details screen
    if (fc->isFCValid())
    {
        onEnterDetailView();
    }
    // call phonebook list CUI to select one contact
    else
    {
        m_FCList->add(fc);
    }
}


void VappShellFCFrame::onBackDetailScr()
{
    onExitDetailView();
}


void VappShellFCFrame::stateConfig()
{
    // state == VAPP_SHELL_FC_SCR_DETAIL, means the screen is drawing backgroud
    switch (getState())
    {
        case VAPP_SHELL_FC_SCR_MENU:
        {
            // hide detail frame
            m_FCDetailScr->setFC(NULL);
            m_FCDetailScr->setHidden(VFX_TRUE);
            m_FCDetailScr->initHistory();
            break;
        }
        case VAPP_SHELL_FC_SCR_DETAIL:
        {
            VappShellFC *fc = m_FCList->getFocusFC();
            if (fc->isFCValid())
            {
                // hide 3D menu frame 
                m_FC3DScr->setHidden(VFX_TRUE);
                m_FCDetailScr->setFC(m_FCList->getFocusFC());
            }
            else
            {
                setState(VAPP_SHELL_FC_SCR_MENU);
                // hide detail frame
                m_FCDetailScr->setFC(NULL);
                m_FCDetailScr->setHidden(VFX_TRUE);
                m_FCDetailScr->onExitView(VFX_FALSE);
            }
            break;
        }
        default:
            break;
    }
}


/***************************************************************************** 
 * Class VappShellFC3DScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellFC3DScr", VappShellFC3DScr, VcpWheelMenu);

VappShellFC3DScr::VappShellFC3DScr(VappShellFCList *FCList)
{
    m_toolBarVisible = VFX_FALSE;
    m_toolBar = NULL;
    m_isMoving = VFX_FALSE;
    m_delete = VFX_FALSE;
    m_timer = NULL;
    m_FCList = FCList;
    m_count = FCList->getCount();
}


void VappShellFC3DScr::onInit()
{
    VcpWheelMenu::onInit();

    // set the child frame sort order
    setIsZSortChild(VFX_TRUE);

    //  set focus item
    setFocus(SHELL_FC_MAX_COUNT + m_FCList->getFocusID());    
    //setIsOpaque(VFX_TRUE);
    //setImgContent(VfxImageSrc(VAPP_SHELL_IMG_SWITCH_BG));

    
    // tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpSegmentButton, this);
    m_toolBar->setPos(SHELL_FC_TOOLBAR_X_POS, SHELL_FC_TOOLBAR_Y_POS);
    m_toolBar->setBounds(VfxRect(VFX_POINT_ZERO,VfxSize(SHELL_FC_TOOLBAR_WIDTH, SHELL_FC_TOOLBAR_HEIGHT)));

    m_toolBar->setStyle(VCP_SEGMENT_BUTTON_STYLE_IMAGE_ONLY);
    m_toolBar->addButton(
        SHELL_FC_SEG_ID_DELETE,
        VcpStateImage(VAPP_SHELL_IMG_DELETE_NOR, VAPP_SHELL_IMG_DELETE_PRE, VAPP_SHELL_IMG_DELETE_DIS, 0),
        VfxWString(),
        0);
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_toolBar->addButton(
        SHELL_FC_SEG_ID_SEND_MSG,
        VcpStateImage(VAPP_SHELL_FC_IMG_MSG_NOR, VAPP_SHELL_FC_IMG_MSG_PRE, VAPP_SHELL_FC_IMG_MSG_DIS, 0),
        VfxWString(),
        SHELL_FC_SEG_ID_DELETE);
    m_toolBar->addButton(
        SHELL_FC_SEG_ID_MAKE_CALL,
        VcpStateImage(VAPP_SHELL_FC_IMG_CALL_NOR, VAPP_SHELL_FC_IMG_CALL_PRE, VAPP_SHELL_FC_IMG_CALL_DIS, 0),
        VfxWString(),
        SHELL_FC_SEG_ID_SEND_MSG);
    #else
    m_toolBar->addButton(
        SHELL_FC_SEG_ID_MAKE_CALL,
        VcpStateImage(VAPP_SHELL_FC_IMG_CALL_NOR, VAPP_SHELL_FC_IMG_CALL_PRE, VAPP_SHELL_FC_IMG_CALL_DIS, 0),
        VfxWString(),
        SHELL_FC_SEG_ID_DELETE);
    #endif

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
}


void VappShellFC3DScr::onDeinit()
{
    VcpWheelMenu::onDeinit();
}


void VappShellFC3DScr::onInitView()
{
    // enable/diable toolbar
    toolBarConfig();
}


void VappShellFC3DScr::onDeinitView()
{
    // do nothing, now
}


void VappShellFC3DScr::onEnterView()
{
    setHidden(VFX_FALSE);

    setFocused(VFX_TRUE);
    
    // enable/diable toolbar
    toolBarConfig();

    // hide toolbar
    m_toolBar->setHidden(VFX_FALSE);

    // change state to normal
    changeState(VCP_WHEEL_MENU_NORMAL_STATE);

    // update 3D menu data
    onUpdateCell();

    // connect tool bar
    m_toolBar->m_signalButtonClicked.connect(this, &VappShellFC3DScr::onToolBarClick);
}


void VappShellFC3DScr::onExitView(VfxBool keepdata)
{
    // disconnect tool bar
    m_toolBar->m_signalButtonClicked.disconnect(this, &VappShellFC3DScr::onToolBarClick);
}


void VappShellFC3DScr::onEnterViewEffect()
{
    setHidden(MMI_FALSE);

    // hide toolbar
    m_toolBar->setHidden(VFX_TRUE);

#ifndef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__    
    // enter effect
    configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 500, 50, VCP_WHEEL_MENU_FOCUS_LAST);
    changeState(VCP_WHEEL_MENU_ENTER_STATE);

    m_timer->setStartDelay(500 + 3 * 50);
    m_timer->m_signalTick.connect(this, &VappShellFC3DScr::onTimerTick);

    m_timer->start();    
#else
    onStateChangeFinished(VCP_WHEEL_MENU_ENTER_STATE);
#endif
}


void VappShellFC3DScr::onTimerTick(VfxTimer *source)
{
    m_toolBar->setHidden(VFX_FALSE);
}


void VappShellFC3DScr::onExitViewEffect()
{
    // hide toolbar
    m_toolBar->setHidden(VFX_TRUE);

#ifndef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__    
    // exit effect
    configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 500, 50, VCP_WHEEL_MENU_FOCUS_FISRT);
    changeState(VCP_WHEEL_MENU_LEAVE_STATE);    
#else
    onStateChangeFinished(VCP_WHEEL_MENU_LEAVE_STATE);
#endif
}


void VappShellFC3DScr::onStateChangeFinished(
    VcpWheelMenuState finishedstate // [IN] finished state.
    )
{
    if (finishedstate == VCP_WHEEL_MENU_LEAVE_STATE)
    {
        // after exit effect, should signal parent to hidden this frame
        setHidden(MMI_TRUE);

        // keep exit view data
        onExitView(VFX_FALSE);
    }
    else if (finishedstate == VCP_WHEEL_MENU_ENTER_STATE)
    {
        onEnterView();
    }
}


void VappShellFC3DScr::setToolBarVisible(VfxBool visible)
{
    m_toolBarVisible = visible;
}


void VappShellFC3DScr::setMenuMoving(VfxBool moving)
{
    m_isMoving = moving;
}


void VappShellFC3DScr::onUpdateContent(VappShellFCList * FCList, mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_UPD_CONTACT:
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct* data = (srv_phb_op_evt_struct*)evt;

            if (FCList->exist(data->store_index) >= 0)
            {
                for (VfxS32 index = getFirstVisibleIndex(); index < getLastVisibleIndex(); index++)
                {
                    MenuCell *cell = (MenuCell*)getCellIfPresent(index, 0);
                    if (cell && (cell->getFC()->getStoreIndex() == data->store_index))
                    {
                        cell->onUpdateCell();
                        update();

                        break;
                    }
                }
            }
            
            break;
        }

        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;

            if (ready->phb_ready)
            {
                updateContent(VFX_FALSE);
            }
            break;
        }
        default:
            break;
    }

    // enable/diable toolbar
    toolBarConfig();
}


void VappShellFC3DScr::onCommandCallClick(VfxObject *obj, VfxId id)
{
    if (id != 0xffff && id != VCP_POPUP_BUTTON_NO_PRESSED)
    {
        VappShellFC * fc = m_FCList->getFocusFC();
        
        VfxWString &data = fc->getInfo(MMI_PHB_NUM_TYPE_TOTAL, id);
        
        ContactUISrv::makeCall(fc->getStoreIndex(), data, id);
    }
    else
    {
        // do nothing
    }
}


void VappShellFC3DScr::makeCall()
{
    VappShellFC* fc = m_FCList->getFocusFC();
    VfxU8 count = fc->getNumber();

    if (count > 0)
    {
        mmi_phb_num_type_enum numType;
        VfxU32 numId;
        VfxWString itemText = fc->getNextNumber(&numType, &numId);

        if (count > 1)
        {
            VcpCommandPopup* menu;
            VFX_OBJ_CREATE(menu, VcpCommandPopup, findScreen());
            
            menu->setText(VFX_WSTR_RES(VAPP_SHELL_FC_STR_MAKE_CALL));
            while(!itemText.isEmpty())
            {
                menu->addItem(numId, itemText, VCP_POPUP_BUTTON_TYPE_NORMAL);
                itemText = fc->getNextNumber(&numType, &numId);
            }

            menu->addItem(0xFFFF, itemText.loadFromRes(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
            
            menu->m_signalButtonClicked.connect(this, &VappShellFC3DScr::onCommandCallClick);

            menu->show(VFX_TRUE);
        }
        else
        {
            ContactUISrv::makeCall(
                fc->getStoreIndex(),
                fc->getInfo(numType, numId),
                numId);
        }
    }
}


void VappShellFC3DScr::onCommandMsgClick(VfxObject * obj, VfxId id)
{
    if (id != 0xffff)
    {
        #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        VappShellFC * fc = m_FCList->getFocusFC();
        
        VfxWString &data = fc->getInfo(MMI_PHB_NUM_TYPE_TOTAL, id);

        ContactUISrv::sendMsg(fc->getStoreIndex(), data, id);
        #endif
    }
    else
    {
        // do nothing
    }
}


void VappShellFC3DScr::sendMsg()
{
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    VappShellFC* fc = m_FCList->getFocusFC();

    if (fc->getNumber())
    {
        mmi_phb_num_type_enum numType;
        VfxU32 numId;
        VfxWString itemText = fc->getNextNumber(&numType, &numId);

        if (fc->getMobileNumberCount() > 1)
        {
            VcpCommandPopup* menu;
            VFX_OBJ_CREATE(menu, VcpCommandPopup, findScreen());

            menu->setText(VFX_WSTR_RES(VAPP_SHELL_FC_STR_SEND_MSG));
                        
            while(!itemText.isEmpty())
            {
                if (numType == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    menu->addItem(numId, itemText, VCP_POPUP_BUTTON_TYPE_NORMAL);
                }
                itemText = fc->getNextNumber(&numType, &numId);
            }
            
            menu->addItem(0xFFFF, itemText.loadFromRes(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
            
            menu->m_signalButtonClicked.connect(this, &VappShellFC3DScr::onCommandMsgClick);

            menu->show(VFX_TRUE);
        }
        else
        {
            ContactUISrv::sendMsg(
                fc->getStoreIndex(),
                fc->getInfo(numType, numId),
                numId);
        }
    }
#endif
}


void VappShellFC3DScr::onDeleteCell(VfxBasePopup* obj, VfxBasePopupStateEnum state)
{
    VFX_UNUSED(obj);

    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION && m_delete)
    {
        m_delete = VFX_FALSE;
        
        m_FCList->remove();
        //withdrawCell(getFocus(), VFX_FALSE);
        MenuCell *cell = (MenuCell*)getCellIfPresent(getFocus(), 0);
        cell->onDeleteName();

        toolBarConfig();
    }
}


void VappShellFC3DScr::onPreDeleteCell(VfxObject* obj, VfxId id)
{
    VFX_UNUSED(obj);

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_delete = VFX_TRUE;
    }
}


void VappShellFC3DScr::deleteCell()
{
    VcpConfirmPopup *deleteConfirm;
    VFX_OBJ_CREATE(deleteConfirm, VcpConfirmPopup, findScreen());

    deleteConfirm->setText(VFX_WSTR_RES(VAPP_SHELL_FC_STR_REMVOE_FC));
    deleteConfirm->setInfoType(VCP_POPUP_TYPE_QUESTION);

    deleteConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    deleteConfirm->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_REMOVE),
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    deleteConfirm->m_signalButtonClicked.connect(this, &VappShellFC3DScr::onPreDeleteCell);
    deleteConfirm->m_signalPopupState.connect(this, &VappShellFC3DScr::onDeleteCell);
    
    deleteConfirm->show(VFX_TRUE);
}


void VappShellFC3DScr::onToolBarClick(VfxObject* button, VfxId id)
{
    switch (id)
    {
        case SHELL_FC_SEG_ID_DELETE:
            deleteCell();
            break;
            
        case SHELL_FC_SEG_ID_MAKE_CALL:
            makeCall();
            break;
            
        #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        case SHELL_FC_SEG_ID_SEND_MSG:
            sendMsg();
            break;
        #endif            
        default:
            break;
    }
}


VfxS32 VappShellFC3DScr::getSubCellCount()
{
    return 1;
}


VfxFrame* VappShellFC3DScr::createCell(VfxS32 cell, VfxS32 subcell)
{
    VfxFrame* frame = NULL;

    if (subcell == 0)
    {
        MenuCell* item;
        VappShellFC* fc = m_FCList->getFC(cell % SHELL_FC_COUNT);

        VFX_OBJ_CREATE_EX(item, MenuCell, this, (fc));
        
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        if (getFocus() == cell)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }

        frame = item;
    }
    else
    {
        VFX_ASSERT(0);
    }

    FCMenuCellData data;
    data.cell = cell;
    data.subcell = subcell;
    data.tick = 0;
    setCellUserData(cell, subcell, frame, &data, sizeof(FCMenuCellData));

    return frame;
}    


void VappShellFC3DScr::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_UNUSED(cell);
    VFX_UNUSED(subcell);

    VFX_OBJ_CLOSE(cellFrame);
}


void VappShellFC3DScr::onUpdateCell()
{
    for (VfxS32 index = getFirstVisibleIndex(); index < getLastVisibleIndex(); index++)
    {
        MenuCell *cell = (MenuCell*)getCellIfPresent(index, 0);
        if (cell)
        {
            cell->onUpdateCell();
        }
    }
}


void VappShellFC3DScr::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    VFX_UNUSED(subcell);
    
    //((MenuCell *)frame)->onUpdate();

    if (cell == getFocus())
    {
        frame->bringToFront();
    }
}


VfxS32 VappShellFC3DScr::getBehindCount()
{
    return SHELL_FC_MENU_BEHIND_CELL_COUNT;
}


VfxS32 VappShellFC3DScr::getAheadCount()
{
    return SHELL_FC_MENU_AHEAD_CELL_COUNT;
}


VfxS32 VappShellFC3DScr::getCount()
{
    // m_count; make the cell turn round
    return (SHELL_FC_MAX_COUNT * 2);
}


void VappShellFC3DScr::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    if (VCP_WHEELMENU_IS_VALID_INDEX(previousFocusItem))
    {
        MenuCell* item = (MenuCell*) getCellIfPresent(previousFocusItem);
        if (item)
        {
            item->setHighlight(VFX_FALSE, VFX_TRUE);
        }
    }
    if (VCP_WHEELMENU_IS_VALID_INDEX(focusItem))
    {
        MenuCell* item = (MenuCell*) getCellIfPresent(focusItem);
        if (item)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }

        // set new focus index
        m_FCList->setFocusID(focusItem % SHELL_FC_COUNT);

        // enable/diable toolbar
        toolBarConfig();
    }
}


void VappShellFC3DScr::toolBarConfig()
{
    if (m_toolBar)
    {
        VappShellFC *fc = m_FCList->getFocusFC();
        
        if (fc->isFCValid())
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_DELETE, VFX_FALSE);
        }
        else
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_DELETE, VFX_TRUE);
        }
        if (fc->hasNumber() && (srv_mode_switch_is_network_service_available() && srv_sim_ctrl_any_sim_is_available()))
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_MAKE_CALL, VFX_FALSE);
        }
        else
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_MAKE_CALL, VFX_TRUE);
        }
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        if (fc->getMobileNumberCount() > 0)
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_SEND_MSG, VFX_FALSE);
        }
        else
        {
            m_toolBar->setButtonIsDisabled(SHELL_FC_SEG_ID_SEND_MSG, VFX_TRUE);
        }
    #endif
    }
}


VfxBool VappShellFC3DScr::onPenInput(VfxPenEvent & event)
{
    return Super::onPenInput(event);
}


VfxBool VappShellFC3DScr::onKeyInput(VfxKeyEvent & event)
{
    switch (event.type)
    {
        case VFX_KEY_EVENT_TYPE_DOWN:
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                setFocus(getFocus() - 1);
                return VFX_TRUE;
            }

            if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
            {
                setFocus(getFocus() + 1);
                return VFX_TRUE;
            }

            if (event.keyCode == VFX_KEY_CODE_CSK)
            {
                m_signalTap.postEmit(this, m_FCList->getFocusFC());	
                return VFX_TRUE;
            }

            break;
        }

        case VFX_KEY_EVENT_TYPE_REPEAT:
        {
            if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
            {
                setFocus(getFocus() - 1);
                return VFX_TRUE;
            }

            if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
            {
                setFocus(getFocus() + 1);
                return VFX_TRUE;
            }

            break;
        }

        default:
            break;
    }

    return Super::onKeyInput(event);
}   


void VappShellFC3DScr::onDragStart()
{
}


void VappShellFC3DScr::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / SHELL_FC_MENU_CELL_HEIGHT, 0);
}


void VappShellFC3DScr::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);
    
    if (yspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s = yspeed > 0 ? 1 : -1;
        // 333.3f, macro
        VfxFloat m = VFX_ABS(yspeed) / 333.3f;
        
        if (m > 3) m = 3;
        
        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
    }
}    


void VappShellFC3DScr::onTap(VfxPoint pt)
{

    VfxS32 up       = SHELL_FC_MENU_CELL_Y_POS - SHELL_FC_MENU_CELL_HEIGHT / 2;
    VfxS32 down     = SHELL_FC_MENU_CELL_Y_POS + SHELL_FC_MENU_CELL_HEIGHT / 2;

    if (pt.y >= up && pt.y <= down)
    {
        MenuCell* cell = (MenuCell*)getCellIfPresent(getFocus());
        if (cell)
        {
            // because maybe the scroll index is changing by drag
            // fix it
            setFocus(getFocus());
            
            // Notify cell handler
            // cell->click();
            m_signalTap.postEmit(this, m_FCList->getFocusFC());
        }
    }
    // TODO: change the focus cell, order, check with BD
    else if (pt.y < up)
    {
        setFocus(getFocus() - 1);
    }
    else if (pt.y > down)
    {
        setFocus(getFocus() + 1);
    }
}


VcpWheelMenuFrameEffectCBFuncPtr VappShellFC3DScr::getFrameEffectCB()
{
    return &VappShellFC3DScr::myFrameEffectCB;
}


vrt_render_dirty_type_enum VappShellFC3DScr::myFrameEffectCB(
                    VfxS32                      cell,           // [IN] the cell index
                    VfxS32                      subCell,        // [IN] the sub cell index
                    VfxFloat                    cellRelPos,     // [IN] the cell position
                    vrt_frame_visual_property_struct * target_frame,
                    VfxFloat                    fPos,
                    VfxS32                      focus,
                    VfxRect                     viewBounds,
                    void                        *userData,
                    VfxU32                      userDataSize,
                    VcpWheelMenuState           state,          // [IN] the state of Menu
                    VfxFloat                    level           // [IN] the level of state
                    )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(userDataSize);
    
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(userDataSize == sizeof(FCMenuCellData));

    //FCMenuCellData* data = (FCMenuCellData*)userData;
 
    VfxFloat offset = cellRelPos; 

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
#endif

    // becase focused index = 3
    VfxFloat index = 3 + offset;

    // check out of range, then set boundary transform
    if (index < 0)
    {
        target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        target_frame->transform.data.matrix3x3 = g_transformArray[0];
    }
    else if (index > 6)
    {
        target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        target_frame->transform.data.matrix3x3 = g_transformArray[6];
    } 
    else
    {
        // find out the lowIndex and upIndex for linear interpolation.
        VfxS32 lowIndex = VfxS32(index);
        VfxS32 upIndex = lowIndex + 1;
        vrt_matrix3x3_struct tempTransform;
        // VfxU8 i;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
        tempTransform.m[0] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[0] + (index - lowIndex) * g_transformArray[upIndex].m[0];
        tempTransform.m[3] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[1] + (index - lowIndex) * g_transformArray[upIndex].m[1];
        tempTransform.m[6] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[2] + (index - lowIndex) * g_transformArray[upIndex].m[2];
        tempTransform.m[1] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[3] + (index - lowIndex) * g_transformArray[upIndex].m[3];
        tempTransform.m[4] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[4] + (index - lowIndex) * g_transformArray[upIndex].m[4];
        tempTransform.m[7] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[5] + (index - lowIndex) * g_transformArray[upIndex].m[5];
        tempTransform.m[2] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[6] + (index - lowIndex) * g_transformArray[upIndex].m[6];
        tempTransform.m[5] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[7] + (index - lowIndex) * g_transformArray[upIndex].m[7];
        tempTransform.m[8] = ((VfxFloat)upIndex - index) * g_transformArray[lowIndex].m[8] + (index - lowIndex) * g_transformArray[upIndex].m[8];
#endif
        
        target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3;
        target_frame->transform.data.matrix3x3 = tempTransform;
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
#endif

    // opacity setting
    target_frame->pos_z = VFX_ABS(offset);


    target_frame->opacity = (3.0f - VFX_ABS(offset)) / 3.0f;

    if (target_frame->opacity < 0)
    {
        target_frame->opacity = 0;
    }

#ifndef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__
    // flap out
    if (state != VCP_WHEEL_MENU_NORMAL_STATE)
    {
        /* to avoid rotate transform final little mistake */
        if (level == 1 && state == VCP_WHEEL_MENU_ENTER_STATE)
        {
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
        
        VfxMatrix3x3Ex mat = VfxMatrix3x3Ex(target_frame->transform.data.matrix3x3);
        VfxMatrix3x3Ex tempMat;

        // VfxFloat tx, ty;
        // tx = mat.m[6];
        // ty = mat.m[7];

        VfxFloat p1x, p1y, p2x, p2y;

        p1x = mat.m[6]/mat.m[8];
        p1y = mat.m[7]/mat.m[8];
        
        p2x = (mat.m[0] * SHELL_FC_MENU_CELL_WIDTH + mat.m[3] * SHELL_FC_MENU_CELL_HEIGHT + mat.m[6]) /
                (mat.m[2] * SHELL_FC_MENU_CELL_WIDTH + mat.m[5] * SHELL_FC_MENU_CELL_HEIGHT + mat.m[8]);
        
        p2y = (mat.m[1] * SHELL_FC_MENU_CELL_WIDTH + mat.m[4] * SHELL_FC_MENU_CELL_HEIGHT + mat.m[7]) /
                (mat.m[2] * SHELL_FC_MENU_CELL_WIDTH + mat.m[5] * SHELL_FC_MENU_CELL_HEIGHT + mat.m[8]);

        tempMat.setTranslation((-1 * (p1x + p2x)/2), (-1 * (p1y + p2y)/2));
        mat = tempMat * mat;
       
        tempMat.setRotateByZ(VFX_DEG_TO_RAD(360 * level));
        mat = tempMat * mat;
        
        if (state == VCP_WHEEL_MENU_ENTER_STATE)
        {
            tempMat.setTranslation(SHELL_FC_MENU_CELL_TRANS_WIDTH - SHELL_FC_MENU_CELL_TRANS_WIDTH * level, 0);
        }
        else
        {
            tempMat.setTranslation(-(SHELL_FC_MENU_CELL_TRANS_WIDTH * level), 0);
        }
        mat = tempMat * mat;

        tempMat.setTranslation((p1x + p2x)/2 ,(p1y + p2y)/2);
        mat = tempMat * mat;

        mat.initMatrix3x3(target_frame->transform.data.matrix3x3);
    }
#endif
    
    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


VappShellFC3DScr::MenuCell::MenuCell(VappShellFC *fc):
        m_FCName(NULL),
        m_FCAdd(NULL),
        m_bgImg(NULL),
        m_FCImg(NULL),
        m_highlight(VFX_FALSE)
{
    VFX_ASSERT(fc != NULL);
    m_FC = fc;
    setCacheMode(VFX_CACHE_MODE_FORCE);
}

void VappShellFC3DScr::MenuCell::setFC(VappShellFC * fc)
{
    m_FC = fc;
}


VappShellFC* VappShellFC3DScr::MenuCell::getFC()
{
    return m_FC;
}


void VappShellFC3DScr::MenuCell::click()
{
    // go to fc detail screen or add a new fc
    m_signalClick.postEmit(this, m_FC);
}

void VappShellFC3DScr::MenuCell::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);
    adjustPos(value);
}

void VappShellFC3DScr::MenuCell::adjustPos(const VfxRect &value)
{
    // ajust child frame position, bounds
}

//void VappShellFC3DScr::MenuCell::remove()
//{

//}

void VappShellFC3DScr::MenuCell::onUpdateCell()
{
    // update contact image
    const VfxImageSrc &image = m_FC->getImg();
    m_FCImg->setCenterImg(image);

    if (m_FC->isFCValid())
    {
        m_FCName->set(m_FC, VappFCNameFrame::VAPP_FC_NAME_CENTER);

        m_FCName->setHidden(VFX_FALSE);
        m_FCAdd->setHidden(VFX_TRUE);
        
    }
    else
    {
        m_FCName->setHidden(VFX_TRUE);
        m_FCAdd->setHidden(VFX_FALSE);
    }
    
    setAutoAnimate(VFX_FALSE);

}


void VappShellFC3DScr::MenuCell::setHighlight(VfxBool isHighLight, VfxBool isAnim)
{
    m_highlight = isHighLight;
    if (isHighLight)
    {
        bringToFront();
    }
}

void VappShellFC3DScr::MenuCell::onInit()
{
    VfxControl::onInit();

    // post the other frames initialization to onUpdate
    
    //sendToBack();
    setOpacity(1.0f);
    setAnchor(VfxFPoint(0.5f, 0.5f));
    setIsCached(VFX_TRUE);
    //setIsOpaque(VFX_TRUE);
    setPos(SHELL_FC_MENU_CELL_TRANS_WIDTH/2, SHELL_FC_MENU_CELL_Y_POS);
    setSize(SHELL_FC_MENU_CELL_WIDTH, SHELL_FC_MENU_CELL_HEIGHT);

    // back group image
    VFX_OBJ_CREATE(m_bgImg, VfxImageFrame, this);
    m_bgImg->setResId(VAPP_SHELL_FC_IMG_BG);
    m_bgImg->setAnchor(VfxFPoint(0.5, 0.5));
    m_bgImg->setPos(SHELL_FC_MENU_CELL_WIDTH / 2,SHELL_FC_MENU_CELL_HEIGHT / 2);

    // contact image
    VFX_OBJ_CREATE(m_FCImg, VappFCImage, this);
    m_FCImg->setPos(SHELL_FC_MENU_CELL_IMG_X_POS, SHELL_FC_MENU_CELL_HEIGHT/2);

    VFX_OBJ_CREATE(m_deleteEffect, VcpFrameEffect, this);
    m_deleteEffect->m_signalFinished.connect(this, &VappShellFC3DScr::MenuCell::onDeleteCellFinished);

    VFX_OBJ_CREATE(m_deleteEffect2, VcpFrameEffect, this);

    // contact name
    VFX_OBJ_CREATE(m_FCName, VappFCNameFrame, this);
    m_FCName->setAnchor(0.5f, 0.5f);
    m_FCName->setPos(VfxPoint(SHELL_FC_MENU_CELL_NAME_X_POS, SHELL_FC_MENU_CELL_HEIGHT/2));
    m_FCName->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(SHELL_FC_MENU_CELL_NAME_WIDTH, SHELL_FC_MENU_CELL_HEIGHT)));

    VFX_OBJ_CREATE(m_FCAdd, VappFCAddFrame, this);
    m_FCAdd->setAnchor(0.5f, 0.5f);
    m_FCAdd->setPos(VfxPoint(SHELL_FC_MENU_CELL_NAME_X_POS, SHELL_FC_MENU_CELL_HEIGHT/2));
    m_FCAdd->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(SHELL_FC_MENU_CELL_NAME_WIDTH, SHELL_FC_MENU_CELL_HEIGHT)));
    m_FCAdd->setImg(VAPP_SHELL_FC_IMG_ADD);
    m_FCAdd->setText(VFX_WSTR_RES(VAPP_SHELL_FC_STR_ADD_NEW_CONTACT), SHELL_FC_MENU_CELL_ADD_FONT, 2);
    m_FCAdd->commit();

    onUpdateCell();
}


void VappShellFC3DScr::MenuCell::onDeinit()
{
    VfxControl::onDeinit();
}

VfxS32 VappShellFC3DScr::MenuCell::getMenuPos()
{
    return 0;
}

VappShellFC3DScr* VappShellFC3DScr::MenuCell::getMenu()
{
    if (getParentFrame())
    {
        return (VappShellFC3DScr*) getParentFrame();
    }
	
    return NULL;
}


void VappShellFC3DScr::MenuCell::onDeleteCellFinished(VfxFrame *obj, VfxBool complete)
{
    onUpdateCell();
}

void VappShellFC3DScr::MenuCell::onDeleteName()
{
    m_FCAdd->setHidden(VFX_FALSE);
    
    m_deleteEffect->applyEffect(
        m_FCName,
        VCP_EFFECT_FADE_OUT,
        1500,
        VCP_EFFECT_DIRECTION_FROM_NONE,
        VFX_FALSE,
        NULL,
        0);
    m_deleteEffect->applyEffect(
        m_FCAdd,
        VCP_EFFECT_FADE_IN,
        1500,
        VCP_EFFECT_DIRECTION_FROM_NONE,
        VFX_FALSE,
        NULL,
        0);
}

/***************************************************************************** 
 * Class VappShellFCDetailScr
 *****************************************************************************/
void VappShellFCDetailScr::onInit()
{
    Super::onInit();

    // make sure , this is created first.
    VFX_OBJ_CREATE(m_effect, VcpFrameEffect, this);
    m_effect->m_signalFinished.connect(this, &VappShellFCDetailScr::onEffectFinisted);
        
    // create back button
    VFX_OBJ_CREATE(m_back, VcpButton, this);

    m_back->setImage(VcpStateImage(VAPP_SHELL_IMG_BK_NORMAL, VAPP_SHELL_IMG_BK_PRESS, 0, 0));
    m_back->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);

    // create image button
    VFX_OBJ_CREATE(m_FCImg, VappFCImageButton, this);
    
    // create name frame
    VFX_OBJ_CREATE(m_name, VappFCNameFrame, this);

    // create list cps
    VFX_OBJ_CREATE_EX(m_detListProvider, VappShellListDetailProvider, this, (m_FC));    
    VFX_OBJ_CREATE(m_detList, VcpListMenu, this);
    m_detListProvider->setMenu(m_detList);

    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    VFX_OBJ_CREATE(m_msgListProvider, VappMsgListProvider, this);
    VFX_OBJ_CREATE(m_msgs, VcpListMenu, this);
    m_msgListProvider->setMenu(m_msgs);
    #endif

    VFX_OBJ_CREATE(m_clogListProvider, VappShellListCHProvider, this);
    VFX_OBJ_CREATE(m_calls, VcpListMenu, this);
    m_clogListProvider->setMenu(m_calls);

    // create tab bar
    VFX_OBJ_CREATE(m_tab, VcpTabBar, this);

}


void VappShellFCDetailScr::onDeinit()
{
    // disconnect signal
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_msgListProvider->preDeinit();
    #endif    
    Super::onDeinit();
}

void VappShellFCDetailScr::initHistory()
{
    m_history.id = VAPP_SHELL_FC_DETAIL_INFO;

    m_history.callsListIndex = 0;
    m_history.infoListIndex = 0;
    m_history.msgsListIndex = 0;

    m_history.infoListCount = 0;
    m_history.msgsListCount = 0;

    m_history.storeIndex = 0xffff;
}

void VappShellFCDetailScr::storeHistory()
{
    m_history.id = m_currTab;

    m_history.callsListIndex = m_calls->getFocusItemIndex();
    m_history.infoListIndex = m_detList->getFocusItemIndex();
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_history.msgsListIndex = m_msgs->getFocusItemIndex();
    #endif
    m_history.infoListCount = m_detListProvider->getCount();
    m_detList->getHistory(&m_history.infoListHistory);

    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    /* if message list is updating, then use pre-list history */
    if (!m_msgListProvider->isUpdating())
    {
        m_history.msgsListCount = m_msgListProvider->getCount();
        m_msgs->getHistory(&m_history.msgsListHistory);
    }
    #endif    
    m_history.storeIndex = m_FC->getStoreIndex();
}

void VappShellFCDetailScr::getHistory()
{
    if (m_FC)
    {
        m_currTab = m_history.id;
        m_detListProvider->setFCHistory(m_history.infoListCount, &m_history.infoListHistory);
        #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        m_msgListProvider->setFCHistory(m_history.msgsListCount, &m_history.msgsListHistory);
        #endif
    }
    else
    {
        initHistory();
    }
}

void VappShellFCDetailScr::onInitView()
{
    // restore history data
    getHistory();
    
    // back button
    m_back->setRect(SHELL_FC_DETAIL_BACK_X_POS, SHELL_FC_DETAIL_BACK_Y_POS, SHELL_FC_DETAIL_BACK_WIDTH, SHELL_FC_DETAIL_BACK_HIGHT);

    // image button
    m_FCImg->setPos(VfxPoint(SHELL_FC_DETAIL_IMG_X_POS, SHELL_FC_DETAIL_IMG_Y_POS));
    m_FCImg->setSize(
        VfxImageSrc(VAPP_SHELL_FC_IMG_DEFAULT).getSize().width + VfxImageSrc(VAPP_SHELL_FC_IMG_CONTACT_SHADOW).getSize().width,
        VfxImageSrc(VAPP_SHELL_FC_IMG_DEFAULT).getSize().height);
    m_FCImg->set(m_FC);

    // name frame
    m_name->setPos(VfxPoint(SHELL_FC_DETAIL_NAME_X_POS, SHELL_FC_DETAIL_NAME_Y_POS));
    m_name->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(SHELL_FC_DETAIL_NAME_WIDTH, SHELL_FC_DETAIL_NAME_HIGHT)));
    m_name->set(m_FC, VappFCNameFrame::VAPP_FC_NAME_LEFT);

    VfxRect rect = getBounds();

    // tab bar
    m_tab->setAnchor(0.0f, 1.0f);
    m_tab->setPos(VfxPoint(0, rect.getHeight()));
    m_tab->setLayout(VCP_TABBAR_LAYOUT_BOTTOM);

    m_tab->setSize(rect.getWidth(), m_tab->getSize().height);

    m_tab->addTab(
        VAPP_SHELL_FC_DETAIL_INFO,
        VcpStateImage(VAPP_SHELL_FC_IMG_DETAIL_NOR, VAPP_SHELL_FC_IMG_DETAIL_HIGH, 0, VAPP_SHELL_FC_IMG_DETAIL_HIGH),
        VFX_WSTR_RES(VAPP_SHELL_FC_STR_DETAILS));
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_tab->addTab(
        VAPP_SHELL_FC_DETAIL_MSG,
        VcpStateImage(VAPP_SHELL_FC_IMG_MSGS_NOR, VAPP_SHELL_FC_IMG_MSGS_HIGH, 0, VAPP_SHELL_FC_IMG_MSGS_HIGH),
        VFX_WSTR_RES(VAPP_SHELL_FC_STR_MSGS));    
    #endif
    m_tab->addTab(
        VAPP_SHELL_FC_DETAIL_CLOG,
        VcpStateImage(VAPP_SHELL_FC_IMG_CALLS_NOR, VAPP_SHELL_FC_IMG_CALLS_HIGH, 0, VAPP_SHELL_FC_IMG_CALLS_HIGH),
        VFX_WSTR_RES(VAPP_SHELL_FC_STR_CALLS));


    // need to use the pre-time tab id, if redraw screen
    configTab();

    VfxS32 listPosY = rect.getHeight() - m_tab->getBounds().getHeight();
    VfxS32 listHeight = listPosY - SHELL_FC_DETAIL_LIST_Y_POS;

    // detail list
    m_detList->setAnchor(0.0f, 1.0f);
    m_detList->setPos(VfxPoint(0, listPosY));
    m_detList->setSize(rect.getWidth(), listHeight);
    
    m_detList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_detList->setContentProvider(m_detListProvider);
    m_detList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_detList->setThemeData(g_fc_list_menu_theme);

    m_detListProvider->setFC(m_FC);
    m_detListProvider->getContent(VFX_FALSE);


    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    // msgs list   
    m_msgs->setAnchor(0.0f, 1.0f);
    m_msgs->setPos(VfxPoint(0, listPosY));
    m_msgs->setSize(rect.getWidth(), listHeight);

    m_msgs->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_QUADRUPLE_TEXT);
    m_msgs->setContentProvider(m_msgListProvider);
    m_msgs->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_msgs->setThemeData(g_fc_list_menu_theme);

    m_msgListProvider->setFC(m_FC);
    m_msgListProvider->getContent(VFX_FALSE);
    #endif
    // clog list
    m_calls->setAnchor(0.0f, 1.0f);
    m_calls->setPos(VfxPoint(0, listPosY));
    m_calls->setSize(rect.getWidth(), listHeight);
    
    m_calls->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_QUINTUPLE_TEXT);
    m_calls->setContentProvider(m_clogListProvider);
    m_calls->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
    m_calls->setThemeData(g_fc_list_menu_theme);

    m_clogListProvider->setFC(m_FC);
    m_clogListProvider->getContent(VFX_FALSE);

}

void VappShellFCDetailScr::onDeinitView()
{
    // now, nothing to do
}

void VappShellFCDetailScr::onEnterView()
{
    setFocused(VFX_TRUE);
    
    // refresh data
    m_detListProvider->setFC(m_FC);
    m_detListProvider->getContent(VFX_TRUE);

    m_FCImg->set(m_FC);
    m_FCImg->m_signalClicked.connect(this, &VappShellFCDetailScr::onTabImage);

    m_name->set(m_FC, VappFCNameFrame::VAPP_FC_NAME_LEFT);

    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_msgListProvider->setFC(m_FC);
    m_msgListProvider->getContent(VFX_TRUE);
    #endif
    m_clogListProvider->setFC(m_FC);
    m_clogListProvider->getContent(VFX_TRUE);
    
    // back button
    m_back->m_signalClicked.connect(this, &VappShellFCDetailScr::onBackButton);
    
    // list lisener
    m_detList->m_signalTapItem.connect(this, &VappShellFCDetailScr::onTapItem);
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__ 
    m_msgs->m_signalTapItem.connect(this, &VappShellFCDetailScr::onTapItem);
    #endif
    m_calls->m_signalTapItem.connect(this, &VappShellFCDetailScr::onTapItem);
    
    // reset tab position, after hide the shortcut bar
    m_tab->m_signalTabSwitched.connect(this, &VappShellFCDetailScr::onSwitchTab);

    if (m_currTab == VAPP_SHELL_FC_DETAIL_CLOG)
    {
        m_clogListProvider->setViewed(VFX_TRUE);
    }

    // register message handler
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY,    &VappMsgListProvider::onUmSrvReadyNotify, m_msgListProvider);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,  &VappMsgListProvider::onUmSrvRefreshNotify, m_msgListProvider);
    #endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_READY,         &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_ADD_LOG,       &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_LOG,    &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_UPDATE_ALL,    &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_LOG,       &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_reg_event(EVT_ID_SRV_CLOG_DEL_ALL,       &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    

    // Connect signal to refresh the recent event time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappShellFCDetailScr::onTimeChanged);
}

void VappShellFCDetailScr::onTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_DAY)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_CHANGE_NOTIFY, 1);
 
        // Update the time string of each call log    
        m_clogListProvider->refresh();
    }
}

void VappShellFCDetailScr::onExitView(VfxBool keepData)
{
    setHidden(VFX_TRUE);

    if (keepData)
    {
        storeHistory();
    }
    else
    {
        // reset data provider
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        m_msgListProvider->setFC(NULL);
    #endif
        m_clogListProvider->setFC(NULL);

        initHistory();
    }

    // when exit the screen reset data base
    m_FC = NULL;

    m_clogListProvider->clearMissedNum();

    // deregister message handler
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY,  &VappMsgListProvider::onUmSrvReadyNotify, m_msgListProvider);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH,&VappMsgListProvider::onUmSrvRefreshNotify, m_msgListProvider);
    #endif    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_READY,       &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_ADD_LOG,     &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_LOG,  &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_UPDATE_ALL,  &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_LOG,     &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_CLOG_DEL_ALL,     &VappShellListCHProvider::onClogChangeNotify, m_clogListProvider);

    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappShellFCDetailScr::onTimeChanged);
}


void VappShellFCDetailScr::onEffectFinisted(VfxFrame *obj, VfxBool isCompleted)
{
    if (m_state)
    {
    }
    else
    {
        // after exit view effect, call exit view
        onExitView(VFX_FALSE);
    }
    m_effect->restore();
}


void VappShellFCDetailScr::onEnterViewEffect()
{
    setHidden(VFX_FALSE);

    // config visable components
    getHistory();
    configTab();

    // show enter effect
    
    // after effect, call enter view
    onEnterView();

#ifndef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__        
    m_effect->applyEffect(
        this,
        VCP_EFFECT_TRANSFORMER,
        (500 + 3 * 50),
        VCP_EFFECT_DIRECTION_FROM_NONE,
        VFX_FALSE,
        NULL,
        0);

    m_state = 1; // enter view
#else
    // do nothing
#endif
}

void VappShellFCDetailScr::onExitViewEffect()
{
    // disconnect signal
    // back button
    m_back->m_signalClicked.disconnect(this, &VappShellFCDetailScr::onBackButton);
    
    // list lisener
    m_detList->m_signalTapItem.disconnect(this, &VappShellFCDetailScr::onTapItem);
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    m_msgs->m_signalTapItem.disconnect(this, &VappShellFCDetailScr::onTapItem);
    #endif
    m_calls->m_signalTapItem.disconnect(this, &VappShellFCDetailScr::onTapItem);
    
    // reset tab position, after hide the shortcut bar
    m_tab->m_signalTabSwitched.disconnect(this, &VappShellFCDetailScr::onSwitchTab);

#ifndef __MMI_VUI_SHELL_FAV_CONTACT_SLIM__    
    m_effect->applyEffect(
        this,
        VCP_EFFECT_TRANSFORMER,
        (500 + 3 * 50),
        VCP_EFFECT_DIRECTION_FROM_NONE,
        VFX_TRUE,
        NULL,
        0);

    m_state = 0; // exit view
#else
    // after exit view effect, call exit view
    onExitView(VFX_FALSE);
#endif
}

void VappShellFCDetailScr::onUpdateContent(VappShellFCList * FCList, mmi_event_struct* evt)
{
    // refresh data
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_UPD_CONTACT:
        {
            srv_phb_op_evt_struct* data = (srv_phb_op_evt_struct*)evt;

            if (data->store_index == m_FC->getStoreIndex())
            {
                if (data->update_field == MMI_PHB_CONTACT_FIELD_IMAGE)
                {
                    // refresh image
                    m_FCImg->set(m_FC);
                }
            }

            break;
        }
        
        default:
            break;
    }
}

void VappShellFCDetailScr::onBackButton(VfxObject* obj, VfxId id)
{
    VFX_UNUSED(obj);
    VFX_UNUSED(id);
    m_signalBack.postEmit();
}

void VappShellFCDetailScr::onTabImageCb(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case VAPP_SHELL_FC_TAKE_PHOTO:
        {
            m_FC->takeImg();
            break;
        }
        case VAPP_SHELL_FC_SELECT_FILE:
        {
            m_FC->addImg();
            break;
        }
        case VAPP_SHELL_FC_DELETE_IMG:
        {
            m_FC->removeImg();
            break;
        }
        default:
            break;
    }
}

void VappShellFCDetailScr::onTabImage(VfxObject *obj, VfxId id)
{
    VFX_UNUSED(obj);
    VFX_UNUSED(id);
    
    VcpCommandPopup* menu;
    VFX_OBJ_CREATE(menu, VcpCommandPopup, findScreen());

    // take photo
    menu->addItem(VAPP_SHELL_FC_TAKE_PHOTO, VFX_WSTR_RES(VAPP_SHELL_FC_STR_TAKE_PHOTO), VCP_POPUP_BUTTON_TYPE_NORMAL);
    // select from file
#if defined(__MMI_FILE_MANAGER__)    
    menu->addItem(VAPP_SHELL_FC_SELECT_FILE, VFX_WSTR_RES(VAPP_SHELL_FC_STR_SELECT_FILE), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
    // remove file
    if (m_FC->hasImg())
    {
        menu->addItem(VAPP_SHELL_FC_DELETE_IMG, VFX_WSTR_RES(STR_GLOBAL_REMOVE), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    // cancel
    menu->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    
    menu->m_signalButtonClicked.connect(this, &VappShellFCDetailScr::onTabImageCb);

    menu->show(VFX_TRUE);
}


void VappShellFCDetailScr::onTapItem(VcpListMenu* list, VfxU32 index)
{
    if (list == m_detList)
    {
        switch (m_detListProvider->m_action[index].m_action)
        {
            case SHELL_FC_MAKE_CALL:
                ContactUISrv::makeCall(
                    m_FC->getStoreIndex(),
                    m_FC->getInfo(m_detListProvider->m_action[index].m_infoType, m_detListProvider->m_action[index].m_infoId),
                    m_detListProvider->m_action[index].m_infoId);
                break;
                
            case SHELL_FC_SEND_MSG:
                ContactUISrv::sendMsg(
                    m_FC->getStoreIndex(),
                    m_FC->getInfo(m_detListProvider->m_action[index].m_infoType, m_detListProvider->m_action[index].m_infoId),
                    m_detListProvider->m_action[index].m_infoId);
                break;
                
            case SHELL_FC_SEND_MAIL:
                ContactUISrv::sendEmail(
                    m_FC->getStoreIndex(),
                    m_FC->getInfo(m_detListProvider->m_action[index].m_infoType, m_detListProvider->m_action[index].m_infoId),
                    m_detListProvider->m_action[index].m_infoId);
                break;
            default:
                break;
        }
    }
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    else if (list == m_msgs)
    {
        ContactUISrv::viewMsg(m_msgListProvider->getMsgId(index), m_msgListProvider->getMsgType(index));
    }
    #endif
    else if (list == m_calls)
    {
        m_clogListProvider->onTapItem(index);
    }

}

void VappShellFCDetailScr::onSwitchTab(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_SHELL_FC_DETAIL_INFO:
        {
            // show phonebook info page
            if (m_currTab != VAPP_SHELL_FC_DETAIL_INFO)
            {
                // change tab list
                m_currTab = VAPP_SHELL_FC_DETAIL_INFO;
            }
            break;
        }    
        case VAPP_SHELL_FC_DETAIL_CLOG:
        {
            // show call log info about this contact
            if (m_currTab != VAPP_SHELL_FC_DETAIL_CLOG)
            {
                // change tab list
                m_currTab = VAPP_SHELL_FC_DETAIL_CLOG;

                m_clogListProvider->setViewed(VFX_TRUE);
            }
            break;
        }    
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        case VAPP_SHELL_FC_DETAIL_MSG:
        {
            // show messages about this contact
            if (m_currTab != VAPP_SHELL_FC_DETAIL_MSG)
            {
                // change tab list
                m_currTab = VAPP_SHELL_FC_DETAIL_MSG;
            }
            
            break;
        }    
#endif
        default:
            break;
    }

    // config tab and list menu
    configTab();
}

void VappShellFCDetailScr::configTab()
{
    if (m_currTab == VAPP_SHELL_FC_DETAIL_INFO)
    {
        m_tab->setHighlightedTab(VAPP_SHELL_FC_DETAIL_INFO);

        m_detList->setHidden(VFX_FALSE);
        m_calls->setHidden(VFX_TRUE);
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        m_msgs->setHidden(VFX_TRUE);
    #endif
    }
    else if (m_currTab == VAPP_SHELL_FC_DETAIL_CLOG)
    {
        m_tab->setHighlightedTab(VAPP_SHELL_FC_DETAIL_CLOG);

        m_calls->setHidden(VFX_FALSE);
        m_detList->setHidden(VFX_TRUE);
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
        m_msgs->setHidden(VFX_TRUE);    
    #endif
    }
    #ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    else if (m_currTab == VAPP_SHELL_FC_DETAIL_MSG)
    {
        m_tab->setHighlightedTab(VAPP_SHELL_FC_DETAIL_MSG);

        m_detList->setHidden(VFX_TRUE);
        m_calls->setHidden(VFX_TRUE);
        m_msgs->setHidden(VFX_FALSE);
        m_msgListProvider->refresh();
    }
    #endif
}


void VappShellFCDetailScr::setFC(VappShellFC * fc)
{
    m_FC = fc;
}




/***************************************************************************** 
 * Class VappFCNameFrame
 *****************************************************************************/
void VappFCNameFrame::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_name, VfxTextFrame, this);
    m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
}

void VappFCNameFrame::onDeinit()
{
    VfxFrame::onDeinit();
}

void VappFCNameFrame::set(VappShellFC* fc, vapp_fc_name_mode mode)
{
    m_FC = fc;

    if (fc)
    {
        if (fc->getFieldFlag() & MMI_PHB_CONTACT_FIELD_NAME)
        {
            setName(fc->getInfo(MMI_PHB_NUM_TYPE_TOTAL, SRV_PHB_ENTRY_FIELD_NAME));
        }
        else
        {
            setName(fc->getInfo(MMI_PHB_NUM_TYPE_TOTAL, SRV_PHB_ENTRY_FIELD_NUMBER));
        }
        
        VfxFontDesc font;
        
        font.size = VFX_FONT_DESC_VF_SIZE(SHELL_FC_MENU_CELL_NAME_FONT);
        
        m_name->setFont(font);
        
        VfxRect rect = this->getBounds();
        
        if (mode == VAPP_FC_NAME_CENTER)
        {
            m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);

            m_name->setAnchor(0.5f, 0.5f);
            m_name->setPos(rect.getMidX(), rect.getMidY());
        }
        else
        {
            m_name->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

            m_name->setAnchor(0.0f, 0.5f);
            m_name->setPos(rect.getMinX(), rect.getMidY());
        }
        
        m_name->setSize(rect.size);
    }
}

void VappFCNameFrame::setName(VfxWString& name)
{
    m_name->setString(name);
}

void VappFCNameFrame::setTitle(VfxWString& title)
{
    m_title->setString(title);
}

void VappFCNameFrame::commit()
{
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
#endif    
}


/***************************************************************************** 
 * Class VappFCImageButton
 *****************************************************************************/
void VappFCImageButton::set(VappShellFC *fc)
{
    if (fc)
    {
        VfxRect rect = getBounds();
        m_FCImg->setPos(rect.size.height/2, rect.size.height/2);
        m_FCImg->setCenterImg(fc->getImg());

        // image shadow
        m_FCImgShadow->setResId(VAPP_SHELL_FC_IMG_CONTACT_SHADOW);
        m_FCImgShadow->setAnchor(0.0f, 1.0f);
        m_FCImgShadow->setPos(
            VfxImageSrc(VAPP_SHELL_FC_IMG_DEFAULT).getSize().width - 5, // - 5, to put it backgroup of image
            rect.getMaxY());
        
        if (!fc->hasImg())
        {
            m_addImg->setHidden(VFX_FALSE);
            m_addImg->setAnchor(0.5f, 1.0f);
            m_addImg->setPos(VfxImageSrc(VAPP_SHELL_FC_IMG_DEFAULT).getSize().width/2, rect.getMaxY() - 3);
            m_addImg->setSize(SHELL_FC_DETAIL_IMG_ADD_WIDTH, SHELL_FC_DETAIL_IMG_ADD_HIGHT);
            m_addImg->setImg(VAPP_SHELL_FC_IMG_ADD);
            m_addImg->setText(VFX_WSTR_RES(VAPP_SHELL_FC_STR_ADD_IMG), SHELL_FC_DETAIL_ADD_IMG_FONT, 1);
            m_addImg->commit();
        }
        else
        {
            m_addImg->setHidden(VFX_TRUE);
        }
    }
}

VfxBool VappFCImageButton::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            if (m_FCImg->containPoint(event.getRelPos(m_FCImg)))
            {
            #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
            #endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */            	
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
                VfxAutoAnimate::setDuration(300);

                setPos(getPos().x + 3, getPos().y + 3);
                
                VfxAutoAnimate::commit();

                return VFX_TRUE;
            }

            break;
        }
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            
            setPos(getPos().x - 3, getPos().y - 3);
            
            VfxAutoAnimate::commit();
            
            if (m_FCImg->containPoint(event.getRelPos(m_FCImg)))
            {
                m_signalClicked.postEmit(this, 0);

                return VFX_TRUE;
            }
        }
        default:
            break;
    }
    
    return Super::onPenInput(event);
}

void VappFCImageButton::onInit()
{
    Super::onInit();
    VFX_OBJ_CREATE(m_FCImg, VappFCImage, this);
    VFX_OBJ_CREATE(m_addImg, VappFCAddFrame, this);
    // image shadow
    VFX_OBJ_CREATE(m_FCImgShadow, VfxImageFrame, this);   
}

void VappFCImageButton::onDeinit()
{
    Super::onDeinit();
}


/***************************************************************************** 
 * Class VappFCAddFrame
 *****************************************************************************/
void VappFCAddFrame::onInit()
{
    VfxFrame::onInit();

    // create add icon
    VFX_OBJ_CREATE(m_addImage, VfxImageFrame, this);
    m_addImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);

    // create add string
    VFX_OBJ_CREATE(m_addImgStr, VfxTextFrame, this);
    m_addImgStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
}


void VappFCAddFrame::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappFCAddFrame::setImg(VfxS32 resId)
{
    m_addImage->setResId(resId);
}


void VappFCAddFrame::setText(const VfxWString & str, VfxU8 fontSize, VfxU8 line)
{
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(fontSize);
    m_addImgStr->setFont(font);

    if (line > 1)
    {
        m_addImgStr->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
        m_addImgStr->setMaxLines(line);
        m_addImgStr->setLineGap(3);
    }

    m_addImgStr->setString(str);
}


void VappFCAddFrame::commit()
{
    VfxS32 shift;
    
    VfxRect rect = this->getBounds();
    VfxImageSrc img(m_addImage->getResId());

    // set icon bounds
    m_addImage->setAnchor(VfxFPoint(0.0, 0.5));
    m_addImage->setPos(VfxPoint(rect.getMinX() + 2, rect.getMidY()));

    if (img.getSize().height > rect.getHeight())
    {
        m_addImage->setSize(rect.getHeight(), rect.getHeight());
        shift = rect.getHeight() + SHELL_FC_MENU_CELL_NAME_GAP;
    }
    else
    {
        // get label shift
        shift = img.getSize().width + SHELL_FC_MENU_CELL_NAME_GAP;
    }

    m_addImgStr->setAnchor(VfxFPoint(0.0, 0.5));
    m_addImgStr->setPos(VfxPoint(rect.getMinX() + shift, rect.getMidY()));
    
    VfxSize m_sizeText;

    m_sizeText.width = rect.getWidth() - shift;
    m_sizeText.height = rect.getHeight();
    m_addImgStr->setSize(m_sizeText);
}


/***************************************************************************** 
 * Class VappFCImage
 *****************************************************************************/
void VappFCImage::onInit()
{
    Super::onInit();
    setAnchor(0.5f, 0.5f);
    setSize(
        VfxImageSrc(VAPP_SHELL_FC_IMG_CONTACT_BG).getSize().width,
        VfxImageSrc(VAPP_SHELL_FC_IMG_CONTACT_BG).getSize().height);
    
    setImgContent(VfxImageSrc(VAPP_SHELL_FC_IMG_CONTACT_BG));

    VFX_OBJ_CREATE(m_img, VfxImageFrame, this);
    m_img->setAnchor(0.5f, 0.5f);
}


void VappFCImage::onDeinit()
{
    Super::onDeinit();
}


void VappFCImage::setCenterImg(const VfxImageSrc& img)
{
    VfxBool resize = VFX_TRUE;

    if (img.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        m_img->setResId(img.getResId());

        if (img.getResId() == VAPP_SHELL_FC_IMG_DEFAULT)
        {
            resize = VFX_FALSE;
        }
    }
    else if (img.getType() == VFX_IMAGE_SRC_TYPE_PATH)
    {
        if (srv_fmgr_fs_path_exist((WCHAR*)(img.getPath().getBuf())) >= 0)
        {
            m_img->setPath(img.getPath());
        }
        else
        {
            m_img->setResId(VAPP_SHELL_FC_IMG_DEFAULT);
            resize = VFX_FALSE;
        }
    }
    else if (img.isEmpty())
    {
        m_img->setResId(VAPP_SHELL_FC_IMG_DEFAULT);
        resize = VFX_FALSE;
    }
    
    VfxRect rect = getBounds();

    m_img->setPos(rect.size.width/2, rect.size.height/2);

    // resize picture
    if (resize)
    {
        VfxSize size(rect.size.width - 10, rect.size.height - 10);

        // only the picture biger than default need to resize
        if (m_img->getSize().width > size.width || m_img->getSize().height > size.height)
        {
            m_img->setSize(size);
          	m_img->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        }
    }
}


/***************************************************************************** 
 * Class VappShellListDetailProvider

 *****************************************************************************/
void VappShellListDetailProvider::onInit()
{
    VfxObject::onInit();
    
}


void VappShellListDetailProvider::onDeinit()
{
    VfxObject::onDeinit();
}


void VappShellListDetailProvider::setFC(VappShellFC *fc)
{
    m_FC = fc;
}


void VappShellListDetailProvider::getContent(VfxBool sync)
{
    // make contact build data cache
    // only cache number and email address
    m_count = 0;
    
    if (m_FC)
    {
        VfxU8 count;
        count = m_FC->getMobileNumberCount();

        // conact has numbers
        if (m_FC->getNumber())
        {
            mmi_phb_num_type_enum numType;
            VfxU32 numId;
            VfxU8 i = 0, j = 0, k = 0;
            VfxWString itemText = m_FC->getNextNumber(&numType, &numId);

            // get one number
            while (!itemText.isEmpty())
            {
                // if number is mobile number, then build send message action
                if (numType == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    m_action[i].m_action = SHELL_FC_MAKE_CALL;
                    m_action[i].m_infoId = numId;
                    m_action[i++].m_infoType = numType;

                    m_action[count + j].m_action = SHELL_FC_SEND_MSG;
                    m_action[count + j].m_infoId = numId;
                    m_action[count + j++].m_infoType = numType;
                }
                else
                {
                    // always build call action
                    m_action[count * 2 + k].m_action = SHELL_FC_MAKE_CALL;
                    m_action[count * 2 + k].m_infoId = numId;
                    m_action[count * 2 + k++].m_infoType = numType;
                }
                itemText = m_FC->getNextNumber(&numType, &numId);
            }

            m_count = count * 2 + k;
        }
    #ifdef __MMI_EMAIL__        
        count = m_FC->getEmail();

        // contact has email
        if (count)
        {
            mmi_phb_num_type_enum numType;
            VfxU32 numId;
            VfxWString itemText;
            itemText = m_FC->getNextEmail(&numType, &numId);

            // get one email address
            while (!itemText.isEmpty())
            {
                m_action[m_count].m_action = SHELL_FC_SEND_MAIL;
                m_action[m_count].m_infoId = numId;
                m_action[m_count++].m_infoType = numType;

                itemText = m_FC->getNextEmail(&numType, &numId);
            }
        }
    #endif /* __MMI_EMAIL__ */
    }

    if (m_count == 0)
    {
        if (m_info == NULL)
        {
            VFX_OBJ_CREATE(m_info, VfxTextFrame, m_list);
            m_info->setString(VFX_WSTR_RES(VAPP_SHELL_FC_STR_NO_DETAILS));
            m_info->setAnchor(0.5f, 0.5f);
            m_info->setPos(m_list->getBounds().getWidth()/2, m_list->getBounds().getHeight()/2);
        }
    }
    else
    {
        if (m_info)
        {
            VFX_OBJ_CLOSE(m_info);
        }
    }

    reStoreHistory(sync);
}


void VappShellListDetailProvider::setMenu(VcpListMenu *list)
{
    m_list = list;
}


VfxBool VappShellListDetailProvider::swapItem(VfxU32 index1, VfxU32 index2)
{
    // no need to swap item

    return VFX_FALSE;
}


VfxU32 VappShellListDetailProvider::getCount() const
{
    // return dynamic list item counts

    return m_count;
}


VcpListMenuItemStateEnum VappShellListDetailProvider::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappShellListDetailProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        switch (m_action[index].m_action)
        {
            case SHELL_FC_MAKE_CALL:
                image.setResId(VAPP_SHELL_FC_IMG_MAKE_CALL);
                break;
                
            case SHELL_FC_SEND_MSG:
                image.setResId(VAPP_SHELL_FC_IMG_SEND_MSG);
                break;
                
            case SHELL_FC_SEND_MAIL:
                image.setResId(VAPP_SHELL_FC_IMG_SEND_MAIL);
                break;
                
            default:
                VFX_ASSERT(0);
                break;
        }

        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VfxBool VappShellListDetailProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        switch (m_action[index].m_action)
        {
            case SHELL_FC_MAKE_CALL:
                // should append with number type
                if (m_action[index].m_infoType == MMI_PHB_NUM_TYPE_MOBILE)
                {
                    text.loadFromRes(VAPP_SHELL_FC_STR_CALL_MOBILE);
                }
                else if (m_action[index].m_infoType == MMI_PHB_NUM_TYPE_OFFICE)
                {
                    text.loadFromRes(VAPP_SHELL_FC_STR_CALL_OFFIC);
                }
                else if (m_action[index].m_infoType == MMI_PHB_NUM_TYPE_HOME)
                {
                    text.loadFromRes(VAPP_SHELL_FC_STR_CALL_HOME);
                }
                else
                {
                    text.loadFromRes(VAPP_SHELL_FC_STR_CALL_FAX);
                }
                break;
                
            case SHELL_FC_SEND_MSG:
                text.loadFromRes(VAPP_SHELL_FC_STR_SEND_MSG);
                break;
                
            case SHELL_FC_SEND_MAIL:
                text.loadFromRes(VAPP_SHELL_FC_STR_SEND_MAIL);
                break;
                
            default:
                VFX_ASSERT(0);
                break;
        }

        return VFX_TRUE;
    }

    if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text = m_FC->getInfo(m_action[index].m_infoType, m_action[index].m_infoId);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;

        return VFX_TRUE;
    }
    
    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame* VappShellListDetailProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    return NULL;
}


void VappShellListDetailProvider::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
    // use resrcouse id, no need release
}


void VappShellListDetailProvider::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame * cell)
{
    VFX_UNUSED(index);
    VFX_OBJ_CLOSE(cell);
}


void VappShellListDetailProvider::setFCHistory(VfxU16 oldCount, VcpListMenuHistoryStruct *history)
{
    m_oldCount = oldCount;
    m_history = history;
}


void VappShellListDetailProvider::reStoreHistory(VfxBool sync)
{
    if (m_count != 0 && m_count == m_oldCount)
    {
        m_list->setHistory(m_history);
    }
    else
    {
        m_list->reset();
    }

    if (sync)
    {
        m_oldCount = 0;
    }
}

#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__

/*****************************************************************************
 * Class VappMsgListProvider
 *****************************************************************************/
void VappMsgListProvider::onInit()
{
    Super::onInit();

    VFX_OBJ_CREATE(m_msgList, VappMsgList, this);

    srv_um_msg_enum msgType = (srv_um_msg_enum)(SRV_UM_MSG_SMS | SRV_UM_MSG_MMS);
    if (!srv_mode_switch_is_network_service_available())
    {
        msgType = SRV_UM_MSG_SMS;
    }
    
    m_msgList->setMsgBoxInfo(
        msgType,
        (srv_um_msg_box_enum)(SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT));
    
    m_msgList->setSortBy(SRV_UM_LIST_IDX_TIMESTAMP, SRV_UM_SORT_ORDER_UNCLASSIFIED);

    m_msgList->m_signalListUpdated.connect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.connect(this, &Self::onMsgListReleased);
    //m_msgList->m_signalListUpdating.connect(this, &Self::onMsgListUpdating);
    
    VFX_OBJ_CREATE(m_msgHandle, VappMsgDataProvider, this);
    m_msgHandle->m_signalGetMsgInfoFinished.connect(this, &VappMsgListProvider::onGetMsgInfoFinished);
}


void VappMsgListProvider::onDeinit()
{
    Super::onDeinit();
}


void VappMsgListProvider::preDeinit()
{
    m_msgList->m_signalListUpdated.disconnect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.disconnect(this, &Self::onMsgListReleased);
    //m_msgList->m_signalListUpdating.connect(this, &Self::onMsgListUpdating);
    
    m_msgHandle->m_signalGetMsgInfoFinished.disconnect(this, &VappMsgListProvider::onGetMsgInfoFinished);
}


void VappMsgListProvider::onGetMsgInfoFinished(srv_um_get_msg_info_result result)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_GET_FINISHED, result.error);
    
    if (result.error == SRV_UM_RESULT_OK)
    {
        showHelpInfo();
        m_list->updateAllItems();
    }
}


void VappMsgListProvider::onMsgListUpdated()
{
    if (m_FC && m_list)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_UPDATE, m_msgList->getListSize());
        
        showHelpInfo();            
        reStoreHistory(VFX_TRUE);
    }
}

void VappMsgListProvider::onMsgListReleased()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_RELEASED);
    
    // released message list
    refresh();
}


mmi_ret VappMsgListProvider::onUmSrvReadyNotify(mmi_event_struct *param)
{
    VappMsgListProvider *msgProvider =  (VappMsgListProvider *) param->user_data;

    srv_um_notify_ready_evt_struct *evt = (srv_um_notify_ready_evt_struct*) param;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_READY_NOTIFY, evt->msg_type);
    
    if (evt->msg_type == SRV_UM_MSG_SMS || evt->msg_type == SRV_UM_MSG_MMS)
    {
        msgProvider->getContent(VFX_TRUE);
        msgProvider->refresh();
    }
    
    return MMI_RET_OK;
}


mmi_ret VappMsgListProvider::onUmSrvRefreshNotify(mmi_event_struct *param)
{
    VappMsgListProvider *msgProvider =  (VappMsgListProvider *) param->user_data;

    srv_um_notify_refresh_evt_struct *evt = (srv_um_notify_refresh_evt_struct*) param;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_REFRESH_NOTIFY, evt->msg_type, evt->msg_box_type);
    
    if (evt->msg_type == SRV_UM_MSG_SMS || evt->msg_type == SRV_UM_MSG_MMS)
    {
        if ((evt->msg_type & (SRV_UM_MSG_SMS | SRV_UM_MSG_MMS)) && (evt->msg_box_type & (SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_SENT)))
        {
            msgProvider->getContent(VFX_TRUE);
            msgProvider->refresh();
        }
    }
    
    return MMI_RET_OK;
}


void VappMsgListProvider::showHelpInfo()
{
    VFX_ASSERT(m_list);

    if (m_msgList->isUpdating())
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_SHOW_WAITING);
        // show witing icon
        if (m_waitingIcon == NULL)
        {
            VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, m_list);
            
            VfxRect rect = m_list->getBounds();

            m_waitingIcon->setAnchor(0.5f, 0.5f);
            m_waitingIcon->setPos(rect.getWidth()/2, rect.getHeight()/2);
            m_waitingIcon->setHiddenWhenStopped(VFX_TRUE);

            m_waitingIcon->start();
        }
        // close help info
        if (m_info)
        {
            VFX_OBJ_CLOSE(m_info);
        }
    }
    else
    {
        VfxU32 count = 0;

        count = (m_msgList->getListSize() > SHELL_FC_MSG_COUNT) ? SHELL_FC_MSG_COUNT : m_msgList->getListSize();
        VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_SHOW_INFO, count);
        
        if (count == 0)
        {
            if (m_info == NULL)
            {
                VFX_OBJ_CREATE(m_info, VfxTextFrame, m_list);
                m_info->setString(VFX_WSTR_RES(VAPP_SHELL_FC_STR_NO_MSGS));
                m_info->setAnchor(0.5f, 0.5f);
                m_info->setPos(m_list->getBounds().getWidth()/2, m_list->getBounds().getHeight()/2);
            }
        }
        else
        {
            if (m_info)
            {
                VFX_OBJ_CLOSE(m_info);
            }
        }

        // close waiting icon
        if (m_waitingIcon)
        {
            VFX_OBJ_CLOSE(m_waitingIcon);
        }
    }

}


void VappMsgListProvider::refresh()
{
    VFX_ASSERT(m_list);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MSG_REFRSH, m_sync);

    // in exit view state
    if (m_FC == NULL)
    {
        return;
    }
    
    // use the old data
    if (!m_sync)
    {
        return;
    }

    // get the newest data
    if (m_msgList->isOutOfDate())
    {
        m_msgList->update();
        m_list->reset();
    }

    showHelpInfo();
}


void VappMsgListProvider::setFC(VappShellFC* fc)
{
    m_FC = fc;
}


void VappMsgListProvider::getContent(VfxBool sync)
{
    VFX_ASSERT(m_list);

    // should get the newest data
    m_sync = sync;
    
    // should only be called one time
    if (m_FC)
    {
        if (sync)
        {
            // conact has numbers
            if (m_FC->getNumber())
            {
                mmi_phb_num_type_enum numType;
                VfxU32 numId;
                VfxWString itemText = m_FC->getNextNumber(&numType, &numId);

                // get one number
                while (!itemText.isEmpty())
                {
                #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
                    m_msgList->setThreadIDbyAddress(SRV_UM_ADDR_PHONE_NUMBER, itemText);
                #endif
                    // only need to set one contact's number
                    //itemText = m_FC->getNextNumber(&numType, &numId);
                    break;
                }

                m_msgList->update();
            }
            else
            {
                m_msgList->release(VFX_TRUE);
            }
        }
        else
        {
            // use temp buffer
        }
    }
}


VfxU32 VappMsgListProvider::getMsgId(VfxS32 index)
{
    return m_msgList->getMsgList()[index].msg_id;
}


srv_um_msg_enum VappMsgListProvider::getMsgType(VfxS32 index)
{
    return m_msgList->getMsgList()[index].msg_type;
}


void VappMsgListProvider::setMenu(VcpListMenu *list)
{
    m_list = list;
}


VfxBool VappMsgListProvider::swapItem(VfxU32 index1, VfxU32 index2)
{
    // no need to swap item

    return VFX_FALSE;
}


VfxU32 VappMsgListProvider::getCount() const
{
    VfxU32 count = 0;
    // return dynamic list item counts
    if (m_FC && !m_msgList->isUpdating())
    {
        count = (m_msgList->getListSize() > SHELL_FC_MSG_COUNT) ? SHELL_FC_MSG_COUNT : m_msgList->getListSize();
    }
    
    return count;
}


VcpListMenuItemStateEnum VappMsgListProvider::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappMsgListProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{
    if (m_msgList && m_msgList->getListSize() > (VfxS32)index)
    {
        srv_um_msg_box_enum box = SRV_UM_MSG_BOX_NONE;
        
        switch ((m_msgList->getMsgList()[index].msg_type))
        {
            case SRV_UM_MSG_SMS:
                box = mmi_sms_query_um_msg_box((m_msgList->getMsgList()[index].msg_id));
                break;
            case SRV_UM_MSG_MMS:
            #ifdef __MMI_MMS_2__
                box = (srv_um_msg_box_enum) mmi_umms_app_if_get_um_box_type_from_msg_id((m_msgList->getMsgList()[index].msg_id));
            #endif                
                break;
            default:
                break;
        }
        if (SRV_UM_MSG_BOX_INBOX == box)
        {
            image.setResId(VAPP_SHELL_FC_IMG_REC_MSG);
        }
        else if (SRV_UM_MSG_BOX_SENT == box)
        {
            image.setResId(VAPP_SHELL_FC_IMG_SEND_MSG);
        }
        else
        {
            return VFX_FALSE;
        }

        return VFX_TRUE;
    }
    return VFX_FALSE;
}


VfxBool VappMsgListProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    
    /* not exist in cache */
    if (m_msgHandle->getMsgInfo(m_msgList->getMsgList(), m_msgList->getListSize(), index, 1, &m_msgInfo) != SRV_UM_RESULT_OK)
    {
        return VFX_FALSE;
    }

    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        text.loadFromMem(m_msgInfo->address);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        break;

    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        text.loadFromMem(m_msgInfo->subject);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        break;

    case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        timestamp2String(text, m_msgInfo->timestamp, VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        break;

    case VCP_LIST_MENU_FIELD_SUB_TEXT3:
        timestamp2String(text, m_msgInfo->timestamp, VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        break;
    default:
        return VFX_FALSE;

    }

    return VFX_TRUE;
}


VcpListMenuCellClientBaseFrame* VappMsgListProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    return NULL;
}


void VappMsgListProvider::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
    // use resrcouse id, no need release
}


void VappMsgListProvider::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame * cell)
{
    VFX_UNUSED(index);
    VFX_OBJ_CLOSE(cell);
}


void VappMsgListProvider::setFCHistory(VfxU16 oldCount, VcpListMenuHistoryStruct *history)
{
    m_oldCount = oldCount;
    m_history = history;
}


void VappMsgListProvider::reStoreHistory(VfxBool sync)
{
    if (m_msgList->getListSize() != 0 && m_msgList->getListSize() == m_oldCount)
    {
        m_list->setHistory(m_history);
        m_list->updateLayout();
    }
    else
    {
        m_list->reset();
    }

    if (sync)
    {
        m_oldCount = 0;
    }
}

#endif
/***************************************************************************** 
 * Class VappShellListDetailProvider

 *****************************************************************************/
VfxU32 VappShellListCHProvider::m_logs[SHELL_FC_CALL_COUNT];
VfxU8 VappShellListCHProvider::m_index;


void VappShellListCHProvider::onInit()
{
    VfxObject::onInit();
}


void VappShellListCHProvider::onDeinit()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_ONDEINIT, m_hdlr);
    
    if (m_hdlr != 0)
    {
        srv_clog_destroy(m_hdlr);
    }
    
    VfxObject::onDeinit();
}


void VappShellListCHProvider::setFC(VappShellFC *fc)
{
    m_FC = fc;
}


void VappShellListCHProvider::setViewed(VfxBool viewed)
{
    m_viewed = viewed;
}


VfxBool VappShellListCHProvider::hasViewed()
{
    return m_viewed;
}


void VappShellListCHProvider::getClogDone()
{    
    m_count = VappShellListCHProvider::m_index;
    m_list->reset();

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_GET_DONE, m_hdlr, m_count);    

    // reset hdlr
    srv_clog_destroy(m_hdlr);
    m_hdlr = 0;
    
    showHelpInfo();
}


VfxS32 VappShellListCHProvider::getClogCb(
                                    SRV_CLOG_HANDLE handle,
                                    VfxS32 pid, 
                                    void *req_data,
                                    void *cnf_data, 
                                    MMI_BOOL more,
                                    srv_clog_ret_enum ret)
{
    srv_clog_search_list_log_ids_cnf_struct *cnf = (srv_clog_search_list_log_ids_cnf_struct *) cnf_data;

    if (ret == SRV_CLOG_RET_OK)
    {
        for (VfxU8 index = 0; index < cnf->id_num && VappShellListCHProvider::m_index < SHELL_FC_CALL_COUNT; index ++)
        {
            VappShellListCHProvider::m_logs[VappShellListCHProvider::m_index++] = cnf->log_ids[index];
        }
    }
    else
    {
        VappShellListCHProvider *provider = (VappShellListCHProvider *)srv_clog_get_user_data(handle);
        VappShellListCHProvider::m_index = 0;
        provider->getClogDone();

        return SRV_CLOG_RET_STOP;
    }
    
    if (more && VappShellListCHProvider::m_index < SHELL_FC_CALL_COUNT)
    {
        srv_clog_search_list_log_ids_req_struct *req = (srv_clog_search_list_log_ids_req_struct*)req_data;
        req->start_elm = cnf->next_elm;
            
        srv_clog_search_list_log_ids(
            handle,
            pid,
            req,
            VappShellListCHProvider::getClogCb);
    }
    else
    {
        VappShellListCHProvider *provider = (VappShellListCHProvider *)srv_clog_get_user_data(handle);
        provider->getClogDone();
    }

    return SRV_CLOG_RET_OK;
}


void VappShellListCHProvider::createCLogInstance(SRV_CLOG_HANDLE &hdlr) const
{
#ifdef __MMI_DUAL_SIM__
    VfxU32 sim_id = MMI_SIM1 | MMI_SIM2;
#else
	VfxU32 sim_id = MMI_SIM1;
#endif
    srv_clog_create_struct create;

    create.identity.cate = SRV_CLOG_CATE_CALL;
    create.identity.sim_id = sim_id;
    create.identity.log_type = SRV_CLOG_CLT_ALL;
    create.identity.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;
    create.user_data = (void*)this;

    hdlr = srv_clog_create((const srv_clog_create_struct *)&create);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_CREATE_HDLR, hdlr);
}


void VappShellListCHProvider::getContent(VfxBool sync)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_GET_CONTENT, sync);
    
    // make contact build data cache
    // only cache number and email address
    if (m_FC && m_FC->hasNumber())
    {
        if (sync)
        {
            m_count = 0;
            VappShellListCHProvider::m_index = 0;
            
            // init cache ids
            memset(VappShellListCHProvider::m_logs, 0xffffffff, SHELL_FC_CALL_COUNT);
            VappShellListCHProvider::m_index = 0;

            // init get clog handler
            if (m_hdlr != 0)
            {
                srv_clog_destroy(m_hdlr);
            }
            
        	createCLogInstance(m_hdlr);
            
            srv_clog_search_list_log_ids_req_struct req;
            srv_clog_init_para(SRV_CLOG_PARA_SEARCH_LIST_LOG_IDS_REQ, &req);

        /*  // see hdlr info
            req.cate = SRV_CLOG_CATE_CALL;
            req.sim_id = MMI_SIM1 | MMI_SIM2;
            req.log_type = SRV_CLOG_CLT_ALL;
            req.sub_type = SRV_CLOG_CALL_TYPE_NON_VOIP;
        */
            req.start_by = SRV_CLOG_BY_ID;
            req.search_fields = SRV_CLOG_LOG_FIELD_PHB_IDXS;
            req.start_elm = 0;
            req.phb_idx_num = 1;
            req.phb_idx[0] = m_FC->getStoreIndex();
                
            srv_clog_search_list_log_ids(
                m_hdlr,
                0,
                &req,
                VappShellListCHProvider::getClogCb);
        }
        else
        {
            // use temp buffer
        }
    }
    else
    {
        m_count = 0;
        // show no clogs info
        showHelpInfo();        
    }

}


void VappShellListCHProvider::showHelpInfo()
{
    if (m_count == 0)
    {
        if (m_info == NULL)
        {
            VFX_OBJ_CREATE(m_info, VfxTextFrame, m_list);
            m_info->setString(VFX_WSTR_RES(VAPP_SHELL_FC_STR_NO_CLOGS));
            m_info->setAnchor(0.5f, 0.5f);
            m_info->setPos(m_list->getBounds().getWidth()/2, m_list->getBounds().getHeight()/2);
        }
    }
    else
    {
        if (m_info)
        {
            VFX_OBJ_CLOSE(m_info);
        }
    }
}


void VappShellListCHProvider::refresh()
{
    getContent(VFX_TRUE);
}


void VappShellListCHProvider::clearMissedNum()
{
    if (!hasViewed())
    {
        return;
    }

    setViewed(VFX_FALSE);
    
    if (srv_clog_get_unread_missed_call_num() == 0)
    {
        return;
    }

    srv_clog_log_struct log;
    srv_clog_update_log_req_struct req;
    
    VfxS32 result;

    for (VfxU16 i = 0; i < VappShellListCHProvider::m_index; i ++)
    {
        result = srv_clog_get_log_by_id(
                    0,
                    VappShellListCHProvider::m_logs[i],
                    SRV_CLOG_LOG_FIELD_UNREAD_NUM,
                    &log);

        if (result != SRV_CLOG_RET_OK)
        {
            break;
        }

        if (log.data.call_log.unread_num > 0)
        {
            srv_clog_init_para(SRV_CLOG_PARA_UPDATE_LOG_REQ, &req);

            req.log_data.cate = SRV_CLOG_CATE_CALL;
            req.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
            req.log_data.data.call_log.log_id = log.data.call_log.log_id;
            req.log_data.data.call_log.unread_num = 0;

            srv_clog_update_log(
                0,
                0,
                &req,
                NULL);
         }
    }
}


void VappShellListCHProvider::setMenu(VcpListMenu *list)
{
    m_list = list;
}


VfxBool VappShellListCHProvider::swapItem(VfxU32 index1, VfxU32 index2)
{
    // no need to swap item

    return VFX_FALSE;
}


VfxU32 VappShellListCHProvider::getCount() const
{
    // return dynamic list item counts

    return m_count;
}


VcpListMenuItemStateEnum VappShellListCHProvider::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


VfxBool VappShellListCHProvider::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc & image)
{
    if (index >= m_count)
    {
        return VFX_FALSE;
    }

    // init get clog handler
    SRV_CLOG_HANDLE hdlr;
	createCLogInstance(hdlr);
    
    srv_clog_log_struct log;
    // VfxS32 result;
    
    srv_clog_get_log_by_id(
        hdlr,
        VappShellListCHProvider::m_logs[index],
        SRV_CLOG_LOG_FIELD_DEFAULT,
        &log);

    srv_clog_destroy(hdlr);

    VappShellRCInfo info;
    info.cate = log.data.call_log.cate;
    info.log_type = log.data.call_log.log_type;
    info.sim_id = log.data.call_log.sim_id;
    info.sub_type = log.data.call_log.sub_type;
        
    VappShellRCDataProvider::getLogIcon(info, image);
    
    return VFX_TRUE;
}


VfxBool VappShellListCHProvider::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

    if (index >= m_count)
    {
        return VFX_FALSE;
    }

    // init get clog handler
    SRV_CLOG_HANDLE hdlr;
	createCLogInstance(hdlr);

    srv_clog_log_struct log;
    VfxS32 result;
    
    result = srv_clog_get_log_by_id(
                hdlr,
                VappShellListCHProvider::m_logs[index],
                SRV_CLOG_LOG_FIELD_DEFAULT,
                &log);

    srv_clog_destroy(hdlr);

    if (result == SRV_CLOG_RET_OK)
    {
        switch(fieldType)
        {
            case VCP_LIST_MENU_FIELD_TEXT:
                text.loadFromMem(log.data.call_log.cid);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                break;
                
        	case VCP_LIST_MENU_FIELD_TAIL_TEXT:
        	{
        	    if (log.data.call_log.unread_num > 1)
                    {
                        text.format("(%d)", log.data.call_log.unread_num);
                    }
        	    else
        	    {
        		text.setNull();
        	    }
        	    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                    break;
        	}
            
            case VCP_LIST_MENU_FIELD_SUB_TEXT1:
            {
                switch (log.data.call_log.log_type)
                {
                    case SRV_CLOG_CLT_DIALED:
                        if (log.data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX] > 0)
                        {
                            VfxWString duration;
                            durationToString(log.data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX], duration);

                            text.loadFromRes(VAPP_SHELL_FC_STR_DURATION);

                            text += duration;
                        }
                        else
                        {
                            text.loadFromRes(VAPP_SHELL_FC_STR_NO_ANSWER);
                        }
                        break;
                        
                    case SRV_CLOG_CLT_RECVED:
                    {
                        VfxWString duration;
                        durationToString(log.data.call_log.duration[SRV_CLOG_LASTEST_TIME_IDX], duration);

                        text.loadFromRes(VAPP_SHELL_FC_STR_DURATION);

                        text += duration;
                        break;
                    }
                    case SRV_CLOG_CLT_REJED:
                        text.loadFromRes(VAPP_SHELL_FC_STR_REJECTED);
                        break;
                        
                    case SRV_CLOG_CLT_MISSED:
                        text.loadFromRes(VAPP_SHELL_FC_STR_MISSED);
                        break;
                    default:
                        text.setNull();
                        break;
                }
                color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                break;
            }
            case VCP_LIST_MENU_FIELD_SUB_TEXT2:
                timestamp2String(text, log.data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX], VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY);
                color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                break;

            case VCP_LIST_MENU_FIELD_SUB_TEXT3:
                timestamp2String(text, log.data.call_log.timestamp[SRV_CLOG_LASTEST_TIME_IDX], VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
                color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
                break;
            default:
                return VFX_FALSE;
        }
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame* VappShellListCHProvider::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    return NULL;
}


void VappShellListCHProvider::closeItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc Image)
{
    //VFX_ASSERT(0);
}


void VappShellListCHProvider::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame * cell)
{
    //VFX_ASSERT(0);
}


mmi_ret VappShellListCHProvider::onClogChangeNotify(mmi_event_struct *param)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_CHANGE_NOTIFY, param->evt_id);
    
    VappShellListCHProvider *msgProvider =  (VappShellListCHProvider *) param->user_data;
    msgProvider->refresh();

    return MMI_RET_OK;
}


void VappShellListCHProvider::onCommandClick(VfxObject * obj, VfxId id)
{
    VFX_UNUSED(obj);
    VfxWString number(m_number);
    
    if (id == SHELL_FC_MAKE_CALL)
    {
        ContactUISrv::makeCall(m_FC->getStoreIndex(), number, m_numId);
    }
    else if (id == SHELL_FC_SEND_MSG)
    {
        ContactUISrv::sendMsg(m_FC->getStoreIndex(), number, m_numId);
    }
}


void VappShellListCHProvider::onTapItem(VfxU32 index)
{
    // init get clog handler
    SRV_CLOG_HANDLE hdlr;
    
	createCLogInstance(hdlr);

    srv_clog_log_struct log;
    VfxS32 result;
    
    result = srv_clog_get_log_by_id(
                hdlr,
                VappShellListCHProvider::m_logs[index],
                SRV_CLOG_LOG_FIELD_DEFAULT,
                &log);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_CLOG_TAP_ITEM, index, hdlr, result);

    srv_clog_destroy(hdlr);

    if (result == SRV_CLOG_RET_OK)
    {
        VcpCommandPopup* menu;
        VFX_OBJ_CREATE(menu, VcpCommandPopup, m_list->findScreen());

        m_numId = log.data.call_log.phb_id.number_index;
        m_number = VFX_WSTR_MEM(log.data.call_log.cid);
        
        menu->setText(m_number);
        
        menu->addItem(SHELL_FC_MAKE_CALL, VFX_WSTR_RES(VAPP_SHELL_FC_STR_MAKE_CALL), VCP_POPUP_BUTTON_TYPE_NORMAL);
        menu->addItem(SHELL_FC_SEND_MSG, VFX_WSTR_RES(VAPP_SHELL_FC_STR_SEND_MSG), VCP_POPUP_BUTTON_TYPE_NORMAL);
        menu->addItem(0xFFFF, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
        
        menu->m_signalButtonClicked.connect(this, &VappShellListCHProvider::onCommandClick);

        menu->show(VFX_TRUE);
    }
}


/***************************************************************************** 
 * Class ContactUISrv

 *****************************************************************************/
mmi_ret ContactUISrv::proc(mmi_event_struct *evt)
{
#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MSG_VIEWER_CLOSE:
        {
            cui_msg_viewer_close(((cui_msg_viewer_event_struct*)evt)->sender_id);
            break;
        }
        default:
            break;
    }
#endif
    return MMI_RET_OK;
}


void ContactUISrv::makeCallCb(mmi_ucm_after_make_call_cb_struct* make_call_cb_para)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MAKE_CALL_CB);
    
    srv_phb_destory_cm_user_data(make_call_cb_para->user_data);
}


void ContactUISrv::makeCall(VfxU16 storeIndex, const VfxWString number, VfxU32 numberType)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_MAKE_CALL, storeIndex, numberType);
    
    mmi_ucm_make_call_para_struct make_call_para; 
    void *cm_user_data;

    mmi_ucm_init_call_para(&make_call_para);

    cm_user_data = srv_phb_create_cm_user_data(NULL, numberType, storeIndex);

    /* choose right call type to make call: MAUI_02058877, MAUI_02055879 */

    make_call_para.dial_type = (srv_ucm_call_type_enum)(make_call_para.dial_type & (~SRV_UCM_VOIP_CALL_TYPE));
    
    make_call_para.adv_para.after_callback_user_data = cm_user_data;
    make_call_para.adv_para.phb_data = cm_user_data;    
    make_call_para.adv_para.after_make_call_callback = ContactUISrv::makeCallCb;
    make_call_para.ucs2_num_uri = (U16*)number.getBuf();
    
    mmi_ucm_call_launch(0, &make_call_para);
    
}


void ContactUISrv::sendMsg(VfxU16 storeIndex, VfxWString &to, VfxU32 addrType)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_SEND_MSG);
    
#ifdef __MMI_UNIFIED_COMPOSER__
    mmi_uc_entry_write_struct data;
    mmi_uc_addr_struct addr;

    if (IsMessagesReEntering())
    {
        mmi_popup_display_simple(
            (UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);

        return;
    }

    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
    memset(&addr, 0x00, sizeof(mmi_uc_addr_struct));
    data.addr_num = 1;
    addr.addr = (kal_uint8*) to.getBuf();
    
    if (mmi_ucs2chr((const CHAR*)to.getBuf(), L'@') == NULL)
    {
        addr.type = MMI_UC_ADDRESS_TYPE_PHONE_NUMBER;
    }
    else
    {
        addr.type = MMI_UC_ADDRESS_TYPE_EMAIL;
    }

    addr.group = MMI_UC_ADDRESS_GROUP_TYPE_TO;
    data.addr = &addr;
    data.msg_type = MMI_UC_MSG_TYPE_DEFAULT;
    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
#else
    if (!mmi_sms_is_reenter_message())
    {        
        CHAR ascii_number[MMI_PHB_NUMBER_LENGTH + 1 + 1];
        mmi_sms_write_msg_para_struct sendData;
        
        memset(ascii_number, 0, sizeof(ascii_number));
        memset(&sendData, 0, sizeof(mmi_sms_write_msg_para_struct));

        mmi_ucs2_n_to_asc((CHAR*)ascii_number, (CHAR*)to.getBuf(), MMI_PHB_NUMBER_LENGTH + 1);
        sendData.string = NULL;
        sendData.stringlength = 0;
        sendData.dcs = 0;
        sendData.flag = MMI_SMS_ENTRY_WRITE_REPLY;
        sendData.ascii_addr = (U8*) ascii_number;

        mmi_sms_write_msg_lanch(0, &sendData);    
    }
#endif    
}


void ContactUISrv::sendEmail(VfxU16 storeIndex, VfxWString &addr, VfxU32 addrType)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_SEND_EMAIL);
    
#ifdef __MMI_EMAIL__
    VfxU16 name[MMI_PHB_NAME_LENGTH + 1];
    srv_phb_get_name(storeIndex, name, MMI_PHB_NAME_LENGTH);

    mmi_email_app_send_to_ext((const CHAR*) addr.getBuf(), (const CHAR *) name);
#endif    
}

#ifdef __MMI_VUI_SHELL_FAV_CONTACT_MSG__
void ContactUISrv::viewMsg(VfxU32 msgId, srv_um_msg_enum msgType)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_FC_VIEW_MSG, msgId, msgType);
    
    MMI_ID parentId, childId;
    parentId = mmi_frm_group_create(
                    GRP_ID_ROOT,
                    GRP_ID_AUTO_GEN,
                    ContactUISrv::proc,
                    NULL);
    mmi_frm_group_enter(parentId, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    childId = cui_msg_viewer_create(parentId, (U32) msgId, msgType, 0);
    //cui_msg_viewer_set_style(childId, CUI_MSG_VIEWER_TYPE_NORMAL);
    cui_msg_viewer_run(childId);
}
#endif
#endif
