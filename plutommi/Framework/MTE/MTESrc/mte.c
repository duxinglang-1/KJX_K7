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
 *  mte.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MoDIS Theme Editor, MoDIS only.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __MTK_TARGET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_include.h"
#include "wgui_categories_util.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "osc_type.h"
#include "osc_func.h"
#include "mmiapi.h"
#include "ABMLoader.h"
#include "DialerGprot.h"
#include "IdleGprot.h"

#include "mmi_rp_app_uiframework_def.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif
#if !defined(__DISABLE_SHORTCUTS_MENU__) && !defined(__COSMOS_MMI__)
#include "mmi_rp_app_shortcuts_def.h"
#endif

#if defined(__MMI_CALENDAR__) && !defined(__COSMOS_MMI__)
#include "CalendarGprot.h"
#endif

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIThemes.h"
#endif

/* example screens */
#include "SettingGenum.h"
#include "IdleAppDef.h"
#include "PhoneSetup.h"
#include "SettingResDef.h"
#include "AlarmResDef.h"
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__COSMOS_MMI__)
#include "mmi_rp_app_medply_def.h"
#endif
#if defined(__MMI_MEDIA_PLAYER__)
#include "MediaPlayerResDef.h"
#include "MediaPlayerGProt.h"
#endif

#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"
#include "mmi_rp_app_dcd_def.h"
#endif /* __MMI_OP01_DCD__ */

#include "gui_title.h"
#include "Wgui_title.h"
#include "wgui_categories_MM.h"
#include "gui_calendar.h"
#include "gui_themes.h"
#include "mteGprot.h"
#include "mte.h"
#include "mte_img_resource.h"
#include "CommonScreensResDef.h"

#include "hisr_config.h"
#include "Gpiosrvgprot.h"
#include "gdi_image.h"
#include "MainMenuProt.h"
#include "SettingProt.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static U8 *g_mmi_mte_image_folder_path = NULL;
static S32  g_mmi_mte_language_id = MMI_MTE_LANG_ENGLISH;
static mmi_mte_state_enum g_mmi_mte_state = MMI_MTE_STATE_INACTIVE;
static U8 g_mmi_mte_abm_exe_path[MMI_MTE_MAX_PATH_LEN];
static U8 g_mmi_mte_example_screen_buffer[MMI_MTE_EXAMPLE_SCREEN_BUF_SIZE];

static S32 g_mmi_mte_example_screen_tab_num = 0;

static MMI_BOOL g_mmi_mte_example_screen_editor_is_IME_mode = MMI_FALSE;
static S32 g_mmi_mte_example_screen_group_index = -1;

static const mmi_mte_font_struct g_mmi_mte_font[MMI_MTE_FONT_TYPE_NUM] =
{
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DEFAULT),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_UI_DEFAULT),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_SMALL),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_MEDIUM),     
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_LARGE),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_VKBD),     
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_SUBLCD),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DIALER_F1),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_DIALER_F2),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_MEDIUM_BOLD),
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT1),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT2),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT3),    
    MMI_MTE_FONT_DECLARE(MMI_MTE_FONT_NEW_FONT4)   
};

static void *g_mmi_mte_system_variable[MMI_MTE_SYSTEM_VALUE_NUM] = {NULL};

/*
 * Image related
 */
static gdi_handle   g_mmi_mte_anim_handle = GDI_NULL_HANDLE;
/* working buffer for the image resource */
static U32 g_mmi_mte_image_buffer[(MMI_MTE_MAX_IMAGE_RESOURCE_SIZE + 8) / 4];
static gdi_handle g_mmi_mte_image_layer_handle = GDI_NULL_HANDLE;
/* output image layer */
static U32 g_mmi_mte_image_layer_buffer[MMI_MTE_MAX_IMAGE_RESOURCE_SIZE];
static U8 *g_mmi_mte_output_buffer;
static S32 g_mmi_mte_output_image_width, g_mmi_mte_output_image_height;
static void (*g_mmi_mte_image_frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height);

/* 
 * MTE RPC 
 */
static kal_hisrid g_mte_to_mmi_hisr;
static int *g_mte_rpc_msg;  /* RPC message */
static int g_mmi_mte_api_index;
static int mmi_mte_ret_value;
static void (*mte_api_finish_callback)(void);
static void mmi_mte_rpc_handler(void *msg);
static void (*g_mmi_mte_switch_screen_callback)(void);

/*
 * Static functions
 */
static mmi_mte_resource_map_struct g_mmi_mte_res_map_table[MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM];
static S32 g_mmi_mte_resource_mapping_table_count = 0;
static void mmi_mte_free_res_mapping_table(void);
static U32 mmi_mte_get_image_resource_size(U8 *res_ptr);
static MMI_BOOL mmi_mte_is_ems_image(S8 *filename);

void mte_to_mmi_hisr(void);

static void mmi_mte_dummy_function(void);

static void mmi_mte_set_system_theme(U16 index);

static void mmi_mte_activate_entry(void);

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/*
 * System theme
 */
extern S32 n_MMI_themes;
#ifndef __MMI_THEMES_V2_SUPPORT__    
extern const MMI_theme **MMI_themes;
#else /* __MMI_THEMES_V2_SUPPORT__ */
extern const theme_details_struct *MMI_themes;
#endif /* __MMI_THEMES_V2_SUPPORT__ */
extern int tolower(kal_int32);
extern kal_char* release_verno(void);

extern const U16 gIndexIconsImageList[];

/*
 * External global functions
 */
extern UI_filled_area* dm_get_current_scr_bg_filler(void);

/* 
 * MMI
 */
//extern MMI_BOOL MMI_softkey_filler_disabled;

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
/* techno bar clock */
extern U8 g_clock_type;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

/* thick title flag */
extern MMI_BOOL g_wgui_use_thick;

extern FuncPtr Cat165TimerExpireCallBack;

#ifndef __COSMOS_MMI__
/* MMI theme context */
#ifdef __MMI_THEMES_APPLICATION__
extern thm_contex_struct g_thm_cntx;
#endif
#endif

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/* 
 * Memory allocation
 *
 * Disable OSCAR scheduler for safety.
 */
 
/*****************************************************************************
 * FUNCTION
 *  MTE_ALLOC
 * DESCRIPTION
 *  Allocates 4-byte aligned memory.
 * PARAMETERS
 *  alloc_size      [IN]    memory allocation size
 * RETURNS
 *  Memory pointer
 *****************************************************************************/
static void *MTE_ALLOC(U32 alloc_size)            
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     alloc_mem_ptr;
    U32     *aligned_mem_ptr;
    U32     aligned_size;
    U32     padding_bytes;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * The real address is stored in front of the aligned memory buffer.
     *
     * 4-BYTE PADDING + 4-BYTE REAL ADRRESS + MEMORY IN SIZE 
     */
    /* Do not accept zero size. This is different to the C malloc() behavior. */
    if (alloc_size == 0)
    {
        return NULL;
    }

    /* add 4-byte real address and preserve another 4-byte for padding */
    aligned_size = alloc_size + 4 + 4;

    OSC_Sys_Schedule_Enable(0);
    alloc_mem_ptr = (PU8)malloc(aligned_size);    
    OSC_Sys_Schedule_Enable(1);    

    if (alloc_mem_ptr)
    {
        padding_bytes = 4 - ((U32)alloc_mem_ptr & 0x3);
        aligned_mem_ptr = (U32*)(alloc_mem_ptr + padding_bytes);
        aligned_mem_ptr[0] = (U32)alloc_mem_ptr;
        
        return (aligned_mem_ptr + 1);
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  MTE_FREE
 * DESCRIPTION
 *  Frees 4-byte aligned memory.
 * PARAMETERS
 *  mem       [IN]  allocated memory pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void MTE_FREE(void *mem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     *alloc_mem_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem == NULL)
    {
        return;
    }

    alloc_mem_ptr = (U32*)mem;
    alloc_mem_ptr = (U32*)alloc_mem_ptr[-1];

    OSC_Sys_Schedule_Enable(0);
    free(alloc_mem_ptr);
    OSC_Sys_Schedule_Enable(1);        
}


/*
 * Image
 */
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_image_type_from_mte_to_gdi
 * DESCRIPTION
 *  Converts the MTE image type to the GDI image type.
 * PARAMETERS
 *  mte_image_type  [IN]   MTE input image type
 * RETURNS
 *  GDI image type
 *****************************************************************************/
static U8 mmi_mte_translate_image_type_from_mte_to_gdi(mmi_mte_image_enum mte_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 gdi_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mte_image_type)
    {
        case MMI_MTE_IMAGE_GIF:
            gdi_image_type = GDI_IMAGE_TYPE_GIF;
            break;

        case MMI_MTE_IMAGE_JPG:
            gdi_image_type = GDI_IMAGE_TYPE_JPG;
            break;

        case MMI_MTE_IMAGE_BMP:
            gdi_image_type = GDI_IMAGE_TYPE_BMP;
            break;

        case MMI_MTE_IMAGE_PNG:
            gdi_image_type = GDI_IMAGE_TYPE_PNG;
            break;

        case MMI_MTE_IMAGE_JPG_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_JPG_SEQUENCE;
            break;

        case MMI_MTE_IMAGE_BMP_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_BMP_SEQUENCE;
            break;

        case MMI_MTE_IMAGE_PNG_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_PNG_SEQUENCE;
            break;
        
        case MMI_MTE_IMAGE_BMP_TO_ABM:
        case MMI_MTE_IMAGE_PNG_TO_ABM:
            gdi_image_type = GDI_IMAGE_TYPE_ABM;
            break;

        case MMI_MTE_IMAGE_BMP_TO_ABM_SEQUENCE:
        case MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_ABM_SEQUENCE;
            break;

        case MMI_MTE_IMAGE_ABM_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_ABM_SEQUENCE;
            break;

        case MMI_MTE_IMAGE_BMP_TO_AB2:
        case MMI_MTE_IMAGE_PNG_TO_AB2:
            gdi_image_type = GDI_IMAGE_TYPE_AB2;
            break;
            
        case MMI_MTE_IMAGE_BMP_TO_AB2_SEQUENCE:
        case MMI_MTE_IMAGE_PNG_TO_AB2_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_AB2_SEQUENCE;
            break;
            
        case MMI_MTE_IMAGE_AB2_SEQUENCE:
            gdi_image_type = GDI_IMAGE_TYPE_AB2_SEQUENCE;
            break;

        case MMI_MTE_IMAGE_9SLICE:
            gdi_image_type = GDI_IMAGE_TYPE_9SLICE;
            break;

        default:
            return GDI_IMAGE_TYPE_INVALID;
    }

    return gdi_image_type;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_image_type_from_gdi_to_mte
 * DESCRIPTION
 *  Converts the GDI image type to the MTE image type.
 * PARAMETERS
 *  gdi_image_type      [IN]    GDI image type
 * RETURNS
 *  MTE image type
 *****************************************************************************/
static mmi_mte_image_enum mmi_mte_translate_image_type_from_gdi_to_mte(U8 gdi_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mte_image_enum mte_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gdi_image_type)
    {
        case GDI_IMAGE_TYPE_GIF:
            mte_image_type = MMI_MTE_IMAGE_GIF;
            break;

        case GDI_IMAGE_TYPE_JPG:
            mte_image_type = MMI_MTE_IMAGE_JPG;
            break;

        case GDI_IMAGE_TYPE_BMP:
            mte_image_type = MMI_MTE_IMAGE_BMP;
            break;

        case GDI_IMAGE_TYPE_PNG:
            mte_image_type = MMI_MTE_IMAGE_PNG;
            break;

        case GDI_IMAGE_TYPE_ABM:
            mte_image_type = MMI_MTE_IMAGE_BMP_TO_ABM;
            break;

        case GDI_IMAGE_TYPE_AB2:
            mte_image_type = MMI_MTE_IMAGE_BMP_TO_AB2;
            break;

        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
            mte_image_type = MMI_MTE_IMAGE_JPG_SEQUENCE;
            break;

        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
            mte_image_type = MMI_MTE_IMAGE_BMP_SEQUENCE;
            break;

        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
            mte_image_type = MMI_MTE_IMAGE_PNG_SEQUENCE;
            break;

        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
            mte_image_type = MMI_MTE_IMAGE_ABM_SEQUENCE;
            break;

        case GDI_IMAGE_TYPE_AB2_SEQUENCE:
            mte_image_type = MMI_MTE_IMAGE_AB2_SEQUENCE;
            break;

        case GDI_IMAGE_TYPE_9SLICE:
            mte_image_type = MMI_MTE_IMAGE_9SLICE;
                break;

        default:
            return MMI_MTE_IMAGE_NONE;
    }

    return mte_image_type;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_sequence_delay
 * DESCRIPTION
 *  Gets the delay of a frame
 * PARAMETERS
 *  img_data_ptr       [IN]     image sequence resource pointer
 *  frame_index        [IN]     frame index
 * RETURNS
 *  Delay time in ms.
 *****************************************************************************/
