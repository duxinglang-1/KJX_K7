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
 *  FileMgrSrvStorage.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File manager service - Storage
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvProt.h"

#include "mmi_rp_srv_filemanager_def.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBSrvGprot.h"             // for USB check
#endif
#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"     /* for USB_HOST_MS_SUPPORT_LUN */
#endif 

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"

#include "FileMgrSrvGProt.h"
#include "FileMgrSrvIProt.h"

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Typedef
*****************************************************************************/

enum {
    SRV_FMGRI_DRV_STATE_INIT,
    SRV_FMGRI_DRV_STATE_NOT_MOUNTED,
    SRV_FMGRI_DRV_STATE_MOUNTED
};

typedef struct 
{
    U8          drv_count;                          /* count of existed drive (not mounted) */
    U8          drv_mount_state[SRV_FMGR_DRV_TOTAL];/* 2 for mounted, 
                                                     * 1 for not mounted, 
                                                     * 0 for unknown */
    WCHAR       drv_list[SRV_FMGR_DRV_TOTAL][4];    /* X:\ in ascii format */
} srv_fmgr_storage_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/
const static WCHAR g_srv_fmgr_volume_label_invalid_chars[] = L"/\\:*?\"<>|+,.;=[]\n\r\xFFFF";

const static mmi_str_id g_srv_fmgr_drive_string_table[SRV_FMGR_DRV_TOTAL] = 
{
    STR_GLOBAL_PHONE,       /* SRV_FMGR_DRV_PHONE_TYPE */
    STR_GLOBAL_PHONE,       /* SRV_FMGR_DRV_PHONE_2_TYPE */

    STR_GLOBAL_MEMORY_CARD, /* SRV_FMGR_DRV_CARD_TYPE */

#if defined (__FS_CARD2_SUPPORT__)
    STR_ID_FMGR_MEMORY_CARD2, /* SRV_FMGR_DRV_CARD_2_TYPE */
#else
    0,
#endif

#ifdef __OTG_ENABLE__    
    STR_FMGR_USB_STORAGE,   /* SRV_FMGR_DRV_OTG_TYPE */
    STR_FMGR_USB_STORAGE2,  /* SRV_FMGR_DRV_OTG_2_TYPE */
    STR_FMGR_USB_STORAGE3,  /* SRV_FMGR_DRV_OTG_3_TYPE */
    STR_FMGR_USB_STORAGE4,  /* SRV_FMGR_DRV_OTG_4_TYPE */
    STR_FMGR_USB_STORAGE5,  /* SRV_FMGR_DRV_OTG_5_TYPE */
    STR_FMGR_USB_STORAGE6,  /* SRV_FMGR_DRV_OTG_6_TYPE */
    STR_FMGR_USB_STORAGE7,  /* SRV_FMGR_DRV_OTG_7_TYPE */
    STR_FMGR_USB_STORAGE8,  /* SRV_FMGR_DRV_OTG_8_TYPE */
#else
    0, 0, 0, 0, 0, 0, 0, 0, 
#endif

#ifdef __SIM_PLUS__    
    STR_FMGR_SIM_PLUS,      /* SRV_FMGR_DRV_SIMPLUS_TYPE */
    STR_FMGR_SIM_PLUS2,     /* SRV_FMGR_DRV_SIMPLUS_2_TYPE */
    STR_FMGR_SIM_PLUS3,     /* SRV_FMGR_DRV_SIMPLUS_2_TYPE */
    STR_FMGR_SIM_PLUS4,     /* SRV_FMGR_DRV_SIMPLUS_2_TYPE */
#else
    0, 0, 0, 0,
#endif
};

static srv_fmgr_storage_context_struct g_srv_fmgr_storage_ctxt;
    
/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
static S32 srv_fmgri_drv_get_volume_name(U8 drv_letter, U16* name_buffer, S32 name_buf_size);
static MMI_BOOL srv_fmgri_drv_type_is_removable(srv_fmgr_drv_type_enum drv_type);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

