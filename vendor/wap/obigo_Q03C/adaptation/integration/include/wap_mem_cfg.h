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
 *   wap_mem_cfg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Common definition of wap framework adaptation for internal use
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef WAP_MEM_CFG_H
#define WAP_MEM_CFG_H

#include "custom_wap_config.h"

/****************************************************************************
 *  This is used to speed up the WAP download.
 *  1. it needs 58 KB more system memory
 *  2. pipe for DAS will be enlarged to 8KB
 *  3. DAS buffer will be also enlarged to 8KB
 * * **************************************************************************/
#if (defined __WIFI_SUPPORT__) && (defined __CUSTOM_WIFI_FEATURES_SWITCH__)
#define WAP_DOWNLOAD_SPEEDUP
#endif

#ifdef WAP_DOWNLOAD_SPEEDUP
#define MAX_NUM_BIG_PIPES           (4)
#endif


#ifdef __J2ME__
#if   MAX_VM_INSTANCE_NUM == 2
#define MSF_NUM_INST_VM 0
#define MSF_MAX_VM_CONN 8
#elif MAX_VM_INSTANCE_NUM == 3
#define MSF_NUM_INST_VM 1
#define MSF_MAX_VM_CONN 10
#elif MAX_VM_INSTANCE_NUM == 4
#define MSF_NUM_INST_VM  2
#define MSF_MAX_VM_CONN 12
#elif MAX_VM_INSTANCE_NUM == 5
#define MSF_NUM_INST_VM 3
#define MSF_MAX_VM_CONN 14
#endif
#else /*__J2ME__*/
#define MSF_NUM_INST_VM 0
#endif


/***************************************************************************** 
* Define
*****************************************************************************/
/* Use aplication-shared memory */

#ifdef OBIGO_Q03C_BROWSER

    #define WAP_USE_ASM

  #if (defined(LIBRA35_DEMO_BB) && (defined(__FLAVOR_FREETYPE_JBLENDIA_Q03C_LANG__) || defined(__FLAVOR_FREETYPE_JBLENDIA_Q03C_LANG2__))) || \
             (defined(AMBER38_DEMO_BB) && (defined(__FLAVOR_MONOTYPE_IJET_Q03C_LANG__) || defined(__FLAVOR_MONOTYPE_IJET_Q03C_LANG2__))) || defined(WAP_CUSTOM_CFG_SUPPORT_LARGE_MEM_POOL)

          #define WAP_FLAVOR_LARGE_MEM_POOL

	#elif defined __OP02__
          #define WAP_FLAVOR_LARGE_MEM_POOL

    #endif

#endif /*OBIGO_Q03C_BROWSER*/

/***************************************************************************** 
 * WAP encoding support definitions
 *****************************************************************************/
/*Following MACROS are used to force to use perticular memory configuration other that default.
  Define only one of the pools.*/

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*Following are the default setting. Applicable when force settings are disable.*/
#ifndef WAP_CONFIG_DECODE
    #if (defined WAP_USE_ASM) && (defined __J2ME__) && !(defined SLIM_WAP_MMS)
        #define WAP_CONFIG_DECODE
        #define WAP_DECODE_USE_ASM_POOL
    #endif /*(defined WAP_USE_ASM) && (defined __J2ME__)*/
#endif /*WAP_CONFIG_DECODE*/

#ifndef WAP_CONFIG_DECODE
    #if (defined WAP_DECODE_USE_ASM_POOL) || (defined WAP_DECODE_USE_SYS_POOL)
        #error "Wrong memory configuration for WAP_CONFIG_DECODE."
    #endif /*(defined WAP_DECODE_USE_ASM_POOL) && (defined WAP_DECODE_USE_SYS_POOL)*/
#endif /*WAP_CONFIG_DECODE*/

#ifdef WAP_CONFIG_DECODE
    #if (defined WAP_DECODE_USE_ASM_POOL) && (defined WAP_DECODE_USE_SYS_POOL)
        #error "Wrong memory configuration for WAP_CONFIG_DECODE."
    #endif /*(defined WAP_DECODE_USE_ASM_POOL) && (defined WAP_DECODE_USE_SYS_POOL)*/

    #if defined WAP_DECODE_USE_ASM_POOL
        #define WAP_DECODE_ASM_MEMORY_POOL_SIZE (1024*50*5)
        #define WAP_DECODE_SYS_MEMORY_POOL_SIZE (0)
    #elif defined WAP_DECODE_USE_SYS_POOL
        #define WAP_DECODE_SYS_MEMORY_POOL_SIZE (1024*50*8)
        #define WAP_DECODE_ASM_MEMORY_POOL_SIZE (0)
    #else
        #error "Wrong memory configuration for WAP_CONFIG_DECODE."
    #endif /*WAP_DECODE_USE_ASM_POOL*/
