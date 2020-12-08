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
 *   sbc.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SBC codec interface
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 *
 *  Bluetooth low-complexity, subband codec (SBC) library
 *
 *  Copyright (C) 2004  Marcel Holtmann <marcel@holtmann.org>
 *  Copyright (C) 2004  Henryk Ploetz <henryk@ploetzli.ch>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#if defined(__BT_A2DP_PROFILE__)

#ifndef _SBC_H_
#define _SBC_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include "kal_non_specific_general_types.h"
//#include "l1audio.h"
#include "kal_general_types.h"

#define SBC_SYNCWORD 0x9C
/* sampling frequency */
#define SBC_FS_16	0x00
#define SBC_FS_32	0x01
#define SBC_FS_44	0x02
#define SBC_FS_48	0x03

/* nrof_blocks */
#define SBC_NB_4	0x00
#define SBC_NB_8	0x01
#define SBC_NB_12	0x02
#define SBC_NB_16	0x03

/* channel mode */
#define SBC_CM_MONO		0x00
#define SBC_CM_DUAL_CHANNEL	0x01
#define SBC_CM_STEREO		0x02
#define SBC_CM_JOINT_STEREO	0x03

#define MONO		0x00
#define DUAL_CHANNEL	0x01
#define STEREO		0x02
#define JOINT_STEREO	0x03

/* allocation mode */
#define SBC_AM_LOUDNESS		0x00
#define SBC_AM_SNR		0x01

#define LOUDNESS		0x00
#define SNR		0x01

#define PREFFERED_ALLOCATION_MODE		LOUDNESS

/* SBC internal functions */
#if (PREFFERED_ALLOCATION_MODE==LOUDNESS)
#define SBC_ALLOCATION_SUPPORT      0x1 // alloc_method: loudness only
#elif (PREFFERED_ALLOCATION_MODE==SNR)
#define SBC_ALLOCATION_SUPPORT      0x2 // alloc_method: snr only
#else
#error wrong definition in sbc.h
#endif

/* subbands */
#define SBC_SB_4	0x00
#define SBC_SB_8	0x01

#define SB_NUM 		8

#define SBC_IN_TCM 1
#define SBC_FIXED_POINT

#if (SBC_IN_TCM == 1) && defined(SBC_FIXED_POINT)
#define SBC_TABLE_INTERNAL
#endif

#define ESBC_MAX_BITPOOL 40 // If bitpool setting is less than this, the E-SBC will turn on


typedef struct{
#ifdef SBC_FIXED_POINT
    #ifdef DEDICATED_ON_MONO
        short X[1][80];
    #else
        short X[2][80];
    #endif
#else // floating-point
    float S[2][8];				/* Subband samples */
    float X[2][80], Y[2][16], Z[2][80];	/* Vectors */
#endif
}SBC_Encoder_State;

typedef struct{
	float S[2][8];				/* Subband samples */
	float X[2][8];				/* Audio samples */
	float V[2][160], U[2][80], W[2][80];	/* Vectors */
}SBC_Decoder_State;

#if 1
#define SB_CLIPPING 
typedef short SB_Type;
#else 
/* under construction !*/
#endif 

typedef unsigned char SCF_T;

typedef struct {
	int sampling_frequency;	/* in kHz */
	int blocks;
	int channels;
	int subbands;
	int channel_mode;
	int allocation_method;
	int bitpool;
	short *sb_sample;
	unsigned char sbc_frame_header_data;
	SCF_T scale_factor[2][8];
	int ESBC_disable;
} SBC_Frame_State;

typedef struct {
	int frame_num;
	SBC_Frame_State *frame;
	short sub_sample[16][2][8];
	unsigned char LR_scf[2][8];
	unsigned char MS_scf[2][8];
	unsigned char join[8];
	int bits[2][8];
	unsigned short  q_sub_sample[2][16][8];
	short  deq_sub_sample[2][16][8];

	signed char snr_min_save[2][8];
	unsigned char min_bits_need_save[2][8];
	short localmax[2][8];
	SCF_T scf_lr_bak[2][8];
	SCF_T scf_lr[2][8];
	signed char bits_budget[2];
	int total_atten[2][8];
	int bits_orig[2][8];
	int sum_err1[2][8];
} SBC_Frame_Debug;

typedef short (*SB_BUF2_T)[8][2];
typedef short (*SB_BUF_T)[2][8];
typedef short (*PCM_BUF_T)[16*8];

int sbc_analyze_audio(int srcChannels, SBC_Encoder_State *sbc_state, SBC_Frame_State *frame, short *pcm_sample);
int sbc_synthesize_audio(SBC_Decoder_State *sbc_state, SBC_Frame_State *frame, short pcm_sample[2][16*8]);
void sbc_pack_frame(SBC_Frame_State *frame, unsigned char *frame_data, int *frame_data_len, int current_frame_size); 
int sbc_unpack_frame(SBC_Frame_State *frame, unsigned char *data,  int len);
void sbc_Init_ZI(void);
int sbc_Init_Ptr(short* base);
void sbc_UpdateSeed(void);

/* Common part in encoder and decoder */
#ifdef SBC_FIXED_POINT
extern const short sbc_proto_4_40_fx[40];
extern const short sbc_proto_8_80_fx[80];
#endif
extern const double sbc_proto_4_40[40];
extern const double sbc_proto_8_80[80];

unsigned char sbc_crc8(unsigned char * data, int len);
void sbc_calculate_bits(SBC_Frame_State *frame, int (*bits)[8]);

void sbc_RampUpSignal(short *pBuf, int QFormat, int len, int *rampGain, int channel);

void sbc_initiate_internal(const kal_uint8 code[16]);
kal_bool sbc_isAuthenticated( void );

#ifdef __cplusplus
}
#endif

#endif

#endif
