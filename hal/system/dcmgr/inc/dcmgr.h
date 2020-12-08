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
 *
 * Filename:
 * ---------
 *   dcmgr.h
 *
 * Project:
 * --------
 *   MAUI (MT6226/MT6227/MT6228/MT6229)
 *
 * Description:
 * ------------
 *   Dynamic Code Manager for dynamic code relocation into TCM(internal SRAM)
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
*  Maintenance / Configuration Notes
*  ================================================================================
*
*  Definitions :
*  ==============
*
*  DYNAMIC_CODE_NUM         : Total number of DCM candidates (regardless of DCM
*                             target pool)
*  DYNAMIC_CODE_XXX         : Identity number of DCM candidate, must be an
*                             incremental number
*                             Note, must not change the pre-fix DYNAMIC_CODE_
*  DCM_TARGET_NUM           : Total number DCM target pools
*  DCM_TARGET_ADDRESSx      : Start Address of DCM target pool x, must be consistent
*                             with scattter file
*  DCM_TARGET_SIZEx         : Size of DCM target pool x
*
*  DCM_SCAT_CODEx_AVAILABLE : The xth DCM identity is available for certain BB-chip
*
*  DCM_TARGET_CONFIGURE     : Specify DCM target pool of the entire DCM candidates
*                             according to their identity
*
*  SOP to add-in a new DCM candidates :
*  =====================================
*  New candidate, DYNAMIC_CODE_EXAMMPLE
*
*  STEP 1 :  increment DYNAMIC_CODE_NUM by 1 and define identity number for
*            new DCM candidate
*
*            #define DYNAMIC_CODE_NUM        N
*            #define DYNAMIC_CODE_EXAMMPLE  (N-1)
*
*  STEP 2 :  edit scatter file
*
*  STEP 3 :  change the DCM_TARGET_NUM, and create DCM_TARGET_ADDRESSx
*            together with DCM_TARGET_SIZEx in case of new DCM target pool
*            is needed
*
*  STEP 4 :  define DCM_SCAT_CODEN_AVAILABLE for specific BB-chip if it
*            is not common candidates
*
*  STEP 5 :  specify DCM target pool ID for all DCM candidates
*            Despite of availability, each DCM ID must be specified with a
*            DCM target pool, 0 if unavailable
*
*  STEP 6 :  edit dcmgr.c, declare the correspondence linker symbol, and
*            assign as an entry of DCM_linker_symbols_by_dynamic_code_id[].
*
*  STEP 7 :  in case of new DCM target pool added, create a new entry
*            for the following array in dcmgr.c
*            current_dynamic_code_id[]
*            DCM_target_pool_addr[]
*            DCM_target_pool_size[]
*
*****************************************************************************/

#ifndef __DCMGR_H
#define __DCMGR_H

#include "kal_general_types.h"
#include "intrCtrl.h"

#if defined(__MTK_TARGET__)

/*
 * Define chips dependency.
 */

#if defined(MT6228)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6229) || defined(MT6230)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6268T)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6268H)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6238) || defined(MT6239)
#define MT6238_SERIES_DCMGR
#endif

#if defined(MT6235) || defined(MT6235B)
#define MT6235_SERIES_DCMGR
#endif

#if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D)
#define MT6227_SERIES_DCMGR
#endif

#if defined(MT6223) || defined(MT6223P)
#define MT6223_SERIES_DCMGR
#endif

#if defined(MT6227D)
#define MT6227_SERIES_DCMGR
#endif

#if defined(MT6253T) || defined(MT6253)
#define MT6253_SERIES_DCMGR
#endif

#if defined(MT6236) || defined(MT6236B)
#define MT6236_SERIES_DCMGR
#endif

#if defined(MT6252)
#define MT6252_SERIES_DCMGR
#endif

#if defined(MT6250)
#define MT6250_SERIES_DCMGR
#endif

#if defined(MT6260)
#define MT6260_SERIES_DCMGR
#endif


#if defined(MT6260_SERIES_DCMGR)
#define DCMGR_MT6260_AFTER
#endif

/*
 * Define constants.
 */

/* invalid value */
#define DCMGR_INVALID_VAL   (0xFFFFFFFF)

/* mask to convert dynamic code ID to suitable pool index */
#define DYNAMIC_POOL_ID_MASK  (0xFF)

#if defined(__DYNAMIC_CODE_MANAGER__)

/* DCM users should use __DYNAMIC_CODE_MANAGER__ but DYNAMIC_CODE_MANAGER */
#define DYNAMIC_CODE_MANAGER

/* define dynamic code information */
#define DYNAMIC_CODE_NUM      23
#define DYNAMIC_CODE_NONE     -1
#define DYNAMIC_CODE_AMR515   0
#define DYNAMIC_CODE_G3D      1
#define DYNAMIC_CODE_CTM      2
#define DYNAMIC_CODE_G729     3
#define DYNAMIC_CODE_SBC      4
#define DYNAMIC_CODE_BCODE    5
#define DYNAMIC_CODE_REVERB   6
#define DYNAMIC_CODE_RESAMPLE 7
#define DYNAMIC_CODE_JPEG_ENC 8
#define DYNAMIC_CODE_JPEG_DEC 9
#define DYNAMIC_CODE_VRENGINE 10
#define DYNAMIC_CODE_MP4DEC_B 11
#define DYNAMIC_CODE_MP4ENC_B 12
#define DYNAMIC_CODE_264DEC_B 13
#define DYNAMIC_CODE_MP4DEC_S 14
#define DYNAMIC_CODE_MP4ENC_S 15
#define DYNAMIC_CODE_264DEC_S 16
#define DYNAMIC_CODE_MP4DEC_C 17 /* only for MT6225 now */
#define DYNAMIC_CODE_MP4ENC_C 18   /* only for MT6225 now */
#define DYNAMIC_CODE_264DEC_C 19   /* only for MT6253 now */
#define DYNAMIC_CODE_RVDEC_B  20
#define DYNAMIC_CODE_RVDEC_S  21
#define DYNAMIC_CODE_RVDEC_C  22

#if defined(MT6228_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE2$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        2
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE2$$Base)
#define DCM_TARGET_SIZE2      0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6238_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5010F000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5010C800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */


/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6235_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		3
#define DCM_TARGET_ADDRESS1   		0x5010F000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5010C800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */
#define DCM_TARGET_ADDRESS3   		0x50108C00
#define DCM_TARGET_SIZE3      		0x3C00      /* 15KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE14_AVAILABLE   /* H264B */
#define DCM_SCAT_CODE15_AVAILABLE   /* MP4ENCS */
#define DCM_SCAT_CODE16_AVAILABLE   /* MP$DECS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,3,3,3,2,2,2,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6268A)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5011B000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50118800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6268)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x50116000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50113800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6270A)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5012F000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5012C800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */


#elif defined(MT6227_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE6_AVAILABLE   /* BCODE */
#define DCM_SCAT_CODE7_AVAILABLE   /* REVERB */
#define DCM_SCAT_CODE8_AVAILABLE   /* RESAMPLE */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */


/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6225)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE18$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        2
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE18$$Base)
#define DCM_TARGET_SIZE2      0xd90      /* 3KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE14_AVAILABLE   /* H264B */
#define DCM_SCAT_CODE18_AVAILABLE   /* MP4DEC_CODE */
#define DCM_SCAT_CODE19_AVAILABLE   /* MP4ENC */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,2,2,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6253_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        3
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE17$$Base)
#define DCM_TARGET_SIZE2      0xd90      /* 3KB */
#define DCM_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_CODE12$$Base)
#define DCM_TARGET_SIZE3      0x9600      /* 37.5KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE16_AVAILABLE   /* MP4ENCS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */
#define DCM_SCAT_CODE18_AVAILABLE   /* MP4DEC_CODE */
#define DCM_SCAT_CODE19_AVAILABLE   /* MP4ENC */
#define DCM_SCAT_CODE20_AVAILABLE   /* H264C */
#define DCM_SCAT_CODE22_AVAILABLE   /* RVDECS */
#define DCM_SCAT_CODE23_AVAILABLE   /* RVDECC */

/*
 * setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
 * 3 : DCM target pool 3
 */
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,3,1,0,0,3,2,2,2,3,0,2,3

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6223_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE3$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE3$$Base)
#define DCM_TARGET_SIZE1      0x1280      /* 4736 Bytes */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE7_AVAILABLE   /* REVERB */
#define DCM_SCAT_CODE8_AVAILABLE   /* RESAMPLE */
#define DCM_SCAT_CODE9_AVAILABLE   /* JPG_ENC */
#define DCM_SCAT_CODE10_AVAILABLE   /* JPG_DEC */
/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6252_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        3

#define DCM_TARGET_ADDRESS1   0x0
#define DCM_TARGET_SIZE1      0x0
#define DCM_TARGET_ADDRESS2   0x0
#define DCM_TARGET_SIZE2      0x0
#define DCM_TARGET_ADDRESS3   0x0
#define DCM_TARGET_SIZE3      0x0

/*
 * setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
 * 3 : DCM target pool 3
 */
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,3,1,0,0,3,2,2,2,3,0,2,3

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6250_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        3

#define DCM_TARGET_ADDRESS1   0x0
#define DCM_TARGET_SIZE1      0x0
#define DCM_TARGET_ADDRESS2   0x0
#define DCM_TARGET_SIZE2      0x0
#define DCM_TARGET_ADDRESS3   0x0
#define DCM_TARGET_SIZE3      0x0

/*
 * setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
 * 3 : DCM target pool 3
 */
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,3,1,0,0,3,2,2,2,3,0,2,3

/* ---------------------------------------------------------------------------------- */
#elif defined(MT6236_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5010B000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50110000
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE15_AVAILABLE   /* MP4DECS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */
#define DCM_SCAT_CODE22_AVAILABLE   /* RVDECS */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,2,0,2,0,0,0,0,2,0

#else

#error Overlay region for dynamic code relocation should be determined for new chipset

#endif

#endif /* __DYNAMIC_CODE_MANAGER__ */

#endif /* __MTK_TARGET__ */
/* ---------------------------------------------------------------------------------- */


