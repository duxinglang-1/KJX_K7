/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * --------- 
 *   j2me_msg_handler.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/

#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "jal.h"
#include "jnw_internal.h"
#include "jvm_internal.h"
#include "jvm_adaptor.h"
#include "jam_internal.h"
#include "jui_interface.h"
#include "jma_interface.h"
#include "jma_internal.h"
#include "jcc_internal.h"
#include "jam_msg_handler.h"

#include "jam_interface.h"
#include "j2me_custom.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "JavaAgencyProt.h"
#include "wgui_categories.h"
#include "GlobalDefs.h"

#ifdef __DRM_SUPPORT__
#include "DateTimeType.h"
#include "drm_def.h"
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "jwa_internal.h"
#include "j2me_custom_option.h"
#include "j2me_custom_param.h"

#define MMIAPI_USING_SMS
#include "mmiapi_struct.h"

#include "wapadp.h"
#include "wap_adp.h"
#include "mmsadp.h"

#ifdef __JBLENDIA__
#include "jblendia_event.h"
#include "jblendia_adaptation.h"
#endif /* __JBLENDIA__ */ 
#include "cbm_api.h"

#include "IdleHomescreenGProt.h"
#include "App_str.h"
#include "app_ua.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "jam_mvm_manager.h"
#include "jui_interface.h"    //JUI MVM
#include "jvm_trace_interface.h" //Added for performance test
#ifdef __OP02__ 
#include "BrowserGprots.h"
#endif

#ifdef __COSMOS_MMI_PACKAGE__
#include "Vapp_java_srv.h"
#endif
/*************************************************************************
 * External Declaration
 *************************************************************************/
 #ifdef __SUPPORT_JAVA_PUSH__
extern void jam_timealarm_push_ind_handler(
                kal_uint32 type,
                void *callback_entry,
                kal_char *mid_name,
                kal_int32 mid_id,
                kal_char *mid_storagename,
                kal_bool show_popup);
 #endif
extern int j2me_deactivate_socket(kal_int32 vm_id);
extern void set_virtual_direction(kal_bool is_direction);

/* Local Function Declaration */
static void jam_internal_mid_start_req_handler(ilm_struct *ilm_ptr);
static void jam_internal_mid_start_req_post_handler(kal_int32 vm_id,kal_uint32 returnCode);
static void jam_set_mode_req_post_handler(void);
extern void jam_asm_free_mem_notification(kal_bool* keep);
void jam_send_tck_result_ind(kal_int32 error_code);
#ifdef J2ME_SUPPORT_BACKGROUND
static kal_bool jam_asm_memory_is_used();
static void jam_asm_memory_pool_free(void);

#endif

long* g_jam_mvm_whole_heap_space = NULL;
long* g_jam_mvm_little_mem_space_oom = NULL;
kal_uint32 g_jam_mvm_whole_heap_size = 0;
/* Java memory size setup by engineer mode */
extern kal_int32 g_jam_engineer_mode_memory_size;
extern long *javaheap_space;
extern kal_uint32 javaheap_size;
extern kal_bool pending_pushalarm;
extern mmi_java_timealarm_push_res_struct pending_pushalarm_action;
extern kal_eventgrpid g_java_event_group_1;
extern kal_eventgrpid g_java_event_group_2;

kal_bool g_jam_is_med_mem_alloc_for_runtime = KAL_FALSE;
kal_bool g_jam_is_in_java_list = KAL_FALSE;
void jam_mids_np_crc_enc(void);

#if defined( __NEMO_VM__)  || defined( __IJET_VM__)
extern int postInstallMsgBackToProvider(char *);
extern void jam_clean_media_temp_file(void);
#endif /* __NEMO_VM__ or __IJET_VM__ */
/*************************************************************************
 * Global Definition
 *************************************************************************/
extern install_update_struct install_update_status;

/* this is used for Java HTTP over TCP/IP proxy setting */
extern srv_dtcnt_prof_proxy_info_cnf_struct net_prof[MAX_VM_INSTANCE_NUM];


/* Indicate JVM is processing timealarmpush */
extern kal_uint32 g_jam_is_jvm_timealarmpush_session;

/* used by jam_vm_is_busy function indicating if jvm task is busy. This variable will be set firstly
   in the jam_create.c after jvm task has been initilized. */
extern kal_bool g_jam_is_jvm_in_busy;
extern kal_bool g_jam_is_jam_in_busy;
extern kal_bool g_jam_heap_is_releasing;
/* this is used by jam to invoke VM functions */
jam_call_back_function_struct jam_call_back_functions;
kal_bool g_jam_start_up;
kal_int32 g_jam_start_up_mode;
kal_bool endKeyPressed = KAL_FALSE;

/* this is used by Eureka, for EGE_Command_Line */
#ifdef __SUPPORT_INFUSIO__
extern kal_bool g_jam_support_ege_runtime;
#endif 

#ifdef __USB_IN_NORMAL_MODE__
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
#endif 

/* this veriable is used to check if it's in removing state */
kal_bool g_jam_in_remove_state = KAL_FALSE;

kal_uint8 g_jam_current_running_mids_prof_id;
kal_int32 g_jam_current_running_mids_sim;
kal_uint32 g_jam_need_storage_size;
kal_char g_jam_need_storage_drive = 'Z';
kal_bool g_jam_is_local_installed_mids;

extern kal_bool g_jam_stopFS;
/* HTTP External variables */
extern kal_uint32 g_jam_http_conn_id;
extern kal_uint8 *rsp_hdr;
extern kal_uint8 *content;
extern kal_uint16 hdr_len;
extern kal_uint16 data_len;

static jam_getlist_filter_struct *g_jam_last_filter = NULL;

extern kal_int32 g_jam_741_index;

//static kal_bool g_jam_abort_received = KAL_FALSE;

java_java_mid_start_req_struct g_java_start_last_req ;
extern kal_bool g_resend_push;
extern kal_bool g_is_asm_allow_to_launch;
extern java_context_struct g_java;
extern kal_bool g_jam_install_abort;
extern kal_bool g_mmi_java_is_no_network_usable;
extern mmi_java_nw_cntx g_mmi_java_nw_cntx;
extern kal_int32 g_mmi_java_current_selected_vm_id;

extern mmi_java_push_cntx_struct g_mmi_java_push_cntx;

static kal_int32 g_jam_last_terminate_vm_id;
static kal_int32 g_jam_last_terminate_error_code;

static kal_bool g_jam_push_launch_fail;
#ifdef __COSMOS_MMI_PACKAGE__
static kal_bool g_jam_push_launch_need_close_dummy_grp = KAL_FALSE;
#endif
/*************************************************************************
 * Local Definition
 *************************************************************************/
extern long *custom_java_runtimemem_space;
#define LCD_ASM_MEMORY_SIZE (UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT*2)

/*************************************************************************
 * Message Handler
 *************************************************************************/

#ifdef __JAVA_MANAGER__


/*****************************************************************************
 * FUNCTION
 *  mmi_java_cmd_query_req_handler
 * DESCRIPTION
 *  Used to process messge from java manager
 *  and query mids's index by name in the installed list.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_cmd_query_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_int32 mids_start_idx = 0;
    kal_int32 mids_list_count = 0;
    kal_int32 mids_found_idx = -1;
    kal_int32 mids_total_count = 0;
    kal_int32 error_code = J2ME_NO_ERROR;
    kal_bool mids_is_found = KAL_FALSE;
    kal_uint8 mids_found_attribute = 0;
   // ilm_struct *send_ilm = NULL;
    mids_list_info_struct *mids_info_ptr = NULL;
    mmi_java_cmd_query_req_struct *ptrReq = NULL;
    java_mmi_cmd_query_rsp_struct *ptrRsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptrReq = (mmi_java_cmd_query_req_struct*) ilm_ptr->local_para_ptr;
    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
    /* 1.Try to get whole mids list, if set the mids name */
    while ((NULL != ptrReq->mids_name) || (0 <= ptrReq->mids_index))
    {
        error_code = jam_parse_midslistfile(mids_start_idx, 3, &saved_mids_listfile_ptr, 0);      /* JAVA_LIST_CACHE_COUNT */
        mids_start_idx = mids_list_count = mids_total_count = -1;
        if (error_code == J2ME_INSUFFICIENT_MEMORY &&
            (saved_mids_listfile_ptr && (saved_mids_listfile_ptr->mids_avail_count > 0)))
        {
            /* If have at lease one mids, seem successful */
            error_code = J2ME_NO_ERROR;
        }
        if (error_code == J2ME_NO_ERROR && saved_mids_listfile_ptr)
        {
            mids_start_idx = saved_mids_listfile_ptr->mids_avail_indx;
            mids_list_count = saved_mids_listfile_ptr->mids_avail_count;
            mids_total_count = saved_mids_listfile_ptr->mids_count;
        }
        else
        {
            /* if error, free previous saved listfile info */
            jam_call_back_functions.jam_free_list();
            mids_start_idx = mids_list_count = mids_total_count = -1;
        }
        if (0 < mids_list_count)
        {
            mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
            /* Search  the mids from current midslist by name */
            for (idx = 0; (KAL_FALSE == mids_is_found) && (idx < mids_list_count) && (NULL != mids_info_ptr); idx++)
            {
                if ((ptrReq->mids_index == mids_start_idx + idx)
                    || ((NULL != mids_info_ptr->mids_name) && (NULL != ptrReq->mids_name)
                        && 0 == mmi_ucs2icmp((const CHAR*)ptrReq->mids_name, (const CHAR*)mids_info_ptr->mids_name)))
                {
                    mids_is_found = KAL_TRUE;
                }
                if (mids_is_found)
                {
                    mids_found_idx = mids_start_idx + idx;
                    /*   set mids attribute    */
                    if (mids_start_idx + idx < j2me_default_game_count)
                    {
                        mids_found_attribute = IS_DEFAULT_GAME; /* default game can not be updated and removed */
                        if (mids_info_ptr->webside &&
                            strncmp((kal_char*) mids_info_ptr->webside, "h\0t\0t\0p\0:\0/\0/\0", 14) == 0)
                        {
                            mids_found_attribute |= CAN_BE_UPDATE;
                        }
                    }
                    else
                    {
                        mids_found_attribute = CAN_BE_UPDATE | CAN_BE_REMOVE;   /* not a default game */
                    }
                    if (mids_info_ptr->jad_url != NULL)
                    {
                        /* check if the url starts with "file://" */
                        if (strncmp((kal_char*) mids_info_ptr->jad_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
                        {
                            mids_found_attribute &= ~CAN_BE_UPDATE;     /* local install game, can not be updated */
                        }
                    }
                    else if (mids_info_ptr->jar_url != NULL)
                    {
                        /* check if the url starts with "file://" */
                        if (strncmp((kal_char*) mids_info_ptr->jar_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
                        {
                            mids_found_attribute &= ~CAN_BE_UPDATE;     /* local install game, can not be updated */
                        }
                    }
                    break;
                }
                mids_info_ptr = mids_info_ptr->mids_list_info_next;
            }
        }
        /* check whether break loop */
        if ((KAL_FALSE == mids_is_found) && (mids_start_idx + mids_list_count < mids_total_count))
        {
            /* current gotten list not found, so find next if exist */
            mids_start_idx += mids_list_count;
            continue;
        }
        else
        {
            /* 2. Set respond result of mids index actually gotten  */
            ptrRsp = construct_local_para(sizeof(java_mmi_cmd_query_rsp_struct), TD_CTRL);
            ptrRsp->mids_idx = mids_found_idx;
            ptrRsp->mids_attrib = mids_found_attribute;
            ptrRsp->error_code = error_code;
            break;
        }
    }

    /* 3. Reply the query reRult */
    if ((ptrReq->extend_mode == KAL_TRUE) && (ptrReq->confirm_data_ptr))
    {
        *(ptrReq->confirm_data_ptr) = ptrRsp;
        kal_set_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_2, KAL_OR);
    }
    else
    {
        check_incoming_call_and_block();
        java_send_msg_from_active_mod(MOD_MMI,MMI_J2ME_SAP,MSG_ID_JAVA_MMI_CMD_QUERY_RSP,NULL);
    }
}
#endif /* __JAVA_MANAGER__ */ 

#ifdef J2ME_SLIM_MEMORY_SUPPORT
extern kal_bool jam_move_javaruntimesp_to_bigpool(kal_uint32);
extern void jam_move_javaruntimesp_to_smllpool(kal_bool,kal_uint32);
#endif
extern void jam_javaruntime_set_poolflag(kal_uint32);
extern void jam_javaruntime_clear_poolflag(kal_uint32);
extern void jam_javaruntime_clearall_poolflag(void);
extern kal_bool jam_javaruntime_is_poolflag_set(void);


/* make sure javaruntime_sp is not NULL before call this function */
static kal_bool  jam_move_javaruntimesp_to_bigpool(kal_uint32 flag)
{

    long * javaruntime_sp = NULL;

    if(javaruntime_size == DEFAULT_MIN_POOL_SIZE)
    {
         javaruntime_sp = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,DEFAULT_POOL_SIZE);
        
        if(javaruntime_sp != NULL)
        {
            javaruntime_space = javaruntime_sp;
            javaruntime_size = DEFAULT_POOL_SIZE;
            jam_call_back_functions.jam_runtime_memory_finalize();
            jam_call_back_functions.jam_runtime_memory_initialize(javaruntime_space, javaruntime_size);
			jam_javaruntime_set_poolflag(flag);
		    if(saved_mids_listfile_ptr)
		   {
		    saved_mids_listfile_ptr=NULL;  
		    kal_prompt_trace(MOD_MMI, "Here set saved_mids_listfile_ptr= NULL"  );
	       }
            return KAL_TRUE;
        }
    }
	else if(javaruntime_size == DEFAULT_POOL_SIZE)
	{
	    jam_javaruntime_set_poolflag(flag);
		return KAL_TRUE;
	}

    return KAL_FALSE; 

}

static void jam_move_javaruntimesp_to_smllpool(kal_bool is_free_javaruntimesp,kal_uint32 flag)
{

    long * memory_ptr = javaruntime_space;

    if(javaruntime_size == DEFAULT_POOL_SIZE && jam_javaruntime_is_poolflag_set())
    {
        jam_javaruntime_clear_poolflag(flag);
    }

    if(javaruntime_size == DEFAULT_POOL_SIZE && !jam_javaruntime_is_poolflag_set())
    {
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
        /* pluto slim need free list first */
        jam_call_back_functions.jam_free_list();
#endif
        //memory_ptr = javaruntime_space;
        javaruntime_space = (long*)custom_java_runtimemem_space;
        javaruntime_size = DEFAULT_MIN_POOL_SIZE;
        jam_call_back_functions.jam_runtime_memory_finalize();
        jam_call_back_functions.jam_runtime_memory_initialize(javaruntime_space, javaruntime_size);
		
		if(saved_mids_listfile_ptr)
		{
		    saved_mids_listfile_ptr=NULL;  
		    kal_prompt_trace(MOD_MMI, "Here set saved_mids_listfile_ptr= NULL"  );
	    }
        if(is_free_javaruntimesp)
		{
            applib_mem_ap_free(memory_ptr);    
		}
    }



}

void jam_javaruntime_set_poolflag(kal_uint32 flag)
{
	javaruntime_poolflag |= 1 << flag;
}

void jam_javaruntime_clear_poolflag(kal_uint32 flag)
{
	javaruntime_poolflag &= ~(1 << flag);
}

void jam_javaruntime_clearall_poolflag()
{
	javaruntime_poolflag = 0;
}

kal_bool jam_javaruntime_is_poolflag_set()
{
    return javaruntime_poolflag > 0 ? KAL_TRUE : KAL_FALSE;
}

void jam_mids_getlist_exit_free(void)
{
   // long * memory_ptr = NULL;
    kal_trace(MOD_JAM,FUNC_JAM_MIDS_GETLIST_EXIT_FREE,javaruntime_size,DEFAULT_POOL_SIZE,g_jam_is_med_mem_alloc_for_runtime,g_jam_is_in_java_list);
    if(g_jam_is_med_mem_alloc_for_runtime == KAL_TRUE)
    {
        g_jam_is_in_java_list = KAL_FALSE;
    }
#ifdef J2ME_SLIM_MEMORY_SUPPORT
#ifndef __SUPPORT_NATIVE_INSTALLER__
    if(javaruntime_size == DEFAULT_POOL_SIZE && 
        g_jam_is_med_mem_alloc_for_runtime == KAL_TRUE
        && !g_jam_is_jam_in_busy
    )
    {
        jam_call_back_functions.jam_free_list();
        media_free_ext_buffer(MOD_JAM, (void **)&(javaruntime_space));
        g_jam_is_med_mem_alloc_for_runtime = KAL_FALSE;
        javaruntime_space = (long*)custom_java_runtimemem_space;
        javaruntime_size = DEFAULT_MIN_POOL_SIZE;
        jam_call_back_functions.jam_runtime_memory_finalize();
        jam_call_back_functions.jam_runtime_memory_initialize(javaruntime_space, javaruntime_size);
    }
    if(javaheap_space)
    {
        applib_mem_ap_free(javaheap_space);
        javaheap_space = NULL;
        javaheap_size = 0;
    }
#endif /* __SUPPORT_NATIVE_INSTALLER__ */   
#endif /*J2ME_SLIM_MEMORY_SUPPORT*/

#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT )
        jam_call_back_functions.jam_free_list();
        jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_GETLIST);
        kal_trace(JAM_JAVAAGENCY_GROUP,JAM_GET_LIST_EXIT_FREE_RUNTIME,g_jam_is_med_mem_alloc_for_runtime);  
#endif
}
/*****************************************************************************
 * FUNCTION
 *  jam_mids_getlist_req_handler
 * DESCRIPTION
 *  a. In jam_mids_getlist_req_handler(), must free last getlist confirm memory
 *  before to allocate this getlist confirm memory. That means system at
 *  most use 1 memory region as mids getlist confirm.
 *  
 *  b. In mid_getlist_req_handler(), system can keep mids getlist memory.
 *  
 *  c. mids getlist mids list memory is allocated from Java runtime memory pool,
 *  that means the memory will be destroyed after VM start.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_getlist_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *send_ilm;
    kal_int32 error_code = J2ME_NO_ERROR;
    mmi_java_mids_getlist_req_struct *getlist_req_ptr;
    mmi_java_mids_getlist_cnf_struct *getlist_cnf_ptr;
    mids_list_struct *pmids_list = NULL;
    kal_int32 i, mids_count = 0;
    mids_list_info_struct *mids_info_ptr;
    kal_int32 mids_start_indx, mids_list_count;
    kal_char  storage_name[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GETLIST_REQ_HANDLER);
    g_jam_is_jam_in_busy = KAL_TRUE;
    getlist_req_ptr = (mmi_java_mids_getlist_req_struct*) ilm_ptr->local_para_ptr;

    mids_start_indx = (kal_int32) getlist_req_ptr->start_indx;

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    if(!jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_GETLIST))
    {
        /* NO ERROR HANDLE ON THIS CASE */
        error_code = J2ME_INSUFFICIENT_MEMORY;
        mids_count = 0;
        getlist_cnf_ptr = (mmi_java_mids_getlist_cnf_struct*)
        construct_local_para(sizeof(mmi_java_mids_getlist_cnf_struct), TD_CTRL);
        goto FUN_END;
    }
    