#else /*WAP_CONFIG_DECODE*/
    #define WAP_DECODE_SYS_MEMORY_POOL_SIZE (0)
    #define WAP_DECODE_ASM_MEMORY_POOL_SIZE (0)
#endif /*WAP_CONFIG_DECODE*/

/* 
 * Add checksum before and after an allocated memory chunk. 
 * Used to detect memory corruption or memory double release. 
 * Because it has space overheads in memory consumption , it should not be used
 * in production load.
 */
#ifdef WAP_MEM_DEBUG
    #define WAP_MEM_CHECK
#endif

#if !defined(WAP_USE_ADM) && defined(WAP_MEM_CHECK)
    #define MEM_CHECK_EXTRA_SIZE(x)  (x*5/4)        /* Increase memory heap due to space overheads */
#else 
    #define MEM_CHECK_EXTRA_SIZE(x)  (x)
#endif 

#ifdef WAP_USE_ASM
    #ifdef WAP_GLOBAL_MEM_SIZE
        #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_GLOBAL_MEM_SIZE)
    #elif defined(WAP_FLAVOR_LARGE_MEM_POOL) 
        #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*525)
    #elif defined(SLIM_WAP_MMS) 
        #ifdef __OP01__
            #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*500)
        #else
            #ifdef PGDL_SUPPORT_YOUTUBE
                #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*280)
            #else
                #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*195)
            #endif
        #endif
    #else
        #ifdef __J2ME__
            #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*280)
        #else
            #define WAP_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*230)
        #endif /* __J2ME__ */
    #endif /* WAP_GLOBAL_MEM_SIZE */
#else
    #define WAP_ASM_MEM_SIZE (0)
#endif /* WAP_USE_ASM */

#ifdef __MMI_MMS_V01_USE_ASM__
    #ifdef SLIM_WAP_MMS
        #define MMS_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*195)
    #else
        #ifdef __J2ME__
            #define MMS_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*280)
        #else
            #define MMS_ASM_MEM_SIZE MEM_CHECK_EXTRA_SIZE(1024*230)
        #endif /* __J2ME__ */
    #endif /* SLIM_WAP_MMS */
#endif /* __MMI_MMS_V01_USE_ASM__ */

#define WAP_ASM_MEM_SIZE_TOTAL WAP_ASM_MEM_SIZE+WAP_DECODE_ASM_MEMORY_POOL_SIZE



/* 
 * WAP_GLOBAL_MEM_SIZE is to define the size of WAP dynamic memory pool for application part, which 
 * determines the size of web page and MMS supported. If WAP_GLOBAL_MEM_SIZE is larger, then more 
 * web page or larger MMS can be displayed and supported. If WAP_GLOBAL_MEM_SIZE is defined in 
 * custom_wap_config.h, then WAP_INT_GLOBAL_MEM_SIZE equals WAP_GLOBAL_MEM_SIZE, otherwise, 
 * WAP_INT_GLOBAL_MEM_SIZE is (1024*200) by default. Customer can change this value if she want to
 * support bigger or richer web page or MMS.
 */
#ifdef WAP_USE_ASM
    #define WAP_INT_GLOBAL_MEM_SIZE WAP_ASM_MEM_SIZE
    #ifdef WAP_SYS_MEM_SIZE
        #define WAP_INT_SYS_MEMSIZE WAP_SYS_MEM_SIZE
    #else
    	#ifdef OBIGO_Q03C_MMS_V01
        #define WAP_INT_SYS_MEMSIZE (1024*80) 
    	#else
            #ifdef SLIM_WAP_MMS
                #if defined(WAP_CUSTOM_CFG_SUPPORT_LARGE_MEM_POOL)
                    #define WAP_INT_SYS_MEMSIZE (1024*80) 
                #else
            	    #define WAP_INT_SYS_MEMSIZE (1024*45) 
                #endif /* defined(WAP_CUSTOM_CFG_SUPPORT_LARGE_MEM_POOL) */
            #else
                #ifdef __OP01_3G__ /*CMCC TD Project. Need more memory in STK buffers & pipes to speed-up data transfer.*/
                    #define WAP_INT_SYS_MEMSIZE (1024*100)
                #else
                    #define WAP_INT_SYS_MEMSIZE (1024*80) 
                #endif
            #endif
        #endif
    #endif
    #ifdef OBIGO_Q03C_MMS_V01
		#ifdef __MMI_MMS_V01_USE_ASM__
			#define MMS_MEM_SIZE (1024*40) 
        #else
        #define MMS_MEM_SIZE (1024*200)
		#endif
    #elif defined(OBIGO_Q03C_MMS_V02)
        #define MMS_MEM_SIZE (0)
    #else
        #define MMS_MEM_SIZE (0)
    #endif
     