/* define compressed dynamic code ID information */
#define DYNAMIC_CODE_COMPRESS_NUM          64
#define DYNAMIC_CODE_COMPRESS_END          0x140
#define DYNAMIC_CODE_COMPRESS_BEGIN        0x100
#define DYNAMIC_CODE_COMPRESS_NONE         -1
#define DYNAMIC_CODE_COMPRESS_SBC                 DYNAMIC_CODE_COMPRESS_BEGIN+0      //0x100
#define DYNAMIC_CODE_COMPRESS_BESLOUDNESS         DYNAMIC_CODE_COMPRESS_BEGIN+1      //0x101
#define DYNAMIC_CODE_COMPRESS_MP4DEC_C            DYNAMIC_CODE_COMPRESS_BEGIN+2      //0x102
#define DYNAMIC_CODE_COMPRESS_MP4ENC_C            DYNAMIC_CODE_COMPRESS_BEGIN+3      //0x103
#define DYNAMIC_CODE_COMPRESS_H264DEC_C           DYNAMIC_CODE_COMPRESS_BEGIN+4      //0x104
#define DYNAMIC_CODE_COMPRESS_MP4ASPDEC           DYNAMIC_CODE_COMPRESS_BEGIN+5      //0x105
#define DYNAMIC_CODE_COMPRESS_VP8DEC              DYNAMIC_CODE_COMPRESS_BEGIN+6      //0x106
#define DYNAMIC_CODE_COMPRESS_MATVDRIVER           DYNAMIC_CODE_COMPRESS_BEGIN+7      //0x107
#define DYNAMIC_CODE_COMPRESS_VEENC                DYNAMIC_CODE_COMPRESS_BEGIN+8      //0x108
#define DYNAMIC_CODE_COMPRESS_VEDEC                DYNAMIC_CODE_COMPRESS_BEGIN+9      //0x109
#define DYNAMIC_CODE_COMPRESS_DAF                  DYNAMIC_CODE_COMPRESS_BEGIN+10     //0x10a
#define DYNAMIC_CODE_COMPRESS_WAVETABLE            DYNAMIC_CODE_COMPRESS_BEGIN+11     //0x10b
#define DYNAMIC_CODE_COMPRESS_BROWSER              DYNAMIC_CODE_COMPRESS_BEGIN+12     //0x10c
#define DYNAMIC_CODE_COMPRESS_CALC                 DYNAMIC_CODE_COMPRESS_BEGIN+13     //0x10d
#define DYNAMIC_CODE_COMPRESS_CALLSET              DYNAMIC_CODE_COMPRESS_BEGIN+14     //0x10e
#define DYNAMIC_CODE_COMPRESS_CAMCO                DYNAMIC_CODE_COMPRESS_BEGIN+15     //0x10f
#define DYNAMIC_CODE_COMPRESS_CLNDR                DYNAMIC_CODE_COMPRESS_BEGIN+16     //0x110
#define DYNAMIC_CODE_COMPRESS_CLOCK                DYNAMIC_CODE_COMPRESS_BEGIN+17     //0x111
#define DYNAMIC_CODE_COMPRESS_FMRADIO              DYNAMIC_CODE_COMPRESS_BEGIN+18     //0x112
#define DYNAMIC_CODE_COMPRESS_SOUNDSET             DYNAMIC_CODE_COMPRESS_BEGIN+19     //0x113
#define DYNAMIC_CODE_COMPRESS_COSMOS_EM            DYNAMIC_CODE_COMPRESS_BEGIN+20     //0x114
#define DYNAMIC_CODE_COMPRESS_COSMOS_FM            DYNAMIC_CODE_COMPRESS_BEGIN+21     //0x115
#define DYNAMIC_CODE_COMPRESS_COSMOS_DTCNT         DYNAMIC_CODE_COMPRESS_BEGIN+22     //0x116
#define DYNAMIC_CODE_COMPRESS_MOT                  DYNAMIC_CODE_COMPRESS_BEGIN+23     //0x117
#define DYNAMIC_CODE_COMPRESS_SECSET               DYNAMIC_CODE_COMPRESS_BEGIN+24     //0x118
#define DYNAMIC_CODE_COMPRESS_BAIDUSEARCH          DYNAMIC_CODE_COMPRESS_BEGIN+25     //0x119
#define DYNAMIC_CODE_COMPRESS_BOOTUP               DYNAMIC_CODE_COMPRESS_BEGIN+26     //0x11a
#define DYNAMIC_CODE_COMPRESS_SETTING              DYNAMIC_CODE_COMPRESS_BEGIN+27     //0x11b
#define DYNAMIC_CODE_COMPRESS_SOUNDREC             DYNAMIC_CODE_COMPRESS_BEGIN+28     //0x11c
#define DYNAMIC_CODE_COMPRESS_CAMIMGV              DYNAMIC_CODE_COMPRESS_BEGIN+29     //0x11d
#define DYNAMIC_CODE_COMPRESS_VDOREC               DYNAMIC_CODE_COMPRESS_BEGIN+30     //0x11e
#define DYNAMIC_CODE_COMPRESS_CALENDAR             DYNAMIC_CODE_COMPRESS_BEGIN+31     //0x11f
#define DYNAMIC_CODE_COMPRESS_CALCULATOR           DYNAMIC_CODE_COMPRESS_BEGIN+32     //0x120
#define DYNAMIC_CODE_COMPRESS_VDOPLY               DYNAMIC_CODE_COMPRESS_BEGIN+33     //0x121
#define DYNAMIC_CODE_COMPRESS_MATV                 DYNAMIC_CODE_COMPRESS_BEGIN+34     //0x122
#define DYNAMIC_CODE_COMPRESS_SNDREC               DYNAMIC_CODE_COMPRESS_BEGIN+35     //0x123
#define DYNAMIC_CODE_COMPRESS_PROFILE              DYNAMIC_CODE_COMPRESS_BEGIN+36     //0x124
#define DYNAMIC_CODE_COMPRESS_CALLSETTING          DYNAMIC_CODE_COMPRESS_BEGIN+37     //0x125
#define DYNAMIC_CODE_COMPRESS_SCRLOCK              DYNAMIC_CODE_COMPRESS_BEGIN+38     //0x126
#define DYNAMIC_CODE_COMPRESS_SETTINGS             DYNAMIC_CODE_COMPRESS_BEGIN+39     //0x127
#define DYNAMIC_CODE_COMPRESS_DTCNT                DYNAMIC_CODE_COMPRESS_BEGIN+40     //0x128
#define DYNAMIC_CODE_COMPRESS_EM                   DYNAMIC_CODE_COMPRESS_BEGIN+41     //0x129
#define DYNAMIC_CODE_COMPRESS_FM                   DYNAMIC_CODE_COMPRESS_BEGIN+42     //0x12a
#define DYNAMIC_CODE_COMPRESS_AMRREC              DYNAMIC_CODE_COMPRESS_BEGIN+43     //0x12b
#define DYNAMIC_CODE_COMPRESS_WAVREC              DYNAMIC_CODE_COMPRESS_BEGIN+44     //0x12c
#define DYNAMIC_CODE_COMPRESS_PCMREC              DYNAMIC_CODE_COMPRESS_BEGIN+45     //0x12d
#define DYNAMIC_CODE_COMPRESS_MDP                 DYNAMIC_CODE_COMPRESS_BEGIN+46     //0x12e
#define DYNAMIC_CODE_COMPRESS_VECOM               DYNAMIC_CODE_COMPRESS_BEGIN+47     //0x12f
#define DYNAMIC_CODE_COMPRESS_RENDER              DYNAMIC_CODE_COMPRESS_BEGIN+48     //0x130
#define DYNAMIC_CODE_COMPRESS_MDICAM              DYNAMIC_CODE_COMPRESS_BEGIN+49     //0x131
#define DYNAMIC_CODE_COMPRESS_MWREC               DYNAMIC_CODE_COMPRESS_BEGIN+50     //0x132
#define DYNAMIC_CODE_COMPRESS_MDIVID              DYNAMIC_CODE_COMPRESS_BEGIN+51     //0x133
#define DYNAMIC_CODE_COMPRESS_VIDMSG              DYNAMIC_CODE_COMPRESS_BEGIN+52     //0x134
#define DYNAMIC_CODE_COMPRESS_MWWEBCAM            DYNAMIC_CODE_COMPRESS_BEGIN+53     //0x135
#define DYNAMIC_CODE_COMPRESS_USBVIDEO            DYNAMIC_CODE_COMPRESS_BEGIN+54     //0x136
#define DYNAMIC_CODE_COMPRESS_MDIMTV              DYNAMIC_CODE_COMPRESS_BEGIN+55     //0x137
#define DYNAMIC_CODE_COMPRESS_MEDMTV              DYNAMIC_CODE_COMPRESS_BEGIN+56     //0x138
#define DYNAMIC_CODE_COMPRESS_MDISTREAM           DYNAMIC_CODE_COMPRESS_BEGIN+57     //0x139
#define DYNAMIC_CODE_COMPRESS_MEDSTREAM           DYNAMIC_CODE_COMPRESS_BEGIN+58     //0x13a
#define DYNAMIC_CODE_COMPRESS_CAMCAL              DYNAMIC_CODE_COMPRESS_BEGIN+59     //0x13b
#define DYNAMIC_CODE_COMPRESS_CAMMED              DYNAMIC_CODE_COMPRESS_BEGIN+60     //0x13c
#define DYNAMIC_CODE_COMPRESS_VKLAYOUT            DYNAMIC_CODE_COMPRESS_BEGIN+61     //0x13d
#define DYNAMIC_CODE_COMPRESS_GUOBIHW             DYNAMIC_CODE_COMPRESS_BEGIN+62     //0x13e
#define DYNAMIC_CODE_COMPRESS_IME                 DYNAMIC_CODE_COMPRESS_BEGIN+63     //0x13f


#define MAX_BITMAP_SIZE 4

#define DYNAMIC_CODE_COMPRESS_GROUP_NONE  0
#define DYNAMIC_CODE_COMPRESS_MEMBER_NONE 0
#define GROUP_MEMBER_NUMBER_NONE          -1

/* value to indicate whether a trunk is 
  1. not loaded to ram yet
  2. loaded but is not valid now
  3. loaded and valid
  */
#define   DCM_COMP_TRUNK_NOT_ON_RAM 0
#define   DCM_COMP_TRUNK_ON_RAM_INVALID 1
#define   DCM_COMP_TRUNK_ON_RAM_VALID 2



#if defined(__MTK_TARGET__)
#if defined(__DCM_WITH_COMPRESSION__)

/* DCM with compression user RO size
 * !CAUTION!
 * The defined RO size should be close to the linked size of each user
 * Following definitions would be parsed by sysgen.
 * Please do not change it without notice to sysgen owner.
 */

/* Video */
#define DYNAMIC_CODE_COMPRESS_H264DEC_RO_SIZE       0x14000
#define DYNAMIC_CODE_COMPRESS_MP4DEC_RO_SIZE        0x1E000
#define DYNAMIC_CODE_COMPRESS_MP4ENC_RO_SIZE        0x11800
#define DYNAMIC_CODE_COMPRESS_MP4ASPDEC_RO_SIZE     0x1D000
#define DYNAMIC_CODE_COMPRESS_VP8DEC_RO_SIZE        0x1D000
#define DYNAMIC_CODE_COMPRESS_VEDEC_RO_SIZE          0xE000
#define DYNAMIC_CODE_COMPRESS_VEENC_RO_SIZE          0xE000

/* Audio Post-Process */
#define DYNAMIC_CODE_COMPRESS_BESLOUDNESS_RO_SIZE   0x3400
#define DYNAMIC_CODE_COMPRESS_SBC_RO_SIZE           0x2000
/* Audio Codec */
#define DYNAMIC_CODE_COMPRESS_DAF_RO_SIZE           0x9000
#define DYNAMIC_CODE_COMPRESS_WAVETABLE_RO_SIZE     0x5C00

/* DCM with compression user RO size
 * !CAUTION!
 * The defined RO size should be something close to the linked size of each user
 * Above definitions would be parsed by sysgen.
 * Please do not change it without notice to sysgen owner.
 */

#if defined(MT6252_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC$$Base;

/* dynamic code availability on scatter file */
#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__) && defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_BT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__) && defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_EFFECT__ */

#if defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEDEC_AVAILABLE        /* VEDEC with compression */
#endif /* H264_DEC_SUPPORT__ || __MPEG4_DEC_SUPPORT__ || __MJPEG_DEC_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEENC_AVAILABLE        /* VEENC with compression */
#endif /* __MPEG4_ENC_SUPPORT__ || __MJPEG_ENC_SUPPORT__ */

/* define target pool information */
#define DCM_COMP_TARGET_NUM        4

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#else
#define DCM_COMP_TARGET_ADDRESS1   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE1      0x0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#define DCM_COMP_TARGET_SIZE2      0x3400      /* 13KB */
#else
#define DCM_COMP_TARGET_ADDRESS2   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE2      0x0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#else
#define DCM_COMP_TARGET_ADDRESS3   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE3      0x0
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS4   ((kal_uint32)&Image$$DYNAMIC_COMP_VEDEC$$Base)
#define DCM_COMP_TARGET_SIZE4      0xE000      /* 59 KB */
#elif defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS4   ((kal_uint32)&Image$$DYNAMIC_COMP_VEENC$$Base)
#define DCM_COMP_TARGET_SIZE4      0xE000      /* 59 KB */
#else
#define DCM_COMP_TARGET_ADDRESS4   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE4      0x0
#endif

/*
 * setup target pool by code id
 * 0 : DCM with compression candidate unavailable
 * 1 : DCM with compression target pool 1
 * 2 : DCM with compression target pool 2
 * 3 : DCM with compression target pool 3
 * 4 : DCM with compression target pool 4
 */
#define DCM_COMP_TARGET_CONFIGURE  1,2,3,3,3,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//-----------------------------------------------------------------------
#elif defined(MT6250_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ASPDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VP8DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DAF$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_WAVETABLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BROWSER$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLNDR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FMRADIO$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_FM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MOT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SECSET$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BOOTUP$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CAMIMGV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALENDAR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALCULATOR$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_VDOPLY$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MATV$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SNDREC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_PROFILE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSETTING$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SCRLOCK$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_SETTINGS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_DTCNT$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_EM$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_FM$$Base;


/* dynamic code availability on scatter file */
#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__) && defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_BT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__) && defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_EFFECT__ */


#if defined(__MPEG4_DEC_SW_SUPPORT__) && defined(__MP4_DEC_SW_SUPPORT_ASP__)
#define DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE      /* MP4ASPDEC with compression */
#elif defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ && __MP4_DEC_SW_SUPPORT_ASP__  */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

#if defined(__VP8_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_VP8DEC_AVAILABLE         /* VP8DEC with compression */
#endif /* __VP8_DEC_SW_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEDEC_AVAILABLE          /* VEDEC with compression */
#endif /* H264_DEC_SUPPORT__ || __MPEG4_DEC_SUPPORT__ || __MJPEG_DEC_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEENC_AVAILABLE          /* VEENC with compression */
#endif /* __MPEG4_ENC_SUPPORT__ || __MJPEG_ENC_SUPPORT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) && defined(DAF_DECODE)
#define DCM_COMP_SCAT_DAF_AVAILABLE            /* DAF with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_CODEC__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) && defined(DSP_WT_SYN)
#define DCM_COMP_SCAT_WAVETABLE_AVAILABLE      /* WAVETABLE with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_CODEC__ */


