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
 *  vapp_phb_res.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_PICTURE_H__
#define __PB_PICTURE_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrSrvGprot.h"

#ifdef __cplusplus
}
#endif

#if defined(__MMI_MAINLCD_480X800__) // WVGA
    #define VAPP_PHB_IMG_SIZE_WIDTH (102)
    #define VAPP_PHB_IMG_SIZE_HEIGHT (102)
#elif defined(__MMI_MAINLCD_320X480__) // HVGA
    #define VAPP_PHB_IMG_SIZE_WIDTH (68)
    #define VAPP_PHB_IMG_SIZE_HEIGHT (68)
#elif  defined(__MMI_MAINLCD_240X320__)
    #define VAPP_PHB_IMG_SIZE_WIDTH (48)
    #define VAPP_PHB_IMG_SIZE_HEIGHT (48)
#else
    #define VAPP_PHB_IMG_SIZE_WIDTH (48)
    #define VAPP_PHB_IMG_SIZE_HEIGHT (48)
#endif

typedef struct
{
    MMI_ID selector_cui_id;
    MMI_ID img_cliper_cui_id;
    VfxWChar *img_path;
    VfxBool result;
} vapp_phb_res_cliper_user_data_struct;


/***************************************************************************** 
 * Class VappPhbResSelectorObj
 *****************************************************************************/ 
class VappPhbResSelectorObj: public VfxObject
{
public:
    VappPhbResSelectorObj(){}

public:
    MMI_ID selector_cui_id;
    MMI_ID img_cliper_cui_id;
    VfxWChar img_path[SRV_FMGR_PATH_MAX_LEN + 1];
    VfxBool result;
};

/***************************************************************************** 
 * Class PBPicture
 *****************************************************************************/ 
class PBPicture: public VfxObject
{
public:
    enum PB_PIC_TYPE
    {
        PB_PIC_FILE = 0x01,
        PB_PIC_CAMRO = 0x02,
        PB_PIC_REMOVE = 0x04,
        PB_PIC_TYPE_TOTAL
    };

public:
    PBPicture(){}
};

#endif /* __PB_PICTURE_H__ */