#define SET_DRIVE(drv_letter, type) \
    do { \
        drive = drv_letter; \
        if(drive > 0) g_srv_fmgr_storage_ctxt.drv_list[(type)][0] = drive; \
    } while(0)

void srv_fmgr_drv_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_fmgr_storage_ctxt, 0, sizeof(g_srv_fmgr_storage_ctxt));

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode() && !srv_usb_is_leaving_ms_mode())
    {
//        FMGR_TRACE1(TRC_MMI_FMGR_36B00D34D6154EE4BBD0101210DB64C1,   
//            "[MMIFMGR] > FSData > srv_fmgr_drv_init > count=%d\n", -1);
        FMGR_TRACE1(TGL1, TRC_SRV_FMGR_F52F81E176D44FADB09AC476E39FB6AC, "[SRV_FMGR] > Drv > Init: %d", -1);
        return;
    }
#endif 

    /* Phone Drive -- NOR */
    SET_DRIVE(FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_PHONE_TYPE);
    /* Phone Drive -- NAND */
    SET_DRIVE(FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_PHONE_2_TYPE);

#if defined (__FS_CARD_SUPPORT__)
    /* Card Drive -- Card */
    SET_DRIVE(FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_CARD_TYPE);
#endif

#if defined (__FS_CARD2_SUPPORT__)
    /* Card Drive -- Card 2 */
    SET_DRIVE(FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_CARD_2_TYPE);
#endif

#ifdef __OTG_ENABLE__
    i = USB_HOST_MS_SUPPORT_LUN;
    if(i > 8) i = 8;    /* only 8 macro */
    i --;
    for (; i >= 0 ; i--)
        SET_DRIVE(FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_OTG_TYPE + i);
#endif

#ifdef __SIM_PLUS__
    for (i=0; i<4; i++)
        SET_DRIVE(FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE), SRV_FMGR_DRV_SIMPLUS_TYPE + i);
#endif

    for (i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        if(g_srv_fmgr_storage_ctxt.drv_list[i])
        {
            g_srv_fmgr_storage_ctxt.drv_count++;
            g_srv_fmgr_storage_ctxt.drv_list[i][1] = ':';
            g_srv_fmgr_storage_ctxt.drv_list[i][2] = '\\';
        }
    }

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_F52F81E176D44FADB09AC476E39FB6AC, "[SRV_FMGR] > Drv > Init: %d", g_srv_fmgr_storage_ctxt.drv_count);
    srv_fmgr_drivelist_destroy(srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL));
}

S32 srv_fmgr_drv_get_name(U8 drv_letter, WCHAR* name_buf, S32 name_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S32 drv_type;
    mmi_str_id              str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(drv_letter);
    if(drv_type < 0)
        return FS_DRIVE_NOT_FOUND;

    switch(drv_type)
    {
    case SRV_FMGR_DRV_CARD_TYPE:
#if defined (__FS_CARD2_SUPPORT__)
    case SRV_FMGR_DRV_CARD_2_TYPE:
#endif        
        len = srv_fmgri_drv_get_volume_name(drv_letter, name_buf, name_buf_size);
        if(len >= 0)
            return len;
        break;
    }

    str_id = srv_fmgr_drv_get_string(drv_letter);
    len = mmi_wcslen((WCHAR*)get_string(str_id));
    
    if(!name_buf)
        return len;
    
    if((len + 1)*ENCODING_LENGTH > name_buf_size)
        return FS_STRING_BUFFER_TOO_SMALL;

    mmi_wcsncpy(name_buf, (WCHAR*)get_string(str_id), len);
    return 0;
}

mmi_str_id srv_fmgr_drv_get_string(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(drv_letter);
    if(drv_type < 0)
        return 0;

    return g_srv_fmgr_drive_string_table[drv_type];
}

S32 srv_fmgr_drv_get_type(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(drv_letter >= 'a' && drv_letter <= 'z')
        drv_letter -= ('a' - 'A');

    if(drv_letter < 'A' || drv_letter > 'Z')
        return -1;
    
    for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        if(g_srv_fmgr_storage_ctxt.drv_list[i][0] && g_srv_fmgr_storage_ctxt.drv_list[i][0] == drv_letter)
        {
            return i;
        }
    }
    return -1;
}