#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#define DCM_COMP_SCAT_BROWSER_AVAILABLE        /* BROWSER with compression  */
#define DCM_COMP_SCAT_CALC_AVAILABLE           /* CALC with compression  */
#define DCM_COMP_SCAT_CALLSET_AVAILABLE        /* CALLSET with compression  */
#define DCM_COMP_SCAT_CAMCO_AVAILABLE          /* CAMCO with compression  */
#define DCM_COMP_SCAT_CLNDR_AVAILABLE          /* CLNDR with compression  */
#define DCM_COMP_SCAT_CLOCK_AVAILABLE          /* CLOCK with compression  */
#define DCM_COMP_SCAT_FMRADIO_AVAILABLE        /* FMRADIO with compression  */
#define DCM_COMP_SCAT_SOUNDSET_AVAILABLE       /* SOUNDSET with compression  */
#define DCM_COMP_SCAT_COSMOS_EM_AVAILABLE      /* EM with compression  */
#define DCM_COMP_SCAT_COSMOS_FM_AVAILABLE      /* FM with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
#define DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE   /* DTCNT with compression  */
#define DCM_COMP_SCAT_MOT_AVAILABLE            /* MOT with compression  */
#define DCM_COMP_SCAT_SECSET_AVAILABLE         /* SECSET with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_B__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
#define DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE    /* BAIDUSEARCH with compression  */
#define DCM_COMP_SCAT_BOOTUP_AVAILABLE         /* BOOTUP with compression  */
#define DCM_COMP_SCAT_SETTING_AVAILABLE        /* SETTING with compression  */
#define DCM_COMP_SCAT_SOUNDREC_AVAILABLE       /* SOUNDREC with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_C__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_AP__)
#define DCM_COMP_SCAT_CAMIMGV_AVAILABLE         /* AP CAMERA and IMGIVEW with compression  */
#define DCM_COMP_SCAT_VDOREC_AVAILABLE         /* AP VDOREC with compression  */
#define DCM_COMP_SCAT_CALENDAR_AVAILABLE          /* AP CALENDAR with compression  */
#define DCM_COMP_SCAT_CALCULATOR_AVAILABLE           /* AP CALCULATOR with compression  */
#define DCM_COMP_SCAT_VDOPLY_AVAILABLE         /* AP VDOPLY with compression  */
#define DCM_COMP_SCAT_MATV_AVAILABLE           /* AP MATV with compression  */
#define DCM_COMP_SCAT_SNDREC_AVAILABLE         /* AP SNDREC with compression  */
#define DCM_COMP_SCAT_PROFILE_AVAILABLE        /* AP PROFILE with compression  */
#define DCM_COMP_SCAT_CALLSETTING_AVAILABLE        /* AP CALLSETTING with compression  */
#define DCM_COMP_SCAT_SCRLOCK_AVAILABLE        /* AP SCRLOCK with compression  */
#define DCM_COMP_SCAT_SETTINGS_AVAILABLE        /* AP SETTING with compression  */
#define DCM_COMP_SCAT_DTCNT_AVAILABLE          /* AP DTCNT with compression  */
#define DCM_COMP_SCAT_EM_AVAILABLE             /* AP EM with compression  */
#define DCM_COMP_SCAT_FM_AVAILABLE             /* AP FM with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_AP__ */



/* define target pool information */
#define DCM_COMP_TARGET_NUM        9

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#else
#define DCM_COMP_TARGET_ADDRESS1   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE1      0x0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#define DCM_COMP_TARGET_SIZE2      0x3400      /* 13KB */
#else
#define DCM_COMP_TARGET_ADDRESS2   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE2      0x0
#endif


#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x1B800      /* 112KB */
#elif defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x1B800      /* 112KB */
#elif defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ASPDEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x1B800      /* 112KB */
#elif defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_VP8DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x1B800      /* 112KB */
#elif defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x11000      /* 68KB */
#else
#define DCM_COMP_TARGET_ADDRESS3   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE3      0x0
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS4   ((kal_uint32)&Image$$DYNAMIC_COMP_VEDEC$$Base)
#define DCM_COMP_TARGET_SIZE4      0xE000      /* 59 KB */
#elif defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS4   ((kal_uint32)&Image$$DYNAMIC_COMP_VEENC$$Base)
#define DCM_COMP_TARGET_SIZE4      0xE000      /* 59 KB */
#else
#define DCM_COMP_TARGET_ADDRESS4   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE4      0x0
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS5   ((kal_uint32)&Image$$DYNAMIC_COMP_DAF$$Base)
#define DCM_COMP_TARGET_SIZE5      0x9000      /* 36KB */
#elif defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS5   ((kal_uint32)&Image$$DYNAMIC_COMP_WAVETABLE$$Base)
#define DCM_COMP_TARGET_SIZE5      0x9000      /* 36KB */
#else
#define DCM_COMP_TARGET_ADDRESS5   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE5      0x0
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_BROWSER$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_CALC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_CALC$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_CALLSET$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_CAMCO$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_CLNDR$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_CLOCK$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_FMRADIO$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_SOUNDSET$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_EM$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#elif defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS6   ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_FM$$Base)
#define DCM_COMP_TARGET_SIZE6      0xE800      /* 58KB */
#else
#define DCM_COMP_TARGET_ADDRESS6   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE6      0x0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS7   ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base)
#define DCM_COMP_TARGET_SIZE7      0x5000      /* 20KB */
#elif defined(DCM_COMP_SCAT_MOT_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS7   ((kal_uint32)&Image$$DYNAMIC_COMP_MOT$$Base)
#define DCM_COMP_TARGET_SIZE7      0x5000      /* 20KB */
#elif defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS7   ((kal_uint32)&Image$$DYNAMIC_COMP_SECSET$$Base)
#define DCM_COMP_TARGET_SIZE7      0x5000      /* 20KB */
#else
#define DCM_COMP_TARGET_ADDRESS7   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE7      0x0
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS8   ((kal_uint32)&Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base)
#define DCM_COMP_TARGET_SIZE8      0x5800      /* 22KB */
#elif defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS8   ((kal_uint32)&Image$$DYNAMIC_COMP_BOOTUP$$Base)
#define DCM_COMP_TARGET_SIZE8      0x5800      /* 22KB */
#elif defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS8   ((kal_uint32)&Image$$DYNAMIC_COMP_SETTING$$Base)
#define DCM_COMP_TARGET_SIZE8      0x5800      /* 22KB */
#elif defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS8   ((kal_uint32)&Image$$DYNAMIC_COMP_SOUNDREC$$Base)
#define DCM_COMP_TARGET_SIZE8      0x5800      /* 22KB */
#else
#define DCM_COMP_TARGET_ADDRESS8   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE8      0x0
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_CAMIMGV$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_VDOREC$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_CALENDAR$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_CALCULATOR$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_VDOPLY_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_VDOPLY$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_MATV_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_MATV$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_SNDREC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_SNDREC$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_PROFILE_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_PROFILE$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_CALLSETTING$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_SCRLOCK$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_SETTINGS_AVAILABLE)        
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_SETTINGS$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_DTCNT_AVAILABLE)         
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_DTCNT$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_EM_AVAILABLE)             
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_EM$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#elif defined (DCM_COMP_SCAT_FM_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS9   ((kal_uint32)&Image$$DYNAMIC_COMP_FM$$Base)
#define DCM_COMP_TARGET_SIZE9      0xA000      /* 40KB */
#else
#define DCM_COMP_TARGET_ADDRESS9   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE9      0x0
#endif


/*
 * setup target pool by code id
 * 0 : DCM with compression candidate unavailable
 * 1 : DCM with compression target pool 1
 * 2 : DCM with compression target pool 2
 * 3 : DCM with compression target pool 3
 * 4 : DCM with compression target pool 4
 * 5 : DCM with compression target pool 5
 * 6 : DCM with compression target pool 6
 * 7 : DCM with compression target pool 7
 * 8 : DCM with compression target pool 8
 */
#define DCM_COMP_TARGET_CONFIGURE  1,2,3,3,3,3,3,0,4,4,5,5,6,6,6,6,6,6,6,6,6,6,7,7,7,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
//-----------------------------------------------------------------------

#elif defined(MT6253_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;

/* dynamic code availability on scatter file */
#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__) && defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_BT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__) && defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_EFFECT__ */

#if defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

/* define target pool information */
#define DCM_COMP_TARGET_NUM        3

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#else
#define DCM_COMP_TARGET_ADDRESS1   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE1      0x0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#define DCM_COMP_TARGET_SIZE2      0x3400      /* 13KB */
#else
#define DCM_COMP_TARGET_ADDRESS2   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE2      0x0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#else
#define DCM_COMP_TARGET_ADDRESS3   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE3      0x0
#endif

/*
 * setup target pool by code id
 * 0 : DCM with compression candidate unavailable
 * 1 : DCM with compression target pool 1
 * 2 : DCM with compression target pool 2
 * 3 : DCM with compression target pool 3
 */
#define DCM_COMP_TARGET_CONFIGURE  1,2,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0


#elif defined(MT6260_SERIES_DCMGR)


/* 
 * define avaliable region according to  compile option 
 */

/* dynamic code availability on scatter file */
#if defined(__DCM_WITH_COMPRESSION_AUDIO_BT__) && defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_BT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__) && defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_EFFECT__ */


#if defined(__MPEG4_DEC_SW_SUPPORT__) && defined(__MP4_DEC_SW_SUPPORT_ASP__)
#define DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE      /* MP4ASPDEC with compression */
#elif defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ && __MP4_DEC_SW_SUPPORT_ASP__  */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

#if defined(__VP8_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_VP8DEC_AVAILABLE         /* VP8DEC with compression */
#endif /* __VP8_DEC_SW_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEENC_AVAILABLE          /* VEENC with compression */
#endif /* __MPEG4_ENC_SUPPORT__ || __MJPEG_ENC_SUPPORT__ */

#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__)
#define DCM_COMP_SCAT_VEDEC_AVAILABLE          /* VEDEC with compression */
#endif /* H264_DEC_SUPPORT__ || __MPEG4_DEC_SUPPORT__ || __MJPEG_DEC_SUPPORT__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) && defined(DAF_DECODE)
#define DCM_COMP_SCAT_DAF_AVAILABLE            /* DAF with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_CODEC__ */

#if defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) && defined(DSP_WT_SYN)
#define DCM_COMP_SCAT_WAVETABLE_AVAILABLE      /* WAVETABLE with compression  */
#endif /* __DCM_WITH_COMPRESSION_AUDIO_CODEC__ */


#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#define DCM_COMP_SCAT_BROWSER_AVAILABLE        /* BROWSER with compression  */
#define DCM_COMP_SCAT_CALC_AVAILABLE           /* CALC with compression  */
#define DCM_COMP_SCAT_CALLSET_AVAILABLE        /* CALLSET with compression  */
#define DCM_COMP_SCAT_CAMCO_AVAILABLE          /* CAMCO with compression  */
#define DCM_COMP_SCAT_CLNDR_AVAILABLE          /* CLNDR with compression  */
#define DCM_COMP_SCAT_CLOCK_AVAILABLE          /* CLOCK with compression  */
#define DCM_COMP_SCAT_FMRADIO_AVAILABLE        /* FMRADIO with compression  */
#define DCM_COMP_SCAT_SOUNDSET_AVAILABLE       /* SOUNDSET with compression  */
#define DCM_COMP_SCAT_COSMOS_EM_AVAILABLE      /* EM with compression  */
#define DCM_COMP_SCAT_COSMOS_FM_AVAILABLE      /* FM with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_B__)
#define DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE   /* DTCNT with compression  */
#define DCM_COMP_SCAT_MOT_AVAILABLE            /* MOT with compression  */
#define DCM_COMP_SCAT_SECSET_AVAILABLE         /* SECSET with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_B__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
#define DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE    /* BAIDUSEARCH with compression  */
#define DCM_COMP_SCAT_BOOTUP_AVAILABLE         /* BOOTUP with compression  */
#define DCM_COMP_SCAT_SETTING_AVAILABLE        /* SETTING with compression  */
#define DCM_COMP_SCAT_SOUNDREC_AVAILABLE       /* SOUNDREC with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_C__ */

#if defined(__DCM_WITH_COMPRESSION_MMI_AP__)
#define DCM_COMP_SCAT_CAMIMGV_AVAILABLE         /* AP CAMERA and IMGIVEW with compression  */
#define DCM_COMP_SCAT_VDOREC_AVAILABLE         /* AP VDOREC with compression  */
#define DCM_COMP_SCAT_CALENDAR_AVAILABLE          /* AP CALENDAR with compression  */
#define DCM_COMP_SCAT_CALCULATOR_AVAILABLE           /* AP CALCULATOR with compression  */
#define DCM_COMP_SCAT_VDOPLY_AVAILABLE         /* AP VDOPLY with compression  */
#define DCM_COMP_SCAT_MATV_AVAILABLE           /* AP MATV with compression  */
#define DCM_COMP_SCAT_SNDREC_AVAILABLE         /* AP SNDREC with compression  */
#define DCM_COMP_SCAT_PROFILE_AVAILABLE        /* AP PROFILE with compression  */
#define DCM_COMP_SCAT_CALLSETTING_AVAILABLE        /* AP CALLSETTING with compression  */
#define DCM_COMP_SCAT_SCRLOCK_AVAILABLE        /* AP SCRLOCK with compression  */
#define DCM_COMP_SCAT_SETTINGS_AVAILABLE        /* AP SETTING with compression  */
#define DCM_COMP_SCAT_DTCNT_AVAILABLE          /* AP DTCNT with compression  */
#define DCM_COMP_SCAT_EM_AVAILABLE             /* AP EM with compression  */
#define DCM_COMP_SCAT_FM_AVAILABLE             /* AP FM with compression  */
#endif /* __DCM_WITH_COMPRESSION_MMI_AP__ */


#if defined (__MM_DCM_SUPPORT__)

#if defined(__ATV_SUPPORT__)
#define DCM_COMP_SCAT_MATVDRIVER_AVAILABLE
#endif /* __ATV_SUPPORT__ */

#define DCM_COMP_SCAT_AMRREC_AVAILABLE
#define DCM_COMP_SCAT_WAVREC_AVAILABLE
#define DCM_COMP_SCAT_PCMREC_AVAILABLE
#define DCM_COMP_SCAT_MDP_AVAILABLE
#define DCM_COMP_SCAT_VECOM_AVAILABLE
#define DCM_COMP_SCAT_RENDER_AVAILABLE
#define DCM_COMP_SCAT_MDICAM_AVAILABLE
#define DCM_COMP_SCAT_MWREC_AVAILABLE	
#define DCM_COMP_SCAT_MDIVID_AVAILABLE
#define DCM_COMP_SCAT_VIDMSG_AVAILABLE
#define DCM_COMP_SCAT_MWWEBCAM_AVAILABLE
#define DCM_COMP_SCAT_USBVIDEO_AVAILABLE
#define DCM_COMP_SCAT_MDIMTV_AVAILABLE
#define DCM_COMP_SCAT_MEDMTV_AVAILABLE
#define DCM_COMP_SCAT_MDISTREAM_AVAILABLE
#define DCM_COMP_SCAT_MEDSTREAM_AVAILABLE
#define DCM_COMP_SCAT_CAMCAL_AVAILABLE //
#define DCM_COMP_SCAT_CAMMED_AVAILABLE

