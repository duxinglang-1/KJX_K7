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
 *  MediaCacheSrvmem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MEDIALIB Cache Srv header file for memory define
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MEDIACACHE_SRV_MEM_H_
#define _MEDIACACHE_SRV_MEM_H_
#if defined(__MMI_SRV_MEDIACACHE__)

#include "mmi_features.h"
#include "lcd_sw_rnd.h"
#include "lcd_sw_inc.h"

#ifdef __MMI_SRV_MEDIA_CACHE_USE_SRV_IES__
#include "ImgEdtSrvConfig.h"
#endif

/*meta working buffer*/
#if defined(__SQLITE3_SUPPORT__) && defined(__MMI_SRV_MEDIACACHE__) && defined(__MMI_IMAGE_VIEWER_EX_DB__) && defined(__SCALADO_SUPPORT__)
    #define SRV_MEDIACACHE_META_WORKING_BUFFER  (400 * 1024 + 280 * 1024)
#else
    #define SRV_MEDIACACHE_META_WORKING_BUFFER  (0)
#endif

/*working memory for IES. Please allocate cachable memory for this buffer.*/
#ifdef __MMI_SRV_IES_META__
    #define SRV_MEDIACACHE_IES_WORKING_BUF_SIZE (SRV_IES_VIEW_WORK_MEMORY)  // 9 MB
#else
    #define SRV_MEDIACACHE_IES_WORKING_BUF_SIZE (SRV_IES_VIEW_WORK_MEMORY)  // 6.7 MB
#endif 

/*One IO buffer size of L2*/
#define SRV_MEDIACACHE_DB_IO_BUF_SIZE     ((LCD_WIDTH * LCD_HEIGHT * DRV_MAINLCD_BIT_PER_PIXEL)>>5)/*>>3 covert to bytes and >>2 mean 1/4 LCD size*/

/*One IO buffer size of L1*/
#define SRV_MEDIACACHE_DB_L1_IO_BUF_SIZE     ((LCD_WIDTH * LCD_HEIGHT * DRV_MAINLCD_BIT_PER_PIXEL)>>3)/*>>3 covert to bytes*/

#define SRV_MEDIACACHE_DB_L1_IO_BUF_SIZE_24BIT     ((LCD_WIDTH * LCD_HEIGHT * 24)>>3)/*>>3 covert to bytes*/


/*Min memory size for database run*/
#define SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_MIN         (80 * 1024 + SRV_MEDIACACHE_DB_IO_BUF_SIZE * 2 + 4)


#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
/* use slightly larger SQLite heap for slim, since we adjust the page size larger in Cosmos slim */
#define SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL (350)
#else
#define SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL (320)
#endif

/*Default memory size for database run of L2 */
#define SRV_MEDIACACHE_SQLITE_DB_BUF_SIZE_DEFAULT     (SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL * 1024 + SRV_MEDIACACHE_DB_IO_BUF_SIZE * 2 + 4)

/*Min memory for srv run*/
#define SRV_MEDIACACHE_RUN_BUF_BASE       (3080) /*structure max*/
#define SRV_MEDIACACHE_RUN_BUF_SIZE(num)  (SRV_MEDIACACHE_RUN_BUF_BASE + 120 * num) /*num here is mean srv can maintain cache number*/

/*Default memory for srv run*/
#define SRV_MEDIACACHE_RUN_BUF_SIZE_MIN   (SRV_MEDIACACHE_RUN_BUF_SIZE(10))

/*IO buffer size*/
#ifdef __LOW_COST_SUPPORT_COMMON__
#define SRV_MEDIACACHE_DB_IO_BUF_COUNT (1)
#else
#define SRV_MEDIACACHE_DB_IO_BUF_COUNT (2)
#endif 

#define SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE (SRV_MEDIACACHE_DB_L1_IO_BUF_SIZE * SRV_MEDIACACHE_DB_IO_BUF_COUNT)
#define SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE_24BIT (SRV_MEDIACACHE_DB_L1_IO_BUF_SIZE_24BIT * SRV_MEDIACACHE_DB_IO_BUF_COUNT)

/*Min memory size for database run*/
#define SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_MIN   ((80 * 1024 + SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE + 4))
/*Default memory size for database run*/
#define SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT  (SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL * 1024 + SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE + 4)
/*Default memory size for database run*/
#define SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_DEFAULT_24BIT     ((SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL * 1024 * 3 / 2) + SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE_24BIT + 4)
/*Default memory size for database run of L1 */
#define SRV_MEDIACACHE_SQLITE_DB_L1_BUF_SIZE_BEST  (SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL * 1024 + SRV_MEDIACACHE_DB_L1_IO_BUF_TOTAL_SIZE + 4 + SRV_MEDIACACHE_META_WORKING_BUFFER)

#define SRV_MEDIACACHE_CALC_SQLITE_DB_BUF_SIZE_BY_W_H(w,h)     (SRV_MEDIACACHE_SQL_DB_WORKING_OPTIMAL * 1024 + (w) * (h) * (DRV_MAINLCD_BIT_PER_PIXEL>>3)*SRV_MEDIACACHE_DB_IO_BUF_COUNT + 4)

#endif /* __MMI_SRV_MEDIACACHE__ */
#endif /* _MEDIACACHE_SRV_MEM_H_ */ 



