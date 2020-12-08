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
 *   aac_sbr.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   AAC SBR checker
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__AAC_DECODE_SWIP__)

#include "kal_public_api.h"
#include "kal_non_specific_general_types.h"
#include "string.h"
#include "fsal.h"
#include "l1audio.h"
#include "aac_huffman_table.h"
#include "media.h"
#include "aac_drv.h"
#include "common_def.h"

#if defined(AAC_PLUS_DECODE)

#if defined(MT6252) || defined(MT6252H) || defined(MT6251)
#error Do not support AAC Plus or AAC Plus v2 on this platform
#endif

#define BITMASK(_cnt) (0xFFFFFFFF >> (32-_cnt))
#define bit_set(A, B) ((A) & (1<<(B)))

static kal_uint32 aacPlusPeekBits(aacMediaHdl *ihdl, kal_uint32 puBitCnt, kal_uint32 uBaseOffset, kal_uint8 ubCnt)
{
	kal_uint32 uResult, uFileOffset, uCurPos;

   if(ubCnt >= 24){
      ihdl->aac.sbrParseError = true;
      return 0;
   }

	uFileOffset = uBaseOffset + (puBitCnt >> 3);
	FSAL_GetCurPos(ihdl->pstFSAL, &uCurPos);
	FSAL_Seek( ihdl->pstFSAL, uFileOffset);
	FSAL_Peek_UINT(ihdl->pstFSAL, &uResult);
	FSAL_Seek( ihdl->pstFSAL, uCurPos);
	return (uResult >> (32-(puBitCnt & 0x07) - ubCnt)) & BITMASK(ubCnt);
}

static void aacPlusProgramConfigElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint32 i;
   kal_uint8  num_front_channel_elements, num_side_channel_elements
            , num_back_channel_elements, num_lfe_channel_elements
            , num_assoc_data_elements, num_valid_cc_elements, dummy, comment_field_bytes;
         /*--- PCE ---*/

   /* element_instance_tag */
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   /* object type */
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 6);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_front_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_side_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_back_channel_elements, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_lfe_channel_elements, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_assoc_data_elements, 3);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_valid_cc_elements, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 1);
   if (dummy == 1)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 3);

   for (i = 0; i < num_front_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_side_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_back_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   for (i = 0; i < num_lfe_channel_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   for (i = 0; i < num_assoc_data_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);

   for (i = 0; i < num_valid_cc_elements; i++)
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8-((*puBitCnt) & 0x07));

   FSAL_Read_Bytes( ihdl->pstFSAL, &comment_field_bytes, 1);
   FSAL_Skip_Bytes( ihdl->pstFSAL, comment_field_bytes);
   *puBitCnt += (comment_field_bytes+1) << 3;
}

static void aacPlusDataStreamElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  byte_aligned, temp;
   kal_uint16 count;
   kal_int16 i;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &byte_aligned, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
   count = (uint16)temp;

   if(count == 255){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
      count += (uint16)temp;
   }

   if(byte_aligned)
      *puBitCnt += 8-(*puBitCnt & 0x07); // byte alignment

   for(i = count; --i >= 0;){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &temp, 8);
   }
}

/* Table 4.4.32 */
static kal_uint8 aacPlusExcludedChannels(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  additional_excluded_chns, n = 0;
   do {
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &additional_excluded_chns, 7);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &additional_excluded_chns, 1);
      if(n == 255){
         ihdl->aac.sbrParseError = true;
         break;
      }
      n++;
   } while (additional_excluded_chns == 1);
   return n;
}

static void aacPlusExtensionPayload_S(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint16 count)
{
   kal_uint16 i;
   kal_uint8  extension_type, dummy;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &extension_type, 4);
   
   switch(extension_type)
   {
      case EXT_SBR_DATA:
      case EXT_SBR_DATA_CRC:
         ihdl->aac.bChanSbrFlag[ihdl->aac.sbr_chanidx] = true;
         break;
   }
   
   // Consume all
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);
   for (i = 0; i < count-1; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 8);
   }
}


