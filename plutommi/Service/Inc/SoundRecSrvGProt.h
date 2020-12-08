/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  SoundRecSrvGProt.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SOUND_REC_SRV_G_PROT_H__
#define __SOUND_REC_SRV_G_PROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mdi_audio.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    SRV_SOUNDREC_QUALITY_NORMAL,
    SRV_SOUNDREC_QUALITY_HIGH,
    SRV_SOUNDREC_QUALITY_TOTAL
}srv_soundrec_quality_enum;

typedef struct
{
    U8 mdi_format;
    U8 mdi_quality;
    const kal_wchar* file_ext;
}srv_soundrec_mdi_rec_param_struct;


/***************************************************************************** 
 * Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_set_quality
 * DESCRIPTION
 *  This function is to set record quality and save to NVRAM
 * PARAMETERS
 *  quality       : [IN] record quality
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_soundrec_set_quality(srv_soundrec_quality_enum quality);

/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_set_storage
 * DESCRIPTION
 *  This function is to set record drive and save to NVRAM
 * PARAMETERS
 *  drive       : [IN] record storage
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_soundrec_set_storage(U8 drive);

/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_quality
 * DESCRIPTION
 *  This function is to get record drive from NVRAM
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Quality in srv_soundrec_quality_enum
 *****************************************************************************/
extern srv_soundrec_quality_enum srv_soundrec_get_quality(void);

/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_mdi_quality
 * DESCRIPTION
 *  This function is to get record drive from NVRAM and covert it to MDI quality enum
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Quality in MDI_AUDIO_REC_QUALITY_ENUM
 *****************************************************************************/
extern MDI_AUDIO_REC_QUALITY_ENUM srv_soundrec_get_mdi_quality(void);


/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_get_storage
 * DESCRIPTION
 *  This function is to set record drive of sound recorder and save to NVRAM
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Drive letter
 *****************************************************************************/
extern U8 srv_soundrec_get_storage(void);

#ifdef AUD_REC_ENABLE
/*****************************************************************************
 * FUNCTION
 *  srv_soundrec_auto_record_set_status
 * DESCRIPTION
 *  This function is to set auto speech record (vm format) function on/off
 * PARAMETERS
 *  is_on   [IN] : Turn on/off auto speech record function
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_soundrec_auto_record_set_status(MMI_BOOL is_on);
#endif

#endif /* __SOUND_REC_SRV_G_PROT_H__ */

