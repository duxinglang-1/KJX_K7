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
*  lcd_c_model_process.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  LCD C Model
*
* Author:
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "stdio.h"
#include "stdlib.h" 
#include "string.h"
//#include "utl.h"
#include "kal_non_specific_general_types.h"
//#include "lcd_sw_inc.h"
#include "lcd_c_model.h"
//#include "lcd.h"
//#include "lcd_function.h"
//#include "lcd_sw.h"

#pragma runtime_checks("", off)
#pragma optimize("g", on)
#pragma optimize("t", on)
#pragma optimize("2", on)
#define LCD_C_MODEL_SINGLE_LAYER_OPTIMIZATION
// initial all static variable, add by Neil Xu 2008-11-4
int initial_write_to_LCM = 1;
int initial_dithering    = 1;
extern lcd_register_struct lcd_sw_register;
extern lcd_layer_config_t  lcd_sw_layer_config[4];
extern lcd_roi_config_t    lcd_sw_roi_config;

lcd_color lcd_rgb666to888(unsigned int rgb666)
{
   unsigned int temp;
   lcd_color pixel;

   temp = (rgb666>>18)&0x3f;
   pixel.alpha = (temp<<2) | ((temp>>4)&0x3);

   temp = (rgb666>>12)&0x3f;
   pixel.r = (temp<<2) | ((temp>>4)&0x3);

   temp = (rgb666>>6)&0x3f;
   pixel.g = (temp<<2) | ((temp>>4)&0x3);

   temp = rgb666&0x3f;
   pixel.b = (temp<<2) | ((temp>>4)&0x3);

   return (pixel);
}

lcd_color rgb565to888(unsigned int rgb565)
{                                            
    unsigned int temp;                        
    lcd_color pixel;                       

    temp = (rgb565>>11)&0x1f;                 
    pixel.r = (temp<<3) | ((temp>>2)&0x7);    

    temp = (rgb565>>5)&0x3f;                  
    pixel.g = (temp<<2) | ((temp>>4)&0x3);    

    temp = (rgb565)&0x1f;                     
    pixel.b = (temp<<3) | ((temp>>2)&0x7);    

    return(pixel);                            
}   

unsigned int YUYV422_to_RGB888(unsigned int yuv_pixel)
{

    int tempY, tempU, tempV;

    int R, G, B;

    //extract YUV parts
    tempV = (yuv_pixel>>16) & 0xff;
    tempU = (yuv_pixel>>8) & 0xff;
    tempY = (yuv_pixel) & 0xff;

    /*
    tempY = (yuv_pixel>>16) & 0xff;
    tempU = (yuv_pixel>>8) & 0xff;
    tempV = (yuv_pixel) & 0xff;
    */

    //convert each to RGB component;
    R = (32*tempY + 45*(tempV-128))/32;
    G = (32*tempY + -11*(tempU-128) + -23*(tempV-128))/32;
    B = (32*tempY + 57*(tempU-128))/32;

    //make sure within 8 bit limit
    if (R > 255) R = 255;
    else if (R < 0) R = 0;

    if (G > 255) G = 255;
    else if (G < 0) G = 0;

    if (B > 255) B = 255;
    else if (B < 0) B = 0;

    /*
    printf("rgbYUV to 888\n");
    printf("Y:%x U:%x V:%x\n", tempY, tempU, tempV);
    printf("R:%x G:%x B:%x\n", (unsigned int)R, (unsigned int)G, (unsigned int)B );
    printf("\n");
    */

    return( (R<<16) | (G<<8) | B );

}

kal_uint16 rgb666to565(kal_uint32 rgb666_data)
{
    kal_uint8 r_data,g_data,b_data;
    kal_uint16 return_data;

    r_data=((rgb666_data>>12)&0x3F)>>1;
    g_data=(rgb666_data>>6)&0x3F;
    b_data=((rgb666_data)&0x3F)>>1;

    return_data=(r_data<<11)|(g_data<<5)|(b_data);

    return return_data;
}	/* rgb666_to_rgb555() */

lcd_color lcd_int2color(unsigned int *pixel_int, unsigned char clrdpt, unsigned char swap )
{
    lcd_color pixel;
    unsigned int swap_pixel;

    if (swap) 
    {
        if (clrdpt==RGB565) 
        {
            swap_pixel = ((*pixel_int&0xff)<<8) | ((*pixel_int>>8)&0xff);
        }
        else if (clrdpt==RGB888)
        {
            swap_pixel = ((*pixel_int&0xff)<<16) | (*pixel_int&0xff00) | ((*pixel_int>>16)&0xff);
        }
        else if ((clrdpt==ARGB8888) || (clrdpt == PARGB8888))
        {
            swap_pixel = ((*pixel_int&0xff)<<24) | (((*pixel_int>>8)&0xff)<<16) | 
                (((*pixel_int>>16)&0xff)<<8) | ((*pixel_int>>24)&0xff);
        }
    } 
    else
    {
        swap_pixel = *pixel_int;
    }

    *pixel_int = swap_pixel;

    switch(clrdpt) 
    {
    case RGB565: 
        pixel = rgb565to888(swap_pixel);
        break;
    case RGB888:  
        pixel.r = (swap_pixel>>16) & 0xff;
        pixel.g = (swap_pixel>>8)  & 0xff;
        pixel.b = (swap_pixel)     & 0xff;
        break;
    case ARGB8888:
    case PARGB8888:
        pixel.alpha = (swap_pixel>>24) &0xff;
        pixel.r = (swap_pixel>>16) & 0xff;
        pixel.g = (swap_pixel>>8)  & 0xff;
        pixel.b = (swap_pixel)     & 0xff;
        break;
     case ARGB6666:
     case PARGB6666:
	pixel = lcd_rgb666to888(swap_pixel);
	break;
    }
    return(pixel);
}


