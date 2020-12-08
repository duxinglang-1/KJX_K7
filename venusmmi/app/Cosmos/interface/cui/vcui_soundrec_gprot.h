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
 *  vcui_soundrec_gprot.h
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SOUNDREC_GPROT_H__
#define __VCUI_SOUNDREC_GPROT_H__

#include "MMI_features.h" 

#ifdef __MMI_SOUNDREC_CUI__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCUI_SOUNDREC_PARAM_NO_PAUSE            0x01    /* No pause function when record */
#define VCUI_SOUNDREC_PARAM_NO_PREVIEW          0x02    /* No record file preview after record */
#define VCUI_SOUNDREC_PARAM_DISPLAY_REC_LIMIT   0x04    /* Display record limit time instead of maximum record time */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* in header: evt_id, size, user_data, sender_id */
    S32 result; /* >0, success; =0, Cancel, <0, error */
    const WCHAR *file_path;
}vcui_soundrec_evt_struct;

typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SOUNDREC_BEGIN = VCUI_SOUNDREC,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_SOUNDREC_RESULT, /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this 
                                         * event:
                                         *      1: User select a storage
                                         *      2: User cancel
                                         *      3: Some error happen
                                         */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_SOUNDREC_TOTAL
    /* DOM-NOT_FOR_SDK-END */
}vcui_soundrec_event_enum;

typedef enum
{
    VCUI_SOUNDREC_QUALITY_BY_SETTING,
    VCUI_SOUNDREC_QUALITY_NORMAL,
    VCUI_SOUNDREC_QUALITY_HIGH,
    VCUI_SOUNDREC_QUALITY_TOTAL
}vcui_soundrec_quality_enum;


/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif


/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_create
 * DESCRIPTION
 *
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  mmi_id
 *****************************************************************************/
mmi_id vcui_soundrec_create(mmi_id parent_id);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_run
 * DESCRIPTION
 *
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_soundrec_run(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_close
 * DESCRIPTION
 *
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_soundrec_close(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_set_param
 * DESCRIPTION
 *  Set record related parameters
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  param               :           [IN]        configurable parameters for CUI
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vcui_soundrec_set_param(mmi_id cui_id, VfxU32 param);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_set_record_time
 * DESCRIPTION
 *  Set record time limitation, called before run CUI
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  duration            :           [IN]        maximum record duration (in seconds)
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_soundrec_set_record_time(mmi_id cui_id, VfxU32 duration);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_set_record_size
 * DESCRIPTION
 *  Set record size limitation, called before run CUI
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  size                :           [IN]        maximum record size (in bytes)
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_soundrec_set_record_size(mmi_id cui_id, VfxU32 size);

/*****************************************************************************
 * FUNCTION
 *  vcui_soundrec_set_record_quality
 * DESCRIPTION
 *  Set record quality, called before run CUI
 * PARAMETERS
 *  cui_id              :           [IN]        cui_id
 *  quality             :           [IN]        specify quality (in vcui_soundrec_quality_enum)
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_soundrec_set_record_quality(mmi_id cui_id, VfxU32 quality);


#ifdef __cplusplus
}
#endif

#endif
#endif /* __VCUI_SOUNDREC_GPROT_H__ */