#endif 

    /* we need to backup filter for jam_mid_getlist_req_handler use */
    if (g_jam_last_filter)
    {
        if (g_jam_last_filter->vendor_name)
        {
            free_ctrl_buffer(g_jam_last_filter->vendor_name);
        }
        free_ctrl_buffer(g_jam_last_filter);
    }

    if (getlist_req_ptr->filter)
    {
        g_jam_last_filter = (jam_getlist_filter_struct*) get_ctrl_buffer(sizeof(jam_getlist_filter_struct));
        g_jam_last_filter->filter_type = getlist_req_ptr->filter->filter_type;
        g_jam_last_filter->category_type = getlist_req_ptr->filter->category_type;
        g_jam_last_filter->disk_name = getlist_req_ptr->filter->disk_name;
        if (getlist_req_ptr->filter->vendor_name)
        {
            g_jam_last_filter->vendor_name = get_ctrl_buffer((get_ucs2_len(getlist_req_ptr->filter->vendor_name) + 1) << 1);
            memcpy(
                g_jam_last_filter->vendor_name,
                getlist_req_ptr->filter->vendor_name,
                (get_ucs2_len(getlist_req_ptr->filter->vendor_name) + 1) << 1);
        }
		else
			g_jam_last_filter->vendor_name=NULL;
    }

    /* Try to get whole list */
    if (getlist_req_ptr->filter)
    {
        error_code = jam_parse_midslistfile(
                        mids_start_indx,
                        JAVA_LIST_CACHE_COUNT,
                        &saved_mids_listfile_ptr,
                        getlist_req_ptr->filter);
    }
    else
    {
        error_code = jam_parse_midslistfile(mids_start_indx, JAVA_LIST_CACHE_COUNT, &saved_mids_listfile_ptr, 0);
    }

    mids_start_indx = mids_list_count = -1;

    if (error_code == J2ME_INSUFFICIENT_MEMORY && saved_mids_listfile_ptr)
    {
        /* If have at lease one mids, seem successful */
        if (saved_mids_listfile_ptr && (saved_mids_listfile_ptr->mids_avail_count > 0))
        {
            error_code = J2ME_NO_ERROR;
        }

        mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;
        mids_list_count = saved_mids_listfile_ptr->mids_avail_count;
    }
    else if (error_code == J2ME_NO_ERROR && saved_mids_listfile_ptr)
    {
        mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;
        mids_list_count = saved_mids_listfile_ptr->mids_avail_count;
    }
    else
    {
        /* if error, free previous saved listfile info */
        jam_call_back_functions.jam_free_list();
        mids_start_indx = mids_list_count = 0;
    }

    if (saved_mids_listfile_ptr && saved_mids_listfile_ptr->mids_avail_count)
    {
        mids_count = saved_mids_listfile_ptr->mids_count;
        getlist_cnf_ptr =
            (mmi_java_mids_getlist_cnf_struct*)
            construct_local_para(
                (kal_uint16) (sizeof(mmi_java_mids_getlist_cnf_struct) + (saved_mids_listfile_ptr->mids_avail_count - 1) * sizeof(mids_list_struct)),
                TD_CTRL);

        /* | mmi_java_mids_getlist_cnf_struct ( mids_list_struct[1]) | mds_list_struct[mids_count-1] */
        /*                           ^-- *pmids_list                            */
        pmids_list = (mids_list_struct*) ((kal_uint8*) getlist_cnf_ptr +
                                           sizeof(mmi_java_mids_getlist_cnf_struct) - sizeof(mids_list_struct));

        mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;

        for (i = 0; i < saved_mids_listfile_ptr->mids_avail_count && mids_info_ptr; i++)
        {
            kal_uint8 attribute;

            pmids_list[i].mids_id = i + 1 + mids_start_indx;
            pmids_list[i].mids_name = mids_info_ptr->mids_name;
            pmids_list[i].storage_name = mids_info_ptr->mids_root;

            if (mids_info_ptr->mids_icon.icon_size)
            {
                pmids_list[i].mids_icon = (kal_char*) mids_info_ptr->mids_icon.icon_data;
            }
            else
            {
                pmids_list[i].mids_icon = NULL;
            }
            
            trans_ucs2_to_utf8(storage_name,pmids_list[i].storage_name);
            if (((getlist_req_ptr->filter == NULL
                 || getlist_req_ptr->filter->filter_type & JAM_DEFAULT_GAME_FILTER
                 || (getlist_req_ptr->filter->filter_type & JAM_CATEGORY_FILTER && getlist_req_ptr->filter->category_type == JAM_CATEGORY_DUMMY)
                 || getlist_req_ptr->filter->filter_type == JAM_NONE_FILTER)
                && mids_start_indx + i < j2me_default_game_count)
                 #ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__    
				 ||srv_java_appfactory_mids_is_default(storage_name)
				 #endif
                 )
            {
                attribute = IS_DEFAULT_GAME;    /* default game can not be updated and removed */
                if (mids_info_ptr->webside &&
                    strncmp((kal_char*) mids_info_ptr->webside, "h\0t\0t\0p\0:\0/\0/\0", 14) == 0)
                {
                    attribute |= CAN_BE_UPDATE;
                }
            }
            else
            {
            #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
                attribute = CAN_BE_UPDATE | CAN_BE_REMOVE | CAN_BE_SEND;  /* not a default game */
            #else
                attribute = CAN_BE_UPDATE | CAN_BE_REMOVE;
            #endif
            }

            if (mids_info_ptr->jad_url != NULL)
            {
                /* check if the url starts with "file://" */
                if (strncmp((kal_char*) mids_info_ptr->jad_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
                {
                    attribute &= ~CAN_BE_UPDATE;    /* local install game, can not be updated */
                }
            }
            else if (mids_info_ptr->jar_url != NULL)
            {
                /* check if the url starts with "file://" */
                if (strncmp((kal_char*) mids_info_ptr->jar_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
                {
                    attribute &= ~CAN_BE_UPDATE;    /* local install game, can not be updated */
                }
            }
            #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
            if (!jam_drm_can_be_send(mids_start_indx+i+1)) /* mids number start from 1 */
            {
                 attribute &= ~CAN_BE_SEND;   
            }
            #endif
            #ifndef  BROWSER_SUPPORT
                attribute &= ~CAN_BE_UPDATE;
            #endif /*!BROWSER_SUPPORT*/

            pmids_list[i].mids_attributes = attribute;

            pmids_list[i].mid_count = mids_info_ptr->mid_info.mid_count;
            pmids_list[i].mids_size = mids_info_ptr->mids_size;
            mids_info_ptr = mids_info_ptr->mids_list_info_next;
        }
    }
    else
    {
        getlist_cnf_ptr = (mmi_java_mids_getlist_cnf_struct*)
            construct_local_para(sizeof(mmi_java_mids_getlist_cnf_struct), TD_CTRL);
    }

FUN_END:
    getlist_cnf_ptr->mids_count = mids_count;
    /* Reply actual got list start index, and count */
    getlist_cnf_ptr->start_indx = mids_start_indx;
    getlist_cnf_ptr->mids_list_count = mids_list_count;
    getlist_cnf_ptr->error_code = error_code;
    getlist_cnf_ptr->filter = getlist_req_ptr->filter;
     g_jam_is_jam_in_busy = KAL_FALSE;
    if ((getlist_req_ptr->extend_mode == KAL_TRUE) && (getlist_req_ptr->confirm_data_ptr))
    {
        *getlist_req_ptr->confirm_data_ptr = getlist_cnf_ptr;

        kal_set_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_1, KAL_OR);
    }
    else
    {
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_GETLIST_CNF,getlist_cnf_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_mid_getlist_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mid_getlist_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *send_ilm;
    kal_int32 error_code = J2ME_NO_ERROR;
    mmi_java_mid_getlist_req_struct *getlist_req_ptr;
    mmi_java_mid_getlist_cnf_struct *getlist_cnf_ptr = NULL;

    kal_int32 mids_id;
    mids_list_info_struct *mids_info_ptr = NULL;
    mid_list_struct *pmid_list = NULL;
    mid_struct *mid_ptr;
    kal_int32 i, mid_count;
    //kal_int32 mids_start_indx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MID_GETLIST_REQ_HANDLER);
    g_jam_is_jam_in_busy = KAL_TRUE;
    getlist_req_ptr = (mmi_java_mid_getlist_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = getlist_req_ptr->mids_id;
    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT )
        if(!jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_GETLIST))
        {
            error_code = J2ME_INSUFFICIENT_MEMORY;
            mid_count = 0;
            getlist_cnf_ptr =
                (mmi_java_mid_getlist_cnf_struct*) construct_local_para(sizeof(mmi_java_mid_getlist_cnf_struct), TD_CTRL);
            goto FUN_END;
        }
        
#endif
    error_code = jam_parse_midslistfile((mids_id - 1), 1, &saved_mids_listfile_ptr, g_jam_last_filter);
    if (saved_mids_listfile_ptr)
    {
        mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
    }
    else
    {
        error_code = J2ME_MIDS_NOT_EXIST;
    }

    if (mids_id && (error_code == J2ME_NO_ERROR))
    {

        //mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;

        mid_count = mids_info_ptr->mid_info.mid_count;

        if (mid_count)
        {
            getlist_cnf_ptr = (mmi_java_mid_getlist_cnf_struct*) construct_local_para(
                                                                    (kal_uint16) (sizeof (mmi_java_mid_getlist_cnf_struct) + (mid_count - 1) * sizeof(mid_list_struct)),
                                                                    TD_CTRL);

            pmid_list = (mid_list_struct*) ((kal_uint8*) getlist_cnf_ptr +
                                             sizeof(mmi_java_mid_getlist_cnf_struct) - sizeof(mid_list_struct));

            mid_ptr = mids_info_ptr->mid_info.mid_list;

            for (i = 0; i < mid_count && mid_ptr; i++)
            {
                pmid_list[i].mid_id = i + 1;
                pmid_list[i].mid_name = mid_ptr->mid_name;

                if (mid_ptr->mid_icon.icon_size)
                {
                    pmid_list[i].mid_icon = (kal_char*) mid_ptr->mid_icon.icon_data;
                }
                else
                {
                    pmid_list[i].mid_icon = NULL;
                }

                mid_ptr = mid_ptr->mid_next;
            }
        }
        else
        {
            getlist_cnf_ptr =
                (mmi_java_mid_getlist_cnf_struct*) construct_local_para(
                                                    sizeof(mmi_java_mid_getlist_cnf_struct),
                                                    TD_CTRL);
        }
    }
    else
    {
        error_code = J2ME_MIDS_NOT_EXIST;
        mid_count = 0;
        getlist_cnf_ptr =
            (mmi_java_mid_getlist_cnf_struct*) construct_local_para(sizeof(mmi_java_mid_getlist_cnf_struct), TD_CTRL);
    }
FUN_END:
    getlist_cnf_ptr->error_code = error_code;
    getlist_cnf_ptr->mid_count = mid_count;
    g_jam_is_jam_in_busy = KAL_FALSE;
    if ((getlist_req_ptr->extend_mode == KAL_TRUE) && (getlist_req_ptr->confirm_data_ptr))
    {
        *getlist_req_ptr->confirm_data_ptr = getlist_cnf_ptr;
        kal_set_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_2, KAL_OR);
    }
    else
    {
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MID_GETLIST_CNF,getlist_cnf_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_current_running_mids_prof
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 jam_get_current_running_mids_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jam_current_running_mids_prof_id;
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_current_running_mids_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_get_current_running_mids_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_jam_current_running_mids_sim;
}


/*****************************************************************************
 * FUNCTION
 *  jam_send_stop_ind
 * DESCRIPTION
 *  send stop indication to MMI
 * PARAMETERS
 *  exit_code                   [IN]        
 *  is_timealarm_push_start     [IN]        
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_send_stop_ind(kal_int32 vm_id, kal_uint32 exit_code, kal_bool is_timealarm_push_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_stop_ind_struct *stop_ind_ptr;
    //ilm_struct *send_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_ind_ptr = construct_local_para(sizeof(mmi_java_mid_stop_ind_struct), TD_CTRL);

    stop_ind_ptr->exit_code = exit_code;
    stop_ind_ptr->vm_id = vm_id;
    stop_ind_ptr->is_timealarm_push_start = is_timealarm_push_start;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MID_STOP_IND,stop_ind_ptr);

}

static void jam_send_shutdown_all_ind(kal_uint32 exit_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_shutdown_all_ind_struct *ind_ptr;
    //ilm_struct *send_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_ptr = construct_local_para(sizeof(mmi_java_shutdown_all_ind_struct), TD_CTRL);

    ind_ptr->exit_code = exit_code;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_SHUTDOWN_ALL_IND,ind_ptr);

}

/*****************************************************************************
 * FUNCTION
 *  jam_set_audio_volume_req_handler
 * DESCRIPTION
 *  MAUI_02324267
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 * void
 *****************************************************************************/
void jam_set_audio_volume_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_audio_volume_struct *req_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_ptr = (mmi_java_set_audio_volume_struct*) ilm_ptr->local_para_ptr;
    if (jma_audio_player_is_really_active())
    {
        jam_set_aud_volume_level(req_ptr->volume);
    }
}
/*****************************************************************************
 * FUNCTION
 *  jam_jvm_send_mid_start_req
 * DESCRIPTION
 *  send a start message to JVM to start VM.
 * PARAMETERS
 *  mids_id             [IN]        
 *  mid_name_str        [?]         
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_send_mid_start_req( kal_int32 mids_id, kal_int32 mid_id, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct *ilm_ptr;
    jam_jvm_mid_start_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (jam_jvm_mid_start_req_struct*) construct_local_para(sizeof(jam_jvm_mid_start_req_struct), TD_CTRL);
    msg->mids_id = mids_id;
    msg->mid_name_str = NULL;
    msg->mid_id = mid_id;
    msg->vm_id = vm_id;

    java_send_msg_from_active_mod(MOD_J2ME,J2ME_MMI_SAP,MSG_ID_JAM_JVM_MID_START_REQ,msg);
    g_is_asm_allow_to_launch = KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_send_mid_stop_req
 * DESCRIPTION
 *  send stop req to JAM to do some finalize.
 * PARAMETERS
 *  mids_id             [IN]        
 *  mid_name_str        [?]         
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_send_mid_stop_req(kal_uint32 returnCode, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // ilm_struct *ilm_ptr;
    jam_jvm_mid_stop_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!jam_mvm_is_vm_notifyed_stopped(vm_id))
    {
        msg = (jam_jvm_mid_stop_req_struct*) construct_local_para(sizeof(jam_jvm_mid_stop_req_struct), TD_CTRL);
        msg->returnCode = returnCode;
        msg->vm_id = vm_id;
        jam_mvm_set_vm_notifyed_stopped(vm_id);
        java_send_msg_from_active_mod(MOD_JAM,J2ME_MMI_SAP,MSG_ID_JAM_JVM_MID_STOP_REQ,msg);
    }
}
void jam_jvm_send_shutdown_all_notify(kal_int32 error_code)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        kal_int32 idx = 0;
       // ilm_struct *ilm_ptr = NULL;
        jam_jvm_shutdown_all_ind_struct *msg = NULL;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        jam_mvm_set_ctxt_shutdowning();
        for(idx = 0; idx< jam_mvm_get_max_vm_num();idx++)
        {
            if(jam_mvm_is_vm_notifyed_stopped(idx))
                continue;
            jam_jvm_send_mid_stop_req(J2ME_NO_ERROR,idx);
            /*wait current vm terminate successfully*/
            while(jam_mvm_find_vm_instance(idx))
            {
                kal_trace(TRACE_FUNC,FUNC_JAM_MVM_WAIT_MIDLET_STOP, idx);
                kal_sleep_task(5);
            }
        }        
        msg = (jam_jvm_shutdown_all_ind_struct*) construct_local_para(sizeof(jam_jvm_shutdown_all_ind_struct), TD_CTRL);
        msg->returnCode = error_code;
        java_send_msg_from_active_mod(MOD_JAM,J2ME_MMI_SAP,MSG_ID_JAM_JVM_SHUTDOWN_ALL_IND,msg);

}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_mid_start_cnf_handler
 * DESCRIPTION
 *  To launch a specific MIDlet of a MIDlet suite by MIDS ID and MID ID
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_mid_start_cnf_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_uint32 returnCode;
    //kal_int32 vm_id = 0;
    //kal_wchar *mid_name_str = NULL;
    //jam_jvm_mid_start_cnf_struct *mid_start_req_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* mid_start_req_ptr = (jam_jvm_mid_start_cnf_struct*) ilm_ptr->local_para_ptr;
    returnCode = mid_start_req_ptr->returnCode;
    mid_name_str = mid_start_req_ptr->mid_name_str;
    if (returnCode != J2ME_NO_ERROR)
    {
        jam_internal_mid_start_req_post_handler(vm_id,returnCode, mid_name_str);
    }*/

}

/* Justin 004 */
/*****************************************************************************
 * FUNCTION
 *  jam_jvm_send_tck_start_req
 * DESCRIPTION
 *  send a start message to JVM to start VM.
 * PARAMETERS
 *  tck_mode        [IN]        
 *  to_execute      [IN]        
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_send_tck_stop_req(kal_int32 returnCode, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_jvm_tck_stop_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (jam_jvm_tck_stop_req_struct*) construct_local_para(sizeof(jam_jvm_tck_stop_req_struct), TD_CTRL);
    msg->returnCode = returnCode;
    msg->vm_id = vm_id;
    java_send_msg_from_active_mod(MOD_JAM,J2ME_MMI_SAP,MSG_ID_JAM_JVM_TCK_STOP_REQ,msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_jvm_send_tck_start_req
 * DESCRIPTION
 *  send a start message to JVM to start VM.
 * PARAMETERS
 *  tck_mode        [IN]        
 *  to_execute      [IN]        
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_send_tck_start_req(java_mode_enum tck_mode, kal_bool to_execute, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct *ilm_ptr;
    jam_jvm_tck_start_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (jam_jvm_tck_start_req_struct*) construct_local_para(sizeof(jam_jvm_tck_start_req_struct), TD_CTRL);
    msg->tck_mode = tck_mode;
    msg->to_execute = to_execute;
    msg->vm_id = vm_id;
    java_send_msg_from_active_mod(MOD_J2ME,J2ME_MMI_SAP,MSG_ID_JAM_JVM_TCK_START_REQ,msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_jvm_tck_start_cnf_handler
 * DESCRIPTION
 *  To launch a specific MIDlet of a MIDlet suite by MIDS ID and MID ID
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_tck_start_cnf_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    /* jam_set_mode_req_post_handler(); */

}

/*****************************************************************************
 * FUNCTION
 *  jam_external_mid_start_req_handler
 * DESCRIPTION
 *  To launch a specific MIDlet of a MIDlet suite by MIDS ID and MID ID
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
 void jam_external_mid_start_req_handler(ilm_struct * ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_internal_mid_start_req_handler(ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_internal_mid_start_req_handler
 * DESCRIPTION
 *  To launch a specific MIDlet of a MIDlet suite by MIDS ID and MID ID
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_internal_mid_start_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *send_ilm = NULL;
    kal_int32 mids_id = -1;
    kal_int32 mid_id = -1;
    kal_int32 returnCode = J2ME_NO_ERROR;
    mmi_java_mid_start_req_struct *start_req_ptr = NULL;
    java_java_mid_start_req_struct *java_start_req_ptr = NULL;
    mmi_java_mid_start_cnf_struct *start_cnf_ptr = NULL;
    kal_wchar *mid_name_str = NULL;
    //kal_bool abort_received = KAL_FALSE;

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    mmi_java_get_confirm_ind_struct *get_confirm;
    kal_uint8 vk_permission_level = 0;
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 
    kal_char *mids_storage_name = NULL;
    kal_int32 vm_id = INVALIDE_VM_ID;
    kal_bool is_launch_as_bg_running = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr->msg_id == MSG_ID_MMI_JAVA_MID_START_REQ)
    {
        start_req_ptr = (mmi_java_mid_start_req_struct*) ilm_ptr->local_para_ptr;
        mid_id = start_req_ptr->mid_id;
        mids_storage_name = start_req_ptr->storage_name;
        mid_name_str = start_req_ptr->mid_name;
        is_launch_as_bg_running = start_req_ptr->is_launch_as_bg_running;
        g_jam_start_up_mode = 1;

    }
    else if (ilm_ptr->msg_id == MSG_ID_JAVA_JAVA_MID_START_REQ ||
        ilm_ptr->msg_id == MSG_ID_RESEND_TIMEALARM_PUSH_REQ)
    {
        java_start_req_ptr = (java_java_mid_start_req_struct*) ilm_ptr->local_para_ptr;
        mid_id = java_start_req_ptr->mid_id;
        mids_storage_name = java_start_req_ptr->storage_name;
        mid_name_str = java_start_req_ptr->mid_name;
        is_launch_as_bg_running = java_start_req_ptr->is_launch_as_bg_running;
        g_jam_start_up_mode = 0;
        jam_call_back_functions.jam_free_list();
    }

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    vk_permission_level = jam_get_vk_permission();

    if (vk_permission_level == J2ME_CHOICE_ALLOW)
    {
        set_virtual_direction(KAL_TRUE);
    }
    else if (vk_permission_level == J2ME_CHOICE_NEVER)
    {
        set_virtual_direction(KAL_FALSE);
    }
    else if (vk_permission_level == J2ME_CHOICE_PROMPT)
    {
        get_confirm = construct_local_para(sizeof(mmi_java_get_confirm_ind_struct), TD_CTRL);
        get_confirm->confirm_enum = JAVA_CONFIRM_FOURWAY_KEY_ENUM;
        get_confirm->confirm_title = STR_JAVA_CONFIRM_VIRTUAL_KEYPAD_TITLE;
        get_confirm->confirm_msg = (kal_char*) GetString(STR_JAVA_CONFIRM_VIRTUAL_KEYPAD);
        get_confirm->confirm_image = JAVA_CONFIRM_NOTIFICATION_CATEGORY;
        get_confirm->window_category = JAVA_CONFIRM_NOTIFICATION_CATEGORY;

        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_CONFIRM_IND,get_confirm);

        set_virtual_direction(get_next_event
                              (KAL_TRUE, MSG_ID_MMI_JAVA_GET_CONFIRM_RES, KAL_FALSE, KAL_TRUE, &abort_received));
        if(abort_received == KAL_TRUE)
        {
            returnCode = J2ME_USER_CANCEL;
            goto FUN_END;
        }
    }

#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */ 
    vm_id = jam_mvm_get_vm_instance((kal_char *)mids_storage_name, mid_id, JAVA_NORMAL_MODE,&returnCode);        
    if (returnCode != J2ME_NO_ERROR)
    {
        goto FUN_END;
    }

    if(returnCode != J2ME_NO_ERROR)
    {
        goto FUN_END;
    }

    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(mids_storage_name);
    if(mids_id < 0)
    {
        returnCode = J2ME_READ_MIDS_LIST_FIlE_FAILURE;
        goto FUN_END;
    }
    returnCode = jam_call_back_functions.jam_start_up(mids_id, mid_id,vm_id);
