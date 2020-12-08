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
 *  vfx_frame_aligner.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __VFX_FRAME_ALIGNER_H__
#define __VFX_FRAME_ALIGNER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "..\pme\vfx_object.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxFrame;


// Frame aligner side enum
enum VfxFrameAlignerSideEnum
{
    VFX_FRAME_ALIGNER_SIDE_LEFT,    // left
    VFX_FRAME_ALIGNER_SIDE_TOP,     // top
    VFX_FRAME_ALIGNER_SIDE_RIGHT,   // right
    VFX_FRAME_ALIGNER_SIDE_BOTTOM,  // bottom
    VFX_FRAME_ALIGNER_SIDE_END_OF_ENUM
};


// Frame aligner mode enum
enum VfxFrameAlignerModeEnum
{
    VFX_FRAME_ALIGNER_MODE_NONE,    // Align none
    VFX_FRAME_ALIGNER_MODE_SIDE,    // Align side
    VFX_FRAME_ALIGNER_MODE_MID,     // Align mid
    VFX_FRAME_ALIGNER_MODE_END_OF_ENUM
};


/***************************************************************************** 
 * Class VfxFrameAligner
 *****************************************************************************/

/*
 * VfxFrameAligner is the base class of a frame aligner.
 */
class VfxFrameAligner : public VfxObject
{
// Constructor / Destructor
public:
    // Default constructor
    VfxFrameAligner();

// Method
public:
    // Align child frames
    static void alignChildFrames(
        VfxFrame *targetFrame           // align all the fhild frames in this frame
    );

    // Align parent frame
    void alignParentFrame(
        VfxFrame *targetFrame           // align this frame to its parent frame
    );

    // Set alignment information
    void setAlignment(
        VfxFrameAlignerSideEnum side,   // side
        VfxFrameAlignerModeEnum mode,   // mode
        VfxS32 dist                     // distance
    );

    // Get alignment mode
    // RETURNS: VfxFrameAlignerModeEnum
    VfxFrameAlignerModeEnum getAlignMode(
        VfxFrameAlignerSideEnum side    // side
    );

    // Get alignment distance
    // RETURNS: distance
    VfxS32 getAlignDist(
        VfxFrameAlignerSideEnum side    // side
    );

    // Check whether this aligner is empty
    // RETURNS: true or false
    VfxBool isEmpty();

// Implementation
private:
    // Align mode: right (2 bits) + left (2 bits) + down (2 bits) + up (2 bits)
    VfxS8 m_mode;

    // Distance
    VfxS32 m_dist[VFX_FRAME_ALIGNER_SIDE_END_OF_ENUM];
};

#endif