/* Table 4.4.11 */
static void aacPlusFillElement(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8  tmp;
   kal_int16  count;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 4);
   count = (kal_int16)tmp;
   if(count == 15){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 8);
      count += (kal_int16)(tmp - 1);
   }

   aacPlusExtensionPayload_S(ihdl, puBitCnt, count);
}

static void aacPlusWindowGroupingInfo(aacMediaHdl *ihdl, iCS *ic)
{
    kal_uint8 i, g;
    kal_uint8 sr_index = ihdl->aac.sr_idx;
    ic->num_windows=0;

    switch(ic->window_sequence){
       case ONLY_LONG_SEQUENCE:
       case LONG_START_SEQUENCE:
       case LONG_STOP_SEQUENCE:
           ic->num_windows = 1;
           ic->num_window_groups = 1;
           ic->window_group_length[ic->num_window_groups-1] = 1;
           ic->num_swb = num_swb_1024_window[sr_index];

           for(i = 0; i < ic->num_swb; i++)
           {
              ic->sect_sfb_offset[0][i] = swb_offset_1024_window[sr_index][i];
              ic->swb_offset[i] = swb_offset_1024_window[sr_index][i];
           }
           ic->sect_sfb_offset[0][ic->num_swb] = 1024;
           ic->swb_offset[ic->num_swb] = 1024;
           break;
       case EIGHT_SHORT_SEQUENCE:
           ic->num_windows = 8;
           ic->num_window_groups = 1;
           ic->window_group_length[ic->num_window_groups-1] = 1;
           ic->num_swb = num_swb_128_window[sr_index];

           for(i = 0; i < ic->num_swb; i++)
           {
              ic->swb_offset[i] = swb_offset_128_window[sr_index][i];
           }
           ic->swb_offset[ic->num_swb] = 128;

           for(i = 0; i < ic->num_windows-1; i++)
           {
              if(bit_set(ic->scale_factor_grouping, 6-i) == 0)
              {
                 ic->num_window_groups += 1;
                 ic->window_group_length[ic->num_window_groups-1] = 1;
              }
              else
              {
                  ic->window_group_length[ic->num_window_groups-1] += 1;
              }
           }

           for(g = 0; g < ic->num_window_groups; g++)
           {
              kal_uint16 wid = 0;
              kal_uint8  sect_sfb = 0;
              kal_uint16 offset = 0;

              for(i = 0; i < ic->num_swb; i++)
              {
                  if(i+1 == ic->num_swb)
                  {
                     wid = 128 - swb_offset_128_window[sr_index][i];
                  }
                  else
                  {
                      wid = swb_offset_128_window[sr_index][i+1] - swb_offset_128_window[sr_index][i];
                  }
                  wid *= ic->window_group_length[g];
                  ic->sect_sfb_offset[g][sect_sfb++] = offset;
                  offset += wid;
              }
              ic->sect_sfb_offset[g][sect_sfb] = offset;
           }
           break;
       default:
           ihdl->aac.sbrParseError = true;
    }
}

static void aacPlusIcsInfo(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 ics_reserved_bit;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics_reserved_bit, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->window_sequence, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->window_shape, 1);

   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->max_sfb, 4);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->scale_factor_grouping, 7);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->max_sfb, 6);
    }

   /* get the grouping information */
   aacPlusWindowGroupingInfo(ihdl, ics);

   if(ics->max_sfb > ics->num_swb){
      ihdl->aac.sbrParseError = true;
      return;
   }

   if(ics->window_sequence != EIGHT_SHORT_SEQUENCE){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->predictor_data_present, 1);
      if(ics->predictor_data_present){
         /* Not support */
         ihdl->aac.sbrParseError = true;
      }
   }
}

