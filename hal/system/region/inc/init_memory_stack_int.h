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
 *   init.h
 *
 * Project:
 * --------
 *   Maui_Software
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

#ifndef __INIT_MEMORY_STACK_H__
#define __INIT_MEMORY_STACK_H__

#include "kal_public_defs.h"
typedef enum
{
   STACK_FREED,
   STACK_ALLOCATED
} switch_stack_state;

typedef struct
{
   void        *stack_start;
   void        *stack_end;
} switch_stack_info_struct;

typedef struct
{
   switch_stack_state  state;
   void                *stack_start;
   void                *stack_end;
   void                *old_sp;
   kal_taskid          task_id;
} switch_stack_history_struct;

#if defined(__LOW_COST_SUPPORT_ULC__)

#define SWITCH_STACK_INFO_NUM 2

#define SWITCH_STACK_HISTORY_NUM 4

#else

#define SWITCH_STACK_INFO_NUM 10

#define SWITCH_STACK_HISTORY_NUM 10

#endif /* __LOW_COST_SUPPORT_ULC__ */


/*************************************************************************
 * Define DSP RX/TX buffer support flag
 *************************************************************************/
#if defined(MT6229) || defined(MT6230) 
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6223) || defined(MT6223P)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6268T) || defined(MT6268H)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6268A) || defined(MT6268) || defined(MT6270A) || defined(MT6276) || defined(MT6573)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(TK6516) || defined(MT6516)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6253T) || defined(MT6253)|| defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6250) || defined(MT6260)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#if defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6255)
#define SUPPORT_DSP_TXRX_BUFF
#endif

#endif /* __INIT_MEMORY_STACK_H__ */