const WCHAR* srv_fmgr_drv_get_invalid_chars(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_fmgr_volume_label_invalid_chars;
}

S32 srv_fmgr_drv_get_size(U8 drv_letter, U64* total_size, U64* free_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR path[4];
    FS_DiskInfo disk_info;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!total_size && !free_size)
        return FS_PARAM_ERROR;

    path[0] = drv_letter;
    path[1] = ':';
    path[2] = '\\';
    path[3] = 0;

    fs_ret = FS_GetDiskInfo(path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if(fs_ret < 0)
    {
        if(total_size)
            *total_size = 0;
        if(free_size)
            *free_size = 0;
    }
    else
    {
        if(total_size)
            *total_size = (U64)disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if(free_size)
            *free_size = (U64)disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }
    
    return fs_ret;
}

S32 srv_fmgr_drv_check_free_size(U8 drv_letter, U64 size_required)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    U64 free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = srv_fmgr_drv_get_size(drv_letter, NULL, &free_space);
    if(fs_ret < 0)
        return fs_ret;
    return size_required <= free_space ? 0 : FS_DISK_FULL;
}

MMI_BOOL srv_fmgr_drv_is_accessible(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(drv_letter);
    if(drv_type < 0)
        return MMI_FALSE;

    if(g_srv_fmgr_storage_ctxt.drv_mount_state[drv_type] == SRV_FMGRI_DRV_STATE_INIT)
    {
        if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR 
#if defined(__MTK_TARGET__)
            && FS_GetDevStatus(drv_letter, FS_EXPORT_STATE_ENUM) == FS_NO_ERROR
#endif
            )
        {
            g_srv_fmgr_storage_ctxt.drv_mount_state[drv_type] = SRV_FMGRI_DRV_STATE_MOUNTED;
        }
        else
        {
            g_srv_fmgr_storage_ctxt.drv_mount_state[drv_type] = SRV_FMGRI_DRV_STATE_NOT_MOUNTED;
        }
    }

    if(g_srv_fmgr_storage_ctxt.drv_mount_state[drv_type] == SRV_FMGRI_DRV_STATE_MOUNTED)
        return MMI_TRUE;
    else
        return MMI_FALSE;    
}

MMI_BOOL srv_fmgr_drv_is_busy(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_GetDevStatus(drv_letter, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
        return MMI_TRUE;
    else
        return MMI_FALSE;    
}

MMI_BOOL srv_fmgr_drv_is_valid(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(drv_letter);
    if(drv_type < 0)
        return MMI_FALSE;

    return MMI_TRUE;
}

MMI_BOOL srv_fmgr_drv_is_removable(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(drv_letter);
    if(drv_type < 0)
        return MMI_FALSE;

    return srv_fmgri_drv_type_is_removable((srv_fmgr_drv_type_enum)drv_type);
}

MMI_BOOL srv_fmgr_drv_has_accessible_removable_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        if(g_srv_fmgr_storage_ctxt.drv_list[i][0] &&
           srv_fmgri_drv_type_is_removable((srv_fmgr_drv_type_enum)i) &&
           srv_fmgr_drv_is_accessible((U8)g_srv_fmgr_storage_ctxt.drv_list[i][0]))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

U8 srv_fmgr_drv_get_letter_by_type(srv_fmgr_drv_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type >= SRV_FMGR_DRV_TOTAL)
        return 0;

    return (U8)g_srv_fmgr_storage_ctxt.drv_list[type][0];
}

const WCHAR* srv_fmgr_drv_get_path_by_type(srv_fmgr_drv_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type >= SRV_FMGR_DRV_TOTAL)
        return NULL;

    return g_srv_fmgr_storage_ctxt.drv_list[type];
}