static void aacPlusSectionData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 g, sect_esc_val, sect_bits;

   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE)
      sect_bits = 3;
   else
      sect_bits = 5;
   sect_esc_val = (1<<sect_bits) - 1;

   for(g = 0; g < ics->num_window_groups; g++){
      kal_uint8 k = 0;
      kal_uint8 i = 0;

      while(k < ics->max_sfb){
         kal_uint8  sfb;
         kal_uint8  sect_len_incr;
         kal_uint16 sect_len = 0;
         kal_uint8  sect_cb_bits = 4;

         if(i >= 120) { /* 8*15 */
            ihdl->aac.sbrParseError = true;
            break;
         }

         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->sect_cb[g][i], sect_cb_bits);

         if(ics->sect_cb[g][i] == NOISE_HCB)
            ics->noise_used = 1;
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &sect_len_incr, sect_bits);

         while(sect_len_incr == sect_esc_val)
         {
            sect_len += sect_len_incr;
            if(FSAL_OK != FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &sect_len_incr, sect_bits))
            {
               ihdl->aac.sbrParseError = true;
               break;        	
            }            
         }

         sect_len += sect_len_incr;

         ics->sect_start[g][i] = k;
         ics->sect_end[g][i] = k + sect_len;

         if((k + sect_len >= 120) || (i >= 120)){ /* 8*15 */
            ihdl->aac.sbrParseError = true;
            break;
         }

         for(sfb = k; sfb < k + sect_len; sfb++)
            ics->sfb_cb[g][sfb] = ics->sect_cb[g][i];

         k += sect_len;
         i++;
      }
      ics->num_sec[g] = i;
   }
}

static kal_int8 aacPlusHuffmanScaleFactor(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint16 offset = 0;
   kal_uint8  b;
   while(hcb_sf[offset][1])
   {
   	  if(FSAL_OK != FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1))
      {
         ihdl->aac.sbrParseError = true;
         break;
      }
      offset += hcb_sf[offset][b];
      if(offset > 240)
      {
         ihdl->aac.sbrParseError = true;
         break;
      }
   }
   return hcb_sf[offset][0];
}

static void aacPlusDecodeScaleFactors(aacMediaHdl *ihdl, iCS *ic, kal_uint32 *puBitCnt)
{
   kal_uint8 g, sfb;
   kal_int16 t;
   kal_int8  noise_pcm_flag = 1;
   kal_int16 SF = ic->global_gain;
   kal_int16 position = 0;
   kal_int16 noise_entropy = ic->global_gain - 90;

   for(g = 0; g < ic->num_window_groups; g++){
      for(sfb = 0; sfb < ic->max_sfb; sfb++){
         if (ic->sfb_cb[g][sfb] == ZERO_HCB){ //zero book
            ic->scale_factors[g][sfb] = 0;
         }
         else if ((ic->sfb_cb[g][sfb] == INTENSITY_HCB) || (ic->sfb_cb[g][sfb] == INTENSITY_HCB2)){ //intensity books
         	   //decode intensity position
         	   t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
             position += (t - 60);
             ic->scale_factors[g][sfb] = position;
         }
         else if (ic->sfb_cb[g][sfb] == NOISE_HCB ){ //noise books
         	   //decode noise energy
             if(noise_pcm_flag){
                kal_uint8 tmp1, tmp2;
                noise_pcm_flag = 0;
                FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp1, 8);
                FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp2, 1);
                t = (uint16)(tmp2 << 8) | (uint16)tmp1;
                t = t - 256;
             }else{
                 t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
                 t -= 60;
              }
             noise_entropy += t;
             ic->scale_factors[g][sfb] = noise_entropy;
         }
         else{ //spectral books ; scale_factors[g][sfb]: 0~255
             ic->scale_factors[g][sfb] = 0;
             //decode scale factor
             t = aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
             SF += (t - 60);
             if (SF < 0 || SF > 255)
                 ihdl->aac.sbrParseError = true;
             ic->scale_factors[g][sfb] = SF;
         }
      }
   }
}

