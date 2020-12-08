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
 *  gdi_image.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI image drawing functions..
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "gdi_trc.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "mmi_fw_trc.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "CustDataRes.h"
#include "string.h"

#include "gdi_internal.h"
#include "gdi_features.h"
#include "gdc_include.h"
#include "gdi_util.h"

#include "gui.h"
#include "drm_gprot.h"

#include "lcd_sw_inc.h"
#include "gdi_image.h"
#include "gdi_image_bmp.h"
#include "gdi_image_sequence.h"
#include "gdi_image_gif.h"
#include "gdi_image_dev_bmp.h"
#include "gdi_image_wbmp.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_png.h"
#include "gdi_image_virtualfile.h"
#include "gdi_image_alpha_bmp.h"
#include "gdi_image_alpha_bmp_v2.h"
#include "gdi_image_9slice.h"
#include "gdi_image_ktx.h"
#include "gdi_imgdec_internal.h"
#include "gdi_image_mav.h"
#include "med_smalloc.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "drv_comm.h"
#include "gdi_animate.h"
#include "stdio.h"
#include "stack_config.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "app_str.h"


/* GraphicLib's header */
#ifdef GDI_USING_TV_OUTPUT
#include "mdi_datatype.h"
#include "mdi_tv.h"
#endif /* GDI_USING_TV_OUTPUT */ 

#include "mmi_frm_gprot.h"

#include "med_global.h"
#include "med_api.h"    /* media task */
#include "med_main.h"
#include "med_utility.h"


#if defined(GDI_USING_JPEG_ENCODE_V2)
#include "jpeg_enum.h"
#include "jpeg_encode_api.h"
#include "jpeg_decode_api.h"
#endif

#if defined(GDI_IMAGE_PROFILE)
    #include "gui_themes.h"
    #include "app_str.h"
    #include "ProfilingEngine.h"


    #if  (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__NOR_FLASH_BOOTING__)) && defined(__MTK_TARGET__)
        extern kal_bool   NFB_SecondaryImageLoaded;
    #endif
#endif

U16 * const gdi_image_ext_name[] = 
{
    // #define GDI_IMAGE_TYPE_INVALID                               0
    L"",
    // #define GDI_IMAGE_TYPE_BMP                                   1
    L".bmp",
    // #define GDI_IMAGE_TYPE_BMP_SEQUENCE                          2
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF                                   3
    L".gif",
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP                         4
    L".pbm",
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE                5
    L".pbm",
    // #define GDI_IMAGE_TYPE_BMP_FILE                              6
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF_FILE                              7
    L".gif",
    // #define GDI_IMAGE_TYPE_WBMP_FILE                             8
    L".wbmp",
    // #define GDI_IMAGE_TYPE_JPG                                   9
    L".jpg",
    // #define GDI_IMAGE_TYPE_JPG_FILE                              10
    L".jpg",
    // #define GDI_IMAGE_TYPE_WBMP                                  11
    L".wbmp",
    // #define GDI_IMAGE_TYPE_AVI                                   12
    L".avi",
    // #define GDI_IMAGE_TYPE_AVI_FILE                              13
    L".avi",
    // #define GDI_IMAGE_TYPE_3GP                                   14
    L".3gp",
    // #define GDI_IMAGE_TYPE_3GP_FILE                              15
    L".3gp",
    // #define GDI_IMAGE_TYPE_MP4                                   16
    L".mp4",
    // #define GDI_IMAGE_TYPE_MP4_FILE                              17
    L".mp4",
    // #define GDI_IMAGE_TYPE_JPG_SEQUENCE                          18
    L".jpg",
    // #define GDI_IMAGE_TYPE_PNG                                   19
    L".png",
    // #define GDI_IMAGE_TYPE_PNG_FILE                              20
    L".png",
    // #define GDI_IMAGE_TYPE_PNG_SEQUENCE                          21
    L".png",
    // #define GDI_IMAGE_TYPE_DEVICE_BMP_FILE                       22
    L".pbm",
    // #define GDI_IMAGE_TYPE_BMP_FILE_OFFSET                       23
    L".bmp",
    // #define GDI_IMAGE_TYPE_GIF_FILE_OFFSET                       24
    L".gif",
    // #define GDI_IMAGE_TYPE_M3D                                   25
    L".m3d",
    // #define GDI_IMAGE_TYPE_M3D_FILE                              26
    L".m3d",
    // #define GDI_IMAGE_TYPE_SVG                                   27
    L".svg",
    // #define GDI_IMAGE_TYPE_SVG_FILE                              28
    L".svg",
    //#define GDI_IMAGE_TYPE_SWFLASH                                29
    L".cmp",
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE                           30
    L".cmp",
    //#define GDI_IMAGE_TYPE_JPG_FILE_OFFSET                        31
    L".jpg",
    //#define GDI_IMAGE_TYPE_PNG_FILE_OFFSET                        32
    L".png",
    //#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET                 33
    L".pbm",
    //#define GDI_IMAGE_TYPE_WBMP_FILE_OFFSET                       34
    L".wbmp",
    //#define GDI_IMAGE_TYPE_M3D_FILE_OFFSET                        35
    L".m3d",
    //#define GDI_IMAGE_TYPE_SVG_FILE_OFFSET                        36
    L".svg",
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET                    37
    L".cmp",
    //#define GDI_IMAGE_TYPE_AVATAR                                 38    
    L".m3d",
    // #define GDI_IMAGE_TYPE_ABM_FILE_OFFSET                       39
    L".abm",
    // #define GDI_IMAGE_TYPE_ABM                                   40
    L".abm",    
    // #define GDI_IMAGE_TYPE_ABM_SEQUENCE                          41
    L".abm",    
    // #define GDI_IMAGE_TYPE_ABM_FILE                              42
    L".abm",    
    //#define GDI_IMAGE_TYPE_MPG                                    43
    L".mpg",
    //#define GDI_IMAGE_TYPE_MPG_FILE                               44
    L".mpg",
    //#define GDI_IMAGE_TYPE_MPG_FILE_OFFSET                        45
    L".mpg",
    //#define GDI_IMAGE_TYPE_3G2                                    46
    L".3g2",
    //#define GDI_IMAGE_TYPE_3G2_FILE                               47
    L".3g2",
    //#define GDI_IMAGE_TYPE_3G2_FILE_OFFSET                        48
    L".3g2",
    //#define GDI_IMAGE_TYPE_VIS                                    49
    L".vis",
    //#define GDI_IMAGE_TYPE_VIS_FILE                               50
    L".vis",
    //#define GDI_IMAGE_TYPE_BMP_MEM                                51
    L".bmp",
    //#define GDI_IMAGE_TYPE_AB2                                    52
    L".ab2",
    //#define GDI_IMAGE_TYPE_AB2_SEQUENCE                           53
    L".ab2",
    //#define GDI_IMAGE_TYPE_AB2_FILE                               54
    L".ab2",
    //#define GDI_IMAGE_TYPE_AB2_FILE_OFFSET                        55
    L".ab2",
    //#define GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET               56
    L".bmp",
    //#define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET     57
    L".pbm",
    //#define GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET               58
    L".jpg",
    //#define GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET               59
    L".png",
    //#define GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET               60
    L".abm",
    //#define GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET               61
    L".ab2",
    //#define GDI_IMAGE_TYPE_9SLICE                                 62
    L".9slice",
    //#define GDI_IMAGE_TYPE_9SLICE_FILE                            63
    L".9slice",
    //#define GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET                     64
    L".9slice",
    //#define GDI_IMAGE_TYPE_RM                                     65
    L".rm",
    //#define GDI_IMAGE_TYPE_RA                                     66
    L".ra",
    //#define GDI_IMAGE_TYPE_KTX                                    67
    L".ktx",
    //#define GDI_IMAGE_TYPE_KTX_FILE                               68
    L".ktx",
    // #define GDI_IMAGE_TYPE_MAV						69
    L".mav",
    // #define GDI_IMAGE_TYPE_MAV_FILE					70
    L".mav",
    //#define GDI_IMAGE_TYPE_SUM                                    71
    L""
};

/****************************************************************************
* Local Variable
*****************************************************************************/
#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
static const U8 *gdi_image_single_bank_cache_src;
static S32 gdi_image_single_bank_cache_size;
static U32 gdi_image_single_bank_cache_buf[GDI_IMAGE_SINGLE_BANK_CACHE_SIZE/4];
#endif

