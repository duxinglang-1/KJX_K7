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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef LCD_C_MODEL_H
#define LCD_C_MODEL_H

#include "kal_general_types.h"

//number of layers
#define LAYER_NUM 6

//layer_num changed from 6 to 4

//number of roi registers to read in config file          
#define ROI_CONFIG_NUM 34

//number of layer fields to read in config file
#define LAYER_CONFIG_NUM 8

//number of entries in gamma table
#define GAMMA_NUM 256

//number of entries in palette table
#define PALETTE_NUM 256

//number of commands in command table
#define COMMAND_NUM 64

//constant alpha value for 32bpp layers
#define SRC_ALPHA 0x40

//Base Address
#define LCD_BASE 0x90000000

//layer color depth
#define BPP8    0
#define RGB565		1
#define YUYV422 2
#define RGB888		3
#define ARGB8888    4
#define PARGB8888   5
#define ARGB6666	6
#define PARGB6666	7

//GMC Port Burst length
#define BURST_1    0
#define BURST_4_2  1
#define BURST_4    1
#define BURST_8    2
#define BURST_16   3

//write to memory color depth
#define W2M_RGB565 0
#define W2M_RGB888 1
#define W2M_PARGB8888_CONST_A 2
#define W2M_PARGB8888_PER_A 3 
#define W2M_PARGB6666_CONST_A 4 //constant alpha
#define W2M_PARGB6666_PER_A 5 //alpha value determined by blending equation

//write to LCM rgb sequence
#define BGR_SEQ 1
#define RGB_SEQ 0

//write to LCM significant sequence
#define MSB_FIRST 0
#define LSB_FIRST 1

//write to LCM padding position
#define PADDING_LSB 0
#define PADDING_MSB 1

//write to LCM interface bit as defined in ROI control register
#define LCM8B 0
#define LCM9B 2
#define LCM16B 1
#define LCM18B 3

//output interface size as defined in Parallel Interface Configuration register
#define PCNF_8B 0
#define PCNF_9B 1
#define PCNF_16B 2
#define PCNF_18B 3

//write to LCM format
/*
#define RGB332 0
#define RGB444 1
#define RGB565 2
#define RGB666 3
#define RGB888 4
*/

#define GAMMA0 0
#define GAMMA1 1
#define GAMMA2 2


//Number of segments for piece-wise gamma correction
#define LGAMMA_SEGNUM 8

#define DIV255(x) (unsigned char)( (x + (x>>8)) >>8 )
#define SAT(x) (x > 255) ? 255 : \
               (x < 0  ) ? 0   : (unsigned char)x
               	