//Write pixel to memory location addr.
void lcd_write_to_memory_mem( lcd_color pixel, lcd_roi_config_t *roi_config, unsigned char *addr)
{
    switch (roi_config->w2m_fmt) 
    {
    unsigned int argb6666_val;
    case W2M_RGB565:
        *addr = ((pixel.g&0x1c)<<3) | (pixel.b>>3);
        *(addr+1) = (pixel.r&0xf8) | (pixel.g>>5);
        break;
    case W2M_RGB888:
        *addr = pixel.b;
        *(addr+1) = pixel.g;
        *(addr+2) = pixel.r;
        break;
    case W2M_PARGB8888_CONST_A:
        *addr = pixel.b;
        *(addr+1) = pixel.g;
        *(addr+2) = pixel.r;
        *(addr+3) = (unsigned char) roi_config->alpha;
        break;
    case W2M_PARGB8888_PER_A:
        *addr = pixel.b;
        *(addr+1) = pixel.g;
        *(addr+2) = pixel.r;
        *(addr+3) = pixel.alpha;
        break;
    case W2M_PARGB6666_CONST_A:
	      argb6666_val = ((((unsigned char)roi_config->alpha)>>2)<<18 ) | ((pixel.r>>2)<<12 ) | ((pixel.g>>2)<<6) | (pixel.b>>2);
	      *addr	= argb6666_val		& 0xff;
	      *(addr+1)= (argb6666_val>>8) & 0xff;
	      *(addr+2)= (argb6666_val>>16)& 0xff;
	      break;
	  case W2M_PARGB6666_PER_A:
	      argb6666_val = ((pixel.alpha>>2)<<18 ) | ((pixel.r>>2)<<12 ) | ((pixel.g>>2)<<6) | (pixel.b>>2);
	      *addr	= argb6666_val		& 0xff;
	      *(addr+1)= (argb6666_val>>8) & 0xff;
	      *(addr+2)= (argb6666_val>>16)& 0xff;
	      break;
    }
}

unsigned char lcd_lookup_gamma(unsigned char index, unsigned char table_id, unsigned int *gamma_table)
{
    unsigned int gamma_int;
    unsigned int gamma_value;

    gamma_int = gamma_table[index];

    if (table_id == GAMMA0)
        gamma_value = gamma_int & 0xff; 
    else if (table_id == GAMMA1)
        gamma_value = (gamma_int>>8) & 0xff; 
    else if (table_id == GAMMA2)
        gamma_value = (gamma_int>>16) & 0xff; 
    else
        gamma_value = index;

    return((unsigned char)gamma_value);
}

void lcd_gamma_correct(lcd_color *src, lcd_roi_config_t *roi_config )
{
    unsigned int if_num;

    if_num = (roi_config->data_addr>>12) &0xff;


    if ((if_num == 0x8) || (if_num == 0x9)) {
        src->r = lcd_lookup_gamma(src->r, roi_config->serial_gamma_id, roi_config->gamma);
        src->g = lcd_lookup_gamma(src->g, roi_config->serial_gamma_id, roi_config->gamma);
        src->b = lcd_lookup_gamma(src->b, roi_config->serial_gamma_id, roi_config->gamma);
    }
    else {
        src->r = lcd_lookup_gamma(src->r, roi_config->gamma_id.r, roi_config->gamma);
        src->g = lcd_lookup_gamma(src->g, roi_config->gamma_id.g, roi_config->gamma);
        src->b = lcd_lookup_gamma(src->b, roi_config->gamma_id.b, roi_config->gamma);
    }
}

void lcd_alpha_blend(lcd_color src, lcd_color *dst, lcd_layer_config_t *layer_config)
{

    int SCA = layer_config->opacity;
    int x, x1;
    int y;

    int src_alpha_prime;
    int src_r_prime;
    int src_g_prime;
    int src_b_prime;

   if ((layer_config->clrdpt == ARGB8888) | (layer_config->clrdpt == ARGB6666))
    {
        if (SCA != 0xff) 
        {
            x = (src.alpha * SCA) + 128;
            y = DIV255(x);
            src_alpha_prime = SAT(y);
            x = (dst->alpha * (255 - src_alpha_prime)) + 128;
            y = DIV255(x);
            dst->alpha = SAT(src_alpha_prime + y);

            x  = ((src_alpha_prime * ((int)src.r - (int)dst->r)) + (255*(int)dst->r)) + 128;
            x1 = DIV255(x);
            dst->r = SAT(x1);

            x  = ((src_alpha_prime * ((int)src.g - (int)dst->g)) + (255*(int)dst->g)) + 128;
            x1 = DIV255(x);
            dst->g = SAT(x1);

            x  = ((src_alpha_prime * ((int)src.b - (int)dst->b)) + (255*(int)dst->b)) + 128;
            x1 = DIV255(x);
            dst->b = SAT(x1);
        } 
        else 
        {
            x      = (int)((src.alpha * ((int)src.r - (int)dst->r)) + (255*dst->r)) + 128;
            x1     = DIV255(x);
            dst->r = SAT(x1);

            x      = (int)((src.alpha * ((int)src.g - (int)dst->g)) + (255*dst->g)) + 128;
            x1     = DIV255(x);
            dst->g = SAT(x1);

            x      = (int)((src.alpha * ((int)src.b - (int)dst->b)) + (255*dst->b)) + 128;
            x1     = DIV255(x);
            dst->b = SAT(x1);

            x      = (dst->alpha * (255 - src.alpha)) + 128;
            x1     = DIV255(x);
            dst->alpha = SAT(x1 + src.alpha);
        }
    } 
   else if ((layer_config->clrdpt == PARGB8888) | (layer_config->clrdpt == PARGB6666))
    {
        if (SCA != 0xff) 
        {
            x = (src.alpha * SCA) + 128;
            y = DIV255(x);
            src_alpha_prime = SAT(y);
            x = (dst->alpha * (255 - src_alpha_prime)) + 128;
            y = DIV255(x);
            dst->alpha = SAT(src_alpha_prime + y);

            x = (src.r * SCA) + 128;
            y = DIV255(x);
            src_r_prime = SAT(y);
            x = (dst->r * (255 - src_alpha_prime)) + 128;
            y = DIV255(x);
            dst->r = SAT(src_r_prime + y);

            x = (src.g * SCA) + 128;
            y = DIV255(x);
            src_g_prime = SAT(y);
            x = (dst->g * (255 - src_alpha_prime)) + 128;
            y = DIV255(x);
            dst->g = SAT(src_g_prime + y);

            x = (src.b * SCA) + 128;
            y = DIV255(x);
            src_b_prime = SAT(y);
            x = (dst->b * (255 - src_alpha_prime)) + 128;
            y = DIV255(x);
            dst->b = SAT(src_b_prime + y);
        } 
        else 
        {
            x      = (dst->r * (255 - src.alpha)) + 128;
            x1     = DIV255(x);
            dst->r = SAT(x1 + src.r);

            x      = (dst->g * (255 - src.alpha)) + 128;
            x1     = DIV255(x);
            dst->g = SAT(x1 + src.g);

            x      = (dst->b * (255 - src.alpha)) + 128;
            x1     = DIV255(x);
            dst->b = SAT(x1 + src.b);

            x      = (dst->alpha * (255 - src.alpha)) + 128;
            x1     = DIV255(x);
            dst->alpha = SAT(x1 + src.alpha);
        }
    } 
    else 
    { //layer_config->clrdpt == RGB | YUV
        x      = ((SCA * ((int)src.r - (int)dst->r)) + (255*(int)dst->r)) + 128;
        x1     = DIV255(x);
        dst->r = SAT(x1);

        x      = ((SCA * ((int)src.g - (int)dst->g)) + (255*(int)dst->g)) + 128;
        x1     = DIV255(x);
        dst->g = SAT(x1);

        x      = ((SCA * ((int)src.b - (int)dst->b)) + (255*(int)dst->b)) + 128;
        x1     = DIV255(x);
        dst->b = SAT(x1);

        x      = (dst->alpha * (255 - SCA)) + 128;
        x1     = DIV255(x);
        dst->alpha = SAT(x1 + SCA);
    }
}