static void aacPlusTnsData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 w, filt, i, start_coef_bits, coef_bits, dummy;
   kal_uint8 n_filt_bits = 2;
   kal_uint8 length_bits = 6;
   kal_uint8 order_bits = 5;

   start_coef_bits = 0;
   if(ics->window_sequence == EIGHT_SHORT_SEQUENCE){
      n_filt_bits = 1;
      length_bits = 4;
      order_bits = 3;
   }

   for(w = 0; w < ics->num_windows; w++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.n_filt[w], n_filt_bits);
      if(ics->tns.n_filt[w]){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.coef_res[w], 1);
         if(ics->tns.coef_res[w]){
            start_coef_bits = 4;
         }else{
             start_coef_bits = 3;
          }
      }

      for(filt = 0; filt < ics->tns.n_filt[w]; filt++){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.length[w][filt], length_bits);
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.order[w][filt], order_bits);

         if(ics->tns.order[w][filt]){
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.direction[w][filt], 1);
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns.coef_compress[w][filt], 1);
            coef_bits = start_coef_bits - ics->tns.coef_compress[w][filt];
            if(coef_bits>8)
               ihdl->aac.sbrParseError = true;
            for(i = 0; i < ics->tns.order[w][filt]; i++)
               FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, coef_bits);
         }
      }
   }
}

static void aacPlusPulseData(aacMediaHdl *ihdl, kal_uint32 *puBitCnt)
{
   kal_uint8 i, number_pulse, dummy;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &number_pulse, 2);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 6); /* pulse_start_sfb */

   for (i = 0; i < number_pulse+1; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 5);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, 4);
   }
}

static void aacPlusHuffman2stepQuad(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint32 cw;
   kal_uint16 offset = 0;
   kal_uint8  extra_bits, dummy;
   kal_int8   tmp;

   cw = aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, hcbN[cb]);

   offset = hcb_table[cb][cw].offset;
   extra_bits = hcb_table[cb][cw].extra_bits;

   if(extra_bits){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcbN[cb]);
      offset += (uint16)aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, extra_bits);
      tmp = hcb_2_quad_table[cb][offset].bits - hcbN[cb];
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, tmp);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_quad_table[cb][offset].bits);
    }

   if(offset > hcb_2_quad_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_2_quad_table[cb][offset].x;
   sp[1] = hcb_2_quad_table[cb][offset].y;
   sp[2] = hcb_2_quad_table[cb][offset].v;
   sp[3] = hcb_2_quad_table[cb][offset].w;
}

static void aacPlusHuffmanSignBits(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 len, kal_int16 *sp)
{
   kal_uint8 i, tmp;

   for(i = 0; i < len; i++){
      if(sp[i]){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 1);
         if(tmp&1){
            sp[i] = -sp[i];
         }
      }
   }
}

static void aacPlusHuffmanBinaryQuad(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint16 offset = 0;
   kal_uint8  b;

   while(!hcb3[offset].is_leaf)
   {
      if(FSAL_OK != FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1))
      {
         ihdl->aac.sbrParseError = true;
         break;
      }
      offset += hcb3[offset].data[b];
   }

   if(offset > hcb_bin_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb3[offset].data[0];
   sp[1] = hcb3[offset].data[1];
   sp[2] = hcb3[offset].data[2];
   sp[3] = hcb3[offset].data[3];
}

static void aacPlusHuffmanBinaryQuadSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffmanBinaryQuad(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, 4, sp);
}

static void aacPlusHuffmanBinaryPair(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint16 offset = 0;
   kal_uint8  b;

   while(!hcb_bin_table[cb][offset].is_leaf)
   {
      if(FSAL_OK != FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &b, 1))
      {
         ihdl->aac.sbrParseError = true;
         break;
      }
      offset += hcb_bin_table[cb][offset].data[b];
   }

   if(offset > hcb_bin_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_bin_table[cb][offset].data[0];
   sp[1] = hcb_bin_table[cb][offset].data[1];
}

static void aacPlusHuffmanBinaryPairSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffmanBinaryPair(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, PAIR_LEN, sp);
}