#else /* WAP_USE_ASM */
    #ifdef OBIGO_Q03C_BROWSER
		#ifdef WAP_GLOBAL_MEM_SIZE
			#define WAP_INT_GLOBAL_MEM_SIZE WAP_GLOBAL_MEM_SIZE
		#else 
			#define WAP_INT_GLOBAL_MEM_SIZE (1024*200)
		#endif 
	#else
		#define WAP_INT_GLOBAL_MEM_SIZE (0)
    #endif 

    /* 
     * WAP_SYS_MEM_SIZE is to define the size of WAP dynamic memory pool for obigo system part.
     * If WAP_SYS_MEM_SIZE is defined in custom_wap_config.h, then WAP_INT_SYS_MEMSIZE equals 
     * WAP_SYS_MEM_SIZE, otherwise, WAP_INT_SYS_MEMSIZE is (1024*80) by default. Genernally, 
     * customer do not need to change this value unless "Internal Error" happen at run-time, which
     * means the memory is not enough for system.
     */
    #ifdef WAP_SYS_MEM_SIZE
        #define WAP_INT_SYS_MEMSIZE WAP_SYS_MEM_SIZE
    #else 
    	#ifdef OBIGO_Q03C_MMS_V01
        #define WAP_INT_SYS_MEMSIZE (1024*80)
    	#else
			#ifdef SLIM_WAP_MMS
            	#define WAP_INT_SYS_MEMSIZE (1024*45) 
	    	#else
				#define WAP_INT_SYS_MEMSIZE (1024*80) 
			#endif
    	#endif 
    #endif 
#endif /* WAP_USE_ASM */

#define WAP_APP_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_INT_GLOBAL_MEM_SIZE)
#ifdef MSF_MAX_VM_CONN
#define WAP_SYS_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_INT_SYS_MEMSIZE + ((MSF_MAX_VM_CONN - 6)*6*1024)) /* 6 connections are already supported in original memory configuration. 
                                                                                                       Additionally we need 6K per connection*/
#else
#define WAP_SYS_MEM_SIZE MEM_CHECK_EXTRA_SIZE(WAP_INT_SYS_MEMSIZE)
#endif /*MSF_MAX_VM_CONN*/
#define WAP_SPARE_MEM_SIZE (1024*4)

#ifdef WAP_DOWNLOAD_SPEEDUP
#define WAP_MEM_PER_BIG_PIPE        (15*1024)
#define DL_MEM_SIZE MEM_CHECK_EXTRA_SIZE(MAX_NUM_BIG_PIPES * WAP_MEM_PER_BIG_PIPE)
#else
#define DL_MEM_SIZE (0)
#endif
#ifdef WAP_DECODE_USE_SYS_POOL
#ifdef WAP_USE_ASM
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_SPARE_MEM_SIZE+MMS_MEM_SIZE+DL_MEM_SIZE+WAP_DECODE_SYS_MEMORY_POOL_SIZE)
#else 
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_APP_MEM_SIZE+WAP_SPARE_MEM_SIZE+DL_MEM_SIZE+WAP_DECODE_SYS_MEMORY_POOL_SIZE)
#endif /*WAP_USE_ASM*/
#else
#ifdef WAP_USE_ASM
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_SPARE_MEM_SIZE+MMS_MEM_SIZE+DL_MEM_SIZE)
#else 
#define WAP_MEM_SIZE               (WAP_SYS_MEM_SIZE+WAP_APP_MEM_SIZE+WAP_SPARE_MEM_SIZE+DL_MEM_SIZE)
#endif /*WAP_USE_ASM*/
#endif /*WAP_DECODE_USE_SYS_POOL*/



/***************************************************************************** 
 * Extern Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/



#endif /* WAP_MEM_CFG_H */