typedef struct                      
{                                   
   kal_uint32  lcd_sta     ;              
   kal_uint32  lcd_inten   ;         
   kal_uint32  lcd_intsta  ;         
   kal_uint32  lcd_start   ;         
   kal_uint32  lcd_rstb    ;        
   kal_uint32  lcd_scnf    ;         
   kal_uint32  lcd_pcnf0   ;         
   kal_uint32  lcd_pcnf1   ;         
   kal_uint32  lcd_pcnf2   ;         
   kal_uint32  lcd_tecon   ;         
   kal_uint32  lcd_misc    ;         
   kal_uint32  lcd_gmccon  ;         
   kal_uint32  lcd_wroi_w2madd ;     
   kal_uint32  lcd_w2m_pitch   ;     
   kal_uint32  lcd_wroi_w2mofs ;     
   kal_uint32  lcd_wroi_w2mcon ;     
   kal_uint32  lcd_pal_add     ;     
   kal_uint32  lcd_wroicon     ;     
   kal_uint32  lcd_wroiofs     ;     
   kal_uint32  lcd_wroicadd    ;     
   kal_uint32  lcd_wroidadd    ;     
   kal_uint32  lcd_wroisize    ;     
   kal_uint32  lcd_wroi_hwref  ;     
   kal_uint32  lcd_wroi_bgclr  ;     
   kal_uint32  lcd_l0wincon    ;     
   kal_uint32  lcd_l0winkey    ;     
   kal_uint32  lcd_l0winofs    ;     
   kal_uint32  lcd_l0winadd    ;     
   kal_uint32  lcd_l0winsize   ;     
   kal_uint32  lcd_l0winscrl   ;     
   kal_uint32  lcd_l0winmofs   ;     
   kal_uint32  lcd_l0winpitch  ;     
   kal_uint32  lcd_l1wincon    ;     
   kal_uint32  lcd_l1winkey    ;     
   kal_uint32  lcd_l1winofs    ;     
   kal_uint32  lcd_l1winadd    ;     
   kal_uint32  lcd_l1winsize   ;     
   kal_uint32  lcd_l1winscrl   ;     
   kal_uint32  lcd_l1winmofs   ;     
   kal_uint32  lcd_l1winpitch  ;     
   kal_uint32  lcd_l2wincon    ;     
   kal_uint32  lcd_l2winkey    ;     
   kal_uint32  lcd_l2winofs    ;     
   kal_uint32  lcd_l2winadd    ;     
   kal_uint32  lcd_l2winsize   ;     
   kal_uint32  lcd_l2winscrl   ;     
   kal_uint32  lcd_l2winmofs   ;     
   kal_uint32  lcd_l2winpitch  ;     
   kal_uint32  lcd_l3wincon    ;     
   kal_uint32  lcd_l3winkey    ;     
   kal_uint32  lcd_l3winofs    ;     
   kal_uint32  lcd_l3winadd    ;     
   kal_uint32  lcd_l3winsize   ;     
   kal_uint32  lcd_l3winscrl   ;     
   kal_uint32  lcd_l3winmofs   ;     
   kal_uint32  lcd_l3winpitch  ;     
   kal_uint32  lcd_l4wincon    ;     
   kal_uint32  lcd_l4winkey    ;     
   kal_uint32  lcd_l4winofs    ;     
   kal_uint32  lcd_l4winadd    ;     
   kal_uint32  lcd_l4winsize   ;     
   kal_uint32  lcd_l4winscrl   ;     
   kal_uint32  lcd_l4winmofs   ;     
   kal_uint32  lcd_l4winpitch  ;     
   kal_uint32  lcd_l5wincon    ;     
   kal_uint32  lcd_l5winkey    ;     
   kal_uint32  lcd_l5winofs    ;     
   kal_uint32  lcd_l5winadd    ;     
   kal_uint32  lcd_l5winsize   ;     
   kal_uint32  lcd_l5winscrl   ;     
   kal_uint32  lcd_l5winmofs   ;     
   kal_uint32  lcd_l5winpitch  ;     
   kal_uint32  lcd_dither_con  ;     
   kal_uint32  lcd_lgma_con    ;     
   kal_uint32  lcd_lgma_ofs0   ;     
   kal_uint32  lcd_lgma_ofs1   ;     
   kal_uint32  lcd_lgma_ofs2   ;     
   kal_uint32  lcd_lgma_ofs3   ;     
   kal_uint32  lcd_lgma_ofs4   ;     
   kal_uint32  lcd_lgma_ofs5   ;     
   kal_uint32  lcd_lgma_ofs6   ;     
   kal_uint32  lcd_lgma_ofs7   ;     
   kal_uint32  lcd_lgma_slp0   ;     
   kal_uint32  lcd_lgma_slp1   ;     
   kal_uint32  lcd_lgma_slp2   ;     
   kal_uint32  lcd_lgma_slp3   ;     
   kal_uint32  lcd_lgma_slp4   ;     
   kal_uint32  lcd_lgma_slp5   ;     
   kal_uint32  lcd_lgma_slp6   ;     
   kal_uint32  lcd_lgma_slp7   ;     
   kal_uint32  lcd_wroi_hwref_blk;   
   kal_uint32  lcd_wroi_hwref_dly;   
   kal_uint32  lcd_db_addcon   ;     
   kal_uint32  lcd_db_mcon     ;     
   kal_uint32  lcd_db_w2mcon   ;     
   kal_uint32  lcd_gamma_table[256]; 
}lcd_register_struct;               

typedef struct 
{
   unsigned int x;
   unsigned int y;
} lcd_vec2;

typedef struct  
{
   unsigned char alpha;
   unsigned char  r;
   unsigned char  g;
   unsigned char  b;
   unsigned char skey_hit;
   unsigned char  dkey_hit;
}lcd_color;

typedef struct  {
   unsigned int output[4];    //the output string
   unsigned int num_char[4];  //number of characters in each string
   unsigned int num_out;      //number of strings to output
}lcd_dbi_print_t;