SRV_FMGR_DRVLIST_HANDLE srv_fmgr_drivelist_create(srv_fmgr_drivelist_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 drv_mask;
    S32 i;
    U8  drv_letter;
    U8  enable_2nd_card;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_ASSERT(SRV_FMGR_DRV_TOTAL <= 31);  /* we use U32 as bitmask to store data */

#if defined (__FS_CARD2_SUPPORT__)
    enable_2nd_card = (type & SRV_FMGR_DRIVELIST_ITYPE_FLAG_2ND_CARD) ? 1 : 0;
#else
    enable_2nd_card = 0;
#endif
    type &= SRV_FMGR_DRIVELIST_ITYPE_FLAG_MASK;

    drv_mask = 0x80000000;  /* make sure it is not zero when there is no drive */
    for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        drv_letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)i);
        if(!drv_letter)
            continue;
            
        if(!enable_2nd_card && i == SRV_FMGR_DRV_CARD_2_TYPE)
            continue;

        switch(type)
        {
        default:
        case SRV_FMGR_DRIVELIST_TYPE_ALL:
            break;

        case SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE:
            if(!srv_fmgr_drv_is_accessible(drv_letter) && 
                i != SRV_FMGR_DRV_CARD_TYPE &&
                i != SRV_FMGR_DRV_CARD_2_TYPE)
                continue;
            break;

        case SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY:
        case SRV_FMGR_DRIVELIST_ITYPE_FMGR:
            if(!srv_fmgr_drv_is_accessible(drv_letter))
                continue;
            break;
        }
        drv_mask |= (U32)(1 << i);
    }

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_460E3091C2034F1C9D08CA68C798CA11, 
        "[SRV_FMGR] > Drv List > create(%d): %x", type, drv_mask);
    return drv_mask;

}

void srv_fmgr_drivelist_destroy(SRV_FMGR_DRVLIST_HANDLE hdrvlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* do nothing, because handle is a U32 bit-mask */
    
    /* please still call create / destroy in pair, 
     * in case in the future handle becomes a dynamic resource */
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_A5613B9E6B0445D2BF666AF71BF5124D, "[SRV_FMGR] > Drv List > destroy(%x)", hdrvlist);
}

S32 srv_fmgr_drivelist_count(SRV_FMGR_DRVLIST_HANDLE hdrvlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    count = 0;
    for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        if(hdrvlist & (U32)(1<<i))
            count++;
    }

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_F0F547FC72814D12AEB68573CC0BE814, 
        "[SRV_FMGR] > Drv List > count(%x): %d", hdrvlist, count);
    return count;

}

U8 srv_fmgr_drivelist_get_drv_letter(SRV_FMGR_DRVLIST_HANDLE hdrvlist, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count;
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    count = 0;
    for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
    {
        if(hdrvlist & (U32)(1<<i))
            count++;
        
        if (count == index + 1)
            break;
    }

    ret = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)i);
    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_BA73EDCB69FF46F7AA3998749925DA49, 
        "[SRV_FMGR] > Drv List > get_drv_letter(%x,%d): %d", hdrvlist, index, ret);
    return ret;
}

S32 srv_fmgr_drivelist_get_index_by_drv_letter(SRV_FMGR_DRVLIST_HANDLE hdrvlist, U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        ret = -1;
        if(!drv_letter)
            break;

        count = 0;
        for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
        {
            if(hdrvlist & (U32)(1<<i))
            {
                count++;

                if(srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)i) == drv_letter)
                {
                    ret = count - 1;
                    i = SRV_FMGR_DRV_TOTAL;
                    break;
                }
            }
        }
    } while(0);

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_12C8C7C2C754436383D0ACC98C5BFBFA, 
        "[SRV_FMGR] > Drv List > get_index(%x, drv=%d): %d", hdrvlist, drv_letter, ret);
    return ret;
}