const gdi_image_codecs_struct gdi_image_codecs[GDI_IMAGE_TYPE_SUM + 1] = 
{
    // #define GDI_IMAGE_TYPE_INVALID                                       0
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_BMP                                           1
    {
     NULL,
     gdi_image_bmp_draw_handler,
     NULL,
     gdi_image_bmp_get_dimension_handler,
     NULL,
     NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_BMP_SEQUENCE                          2
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL,MMI_TRUE},
    // #define GDI_IMAGE_TYPE_GIF                                                   3
    {
     NULL,
     gdi_image_gif_draw_handler,
     NULL,
     gdi_image_gif_get_dimension_handler,
     gdi_image_gif_get_pos_info_handler,
     NULL,MMI_TRUE},

    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP                         4
    { NULL,
      gdi_image_dev_bmp_draw_handler,
      NULL,
      gdi_image_dev_bmp_get_dimension_handler,
      NULL,
      NULL,
      MMI_FALSE },
    // #define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE        5
    { NULL, NULL, NULL, NULL, NULL, NULL, MMI_FALSE },

    // #define GDI_IMAGE_TYPE_BMP_FILE                                      6
    {
     NULL,
     gdi_image_bmp_draw_handler,
     NULL,
     gdi_image_bmp_get_dimension_handler,
     NULL,
     gdi_image_is_bmp_file,MMI_FALSE
     },
    // #define GDI_IMAGE_TYPE_GIF_FILE                                      7
    {
     NULL,
     gdi_image_gif_draw_handler,
     NULL,
     gdi_image_gif_get_dimension_handler,
     gdi_image_gif_get_pos_info_handler,
     gdi_image_is_gif_file,MMI_TRUE},
    // #define GDI_IMAGE_TYPE_WBMP_FILE                                     8
    #if defined(GDI_USING_WBMP)
    {
     NULL,
     gdi_image_wbmp_draw_handler,
     NULL,
     gdi_image_wbmp_get_dimension_handler,
     NULL,
     gdi_image_is_wbmp_file,MMI_FALSE},
    #else
    {
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,MMI_FALSE},
    #endif
    // #define GDI_IMAGE_TYPE_JPG                                                   9
    {
     NULL,
     gdi_image_jpeg_draw_handler,
     NULL,
     gdi_image_jpeg_get_dimension_handler,
     NULL,
     NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_JPG_FILE                                      10
    {
     NULL,
     gdi_image_jpeg_draw_handler,
     NULL,
     gdi_image_jpeg_get_dimension_handler,
     NULL,
     gdi_image_is_jpeg_file,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_WBMP                                          11
    #if defined(GDI_USING_WBMP)
    {
     NULL,
     gdi_image_wbmp_draw_handler,
     NULL,
     gdi_image_wbmp_get_dimension_handler,
     NULL,
     NULL,MMI_FALSE},
    #else
    {
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,MMI_FALSE},
    #endif
    // #define GDI_IMAGE_TYPE_AVI                                                   12
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_AVI_FILE                                      13
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_3GP                                                   14
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_3GP_FILE                                      15
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_MP4                                           16
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_MP4_FILE                                      17
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_JPG_SEQUENCE                          18
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL,MMI_TRUE},
    // #define GDI_IMAGE_TYPE_PNG                                           19
    {
     NULL,
     gdi_image_png_draw_handler,
     NULL,
     gdi_image_png_get_dimension_handler,
     NULL,
     NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_PNG_FILE                                      20
    {
     NULL,
     gdi_image_png_draw_handler,
     NULL,
     gdi_image_png_get_dimension_handler,
     NULL,
     gdi_image_is_png_file,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_PNG_SEQUENCE                          21
    {
     NULL,
     gdi_image_sequence_draw_handler,
     NULL,
     gdi_image_sequence_get_dimension_handler,
     gdi_image_sequence_get_pos_info_handler,
     NULL,MMI_TRUE},
    // #define GDI_IMAGE_TYPE_DEVICE_BMP_FILE                       22
    #if defined(GDI_USING_PBM)
    {
     NULL,
     gdi_image_dev_bmp_draw_handler,
     NULL,
     gdi_image_dev_bmp_get_dimension_handler,
     NULL,
     gdi_image_is_device_bmp_file,MMI_FALSE},
    #else
    {
     NULL,
     NULL,//gdi_image_dev_bmp_draw_handler,
     NULL,
     NULL,//gdi_image_dev_bmp_get_dimension_handler,
     NULL,
     NULL,/*gdi_image_is_device_bmp_file,*/MMI_FALSE},
     #endif
    // #define GDI_IMAGE_TYPE_BMP_FILE_OFFSET                       23
    {
     NULL,
     gdi_image_virtualfile_draw_handler,
     NULL,
     gdi_image_virtualfile_get_dimension_handler,
     gdi_image_virtualfile_get_pos_info_handler,
     NULL,MMI_FALSE},
    // #define GDI_IMAGE_TYPE_GIF_FILE_OFFSET                       24
    {
     NULL,
     gdi_image_virtualfile_draw_handler,
     NULL,
     gdi_image_virtualfile_get_dimension_handler,
     gdi_image_virtualfile_get_pos_info_handler,
     NULL,MMI_TRUE},
    //#define GDI_IMAGE_TYPE_M3D                                 25
    //#define GDI_IMAGE_TYPE_M3D_FILE                         26
 #ifdef GDI_USING_M3D
    {
     gdi_image_m3d_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_get_pos_info_handler,
     NULL,MMI_TRUE},
    {
     gdi_image_m3d_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_get_pos_info_handler,
     gdi_image_is_m3d_file,MMI_TRUE},
 #else /* GDI_USING_M3D */ 
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
 #endif /* GDI_USING_M3D */ 

    // #define GDI_IMAGE_TYPE_SVG                                   27
    // #define GDI_IMAGE_TYPE_SVG_FILE                              28
#ifdef GDI_USING_SVG
    {
        gdi_image_svg_draw_before_handler,
        gdi_image_svg_draw_handler,
        gdi_image_svg_draw_after_handler,
        gdi_image_svg_get_dimension_handler,
        gdi_image_svg_get_pos_info_handler,
        NULL,MMI_TRUE
    },
    {
        gdi_image_svg_draw_before_handler,
        gdi_image_svg_draw_handler,
        gdi_image_svg_draw_after_handler,
        gdi_image_svg_get_dimension_handler,
        gdi_image_svg_get_pos_info_handler,
        gdi_image_is_svg_file,MMI_TRUE
    },
#else
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
#endif
    //#define GDI_IMAGE_TYPE_MFLASH                                 29
    //#define GDI_IMAGE_TYPE_MFLASH_FILE                            30
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
        
    //#define GDI_IMAGE_TYPE_JPG_FILE_OFFSET                        31
    //#define GDI_IMAGE_TYPE_PNG_FILE_OFFSET                        32
    //#define GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET                 33
    //#define GDI_IMAGE_TYPE_WBMP_FILE_OFFSET                       34
    //#define GDI_IMAGE_TYPE_M3D_FILE_OFFSET                        35
    //#define GDI_IMAGE_TYPE_SVG_FILE_OFFSET                        36
    //#define GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET                    37
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_TRUE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_TRUE},
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    //#define GDI_IMAGE_TYPE_AVATAR                                 38
#ifdef GDI_USING_AVATAR
    {
     gdi_image_m3d_avatar_draw_before_handler,
     gdi_image_m3d_draw_handler,
     gdi_image_m3d_draw_after_handler,
     gdi_image_m3d_get_dimension_handler,
     gdi_image_m3d_avatar_get_pos_info_handler,
     gdi_image_is_m3d_file,MMI_TRUE},
#else
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
#endif
    //#define GDI_IMAGE_TYPE_ABM_FILE_OFFSET                        39
    {NULL,gdi_image_virtualfile_draw_handler,NULL,gdi_image_virtualfile_get_dimension_handler,gdi_image_virtualfile_get_pos_info_handler,NULL,MMI_FALSE},
    //#define GDI_IMAGE_TYPE_ABM                                    40
    {
        NULL,
        gdi_image_abm_draw_handler,
        NULL,
        gdi_image_abm_get_dimension_handler,
        NULL,
        NULL,MMI_FALSE
    },
    //#define GDI_IMAGE_TYPE_ABM_SEQUENCE                           41
    {
        NULL,
        gdi_image_sequence_draw_handler,
        NULL,
        gdi_image_sequence_get_dimension_handler,
        gdi_image_sequence_get_pos_info_handler,
        NULL,MMI_TRUE
    },
    //#define GDI_IMAGE_TYPE_ABM_FILE                               42
    {
        NULL,
        gdi_image_abm_draw_handler,
        NULL,
        gdi_image_abm_get_dimension_handler,
        NULL,
        NULL,MMI_FALSE
    },    
    
    //#define GDI_IMAGE_TYPE_MPG                                    43
    //#define GDI_IMAGE_TYPE_MPG_FILE                               44
    //#define GDI_IMAGE_TYPE_MPG_FILE_OFFSET                        45
    //#define GDI_IMAGE_TYPE_3G2                                    46
    //#define GDI_IMAGE_TYPE_3G2_FILE                               47
    //#define GDI_IMAGE_TYPE_3G2_FILE_OFFSET                        48
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},

    //#define GDI_IMAGE_TYPE_VIS                                    49
    //#define GDI_IMAGE_TYPE_VIS_FILE                               50
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},

    //#define GDI_IMAGE_TYPE_BMP_MEM                                51
    {
     NULL,
     gdi_image_bmp_draw_handler,
     NULL,
     gdi_image_bmp_get_dimension_handler,
     NULL,
     NULL,MMI_FALSE},
    //#define GDI_IMAGE_TYPE_AB2                                    52
    {
        NULL,
        gdi_image_ab2_draw_handler,
        NULL,
        gdi_image_ab2_get_dimension_handler,
        NULL,
        NULL, 
        MMI_FALSE
    },
    //#define GDI_IMAGE_TYPE_AB2_SEQUENCE                           53
    {
        NULL,
        gdi_image_sequence_draw_handler,
        NULL,
        gdi_image_sequence_get_dimension_handler,
        gdi_image_sequence_get_pos_info_handler,
        NULL,
        MMI_TRUE
    },
    //#define GDI_IMAGE_TYPE_AB2_FILE                               54
    {
        NULL,
        gdi_image_ab2_draw_handler,
        NULL,
        gdi_image_ab2_get_dimension_handler,
        NULL,
        gdi_image_is_ab2_file, 
        MMI_FALSE
    },    
    //#define GDI_IMAGE_TYPE_AB2_FILE_OFFSET                        55
    {
        NULL,
        gdi_image_virtualfile_draw_handler,
        NULL,
        gdi_image_virtualfile_get_dimension_handler,
        gdi_image_virtualfile_get_pos_info_handler,
        NULL, 
        MMI_FALSE},
    
    //#define GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET               56
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET               57
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET               58
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET               59
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET               60
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET               61
    {
        NULL,
        gdi_image_virtualfile_sequence_draw_handler,
        NULL,
        gdi_image_virtualfile_sequence_get_dimension_handler,
        gdi_image_virtualfile_sequence_get_pos_info_handler,
        NULL, 
        MMI_TRUE},

    //#define GDI_IMAGE_TYPE_9SLICE                                 62
    {
        NULL,
        gdi_image_9slice_draw_handler,
        NULL,
        gdi_image_9slice_get_dimension_handler,
        NULL,
        NULL, 
        MMI_FALSE},

    //#define GDI_IMAGE_TYPE_9SLICE_FILE                            63
    {
        NULL,
        gdi_image_9slice_draw_handler,
        NULL,
        gdi_image_9slice_get_dimension_handler,
        NULL,
        gdi_image_is_9slice_file, 
        MMI_FALSE},

    //#define GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET                     64
    {
        NULL,
        gdi_image_virtualfile_draw_handler,
        NULL,
        gdi_image_virtualfile_get_dimension_handler,
        gdi_image_virtualfile_get_pos_info_handler,
        NULL, 
        MMI_FALSE},

    //#define GDI_IMAGE_TYPE_RM_FILE                                65
    //#define GDI_IMAGE_TYPE_RA_FILE                                66
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE},
#if defined(__MMI_VUI_ENGINE__)

    //#define GDI_IMAGE_TYPE_KTX                                    67
    {
        NULL,
        gdi_image_ktx_draw_handler,
        NULL,
        gdi_image_ktx_get_dimension_handler,
        NULL,
        NULL, 
        MMI_FALSE},

    //#define GDI_IMAGE_TYPE_KTX_FILE                               68
    {
        NULL,
        gdi_image_ktx_draw_handler,
        NULL,
        gdi_image_ktx_get_dimension_handler,
        NULL,
        gdi_image_is_ktx_file, 
        MMI_FALSE},
 #endif
        
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
    //#define GDI_IMAGE_TYPE_MAV                                    69
    {
        NULL,
        gdi_image_mav_draw_handler,
        NULL,
        gdi_image_mav_get_dimension_handler,
        gdi_image_mav_get_pos_info_handler,
        NULL, 
        MMI_FALSE},

    //#define GDI_IMAGE_TYPE_MAV_FILE                               70
    {
        NULL,
        gdi_image_mav_draw_handler,
        NULL,
        gdi_image_mav_get_dimension_handler,
        gdi_image_mav_get_pos_info_handler,
        gdi_image_is_mav_file, 
        MMI_FALSE},
#else /* defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__) */
    {NULL, NULL, NULL, NULL, NULL, NULL, MMI_FALSE},
    {NULL, NULL, NULL, NULL, NULL, NULL, MMI_FALSE},
#endif

    //#define GDI_IMAGE_TYPE_SUM                                    71
    {NULL, NULL, NULL, NULL, NULL, NULL,MMI_FALSE}
};

BOOL gdi_memory_output = FALSE;
U16 gdi_memory_output_width;
U16 gdi_memory_output_height;
U32 gdi_memory_output_buffer_address;
U32 gdi_memory_output_buffer_size;
static U32 gdi_image_codec_flag_stack[8] = {0};
static U32 gdi_image_codec_flag_index = 0;

static kal_timerid gdi_image_timer; // this timer is for codec used
static S32 gdi_image_timer_count; // it is the total number of 0.5 seconds
static S32 gdi_image_timer_timeout_count ; // if gdi_image_timer_count > this value , it should be timeout
static BOOL gdi_image_timer_timeout_flag;

static BOOL gdi_image_abort_flag = FALSE;
static BOOL gdi_nb_is_high_priority_flag = FALSE;

static void (*gdi_image_progress_callback_ptr)(void *,S32,S32,S32,S32) = NULL;
static void*  gdi_image_progress_callback_arg;
static S32 gdi_image_progress_count; // this value is the previous progress callback timer_count

static S32 gdi_image_update_area_x1;
static S32 gdi_image_update_area_y1;
static S32 gdi_image_update_area_x2;
static S32 gdi_image_update_area_y2;

/*****************************************************************************
 * FUNCTION
 *  gdi_capability_decoder_concurrency
 * DESCRIPTION
 *  Get the concurrence capability of one image_type.
 *  ex. If GDI_CAPABILITY_NO_VIDEO is set in *no_concurrence_flag,
 *  means the decoding of the image_type can't run with VIDEO at the same time.
 * PARAMETERS
 *  image_type          : [IN]  gdi image type
 *  no_concurrence_flag : [OUT] combination of gdi_capability_decoder_concurrency_enum
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_capability_decoder_concurrency(U8 image_type, U32 *no_concurrence_flag)
{
    *no_concurrence_flag = 0;
    
    if (GDI_IMAGE_TYPE_INVALID == image_type || image_type >= GDI_IMAGE_TYPE_SUM)
    {
        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
    }

    // This API could be removed. Because jpeg can always run with video at the same time after HAL.
/*
    switch (image_type)
    {
        case GDI_IMAGE_TYPE_JPG:
        case GDI_IMAGE_TYPE_JPG_FILE:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
        case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET:
        //#if defined(MT6235) || defined(MT6235B)
            *no_concurrence_flag = 0;
        //#else
        //    *no_concurrence_flag = (GDI_CAPABILITY_NO_VIDEO | GDI_CAPABILITY_NO_CAMERA);
        //#endif
            break;
        
        default :
            *no_concurrence_flag = 0;
            break;
    }
*/
    return GDI_SUCCEED;
}

/****************************************************************************
* Gif Anim Internal Functions
*****************************************************************************/
static void gdi_image_timeout_handler(void *param)
{
    gdi_image_timer_count++;
    
    if(gdi_image_timer_count >= gdi_image_timer_timeout_count)
        gdi_image_timer_timeout_flag = TRUE;
    else
        kal_set_timer(gdi_image_timer, gdi_image_timeout_handler, (void*)0, KAL_TICKS_100_MSEC*5, 0); // 0.5 seconds
}

void gdi_image_set_timeout(S32 seconds)
{
    GDI_TRACE(GDI_TRC, GDI_TRC_53,//"gdi_image_codec set timeout = %d seconds"
        seconds);

    gdi_image_timer_timeout_count = seconds *2; // 1 count is 0.5 seconds 
    gdi_image_timer_count = 0;
    gdi_image_timer_timeout_flag = FALSE;
    kal_set_timer(gdi_image_timer, gdi_image_timeout_handler, (void*)0, KAL_TICKS_100_MSEC*5, 0); // 0.5 seconds
}

void gdi_image_clear_timeout(void)
{
    GDI_TRACE(GDI_TRC, GDI_TRC_54//"gdi_image_codec clean timeout"
        );
    kal_cancel_timer(gdi_image_timer);
}

void gdi_image_set_progress_callback(void (*ptr)(void *,S32,S32,S32,S32),void* arg)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_set_progress_callback)
    gdi_image_progress_callback_ptr = ptr;
    gdi_image_progress_callback_arg = arg;
    gdi_image_progress_count        = 0;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_set_progress_callback)
}

BOOL gdi_image_is_timeout(void)
{
    return gdi_image_timer_timeout_flag;
}

void gdi_image_set_abort(BOOL is_abort)
{
    gdi_image_abort_flag = is_abort;
}
BOOL gdi_image_is_abort(void)
{
    return gdi_image_abort_flag;
}

S32 gdi_image_progress_callback(void)
{
    /* This function is called by image decoders and ipp process(gdi_ipp_process). */
    /* Used to abort non-blocking process. */
    if(gdi_image_abort_flag) 
    {
        GDI_TRACE(GDI_TRC, GDI_TRC_55//"FORCE ABORT SUCCEED"
        );
        return 0;
    }
    if(gdi_image_timer_timeout_flag)
    {
        return 0;
    }

    if(gdi_image_progress_callback_ptr != NULL)
    if(gdi_image_progress_count < gdi_image_timer_count)
    {
        gdi_image_progress_count = gdi_image_timer_count;
        gdi_image_progress_callback_ptr (
                gdi_image_progress_callback_arg,
                gdi_image_update_area_x1,
                gdi_image_update_area_y1,
                gdi_image_update_area_x2,
                gdi_image_update_area_y2
                );
    }        

    return 1;
}

void gdi_image_set_update_area(S32 x1,S32 y1,S32 x2,S32 y2)
{
    gdi_image_update_area_x1 = x1;
    gdi_image_update_area_y1 = y1;
    gdi_image_update_area_x2 = x2;
    gdi_image_update_area_y2 = y2;
}

void gdi_image_get_update_area(S32 *x1,S32 *y1,S32 *x2,S32 *y2)
{
    *x1 = gdi_image_update_area_x1;
    *y1 = gdi_image_update_area_y1;
    *x2 = gdi_image_update_area_x2;
    *y2 = gdi_image_update_area_y2;
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_init
 * DESCRIPTION
 *  Init GDI Iamge module.
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_init(void)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_init)
    {
        gdi_image_timer = kal_create_timer("GDIMG");
        gdi_image_timer_timeout_flag = FALSE;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_init)
    return GDI_SUCCEED;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_resource_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_parse_resource_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size, S32 *frame_number, S32 *width, S32 *height)
{
    


	PU8 imgBuffer = NULL;
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(res_src))
		imgBuffer = res_src;
	else
		imgBuffer =  (PU8)GetImageData(res_src);
#else
	imgBuffer = res_src;