unsigned int lcd_lfsr(unsigned int seed) 
{
    unsigned int x;
    unsigned int new_seed;

    //calculate new bit to shift in
    x = (((seed>>19)&0x1) ^ ((seed>>2)&0x1))&0x1;

    new_seed = ((seed&0xfffff)<<1) | x;

    return(new_seed & 0xfffff);

}

lcd_color lcd_dithering(lcd_color src, lcd_roi_config_t *roi_config)
{
    static unsigned int seed_r = 0;
    static unsigned int seed_g = 0;
    static unsigned int seed_b = 0;

    unsigned int b_bits, g_bits, r_bits;
    unsigned int lfsr_r, lfsr_g, lfsr_b;

    lcd_color dithered_pixel;

    unsigned int temp_r, temp_g, temp_b;

    // initial all static variable, add by Neil Xu 2008-11-4  
    if ( initial_dithering == 1 ) 
    {
        seed_r = roi_config->lfsr_r_seed;
        seed_g = roi_config->lfsr_g_seed;
        seed_b = roi_config->lfsr_b_seed;
        initial_dithering = 0;
    }
    //calculate bits to compare from src pixel
    if (roi_config->db_b == 0) b_bits = src.b & 0x1;
    else if (roi_config->db_b == 1) b_bits = src.b & 0x3;
    else if (roi_config->db_b == 2) b_bits = src.b & 0x7;
    else if (roi_config->db_b == 3) b_bits = src.b & 0xf;

    if (roi_config->db_g == 0) g_bits = src.g & 0x1;
    else if (roi_config->db_g == 1) g_bits = src.g & 0x3;
    else if (roi_config->db_g == 2) g_bits = src.g & 0x7;
    else if (roi_config->db_g == 3) g_bits = src.g & 0xf;

    if (roi_config->db_r == 0) r_bits = src.r & 0x1;
    else if (roi_config->db_r == 1) r_bits = src.r & 0x3;
    else if (roi_config->db_r == 2) r_bits = src.r & 0x7;
    else if (roi_config->db_r == 3) r_bits = src.r & 0xf;

    //calculate bits to compare from lfsr output
    if (roi_config->db_b == 0) lfsr_b = seed_b & 0x1;
    else if (roi_config->db_b == 1) lfsr_b = seed_b & 0x3;
    else if (roi_config->db_b == 2) lfsr_b = seed_b & 0x7;
    else if (roi_config->db_b == 3) lfsr_b = seed_b & 0xf;
    seed_b = lcd_lfsr(seed_b);

    if (roi_config->db_g == 0) lfsr_g = seed_g & 0x1;
    else if (roi_config->db_g == 1) lfsr_g = seed_g & 0x3;
    else if (roi_config->db_g == 2) lfsr_g = seed_g & 0x7;
    else if (roi_config->db_g == 3) lfsr_g = seed_g & 0xf;
    seed_g = lcd_lfsr(seed_g);

    if (roi_config->db_r == 0) lfsr_r = seed_r & 0x1;
    else if (roi_config->db_r == 1) lfsr_r = seed_r & 0x3;
    else if (roi_config->db_r == 2) lfsr_r = seed_r & 0x7;
    else if (roi_config->db_r == 3) lfsr_r = seed_r & 0xf;
    seed_r = lcd_lfsr(seed_r);

    //compare values and compute results
    if (b_bits > lfsr_b) 
    {
        temp_b = ((src.b >> (roi_config->db_b + 1)) + 0x1) << (roi_config->db_b + 1);
    }
    else 
    {
        temp_b = ((src.b >> (roi_config->db_b + 1))) << (roi_config->db_b + 1);
    }

    if (g_bits > lfsr_g) 
    {
        temp_g = ((src.g >> (roi_config->db_g + 1)) + 0x1) << (roi_config->db_g + 1);
    }
    else 
    {
        temp_g = ((src.g >> (roi_config->db_g + 1))) << (roi_config->db_g + 1);
    }

    if (r_bits > lfsr_r) 
    {
        temp_r = ((src.r >> (roi_config->db_r + 1)) + 0x1) << (roi_config->db_r + 1);
    }
    else 
    {
        temp_r = ((src.r >> (roi_config->db_r + 1))) << (roi_config->db_r + 1);
    }

    //clamp values
    if (temp_b > 255) 
        dithered_pixel.b = 255;
    else 
        dithered_pixel.b = (unsigned char)temp_b;

    if (temp_g > 255) 
        dithered_pixel.g = 255;
    else 
        dithered_pixel.g = (unsigned char)temp_g;

    if (temp_r > 255) 
        dithered_pixel.r = 255;
    else 
        dithered_pixel.r = (unsigned char)temp_r;

    //copy alpha value and skey_hit value to return;
    dithered_pixel.alpha = src.alpha;
    dithered_pixel.skey_hit = src.skey_hit;
    dithered_pixel.dkey_hit = src.dkey_hit;

    return(dithered_pixel);
}


