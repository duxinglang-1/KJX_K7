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
 *	 Res_progress.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  NFB progress image resource
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"       /* add if you use any compile options defined in MMI_features.h */

#include "MMIDataType.h"        /* for resource base */
#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */

void PopulateNFBProgressImg(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
#if defined(__COSMOS_MMI__)
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\progress_bar.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\0.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\1.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\2.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\3.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\4.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\5.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\6.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\7.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\8.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\9.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\percent.pbm");
    ADD_NFB_IMAGE(RES_IMG_ROOT"\\\\BootupShutdown\\\\ProgressBar\\\\progress_twill.pbm");
#else /*__COSMOS_MMI__*/
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\progress_bar.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\0.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\1.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\2.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\3.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\4.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\5.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\6.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\7.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\8.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\9.bmp");
    ADD_NFB_IMAGE(CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\percent.bmp");
#endif /*__COSMOS_MMI__*/
#endif /* defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) */
}