static U32 mmi_mte_get_image_sequence_delay(PU8 img_data_ptr, S32 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *frame_delay_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frame_delay_ptr = (U32*)(img_data_ptr + 16 + 12 * frame_index);

    return *frame_delay_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_sequence_size
 * DESCRIPTION
 *  Gets the image size of a frame
 * PARAMETERS
 *  img_data_ptr       [IN]     image sequence resource pointer
 *  frame_index        [IN]     frame index
 * RETURNS
 *  Image frame size in bytes.
 *****************************************************************************/
static U32 mmi_mte_get_image_sequence_size(PU8 img_data_ptr, S32 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *frame_size_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    frame_size_ptr = (U32*)(img_data_ptr + 12 + 12 * frame_index);

    return *frame_size_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_sequence_total_size
 * DESCRIPTION
 *  Gets the total size of the image
 * PARAMETERS
 *  img_data_ptr       [IN]     image sequence resource pointer
 * RETURNS
 *  Sequence total size in bytes.
 *****************************************************************************/
static U32 mmi_mte_get_image_sequence_total_size(PU8 img_data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 total_size;
    S32 frame_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_get_image_frame_count((S8*)img_data_ptr, &frame_count);

    /* header and frame info blocks */
    total_size = 8 + 12 * frame_count;

    /* add all frame size together to get the total size */
    for (i = 0; i < frame_count; i++)
    {
        total_size += mmi_mte_get_image_sequence_size(img_data_ptr, i);
    }

    return total_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_info
 * DESCRIPTION
 *  Gets image resource information.
 * PARAMETERS
 *  img_res_ptr          [IN]   image resource pointer
 *  frame_index          [IN]   frame index. -1 means don't care or whole image sequence.
 *  img_data_ptr         [OUT]  image data pointer
 *  mte_image_type       [OUT]  MTE image type
 *  width                [OUT]  width
 *  height               [OUT]  height
 *  size                 [OUT]  size
 *  delay                [OUT]  delay
 *  repeat_count         [OUT]  repeat count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_image_resource_info(char *img_res_ptr, int frame_index, char **img_data_ptr, mmi_mte_image_enum *mte_image_type, int *width, int *height, int *size, int *delay, int *repeat_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 header = (PU8)img_res_ptr;
    MMI_BOOL is_sequence;
    U8  gdi_img_type;
    U32 *frame_offset;
    U32 frame_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_img_type = header[0];

    /* for sequence images, the image data contains the resource header */
    if ((gdi_img_type == GDI_IMAGE_TYPE_JPG_SEQUENCE) || 
        (gdi_img_type == GDI_IMAGE_TYPE_BMP_SEQUENCE) ||
        (gdi_img_type == GDI_IMAGE_TYPE_ABM_SEQUENCE) || 
        (gdi_img_type == GDI_IMAGE_TYPE_PNG_SEQUENCE) ||
        (gdi_img_type == GDI_IMAGE_TYPE_AB2_SEQUENCE))
    {
        is_sequence = MMI_TRUE;
    }
    else
    {
        is_sequence = MMI_FALSE;
    }

    if (is_sequence)
    {
        if (frame_index < 0)
        {
            *img_data_ptr = header;
        }
        else
        {
            frame_count = (U32)header[1];
            frame_offset = (U32*)(header + 8 + 12 * frame_index);
            *img_data_ptr = header + *frame_offset + 12 * frame_count;
        }
    }
    else
    {
        *img_data_ptr = header + 8;
    }        
       
    *mte_image_type = mmi_mte_translate_image_type_from_gdi_to_mte(gdi_img_type);

    /* The image sequence size is not stored in the 8-byte header. Have to calculate it. */
    if (is_sequence)
    {
        if (frame_index < 0)
        {
            *size = mmi_mte_get_image_sequence_total_size(header);
        }
        else
        {
            *size = mmi_mte_get_image_sequence_size(header, frame_index);
        }
    }
    else
    {
        *size = (S32)mmi_mte_get_image_resource_size(header);
    }

    /* get frame delay */
    if (delay)
    {
        if (is_sequence && (frame_index >= 0))
        {
            *delay = mmi_mte_get_image_sequence_delay(header, frame_index);
        }
        else
        {
            *delay = 0;
        }    
    }

    /* get repeat count */
    if (repeat_count)
    {
        if (is_sequence)
        {
            *repeat_count = (S32)header[2];
        }
        else
        {
            *repeat_count = 0;
        }
    }
    
    *width = (header[7] << 4) | (header[6] >> 4);
    *height = ((header[6] & 0xF) << 8) | header[5];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_file_size
 * DESCRIPTION
 *  Get the file size.
 * PARAMETERS
 *  filename       [IN]     filename
 * RETURNS
 *  File size in bytes.
 *****************************************************************************/
static int mmi_mte_get_file_size(char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE    *fp;
    S32     fpos, file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(filename, "rb");   
    if (fp == NULL)
    {
        return 0;
    }
    
    /* save the current file position */
    fpos = ftell(fp);

    /* seek to the EOF */    
    fseek(fp, 0, SEEK_END);

    /* get file size */
    file_size = ftell(fp);

    fclose(fp);

    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_filter_image_type
 * DESCRIPTION
 *  Changes the image type due to some constraints.
 * PARAMETERS
 *  image_type       [IN]   input image type
 *  is_full_screen   [IN]   is full screen
 * RETURNS
 *  Filtered image type.
 *****************************************************************************/
static unsigned int mmi_mte_filter_image_type(unsigned int image_type, MMI_BOOL is_full_screen, MMI_BOOL is_recommend, mmi_mte_theme_component_struct *theme_component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_type & MMI_MTE_IMAGE_9SLICE)
    {
        if (is_recommend)
            image_type = MMI_MTE_IMAGE_9SLICE;
        else
            image_type = MMI_MTE_IMAGE_9SLICE | MMI_MTE_IMAGE_BMP | MMI_MTE_IMAGE_PNG;
    }
    /* discard unsupported image types */
#ifndef GDI_USING_JPEG
//    image_type &= ~MMI_MTE_IMAGE_JPG;
#endif /* GDI_USING_JPEG */

    /* do not use PNG if alpha blending is not supported */
#ifndef __MMI_ALPHA_BLENDING__
    image_type &= ~MMI_MTE_IMAGE_PNG;
    image_type &= ~MMI_MTE_IMAGE_PNG_SEQUENCE;
#endif /* __MMI_ALPHA_BLENDING__ */

#if defined(__MMI_VUI_HOMESCREEN__) && defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    if (!strcmp(theme_component->name, "calendar_idle_bg_image"))
    {
        if (is_recommend)
            image_type = MMI_MTE_IMAGE_BMP;
        else
            image_type &= ~MMI_MTE_IMAGE_PNG;
    }
#endif

    
#ifndef GDI_USING_HW_PNG
    /* do not allow raw PNG, use ABM instead, except HW PNG decoder is available. */
    if (image_type & MMI_MTE_IMAGE_PNG)
    {
        image_type &= ~MMI_MTE_IMAGE_PNG;
        
        /* AB2 is not allowed on 6205, 6223 */
        image_type |= MMI_MTE_IMAGE_PNG_TO_AB2;

        if (!is_recommend)
            image_type |= MMI_MTE_IMAGE_PNG_TO_ABM;
    }

    /* PNG sequence as PNG */
    if (image_type & MMI_MTE_IMAGE_PNG_SEQUENCE)
    {
        image_type &= ~MMI_MTE_IMAGE_PNG_SEQUENCE;
        image_type |= MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE;
    }    
#endif /* GDI_USING_HW_PNG */
#if defined(__CPU_ARM7EJ_S__)
#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X480__) 
    if (is_recommend)
    {
        if (!strcmp(theme_component->name, "main_menu_bkg_filler") ||
            !strcmp(theme_component->name, "sub_menu_bkg_filler") ||
            !strcmp(theme_component->name, "idle_bkg_filler") )
            image_type = MMI_MTE_IMAGE_BMP;
    }
#endif
#endif

    /* use ABM instead of BMP */
    if (image_type & MMI_MTE_IMAGE_BMP)
    {
        image_type &= ~MMI_MTE_IMAGE_BMP;
        image_type |= MMI_MTE_IMAGE_BMP_TO_AB2;
        
        if (!is_recommend)
            image_type |= MMI_MTE_IMAGE_BMP_TO_ABM;
    }

    /* BMP sequence as BMP */
    if (image_type & MMI_MTE_IMAGE_BMP_SEQUENCE)
    {
        image_type &= ~MMI_MTE_IMAGE_BMP_SEQUENCE;
         image_type |= MMI_MTE_IMAGE_BMP_TO_ABM_SEQUENCE;
    }    

    /* If there is no format available, use MMI_MTE_IMAGE_BMP_TO_ABM. */
    if (image_type == MMI_MTE_IMAGE_NONE)
    {
        // TODO: ASSERT here? */
        image_type |= MMI_MTE_IMAGE_BMP_TO_AB2;
        
        if (!is_recommend)
            image_type |= MMI_MTE_IMAGE_BMP_TO_ABM;
    }

    return image_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_make_resource_header
 * DESCRIPTION
 *  Make 8-byte MMI resource header
 * PARAMETERS
 *  header       [IN]   header buffer
 *  type         [IN]   GDI image type
 *  width        [IN]   image width
 *  height       [IN]   image height
 *  size         [IN]   image size
 *  frame_num    [IN]   number of frames
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_make_resource_header(U8 *header, U8 type, S32 width, S32 height, S32 size, S32 frame_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header[0] = type;
    header[1] = frame_num;  /* number of frames */
    header[2] = size & 0xFF;
    header[3] = (size >> 8) & 0xFF;
    header[4] = (size >> 16) & 0xFF;
    header[5] = height & 0xFF;
    header[6] = ((height >> 8) & 0xF) | ((width & 0xF) << 4);
    header[7] = (width >> 4) & 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_image_dimension
 * DESCRIPTION
 *  Get the dimension for an image theme component
 * PARAMETERS
 *  theme_component       [IN]      theme component strucuture
 *  lcd_dimension         [IN]      current LCD dimension
 *  width                 [OUT]     image width
 *  height                [OUT]     image height
 * RETURNS
 *  0: The dimension is undefined.
 *  1: The dimension is defined.
 *****************************************************************************/
static int mmi_mte_get_theme_image_dimension(mmi_mte_theme_component_struct *theme_component, mmi_mte_lcd_dimension_enum lcd_dimension, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *width = theme_component->internal_data.image_dimension[lcd_dimension][0];
    *height = theme_component->internal_data.image_dimension[lcd_dimension][1];
    
    if ((*width == 0) && (*height == 0))
    {
        return 0;
    } 
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_convert_image_layer_to_32
 * DESCRIPTION
 *  Converts the image layer to the 32-bit ARGB output buffer.
 * PARAMETERS
 *  image_layer      [IN]   image layer handle
 *  out_buffer       [OUT]  32-bit output buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_convert_image_layer_to_32(gdi_handle image_layer, U8* out_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         width, height;
    S32         x, y;
    gdi_color   c;
    U32         a, r, g, b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(image_layer);
    gdi_layer_get_dimension(&width, &height);

    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            c = gdi_act_get_pixel(x, y);
            gdi_act_color_to_rgb(&a, &r, &g, &b, c);
            *out_buffer++ = b;
            *out_buffer++ = g;
            *out_buffer++ = r;
            *out_buffer++ = a;
        }
    }

    gdi_layer_pop_and_restore_active();
}


/*
 * MTE RPC
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_to_mte_isr
 * DESCRIPTION
 *  MMI to MTE finish notification ISR
 * PARAMETERS
 *  param1       [IN]   NOT USED
 * RETURNS
 *  NULL
 *****************************************************************************/
static void *mmi_to_mte_isr(void * param1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_UNUSED_PARAMETER(param1);
    
    mte_api_finish_callback();

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mte_to_mmi_hisr
 * DESCRIPTION
 *  MTE to MMI RPC request HISR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mte_to_mmi_hisr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int     *msg;
    static int msg_buf[16];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* copy arguments into local message buffer */
    msg = msg_buf;
    memcpy(msg, g_mte_rpc_msg, sizeof(int) * 16);

    /* send RPC request message to the MMI task */
    SEND_MESSAGE(MOD_IDLE, MOD_MMI, 0, MMI_MTE_MESSAGE_ID, msg, NULL);    
}


/*****************************************************************************
 * FUNCTION
 *  mte_to_mmi_isr
 * DESCRIPTION
 *  MTE to MMI RPC request ISR
 * PARAMETERS
 *  param1       [IN]   NOT USED
 * RETURNS
 *  NULL
 *****************************************************************************/
static void *mte_to_mmi_isr(void * param1, ...)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_UNUSED_PARAMETER(param1);       
    kal_activate_hisr(g_mte_to_mmi_hisr);

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_rpc_handler
 * DESCRIPTION
 *  MMI message handler for MTE RPC.
 * PARAMETERS
 *  msg       [IN]  local message buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_rpc_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int     *args, api_index;
    func_10_int_params_ptr  f10;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn on backlight */
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME); // 1 

    args = (int *)msg;
    api_index = args[0];
    f10 = (func_10_int_params_ptr)g_mmi_mte_function_table[api_index];

    MTE_DEBUG("mmi_mte_rpc_handler RUN JOB %d\n", api_index);
    mmi_mte_ret_value = f10(args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);
  
    /* notify the MTE UI we're finished */
    MTE_DEBUG("mmi_mte_rpc_handler FINISH JOB\n");
    OSC_Activate_ISR(MTE_MMI_TO_MTE_ISR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_rpc_invoker
 * DESCRIPTION
 *  Fills the RPC request structure.
 * PARAMETERS
 *  a0       [IN]   1st argument
 *  a1       [IN]   2nd argument
 *  a2       [IN]   3rd argument
 *  a3       [IN]   4th argument
 *  a4       [IN]   5th argument
 *  a5       [IN]   6th argument
 *  a6       [IN]   7th argument
 *  a7       [IN]   8th argument
 *  a8       [IN]   9th argument
 *  a9       [IN]   10th argument 
 * RETURNS
 *  0
 *****************************************************************************/
static int mmi_mte_rpc_invoker(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    static int msg[16];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg[0] = g_mmi_mte_api_index;
    msg[1] = a0;
    msg[2] = a1;
    msg[3] = a2;
    msg[4] = a3;    
    msg[5] = a4;
    msg[6] = a5;
    msg[7] = a6;
    msg[8] = a7; 
    msg[9] = a8;
    msg[10] = a9;        

    g_mte_rpc_msg = msg;

    MTE_DEBUG("mmi_mte_rpc_invoker REQUEST %d\n", msg[0]);
    
    OSC_Activate_ISR(MTE_MTE_TO_MMI_ISR);
   
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_register_finish_callback
 * DESCRIPTION
 *  Registers the finish callback function by the MTE UI. The callback function
 *  is used internally by MTE, which is actually SetEvent() to let the MTE UI 
 *  thread continue from WaitForSingleObject().
 * PARAMETERS
 *  finish_cb       [IN]    finish callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_register_finish_callback(void (*finish_cb)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mte_api_finish_callback = finish_cb;
}


/*
 * Example Screen
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_component_in_dm_group
 * DESCRIPTION
 *  Checks if the component ID is in the specified DM group.
 * PARAMETERS
 *  component_id       [IN]     MTE theme component ID
 *  dm_group_id        [IN]     Draw Manager group ID
 * RETURNS
 *  0: No.
 *  1: Yes.
 *****************************************************************************/
static int mmi_mte_is_component_in_dm_group(int component_id, int dm_group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int g;
    const mmi_mte_control_set_group_struct  *control_set_group;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    control_set_group = g_mmi_mte_control_set_group + dm_group_id;

    for (g = 0; g < (int)control_set_group->num; g++)
    {
        if (component_id == control_set_group->component_id[g])
        {
            return 1;
        }                    
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_append_control_set
 * DESCRIPTION
 *  Appends the source DM control set to the output control set.
 * PARAMETERS
 *  dst_control_set       [IN]      destination control set pointer
 *  control_set_num       [IN/OUT]  destination control set number
 *  src_control_set       [IN]      source control set pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_append_control_set(U8 *dst_control_set, S32 *control_set_num, U8 *src_control_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(dst_control_set + *control_set_num, src_control_set + 1, src_control_set[0]); 
    *control_set_num += src_control_set[0];    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_component_operation_in_screen_filter
 * DESCRIPTION
 *  Gets the component operation in the screen filter.
 * PARAMETERS
 *  component_id       [IN]     MTE theme component ID
 *  screen_id          [IN]     screen id
 *  category_id        [IN]     category id
 * RETURNS
 *  MMI_MTE_SCREEN_FILTER_COMP_OPERATION_NONE: Not found.
 *  MMI_MTE_SCREEN_FILTER_COMP_OPERATION_ADD: Add operation
 *  MMI_MTE_SCREEN_FILTER_COMP_OPERATION_REMOVE: Remove operation
 *****************************************************************************/
static mmi_mte_screen_filter_comp_operation_enum mmi_mte_get_component_operation_in_screen_filter(S32 component_id, S32 screen_id, S32 category_id)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int filter_category_id, filter_screen_id;
    const mmi_mte_current_screen_filter_struct *filter;
    int filter_component_num;
    const int *filter_component_id;
    int fid;
    int i, f;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (f = 0; f < MMI_MTE_CURRENT_SCREEN_FILTER_NUM; f++)
    {
        filter = &g_mmi_mte_current_screen_filter[f];
        filter_category_id = filter->category_id ? filter->category_id : category_id;
        filter_screen_id = filter->screen_id ? filter->screen_id : screen_id;

        if ((filter_category_id == category_id) && (filter_screen_id == screen_id))
        {
            filter_component_num = filter->component_set.num;
            filter_component_id = filter->component_set.component_id;
            for (i = 0; i < filter_component_num; i++)
            {
                fid = filter_component_id[i];
                if (fid != MMI_MTE_INVALID_FILTER_COMPONENT)
                {
                    if (fid < 0)
                    {   /* remove this component */
                        if (component_id == -fid)
                        {
                            return MMI_MTE_SCREEN_FILTER_COMP_OPERATION_REMOVE;
                        }                        
                    }
                    else
                    {   /* add this component */
                        if (component_id == fid)
                        {
                            return MMI_MTE_SCREEN_FILTER_COMP_OPERATION_ADD;
                        }                        
                    }
                }
            }    

            break;
        }
    }

    return MMI_MTE_SCREEN_FILTER_COMP_OPERATION_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_dummy_function
 * DESCRIPTION
 *  MTE Dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_get_async_items
 * DESCRIPTION
 *  A fake get async menu item callback function for MTE example screens.
 * PARAMETERS
 *  start_index       [IN]  menu item start index
 *  menuData          [IN]  menu item data to be returned
 *  num_item          [IN]  number of items requested
 * RETURNS
 *  The number of returned menu items.
 *****************************************************************************/
static S32 mmi_mte_example_screen_get_async_items(S32 start_index, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; i++)
    {
        for (j = 0; j < FIXED_ICONLIST_MAX_TEXT_COLUMNS; j++)
        {
            menuData[i].item_list[j] = (UI_string_type)GetString(STR_GLOBAL_OK);
        }

        for (j = 0; j < FIXED_ICONLIST_MAX_ICON_COLUMNS; j++)
        {
            menuData[i].image_list[j] = NULL;
        }
    }

    return num_item;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_get_dync_items
 * DESCRIPTION
 *  A fake get async menu item callback function for MTE example screens.
 * PARAMETERS
 *  start_index       [IN]  menu item start index
 *  menuData          [IN]  menu item data to be returned
 *  num_item          [IN]  number of items requested
 * RETURNS
 *  The number of returned menu items.
 *****************************************************************************/
static S32 mmi_mte_example_screen_get_dync_items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S32     i, j;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy((S8*) str_buff, GetString(STR_GLOBAL_OK));
    *img_buff_p = (U8*) GetImage((U16)(IMG_GLOBAL_L1));
	
    return (pBOOL) MMI_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_get_hint_items
 * DESCRIPTION
 *  A fake get async menu item hint callback function for MTE example screens.
 * PARAMETERS
 *  start_index       [IN]
 *  hint_array        [IN]
 * RETURNS
 *  1
 *****************************************************************************/
static S32 mmi_mte_example_screen_get_hint_items(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hint_array[0] = (UI_string_type)GetString(STR_GLOBAL_OK);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_exit_editor
 * DESCRIPTION
 *  Editor example screen exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_exit_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_del_scr_editor
 * DESCRIPTION
 *  Editor example scree delete screen callback
 * PARAMETERS
 *  history_index       [IN]    history index
 * RETURNS
 *  MMI_HIST_ALLOW_DELETING
 *****************************************************************************/
static mmi_ret mmi_mte_example_screen_del_scr_editor(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_EXIT:
    mmi_mte_example_screen_exit_editor();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_screen_editor
 * DESCRIPTION
 *  Editor example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     gui_buffer;
    mmi_imm_input_mode_enum supported_ime[IMM_INPUT_MODE_MAX_NUM];
    mmi_imm_input_mode_enum stroke_ime;
    S32     i, supported_ime_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        mmi_mte_example_screen_exit_editor,
        mmi_mte_example_screen_entry_editor,
        MMI_FRM_FULL_SCRN);
    mmi_frm_scrn_set_leave_proc (GRP_ID_MTE_EXAMPLE, SCR_ID_MTE_EXAMPLE, mmi_mte_example_screen_del_scr_editor);
#endif
    

    /* find stroke ime */
    stroke_ime = IMM_INPUT_MODE_NONE;
    supported_ime_num = mmi_imm_get_system_support_input_mode_list(supported_ime, IMM_INPUT_MODE_MAX_NUM);
    for (i = 0; i < supported_ime_num; i++)
    {
        if ((supported_ime[i] == IMM_INPUT_MODE_TR_STROKE) || (supported_ime[i] == IMM_INPUT_MODE_SM_STROKE) || (supported_ime[i] == IMM_INPUT_MODE_HK_STROKE))
        {
            stroke_ime = supported_ime[i];
            break;
        }
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    if (gui_buffer == NULL)
    {
        mmi_ucs2cpy((S8*)g_mmi_mte_example_screen_buffer, GetString(STR_GLOBAL_OK));

        if (g_mmi_mte_example_screen_editor_is_IME_mode && (stroke_ime != IMM_INPUT_MODE_NONE))
        {
            /* set preferred IME to STROKE to display the most IME theme compoments (stroke_xxx) */
            mmi_imm_set_app_desired_input_mode(stroke_ime);
        }
    }

    ShowCategory5Screen(
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMM_INPUT_TYPE_SENTENCE,
        (U8*)g_mmi_mte_example_screen_buffer,
        100,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_mte_dummy_function, KEY_EVENT_UP);
    
#if 0
/* under construction !*/
#else
    SetCategory5RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif

    /* a hack for IME to keep the IME window displayed when refreshing this screen */
    if (g_mmi_mte_example_screen_editor_is_IME_mode)
    {
        /* must send KEY_2 KEY_UP before the next key is pressed; otherwise the IME will not respond to key events */
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_dialer_launch
 * DESCRIPTION
 *  Dialer example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_dialer_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     gui_buffer;
	static U8 mte_dialer_launch_buffer[84];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_dialer_launch,
        MMI_FRM_FULL_SCRN);
#endif

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory16Screen(
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*)mte_dialer_launch_buffer,
        (sizeof(mte_dialer_launch_buffer) - ENCODING_LENGTH)/ ENCODING_LENGTH,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_mte_dummy_function, KEY_EVENT_UP);
#if 0
/* under construction !*/
#else
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_call
 * DESCRIPTION
 *  Calling example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_call,
        MMI_FRM_FULL_SCRN);
#endif
    
    ShowCategory18Screen(
        0,
        0,
        0,
        STR_GLOBAL_ABORT,
        0, 
        STR_GLOBAL_OK,
        (U8*)L"1234567890",
        0,
        0,
        IMG_GLOBAL_OK,
        NULL,
        FALSE,
        NULL);
    
#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_rotated_popup
 * DESCRIPTION
 *  Rotated popup example screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_rotated_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_rotated_popup,
        MMI_FRM_FULL_SCRN);
#endif

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif /* __MMI_SCREEN_ROTATE__ */

    ShowCategory65Screen((PU8)GetString(STR_GLOBAL_OK), IMG_GLOBAL_INFO, NULL);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_rotated_list
 * DESCRIPTION
 *  Rotated list example screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_rotated_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16     string_list[2] = {STR_GLOBAL_OK, STR_GLOBAL_OK};
    U16     image_list[2] = {IMG_GLOBAL_L1, IMG_GLOBAL_L2};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_rotated_list,
        MMI_FRM_FULL_SCRN);
#endif

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif /* __MMI_SCREEN_ROTATE__ */

    ShowCategory52Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        string_list,
        image_list,
        NULL,
        0,
        0,
        NULL);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_PIN
 * DESCRIPTION
 *  PIN example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_PIN(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_PIN,
        MMI_FRM_FULL_SCRN);
#endif

    mmi_ucs2cpy((S8*)g_mmi_mte_example_screen_buffer, (S8*)L"12");

#if defined __MMI_SMALL_PIN_EDIT_SCREEN__
    enable_resized_small_screen();
#endif 

    ShowCategory111Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        STR_ID_MTE_PIN,
        IMM_INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*)g_mmi_mte_example_screen_buffer,
        4 + 1,
        NULL,
        NULL);

    SetLeftSoftkeyFunction(mmi_mte_dummy_function, KEY_EVENT_UP);
#if 0
/* under construction !*/
#else
    SetCategory111RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_check_list
 * DESCRIPTION
 *  Check list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_check_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 *itemlist[5];
    PU8 ItemListState = (PU8)g_mmi_mte_example_screen_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_check_list,
        MMI_FRM_FULL_SCRN);
#endif

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (PU8)GetString(STR_GLOBAL_OK);
        ItemListState[index] = 0;        
    }

    ItemListState[0] = 1;
    ItemListState[2] = 1;
 
    ShowCategory12Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        itemlist,
        (U8*)ItemListState,
        0,
        NULL);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_multirow_list
 * DESCRIPTION
 *  Multirow list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_multirow_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI__
#ifdef __MMI_MAINLCD_320X480__   
    S32 error;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_multirow_list,
        MMI_FRM_FULL_SCRN);