//piece wise linear gamma correction
lcd_color lcd_lgamma_correct(lcd_color src, lcd_roi_config_t *roi_config)
{
    lcd_color lgamma_pixel;

    int sym_start[8] = {0, 32, 64, 96, 128, 160, 192, 224};
    int sym_end[8] = {31, 63, 95, 127, 159, 191, 223, 255};

    int asym_start[8] = {0, 2, 4, 8, 16, 32, 64, 128};
    int asym_end[8] = {1, 3, 7, 15, 31, 63, 127, 255};

    int i, seg_r, seg_g, seg_b;

    int input_r, input_g, input_b;
    int delta_r, delta_g, delta_b;
    int output_r, output_g, output_b;

    input_r = (int)src.r;
    input_g = (int)src.g;
    input_b = (int)src.b;

    //determine segment for input
    if (roi_config->lgamma_mode == 0) 
    {
        for(i=0; i<LGAMMA_SEGNUM; i++) 
        {

            if ((input_r <= asym_end[i]) && (input_r >= asym_start[i])) 
                seg_r = i;
            if ((input_g <= asym_end[i]) && (input_g >= asym_start[i])) 
                seg_g = i;
            if ((input_b <= asym_end[i]) && (input_b >= asym_start[i])) 
                seg_b = i;
        }
        delta_r = input_r - asym_start[seg_r];
        delta_g = input_g - asym_start[seg_g];
        delta_b = input_b - asym_start[seg_b];
    }
    else 
    {
        for(i=0; i<LGAMMA_SEGNUM; i++) 
        {
            if ((input_r <= sym_end[i]) && (input_r >= sym_start[i])) 
                seg_r = i;
            if ((input_g <= sym_end[i]) && (input_g >= sym_start[i])) 
                seg_g = i;
            if ((input_b <= sym_end[i]) && (input_b >= sym_start[i])) 
                seg_b = i;
        }

        delta_r = input_r - sym_start[seg_r];
        delta_g = input_g - sym_start[seg_g];
        delta_b = input_b - sym_start[seg_b];
    }

    //calculate gamma corrected output
    output_r = ((((int)roi_config->lgamma_slope[seg_r]*delta_r)&0xffff)>>roi_config->lgamma_dec_bits[seg_r])
        + roi_config->lgamma_offset[seg_r];

    output_g = ((((int)roi_config->lgamma_slope[seg_g]*delta_g)&0xffff)>>roi_config->lgamma_dec_bits[seg_g])
        + roi_config->lgamma_offset[seg_g];

    output_b = ((((int)roi_config->lgamma_slope[seg_b]*delta_b)&0xffff)>>roi_config->lgamma_dec_bits[seg_b])
        + roi_config->lgamma_offset[seg_b];
    //clamp values to 8 bits per channel
    if (output_r>255) output_r = 255;
    if (output_g>255) output_g = 255;
    if (output_b>255) output_b = 255;

    //fill out fields of lgamma_pixel and return   
    lgamma_pixel.r = (unsigned char)output_r;
    lgamma_pixel.g = (unsigned char)output_g;
    lgamma_pixel.b = (unsigned char)output_b;
    lgamma_pixel.alpha = src.alpha;
    lgamma_pixel.skey_hit = src.skey_hit;
    lgamma_pixel.dkey_hit = src.dkey_hit;

    return(lgamma_pixel);
}


lcd_color lcd_get_pixel_value(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config, lcd_vec2 layer_pos)
{
    int index;   
    lcd_color src;
    unsigned int src_color;
    unsigned int index_color;
    unsigned int src_key;
    unsigned int yuvaddr;
    unsigned int num_bytes;
    unsigned int addr;

    //calculate the memory address of the pixel
    index = layer_config->pitch * layer_pos.y + layer_pos.x;

    if (layer_config->clrdpt == BPP8) 
        num_bytes = 1;
    else if (layer_config->clrdpt == RGB565) 
        num_bytes = 2;
    else if ((layer_config->clrdpt == RGB888) || (layer_config->clrdpt == ARGB6666) || (layer_config->clrdpt == PARGB6666))
        num_bytes = 3;
    else if ((layer_config->clrdpt == ARGB8888) || (layer_config->clrdpt == PARGB8888)) 
        num_bytes = 4;
    else if (layer_config->clrdpt == YUYV422) 
        num_bytes = 2;

    addr = index;

    //for BPP24
    if (layer_config->clrdpt == BPP8) 
    {
        src_color = layer_config->layer_add[addr];
    }
    else if (layer_config->clrdpt == RGB565) 
    {
        src_color = layer_config->layer_add[addr*num_bytes] | (layer_config->layer_add[addr*num_bytes+1]<<8);
    }
   else if ((layer_config->clrdpt == RGB888 || (layer_config->clrdpt == ARGB6666) || 
	   (layer_config->clrdpt == PARGB6666)) )
    {
        src_color = layer_config->layer_add[addr*num_bytes] | (layer_config->layer_add[addr*num_bytes+1]<<8) |
            (layer_config->layer_add[addr*num_bytes+2]<<16);
    }
    else if ((layer_config->clrdpt == ARGB8888) || (layer_config->clrdpt == PARGB8888)) 
    {
        src_color = layer_config->layer_add[addr*num_bytes] | (layer_config->layer_add[addr*num_bytes+1]<<8) |
            (layer_config->layer_add[addr*num_bytes+2]<<16)| (layer_config->layer_add[addr*num_bytes+3]<<24);
    }
    else if (layer_config->clrdpt == YUYV422) 
    {
        //odd pixel
        if (addr & 0x1) 
        {
            yuvaddr = (2*(layer_pos.x-1)) + (layer_pos.y*layer_config->pitch*num_bytes);

            //need to do swap here because we only store YUV and throw away
            //the other Y for each pixel, so cant do swap once we enter 
            //process_roi. 
            if (layer_config->swap) 
            {
                src_color = layer_config->layer_add[(yuvaddr)+2] |(layer_config->layer_add[(yuvaddr)+1]<<8) |
                    (layer_config->layer_add[(yuvaddr)+3]<<16);
            }
            else 
            {
                src_color = layer_config->layer_add[(yuvaddr)+3] |(layer_config->layer_add[(yuvaddr)]<<8) |
                    (layer_config->layer_add[(yuvaddr)+2]<<16);
            }
        }
        //even pixel
        else 
        {
            yuvaddr = (2*layer_pos.x) + (layer_pos.y*layer_config->pitch*num_bytes);

            if (layer_config->swap) 
            {
                src_color = layer_config->layer_add[yuvaddr] | (layer_config->layer_add[yuvaddr+1]<<8) |
                    (layer_config->layer_add[yuvaddr+3]<<16);
            }
            else 
            {
                src_color = layer_config->layer_add[yuvaddr+1] | (layer_config->layer_add[yuvaddr]<<8) |
                    (layer_config->layer_add[yuvaddr+2]<<16);
            }  
        }
    }
    /*end fpga code*/

    //store the index color for later source key checking
    index_color = src_color;

    if (layer_config->clrdpt==BPP8) 
    { //lookup palette
        src_color = roi_config->palette[src_color];
        src = lcd_int2color(&src_color, RGB565, 0);
    }
    else if (layer_config->clrdpt==YUYV422) 
    {
        //YUYV swap handled at input_hex

        //convert to RGB
        src_color = YUYV422_to_RGB888(src_color);
        //convert to struct format for use
        src = lcd_int2color(&src_color, RGB888, 0);
    }
    else //translate 32bit color value into struct color
    {
        src = lcd_int2color(&src_color, layer_config->clrdpt, layer_config->swap);
    }

    // make its alpha channel = 0xff if not ARGB and not PARG 
   if ((layer_config->clrdpt!=ARGB8888) && (layer_config->clrdpt!=PARGB8888)
	   && (layer_config->clrdpt!=ARGB6666) && (layer_config->clrdpt!=PARGB6666) )
        src.alpha = 0xff;

    //check if this pixel hits source key
    src_key = layer_config->skey;
    src.skey_hit = 0;
    src.dkey_hit = 1;   //always assume there is hit unless otherwise

    if (layer_config->skey_en) 
    {
        switch (layer_config->clrdpt) 
        {
        case BPP8:  
            src.skey_hit = (index_color&0xff)   == (src_key&0xff);
            break;
        case YUYV422: 
            src.skey_hit = (index_color&0xffffff)   == (src_key&0xffffff);
            break;
         case RGB565: 
            src.skey_hit = (src_color&0xffff)   == (src_key&0xffff);
            break;
        case ARGB8888:  
        case PARGB8888: 
            src.skey_hit = src_color            ==  src_key;
            break;
	case ARGB6666:
	case PARGB6666:
        case RGB888: 
            src.skey_hit = (src_color&0xffffff) == (src_key&0xffffff);
            break;
        }
    }

    //note dkey_hit only affects the next layer, not this layer
    if (layer_config->dkey_en) 
    {
        src.dkey_hit = 0;  

        switch (layer_config->clrdpt) 
        {
        case BPP8:  
            src.dkey_hit = (index_color&0xff)   == (src_key&0xff);
            break;
        case YUYV422: 
            src.dkey_hit = (index_color&0xffffff)   == (src_key&0xffffff);
            break;
        case RGB565: 
            src.dkey_hit = (src_color&0xffff)   == (src_key&0xffff);
            break;
        case ARGB8888:  
        case PARGB8888: 
            src.dkey_hit = src_color            ==  src_key;
            break;
	case ARGB6666:
	case PARGB6666:
        case RGB888: 
            src.dkey_hit = (src_color&0xffffff) == (src_key&0xffffff);
            break;
        }
    }
    return(src);
}   