static void aacPlusHuffman2stepPair(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   kal_uint32 cw;
   kal_uint16 offset = 0;
   kal_uint8 extra_bits, dummy;

   cw = aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, hcbN[cb]);

   offset = hcb_table[cb][cw].offset;
   extra_bits = hcb_table[cb][cw].extra_bits;

   if(extra_bits){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcbN[cb]);
      offset += aacPlusPeekBits(ihdl, *puBitCnt, ihdl->fileOffset + ihdl->aac.rawDataBlockOffset, extra_bits);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_pair_table[cb][offset].bits - hcbN[cb]);
   }else{
       FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &dummy, hcb_2_pair_table[cb][offset].bits);
    }

   if(offset > hcb_2_pair_table_size[cb]){
      ihdl->aac.sbrParseError = true;
   }

   sp[0] = hcb_2_pair_table[cb][offset].x;
   sp[1] = hcb_2_pair_table[cb][offset].y;
}

static void aacPlusHuffman2stepPairSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffman2stepPair(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, PAIR_LEN, sp);
}

static void aacPlusHuffman2stepQuadSign(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   aacPlusHuffman2stepQuad(ihdl, puBitCnt, cb, sp);
   aacPlusHuffmanSignBits(ihdl, puBitCnt, QUAD_LEN, sp);
}

static kal_int16 aacPlusHuffmanCodebook( kal_uint8 i )
{
   static const kal_uint32 data = 16428320;
   if(i == 0) return (kal_int16)(data >> 16) & 0xFFFF;
   else       return (kal_int16)data & 0xFFFF;
}

static kal_int16 aacPlusHuffmanGetescape(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_int16 sp)
{
   kal_uint8 neg, i, tmp;
   kal_int32 j, off;

   if(sp < 0){
      if(sp != -16)
         return sp;
      neg = 1;
   }else{
       if(sp != 16)
          return sp;
       neg = 0;
    }

   for(i = 4; ; i++){
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 1);
      if(tmp==0)
         break;
   }

   off = 0;
   {
      kal_int32 k, cnt;
      kal_uint8 i1;
      i1 = i;
      k = i1/8;
      if(k>0)
         for(cnt=0; cnt<k; cnt++){
            FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, 8);
            off = ((uint32)off << (cnt*8))|(uint32)tmp;
         }
      i1 -= (8*k);
      if(i1>0){
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &tmp, i1);
         off = ((uint32)off << i1)|(uint32)tmp;
      }
   }

   j = off | (1<<i);
   if(neg)
      j = -j;

   return j;
}

static void aacPlusHuffmanSpectralData(aacMediaHdl *ihdl, kal_uint32 *puBitCnt, kal_uint8 cb, kal_int16 *sp)
{
   switch (cb)
   {
      case 1:
      case 2:
          aacPlusHuffman2stepQuad(ihdl, puBitCnt, cb, sp);
          break;
      case 3:
          aacPlusHuffmanBinaryQuadSign(ihdl, puBitCnt, cb, sp);
          break;
      case 4:
          aacPlusHuffman2stepQuadSign(ihdl, puBitCnt, cb, sp);
          break;
      case 5:
          aacPlusHuffmanBinaryPair(ihdl, puBitCnt, cb, sp);
          break;
      case 6:
          aacPlusHuffman2stepPair(ihdl, puBitCnt, cb, sp);
          break;
      case 7:
      case 9:
          aacPlusHuffmanBinaryPairSign(ihdl, puBitCnt, cb, sp);
          break;
      case 8:
      case 10:
          aacPlusHuffman2stepPairSign(ihdl, puBitCnt, cb, sp);
          break;
      case 12:
          aacPlusHuffman2stepPair(ihdl, puBitCnt, 11, sp);
          sp[0] = aacPlusHuffmanCodebook(0);
          sp[1] = aacPlusHuffmanCodebook(1);
          break;
      case 11:
          aacPlusHuffman2stepPairSign(ihdl, puBitCnt, 11, sp);
          sp[0] = aacPlusHuffmanGetescape(ihdl, puBitCnt, sp[0]);
          sp[1] = aacPlusHuffmanGetescape(ihdl, puBitCnt, sp[1]);
          break;
      default:
          break;
   }
}