FUN_END:
    if (returnCode == J2ME_NO_ERROR)
    {
        if(g_jam_is_jvm_in_busy == KAL_FALSE)
        {
            g_jam_is_jvm_in_busy = KAL_TRUE;
        }
        g_jam_start_up = KAL_TRUE;
        jam_mvm_set_vm_mid_name(vm_id,mid_name_str);
    }
    else
    {
        if(g_jam_start_up_mode == 0 && java_start_req_ptr!= NULL)
        {
            g_java_start_last_req.game_type = java_start_req_ptr->game_type;
            g_java_start_last_req.is_launch_as_bg_running = java_start_req_ptr->is_launch_as_bg_running;
            g_java_start_last_req.mids_id = java_start_req_ptr->mids_id;
            g_java_start_last_req.mid_id = java_start_req_ptr->mid_id;
            g_java_start_last_req.wap_prof_id = java_start_req_ptr->wap_prof_id;
            g_java_start_last_req.mid_name = (kal_wchar*) get_ctrl_buffer((get_ucs2_len(java_start_req_ptr->mid_name) << 1) + 2);
            memcpy(g_java_start_last_req.mid_name, java_start_req_ptr->mid_name, (get_ucs2_len(java_start_req_ptr->mid_name) << 1));
            g_java_start_last_req.mid_name[get_ucs2_len(java_start_req_ptr->mid_name)] = 0;
            g_java_start_last_req.storage_name = (kal_char*) get_ctrl_buffer(strlen(java_start_req_ptr->storage_name) + 1);
            memcpy(g_java_start_last_req.storage_name, java_start_req_ptr->storage_name, strlen(java_start_req_ptr->storage_name));
            g_java_start_last_req.storage_name[strlen(java_start_req_ptr->storage_name)] = 0;
            if (returnCode == J2ME_VM_IS_BUSY)
            {
                g_jam_push_launch_fail = KAL_TRUE;
            }
        }
        if(vm_id != INVALIDE_VM_ID)
        {
            jam_mvm_terminate_vm(vm_id);
            vm_id = INVALIDE_VM_ID;
        }
        if (returnCode == J2ME_INSUFFICIENT_MEMORY || returnCode == J2ME_INSUFFICIENT_MEMORY_WHOLE_POOL)
        {
            g_is_asm_allow_to_launch = KAL_FALSE;
        }
    }

    if(mids_storage_name)
    {
        free_ctrl_buffer(mids_storage_name);
        mids_storage_name = NULL;
    }
    if(mid_name_str)
    {
        free_ctrl_buffer(mid_name_str);
        mid_name_str = NULL;
    }
    start_cnf_ptr = construct_local_para(sizeof(mmi_java_mid_start_cnf_struct), TD_CTRL);
    start_cnf_ptr->error_code = returnCode;
    start_cnf_ptr->is_launch_as_bg_running = is_launch_as_bg_running;
    start_cnf_ptr->vm_id = vm_id;
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MID_START_CNF,start_cnf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_internal_mid_start_req_post_handler
 * DESCRIPTION
 *  To launch a specific MIDlet of a MIDlet suite by MIDS ID and MID ID
 * PARAMETERS
 *  returnCode          [IN]        
 *  mid_name_str        [?]         
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void jam_internal_mid_start_req_post_handler(kal_int32 vm_id,kal_uint32 returnCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_terminated_by_user = KAL_FALSE;
    kal_bool is_timealarm_push_start = KAL_FALSE;
    mmi_java_terminate_notify_struct * terminate_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!jam_mvm_get_vm_is_auto_terminated(vm_id) && (jam_mvm_is_shutdowning()||
        jam_mvm_get_vm_state(vm_id) == JVM_TERMINATING_STATE))
    {
        is_terminated_by_user = KAL_TRUE;
    }
    //jam_backlight_deinit();

    if (returnCode == JAR_NOT_FOUND || returnCode == DISK_NOT_FOUND || returnCode == UNSUPPORT_MIDLET)
    {
        is_timealarm_push_start = KAL_FALSE;
    }
    else if (returnCode == DRM_PROHIBIT)
    {
        is_timealarm_push_start = KAL_FALSE;
    }
    else
    {
        if (g_jam_start_up_mode == 1)
        {
            is_timealarm_push_start = KAL_FALSE;
        }
        else if (g_jam_start_up_mode == 0)
        {
            is_timealarm_push_start = KAL_TRUE;
            if(!g_is_asm_allow_to_launch)
                g_is_asm_allow_to_launch = KAL_TRUE;
        }
        endKeyPressed = KAL_FALSE;
    }

    terminate_ptr = (mmi_java_terminate_notify_struct *) get_ctrl_buffer(sizeof(mmi_java_terminate_notify_struct));
    terminate_ptr->vm_id = vm_id;
    if(is_terminated_by_user)
    {
        terminate_ptr->return_code = J2ME_NO_ERROR;
    }
    else
    {
        terminate_ptr->return_code = returnCode;
    }

    terminate_ptr->is_timealarm_push_start = is_timealarm_push_start;
    terminate_ptr->is_tck = KAL_FALSE;

    if (endKeyPressed)
    {
        jam_goto_idle_screen(terminate_ptr);
    }
    else
    {
        jam_exit_screen(terminate_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_internal_mid_start_req_terminate_notify_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_internal_mid_start_req_terminate_notify_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_terminate_notify_struct * terminate_ptr = (mmi_java_terminate_notify_struct*) ilm_ptr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_mvm_terminate_vm(terminate_ptr->vm_id);

    if (!terminate_ptr->is_tck)
    {
        if (jam_mvm_get_running_count() > 0)
        {
            jam_send_stop_ind(terminate_ptr->vm_id,terminate_ptr->return_code, terminate_ptr->is_timealarm_push_start);
        }
        else
        {
            g_jam_last_terminate_vm_id = terminate_ptr->vm_id;
            g_jam_last_terminate_error_code = terminate_ptr->return_code;
        }
	    
        g_jam_start_up = KAL_FALSE;
    }
    else
    {
        jam_mvm_shutdown_all();
        jam_send_tck_result_ind(terminate_ptr->return_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_mid_start_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mid_start_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MID_START_REQ_HANDLER);

    jam_internal_mid_start_req_handler(ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_whole_heap_alloc
 * DESCRIPTION
 *  Malloc java whole heap before frist launch a midlet. only canbe called by JAM
 * PARAMETERS
 *  void       [IN] 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_whole_heap_alloc(java_mode_enum java_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 return_size = 0;
    kal_int32  error_code = J2ME_NO_ERROR;
    kal_bool need_whole_pool_memory = KAL_FALSE;
    long* whole_heap_space = NULL;
    kal_uint32 whole_heap_size = 0;
    //kal_int32 remain_bits;
    kal_uint8* memory_ptr = NULL;
	#ifdef J2ME_SLIM_MEMORY_SUPPORT
    kal_uint32 runtime_alloc_size = DEFAULT_POOL_SIZE;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_jam_mvm_whole_heap_space!=NULL)
    {
        kal_trace(MOD_JAM, FUNC_JAM_MVM_HEAP_ALLOC_BUSY);
        return J2ME_VM_IS_BUSY;
    }

#if DATACACHE_FBBR_ON
#ifdef __APPLIB_MEM_AP_FBBR_ALIGN_POOL__
    whole_heap_space = applib_mem_ap_alloc_FBBR_pool(APPLIB_MEM_AP_ID_JAVA, &return_size);
    //kal_prompt_trace(MOD_J2ME,"----[jam_msg_handler.c] applib_mem_ap_alloc_FBBR_pool----");
#else /* __APPLIB_MEM_AP_FBBR_ALIGN_POOL__ */ 
    whole_heap_space = applib_mem_ap_alloc_full_pool(APPLIB_MEM_AP_ID_JAVA, &return_size);
    need_whole_pool_memory = KAL_TRUE;
    //kal_prompt_trace(MOD_J2ME,"----[jam_msg_handler.c] applib_mem_ap_alloc_full_pool----");
#endif /* __APPLIB_MEM_AP_FBBR_ALIGN_POOL__ */ 
    /* for saving the L1 cachable register under FBBR mode */
    if ((((kal_int32) whole_heap_space & (4 * 1024 * 1024 - 1)) == 0) && return_size >= 8 * 1024 * 1024)
    {
        return_size = 8 * 1024 * 1024;
    }
    else if (((((kal_int32) whole_heap_space & (4 * 1024 * 1024 - 1)) == 0) ||
              ((((kal_int32) whole_heap_space + 1024 * 1024) & (4 * 1024 * 1024 - 1)) == 0))
             && return_size >= 6 * 1024 * 1024)
    {
        return_size = 6 * 1024 * 1024;
    }
    else if (((((kal_int32) whole_heap_space & (4 * 1024 * 1024 - 1)) == 0) ||
              ((((kal_int32) whole_heap_space + 2 * 1024 * 1024) & (4 * 1024 * 1024 - 1)) == 0))
             && return_size >= 4 * 1024 * 1024)
    {
        return_size = 5 * 1024 * 1024;
    }
    else if ((((kal_int32) whole_heap_space & (2 * 1024 * 1024 - 1)) == 0) && return_size >= 4 * 1024 * 1024)
    {
        return_size = 4 * 1024 * 1024;
    }
    else if (return_size >= 3072 * 1024)
    {
        return_size = 3072 * 1024;
    }
    else if (return_size >= 2048 * 1024)
    {
        return_size = 2048 * 1024;
    }
    else if (return_size >= 1536 * 1024)
    {
        return_size = 1536 * 1024;
    }
    else if (return_size >= 1280 * 1024)
    {
        return_size = 1280 * 1024;
    }
    else if (return_size >= 1152 * 1024)
    {
        return_size = 1152 * 1024;
    }
    else if (return_size >= 1024 * 1024)
    {
        return_size = 1024 * 1024;
    }
    else if (return_size >= 768 * 1024)
    {
        return_size = 768 * 1024;
    }
    else if (return_size >= 512 * 1024)
    {
        return_size = 512 * 1024;
    }
    else
    {
        return_size &= ~(128 * 1024 - 1);
    }
#else /* DATACACHE_FBBR_ON */ 
#ifdef __PLUTO_MMI_PACKAGE__

if (g_jam_engineer_mode_memory_size > 0 && g_jam_engineer_mode_memory_size < DEFAULTHEAPSIZE)
{
    whole_heap_size = g_jam_engineer_mode_memory_size;
}
else
{
    whole_heap_size = DEFAULTHEAPSIZE;
}

#ifndef J2ME_SLIM_MEMORY_SUPPORT
    memory_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,whole_heap_size);
    if(NULL != memory_ptr)
    {
        /* javaheap */
        g_jam_mvm_whole_heap_space = (long * )(memory_ptr);
        g_jam_mvm_whole_heap_size = whole_heap_size;
    
    }
    else
    {
        error_code = J2ME_INSUFFICIENT_MEMORY;
    }
    return error_code;
#else /* J2ME_SLIM_MEMORY_SUPPORT*/

    /* force free big pool */
	jam_javaruntime_clearall_poolflag();

    jam_mids_getlist_exit_free();
//MAUI_03344246 start
    applib_mem_ap_free_all_cache();          
//MAUI_03344246 end
    memory_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_JAVA,whole_heap_size + runtime_alloc_size);
    /* jui buffer : slim use gdi buffer */
    jui_lcd_buffer = NULL;
    if(NULL != memory_ptr)
    {
        applib_mem_ap_free(memory_ptr);
        
        /* javaruntime */
        javaruntime_space = (long * )applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,runtime_alloc_size);
        javaruntime_size = runtime_alloc_size;
		jam_javaruntime_set_poolflag(JAVARUNTIME_POOL_RUNTIME);
                
        /* javaheap */
        g_jam_mvm_whole_heap_space = (long * )applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,whole_heap_size);
        g_jam_mvm_whole_heap_size = whole_heap_size;
    
    }
    else
    {
        error_code = J2ME_INSUFFICIENT_MEMORY;
    }
return error_code;

#endif
#else /* __PLUTO_MMI_PACKAGE__ */
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    kal_trace(JAM_JAVAAGENCY_GROUP,JAM_MVM_WHOLE_HEAP_ALLOC_6);
    vapp_java_enable_lock_screen();
    mmi_frm_asm_prepare(APP_JAVA, 0, jam_mem_prepare_proc, NULL, MMI_FRM_ASM_F_NONE);
    jam_mvm_retrieve_asm_eg_event();
    vapp_java_disable_lock_screen();
    if(!g_jam_mvm_little_mem_space_oom && g_jam_mvm_whole_heap_space != NULL)
    {
        g_jam_mvm_little_mem_space_oom = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, 1);
    }
#else
    memory_ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, DEFAULTHEAPSIZE + DEFAULT_POOL_SIZE);
          // MMI_ASSERT(memory_ptr); // impossible
          if(NULL == memory_ptr)
          {
             error_code = J2ME_INSUFFICIENT_MEMORY;
            return error_code;
            }
           javaruntime_space = (long * )(memory_ptr);
           javaruntime_size = DEFAULT_POOL_SIZE;
           jam_javaruntime_set_poolflag(JAVARUNTIME_POOL_RUNTIME);
           g_jam_mvm_whole_heap_space = (long * )(memory_ptr + javaruntime_size);
           g_jam_mvm_whole_heap_size = DEFAULTHEAPSIZE;
    
    
#endif

    if(g_jam_mvm_whole_heap_space)
    return J2ME_NO_ERROR;
#endif 

#endif /* DATACACHE_FBBR_ON */ 
    if(java_mode != JAVA_NORMAL_MODE)
    {
        if (whole_heap_space != NULL)
        {
            return_size = DEFAULTHEAPSIZE;
        }
        else
        {
            return_size = applib_mem_ap_get_max_alloc_size();
            if (return_size > DEFAULTHEAPSIZE)
            {
                return_size = DEFAULTHEAPSIZE;
            }
            whole_heap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, return_size);
        }
    }
    if (whole_heap_space == NULL)
    {
#ifdef __APPLIB_MEM_AP_FBBR_ALIGN_POOL__
    if(whole_heap_space!= NULL)
    {
        applib_mem_ap_free_FBBR_pool(APPLIB_MEM_AP_ID_JAVA);
        whole_heap_space = NULL;
    }
#else 
    if(whole_heap_space!= NULL)
    {
        applib_mem_ap_free(whole_heap_space);
        whole_heap_space = NULL;
    }
#endif  
        if (whole_heap_space == NULL && need_whole_pool_memory)
        {
            error_code = J2ME_INSUFFICIENT_MEMORY_WHOLE_POOL;
            kal_trace(JAM_JAVAAGENCY_GROUP,JAM_MVM_WHOLE_HEAP_ALLOC_7);
        }
        else
        {
            error_code = J2ME_INSUFFICIENT_MEMORY;
            kal_trace(JAM_JAVAAGENCY_GROUP,JAM_MVM_WHOLE_HEAP_ALLOC_8);
        }
        whole_heap_space = NULL;
        whole_heap_size = 0;
    }    
    else
    {
        if (g_jam_engineer_mode_memory_size > 0 && g_jam_engineer_mode_memory_size < return_size)
        {
            return_size = g_jam_engineer_mode_memory_size;
        }
        whole_heap_size = return_size;        
        error_code = J2ME_NO_ERROR;
    }
    g_jam_mvm_whole_heap_space = whole_heap_space;
    g_jam_mvm_whole_heap_size = whole_heap_size;
    FBBR_heap_init();

    return error_code;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mvm_whole_heap_release
 * DESCRIPTION
 *  Release whole java heap after last a midlet terminated. only canbe called by JAM
 * PARAMETERS
 *  void       [IN] 
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 jam_mvm_whole_heap_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool keep_little = KAL_FALSE;
	#ifndef __PLUTO_MMI_PACKAGE__
    long *memory_ptr = NULL;
	#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FBBR_heap_finalize();
    if(g_jam_mvm_whole_heap_space)
    {
 #ifdef __PLUTO_MMI_PACKAGE__
    #ifdef J2ME_SLIM_MEMORY_SUPPORT
        if(javaruntime_space)
        {
            jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_RUNTIME); 

            applib_mem_ap_free(g_jam_mvm_whole_heap_space);
            jui_lcd_buffer = NULL;
           
            jam_asm_free_mem_notification(&keep_little);     
        }
    #else
        applib_mem_ap_free(g_jam_mvm_whole_heap_space);      
        jam_asm_free_mem_notification(&keep_little);    
    #endif    
#else
#ifndef J2ME_SLIM_MEMORY_SUPPORT
        kal_trace(JAM_JAVAAGENCY_GROUP,JAM_MVM_WHOLE_HEAP_ALLOC_9);
        if(javaruntime_space)
        {
            memory_ptr = javaruntime_space;
            jam_move_javaruntimesp_to_smllpool(KAL_FALSE,JAVARUNTIME_POOL_RUNTIME);
            mmi_frm_asm_free_r(APP_JAVA, memory_ptr); /*Java Runtime and Heap*/

            
#ifdef J2ME_SUPPORT_BACKGROUND
			/* free asm memory */
			if(jam_asm_memory_is_used())
			{
			    jam_asm_memory_pool_free();
			}
#endif
            
        }
        if(g_jam_mvm_little_mem_space_oom && !mmi_frm_group_is_present(VAPP_JAVA))
        {
            applib_mem_ap_free(g_jam_mvm_little_mem_space_oom);/*Little memory for OOM list */ 
        }
        else
        {
            keep_little = KAL_TRUE;
            
        }
        
#else//cosmos and slim
       kal_trace(JAM_JAVAAGENCY_GROUP,JAM_MVM_WHOLE_HEAP_ALLOC_9);
       if(javaruntime_space)
       {
            memory_ptr = javaruntime_space;
            jam_move_javaruntimesp_to_smllpool(KAL_FALSE,JAVARUNTIME_POOL_RUNTIME);
            applib_mem_ap_free(memory_ptr); /*Java Runtime and Heap*/
               
                           
       #ifdef J2ME_SUPPORT_BACKGROUND
             /* free asm memory */
           if(jam_asm_memory_is_used())
           {
                jam_asm_memory_pool_free();
           }
       #endif
                           
       }
        
#endif
        jam_asm_free_mem_notification(&keep_little);
