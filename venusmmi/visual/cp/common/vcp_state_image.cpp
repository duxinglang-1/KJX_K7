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
 *  vcp_cp_image_list.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  General component image list
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/
#include "vcp_state_image.h"

#include "vfx_datatype.h"
#include "vfx_image_src.h"

/***************************************************************************** 
 * Class VcpStateImage
 *****************************************************************************/

void VcpStateImage::setImage (
    VfxResId normalId,
    VfxResId pressedId,
    VfxResId disabledId,
    VfxResId highlightId
)
{
    VfxImageSrc image;

    image.setResId(normalId);
    setItem('NORM', image);

    image.setResId(pressedId);
    setItem('PRES', image);

    image.setResId(disabledId);
    setItem('DSBL', image);

    image.setResId(highlightId);
    setItem('HILI', image);
}


void VcpStateImage::setImage (
    const VfxImageSrc &normalSrc,
    const VfxImageSrc &pressedSrc,
    const VfxImageSrc &disabledSrc,
    const VfxImageSrc &highlightSrc
)
{
    setItem('NORM', normalSrc);
    setItem('PRES', pressedSrc);
    setItem('DSBL', disabledSrc);
    setItem('HILI', highlightSrc);
}


const VfxImageSrc &VcpStateImage::getImageInternal (VfxId id) const
{
    VfxImageSrc image = getItem(id);

    if (getItem(id).isNull())
    {
        return getItem('NORM');
    }
    else
    {
        return getItem(id);
    }
}

