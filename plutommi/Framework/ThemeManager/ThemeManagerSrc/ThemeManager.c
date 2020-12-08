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
 * ThemeManager.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the source file for Theme Manager.
 *
 * Author:
 * -------
 * -------
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*  Include: MMI header file */
#include "MMI_features.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "gui_themes.h"
#include "drm_gprot.h"
#include "xml_def.h"
#include "FileMgrSrvGProt.h"
#include "Conversions.h"
#include "app_crc.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "custom_mmi_default_value.h"
#include "CustVenusThemeRes.h"
#include "MMIDataType.h"
#include "CustThemesRes.h"
#include "mmi_rp_app_uiframework_def.h"
#include "kal_general_types.h"
#include "mmi_theme_mgr.h"
#include "gdi_const.h"
#include "mmi_theme_converter.h"
#include "CustDataRes.h"
#include "string.h"
#include "gdi_include.h"
#include "pluto_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "FileMgrServiceResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "lcd_sw_inc.h"
#include "PhoneSetupResList.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/* cache size */
#if defined(__MMI_DLT_CACHE_SUPPORT__)
    #define DLT_LOAD_ALWAYS_CACHE_SIZE      ((((__DLT_ALWAYS_LOAD_BUFFER_SIZE__) * 1024) + 3) & ~3)
    #define DLT_LOAD_ON_DEMAND_CACHE_SIZE   ((((__DLT_LOAD_ON_DEMAND_BUFFER_SIZE__) * 1024) + 3) & ~3)
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 

/* File buffer size for input to crc check */
#define TM_FILE_BUFF_SIZE    512


/***************************************************************************** 
* Typedef 
*****************************************************************************/
/***************************************************************************** 
* Local Variable
*****************************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

static tm_context_struct g_tm_cntx;

#ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
__align(4)
static U8 g_tm_theme_image_dirty_bits[(MAX_MMI_IMAGEID_IMAGES / 8) + 1];
#endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */

#ifdef __MMI_DLT_CACHE_SUPPORT__
typedef struct {
    U8 img_offset_type;
    U8 img_real_type;
} mmi_tm_img_map_type;

const mmi_tm_img_map_type g_tm_img_type_map[] = {
    {GDI_IMAGE_TYPE_GIF_FILE_OFFSET, GDI_IMAGE_TYPE_GIF},
    {GDI_IMAGE_TYPE_BMP_FILE_OFFSET, GDI_IMAGE_TYPE_BMP_MEM},   /* GDI_IMAGE_TYPE_BMP is used for bmp from resgen */
    {GDI_IMAGE_TYPE_JPG_FILE_OFFSET, GDI_IMAGE_TYPE_JPG},
    {GDI_IMAGE_TYPE_ABM_FILE_OFFSET, GDI_IMAGE_TYPE_ABM},
    {GDI_IMAGE_TYPE_AB2_FILE_OFFSET, GDI_IMAGE_TYPE_AB2},
    {GDI_IMAGE_TYPE_PNG_FILE_OFFSET, GDI_IMAGE_TYPE_PNG},
    {GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_BMP_SEQUENCE},
    {GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE},
    {GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_JPG_SEQUENCE},
    {GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_PNG_SEQUENCE},
    {GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_ABM_SEQUENCE},
    {GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET, GDI_IMAGE_TYPE_AB2_SEQUENCE},
    {GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET, GDI_IMAGE_TYPE_9SLICE}
    };
#endif

static U16 gVirAudFileNameList[MAXIMUM_THEMES_TONES][FS_GenVFN_SIZE + 8];

static DYNAUDIOINFO gDwnlThmToneInfo[MAXIMUM_THEMES_TONES];

#endif

static U8 g_curr_thm_index = 0;

/***************************************************************************** 
* Local Function
*****************************************************************************/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static void mmi_tm_create_image_header_pool(
                tm_theme_image_header_struct *ds_p,
                void *mempool_p,
                U16 unit_size,
                U32 total_pool_size);
static void *mmi_tm_add_image_header_to_pool(tm_theme_image_header_struct *ds_p, void *buff_p);
static void mmi_tm_reset_image_header_pool(tm_theme_image_header_struct *ds_p);
static void *mmi_tm_get_downloaded_theme_image(U32 image_offset, S32);
static U32 mmi_tm_get_theme_image_offset_or_index(U16 image_id, S32 *nArrayIndex_p);
static void mmi_tm_sort_theme_image_table(void);
static U16 mmi_ta_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height);
static U16 mmi_ta_check_theme_file_version_compatibility(FLOAT theme_version);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#ifdef __MMI_THEMES_V2_SUPPORT__
static void mmi_tm_image_table_quick_sort(U16, U16);
static void mmi_tm_image_table_insertion_sort(U16, U16);
static void mmi_tm_image_table_swap_node(U16, U16);
static void *mmi_tm_get_system_theme_image(U32 image_index);
#endif /* __MMI_THEMES_V2_SUPPORT__ */

#ifndef __MTK_TARGET__
S32 mmi_mte_is_active(void);
#endif
/***************************************************************************** 
* Global Variable
*****************************************************************************/
theme_details_struct g_tm_activated_theme;

#if (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))
#if (defined(__MMI_DLT_CACHE_SUPPORT__))
static U8 g_tm_load_always_cache[DLT_LOAD_ALWAYS_CACHE_SIZE+DLT_LOAD_ON_DEMAND_CACHE_SIZE];
static U8 *g_tm_load_ondemand_cache = g_tm_load_always_cache + DLT_LOAD_ALWAYS_CACHE_SIZE;
static U32 g_tm_load_always_offset = 0;
static U32 g_tm_load_ondemand_offset = 0;
#endif /* (defined(__MMI_DLT_CACHE_SUPPORT__)) */ 
/***************************************************************
Start Supported Theme version Table
***************************************************************/
FLOAT g_tm_supported_thm_version_table[MAX_SUPPORTED_VERSION_NUM] = 
{
    10.0     /* 11A */
};