typedef struct  
{                                                   
   unsigned int temp_value[ROI_CONFIG_NUM];                             
                                                                        
   unsigned int send_res_mod;                                           
                                                                        
   unsigned char *w2m_add;                                              
   unsigned char *pal_add;                                              
                                                                        
   //not used for 6236                                                  
   lcd_vec2 mwin_size;                                               
                                                                        
   lcd_vec2 w2m_ofs;                                                 
   lcd_vec2 ofs;                                                     
   lcd_vec2 size;                                                    
   unsigned int bgclr;                                                  
                                                                        
   //not used for 6236                                                  
   lcd_vec2 eis_gmv;                                                 
   unsigned int eis_col;                                                
                                                                        
   unsigned int alpha;                                                  
   unsigned int w2lcm;                                                  
   unsigned int pitch;     //pitch when writing data to memory          
   unsigned int w2m_fmt;                                                
   unsigned int max_burst;                                              
                                                                        
   //not used for 6236                                                  
   unsigned int discont;                                                
                                                                        
   unsigned int sequence;                                               
   unsigned int significant;                                            
   unsigned int padding;                                                
   unsigned int out_fmt;                                                
   unsigned int out_if;                                                 
   unsigned int w2m;                                                    
                                                                        
   unsigned int layer_en;                                               
                                                                        
   unsigned int enc;                                                    
   unsigned int com_sel;                                                
   unsigned int num_com;                                                
                                                                        
   lcd_color gamma_id;                                               
                                                                        
   unsigned char serial_gamma_id;                                       
   unsigned int serial_command_bit;                                     
   unsigned int serial_non_dbi;     //If this is set to 0 and also using
                                    //serial interface. Then out_if MUST
   unsigned int command_addr;       //be set to 8bits.                  
   unsigned int data_addr;                                              
                                                                        
   //dither control register                                            
   unsigned int db_b;                                                   
   unsigned int db_g;                                                   
   unsigned int db_r;                                                   
   unsigned int lfsr_b_seed;                                            
   unsigned int lfsr_g_seed;                                            
   unsigned int lfsr_r_seed;                                            
                                                                        
   //piece-wise linear gamma                                            
   unsigned int lgamma_mode;                                            
                                                                        
   unsigned int lgamma_offset[LGAMMA_SEGNUM];                           
   unsigned int lgamma_dec_bits[LGAMMA_SEGNUM];                         
   unsigned int lgamma_slope[LGAMMA_SEGNUM];                            
                                                                        
   unsigned int gamma[GAMMA_NUM];                                       
   unsigned int command[COMMAND_NUM];                                   
   unsigned int palette[PALETTE_NUM];                                   
}lcd_roi_config_t;                                                                      
                                                                        
typedef struct 
{                                                 
   unsigned int temp_value[LAYER_CONFIG_NUM];                           
                                                                        
   unsigned int opacity;   //called alpha in 6236                       
   unsigned int opaen;                                                  
   unsigned int clrdpt;                                                 
   unsigned int rotate;                                                 
   unsigned int skey_en;                                                
   unsigned int dkey_en;                                                
   unsigned int swap;                                                   
   unsigned int scrl_en;                                                
                                                                        
   unsigned char *layer_add;                                            
                                                                        
   //new to 6236                                                        
   unsigned int blend_mode;                                             
                                                                        
   //unused for 6236                                                    
   unsigned int hw_eis_en;                                              
   unsigned int sw_eis_en;                                              
                                                                        
   unsigned int skey;                                                   
   lcd_vec2 ofs;                                                     
   unsigned int *buf;                                                   
   lcd_vec2 size;                                                    
   lcd_vec2 scroll;                                                  
   lcd_vec2 bmp_size;                                                
                                                                        
   lcd_vec2 mem_ofs;                                                 
   unsigned int pitch;                                                  
                                                                        
   unsigned int dither_en;                                              
   unsigned int lgamma_en;                                              
   unsigned int bpp;
                                                                        
//   char pic_filename[TEMP_STR_LEN];                                     
}lcd_layer_config_t;  

void _modis_lcd_update(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config);
void lcd_process_roi(lcd_layer_config_t *layer_config, lcd_roi_config_t *roi_config);

#endif                                                                    