lcd_vec2 lcd_calc_pixel_position(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config, lcd_vec2 curr_pos)
{
    // ------------------------------------------------------------------------------
    // layer x,y position calculation
    // ------------------------------------------------------------------------------
    lcd_vec2 layer_local_pos;
    int layer_xpos_pre;
    int layer_xpos_post;
    int layer_ypos_pre;
    int layer_ypos_post;
    int layer_prephy_xpos, layer_prephy_ypos;
    int layer_prephy_xpos_wrap, layer_prephy_ypos_wrap;
    lcd_vec2 layer_pos;

    layer_local_pos.x = curr_pos.x - layer_config->ofs.x; 
    layer_local_pos.y = curr_pos.y - layer_config->ofs.y; 

    // --------------------------------------------------------------------------
    //   000 :  no rotation
    //   001 :  90 degree counterclockwise rotation
    //   010 : 180 degree counterclockwise rotation
    //   011 : 270 degree counterclockwise rotation
    //   100 : horizontal flip +  no rotation
    //   101 : horizontal flip +  90 degree counterclockwise rotation
    //   110 : horizontal flip + 180 degree counterclockwise rotation
    //   111 : horizontal flip + 270 degree counterclockwise rotation
    switch(layer_config->rotate) 
    {
    case 0: 
    case 6: 
        layer_xpos_pre = layer_local_pos.x;
        break;
    case 3: 
    case 5: 
        layer_xpos_pre = layer_local_pos.y;
        break;
    case 1: 
    case 2: 
    case 4: 
    case 7: 
        layer_xpos_pre = layer_config->size.x - 1;
        break;
    }
    switch(layer_config->rotate) 
    {
    case 0: 
    case 3: 
    case 5: 
    case 6: 
        layer_xpos_post = 0;
        break;
    case 1: 
    case 7: 
        layer_xpos_post = layer_local_pos.y;
        break;
    case 2: 
    case 4: 
        layer_xpos_post = layer_local_pos.x;
        break;
    }
    switch(layer_config->rotate) 
    {
    case 2: 
    case 3:
    case 6: 
    case 7: 
        layer_ypos_pre = layer_config->size.y - 1;
        break;
    case 1: 
    case 5: 
        layer_ypos_pre = layer_local_pos.x;
        break; 
    case 0: 
    case 4: 
        layer_ypos_pre = layer_local_pos.y;
        break;
    }
    switch(layer_config->rotate) 
    {
    case 0: 
    case 1: 
    case 4: 
    case 5: 
        layer_ypos_post = 0;
        break;
    case 2: 
    case 6: 
        layer_ypos_post = layer_local_pos.y;
        break;
    case 3: 
    case 7: 
        layer_ypos_post = layer_local_pos.x;
        break;
    }

    layer_prephy_xpos = layer_xpos_pre - layer_xpos_post +
        ((layer_config->scrl_en) ? layer_config->scroll.x : 0);
    layer_prephy_ypos = layer_ypos_pre - layer_ypos_post +
        ((layer_config->scrl_en) ? layer_config->scroll.y : 0);
    layer_prephy_xpos_wrap = layer_prephy_xpos - layer_config->size.x;
    layer_prephy_ypos_wrap = layer_prephy_ypos - layer_config->size.y;

    if (layer_config->scrl_en) 
    {
        layer_pos.x = (layer_prephy_xpos_wrap < 0) ? layer_prephy_xpos 
            : layer_prephy_xpos_wrap;
        layer_pos.y = (layer_prephy_ypos_wrap < 0) ? layer_prephy_ypos 
            : layer_prephy_ypos_wrap;
    } 
    else 
    {
        layer_pos.x = layer_prephy_xpos;
        layer_pos.y = layer_prephy_ypos;
    }

    layer_pos.x = layer_pos.x + layer_config->mem_ofs.x;
    layer_pos.y = layer_pos.y + layer_config->mem_ofs.y;

    return layer_pos;
}