/***************************************************************
End of Supported Theme version Table
***************************************************************/
U16 g_tm_checkThemeVersion; /* Variable check for theme versioning */

extern XML_PARSER_STRUCT g_tc_parser;
extern tc_deviceinfo_struct g_tc_deviceInfo;
extern tc_theme_download_info_struct g_tc_themeInfo;
#endif /* (defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)) */ 

#ifdef __DLT_ENABLE_PROCESS_QUEUE__
extern oslMsgqid mmi_ext_qid;
extern MMI_BOOL g_keypad_flag;
extern drv_get_key_func keypad_ptr;
#endif /* __DLT_ENABLE_PROCESS_QUEUE__ */

#ifdef __MMI_THEMES_V2_SUPPORT__
extern theme_details_struct *MMI_themes;
#else 
extern CONST_HARDWARE MMI_theme **MMI_themes;
#endif 

extern U8 g_tc_audiothmfileformat;

extern MMI_theme *current_MMI_theme;
extern S32 n_MMI_themes;


/***************************************************************************** 
* Global Function
*****************************************************************************/


S32 GetThemesNames(U8 **dest[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 noOfThemes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
    {
        return noOfThemes;
    }

    *dest = NULL;

#if defined(__COSMOS_MMI__)
    return mmi_res_get_theme_count();
#else /* defined(__COSMOS_MMI__) */
    return n_MMI_themes;
#endif /* defined(__COSMOS_MMI__) */
}


void SetThemes(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_curr_thm_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  UpdateUITheme
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateUITheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        return;
    }
#endif /* __MTK_TARGET__ */
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  /* fixed for usb */
    {
        if (g_tm_activated_theme.theme != current_MMI_theme)
        {
            set_MMI_theme(g_tm_activated_theme.theme);
            MMI_apply_current_theme();
        }
    }
    else
    {
        if (MMI_themes[g_curr_thm_index-1].theme != current_MMI_theme)
        {
            set_MMI_theme((MMI_theme*) MMI_themes[g_curr_thm_index-1].theme);
            MMI_apply_current_theme();
        }
    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#if defined(__COSMOS_MMI__)
    /* COSMOS only has one pluto theme, and pluto category screen will not change with theme */
    if (MMI_themes[0] != current_MMI_theme)
    {
        set_MMI_theme((MMI_theme*) MMI_themes[0]);
        MMI_apply_current_theme();
    }
#else /* defined(__COSMOS_MMI__) */
    if (MMI_themes[g_curr_thm_index] != current_MMI_theme)
    {
        set_MMI_theme((MMI_theme*) MMI_themes[g_curr_thm_index]);
        MMI_apply_current_theme();
    }
#endif /* defined(__COSMOS_MMI__) */

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
}


S8 *GetImageTheme(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ImageId)
    {
        case CHECKBOX_ON_IMAGE_ID:  /* check-box image */
            img = (U8*)(current_MMI_theme->list_check_selected_image);
            break;

        case CHECKBOX_OFF_IMAGE_ID:
            img = (U8*)(current_MMI_theme->list_check_unselected_image);
            break;

        case RADIO_ON_IMAGE_ID:     /* radio selector image */
            img = (U8*)(current_MMI_theme->list_radio_selected_image);
            break;

        case RADIO_OFF_IMAGE_ID:
            img = (U8*)(current_MMI_theme->list_radio_unselected_image);
            break;

        case IMG_H_SELECT_LEFT:     /* in-line editor, left-right selector */
            img = (U8*)(current_MMI_theme->inline_edit_left_arrow_image);
            break;

        case IMG_H_SELECT_RIGHT:
            img = (U8*)(current_MMI_theme->inline_edit_right_arrow_image);
            break;

        default:
            break;
    }

    return (S8*) img;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_get_phone_model
 * DESCRIPTION
 *  This function gets the phone model in theme res
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* mmi_get_phone_model(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MTK_INTERNAL__
    extern char* mmi_theme_phone_model;   /* defined in standalone res */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_theme_phone_model;/* Customer should define their own phone model */
#else /* __MTK_INTERNAL__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */ 
}


#ifdef __MMI_THEMES_V2_SUPPORT__

S8 *GetImageFromTheme(
        U16 ImgID,
        U16 ImgIndex,
        const CUSTOM_IMAGE_MAP *ImgIDMap,
        const CUSTOM_IMAGE_SEARCH_MAP *ImgIDSearchMap,
        const CUSTOM_IMAGE *ImgNames)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_does_theme_have_alt_image())
    {
        if (mmi_tm_is_theme_dirty_bit_set(ImgIndex))
        {
            S32 nArrayIndex;

            if (mmi_tm_get_curr_theme_type() == THEME_TYPE_SYSTEM)
            {
                return (S8*)mmi_tm_get_system_theme_image(
                        mmi_tm_get_theme_image_offset_or_index(ImgID, &nArrayIndex));
            }
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
            else
            {
                U32 nImageIndex = mmi_tm_get_theme_image_offset_or_index(ImgID, &nArrayIndex);

                if (nImageIndex > 0)
                {
                    S8 *pImageData;
#ifdef __MMI_DLT_CACHE_SUPPORT__
                    U8 image_type = mmi_tm_get_image_load_type(nArrayIndex);

                    if (image_type != THEME_IMG_LOAD_NEVER)
                    {
                        pImageData = (PS8) mmi_tm_find_img_in_cache(nArrayIndex, image_type);
                        
                        if (!pImageData)
                        {
                            pImageData = (PS8) mmi_tm_add_img_id_to_cache(nArrayIndex, nImageIndex, image_type);
                            if (!pImageData)
                            {
                                pImageData = (PS8) mmi_tm_get_downloaded_theme_image(nImageIndex, nArrayIndex);
                                if (!pImageData)
                                {
                                    return NULL;
                                }
                            }
                        }
                        return pImageData;
                    }
                    else
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
                    {
                        pImageData = (PS8) mmi_tm_get_downloaded_theme_image(nImageIndex, nArrayIndex);
                        if (!pImageData)
                        {
                            return NULL;
                        }

                        return pImageData;
                    }
                }
                else
                {
                    return NULL;
                }

            }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        }
    }
    return NULL;
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */



