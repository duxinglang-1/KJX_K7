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
 *  vcp_state_image.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  image list with state for CP
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#ifndef __VCP_STATE_IMAGE_H__
#define __VCP_STATE_IMAGE_H__
 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_image_src.h"
#include "vfx_datatype.h"

/***************************************************************************** 
 * Class VcpStateImage
 *****************************************************************************/
class VcpStateImage : public VfxImageList
{
// Constructor / Destructor
public:
    // <group DOM_StateImage_VcpStateImage_Constructor/Destructor>
    // Default constructor
    VcpStateImage() {}

    // <group DOM_StateImage_VcpStateImage_Constructor/Destructor>
    // Create by one image ID
    VcpStateImage(
        VfxResId normalId               // [IN] image ID of normal state
    )
    {
        setImage(normalId, 0, 0, 0);
    }

    // <group DOM_StateImage_VcpStateImage_Constructor/Destructor>
    // Create by four image IDs
    VcpStateImage(
        VfxResId normalId,              // [IN] image ID of normal state
        VfxResId pressedId,             // [IN] image ID of pressed state
        VfxResId disabledId,            // [IN] image ID of disabled state
        VfxResId highlightId            // [IN] image ID of highlight state
    )
    {
        setImage(normalId, pressedId, disabledId, highlightId);
    }

// Method
public:
    // <group DOM_StateImage_VcpStateImage_Method>
    // Set images for normal, pressed, disabled, and highlight state
    void setImage (
        VfxResId normalId,              // [IN] image ID of normal state
        VfxResId pressedId,             // [IN] image ID of pressed state
        VfxResId disabledId,            // [IN] image ID of disabled state
        VfxResId highlightId            // [IN] image ID of highlight state
    );

    // <group DOM_StateImage_VcpStateImage_Method>
    // Set images for normal, pressed, disabled, and highlight state
    void setImage (
        const VfxImageSrc &normalSrc,   // [IN] image src of normal state
        const VfxImageSrc &pressedSrc,  // [IN] image src of pressed state
        const VfxImageSrc &disabledSrc, // [IN] image src of disabled state
        const VfxImageSrc &highlightSrc // [IN] image src of highlight state
    );

    // <group DOM_StateImage_VcpStateImage_Method>
    // Get normal image src
    // RETURNS: VfxImageSrc
    const VfxImageSrc &getImageNormal () const
    {
        return getImageInternal('NORM');
    }

    // <group DOM_StateImage_VcpStateImage_Method>
    // Get pressed image src, returns normal image if NULL
    // RETURNS: VfxImageSrc
    const VfxImageSrc &getImagePressed () const
    {
        return getImageInternal('PRES');
    }

    // <group DOM_StateImage_VcpStateImage_Method>
    // Get disabled image src, returns normal image if NULL
    // RETURNS: VfxImageSrc
    const VfxImageSrc &getImageDisabled () const
    {
        return getImageInternal('DSBL');
    }

    // <group DOM_StateImage_VcpStateImage_Method>
    // Get highlight image src, returns normal image if NULL
    // RETURNS: VfxImageSrc
    const VfxImageSrc &getImageHighlight () const
    {
        return getImageInternal('HILI');
    }

// Implementation
private:
    // <group DOM_StateImage_VcpStateImage_Implementation>
    // get image for state
    const VfxImageSrc &getImageInternal (
        VfxId id                        // [IN] state
    ) const;
};

#endif /* __VCP_STATE_IMAGE_H__ */