#endif

    /* display shortcut */
    wgui_reset_disable_shortcut_display();
#ifdef __MMI_MAINLCD_320X480__        

    ShowCategory263Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SUB_MENUS,
        mmi_mte_example_screen_get_async_items,
        mmi_mte_example_screen_get_hint_items,
        0,
        IMG_GLOBAL_OK,
        NULL,
        &error);
#else
    ShowCategory85Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MAX_SUB_MENUS,
        mmi_mte_example_screen_get_async_items,
        mmi_mte_example_screen_get_hint_items,
        0,
        IMG_GLOBAL_OK,
        IMG_GLOBAL_OK,
        IMG_GLOBAL_OK,
        NULL);
#endif

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
#endif /* __COSMOS_MMI__ */
}



/*****************************************************************************
* FUNCTION
*  mmi_mte_toolbar_callback
* DESCRIPTION
*  Call button handler
* PARAMETERS
*  index       [IN]        Message index
* RETURNS
*  void
*****************************************************************************/
void mmi_mte_toolbar_callback(S32 index)
{
	return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_tab_ex
 * DESCRIPTION
 *  Tab list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_tab_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //BOOL    is_list_ready;
   // tab_bar_item_type MMI_tab_bar_items[3];
    
#ifdef __MMI_FTE_SUPPORT__
    S32     i;
    PU8 enable_icons[4];
    PU8 disable_icons[4];
    PU8 hint_string[4];
#endif
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    EntryNewScreen(SCR_ID_MTE_EXAMPLE + 1, NULL, mmi_mte_example_screen_entry_tab_ex, MMI_TAB_PAGE);

    if(!mmi_frm_scrn_tab_page_enter(
        GRP_ID_MTE_EXAMPLE, SCR_ID_MTE_EXAMPLE, SCR_ID_MTE_EXAMPLE + 1, NULL, mmi_mte_example_screen_entry_tab_ex, MMI_FRM_TAB_PAGE))
    {
        return;
    }

//    guiBuffer = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_MTE_EXAMPLE + 1);   
    guiBuffer   = mmi_frm_scrn_tab_page_get_active_gui_buf(); 
#ifdef __MMI_FTE_SUPPORT__
	for (i = 0; i < 4; i++)
	{
		enable_icons[i] = (PU8)GetImage(IMG_GLOBAL_TOOLBAR_CALL);
		disable_icons[i] = (PU8)GetImage(IMG_GLOBAL_TOOLBAR_CALL_DISABLED);
		hint_string[i] = (PU8)GetString(STR_GLOBAL_DIAL);
	}
	wgui_icon_bar_setup(
        3,
        enable_icons,
        disable_icons,
        hint_string,
        mmi_mte_toolbar_callback);
#endif
    ShowCategory629Screen(
        (U16)GetString(STR_GLOBAL_OK),//PU8
        (U16)NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_mmi_mte_example_screen_tab_num,
        (GetItemFuncPtr)mmi_mte_example_screen_get_dync_items,
        (GetHintFuncPtr)mmi_mte_example_screen_get_hint_items,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


void mmi_mte_example_screen_entry_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct tab_pages_info_array[1];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_pages_info_array[0].screen_id = SCR_ID_MTE_EXAMPLE + 1;
    tab_pages_info_array[0].tab_entry_func = mmi_mte_example_screen_entry_tab_ex;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    
	
//	  mmi_frm_set_first_sel_page(0);
//    mmi_frm_general_tab_entry(SCR_ID_MTE_EXAMPLE, mmi_mte_example_screen_entry_tab, tab_pages_info_array, 1);

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_frm_scrn_tab_enter(GRP_ID_MTE_EXAMPLE, SCR_ID_MTE_EXAMPLE,NULL,mmi_mte_example_screen_entry_tab,
        tab_pages_info_array,1,0);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_twoline_list
 * DESCRIPTION
 *  Two-line list example screen entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_twoline_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8     string_list[12];
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_twoline_list,
        MMI_FRM_FULL_SCRN);
#endif
    
    for (i = 0; i < 12; i++)
    {
         string_list[i] = (PU8)GetString(STR_GLOBAL_OK);
    }
    
    ShowCategory354Screen(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_OK,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        12,
        string_list,
        string_list,
        (PU16)gIndexIconsImageList,
        0,
        NULL);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_popup
 * DESCRIPTION
 *  Popup screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_popup,
        MMI_FRM_FULL_SCRN);
#endif
    
    ShowCategory165Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        get_string(STR_GLOBAL_OK),
        IMG_GLOBAL_WARNING,
        10,
        NULL);
        
    SetCat165TimerExpireFunc(mmi_mte_dummy_function);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


#ifdef __MMI_SMALL_LIST_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_small_list
 * DESCRIPTION
 *  Small list entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_small_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 str_list[6], icon_list[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_small_list,
        MMI_FRM_FULL_SCRN);
#endif

    for (i = 0; i < 6; i++)
    {
        str_list[i] = STR_GLOBAL_1 + i;
        icon_list[i] = IMG_GLOBAL_L1 + i;
    }

    ShowCategory10Screen(
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        6,
        str_list,
        icon_list,
        0,
        NULL);
        
#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


#endif /* __MMI_SMALL_LIST_SCREEN__ */


#ifdef __MMI_CASCADE_MENU__

static mmi_ret mmi_mte_post_show_cascading_menu(mmi_event_struct *evt)
{
    gdi_layer_clear(GDI_COLOR_WHITE); 

    // TODO: should use a test menu resource
    mmi_cascading_register_rsk_handler(mmi_idle_display);

    DisplayCascadingMenu(IDLE_SCREEN_MENU_ID, NULL);
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_cascade_menu
 * DESCRIPTION
 *  Cascading menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_cascade_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: should use a test menu resource
    //SetMenuItemDimmed(GetSeqItemId_Ext(IDLE_SCREEN_MENU_ID, 0), MMI_TRUE);
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_cascade_menu,
        MMI_FRM_FULL_SCRN);
#endif
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        mmi_frm_post_event(&evt, mmi_mte_post_show_cascading_menu, NULL);
    }
    SetRightSoftkeyFunction(mmi_idle_display, KEY_EVENT_UP);
}


#endif /* __MMI_CASCADE_MENU__ */

#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_media_player
 * DESCRIPTION
 *  Cascading menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_media_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // TODO: should use a test menu resource
    mmi_medply_app_entry_mscr();
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_example_main_menu_style
 * DESCRIPTION
 *  Sets the main menu style.
 * PARAMETERS
 *  style       [IN]    main menu style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_set_example_main_menu_style(U8 style)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    extern PHNSET_CNTX *g_phnset_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_phnset_cntx_p->MenuStyle = style;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */
}


static const U8 *MTESymbolPickerSymbols[34] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    /* (U8*)"\xa2\0\0", */
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0"
    /* (U8*)" \0\0", */
};
/*****************************************************************************
 * FUNCTION
 *  mmi_mte_example_screen_entry_symbol_picker
 * DESCRIPTION
 *  Symbol picker entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_example_screen_entry_symbol_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__	
    MMI_BOOL        freeze_state;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifdef __MMI_VUI_ENGINE__
    freeze_state = gdi_lcd_get_freeze();
    gdi_lcd_freeze(TRUE);
#else    
    gdi_layer_lock_frame_buffer();
#endif
#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE,
        NULL,
        mmi_mte_example_screen_entry_symbol_picker,
        MMI_FRM_FULL_SCRN);
#endif
    //mmi_imm_set_required_mode_list(IMM_INPUT_TYPE_SENTENCE, NULL, IMM_INPUT_MODE_NONE); 
    
    /* The following code is from EntrySymbolPickerScreenFromMenuList(). */
    ShowCategory22Screen(
        STR_GLOBAL_DEFAULT,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        34,
        (U8**)MTESymbolPickerSymbols,
        0,
        NULL);

#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
    /* 
     * clear LSK to prevent calling the symbol picker default LSK handler,
     * which will insert the selected symbol into the non-existence input box.
     */     
    ChangeLeftSoftkey(0, 0);             
    clear_left_softkey(); 
#ifdef __MMI_VUI_ENGINE__
    gdi_lcd_freeze(freeze_state);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (vadp_p2v_uc_is_in_venus())
    {
        // Refresh screen for venus screen(vrt will be suspended).
        mmi_mte_refresh_screen(MMI_MTE_LCD_TYPE_MAIN);
    }
#else    
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_search_dm_group_in_control_set
 * DESCRIPTION
 *  Searchs a DM group id in the control set.
 * PARAMETERS
 *  group_id                [IN]    DM group ID
 *  local_control_set       [IN]    control set
 *  control_set_num         [IN]    number of DM groups in the control set
 * RETURNS
 *  Index if found, otherwise -1.
 *****************************************************************************/
