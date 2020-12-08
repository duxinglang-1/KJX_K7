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

/**************************************************************

FILENAME: imageviewcui.res

PURPOSE: Define resource for ImageViewer CUI

REMARKS: nil

AUTHOR: Ye Jiao

DATE: Feb-8-2012

**************************************************************/
/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "CustomCfg.h"
#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif
#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustResDef.h"
#include "ImgViewerConfig.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_IMAGE_VIEWER_EX__)
/* APP tag, include your app name defined in mmi_pluto_res_range_def.h */
<APP id="CUI_IMAGEVIEWER" name="STR_ID_IMGVIEWCUI_NAME">

    <STRING id="STR_ID_IMGVIEWCUI_NAME"/>
    #ifdef __MMI_IV_PLUTO_SLIM__
		<TIMER id="IV_LOADING_TIMER"/>
	#endif
    <!--Memory config for ASM2.0-->
    <MEMORY heap="$(MAX_FS_SORT_MEM_SIZE)" fg="$(IV_TOTAL_SCREEN_MEMORY_SIZE) + $(IV_TOTAL_MED_MEMORY_SIZE)" inc="ImgViewerConfig.h, med_global.h"/>
</APP>
#endif  /* defined(__MMI_IMAGE_VIEWER__) && !defined(__MMI_IMAGE_VIEWER_EX__) */

#if defined(__MMI_IMAGE_VIEWER_EX__)
/* APP tag, include your app name defined in mmi_pluto_res_range_def.h */
<APP id="CUI_IMAGEVIEWER" name="STR_ID_IMGVIEWCUI_NAME">

    <STRING id="STR_ID_IMGVIEWCUI_NAME"/>

    <!--Memory config for ASM2.0-->
    <MEMORY heap="$(MAX_FS_SORT_MEM_SIZE) + $(MAX_MED_JPG_DEC_EXT_MEM_SIZE) + $(MMI_IVEX_TOTAL_MED_MEM_POOL_SIZE) + $(MMI_IVEX_TOTAL_APP_BASED_MEM_POOL_SIZE) + $(AUD_EXT_MEM_SIZE) + $(MTV_BG_RECORD_MEM_SIZE) + $(MAX_VRT_EXT_MEM_SIZE) + $(MAX_MED_MEDIACACHE_IES_EXT_MEM_SIZE)"
            fg="$(IV_TOTAL_SCREEN_MEMORY_SIZE)"
            inc="ImageViewerExAppGprot.h, ImgViewerConfig.h, med_global.h, med_mem.h"/>
</APP>
#endif  /* defined(__MMI_IMAGE_VIEWER_EX__) */