#endif
        while(g_jam_mvm_whole_heap_space != NULL)
        {
            //clean_event();
            kal_sleep_task(1);
        }
        g_jam_mvm_whole_heap_size = 0;
    }
    return J2ME_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  jam_mid_stop_res_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mid_stop_res_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_java_mid_stop_res_struct *stop_res_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MID_STOP_RES_HANDLER);
    //stop_res_ptr = (mmi_java_mid_stop_res_struct*) ilm_ptr->local_para_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_getinfo_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_getinfo_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *send_ilm;
    kal_uint32 mids_id;
    kal_int32 error_code = J2ME_NO_ERROR;
    mmi_java_mids_getinfo_req_struct *getinfo_req_ptr;
    mmi_java_mids_getinfo_cnf_struct *getinfo_cnf_ptr;
    mids_list_info_struct *pmids_list = NULL;
    mid_struct *cur_mid_ptr;
    kal_uint32 i, mids_mid_count = 0;
    kal_int32 mids_start_indx;
    WCHAR *wfilename;
    kal_int32 handle = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GETINFO_REQ_HANDLER);

    getinfo_req_ptr = (mmi_java_mids_getinfo_req_struct*) ilm_ptr->local_para_ptr;

    mids_id = getinfo_req_ptr->mids_id;

    /* Update working internal system directory path */
    g_jam_is_jam_in_busy = KAL_FALSE;
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_GETLIST);
#endif 

    if (mids_id <= j2me_default_game_count)
    {
        wfilename = jam_call_back_functions.jam_get_jar_storage_name_from_mids_id(jam_listmem_malloc, mids_id);
        if (jam_call_back_functions.jam_restore_default_game && (kal_char) wfilename[0] != work_sys_dir_path[0] &&
            (handle = FS_Open(wfilename, (FS_READ_ONLY | FS_OPEN_SHARED))) < 0)
        {
            jam_call_back_functions.jam_restore_default_game(mids_id);
        }
        FS_Close(handle);
        jam_listmem_free(wfilename);
    }

    jam_parse_midslistfile( mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);

    if (mids_id && saved_mids_listfile_ptr)
    {
        if (error_code == J2ME_NO_ERROR)
        {
            pmids_list = saved_mids_listfile_ptr->mids_info_list;
            mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;

            for (i = 1; i < mids_id - mids_start_indx && pmids_list; i++)
            {
                pmids_list = pmids_list->mids_list_info_next;
            }
        }
    }
    else
    {
        error_code = J2ME_MIDS_NOT_EXIST;
    }

    if (error_code == J2ME_NO_ERROR && pmids_list)
    {
        mids_mid_count = pmids_list->mid_info.mid_count;
    }
    getinfo_cnf_ptr = construct_local_para(
                        (kal_uint16) (sizeof(mmi_java_mids_getinfo_cnf_struct) + (mids_mid_count - 1) * sizeof(kal_wchar*)),
                        TD_CTRL);

    getinfo_cnf_ptr->error_code = error_code;

    if (error_code == J2ME_NO_ERROR)
    {

        WCHAR *wfilename = NULL;
        kal_int32 len = 0;

        wfilename = jam_call_back_functions.jam_get_jar_storage_name_from_mids_id(jam_listmem_malloc, mids_id);
        len = get_ucs2_len(wfilename);
        getinfo_cnf_ptr->mids_info.mids_filename = (kal_wchar*) get_ctrl_buffer((len + 1) * 2);
        kal_mem_cpy(getinfo_cnf_ptr->mids_info.mids_filename, wfilename, (len + 1) * 2);
        jam_listmem_free(wfilename);

        getinfo_cnf_ptr->mids_info.mids_name = pmids_list->mids_name;
        getinfo_cnf_ptr->mids_info.mids_size = pmids_list->mids_size;
        getinfo_cnf_ptr->mids_info.mids_version = pmids_list->mids_version;
        getinfo_cnf_ptr->mids_info.mids_vendor = pmids_list->mids_vendor;
        getinfo_cnf_ptr->mids_info.mids_description = pmids_list->mids_description;
        /* A MIDlet has webside starting with "file://" is a local install MIDlet.
           We should not display the webside information to user since it is not meaningful */
        if (strncmp((kal_char*) pmids_list->webside, "f\0i\0l\0e\0:\0/\0/\0", 14) != 0)
        {
            getinfo_cnf_ptr->mids_info.mids_webside = pmids_list->webside;
        }
        else
        {
            getinfo_cnf_ptr->mids_info.mids_webside = (kal_wchar*) "\0\0";
        }
        getinfo_cnf_ptr->mids_info.mids_authorized = pmids_list->mids_authorized;
        getinfo_cnf_ptr->mids_info.mids_authorized_by = pmids_list->mids_authorized_by;
        getinfo_cnf_ptr->mids_info.mids_auto_start_connection = pmids_list->mids_auto_start;

        getinfo_cnf_ptr->mids_info.mids_mid_count = mids_mid_count;

        cur_mid_ptr = pmids_list->mid_info.mid_list;
        for (i = 0; i < mids_mid_count && cur_mid_ptr; i++)
        {
            getinfo_cnf_ptr->mids_info.mids_mid_name_list[i] = cur_mid_ptr->mid_name;
            cur_mid_ptr = cur_mid_ptr->mid_next;
        }

    }

    #ifdef __PLUTO_MMI_PACKAGE__
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF,getinfo_cnf_ptr);
    #elif defined (__COSMOS_MMI_PACKAGE__)
    mmi_java_recv_mids_getinfo_cnf(getinfo_cnf_ptr);
    kal_set_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_3, KAL_OR);
    #endif
    g_jam_is_jam_in_busy = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_get_setting_req_handler
 * DESCRIPTION
 *  To get and set security setting.
 *  The parameters of the MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ message
 *  must follow the rule described in SAP
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_get_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //ilm_struct *send_ilm;
    mmi_java_mids_get_setting_req_struct *get_setting_req_ptr;
    mmi_java_mids_get_setting_cnf_struct *get_setting_cnf_ptr;

    kal_int32 mids_id;
    mids_list_info_struct *mids_info_ptr = NULL;
    kal_wchar* storage_name;
    kal_int32 len =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GET_SETTING_REQ_HANDLER);

    get_setting_req_ptr = (mmi_java_mids_get_setting_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = get_setting_req_ptr->mids_id;

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_GETSETTING);
#endif 
    if (get_setting_req_ptr->storage_name == NULL)
    {
        jam_parse_midslistfile(mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);
		
        mids_info_ptr = find_mids_info_by_id(mids_id, KAL_FALSE);
		
        /* mids not exist */
        if (mids_info_ptr == NULL)
        {
            get_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_get_setting_cnf_struct), TD_CTRL);
		
            get_setting_cnf_ptr->error_code = J2ME_MIDS_NOT_EXIST;
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF,get_setting_cnf_ptr);
            return;
        }
        len = app_ucs2_strlen((const kal_int8 *)mids_info_ptr->mids_root);
        storage_name = (kal_wchar*)get_ctrl_buffer((len+1)<<1);
		app_ucs2_strcpy((kal_int8 *) storage_name,(const kal_int8 *) mids_info_ptr->mids_root);
    }
    else
    {   
        len = strlen(get_setting_req_ptr->storage_name);
        storage_name = (kal_wchar*)get_ctrl_buffer((len+1)<<1);
        app_asc_str_to_ucs2_str((kal_int8 *) storage_name,(kal_int8 *) get_setting_req_ptr->storage_name);
    }
    get_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_get_setting_cnf_struct), TD_CTRL);


    get_setting_cnf_ptr->storage_name = get_setting_req_ptr->storage_name;
    
    get_setting_cnf_ptr->error_code = jam_call_back_functions.jam_get_setting(
                                                                &get_setting_cnf_ptr->mids_setting,
                                                                &get_setting_cnf_ptr->mids_max_setting,
                                                                mids_id,
                                                                storage_name,
                                                                &get_setting_cnf_ptr->mids_trusted);
    free_ctrl_buffer(storage_name);
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    jam_move_javaruntimesp_to_smllpool(KAL_TRUE, JAVARUNTIME_POOL_GETSETTING);
#endif
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF,get_setting_cnf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_push_get_setting_req_handler
 * DESCRIPTION
 *  To get and set security setting.
 *  The parameters of the MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ message
 *  must follow the rule described in SAP
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_push_get_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct *send_ilm;
    mmi_java_mids_get_setting_req_struct *get_setting_req_ptr;
    mmi_java_mids_get_setting_cnf_struct *get_setting_cnf_ptr;

    kal_int32 mids_id;
    mids_list_info_struct *mids_info_ptr = NULL;
    kal_wchar* storage_name;
    kal_int32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GET_SETTING_REQ_HANDLER);

    get_setting_req_ptr = (mmi_java_mids_get_setting_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = jam_call_back_functions.jam_get_mids_id_from_push_name(get_setting_req_ptr->storage_name);

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    if(g_jam_mvm_whole_heap_size == 0)
    {
        applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_TRUE);
    }
    jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_PUSHGETSETTING);
#endif 
    if (get_setting_req_ptr->storage_name == NULL)
    {
        jam_parse_midslistfile(mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);
		
        mids_info_ptr = find_mids_info_by_id(mids_id,KAL_FALSE);
		
        /* mids not exist */
        if (mids_info_ptr == NULL)
        {
            get_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_get_setting_cnf_struct), TD_CTRL);
		
            get_setting_cnf_ptr->error_code = J2ME_MIDS_NOT_EXIST;
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF,get_setting_cnf_ptr);
            return;
        }
        len = app_ucs2_strlen((const kal_int8 *)mids_info_ptr->mids_root);
        storage_name = (kal_wchar*)get_ctrl_buffer((len+1)<<1);
		app_ucs2_strcpy((kal_int8 *) storage_name,(const kal_int8 *) mids_info_ptr->mids_root);
    }
    else
    {   
        len = strlen(get_setting_req_ptr->storage_name);
        storage_name = (kal_wchar*)get_ctrl_buffer((len+1)<<1);
        app_asc_str_to_ucs2_str((kal_int8 *) storage_name,(kal_int8 *) get_setting_req_ptr->storage_name);
    }
    get_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_get_setting_cnf_struct), TD_CTRL);

    get_setting_cnf_ptr->storage_name = get_setting_req_ptr->storage_name;

    get_setting_cnf_ptr->error_code = jam_call_back_functions.jam_get_setting(
                                                                &get_setting_cnf_ptr->mids_setting,
                                                                &get_setting_cnf_ptr->mids_max_setting,
                                                                mids_id,
                                                                storage_name,
                                                                &get_setting_cnf_ptr->mids_trusted);
    free_ctrl_buffer(storage_name);
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    jam_move_javaruntimesp_to_smllpool(KAL_TRUE, JAVARUNTIME_POOL_PUSHGETSETTING);
    if(g_jam_mvm_whole_heap_size == 0)
    {
        applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
    }
#endif
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF,get_setting_cnf_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_mids_set_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_set_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    ilm_struct *send_ilm;
    mmi_java_mids_set_setting_req_struct *set_setting_req_ptr;
    mmi_java_mids_set_setting_cnf_struct *set_setting_cnf_ptr;

    kal_int32 mids_id;
    mids_list_info_struct *mids_info_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GET_SETTING_REQ_HANDLER);
    /* set setting will block always do not let push install start up */

    set_setting_req_ptr = (mmi_java_mids_set_setting_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = set_setting_req_ptr->mids_id;

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
#if defined (__PLUTO_MMI_PACKAGE__) && defined(J2ME_SLIM_MEMORY_SUPPORT)
    jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_SETSETTING);
#endif 
    jam_parse_midslistfile(mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);
    mids_info_ptr = find_mids_info_by_id(mids_id,KAL_FALSE);

    /* mids not exist */
    if (mids_info_ptr == NULL)
    {
        set_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_set_setting_cnf_struct), TD_CTRL);

        set_setting_cnf_ptr->error_code = J2ME_MIDS_NOT_EXIST;
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF,set_setting_req_ptr);
        return;
    }

    set_setting_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_set_setting_cnf_struct), TD_CTRL);

    set_setting_cnf_ptr->error_code = J2ME_ACTION_FAILE;
    g_jam_is_jam_in_busy = KAL_TRUE;
    set_setting_cnf_ptr->error_code = jam_call_back_functions.jam_set_setting(
                                                                &set_setting_req_ptr->mids_setting,
                                                                mids_id,
                                                                mids_info_ptr,
                                                                KAL_TRUE);
    g_jam_is_jam_in_busy = KAL_FALSE;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF,set_setting_cnf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_update_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
/* used by Java_com_sun_midp_main_CommandProcessor_installationCNF to distinguish */
/* if the install is an update actually. */
void jam_mids_update_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mids_id;
    mmi_java_mids_update_req_struct *update_req_ptr;
    //java_wap_abort_req_struct *msg2;
    mids_list_info_struct *mids_info_ptr;
    //ilm_struct *send_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_UPDATE_REQ_HANDLER);
    install_update_status.is_update = KAL_TRUE;

    update_req_ptr = (mmi_java_mids_update_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = update_req_ptr->mids_id;
    download_error_code = 0;
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
			if(g_jam_mvm_whole_heap_size == 0)
			{
				applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_TRUE);
			}
			jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_UPDATE);
			
#endif 

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

    mids_info_ptr = find_mids_info_by_id(mids_id, KAL_FALSE);

    /* Error! JVM is running, or mids not exist */
    if (
#ifndef __SUPPORT_NATIVE_INSTALLER__
           (g_jam_is_jvm_in_busy) ||
#endif 
           (mids_info_ptr == NULL))
    {
        mmi_java_mids_update_cnf_struct *update_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_update_cnf_struct), TD_CTRL);

    #ifndef __SUPPORT_NATIVE_INSTALLER__
        if (g_jam_is_jvm_in_busy)
        {
            update_cnf_ptr->error_code = J2ME_INVALID_REQUEST;
        }
        else
    #endif /* __SUPPORT_NATIVE_INSTALLER__ */ 
        if (mids_info_ptr == NULL)
        {
            update_cnf_ptr->error_code = J2ME_MIDS_NOT_EXIST;
        }

        check_incoming_call_and_block();
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,update_cnf_ptr);
        return;
    }


#ifndef __SUPPORT_NATIVE_INSTALLER__
	if(javaheap_space == NULL)
	{
        javaheap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, DEFAULTHEAPSIZEFORJAM);
        javaheap_size = DEFAULTHEAPSIZEFORJAM;
	}
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 

    if (KAL_FALSE
#ifndef __SUPPORT_NATIVE_INSTALLER__
       || javaheap_space == NULL 
#endif
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
       || javaruntime_size == DEFAULT_MIN_POOL_SIZE
#endif /* J2ME_SLIM_MEMORY_SUPPORT*/
		)
    {
        mmi_java_mids_update_cnf_struct *update_cnf_ptr;

#ifndef __SUPPORT_NATIVE_INSTALLER__
	    if(javaheap_space)
	    {
	        applib_mem_ap_free(javaheap_space);
	        javaheap_space = NULL;
	        javaheap_size = 0;
	    }
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 

        update_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_update_cnf_struct), TD_CTRL);

        update_cnf_ptr->error_code = J2ME_INSUFFICIENT_MEMORY;

        check_incoming_call_and_block();
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,update_cnf_ptr);
        return;
    }

#ifndef __SUPPORT_NATIVE_INSTALLER__
    g_jam_is_jvm_in_busy = KAL_TRUE;
    jam_initVMExternal(0);
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 

    install_update_status.need_to_clean = KAL_FALSE;
    install_update_status.can_be_aborted = KAL_TRUE;
    install_update_status.has_returned_res = KAL_FALSE;

    g_jam_allowed_sending_abort_from_idle = KAL_TRUE;

    jam_call_back_functions.jam_update_midlet_suite(mids_id);

    install_update_status.is_update = KAL_FALSE;
    install_download_url = NULL;

    if (install_update_status.has_returned_res == KAL_FALSE)
    {
        mmi_java_mids_update_cnf_struct *update_cnf_ptr;
        update_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_update_cnf_struct), TD_CTRL);
        update_cnf_ptr->download_error_code = J2ME_NO_ERROR;
        update_cnf_ptr->error_string = (kal_wchar*) get_string(STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE);

        update_cnf_ptr->error_code = J2ME_INSTALL_FAIL;

        check_incoming_call_and_block();
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,update_cnf_ptr);
    }

    install_update_status.need_to_clean = KAL_FALSE;
    install_update_status.can_be_aborted = KAL_FALSE;

    /* this is to ensure the WPS channel has been freed properly */
    jnw_http_finalize(J2ME_HTTP_INSTALL_APP_ID);

#ifndef __SUPPORT_NATIVE_INSTALLER__
    if(javaheap_space)
    {
        applib_mem_ap_free(javaheap_space);
        javaheap_space = NULL;
        javaheap_size = 0;
    }    
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 

#ifndef __SUPPORT_NATIVE_INSTALLER__
    g_jam_is_jvm_in_busy = KAL_FALSE;
#endif 
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
        if(g_jam_mvm_whole_heap_size == 0)
        {
            applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
        }

        jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_UPDATE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_remove_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_remove_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id = -1;
    mmi_java_mids_remove_req_struct *remove_req_ptr = NULL;
    mmi_java_mids_remove_cnf_struct *remove_cnf_ptr = NULL;
    mids_list_info_struct *mids_info_ptr = NULL;
    kal_int32 error_code = J2ME_UNDEFINED_ERROR;
    kal_char* mids_storage_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_REMOVE_REQ_HANDLER);

    remove_req_ptr = (mmi_java_mids_remove_req_struct*) ilm_ptr->local_para_ptr;
    mids_id = remove_req_ptr->mids_id;
    g_jam_allowed_sending_abort_from_idle = KAL_TRUE;

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
        
#if defined (__COSMOS_MMI_PACKAGE__)  || defined(J2ME_SLIM_MEMORY_SUPPORT )
    /* midlet remove need runtime memory*/
    if(!jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_REMOVE))
    {
        error_code = J2ME_INSUFFICIENT_MEMORY;
        goto FUN_END;
    }
        
#endif 
    if(remove_req_ptr->mids_id != -1)
    {
        mids_id = remove_req_ptr->mids_id;
        jam_parse_midslistfile(mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);
    }else{
        /* We need to get absolute mids_index in list file*/
        mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name((kal_char*)remove_req_ptr->mids_storage_id);
        /*Use the absolute mids index to get mids inforation */  
        if(mids_id != -1)
        {
            jam_parse_midslistfile(mids_id - 1, 1, &saved_mids_listfile_ptr, NULL);
        }
    }
    if(remove_req_ptr->mids_storage_id)
    {
        free_ctrl_buffer(remove_req_ptr->mids_storage_id);
        remove_req_ptr->mids_storage_id = NULL;
    }
    if(mids_id != -1)
    {
        mids_info_ptr = find_mids_info_by_id(mids_id, KAL_FALSE);
    }else{
        mids_info_ptr = NULL;
    }
    //get mids_storage_id
    if(mids_info_ptr)
    {
#ifdef __JBLENDIA__
        if(jam_call_back_functions.jam_get_dm_id_from_mids_root&&mids_info_ptr->mids_root)
        {
            kal_char* dm_id = NULL;
            dm_id = jam_call_back_functions.jam_get_dm_id_from_mids_root((kal_wchar*)mids_info_ptr->mids_root);
            mids_storage_id = get_ctrl_buffer(strlen((const kal_char *)dm_id)+1);
            strcpy((kal_char *) mids_storage_id, (const kal_char *) dm_id);
        }
        else
        {
            mids_storage_id = NULL;
        }
#else
        mids_storage_id = get_ctrl_buffer(app_ucs2_strlen((const kal_int8 *)mids_info_ptr->mids_root)+1);
        app_ucs2_str_to_asc_str((kal_int8 *) mids_storage_id, (kal_int8 *) mids_info_ptr->mids_root);
        mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(mids_storage_id);
#endif
    }
    else
    {
        mids_storage_id = NULL;
    }
    if (mids_info_ptr == NULL)
    {
        error_code = J2ME_MIDS_NOT_EXIST;
        goto FUN_END;
    }
    if(mids_storage_id)
    {
        if(jam_mvm_has_running_midlet_in_mids((char *)mids_storage_id))
        {
            error_code = MIDLET_RUNNING;
            goto FUN_END;
        }
    }

    g_jam_in_remove_state = KAL_TRUE;
#ifdef __JBED__
    javaheap_size = DEFAULTHEAPSIZEFORJAM;
#ifdef J2ME_SHARE_MED_EXT_MEM
    jvm_alloc_med_mem = KAL_TRUE;
    media_get_ext_buffer(MOD_JAM, (void **)&(javaheap_space), DEFAULTHEAPSIZEFORJAM);
#else /* J2ME_SHARE_MED_EXT_MEM */ 
    javaheap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, DEFAULTHEAPSIZEFORJAM);
#endif /* J2ME_SHARE_MED_EXT_MEM */ 
    if (javaheap_space == NULL)
    {
        error_code = J2ME_INSUFFICIENT_MEMORY;
        goto FUN_END;
    }
#endif /* __JBED__ */ 
#ifndef __SUPPORT_NATIVE_INSTALLER__
    g_jam_is_jvm_in_busy = KAL_TRUE;
#else
    g_jam_is_jam_in_busy = KAL_TRUE;
#endif
    error_code = J2ME_UNDEFINED_ERROR;

    jam_initVMExternal(0);
    jam_call_back_functions.jam_remove_midlet_suite(mids_id, &error_code);
FUN_END:
#ifndef __SUPPORT_NATIVE_INSTALLER__
    g_jam_is_jvm_in_busy = KAL_FALSE;
#else
    g_jam_is_jam_in_busy = KAL_FALSE;
#endif /*__SUPPORT_NATIVE_INSTALLER__*/

#ifdef __JBED__
#ifdef J2ME_SHARE_MED_EXT_MEM
    media_free_ext_buffer(MOD_JAM, (void **)&(javaheap_space));
    jvm_alloc_med_mem = KAL_FALSE;
#else /* J2ME_SHARE_MED_EXT_MEM */ 
    applib_mem_ap_free(javaheap_space);
#endif /* J2ME_SHARE_MED_EXT_MEM */ 
#endif /* __JBED__ */ 

#if defined (__COSMOS_MMI_PACKAGE__)  || defined(J2ME_SLIM_MEMORY_SUPPORT )
    jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_REMOVE);     
#endif

    g_jam_in_remove_state = KAL_FALSE;
    remove_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_remove_req_struct), TD_CTRL);

    remove_cnf_ptr->error_code = error_code;
    remove_cnf_ptr->mids_storage_id = mids_storage_id;

    g_jam_allowed_sending_abort_from_idle = KAL_TRUE;
    /* ??? */
#ifdef __PLUTO_MMI_PACKAGE__
    check_incoming_call_and_block();
#endif
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF,remove_cnf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_install_mids_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
/* global veriable used to identify a install session */

/* WAPJADURL of installer.java */
kal_wchar *install_download_url;