//exact replica of hardware RTL logic
int lcd_find_hitten_layer_hardware(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config, lcd_vec2 curr_pos)
{
    int l0win_local_xpos, l0win_local_ypos;
    int l1win_local_xpos, l1win_local_ypos;
    int l2win_local_xpos, l2win_local_ypos;
    int l3win_local_xpos, l3win_local_ypos;
    int l4win_local_xpos, l4win_local_ypos;
    int l5win_local_xpos, l5win_local_ypos;

    int l0win_col_hit, l0win_row_hit;
    int l1win_col_hit, l1win_row_hit;
    int l2win_col_hit, l2win_row_hit;
    int l3win_col_hit, l3win_row_hit;
    int l4win_col_hit, l4win_row_hit;
    int l5win_col_hit, l5win_row_hit;

    int l0win_rotate, l1win_rotate, l2win_rotate, l3win_rotate, l4win_rotate, l5win_rotate;

    int l0pos_hit, l1pos_hit, l2pos_hit, l3pos_hit, l4pos_hit, l5pos_hit;
    int l1_not_cover, l2_not_cover, l3_not_cover, l4_not_cover, l5_not_cover;

    int l0win_en, l1win_en, l2win_en, l3win_en, l4win_en, l5win_en;

    int l0win_hit, l1win_hit, l2win_hit, l3win_hit, l4win_hit, l5win_hit;

    int hitten_layers = 0;

    l0win_en = (roi_config->layer_en >> (LAYER_NUM-1)) &0x1;
    l1win_en = (roi_config->layer_en >> (LAYER_NUM-2)) &0x1;
    l2win_en = (roi_config->layer_en >> (LAYER_NUM-3)) &0x1;
    l3win_en = (roi_config->layer_en >> (LAYER_NUM-4)) &0x1;
    l4win_en = (roi_config->layer_en >> (LAYER_NUM-5)) &0x1;
    l5win_en = roi_config->layer_en & 0x1;

    l0win_rotate = layer_config[0].rotate % 2;
    l1win_rotate = layer_config[1].rotate % 2;
    l2win_rotate = layer_config[2].rotate % 2;
    l3win_rotate = layer_config[3].rotate % 2;
    l4win_rotate = layer_config[4].rotate % 2;
    l5win_rotate = layer_config[5].rotate % 2;

    l0win_local_xpos = (int)curr_pos.x - (int)layer_config[0].ofs.x;
    l0win_local_ypos = (int)curr_pos.y - (int)layer_config[0].ofs.y;
    l1win_local_xpos = (int)curr_pos.x - (int)layer_config[1].ofs.x;
    l1win_local_ypos = (int)curr_pos.y - (int)layer_config[1].ofs.y;
    l2win_local_xpos = (int)curr_pos.x - (int)layer_config[2].ofs.x;
    l2win_local_ypos = (int)curr_pos.y - (int)layer_config[2].ofs.y;
    l3win_local_xpos = (int)curr_pos.x - (int)layer_config[3].ofs.x;
    l3win_local_ypos = (int)curr_pos.y - (int)layer_config[3].ofs.y;
    l4win_local_xpos = (int)curr_pos.x - (int)layer_config[4].ofs.x;
    l4win_local_ypos = (int)curr_pos.y - (int)layer_config[4].ofs.y;
    l5win_local_xpos = (int)curr_pos.x - (int)layer_config[5].ofs.x;
    l5win_local_ypos = (int)curr_pos.y - (int)layer_config[5].ofs.y;

    l0win_col_hit = (l0win_local_xpos >= 0) && 
        (l0win_local_xpos < (l0win_rotate ? layer_config[0].size.y : layer_config[0].size.x));

    l0win_row_hit = (l0win_local_ypos >= 0) && 
        (l0win_local_ypos < (l0win_rotate ? layer_config[0].size.x : layer_config[0].size.y));

    l1win_col_hit = (l1win_local_xpos >= 0) && 
        (l1win_local_xpos < (l1win_rotate ? layer_config[1].size.y : layer_config[1].size.x));

    l1win_row_hit = (l1win_local_ypos >= 0) && 
        (l1win_local_ypos < (l1win_rotate ? layer_config[1].size.x : layer_config[1].size.y));  

    l2win_col_hit = (l2win_local_xpos >= 0) && 
        (l2win_local_xpos < (l2win_rotate ? layer_config[2].size.y : layer_config[2].size.x));

    l2win_row_hit = (l2win_local_ypos >= 0) && 
        (l2win_local_ypos < (l2win_rotate ? layer_config[2].size.x : layer_config[2].size.y));   

    l3win_col_hit = (l3win_local_xpos >= 0) && 
        (l3win_local_xpos < (l3win_rotate ? layer_config[3].size.y : layer_config[3].size.x));

    l3win_row_hit = (l3win_local_ypos >= 0) && 
        (l3win_local_ypos < (l3win_rotate ? layer_config[3].size.x : layer_config[3].size.y));

    l4win_col_hit = (l4win_local_xpos >= 0) && 
        (l4win_local_xpos < (l4win_rotate ? layer_config[4].size.y : layer_config[4].size.x));
    
    l4win_row_hit = (l4win_local_ypos >= 0) && 
        (l4win_local_ypos < (l4win_rotate ? layer_config[4].size.x : layer_config[4].size.y));

    l5win_col_hit = (l5win_local_xpos >= 0) && 
        (l5win_local_xpos < (l5win_rotate ? layer_config[5].size.y : layer_config[5].size.x));
    
    l5win_row_hit = (l5win_local_ypos >= 0) && 
        (l5win_local_ypos < (l5win_rotate ? layer_config[5].size.x : layer_config[5].size.y));

    l0pos_hit = l0win_en & l0win_col_hit & l0win_row_hit;
    l1pos_hit = l1win_en & l1win_col_hit & l1win_row_hit;
    l2pos_hit = l2win_en & l2win_col_hit & l2win_row_hit;
    l3pos_hit = l3win_en & l3win_col_hit & l3win_row_hit;
    l4pos_hit = l4win_en & l4win_col_hit & l4win_row_hit;
    l5pos_hit = l5win_en & l5win_col_hit & l5win_row_hit;

    l1_not_cover = (l1pos_hit==0)||(layer_config[1].skey_en==1)||(layer_config[1].opaen==1)||
                  ((l0pos_hit==1)&&(layer_config[0].dkey_en==1));

    l2_not_cover = (l2pos_hit==0)||(layer_config[2].skey_en==1)||(layer_config[2].opaen==1)||
                  ((l1pos_hit==1)&&(layer_config[1].dkey_en==1)) ||
                  ((l1pos_hit==0)&&(l0pos_hit==1)&&(layer_config[0].dkey_en==1));

    l3_not_cover = (l3pos_hit==0)||(layer_config[3].skey_en==1)||(layer_config[3].opaen==1)||
                  ((l2pos_hit==1)&&(layer_config[2].dkey_en==1)) ||
                  ((l2pos_hit==0)&&(l1pos_hit==1)&&(layer_config[1].dkey_en==1)) ||
                  ((l2pos_hit==0)&&(l1pos_hit==0)&&(l0pos_hit==1)&&(layer_config[0].dkey_en==1));

    l4_not_cover = (l4pos_hit==0)||(layer_config[4].skey_en==1)||(layer_config[4].opaen==1)||
                  ((l3pos_hit==1)&&(layer_config[3].dkey_en==1)) ||
                  ((l3pos_hit==0)&&(l2pos_hit==1)&&(layer_config[2].dkey_en==1)) ||
                  ((l3pos_hit==0)&&(l2pos_hit==0)&&(l1pos_hit==1)&&(layer_config[1].dkey_en==1)) ||
                  ((l3pos_hit==0)&&(l2pos_hit==0)&&(l1pos_hit==0)&&(l0pos_hit==1)&&(layer_config[0].dkey_en==1));
    
    l5_not_cover = (l5pos_hit==0)||(layer_config[5].skey_en==1)||(layer_config[5].opaen==1)||
                  ((l4pos_hit==1)&&(layer_config[4].dkey_en==1)) ||
                  ((l4pos_hit==0)&&(l3pos_hit==1)&&(layer_config[3].dkey_en==1)) ||
                  ((l4pos_hit==0)&&(l3pos_hit==0)&&(l2pos_hit==1)&&(layer_config[2].dkey_en==1)) ||
                  ((l4pos_hit==0)&&(l3pos_hit==0)&&(l2pos_hit==0)&&(l1pos_hit==1)&&(layer_config[1].dkey_en==1)) ||
                  ((l4pos_hit==0)&&(l3pos_hit==0)&&(l2pos_hit==0)&&(l1pos_hit==0)&&(l0pos_hit==1)&&(layer_config[0].dkey_en==1));

    l0win_hit = l0win_en && l0win_row_hit && l0win_col_hit &&
                l1_not_cover && l2_not_cover && l3_not_cover && l4_not_cover && l5_not_cover;
    
    l1win_hit = l1win_en && l1win_row_hit && l1win_col_hit &&
                l2_not_cover && l3_not_cover && l4_not_cover && l5_not_cover;
    
    l2win_hit = l2win_en && l2win_row_hit && l2win_col_hit &&
                l3_not_cover && l4_not_cover && l5_not_cover;
    
    l3win_hit = l3win_en && l3win_row_hit && l3win_col_hit &&
                l4_not_cover && l5_not_cover;
    
    l4win_hit = l4win_en && l4win_row_hit && l4win_col_hit &&
                l5_not_cover;
    
    l5win_hit = l5win_en && l5win_row_hit && l5win_col_hit;
    
    hitten_layers = (l0win_hit<<(LAYER_NUM-1)) | (l1win_hit<<(LAYER_NUM-2))|
                    (l2win_hit<<(LAYER_NUM-3)) | (l3win_hit<<(LAYER_NUM-4))|
                    (l4win_hit<<(LAYER_NUM-5)) | (l5win_hit<<(LAYER_NUM-6));

    return(hitten_layers);
}

