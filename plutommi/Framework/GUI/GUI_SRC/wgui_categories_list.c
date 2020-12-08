/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   wgui_categories_list.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  list category related funtions
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "CustDataRes.h"
#include "CustDataProts.h"
#include "lcd_if.h"
#include "ScreenRotationGprot.h"
#include "wgui_asyncdynamic_menus.h"
#include "wgui_tab_bars.h"
#include "wgui_dynamic_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_softkeys.h"

#include "gui_font_size.h"

#include "CommonScreens.h"
#include "FileMgrSrvGProt.h"

#include "CustThemesRes.h"

/*RHR*/
    #include "wgui_categories_list.h"
    #include "gui_data_types.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gdi_include.h"
    #include "gui.h"
    #include "gui_windows.h"
    #include "wgui.h"
    #include "wgui_categories_IMPS.h"
    #include "gui_typedef.h"
    #include "gui_effect_oem.h"
    #include "MMI_features.h"
    #include "mmi_frm_input_gprot.h"
    #include "wgui_fixed_menus.h"
    #include "gui_fixed_menus.h"
    #include "wgui_categories_util.h"
    #include "wgui_include.h"
    #include "wgui_asyncdynamic_menuitems.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "gui_fixed_menuitems.h"
    #include "wgui_categories.h"
    #include "gui_themes.h"
    #include "wgui_inputs.h"
    #include "gui_buttons.h"
    #include "gdi_const.h"
    #include "gui_theme_struct.h"
    #include "wgui_draw_manager.h"
    #include "wgui_categories_enum.h"
    #include "gui_switch.h"
    #include "gui_scrollbars.h"
    #include "PixcomFontEngine.h"
    #include "FontRes.h"
    #include "wgui_title.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_events_gprot.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "gui_config.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "gdi_datatype.h"
    #include "MMI_features_switch.h"
    #include "MMI_features_type.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_history_gprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "CustMenuRes.h"
    #include "wgui_categories_defs.h"
    #include "string.h"
    #include "wgui_categories_inputs.h"
    #include "wgui_touch_screen.h"
    #include "gui_tab_bars_pre_oem.h"
    #include "wgui_categories_popup.h"
    #include "gui_inputs.h"
    #include "ImeGprot.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "gui_menu_post_oem.h"
    #include "gd_include.h"
    #include "custom_mmi_default_value.h"
	#include "wgui_categories_search.h"
    #include "wgui_softkeys_post_oem.h"
/*RHR end*/

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) || defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__)
#include "gui_text_frame.h"
#include "gui_asyncdynamic_menus.h"
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ || __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#ifdef __J2ME__
extern gdi_handle jui_layer_handle;
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
extern void gui_title_oem_show_normal_ex(void);
#endif
#endif /* __J2ME__ */ 

#if defined(__ATV_SMS_SUPPORT__)

typedef struct _atv_sms_struct
{
    MMI_BOOL Isuse;
    S32 CatId;
    FuncPtr	atv_sms_cb;
} atv_sms_struct;

static atv_sms_struct g_atv_sms_struct;

static void wgui_cate_reset_atv_sms_struct(void);
static void wgui_cate_execute_atv_sms_cb(void);
#endif /* __ATV_SMS_SUPPORT__ */


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static wgui_cat_get_list_menu_flags_funcptr_type wgui_cat_get_list_menu_flags_callback = NULL;
static s32 wgui_cat_cascading_menu_last_width = 0;
static UI_string_type MMI_list_empty_string = NULL;
static MMI_BOOL MMI_list_show_empty = MMI_TRUE;
static gdi_image_cache_bmp_struct g_cache_small_list_bg = {0, 0, NULL};

static gdi_image_cache_bmp_struct g_cascading_cache_buf;

#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
static MMI_BOOL g_cat_list_is_show_thumbnail = MMI_FALSE;
#endif

static GetAsyncItemFuncPtr wgui_cat_AsyncItemFuncPtr;
static GetAsyncHintFuncPtr wgui_cat_AsyncHintFuncPtr;

extern BOOL dynamic_item_text_align_left;

extern void ExitListCategoryScreen(void);
extern void ShowListCategoryScreen_ext(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                UI_string_type right_softkey);

#define wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey)	\
					ShowListCategoryScreen_ext((UI_string_type)title, (PU8)title_icon, (UI_string_type)left_softkey, (UI_string_type)right_softkey)

static void ShowCategory1704Screen(
                U8 *title,
                PU8 title_icon,
                U8 *left_softkey,
                U8 *right_softkey,
                S32 number_of_items,
                U8 **list_of_items,
                PU8 *list_of_icons,
                U8 **list_of_descriptions,
                S32 flags,
                MMI_BOOL scroll_text,
                S32 highlighted_item,
        U8 *history_buffer);

extern void RedrawListCategoryScreen(void);

static scrolling_text wgui_catEMS_scrolling_text;

#if !defined(__MMI_FTE_SUPPORT__)
#define MMI_ICON_BAR_HEIGHT MMI_TITLE_HEIGHT
#endif /* __MMI_FTE_SUPPORT__ */
#define MMI_FTE_TOOLBAR_HEIGHT MMI_ICON_BAR_HEIGHT
#define MMI_FTE_SMALLLIST_GAP 20
#define MMI_FTE_TOOLBAR_START_X 10
/*----------------------------Async Dynamic Multi Row List-----------------------------*/
// *************************************************************************************//
extern S32 gui_asyncdynamic_list_error;
extern U16 title_bg_id;

/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
	#define CAT627_TOP_GAP 5
#else
	#define CAT627_TOP_GAP 2
#endif
#define CAT627_MENUITEM_HEIGHT CAT425_MENUITEM_HEIGHT

/***************************************************************************** 
* Local Variable
*****************************************************************************/
S32 g_cat_tab_num = 0;


/*****************************************************************************
 * FUNCTION
 *  RedrawListCategoryScreen
 * DESCRIPTION
 *  Redraw category function of current main lcd category scrren using list menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawListCategoryScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_TITLE_TRANSITION__
    S32 no_transition_in_title = 0;

    {
        if ((gOnFullScreen & MMI_IN_FULL_SCREEN || gOnFullScreen & MMI_LEAVE_FULL_SCREEN) &&
            !(gOnFullScreen & MMI_LEAVE_FULL_IDLE_SCREEN))
        {
            no_transition_in_title = 1;
        }
        if (get_title_transition() != WGUI_TRANSITION_NONE && !no_transition_in_title)
        {
            draw_title();
        }
    }
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 

    gdi_layer_lock_frame_buffer();
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
#endif 

#ifdef __MMI_WGUI_MINI_TAB_BAR__
    if (wgui_if_mini_tab_bar_enable() == MMI_TRUE)
    {
        move_fixed_list(MMI_fixed_list_menu.x, MMI_content_y + 5);
        resize_fixed_list(MMI_fixed_list_menu.width, MMI_fixed_list_menu.height - 5);
        wgui_show_mini_tab_bar();
    }
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
    clear_buttonbar();
    show_title_status_icon();

#ifdef __MMI_UI_TITLE_TRANSITION__
    if (no_transition_in_title || get_title_transition() == WGUI_TRANSITION_NONE)
#endif 

    /* For transition, title function call should be from here */
    draw_title();

    show_fixed_list();
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}   /* end of RedrawListCategoryScreen */


/*****************************************************************************
 * FUNCTION
 *  ExitListCategoryScreen
 * DESCRIPTION
 *  Exit category function of current main lcd category scrren using list menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitListCategoryScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    reset_fixed_list();
    reset_pop_up_descriptions();
    /* Reset key callback in editor option menu */
    wgui_inputs_option_menu_reset_key_callback();
    wgui_inputs_option_menu_reset_highlight_callback();
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_reset_pop_up_description_transition();
#endif

}   /* end of ExitListCategoryScreen */


/*****************************************************************************
 * FUNCTION
 *  wgui_stop_list_menuitem_scrolling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_stop_list_menuitem_scrolling(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif
    gui_fixed_icontext_list_menuitem_stop_scroll();
    gui_fixed_icontext_menuitem_stop_scroll();
    gui_fixed_text_menuitem_stop_scroll();
    gui_fixed_twostate_menuitem_stop_scroll();
#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
    wgui_two_line_stop_scroller();
#endif
    /* IMPORTANT: stop the popup description scrolling */
    gui_pop_up_description_stop_scroll();
}
/* End of Common List Category Screen  */


/*****************************************************************************
* Category 628
* Dynamic icon-text list with check-box
*****************************************************************************/
static void DrawCate628CategoryControlAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_disable_left_softkey
 * DESCRIPTION
 *  disable left softkey when all items are disabled in list menu
 *  this is a bug for MAUI_02988276
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_disable_left_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
    if (MMI_fixed_list_menu.highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
        set_left_softkey_label(NULL);
        set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
        set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
        clear_softkey_handler(MMI_LEFT_SOFTKEY);
        clear_softkey_handler(MMI_CENTER_SOFTKEY);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_load_string
 * DESCRIPTION
 *  convert menuitem from ID to String with buffer "subMenuDataPtrs"
 * PARAMETERS
 *  number_of_items	[IN]		number of items
 *  list_of_items		[IN]		the array of list items ID
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_load_string(S32 number_of_items, U16 *list_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8)GetString(list_of_items[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_set_right_softkey_function
 * DESCRIPTION
 *  set right softkey function for on/off category
 * PARAMETERS
 *  vMod     [IN]        the flag for Done or back right softkey
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_set_right_softkey_function(U8 vMod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vMod)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        set_right_softkey_function(checkbox_toggle_BACK_RSK_function, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryCommonScreen
 * DESCRIPTION
 *  Exits the Common category screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategoryCommonScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ExitListCategoryScreen();
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_reset_atv_sms_struct();
#endif /* __ATV_SMS_SUPPORT__ */

}   /* end of ExitCategoryCommonScreen */


#ifdef __MMI_UI_HINTS_IN_MENUITEM__

PU8 default_empty_description = (PU8)(L" ");
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_configure_slim_hint
 * DESCRIPTION
 *  set hint in menuitem if hint exist
 *  this function is valid for compile option __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_configure_slim_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    set_force_all_hints_in_menuitem();
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_set_default_empty_descriptions
 * DESCRIPTION
 *  set default empty hint for two line show in menuitem if hint no-exist
 *  this function is valid for compile option __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__
 * PARAMETERS
 *  number_of_items	[IN]		number of items    
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_set_default_empty_descriptions(S32 number_of_items)
{
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, hints = 0;
    UI_string_type text;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    for (i = 0; i < number_of_items; i++)
    {
        text = wgui_pop_up_description_strings[i].text_strings[0];
        if (!((text == NULL) || (*((U8*)(text)) == 0 && *((U8*)(text) + 1) == 0)))
        {
            hints = 1;
            break;
        }
    }
    
    for (i = 0; i < number_of_items; i++)
    {
        if (hints == 1)
        {
            text = wgui_pop_up_description_strings[i].text_strings[0];
            if ((text == NULL) || (*((U8*)(text)) == 0 && *((U8*)(text) + 1) == 0))
            {
                wgui_pop_up_description_strings[i].text_strings[0] = (UI_string_type)default_empty_description;
            }
        }
        else
        {
            wgui_pop_up_description_strings[i].text_strings[0] = (UI_string_type)NULL;
        }
    }
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_set_hint_in_menuitem_flag
 * DESCRIPTION
 *  set hint in menuitem flag 
 * PARAMETERS
 *  number_of_items	  [IN]	 number of items
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_set_hint_in_menuitem_flag(S32 number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	if ((MMI_fixed_icontext_menuitem.ext_flags & UI_MENUITEM_SHOW_ICON_ONLY_ON_HIGHLIGHT)
		|| (MMI_fixed_icontext_menuitem.ext_flags & UI_MENUITEM_SHOW_ALL_HINTS)
		|| (MMI_fixed_icontext_menuitem.ext_flags & UI_MENUITEM_SHOW_HIGHLIGHTED_HINT))
	{
	    return ;
	}
    if (is_set_force_icon_on_highlight_only_in_menuitem())
    {
        wgui_show_icon_only_highlight_in_icontext_menuitem();
    }
    if (is_set_force_all_hints_in_menuitem())
    {
        wgui_enable_hints_in_icontext_menuitem();
    }
    else if (is_set_force_hints_on_highlight_in_menuitem())
    {
        wgui_enable_hint_highlight_in_icontext_menuitem();
    }
    else
    {
        wgui_enable_hint_highlight_in_icontext_menuitem();
    }
    
    set_pop_up_descriptions(1, number_of_items, MMI_fixed_list_menu.highlighted_item);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_set_hint_in_menuitem
 * DESCRIPTION
 *  set hint in menuitem if hint exist
 * PARAMETERS
 *  list_of_descriptions     [IN]        string array of description
 *  number_of_items	  [IN]	 number of items
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_set_hint_in_menuitem(U8 **list_of_descriptions, S32 number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, hints = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (list_of_descriptions != NULL)
    {	
        for (i = 0; i < number_of_items; i++)
        {
            if (wgui_pop_up_description_strings[i].text_strings[0])
            {
                hints = 1;
                break;
            }
        }
        if (hints)
        {
            wgui_cat_set_hint_in_menuitem_flag(number_of_items);
        }
    }
}
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_register_get_flags_callback
 * DESCRIPTION
 *  Register callback function to get flags for initializing list
 * PARAMETERS
 *  wgui_cat_get_list_menu_flags_funcptr_type     [IN]        callback for flags when initializing list
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_register_get_flags_callback(wgui_cat_get_list_menu_flags_funcptr_type get_flags_callback)
{
    wgui_cat_get_list_menu_flags_callback = get_flags_callback;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cat_refresh_asyncdynamic_list
 * DESCRIPTION
 *  Refresh asyncdynamic list
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 *  get_hint_func       [IN]        get hint function callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cat_refresh_asyncdynamic_list(
        S32 number_of_items,
        S32 highlighted_item,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(number_of_items >= 0)
    {
        if(gui_screen_smooth_scrolling_moved_by_pen())
        {
            return;
        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif    
    gdi_layer_lock_frame_buffer();
    
    gui_asyncdynamic_list_error = 0;

    MMI_fixed_list_menu.n_items = number_of_items;

    wgui_title_set_menu_shortcut_number(highlighted_item + 1);
    set_menu_item_count(number_of_items);

    init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    MMI_ASSERT (!gui_asyncdynamic_list_error);

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

	wgui_text_menuitem_reset_scrolling();
	wgui_text_menuitem_restart_scrolling();

    gdi_layer_unlock_frame_buffer();

    RedrawCategoryFunction();
    wgui_cat_show_list_menu_empty_lable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_refresh_asyncdynamic_list_keep_scrolling
 * DESCRIPTION
 *  Refresh asyncdynamic list and keep scrolling the current highlight item in refresh
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 *  get_hint_func       [IN]        get hint function callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cat_refresh_asyncdynamic_list_keep_scrolling(
        S32 number_of_items,
        S32 highlighted_item,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif    
    gdi_layer_lock_frame_buffer();
    
    gui_asyncdynamic_list_error = 0;

    MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_EXT_KEEP_SCROLLING;

    MMI_fixed_list_menu.n_items = number_of_items;

    wgui_title_set_menu_shortcut_number(highlighted_item + 1);
    set_menu_item_count(number_of_items);

    init_asyncdynamic_item_buffer(number_of_items, get_item_func, get_hint_func);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    MMI_ASSERT (!gui_asyncdynamic_list_error);

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

	wgui_text_menuitem_reset_scrolling();

    gdi_layer_unlock_frame_buffer();

    RedrawCategoryFunction();
    wgui_cat_show_list_menu_empty_lable();
    MMI_fixed_icontext_list_menuitem.ext_flags &= ~UI_MENUITEM_EXT_KEEP_SCROLLING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_set_list_menu_empty_lable
 * DESCRIPTION
 *  set string information when list is empty
 * PARAMETERS
 *   lable               : [IN ] (N/A) string pointer to empty string information
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_set_list_menu_empty_lable(UI_string_type lable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_empty_string = lable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_reset_list_menu_empty_lable
 * DESCRIPTION
 *  reset string information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_reset_list_menu_empty_lable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_empty_string = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_is_user_empty_string
 * DESCRIPTION
 *  check if is user passed string or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        [N/A] TRUE when user passed empty string, else return FALSE
 *****************************************************************************/
MMI_BOOL wgui_cat_is_user_empty_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_list_empty_string != NULL)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_disable_list_menu_empty_lable
 * DESCRIPTION
 *  disable list menu empty lable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_disable_list_menu_empty_lable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_show_empty = MMI_FALSE;
    disable_fixed_list_show_empty();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_disable_list_menu_empty_lable
 * DESCRIPTION
 *  enable list menu empty lable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_enable_list_menu_empty_lable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_list_show_empty = MMI_TRUE;
    MMI_list_empty_string = NULL;
    reset_fixed_list_show_empty();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_show_list_menu_empty_lable
 * DESCRIPTION
 *  show list empty string information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_show_list_menu_empty_lable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items > 0 || !MMI_list_show_empty)
    {
        return;
    }

    if(MMI_list_empty_string != NULL)
    {
        disable_fixed_list_show_empty(); 
        
        gdi_layer_set_clip(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1);
        
        gui_set_font((UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST));
        gui_set_text_color(*(current_MMI_theme->list_normal_text_color));
        
        gui_measure_string(MMI_list_empty_string, &str_width, &str_height);
        if(str_width > MMI_fixed_list_menu.width)
        {
            str_width = MMI_fixed_list_menu.width; 
        }
        offset_x = MMI_fixed_list_menu.x + ((MMI_fixed_list_menu.width - str_width) >> 1);
        offset_y = MMI_fixed_list_menu.y + ((MMI_fixed_list_menu.height - str_height) >> 1);
        
        if (mmi_fe_get_r2l_state())
        {
            gui_print_truncated_text(offset_x + str_width, offset_y, str_width, MMI_list_empty_string);
        }
        else
        {
            gui_print_truncated_text(offset_x, offset_y, str_width, MMI_list_empty_string);
        }
    }
}


static U16 two_state_radio_list_history_id = 0;
/*****************************************************************************
 * FUNCTION
 *  wgui_set_twostate_radio_list_history
 * DESCRIPTION
 *  Sets the history data for the two state radio list menu(radio button list)
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [IN]        Buffer from which history data is taken
 * RETURNS
 *  byte              Returns true if the history ID is valid
 *****************************************************************************/
static U8 wgui_set_twostate_radio_list_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	two_state_radio_list_history_id = history_ID;
    if (history_buffer != NULL)
    {
        list_menu_two_state_radio_history *h = (list_menu_two_state_radio_history*) history_buffer;
        
        if (history_valid(h->history_ID, history_ID))
        {
            MMI_fixed_list_menu.highlighted_item = h->highlighted_item;
            MMI_fixed_list_menu.first_displayed_item = h->first_displayed_item;
            MMI_fixed_list_menu.last_displayed_item = h->last_displayed_item;
		#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
            MMI_fixed_list_menu.first_displayed_offset = h->first_displayed_offset;
            MMI_fixed_list_menu.last_displayed_offset = h->last_displayed_offset;
		#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
            MMI_fixed_list_menu.displayed_items = h->displayed_items;
            MMI_fixed_list_menu.flags = h->flags;
            return (1);
        }
    }
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_twostate_radio_list_history
 * DESCRIPTION
 *  Gets the history data for the two state radio list menu(radio button list)
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [OUT]        Buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
static void get_twostate_radio_list_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
        S32 i = 0;
        
        list_menu_two_state_radio_history *h = (list_menu_two_state_radio_history*) history_buffer;
        
        h->history_ID = hID;
        h->highlighted_item = (S16) MMI_fixed_list_menu.highlighted_item;
        h->first_displayed_item = (S16) MMI_fixed_list_menu.first_displayed_item;
        h->last_displayed_item = (S16) MMI_fixed_list_menu.last_displayed_item;
	#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
        h->first_displayed_offset = (S16)MMI_fixed_list_menu.first_displayed_offset;
        h->last_displayed_offset = (S16)MMI_fixed_list_menu.last_displayed_offset;
	#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        h->displayed_items = (S16) MMI_fixed_list_menu.displayed_items;
        h->flags = MMI_fixed_list_menu.flags;
        h->no_of_items = MMI_fixed_list_menu.n_items;
        for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
        {
            if (MMI_fixed_twostate_menuitems[i].flags & UI_MENUITEM_STATE_SELECTED)
            {
                h->selected_item = i;
                break;
            }
        }
    }

}


/*****************************************************************************
* FUNCTION
*  GetCategory140History
* DESCRIPTION
*  Gets the history buffer for Category140 screen
* PARAMETERS
*  history_buffer      [OUT]        History_buffer is a pointer to the buffer where the history data is to be stored      (pre-allocated)
* RETURNS
*  void
*****************************************************************************/
U8 *wgui_get_twostate_radio_list_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(two_state_radio_list_history_id != 0);
    get_twostate_radio_list_history(two_state_radio_list_history_id, history_buffer);
    return (history_buffer);
}   /* end of GetCategory140History */


/*****************************************************************************
* FUNCTION
*  wgui_get_twostate_radio_list_history_size
* DESCRIPTION
*  Gets the history buffer size for two state radio list screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
S32 wgui_get_twostate_radio_list_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_two_state_radio_history));
}   /* end of wgui_get_twostate_radio_list_history_size */


/*****************************************************************************
*               Category85 start
*****************************************************************************/
static U8 wgui_cat85_disable_arrowkey = WGUI_CAT85_DISABLE_NONE;
static wgui_cat85_get_image_buf_function g_wgui_cat85_get_image_buf = NULL;

/*****************************************************************************
 * FUNCTION
 *  cat85_clear_icon_bg
 * DESCRIPTION
 *  Clear button background function
 * PARAMETERS
 *  button      [IN]        Button pointer
 * RETURNS
 *  void
 *****************************************************************************/
void cat85_clear_icon_bg(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(b->x, b->y, b->x + b->width, b->y + b->height);
    gdi_draw_solid_rect(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1, GDI_COLOR_TRANSPARENT);    /* 061705 Calvin added */
    if (title_bg_id != 0)
    {
        gdi_image_draw_id(MMI_title_x, MMI_title_y, title_bg_id);
    }
    else
    {
        gui_draw_filled_area(
            MMI_title_x,
            MMI_title_y,
            MMI_title_x + MMI_title_width - 1,
            MMI_title_y + MMI_title_height - 1,
            current_UI_theme->window_title_theme->active_filler);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory85Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory85Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title_bg_id = 0;
    g_wgui_cat85_get_image_buf = NULL;
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
}

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_FTE_SUPPORT__)
FuncPtr gCat_touch_title_button1_up_handler;
FuncPtr gCat_touch_title_button2_up_handler;
/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_touch_title_button1_up_handler
 * DESCRIPTION
 *  category85 touch title button1 up handler
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_touch_title_button1_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if (wgui_cat85_disable_arrowkey != WGUI_CAT85_DISABLE_LAR)
    {
        if (gCat_touch_title_button1_up_handler)
        {
            gCat_touch_title_button1_up_handler();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_touch_title_button2_up_handler
 * DESCRIPTION
 *  category85 touch title button2 up handler
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_touch_title_button2_up_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if (wgui_cat85_disable_arrowkey != WGUI_CAT85_DISABLE_RAR)
    {
        if (gCat_touch_title_button2_up_handler)
        {
            gCat_touch_title_button2_up_handler();
        }
    }
}
#endif /* __MMI_TOUCH_SCREEN__ && !__MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_set_disable_arrowkey
 * DESCRIPTION
 *  category85 set left/right arrow key disable
 * PARAMETERS
 *  disable                   [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat85_set_disable_arrowkey(U8 disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    wgui_cat85_disable_arrowkey = disable;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_disable_lar_button
 * DESCRIPTION
 *  category85 set arrow left arrow key disable
 * PARAMETERS
 *  void                     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_disable_lar_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *bt_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    bt_info = dm_get_button(0);
    bt_info->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
    bt_info->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
#if defined(__MMI_FTE_SUPPORT__)
    bt_info->flags |= UI_BUTTON_STATE_DISABLED;
#endif /* __MMI_FTE_SUPPORT__ */
    gui_icontext_button_set_icon(bt_info, get_image(LEFT_RED_ARROW), gui_transparent_color(0, 0, 0));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_disable_rar_button
 * DESCRIPTION
 *  category85 set arrow right arrow key disable
 * PARAMETERS
 *  void                     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_disable_rar_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *bt_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    bt_info = dm_get_button(1);
    bt_info->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
    bt_info->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
#if defined(__MMI_FTE_SUPPORT__)
    bt_info->flags |= UI_BUTTON_STATE_DISABLED;
#endif /* __MMI_FTE_SUPPORT__ */
    gui_icontext_button_set_icon(bt_info, get_image(RIGHT_RED_ARROW), gui_transparent_color(0, 0, 0));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_add_button
 * DESCRIPTION
 *  category85 add button in title
 * PARAMETERS
 *  up_id                   [IN]       button image id  for up status
 *  down_id			[IN]		button image id for down status
 *  func_handler              [IN]          button click handler function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_add_button(U16 up_id, U16 down_id, FuncPtr func_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img_up, img_down;
    U16 btn_item_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    img_up = (PU8) get_image(up_id);
    img_down = (PU8) get_image(down_id);

#if !defined(__MMI_TOUCH_SCREEN__)
    btn_item_id = dm_add_button(NULL, img_up, img_down, cat85_clear_icon_bg);
#else /* __MMI_TOUCH_SCREEN__ */
    btn_item_id = dm_add_button(NULL, img_up, img_down, cat85_clear_icon_bg);
    dm_register_button_functions(btn_item_id, KEY_EVENT_UP, func_handler);
#endif /* __MMI_TOUCH_SCREEN__ */
#if !defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_FTE_SUPPORT_SLIM__)
    dm_get_button(btn_item_id)->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
    dm_get_button(btn_item_id)->flags |= UI_BUTTON_NO_SHIFT_BUTTON;
#endif /* __MMI_SLIM_IMG_RES__ || __MMI_FTE_SUPPORT_SLIM__ */
}
// *************************************************************************************//

/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_register_get_image_buf_callback_func
 * DESCRIPTION
 *  register get image buffer pointer callback function for category85
 * PARAMETERS
 *  func        [IN]        callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat85_register_get_image_buf_callback_func(wgui_cat85_get_image_buf_function func)
{
    g_wgui_cat85_get_image_buf = func;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat85_post_display_menuitem
 * DESCRIPTION
 *  post display menuitem callback function of category85
 * PARAMETERS
 *  item                        [IN]       menuitem pointer
 *  common_item_data			[IN]	   menuitem data pointer
 *  x                           [IN]       x coordinate of menuitem
 *  y                           [IN]       y coordinate of menuitem
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat85_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;
    S32 x2, y2;
    S32 img_area_width, img_area_height;
    S32 img_width, img_height;
    S32 resized_img_width, resized_img_height;
    MMI_BOOL alpha = MMI_FALSE;
    U8 *img_buf = NULL;
    U8 img_type;
    S32 img_size = 0;
    S32 item_index;
    MMI_BOOL ret = MMI_FALSE;
    S32 gdi_ret;
    S32 img_x = 0, img_y = 0;
    S32 resized_offset_x, resized_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }

    if(g_wgui_cat85_get_image_buf)
    {
        ret = g_wgui_cat85_get_image_buf(item_index, &img_buf, &img_type, &img_size);
    }
    if(ret == MMI_FALSE)
    {
        return;
    }
    gdi_ret = gdi_image_get_dimension_mem(img_type, img_buf, img_size, &img_width, &img_height);
    if( (gdi_ret < 0) || (img_width <= 0) || (img_height <= 0))
    {
        return;
    }
    img_area_width = MMI_fixed_icontext_list_menuitem.icon_coordinates[1].width;
    img_area_height = MMI_fixed_icontext_list_menuitem.icon_coordinates[1].height;
    if( (img_width <= img_area_width) && (img_height <= img_area_height) )
    {
        resized_offset_x = (img_area_width - img_width)>>1;
        resized_offset_y = (img_area_height - img_height)>>1;
        resized_img_width = img_width;
        resized_img_height = img_height;
    }
    else if ((img_width > img_area_width) || (img_height > img_area_height))
    {
        gdi_util_fit_box(
            GDI_UTIL_MODE_SHORT_SIDE_FIT,
            img_area_width,
            img_area_height,
            img_width,
            img_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_img_width,
            &resized_img_height); 
    }
    
    x2 = x + MMI_fixed_icontext_list_menuitem.icon_coordinates[1].x + img_area_width - 1;
    y2 = y + MMI_fixed_icontext_list_menuitem.icon_coordinates[1].y + img_area_height - 1;
    /*this is used to set clip area*/
    if(y2 > MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1)
    {
        y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
    }

    gui_push_clip();
    gui_set_clip(
       x + MMI_fixed_icontext_list_menuitem.icon_coordinates[1].x,
       y + MMI_fixed_icontext_list_menuitem.icon_coordinates[1].y,
       x2,
       y2);

    gdi_layer_get_active(&act_lcd);
    if(MMI_fixed_list_menu.highlighted_item == item_index)
    {
        alpha = MMI_TRUE;
        gdi_push_and_set_alpha_blending_source_layer(act_lcd);
    }
    img_x = MMI_fixed_icontext_list_menuitem.icon_coordinates[1].x + resized_offset_x;
    img_y = MMI_fixed_icontext_list_menuitem.icon_coordinates[1].y + resized_offset_y;

    gdi_image_draw_resized_mem(x + img_x, y + img_y, resized_img_width, resized_img_height, img_buf, img_type, img_size);
    if(alpha)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    gui_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory85Screen_int
 * DESCRIPTION
 *  category screen of integrated calendar (daily)
 * PARAMETERS
 *  title                   [IN]         
 *  title_icon              [IN]          
 *  left_softkey            [IN]        
 *  right_softkey           [IN]        
 *  number_of_items         [IN]        
 *  get_item_func           [IN]        
 *  get_hint_func           [IN]  
 *  highlighted_item        [IN]        
 *  left_icon               [IN]
 *  right_icon_1            [IN]
 *  right_icon_2            [IN]       
 *  history_buffer          [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory85Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U16 left_icon,
        U16 right_icon_1,
        U16 right_icon_2,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_icon_w = 0, left_icon_h = 0, left_icon_y;
    S32 right_icon_1_w = 0, right_icon_1_h = 0, right_icon_2_w = 0, right_icon_2_h = 0;
    S32 text_0_h = 0, text_width = 0;
    U16 catId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset The Error Variable */
    gui_asyncdynamic_list_error = 0;
    /* Set The Application Side Variable To True */
    
    gdi_layer_lock_frame_buffer();
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    MMI_title_string = (UI_string_type) title;
    if (wgui_is_touch_title_bar_buttons())
    {
        catId = MMI_CATEGORY85_ID;
        MMI_title_icon = NULL;
#if defined(__MMI_TOUCH_SCREEN__)
#if !defined(__MMI_FTE_SUPPORT__)
    gCat_touch_title_button1_up_handler = gMMI_touch_title_button1_up_handler;
	gCat_touch_title_button2_up_handler = gMMI_touch_title_button2_up_handler;
	gMMI_touch_title_button1_up_handler = wgui_cat85_touch_title_button1_up_handler;
	gMMI_touch_title_button2_up_handler = wgui_cat85_touch_title_button2_up_handler;
#endif /* __MMI_FTE_SUPPORT__ */
    #if defined(__MMI_SLIM_IMG_RES__)
        wgui_cat85_add_button(LEFT_RED_ARROW, LEFT_RED_ARROW, gMMI_touch_title_button1_up_handler);
        wgui_cat85_add_button(RIGHT_RED_ARROW, RIGHT_RED_ARROW, gMMI_touch_title_button2_up_handler);
    #else /* __MMI_SLIM_IMG_RES__ */
        wgui_cat85_add_button(LEFT_RED_ARROW_NORMAL, LEFT_RED_ARROW_PRESSED, gMMI_touch_title_button1_up_handler);
        wgui_cat85_add_button(RIGHT_RED_ARROW_NORMAL, RIGHT_RED_ARROW_PRESSED, gMMI_touch_title_button2_up_handler);
    #endif /* __MMI_SLIM_IMG_RES__ */
#else /* __MMI_TOUCH_SCREEN__ */
    #if defined(__MMI_SLIM_IMG_RES__)
        wgui_cat85_add_button(LEFT_RED_ARROW, LEFT_RED_ARROW, NULL);
        wgui_cat85_add_button(RIGHT_RED_ARROW, RIGHT_RED_ARROW, NULL);
    #else /* __MMI_SLIM_IMG_RES__ */
        wgui_cat85_add_button(LEFT_RED_ARROW_NORMAL, LEFT_RED_ARROW_PRESSED, NULL);
        wgui_cat85_add_button(RIGHT_RED_ARROW_NORMAL, RIGHT_RED_ARROW_PRESSED, NULL);
    #endif /* __MMI_SLIM_IMG_RES__ */
#endif /* __MMI_TOUCH_SCREEN__ */
    #if defined(__MMI_FTE_SUPPORT__)
        title_bg_id = 0;	/* for showing different title bar. */
    #else
        title_bg_id = IMAGE_VIEW_TITLEBAR_BG;
    #endif /* __MMI_FTE_SUPPORT_SLIM__ || __MMI_SLIM_IMG_RES__ */
        if (wgui_cat85_disable_arrowkey == WGUI_CAT85_DISABLE_LAR)
        {
            wgui_cat85_disable_lar_button();
        }
        else if (wgui_cat85_disable_arrowkey == WGUI_CAT85_DISABLE_RAR)
        {
            wgui_cat85_disable_rar_button();
        }
    }
    else
    {
        catId = MMI_CATEGORY85_NO_BUTTON_ID;
        MMI_title_icon = (PU8) get_image(title_icon);
    }

#if(defined __MMI_MAINLCD_480X800__ || defined __MMI_MAINLCD_320X480__ || defined __MMI_MAINLCD_360X640__)
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        3,
        get_item_func,
        get_hint_func,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        catId,
        history_buffer);
#else
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        3,
        get_item_func,
        get_hint_func,
        highlighted_item,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        catId,
        history_buffer);
#endif/*defined __MMI_MAINLCD_480X800__ || defined __MMI_MAINLCD_320X480__ || defined __MMI_MAINLCD_360X640__*/
    if(g_wgui_cat85_get_image_buf)
    {
        set_fixed_icontext_list_menuitems_post_display(wgui_cat85_post_display_menuitem);
    }
    
    if (wgui_is_touch_title_bar_buttons())
	{
	    wgui_title_set_no_icon_shct(MMI_FALSE);
	}
    gui_measure_image(get_image(left_icon), &left_icon_w, &left_icon_h);
    gui_measure_image(get_image(right_icon_2), &right_icon_2_w, &right_icon_2_h);
    gui_measure_image(get_image(right_icon_1), &right_icon_1_w, &right_icon_1_h);
    if(left_icon_w == 0)
    {
        left_icon_w = MMI_MENUITEM_HEIGHT - CAT85_MENUITEM_OFFSET*2;
    }
    if(left_icon_h == 0)
    {
        left_icon_h = MMI_MENUITEM_HEIGHT - CAT85_MENUITEM_OFFSET*2;
    }
    text_width = MMI_content_width - MMI_fixed_list_menu.vbar.width - CAT85_MENUITEM_OFFSET*3 - 3 - left_icon_w - right_icon_1_w - right_icon_2_w;  
    text_0_h = Get_CharHeightOfAllLang((current_UI_theme->fixed_icontext_list_menuitem_theme)->text_fonts[0]->size);

    left_icon_y = (MMI_fixed_icontext_list_menuitem.height - left_icon_h)>>1;
    set_fixed_icontext_list_text_coordinates(0, CAT85_MENUITEM_OFFSET*2 + left_icon_w, CAT85_TEXT_Y, text_width, text_0_h);
    set_fixed_icontext_list_text_coordinates(1, CAT85_MENUITEM_OFFSET*2 + left_icon_w, CAT85_TEXT_Y+text_0_h, text_width, MMI_fixed_icontext_list_menuitem.height-text_0_h);
    set_fixed_icontext_list_icon_coordinates(0, CAT85_MENUITEM_OFFSET*3 + left_icon_w + text_width, CAT85_RIGHT_ICON_Y, right_icon_1_w, right_icon_1_h);
    set_fixed_icontext_list_icon_coordinates(1, CAT85_MENUITEM_OFFSET, left_icon_y, left_icon_w, left_icon_h);
    set_fixed_icontext_list_icon_coordinates(2, CAT85_MENUITEM_OFFSET*3 + left_icon_w + text_width + right_icon_1_w, CAT85_RIGHT_ICON_Y, right_icon_2_w, right_icon_2_h);

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;  /* 111306 scrolling */
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height);
    gdi_layer_unlock_frame_buffer();
	if (gui_asyncdynamic_list_error)
    {
        return;
    }
	wgui_cat_setup_category_default_history((S32)catId, 0, ExitCategory85Screen);
    dm_redraw_category_screen();
}


/*****************************************************************************
* Category 384
* Dynamic icon-text list with check-box
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  DrawCate384CategoryControlArea
 * DESCRIPTION
 *  draw the information message for category 384
 * PARAMETERS
 *  coordinate      [IN] Coordinated of the control area     
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate384CategoryControlAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y11, y22;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y11 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT;
    y22 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - 1;

    gui_push_clip();
    gui_reset_clip();
    gui_set_clip(x1, y11, x2, y22);

#ifdef __MMI_MAINLCD_128X128__
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_WHITE);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */
	gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory384Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [IN] Char array of title
 *  title_icon              [IN] Byte array of title icon
 *  left_softkey            [IN] String ID of left softkey
 *  left_softkey_icon       [IN] Image ID of left softkey icon
 *  right_softkey           [IN] String ID of right softkey
 *  right_softkey_icon      [IN] Image ID of right softkey icon
 *  info_message            [IN] Char array of information message
 *  number_of_items         [IN] Number of items of list
 *  get_item_func           [IN] Get item function pointer
 *  get_hint_func           [IN] Get hint function pointer
 *  get_state_func          [IN] Get state of check-box function pointer
 *  set_state_func          [IN] Set state of check-box function pointer
 *  highlighted_item        [IN] Currently highlighted item
 *  history_buffer          [IN] History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory384Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8* info_message,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;    
    S32 scroll_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	dm_add_title(title, title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    gui_setup_submenu_layout();   

    /* initialize list */
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

    h_flag = set_list_menu_category_history(MMI_CATEGORY384_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

#if defined(__MMI_MAINLCD_128X64__)
    wgui_title_set_no_icon_shct(MMI_FALSE);
#endif /* __MMI_MAINLCD_128X64__ */
    
    /* adjust list */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_positions(
		GUI_ICONTEXT_MENUITEM_TEXT_X + MMI_ICONTEXT_MENUITEM_HEIGHT, 0, 
		GUI_ICONTEXT_MENUITEM_ICON_X + MMI_ICONTEXT_MENUITEM_HEIGHT, 0);

    /* set check-box */
    wgui_menuitem_set_icontext_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_checkbox_callback(set_state_func, get_state_func);


    /* set the layout of the list */
    if (info_message != NULL)
    {
		gui_set_font(&MMI_medium_font);
        dm_add_scroll_text(
            (UI_string_type)info_message, 
            NULL, 
            DrawCate384CategoryControlAreaBackground,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
		    *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
		    );
        scroll_height = MMI_MENUITEM_HEIGHT;
    }

    wgui_dynamic_list_move_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_dynamic_list_resize_icontext_menu(MMI_content_width, MMI_content_height - scroll_height);

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY384_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory384Screen);
    /* redraw category screen */
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory384Screen
 * DESCRIPTION
 *  exit category 384
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory384Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategory184Screen();
}

#ifdef __MMI_CAT265_SUPPORT__
/*-------------------------------
Global variables
-------------------------------*/
static wgui_matv_context_struct *wgui_matv_cntx = NULL;
static U16 mmi_cat1007_screen = 0;

static gdi_handle matv_preview_handle = 0;

typedef struct{
    S32 x;
    S32 y;
    S32 width;
    S32 height;
}matv_rect;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/*----------------------------Async Dynamic Multi Row List-----------------------------*/
// *************************************************************************************//

#if defined(__MMI_MAINLCD_320X240__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__))
extern UI_filled_area* dm_get_current_scr_bg_filler(void);
static GDI_HANDLE g_matv_listmenu_layer = GDI_NULL_HANDLE;
/*****************************************************************************
 * FUNCTION
 *  wgui_matv_draw_background
 * DESCRIPTION
 *  This function is used to draw the background of the calling image in matv for scanline
 * PARAMETERS
 *  x1	[IN]
 *  y1	[IN]
 *  x2	[IN]
 *  y2	[IN]
 *  flag	[IN]		whether set clip region
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_matv_draw_background(S32 x1, S32 y1, S32 x2, S32 y2, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == MMI_TRUE)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, gdi_layer_get_background());
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, dm_get_current_scr_bg_filler());
        gdi_layer_pop_clip();
    }
    else
    {
        gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, gdi_layer_get_background());
        gui_draw_filled_area(0, 0, UI_device_width - 1, UI_device_height - 1, dm_get_current_scr_bg_filler());
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_draw_listmenu_background
 * DESCRIPTION
 *  draw list menu background for matv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_matv_draw_listmenu_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 y1 = CAT265_LIST_Y, y2 = UI_device_height - 1 - CAT265_LIST_Y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_multi_layer_enable();
	wgui_set_wallpaper_on_bottom(MMI_TRUE);
    
    /* create layer */
    dm_create_layer(0, CAT265_LIST_Y, UI_device_width, UI_device_height/2, &g_matv_listmenu_layer, DM_LAYER_BOTTOM);
    MMI_ASSERT(g_matv_listmenu_layer);
    
    /* draw layer */
    gdi_set_alpha_blending_source_layer(g_matv_listmenu_layer);
    gdi_layer_push_and_set_active(g_matv_listmenu_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_draw_solid_rect(0, -y1, UI_device_width - 1, y2, gdi_layer_get_background());
	gui_draw_filled_area(0, -y1, UI_device_width - 1, y2, dm_get_current_scr_bg_filler());
    gdi_layer_pop_and_restore_active();	
}


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_hide_status_icons_bar0
 * DESCRIPTION
 *  hide function of stats icon horizontal bar of matv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_matv_hide_status_icons_bar0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
	wgui_matv_draw_background(x1, y1, x2, y2, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_draw_time_background
 * DESCRIPTION
 *  draw time background at control area for matv
 * PARAMETERS
 *  x                   [IN]        x of the top-left of the title
 *  y            [IN]        y of the top-left of the title
 *  clip_x1       [IN]        x1 of the clip area
 *  clip_y1           [IN]        y1 of the clip area
 *  clip_x2      [IN]        x2 of the clip area
 *  clip_y2          [IN]        y2 of the clip area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_matv_draw_time_background(
                    S32 x, 
                    S32 y, 
                    S32 clip_x1, 
                    S32 clip_y1, 
                    S32 clip_x2, 
                    S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_matv_draw_background(clip_x1, clip_y1, clip_x2, clip_y2, MMI_TRUE);
}
#endif /* __MMI_MAINLCD_320X240__ && __LCM_SCANLINE_ROTATION_SUPPORT__ */


static void wgui_matv_init_cntx(
                wgui_menuitem_callback pre_highlight_callback,
                LayerRedrawCallback redraw_callback,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                FuncPtr preview_name_time,
                FuncPtr post_display,
                S32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_matv_cntx = (wgui_matv_context_struct*)mmi_frm_scrmem_alloc_framebuffer(sizeof(wgui_matv_context_struct));
    MMI_ASSERT(wgui_matv_cntx);
    memset(wgui_matv_cntx, 0, sizeof(wgui_matv_context_struct));
    wgui_matv_cntx->preview_buf = (U8*)mmi_frm_scrmem_alloc_framebuffer(sizeof(U8)*mem_size);
    MMI_ASSERT(wgui_matv_cntx->preview_buf);
    memset(wgui_matv_cntx->preview_buf, 0, sizeof(U8)*mem_size);
    
    wgui_matv_cntx->pre_highlight_callback = pre_highlight_callback;
    wgui_matv_cntx->redraw_preview_area = redraw_callback;
    wgui_matv_cntx->get_item = get_item_func;
    wgui_matv_cntx->get_hint = get_hint_func;
	wgui_matv_cntx->preview_name_time = preview_name_time;
	wgui_matv_cntx->post_display = post_display;
}


static void wgui_matv_free_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_matv_cntx != NULL)
    {
        if(wgui_matv_cntx->preview_buf != NULL)
        {
			if ((wgui_matv_cntx->preview_handle)
				&& (*wgui_matv_cntx->preview_handle != GDI_ERROR_HANDLE))
			{
			    gdi_layer_flatten_previous_to_base();
			    gdi_layer_free(*wgui_matv_cntx->preview_handle);
				*wgui_matv_cntx->preview_handle = GDI_ERROR_HANDLE;
				wgui_matv_cntx->preview_handle = NULL;
			}
            mmi_frm_scrmem_free(wgui_matv_cntx->preview_buf);
            wgui_matv_cntx->preview_buf = NULL;
        }
        mmi_frm_scrmem_free(wgui_matv_cntx);
        wgui_matv_cntx = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_matv_scrolling_background
 * DESCRIPTION
 *  draw background callback function of scrolling text of matv
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_matv_scrolling_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
#if defined(__MMI_MAINLCD_320X240__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__))
    if (MMI_fixed_list_menu.n_items > 0)
    {
        wgui_matv_draw_background(x1, y1, x2, y2, MMI_TRUE);
    }
#endif /* __MMI_MAINLCD_320X240__ && __LCM_SCANLINE_ROTATION_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_scrolling_timer
 * DESCRIPTION
 *  timer callback of category265scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer(?)
 *****************************************************************************/
static void wgui_matv_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_matv_cntx->preview_name_scrolling_text);
}


static void wgui_matv_create_preview_name(matv_rect *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_TITLE));
	gui_scrolling_text_stop(&wgui_matv_cntx->preview_name_scrolling_text);
    gui_create_scrolling_text(
        &wgui_matv_cntx->preview_name_scrolling_text,
        pos->x, pos->y, pos->width, pos->height,
        (UI_string_type) wgui_matv_cntx->preview_name,
        wgui_matv_scrolling_timer,
        wgui_matv_scrolling_background,
        *current_MMI_theme->list_normal_text_color,
        *current_MMI_theme->list_normal_text_color);
}


static void wgui_matv_create_preview_time(matv_rect *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_handle;
    gdi_handle lcd_handle;
    gui_util_painter_struct bg_painter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scrolling name */
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_TITLE));
    gdi_layer_get_active(&layer_handle);
    gdi_lcd_get_active(&lcd_handle);
#if defined(__MMI_MAINLCD_320X240__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__))
    if (MMI_fixed_list_menu.n_items > 0)
    {
        gui_util_painter_create_callback(&bg_painter, wgui_matv_draw_time_background);
    }
	else
	{
	    gui_util_painter_create_transparent(&bg_painter);
	}
#else
    gui_util_painter_create_transparent(&bg_painter);
#endif
	wgui_text_label_close(wgui_matv_cntx->text_label_id);
    wgui_text_label_create(wgui_matv_cntx->text_label_id,
        pos->x,
        pos->y + 10 /* TBD */,
        pos->width,
        pos->height,
        wgui_matv_cntx->preview_time,
        &MMI_small_font,
        *current_MMI_theme->list_normal_text_color,
        MMI_FALSE,
        *current_MMI_theme->list_normal_text_color,
        bg_painter,
        GUI_TEXT_LABEL_H_ALIGN_LEFT,
        GUI_TEXT_LABEL_V_ALIGN_TOP,
        layer_handle,
        lcd_handle);
}


#define wgui_matv_stop_preview_name()	\
	do{		\
		gui_scrolling_text_stop(&wgui_matv_cntx->preview_name_scrolling_text);	\
		}while(0)
		

#define wgui_matv_stop_preview_time()	\
	do{		\
		wgui_text_label_close(wgui_matv_cntx->text_label_id);	\
		}while(0)


#define wgui_matv_redraw_preview_area(x, y, w, h)	\
	do{		\
		if(wgui_matv_cntx->redraw_preview_area && wgui_matv_cntx->preview_handle)	\
			wgui_matv_cntx->redraw_preview_area(	\
			                    *wgui_matv_cntx->preview_handle,	\
			                    wgui_matv_cntx->blt_layer_flag,		\
			                    wgui_matv_cntx->preview_layer_flag, 	\
			                    (x), (y), (w), (h));	\
		}while(0)


#define wgui_matv_init_asyncdynamic_item_buffer(n_items)	\
	do{		\
		init_asyncdynamic_item_buffer((n_items), wgui_matv_cntx->get_item, wgui_matv_cntx->get_hint);	\
		}while(0)

	
#define wgui_matv_get_preview_time()	(wgui_matv_cntx->preview_time)


static void wgui_matv_draw_control_area(dm_coordinates *coordinate, matv_rect *mem_pos, S32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = coordinate->s16X;
    S32 y = coordinate->s16Y;
    S32 width = coordinate->s16Width;
    S32 height = coordinate->s16Height;
    GDI_RESULT ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x, y, x+width-1, y+height-1, GDI_COLOR_TRANSPARENT);

    if(MMI_fixed_list_menu.n_items > 0)
    {
#if defined(__MMI_MAINLCD_320X240__) && defined(__LCM_SCANLINE_ROTATION_SUPPORT__) && (!defined(__MMI_FTE_SUPPORT__))
        wgui_matv_draw_background(x, y, x + width - 1, y + height - 1, MMI_TRUE);
#endif /* __MMI_MAINLCD_320X240__ && __LCM_SCANLINE_ROTATION_SUPPORT__ */
        /* preview area */
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) || !defined(__MMI_ATV_SUPPORT__)
		ret = gdi_layer_create_using_outside_memory(
				mem_pos->x,
				mem_pos->y,
				mem_pos->width,
				mem_pos->height,
				&matv_preview_handle,
				wgui_matv_cntx->preview_buf,
				mem_size);
#else /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
	    ret = gdi_layer_create_double_using_outside_memory(
	    		mem_pos->x,
	            mem_pos->y,
	            mem_pos->width,
	            mem_pos->height,
	            &matv_preview_handle,
	            wgui_matv_cntx->preview_buf,
	            /*CAT265_PREVIEW_AREA_SIZE*/mem_size);
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
		MMI_ASSERT(ret >= 0);

		/* init layer */
		gdi_layer_push_and_set_active(matv_preview_handle);
		gdi_layer_clear(GDI_COLOR_BLACK);
		gdi_layer_pop_and_restore_active();

        gdi_layer_set_blt_layer(dm_get_layer_handle(0), dm_get_layer_handle(1), matv_preview_handle, 0);
        wgui_matv_cntx->preview_handle = dm_get_layer_handle_ptr(2);
		*wgui_matv_cntx->preview_handle = matv_preview_handle;
        wgui_matv_cntx->blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        wgui_matv_cntx->preview_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
    }
}



static void wgui_matv_menu_post_display(matv_rect *prev_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Process after we change the highlight, ex. redraw preview */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if (gui_screen_smooth_scrolling_by_pen() != MMI_TRUE)
#endif
    {
        wgui_matv_redraw_preview_area(prev_pos->x, prev_pos->y, prev_pos->width, prev_pos->height);
        wgui_fixed_list_register_display_callback(NULL);
    }
}


static void wgui_matv_show_control_area_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_scrolling_text(&wgui_matv_cntx->preview_name_scrolling_text);
    if (wgui_matv_cntx->preview_time != NULL)	
    {
        wgui_text_label_show(wgui_matv_cntx->text_label_id);
    }
}


static void wgui_matv_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Support menu shortcut */
    wgui_title_set_menu_shortcut_number(item_index + 1);
    /* Process before we change the highlight, ex. stop preview */
    if(wgui_matv_cntx->pre_highlight_callback)
    {
        wgui_matv_cntx->pre_highlight_callback(item_index, MMI_FALSE);
    }

    /* Process the highlight */
    MMI_highlighted_item_text = get_asyncdynamic_item_text(item_index);
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 

    /* update title scrolling text */
	wgui_matv_cntx->preview_name_time();
	wgui_matv_show_control_area_content();
	wgui_fixed_list_register_display_callback(wgui_matv_cntx->post_display);
}


#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
/*****************************************************************************
 * FUNCTION
 *  wgui_matv_preview_stop_handler
 * DESCRIPTION
 *  stop preview
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_matv_preview_stop_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	/* Process before we change the highlight, ex. stop preview */
    if(wgui_matv_cntx->pre_highlight_callback)
    {
        if (gui_screen_smooth_scrolling_by_pen() == MMI_TRUE)
        {
            /* assume -1 as invalid index
                in order to make applicatin to react accordingly*/
            wgui_matv_cntx->pre_highlight_callback(-1, MMI_TRUE);
        }
    }
}
#endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) */


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_set_preview_name_ext
 * DESCRIPTION
 *  set the preview name string for displaying
 * PARAMETERS
 *  name      [IN]        preview string
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_matv_set_preview_name_ext(U8 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_cat1007_screen == 0)
    {
		wgui_matv_cntx->preview_name = name;
        /* update scrolling text */
		wgui_matv_cntx->preview_name_time();
		gui_show_scrolling_text(&wgui_matv_cntx->preview_name_scrolling_text);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_matv_set_preview_name_time
 * DESCRIPTION
 *  set the preview name string for displaying
 * PARAMETERS
 *  name      [IN]        preview name string
 *  time      [IN]        preview time string
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_matv_set_preview_name_time(U8 *name, U8 *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_cat1007_screen == 0)
    {
		wgui_matv_cntx->preview_name = name;
		wgui_matv_cntx->preview_time = time;
    
        /* update scrolling text */
		wgui_matv_cntx->preview_name_time();
		gui_show_scrolling_text(&wgui_matv_cntx->preview_name_scrolling_text);
		
		if (wgui_matv_cntx->preview_time != NULL)	
		{
			wgui_text_label_show(wgui_matv_cntx->text_label_id);
		}
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_create_preview_name_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat265_create_preview_name_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    matv_rect pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pos.x = CAT265_NAME_X;
	pos.width = CAT265_NAME_WIDTH;
	pos.height = CAT265_NAME_HEIGHT;
	if (wgui_matv_get_preview_time() == NULL)
	{
		pos.y = CAT265_NAME_Y;
	}
	else
	{
		pos.y = CAT265_PREVIEW_STR_1_Y;
	}
	wgui_matv_create_preview_name(&pos);

    if (wgui_matv_get_preview_time() != NULL)
    {
		pos.y = CAT265_PREVIEW_STR_2_Y;
		wgui_matv_create_preview_time(&pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_menu_post_display
 * DESCRIPTION
 *  post menu to display
 * PARAMETERS
 *  void
 * RETURNS   void
 *****************************************************************************/
static void wgui_cat265_menu_post_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    matv_rect p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p.x = CAT265_PREVIEW_X;
    p.y = CAT265_PREVIEW_Y;
    p.width = CAT265_PREVIEW_WIDTH;
    p.height = CAT265_PREVIEW_HEIGHT;

    wgui_matv_menu_post_display(&p);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_draw_control_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category265 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat265_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    matv_rect p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p.x = CAT265_PREVIEW_X;
    p.y = CAT265_PREVIEW_Y;
    p.width = CAT265_PREVIEW_WIDTH;
    p.height = CAT265_PREVIEW_HEIGHT;

    wgui_matv_draw_control_area(coordinate, &p, CAT265_PREVIEW_AREA_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory265Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory265Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    wgui_matv_stop_preview_name();
    //TBD
    wgui_matv_stop_preview_time();

	wgui_matv_free_cntx();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */   
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory265Screen
 * DESCRIPTION
 *  category screen of channel list with video preview
 * PARAMETERS
 *  title                   [IN]    initial title string pointer         
 *  title_icon              [IN]    title icon
 *  left_softkey            [IN]    left softkey string id
 *  left_softkey_icon       [IN]    left softkey icon id    
 *  right_softkey           [IN]    right softkey string id
 *  right_softkey_icon      [IN]    right softkey icon id    
 *  double_line_list_flag   [IN]    flog to indicate list item in two lines    
 *  number_of_items         [IN]    total number of menu items    
 *  get_item_func           [IN]    callback to prepare menuitem data
 *  get_hint_func           [IN]    callback to prepare hint data
 *  pre_highlight_callback  [IN]    callback before highlight is changed. In preview view case, the callback is to stop video playing.
 *  redraw_callback         [IN]    callback after highlight is changed. In preview view case, the callback is to start video playing.
 *  highlighted_item        [IN]    default highlighted item
 *  history_buffer          [IN]    history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory265Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        MMI_BOOL double_line_list_flag,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        wgui_menuitem_callback pre_highlight_callback,
        LayerRedrawCallback redraw_callback,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    U8 h_flag;
    S32 number_of_text;
    S32 menuitem_height;
    U32 flag;
    S32 row_start_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
	
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();

    dm_add_title(title, title_icon);

    gui_asyncdynamic_list_error = 0;
    wgui_title_set_menu_shortcut_number(-1);
	wgui_matv_init_cntx(
		pre_highlight_callback,
		NULL,
		get_item_func,
		get_hint_func,
		wgui_cat265_create_preview_name_time,
		wgui_cat265_menu_post_display,
		CAT265_PREVIEW_AREA_SIZE);

	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    flag = (UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y);
    if (double_line_list_flag == MMI_TRUE)
    {
        menuitem_height = MMI_MENUITEM_MULTIROW_HEIGHT;
        flag |= WGUI_LIST_MENU_MULTIROW;
        number_of_text = 3;
        row_start_y = 2;
    }
    else
    {
        menuitem_height = MMI_MENUITEM_HEIGHT;
        number_of_text = 2;
        row_start_y = 0;
    }

    if(!(wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            number_of_text,
            1,
            get_item_func,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            menuitem_height,
            flag,
            MMI_CATEGORY265_ID,
            history_buffer)))
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }
        
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    h_flag = set_list_menu_category_history(MMI_CATEGORY265_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    /* Enable menu shortcut */
    wgui_title_set_menu_shortcut_number(MMI_fixed_list_menu.highlighted_item + 1);
    /* Disable menu shortcut to be displayed */
    wgui_title_set_no_icon_shct(MMI_FALSE);

    if (MMI_TRUE == double_line_list_flag)
    {
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;

        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_AUTO_CHOOSE_MARQUEE);

        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_ICON_X);
    }

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT;

    set_fixed_icontext_list_text_coordinates(0, CAT265_TEXT_0_X+CAT265_TEXT_0_OFFSET, row_start_y, CAT265_TEXT_0_WIDTH-(CAT265_TEXT_0_OFFSET*2), get_menu_item_height());
    set_fixed_icontext_list_icon_coordinates(0, CAT265_ICON_X+CAT265_ICON_OFFSET, row_start_y, CAT265_ICON_WIDTH-(CAT265_ICON_OFFSET*2), get_menu_item_height());
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT265_TEXT_0_WIDTH - CAT265_ICON_WIDTH - (CAT265_TEXT_1_OFFSET*2) - 2 /* gap */;
    set_fixed_icontext_list_text_coordinates(1, CAT265_TEXT_1_X+CAT265_TEXT_1_OFFSET, row_start_y, text_width, get_menu_item_height());
    
    // TBD
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;

    if (MMI_TRUE == double_line_list_flag)
    {
        /* 2nd row */
        text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - 3 /* gap */;
        set_fixed_icontext_list_text_coordinates(2, CAT265_TEXT_2_X+CAT265_TEXT_2_OFFSET, Get_CharHeightOfAllLang(MEDIUM_FONT) + 7 /* line gap */ , text_width, Get_CharHeightOfAllLang(MEDIUM_FONT));
        MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
    }

    wgui_async_list_override_multi_icontext_highlight_handler(wgui_matv_list_highlight_handler);
	
    if (number_of_items > 0)
    {
        wgui_async_list_move_multi_icontext_menu(0, CAT265_LIST_Y);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH, CAT265_LIST_HEIGHT);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(0, CAT265_CONTROL_AREA_Y);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH, CAT265_LIST_HEIGHT + CAT265_CONTROL_AREA_HEIGHT);
    }

    if (gui_asyncdynamic_list_error)
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY265_ID, 0, ExitCategory265Screen);
    dm_register_category_controlled_callback(wgui_cat265_draw_control_area);

#if defined(__MMI_MAINLCD_320X240__) && (!defined(__MMI_FTE_SUPPORT__))
#if defined(__LCM_SCANLINE_ROTATION_SUPPORT__)
    if (MMI_fixed_list_menu.n_items > 0)
    {
		wgui_status_icon_bar_register_hide_callback(
			WGUI_STATUS_ICON_BAR_H_BAR, 
			wgui_matv_hide_status_icons_bar0);
		wgui_matv_draw_listmenu_background();
    }
	else
	{
	    dm_setup_and_draw_scr_bg(NULL);
	}
#else /* __LCM_SCANLINE_ROTATION_SUPPORT__ */
    dm_setup_and_draw_scr_bg(NULL);
#endif /* __LCM_SCANLINE_ROTATION_SUPPORT__ */
#endif /* __MMI_MAINLCD_320X240__ */
    dm_redraw_category_screen();

	wgui_matv_show_control_area_content();
     
    /* for smooth scrolling */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_list_menu_smooth_scrolling_register_stop_callback(wgui_matv_preview_stop_handler);
#endif

    /* Note: 
       TV out rule: starting  video playing is to switch GDI flushing to TV-Out path become video-trigger. 
       It means dm_redraw's output needs to wait for the first video frame playing.
       so, the preview area (start video playing) callback is moved after dm_redraw (GDI drawing). */
    if (!mmi_is_redrawing_bk_screens() && number_of_items > 0)
    {
        wgui_matv_cntx->redraw_preview_area = redraw_callback;
        wgui_matv_redraw_preview_area(CAT265_PREVIEW_X, CAT265_PREVIEW_Y, CAT265_PREVIEW_WIDTH, CAT265_PREVIEW_HEIGHT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat265_refresh_list
 * DESCRIPTION
 *  Refresh the cat265 list
 *  (it will reload menu item data with 'get_item_func' passed in ShowCategory265Screen)
 *  
 *  Category 265 screen should be currently displayed.
 * PARAMETERS
 *  number_of_items         [IN]        The number of menu items.
 *  highlighted_item        [IN]        The highlighted item
 *  redraw_flag             [IN]        reserved
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat265_refresh_list(S32 number_of_items, S32 highlighted_item, MMI_BOOL redraw_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    if(mmi_cat1007_screen == 0)
    {
        /* Note: don't invoke highlight_handler in the process */
        wgui_async_list_override_multi_icontext_highlight_handler(MMI_dummy_highlight_handler);
    }

    gui_asyncdynamic_list_error = 0;
    MMI_fixed_list_menu.n_items = number_of_items;

	wgui_matv_init_asyncdynamic_item_buffer(number_of_items);
    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
    MMI_ASSERT (!gui_asyncdynamic_list_error);
	wgui_text_menuitem_reset_scrolling();
    redraw_asyncdynamic_list();

    if(mmi_cat1007_screen == 0)
    {
        wgui_async_list_override_multi_icontext_highlight_handler(wgui_matv_list_highlight_handler);
    }
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory1007Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory1007Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    mmi_cat1007_screen = 0;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */   

}


void wgui_cat1007_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        MMI_BOOL double_line_list_flag,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width;
    U8 h_flag;
    S32 number_of_text;
    S32 menuitem_height;
    U32 flag;
    S32 row_start_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();

    mmi_cat1007_screen = 1;
    *category_error_flag = 1;
    gui_asyncdynamic_list_error = 0;
    wgui_title_set_menu_shortcut_number(-1);
    
    dm_add_title((UI_string_type)title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    flag = 0;
    flag |= (UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_Y);
    if (double_line_list_flag == MMI_TRUE)
    {
        menuitem_height = MMI_MENUITEM_MULTIROW_HEIGHT;
        flag |= WGUI_LIST_MENU_MULTIROW;
        number_of_text = 3;
        row_start_y = 2;
    }
    else
    {
        menuitem_height = MMI_MENUITEM_HEIGHT;
        number_of_text = 2;
        row_start_y = 0;
    }

    if(!(wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            number_of_text,
            1,
            get_item_func,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            menuitem_height,
            flag,
            /*MMI_CAT1007_ID*/0,
            /*history_buffer*/NULL)))
    {
        gdi_layer_unlock_frame_buffer();
        mmi_cat1007_screen = 0;
        return;
    }
        
    h_flag = set_list_menu_category_history(MMI_CAT1007_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

#if 0
/* under construction !*/
/* under construction !*/
#endif
    /* Disable menu shortcut to be displayed */
    wgui_title_set_no_icon_shct(MMI_FALSE);


    if (MMI_TRUE == double_line_list_flag)
    {
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;

        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_AUTO_CHOOSE_MARQUEE);

        MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_ICON_X);
    }

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT;

    set_fixed_icontext_list_text_coordinates(0, CAT265_TEXT_0_X+CAT265_TEXT_0_OFFSET, row_start_y, CAT265_TEXT_0_WIDTH-(CAT265_TEXT_0_OFFSET*2), get_menu_item_height());
    set_fixed_icontext_list_icon_coordinates(0, CAT265_ICON_X+CAT265_ICON_OFFSET, row_start_y, CAT265_ICON_WIDTH-(CAT265_ICON_OFFSET*2), get_menu_item_height());
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT265_TEXT_0_WIDTH - CAT265_ICON_WIDTH - (CAT265_TEXT_1_OFFSET*2) - 2 /* gap */;
    set_fixed_icontext_list_text_coordinates(1, CAT265_TEXT_1_X+CAT265_TEXT_1_OFFSET, row_start_y, text_width, get_menu_item_height());
    
    // TBD
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;

    if (MMI_TRUE == double_line_list_flag)
    {
        /* 2nd row */
        text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - 3 /* gap */;
        set_fixed_icontext_list_text_coordinates(2, CAT265_TEXT_2_X+CAT265_TEXT_2_OFFSET, Get_CharHeightOfAllLang(MEDIUM_FONT) + 7 /* line gap */ , text_width, Get_CharHeightOfAllLang(MEDIUM_FONT));
        MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
    }

    if (gui_asyncdynamic_list_error)
    {
        gdi_layer_unlock_frame_buffer();
        mmi_cat1007_screen = 0;
        return;
    }

    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height);

	wgui_cat_setup_category_default_history(MMI_CAT1007_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory1007Screen);
    dm_redraw_category_screen();

    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
    	mmi_cat1007_screen = 0;
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    *category_error_flag = 0;
}

#endif /* __MMI_CAT265_SUPPORT__ */

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__

static UI_horizontal_tab_bar_theme wgui_mbbms_cat_tab_theme;


void wgui_cat_mbbms_set_tab_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&wgui_mbbms_cat_tab_theme, MMI_horizontal_tab_bar.theme, sizeof(UI_horizontal_tab_bar_theme));
    wgui_mbbms_cat_tab_theme.tab_text_font = &MMI_small_font;
    wgui_mbbms_cat_tab_theme.focused_tab_text_font = &MMI_small_font;

    gui_set_horizontal_tab_bar_theme(&MMI_horizontal_tab_bar, &wgui_mbbms_cat_tab_theme);
}


static void wgui_cat1008_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    matv_rect p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p.x = CAT1008_PREVIEW_X;
	p.y = CAT1008_PREVIEW_Y;
	p.width = CAT1008_PREVIEW_WIDTH;
	p.height = CAT1008_PREVIEW_HEIGHT;

	wgui_matv_draw_control_area(coordinate, &p, CAT1008_PREVIEW_AREA_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1008_menu_post_display
 * DESCRIPTION
 *  post menu to display
 * PARAMETERS
 *  void
 * RETURNS   void
 *****************************************************************************/
static void wgui_cat1008_menu_post_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	matv_rect p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p.x = CAT1008_PREVIEW_X;
	p.y = CAT1008_PREVIEW_Y;
	p.width = CAT1008_PREVIEW_WIDTH;
	p.height = CAT1008_PREVIEW_HEIGHT;

	wgui_matv_menu_post_display(&p);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1008_create_preview_name_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1008_create_preview_name_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	matv_rect pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pos.x = CAT1008_NAME_X;
	pos.width = CAT1008_NAME_WIDTH;
	pos.height = CAT1008_NAME_HEIGHT;
	if (wgui_matv_get_preview_time() == NULL)
	{
		pos.y = CAT1008_NAME_Y;
	}
	else
	{
		pos.y = CAT1008_PREVIEW_STR_1_Y;
	}
	wgui_matv_create_preview_name(&pos);

    if (wgui_matv_get_preview_time() != NULL)
    {
		pos.y = CAT1008_PREVIEW_STR_2_Y;
    }
	wgui_matv_create_preview_time(&pos);
}


static void wgui_cat1008_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }

    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();

    wgui_matv_stop_preview_name();
    //TBD
    wgui_matv_stop_preview_time();

	wgui_matv_free_cntx();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cattab_get_space_and_tab_width
 * DESCRIPTION
 *  get space and tab width of screen
 * PARAMETERS
 *  space      [OUT]        preview name string
 *  tab_w      [OUT]        preview time string
 *  n_tabs     [IN]         number of tabs
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cattab_get_space_and_tab_width(S16 *space, S16 *tab_w, S8 n_tabs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 diff = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(n_tabs <= 2)
	{
		diff = 2;
	}
	else
	{
		diff = 3;
    }
    *space = GUI_TAB_GAP;
    *tab_w = (UI_device_width - ((GUI_TAB_GAP)<<1))/diff;
}


extern void wgui_setup_horizontal_tab_bar_no_title_shortcut(void);
void wgui_cat1008_show(
         WCHAR* title,
         PU8 title_icon,
         WCHAR* left_softkey,
         PU8 left_softkey_icon,
         WCHAR* right_softkey,
         PU8 right_softkey_icon,
         MMI_BOOL double_line_list_flag,
         S32 number_of_items,
         GetAsyncItemFuncPtr get_item_func,
         GetAsyncHintFuncPtr get_hint_func,
         wgui_menuitem_callback pre_highlight_callback,
         LayerRedrawCallback redraw_callback,
         S32 highlighted_item,
         S32 highlighted_tab,
         U8 *history_buffer,
         S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S8 n_tabs = 0;
    S32 line_height = 0;
    S32 ch_w = 0, time_w = 0;
    S32 chn_x = 0, curr_ch_x = 0;
    S32 icon_x = UI_device_width - (GUI_ICONTEXT_MENUITEM_ICON_X + GUI_MENUITEM_TEXT_RIGHT_GAP + CAT1008_ICON_WIDTH);
    S16 spac = 0, tab_w = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();
    gui_asyncdynamic_list_error = 0;

	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    /* get the number of horizontal tab and create it */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
    //wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
    dm_add_title((UI_string_type)title, title_icon);

    wgui_cattab_get_space_and_tab_width(&spac, &tab_w, n_tabs);

//	wgui_create_horizontal_tab_bar_with_style(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE, GUI_TAB_BAR_STYLE_AUTO_RESIZE_ITEM_WIDTH | GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM);
    //wgui_create_horizontal_tab_bar_with_style(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE, GUI_TAB_BAR_STYLE_AUTO_RESIZE_ITEM_WIDTH | GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM);
	wgui_create_horizontal_tab_bar_ex(
		FALSE,
		(UI_string_type)NULL, 
		n_tabs, 
		highlighted_tab,
		tab_w,
		tab_w,
		spac,
		MMI_FALSE,
		GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE);

    wgui_setup_horizontal_tab_bar_no_title_shortcut();
    
    /*set tab text font to be small font*/
    wgui_cat_mbbms_set_tab_theme();

    /* create category1008 context used memory, it is screen based memory */
	wgui_matv_init_cntx(
	    pre_highlight_callback,
	    redraw_callback,
	    get_item_func,
	    get_hint_func,
	    wgui_cat1008_create_preview_name_time,
	    wgui_cat1008_menu_post_display,
	    CAT1008_PREVIEW_AREA_SIZE);

    /* set the menuitem height and text number in the menuitem */
    line_height = (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1);

	/* judge if there is scroll bar or not */
	if(number_of_items > CAT1008_LIST_HEIGHT/MMI_MENUITEM_THICK_WITH_TAB_HEIGHT)
	{
		icon_x -= MMI_fixed_list_menu.vbar.width;
	}

    MMI_fixed_icontext_list_menuitem.flags = 0;

    /* create a multi icon-text list */
    if(!(wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            4,
            2,
            get_item_func,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
            WGUI_LIST_MENU_DISABLE_SHORTCUT,
            0,
            NULL)))
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    /* set histoty of list */
    h_flag = set_list_menu_category_history(MMI_CAT1008_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    {
        U16 channel[] = L"CH888  ";
		U16 time[] = L"88:88-88:88 ";
        S32 w, h;
    #ifdef __MMI_MAINLCD_320X480__
        gui_set_font(&MMI_medium_font);
	#else /* __MMI_MAINLCD_320X480__ */
        gui_set_font(&MMI_small_font);
	#endif /* __MMI_MAINLCD_320X480__ */
        gui_measure_string((UI_string_type)channel, &w, &h);
        ch_w = w+2;
        gui_measure_string((UI_string_type)time, &w, &h);
        time_w = w+2;

        chn_x = GUI_TEXT_MENUITEM_TEXT_X + ch_w;
        curr_ch_x = GUI_TEXT_MENUITEM_TEXT_X + time_w;
    }

    set_fixed_icontext_list_icon_coordinates(0, icon_x, 0, CAT1008_ICON_WIDTH, line_height);
    set_fixed_icontext_list_icon_coordinates(1, icon_x, line_height, CAT1008_ICON_WIDTH, line_height);
    set_fixed_icontext_list_text_coordinates(0, GUI_TEXT_MENUITEM_TEXT_X, 1, ch_w, line_height);
	icon_x = icon_x - 3; 
    set_fixed_icontext_list_text_coordinates(1, chn_x, 1, icon_x - chn_x, line_height);
    set_fixed_icontext_list_text_coordinates(2, GUI_TEXT_MENUITEM_TEXT_X, line_height - 1, time_w, line_height);
    set_fixed_icontext_list_text_coordinates(3, curr_ch_x, line_height - 1, icon_x - curr_ch_x, line_height);

    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_AUTO_CHOOSE_MARQUEE);
    /* set list flags */
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT | UI_MENUITEM_CENTER_ICON_Y | UI_MENUITEM_CENTER_TEXT_Y;

    /* set the font of each text in the menuitem */
#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_medium_font;
#else /* __MMI_MAINLCD_320X480__ */
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_small_font;
#endif /* __MMI_MAINLCD_320X480__ */

    /* set filler of the menuitem */
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;//menuitem_thick_with_tab_highlight_without_scroll_filler
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
    
    wgui_async_list_override_multi_icontext_highlight_handler(wgui_matv_list_highlight_handler);

    if(number_of_items > 0)
    {
        line_height = 0;
    }
    else
    {
        line_height = CAT1008_CONTROL_AREA_HEIGHT;
    }
	wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X, CAT1008_LIST_Y - line_height);
	wgui_async_list_resize_multi_icontext_menu(MMI_content_width, CAT1008_LIST_HEIGHT + line_height);

    if (gui_asyncdynamic_list_error)
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

	wgui_cat_setup_category_default_history(MMI_CAT1008_ID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1008_exit);
    dm_register_category_controlled_callback(wgui_cat1008_draw_control_area);
    dm_redraw_category_screen();

    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

	wgui_matv_show_control_area_content();

    *category_error_flag = 0;

    /* for smooth scrolling */
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_list_menu_smooth_scrolling_register_stop_callback(wgui_matv_preview_stop_handler);
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */

    /* Note: 
       TV out rule: starting  video playing is to switch GDI flushing to TV-Out path become video-trigger. 
       It means dm_redraw's output needs to wait for the first video frame playing.
       so, the preview area (start video playing) callback is moved after dm_redraw (GDI drawing). */
    if(number_of_items > 0)
    {
        wgui_matv_redraw_preview_area(CAT1008_PREVIEW_X, CAT1008_PREVIEW_Y, CAT1008_PREVIEW_WIDTH, CAT1008_PREVIEW_HEIGHT);
    }
}

/* the following is wgui_cat1009_show, have three lines of eache menuitem */
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1009_create_infomsg
 * DESCRIPTION
 *  create and get string area height according to string
 * PARAMETERS
 *  string                       [IN]       description string displayed at control area 
 * RETURNS
 *  return height
 *****************************************************************************/
static S32 wgui_cat1009_create_infomsg(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 var, var1 = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string == NULL)
    {
        return 0;
    }
    var = gui_strlen(string);
    if (var == 0)
    {
        return 0;
    }
    create_multiline_inputbox_set_buffer(string, var, var, 0);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND;
    MMI_multiline_inputbox.normal_text_color = current_fixed_icontext_menuitem_theme->normal_text_color;
    wgui_inputs_ml_resize_fit(
        UI_device_width, 
        UI_device_height, 
        &var,
        &var1);
    return var1;
}

/*****************************************************************************
 * FUNCTION
 *  DrawCate1009CategoryControlArea
 * DESCRIPTION
 *  control area callback 
 * PARAMETERS
 *  coordinate             [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate1009CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_multiline_inputbox(MMI_content_x, 
        MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1009_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1009_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }

    reset_multiline_inputbox();
	
    wgui_reset_touch_title_bar_buttons();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);

    mmi_cat1007_screen = 0;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */   

}


extern void gui_fixed_icontext_list_menuitem_reset_scroll_text_column(void);
/*
 *S32 flag parameter explanation
 *-----------------------------------------------
 *if flag == 0, menuitem icon style is:     @
 *                                          @
 *
 *-----------------------------------------------
 *-----------------------------------------------
 *if flag == 1, menuitem icon style is:     
 *                                          @
 *                                          @
 *-----------------------------------------------
 */
static void wgui_cat1009_show_ext(
                WCHAR* title,
                PU8 title_icon,
                WCHAR* left_softkey,
                PU8 left_softkey_icon,
                WCHAR* right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                UI_string_type info_msg,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 flag,
                S32 highlighted_item,
                S32 highlighted_tab,
                U8 *history_buffer,
                S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S8 n_tabs = 0;
    S32 text_width = 0, time_width = 0;
    S32 menuitem_h = 0; /*menuitem height in the list*/
    S32 line_h = 0; /*line height in the menuitem*/
    S32 t1_x = 0; /*text position after icon*/
    S32 t2_x = 0; /*text position of time*/
    S32 cat_id = 0; /*category id that will be used in this category*/
    S32 i_start_y = 0;
    S32 number_of_text = 4;
    S32 number_of_icon = 2;
    U32 l_flag = 0;
    S16 spac = 0, tab_w = 0;
    S32 icon_width = 0; /*add for cat1021 change*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

    gdi_layer_lock_frame_buffer();
    gui_asyncdynamic_list_error = 0;
    *category_error_flag = 1;

	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    /* get the number of horizontal tab and create it */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;

    dm_add_title((UI_string_type)title, title_icon);
    if(n_tabs > 0)
    {
        l_flag = WGUI_LIST_MENU_DISABLE_SHORTCUT;
        //wgui_create_horizontal_tab_bar_with_style(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE, GUI_TAB_BAR_STYLE_AUTO_RESIZE_ITEM_WIDTH | GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM);
        //wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        
        wgui_cattab_get_space_and_tab_width(&spac, &tab_w, n_tabs);
            wgui_create_horizontal_tab_bar_ex(
            FALSE,
            (UI_string_type)title, 
            n_tabs, 
            highlighted_tab,
            tab_w,
            tab_w,
            spac,
            MMI_FALSE,
            GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();   
        /*set tab text font to be small font*/
        wgui_cat_mbbms_set_tab_theme();
    
        cat_id = MMI_CAT1009_ID;
    }
    else
    {
        cat_id = MMI_CAT1007_ID;
    }

    if(flag == 2)
    {
        menuitem_h = MMI_MULTIROW_MENUITEM_HEIGHT;
        line_h = (menuitem_h>>1);
    }
    else
    {
#if defined(__MMI_MAINLCD_320X480__)
        menuitem_h = MMI_MULTIROW_MENUITEM_HEIGHT;
#else /* __MMI_MAINLCD_320X480__ */
        menuitem_h = MMI_MENUITEM_TWOLINE_HEIGHT;
#endif /* __MMI_MAINLCD_320X480__ */

        line_h = menuitem_h/3;
    }

    if(flag == 1)
    {
        number_of_text = 3;
        i_start_y = line_h;
    }
    else if(flag == 2)
    {
        number_of_text = 2;
        number_of_icon = /*1*/2;
    }
    else if (flag == 0)
    {
        number_of_icon = 3;
    }

    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        number_of_text,
        number_of_icon,
        get_item_func,
        get_hint_func,
        /*highlighted_item*/WGUI_LIST_INVALID_HIGHLIGHT,
        /*MMI_MENUITEM_TWOLINE_HEIGHT*/menuitem_h,
        l_flag,
        /*MMI_CAT1006_ID*/0,
        /*history_buffer*/NULL);

	/* set histoty of list */
    h_flag = set_list_menu_category_history(/*MMI_CAT1006_ID*/cat_id, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    /* mesure the width of time */
    {
        S32 w, h;
        U16 temp1[] = L"8888-88-88";
    #ifdef __MMI_MAINLCD_320X480__
        gui_set_font(&MMI_medium_font);
	#else /* __MMI_MAINLCD_320X480__ */
        gui_set_font(&MMI_small_font);
	#endif /* __MMI_MAINLCD_320X480__ */
        gui_measure_string((UI_string_type)temp1, &w, &h);
        time_width = w + 2;
    }
    
    /* if flag == 2, icon width will be 32, else icon width will be the same as cat1008 */
    if(flag == 2){
        icon_width = 32;
    }
    else{
        icon_width = CAT1008_ICON_WIDTH;
    }

    t1_x = GUI_ICONTEXT_MENUITEM_ICON_X + /*CAT1008_ICON_WIDTH*/icon_width + 4;
    t2_x = t1_x + 4 + time_width;

    text_width = UI_device_width - t1_x - GUI_MENUITEM_TEXT_RIGHT_GAP - MMI_fixed_list_menu.vbar.width;

    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, i_start_y + 0, /*CAT1008_ICON_WIDTH*/icon_width, line_h);
    set_fixed_icontext_list_icon_coordinates(1, GUI_ICONTEXT_MENUITEM_ICON_X, i_start_y + line_h, /*CAT1008_ICON_WIDTH*/icon_width, line_h);
    if (flag == 0)
    {
        set_fixed_icontext_list_icon_coordinates(2, GUI_ICONTEXT_MENUITEM_ICON_X, menuitem_h - line_h - 1, /*CAT1008_ICON_WIDTH*/icon_width, line_h);
    }

    set_fixed_icontext_list_text_coordinates(0, t1_x, 1, text_width, line_h);
    if(flag == 0)
    {
        set_fixed_icontext_list_text_coordinates(1, t1_x, line_h - 1, time_width, line_h);
        set_fixed_icontext_list_text_coordinates(2, t2_x, line_h - 1, text_width - time_width - 4, line_h);
    }
    else
    {
        set_fixed_icontext_list_text_coordinates(1, t1_x, line_h - 1, text_width, line_h);
        set_fixed_icontext_list_text_coordinates(2, t1_x, menuitem_h - line_h - 1, text_width, line_h);
    }
    set_fixed_icontext_list_text_coordinates(3, t1_x, menuitem_h - line_h - 1, text_width, line_h);

#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_medium_font;
#else /* __MMI_MAINLCD_320X480__ */
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[3] = &MMI_small_font;
#endif /* __MMI_MAINLCD_320X480__ */

    /* set list flags */
    if (flag == 1)
    {
        MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_CENTER_ICON_Y | UI_MENUITEM_CENTER_TEXT_Y;
		gui_fixed_icontext_list_menuitem_reset_scroll_text_column();
    }
	else
	{
	    MMI_fixed_icontext_list_menuitem.flags &= ~(UI_MENUITEM_AUTO_CHOOSE_MARQUEE);
		MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_TRUNCATE_CONTENT | UI_MENUITEM_CENTER_ICON_Y | UI_MENUITEM_CENTER_TEXT_Y;
	}

#if defined(__MMI_MAINLCD_320X480__)
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_multirow_highlight_filler;//menuitem_multirow_highlight_without_scroll_filler
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
#else /* __MMI_MAINLCD_320X480__ */
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_two_line_highlight_filler;//menuitem_two_line_highlight_without_scroll_filler
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_two_line_highlight_filler;
#endif /* __MMI_MAINLCD_320X480__ */

    if(n_tabs > 0)
    {
        S32 control_area_h = 0;
        if (flag == 1)
        {
            control_area_h = wgui_cat1009_create_infomsg(info_msg);
            if (control_area_h > 0)
            {
                dm_register_category_controlled_callback(DrawCate1009CategoryControlArea);
            }
        }
        wgui_async_list_move_multi_icontext_menu(0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + control_area_h);
        wgui_async_list_resize_multi_icontext_menu(MAIN_LCD_DEVICE_WIDTH, MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - control_area_h);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X, MMI_CONTENT_Y);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT);
    }

	wgui_cat_setup_category_default_history(cat_id, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1009_exit);
    dm_redraw_category_screen();

    gdi_layer_unlock_frame_buffer();
    if(gui_asyncdynamic_list_error)
    {
        return;
    }
    *category_error_flag = 0;

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

void wgui_cat1009_show(
                WCHAR* title,
                PU8 title_icon,
                WCHAR* left_softkey,
                PU8 left_softkey_icon,
                WCHAR* right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                S32 highlighted_tab,
                U8 *history_buffer,
                S32 *category_error_flag)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1009_show_ext(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        NULL,
        get_item_func,
        get_hint_func,
        0,
        highlighted_item,
        highlighted_tab,
        history_buffer,
        category_error_flag);
}


void wgui_cat1020_show(
                WCHAR* title,
                PU8 title_icon,
                WCHAR* left_softkey,
                PU8 left_softkey_icon,
                WCHAR* right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                UI_string_type info_msg,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                S32 highlighted_tab,
                U8 *history_buffer,
                S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1009_show_ext(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        info_msg,
        get_item_func,
        get_hint_func,
        1,
        highlighted_item,
        highlighted_tab,
        history_buffer,
        category_error_flag);
}


void wgui_cat1021_show(
                WCHAR* title,
                PU8 title_icon,
                WCHAR* left_softkey,
                PU8 left_softkey_icon,
                WCHAR* right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1009_show_ext(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        NULL,
        get_item_func,
        get_hint_func,
        2,
        highlighted_item,
        -1,
        history_buffer,
        category_error_flag);
}

void wgui_cat1022_show(
                WCHAR* title,
                PU8 title_icon,
                WCHAR* left_softkey,
                PU8 left_softkey_icon,
                WCHAR* right_softkey,
                PU8 right_softkey_icon,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                GetAsyncHintFuncPtr get_hint_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1009_show_ext(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        NULL,
        get_item_func,
        get_hint_func,
        0,
        highlighted_item,
        -1,
        history_buffer,
        category_error_flag);
}


/*The follows are wgui_cat1023_show related variables and functions */
/* category 1023 history buffer pointer */
static list_menu_cat1023_history *cat1023_history = NULL;

typedef struct
{
    S32 h_date;	/* highlighted date of current screen */
	S32 h_tab;	/* highlighted tab of current screen */
	S32 date_count;
	S32 list_m_count;	/* the menuitem count of the list */
	S32 *tab_history;	/* tab history buffer pointer of each date */
	U32 history_size;	/* category 1023 history buffer size, should be put to .c file */
	wgui_cat1023_get_highlight_callback get_highlight;	/*get highlight callback*/
} wgui_cat1023_cntx;

static wgui_cat1023_cntx g_cat1023_cntx = {0};


void wgui_cat1023_register_get_highlight_callback(wgui_cat1023_get_highlight_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_cat1023_cntx.get_highlight = cb;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_set_history_buffer
 * DESCRIPTION
 *  Set category history buffer for this category
 * PARAMETERS
 *  size       :    [IN]    buffer size
 *  buffer    :    [IN]    the pointer of the buffer
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE if malloc buffer success, MMI_FALSE
 *****************************************************************************/
MMI_BOOL wgui_cat1023_set_history_buffer(S32 size, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT((size > 0) && (buffer != NULL));

    if(size < 0 || buffer == NULL)
    {
        return MMI_FALSE;
    }
	
    /* caculate and set list history pointer */
    tmp = (S32*)buffer;
    tmp += MMI_CAT1023_MAX_DATE_COUNT;

    /* set history buffer pointer */
    g_cat1023_cntx.history_size = size;
    g_cat1023_cntx.tab_history = (S32*) buffer; /* tab history */
    cat1023_history = (list_menu_cat1023_history*)tmp;/*list history*/

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_reset_history_buffer
 * DESCRIPTION
 *  reset category history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  
 *****************************************************************************/
void wgui_cat1023_reset_history_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set history value to be zero */
    wgui_cat1023_initialize_history_buffer();

    /* set history pointer to be NULL */
    g_cat1023_cntx.tab_history = NULL;
    cat1023_history = NULL;
    /* set history size to be zero */
    g_cat1023_cntx.history_size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_initialize_history_buffer
 * DESCRIPTION
 *  Initialize history buffer to be zero, so that we can identify if history is available ot not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1023_initialize_history_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((cat1023_history != NULL) && (g_cat1023_cntx.history_size > 0));

    memset((S8*)(g_cat1023_cntx.tab_history), 0, g_cat1023_cntx.history_size);
}


static WCHAR *cat1023_date_text[MMI_CAT1023_MAX_DATE_COUNT];
static WCHAR* cat1023_tab_text[MMI_CAT1023_MAX_TAB_COUNT];

typedef struct
{
    GetCat1023TabItemCount get_tab_count_ptr;
	GetCat1023TabItemFuncPtr get_tab_items_ptr;
	GetCat1023MenuItemCount get_menuitem_count_ptr;
	GetCat1023AsyncItemFuncPtr get_menuitems_ptr;
	GetCat1023AsyncHintFuncPtr get_menuitem_hints_ptr;
} wgui_cat1023_cb_func;

static wgui_cat1023_cb_func g_cat1023_cb_func;

#define CAT1023_TAB_BAR_NUM	5


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_construct_tab_info
 * DESCRIPTION
 *  construct tab structure of category1023
 * PARAMETERS
 *  date_index            [IN]    highlighted date of current screen
 *  tab_index              [IN]    highglighted tab of current screen
 *  start_index      :    [IN]     Start index of menu item
 *  menu_data        :    [OUT]    A pointer of parameter to store the menu data
 *  data_size        :    [IN]     The number of load menu items
 * RETURNS
 *  MMI_BOOL        return MMI_TRUE if construct success, else return MMI_FALSE
 *****************************************************************************/
static S32 wgui_cat1023_get_item_func_ptr(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cat1023_cb_func.get_menuitems_ptr(
               g_cat1023_cntx.h_date,
               g_cat1023_cntx.h_tab,
               start_index,
               menu_data,
               data_size);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_get_hint_func_ptr
 * DESCRIPTION
 *  wrap app's get menu's hint callback for category1023
 * PARAMETERS
 *  date_index            [IN]    highlighted date of current screen
 *  tab_index              [IN]    highglighted tab of current screen
 *  start_index            [IN]     Start index of menu item
 *  hint_array             [OUT]    A pointer of parameter to store the hint
 * RETURNS
 *  MMI_BOOL        return MMI_TRUE if construct success, else return MMI_FALSE
 *****************************************************************************/
static S32 wgui_cat1023_get_hint_func_ptr(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cat1023_cb_func.get_menuitem_hints_ptr(
               g_cat1023_cntx.h_date,
               g_cat1023_cntx.h_tab,
               start_index,
               hint_array);
}


static void wgui_cat1023_set_curr_history_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cat1023_history != NULL);
    MMI_ASSERT((g_cat1023_cntx.h_date < MMI_CAT1023_MAX_DATE_COUNT) && (g_cat1023_cntx.h_tab < MMI_CAT1023_MAX_TAB_COUNT));
    
    /* restore tab history */
    g_cat1023_cntx.tab_history[g_cat1023_cntx.h_date] = g_cat1023_cntx.h_tab;
    
    /* restore list history */
	index = (g_cat1023_cntx.h_date)*MMI_CAT1023_MAX_TAB_COUNT + (g_cat1023_cntx.h_tab);
    cat1023_history[index].first_displayed_item = MMI_fixed_list_menu.first_displayed_item;
    cat1023_history[index].highlighted_item = MMI_fixed_list_menu.highlighted_item;
    cat1023_history[index].last_displayed_item = MMI_fixed_list_menu.last_displayed_item;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_construct_list_history
 * DESCRIPTION
 *  wrap app's get menu's hint callback for category1023
 * PARAMETERS
 *  h                    [OUT]    list history will be constructed
 *  h_id                [IN]       history id of this screen
 *  n_itmes           [IN]    total number of list menuitems in the screen
 * RETURNS
 *  MMI_BOOL        return MMI_TRUE if construct success, else return MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cat1023_construct_list_history(list_menu_category_history *h, U16 h_id, S32 n_itmes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 index;
	list_menu_cat1023_history *cat_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cat1023_history != NULL);
    MMI_ASSERT((g_cat1023_cntx.h_date < MMI_CAT1023_MAX_DATE_COUNT) && (g_cat1023_cntx.h_tab < MMI_CAT1023_MAX_TAB_COUNT));

	index = (g_cat1023_cntx.h_date)*MMI_CAT1023_MAX_TAB_COUNT + (g_cat1023_cntx.h_tab);
	cat_h = &cat1023_history[index];
    
    if(h == NULL)
    {
        return MMI_FALSE;
    }

    h->history_ID = (h_id | 0x8000);
    h->first_displayed_item = cat_h->first_displayed_item;
    h->highlighted_item = cat_h->highlighted_item;
    h->last_displayed_item = cat_h->last_displayed_item;
    h->displayed_items = cat_h->last_displayed_item - cat_h->first_displayed_item + 1;
    h->flags = MMI_fixed_list_menu.flags;
    h->state = (S8) (-1);
    h->num_items = n_itmes;

    /*add for history change to current time item*/
    if(g_cat1023_cntx.get_highlight != NULL 
		&& (cat_h->first_displayed_item == 0 && cat_h->highlighted_item == 0 && cat_h->last_displayed_item == 0))
    {
        change_list_menu_category_history((U8 *)h, g_cat1023_cntx.get_highlight(), n_itmes, h->flags);
    }
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_get_date_area_x_and_width
 * DESCRIPTION
 *  Used to get date text area start position and width
 * PARAMETERS
 *  x            [OUT]   start value of date area
 *  width      [OTU]   width of date area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_get_date_area_x_and_width(S32 *x, S32 *width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)
    *x = (MAIN_LCD_DEVICE_WIDTH>>1) + 9 + MMI_TITLEBAR_BUTTON_WIDTH;
    *width = (MAIN_LCD_DEVICE_WIDTH>>1) - ((8 + MMI_TITLEBAR_BUTTON_WIDTH)<<1);
#else
    *x = (MAIN_LCD_DEVICE_WIDTH>>1) + 6 + MMI_TITLEBAR_BUTTON_WIDTH;
    *width = (MAIN_LCD_DEVICE_WIDTH>>1) - ((6 + MMI_TITLEBAR_BUTTON_WIDTH)<<1);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_control_area_callback
 * DESCRIPTION
 *  control area callback for category 1023, used to clear control to be
 *  transparent with background
 * PARAMETERS
 *  coordinate    [IN]   coordinates of control area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_control_area_callback(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ax = 0, aw = 0;
    S32 tx = 0, ty = MMI_TITLE_Y, tw = 0, th = 0;
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image(get_image(LEFT_RED_ARROW_PRESSED), &iw, &ih);

    /* flash the area to be transparent with background */
#ifdef GDI_USING_LAYER
    gdi_draw_solid_rect(
        coordinate->s16X, MMI_TITLE_Y,
        coordinate->s16X + coordinate->s16Width - 1, MMI_TITLE_Y + MMI_TITLE_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);
#else
    gdi_draw_solid_rect(
        coordinate->s16X, MMI_TITLE_Y,
        coordinate->s16X + coordinate->s16Width - 1, MMI_TITLE_Y + MMI_TITLE_HEIGHT - 1,
        GDI_COLOR_WHITE);
#endif

    /* get text area start position and width */
    wgui_cat1023_get_date_area_x_and_width(&ax, &aw);

    /* measure the string width and height */
	gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type)cat1023_date_text[g_cat1023_cntx.h_date], &tw, &th);

    /* caculate text position will be shown, centralize text in X and Y position */
    if(aw > tw)
    {
        if (mmi_fe_get_r2l_state())
        {
            tx = ax + aw - ((aw - tw - 2)>>1);
        }
        else
        {
            tx = ax + ((aw - tw - 2)>>1);
        }
        tw = tw + 1;        
    }
    else
    {
        if (mmi_fe_get_r2l_state())
        {
            tx = ax + aw;
        }
        else
        {
            tx = ax;
        }
        tw = aw;
    }
    ty += ((MMI_TITLE_HEIGHT - th)>>1);

//    gdi_layer_pop_clip();

//    gdi_layer_unlock_frame_buffer();

    /*Maybe we need to blt data to LCD*/
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* show the text in the special area */
    gui_print_truncated_text(tx, ty, tw, (UI_string_type)cat1023_date_text[g_cat1023_cntx.h_date]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_exit
 * DESCRIPTION
 *  exit function of category 1023
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set highlighted tab to the history */
    g_cat1023_cntx.tab_history[g_cat1023_cntx.h_date] = g_cat1023_cntx.h_tab;

    /* record history of current screen's list */
	wgui_cat1023_set_curr_history_node();

    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    //ExitListCategoryScreen();
    if(g_cat_tab_num > 0)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    
	g_cat1023_cntx.get_highlight = NULL;
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_map_curr_tab_bar
 * DESCRIPTION
 *  map current tab bar to 5 tabs
 * PARAMETERS
 *  f_tab		[OUT]	first tab after mapping
 *  h_tab		[OUT]	highlight tab after mapping
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_map_curr_tab_bar(S8 *f_tab, S8 *h_tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 m_tab_num, highlight_tab, first_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get highlight tab index and middle tab index */
    if (g_cat1023_cntx.h_tab < 2)
    {
        highlight_tab = g_cat1023_cntx.h_tab;
        m_tab_num = 0;
    }
    else if (g_cat1023_cntx.h_tab > g_cat_tab_num - 2 - 1)
    {
        highlight_tab = g_cat1023_cntx.h_tab - (g_cat_tab_num - 2 - 1) + 2;
        m_tab_num = g_cat1023_cntx.h_tab - 2;
    }
    else
    {
        highlight_tab = 2;
        m_tab_num = g_cat1023_cntx.h_tab - 2;
    }
    
    /* get first tab index */
    if (highlight_tab < 2)
    {
        first_tab = 0;
    }
    else if (highlight_tab > 2)
    {
        first_tab = g_cat_tab_num - CAT1023_TAB_BAR_NUM;
    }
    else 
    {
        first_tab = (S8)m_tab_num;
    }
	*h_tab = (S8)highlight_tab;
	*f_tab = (S8)first_tab;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_create_tab_bar
 * DESCRIPTION
 *  create horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_create_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0, h_tab = 0, f_tab = 0, i;
    S16 spac = 0, tab_w = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get tab counts of current screen */
	g_cat1023_cb_func.get_tab_count_ptr(g_cat1023_cntx.h_date, &g_cat_tab_num);
    MMI_ASSERT(g_cat_tab_num >= 0);
    n_tabs = 0xff&g_cat_tab_num;
    if (n_tabs > CAT1023_TAB_BAR_NUM)
    {
        n_tabs = CAT1023_TAB_BAR_NUM;
		wgui_cat1023_map_curr_tab_bar(&f_tab, &h_tab);
    }
    else
    {
        h_tab = 0xff & (g_cat1023_cntx.h_tab);
    }
    
    /* construct tab information structure */
	g_cat1023_cb_func.get_tab_items_ptr(f_tab, n_tabs, cat1023_tab_text);
	
    for(i = 0; i < n_tabs; ++i)
    {
        MMI_tab_bar_items[i].icon = NULL;
        MMI_tab_bar_items[i].text = (UI_string_type)cat1023_tab_text[(f_tab + i)];
        MMI_tab_bar_items[i].flags = 0;
    #ifdef __MMI_OP11_TAB_BAR__
        /* The duration of blinking, the unit is ms */
        MMI_tab_bar_items[i].blink_duration = 0;
    #endif/* __MMI_OP11_TAB_BAR__ */
    }

    /* it will be assert if there is no this line */
    MMI_horizontal_tab_bar.title.sc.normal_font = &MMI_medium_font;
    
    /* create tab bar */
    if(n_tabs > 0)
    {
        wgui_cattab_get_space_and_tab_width(&spac, &tab_w, n_tabs);
        wgui_create_horizontal_tab_bar_ex(
            FALSE,
            NULL, 
            n_tabs, 
            h_tab,
            tab_w,
            tab_w,
            spac,
            MMI_FALSE,
            GUI_TAB_BAR_STYLE_SHOW_ONLY_TEXT_IN_TAB_ITEM,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
		
        /*set tab text font to be small font*/
        wgui_cat_mbbms_set_tab_theme();
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        
    }
}


static void wgui_cat1023_redraw_tab_and_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U8 h_flag;
	list_menu_category_history l_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_cat_tab_num > 0)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }

    /* create tab bar */
    wgui_cat1023_create_tab_bar();
    wgui_move_horizontal_tab_bar(MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT);
    wgui_show_horizontal_tab_bar();

    /* update list */
    /* construct list history */
    /* get menu item count of current screen */
    g_cat1023_cb_func.get_menuitem_count_ptr(g_cat1023_cntx.h_date, g_cat1023_cntx.h_tab, &(g_cat1023_cntx.list_m_count));
	MMI_ASSERT(g_cat1023_cntx.list_m_count >= 0);
	ret = wgui_cat1023_construct_list_history(&l_history, MMI_CAT1023_ID, g_cat1023_cntx.list_m_count);

    /* set list menu category history */
    MMI_fixed_list_menu.first_displayed_item = 0;
    MMI_fixed_list_menu.highlighted_item = 0;
    MMI_fixed_list_menu.n_items = g_cat1023_cntx.list_m_count;
    if(ret)
    {
        h_flag = set_list_menu_category_history(MMI_CAT1023_ID,(U8 *)&l_history);
        if(!h_flag)
        {
            MMI_fixed_list_menu.highlighted_item = 0;
        }
    }
    else /* if there no history, we will reset list data */
    {
        MMI_fixed_list_menu.first_displayed_item = 0;
        MMI_fixed_list_menu.highlighted_item = 0;
    }

	if (g_cat1023_cntx.list_m_count <= 0)
	{
	    wgui_stop_list_menuitem_scrolling();
	}
    mmi_cat_refresh_asyncdynamic_list(
        g_cat1023_cntx.list_m_count,
        MMI_fixed_list_menu.highlighted_item,
        wgui_cat1023_get_item_func_ptr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_star_pound_key_handler
 * DESCRIPTION
 *  *key handler, it will show the previous date information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_star_pound_key_handler(U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tab = 0;
    dm_coordinates coord;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((g_cat1023_cntx.h_date >= 0) && (g_cat1023_cntx.h_date < MMI_CAT1023_MAX_DATE_COUNT));

    /* restore previous list history */
	wgui_cat1023_set_curr_history_node();

    coord.s16X = (MMI_TITLE_WIDTH>>1) + 6 + MMI_TITLEBAR_BUTTON_WIDTH;
    coord.s16Y = MMI_TITLE_Y;
    coord.s16Width = (MMI_TITLE_WIDTH>>1) - 12 - (MMI_TITLEBAR_BUTTON_WIDTH<<1);
    coord.s16Height = MMI_TITLE_HEIGHT;

    /* caculate highlighted date index */
    switch(key_type)
    {
        case KEY_STAR:
            if(g_cat1023_cntx.h_date == 0)/* current is first, then go to the last */
            {
                  g_cat1023_cntx.h_date = g_cat1023_cntx.date_count - 1;
            }
            else
            {
                  --(g_cat1023_cntx.h_date);
            }
        break;

        case KEY_POUND:
        default:
            if(g_cat1023_cntx.h_date == g_cat1023_cntx.date_count - 1)/* current is last, then go to the first */
            {
                  g_cat1023_cntx.h_date = 0;
            }
            else
            {
                  ++(g_cat1023_cntx.h_date);
            }
        break;
    }

    /* get highlighted tab of highlighted date in history if exist */
    if(g_cat1023_cntx.tab_history != NULL && g_cat1023_cntx.history_size > 0)
    {
        tab = g_cat1023_cntx.tab_history[g_cat1023_cntx.h_date];
    }

    /* set global highlighted tab variable to be the right value */
    g_cat1023_cntx.h_tab = tab;

    wgui_cat1023_control_area_callback(&coord);
    /**/
    wgui_cat1023_redraw_tab_and_list();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_star_key_handler
 * DESCRIPTION
 *  *key handler, it will show the previous date information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_star_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1023_star_pound_key_handler(KEY_STAR);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_pound_key_handler
 * DESCRIPTION
 *  # key handler, it will show next date information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_pound_key_handler(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1023_star_pound_key_handler(KEY_POUND);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_larrow_key_handler
 * DESCRIPTION
 *  left arrow key handler of wgui_cat1023_show, forcus the previous horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_larrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* restore previous list history */
	wgui_cat1023_set_curr_history_node();

    /* caculate the right highlighted tab */
    if(g_cat1023_cntx.h_tab == 0)
    {
        g_cat1023_cntx.h_tab = g_cat_tab_num - 1;
    }
    else
    {
        --(g_cat1023_cntx.h_tab);
    }

    wgui_cat1023_redraw_tab_and_list();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_rarrow_key_handler
 * DESCRIPTION
 *  # key handler, it will show next date information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_rarrow_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* restore previous list history */
	wgui_cat1023_set_curr_history_node();

    /* caculate the right highlighted tab */
    if(g_cat1023_cntx.h_tab == g_cat_tab_num - 1)
    {
        g_cat1023_cntx.h_tab = 0;
    }
    else
    {
        ++(g_cat1023_cntx.h_tab);
    }

    wgui_cat1023_redraw_tab_and_list();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1023_tab_handler
 * DESCRIPTION
 *  # tab handler, it will show selected tab information
 * PARAMETERS
 *  index	:[IN]	selected tab index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1023_tab_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore previous list history */
	wgui_cat1023_set_curr_history_node();
    
    /* set the highlighted tab  */
    (g_cat1023_cntx.h_tab) += index - (S32)MMI_horizontal_tab_bar.focused_item;
    /* update tab and list */
    wgui_cat1023_redraw_tab_and_list();
}

static void wgui_cat1023_button_clearbg_callback(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2;
    icontext_button *b = (icontext_button*)button;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = b->x;
    x2 = b->x + b->width - 1;

#ifdef GDI_USING_LAYER
    gdi_draw_solid_rect(x1, MMI_TITLE_Y, x2, MMI_TITLE_Y + MMI_TITLE_HEIGHT - 1, GDI_COLOR_TRANSPARENT);
#else
    gdi_draw_solid_rect(x1, MMI_TITLE_Y, x2, MMI_TITLE_Y + MMI_TITLE_HEIGHT - 1, GDI_COLOR_WHITE);
#endif
}


static void wgui_cat1023_tab_select_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    /* restore previous list history */
#ifndef __MMI_FTE_SUPPORT__
    if (MMI_horizontal_tab_bar.left_button_pressed == 1)
    {
        wgui_cat1023_larrow_key_handler();
    }
    else if (MMI_horizontal_tab_bar.right_button_pressed == 1)
    {
        wgui_cat1023_rarrow_key_handler();
    }
    else
    {
        wgui_cat1023_tab_handler(index);
    }
#else /* __MMI_FTE_SUPPORT__ */
    wgui_cat1023_tab_handler(index);
#endif /* __MMI_FTE_SUPPORT__ */
}


void wgui_cat1023_show(
           WCHAR* title,
	       PU8 title_icon,
	       WCHAR* left_softkey,
	       PU8 left_softkey_icon,
	       WCHAR* right_softkey,
	       PU8 right_softkey_icon,
	       S32 number_of_dates,
	       WCHAR** date_of_items,
	       S32 highlighted_date,
	       GetCat1023TabItemCount get_tab_count_func,
	       GetCat1023TabItemFuncPtr get_tab_item_func,
	       S32 highlighted_tab,
	       GetCat1023MenuItemCount get_item_count_func,
	       GetCat1023AsyncItemFuncPtr get_item_func,
	       GetCat1023AsyncHintFuncPtr get_hint_func,
	       S32 highlighted_item,
	       U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    S32 i = 0;
    MMI_BOOL ret = MMI_FALSE;
    S32 text_width = 0, text_height;
    U16 btn_prev_item_id = 0, btn_next_item_id = 0;
	list_menu_category_history l_history;
	GetAsyncHintFuncPtr hintFuncPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

    gdi_layer_lock_frame_buffer();
    gui_asyncdynamic_list_error = 0;

    if(history_buffer == NULL)
    {
        /* recorde date information */
        g_cat1023_cntx.date_count = number_of_dates;
        for(i = 0; i < number_of_dates; ++i)
        {
            cat1023_date_text[i] = date_of_items[i];
        }

        /* 
         * initialize category 1023 context variables
         * if goback from history, we will not initialize these context variables
         */
        /* initialize callback functions registered by app */
        g_cat1023_cb_func.get_tab_count_ptr = get_tab_count_func;
        g_cat1023_cb_func.get_tab_items_ptr = get_tab_item_func;
        g_cat1023_cb_func.get_menuitem_count_ptr = get_item_count_func;
        g_cat1023_cb_func.get_menuitems_ptr = get_item_func;
        g_cat1023_cb_func.get_menuitem_hints_ptr = get_hint_func;

        /* initialize highlighted date and tab index */
        g_cat1023_cntx.h_date = highlighted_date;
        g_cat1023_cntx.h_tab = highlighted_tab;
    }
    else
    {
        g_cat1023_cntx.h_tab = g_cat1023_cntx.tab_history[g_cat1023_cntx.h_date];
    }

    /* add screen's title and softkeys */
    dm_add_title((UI_string_type)title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    /* create tab bar */
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    wgui_cat1023_create_tab_bar();

    MMI_fixed_icontext_list_menuitem.flags = 0; 

    /* get menuitem count of current screen */
    g_cat1023_cntx.list_m_count = -1;
    g_cat1023_cb_func.get_menuitem_count_ptr(g_cat1023_cntx.h_date, g_cat1023_cntx.h_tab, &(g_cat1023_cntx.list_m_count));
    MMI_ASSERT(g_cat1023_cntx.list_m_count >= 0);

    if(get_hint_func != NULL)
    {
        hintFuncPtr = wgui_cat1023_get_hint_func_ptr;
    }

	ret = wgui_async_list_create_multi_icontext_menu(
    		g_cat1023_cntx.list_m_count,
    		2,
    		3,
    		wgui_cat1023_get_item_func_ptr,
    		hintFuncPtr,
    		highlighted_item,
    		MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
    		WGUI_LIST_MENU_DISABLE_SHORTCUT,
    		0,
    		NULL);

	
    /* create async dynamic list */
    if(!ret)
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    /* construct list history */
	ret = wgui_cat1023_construct_list_history(&l_history, MMI_CAT1023_ID, g_cat1023_cntx.list_m_count);

    /* set list menu category history */
    if(ret)/* if history construct success, we will set list menu history, else we will only set h_flag to zero */
    {
	    h_flag = set_list_menu_category_history(MMI_CAT1023_ID,(U8 *)&l_history);
    }

    if(!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    /* caculate and set text&icon position in the menuitem */
    text_height = MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1;
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, CAT1008_ICON_WIDTH, text_height);
    set_fixed_icontext_list_icon_coordinates(1, GUI_ICONTEXT_MENUITEM_ICON_X, text_height, CAT1008_ICON_WIDTH, text_height);
	text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT1008_ICON_WIDTH - GUI_MENUITEM_X2_GAP;
	set_fixed_icontext_list_icon_coordinates(2, text_width, 0, CAT1008_ICON_WIDTH, MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);

	text_width = text_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 1, text_width, text_height);
    set_fixed_icontext_list_text_coordinates(1, GUI_ICONTEXT_MENUITEM_TEXT_X, text_height - 1, text_width, text_height);

    /* set text font that of menuitem's text */
#ifdef __MMI_MAINLCD_320X480__
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
#else /* __MMI_MAINLCD_320X480__ */
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
#endif /* __MMI_MAINLCD_320X480__ */

    /* set filler of the menuitem */
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;//menuitem_thick_with_tab_highlight_without_scroll_filler
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;

    /* set list flags */
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_CENTER_ICON_Y | UI_MENUITEM_CENTER_TEXT_Y;

    /* set list to the right place */
    if(g_cat_tab_num > 0)
	{
        wgui_async_list_move_multi_icontext_menu(0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
        wgui_async_list_resize_multi_icontext_menu(MAIN_LCD_DEVICE_WIDTH, MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X, MMI_CONTENT_Y);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT);
    }

    /* add button */
    btn_prev_item_id = dm_add_button(
        NULL,
        get_image(LEFT_RED_ARROW_NORMAL),
        get_image(LEFT_RED_ARROW_PRESSED),
        wgui_cat1023_button_clearbg_callback);
    btn_next_item_id = dm_add_button(
        NULL,
        get_image(RIGHT_RED_ARROW_NORMAL),
        get_image(RIGHT_RED_ARROW_PRESSED),
        wgui_cat1023_button_clearbg_callback);

    dm_get_button(btn_prev_item_id)->flags = UI_BUTTON_DISABLE_BACKGND_DISPLAY;
    dm_get_button(btn_next_item_id)->flags = UI_BUTTON_DISABLE_BACKGND_DISPLAY;

#if defined(__MMI_TOUCH_SCREEN__)
    dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, wgui_cat1023_star_key_handler);
    dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, wgui_cat1023_pound_key_handler);
#endif /*__MMI_TOUCH_SCREEN__*/

    gdi_layer_unlock_frame_buffer();

    /* set draw manager information */
	wgui_cat_setup_category_default_history(MMI_CAT1023_ID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1023_exit);
    dm_register_category_controlled_callback(wgui_cat1023_control_area_callback);

    dm_redraw_category_screen();

    /* register star key and pound key */
    mmi_frm_set_key_handler(wgui_cat1023_star_key_handler, KEY_STAR, KEY_EVENT_UP); /* register '*' key handler */
    mmi_frm_set_key_handler(wgui_cat1023_pound_key_handler, KEY_POUND, KEY_EVENT_UP); /* register  '#' key handler */

    mmi_frm_set_key_handler(wgui_cat1023_larrow_key_handler, KEY_LEFT_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(wgui_cat1023_rarrow_key_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__ 
    wgui_set_horizontal_tab_bar_select_callback(wgui_cat1023_tab_select_callback);
#endif /* __MMI_TOUCH_SCREEN__ */
}


typedef struct
{
	S32 icon_y;
	S32 icon_width;
	S32 icon_height;
	S32 *state;
	GetAsyncItemFuncPtr GetItemFunc;
    FuncPtr ckey_func;
}cat1048_cntx;


static cat1048_cntx g_cat1048_cntx;


/*****************************************************************************
* FUNCTION
*  DrawCate1048CategoryControlAreaBackground
* DESCRIPTION
*  draw control area background for cat1048
* PARAMETERS
*  x1	[IN]
*  y1	[IN]
*  x2	[IN]
*  y2	[IN]
* RETURNS
*  void
*****************************************************************************/
static void DrawCate1048CategoryControlAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color = gdi_act_color_from_rgb(255, 48, 48, 48);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
    gui_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_get_checkbox_area
* DESCRIPTION
*  get rect of checkbox button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_get_checkbox_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_measure_image(get_image(CHECKBOX_OFF_IMAGE_ID), &g_cat1048_cntx.icon_width, &g_cat1048_cntx.icon_height);
    g_cat1048_cntx.icon_y = (CAT1048_INFO_AREA_H - g_cat1048_cntx.icon_height)/2;
    g_cat1048_cntx.icon_y += CAT1048_INFO_AREA_Y;
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_draw_checkbox
* DESCRIPTION
*  draw the checkbox button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_draw_checkbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id = CHECKBOX_OFF_IMAGE_ID;
    S32 x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*g_cat1048_cntx.state == 1)
    {
        icon_id = CHECKBOX_ON_IMAGE_ID;
    }

    x2 = GUI_ICONTEXT_MENUITEM_ICON_X + g_cat1048_cntx.icon_width;
    y2 = g_cat1048_cntx.icon_y + g_cat1048_cntx.icon_height;
    gdi_layer_lock_frame_buffer();
    gui_push_clip();
    gui_set_clip(GUI_ICONTEXT_MENUITEM_ICON_X, g_cat1048_cntx.icon_y, x2, y2);
    gdi_image_draw(GUI_ICONTEXT_MENUITEM_ICON_X, g_cat1048_cntx.icon_y, get_image(icon_id));
    gui_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(GUI_ICONTEXT_MENUITEM_ICON_X, g_cat1048_cntx.icon_y, x2, y2);
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_star_key_handler
* DESCRIPTION
*  the function handler for star key
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_star_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*g_cat1048_cntx.state == 1)
    {
        *g_cat1048_cntx.state = 0;
    }
    else
    {
        *g_cat1048_cntx.state = 1;
    }
    wgui_cat1048_draw_checkbox();
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  wgui_cat1048_pen_down_hdlr
* DESCRIPTION
*  the function handler for pen down control area rect
* PARAMETERS
*  point		[IN]	the point postion at control area rect
* RETURNS
*  whether parse this action
*****************************************************************************/
static MMI_BOOL wgui_cat1048_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__)
    x = MMI_SUBMENU_CONTENT_X;
    y = CAT1048_INFO_AREA_Y;
    w = MMI_SUBMENU_CONTENT_WIDTH;
    h = CAT1048_INFO_AREA_H;
#else /* __MMI_FTE_SUPPORT__ */
    x = GUI_ICONTEXT_MENUITEM_ICON_X;
    y = g_cat1048_cntx.icon_y;
    w = g_cat1048_cntx.icon_width;
    h = g_cat1048_cntx.icon_height;
#endif /* __MMI_FTE_SUPPORT__ */

    if (PEN_CHECK_BOUND(point.x, point.y, x, y, w, h))
    {
        wgui_cat1048_star_key_handler();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_draw_control_area
* DESCRIPTION
*  the function handler for draw control area
* PARAMETERS
*  coordinate		[IN]	the point postion at control area rect
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_draw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;
#if defined(__MMI_UI_LIST_GRID_LINE__)
    gdi_handle alpha_layer;
    color grid_line = gui_color32(198, 198, 198, 255);
#endif /* __MMI_UI_LIST_GRID_LINE__ */
    gdi_color bg_color = gdi_act_color_from_rgb(255, 48, 48, 48);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = coordinate->s16X;
    x2 = coordinate->s16X + coordinate->s16Width;
    y1 = coordinate->s16Y;
    y2 = coordinate->s16Y + coordinate->s16Height;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
#if defined(__MMI_UI_LIST_GRID_LINE__)
    gdi_layer_get_active(&alpha_layer);
    gdi_effect_alpha_blending_rect(alpha_layer,
        x1, y1, x2, (y1+1),
        grid_line.alpha, grid_line.r, grid_line.g, grid_line.b);
    y1 = y1 + 1;
#endif /* __MMI_UI_LIST_GRID_LINE__*/
    gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
    gui_pop_clip();
    wgui_cat1048_draw_checkbox();
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_exit
* DESCRIPTION
*  the exit function for cat1048
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    memset((char*)&g_cat1048_cntx, 0, sizeof(cat1048_cntx));
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_get_item
* DESCRIPTION
*  the function for get item data(icon and text)
* PARAMETERS
*  start_index		[IN]	the start index for user's data
*  menu_data		[IN]	the buffer of item data
*  data_size		[IN]	the range from start index
* RETURNS
*  the number of items got
*****************************************************************************/
static S32 wgui_cat1048_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number, index;
    PU8 unsel_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number = g_cat1048_cntx.GetItemFunc(start_index, menu_data, data_size);
    unsel_icon = get_image(RADIO_OFF_IMAGE_ID);

    for (index = 0; index < number; index++)
    {
        if (MMI_fixed_list_menu.highlighted_item == (start_index + index))
        {
            menu_data[index].image_list[0] = get_image(RADIO_ON_IMAGE_ID);
        }
        else
        {
            menu_data[index].image_list[0] = unsel_icon;
        }
    }
    return number;
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_highlight_handler
* DESCRIPTION
*  the function for highlight current item
* PARAMETERS
*  item_index		[IN]	the index of current item
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_type *menuitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menuitem = get_asyncdynamic_item_from_buffer(item_index);
    menuitem->item_icons[0] = get_image(RADIO_ON_IMAGE_ID);
    asyncdynamic_list_highlight_handler(item_index);
}


/*****************************************************************************
* FUNCTION
*  wgui_cat1048_unhighlight_handler
* DESCRIPTION
*  the function for unhighlight current item
* PARAMETERS
*  item_index		[IN]	the index of current item
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1048_unhighlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem_type *menuitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < asyncdynamic_item_buffer.head_item_index)
    {
        return ;
    }
    if ((item_index - asyncdynamic_item_buffer.head_item_index) > 
        asyncdynamic_item_buffer.count)
    {
        return ;
    }
    menuitem = get_asyncdynamic_item_from_buffer(item_index);
    menuitem->item_icons[0] = get_image(RADIO_OFF_IMAGE_ID);
}


/*****************************************************************************
 * FUNCTION
 *  GetCat1048HistorySize
 * DESCRIPTION
 *  Get category1048 history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  the size of history buffer
 *****************************************************************************/
static S32 wgui_cat1048_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((sizeof(list_menu_category_history) + 3) & (~3)) + sizeof(multiline_inputbox_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_get_history
 * DESCRIPTION
 *  Get category1048 history.
 * PARAMETERS
 *  history_buffer      [OUT]        History buffer
 * RETURNS
 *  hitsory buffer
 *****************************************************************************/
static U8 *wgui_cat1048_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CAT1048_ID, history_buffer);
    offset = (sizeof(list_menu_category_history) + 3) & (~3);
    wgui_inputs_ml_get_category_history(MMI_CAT1048_ID, (U8*)(history_buffer + offset));
    return (history_buffer);
}


#if defined(__MMI_FTE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_background_callback
 * DESCRIPTION
 *  show center key background
 * PARAMETERS
 *  button		[IN]		center button object
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_ckey_background_callback(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button backup_center_btn;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((CHAR*)&backup_center_btn, (CHAR*)&MMI_softkeys[MMI_CENTER_SOFTKEY], sizeof(icontext_button));
    memcpy((CHAR*)&MMI_softkeys[MMI_CENTER_SOFTKEY], (CHAR*)button, sizeof(icontext_button));
    wgui_softkey_oem_hide(MMI_CENTER_SOFTKEY);
    memcpy((CHAR*)&MMI_softkeys[MMI_CENTER_SOFTKEY], (CHAR*)&backup_center_btn, sizeof(icontext_button));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_pen_handler
 * DESCRIPTION
 *  handler center button event according to flags
 * PARAMETERS
 *  btn_object		[IN]		center button object
 *  flags			[IN]		1 = show button when down, 
 *						2 = show button when up, 
 *						3 show first
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_ckey_pen_handler(void *btn_object, S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE targer_layer, abm_layer;
    icontext_button *b = (icontext_button*)btn_object;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    targer_layer = wgui_softkey_get_target_layer();
    abm_layer = wgui_softkey_get_abm_layer();
    
    if (targer_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_push_and_set_active(targer_layer);
    }
    if (abm_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(abm_layer);
    }

    switch(flags)
    {
        case 1 :
            gui_icontext_button_show_down_by_pen((void*)b);
            break;
        case 2 :
            gui_icontext_button_show_up_by_pen((void*)b);
            break;
        case 3 :
            gui_show_icontext_button(b);
			break;
        default :
        break;
    }
    
    if (abm_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    if (targer_layer != GDI_NULL_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_pen_down
 * DESCRIPTION
 *  draw center button when down event
 * PARAMETERS
 *  button_object		[IN]		center button object
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1048_ckey_pen_down(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1048_ckey_pen_handler(button_object, 1);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_pen_up
 * DESCRIPTION
 *  draw center button when up event
 * PARAMETERS
 *  button_object		[IN]		center button object
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1048_ckey_pen_up(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1048_ckey_pen_handler(button_object, 2);
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_up_func
 * DESCRIPTION
 *  center key function for touch button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_ckey_up_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat1048_cntx.ckey_func)
    {
        g_cat1048_cntx.ckey_func();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_register_ckey_func
 * DESCRIPTION
 *  register center key function
 * PARAMETERS
 *  cb		[IN]		center key function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1048_register_ckey_func(FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat1048_cntx.ckey_func = cb;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_down
 * DESCRIPTION
 *  draw center button when down key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_ckey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = dm_get_button(0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(b->flags & UI_BUTTON_STATE_CLICKED))
    {
        wgui_cat1048_ckey_background_callback((void*)b);
        wgui_cat1048_ckey_pen_handler((void*)b, 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_ckey_up
 * DESCRIPTION
 *  draw center button when up key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_ckey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = dm_get_button(0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->flags & UI_BUTTON_STATE_CLICKED)
    {
        wgui_cat1048_ckey_background_callback((void*)b);
        wgui_cat1048_ckey_pen_handler((void*)b, 2);
        if (g_cat1048_cntx.ckey_func)
        {
            g_cat1048_cntx.ckey_func();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_setup_and_draw_button_bar
 * DESCRIPTION
 *  This function is used setup the button bar for 3 softkey and then draw it
 * PARAMETERS
 *  center_button_id		[IN]		center button string id
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1048_setup_and_draw_button_bar(U16 center_button_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y, button_width, left_gap, right_gap;
    U16 btn_id;
    icontext_button *b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (center_button_id == 0)
    {
        dm_add_button(0, 0, 0, 0);
        return ;
    }
    y = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT;
    button_width = MAIN_LCD_DEVICE_WIDTH / 3;
    right_gap = MAIN_LCD_DEVICE_WIDTH - (button_width * 3);
    left_gap = right_gap / 2;
    right_gap = right_gap - left_gap;
    
    set_button_bar_height(MMI_BUTTON_BAR_HEIGHT);
    show_softkey_background();
    
    /* left */
    move_softkey(left_gap, y, MMI_LEFT_SOFTKEY);
    resize_softkey(button_width, MMI_BUTTON_BAR_HEIGHT, MMI_LEFT_SOFTKEY);
    show_softkey(MMI_LEFT_SOFTKEY);
    
    /* right */
    move_softkey(MAIN_LCD_DEVICE_WIDTH - right_gap - button_width, y, MMI_RIGHT_SOFTKEY);
    resize_softkey(button_width, MMI_BUTTON_BAR_HEIGHT, MMI_RIGHT_SOFTKEY);
    show_softkey(MMI_RIGHT_SOFTKEY);
    
    /* center */
    btn_id = dm_add_button((UI_string_type)GetString(center_button_id), 0, 0, 0);
    dm_move_button(btn_id, left_gap + button_width, y);
    dm_resize_button(btn_id, button_width, MMI_BUTTON_BAR_HEIGHT);
    b = dm_get_button(btn_id);
    b->horizontal_gap = MMI_softkeys[MMI_LEFT_SOFTKEY].horizontal_gap;
    b->flags = MMI_softkeys[MMI_LEFT_SOFTKEY].flags;
    b->clear_background_fp = wgui_cat1048_ckey_background_callback;
#ifdef __MMI_TOUCH_SCREEN__
    gui_icontext_button_overwirte_pen_response_area(b, b->x, b->y, b->x + b->width - 1, b->y + b->height - 1);
    b->draw_down_fp = wgui_cat1048_ckey_pen_down;
    b->draw_up_fp = wgui_cat1048_ckey_pen_up;
#endif
    dm_register_button_functions(btn_id, KEY_EVENT_UP, wgui_cat1048_ckey_up_func);
	mmi_frm_set_key_handler(wgui_cat1048_ckey_down, KEY_ENTER, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(wgui_cat1048_ckey_up, KEY_ENTER, KEY_EVENT_UP);
    wgui_cat1048_ckey_pen_handler((void*)b, 3);
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1048_show
 * DESCRIPTION
 *  Async Dynamic List menu category for cat1048
 * PARAMETERS
 *  title                   [IN] Char array of title
 *  title_icon              [IN] Byte array of title icon
 *  left_softkey            [IN] String ID of left softkey
 *  center_softkey		[IN] String ID of center softkey
 *  right_softkey           [IN] String ID of right softkey
 *  info_message            [IN] Char array of information message
 *  state				[IN]	the state for checkbox
 *  number_of_items         [IN] Number of items of list
 *  get_item_func           [IN] Get item function pointer
 *  get_hint_func           [IN] Get hint function pointer
 *  highlighted_item        [IN] Currently highlighted item
 *  history_buffer          [IN] History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1048_show(
			PU8 title,
			PU8 title_icon,
			U16 left_softkey,
			U16 center_softkey,
			U16 right_softkey,
			PU8 info_message,
			S32 *state,
			S32 number_of_items,
			GetAsyncItemFuncPtr get_item_func,
			GetAsyncHintFuncPtr get_hint_func,
			S32 highlighted_item,
			U8 *history_buffer,
			S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
    S32 width, height, len;
    dm_data_struct dm_data;
	UI_string_type text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    UI_UNUSED_PARAMETER(center_softkey);
#endif /* __MMI_FTE_SUPPORT__*/
    gdi_layer_lock_frame_buffer();
    *category_error_flag = 1;

    gui_asyncdynamic_list_error = 0;

	dm_add_softkey((UI_string_type) GetString((U16)left_softkey), 
				NULL ,
				(UI_string_type) GetString((U16)right_softkey), 
				NULL);

    len = gui_strlen((UI_string_type) title);
    create_multiline_inputbox_set_buffer((UI_string_type) title, len, len, 0);
	gui_set_multi_line_input_box_default_bg_color(
		&MMI_multiline_inputbox,
		gui_color(48, 48, 48),
		MMI_TRUE);
	MMI_multiline_inputbox.normal_text_color = gui_color(255, 255, 255);
	MMI_multiline_inputbox.flags |= \
		UI_MULTI_LINE_INPUT_BOX_AUTO_VERTICAL_SCROLL	\
		| UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW	\
		| UI_MULTI_LINE_INPUT_BOX_VIEW_MODE		\
		| UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
    if (history_buffer)
    {
        S32 offset;
        offset = (sizeof(list_menu_category_history) + 3) & (~3);
        set_multiline_inputbox_category_history(MMI_CAT1048_ID, (U8*)(history_buffer + offset));
    }

    /* create a multi icon-text list */
    g_cat1048_cntx.GetItemFunc = get_item_func;
    if(!(wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            1,
            1,
            wgui_cat1048_get_item,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            MMI_MENUITEM_HEIGHT,
            0,
            0,
            NULL)))
    {
        gdi_layer_unlock_frame_buffer();
        return;
    }

    /* set histoty of list */
    h_flag = set_list_menu_category_history(MMI_CAT1048_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

    gui_measure_image(get_image(RADIO_ON_IMAGE_ID), &width, &height);
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, width, MMI_MENUITEM_HEIGHT);
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    width = MMI_content_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X;
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, width, MMI_MENUITEM_HEIGHT);

    register_fixed_list_highlight_handler(wgui_cat1048_highlight_handler);
    register_fixed_list_unhighlight_handler(wgui_cat1048_unhighlight_handler);

    g_cat1048_cntx.state = NULL;
    text = NULL;
    len = CAT1048_MENU_HEIGHT + CAT1048_INFO_AREA_H;
    if (state)
    {
        g_cat1048_cntx.state = state;
        wgui_cat1048_get_checkbox_area();
        text = (UI_string_type)info_message;
    #if defined(__MMI_TOUCH_SCREEN__)
        wgui_register_category_screen_control_area_pen_handlers(wgui_cat1048_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    #endif /* __MMI_TOUCH_SCREEN__ */
        mmi_frm_set_key_handler(wgui_cat1048_star_key_handler, KEY_STAR, KEY_EVENT_UP);
        len = CAT1048_MENU_HEIGHT;
    }

    dm_add_scroll_text(
        text,
        NULL,
        DrawCate1048CategoryControlAreaBackground,
        *current_MMI_theme->list_normal_text_color,
        gui_color(255, 255, 255));

	wgui_async_list_move_multi_icontext_menu(MMI_SUBMENU_CONTENT_X, CAT1048_MENU_Y);
	wgui_async_list_resize_multi_icontext_menu(MMI_SUBMENU_CONTENT_WIDTH, len);

    *category_error_flag = 0;

    ExitCategoryFunction = wgui_cat1048_exit;

    dm_setup_category_functions(
		dm_redraw_category_screen,
		wgui_cat1048_get_history,
		wgui_cat1048_get_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT1048_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(NULL);
    if (state)
    {
    dm_register_category_controlled_callback(wgui_cat1048_draw_control_area);
    }
    dm_redraw_category_screen();
#ifdef __MMI_FTE_SUPPORT__
    wgui_cat1048_setup_and_draw_button_bar(center_softkey);
#endif /* __MMI_FTE_SUPPORT__ */
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1050_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1050_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1050_post_display_menuitem
 * DESCRIPTION
 *  show icontext list menuitem for cat1050
 * PARAMETERS
 *  item						[IN]        fixed_icontext_list_menuitem_type
 *  common_item_data			[IN]        fixed_icontext_list_menuitem
 *  x							[IN]		
 *  y							[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1050_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    UI_string_type _text;
    color text_color;
	UI_font_type text_font;
    gui_text_frame_struct t;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _text = mi->item_texts[0];
	/* get text font */
    if ((mi->flags & UI_MENUITEM_STATE_FOCUSSED) && (m->selected_fonts[0]))
    {
        text_font = m->selected_fonts[0];
    }
    else
    {
        text_font = m->text_fonts[0];
    }

	/* get text color */
    if (mi->flags & UI_MENUITEM_STATE_FOCUSSED)
    {
        text_color = m->focussed_text_colors[0];
    }
    else
    {
        text_color = m->normal_text_colors[0];
    }

    /* draw text */
    gui_text_frame_create(
    	&t,
    	(x + m->text_coordinates[0].x), 
    	(y + m->text_coordinates[0].y), 
    	m->text_coordinates[0].width,
    	m->text_coordinates[0].height,
    	_text,
    	text_font,
    	text_color,
    	0);
    gui_text_frame_show(&t);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1050_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for single large text
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items         [IN]        Number of items in the menu
 *  get_item_func           [IN]        function for get item string and icon
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 *  category_error_flag		[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1050_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U8 *history_buffer,
                S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 w, h, text_fh;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gui_asyncdynamic_list_error = 0;
    dm_add_softkey(
        (UI_string_type)GetString(left_softkey),
        0,
        (UI_string_type)GetString(right_softkey),
        0);
    dm_add_title((UI_string_type) title, title_icon);
    
    if (!wgui_async_list_create_multi_icontext_menu(
            number_of_items,
            1,
            1,
            get_item_func,
            NULL,
            WGUI_LIST_INVALID_HIGHLIGHT,
            MMI_MULTIROW_MENUITEM_HEIGHT,
            WGUI_LIST_MENU_MULTIROW,
            0,
            NULL))
    {
        gdi_layer_unlock_frame_buffer();
        return ;
    }
        
    if (!set_list_menu_category_history(MMI_CAT1050_ID, history_buffer))
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY;
    
    h = Get_CharHeightOfAllLang(MEDIUM_FONT);
    h += h;
    text_fh = (MMI_MULTIROW_MENUITEM_HEIGHT - h)/2;
    
    w = MMI_content_width - GUI_ICONTEXT_MENUITEM_ICON_X - CAT1008_ICON_WIDTH - 2 - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_TEXT_RIGHT_GAP;
    
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X + CAT1008_ICON_WIDTH + 2, text_fh, w, h);

	set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, CAT1008_ICON_WIDTH, MMI_MULTIROW_MENUITEM_HEIGHT);
    
    set_fixed_icontext_list_menuitems_post_display(wgui_cat1050_post_display_menuitem);
    
    wgui_async_list_move_multi_icontext_menu(MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y);
    wgui_async_list_resize_multi_icontext_menu(MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT);

    ExitCategoryFunction = wgui_cat1050_exit;
	
    dm_setup_category_functions(
		dm_redraw_category_screen,
		dm_get_category_history,
		dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CAT1050_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

#endif /*__MMI_MOBILE_TV_CMMB_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  ExitCategory427Screen
 * DESCRIPTION
 *  Exit the category427 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory427Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory427Screen_int
 * DESCRIPTION
 *  Displays the category427 screen for multi-download list
 *  
 *  1. Each menu item has three text strings: name(scrolling) [0], percentage [1], and size [2].
 *  2. Each menu item has one image icons: state of this item [0].
 *  An empty icon can be set as NULL in 'get_item_func'
 * 
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title string
 *   title_icon                    : [IN ] (N/A) Title icon
 *   left_softkey                  : [IN ] (LSK) Left softkey string
 *   right_softkey                 : [IN ] (RSK) Right softkey string
 *   number_of_items               : [IN ] (N/A) Number of menu items
 *   get_item_func                 : [IN ] (C427_1,C427_2,C427_3) Callback function to get menu text.
 *   highlighted_item              : [IN ] (N/A) Default highlighted menu item
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory427Screen_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 var0, var1, var2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();    /* in order let APP to refresh quickly, we block this effect */
#endif 

    gdi_layer_lock_frame_buffer();

    wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    gui_asyncdynamic_list_error = 0;  

    /* set list */
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        3,
        1,
        get_item_func,
        NULL,
        highlighted_item,
        (MMI_MENUITEM_HEIGHT << 1),
        0,
        MMI_CATEGORY427_ID,
        history_buffer);
    
    /* set icon-text-list */
    MMI_fixed_icontext_list_menuitem.flags |=
        UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_DOTTED_UNDERLINE | UI_MENUITEM_RIGHT_JUSTIFY_COL2;
    
    /* compute string width */
    {
        U16 temp[] = L"0123456789K/%";
        gui_set_font(&MMI_small_font);
        mmi_fe_measure_string_by_char_num((U8*)temp, 4/* text1 can only show 4 characters, eg. 100% */, &var1, &var0);
		var0 = MMI_fixed_icontext_list_menuitem.width - GUI_TEXT_MENUITEM_TEXT_X * 3;/* gap */

        /* text2 can only show 10 characters, eg. 9999/9999K */
        var2 = var0 - var1;

        /* may need error control about text width */
        var0 = var0 - MMI_MENUITEM_HEIGHT /* icon widh */;
    }

    /* set item position */
    set_fixed_icontext_list_text_coordinates(0, /* name */
        GUI_TEXT_MENUITEM_TEXT_X, 2 /* gap */,
        var0, MMI_MENUITEM_HEIGHT);
	var0 = MMI_fixed_icontext_list_menuitem.width - GUI_TEXT_MENUITEM_TEXT_X;
    set_fixed_icontext_list_text_coordinates(1, /* percentage */
        var0 - var1, MMI_MENUITEM_HEIGHT + 2 /* gap */,
        var1, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(2, /* size */
        GUI_TEXT_MENUITEM_TEXT_X, MMI_MENUITEM_HEIGHT + 2 /* gap */,
        var2, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, /* state icon */
        var0 - MMI_MENUITEM_HEIGHT /* icon width */ + 2 /* gap */, 2 /* gap */,
        MMI_MENUITEM_HEIGHT, MMI_MENUITEM_HEIGHT);
    
    /* override menu item style */
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;

    MMI_ASSERT(!gui_asyncdynamic_list_error);
    
    gdi_layer_unlock_frame_buffer();

    /* Setup category/draw manager data */
	wgui_cat_setup_category_default_history(MMI_CATEGORY427_ID, 0, ExitCategory427Screen);
    dm_redraw_category_screen();
}


/*
 * Cascading Menu CATEGORY 800
 */
//#define MMI_CASCADING_MENU_FIXED_WIDTH
static S32 g_mmi_category800_previous_menu_x1, g_mmi_category800_previous_menu_x2;
static S32 g_mmi_category800_previous_menu_y1;
static void (*mmi_cat800_hide_softkey) (WGUI_SOFTKEY_ENUM softkey_type) = NULL;
static MMI_BOOL cm_is_not_displayed_by_menu_cui = MMI_FALSE;

typedef struct {
	S32 menu_x;
	S32 menu_y;
	S32 menu_width;
	S32 max_menu_width;
	S32 max_item_text_width;
	MMI_BOOL show_submenu_indicator;

}cascading_position_values;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_set_width_for_first_level
 * DESCRIPTION
 *  original caculate width and height for first level.
 * PARAMETERS
 *  param              [IN/OUT]    menu information pointer
 *  is_rotated		[IN]		whether is rotated screen
 *  show_scrollbar     [IN]        Judge show scrollbar or not
 *  arrow_width        [IN]        arrow image width
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_set_width_for_first_level(
					cascading_position_values *param,
					MMI_BOOL is_rotated,
					MMI_BOOL show_scrollbar,
					S32 arrow_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 var = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    param->menu_x = CASCADING_MENU_BORDER_SIZE;
#else /* __MMI_FTE_SUPPORT__ */
    param->menu_x = CASCADING_MENU_FIRST_LEVEL_X_OFFSET;		
#endif /* __MMI_FTE_SUPPORT__ */
    
    /* force bottom aligned */
    param->menu_y = UI_device_height;

    if (!is_rotated)
    {
        /* set menu width is the device width if from right to left show */
        param->menu_width = UI_device_width - ((param->menu_x) << 1) - 1;
    }
    else
    {
        if (mmi_fe_get_r2l_state())
        {
            /* set menu width is the device width if from right to left show */
            param->menu_width = UI_device_width - CASCADING_MENU_FIRST_LEVEL_X_OFFSET - CASCADING_MENU_BORDER_SIZE * 2;
        }
        else
        {
            /* set menu width according max width between max text width and device width */
            param->menu_width = param->max_item_text_width + GUI_MENUITEM_X1_GAP + GUI_MENUITEM_X2_GAP * 2+ 
                CASCADING_MENU_FIRST_LEVEL_X_OFFSET + arrow_width + 
                CASCADING_MENU_TEXT_LEFT_GAP + CASCADING_MENU_TEXT_RIGHT_GAP;
            param->show_submenu_indicator = MMI_FALSE;
            if (show_scrollbar)    
            {
                param->menu_width += MMI_fixed_list_menu.vbar.width;
            }
            param->max_menu_width = UI_device_width - CASCADING_MENU_FIRST_LEVEL_X_OFFSET - CASCADING_MENU_BORDER_SIZE * 2;
            var = arrow_width + CASCADING_MENU_ARROW_TO_TEXT_GAP;
            if (param->menu_width > param->max_menu_width)
            {
                param->menu_width = param->max_menu_width;
            }
        }
    }
        
    param->max_menu_width = param->menu_width;
    
    /* consider menu x1 and x2 gap */
    param->max_item_text_width = param->menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - var; 
    
    if (show_scrollbar) 	   
    {
        param->max_item_text_width -= MMI_fixed_list_menu.vbar.width;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_set_width_for_second_level
 * DESCRIPTION
 *  original caculate width and height for second level.
 * PARAMETERS
 *  param              [IN/OUT]    menu information pointer
 *  is_rotated		[IN]		whether is rotated screen
 *  show_scrollbar     [IN]        Judge show scrollbar or not
 *  arrow_width        [IN]        arrow image width
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_set_width_for_second_level(
					cascading_position_values *param,
					MMI_BOOL is_rotated,
					MMI_BOOL show_scrollbar,
					S32 arrow_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param->max_item_text_width += CASCADING_MENU_TEXT_LEFT_GAP + CASCADING_MENU_TEXT_RIGHT_GAP + GUI_MENUITEM_X2_GAP * 2;
    
    if (is_rotated)
    {
        param->max_menu_width = UI_device_width - CASCADING_MENU_BORDER_SIZE * 4 - CASCADING_MENU_SHADOW_DEPTH - MMI_SOFTKEY_WIDTH;
    }
    else
    {
        param->max_menu_width = (UI_device_width<<1)/3;
    }
    /* the second level indicator is radio box for cat802 */
    if(param->show_submenu_indicator)
    {
        param->menu_width = param->max_item_text_width + GUI_ICONTEXT_MENUITEM_TEXT_X + GUI_MENUITEM_TEXT_RIGHT_GAP + GUI_MENUITEM_X1_GAP + GUI_MENUITEM_X2_GAP * 2;
    }
    else
    {
        param->menu_width = param->max_item_text_width + GUI_MENUITEM_X1_GAP + GUI_MENUITEM_X2_GAP * 2;
    }
    
    if (show_scrollbar)
    {
        param->menu_width += MMI_fixed_list_menu.vbar.width;
    }
    
    if (param->menu_width > param->max_menu_width)
    {
        param->menu_width = param->max_menu_width;
        if(param->show_submenu_indicator)
        {
            param->max_item_text_width = param->menu_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        }
        else
        {
            param->max_item_text_width = param->menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        }
        if (show_scrollbar)
        {
            param->max_item_text_width -= MMI_fixed_list_menu.vbar.width;
        }
    }
    
    if (mmi_fe_get_r2l_state())
    {  
        /* R2L, left-aligned */
        param->menu_x = CASCADING_MENU_BORDER_SIZE;
        if (is_rotated)
        {
            if(param->menu_x + param->menu_width - 1 < g_mmi_category800_previous_menu_x1)
            {
                param->menu_x = g_mmi_category800_previous_menu_x1 - param->menu_width;
            }
        }
    }
    else
    { 
        /* L2R, right-aligned */
        if (is_rotated)
        {
            param->menu_x = UI_device_width - param->menu_width - CASCADING_MENU_BORDER_SIZE * 2
                - CASCADING_MENU_SHADOW_DEPTH - MMI_SOFTKEY_WIDTH;
            
            if(param->menu_x > g_mmi_category800_previous_menu_x2)
            {
                param->menu_x = g_mmi_category800_previous_menu_x2 + 3;
            }
        }
        else
        {
        #ifdef __MMI_FTE_SUPPORT__
            param->menu_x = UI_device_width - param->menu_width - CASCADING_MENU_BORDER_SIZE - 1;
        #else /* __MMI_FTE_SUPPORT__ */
            param->menu_x = UI_device_width - param->menu_width - CASCADING_MENU_FIRST_LEVEL_X_OFFSET - 1;	  
        #endif /* __MMI_FTE_SUPPORT__ */
        }
    }
    
    param->menu_y = g_mmi_category800_previous_menu_y1 + CASCADING_MENU_SECOND_LEVEL_Y_OFFSET;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cascading_menu_darken_full_screen
 * DESCRIPTION
 *  darken the previous full screen when show cascading menu first level.
 * PARAMETERS
 *  current_cm_level           [IN]    level of cacading menu
 *  is_rotated                 [IN]    screen is rotate of not, TRUE is rotate
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cascading_menu_darken_full_screen(S32 current_cm_level, MMI_BOOL is_rotated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (current_cm_level == 0)
    {
        if(is_rotated)
        {      
            if(mmi_cat800_hide_softkey == NULL)
            {
                gdi_draw_darken_rect(0, 0, UI_device_width - 1, UI_device_height - 1, 20);
                return ;
            }
        }
        gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, 0, 0);
    }
}


void wgui_cm_set_display_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cm_is_not_displayed_by_menu_cui = MMI_TRUE;
}

void wgui_cm_reset_display_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cm_is_not_displayed_by_menu_cui = MMI_FALSE;
}

MMI_BOOL wgui_cm_is_not_displayed_by_menu_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    return cm_is_not_displayed_by_menu_cui;
}

#if (!defined(__MMI_CASCADING_MENU_ROUNDED_BORDER__) && !defined(__MMI_FTE_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  DrawCategory800Shadow
 * DESCRIPTION
 *  Draws a shadow border for the cascading menu.
 * PARAMETERS
 *  shadow_x1           [IN]    x1
 *  shadow_y1           [IN]    y1
 *  shadow_width        [IN]    width
 *  shadow_height       [IN]    height
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCategory800Shadow(S32 shadow_x1, S32 shadow_y1, S32 shadow_width, S32 shadow_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 shadow_depth = CASCADING_MENU_SHADOW_DEPTH;
    S32 shadow_offset = CASCADING_MENU_SHADOW_OFFSET;
    S32 shadow_alpha_start = CASCADING_MENU_SHADOW_ALPHA_START;
    S32 shadow_alpha_end = CASCADING_MENU_SHADOW_ALPHA_END;
    S32 shadow_alpha_step;
    S32 shadow_alpha;
    gdi_handle  active_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_active(&active_layer);

    shadow_alpha = shadow_alpha_start;

    if (shadow_depth == 1)
    {
        shadow_alpha_step = 0;
    }
    else
    {
        shadow_alpha_step = (shadow_alpha_end - shadow_alpha_start) / (shadow_depth - 1);
    }
 
    for (i = 0; i < shadow_depth; i++)
    {
        /* bottom shadow */
        gdi_effect_alpha_blending_rect(
            active_layer, 
            shadow_x1 + shadow_offset, 
            shadow_y1 + shadow_height + i, 
            shadow_x1 + shadow_width + i, 
            shadow_y1 + shadow_height + i,
            shadow_alpha, 
            0, 
            0, 
            0);
            
        /* right shadow */
        gdi_effect_alpha_blending_rect(
            active_layer, 
            shadow_x1 + shadow_width + i, 
            shadow_y1 + shadow_offset, 
            shadow_x1 + shadow_width + i, 
            shadow_y1 + shadow_height - 1 + i,
            shadow_alpha, 
            0, 
            0, 
            0);            

        shadow_alpha += shadow_alpha_step;
    }
}

#endif /* !define(__MMI_CASCADING_MENU_ROUNDED_BORDER__) && !define(__MMI_FTE_SUPPORT__) */

extern S32 g_mmi_cascading_menu_current_level;
static void wgui_show_shadow_in_first_level(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_cat800_hide_lsk
 * DESCRIPTION
 *  Draws the LSK background.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cat800_hide_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cat800_hide_softkey(MMI_LEFT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat800_hide_csk
 * DESCRIPTION
 *  Draws the CSK background.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cat800_hide_csk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cat800_hide_softkey(MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat800_hide_rsk
 * DESCRIPTION
 *  Draws the RSK background.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cat800_hide_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cat800_hide_softkey(MMI_RIGHT_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_register_hide_keys
 * DESCRIPTION
 *  register hide keys.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_register_hide_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     /* 
        * Register softkey hide function to recover the old softkey background.
        * There is no CSK because the cascading menu does not support CSK yet.
        */
    if (mmi_cat800_hide_softkey)
    {
        register_hide_softkey(mmi_cat800_hide_lsk, MMI_LEFT_SOFTKEY);
        register_hide_softkey(mmi_cat800_hide_csk, MMI_CENTER_SOFTKEY);
        register_hide_softkey(mmi_cat800_hide_rsk, MMI_RIGHT_SOFTKEY);
    }
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_restore_softkey_bkg
 * DESCRIPTION
 *  Restores the softkey background if the new screen is a cascading menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat800_restore_softkey_bkg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_cat800_hide_softkey = NULL;
}



void wgui_cascading_menu_register_hide_softkey(void (*f) (WGUI_SOFTKEY_ENUM))
{
    mmi_cat800_hide_softkey = f;
}


typedef struct{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
}wgui_cm_first_level_ps;

static wgui_cm_first_level_ps cm_ps = {0, 0, 0, 0};

static void wgui_reset_cm_first_level_ps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    cm_ps.x1 = 0;
    cm_ps.y1 = 0;
    cm_ps.x2 = 0;
    cm_ps.y2 = 0;   
}


static void wgui_set_cm_first_level_ps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifndef __MMI_CASCADING_MENU_ROUNDED_BORDER__
    cm_ps.x1 = MMI_fixed_list_menu.x;
    cm_ps.y1 = MMI_fixed_list_menu.y;
    cm_ps.x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1;
    cm_ps.y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
#else /* __MMI_CASCADING_MENU_ROUNDED_BORDER__ */
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /*__MMI_OP11_HOMESCREEN__*/
    cm_ps.x1 = MMI_fixed_list_menu.x - 2;
    cm_ps.y1 = MMI_fixed_list_menu.y - 10;
    cm_ps.x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width + 2;
    cm_ps.y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height + 10;
#endif /*__MMI_OP11_HOMESCREEN__*/
#endif /* __MMI_CASCADING_MENU_ROUNDED_BORDER__ */
}

static void draw_first_level_shadow(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    // TODO: NEED THE NEW DARKEN METHOD
    /* darken the full screen again to work around a popup over a cascading menu which is not darkened */
#ifdef __MMI_OP11_HOMESCREEN__
#if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
#ifdef __MMI_SCREEN_ROTATE__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
#endif /* __MMI_SCREEN_ROTATE__ */
#endif
#else
#if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
    gdi_draw_darken_rect(0, 0, UI_device_width - 1, UI_device_height - 1, 75);
#endif
#endif

    /* reset the shaow area of cascading menu */
    wgui_reset_cm_first_level_ps();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_shadow_in_first_level
 * DESCRIPTION
 *  draw shadow in the first level when second level display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_show_shadow_in_first_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();

    if(cm_is_not_displayed_by_menu_cui) /* this is indicate cm is displayed by common screen */
    {
        if (g_mmi_cascading_menu_current_level != 0)
        {
#ifdef __MMI_SCREEN_ROTATE__
            if((mmi_frm_is_screen_width_height_swapped()) && (mmi_cat800_hide_softkey != NULL) )
            {
                gdi_draw_darken_rect(cm_ps.x1, cm_ps.y1, cm_ps.x2, cm_ps.y2, 75);
            }
            else
            {
#endif /* __MMI_SCREEN_ROTATE__ */
                draw_first_level_shadow(g_id);
#ifdef __MMI_SCREEN_ROTATE__
            }
#endif /* __MMI_SCREEN_ROTATE__ */
        }
        wgui_cm_reset_display_flag();
    }
    else
    {
        if (g_id != GRP_ID_INVALID && g_mmi_cascading_menu_current_level != 0)
        {
            draw_first_level_shadow(g_id);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory800Screen
 * DESCRIPTION
 *  Exits the category800 screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory800Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_small_screen();

    /* record first level position */
    wgui_set_cm_first_level_ps();

    g_mmi_category800_previous_menu_y1 = MMI_fixed_list_menu.highlight_y;
    
    /* restore list menu flag */
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_ALIGN_TO_TOP;

    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    ExitListCategoryScreen();
    entry_full_screen();

    gui_set_fixed_list_menu_current_theme(&MMI_fixed_list_menu);

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

    /* restore softkey background */
//    wgui_cat800_restore_softkey_bkg();
  
    /* free allocated bg layer */
    if (g_cascading_cache_buf.buf_ptr)
    {
        mmi_frm_scrmem_free(g_cascading_cache_buf.buf_ptr);
        g_cascading_cache_buf.buf_ptr = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_get_arrow_image
 * DESCRIPTION
 *  get arrow image for cascading menu
 * PARAMETERS
 *  arrow                   [IN]        normal arrow image
 *  disabled_arrow              [IN]        disabled arrow image
 *  highlight_arrow            [IN]        highlighted arrow image
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_get_arrow_image(PU8 *arrow, PU8 *disabled_arrow, PU8 *highlight_arrow)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fe_get_r2l_state())
    {
        *arrow = current_MMI_theme->cascade_menu_submenu_left_arrow_image;
        *disabled_arrow = current_MMI_theme->cascade_menu_submenu_disabled_left_arrow_image;
#ifndef __MMI_FWUI_SLIM__
        if (*disabled_arrow == NULL)
        {
            *disabled_arrow = (PU8)GetImage(IMG_LEFT_DISABLED_ARROW);
        }
#endif		
        if (*arrow == NULL)
        {
            *highlight_arrow = current_MMI_theme->cascade_menu_submenu_highlight_left_arrow_image;
        }
    }
    else
    {
        *arrow = current_MMI_theme->cascade_menu_submenu_right_arrow_image;
        *disabled_arrow = current_MMI_theme->cascade_menu_submenu_disabled_right_arrow_image;
#ifndef __MMI_FWUI_SLIM__
        if (*disabled_arrow == NULL)
        {
            *disabled_arrow = (PU8)GetImage(IMG_RIGHT_DISABLED_ARROW);
        }
#endif		
        if (*arrow == NULL)
        {
            *highlight_arrow = current_MMI_theme->cascade_menu_submenu_highlight_right_arrow_image;
        }
    }
}

#define WGUI_CAT_DRAW_801_BK_NO 0
#define WGUI_CAT_DRAW_801_BK	1
#define WGUI_CAT_DRAW_800_BK	2

/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_draw_background
 * DESCRIPTION
 *  draw category800 background
 * PARAMETERS
 *  x                   [IN]        x of background
 *  y              [IN]        y of background
 *  w            [IN]        width of background
 *  h			[IN]		height of background
 *  flag		[IN]		flag for draw background
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_draw_background(S32 x, S32 y, S32 w, S32 h, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    S32 var;
#endif /* __MMI_FTE_SUPPORT__ */
    color menu_border_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_border_color = *current_MMI_theme->cascade_menu_border_color;
    
#ifdef __MMI_FTE_SUPPORT__
    gui_draw_filled_area(
        x - CASCADING_MENU_BORDER_SIZE, 
        y - CASCADING_MENU_BORDER_Y_GAP, 
        x + w - 1 + CASCADING_MENU_BORDER_SIZE, 
        y + h - 1 + CASCADING_MENU_BORDER_Y_GAP,
        current_MMI_theme->cascade_menu_background_filler);
    if (!(current_MMI_theme->cascade_menu_background_filler->flags & UI_FILLED_AREA_TYPE_BITMAP))
    {
        var = CASCADING_MENU_BORDER_Y_GAP;
        if (y + h + CASCADING_MENU_BORDER_Y_GAP + 1 > MMI_content_y + MMI_content_height - 1)
        {
            var = CASCADING_MENU_BORDER_Y_GAP / 2;
        }
		gdi_draw_rect(
			(x > CASCADING_MENU_BORDER_SIZE ? (x - CASCADING_MENU_BORDER_SIZE) : 0), 
			y - CASCADING_MENU_BORDER_Y_GAP, 
			x + w + CASCADING_MENU_BORDER_SIZE, 
			y + h + var + 1,
			gdi_act_color_from_rgb(255, menu_border_color.r, menu_border_color.g, menu_border_color.b));
    }
    /* allocate memory */
    if (!g_cascading_cache_buf.buf_ptr)
    {
        g_cascading_cache_buf.buf_ptr = (U8*) mmi_frm_scrmem_alloc(MMI_CASCADING_ASM_BUFFER_SIZE);
        
        /* 
        * We can't 100% gaurantee to get buffer from screen memory manager.
        * Add assert to find the problem, or add some error handling 
        */
 //       MMI_DBG_ASSERT(g_cascading_cache_buf.buf_ptr); 
        if(g_cascading_cache_buf.buf_ptr != NULL)
        {
        gdi_image_cache_bmp_get(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y, 
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1, 
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1,
            &g_cascading_cache_buf);
        }
    }

#else /* __MMI_FTE_SUPPORT__ */

    if (flag == WGUI_CAT_DRAW_800_BK) //called by category800
    {
    #ifdef __MMI_CASCADING_MENU_ROUNDED_BORDER__
    
        gui_draw_gradient_rounded_rectangle(
            x - CASCADING_MENU_BORDER_SIZE, 
            y - CASCADING_MENU_BORDER_SIZE, 
            x + w + CASCADING_MENU_BORDER_SIZE,
            y + h + CASCADING_MENU_BORDER_SIZE, 
            menu_border_color,
            MMI_fixed_list_menu.normal_filler->c,
            CASCADING_MENU_BORDER_SIZE);
    
    #else /* __MMI_CASCADING_MENU_ROUNDED_BORDER__ */
    
        /* draw a single border line OUT of the menu rectangle */
        gdi_draw_rect(
            x - CASCADING_MENU_BORDER_SIZE, 
            y - CASCADING_MENU_BORDER_SIZE, 
            x + w,
            y + h, 
            gdi_act_color_from_rgb(255, menu_border_color.r, menu_border_color.g, menu_border_color.b));
        
        /* draw the shadow */
        DrawCategory800Shadow(
            x - CASCADING_MENU_BORDER_SIZE,
            y - CASCADING_MENU_BORDER_SIZE,
            w + CASCADING_MENU_BORDER_SIZE * 2,
            h + CASCADING_MENU_BORDER_SIZE * 2);
    
    #endif /* __MMI_CASCADING_MENU_ROUNDED_BORDER__ */
    }
	else	//called by category801, 802, 803
	{
        /* draw the border */
        /* draw a single border line OUT of the menu rectangle */	 
        gdi_draw_rect(
            x - CASCADING_MENU_BORDER_SIZE, 
            y - CASCADING_MENU_BORDER_SIZE, 
            x + w,
            y + h, 
            gdi_act_color_from_rgb(255, menu_border_color.r, menu_border_color.g, menu_border_color.b));
        
    #ifndef __MMI_CASCADING_MENU_ROUNDED_BORDER__
        if (flag == WGUI_CAT_DRAW_801_BK)
        {
            /* draw the shadow */
            DrawCategory800Shadow(
                x - CASCADING_MENU_BORDER_SIZE,
                y - CASCADING_MENU_BORDER_SIZE,
                w + CASCADING_MENU_BORDER_SIZE * 2,
                h + CASCADING_MENU_BORDER_SIZE * 2);
        }
    #endif /* __MMI_CASCADING_MENU_ROUNDED_BORDER__ */
	}
#endif /* __MMI_FTE_SUPPORT__ */
}

#ifdef __MMI_FTE_SUPPORT__
static void CategoryCascadingHideFunction(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    if (g_cascading_cache_buf.buf_ptr)
    {
        gdi_image_cache_bmp_draw(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y, 
            &g_cascading_cache_buf);

    }
    else
    {
        wgui_cat800_draw_background(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y, 
            MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.height,
            0);
    }
    gdi_layer_pop_clip();
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_calc_menu_height
 * DESCRIPTION
 *  calc menu height for category800
 * PARAMETERS
 *  rotated                   [IN]        whether is rotated
 *  n_items              [IN]        number of items
 *  menu_height            [OUT]        menu height
 *  show_scrollbar			[OUT]		whether show scrollbar
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_calc_menu_height(MMI_BOOL rotated, S32 n_items, S32 *menu_height, MMI_BOOL *show_scrollbar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 var;
    S32 max_height;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(rotated)
    {
        max_height = MMI_CONTENT_HEIGHT >> 1;
    }
    else
    {
        max_height = MMI_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT);
    }
    
    var = CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP + CASCADING_MENU_BORDER_SIZE * 2;
    *menu_height = n_items * MMI_MENUITEM_HEIGHT + var;
    /* adjust the max menu height a little to fit all cascade menu perfectly in one page */ 
    max_height = (max_height / MMI_MENUITEM_HEIGHT) * MMI_MENUITEM_HEIGHT + var;
    
    if (*menu_height <= max_height)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
        *show_scrollbar = MMI_FALSE;
    }
    else
    {
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_SCROLLBAR;
        *menu_height = max_height;
        *show_scrollbar = MMI_TRUE;
    }	 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_common_setting
 * DESCRIPTION
 *  common setting for cascading menu
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat800_common_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if not first level, and draw the previous screen with shadow */
    wgui_show_shadow_in_first_level();

	/* set cascading menu for small screen */
    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);

    /* disable list effect for sse */
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

    /* enable horizontal icon bar */
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);    /* early status icon */
}
/*****************************************************************************
 * FUNCTION
 *  ShowCategory802Screen
 * DESCRIPTION
 *  Shows category 801 screen (Cascade Menu Radio list).
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory802Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory802Screen_ext((U8*)get_string(title),
        get_image(title_icon),
        (U8*) get_string(left_softkey),
        get_image(left_softkey_icon),
        (U8*)get_string(right_softkey),
        get_image(right_softkey_icon),
        number_of_items,
        list_of_items,
        current_cm_level,
        max_cm_level,
        highlighted_item,
        history_buffer);    
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory802Screen_ext_int
 * DESCRIPTION
 *  Shows category 801 screen (Cascade Menu).
 * PARAMETERS
 *  title                   [IN]        Title string for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label string
 *  right_softkey           [IN]        Right softkey label string
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory802Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag, bk_flag;
    S32 menu_height, menu_width, menu_x, menu_y;
    S32 max_item_text_width = 0, text_width, text_height;
    S32 arrow_width = 0, arrow_height = 0;
    MMI_BOOL show_scrollbar;
    MMI_BOOL is_rotated = MMI_FALSE;
    cascading_position_values param;
	S32 var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	wgui_cat800_common_setting();

	wgui_fixed_list_create_twostate_menu(
		get_image(RADIO_ON_IMAGE_ID),
		get_image(RADIO_OFF_IMAGE_ID),
		number_of_items,
		highlighted_item,
		0,
		0,
		NULL);

#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif

    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    /* use cascade menu theme */
    MMI_fixed_twostate_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_twostate_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;   
    MMI_fixed_twostate_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->cascade_menu_background_filler;
#endif
    MMI_fixed_twostate_menuitem.normal_text_color = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_twostate_menuitem.disabled_text_color = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_twostate_menuitem.selected_text_color = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_twostate_menuitem.focussed_text_color = *current_MMI_theme->cascade_menu_selected_text_color;
    
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_register_hide_function(CategoryCascadingHideFunction);
#endif
   
    /* List */    
    register_fixed_list_highlight_handler(standard_radio_list_highlight_handler);

    /* measure submenu arrow dimension */
    gui_measure_image(get_image(RADIO_ON_IMAGE_ID), &arrow_width, &arrow_height);

    /* check if rotated */
#ifdef __MMI_SCREEN_ROTATE__
    is_rotated = mmi_frm_is_screen_width_height_swapped();
#endif
    /* add menu items */
	wgui_fixed_list_begin_add_twostate_one_item();
    for (i = 0; i < number_of_items; i++)
    {   
        wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], NULL);
        if(is_rotated || current_cm_level != 0)
        {
            /* find the max width of menu item strings for the second level */
            gui_set_font(gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT));
            gui_measure_string((UI_string_type)list_of_items[i], &text_width, &text_height);
            
            if (text_width > max_item_text_width)
            {
                max_item_text_width = text_width;
            }
        }
    }

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    /* calculate menu height */
    wgui_cat800_calc_menu_height(is_rotated, number_of_items, &menu_height, &show_scrollbar);

    param.max_item_text_width = max_item_text_width;
    param.show_submenu_indicator = MMI_TRUE;

    /* calculate menu width */
    if (current_cm_level == 0)
    {
        /* 1st level, full width */
        wgui_cat800_set_width_for_first_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
    else
    {
        /* 2nd level of CM */        
        /* leave right and left text gaps inside the highlight */
        wgui_cat800_set_width_for_second_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
        
    menu_x = param.menu_x;
  
    menu_width = param.menu_width;

    menu_y = param.menu_y;

#ifdef __MMI_FTE_SUPPORT__
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_Y_GAP >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_Y_GAP;
    }
#else
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_SIZE >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_SIZE;
    }
#endif

    /* resize menu item depending on the scroll bar is shown or not */
    var = menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
    if (show_scrollbar)
    {
        var = var - MMI_fixed_list_menu.vbar.width;
    }
	resize_fixed_twostate_menuitems(var, 0);

    /* decrease the top and bottom border size to get the true menu height */
    menu_height -= (CASCADING_MENU_BORDER_SIZE * 2) + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP;

    resize_fixed_list(menu_width, menu_height); 

    /* change the fixed menu top offset */
  //  MMI_fixed_list_menu.top = CASCADING_MENU_TOP_GAP;
    
    if (current_cm_level != 0)
    {
        if (menu_x > wgui_cat_cascading_menu_last_width)
            menu_x = wgui_cat_cascading_menu_last_width;
    }
    move_fixed_list(menu_x, menu_y);

    wgui_cat_cascading_menu_last_width = menu_x + menu_width - 1;

    h_flag = set_list_menu_category_history(MMI_CATEGORY_CASCADING_MENU_ID, history_buffer);
    
    // TODO: Fix the problem that popup DARKEN effect will not apply to the cascading menu.
    /* only darken the first level of cascading menu */

    /* draw darken area for the previous full screen */
	wgui_cascading_menu_darken_full_screen(current_cm_level, is_rotated);

    bk_flag = WGUI_CAT_DRAW_801_BK_NO;
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID || !h_flag)
    {
        bk_flag = WGUI_CAT_DRAW_801_BK;
    }
    wgui_cat800_draw_background(menu_x, menu_y, menu_width, menu_height, bk_flag);
  
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
	fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    select_fixed_twostate_item(MMI_fixed_list_menu.highlighted_item);
    /* No blt is needed here because of DM_FULL_SCREEN_COORDINATE_FLAG. */
    gdi_layer_unlock_frame_buffer();

    if (is_rotated)
    {
        wgui_cat800_register_hide_keys();
    }

	wgui_cat_setup_category_default_history(MMI_CATEGORY_CASCADING_MENU_ID, 0, ExitCategory800Screen);
    dm_set_dm_data_flag(DM_NO_FLAGS);
    dm_redraw_category_screen();    

    /* save current menu x1 and x2 for the second level */
    g_mmi_category800_previous_menu_x1 = MMI_fixed_list_menu.x;
    g_mmi_category800_previous_menu_x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory801Screen_int
 * DESCRIPTION
 *  Shows category 801 screen (Cascade Menu).
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory801Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_icons,
        U8 *list_of_flags,
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory801Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*) get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_flags,
        current_cm_level,
        max_cm_level,
        highlighted_item,
        history_buffer);    
	
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory801Screen_ext_int
 * DESCRIPTION
 *  Shows category 801 screen (Cascade Menu).
 * PARAMETERS
 *  title                   [IN]        Title string for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label string
 *  right_softkey           [IN]        Right softkey label string
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory801Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_icons,
        U8 *list_of_flags,
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag, bk_flag;
    S32 menu_height, menu_width, menu_x, menu_y;
    S32 max_item_text_width = 0, text_width, text_height;
    MMI_BOOL show_submenu_indicator = MMI_FALSE;
    S32 arrow_width = 0, arrow_height = 0, indicator_width, indicator_height;
    PU8 arrow_image, highlight_arrow_image = NULL;
    PU8 disabled_arrow_image;
    MMI_BOOL show_scrollbar;
    MMI_BOOL is_rotated = MMI_FALSE;
    cascading_position_values param;
	S32 var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	wgui_cat800_common_setting();

    wgui_fixed_list_create_multi_icontext_menu(
		1,
		1,
		number_of_items,
		highlighted_item,
		MMI_MENUITEM_HEIGHT,
		0,
		0,
		NULL);

#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif

		    
    /* use cascade menu theme */
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;   
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->cascade_menu_background_filler;
#endif
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_icontext_list_menuitem.disabled_text_colors[0] = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    /* do not display the shortcut */
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_register_hide_function(CategoryCascadingHideFunction);
#endif
    wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    
    /* measure submenu arrow dimension */
	wgui_cat800_get_arrow_image(&arrow_image, &disabled_arrow_image, &highlight_arrow_image);

    if (arrow_image)
        highlight_arrow_image = arrow_image;
    else if (disabled_arrow_image)
        highlight_arrow_image = disabled_arrow_image;
    gui_measure_image(highlight_arrow_image, &arrow_width, &arrow_height);
    /* check if rotated */
#ifdef __MMI_SCREEN_ROTATE__
    is_rotated = mmi_frm_is_screen_width_height_swapped();
#endif

    /* add menu items */
	wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {   
        fixed_icontext_list_item_insert(i);
		add_fixed_icontext_list_item_text(i, 0, (UI_string_type)list_of_items[i]);
		highlight_arrow_image = NULL;

        if (list_of_icons == NULL)
        {   
            if ((current_cm_level < max_cm_level - 1) && list_of_flags &&
                (list_of_flags[i] & UI_CASCADING_MENU_WITH_SUBMENU))
            {
                show_submenu_indicator = MMI_TRUE;
                if (list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
					highlight_arrow_image = disabled_arrow_image;
                else
					highlight_arrow_image = arrow_image;
                MMI_fixed_icontext_list_menuitems[i].ext_flags |= UI_MENUITEM_EXT_WITH_SUBMENU;
            }
        }
        else
        {
            show_submenu_indicator = MMI_TRUE;
            if ((current_cm_level < max_cm_level - 1) && list_of_flags &&
                (list_of_flags[i] & UI_CASCADING_MENU_WITH_SUBMENU))
                /*GetNumOfChild_Ext(menu_item_id))*/
            {
                if (list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
					highlight_arrow_image = disabled_arrow_image;
                else
					highlight_arrow_image = arrow_image;
                MMI_fixed_icontext_list_menuitems[i].ext_flags |= UI_MENUITEM_EXT_WITH_SUBMENU;
            }
            else
            {
				highlight_arrow_image = list_of_icons[i];
                indicator_width = 0;
                indicator_height = 0;
                gui_measure_image(list_of_icons[i], &indicator_width, &indicator_height);
                if (indicator_width > arrow_width)
                    arrow_width = indicator_width;
                if (indicator_height > arrow_height)
                    arrow_height = indicator_height;
            }
        }
        add_fixed_icontext_list_item_icon(i, 0, highlight_arrow_image);

        if (list_of_flags && list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
        {
            MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_STATE_DISABLED;
        }
        if(is_rotated || current_cm_level != 0)
        {
            /* find the max width of menu item strings for the second level */
            if(MMI_fixed_icontext_list_menuitem.selected_fonts[0] != NULL)
            {
                gui_set_font(MMI_fixed_icontext_list_menuitem.selected_fonts[0]);
            }
            gui_measure_string((UI_string_type)list_of_items[i], &text_width, &text_height);
            
            if (text_width > max_item_text_width)
            {
                max_item_text_width = text_width;
            }
        }
    }

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    /* calculate menu height */
    wgui_cat800_calc_menu_height(is_rotated, number_of_items, &menu_height, &show_scrollbar);

    param.max_item_text_width = max_item_text_width;
    param.show_submenu_indicator = show_submenu_indicator;

    /* calculate menu width */
    if (current_cm_level == 0)
    {
        /* 1st level, full width */
        wgui_cat800_set_width_for_first_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
    else
    {
        /* 2nd level of CM */        
        /* leave right and left text gaps inside the highlight */
        wgui_cat800_set_width_for_second_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
        
    menu_x = param.menu_x;
    menu_y = param.menu_y;
    menu_width = param.menu_width;
    max_item_text_width = param.max_item_text_width;
    show_submenu_indicator = param.show_submenu_indicator;

#ifdef __MMI_FTE_SUPPORT__
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_Y_GAP >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_Y_GAP;
    }
#else
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_SIZE >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_SIZE;
    }
#endif

    /* resize menu item depending on the scroll bar is shown or not */
    var = menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
    if (show_scrollbar)
    {
        var = var - MMI_fixed_list_menu.vbar.width;
    }
	resize_fixed_icontext_list_menuitems(var, 0);

    if (show_submenu_indicator)
    {
        max_item_text_width -= arrow_width + (CASCADING_MENU_ARROW_TO_TEXT_GAP<<1);
    }

    set_fixed_icontext_list_text_coordinates(0, CASCADING_MENU_TEXT_LEFT_GAP, 0, max_item_text_width - CASCADING_MENU_TEXT_LEFT_GAP - CASCADING_MENU_TEXT_RIGHT_GAP, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, max_item_text_width + CASCADING_MENU_ARROW_TO_TEXT_GAP, 0, arrow_width, arrow_height);  

    /* decrease the top and bottom border size to get the true menu height */
    menu_height -= (CASCADING_MENU_BORDER_SIZE * 2) + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP;

    resize_fixed_list(menu_width, menu_height); 

    /* change the fixed menu top offset */
 //   MMI_fixed_list_menu.top = CASCADING_MENU_TOP_GAP;
    
    if (current_cm_level != 0)
    {
        if (menu_x > wgui_cat_cascading_menu_last_width)
            menu_x = wgui_cat_cascading_menu_last_width;
    }
    move_fixed_list(menu_x, menu_y);

    wgui_cat_cascading_menu_last_width = menu_x + menu_width - 1;

    h_flag = set_list_menu_category_history(MMI_CATEGORY_CASCADING_MENU_ID, history_buffer);
    
    // TODO: Fix the problem that popup DARKEN effect will not apply to the cascading menu.
    /* only darken the first level of cascading menu */

    /* draw darken area for the previous full screen */
	wgui_cascading_menu_darken_full_screen(current_cm_level, is_rotated);

    bk_flag = WGUI_CAT_DRAW_801_BK_NO;
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID || !h_flag)
    {
        bk_flag = WGUI_CAT_DRAW_801_BK;
    }
    wgui_cat800_draw_background(menu_x, menu_y, menu_width, menu_height, bk_flag);
  
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
	fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

    /* No blt is needed here because of DM_FULL_SCREEN_COORDINATE_FLAG. */
    gdi_layer_unlock_frame_buffer();

    if (is_rotated)
    {
        wgui_cat800_register_hide_keys();
    }

    /* The lsk is disabled when all items are disabled */
    wgui_cate_disable_left_softkey();


	wgui_cat_setup_category_default_history(MMI_CATEGORY_CASCADING_MENU_ID, 0, ExitCategory800Screen);
    dm_set_dm_data_flag(DM_NO_FLAGS);
    dm_redraw_category_screen();    

    /* save current menu x1 and x2 for the second level */
    g_mmi_category800_previous_menu_x1 = MMI_fixed_list_menu.x;
    g_mmi_category800_previous_menu_x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1;  
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat801_refresh_list
 * DESCRIPTION
 *  Refresh the cat801 list
 * PARAMETERS
 *  list_of_items         [IN]        The list items.
 *  list_of_icons        [IN]        The icon items
 *  list_of_flags             [IN]    The flags
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat801_refresh_list(
	U8 **list_of_items,
	U8 **list_of_icons,
	U8 *list_of_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 disabled_arrow_image, arrow_image, temp_arrow_image;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	/* measure submenu arrow dimension */
	wgui_cat800_get_arrow_image(&arrow_image, &disabled_arrow_image, &temp_arrow_image);

    /* add menu items */
    for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {   
    
		add_fixed_icontext_list_item_text(i, 0, (UI_string_type)list_of_items[i]);
		temp_arrow_image = NULL;
        if (list_of_icons == NULL)
        {   
            if (list_of_flags &&
                (list_of_flags[i] & UI_CASCADING_MENU_WITH_SUBMENU))
            {
                if (list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
					temp_arrow_image = disabled_arrow_image;
                else
					temp_arrow_image = arrow_image;
            }
        }
        else
        {
            if (list_of_flags && (list_of_flags[i] & UI_CASCADING_MENU_WITH_SUBMENU))
            {
                if (list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
					temp_arrow_image = disabled_arrow_image;
                else
					temp_arrow_image = arrow_image;
            }
            else
            {
                temp_arrow_image = list_of_icons[i];
            }
        }

        add_fixed_icontext_list_item_icon(i, 0, temp_arrow_image);
        if (list_of_flags && list_of_flags[i] & UI_CASCADING_MENU_DISABLED)
        {
            MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_STATE_DISABLED;
        }

    }
    show_fixed_list();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory800Screen_int
 * DESCRIPTION
 *  Shows category 800 screen (Cascade Menu).
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  cm_menu_id              [IN]        Cascade menu resource ID
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory800Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 current_cm_level,
        S32 max_cm_level,
        U16 cm_menu_id,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag;
    S32 menu_height, menu_width, menu_x, menu_y;
    S32 max_item_text_width = 0, text_width, text_height;
    UI_string_type  item_text;
    MMI_BOOL show_submenu_indicator = MMI_FALSE;
    S32 arrow_width = 0, arrow_height = 0;
    PU8 arrow_image, highlight_arrow_image = NULL;
    PU8 disabled_arrow_image;
    MMI_BOOL show_scrollbar;
    U16 menu_item_id;

    MMI_BOOL is_rotated = MMI_FALSE;
#ifndef __MMI_FTE_SUPPORT__
    S32 bottom_gap;
#endif
    cascading_position_values param;
	S32 var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	wgui_cat800_common_setting();

    wgui_fixed_list_create_multi_icontext_menu(
        1,
        1,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        0,
        0,
        NULL);

#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif

    /* use cascade menu theme */
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;   
    /* for UI_LIST_MENU_DISABLE_SCROLLBAR */
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->cascade_menu_background_filler;
#endif
    MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_icontext_list_menuitem.disabled_text_colors[0] = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    /* do not display the shortcut */
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_register_hide_function(CategoryCascadingHideFunction);
#endif

    dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    
    /* measure submenu arrow dimension */
	wgui_cat800_get_arrow_image(&arrow_image, &disabled_arrow_image, &highlight_arrow_image);

    if (arrow_image)
        highlight_arrow_image = arrow_image;
    else if (disabled_arrow_image)
        highlight_arrow_image = disabled_arrow_image;
    gui_measure_image(highlight_arrow_image, &arrow_width, &arrow_height);
    
    /* leave x gap to the right of arrow */
    if (arrow_width)
    {
        arrow_width += CASCADING_MENU_ARROW_X_GAP;
    }

    /* check if rotated */
#ifdef __MMI_SCREEN_ROTATE__
    is_rotated = mmi_frm_is_screen_width_height_swapped();
#endif

    /* add menu items */
	wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {   
        menu_item_id = GetSeqItemId_Ext(cm_menu_id, (U16)i);
    
        fixed_icontext_list_item_insert(i);
        item_text = get_string(list_of_items[i]);
		add_fixed_icontext_list_item_text(i, 0, item_text);

		highlight_arrow_image = NULL;
        if (list_of_icons == NULL)
        {   
            if ((current_cm_level < max_cm_level - 1) && GetNumOfChild_Ext(menu_item_id))
            {
                show_submenu_indicator = MMI_TRUE;
                if (IsMenuItemDimmed(menu_item_id))
					highlight_arrow_image = disabled_arrow_image;
                else
					highlight_arrow_image = arrow_image;
                MMI_fixed_icontext_list_menuitems[i].ext_flags |= UI_MENUITEM_EXT_WITH_SUBMENU;
            }
        }
        else
        {
            highlight_arrow_image = get_image(list_of_icons[i]);
        }

        add_fixed_icontext_list_item_icon(i, 0, highlight_arrow_image);
        if (IsMenuItemDimmed(menu_item_id))
        {
            MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_STATE_DISABLED;
        }
        if(is_rotated || current_cm_level != 0)
        {
            /* find the max width of menu item strings for the second level */
            if(MMI_fixed_icontext_list_menuitem.selected_fonts[0] != NULL)
            {
                gui_set_font(MMI_fixed_icontext_list_menuitem.selected_fonts[0]);
            }
            gui_measure_string(item_text, &text_width, &text_height);
            
            if (text_width > max_item_text_width)
            {
                max_item_text_width = text_width;
            }
        }
    }

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    /* calculate menu height */
    wgui_cat800_calc_menu_height(is_rotated, number_of_items, &menu_height, &show_scrollbar);

#ifndef __MMI_FTE_SUPPORT__
    /* get rotation-related gaps */
    if (is_rotated)
    {
        /* softkey bar on right */        
        bottom_gap = 0;
    }
    else
    {
        /* softkey bar on bottom */    
        bottom_gap  = MMI_SOFTKEY_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
    param.max_item_text_width = max_item_text_width;
    param.show_submenu_indicator = show_submenu_indicator;

    /* calculate menu width */
    if (current_cm_level == 0)
    {
        /* 1st level, full width */
        wgui_cat800_set_width_for_first_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
    else
    { 
        /* 2nd level of CM */        
        /* leave right and left text gaps inside the highlight */
        wgui_cat800_set_width_for_second_level(&param, is_rotated, show_scrollbar, arrow_width);
    }   

    menu_x = param.menu_x;
    menu_y = param.menu_y;
    menu_width = param.menu_width;
    max_item_text_width = param.max_item_text_width;
    show_submenu_indicator = param.show_submenu_indicator;

#ifdef __MMI_FTE_SUPPORT__
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_Y_GAP >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_SIZE;
    }
#else
    /* aligned menu to sit on bottom if menu exceed the bottom of the screen. */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_SIZE >= UI_device_height - bottom_gap)
    {   
        menu_y = UI_device_height - bottom_gap - menu_height - 1 + CASCADING_MENU_BORDER_SIZE;
    }
#endif
    else if (current_cm_level)
    {   /* 
         * for non-first level CM, menu_y must be adjusted menu_y for the CASCADING_MENU_TOP_GAP, 
         * since MMI_fixed_list_menu.highlight_y as the menu_y, and there is CASCADING_MENU_TOP_GAP above it.
         */
        menu_y -= CASCADING_MENU_TOP_GAP;
    }

    /* resize menu item depending on the scroll bar is shown or not */
	var = menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
    if (show_scrollbar)
    {
        var = var - MMI_fixed_list_menu.vbar.width;
    }
	resize_fixed_icontext_list_menuitems(var, 0);

    if (show_submenu_indicator)
    {
        max_item_text_width -= arrow_width + (CASCADING_MENU_ARROW_TO_TEXT_GAP<<1);
    }

    var = max_item_text_width - CASCADING_MENU_TEXT_LEFT_GAP - CASCADING_MENU_TEXT_RIGHT_GAP;
#ifdef MMI_CASCADING_MENU_FIXED_WIDTH
    if (current_cm_level == 0)
		var = max_item_text_width;
#else
    if (mmi_fe_get_r2l_state())
    {
        if (current_cm_level == 0)
			var = max_item_text_width;
    }
#endif
    set_fixed_icontext_list_text_coordinates(0, CASCADING_MENU_TEXT_LEFT_GAP, 0, var, MMI_MENUITEM_HEIGHT);
    /* set the arrow coordinate */
    set_fixed_icontext_list_icon_coordinates(0, max_item_text_width + CASCADING_MENU_ARROW_TO_TEXT_GAP, 0, arrow_width - CASCADING_MENU_ARROW_X_GAP, arrow_height);

    /* decrease the top and bottom border size to get the true menu height */
    menu_height -= (CASCADING_MENU_BORDER_SIZE * 2) + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP;

    resize_fixed_list(menu_width, menu_height); 

    /* change the fixed menu top offset */
 //   MMI_fixed_list_menu.top = CASCADING_MENU_TOP_GAP;
    
    move_fixed_list(menu_x, menu_y);

    h_flag = set_list_menu_category_history(MMI_CATEGORY_CASCADING_MENU_ID, history_buffer);

    /* draw darken area for the previous full screen */
	wgui_cascading_menu_darken_full_screen(current_cm_level, is_rotated);

    wgui_cat800_draw_background(menu_x, menu_y, menu_width, menu_height, WGUI_CAT_DRAW_800_BK);

    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
	fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

    /* No blt is needed here because of DM_FULL_SCREEN_COORDINATE_FLAG. */
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY_CASCADING_MENU_ID, DM_USER_DEFINE_ROTATE_BG_IMG, ExitCategory800Screen);
    /* 
     * Do not clear the background in dm_setup_data when rotated since it will force DM_CLEAR_SCREEN_BACKGROUND.
     * The rule is that the rotated cascading menu cannot be invoked from a non-rotated screen.
     */
    dm_set_dm_data_flag(DM_NO_FLAGS);


    if (is_rotated)
    {
        wgui_cat800_register_hide_keys();
    }

    
    dm_redraw_category_screen();

    /* save current menu x1 and x2 for the second level */
    g_mmi_category800_previous_menu_x1 = MMI_fixed_list_menu.x;
    g_mmi_category800_previous_menu_x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat800_refresh_list
 * DESCRIPTION
 *  Refresh the cat800 list
 * PARAMETERS
 *  list_of_items         [IN]        The list items.
 *  list_of_icons        [IN]        The icon items
 *  cm_menu_id             [IN]    The menu id
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_cat800_refresh_list(
    U16 *list_of_items,
    U16 *list_of_icons,
    U16 cm_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 menu_item_id;
    UI_string_type  item_text;
    PU8 disabled_arrow_image, arrow_image, temp_arrow_image;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	/* measure submenu arrow dimension */
	wgui_cat800_get_arrow_image(&arrow_image, &disabled_arrow_image, &temp_arrow_image);
	
    /* add menu items */
    for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {   
        menu_item_id = GetSeqItemId_Ext(cm_menu_id, (U16)i);
		
        item_text = get_string(list_of_items[i]);
		add_fixed_icontext_list_item_text(i, 0, item_text);

		temp_arrow_image = NULL;
        if (list_of_icons == NULL)
        {   
            if (GetNumOfChild_Ext(menu_item_id))
            {
                if (IsMenuItemDimmed(menu_item_id))
					temp_arrow_image = disabled_arrow_image;
                else
					temp_arrow_image = arrow_image;
            }
        }
        else
        {
            temp_arrow_image = get_image(list_of_icons[i]);
        }

		add_fixed_icontext_list_item_icon(i, 0, temp_arrow_image);
		
        if (IsMenuItemDimmed(menu_item_id))
        {
            MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_STATE_DISABLED;
        }
		
    }
    show_fixed_list();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
	
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory1Screen_int
 * DESCRIPTION
 *  Displays the category1 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Index of the item to be highlighted by default
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory1Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_load_string(number_of_items, list_of_items);
    ShowCategory6Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        subMenuDataPtrs,
        NULL,
        highlighted_item,
        history_buffer);

}   /* end of ShowCategory1Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory6Screen_int
 * DESCRIPTION
 *  Displays the category6 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items
 *  list_of_items               [IN]        List of text items.
 *  list_of_descriptions        [IN]        Descriptions of list items
 *  highlighted_item            [IN]        This is the default item that will be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory6Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__WGUI_CATE_LIST_SIMPLE_TEXT_MAP__)
    ShowCategory53Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        list_of_descriptions,
        0,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_SIMPLE_TEXT_MAP__ */
    ShowCategory6Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_descriptions,
        highlighted_item,
        history_buffer);
#endif /* __WGUI_CATE_LIST_SIMPLE_TEXT_MAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory6Screen_ext_int
 * DESCRIPTION
 *  Displays the category6 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items
 *  list_of_items               [IN]        List of text items.
 *  list_of_descriptions        [IN]        Descriptions of list items
 *  highlighted_item            [IN]        This is the default item that will be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory6Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
#if defined(__WGUI_CATE_LIST_SIMPLE_TEXT_MAP__)
    ShowCategory353Screen_ext_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        list_of_descriptions,
        0,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_SIMPLE_TEXT_MAP__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);

    wgui_fixed_list_create_text_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY6_ID, history_buffer);
    wgui_fixed_list_add_text_items(list_of_items, list_of_descriptions);

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY6_ID, 0, ExitListCategoryScreen);
    dm_redraw_category_screen();
#endif /* __WGUI_CATE_LIST_SIMPLE_TEXT_MAP__ */
}   /* end of ShowCategory6Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory55Screen_int
 * DESCRIPTION
 *  Displays the category55 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items
 *  list_of_items               [IN]        List of text items.
 *  list_of_descriptions        [IN]        
 *  highlighted_item            [IN]        This is the default item that will be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory55Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }
    ShowCategory6Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        subMenuDataPtrs,
        list_of_descriptions,
        highlighted_item,
        history_buffer);

}   /* end of ShowCategory55Screen */


/*****************************************************************************
 * FUNCTION
 *  Category52ChangeItemText
 * DESCRIPTION
 *  change category 52 item text
 * PARAMETERS
 *  index       [IN]        Item index to change
 *  text        [IN]        String to change
 * RETURNS
 *  void
 *****************************************************************************/
void Category52ChangeItemText(S32 index, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitems[index].item_text = (UI_string_type) text;
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
}   /* end of Category52ChangeItemText */


/*****************************************************************************
 * FUNCTION
 *  Category52ChangeItemDescription
 * DESCRIPTION
 *  change the popup text of menu item of particular index of category52
 * PARAMETERS
 *  index       [IN]        Item index
 *  text        [IN]        Description text
 * RETURNS
 *  void
 *****************************************************************************/
void Category52ChangeItemDescription(S32 index, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    if ((text == NULL) || (*(text) == 0 && *(text+1) == 0))
    {
        wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) default_empty_description;
    }
    else
    {
        wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) text;
    }
#else /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */
    wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) text;
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */

#if defined(__MMI_UI_HINTS_IN_MENUITEM__)
    wgui_cat_set_hint_in_menuitem_flag(MMI_fixed_list_menu.n_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_setup_pop_up_description_transition();
#endif 
}   /* end of Category52ChangeItemDescription */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory52Screen_int
 * DESCRIPTION
 *  Displays the category52 screen ( List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory52Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat_load_string(number_of_items, list_of_items);
    ShowCategory53Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        subMenuDataPtrs,
        list_of_icons,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);

}   

/*****************************************************************************
 * FUNCTION
 *  Category53ChangeItemText
 * DESCRIPTION
 *  change category 53 item text
 * PARAMETERS
 *  index       [IN]        Item index to change
 *  text        [IN]        String to change
 * RETURNS
 *  void
 *****************************************************************************/
void Category53ChangeItemText(S32 index, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitems[index].item_text = (UI_string_type) text;
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
}   /* end of Category53ChangeItemText */

/*****************************************************************************
 * FUNCTION
 *  Category53ChangeItemIcon
 * DESCRIPTION
 *  change category 53 item icon
 * PARAMETERS
 *  index       [IN]        Item index to change
 *  text        [IN]        icon to change
 * RETURNS
 *  void
 *****************************************************************************/
void Category53ChangeItemIcon(S32 index, U8 *icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_icontext_menuitems[index].item_icon= (PU8) icon;
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
}   /* end of Category53ChangeItemIcon */


/*****************************************************************************
 * FUNCTION
 *  Category53ChangeItemDescription
 * DESCRIPTION
 *  change category53 descripition
 * PARAMETERS
 *  index       [IN]        Item index to change
 *  text        [IN]        String to change
 * RETURNS
 *  void
 *****************************************************************************/
void Category53ChangeItemDescription(S32 index, U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    if ((text == NULL) || (*(text) == 0 && *(text+1) == 0))
    {
        wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) default_empty_description;
    }
    else
    {
        wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) text;
    }
#else /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */
    wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) text;
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */

#if defined(__MMI_UI_HINTS_IN_MENUITEM__)
    wgui_cat_set_hint_in_menuitem_flag(MMI_fixed_list_menu.n_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
    wgui_setup_pop_up_description_transition();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory53Screen_int
 * DESCRIPTION
 *  Displays the category53 screen ( List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory53Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory353Screen_int(
        (U8*) GetString(title),
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory53Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory353Screen_int
 * DESCRIPTION
 *  Displays the category353 screen ( List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory353Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory353Screen_ext_int(
        title,
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);	
}   /* end of ShowCategory353Screen */


#if defined(__MMI_FTE_SUPPORT__)
static void wgui_cat353_stop_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_stop_list_menuitem_scrolling();
}


static void wgui_cat353_resume_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    
    gdi_layer_lock_frame_buffer();
    show_fixed_list();
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.height - 1);
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory353Screen_ext_int
 * DESCRIPTION
 *  Displays the category353 screen ( List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title string for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory353Screen_ext_int(
        U8 *title,
        U8 *title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	MMI_BOOL flag = MMI_FALSE;
	PU8 icon = NULL;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY52_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, (U16)CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY52_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_list_begin_add_icontext_one_item();
    for(i = 0; i < number_of_items; i++)
    {
        icon = NULL;
        if (list_of_icons != NULL)
        {
            icon = wgui_get_list_menu_icon(i, list_of_icons[i]);
        }
		if (icon != NULL)
		{
		    flag = MMI_TRUE;
		}
        if(list_of_descriptions == NULL)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], icon, NULL);
        }
        else
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], icon, list_of_descriptions[i]);
        }
    }
	if (!flag)
	{
	    set_fixed_text_positions(GUI_TEXT_MENUITEM_TEXT_X, 0);
	}

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    wgui_cat_configure_slim_hint();
    wgui_cat_set_hint_in_menuitem(list_of_descriptions, number_of_items);
    wgui_cat_set_default_empty_descriptions(number_of_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */
    wgui_fixed_list_end_add_icontext_one_item();

    /* The lsk is disabled when all items are disabled */
    wgui_cate_disable_left_softkey();

    /* set some item disable but not to change text color */
    if (flags & WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR)
    {
        MMI_fixed_icontext_menuitem.disabled_text_color = MMI_fixed_icontext_menuitem.normal_text_color;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        wgui_icon_bar_register_pause_interactive_UI_callback(wgui_cat353_stop_scroll);
        wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat353_resume_scroll);

        set_list_menu_category_history(MMI_CATEGORY52_ID, history_buffer);
    }
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    gdi_layer_unlock_frame_buffer();
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, s32flags, ExitCategoryCommonScreen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY52_ID, 0, ExitCategoryCommonScreen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory353Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory11Screen_int
 * DESCRIPTION
 *  Displays the category11 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory11Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat_load_string(number_of_items, list_of_items);
    ShowCategory36Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        subMenuDataPtrs,
        highlighted_item,
        history_buffer);

}   /* end of ShowCategory11Screen */


static void ExitCategory36Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryCommonScreen();
    two_state_radio_list_history_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory36Screen_int
 * DESCRIPTION
 *  Displays the Dynamic radio list screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory36Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ShowCategory36Screen_ext_int(
           (U8*)get_string(title),
           get_image(title_icon),
           (U8*)get_string(left_softkey),
           (U8*)get_string(right_softkey),
           number_of_items,
           list_of_items,
           highlighted_item,
           history_buffer);
}   /* end of ShowCategory36Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory36Screen_ext_int
 * DESCRIPTION
 *  Displays the Dynamic radio list screen
 * PARAMETERS
 *  title                   [IN]        Title string for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label string
 *  right_softkey           [IN]        Right softkey label string 
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory36Screen_ext_int(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* right_softkey,
                S32 number_of_items,
                U8 **list_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{
#if defined(__WGUI_CATE_LIST_RADIO_BOX_MAP__)
    ShowCategory109Screen_ext_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        (S32)highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_RADIO_BOX_MAP__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag = 0;
    S32 selected_index = 0;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY36_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    /* Setup menuitem */
    wgui_fixed_list_create_twostate_menu(
        get_image(RADIO_ON_IMAGE_ID),
        get_image(RADIO_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        0,
        NULL);

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    h_flag = wgui_set_twostate_radio_list_history((U16)CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    h_flag = wgui_set_twostate_radio_list_history(MMI_CATEGORY36_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    if(!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
        selected_index = highlighted_item;
    }
    else
    {
        list_menu_two_state_radio_history *h = (list_menu_two_state_radio_history*) history_buffer;
        selected_index = h->selected_item;
    }

    wgui_fixed_list_begin_add_twostate_one_item();

    for (i = 0; i < number_of_items; i++)
    {
        wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], NULL);
    }

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */
	
    wgui_fixed_list_end_add_twostate_one_item();
    wgui_fixed_list_override_twostate_highlight_handler(standard_radio_list_highlight_handler);

    select_fixed_twostate_item(selected_index);

    gdi_layer_unlock_frame_buffer();

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category(
        CatId,
        s32flags,
        ExitCategory36Screen,
        wgui_get_twostate_radio_list_history,
        wgui_get_twostate_radio_list_history_size);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category(
        MMI_CATEGORY36_ID,
        0,
        ExitCategory36Screen,
        wgui_get_twostate_radio_list_history,
        wgui_get_twostate_radio_list_history_size);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
#endif /* __WGUI_CATE_LIST_RADIO_BOX_MAP__ */
}   /* end of ShowCategory36Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory12Screen_int
 * DESCRIPTION
 *  (two state menuitem)
 *  Displays the Category12 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_states          [IN]        Array containing the states of the items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory12Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory12Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_states,
        highlighted_item,
        history_buffer);

}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory12Screen_ext_int
 * DESCRIPTION
 *  (two state menuitem)
 *  Displays the Category12 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_states          [IN]        Array containing the states of the items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory12Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY12_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    /* Setup menuitem */

	
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    wgui_fixed_list_create_twostate_menu(
        get_image(CHECKBOX_ON_IMAGE_ID),
        get_image(CHECKBOX_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        (U16)CatId,
        history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_list_create_twostate_menu(
        get_image(CHECKBOX_ON_IMAGE_ID),
        get_image(CHECKBOX_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        MMI_CATEGORY12_ID,
        history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    resize_fixed_twostate_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_left_softkey_function(standard_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    checklist_category_menu_item_states = list_of_states;
    wgui_fixed_list_add_twostate_items(list_of_items, list_of_states, NULL);

#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.disable_up_select = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */

    gdi_layer_unlock_frame_buffer();

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, s32flags, ExitCategoryCommonScreen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY12_ID, 0, ExitCategoryCommonScreen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory12Screen */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory13Screen_int
 * DESCRIPTION
 *  Displays the Category13 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_states          [IN]        Array containing the states of the items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory13Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat_load_string(number_of_items, list_of_items);
    ShowCategory12Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        subMenuDataPtrs,
        list_of_states,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory13Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory15Screen
 * DESCRIPTION
 *  Exits the category15 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory15Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_fixed_matrix();
    /* Reset key callback in editor option menu */
    wgui_inputs_option_menu_reset_key_callback();
    wgui_inputs_option_menu_reset_highlight_callback();
#ifdef __MMI_SMALL_LIST_SCREEN__
    restore_small_screen();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory15Screen_int
 * DESCRIPTION
 *  Displays the category15 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        (see explanation below)
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory15Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
#if defined(__WGUI_CATE_LIST_SIMPLE_LIST_MAP__)
    ShowCategory52Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons,
        NULL,
        0,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_SIMPLE_LIST_MAP__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SMALL_LIST_SCREEN__
    if (whether_no_small_screen())
    {
        ShowCategory10Screen(
            title,
            title_icon,
            left_softkey,
            0,
            right_softkey,
            0,
            number_of_items,
            list_of_items,
            list_of_icons,
            highlighted_item,
            history_buffer);
    }
    else
#endif /* __MMI_SMALL_LIST_SCREEN__ */ 
    {

        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        S32 i, ixsize, iysize, CatId;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        gdi_layer_lock_frame_buffer();
		dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
		dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
        wgui_title_set_menu_shortcut_number(-1);

        MMI_current_menu_type = flags & 0x0f;

        switch (MMI_current_menu_type)
        {
            case LIST_MENU:

                wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY15_LIST_ID, history_buffer);
                wgui_fixed_list_begin_add_icontext_one_item();
                for (i = 0; i < number_of_items; i++)
                {
                    wgui_fixed_list_add_icontext_one_item(i, (U8 *)get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
                }
                wgui_fixed_list_end_add_icontext_one_item();

                break;

            case MATRIX_MENU:
                wgui_fixed_matrix_create_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY15_MATRIX_ID, history_buffer);

                wgui_fixed_matrix_begin_add_one_item();
                for (i = 0; i < number_of_items; i++)
                {
                    wgui_fixed_matrix_add_one_item(i, (U8*)get_string(list_of_items[i]), get_image(list_of_icons[i]));
                }
                
                MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_LOOP;
        
                wgui_fixed_matrix_override_highlight_handler(standard_animated_matrix_highlight_handler_type2);

                if (number_of_items > 9)
                {
                    ixsize = (MMI_content_width - MMI_fixed_matrix_menu.vbar.width - 6) / 3;
                }
                else
                {
                    ixsize = (MMI_content_width - 6) / 3;
                }
                iysize = (MMI_content_height - 6) / 3;
                configure_fixed_matrix(ixsize, iysize, 3, 0);
                wgui_fixed_matrix_end_add_one_item();
                MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY;
                MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_ICON_X | UI_MENUITEM_CENTER_ICON_Y;
                
                MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->symbol_picker_highlight_filler;
                MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->symbol_picker_highlight_filler;
                break;
                
            default:
            {
                MMI_ASSERT(0);
            }
        }

        gdi_layer_unlock_frame_buffer();
		
        if ((MMI_current_menu_type == LIST_MENU) || (MMI_current_menu_type == PAGE_MENU))
        {
            CatId = MMI_CATEGORY15_LIST_ID;
        }
        else
        {
            CatId = MMI_CATEGORY15_MATRIX_ID;
        }
		
		wgui_cat_setup_category_default_history(CatId, 0, ExitCategory15Screen);
        dm_redraw_category_screen();
    }
#endif /* __WGUI_CATE_LIST_SIMPLE_LIST_MAP__ */
}   /* end of ShowCategory15Screen */


#ifdef __MMI_SMALL_LIST_SCREEN__
UI_filled_area *fixed_list_backup_filler;
S32 cat10_list_item_num = 0;


/*****************************************************************************
 * FUNCTION
 *  ExitCategory10Screen
 * DESCRIPTION
 *  Exits the category10 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory10Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_small_screen();
    MMI_fixed_list_menu.normal_filler = fixed_list_backup_filler;
    title_bg_id = 0;
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);    /* 052906 early status icon */

    /* Reset key callback in editor option menu */
    wgui_inputs_option_menu_reset_key_callback();
    wgui_inputs_option_menu_reset_highlight_callback();
    if(g_cache_small_list_bg.buf_ptr)
    {
        mmi_frm_scrmem_free(g_cache_small_list_bg.buf_ptr);
        g_cache_small_list_bg.buf_ptr = NULL;
    }

    gui_vertical_scrollbar_reset_hide_callback(&MMI_fixed_list_menu.vbar);
    ExitListCategoryScreen();
}

#define UI_SMALL_LIST_SCREEN_WITHOUT_TITLE
#define MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT 3

#if defined(__MMI_FTE_SUPPORT__)
void draw_cat10_background()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, w, h;
    U32 flags = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = MMI_fixed_list_menu.x - (MMI_FTE_TOOLBAR_START_X);
    y1 = MMI_fixed_list_menu.y - MMI_FTE_TOOLBAR_START_X;
    w = MMI_fixed_list_menu.width + (MMI_FTE_TOOLBAR_START_X<<1);
    h = MMI_fixed_list_menu.height + (MMI_FTE_TOOLBAR_START_X<<1);
    flags = current_MMI_theme->small_list_menu_normal_filler->flags;

    flags = flags & 0x0ff;
   
    /*This part changed only for MTE*/
    if((flags == UI_FILLED_AREA_TYPE_BITMAP) || (flags == UI_FILLED_AREA_TYPE_IMAGE_LEFT_ALIGN) || (flags == UI_FILLED_AREA_TYPE_IMAGE_RIGHT_ALIGN))
    {
        gui_draw_filled_area(x1, y1, x1 + w, y1 + h, current_MMI_theme->small_list_menu_normal_filler);
        if(current_MMI_theme->small_list_menu_normal_filler->flags != UI_FILLED_AREA_TYPE_BITMAP)
        {
            gui_draw_rectangle(x1, y1, x1 + w, y1 + h - 1, current_MMI_theme->small_list_screen_border_filler->c);
        }
    }
    else
    {
        if(current_MMI_theme->small_list_menu_normal_filler->flags != UI_FILLED_AREA_TYPE_BITMAP)
        {
            gui_draw_filled_area(x1+1, y1+1, x1 + w-1, y1 + h - 2, (current_MMI_theme->small_list_screen_border_filler));
        }
        gui_draw_filled_area(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y - 1,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height,
            current_MMI_theme->small_list_menu_normal_filler);
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  DrawCate10CategoryControlArea
 * DESCRIPTION
 *  Cateogry 10 control area redraw callback
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate10CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    S32 x1, x2, y1, y2;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);

#ifdef __MMI_FTE_SUPPORT__
    draw_cat10_background();
    if(!g_cache_small_list_bg.buf_ptr)
    {
        g_cache_small_list_bg.buf_ptr = (U8 *)mmi_frm_scrmem_alloc(MMI_CASCADING_ASM_BUFFER_SIZE);
        MMI_DBG_ASSERT(g_cache_small_list_bg.buf_ptr);
        gdi_image_cache_bmp_get(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1,
            &g_cache_small_list_bg);
    }
#else /* __MMI_FTE_SUPPORT__ */
    gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, 20, 1);

    x1 = MMI_SMALL_LIST_LEFT_OFFSET - 1;
    x2 = MMI_SMALL_LIST_SCREEN_WIDTH + 2;

#ifdef UI_SMALL_LIST_SCREEN_WITHOUT_TITLE
    y1 = UI_device_height - MMI_button_bar_height - (4 + get_menu_item_height() * cat10_list_item_num + 4 + 5) - 2;
#else /* UI_SMALL_LIST_SCREEN_WITHOUT_TITLE */ 
    y1 = UI_device_height - MMI_button_bar_height - MMI_title_height - (4 +
                                                                        get_menu_item_height() * cat10_list_item_num +
                                                                        4 + 5) - 2;
#endif /* UI_SMALL_LIST_SCREEN_WITHOUT_TITLE */ 
    y2 = UI_device_height - MMI_button_bar_height - 1;

    gui_draw_filled_area(x1, y1, x2, y2, (current_MMI_theme->small_list_screen_border_filler/*current_MMI_theme->cascade_menu_background_filler*/));
#endif /* __MMI_FTE_SUPPORT__ */
}


#if defined(__MMI_FTE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat10_menu_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat10_menu_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    if (g_cache_small_list_bg.buf_ptr)
    {
        gdi_image_cache_bmp_draw(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y,
            &g_cache_small_list_bg);
    }
    else
    {
        draw_cat10_background();
    }

    gdi_layer_pop_clip();
}


static void wgui_cat10_vertical_scrollbar_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_fill_transparent_color(x1, y1, x2, y2, gui_color32(255, 255, 255, 0));
#else
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
#endif /*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/
    
    gdi_layer_pop_clip();
}
#endif /* __MMI_FTE_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory10Screen
 * DESCRIPTION
 *  show category 10 screen(Small-list)
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory10Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, icon_width = 0, icon_height = 0;
    color c = UI_COLOR_BLACK;
    /*U8 flag = 0;*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_x = MMI_SMALL_SCREEN_X_OFFSET + 1;
    MMI_title_y += MMI_title_height + MMI_SMALL_SCREEN_Y_OFFSET;
    MMI_title_width -= (2 * MMI_SMALL_SCREEN_X_OFFSET + 1);

    gdi_layer_lock_frame_buffer();

    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);

    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);    /* early status icon */
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY10_ID, history_buffer);
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_register_hide_function(wgui_cat10_menu_hide_function);
    gui_vertical_scrollbar_register_hide_callback(&MMI_fixed_list_menu.vbar, wgui_cat10_vertical_scrollbar_hide_function);
    MMI_fixed_list_menu.normal_filler = (current_MMI_theme->small_list_menu_normal_filler);
    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->small_list_menu_highlight_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->small_list_menu_highlight_filler;  
#else /* __MMI_FTE_SUPPORT__ */
    fixed_list_backup_filler = MMI_fixed_list_menu.normal_filler;
    MMI_fixed_list_menu.normal_filler = (current_MMI_theme->small_list_menu_normal_filler);
#endif /* __MMI_FTE_SUPPORT__ */
    MMI_fixed_icontext_menuitem.normal_text_color = *(current_MMI_theme->small_list_menu_text_color);
    MMI_fixed_icontext_menuitem.selected_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);
    MMI_fixed_icontext_menuitem.focussed_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);

    wgui_set_disable_shortcut_display();
    wgui_fixed_list_begin_add_icontext_one_item();

    if (list_of_icons == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(list_of_items[i]), NULL, NULL);
        }
        /* 
         * when there is no icon before all items, set text position to GUI_ICONTEXT_MENUITEM_ICON_X
         */
        set_fixed_icontext_positions(GUI_ICONTEXT_MENUITEM_ICON_X, 0, GUI_ICONTEXT_MENUITEM_ICON_X, 0);
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
            if (list_of_icons[i] != 0)
            {
                /*flag = 1;*/
                gui_measure_image(get_image(list_of_icons[i]), &icon_width, &icon_height);
            }
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();

    if (number_of_items <= MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT)
    {
        cat10_list_item_num = number_of_items;
    }
    else
    {
        cat10_list_item_num = MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT;
    }
    wgui_fixed_list_resize_icontext_menu(MMI_SMALL_LIST_SCREEN_WIDTH - 3, get_menu_item_height() * cat10_list_item_num);
    resize_fixed_icontext_menuitems(MMI_SMALL_LIST_SCREEN_WIDTH - 3  - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_move_icontext_menu(MMI_SMALL_LIST_LEFT_OFFSET + MMI_FTE_TOOLBAR_START_X,
    UI_device_height - MMI_button_bar_height - (get_menu_item_height() * cat10_list_item_num + MMI_FTE_TOOLBAR_START_X));
#else /* __MMI_FTE_SUPPORT__ */
    wgui_fixed_list_move_icontext_menu(MMI_SMALL_LIST_LEFT_OFFSET + 1,
    UI_device_height - MMI_button_bar_height - (4 + get_menu_item_height() * cat10_list_item_num + 4 + 5) + 4);
#endif /* __MMI_FTE_SUPPORT__ */

#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_icontext_menuitem.focussed_without_sc_filler = current_MMI_theme->small_list_menu_highlight_filler;//small_list_menu_highlight_without_scrollbar_filler
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
#endif /* __MMI_FTE_SUPPORT__ */
    
    title_bg_id = IMG_FLEXIBLE_TITLEBAR_BG;

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY10_ID, 0, ExitCategory10Screen);
    dm_add_rectangle(c, DM_RECTANGLE_FILL_GRAYSCALE);
    dm_register_category_controlled_callback(DrawCate10CategoryControlArea);
    dm_redraw_category_screen();

}

#endif /* __MMI_SMALL_LIST_SCREEN__ */


#define MMI_SMALL_LIST_MAX_ITEM_COUNT 3
static S32 g_wgui_cat110_list_item_num = 0;
static GDI_HANDLE new_layer = GDI_ERROR_HANDLE;
/*****************************************************************************
 * FUNCTION
 *  wgui_cat110_cache_status_bg
 * DESCRIPTION
 *  function to cache the status icon bar area of wallpaper for category 110
 *  NOTE:
 *  it will be called on exiting idlescreen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat110_cache_status_bg(gdi_handle wallpaper_layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_layer = wallpaper_layer_handle;
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory110Screen
 * DESCRIPTION
 *  Exits the category110 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory110Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_small_screen();

    ExitListCategoryScreen();
    g_wgui_cat110_list_item_num = 0;
    gdi_layer_push_and_set_active((gdi_handle)(&GDI_LAYERS[1]));
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat110_menu_hide_function
 * DESCRIPTION
 *  function to draw background of small list menu for category 110
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat110_menu_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_bitblt(
        new_layer,
        0,
        UI_device_height - MMI_button_bar_height - get_menu_item_height() * g_wgui_cat110_list_item_num,
        MAIN_LCD_DEVICE_WIDTH,
        UI_device_height - MMI_button_bar_height,
        0,
        UI_device_height - MMI_button_bar_height - get_menu_item_height() * g_wgui_cat110_list_item_num);
#endif /* __GDI_MEMORY_PROFILE_2__ */

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_fill_transparent_color(x1, y1, x2, y2, gui_color32(255, 255, 255, 60));
#else
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
#endif /*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/
    gdi_layer_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat110_hide_status_icons_bar0
 * DESCRIPTION
 *  function to draw background of status icon bar0 for category 110
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat110_hide_status_icons_bar0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    /*
     * x1, y1, x2, y2 are not status bar area but an icon area in status bar
     * so when we call draw function, we need set x and y to status bar's start x and start y
     */
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);
    gdi_layer_set_clip(x1, y1, x2, y2);

    gdi_bitblt(
        new_layer,
        0,
        0,
        MAIN_LCD_DEVICE_WIDTH,
        MMI_status_bar_height,
        0,
        0);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory110Screen
 * DESCRIPTION
 *  show category 110 screen(Small-list)
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  list_of_descriptions    [IN]        Hint list of items
 *  flags                   [IN]        Flags(Reserved)
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory110Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    color c = UI_COLOR_BLACK;
    gdi_handle active_layer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();

    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);

#ifdef __GDI_MEMORY_PROFILE_2__
    wgui_status_icon_bar_register_hide_callback(WGUI_STATUS_ICON_BAR_H_BAR, wgui_cat110_hide_status_icons_bar0);
#endif /* __GDI_MEMORY_PROFILE_2__ */
    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY110_ID, history_buffer);
    wgui_fixed_list_register_hide_function(wgui_cat110_menu_hide_function);

    MMI_fixed_icontext_menuitem.normal_text_color = *(current_MMI_theme->small_list_menu_text_color);
    MMI_fixed_icontext_menuitem.selected_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);
    MMI_fixed_icontext_menuitem.focussed_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);

    wgui_set_disable_shortcut_display();
    wgui_fixed_list_begin_add_icontext_one_item();

    if (list_of_icons == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], NULL, NULL);
        }
        /*
         * when there is no icon before all items, set text position to GUI_ICONTEXT_MENUITEM_ICON_X
         */
        set_fixed_icontext_positions(GUI_ICONTEXT_MENUITEM_ICON_X, 0, GUI_ICONTEXT_MENUITEM_ICON_X, 0);
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], list_of_icons[i], NULL);
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();

    if (number_of_items <= MMI_SMALL_LIST_MAX_ITEM_COUNT)
    {
        g_wgui_cat110_list_item_num = number_of_items;
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
        resize_fixed_icontext_menuitems(MAIN_LCD_DEVICE_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
    }
    else
    {
        g_wgui_cat110_list_item_num = MMI_SMALL_LIST_MAX_ITEM_COUNT; 
        resize_fixed_icontext_menuitems(MAIN_LCD_DEVICE_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
    }
    wgui_fixed_list_resize_icontext_menu(
        MAIN_LCD_DEVICE_WIDTH,
        get_menu_item_height() * g_wgui_cat110_list_item_num);
    wgui_fixed_list_move_icontext_menu(
        0,
        UI_device_height - MMI_button_bar_height - get_menu_item_height() * g_wgui_cat110_list_item_num);

#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_get_active(&active_layer);

    gdi_layer_push_and_set_active(new_layer);
    gdi_bitblt(
        active_layer,
        0, 
        UI_device_height - MMI_button_bar_height - get_menu_item_height() * g_wgui_cat110_list_item_num,
        MAIN_LCD_DEVICE_WIDTH,
        UI_device_height - MMI_button_bar_height,
        0,
        MMI_button_bar_height);
    gdi_layer_pop_and_restore_active();
#endif /* __GDI_MEMORY_PROFILE_2__ */

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY110_ID, 0, ExitCategory110Screen);
    dm_add_rectangle(c, DM_RECTANGLE_FILL_GRAYSCALE);
    dm_redraw_category_screen();
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_exit
 * DESCRIPTION
 *  Exits the category1001 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1001_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_small_screen();
    ExitListCategoryScreen();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */  
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_menu_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1001_menu_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);

    gui_fill_rectangle(x1, y1, x2, y2, *(current_MMI_theme->lite_disp_scr_bg_color));

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_draw_ctrl_area
 * DESCRIPTION
 *  Cateogry 1001 control area redraw callback
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1001_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    x1 = MMI_fixed_list_menu.x - 1;
    y1 = MMI_fixed_list_menu.y - 1;
    x2 = x1 + MMI_fixed_list_menu.width + 1;
    y2 = y1 + MMI_fixed_list_menu.height + 1;
    
    gui_fill_rectangle(x1, y1, x2, y2, *(current_MMI_theme->list_normal_text_color));
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_pen_up_hdlr
 * DESCRIPTION
 *  Cateogry 1001 pen up handler
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1001_pen_up_hdlr(mmi_pen_point_struct point)
{
    UI_UNUSED_PARAMETER(point);
    GoBackHistory();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_pen_down_hdlr
 * DESCRIPTION
 *  Cateogry 1001 pen down handler
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1001_pen_down_hdlr(mmi_pen_point_struct point)
{
    UI_UNUSED_PARAMETER(point);
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_show
 * DESCRIPTION
 *  show category 1001 screen(Small-list)
 * PARAMETERS
 *  left_softkey                         [IN]        Left softkey label
 *  left_softkey_icon                    [IN]        Left softkey icon
 *  right_softkey                        [IN]        Right softkey label
 *  right_softkey_icon                   [IN]        Right softkey icon
 *  number_of_items                      [IN]        Item count
 *  list_of_items                        [IN]        String list of items
 *  list_of_icons                        [IN]        Icon list of items
 *  wgui_cat_inputbox_coordinate_struct  [IN]        inputbox coordinate
 *  highlighted_item                     [IN]        Index of highlighted item
 *  history_buffer                       [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1001_show(
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        wgui_cat_inputbox_coordinate_struct *inputbox,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ref_point_y, max_item_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();

    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);

    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CAT1001_ID, history_buffer);
    wgui_fixed_list_register_hide_function(wgui_cat1001_menu_hide_function);

    wgui_set_disable_shortcut_display();
    wgui_fixed_list_begin_add_icontext_one_item();

    if (list_of_icons == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], NULL, NULL);
        }
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], list_of_icons[i], NULL);
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();
    
    ref_point_y = ((UI_device_height - inputbox->height) >> 1) - WGUI_CAT1001_GAP;
    
    if (inputbox->y >= ref_point_y)
    {
        max_item_count = (inputbox->y - WGUI_CAT1001_GAP - MMI_status_bar_height) / get_menu_item_height();
        if (max_item_count < number_of_items)
        {
            wgui_fixed_list_resize_icontext_menu(inputbox->width, get_menu_item_height() * max_item_count);
            resize_fixed_icontext_menuitems(inputbox->width - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
            wgui_fixed_list_move_icontext_menu(
                inputbox->x,
                inputbox->y - get_menu_item_height() * max_item_count - WGUI_CAT1001_GAP);        
        }
        else
        {
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
            wgui_fixed_list_resize_icontext_menu(inputbox->width, get_menu_item_height() * number_of_items);
            resize_fixed_icontext_menuitems(inputbox->width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
            wgui_fixed_list_move_icontext_menu(
                inputbox->x,
                inputbox->y - get_menu_item_height() * number_of_items - WGUI_CAT1001_GAP);                
        }
    }
    else
    {
        max_item_count = (UI_device_height - 1 - inputbox->y - MMI_button_bar_height - inputbox->height - WGUI_CAT1001_GAP) / get_menu_item_height();
        if (max_item_count < number_of_items)
        {
            wgui_fixed_list_resize_icontext_menu(inputbox->width, get_menu_item_height() * max_item_count);
            resize_fixed_icontext_menuitems(inputbox->width - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
        }
        else
        {
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
            wgui_fixed_list_resize_icontext_menu(inputbox->width, get_menu_item_height() * number_of_items);        
            resize_fixed_icontext_menuitems(inputbox->width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
        }
        wgui_fixed_list_move_icontext_menu(
            inputbox->x,
            inputbox->y + inputbox->height + WGUI_CAT1001_GAP);
    }

    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->list_selected_item_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->list_selected_item_filler;
    MMI_fixed_icontext_menuitem.focussed_without_sc_filler = current_MMI_theme->list_selected_item_filler;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat1001_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat1001_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
#endif /* __MMI_TOUCH_SCREEN__ */
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CAT1001_ID, 0, wgui_cat1001_exit);
    dm_add_rectangle(UI_COLOR_BLACK, DM_RECTANGLE_FILL_GRAYSCALE);
    dm_register_category_controlled_callback(wgui_cat1001_draw_ctrl_area);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  set_list_menu_category140_history
 * DESCRIPTION
 *  Sets the history data for the list menu of category140 (check box list)
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [IN]        Buffer from which history data is taken
 * RETURNS
 *  byte              Returns true if the history ID is valid
 *****************************************************************************/
U8 set_list_menu_category140_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history_cat140 *h = (list_menu_category_history_cat140*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_fixed_list_menu.highlighted_item = h->highlighted_item;
            MMI_fixed_list_menu.first_displayed_item = h->first_displayed_item;
            MMI_fixed_list_menu.last_displayed_item = h->last_displayed_item;
		#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
			MMI_fixed_list_menu.first_displayed_offset = h->first_displayed_offset;
		    MMI_fixed_list_menu.last_displayed_offset = h->last_displayed_offset;
		#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
            MMI_fixed_list_menu.displayed_items = h->displayed_items;
            MMI_fixed_list_menu.flags = h->flags;
            item_checked = h->state;
			for (i = 0; i < h->no_of_items; i++)
            {
                if (h->list_of_states[i] == 1)
                {
                    MMI_fixed_twostate_menuitems[i].flags |= UI_MENUITEM_STATE_SELECTED;
                }
                else
                {
                    MMI_fixed_twostate_menuitems[i].flags &= ~UI_MENUITEM_STATE_SELECTED;
                }
            }
            return (1);
        }
    }
    return (0);
}   /* end of set_list_menu_category140_history */


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history140
 * DESCRIPTION
 *  Gets the history data for the list menu of category140 (check box list)
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [OUT]        Buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void get_list_menu_category_history140(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);
		S32 i;

        list_menu_category_history_cat140 *h = (list_menu_category_history_cat140*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = (S16) MMI_fixed_list_menu.highlighted_item;
        h->first_displayed_item = (S16) MMI_fixed_list_menu.first_displayed_item;
        h->last_displayed_item = (S16) MMI_fixed_list_menu.last_displayed_item;
	#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
		h->first_displayed_offset = MMI_fixed_list_menu.first_displayed_offset;
	    h->last_displayed_offset = (S16)MMI_fixed_list_menu.last_displayed_offset;
	#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */
        h->displayed_items = (S16) MMI_fixed_list_menu.displayed_items;
        h->flags = MMI_fixed_list_menu.flags;
        h->no_of_items = MMI_fixed_list_menu.n_items;
        h->state = (S8) item_checked;
		for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
        {
            if (MMI_fixed_twostate_menuitems[i].flags & UI_MENUITEM_STATE_SELECTED)
            {
                h->list_of_states[i] = 1;
            }
            else
            {
                h->list_of_states[i] = 0;
            }
        }
    }
}   /* end of get_list_menu_category_history140 */


/*****************************************************************************
 * FUNCTION
 *  GetCategory140HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for Category140 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 GetCategory140HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history_cat140));
}   /* end of GetCategory140HistorySize */


/*****************************************************************************
 * FUNCTION
 *  GetCategory140History
 * DESCRIPTION
 *  Gets the history buffer for Category140 screen
 * PARAMETERS
 *  history_buffer      [OUT]        History_buffer is a pointer to the buffer where the history data is to be stored      (pre-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetCategory140History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history140(MMI_CATEGORY140_ID, history_buffer);
    return (history_buffer);
}   /* end of GetCategory140History */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory140Screen
 * DESCRIPTION
 *  Displays the Category140 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_states              [IN]        Item state list
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory140Screen(
        U16 title,
        U16 title_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory140Screen_ext(
        (U8*)get_string(title),
        get_image(title_icon),
        number_of_items,
        list_of_items,
        list_of_states,
        highlighted_item,
        history_buffer);	
}   /* end of ShowCategory140Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory140Screen_ext
 * DESCRIPTION
 *  Displays the Category140 screen extention
 * PARAMETERS
 *  title                       [IN]        Title String for the screen
 *  title_icon                  [IN]        Icon pointer displayed with the title
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_states              [IN]        Item state list
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory140Screen_ext(
                U8 * title,
                U8 * title_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 *list_of_states,
                S32 highlighted_item,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY140_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	dm_add_title((UI_string_type)title, title_icon);
	dm_add_softkey_id((MMI_STR_ID)STR_GLOBAL_OK, (MMI_STR_ID)STR_GLOBAL_OK);
    wgui_fixed_list_create_twostate_menu(
        get_image(CHECKBOX_ON_IMAGE_ID),
        get_image(CHECKBOX_OFF_IMAGE_ID),
        number_of_items,
        WGUI_LIST_INVALID_HIGHLIGHT,
        0,
        0,
        NULL);

    set_left_softkey_function(toggle_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    SetCenterSoftkeyFunction(toggle_check_list_handle_left_softkey_up, KEY_EVENT_UP);
    checklist_category_menu_item_states = list_of_states;
	item_checked = 0;
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    h_flag = set_list_menu_category140_history((U16)CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    h_flag = set_list_menu_category140_history(MMI_CATEGORY140_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    if (h_flag)
    {
        list_menu_category_history_cat140 *h = (list_menu_category_history_cat140*) history_buffer;
        memcpy((U8*)list_of_states, (U8*)h->list_of_states, number_of_items);
    }

    wgui_fixed_list_add_twostate_items(list_of_items, list_of_states, NULL);
    wgui_fixed_list_override_twostate_highlight_handler(toggle_check_list_highlight_handler);
    wgui_cat_set_right_softkey_function(item_checked);

	
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */

    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }
    fixed_list_goto_item_no_redraw(highlighted_item);
    resize_fixed_twostate_menuitems_to_list_width();

#ifdef __MMI_TOUCH_SCREEN__
    MMI_fixed_list_menu.disable_up_select = MMI_FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */

    gdi_layer_unlock_frame_buffer();

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category(
        CatId,
        s32flags,
        ExitCategoryCommonScreen,
        GetCategory140History,
        GetCategory140HistorySize);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category(
        MMI_CATEGORY140_ID,
        0,
        ExitCategoryCommonScreen,
        GetCategory140History,
        GetCategory140HistorySize);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();

}   /* end of ShowCategory140Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory803Screen_ext
 * DESCRIPTION
 *  Shows category 803 screen (Cascade Menu check box).
 * PARAMETERS
 *  title                   [IN]        Title string for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_states           [IN]        List of states of  items
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory803Screen(
        U16 title,
        U16 title_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,         
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory803Screen_ext((U8*)get_string(title),
        get_image(title_icon),
        number_of_items,
        list_of_items,
        list_of_states,
        current_cm_level,
        max_cm_level,
        highlighted_item,
        history_buffer);    
}




/*****************************************************************************
 * FUNCTION
 *  ShowCategory803Screen_ext
 * DESCRIPTION
 *  Shows category 803 screen (Cascade Menu check box).
 * PARAMETERS
 *  title                   [IN]        Title string for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_states           [IN]        List of states of  items
 *  current_cm_level        [IN]        Cascade menu current level
 *  max_cm_level            [IN]        Cascade menu max level (ONLY SUPPORT 2 now)
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory803Screen_ext(
        U8* title,
        U8* title_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,        
        S32 current_cm_level,
        S32 max_cm_level,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag, bk_flag;
    S32 menu_height, menu_width, menu_x, menu_y;
    S32 max_item_text_width = 0, text_width, text_height;
    MMI_BOOL show_submenu_indicator = MMI_TRUE;
    S32 arrow_width = 0, arrow_height = 0;
    MMI_BOOL show_scrollbar;
    MMI_BOOL is_rotated = MMI_FALSE;
    cascading_position_values param;
	S32 var;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	wgui_cat800_common_setting();

    wgui_fixed_list_create_twostate_menu(
        get_image(CHECKBOX_ON_IMAGE_ID),
        get_image(CHECKBOX_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        0,
        NULL);
    
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
#endif

    dm_add_title((UI_string_type)title, title_icon);
	dm_add_softkey_id((MMI_STR_ID)STR_GLOBAL_OK, (MMI_STR_ID)STR_GLOBAL_DONE);

    /* use cascade menu theme */
    MMI_fixed_twostate_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_twostate_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;   
    MMI_fixed_twostate_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->cascade_menu_background_filler;
#endif
    MMI_fixed_twostate_menuitem.normal_text_color = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_twostate_menuitem.disabled_text_color = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_twostate_menuitem.selected_text_color = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_twostate_menuitem.focussed_text_color = *current_MMI_theme->cascade_menu_selected_text_color;

    /* do not display the shortcut */
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    
#ifdef __MMI_FTE_SUPPORT__
    wgui_fixed_list_register_hide_function(CategoryCascadingHideFunction);
#endif
   
    /* List */
    set_left_softkey_function(toggle_check_list_handle_left_softkey_up, KEY_EVENT_UP);

    checklist_category_menu_item_states = list_of_states;
	item_checked = 0;
    h_flag = set_list_menu_category140_history(MMI_CATEGORY_CASCADING_MENU_ID, history_buffer);

    if (h_flag)
    {
        list_menu_category_history_cat140 *h = (list_menu_category_history_cat140*) history_buffer;
        memcpy((U8*)list_of_states, (U8*)h->list_of_states, number_of_items);
    }	
    
    register_fixed_list_highlight_handler(toggle_check_list_highlight_handler);

    /* measure submenu arrow dimension */
    gui_measure_image(get_image(CHECKBOX_ON_IMAGE_ID), &arrow_width, &arrow_height);
    /* add menu items */
    wgui_fixed_list_begin_add_twostate_one_item();	
    for (i = 0; i < number_of_items; i++)
    {   
        wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], NULL);
        if (list_of_states[i])
        {
            select_fixed_twostate_item(i);
        }

        /* find the max width of menu item strings for the second level */
        gui_measure_string((UI_string_type)list_of_items[i], &text_width, &text_height);
        
        if (text_width > max_item_text_width)
        {
            max_item_text_width = text_width;
        }
    }
	wgui_cat_set_right_softkey_function(item_checked);

    MMI_fixed_list_menu.flags |= UI_LIST_MENU_ALIGN_TO_TOP;

    /* check if rotated */
#ifdef __MMI_SCREEN_ROTATE__
    is_rotated = mmi_frm_is_screen_width_height_swapped();
#endif

    /* calculate menu height */
    wgui_cat800_calc_menu_height(is_rotated, number_of_items, &menu_height, &show_scrollbar);

    param.max_item_text_width = max_item_text_width;
    param.show_submenu_indicator = show_submenu_indicator;

    /* calculate menu width */
    if (current_cm_level == 0)
    {
        /* 1st level, full width */
        wgui_cat800_set_width_for_first_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
    else
    {
        /* 2nd level of CM */        
        /* leave right and left text gaps inside the highlight */
        wgui_cat800_set_width_for_second_level(&param, is_rotated, show_scrollbar, arrow_width);
    }
        
    menu_x = param.menu_x;
	var = (CASCADING_MENU_TEXT_LEFT_GAP + CASCADING_MENU_TEXT_RIGHT_GAP) * 10;
    if (menu_x > (arrow_width + var))
    {
        menu_x -= (arrow_width + var);
    }   
    menu_width = param.menu_width + arrow_width + var;
	var = (CASCADING_MENU_TEXT_LEFT_GAP + CASCADING_MENU_TEXT_RIGHT_GAP) * 2;
    if (menu_x > var)
    {
        menu_x -= var;
        menu_width += var;
    }   

    menu_y = param.menu_y;
    max_item_text_width = param.max_item_text_width;

#ifdef __MMI_FTE_SUPPORT__
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_Y_GAP >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_Y_GAP;
    }
#else
    /* aligned to bottom */
    if (menu_y + menu_height - CASCADING_MENU_BORDER_SIZE >= UI_device_height - MMI_SOFTKEY_HEIGHT)
    {   
        menu_y = UI_device_height - MMI_SOFTKEY_HEIGHT - menu_height - 1 + CASCADING_MENU_BORDER_SIZE;
    }
#endif

    /* resize menu item depending on the scroll bar is shown or not */
    var = menu_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
    if (show_scrollbar)
    {
        var = var - MMI_fixed_list_menu.vbar.width;
    }
	resize_fixed_twostate_menuitems(var, 0);

    /* decrease the top and bottom border size to get the true menu height */
    menu_height -= CASCADING_MENU_BORDER_SIZE * 2;

    resize_fixed_list(menu_width, menu_height); 

    /* change the fixed menu top offset */
    MMI_fixed_list_menu.top = CASCADING_MENU_TOP_GAP;
    
    if (current_cm_level != 0)
    {
        if (menu_x > wgui_cat_cascading_menu_last_width)
            menu_x = wgui_cat_cascading_menu_last_width;
    }
    move_fixed_list(menu_x, menu_y);

    wgui_cat_cascading_menu_last_width = menu_x + menu_width - 1;

    // TODO: Fix the problem that popup DARKEN effect will not apply to the cascading menu.
    /* only darken the first level of cascading menu */

    /* draw darken area for the previous full screen */
	wgui_cascading_menu_darken_full_screen(current_cm_level, is_rotated);

    bk_flag = WGUI_CAT_DRAW_801_BK_NO;
    if (mmi_frm_group_get_active_id() == GRP_ID_INVALID || !h_flag)
    {
        bk_flag = WGUI_CAT_DRAW_801_BK;
    }
    wgui_cat800_draw_background(menu_x, menu_y, menu_width, menu_height, bk_flag);
  
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
	fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    /* No blt is needed here because of DM_FULL_SCREEN_COORDINATE_FLAG. */
    gdi_layer_unlock_frame_buffer();

    if (is_rotated)
    {
        wgui_cat800_register_hide_keys();
    }

	wgui_cat_setup_category(
		MMI_CATEGORY_CASCADING_MENU_ID,
		0,
		ExitCategory800Screen,
		GetCategory140History,
		GetCategory140HistorySize);
    dm_set_dm_data_flag(DM_NO_FLAGS);
    dm_redraw_category_screen();    

    /* save current menu x1 and x2 for the second level */
    g_mmi_category800_previous_menu_x1 = MMI_fixed_list_menu.x;
    g_mmi_category800_previous_menu_x2 = MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory150Screen
 * DESCRIPTION
 *  Displays the category screen 153
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items
 *  list_of_items1          [IN]        Strings of item1
 *  list_of_items2          [IN]        Strings if item2
 *  highlighted_item        [IN]        Highlighted index
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory150Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, w;
	S32 w1, h1, w1_max = 0;
	S32 w2, h2, w2_max = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    wgui_fixed_list_create_multi_icontext_menu(
        0,
        2,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        0,
        MMI_CATEGORY150_ID,
        history_buffer);
	for(i = 0; i< number_of_items; i++)
	{
		gui_measure_string((UI_string_type) list_of_items1[i], &w1, &h1);
		gui_measure_string((UI_string_type) list_of_items2[i], &w2, &h2);
		if(w1_max < w1)
		{
			w1_max = w1;
		}
		if(w2_max < w2)
		{
			w2_max = w2;
		}
	}
    w = UI_device_width - MMI_fixed_list_menu.vbar.width - 4;

	if((w1_max + w2_max) < w)
	{
		w1 = w1_max;
		w2 = w - w1;
	}
	else
	{
		w1 = w>>1;
		w2 = w>>1;
	}

    set_fixed_icontext_list_text_coordinates(0, 2, 0, w1, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(1, w1 + 2, 0, w2, MMI_MENUITEM_HEIGHT);

    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[1] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[2] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);

    MMI_fixed_icontext_list_menuitem.flags |= (UI_MENUITEM_RIGHT_JUSTIFY_COL2);
    MMI_fixed_list_menu.item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;

    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[2];
        items[0] = list_of_items1[i];
        items[1] = list_of_items2[i];
        wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
    // TODO: GUI should provide an API to do this.
    /* register dummmy highlight item function to prevent scrolling and displaying highlight. */    

    //MMI_fixed_list_menu.item_highlight_function = UI_fixed_menuitem_dummy_highlight_function;
    resize_fixed_icontext_list_menuitems_to_list_width();

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY150_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitListCategoryScreen);
    dm_redraw_category_screen();
}   /* end of ShowCategory150Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory153Screen
 * DESCRIPTION
 *  Displays the category screen 153
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items
 *  list_of_items1          [IN]        Strings of item1
 *  list_of_items2          [IN]        Strings if item2
 *  highlighted_item        [IN]        Highlighted index
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory153Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlighted_item = -1;
    wgui_set_disable_shortcut_display();
    ShowCategory150Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_items1,
        list_of_items2,
        highlighted_item,
        history_buffer);
    /* Disable pen on list menu */
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_PEN;

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    clear_key_handlers();
}   /* end of ShowCategory153Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory170Screen_int
 * DESCRIPTION
 *  Displays the Dynamic menu screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        Flags (Always set to 0. Reserved for future use.)
 *  highlighted_item        [IN]        Highlighted index
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory170Screen_int(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory1704Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons,
        NULL,
        flags,
        MMI_FALSE,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory170Screen */


/*****************************************************************************
 * FUNCTION
 *  category172_list_highlight_handler
 * DESCRIPTION
 *  highlight handler of category 172
 * PARAMETERS
 *  item_index      [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void category172_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
#ifndef __MMI_RADIO_BUTTON_HIGHLIGHT_NO_SELECT__
    radio_list_handle_item_select_no_draw(item_index);
#endif 
    MMI_highlighted_item_text = get_item_text(item_index);
    gdi_layer_lock_frame_buffer();
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gdi_layer_unlock_frame_buffer();
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}   /* end of category172_list_highlight_handler */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory172Screen_int
 * DESCRIPTION
 *  Displays the Dynamic radio list
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        Array of items
 *  flags                   [IN]        Flags (Always set to 0. Reserved for future use.)
 *  highlighted_item        [IN]        Highlighted index
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory172Screen_int(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
#if defined(__WGUI_CATE_LIST_RADIO_WITH_SCROLL_TITLE_MAP__)
    ShowCategory109Screen_ext_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_RADIO_WITH_SCROLL_TITLE_MAP__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag = 0;
    S32 selected_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(flags);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);

    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    wgui_fixed_list_create_twostate_menu(
        get_image(RADIO_ON_IMAGE_ID),
        get_image(RADIO_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        0,
        NULL);
    
    h_flag = wgui_set_twostate_radio_list_history(MMI_CATEGORY172_ID, history_buffer);
    if(!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
        selected_index = highlighted_item;
    }
    else
    {
        list_menu_two_state_radio_history *h = (list_menu_two_state_radio_history*) history_buffer;
        selected_index = h->selected_item;
    }

    wgui_fixed_list_begin_add_twostate_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], NULL);
    }
    wgui_fixed_list_end_add_twostate_one_item();

    wgui_fixed_list_override_twostate_highlight_handler(category172_list_highlight_handler);
    select_fixed_twostate_item(selected_index);
    //setup_scrolling_title();

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category(
		MMI_CATEGORY172_ID,
	#ifdef __MMI_WALLPAPER_ON_BOTTOM__
	    DM_CLEAR_SCREEN_BACKGROUND | DM_SCROLL_TITLE,
	#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
	    DM_SCROLL_TITLE,
	#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
		ExitCategory172Screen,
		wgui_get_twostate_radio_list_history,
		wgui_get_twostate_radio_list_history_size);
    dm_redraw_category_screen();
#endif /* __WGUI_CATE_LIST_RADIO_WITH_SCROLL_TITLE_MAP__ */
}   /* end of ShowCategory172Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory172Screen
 * DESCRIPTION
 *  Exits the dynamic menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory172Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    close_scrolling_title();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
	two_state_radio_list_history_id = 0;
}   /* end of ExitCategory172Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory174Screen
 * DESCRIPTION
 *  Exits the dynamic menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory174Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    close_scrolling_title();
    ClearHighlightHandler();
    reset_softkeys();
    reset_pop_up_descriptions();
    reset_menu_shortcut_handler();
    reset_fixed_list();
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_reset_atv_sms_struct();
#endif /* __ATV_SMS_SUPPORT__ */
}   /* end of ExitCategory174Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory1704Screen
 * DESCRIPTION
 *  Displays the Dynamic menu screen with description.
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of descriptions
 *  flags                       [IN]        Flags (Always set to 0. Reserved for future use.)
 *  scroll_text                 [IN]        title text scroll or not
 *  highlighted_item            [IN]        Highlighted index
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory1704Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        MMI_BOOL scroll_text,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 s32flags;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY174_ID;
#else /* __ATV_SMS_SUPPORT__ */
    S32 i;
    U8 flag = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(flags);

    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
    }
    wgui_fixed_list_create_icontext_menu(
		number_of_items, 
		highlighted_item,
		flags,
		(U16)CatId,
		history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_list_create_icontext_menu(
        number_of_items, 
        highlighted_item,
        0,
        MMI_CATEGORY174_ID,
        history_buffer);
    for (i = 0; i < number_of_items; i++)
    {
        if (list_of_icons[i] != UI_NULL_IMAGE)
        {
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);
    }	 
#endif /* __ATV_SMS_SUPPORT__ */

#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    wgui_cat_configure_slim_hint();
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */
    wgui_fixed_list_add_icontext_items(list_of_items, list_of_icons, list_of_descriptions);
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    wgui_cat_set_default_empty_descriptions(number_of_items);
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ */

    gdi_layer_unlock_frame_buffer();

    if(scroll_text)
    {
        s32flags = DM_SCROLL_TITLE;
    }
    else
    {
    	s32flags = 0;
    }
	
	s32flags |= DM_CLEAR_SCREEN_BACKGROUND;

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, s32flags, ExitCategory174Screen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY174_ID, s32flags, ExitCategory174Screen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory1704Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory174Screen_int
 * DESCRIPTION
 *  Displays the Dynamic menu screen with description.
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of descriptions
 *  flags                       [IN]        Flags (Always set to 0. Reserved for future use.)
 *  highlighted_item            [IN]        Highlighted index
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory174Screen_int(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory1704Screen(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_descriptions,
        flags,
        MMI_TRUE,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory174Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory109Screen_int
 * DESCRIPTION
 *  (twostate menuitem with hint, and no LSK function)
 *  Displays the category109 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Items count in list
 *  list_of_items               [IN]        String of list
 *  list_of_descriptions        [IN]        Description of list
 *  highlighted_item            [IN]        Index of highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory109Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory109Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_descriptions,
        highlighted_item,
        history_buffer);

}
/*****************************************************************************
 * FUNCTION
 *  ShowCategory109Screen_ext_int
 * DESCRIPTION
 *  (twostate menuitem with hint, and no LSK function)
 *  Displays the category109 screen
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Items count in list
 *  list_of_items               [IN]        String of list
 *  list_of_descriptions        [IN]        Description of list
 *  highlighted_item            [IN]        Index of highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory109Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 h_flag = 0;
    S32 selected_index = 0;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY109_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    /* Setup menuitem */
    wgui_fixed_list_create_twostate_menu(
        get_image(RADIO_ON_IMAGE_ID),
        get_image(RADIO_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item,
        0,
        0,
        NULL);

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    h_flag = wgui_set_twostate_radio_list_history((U16)CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    h_flag = wgui_set_twostate_radio_list_history(MMI_CATEGORY109_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    if(!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
        selected_index = highlighted_item;
    }
    else
    {
        list_menu_two_state_radio_history *h = (list_menu_two_state_radio_history*) history_buffer;
        selected_index = h->selected_item;
    }

    wgui_fixed_list_begin_add_twostate_one_item();
	for (i = 0; i < number_of_items; i++)
	{
	    if (list_of_descriptions == NULL)
	    {
	        wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], NULL);
	    }
		else
		{
		    wgui_fixed_list_add_twostate_one_item(i, list_of_items[i], list_of_descriptions[i]);
		}
	}

#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__) || defined(__WGUI_CATE_LIST_HIGHLIGHTED_HINTS_IN_MENUITEM__)
    wgui_cat_configure_slim_hint();
    wgui_cat_set_hint_in_menuitem(list_of_descriptions, number_of_items);
    wgui_cat_set_default_empty_descriptions(number_of_items);
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ || __WGUI_CATE_LIST_HIGHLIGHTED_HINTS_IN_MENUITEM__ */

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */

    wgui_fixed_list_end_add_twostate_one_item();
    wgui_fixed_list_override_twostate_highlight_handler(standard_radio_list_highlight_handler);
    select_fixed_twostate_item(selected_index);

    gdi_layer_unlock_frame_buffer();

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category(
        CatId,
        s32flags,
        ExitCategory36Screen,
        wgui_get_twostate_radio_list_history,
        wgui_get_twostate_radio_list_history_size);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category(
        MMI_CATEGORY109_ID,
        0,
        ExitCategory36Screen,
        wgui_get_twostate_radio_list_history,
        wgui_get_twostate_radio_list_history_size);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory109Screen */

U8 category89_string_list[MAX_CATEGORY89_STRINGS][MAX_CATEGORY89_STRING_LENGTH];
extern S32 GUI_current_fixed_icontext_list_menuitem_column;

/*****************************************************************************
 * FUNCTION
 *  ShowCategory89Screen_int
 * DESCRIPTION
 *  Displays the Numbered Items screen(with description)
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory89Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __WGUI_CATE_LIST_NUMBERED_LIST_MAP__
    ShowCategory53Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_NUMBERED_LIST_MAP__ */
    ShowCategory89Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);
#endif /* __WGUI_CATE_LIST_NUMBERED_LIST_MAP__ */
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory89Screen_ext_int
 * DESCRIPTION
 *  Displays the Numbered Items screen(with description)
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory89Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
#if defined(__WGUI_CATE_LIST_NUMBERED_LIST_MAP__) || defined(__MMI_MAINLCD_128X64__)
    ShowCategory353Screen_ext_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        NULL,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer);
#else /* __WGUI_CATE_LIST_NUMBERED_LIST_MAP__ || __MMI_MAINLCD_128X64__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 text1_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(number_of_items <= MAX_CATEGORY89_STRINGS);

    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);

    wgui_fixed_list_create_multi_icontext_menu(
        0,
        2,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        0,
        MMI_CATEGORY89_ID,
        history_buffer);

    GUI_current_fixed_icontext_list_menuitem_column = 1;

    /* compute string width */
    {
        U16 temp[] = L"0123456789.";
        S32 w, h;

        gui_set_font(&MMI_medium_font);
        mmi_fe_measure_string_by_char_num((U8*)temp, 3 /* 00. */, &w, &h);
        text1_width = w;
    }

    set_fixed_icontext_list_text_coordinates(0,
        GUI_TEXT_MENUITEM_TEXT_X, 0,
        text1_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_text_coordinates(1,
        GUI_TEXT_MENUITEM_TEXT_X + text1_width, 0,
        MMI_fixed_icontext_list_menuitem.width - (GUI_TEXT_MENUITEM_TEXT_X + 1) - text1_width, MMI_MENUITEM_HEIGHT);
#ifdef __MMI_MAINLCD_320X480__  
	MMI_fixed_icontext_list_menuitem.normal_text_colors[0] = *current_MMI_theme->list_normal_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[0] = *current_MMI_theme->list_selected_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[0] = *current_MMI_theme->list_selected_text_color;
	MMI_fixed_icontext_list_menuitem.normal_text_colors[1] = *current_MMI_theme->list_normal_text_color;
    MMI_fixed_icontext_list_menuitem.focussed_text_colors[1] = *current_MMI_theme->list_selected_text_color;
    MMI_fixed_icontext_list_menuitem.selected_text_colors[1] = *current_MMI_theme->list_selected_text_color;
#endif

    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[1] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[2] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);

    wgui_fixed_list_begin_add_multi_icontext_one_item();

    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[2];
        gui_itoa(i + 1, (UI_string_type) category89_string_list[i], 10);
        gui_strcat((UI_string_type) category89_string_list[i], (UI_string_type) ".\0");
        items[0] = category89_string_list[i];
        items[1] = list_of_items[i];
        if(list_of_descriptions == NULL)
        {
            wgui_fixed_list_add_multi_icontext_one_item(i, items,  NULL, NULL);
        }
        else
        {
            wgui_fixed_list_add_multi_icontext_one_item(i, items, NULL, list_of_descriptions[i]);
        }
        
        MMI_fixed_icontext_list_menuitems[i].flags |= UI_MENUITEM_TEXT_COL1_IS_NUMBER;
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY89_ID, 0, ExitListCategoryScreen);
    dm_redraw_category_screen();
#endif /* __WGUI_CATE_LIST_NUMBERED_LIST_MAP__ || __MMI_MAINLCD_128X64__*/
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory89Screen
 * DESCRIPTION
 *  Exits the Numbered Items screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory89Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GUI_current_fixed_icontext_list_menuitem_column = 0;
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_pop_up_descriptions();
    reset_fixed_list();
}


/*************************************************************
 *
 *Display category155 for screen with hide menu when go back.
 *
 ************************************************************/
 typedef struct _list_menu_category_history155
{
    U16 history_ID;
    S16 highlighted_item;
    S16 first_displayed_item;
    S16 last_displayed_item;
    S16 displayed_items;
	U16 highlighted_menu_id;
    U32 flags;
} list_menu_category_history_cat155;

static U16 g_cat155_highligt_menu_id;
static U16 g_cat155_paraent_id;


/*****************************************************************************
 * FUNCTION
 *  wgui_cat155_list_highlight_handler
 * DESCRIPTION
 *  System Highlight handler
 *  
 *  Internal function
 * PARAMETERS
 *  item_index      [IN]        Index of current highlight item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat155_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_cat155_highligt_menu_id = GetSeqItemId_Ext(g_cat155_paraent_id, (U16)item_index);
	standard_list_highlight_handler(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  set_list_menu_category155_history
 * DESCRIPTION
 *  Sets the history data for the list menu of category152
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [IN]        Buffer from which history data is taken
 * RETURNS
 *  byte              Returns true if the history ID is valid
 *****************************************************************************/
U8 set_list_menu_category155_history(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        list_menu_category_history_cat155 *h = (list_menu_category_history_cat155*) history_buffer;

        if (history_valid(h->history_ID, history_ID))
        {
            MMI_fixed_list_menu.highlighted_item = h->highlighted_item;
            MMI_fixed_list_menu.first_displayed_item = h->first_displayed_item;
            MMI_fixed_list_menu.last_displayed_item = h->last_displayed_item;
            MMI_fixed_list_menu.displayed_items = h->displayed_items;
            MMI_fixed_list_menu.flags = h->flags;
            g_cat155_highligt_menu_id = h->highlighted_menu_id;
 
            return (1);
        }
    }
    return (0);
}   /* end of set_list_menu_category155_history */


/*****************************************************************************
 * FUNCTION
 *  get_list_menu_category_history155
 * DESCRIPTION
 *  Gets the history data for the list menu of category152
 *  from the given history buffer
 * PARAMETERS
 *  history_ID          [IN]        The ID used by category screens
 *  history_buffer      [OUT]        Buffer from which history data is taken
 * RETURNS
 *  void
 *****************************************************************************/
void get_list_menu_category_history155(U16 history_ID, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
        U16 hID = (U16) (history_ID | 0x8000);

        list_menu_category_history_cat155 *h = (list_menu_category_history_cat155*) history_buffer;

        h->history_ID = hID;
        h->highlighted_item = (S16) MMI_fixed_list_menu.highlighted_item;
        h->first_displayed_item = (S16) MMI_fixed_list_menu.first_displayed_item;
        h->last_displayed_item = (S16) MMI_fixed_list_menu.last_displayed_item;
        h->displayed_items = (S16) MMI_fixed_list_menu.displayed_items;
        h->flags = MMI_fixed_list_menu.flags;
        h->highlighted_menu_id = g_cat155_highligt_menu_id;
    }
}   /* end of get_list_menu_category_history155 */


/*****************************************************************************
 * FUNCTION
 *  GetCategory152HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for Category155 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 GetCategory155HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history_cat155));
}   /* end of GetCategory152HistorySize */


/*****************************************************************************
 * FUNCTION
 *  GetCategory155History
 * DESCRIPTION
 *  Gets the history buffer for Category155 screen
 * PARAMETERS
 *  history_buffer      [OUT]        History_buffer is a pointer to the buffer where the history data is to be stored      (pre-allocated)
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetCategory155History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history155(MMI_CATEGORY52_ID, history_buffer);
    return (history_buffer);
}   /* end of GetCategory155History */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory155Screen_int
 * DESCRIPTION
 *  Displays the category155 screen ( List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  right_softkey               [IN]        Right softkey label
 *  paraent_id                  [IN]        Paraent menu id
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory155Screen_int(
    UI_string_type title,
    PU8 title_icon,
    UI_string_type left_softkey,
    UI_string_type right_softkey,
    U16 paraent_id, /* get item count and item string */
    U16 *item_icons,
    U8 **item_popups,
    S32 flag,
    S32 highlighted_item,
    U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_count;
    U16 item_texts[MAX_SUB_MENUS];
    S32 i;
	PU8 icon = NULL;
	MMI_BOOL flags = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat155_paraent_id = paraent_id;
    item_count = GetNumOfChild_Ext(paraent_id);
    GetSequenceStringIds_Ext(paraent_id, item_texts);
    gdi_layer_lock_frame_buffer();
	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    wgui_fixed_list_create_icontext_menu(item_count, WGUI_LIST_INVALID_HIGHLIGHT, 0, 0, NULL);
    wgui_fixed_list_override_icontext_highlight_handler(wgui_cat155_list_highlight_handler);
	MMI_fixed_list_menu.highlighted_item = highlighted_item;
    if (set_list_menu_category155_history(MMI_CATEGORY52_ID, history_buffer))
    {
        if(GetSeqItemId_Ext(g_cat155_paraent_id, (U16)MMI_fixed_list_menu.highlighted_item) != g_cat155_highligt_menu_id)
        {
            i = GetChildMenuIDIndexByParentMenuID_Ext(g_cat155_paraent_id, g_cat155_highligt_menu_id);
            if (-1 != i)
            {
                MMI_fixed_list_menu.highlighted_item = i;
            }
        }
    }
    
    wgui_fixed_list_begin_add_icontext_one_item();
    for (i = 0; i < item_count; i++)
    {
        icon = NULL;
        if (item_icons != NULL)
        {
            icon = wgui_get_list_menu_icon(i, item_icons[i]);
        }
        if (icon != NULL)
        {
            flags = MMI_TRUE;
        }
        if (item_popups != NULL)
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(item_texts[i]), icon, item_popups[i]);
        }
        else
        {
            wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(item_texts[i]), icon, NULL);
        }
    }
	if (!flags)
	{
	    set_fixed_text_positions(GUI_TEXT_MENUITEM_TEXT_X, 0);
	}
	
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__) || defined(__WGUI_CATE_LIST_HIGHLIGHTED_HINTS_IN_MENUITEM__)
    wgui_cat_configure_slim_hint();
    wgui_cat_set_hint_in_menuitem(item_popups, item_count);
    wgui_cat_set_default_empty_descriptions(item_count);
#endif /* __WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__ || __WGUI_CATE_LIST_HIGHLIGHTED_HINTS_IN_MENUITEM__ */
	
    wgui_fixed_list_end_add_icontext_one_item();
        
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category(
		MMI_CATEGORY52_ID,
		0,
		ExitListCategoryScreen,
		GetCategory155History,
		GetCategory155HistorySize);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory525Screen
 * DESCRIPTION
 *  Exit the category525 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory525Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitListCategoryScreen();
    wgui_close_horizontal_tab_bar();
    
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory525Screen
 * DESCRIPTION
 *  Displays the category525 screen ( List menu with description and with tabbar )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  n_tabs                      [IN]        number of tab
 *  highlighted_tab             [IN]        highlighted tab
 *  tab_items                   [IN]        tab item 
 *  contain_hint                [IN]        contain hint or not
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory525Screen(
                           U16 title,
                           U16 title_icon,
                           U16 left_softkey,
                           U16 left_softkey_icon,
                           U16 right_softkey,
                           U16 right_softkey_icon,
                           S8 n_tabs,
                           S8 highlighted_tab,
                           tab_bar_item_type *tab_items,
                           MMI_BOOL contain_hint,
                           S32 number_of_items,
                           U16 *list_of_items,
                           U16 *list_of_icons,
                           U8 **list_of_descriptions,
                           S32 flags,
                           S32 highlighted_item,
                           U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }
    gdi_layer_lock_frame_buffer();
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY525_ID, history_buffer);
    
    if (n_tabs)
    {
        for (i = 0; i < n_tabs; i++)
        {
            MMI_tab_bar_items[i] = tab_items[i];
        }
        if (contain_hint)
        {
            wgui_create_horizontal_tab_bar(TRUE, (UI_string_type) GetString(title), n_tabs, highlighted_tab, MMI_FALSE);
            wgui_fixed_list_move_icontext_menu(
                MMI_CONTENT_X,
                MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_TITLE_HEIGHT);
            wgui_fixed_list_resize_icontext_menu(
                MMI_CONTENT_WIDTH,
                MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        }
        else
        {
            wgui_create_horizontal_tab_bar(
                FALSE,
                (UI_string_type) GetString(title),
                n_tabs,
                highlighted_tab,
                MMI_FALSE);
            wgui_fixed_list_move_icontext_menu(MMI_CONTENT_X, MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_TITLE_HEIGHT);		
            wgui_fixed_list_resize_icontext_menu(
                MMI_CONTENT_WIDTH,
                MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
        }
    }
    
    wgui_fixed_list_begin_add_icontext_one_item();
    if (list_of_descriptions == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, subMenuDataPtrs[i], wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
        }
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, subMenuDataPtrs[i], wgui_get_list_menu_icon(i, list_of_icons[i]), list_of_descriptions[i]);

        }
    }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    wgui_cat_set_hint_in_menuitem(list_of_descriptions, number_of_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */

    wgui_fixed_list_end_add_icontext_one_item();
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY525_ID, 0, ExitCategory525Screen);
    dm_redraw_category_screen();
    
}   


/*****************************************************************************
 * FUNCTION
 *  SetCategory525TabSelectCallback
 * DESCRIPTION
 *  set tabbar select callback
 * PARAMETERS
 *  select_callback     [IN]        function of callback
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory525TabSelectCallback(void (*select_callback) (int index))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_set_horizontal_tab_bar_select_callback(select_callback);
}


/*****************************************************************************
 * FUNCTION
 *  Category525BlinkTab
 * DESCRIPTION
 *  Category 525 blink tab
 * PARAMETERS
 *  tab     [IN]        index of tab
 * RETURNS
 *  void
 *****************************************************************************/
void Category525BlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_start_blinking(tab);
}


/*****************************************************************************
 * FUNCTION
 *  Category525UnBlinkTab
 * DESCRIPTION
 *  Category 525 unblink tab
 * PARAMETERS
 *  tab     [IN]        index of tab
 * RETURNS
 *  void
 *****************************************************************************/
void Category525UnBlinkTab(S8 tab)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_stop_blinking(tab);
}

/* cat410 */
static U8** g_cat410_list_items = NULL;
static U16* g_cat410_list_icons = NULL;
UI_filled_area g_410_focussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {255, 128, 0, 0},
    {0, 0, 0, 0},
    {255, 255, 255, 0},
    {0, 0, 0, 0},
    0
};

/*****************************************************************************
 * FUNCTION
 *  ShowCategory410Screen
 * DESCRIPTION
 *  Displays the category410 screen (adjust list order) for orange
 *  
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
 void ShowCategory410Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    g_cat410_list_items = list_of_items;
    g_cat410_list_icons = list_of_icons;
    dm_add_title(title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_icontext_menu(
            number_of_items, 
            highlighted_item, 
            WGUI_LIST_MENU_DISABLE_SHORTCUT,
            MMI_CATEGORY410_ID,
            history_buffer);
    MMI_fixed_icontext_menuitem.focussed_filler = &g_410_focussed_filler;
	MMI_fixed_icontext_menuitem.selected_filler = &g_410_focussed_filler;
    wgui_fixed_list_begin_add_icontext_one_item();

    for (i = 0; i < number_of_items; i++)
    {
        wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
    }
    wgui_fixed_list_end_add_icontext_one_item();

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY410_ID, 0, ExitListCategoryScreen);
    dm_redraw_category_screen();

} 


/*****************************************************************************
 * FUNCTION
 *  wgui_cat410_refresh_list
 * DESCRIPTION
 *  Refresh cat410 list when adjusting list order
 * 
 * PARAMETERS
 *  highlighted_item          [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat410_goto_list(S32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {
        change_fixed_icontext_item(i, (UI_string_type) g_cat410_list_items[i], wgui_get_list_menu_icon(i, g_cat410_list_icons[i]));
        wgui_pop_up_description_strings[i].text_strings[0] = NULL;
    }
    fixed_list_goto_item(highlighted_item);
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat410_touch_refresh_list
 * DESCRIPTION
 *  Refresh cat410 list when touch list item
 * 
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/

void wgui_cat410_touch_refresh_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {
        change_fixed_icontext_item(i, (UI_string_type) g_cat410_list_items[i], wgui_get_list_menu_icon(i, g_cat410_list_icons[i]));
        wgui_pop_up_description_strings[i].text_strings[0] = NULL;
    }
    show_fixed_list();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/************
 * category210
*************/
static S32 g_cat210_list_item_num = 0;
UI_filled_area *g_cat210_fixed_list_backup_filler;
#define MMI_CAT210_MAX_LIST_ITEMS_COUNT 4
#define MMI_CAT210_LIST_MARGIN_SPACE 4
extern UI_filled_area wgui_pop_up_dialog_background;
/*****************************************************************************
 * FUNCTION
 *  DrawCate210CategoryControlArea
 * DESCRIPTION
 *  Cateogry 210 control area redraw callback
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate210CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;
	S32 gap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    gui_greyscale_rectangle(0, 0, UI_device_width - 1, UI_device_height - 1, MMI_BG_GREYSCALE_VALUE, MMI_BG_GREYSCALE_BLACK_VALUE);
#ifdef __MMI_FTE_SUPPORT__
	gap = WGUI_POPUP_FTE_AREA_X;
#else
	gap = UI_POPUP_BORDER_SIZE;
#endif
    x1 = MMI_POP_UP_DIALOG_X;
    y1 = MMI_POP_UP_DIALOG_Y;
    x2 = MMI_POP_UP_DIALOG_X + MMI_POP_UP_DIALOG_WIDTH - 1;
	y2 = MMI_POP_UP_DIALOG_Y + MMI_CAT210_LIST_MARGIN_SPACE*2 + get_menu_item_height() * g_cat210_list_item_num +  gap*2 - 1;
    wgui_draw_pop_up_screen_background(x1, y1, x2, y2, &wgui_pop_up_dialog_background, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory210Screen
 * DESCRIPTION
 *  Exits the category210 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory210Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_small_screen();
    MMI_fixed_list_menu.normal_filler = g_cat210_fixed_list_backup_filler;
    title_bg_id = 0;
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);    /* 052906 early status icon */
    ExitListCategoryScreen();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory210Screen
 * DESCRIPTION
 *  show category 210 screen(Popup list)
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Item count
 *  list_of_items           [IN]        String list of items
 *  list_of_icons           [IN]        Icon list of items
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory210Screen(
    UI_string_type left_softkey,
	PU8 left_softkey_icon,
	UI_string_type right_softkey,
	PU8 right_softkey_icon,
	S32 number_of_items,
	U16 *list_of_items,
	U16 *list_of_icons,
	S32 highlighted_item,
	U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	S32 gap;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_lock_frame_buffer();
    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);
    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CATEGORY210_ID, history_buffer);
    wgui_set_disable_shortcut_display();
    g_cat210_fixed_list_backup_filler = MMI_fixed_list_menu.normal_filler;

    MMI_fixed_icontext_menuitem.selected_filler = &g_410_focussed_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = &g_410_focussed_filler;
    MMI_fixed_icontext_menuitem.focussed_without_sc_filler = &g_410_focussed_filler;
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->small_list_menu_normal_filler;
#endif
    wgui_fixed_list_begin_add_icontext_one_item();
	if(list_of_icons == NULL)
	{
		for(i = 0; i < number_of_items; i++)
		{
			wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(list_of_items[i]), NULL, NULL);
		}
	}
	else
	{
		for(i = 0; i < number_of_items; i++)
		{
			wgui_fixed_list_add_icontext_one_item(i, (U8*)get_string(list_of_items[i]), wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
		}
	}
    wgui_fixed_list_end_add_icontext_one_item();
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
    if(number_of_items <= MMI_CAT210_MAX_LIST_ITEMS_COUNT)
	{
		g_cat210_list_item_num = number_of_items;
	}
	else
	{
		g_cat210_list_item_num = MMI_CAT210_MAX_LIST_ITEMS_COUNT;
	}
#ifdef __MMI_FTE_SUPPORT__
	gap = WGUI_POPUP_FTE_AREA_X ;
#else
	gap = UI_POPUP_BORDER_SIZE;
#endif
    wgui_fixed_list_resize_icontext_menu(
		MMI_POP_UP_DIALOG_WIDTH - gap*2,
		get_menu_item_height() * g_cat210_list_item_num);
    resize_fixed_icontext_menuitems(MMI_POP_UP_DIALOG_WIDTH - gap*2 - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
    wgui_fixed_list_move_icontext_menu(
		MMI_POP_UP_DIALOG_X + gap,
		MMI_POP_UP_DIALOG_Y + gap + MMI_CAT210_LIST_MARGIN_SPACE);
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY210_ID, 0, ExitCategory210Screen);
    dm_register_category_controlled_callback(DrawCate210CategoryControlArea);
    dm_redraw_category_screen();
}

#if !defined(__WGUI_CATE_LIST_TWO_ICONS_MAP__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat73_DrawScreen
 * DESCRIPTION
 *  draw text and icon coordinates of category73
 * PARAMETERS
 *  width1	: [IN] width of icon1
 *  height1	: [IN] height of icon1
 *  width2	: [IN] width of icon2
 *  height2	: [IN] height of icon2
 * RETURNS
 *  void
 *****************************************************************************/
static U8 g_wgui_cat73_display_flag;

static void wgui_cat73_DrawScreen(S32 width1, S32 height1, S32 width2, S32 height2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 isicon1 = 0, isicon2 = 0;
    S32 w1 = 0, w2 = 0, h1 = 0, h2 = 0;
    S32 icon1_position = 0, icon2_position = 0, text_width = 0, text_position = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    isicon1 = (!width1 || !height1) ? (0) : (1);
    isicon2 = (!width2 || !height2) ? (0) : (1);  
    w1 = (isicon1) ? (width1) : (0);
    h1 = (isicon1) ? (height1) : (0);
    w2 = (isicon2) ? (width2) : (0);
    h2 = (isicon2) ? (height2) : (0);
    
    switch (g_wgui_cat73_display_flag)
    {
        case ICON_TEXT_ICON:
            icon1_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_ICON_X) : (0);
            text_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_TEXT_X) : (GUI_TEXT_MENUITEM_TEXT_X);
            text_width = (UI_device_width - MMI_fixed_list_menu.vbar.width - text_position - 1 - 2/* image highlight border*/);
            text_width -= (isicon2) ? (w2 + 3) : (0);
            icon2_position = (isicon2) ? (text_position + text_width + 3 - 1) : (0);
            break;
        
        case ICON_ICON_TEXT:
            icon1_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_ICON_X) : (0);
            icon2_position = (isicon1) ? (GUI_ICONTEXT_MENUITEM_TEXT_X) : (GUI_ICONTEXT_MENUITEM_ICON_X);
            icon2_position = (isicon2) ? icon2_position : (0);
            if (isicon1 && isicon2)
            {
                text_position = icon2_position + w2 + 3 - 1;
            }
            else if (isicon1 || isicon2)
            {
                text_position = GUI_ICONTEXT_MENUITEM_TEXT_X;
            }
            else
            {
                text_position = GUI_TEXT_MENUITEM_TEXT_X;
            }
            text_width = (UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - text_position);
            break;
        
        case TEXT_ICON_ICON:
            text_position = GUI_TEXT_MENUITEM_TEXT_X;
            text_width = (UI_device_width - MMI_fixed_list_menu.vbar.width - text_position - 1 - 2/* image highlight border*/);
            text_width -= (isicon1) ? (w1 + 3) : (0);
            text_width -= (isicon2) ? (w2 + 3) : (0);
            icon1_position = (isicon1) ? (text_position + text_width + 3 - 1) : (0);
            icon2_position = (isicon1) ? (icon1_position + w1 + 3 - 1) : (text_position + text_width + 3 - 1);
            icon2_position = (isicon2) ? (icon2_position) : (0);
            break;
        
        default:
        {
            MMI_ASSERT(0);
        }
    }
    
    /* Recalculate icon/text coordinates if icon is changed */
    set_fixed_icontext_list_text_coordinates(0, text_position, 0, text_width, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_list_icon_coordinates(0, icon1_position, 0, w1, h1);
    set_fixed_icontext_list_icon_coordinates(1, icon2_position, 0, w2, h2);
}
#endif /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ */


/*****************************************************************************
 * FUNCTION
 *  Category73RedrawScreen
 * DESCRIPTION
 *  Draw category 73 screen without invoking animation effect again
 *  It can be used to update the display content of category 73
 *
 *  Remark: this function only support ICON_ICON_TEXT style; other styles unsupported yet
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Category73RedrawScreen(void)
{
#if defined(__WGUI_CATE_LIST_TWO_ICONS_MAP__) || defined(__MMI_MAINLCD_128X64__)
    RedrawCategoryFunction();
#else /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, w1 = 0, w2 = 0, h1 = 0, h2 = 0, iw, ih;
    PU8 img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

    for (i = 0; i < MMI_fixed_list_menu.n_items; i++)
    {
        img = MMI_fixed_icontext_list_menuitems[i].item_icons[0];
        if (img)
        {
            gui_measure_image(img, &iw, &ih);
            w1 = (iw > w1) ? (iw) : (w1);
            h1 = (ih > h1) ? (ih) : (h1);
        }

        img = MMI_fixed_icontext_list_menuitems[i].item_icons[1];
        if (img)
        {
            gui_measure_image(img, &iw, &ih);
            w2 = (iw > w2) ? (iw) : (w2);
            h2 = (ih > h2) ? (ih) : (h2);
        }
    }
    wgui_cat73_DrawScreen(w1, h1, w2, h2);
    gui_fixed_icontext_list_menuitem_stop_scroll();
    gui_fixed_icontext_list_menuitem_start_scroll();
	
    RedrawCategoryFunction();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif
#endif /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__*/
}


/*****************************************************************************
 * FUNCTION
 *  Category73ChangeItemIcon
 * DESCRIPTION
 *  Change the icon of category 73
 *  Please use Category73RedrawScreen() to redraw after data changed
 * PARAMETERS
 *  item_index      [IN]        Menu item index
 *  icon_index      [IN]        Icon index (0 or 1)
 *  icon            [IN]        Icon image
 * RETURNS
 *  void
 *****************************************************************************/
void Category73ChangeItemIcon(S32 item_index, S32 icon_index, PU8 icon)
{
#if defined(__WGUI_CATE_LIST_TWO_ICONS_MAP__) || defined(__MMI_MAINLCD_128X64__)
    MMI_fixed_icontext_menuitems[item_index].item_icon = icon;
#else /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (icon_index < 2)
    {
        MMI_fixed_icontext_list_menuitems[item_index].item_icons[icon_index] = icon;
    }
#endif /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__*/
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory73ScreenExt_int
 * DESCRIPTION
 *  Displays the category73 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_icons1          [IN]        List for first column of icons
 *  list_of_icons2          [IN]        List for second column of icons
 *  list_of_descriptions    [IN]        List of text hints
 *  highlighted_item        [IN]        Default item to be highlighted(if there is no history)
 *  history_buffer          [IN]        History buffer
 *  u8display_flag          [IN]        ICON_TEXT_ICON, ICON_ICON_TEXT, TEXT_ICON_ICON
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory73ScreenExt_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons1,
        U16 *list_of_icons2,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer,
        U8 u8display_flag)
{
#if defined(__WGUI_CATE_LIST_TWO_ICONS_MAP__) || defined(__MMI_MAINLCD_128X64__)
    U16 *icon = NULL;
    
    if (u8display_flag == ICON_ICON_TEXT)
    {
        icon = list_of_icons1;
    }
    else
    {
        icon = list_of_icons2;
    }
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    ShowCategory353Screen_ext_int(
		(U8*) title,
		title_icon,
		(U8*) left_softkey,
		(U8*) right_softkey,
		number_of_items,
		list_of_items,
		icon,
		list_of_descriptions,
		0,
		highlighted_item,
		history_buffer);
	wgui_restore_list_menu_slim_style();
#else /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__ */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, w1 = 0, w2 = 0, h1 = 0, h2 = 0, iw = 0, ih = 0;
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat73_display_flag = u8display_flag;

    gdi_layer_lock_frame_buffer();
    dm_add_title(title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    wgui_fixed_list_create_multi_icontext_menu(
        2,
        1,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        0,
        MMI_CATEGORY73_ID,
        history_buffer);

    for (i = 0; i < number_of_items; i++)
    {
        img = (U8*) GetImage(list_of_icons1[i]);
        if (img)
        {
            gui_measure_image(img, &iw, &ih);
            w1 = (iw > w1) ? (iw) : (w1);
            h1 = (ih > h1) ? (ih) : (h1);
        }

        img = (U8*) GetImage(list_of_icons2[i]);
        if (img)
        {
            gui_measure_image(img, &iw, &ih);
            w2 = (iw > w2) ? (iw) : (w2);
            h2 = (ih > h2) ? (ih) : (h2);
        }
    }
    wgui_cat73_DrawScreen(w1, h1, w2, h2);

    MMI_fixed_icontext_list_menuitem.selected_fonts[0] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[1] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);
    MMI_fixed_icontext_list_menuitem.selected_fonts[2] = gui_font_get_type(GUI_FONT_SIZE_LIST_HIGHLIGHT);

    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[1];
        U8 *icons[2];
        items[0] = list_of_items[i];
        icons[0] = get_image(list_of_icons1[i]);
        icons[1] = get_image(list_of_icons2[i]);
        if(list_of_descriptions == NULL)
        {
            wgui_fixed_list_add_multi_icontext_one_item(i, items, icons, NULL);
        }
        else
        {
            wgui_fixed_list_add_multi_icontext_one_item(i, items, icons, list_of_descriptions[i]);
        }
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY;

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY73_ID, 0, ExitListCategoryScreen);
    dm_redraw_category_screen();
#endif /* __WGUI_CATE_LIST_TWO_ICONS_MAP__ || __MMI_MAINLCD_128X64__*/
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory73Screen_int
 * DESCRIPTION
 *  Displays the category73 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_icons1          [IN]        List for first column of icons
 *  list_of_icons2          [IN]        List for second column of icons
 *  highlighted_item        [IN]        Default item to be highlighted(if there is no history)
 *  history_buffer          [IN]        History buffer
 *  u8display_flag          [IN]        ICON_TEXT_ICON, ICON_ICON_TEXT, TEXT_ICON_ICON
 
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory73Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons1,
        U16 *list_of_icons2,
        S32 highlighted_item,
        U8 *history_buffer,
        U8 u8display_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory73Screen_ext_int(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons1,
        list_of_icons2,
        highlighted_item,
        history_buffer,
        u8display_flag);	

}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory73Screen_ext_int
 * DESCRIPTION
 *  Displays the category73 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  list_of_icons1          [IN]        List for first column of icons
 *  list_of_icons2          [IN]        List for second column of icons
 *  highlighted_item        [IN]        Default item to be highlighted(if there is no history)
 *  history_buffer          [IN]        History buffer
 *  u8display_flag          [IN]        ICON_TEXT_ICON, ICON_ICON_TEXT, TEXT_ICON_ICON
 
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory73Screen_ext_int(
        U8* title,
        U8* title_icon,
        U8* left_softkey,
        U8* right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons1,
        U16 *list_of_icons2,
        S32 highlighted_item,
        U8 *history_buffer,
        U8 u8display_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory73ScreenExt_int(
        (UI_string_type)title,
        (PU8)title_icon,
        (UI_string_type)left_softkey,
        (UI_string_type)right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons1,
        list_of_icons2,
        NULL,
        highlighted_item,
        history_buffer,
        u8display_flag);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory354Screen_int
 * DESCRIPTION
 *  Displays the category354 screen ( List menu with two text rows )
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items1          [IN]        String array1 of items
 *  list_of_items2          [IN]        String array2 of items
 *  list_of_icons           [IN]        Array of icons
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory354Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        U16 *list_of_icons,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory354Screen_ext_int(
        title,
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items1,
	 list_of_items2,
	 list_of_icons,
	 highlighted_item,
	 history_buffer);
	
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory354Screen_ext_int
 * DESCRIPTION
 *  Displays the category354 screen ( List menu with two text rows )
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items1          [IN]        String array1 of items
 *  list_of_items2          [IN]        String array2 of items
 *  list_of_icons           [IN]        Array of icons
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory354Screen_ext_int(
        U8 *title,
        U8 *title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        U16 *list_of_icons,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 img_width, text_width, item_height;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY52_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

	wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    item_height = get_menu_item_height();

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    wgui_fixed_list_create_multi_icontext_menu(
        1,
        2,
        number_of_items,
        highlighted_item,
        item_height << 1,/* we need two lines */
        0,
        (U16)CatId,
        history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_list_create_multi_icontext_menu(
        1,
        2,
        number_of_items,
        highlighted_item,
        item_height << 1,/* we need two lines */
        0,
        MMI_CATEGORY52_ID,
        history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */

    gdi_image_get_dimension_id(list_of_icons[0], &img_width, &text_width);
    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - 2;
    set_fixed_icontext_list_icon_coordinates(0, 1, 0, img_width, item_height << 1);
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_TEXT_X, 0, text_width, item_height);
    set_fixed_icontext_list_text_coordinates(1, GUI_ICONTEXT_MENUITEM_TEXT_X, item_height, text_width, item_height);
        
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_MARQUEE_SCROLL;
    
    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[2];
        U8 *icon[1];
        items[0] = list_of_items1[i];
        items[1] = list_of_items2[i];
        icon[0] = get_image(list_of_icons[i]);
        wgui_fixed_list_add_multi_icontext_one_item(i, items, icon, NULL);
    }

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */
	
    wgui_fixed_list_end_add_multi_icontext_one_item();

    gdi_layer_unlock_frame_buffer();

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, s32flags, ExitCategoryCommonScreen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY52_ID, 0, ExitCategoryCommonScreen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory354Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory354Screen
 * DESCRIPTION
 *  Exits the category354 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory354Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_ICON_Y;
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_MARQUEE_SCROLL;
    MMI_fixed_icontext_list_menuitem.flags &= ~UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat354_refresh
 * DESCRIPTION
 *  refresh the category354 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat354_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif

	gdi_layer_lock_frame_buffer();
    show_fixed_list();
	if ((MMI_fixed_list_menu.highlighted_item == GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
		|| (MMI_fixed_list_menu.n_items == 0))
	{
	    wgui_text_menuitem_reset_scrolling();
	}
	gdi_layer_unlock_frame_buffer();
	
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


#if defined(__MMI_TOUCH_SCREEN__)
static FuncPtr pen_up_call_back = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */

void wgui_cat1003_goback_callback(FuncPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    pen_up_call_back = func;
#else /* __MMI_TOUCH_SCREEN__ */
    return ;
#endif /* __MMI_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  draw_cat1003_background
 * DESCRIPTION
 *  Cateogry 1003 control area redraw background
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void draw_cat1003_background()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = MMI_fixed_list_menu.x - MMI_FTE_TOOLBAR_START_X;
    y1 = MMI_fixed_list_menu.y - MMI_FTE_TOOLBAR_START_X - MMI_TITLE_HEIGHT;
    w = MMI_fixed_list_menu.width + (MMI_FTE_TOOLBAR_START_X<<1);
    h = MMI_fixed_list_menu.height + MMI_TITLE_HEIGHT + MMI_FTE_SMALLLIST_GAP;

    gui_draw_filled_area(x1, y1, x1 + w, y1 + h, current_MMI_theme->small_list_menu_normal_filler);
}


static void wgui_cat1003_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    
    draw_cat1003_background();   
#ifdef __MMI_FTE_SUPPORT__
    if(!g_cache_small_list_bg.buf_ptr)
    {
        g_cache_small_list_bg.buf_ptr = (U8 *)mmi_frm_scrmem_alloc(MMI_CASCADING_ASM_BUFFER_SIZE);
        MMI_DBG_ASSERT(g_cache_small_list_bg.buf_ptr);
        gdi_image_cache_bmp_get(
            MMI_fixed_list_menu.x,
            MMI_fixed_list_menu.y,
            MMI_fixed_list_menu.x + MMI_fixed_list_menu.width - 1,
            MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1,
            &g_cache_small_list_bg);
    }
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1003_menu_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1003_menu_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
#ifdef __MMI_FTE_SUPPORT__
    if (g_cache_small_list_bg.buf_ptr)
    {
        gdi_image_cache_bmp_draw(
            MMI_fixed_list_menu.x, 
            MMI_fixed_list_menu.y,
            &g_cache_small_list_bg);
    }
    else
    {
        draw_cat1003_background();
    }
#else /* __MMI_FTE_SUPPORT__ */
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_fill_transparent_color(x1, y1, x2, y2, gui_color32(255,255,255,0));
#else
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
#endif /*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/
#endif /* __MMI_FTE_SUPPORT__ */
    gdi_layer_pop_clip();
}


static void wgui_cat1003_vertical_scrollbar_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    color white_color = {255, 255, 255, 0};
#endif /* __MMI_UI_TRANSPARENT_EFFECT__ || __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
      
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
    gui_fill_transparent_color(x1, y1, x2, y2, white_color);
#else
    gui_fill_rectangle(x1, y1, x2, y2, gui_color(255, 255, 255));
#endif /*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/
    
    gdi_layer_pop_clip();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  PtInControlArea
 * DESCRIPTION
 *  judge point in the control area
 * PARAMETERS
 *  point      [IN]     pen down/up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL PtInControlArea(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    x1 = MMI_fixed_list_menu.x;
    y1 = MMI_fixed_list_menu.y - MMI_TITLE_HEIGHT;
    x2 = x1 + MMI_fixed_list_menu.width;
    y2 = y1 + MMI_fixed_list_menu.height + MMI_TITLE_HEIGHT;

    if(point.x > x1 && point.x < x2 && point.y > y1 && point.y < y2)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_pen_up_hdlr
 * DESCRIPTION
 *  Cateogry 1001 pen up handler
 * PARAMETERS
 *  point      [IN]     pen up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1003_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!PtInControlArea(point))
    {
        if(pen_up_call_back)
        {
            pen_up_call_back();
        }
        else
        {
            GoBackHistory();
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1001_pen_down_hdlr
 * DESCRIPTION
 *  Cateogry 1001 pen down handler
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1003_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(point);
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*  wgui_cat1003_exit
* DESCRIPTION
*  Exits the category1003 screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1003_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1001_exit();
    if(g_cache_small_list_bg.buf_ptr)
    {
        mmi_frm_scrmem_free(g_cache_small_list_bg.buf_ptr);
        g_cache_small_list_bg.buf_ptr = NULL;
    }
#if defined(__MMI_TOUCH_SCREEN__)
    pen_up_call_back = NULL;
#endif /* __MMI_TOUCH_SCREEN__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1003_show
 * DESCRIPTION
 *  show category 1003 screen(Small-list for FTE tool bar)
 * PARAMETERS
 *  title                                [IN] (TITLE)    Title of the small list
 *  title_icon                           [IN] (N/A)      icon displayed with the title
 *  left_softkey                         [IN] (LSK)      Left softkey label
 *  left_softkey_icon                    [IN] (N/A)      Left softkey icon
 *  right_softkey                        [IN] (RSK)      Right softkey label
 *  right_softkey_icon                   [IN] (N/A)      Right softkey icon
 *  number_of_items                      [IN] (N/A)      Item count
 *  list_of_items                        [IN] (ICONTEXT) Array of items
 *  list_of_icons                        [IN] (N/A)      Array of items
 *  flags                                [IN] (N/A)      flags(always set to 0, reserved for future use.)
 *  highlighted_item                     [IN] (N/A)      Index of highlighted item
 *  history_buffer                       [IN] (N/A)      History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1003_show(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, max_item_count = 0;
    S32 list_width, list_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif

    gdi_layer_lock_frame_buffer();

    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);

    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, MMI_CAT1003_ID, history_buffer);
    wgui_fixed_list_register_hide_function(wgui_cat1003_menu_hide_function);
    gui_vertical_scrollbar_register_hide_callback(&MMI_fixed_list_menu.vbar, wgui_cat1003_vertical_scrollbar_hide_function);

    wgui_set_disable_shortcut_display();

    wgui_fixed_list_begin_add_icontext_one_item();
    if(list_of_icons == NULL)
    {
        for(i = 0; i < number_of_items; ++i)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], NULL, NULL);
        }
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);
    }
    else
    {
        for(i = 0; i < number_of_items; ++i)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], list_of_icons[i], NULL);
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();

    max_item_count = (MMI_CONTENT_HEIGHT - MMI_TITLE_HEIGHT - MMI_FTE_TOOLBAR_HEIGHT - MMI_FTE_SMALLLIST_GAP)/get_menu_item_height();

    if(number_of_items < max_item_count)
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
        list_height = number_of_items*get_menu_item_height();
        list_width = MMI_CONTENT_WIDTH - MMI_FTE_TOOLBAR_START_X*2;
    }
    else
    {
        list_height = max_item_count*get_menu_item_height();
        list_width = MMI_CONTENT_WIDTH - MMI_FTE_TOOLBAR_START_X*2 - UI_SCROLLBAR_WIDTH;
    }

    wgui_fixed_list_resize_icontext_menu(MMI_CONTENT_WIDTH - MMI_FTE_TOOLBAR_START_X*2, list_height);
    resize_fixed_icontext_list_menuitems(list_width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
    wgui_fixed_list_move_icontext_menu(
        MMI_FTE_TOOLBAR_START_X,
        MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_FTE_TOOLBAR_HEIGHT - (MMI_FTE_SMALLLIST_GAP>>1) - list_height);

    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->small_list_menu_highlight_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->small_list_menu_highlight_filler;   
    /* show title of small list in single line editor */
    create_singleline_inputbox_set_buffer(
        (UI_string_type)title,
        gui_strlen((UI_string_type)title) + 1,
        gui_strlen((UI_string_type)title),
        gui_strlen((UI_string_type)title));
    set_singleline_inputbox_mask(0);
    MMI_singleline_inputbox.flags |= 
        (UI_SINGLE_LINE_INPUT_BOX_DISABLE_BACKGROUND | UI_SINGLE_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
        UI_SINGLE_LINE_INPUT_BOX_CENTER_JUSTIFY);
    wgui_inputs_sl_resize(MMI_CONTENT_WIDTH - MMI_FTE_TOOLBAR_START_X*2, MMI_TITLE_HEIGHT);
    wgui_inputs_sl_move(MMI_FTE_TOOLBAR_START_X, MMI_fixed_list_menu.y - MMI_TITLE_HEIGHT);
    MMI_singleline_inputbox.normal_text_color = *(current_MMI_theme->list_normal_text_color);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat1003_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat1003_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
#endif /* __MMI_TOUCH_SCREEN__ */
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CAT1003_ID, 0, wgui_cat1003_exit);
    dm_add_rectangle(UI_COLOR_BLACK, DM_RECTANGLE_FILL_GRAYSCALE);
    dm_register_category_controlled_callback(wgui_cat1003_draw_ctrl_area);
    dm_redraw_category_screen();
    show_singleline_inputbox();
}

/*****************************************************************************
 * FUNCTION
 *  draw_cat1004_background
 * DESCRIPTION
 *  Cateogry 1004 control area redraw background
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void draw_cat1004_background()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, w, h;
    S32 popup_title_h;
    S32 popup_button_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {
        popup_title_h =  MMI_ROTATED_TITLE_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        popup_title_h = MMI_TITLE_HEIGHT;
    }
    if(MMI_softkeys[MMI_LEFT_SOFTKEY].text != NULL || 
        MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon != NULL ||
        MMI_softkeys[MMI_RIGHT_SOFTKEY].text != NULL || 
        MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon != NULL)
    {
        popup_button_h = popup_title_h;
    }
    else
    {
        popup_button_h = 0;
    }

    x1 = MMI_fixed_list_menu.x - CASCADING_MENU_BORDER_SIZE;
    y1 = MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - popup_title_h - CASCADING_MENU_BORDER_SIZE;
    w = MMI_fixed_list_menu.width + CASCADING_MENU_BORDER_SIZE * 2;
    h = MMI_fixed_list_menu.height + popup_title_h + popup_button_h + CASCADING_MENU_BORDER_SIZE * 2 + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP;
#ifdef __MMI_FTE_SUPPORT__
    if (g_cache_small_list_bg.buf_ptr)
    {
        gdi_image_cache_bmp_draw(
            x1, 
            y1,
            &g_cache_small_list_bg);
        return;
    }
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_FTE_SUPPORT__
    gui_draw_filled_area(x1, y1, x1 + w - 1, y1 + h - 1, current_MMI_theme->cascade_menu_background_filler);
#else
    gui_draw_filled_area(
        x1, 
        y1, 
        x1 + w - 1,
        y1 + h - 1,
        current_MMI_theme->cascade_menu_background_filler);
#endif /* __MMI_FTE_SUPPORT__ */
}

#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    WGUI_CAT1004_PEN_DOWN_INSIDE_NONE,
    WGUI_CAT1004_PEN_DOWN_INSIDE_CLOSE_ICON,
    WGUI_CAT1004_PEN_DOWN_INSIDE_LSK,
    WGUI_CAT1004_PEN_DOWN_INSIDE_RSK,
    WGUI_CAT1004_PEN_DOWN_INSIDE_TOTAL
}wgui_cat1004_pen_down_inside_enum;
static wgui_cat1004_pen_down_inside_enum g_wgui_cat1004_pen_down_inside;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_draw_close_icon
 * DESCRIPTION
 *  draw the close icon
 * PARAMETERS
 *  normal_state      [IN]     TRUE: normal state, FALSE: press down state
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1004_draw_close_icon(MMI_BOOL normal_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 close_icon_x, close_icon_y;
    S32 close_icon_w, close_icon_h;
    gdi_handle alpha_layer;
    s32 popup_width, popup_title_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {
        popup_width = (MMI_ROTATED_LCD_WIDTH*2)/3;
        popup_title_h =  MMI_ROTATED_TITLE_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        popup_width = (MAIN_LCD_DEVICE_WIDTH*4)/5;
        popup_title_h =  MMI_TITLE_HEIGHT;
    }
    gui_measure_image(get_image(IMG_CAT1004_CLOSE_ICON_UP), &close_icon_w, &close_icon_h);
    close_icon_x = MMI_fixed_list_menu.x + popup_width - CASCADING_MENU_BORDER_SIZE*2 - ((popup_title_h + close_icon_w)>>1);
    close_icon_y = MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - ((popup_title_h + close_icon_h)>>1);
    gdi_layer_get_base_handle(&alpha_layer);
    if(alpha_layer != GDI_NULL_HANDLE)
    {
        gdi_push_and_set_alpha_blending_source_layer(alpha_layer);
    }
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_fixed_list_menu.x + popup_width - CASCADING_MENU_BORDER_SIZE*2 - popup_title_h, 
        MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - popup_title_h, 
        MMI_fixed_list_menu.x + popup_width - CASCADING_MENU_BORDER_SIZE*2 - 1, 
        MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - 1);
    draw_cat1004_background();
    if(normal_state){
        gdi_image_draw_id(close_icon_x, close_icon_y, IMG_CAT1004_CLOSE_ICON_UP);
    }
    else
    {
        gdi_image_draw_id(close_icon_x, close_icon_y, IMG_CAT1004_CLOSE_ICON_DOWN);
    }
    gdi_layer_pop_clip();
    if(alpha_layer != GDI_NULL_HANDLE)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_touch_close_icon
 * DESCRIPTION
 *  judge whether touch the close icon
 * PARAMETERS
 *  point      [IN]     pen down/up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1004_touch_close_icon(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 close_icon_w, close_icon_h, close_icon_x, close_icon_y;
    S32 popup_width, popup_title_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {
        popup_width = (MMI_ROTATED_LCD_WIDTH*2)/3;
        popup_title_h =  MMI_ROTATED_TITLE_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        popup_width = (MAIN_LCD_DEVICE_WIDTH*4)/5;
        popup_title_h =  MMI_TITLE_HEIGHT;
    }
    gui_measure_image(get_image(IMG_CAT1004_CLOSE_ICON_UP), &close_icon_w, &close_icon_h);
    close_icon_x = MMI_fixed_list_menu.x + popup_width - CASCADING_MENU_BORDER_SIZE*2 - ((popup_title_h + close_icon_w)>>1);
    close_icon_y = MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - ((popup_title_h + close_icon_h)>>1);
    if(PEN_CHECK_BOUND(point.x, point.y, close_icon_x, close_icon_y, close_icon_w, close_icon_h))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_pen_up_hdlr
 * DESCRIPTION
 *  Cateogry 1004 pen up handler
 * PARAMETERS
 *  point      [IN]     pen up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1004_pen_up_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    gui_button_pen_enum button_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_CLOSE_ICON)
    {
        gdi_layer_lock_frame_buffer();
        wgui_cat1004_draw_close_icon(MMI_TRUE);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_width - 1);
        if(wgui_cat1004_touch_close_icon(point))
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    else if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_LSK)
    {
        ret = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &button_event);
        if (ret)
        {
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
               execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
            }
            else
            {
                SetkeyInfo(KEY_LSK, KEY_EVENT_UP);
            }
        }
    }
    else if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_RSK)
    {
        ret = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_RIGHT_SOFTKEY],
            MMI_PEN_EVENT_UP,
            point.x,
            point.y,
            &button_event);
        if (ret)
        {
            if (button_event == GUI_BUTTON_PEN_UP_INSIDE)
            {
                execute_softkey_function(KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
            }
            else
            {
                SetkeyInfo(KEY_RSK, KEY_EVENT_UP);
            }
        }
    }
    g_wgui_cat1004_pen_down_inside = WGUI_CAT1004_PEN_DOWN_INSIDE_NONE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_pen_down_hdlr
 * DESCRIPTION
 *  Cateogry 1004 pen down handler
 * PARAMETERS
 *  point      [IN]     pen up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1004_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    gui_button_pen_enum button_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat1004_pen_down_inside = WGUI_CAT1004_PEN_DOWN_INSIDE_NONE;
    if(wgui_cat1004_touch_close_icon(point))
    {
        g_wgui_cat1004_pen_down_inside = WGUI_CAT1004_PEN_DOWN_INSIDE_CLOSE_ICON;
        gdi_layer_lock_frame_buffer();
        wgui_cat1004_draw_close_icon(MMI_FALSE);
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_width - 1);
        return MMI_TRUE;
    }

    ret = gui_icontext_button_translate_pen_event(
            &MMI_softkeys[MMI_LEFT_SOFTKEY],
            MMI_PEN_EVENT_DOWN,
            point.x,
            point.y,
            &button_event);

    if (ret)
    {
        g_wgui_cat1004_pen_down_inside = WGUI_CAT1004_PEN_DOWN_INSIDE_LSK;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        }
        return MMI_TRUE;
    }

    /* RSK */
    ret = gui_icontext_button_translate_pen_event(
        &MMI_softkeys[MMI_RIGHT_SOFTKEY],
        MMI_PEN_EVENT_DOWN,
        point.x,
        point.y,
        &button_event);

    if (ret)
    {
        g_wgui_cat1004_pen_down_inside = WGUI_CAT1004_PEN_DOWN_INSIDE_RSK;
        if (button_event == GUI_BUTTON_PEN_DOWN)
        {
            execute_softkey_function(KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        }
        return MMI_TRUE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_pen_move_hdlr
 * DESCRIPTION
 *  Cateogry 1004 pen move handler
 * PARAMETERS
 *  point      [IN]     pen up point
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL wgui_cat1004_pen_move_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_button_pen_enum button_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_CLOSE_ICON)
    {
        gdi_layer_lock_frame_buffer();
        if(wgui_cat1004_touch_close_icon(point))
        {
            wgui_cat1004_draw_close_icon(MMI_FALSE);
        }
        else
        {
            wgui_cat1004_draw_close_icon(MMI_TRUE);
        }
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_width - 1);
    }
    else if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_LSK)
    {
        gui_icontext_button_translate_pen_event(
              &MMI_softkeys[MMI_LEFT_SOFTKEY],
              MMI_PEN_EVENT_MOVE,
              point.x,
              point.y,
              &button_event);
    }
    else if(g_wgui_cat1004_pen_down_inside == WGUI_CAT1004_PEN_DOWN_INSIDE_RSK)
    {
        gui_icontext_button_translate_pen_event(
              &MMI_softkeys[MMI_RIGHT_SOFTKEY],
              MMI_PEN_EVENT_MOVE,
              point.x,
              point.y,
              &button_event);
    }
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_hide_lsk
 * DESCRIPTION
 *  Draw lsk background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1004_hide_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_LEFT_SOFTKEY].x, 
        MMI_softkeys[MMI_LEFT_SOFTKEY].y,
        MMI_softkeys[MMI_LEFT_SOFTKEY].x + MMI_softkeys[MMI_LEFT_SOFTKEY].width - 1,
        MMI_softkeys[MMI_LEFT_SOFTKEY].y + MMI_softkeys[MMI_LEFT_SOFTKEY].height - 1);
    draw_cat1004_background();
    gdi_layer_pop_clip();  
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_hide_rsk
 * DESCRIPTION
 *  Draw rsk background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1004_hide_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x, 
        MMI_softkeys[MMI_RIGHT_SOFTKEY].y,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].x + MMI_softkeys[MMI_RIGHT_SOFTKEY].width - 1,
        MMI_softkeys[MMI_RIGHT_SOFTKEY].y + MMI_softkeys[MMI_RIGHT_SOFTKEY].height - 1);
    draw_cat1004_background();
    gdi_layer_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_add_softkey
 * DESCRIPTION
 *  add softkey
 * PARAMETERS
 *  lsk_text    [IN]        label of left softkey
 *  lsk_icon    [IN]        icon of left softkey
 *  rsk_text    [IN]        label of right softkey
 *  rsk_icon    [IN]        icon of right softkey
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_add_softkey(U8* lsk_text, U8* lsk_icon, U8* rsk_text, U8* rsk_icon, MMI_BOOL hide_text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset softkey handle / show (hide) function */
    SetupCategoryKeyHandlers();
    
    /* set softkey content */
    if(hide_text || (lsk_text == NULL && rsk_text == NULL))
    {
        set_left_softkey_label(NULL);
        set_right_softkey_label(NULL);
        set_left_softkey_icon(lsk_icon);
        set_right_softkey_icon(rsk_icon);
    }
    else
    {
        set_left_softkey_label((UI_string_type)lsk_text);
        set_right_softkey_label((UI_string_type)rsk_text);
        set_left_softkey_icon(NULL);
        set_right_softkey_icon(NULL);
    }

    /* register default softkey handler */
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();
}

static void wgui_cat1004_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FTE_SUPPORT__
    S32 popup_title_h;
    S32 popup_button_h;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
    draw_cat1004_background();
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {
        popup_title_h =  MMI_ROTATED_TITLE_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__*/
    {
        popup_title_h = MMI_TITLE_HEIGHT;  
    }
    if(MMI_softkeys[MMI_LEFT_SOFTKEY].text != NULL || 
        MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon != NULL ||
        MMI_softkeys[MMI_RIGHT_SOFTKEY].text != NULL || 
        MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon != NULL)
    {
        popup_button_h = popup_title_h;
    }
    else
    {
        popup_button_h = 0;
    }
    if(!g_cache_small_list_bg.buf_ptr)
    {
        g_cache_small_list_bg.buf_ptr = (U8 *)mmi_frm_scrmem_alloc(MMI_CASCADING_ASM_BUFFER_SIZE);
        if(g_cache_small_list_bg.buf_ptr){
            gdi_image_cache_bmp_get(
                MMI_fixed_list_menu.x - CASCADING_MENU_BORDER_SIZE,
                MMI_fixed_list_menu.y - CASCADING_MENU_TOP_GAP - popup_title_h - CASCADING_MENU_BORDER_SIZE,
                MMI_fixed_list_menu.x + MMI_fixed_list_menu.width + CASCADING_MENU_BORDER_SIZE - 1,
                MMI_fixed_list_menu.y + MMI_fixed_list_menu.height + CASCADING_MENU_BOTTOM_GAP + CASCADING_MENU_BORDER_SIZE + popup_button_h - 1,
                &g_cache_small_list_bg);
        }
    }
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat1004_draw_close_icon(MMI_TRUE);
#endif /* __MMI_TOUCH_SCREEN__ */
    if(MMI_softkeys[MMI_LEFT_SOFTKEY].text != NULL || MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon != NULL)
    {
        wgui_softkey_oem_show(MMI_LEFT_SOFTKEY);
    }
    if(MMI_softkeys[MMI_RIGHT_SOFTKEY].text != NULL || MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon != NULL)
    {
        wgui_softkey_oem_show(MMI_RIGHT_SOFTKEY);
    }
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1004_menu_hide_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat1004_menu_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(x1, y1, x2, y2);
    draw_cat1004_background();
    gdi_layer_pop_clip();
}
#endif /* __MMI_FTE_SUPPORT__ */
/*****************************************************************************
* FUNCTION
*  wgui_cat1004_exit
* DESCRIPTION
*  Exits the category1004 screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1004_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1001_exit();
    /* reset softkey theme */
    wgui_softkey_reset_theme(MMI_LEFT_SOFTKEY);
    wgui_softkey_reset_theme(MMI_RIGHT_SOFTKEY);
    /* reset softkey flags */
	set_softkey_flags_off(UI_BUTTON_CENTER_TEXT_X, MMI_LEFT_SOFTKEY);
	set_softkey_flags_off(UI_BUTTON_CENTER_TEXT_X, MMI_RIGHT_SOFTKEY);
	set_softkey_flags_on(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_LEFT_SOFTKEY);
	set_softkey_flags_on(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_RIGHT_SOFTKEY);
        set_softkey_flags_on(UI_BUTTON_RIGHT_ALIGN, MMI_RIGHT_SOFTKEY);

    if(g_cache_small_list_bg.buf_ptr)
    {
        mmi_frm_scrmem_free(g_cache_small_list_bg.buf_ptr);
        g_cache_small_list_bg.buf_ptr = NULL;
    }
}
void wgui_cat1004_show(
        WCHAR *title,
        PU8 title_icon,
        WCHAR *left_softkey,
        PU8 left_softkey_icon,
        WCHAR *right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 popup_width, popup_title_h;
    S32 small_screen_x, small_screen_y;
    MMI_BOOL icon_exist = MMI_FALSE;
    PU8 icon;
    S32 max_item_count;
    S32 list_height, list_width, softkey_width;
    S32 title_w = 0, title_h = 0, title_area_w;
    S32 lsk_text_w = 0, rsk_text_w = 0, softkey_text_h;
    MMI_BOOL softkey_hide_text = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {
        popup_width = (MMI_ROTATED_LCD_WIDTH*2)/3;
        popup_title_h =  MMI_ROTATED_TITLE_HEIGHT;
        max_item_count = (MMI_ROTATED_LCD_HEIGHT - popup_title_h*2 - CASCADING_MENU_BORDER_SIZE*2 - CASCADING_MENU_TOP_GAP - CASCADING_MENU_BOTTOM_GAP)/MMI_MENUITEM_HEIGHT;
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        popup_width = (MAIN_LCD_DEVICE_WIDTH*4)/5;
        popup_title_h = MMI_TITLE_HEIGHT;
        max_item_count = (MAIN_LCD_DEVICE_HEIGHT - popup_title_h*4 - CASCADING_MENU_BORDER_SIZE*2 - CASCADING_MENU_TOP_GAP - CASCADING_MENU_BOTTOM_GAP)/MMI_MENUITEM_HEIGHT;
    }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    gdi_layer_lock_frame_buffer();
    set_small_screen();
    gui_add_cleanup_hook(disable_resized_small_screen);
    wgui_fixed_list_create_icontext_menu(
        number_of_items,
        highlighted_item,
        0,
        MMI_CAT1004_ID,
        history_buffer);
#ifndef __MMI_FTE_SUPPORT__
    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR;
    MMI_fixed_list_menu.normal_filler = current_MMI_theme->cascade_menu_background_filler;
#else /* __MMI_FTE_SUPPORT__ */
    wgui_fixed_list_register_hide_function(wgui_cat1004_menu_hide_function);
#endif /* __MMI_FTE_SUPPORT__ */
    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_menuitem.focussed_without_sc_filler = current_MMI_theme->cascade_menu_highlight_filler;
    MMI_fixed_icontext_menuitem.normal_text_color = *current_MMI_theme->cascade_menu_normal_text_color;
    MMI_fixed_icontext_menuitem.disabled_text_color = *current_MMI_theme->cascade_menu_disabled_text_color;
    MMI_fixed_icontext_menuitem.selected_text_color = *current_MMI_theme->cascade_menu_selected_text_color;
    MMI_fixed_icontext_menuitem.focussed_text_color = *current_MMI_theme->cascade_menu_selected_text_color;

    wgui_set_disable_shortcut_display();
    wgui_fixed_list_begin_add_icontext_one_item();

    for(i = 0; i < number_of_items; i++)
    {
        icon = NULL;
        if (list_of_icons != NULL)
        {
            icon = wgui_get_list_menu_icon((int)i, (MMI_ID_TYPE)list_of_icons[i]);
        }
		if (icon != NULL)
		{
		    icon_exist = MMI_TRUE;
		}
        wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], icon, NULL);
    }
	if (!icon_exist)
	{
	    set_fixed_text_positions(CASCADING_MENU_TEXT_LEFT_GAP, 0);
	}
    wgui_fixed_list_end_add_icontext_one_item();
    if(number_of_items > max_item_count)
    {
        list_height = max_item_count*MMI_MENUITEM_HEIGHT;
    }
    else
    {
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
        list_height = number_of_items*MMI_MENUITEM_HEIGHT;
    }
    list_width = popup_width - CASCADING_MENU_BORDER_SIZE*2;
#ifdef __MMI_SCREEN_ROTATE__
    if(mmi_frm_is_screen_width_height_swapped())
    {    
        small_screen_x = (MMI_ROTATED_LCD_WIDTH - popup_width)/2;
        small_screen_y = (MMI_ROTATED_LCD_HEIGHT - list_height - MMI_ROTATED_TITLE_HEIGHT*2 - CASCADING_MENU_BORDER_SIZE*2 - CASCADING_MENU_TOP_GAP - CASCADING_MENU_BOTTOM_GAP)/2;
        wgui_fixed_list_move_icontext_menu(
            small_screen_x + CASCADING_MENU_BORDER_SIZE,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + CASCADING_MENU_TOP_GAP + MMI_TITLE_HEIGHT);
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        small_screen_x = (MAIN_LCD_DEVICE_WIDTH - popup_width)/2;
        small_screen_y = (MAIN_LCD_DEVICE_HEIGHT - list_height - MMI_TITLE_HEIGHT*2 - CASCADING_MENU_BORDER_SIZE*2 - CASCADING_MENU_TOP_GAP - CASCADING_MENU_BOTTOM_GAP)/2;
        wgui_fixed_list_move_icontext_menu(
            small_screen_x + CASCADING_MENU_BORDER_SIZE,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + CASCADING_MENU_TOP_GAP + MMI_TITLE_HEIGHT);
    }
    wgui_fixed_list_resize_icontext_menu(list_width, list_height);
#ifdef __MMI_FTE_SUPPORT__
    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        MMI_MENUITEM_HEIGHT);
#else
    resize_fixed_icontext_menuitems(
        MMI_fixed_list_menu.width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
        MMI_MENUITEM_HEIGHT);
#endif
    if((left_softkey != NULL || left_softkey_icon != NULL) && (right_softkey != NULL || right_softkey_icon != NULL))
    {
        softkey_width = (popup_width - CASCADING_MENU_BORDER_SIZE*2)/2;
    }
    else if((left_softkey != NULL || left_softkey_icon != NULL) || (right_softkey != NULL || right_softkey_icon != NULL))
    {
        softkey_width = popup_width - CASCADING_MENU_BORDER_SIZE*2;
    }
    else
    {
        softkey_width = 0;
    }
    if(left_softkey != NULL || left_softkey_icon != NULL)
    {
        wgui_softkey_set_theme(
            MMI_LEFT_SOFTKEY,
            current_MMI_theme->popup_embedded_lsk_normal_up_filler,
            current_MMI_theme->popup_embedded_lsk_normal_down_filler,
            *current_MMI_theme->LSK_up_text_color,
    		*current_MMI_theme->LSK_down_text_color,
            *current_MMI_theme->softkey_text_border_color,
            &MMI_medium_font); 
        set_softkey_flags_on(UI_BUTTON_CENTER_TEXT_X, MMI_LEFT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_LEFT_SOFTKEY);
        gui_measure_string((UI_string_type)left_softkey, &lsk_text_w, &softkey_text_h);
        if(left_softkey_icon != NULL && (lsk_text_w + 4) > softkey_width)
        {
            softkey_hide_text = MMI_TRUE;
        }
    }
    if(right_softkey != NULL || right_softkey_icon != NULL)
    {
        wgui_softkey_set_theme(
            MMI_RIGHT_SOFTKEY,
            current_MMI_theme->popup_embedded_rsk_normal_up_filler,
            current_MMI_theme->popup_embedded_rsk_normal_down_filler,
            *current_MMI_theme->LSK_up_text_color,//RSK_up_text_color
    		*current_MMI_theme->LSK_down_text_color,//RSK_down_text_color
            *current_MMI_theme->softkey_text_border_color,
            &MMI_medium_font);
        set_softkey_flags_on(UI_BUTTON_CENTER_TEXT_X, MMI_RIGHT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_RIGHT_ALIGN, MMI_RIGHT_SOFTKEY);
    	set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_RIGHT_SOFTKEY);
        gui_measure_string((UI_string_type)right_softkey, &rsk_text_w, &softkey_text_h);
        if(right_softkey_icon != NULL && (rsk_text_w + 4) > softkey_width)
        {
            softkey_hide_text = MMI_TRUE;
        }
    }
    if(left_softkey_icon == NULL || right_softkey_icon == NULL)
    {
        softkey_hide_text = MMI_FALSE;
    }
    
    wgui_cat_add_softkey(
        (U8*)left_softkey,
        left_softkey_icon,
        (U8*)right_softkey,
        right_softkey_icon,
        softkey_hide_text);
    /* move must before resize */
    if(left_softkey != NULL || left_softkey_icon != NULL)
    {
        move_softkey(
            small_screen_x + CASCADING_MENU_BORDER_SIZE,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + popup_title_h + list_height + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP,
            MMI_LEFT_SOFTKEY);
        resize_softkey(
            softkey_width,
            popup_title_h,
            MMI_LEFT_SOFTKEY);
        register_hide_softkey(wgui_cat1004_hide_lsk, MMI_LEFT_SOFTKEY);
    }
    else if(right_softkey != NULL || right_softkey_icon != NULL)
    {
        move_softkey(
            small_screen_x + CASCADING_MENU_BORDER_SIZE,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + popup_title_h + list_height + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP,
            MMI_RIGHT_SOFTKEY);
        resize_softkey(
            softkey_width,
            popup_title_h,
            MMI_RIGHT_SOFTKEY);      
        register_hide_softkey(wgui_cat1004_hide_rsk, MMI_RIGHT_SOFTKEY);
    }
    if((right_softkey != NULL || right_softkey_icon != NULL) && (left_softkey != NULL || left_softkey_icon != NULL))
    {
        move_softkey(
            small_screen_x + CASCADING_MENU_BORDER_SIZE + softkey_width,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + popup_title_h + list_height + CASCADING_MENU_TOP_GAP + CASCADING_MENU_BOTTOM_GAP,
            MMI_RIGHT_SOFTKEY);
        resize_softkey(
            softkey_width,
            popup_title_h,
            MMI_RIGHT_SOFTKEY);      
        register_hide_softkey(wgui_cat1004_hide_rsk, MMI_RIGHT_SOFTKEY);
    }


#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_category_screen_control_area_pen_handlers(wgui_cat1004_pen_up_hdlr, MMI_PEN_EVENT_UP);
        wgui_register_category_screen_control_area_pen_handlers(wgui_cat1004_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
        wgui_register_category_screen_control_area_pen_handlers(wgui_cat1004_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */

	wgui_cat_setup_category_default_history(MMI_CAT1004_ID, 0, wgui_cat1004_exit);
    dm_set_dm_data_flag(DM_NO_FLAGS);
    dm_add_rectangle(UI_COLOR_BLACK, DM_RECTANGLE_FILL_GRAYSCALE);
    dm_register_category_controlled_callback(wgui_cat1004_draw_ctrl_area);
    dm_redraw_category_screen();

#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) && !defined(__MMI_FTE_SUPPORT__)
    /* erase gui_ssp_pen_pre_hdlr registered by draw manager */
    wgui_pen_register_pre_hdlr(NULL);
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
#endif /* defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN) && !defined(__MMI_FTE_SUPPORT__) */

    /* Show title */
    title_area_w = popup_width - CASCADING_MENU_BORDER_SIZE*2 - popup_title_h;
    gdi_layer_push_and_set_clip(
        small_screen_x + CASCADING_MENU_BORDER_SIZE,
        small_screen_y + CASCADING_MENU_BORDER_SIZE,
        small_screen_x + popup_width - CASCADING_MENU_BORDER_SIZE - popup_title_h,
        small_screen_y + CASCADING_MENU_BORDER_SIZE + popup_title_h);
    gui_set_font(MMI_fixed_icontext_menuitem.text_font);
    gui_set_text_color(MMI_fixed_icontext_menuitem.normal_text_color);
    gui_measure_string((UI_string_type)title, &title_w, &title_h);
    if(title_area_w < title_w)
    {
        title_w = title_area_w;
    }
    if (mmi_fe_get_r2l_state())
    {
       gui_print_truncated_text(
            small_screen_x + CASCADING_MENU_BORDER_SIZE + (title_area_w + title_w)/2,
            small_screen_y + CASCADING_MENU_BORDER_SIZE + (popup_title_h - title_h)/2,
            title_area_w,
            (UI_string_type)title);
    }   
    else
    {
        gui_print_truncated_text(
             small_screen_x + CASCADING_MENU_BORDER_SIZE + (title_area_w - title_w)/2,
             small_screen_y + CASCADING_MENU_BORDER_SIZE + (popup_title_h - title_h)/2,
             title_area_w,
             (UI_string_type)title);
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_width - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory84Screen_int
 * DESCRIPTION
 *  Displays the category84 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items to be displayed
 *  list_of_items           [IN]        Array of items to be displayed.
 *  list_of_icons           [IN]        Array of icons to be displayed.
 *  flags                   [IN]        Represent the type of the menu. LIST_MENU, MATRIX_MENU
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory84Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory53Screen_int(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        list_of_items,
        list_of_icons,
        NULL,
        flags,
        highlighted_item,
        history_buffer);

}   /* end of ShowCategory84Screen */


static MMI_BOOL cat184_center_justify = MMI_FALSE;

static void wgui_cat183_stop_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_stop_list_menuitem_scrolling();
}


static void wgui_cat183_resume_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    show_dynamic_list();
}
/*****************************************************************************
* FUNCTION
*  ShowCategory183Screen
* DESCRIPTION
*  Similar to Category 184 but data caching is disabled in dynamic list menu.
*  
*  Designed for JAM (Java application manager) because Java adopts special architecture.
* PARAMETERS
*  title                   [IN]        Title for the screen
*  title_icon              [IN]        Icon shown with the title
*  left_softkey            [IN]        Left softkey label
*  left_softkey_icon       [IN]        Icon for the Left softkey
*  right_softkey           [IN]        Right softkey label
*  right_softkey_icon      [IN]        Icon for the right softkey
*  number_of_items         [IN]        Number of items to be displayed
*  get_item_func           [IN]        Function pointer to get next displayed items
*  get_hint_func           [IN]        Function pointer to get next displayed hint data
*  highlighted_item        [IN]        Index of item to be highlighted
*  disable_data_cache      [IN]        Whether caching of dynamic data is disabled
*  flush_data_callback     [IN]        Callback function invoked before data is reloaded
*  history_buffer          [IN]        History buffer
* RETURNS
*  void
*****************************************************************************/
void ShowCategory183Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        MMI_BOOL disable_data_cache,
        void (*flush_data_callback) (void),
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags = 0;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY184_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_layer_lock_frame_buffer();
	
	dm_add_title(title, title_icon);
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);

    if (wgui_cat_get_list_menu_flags_callback)
    {
        flags = wgui_cat_get_list_menu_flags_callback();
    }

#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        disable_data_cache,
        flush_data_callback,
        flags,
        (U16)CatId,
        history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        disable_data_cache,
        flush_data_callback,
        flags,
        MMI_CATEGORY184_ID,
        history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */

#if defined(__MMI_MAINLCD_128X64__)
    wgui_title_set_no_icon_shct(MMI_FALSE);
#endif /* __MMI_MAINLCD_128X64__ */

    if(cat184_center_justify)
    {
        MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_ICON_CENTER_JUSTIFY;
    }

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_execute_atv_sms_cb();
#endif /* __ATV_SMS_SUPPORT__ */

    gdi_layer_unlock_frame_buffer();
	
    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_cat183_stop_scroll);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat183_resume_scroll);

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, s32flags, ExitCategory184Screen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY184_ID, 0, ExitCategory184Screen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory184Screen */


void wgui_cat184_set_icon_center_justify(MMI_BOOL center)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat184_center_justify = center;
}


void wgui_cat184_refresh_list(S32 number_of_items, S32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif
//  reset_softkeys();
    reset_softkey(MMI_LEFT_SOFTKEY);
    reset_softkey(MMI_RIGHT_SOFTKEY);
    redraw_left_softkey();
    redraw_right_softkey();
    reset_softkey(MMI_CENTER_SOFTKEY);
    redraw_center_softkey();
    wgui_text_menuitem_reset_scrolling();
    /* update the dynamic list */
    wgui_dynamic_list_update_icontext_menu(number_of_items, highlighted_item);
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory184Screen
 * DESCRIPTION
 *  Displays the category184 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory184Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory183Screen(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_image(left_softkey_icon),
        get_string(right_softkey),
        get_image(right_softkey_icon),
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        MMI_FALSE,
        UI_dummy_function,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory185Screen
 * DESCRIPTION
 *  Similar to Category 184 but data caching is disabled in dynamic list menu.
 *  
 *  Designed for JAM (Java application manager) because Java adopts special architecture.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  disable_data_cache      [IN]        Whether caching of dynamic data is disabled
 *  flush_data_callback     [IN]        Callback function invoked before data is reloaded
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory185Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        MMI_BOOL disable_data_cache,
        void (*flush_data_callback) (void),
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ShowCategory183Screen(
		get_string(title),
		get_image(title_icon),
		get_string(left_softkey),
		get_image(left_softkey_icon),
		get_string(right_softkey),
		get_image(right_softkey_icon),
		number_of_items,
		get_item_func,
		get_hint_func,
		highlighted_item,
		disable_data_cache,
		flush_data_callback,
		history_buffer);

}   /* end of ShowCategory184Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory184Screen
 * DESCRIPTION
 *  Exits category 184 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory184Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_128X64__)
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
#endif /* __MMI_MAINLCD_128X64__ */
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();

    cat184_center_justify = MMI_FALSE;
    dynamic_item_text_align_left = FALSE;
    wgui_cat_get_list_menu_flags_callback = NULL;
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_reset_atv_sms_struct();
    wgui_cat_enable_list_menu_empty_lable();
#endif /* __ATV_SMS_SUPPORT__ */
}


/*****************************************************************************
* Category 284
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory284Screen
 * DESCRIPTION
 *  show category 284
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  history_buffer          [IN]        HisgoryBuffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory284Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_text_align_left = TRUE;
    ShowCategory184Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        history_buffer);
}


/*****************************************************************************
* Category 186
* Dynamic list menu supporting on/off toggling
*****************************************************************************/

/* Context of category 186 */
typedef struct
{
    /* Array of 0-1 states */
    U8 *states;
    /* callback function to get text  */
      pBOOL(*get_text_callback) (S32 item_index, UI_string_type str_buff);
    /* Whether data is modified */
    MMI_BOOL modified;
} wgui_cat186_context_struct;

/* Context pointer of category 186 */
static wgui_cat186_context_struct *wgui_cat186_p;

/* Function Pointer to save the extra LSK handler function for Category187 */
FuncPtr wgui_cat_187_lsk_handler = NULL;
pBOOL(*wgui_cat_187_img_callback) (S32 item_index, U8 state, PU8 *img_buff_p) = NULL;
pBOOL(*wgui_cat_187_pre_highlight_callback) (S32 item_index) = NULL;

/*****************************************************************************
 * FUNCTION
 *  Category186GetItem
 * DESCRIPTION
 *  Common dynamic item data callback for Category 186
 * PARAMETERS
 *  item_index          [IN]        Menu item index
 *  str_buff            [IN]        Text buffer
 *  img_buff_p          [IN]        Pointer to image buffer
 *  str_img_mask        [IN]        Mask (unused)
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL Category186GetItem(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL ret_val = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);
    UI_UNUSED_PARAMETER(str_img_mask);

    if(wgui_cat_187_img_callback == NULL)
    {
        if (wgui_cat186_p->states[item_index])
        {
            *img_buff_p = get_image(CHECKBOX_ON_IMAGE_ID);
        }
        else
        {
            *img_buff_p = get_image(CHECKBOX_OFF_IMAGE_ID);
        }
    }
    else
    {
        ret_val = wgui_cat_187_img_callback(item_index,wgui_cat186_p->states[item_index],img_buff_p);
    }

    if(ret_val)
    {
        return wgui_cat186_p->get_text_callback(item_index, str_buff);
    }
    else
    {
        return ret_val;
    }
}


static void Category186SetItemImg(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 img_buff_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);
    
    if(wgui_cat_187_img_callback == NULL)
    {
        if (wgui_cat186_p->states[item_index])
        {
            img_buff_p = get_image(CHECKBOX_ON_IMAGE_ID);
        }
        else
        {
            img_buff_p = get_image(CHECKBOX_OFF_IMAGE_ID);
        }
    }
    else
    {
        wgui_cat_187_img_callback(item_index,wgui_cat186_p->states[item_index],&img_buff_p);
    }
    MMI_fixed_icontext_menuitems[item_index].item_icon = img_buff_p;
}

/*****************************************************************************
 * FUNCTION
 *  Category186ToggleCheckBox
 * DESCRIPTION
 *  Toggle on/off of the current highlighted checkbox
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Category186ToggleCheckBox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);

    gdi_layer_lock_frame_buffer();
    if (wgui_cat186_p->states[index])
    {
        wgui_cat186_p->states[index] = 0;
		ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    else
    {
        wgui_cat186_p->states[index] = 1;
		ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    Category186SetItemImg(index);

    if (!wgui_cat186_p->modified)
    {
        wgui_cat186_p->modified = MMI_TRUE;
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);
    }

    /* Reload data & invoke list highlight handler */
    gdi_layer_unlock_frame_buffer();

    show_dynamic_list();
    
    if(wgui_cat_187_lsk_handler != NULL)
    {
        wgui_cat_187_lsk_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Category186ListHighlightHdlr
 * DESCRIPTION
 *  Exit category function for category 186
 * PARAMETERS
 *  item_index      [IN]        Index of item to set highlight
 * RETURNS
 *  void
 *****************************************************************************/
void Category186ListHighlightHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL ret_val = TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);

    gdi_layer_lock_frame_buffer();
    if(wgui_cat_187_pre_highlight_callback != NULL)
    {
        /* If the function below returns FALSE then we need to clear 
         * the LSK handler.Else everything will work normally
         */
        ret_val = wgui_cat_187_pre_highlight_callback(item_index);
    }

    if(ret_val)
    {
        if (wgui_cat186_p->states[item_index])
        {
            ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
        }

        /* We need to set the LeftSoftkeyFunction everytime  in case 
         * wgui_cat_187_pre_highlight_callback is registered 
         */
        if(wgui_cat_187_pre_highlight_callback != NULL)
        {
            SetLeftSoftkeyFunction(Category186ToggleCheckBox, KEY_EVENT_UP);
        }
    }
    else
    {
        /* This will clear the LSK handler */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }

    dynamic_list_highlight_handler(item_index);
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory186History
 * DESCRIPTION
 *  Get history data of category 186
 * PARAMETERS
 *  history_buffer      [OUT]        Buffer to store history data
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetCategory186History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);

    if (wgui_cat186_p->modified)
    {
        *((S32*) history_buffer) = 1;
    }
    else
    {
        *((S32*) history_buffer) = 0;
    }
    get_list_menu_category_history(MMI_CATEGORY186_ID, history_buffer + sizeof(S32));
    return history_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory186HistorySize
 * DESCRIPTION
 *  Get history data of category 186
 * PARAMETERS
 *  void
 * RETURNS
 *  Size of 186 history
 *****************************************************************************/
S32 GetCategory186HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(S32) + get_list_menu_category_history_size();
}


/*****************************************************************************
 * FUNCTION
 *  SetCategory186History
 * DESCRIPTION
 *  Set history data of category 186
 * PARAMETERS
 *  history_buffer      [OUT]        Buffer to store history data
 * RETURNS
 *  Whether the operation succeeds
 *****************************************************************************/
U8 SetCategory186History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);

    if (history_buffer)
    {
        if (*((S32*) history_buffer))
        {
            wgui_cat186_p->modified = MMI_TRUE;
        }
        else
        {
            wgui_cat186_p->modified = MMI_FALSE;
        }
        return set_list_menu_category_history(MMI_CATEGORY186_ID, history_buffer + sizeof(S32));
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory186Screen
 * DESCRIPTION
 *  Exit category function for category 186
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory186Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(wgui_cat186_p);

    ExitCategory184Screen();

    OslMfree(wgui_cat186_p);
    wgui_cat186_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory186Screen
 * DESCRIPTION
 *  Displays the category186 screen. A dynamic menu handling on/off toggling.
 *  Use SetCheckboxToggleRightSoftkeyFunctions() *before* this function.
 *  
 *  Reference: ShowCategory185Screen(), ShowCategory140Screen()
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_text_callback       [IN]        Callback function to get the text of menu item
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  list_of_states          [IN]        On/off states
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory186Screen(
        U16 title,
        U16 title_icon,
        S32 number_of_items,
        pBOOL(*get_text_callback) (S32 item_index, UI_string_type str_buff),
        GetHintFuncPtr get_hint_func,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ShowCategory187Screen(
        title,
        title_icon,
        number_of_items,
        get_text_callback,
        NULL,
        NULL,
        get_hint_func,
        list_of_states,
        highlighted_item,
        NULL,
        history_buffer);
}

#ifdef __MMI_TOUCH_SCREEN__
static void wgui_cat187_tap_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Category186ToggleCheckBox();
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  ShowCategory187Screen
 * DESCRIPTION
 *  Displays the category187 screen. A dynamic menu handling on/off toggling.
 *  Use SetCheckboxToggleRightSoftkeyFunctions() *before* this function.
 *  
 *  Reference: ShowCategory185Screen(), ShowCategory140Screen()
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_text_callback       [IN]        Callback function to get the text of menu item
 *  get_img_callback        [IN]        Callback function to get the image of menu item
 *  pre_highlight_callback  [IN]        Callback function to be called before highlight 
 *                                      if application wants to perform some extra task 
 *                                      before higlighting any menu item.Currently it is
 *                                      used for clearing LSK for a particular menu item.
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  list_of_states          [IN]        On/off states
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  lsk_handler_func        [IN]        This is an extra lsk handler.Needs to be 
 *                                      registered to add extra functionality along with toggle.
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory187Screen(
        U16 title,
        U16 title_icon,
        S32 number_of_items,
        pBOOL(*get_text_callback) (S32 item_index, UI_string_type str_buff),
        pBOOL(*get_img_callback) (S32 item_index, U8 state, PU8 *img_buff_p),
        pBOOL(*pre_highlight_callback) (S32 item_index),
        GetHintFuncPtr get_hint_func,
        U8 *list_of_states,
        S32 highlighted_item,
        FuncPtr lsk_handler_func,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Setup context */
    if (!wgui_cat186_p)
    {
        wgui_cat186_p = OslMalloc(sizeof(wgui_cat186_context_struct));
    }
    wgui_cat186_p->get_text_callback = get_text_callback;
    wgui_cat186_p->states = list_of_states;
    wgui_cat186_p->modified = MMI_FALSE;

    /* Draw screen */
    gdi_layer_lock_frame_buffer();
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
    if(number_of_items > 0)
    {
        dm_add_softkey_id((MMI_STR_ID)STR_GLOBAL_ON, (MMI_STR_ID)STR_GLOBAL_BACK);

    }
    else
    {
        dm_add_softkey_id((MMI_STR_ID)0, (MMI_STR_ID)STR_GLOBAL_BACK);
    }

    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        Category186GetItem,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

    resize_fixed_list(MMI_content_width, MMI_content_height);

    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    //set_fixed_icontext_positions(MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0, 1, 0);

    wgui_dynamic_list_override_icontext_highlight_handler(Category186ListHighlightHdlr);

    if(lsk_handler_func != NULL)
    {
        wgui_cat_187_lsk_handler = lsk_handler_func;
    }
    else
    {
        wgui_cat_187_lsk_handler = NULL;
    }
	
    /* If this callback is registered then Application will provide the Menuitem image */
    wgui_cat_187_img_callback = get_img_callback;
    
    /* If this callback is registered then the function will be invoked before highlighting any item */
    wgui_cat_187_pre_highlight_callback = pre_highlight_callback;
	
    set_left_softkey_function(Category186ToggleCheckBox, KEY_EVENT_UP);

    
    h_flag = SetCategory186History(history_buffer);
    if (wgui_cat186_p->modified)
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        set_right_softkey_function(checkbox_toggle_DONE_RSK_function, KEY_EVENT_UP);
    }
    else
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
        set_right_softkey_function(checkbox_toggle_BACK_RSK_function, KEY_EVENT_UP);
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(wgui_cat187_tap_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */

    dynamic_list_goto_item_no_redraw(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);

    set_dynamic_pop_up_descriptions(h_flag ? MMI_fixed_list_menu.highlighted_item : highlighted_item);  /* ????? */

    if(number_of_items > 0)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
        SetCenterSoftkeyFunction(Category186ToggleCheckBox, KEY_EVENT_UP);
    }

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category(
		MMI_CATEGORY186_ID,
		0,
		ExitCategory186Screen,
		GetCategory186History,
		GetCategory186HistorySize);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  GetListCategoryHistory
 * DESCRIPTION
 *  Get category history function of current main lcd category scrren
 *  using list menu
 * PARAMETERS
 *  history_buffer      [OUT]       Buffer to write history of list
 * RETURNS
 *  void
 *****************************************************************************/
U8 *GetListCategoryHistory(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history((U16) g_gui_current_catid, history_buffer);
    return (history_buffer);
}   /* end of GetListCategoryHistory */


/*****************************************************************************
 * FUNCTION
 *  SetListScreenFunctions
 * DESCRIPTION
 *  Common functions to set ExitCategory, RedrawCategory, GetCategoryHistory
 *  GetCategoryHistorySize functions.
 * PARAMETERS
 *  cat_id      [IN]        Current category id
 * RETURNS
 *  void
 *****************************************************************************/
void SetListScreenFunctions(S32 cat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExitCategoryFunction = ExitListCategoryScreen;
    RedrawCategoryFunction = RedrawListCategoryScreen;
    GetCategoryHistory = GetListCategoryHistory;
    GetCategoryHistorySize = get_list_menu_category_history_size;
    g_gui_current_catid = cat_id;
}   /* end of SetListScreenFunctions */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory158Screen
 * DESCRIPTION
 *  Displays the category158 screen, Editor option list category (With editor menu item in it)
 *  Pass by menu item string.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items string array
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        (see explanation below)
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 *  f_highlight             [IN]        Highlight handler
 *  f_close                 [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory158Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8  **list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *new_list_of_items[MAX_SUB_MENUS];
    U16 new_list_of_icons[MAX_SUB_MENUS];
    S32 new_num_of_items, i, ixsize, iysize, s32CatId;

#ifdef __MMI_SMALL_LIST_SCREEN__
    S32 icon_width = 0, icon_height = 0;
    color c = UI_COLOR_BLACK;
#endif /* __MMI_SMALL_LIST_SCREEN__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_num_of_items = wgui_inputs_options_add_menu_items(
        number_of_items,
        list_of_items,
        new_list_of_items,
        list_of_icons,
        new_list_of_icons,
        NULL,
        NULL,
        f_highlight,
        f_close,
        history_buffer);

#ifdef __MMI_SMALL_LIST_SCREEN__
    if (whether_no_small_screen())
    {
        MMI_title_x = MMI_SMALL_SCREEN_X_OFFSET + 1;
        MMI_title_y += MMI_title_height + MMI_SMALL_SCREEN_Y_OFFSET;
        MMI_title_width -= (2 * MMI_SMALL_SCREEN_X_OFFSET + 1);

        gdi_layer_lock_frame_buffer();

        set_small_screen();
        gui_add_cleanup_hook(disable_resized_small_screen);

        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);    /* early status icon */
		dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
		dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
        wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, 0, NULL);
        SetCategoryEditorOptionListHistory(history_buffer, highlighted_item);

        fixed_list_backup_filler = MMI_fixed_list_menu.normal_filler;
        MMI_fixed_list_menu.normal_filler = (current_MMI_theme->small_list_menu_normal_filler);
        MMI_fixed_icontext_menuitem.normal_text_color = *(current_MMI_theme->small_list_menu_text_color);
        MMI_fixed_icontext_menuitem.selected_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);
        MMI_fixed_icontext_menuitem.focussed_text_color = *(current_MMI_theme->small_list_menu_highlight_text_color);
    
        wgui_set_disable_shortcut_display();
        wgui_fixed_list_begin_add_icontext_one_item();

        if (list_of_icons == NULL)
        {
            for (i = 0; i < new_num_of_items; i++)
            {
                wgui_fixed_list_add_icontext_one_item(i, new_list_of_items[i], NULL, NULL);
            }
        }
        else
        {
            for (i = 0; i < new_num_of_items; i++)
            {
                wgui_fixed_list_add_icontext_one_item(i, new_list_of_items[i], wgui_get_list_menu_icon(i, new_list_of_icons[i]), NULL);
                if (new_list_of_icons[i] != 0)
                {
                    /*flag = 1;*/
                    gui_measure_image(get_image(new_list_of_icons[i]), &icon_width, &icon_height);
                }
            }
        }
        wgui_fixed_list_end_add_icontext_one_item();

        if (new_num_of_items <= MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT)
        {
            cat10_list_item_num = new_num_of_items;
            MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_SCROLLBAR;
            wgui_fixed_list_resize_icontext_menu(MMI_SMALL_LIST_SCREEN_WIDTH - 3, get_menu_item_height() * new_num_of_items);
            resize_fixed_icontext_menuitems(MMI_SMALL_LIST_SCREEN_WIDTH - 3  - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP, 0);
            wgui_fixed_list_move_icontext_menu(
                MMI_SMALL_LIST_LEFT_OFFSET + 1,
                UI_device_height - MMI_button_bar_height - (4 + get_menu_item_height() * new_num_of_items + 4 + 5) + 4);
        }
        else
        {
            cat10_list_item_num = MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT;
            wgui_fixed_list_resize_icontext_menu(
                MMI_SMALL_LIST_SCREEN_WIDTH - 3,
                get_menu_item_height() * MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT);
            resize_fixed_icontext_menuitems(MMI_SMALL_LIST_SCREEN_WIDTH - 3 - MMI_fixed_list_menu.vbar.width, 0);
            wgui_fixed_list_move_icontext_menu(
                MMI_SMALL_LIST_LEFT_OFFSET + 1,
                UI_device_height - MMI_button_bar_height - (4 + get_menu_item_height() * MMI_SMALL_SCREEN_MAX_LIST_ITEMS_COUNT + 4 + 5) + 4);
        }
        title_bg_id = IMG_FLEXIBLE_TITLEBAR_BG;

        gdi_layer_unlock_frame_buffer();

		wgui_cat_setup_category(
			MMI_CATEGORY10_ID,
			0,
			ExitCategory10Screen,
			GetCategoryEditorOptionListHistory,
			GetCategoryEditorOptionListHistorySize);
        dm_add_rectangle(c, DM_RECTANGLE_FILL_GRAYSCALE);
        dm_register_category_controlled_callback(DrawCate10CategoryControlArea);
        dm_redraw_category_screen();
    }
    else
#endif /* __MMI_SMALL_LIST_SCREEN__ */ 
    {
        gdi_layer_lock_frame_buffer();
		dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
		dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
        wgui_title_set_menu_shortcut_number(-1);

        MMI_current_menu_type = flags & 0x0f;

        switch (MMI_current_menu_type)
        {
            case LIST_MENU:

                wgui_fixed_list_create_icontext_menu(new_num_of_items, highlighted_item, 0, 0, NULL);
                SetCategoryEditorOptionListHistory(history_buffer, highlighted_item);
                
                wgui_fixed_list_begin_add_icontext_one_item();
                for (i = 0; i < new_num_of_items; i++)
                {
                    wgui_fixed_list_add_icontext_one_item(i, new_list_of_items[i], wgui_get_list_menu_icon(i, new_list_of_icons[i]), NULL);
                }
                wgui_fixed_list_end_add_icontext_one_item();
                wgui_fixed_list_resize_icontext_menu(MMI_content_width, MMI_content_height);

                break;

            case MATRIX_MENU:
                wgui_fixed_matrix_create_menu(new_num_of_items, highlighted_item, 0, 0, NULL);
                SetCategoryEditorOptionListHistory(history_buffer, highlighted_item);

                wgui_fixed_matrix_begin_add_one_item();
                for (i = 0; i < new_num_of_items; i++)
                {
                    wgui_fixed_matrix_add_one_item(i, new_list_of_items[i], get_image(new_list_of_icons[i]));
                }
                
                MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_LOOP;
        
                wgui_fixed_matrix_override_highlight_handler(standard_animated_matrix_highlight_handler_type2);

                if (new_num_of_items > 9)
                {
                    ixsize = (MMI_content_width - MMI_fixed_matrix_menu.vbar.width - 6) / 3;
                }
                else
                {
                    ixsize = (MMI_content_width - 6) / 3;
                }
                iysize = (MMI_content_height - 6) / 3;
                configure_fixed_matrix(ixsize, iysize, 3, 0);
                wgui_fixed_matrix_end_add_one_item();
                MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_DISABLE_TEXT_DISPLAY;
                break;
        }

        gdi_layer_unlock_frame_buffer();
		
        if ((MMI_current_menu_type == LIST_MENU) || (MMI_current_menu_type == PAGE_MENU))
        {
            s32CatId = MMI_CATEGORY15_LIST_ID;
        }
        else
        {
            s32CatId = MMI_CATEGORY15_MATRIX_ID;
        }
		
		wgui_cat_setup_category(
			s32CatId,
			0,
			ExitCategory15Screen,
			GetCategoryEditorOptionListHistory,
			GetCategoryEditorOptionListHistorySize);
        dm_redraw_category_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory159Screen
 * DESCRIPTION
 *  Displays the category159 screen, Editor option list category (With editor menu item in it)
 *  Pass by menu item string ID.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items id array
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        (see explanation below)
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 *  f_highlight             [IN]        Highlight handler
 *  f_close                 [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory159Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }

    ShowCategory158Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        list_of_icons,
        flags,
        highlighted_item,
        history_buffer,
        f_highlight,
        f_close);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory539Screen_ext
 * DESCRIPTION
 *  Displays the category529 screen ( List menu with description )
 *  Pass by menu item string.
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 *  f_highlight                 [IN]        Highlight handler
 *  f_close                     [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory539Screen_ext(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer,
                void (*f_highlight) (S32 item_index),
                void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *new_list_of_items[MAX_SUB_MENUS];
    U8 *new_list_of_descriptions[MAX_SUB_MENUS];
    U16 new_list_of_icons[MAX_SUB_MENUS];
    S32 new_num_of_items;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY52_ID;
    S32 s32flags = 0;
#endif /* __ATV_SMS_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
        s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }
#endif /* __ATV_SMS_SUPPORT__ */
    
    new_num_of_items = wgui_inputs_options_add_menu_items(
                            number_of_items,
                            list_of_items,
                            new_list_of_items,
                            list_of_icons,
                            new_list_of_icons,
                            list_of_descriptions,
                            new_list_of_descriptions,
                            f_highlight,
                            f_close,
                            history_buffer);
    
    gdi_layer_lock_frame_buffer();
    dm_add_title(title, title_icon);
    dm_add_softkey_str(left_softkey, right_softkey);
    
    wgui_fixed_list_create_icontext_menu(new_num_of_items, highlighted_item, 0, 0, NULL);
    SetCategoryEditorOptionListHistory(history_buffer, highlighted_item);
    
    wgui_fixed_list_begin_add_icontext_one_item();
    for(i = 0; i < new_num_of_items; i++)
    {
        if(list_of_descriptions == NULL)
        {
            wgui_fixed_list_add_icontext_one_item(i, new_list_of_items[i], wgui_get_list_menu_icon(i, new_list_of_icons[i]), NULL);
        }
        else
        {
            wgui_fixed_list_add_icontext_one_item(i, new_list_of_items[i], wgui_get_list_menu_icon(i, new_list_of_icons[i]), new_list_of_descriptions[i]);
        }
    }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    wgui_cat_set_hint_in_menuitem(list_of_descriptions, new_num_of_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */
    wgui_fixed_list_end_add_icontext_one_item();
    
    gdi_layer_unlock_frame_buffer();
    
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category(
        CatId,
        s32flags,
        ExitCategoryCommonScreen,
        GetCategoryEditorOptionListHistory,
        GetCategoryEditorOptionListHistorySize);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category(
        MMI_CATEGORY52_ID,
        0,
        ExitCategoryCommonScreen,
        GetCategoryEditorOptionListHistory,
        GetCategoryEditorOptionListHistorySize);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory539Screen
 * DESCRIPTION
 *  Displays the category529 screen ( List menu with description )
 *  Pass by menu item string.
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 *  f_highlight                 [IN]        Highlight handler
 *  f_close                     [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory539Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory539Screen_ext(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer,
        f_highlight,
        f_close);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory529Screen
 * DESCRIPTION
 *  Displays the category529 screen ( List menu with description for editor option )
 *  Menu list with menu item text id.
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer              [IN]        History buffer
 *  f_highlight                 [IN]        Highlight handler
 *  f_close                     [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory529Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }

    ShowCategory539Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        list_of_icons,
        list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer,
        f_highlight,
        f_close);
}   


/*****************************************************************************
 * FUNCTION
 *  ShowCategory369Screen
 * DESCRIPTION
 *  Displays the category369 screen. (Editor option radio list category (With editor menu item in it)
 *  Pass by menu item string.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 *  f_highlight             [IN]        Highlight handler
 *  f_close                 [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory369Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *new_list_of_items[MAX_SUB_MENUS];
    S32 new_num_of_items, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_num_of_items = wgui_inputs_options_add_menu_items(
        number_of_items,
        list_of_items,
        new_list_of_items,
        NULL,
        NULL,
        NULL,
        NULL,
        f_highlight,
        f_close,
        history_buffer);
    
    gdi_layer_lock_frame_buffer();
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    /* Setup menuitem */
    wgui_fixed_list_create_twostate_menu(
        get_image(RADIO_ON_IMAGE_ID),
        get_image(RADIO_OFF_IMAGE_ID),
        new_num_of_items,
        highlighted_item,
        0,
        0,
        NULL);

    SetCategoryEditorOptionListHistory(history_buffer, highlighted_item);

    wgui_fixed_list_begin_add_twostate_one_item();

    for (i = 0; i < new_num_of_items; i++)
    {
        wgui_fixed_list_add_twostate_one_item(i, new_list_of_items[i], NULL);
    }
    wgui_fixed_list_end_add_twostate_one_item();
    wgui_fixed_list_override_twostate_highlight_handler(standard_radio_list_highlight_handler);

    select_fixed_twostate_item(MMI_fixed_list_menu.highlighted_item);

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category(
		MMI_CATEGORY36_ID,
		0,
		ExitListCategoryScreen,
		GetCategoryEditorOptionListHistory,
		GetCategoryEditorOptionListHistorySize);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory118Screen
 * DESCRIPTION
 *  Displays the category118 screen, Editor option list category (With editor menu item in it)
 *  Pass by menu item string ID.
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        List of text items
 *  highlighted_item        [IN]        Zero based index of the highlighed item (used if there is no history)
 *  history_buffer          [IN]        History buffer
 *  f_highlight             [IN]        Highlight handler
 *  f_close                 [IN]        Close function to return to editor screen
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory118Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }

    ShowCategory369Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        highlighted_item,
        history_buffer,
        f_highlight,
        f_close);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategoryEditorOptionListHistory
 * DESCRIPTION
 *  Gets the history buffer for Editor option list
 * PARAMETERS
 *  history_buffer      [OUT]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *GetCategoryEditorOptionListHistory(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 s;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY52_ID;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
    }
    get_list_menu_category_history(CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    get_list_menu_category_history(MMI_CATEGORY52_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    s = sizeof(list_menu_category_history);
    memcpy((S8 *)(((U32)history_buffer + s + 3) & ~3), (S8 *)mmi_imc_get_editor_history_data(), sizeof(mmi_imc_editor_menu_history_data_struct));
    s = sizeof(list_menu_category_history) + sizeof(mmi_imc_editor_menu_history_data_struct);
    wgui_inputs_options_menu_get_category_history((U8 *)(((U32)history_buffer + s + 3) & ~3));
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  GetCategoryEditorOptionListHistorySize
 * DESCRIPTION
 *  Gets the history buffer size for CategoryEditorOptionList screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 GetCategoryEditorOptionListHistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(list_menu_category_history) + sizeof(mmi_imc_editor_menu_history_data_struct) + sizeof(editor_list_menu_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  SetCategoryEditorOptionListHistory
 * DESCRIPTION
 *  Sets the history for Editor option list
 * PARAMETERS
 *  history_buffer          [IN]        Is the buffer from which the history data is restored
 *  highlighted_item        [IN]        Highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategoryEditorOptionListHistory(U8 *history_buffer, U16 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    editor_list_menu_category_history *h = NULL;
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_NORMAL_KEYPAD__)
    S32 new_word_on_off;
    S32 offset_on_off = 3; /* Need to add Insert Symbol and Set Zi menu item offset*/
    S32 offset_off_on = 2; /* Need to add Insert Symbol and Set Zi menu item offset*/
#endif
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY52_ID;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
    }
#endif /* __ATV_SMS_SUPPORT__ */

    if (history_buffer != NULL)
    {
    #if defined(__ATV_SMS_SUPPORT__)
        h_flag = set_list_menu_category_history((U16)CatId, history_buffer);
    #else /* __ATV_SMS_SUPPORT__ */
        h_flag = set_list_menu_category_history(MMI_CATEGORY52_ID, history_buffer);
    #endif /* __ATV_SMS_SUPPORT__ */
        if (!h_flag)
        {
            MMI_fixed_list_menu.highlighted_item = highlighted_item;
        }
        else
        {
            h = (editor_list_menu_category_history*)(history_buffer + (sizeof(list_menu_category_history) + sizeof(mmi_imc_editor_menu_history_data_struct)));

            wgui_inputs_options_menu_set_category_history_key_info((U8*)&h->key_info);

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_NORMAL_KEYPAD__)
            new_word_on_off = mmi_imm_is_smart_alphabetic_input_modes_enabled();

            if ((h->new_word_on_off == MMI_TRUE) && (new_word_on_off == MMI_FALSE) &&
                (MMI_fixed_list_menu.highlighted_item > (h->input_method_index + offset_on_off)))
            {
                MMI_fixed_list_menu.highlighted_item--;
            }
            else if ((h->new_word_on_off == MMI_FALSE) && (new_word_on_off == MMI_TRUE) &&
                     (MMI_fixed_list_menu.highlighted_item > (h->input_method_index + offset_off_on)))
            {
                MMI_fixed_list_menu.highlighted_item++;
            }
#endif           
        }
    }
}


#if defined(__MMI_FTE_SUPPORT__)
#define MMI_CAT22_MATRIX_COLUMNS    6

static void mmi_cat22_caculate_item_width_height(S32 nums, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rows = 0;
    S32 tw = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rows = nums/MMI_CAT22_MATRIX_COLUMNS;
    if(nums%MMI_CAT22_MATRIX_COLUMNS != 0)
    {
        rows += 1;
    }
    tw = MMI_content_width/MMI_CAT22_MATRIX_COLUMNS;
    *h = tw;

    if(rows*tw > MMI_content_height)
    {
        tw = (MMI_content_width - UI_SCROLLBAR_WIDER_WIDTH)/MMI_CAT22_MATRIX_COLUMNS;
    }
    *w = tw;
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory22Screen_int
 * DESCRIPTION
 *  Displays the category22 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  num_of_symbols          [IN]        Number of symbols
 *  MMI_symbols             [IN]        Symbols specific to application
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory22Screen_ext(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                UI_string_type right_softkey,
                S32 num_of_symbols,
                U8 **MMI_symbols,
                S32 highlighted_item,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, w = 0, h = 0, tw, th;
#if defined(__ATV_SMS_SUPPORT__)
    S32 CatId = MMI_CATEGORY22_ID;
#endif /* __ATV_SMS_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    gdi_layer_lock_frame_buffer();
	dm_add_title(title, title_icon);
	dm_add_softkey_str(left_softkey, right_softkey);
#if defined(__ATV_SMS_SUPPORT__)
    if (g_atv_sms_struct.Isuse)
    {
        CatId = g_atv_sms_struct.CatId;
    }
    wgui_fixed_matrix_create_menu(num_of_symbols, highlighted_item, WGUI_LIST_MENU_DISABLE_SHORTCUT, (U16)CatId, history_buffer);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_fixed_matrix_create_menu(num_of_symbols, highlighted_item, WGUI_LIST_MENU_DISABLE_SHORTCUT, MMI_CATEGORY22_ID, history_buffer);
#endif /* __ATV_SMS_SUPPORT__ */
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_X;
    MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_LOOP;
    
    MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->symbol_picker_highlight_filler;
    MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->symbol_picker_highlight_filler;
    resize_fixed_matrix(MMI_content_width, MMI_content_height);
    wgui_fixed_matrix_begin_add_one_item();

	gui_set_font(gui_font_get_type(GUI_FONT_SIZE_MATRIX));
    for (i = 0; i < num_of_symbols; i++)
    {
        wgui_fixed_matrix_add_one_item(i, MMI_symbols[i], NULL);

        gui_measure_string((UI_string_type) MMI_symbols[i], &tw, &th);
		if (tw > w)
		{
		    w = tw;
		}
		if (th > h)
		{
		    h = th;
		}
    }
	w += 2;
	h += 2;
	/* if the highlight image is larger than the matrix item, enlarge the matrix item dimension to the image */
    if (current_MMI_theme->symbol_picker_highlight_filler && 
        (current_MMI_theme->symbol_picker_highlight_filler->flags & 0xFF) == UI_FILLED_AREA_TYPE_BITMAP)
    {
        gdi_image_get_dimension(current_MMI_theme->symbol_picker_highlight_filler->b, &tw, &th);
		
        /* 2 for 2-pixel spacing (see configure_fixed_matrix() below) */
        if ((tw > w) && (th > h))
        {
            w = tw;
            h = th;
        }
    }

#if defined(__MMI_FTE_SUPPORT__)
    mmi_cat22_caculate_item_width_height(num_of_symbols, &w, &h);
	configure_fixed_matrix(w, h, MMI_CAT22_MATRIX_COLUMNS, 0);
#else /* __MMI_FTE_SUPPORT__ */
    configure_fixed_matrix(w, h, 0, 0);
#endif /* __MMI_FTE_SUPPORT__ */
    wgui_fixed_matrix_end_add_one_item();
    wgui_fixed_matrix_override_highlight_handler(standard_noshortcut_matrix_highlight_handler);

    gdi_layer_unlock_frame_buffer();
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cat_setup_category_default_history(CatId, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory22Screen);
#else /* __ATV_SMS_SUPPORT__ */
    wgui_cat_setup_category_default_history(MMI_CATEGORY22_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory22Screen);
#endif /* __ATV_SMS_SUPPORT__ */
    dm_redraw_category_screen();
}   /* end of ShowCategory22Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory22Screen
 * DESCRIPTION
 *  Displays the category22 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  num_of_symbols          [IN]        Number of symbols
 *  MMI_symbols             [IN]        Symbols specific to application
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory22Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 num_of_symbols,
        U8 **MMI_symbols,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory22Screen_ext(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_string(right_softkey),
        num_of_symbols,
        MMI_symbols,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory22Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory22Screen
 * DESCRIPTION
 *  Exits the category22 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory22Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_menu_shortcut_handler();
    reset_fixed_matrix();
	
    gui_scrolling_text_stop(&wgui_catEMS_scrolling_text);
#if defined(__ATV_SMS_SUPPORT__)
    wgui_cate_reset_atv_sms_struct();
#endif /* __ATV_SMS_SUPPORT__ */
}   /* end of ExitCategory22Screen */


/*****************************************************************************
 * FUNCTION
 *  GetCategory22HistorySize
 * DESCRIPTION
 *  Get category22 history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  the size of history buffer
 *****************************************************************************/
S32 GetCategory22HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: need to revise.
    return (20);
}   /* end of GetCategory22HistorySize */


/*****************************************************************************
 * FUNCTION
 *  GetCategory22History
 * DESCRIPTION
 *  Get category22 history.
 * PARAMETERS
 *  history_buffer      [IN]        History buffer
 * RETURNS
 *  hitsory buffer
 *****************************************************************************/
U8 *GetCategory22History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_matrix_menu_category_history(MMI_CATEGORY22_ID, history_buffer);
    return (history_buffer);
}   /* end of GetCategory22History */


/***************************************************************************
Function Name: EMS_matrix_highlight_handler
***************************************************************************/
static void wgui_catEMS_set_scrolling_text(void);

#if defined(__MMI_FTE_SUPPORT__)
UI_filled_area catEMS_inputbox_filler_defaultTheme={
    UI_FILLED_AREA_TYPE_COLOR|UI_FILLED_AREA_SINGLE_BORDER,
    UI_IMAGE_ID_NULL,
    NULL,
    {255,255,255,100},
    {0,0,0,100},
    {0,0,0,100},
    {0,0,0,100},
 	0};
#endif /*__MMI_FTE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  EMS_matrix_highlight_handler
 * DESCRIPTION
 *  EMS screen matrix highlight handler
 * PARAMETERS
 *  item_index      [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void EMS_matrix_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINLCD_128X128__
    extern color MMI_white_color;
#endif /* __MMI_MAINLCD_128X128__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);

    gdi_layer_lock_frame_buffer();

#ifdef __MMI_MAINLCD_128X128__
    gui_fill_rectangle(
        MMI_SUBMENU_CONTENT_X,
        MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP,
        MMI_SUBMENU_CONTENT_X + MMI_SUBMENU_CONTENT_WIDTH - 1,
        MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP + MMI_SINGLELINE_INPUTBOX_HEIGHT - 1,
        MMI_white_color);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        MMI_SUBMENU_CONTENT_X,
        MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP,
        MMI_SUBMENU_CONTENT_X + MMI_SUBMENU_CONTENT_WIDTH - 1,
        MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP + MMI_SINGLELINE_INPUTBOX_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */
    
	wgui_catEMS_set_scrolling_text();

    gdi_layer_unlock_frame_buffer();

    MMI_user_highlight_handler_Ext((U8)eMatrixhighlight, item_index);
}


/***************************************************************************
Function Name: ShowCategoryEMSScreen
***************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_catEMS_scrolling_timer
 * DESCRIPTION
 *  timer callback of categoryEMS scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer(?)
 *****************************************************************************/
static void wgui_catEMS_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_handle_scrolling_text(&wgui_catEMS_scrolling_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catEMS_scrolling_text_draw_background
 * DESCRIPTION
 *  background callback of scrolling text, used to draw scroll text background
 * PARAMETERS
 *  x1      [IN]   start position of x
 *  y1      [IN]   start position of y
 *  x2      [IN]   end position of x
 *  y2      [IN]   end position of y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_catEMS_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MAINLCD_128X128__
    extern color MMI_white_color;
    #endif /* __MMI_MAINLCD_128X128__ */
	S32 x11, y11, x22, y22;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	x11 = MMI_SUBMENU_CONTENT_X;
	y11 = MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP;
	x22 = x1 + MMI_SUBMENU_CONTENT_WIDTH - 1;
	y22 = y1 + MMI_SINGLELINE_INPUTBOX_HEIGHT - 1;

#ifdef __MMI_MAINLCD_128X128__
    gui_fill_rectangle(
        x11, y11, x22, y22,
        MMI_white_color);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x11, y11, x22, y22,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catEMS_create_scrolling_preview_name
 * DESCRIPTION
 *  create the scrolling text of ShowCategoryEMSScreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_catEMS_create_scrolling_preview_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	color c;
	S32 x = 0;
    S32 t_w = 0, t_h = 0;
	S32 w = MMI_SUBMENU_CONTENT_WIDTH;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

#ifdef __MMI_FTE_SUPPORT__
	c = catEMS_inputbox_filler_defaultTheme.c;
#else
	c= *current_MMI_theme->list_normal_text_color;
#endif

	Get_StringWidthHeight((U8*)MMI_highlighted_item_text, &t_w, &t_h);

    if(t_w + 8 < w)
    {
        x = ((w - t_w)>>1);
        t_w = t_w + 4;
    }
    else
    {
        x = 4;
		t_w = w - 8;
    }

    gui_create_scrolling_text(
        &wgui_catEMS_scrolling_text,
        x,
        MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP,
        t_w,
        MMI_SINGLELINE_INPUTBOX_HEIGHT,
        (UI_string_type)MMI_highlighted_item_text,
        wgui_catEMS_scrolling_timer,
        wgui_catEMS_scrolling_text_draw_background,
        c,
        c);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catEMS_set_scrolling_text
 * DESCRIPTION
 *  stop the previous scrolling text then create and show current scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_catEMS_set_scrolling_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&wgui_catEMS_scrolling_text);
    wgui_catEMS_create_scrolling_preview_name();
    gui_show_scrolling_text(&wgui_catEMS_scrolling_text);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catEMS_draw_ctrl_area
 * DESCRIPTION
 *  control area callback function, used to create and show object name
 * PARAMETERS
 *  coordinate  [IN] coordinate of control area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_catEMS_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MAINLCD_128X128__
    extern color MMI_white_color;
    #endif /* __MMI_MAINLCD_128X128__ */
    S32 tw = 0, th = 0;
	S32 x, y, w, h;
	color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	x = coordinate->s16X;
	y = coordinate->s16Y;
	w = coordinate->s16Width;
	h = coordinate->s16Height;

#ifdef __MMI_FTE_SUPPORT__
	c = catEMS_inputbox_filler_defaultTheme.c;
#else
	c= *current_MMI_theme->list_normal_text_color;
#endif

	gdi_layer_lock_frame_buffer();
	
#ifdef __MMI_MAINLCD_128X128__
    gui_fill_rectangle(
        x, y, x + w - 1, y + h - 1,
        MMI_white_color);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x, y, x + w - 1, y + h - 1,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */

    gdi_draw_solid_rect(x, y, x + w - 1, y + h - 1, GDI_COLOR_TRANSPARENT);

    gui_set_font(&MMI_medium_font);

	Get_StringWidthHeight((U8*)MMI_highlighted_item_text, &tw, &th);

    if(tw + 4 < w)
    {
        x = ((w - tw)>>1);
        tw = tw + 4;
    }
    else
    {
        x = 4;
		tw = w - 8;
    }

    gui_create_scrolling_text(
        &wgui_catEMS_scrolling_text,
        x, y, tw, h,
        (UI_string_type)MMI_highlighted_item_text,
        wgui_catEMS_scrolling_timer,
        wgui_catEMS_scrolling_text_draw_background,
        c,
        c);

    gui_show_scrolling_text(&wgui_catEMS_scrolling_text);

    gdi_layer_unlock_frame_buffer();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategoryEMSScreen
 * DESCRIPTION
 *  show EMS category
 * PARAMETERS
 *  title                   [IN]        Title for the screen  
 *  title_icon              [IN]        Icon shown with the title  
 *  left_softkey            [IN]        Left softkey label  
 *  left_softkey_icon       [IN]        Icon for the Left softkey  
 *  right_softkey           [IN]        Right softkey label  
 *  right_softkey_icon      [IN]        Icon for the right softkey  
 *  num_of_symbols          [IN]        Number of symbols
 *  symbols                 [IN]        Symbols list
 *  descriptions            [IN]        Descriptions list
 *  highlighted_item        [IN]        Index of highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategoryEMSScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_symbols,
        MMI_ID_TYPE *symbols,
        MMI_ID_TYPE *descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, symbol_width = 0, symbol_height = 0, width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable list effect to keep the same behavior with category 22 */
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
    
    gdi_layer_lock_frame_buffer();

	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);

    wgui_fixed_matrix_create_menu(num_of_symbols, highlighted_item, WGUI_LIST_MENU_DISABLE_SHORTCUT, MMI_CATEGORY22_ID, history_buffer);
    MMI_current_menu_type = MATRIX_MENU_EMS;
    wgui_fixed_matrix_begin_add_one_item();
    for (i = 0; i < num_of_symbols; i++)
    {
        PU8 img = (PU8) get_image(symbols[i]);
        wgui_fixed_matrix_add_one_item(i, (U8*) get_string(descriptions[i]), img);
        gui_measure_image(img, &symbol_width, &symbol_height);
        if (symbol_width > width)
        {
            width = symbol_width;
        }
        if (symbol_height > height)
        {
            height = symbol_width;
        }
    }
    configure_fixed_matrix(width, height, 0, 0);
    wgui_fixed_matrix_end_add_one_item();
    
    MMI_fixed_matrix_menu.height =
        MMI_fixed_matrix_menu.n_rows * (MMI_fixed_matrix_menu.width / MMI_fixed_matrix_menu.n_columns);
    MMI_fixed_icontext_menuitem.flags |= UI_MENUITEM_FOCUSSED_ANIMATE | UI_MENUITEM_DISABLE_TEXT_DISPLAY | UI_MENUITEM_CENTER_ICON_X;

    wgui_fixed_matrix_override_highlight_handler(EMS_matrix_highlight_handler);
    MMI_fixed_matrix_menu.flags |= UI_MATRIX_MENU_LOOP;
   // h_flag = set_matrix_menu_category_history(MMI_CATEGORY22_ID, history_buffer);
    if (history_buffer)//(h_flag)
    {
        MMI_highlighted_item_text = get_item_text(MMI_fixed_matrix_menu.highlighted_item);
    }
    else
    {
        MMI_highlighted_item_text = get_item_text(highlighted_item);
    }    


    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY_EMS_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory22Screen);
    dm_register_category_controlled_callback(wgui_catEMS_draw_ctrl_area);
    dm_redraw_category_screen();
}

/*****************************************************************************
 * FUNCTION
 *  GetCategory32HistorySize
 * DESCRIPTION
 *  Get category32 history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  the size of history buffer
 *****************************************************************************/
S32 GetCategory32HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (((sizeof(list_menu_category_history) + 3) & (~3)) + sizeof(multiline_inputbox_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory32History
 * DESCRIPTION
 *  Get category32 history.
 * PARAMETERS
 *  history_buffer      [OUT]        History buffer
 * RETURNS
 *  hitsory buffer
 *****************************************************************************/
U8 *GetCategory32History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY32_ID, history_buffer);
    offset = (sizeof(list_menu_category_history) + 3) & (~3);
    wgui_inputs_ml_get_category_history(MMI_CATEGORY32_ID, (U8*)(history_buffer + offset));
    return (history_buffer);
}



/*****************************************************************************
 * FUNCTION
 *  category32_list_highlight_handler
 * DESCRIPTION
 *  high light handler of category32
 * PARAMETERS
 *  item_index      [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void category32_list_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_number(item_index + 1);
    MMI_highlighted_item_text = get_item_text(item_index);
    gdi_layer_lock_frame_buffer();
	MMI_user_highlight_handler_Ext((U8)eListhighlight, item_index);
    gdi_layer_unlock_frame_buffer();
#if(UI_ENABLE_POP_UP_DESCRIPTIONS)
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;
#endif /* (UI_ENABLE_POP_UP_DESCRIPTIONS) */ 
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat32_create_and setup_multiline_inputbox
 * DESCRIPTION
 *  create and setup multiline input box
 * PARAMETERS
 *  title                   [IN]        Title for the screen

 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat32_create_and_setup_multiline_inputbox(UI_string_type buffer, S32 buffer_len, S32 text_len, U32 flags, U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 var;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    create_multiline_inputbox_set_buffer(buffer, buffer_len, text_len, 0);
    MMI_multiline_inputbox.flags |= flags;

    if (history_buffer)
    {
        var = (sizeof(list_menu_category_history) + 3) & (~3);
        set_multiline_inputbox_category_history(MMI_CATEGORY32_ID, (U8*)(history_buffer + var));
    }
}

#define WGUI_CAT32_ANIMATION_IMAGE_X	24

/*****************************************************************************
 * FUNCTION
 *  ShowCategory32Screen
 * DESCRIPTION
 *  Displays the Dynamic menu screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  right_softkey           [IN]        Right softkey label
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  CatId                   [IN]        Category ID for Category32 or Category1049
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory32Screen_ext(
				U8 *title,
				PU8 title_icon,
				PU8 left_softkey,
				PU8 right_softkey,
				S32 number_of_items,
				U8 **list_of_items,
				PU8 *list_of_icons,
				S32 CatId,
				S32 highlighted_item,
				U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 var;
    U32 flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    
    dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    
    //TODO: why disable menu shortcut
    wgui_fixed_list_create_icontext_menu(
        number_of_items,
        highlighted_item,
        0,
        CatId,
        history_buffer);
    
    resize_fixed_list(MMI_content_width, UI_device_height - (MMI_title_height << 1) - MMI_button_bar_height);
    wgui_fixed_list_begin_add_icontext_one_item();
    for (var = 0; var < number_of_items; var++)
    {
        wgui_fixed_list_add_icontext_one_item(var, list_of_items[var], list_of_icons[var],NULL);
        if (list_of_icons[var] != UI_NULL_IMAGE)
        {
            flag = 1;
        }
    }
    wgui_fixed_list_end_add_icontext_one_item();
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    if (flag == 0)
    {
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);
    }
    
    wgui_fixed_list_override_icontext_highlight_handler(category32_list_highlight_handler);
    
    MMI_title_string = (UI_string_type) title;
    /* Maybe it is show at sub LCD screen */
    var = WGUI_CAT32_ANIMATION_IMAGE_X;
    wgui_set_animation_image(var >> 1, (MMI_title_y + MMI_title_height), (PU8) title_icon);
    
    var = gui_strlen(MMI_title_string);
    flag = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
           UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
           UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
    wgui_cat32_create_and_setup_multiline_inputbox(MMI_title_string, var, var, flag, history_buffer);
    clear_keyboard_key_handler();
    wgui_cat_setup_category(
        CatId,
        DM_CLEAR_SCREEN_BACKGROUND,
        ExitCategory32Screen,
        GetCategory32History,
        GetCategory32HistorySize);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory32Screen
 * DESCRIPTION
 *  Displays the Dynamic menu screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        Flags (see explanation below)
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory32Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    ShowCategory32Screen_ext(
            title,
            title_icon,
            left_softkey,
            right_softkey,
            number_of_items,
            list_of_items,
            list_of_icons,
            MMI_CATEGORY32_ID,
            highlighted_item,
            history_buffer);
    SetKeyHandler(multiline_inputbox_previous_line, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(multiline_inputbox_next_line, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    gdi_layer_unlock_frame_buffer();
    
    dm_redraw_category_screen();
}   /* end of ShowCategory32Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory32Screen
 * DESCRIPTION
 *  Exits the dynamic menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory32Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
#if(UI_BLINKING_CURSOR_SUPPORT)
    StopTimer(BLINKING_CURSOR);
#endif 
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
}   /* end of ExitCategory32Screen */


#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
/*****************************************************************************
 * FUNCTION
 *  ShowCategory273Screen
 * DESCRIPTION
 *  A category to display thumbnail images in menu item.
 *  * PARAMETERS
 *  *  title                IN Title for the screen
 *  *  title_icon           IN Icon shown with the title
 *  *  left_softkey         IN Left softkey label
 *  *  left_softkey_icon    IN Icon for the Left softkey
 *  *  right_softkey        IN right softkey label
 *  *  right_softkey_icon   IN Icon for the right softkey
 *  *  number_of_items      IN number of items to be displayed
 *  *  get_item_func        IN function pointer to get next displayed items
 *  *  get_display_style_func        IN function pointer to get the display style of next item
 *  *  get_properties_func                          IN      function pointer to get the properties to highlighted menu item
 *  *  highlighted_item     IN index of item to be highlighted
 *  *  history_buffer       IN history buffer
 *  *  disable_data_cache      IN whether caching of dynamic data is disabled
 *  *  flush_data_callback     IN callback function invoked before data is reloaded
 *  *
 *  * RETURNS
 *  *  void
 * PARAMETERS
 *  title                       [IN]        Title for the screen  
 *  title_icon                  [IN]        Icon shown with the title  
 *  left_softkey                [IN]        Left softkey label  
 *  left_softkey_icon           [IN]        Icon for the Left softkey  
 *  right_softkey               [IN]        Right softkey label  
 *  right_softkey_icon          [IN]        Icon for the right softkey  
 *  number_of_items             [IN]        Total count of items
 *  get_item_func               [IN]        Get item function
 *  get_display_style_func      [IN]        Get display style function
 *  get_properties_func         [IN]        Get properties function
 *  highlighted_item            [IN]        Index of highlight item
 *  history_buffer              [IN]        History Buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory273Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        wgui_get_display_style get_display_style_func,
        wgui_get_two_line_menu_item_properties get_properties_func,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_set_pfn_to_get_display_style(get_display_style_func);
    wgui_set_pfn_to_get_current_menu_item_properties(get_properties_func);
    gui_add_cleanup_hook(wgui_two_line_reset_all_pointers); /* 2 line Calvin */
    if (history_buffer)
    {
        wgui_two_line_disable_complete_callback();
    }
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        NULL,
        highlighted_item,
        MMI_FALSE,
        UI_dummy_function,
        0,
        MMI_CATEGORY273_ID,
        history_buffer);

    gdi_layer_unlock_frame_buffer();
	wgui_cat_setup_category_default_history(MMI_CATEGORY273_ID, 0, ExitCategory273Screen);
    dm_redraw_category_screen();

}   /* end of ShowCategory273Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory273Screen
 * DESCRIPTION
 *  Exits the Category 273 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory273Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
    dynamic_item_text_align_left = FALSE;
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
}
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


#ifdef __J2ME__

//extern kal_bool jui_is_show_menu; //JUI MVM
UI_filled_area *wgui_cat16_backup_filler = NULL;

UI_filled_area g_176_normal_filler =
    {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 100},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    0
};

UI_filled_area g_176_focussed_filler =
    {UI_FILLED_AREA_TYPE_COLOR,
    UI_NULL_IMAGE,
    NULL,
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {255, 255, 255, 0},
    {0, 0, 0, 0},
    0
};

/* 011507 menu Start */
/*****************************************************************************
 * FUNCTION
 *  wgui_cat176_set_jui_menu_filler
 * DESCRIPTION
 *  set jui menu filler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat176_set_jui_menu_filler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat16_backup_filler == NULL)
    {
        wgui_cat16_backup_filler = MMI_fixed_list_menu.normal_filler;
        MMI_fixed_list_menu.normal_filler = current_MMI_theme->general_background_filler;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat176_reset_jui_menu_filler
 * DESCRIPTION
 *  reset jui menu filler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat176_reset_jui_menu_filler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_cat16_backup_filler != NULL)
    {
        MMI_fixed_list_menu.normal_filler = wgui_cat16_backup_filler;
        wgui_cat16_backup_filler = NULL;
    }
}

/* 011507 menu End */


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory176Screen
 * DESCRIPTION
 *  Redraws the dynamic menu screen (For SIM Application Toolkit)
 *  Category 176 is used by java.
 *  It is modify from Category 170, and remove keypad register, scrolling title, shortcut, blt out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawCategory176Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_menuitem *m;
    gdi_handle org_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    clear_buttonbar();

    gdi_get_alpha_blending_source_layer(&org_layer_handle);
    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_set_alpha_blending_source_layer(jui_layer_handle);
        /* title bg color depends on JUI layer on PNG case */
        wgui_title_set_alpha_layer(jui_layer_handle);
    }
    wgui_softkey_set_target_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    wgui_status_icon_bar_enable_integrated(KAL_TRUE);
    wgui_status_icon_bar_register_integrated_redraw(gui_title_oem_show_normal_ex);
#endif
    draw_title();

    /* Temp solution for SQC to verify Java menu
       Will apply right solution before W0723 */
    m = (fixed_icontext_menuitem*) MMI_fixed_list_menu.common_item_data;
    m->normal_text_color = UI_COLOR_BLACK;
    m->focussed_text_color = UI_COLOR_WHITE;
    m->normal_filler = &g_176_normal_filler;
    m->focussed_filler = &g_176_focussed_filler;
    m->focussed_without_sc_filler = &g_176_focussed_filler;

    show_fixed_list();
    show_softkey_background();
    show_left_softkey();
    show_right_softkey();
    gdi_set_alpha_blending_source_layer(org_layer_handle);
    wgui_title_reset_alpha_blend_layer();
    gdi_layer_unlock_frame_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory176Screen
 * DESCRIPTION
 *  Displays the Dynamic menu screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  number_of_items         [IN]        Number of items
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        Flags (Always set to 0. Reserved for future use.)
 *  highlighted_item        [IN]        Highlighted index
 *  is_full_screen          [IN]        Is full screen or not
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory176Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U32 is_full_screen,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(flags);
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    gdi_layer_lock_frame_buffer();
    dm_add_title((UI_string_type)title, title_icon);
    wgui_text_menuitem_reset_scrolling();

    /* list create function */
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, WGUI_LIST_MENU_DISABLE_SHORTCUT | WGUI_LIST_MENU_DISABLE_KEY_HANDLE, MMI_CATEGORY176_ID, history_buffer);
    //register_menu_shortcut_handler(UI_dummy_function);
    /* rigister highlight handler as dummy */
	register_fixed_list_highlight_handler(UI_dummy_function_s32);

    /* Softkeys */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);

    /* List */
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 

    for (i = 0; i < number_of_items; i++)
    {
        if (list_of_icons[i] != UI_NULL_IMAGE)
        {
            flag = 1;
        }
    }

    wgui_fixed_list_move_icontext_menu(0, MMI_title_height);
    if(is_full_screen)
    {
        wgui_fixed_list_resize_icontext_menu(MMI_content_width, UI_device_height-MMI_title_height-MMI_button_bar_height);
    }
    else
    {
        wgui_fixed_list_resize_icontext_menu(MMI_content_width, MMI_content_height);
    }

    resize_fixed_icontext_menuitems(0, MMI_ICONTEXT_MENUITEM_HEIGHT);
    if (flag)
    {
        //set_fixed_icontext_positions(MMI_MENUITEM_HEIGHT + 2, 0, 1, 0);
    }
    else
    {
        set_fixed_icontext_positions(GUI_TEXT_MENUITEM_TEXT_X, 0, 1, 0);
        //MMI_fixed_icontext_menuitem.scroll_width = MMI_fixed_icontext_menuitem.width - 2;
    }

    wgui_fixed_list_add_icontext_items(list_of_items, list_of_icons, NULL);

    gui_set_multilayer_mask(gui_get_multilayer_mask() & ~UI_MUL_BKG_SUBMENU);
    gui_set_multilayer_mask(gui_get_multilayer_mask() & ~UI_MUL_BKG_MAINMENU);

    gdi_layer_unlock_frame_buffer();
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
    MMI_fixed_list_menu.act_layer_handle = jui_layer_handle;

    SetListScreenFunctions(MMI_CATEGORY176_ID);
    RedrawCategoryFunction = RedrawCategory176Screen;
    ExitCategoryFunction = ExitCategory176Screen;
    RedrawCategoryFunction();
    //jui_is_show_menu = KAL_TRUE;      //JUI MVM

}   /* end of ShowCategory176Screen */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory176Screen
 * DESCRIPTION
 *  Exits the dynamic menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory176Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    close_scrolling_title();
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    MMI_fixed_list_menu.act_lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
    MMI_fixed_list_menu.act_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    //jui_is_show_menu = KAL_FALSE; //JUI MVM
}
#endif /* __J2ME__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitCategory626Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory626Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }

    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_pop_up_descriptions();

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory626Screen
 * DESCRIPTION
 *  Displays the category626 screen (Tab List menu with description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items               [IN]        Array of items
 *  list_of_icons               [IN]        Array of icons
 *  list_of_descriptions        [IN]        Array of Pop up description strings
 *  flags                       [IN]        Flags (see explanation below)
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  n_tabs                  [IN]
 *  highlighted_tab         [IN]
 *  tab_items               [IN]
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory626Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        S8 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S8 n_tabs = 0;
    U16 catId;
    S32 list_height = MMI_CONTENT_HEIGHT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_lock_frame_buffer();

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;

    if (n_tabs)
    {
        catId = MMI_CATEGORY626_ID;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
    }
    else
    {
        dm_add_title((UI_string_type)title, get_image(title_icon));
        catId = MMI_CATEGORY626_NO_TAB_ID;
    }

    /* Softkeys */
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    /* Show List */
    wgui_fixed_list_create_icontext_menu(number_of_items, highlighted_item, 0, catId, history_buffer);
    
    wgui_fixed_list_begin_add_icontext_one_item();

    if (list_of_descriptions == NULL)
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]), NULL);
        }
    }
    else
    {
        for (i = 0; i < number_of_items; i++)
        {
            wgui_fixed_list_add_icontext_one_item(i, list_of_items[i], wgui_get_list_menu_icon(i, list_of_icons[i]), list_of_descriptions[i]);

        }
    }
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    wgui_cat_set_hint_in_menuitem(list_of_descriptions, number_of_items);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */

    wgui_fixed_list_end_add_icontext_one_item();

    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_fixed_list_move_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
        wgui_fixed_list_move_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        wgui_fixed_list_resize_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);
    }
    else
    {
        wgui_fixed_list_move_icontext_menu(MMI_CONTENT_X, MMI_CONTENT_Y);
        wgui_fixed_list_resize_icontext_menu(MMI_CONTENT_WIDTH, list_height);
    }

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history((S32)catId, 0, ExitCategory626Screen);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory627Screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory627Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }

    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_fixed_list();
    reset_pop_up_descriptions();
}

extern void wgui_setup_horizontal_tab_bar_no_title_shortcut(void);
/*****************************************************************************
 * FUNCTION
 *  ShowCategory627Screen
 * DESCRIPTION
 *  Displays the category627 screen (Tab List menu without description )
 * PARAMETERS
 *  title                       [IN]        Title for the screen
 *  title_icon                  [IN]        Icon displayed with the title
 *  left_softkey                [IN]        Left softkey label
 *  left_softkey_icon           [IN]        Left softkey icon
 *  right_softkey               [IN]        Right softkey label
 *  right_softkey_icon          [IN]        Right softkey icon
 *  number_of_items             [IN]        Number of items in the menu
 *  list_of_items1              [IN]        Array of items1
 *  list_of_items2              [IN]        Array of items2
 *  list_of_icons               [IN]        Array of icons
 *  highlighted_item            [IN]        Default item to be highlighted (if there is no history)
 *  highlighted_tab             [IN]        
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory627Screen(
        UI_string_type  title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items1,
        U8 **list_of_items2,
        U16 *list_of_icons,
        S32 highlighted_item,
        S8 highlighted_tab,
        U8 *history_buffer)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, w1, h1, text_width, text_width1, font_height;
    S8 n_tabs = 0;
    PU8 img;
    U16 catId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
    if (n_tabs)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        catId = MMI_CATEGORY627_ID;
#else
        if(title == NULL)
        {
            wgui_create_horizontal_tab_bar(FALSE, NULL, n_tabs, highlighted_tab, MMI_FALSE);
            wgui_setup_horizontal_tab_bar_no_title_shortcut();
            catId = MMI_CATEGORY627_ID;
        }
        else
        {
            wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
            catId = MMI_CATEGORY626_ID;
        }  
#endif
    }
    else
    {
        dm_add_title((UI_string_type)title, title_icon);
        catId = MMI_CATEGORY626_NO_TAB_ID;
    }
    
    if(catId == MMI_CATEGORY626_ID)
    {
        wgui_fixed_list_move_twostate_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
        wgui_fixed_list_resize_twostate_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB);
    }
    if(catId == MMI_CATEGORY627_ID)
    {
        wgui_fixed_list_move_twostate_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        wgui_fixed_list_resize_twostate_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB  + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
    }
    if(catId == MMI_CATEGORY626_NO_TAB_ID)
    {
        wgui_fixed_list_move_twostate_menu(MMI_CONTENT_X, MMI_CONTENT_Y);
        wgui_fixed_list_resize_twostate_menu(MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT);
    }
		
    
    /* Softkeys */
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_fixed_list_create_multi_icontext_menu(
        1,
        2,
        number_of_items,
        highlighted_item,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        catId,
        history_buffer);
    
    if (n_tabs)
    {
        resize_fixed_icontext_list_menuitems(0, CAT627_MENUITEM_HEIGHT);
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;            
        MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler; //menuitem_thick_with_tab_highlight_without_scroll_filler       
    }

    img = get_image(list_of_icons[0]);
    gui_measure_image(img, &w1, &h1);

    text_width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_ICON_X - GUI_MENUITEM_TEXT_RIGHT_GAP;
    text_width1 = UI_device_width - MMI_fixed_list_menu.vbar.width - w1 - 2*GUI_ICONTEXT_MENUITEM_ICON_X - GUI_MENUITEM_TEXT_RIGHT_GAP;

    /* It may contain non-alphanumeric characters like Chinese */
	font_height = Get_CharHeightOfAllLang(MEDIUM_FONT);
    if(h1 < font_height)
	{
	    h1 = font_height;
	}
    
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, (n_tabs ? CAT627_MENUITEM_HEIGHT : MMI_MULTIROW_MENUITEM_HEIGHT) - h1 - 2, w1, h1);
    set_fixed_icontext_list_text_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, CAT627_TOP_GAP, text_width, (n_tabs ? CAT627_MENUITEM_HEIGHT : MMI_MULTIROW_MENUITEM_HEIGHT) - h1 - 1);
    set_fixed_icontext_list_text_coordinates(1, GUI_ICONTEXT_MENUITEM_ICON_X*2 + w1,  (n_tabs ? CAT627_MENUITEM_HEIGHT : MMI_MULTIROW_MENUITEM_HEIGHT) - h1 - CAT627_TOP_GAP, text_width1, h1);

    /* text0 is small font, text1 is medium font */
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_default_font;
    
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;

    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[2];
        U8 *icon[1];
        items[0] = list_of_items1[i];
        items[1] = list_of_items2[i];
        icon[0] = get_image(list_of_icons[i]);
        wgui_fixed_list_add_multi_icontext_one_item(i, items, icon, NULL);
    }
    wgui_fixed_list_end_add_multi_icontext_one_item();

    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history((S32)catId, 0, ExitCategory627Screen);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  DrawCate628CategoryControlAreaBackground
 * DESCRIPTION
 *  draw the information message for category 628
 * PARAMETERS
 *  coordinate      [IN] Coordinated of the control area     
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate628CategoryControlAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y11, y22;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y11 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT;
    y22 = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - 1;

	  gui_push_clip();
	  gui_reset_clip();
    gui_set_clip(x1, y11, x2, y22);

#ifdef __MMI_MAINLCD_128X128__
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_WHITE);
#else /* __MMI_MAINLCD_128X128__ */
    gdi_draw_solid_rect(
        x1, y11, x2, y22,
        GDI_COLOR_TRANSPARENT);
#endif /* __MMI_MAINLCD_128X128__ */
	  gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory628Screen
 * DESCRIPTION
 *  exit category 628
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory628Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    // gui_unblock_list_effect();
#endif
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory628Screen
 * DESCRIPTION
 *  Dynamic List menu category with checkbox and tab support
 * PARAMETERS
 *  title                   [IN] Char array of title
 *  title_icon              [IN] Byte array of title icon
 *  left_softkey            [IN] String ID of left softkey
 *  left_softkey_icon       [IN] Image ID of left softkey icon
 *  right_softkey           [IN] String ID of right softkey
 *  right_softkey_icon      [IN] Image ID of right softkey icon
 *  info_message            [IN] Char array of information message
 *  number_of_items         [IN] Number of items of list
 *  get_item_func           [IN] Get item function pointer
 *  get_hint_func           [IN] Get hint function pointer
 *  get_state_func          [IN] Get state of check-box function pointer
 *  set_state_func          [IN] Set state of check-box function pointer
 *  highlighted_item        [IN] Currently highlighted item
 *  history_buffer          [IN] History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory628Screen(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8* info_message,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 highlighted_item,
        S32 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 h_flag = 0;
    S8 n_tabs = 0;    
    S32 scroll_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    // gui_block_list_effect();
#endif

    gdi_layer_lock_frame_buffer();

	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    wgui_title_set_no_icon_shct(MMI_TRUE);

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
#if (defined(__MMI_FTE_SUPPORT__) && (__MMI_MAINLCD_320X240__))
    wgui_create_horizontal_tab_bar(FALSE, title, n_tabs, highlighted_tab, MMI_FALSE);
    wgui_setup_horizontal_tab_bar_no_title_shortcut();
#else
    wgui_create_horizontal_tab_bar(TRUE, title, n_tabs, highlighted_tab, MMI_FALSE);
#endif
    /* initialize list */
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

    h_flag = set_list_menu_category_history(MMI_CATEGORY628_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
    /* adjust list */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_positions(
		GUI_ICONTEXT_MENUITEM_TEXT_X + MMI_ICONTEXT_MENUITEM_HEIGHT, 0, 
		GUI_ICONTEXT_MENUITEM_ICON_X + MMI_ICONTEXT_MENUITEM_HEIGHT, 0);

    /* set check-box */
    wgui_menuitem_set_icontext_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_checkbox_callback(set_state_func, get_state_func);


    /* set the layout of the list */
    if (info_message != NULL)
    {
        dm_add_scroll_text(
            (UI_string_type)info_message,
            NULL,
            DrawCate628CategoryControlAreaBackground,
#ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
#else /* __MMI_MAINLCD_128X128__ */
		    *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
#endif /* __MMI_MAINLCD_128X128__ */
		    );
        scroll_height = MMI_MENUITEM_HEIGHT;
    }
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
    wgui_dynamic_list_move_icontext_menu(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
    wgui_dynamic_list_resize_icontext_menu(MMI_CONTENT_WIDTH_WITH_H_TAB, MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - scroll_height);
#else
    wgui_dynamic_list_move_icontext_menu(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB);
    wgui_dynamic_list_resize_icontext_menu(MMI_CONTENT_WIDTH_WITH_H_TAB, MMI_CONTENT_HEIGHT_WITH_H_TAB - scroll_height);
#endif
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY628_ID, DM_CLEAR_SCREEN_BACKGROUND, ExitCategory628Screen);
    /* redraw category screen */
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory629Screen
 * DESCRIPTION
 *  exit category 629
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory629Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    dynamic_item_text_align_left = FALSE;
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();    
}


void wgui_cat629_set_text_align_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_text_align_left = TRUE;
}


static void wgui_cat629_stop_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_stop_list_menuitem_scrolling();
}


static void wgui_cat629_resume_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

    gdi_layer_lock_frame_buffer();
    show_dynamic_list();
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(MMI_fixed_list_menu.x, MMI_fixed_list_menu.y, MMI_fixed_list_menu.width - 1, MMI_fixed_list_menu.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory629Screen
 * DESCRIPTION
 *  Dynamic List menu category with tab support
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  number_of_items         [IN]        Number of items to be displayed
 *  get_item_func           [IN]        Function pointer to get next displayed items
 *  get_hint_func           [IN]        Function pointer to get next displayed hint data
 *  highlighted_item        [IN]        Index of item to be highlighted
 *  highlighted_tab         [IN]        Currently highlighted tab page
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory629Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        S32 highlighted_tab,        
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;    
    S32 list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
    U8 h_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_lock_frame_buffer();

	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    wgui_title_set_no_icon_shct(MMI_TRUE);

    /* Show Tab bars */
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
    wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)GetString(title), n_tabs, highlighted_tab, MMI_FALSE);
    wgui_setup_horizontal_tab_bar_no_title_shortcut();
    list_height += MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
    wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)GetString(title), n_tabs, highlighted_tab, MMI_FALSE);
#endif
    wgui_dynamic_list_create_icontext_menu(
        number_of_items,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/    
    h_flag = set_list_menu_category_history(MMI_CATEGORY629_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
#if (defined(__MMI_FTE_SUPPORT__) && (__MMI_MAINLCD_320X240__))
    wgui_dynamic_list_move_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
    wgui_dynamic_list_move_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
    wgui_dynamic_list_resize_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);
    dynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);

    wgui_icon_bar_register_pause_interactive_UI_callback(wgui_cat629_stop_scroll);
    wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat629_resume_scroll);
    gdi_layer_unlock_frame_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY629_ID, 0, ExitCategory629Screen);
    dm_redraw_category_screen();

}


#define MMI_CAT1006_TAB_CONTENT_HEIGHT (MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
static wgui_cat1006_get_image_path mmi_cat1006_get_img_path = NULL;
static wgui_cat1006_get_image_id mmi_cat1006_get_img_id = NULL;

static void wgui_cat1006_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    dynamic_item_text_align_left = FALSE;
    mmi_cat1006_get_img_path = NULL;
    mmi_cat1006_get_img_id = NULL;
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
}

static MMI_BOOL wgui_caculate_width_and_height(S32 *width, S32 *height, S32 menu_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w = *width;
    h = *height;

    if((w <= 0 || h <= 0) || (menu_height <= 0))
    {
        return MMI_FALSE;
    }

    if(w >= h)
    {
        if(w + 3 > menu_height)
        {
            w = menu_height - 4;
            h = w*h/(*width);
        }
    }
    else
    {
        if(h + 3 > menu_height)
        {
            h = menu_height - 4;
            w = w*h/(*height);
        }
    }

    *width = w;
    *height = h;

    return MMI_TRUE;
}


static void wgui_cat1006_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd, layers[4];
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    S32 x2, y2, item_index;
    S32 img_width, img_height;
    S32 img_id = -1;
    MMI_BOOL alpha = MMI_FALSE;
    CHAR imagepath[SRV_FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    x2 = x + m->width - 1;
    y2 = y + m->height - 1;
    /*this is used to set clip area*/
    if(y2 > MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1)
    {
        y2 = MMI_fixed_list_menu.y + MMI_fixed_list_menu.height - 1;
    }

    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);

    gui_push_clip();
    gui_set_clip(x, y, x2, y2);

    gdi_layer_get_active(&act_lcd);
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }
    
    if(MMI_fixed_list_menu.highlighted_item == item_index)
    {
        alpha = MMI_TRUE;
        gdi_push_and_set_alpha_blending_source_layer(act_lcd);
    }

    if(mmi_cat1006_get_img_path != NULL)
    {
        mmi_cat1006_get_img_path(item_index, (WCHAR*)imagepath);
        gdi_image_get_dimension_file((S8*) imagepath, &img_width, &img_height);
        wgui_caculate_width_and_height(&img_width, &img_height, MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);
        if (mmi_fe_get_r2l_state())
        {
            x = x2 - ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT + img_width) >> 1);
        }
        else
        {
            x += ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - img_width) >> 1);
        }
        y += ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - img_height) >> 1);
        gdi_image_draw_resized_file(x, y, img_width, img_height, (PS8)imagepath);
    }
    else
    {
        if(mmi_cat1006_get_img_id == NULL)
        {
            MMI_ASSERT(MMI_FALSE);
        }
        mmi_cat1006_get_img_id(item_index, &img_id);
        gdi_image_get_dimension_id(img_id, &img_width, &img_height);
        wgui_caculate_width_and_height(&img_width, &img_height, MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);

        if (mmi_fe_get_r2l_state())
        {
            x = x2 - ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT + img_width) >> 1);
        }
        else
        {
            x += ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - img_width) >> 1);
        }
        y += ((MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - img_height) >> 1);
        gdi_image_draw_resized_id(x, y, img_width, img_height, img_id);
    }
    
    if(alpha)
    {
        gdi_pop_and_restore_alpha_blending_source_layer();
    }
    gui_pop_clip();
}

void wgui_cat1006_show(
         WCHAR *title,
         PU8 title_icon,
         WCHAR *left_softkey,
         PU8 left_softkey_icon,
         WCHAR *right_softkey,
         PU8 right_softkey_icon,
         S32 number_of_items,
         GetAsyncItemFuncPtr get_item_func,
         GetAsyncHintFuncPtr get_hint_func,
         wgui_cat1006_get_image_path get_img_path_func,
         wgui_cat1006_get_image_id get_img_id_func,
         PU8 list_icon[3],
         S32 number_of_string,
         S32 number_of_icon,
         S32 highlighted_item,
         S32 highlighted_tab,
         U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width[3], icon_width[3], icon_height[3];
    S32 icon_x = 0;
    S8 n_tabs = 0;
    S32 scrollBar_w = 0;
    S32 list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_SLIDE_EFFECT__
    gui_block_list_effect();
#endif /* __MMI_UI_LIST_SLIDE_EFFECT__ */
    gdi_layer_lock_frame_buffer();
    gui_asyncdynamic_list_error = 0;
    mmi_cat1006_get_img_path = get_img_path_func;
    mmi_cat1006_get_img_id = get_img_id_func;

	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    wgui_title_set_no_icon_shct(MMI_TRUE);

    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
    wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
    list_height += MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
    wgui_setup_horizontal_tab_bar_no_title_shortcut();
#else
    wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
#endif
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        number_of_string,
        number_of_icon,
        get_item_func,
        get_hint_func,
        highlighted_item,
        MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
        0,
        MMI_CAT1006_ID,
        history_buffer);
    set_fixed_icontext_list_menuitems_post_display(wgui_cat1006_post_display_menuitem);
    
#if defined(__MMI_MAINLCD_320X480__)
    if((MMI_CAT1006_TAB_CONTENT_HEIGHT/MMI_MENUITEM_THICK_WITH_TAB_HEIGHT) >= number_of_items)
    {
        scrollBar_w = 2;
    }
    else
#endif /* __MMI_MAINLCD_320X480__ */
    {
        scrollBar_w = MMI_fixed_list_menu.vbar.width;
    }

    gdi_image_get_dimension(list_icon[0], &icon_width[0], &icon_height[0]);  
    text_width[0] = UI_device_width - /*GUI_ICONTEXT_MENUITEM_TEXT_X*/MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - icon_width[0] - GUI_MENUITEM_TEXT_RIGHT_GAP - scrollBar_w - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
    text_width[1] = (UI_device_width - /*GUI_ICONTEXT_MENUITEM_TEXT_X*/MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - scrollBar_w - GUI_MENUITEM_TEXT_RIGHT_GAP)>>1;
    switch(number_of_icon)
    {
        case 1:  
            if(number_of_string == 1) /* there is only have one string for each menuitem */
            {
                set_fixed_icontext_list_icon_coordinates(
                    0,
                    UI_device_width - scrollBar_w - GUI_MENUITEM_TEXT_RIGHT_GAP - icon_width[0],
                    0,
                    icon_width[0],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);

                set_fixed_icontext_list_text_coordinates(
                    0,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    0,
                    text_width[0],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);
            }
            else if(number_of_string == 3)/* there are there strings for each menuitem */
            {
                text_width[1] = (UI_device_width - MMI_MENUITEM_THICK_WITH_TAB_HEIGHT - scrollBar_w - GUI_MENUITEM_TEXT_RIGHT_GAP)>>1;
                set_fixed_icontext_list_icon_coordinates(
                    0,
                    UI_device_width - scrollBar_w - GUI_MENUITEM_TEXT_RIGHT_GAP - icon_width[0],
                    2,
                    icon_width[0],
                    icon_height[0]);

                set_fixed_icontext_list_text_coordinates(
                    0,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    0,
                    text_width[0],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
                set_fixed_icontext_list_text_coordinates(
                    2,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1),
                    text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
                set_fixed_icontext_list_text_coordinates(
                    1,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT + text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1),
                    text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
            }
            else /* it will assert if string number is not 1 or 3 */
            {
                MMI_ASSERT(MMI_FALSE);
            }

            break;

        case 3:
            gdi_image_get_dimension(list_icon[1], &icon_width[1], &icon_height[1]);
            gdi_image_get_dimension(list_icon[2], &icon_width[2], &icon_height[2]);

            text_width[0] = text_width[0] - icon_width[1] - icon_width[2] - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
            icon_x = UI_device_width - scrollBar_w - GUI_MENUITEM_TEXT_RIGHT_GAP - icon_width[0];
            if(number_of_string == 1)
            {
                set_fixed_icontext_list_icon_coordinates(
                    0,
                    icon_x,
                    0,
                    icon_width[0],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);
                set_fixed_icontext_list_icon_coordinates(
                    1,
                    icon_x - icon_width[1] - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
                    0,
                    icon_width[1],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);
                set_fixed_icontext_list_icon_coordinates(
                    2,
                    icon_x - icon_width[1] - (GUI_MENUITEM_X1_GAP<<1) - GUI_MENUITEM_X2_GAP - icon_width[2],
                    0,
                    icon_width[2],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);

                set_fixed_icontext_list_text_coordinates(
                    0,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    0,
                    text_width[0],
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT);

            }
            else if(number_of_string == 3)
            {
                set_fixed_icontext_list_icon_coordinates(
                    0,
                    icon_x,
                    2,
                    icon_width[0],
                    icon_height[0]);
                set_fixed_icontext_list_icon_coordinates(
                    1,
                    icon_x - icon_width[1] - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP,
                    0,
                    icon_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
                set_fixed_icontext_list_icon_coordinates(
                    2,
                    icon_x - icon_width[1] - (GUI_MENUITEM_X1_GAP<<1) - GUI_MENUITEM_X2_GAP - icon_width[2],
                    0,
                    icon_width[2],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));

                set_fixed_icontext_list_text_coordinates(
                    0,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    0,
                    text_width[0],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
                set_fixed_icontext_list_text_coordinates(
                    2,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT,
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1),
                    text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
                set_fixed_icontext_list_text_coordinates(
                    1,
                    MMI_MENUITEM_THICK_WITH_TAB_HEIGHT + text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1),
                    text_width[1],
                    (MMI_MENUITEM_THICK_WITH_TAB_HEIGHT>>1));
            }
            else
            {
                MMI_ASSERT(MMI_FALSE);
            }
            break;

        default:
        {
            MMI_ASSERT(MMI_FALSE);
        }
    }

    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY_COL2 | UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER | UI_MENUITEM_AUTO_CHOOSE_MARQUEE | UI_MENUITEM_CENTER_ICON_Y | UI_MENUITEM_CENTER_TEXT_Y;
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_medium_font;
    MMI_fixed_icontext_list_menuitem.text_fonts[2] = &MMI_small_font;
	MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;

    MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;
    MMI_fixed_icontext_list_menuitem.focussed_without_sc_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;//menuitem_thick_with_tab_highlight_without_scroll_filler
    MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_thick_with_tab_highlight_filler;

#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
    wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
    wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
    wgui_async_list_resize_multi_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);

	wgui_cat_setup_category_default_history(MMI_CAT1006_ID, 0, wgui_cat1006_exit);
    dm_redraw_category_screen();

    gdi_layer_unlock_frame_buffer();

    if(gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH - 1, MAIN_LCD_DEVICE_HEIGHT - 1);
}

/***************************************************************************** 
 * Category 426
 *****************************************************************************/
#ifndef __MMI_MAINLCD_128X128__

#define WGUI_CAT426_THUMBNAIL_BUFFER_SIZE           10  /* for non-blocking decoder */

typedef enum
{
    WGUI_CAT426_CACHE_ITEM_EMPTY = 0,
    WGUI_CAT426_CACHE_ITEM_USED,
    WGUI_CAT426_CACHE_ITEM_QUEUED,

    WGUI_CAT426_CACHE_ITEM_TYPE_END
} WGUI_CAT426_CACHE_ITEM_TYPE;

typedef struct 
{
    S32 thumbnail_x1;
    S32 thumbnail_y1;
    S32 thumbnail_x2;    
    S32 thumbnail_y2;    
    S32 check_box_x1;
    S32 check_box_y1;
    S32 check_box_x2;
    S32 check_box_y2;
    MMI_ID_TYPE checkbox_on_icon;
    MMI_ID_TYPE checkbox_off_icon;
    U8 *checkbox_values;
    wgui_cat426_thumbnail_callback_type thumbnail_callback;
    GDI_HANDLE icon_handle[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_x1[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_y1[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_x2[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_y2[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_cb_x1[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_cb_y1[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_cb_x2[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 icon_cb_y2[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    U16 default_image_id[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    U8 on_off_value[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 buffer_cache_map[WGUI_CAT426_THUMBNAIL_BUFFER_SIZE];
    S32 cache_size;
    S32 cache_current_index;
    S32 *cache_index;
    S32 *cache_x;
    WGUI_CAT426_CACHE_ITEM_TYPE *cache_check;
    U8* cache_buffer;
    GDI_HANDLE cache_handle;
} wgui_cat426_context_struct;

/* Context of category 426 */
static wgui_cat426_context_struct *g_wgui_cat426_p;
static wgui_cat426_cb_value_callback_type g_wgui_cat426_cbv_cb = NULL;


/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_show_check_box
 * DESCRIPTION
 *  show check-box of thumbnail
 * PARAMETERS
 *  x1
 *  y1
 *  x2
 *  y2
 *  on_off_value
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat426_show_check_box(S32 x1, S32 y1, S32 x2, S32 y2, U8 on_off_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    gui_show_transparent_image(
            x1,
            y1,
            get_image((MMI_ID_TYPE) (on_off_value ? g_wgui_cat426_p->checkbox_on_icon : g_wgui_cat426_p->checkbox_off_icon)),
            UI_DEFAULT_TRANSPARENT_COLOR);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_show_default_thumbnail_image
 * DESCRIPTION
 *  show thumbnail image
 * PARAMETERS
 *  x1
 *  y1
 *  x2
 *  y2
 *  image ID
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat426_show_thumbnail_image(S32 x1, S32 y1, S32 x2, S32 y2, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width = 0, image_height = 0;
    S32 resized_offset_x = 0, resized_offset_y = 0;
    S32 resized_width = 0, resized_height = 0;
    S32 box_width = (x2 - x1 + 1), box_height = (y2 - y1 + 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_image_get_dimension_id(image_id, &image_width, &image_height);

    if ((image_width >= box_width) || (image_height >= box_height))
    {
        gdi_image_util_fit_bbox(
                (x2 - x1 + 1),
                (y2 - y1 + 1),
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

        resized_width = (resized_width == 0) ? 1 : resized_width;
        resized_height = (resized_height == 0) ? 1 : resized_height;
    }
    else
    {
        resized_offset_x = ((box_width - image_width) >> 1);
        resized_offset_y = ((box_height - image_height) >> 1);
        resized_width = image_width;
        resized_height = image_height;
    }

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    gdi_image_draw_resized_id(
            x1 + resized_offset_x,
            y1 + resized_offset_y,
            resized_width,
            resized_height,
            image_id);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_nb_display_callback
 * DESCRIPTION
 *  Customized display callback after non-block image display
 * PARAMETERS
 *  result
 *  handle
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat426_nb_display_callback(GDI_RESULT result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* GDI non-blocking decoder cannot stop while decoding,
     * so we have to check whether this callback is valid or not. */
    if (g_wgui_cat426_p == NULL)
    {
        return;
    }

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_lock_frame_buffer();

    for (i = 0; i < WGUI_CAT426_THUMBNAIL_BUFFER_SIZE; i++)
    {
        if (handle == g_wgui_cat426_p->icon_handle[i])
        {
            if (result == GDI_SUCCEED)
            {
                /* if cache, draw from cache */
                if (g_wgui_cat426_p->cache_buffer != NULL)
                {
                    S32 cache_ind = g_wgui_cat426_p->buffer_cache_map[i];
                    S32 cache_x = g_wgui_cat426_p->cache_x[cache_ind];
                    S32 x1 = g_wgui_cat426_p->icon_x1[i];
                    S32 y1 = g_wgui_cat426_p->icon_y1[i];
                    S32 x2 = g_wgui_cat426_p->icon_x2[i];
                    S32 y2 = g_wgui_cat426_p->icon_y2[i];

                    /* draw cache */
                    gd_bitblt[gdi_act_layer->cf](
                            gdi_act_layer->buf_ptr,
                            gdi_act_layer->width, gdi_act_layer->height,
                            x1, y1, x2, y2,
                            g_wgui_cat426_p->cache_buffer,
                            WGUI_CAT426_IMAGE_WIDTH*g_wgui_cat426_p->cache_size, WGUI_CAT426_IMAGE_HEIGHT,
                            cache_x, 0, cache_x + WGUI_CAT426_IMAGE_WIDTH, WGUI_CAT426_IMAGE_HEIGHT,
                            x1, y1, x2, y2,
                            0x01FFFFFF, 0x01FFFFFF);

                    g_wgui_cat426_p->cache_check[cache_ind] = WGUI_CAT426_CACHE_ITEM_USED;
                }
            }
            else
            {
                /* clean cache */
                if (g_wgui_cat426_p->cache_buffer != NULL)
                {
                    S32 cache_ind = g_wgui_cat426_p->buffer_cache_map[i];

                    g_wgui_cat426_p->cache_index[cache_ind] = -1;
                    g_wgui_cat426_p->cache_check[cache_ind] = WGUI_CAT426_CACHE_ITEM_EMPTY;
                }

                wgui_cat426_show_thumbnail_image(
                        g_wgui_cat426_p->icon_x1[i],
                        g_wgui_cat426_p->icon_y1[i],
                        g_wgui_cat426_p->icon_x1[i] + WGUI_CAT426_IMAGE_WIDTH - 1,
                        g_wgui_cat426_p->icon_y1[i] + WGUI_CAT426_IMAGE_HEIGHT - 1,
                        g_wgui_cat426_p->default_image_id[i]);
            }

            gui_draw_rectangle(
                        g_wgui_cat426_p->icon_x1[i] - 1,
                        g_wgui_cat426_p->icon_y1[i] - 1,
                        g_wgui_cat426_p->icon_x2[i] + 1,
                        g_wgui_cat426_p->icon_y2[i] + 1,
                        gui_color(0, 0, 0));

            wgui_cat426_show_check_box(
                    g_wgui_cat426_p->icon_cb_x1[i],
                    g_wgui_cat426_p->icon_cb_y1[i],
                    g_wgui_cat426_p->icon_cb_x2[i],
                    g_wgui_cat426_p->icon_cb_y2[i],
                    g_wgui_cat426_p->on_off_value[i]);
            
            //gdi_image_nb_stop(g_wgui_cat426_p->icon_handle[i]);
            g_wgui_cat426_p->icon_handle[i] = GDI_NULL_HANDLE;

            break;
        }
    }

    gdi_layer_unlock_frame_buffer();

    gdi_lcd_repaint_all();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_pre_display_callback
 * DESCRIPTION
 *  Customized display callback for each icontext-list menu item in Category 426
 * PARAMETERS
 *  item                [IN/OUT]
 *  common_item_data    [IN/OUT]
 *  x                   [IN]
 *  y                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat426_pre_display_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WGUI_CAT426_THUMBNAIL_BUFFER_SIZE; i++)
    {
        if (g_wgui_cat426_p->icon_handle[i] != GDI_NULL_HANDLE)
        {
            if (g_wgui_cat426_p->cache_buffer != NULL)
            {
                S32 cache_ind = g_wgui_cat426_p->buffer_cache_map[i];

                g_wgui_cat426_p->cache_index[cache_ind] = -1;
                g_wgui_cat426_p->cache_check[cache_ind] = WGUI_CAT426_CACHE_ITEM_EMPTY;
            }
            gdi_image_nb_stop(g_wgui_cat426_p->icon_handle[i]);
            g_wgui_cat426_p->icon_handle[i] = GDI_NULL_HANDLE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_post_display_callback
 * DESCRIPTION
 *  Customized display callback for each icontext-list menu item in Category 426
 * PARAMETERS
 *  item                [IN/OUT]
 *  common_item_data    [IN/OUT]
 *  x                   [IN]
 *  y                   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat426_post_display_callback(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    //fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    S32 x1, y1, x2, y2, buffer_ind = 0, cache_ind = 0;
    S32 right_x;
    U8 on_off_value;
    S32 index;
    U8 thumbnail_filename[(SRV_FMGR_PATH_MAX_LEN + 1)*ENCODING_LENGTH];
    MMI_BOOL draw_by_cache = MMI_FALSE;
    U16 default_image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_wgui_cat426_p);

    right_x = x + m->width - 1;

    /* get thumbnail image file name */
    index = MMI_fixed_list_menu.current_displayed_item;
    if (index == -1)
    {
        index = wgui_title_get_menu_shortcut_number() - 1;
    }
    if (g_wgui_cat426_p->thumbnail_callback != NULL)
    {
        g_wgui_cat426_p->thumbnail_callback(
                index,
                thumbnail_filename,
                (SRV_FMGR_PATH_MAX_LEN + 1)*ENCODING_LENGTH,
                &default_image_id);
    }
    else
    {
        return ;
    }

    /* 
     * [Note] Icontext-list menu item can handle r2lMMIFlag by adjusting icon/text position.
     *
     * We need to change the icon text position here because we do not use standard GUI components 
     * in this callback.
     */

    /* Show thumbnail */
    if (mmi_fe_get_r2l_state())
    {
        x1 = right_x - g_wgui_cat426_p->thumbnail_x2;
        x2 = right_x - g_wgui_cat426_p->thumbnail_x1;
    }
    else
    {
        x1 = x + g_wgui_cat426_p->thumbnail_x1;
        x2 = x + g_wgui_cat426_p->thumbnail_x2;
    }
    y1 = y + g_wgui_cat426_p->thumbnail_y1;    
    y2 = y + g_wgui_cat426_p->thumbnail_y2;

    gui_push_clip();

    gui_set_clip(x1 - 1, y1 - 1, x2 + 1, y2 + 1);

    /* check cache */
    if (g_wgui_cat426_p->cache_buffer != NULL)
    {
        for (cache_ind = 0; cache_ind < g_wgui_cat426_p->cache_size; cache_ind ++)
        {
            if (g_wgui_cat426_p->cache_index[cache_ind] == index)
            {
                if (g_wgui_cat426_p->cache_check[cache_ind] == WGUI_CAT426_CACHE_ITEM_USED)
                {
                    S32 cache_x = g_wgui_cat426_p->cache_x[cache_ind];

                    /* draw cache */
                    gd_bitblt[gdi_act_layer->cf](
                            gdi_act_layer->buf_ptr,
                            gdi_act_layer->width, gdi_act_layer->height,
                            x1, y1, x2, y2,
                            g_wgui_cat426_p->cache_buffer,
                            WGUI_CAT426_IMAGE_WIDTH*g_wgui_cat426_p->cache_size, WGUI_CAT426_IMAGE_HEIGHT,
                            cache_x, 0, cache_x + WGUI_CAT426_IMAGE_WIDTH, WGUI_CAT426_IMAGE_HEIGHT,
                            x1, y1, x2, y2,
                            0x01FFFFFF, 0x01FFFFFF);
                }
                else
                {
                    /* draw default image */
                    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
                    wgui_cat426_show_thumbnail_image(x1, y1, x2, y2, default_image_id);
                }

                draw_by_cache = MMI_TRUE;

                break;
            }
        }
    }

    /* non_blocking decoder */
    if (draw_by_cache == MMI_FALSE)
    {
        S32 image_width = 0, image_height = 0;
        GDI_RESULT ret;

        /* draw default image */
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_WHITE);
        wgui_cat426_show_thumbnail_image(x1, y1, x2, y2, default_image_id);

        ret = gdi_image_get_dimension_file(
                (S8*)thumbnail_filename,
                &image_width, &image_height);

        if ((ret >= 0) && (image_width > 0) && (image_height > 0))
        {
            for (buffer_ind = 0; buffer_ind < WGUI_CAT426_THUMBNAIL_BUFFER_SIZE; buffer_ind ++)
            {
                if (g_wgui_cat426_p->icon_handle[buffer_ind] == GDI_NULL_HANDLE)
                {
                    /* if cahce, draw to cahce */
                    if (g_wgui_cat426_p->cache_buffer != NULL)
                    {
                        S32 cache_x;

                        /* non-blocking image decoder */
                        gdi_layer_push_and_set_active(g_wgui_cat426_p->cache_handle);

                        while ((g_wgui_cat426_p->cache_current_index > 0) &&
                               (g_wgui_cat426_p->cache_check[g_wgui_cat426_p->cache_current_index] == WGUI_CAT426_CACHE_ITEM_EMPTY))
                        {
                            g_wgui_cat426_p->cache_current_index --;
                        }
                        g_wgui_cat426_p->cache_current_index = (g_wgui_cat426_p->cache_current_index + 1)%(g_wgui_cat426_p->cache_size);

                        cache_x = WGUI_CAT426_IMAGE_WIDTH*g_wgui_cat426_p->cache_current_index;

                        /* clean cache */
                        gdi_draw_solid_rect(cache_x, 0, cache_x + WGUI_CAT426_IMAGE_WIDTH, WGUI_CAT426_IMAGE_HEIGHT, GDI_COLOR_WHITE);

                        gdi_nb_set_blt(MMI_FALSE,MMI_FALSE);
                        gdi_nb_set_done_callback(wgui_cat426_nb_display_callback);

                        {   /* draw no-blocking resized image */
                            S32 resized_offset_x = 0, resized_offset_y = 0;
                            S32 resized_width = 0, resized_height = 0;

                            if ((image_width <= WGUI_CAT426_IMAGE_WIDTH) &&
                                (image_height <= WGUI_CAT426_IMAGE_HEIGHT))
                            {
                                resized_offset_x = ((WGUI_CAT426_IMAGE_WIDTH - image_width) >> 1);
                                resized_offset_y = ((WGUI_CAT426_IMAGE_HEIGHT - image_height) >> 1);
                                resized_width = image_width;
                                resized_height = image_height;
                            }
                            else
                            {
                                gdi_image_util_fit_bbox(
                                        WGUI_CAT426_IMAGE_WIDTH,
                                        WGUI_CAT426_IMAGE_HEIGHT,
                                        image_width,
                                        image_height,
                                        &resized_offset_x,
                                        &resized_offset_y,
                                        &resized_width,
                                        &resized_height);
                            }

                            resized_width = (resized_width == 0) ? 1 : resized_width;
                            resized_height = (resized_height == 0) ? 1 : resized_height;

                            g_wgui_cat426_p->icon_handle[buffer_ind] =
                                gdi_image_nb_draw_resized_file(
                                        cache_x + resized_offset_x,
                                        0 + resized_offset_y,
                                        resized_width,
                                        resized_height,
                                        (S8*)thumbnail_filename);
                        }

                        if (g_wgui_cat426_p->icon_handle[buffer_ind] == GDI_ERROR_HANDLE)
                        {
                            g_wgui_cat426_p->icon_handle[buffer_ind] = GDI_NULL_HANDLE;
                        }

                        g_wgui_cat426_p->cache_x[g_wgui_cat426_p->cache_current_index] = cache_x;
                        g_wgui_cat426_p->cache_index[g_wgui_cat426_p->cache_current_index] = index;
                        g_wgui_cat426_p->cache_check[g_wgui_cat426_p->cache_current_index] = WGUI_CAT426_CACHE_ITEM_QUEUED;
                        g_wgui_cat426_p->buffer_cache_map[buffer_ind] = g_wgui_cat426_p->cache_current_index;

                        gdi_layer_pop_and_restore_active();

                        g_wgui_cat426_p->icon_x1[buffer_ind] = x1;
                        g_wgui_cat426_p->icon_y1[buffer_ind] = y1;
                        g_wgui_cat426_p->icon_x2[buffer_ind] = x2;
                        g_wgui_cat426_p->icon_y2[buffer_ind] = y2;
                    }
                    /* if no cache, draw directly */
                    else
                    {
                        /* non-blocking image decoder */
                        gdi_nb_set_blt(MMI_FALSE,MMI_FALSE);
                        gdi_nb_set_done_callback(wgui_cat426_nb_display_callback);

                        g_wgui_cat426_p->icon_handle[buffer_ind] = gdi_image_nb_draw_resized_file(x1, y1, WGUI_CAT426_IMAGE_WIDTH, WGUI_CAT426_IMAGE_HEIGHT, (S8*)thumbnail_filename);
                        if (g_wgui_cat426_p->icon_handle[buffer_ind] == GDI_ERROR_HANDLE)
                        {
                            g_wgui_cat426_p->icon_handle[buffer_ind] = GDI_NULL_HANDLE;
                        }
                    }
                    break;
                }
            }
        }
        else
        {
            /* broken image, treated as draw_by_cache */
            draw_by_cache = MMI_TRUE;
        }
    }
    
    gui_draw_rectangle(x1 - 1, y1 - 1, x2 + 1, y2 + 1, gui_color(0, 0, 0));

    gui_pop_clip();
    
    /* Show checkbox */    
    {
        S32 cbv_index = 0;

        /* get index */
        cbv_index = (MMI_fixed_list_menu.current_displayed_item == -1)
                    ? (MMI_fixed_list_menu.highlighted_item)
                    : (MMI_fixed_list_menu.current_displayed_item);

        /* get valuse */
        if (g_wgui_cat426_p->checkbox_values != NULL)
        {
            on_off_value = g_wgui_cat426_p->checkbox_values[cbv_index];
        }
        else if (g_wgui_cat426_cbv_cb != NULL)
        {
            g_wgui_cat426_cbv_cb(cbv_index, &on_off_value);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    if (mmi_fe_get_r2l_state())
    {
        x1 = right_x - g_wgui_cat426_p->check_box_x2;
        x2 = right_x - g_wgui_cat426_p->check_box_x1;
    }
    else
    {
        x1 = x + g_wgui_cat426_p->check_box_x1;
        x2 = x + g_wgui_cat426_p->check_box_x2;
    }
    y1 = y + g_wgui_cat426_p->check_box_y1;
    y2 = y + g_wgui_cat426_p->check_box_y2;

    wgui_cat426_show_check_box(x1, y1, x2, y2, on_off_value);

    if (draw_by_cache == MMI_FALSE)
    {
        if ((buffer_ind < WGUI_CAT426_THUMBNAIL_BUFFER_SIZE) &&
            (g_wgui_cat426_p->icon_handle[buffer_ind] != GDI_NULL_HANDLE))
        {
            g_wgui_cat426_p->icon_cb_x1[buffer_ind] = x1;
            g_wgui_cat426_p->icon_cb_y1[buffer_ind] = y1;
            g_wgui_cat426_p->icon_cb_x2[buffer_ind] = x2;
            g_wgui_cat426_p->icon_cb_y2[buffer_ind] = y2;
            g_wgui_cat426_p->on_off_value[buffer_ind] = on_off_value;
            g_wgui_cat426_p->default_image_id[buffer_ind] = default_image_id;
        }
    }
}




/*****************************************************************************
 * FUNCTION
 *  wgui_cat426_get_hints
 * DESCRIPTION
 *  Dummy callback for AsyncDynamic hint handler of Category 426
 * PARAMETERS
 *  start_index         [IN]        unused
 *  hint_array          [IN]        unused
 * RETURNS
 *  Always return 0 to indicate no hint is used
 *****************************************************************************/
static S32 wgui_cat426_get_hints(S32 start_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory426Screen
 * DESCRIPTION
 *  Exit the category426 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory426Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    /* Reset icontext-list style */
    fixed_icontext_list_menuitem_apply_current_theme();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */   

    if (g_wgui_cat426_p->cache_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_wgui_cat426_p->cache_handle);
        g_wgui_cat426_p->cache_handle = GDI_NULL_HANDLE;
    }

    for (i = 0; i < WGUI_CAT426_THUMBNAIL_BUFFER_SIZE; i++)
    {
        if (g_wgui_cat426_p->icon_handle[i] != GDI_NULL_HANDLE)
        { 
            gdi_image_nb_stop(g_wgui_cat426_p->icon_handle[i]);
            g_wgui_cat426_p->icon_handle[i] = GDI_NULL_HANDLE;
        }
    }
    
    if (g_wgui_cat426_p->cache_index != NULL)
    {
        OslMfree(g_wgui_cat426_p->cache_index);
        g_wgui_cat426_p->cache_index = NULL;
    }
    
    if (g_wgui_cat426_p->cache_x != NULL)
    {
        OslMfree(g_wgui_cat426_p->cache_x);
        g_wgui_cat426_p->cache_x = NULL;
    }
    
    if (g_wgui_cat426_p->cache_check != NULL)
    {
        OslMfree(g_wgui_cat426_p->cache_check);
        g_wgui_cat426_p->cache_check = NULL;
    }

    OslMfree(g_wgui_cat426_p);
    g_wgui_cat426_p = NULL;

    g_wgui_cat426_cbv_cb = NULL;

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  SetCat426CheckboxValueCallback
 * DESCRIPTION
 *  register check value callback for category 426
 * PARAMETERS
 *  cv_cb       [IN]    callback function
 * RETURNS
 *  void
 *****************************************************************************/
void SetCat426CheckboxValueCallback(
        wgui_cat426_cb_value_callback_type cbv_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat426_cbv_cb = cbv_cb;
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void ShowCategory426Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        MMI_ID_TYPE checkbox_on_icon,
        MMI_ID_TYPE checkbox_off_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_callback,
        wgui_cat426_thumbnail_callback_type get_thumbnail_callback,        
        U8 checkbox_values[],
        U8* cache_buffer,
        S32 cache_buffer_size,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 checkbox_width, checkbox_height;
    S32 text_column_width, text_column_x;    
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat426_p = OslMalloc(sizeof(wgui_cat426_context_struct));
    memset(g_wgui_cat426_p, 0, sizeof(wgui_cat426_context_struct));

    g_wgui_cat426_p->checkbox_values = (g_wgui_cat426_cbv_cb) ? (NULL) : (checkbox_values);
    g_wgui_cat426_p->thumbnail_callback = get_thumbnail_callback;
    g_wgui_cat426_p->checkbox_on_icon = checkbox_on_icon;
    g_wgui_cat426_p->checkbox_off_icon = checkbox_off_icon;

    gui_lock_double_buffer();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);

    /* check cache */
    g_wgui_cat426_p->cache_buffer = cache_buffer;
    if (cache_buffer != NULL)
    {
        gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

        g_wgui_cat426_p->cache_size = (S32)(cache_buffer_size/((WGUI_CAT426_IMAGE_WIDTH*WGUI_CAT426_IMAGE_HEIGHT*gdi_layer_get_bit_per_pixel() + 7) >> 3));
        
        /* assume the output display is base layer */
        gdi_layer_create_cf_using_outside_memory(
                gdi_act_layer->cf,
                0, 0,
                WGUI_CAT426_IMAGE_WIDTH*g_wgui_cat426_p->cache_size, WGUI_CAT426_IMAGE_HEIGHT,
                &g_wgui_cat426_p->cache_handle,
                cache_buffer, cache_buffer_size);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(g_wgui_cat426_p->cache_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();

        g_wgui_cat426_p->cache_index = OslMalloc(g_wgui_cat426_p->cache_size*sizeof(S32));
        g_wgui_cat426_p->cache_x = OslMalloc(g_wgui_cat426_p->cache_size*sizeof(S32));
        g_wgui_cat426_p->cache_check = OslMalloc(g_wgui_cat426_p->cache_size*sizeof(WGUI_CAT426_CACHE_ITEM_TYPE));

        for (i = 0; i < g_wgui_cat426_p->cache_size; i++)
        {
            g_wgui_cat426_p->cache_index[i] = -1;
            g_wgui_cat426_p->cache_x[i] = -1;
            g_wgui_cat426_p->cache_check[i] = WGUI_CAT426_CACHE_ITEM_EMPTY;
        }
    }
    
    /* 
     * Setup layout of menu: 0 icons, 2 texts
     * 
     * Thumbnail images and checkbox images are drawn by wgui_cat426_post_display_callback
     * instead of icontext-list menu item.
     */
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        0,
        get_item_callback,
        wgui_cat426_get_hints,
        highlighted_item,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        0,
        MMI_CATEGORY426_ID,
        history_buffer);
        
    /* Create icontext-list menu item */
    set_fixed_icontext_list_menuitems_post_display(wgui_cat426_post_display_callback);
    register_asyncdynamic_list_pre_display_handler(wgui_cat426_pre_display_callback);
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;
    resize_fixed_icontext_list_menuitems(0, MMI_MULTIROW_MENUITEM_HEIGHT);

#ifdef __MMI_SCREEN_ROTATE__
    if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {    
        MMI_fixed_icontext_list_menuitem.focussed_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
        MMI_fixed_icontext_list_menuitem.selected_filler = current_MMI_theme->menuitem_multirow_highlight_filler;
    }

    /* Set text coordinates inside icontext-list menu item */
    gui_measure_image(get_image(checkbox_on_icon), &checkbox_width, &checkbox_height);

    g_wgui_cat426_p->thumbnail_x1 = WGUI_CAT426_IMAGE_X;
    g_wgui_cat426_p->thumbnail_y1 = WGUI_CAT426_IMAGE_Y;
    g_wgui_cat426_p->thumbnail_x2 = WGUI_CAT426_IMAGE_X + WGUI_CAT426_IMAGE_WIDTH - 1;
    g_wgui_cat426_p->thumbnail_y2 = WGUI_CAT426_IMAGE_Y + WGUI_CAT426_IMAGE_HEIGHT - 1;

    /* set the position of check box */
#if defined (WGUI_CAT426_CBOX_AT_RIGHT_TOP)
    g_wgui_cat426_p->check_box_x1 = g_wgui_cat426_p->thumbnail_x2 - WGUI_CAT426_CBOX_MARGIN_GAP - checkbox_width + 1;
    g_wgui_cat426_p->check_box_y1 = g_wgui_cat426_p->thumbnail_y1 + WGUI_CAT426_CBOX_MARGIN_GAP;
#elif defined (WGUI_CAT426_CBOX_AT_RIGHT_DOWN)
    g_wgui_cat426_p->check_box_x1 = g_wgui_cat426_p->thumbnail_x2 - WGUI_CAT426_CBOX_MARGIN_GAP - checkbox_width + 1;
    g_wgui_cat426_p->check_box_y1 = g_wgui_cat426_p->thumbnail_y2 - WGUI_CAT426_CBOX_MARGIN_GAP - checkbox_height + 1;
#else
#error "category 426 did not have such kind of layout for check box"
#endif
    g_wgui_cat426_p->check_box_x2 = g_wgui_cat426_p->check_box_x1 + checkbox_width - 1;
    g_wgui_cat426_p->check_box_y2 = g_wgui_cat426_p->check_box_y1 + checkbox_height - 1;
    
    text_column_x = g_wgui_cat426_p->thumbnail_x2 + 1 + WGUI_CAT426_IMAGE_TEXT_GAP;
    text_column_width = MMI_fixed_icontext_list_menuitem.width - text_column_x - WGUI_CAT426_TEXT_SCROLLBAR_GAP;
            
    set_fixed_icontext_list_text_coordinates(
        0,
        text_column_x,
        WGUI_CAT426_TEXT1_Y,
        text_column_width,
        WGUI_CAT426_TEXT1_HEIGHT);
    set_fixed_icontext_list_text_coordinates(
        1,
        text_column_x,
        WGUI_CAT426_TEXT2_Y,
        text_column_width,
        WGUI_CAT426_TEXT2_HEIGHT);

    /* Override menu item style. We do not want UI_MENUITEM_CENTER_TEXT_Y */
    MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
    MMI_fixed_icontext_list_menuitem.flags &=
        ~(UI_MENUITEM_CENTER_TEXT_X | UI_MENUITEM_CENTER_TEXT_Y | UI_MENUITEM_CENTER_ICON_X |
          UI_MENUITEM_CENTER_ICON_Y);

    MMI_ASSERT(!gui_asyncdynamic_list_error);

    gui_unlock_double_buffer();

	wgui_cat_setup_category_default_history(MMI_CATEGORY426_ID, 0, ExitCategory426Screen);
    dm_redraw_category_screen();
}


/* For detail description, please refer to wgui_categories_IMPS.h */
void RefreshCategory426Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_wgui_cat426_p)
    {
        MMI_DBG_ASSERT(0);
        return;
    }
    wgui_text_menuitem_reset_scrolling();
    RedrawCategoryFunction();
}

#endif /* __MMI_MAINLCD_128X128__ */

//###############################################################

#if defined(__ATV_SMS_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  wgui_cate_reset_atv_sms_struct
 * DESCRIPTION
 *  reset atv sms struct
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_reset_atv_sms_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PU8*)&g_atv_sms_struct, 0, sizeof(atv_sms_struct));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_execute_atv_sms_cb
 * DESCRIPTION
 *  execute atv sms callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_execute_atv_sms_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_atv_sms_struct.Isuse) && (g_atv_sms_struct.atv_sms_cb))
    {
        g_atv_sms_struct.atv_sms_cb();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_set_atv_sms
 * DESCRIPTION
 *  set atv sms CatId and cb, and enable atv sms category
 * PARAMETERS
 *  CatId		[IN]		Category ID
 *  cb		[IN]		atv sms callback function
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_set_atv_sms(S32 CatId, FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_atv_sms_struct.atv_sms_cb = cb;
    g_atv_sms_struct.CatId = CatId;
    g_atv_sms_struct.Isuse = MMI_TRUE;
}


extern void gui_ssp_set_static_layer(gdi_handle layer);
/*****************************************************************************
 * FUNCTION
 *  wgui_cate_init_atv_setting
 * DESCRIPTION
 *  init scr blt and layer of ssp setting for SMS mATV 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_init_atv_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE effect_handle = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    
    /* get gdi layer handler for list effect */
    effect_handle = wgui_cat_matv_get_util_layer_handle();
    
    /* set gdi layer handle for list effect */
    gui_ssp_set_static_layer(effect_handle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cate_show_video_func
 * DESCRIPTION
 *  show video function for SMS mATV 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cate_show_video_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    show_video_func show_video;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    show_video = wgui_cat_matv_get_show_video_func();
    if ((show_video != NULL) && (!mmi_is_redrawing_bk_screens()))
    {
        show_video(wgui_cat_matv_get_video_layer_handle(),
            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3,
            GDI_LAYER_ENABLE_LAYER_1,
            WGUI_CAT_MATV_VIDEO_X,
            WGUI_CAT_MATV_VIDEO_Y,
            WGUI_CAT_MATV_VIDEO_W,
            WGUI_CAT_MATV_VIDEO_H);
    }
    else
    {
        gdi_draw_solid_rect(
            WGUI_CAT_MATV_VIDEO_X, 
            WGUI_CAT_MATV_VIDEO_Y,
            WGUI_CAT_MATV_VIDEO_X + WGUI_CAT_MATV_VIDEO_W -1,
            WGUI_CAT_MATV_VIDEO_Y + WGUI_CAT_MATV_VIDEO_H - 1,
            GDI_COLOR_BLACK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat1010_show
 * DESCRIPTION
 *  Displays the category1010 screen ( Normal list menu with description for SMS mATV )
 *  Normal list menu like 
 * PARAMETERS
 *  for detail information, please refer it's declaration
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1010_show(
         WCHAR *title,
         PU8 title_icon,
         WCHAR *left_softkey,
         PU8 left_softkey_icon,
         WCHAR *right_softkey,
         PU8 right_softkey_icon,
         S32 number_of_items,
         WCHAR **list_of_items,
         PU8 *list_of_icons,
         WCHAR **list_of_descriptions,
         S32 flags,
         S32 highlighted_item,
         U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, NULL);
    
    ShowCategory1704Screen(
        (U8*) title,
        title_icon,
        (U8*) left_softkey,
        (U8*) right_softkey,
        number_of_items,
        (U8**)list_of_items,
        list_of_icons,
        (U8**)list_of_descriptions,
        flags,
        MMI_FALSE,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


void wgui_cat1010_change_item_text(S32 index, WCHAR *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_fixed_icontext_menuitems[index].item_text = (UI_string_type)text;
	fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
}


void wgui_cat1010_change_item_description(S32 index, WCHAR *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_pop_up_description_strings[index].text_strings[0] = (UI_string_type) text;

#ifdef __MMI_UI_HINT_TOGGLE_TRANSITION__
	wgui_setup_pop_up_description_transition();
#endif /* __MMI_UI_HINT_TOGGLE_TRANSITION__ */
}


/*wgui_cat1011_show*/
/*****************************************************************************
* FUNCTION
*  wgui_cat1011_atv_sms_cb
* DESCRIPTION
*  disable list empty show
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1011_atv_sms_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }
}


 /*****************************************************************************
 * FUNCTION
 *  wgui_cat1011_show
 * DESCRIPTION
 *  Displays the category1011 screen (special for SMS mATV )
 * 
 * <img name="wgui_cat1010_img1" />
 * PARAMETERS
 *   for detail information, please refer it's declaration
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1011_show(
         WCHAR *title,
         PU8 title_icon,
         WCHAR *left_softkey,
         PU8 left_softkey_icon,
         WCHAR *right_softkey,
         PU8 right_softkey_icon,
         S32 number_of_items,
         GetItemFuncPtr get_item_func,
         GetHintFuncPtr get_hint_func,
         S32 highlighted_item,
         U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    gdi_layer_lock_frame_buffer();
    
    wgui_cate_set_atv_sms(MMI_CAT1011_ID, wgui_cat1011_atv_sms_cb);
    
    ShowCategory183Screen(
        (UI_string_type) title,
        title_icon,
        (UI_string_type) left_softkey,
        0,
        (UI_string_type) right_softkey,
        0,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        MMI_FALSE,
        NULL,
        history_buffer);
    
    wgui_cat_show_list_menu_empty_lable();
    
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    
    wgui_cate_show_video_func();
}
 

 /*****************************************************************************
 * FUNCTION
 *  wgui_cat1012_show
 * DESCRIPTION
 *  Displays the category1012 screen ( List menu with description for editor option special for SMS mATV)
 *  Menu list with menu item text id.
 * 
 * <img name="wgui_cat1012_img1" />
 * PARAMETERS
 *   for detail information, please refer it's declaration
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1012_show(
        WCHAR *title,
        PU8 title_icon,
        WCHAR *left_softkey,
        PU8 left_softkey_icon,
        WCHAR *right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        WCHAR **list_of_items,
        U16 *list_of_icons,
        WCHAR **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer,
        void (*f_highlight) (S32 item_index),
        void (*f_close) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables 											   */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, NULL);
    
    ShowCategory539Screen_ext(
        (UI_string_type) title,
        title_icon,
        (UI_string_type) left_softkey,
        (UI_string_type) right_softkey,
        number_of_items,
        (PU8*) list_of_items,
        list_of_icons,
        (PU8*) list_of_descriptions,
        flags,
        highlighted_item,
        history_buffer,
        f_highlight,
        f_close);
    
    wgui_cate_show_video_func();
}


/*
 * accordance with ShowCategory22Screen
 */
void wgui_cat1013_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 num_of_symbols,
        U8 **MMI_symbols,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1013_ID, NULL);
    
    ShowCategory22Screen_ext(
        (UI_string_type) title,
        title_icon,
        (UI_string_type) left_softkey,
        (UI_string_type) right_softkey,
        num_of_symbols,
        MMI_symbols,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


static void wgui_cat1014_atv_sms_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_fixed_list_move_twostate_menu(WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y);
    wgui_fixed_list_resize_twostate_menu(WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_CONTENT_H);
}

/*
 * accordance with ShowCategory36Screen
 */
void wgui_cat1014_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, wgui_cat1014_atv_sms_cb);
    
    ShowCategory36Screen_ext(
        (U8*) title,
        title_icon,
        (U8*) left_softkey,
        left_softkey_icon,
        (U8*) right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_items,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


/*
 * accordance with ShowCategory11Screen
 */
void wgui_cat1017_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }
    wgui_cat1014_show(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        highlighted_item,
        history_buffer);
}   /* end of ShowCategory11Screen */


/*
 * accordance with ShowCategory13Screen
 */
void wgui_cat1015_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }
    
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, wgui_cat1014_atv_sms_cb);
    
    ShowCategory12Screen_ext(
        (U8*) title,
        title_icon,
        (U8*) left_softkey,
        left_softkey_icon,
        (U8*) right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        list_of_states,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


/*
 * accordance with ShowCategory140Screen
 */
void wgui_cat1016_show(
        WCHAR* title,
        PU8 title_icon,
        S32 number_of_items,
        U8 **list_of_items,
        U8 *list_of_states,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, wgui_cat1014_atv_sms_cb);
    
    ShowCategory140Screen_ext(
        (U8*) title,
        title_icon,
        number_of_items,
        list_of_items,
        list_of_states,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


void wgui_cat1018_show(/* mapping with ShowCategory15Screen */
         WCHAR* title,
         PU8 title_icon,
         WCHAR* left_softkey,
         PU8 left_softkey_icon,
         WCHAR* right_softkey,
         PU8 right_softkey_icon,
         S32 number_of_items,
         U16 *list_of_items,
         U16 *list_of_icons,
         S32 highlighted_item,
		 U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_items; i++)
    {
        subMenuDataPtrs[i] = (PU8) get_string(list_of_items[i]);
    }
    
    wgui_cate_init_atv_setting();
    
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, wgui_cat1014_atv_sms_cb);
    
    ShowCategory353Screen_ext(
        (U8*) title,
        title_icon,
        (U8*) left_softkey,
        left_softkey_icon,
        (U8*) right_softkey,
        right_softkey_icon,
        number_of_items,
        subMenuDataPtrs,
        list_of_icons,
        NULL,
        0,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}


void wgui_cat1019_show(/* mapping with ShowCategory354Screen */
         WCHAR* title,
         PU8 title_icon,
         WCHAR* left_softkey,
         PU8 left_softkey_icon,
         WCHAR* right_softkey,
         PU8 right_softkey_icon,
         S32 number_of_items,
         U8 **list_of_items1,
         U8 **list_of_items2,
         U16 *list_of_icons,
         S32 highlighted_item,
         U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cate_init_atv_setting();
    
    wgui_cate_set_atv_sms(MMI_CAT1010_ID, wgui_cat1014_atv_sms_cb);
    
    ShowCategory354Screen_ext(
        (U8*) title,
        title_icon,
        (U8*) left_softkey,
        left_softkey_icon,
        (U8*) right_softkey,
        right_softkey_icon,
        number_of_items,
        list_of_items1,
        list_of_items2,
        list_of_icons,
        highlighted_item,
        history_buffer);
    
    wgui_cate_show_video_func();
}
#endif /* __ATV_SMS_SUPPORT__ */


static MMI_BOOL	disable_sc_show = MMI_FALSE;


void wgui_cat1031_set_disable_sc_show(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disable_sc_show = flag;
}


static void wgui_cat1031_tab_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tab_n = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	disable_sc_show = MMI_FALSE;
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
     if(g_cat_list_is_show_thumbnail)
     {
        wgui_cat_thumbnail_deninit();
        g_cat_list_is_show_thumbnail = MMI_FALSE;
     }
#endif
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &tab_n);
    if(tab_n > 0)
    {
        wgui_close_horizontal_tab_bar();
    }
    wgui_cat_enable_list_menu_empty_lable();
    wgui_cat_AsyncItemFuncPtr = NULL;
    wgui_cat_AsyncHintFuncPtr = NULL;
}


/*  Async dynamic list
 * icon1   string1   icon2
 *                   string2  
 * support tab              */
#if defined(__MMI_FTE_SUPPORT__)
void wgui_cat1031_iconbar_resume(void)
{
    gui_fixed_icontext_list_menuitem_start_scroll();
    gdi_layer_lock_frame_buffer();
    show_asyncdynamic_list();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(
        MMI_fixed_list_menu.x,
        MMI_fixed_list_menu.y,
        MMI_fixed_list_menu.width - 1,
        MMI_fixed_list_menu.height - 1);
}
#endif

#define WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE	1
#define WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS	2
#define WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE	3
#define WGUI_CAT_ASYNC_DYN_SINGLE_LINE	0

static S32 wgui_cat_get_async_config(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = WGUI_CAT_ASYNC_DYN_SINGLE_LINE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__WGUI_CATE_LIST_ALL_HINTS_IN_MENUITEM__)
    flags = WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS;
#elif defined(__WGUI_CATE_LIST_HIGHLIGHTED_HINTS_IN_MENUITEM__)
    flags = WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE;
#else 
    flags = WGUI_CAT_ASYNC_DYN_SINGLE_LINE;
#endif 
    return flags;
}

static S32 wgui_cat_get_AsyncItem(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = wgui_cat_AsyncItemFuncPtr(start_index, menu_data, data_size);
    for (i = 0; i < ret; i++)
    {
        menu_data[i].item_list[1][0] = (UI_character_type)0;
        wgui_cat_AsyncHintFuncPtr(start_index + i, &menu_data[i].item_list[1]);
    }
    return ret;
}

static void wgui_cat_async_list_create_menu(S32 number_of_items, GetAsyncItemFuncPtr get_item_func, GetAsyncHintFuncPtr get_hint_func, S32 flags, S8 m_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number_of_text, menuitem_height, flag;
    GetAsyncItemFuncPtr getAsyncItem;
    GetAsyncHintFuncPtr getAsyncHint;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number_of_text = 1;
    flag = 0;
    menuitem_height = MMI_MENUITEM_HEIGHT;
    getAsyncItem = get_item_func;
    getAsyncHint = get_hint_func;
    if (get_hint_func)
    {
        if(flags == WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE ||
			flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS)
        {
            wgui_cat_AsyncItemFuncPtr = get_item_func;
            wgui_cat_AsyncHintFuncPtr = get_hint_func;
            getAsyncItem = wgui_cat_get_AsyncItem;
            getAsyncHint = NULL;
            menuitem_height = m_height;
            number_of_text = 2;
        }
        else if (flags == WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE)
        {
            flag = WGUI_ASYNC_DYNAMIC_LIST_MENU_TWO_LINE;
        }
    }
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        number_of_text,
        2,
        getAsyncItem,
        getAsyncHint,
        WGUI_LIST_INVALID_HIGHLIGHT,
        menuitem_height,
        flag,
        0,
        NULL);
}

static void wgui_cat1031_tab_show(
		WCHAR* title,
		PU8 title_icon,
		WCHAR* left_softkey,
		WCHAR* right_softkey,
		S32 number_of_items,
		GetAsyncItemFuncPtr get_item_func,
		GetAsyncHintFuncPtr get_hint_func,
		S32 highlighted_item,
		S8 highlighted_tab,    
		U16 list_icon1,
		U16 list_icon2,
		U8 *history_buffer,
		S32 *category_error_flag,
		S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;
    S32 w = 0, h = 0, text1_x, icon2_x, var;
    S32 catID, list_height, mi_height;
    S32 sec_fh, fir_fh;
    PU8 p_list_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    #ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
        wgui_cat_thumbnail_init(number_of_items);
    #endif
#ifdef __MMI_MAINLCD_96X64__ 
	if(category_error_flag!=NULL)
	{
		*category_error_flag=1;
	}
#endif
	gui_asyncdynamic_list_error = 0;
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
        catID = MMI_CAT1031_ID;
        mi_height = CAT627_MENUITEM_HEIGHT;
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CAT1031_NO_TAB_ID;
        mi_height = MMI_MULTIROW_MENUITEM_HEIGHT;
        list_height = MMI_CONTENT_HEIGHT;
    }
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif
    if (flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS)
    {
        mi_height = MMI_MENUITEM_HEIGHT<<1;
    }
    
    wgui_cat_async_list_create_menu(number_of_items, get_item_func, get_hint_func, flags, mi_height);
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_state();
#endif /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
   #ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {   
		MMI_fixed_icontext_list_menuitem.disabled_text_colors[0] = MMI_fixed_icontext_list_menuitem.normal_text_colors[0];
        set_fixed_icontext_list_menuitems_post_display(wgui_cat_thumbnail_post_display_callback);
    }
    #endif
    if (!set_list_menu_category_history((U16)catID, history_buffer))
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    p_list_icon = wgui_get_list_menu_icon(0, list_icon1);
    gui_measure_image(p_list_icon, &w, &h);
    var = 2;
    if ((get_hint_func) && (flags == WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE))
    {
        var = (mi_height - h)>>1;
    }
    if ((flags == WGUI_CAT_ASYNC_DYN_SINGLE_LINE) 
        || (flags == WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE))
    {
        var = 0;
    }
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, var,  w, h);
    text1_x = GUI_ICONTEXT_MENUITEM_ICON_X + w + 2;
    #ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
        wgui_cat_thumbnail_set_image_box_size(w, h);
        text1_x += 4;
    }
    #endif
	w = 0;
	h = 0;
    gui_measure_image(get_image(list_icon2), &w, &h);
	var = 2;
#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__)
    if (flags == WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE)
    {
        var = 0;
    }
#endif /* __MMI_MAINLCD_128X160__ || __MMI_MAINLCD_128X128__ */
    icon2_x = MMI_content_width - GUI_ICONTEXT_MENUITEM_ICON_X - w - MMI_fixed_list_menu.vbar.width;
    set_fixed_icontext_list_icon_coordinates(1, icon2_x, var, w, h);
    
    fir_fh = Get_CharHeightOfAllLang(gui_font_get_type(GUI_FONT_SIZE_LIST)->size);
	var = 2;
    if (get_hint_func)
    {
        if (flags == WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE)
        {
            MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_RIGHT_JUSTIFY_COL2;
            sec_fh = Get_CharHeightOfAllLang(SMALL_FONT);
            MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_small_font;
			if((mi_height - fir_fh - sec_fh)>0)
			{
            	var = (mi_height - fir_fh - sec_fh)>>1;
			}
            set_fixed_icontext_list_text_coordinates(1, text1_x, var + fir_fh, 
				MMI_content_width - MMI_fixed_list_menu.vbar.width - text1_x - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP, 
				sec_fh);
        }
        else if (flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS)
        {
            MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
            var = ((mi_height>>1)- fir_fh)>>1;
            set_fixed_icontext_list_text_coordinates(1, text1_x, (mi_height>>1) + var, 
				MMI_content_width - MMI_fixed_list_menu.vbar.width - text1_x - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP, 
				fir_fh);			
        }
    }
    if ((flags == WGUI_CAT_ASYNC_DYN_SINGLE_LINE) 
        || (flags == WGUI_CAT_ASYNC_DYN_HIGHLIGHTED_TWO_LINE))
    {
        var = 0;
    }
    set_fixed_icontext_list_text_coordinates(0, text1_x, var, icon2_x - text1_x - GUI_MENUITEM_TEXT_RIGHT_GAP, fir_fh);
    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
        wgui_async_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        wgui_async_list_resize_multi_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
    }
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        wgui_icon_bar_register_pause_interactive_UI_callback(gui_fixed_icontext_list_menuitem_stop_scroll);
        wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat1031_iconbar_resume);
    }
#endif
#endif/*__MMI_ICON_BAR_SUPPORT__*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

	wgui_cat_setup_category_default_history(catID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1031_tab_exit);
	if (disable_sc_show)
    {
		wgui_title_set_no_icon_shct(MMI_FALSE);
    }
	dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    #ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
        wgui_cat_thumbnail_post_init(number_of_items);
    }
   #endif
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#ifdef __MMI_MAINLCD_96X64__ 
	if(category_error_flag!=NULL)
	{
		*category_error_flag=0;
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat1031_refresh_list
 * DESCRIPTION
 *  refresh category1031 list menu
 * PARAMETERS
 *  number_of_items                       [IN]        number of items
 *  highlighted_item                  [IN]        highlighted item
 *  get_item_func                [IN]        function for get item
 *  get_hint_func           [IN]        function for get hint
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1031_refresh_list(
					S32 number_of_items, 
					S32 highlighted_item, 
					GetAsyncItemFuncPtr get_item_func,
					GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GetAsyncItemFuncPtr getAsyncItem;
    GetAsyncHintFuncPtr getAsyncHint;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    getAsyncItem = get_item_func;
    getAsyncHint = get_hint_func;
    if (get_hint_func)
    {
        wgui_cat_AsyncItemFuncPtr = get_item_func;
        wgui_cat_AsyncHintFuncPtr = get_hint_func;
        getAsyncItem = wgui_cat_get_AsyncItem;
        getAsyncHint = NULL;
    }
    mmi_cat_refresh_asyncdynamic_list(number_of_items, highlighted_item, getAsyncItem, getAsyncHint);
}

void wgui_cat1031_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
		S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
		S8 highlighted_tab,    
        U16 list_icon1,
		U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1031_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        highlighted_tab,
        list_icon1,
        list_icon2,
        history_buffer,
        category_error_flag,
        WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE);
}


/* Async dynamic list
 * icon1   string1   icon2
 * with descriptions
 * support tab              */

/*****************************************************************************
 * FUNCTION
 *  mmi_cat1032_refresh_list
 * DESCRIPTION
 *  refresh category1032 list menu
 * PARAMETERS
 *  number_of_items                       [IN]        number of items
 *  highlighted_item                  [IN]        highlighted item
 *  get_item_func                [IN]        function for get item
 *  get_hint_func           [IN]        function for get hint
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1032_refresh_list(
					S32 number_of_items, 
					S32 highlighted_item, 
					GetAsyncItemFuncPtr get_item_func,
					GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags;
    GetAsyncItemFuncPtr getAsyncItem;
    GetAsyncHintFuncPtr getAsyncHint;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	flags = wgui_cat_get_async_config();
    getAsyncItem = get_item_func;
    getAsyncHint = get_hint_func;
    if (get_hint_func)
    {
        if(flags == WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE ||
			flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS)
        {
            wgui_cat_AsyncItemFuncPtr = get_item_func;
            wgui_cat_AsyncHintFuncPtr = get_hint_func;
            getAsyncItem = wgui_cat_get_AsyncItem;
            getAsyncHint = NULL;
        }
    }
    mmi_cat_refresh_asyncdynamic_list(number_of_items, highlighted_item, getAsyncItem, getAsyncHint);
}

void wgui_cat1034_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        S8 highlighted_tab,    
        U16 list_icon1,
        U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__	
    g_cat_list_is_show_thumbnail = MMI_TRUE;
#endif
    wgui_cat1031_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        highlighted_tab,    
        list_icon1,
        list_icon2,
        history_buffer,
        category_error_flag,
        wgui_cat_get_async_config());  
}

void wgui_cat1032_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        S8 highlighted_tab,    
        U16 list_icon1,
        U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1031_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        highlighted_tab,    
        list_icon1,
        list_icon2,
        history_buffer,
        category_error_flag,
        wgui_cat_get_async_config());
}

static void wgui_cat1033_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	reset_fixed_list();
    reset_pop_up_descriptions();
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
        wgui_close_horizontal_tab_bar();
    }
}
/* Fixed icontext list
 * icon1   string1   icon2
 * highlight two line
 * support tab              */

void wgui_cat1033_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
		S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        U16 *list_of_icons,
        S32 highlighted_item,
        S8 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 n_tabs = 0;
	U8 h_flag = 0;
	S32 w1 = 0, h1 = 0;
	S32 text1_x, text1_w;
	S32 font_height_m;
	U16 catID;
	S32 list_height = MMI_CONTENT_HEIGHT;
	U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
	mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT;
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        list_height = CAT_MMI_CONTENT_HEIGHT_WITH_H_TAB;
#endif
        catID = MMI_CAT1033_ID;
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        catID = MMI_CAT1033_NO_TAB_ID;
    }
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/
	wgui_fixed_list_create_multi_icontext_menu(
        1,
        2,
        number_of_items,
        highlighted_item,
        MMI_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_TWO_LINE,
        0,
        NULL);
	h_flag = set_list_menu_category_history(catID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
	MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_CENTER_TEXT_Y;

	gui_measure_image(get_image(list_of_icons[0]), &w1, &h1);
    
    font_height_m = Get_CharHeightOfAllLang(MEDIUM_FONT);

	set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0,  w1, h1);

	text1_x = GUI_ICONTEXT_MENUITEM_ICON_X + w1 + 2;
	text1_w = MMI_content_width - text1_x - GUI_ICONTEXT_MENUITEM_ICON_X - MMI_fixed_list_menu.vbar.width;
	set_fixed_icontext_list_text_coordinates(0, text1_x, 0, text1_w, font_height_m);
	set_fixed_icontext_list_text_coordinates(1, text1_x, MMI_MENUITEM_HEIGHT, text1_w, font_height_m);
    wgui_fixed_list_begin_add_multi_icontext_one_item();
    for (i = 0; i < number_of_items; i++)
    {
        U8 *items[2];
        U8 *icons[1];
        items[0] = list_of_items[i];
		items[1] = list_of_descriptions[i];
        icons[0] = get_image(list_of_icons[i]);

        wgui_fixed_list_add_multi_icontext_one_item(i, items, icons, NULL);

    }
    wgui_fixed_list_end_add_multi_icontext_one_item();
	if(n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_fixed_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
#else
        wgui_fixed_list_move_multi_icontext_menu(CAT_MMI_CONTENT_X_WITH_H_TAB, CAT_MMI_CONTENT_Y_WITH_H_TAB);
#endif
        wgui_fixed_list_resize_multi_icontext_menu(CAT_MMI_CONTENT_WIDTH_WITH_H_TAB, list_height);
    }
    else
    {
        wgui_fixed_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        wgui_fixed_list_resize_multi_icontext_menu(MMI_content_width, list_height);
    }

	wgui_cat_setup_category_default_history((S32)catID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1033_exit);
    gdi_layer_unlock_frame_buffer();
	dm_redraw_category_screen();
}

//###############################################################

static void wgui_cat1024_tab_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
     if(g_cat_list_is_show_thumbnail)
     {
        wgui_cat_thumbnail_deninit();
        g_cat_list_is_show_thumbnail = MMI_FALSE;
     }
#endif
    if (g_cat_tab_num)
    {
        wgui_close_horizontal_tab_bar();
        g_cat_tab_num = 0;
    }
    wgui_title_disable_menu_shortcut_display(MMI_FALSE);
    reset_menu_shortcut_handler();
    reset_asyncdynamic_list();
    reset_pop_up_descriptions();
#ifdef __MMI_UI_HINTS_IN_MENUITEM__
    reset_all_force_flags_for_hints();
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */
}

static void wgui_cat1024_tab_show(
            WCHAR* title,
            PU8 title_icon,
            WCHAR* left_softkey,
            WCHAR* right_softkey,
            WCHAR* info_message,
            S32 number_of_items,
            GetAsyncItemFuncPtr get_item_func,
            GetAsyncHintFuncPtr get_hint_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,
            S32 highlighted_item,
            S32 highlighted_tab,
            U16 list_icon1,
            U16 list_icon2,
            U8 *history_buffer,
            S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 n_tabs = 0;
    S32 w = 0;
    S32 var = 0, text_width = 0, CatId, mi_height;
	S32 w1 = 0, h1 = 0, fir_fh;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
        wgui_cat_thumbnail_init(number_of_items);
#endif 
    gui_asyncdynamic_list_error = 0;
	dm_add_softkey_str((UI_string_type)left_softkey, (UI_string_type)right_softkey);
    mmi_frm_get_tab_bar_items(MMI_tab_bar_items, &n_tabs);
    g_cat_tab_num = n_tabs;
    if (n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_create_horizontal_tab_bar(FALSE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
        wgui_setup_horizontal_tab_bar_no_title_shortcut();
#else
        wgui_create_horizontal_tab_bar(TRUE, (UI_string_type)title, n_tabs, highlighted_tab, MMI_FALSE);
#endif
        CatId = MMI_CAT1025_ID;
		mi_height = CAT627_MENUITEM_HEIGHT;
    }
    else
    {
        dm_add_title((UI_string_type) title, title_icon);
        CatId = MMI_CAT1024_ID;
		mi_height = MMI_MULTIROW_MENUITEM_HEIGHT;
    }
	
    if (flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS)
    {
        mi_height = MMI_MENUITEM_HEIGHT<<1;
    }
    
	wgui_cat_async_list_create_menu(number_of_items, get_item_func, get_hint_func, flags, mi_height);
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {   
		MMI_fixed_icontext_list_menuitem.disabled_text_colors[0] = MMI_fixed_icontext_list_menuitem.normal_text_colors[0];
        set_fixed_icontext_list_menuitems_post_display(wgui_cat_thumbnail_post_display_callback);
    }
#endif
    if(!set_list_menu_category_history((U16)CatId, history_buffer))
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
    /* set check-box */
    wgui_menuitem_set_icontext_list_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_state_func);
    
    gui_measure_image(get_image(CHECKBOX_ON_IMAGE_ID), &w, &text_width);
    w = w + 4;
    text_width = UI_device_width - (w + 2 + MMI_fixed_list_menu.vbar.width);

    gui_measure_image(get_image(list_icon1), &w1, &h1);
	set_fixed_icontext_list_icon_coordinates(0, w, 0, w1, h1);
	text_width = text_width - w1;
	w = w + w1 + 2;
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    w = w + 4;
#endif

    w1 = 0;
	h1 = 0;
	gui_measure_image(get_image(list_icon2), &w1, &h1);
    set_fixed_icontext_list_icon_coordinates(1, 
		UI_device_width - w1 - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X2_GAP, 
		0, w1, h1);
	
    fir_fh = Get_CharHeightOfAllLang(gui_font_get_type(GUI_FONT_SIZE_LIST)->size);
	var = 2;
	if (get_hint_func && (flags == WGUI_CAT_ASYNC_DYN_ALL_HINTS_IN_MENUITEMS))
    {
        MMI_fixed_icontext_list_menuitem.text_fonts[1] = &MMI_medium_font;
        var = ((mi_height>>1) - fir_fh)>>1;
        set_fixed_icontext_list_text_coordinates(1, w, (mi_height>>1) + var, 
			MMI_content_width - MMI_fixed_list_menu.vbar.width - w - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP, 
			fir_fh);
    }
    set_fixed_icontext_list_text_coordinates(0, w, var, 
		UI_device_width - w1 - MMI_fixed_list_menu.vbar.width - w - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP, 
		fir_fh);
    
    /* set the layout of the list */
    var = 0;
    if (info_message != NULL)
    {
        gui_set_font(&MMI_medium_font);
        dm_add_scroll_text(
            (UI_string_type) info_message,
            NULL,
            DrawCate628CategoryControlAreaBackground,
        #ifdef __MMI_MAINLCD_128X128__
            gui_color(0, 0, 0),
            gui_color(255, 255, 255)
        #else /* __MMI_MAINLCD_128X128__ */
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255)
        #endif /* __MMI_MAINLCD_128X128__ */
        );
        var = MMI_MENUITEM_HEIGHT;
    }
    
    if (n_tabs > 0)
    {
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
        wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH_WITH_H_TAB, MMI_CONTENT_HEIGHT_WITH_H_TAB + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - var);
#else
        wgui_async_list_move_multi_icontext_menu(MMI_CONTENT_X_WITH_H_TAB, MMI_CONTENT_Y_WITH_H_TAB);
        wgui_async_list_resize_multi_icontext_menu(MMI_CONTENT_WIDTH_WITH_H_TAB, MMI_CONTENT_HEIGHT_WITH_H_TAB - var);
#endif
    }
    else
    {
        wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
        wgui_async_list_resize_multi_icontext_menu(MMI_content_width, MMI_content_height - var);
    }
	wgui_cat_setup_category_default_history(CatId, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1024_tab_exit);
    /* redraw category screen */
    dm_redraw_category_screen();
    
    gdi_layer_unlock_frame_buffer();
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
        wgui_cat_thumbnail_post_init(number_of_items);
    }
#endif
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

void wgui_cat1024_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        WCHAR* info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 list_icon1,
        U16 list_icon2,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1024_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        0,
        list_icon1,
        list_icon2,
        history_buffer,
        wgui_cat_get_async_config());        
}


void wgui_cat1025_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        WCHAR* info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 list_icon1,
        U16 list_icon2,
        S32 highlighted_item,
        S32 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1024_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        highlighted_tab,
        list_icon1,
        list_icon2,
        history_buffer,
        wgui_cat_get_async_config());		
}

void wgui_cat1026_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        WCHAR* info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 list_icon1,
        U16 list_icon2,
        S32 highlighted_item,
        U8 *history_buffer)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    g_cat_list_is_show_thumbnail = MMI_TRUE;
#endif
    wgui_cat1024_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        0,
        list_icon1,
        list_icon2,
        history_buffer,
        wgui_cat_get_async_config());  

}
/*****************************************************************************
* FUNCTION
*  wgui_cat1042_show
* DESCRIPTION
*  Displays Category1031 screen
*  there use ID of title and softkey for application
*****************************************************************************/
void wgui_cat1042_show(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
		S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
		S8 highlighted_tab,    
        U16 list_icon1,
		U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1031_tab_show(
        (WCHAR*)get_string(title),
        get_image(title_icon),
        (WCHAR*)get_string(left_softkey),
        (WCHAR*)get_string(right_softkey),
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        highlighted_tab,
        list_icon1,
        list_icon2,
        history_buffer,
        category_error_flag,
        WGUI_CAT_ASYNC_DYN_ALWAYS_TWO_LINE);
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1043_show
* DESCRIPTION
*  Displays Category1032 screen
*  there use ID of title and softkey for application
*****************************************************************************/
void wgui_cat1043_show(
		U16 title,
		U16 title_icon,
		U16 left_softkey,
		U16 right_softkey,
		S32 number_of_items,
		GetAsyncItemFuncPtr get_item_func,
		GetAsyncHintFuncPtr get_hint_func,
		S32 highlighted_item,
		S8 highlighted_tab,    
		U16 list_icon1,
		U16 list_icon2,
		U8 *history_buffer,
		S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1031_tab_show(
        (WCHAR*)get_string(title),
        get_image(title_icon),
        (WCHAR*)get_string(left_softkey),
        (WCHAR*)get_string(right_softkey),
        number_of_items,
        get_item_func,
        get_hint_func,
        highlighted_item,
        highlighted_tab,
        list_icon1,
        list_icon2,
        history_buffer,
        category_error_flag,
        wgui_cat_get_async_config());
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1044_show
* DESCRIPTION
*  Displays Category1024 screen
*  there use ID of title and softkey for application
*****************************************************************************/
void wgui_cat1044_show(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        WCHAR* info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 list_icon1,
        U16 list_icon2,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1024_tab_show(
        (WCHAR*)get_string(title),
        get_image(title_icon),
        (WCHAR*)get_string(left_softkey),
        (WCHAR*)get_string(right_softkey),
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        0,
        list_icon1,
        list_icon2,
        history_buffer,
        wgui_cat_get_async_config());
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1045_show
* DESCRIPTION
*  Displays Category1025 screen
*  there use ID of title and softkey for application
*****************************************************************************/
void wgui_cat1045_show(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        WCHAR* info_message,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        checkbox_get_image_funcptr_type get_state_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 list_icon1,
        U16 list_icon2,
        S32 highlighted_item,
        S32 highlighted_tab,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1024_tab_show(
        (WCHAR*)get_string(title),
        get_image(title_icon),
        (WCHAR*)get_string(left_softkey),
        (WCHAR*)get_string(right_softkey),
        info_message,
        number_of_items,
        get_item_func,
        get_hint_func,
        get_state_func,
        set_state_func,
        highlighted_item,
        highlighted_tab,
        list_icon1,
        list_icon2,
        history_buffer,
        wgui_cat_get_async_config());		
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1046_show
* DESCRIPTION
*  Displays Category174 screen
*  there use ID of title and softkey for application
*****************************************************************************/
void wgui_cat1046_show(
		U16 title,
		U16 title_icon,
		U16 left_softkey,
		U16 right_softkey,
		S32 number_of_items,
		U8 **list_of_items,
		PU8 *list_of_icons,
		U8 **list_of_descriptions,
		S32 flags,
		S32 highlighted_item,
		U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory1704Screen(
        (U8*)get_string(title),
        get_image(title_icon),
        (U8*)get_string(left_softkey),
        (U8*)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons,
        list_of_descriptions,
        flags,
        MMI_TRUE,
        highlighted_item,
        history_buffer);
}

pBOOL(*wgui_cat1047_get_text_callback) (S32 item_index, UI_string_type str_buff);

/*****************************************************************************
* FUNCTION
*  wgui_cat1034_get_item
* DESCRIPTION
*  get item handler for async dynamic list menu
* PARAMETERS
*  start_index				   [IN] 	   start item index
*  menu_data				   [IN]	   item data
*  data_size				   [IN]	   number of get item
* RETURNS
*  void
*****************************************************************************/
static S32 wgui_cat1047_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 check_box;
    S32 i, index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < data_size; i++)
    {
        index = start_index + i;
        wgui_cat1047_get_text_callback(index, menu_data[i].item_list[0]);
        if (checklist_category_menu_item_states[index])
        {
            check_box = CHECKBOX_ON_IMAGE_ID;
        }
        else
        {
            check_box = CHECKBOX_OFF_IMAGE_ID;
        }
        menu_data[i].image_list[0] = get_image(check_box);
    }
    return data_size;
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1047_toggle_checkbox
* DESCRIPTION
*  toggle event for center or left softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1047_toggle_checkbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 check_box;
    S32 index = MMI_fixed_list_menu.highlighted_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    if (checklist_category_menu_item_states[index])
    {
        checklist_category_menu_item_states[index] = 0;
        check_box = CHECKBOX_OFF_IMAGE_ID;
    }
    else
    {
        checklist_category_menu_item_states[index] = 1;
        check_box = CHECKBOX_ON_IMAGE_ID;
    }
    MMI_fixed_icontext_list_menuitems[index].item_icons[0] = get_image(check_box);
	item_checked = 1;
	wgui_cat_set_right_softkey_function(item_checked);
    
    /* Reload data & invoke list highlight handler */
    asyncdynamic_list_goto_item_no_redraw(index);
    gdi_layer_unlock_frame_buffer();
    
    show_asyncdynamic_list();
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1047_highlight_handler
* DESCRIPTION
*  highlight handler function
* PARAMETERS
*  item_index				   [IN] 	   highlighted item
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1047_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 check_box;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    if (checklist_category_menu_item_states[item_index])
    {
        check_box = STR_GLOBAL_OFF;
    }
    else
    {
        check_box = STR_GLOBAL_ON;
    }
    ChangeLeftSoftkey(check_box, 0);
    asyncdynamic_list_highlight_handler(item_index);
    gdi_layer_unlock_frame_buffer();
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1047_get_history
* DESCRIPTION
*  get history for category1047
* PARAMETERS
*  history_buffer				   [IN] 	   history buffer
* RETURNS
*  return history buffer
*****************************************************************************/
U8 *wgui_cat1047_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_checked)
    {
        *((S32*) history_buffer) = 1;
    }
    else
    {
        *((S32*) history_buffer) = 0;
    }
    get_list_menu_category_history(MMI_CAT1031_NO_TAB_ID, history_buffer + sizeof(S32));
    return history_buffer;
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1047_get_history_size
* DESCRIPTION
*  get history size for category1047
* PARAMETERS
*  void
* RETURNS
*  return size of history buffer
*****************************************************************************/
S32 wgui_cat1047_get_history_size(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	return sizeof(S32) + get_list_menu_category_history_size();
}

/*****************************************************************************
* FUNCTION
*  wgui_cat1047_set_history
* DESCRIPTION
*  set history size for category1047
* PARAMETERS
*  history_buffer	[IN]	history buffer
* RETURNS
*  void
*****************************************************************************/
U8 wgui_cat1047_set_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer)
    {
        if (*((S32*) history_buffer))
        {
            item_checked = 1;
        }
        else
        {
            item_checked = 0;
        }
        return set_list_menu_category_history(MMI_CAT1031_NO_TAB_ID, history_buffer + sizeof(S32));
    }
    else
    {
        return 0;
    }
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
* FUNCTION
*  wgui_cat1047_tap_hdlr
* DESCRIPTION
*  tap handler function
* PARAMETERS
*  tap_type				   [IN] 	   tap type
*  index			   [IN] 	   tapped item index
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat1047_tap_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat1047_toggle_checkbox();
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1047_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for check box with on/off lsk
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  number_of_items         [IN]        Number of items in the menu
 *  get_item_func           [IN]        function for get item string and icon
 *  list_of_states                   [IN]        state for item state whether on or off
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1047_show(
		U16 title,
		U16 title_icon,
		S32 number_of_items,
		pBOOL(*get_text_callback) (S32 item_index, UI_string_type str_buff),
		U8 *list_of_states,
		S32 highlighted_item,
		U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U16 lsk_label = 0;
    S32 w, h;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    /* Draw screen */
    gdi_layer_lock_frame_buffer();
	gui_asyncdynamic_list_error = 0;
    if(number_of_items > 0)
    {
        lsk_label = STR_GLOBAL_ON;
    }
    
	dm_add_title_id((MMI_STR_ID)title, (MMI_IMG_ID)title_icon);
	dm_add_softkey_id((MMI_STR_ID)lsk_label, (MMI_STR_ID)STR_GLOBAL_BACK);
    
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        1,
        1,
        wgui_cat1047_get_item,
        NULL,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        0,
        0,
        NULL);
    
    wgui_async_list_override_multi_icontext_highlight_handler(wgui_cat1047_highlight_handler);
    
    set_left_softkey_function(wgui_cat1047_toggle_checkbox, KEY_EVENT_UP);
    if (number_of_items > 0)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
        SetCenterSoftkeyFunction(wgui_cat1047_toggle_checkbox, KEY_EVENT_UP);
    }
    
    checklist_category_menu_item_states = list_of_states;
    item_checked = 0;
	wgui_cat1047_get_text_callback = get_text_callback;
    if (!wgui_cat1047_set_history(history_buffer))
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    wgui_cat_set_right_softkey_function(item_checked);
    gui_measure_image(get_image(CHECKBOX_ON_IMAGE_ID), &w, &h);
    set_fixed_icontext_list_icon_coordinates(0, GUI_ICONTEXT_MENUITEM_ICON_X, 0, w, MMI_MENUITEM_HEIGHT);
    w = w + GUI_ICONTEXT_MENUITEM_ICON_X + 2;
    set_fixed_icontext_list_text_coordinates(0, w, 0, MMI_content_width - MMI_fixed_list_menu.vbar.width - w, MMI_MENUITEM_HEIGHT);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(wgui_cat1047_tap_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */
    
    asyncdynamic_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    
    gdi_layer_unlock_frame_buffer();
    
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
    
    wgui_cat_setup_category(
                    MMI_CAT1031_NO_TAB_ID,
                    0,
                    wgui_cat1031_tab_exit,
                    wgui_cat1047_get_history, 
                    wgui_cat1047_get_history_size);
    dm_redraw_category_screen();
}

#define WGUI_CATE_ML_GAP_HEIGHT		(MMI_MENUITEM_HEIGHT>>1)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1049_show
 * DESCRIPTION
 *  Displays the Dynamic menu screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label ID
 *  right_softkey           [IN]        Right softkey label ID
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  flags                   [IN]        flags
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1049_show(
		U8 *title,
		U16 left_softkey,
		U16 right_softkey,
		S32 number_of_items,
		U8 **list_of_items,
		PU8 *list_of_icons,
		S32 flags,
		S32 highlighted_item,
		U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 var1 = MAIN_LCD_DEVICE_WIDTH, var2 = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    ShowCategory32Screen_ext(
        title,
        NULL,
        (PU8)get_string(left_softkey),
        (PU8)get_string(right_softkey),
        number_of_items,
        list_of_items,
        list_of_icons,
        MMI_CAT1049_ID,
        highlighted_item,
        history_buffer);
    
    MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
    MMI_multiline_inputbox.flags |= 
		UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR
		| UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND;
	MMI_multiline_inputbox.normal_text_color = current_fixed_icontext_menuitem_theme->normal_text_color;
    wgui_inputs_ml_resize_fit(
        UI_device_width, 
        UI_device_height, 
        &var1,
        &var2);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    move_multiline_inputbox(MMI_title_x, MMI_title_y + MMI_title_height + WGUI_CATE_ML_GAP_HEIGHT);
    var1 = MMI_title_y + MMI_title_height + WGUI_CATE_ML_GAP_HEIGHT + var2 + WGUI_CATE_ML_GAP_HEIGHT;
#else
    move_multiline_inputbox(MMI_title_x, MMI_title_y + WGUI_CATE_ML_GAP_HEIGHT);
    var1 = MMI_title_y + WGUI_CATE_ML_GAP_HEIGHT + var2 + WGUI_CATE_ML_GAP_HEIGHT;
#endif
    resize_fixed_list(
        MMI_content_width, 
        UI_device_height - var1 - MMI_button_bar_height);
    move_fixed_list(MMI_content_x, var1);
    gdi_layer_unlock_frame_buffer();
    
    dm_redraw_category_screen();
    show_multiline_inputbox();
}
/*****************************************************************************
 * FUNCTION
 *  wgui_cat1070_show
 * DESCRIPTION
 *  Display two state list, show a description at the bottom of screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  left_softkey            [IN]        Left softkey label ID
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label ID
 *  right_softkey_icon      [IN]        Right softkey icon
 *  descriptions            [IN]        Descriptions
 *  number_of_items         [IN]        Number of items in the menu
 *  list_of_items           [IN]        Array of items
 *  list_of_icons           [IN]        Array of icons
 *  highlighted_item        [IN]        Default item to be highlighted (if there is no history)
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat1070_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        WCHAR* description,
        S32 number_of_items,
		U8 **list_of_items,
        U8 *list_of_states,
		S32 highlighted_item,
		U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 var;
    U32 flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_cat_add_title_and_softkey(title, title_icon, left_softkey, right_softkey);
    wgui_fixed_list_create_twostate_menu(
        get_image(CHECKBOX_ON_IMAGE_ID),
        get_image(CHECKBOX_OFF_IMAGE_ID),
        number_of_items,
        highlighted_item, 
        0,
        MMI_CAT1070_ID,
        history_buffer);
    checklist_category_menu_item_states = list_of_states;
    wgui_fixed_list_add_twostate_items(list_of_items, list_of_states, NULL);
    var = gui_strlen((UI_string_type)description);
    flag = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE
        | UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR
        | UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
    wgui_cat32_create_and_setup_multiline_inputbox((UI_string_type)description, var, var, flag, history_buffer);
	MMI_multiline_inputbox.normal_text_color = current_fixed_icontext_menuitem_theme->normal_text_color;
#ifdef __MMI_FTE_SUPPORT__
    gui_inputs_set_transparent_background(MMI_TRUE);
#endif /* __MMI_FTE_SUPPORT */
    gdi_layer_unlock_frame_buffer();
    wgui_cat_setup_category(
        MMI_CAT1070_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        ExitCategory32Screen,
        GetCategory32History,
        GetCategory32HistorySize);
    dm_redraw_category_screen();
}


#if defined(__MMI_UI_LIST_SCROLL_BY_PIXEL__)
static MMI_BOOL IsChangeItem = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_list_menu_set_changeitem
 * DESCRIPTION
 *  when you goback from history but not change number of items, IsHalf set MMI_TRUE.
 * PARAMETERS
 *  change       [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_list_menu_set_changeitem(MMI_BOOL change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
    IsChangeItem = change;
}
#endif /* __MMI_UI_LIST_SCROLL_BY_PIXEL__ */


#if defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__)
static cat_iconlist_menu_item_ext md_ext[MAX_ASYNCDYNAMIC_ITEMS_BUFF];


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_list_menu_goto_item
 * DESCRIPTION
 *  Go to a specified item index for change item height.
 * PARAMETERS
 *  m       [IN]        list menu object
 *  i       [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_list_menu_goto_item(fixed_list_menu *m, S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 n_items;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
    if ((i < -1) || (i > m->n_items - 1))
    {
        return;
    }
    
    if (i == m->highlighted_item && i != -1)
    {
        return ;
    }

	if (m->last_displayed_item > m->n_items - 1)
	{
	    n_items = m->n_items - 1;
	}
	else
	{
	    n_items = m->last_displayed_item;
	}

	n_items = n_items - m->first_displayed_item + 1;

	if (n_items == 0)
	{
	    n_items++;
	}

    if (gui_asyncdynamic_list_error == 0 &&
        !load_chunk_asyncdynamic_item_buffer(m->first_displayed_item, n_items))
    {
        gui_asyncdynamic_list_error = 1;
		if (m->highlighted_item == -1)
		{
		    m->highlighted_item = i;
		}
        return ;
    }	

	if (IsChangeItem)
	{
	    m->flags &= ~UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM;
	}
    gui_list_menu_goto_item(m, i);
	if ((!gui_asyncdynamic_list_loading_error) && (!gui_asyncdynamic_list_error))
	{
		if (m->highlighted_item == i)
		{
		    m->highlighted_item = -1;
		}
	    gui_list_menu_goto_item(m, i);
		wgui_cat_list_menu_set_changeitem(MMI_FALSE);
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_list_menu_goto_previous_item
 * DESCRIPTION
 *  Go to the item previous to the highlighted item for change item height.
 * PARAMETERS
 *  m       [IN]        list menu object     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_list_menu_goto_previous_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, iwidth, iheight, total, last_highlighted_item;
	MMI_BOOL goto_item = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
	m->flags &= ~UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM;
	last_highlighted_item = m->highlighted_item;
	m->highlighted_item--;

	if ((m->highlighted_item > m->first_displayed_item)
		|| (m->highlighted_item == -1))
	{
	    goto_item = MMI_TRUE;
	}
	else
	{
		m->current_displayed_item = m->highlighted_item;
    	m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
	    if (m->first_displayed_offset == 0)
	    {
	        goto_item = MMI_TRUE;
	    }
		else if ((m->first_displayed_offset > 0)
			&& (iheight < m->height))
		{
		    goto_item = MMI_TRUE;
		}
		else
		{
		    if (m->first_displayed_item != m->last_displayed_item)
		    {
				m->first_displayed_item = m->highlighted_item;
				m->current_displayed_item = m->highlighted_item;
				m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
				m->first_displayed_offset = iheight - m->height;
				gui_asyncdynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
		    }
			else
			{
			    if (m->first_displayed_offset == 0)
			    {
					goto_item = MMI_TRUE;
			    }
				else
				{
				    m->highlighted_item = last_highlighted_item;
				    m->first_displayed_offset -= m->height;
					if (m->first_displayed_offset < 0)
					{
					    m->first_displayed_offset = 0;
					}
				}
			}
		}
	}

	if (goto_item)
	{
	    m->highlighted_item = last_highlighted_item;
		gui_list_menu_goto_previous_item(m);
	}
		
	total = 0;
	if ((m->last_displayed_item == m->n_items - 1)
		&& (m->last_displayed_item == m->highlighted_item))
	{
	    m->last_displayed_offset = 0;
	}
	for (i = m->last_displayed_item; i >= 0; i--)
	{
		m->current_displayed_item = i;
		m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
		total += iheight;

		if ((i == m->last_displayed_item) && (m->last_displayed_offset > 0))
		{
		    total -= iheight - m->last_displayed_offset;
		}
		
		if (total > m->height)
		{
			break;
		}
	}

	if (i > m->first_displayed_item)
	{
	    m->first_displayed_item = i;
		m->first_displayed_offset = total - m->height;
		if (gui_asyncdynamic_list_error == 0 &&
			!load_chunk_asyncdynamic_item_buffer(m->first_displayed_item, 
				m->last_displayed_item - m->first_displayed_item))
		{
			gui_asyncdynamic_list_error = 1;
			return ;
		}	
	}
	
	if ((!gui_asyncdynamic_list_loading_error) && (!gui_asyncdynamic_list_error))
	{
	    gui_asyncdynamic_list_menu_locate_highlighted_item(m);
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_list_menu_goto_next_item
 * DESCRIPTION
 *  Go to the item next to the highlighted item for change item height.
 * PARAMETERS
 *  m       [IN]        list menu object   
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_list_menu_goto_next_item(fixed_list_menu *m)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, iwidth, iheight, total, last_highlighted_item, offset = 0;
	MMI_BOOL goto_item = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/	
	m->flags &= ~UI_LIST_MENU_ENABLE_GOTO_HALF_ITEM;
	last_highlighted_item = m->highlighted_item;
	m->highlighted_item++;

	if (m->highlighted_item < m->last_displayed_item) 
	{
	    goto_item = MMI_TRUE;
	}
	else
	{
	    total = 0;
		for (i = m->first_displayed_item; i < m->last_displayed_item + 1; i++)
		{
			m->current_displayed_item = i;
			m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
			total += iheight;
		}
		offset = 0;
		if (m->last_displayed_offset > 0)
		{
		    offset = iheight - m->last_displayed_offset;
		}
		if (total == m->height + m->first_displayed_offset + offset)
		{
		    if ((last_highlighted_item >= m->last_displayed_item) && (offset > 0))
		    {
		        m->first_displayed_offset = 0;
		    }
			else
			{
				if ((m->highlighted_item >= m->n_items) || (iheight > m->height))
				{
					m->first_displayed_offset = 0;
				}
			}
			goto_item = MMI_TRUE;
		}
		else if ((total > m->height + m->first_displayed_offset + offset)
			&& (iheight < m->height))
		{
		    goto_item = MMI_TRUE;
		}
		else
		{
		    if (m->first_displayed_item != m->last_displayed_item)
		    {
		        if (total <= m->height + m->first_displayed_offset)
		        {
		            goto_item = MMI_TRUE;
		        }
				else
				{
					m->first_displayed_offset = 0;
					m->first_displayed_item = m->highlighted_item;
					gui_asyncdynamic_list_menu_switch_highlighted_item(m, last_highlighted_item);
				}
		    }
			else
			{
			    if (m->first_displayed_offset + m->height + offset == iheight)
			    {
			        goto_item = MMI_TRUE;
			    }
				else
				{
				    m->highlighted_item = last_highlighted_item;
				    m->first_displayed_offset += m->height;
					if (m->first_displayed_offset + m->height > iheight)
					{
					    m->first_displayed_offset = iheight - m->height;
					}
				}
			}
		}
	}

	if (goto_item)
	{
	    m->highlighted_item = last_highlighted_item;
		gui_list_menu_goto_next_item(m);
	}

	total = 0;
	for (i = m->first_displayed_item; i < m->n_items; i++)
	{
		m->current_displayed_item = i;
		m->item_measure_function(NULL, m->common_item_data, &iwidth, &iheight);
		total += iheight;
		
		if (total > m->height + m->first_displayed_offset)
		{
			break;
		}
	}

	if (i > m->last_displayed_item)
	{
		if (gui_asyncdynamic_list_error == 0 &&
			!load_chunk_asyncdynamic_item_buffer(m->first_displayed_item, 
				i - m->first_displayed_item))
		{
			gui_asyncdynamic_list_error = 1;
			return ;
		}	
	}

	if ((!gui_asyncdynamic_list_loading_error) && (!gui_asyncdynamic_list_error))
	{
	    gui_asyncdynamic_list_menu_locate_highlighted_item(m);
	}
}

typedef struct
{
    S32 checkbox_width;
    S32 icontext_height;
    S32 loading_width;
    S32 loading_height;
    S32 rbub_height;
    S32 lbub_height;
    S32 rbub_width;
    S32 lbub_width;
    UI_font_type text_font;
    CatGetAsyncItemFuncPtr get_item_func;
}cat_conversation_cntx;

static cat_conversation_cntx g_cat_conv_cntx;
static cat_conversation_cntx *g_cat_conv_cntx_p = &g_cat_conv_cntx;


/*****************************************************************************
* FUNCTION
*  wgui_cat_conversation_calc_mi_height
* DESCRIPTION
*  calc menuitem height
* PARAMETERS
*  text			[IN]		menu item large text
*  align			[IN]		large text align to left or right
*  t_width		[OUT]	width of large text
*  t_height		[OUT]	height of large text
* RETURNS
*  return menuitem height
*****************************************************************************/
static S32 wgui_cat_conversation_calc_mi_height(UI_string_type text, S32 align, S32 *t_width, S32 *t_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 height = 0, width = 0, max_height;
	gui_text_frame_struct tf;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*t_width = -1;
	*t_height = -1;
	gui_text_frame_create(&tf,
		0,	0,	UI_device_width, UI_device_height,
		text,
		g_cat_conv_cntx_p->text_font,
		gui_color(0, 0, 0),
		GUI_TEXT_FRAME_NOT_USE_CACHE);

	if (align == 0)
	{
		width = g_cat_conv_cntx_p->lbub_width;
		max_height = g_cat_conv_cntx_p->lbub_height;
	}
	else
	{
		width = g_cat_conv_cntx_p->rbub_width;
		max_height = g_cat_conv_cntx_p->rbub_height;
	}
	gui_text_frame_set_max_height(&tf, max_height);
	gui_text_frame_get_size(&tf, &width, &height);
	if (g_cat_conv_cntx_p->loading_height > height)
	{
	    height = g_cat_conv_cntx_p->loading_height;
	}
	if (g_cat_conv_cntx_p->loading_width > width)
	{
	    width = g_cat_conv_cntx_p->loading_width;
	}
	if (t_height && t_width)
	{
		*t_height = height;
		*t_width = width;
	}
	height += g_cat_conv_cntx_p->icontext_height;

	if (align == 0)
	{
	    height += (CAT_CONVERSATION_BULL_TO_TOP << 1) + 
			CAT_LEFT_BUBBLE_TEXT_TO_TOP + CAT_LEFT_BUBBLE_TEXT_TO_BOM;
	}
	else
	{
	    height += (CAT_CONVERSATION_BULL_TO_TOP << 1) + 
			CAT_RIGHT_BUBBLE_TEXT_TO_TOP + CAT_RIGHT_BUBBLE_TEXT_TO_BOM;
	}
	return height;
}


/*****************************************************************************
* FUNCTION
*  wgui_cat_conversation_get_mi_height
* DESCRIPTION
*  return height of every menutiem
* PARAMETERS
*  index		[IN]		menu item index
* RETURNS
*  height pixel number
*****************************************************************************/
static S32 wgui_cat_conversation_get_mi_height(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 height = 0, width = 0, align;
	UI_string_type _text;
	cat_iconlist_menu_item_ext *item_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (in_asyncdynamic_item_buffer(index))
	{
	    index = index - asyncdynamic_item_buffer.head_item_index;
	    item_info = &md_ext[(index + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
	    _text = (UI_string_type)item_info->string_ptr;
		width = item_info->string_width;
		height = item_info->string_height;
		align = item_info->lr_flag;
	}
	else
	{
	    index = index - asyncdynamic_item_buffer.head_item_index;
	    item_info = &md_ext[(index + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
	    _text = NULL;
		width = -1;
		height = -1;
		align = item_info->lr_flag;
	}
	
	if ((width != -1) && (height != -1))
	{
		if (_text)
		{
		    height += g_cat_conv_cntx_p->icontext_height;
		}
		if (align == 0)
		{
			height += (CAT_CONVERSATION_BULL_TO_TOP << 1) + 
				CAT_LEFT_BUBBLE_TEXT_TO_TOP + CAT_LEFT_BUBBLE_TEXT_TO_BOM;
		}
		else
		{
			height += (CAT_CONVERSATION_BULL_TO_TOP << 1) + 
				CAT_RIGHT_BUBBLE_TEXT_TO_TOP + CAT_RIGHT_BUBBLE_TEXT_TO_BOM;
		}
		return height;
	}

    return wgui_cat_conversation_calc_mi_height(_text, align, &width, &height);
}

#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_conversation_pen_check_bound
 * DESCRIPTION
 *  check whether is in the bubble the pen position
 * PARAMETERS
 *  item						[IN]        fixed_icontext_list_menuitem_type
 *  common_item_data			[IN]        fixed_icontext_list_menuitem
 *  index						[IN]		menu item index
 *  x							[IN]		
 *  y							[IN]
 * RETURNS
 *  return MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL wgui_cat_conversation_pen_check_bound(void *item, void *common_item_data, S32 index, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    cat_iconlist_menu_item_ext *item_info;
	S32 clip_x1, clip_x2, clip_y1, clip_y2, height, width;
	S32 dt_width = 0, dt_height = 0, i_width = 0, i_height = 0, t_width = 0, t_height = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
	if (in_asyncdynamic_item_buffer(index))
	{
	    index = index - asyncdynamic_item_buffer.head_item_index;
	    item_info = &md_ext[(index + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
		t_height = item_info->string_height;
		t_width = item_info->string_width;

		if (item_info->string_ptr)
		{
		    t_height += g_cat_conv_cntx_p->icontext_height;
		}
		if (item_info->lr_flag == 0)
		{
		    if (mi == NULL)
		    {
		        mi = get_asyncdynamic_item_from_buffer(index + asyncdynamic_item_buffer.head_item_index);
		    }
			if (mi->item_texts[0])
			{
				dt_width = m->text_coordinates[0].width;
				dt_height = m->text_coordinates[0].height;
			}
			if (mi->item_icons[0])
			{
				i_width = m->icon_coordinates[0].width;
				i_height = m->icon_coordinates[0].height;
			}
			
			if (t_width > dt_width + i_width)
			{
				width = t_width;
			}
			else
			{
				width = dt_width + i_width;
			}
			
			height = t_height + i_height;
			
			if (g_cat_conv_cntx_p->checkbox_width)
			{
				clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT;
				clip_x1 = clip_x2 - width - CAT_LEFT_BUBBLE_TEXT_TO_LEFT - CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;
			}
			else
			{
				clip_x1 = CAT_CONVERSATION_BULL_TO_LEFT;
				clip_x2 = clip_x1 + width + CAT_LEFT_BUBBLE_TEXT_TO_LEFT + CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;
			}
			clip_y1 = CAT_CONVERSATION_BULL_TO_TOP;
			clip_y2 = clip_y1 + CAT_LEFT_BUBBLE_TEXT_TO_TOP 
				+ height + CAT_LEFT_BUBBLE_TEXT_TO_BOM;
		}
		else
		{
		    if (mi == NULL)
		    {
		        mi = get_asyncdynamic_item_from_buffer(index + asyncdynamic_item_buffer.head_item_index);
		    }
			if (mi->item_texts[0])
			{
				dt_width = m->text_coordinates[0].width;
				dt_height = m->text_coordinates[0].height;
			}
			if (mi->item_icons[0])
			{
				i_width = m->icon_coordinates[0].width;
				i_height = m->icon_coordinates[0].height;
			}
			
			if (t_width > dt_width + i_width)
			{
				width = t_width;
			}
			else
			{
				width = dt_width + i_width;
			}

			height = t_height + i_height;

			clip_y1 = CAT_CONVERSATION_BULL_TO_TOP;
			clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT;
			clip_x1 = clip_x2 - width - CAT_RIGHT_BUBBLE_TEXT_TO_LEFT - CAT_RIGHT_BUBBLE_TEXT_TO_RIGHT;
			clip_y2 = clip_y1 + CAT_RIGHT_BUBBLE_TEXT_TO_TOP
				+ height + CAT_RIGHT_BUBBLE_TEXT_TO_BOM;
		}

		if ((x >= clip_x1) 
			&& (x <= clip_x2) 
			&& (y >= clip_y1) 
			&& (y <= clip_y2))
		{
		    return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1058_post_display_menuitem
 * DESCRIPTION
 *  show icontext list menuitem for owner draw
 * PARAMETERS
 *  item						[IN]        fixed_icontext_list_menuitem_type
 *  common_item_data			[IN]        fixed_icontext_list_menuitem
 *  x							[IN]		
 *  y							[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_conversation_post_display_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    fixed_icontext_list_menuitem *m = (fixed_icontext_list_menuitem*) common_item_data;
    fixed_icontext_list_menuitem_type *mi = (fixed_icontext_list_menuitem_type*) item;
    gui_text_frame_struct tf;
    color text_color;
    UI_string_type _text = NULL;
	S32 item_index, align = 0, width, height;
	U16 image_id = 0;
	S32 clip_x1, clip_x2, clip_y1, clip_y2;
	S32 dt_width = 0, dt_height = 0, i_width = 0, i_height = 0, t_width = 0, t_height = 0;
	cat_iconlist_menu_item_ext *item_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    item_index = MMI_fixed_list_menu.current_displayed_item;
    if (item_index == -1)
    {
        item_index = wgui_title_get_menu_shortcut_number() - 1;
    }

	if (in_asyncdynamic_item_buffer(item_index))
	{
	    item_index = item_index - asyncdynamic_item_buffer.head_item_index;
	    item_info = &md_ext[(item_index + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
	    _text = (UI_string_type)item_info->string_ptr;
		align = item_info->lr_flag;
		t_height = item_info->string_height;
		t_width = item_info->string_width;
	}
	else
	{
		item_index = item_index - asyncdynamic_item_buffer.head_item_index;
		item_info = &md_ext[(item_index + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
	    _text = NULL;
		align = item_info->lr_flag;
		t_height = -1;
		t_width = -1;
	}

	if (align == 0) /* left align */
	{
 		if (mi->flags & UI_MENUITEM_STATE_FOCUSSED)
		{
		    text_color = gui_color(0, 0, 0);
			image_id = IMG_SMS_CONVERSATION_L_HIGHLIGHTED;
		}
		else
		{
		    text_color = gui_color(255, 255, 255);
			image_id = IMG_SMS_CONVERSATION_L_UNHIGHLIGHTED;
		}
		
		if ((t_width != -1) && (t_height != -1))
		{
			gui_text_frame_create(
				&tf,
				0, 0, g_cat_conv_cntx_p->lbub_width, t_height,
				_text,
				g_cat_conv_cntx_p->text_font,
				text_color,
				GUI_TEXT_FRAME_NOT_USE_CACHE);
			gui_text_frame_set_max_height(&tf, g_cat_conv_cntx_p->lbub_height);
		}
		else
		{
			gui_text_frame_create(
				&tf,
				0, 0, UI_device_width, UI_device_height,
				_text,
				g_cat_conv_cntx_p->text_font,
				text_color,
				GUI_TEXT_FRAME_NOT_USE_CACHE);
			t_width = g_cat_conv_cntx_p->lbub_width;
			gui_text_frame_set_max_height(&tf, g_cat_conv_cntx_p->lbub_height);
			gui_text_frame_get_size(&tf, &t_width, &t_height);
			if (g_cat_conv_cntx_p->loading_height > t_height)
			{
				t_height = g_cat_conv_cntx_p->loading_height;
			}
			if (g_cat_conv_cntx_p->loading_width > t_width)
			{
				t_width = g_cat_conv_cntx_p->loading_width;
			}
		}
		
		if (mi->item_texts[0])
		{
		    gui_set_font(m->text_fonts[0]);
		    gui_measure_string((UI_string_type)mi->item_texts[0], &dt_width, &dt_height);
		}
		if (mi->item_icons[0])
		{
		    i_width = m->icon_coordinates[0].width;
			i_height = m->icon_coordinates[0].height;
		}

		if (t_width > dt_width + i_width)
		{
		    width = t_width;
		}
		else
		{
		    width = dt_width + i_width;
		}

		height = t_height + g_cat_conv_cntx_p->icontext_height;

		/* draw bull */
		if (g_cat_conv_cntx_p->checkbox_width)
		{
			clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT;
			clip_x1 = clip_x2 - width - CAT_LEFT_BUBBLE_TEXT_TO_LEFT - CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;
		}
		else
		{
			clip_x1 = x + CAT_CONVERSATION_BULL_TO_LEFT;
			clip_x2 = clip_x1 + width + CAT_LEFT_BUBBLE_TEXT_TO_LEFT + CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;
		}
		clip_y1 = y + CAT_CONVERSATION_BULL_TO_TOP;
		clip_y2 = clip_y1 + CAT_LEFT_BUBBLE_TEXT_TO_TOP 
			+ CAT_CONVERSATION_TEXT_TO_TEXT + height + 
			CAT_LEFT_BUBBLE_TEXT_TO_BOM;
		
		gui_push_clip();
		gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
		gdi_image_draw_resized_id(
			clip_x1,
			clip_y1,
			(clip_x2 - clip_x1),
			(clip_y2 - clip_y1),
			image_id);
			
		gui_pop_clip();

		/* draw large text */
		clip_x1 = clip_x1 + CAT_LEFT_BUBBLE_TEXT_TO_LEFT;
		clip_y1 = clip_y1 + CAT_LEFT_BUBBLE_TEXT_TO_TOP;
		gui_text_frame_move(&tf, clip_x1, clip_y1);
		gui_text_frame_set_need_update(&tf, MMI_FALSE);
		gui_text_frame_show(&tf);

		/* draw icon */
		clip_y2 = clip_y2 - CAT_LEFT_BUBBLE_TEXT_TO_BOM;
		clip_y1 = clip_y2 - i_height;
		clip_x2 = clip_x1 + i_width;
		if (mi->item_icons[0])
		{
			gui_push_clip();
			gui_set_clip_preset(clip_x1, clip_y1 - CAT_CONVERSATION_TEXT_TO_TEXT, clip_x2, clip_y2);
			gdi_image_draw(clip_x1, clip_y1, mi->item_icons[0]);
			gui_pop_clip();
		}

		/* draw date and time */
		if (g_cat_conv_cntx_p->checkbox_width)
		{
			clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT 
				- CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;
			clip_x1 = clip_x2 - dt_width;
		}
		else
		{
			clip_x2 = x + CAT_CONVERSATION_BULL_TO_LEFT + 
				width + CAT_LEFT_BUBBLE_TEXT_TO_LEFT;
			clip_x1 = clip_x2 - dt_width;
		}
		clip_y1 = clip_y2 - CAT_CONVERSATION_DT_TO_BOM - dt_height - CAT_CONVERSATION_TEXT_TO_TEXT;

		if (mi->item_texts[0])
		{
			gui_push_clip();
			gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
			
			/* draw lines */
			gui_set_text_color(text_color);
			gui_set_font(m->text_fonts[0]);
			gui_move_text_cursor(clip_x1, clip_y1 + CAT_CONVERSATION_TEXT_TO_TEXT);
			gui_print_text(mi->item_texts[0]);
			gui_pop_clip();
		}
	}
	else /* right align */
	{
		if (mi->flags & UI_MENUITEM_STATE_FOCUSSED)
		{
		    text_color = gui_color(0, 0, 0);
			image_id = IMG_SMS_CONVERSATION_R_HIGHLIGHTED;
		}
		else
		{
		    text_color = gui_color(255, 255, 255);
			image_id = IMG_SMS_CONVERSATION_R_UNHIGHLIGHTED;
		}
		
		/* draw bull */		
		if ((t_width != -1) && (t_height != -1))
		{
			gui_text_frame_create(
				&tf,
				0, 0, g_cat_conv_cntx_p->rbub_width, t_height,
				_text,
				g_cat_conv_cntx_p->text_font,
				text_color,
				GUI_TEXT_FRAME_NOT_USE_CACHE);
			gui_text_frame_set_max_height(&tf, g_cat_conv_cntx_p->rbub_height);
		}
		else
		{
			gui_text_frame_create(
				&tf,
				0, 0, UI_device_width, UI_device_height,
				_text,
				g_cat_conv_cntx_p->text_font,
				text_color,
				GUI_TEXT_FRAME_NOT_USE_CACHE);
			t_width = g_cat_conv_cntx_p->rbub_width;
			gui_text_frame_set_max_height(&tf, g_cat_conv_cntx_p->rbub_height);
			gui_text_frame_get_size(&tf, &t_width, &t_height);
			if (g_cat_conv_cntx_p->loading_height > t_height)
			{
				t_height = g_cat_conv_cntx_p->loading_height;
			}
			if (g_cat_conv_cntx_p->loading_width > t_width)
			{
				t_width = g_cat_conv_cntx_p->loading_width;
			}
		}

		if (mi->item_texts[0])
		{
		    gui_set_font(m->text_fonts[0]);
		    gui_measure_string((UI_string_type)mi->item_texts[0], &dt_width, &dt_height);
		}
		if (mi->item_icons[0])
		{
		    i_width = m->icon_coordinates[0].width;
			i_height = m->icon_coordinates[0].height;
		}

		if (t_width > dt_width + i_width)
		{
            width = t_width;
		}
		else
		{
            width = dt_width + i_width;
		}

		height = t_height + g_cat_conv_cntx_p->icontext_height;

		clip_y1 = y + CAT_CONVERSATION_BULL_TO_TOP;
		clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT;
		clip_x1 = clip_x2 - width - CAT_RIGHT_BUBBLE_TEXT_TO_LEFT - CAT_RIGHT_BUBBLE_TEXT_TO_RIGHT;
		clip_y2 = clip_y1 + CAT_RIGHT_BUBBLE_TEXT_TO_TOP
			+ CAT_CONVERSATION_TEXT_TO_TEXT + height + 
			CAT_RIGHT_BUBBLE_TEXT_TO_BOM;

 		gui_push_clip();
		gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
		gdi_image_draw_resized_id(
			clip_x1,
			clip_y1,
			(clip_x2 - clip_x1),
			(clip_y2 - clip_y1),
			image_id);
			
		gui_pop_clip();

		/* draw large text */
		clip_x1 = clip_x1 + CAT_RIGHT_BUBBLE_TEXT_TO_LEFT;
		clip_y1 = clip_y1 + CAT_RIGHT_BUBBLE_TEXT_TO_TOP;
		gui_text_frame_move(&tf, clip_x1, clip_y1);
		gui_text_frame_set_need_update(&tf, MMI_FALSE);
		gui_text_frame_show(&tf);

		/* draw icon */
		clip_y2 = clip_y2 - CAT_RIGHT_BUBBLE_TEXT_TO_BOM;
		clip_y1 = clip_y2 - i_height;
		clip_x2 = clip_x1 + i_width;
		if (mi->item_icons[0])
		{
			gui_push_clip();
			gui_set_clip_preset(clip_x1, clip_y1 - CAT_CONVERSATION_TEXT_TO_TEXT, clip_x2, clip_y2);
			gdi_image_draw(clip_x1, clip_y1, mi->item_icons[0]);
			gui_pop_clip();
		}

		clip_x2 = MMI_content_width - CAT_CONVERSATION_BULL_TO_LEFT - CAT_RIGHT_BUBBLE_TEXT_TO_RIGHT;
		clip_x1 = clip_x2 - dt_width;
		clip_y1 = clip_y2 - CAT_CONVERSATION_DT_TO_BOM - dt_height - CAT_CONVERSATION_TEXT_TO_TEXT;
		if (mi->item_texts[0])
		{			
			gui_push_clip();
			gui_set_clip_preset(clip_x1, clip_y1, clip_x2, clip_y2);
			
			/* draw lines */
			gui_set_text_color(text_color);
			gui_set_font(m->text_fonts[0]);
			gui_move_text_cursor(clip_x1, clip_y1 + CAT_CONVERSATION_TEXT_TO_TEXT);
			gui_print_text(mi->item_texts[0]);
			gui_pop_clip();
		}
	}
}
 

/*****************************************************************************
 * FUNCTION
 *  wgui_cat_conversation_get_item
 * DESCRIPTION
 *  A general function to get the async item data function. 
 * PARAMETERS
 *  start_index         [IN]: Start index
 *  menu_data           [IN]: Menu item data
 *  num_of_item         [IN]: Number of items
 * RETURNS
 *  The number of items
 *****************************************************************************/
static S32 wgui_cat_conversation_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 get_size = 0, i, width, height, index, start, first_index, offset;
	cat_iconlist_menu_item md[MAX_ASYNCDYNAMIC_ITEMS_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_cat_conv_cntx_p->get_item_func == NULL)
	{
	    return data_size;
	}

    if (asyncdynamic_item_buffer.count == 0)
    {
        start = 0;
    }
	else
	{
	    start = start_index - asyncdynamic_item_buffer.head_item_index;
	}
	start = start + asyncdynamic_item_buffer.head;
	offset = -1;
	for (i = 0; i < data_size; i++)
	{
		md[i].item_list[0] = menu_data[i].item_list[0];
		md[i].item_list[1] = menu_data[i].item_list[1];
		md[i].image_list[0] = menu_data[i].image_list[0];

		md[i].string_ptr = NULL;
		md[i].lr_flag = 0;

		md[i].flag = menu_data[i].flag;
		md[i].flag_ext = menu_data[i].flag_ext;

		if (in_asyncdynamic_item_buffer(start_index + i))
		{
		    offset++;
		}
	}

	get_size = g_cat_conv_cntx_p->get_item_func(start_index, md, data_size);

	for (i = 0; i < data_size; i++)
	{
		index = (S32)((i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF);
		md_ext[index].lr_flag = md[i].lr_flag;
	}

	for (i = 0; i < get_size; i++)
	{
        menu_data[i].image_list[0] = md[i].image_list[0];
		menu_data[i].flag = md[i].flag;
		menu_data[i].flag_ext = md[i].flag_ext;

	    index = (S32)((i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF);
	    md_ext[index].lr_flag = md[i].lr_flag;
		if (md[i].string_ptr != NULL)
		{
		    md_ext[index].string_ptr = md[i].string_ptr;
		}
		else
		{
		    md_ext[index].string_ptr = (PU8)GetString(STR_GLOBAL_LOADING);
		}
		wgui_cat_conversation_calc_mi_height((UI_string_type)md_ext[index].string_ptr, md[i].lr_flag, &width, &height);
		md_ext[index].string_height = height;
		md_ext[index].string_width = width;
	}

	if (gui_screen_smooth_scrolling_moved_by_pen())
	{
	    S32 ret = get_size;

		if (get_size != data_size)
		{
		    if (get_size != -1)
		    {
		        ret = data_size;
		    }
		}
		
		first_index = get_size;
		if (first_index < 0)
		{
			first_index = 0;
		}
		for (i = first_index; i < data_size; i++)
		{
		    memset((CHAR*)menu_data[i].item_list[0], 0, sizeof(menu_data[i].item_list[0]));
			memset((CHAR*)menu_data[i].item_list[1], 0, sizeof(menu_data[i].item_list[1]));
			index = (S32)((i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF);
			md_ext[index].string_ptr = (PU8)GetString(STR_GLOBAL_LOADING);
			if (i > offset)
			{
				md_ext[index].string_height = g_cat_conv_cntx_p->loading_height;
				md_ext[index].string_width = g_cat_conv_cntx_p->loading_width;
			}
		}
		return ret;
	}

    if (get_size != data_size && get_size != -1)
    {
        /* Data loaded fail */
        return get_size;
    }
    else if (get_size != data_size)
    {
        first_index = get_size;
        if (first_index < 0)
        {
            first_index = 0;
        }
		for (i = first_index; i < data_size; i++)
		{
			index = (S32)((i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF);
			md_ext[index].string_ptr = (PU8)GetString(STR_GLOBAL_LOADING);
			if (i > offset)
			{
				md_ext[index].string_height = g_cat_conv_cntx_p->loading_height;
				md_ext[index].string_width = g_cat_conv_cntx_p->loading_width;
			}
		}
    }

	return get_size;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_conversation_exit
 * DESCRIPTION
 *  exit cat conversation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_conversation_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_cat_conv_cntx_p->text_font = NULL;
	g_cat_conv_cntx_p->checkbox_width = 0;
	g_cat_conv_cntx_p->loading_height = 0;
	g_cat_conv_cntx_p->loading_width = 0;
    g_cat_conv_cntx_p->get_item_func = NULL;
    MMI_fixed_icontext_list_menuitem.ext_flags &= ~UI_MENUITEM_EXT_INEQUAL_HEIGHT;
    MMI_fixed_list_menu.flags &= 
        ~(UI_LIST_MENU_CUSTOM_GOTO_FUNCTION | UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS | UI_LIST_MENU_DISABLE_GRID_LINE);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    wgui_cat1031_tab_exit();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cat_conversation_refresh
 * DESCRIPTION
 *  Refresh sms conversation
 *  Please notice that only those categories which do not have list effect are suggested to refresh
 * PARAMETERS
 *  number_of_items     [IN]        number of menu-items
 *  highlighted_item    [IN]        currently highlighted item
 *  get_item_func       [IN]        get item function callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cat_conversation_refresh(
        S32 number_of_items,
        S32 highlighted_item,
        CatGetAsyncItemFuncPtr get_item_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif    
    gdi_layer_lock_frame_buffer();

    gui_asyncdynamic_list_error = 0;

    MMI_fixed_list_menu.n_items = number_of_items;

    wgui_title_set_menu_shortcut_number(highlighted_item + 1);
    set_menu_item_count(number_of_items);

    g_cat_conv_cntx_p->get_item_func = get_item_func;
    init_asyncdynamic_item_buffer(number_of_items, wgui_cat_conversation_get_item, NULL);

    asyncdynamic_list_goto_item_no_redraw(highlighted_item);
	if (gui_asyncdynamic_list_error)
	{
	    gdi_layer_unlock_frame_buffer();
	    return ;
	}

    set_asyncdynamic_pop_up_descriptions(highlighted_item);

	wgui_text_menuitem_reset_scrolling();

    gdi_layer_unlock_frame_buffer();

    RedrawCategoryFunction();
    wgui_cat_show_list_menu_empty_lable();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_conversation_show
 * DESCRIPTION
 *  Displays the async dynamic list menu for conversation
 * PARAMETERS
 *  title                   	[IN]        Title for the screen
 *  left_softkey		[IN]		String ID of left softkey	
 *  right_softkey		[IN]		String ID of right softkey
 *  number_of_items	[IN]        Number of items in the menu
 *  get_item_func		[IN]        function for get item string and icon
 *  highlighted_item	[IN]        Default item to be highlighted (if there is no history)
 *  list_icon			[IN]		default list icon for calc width and height
 *  history_buffer		[IN]        History buffer
 *  category_error_flag	[IN]		error flag to show whether show success
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat_conversation_show(
			PU8 title,
			PU8 title_icon,
            U16 left_softkey,
            U16 right_softkey,
            S32 number_of_items,
            CatGetAsyncItemFuncPtr get_item_func,
            checkbox_get_image_funcptr_type get_state_func,
            checkbox_clicked_funcptr_type set_state_func,
            S32 highlighted_item,
            U16 list_icon,
            U8 *history_buffer,
            S32 *category_error_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 list_height = MMI_CONTENT_HEIGHT, iwidth, var;
	static U16 dateAndtime[] = L"88:88 AM";
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();
	gui_asyncdynamic_list_error = 0;
	dm_add_softkey_id((MMI_STR_ID)left_softkey, (MMI_STR_ID)right_softkey);
	dm_add_title((UI_string_type)title, title_icon);
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    *category_error_flag = 1;
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
    if(MMI_TRUE == wgui_icon_bar_is_created())
    {
        list_height = list_height - MMI_ICON_BAR_HEIGHT;
    }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        1,
        wgui_cat_conversation_get_item,
        NULL,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_MENUITEM_HEIGHT,
        0,
        0,
        NULL);
    
    if (!set_list_menu_category_history(MMI_CAT1031_NO_TAB_ID, history_buffer))
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }

	g_cat_conv_cntx_p->get_item_func = get_item_func;

	
    /* set check-box */
	g_cat_conv_cntx_p->checkbox_width = 0;
	if (set_state_func && get_state_func)
	{
		wgui_menuitem_set_icontext_list_checkbox_position(1, 0);
		wgui_menuitem_register_icontext_list_checkbox_callback(set_state_func, get_state_func);
		
		gui_measure_image(get_image(CHECKBOX_ON_IMAGE_ID), &iwidth, &var);
		g_cat_conv_cntx_p->checkbox_width = iwidth + 4;
	}

    /* set date and time pos */
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type)dateAndtime, &iwidth, &var);
	iwidth++;
    MMI_fixed_icontext_list_menuitem.text_fonts[0] = &MMI_small_font;
	g_cat_conv_cntx_p->loading_width = 0;
	g_cat_conv_cntx_p->loading_height = 0;
	gui_measure_string(
		(UI_string_type)GetString(STR_GLOBAL_LOADING), 
		&g_cat_conv_cntx_p->loading_width, 
		&g_cat_conv_cntx_p->loading_height);
	if (g_cat_conv_cntx_p->loading_height > var)
	{
		var = g_cat_conv_cntx_p->loading_height;
	}
	if (g_cat_conv_cntx_p->loading_width > iwidth)
	{
		iwidth = g_cat_conv_cntx_p->loading_width + 1;
	}
	set_fixed_icontext_list_text_coordinates(0,	0, 0, iwidth, var);

    /* set text infomation pos */
	g_cat_conv_cntx_p->text_font = (UI_font_type)&MMI_small_font;
	set_fixed_icontext_list_text_coordinates(1, 0, 0, MMI_content_width, MMI_MENUITEM_HEIGHT);

    /* set icon pos */
    gui_measure_image(get_image(list_icon), &iwidth, &var);
    set_fixed_icontext_list_icon_coordinates(0, 0, 0, iwidth, var);
	g_cat_conv_cntx_p->icontext_height = var + CAT_CONVERSATION_TEXT_TO_TEXT;
	
	MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_DISABLE_ICON 
		| UI_MENUITEM_DISABLE_TEXT_DISPLAY 
		| UI_MENUITEM_DISABLE_HIGHLIGHT_DISPLAY;
    MMI_fixed_icontext_list_menuitem.ext_flags |= UI_MENUITEM_EXT_INEQUAL_HEIGHT
		| UI_MENUITEM_EXT_DISABLED_SCROLL;
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_CUSTOM_GOTO_FUNCTION
		| UI_LIST_MENU_INEQUAL_HEIGHT_ITEMS
		| UI_LIST_MENU_DISABLE_GRID_LINE;

    gui_asyncdynamic_list_menu_set_goto_functions(
		&MMI_fixed_list_menu,
		wgui_cat_list_menu_goto_item,
		wgui_cat_list_menu_goto_next_item,
		wgui_cat_list_menu_goto_previous_item);
	gui_asyncdynamic_list_menu_set_item_get_height_function(
		&MMI_fixed_list_menu,
		wgui_cat_conversation_get_mi_height);
    set_fixed_icontext_list_menuitems_post_display(wgui_cat_conversation_post_display_menuitem);
#if defined(__MMI_TOUCH_SCREEN__)
	gui_asyncdynamic_list_menu_set_pen_check_bound_function(
		&MMI_fixed_list_menu,
		wgui_cat_conversation_pen_check_bound);
#endif
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
	gui_ssp_set_highlight_threshold(
		CAT_LEFT_BUBBLE_TEXT_TO_TOP + CAT_CONVERSATION_BULL_TO_TOP, 
		CAT_LEFT_BUBBLE_TEXT_TO_BOM + CAT_CONVERSATION_BULL_TO_TOP);
#endif
    MMI_fixed_list_menu.show_loading_index = -2;
 	
	g_cat_conv_cntx_p->lbub_height = list_height - (CAT_CONVERSATION_BULL_TO_TOP << 1)
		- CAT_LEFT_BUBBLE_TEXT_TO_TOP - CAT_LEFT_BUBBLE_TEXT_TO_BOM
		- g_cat_conv_cntx_p->icontext_height;
	g_cat_conv_cntx_p->rbub_height = list_height - (CAT_CONVERSATION_BULL_TO_TOP << 1)
		- CAT_RIGHT_BUBBLE_TEXT_TO_TOP - CAT_RIGHT_BUBBLE_TEXT_TO_BOM
		- g_cat_conv_cntx_p->icontext_height;

	g_cat_conv_cntx_p->rbub_width = MMI_content_width - CAT_CONVERSATION_OFFSET - 
			(CAT_CONVERSATION_BULL_TO_LEFT << 1) -
			CAT_RIGHT_BUBBLE_TEXT_TO_LEFT - CAT_RIGHT_BUBBLE_TEXT_TO_RIGHT;
	g_cat_conv_cntx_p->lbub_width = MMI_content_width - CAT_CONVERSATION_OFFSET - 
			(CAT_CONVERSATION_BULL_TO_LEFT << 1) -
			CAT_LEFT_BUBBLE_TEXT_TO_LEFT - CAT_LEFT_BUBBLE_TEXT_TO_RIGHT;

    wgui_async_list_move_multi_icontext_menu(MMI_content_x, MMI_content_y);
    wgui_async_list_resize_multi_icontext_menu(MMI_content_width, list_height);
#ifdef __MMI_ICON_BAR_SUPPORT__
#if defined(__MMI_FTE_SUPPORT__)
	if(MMI_TRUE == wgui_icon_bar_is_created())
	{
		wgui_icon_bar_register_pause_interactive_UI_callback(gui_fixed_icontext_list_menuitem_stop_scroll);
		wgui_icon_bar_register_resume_interactive_UI_callback(wgui_cat1031_iconbar_resume);
	}
#endif
#endif /*__MMI_ICON_BAR_SUPPORT__*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

	wgui_cat_setup_category_default_history(
		MMI_CAT1031_NO_TAB_ID, 
		DM_CLEAR_SCREEN_BACKGROUND, 
		wgui_cat_conversation_exit);
	dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    if (gui_asyncdynamic_list_error)
    {
        return;
    }
	*category_error_flag = 0;
}

#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1071_set_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void wgui_cat1071_set_displayable(S32 index, MMI_BOOL displayable)
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
 *  mmi_phb_viewer_thumbnail_get_displayable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat1071_get_displayable(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat1071_get_id_by_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index            [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static U16 wgui_cat1071_get_id_by_list_index(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return item_index;
}
#endif /*#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__*/



#ifdef __LOW_COST_SUPPORT_COMMON__
static S32 wgui_cat1071_get_item_func(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    CHAR *trunc_str = (CHAR*)GetString(STR_GLOBAL_LOADING);
    S32 ret;
    S32 cut_index, w;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = wgui_cat_AsyncItemFuncPtr(start_index, menu_data, data_size);
    
    w = gui_get_string_width_n(menu_data[0].item_list[0], 4);
    if(w == 0)
    {
        return ret;
    }
    /* Don't let font engine do the truncation */
    cut_index = (MMI_fixed_icontext_list_menuitem.text_coordinates[0].width / w)*4 - 6;
    if(cut_index >= 0 && cut_index < MAX_SUBMENU_CHARACTERS - 3 && gui_screen_smooth_scrolling_in_freerun())
    {
        for(i = 0; i < ret; i++)
        {
            mmi_ucs2cpy((CHAR*)&menu_data[i].item_list[0][cut_index], (CHAR*)L"...");
        }
    }
    return ret;
}
#endif
static void wgui_cat1071_tab_show(
                PU8 title,
                PU8 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                GetAsyncItemFuncPtr get_item_func,
                S32 highlighted_item,
                U16 left_icon,
                U16 right_icon,
                U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
		
    S32 left_icon_w = 0, left_icon_h = 0, right_icon_w = 0, right_icon_h = 0;
    S32 text_w = 0, text_0_h = 0, text_1_h = 0;
    S32 x, y;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
    	wgui_thumbnail_register_set_displayable_func(wgui_cat1071_set_displayable);
    	wgui_thumbnail_register_get_displayable_func(wgui_cat1071_get_displayable);
    	wgui_thumbnail_register_get_store_id_func(wgui_cat1071_get_id_by_list_index);
        wgui_cat_thumbnail_init(number_of_items);
    }
    #endif
    gui_asyncdynamic_list_error = 0;
    gdi_layer_lock_frame_buffer();
    dm_add_softkey_id(left_softkey, right_softkey);
    dm_add_title((UI_string_type)title, title_icon);
#ifdef __LOW_COST_SUPPORT_COMMON__
    wgui_cat_AsyncItemFuncPtr = get_item_func;
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        2,
        wgui_cat1071_get_item_func,
        NULL,
        highlighted_item,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        MMI_CAT1071_ID,
        history_buffer);
#else
    wgui_async_list_create_multi_icontext_menu(
        number_of_items,
        2,
        2,
        get_item_func,
        NULL,
        highlighted_item,
        MMI_MULTIROW_MENUITEM_HEIGHT,
        WGUI_LIST_MENU_MULTIROW,
        MMI_CAT1071_ID,
        history_buffer);
 #endif   
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
        set_fixed_icontext_list_menuitems_post_display(wgui_cat_thumbnail_post_display_callback);
    }
#endif
    MMI_fixed_icontext_list_menuitem.flags |= UI_MENUITEM_AUTO_CHOOSE_MARQUEE;  
    
    gui_measure_image(get_image(left_icon), &left_icon_w, &left_icon_h);
    gui_measure_image(get_image(right_icon), &right_icon_w, &right_icon_h);
    if(left_icon_w == 0)
    {
        left_icon_w = (MMI_MULTIROW_MENUITEM_HEIGHT*2)/3;
        left_icon_h = left_icon_w;
    }
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    wgui_cat_thumbnail_set_image_box_size(left_icon_w, left_icon_h);
#endif
    x = GUI_ICONTEXT_MENUITEM_ICON_X;
    y = (MMI_MULTIROW_MENUITEM_HEIGHT - left_icon_h)>>1;
    set_fixed_icontext_list_icon_coordinates(0, x, y, left_icon_w, left_icon_h);

    x = MMI_content_width - MMI_fixed_list_menu.vbar.width - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - right_icon_w - 1;
    y = (MMI_MULTIROW_MENUITEM_HEIGHT - right_icon_h)>>1;
    set_fixed_icontext_list_icon_coordinates(1, x, y, right_icon_w, right_icon_h);

    text_w = x - GUI_ICONTEXT_MENUITEM_ICON_X - left_icon_w - WGUI_CATE_LIST_MULTI_ICONTEXT_COLUMN_GAP*2;
    x = GUI_ICONTEXT_MENUITEM_ICON_X + left_icon_w + WGUI_CATE_LIST_MULTI_ICONTEXT_COLUMN_GAP;
    gui_set_font(&MMI_medium_font);
    text_0_h = gui_get_character_height();
    gui_set_font(&MMI_small_font);
    text_1_h = gui_get_character_height();
    y = (MMI_MULTIROW_MENUITEM_HEIGHT - text_0_h - text_1_h - WGUI_CATE_LIST_MULTI_ICONTEXT_ROW_GAP)>>1;
    set_fixed_icontext_list_text_coordinates(0, x, y, text_w, text_0_h);

    y += text_0_h + WGUI_CATE_LIST_MULTI_ICONTEXT_ROW_GAP;
    set_fixed_icontext_list_text_coordinates(1, x, y, text_w, text_1_h);

    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        wgui_cat_disable_list_menu_empty_lable();
    }
    if(wgui_cat_is_user_empty_string())
    {
        disable_fixed_list_show_empty();
    }

    wgui_cat_setup_category_default_history(MMI_CAT1071_ID, DM_CLEAR_SCREEN_BACKGROUND, wgui_cat1031_tab_exit);
    dm_redraw_category_screen();
    wgui_cat_show_list_menu_empty_lable();
    gdi_layer_unlock_frame_buffer();
    #ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    if(g_cat_list_is_show_thumbnail)
    {
        wgui_cat_thumbnail_post_init(number_of_items);
    }
    #endif
    if(gui_asyncdynamic_list_error)
    {
        return;
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

void wgui_cat1071_show(
        PU8 title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        S32 highlighted_item,
        U16 left_icon,
        U8 *history_buffer)
{
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    g_cat_list_is_show_thumbnail = MMI_TRUE;
#endif
    wgui_cat1071_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        get_item_func,
        highlighted_item,
        left_icon,
        0,
        history_buffer);
}

void wgui_cat1072_show(
        PU8 title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        S32 highlighted_item,
        U16 left_icon,
        U16 right_icon,
        U8 *history_buffer)
{
#ifdef __MMI_PHONEBOOK_LIST_THUMBNAIL__
    g_cat_list_is_show_thumbnail = MMI_TRUE;
#endif
    wgui_cat1071_tab_show(
        title,
        title_icon,
        left_softkey,
        right_softkey,
        number_of_items,
        get_item_func,
        highlighted_item,
        left_icon,
        right_icon,
        history_buffer);
}