/* WAP download error code */
kal_uint32 download_error_code = 0;
/*****************************************************************************
 * FUNCTION
 *  jam_install_mids_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_install_mids_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_mids_req_struct *install_req_ptr = NULL;
    kal_wchar *jad_file = NULL;
    kal_wchar *jar_file = NULL;
    kal_int32 len = 0;
    kal_int32 error_code = J2ME_NO_ERROR;
    extern install_report_info_struct g_jam_install_report;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_MMI_INSTALL_INSTALL_REQ_HANDLER);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        jam_install_confirm(DISK_NOT_FOUND);
        return;
    }
#endif

    /* Free last saved mids list memory first */
    jam_call_back_functions.jam_free_list();
    memset(&g_jam_install_report,0,sizeof(install_report_info_struct));
    install_req_ptr = (mmi_java_install_mids_req_struct*) ilm_ptr->local_para_ptr;
    install_download_url = install_req_ptr->download_url;
    download_error_code = 0;
    g_jam_stopFS =KAL_FALSE;
    g_jam_need_lauch = 0;
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
     if(g_jam_mvm_whole_heap_size == 0)
     {
         applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_TRUE);
     }
     jam_move_javaruntimesp_to_bigpool(JAVARUNTIME_POOL_INSTALL);
#endif /*J2ME_SLIM_MEMORY_SUPPORT*/

#ifndef __SUPPORT_NATIVE_INSTALLER__
    if (javaheap_space == NULL)
    {
        javaheap_space = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA, DEFAULTHEAPSIZEFORJAM);
        javaheap_size = DEFAULTHEAPSIZEFORJAM;
    }
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 


    if (KAL_FALSE
#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT )
       ||javaruntime_size == DEFAULT_MIN_POOL_SIZE
#endif /*#if defined (__COSMOS_MMI_PACKAGE__) || defined(J2ME_SLIM_MEMORY_SUPPORT ) */
#ifndef __SUPPORT_NATIVE_INSTALLER__
       || javaheap_space == NULL 
#endif
        )
    {
       // mmi_java_install_mids_cnf_struct *install_cnf_ptr;

#ifndef __SUPPORT_NATIVE_INSTALLER__
        if(javaheap_space)
        {
            applib_mem_ap_free(javaheap_space);
            javaheap_space = NULL;
            javaheap_size = 0;
        }
#endif /* __SUPPORT_NATIVE_INSTALLER__ */        

#if defined (__COSMOS_MMI_PACKAGE__) ||defined(J2ME_SLIM_MEMORY_SUPPORT )
        if(g_jam_mvm_whole_heap_size == 0)
        {
            applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
        }

        jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_INSTALL);
#endif

        jam_install_confirm(J2ME_INSUFFICIENT_MEMORY);
        return;
    }

#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /* delete previous midlet message */
    jvm_util_delete_midlet_msg_temp_file();
#endif

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
    g_jam_is_jam_in_busy = KAL_TRUE;

    jad_file = install_req_ptr->jad_file_path;
    jar_file = install_req_ptr->jar_file_path;
    if(jad_file && install_download_url[0]=='f')
    {
        jar_file = (U16*) get_jar_url((kal_wchar*) jad_file, &error_code);
        if(error_code != J2ME_NO_ERROR)
        {
#if defined (__COSMOS_MMI_PACKAGE__) ||defined(J2ME_SLIM_MEMORY_SUPPORT )
            if(g_jam_mvm_whole_heap_size == 0)
            {
                applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
            }

            jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_INSTALL);
#endif
            g_jam_is_jam_in_busy = KAL_FALSE;
            jam_install_confirm(error_code);
            return;
        }
        if(jar_file != NULL && FS_GetAttributes((WCHAR*) jar_file) < FS_NO_ERROR)
        {
            free_ctrl_buffer(jar_file);
            jar_file = NULL;
        }
        if (jar_file == NULL)               
        {
            len = mmi_ucs2strlen((const S8*)jad_file); 
            jar_file = get_ctrl_buffer((len + 1) << 1);                                   
            mmi_ucs2cpy((S8*)jar_file, (S8*)jad_file);                                   
            if(jar_file[len - 2]=='a')
            {   
                jar_file[len - 1] = 'r';      
            }
            else
            {                        
                jar_file[len - 1] = 'R';  
            }                             
        }                                 
        if (FS_GetAttributes((WCHAR*) jar_file) < FS_NO_ERROR) 
        {
#if defined (__COSMOS_MMI_PACKAGE__) ||defined(J2ME_SLIM_MEMORY_SUPPORT )
            if(g_jam_mvm_whole_heap_size == 0)
            {
                applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
            }

            jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_INSTALL);
#endif
            error_code = JAR_NOT_FOUND;
            if(jar_file) free_ctrl_buffer(jar_file); 
            g_jam_is_jam_in_busy = KAL_FALSE;
            jam_install_confirm(error_code);
            return;
        }                             
    }
    /* check http already in used */
    install_update_status.can_be_aborted = KAL_TRUE;
    install_update_status.has_returned_res = KAL_FALSE;
    install_update_status.need_to_clean = KAL_FALSE;
    install_update_status.is_normal_install = KAL_TRUE;
    install_update_status.is_aborted = KAL_FALSE;
    g_jam_allowed_sending_abort_from_idle = KAL_TRUE;

    jam_call_back_functions.jam_install_midlet_suite(jad_file, jar_file, install_download_url);

    if (install_download_url != NULL)
        free_ctrl_buffer(install_download_url);
    if (jad_file != NULL)
        free_ctrl_buffer(jad_file);
    if (jar_file != NULL)
        free_ctrl_buffer(jar_file);
    install_download_url = NULL;
    free_jam_ca_list();

    if (install_update_status.has_returned_res == KAL_FALSE)
    {
        jam_install_confirm(J2ME_INSTALL_FAIL);
    }

    install_update_status.need_to_clean = KAL_FALSE;
    install_update_status.can_be_aborted = KAL_FALSE;
    install_update_status.is_normal_install = KAL_FALSE;
    jam_call_back_functions.jam_free_list();

#if defined (__COSMOS_MMI_PACKAGE__) ||defined(J2ME_SLIM_MEMORY_SUPPORT )
    if(g_jam_mvm_whole_heap_size == 0)
    {
        applib_mem_ap_set_hide(APPLIB_MEM_AP_ID_JAVA , KAL_FALSE);
    }

    jam_move_javaruntimesp_to_smllpool(KAL_TRUE,JAVARUNTIME_POOL_INSTALL);
#endif

#ifndef __SUPPORT_NATIVE_INSTALLER__
    if(javaheap_space)
    {
        applib_mem_ap_free(javaheap_space);
        javaheap_space = NULL;
        javaheap_size = 0;
    }    
#endif /* __SUPPORT_NATIVE_INSTALLER__ */ 
#ifndef __SUPPORT_NATIVE_INSTALLER__
    g_jam_is_jvm_in_busy = KAL_FALSE;
#else 
    g_jam_is_jam_in_busy = KAL_FALSE;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  jam_abort_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_abort_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_abort_cnf_struct *abort_cnf_ptr;
    kal_int32 vm_id = 0;
    mmi_java_abort_req_struct *abort_req_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMI_ABORT_REQ_HANDLER);
    abort_req_ptr = (mmi_java_abort_req_struct *)ilm_ptr;
    /* only jam task can send message */
    if (kal_get_active_module_id() == MOD_JAM)
    {

        /* To check install/update only, start, remove... don't care */
        if (install_update_status.can_be_aborted)
        {
            abort_cnf_ptr = construct_local_para(sizeof(mmi_java_abort_cnf_struct), TD_CTRL);
            abort_cnf_ptr->error_code = J2ME_NO_ERROR;

            check_incoming_call_and_block();
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_ABORT_CNF,abort_cnf_ptr);
            install_update_status.can_be_aborted = KAL_FALSE;
        }
        /* This is temp solution for CR MAUI_01724480 */
        /* Ask VM remove in future */
        if(!(install_update_status.is_normal_install ||
                                     install_update_status.is_update || 
                                     install_update_status.is_local_install ||
                                      (g_jam_install_abort == KAL_TRUE &&
                                      (jam_mvm_is_minimize_mode(vm_id)||jam_mvm_is_pause_mode(vm_id)) )))
        {        
            //ilm_struct *ilm_ptr;
            mmi_java_abort_req_struct *msg;
            
            msg = (mmi_java_abort_req_struct*) construct_local_para(sizeof(mmi_java_abort_req_struct), TD_CTRL);
            msg->vm_id = abort_req_ptr->vm_id;
            java_send_msg_from_active_mod(MOD_J2ME,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_ABORT_REQ,msg);
        } 
        g_jam_allowed_sending_abort_from_idle = KAL_TRUE;
        g_jam_install_abort = KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_asm_abort_handler
 * DESCRIPTION
 *  Handle msg MSG_ID_MMI_JAVA_ASM_ABORT_REQ to abort msg to VM
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_asm_abort_handler(ilm_struct *ilm_p )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//ilm_struct *ilm_ptr;
	mmi_java_abort_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
	msg = (mmi_java_abort_req_struct*) construct_local_para(sizeof(mmi_java_abort_req_struct), TD_CTRL);
	java_send_msg_from_active_mod(MOD_J2ME,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_ABORT_REQ,msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_delete_menu_abort_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_delete_menu_abort_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_DELETE_MENU_ABORT_CNF_HANDLER);

    if (g_jam_need_storage_size > 0)
    {
        g_jam_need_storage_size = 0;
    }

    //check_incoming_call_and_block();MAUI_03030824
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_CNF,NULL);

    if (g_jam_need_storage_size > 0 && !g_jam_is_local_installed_mids)
    {
        /* delay report to server for CT898 */
    #ifdef __MMI_JAVA_INSTALL_DELETE_MENU__
    #if defined( __NEMO_VM__)  || defined( __IJET_VM__)
        postInstallMsgBackToProvider("901 Insufficient Memory");
    #endif /* __NEMO_VM__ or __IJET_VM__ */
    #endif /* __MMI_JAVA_INSTALL_DELETE_MENU__ */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  jam_restore_factory_mode_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_restore_factory_mode_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
    javaFileGenerator(KAL_TRUE);
#endif /* !defined(MMI_ON_WIN32) && defined(__J2ME__) */ 

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_CNF,NULL);

}
/*****************************************************************************
 * FUNCTION
 *  jam_mids_package_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_package_req_handler(ilm_struct *ilm_ptr)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_package_req_struct *req_ptr = NULL;
    mmi_java_mids_package_cnf_struct *cnf_ptr = NULL;
    kal_wchar* jad_path = NULL;
    kal_wchar* jar_path = NULL;
    kal_wchar* midlet_message_path = NULL;
    kal_int32 len = 0;
   // kal_int32 drm_file_handle = -1;
    //kal_bool is_future_right = KAL_FALSE;
    kal_int32 error_code = J2ME_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_741_index ++;
    kal_trace(TRACE_FUNC, JAM_MIDS_PACKAGE_REQ_HANDLER, g_jam_741_index);
    g_jam_is_jam_in_busy = KAL_TRUE;
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /* delete previous midlet message */
    jvm_util_delete_midlet_msg_temp_file();
#endif
    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
    jvm_file_initialize();

    req_ptr = (mmi_java_mids_package_req_struct*) ilm_ptr->local_para_ptr;

    if (req_ptr->mids_id == 0xFFFFFFFF)  //req_ptr->mids_id ==-1
    {
        /* file manager mode */
        len = get_ucs2_len(req_ptr->file_path);
        jad_path = jam_listmem_malloc((len+1)<<1);
        memcpy(jad_path, req_ptr->file_path, (len+1)<<1);
        jam_set_get_jar_url_check_exist(KAL_TRUE);
        jar_path = (U16*) get_jar_url((kal_wchar*) jad_path, &error_code);
        if (error_code == J2ME_NO_ERROR && jar_path == NULL)/* the return memory is ctrl buffer */
        {
            jar_path = get_ctrl_buffer((len + 1) << 1);
            mmi_ucs2cpy((CHAR*)jar_path, (const CHAR*)jad_path);
            jar_path[len - 1] = 'r';
        }

        /* valid right before verify jar */
        if(error_code == J2ME_NO_ERROR)
        {
            if (!DRM_validate_permission(NULL, jar_path, DRM_PERMISSION_EXECUTE))
            {
                error_code = DRM_PROHIBIT;
            }
            else
            {
                    /* file manager mode need to verify JAR */
                error_code = jam_call_back_functions.jam_verify_jar(jad_path, jar_path);
                if (error_code == J2ME_NO_ERROR)
                {
                    midlet_message_path = jvm_util_package_midlet_message(jad_path, jar_path, req_ptr->output_dir, KAL_FALSE, &error_code);
                }
                else
                {
                    if (error_code != USER_CANCEL)
                    {
                        error_code = UNSUPPORTED_CERT;
                    }
                }
            }
        }
        if(jad_path!=NULL)
        {
            jam_listmem_free(jad_path);
            jad_path = NULL;
        }
        if(jar_path)
        {
            free_ctrl_buffer(jar_path);
            jar_path = NULL;
        }
        
    }
    else
    {
        /* make sure correct mids_info */
        jam_parse_midslistfile(req_ptr->mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);
        /* Java screen mode */
        jad_path = jam_call_back_functions.jam_get_jad_storage_name_from_mids_id(jam_listmem_malloc, req_ptr->mids_id);
        jar_path = jam_call_back_functions.jam_get_jar_storage_name_from_mids_id(jam_listmem_malloc, req_ptr->mids_id);

        
        if (!DRM_validate_permission(NULL, jar_path, DRM_PERMISSION_EXECUTE))
        {
            error_code = DRM_PROHIBIT;
        }
        else
        {
            if (jad_path == NULL)
            {
                midlet_message_path = jvm_util_copy_and_rename_jar(saved_mids_listfile_ptr->mids_info_list->mids_name, jar_path,req_ptr->output_dir, &error_code);
            }
            else
            {
                midlet_message_path = jvm_util_package_midlet_message(jad_path, jar_path, req_ptr->output_dir, KAL_FALSE,&error_code);
            }
        }
       
        if (jad_path)
        {
            jam_listmem_free(jad_path);
            jad_path = NULL;
        }
        if (jar_path)
        {
            jam_listmem_free(jar_path);
            jar_path = NULL;
        }
    }

    cnf_ptr = construct_local_para(sizeof(mmi_java_mids_package_cnf_struct), TD_CTRL);

    if (midlet_message_path)
    {
        cnf_ptr->error_code = error_code;

        len = get_ucs2_len(midlet_message_path);

        cnf_ptr->file_path = get_ctrl_buffer((len+1)<<1);
        memcpy(cnf_ptr->file_path, midlet_message_path, (len+1)<<1);

        jam_listmem_free(midlet_message_path);
    }
    else
    {
        if (error_code)
        {
            cnf_ptr->error_code = error_code;
        }
        else
        {
            cnf_ptr->error_code = PACKAGE_FAIL;
        }
        cnf_ptr->file_path = NULL;
    }

    jvm_file_finalize();
    g_jam_is_jam_in_busy = KAL_FALSE;
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_PACKAGE_CNF,cnf_ptr);
#endif
}


#ifdef SUPPORT_JSR_120
/*****************************************************************************
 * FUNCTION
 *  jam_mmiapi_sms_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mmiapi_sms_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *entry_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMIAPI_SMS_IND_HANDLER);

    entry_ptr = j2me_process_recvd_sms_ind(ilm_ptr);

    if (entry_ptr)
    {
        #ifdef __SUPPORT_JAVA_PUSH__
        jam_timealarm_push_ind_handler(
            PUSHTYPE_SMS_PUSH,
            (void*)entry_ptr,
            entry_ptr->midlet,
            entry_ptr->midletid,
            entry_ptr->storagename,
            KAL_FALSE);
        #endif
    }
    else
    {
        /*
         * Current implementation only consider push case,
         * *       If Eureka persistent SMS queue Req10 needs to consider SMS data indication.
         * *    We need to send message to inform JVM (current task is JDaemon) to call jpush_eureka_process_pending_sms()
         * *    However, we still need to consider WMA process message during req polling case, which will cause lost response.
         */
    }
}

#endif

#ifdef SUPPORT_JSR_205


/*****************************************************************************
 * FUNCTION
 *  jam_appmms_new_mms_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_appmms_new_mms_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *entry_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ptr = j2me_process_recvd_mms_ind(ilm_ptr);

    if (entry_ptr)
    {
        #ifdef __SUPPORT_JAVA_PUSH__
        jam_timealarm_push_ind_handler(
            PUSHTYPE_MMS_PUSH,
            (void*)entry_ptr,
            entry_ptr->midlet,
            entry_ptr->midletid,
            entry_ptr->storagename,
            KAL_FALSE);
        #endif
    }
}
#endif /* SUPPORT_JSR_205 */ 

#ifdef __SUPPORT_JAVA_PUSH__

/*****************************************************************************
 * FUNCTION
 *  jam_timealarm_push_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alarmpush_type      [IN]        
 *  callback_entry      [?]         [?]
 *  mid_name            [?]         [?]
 *  mid_storagename     [?]         [?]
 *  type(?)             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_timealarm_push_ind_handler(
        kal_uint32 alarmpush_type,
        void *callback_entry,
        kal_char *mid_name,
        kal_int32 mid_id,
        kal_char *mid_storagename,
        kal_bool show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id;
    mmi_java_timealarm_push_ind_struct *timealarm_push_ind_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMI_TIMEALARM_PUSH_IND_HANDLER);

#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        if (alarmpush_type == PUSHTYPE_ALARM_PUSH)
        {
            jpush_alarm_del((alarmentry_struct*) callback_entry);
        }
    #ifdef SUPPORT_JSR_257
        else if (alarmpush_type == PUSHTYPE_NFC_PUSH)
        {
            jcc_nfc_push_execution_callback(KAL_FALSE, (pushentry_struct *)callback_entry);
        }
    #endif
        return;
    }
#endif

    /* Update working internal system directory path */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

    if (mid_storagename == NULL)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        if (g_jam_push_launch_need_close_dummy_grp)
        {
            timealarm_push_ind_ptr = (mmi_java_timealarm_push_ind_struct*)
                construct_local_para(sizeof(mmi_java_timealarm_push_ind_struct), TD_CTRL);
            timealarm_push_ind_ptr->pushalarm_type = -1;
            timealarm_push_ind_ptr->close_dummy_group = KAL_TRUE;
            timealarm_push_ind_ptr->show_busy_popup = show_popup;
            g_jam_push_launch_need_close_dummy_grp = KAL_FALSE;
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND,timealarm_push_ind_ptr);
        }
#endif
        return;
    }

    mids_id = jam_call_back_functions.jam_get_mids_id_from_push_name(mid_storagename);

    if (mids_id == -1)
    {
    #ifdef MIDP_FILE_DEBUG
        Kputs("J2ME Error: pussh get mids name failed");
    #endif
#ifdef __COSMOS_MMI_PACKAGE__
        if (g_jam_push_launch_need_close_dummy_grp)
        {
            timealarm_push_ind_ptr = (mmi_java_timealarm_push_ind_struct*)
                construct_local_para(sizeof(mmi_java_timealarm_push_ind_struct), TD_CTRL);
            timealarm_push_ind_ptr->pushalarm_type = -1;
            timealarm_push_ind_ptr->close_dummy_group = KAL_TRUE;
            timealarm_push_ind_ptr->show_busy_popup = show_popup;
            g_jam_push_launch_need_close_dummy_grp = KAL_FALSE;
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND,timealarm_push_ind_ptr);
        }
#endif
        return;
    }

    /* Ensure push registration entry will be executed between power cycles of the handle set */
    if (alarmpush_type == PUSHTYPE_ALARM_PUSH)
    {
        jpush_add_persistent_push(0, alarmpush_type, mid_name, mid_id, mid_storagename, NULL, NULL, NULL, NULL);
    }
    else if (alarmpush_type == PUSHTYPE_SMS_PUSH || alarmpush_type == PUSHTYPE_MMS_PUSH || alarmpush_type == PUSHTYPE_NFC_PUSH)
    {
        pushentry_struct *entry_ptr = (pushentry_struct*) callback_entry;

        jpush_add_persistent_push(
            entry_ptr->portNo,
            alarmpush_type,
            mid_name,
            mid_id,
            mid_storagename,
            entry_ptr->filter,
            entry_ptr->connection,
            entry_ptr->appid,
            entry_ptr->nfc_url);
    }
    else
    {
    #ifdef MIDP_FILE_DEBUG
        Kputs("J2ME Error: alarm type error");
    #endif
        return;
    }
    timealarm_push_ind_ptr = (mmi_java_timealarm_push_ind_struct*)
        construct_local_para(sizeof(mmi_java_timealarm_push_ind_struct), TD_CTRL);
    timealarm_push_ind_ptr->pushalarm_type = alarmpush_type;
    timealarm_push_ind_ptr->callback_entry = callback_entry;
    timealarm_push_ind_ptr->mid_class_name = mid_name;
    timealarm_push_ind_ptr->mid_id = mid_id;
    timealarm_push_ind_ptr->mids_storage_name = mid_storagename;
    timealarm_push_ind_ptr->show_busy_popup = show_popup;