static void aacPlusSpectralData(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_int8   i;
   kal_uint8  g, sect_cb_cache;
   kal_uint16 inc, k, p = 0;
   kal_uint8  groups = 0;
   kal_uint16 nshort = 128; // frameLength/8

   for(g = 0; g < ics->num_window_groups; g++)
   {
      p = groups*nshort;

      for (i = 0; i < ics->num_sec[g]; i++)
      {
         sect_cb_cache = ics->sect_cb[g][i];
         inc = (sect_cb_cache >= FIRST_PAIR_HCB) ? 2 : 4;

         switch (sect_cb_cache)
         {
            case ZERO_HCB:
            case NOISE_HCB:
            case INTENSITY_HCB:
            case INTENSITY_HCB2:
                 p += (ics->sect_sfb_offset[g][ics->sect_end[g][i]] -
                     ics->sect_sfb_offset[g][ics->sect_start[g][i]]);
                 break;
            default:
                 for (k = ics->sect_sfb_offset[g][ics->sect_start[g][i]];
                      k < ics->sect_sfb_offset[g][ics->sect_end[g][i]]; k += inc)
                 {
                    aacPlusHuffmanSpectralData(ihdl, puBitCnt, sect_cb_cache, &ics->spectral_Data[p]);
                    p += inc;
                 }
                 break;
         }
      }
      groups += ics->window_group_length[g];
   }
}

static void aacPlusIndividualChannelStream(aacMediaHdl *ihdl, iCS *ics,
                              kal_uint32 *puBitCnt, kal_uint8 common_window, kal_uint8 scal_flag)
{
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->global_gain, 8);

   if(!common_window && !scal_flag)
      aacPlusIcsInfo(ihdl, ics, puBitCnt);

   aacPlusSectionData(ihdl, ics, puBitCnt);
   aacPlusDecodeScaleFactors(ihdl, ics, puBitCnt);

   if (!scal_flag)
   {
      /* get pulse data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->pulse_data_present, 1);
      if(ics->pulse_data_present)
         aacPlusPulseData(ihdl, puBitCnt);

      /* get tns data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->tns_data_present, 1);
      if(ics->tns_data_present)
         aacPlusTnsData(ihdl, ics, puBitCnt);

      /* get gain control data */
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->gain_control_data_present, 1);
      if(ics->gain_control_data_present){
         ihdl->aac.sbrParseError = true;
         return;
      }
   }
   /* decode the spectral data */
   aacPlusSpectralData(ihdl, ics, puBitCnt);
}

static void aacPlusSingleChannelElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 element_instance_tag;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &element_instance_tag, 4);
   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, 0, 0);
}

static void aacPlusChannelPairElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 element_instance_tag, common_window;
   iCS *ics2;

   ics2 = (iCS*)audio_alloc_mem( sizeof(iCS) );
   if(ics2 == NULL){
      ihdl->aac.sbrParseError = true;
      return;
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &element_instance_tag, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &common_window, 1);

   if(common_window){
      /* both channels have common ics information */
      aacPlusIcsInfo(ihdl, ics, puBitCnt);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->ms_mask_present, 2);
      if (ics->ms_mask_present == 1){
          kal_uint8 g, sfb;
          for(g = 0; g < ics->num_window_groups; g++){
             for(sfb = 0; sfb < ics->max_sfb; sfb++)
                FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ics->ms_used[g][sfb], 1);
          }
      }
   }
   memcpy(ics2, ics, sizeof(iCS));
   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, common_window, 0);
   aacPlusIndividualChannelStream(ihdl, ics2, puBitCnt, common_window, 0);
   audio_free_mem( (void **) &ics2 );
}

