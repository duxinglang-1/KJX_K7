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
 *  gdi_w32_lcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Image Hardware Gif related.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 
#ifndef NEPTUNE_MMI

#include <memory.h>
#include "gdi_internal.h"
#include "gd_primitive.h"
#include "gdi_layer.h"
#include "lcm_if.h"
#include "drv_sw_features_display.h"
#include "kal_release.h"
#include "common\display_io.h"
#include "kal_public_api.h"

#if defined(DRV_DISPLAY_DRIVER_V1)

#define LCD_USE_C_MODEL 1

#define LCD_PITCH_BY_PIXEL 1

#if (LCD_USE_C_MODEL == 1)
//#include "lcd_config.h"
//#include "lcd_process_roi.h"
#include "lcd_c_model.h"
#define SIMULATOR_LAYER_COUNT	(6)
static lcd_layer_config_t g_layer_config[SIMULATOR_LAYER_COUNT];
#endif

static U32 gdi_w32_main_lcd_buffer[GDI_LCD_WIDTH * GDI_LCD_HEIGHT];

#ifdef __MMI_SUBLCD__
static U32 gdi_w32_sub_lcd_buffer[GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT];
#endif 

U32 *gdi_w32_lcd_buffer[GDI_LCD_SUM];
lcd_layer_struct gdi_w32_layer_data[GDI_LCD_SUM][GDI_LAYER_HW_LAYER_COUNT];
gdi_layer_struct *gdi_w32_layer[GDI_LCD_SUM][GDI_LAYER_HW_LAYER_COUNT];
gdi_color gdi_w32_palette[2][256];
gdi_layer_struct gdi_w32_output_layer;

int g_lcd_debug = 0;
char g_lcd_debug_path[256];
char g_lcd_debug_file[256];

/* create this table, so we can use for loop to prcess each layer */
static U32 layer_flag_table[] = 
{
    LCD_LAYER0_ENABLE,
    LCD_LAYER1_ENABLE,
    LCD_LAYER2_ENABLE,
    LCD_LAYER3_ENABLE,
    LCD_LAYER4_ENABLE,
    LCD_LAYER5_ENABLE
};

#define BGR(R,G,B)      (((R)<<16)|((G)<<8)|(B))

void dump(void* pBuffer, UINT width, UINT height, UINT bpp, char* file)
{
    FILE* fp = NULL;
    UINT size = width * height * bpp;
    UINT data = 0;
    if (pBuffer == NULL)
        return;
    if (width == 0 || height == 0)
        return;
    if (file == NULL)
    {
        strcpy(g_lcd_debug_file, g_lcd_debug_path);
        strcat(g_lcd_debug_file, "\\temp.ibf");
    }
    else
    {
        strcpy(g_lcd_debug_file, g_lcd_debug_path);
        strcat(g_lcd_debug_file, "\\");
        strcat(g_lcd_debug_file, file);
    }
    fp = fopen(g_lcd_debug_file, "wb");
    if (fp)
    {
        data = 1;
        fwrite(&data, 4, 1, fp);
        fwrite(&size, 4, 1, fp);
        fwrite(&width, 4, 1, fp);
        fwrite(&height, 4, 1, fp);
        if (bpp == 2)
            data = 1;
        else if (bpp == 3)
            data = 2;
        else if (bpp == 4)
            data = 3;
        else
            data = -1;
        fwrite(&data, 4, 1, fp);
        fwrite(pBuffer, size, 1, fp);
        fclose(fp);
    }
}

/*****************************************************************************
 * FUNCTION
 *  lcd_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id                  [IN]        
 *  background_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U8 R, G, B;
    U32 c;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcd_id--;
    switch (lcd_id)
    {
    case 0:
        R = DRV_HW_TO_RGB_R(background_color);
        G = DRV_HW_TO_RGB_G(background_color);
        B = DRV_HW_TO_RGB_B(background_color);
        c = BGR(R, G, B);
        size = GDI_LCD_WIDTH * GDI_LCD_HEIGHT;
        gdi_w32_lcd_buffer[lcd_id] = gdi_w32_main_lcd_buffer;
        break;
#ifdef __MMI_SUBLCD__
    case 1:
        R = HW_FORMAT_TO_SUBMMI_R(background_color);
        G = HW_FORMAT_TO_SUBMMI_G(background_color);
        B = HW_FORMAT_TO_SUBMMI_B(background_color);
        c = BGR(R, G, B);
        size = GDI_SUBLCD_WIDTH * GDI_SUBLCD_HEIGHT;
        gdi_w32_lcd_buffer[lcd_id] = gdi_w32_sub_lcd_buffer;
        break;
#endif /* __MMI_SUBLCD__ */ 
    default:
        GDI_ASSERT(0);
    }

    for (i = 0; i < size; i++)
    {
        gdi_w32_lcd_buffer[lcd_id][i] = c;
    }

}