#ifdef __COSMOS_MMI_PACKAGE__
    if (g_jam_push_launch_need_close_dummy_grp)
    {
        timealarm_push_ind_ptr->close_dummy_group = KAL_TRUE;
        g_jam_push_launch_need_close_dummy_grp = KAL_FALSE;
    }
#endif
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND,timealarm_push_ind_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_timealarm_push_res_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_timealarm_push_res_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_timealarm_push_res_struct *timealarm_push_res_ptr;
    pushentry_struct *entry_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMI_TIMEALARM_PUSH_RES_HANDLER);
    timealarm_push_res_ptr = (mmi_java_timealarm_push_res_struct*) ilm_ptr->local_para_ptr;

#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_ALARM_PUSH)
        {
            jpush_alarm_del((alarmentry_struct*) timealarm_push_res_ptr->callback_entry);
        }
    #ifdef SUPPORT_JSR_257
        else if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_NFC_PUSH)
        {
            jcc_nfc_push_execution_callback(KAL_FALSE, (pushentry_struct *)timealarm_push_res_ptr->callback_entry);
        }
    #endif
        return;
    }
#endif
    /* Update current working directory */

    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

    entry_ptr = (pushentry_struct*) timealarm_push_res_ptr->callback_entry;
    /* Ensure push registration entry will be executed between power cycles of the handle set */
    if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_ALARM_PUSH)
    {
        jpush_search_and_delete_persistent_push(
            0,
            timealarm_push_res_ptr->pushalarm_type,
            timealarm_push_res_ptr->mid_class_name,
            timealarm_push_res_ptr->mid_id,
            timealarm_push_res_ptr->mids_storage_name,
            NULL,
            NULL,
            NULL,
            NULL,
            KAL_TRUE);
    }
    else if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_SMS_PUSH ||
             timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_MMS_PUSH ||
             timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_NFC_PUSH)
    {
        /* workaround solution for delete midlet and then install for sms */
        if(timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_SMS_PUSH && entry_ptr->appid!=NULL)
            return;
        
        if((timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_SMS_PUSH || timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_MMS_PUSH) &&
            entry_ptr->nfc_url != NULL)
            return;
        
        jpush_search_and_delete_persistent_push(
            entry_ptr->portNo,
            timealarm_push_res_ptr->pushalarm_type,
            timealarm_push_res_ptr->mid_class_name,
            timealarm_push_res_ptr->mid_id,
            timealarm_push_res_ptr->mids_storage_name,
            entry_ptr->filter,
            entry_ptr->connection,
            entry_ptr->appid,
            entry_ptr->nfc_url,
            KAL_TRUE);
    }
    else
    {
        timealarm_push_res_ptr->execute = KAL_FALSE;
    }

    if (timealarm_push_res_ptr->execute == KAL_TRUE)
    {
        if (jam_mvm_get_running_count() < MAX_VM_INSTANCE_NUM && !g_jam_is_jam_in_busy)
        {
            kal_wchar *tmp_midname = NULL;
            kal_char *tmp_storagename = NULL;
            kal_uint32 tmp_midsid;

        #ifdef __JBLENDIA__
            kal_int32 error_code;
        #endif 

		    tmp_midname = (kal_wchar*)get_ctrl_buffer(256);

        #ifndef __JBLENDIA__
            trans_utf8_to_ucs2(tmp_midname, timealarm_push_res_ptr->mid_class_name);
        #endif 
            tmp_midsid = jam_call_back_functions.jam_get_mids_id_from_push_name(timealarm_push_res_ptr->mids_storage_name);
        #ifdef __JBLENDIA__
            trans_utf8_to_ucs2(
                tmp_midname,
                jblendia_mid_getNameFromClass(tmp_midsid, timealarm_push_res_ptr->mid_class_name, &error_code));
        #endif /* __JBLENDIA__ */ 
            tmp_storagename = get_ctrl_buffer(30);
            strcpy(tmp_storagename, timealarm_push_res_ptr->mids_storage_name);
            
        #ifdef __SUPPORT_INFUSIO__
            if (game_type != GAMETYPE_INFUSIO_EUREKA || g_jam_support_ege_runtime)
        #endif 
            {
                if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_SMS_PUSH ||
                    timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_MMS_PUSH ||
                    timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_NFC_PUSH)
                {
                    entry_ptr->available = KAL_TRUE;

                }
				
				g_jam_push_launch_fail = KAL_FALSE;
				
                jam_send_mid_start_req(
                    timealarm_push_res_ptr->wap_prof_id,
                    tmp_midsid,
                    timealarm_push_res_ptr->mid_id,
                    tmp_midname,
                    tmp_storagename);

				if (g_jam_push_launch_fail)
				{
				    jam_timealarm_push_ind_handler(
                        timealarm_push_res_ptr->pushalarm_type,
                        timealarm_push_res_ptr->callback_entry,
                        timealarm_push_res_ptr->mid_class_name,
                        timealarm_push_res_ptr->mid_id,
                        timealarm_push_res_ptr->mids_storage_name,
                        KAL_FALSE);
				}
				else
				{
				    if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_ALARM_PUSH)
                    {
                        jpush_alarm_del((alarmentry_struct*) timealarm_push_res_ptr->callback_entry);
                    }
                #ifdef SUPPORT_JSR_257
                    else if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_NFC_PUSH)
                    {
                        jcc_nfc_push_execution_callback(KAL_TRUE, (pushentry_struct *)timealarm_push_res_ptr->callback_entry);
                    }
                #endif
				}
            }
        }
        else
        {
        #ifdef __COSMOS_MMI_PACKAGE__
            g_jam_push_launch_need_close_dummy_grp = KAL_TRUE;
        #endif
        	jam_timealarm_push_ind_handler(
                timealarm_push_res_ptr->pushalarm_type,
                timealarm_push_res_ptr->callback_entry,
                timealarm_push_res_ptr->mid_class_name,
                timealarm_push_res_ptr->mid_id,
                timealarm_push_res_ptr->mids_storage_name,
                KAL_TRUE);
        }
    }
    else
    {
        /* Free resource */
        if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_ALARM_PUSH)
        {
            jpush_alarm_del((alarmentry_struct*) timealarm_push_res_ptr->callback_entry);
        }
    #ifdef SUPPORT_JSR_257
        else if (timealarm_push_res_ptr->pushalarm_type == PUSHTYPE_NFC_PUSH)
        {
            jcc_nfc_push_execution_callback(KAL_FALSE, (pushentry_struct *)timealarm_push_res_ptr->callback_entry);
        }
    #endif
    }
}

#endif

#ifdef SUPPORT_JSR_120
#ifdef __SUPPORT_INFUSIO__

kal_int32 jpush_eureka_process_pending_sms(mmiapi_sms_ind_struct *sms_ind);


/*****************************************************************************
 * FUNCTION
 *  jam_enqueue_sms_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jam_enqueue_sms_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_sms_ind_struct *sms_ind = (mmiapi_sms_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (JWA_SMS_STATE_IDLE != jwa_sms_get_state())
    {
        mmiapi_sms_ind_struct *local = (mmiapi_sms_ind_struct*)
            construct_local_para(sizeof(mmiapi_sms_ind_struct), TD_CTRL);

        /*
         * If here, that means we support push during VM busy. Meanwhile, JVM is issuing SMS request, and 
         * * wait response. We should process eureka push indication later.
         */

        //local->dcs = sms_ind->dcs;
        local->port_number = sms_ind->port_number;
        //local->serial = sms_ind->serial;

        java_send_msg_from_active_mod(MOD_JAM,MMI_J2ME_SAP,MSG_ID_JAVA_JAVA_ENQUEUE_SMS_REQ,local);

        kal_sleep_task(200);

    }
    else
    {
    #ifdef __SUPPORT_INFUSIO__
        jpush_eureka_process_pending_sms((mmiapi_sms_ind_struct*) sms_ind);
    #endif 
    }
}

#endif 
#endif

/*****************************************************************************
 * FUNCTION
 *  jam_send_mid_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  game_type       [IN]        
 *  wap_prof_id     [IN]        
 *  mids_id         [IN]        
 *  mid_name        [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_send_mid_start_req(
        kal_uint8 wap_prof_id,
        kal_uint32 mids_id,
        kal_int32 mid_id,
        kal_wchar *mid_name,
        kal_char *storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct send_ilm;
    java_java_mid_start_req_struct *start_req_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MID_START_REQ_HANDLER);
    start_req_ptr =
        (java_java_mid_start_req_struct*) construct_local_para(sizeof(java_java_mid_start_req_struct), TD_CTRL);
    start_req_ptr->mids_id = mids_id;
    start_req_ptr->mid_id = mid_id;
    start_req_ptr->mid_name = mid_name;
    start_req_ptr->storage_name= storage_name;
    start_req_ptr->wap_prof_id = wap_prof_id;
    start_req_ptr->is_launch_as_bg_running = KAL_FALSE;
    send_ilm.src_mod_id = MOD_JAM;
    send_ilm.dest_mod_id = MOD_JAM;
    send_ilm.local_para_ptr = (local_para_struct*) start_req_ptr;
    send_ilm.peer_buff_ptr = NULL;
    send_ilm.msg_id = MSG_ID_JAVA_JAVA_MID_START_REQ;
    send_ilm.sap_id = MMI_J2ME_SAP;

    jam_internal_mid_start_req_handler(&send_ilm);

    free_local_para((local_para_struct*) start_req_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_set_mode_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_set_mode_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 returnCode = J2ME_NO_ERROR;
    kal_int32 vm_id = -1;
    mmi_java_set_mode_req_struct *ptr = (mmi_java_set_mode_req_struct *)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMI_JAVA_SET_MODE_REQ_HANDLER);
    if (ptr->java_mode != JAVA_NORMAL_MODE)
    {
        vm_id = jam_mvm_get_vm_instance((kal_char *)NULL, -1, (java_mode_enum) ptr->java_mode,&returnCode);  
        if( returnCode != J2ME_NO_ERROR)
        {
            jam_mvm_terminate_vm(vm_id);
        }
    }
    mmi_java_set_mode_cnf_handler(returnCode,vm_id);
    if(returnCode == J2ME_NO_ERROR)
    {
        g_jam_is_jvm_in_busy = KAL_TRUE;
        jam_call_back_functions.jam_tck_start_up((java_mode_enum) ptr->java_mode, ptr->execute,vm_id);
    }
}

void jam_send_tck_result_ind(kal_int32 error_code)
            {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_tck_result_struct*tck_ind_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tck_ind_ptr = (mmi_java_tck_result_struct*)construct_local_para(sizeof(mmi_java_tck_result_struct), TD_CTRL);
    tck_ind_ptr->tck_result= error_code;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_TCK_RESULT_IND,tck_ind_ptr);
}
/*****************************************************************************
 * FUNCTION
 *  jam_set_mode_req_post_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
//void jam_set_mode_req_post_handler(void)
//{


//}

#ifdef OGDR_SECURITY_SETTING


/*****************************************************************************
 * FUNCTION
 *  jam_get_domain_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_get_domain_list_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_domain_list_cnf_struct *get_domain_list_cnf;
    //mmi_java_get_domain_list_req_struct *get_domain_list_req;
    kal_int32 domain_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    //get_domain_list_req = (mmi_java_get_domain_list_req_struct*) ilm_ptr->local_para_ptr;
    get_domain_list_cnf = construct_local_para(sizeof(mmi_java_get_domain_list_cnf_struct), TD_CTRL);
    get_domain_list_cnf->error_code = jam_call_back_functions.jam_get_domain_list(
                                                                &get_domain_list_cnf->total_domain,
                                                                get_domain_list_cnf->domains);

    while (get_domain_list_cnf->domains[domain_index][0] != 0)
    {
        kal_wchar *matched_str = NULL;

        if (jam_domain_compare(get_domain_list_cnf->domains[domain_index], JAM_OPERATOR_DOMAIN))
        {
            matched_str = (kal_wchar*) get_string(STR_JAVA_PERM_DMN_OPERATOR);
        }
        else if (jam_domain_compare(get_domain_list_cnf->domains[domain_index], JAM_MANUFACTURER_DOMAIN))
        {
            matched_str = (kal_wchar*) get_string(STR_JAVA_PERM_DMN_MANUFACTURER);
        }
        else if (jam_domain_compare(get_domain_list_cnf->domains[domain_index], JAM_THIRDPARTY_DOMAIN))
        {
            matched_str = (kal_wchar*) get_string(STR_JAVA_PERM_DMN_3RDPARTY);
        }
        else if (jam_domain_compare(get_domain_list_cnf->domains[domain_index], JAM_UNTRUSTED_DOMAIN))
        {
            matched_str = (kal_wchar*) get_string(STR_JAVA_PERM_DMN_UNTRUSTED);
        }
        if (matched_str != NULL)
        {
            memcpy(get_domain_list_cnf->domains[domain_index], matched_str, (get_ucs2_len(matched_str) << 1) + 2);
        }
        domain_index++;
    }
    g_jam_is_jam_in_busy = KAL_FALSE;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_CNF,get_domain_list_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_default_domain_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_get_default_domain_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_default_domain_req_struct *jam_get_setting_req;
    mmi_java_get_default_domain_cnf_struct *jam_get_setting_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    jam_get_setting_req = (mmi_java_get_default_domain_req_struct*) ilm_ptr->local_para_ptr;
    jam_get_setting_cnf = construct_local_para(sizeof(mmi_java_get_default_domain_cnf_struct), TD_CTRL);
    jam_get_setting_cnf->error_code = jam_call_back_functions.jam_get_default_setting(
                                                                jam_get_setting_req->domain_id,
                                                                &jam_get_setting_cnf->max_setting,
                                                                &jam_get_setting_cnf->default_setting);
    g_jam_is_jam_in_busy = KAL_FALSE;
    jam_get_setting_cnf->domain_id = jam_get_setting_req->domain_id;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF,jam_get_setting_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  jam_set_default_domain_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_set_default_domain_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_default_domain_req_struct *jam_set_setting_req;
    mmi_java_set_default_domain_cnf_struct *jam_set_setting_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    jam_set_setting_req = (mmi_java_set_default_domain_req_struct*) ilm_ptr->local_para_ptr;

    jam_set_setting_cnf = construct_local_para(sizeof(mmi_java_set_default_domain_cnf_struct), TD_CTRL);
    jam_set_setting_cnf->error_code = jam_call_back_functions.jam_set_default_setting(
                                                                jam_set_setting_req->domain_id,
                                                                &jam_set_setting_req->default_setting);
    g_jam_is_jam_in_busy = KAL_FALSE;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_CNF,jam_set_setting_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  jam_reset_default_domain_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_reset_default_domain_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_reset_default_domain_cnf_struct *jam_reset_setting_cnf;
    //mmi_java_reset_default_domain_req_struct *jam_reset_setting_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //jam_reset_setting_req = (mmi_java_reset_default_domain_req_struct*) ilm_ptr->local_para_ptr;

    jam_reset_setting_cnf = construct_local_para(sizeof(mmi_java_reset_default_domain_cnf_struct), TD_CTRL);
    jam_reset_setting_cnf->error_code = jam_call_back_functions.jam_reset_default_permission_setting();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_CNF,jam_reset_setting_cnf);
}

#endif /* OGDR_SECURITY_SETTING */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_java_set_mode_cnf_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code      [IN]        
 *  tck_result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_set_mode_cnf_handler(kal_uint32 error_code, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_mode_cnf_struct *java_setmode_cnf_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_J2ME_MMI_JAVA_SET_MODE_CNF_HANDLER);

    java_setmode_cnf_ptr = construct_local_para(sizeof(mmi_java_set_mode_cnf_struct), TD_CTRL);

    java_setmode_cnf_ptr->error_code = error_code;
    java_setmode_cnf_ptr->vm_id= vm_id;

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_SET_MODE_CNF,java_setmode_cnf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_send_mma_event_callback
 * MMAPI
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        [?]
 *  event           [IN]        
 *  aud_id          [IN]        
 *  seq_id          [IN]        
 *  device(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_send_mma_event_callback(kal_int32 handle, kal_int32 event, kal_int32 aud_id, kal_int32 seq_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_event_callback_struct *mma_event_callback_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_event_callback_ptr = construct_local_para(sizeof(mma_event_callback_struct), TD_CTRL);

    mma_event_callback_ptr->aud_id = aud_id;
    mma_event_callback_ptr->seq_id = seq_id;
    mma_event_callback_ptr->handle = handle;
    mma_event_callback_ptr->event = event;

    java_send_msg_from_active_mod(MOD_JASYN,MMI_J2ME_SAP,MSG_ID_JAVA_MMA_EVENT_CALLBACK,mma_event_callback_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_hs_np_delete_notifier
 * DESCRIPTION
 *  This routin notify MMI for deleted mids
 * PARAMETERS
 *  mids_storage        [?]     [kal_char* ]   the storage of deleted mids
 * RETURNS
 *  void
 *****************************************************************************/
void jam_hs_np_delete_notifier(kal_char *mids_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //kal_uint16 profs[2] = {0, 0};
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
   // mids_list_info_struct *mids_info;
   // kal_int32 mids_id;
    kal_wchar w_mids_storage[30] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JAM_HS_NP_DELETE_NOTIFY);
   app_asc_str_to_ucs2_str((kal_int8 *) w_mids_storage,(kal_int8 *) mids_storage);

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_np_reset
 * DESCRIPTION
 *  This routin reset all np setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_np_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  jam_mids_hs_reset
 * DESCRIPTION
 *  This routin reset all hs setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_hs_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, JAM_HS_RESET);
    jvm_file_delete(HS_MIDS_TBL);
}

#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */ 

/*****************************************************************************
 * FUNCTION
 *  jam_send_waiting_right_start_handler
 * DESCRIPTION
 *  send the start msg of notify to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_send_waiting_right_start_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_waiting_right_start_req_struct *waiting_right_start_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_sleep_task(5000); */
    waiting_right_start_msg = construct_local_para(sizeof(mmi_java_waiting_right_start_req_struct), TD_CTRL);
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_WAITING_RIGHT_START_REQ,waiting_right_start_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_send_waiting_right_end_handler
 * DESCRIPTION
 *  send the finish msg of notify to MMI
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  kal_bool  the sending success or not(?)
 *****************************************************************************/
void jam_send_waiting_right_end_handler(kal_bool success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_waiting_right_end_req_struct *waiting_right_end_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    waiting_right_end_msg = construct_local_para(sizeof(mmi_java_waiting_right_end_req_struct), TD_CTRL);
    waiting_right_end_msg->success = success;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_WAITING_RIGHT_END_REQ,waiting_right_end_msg);
}

#ifdef OGDR_SECURITY_SETTING

