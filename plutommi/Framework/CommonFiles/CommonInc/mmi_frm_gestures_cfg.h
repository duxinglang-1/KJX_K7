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
*  mmi_
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
 * -------
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef MMI_FRM_GESTURES_CFG_H
#define MMI_FRM_GESTURES_CFG_H

/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum{
    MMI_FRM_STROKES_INVALID = -1,
    MMI_FRM_STROKES_UP,                 /* A straight Up movement */
    MMI_FRM_STROKES_UP_RIGHT,           /* A straight Up-Right movement */
    MMI_FRM_STROKES_RIGHT,              /* A straight Right movement */
    MMI_FRM_STROKES_DOWN_RIGHT,         /* A straight Down-Right movement */
    MMI_FRM_STROKES_DOWN,               /* A straight Down movement */
    MMI_FRM_STROKES_DOWN_LEFT,          /* A straight Down-Left movement */
    MMI_FRM_STROKES_LEFT,               /* A straight Left movement */
    MMI_FRM_STROKES_UP_LEFT,            /* A straight Up-Left movement */
    MMI_FRM_STROKES_CLOCKWISE,
    MMI_FRM_STROKES_ANTICLOCKWISE,
    MMI_FRM_STROKES_SEMICIRCLE_UP,      /* The arc direction of semicircle is up */
    MMI_FRM_STROKES_SEMICIRCLE_DOWN,    /* The arc direction of semicircle is down */
    MMI_FRM_STROKES_SEMICIRCLE_LEFT,    /* The arc direction of semicircle is left ( */
    MMI_FRM_STROKES_SEMICIRCLE_RIGHT,   /* The arc direction of semicircle is right ) */
    MMI_FRM_STROKES_END = 255           /* The end of strokes sequence */
}mmi_frm_strokes_enum;
#endif /* MMI_FRM_GESTURE_CFG_H */