lcd_color lcd_process_pixel(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config, lcd_vec2 curr_pos)
{
    int hitten_layers;
    int i;
    lcd_vec2 layer_pos;
    lcd_color src_color;
    lcd_color dst_color;
    int r, g, b;

    int dkey_hit;

    //dst_color changed to include alpha value of bgclr as well
    dst_color = lcd_int2color(&(roi_config->bgclr), PARGB8888, 0);

    //background of roi has no dkey, so always dkey_hit
    dkey_hit = 1;

    hitten_layers = lcd_find_hitten_layer_hardware(layer_config, roi_config, curr_pos);

    for (i=0;i<LAYER_NUM;i++) 
    {
        if (hitten_layers & (0x1<<(LAYER_NUM-1)) ) 
        {    
            layer_pos = lcd_calc_pixel_position(&layer_config[i], roi_config, curr_pos);
            src_color = lcd_get_pixel_value(&layer_config[i], roi_config, layer_pos);

            //check for linear gamma enable for this layer
            if (layer_config[i].lgamma_en) 
            {
                //if enabled, then modify this source pixel
                src_color = lcd_lgamma_correct(src_color, roi_config);
            }

            //check for dithering in this layer
            if (layer_config[i].dither_en) 
            {
                //if enabled, then modify this source pixel
                src_color = lcd_dithering(src_color, roi_config);
            }
            if (layer_config[i].skey_en) 
            {
                if (!src_color.skey_hit) 
                {
                    if (layer_config[i].opaen)
                    {
                        lcd_alpha_blend(src_color, &dst_color, &layer_config[i]);
                    }
                    else
                        dst_color = src_color;
                }
            }
            else 
            {
                if (dkey_hit) 
                {
                    if (layer_config[i].opaen)
                    {
                        lcd_alpha_blend(src_color, &dst_color, &layer_config[i]);
                    }
                    else
                        dst_color = src_color;
                }
            }
            //if this layer has dkey then set for next layer
            if (layer_config[i].dkey_en) 
            {
                dkey_hit = src_color.dkey_hit;
            }
            else 
            {
                dkey_hit = 1;
            }  
        }

        hitten_layers = hitten_layers<<1;
    }

    //lcd_gamma_correct(&dst_color, roi_config);
    r = dst_color.r;
    g = dst_color.g;
    b = dst_color.b;
    return(dst_color);
}

typedef struct
{
    int x;
    int y;
    int width;
    int height;
} RECTANGLE;

static void _rectangle_and(RECTANGLE* pRect1, RECTANGLE* pRect2, RECTANGLE* pRectResult)
{
    int left, right, top, bottom, width, height;
    if ((pRect1->width == 0) || (pRect1->height == 0) || (pRect2->width == 0) || (pRect2->height == 0))
    {
        memset(pRectResult, 0, sizeof(RECTANGLE));
        return;
    }
    if (pRect1->x < pRect2->x)
        left = pRect2->x;
    else
        left = pRect1->x;
    if ((pRect1->x + pRect1->width) < (pRect2->x + pRect2->width))
        right = pRect1->x + pRect1->width;
    else
        right = pRect2->x + pRect2->width;
    if (left < right)
    {
        width = right - left;
    }
    else
        width = 0;
    if (pRect1->y < pRect2->y)
        top = pRect2->y;
    else
        top = pRect1->y;
    if ((pRect1->y + pRect1->height) < (pRect2->y + pRect2->height))
        bottom = pRect1->y + pRect1->height;
    else
        bottom = pRect2->y + pRect2->height;
    if (top < bottom)
    {
        height = bottom - top;
    }
    else
        height = 0;
    if ((width == 0) || (height == 0))
    {
        pRectResult->x = pRectResult->y = pRectResult->width = pRectResult->height = 0;
    }
    else
    {
        pRectResult->x = left;
        pRectResult->y = top;
        pRectResult->width = width;
        pRectResult->height = height;
    }
}