extern mids_setting_struct saved_mids_max_setting;
/*****************************************************************************
 * FUNCTION
 *  jam_mids_reset_domain_setting_hdlr
 * DESCRIPTION
 *  reset the mids setting according to the setting recorded when installing
 * PARAMETERS
 *  ilm_ptr     [?]     [ilm_struct*]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mids_reset_domain_setting_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_reset_domain_setting_req_struct *req_msg;
    mmi_java_mids_reset_domain_setting_cnf_struct *cnf_msg;
    /* kal_int32 mids_domain; */
    kal_uint32 mids_id;
    mids_list_info_struct *mids_info_ptr;
    jam_mids_setting_struct default_setting;
   // mmi_setting_struct allow_setting;
    jam_mids_network_struct nw_setting = {0};
    /* mmi_setting_struct max_setting; */
    //kal_bool ret = J2ME_NO_ERROR;
    kal_int32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    req_msg = (mmi_java_mids_reset_domain_setting_req_struct*) ilm_ptr->local_para_ptr;
    cnf_msg = construct_local_para(sizeof(mmi_java_mids_reset_domain_setting_cnf_struct), TD_CTRL);

    mids_id = req_msg->mids_id;

    /* change the direction */
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();

    /* get the infor of this mids */
    mids_info_ptr = find_mids_info_by_id( mids_id, KAL_FALSE);

    /* get the setting  recorded when installing */
    jam_call_back_functions.jam_mids_get_default_setting( &default_setting, mids_id, mids_info_ptr);
    jam_call_back_functions.jam_restore_setting( &default_setting, req_msg->storage, mids_info_ptr);
    /* bug fix: origin design will reset doman with MMI domian category             */
    /*          but it should be each permission                                    */
    /*          so change to mids_list_info_struct instead of mmi_setting_struct    */
    /*          we set max setting as whar we want to reset and all choice is ALLOW */ 
    /*          so new seeting will follow max setting and this is what we want     */

    
      
    /* set the  setting recorded when installing to current seeting */
    //ret = jam_call_back_functions.jam_set_setting(type, &allow_setting, mids_id, mids_info_ptr);
    /* bug fix : the same setting will not return J2ME_NO_ERROR */
    /*           in normal case the default setting will not be error in conflict with max setting */
    /*           so, we always return true */
    /* if(ret != J2ME_NO_ERROR)        
       {
       cnf_msg->success = KAL_FALSE;            
       }
       else
       { */
    cnf_msg->success = KAL_TRUE;
    /* } */
    for(index = 0; index < MMI_SIM_TOTAL; index ++)    
    {
        jam_nw_create_setting(req_msg->storage, &nw_setting, NULL, index);
    }
    free_ctrl_buffer(req_msg->storage);
    g_jam_is_jam_in_busy = KAL_FALSE;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_CNF,cnf_msg);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  jam_set_domain_status_req
 * DESCRIPTION
 *  set the domain enable/disable ststus
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_set_domain_status_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_change_domain_req_struct *req_msg;
    mmi_java_change_domain_cnf_struct *cnf_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    req_msg = (mmi_java_change_domain_req_struct*) ilm_ptr->local_para_ptr;
    cnf_msg =
        (mmi_java_change_domain_cnf_struct*) construct_local_para(sizeof(mmi_java_change_domain_cnf_struct), TD_CTRL);

    /* set the status */
    cnf_msg->error_code = jam_call_back_functions.jam_set_domain_status(req_msg->total_domain, req_msg->status);

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_CNF,cnf_msg);
    g_jam_is_jam_in_busy = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_domain_status_req
 * DESCRIPTION
 *  get the domain enable/disable ststus
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_get_domain_status_req(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_java_get_domain_status_req_struct *req_msg;
    mmi_java_get_domain_status_cnf_struct *cnf_msg;
    kal_uint32 i;
    kal_wchar *domain_name[DOMAIN_MAX_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_is_jam_in_busy = KAL_TRUE;
    //req_msg = (mmi_java_get_domain_status_req_struct*) ilm_ptr->local_para_ptr;
    cnf_msg =
        (mmi_java_get_domain_status_cnf_struct*) construct_local_para(
                                                    sizeof(mmi_java_get_domain_status_cnf_struct),
                                                    TD_CTRL);

    for (i = 0; i < DOMAIN_MAX_COUNT; i++)
    {
        domain_name[i] = (kal_wchar*) jvm_malloc(DOMAIN_MAX_LEN * 2);
    }

    /* get the status */
    jam_call_back_functions.jam_get_domain_status(
                                &cnf_msg->total_count,
                                cnf_msg->domains_status,
                                domain_name);

    /* trans the domian string to corresponding string ID */
    for (i = 0; i < cnf_msg->total_count; i++)
    {

        if (jam_domain_compare(domain_name[i], JAM_OPERATOR_DOMAIN))
        {
            cnf_msg->domains[i] = STR_JAVA_PERM_DMN_OPERATOR;
        }
        else if (jam_domain_compare(domain_name[i], JAM_MANUFACTURER_DOMAIN))
        {
            cnf_msg->domains[i] = STR_JAVA_PERM_DMN_MANUFACTURER;
        }
        else if (jam_domain_compare(domain_name[i], JAM_THIRDPARTY_DOMAIN))
        {
            cnf_msg->domains[i] = STR_JAVA_PERM_DMN_3RDPARTY;
        }
        else if (jam_domain_compare(domain_name[i], JAM_UNTRUSTED_DOMAIN))
        {
            cnf_msg->domains[i] = STR_JAVA_PERM_DMN_UNTRUSTED;
        }
    }
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_CNF,cnf_msg);

    for (i = 0; i < DOMAIN_MAX_COUNT; i++)
    {
        jvm_free(domain_name[i]);
    }
    g_jam_is_jam_in_busy = KAL_FALSE;
}

#endif /* OGDR_SECURITY_SETTING */ 

/* JVM Task Handler */
#ifdef __DM_SCOMO_SUPPORT__
#define REMOVE_ALL_FILE_MARK "__remove_all_mids__.tmp"
#define REMOVE_SINGLE_MIDS_MARK "__remove_single_mids__.tmp"
void jam_remove_all_mids_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fh = FS_NO_ERROR;
    kal_char * sys_dir_path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sys_dir_path = _jvm_get_dir_path();
    kal_wsprintf(WCHARFilename_JAM, "%s\\%s\0", sys_dir_path,REMOVE_ALL_FILE_MARK);
    fh = FS_Open((const WCHAR *) WCHARFilename_JAM, FS_CREATE_ALWAYS | FS_READ_WRITE);
    FS_Close(fh);
}
void jam_remove_single_mids_notify(kal_char* storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_int32 fh = FS_NO_ERROR;
    kal_uint32 written_size = 0;
    kal_char * sys_dir_path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(storage_name==NULL|| strlen(storage_name)==0)return;
    sys_dir_path = _jvm_get_dir_path();
    kal_wsprintf(WCHARFilename_JAM, "%s\\%s\0", sys_dir_path,REMOVE_SINGLE_MIDS_MARK);
    fh = FS_Open((const WCHAR *) WCHARFilename_JAM, FS_CREATE_ALWAYS | FS_READ_WRITE);
    FS_Write(fh, storage_name, strlen((void*)storage_name), &written_size);
    FS_Close(fh);
}
void jam_remove_mids_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fh = FS_NO_ERROR;
    kal_uint32 file_size = 0;
    kal_uint32 read_size = 0;
    kal_char* kept_storage_name = NULL;
    kal_char * sys_dir_path = NULL;
    mmi_java_remove_mids_ind_struct *ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sys_dir_path = _jvm_get_dir_path();
    
    kal_wsprintf(WCHARFilename_JAM, "%s\\%s\0", sys_dir_path,REMOVE_ALL_FILE_MARK);
    fh = FS_Open((const WCHAR *) WCHARFilename_JAM,  FS_READ_ONLY);
    
    if(fh > FS_NO_ERROR)
    {        
        FS_Close(fh);    
        FS_Delete((const WCHAR *) WCHARFilename_JAM);
        ptr = construct_local_para(sizeof(mmi_java_remove_mids_ind_struct), TD_CTRL);
        ptr->deleteAll = KAL_TRUE;
        ptr->storage_name = NULL;
        check_incoming_call_and_block();
        java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_REMOVE_IND,ptr);
        /*Need set false after default game notify done*/
        g_jam_is_jam_in_busy = KAL_TRUE;
    }else{

        kal_wsprintf(WCHARFilename_JAM, "%s\\%s\0", sys_dir_path,REMOVE_SINGLE_MIDS_MARK);
        fh = FS_Open((const WCHAR *) WCHARFilename_JAM,  FS_READ_ONLY);
        if(fh > FS_NO_ERROR)
        {
            FS_GetFileSize(fh, &file_size);
            if(file_size<=0)return;
            kept_storage_name = get_ctrl_buffer(file_size+1);
            FS_Read(fh,kept_storage_name,file_size,&read_size);
            kept_storage_name[file_size] = '\0';
            FS_Close(fh);    
            FS_Delete((const WCHAR *) WCHARFilename_JAM);
            ptr = construct_local_para(sizeof(mmi_java_remove_mids_ind_struct), TD_CTRL);
            ptr->deleteAll = KAL_FALSE;
            ptr->storage_name = kept_storage_name;
            check_incoming_call_and_block();
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_REMOVE_IND,ptr);
        }
        
    }
}


void jam_preinstall_mids_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 error_code = J2ME_NO_ERROR;
    jam_getlist_filter_struct filter = {0};
    mids_list_info_struct *mids_info_ptr = NULL;
    kal_int32 mids_id = -1;
    mmi_java_preinstall_mids_ind_struct *ptr = NULL;
    kal_int32 mids_start_indx = -1;
    kal_int32 mids_avail_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter.filter_type = JAM_DEFAULT_GAME_FILTER;
    error_code = jam_call_back_functions.jam_get_list(
                    0, JAVA_LIST_CACHE_COUNT, &saved_mids_listfile_ptr, &filter);
    if (error_code == J2ME_NO_ERROR && saved_mids_listfile_ptr)
    {
        mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
        mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;
        mids_avail_cnt = saved_mids_listfile_ptr->mids_avail_count;
        for (mids_id = mids_start_indx; mids_id < mids_start_indx + mids_avail_cnt && mids_info_ptr; mids_id++)
        {
            ptr = (mmi_java_preinstall_mids_ind_struct*)construct_local_para(sizeof(mmi_java_preinstall_mids_ind_struct), TD_CTRL);
            if(mids_info_ptr->mids_root!=NULL)
            {
                ptr->mids_report_info.install_mids_storage_id= get_ctrl_buffer(app_ucs2_strlen((const kal_int8*)mids_info_ptr->mids_root)+1);    
                app_ucs2_str_to_asc_str((kal_int8* )(ptr->mids_report_info.install_mids_storage_id),(kal_int8*)mids_info_ptr->mids_root);
            }
            else
            {
                ASSERT(mids_info_ptr->mids_root != NULL);
            }
            if(mids_info_ptr->mids_name != NULL)
            {
                ptr->mids_report_info.install_mids_name = get_ctrl_buffer((app_ucs2_strlen((const kal_int8*)mids_info_ptr->mids_name)+1)<<1);
                app_ucs2_strcpy((kal_int8 * )(ptr->mids_report_info.install_mids_name), (const kal_int8 *)mids_info_ptr->mids_name);
            }
            else
            {
                ptr->mids_report_info.install_mids_name = NULL;
            } 
            if(mids_info_ptr->mids_vendor!= NULL)
            {
                ptr->mids_report_info.install_mids_vendor = get_ctrl_buffer((app_ucs2_strlen((const kal_int8*)mids_info_ptr->mids_vendor)+1)<<1);
                app_ucs2_strcpy((kal_int8 * )(ptr->mids_report_info.install_mids_vendor), (const kal_int8 *)mids_info_ptr->mids_vendor);
            }
            else
            {
                ptr->mids_report_info.install_mids_vendor = NULL;
            }
            if(mids_info_ptr->mids_version != NULL) 
            {
                ptr->mids_report_info.install_mids_version= get_ctrl_buffer(app_ucs2_strlen((const kal_int8*)mids_info_ptr->mids_version)+1);    
                app_ucs2_str_to_asc_str((kal_int8* )(ptr->mids_report_info.install_mids_version),(kal_int8*)mids_info_ptr->mids_version);
            }            
            else
            {
                ptr->mids_report_info.install_mids_version = NULL;
            }
            check_incoming_call_and_block();
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_IND,ptr);
            mids_info_ptr = mids_info_ptr->mids_list_info_next;
            while (jam_vm_get_next_event(KAL_FALSE, MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_RES, KAL_FALSE, KAL_TRUE) ==
                J2ME_GET_NEXT_EVENT_ABORT)
            {
                kal_sleep_task(10);  
            }

        }
        
    }
    jam_call_back_functions.jam_free_list();
    g_jam_is_jam_in_busy = KAL_FALSE;
}
#else
void jam_remove_all_mids_notify(void){}
void jam_remove_single_mids_notify(kal_char* storage_name){}
#endif /*__DM_SCOMO_SUPPORT__*/



/*****************************************************************************
 * FUNCTION
 *  jam_jvm_send_general_assist_req
 * DESCRIPTION
 *  send a request to ask JAM assistance.
 * PARAMETERS
 *  input       [?]     
 *  ilm_ptr     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_send_general_assist_req(kal_int32 index, kal_char* input, kal_int32 input_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_jvm_general_assist_req_struct *assist_req_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    assist_req_ptr = construct_local_para(sizeof(jam_jvm_general_assist_req_struct), TD_CTRL);
    assist_req_ptr->index = index;
    memcpy(assist_req_ptr->input,input,input_len);
    assist_req_ptr->input_len = input_len;
    java_send_msg_from_active_mod(MOD_JAM,J2ME_MMI_SAP,MSG_ID_JAM_JVM_GENERAL_ASSIST_REQ,assist_req_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_general_assist_req_handler
 * DESCRIPTION
 *  run VM provide general assist function on JAM task.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_general_assist_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //jam_jvm_general_assist_cnf_struct *assist_cnf_ptr;
    //kal_int32 returnCode = 0;
    kal_int32 index = 0;
    kal_char *input = NULL;
    kal_int32 input_len = 0;
    jam_jvm_general_assist_req_struct *assist_req_ptr = NULL;

    kal_bool wait_forever = KAL_FALSE; 
    msg_type expected_msg = MSG_ID_INVALID_TYPE; 
    kal_bool clean_msg = KAL_FALSE;
    kal_bool must_match = KAL_FALSE;
    kal_uint8 **abort_msg_received = NULL;

    kal_int32 cur = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    assist_req_ptr = (jam_jvm_general_assist_req_struct*) ilm_ptr->local_para_ptr;
    index = assist_req_ptr->index;
    input = assist_req_ptr->input;
    input_len = assist_req_ptr->input_len;

    if (index == JVM_GET_NEXT_EVENT_INDX)
    {
        if(input_len > sizeof(kal_bool)*3 + sizeof(msg_type))
        {
            abort_msg_received = (kal_uint8 **)(input+cur);
            cur += sizeof(kal_bool*);
        }
        else
        {
            abort_msg_received = NULL;    
        }
        
        memcpy(&wait_forever,input+cur,sizeof(kal_bool));
        cur += sizeof(kal_bool);
        memcpy(&expected_msg,input+cur,sizeof(msg_type));
        cur += sizeof(msg_type);
        memcpy(&clean_msg,input+cur,sizeof(kal_bool));
        cur += sizeof(kal_bool);
        memcpy(&must_match,input+cur,sizeof(kal_bool));
        cur += sizeof(kal_bool);
        
        // 20101225: Fix crash for http over TCK issue
        if(abort_msg_received == NULL) {
	    g_jvm_get_next_event_result = get_next_event(wait_forever, expected_msg, clean_msg, must_match, (kal_bool*)abort_msg_received);
        } else {
            g_jvm_get_next_event_result = get_next_event(wait_forever, expected_msg, clean_msg, must_match, (kal_bool*)*abort_msg_received);
        }
        kal_set_eg_events(g_java_event_group_2, JAVA_EG_JVM_GET_NEXT_EVENT_1, KAL_OR);
    }
    else
    {
        jam_call_back_functions.jam_general_assist(index,input,input_len);
    }
}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_general_assist_cnf_handler
 * DESCRIPTION
 *  run VM provide general assist function on JAM task.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_general_assist_cnf_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_general_assist_cnf_handler
 * DESCRIPTION
 *  run VM provide general assist function on JAM task.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_mid_stop_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 returnCode;
   // kal_wchar *mid_name_str = NULL;
    jam_jvm_mid_stop_req_struct *mid_stop_req_ptr;
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mid_stop_req_ptr = (jam_jvm_mid_stop_req_struct*) ilm_ptr->local_para_ptr;
    returnCode = mid_stop_req_ptr->returnCode;
    //mid_name_str = mid_stop_req_ptr->mid_name_str;
    vm_id = mid_stop_req_ptr->vm_id;
    jam_internal_mid_start_req_post_handler(vm_id,returnCode);
}

void jam_jvm_shutdown_all_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_jvm_shutdown_all_ind_struct* ptr = (jam_jvm_shutdown_all_ind_struct*)ilm_ptr;
    kal_bool is_timealarm_push_start = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_mvm_shutdown_all();
    if (jam_mvm_get_running_count() == 0)
    {
        if (g_jam_start_up_mode == 1)
        {
            is_timealarm_push_start = KAL_FALSE;
        }
        else if (g_jam_start_up_mode == 0)
        {
            is_timealarm_push_start = KAL_TRUE;
        }
        jam_send_stop_ind(g_jam_last_terminate_vm_id, g_jam_last_terminate_error_code, is_timealarm_push_start);
        g_jam_last_terminate_vm_id = -1;
        g_jam_last_terminate_error_code = 0;
    }
    g_jam_is_jvm_in_busy = KAL_FALSE;
    jam_send_shutdown_all_ind((ptr!=NULL?ptr->returnCode:J2ME_NO_ERROR));
}

/*****************************************************************************
 * FUNCTION
 *  jam_jvm_general_assist_cnf_handler
 * DESCRIPTION
 *  run VM provide general assist function on JAM task.
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_jvm_tck_stop_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_jvm_tck_stop_req_struct *ptr =NULL;
    mmi_java_terminate_notify_struct * terminate_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = (jam_jvm_tck_stop_req_struct*) ilm_ptr->local_para_ptr;
    terminate_ptr = (mmi_java_terminate_notify_struct *) get_ctrl_buffer(sizeof(mmi_java_terminate_notify_struct));
    terminate_ptr->vm_id = ptr->vm_id;
    terminate_ptr->return_code = ptr->returnCode;
    terminate_ptr->is_timealarm_push_start = KAL_FALSE;
    terminate_ptr->is_tck = KAL_TRUE;
    jam_exit_screen(terminate_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_cbm_bearer_info_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern void jnw_cbm_bearer_info_handler(app_cbm_bearer_info_ind_struct *ind_ptr);
void jam_cbm_bearer_info_handler(ilm_struct *ilm_ptr)
{
    app_cbm_bearer_info_ind_struct *ind_ptr = (app_cbm_bearer_info_ind_struct*) ilm_ptr->local_para_ptr;
    jnw_cbm_bearer_info_handler(ind_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_global_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_get_global_setting_req_handler(ilm_struct *ilm_ptr)
{
#ifndef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_global_setting_req_struct *req_ptr;
    mmi_java_nw_get_global_setting_rsp_struct *rsp_ptr;
    kal_uint8 sim_id = 0;
    kal_uint8 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_NW_GET_GLOBAL_SETTING_REQ_HANDLER);    
    req_ptr = (mmi_java_nw_get_global_setting_req_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_get_global_setting_rsp_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_get_global_setting_rsp_struct),
                                                    TD_CTRL);

    for(index = 0; index < MMI_SIM_TOTAL; index ++)    
    {
        sim_id = index;
        jam_nw_adp_sim_id(&sim_id, INTEGER0_TO_BIT);
        g_mmi_java_nw_cntx.sim_index |= sim_id;
        rsp_ptr->error_code = jam_nw_get_setting("global", (req_ptr->network[index]));
        g_mmi_java_nw_cntx.sim_index &= NW_SIM_ID_DEFAULT;
    }

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_RSP,rsp_ptr);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_local_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_get_local_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mmi_java_nw_get_local_setting_req_struct *req_ptr;
    mmi_java_nw_get_local_setting_rsp_struct *rsp_ptr;
    kal_uint8 sim_id;
    kal_uint8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_NW_GET_LOCAL_SETTING_REQ_HANDLER);        
    req_ptr = (mmi_java_nw_get_local_setting_req_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_get_local_setting_rsp_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_get_local_setting_rsp_struct),
                                                    TD_CTRL);
    for(index = 0; index < MMI_SIM_TOTAL; index ++)    
    {
        sim_id = index;
        jam_nw_adp_sim_id(&sim_id, INTEGER0_TO_BIT);
        g_mmi_java_nw_cntx.sim_index |= sim_id;
        rsp_ptr->error_code = jam_nw_get_setting(req_ptr->storage, (req_ptr->network[index]));
        g_mmi_java_nw_cntx.sim_index &= NW_SIM_ID_DEFAULT;
    }

    rsp_ptr->storage= req_ptr->storage;  
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_RSP,rsp_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_set_global_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_set_global_setting_req_handler(ilm_struct *ilm_ptr)
{
    #ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_global_setting_req_struct *req_ptr;
    mmi_java_nw_set_global_setting_rsp_struct *rsp_ptr;
    kal_int32 index = 0;
    kal_uint8 sim_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_NW_SET_GLOBAL_SETTING_REQ_HANDLER);        
    req_ptr = (mmi_java_nw_set_global_setting_req_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_set_global_setting_rsp_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_set_global_setting_rsp_struct),
                                                    TD_CTRL);
    
    for(index = 0;index<MMI_SIM_TOTAL;index++)
    {
        sim_id = index;
        jam_nw_adp_sim_id(&sim_id, INTEGER0_TO_BIT);
        g_mmi_java_nw_cntx.sim_index |= sim_id;
        if(req_ptr->network[index]!=NULL)
        { 
            rsp_ptr->error_code = jam_nw_set_setting("global", (req_ptr->network[index]));    
    }
        g_mmi_java_nw_cntx.sim_index &= NW_SIM_ID_DEFAULT;
    }
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_RSP,rsp_ptr);

#endif
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_set_local_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_set_local_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_set_local_setting_req_struct *req_ptr;
    mmi_java_nw_set_local_setting_rsp_struct *rsp_ptr;
    kal_int32 index = 0;
    kal_uint8 sim_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_NW_SET_LOCAL_SETTING_REQ_HANDLER);        

    req_ptr = (mmi_java_nw_set_local_setting_req_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_set_local_setting_rsp_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_set_local_setting_rsp_struct),
                                                    TD_CTRL);  
    for(index = 0;index<MMI_SIM_TOTAL;index++)
    {
        sim_id = index;
        jam_nw_adp_sim_id(&sim_id, INTEGER0_TO_BIT);
        g_mmi_java_nw_cntx.sim_index |= sim_id;    
        if(req_ptr->network[index]!=NULL)
        {
            rsp_ptr->error_code = jam_nw_set_setting(req_ptr->storage, (req_ptr->network[index]));    
    }
        g_mmi_java_nw_cntx.sim_index &= NW_SIM_ID_DEFAULT;
    }
    rsp_ptr->storage= req_ptr->storage;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_RSP,rsp_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_get_profile_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_get_profile_req_handler(ilm_struct *ilm_ptr)
{
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_set_profile_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_set_profile_req_handler(ilm_struct *ilm_ptr)
{
}

/*****************************************************************************
 * FUNCTION
 *  jam_nw_update_setting_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_update_setting_req_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_mids_network_struct connection  = {0};
    kal_int32 err_code = NW_OP_NO_ERR;
    kal_int32 vm_id = 0;
    mmi_java_nw_update_setting_req_struct* msg = (mmi_java_nw_update_setting_req_struct*)ilm_ptr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_NW_UPDATE_SETTING_REQ_HANDLER);   
    vm_id = msg->vm_id;   
    if(vm_id != INVALIDE_VM_ID)
    {        
        while(1)
        {     
            err_code =  jam_nw_mids_get_connection((kal_char*)jam_mvm_get_storage_name_by_vm_id(vm_id),&connection);
            if( err_code == NW_OP_ERR_BUSY)
            {
                kal_trace(TRACE_FUNC, JAM_NW_MIDS_GET_CONNECTION_RET,err_code); 
                kal_sleep_task(100);
            }
            else
            {
                break;
            }
        }
        jam_nw_mids_set_bearer_content(connection.account_id,KAL_FALSE,vm_id);
    }
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_UPDATE_SETTING_RSP,NULL);
} 


/*****************************************************************************
 * FUNCTION
 *  jam_nw_update_conn_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_update_conn_req_handler(ilm_struct *ilm_ptr)
{
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_update_dtcnt_ind_handler
 * DESCRIPTION
 *  update connection after data account profile update
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
extern  kal_int8 jam_nw_dtcnt_update_conn(srv_dtcnt_acct_update_ind_evt_struct update_info);
void jam_nw_update_dtcnt_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_update_dtcnt_ind_struct *req_ptr;
    mmi_java_nw_update_dtcnt_cnf_struct *rsp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_ptr = (mmi_java_nw_update_dtcnt_ind_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_update_dtcnt_cnf_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_update_dtcnt_cnf_struct),
                                                    TD_CTRL);
    
    rsp_ptr->error_code = jam_nw_dtcnt_update_conn(req_ptr->account_info);

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_UPDATE_CONN_TYPE_RSP,rsp_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_nw_delete_dtcnt_ind_handler
 * DESCRIPTION
 *  update connection after data account profile deleted
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_nw_delete_dtcnt_ind_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_delete_dtcnt_ind_struct *req_ptr;
    mmi_java_nw_delete_dtcnt_cnf_struct *rsp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_ptr = (mmi_java_nw_delete_dtcnt_ind_struct*) ilm_ptr->local_para_ptr;
    rsp_ptr =
        (mmi_java_nw_delete_dtcnt_cnf_struct*) construct_local_para(
                                                    sizeof(mmi_java_nw_delete_dtcnt_cnf_struct),
                                                    TD_CTRL);
    
    rsp_ptr->error_code = jam_nw_dtcnt_delete_conn(req_ptr->account_info);
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_UPDATE_CONN_TYPE_RSP,rsp_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_getlist_detect_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_getlist_detect_response(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_RSP,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  jam_mvm_get_running_mids_list_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_mvm_get_running_mids_list_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_running_mids_rsp_struct * rsp_ptr;
    mmi_java_get_running_mids_req_struct * req_ptr;
    kal_int32 err_code = J2ME_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_ptr = (mmi_java_get_running_mids_req_struct*) ilm_ptr->local_para_ptr;
    *(req_ptr->running_mid_list) = jam_mvm_get_running_mids_list(&err_code,req_ptr->count);
    req_ptr->err_code = err_code;
    kal_set_eg_events(g_java_event_group_2,JAVA_EG_GET_RUNNING_LIST,KAL_OR);
    rsp_ptr = (mmi_java_get_running_mids_rsp_struct*) construct_local_para(
                                                    sizeof(mmi_java_get_running_mids_rsp_struct),
                                                    TD_CTRL);
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_CNF,rsp_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jam_check_is_running_mids
 * DESCRIPTION
 *  check whether a MIDlet is the current running by storage name
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 * void
 *****************************************************************************/