#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_create_image_header_pool
 * DESCRIPTION
 *  This function is for initializing image header buffer
 * PARAMETERS
 *  ds_p                [IN] pointer to image header buffer
 *  mempool_p           [IN] image header buffer
 *  unit_size           [IN]            
 *  total_pool_size     [IN]            
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
static void mmi_tm_create_image_header_pool(
        tm_theme_image_header_struct *ds_p,
        void *mempool_p,
        U16 unit_size,
        U32 total_pool_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ds_p->mempool_p = mempool_p;
    ds_p->current_offset = 0;
    ds_p->unit_size = unit_size;
    ds_p->total_pool_size = total_pool_size;
}


void mmi_tm_reset_imageid_image_header_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_reset_image_header_pool(&(g_tm_cntx.imageid_images_headers));
    memset(&g_tm_cntx.image_cache, 0xFF, sizeof(g_tm_cntx.image_cache));
}


void mmi_tm_reset_non_imageid_image_header_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_reset_image_header_pool(&(g_tm_cntx.non_imageid_images_headers));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer
 * PARAMETERS
 *  ds_p        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_reset_image_header_pool(tm_theme_image_header_struct *ds_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ds_p->current_offset = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_image_header_to_pool
 * DESCRIPTION
 *  this function adds image header to pool buffer
 * PARAMETERS
 *  ds_p        [?]     
 *  buff        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_tm_add_image_header_to_pool(tm_theme_image_header_struct *ds_p, void *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ds_p->current_offset + ds_p->unit_size) > ds_p->total_pool_size)
    {
        return NULL;
    }
    else
    {
        memcpy((ds_p->mempool_p + ds_p->current_offset), buff, ds_p->unit_size);
        temp_ptr = ds_p->mempool_p + ds_p->current_offset;
        ds_p->current_offset += ds_p->unit_size;
        return temp_ptr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_downloaded_theme_image
 * DESCRIPTION
 *  It returns downloadable theme image pointer
 * PARAMETERS
 *  image_offset        [IN]        
 *  nArrIndex           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_tm_get_downloaded_theme_image(U32 image_offset, S32 nArrIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    void *image_p;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_ParseFH(g_tm_cntx.theme_file_handle) >= 0)
    {
        if (g_tm_cntx.image_cache[nArrIndex].nOffset != -1)
        {
            return (void*)((S8*) g_tm_cntx.imageid_images_headers.mempool_p +
                            g_tm_cntx.image_cache[nArrIndex].nOffset);
        }

        if (DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >= 0 )
        {
            if (DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) !=
                FS_NO_ERROR)
            {
  		       return NULL;
            }
        }
        else
        {
  	      return NULL;
        }


        /* offset in next 4 bytes */
        buff[8] = (U8) (image_offset & 0x000000ff);
        buff[9] = (U8) ((image_offset >> 8) & 0x000000ff);
        buff[10] = (U8) ((image_offset >> 16) & 0x000000ff);
        buff[11] = (U8) ((image_offset >> 24) & 0x000000ff);

        /* file handle in next 4 bytes */
        buff[12] = (U8) (g_tm_cntx.theme_file_handle & 0x000000ff);
        buff[13] = (U8) ((g_tm_cntx.theme_file_handle >> 8) & 0x000000ff);
        buff[14] = (U8) ((g_tm_cntx.theme_file_handle >> 16) & 0x000000ff);
        buff[15] = (U8) ((g_tm_cntx.theme_file_handle >> 24) & 0x000000ff);

        image_p = mmi_tm_add_image_header_to_pool(&(g_tm_cntx.imageid_images_headers), buff);
        if (image_p)
        {
            g_tm_cntx.image_cache[nArrIndex].nOffset =
                (U16) ((S8*) image_p - (S8*) g_tm_cntx.imageid_images_headers.mempool_p);
            return image_p;
        }
    }

    return GetDefaultImage();
}


#ifdef __MMI_DLT_CACHE_SUPPORT__

void mmi_tm_clear_ondemand_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_tm_load_ondemand_offset && count < g_tm_cntx.theme_imageid_image_count)
    {
        if (g_tm_cntx.theme_image_list[count].image_type == THEME_IMG_LOAD_ONDEMAND)
        {
            g_tm_cntx.theme_image_list[count].image_cache_ptr = NULL;
        }
        ++count;
    }
    g_tm_load_ondemand_offset = 0;

}


tm_image_load_type_enum mmi_tm_get_image_load_type(U32 img_list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_image_list[img_list_index].image_type;
}


PU8 mmi_tm_find_img_in_cache(U32 img_list_index, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_image_list[img_list_index].image_cache_ptr;
}