#endif
	GDI_DEBUG_ASSERT(imgBuffer);
	*img_type = imgBuffer[0];
	*frame_number = (S32)(U32) imgBuffer[1];

    switch (*img_type)
    {
        case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM_FILE_OFFSET:
        case GDI_IMAGE_TYPE_AB2_FILE_OFFSET:
        case GDI_IMAGE_TYPE_9SLICE_FILE_OFFSET:
		*width 		  = (S32)(( ((U32)imgBuffer[7])     <<4) | (((U32)imgBuffer[6]&0xF0)>>4));
		*height		  = (S32)(((((U32)imgBuffer[6])&0xF)<<8) |  ((U32)imgBuffer[5]         ));
		*img_size = (S32)(((U32)imgBuffer[4])<<16)|(((U32)imgBuffer[3])<<8)|(((U32)imgBuffer[2]));
		*data_ptr = imgBuffer;
		    break;
            
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET:
		*width 		  = (S32)(( ((U32)imgBuffer[7])     <<4) | (((U32)imgBuffer[6]&0xF0)>>4));
		*height		  = (S32)(((((U32)imgBuffer[6])&0xF)<<8) |  ((U32)imgBuffer[5]         ));
		*img_size = (S32) (imgBuffer[2]) | (S32) ((S32) imgBuffer[3] << 8) | (S32) ((S32) imgBuffer[4] << 16);
			// Here img_size is 0. To get img sequence data size, use gdi_image_sequence_get_data_len.
			// See gdi_image_get_buf_len.
            break;
   case GDI_IMAGE_TYPE_DEV_BMP:
            *width 		  = (S32)((U32)res_src[6]);
            *height		  = (S32)((U32)res_src[8]);
            *img_size = (*width) * (*height) * ((U8)res_src[4]) + 12;
            *data_ptr = res_src;
            break;           
        default:
		*width 		  = (S32)(( ((U32)imgBuffer[7])     <<4) | (((U32)imgBuffer[6]&0xF0)>>4));
		*height		  = (S32)(((((U32)imgBuffer[6])&0xF)<<8) |  ((U32)imgBuffer[5]         ));
		*img_size = (S32) (imgBuffer[2]) | (S32) ((S32) imgBuffer[3] << 8) | (S32) ((S32) imgBuffer[4] << 16);
		*data_ptr = imgBuffer + 8;
            break;
    }