static void aacPlusCouplingChannelElement(aacMediaHdl *ihdl, iCS *ics, kal_uint32 *puBitCnt)
{
   kal_uint8 c;
   kal_uint8 ind_sw_cce_flag = 0;
   kal_uint8 num_gain_element_lists = 0;
   kal_uint8 num_coupled_elements = 0;

   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &c, 4);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &ind_sw_cce_flag, 1);
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &num_coupled_elements, 3);

   for (c = 0; c < num_coupled_elements + 1; c++){
      kal_uint8 cc_target_is_cpe, cc_target_tag_select;

      num_gain_element_lists++;
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_target_is_cpe, 1);
      FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_target_tag_select, 4);

      if (cc_target_is_cpe){
         kal_uint8 cc_l, cc_r;
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_l, 1);
         FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cc_r, 1);

         if (cc_l && cc_r)
            num_gain_element_lists++;
      }
   }
   FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &c, 4);

   aacPlusIndividualChannelStream(ihdl, ics, puBitCnt, 0, 0);

   for (c = 1; c < num_gain_element_lists; c++){
      kal_uint8 cge;
      if (ind_sw_cce_flag){
          cge = 1;
      } else {
          FSAL_Read_Bits( ihdl->pstFSAL, puBitCnt, &cge, 1);
      }
      if (cge){
         aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
      } else {
          kal_uint8 g, sfb;

          for (g = 0; g < ics->num_window_groups; g++){
             for (sfb = 0; sfb < ics->max_sfb; sfb++){
                if (ics->sfb_cb[g][sfb] != ZERO_HCB)
                   aacPlusHuffmanScaleFactor(ihdl, puBitCnt);
              }
          }
      }
   }
}

/* Refer to ISO/IEC 14496-3:2001(E)
   However,only required to parse SCE/CPE/LFE/CCE/DCE/PCE/FIL
   in raw_data_block(), without interpreting them.
*/

void aacPlusSearchSBR(aacMediaHdl *ihdl)
{
   iCS *ics;
   kal_uint8  id_syn_ele;
   kal_uint32 puBitCnt=0;

   FSAL_Seek( ihdl->pstFSAL, (ihdl->fileOffset + ihdl->aac.rawDataBlockOffset));
   ics = (iCS*)audio_alloc_mem( sizeof(iCS) );
   if(ics == NULL){
      ihdl->aac.sbrParseError = true;
      return;
   }
   memset(ics, 0, sizeof(iCS));

   /* Table 4.4.3: raw_data_block() */
   while(1){
      if(FSAL_OK != FSAL_Read_Bits( ihdl->pstFSAL, &puBitCnt, &id_syn_ele, LEN_SE_ID))
         break;         
      if( id_syn_ele == ID_END || ihdl->aac.sbrParseError == true) break;

      switch (id_syn_ele) {
         case ID_SCE:
             aacPlusSingleChannelElement(ihdl, ics, &puBitCnt);
             ihdl->aac.SCEnum += 1;
             ihdl->aac.channelNum++;
             break;
         case ID_CPE:
             aacPlusChannelPairElement(ihdl, ics, &puBitCnt);
             ihdl->aac.channelNum += 2;
             break;
         case ID_LFE:
             ihdl->aac.SCEnum += 1;
             ihdl->aac.channelNum++;
             aacPlusSingleChannelElement(ihdl, ics, &puBitCnt);
             break;
         case ID_CCE:
             aacPlusCouplingChannelElement(ihdl, ics, &puBitCnt);
             break;
         case ID_DSE:
             aacPlusDataStreamElement(ihdl, &puBitCnt);
             break;
         case ID_PCE:
             aacPlusProgramConfigElement(ihdl, &puBitCnt);
             break;
         case ID_FIL:
             aacPlusFillElement(ihdl, &puBitCnt);
             if(ihdl->aac.sbr_chanidx < (AAC_MAX_SUPPORT_ID_ARRAYS-1))
                ihdl->aac.sbr_chanidx += 1;
             break;
         default:
             if(ihdl->aac.bChanSbrFlag[0] || ihdl->aac.bChanSbrFlag[1])
                ihdl->aac.sbrPresentFlag = true;
             audio_free_mem( (void **) &ics );
             return;
      }
   }
   audio_free_mem( (void **) &ics );
}
#endif // AAC_PLUS_DECODE
#endif 