static S32 mmi_mte_search_dm_group_in_control_set(S32 group_id, U8 *local_control_set, S32 control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < control_set_num; i++)
    {
        if (local_control_set[i] == group_id)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_remove_dm_group_in_control_set
 * DESCRIPTION
 *  Removes a specified group id in the control set.
 * PARAMETERS
 *  group_id                [IN]    DM group ID
 *  local_control_set       [IN]    control set
 *  control_set_num         [IN]    number of DM groups in the control set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_remove_dm_group_in_control_set(S32 group_id, U8 *local_control_set, S32 control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_mte_search_dm_group_in_control_set(group_id, local_control_set, control_set_num);

    if (i == -1)
    {
        return;
    }

    /* remove the group by replacing it by a dummy ID */
    local_control_set[i] = DM_BASE_LAYER_START;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_process_dm_group_in_filter
 * DESCRIPTION
 *  Discard or insert DM groups in the control set.
 * PARAMETERS
 *  screen_id               [IN]        current screen ID
 *  category_id             [IN]        current category ID
 *  local_control_set       [IN]        control set
 *  control_set_num         [IN/OUT]    number of DM groups in the control set
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_process_dm_group_in_filter(S32 screen_id, S32 category_id, U8 *local_control_set, S32 *control_set_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 filter_category_id, filter_screen_id;
    const mmi_mte_current_screen_filter_struct *filter;
    S32 discard_num;
    const int *discard_component_id;
    S32 i,  f;//j,
    S32 dm_group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (f = 0; f < MMI_MTE_CURRENT_SCREEN_FILTER_NUM; f++)
    {
        filter = &g_mmi_mte_current_screen_filter[f];
        filter_category_id = filter->category_id ? filter->category_id : category_id;
        filter_screen_id = filter->screen_id ? filter->screen_id : screen_id;

        if ((filter_category_id == category_id) && (filter_screen_id == screen_id))
        {
            discard_num = filter->discard_dm.num;
            discard_component_id = filter->discard_dm.dm_group_id;
            for (i = 0; i < discard_num; i++)
            {
                dm_group_id = discard_component_id[i];
                if (dm_group_id >= 0)
                {   /* remove the dm group id */
                    mmi_mte_remove_dm_group_in_control_set(dm_group_id, local_control_set, *control_set_num); 
                }
                else
                {   /* add the dm group (use minus) */
                    local_control_set[(*control_set_num)++] = -dm_group_id;
                }
            }

            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_control_coordinate_flag
 * DESCRIPTION
 *  Gets the category coordinate flag of a control.
 * PARAMETERS
 *  category_id       [IN]  category id
 *  control_id        [IN]  control id
 * RETURNS
 *  Coordinate flag
 *****************************************************************************/
static S32 mmi_mte_get_control_coordinate_flag(S32 category_id, mmi_dm_control_ids_enum control_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_coordinates coordinate;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    coordinate.Flags = 0;
    dm_get_control_coordinates_from_category(
        -1,
        category_id,
        control_id,
        -1,
        &coordinate);
        
    return coordinate.Flags;
}    


/*
 * Image Resource Replacement
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_search_resource_mapping_table_by_id
 * DESCRIPTION
 *  Get the index in the resource mapping table by a resource ID.
 * PARAMETERS
 *  id       [IN]   image resource ID
 * RETURNS
 *  -1: Not found.
 *  Others: Index.
 *****************************************************************************/
static int mmi_mte_search_resource_mapping_table_by_id(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_mte_resource_mapping_table_count; i++)
    {
        if (g_mmi_mte_res_map_table[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_size
 * DESCRIPTION
 *  Get the image resource size.
 * PARAMETERS
 *  res_ptr       [IN]  MMI image resource pointer
 * RETURNS
 *  Image resource size. (not including the 8-byte resource header)
 *****************************************************************************/
static U32 mmi_mte_get_image_resource_size(U8 *res_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return res_ptr[2] | (res_ptr[3] << 8) | (res_ptr[4] << 16);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_free_res_mapping_table
 * DESCRIPTION
 *  Free the resource mapping table.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_free_res_mapping_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_mte_resource_mapping_table_count; i++)
    {
        if (g_mmi_mte_res_map_table[i].buf)
        {
            MTE_FREE(g_mmi_mte_res_map_table[i].buf);
            g_mmi_mte_res_map_table[i].buf = NULL;
        }
    }

    g_mmi_mte_resource_mapping_table_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_allocate_image_buffer
 * DESCRIPTION
 *  Allocates the image buffer with the optional initialization data. 
 * PARAMETERS
 *  size            [IN]    size in bytes
 *  init_data       [IN]    initialization data
 * RETURNS
 *  Allocated memory pointer.
 *****************************************************************************/
static U8 *mmi_mte_allocate_image_buffer(U32 size, U8 *init_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*     alloc_buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((alloc_buf = (U8*)MTE_ALLOC(size)) == NULL)
    {
        return NULL;
    }
    
    if (init_data)
    {
        memcpy(alloc_buf, init_data, size);
    }

    return alloc_buf;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_read_file_into_buffer
 * DESCRIPTION
 *  Read a file into the memory
 * PARAMETERS
 *  filename         [IN]   filename
 *  buffer           [IN]   buffer pointer
 *  buffer_len       [IN]   buffer size
 *  read_bytes       [OUT]  file size
 * RETURNS
 *  0: Success.
 *  1: Error.
 *****************************************************************************/
static int mmi_mte_read_file_into_buffer(S8 *filename, U8 *buffer, S32 buffer_len, S32 *read_bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE    *fp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        return 1;
    }

    /* The 8-byte header space is already reserved in the buffer. */
    *read_bytes = fread(buffer, 1, buffer_len, fp);
    
    fclose(fp);  

    /* error out if the file is not properly loaded into the buffer */
    if ((*read_bytes == 0) || (mmi_mte_get_file_size(filename) != *read_bytes))
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_file_exist
 * DESCRIPTION
 *  Checks if a file exists.
 * PARAMETERS
 *  file_path       [IN]    file path
 * RETURNS
 *  MMI_TRUE if yes; otherwise MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_mte_is_file_exist(S8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fp = fopen(file_path, "rb"))
    {
        fclose(fp);
    
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_load_image_resource_from_file
 * DESCRIPTION
 *  Convert an image from file to image resource (add a 8-byte resource header)
 * PARAMETERS
 *  filename       [IN]     image filename
 *  resource_size  [OUT]    resource size in bytes
 * RETURNS
 *  0: Success. 
 *  1: Failure.
 *****************************************************************************/
static int mmi_mte_load_image_resource_from_file(S8 *filename, S32 *resource_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     read_bytes;
    U16     image_type;
    U8      *image_data;
    S32     width, height;
    S32     mte_image_type;
 //   S8      command_line_str[MMI_MTE_MAX_PATH_LEN];
 //   S8      abm_exe_path[MMI_MTE_MAX_PATH_LEN];
 //   S8      temp_filename[MMI_MTE_MAX_PATH_LEN];
    mmi_mte_abm_encoder_error_enum  ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cannot load EMS BMP files in EMS_IMAGE_PATH. */   
    if (mmi_mte_is_ems_image(filename))
    {
        return 1;
    }

    /* reserve the 8-byte header in the beginning */
    image_data = (U8*)g_mmi_mte_image_buffer + 8;
    *resource_size = 0;
    
    if (mmi_mte_read_file_into_buffer(filename, image_data, MMI_MTE_MAX_IMAGE_RESOURCE_SIZE - 8, &read_bytes))
    {
        return 1;
    }

    image_type = gdi_image_get_type_from_mem(image_data);

    /* map image type to MTE definition */
    switch (image_type)
    {
        case GDI_IMAGE_TYPE_GIF:
            mte_image_type = MMI_MTE_IMAGE_GIF;
            break;

        case GDI_IMAGE_TYPE_JPG:
            mte_image_type = MMI_MTE_IMAGE_JPG;
            break;

        case GDI_IMAGE_TYPE_BMP:
            mte_image_type = MMI_MTE_IMAGE_BMP;
            break;

        case GDI_IMAGE_TYPE_PNG:
            mte_image_type = MMI_MTE_IMAGE_PNG;
            break;

        case GDI_IMAGE_TYPE_9SLICE:
            mte_image_type = MMI_MTE_IMAGE_9SLICE;
            break;

        default:
            return 1;
    }

    /* convert PNG to ABM */
    if (image_type == GDI_IMAGE_TYPE_PNG)
    {
        read_bytes = MMI_MTE_MAX_IMAGE_RESOURCE_SIZE - 8;

        ret = mmi_mte_encode_abm_image(MMI_MTE_ABMENC_MODE_OUTPUT_MEM, MMI_MTE_IMAGE_PNG_TO_AB2, filename, image_data, &read_bytes);
        if (ret == MMI_MTE_ABMENC_NO_ERROR)
        {
            image_type = GDI_IMAGE_TYPE_ABM;
            mte_image_type = MMI_MTE_IMAGE_PNG_TO_ABM;
        }
        else if (ret == MMI_MTE_AB2ENC_NO_ERROR)
        {
            image_type = GDI_IMAGE_TYPE_AB2;
            mte_image_type = MMI_MTE_IMAGE_PNG_TO_AB2;
        }
        else
            return 1;
    }

    /* make the resource header */
    mmi_mte_get_image_dimension(mte_image_type, image_data, &width, &height);
    mmi_mte_make_resource_header((U8*)g_mmi_mte_image_buffer, (U8)image_type, width, height, read_bytes, 1);
    *resource_size = read_bytes + 8;
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_check_theme
 * DESCRIPTION
 *  Checks and makes the report of the MMI theme.
 * PARAMETERS
 *  mmi_theme       [IN]    MMI theme
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_check_theme(MMI_theme *mmi_theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    mmi_mte_theme_component_struct *c;
    void    *theme_data_address;
    U32     data_ptr;
    UI_filled_area *filler;
    UI_font_type   font;
    PU8     image;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MTE_DEBUG("\n");

    for (i = 0; i < mmi_mte_get_theme_component_num(); i++)
    {
        /* The theme component info structure is actually non-constant. */
        c = (mmi_mte_theme_component_struct*)mmi_mte_get_theme_component(i);
        theme_data_address = mmi_mte_translate_theme_component_data_pointer(c, mmi_theme);
        data_ptr = *((U32*)theme_data_address);

        filler = (UI_filled_area*)data_ptr;
        font = (UI_font_type)data_ptr;
        image = (PU8)data_ptr;
        
        switch (c->type)
        {
            case MMI_MTE_THEME_DATA_TYPE_FILLER:
                /* override filler allow NULL */
                if (filler == NULL)
                {
                    if (!(c->filler_flag & MMI_MTE_FILLER_ALLOW_NULL))
                    {
                        MTE_DEBUG("[MTE] %s filler allow null inconsistency.\n", c->name);
                    }

                    c->filler_flag |= MMI_MTE_FILLER_ALLOW_NULL;
                }
                
                /* override filler allow single border */                
                if (filler && (filler->flags & UI_FILLED_AREA_SINGLE_BORDER))
                {
                    if (!(c->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
                    {
                        MTE_DEBUG("[MTE] %s filler allow border inconsistency.\n", c->name);
                    }

                    // TODO: remove me
                    // c->filler_flag |= MMI_MTE_FILLER_ALLOW_BORDER;
                }                
                break;

            case MMI_MTE_THEME_DATA_TYPE_FONT:
                /* check non-system font */                
                if (font)
                {
                    if (mmi_mte_translate_font_pointer(font) == MMI_MTE_FONT_TYPE_UNDEF)
                    {
                        MTE_DEBUG("Theme compoent %s has an invalid font type.\n", c->name);
                    }
                }            
                break;

            default:
                break;
        }            
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_to_lower_string
 * DESCRIPTION
 *  Converts a string to the lower case.
 * PARAMETERS
 *  str_in        [IN]  input string
 *  str_out       [IN]  output string
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_to_lower_string(S8 *str_in, S8 *str_out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8      c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do 
    {   
        c = *str_in++;
        *str_out++ = tolower(c);
    } while (c);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_ems_image
 * DESCRIPTION
 *  Checks if the image file is an EMS image.
 * PARAMETERS
 *  filename       [IN]     image filename
 * RETURNS
 *  MMI_TRUE if yes; otherwise, MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL mmi_mte_is_ems_image(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8      lowercase_filename[MMI_MTE_MAX_PATH_LEN];    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_to_lower_string(filename, lowercase_filename);

    if (strstr(lowercase_filename, "mainlcd\\sms\\pic"))
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*
 * MTE UI API
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_init
 * DESCRIPTION
 *  MTE initialization in MMI side
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, theme_num;
    const MMI_theme *theme_list[MMI_MTE_MAX_THEME_NUMBER];
    const char *theme_name_list[MMI_MTE_MAX_THEME_NUMBER];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set the MTE RPC handler as the handler. */
    SetProtocolEventHandler(mmi_mte_rpc_handler, MMI_MTE_MESSAGE_ID);

    /* register ISRs for MTE RPC */
    OSC_Register_ISR(MTE_MMI_TO_MTE_ISR, mmi_to_mte_isr);
    OSC_Register_ISR(MTE_MTE_TO_MMI_ISR, mte_to_mmi_isr);

    g_mte_to_mmi_hisr = kal_init_hisr(MTE_TO_MMI_HISR);

    /* check all system themes */
    theme_num = mmi_mte_get_system_theme_data(MMI_MTE_MAX_THEME_NUMBER, theme_list, theme_name_list);
    for (i = 0; i < theme_num; i++)
    {
        mmi_mte_check_theme((MMI_theme*)theme_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  w32_mmi_mte_api
 * DESCRIPTION
 *  The function returns the function pointer of a specified api_index.
 *  NOTE: THIS FUNCTION SHALL NOT BE USED BY MTE UI.
 * PARAMETERS
 *  api_index       [IN]    API index
 * RETURNS
 *  A function pointer of MTE API.
 *****************************************************************************/
void (*w32_mmi_mte_api(int api_index))(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_api_index = api_index;

    if (api_index == MMI_MTE_RPC_REGISTER_FINISH_CALLBACK_API_INDEX)
    {
        return (void_func_ptr)mmi_mte_register_finish_callback;
    } 
    else if (api_index == MMI_MTE_RPC_GET_RETURN_VALUE_API_INDEX)
    {
        return (void_func_ptr)mmi_mte_ret_value;
    }

    /* Do RPC only for necessary APIs for better performance. */
    for (i = 0; i < MMI_MTE_API_NEED_SYNC_NUM; i++)
    {
        if (mmi_mte_api_need_sync_index[i] == api_index)
        {
            return (void_func_ptr)mmi_mte_rpc_invoker;
        }
    }

    return (void_func_ptr)g_mmi_mte_function_table[api_index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_baseband_chip
 * DESCRIPTION
 *  The function returns the current baseband chip name string.
 * PARAMETERS
 *  void
 * RETURNS
 *  BB chip name ASCII string.
 *****************************************************************************/
const char *mmi_mte_get_baseband_chip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * release_bb_chip() in init.c is not available in MoDIS. So, just do it directly.
     * The available chip names are from option.mak.
     */
#if defined(__CPU_ARM7EJ_S__)
        return "ARM7EJ";
#elif defined(__CPU_ARM9EJ_S__)
        return "ARM9EJ";
#elif defined(__CPU_ARM7TDMI__)
        return "ARM7TDMI";
#elif defined(__CPU_ARM1176JZ_S__)
        return "ARM1176JZ";
#else
        return "UNKNOWN";
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_lcd_resolution
 * DESCRIPTION
 *  Get the LCD width and height.
 * PARAMETERS
 *  lcd_type       [IN]     lcd type. main lcd: MMI_MTE_LCD_TYPE_MAIN, sub lcd: MMI_MTE_LCD_TYPE_SUB
 *  width          [OUT]    lcd width     
 *  height         [OUT]    lcd height
 * RETURNS
 *  0: success, 1: failure (e.g. The sublcd is not avaialable.)
 *****************************************************************************/
int mmi_mte_get_lcd_resolution(mmi_mte_lcd_type_enum lcd_type, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_type == MMI_MTE_LCD_TYPE_MAIN)
    {
        *width = GDI_LCD_WIDTH;
        *height = GDI_LCD_HEIGHT;

        return 0;
    }
#ifdef __MMI_SUBLCD__
    else
    {
        *width = GDI_SUBLCD_WIDTH;
        *height = GDI_SUBLCD_HEIGHT;        
    
        return  0;
    }
#endif /* __MMI_SUBLCD__ */        

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_symbol_info
 * DESCRIPTION
 *  The function returns the symbol string of a specified theme component. 
 * PARAMETERS
 *  theme_component       [IN]  pointer to a theme component structure
 * RETURNS
 *  Symbol ASCII string.
 *****************************************************************************/
const char *mmi_mte_get_theme_component_symbol_info(const mmi_mte_theme_component_struct *theme_component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return theme_component->internal_data.symbol_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_font_pointer
 * DESCRIPTION
 *  Translate from a UI_font_type pointer to predefined font type.
 * PARAMETERS
 *  font_ptr       [IN]     font pointer
 * RETURNS
 *  Recognized font type.
 *****************************************************************************/
mmi_mte_theme_font_data_type_enum mmi_mte_translate_font_pointer(UI_font_type font_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MTE_FONT_TYPE_NUM; i++)
    {
        if (g_mmi_mte_font[i].ptr == font_ptr)
        {
            return i;
        }
    }

    return MMI_MTE_FONT_TYPE_UNDEF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_font_symbol
 * DESCRIPTION
 *  Provide font symbol name suitable to print on ThemeRes.c.
 * PARAMETERS
 *  font_type       [IN]        font type
 * RETURNS
 *  Font symbol name in ASCII. NULL if undefined.
 *****************************************************************************/
const char *mmi_mte_get_font_symbol(mmi_mte_theme_font_data_type_enum font_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (font_type >= MMI_MTE_FONT_TYPE_NUM)
    {
        return NULL;
    }    
    
    return g_mmi_mte_font[font_type].name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_image_info
 * DESCRIPTION
 *  The function returns the input image type of a specified theme component. 
 * PARAMETERS
 *  theme_component            [IN]     pointer to a theme component structure
 *  recommend_width            [OUT]    recommended image width. If it equals to 0, there is no recommendation.
 *  recommend_height           [OUT]    recommended image height. If it equals to 0, there is no recommendation.
 *  max_width                  [OUT]    max image width
 *  max_height                 [OUT]    max image height
 *  allowed_image_type         [OUT]    a flag union to identify supported input image formats. (bitwise ORed)
 *  recommend_image_type       [OUT]    recommended image type. At most one image type is recommended. If there is not special recommendation, it may returns MMI_MTE_IMAGE_NONE.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_theme_component_image_info(mmi_mte_theme_component_struct *theme_component, int *recommend_width, int *recommend_height, int *max_width, int *max_height, unsigned int *allowed_image_type, mmi_mte_image_enum *recommend_image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int             lcd_width, lcd_height;
    unsigned int    selectable_image_type;
    int             iw, ih;
    MMI_BOOL        is_full_screen;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the theme component does not contain images, return none. */
    if (theme_component->internal_data.image_type == MMI_MTE_IMAGE_NONE)
    {
        *allowed_image_type = MMI_MTE_IMAGE_NONE;
        *recommend_image_type = MMI_MTE_IMAGE_NONE;
        
        return;
    }
    
    mmi_mte_get_lcd_resolution(theme_component->lcd_type, &lcd_width, &lcd_height);        
    
    *max_width = lcd_width;
    *max_height = lcd_height; 
    
    if (!mmi_mte_get_theme_image_dimension(theme_component, MTE_CURRENT_LCD_RES, &iw, &ih) && 
        !mmi_mte_get_theme_image_dimension(theme_component, MMI_MTE_LCD_DEFAULT, &iw, &ih))
    {
        *recommend_width = 0;
        *recommend_height = 0;        
    }            
    else
    {
        *recommend_width = iw;
        *recommend_height = ih;
        *max_width = iw;
        *max_height = ih;
    }        
    
    if (lcd_width * lcd_height == iw * ih)
    {
        is_full_screen = MMI_TRUE;
    }
    else
    {
        is_full_screen = MMI_FALSE;
    }    

    /* allowed image types */
    selectable_image_type = theme_component->internal_data.image_type;
    selectable_image_type = mmi_mte_filter_image_type(selectable_image_type & 0xFFFF, is_full_screen, MMI_FALSE, theme_component);    
    *allowed_image_type = selectable_image_type;

    /* recommended image type out of allowed ones */
    *recommend_image_type = mmi_mte_filter_image_type(theme_component->internal_data.image_type >> 16, is_full_screen, MMI_TRUE, theme_component);
    *allowed_image_type |= *recommend_image_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_info_string
 * DESCRIPTION
 *  Return NULL or a recommended warning/information string when choosing a certain image type.
 * PARAMETERS
 *  image_type       [IN]   image type
 * RETURNS
 *  A hint string for a specified image type in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_image_info_string(mmi_mte_image_enum image_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* HAVE TO sync with gui_image_query_cache_type() */

    return (const char *)L"";
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_dimension
 * DESCRIPTION
 *  Get image width and height.
 * PARAMETERS
 *  image_type       [IN]   input image type
 *  image_data       [IN]   input image data
 *  width            [OUT]  input image width
 *  height           [OUT]  input image height
 * RETURNS
 *  0: success, 1: failure
 *****************************************************************************/
int mmi_mte_get_image_dimension(mmi_mte_image_enum image_type, char *image_data, int *width, int *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT  ret;
    U8          input_image_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    input_image_type = mmi_mte_translate_image_type_from_mte_to_gdi(image_type);

    if (input_image_type == GDI_IMAGE_TYPE_INVALID)
    {
        return 1;
    }
    
    ret = gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_MEMORY,
            image_data,
            input_image_type,
            MMI_MTE_MAX_IMAGE_RESOURCE_SIZE,
            width,
            height,
            0);

    if (ret == GDI_SUCCEED)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_image_finish_callback
 * DESCRIPTION
 *  GDI image frame finish callback
 * PARAMETERS
 *  result      [IN]    GDI result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_image_finish_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* convert the image layer to 32-bit output buffer */
    mmi_mte_convert_image_layer_to_32(g_mmi_mte_image_layer_handle, g_mmi_mte_output_buffer);

    if (g_mmi_mte_image_frame_finish_callback)
    {
        g_mmi_mte_image_frame_finish_callback((char*)g_mmi_mte_output_buffer, g_mmi_mte_output_image_width, g_mmi_mte_output_image_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_start_decode_image
 * DESCRIPTION
 *  Decode an image to the output buffer. The pixel format of the output buffer is ARGB8888. 
 *  Although resizing is supported here, it is NOT recommended to do resizing since the GDI 
 *  resizing quality is not good. Moreover, some image decoders do not support resizing.
 * PARAMETERS
 *  image_type                  [IN]    input image type
 *  image_data                  [IN]    The memory space for the string pointer array is allocated by the caller. It should be 4-byte aligned.
 *  image_size                  [IN]    input image size
 *  output_buffer               [OUT]   output buffer. It should be 4-byte aligned.
 *  output_buffer_size          [IN]    output buffer size (output_image_width * output_image_height * 4)
 *  output_image_width          [IN]    output image width
 *  output_image_height         [IN]    output image height
 *  frame_finish_callback       [IN]    frame finish callback function. If this callback is not NULL, it is invoked after each frame is decoded. For example, MTE can bitblt out the decoded buffer in this callback for GIF animation.
 *  start_frame                 [IN]    start frame index
 * RETURNS
 *  0: Success.
 *  1: Decoder error.
 *****************************************************************************/
mmi_mte_return_code_enum mmi_mte_start_decode_image(mmi_mte_image_enum image_type, char *image_data, int image_size, char *output_buffer, unsigned int output_buffer_size, int output_image_width, int output_image_height, void (*frame_finish_callback)(char *output_buffer, int output_image_width, int output_image_height), int start_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT      ret;
    U8              input_image_type;
//    S32             frame_num;
    gdi_handle      old_src_layer;
#ifdef __MMI_VUI_ENGINE__	
    MMI_BOOL        freeze_state;   
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = GDI_FAILED;
    
    g_mmi_mte_output_buffer = (U8*)output_buffer;
    
    mmi_mte_stop_decode_image();

    /* free the layer if it was created */
    if (g_mmi_mte_image_layer_handle > 0)
    {
        gdi_layer_free(g_mmi_mte_image_layer_handle);
        g_mmi_mte_image_layer_handle = GDI_NULL_HANDLE;
    }

    /* pass too large images */
    if (output_image_width * output_image_height * 4 > MMI_MTE_MAX_IMAGE_RESOURCE_SIZE)
    {
        return MMI_MTE_ERROR;
    }

    /* image output layer */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        output_image_width,
        output_image_height,
        &g_mmi_mte_image_layer_handle,
        (kal_uint8*)g_mmi_mte_image_layer_buffer,
        MMI_MTE_MAX_IMAGE_RESOURCE_SIZE);        

#ifdef __MMI_VUI_ENGINE__
    freeze_state = gdi_lcd_get_freeze();
    gdi_lcd_freeze(TRUE);
#else
    gdi_layer_lock_frame_buffer();
#endif
    gdi_layer_push_and_set_active(g_mmi_mte_image_layer_handle);
    /* fill white background for ALPHA images, such as PNG and ABM. */
    gdi_layer_clear(GDI_COLOR_WHITE);

    g_mmi_mte_image_frame_finish_callback = frame_finish_callback;

    if (frame_finish_callback)
    {
        gdi_anim_set_blt_after_callback(mmi_mte_image_finish_callback);
    }

    input_image_type = mmi_mte_translate_image_type_from_mte_to_gdi(image_type);

    old_src_layer = gdi_set_alpha_blending_source_layer(g_mmi_mte_image_layer_handle);

    if (input_image_type == GDI_IMAGE_TYPE_BMP)
    {
        /* 
         * The BMP decoder does not use the first palette color as the transparent color if the BMP is from memory. 
         * Use gdi_image_codec_draw() to decode the BMP as resource.
         */
        ret = gdi_image_codec_draw(
                GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER,
                (U8*)image_data,
                GDI_IMAGE_TYPE_BMP,
                image_size,
                0,
                0,
                0,
                0,
                0,
                0);        
    }
    else if ((input_image_type == GDI_IMAGE_TYPE_JPG_SEQUENCE) || 
             (input_image_type == GDI_IMAGE_TYPE_BMP_SEQUENCE) ||
             (input_image_type == GDI_IMAGE_TYPE_ABM_SEQUENCE) || 
             (input_image_type == GDI_IMAGE_TYPE_PNG_SEQUENCE) ||
             (input_image_type == GDI_IMAGE_TYPE_AB2_SEQUENCE))
    {
        /* The image sequence has a resource header. */
        ret = gdi_anim_draw_frames(0, 0, (U8*)image_data, &g_mmi_mte_anim_handle, start_frame);
    }
    else
    {
        /* The normal image does not have a resource header. */
        ret = gdi_anim_draw_mem_frames(0, 0, (U8*)image_data, input_image_type, image_size, &g_mmi_mte_anim_handle, start_frame);
    }
    
    gdi_set_alpha_blending_source_layer(old_src_layer);

    gdi_layer_pop_and_restore_active();
#ifdef __MMI_VUI_ENGINE__
    gdi_lcd_freeze(freeze_state);
#else
    gdi_layer_unlock_frame_buffer();
#endif
    
    if (ret < 0)
    {
        return MMI_MTE_ERROR;
    }

    /* convert the image layer to 32-bit output buffer */
    mmi_mte_convert_image_layer_to_32(g_mmi_mte_image_layer_handle, g_mmi_mte_output_buffer);
 
    return MMI_MTE_SUCCESS;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_stop_decode_image
 * DESCRIPTION
 *  Stop GIF animation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_stop_decode_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_anim_handle > 0)
    {
        gdi_anim_stop(g_mmi_mte_anim_handle);
    }

    g_mmi_mte_anim_handle = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_schema_version
 * DESCRIPTION
 *  The function returns the MTE version information.
 * PARAMETERS
 *  major_verno       [IN]  major version number
 *  minor_verno       [IN]  minor version number
 * RETURNS
 *  The MTE version string.
 *****************************************************************************/
const char *mmi_mte_get_theme_schema_version(int *major_verno, int *minor_verno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* increase the verno for the new branch */
    *major_verno = 2;
    *minor_verno = 0;

    return (const char *)release_verno();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component_num
 * DESCRIPTION
 *  Get the total number of theme components.
 * PARAMETERS
 *  void
 * RETURNS
 *  The total number of theme components.
 *****************************************************************************/
int mmi_mte_get_theme_component_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_THEME_COMPONENT_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_component
 * DESCRIPTION
 *  Get the theme component structure by its id.
 * PARAMETERS
 *  component_id       [IN]     theme component id. Range: 0 to (mmi_mte_get_theme_component_num() - 1)
 * RETURNS
 *  Pointer to the theme component structure by its id.
 *****************************************************************************/
const mmi_mte_theme_component_struct *mmi_mte_get_theme_component(int component_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (component_id >= mmi_mte_get_theme_component_num())
    {
        return NULL;
    }

    return &g_mmi_mte_theme_component_info[component_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_map_theme_component_name_to_old_branch
 * DESCRIPTION
 *  Maps the theme component name to the corresponding name in the older MTE version.
 * PARAMETERS
 *  old_major_verno            [IN]     old branch verno
 *  theme_component_name       [IN]     theme component name
 * RETURNS
 *  The mapped theme component name.
 *****************************************************************************/
char *mmi_mte_map_theme_component_name_to_old_branch(int old_major_verno, char *theme_component_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     major_ver, minor_ver;
    S32     i;//, j;
    S8      *name_entry, *result_name;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_get_theme_schema_version(&major_ver, &minor_ver);

    /* validate the major ver */
    for (i = 0; i < MMI_MTE_BRANCH_NUM; i++)
    {
        if (MMI_MTE_GET_MAJOR_VER(g_mmi_mte_branch_ver[i]) == old_major_verno)
        {
            break;
        }
    }

    /* not a valid old branch, return the input name */
    if ((i == MMI_MTE_BRANCH_NUM) || (old_major_verno >= major_ver))
    {
        return theme_component_name;
    }

    result_name = NULL;

    /* find the mapped name in the mapping table */
    for (i = 0; i < MMI_MTE_BACKWARD_COMPATIBILITY_COMPONENT_NUM; i++)
    {
        name_entry = (S8*)g_mmi_mte_backward_component[MMI_MTE_BRANCH_NUM * i + major_ver - 1];
        if (!strcmp(theme_component_name, name_entry))
        {
            result_name = (S8*)g_mmi_mte_backward_component[MMI_MTE_BRANCH_NUM * i + major_ver - 1 - old_major_verno];
            break;
        }
    }

    /* cannot find the corresponding name, return the input name */
    if (result_name == NULL)
    {
        result_name = theme_component_name;
    }

    return result_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_theme_components_in_current_screen
 * DESCRIPTION
 *  Return a list of theme component names used in the current screen.
 * PARAMETERS
 *  max_component_number        [IN]    number of available component (at least 100 is suggested)
 *  theme_component_list        [OUT]   a list of theme component structure pointers. The memory space for the string pointer array is allocated by the caller.
 * RETURNS
 *  Number of components in the returned theme_component_list.
 *****************************************************************************/
int mmi_mte_get_theme_components_in_current_screen(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i, j;//, g;
    U8      *control_set_ptr = NULL;
    S16     *coordinate_set;
    S32     control_set_num, old_control_set_num;
    const mmi_mte_theme_component_struct *tc;
    S32     control_set_id;
    S32     done;
    S32     count;
    U8      local_control_set[128];
    S32     dm_data_flag;
    S32     current_category_id, current_screen_id;
    S32     *theme_component_category_id_filter;
    S32     category_filter_id;
    S32     coordinate_flag, scr_bg_flag;

    MMI_BOOL    to_show_list_menu;    
    MMI_BOOL    is_softkey_bar_arrow_visible;
    MMI_BOOL    is_popup;
    MMI_BOOL    to_show_vkbd;

    mmi_mte_screen_filter_comp_operation_enum comp_operation;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_component_number > mmi_mte_get_theme_component_num())
    {
        max_component_number = mmi_mte_get_theme_component_num();
    }

    dm_get_dm_data_flag(&dm_data_flag);
    current_category_id = g_dm_data.s32CatId;
    current_screen_id = GetActiveScreenId();

    /* special screen check */
    count = 0;    

    /* get the control set of the current category */
    control_set_ptr = dm_search_control_set((U16)g_dm_data.s32CatId, &coordinate_set);    

    /* prevent screen without control set, such as the camera screen. */
    if (control_set_ptr == NULL)
    {
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__COSMOS_MMI__)
        if (current_screen_id == SCREEN_FILTER_SCR_ID_MEDPLY_MAIN_SCREEN)
        {
            /* check each component */
            for (i = 0; i < mmi_mte_get_theme_component_num(); i++)
            {                
                tc = mmi_mte_get_theme_component(i);
                
                done = 0;
                
                /* check if the theme component is in the specified rule */
                comp_operation = mmi_mte_get_component_operation_in_screen_filter(tc->id, current_screen_id, current_category_id);
                if (comp_operation == MMI_MTE_SCREEN_FILTER_COMP_OPERATION_ADD)
                {
                    done = 1;
                }
                else if (comp_operation == MMI_MTE_SCREEN_FILTER_COMP_OPERATION_REMOVE)
                {
                    continue;
                }
                
                /* check the theme component category id filter */
                theme_component_category_id_filter = tc->internal_data.category_filter;
                if (theme_component_category_id_filter)
                {
                    while ((category_filter_id = *theme_component_category_id_filter++) != -1)
                    {
                        if (current_category_id == category_filter_id)
                        {
                            done = 1;
                            break;
                        }
                    }
                }
                /* do not exceed the caller limit */
                if (count >= max_component_number)
                {
                    break;
                }
                
                /* add the component into the returned list */
                if (done == 1)
                {
                    theme_component_list[count++] = tc;
                }
            }
            return count;
            
        }
        else
#endif
        {
        return 0;
        }
    }

    old_control_set_num = (S32)control_set_ptr[0];
    control_set_num = 0;

    /* expand draw manager BASE control sets */
    for (j = 0; j < old_control_set_num; j++)
    {
        control_set_id = control_set_ptr[j + 1];

        switch (control_set_id)
        {
            case DM_BASE_CONTROL_SET1:
        #if !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_SUBMENU:
        #endif /* !defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */
        #if !defined(GUI_COMMON_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_COMMON:
        #endif /*!defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
            {
                extern const U8 dm_base_control_set[];               
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set);
                break;
            }                

            case DM_BASE_CONTROL_SET2:
            {
                extern const U8 dm_base_control_set2[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set2);        
                break;
            }

        #if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_SUBMENU:
            {
                extern const U8 dm_base_control_set_submenu[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set_submenu);        
                break;
            }

        #endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

        #if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
            case DM_BASE_CONTROL_SET_COMMON:
            {
                extern const U8 dm_base_control_set_common[];
                mmi_mte_append_control_set(local_control_set, &control_set_num, (U8*)dm_base_control_set_common);                    
                break;
            }
        #endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

            default:
                local_control_set[control_set_num++] = control_set_id;
                break;
        }

    }

    /* remove/add dm groups in filter */
    mmi_mte_process_dm_group_in_filter(current_screen_id, current_category_id, local_control_set, &control_set_num);

    is_popup = MMI_FALSE;
    
    /* popup rule: remove multiline inputbox group */
    if ((mmi_mte_search_dm_group_in_control_set(DM_POPUP_BACKGROUND, local_control_set, control_set_num) != -1) &&
        (mmi_mte_search_dm_group_in_control_set(DM_MULTILINE_INPUTBOX1, local_control_set, control_set_num) != -1))
    {
        // TODO: This is a tricky way to identify the popup.
        if ((MMI_multiline_inputbox.flags & UI_MULTI_LINE_INPUT_BOX_VIEW_MODE) && 
            !memcmp(&MMI_multiline_inputbox.normal_text_color, current_MMI_theme->popup_text_color, sizeof(color)))
        {
            is_popup = MMI_TRUE;
        }

        mmi_mte_remove_dm_group_in_control_set(DM_MULTILINE_INPUTBOX1, local_control_set, control_set_num);
    }

    to_show_vkbd = MMI_FALSE;

    /* only show all virtual keyboard related components in category 111 if input type is not numeric only */
    if (current_category_id == MMI_CATEGORY111_ID)
    {
        to_show_vkbd = MMI_TRUE;
    }

    /* remove DM_TITLE_1 if no title, e.g. popups */
    if (dm_data_flag & DM_NO_TITLE)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_TITLE1, local_control_set, control_set_num);
    }
    /* remove DM_BUTTON_BAR1 if no softkey, e.g., the touch idle screen */
    if (dm_data_flag & DM_NO_SOFTKEY)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_BUTTON_BAR1, local_control_set, control_set_num);
    }
    /* remove DM_STATUS_BAR1 if no status bar */
    if (dm_data_flag & DM_NO_STATUS_BAR)
    {
        mmi_mte_remove_dm_group_in_control_set(DM_STATUS_BAR1, local_control_set, control_set_num);
    }
   
    /* check whether the button bar arrows exist */
    is_softkey_bar_arrow_visible = MMI_FALSE;
    if (mmi_mte_search_dm_group_in_control_set(DM_BUTTON_BAR1, local_control_set, control_set_num) != -1)
    {
        coordinate_flag = mmi_mte_get_control_coordinate_flag(current_category_id, DM_BUTTON_BAR1);

        if (!(coordinate_flag & DM_BUTTON_DISABLE_BACKGROUND) &&
            ((coordinate_flag & DM_BUTTON_BAR_LEFT_ARROW) || 
             (coordinate_flag & DM_BUTTON_BAR_RIGHT_ARROW) || 
             (coordinate_flag & DM_BUTTON_BAR_UP_ARROW) || 
             (coordinate_flag & DM_BUTTON_BAR_DOWN_ARROW)))
        {
            is_softkey_bar_arrow_visible = MMI_TRUE;
        }        
    }


    /* see if the list menu will be shown */
    if ((mmi_mte_search_dm_group_in_control_set(DM_LIST1, local_control_set, control_set_num) != -1) ||
        (mmi_mte_search_dm_group_in_control_set(DM_DYNAMIC_LIST1, local_control_set, control_set_num) != -1) ||
        (mmi_mte_search_dm_group_in_control_set(DM_ASYNCDYNAMIC_LIST1, local_control_set, control_set_num) != -1))
    {
        to_show_list_menu = MMI_TRUE;
    }
    else
    {
        to_show_list_menu = MMI_FALSE;        
    }

    /* check each component */
    for (i = 0; i < mmi_mte_get_theme_component_num(); i++)
    {                
        tc = mmi_mte_get_theme_component(i);

        done = 0;

        /* check if the theme component is in the specified rule */
        comp_operation = mmi_mte_get_component_operation_in_screen_filter(tc->id, current_screen_id, current_category_id);
        if (comp_operation == MMI_MTE_SCREEN_FILTER_COMP_OPERATION_ADD)
        {
            done = 1;
        }
        else if (comp_operation == MMI_MTE_SCREEN_FILTER_COMP_OPERATION_REMOVE)
        {
            continue;
        }

        /* check the theme component category id filter */
        theme_component_category_id_filter = tc->internal_data.category_filter;
        if (theme_component_category_id_filter)
        {
            while ((category_filter_id = *theme_component_category_id_filter++) != -1)
            {
                if (current_category_id == category_filter_id)
                {
                    done = 1;
                    break;
                }
            }
        }

        /* 
         * NEGATIVE rules
         */
        /* choose title components (normal or thick) */
        if (g_wgui_use_thick)
        {
            /* remove normal title components if the title is thick */
            if (!strncmp(tc->name, "title_", 6))
            {
                continue;
            }            
        }
        else
        {
            /* remove thick title components if the title is normal */
            if (!strncmp(tc->name, "thick_title", 11))
            {
                continue;
            }
        }

    /* PAGE menu special rule. Do not use included theme components in the filter. */
#ifdef __MMI_MAINMENU_PAGE_SUPPORT__
    if (current_category_id == MMI_CATEGORY14_LIST_ID)
    {
    #ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
        if (PhnsetGetMainMenuStyle() == PHNSET_MAINMENU_STYLE_PAGE)
        {
            if (!strncmp(tc->name, "list_main_menu_", 15) ||
                !strncmp(tc->name, "title_", 6) ||
		!strncmp(tc->name, "scrollbar_", 10) ||
		!strcmp(tc->name, "main_menu_bkg_filler"))
		{
		    continue;
		}
        }
    #endif
    }    
#endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */

        /* title_filler does not work at all if the title_bg_id is not 0 or GUI_TITLE_STYLE_DISABLEBG */
        if (!strcmp(tc->name, "title_filler") && 
            (title_bg_id || (g_wgui_title_bar.style & GUI_TITLE_STYLE_DISABLEBG)))
        {
            continue;   
        }

#ifdef __MMI_SCREEN_ROTATE__
        /* only show rotated_xxxx components in the rotated environment */
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            if (!strncmp(tc->name, "rotated_", 8))
            {
                continue;
            }
        }
        else
        {
            if (!strcmp(tc->name, "title_filler"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_bkg_image"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_screen_background_color"))
            {
                continue;
            }
            
            if (!strcmp(tc->name, "popup_screen_border_color"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_lsk_normal_up_filler"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_lsk_normal_down_filler"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_rsk_normal_up_filler"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_rsk_normal_down_filler"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_softkey_text_color"))
            {
                continue;
            }
            if (!strcmp(tc->name, "popup_embedded_softkey_text_border_color"))
            {
                continue;
            }
            if (!strcmp(tc->name, "softkey_bar_bkg_filler"))
            {
                continue;
            }
        }
#endif /* __MMI_SCREEN_ROTATE__ */
        
#ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
        /* do not show calendar on idle components if not enabled */
        if (!strncmp(tc->name, "calendar_", 9) && 
            strstr(tc->name, "for_idle") &&
            !PhnsetGetCalendarIdleScreen())
        {
            continue;
        }
#endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */

    #ifndef __MMI_MAINLCD_128X128__
        /* softkey_bar_bkg_filler does not work in wallpaper on bottom and MMI_softkey_filler_disabled. */
        if (!strcmp(tc->name, "softkey_bar_bkg_filler"))
        {
            if (wgui_is_wallpaper_on_bottom())//MMI_softkey_filler_disabled && 
            {
                continue;
            }

            /* For non 128x128, IMG_SOFTKEY_BAR image is used instead. See show_softkey_background_with_clipping(). */
            if (!wgui_is_wallpaper_on_bottom())
            {
                continue;
            }

        #ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
            if (current_category_id == MMI_CATEGORY414_ID)
            {
                continue;
            }
        #endif
        }
    #endif /* __MMI_MAINLCD_128X128__ */
    
        /*
         * Idle screen analog clock
         */
        if ((current_screen_id == IDLE_SCREEN_ID) &&
        #ifdef __MMI_OP11_CAT433_SUPPORT__
            (current_category_id != MMI_CATEGORY433_ID) /* orange homescreen */
        #else /* __MMI_OP11_CAT433_SUPPORT__ */
            1
        #endif /* __MMI_OP11_CAT433_SUPPORT__ */
           )
        {
    #ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        #if defined(__MMI_ANALOG_CLOCK__) && !defined(__COSMOS_MMI__)
            if ((U32)PhnsetGetCurWallpaperName() == (U32)GetString(STR_ID_PHNSET_DISPCHAR_ANALOG))
            {   /* analog clock on the idle screen */
                if (!strcmp(tc->name, "analog_hand_hour_color") ||
                    !strcmp(tc->name, "analog_hand_min_color") ||
                    !strcmp(tc->name, "analog_axis_color"))
                {
                    done = 1;
                }
            }
        #endif /* __MMI_ANALOG_CLOCK__ */
    #else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
            if (g_clock_type == ANALOG)
            {
                if (!strcmp(tc->name, "analog_hand_hour_color") ||
                    !strcmp(tc->name, "analog_hand_min_color"))
                {
                    done = 1;
                }            
            }
    #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
        }

        /* soft key bar arrows */
        if (is_softkey_bar_arrow_visible &&
            (!strcmp(tc->name, "arrow_indication_color") ||
             !strcmp(tc->name, "arrow_indication_border_color")))
        {
            done = 1;   
        }

        /* popup_text_color only appears in popup screens */
        if (is_popup && !strcmp(tc->name, "popup_text_color"))
        {
            done = 1;
        }

        /* virtual keyboard */
        if (to_show_vkbd && (!strncmp(tc->name, "virtual_keyboard_", 17) || !strncmp(tc->name, "ime_", 4)))
        {
            done = 1;
        }
        
#ifdef __MMI_ICON_BAR_SUPPORT__ 
        if (wgui_icon_bar_is_created() && !strncmp(tc->name, "icon_bar_", 9))
        {
            done = 1;
        }
#endif/*__MMI_ICON_BAR_SUPPORT__*/        
        /* check if any control set contains the theme component. */
        for (j = 0; j < control_set_num && !done; j++)
        {                
            control_set_id = (S32)local_control_set[j];

            /* DM_SCR_BG SPECIAL RULE */
            if (control_set_id == DM_SCR_BG)
            {
                /* do not include the SCR BG theme component if SCR BG is set by the category, e.g, category 105. */
                dm_get_scr_bg_flag(&scr_bg_flag);
                if (scr_bg_flag & DM_SCR_BG_FORCE_SHOW)
                {
                    continue;
                }
                            
                if ((dm_get_current_scr_bg_filler() == current_MMI_theme->main_menu_bkg_filler) &&
                    !strcmp(tc->name, "main_menu_bkg_filler"))
                {
                    done = 1;
                    break;
                }
                else if ((dm_get_current_scr_bg_filler() == current_MMI_theme->sub_menu_bkg_filler) &&
                    !strcmp(tc->name, "sub_menu_bkg_filler"))
                {
                #if defined (__MMI_CAT44X_SUPPORT__) && defined(__MMI_MAINLCD_320X480__)
                    if (current_category_id >=  MMI_CATEGORY440_ID && current_category_id <= MMI_CATEGORY449_ID)
                    {
                        done = 0;
                    }
                    else if (current_category_id != MMI_CATEGORY222_ID)
                    {
                        done = 1;
                    }
                    break;
                #else
                    if (current_category_id != MMI_CATEGORY222_ID && current_category_id != MMI_CATEGORY306_ID && current_category_id != MMI_CATEGORY307_ID)
                    {
                        done = 1;
                    }
                    break;
                #endif
                }
            }

            /* check if the theme component belongs to one of the DM group */
            if (mmi_mte_is_component_in_dm_group(tc->id, control_set_id))
            {
                done = 1;
                break;
            }
        }

        /* do not exceed the caller limit */
        if (count >= max_component_number)
        {
            break;
        }

        /* add the component into the returned list */
        if (done == 1)
        {
            theme_component_list[count++] = tc;
        }
    }
    
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_component_group_num
 * DESCRIPTION
 *  Get the total number of component groups.
 * PARAMETERS
 *  void
 * RETURNS
 *  The total number of component groups.
 *****************************************************************************/
int mmi_mte_get_component_group_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_THEME_COMPONENT_GROUP_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_component_group_name
 * DESCRIPTION
 *  Get the group name by its id.
 * PARAMETERS
 *  group_id       [IN]     group id. Range: 0 to mmi_mte_get_component_group_num() - 1
 * RETURNS
 *  The group name string in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_component_group_name(int group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id >= mmi_mte_get_component_group_num())
    {
        return NULL;
    }
   
    return (const char*)g_mmi_mte_theme_component_group_name[group_id];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_system_theme_data
 * DESCRIPTION
 *  Get current fixed compiled system theme information.
 * PARAMETERS
 *  max_theme_number        [IN]    max number of returned system themes for theme_list[] and theme_name_list[]. (At least 20 is suggested)
 *  theme_list[]            [OUT]   system theme structure list    
 *  theme_name_list[]       [OUT]   list of system theme name strings in ASCII
 * RETURNS
 *  Number of available system themes.
 *****************************************************************************/
int mmi_mte_get_system_theme_data(int max_theme_number, const MMI_theme *theme_list[], const char *theme_name_list[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_theme_number > n_MMI_themes)
    {
        max_theme_number = n_MMI_themes;
    }

    for (i = 0; i < max_theme_number; i++)
    {
    #ifndef __MMI_THEMES_V2_SUPPORT__
        theme_list[i] = MMI_themes[i];
    #else /* __MMI_THEMES_V2_SUPPORT__ */
        theme_list[i] = MMI_themes[i].theme;
    #endif /* __MMI_THEMES_V2_SUPPORT__ */

        /* no theme names */
        theme_name_list[i] = NULL;
    }
    
    return max_theme_number;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_current_system_theme
 * DESCRIPTION
 *  Gets the current activated MMI theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  Current activated MMI theme.
 *****************************************************************************/
MMI_theme *mmi_mte_get_current_system_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return current_MMI_theme;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_refresh_screen
 * DESCRIPTION
 *  Refresh MoDIS MMI screen. It is typically invoked when theme data or image file is changed.
 * PARAMETERS
 *  lcd_type       [IN]     SubLCD or Main LCD
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_refresh_screen(mmi_mte_lcd_type_enum lcd_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_activate_entry, MMI_FRM_UNKNOW_SCRN);
//    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_MTE_EXAMPLE, MMI_SCRN_ATTRIB_ADD_HISTORY);
//    ShowCategoryDummyScreen();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DUMMY_MTE_EXAMPLE,NULL, NULL);
    mmi_frm_group_enter(GRP_ID_DUMMY_MTE_EXAMPLE,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_mte_activate_entry();

    ExecSubLCDCurrExitHandler();
    GoBackBothLCDHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_activate_theme
 * DESCRIPTION
 *  Activate a theme.
 * PARAMETERS
 *  theme       [IN]    MMI theme to be activated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_activate_theme(MMI_theme *theme, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mte_state_enum  mte_state;
    U16 current_scr_id;
#ifdef __MMI_VUI_ENGINE__	
    MMI_BOOL        freeze_state, force_freeze = MMI_FALSE;   
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_scr_id = GetActiveScreenId();
    
#ifdef __MMI_VUI_ENGINE__
    freeze_state = gdi_lcd_get_freeze();
    if (!vadp_p2v_uc_is_in_venus() && 
        g_dm_data.s32CatId != MMI_CATEGORY63_ID &&
        g_dm_data.s32CatId != MMI_CATEGORY165_ID &&
        g_dm_data.s32CatId != MMI_CATEGORY14_MATRIX_PAGE_ID
    #ifdef __PLUTO_MMI_PACKAGE__
        && g_dm_data.s32CatId != MMI_CATEGORY105_ID
    #endif
        )
    {
        if (g_dm_data.s32ScrId != SCR_ID_INPUT_METHOD_VK_POPUP_LIST)
        {
            force_freeze = MMI_TRUE;
        }
        gdi_lcd_freeze(TRUE);
    }
#else    
    gdi_layer_lock_frame_buffer();
#endif

    /* 
     * Enter a new screen first and then apply the theme to prevent 
     * some categories from restoring the theme variable.
     */
//    mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_activate_entry, MMI_FRM_UNKNOW_SCRN);
//    mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_MTE_EXAMPLE, MMI_SCRN_ATTRIB_ADD_HISTORY);

//    ShowCategoryDummyScreen();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_DUMMY_MTE_EXAMPLE,NULL, NULL);
    mmi_frm_group_enter(GRP_ID_DUMMY_MTE_EXAMPLE,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_mte_activate_entry();

    /* activate system theme 0 in the MMI normal way to keep the activated theme correct after MTE exits. */
    mmi_mte_set_system_theme(index);

    /* Temporarily change the MTE state because set_MMI_theme() will not work when mte is active. */
    mte_state = mmi_mte_is_active();
    mmi_mte_set_state(MMI_MTE_STATE_INACTIVE);
    set_MMI_theme(theme);
    mmi_mte_set_state(mte_state);
    MMI_apply_current_theme();

#ifdef __MMI_OP01_DCD__
    // TODO: The DCD agent should provide an API to re-get the MMI DCD theme components.
    /* A VERY DIRTY WORKAROUND TO UPDATE THE DCD THEME */
    if ((current_scr_id > SCR_ID_DCD_CHANNEL_LIST) && (current_scr_id < SCR_ID_DCD_END) || (current_scr_id == IDLE_SCREEN_ID))
    {
        mmi_dcd_switch(MMI_FALSE);
        mmi_dcd_switch(MMI_TRUE);

        /* story viewer need this to display its content... */
        if (current_scr_id == SCR_ID_DCD_STORY_VIEWER)
        {
            // mmi_dcd_pre_entry_story_viewer();
            mmi_dcd_idle_to_story_viewer();
            GoBackHistory();
        }
    }
#endif /* __MMI_OP01_DCD__ */
    
    mmi_mte_refresh_screen(MMI_MTE_LCD_TYPE_MAIN);
#ifdef __MMI_VUI_ENGINE__
    if ((!vadp_p2v_uc_is_in_venus()) || force_freeze)
    {
        gdi_lcd_freeze(freeze_state);    
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }
#else    
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_translate_theme_component_data_pointer
 * DESCRIPTION
 *  Return the pointer to the theme component in the given MMI_theme. 
 *  This function links two structures 'mmi_mte_theme_component_struct' and 'MMI_theme' together.
 * PARAMETERS
 *  theme_component       [IN]  pointer to the theme component structure
 *  theme                 [IN]  pointer to MMI theme
 * RETURNS
 *  Return theme component data pointer, which needs type casting according to the component type.
 *****************************************************************************/
void *mmi_mte_translate_theme_component_data_pointer(const mmi_mte_theme_component_struct *theme_component, MMI_theme *theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*)theme + theme_component->internal_data.mmi_theme_offset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_controlarea_in_current_screen
 * DESCRIPTION
 *  Return the pointer to the theme component in the given MMI_theme. 
 *  This function links two structures 'mmi_mte_theme_component_struct' and 'MMI_theme' together.
 * PARAMETERS
 * RETURNS
 *  Return theme component data pointer, which needs type casting according to the component type.
 *****************************************************************************/
mmi_mte_return_code_enum mmi_mte_is_controlarea_in_current_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     dm_data_flag;
    S32     current_category_id;//, current_screen_id;
    MMI_BOOL is_control_area, is_control_area2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_get_dm_data_flag(&dm_data_flag);
    current_category_id = g_dm_data.s32CatId;
    if (current_category_id == 0)
    {
        return MMI_MTE_SUCCESS;
    }
    
    is_control_area = dm_check_control_exist((U16)g_dm_data.s32CatId, DM_CATEGORY_CONTROLLED_AREA);    
    is_control_area2 = dm_check_control_exist((U16)g_dm_data.s32CatId, DM_CATEGORY_CONTROLLED_AREA2);    
    if (is_control_area || is_control_area2)
    {
        return MMI_MTE_SUCCESS;
    }
    else
    {
        return MMI_MTE_ERROR;
    }
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_register_switch_screen_callback
 * DESCRIPTION
 *  This registered callback function is called when a screen change happens in MMI. 
 *  MTE can use this callback to update the component list of [Screen 5] when the 
 *  theme component filter is set to "Current Screen".
 * PARAMETERS
 *  switch_screen_callback      [IN]    switch screen callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_register_switch_screen_callback(void (*switch_screen_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_switch_screen_callback = switch_screen_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_example_screen_num
 * DESCRIPTION
 *  Get the number of example screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of example screens.
 *****************************************************************************/
int mmi_mte_get_example_screen_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_MTE_EXAMPLE_SCREEN_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_example_screen_name
 * DESCRIPTION
 *  Get the example screen name by its screen index.
 * PARAMETERS
 *  screen_index       [IN]     screen index
 * RETURNS
 *  Name of the specified screen in Unicode.
 *****************************************************************************/
const char *mmi_mte_get_example_screen_name(int screen_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (screen_index > mmi_mte_get_example_screen_num())
    {
        return NULL;   
    }

    return (const char*)g_mmi_mte_example_screen_name[screen_index];
}

#if defined (__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__)
static void mmi_mte_example_screen_statuc_icon_rsk_function(void)
{
	mmi_frm_close_to_idle_group();
}

void mmi_mte_example_screen_entry_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;
    U8 *guiBuffer = NULL;
    S32 index;
    U8 *itemlist[2];
    U16 nImgIds[2], callstates[2];
#ifdef __MMI_VUI_ENGINE__
	
    MMI_BOOL        freeze_state;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*
     *  to goto a screen normally, it is safer to go back to the idle first.
     */
    freeze_state = gdi_lcd_get_freeze();
    gdi_lcd_freeze(TRUE);
#else    
    gdi_layer_lock_frame_buffer();
#endif

#if 0
/* under construction !*/
#else
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MTE_EXAMPLE, NULL,NULL);
    mmi_frm_group_enter(GRP_ID_MTE_EXAMPLE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_scrn_enter(
        GRP_ID_MTE_EXAMPLE, 
        SCR_ID_MTE_EXAMPLE_STATUS_ICON,
        NULL,
        mmi_mte_example_screen_entry_status_icon,
        MMI_FRM_FULL_SCRN);
#endif

    for (index = 0; index < 2; index++)
    {
        itemlist[index] = (U8*)L"1234567890";
        nImgIds[index] = IMG_GLOBAL_OK;
		callstates[index] = IMG_GLOBAL_OK;
    }

    GetDateTime(&time);
    ShowCategory19Screen(
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        index,
        itemlist,
        callstates,
        nImgIds,
        (UI_time*) & time,
        0,
        NULL);
    
#if 0
/* under construction !*/
#else
    SetRightSoftkeyFunction(mmi_mte_example_screen_statuc_icon_rsk_function, KEY_EVENT_UP);
#endif
    
#ifdef __MMI_VUI_ENGINE__
    gdi_lcd_freeze(freeze_state);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#else        
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_show_example_screen
 * DESCRIPTION
 *  Show an example screen by its screen index. This function is provided to 
 *  let users be able to choose a screen to work on.
 * PARAMETERS
 *  screen_index       [IN]     screen index
 * RETURNS
 *  0: Success.
 *  1: Failure. Invalid screen index.
 *****************************************************************************/
int mmi_mte_show_example_screen(int screen_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 old_menu_style = 0;
#ifdef __MMI_VUI_ENGINE__	
    MMI_BOOL        freeze_state;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*
     *  to goto a screen normally, it is safer to go back to the idle first.
     */
//#ifdef __MMI_VUI_ENGINE__
    freeze_state = gdi_lcd_get_freeze();
    gdi_lcd_freeze(TRUE);
#else    
    gdi_layer_lock_frame_buffer();
#endif

    /*
    if (GetScreenCountInHistory())
    {
        GoBacknHistory((U16)(GetScreenCountInHistory() - 1));
    }
    */

    mmi_idle_display();

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    old_menu_style = PhnsetGetMainMenuStyle();
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */            

    switch (screen_index)
    {
        /*
         * Idle Screen
         */
    #ifdef __MMI_OP01_DCD__
        case MMI_MTE_EXAMPLE_SCREEN_DCD_IDLE:
    #endif /* __MMI_OP01_DCD__ */
        case MMI_MTE_EXAMPLE_SCREEN_IDLE: 
            // TODO: DCD and Calendar is mutally exclusive. But they SHOULD not be turned on at the same time?
        #ifdef __MMI_CALENDAR_ON_IDLE_SCREEN__
            /* force to turn on calendar on idle */
            /* Phone setting is MODIFIED. */
            g_phnset_cntx_p->curCalendarIdleScrStatus = 1;
        #endif /* __MMI_CALENDAR_ON_IDLE_SCREEN__ */
        
        #ifdef __MMI_OP01_DCD__
            /* force to turn on DCD for DCD idle */
            /* NOTE: phone setting is NOT MODIFIED. */
            mmi_dcd_switch(MMI_FALSE);
            mmi_dcd_switch(MMI_TRUE);
        #endif /* __MMI_OP01_DCD__ */
            
            // TODO: The idle screen redrawing will hang...
        #ifndef __MMI_OP01_DCD__
            /* redraw idle screen for calendar on idle */
            mmi_mte_refresh_screen(MMI_MTE_LCD_TYPE_MAIN);
        #endif /* __MMI_OP01_DCD__ */
            break;

        /*
         * 6 Styles of Main Menus
         */
    #if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_MATRIX);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */

    #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU:
            goto_main_menu();
            break;
    #endif /* defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_LIST);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */

    #if defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_PAGE_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_PAGE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_PAGE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_3D_CIRCULAR_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_CIRCULE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_CIRCULAR_SUPPORT__) && defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

    #if defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_EXAMPLE_SCREEN_ROTATE_MAIN_MENU:
            mmi_mte_set_example_main_menu_style(PHNSET_MAINMENU_STYLE_ROTATE);
            goto_main_menu();
            break;
    #endif /* defined(__MMI_MAINMENU_ROTATE_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */    

        case MMI_MTE_EXAMPLE_SCREEN_LIST: /* list menu */            
            /* setting menu */
            EntryScrSettingMenu();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_INLINE:
            EntryPhnsetSetDT();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_EDITOR:
            /* enable IME mode from group only */
            // TODO: SHOULD BE MORE ELEGANT...
            if ((g_mmi_mte_example_screen_group_index == MMI_MTE_GROUP_INPUTBOX_IME))
            {
                g_mmi_mte_example_screen_editor_is_IME_mode = MMI_TRUE;
            }
            else
            {
                g_mmi_mte_example_screen_editor_is_IME_mode = MMI_FALSE;            
            }
            
            mmi_mte_example_screen_entry_editor();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_CALL:
            mmi_mte_example_screen_entry_call();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_DIALER:
            /* dialer from idle */
            mmi_mte_example_screen_entry_dialer_launch();
            break;

    #if defined(__MMI_CALENDAR__) && !defined(__COSMOS_MMI__)
        case MMI_MTE_EXAMPLE_SCREEN_CALENDAR:
            /* calendar */
            mmi_clndr_launch(GRP_ID_ROOT, MMI_CAL_LAUNCH_TYPE_AUTO, NULL);
            break;
    #endif /* __MMI_CALENDAR__ */             

    #if defined(__MMI_SCREEN_ROTATE__) &&  !defined(__MMI_MAINLCD_320X240__)
        case MMI_MTE_EXAMPLE_SCREEN_ROTATED_POPUP:
            mmi_mte_example_screen_entry_rotated_popup();            
            break;

        case MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST:
            mmi_mte_example_screen_entry_rotated_list();
            break;            
    #endif /* __MMI_SCREEN_ROTATE__ */

        case MMI_MTE_EXAMPLE_SCREEN_PIN:
            /* PIN single line input */
            mmi_mte_example_screen_entry_PIN();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER:
            mmi_mte_example_screen_entry_symbol_picker();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_RADIO_LIST:
            EntryPhnsetLang();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_CHECK_LIST:
            mmi_mte_example_screen_entry_check_list();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_MULTIROW_LIST:
            mmi_mte_example_screen_entry_multirow_list();
            break;

    #if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)
        case MMI_MTE_EXAMPLE_SCREEN_TAB_LIST:
            g_mmi_mte_example_screen_tab_num = 3;
            mmi_mte_example_screen_entry_tab();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_TAB_LIST_WITHOUT_TAB:
            g_mmi_mte_example_screen_tab_num = 0;
            mmi_mte_example_screen_entry_tab();
            break;
    #endif /* defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__) */
    
        case MMI_MTE_EXAMPLE_SCREEN_TWOLINE_LIST:
            mmi_mte_example_screen_entry_twoline_list();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_POPUP:
            mmi_mte_example_screen_entry_popup();
            break;           

    #if defined(__MMI_SMALL_LIST_SCREEN__)        
        case MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST:
            mmi_mte_example_screen_entry_small_list();
            break;
    #endif /* defined(__MMI_SMALL_LIST_SCREEN__) */ 

    #if defined(__MMI_CASCADE_MENU__)
        case MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU:
            mmi_mte_example_screen_entry_cascade_menu();
            break;
    #endif /* defined(__MMI_CASCADE_MENU__) */        

    #ifdef __MMI_OP01_DCD__
        case MMI_MTE_EXAMPLE_SCREEN_DCD_STORY_VIEWER:
            mmi_dcd_switch(MMI_FALSE);
            mmi_dcd_switch(MMI_TRUE);
            mmi_dcd_idle_to_story_viewer();
            break;

        case MMI_MTE_EXAMPLE_SCREEN_DCD_CHANNEL_LIST:
            mmi_dcd_entry_channel_list_screen();
            break;
    #endif /* __MMI_OP01_DCD__ */
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
        case MMI_MTE_EXAMPLE_SCREEN_MEDIA_PLAYER:
            mmi_mte_example_screen_entry_media_player();
            break;
#endif

        default:
#ifdef __MMI_VUI_ENGINE__
            gdi_lcd_freeze(freeze_state);
#else    
            gdi_layer_unlock_frame_buffer();
#endif
            return 1;
    }

#ifdef __MMI_VUI_ENGINE__
    gdi_lcd_freeze(freeze_state);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (vadp_p2v_uc_is_in_venus())
    {
        // Refresh screen for venus screen(vrt will be suspended).
        mmi_mte_refresh_screen(MMI_MTE_LCD_TYPE_MAIN);
    }
#else    
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, 0, 0);
#endif

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_show_example_screen_by_group
 * DESCRIPTION
 *  Show the example screen by group index.
 * PARAMETERS
 *  group_index       [IN]  group index
 * RETURNS
 *  0: Success.
 *  1: Failure. Invalid group index.
 *****************************************************************************/
int mmi_mte_show_example_screen_by_group(int group_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((group_index < 0) || (group_index >= MMI_MTE_THEME_COMPONENT_GROUP_NUM))
    {
        return 1;
    }

    g_mmi_mte_example_screen_group_index = group_index;
    
    switch (group_index)
    {
        case MMI_MTE_GROUP_SCREEN_IDLE:
        case MMI_MTE_GROUP_CLOCK:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_IDLE);
            break;

        case MMI_MTE_GROUP_INPUTBOX:
        case MMI_MTE_GROUP_INPUTBOX_KEYBOARD:            
        case MMI_MTE_GROUP_INPUTBOX_IME:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_EDITOR);
            break;

        case MMI_MTE_GROUP_SCROLLBAR:
        case MMI_MTE_GROUP_TITLE:
        case MMI_MTE_GROUP_SUBMENU_LIST:
        case MMI_MTE_GROUP_SOFTKEY:
#if (!(defined (__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__)))
        case MMI_MTE_GROUP_STATUS_ICONS:
#endif
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_LIST);
            break;

        case MMI_MTE_GROUP_SCREEN_SYMBOL_PICKER:        
        case MMI_MTE_GROUP_SUBMENU_MATRIX:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_SYMBOL_PICKER);
            break;

        case MMI_MTE_GROUP_INLINE_EDITOR:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_INLINE);
            break;

        case MMI_MTE_GROUP_MAIN_MENU_MATRIX:
        #if defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
        case MMI_MTE_GROUP_MAIN_MENU_BIDEGREE:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_BIDEGREE_MAIN_MENU);
        #elif defined(__MMI_MAINMENU_MATRIX_SUPPORT__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_MATRIX_MAIN_MENU);
        #endif /* defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */              
            break;

        case MMI_MTE_GROUP_MAIN_MENU_LIST:        
        #if defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_LIST_MAIN_MENU);
        #endif /* defined(__MMI_MAINMENU_LIST_SUPPORT__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__) */
            break;

        case MMI_MTE_GROUP_COMMON:
            break;

        case MMI_MTE_GROUP_SCREEN_PIN_INPUT:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_PIN);
            break;

        case MMI_MTE_GROUP_SCREEN_CALLING:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CALL);
            break;

#if defined (__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__)
        case MMI_MTE_GROUP_STATUS_ICONS:
            mmi_mte_example_screen_entry_status_icon();
            break;
#endif
        case MMI_MTE_GROUP_SCREEN_DIALER:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_DIALER);
            break;        

        case MMI_MTE_GROUP_CALENDAR:
        #ifdef __MMI_CALENDAR__ 
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CALENDAR);
        #endif /* __MMI_CALENDAR__ */
            break;

        case MMI_MTE_GROUP_TAB:
        #if defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__)        
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_TAB_LIST);
        #endif /* defined(__MMI_IMPS__) || defined(__MMI_UCM__) || defined(__MMI_VOIP__) */
            break;

        case MMI_MTE_GROUP_SCREEN_POPUP:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_POPUP);
            break;
        
        case MMI_MTE_GROUP_SCREEN_ROTATED:
        #if defined(__MMI_SCREEN_ROTATE__) &&  !defined(__MMI_MAINLCD_320X240__)
             mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_ROTATED_LIST);
        #endif /* defined(__MMI_SCREEN_ROTATE__) */
            break;

        case MMI_MTE_GROUP_SCREEN_SMALL_MENU:
        #if defined(__MMI_SMALL_LIST_SCREEN__)        
             mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_SMALL_LIST);
        #endif /* defined(__MMI_SMALL_LIST_SCREEN__) */      
            break;

        case MMI_MTE_GROUP_SUBMENU_CASCADE:
        #if defined(__MMI_CASCADE_MENU__)
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_CASCADE_MENU);
        #endif /* defined(__MMI_CASCADE_MENU__) */
            break;

    #ifdef __MMI_OP01_DCD__
        case MMI_MTE_GROUP_DCD_IDLE:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_DCD_IDLE);
            break;

        case MMI_MTE_GROUP_STORY_VIEWER:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_DCD_STORY_VIEWER);
            break;

        case MMI_MTE_GROUP_CHANNEL_LIST:
            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_DCD_CHANNEL_LIST);
            break;
    #endif /* __MMI_OP01_DCD__ */
#if defined(__MMI_MEDIA_PLAYER__) && !defined(__MMI_FTE_SUPPORT__) && !defined(__COSMOS_MMI__)
        case MMI_MTE_GROUP_MEDIA_PLAYER:
        case MMI_MTE_GROUP_SPECIAL_SCREEN:

            mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_MEDIA_PLAYER);
            break;
#endif
		case MMI_MTE_GROUP_ICON_BAR:
			mmi_mte_show_example_screen(MMI_MTE_EXAMPLE_SCREEN_TAB_LIST);
            break;

        default:
            break;
    }

    /* set as the invalid group index */
    g_mmi_mte_example_screen_group_index = -1;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_image_source
 * DESCRIPTION
 *  Get the image resource name by the full-path filename under the image resource folder.
 * PARAMETERS
 *  use_image_folder       [IN]     0: use system images. 1: use local image files located 'folder_path'
 *  folder_path            [IN]     the path containing local image files
 * RETURNS
 *  0: Success.
 *  1: Cannot open <folder_path>
 *****************************************************************************/
int mmi_mte_set_image_source(int use_image_folder, const char *folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      tmp_file_path[MMI_MTE_MAX_PATH_LEN];
    FILE    *fp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (use_image_folder == 0)
    {
        g_mmi_mte_image_folder_path = NULL;
    }
    else
    {   
        /* 
         * Check the folder path validity by a dirty trick to invoke 
         * ANSI C FILE I/O functions only...Of course, not workable on the target.
         */
        /* The STAMP file is named as "_REMOVE_ME_" under the target folder. */
        tmp_file_path[MMI_MTE_MAX_PATH_LEN - 15 - 1] = 0;
        strncpy(tmp_file_path, folder_path, MMI_MTE_MAX_PATH_LEN - 15 - 1);
        strcat(tmp_file_path, "\\_REMOVE_ME_");
       
        if ((fp = fopen(tmp_file_path, "w")) == NULL)
        {
            return 1;
        }

        fclose(fp);

        /* remove the STAMP file */
        remove(tmp_file_path);

        g_mmi_mte_image_folder_path = (U8*)folder_path;        
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_total_size
 * DESCRIPTION
 *  Get the total size of image resource.
 * PARAMETERS
 *  in_local_folder       [IN]      0: the size of system images. 1: the size of local image files located 'folder_path'
 * RETURNS
 *  The total size of all images in byte; return 0 if local folder path was not 
 *  initialized by mmi_mte_set_image_source().
 *****************************************************************************/
int mmi_mte_get_image_resource_total_size(int in_local_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     total_size;
    U8      file_path[MMI_MTE_MAX_PATH_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_local_folder == 0)
    {
        return MMI_MTE_SYSTEM_IMAGE_RESOURCE_SIZE;
    }

    if (g_mmi_mte_image_folder_path == NULL)
    {
        return 0;
    }

    total_size = 0;
    
    for (i = 0; i < MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM; i++)
    {        
        if (g_mmi_mte_img_resource[i].path && (g_mmi_mte_img_resource[i].size > 0))
        {
            _snprintf(file_path, MMI_MTE_MAX_PATH_LEN - 1, "%s\\%s", g_mmi_mte_image_folder_path, g_mmi_mte_img_resource[i].path);        
            total_size += mmi_mte_get_file_size(file_path) + 8; /* plus 8-byte resource header */
        }
    }        

    return total_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_language
 * DESCRIPTION
 *  Set the MTE language.
 * PARAMETERS
 *  language_id       [IN]      0: English. 1: Simplified Chinese
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_set_language(int language_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    S32     theme_component_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (language_id >= MMI_MTE_LANGUAGE_NUM)
    {
        return;    
    }
    
    g_mmi_mte_language_id = language_id;

    /* switch string pointer arrays */
    g_mmi_mte_example_screen_name = g_mmi_mte_language[language_id].example_screen_name;
    g_mmi_mte_theme_component_description = g_mmi_mte_language[language_id].theme_component_description;
    g_mmi_mte_theme_component_group_name = g_mmi_mte_language[language_id].theme_component_group_name;
    
    /* replace theme component descriptions with the specified language  */
    theme_component_num = mmi_mte_get_theme_component_num();
    for (i = 0; i < theme_component_num; i++)
    {
        g_mmi_mte_theme_component_info[i].description = (char*)g_mmi_mte_theme_component_description[i];
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_welcome_string
 * DESCRIPTION
 *  Prompt some messages to users about the theme to be edited. 
 * PARAMETERS
 *  theme       [IN]    mmi theme
 * RETURNS
 *  String to be displayed in the welcome screen. If the string is null, do not show the welcome screen.
 *****************************************************************************/
const char *mmi_mte_get_welcome_string(const MMI_theme *theme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NULL;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_header
 * DESCRIPTION
 *  Get the 8-byte image resource header.
 * PARAMETERS
 *  header           [IN]   output header buffer
 *  image_type       [IN]   image type
 *  width            [IN]   image width
 *  height           [IN]   image height
 *  size             [IN]   image size (not including the 8-byte header)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_get_image_header(char *header, mmi_mte_image_enum image_type, int width, int height, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mte_make_resource_header(
        (PU8)header,
        mmi_mte_translate_image_type_from_mte_to_gdi(image_type),
        width,
        height,
        size,
        1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_sequence_header
 * DESCRIPTION
 *  Gets the image sequence resource header.
 * PARAMETERS
 *  header            [IN]  image sequence resource header
 *  image_type        [IN]  image type
 *  output_header_size  [IN/OUT]    output header size in bytes
 *  width             [IN]  width
 *  height            [IN]  height
 *  frame_num         [IN]  number of frames
 *  repeat_count      [IN]  repeat number. 0 means forever.
 *  frame_size        [IN]  frame size array for each frame
 *  frame_delay       [IN]  frame delay array for each frame
 * RETURNS
 *  MMI_MTE_SUCCESS: Successful.
 *  MMI_MTE_ERROR: Output_header_size is not enough. The header size must be at least (8 + 12 * frame_num) bytes.
 *****************************************************************************/
mmi_mte_return_code_enum mmi_mte_get_image_sequence_header(char *header, mmi_mte_image_enum image_type, int *output_header_size, int width, int height, int frame_num, int repeat_count, int *frame_size, int *frame_delay)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    U32     *header32;
    U32     offset;
    S32     result_header_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_header_size = 8 + 12 * frame_num;

    /* insufficient size */
    if (*output_header_size < result_header_size)
    {
        return MMI_MTE_ERROR;
    }

    /* generate 8-byte header */
    mmi_mte_make_resource_header(
        (PU8)header,
        mmi_mte_translate_image_type_from_mte_to_gdi(image_type),
        width,
        height,
        0,  /* The sequence size can be 0 here. */
        frame_num);

    ((PU8)header)[2] = repeat_count;

    header += 8;
    offset = 8;
    
    /* Note that there is no alignment problem for x86, so it is safe to be free-style here. */
    header32 = (U32*)header;

    /* output the 12-byte information block for each frame */
    for (i = 0; i < frame_num; i++)
    {
        /* offset */
        *header32++ = offset;
        offset += ((frame_size[i] + 3) >> 2) << 2;
        /* size */
        *header32++ = ((frame_size[i] + 3) >> 2) << 2;
        /* delay */
        *header32++ = frame_delay[i];
    }

    *output_header_size = result_header_size;

    return MMI_MTE_SUCCESS;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_9slice_header
 * DESCRIPTION
 *  Gets the image sequence resource header.
 * PARAMETERS
 *  header            [IN]  image sequence resource header
 *  image_type        [IN]  image type
 *  output_header_size  [IN/OUT]    output header size in bytes
 *  width             [IN]  width
 *  height            [IN]  height
 *  frame_num         [IN]  number of frames
 *  repeat_count      [IN]  repeat number. 0 means forever.
 *  frame_size        [IN]  frame size array for each frame
 *  frame_delay       [IN]  frame delay array for each frame
 * RETURNS
 *  MMI_MTE_SUCCESS: Successful.
 *  MMI_MTE_ERROR: Output_header_size is not enough. The header size must be at least (8 + 12 * frame_num) bytes.
 *****************************************************************************/
mmi_mte_return_code_enum mmi_mte_get_image_9slice_header(char *header, mmi_mte_image_enum image_type, int *output_header_size, int width, int height,int len, int left, int top, int right, int bottom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S32     i;
    U32     *header32;
    U32     offset;
    S32     result_header_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_header_size = 8 + 20;

    /* insufficient size */
    if (*output_header_size < result_header_size)
    {
        return MMI_MTE_ERROR;
    }

    /* generate 8-byte header */
    mmi_mte_make_resource_header(
        (PU8)header,
        GDI_IMAGE_TYPE_9SLICE,
        width,
        height,
        len,//0,  /* The sequence size can be 0 here. */
        1);

    header += 8;
    offset = 8;
    
    /* Note that there is no alignment problem for x86, so it is safe to be free-style here. */
    header32 = (U32*)header;

    ((PU8)header32)[0] = 	mmi_mte_translate_image_type_from_mte_to_gdi(image_type);
    /* output the 12-byte information block for each frame */
    header[1] = 1 & 0xFF;
    header[4] = left & 0xFF;
    header[5] = (left >> 8) & 0xFF;

    header[8] = top & 0xFF;
    header[9] = (top >> 8) & 0xFF;

    header[12] = right & 0xFF;
    header[13] = (right >> 8) & 0xFF;

    header[16] = bottom & 0xFF;
    header[17] = (bottom >> 8) & 0xFF;

    *output_header_size = result_header_size;

    return MMI_MTE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_frame_count
 * DESCRIPTION
 *  Gets the image frame count.
 * PARAMETERS
 *  image_ptr       [IN]    image data
 *  frame_count     [OUT]   frame count
 * RETURNS
 *  MMI_MTE_SUCCESS: Successful.
 *  MMI_MTE_ERROR: Failed.
 *****************************************************************************/
mmi_mte_return_code_enum mmi_mte_get_image_frame_count(char *image_ptr, int *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* obtain the frame count from the image resource header byte 1 */
    *frame_count = (S32)*((PU8)image_ptr + 1);

    /* fix the wrong frame count 0 which is caused by the old ABM toolchain */
    if (*frame_count == 0)
    {
        *frame_count = 1;
    }

    return MMI_MTE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_data_length
 * DESCRIPTION
 *  Get the image resource size.
 * PARAMETERS
 *  image_ptr       [IN]    image data
 * RETURNS
 *  The size of the image data in bytes plus 8 (the 8-byte header)
 *****************************************************************************/
int mmi_mte_get_image_data_length(char *image_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8      *data_ptr;
    U8      img_type;
    S32     img_size;
    S32     frame_number;
    S32     width;
    S32     height;
    GDI_RESULT  ret;
            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_parse_info(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            &data_ptr,
            &img_type,
            &img_size,
            &frame_number,
            &width,
            &height);

    if (ret != GDI_SUCCEED)
    {
        return 0;
    }

    /* need to calculate sequence total size because the header does not contain the size. */
    if ((img_type == GDI_IMAGE_TYPE_JPG_SEQUENCE) || 
        (img_type == GDI_IMAGE_TYPE_BMP_SEQUENCE) ||
        (img_type == GDI_IMAGE_TYPE_ABM_SEQUENCE) || 
        (img_type == GDI_IMAGE_TYPE_PNG_SEQUENCE) ||
        (img_type == GDI_IMAGE_TYPE_AB2_SEQUENCE))
    {
        return mmi_mte_get_image_sequence_total_size((PU8)image_ptr);   
    }

    return img_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_state
 * DESCRIPTION
 *  Set the MTE current state.
 * PARAMETERS
 *  state       [IN]    MTE state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_set_state(mmi_mte_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_mte_state = state;
}


/*
 * MMI interface API
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_active
 * DESCRIPTION
 *  Checks if the MTE is active.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: Inactive.
 *  1: Active. 
 *****************************************************************************/
S32 mmi_mte_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)g_mmi_mte_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_is_resource_replacement_working
 * DESCRIPTION
 *  Checks if the resource replacement is enabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: Disabled.
 *  1: Enabled.
 *****************************************************************************/
S32 mmi_mte_is_resource_replacement_working(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_image_folder_path)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_mmi_notify_screen_switch
 * DESCRIPTION
 *  Screen switch notification from MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_mmi_notify_screen_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_switch_screen_callback)
    {   
        /* 
         * cancel the screen switch timer from mmi_mte_mmi_notify_new_screen() to
         * prevent the category show function from refreshing again.
         */
        gui_cancel_timer(mmi_mte_mmi_notify_screen_switch);

        OSC_Sys_Schedule_Enable(0);
        g_mmi_mte_switch_screen_callback();
        OSC_Sys_Schedule_Enable(1);           
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_mmi_notify_new_screen
 * DESCRIPTION
 *  EntryNewScreen notification from MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mte_mmi_notify_new_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_mte_switch_screen_callback)
    {   
        gui_start_timer(0, mmi_mte_mmi_notify_screen_switch);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_image_resource_buffer_by_id
 * DESCRIPTION
 *  Loads the image resource from the file and returns the buffer pointer 
 *  for a specific image resource ID.
 * PARAMETERS
 *  image_id       [IN] image resource ID
 * RETURNS
 *  Image buffer pointer
 *****************************************************************************/
U8 *mmi_mte_get_image_resource_buffer_by_id(U32 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    U8      file_path[MMI_MTE_MAX_PATH_LEN];
    S32     resource_size;
    U8      *img_buf;
    U8      *old_resource_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MTE_SYSTEM_IMAGE_RESOURCE_NUM; i++)
    {        
        if (g_mmi_mte_img_resource[i].id == image_id)
        {
            if (g_mmi_mte_img_resource[i].path == NULL)
            {
                MTE_DEBUG("%d %s PATH NULL!\n", image_id, file_path);
                return NULL;
            }
            
            _snprintf(file_path, MMI_MTE_MAX_PATH_LEN - 1, "%s\\%s", g_mmi_mte_image_folder_path, g_mmi_mte_img_resource[i].path); 
            if (mmi_mte_load_image_resource_from_file(file_path, &resource_size) == 1)
            {
                MTE_DEBUG("%d %s NOT FOUND!\n", image_id, file_path);
                return NULL;
            }
            else
            {               
                i = mmi_mte_search_resource_mapping_table_by_id(image_id);
                
                if (i == -1)
                {   /* add a new entry */
                    if ((img_buf = mmi_mte_allocate_image_buffer(resource_size, (U8*)g_mmi_mte_image_buffer)) == NULL)
                    {
                        return NULL;
                    }
                    
                    g_mmi_mte_res_map_table[g_mmi_mte_resource_mapping_table_count].buf = img_buf;
                    g_mmi_mte_res_map_table[g_mmi_mte_resource_mapping_table_count].id = image_id;
                    g_mmi_mte_resource_mapping_table_count++;                    
                }               
                else
                {   /* replace an old entry */
                    old_resource_ptr = g_mmi_mte_res_map_table[i].buf;

                    /* 
                     * Allocate new buffer for the existing resource only if it is changed.
                     * This is a workaround for screens keeping pointers to image resources, such as the main menu.
                     */                                       
                    if (old_resource_ptr)
                    {
                        if ((mmi_mte_get_image_resource_size(old_resource_ptr) == resource_size - 8) &&
                            !memcmp(old_resource_ptr, g_mmi_mte_image_buffer, resource_size))
                        {                            
                            return old_resource_ptr;
                        }
                        
                        MTE_FREE(old_resource_ptr);
                    }

                    if ((img_buf = mmi_mte_allocate_image_buffer(resource_size, (U8*)g_mmi_mte_image_buffer)) == NULL)
                    {
                        return NULL;
                    }
                    
                    g_mmi_mte_res_map_table[i].buf = img_buf;                    
                }

                return img_buf;
            }
        }
    }        

    return NULL;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_get_value
 * DESCRIPTION
 *  Gets MTE system variables.
 * PARAMETERS
 *  name       [IN]     system variable name
 * RETURNS
 *  The specified MTE system variable value.
 *****************************************************************************/
void *mmi_mte_get_value(mmi_mte_system_value_enum name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((name >= 0) && (name < MMI_MTE_SYSTEM_VALUE_NUM));
    
    return g_mmi_mte_system_variable[name];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_value
 * DESCRIPTION
 *  Set the MTE system variable.
 * PARAMETERS
 *  name        [IN]    system varaible name
 *  value       [IN]    system variable value
 * RETURNS
 *  0: Successful.
 *  1: Failed.
 *****************************************************************************/
int mmi_mte_set_value(mmi_mte_system_value_enum name, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         str_len;
    void        *var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((name >= 0) && (name < MMI_MTE_SYSTEM_VALUE_NUM));

    switch (name)
    {
        case MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH:
        case MMI_MTE_SYSTEM_VALUE_TEMP_PATH:
            /* make sure the string length does not exceed the 1024 limitation */
            str_len = strlen(value);
            if (str_len > MMI_MTE_MAX_PATH_LEN)
            {
                return 1;
            }

            var = mmi_mte_get_value(name);
            if (var)
            {
                MTE_FREE(var);         
            }

            var = MTE_ALLOC(str_len + 1);
            g_mmi_mte_system_variable[name] = var;
            
            strcpy(var, value);
            break;
    
        default:
            break;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_encode_abm_image
 * DESCRIPTION
 *  Encodes a PNG or BMP image to an ABM image.
 * PARAMETERS
 *  mode                       [IN]     ABM encoder mode
 *  input_image_type           [IN]     input image type
 *  input_filename             [IN]     input filename
 *  output_abm_bitstream       [IN/OUT] output file name or output buffer
 *  output_size                [IN/OUT] output size in bytes
 * RETURNS
 *  MMI_MTE_ABMENC_NO_ERROR: success
 *  MMI_MTE_ABMENC_INPUT_TYPE_ERROR: only support BMP and PNG input
 *  MMI_MTE_ABMENC_PNG_CONVERT_ERROR: convert PNG to BMP by convert.exe error
 *  MMI_MTE_ABMENC_ABM_ENCODE_ERROR: convert BMP to ABM error
 *  MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR: output ABM file error
 *  MMI_MTE_ABMENC_OUTPUT_BUFFER_OVERFLOW: Output size is more than given. (only in MMI_MTE_ABMENC_MODE_OUTPUT_MEM mode)
 *****************************************************************************/
mmi_mte_abm_encoder_error_enum mmi_mte_encode_abm_image(mmi_mte_abmenc_mode_enum mode, mmi_mte_image_enum input_image_type, char *input_filename, char *output_abm_bitstream, int *output_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     ret;
    S32     w, h;
    PU8     abm_buf_p;

    S8      *output_abm_filename;
    S8      command_line_str[MMI_MTE_MAX_PATH_LEN * 3];    
    S8      temp_filename[MMI_MTE_MAX_PATH_LEN];
    FILE    *fp;
    S32     output_buffer_limit_size;

    MMI_BOOL    is_temp_file_exist;

    U8      bitmap_header[54];
   // U32     bitmap_bpp, bitmap_compression;

    U8      encode_input_type;
    U32     encode_option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OSC_Sys_Schedule_Enable(0);
    output_buffer_limit_size = *output_size;
    is_temp_file_exist = MMI_FALSE;
        
    /* only accept BMP and PNG input formats */
    if ((input_image_type != MMI_MTE_IMAGE_BMP_TO_ABM) && (input_image_type != MMI_MTE_IMAGE_BMP_TO_AB2) &&
        (input_image_type != MMI_MTE_IMAGE_PNG_TO_ABM) && (input_image_type != MMI_MTE_IMAGE_PNG_TO_AB2))
    {
        OSC_Sys_Schedule_Enable(1);
        return MMI_MTE_ABMENC_INPUT_TYPE_ERROR;
    }

    temp_filename[MMI_MTE_MAX_PATH_LEN - 1] = 0;

    /* use convert.exe to convert PNG to BMP first */
    if ((input_image_type == MMI_MTE_IMAGE_PNG_TO_ABM) || (input_image_type == MMI_MTE_IMAGE_PNG_TO_AB2))
    {   /* PNG to ABM */
        _snprintf(temp_filename, MMI_MTE_MAX_PATH_LEN - 1, "%s%s", mmi_mte_get_value(MMI_MTE_SYSTEM_VALUE_TEMP_PATH), MMI_MTE_ABM_TEMP_FILENAME);    
        _snprintf(
            command_line_str, 
            MMI_MTE_MAX_PATH_LEN * 3 - 1, 
            "\"\"%s\" -channel Alpha -negate -compress none png32:\"%s\" bmp:\"%s\"\"", 
            mmi_mte_get_value(MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH), 
            input_filename, 
            temp_filename);

        /* change input filename to the converted temp filename */            
        input_filename = temp_filename;

        if (system(command_line_str))
        {
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_PNG_CONVERT_ERROR;
        }

        is_temp_file_exist = MMI_TRUE;
    }
    else
    {   /* BMP to ABM */
        fp = fopen(input_filename, "rb");
        if (fp == NULL)
        {
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_INPUT_TYPE_ERROR;
        }

        /* read bitmap header at once */
        if (fread(bitmap_header, 54, 1, fp) != 1)
        {
            fclose(fp);
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_INPUT_TYPE_ERROR;
        }

        /* check the BM signature */
        if ((bitmap_header[0] != 'B') || (bitmap_header[1] != 'M'))
        {
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_INPUT_TYPE_ERROR;
        }

        fclose(fp);
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
#endif		
    }

    output_abm_filename = output_abm_bitstream;
    w = h = 0;
    abm_buf_p = (PU8)g_mmi_mte_image_buffer;    

    if ((input_image_type == MMI_MTE_IMAGE_PNG_TO_ABM) || (input_image_type == MMI_MTE_IMAGE_PNG_TO_AB2))
    {
        encode_input_type = IMAGE_TYPE_PNG;
    }
    else
    {
        encode_input_type = IMAGE_TYPE_BMP;
    }
    
    if ((input_image_type == MMI_MTE_IMAGE_BMP_TO_AB2) || (input_image_type == MMI_MTE_IMAGE_PNG_TO_AB2))
    {
        encode_option = ABM_ENC_OPTION_FLAG_AB2;
    }
    else
    {
        encode_option = ABM_ENC_OPTION_FLAG_ABM;
    }

    ret = ABM_load(
        (PU8)input_filename,
        __MMI_DEVICE_BMP_FORMAT__,
        encode_input_type,
        encode_option,
        abm_buf_p,
        output_size,
        &w,
        &h, MMI_FALSE, NULL);    

    /* remove the temporary BMP file */
    if (is_temp_file_exist)
    {
        remove(temp_filename);
    }

    /* ABM encoder failure */
    if ((w == 0) && (h == 0) || (ret == ABM_ENC_RETURN_KEEP_ORIGINAL))
    {
        OSC_Sys_Schedule_Enable(1);
        return MMI_MTE_ABMENC_ABM_ENCODE_ERROR;
    }

    /* file output mode, save the bitstream to the output file */
    if (mode == MMI_MTE_ABMENC_MODE_OUTPUT_FILE)
    {
        if ((fp = fopen(output_abm_filename, "wb")) == NULL)
        {
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR;
        }
       
        if (fwrite(abm_buf_p, *output_size, 1, fp) != 1)
        {
            fclose(fp);
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_OUTPUT_ABM_FILE_ERROR;
        }

        fclose(fp);            
    }
    else
    {
        if (*output_size > output_buffer_limit_size)
        {
            OSC_Sys_Schedule_Enable(1);
            return MMI_MTE_ABMENC_OUTPUT_BUFFER_OVERFLOW;
        }
    
        /* buffer output mode, simply memcpy */
        memcpy(output_abm_bitstream, abm_buf_p, *output_size);
    }
    if (ret == ABM_ENC_RETURN_USE_ABM )
    {
        OSC_Sys_Schedule_Enable(1);
        return MMI_MTE_ABMENC_NO_ERROR;
}
    else
    {
        OSC_Sys_Schedule_Enable(1);
        return MMI_MTE_AB2ENC_NO_ERROR;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mte_set_system_theme
 * DESCRIPTION
 *  Sets the default theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mte_set_system_theme(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_APPLICATION__
#ifdef __MMI_THEMES_V2_SUPPORT__
    /* DLT begins with 1. */
    mmi_tm_activate_theme(1);
#else /* __MMI_THEMES_V2_SUPPORT__ */           
#ifdef __COSMOS_MMI__
    index = 0;
#else
    if (index >= g_thm_cntx.TotalTheme)
        index = 0;
    g_thm_cntx.CurrTheme = index;   
#endif
    
    SetThemes(index);
#endif /* __MMI_THEMES_V2_SUPPORT__ */
#endif /* __MMI_THEMES_APPLICATION__ */    
}


static void mmi_mte_activate_entry(void)
{
//    if (mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_MTE_EXAMPLE, NULL, mmi_mte_activate_entry, MMI_FRM_UNKNOW_SCRN))
    if (mmi_frm_scrn_enter(GRP_ID_DUMMY_MTE_EXAMPLE, SCRN_ID_DUMMY_MTE_EXAMPLE, NULL, mmi_mte_activate_entry, MMI_FRM_UNKNOW_SCRN))
    {
        mmi_frm_scrn_clear_attribute(GRP_ID_DUMMY_MTE_EXAMPLE, SCRN_ID_DUMMY_MTE_EXAMPLE, MMI_SCRN_ATTRIB_ADD_HISTORY);
        ShowCategoryDummyScreen();
    }
}


#else /* __MTK_TARGET__ */

/* avoid the target compilation warning */
char g_mmi_mte_avoid_warning;

#endif /* __MTK_TARGET__ */