#if defined (__IMEHW_DCM_SUPPORT__)

#define DCM_COMP_SCAT_VKLAYOUT_AVAILABLE
#define DCM_COMP_SCAT_GUOBIHW_AVAILABLE
#define DCM_COMP_SCAT_IME_AVAILABLE

#endif /* __IMEHW_DCM_SUPPORT__ */

#endif /* __MM_DCM_SUPPORT__ */


/* 
 * define DCM_COMP_EXEC_REGION_XXX_ADDRESS 
 */

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ASPDEC$$Base;
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VP8DEC$$Base;
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VEENC$$Base;
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VEDEC$$Base;
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_DAF$$Base;
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_WAVETABLE$$Base;
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_BROWSER$$Base;
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CALC$$Base;
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSET$$Base;
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCO$$Base;
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CLNDR$$Base;
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CLOCK$$Base;
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_FMRADIO$$Base;
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDSET$$Base;
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_EM$$Base;
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_FM$$Base;
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base;
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MOT$$Base;
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SECSET$$Base;
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base;
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_BOOTUP$$Base;
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SETTING$$Base;
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SOUNDREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CAMIMGV$$Base;
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VDOREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CALENDAR$$Base;
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CALCULATOR$$Base;
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VDOPLY$$Base;
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MATV$$Base;
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SNDREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_PROFILE$$Base;
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CALLSETTING$$Base;
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SCRLOCK$$Base;
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_SETTINGS$$Base;
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_DTCNT$$Base;
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_EM$$Base;
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_FM$$Base;
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MATVDRIVER$$Base;
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_AMRREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_WAVREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_PCMREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MDP$$Base;
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VECOM$$Base;
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_RENDER$$Base;
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MDICAM$$Base;
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MWREC$$Base;
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MDIVID$$Base;
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VIDMSG$$Base;
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MWWEBCAM$$Base;
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_USBVIDEO$$Base;
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MDIMTV$$Base;
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MEDMTV$$Base;
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MDISTREAM$$Base;
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_MEDSTREAM$$Base;
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CAMCAL$$Base;
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_CAMMED$$Base;
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_VKLAYOUT$$Base;
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_GUOBIHW$$Base;
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
extern kal_uint32 Image$$DYNAMIC_COMP_IME$$Base;
#endif


#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SBC_ADDRESS              ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#else
#define DCM_COMP_EXEC_REGION_SBC_ADDRESS              DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_EXEC_REGION_BESLOUDNESS_ADDRESS      ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#else
#define DCM_COMP_EXEC_REGION_BESLOUDNESS_ADDRESS      DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MP4DEC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#else
#define DCM_COMP_EXEC_REGION_MP4DEC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MP4ENC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#else
#define DCM_COMP_EXEC_REGION_MP4ENC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_H264DEC_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#else
#define DCM_COMP_EXEC_REGION_H264DEC_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MP4ASPDEC_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ASPDEC$$Base)
#else
#define DCM_COMP_EXEC_REGION_MP4ASPDEC_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VP8DEC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_VP8DEC$$Base)
#else
#define DCM_COMP_EXEC_REGION_VP8DEC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MATVDRIVER_ADDRESS       ((kal_uint32)&Image$$DYNAMIC_COMP_MATVDRIVER$$Base)
#else
#define DCM_COMP_EXEC_REGION_MATVDRIVER_ADDRESS       DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VEENC_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_VEENC$$Base)
#else
#define DCM_COMP_EXEC_REGION_VEENC_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VEDEC_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_VEDEC$$Base)
#else
#define DCM_COMP_EXEC_REGION_VEDEC_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
#define DCM_COMP_EXEC_REGION_DAF_ADDRESS              ((kal_uint32)&Image$$DYNAMIC_COMP_DAF$$Base)
#else
#define DCM_COMP_EXEC_REGION_DAF_ADDRESS              DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
#define DCM_COMP_EXEC_REGION_WAVETABLE_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_WAVETABLE$$Base)
#else
#define DCM_COMP_EXEC_REGION_WAVETABLE_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
#define DCM_COMP_EXEC_REGION_BROWSER_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_BROWSER$$Base)
#else
#define DCM_COMP_EXEC_REGION_BROWSER_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CALC_ADDRESS             ((kal_uint32)&Image$$DYNAMIC_COMP_CALC$$Base)
#else
#define DCM_COMP_EXEC_REGION_CALC_ADDRESS             DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CALLSET_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_CALLSET$$Base)
#else
#define DCM_COMP_EXEC_REGION_CALLSET_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CAMCO_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_CAMCO$$Base)
#else
#define DCM_COMP_EXEC_REGION_CAMCO_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CLNDR_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_CLNDR$$Base)
#else
#define DCM_COMP_EXEC_REGION_CLNDR_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CLOCK_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_CLOCK$$Base)
#else
#define DCM_COMP_EXEC_REGION_CLOCK_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
#define DCM_COMP_EXEC_REGION_FMRADIO_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_FMRADIO$$Base)
#else
#define DCM_COMP_EXEC_REGION_FMRADIO_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SOUNDSET_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_SOUNDSET$$Base)
#else
#define DCM_COMP_EXEC_REGION_SOUNDSET_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_COSMOS_EM_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_EM$$Base)
#else
#define DCM_COMP_EXEC_REGION_COSMOS_EM_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_COSMOS_FM_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_FM$$Base)
#else
#define DCM_COMP_EXEC_REGION_COSMOS_FM_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
#define DCM_COMP_EXEC_REGION_COSMOS_DTCNT_ADDRESS     ((kal_uint32)&Image$$DYNAMIC_COMP_COSMOS_DTCNT$$Base)
#else
#define DCM_COMP_EXEC_REGION_COSMOS_DTCNT_ADDRESS     DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MOT_ADDRESS              ((kal_uint32)&Image$$DYNAMIC_COMP_MOT$$Base)
#else
#define DCM_COMP_EXEC_REGION_MOT_ADDRESS              DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SECSET_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_SECSET$$Base)
#else
#define DCM_COMP_EXEC_REGION_SECSET_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
#define DCM_COMP_EXEC_REGION_BAIDUSEARCH_ADDRESS      ((kal_uint32)&Image$$DYNAMIC_COMP_BAIDUSEARCH$$Base)
#else
#define DCM_COMP_EXEC_REGION_BAIDUSEARCH_ADDRESS      DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
#define DCM_COMP_EXEC_REGION_BOOTUP_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_BOOTUP$$Base)
#else
#define DCM_COMP_EXEC_REGION_BOOTUP_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SETTING_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_SETTING$$Base)
#else
#define DCM_COMP_EXEC_REGION_SETTING_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SOUNDREC_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_SOUNDREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_SOUNDREC_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CAMIMGV_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_CAMIMGV$$Base)
#else
#define DCM_COMP_EXEC_REGION_CAMIMGV_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VDOREC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_VDOREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_VDOREC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CALENDAR_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_CALENDAR$$Base)
#else
#define DCM_COMP_EXEC_REGION_CALENDAR_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CALCULATOR_ADDRESS       ((kal_uint32)&Image$$DYNAMIC_COMP_CALCULATOR$$Base)
#else
#define DCM_COMP_EXEC_REGION_CALCULATOR_ADDRESS       DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VDOPLY_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_VDOPLY$$Base)
#else
#define DCM_COMP_EXEC_REGION_VDOPLY_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MATV_ADDRESS             ((kal_uint32)&Image$$DYNAMIC_COMP_MATV$$Base)
#else
#define DCM_COMP_EXEC_REGION_MATV_ADDRESS             DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SNDREC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_SNDREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_SNDREC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
#define DCM_COMP_EXEC_REGION_PROFILE_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_PROFILE$$Base)
#else
#define DCM_COMP_EXEC_REGION_PROFILE_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CALLSETTING_ADDRESS      ((kal_uint32)&Image$$DYNAMIC_COMP_CALLSETTING$$Base)
#else
#define DCM_COMP_EXEC_REGION_CALLSETTING_ADDRESS      DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SCRLOCK_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_SCRLOCK$$Base)
#else
#define DCM_COMP_EXEC_REGION_SCRLOCK_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
#define DCM_COMP_EXEC_REGION_SETTINGS_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_SETTINGS$$Base)
#else
#define DCM_COMP_EXEC_REGION_SETTINGS_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
#define DCM_COMP_EXEC_REGION_DTCNT_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_DTCNT$$Base)
#else
#define DCM_COMP_EXEC_REGION_DTCNT_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_EM_ADDRESS               ((kal_uint32)&Image$$DYNAMIC_COMP_EM$$Base)
#else
#define DCM_COMP_EXEC_REGION_EM_ADDRESS               DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_FM_ADDRESS               ((kal_uint32)&Image$$DYNAMIC_COMP_FM$$Base)
#else
#define DCM_COMP_EXEC_REGION_FM_ADDRESS               DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_AMRREC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_AMRREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_AMRREC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_WAVREC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_WAVREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_WAVREC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_PCMREC_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_PCMREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_PCMREC_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MDP_ADDRESS              ((kal_uint32)&Image$$DYNAMIC_COMP_MDP$$Base)
#else
#define DCM_COMP_EXEC_REGION_MDP_ADDRESS              DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VECOM_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_VECOM$$Base)
#else
#define DCM_COMP_EXEC_REGION_VECOM_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
#define DCM_COMP_EXEC_REGION_RENDER_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_RENDER$$Base)
#else
#define DCM_COMP_EXEC_REGION_RENDER_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MDICAM_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MDICAM$$Base)
#else
#define DCM_COMP_EXEC_REGION_MDICAM_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MWREC_ADDRESS            ((kal_uint32)&Image$$DYNAMIC_COMP_MWREC$$Base)
#else
#define DCM_COMP_EXEC_REGION_MWREC_ADDRESS            DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MDIVID_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MDIVID$$Base)
#else
#define DCM_COMP_EXEC_REGION_MDIVID_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VIDMSG_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_VIDMSG$$Base)
#else
#define DCM_COMP_EXEC_REGION_VIDMSG_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MWWEBCAM_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_MWWEBCAM$$Base)
#else
#define DCM_COMP_EXEC_REGION_MWWEBCAM_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
#define DCM_COMP_EXEC_REGION_USBVIDEO_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_USBVIDEO$$Base)
#else
#define DCM_COMP_EXEC_REGION_USBVIDEO_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MDIMTV_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MDIMTV$$Base)
#else
#define DCM_COMP_EXEC_REGION_MDIMTV_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MEDMTV_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_MEDMTV$$Base)
#else
#define DCM_COMP_EXEC_REGION_MEDMTV_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MDISTREAM_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_MDISTREAM$$Base)
#else
#define DCM_COMP_EXEC_REGION_MDISTREAM_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
#define DCM_COMP_EXEC_REGION_MEDSTREAM_ADDRESS        ((kal_uint32)&Image$$DYNAMIC_COMP_MEDSTREAM$$Base)
#else
#define DCM_COMP_EXEC_REGION_MEDSTREAM_ADDRESS        DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CAMCAL_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_CAMCAL$$Base)
#else
#define DCM_COMP_EXEC_REGION_CAMCAL_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
#define DCM_COMP_EXEC_REGION_CAMMED_ADDRESS           ((kal_uint32)&Image$$DYNAMIC_COMP_CAMMED$$Base)
#else
#define DCM_COMP_EXEC_REGION_CAMMED_ADDRESS           DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
#define DCM_COMP_EXEC_REGION_VKLAYOUT_ADDRESS         ((kal_uint32)&Image$$DYNAMIC_COMP_VKLAYOUT$$Base)
#else
#define DCM_COMP_EXEC_REGION_VKLAYOUT_ADDRESS         DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
#define DCM_COMP_EXEC_REGION_GUOBIHW_ADDRESS          ((kal_uint32)&Image$$DYNAMIC_COMP_GUOBIHW$$Base)
#else
#define DCM_COMP_EXEC_REGION_GUOBIHW_ADDRESS          DCMGR_INVALID_VAL
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
#define DCM_COMP_EXEC_REGION_IME_ADDRESS              ((kal_uint32)&Image$$DYNAMIC_COMP_IME$$Base)
#else
#define DCM_COMP_EXEC_REGION_IME_ADDRESS              DCMGR_INVALID_VAL
#endif

/*
 * Start pool and group configuration 
 */

#ifndef __MM_DCM_SUPPORT__

#define DCM_COMP_TARGET_NUM         9
#define DCM_COMP_GROUP_NUM          42


