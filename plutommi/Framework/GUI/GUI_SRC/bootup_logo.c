#if defined(__ZIMAGE_SUPPORT__) 

#include "lcd_if.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"

#include "MMIDataType.h"
#include "mmi_features.h"
#include "gdi_include.h"
#include "bootup_logo.h"

#if defined(DRV_DISPLAY_DRIVER_V2)
#include "wfc.h"
#include "Owfimage.h"
#endif


#include "CustBootupImgData.h"


void get_image_start_values_dummy (int * offset_x, int * offset_y)
{
	kal_uint32 temp;
	int height, width;
	
	temp = (kal_uint32)((kal_uint32)bootup_logo_img[5] | (kal_uint32)(bootup_logo_img[6]<<8) | (kal_uint32)(bootup_logo_img[7]<<16));
	
	width =  (kal_uint32)((temp & 0x00FFF000)>>12);
	height = (kal_uint32)(temp & 0x00000FFF);

	*offset_x = (GDI_LCD_WIDTH - width )/2;
	*offset_y = (GDI_LCD_HEIGHT - height )/2;
}


void draw_bootup_pbm_image(int offset_x, int offset_y, const kal_uint8 *dev_bmp_src, kal_uint8 *layer_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 dev_bmp_width;
    kal_uint32 dev_bmp_height;
    kal_uint32 dev_bmp_depth;
    kal_uint32 dev_bmp_row_byte;
    int i, j;
    int y_jump, x_jump;
    int jump_size;
    int y_draw_count;
    int x_draw_count;
    
    kal_uint16 *dest_ptr;
    kal_uint16 *dest_ptr_line_start;
    kal_uint8 *dev_bmp_ptr_line_start;
    kal_uint8 *dev_bmp_ptr;
    kal_uint32 byte_per_pixel;
    kal_uint32 size;
    kal_uint16 pixel_color;
    int temp_value = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	
	
    /* TODO: add size check */
    dev_bmp_width = dev_bmp_src[0] | (dev_bmp_src[1] << 8) | (dev_bmp_src[2] << 16) | (dev_bmp_src[3] << 24);
    dev_bmp_src += 4;
    dev_bmp_height = dev_bmp_src[0] | (dev_bmp_src[1] << 8) | (dev_bmp_src[2] << 16) | (dev_bmp_src[3] << 24);
    dev_bmp_src += 4;
    dev_bmp_depth = dev_bmp_src[0];
    dev_bmp_src += 1;
    dev_bmp_row_byte = dev_bmp_src[0] | (dev_bmp_src[1] << 8) | (dev_bmp_src[2] << 16) | (dev_bmp_src[3] << 24);
    dev_bmp_src += 4;

    byte_per_pixel = 2;

    
    y_jump = 0;   
    x_jump = 0;
    dev_bmp_ptr_line_start = (kal_uint8 *)dev_bmp_src;

    jump_size = ((y_jump + offset_y/* + dev_bmp_height - 1*/) * GDI_LCD_WIDTH + offset_x) * byte_per_pixel; //13410
    dest_ptr_line_start = (kal_uint16*) (layer_buffer + jump_size);

	x_draw_count = dev_bmp_width ; 
 	y_draw_count = dev_bmp_height; 

    for (i = 0; i < y_draw_count; i++)
    {
        dest_ptr = dest_ptr_line_start + GDI_LCD_WIDTH * i;
        dev_bmp_ptr = dev_bmp_ptr_line_start + dev_bmp_width * i * 2;

        for (j = 0; j < x_draw_count; j++)
        {
            pixel_color = (dev_bmp_ptr[0]) | (dev_bmp_ptr[1] << 8);
            if (pixel_color != 0x1234)
            {
                temp_value = (int) pixel_color;
                (*((kal_uint16*)layer_buffer+((i + offset_y)*(GDI_LCD_WIDTH)+(j + offset_x))))= temp_value;
            }
            dev_bmp_ptr += 2;
            dest_ptr++;
        }
    }

}



void MMICheckDiskDisplay_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *layer_buffer;
    int offset_x;
    int offset_y;
    static kal_uint32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_init();
    layer_buffer = GDI_LAYERS[0].buf_ptr;

    #if defined(GUI_BOOTUP_LOGO_X) && defined(GUI_BOOTUP_LOGO_Y)
    offset_x = GUI_BOOTUP_LOGO_X;
    offset_y = GUI_BOOTUP_LOGO_Y;
    
    #else 
    get_image_start_values_dummy (&offset_x, &offset_y);
    #endif
#ifndef __ZIMAGE_LOGO_ANIMATED_SUPPORT__	
#ifdef __COSMOS_MMI_PACKAGE__
    gdi_layer_clear_nb_concurrent(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, GDI_COLOR_BLACK);
#endif
    draw_bootup_pbm_image(offset_x, offset_y, (kal_uint8  *) bootup_logo_img + 8, layer_buffer); 
    gdi_layer_blt(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0, 0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
#else
    if ((i % 2) == 0)
    {
        gdi_layer_clear_nb_concurrent(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, GDI_COLOR_BLACK);
        if ((i % 8) == 0)
        {
            draw_bootup_pbm_image(offset_x, offset_y, (kal_uint8  *) bootup_logo_img_1 + 8, layer_buffer); 
        }
        else if ((i % 8) == 2)
        {
            draw_bootup_pbm_image(offset_x, offset_y, (kal_uint8  *) bootup_logo_img_2 + 8, layer_buffer); 
        }
        else if ((i % 8) == 4)
        {
            draw_bootup_pbm_image(offset_x, offset_y, (kal_uint8  *) bootup_logo_img_3 + 8, layer_buffer); 
        }  
        else 
        {
            draw_bootup_pbm_image(offset_x, offset_y, (kal_uint8  *) bootup_logo_img_4 + 8, layer_buffer); 
        } 
    	gdi_layer_blt(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0, 0, 0, GDI_LCD_WIDTH - 1, GDI_LCD_HEIGHT - 1);
    }
    i ++;    
#endif
    
}

#endif