PU8 mmi_tm_add_to_DLT_img_cache(U32 image_offset, tm_image_load_type_enum img_load_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size, i;
    U32 fp;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};
    S32 image_file_size;
    S32 dlt_img_cache_size;
    PU8 image_buff;
    PU32 cache_offset;
    PU8 cache_ptr;
	PU8 p_img_ret=NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( FS_GetFilePosition(g_tm_cntx.theme_file_handle, &fp) != FS_NO_ERROR )
    {
        return NULL;
    }

    if( DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >= 0)
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) != FS_NO_ERROR )
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    /* offset in next 4 bytes */
    buff[8] = (U8) (image_offset & 0x000000ff);
    buff[9] = (U8) ((image_offset >> 8) & 0x000000ff);
    buff[10] = (U8) ((image_offset >> 16) & 0x000000ff);
    buff[11] = (U8) ((image_offset >> 24) & 0x000000ff);

    /* file handle in next 4 bytes */
    buff[12] = (U8) (g_tm_cntx.theme_file_handle & 0x000000ff);
    buff[13] = (U8) ((g_tm_cntx.theme_file_handle >> 8) & 0x000000ff);
    buff[14] = (U8) ((g_tm_cntx.theme_file_handle >> 16) & 0x000000ff);
    buff[15] = (U8) ((g_tm_cntx.theme_file_handle >> 24) & 0x000000ff);
    
    gdi_image_virtualfile_sequence_get_image_size(buff, (U32*)&image_file_size);

    switch (img_load_type)
    {
        case THEME_IMG_LOAD_ALWAYS:
            cache_ptr = g_tm_load_always_cache;
            cache_offset = &g_tm_load_always_offset;
            dlt_img_cache_size = DLT_LOAD_ALWAYS_CACHE_SIZE;
            break;
        case THEME_IMG_LOAD_ONDEMAND:
        default:
            cache_ptr = g_tm_load_ondemand_cache;
            cache_offset = &g_tm_load_ondemand_offset;
            dlt_img_cache_size = DLT_LOAD_ON_DEMAND_CACHE_SIZE;
    }

    /* 4-byte algin */
    if (((U32) cache_ptr + *cache_offset) % 4)
    {
        *cache_offset += 4 - (((U32) cache_ptr + *cache_offset) % 4);
    }
    image_buff = cache_ptr + *cache_offset;

    /* Refer gdi_image_parse_resource_internal() in Gdi_image.c for header format information */
    for (i=sizeof(g_tm_img_type_map)/sizeof(mmi_tm_img_map_type)-1; i>=0; i--)
    {
        if (buff[0] == g_tm_img_type_map[i].img_offset_type)
        {
            if ((*cache_offset + image_file_size + 8) > dlt_img_cache_size) /* 8 extra bytes for internal Header */
            {
                DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN);
                return NULL;
            }
            /* change image type since we load data from file to cache */
            image_buff[0] = g_tm_img_type_map[i].img_real_type;

            image_buff[1] = buff[1];
            image_buff[2] = buff[2];
            image_buff[3] = buff[3];
            image_buff[4] = buff[4];
            image_buff[5] = buff[5];
            image_buff[6] = buff[6];
            image_buff[7] = buff[7];

            p_img_ret = image_buff;
        }
    }

	/* load data to cache from file */
	if (p_img_ret != NULL)
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, image_buff + 8, image_file_size, (U32*) & size) != FS_NO_ERROR )
    {
            return NULL;
        }

        *cache_offset += (image_file_size + 8); /* 8 extra bytes for Header */
    }

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN) < 0)
    {
        return NULL;
    }
	return p_img_ret;
}


PU8 mmi_tm_add_img_id_to_cache(U32 img_list_index, U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 pImage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pImage = mmi_tm_add_to_DLT_img_cache(image_offset, type);
    g_tm_cntx.theme_image_list[img_list_index].image_cache_ptr = pImage;

    MMI_TRACE(PLUTO_FW_TRC_THEME, MMI_TM_TRC_ADD_IMG_ID_TO_CACHE_HDLR, img_list_index, image_offset, type);

    return pImage;
}
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 


PU8 mmi_tm_create_non_imageid_image(U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    U32 fp;
    U8 buff[MAX_THEME_IMAGE_HEADER_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DLT_CACHE_SUPPORT__
    if (type != THEME_IMG_LOAD_NEVER)
    {
        PU8 pImage = mmi_tm_add_to_DLT_img_cache(image_offset, type);

        if (pImage)
        {
            MMI_TRACE(PLUTO_FW_TRC_THEME, MMI_TM_TRC_CREATE_NON_IMAGEID_IMAGE_HDLR, image_offset, type);
            return pImage;
        }
    }
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
    if ( FS_GetFilePosition(g_tm_cntx.theme_file_handle, &fp) != FS_NO_ERROR )
    {
        return NULL;
    }

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, image_offset, FS_FILE_BEGIN) >=0 )
    {
        if ( DRM_read_file(g_tm_cntx.theme_file_handle, buff, THEME_IMAGE_INFO_HEADER, (U32*) & size) != FS_NO_ERROR )
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    /* offset in next 4 bytes */
    buff[8] = (U8) (image_offset & 0x000000ff);
    buff[9] = (U8) ((image_offset >> 8) & 0x000000ff);
    buff[10] = (U8) ((image_offset >> 16) & 0x000000ff);
    buff[11] = (U8) ((image_offset >> 24) & 0x000000ff);

    /* file handle in next 4 bytes */
    buff[12] = (U8) (g_tm_cntx.theme_file_handle & 0x000000ff);
    buff[13] = (U8) ((g_tm_cntx.theme_file_handle >> 8) & 0x000000ff);
    buff[14] = (U8) ((g_tm_cntx.theme_file_handle >> 16) & 0x000000ff);
    buff[15] = (U8) ((g_tm_cntx.theme_file_handle >> 24) & 0x000000ff);

    if ( DRM_seek_file(g_tm_cntx.theme_file_handle, fp, FS_FILE_BEGIN) < 0)
    {
        return NULL;
    }

    return (PU8) mmi_tm_add_image_header_to_pool(&(g_tm_cntx.non_imageid_images_headers), buff);
}