#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_SBC_TARGET          1
#define DCM_COMP_SBC_GROUP           1
#else
#define DCM_COMP_SBC_TARGET          0
#define DCM_COMP_SBC_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_BESLOUDNESS_TARGET  2
#define DCM_COMP_BESLOUDNESS_GROUP   2
#else
#define DCM_COMP_BESLOUDNESS_TARGET  0
#define DCM_COMP_BESLOUDNESS_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_MP4DEC_TARGET       3
#define DCM_COMP_MP4DEC_GROUP        3
#else
#define DCM_COMP_MP4DEC_TARGET       0
#define DCM_COMP_MP4DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_MP4ENC_TARGET       3
#define DCM_COMP_MP4ENC_GROUP        4
#else
#define DCM_COMP_MP4ENC_TARGET       0
#define DCM_COMP_MP4ENC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_H264DEC_TARGET      3
#define DCM_COMP_H264DEC_GROUP       5
#else
#define DCM_COMP_H264DEC_TARGET      0
#define DCM_COMP_H264DEC_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
#define DCM_COMP_MP4ASPDEC_TARGET    3
#define DCM_COMP_MP4ASPDEC_GROUP     6
#else
#define DCM_COMP_MP4ASPDEC_TARGET    0
#define DCM_COMP_MP4ASPDEC_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
#define DCM_COMP_VP8DEC_TARGET       3
#define DCM_COMP_VP8DEC_GROUP        7
#else
#define DCM_COMP_VP8DEC_TARGET       0
#define DCM_COMP_VP8DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
#define DCM_COMP_MATVDRIVER_TARGET   0
#define DCM_COMP_MATVDRIVER_GROUP    0
#else
#define DCM_COMP_MATVDRIVER_TARGET   0
#define DCM_COMP_MATVDRIVER_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_VEENC_TARGET        4
#define DCM_COMP_VEENC_GROUP         8
#else
#define DCM_COMP_VEENC_TARGET        0
#define DCM_COMP_VEENC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_VEDEC_TARGET        4
#define DCM_COMP_VEDEC_GROUP         9
#else
#define DCM_COMP_VEDEC_TARGET        0
#define DCM_COMP_VEDEC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
#define DCM_COMP_DAF_TARGET          5
#define DCM_COMP_DAF_GROUP           10
#else
#define DCM_COMP_DAF_TARGET          0
#define DCM_COMP_DAF_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
#define DCM_COMP_WAVETABLE_TARGET    5
#define DCM_COMP_WAVETABLE_GROUP     11
#else
#define DCM_COMP_WAVETABLE_TARGET    0
#define DCM_COMP_WAVETABLE_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
#define DCM_COMP_BROWSER_TARGET      6
#define DCM_COMP_BROWSER_GROUP       12
#else
#define DCM_COMP_BROWSER_TARGET      0
#define DCM_COMP_BROWSER_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
#define DCM_COMP_CALC_TARGET         6
#define DCM_COMP_CALC_GROUP          13
#else
#define DCM_COMP_CALC_TARGET         0
#define DCM_COMP_CALC_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
#define DCM_COMP_CALLSET_TARGET      6
#define DCM_COMP_CALLSET_GROUP       14
#else
#define DCM_COMP_CALLSET_TARGET      0
#define DCM_COMP_CALLSET_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
#define DCM_COMP_CAMCO_TARGET        6
#define DCM_COMP_CAMCO_GROUP         15
#else
#define DCM_COMP_CAMCO_TARGET        0
#define DCM_COMP_CAMCO_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
#define DCM_COMP_CLNDR_TARGET        6
#define DCM_COMP_CLNDR_GROUP         16
#else
#define DCM_COMP_CLNDR_TARGET        0
#define DCM_COMP_CLNDR_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
#define DCM_COMP_CLOCK_TARGET        6
#define DCM_COMP_CLOCK_GROUP         17
#else
#define DCM_COMP_CLOCK_TARGET        0
#define DCM_COMP_CLOCK_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
#define DCM_COMP_FMRADIO_TARGET      6
#define DCM_COMP_FMRADIO_GROUP       18
#else
#define DCM_COMP_FMRADIO_TARGET      0
#define DCM_COMP_FMRADIO_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
#define DCM_COMP_SOUNDSET_TARGET     6
#define DCM_COMP_SOUNDSET_GROUP      19
#else
#define DCM_COMP_SOUNDSET_TARGET     0
#define DCM_COMP_SOUNDSET_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
#define DCM_COMP_COSMOS_EM_TARGET    6
#define DCM_COMP_COSMOS_EM_GROUP     20
#else
#define DCM_COMP_COSMOS_EM_TARGET    0
#define DCM_COMP_COSMOS_EM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
#define DCM_COMP_COSMOS_FM_TARGET    6
#define DCM_COMP_COSMOS_FM_GROUP     21
#else
#define DCM_COMP_COSMOS_FM_TARGET    0
#define DCM_COMP_COSMOS_FM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
#define DCM_COMP_COSMOS_DTCNT_TARGET 7
#define DCM_COMP_COSMOS_DTCNT_GROUP  22
#else
#define DCM_COMP_COSMOS_DTCNT_TARGET 0
#define DCM_COMP_COSMOS_DTCNT_GROUP  0
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
#define DCM_COMP_MOT_TARGET          7
#define DCM_COMP_MOT_GROUP           23
#else
#define DCM_COMP_MOT_TARGET          0
#define DCM_COMP_MOT_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
#define DCM_COMP_SECSET_TARGET       7
#define DCM_COMP_SECSET_GROUP        24
#else
#define DCM_COMP_SECSET_TARGET       0
#define DCM_COMP_SECSET_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
#define DCM_COMP_BAIDUSEARCH_TARGET  8
#define DCM_COMP_BAIDUSEARCH_GROUP   25
#else
#define DCM_COMP_BAIDUSEARCH_TARGET  0
#define DCM_COMP_BAIDUSEARCH_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
#define DCM_COMP_BOOTUP_TARGET       8
#define DCM_COMP_BOOTUP_GROUP        26
#else
#define DCM_COMP_BOOTUP_TARGET       0
#define DCM_COMP_BOOTUP_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
#define DCM_COMP_SETTING_TARGET      8
#define DCM_COMP_SETTING_GROUP       27
#else
#define DCM_COMP_SETTING_TARGET      0
#define DCM_COMP_SETTING_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
#define DCM_COMP_SOUNDREC_TARGET     8
#define DCM_COMP_SOUNDREC_GROUP      28
#else
#define DCM_COMP_SOUNDREC_TARGET     0
#define DCM_COMP_SOUNDREC_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
#define DCM_COMP_CAMIMGV_TARGET      9
#define DCM_COMP_CAMIMGV_GROUP       29
#else
#define DCM_COMP_CAMIMGV_TARGET      0
#define DCM_COMP_CAMIMGV_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
#define DCM_COMP_VDOREC_TARGET       9
#define DCM_COMP_VDOREC_GROUP        30
#else
#define DCM_COMP_VDOREC_TARGET       0
#define DCM_COMP_VDOREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
#define DCM_COMP_CALENDAR_TARGET     9
#define DCM_COMP_CALENDAR_GROUP      31
#else
#define DCM_COMP_CALENDAR_TARGET     0
#define DCM_COMP_CALENDAR_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
#define DCM_COMP_CALCULATOR_TARGET   9
#define DCM_COMP_CALCULATOR_GROUP    32
#else
#define DCM_COMP_CALCULATOR_TARGET   0
#define DCM_COMP_CALCULATOR_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
#define DCM_COMP_VDOPLY_TARGET       9
#define DCM_COMP_VDOPLY_GROUP        33
#else
#define DCM_COMP_VDOPLY_TARGET       0
#define DCM_COMP_VDOPLY_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
#define DCM_COMP_MATV_TARGET         9
#define DCM_COMP_MATV_GROUP          34
#else
#define DCM_COMP_MATV_TARGET         0
#define DCM_COMP_MATV_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
#define DCM_COMP_SNDREC_TARGET       9
#define DCM_COMP_SNDREC_GROUP        35
#else
#define DCM_COMP_SNDREC_TARGET       0
#define DCM_COMP_SNDREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
#define DCM_COMP_PROFILE_TARGET      9
#define DCM_COMP_PROFILE_GROUP       36
#else
#define DCM_COMP_PROFILE_TARGET      0
#define DCM_COMP_PROFILE_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
#define DCM_COMP_CALLSETTING_TARGET  9
#define DCM_COMP_CALLSETTING_GROUP   37
#else
#define DCM_COMP_CALLSETTING_TARGET  0
#define DCM_COMP_CALLSETTING_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
#define DCM_COMP_SCRLOCK_TARGET      9
#define DCM_COMP_SCRLOCK_GROUP       38
#else
#define DCM_COMP_SCRLOCK_TARGET      0
#define DCM_COMP_SCRLOCK_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
#define DCM_COMP_SETTINGS_TARGET     9
#define DCM_COMP_SETTINGS_GROUP      39
#else
#define DCM_COMP_SETTINGS_TARGET     0
#define DCM_COMP_SETTINGS_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
#define DCM_COMP_DTCNT_TARGET        9
#define DCM_COMP_DTCNT_GROUP         40
#else
#define DCM_COMP_DTCNT_TARGET        0
#define DCM_COMP_DTCNT_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
#define DCM_COMP_EM_TARGET           9
#define DCM_COMP_EM_GROUP            41
#else
#define DCM_COMP_EM_TARGET           0
#define DCM_COMP_EM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
#define DCM_COMP_FM_TARGET           9
#define DCM_COMP_FM_GROUP            42
#else
#define DCM_COMP_FM_TARGET           0
#define DCM_COMP_FM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
#define DCM_COMP_AMRREC_TARGET       0
#define DCM_COMP_AMRREC_GROUP        0
#else
#define DCM_COMP_AMRREC_TARGET       0
#define DCM_COMP_AMRREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
#define DCM_COMP_WAVREC_TARGET       0
#define DCM_COMP_WAVREC_GROUP        0
#else
#define DCM_COMP_WAVREC_TARGET       0
#define DCM_COMP_WAVREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
#define DCM_COMP_PCMREC_TARGET       0
#define DCM_COMP_PCMREC_GROUP        0
#else
#define DCM_COMP_PCMREC_TARGET       0
#define DCM_COMP_PCMREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
#define DCM_COMP_MDP_TARGET          0
#define DCM_COMP_MDP_GROUP           0
#else
#define DCM_COMP_MDP_TARGET          0
#define DCM_COMP_MDP_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
#define DCM_COMP_VECOM_TARGET        0
#define DCM_COMP_VECOM_GROUP         0
#else
#define DCM_COMP_VECOM_TARGET        0
#define DCM_COMP_VECOM_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
#define DCM_COMP_RENDER_TARGET       0
#define DCM_COMP_RENDER_GROUP        0
#else
#define DCM_COMP_RENDER_TARGET       0
#define DCM_COMP_RENDER_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
#define DCM_COMP_MDICAM_TARGET       0
#define DCM_COMP_MDICAM_GROUP        0
#else
#define DCM_COMP_MDICAM_TARGET       0
#define DCM_COMP_MDICAM_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
#define DCM_COMP_MWREC_TARGET        0
#define DCM_COMP_MWREC_GROUP         0
#else
#define DCM_COMP_MWREC_TARGET        0
#define DCM_COMP_MWREC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
#define DCM_COMP_MDIVID_TARGET       0
#define DCM_COMP_MDIVID_GROUP        0
#else
#define DCM_COMP_MDIVID_TARGET       0
#define DCM_COMP_MDIVID_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
#define DCM_COMP_VIDMSG_TARGET       0
#define DCM_COMP_VIDMSG_GROUP        0
#else
#define DCM_COMP_VIDMSG_TARGET       0
#define DCM_COMP_VIDMSG_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
#define DCM_COMP_MWWEBCAM_TARGET     0
#define DCM_COMP_MWWEBCAM_GROUP      0
#else
#define DCM_COMP_MWWEBCAM_TARGET     0
#define DCM_COMP_MWWEBCAM_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
#define DCM_COMP_USBVIDEO_TARGET     0
#define DCM_COMP_USBVIDEO_GROUP      0
#else
#define DCM_COMP_USBVIDEO_TARGET     0
#define DCM_COMP_USBVIDEO_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
#define DCM_COMP_MDIMTV_TARGET       0
#define DCM_COMP_MDIMTV_GROUP        0
#else
#define DCM_COMP_MDIMTV_TARGET       0
#define DCM_COMP_MDIMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
#define DCM_COMP_MEDMTV_TARGET       0
#define DCM_COMP_MEDMTV_GROUP        0
#else
#define DCM_COMP_MEDMTV_TARGET       0
#define DCM_COMP_MEDMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
#define DCM_COMP_MDISTREAM_TARGET    0
#define DCM_COMP_MDISTREAM_GROUP     0
#else
#define DCM_COMP_MDISTREAM_TARGET    0
#define DCM_COMP_MDISTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
#define DCM_COMP_MEDSTREAM_TARGET    0
#define DCM_COMP_MEDSTREAM_GROUP     0
#else
#define DCM_COMP_MEDSTREAM_TARGET    0
#define DCM_COMP_MEDSTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
#define DCM_COMP_CAMCAL_TARGET       0
#define DCM_COMP_CAMCAL_GROUP        0
#else
#define DCM_COMP_CAMCAL_TARGET       0
#define DCM_COMP_CAMCAL_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
#define DCM_COMP_CAMMED_TARGET       0
#define DCM_COMP_CAMMED_GROUP        0
#else
#define DCM_COMP_CAMMED_TARGET       0
#define DCM_COMP_CAMMED_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
#define DCM_COMP_VKLAYOUT_TARGET     0
#define DCM_COMP_VKLAYOUT_GROUP      0
#else
#define DCM_COMP_VKLAYOUT_TARGET     0
#define DCM_COMP_VKLAYOUT_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
#define DCM_COMP_GUOBIHW_TARGET      0
#define DCM_COMP_GUOBIHW_GROUP       0
#else
#define DCM_COMP_GUOBIHW_TARGET      0
#define DCM_COMP_GUOBIHW_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
#define DCM_COMP_IME_TARGET          0
#define DCM_COMP_IME_GROUP           0
#else
#define DCM_COMP_IME_TARGET          0
#define DCM_COMP_IME_GROUP           0
#endif