#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	SetImageFlushable(res_src);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_id
 * DESCRIPTION
 *  stop a animation by handle
 * PARAMETERS
 *  image_id        [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_id(U16 image_id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            (U8*) GetImage(image_id),
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_file
 * DESCRIPTION
 *  get image dimension from a file
 * PARAMETERS
 *  image_name      [?]         
 *  width           [OUT]       
 *  height          [OUT]       
 *  U16(?)          [IN]        Image_id
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_file(S8 *image_name, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_FILE,
            (U8*) image_name,
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension
 * DESCRIPTION
 *  get image dimesion from resource
 * PARAMETERS
 *  image_ptr       [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension(U8 *image_ptr, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            width,
            height,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_dimension_mem
 * DESCRIPTION
 *  get image dimesion from memory
 * PARAMETERS
 *  image_ptr       [IN]        
 *  width           [OUT]       
 *  height          [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_dimension_mem(U8 img_type,U8 *img_ptr,S32 img_size,S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_dimension(
            GDI_IMAGE_SRC_FROM_MEMORY,
            img_ptr,
            img_type,
            img_size,
            width,
            height,
            0);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_id
 * DESCRIPTION
 *  get frame count of an animation from id
 * PARAMETERS
 *  image_id        [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count_id(U16 image_id, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            (U8*) GetImage(image_id),
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count
 * DESCRIPTION
 *  get frame count of an animation from memory
 * PARAMETERS
 *  image_ptr       [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count(U8 *image_ptr, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_file
 * DESCRIPTION
 *  get frame count of an animation from file
 * PARAMETERS
 *  image_ptr       [IN]        
 *  frame_count     [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count_file(U8 *image_ptr, S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_FILE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_mem
 * DESCRIPTION
 *  get frame count of an animation from memory
 * PARAMETERS
 *  image_type      [IN]    image type, ex. GDI_IMAGE_TYPE_GIF
 *  image_ptr       [IN]    image pointer
 *  image_size      [IN]    image size
 *  frame_count     [OUT]   frame count
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_count_mem(
            U8  image_type,
            U8  *image_ptr,
            S32 image_size,
            S32 *frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_count(
            GDI_IMAGE_SRC_FROM_MEMORY,
            image_ptr,
            image_type,
            image_size,
            frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_delay
 * DESCRIPTION
 *  get frame delay of each frame of an animation from memory
 * PARAMETERS
 *  image_ptr        [IN]       image data pointer
 *  frame_count      [OUT]      number of frames in image
 *  frame_delay_array[OUT]      delay time of each frame
 *  max_frame_count  [IN]       the size of frame_delay_array
 * RETURNS
 *  U16
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_delay(U8 *image_ptr, S32 *frame_count, U32 *frame_delay_array, U32 max_frame_count)
{
    return gdi_image_codec_get_frame_delay(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            frame_delay_array,
            max_frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_delay_file
 * DESCRIPTION
 *  get frame delay of each frame of an animation from file
 * PARAMETERS
 *  image_ptr        [IN]       image file name
 *  frame_count      [OUT]      number of frames in image
 *  frame_delay_array[OUT]      delay time of each frame
 *  max_frame_count  [IN]       the size of frame_delay_array
 * RETURNS
 *  U16
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_delay_file(U8 *image_ptr, S32 *frame_count, U32 *frame_delay_array, U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_delay(
            GDI_IMAGE_SRC_FROM_FILE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            frame_delay_array,
            max_frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_frame_count_id
 * DESCRIPTION
 *  get frame delay of each frame of an animation from image id
 * PARAMETERS
 *  image_id         [IN]       the resource id of image
 *  frame_count      [OUT]      number of frames in image
 *  frame_delay_array[OUT]      delay time of each frame
 *  max_frame_count  [IN]       the size of frame_delay_array
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_get_frame_delay_id(U16 image_id, S32 *frame_count, U32 *frame_delay_array, U32 max_frame_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_get_frame_delay(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            (U8*) GetImage(image_id),
            GDI_IMAGE_TYPE_INVALID,
            0,
            frame_count,
            frame_delay_array,
            max_frame_count,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_frame_delay
 * DESCRIPTION
 *  get frame delay of each frame of an animation from memory
 * PARAMETERS
 *  ptr        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
GDI_RESULT gdi_image_codec_get_frame_delay(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 *frame_count,
            U32 *frame_delay_array, 
            U32 max_frame_count,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data_ptr;
    S32 tmp1,tmp2;
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_get_frame_delay)
    
    ret = gdi_image_parse_info(src_type, img_src, &data_ptr, &img_type, &img_size, frame_count, &tmp1,&tmp2);
    if (ret != GDI_SUCCEED) GDI_RETURN(ret);

    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);

    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
    {
        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
    }
    else if (src_type == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
    }

    switch (img_type)
    {
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            ret = gdi_image_gif_get_frame_delay(flag, data_ptr, img_size, frame_count, frame_delay_array, max_frame_count);
            break;
        default:
            ret = GDI_IMAGE_ERR_INVALID_IMG_TYPE;
            break;
    }
    
    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_get_frame_delay)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_mem
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  ptr        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_mem_internal(U8 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p[0] == 'B' && p[1] == 'M')
        return GDI_IMAGE_TYPE_BMP;

    if (p[0] == 'G' && p[1] == 'I' && p[2] == 'F')
        return GDI_IMAGE_TYPE_GIF;

    if (p[0] == 0xff && p[1] == 0xd8 && p[2] == 0xff)
        return GDI_IMAGE_TYPE_JPG;

    if (memcmp((void*)p, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)
        return GDI_IMAGE_TYPE_PNG;

    if (p[0] == 'P' && p[1] == 'B' && p[2] == 'M')
        return GDI_IMAGE_TYPE_DEVICE_BITMAP;

    return (GDI_IMAGE_TYPE_INVALID);
}


static gdi_image_type gdi_image_get_type_from_file_header(kal_uint8 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_type type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = (gdi_image_type)gdi_image_get_type_from_mem_internal(p);

    switch (type)
    {
        case GDI_IMAGE_TYPE_BMP: return GDI_IMAGE_TYPE_BMP_FILE;
        case GDI_IMAGE_TYPE_GIF: return GDI_IMAGE_TYPE_GIF_FILE;
        case GDI_IMAGE_TYPE_JPG: return GDI_IMAGE_TYPE_JPG_FILE;
        case GDI_IMAGE_TYPE_PNG: return GDI_IMAGE_TYPE_PNG_FILE;

        default:
            if (p[0] == 'P' && p[1] == 'B' && p[2] == 'M')
                return GDI_IMAGE_TYPE_DEVICE_BMP_FILE;
    }

    return (GDI_IMAGE_TYPE_INVALID);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_mem
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  ptr        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_mem(PS8 ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_get_type_from_mem_internal((U8*)ptr);
}


static const WCHAR* gdi_image_get_file_ext_name(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR *ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = filepath;
    while (*ch != L'\0')
    {
        ch++;
    }

    /* Now ch at the end of filepath[] */
    while (ch != filepath)
    {
        ch--;
        switch (*ch)
        {
            case L'.':
                ch++;
                if (ch != L'\0')
                {
                    return ch;
                }
                else
                {
                    return NULL;
                }

            case L'/':
            case L'\\':
                return NULL;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_file_internal
 * DESCRIPTION
 *  get image type from file
 * PARAMETERS
 *  file_name       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_type_from_file_internal(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 type;
    U16 *ext;
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* null string */
    if (file_name == NULL)
    {
        return (GDI_IMAGE_TYPE_INVALID);
    }

    /* search the '.' from end of file_name */
    ext = (U16*)gdi_image_get_file_ext_name((WCHAR*)file_name);

    if (ext)    /* have ext name */
    {
		for(type=1;type<GDI_IMAGE_TYPE_SUM;type++)
		{
			if(gdi_image_codecs[type].is_match_file_type)
			{
				if(gdi_ucs2_stricmp((U16*)ext,(U16*)(gdi_image_ext_name[type]+1))==0)
				{
				    ret = gdi_image_codecs[type].is_match_file_type((U8*)file_name);
					if(GDI_SUCCEED == ret)
					{
						return type;
					}
					else if (GDI_IMAGE_ERR_INVALID_FILE == ret)
					{
					    return (GDI_IMAGE_TYPE_INVALID);
					}
				}
			}
		}
    }

    { /* Get the file type from header by single FS_Open() */
        FS_HANDLE f_handle;
        kal_uint8 header[16];

        f_handle = FS_Open((WCHAR*)file_name, FS_READ_ONLY);
        if (f_handle > 0)
        {
            kal_int32 f_ret, n_read;

            type = IMAGE_TYPE_INVALID;
            f_ret = FS_Read(f_handle, header, sizeof(header), &n_read);
            if (f_ret == FS_NO_ERROR && n_read == sizeof(header))
            {
                type = gdi_image_get_type_from_file_header(header);
            }
            FS_Close(f_handle);

            if (type != IMAGE_TYPE_INVALID)
            {
                return type;
            }
        }
    }

	// try again without ext information
	for(type=1;type<GDI_IMAGE_TYPE_SUM;type++)
	{
		if(gdi_image_codecs[type].is_match_file_type)
		{
			ret = gdi_image_codecs[type].is_match_file_type((U8*)file_name);
			if(GDI_SUCCEED == ret)
			{
				return type;
			}
			else if(GDI_IMAGE_ERR_INVALID_FILE == ret)
			{
			    break;
			}
		}
        }

    return (GDI_IMAGE_TYPE_INVALID);

#undef IC
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 gdi_image_get_type_from_file(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_get_type_from_file_internal(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_ext_name_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
const U16 *gdi_image_get_ext_name_from_file(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_ext_name[gdi_image_get_type_from_file_internal(file_name)];
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_ext_name_from_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const U16 *gdi_image_get_ext_name_from_file_type(U16 file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(file_type < GDI_IMAGE_TYPE_SUM);
    return gdi_image_ext_name[file_type];
}


static GDI_RESULT gdi_image_get_all_info_from_file(
    const WCHAR *filepath,
    gdi_image_info_struct *out_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR *ext_name;
    gdi_image_type image_type;
    const gdi_image_codecs_struct *codec_entry;
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(filepath != NULL && out_info != NULL);

    out_info->type = GDI_IMAGE_TYPE_INVALID;
    out_info->width = 0;
    out_info->height = 0;
    
    ext_name = gdi_image_get_file_ext_name(filepath);

    if (ext_name != NULL)
    {
        for (image_type = 0; image_type < GDI_IMAGE_TYPE_SUM; image_type++)
        {
            codec_entry = &(gdi_image_codecs[image_type]);
            if (codec_entry->is_match_file_type != NULL &&
                codec_entry->get_dimension != NULL &&
                app_ucs2_wcsicmp(gdi_image_ext_name[image_type] + 1, ext_name) == 0)
            {
                GDI_RESULT result;

                result = codec_entry->get_dimension(
                            GDI_IMAGE_CODEC_FLAG_IS_FILE,
                            (U8*)filepath,
                            0,
                            &(out_info->width),
                            &(out_info->height));

                if (result == GDI_SUCCEED)
                {
                    out_info->type = image_type;
                    return GDI_SUCCEED;
                }
            }
        }
    }

    /* Ignore ext name */
    
    { /* Get the file type from header by single FS_Open() */
        FS_HANDLE f_handle;
        kal_uint8 header[8];

        f_handle = FS_Open(filepath, FS_READ_ONLY);
        if (f_handle > 0)
        {
            kal_int32 f_ret, n_read;

            image_type = IMAGE_TYPE_INVALID;
            f_ret = FS_Read(f_handle, header, sizeof(header), &n_read);
            if (f_ret == FS_NO_ERROR && n_read == sizeof(header))
            {
                image_type = gdi_image_get_type_from_file_header(header);
            }
            FS_Close(f_handle);

            out_info->type = image_type;
            if (image_type != IMAGE_TYPE_INVALID)
            {
                codec_entry = &(gdi_image_codecs[image_type]);
                if (codec_entry->is_match_file_type != NULL &&
                    codec_entry->get_dimension != NULL)
                {
                    result = codec_entry->get_dimension(
                                GDI_IMAGE_CODEC_FLAG_IS_FILE,
                                (U8*)filepath,
                                0,
                                &(out_info->width),
                                &(out_info->height));

                    if (result == GDI_SUCCEED)
                    {
                        return result;
                    }
                }
            }
        }
    }

    /* General for no ext name & no header rule */
    for (image_type = 0; image_type < GDI_IMAGE_TYPE_SUM; image_type++)
    {
        codec_entry = &(gdi_image_codecs[image_type]);
        if (codec_entry->is_match_file_type != NULL &&
            codec_entry->get_dimension != NULL)
        {
            result = codec_entry->is_match_file_type((U8*)filepath);
            if (result != GDI_SUCCEED)
            {
                continue;
            }

            result = codec_entry->get_dimension(
                        GDI_IMAGE_CODEC_FLAG_IS_FILE,
                        (U8*)filepath,
                        0,
                        &(out_info->width),
                        &(out_info->height));

            if (result == GDI_SUCCEED)
            {
                out_info->type = image_type;
                return GDI_SUCCEED;
            }
        }
    }

    return GDI_FAILED;
}


static kal_bool gdi_image_is_alpha_type(gdi_image_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case GDI_IMAGE_TYPE_ABM:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
        case GDI_IMAGE_TYPE_ABM_FILE:
        case GDI_IMAGE_TYPE_AB2:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE:
        case GDI_IMAGE_TYPE_AB2_FILE:
        case GDI_IMAGE_TYPE_KTX:
        case GDI_IMAGE_TYPE_KTX_FILE:
        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            /* Not accurate, we should check header */
            return KAL_TRUE;
    }

    return KAL_FALSE;
}


GDI_RESULT gdi_image_get_info_from_file(
    const WCHAR *filepath,
    gdi_image_type *image_type,
    kal_int32 *width,
    kal_int32 *height,
    kal_bool *with_alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    gdi_image_type t_image_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t_image_type = GDI_IMAGE_TYPE_INVALID;
    if (width != NULL && height != NULL)
    {
        gdi_image_info_struct info;

        ret = gdi_image_get_all_info_from_file(filepath, &info);
        if (ret == GDI_SUCCEED)
        {
            t_image_type = info.type;
            *width = info.width;
            *height = info.height;
        }
    }
    else
    {
        t_image_type = (gdi_image_type)gdi_image_get_type_from_file((S8*)filepath);
        if (t_image_type != GDI_IMAGE_TYPE_INVALID)
        {
            ret = GDI_SUCCEED;
        }
    }

    if (ret == GDI_SUCCEED)
    {
        if (image_type != NULL)
        {
            *image_type = t_image_type;
        }
        if (with_alpha != NULL)
        {
            *with_alpha = gdi_image_is_alpha_type(t_image_type);
        }
    }

    return ret;
}


GDI_RESULT gdi_image_get_info_from_res_data(
    const kal_uint8 *res_data,
    gdi_image_type *image_type,
    kal_int32 *width,
    kal_int32 *height,
    kal_bool *with_alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 t_image_type;
    U8 *t_data_ptr;
    S32 t_img_size;
    S32 t_frame_number;
    S32 t_width, t_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_parse_resource_internal(
        (U8*)res_data,
        &t_data_ptr,
        &t_image_type,
        &t_img_size,
        &t_frame_number,
        &t_width,
        &t_height);

    if (image_type != NULL)
    {
        *image_type = t_image_type;
    }
    if (width != NULL)
    {
        *width = t_width;
    }
    if (height != NULL)
    {
        *height = t_height;
    }
    if (with_alpha != NULL)
    {
        *with_alpha = gdi_image_is_alpha_type(t_image_type);
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_output_another_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 *  src         [?]         
 *  size        [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_output_another_buffer(BOOL enable, U8 *src, U32 size, U16 width, U16 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER
    GDI_ENTER_CRITICAL_SECTION(gdi_image_output_another_buffer)
    gdi_memory_output = enable;
    gdi_memory_output_width = width;
    gdi_memory_output_height = height;
    gdi_memory_output_buffer_size = size;
    gdi_memory_output_buffer_address = (U32) src;
    GDI_EXIT_CRITICAL_SECTION(gdi_image_output_another_buffer)
    return GDI_SUCCEED;
#else /* GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER */ 
    return GDI_FAILED;
#endif /* GDI_HW_JPEG_SUPPORT_OUTPUT_ANOTHER_BUFFER */ 
    
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_type
 * DESCRIPTION
 *  check gdi decoder's capability
 * PARAMETERS
 *  image_id        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gdi_image_get_buf_type(U8 * image_ptr)
{
PU8 imgBuffer = NULL;
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(image_ptr))
		imgBuffer = image_ptr;
	else
	imgBuffer = (PU8)GetImageData(image_ptr); 
#else
	imgBuffer = image_ptr;
#endif

    if (imgBuffer == NULL)
        return GDI_IMAGE_TYPE_INVALID;

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
/* SInce we just need to provide information which has already been obtianed 
By locality of referenc e, i suspect this image needs to come back to cache soon*/
	SetImageFlushable(image_ptr);
#endif
    return (U16) imgBuffer[0];
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_buf_len
 * DESCRIPTION
 *  
 *****************************************************************************/
S32 gdi_image_get_buf_len(U8* res_src)
{
	U8* data_ptr;
	U8   img_type;
	S32 img_size;
	S32 frame_number;
	S32 width;
	S32 height;
	PU8 imgBuffer;

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(res_src))
		imgBuffer = res_src;
	else
		imgBuffer = (PU8)GetImageData(res_src);
#else
	imgBuffer = res_src;
#endif

    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_buf_len);
	gdi_image_parse_resource_internal(res_src, &data_ptr, &img_type, &img_size, &frame_number, &width, &height);

    switch (img_type)
    {
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE_FILE_OFFSET:
        case GDI_IMAGE_TYPE_AB2_SEQUENCE_FILE_OFFSET:

		gdi_image_sequence_get_data_len(imgBuffer, &img_size);
            break;
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_buf_len);
    
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	SetImageFlushable(res_src);
#endif
	return img_size;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_get_buf_ptr
 * DESCRIPTION
 *  
 *****************************************************************************/
U8 *gdi_image_get_buf_ptr(U8* res_src)
{
	U8* data_ptr;
	U8   img_type;
	S32 img_size;
	S32 frame_number;
	S32 width;
	S32 height;

    GDI_ENTER_CRITICAL_SECTION(gdi_image_get_buf_ptr);
	gdi_image_parse_resource_internal(res_src, &data_ptr, &img_type, &img_size, &frame_number, &width, &height);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_get_buf_ptr);
	
	return data_ptr;
}

void gdi_image_set_encoding_flag(U32 flag)
{
    /* This is an old API for app to set output jpeg format. */
    /*  #define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_440    0     // default value
        #define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_GRAY   (1<<0)
        #define GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_442    (1<<1)
    */
    //gdi_image_encoding_flag = flag;
}


GDI_RESULT gdi_image_encode_layer_to_jpeg(gdi_handle layer_handle, PS8 file_name)
{
    return gdi_image_encode_layer_to_jpeg_with_exp_size(
                layer_handle,
                file_name,
                0,
                NULL);
}


#if defined(GDI_USING_JPEG_ENCODE_V2)
/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_buffer_to_jpeg_in_memroy_V2
 * DESCRIPTION
 *  encode data in src_buf_ptr to a jpeg data. 
 *  output to dst_buf_ptr.
 *  If dst_buf_ptr is null, this API will alloc med buffer, and return the buffer by dst_buf_ptr_out.
 *  Remember to free dst_buf_ptr_out after using this API if dst_buf_ptr is NULL.
 *  output_buf_ptr is the start address of jpeg data, it may not equal to dst_buf_ptr_out.
 *  Because jpeg encode has alignment limitation. It may not output data from dst_buf_ptr_out.
 * PARAMETERS
 *  codec_type      [IN]    encoder type, hw or sw
 *  src_buf_ptr     [IN]    source buffer pointer
 *  dst_buf_ptr     [IN]    destination buffer pointer, it could be NULL.
 *  dst_buf_ptr_out [IN]    If dst_buf_ptr isn't null, it equal to dst_buf_ptr. If dst_buf_ptr is NULL, it return a buffer pointer from med memory.
 *  output_buf_ptr  [IN]    start address of jpeg data.
 *  output_buf_size [IN]    size of jpeg data
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
static GDI_RESULT gdi_image_encode_buffer_to_jpeg_in_memroy_V2(
                    JPEG_CODEC_TYPE_ENUM codec_type,
                    JPEG_RGB_FORMAT_ENUM src_color_format_RGB,
                    JPEG_YUV_FORMAT_ENUM src_color_format_UYVY,
                    void *src_buf_ptr,
                    kal_uint32 src_buf_size,
                    kal_uint32 src_width,
                    kal_uint32 src_height,
                    void *dst_buf_ptr,
                    kal_uint32 dst_buf_size,
                    void **dst_buf_ptr_out,
                    kal_uint8 **output_buf_ptr,
                    kal_uint32 *output_buf_size,
                    gdi_jpeg_encode_quality_enum quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    JPEG_CODEC_STATE_ENUM jpeg_state = JPEG_CODEC_STATE_FREE;
    JPEG_STATUS_ENUM jpeg_status = JPEG_STATUS_OK;
    JPEG_ENCODER_HANDLE jpeg_encoder_hdl;

    kal_uint32 intmemsize_max = 0, intmemsize_min = 0;
    kal_uint32 extmemsize_max = 0, extmemsize_min = 0;
    void *extmem = NULL;
    void *intmem = NULL;
    kal_bool intMem_isExt = KAL_FALSE;

    kal_uint8 *temp_dst_buf_ptr = NULL;
    kal_uint32 temp_dst_buf_size = 0;
    S32 start_time = 0, decode_ms = 0;
    JPEG_ENCODE_QUALITTY_ENUM jpeg_quality = JPEG_ENCODE_QUALITY_EXCELLENT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(output_buf_ptr != NULL);
    ASSERT(output_buf_size != NULL);
    
    *output_buf_ptr = NULL;
    *output_buf_size = 0;

    if (dst_buf_ptr_out != NULL)
    {
        *dst_buf_ptr_out = NULL;
    }
    
    GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_MEM_ENTER,//[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Enter - codec_type:%d src-size:%d w:%d h:%d dst-ptr:%x size:%d
        codec_type, src_buf_size, src_width, src_height, dst_buf_ptr, dst_buf_size);
    jpeg_status = jpegEncGetEncoder(codec_type, &jpeg_encoder_hdl);
    if (jpeg_status != JPEG_STATUS_OK)
    {
        GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_MEM_LEAVE,//[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Leave - ret:%d decode_ms:%d encode_size:%d
            ret, 0, 0);
        return GDI_FAILED;
    }

    if (codec_type == JPEG_CODEC_TYPE_HW)
    {
        GDI_IMGDEC_HW_LOCK();   /* prevent imgdec jpeg decoding at the same time */
    }

    do
    {
        /* set source */
        if (src_color_format_UYVY == JPEG_YUV_FORMAT_PACKED_UYVY422)
        {
            jpeg_status = jpegEncSetSrcMode(jpeg_encoder_hdl, JPEG_ENCODE_SOURCE_YUV_BUFFER);
            jpeg_status = jpegEncSetSrcYUVFormat(jpeg_encoder_hdl, src_color_format_UYVY);
            jpeg_status = jpegEncSetYUVBuffer(jpeg_encoder_hdl, src_buf_ptr, NULL, NULL, src_buf_size, 0, 0);
        }
        else
        {
            jpeg_status = jpegEncSetSrcMode(jpeg_encoder_hdl, JPEG_ENCODE_SOURCE_RGB_BUFFER);
            jpeg_status = jpegEncSetSrcRGBFormat(jpeg_encoder_hdl, src_color_format_RGB);
            jpeg_status = jpegEncSetRGBBuffer(jpeg_encoder_hdl, src_buf_ptr, src_buf_size);
        }
        
        jpeg_status = jpegEncSetSrcDimension(jpeg_encoder_hdl, src_width, src_height);
        if (jpeg_status != JPEG_STATUS_OK){break;}

        /* set destination */
        jpeg_status = jpegEncSetDstDimension(jpeg_encoder_hdl, src_width, src_height);
        jpeg_status = jpegEncSetDirectFileOutputHandle(jpeg_encoder_hdl, NULL);
        jpeg_status = jpegEncSetDstFileFormat(jpeg_encoder_hdl, JPEG_FILE_FORMAT_JPEG); 
        switch(quality)
        	{
            case GDI_JPEG_ENCODE_QUALITY_LOW:
                jpeg_quality = JPEG_ENCODE_QUALITY_LOW;
                break;
            case GDI_JPEG_ENCODE_QUALITY_FAIR:
                jpeg_quality = JPEG_ENCODE_QUALITY_FAIR;
                break;
            case GDI_JPEG_ENCODE_QUALITY_GOOD:
                jpeg_quality = JPEG_ENCODE_QUALITY_GOOD;
                break;
            case GDI_JPEG_ENCODE_QUALITY_EXCELLENT:
                jpeg_quality = JPEG_ENCODE_QUALITY_EXCELLENT;
                break;
            case GDI_JPEG_ENCODE_QUALITY_POOR:
                jpeg_quality = JPEG_ENCODE_QUALITY_POOR;
                break;
            default:
                GDI_ASSERT(0);
        }
        jpeg_status = jpegEncSetDstQuality(jpeg_encoder_hdl, jpeg_quality); 
        jpeg_status = jpegEncSetDstSampleFormat(jpeg_encoder_hdl, JPEG_YUV_FORMAT_YUV422); 
        jpeg_status = jpegEncSetDstThumbnail(jpeg_encoder_hdl, KAL_FALSE, 0, 0);
        if (jpeg_status != JPEG_STATUS_OK){break;}

        /* working memory */
        jpeg_status = jpegEncQueryWorkingMemory(jpeg_encoder_hdl, &intmemsize_max, &intmemsize_min, &extmemsize_max, &extmemsize_min);
        if (jpeg_status != JPEG_STATUS_OK){break;}

        if (intmemsize_max)
        {
            while(1)
            {
                if (codec_type == JPEG_CODEC_TYPE_SW)
                {
                    intmem = (void *)gdi_alloc_ext_mem_cacheable(intmemsize_max);
                    intMem_isExt = KAL_TRUE;
                }
                else
                {
                    intmem = (void *)med_alloc_int_mem(intmemsize_max);
                }

                if ((intmem != NULL) || (intmemsize_max == intmemsize_min))
                {
                    break;
                }
                
                intmemsize_max = intmemsize_max >> 1;
                if (intmemsize_max < intmemsize_min)
                {
                    intmemsize_max = intmemsize_min;
                }
            }
            
            if (!intmem)
            {
                intmem = (void *)gdi_alloc_ext_mem(intmemsize_max);
                intMem_isExt = KAL_TRUE;
                if (!intmem)
                {
                    ret = GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH;
                    break;
                }
            }
        }

        if (extmemsize_max)
        {
            while(1)
            {
                extmem = (void *)gdi_alloc_ext_mem(extmemsize_max);
                if ((extmem != NULL) || (extmemsize_max == extmemsize_min))
                {
                    break;
                }
                extmemsize_max = extmemsize_max >> 1;
                if (extmemsize_max < extmemsize_min)
                {
                    extmemsize_max = extmemsize_min;
                }
            }
            
            if (!extmem)
            {
                ret = GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH;
                break;
            }
        }

        jpeg_status = jpegEncSetWorkingMemory(jpeg_encoder_hdl, intmem, intmemsize_max, extmem, extmemsize_max);
        if (jpeg_status != JPEG_STATUS_OK){break;}

        /* set destination */
        if (dst_buf_ptr == NULL)
        {
            kal_uint32 temp_dst_buf_size_min = 2048;    // The dst buffer have larger than 607byte (jpeg header)

            temp_dst_buf_size = src_buf_size;            
            if (temp_dst_buf_size < temp_dst_buf_size_min)
            {
                temp_dst_buf_size = temp_dst_buf_size_min;
            }
            while(1)
            {
                temp_dst_buf_ptr = (kal_uint8*)gdi_alloc_ext_mem(temp_dst_buf_size);
                if ((temp_dst_buf_ptr != NULL) || (temp_dst_buf_size == temp_dst_buf_size_min))
                {
                    break;
                }
                temp_dst_buf_size -= 1024;
                if (temp_dst_buf_size < temp_dst_buf_size_min)
                {
                    temp_dst_buf_size = temp_dst_buf_size_min;
                }
            }

            if (dst_buf_ptr_out != NULL)
            {
                *dst_buf_ptr_out = (void*)temp_dst_buf_ptr;
            }
            jpeg_status = jpegEncSetDstBuffer(jpeg_encoder_hdl, temp_dst_buf_ptr, temp_dst_buf_size);
            if (jpeg_status != JPEG_STATUS_OK){break;}
        }
        else
        {
            if (dst_buf_ptr_out != NULL)
            {
                *dst_buf_ptr_out = dst_buf_ptr;
            }
            jpeg_status = jpegEncSetDstBuffer(jpeg_encoder_hdl, dst_buf_ptr, dst_buf_size);
            if (jpeg_status != JPEG_STATUS_OK){break;}
        }
        
        // start encode
        jpeg_status = jpegEncSetCallbackFunction(jpeg_encoder_hdl, NULL);
        jpeg_state = JPEG_CODEC_STATE_BUSY;
        start_time = drv_get_current_time();
        jpeg_status = jpegEncStart(jpeg_encoder_hdl);
        GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_MEM_START,//[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Start - status:%d
            jpeg_status);
        do
        {
            if (jpeg_status != JPEG_STATUS_OK)
            {
                *output_buf_size = 0;
                *output_buf_ptr = NULL;
                break;
            }
            /// the following is to simulate the behavior of message handler
            while (JPEG_CODEC_STATE_COMPLETE != jpeg_state && JPEG_CODEC_STATE_ERROR != jpeg_state)
            {
                jpeg_status = jpegEncGetEncoderState(jpeg_encoder_hdl, &jpeg_state);

                switch (jpeg_state) {
                case JPEG_CODEC_STATE_BUSY:
                    break;

                case JPEG_CODEC_STATE_PAUSED:
                    break;
                }
            } 

            if (JPEG_CODEC_STATE_COMPLETE == jpeg_state)
            {
                jpeg_status = jpegEncGetEncodedData(jpeg_encoder_hdl, output_buf_ptr, output_buf_size);
            }
            else
            {
                *output_buf_size = 0;
                *output_buf_ptr = NULL;
                break;
            }
        }while(0);
        decode_ms = drv_get_duration_ms(start_time);

        /* return value */
        if ((*output_buf_ptr != NULL) && (*output_buf_size != 0))
        {
            ret = GDI_SUCCEED;
            break;
        }
        else
        {
            switch(jpeg_status)
            {
                case JPEG_STATUS_ENC_ERROR_INSUFFICIENT_MEMORY:
                    ret = GDI_IMAGE_ENCODER_ERR_MEMORY_NOT_ENOUGH;
                    break;

                case JPEG_STATUS_ENC_ERROR_INVALID_WIDTH:
                case JPEG_STATUS_ENC_ERROR_INVALID_HEIGHT:
                    ret = GDI_IMAGE_ERR_INVALID_IMAGE_SIZE;
                    break;
                    
                default:
                    /* encode failed */
                    ret = GDI_FAILED;
                    break;
            }
        }
    }while(0);

    if (codec_type == JPEG_CODEC_TYPE_HW)
    {
        GDI_IMGDEC_HW_UNLOCK();   /* prevent imgdec jpeg decoding at the same time */
    }
    
    /* clean up */
    jpegEncReleaseEncoder(jpeg_encoder_hdl);

    if (extmem)
    {
        gdi_free_ext_mem(&extmem);
    }

    if (intmem)
    {
        if (intMem_isExt)
        {
            gdi_free_ext_mem(&intmem);
        }
        else
        {
            med_free_int_mem(&intmem);
        }
    }

    if ((dst_buf_ptr == NULL) && (temp_dst_buf_ptr != NULL) && (*output_buf_size == 0))
    {
        gdi_free_ext_mem((void**)&temp_dst_buf_ptr);
    }

    if (ret < 0)
    {
        ASSERT(*output_buf_size == 0);
        ASSERT(*output_buf_ptr == NULL);
    }
    GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_MEM_LEAVE,//[gdi_image_encode_buffer_to_jpeg_in_memroy_V2]: Leave - ret:%d decode_ms:%d encode_size:%d
            ret, decode_ms, *output_buf_size);
    return ret;
}
#endif


#if defined(GDI_USING_JPEG_ENCODE)
static GDI_RESULT gdi_image_encode_buffer_to_jpeg_with_exp_size_V1(
                   U8* buf_ptr,
                   S32 width,
                   S32 height,
                   U8 cf,
                   PS8 file_name,
                   S32 expected_encode_size,
                   S32 *encode_file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_encode_struct encode_data;
    S32 ret;
    kal_bool bg_mode = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT((width >= 0) && (height >= 0) && (buf_ptr != NULL));

#if defined(__SW_JPEG_CODEC_SUPPORT__)
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            encode_data.input_type = IMAGE_FORMAT_RGB565;
            break;
            
        case GDI_COLOR_FORMAT_24:
            encode_data.input_type = IMAGE_FORMAT_RGB888;
            break;

        case GDI_COLOR_FORMAT_UYVY422:
            encode_data.input_type = IMAGE_FORMAT_UYVY;
            break;
            
        default:
            GDI_ASSERT(0);
            break;
    }
#else
    /* hw encode */
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            encode_data.input_type = IBR1_TYPE_RGB565;
            break;
            
        case GDI_COLOR_FORMAT_24:
            encode_data.input_type = IBR1_TYPE_RGB888;
            break;
            
        default:
            GDI_ASSERT(0);
            break;
    }
#endif

    encode_data.image_width = width;
    encode_data.image_height = height;

    encode_data.image_quality = CAM_JPG_QTY_HIGH;
    encode_data.image_buffer_p = (void*)buf_ptr;
    encode_data.image_buffer_size = width * height * (gdi_bits_per_pixel(cf) >> 3);

    encode_data.target_width = width;
    encode_data.target_height = height;
    encode_data.media_mode = MED_MODE_FILE;
    encode_data.media_type = MED_TYPE_JPG;

    encode_data.data = (void*)file_name;
    encode_data.file_size_p = encode_file_size;
    encode_data.blocking = (kal_bool) TRUE;         /* blocking */
    encode_data.seq_num = (kal_uint16) 0;           /* not used */
    encode_data.file_buffer_len = (kal_uint32) 0;   /* not used */
    encode_data.gray_mode = 0;
    encode_data.expected_encode_size = (kal_uint32)expected_encode_size;   /* 0: don't caer, >0 will use to judge write to disc or not */

    gdi_image_jpeg_get_background_mode(&bg_mode);
    if (bg_mode)
    {
        encode_data.background_encode = KAL_TRUE;
    }
    else
    {
        encode_data.background_encode = KAL_FALSE;
    }
#ifdef JPEG_ENCODE_THUMBNAIL_MODE
    encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV422;
    
    encode_data.thumbnail_mode = FALSE;
    encode_data.overlay_frame_mode = FALSE;
#endif 

    ret = media_img_encode(stack_int_get_active_module_id(), &encode_data);

    if (ret == MED_RES_OK)
    {
        ret = GDI_SUCCEED;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        ret = GDI_IMAGE_ENCODER_ERR_DISK_FULL;
    }
    else if (ret == MED_RES_WRITE_PROTECTION)
    {
        ret = GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION;
    }
    else if (ret == MED_RES_NO_DISC)
    {
        ret = GDI_IMAGE_ENCODER_ERR_NO_DISK;
    }
    else if (ret == MED_RES_IMGAE_ENCODED_SIZE_LARGER_THAN_EXPECTATION)
    {
        ret = GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION;
    }
    else if (ret == MED_RES_ROOT_DIR_FULL)
    {
        ret = GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL;
    }
    else
    {
        ret = GDI_FAILED;
    }
    return ret;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_buffer_to_jpeg_with_exp_size_V2
 * DESCRIPTION
 *  Encode a buffer to jpeg file.
 *  This API can assign a expected encode size of the output jpeg file.
 * PARAMETERS
 *  buf_ptr                     : [IN] butter to encode
 *  width                       : [IN] butter width
 *  buf_ptr                     : [IN] butter height
 *  cf                          : [IN] butter color format
 *  file_name                   : [IN] output file name
 *  expected_encode_size        : [IN] expected encode size of output jpeg file
 *  encode_file_size            : [OUT] actual encode size
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
static GDI_RESULT gdi_image_encode_buffer_to_jpeg_with_exp_size_V2(
                   U8* buf_ptr,
                   S32 width,
                   S32 height,
                   U8 cf,
                   PS8 file_name,
                   S32 expected_encode_size,
                   S32 *encode_file_size,
                   kal_bool is_force_sw,
                   gdi_jpeg_encode_quality_enum quality)
{
#if defined(GDI_USING_JPEG_ENCODE_V2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;

    JPEG_CODEC_TYPE_ENUM _jpeg_codec_type = JPEG_CODEC_TYPE_HW;
    JPEG_RGB_FORMAT_ENUM _jpeg_encode_type = JPEG_RGB_FORMAT_UNSUPPORTED;
    JPEG_YUV_FORMAT_ENUM _jpeg_encode_UYVU_type = JPEG_YUV_FORMAT_UNSUPPORTED;
    kal_uint32 _jpeg_enc_src_size = 0;

    kal_int32 file_handle; 
    kal_uint8 *_jpeg_enc_output_file_addr;
    kal_uint32 _jpeg_enc_output_file_size = 0;

    void *temp_file_buffer = NULL;
    S32 start_time = 0, decode_ms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_BUFFER_ENTER,//[gdi_image_encode_buffer_to_jpeg_with_exp_size]: Enter - version:%d buf:%x encode_size:%d
        2, buf_ptr, expected_encode_size);
    GDI_ASSERT((width >= 0) && (height >= 0) && (buf_ptr != NULL));
    
    if (encode_file_size != NULL)
    {
        *encode_file_size = 0;
    }

    /* get input layer color format */
    switch(cf)
    {
        case GDI_COLOR_FORMAT_16:
             _jpeg_encode_type = JPEG_RGB_FORMAT_RGB565;
             break;

        case GDI_COLOR_FORMAT_24:
             _jpeg_encode_type = JPEG_RGB_FORMAT_RGB888;
             break;

        case GDI_COLOR_FORMAT_32:
             _jpeg_encode_type = JPEG_RGB_FORMAT_ARGB8888;
             break;

        case GDI_COLOR_FORMAT_UYVY422:
             _jpeg_encode_UYVU_type = JPEG_YUV_FORMAT_PACKED_UYVY422;
             break;

        default:
             GDI_ASSERT(0);
             break;
    }
        
    /* open the file */
    do
    {
        file_handle = FS_Open((kal_wchar*) file_name, FS_CREATE | FS_READ_WRITE);
            
        if (file_handle < 0)
        {
            GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_BUFFER_FS_OPEN_ERROR,//[gdi_image_encode_buffer_to_jpeg_with_exp_size]: FS open error:%d
                 file_handle);
            if (file_handle == FS_WRITE_PROTECTION)
            {
                return GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION;
            }
            else if ((file_handle == FS_DISK_FULL)||(file_handle == FS_PATH_NOT_FOUND))
            {
                return GDI_IMAGE_ENCODER_ERR_DISK_FULL;
            }
            else if (file_handle == FS_DRIVE_NOT_FOUND)
            {
                return GDI_IMAGE_ENCODER_ERR_NO_DISK;
            }
            else if (file_handle == FS_ROOT_DIR_FULL)
            {
                return GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL;
            }
            else
            {
                return GDI_FAILED;
            }
        }
    }while(0);

        /* ENCODE */
    _jpeg_enc_src_size = width * height * (gdi_bits_per_pixel(cf) >> 3);

    if (is_force_sw)
    {
        _jpeg_codec_type = JPEG_CODEC_TYPE_SW;
    }

    while (1)
    {
        ret = gdi_image_encode_buffer_to_jpeg_in_memroy_V2(
                  _jpeg_codec_type,
                  _jpeg_encode_type,
                  _jpeg_encode_UYVU_type,
                  (void *)buf_ptr,
                  _jpeg_enc_src_size,
                  width,
                  height,
                  NULL,
                  0,
                  &temp_file_buffer,
                  &_jpeg_enc_output_file_addr,
                  &_jpeg_enc_output_file_size,
                  quality);

        if ((_jpeg_codec_type == JPEG_CODEC_TYPE_HW) && (ret < 0))
        {
            _jpeg_codec_type = JPEG_CODEC_TYPE_SW;
            continue;
        }
        else
        {
            break;
        }
    }

    if (encode_file_size != NULL)
    {
        *encode_file_size = _jpeg_enc_output_file_size;
    }

    // WRITE TO FILE
    if (_jpeg_enc_output_file_size > 0)
    {
        kal_int32 result;
        kal_uint32 len;

        start_time = drv_get_current_time();
        if ((expected_encode_size > 0) && (_jpeg_enc_output_file_size > expected_encode_size))
        {
            result = GDI_FAILED;
        }
        else
        {
            result = FS_Write(file_handle, (void*)_jpeg_enc_output_file_addr, _jpeg_enc_output_file_size, &len);
        }
        decode_ms = drv_get_duration_ms(start_time);
        FS_Close(file_handle);

        if (temp_file_buffer) // alloc in gdi_image_encode_buffer_to_jpeg_in_memroy_V2
        {
            gdi_free_ext_mem(&temp_file_buffer);
        }

        if (result != FS_NO_ERROR)  // error handle
        {
            GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_BUFFER_FS_WRITE_ERROR,//[gdi_image_encode_buffer_to_jpeg_with_exp_size]: FS write error:%d
                result);
            FS_Delete((kal_wchar*) file_name);

            if (result == FS_DRIVE_NOT_FOUND)
            {   
                ret = GDI_IMAGE_ENCODER_ERR_NO_DISK;
            }
            else if (result == FS_DISK_FULL)
            {
                ret = GDI_IMAGE_ENCODER_ERR_DISK_FULL;
            }
            else if (file_handle == FS_ROOT_DIR_FULL)
            {
                ret = GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL;
            }
            else if (result == GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION)
            {
                ret = GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION;
            }
            else
            {
                ret = GDI_FAILED;
            }
        }
        else if (_jpeg_enc_output_file_size != len)
        {
            FS_Delete((kal_wchar*) file_name);
            ret = GDI_IMAGE_ENCODER_ERR_DISK_FULL;
        }
        else
        {
            ret = GDI_SUCCEED;
        }
    }
    else
    {
        /* Close and delete the file */
        FS_Close(file_handle);
        FS_Delete((kal_wchar*) file_name);
    }

    GDI_TRACE(GDI_TRC_ENCODE, GDI_ENCODE_BUFFER_LEAVE,//[gdi_image_encode_buffer_to_jpeg_with_exp_size]: Leave - ret:%d decode_ms:%d encode_size:%d
        ret, decode_ms, _jpeg_enc_output_file_size);
    return ret;
    
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_buffer_to_jpeg_with_exp_size
 * DESCRIPTION
 *  encode a buffer to jpeg file.
 *  This API can assign a expected encode size of the output jpeg file.
 * PARAMETERS
 *  buf_ptr                     : [IN] butter to encode
 *  width                       : [IN] butter width
 *  buf_ptr                     : [IN] butter height
 *  cf                          : [IN] butter color format
 *  file_name                   : [IN] output file name
 *  expected_encode_size        : [IN] expected encode size of output jpeg file
 *  encode_file_size            : [OUT] actual encode size
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_encode_buffer_to_jpeg_with_exp_size(
            U8* buf_ptr,
            S32 width,
            S32 height,
            U8 cf,
            PS8 file_name,
            S32 expected_encode_size,
            S32 *encode_file_size,
            kal_bool is_force_sw)
{
#if defined(GDI_USING_JPEG_ENCODE_V2)
    {
        gdi_result ret = GDI_FAILED;
        ret = gdi_image_encode_buffer_to_jpeg_with_exp_size_V2(
                  buf_ptr,
                  width,
                  height,
                  cf,
                  file_name,
                  expected_encode_size,
                  encode_file_size,
                  is_force_sw,
                  GDI_JPEG_ENCODE_QUALITY_EXCELLENT);
        return ret;
    }
#elif defined(GDI_USING_JPEG_ENCODE)
    {
        gdi_result ret = GDI_FAILED;
        ret = gdi_image_encode_buffer_to_jpeg_with_exp_size_V1(
                  buf_ptr,
                  width,
                  height,
                  cf,
                  file_name,
                  expected_encode_size,
                  encode_file_size);
        return ret;
    }
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_layer_to_jpeg_with_exp_size
 * DESCRIPTION
 *  encode a layer to jpeg file.
 *  This API can assign a expected encode size of the output jpeg file.
 * PARAMETERS
 *  layer_handle               : [IN]     layer to encode
 *  file_name                  : [IN]     output file name
 *  expected_encode_size       : [IN]     expected encode size of output jpeg file
 *  encode_file_size           : [OUT]    actual encode size
 * RETURNS
 *  GDI_RESULT, return GDI_SUCCEED if succeed
 *****************************************************************************/
GDI_RESULT gdi_image_encode_layer_to_jpeg_with_exp_size(
                gdi_handle layer_handle,
                PS8 file_name,
                S32 expected_encode_size,
                S32 *encode_file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_result ret = GDI_FAILED;
    S32 image_width;
    S32 image_height;
    PU8 image_ptr;
    U8  vcf;
    kal_bool is_force_sw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg_with_exp_size)
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&image_width, &image_height);
    if ((image_width <= 0) || (image_width <= 0))
    {
        gdi_layer_pop_and_restore_active();
        GDI_RETURN(GDI_FAILED);
    }
    gdi_layer_get_buffer_ptr(&image_ptr);
    vcf = ((gdi_layer_struct*)layer_handle)->vcf;
    gdi_layer_pop_and_restore_active();

    gdi_image_jpeg_get_force_use_swjpeg(&is_force_sw);
    ret = gdi_image_encode_buffer_to_jpeg_with_exp_size(
              image_ptr,
              image_width,
              image_height,
              vcf,
              file_name,
              expected_encode_size,
              encode_file_size,
              is_force_sw);
     GDI_EXIT_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg_with_exp_size)
     return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_buffer_to_jpeg_in_memory
 * DESCRIPTION
 *  encode a buffer to jpeg format, output data to a memory buffer.
 * PARAMETERS
 *  buf_ptr             : [IN] butter to encode
 *  width               : [IN] butter width
 *  buf_ptr             : [IN] butter height
 *  cf                  : [IN] butter color format
 *  output_mem          : [IN]    output memory buffer pointer
 *  output_mem_size     : [IN]    output memory buffer size
 *  encode_data_size    : [OUT]   result jpeg data size
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_encode_buffer_to_jpeg_in_memory(
                U8* buf_ptr,
                S32 width,
                S32 height,
                U8 cf,
                U8  *output_mem,
                S32 output_mem_size,
                S32 *encode_data_size,
                gdi_jpeg_encode_quality_enum quality)
{
#if defined(GDI_USING_JPEG_ENCODE_V2)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        GDI_RESULT ret = GDI_SUCCEED;

        JPEG_CODEC_TYPE_ENUM _jpeg_codec_type = JPEG_CODEC_TYPE_HW;
        JPEG_RGB_FORMAT_ENUM _jpeg_encode_type = JPEG_RGB_FORMAT_UNSUPPORTED;
        JPEG_YUV_FORMAT_ENUM _jpeg_encode_UYVU_type = JPEG_YUV_FORMAT_UNSUPPORTED;
        kal_uint32 _jpeg_enc_src_size = 0;

        kal_uint8 *_jpeg_enc_output_file_addr = NULL;
        kal_uint32 _jpeg_enc_output_file_size = 0;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        GDI_ASSERT((width >= 0) && (height >= 0) && (buf_ptr != NULL));

        /* get input layer color format */
        switch(cf)
        {
            case GDI_COLOR_FORMAT_16:
                _jpeg_encode_type = JPEG_RGB_FORMAT_RGB565;
                break;
                
            case GDI_COLOR_FORMAT_24:
                _jpeg_encode_type = JPEG_RGB_FORMAT_RGB888;
                break;

            case GDI_COLOR_FORMAT_32:
                _jpeg_encode_type = JPEG_RGB_FORMAT_ARGB8888;
                break;

            case GDI_COLOR_FORMAT_UYVY422:
                _jpeg_encode_UYVU_type = JPEG_YUV_FORMAT_PACKED_UYVY422;
                break;

            default:
                GDI_ASSERT(0);
                break;
        }

        if (encode_data_size != NULL)
        {
            *encode_data_size = 0;
        }
        
        /* get dimension of layer */


        /* ENCODE */        
        _jpeg_enc_src_size = width * height * (gdi_bits_per_pixel(cf) >> 3);

        while (1)
        {
            ret = gdi_image_encode_buffer_to_jpeg_in_memroy_V2(
                    _jpeg_codec_type,
                    _jpeg_encode_type,
                    _jpeg_encode_UYVU_type,
                    (void*)buf_ptr,
                    _jpeg_enc_src_size,
                    width,
                    height,
                    (void*)output_mem,
                    output_mem_size,
                    NULL,
                    &_jpeg_enc_output_file_addr,
                    &_jpeg_enc_output_file_size,
                    quality);
            if ((_jpeg_codec_type == JPEG_CODEC_TYPE_HW) && (ret < 0))
            {
                _jpeg_codec_type = JPEG_CODEC_TYPE_SW;
                continue;
            }
            else
            {
                break;
            }
        }

        if (encode_data_size != NULL)
        {
            *encode_data_size = _jpeg_enc_output_file_size;
        }
        
        return ret;
    }
    
#elif defined(GDI_USING_JPEG_ENCODE)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    img_encode_struct encode_data;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (encode_data_size != NULL)
    {
        *encode_data_size = 0;
    }
    GDI_ASSERT((width >= 0) && (height >= 0) && (buf_ptr != NULL));

#if defined(__SW_JPEG_CODEC_SUPPORT__)
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            encode_data.input_type = IMAGE_FORMAT_RGB565;
            break;
            
        case GDI_COLOR_FORMAT_24:
            encode_data.input_type = IMAGE_FORMAT_RGB888;
            break;
            
        default:
            GDI_ASSERT(0);
            break;
    }
#else
    /* hw encode */
    switch (cf)
    {
        case GDI_COLOR_FORMAT_16:
            encode_data.input_type = IBR1_TYPE_RGB565;
            break;
            
        case GDI_COLOR_FORMAT_24:
            encode_data.input_type = IBR1_TYPE_RGB888;
            break;
            
        default:
            GDI_ASSERT(0);
            break;
    }
#endif

    encode_data.image_width = width;
    encode_data.image_height = height;

    encode_data.image_quality = CAM_JPG_QTY_HIGH;
    encode_data.image_buffer_p = (void*)buf_ptr;
    encode_data.image_buffer_size = (width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;

    encode_data.target_width = width;
    encode_data.target_height = height;
    encode_data.media_mode = MED_MODE_ARRAY;
    encode_data.media_type = MED_TYPE_JPG;

    encode_data.data = (void*) output_mem;
    encode_data.file_size_p = encode_data_size;
    encode_data.blocking = (kal_bool) TRUE;         /* blocking */
    encode_data.seq_num = (kal_uint16) 0;           /* not used */
    encode_data.file_buffer_len = (kal_uint32) output_mem_size;
    encode_data.gray_mode = 0;
    encode_data.expected_encode_size = 0;   /* 0: don't caer, >0 will use to judge write to disc or not */

#ifdef JPEG_ENCODE_THUMBNAIL_MODE
    encode_data.jpeg_yuv_mode = JPEG_FORMAT_YUV422;
    
    encode_data.thumbnail_mode = FALSE;
    encode_data.overlay_frame_mode = FALSE;
#endif 

    ret = media_img_encode(stack_int_get_active_module_id(), &encode_data);

    if (ret == MED_RES_OK)
    {
        ret = GDI_SUCCEED;
    }
    else if (ret == MED_RES_DISC_FULL)
    {
        ret = GDI_IMAGE_ENCODER_ERR_DISK_FULL;
    }
    else if (ret == MED_RES_WRITE_PROTECTION)
    {
        ret = GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION;
    }
    else if (ret == MED_RES_NO_DISC)
    {
        ret = GDI_IMAGE_ENCODER_ERR_NO_DISK;
    }
    else if (ret == MED_RES_IMGAE_ENCODED_SIZE_LARGER_THAN_EXPECTATION)
    {
        ret = GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION;
    }
    else if (ret == MED_RES_ROOT_DIR_FULL)
    {
        ret = GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL;
    }
    else
    {
        ret = GDI_FAILED;
    }
    return ret;
    }
#else
    return GDI_FAILED;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_layer_to_jpeg_in_memory
 * DESCRIPTION
 *  encode a layer to jpeg format, output data to a memory buffer.
 * PARAMETERS
 *  layer_handle        [IN]    the layer you want to encode to jpeg format
 *  output_mem          [IN]    output memory buffer pointer
 *  output_mem_size     [IN]    output memory buffer size
 *  encode_data_size    [OUT]   result jpeg data size
 *  quality        [IN]    the quality you want to encode to jpeg format
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_encode_layer_to_jpeg_in_memory_ext(
                gdi_handle layer_handle, 
                U8  *output_mem,
                S32 output_mem_size,
                S32 *encode_data_size,
                gdi_jpeg_encode_quality_enum quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_SUCCEED;
    S32 image_width;
    S32 image_height;
    PU8 image_ptr;
    U8  vcf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg_in_memory_ext)
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&image_width, &image_height);
    if ((image_width <= 0) || (image_width <= 0))
    {
        gdi_layer_pop_and_restore_active();
        GDI_RETURN(GDI_FAILED);
    }
    gdi_layer_get_buffer_ptr(&image_ptr);
    vcf = ((gdi_layer_struct*)layer_handle)->vcf;
    gdi_layer_pop_and_restore_active();
    gdi_image_encode_buffer_to_jpeg_in_memory(
        image_ptr,
        image_width,
        image_height,
        vcf,
        output_mem,
        output_mem_size,
        encode_data_size,
        quality);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_encode_layer_to_jpeg_in_memory_ext)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_file_to_jpeg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_file_name       [?]         
 *  dest_file_name      [?]         
 *  dest_width          [IN]        
 *  dest_height         [IN]        
 *  buf_ptr             [?]         
 *  buf_size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_encode_file_to_jpeg(
            S8 *src_file_name,
            S8 *dest_file_name,
            S32 dest_width,
            S32 dest_height,
            U8 *buf_ptr,
            S32 buf_size)
{
    return gdi_image_encode_file_to_jpeg_with_exp_size(
                src_file_name,
                dest_file_name,
                dest_width,
                dest_height,
                buf_ptr,
                buf_size,
                0,      /* expected_encode_size */
                NULL);  /* return encode file size */
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_encode_file_to_jpeg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_file_name       [?]         
 *  dest_file_name      [?]         
 *  dest_width          [IN]        
 *  dest_height         [IN]        
 *  buf_ptr             [?]         
 *  buf_size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_encode_file_to_jpeg_with_exp_size(
            S8 *src_file_name,
            S8 *dest_file_name,
            S32 dest_width,
            S32 dest_height,
            U8 *buf_ptr,
            S32 buf_size,
            S32 expected_encode_size,
            S32 *encode_file_size)
{
#if defined(GDI_USING_JPEG_ENCODE) || defined(GDI_USING_JPEG_ENCODE_V2)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT result = GDI_FAILED;
    gdi_handle dest_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_encode_file_to_jpeg)
    ASSERT(buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(0, 0, dest_width, dest_height, &dest_layer, (PU8) buf_ptr, (S32) buf_size);
    gdi_layer_push_and_set_active(dest_layer);
    gdi_push_and_set_alpha_blending_source_layer(dest_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_image_clear_work_buffer();
    do
    {
        result = gdi_image_draw_resized_file(0, 0, dest_width, dest_height, src_file_name);
        if (GDI_SUCCEED != result) break;

        result = gdi_image_encode_layer_to_jpeg_with_exp_size(
                        dest_layer, 
                        dest_file_name,
                        expected_encode_size,
                        encode_file_size);
    } while(0);
    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_free(dest_layer);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_encode_file_to_jpeg)
    return result;
#else
    return GDI_FAILED;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_mem_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_parse_mem_internal(U8 *res_src, U8 **data_ptr, U8 *img_type, S32 *img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U8* src;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	PU8 imgBuffer = NULL;
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(res_src))
		imgBuffer = res_src;
	else
		imgBuffer = (PU8)GetImageData(res_src);
#else
	imgBuffer = res_src;
#endif



	*img_type = imgBuffer[0];

    switch (*img_type)
    {
        case GDI_IMAGE_TYPE_AVATAR:
		*data_ptr = imgBuffer;
            *img_size = 
			(S32) (imgBuffer[4]) 
			| (S32) ((S32) imgBuffer[5] << 8) 
			| (S32) ((S32) imgBuffer[6] << 16) 
			| (S32) ((S32) imgBuffer[7] << 24);
            break;
        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_M3D:
        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_JPG_SEQUENCE:
        case GDI_IMAGE_TYPE_PNG_SEQUENCE:
        case GDI_IMAGE_TYPE_BMP_SEQUENCE:
		*data_ptr = imgBuffer + 8;
            break;
	    case GDI_IMAGE_TYPE_BMP_FILE_OFFSET:
	    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
        case GDI_IMAGE_TYPE_JPG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_PNG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_DEVICE_BMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_WBMP_FILE_OFFSET:
        case GDI_IMAGE_TYPE_M3D_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SVG_FILE_OFFSET:
        case GDI_IMAGE_TYPE_SWFLASH_FILE_OFFSET:
		*img_size = (((S32)imgBuffer[2])<<16)  |  (((S32)imgBuffer[3])<<8)  |  (((S32)imgBuffer[4]));
		*data_ptr = imgBuffer;
		    break;
        default:
		*data_ptr = imgBuffer + 6;
            break;
    }


#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	SetImageFlushable(res_src);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_parse_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  data_ptr        [IN]        
 *  img_type        [?]         
 *  img_size        [?]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_parse_info(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 **data_ptr,
            U8 *img_type,
            S32 *img_size,
            S32 *frame_number,
            S32 *width,
            S32 *height)
{
	PU8 imgBuffer = NULL;
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(img_src))
		imgBuffer = img_src;
	else
	imgBuffer = (PU8)GetImageData(img_src); 
#else
	imgBuffer = img_src;
#endif

    *width = *height = *frame_number = -1;

    if (imgBuffer == NULL)
        return (GDI_IMAGE_ERR_NULL_IMG_PTR);

    /* Detect image type if unknown */
    *data_ptr = img_src;    /* default data is from begin of img_src */
    switch (src_type)
    {
        case GDI_IMAGE_SRC_FROM_RESOURCE:
            gdi_image_parse_resource_internal(imgBuffer, data_ptr, img_type, img_size,frame_number,width,height);
            break;
        case GDI_IMAGE_SRC_FROM_RESOURCE_WITHOUT_HEADER:
        case GDI_IMAGE_SRC_FROM_MEMORY:
            if (*img_type == GDI_IMAGE_TYPE_INVALID)
            {
                return (GDI_IMAGE_ERR_INVALID_IMG_TYPE);
            }
            else if (*img_type == GDI_IMAGE_TYPE_AVATAR)
            {
                gdi_image_parse_mem_internal(imgBuffer, data_ptr, img_type,img_size);
            } 
            break;
        case GDI_IMAGE_SRC_FROM_FILE:
            if (*img_type == GDI_IMAGE_TYPE_INVALID)
            {
                *img_type = (U8)gdi_image_get_type_from_file_internal((S8*) imgBuffer);
            }
            break;
        default:
            GDI_ASSERT(0);  /* unknown src type */
    }


#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
/* SInce we just need to provide information which has already been obtianed 
By locality of referenc e, i suspect this image needs to come back to cache soon*/
	SetImageFlushable(img_src);
#endif

    return (GDI_SUCCEED);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  width           [?]         
 *  height          [?]         
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_get_dimension(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 *width,
            S32 *height,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data_ptr;
    GDI_RESULT ret;
    S32 tmp;
    const gdi_image_codecs_struct *codec;
    PU8  imgBuffer = NULL;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

	/*img_src  is infact the image handle , which may or may not be in the image cache 
	The code below will get it into the cache */
	if(CheckIsImageBufferPtr(img_src))
		imgBuffer = img_src;
	else
	imgBuffer = (PU8)GetImageData(img_src);
#else

	imgBuffer = img_src;
#endif

    ret = gdi_image_parse_info(src_type, imgBuffer, &data_ptr, &img_type, &img_size, &tmp, width, height);
    
    if (ret != GDI_SUCCEED) return ret;
    
    if(*width ==-1 && *height ==-1)
    {
	    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
	        return GDI_IMAGE_ERR_INVALID_IMG_TYPE;
	
	    codec = &gdi_image_codecs[img_type];
	
	    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
	        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
        else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
	
	    ret = GDI_IMAGE_ERR_NO_DECODER_SUPPORT;
	    *width = *height = 0;
            if (codec->get_dimension)
    	        ret = codec->get_dimension(flag, data_ptr, img_size, width, height);
	}    
	

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
			  SetImageFlushable(img_src);;
#endif
	
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_frame_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  frame_count     [?]         
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_get_frame_count(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 *frame_count,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data_ptr;
    S32 tmp1,tmp2;
    GDI_RESULT ret;
    const gdi_image_codecs_struct *codec;
    gdi_anim_pos_type_enum pos_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_get_frame_count)

    ret = gdi_image_parse_info(src_type, img_src, &data_ptr, &img_type, &img_size,frame_count,&tmp1,&tmp2);
    if (ret != GDI_SUCCEED) GDI_RETURN(ret);

    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);

	if(*frame_count==-1)
	{
	    codec = &gdi_image_codecs[img_type];
	
	    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
	        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
        else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
	    gdi_image_codec_set_flag_begin(flag);
	    ret = GDI_SUCCEED;  /* normal is single frame if no decoder */
	    if (codec->get_pos_info)
	        ret = codec->get_pos_info(flag, data_ptr, img_size, FALSE, frame_count, &pos_type);
	    else
	        *frame_count = 1;
        gdi_image_codec_set_flag_end();
	}
    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_get_frame_count)
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_create_temp_layer
 * DESCRIPTION
 *  The layer created by this function must freed by gdi_image_free_temp_layer.
 *  alloc a buffer from med buffer, and then use the buffer to create layer
 * PARAMETERS
 *  temp_layer_handle  [OUT]  the created layer
 *  cf                 [IN]   color format of created layer
 *  x                  [IN]   x position of created layer
 *  y                  [IN]   y position of created layer
 *  width              [IN]   width of created layer
 *  height             [IN]   height of created layer
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_create_temp_layer(
            gdi_handle *temp_layer_handle,
            gdi_color_format cf,
            S32 x,
            S32 y,
            S32 width,
            S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bytes_per_pixel;
    U32 buf_size;
    U8 *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ASSERT(temp_layer_handle != NULL);
    GDI_ASSERT(width > 0 && height > 0);

    *temp_layer_handle = NULL;

    bytes_per_pixel = gdi_bits_per_pixel(cf) >> 3;
    buf_size = width * height * bytes_per_pixel;
    
    buf = (U8 *)gdi_alloc_ext_mem_framebuffer(buf_size);
    if (buf == NULL)
    {
        /* not enough memory */
        return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
    }
        
    gdi_layer_create_cf_using_outside_memory(
        cf, 
        x, 
        y,
        width, 
        height, 
        temp_layer_handle,
        buf, 
        buf_size);
    if (*temp_layer_handle == GDI_NULL_HANDLE)
    {
        gdi_free_ext_mem((void**)&buf);
        return GDI_FAILED;
    }

    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_free_temp_layer
 * DESCRIPTION
 *  free the layer that created by gdi_image_create_temp_layer.
 * PARAMETERS
 *  temp_layer_handle  [IN]  the layer to be freed
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_free_temp_layer(gdi_handle temp_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp_layer_handle == GDI_NULL_HANDLE)
    {
        /* Do nothing */
        return;
    }

    buf = ((gdi_layer_struct *)temp_layer_handle)->buf_ptr;
    
    gdi_layer_free(temp_layer_handle);

    if (buf != NULL)
    {
        gdi_free_ext_mem((void**)&buf);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_draw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  w               [IN]        
 *  h               [IN]        
 *  flag            [IN]        
 *  frame_pos       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_draw(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U32 flag,
            U32 frame_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data_ptr;
    GDI_RESULT before_ret,ret,ret1;
    const gdi_image_codecs_struct *codec;
    U32 start_time;
    U32 decode_ms = 0;
    U32 delay_time = 0;
	S32 tmp;
	PU8 imgBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_codec_draw)

    GDI_TRACE(GDI_TRC, GDI_TRC_1,//"******* gdi_image_codec_draw PRE type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d"
        src_type,img_src,img_size,x,y,w,h,flag,frame_pos);

    if ((x > gdi_act_layer->clipx2) || (y > gdi_act_layer->clipy2))
    {
        GDI_RETURN(GDI_SUCCEED);
    }


#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	if(CheckIsImageBufferPtr(img_src))
		imgBuffer = img_src;
	else
	  imgBuffer = (PU8)GetImageData(img_src);
#else
	imgBuffer = img_src;
#endif

	ret = gdi_image_parse_info(src_type, imgBuffer, &data_ptr, &img_type, &img_size,&tmp,&tmp,&tmp);
    if (ret != GDI_SUCCEED)
    {
        GDI_RETURN(ret);
    }

    #if defined(GDI_USE_RGB565_TO_SHOW_BW)
	if (img_type == GDI_IMAGE_TYPE_GIF)
	{
		GDI_RETURN(GDI_SUCCEED);
	}
    #endif
    
    if (GDI_IMAGE_TYPE_DEV_BMP == img_type)
    {
        img_type = GDI_IMAGE_TYPE_DEVICE_BITMAP;
    }
    
    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
    {
        GDI_RETURN(GDI_IMAGE_ERR_INVALID_IMG_TYPE);
    }
    GDI_TRACE(GDI_TRC, GDI_TRC_2,//"gdi_image_codec_draw image type=%d src=%d size=%d x=%d y=%d w=%d h=%d flag=%x frame_pos=%d"
            img_type,img_src,img_size,x,y,w,h,flag,frame_pos);

    codec = &gdi_image_codecs[img_type];

    if (src_type == GDI_IMAGE_SRC_FROM_FILE)
    {
        flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
    }
    else if((src_type == GDI_IMAGE_SRC_FROM_MEMORY) || (img_type == GDI_IMAGE_TYPE_BMP_MEM))
    {
        /* img_type == GDI_IMAGE_TYPE_BMP_MEM means the bmp is from DLT */
        /* when bmp is from DLT, we set the GDI_IMAGE_CODEC_FLAG_IS_MEM to prevent the bmp use transparent color */
        flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
    }

    ret = before_ret = GDI_SUCCEED;

    start_time = drv_get_current_time();
    gdi_image_codec_set_flag_begin(flag);
    gdi_image_set_timeout(GDI_IMAGE_CODEC_TIMEOUT);
    
    gdi_image_set_update_area(x,y,x+w,y+h);

    if (codec->draw_before)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_BEFORE) == 0)
        {
            ret = before_ret = codec->draw_before(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }
    if (ret >= GDI_SUCCEED)
    if (codec->draw)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW) == 0)
        {
            ret = codec->draw(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }

    if (codec->draw_after)
        if ((flag & GDI_IMAGE_CODEC_FLAG_DISABLE_DRAW_AFTER) == 0)
		if(before_ret == GDI_SUCCEED) // call draw_after only if draw_before success.
        {
            ret1 = codec->draw_after(flag, frame_pos, x, y, w, h, data_ptr, img_size);
            if (ret >= GDI_SUCCEED && ret1 <GDI_SUCCEED)
                ret =ret1;
            if(ret < GDI_SUCCEED && gdi_image_is_abort()) 
                ret = GDI_ERR_NB_ABORT;
        }

    gdi_image_clear_timeout();
    gdi_image_codec_set_flag_end();
    gdi_image_set_progress_callback(NULL,NULL);
    gdi_nb_set_high_priority(FALSE);
    
    decode_ms = drv_get_duration_ms(start_time);

    delay_time = gdi_anim_get_delay();
    if (delay_time < decode_ms)
    {
        gdi_anim_set_delay(20);
    }
    else
    {
        gdi_anim_set_delay(delay_time - decode_ms);
    }
    GDI_TRACE(GDI_TRC, GDI_TRC_3,//"------- decode time=%d delay time=%d ret=%d", 
                decode_ms, delay_time,ret);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_codec_draw)

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
							SetImageFlushable(img_src);
#endif
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_clear_work_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_clear_work_buffer(void)
{
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_estimate_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/

U32 gdi_image_estimate_decoding_time(U8 img_type,S32 width,S32 height)
{
    U32 ms=0;
    switch(img_type)
    {
    case GDI_IMAGE_TYPE_DEVICE_BITMAP:
    default:
        ms = 300;
        break;
    }
    ms *= width*height;
    ms /=176*220;

    #if defined(MCU_13M)
        ms = ms *52/13;
    #elif defined(MCU_26M)
        ms = ms *52/26;
    #elif defined(MCU_39M)
        ms = ms *52/39;
    #elif defined(MCU_52M)
        ms = ms;
    #elif defined(MCU_78M)
        ms = ms *52/78;
    #else
        ms = ms *52/122; //It should be fast enough, should not detect higher CPU .. #error "Unknown MCU clock"
    #endif
    return ms;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_estimate_show_fullscreen_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/

U32 gdi_image_estimate_show_fullscreen_time(void)
{
    return gdi_image_estimate_decoding_time(GDI_IMAGE_TYPE_DEVICE_BITMAP,GDI_LCD_WIDTH,GDI_LCD_HEIGHT);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_set_callback
 * DESCRIPTION
 *  settint the callback for non-blocking job
 *****************************************************************************/
void gdi_nb_set_blt(BOOL is_blt,BOOL is_progress)
{
    if(!is_blt)
        gdc_job_set_parameter(GDC_JOB_IS_NO_BLT,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
    else if(is_progress)
        gdc_job_set_parameter(GDC_JOB_IS_PROGRESS_BLT,-1,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

void gdi_nb_set_anim_before_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,callback,NULL,NULL,NULL,NULL,NULL,NULL);
}
void gdi_nb_set_anim_after_frame_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,NULL,callback,NULL,NULL,NULL,NULL,NULL);
}
void gdi_nb_set_anim_last_frame_callback(void (*callback)(GDI_RESULT result))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,callback,NULL,NULL,NULL,NULL);
}
void gdi_nb_set_anim_before_each_frame_callback(void (*callback)(GDI_RESULT result))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,NULL,callback,NULL,NULL,NULL);
}
void gdi_nb_set_anim_after_each_frame_callback(void (*callback)(GDI_RESULT result))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,NULL,NULL,callback,NULL,NULL);
}
void gdi_nb_set_done_callback(void (*callback)(GDI_RESULT result,gdi_handle handle))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,NULL,NULL,NULL,callback,NULL);
}
void gdi_nb_set_anim_count(S32 anim_count)
{
    gdc_job_set_parameter(0,anim_count,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}
void gdi_nb_set_anim_handle_query_callback(void (*callback)(gdi_handle anim_handle,gdi_handle job_handle))
{
    gdc_job_set_parameter(0,-1,NULL,NULL,NULL,NULL,NULL,NULL,callback);
}

void gdi_nb_set_high_priority(BOOL is_nb_first)
{
    gdi_nb_is_high_priority_flag = is_nb_first;
}
BOOL gdi_nb_is_high_priority(void)
{
    return gdi_nb_is_high_priority_flag;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_nb_is_non_blocking_decoding
 * DESCRIPTION
 *  return true if the GDC job queue is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL gdi_nb_is_non_blocking_decoding(void)
{
    U32 job_sum = 0;

    gdc_job_get_job_sum(&job_sum);

    if (job_sum == 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


gdi_handle gdi_image_nb_draw_internal(
                            gdi_image_src_enum src_type,
                            U8 *img_src,
                            U8 img_type,
                            S32 img_size,
                            S32 x,
                            S32 y,
                            S32 w,
                            S32 h,
                            U32 img_flag,
                            U32 frame_pos,
                            gdc_job_flag_enum job_flag)
{
    gdi_handle job_handle;
    gdc_job_add_image(
                            src_type,
                            img_src,
                            img_type,
                            img_size,
                            x,
                            y,
                            w,
                            h,
                            img_flag,
                            frame_pos,
                            job_flag,
                            &job_handle);
    return job_handle;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_stop
 * DESCRIPTION
 *  non-blocking draw resource image 
 *****************************************************************************/
GDI_RESULT gdi_image_nb_stop(gdi_handle handle)
{
    return gdc_job_del_one(handle);
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_nb_stop_all
 * DESCRIPTION
 *  non-blocking draw resource image 
 *****************************************************************************/
GDI_RESULT gdi_image_nb_stop_all(void)
{
    return gdc_job_del_all_decoding();

}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_set_flag_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_codec_set_flag_begin(U32 flag)
{
    GDI_ASSERT(gdi_image_codec_flag_index < (sizeof(gdi_image_codec_flag_stack) / sizeof(U32) - 1));
    GDI_LOCK;
    gdi_image_codec_flag_index++;
    gdi_image_codec_flag_stack[gdi_image_codec_flag_index] = gdi_image_codec_flag_stack[gdi_image_codec_flag_index - 1] | flag;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_set_flag_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_codec_set_flag_end(void)
{
    GDI_ASSERT(gdi_image_codec_flag_index > 0);
    gdi_image_codec_flag_index--;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_get_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
U32 gdi_image_codec_get_flag(void)
{
    return gdi_image_codec_flag_stack[gdi_image_codec_flag_index];
}
/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_set_flag
 * DESCRIPTION
 *  modify current flag setting
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void gdi_image_codec_set_flag(U32 flag)
{
    gdi_image_codec_flag_stack[gdi_image_codec_flag_index] = flag;
}

void gdi_image_cache_reset(void)
{
    gdi_image_gif_reset();
    gdi_lfs_initialize();
}
void gdi_image_cache_reset_entry(U8* src,U32 size)
{
    gdi_image_gif_reset_entry(src,size);
    gdi_image_gif_reset_entry(src+8,size);     // from resource need skip 8 bytes header 
}

/*****************************************************************************
 * FUNCTION
 *  gdi_image_check_image_file_valid
 * DESCRIPTION
 *  check a image file is valid or not
 * PARAMETERS
 *  filepath    [IN]    image file path
 * RETURNS
 *  MMI_BOOL, return MMI_TRUE if the image is valid
 *****************************************************************************/
MMI_BOOL gdi_image_check_image_file_valid(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define temp_layer_w 12
    #define temp_layer_buf_sz ((temp_layer_w*temp_layer_w*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
    
    GDI_RESULT ret = GDI_FAILED;
    U8 *buffer = NULL;
    gdi_handle temp_layer;
    S32 width = 0, height = 0;
    U32 rw = temp_layer_w, rh = temp_layer_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image resolution */
    {
        ret = gdi_image_get_dimension_file(filepath, &width, &height);
        if (ret != GDI_SUCCEED || width <= 0 || height <= 0)
        {
            return MMI_FALSE;
        }
    }

    /* Check if the image can be draw successfully */
    buffer =(U8*)gdi_alloc_ext_mem_framebuffer(temp_layer_buf_sz);
    if (buffer == NULL)
    {
        return MMI_FALSE;
    }

    gdi_layer_create_using_outside_memory(
        0,
        0,
        temp_layer_w,
        temp_layer_w,
        &temp_layer,
        buffer,
        (S32)temp_layer_buf_sz);

    if (width < temp_layer_w)
    {
        rw = width;
    }
    if (height < temp_layer_w)
    {
        rh = height;
    }
    gdi_layer_push_and_set_active(temp_layer);
    ret = gdi_image_draw_resized_file(0, 0, rw, rh, filepath);
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(temp_layer);

    if (buffer)
    {
        gdi_free_ext_mem((void**)&buffer);
    }

    if (ret == GDI_SUCCEED)
    {
        if (GDI_IMAGE_TYPE_GIF_FILE == gdi_image_get_type_from_file(filepath))
        {
            gdi_image_cache_reset();
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_load
 * DESCRIPTION
 *  load image data to single bank cache
 * PARAMETERS
 *  img_src         [IN]
 *  img_size        [IN]
 *  reloaded        [OUT]       whether data is reloaded (if FALSE, data was already in cache)
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_single_bank_cache_load(const U8 *img_src, S32 img_size, BOOL *reloaded)
{
	PU8 imgBuffer = NULL ;
    if (!img_src)
    {
        return GDI_FAILED;
    }

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	if(CheckIsImageBufferPtr(image_ptr))
			imgBuffer = image_ptr;
		else
			imgBuffer = (PU8)GetImageData(image_ptr);

#else
	imgBuffer = img_src;
#endif

    if (imgBuffer == gdi_image_single_bank_cache_src && 
        img_size == gdi_image_single_bank_cache_size)
    {
        if (reloaded)
        {
            *reloaded = FALSE;
        }
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
		/* SInce we just need to provide information which has already been obtianed 
		By locality of referenc e, i suspect this image needs to come back to cache soon*/
		SetImageFlushable(img_src);
#endif
        return GDI_SUCCEED;
    }
    else
    {
        if (img_size > GDI_IMAGE_SINGLE_BANK_CACHE_SIZE)
        {
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
			SetImageFlushable(img_src);
#endif

            return GDI_FAILED;
        }
        else
        {
            memcpy(gdi_image_single_bank_cache_buf, imgBuffer, img_size);
            gdi_image_single_bank_cache_src = imgBuffer;
            gdi_image_single_bank_cache_size = img_size;
            if (reloaded)
            {            
                *reloaded = TRUE;
            }
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
			SetImageFlushable(img_src);
#endif
            return GDI_SUCCEED;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_get_buffer
 * DESCRIPTION
 *  Get the buffer pointer of single-bank cache
 * PARAMETERS
 *  void
 * RETURNS
 *  buffer pointer
 *****************************************************************************/
U8 *gdi_image_single_bank_cache_get_buffer(void)
{
    return (U8*) gdi_image_single_bank_cache_buf;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_reset
 * DESCRIPTION
 *  Reset single bank cache for image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_single_bank_cache_reset(void)
{
    gdi_image_single_bank_cache_src = NULL;
    gdi_image_single_bank_cache_size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_single_bank_cache_reset_entry
 * DESCRIPTION
 *  Reset single bank cache for certain image
 * PARAMETERS
 *  img_src         [IN]
 *  img_size        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_single_bank_cache_reset_entry(const U8 *img_src, S32 img_size)
{
    (void) img_size; /* avoid warning */
    if (img_src == gdi_image_single_bank_cache_src) /* loose check without size checking */
    {
        gdi_image_single_bank_cache_reset();
    }
}


#endif /* GDI_USING_IMAGE_SINGLE_BANK_CACHE */


/*****************************************************************************
 * FUNCTION
 *  gdi_image_codec_is_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_type        [IN]        
 *  img_src         [?]         
 *  img_type        [IN]        
 *  img_size        [IN]        
 *  is_anim         [OUT]         
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT gdi_image_codec_is_animation(
            gdi_image_src_enum src_type,
            U8 *img_src,
            U8 img_type,
            S32 img_size,
            MMI_BOOL *is_anim,
            U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *data_ptr;
    S32 tmp1,tmp2;
    GDI_RESULT ret;
    const gdi_image_codecs_struct *codec;
    gdi_anim_pos_type_enum pos_type;
    S32 frame_count;
	PU8 imgBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	if(CheckIsImageBufferPtr(img_src))
		imgBuffer = img_src;
	else
		imgBuffer = (PU8)GetImageData(img_src);	
#else
	imgBuffer = img_src;
#endif

    *is_anim = MMI_FALSE;
    ret = gdi_image_parse_info(src_type, imgBuffer, &data_ptr, &img_type, &img_size, &frame_count,&tmp1,&tmp2);
    if (ret != GDI_SUCCEED) return (ret);

    if (GDI_IMAGE_TYPE_INVALID == img_type || img_type >= GDI_IMAGE_TYPE_SUM)
        return (GDI_IMAGE_ERR_INVALID_IMG_TYPE);

    codec = &gdi_image_codecs[img_type];
    ret = GDI_SUCCEED;  /* normal is single frame if no decoder */
    if (codec->is_animation)
    {        
        if (GDI_IMAGE_TYPE_GIF == img_type)
        {
            ret = gdi_image_gif_check_animation(data_ptr, img_size, is_anim);
        }
        if (GDI_IMAGE_TYPE_GIF_FILE == img_type)
        {
            ret = gdi_image_gif_check_animation_file(data_ptr, is_anim);
        }
        else
        {
            if (src_type == GDI_IMAGE_SRC_FROM_FILE)
            {
	            flag |= GDI_IMAGE_CODEC_FLAG_IS_FILE;
	        }
            else if(src_type == GDI_IMAGE_SRC_FROM_MEMORY)
            {
                flag |= GDI_IMAGE_CODEC_FLAG_IS_MEM;
            }
	        if (codec->get_pos_info)
	        {
	            ret = codec->get_pos_info(flag, data_ptr, img_size, FALSE, &frame_count, &pos_type);
	        }
	        else
	        {
	            frame_count = 1;
	        }
            if (frame_count > 1)
            {
                *is_anim = MMI_TRUE;
            }
        }
	}

#if defined __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
	SetImageFlushable(img_src);
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_animation
 * DESCRIPTION
 *  Check image is animtion or not from resource
 * PARAMETERS
 *  image_ptr       [IN]        
 *  is_anim         [OUT]       
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_is_animation(U8 *image_ptr, MMI_BOOL *is_anim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_is_animation(
            GDI_IMAGE_SRC_FROM_RESOURCE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            is_anim,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_animation_file
 * DESCRIPTION
 *  Check image is animtion or not from file
 * PARAMETERS
 *  image_ptr       [IN]        
 *  is_anim         [OUT]     
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_is_animation_file(U8 *image_ptr, MMI_BOOL *is_anim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_is_animation(
            GDI_IMAGE_SRC_FROM_FILE,
            image_ptr,
            GDI_IMAGE_TYPE_INVALID,
            0,
            is_anim,
            0);
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_animation_mem
 * DESCRIPTION
 *  Check image is animtion or not from memory
 * PARAMETERS
 *  image_type      [IN]    image type, ex. GDI_IMAGE_TYPE_GIF
 *  image_ptr       [IN]    image pointer
 *  image_size      [IN]    image size
 *  frame_count     [OUT]   frame count
 * RETURNS
 *  GDI_RESULT
 *****************************************************************************/
GDI_RESULT gdi_image_is_animation_mem(
            U8  image_type,
            U8  *image_ptr,
            S32 image_size,
            MMI_BOOL *is_anim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_image_codec_is_animation(
            GDI_IMAGE_SRC_FROM_MEMORY,
            image_ptr,
            image_type,
            image_size,
            is_anim,
            0);
}