void jam_check_is_running_mids(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_check_push_mid_running_req_struct* req;
    mmi_java_check_push_mid_running_rsp_struct* rsp = NULL;
	#if (MAX_VM_INSTANCE_NUM > 1)
    kal_char * current_fg_running_storage_name = NULL;
	#endif  
    MMI_ID group_id;
    MMI_ID screen_id;
    mmi_group_node_struct group_info;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_java_check_push_mid_running_req_struct*) ilm_ptr->local_para_ptr;
    rsp = (mmi_java_check_push_mid_running_rsp_struct*) construct_local_para(
                                                sizeof(mmi_java_check_push_mid_running_rsp_struct),
                                                    TD_CTRL);

    mmi_frm_get_active_scrn_id(&group_id, &screen_id);
#ifndef __COSMOS_MMI_PACKAGE__
    for (i = 0; group_id != GRP_ID_JAVA_TEXTFIELD && i < 3; i++)
    {
        mmi_frm_group_get_info(group_id, &group_info);
        group_id = group_info.parent; 
    }
#endif

#if (MAX_VM_INSTANCE_NUM > 1)
    rsp->result = 0;

    if(MAX_VM_INSTANCE_NUM - jam_mvm_get_running_count() == 0)
    {
        rsp->result |= JAM_MIDLET_STATUS_VM_IS_SLOT_FULL;
    }

    if (jam_mvm_get_current_vm_id() != -1)
    {
        current_fg_running_storage_name = (kal_char*)jam_mvm_get_current_storage_name();
        if(strcmp(current_fg_running_storage_name, req->mid_storage_name))
        {
            rsp->result |= JAM_MIDLET_STATUS_OTHERS_SUITE_LAUNCH_IN_FG;
        }
    }

    if (jam_mvm_has_running_midlet_in_mids(req->mid_storage_name))
    {
        if (jam_mvm_get_current_vm_id() != -1 && !(rsp->result & JAM_MIDLET_STATUS_OTHERS_SUITE_LAUNCH_IN_FG))
        {
            rsp->result |= JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_FG;
        }
        else
        {
            rsp->result |= JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_BG; 
        }
		
        if(!jam_mvm_midlet_is_running(req->mid_storage_name, req->mid_id))
        {
            rsp->result |= JAM_MIDLET_STATUS_SUITE_LAUNCH_BUT_MIDLET;
        }
        else
        {
            /* MAUI_02728052 */
            if (rsp->result & JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_FG)
            {
                if (jam_mvm_get_vm_state(jam_mvm_get_vm_id(req->mid_storage_name, req->mid_id)) == JVM_LONG_EVENT_STATE &&
                #ifdef __COSMOS_MMI_PACKAGE__
                    !vapp_java_is_in_per_dialog() &&
                    screen_id != SCR_ID_JAVA_UI_TEXTFIELD_EDITOR &&
                    screen_id != SCR_ID_JAVA_UI_DATEFIELD_DATE
                #else
                    (screen_id != SCR_JAVA_GET_PERMISSION &&
                     screen_id != SCR_ID_JAVA_UI_DATEFIELD_DATE &&
                     group_id != GRP_ID_JAVA_TEXTFIELD)
                #endif
                    )
                {
                    rsp->result &= ~JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_FG;
                    rsp->result |= JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_BG;
                }
            }
        }
    }
    else
    {
        rsp->result |= JAM_MIDLET_STATUS_SUITE_NOT_LAUNCH;
    }
    g_mmi_java_push_cntx.check_mid_running_result = rsp->result;
#else
    if(jam_mvm_has_running_midlet_in_mids(req->mid_storage_name) &&
       jam_mvm_midlet_is_running(req->mid_storage_name, req->mid_id) && 
       (jam_mvm_get_vm_state(0) == JVM_FG_RUNNING_STATE ||
        jam_mvm_get_vm_state(0) == JVM_FG_MMI_RUNNING_STATE ||
    #ifdef __COSMOS_MMI_PACKAGE__
        vapp_java_is_in_per_dialog() ||
        screen_id != SCR_ID_JAVA_UI_TEXTFIELD_EDITOR ||
        screen_id == SCR_ID_JAVA_UI_DATEFIELD_DATE
    #else
        (screen_id == SCR_JAVA_GET_PERMISSION ||
         screen_id == SCR_ID_JAVA_UI_DATEFIELD_DATE ||
         group_id == GRP_ID_JAVA_TEXTFIELD)
    #endif
       ))
    {
        rsp->ret = KAL_TRUE;
    }
    else
    {
        rsp->ret = KAL_FALSE;
    }
    g_mmi_java_push_cntx.check_mid_running_result = (kal_uint8)rsp->ret;
#endif    
    kal_set_eg_events(g_java_event_group_1, JAVA_EG_PUSH_CHECK_RUNNING, KAL_OR);
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_RSP,rsp);
}


kal_bool jam_is_network_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jam_is_network_usable_struct* req;
    kal_uint32 event_group;
    kal_bool is_usable = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     req = (jam_is_network_usable_struct*) construct_local_para(
                                                    sizeof(jam_is_network_usable_struct),
                                                    TD_CTRL);    
    req->is_useable = &is_usable;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NW_USABLE_REQ,req);
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_NW_USEABLE, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
    return is_usable;
    
}

#ifdef J2ME_SLIM_MEMORY_SUPPORT
void *jam_wap_mem_alloc(kal_int32 *ret_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8  threshold = 0;
    kal_uint32 size = 5;
    kal_uint32 unit = 10240; /*10k*/
    void *memory = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    
    while(size > threshold )
    {
        memory = WAP_memAllocExt(size*unit);
        if(memory!=NULL)
        {
            *ret_size = size*unit;
            //wap_mem_need_java_hold = memory;
            //kal_trace(TRACE_INFO,J2ME_ALLOC_MEM_FROM_WAP,memory,*ret_size);
            return memory;
        }
        size--;
    }
    *ret_size = 0;
    //wap_mem_need_java_hold = NULL;	
   // kal_trace(TRACE_INFO,J2ME_FREE_MEM_TO_WAP);
    return NULL;
}

void jam_wap_mem_free(void *memory)
{
	if(memory!=NULL)
	{
		WAP_memFreeExt(memory);
    	//wap_mem_need_java_hold = NULL;
    	//kal_trace(TRACE_INFO,J2ME_ALLOC_WAP_MEM_FAIL);
	}
}
#endif

#ifdef J2ME_SUPPORT_BACKGROUND
#define J2ME_ALLOCATE_ASM_SIZE_LIMIT  (10240)/* 10K */
static kal_bool g_jam_j2me_use_asm_memory = KAL_FALSE;
static void *g_jam_j2me_asm_memory_point = NULL;

/* g_jam_j2me_use_asm_memory get function */
#ifdef J2ME_SUPPORT_BACKGROUND
static kal_bool jam_asm_memory_is_used()
{
    return g_jam_j2me_use_asm_memory;
}
#endif
/* g_jam_j2me_use_asm_memory set function */
static void jam_asm_memory_used_set(kal_bool is_used)
{
    g_jam_j2me_use_asm_memory = is_used;
}

/* g_jam_j2me_asm_memory_point set function */
static void jam_asm_memory_point_set(void * memory_addess)
{
    g_jam_j2me_asm_memory_point = memory_addess;
}

/* g_jam_j2me_asm_memory_point get function */
static void* jam_asm_memory_point_get(void)
{
    return g_jam_j2me_asm_memory_point;
}

static void *jam_asm_left_memory_alloc(kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memory = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*size = mmi_frm_asm_get_max_alloc_size_r(0);


	if((*size) - 210 * 1024 > J2ME_ALLOCATE_ASM_SIZE_LIMIT)
	{
		*size -= 210 * 1024 ;
	    memory = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,*size);
		jam_asm_memory_point_set(memory);
		jam_asm_memory_used_set(KAL_TRUE);
	}

	return memory;

}

static void jam_asm_left_memory_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	void *memory = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memory = jam_asm_memory_point_get();
	if(memory)
	{
        applib_mem_ap_free(memory);
		jam_asm_memory_point_set(NULL);
		jam_asm_memory_used_set(KAL_FALSE);
	}

}



kal_bool jam_asm_memory_pool_prepared(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int   asmMemSize = 0;
	void *asmMem = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asmMem = jam_asm_left_memory_alloc(&asmMemSize);

    if(asmMem !=NULL)
    {
        jam_call_back_functions.jam_asm_memory_initialize((long *)asmMem,asmMemSize);
		return KAL_TRUE;
    }

	return KAL_FALSE;
}

#ifdef J2ME_SUPPORT_BACKGROUND
static void jam_asm_memory_pool_free(void)
{
    jam_call_back_functions.jam_asm_memory_finalize();
	jam_asm_left_memory_free();

}
#endif 

#endif

/*****************************************************************************
* FUNCTION 
* jam_plug_in_out_tcard_handler
* DESCRIPTION
* 
* PARAMETERS
* ilm_struct *ilm_ptr
* RETURNS 
* void 
*modify/add date: 2012-9-03
*modify/add time: 16:58:41
*****************************************************************************/
void jam_plug_in_out_tcard_handler(ilm_struct *ilm_ptr)
	{
	#if defined(J2ME_SLIM_MEMORY_SUPPORT)
		/*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
		 mmi_java_plug_in_out_tcard_struct *ind_ptr = NULL;
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
		ind_ptr = (mmi_java_plug_in_out_tcard_struct*) ilm_ptr->local_para_ptr;

		switch (ind_ptr->evt_id)
		{
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
				javaFileGenerator(KAL_FALSE); 	
             #ifdef __SUPPORT_JAVA_PUSH__
				jpush_push_clear();
				jpush_push_open(PUSHPATH_NAME);
				jpush_alarm_open(ALARMPATH_NAME);
				jpush_init_persistent_push_entries();
             #endif
				break;
			case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
#ifdef __COSMOS_MMI_PACKAGE__
				if (!mmi_java_is_installing() && jam_mvm_get_running_count() == 0)
				{
					vapp_java_close_venus_screen();
				}
				mmi_java_nw_dtcnt_cui_close();
#else
				mmi_frm_scrn_close(GRP_ID_JAVA_CONFIRM, SCR_JAVA_LAUNCH_AFTER_INSTALL);
				mmi_frm_group_close(GRP_ID_JAVA_SETTING);
				mmi_frm_group_close(GRP_ID_JAVA_SECURITY);
				mmi_frm_group_close(APP_JAVA);
#endif
#if (defined(__MMI_NCENTER_SUPPORT__)&&defined(__SUPPORT_JAVA_PUSH__))
				mmi_java_push_ncenter_event_hide();
#else
				mmi_frm_group_close(GRP_ID_JAVA_TIMEALARM_PUSH);
#endif
				break;
			default:
				break;
		}
#endif
	}
void jam_get_appmgr_info_req_handler(ilm_struct *ilm_ptr)
{

	//ilm_struct *send_ilm;
	kal_uint32 mids_id;
	kal_int32 error_code = J2ME_NO_ERROR;
	mmi_java_get_appmgr_info_req_struct *get_appmgr_info_req_ptr;

	mids_list_info_struct *pmids_list = NULL;
	kal_uint32 i, mids_mid_count = 0;
	kal_int32 mids_start_indx;
		 
	kal_uint8 attribute;
	kal_char	storage_name[20];

	kal_trace(TRACE_FUNC, FUNC_J2ME_MIDS_GETINFO_REQ_HANDLER);
			  
	get_appmgr_info_req_ptr = (mmi_java_get_appmgr_info_req_struct*) ilm_ptr->local_para_ptr;
			  
	mids_id = get_appmgr_info_req_ptr->mids_id;
			  
	 /* Update working internal system directory path */
	g_jam_is_jam_in_busy = KAL_FALSE;
	work_sys_dir_path = _jvm_get_dir_path();
	work_info_ptr = _jvm_get_builtin_file_info();

	jam_parse_midslistfile( mids_id - 1, 1, &saved_mids_listfile_ptr, g_jam_last_filter);

    if (mids_id && saved_mids_listfile_ptr)
    {
        if (error_code == J2ME_NO_ERROR)
        {
            pmids_list = saved_mids_listfile_ptr->mids_info_list;
            mids_start_indx = saved_mids_listfile_ptr->mids_avail_indx;

            for (i = 1; i < mids_id - mids_start_indx && pmids_list; i++)
            {
                pmids_list = pmids_list->mids_list_info_next;
            }
        }
    }
    else
    {
        error_code = J2ME_MIDS_NOT_EXIST;
    }

    if (error_code == J2ME_NO_ERROR && pmids_list)
    {
        mids_mid_count = pmids_list->mid_info.mid_count;
    }
    //get_appmgr_info_req_ptr->appmgr_mids_info= get_ctrl_buffer(sizeof(mmi_java_mids_getinfo_cnf_struct));
    //get_appmgr_info_req_ptr->error_code = error_code;

	trans_ucs2_to_utf8(storage_name,pmids_list->mids_root);

	if (mids_start_indx < j2me_default_game_count
		#ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__	
			||srv_java_appfactory_mids_is_default(storage_name)
		#endif
	   )
		{
					   attribute = IS_DEFAULT_GAME;    /* default game can not be updated and removed */
					   if (pmids_list->webside &&
						   strncmp((kal_char*) pmids_list->webside, "h\0t\0t\0p\0:\0/\0/\0", 14) == 0)
					   {
						   attribute |= CAN_BE_UPDATE;
					   }
		}
		else
		{
		   #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
					   attribute = CAN_BE_UPDATE | CAN_BE_REMOVE | CAN_BE_SEND;  /* not a default game */
		   #else
					   attribute = CAN_BE_UPDATE | CAN_BE_REMOVE;
		   #endif
		}
		
		if (pmids_list->jad_url != NULL)
		{
					   /* check if the url starts with "file://" */
					   if (strncmp((kal_char*) pmids_list->jad_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
					   {
						   attribute &= ~CAN_BE_UPDATE;    /* local install game, can not be updated */
					   }
		}
		 else if (pmids_list->jar_url != NULL)
		{
					   /* check if the url starts with "file://" */
					   if (strncmp((kal_char*) pmids_list->jar_url, "f\0i\0l\0e\0:\0/\0/\0", 14) == 0)
					   {
						   attribute &= ~CAN_BE_UPDATE;    /* local install game, can not be updated */
					   }
		}
	    #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
				   if (!jam_drm_can_be_send(mids_start_indx+i+1)) /* mids number start from 1 */
				   {
						attribute &= ~CAN_BE_SEND;	 
				   }
		#endif
		#ifndef	BROWSER_SUPPORT
					   attribute &= ~CAN_BE_UPDATE;
		#endif /*!BROWSER_SUPPORT*/

      if (attribute & CAN_BE_REMOVE)
        get_appmgr_info_req_ptr->can_be_uninstall = KAL_TRUE;
    else
        get_appmgr_info_req_ptr->can_be_uninstall = KAL_FALSE;
    if (attribute & CAN_BE_UPDATE)
        get_appmgr_info_req_ptr->can_be_update = KAL_TRUE;
    else
        get_appmgr_info_req_ptr->can_be_update = KAL_FALSE;
    
    //if (attribute & IS_DEFAULT_GAME)
    //    get_appmgr_info_req_ptr->appmgr_mids_info->storage_type = PHONE_DISK;
    //else
    {
        kal_wchar* wjarpath = jam_call_back_functions.jam_get_jar_path_from_storage_name(jam_listmem_malloc,(kal_char*)storage_name);
        if(wjarpath[0] == SRV_FMGR_PUBLIC_DRV)
           get_appmgr_info_req_ptr->storage_type = 0;
        else 
            get_appmgr_info_req_ptr->storage_type = 1;
        jam_listmem_free((void *) wjarpath);
    }    


    //ASSERT(get_appmgr_info_req_ptr->appmgr_mids_info==NULL);
    if (error_code == J2ME_NO_ERROR)
    {
        get_appmgr_info_req_ptr->mids_name = pmids_list->mids_name;
        get_appmgr_info_req_ptr->mids_size = pmids_list->mids_size;
        get_appmgr_info_req_ptr->mids_version = pmids_list->mids_version;
        get_appmgr_info_req_ptr->mids_vendor = pmids_list->mids_vendor;
        get_appmgr_info_req_ptr->mids_description = pmids_list->mids_description;
        /* A MIDlet has webside starting with "file://" is a local install MIDlet.
           We should not display the webside information to user since it is not meaningful */
        if (strncmp((kal_char*) pmids_list->webside, "f\0i\0l\0e\0:\0/\0/\0", 14) != 0)
        {
            get_appmgr_info_req_ptr->mids_website = pmids_list->webside;
        }
        else
        {
            get_appmgr_info_req_ptr->mids_website = (kal_wchar*) "\0\0";
        }
        get_appmgr_info_req_ptr->mids_authorized = pmids_list->mids_authorized;

   }
  
		kal_set_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_3, KAL_OR);  
		return;
}