#else /* __MM_DCM_SUPPORT__ */

#ifndef __IMEHW_DCM_SUPPORT__


#define DCM_COMP_TARGET_NUM         14
#define DCM_COMP_GROUP_NUM          54


#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_SBC_TARGET          1
#define DCM_COMP_SBC_GROUP           1
#else
#define DCM_COMP_SBC_TARGET          0
#define DCM_COMP_SBC_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_BESLOUDNESS_TARGET  2
#define DCM_COMP_BESLOUDNESS_GROUP   2
#else
#define DCM_COMP_BESLOUDNESS_TARGET  0
#define DCM_COMP_BESLOUDNESS_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_MP4DEC_TARGET       3
#define DCM_COMP_MP4DEC_GROUP        3
#else
#define DCM_COMP_MP4DEC_TARGET       0
#define DCM_COMP_MP4DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_MP4ENC_TARGET       3
#define DCM_COMP_MP4ENC_GROUP        4
#else
#define DCM_COMP_MP4ENC_TARGET       0
#define DCM_COMP_MP4ENC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_H264DEC_TARGET      3
#define DCM_COMP_H264DEC_GROUP       5
#else
#define DCM_COMP_H264DEC_TARGET      0
#define DCM_COMP_H264DEC_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
#define DCM_COMP_MP4ASPDEC_TARGET    3
#define DCM_COMP_MP4ASPDEC_GROUP     6
#else
#define DCM_COMP_MP4ASPDEC_TARGET    0
#define DCM_COMP_MP4ASPDEC_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
#define DCM_COMP_VP8DEC_TARGET       3
#define DCM_COMP_VP8DEC_GROUP        7
#else
#define DCM_COMP_VP8DEC_TARGET       0
#define DCM_COMP_VP8DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
#define DCM_COMP_MATVDRIVER_TARGET   3
#define DCM_COMP_MATVDRIVER_GROUP    8
#else
#define DCM_COMP_MATVDRIVER_TARGET   0
#define DCM_COMP_MATVDRIVER_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_VEENC_TARGET        4
#define DCM_COMP_VEENC_GROUP         9
#else
#define DCM_COMP_VEENC_TARGET        0
#define DCM_COMP_VEENC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_VEDEC_TARGET        4
#define DCM_COMP_VEDEC_GROUP         10
#else
#define DCM_COMP_VEDEC_TARGET        0
#define DCM_COMP_VEDEC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
#define DCM_COMP_DAF_TARGET          5
#define DCM_COMP_DAF_GROUP           11
#else
#define DCM_COMP_DAF_TARGET          0
#define DCM_COMP_DAF_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
#define DCM_COMP_WAVETABLE_TARGET    5
#define DCM_COMP_WAVETABLE_GROUP     12
#else
#define DCM_COMP_WAVETABLE_TARGET    0
#define DCM_COMP_WAVETABLE_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
#define DCM_COMP_BROWSER_TARGET      6
#define DCM_COMP_BROWSER_GROUP       13
#else
#define DCM_COMP_BROWSER_TARGET      0
#define DCM_COMP_BROWSER_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
#define DCM_COMP_CALC_TARGET         6
#define DCM_COMP_CALC_GROUP          14
#else
#define DCM_COMP_CALC_TARGET         0
#define DCM_COMP_CALC_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
#define DCM_COMP_CALLSET_TARGET      6
#define DCM_COMP_CALLSET_GROUP       15
#else
#define DCM_COMP_CALLSET_TARGET      0
#define DCM_COMP_CALLSET_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
#define DCM_COMP_CAMCO_TARGET        6
#define DCM_COMP_CAMCO_GROUP         16
#else
#define DCM_COMP_CAMCO_TARGET        0
#define DCM_COMP_CAMCO_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
#define DCM_COMP_CLNDR_TARGET        6
#define DCM_COMP_CLNDR_GROUP         17
#else
#define DCM_COMP_CLNDR_TARGET        0
#define DCM_COMP_CLNDR_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
#define DCM_COMP_CLOCK_TARGET        6
#define DCM_COMP_CLOCK_GROUP         18
#else
#define DCM_COMP_CLOCK_TARGET        0
#define DCM_COMP_CLOCK_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
#define DCM_COMP_FMRADIO_TARGET      6
#define DCM_COMP_FMRADIO_GROUP       19
#else
#define DCM_COMP_FMRADIO_TARGET      0
#define DCM_COMP_FMRADIO_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
#define DCM_COMP_SOUNDSET_TARGET     6
#define DCM_COMP_SOUNDSET_GROUP      20
#else
#define DCM_COMP_SOUNDSET_TARGET     0
#define DCM_COMP_SOUNDSET_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
#define DCM_COMP_COSMOS_EM_TARGET    6
#define DCM_COMP_COSMOS_EM_GROUP     21
#else
#define DCM_COMP_COSMOS_EM_TARGET    0
#define DCM_COMP_COSMOS_EM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
#define DCM_COMP_COSMOS_FM_TARGET    6
#define DCM_COMP_COSMOS_FM_GROUP     22
#else
#define DCM_COMP_COSMOS_FM_TARGET    0
#define DCM_COMP_COSMOS_FM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
#define DCM_COMP_COSMOS_DTCNT_TARGET 7
#define DCM_COMP_COSMOS_DTCNT_GROUP  23
#else
#define DCM_COMP_COSMOS_DTCNT_TARGET 0
#define DCM_COMP_COSMOS_DTCNT_GROUP  0
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
#define DCM_COMP_MOT_TARGET          7
#define DCM_COMP_MOT_GROUP           24
#else
#define DCM_COMP_MOT_TARGET          0
#define DCM_COMP_MOT_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
#define DCM_COMP_SECSET_TARGET       7
#define DCM_COMP_SECSET_GROUP        25
#else
#define DCM_COMP_SECSET_TARGET       0
#define DCM_COMP_SECSET_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
#define DCM_COMP_BAIDUSEARCH_TARGET  8
#define DCM_COMP_BAIDUSEARCH_GROUP   26
#else
#define DCM_COMP_BAIDUSEARCH_TARGET  0
#define DCM_COMP_BAIDUSEARCH_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
#define DCM_COMP_BOOTUP_TARGET       8
#define DCM_COMP_BOOTUP_GROUP        27
#else
#define DCM_COMP_BOOTUP_TARGET       0
#define DCM_COMP_BOOTUP_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
#define DCM_COMP_SETTING_TARGET      8
#define DCM_COMP_SETTING_GROUP       28
#else
#define DCM_COMP_SETTING_TARGET      0
#define DCM_COMP_SETTING_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
#define DCM_COMP_SOUNDREC_TARGET     8
#define DCM_COMP_SOUNDREC_GROUP      29
#else
#define DCM_COMP_SOUNDREC_TARGET     0
#define DCM_COMP_SOUNDREC_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
#define DCM_COMP_CAMIMGV_TARGET      9
#define DCM_COMP_CAMIMGV_GROUP       30
#else
#define DCM_COMP_CAMIMGV_TARGET      0
#define DCM_COMP_CAMIMGV_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
#define DCM_COMP_VDOREC_TARGET       9
#define DCM_COMP_VDOREC_GROUP        31
#else
#define DCM_COMP_VDOREC_TARGET       0
#define DCM_COMP_VDOREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
#define DCM_COMP_CALENDAR_TARGET     9
#define DCM_COMP_CALENDAR_GROUP      32
#else
#define DCM_COMP_CALENDAR_TARGET     0
#define DCM_COMP_CALENDAR_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
#define DCM_COMP_CALCULATOR_TARGET   9
#define DCM_COMP_CALCULATOR_GROUP    33
#else
#define DCM_COMP_CALCULATOR_TARGET   0
#define DCM_COMP_CALCULATOR_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
#define DCM_COMP_VDOPLY_TARGET       9
#define DCM_COMP_VDOPLY_GROUP        34
#else
#define DCM_COMP_VDOPLY_TARGET       0
#define DCM_COMP_VDOPLY_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
#define DCM_COMP_MATV_TARGET         9
#define DCM_COMP_MATV_GROUP          35
#else
#define DCM_COMP_MATV_TARGET         0
#define DCM_COMP_MATV_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
#define DCM_COMP_SNDREC_TARGET       9
#define DCM_COMP_SNDREC_GROUP        36
#else
#define DCM_COMP_SNDREC_TARGET       0
#define DCM_COMP_SNDREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
#define DCM_COMP_PROFILE_TARGET      9
#define DCM_COMP_PROFILE_GROUP       37
#else
#define DCM_COMP_PROFILE_TARGET      0
#define DCM_COMP_PROFILE_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
#define DCM_COMP_CALLSETTING_TARGET  9
#define DCM_COMP_CALLSETTING_GROUP   38
#else
#define DCM_COMP_CALLSETTING_TARGET  0
#define DCM_COMP_CALLSETTING_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
#define DCM_COMP_SCRLOCK_TARGET      9
#define DCM_COMP_SCRLOCK_GROUP       39
#else
#define DCM_COMP_SCRLOCK_TARGET      0
#define DCM_COMP_SCRLOCK_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
#define DCM_COMP_SETTINGS_TARGET     9
#define DCM_COMP_SETTINGS_GROUP      40
#else
#define DCM_COMP_SETTINGS_TARGET     0
#define DCM_COMP_SETTINGS_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
#define DCM_COMP_DTCNT_TARGET        9
#define DCM_COMP_DTCNT_GROUP         41
#else
#define DCM_COMP_DTCNT_TARGET        0
#define DCM_COMP_DTCNT_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
#define DCM_COMP_EM_TARGET           9
#define DCM_COMP_EM_GROUP            42
#else
#define DCM_COMP_EM_TARGET           0
#define DCM_COMP_EM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
#define DCM_COMP_FM_TARGET           9
#define DCM_COMP_FM_GROUP            43
#else
#define DCM_COMP_FM_TARGET           0
#define DCM_COMP_FM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
#define DCM_COMP_AMRREC_TARGET       10
#define DCM_COMP_AMRREC_GROUP        44
#else
#define DCM_COMP_AMRREC_TARGET       0
#define DCM_COMP_AMRREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
#define DCM_COMP_WAVREC_TARGET       10
#define DCM_COMP_WAVREC_GROUP        45
#else
#define DCM_COMP_WAVREC_TARGET       0
#define DCM_COMP_WAVREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
#define DCM_COMP_PCMREC_TARGET       10
#define DCM_COMP_PCMREC_GROUP        46
#else
#define DCM_COMP_PCMREC_TARGET       0
#define DCM_COMP_PCMREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
#define DCM_COMP_MDP_TARGET          11
#define DCM_COMP_MDP_GROUP           47
#else
#define DCM_COMP_MDP_TARGET          0
#define DCM_COMP_MDP_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
#define DCM_COMP_VECOM_TARGET        12
#define DCM_COMP_VECOM_GROUP         48
#else
#define DCM_COMP_VECOM_TARGET        0
#define DCM_COMP_VECOM_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
#define DCM_COMP_RENDER_TARGET       12
#define DCM_COMP_RENDER_GROUP        48
#else
#define DCM_COMP_RENDER_TARGET       0
#define DCM_COMP_RENDER_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
#define DCM_COMP_MDICAM_TARGET       13
#define DCM_COMP_MDICAM_GROUP        49
#else
#define DCM_COMP_MDICAM_TARGET       0
#define DCM_COMP_MDICAM_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
#define DCM_COMP_MWREC_TARGET        13
#define DCM_COMP_MWREC_GROUP         50
#else
#define DCM_COMP_MWREC_TARGET        0
#define DCM_COMP_MWREC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
#define DCM_COMP_MDIVID_TARGET       13
#define DCM_COMP_MDIVID_GROUP        50
#else
#define DCM_COMP_MDIVID_TARGET       0
#define DCM_COMP_MDIVID_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
#define DCM_COMP_VIDMSG_TARGET       13
#define DCM_COMP_VIDMSG_GROUP        50
#else
#define DCM_COMP_VIDMSG_TARGET       0
#define DCM_COMP_VIDMSG_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
#define DCM_COMP_MWWEBCAM_TARGET     13
#define DCM_COMP_MWWEBCAM_GROUP      51
#else
#define DCM_COMP_MWWEBCAM_TARGET     0
#define DCM_COMP_MWWEBCAM_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
#define DCM_COMP_USBVIDEO_TARGET     13
#define DCM_COMP_USBVIDEO_GROUP      51
#else
#define DCM_COMP_USBVIDEO_TARGET     0
#define DCM_COMP_USBVIDEO_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
#define DCM_COMP_MDIMTV_TARGET       13
#define DCM_COMP_MDIMTV_GROUP        52
#else
#define DCM_COMP_MDIMTV_TARGET       0
#define DCM_COMP_MDIMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
#define DCM_COMP_MEDMTV_TARGET       13
#define DCM_COMP_MEDMTV_GROUP        52
#else
#define DCM_COMP_MEDMTV_TARGET       0
#define DCM_COMP_MEDMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
#define DCM_COMP_MDISTREAM_TARGET    13
#define DCM_COMP_MDISTREAM_GROUP     53
#else
#define DCM_COMP_MDISTREAM_TARGET    0
#define DCM_COMP_MDISTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
#define DCM_COMP_MEDSTREAM_TARGET    13
#define DCM_COMP_MEDSTREAM_GROUP     53
#else
#define DCM_COMP_MEDSTREAM_TARGET    0
#define DCM_COMP_MEDSTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
#define DCM_COMP_CAMCAL_TARGET       14
#define DCM_COMP_CAMCAL_GROUP        54
#else
#define DCM_COMP_CAMCAL_TARGET       0
#define DCM_COMP_CAMCAL_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
#define DCM_COMP_CAMMED_TARGET       14
#define DCM_COMP_CAMMED_GROUP        54
#else
#define DCM_COMP_CAMMED_TARGET       0
#define DCM_COMP_CAMMED_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
#define DCM_COMP_VKLAYOUT_TARGET     0
#define DCM_COMP_VKLAYOUT_GROUP      0
#else
#define DCM_COMP_VKLAYOUT_TARGET     0
#define DCM_COMP_VKLAYOUT_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
#define DCM_COMP_GUOBIHW_TARGET      0
#define DCM_COMP_GUOBIHW_GROUP       0
#else
#define DCM_COMP_GUOBIHW_TARGET      0
#define DCM_COMP_GUOBIHW_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
#define DCM_COMP_IME_TARGET          0
#define DCM_COMP_IME_GROUP           0
#else
#define DCM_COMP_IME_TARGET          0
#define DCM_COMP_IME_GROUP           0
#endif