void mmi_tm_handle_audio(U32 audio_offset, U32 audio_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 virtual_audio_fname[FS_GenVFN_SIZE + 8];
    S32 fs_result;

    /* PMT DLT_FIXES - TK 20060325 START */
    CHAR TempName[MAX_IMAGE_NAME_WIDTH + MAX_AUDIO_NAME_WIDTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT DLT_FIXES - TK 20060325 END */

    if (g_tc_audiothmfileformat == THEME_AUDIO)
    {
        mmi_asc_to_ucs2((CHAR*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_FILE);   /* currently only one audio is suported. Will be changed */
    }
    else if (g_tc_audiothmfileformat == THEME_MIDI)
    {
        mmi_asc_to_ucs2((CHAR*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_MID_FILE);
    }
    else if (g_tc_audiothmfileformat == THEME_MP3)
    {
        mmi_asc_to_ucs2((CHAR*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_MP3_FILE);
    }
    else if (g_tc_audiothmfileformat == THEME_RA)
    {
        mmi_asc_to_ucs2((CHAR*) gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_RA_FILE);
    }
    /* PMT DLT_FIXES - TK 20060325 START */
    memset(TempName, 0, (MAX_IMAGE_NAME_WIDTH + MAX_AUDIO_NAME_WIDTH));
    mmi_asc_to_ucs2((CHAR*) TempName, THEME_AUDIO_FOLDER_PATH);
    FS_CreateDir((PU16) TempName);
    //      CreateDir((U8*)TempName);
    //PMT DLT_FIXES - TK 20060325 END
    //      mmi_asc_to_ucs2((CHAR*)gDwnlThmToneInfo[0].AudioName, THEME_AUDIO_FILE);//currently only one audio is suported. Will be changed
    memset(virtual_audio_fname, 0, sizeof(virtual_audio_fname));
    fs_result = FS_GenVirtualFileName(
                    g_tm_cntx.theme_file_handle,
                    (U16*) virtual_audio_fname,
                    (unsigned int)FS_GenVFN_SIZE,
                    audio_offset,
                    audio_size);
    mmi_ucs2cat((CHAR*) virtual_audio_fname, (CHAR*) ".");
    mmi_ucs2cat((CHAR*) virtual_audio_fname, (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)gDwnlThmToneInfo[0].AudioName));
    mmi_ucs2cpy((CHAR*) gVirAudFileNameList[0], (CHAR*) virtual_audio_fname);
    if (fs_result >= 0)
    {
        g_tm_cntx.theme_res_status[THEME_RES_RINGTONE] = MMI_TRUE;
        gDwnlThmToneInfo[0].AudioId = CURRENT_THEME_INCOMING_CALL_TONE;
    }
    else
    {
        mmi_popup_display_simple((WCHAR*)get_string(STR_ID_FMGR_SPACE_NOT_AVAILABLE), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }

    /* PMT DLT_FIXES - TK 20060328 END */
}


pBOOL mmi_tm_get_current_theme_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_res_status[THEME_RES_RINGTONE];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_check_theme_file_phone_model_compatibility
 * DESCRIPTION
 *  validates Theme Phone Model.
 * PARAMETERS
 *  theme_phone_model       [IN]        
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_tm_check_theme_file_phone_model_compatibility(CHAR* theme_phone_model)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strncmp(theme_phone_model, mmi_get_phone_model(), MAX_MODEL_ID_LEN))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_theme_version_table
 * DESCRIPTION
 *  This function gets the theme version table
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const FLOAT *mmi_tm_get_theme_version_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_supported_thm_version_table;
}


MMI_BOOL mmi_tm_theme_version_and_deviceinfo_check(U16 *theme_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE tmp_theme_file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_tm_checkThemeVersion = MMI_TRUE;

    tmp_theme_file_handle = DRM_open_file((U16*) theme_file_name, FS_READ_ONLY | FS_OPEN_SHARED, 0);

    if (tmp_theme_file_handle < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

    if (xml_new_parser(&g_tc_parser) == -1)
    {
        DRM_close_file(tmp_theme_file_handle);
        return MMI_FALSE;
    }
    xml_register_element_handler(&g_tc_parser, mmi_tc_my_xml_elem_start_hdlr, mmi_tc_my_xml_elem_end_hdlr);
    g_tc_parser.pos = THEME_FILE_SIZE_HEADER + THEME_CHECKSUM_HEADER_SIZE;
    xml_parse_file_from_offset(&g_tc_parser, tmp_theme_file_handle);

    DRM_close_file(tmp_theme_file_handle);
    g_tm_checkThemeVersion = MMI_FALSE;
    if (mmi_ta_check_theme_file_version_compatibility((FLOAT) g_tc_themeInfo.version))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


S32 mmi_tm_verify_theme_checksum(U8 *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 no_of_char;
    U32 checksum[2];
    FS_HANDLE file;
    U32 theme_file_size;
    U32 bytes_read = 0;
    U8 *file_buffer;
    U32 tc_checksumkey = 0xFFFFFFFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    file = FS_Open((WCHAR*) file_name_p, FS_READ_ONLY);

    if (!file)
    {
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
    else
    {
        /* Read checksum & File Size here, after Opening file get it's size */
        if (FS_GetFileSize(file, &theme_file_size) != FS_NO_ERROR)
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        /* 4 bytes of File Size are used to calculate CRC therefore we need to include in CRC checking */
        FS_Read(file, (void *)&checksum, THEME_CHECKSUM_HEADER_SIZE + THEME_FILE_SIZE_HEADER, &no_of_char);

        if (no_of_char < (THEME_CHECKSUM_HEADER_SIZE + THEME_FILE_SIZE_HEADER))
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        if (theme_file_size != checksum[1])
        {
            FS_Close(file);
            return THEME_ERROR_FILE_FORMAT_BAD;
        }

        /* allocate buffer for file read */
        file_buffer = OslMalloc(TM_FILE_BUFF_SIZE);

        /* Tricky THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC is assumed to be multiple of TM_FILE_BUFF_SIZE */
        while (bytes_read < (THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC))        /*  0x80000 Bytes => 512 * 1024 = 524288 Bytes */
        {
            FS_Read(file, (void *)file_buffer, TM_FILE_BUFF_SIZE, &no_of_char);
            if (no_of_char > 0)
            {
                bytes_read += no_of_char;
                tc_checksumkey = applib_crc_update(tc_checksumkey, file_buffer, (U16)no_of_char);

                if (no_of_char < TM_FILE_BUFF_SIZE)
                    break;
            }
            /* PMT DLT_FIXES - TK 20060321 START */
            else
            {
                break;  /* boundary value analysis is not consider here so this loop is */

            }
            /* PMT DLT_FIXES - TK 20060321 END */
        }

        OslMfree(file_buffer);
        
    }
    FS_Close(file);
    if (tc_checksumkey == checksum[0])
    {
        return THEME_ERROR_SUCCESS;
    }
    else
    {
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
}


U8 mmi_tm_get_curr_theme_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_audio_filename
 * DESCRIPTION
 *  It gives the theme tone virtual file name
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  string of theme tone virtual file name
 *****************************************************************************/
static CHAR *mmi_tm_get_audio_filename(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (CHAR*) gVirAudFileNameList[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_file_version_compatibility
 * DESCRIPTION
 *  validates Theme version.
 * PARAMETERS
 *  theme_version       [IN] theme version
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
static U16 mmi_ta_check_theme_file_version_compatibility(FLOAT theme_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    FLOAT *VersionTable_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VersionTable_p = (FLOAT*) mmi_tm_get_theme_version_table();

    for (i = 0; i < MAX_SUPPORTED_VERSION_NUM; i++)
    {
        if (VersionTable_p[i] == theme_version)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_file_lcd_dim_compatibiltiy
 * DESCRIPTION
 *  validates LCD dimensions.
 * PARAMETERS
 *  lcd_width       [IN] lcd width
 *  lcd_height      [IN] lcd height
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
static U16 mmi_ta_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_height == LCD_HEIGHT && lcd_width == LCD_WIDTH)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


CHAR *GetAudioNameWithPathInFileSystem(U16 AudioId, CHAR* AudioData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((AudioId > CURRENT_THEME_TONE_BASE) && (AudioId < CURRENT_THEME_TONE_END))
	{
		U8 i;
		for(i=0; i<MAXIMUM_THEMES_TONES; i++)
		{
			if((U16)gDwnlThmToneInfo[i].AudioId == AudioId)
			{
				/*Changes for virtual tone file*/
				mmi_ucs2cpy(AudioData, (CHAR*)mmi_tm_get_audio_filename(i));
				return AudioData;
			}
		}
	}

	return NULL;
}


U8 GetThemeV2TonesInfo(DYNAUDIOINFO  **downloadThemeTones)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    *downloadThemeTones = gDwnlThmToneInfo;
	return MAXIMUM_THEMES_TONES;
}


#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */


void mmi_theme_manager_init(void)
{
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL is_initialized = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_initialized)
        return;
        
    is_initialized = MMI_TRUE;

    memset((void*)&g_tm_cntx, 0, sizeof(tm_context_struct));
    g_tm_cntx.theme_file_handle = -1;

    mmi_tm_create_image_header_pool(
        &(g_tm_cntx.imageid_images_headers),
        g_tm_cntx.imageid_images_headers_pool,
        MAX_THEME_IMAGE_HEADER_LENGTH,
        (MAX_THEME_IMAGE_HEADER_LENGTH * MAX_THEME_IMAGEID_IMAGES));
    mmi_tm_create_image_header_pool(
        &(g_tm_cntx.non_imageid_images_headers),
        g_tm_cntx.non_imageid_images_headers_pool,
        MAX_THEME_IMAGE_HEADER_LENGTH,
        (MAX_THEME_IMAGE_HEADER_LENGTH * MAX_THEME_NON_IMAGEID_IMAGES));
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
}

#if (defined(__MMI_THEMES_V2_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_system_theme_image
 * DESCRIPTION
 *  It returns system theme image pointer
 * PARAMETERS
 *  image_index     [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_tm_get_system_theme_image(U32 image_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_activated_theme.system_image_list[image_index];
}


void mmi_tm_set_imageid(U16 image_id, U32 image_offset, tm_image_load_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
    U16 image_index;
    U16 n_byte;
    U8 n_bit;
#endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_cntx.theme_imageid_image_count >= MAX_THEME_IMAGEID_IMAGES)
    {
        return;
    }
    else
    {
        MMI_TRACE(PLUTO_FW_TRC_THEME, MMI_TM_TRC_SET_IMAGEID_HDLR, image_id, type);
		if(image_id == IMG_ID_DISPCHAR_THEME_WALLPAPER)
			g_tm_cntx.theme_res_status[THEME_RES_WALLPAPER]= MMI_TRUE;

		if(image_id == IMG_ID_DISPCHAR_THEME_SCREENSAVER)
			g_tm_cntx.theme_res_status[THEME_RES_SCREENSAVER] = MMI_TRUE;

        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_id = image_id;
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_offset = image_offset;
    #ifdef __MMI_DLT_CACHE_SUPPORT__
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_type = type;
        g_tm_cntx.theme_image_list[g_tm_cntx.theme_imageid_image_count].image_cache_ptr = 0;
    #endif /* __MMI_DLT_CACHE_SUPPORT__ */ 
        ++g_tm_cntx.theme_imageid_image_count;

        g_tm_cntx.theme_res_status[THEME_RES_ALTERNATE_IMG] = MMI_TRUE;

    #ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
        image_index = GetImageIndex(image_id);

        n_byte = (image_index >> 3);
        n_bit = (image_index % 8);

        g_tm_theme_image_dirty_bits[n_byte] |= (0x80 >> n_bit);
    #endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_tm_sort_theme_image_table
 * DESCRIPTION
 *  this function sort the table containg image id to offset mapping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_sort_theme_image_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_cntx.theme_imageid_image_count)
    {
        mmi_tm_image_table_quick_sort(0, (U16) (g_tm_cntx.theme_imageid_image_count - 1));
        mmi_tm_image_table_insertion_sort(0, (U16) (g_tm_cntx.theme_imageid_image_count - 1));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_quick_sort
 * DESCRIPTION
 *  It sorts the table using quick sort algorithm
 * PARAMETERS
 *  l       [IN]        
 *  r       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_image_table_quick_sort(U16 l, U16 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U32 pivot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r - l) > 4)
    {
        i = (r + l) / 2;
        if (g_tm_activated_theme.theme_image_details_list[l].image_id >
            g_tm_activated_theme.theme_image_details_list[i].image_id)
        {
            mmi_tm_image_table_swap_node(l, i);
        }
        if (g_tm_activated_theme.theme_image_details_list[l].image_id >
            g_tm_activated_theme.theme_image_details_list[r].image_id)
        {
            mmi_tm_image_table_swap_node(l, r);
        }
        if (g_tm_activated_theme.theme_image_details_list[i].image_id >
            g_tm_activated_theme.theme_image_details_list[r].image_id)
        {
            mmi_tm_image_table_swap_node(i, r);
        }

        j = r - 1;
        mmi_tm_image_table_swap_node(i, j);
        i = l;
        pivot = g_tm_activated_theme.theme_image_details_list[j].image_id;

        for (;;)
        {
            do
            {
            } while (g_tm_activated_theme.theme_image_details_list[++i].image_id < pivot);
            do
            {
            } while (g_tm_activated_theme.theme_image_details_list[--j].image_id > pivot);

            if (j < i)
            {
                break;
            }

            mmi_tm_image_table_swap_node(i, j);
        }

        mmi_tm_image_table_swap_node(i, (U16) (r - 1));
        mmi_tm_image_table_quick_sort(l, j);
        mmi_tm_image_table_quick_sort((U16) (i + 1), r);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_insertion_sort
 * DESCRIPTION
 *  It sorts the table using insertion sort algorithm
 * PARAMETERS
 *  lo      [IN]        
 *  hi      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_image_table_insertion_sort(U16 lo, U16 hi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    theme_image_detail_struct elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = lo + 1; i <= hi; ++i)
    {
        memcpy(&elem, &g_tm_activated_theme.theme_image_details_list[i], sizeof(theme_image_detail_struct));

        j = i;
        while (j > lo)
        {
            if (g_tm_activated_theme.theme_image_details_list[j - 1].image_id <= elem.image_id)
            {
                break;
            }
            memcpy(
                &g_tm_activated_theme.theme_image_details_list[j],
                &g_tm_activated_theme.theme_image_details_list[j - 1],
                sizeof(theme_image_detail_struct));
            j--;
        }
        memcpy(&g_tm_activated_theme.theme_image_details_list[j], &elem, sizeof(theme_image_detail_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_image_table_swap_node
 * DESCRIPTION
 *  It swaps the theme images
 * PARAMETERS
 *  i       [IN]        
 *  j       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_image_table_swap_node(U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    theme_image_detail_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &g_tm_activated_theme.theme_image_details_list[i], sizeof(theme_image_detail_struct));
    memcpy(
        &g_tm_activated_theme.theme_image_details_list[i],
        &g_tm_activated_theme.theme_image_details_list[j],
        sizeof(theme_image_detail_struct));
    memcpy(&g_tm_activated_theme.theme_image_details_list[j], &temp, sizeof(theme_image_detail_struct));
}


U8 mmi_tm_does_theme_have_alt_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_res_status[THEME_RES_ALTERNATE_IMG];
}


pBOOL mmi_tm_get_current_theme_screensaver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_tm_cntx.theme_res_status[THEME_RES_SCREENSAVER];
}


U8 mmi_tm_is_theme_dirty_bit_set(U16 image_index)
{
#ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n_byte;
    U16 n_bit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_byte = (image_index >> 3);
    n_bit = (image_index % 8);

    return (U8) ((g_tm_theme_image_dirty_bits[n_byte]) & (0x80 >> n_bit));
#else
    return MMI_TRUE;
#endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_theme_image_offset_or_index
 * DESCRIPTION
 *  This function gets the offset/index for the image
 * PARAMETERS
 *  image_id            [IN]        
 *  nArrayIndex_p       [?]         [?]
 * RETURNS
 *  numeric value of image offset or index
 *****************************************************************************/
static U32 mmi_tm_get_theme_image_offset_or_index(U16 image_id, S32 *nArrayIndex_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = g_tm_cntx.theme_imageid_image_count;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if (g_tm_activated_theme.theme_image_details_list[nMid].image_id == image_id)
        {
            *nArrayIndex_p = nMid;
            return g_tm_activated_theme.theme_image_details_list[nMid].image_offset;
        }
        if (image_id > g_tm_activated_theme.theme_image_details_list[nMid].image_id)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return 0;
}


MMI_BOOL mmi_tm_does_theme_res_exist(tm_resource_type_enum res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(res_type < THEME_RES_END);
    return g_tm_cntx.theme_res_status[res_type];
}


S32 mmi_tm_activate(U32 theme_id, U8 theme_type, U16* theme_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = THEME_ERROR_FAILURE;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    S32 i;
    U16 nmodels = 0;
    FS_HANDLE last_theme_file_handle = (FS_HANDLE)NULL;
    MMI_BOOL phonemodelcheck = MMI_FALSE;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    U8 previous_theme_type = g_tm_cntx.theme_type;

    g_tm_cntx.theme_type = theme_type;  /* GUI needs to know theme type during activation */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (theme_type)
    {
    case THEME_TYPE_SYSTEM:

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        /* reset DLT info */
        g_tm_activated_theme.system_image_list          = NULL;
        g_tm_activated_theme.theme                      = NULL;
        g_tm_activated_theme.theme_image_details_list   = NULL;

        for (i=0; i<THEME_RES_END; i++)
        {
            g_tm_cntx.theme_res_status[i] = MMI_FALSE;
        }

        if (g_tm_cntx.theme_file_handle >= FS_NO_ERROR)
        {
            DRM_close_file(g_tm_cntx.theme_file_handle);
            g_tm_cntx.theme_file_handle = -1;
        }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

        set_MMI_theme((MMI_theme*) MMI_themes[(theme_id - 1)].theme);
        MMI_apply_current_theme();
        
        result = THEME_ERROR_SUCCESS;
        break;

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

    case THEME_TYPE_DOWNLOADED_PHONE:
    case THEME_TYPE_DOWNLOADED_CARD:

        memset(&g_tc_deviceInfo, 0, sizeof(tc_deviceinfo_struct));
        memset(&g_tc_themeInfo, 0, sizeof(tc_theme_download_info_struct));

        if (mmi_tm_theme_version_and_deviceinfo_check(theme_file_name) != MMI_TRUE)
        {
            g_tm_cntx.theme_type = previous_theme_type;
            return THEME_ERROR_VERSION_FAILURE;
        }
        if (!mmi_ta_check_theme_file_lcd_dim_compatibiltiy(g_tc_deviceInfo.lcdwidth, g_tc_deviceInfo.lcdht))
        {
            g_tm_cntx.theme_type = previous_theme_type;
            return THEME_ERROR_LCD_SIZE_MISMATCH;
        }
        while (*g_tc_deviceInfo.model_ID[nmodels] && nmodels < MAX_PHONE_MODELS)
        {
            if (mmi_tm_check_theme_file_phone_model_compatibility((CHAR*) g_tc_deviceInfo.model_ID[nmodels]) == MMI_TRUE)
            {
                phonemodelcheck = MMI_TRUE;
                break;
            }
            ++nmodels;
        }
        if (!phonemodelcheck)
        {
            g_tm_cntx.theme_type = previous_theme_type;
            return THEME_ERROR_PHONE_MODEL_MISMATCH;
        }

        last_theme_file_handle = g_tm_cntx.theme_file_handle;
        g_tm_cntx.theme_file_handle = DRM_open_file((U16*) theme_file_name, FS_READ_ONLY | FS_OPEN_SHARED, 0);

        if (g_tm_cntx.theme_file_handle < FS_NO_ERROR)
        {
            result = g_tm_cntx.theme_file_handle;
            g_tm_cntx.theme_file_handle = last_theme_file_handle;
            g_tm_cntx.theme_type = previous_theme_type;
            return result;    /* return file system error code (< 0 ) */
        }
        DRM_close_file(last_theme_file_handle);

        g_tm_activated_theme.theme                      = NULL;
        g_tm_activated_theme.system_image_list          = NULL;
        g_tm_activated_theme.theme_image_details_list   = g_tm_cntx.theme_image_list;
        memset(g_tm_cntx.theme_image_list, 0, sizeof(g_tm_cntx.theme_image_list));

        mmi_tm_reset_imageid_image_header_pool();
        mmi_tm_reset_non_imageid_image_header_pool();

        #ifdef __MMI_DLT_CACHE_SUPPORT__
        g_tm_load_always_offset = 0;
        mmi_tm_clear_ondemand_cache();
        #endif /* __MMI_DLT_CACHE_SUPPORT__ */ 

        g_tm_cntx.theme_imageid_image_count = 0;
        for (i=0; i<THEME_RES_END; i++)
        {
            g_tm_cntx.theme_res_status[i] = MMI_FALSE;
        }
#ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
        memset(g_tm_theme_image_dirty_bits, 0, sizeof(g_tm_theme_image_dirty_bits));
#endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */

        if (!mmi_tc_convert_theme_file_to_mmi_theme(&(g_tm_activated_theme.theme), g_tm_cntx.theme_file_handle))
        {
            g_tm_cntx.theme_type = previous_theme_type;
            return THEME_ERROR_FAILURE;
        }
        mmi_tm_sort_theme_image_table();

        set_MMI_theme(g_tm_activated_theme.theme);
        MMI_apply_current_theme();

        result = THEME_ERROR_SUCCESS;
        break;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

    default:
        MMI_ASSERT(0);  /* wrong theme type */
        break;
    }

    wgui_status_icon_bar_initialize();

    if (result != THEME_ERROR_SUCCESS)
        g_tm_cntx.theme_type = previous_theme_type; /* restore theme type */

    return result;
}


#endif /* (defined(__MMI_THEMES_V2_SUPPORT__)) */ 