S32 srv_fmgr_drivelist_get_index_by_drv_type(SRV_FMGR_DRVLIST_HANDLE hdrvlist, srv_fmgr_drv_type_enum drv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        ret = -1;
        if(drv_type >= SRV_FMGR_DRV_TOTAL)
            break;

        count = 0;
        for(i=0;i<SRV_FMGR_DRV_TOTAL;i++)
        {
            if(hdrvlist & (U32)(1<<i))
            {
                count++;

                if(i == drv_type)
                {
                    ret = count - 1;
                    i = SRV_FMGR_DRV_TOTAL;
                    break;
                }
            }
        }
    } while(0);

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_0DAF7FDB1ADD4CB897E15F27919747A2, 
        "[SRV_FMGR] > Drv List > get_index(%x, type=%d): %d", hdrvlist, drv_type, ret);
    return ret;
}

#define LOCAL_FUNCTION

static S32 srv_fmgri_drv_get_volume_name(U8 drv_letter, U16* name_buffer, S32 name_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR           path[5];
    WCHAR           buf_name[SRV_FMGR_DRV_MAX_VOLUME_SIZE + 1];
    FS_HANDLE       handle;
    FS_DOSDirEntry  fs_entry;
    S32             len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    path[0] = drv_letter;
    path[1] = ':';
    path[2] = '\\';
    path[3] = '*';
    path[4] = 0;

    handle = FS_FindFirst(path, FS_ATTR_VOLUME , FS_ATTR_DIR|FS_ATTR_VOLUME, &fs_entry, buf_name, sizeof(buf_name));
    if(handle < 0)
        return handle;
    
    FS_FindClose(handle);
    
    if (fs_entry.NTReserved == FS_SFN_MATCH)
    {
        return srv_fmgri_convert_string(name_buffer, name_buf_size, buf_name);
    }
    else
    {
        len = mmi_wcslen(buf_name);
        if(!name_buffer)
            return len;
        if((len + 1)*ENCODING_LENGTH > name_buf_size)
            return FS_STRING_BUFFER_TOO_SMALL;
        
        mmi_wcsncpy(name_buffer, buf_name, len); 
    }
    return 0;
}

static MMI_BOOL srv_fmgri_drv_type_is_removable(srv_fmgr_drv_type_enum drv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(drv_type)
    {
    case SRV_FMGR_DRV_CARD_TYPE:
    case SRV_FMGR_DRV_CARD_2_TYPE:
    case SRV_FMGR_DRV_OTG_TYPE:
    case SRV_FMGR_DRV_OTG_2_TYPE:
    case SRV_FMGR_DRV_OTG_3_TYPE:
    case SRV_FMGR_DRV_OTG_4_TYPE:
    case SRV_FMGR_DRV_OTG_5_TYPE:
    case SRV_FMGR_DRV_OTG_6_TYPE:
    case SRV_FMGR_DRV_OTG_7_TYPE:
    case SRV_FMGR_DRV_OTG_8_TYPE:
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

void srv_fmgri_drv_update_status(U8* drv_table, S32 drv_count, S32 cause, MMI_BOOL in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, drv_type;
    U8 new_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(in && (cause != FS_MSDC_MOUNT_ERROR))
        new_state = SRV_FMGRI_DRV_STATE_MOUNTED;
    else
        new_state = SRV_FMGRI_DRV_STATE_NOT_MOUNTED;

    for(i=0;i<drv_count;i++)
    {
        drv_type = srv_fmgr_drv_get_type(drv_table[i]);
        if(drv_type < 0)
            continue;

        g_srv_fmgr_storage_ctxt.drv_mount_state[drv_type] = new_state;
    }

    srv_fmgr_drivelist_destroy(srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE));
}

#if defined(SRV_FMGR_TESTBED_ENABLE)

MMI_BOOL srv_fmgri_test_drv_in_c(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_drv_type_enum drv_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_type = srv_fmgr_drv_get_type(0);
    if(srv_fmgr_drv_get_letter_by_type(drv_type) != 0)
        return MMI_FALSE;

    if(srv_fmgr_drv_get_letter_by_type(-1) != 0)
        return MMI_FALSE;
    
    if(srv_fmgr_drv_get_letter_by_type(0xFFFF) != 0)
        return MMI_FALSE;

    return MMI_TRUE;
}

#endif