#else /* __IMEHW_DCM_SUPPORT__ */

#define DCM_COMP_TARGET_NUM         11
#define DCM_COMP_GROUP_NUM          48


#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_SBC_TARGET          1
#define DCM_COMP_SBC_GROUP           1
#else
#define DCM_COMP_SBC_TARGET          0
#define DCM_COMP_SBC_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_BESLOUDNESS_TARGET  2
#define DCM_COMP_BESLOUDNESS_GROUP   2
#else
#define DCM_COMP_BESLOUDNESS_TARGET  0
#define DCM_COMP_BESLOUDNESS_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_MP4DEC_TARGET       3
#define DCM_COMP_MP4DEC_GROUP        3
#else
#define DCM_COMP_MP4DEC_TARGET       0
#define DCM_COMP_MP4DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_MP4ENC_TARGET       3
#define DCM_COMP_MP4ENC_GROUP        4
#else
#define DCM_COMP_MP4ENC_TARGET       0
#define DCM_COMP_MP4ENC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_H264DEC_TARGET      3
#define DCM_COMP_H264DEC_GROUP       5
#else
#define DCM_COMP_H264DEC_TARGET      0
#define DCM_COMP_H264DEC_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_MP4ASPDEC_AVAILABLE)
#define DCM_COMP_MP4ASPDEC_TARGET    3
#define DCM_COMP_MP4ASPDEC_GROUP     6
#else
#define DCM_COMP_MP4ASPDEC_TARGET    0
#define DCM_COMP_MP4ASPDEC_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_VP8DEC_AVAILABLE)
#define DCM_COMP_VP8DEC_TARGET       3
#define DCM_COMP_VP8DEC_GROUP        7
#else
#define DCM_COMP_VP8DEC_TARGET       0
#define DCM_COMP_VP8DEC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATVDRIVER_AVAILABLE)
#define DCM_COMP_MATVDRIVER_TARGET   3
#define DCM_COMP_MATVDRIVER_GROUP    8
#else
#define DCM_COMP_MATVDRIVER_TARGET   0
#define DCM_COMP_MATVDRIVER_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VEENC_AVAILABLE)
#define DCM_COMP_VEENC_TARGET        4
#define DCM_COMP_VEENC_GROUP         9
#else
#define DCM_COMP_VEENC_TARGET        0
#define DCM_COMP_VEENC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_VEDEC_AVAILABLE)
#define DCM_COMP_VEDEC_TARGET        4
#define DCM_COMP_VEDEC_GROUP         10
#else
#define DCM_COMP_VEDEC_TARGET        0
#define DCM_COMP_VEDEC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_DAF_AVAILABLE)
#define DCM_COMP_DAF_TARGET          5
#define DCM_COMP_DAF_GROUP           11
#else
#define DCM_COMP_DAF_TARGET          0
#define DCM_COMP_DAF_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_WAVETABLE_AVAILABLE)
#define DCM_COMP_WAVETABLE_TARGET    5
#define DCM_COMP_WAVETABLE_GROUP     12
#else
#define DCM_COMP_WAVETABLE_TARGET    0
#define DCM_COMP_WAVETABLE_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_BROWSER_AVAILABLE)
#define DCM_COMP_BROWSER_TARGET      6
#define DCM_COMP_BROWSER_GROUP       13
#else
#define DCM_COMP_BROWSER_TARGET      0
#define DCM_COMP_BROWSER_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALC_AVAILABLE)
#define DCM_COMP_CALC_TARGET         6
#define DCM_COMP_CALC_GROUP          14
#else
#define DCM_COMP_CALC_TARGET         0
#define DCM_COMP_CALC_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_CALLSET_AVAILABLE)
#define DCM_COMP_CALLSET_TARGET      6
#define DCM_COMP_CALLSET_GROUP       15
#else
#define DCM_COMP_CALLSET_TARGET      0
#define DCM_COMP_CALLSET_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CAMCO_AVAILABLE)
#define DCM_COMP_CAMCO_TARGET        6
#define DCM_COMP_CAMCO_GROUP         16
#else
#define DCM_COMP_CAMCO_TARGET        0
#define DCM_COMP_CAMCO_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLNDR_AVAILABLE)
#define DCM_COMP_CLNDR_TARGET        6
#define DCM_COMP_CLNDR_GROUP         17
#else
#define DCM_COMP_CLNDR_TARGET        0
#define DCM_COMP_CLNDR_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_CLOCK_AVAILABLE)
#define DCM_COMP_CLOCK_TARGET        6
#define DCM_COMP_CLOCK_GROUP         18
#else
#define DCM_COMP_CLOCK_TARGET        0
#define DCM_COMP_CLOCK_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_FMRADIO_AVAILABLE)
#define DCM_COMP_FMRADIO_TARGET      6
#define DCM_COMP_FMRADIO_GROUP       19
#else
#define DCM_COMP_FMRADIO_TARGET      0
#define DCM_COMP_FMRADIO_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDSET_AVAILABLE)
#define DCM_COMP_SOUNDSET_TARGET     6
#define DCM_COMP_SOUNDSET_GROUP      20
#else
#define DCM_COMP_SOUNDSET_TARGET     0
#define DCM_COMP_SOUNDSET_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_EM_AVAILABLE)
#define DCM_COMP_COSMOS_EM_TARGET    6
#define DCM_COMP_COSMOS_EM_GROUP     21
#else
#define DCM_COMP_COSMOS_EM_TARGET    0
#define DCM_COMP_COSMOS_EM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_FM_AVAILABLE)
#define DCM_COMP_COSMOS_FM_TARGET    6
#define DCM_COMP_COSMOS_FM_GROUP     22
#else
#define DCM_COMP_COSMOS_FM_TARGET    0
#define DCM_COMP_COSMOS_FM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_COSMOS_DTCNT_AVAILABLE)
#define DCM_COMP_COSMOS_DTCNT_TARGET 7
#define DCM_COMP_COSMOS_DTCNT_GROUP  23
#else
#define DCM_COMP_COSMOS_DTCNT_TARGET 0
#define DCM_COMP_COSMOS_DTCNT_GROUP  0
#endif

#if defined(DCM_COMP_SCAT_MOT_AVAILABLE)
#define DCM_COMP_MOT_TARGET          7
#define DCM_COMP_MOT_GROUP           24
#else
#define DCM_COMP_MOT_TARGET          0
#define DCM_COMP_MOT_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_SECSET_AVAILABLE)
#define DCM_COMP_SECSET_TARGET       7
#define DCM_COMP_SECSET_GROUP        25
#else
#define DCM_COMP_SECSET_TARGET       0
#define DCM_COMP_SECSET_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_BAIDUSEARCH_AVAILABLE)
#define DCM_COMP_BAIDUSEARCH_TARGET  8
#define DCM_COMP_BAIDUSEARCH_GROUP   26
#else
#define DCM_COMP_BAIDUSEARCH_TARGET  0
#define DCM_COMP_BAIDUSEARCH_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_BOOTUP_AVAILABLE)
#define DCM_COMP_BOOTUP_TARGET       8
#define DCM_COMP_BOOTUP_GROUP        27
#else
#define DCM_COMP_BOOTUP_TARGET       0
#define DCM_COMP_BOOTUP_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_SETTING_AVAILABLE)
#define DCM_COMP_SETTING_TARGET      8
#define DCM_COMP_SETTING_GROUP       28
#else
#define DCM_COMP_SETTING_TARGET      0
#define DCM_COMP_SETTING_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SOUNDREC_AVAILABLE)
#define DCM_COMP_SOUNDREC_TARGET     8
#define DCM_COMP_SOUNDREC_GROUP      29
#else
#define DCM_COMP_SOUNDREC_TARGET     0
#define DCM_COMP_SOUNDREC_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CAMIMGV_AVAILABLE)
#define DCM_COMP_CAMIMGV_TARGET      9
#define DCM_COMP_CAMIMGV_GROUP       30
#else
#define DCM_COMP_CAMIMGV_TARGET      0
#define DCM_COMP_CAMIMGV_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_VDOREC_AVAILABLE)
#define DCM_COMP_VDOREC_TARGET       9
#define DCM_COMP_VDOREC_GROUP        31
#else
#define DCM_COMP_VDOREC_TARGET       0
#define DCM_COMP_VDOREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CALENDAR_AVAILABLE)
#define DCM_COMP_CALENDAR_TARGET     9
#define DCM_COMP_CALENDAR_GROUP      32
#else
#define DCM_COMP_CALENDAR_TARGET     0
#define DCM_COMP_CALENDAR_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_CALCULATOR_AVAILABLE)
#define DCM_COMP_CALCULATOR_TARGET   9
#define DCM_COMP_CALCULATOR_GROUP    33
#else
#define DCM_COMP_CALCULATOR_TARGET   0
#define DCM_COMP_CALCULATOR_GROUP    0
#endif

#if defined(DCM_COMP_SCAT_VDOPLY_AVAILABLE)
#define DCM_COMP_VDOPLY_TARGET       9
#define DCM_COMP_VDOPLY_GROUP        34
#else
#define DCM_COMP_VDOPLY_TARGET       0
#define DCM_COMP_VDOPLY_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MATV_AVAILABLE)
#define DCM_COMP_MATV_TARGET         9
#define DCM_COMP_MATV_GROUP          35
#else
#define DCM_COMP_MATV_TARGET         0
#define DCM_COMP_MATV_GROUP          0
#endif

#if defined(DCM_COMP_SCAT_SNDREC_AVAILABLE)
#define DCM_COMP_SNDREC_TARGET       9
#define DCM_COMP_SNDREC_GROUP        36
#else
#define DCM_COMP_SNDREC_TARGET       0
#define DCM_COMP_SNDREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PROFILE_AVAILABLE)
#define DCM_COMP_PROFILE_TARGET      9
#define DCM_COMP_PROFILE_GROUP       37
#else
#define DCM_COMP_PROFILE_TARGET      0
#define DCM_COMP_PROFILE_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_CALLSETTING_AVAILABLE)
#define DCM_COMP_CALLSETTING_TARGET  9
#define DCM_COMP_CALLSETTING_GROUP   38
#else
#define DCM_COMP_CALLSETTING_TARGET  0
#define DCM_COMP_CALLSETTING_GROUP   0
#endif

#if defined(DCM_COMP_SCAT_SCRLOCK_AVAILABLE)
#define DCM_COMP_SCRLOCK_TARGET      9
#define DCM_COMP_SCRLOCK_GROUP       39
#else
#define DCM_COMP_SCRLOCK_TARGET      0
#define DCM_COMP_SCRLOCK_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_SETTINGS_AVAILABLE)
#define DCM_COMP_SETTINGS_TARGET     9
#define DCM_COMP_SETTINGS_GROUP      40
#else
#define DCM_COMP_SETTINGS_TARGET     0
#define DCM_COMP_SETTINGS_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_DTCNT_AVAILABLE)
#define DCM_COMP_DTCNT_TARGET        9
#define DCM_COMP_DTCNT_GROUP         41
#else
#define DCM_COMP_DTCNT_TARGET        0
#define DCM_COMP_DTCNT_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_EM_AVAILABLE)
#define DCM_COMP_EM_TARGET           9
#define DCM_COMP_EM_GROUP            42
#else
#define DCM_COMP_EM_TARGET           0
#define DCM_COMP_EM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_FM_AVAILABLE)
#define DCM_COMP_FM_TARGET           9
#define DCM_COMP_FM_GROUP            43
#else
#define DCM_COMP_FM_TARGET           0
#define DCM_COMP_FM_GROUP            0
#endif

#if defined(DCM_COMP_SCAT_AMRREC_AVAILABLE)
#define DCM_COMP_AMRREC_TARGET       10
#define DCM_COMP_AMRREC_GROUP        44
#else
#define DCM_COMP_AMRREC_TARGET       0
#define DCM_COMP_AMRREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_WAVREC_AVAILABLE)
#define DCM_COMP_WAVREC_TARGET       10
#define DCM_COMP_WAVREC_GROUP        45
#else
#define DCM_COMP_WAVREC_TARGET       0
#define DCM_COMP_WAVREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_PCMREC_AVAILABLE)
#define DCM_COMP_PCMREC_TARGET       10
#define DCM_COMP_PCMREC_GROUP        46
#else
#define DCM_COMP_PCMREC_TARGET       0
#define DCM_COMP_PCMREC_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDP_AVAILABLE)
#define DCM_COMP_MDP_TARGET          11
#define DCM_COMP_MDP_GROUP           47
#else
#define DCM_COMP_MDP_TARGET          0
#define DCM_COMP_MDP_GROUP           0
#endif