void _modis_lcd_update(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config)
{
#if defined(LCD_C_MODEL_SINGLE_LAYER_OPTIMIZATION)
    #define TWO(c)       (0x1u << (c))
    #define MASK(c)      (((unsigned int)(-1)) / (TWO(TWO(c)) + 1u))
    #define COUNT(x,c) ((x) & MASK(c)) + (((x) >> (TWO(c))) & MASK(c))
    unsigned int layer_en = roi_config->layer_en;
    layer_en = COUNT(layer_en, 0) ;
    layer_en = COUNT(layer_en, 1) ;
    layer_en = COUNT(layer_en, 2) ;
    layer_en = COUNT(layer_en, 3) ;
    layer_en = COUNT(layer_en, 4) ;
    if (layer_en == 1)
    {
        unsigned int layer_id = 0x20/roi_config->layer_en - 1;
        unsigned int x,y;
        RECTANGLE rcROI, rcLayer, rcCopy;
        if ((layer_config[layer_id].opaen == 0) &&
            (layer_config[layer_id].rotate == 0) &&
            (layer_config[layer_id].skey_en == 0) &&
            ((roi_config->w2m_fmt == W2M_PARGB8888_CONST_A) || (roi_config->w2m_fmt == W2M_PARGB8888_PER_A)))
        {
            // Copy the layer data directly. May need color format conversion if needed.
            rcROI.x = roi_config->ofs.x;
            rcROI.y = roi_config->ofs.y;
            rcROI.width = roi_config->size.x;
            rcROI.height = roi_config->size.y;
            rcLayer.x = layer_config[layer_id].ofs.x;
            rcLayer.y = layer_config[layer_id].ofs.y;
            rcLayer.width = layer_config[layer_id].size.x;
            rcLayer.height = layer_config[layer_id].size.y;
            _rectangle_and(&rcROI, &rcLayer, &rcCopy);
            if (layer_config[layer_id].clrdpt == ARGB8888 || layer_config[layer_id].clrdpt == PARGB8888)
            {
                for (y=0; y<rcCopy.height; y++)
                {
                    memcpy ((void*)((unsigned int)(roi_config->w2m_add)+roi_config->pitch*4*(y+roi_config->w2m_ofs.y)+roi_config->w2m_ofs.x*4), 
                            (void*)((unsigned int)(layer_config[layer_id].layer_add)+(y+rcCopy.y-rcLayer.y+layer_config[layer_id].mem_ofs.y)*layer_config[layer_id].pitch*4+(rcCopy.x - rcLayer.x + layer_config[layer_id].mem_ofs.x)*4),
                            rcCopy.width*4);
                }
                return;
            }
            else if (layer_config[layer_id].clrdpt == RGB565)
            {
                unsigned short* pRGB565;
                unsigned int* pARGB8888;
                unsigned short RGB565_value;
                unsigned char* pByte;
                unsigned int temp;
                //lcd_process_roi(layer_config, roi_config);
                pRGB565 = (unsigned short*) ((unsigned int)(layer_config[layer_id].layer_add)+(rcCopy.y-rcLayer.y+layer_config[layer_id].mem_ofs.y)*layer_config[layer_id].pitch*2+(rcCopy.x-rcLayer.x+layer_config[layer_id].mem_ofs.x)*2);
                pARGB8888 = (unsigned int*) ((unsigned int)(roi_config->w2m_add)+roi_config->pitch*4*(roi_config->w2m_ofs.y)+roi_config->w2m_ofs.x*4);
                for (y=0; y<rcCopy.height; y++)
                {
                    for (x=0; x<rcCopy.width; x++)
                    {
                        RGB565_value = pRGB565[y*layer_config[layer_id].pitch+x];
                        pByte = (unsigned char*) (&(pARGB8888[y*roi_config->pitch+x]));
                        temp = (RGB565_value)&0x1f;                     
                        *(pByte++) = (temp<<3) | ((temp>>2)&0x7);    
                        temp = (RGB565_value>>5)&0x3f;
                        *(pByte++) = (temp<<2) | ((temp>>4)&0x3);    
                        temp = (RGB565_value>>11)&0x1f;                 
                        *(pByte++) = (temp<<3) | ((temp>>2)&0x7);
                        *(pByte++) = 0xFF;
                    }
                }
                return;
            }
        }
    }
#endif
    lcd_process_roi(layer_config, roi_config);
}
//processing pixels in ROI
void lcd_process_roi(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config)
{
    lcd_vec2 curr_pos;
    lcd_color overlaid_pixel;
    int pixel_multiplier;
    unsigned char *pixel_add;

    // initial all static variable, add by Neil Xu 2008-11-4
    initial_write_to_LCM = 1;
    initial_dithering    = 1;

    for (curr_pos.y = roi_config->ofs.y; curr_pos.y < roi_config->ofs.y + roi_config->size.y; curr_pos.y++)  
    {
        for (curr_pos.x = roi_config->ofs.x; curr_pos.x < roi_config->ofs.x + roi_config->size.x; curr_pos.x++) 
        { 
            //get the pixel data for current pixel
            overlaid_pixel = lcd_process_pixel(layer_config, roi_config, curr_pos);

            //determine how many lines to write for each pixel
            if (roi_config->w2m_fmt == W2M_RGB565) 
            {
                pixel_multiplier = 2;
            }
            else if (roi_config->w2m_fmt == W2M_RGB888) 
            {
                pixel_multiplier = 3;
            }
	    else if ((roi_config->w2m_fmt == W2M_PARGB6666_CONST_A) || (roi_config->w2m_fmt == W2M_PARGB6666_PER_A))
            {
                pixel_multiplier = 3;
            }
            else 
            {
                pixel_multiplier = 4;
            }
            //for FPGA C model use only
            if (roi_config->w2m) 
            {
                //calculate addr of pixel
                pixel_add = roi_config->w2m_add + (((roi_config->w2m_ofs.y + (curr_pos.y-roi_config->ofs.y)) * roi_config->pitch
                    + roi_config->w2m_ofs.x + (curr_pos.x-roi_config->ofs.x))*pixel_multiplier);

                //write this pixel to this address
                lcd_write_to_memory_mem(overlaid_pixel, roi_config, pixel_add);
            }
        }
    }
}