/*****************************************************************************
 * FUNCTION
 *  config_lcd_layer_window
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_layer       [IN]        
 *  layer_data      [?]         
 * RETURNS
 *  
 *****************************************************************************/
#if (LCD_USE_C_MODEL == 0)
LCD_STATUS_CODE_ENUM config_lcd_layer_window(kal_uint8 lcd_layer, lcd_layer_struct *layer_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int layer_id = (layer_data - gdi_layer_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_w32_layer_data[GDI_LCD->act_handle - 1][lcd_layer] = *layer_data;
    gdi_w32_layer[GDI_LCD->act_handle - 1][lcd_layer] = &GDI_LAYERS[layer_id];
    return LCD_OK;
}
#else
LCD_STATUS_CODE_ENUM config_lcd_layer_window(kal_uint8 lcd_layer, lcd_layer_struct *layer_data)
{
    unsigned int pitch = 0;
    unsigned int bpp = 0;
    int layer_id = (layer_data - gdi_layer_info);
    gdi_w32_layer_data[GDI_LCD->act_handle - 1][lcd_layer] = *layer_data;
    gdi_w32_layer[GDI_LCD->act_handle - 1][lcd_layer] = &GDI_LAYERS[layer_id];
    memset(&g_layer_config[lcd_layer], 0, sizeof(g_layer_config[lcd_layer]));
    g_layer_config[lcd_layer].layer_add = (unsigned char*)(layer_data->frame_buffer_address);
    g_layer_config[lcd_layer].opaen = layer_data->opacity_enable;
    g_layer_config[lcd_layer].opacity = layer_data->opacity_value;
    switch (layer_data->source_color_format)
    {
    case GDI_HW_COLOR_FORMAT_8:
        g_layer_config[lcd_layer].clrdpt = BPP8;
        pitch = layer_data->column_number;
        bpp = 1;
        break;
    case GDI_HW_COLOR_FORMAT_16:
        g_layer_config[lcd_layer].clrdpt = BPP16;
        pitch = layer_data->column_number;
        bpp = 2;
        break;
    case GDI_HW_COLOR_FORMAT_24:
        g_layer_config[lcd_layer].clrdpt = BPP24;
        pitch = layer_data->column_number;
        bpp = 3;
        break;
    case GDI_HW_COLOR_FORMAT_32:
        g_layer_config[lcd_layer].clrdpt = ARGB;
        pitch = layer_data->column_number;
        bpp = 4;
        break;
    case GDI_HW_COLOR_FORMAT_32_PARGB:
        g_layer_config[lcd_layer].clrdpt = PARGB;
        pitch = layer_data->column_number;
        bpp = 4;
        break;
#if defined(GDI_HW_COLOR_FORMAT_UYVY422)
	case GDI_HW_COLOR_FORMAT_UYVY422:
		g_layer_config[lcd_layer].clrdpt = YUYV422;
		pitch = layer_data->column_number;
		bpp = 2;
		break;
#endif
    default:
        ASSERT(0);
        break;
    }
#if (LCD_PITCH_BY_PIXEL == 0)
    pitch *= bpp;
#endif
    g_layer_config[lcd_layer].dither_en = layer_data->dither_enable;
    g_layer_config[lcd_layer].dkey_en = layer_data->dst_key_enable;
    g_layer_config[lcd_layer].mem_ofs.x = layer_data->mem_x_offset;
    g_layer_config[lcd_layer].mem_ofs.y = layer_data->mem_y_offset;
    g_layer_config[lcd_layer].ofs.x = layer_data->x_offset;
    g_layer_config[lcd_layer].ofs.y = layer_data->y_offset;
    g_layer_config[lcd_layer].pitch = pitch;	// Use pitch from layer_data when caller supports pitch
    g_layer_config[lcd_layer].bpp = bpp;
    switch (layer_data->rotate_value)
    {
    case LCD_LAYER_ROTATE_NORMAL:
        g_layer_config[lcd_layer].rotate = 0;	
        break;
    case LCD_LAYER_ROTATE_90:
        g_layer_config[lcd_layer].rotate = 1;	
        break;
    case LCD_LAYER_ROTATE_180:
        g_layer_config[lcd_layer].rotate = 2;	
        break;
    case LCD_LAYER_ROTATE_270:
        g_layer_config[lcd_layer].rotate = 3;	
        break;
    case LCD_LAYER_MIRROR:
        g_layer_config[lcd_layer].rotate = 4;	
        break;
    case LCD_LAYER_MIRROR_ROTATE_90:
        g_layer_config[lcd_layer].rotate = 5;	
        break;
    case LCD_LAYER_MIRROR_ROTATE_180:
        g_layer_config[lcd_layer].rotate = 6;	
        break;
    case LCD_LAYER_MIRROR_ROTATE_270:
        g_layer_config[lcd_layer].rotate = 7;	
        break;
    default:
        ASSERT(0);
        break;
    }
    g_layer_config[lcd_layer].size.x = layer_data->column_number;
    g_layer_config[lcd_layer].size.y = layer_data->row_number;
    g_layer_config[lcd_layer].skey = layer_data->source_key;
    g_layer_config[lcd_layer].skey_en = layer_data->source_key_enable;
    if (0)
        dump(g_layer_config[lcd_layer].layer_add, g_layer_config[lcd_layer].size.x, g_layer_config[lcd_layer].size.y, bpp, NULL);
    return LCD_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  set_lcd_color_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_palette_select        [IN]        
 *  color_palette_addr_ptr      [?]         
 *  start_index                 [IN]        
 *  number_of_color             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_lcd_color_palette(
        kal_uint8 color_palette_select,
        kal_uint32 *color_palette_addr_ptr,
        kal_uint8 start_index,
        kal_uint8 number_of_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    gdi_color *c = (gdi_color*) color_palette_addr_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_color; i++)
    {
        gdi_w32_palette[color_palette_select][start_index + i] = *c;
        c++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  config_lcd_hw_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hw_layer            [IN]        
 *  layer_offset_x      [IN]        
 *  layer_offset_y      [IN]        
 *  layer_width         [IN]        
 *  layer_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void config_lcd_hw_layer(
        kal_uint32 hw_layer,
        kal_uint16 layer_offset_x,
        kal_uint16 layer_offset_y,
        kal_uint16 layer_width,
        kal_uint16 layer_height)
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
 *  lcd_stop_hw_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_stop_hw_update(kal_uint8 lcd_id)
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
 *  lcd_fb_update_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd                 [IN]        
 *  DEST                [?]         
 *  width               [IN]        
 *  height              [IN]        
 *  dest_start_x        [IN]        
 *  dest_start_y        [IN]        
 *  dest_end_x          [IN]        
 *  dest_end_y          [IN]        
 *  dest_roi_x          [IN]        
 *  dest_roi_y          [IN]        
 *  update_layers       [IN]        
 *  is_up_to_down       [IN]        
 *  is_to_layer         [IN]        
 *  background          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_fb_update_internal(
        int lcd,
        U32 *DEST,
        U32 width,
        U32 height,
        /* destination buffer */ int dest_start_x,
        int dest_start_y,
        int dest_end_x,
        int dest_end_y,
        /* destination output window */ int dest_roi_x,
        int dest_roi_y,
        /* universal  coordinate */ U32 update_layers,
        /* which layers want to be update ? */ int is_up_to_down,
        int is_to_layer,
        U32 background)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int dx, dy;     /* destination position */
    int adx, ady;   /* destination position in universal coordinate */
    U32 layer;
    int lx, ly;     /* layer position */
    lcd_layer_struct *layer_info;
    U32 *dest;
    U32 bg_a, bg_r, bg_g, bg_b;
    gdi_layer_struct *curr_layer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
#ifdef DRV_PALETTE_RGB_888
    gd_color_to_rgb_24(&bg_a, &bg_r, &bg_g, &bg_b, background);
#else
    gd_color_to_rgb_16(&bg_a, &bg_r, &bg_g, &bg_b, background);
#endif
#else 
    bg_a = bg_r = bg_g = bg_b = 0x00ff;
#endif 

    if (dest_start_x < 0)
    {
        dest_start_x = 0;
    }
    if (dest_start_y < 0)
    {
        dest_start_y = 0;
    }

    // shift buffer address to ROI. idea from Glory
    {
        if (is_to_layer == TRUE)
        {
            dest_start_x = dest_roi_x;
            dest_start_y = dest_roi_y;

            dest_end_x = dest_start_x + dest_end_x;
            dest_end_y = dest_start_y + dest_end_y;            
        }
    }

    if(is_to_layer == FALSE)
    {	
        if (lcd == 0)
        {

            if (dest_end_x >= GDI_LCD_WIDTH)
            {
                dest_end_x = GDI_LCD_WIDTH - 1;
            }
            if (dest_end_y >= GDI_LCD_HEIGHT)
            {
                dest_end_y = GDI_LCD_HEIGHT - 1;
            }
        }
#ifdef __MMI_SUBLCD__
        else if (lcd == 1)
        {

            if (dest_end_x >= GDI_SUBLCD_WIDTH)
            {
                dest_end_x = GDI_SUBLCD_WIDTH - 1;
            }
            if (dest_end_y >= GDI_SUBLCD_HEIGHT)
            {
                dest_end_y = GDI_SUBLCD_HEIGHT - 1;
            }


        }

#endif /* __MMI_SUBLCD__ */ 
    }

    for (dy = dest_start_y, ady = dest_roi_y; dy <= dest_end_y; dy++, ady++)
    {
        if (is_up_to_down)
        {
            dest = DEST + (dest_start_x + dy * width);
        }
        else
        {
            dest = DEST + (dest_start_x + (height - dy - 1) * width);
        }

        for (dx = dest_start_x, adx = dest_roi_x; dx <= dest_end_x; dx++, adx++, dest++)
        {
            U32 OA, OR, OG, OB;

            /* the initial color is white ! */
            OA = bg_a;
            OR = bg_r;
            OG = bg_g;
            OB = bg_b;
            for (layer = 0; layer < GDI_LAYER_HW_LAYER_COUNT; layer++)
            {
                if (update_layers & layer_flag_table[layer])
                {
                    gdi_color lc;
                    U32 LA, LR, LG, LB;

                    curr_layer = gdi_w32_layer[lcd][layer];
                    layer_info = &gdi_w32_layer_data[lcd][layer];

                    /* transform to layer's local coordinate */
                    lx = adx - layer_info->x_offset;
                    ly = ady - layer_info->y_offset;

                #ifdef GDI_USING_LAYER_ROTATE
                    switch (layer_info->rotate_value)
                    {
                    case LCD_LAYER_ROTATE_270:
                        {
                            int temp;

                            temp = lx;
                            lx = ly;
                            /* ly = GDI_LCD_WIDTH-1-temp; */
                            ly = layer_info->row_number - 1 - temp;
                        }
                        break;
                    case LCD_LAYER_ROTATE_90:
                        {
                            int temp;

                            temp = ly;
                            ly = lx;
                            lx = layer_info->column_number - 1 - temp;
                        }
                        break;
                    case LCD_LAYER_ROTATE_180:
                        {
                            lx = layer_info->column_number - 1 - lx;
                            ly = layer_info->row_number - 1 - ly;
                        }
                        break;
                    }
                    
                #endif /* GDI_USING_LAYER_ROTATE */ 

                    /* test if in region */
                    if (lx < 0 || lx >= layer_info->column_number || ly < 0 || ly >= layer_info->row_number)
                    {
                        continue;
                    }

                    lc = gd_get_buf_pixel[curr_layer->cf] (curr_layer->buf_ptr, curr_layer->width, lx, ly);

                    if (curr_layer->vcf == GDI_COLOR_FORMAT_8)       /* if is index color */
                    {
                        lc &= 0x00ff;
                        GDI_PALETTE_COLOR_TO_RGB(
                            &LA,
                            &LR,
                            &LG,
                            &LB,
                            gdi_w32_palette[layer_info->color_palette_select][lc]);
                    }
                    else
                    {
                        gd_color_to_rgb[curr_layer->cf](&LA, &LR, &LG, &LB, lc);
                    }

                    /* is source key color */
                    if (layer_info->source_key_enable && layer_info->source_key == lc)
                    {
                        continue;
                    }

                    if (layer_info->opacity_enable || layer_info->source_color_format == GDI_HW_COLOR_FORMAT_32)
                    {
                        unsigned char op_value;     /* opacity value */
                        unsigned char op_value_c;   /* opacity value complement */

                        /* calc opacity ratio */
                        if (layer_info->source_color_format == GDI_HW_COLOR_FORMAT_32)
                        {
                            /* To Support COLOR_FORMAT_32*/
                            op_value_c = (LA & 0x0ff);
                            op_value = (~LA) & 0x0ff;

                        }
                        else
                        {

                            op_value_c = layer_info->opacity_value;
                            op_value = ~op_value_c;
                        }

                        if (op_value != 0)
                        {
                            OR = (OR * op_value + LR * op_value_c) >> 8;
                            OG = (OG * op_value + LG * op_value_c) >> 8;
                            OB = (OB * op_value + LB * op_value_c) >> 8;
                        }
                        else
                        {

                            OR = LR;
                            OG = LG;
                            OB = LB;
                        }
                    }
                    else
                    {
                        OR = LR;
                        OG = LG;
                        OB = LB;
                    }
                }
            }

            if (!is_to_layer)
            {
                *dest = BGR(OR, OG, OB);
            }
            else
            {
                curr_layer = &gdi_w32_output_layer;

                /* to support flatten with negative offset */
                gd_put_buf_pixel[curr_layer->cf] (curr_layer->buf_ptr, curr_layer->width, dx - GDI_LAYER_OFFSET, dy - GDI_LAYER_OFFSET, gd_color_from_rgb[curr_layer->cf](0xFF, OR, OG, OB));
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  lcd_fb_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
#if (LCD_USE_C_MODEL == 0)
LCD_STATUS_CODE_ENUM lcd_fb_update(lcd_frame_update_struct *lcd_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
    bg = lcd_para->roi_background_color;
#else 
    bg = 0x00ffffff;
#endif 

    lcd_fb_update_internal(
        lcd_para->lcd_id - 1,
        (U32*) gdi_w32_lcd_buffer[lcd_para->lcd_id - 1],
        GDI_LCD->act_width,
        GDI_LCD->act_height,
        lcd_para->lcm_start_x,
        lcd_para->lcm_start_y,
        lcd_para->lcm_end_x,
        lcd_para->lcm_end_y,
        lcd_para->roi_offset_x,
        lcd_para->roi_offset_y,
        lcd_para->update_layer,
        FALSE,
        FALSE,
        bg);

    w32_lcd_update(lcd_para, gdi_w32_layer_data, layer_flag_table, gdi_w32_lcd_buffer[lcd_para->lcd_id - 1]);

    if(!lcd_para->block_mode_flag)
        if(lcd_para->lcd_block_mode_cb)
            lcd_para->lcd_block_mode_cb();
    return LCD_OK;
}
#else
LCD_STATUS_CODE_ENUM lcd_fb_update(lcd_frame_update_struct *lcd_para)
{
    lcd_roi_config_t roi_config;
    int i;
    unsigned char * pTempBuffer = NULL;
    //kal_printf("New MoDIS test load. lcd_fb_update()\n");
    memset(&roi_config, 0, sizeof(roi_config));
    roi_config.alpha = 0xFF;
#ifdef GDI_USING_LAYER_BACKGROUND
    roi_config.bgclr = lcd_para->roi_background_color;
#else
    roi_config.bgclr = 0x00FFFFFF;
#endif 
    roi_config.layer_en = lcd_para->update_layer >> (32 - SIMULATOR_LAYER_COUNT);
    roi_config.ofs.x = lcd_para->roi_offset_x;
    roi_config.ofs.y = lcd_para->roi_offset_y;
    pTempBuffer = (unsigned char*) malloc(GDI_LCD->act_width * GDI_LCD->act_height * 4);
    roi_config.w2m_add = pTempBuffer;//(unsigned char*) (gdi_w32_lcd_buffer[lcd_para->lcd_id - 1]);
    roi_config.size.x = lcd_para->lcm_end_x - lcd_para->lcm_start_x + 1;
    roi_config.size.y = lcd_para->lcm_end_y - lcd_para->lcm_start_y + 1;
    roi_config.w2m_fmt = W2M_32BPP;
    roi_config.w2m = 1;
    
    roi_config.pitch = GDI_LCD->act_width;
    roi_config.w2m_ofs.x = lcd_para->lcm_start_x;
    roi_config.w2m_ofs.y = lcd_para->lcm_start_y;    
#if defined(GDI_USING_LAYER_OUTPUT_ANOTHER_MEMORY)
    if (lcd_para->block_mode == LCD_WM_BLOCK_MODE)
    {
        roi_config.w2m_ofs.x = lcd_para->dest_offset_x + lcd_para->lcm_start_x;
        roi_config.w2m_ofs.y = lcd_para->dest_offset_y + lcd_para->lcm_start_y;
        roi_config.pitch = GDI_LCD->act_width;
    }
    else
    {
        roi_config.w2m_ofs.x = lcd_para->lcm_start_x;
        roi_config.w2m_ofs.y = lcd_para->lcm_start_y;
        roi_config.pitch = GDI_LCD->act_width;
    }
#endif
#if (LCD_PITCH_BY_PIXEL == 0)
    roi_config.pitch *= 4;
#endif
    for (i=0; i<256; i++)
        roi_config.palette[i] = gdi_w32_palette[0][i];
    if (g_lcd_debug)  // For debug
    {
        if (lcd_para->update_layer & 0x80000000)
            dump(g_layer_config[0].layer_add, g_layer_config[0].size.x, g_layer_config[0].size.y, g_layer_config[0].bpp, "blt_layer0.ibf");
        if (lcd_para->update_layer & 0x40000000)
            dump(g_layer_config[1].layer_add, g_layer_config[1].size.x, g_layer_config[1].size.y, g_layer_config[1].bpp, "blt_layer1.ibf");
        if (lcd_para->update_layer & 0x20000000)
            dump(g_layer_config[2].layer_add, g_layer_config[2].size.x, g_layer_config[2].size.y, g_layer_config[2].bpp, "blt_layer2.ibf");
        if (lcd_para->update_layer & 0x10000000)
            dump(g_layer_config[3].layer_add, g_layer_config[3].size.x, g_layer_config[3].size.y, g_layer_config[3].bpp, "blt_layer3.ibf");
        if (lcd_para->update_layer & 0x08000000)
            dump(g_layer_config[4].layer_add, g_layer_config[4].size.x, g_layer_config[4].size.y, g_layer_config[4].bpp, "blt_layer4.ibf");
        if (lcd_para->update_layer & 0x04000000)
            dump(g_layer_config[5].layer_add, g_layer_config[5].size.x, g_layer_config[5].size.y, g_layer_config[5].bpp, "blt_layer5.ibf");
    }

    _modis_lcd_update(g_layer_config, &roi_config);

    // Copy ROI region to GRAM
    for (i=lcd_para->lcm_start_y; i<=lcd_para->lcm_end_y; i++)
    {
        memcpy (gdi_w32_lcd_buffer[lcd_para->lcd_id - 1] + (GDI_LCD->act_height - 1 - i) * GDI_LCD->act_width + lcd_para->lcm_start_x, &pTempBuffer[i*GDI_LCD->act_width*4+lcd_para->lcm_start_x*4], roi_config.size.x*4);
    }
    if (g_lcd_debug)  // For debug
        dump(gdi_w32_lcd_buffer[lcd_para->lcd_id - 1], GDI_LCD->act_width, GDI_LCD->act_height, 4, "blt.ibf");

    free(pTempBuffer);
    w32_lcd_update(lcd_para, gdi_w32_layer_data, layer_flag_table, gdi_w32_lcd_buffer[lcd_para->lcd_id - 1]);

    if(!lcd_para->block_mode_flag)
        if(lcd_para->lcd_block_mode_cb)
            lcd_para->lcd_block_mode_cb();
    return LCD_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  lcd_fb_update_to_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
#if (LCD_USE_C_MODEL == 0)
LCD_STATUS_CODE_ENUM lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bg;
    U32 bpp=2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_USING_LAYER_BACKGROUND
    bg = para->roi_background_color;
#else 
    bg = 0x00ffffff;
#endif 

    gdi_w32_output_layer = *gdi_act_layer;

#if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)
    switch(para->memory_data_format)
    {         
    case LCD_WMEM_RGB565:
        bpp = 2;
        break;         
    case LCD_WMEM_RGB888:
        bpp = 3;
        break;         
    default:
        ASSERT(0);
        break;         
    }
#endif
    if (LCD_WM_BLOCK_MODE == para->block_mode)
    {
        para->dest_buffer_address += ((para->dest_block_width * para->dest_offset_y +para->dest_offset_x)*bpp);
    } 
    lcd_fb_update_internal(
        GDI_LCD->act_handle - 1,
        (U32*) para->dest_buffer_address,
        para->dest_block_width,
        0,  /* top-to-download will not use this variable */
        0,  /* startx */
        0,  /* starty */
        para->roi_width - 1,
        para->roi_height - 1,
        para->roi_offset_x,
        para->roi_offset_y,
        para->update_layer,
        TRUE,
        TRUE,
        bg);
    return LCD_OK;
}
#else
LCD_STATUS_CODE_ENUM lcd_fb_update_to_memory(lcd_frame_update_to_mem_struct *para)
{
    lcd_roi_config_t roi_config;
    int i;
    int bpp = 0;
    //kal_printf("New MoDIS test load. lcd_fb_update_to_memory()\n");
    memset(&roi_config, 0, sizeof(roi_config));
    roi_config.alpha = para->alpha_value;
#ifdef GDI_USING_LAYER_BACKGROUND
    roi_config.bgclr = para->roi_background_color;
#else
    roi_config.bgclr = 0x00FFFFFF;
#endif 
    roi_config.layer_en = para->update_layer >> (32 - SIMULATOR_LAYER_COUNT);	// 32 - layernum
    roi_config.ofs.x = para->roi_offset_x;
    roi_config.ofs.y = para->roi_offset_y;
    roi_config.w2m_add = (unsigned char*)(para->dest_buffer_address);
    roi_config.size.x = para->roi_width;
    roi_config.size.y = para->roi_height;
    roi_config.w2m = 1;
    roi_config.w2m_fmt = W2M_16BPP;
    bpp = 2;
#if defined(DRV_LCD_MEMORY_OUTPUT_RGB888_SUPPORT)

    if (0)
    {
    }
#ifdef LCD_WMEM_RGB565
    else if (para->memory_data_format == LCD_WMEM_RGB565)
    {
        roi_config.w2m_fmt = W2M_16BPP;
        bpp = 2;
    }
#endif
#ifdef LCD_WMEM_RGB888
    else if (para->memory_data_format == LCD_WMEM_RGB888)
    {
        roi_config.w2m_fmt = W2M_24BPP;
        bpp = 3;
    }
#endif
#ifdef LCD_WMEM_ARGB8888
    else if (para->memory_data_format == LCD_WMEM_ARGB8888)
    {
        roi_config.w2m_fmt = W2M_32BPP;
        bpp = 4;
    }
#endif
#ifdef LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA:
    else if (para->memory_data_format == LCD_WMEM_ARGB8888_WITH_PIXEL_ALPHA)
    {
        roi_config.w2m_fmt = W2M_32BPP_ALPHA;
        bpp = 4;
    }
#endif
#ifdef LCD_WMEM_PARGB8888
    else if (para->memory_data_format == LCD_WMEM_PARGB8888)
    {
        roi_config.w2m_fmt = W2M_32BPP;
        bpp = 4;
    }
#endif
#ifdef LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA:
    else if (para->memory_data_format == LCD_WMEM_PARGB8888_WITH_PIXEL_ALPHA)
    {
        roi_config.w2m_fmt = W2M_32BPP_ALPHA;
        bpp = 4;
    }
#endif
    else
        ASSERT(0);

#endif
    roi_config.pitch = para->dest_block_width;
#if defined(GDI_USING_LAYER_OUTPUT_ANOTHER_MEMORY)
    if (para->block_mode == LCD_WM_BLOCK_MODE)
    {
        roi_config.w2m_ofs.x = para->dest_offset_x;
        roi_config.w2m_ofs.y = para->dest_offset_y;
        roi_config.pitch = para->dest_block_width;
    }
    else
    {
        roi_config.pitch = roi_config.size.x;
    }
#endif
#if (LCD_PITCH_BY_PIXEL == 0)
    roi_config.pitch *= bpp;
#endif
    for (i=0; i<256; i++)
        roi_config.palette[i] = gdi_w32_palette[0][i];
    if (g_lcd_debug)  // For debug
    {
        if (para->update_layer & 0x80000000)
            dump(g_layer_config[0].layer_add, g_layer_config[0].size.x, g_layer_config[0].size.y, g_layer_config[0].bpp, "flatten_layer0.ibf");
        if (para->update_layer & 0x40000000)
            dump(g_layer_config[1].layer_add, g_layer_config[1].size.x, g_layer_config[1].size.y, g_layer_config[1].bpp, "flatten_layer1.ibf");
        if (para->update_layer & 0x20000000)
            dump(g_layer_config[2].layer_add, g_layer_config[2].size.x, g_layer_config[2].size.y, g_layer_config[2].bpp, "flatten_layer2.ibf");
        if (para->update_layer & 0x10000000)
            dump(g_layer_config[3].layer_add, g_layer_config[3].size.x, g_layer_config[3].size.y, g_layer_config[3].bpp, "flatten_layer3.ibf");
        if (para->update_layer & 0x08000000)
            dump(g_layer_config[4].layer_add, g_layer_config[4].size.x, g_layer_config[4].size.y, g_layer_config[4].bpp, "flatten_layer4.ibf");
        if (para->update_layer & 0x04000000)
            dump(g_layer_config[5].layer_add, g_layer_config[5].size.x, g_layer_config[5].size.y, g_layer_config[5].bpp, "flatten_layer5.ibf");
    }

    _modis_lcd_update(g_layer_config, &roi_config);

    if (g_lcd_debug)  // For debug
        dump(roi_config.w2m_add, para->dest_block_width, roi_config.ofs.y+roi_config.size.y, bpp, "flatten.ibf");

    return LCD_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  config_lcd_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_output      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void config_lcd_output(kal_bool lcd_output)
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
 *  lcd_get_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id          [IN]        
 *  lcd_width       [?]         
 *  lcd_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* lcd_get_size() */


/*****************************************************************************
 * FUNCTION
 *  lcd_get_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_id          [IN]        
 *  lcd_width       [?]         
 *  lcd_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MTK_TARGET__
extern volatile LCD_Funcs *MainLCD;
extern volatile LCD_Funcs *SubLCD;
void LCD_FunConfig(void);
kal_uint32 lcd_get_lcm_ppi(kal_uint8 lcd_id)
{
    kal_uint32 ppi;
    LCD_FunConfig();
    if (lcd_id == 0)
    {
        if (LCM_IOCTRL_NOT_SUPPORT == MainLCD->IOCTRL(LCM_IOCTRL_QUERY__LCD_PPI, &ppi))
        {
            ppi = 0;
        }
    }
#ifdef DUAL_LCD
    if (lcd_id == 1)
    {
        if (LCM_IOCTRL_NOT_SUPPORT == SubLCD->IOCTRL(LCM_IOCTRL_QUERY__LCD_PPI, &ppi))
        {
            ppi = 0;
        }
    }
#endif
    return ppi;
}
kal_uint32 lcd_enable_te_in_sw_trigger(kal_bool enable)
{

    return KAL_TRUE;
}

kal_uint8 lcd_get_te_ctrl_handle(void)
{
    return 0;
}

kal_bool lcd_te_ctrl_push(kal_bool on_Noff, kal_uint8 handle)
{
    return KAL_FALSE;
}

kal_bool lcd_te_ctrl_pop(kal_uint8 handle)
{
    return KAL_FALSE;
}

kal_bool lcd_set_mm_layer_attrib(kal_uint32 enabled_layer, kal_uint32 vdo_buff_addr)
{
    return KAL_TRUE;
}

LCD_CAPS_QUERY_RESULT_E lcd_get_device_caps(LCD_CAPS_ID_E id, kal_uint32 *p_argu)
{
    return LCD_CAPS_NOT_SUPPORT;
}

kal_uint32 get_lcd_frame_buffer_address(void)
{
    return 0;
}

void lcd_em_general_test(kal_uint32 param1,kal_uint32 param2,kal_uint32 param3,kal_uint32 param4)
{
}

#if defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__)
void lcd_landscape_ui_init(kal_uint8* flatten_buff_addr, kal_uint32 flatten_buff_size, kal_uint32 memory_data_format)
{
}

void lcd_landscape_ui_set_mode(LCD_LANDSP_MODE_E mode)
{
}

void lcd_landscape_ui_set_flatten_buff_attr(kal_uint8* flatten_buff_addr, kal_uint32 flatten_buff_size, kal_uint32 memory_data_format)
{
}

kal_uint32 lcd_landscape_ui_query_drvier_buffer_size(kal_uint32 memory_data_format)
{
    return 0;
}
#endif

#endif

#ifndef __MTK_TARGET__
/* MAUI_02255666: Export this API for AP to tell LCD if they want to use
** Partial update or not for SW trigger mode. This is just a temp workaround
*/
void lcd_enable_partial_update(kal_bool flag)
{
}

void SpeechLcdTest(kal_bool iEnable,kal_uint8 iPeriod)
{
  
}

DisplayResultEnum DisplayIOControl(DisplayDeviceEnum device, DisplayCtrlCode code, void* pData)
{
    DisplayResultEnum result = DISPLAY_RESULT_OK;
    switch (code)
    {
    case DISPLAY_IOCTL_CABC_QUERY_SUPPORT:
        {
            DisplayCABC_T* pCABCStruct = (DisplayCABC_T*) pData;
            if (pCABCStruct)
            {
                pCABCStruct->bSupport = KAL_FALSE;
            }
            else
                result = DISPLAY_RESULT_INVALID_DATA;
        }
        break;
    case DISPLAY_IOCTL_CABC_SET_MODE:
        result = DISPLAY_RESULT_CONTROL_FAIL;
        break;
    case DISPLAY_IOCTL_CABC_GET_MODE:
        result = DISPLAY_RESULT_CONTROL_FAIL;
        break;
    default:
        result = DISPLAY_RESULT_INVALID_CODE;
        break;
    }

    return result;
}
#endif //#ifndef __MTK_TARGET__

#endif //#if defined(DRV_DISPLAY_DRIVER_V1)

#endif // MMI_BASE != NEPTUNE_MMI