#if defined(DCM_COMP_SCAT_VECOM_AVAILABLE)
#define DCM_COMP_VECOM_TARGET        11
#define DCM_COMP_VECOM_GROUP         47
#else
#define DCM_COMP_VECOM_TARGET        0
#define DCM_COMP_VECOM_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_RENDER_AVAILABLE)
#define DCM_COMP_RENDER_TARGET       11
#define DCM_COMP_RENDER_GROUP        47
#else
#define DCM_COMP_RENDER_TARGET       0
#define DCM_COMP_RENDER_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDICAM_AVAILABLE)
#define DCM_COMP_MDICAM_TARGET       11
#define DCM_COMP_MDICAM_GROUP        47
#else
#define DCM_COMP_MDICAM_TARGET       0
#define DCM_COMP_MDICAM_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWREC_AVAILABLE)
#define DCM_COMP_MWREC_TARGET        11
#define DCM_COMP_MWREC_GROUP         47
#else
#define DCM_COMP_MWREC_TARGET        0
#define DCM_COMP_MWREC_GROUP         0
#endif

#if defined(DCM_COMP_SCAT_MDIVID_AVAILABLE)
#define DCM_COMP_MDIVID_TARGET       11
#define DCM_COMP_MDIVID_GROUP        47
#else
#define DCM_COMP_MDIVID_TARGET       0
#define DCM_COMP_MDIVID_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VIDMSG_AVAILABLE)
#define DCM_COMP_VIDMSG_TARGET       11
#define DCM_COMP_VIDMSG_GROUP        47
#else
#define DCM_COMP_VIDMSG_TARGET       0
#define DCM_COMP_VIDMSG_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MWWEBCAM_AVAILABLE)
#define DCM_COMP_MWWEBCAM_TARGET     11
#define DCM_COMP_MWWEBCAM_GROUP      47
#else
#define DCM_COMP_MWWEBCAM_TARGET     0
#define DCM_COMP_MWWEBCAM_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_USBVIDEO_AVAILABLE)
#define DCM_COMP_USBVIDEO_TARGET     11
#define DCM_COMP_USBVIDEO_GROUP      47
#else
#define DCM_COMP_USBVIDEO_TARGET     0
#define DCM_COMP_USBVIDEO_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_MDIMTV_AVAILABLE)
#define DCM_COMP_MDIMTV_TARGET       11
#define DCM_COMP_MDIMTV_GROUP        47
#else
#define DCM_COMP_MDIMTV_TARGET       0
#define DCM_COMP_MDIMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MEDMTV_AVAILABLE)
#define DCM_COMP_MEDMTV_TARGET       11
#define DCM_COMP_MEDMTV_GROUP        47
#else
#define DCM_COMP_MEDMTV_TARGET       0
#define DCM_COMP_MEDMTV_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_MDISTREAM_AVAILABLE)
#define DCM_COMP_MDISTREAM_TARGET    11
#define DCM_COMP_MDISTREAM_GROUP     47
#else
#define DCM_COMP_MDISTREAM_TARGET    0
#define DCM_COMP_MDISTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_MEDSTREAM_AVAILABLE)
#define DCM_COMP_MEDSTREAM_TARGET    11
#define DCM_COMP_MEDSTREAM_GROUP     47
#else
#define DCM_COMP_MEDSTREAM_TARGET    0
#define DCM_COMP_MEDSTREAM_GROUP     0
#endif

#if defined(DCM_COMP_SCAT_CAMCAL_AVAILABLE)
#define DCM_COMP_CAMCAL_TARGET       11
#define DCM_COMP_CAMCAL_GROUP        47
#else
#define DCM_COMP_CAMCAL_TARGET       0
#define DCM_COMP_CAMCAL_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_CAMMED_AVAILABLE)
#define DCM_COMP_CAMMED_TARGET       11
#define DCM_COMP_CAMMED_GROUP        47
#else
#define DCM_COMP_CAMMED_TARGET       0
#define DCM_COMP_CAMMED_GROUP        0
#endif

#if defined(DCM_COMP_SCAT_VKLAYOUT_AVAILABLE)
#define DCM_COMP_VKLAYOUT_TARGET     11
#define DCM_COMP_VKLAYOUT_GROUP      48
#else
#define DCM_COMP_VKLAYOUT_TARGET     0
#define DCM_COMP_VKLAYOUT_GROUP      0
#endif

#if defined(DCM_COMP_SCAT_GUOBIHW_AVAILABLE)
#define DCM_COMP_GUOBIHW_TARGET      11
#define DCM_COMP_GUOBIHW_GROUP       48
#else
#define DCM_COMP_GUOBIHW_TARGET      0
#define DCM_COMP_GUOBIHW_GROUP       0
#endif

#if defined(DCM_COMP_SCAT_IME_AVAILABLE)
#define DCM_COMP_IME_TARGET          11
#define DCM_COMP_IME_GROUP           48
#else
#define DCM_COMP_IME_TARGET          0
#define DCM_COMP_IME_GROUP           0
#endif


#endif /* __IMEHW_DCM_SUPPORT__ */


#endif /* __MM_DCM_SUPPORT__ */

#define DCM_COMP_TARGET_CONFIGURE       DCM_COMP_SBC_TARGET, \
    DCM_COMP_BESLOUDNESS_TARGET, \
    DCM_COMP_MP4DEC_TARGET, \
    DCM_COMP_MP4ENC_TARGET, \
    DCM_COMP_H264DEC_TARGET, \
    DCM_COMP_MP4ASPDEC_TARGET, \
    DCM_COMP_VP8DEC_TARGET, \
    DCM_COMP_MATVDRIVER_TARGET, \
    DCM_COMP_VEENC_TARGET, \
    DCM_COMP_VEDEC_TARGET, \
    DCM_COMP_DAF_TARGET, \
    DCM_COMP_WAVETABLE_TARGET, \
    DCM_COMP_BROWSER_TARGET, \
    DCM_COMP_CALC_TARGET, \
    DCM_COMP_CALLSET_TARGET, \
    DCM_COMP_CAMCO_TARGET, \
    DCM_COMP_CLNDR_TARGET, \
    DCM_COMP_CLOCK_TARGET, \
    DCM_COMP_FMRADIO_TARGET, \
    DCM_COMP_SOUNDSET_TARGET, \
    DCM_COMP_COSMOS_EM_TARGET, \
    DCM_COMP_COSMOS_FM_TARGET, \
    DCM_COMP_COSMOS_DTCNT_TARGET, \
    DCM_COMP_MOT_TARGET, \
    DCM_COMP_SECSET_TARGET, \
    DCM_COMP_BAIDUSEARCH_TARGET, \
    DCM_COMP_BOOTUP_TARGET, \
    DCM_COMP_SETTING_TARGET, \
    DCM_COMP_SOUNDREC_TARGET, \
    DCM_COMP_CAMIMGV_TARGET, \
    DCM_COMP_VDOREC_TARGET, \
    DCM_COMP_CALENDAR_TARGET, \
    DCM_COMP_CALCULATOR_TARGET, \
    DCM_COMP_VDOPLY_TARGET, \
    DCM_COMP_MATV_TARGET, \
    DCM_COMP_SNDREC_TARGET, \
    DCM_COMP_PROFILE_TARGET, \
    DCM_COMP_CALLSETTING_TARGET, \
    DCM_COMP_SCRLOCK_TARGET, \
    DCM_COMP_SETTINGS_TARGET, \
    DCM_COMP_DTCNT_TARGET, \
    DCM_COMP_EM_TARGET, \
    DCM_COMP_FM_TARGET, \
    DCM_COMP_AMRREC_TARGET, \
    DCM_COMP_WAVREC_TARGET, \
    DCM_COMP_PCMREC_TARGET, \
    DCM_COMP_MDP_TARGET, \
    DCM_COMP_VECOM_TARGET, \
    DCM_COMP_RENDER_TARGET, \
    DCM_COMP_MDICAM_TARGET, \
    DCM_COMP_MWREC_TARGET, \
    DCM_COMP_MDIVID_TARGET, \
    DCM_COMP_VIDMSG_TARGET, \
    DCM_COMP_MWWEBCAM_TARGET, \
    DCM_COMP_USBVIDEO_TARGET, \
    DCM_COMP_MDIMTV_TARGET, \
    DCM_COMP_MEDMTV_TARGET, \
    DCM_COMP_MDISTREAM_TARGET, \
    DCM_COMP_MEDSTREAM_TARGET, \
    DCM_COMP_CAMCAL_TARGET, \
    DCM_COMP_CAMMED_TARGET, \
    DCM_COMP_VKLAYOUT_TARGET, \
    DCM_COMP_GUOBIHW_TARGET, \
    DCM_COMP_IME_TARGET

        
#define DCM_COMP_GROUP_CONFIGURE     DCM_COMP_SBC_GROUP, \
    DCM_COMP_BESLOUDNESS_GROUP, \
    DCM_COMP_MP4DEC_GROUP, \
    DCM_COMP_MP4ENC_GROUP, \
    DCM_COMP_H264DEC_GROUP, \
    DCM_COMP_MP4ASPDEC_GROUP, \
    DCM_COMP_VP8DEC_GROUP, \
    DCM_COMP_MATVDRIVER_GROUP, \
    DCM_COMP_VEENC_GROUP, \
    DCM_COMP_VEDEC_GROUP, \
    DCM_COMP_DAF_GROUP, \
    DCM_COMP_WAVETABLE_GROUP, \
    DCM_COMP_BROWSER_GROUP, \
    DCM_COMP_CALC_GROUP, \
    DCM_COMP_CALLSET_GROUP, \
    DCM_COMP_CAMCO_GROUP, \
    DCM_COMP_CLNDR_GROUP, \
    DCM_COMP_CLOCK_GROUP, \
    DCM_COMP_FMRADIO_GROUP, \
    DCM_COMP_SOUNDSET_GROUP, \
    DCM_COMP_COSMOS_EM_GROUP, \
    DCM_COMP_COSMOS_FM_GROUP, \
    DCM_COMP_COSMOS_DTCNT_GROUP, \
    DCM_COMP_MOT_GROUP, \
    DCM_COMP_SECSET_GROUP, \
    DCM_COMP_BAIDUSEARCH_GROUP, \
    DCM_COMP_BOOTUP_GROUP, \
    DCM_COMP_SETTING_GROUP, \
    DCM_COMP_SOUNDREC_GROUP, \
    DCM_COMP_CAMIMGV_GROUP, \
    DCM_COMP_VDOREC_GROUP, \
    DCM_COMP_CALENDAR_GROUP, \
    DCM_COMP_CALCULATOR_GROUP, \
    DCM_COMP_VDOPLY_GROUP, \
    DCM_COMP_MATV_GROUP, \
    DCM_COMP_SNDREC_GROUP, \
    DCM_COMP_PROFILE_GROUP, \
    DCM_COMP_CALLSETTING_GROUP, \
    DCM_COMP_SCRLOCK_GROUP, \
    DCM_COMP_SETTINGS_GROUP, \
    DCM_COMP_DTCNT_GROUP, \
    DCM_COMP_EM_GROUP, \
    DCM_COMP_FM_GROUP, \
    DCM_COMP_AMRREC_GROUP, \
    DCM_COMP_WAVREC_GROUP, \
    DCM_COMP_PCMREC_GROUP, \
    DCM_COMP_MDP_GROUP, \
    DCM_COMP_VECOM_GROUP, \
    DCM_COMP_RENDER_GROUP, \
    DCM_COMP_MDICAM_GROUP, \
    DCM_COMP_MWREC_GROUP, \
    DCM_COMP_MDIVID_GROUP, \
    DCM_COMP_VIDMSG_GROUP, \
    DCM_COMP_MWWEBCAM_GROUP, \
    DCM_COMP_USBVIDEO_GROUP, \
    DCM_COMP_MDIMTV_GROUP, \
    DCM_COMP_MEDMTV_GROUP, \
    DCM_COMP_MDISTREAM_GROUP, \
    DCM_COMP_MEDSTREAM_GROUP, \
    DCM_COMP_CAMCAL_GROUP, \
    DCM_COMP_CAMMED_GROUP, \
    DCM_COMP_VKLAYOUT_GROUP, \
    DCM_COMP_GUOBIHW_GROUP, \
    DCM_COMP_IME_GROUP, \



#else

#error "Overlay region for dynamic code relocation with compression should be determined for new chipset"

#endif /* MTxxxx_SERIES_DCMGR */

#endif /* __DCM_WITH_COMPRESSION__ */

/* Dynamic code manager for relocate code into the overlay TCM region */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
void DCM_Unload( kal_int32 dynamic_code_id );
kal_bool DCM_Isloaded( kal_int32 dynamic_code_id );
kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id );

#else /* __MTK_TARGET__ */

/* Dynamic code manager for relocate code into the overlay TCM region */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
void DCM_Unload( kal_int32 dynamic_code_id );
kal_bool DCM_Isloaded( kal_int32 dynamic_code_id );
kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id );

#endif /* __MTK_TARGET__ */

#endif  /* !__DCMGR_H */
