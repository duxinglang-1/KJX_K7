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
 *    commonscreens.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   for input method menu and symbol picker screen
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*  Include
*****************************************************************************/
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#endif 
#include "IMERes.h"
#include "CommonScreens.h"
#include "ProfilesSrvGprot.h"
#include "CommonScreensProt.h"
#include "immprot.h"
#include "imeGprot.h"
#include "MenuCuiGprot.h"
#include "mmi_rp_srv_editor_def.h"
#include "Mmi_frm_scenario_gprot.h"
#include "Imc.h"
#if defined (__MMI_INDIC_ALG__)
#include "IndicEngineGprot.h"
#endif

#ifdef __MMI_CLIPBOARD__
#include "wgui_ems.h"
#include "mmi_rp_srv_editor_def.h"
#endif /* __MMI_CLIPBOARD__ */

#ifdef __MMI_VUI_ENGINE__
#include "framework\vadp_p2v_uc.h"
#endif
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "CommonScreensResDef.h"
#include "wgui_inputs.h"
#include "gui_data_types.h"
#include "gui.h"
#include "GlobalResDef.h"
#include "wgui_inline_edit.h"
#include "gui_config.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_list.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "IdleAppResDef.h"
#include "ScreenRotationGprot.h"
#include "gui_effect_oem.h"
#include "wgui_categories_popup.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "custom_events_notify.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "gdi_include.h"
#include "wgui_categories.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_typedef.h"
#include "CustMenuRes.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "lcd_sw_inc.h"
#include "CustDataProts.h"
#include "CustDataRes.h"
#include "gui_ems.h"
#include "mmi_rp_app_idle_def.h"
#include "PixcomFontEngine.h"
#include "vrt_canvas.h"
#include "wgui_include.h"
#include "wgui_categories_inputs.h"
#include "GlobalMenuItems.h"
#include "commonscreens.h"
#include "commonscreensResDef.h"
#include "mmi_frm_prot.h"
#include "GpioSrvGprot.h"
#if defined(__MMI_IME_PLUG_IN_SETTING__)
#include "ImeSDKGprot.h"
#endif

#include "Wgui_fixed_menuitems.h"
#include "InlineCuiGprot.h"
#include "mmi_rp_app_uiframework_def.h"
#ifdef __MMI_FRM_HISTORY__
#define __MMI_CASCADING_MENU_HISTORY__
#endif /* __MMI_FRM_HISTORY__ */

/*****************************************************************************
 *  Define
 *****************************************************************************/

/* apply new popup interface or not */
#define __MMI_POPUP_NEW_INTERFACE__


#define SYMBOL_PICKER_DEFAULT_SYMBOLS            36
#define SYMBOL_PICKER_BENGALI_SYMBOLS  48
#define SYMBOL_PICKER_GURAJATI_SYMBOLS 46
#define SYMBOL_PICKER_LF_INDEX               35
#define SYMBOL_PICKER_SPACE_INDEX            34
#define SYMBOL_PICKER_THAI_SYMBOLS                42

#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
#define SYMBOL_PICKER_MYANMAR_SYMBOLS                43
#endif 

#define SYMBOL_PICKER_MAX_CHINESE_SYMBOLS    28
#define SYMBOL_PICKER_CHINESE_LF_INDEX       27
#define SYMBOL_PICKER_CHINESE_SPACE_INDEX    26
#define SPACE_SYMBOL (0x20)
#define NEWLINE_SYMBOL (0x0a)
#define EURO_SYMBOL (0x20ac)

/*****************************************************************************
 *  Typedef
 *****************************************************************************/
U16 pen_speed;
U16 pen_color;
#if defined (__MMI_IME_V3__)
MMI_BOOL is_hw_enable ;
U8 stroke_width ;
MMI_BOOL is_follow_vk ;
extern void mmi_ime_settings_back(void);
extern mmi_ret mmi_ime_settings_input_mode_screen_popup_handler_for_sg(mmi_event_struct *param);
#endif
static MMI_ID g_hw_inlinecui_gid;
typedef struct
{
    U32 input_type;
    void (*input_method_screen_close_function)(void);
    void (*input_method_screen_entry_function)(void);
    void (*input_method_screen_exit_function)(void);
    mmi_ime_common_scr_entry_exit_callback entry_callback;
    mmi_ime_common_scr_entry_exit_callback exit_callback;
    mmi_imm_input_mode_enum input_mode;
    mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];
    mmi_imm_support_writing_lang_enum writing_lang; 
    S16 input_ext_type;   
}mmi_common_screen_input_mode_list_history_struct, *mmi_common_screen_input_mode_list_history_struct_p;

typedef struct
{
    void (*input_method_screen_close_function)(void);
    void (*input_method_screen_entry_function)(void);
    void (*input_method_screen_exit_function)(void);
    void (*symbol_table_screen_entry_callback)(void);
    void (*symbol_table_screen_exit_callback)(void);
    U8** default_symbol_table;
    S32 default_max_num;
    S32 symbol_table_stack_top;
    mmi_ime_symbol_table_callback prepare_symbol_table;
    mmi_ime_common_scr_entry_exit_callback entry_callback;
    mmi_ime_common_scr_entry_exit_callback exit_callback;
    const U8 *symbol_list[SYMBOL_PICKER_MAX_SYMBOLS];
}mmi_common_screen_symbol_picker_history_struct, *mmi_common_screen_symbol_picker_history_struct_p;

typedef union
{
    mmi_common_screen_input_mode_list_history_struct input_method_history;
    mmi_common_screen_symbol_picker_history_struct   symbol_picker_history;
} mmi_common_screen_history_union;
 

typedef struct
{
    MMI_BOOL is_shown;
    keypadtype_enum menu_id;
}mmi_ime_commonscreens_keyboardtype_struct;

/*****************************************************************************
 * Global variables
 *****************************************************************************/

// __CUSTPACK_MULTIBIN     Terry   BEGIN
extern const sIMEModeDetails *gIMEModeArray;
extern const sIMEModeDetails *gIMEQSearchModeArray;
/* __CUSTPACK_MULTIBIN     Terry   END */

extern mmi_editor_inoutbox_enum MMI_current_input_box_type;
extern void (*wgui_inline_edit_DONE_function) (void);
extern void  mmi_imm_wlang_change_handler( S32 index);
extern U16 mmi_imm_is_curr_allowed_wlang(S32 wlang);
extern mmi_imc_entry_add_new_word_screen_with_sg(mmi_id g_id);
extern void mmi_ime_commonscreens_popup_lsk_done_hdlr(void);
extern mmi_imc_post_process_data_struct g_ime_post_process_data;
/*****************************************************************************
 * External function
 *****************************************************************************/

#if defined(__MMI_TOUCH_SCREEN__)
extern MMI_BOOL     mmi_imc_is_handwriting_disabled(void);
extern void mmi_imc_set_hw_type_validity(MMI_BOOL v);
extern MMI_BOOL mmi_imc_get_hw_type_validity(void);
#endif
extern MMI_BOOL vm_frm_is_active(void);
extern MMI_BOOL mmi_imm_test_input(UI_string_type cand, S32 cand_len);
extern void leave_full_screen(void);
extern void goto_demo_under_construction(void);
extern void SetActiveScreenId(U16 scrnId);
extern void SetExitScreenId(U16 scrnId);

/* IME SETTINGS */
extern void mmi_imesettings_save_screen(void);
void mmi_ime_commonscreens_screen_close(void);
MMI_ID g_active_ime_group ;
MMI_ID g_active_ime_screen ;
mmi_ret mmi_ime_commonscreens_screen_close_after_popup(mmi_event_struct *param);
void   mmi_ime_commonscreens_screen_close_saved();
void mmi_ime_save_screen();

#if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
void mmi_ime_commonscreens_entry_main_language_screen(void);
void mmi_ime_commonscreens_entry_main_language_screen_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_main_language_screen(void);
void mmi_ime_writinglanguage_main_language_lsk_handler(void);
#if defined(__MMI_MIXED_LANG_SUPPORT__)
/* Writing languages screen  if mixed language is enabled*/
void mmi_ime_commonscreens_entry_writing_language_screen();
void mmi_ime_commonscreens_entry_writing_language_screen_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_writing_language_screen();
#endif
#endif

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)

/* IME options screen*/
void mmi_ime_commonscreens_entry_imeoptions(void);
void mmi_ime_commonscreens_entry_imeoptions_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_imeoptions(void);

#if defined(__MMI_MIXED_LANG_SUPPORT__)
/* Sub language screen */
void mmi_ime_commonscreens_entry_sub_language_screen(void);
void mmi_ime_commonscreens_entry_sub_language_screen_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_sub_language_screen(void);
void mmi_ime_writinglanguage_sub_language_lsk_handler();
#endif
#if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
/* Input pattern screen */
void mmi_ime_commonscreens_entry_keyboardtype(void);
void mmi_ime_commonscreens_entry_keyboardtype_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_keyboardtype(void);
void mmi_ime_commonscreens_keyboard_lsk_handler(void);
void mmi_ime_commonscreens_keyboard_pop_up_handler();
mmi_ret mmi_ime_commonscreens_keyboard_pop_up_handler_for_sg(mmi_event_struct *param);
#endif


/* advanced options screen */
#if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
MMI_BOOL  g_advanced_settings_changed = MMI_FALSE ;
void  mmi_ime_commonscreens_advancedoptions_save();
void mmi_ime_commonscreens_entry_advancedoptions(void);
void mmi_ime_commonscreens_entry_advancedoptions_with_sg(mmi_id g_id);
void mmi_ime_commonscreens_exit_advancedoptions(void);
void mmi_ime_commonscreens_advancedoptions_csk_handler(void);
#endif
/* Main language /writing language if mixed lang is off */
void mmi_ime_writinglanguage_main_language_csk_handler();
void mmi_ime_commonscreens_writing_language_screen_popup_handler();
#endif
extern void mmi_frm_scrn_set_active_input_buf_size (U16 input_buf_size); /* For removing build warning */
/*****************************************************************************
 * Local variables
 *****************************************************************************/

    MMI_BOOL g_ime_commonscreens_is_in_java_screens = MMI_FALSE;

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    U8 g_advanced_settings_menustates[4] ={0,0,0,0};
	U8 g_advanced_settings_menustates_first_enter = 0;
    U8 g_input_pattern_settings_menustates[4] ={0,0,0,0};
   // static U8 g_current_writinglang_index = 0;
    //static U8 currWritingSubLangIdx = 0;
    #if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
    static S32 g_current_highlighted_advancedimesetting = 0;
    #endif 
   // static S32 g_current_highlighted_keyboardtype= 0;
#if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
    mmi_ime_commonscreens_keyboardtype_struct g_mmi_ime_commonscreens_keypad_menu[COMMONSCREENS_KEYPAD_TOTAL];
#endif
    
#endif
void (*InputMethodScreenCloseFunction) (void) = UI_dummy_function;
void (*InputMethodScreenEntryCallback) (void) = UI_dummy_function;
void (*InputMethodScreenExitCallback) (void) = UI_dummy_function;
void (*SymbolTableScreenEntryCallback) (void) = UI_dummy_function;
void (*SymbolTableScreenExitCallback) (void) = UI_dummy_function;
U16 gInputMethodAndDoneCaptionIcon = 0;
static U8 is_popup_allow = POPUP_ALL_ON;    /* it can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON, or POPUP_ALL_ON */
U8 popupToneId = 0; /* 121605 popup tone Calvin */
mmi_ime_symbol_table_callback g_mmi_ime_prepare_symbol_table[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM];
S32 g_mmi_ime_symbol_table_stack_top = -1;
U8** g_mmi_ime_default_symbol_table[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM];
S32 g_mmi_ime_default_symbol_table_max_num[SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM]; 

static mmi_common_screen_history_union mmi_common_screen_history;

void (*g_mmi_ime_common_scr_entry_callback) (U16,U16) = NULL;

void (*g_mmi_ime_common_scr_exit_callback) (U16,U16) = NULL;


const U16 gIndexIconsImageList[] = 
{
    IMG_GLOBAL_L1,
    IMG_GLOBAL_L2,
    IMG_GLOBAL_L3,
    IMG_GLOBAL_L4,
    IMG_GLOBAL_L5,
    IMG_GLOBAL_L6,
    IMG_GLOBAL_L7,
    IMG_GLOBAL_L8,
    IMG_GLOBAL_L9,
    IMG_GLOBAL_L10,
    IMG_GLOBAL_L11,
    IMG_GLOBAL_L12,
    IMG_GLOBAL_L13,
    IMG_GLOBAL_L14,
    IMG_GLOBAL_L15,
    IMG_GLOBAL_L16,
    IMG_GLOBAL_L17,
    IMG_GLOBAL_L18,
    IMG_GLOBAL_L19,
    IMG_GLOBAL_L20,
    IMG_GLOBAL_L21,
    IMG_GLOBAL_L22,
    IMG_GLOBAL_L23,
    IMG_GLOBAL_L24,
    IMG_GLOBAL_L25,
    IMG_GLOBAL_L26,
    IMG_GLOBAL_L27,
    IMG_GLOBAL_L28,
    IMG_GLOBAL_L29,
    IMG_GLOBAL_L30
};

const U16 gTwoLineIndexIconsImageList[] = 
{
    IMG_GLOBAL_L1, 0,
    IMG_GLOBAL_L2, 0,
    IMG_GLOBAL_L3, 0,
    IMG_GLOBAL_L4, 0,
    IMG_GLOBAL_L5, 0,
    IMG_GLOBAL_L6, 0,
    IMG_GLOBAL_L7, 0,
    IMG_GLOBAL_L8, 0,
    IMG_GLOBAL_L9, 0,
    IMG_GLOBAL_L10, 0,
    IMG_GLOBAL_L11, 0,
    IMG_GLOBAL_L12, 0,
    IMG_GLOBAL_L13, 0,
    IMG_GLOBAL_L14, 0,
    IMG_GLOBAL_L15, 0,
    IMG_GLOBAL_L16, 0,
    IMG_GLOBAL_L17, 0,
    IMG_GLOBAL_L18, 0,
    IMG_GLOBAL_L19, 0,
    IMG_GLOBAL_L20, 0,
    IMG_GLOBAL_L21, 0,
    IMG_GLOBAL_L22, 0,
    IMG_GLOBAL_L23, 0,
    IMG_GLOBAL_L24, 0,
    IMG_GLOBAL_L25, 0,
    IMG_GLOBAL_L26, 0,
    IMG_GLOBAL_L27, 0,
    IMG_GLOBAL_L28, 0,
    IMG_GLOBAL_L29, 0,
    IMG_GLOBAL_L30, 0
};


#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG]; 
#endif

const U8 *SymbolPickerSymbols[SYMBOL_PICKER_DEFAULT_SYMBOLS] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    /* (U8*)"\xa2\0\0", */
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
    /* (U8*)" \0\0", */
};

U8 g_mmi_ime_ap_desired_symbol[SYMBOL_PICKER_MAX_SYMBOLS* 2 * sizeof(UI_character_type)]; /* symbol and null end */

#if defined(__MMI_LANG_BENGALI__)
const U8 *SymbolPickerBengaliSymbols[SYMBOL_PICKER_BENGALI_SYMBOLS] = 
{ 
	(U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    /* (U8*)"\xa2\0\0", */
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
	(U8 *) "\x64\x09\0\0",
	(U8 *) "\x65\x09\0\0",
	(U8 *) "\xf2\x09\0\0",
	(U8 *) "\xf3\x09\0\0",
	(U8 *) "\xfa\x09\0\0",
	(U8 *) "\xab\0\0",
	(U8 *) "\xbb\0\0",
	(U8 *) "\x5e\0\0",
	(U8 *) "\xb0\0\0",
	(U8 *) "\x7c\0\0",
	(U8 *) "\x60\0\0",
	(U8 *) "\xb7\0\0",
	(U8 *) "\n\0\0",
	/* (U8*)" \0\0", */
};

#endif 


#if defined(__MMI_LANG_GUJARATI__)
const U8 *SymbolPickerGujaratiSymbols[SYMBOL_PICKER_GURAJATI_SYMBOLS] = 
{ 
	(U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    /* (U8*)"\xa2\0\0", */
    (U8 *) "\xac\x20\0\0",
	(U8 *) "\xa8\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
	(U8 *) "\x64\x09\0\0",
	(U8 *) "\x65\x09\0\0",
	(U8 *) "\xab\0\0",
	(U8 *) "\xbb\0\0",
	(U8 *) "\x5e\0\0",
	(U8 *) "\xb0\0\0",
	(U8 *) "\x7c\0\0",
	(U8 *) "\x60\0\0",
	(U8 *) "\xb7\0\0",
	(U8 *) "\n\0\0",
	/* (U8*)" \0\0", */
};
#endif 

#if defined(__MMI_LANG_ARABIC__)
const U8 *SymbolPickerArabicSymbols[SYMBOL_PICKER_DEFAULT_SYMBOLS] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x0c\06\0\0", /* Arabic Comma */
    (U8 *) "\x1f\x06\0\0", /* Arabic Question Mark */
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) ")\0\0",
    (U8 *) "(\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) "\x1b\x06\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) ">\0\0",
    (U8 *) "<\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "]\0\0",
    (U8 *) "[\0\0",
    (U8 *) "}\0\0",
    (U8 *) "{\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
};

#endif 

#if defined(__MMI_LANG_THAI__)
const U8 *SymbolPickerThaiSymbols[SYMBOL_PICKER_THAI_SYMBOLS] = 
{
    (U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",
    (U8 *) "\xa3\0\0",
    (U8 *) "\x24\0\0",
    (U8 *) "\xa5\0\0",
    (U8 *) "\xa7\0\0",
    (U8 *) "\xac\x20\0\0",
    (U8 *) "\xa4\0\0",
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
    (U8 *) "\x3f\x0e\0",
	(U8 *) "\x46\x0e\0\0",
	(U8 *) "\x2f\x0e\0\0",
	(U8 *) "\x4f\x0e\0\0",
    (U8 *) "\x5a\x0e\0",
    (U8 *) "\x5b\x0e\0",
};

#endif

#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
const U8 *SymbolPickerMyanmarSymbols[SYMBOL_PICKER_MYANMAR_SYMBOLS] = 
{
    (U8 *) "#\x10\0",
    (U8 *) "$\x10\0",
    (U8 *) "%\x10\0",
    (U8 *) "&\x10\0",
    (U8 *) "'\x10\0",
    (U8 *) ")\x10\0",
    (U8 *) "*\x10\0",
    (U8 *) "?\x10\0",
    (U8 *) "L\x10\0",
    (U8 *) "M\x10\0",
    (U8 *) "N\x10\0",
    (U8 *) "O\x10\0",
    (U8 *) "\x2e\0\0",
    (U8 *) "\x2c\0\0",
    (U8 *) "?\0\0",
    (U8 *) "!\0\0",
    (U8 *) "\'\0\0",
    (U8 *) "\"\0\0",
    (U8 *) "(\0\0",
    (U8 *) ")\0\0",
    (U8 *) "@\0\0",
    (U8 *) "\\\0\0",
    (U8 *) "/\0\0",
    (U8 *) ":\0\0",
    (U8 *) "_\0\0",
    (U8 *) ";\0\0",
    (U8 *) "+\0\0",
    (U8 *) "-\0\0",
    (U8 *) "*\0\0",
    (U8 *) "=\0\0",
    (U8 *) "%\0\0",
    (U8 *) "&\0\0",
    (U8 *) "<\0\0",
    (U8 *) ">\0\0",    
    (U8 *) "\x24\0\0",    
    (U8 *) "[\0\0",
    (U8 *) "]\0\0",
    (U8 *) "{\0\0",
    (U8 *) "}\0\0",
    (U8 *) "~\0\0",
    (U8 *) "#\0\0",
    (U8 *) " \0\0",
    (U8 *) "\n\0\0",
};
#endif

const U8 *SymbolPickerChineseSymbols[SYMBOL_PICKER_MAX_CHINESE_SYMBOLS] = 
{
    (U8 *) "\x0c\xff\0\0",
    (U8 *) "\x02\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x61\xff\0\0", */
    (U8 *) "\x01\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x64\xff\0\0", */
    (U8 *) "\x1a\xff\0\0",
    (U8 *) "\x1b\xff\0\0",
    (U8 *) "\x1f\xff\0\0",
    (U8 *) "\x26\x20\0\0",
    (U8 *) "\x01\xff\0\0",
    (U8 *) "\x0a\x30\0\0",
    (U8 *) "\x0b\x30\0\0",
    (U8 *) "\x0e\x30\0\0",
    (U8 *) "\x0f\x30\0\0",
    (U8 *) "\x1c\x20\0\0",
    (U8 *) "\x1d\x20\0\0",
    (U8 *) "\x08\xff\0\0",
    (U8 *) "\x09\xff\0\0",
    (U8 *) "\x0c\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x62\xff\0\0", */
    (U8 *) "\x0d\x30\0\0",  /* using CJK defned value instead of full-width defined value(U8*)"\x63\xff\0\0", */
    (U8 *) "\x18\x20\0\0",
    (U8 *) "\x19\x20\0\0",
    (U8 *) "\x0e\xff\0\0",
    (U8 *) "\x1c\xff\0\0",
    (U8 *) "\x1e\xff\0\0",
    (U8 *) "\x5e\xff\0\0",
    (U8 *) "\x3b\xff\0\0",
    (U8 *) "\x3d\xff\0\0",
    (U8 *) "\x20\x00\0\0",
    (U8 *) "\n\0\0",
};


const U8 SymbolPickerLFString[] = {0x85, 0, '\0', 0};
const U8 SymbolPickerSpaceString[] = {0x86, 0, '\0', 0};
const U8 *SymbolPickerDisplaySymbols[SYMBOL_PICKER_MAX_SYMBOLS];

const U8 *SymbolPickerDisplayChineseSymbols[SYMBOL_PICKER_MAX_CHINESE_SYMBOLS];


/*****************************************************************************
 * Local Function
 *****************************************************************************/
void (*wgui_common_screen_inline_edit_DONE_function) (void);
void mmi_frm_go_back_2_history(void);
void mmi_frm_go_back_2_history_sg(void);
S32 InputMethodSetKeyHandler(S32 index);
mmi_imm_input_mode_enum GetInputModeByIndex(S32 index);
static mmi_ret mmi_common_screen_symbol_picker_key_proc(mmi_event_struct *evt);
static mmi_ret mmi_common_screen_symbol_picker_from_menu_key_proc(mmi_event_struct *evt);
mmi_ret mmi_ime_commonscreens_screen_close_after_popup2(mmi_event_struct *param);


extern void handle_inline_full_screen_edit_complete(void);
extern void handle_inline_full_screen_edit_cancel(void);
extern wgui_inline_item *current_wgui_inline_item;
extern S32 wgui_n_inline_items;
extern S32 wgui_inline_item_highlighted_index;

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_2_screen_close_upto_inputmethod
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_2_screen_close_including_inputmethod()
{
		mmi_frm_scrn_multiple_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id(),
                                MMI_TRUE, 2, 0, 0);
}
/*****************************************************************************
 * FUNCTION
 *  ConfirmInlineFullScreenEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConfirmInlineFullScreenEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if ((current_wgui_inline_item == NULL) || (wgui_n_inline_items <= 0))
    {
        mmi_frm_scrn_close_active_id();
    }
    handle_inline_full_screen_edit_complete();
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  CancelInlineFullScreenEdit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CancelInlineFullScreenEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    if ((current_wgui_inline_item == NULL) || (wgui_n_inline_items <= 0))
    {
        mmi_frm_scrn_close_active_id();
    }
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
#endif 
    handle_inline_full_screen_edit_cancel();
}


/*****************************************************************************
 * Pop-up common screens
 *****************************************************************************/
FuncPtr PopupFunc = NULL;
FuncPtr PopupFunc_interr = NULL;
BOOL popUpTimerFlag = FALSE;
static MMI_BOOL g_mmi_popup_keydown_Flag = MMI_FALSE;
static srv_prof_tone_enum g_mmi_popup_toneId;
static mmi_ret mmi_display_popup_proc(mmi_event_struct *evt);

/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void mmi_display_popup_rotated(UI_string_type string, mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.rotation = rotation;
    mmi_popup_display(string, event_id, &arg);
}
#endif /* __MMI_SCREEN_ROTATE__ */


/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup(UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display(string, event_id, NULL);
}


/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup_with_flag(UI_string_type string, mmi_event_notify_enum event_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    if (flag & MMI_POPUP_DISABLE_SLIDING_EFFECT)
    {
        arg.f_sliding_effect = MMI_FALSE;
    }
    if (flag & MMI_POPUP_DISABLE_SHOW_ICON)
    {
        arg.f_msg_icon = MMI_FALSE;
    }
    mmi_popup_display(string, event_id, &arg);

}

/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup_with_tone(UI_string_type string, mmi_event_notify_enum event_id, srv_prof_tone_enum tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.f_play_tone = MMI_FALSE;
    mmi_popup_display(string, event_id, &arg);
}

/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void mmi_display_popupcallback_rotated(UI_string_type string, mmi_event_notify_enum event_id, FuncPtr f,
                         mmi_frm_screen_rotate_enum rotation)
{
    mmi_popup_property_struct arg;

    mmi_popup_property_init(&arg);
    arg.callback = mmi_alert_normal_exit_helper;
    arg.user_tag = (void *)f;
    arg.rotation = rotation;
    mmi_popup_display(string, event_id, &arg);
}
#endif


/* For detail description, please refer to CommonScreens.h */
void mmi_display_popupcallback(UI_string_type string, mmi_event_notify_enum event_id, FuncPtr f)
{
    mmi_popup_property_struct arg;

    mmi_popup_property_init(&arg);
    arg.callback = mmi_display_popup_proc;
    PopupFunc = f;
    mmi_popup_display(string, event_id, &arg);
}

/* For detail description, please refer to CommonScreens.h */
void mmi_display_popupcallback_ext(UI_string_type string, mmi_event_notify_enum event_id, FuncPtr f, FuncPtr interr_callback)
{
    mmi_popup_property_struct arg;

    mmi_popup_property_init(&arg);
    arg.callback = mmi_display_popup_proc;
    PopupFunc = f;
    PopupFunc_interr = interr_callback;
    mmi_popup_display(string, event_id, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_display_popupconfirm
 * DESCRIPTION
 *  Exit function for DisplayPopupConfirm()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
static void mmi_exit_display_popupconfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResetCenterSoftkey();

    if (g_mmi_popup_toneId)
    {
        srv_prof_stop_tone(g_mmi_popup_toneId);
        g_mmi_popup_toneId = SRV_PROF_TONE_NONE;
    }
}

static void mmi_display_popup_confirm_internal(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon,
                U16 CSK_str, U16 CSK_img, UI_string_type string, mmi_event_notify_enum event_id, U8 rotation, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    srv_prof_tone_enum tone_id;
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_display_popup_proc, NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	if(mmi_frm_scrn_enter(group_id, SCR_CONFIRM_SCREEN, mmi_exit_display_popupconfirm, (FuncPtr)mmi_display_popup_confirm_internal, MMI_FRM_FG_ONLY_SCRN) == MMI_FALSE)
    {
        return;
    }
#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate((mmi_frm_screen_rotate_enum)rotation);
#endif 

    if ((CSK_str != 0) || (CSK_img != 0))
    {
        EnableCenterSoftkey(CSK_str, CSK_img);
    }

    if(flag & MMI_POPUP_DISABLE_SLIDING_EFFECT)
    {
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
    }

    if(flag & MMI_POPUP_DISABLE_SHOW_ICON)
    {
        image_id = 0;
    }
    else
    {
        image_id = mmi_get_event_based_image(event_id);
    }
    tone_id = mmi_get_event_based_sound(event_id);

    ShowCategory163Screen(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, string, image_id, NULL);
    g_mmi_popup_toneId = tone_id;
    if (g_mmi_popup_toneId)
        srv_prof_play_tone(g_mmi_popup_toneId, NULL);
}


/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void mmi_display_popup_confirm_rotated(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, UI_string_type message,
                           mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation)
{
    mmi_display_popup_confirm_internal(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, 0, 0, message, event_id, (U8)rotation, 0);
}
#endif /* __MMI_SCREEN_ROTATE__ */ 


/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup_confirm(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, UI_string_type message,
                    mmi_event_notify_enum event_id)
{
    mmi_display_popup_confirm_internal(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, 0, 0, message, event_id, 0, 0);
}

/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup_confirm_with_flag(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, UI_string_type message,
                    mmi_event_notify_enum event_id, U32 flag)
{
    mmi_display_popup_confirm_internal(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, 0, 0, message, event_id, 0, flag);
}

/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void mmi_display_popup_confirmext_rotated(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, U16 CSK_str, U16 CSK_img, UI_string_type message,
                           mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation)
{
    mmi_display_popup_confirm_internal(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, CSK_str, CSK_img, message, event_id, (U8)rotation, 0);
}
#endif /* __MMI_SCREEN_ROTATE__ */ 

/* For detail description, please refer to CommonScreens.h */
void mmi_display_popup_confirmext(UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, U16 CSK_str, U16 CSK_img, UI_string_type message,
                    mmi_event_notify_enum event_id) 
{
    mmi_display_popup_confirm_internal(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, CSK_str, CSK_img, message, event_id, 0, 0);
}

/*****BEGIN SCREEN GROUP *******/

/* popupcallback static function */
static void mmi_exit_display_popupcallback_with_sg(void);
static void mmi_popupcallback_send_event(
                mmi_id parent_id,
                void *user_tag, 
                mmi_proc_func popup_callback_receiver_func,
                void *user_data,
                mmi_common_screen_event_enum event_id, 
                mmi_popupcallback_result_enum result);
static void mmi_popupcallback_post_event(
                mmi_id parent_id,
                void *user_tag, 
                mmi_proc_func popup_callback_receiver_func,
                void *user_data,
                mmi_common_screen_event_enum event_id,
                mmi_popupcallback_result_enum result);

static void mmi_popupcallback_send_receiver(void);

static void mmi_popupcallback_timer_over_with_sg(void);
#if (defined __MMI_TOUCH_SCREEN__)
static MMI_BOOL mmi_popupcallback_pen_down_hdlr_with_sg(mmi_pen_point_struct point);
#endif
static void mmi_popupcallback_keydown_handler_with_sg(void);
static void mmi_popupcallback_close_by_press_anykey_with_sg(void);
static void mmi_entry_popupcallback_with_sg(void);
static void mmi_exit_display_popupcallback_with_sg(void);
static MMI_BOOL mmi_display_popupcallback_with_sg_internal(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, 
                 mmi_frm_screen_rotate_enum rotation, void *user_tag, mmi_proc_func receiver_proc, void *user_data, U32 flags);

static mmi_ret mmi_popup_proc (mmi_event_struct *evt);


/* popup sg context */
typedef struct _popup_ctx
{
    mmi_id parent_id;
    mmi_id screen_id;
    UI_string_type string;
    mmi_event_notify_enum event_id;
    mmi_frm_screen_rotate_enum rotation;
    void *user_data;
    void *user_tag;
    U32 flags;
}popup_ctx;

static popup_ctx g_popup_ctx = {0};
static mmi_proc_func g_popupcallback_receiver_func;
static MMI_BOOL g_popupcallback_timer_flag = MMI_FALSE; /* timer out or tone out flag*/
static MMI_BOOL g_popup_sender_done = MMI_FALSE;

typedef struct {
  MMI_EVT_PARAM_HEADER
  mmi_id parent_id;
  mmi_id screen_id;
} mmi_event_popoupcallback_post_struct;


typedef struct {
  MMI_EVT_PARAM_HEADER
  mmi_id parent_id;
  mmi_frm_screen_rotate_enum rotation;
  mmi_event_notify_enum notify_event_id;
  MMI_BOOL notify_receiver_proc;            /* TRUE: send event to receiver_proc with receiver_user_data; FALSE: send event to parent group proc with receiver_user_data; */
  mmi_proc_func receiver_proc;
  void *receiver_user_data;
  U32 flags;
  WCHAR string[MAX_SUBMENU_CHARACTERS+1];

} mmi_event_popupcallback_req_struct;


static MMI_BOOL mmi_display_popupcallback_with_sg_internal_show(mmi_id parent_id, void *user_tag, UI_string_type string, mmi_event_notify_enum event_id, 
                 mmi_frm_screen_rotate_enum rotation, mmi_proc_func receiver_proc, void *user_data, U32 flags);
static void mmi_popupcallback_init_ctx(
                mmi_id parent_id,
                mmi_id screen_id,
                UI_string_type string,
                mmi_event_notify_enum event_id,
                mmi_frm_screen_rotate_enum rotation,
                void *user_data,
                void *user_tag,
                U32 flags);




/*****************************************************************************
 * FUNCTION
 *  mmi_popup_proc
 * DESCRIPTION
 *  popup timerout proc function.
 * PARAMETERS
 *  evt     [IN] event content
 * RETURNS
 *  mmi_ret  [OUT]
 *****************************************************************************/
static mmi_ret mmi_popup_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popupcallback_req_struct  *popup_req = (mmi_event_popupcallback_req_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_POPUP_QUIT:
        {
        #ifdef __MMI_SUBLCD__
            if (IsMyTimerExist(POPUP_SUBLCD))
            {
                StopTimer(POPUP_SUBLCD);
                GoBackSubLCDHistory();
            }
        #endif /* __MMI_SUBLCD__ */
            break;
        }

    case EVT_ID_POPUP_REQ:
        {
            MMI_ASSERT(popup_req->receiver_proc == mmi_popup_proc);

            mmi_display_popupcallback_with_sg_internal_show(
                popup_req->parent_id, /* current must be GRP_ID_ROOT */
                NULL, /* user_tag */
                popup_req->string, 
                popup_req->notify_event_id,
                popup_req->rotation,
                mmi_popup_proc, 
                NULL, 
                popup_req->flags);
            break;
        }

    default:
        break;
    }
    return MMI_RET_OK;
}


/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popup_with_sg(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, U32 flags)
{
    mmi_popup_property_struct arg;
    
    mmi_popup_property_init(&arg);
    arg.parent_id = parent_id;
    if (flags & MMI_POPUP_DISABLE_SLIDING_EFFECT)
    {
        arg.f_sliding_effect = MMI_FALSE;
    }
    if (flags & MMI_POPUP_DISABLE_SHOW_ICON)
    {
        arg.f_msg_icon = MMI_FALSE;
    }
    return (MMI_BOOL)mmi_popup_display(string, event_id, &arg);
}

#ifdef __MMI_SCREEN_ROTATE__
MMI_BOOL mmi_display_popup_rotated_with_sg(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation, U32 flags)
{
    mmi_popup_property_struct arg;
    
    mmi_popup_property_init(&arg);
    arg.parent_id = parent_id;
    arg.rotation = rotation;
    if (flags & MMI_POPUP_DISABLE_SLIDING_EFFECT)
    {
        arg.f_sliding_effect = MMI_FALSE;
    }
    if (flags & MMI_POPUP_DISABLE_SHOW_ICON)
    {
        arg.f_msg_icon = MMI_FALSE;
    }
    mmi_popup_display(string, event_id, &arg);
	return MMI_TRUE;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_sent_event
 * DESCRIPTION
 *  popupcallback sent event to caller.
 * PARAMETERS
 *  event_id     [IN] event result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_popupcallback_send_event(
                mmi_id parent_id,
                void *user_tag, 
                mmi_proc_func popup_callback_receiver_func,
                void *user_data,
                mmi_common_screen_event_enum event_id, 
                mmi_popupcallback_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, event_id);
    if(popup_callback_receiver_func == NULL)
    {
        //mmi_frm_group_get_info(g_popup_ctx.parent_id, &parent_node);
        event.result = result;
        event.user_tag = user_tag;
        /* Should use screen group API to send/post the event because the nodes may be destroyed when they receive the post event */
        mmi_frm_scrn_send_to_parent(parent_id, (mmi_event_struct*)&event);
    }
    else
    {
        event.result = result;
        event.user_tag = user_tag;
        mmi_frm_send_event((mmi_event_struct*)&event, popup_callback_receiver_func, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_sent_event
 * DESCRIPTION
 *  popupcallback sent event to caller.
 * PARAMETERS
 *  event_id     [IN] event result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_popupcallback_post_event(
                        mmi_id parent_id,
                        void *user_tag, 
                        mmi_proc_func popup_callback_receiver_func,
                        void *user_data,
                        mmi_common_screen_event_enum event_id, 
                        mmi_popupcallback_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&event, event_id);
    if(popup_callback_receiver_func == NULL)
    {
        //mmi_frm_group_get_info(g_popup_ctx.parent_id, &parent_node);
        event.result = result;
        event.user_tag = user_tag;
        /* Should use screen group API to send/post the event because the nodes may be destroyed when they receive the post event */
        mmi_frm_scrn_post_to_parent(parent_id, (mmi_event_struct*)&event);
    }
    else
    {
        event.result = result;
        event.user_tag = user_tag;
        mmi_frm_post_event((mmi_event_struct*)&event, popup_callback_receiver_func, user_data);
    }
}

static mmi_ret mmi_popupcallback_close_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_post_struct *event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    event = (mmi_event_popoupcallback_post_struct *)evt;
    mmi_frm_scrn_close(event->parent_id, event->screen_id);
    return MMI_RET_OK;
}

static void mmi_popupcallback_send_receiver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_post_struct event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    MMI_FRM_INIT_EVENT(&event, 0);
    /* Avoid call popupcallback again if popupcallback function do not show directly*/
    SetGroupKeyHandler(UI_dummy_function, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);    
    g_popup_sender_done = MMI_TRUE;
    event.parent_id = g_popup_ctx.parent_id;
    event.screen_id = g_popup_ctx.screen_id;
    mmi_popupcallback_send_event(
        g_popup_ctx.parent_id,
        g_popup_ctx.user_tag,
        g_popupcallback_receiver_func,
        g_popup_ctx.user_data,
        EVT_ID_POPUP_QUIT, MMI_POPUP_NORMAL_EXIT);
    //mmi_frm_scrn_close(group_id, screen_id);
    mmi_frm_post_event((mmi_event_struct*)&event, mmi_popupcallback_close_proc, 0);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_exit_display_popupcallback_with_sg
 * DESCRIPTION
 *  Exit screen function for mmi_display_popupcallback_with_sg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_exit_display_popupcallback_with_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_TIMER);
    g_mmi_popup_keydown_Flag = MMI_FALSE;
    g_popupcallback_timer_flag = MMI_FALSE;
    if (g_mmi_popup_toneId)
    {
        srv_prof_stop_tone(g_mmi_popup_toneId);
        g_mmi_popup_toneId = SRV_PROF_TONE_NONE;
    }
    /* clear add history attribute because popup don't add into history*/
    //mmi_frm_scrn_clear_attribute(g_popup_ctx.parent_id, g_popup_ctx.screen_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
    if(g_popup_sender_done == MMI_FALSE)
    {
        /* if inerrupt event come, send exit screen event to caller*/
        mmi_popupcallback_post_event(
            g_popup_ctx.parent_id,
            g_popup_ctx.user_tag, 
            g_popupcallback_receiver_func,
            g_popup_ctx.user_data,
            EVT_ID_POPUP_QUIT, MMI_POPUP_INTERRUPT_EXIT);
    }
    
    g_popup_ctx.user_tag = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_timer_over_with_sg
 * DESCRIPTION
 *  Stops the timer and Call Callback function after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_popupcallback_timer_over_with_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_popupcallback_timer_flag)
    {
        mmi_popupcallback_send_receiver();
    }
    else
    {
        g_popupcallback_timer_flag = MMI_TRUE;
    }

}

#if (defined __MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_pen_down_hdlr_with_sg
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        pen down position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL mmi_popupcallback_pen_down_hdlr_with_sg(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popupcallback_keydown_handler_with_sg();
    mmi_popupcallback_close_by_press_anykey_with_sg();
    return MMI_TRUE;
}
#endif /* (defined __MMI_TOUCH_SCREEN__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_keydown_handler_with_sg
 * DESCRIPTION
 *  turn on popup keydown flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_popupcallback_keydown_handler_with_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_popup_keydown_Flag = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_close_by_press_anykey_with_sg
 * DESCRIPTION
 *  Stops the timer and goes back if users press any key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_popupcallback_close_by_press_anykey_with_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_popup_keydown_Flag == MMI_TRUE)
    {
        g_mmi_popup_keydown_Flag = MMI_FALSE;
        mmi_popupcallback_send_receiver();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_popupcallback_tone_play_over_with_sg
 * DESCRIPTION
 *  callback when tone is finished
 * PARAMETERS
 *  result  [IN]    reserved
 * RETURNS
 *  void
 *****************************************************************************/
static srv_prof_ret mmi_popupcallback_tone_play_over_with_sg(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popupcallback_timer_over_with_sg();
	return SRV_PROF_RET_SUCCESS;
}

static mmi_id mmi_popup_get_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_popup_ctx.screen_id != SCR_POPUP_SCREEN)
    {
        return SCR_POPUP_SCREEN;
    }
    else
    {
        return SCR_POPUP_SCREEN+1;
    }
}
static mmi_id g_popup_confirm_screen_id = 0;
static mmi_id mmi_popup_confirm_get_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_popup_confirm_screen_id != SCR_CONFIRM_SCREEN)
    {
		g_popup_confirm_screen_id = SCR_CONFIRM_SCREEN;
        return SCR_CONFIRM_SCREEN;
    }
    else
    {
		g_popup_confirm_screen_id = SCR_CONFIRM_SCREEN + 1;
        return SCR_CONFIRM_SCREEN+1;
    }
}

static void mmi_popupcallback_init_ctx(
                mmi_id parent_id,
                mmi_id screen_id,
                UI_string_type string,
                mmi_event_notify_enum event_id,
                mmi_frm_screen_rotate_enum rotation,
                void *user_data,
                void *user_tag,
                U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_popup_ctx.parent_id = parent_id;
    g_popup_ctx.screen_id = screen_id;
    g_popup_ctx.string = string;
    g_popup_ctx.event_id = event_id;
    g_popup_ctx.rotation = rotation;
    g_popup_ctx.user_data = user_data;
    g_popup_ctx.user_tag = user_tag;
    g_popup_ctx.flags = flags;
}
                

                
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_popupcallback_with_sg
 * DESCRIPTION
 * popupcallback entry proc for post show
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_popupcallback_with_sg(void)
{
    g_popup_ctx.flags |= MMI_POPUP_DISABLE_SWITCH_SCREEN;
    mmi_display_popupcallback_with_sg_internal_show(g_popup_ctx.parent_id, g_popup_ctx.user_tag,  g_popup_ctx.string, g_popup_ctx.event_id, g_popup_ctx.rotation,
                g_popupcallback_receiver_func, g_popup_ctx.user_data, g_popup_ctx.flags);
}


static MMI_BOOL mmi_display_popupcallback_with_sg_internal_show(mmi_id parent_id, void * user_tag, UI_string_type string, mmi_event_notify_enum event_id, 
                 mmi_frm_screen_rotate_enum rotation, mmi_proc_func receiver_proc, void *user_data, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    U32 duration;
    srv_prof_tone_enum tone_id;
    FuncPtr endKeyDownFuncPtr = NULL, endKeyUpFuncPtr = NULL;
    mmi_group_node_struct node;
    mmi_id screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_RET_OK != mmi_frm_group_get_info(parent_id, &node))
    {
        mmi_popupcallback_post_event(parent_id, user_tag, receiver_proc, user_data, EVT_ID_POPUP_QUIT, MMI_POPUP_NORMAL_EXIT);

        return MMI_FALSE;
    }
    if(!(node.state & MMI_SCENARIO_STATE_ACTIVE))
    {
        mmi_popupcallback_post_event(parent_id, user_tag, receiver_proc, user_data, EVT_ID_POPUP_QUIT, MMI_POPUP_NORMAL_EXIT);

        return MMI_FALSE;     /* if parent group is not active group, do not show popup */
    }

    if(!(flags & MMI_POPUP_DISABLE_SWITCH_SCREEN))
    {
        screen_id = mmi_popup_get_screen_id();
    }
    else
    {
        screen_id = g_popup_ctx.screen_id;
    }
    if(!mmi_frm_scrn_enter(parent_id, screen_id, mmi_exit_display_popupcallback_with_sg, (FuncPtr)mmi_entry_popupcallback_with_sg, MMI_FRM_SMALL_SCRN))
    {
        mmi_frm_scrn_clear_attribute(parent_id, screen_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
        g_popupcallback_receiver_func = receiver_proc;
        mmi_popupcallback_init_ctx(parent_id, screen_id, string, event_id, rotation, user_data, user_tag, flags);
        mmi_frm_scrn_set_user_data(parent_id, g_popup_ctx.screen_id, &g_popup_ctx);
        return MMI_TRUE;     /* Gobackhistory proc, will show in post*/
    }
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_frm_scrn_clear_attribute(parent_id, screen_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
    mmi_popupcallback_init_ctx(parent_id, screen_id, string, event_id, rotation, user_data, user_tag, flags);
    g_popup_sender_done = MMI_FALSE;
    g_popupcallback_receiver_func = receiver_proc;
    g_popupcallback_timer_flag = MMI_FALSE;
    g_mmi_popup_keydown_Flag = MMI_FALSE;
#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate(rotation);
#endif
    image_id = mmi_get_event_based_image(event_id);
    tone_id = mmi_get_event_based_sound(event_id);
    duration = mmi_get_event_based_duration(event_id);

    ShowCategory63Screen((U8*)string, image_id, NULL);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat63_register_pen_down_handler(mmi_popupcallback_pen_down_hdlr_with_sg);
#endif
    endKeyDownFuncPtr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    endKeyUpFuncPtr = GetKeyHandler(KEY_END, KEY_EVENT_UP);

    SetGroupKeyHandler(mmi_popupcallback_keydown_handler_with_sg, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_popupcallback_close_by_press_anykey_with_sg, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_UP);
    SetGroupKeyHandler(UI_dummy_function, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_REPEAT);

    SetKeyHandler(endKeyDownFuncPtr, KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(endKeyUpFuncPtr, KEY_END, KEY_EVENT_UP);

    StartTimer(POPUP_TIMER, duration, mmi_popupcallback_timer_over_with_sg);

    g_mmi_popup_toneId = tone_id;
    if(SRV_PROF_RET_SUCCESS != srv_prof_play_tone(g_mmi_popup_toneId, mmi_popupcallback_tone_play_over_with_sg ))
    {
        g_popupcallback_timer_flag = MMI_TRUE; /* only call popup timer */
    }
    return MMI_TRUE;
}


static MMI_BOOL mmi_display_popupcallback_with_sg_internal(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, 
                 mmi_frm_screen_rotate_enum rotation, void *user_tag, mmi_proc_func receiver_proc, void *user_data, U32 flags)
{
    mmi_event_popupcallback_req_struct      evt = {0};

    if (mmi_frm_shell_is_in_backward_scenario() && parent_id == GRP_ID_ROOT)
    {
        /* If current is backward process in screen group mechanism and want to show the popup in GRP_ID_ROOT, we show the popup via post event. */
        if (receiver_proc == mmi_popup_proc)
        {
            /* popup behavior */
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_POPUP_REQ);
        }
        else
        {
            /* popupcallback behavior */
            return MMI_FALSE;
        }
        evt.parent_id = parent_id;
        evt.notify_event_id = event_id;
        evt.rotation = rotation;
        if (receiver_proc == NULL)
        {
            /* send event to parent group proc with user_tag */
            evt.notify_receiver_proc = MMI_FALSE;
            evt.receiver_proc = NULL;
            evt.receiver_user_data = user_tag;
        }
        else
        {
            /* send event to receiver proc with user_data */
            evt.notify_receiver_proc = MMI_TRUE;
            evt.receiver_proc = receiver_proc;
            evt.receiver_user_data = user_data;
        }
        evt.flags = flags;
        mmi_wcsncpy(evt.string, string, MAX_SUBMENU_CHARACTERS);
        MMI_FRM_POST_EVENT(&evt, mmi_popup_proc, NULL);

        return MMI_FALSE;
    }
    else
    {
        /* popupcallback behavior */
        return mmi_display_popupcallback_with_sg_internal_show(parent_id, user_tag, string, event_id, rotation, receiver_proc, user_data, flags);
    }
}




/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popupcallback_with_sg(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, mmi_proc_func receiver_proc, void *user_data, U32 flags)
{
    return mmi_display_popupcallback_with_sg_internal(parent_id, string, event_id, MMI_FRM_SCREEN_ROTATE_0, NULL, receiver_proc, user_data, flags);
}

MMI_BOOL mmi_display_popupcallback_with_sg_ext(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, void *user_tag, U32 flags)
{
    /* Send EVT_ID_POPUP_xxx to parent group proc */
    return mmi_display_popupcallback_with_sg_internal(parent_id, string, event_id, MMI_FRM_SCREEN_ROTATE_0, user_tag, NULL, NULL, flags);
}

#ifdef __MMI_SCREEN_ROTATE__
/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popupcallback_rotated_with_sg(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation, mmi_proc_func receiver_proc, void *user_data, U32 flags)
{
    return mmi_display_popupcallback_with_sg_internal(parent_id, string, event_id, rotation, NULL, receiver_proc, user_data, flags);
}

MMI_BOOL mmi_display_popupcallback_rotated_with_sg_ext(mmi_id parent_id, UI_string_type string, mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation, void *user_tag, U32 flags)
{
    /* Send EVT_ID_POPUP_xxx to parent group proc */
    return mmi_display_popupcallback_with_sg_internal(parent_id, string, event_id, rotation, user_tag, NULL, NULL, flags);
}
#endif


static MMI_BOOL mmi_display_popup_confirm_internal_with_sg(mmi_id parent_id, UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon,        
   U16 CSK_str, U16 CSK_img, UI_string_type string, mmi_event_notify_enum event_id, U8 rotation, U32 flag)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    srv_prof_tone_enum tone_id;
    mmi_group_node_struct node;
	mmi_id screen_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if(MMI_RET_OK != mmi_frm_group_get_info(parent_id, &node))
        return MMI_FALSE;   

    if(node.state & MMI_SCENARIO_STATE_ACTIVE != MMI_SCENARIO_STATE_ACTIVE)
    {
        return MMI_FALSE;     /* if parent group is not active group, do not show popup */
    }
	screen_id = mmi_popup_confirm_get_screen_id();
    if(!mmi_frm_scrn_enter(parent_id, screen_id, mmi_exit_display_popupconfirm, NULL, MMI_FRM_SMALL_SCRN))
    {
        return MMI_FALSE; /* if caller is not active or called by post */
    }
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_screen_rotate((mmi_frm_screen_rotate_enum)rotation);
#endif 

    if ((CSK_str != 0) || (CSK_img != 0))
    {
        EnableCenterSoftkey(CSK_str, CSK_img);
    }
    if(flag & MMI_POPUP_DISABLE_SLIDING_EFFECT)
    {
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
    }

    if(flag & MMI_POPUP_DISABLE_SHOW_ICON)
    {
        image_id = 0;
    }
    else
    {
        image_id = mmi_get_event_based_image(event_id);
    }
    tone_id = mmi_get_event_based_sound(event_id);

    ShowCategory163Screen(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, string, image_id, NULL);
    g_mmi_popup_toneId = tone_id;
    if (g_mmi_popup_toneId)
        srv_prof_play_tone(g_mmi_popup_toneId, NULL);
    return MMI_TRUE;
}

/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popup_confirmext_with_sg(mmi_id parent_id, UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, 
    U16 CSK_str, U16 CSK_img, UI_string_type message, mmi_event_notify_enum event_id, U32 flags)
{
    return mmi_display_popup_confirm_internal_with_sg(parent_id, left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, CSK_str, CSK_img, message, event_id, 0, flags);
}


/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popup_confirm_with_sg(mmi_id parent_id, UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, UI_string_type message,
                    mmi_event_notify_enum event_id, U32 flags)
{
    return mmi_display_popup_confirm_internal_with_sg(parent_id, left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, 0, 0, message, event_id, 0, 0);
}


#ifdef __MMI_SCREEN_ROTATE__
/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popup_confirmext_rotated_with_sg(mmi_id parent_id, UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, U16 CSK_str, U16 CSK_img, UI_string_type message,
                           mmi_event_notify_enum event_id, mmi_frm_screen_rotate_enum rotation, U32 flags)
{
    return mmi_display_popup_confirm_internal_with_sg(parent_id, left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, CSK_str, CSK_img, message, event_id, (U8)rotation, 0);
}
/* For detail description, please refer to CommonScreens.h */
MMI_BOOL mmi_display_popup_confirm_rotated_with_sg(mmi_id parent_id, UI_string_type left_softkey, PU8 left_softkey_icon, UI_string_type right_softkey, PU8 right_softkey_icon, UI_string_type message,
                    mmi_event_notify_enum event_id,mmi_frm_screen_rotate_enum rotation, U32 flags)
{
    return mmi_display_popup_confirm_internal_with_sg(parent_id, left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, 0, 0, message, event_id, rotation, 0);
}
#endif /* __MMI_SCREEN_ROTATE__ */

/*****END SCREEN GROUP *********/

//specail popup
#ifdef __ATV_SMS_SUPPORT__
static FuncPtr g_sms_matv_popup_exit_callback = NULL;
static void mmi_sms_matv_popup_timer(void)
{
	mmi_frm_scrn_close_active_id();
}
static void mmi_exit_sms_matv_popup(void)
{
	StopTimer(POPUP_TIMER);
	g_mmi_popup_keydown_Flag = MMI_FALSE;
	if(g_sms_matv_popup_exit_callback != NULL)
	    g_sms_matv_popup_exit_callback();
	g_sms_matv_popup_exit_callback = NULL;
}
static void sms_popup_keydown_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_mmi_popup_keydown_Flag = MMI_TRUE;
}

static void sms_popup_general_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_popup_keydown_Flag == MMI_TRUE)
    {
        g_mmi_popup_keydown_Flag = MMI_FALSE;
        mmi_frm_scrn_close_active_id();

    }
}
static mmi_ret mmi_sms_popup_key_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (key_evt->evt_id == EVT_ID_ON_KEY)
	{
		if (key_code == KEY_END)
			return MMI_RET_OK;
		if(key_type == KEY_EVENT_DOWN)
			sms_popup_keydown_handler();
		if(key_type == KEY_EVENT_UP)
			sms_popup_general_key_hdlr();
	}
	return MMI_RET_OK;  
	
}
MMI_BOOL mmi_sms_matv_popup_show(
				 UI_string_type string,
				 mmi_event_notify_enum event_id,
				 MMI_ID parent_id,
				 U16 screen_id,
				 FuncPtr exit_callback)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id;
    srv_prof_tone_enum tone_id;
    mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	EntryNewScreen(screen_id, mmi_exit_sms_matv_popup, NULL, NULL);
    g_sms_matv_popup_exit_callback = exit_callback;
    g_mmi_popup_keydown_Flag = MMI_FALSE;
	image_id = mmi_get_event_based_image(event_id);
	tone_id = mmi_get_event_based_sound(event_id);
	wgui_cat9009_show(0, 0, 0, 0, string,image_id, NULL);
	if (tone_id)
        srv_prof_play_tone(tone_id, NULL);
    mmi_frm_scrn_set_key_proc(parent_id, screen_id, mmi_sms_popup_key_proc);
	StartTimer(POPUP_TIMER, 2000, mmi_sms_matv_popup_timer);
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_ime_display_popup
 * DESCRIPTION
 *  display ime common screen in mATV
 * PARAMETERS
 *  string          [in] : string to display
 *  event_id        [in] : nofity type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_ime_display_popup(MMI_ID string, mmi_event_notify_enum event_id)
{
    mmi_sms_matv_popup_show(get_string(string), event_id, GRP_ID_ROOT, SCR_ID_MTV_IME_POPUP_ID, matv_exit_fptr_ime);
}

#endif

/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopupRotated(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId,
                         mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.parent_id   = GRP_ID_ROOT;
	arg.msg_icon = imageId;
	arg.tone_id = (srv_prof_tone_enum)toneId;
#ifdef __MMI_SCREEN_ROTATE__
    arg.rotation  = rotation;
#endif
    mmi_popup_display((UI_string_type)string, MMI_EVENT_INFO, &arg);
}


#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
{
    DisplayPopupRotated(string, imageId, imageOnBottom, popupDuration, toneId, MMI_FRM_SCREEN_ROTATE_0);
}
#endif /* __MMI_SCREEN_ROTATE__ */ 

static mmi_ret mmi_display_popup_proc(mmi_event_struct *evt)
{

    if(evt->evt_id == EVT_ID_ALERT_QUIT)
{
		mmi_alert_result_evt_struct *ctx = (mmi_alert_result_evt_struct*)evt;
        if((ctx->result == MMI_ALERT_NORMAL_EXIT) && PopupFunc)
		{
			PopupFunc();
			PopupFunc = NULL;
		}

		if((ctx->result == MMI_ALERT_INTERRUPT_EXIT) &&PopupFunc_interr)
    {
			PopupFunc_interr();
			PopupFunc_interr = NULL;
    }
}
    return MMI_RET_OK;
}
/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopupCallBackRotated(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId, FuncPtr f,
                         mmi_frm_screen_rotate_enum rotation)
#else
void DisplayPopupCallBack(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId, FuncPtr f)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.parent_id   = GRP_ID_ROOT;
	arg.msg_icon = imageId;
	arg.tone_id = (srv_prof_tone_enum)toneId;
#ifdef __MMI_SCREEN_ROTATE__
    arg.rotation  = rotation;
#endif
	arg.callback = mmi_display_popup_proc;
    PopupFunc = f;
    mmi_popup_display((UI_string_type)string, MMI_EVENT_INFO, &arg);

}


#ifdef __MMI_SCREEN_ROTATE__
void DisplayPopupCallBack(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId, FuncPtr f)
{
    DisplayPopupCallBackRotated(string, imageId, imageOnBottom, popupDuration, toneId, f,
                         MMI_FRM_SCREEN_ROTATE_0);
}
#endif

/* For detail description, please refer to CommonScreens.h */
void DisplayPopupCallBackExt(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId, FuncPtr f, FuncPtr InterrCallBack)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.parent_id   = GRP_ID_ROOT;
	arg.msg_icon = imageId;
	arg.tone_id = (srv_prof_tone_enum)toneId;
	arg.callback = mmi_display_popup_proc;
    PopupFunc = f;
    PopupFunc_interr = InterrCallBack;
    mmi_popup_display((UI_string_type)string, MMI_EVENT_INFO, &arg);
}


#if !defined(__MTK_TARGET__)
/*****************************************************************************
 * FUNCTION
 *  PopupNoSupport
 * DESCRIPTION
 *  Display the pop-up screen for PC Simulator limitation scenario
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopupNoSupport(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_popup_display_simple_ext(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR,
		MMI_EVENT_WARNING,
		GRP_ID_ROOT,
		0);
    return;
}
#endif /* !defined(__MTK_TARGET__) */ 


/* For detail description, please refer to CommonScreens.h */
void DisplayConfirmCountDown(
        U16 LSK_str,
        U16 LSK_img,
        U16 RSK_str,
        U16 RSK_img,
        UI_string_type message,
        MMI_ID_TYPE message_image,
        U8 toneId,
        U32 duration,
        FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_display_popup_proc, NULL);
    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	if(mmi_frm_scrn_enter(group_id, SCR_CONFIRM_SCREEN, ExitDisplayPopupConfirm, (FuncPtr)DisplayConfirmCountDown, MMI_FRM_FG_ONLY_SCRN) == MMI_FALSE)
    {
        return;
    }
    ShowCategory165Screen_ext(LSK_str, LSK_img, RSK_str, RSK_img, message, (U16) message_image, duration, NULL);
    SetCat165TimerExpireFunc(callback);
    popupToneId = toneId;
    if (popupToneId)
    {
        srv_prof_play_tone((srv_prof_tone_enum)popupToneId, NULL);
    }
}


/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void DisplayConfirmRotated(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                           MMI_ID_TYPE message_image, U8 toneId, mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayConfirm(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    DisplayConfirmRotatedExt(LSK_str, LSK_img, RSK_str, RSK_img, 0, 0, message, message_image, toneId, rotation);
#else
    DisplayConfirmExt(LSK_str, LSK_img, RSK_str, RSK_img, 0, 0, message, message_image, toneId);
#endif
}

#ifdef __MMI_SCREEN_ROTATE__

void DisplayConfirm(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
{
    DisplayConfirmRotated(LSK_str, LSK_img, RSK_str, RSK_img, message, message_image, toneId, MMI_FRM_SCREEN_ROTATE_0);
}

#endif /* __MMI_SCREEN_ROTATE__ */ 


/* For detail description, please refer to CommonScreens.h */
#ifdef __MMI_SCREEN_ROTATE__
void DisplayConfirmRotatedExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                           MMI_ID_TYPE message_image, U8 toneId, mmi_frm_screen_rotate_enum rotation)
#else /* __MMI_SCREEN_ROTATE__ */ 
void DisplayConfirmExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
#endif /* __MMI_SCREEN_ROTATE__ */ 
{
#if 1
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
    arg.parent_id   = GRP_ID_ROOT;
    arg.msg_icon = message_image;
    arg.tone_id = (srv_prof_tone_enum)toneId;
#ifdef __MMI_SCREEN_ROTATE__
    arg.rotation  = rotation;
#endif
    arg.softkey[0].str = get_string(LSK_str);
    arg.softkey[1].str = get_string(CSK_str);
    arg.softkey[2].str = get_string(RSK_str);
    arg.softkey[0].img = get_image(LSK_img);
    arg.softkey[1].img = get_image(CSK_img);
    arg.softkey[2].img = get_image(RSK_img);    

    mmi_confirm_display((UI_string_type)message, MMI_EVENT_QUERY, &arg);
    //ChangeLeftSoftkeyExt(LSK_str);
    //ChangeRightSoftkeyExt(RSK_str);
    //ChangeCenterSoftkey(CSK_str, CSK_img);

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#ifdef __MMI_SCREEN_ROTATE__

void DisplayConfirmExt(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img, U16 CSK_str, U16 CSK_img, UI_string_type message,
                    MMI_ID_TYPE message_image, U8 toneId)
{
    DisplayConfirmRotatedExt(LSK_str, LSK_img, RSK_str, RSK_img, CSK_str, CSK_img, message, message_image, toneId, MMI_FRM_SCREEN_ROTATE_0);
}

#endif /* __MMI_SCREEN_ROTATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitDisplayPopupConfirm
 * DESCRIPTION
 *  Exit function for DisplayPopupConfirm()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void ExitDisplayPopupConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
    leave_full_screen();
#endif
    ResetCenterSoftkey();
    /* 121605 popup tone Calvin Start */
    if (popupToneId)
    {
        srv_prof_stop_tone((srv_prof_tone_enum)popupToneId);
        popupToneId = 0;
    }
    /* 121605 popup tone Calvin End */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_go_back_2_history
 * DESCRIPTION
 *  Go back 2 history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_go_back_2_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    GoBacknHistory(1);
#else
    mmi_frm_go_back_2_history_sg();
#endif
}

void mmi_frm_go_back_2_history_sg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_freeze(TRUE);

    mmi_frm_scrn_multiple_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id(),
                                MMI_TRUE, 0, SCR_INPUT_METHOD_AND_DONE, MMI_FALSE);

    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_inline_generic_done
 * DESCRIPTION
 *  Highlight inline done handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_inline_generic_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(ConfirmInlineFullScreenEdit, KEY_EVENT_UP);
    SetKeyHandler(ConfirmInlineFullScreenEdit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_input_method_generic
 * DESCRIPTION
 *  Highlight input method generic handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_input_method_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_highlight_handler
 * DESCRIPTION
 *  Register highlight generic handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    SetHiliteHandler(MENU_DONE_OPTION_ID, mmi_frm_highlight_inline_generic_done);
//    SetHiliteHandler(MENU_INPUT_METHOD_OPTION_ID, mmi_frm_highlight_input_method_generic);
}


/*****************************************************************************
 * FUNCTION
 *  PopupSubLcdTimerOver
 * DESCRIPTION
 *  Stops the timer and goes back after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopupSubLcdTimerOver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(POPUP_SUBLCD);
    GoBackSubLCDHistory();

}


/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDPopupScr
 * DESCRIPTION
 *  Exit function for DisplaySubLcdPopup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitSubLCDPopupScr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not to add into history */
    StopTimer(POPUP_SUBLCD);
}


/* For detail description, please refer to CommonScreens.h */
void DisplaySubLcdPopup(U16 imageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory304Screen(imageId /* IMG_SUBLCD_CHARGER_POWER_ON */ , 0);
    SetSubLCDExitHandler(ExitSubLCDPopupScr);

    StartTimer(POPUP_SUBLCD, UI_POPUP_NOTIFYDURATION_TIME, PopupSubLcdTimerOver);

}


/* For detail description, please refer to CommonScreens.h */
void SetInterruptPopupDisplay(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The value can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON or POPUP_ALL_ON */
    is_popup_allow = flag;
}


/* For detail description, please refer to CommonScreens.h */
U8 GetInterruptPopupDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* The value can be POPUP_ALL_OFF, POPUP_DSPL_ON, POPUP_TONE_ON, or POPUP_ALL_ON */
    return is_popup_allow;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_is_no_need_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_is_no_need_symbol(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if (!mmi_imm_test_paste((UI_string_type) &c, 1))
        {
            return MMI_TRUE;
        }
    return MMI_FALSE;
}

/* 
 * We want to check the symbol is valid in the category,
 * but we need to know the code set range of the symbols first.
 * It's not used now.
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_is_valid_symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_is_valid_symbol(U16 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* English symbol table */
    for (i = 0; i < SYMBOL_PICKER_DEFAULT_SYMBOLS; i++)
    {
        if (c == *(U16*)SymbolPickerSymbols[i])
        {
            return MMI_TRUE;
        }
    }

    /* Chinese symbol table */
    for (i = 0; i < SYMBOL_PICKER_MAX_CHINESE_SYMBOLS; i++)
    {
        if (c == *(U16*)SymbolPickerChineseSymbols[i])
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*
 * Cascade Menu
 */
typedef struct _cascading_info
{
    mmi_id group_id;
    mmi_id scrn_id;
}cascading_info;

static cascading_info g_cascading_info = {0};


static MMI_BOOL mmi_in_cascading_menu = MMI_FALSE;
S32 g_mmi_cascading_menu_current_level = 0;
MMI_BOOL g_mmi_cascading_menu_is_deleting = MMI_FALSE;
static U16 g_mmi_cascading_menu_current_menu_id = 0;
static U16 g_mmi_cascading_menu_current_highlight_index = 0;
static U16 g_mmi_cascading_menu_id_history[CASCADING_MENU_MAX_LEVEL];
static CascadingMenuCmdHdlrFuncPtr g_mmi_cascading_menu_command_handler = NULL;
static CascadingMenubydataCmdHdlrFuncPtr g_mmi_cascading_menu_by_data_command_handler = NULL;
static CascadingMenubydataHLHdlrFuncPtr g_mmi_cascading_menu_by_data_highlight_handler = NULL;
static MMI_BOOL g_mmi_cascading_menu_first_level = MMI_TRUE;
static U32 num_of_items[CASCADING_MENU_MAX_LEVEL + 1];
cascading_menu_item_struct * g_mmi_cascading_menu_current_data[CASCADING_MENU_MAX_LEVEL];

static gdi_image_cache_bmp_struct  g_common_screen_cascading_cache_buf;

#ifdef __GDI_MEMORY_PROFILE_2__ /* 仅在profile2 有打开的情况下才能cache背景 */
static GDI_HANDLE cascading_layer_handle = GDI_ERROR_HANDLE;
#endif /* __GDI_MEMORY_PROFILE_2__ */
static MMI_BOOL is_cascad_go_back = MMI_FALSE;
static MMI_BOOL g_cascading_exit_by_rsk = MMI_FALSE;

#ifdef __MMI_SCREEN_ROTATE__
static mmi_frm_screen_rotate_enum g_mmi_cascading_menu_rotate_type;
#endif

static FuncPtr mmi_cascading_rsk_handler = NULL;


#ifdef __GDI_MEMORY_PROFILE_2__
static void wgui_cascading_disable_small_screen_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    force_no_small_screen();
}
#endif /*__GDI_MEMORY_PROFILE_2__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_show_background
 * DESCRIPTION
 *  Show the background when leave cascading menu
 *
 * PARAMETERS
 *  void       
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_cascading_show_background(MMI_BOOL to_first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__    
    if (mmi_frm_is_screen_width_height_swapped())
    {
        if(!to_first)
        {
            mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
        }
        if(g_common_screen_cascading_cache_buf.buf_ptr)
        {
            gdi_image_cache_bmp_draw(0, 0, &g_common_screen_cascading_cache_buf);
        }
        else /* clear the background to be black when not cache background in rotate screen */
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
        }
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        if(g_common_screen_cascading_cache_buf.buf_ptr)
        {
            gdi_image_cache_bmp_draw(0, 0, &g_common_screen_cascading_cache_buf);
        }
        else /* darken the cascading menu area if not cache background */
        {
        #if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
            gdi_draw_darken_rect(0, 0, UI_device_width - 1, UI_device_height - 1, 75);
        #endif
        }
    }
}

static void mmi_cascading_free_layer_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free memory */
    if(g_common_screen_cascading_cache_buf.buf_ptr)
    {
    #if defined(__GDI_MEMORY_PROFILE_2__)
        if(cascading_layer_handle != GDI_ERROR_HANDLE)
        {
            gdi_layer_free(cascading_layer_handle);
            cascading_layer_handle = GDI_ERROR_HANDLE;
            g_common_screen_cascading_cache_buf.buf_ptr = NULL;
        }
	#else /* __GDI_MEMORY_PROFILE_2__ */
		g_common_screen_cascading_cache_buf.buf_ptr = NULL;
	#endif /* __GDI_MEMORY_PROFILE_2__ */
    }
}


void mmi_cascading_register_rsk_handler(FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cascading_rsk_handler = handler;
}

static void mmi_cascading_reset_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cascading_rsk_handler = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_is_current_screen
 * DESCRIPTION
 *  Checks if the current screen is a cascading menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: the current screen is a cascading menu.
 *  MMI_FALSE: the current screen is not a cascading menu.
 *****************************************************************************/
static MMI_BOOL mmi_cascading_menu_is_current_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id      g_id;
    S32     scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
	if (g_id == GRP_ID_INVALID)
    {
        scr_id = GetActiveScreenId();
    }
    else
    {
        scr_id = mmi_frm_scrn_get_active_id();
    }

    if ((scr_id >= SCR_ID_CASCADING_MENU_BASE) && 
        (scr_id < SCR_ID_CASCADING_MENU_BASE + CASCADING_MENU_MAX_LEVEL))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascade_menu_data_entry_from_history
 * DESCRIPTION
 *  Cascading menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascade_menu_data_entry_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i, current_level = 0;
    mmi_id  g_id;
    MMI_BOOL is_present = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    for (i = SCR_ID_CASCADING_MENU_BASE + CASCADING_MENU_MAX_LEVEL - 2; i >= 0; i--)
    {
    #if defined(__MMI_CASCADING_MENU_HISTORY__)
        if (g_id == GRP_ID_INVALID)
        {
            is_present = IsScreenPresent((U16)i);
        }
        else
	#endif /* __MMI_CASCADING_MENU_HISTORY__ */
        {
            is_present = mmi_frm_scrn_is_present(g_id, (mmi_id)i, MMI_FRM_NODE_ALL_FLAG);
        }
        if (is_present)
        {
            if (g_mmi_cascading_menu_current_level)
            {
                current_level = g_mmi_cascading_menu_current_level;
            }
			DisplayCascadingMenuByData(
				num_of_items[current_level],
				g_mmi_cascading_menu_current_data[current_level],
				g_mmi_cascading_menu_by_data_command_handler,
				g_mmi_cascading_menu_by_data_highlight_handler);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascade_menu_entry_from_history
 * DESCRIPTION
 *  Cascading menu entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascade_menu_entry_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    mmi_id  g_id;
    MMI_BOOL is_present = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    for (i = SCR_ID_CASCADING_MENU_BASE + CASCADING_MENU_MAX_LEVEL - 2; i >= 0; i--)
    {
    #if defined(__MMI_CASCADING_MENU_HISTORY__)
        if (g_id == GRP_ID_INVALID)
        {
            is_present = IsScreenPresent((U16)i);
        }
        else
	#endif /* __MMI_CASCADING_MENU_HISTORY__ */
        {
            is_present = mmi_frm_scrn_is_present(g_id, (mmi_id)i, MMI_FRM_NODE_ALL_FLAG);
        }
        if (is_present)
        {
            /* 
             * Small screen (the cascading menu) gobackhistory will entry the full-screen app underneath,
             * which may reset the rotation to 0.
             */
        #ifdef __MMI_SCREEN_ROTATE__             
            mmi_frm_screen_rotate(g_mmi_cascading_menu_rotate_type);
        #endif
        
            DisplayCascadingMenu(
                g_mmi_cascading_menu_id_history[g_mmi_cascading_menu_current_level], 
                g_mmi_cascading_menu_command_handler);
            return;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_free_screen_based_memory
 * DESCRIPTION
 *  free the cascading menu memory that allocated to cache the full screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_free_screen_based_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (!mmi_frm_is_in_backward_scenario())
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
#ifdef __MMI_SCREEN_ROTATE__    
        if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
        {
            if (g_common_screen_cascading_cache_buf.buf_ptr)
            {
                gdi_image_cache_bmp_draw(0, 0, &g_common_screen_cascading_cache_buf);
            }
        }
    }
    mmi_cascading_free_layer_buffer();
    mmi_cascading_reset_rsk_handler();
}


#if defined(__MMI_CASCADING_MENU_HISTORY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_cascade_menu_delete_all_cascading_menus_in_history
 * DESCRIPTION
 *  Deletes all cascading menus in history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascade_menu_delete_all_cascading_menus_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CASCADING_MENU_MAX_LEVEL; i++)
    {
        DeleteScreenIfPresent((U16)(SCR_ID_CASCADING_MENU_BASE + i));
    }
}
#endif /* __MMI_CASCADING_MENU_HISTORY__ */

/*****************************************************************************
 * FUNCTION
 *  ExitCascadingMenu
 * DESCRIPTION
 *  Cascading menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCascadingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    history     h;
    mmi_id      g_id;
#endif /* __MMI_CASCADING_MENU_HISTORY__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    g_id = mmi_frm_group_get_active_id();
    if (g_id == GRP_ID_INVALID)
    {
        if (mmi_cascading_menu_is_current_screen())
        {
            h.scrnID = GetActiveScreenId();
            h.entryFuncPtr = mmi_cascade_menu_entry_from_history;
            mmi_ucs2cpy((S8*)h.inputBuffer, (S8*) L"");
            GetCategoryHistory(h.guiBuffer);
            g_mmi_cascading_menu_id_history[g_mmi_cascading_menu_current_level] = g_mmi_cascading_menu_current_menu_id;
            AddHistory(h);
            
            /* going back from the history */
            if (CheckIsBackHistory())
            {
                if (g_mmi_cascading_menu_current_level)
                {
                    g_mmi_cascading_menu_current_level--;
                }
            }
            else
            {
                g_mmi_cascading_menu_current_level++;
            }
        }
        else
        {
            /* delete all cascading menus in the history */
            mmi_cascade_menu_delete_all_cascading_menus_in_history();
            g_mmi_cascading_menu_current_level = 0;
        }
    }
    else
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    {

        if (mmi_cascading_menu_is_current_screen())
        {
            /* going back from the history */
            if (mmi_frm_is_in_backward_scenario())
            {
                g_mmi_cascading_menu_id_history[g_mmi_cascading_menu_current_level] = g_mmi_cascading_menu_current_menu_id;
                if (g_mmi_cascading_menu_current_level)
                {
                    g_mmi_cascading_menu_current_level--;
                }
            }
            else
            {
                g_mmi_cascading_menu_id_history[g_mmi_cascading_menu_current_level - 1] = g_mmi_cascading_menu_current_menu_id;
            }
        }
        else
        {
            mmi_frm_scrn_clear_attribute(g_cascading_info.group_id, g_cascading_info.scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
            /* delete all cascading menus in the history */
            mmi_frm_group_close(GRP_ID_CASCADING_MENU);
            g_mmi_cascading_menu_current_level = 0;
        }
    }

    /*leave the cascading menu*/
    if(!mmi_in_cascading_menu)
    {
        mmi_cascading_menu_free_screen_based_memory();
        wgui_cat800_restore_softkey_bkg();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitCascadingMenu
 * DESCRIPTION
 *  Cascading menu exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCascadingMenuData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    history     h;
    mmi_id      g_id;
#endif /* __MMI_CASCADING_MENU_HISTORY__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    g_id = mmi_frm_group_get_active_id();
    if (g_id == GRP_ID_INVALID)
    {
        /* original screen-history mechanism */
        if (mmi_cascading_menu_is_current_screen())
        {
            h.scrnID = GetActiveScreenId();
            h.entryFuncPtr = mmi_cascade_menu_data_entry_from_history;
            mmi_ucs2cpy((S8*)h.inputBuffer, (S8*) L"");
            GetCategoryHistory(h.guiBuffer);
            AddHistory(h);
            
            /* going back from the history */
            if (CheckIsBackHistory())
            {
                if (g_mmi_cascading_menu_current_level)
                {
                    g_mmi_cascading_menu_current_level--;
                }
            }
            else
            {
                g_mmi_cascading_menu_current_level++;
            }
        }
        else
        {
            /* delete all cascading menus in the history */
            mmi_cascade_menu_delete_all_cascading_menus_in_history();
            g_mmi_cascading_menu_current_level = 0;
            g_mmi_cascading_menu_first_level = MMI_TRUE;
        }
    }
    else
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    {
        if (mmi_cascading_menu_is_current_screen())
        {
            /* going back from the history */
            if (mmi_frm_is_in_backward_scenario())
            {
                if (g_mmi_cascading_menu_current_level)
                {
                    g_mmi_cascading_menu_current_level--;
                }
            }
        }
        else
        {
            mmi_frm_scrn_clear_attribute(g_cascading_info.group_id, g_cascading_info.scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
            /* delete all cascading menus in the history */
            mmi_frm_group_close(GRP_ID_CASCADING_MENU);
            g_mmi_cascading_menu_current_level = 0;
            g_mmi_cascading_menu_first_level = MMI_TRUE;
        }
    }

    /*leave the cascading menu*/
    if(!mmi_in_cascading_menu)
    {
        mmi_cascading_menu_free_screen_based_memory();
        wgui_cat800_restore_softkey_bkg();
    }
}

static void CascadingMenubydataHighlightFuncPtr(S32 menu_index)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cascading_menu_item_struct *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	item = (cascading_menu_item_struct*)g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level];
    g_mmi_cascading_menu_by_data_highlight_handler(((cascading_menu_item_struct*)(item+menu_index))->menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  CloseCascadingMenu
 * DESCRIPTION
 *  Closes all cascading menus.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CloseCascadingMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    mmi_id g_id;
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete all cascading menus in the history */
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    g_id = mmi_frm_group_get_active_id();
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    if (mmi_cascading_menu_is_current_screen())
    {
        /*if it is closed by RSK, we will not redraw screen background*/
        if(!g_cascading_exit_by_rsk)
        {
            mmi_cascading_show_background(MMI_FALSE);
        }
        g_cascading_exit_by_rsk = MMI_FALSE;
        mmi_cascading_free_layer_buffer();

    #if defined(__MMI_CASCADING_MENU_HISTORY__)
        if (g_id == GRP_ID_INVALID)
        {
            mmi_cascade_menu_delete_all_cascading_menus_in_history();
            mmi_frm_scrn_close_active_id();
        }
        else
	#endif /* __MMI_CASCADING_MENU_HISTORY__ */
        {
            mmi_frm_group_close(GRP_ID_CASCADING_MENU);
        }
        /*clsoe screen and reset variables*/
        g_mmi_cascading_menu_current_level = 0;
        g_mmi_cascading_menu_first_level = MMI_TRUE;
        mmi_cascading_reset_rsk_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_user_key_handler
 * DESCRIPTION
 *  handle lsk and left arrow
 * PARAMETERS
 *  flag	[IN]	MMI_TRUE for lsk, or for left arrow
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_user_key_handler(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level >= CASCADING_MENU_MAX_LEVEL)
    {
        return;
    }
    
    menu_id = GetSeqItemId_Ext(g_mmi_cascading_menu_current_menu_id, g_mmi_cascading_menu_current_highlight_index);
    
    /* invoke the command handler */
    if ((flag) && (g_mmi_cascading_menu_command_handler))
    {        
        if (g_mmi_cascading_menu_command_handler(menu_id) == MMI_TRUE)
        {
            return;
        }        
    } 
    
    /* do nothing if disabled */
    if (IsMenuItemDimmed(menu_id))
    {
        return;
    }
    
    /* go to the the next level */
    if (GetNumOfChild_Ext(menu_id) && (g_mmi_cascading_menu_current_level < CASCADING_MENU_MAX_LEVEL - 1))
    {
        if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
        {
            g_mmi_cascading_menu_current_level ++;
        }
        DisplayCascadingMenu(menu_id, g_mmi_cascading_menu_command_handler);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_left_handler
 * DESCRIPTION
 *  Cascading menu general RSK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_left_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level != 0)
    {
        if(!mmi_in_cascading_menu)
        {
            mmi_in_cascading_menu = MMI_TRUE;
        }

        is_cascad_go_back = MMI_TRUE;
		mmi_frm_scrn_close_active_id();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_right_handler
 * DESCRIPTION
 *  Cascading menu general RNK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_right_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cascading_menu_user_key_handler(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_right_handler
 * DESCRIPTION
 *  Cascading menu general RNK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_data_right_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 n_items;
    mmi_id      g_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level >= CASCADING_MENU_MAX_LEVEL)
    {
        return;
    }
    
    n_items = g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].no_of_submenus;
    if (n_items && 
        g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].flag & UI_CASCADING_MENU_WITH_SUBMENU &&
        (g_mmi_cascading_menu_current_level < CASCADING_MENU_MAX_LEVEL - 1))
    {
        g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level + 1] = 
            g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].psub;
        
        g_id = mmi_frm_group_get_active_id();
        if (g_id != GRP_ID_INVALID)
        {
            g_mmi_cascading_menu_current_level ++;
            DisplayCascadingMenuByData(
                n_items, 
                g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level],
                g_mmi_cascading_menu_by_data_command_handler, 
                g_mmi_cascading_menu_by_data_highlight_handler);
        }
        else
        {
            DisplayCascadingMenuByData(
                n_items, 
                g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level + 1],
                g_mmi_cascading_menu_by_data_command_handler, 
                g_mmi_cascading_menu_by_data_highlight_handler);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_rsk_handler
 * DESCRIPTION
 *  Cascading menu general RSK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    mmi_id g_id;
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cascading_exit_by_rsk = MMI_TRUE;
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    g_id = mmi_frm_group_get_active_id();
#endif /* __MMI_CASCADING_MENU_HISTORY__ */

    if (g_mmi_cascading_menu_current_level != 0)
    {
        if(!mmi_in_cascading_menu)
        {
            mmi_in_cascading_menu = MMI_TRUE;
        }
    }
	
    if(g_mmi_cascading_menu_current_level == 0 && g_common_screen_cascading_cache_buf.buf_ptr)
    {
        mmi_cascading_free_layer_buffer();
    }

    if(g_mmi_cascading_menu_current_level > 0)
    {
        if(!mmi_in_cascading_menu)
        {
            mmi_in_cascading_menu = MMI_TRUE;
        }
        is_cascad_go_back = MMI_TRUE;
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_cascading_reset_rsk_handler();
	#if defined(__MMI_CASCADING_MENU_HISTORY__)
        if (g_id == GRP_ID_INVALID)
        {
            mmi_cascade_menu_delete_all_cascading_menus_in_history();
            mmi_frm_scrn_close_active_id();
        }
        else
	#endif /* __MMI_CASCADING_MENU_HISTORY__ */
        {
            mmi_frm_group_close(GRP_ID_CASCADING_MENU);
        }
    }
    /* reset this value */
    g_cascading_exit_by_rsk = MMI_FALSE;

    if(g_mmi_cascading_menu_current_level == 1)
    {
        /*clsoe screen and reset variables*/
        g_mmi_cascading_menu_current_level = 0;
        g_mmi_cascading_menu_first_level = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_lsk_handler
 * DESCRIPTION
 *  Cascading menu general LSK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cascading_menu_user_key_handler(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_data_lsk_handler
 * DESCRIPTION
 *  Cascading menu general LSK handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_data_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 n_items;
    MMI_BOOL ret;
    mmi_id      g_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level >= CASCADING_MENU_MAX_LEVEL)
    {
        return;
    }
    /* invoke the command handler */
    if (g_mmi_cascading_menu_by_data_command_handler)
    {        
        ret = g_mmi_cascading_menu_by_data_command_handler(
            g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].menu_id);
        if (ret == MMI_TRUE)
        {
            return;
        }        
    }

    n_items = g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].no_of_submenus;
    if (n_items && 
        g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].flag & UI_CASCADING_MENU_WITH_SUBMENU &&
        (g_mmi_cascading_menu_current_level < CASCADING_MENU_MAX_LEVEL - 1))
    {
        g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level + 1] = 
            g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][MMI_fixed_list_menu.highlighted_item].psub;
        
        g_id = mmi_frm_group_get_active_id();
        if (g_id != GRP_ID_INVALID)
        {
            g_mmi_cascading_menu_current_level ++;
            DisplayCascadingMenuByData(
                n_items, 
                g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level],
                g_mmi_cascading_menu_by_data_command_handler, 
                g_mmi_cascading_menu_by_data_highlight_handler);
        }
        else
        {
        DisplayCascadingMenuByData(
            n_items, 
            g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level + 1],
            g_mmi_cascading_menu_by_data_command_handler, 
            g_mmi_cascading_menu_by_data_highlight_handler);
    }
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_highlight_handler
 * DESCRIPTION
 *  Cascading menu screen highlight handler
 * PARAMETERS
 *  item_index       [IN]   highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cascading_menu_highlight_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_cascading_menu_current_highlight_index = item_index;
}

#if defined(__MMI_CASCADING_MENU_HISTORY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_cascading_menu_del_scr_callback
 * DESCRIPTION
 *  Cascading menu screen delete callback
 * PARAMETERS
 *  in_param       [IN]   NOT USED 
 * RETURNS
 *  MMI_FALSE
 *****************************************************************************/
static U8 mmi_cascading_menu_del_scr_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(in_param);
    g_mmi_cascading_menu_current_level = 0;
    g_mmi_cascading_menu_first_level = MMI_TRUE;
    

    return MMI_FALSE;
}
#endif /* __MMI_CASCADING_MENU_HISTORY__ */

static mmi_ret mmi_cascading_menu_proc(mmi_event_struct* evt)
{
    /* When other want to delete cascading menu, we reset the related variables */
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            g_mmi_cascading_menu_current_level = 0;
            g_mmi_cascading_menu_first_level = MMI_TRUE;
            g_mmi_cascading_menu_is_deleting = MMI_TRUE;
            break;
        case EVT_ID_GROUP_INACTIVE:
            mmi_frm_scrn_clear_attribute(g_cascading_info.group_id, g_cascading_info.scrn_id, MMI_SCRN_ATTRIB_ADD_HISTORY);
            /* delete all cascading menus in the history */
            mmi_cascading_show_background(MMI_FALSE);
            mmi_cascading_free_layer_buffer();
            
            mmi_frm_group_close(GRP_ID_CASCADING_MENU);
            g_mmi_cascading_menu_current_level = 0;
            mmi_cascading_reset_rsk_handler();
    }

    return MMI_RET_ALLOW_CLOSE;
}


/*****************************************************************************
 * FUNCTION
 *  DisplayCascadingMenu
 * DESCRIPTION
 *  Displays a cascading menu.
 * PARAMETERS
 *  cascading_menu_id       [IN]    cascade menu menu resource ID
 *  command_handler         [IN]    cascade menu command handler
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayCascadingMenu(U16 cascading_menu_id, CascadingMenuCmdHdlrFuncPtr command_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 menu_string_list[MAX_SUB_MENUS];
    U16 n_items;
    U8 *gui_buffer;
    U16 current_screen_id;
    mmi_id g_id;
    U16 item_index;
	U8* list_of_items[MAX_SUB_MENUS];
	U8 list_of_flags[MAX_SUB_MENUS];
	U16 menu_item_id;

#ifdef __GDI_MEMORY_PROFILE_2__
    GDI_RESULT ret = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level >= CASCADING_MENU_MAX_LEVEL)
    {
        return;
    }

    mmi_in_cascading_menu = MMI_TRUE;

#ifdef __MMI_SCREEN_ROTATE__    
    g_mmi_cascading_menu_rotate_type = mmi_frm_get_screen_rotate();

    /* do not let mmi_frm_reset_screen_rotation() clear the background if rotated */
    if (mmi_frm_is_screen_width_height_swapped())
    {
        mmi_frm_enable_clear_rotated_screen(MMI_FALSE);
    }
#endif /* __MMI_SCREEN_ROTATE__ */

	g_id = mmi_frm_group_get_active_id();
#if defined(__MMI_CASCADING_MENU_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
        EntryNewScreen(current_screen_id, ExitCascadingMenu, NULL, NULL);
        /* the current level is decided after EntryNewScreen(). */
        current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
        
        SetActiveScreenId(current_screen_id);
        SetExitScreenId(current_screen_id);
        
        SetDelScrnIDCallbackHandler(current_screen_id, (HistoryDelCBPtr)mmi_cascading_menu_del_scr_callback);
        gui_buffer = GetCurrGuiBuffer(current_screen_id);
        
    #ifdef __MMI_SCREEN_ROTATE__    
        mmi_frm_screen_rotate(g_mmi_cascading_menu_rotate_type);
    #endif
    }
    else
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    {
        if (!mmi_frm_group_is_present(GRP_ID_CASCADING_MENU))
        {
            mmi_frm_group_create(g_id , GRP_ID_CASCADING_MENU, mmi_cascading_menu_proc, NULL);
            mmi_frm_group_enter(GRP_ID_CASCADING_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        
        current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
		if (mmi_frm_scrn_enter(GRP_ID_CASCADING_MENU , 
			        current_screen_id, 
			        ExitCascadingMenu, 
			        mmi_cascade_menu_entry_from_history, 
			        (mmi_frm_scrn_type_enum)0) 
			        == MMI_FALSE)
		{
		    mmi_in_cascading_menu = MMI_FALSE;
			return;
		}
		
    #ifdef __MMI_SCREEN_ROTATE__    
        mmi_frm_screen_rotate(g_mmi_cascading_menu_rotate_type);
    #endif

        /* the current level is decided after EntryNewScreen(). */
        mmi_frm_scrn_set_user_data(GRP_ID_CASCADING_MENU , current_screen_id, &current_screen_id);
		gui_buffer = mmi_frm_scrn_get_active_gui_buf();	
        g_cascading_info.group_id = GRP_ID_CASCADING_MENU;
        g_cascading_info.scrn_id = current_screen_id;
        g_mmi_cascading_menu_is_deleting = MMI_FALSE;
    }
    
#ifdef __GDI_MEMORY_PROFILE_2__

    /*use this to disable small screen redraw*/
    wgui_cascading_disable_small_screen_redraw();

    if ((!g_common_screen_cascading_cache_buf.buf_ptr) && (g_mmi_cascading_menu_current_level == 0))
    {
        ret = gdi_layer_create(
                    0,
                    0,
                    MAIN_LCD_DEVICE_WIDTH,
                    MAIN_LCD_DEVICE_HEIGHT,
                    &cascading_layer_handle);
        if(ret == GDI_SUCCEED)
        {
            gdi_layer_struct *layer = (gdi_layer_struct*)cascading_layer_handle;
            g_common_screen_cascading_cache_buf.buf_ptr = (U8*) layer->buf_ptr;
            MMI_DBG_ASSERT(g_common_screen_cascading_cache_buf.buf_ptr); 

            if(!gui_buffer)
            {
                #ifdef __MMI_SCREEN_ROTATE__    
                if (mmi_frm_is_screen_width_height_swapped())
                {
                    gdi_image_cache_bmp_get(0, 0, MAIN_LCD_DEVICE_HEIGHT - 1, MAIN_LCD_DEVICE_WIDTH - 1, &g_common_screen_cascading_cache_buf);
                }
                else
                #endif
                {
                    gdi_image_cache_bmp_get(0, 0, MAIN_LCD_DEVICE_WIDTH - 1, MAIN_LCD_DEVICE_HEIGHT - 1, &g_common_screen_cascading_cache_buf);
                }
            }
        }
    }
#endif /*__GDI_MEMORY_PROFILE_2__*/
    
    g_mmi_cascading_menu_current_menu_id = cascading_menu_id;    
    g_mmi_cascading_menu_command_handler = command_handler;
        
    n_items = GetSequenceStringIds_Ext(cascading_menu_id, menu_string_list);
	MMI_ASSERT((n_items > 0) && (n_items <= MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS));
    RegisterHighlightHandler(mmi_cascading_menu_highlight_handler);

    wgui_cm_set_display_flag();

    /*draw the background of cascading menu, only when goback from history*/
    if(is_cascad_go_back)
    {
        gdi_layer_lock_frame_buffer();
        mmi_cascading_show_background(MMI_TRUE);
        gdi_layer_unlock_frame_buffer();
        is_cascad_go_back = MMI_FALSE;
    }

    wgui_list_menu_enable_access_by_shortcut();
#ifndef __MMI_CATEGORY_LIST_SLIM__
    ShowCategory800Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_L1,
        STR_GLOBAL_SELECT,
        0,
        /*STR_GLOBAL_CLOSE*/STR_GLOBAL_BACK,
        0,
        (S32)n_items,
        menu_string_list,
        NULL,
        g_mmi_cascading_menu_current_level,
        CASCADING_MENU_MAX_LEVEL,
        cascading_menu_id,
        0,
        gui_buffer);
#else	
        for (item_index=0;item_index<n_items;item_index++)
        {
            list_of_items[item_index] = (U8*)get_string(menu_string_list[item_index]);
			menu_item_id = GetSeqItemId_Ext(cascading_menu_id, (U16)item_index);
			list_of_flags[item_index] = GetNumOfChild_Ext(menu_item_id) >0 ? 1:0;
        }    
    ShowCategory801Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_L1,
        STR_GLOBAL_SELECT,
        0,
        /*STR_GLOBAL_CLOSE*/STR_GLOBAL_BACK,
        0,
        (S32)n_items,
         list_of_items,
         NULL,
        list_of_flags,
        g_mmi_cascading_menu_current_level,
        CASCADING_MENU_MAX_LEVEL,
        0,
        gui_buffer);
#endif    

    mmi_in_cascading_menu = MMI_FALSE;
    SetLeftSoftkeyFunction(mmi_cascading_menu_lsk_handler, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cascading_menu_lsk_handler, KEY_EVENT_UP);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    if(mmi_cascading_rsk_handler != NULL && g_mmi_cascading_menu_current_level == 0)
    {
        SetRightSoftkeyFunction(mmi_cascading_rsk_handler, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_cascading_menu_rsk_handler, KEY_EVENT_UP);
    }
	if (mmi_fe_get_r2l_state())
	{
		SetKeyHandler(mmi_cascading_menu_right_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_cascading_menu_left_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	}
	else
	{
		SetKeyHandler(mmi_cascading_menu_left_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_cascading_menu_right_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	} 
}


/*****************************************************************************
 * FUNCTION
 *  ChangeCascadingMenuByDataIcon
 * DESCRIPTION
 *  Displays a cascading menu.
 * PARAMETERS
 *  menu_id                 [IN]    cascade menu menu ID
 *  img                     [IN]    New icon
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCascadingMenuByDataIcon(U32 menu_id, PU8 img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i <= num_of_items[g_mmi_cascading_menu_current_level]; i++)
    {
        if (g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][i].menu_id == menu_id)
        {
            index = i;
            break; 
        }
    }
    
    if (index != -1)
        add_fixed_icontext_list_item_icon(index, 0, img);
    RedrawCategoryFunction();

}



/*****************************************************************************
 * FUNCTION
 *  ChangeCascadingMenuByDataNIcon
 * DESCRIPTION
 *  Displays a cascading menu.
 * PARAMETERS
 *  n                       [IN]    item count
 *  menu_id                 [IN]    cascade menu menu ID
 *  img                     [IN]    New icon
 * RETURNS
 *  void
 *****************************************************************************/
void ChangeCascadingMenuByDataNIcon(U32 n, U32* menu_id, PU8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = 0; j < n; j++)
    {
        for (i = 0; i <= num_of_items[g_mmi_cascading_menu_current_level]; i++)
        {
            if (g_mmi_cascading_menu_current_data[g_mmi_cascading_menu_current_level][i].menu_id == menu_id[j])
            {
                index = i;
                break;
            }
        }
        
        if (index != -1)
            add_fixed_icontext_list_item_icon(index, 0, img[j]);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  DisplayCascadingMenuByData
 * DESCRIPTION
 *  Displays a cascading menu.
 * PARAMETERS
 *  cascading_menu_id       [IN]    cascade menu menu resource ID
 *  command_handler         [IN]    cascade menu command handler
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayCascadingMenuByData(S32 n_items, 
                                cascading_menu_item_struct *list_of_item,
                                CascadingMenubydataCmdHdlrFuncPtr command_handler,
                                CascadingMenubydataHLHdlrFuncPtr highlight_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 current_screen_id;
    U8* list_of_text[MAX_FIXED_ICONTEXT_MENU_ITEMS], *list_of_icon[MAX_FIXED_ICONTEXT_MENU_ITEMS];
    U8  list_of_flags[MAX_FIXED_ICONTEXT_MENU_ITEMS];
    S32 i;
    mmi_id g_id;
#ifdef __GDI_MEMORY_PROFILE_2__
    GDI_RESULT ret = 0;
#endif /* __GDI_MEMORY_PROFILE_2__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_cascading_menu_current_level >= CASCADING_MENU_MAX_LEVEL)
    {
        return;
    }
    /* indicate that we have enter cascading menu */
    mmi_in_cascading_menu = MMI_TRUE;

    if (g_mmi_cascading_menu_first_level)
    {
        g_mmi_cascading_menu_first_level = MMI_FALSE;
        g_mmi_cascading_menu_current_data[0] = list_of_item;
        num_of_items[0] = n_items;
    }
    else
    {
        num_of_items[g_mmi_cascading_menu_current_level + 1] = n_items;
    }

    g_id = mmi_frm_group_get_active_id();
#if defined(__MMI_CASCADING_MENU_HISTORY__)
    if (g_id == GRP_ID_INVALID)
    {
        current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
        EntryNewScreen(current_screen_id, ExitCascadingMenuData, NULL, NULL);
        /* the current level is decided after EntryNewScreen(). */
        current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
        SetActiveScreenId(current_screen_id);
        SetExitScreenId(current_screen_id);
        SetDelScrnIDCallbackHandler(current_screen_id, (HistoryDelCBPtr)mmi_cascading_menu_del_scr_callback);
    
        gui_buffer = GetCurrGuiBuffer(current_screen_id);
    }
    else
#endif /* __MMI_CASCADING_MENU_HISTORY__ */
    {
        if (!mmi_frm_group_is_present(GRP_ID_CASCADING_MENU))
        {
            mmi_frm_group_create(g_id , GRP_ID_CASCADING_MENU, mmi_cascading_menu_proc, NULL);
            mmi_frm_group_enter(GRP_ID_CASCADING_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
		
		current_screen_id = (U16)(SCR_ID_CASCADING_MENU_BASE + g_mmi_cascading_menu_current_level);
		if (mmi_frm_scrn_enter(GRP_ID_CASCADING_MENU , current_screen_id, ExitCascadingMenuData, mmi_cascade_menu_data_entry_from_history, (mmi_frm_scrn_type_enum)0) == MMI_FALSE)
		{
			mmi_in_cascading_menu = MMI_FALSE;
			return;
		}
        
        /* the current level is decided after EntryNewScreen(). */
		gui_buffer = mmi_frm_scrn_get_active_gui_buf();	
        g_cascading_info.group_id = GRP_ID_CASCADING_MENU;
        g_cascading_info.scrn_id = current_screen_id;
    }
    
    g_mmi_cascading_menu_by_data_command_handler = command_handler;
    g_mmi_cascading_menu_by_data_highlight_handler = highlight_handler;
        
    if (highlight_handler)
        RegisterHighlightHandler(CascadingMenubydataHighlightFuncPtr);

    for (i = 0; i < n_items; i ++)
    {
        list_of_text[i] = list_of_item[i].list_text;
        list_of_flags[i] = list_of_item[i].flag;
        list_of_icon[i] = list_of_item[i].list_icon;
    }
    SetParentHandler(0);

#ifdef __GDI_MEMORY_PROFILE_2__
    if ((!g_common_screen_cascading_cache_buf.buf_ptr) && (g_mmi_cascading_menu_current_level == 0))
    {
        ret = gdi_layer_create(
                    0,
                    0,
                    MAIN_LCD_DEVICE_WIDTH,
                    MAIN_LCD_DEVICE_HEIGHT,
                    &cascading_layer_handle);
        if(ret == GDI_SUCCEED)
        {
            gdi_layer_struct *layer = (gdi_layer_struct*)cascading_layer_handle;
            g_common_screen_cascading_cache_buf.buf_ptr = (U8*) layer->buf_ptr;
            MMI_DBG_ASSERT(g_common_screen_cascading_cache_buf.buf_ptr); 

            if(!gui_buffer)
            {
                #ifdef __MMI_SCREEN_ROTATE__    
                if (mmi_frm_is_screen_width_height_swapped())
                {
                    gdi_image_cache_bmp_get(0, 0, MAIN_LCD_DEVICE_HEIGHT - 1, MAIN_LCD_DEVICE_WIDTH - 1, &g_common_screen_cascading_cache_buf);
                }
                else
                #endif
                {
                    gdi_image_cache_bmp_get(0, 0, MAIN_LCD_DEVICE_WIDTH - 1, MAIN_LCD_DEVICE_HEIGHT - 1, &g_common_screen_cascading_cache_buf);
                }
            }
        }
    }
#endif /*__GDI_MEMORY_PROFILE_2__*/

    wgui_cm_set_display_flag();

    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory801Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_L1,
        STR_GLOBAL_SELECT,
        0,
        /*STR_GLOBAL_CLOSE*/STR_GLOBAL_BACK,
        0,
        (S32)n_items,
        list_of_text,
        list_of_icon,
        list_of_flags,
        g_mmi_cascading_menu_current_level,
        CASCADING_MENU_MAX_LEVEL,
        0,
        gui_buffer);

    mmi_in_cascading_menu = MMI_FALSE;
    SetLeftSoftkeyFunction(mmi_cascading_menu_data_lsk_handler, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_cascading_menu_data_lsk_handler, KEY_EVENT_UP);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetRightSoftkeyFunction(mmi_cascading_menu_rsk_handler, KEY_EVENT_UP);
    SetKeyHandler(mmi_cascading_menu_left_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_cascading_menu_data_right_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#if defined(__MMI_EM_MISC_CASCADE_MENU__)

/*****************************************************************************
 * FUNCTION
 *  mmi_cascade_menu_test_command_handler
 * DESCRIPTION
 *  Cascading menu test command handler
 * PARAMETERS
 *  menu_id       [IN]      menu resource ID
 * RETURNS
 *  MMI_TRUE if the command is handled; otherwise, MMI_FALSE to follow the cascading menu rule.
 *****************************************************************************/
static MMI_BOOL mmi_cascading_menu_test_command_handler(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
        case MAIN_MENU_FILE_MNGR_MENUID:
            DisplayPopup(
                (PU8)GetString(STR_GLOBAL_OK),
                IMG_GLOBAL_OK,
                1,
                1000,
                WARNING_TONE);
            return MMI_TRUE;                
       
        default:
            break;
    }

    return MMI_FALSE;
}


static MMI_BOOL mmi_cascading_menu_by_data_test_command_handler(U32 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 i = 0;
    static S32 j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
    case 1:
        DisplayPopup(
            (PU8)GetString(STR_GLOBAL_BACK),
            IMG_GLOBAL_OK,
            1,
            1000,
            WARNING_TONE);
        return MMI_TRUE;  
    case 10:
        DisplayPopup(
            (PU8)GetString(STR_GLOBAL_OK),
            IMG_GLOBAL_OK,
            1,
            1000,
            WARNING_TONE);
        return MMI_TRUE;  
        
    case 12:
        if (j == 0)
        {
            ChangeCascadingMenuByDataIcon(12, (PU8)GetImage(RADIO_OFF_IMAGE_ID));
            ChangeCascadingMenuByDataIcon(13, (PU8)GetImage(RADIO_ON_IMAGE_ID));
            j = 1;
        }
        else
        {
            ChangeCascadingMenuByDataIcon(13, (PU8)GetImage(RADIO_OFF_IMAGE_ID));
            ChangeCascadingMenuByDataIcon(12, (PU8)GetImage(RADIO_ON_IMAGE_ID));
            j = 0;
        }
        return MMI_TRUE;  
    case 0:
        if (i == 0)
        {
            ChangeCascadingMenuByDataIcon(0, (PU8)GetImage(RADIO_OFF_IMAGE_ID));
            ChangeCascadingMenuByDataIcon(1, (PU8)GetImage(RADIO_ON_IMAGE_ID));
            i = 1;
        }
        else
        {
            ChangeCascadingMenuByDataIcon(1, (PU8)GetImage(RADIO_OFF_IMAGE_ID));
            ChangeCascadingMenuByDataIcon(0, (PU8)GetImage(RADIO_ON_IMAGE_ID));
            i = 0;
        }
        return MMI_TRUE;  
        
    default:
        break;
    }
    
    return MMI_FALSE;
}



static void mmi_cascading_menu_by_data_highlight_handler(U32 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    
    return ;
}

U8* cm_icon[5] = {NULL, NULL, NULL, NULL, NULL};
U8* cm_string[5] = {(U8*)L"11111", (U8*)L"222", (U8*)L"33",(U8*)L"4444",(U8*)L"555555"};
cascading_menu_item_struct p[3];
cascading_menu_item_struct q[5];
/*****************************************************************************
 * FUNCTION
 *  mmi_cascade_menu_test
 * DESCRIPTION
 *  Cascade menu test function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cascade_menu_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable the first item for DLT QA */
    SetMenuItemDimmed(GetSeqItemId_Ext(IDLE_SCREEN_MENU_ID, 0), MMI_TRUE);
    
#if 1
    DisplayCascadingMenu(IDLE_SCREEN_MENU_ID, mmi_cascading_menu_test_command_handler);
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

#endif /* #if defined(__MMI_EM_MISC_CASCADE_MENU__) */

#ifdef __MMI_CLIPBOARD__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardOptionScreen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_mark
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option mark text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardLocateCursorScreen, KEY_EVENT_UP);
   // SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardLocateCursorScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_copy
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option copy menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_copy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardCopy, KEY_EVENT_UP);
 //   SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardCopy, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_copy_all
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option copy all menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_copy_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardCopyAll, KEY_EVENT_UP);
   // SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardCopyAll, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_cut
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option cut menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_cut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardCut, KEY_EVENT_UP);
   // SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardCut, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_cut_all
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option cut all menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_cut_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardCutAll, KEY_EVENT_UP);
  //  SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardCutAll, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_highlight_clipboard_edit_option_paste
 * DESCRIPTION
 *  Highlight hanlder of clipboard edit option paste menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_highlight_clipboard_edit_option_paste(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(EntryClipboardPaste, KEY_EVENT_UP);
  //  SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryClipboardPaste, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardOptionScreen
 * DESCRIPTION
 *  Entry fn for clipboard option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardOptionScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_clipboard_entry_option_screen_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_clipboard_entry_option_screen_with_sg
 * DESCRIPTION
 *  Entry fn for clipboard option menu with group ID
 * PARAMETERS
 *  g_id            [IN]        group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_clipboard_entry_option_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_string[MAX_SUB_MENUS];
    U16 list_num;
    U8  *gui_buffer;
    U8  *input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
	    if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_ID_CLIPBOARD_EDIT_OPTION);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }

        EntryNewScreen(scr_id, ExitClipboardOptionScreen, NULL, NULL);
    #if defined(__ATV_SMS_SUPPORT__)
        if(matv_init_fptr_ime != NULL)
        {
            matv_init_fptr_ime();
        }
    #endif
        gui_buffer = GetCurrGuiBuffer(scr_id);
        input_buffer = GetCurrNInputBuffer(scr_id, &input_buffer_size);
    }
    else
#endif
    {
		if (mmi_frm_scrn_enter(g_id , SCR_ID_CLIPBOARD_EDIT_OPTION, ExitClipboardOptionScreen, EntryClipboardOptionScreen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		gui_buffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (U8*)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_imc_editor_menu_history_data_struct);

    }

    if (input_buffer != NULL)
    {
        MMI_ASSERT(sizeof(mmi_imc_editor_menu_history_data_struct) == input_buffer_size);
        InputMethodScreenCloseFunction = ((mmi_imc_editor_menu_history_data_struct_p)input_buffer)->ScreenCloseFunction;
    }

    mmi_imc_clipboard_show_hide_edit_option_menu((mmi_imc_editor_menu_history_data_struct_p)input_buffer);

    /* Get menu resource */
    list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS);
    GetSequenceStringIds_Ext(MENU_ID_EDITOR_OPT_EDIT_OPTIONS, list_string);
    SetParentHandler(MENU_ID_EDITOR_OPT_EDIT_OPTIONS);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    if (list_num > 0)
    {
	#if defined(__ATV_SMS_SUPPORT__)
        if( dm_is_fixed_layer_mode_enabled() )
        {
            wgui_list_menu_enable_access_by_shortcut();
            wgui_cat1018_show(
                (WCHAR*)GetString(STR_ID_CLIPBOARD_EDIT_OPTION),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_OK),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_BACK),
                NULL,
                list_num,
                list_string,
                (U16*)gIndexIconsImageList,
                0,
                gui_buffer);

            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
        else
    #endif
        {
            /* Show Category 15 */
            ShowCategory15Screen(
                STR_ID_CLIPBOARD_EDIT_OPTION,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                list_num,
                list_string,
                (U16*)gIndexIconsImageList,
                LIST_MENU,
                0,
                gui_buffer);
        }

        /* Set Key */
        SetRightSoftkeyFunction(InputMethodScreenCloseFunction, KEY_EVENT_UP);
    }
    else
    {
        mmi_frm_scrn_close_active_id();
        if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_WARNING);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_WARNING, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitClipboardOptionScreen
 * DESCRIPTION
 *  Exit fn for clipboard option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitClipboardOptionScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__ATV_SMS_SUPPORT__)
    mmi_imc_get_editor_history_data()->ScreenCloseFunction = InputMethodScreenCloseFunction;
	g_id = mmi_frm_group_get_active_id();
#ifdef __MMI_FRM_HISTORY__	
	if (g_id == GRP_ID_INVALID)
	{
        h.scrnID = GetExitScrnID();
        h.entryFuncPtr = EntryClipboardOptionScreen;

        inputBufferSize = sizeof(mmi_imc_editor_menu_history_data_struct);
        MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
        memcpy((S8*)h.inputBuffer, (S8*)mmi_imc_get_editor_history_data(), inputBufferSize);
        GetCategoryHistory(h.guiBuffer);
        AddNHistory(h, inputBufferSize);
	}
	else
#endif
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_imc_editor_menu_history_data_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)mmi_imc_get_editor_history_data());
	}
#else
    if(matv_exit_fptr_ime != NULL)
    {
        matv_exit_fptr_ime();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardLocateCursorScreen
 * DESCRIPTION
 *  Entry fn for clipboard Locate Cursor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardLocateCursorScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif

    mmi_imc_clipboard_enter_locate_start_cursor_state();

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardCopy
 * DESCRIPTION
 *  Entry fn for clipboard copy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardCopy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_clipboard_ret_enum ret;
    mmi_id g_id;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    g_imc_clipboard_data.close_flag = 1;

    /* Go back editor screen from options screen */
    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif

    g_id = mmi_frm_group_get_active_id();
    ret = mmi_imc_clipboard_copy();
#if defined(__ATV_SMS_SUPPORT__)
    /* Only ATV will use copy/cut function in menu handler (not support menu CUI), the context should be reset after copy/cut */
    /* Other project will use cascading menu handler and the clipboard context is reset at mmi_imc_clipboard_option_handle */
    memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
#endif
    if (ret == MMI_IMC_CLIPBOARD_RET_OK)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_COPY_SUCESS, MMI_EVENT_SUCCESS);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, 0);
        }
    }
    else
    {
      /*  if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, 0);
        }*/
    }

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardCut
 * DESCRIPTION
 *  Entry fn for clipboard cut
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardCut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_clipboard_ret_enum ret;
    mmi_id g_id;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_clipboard_data.close_flag = 1;
    /* Go back editor screen from two options screen */
    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();

    g_id = mmi_frm_group_get_active_id();
    ret = mmi_imc_clipboard_cut();
#if defined(__ATV_SMS_SUPPORT__)
    /* Only ATV will use copy/cut function in menu handler (not support menu CUI), the context should be reset after copy/cut */
    /* Other project will use cascading menu handler and the clipboard context is reset at mmi_imc_clipboard_option_handle */
    memset(&g_imc_clipboard_data, 0 , sizeof(mmi_imc_clipboard_data_struct));
#endif
    if (ret == MMI_IMC_CLIPBOARD_RET_OK)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_COPY_SUCESS, MMI_EVENT_SUCCESS);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT), MMI_EVENT_INFO, 0);
        }
    }
    else
    {
    /*	if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, 0);
        }*/
    }

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardCopyAll
 * DESCRIPTION
 *  Entry fn for clipboard copy all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardCopyAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_clipboard_ret_enum ret;
    mmi_id g_id;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_EMS__
    EMS_disable_audio_playback();
    gui_EMS_input_box_disable_sound(MMI_TRUE);
#endif

    /* Go back editor screen from options screen */
    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();

#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_disable_sound(MMI_FALSE);
#endif

    g_id = mmi_frm_group_get_active_id();
    ret = mmi_imc_clipboard_copy_all();
    if (ret == MMI_IMC_CLIPBOARD_RET_OK)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_COPY_SUCESS, MMI_EVENT_SUCCESS);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, 0);
        }
    }
    else
    {
      /*  if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, 0);
        }*/
    }

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardCutAll
 * DESCRIPTION
 *  Entry fn for clipboard cut all
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardCutAll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_clipboard_ret_enum ret;
    mmi_id g_id;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back editor screen from two options screen */
    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();

    g_id = mmi_frm_group_get_active_id();
    ret = mmi_imc_clipboard_cut_all();
    if (ret == MMI_IMC_CLIPBOARD_RET_OK)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_COPY_SUCESS, MMI_EVENT_SUCCESS);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_COPY_SUCESS), MMI_EVENT_SUCCESS, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_NOT_ENOUGH)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY), MMI_EVENT_INFO, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_MEMORY_ERROR)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), MMI_EVENT_FAILURE, 0);
        }
    }
    else if (ret == MMI_IMC_CLIPBOARD_RET_CUT_UNSUPPRT_CONTENT)
    {
        if (g_id == GRP_ID_INVALID)
    	{
    	#if defined(__ATV_SMS_SUPPORT__)
            if(dm_is_fixed_layer_mode_enabled())
            {
                mmi_mtv_ime_display_popup(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT, MMI_EVENT_INFO);
            }
            else
        #endif
            {
                mmi_display_popup((UI_string_type)GetString(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT), MMI_EVENT_INFO);
            }
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT), MMI_EVENT_INFO, 0);
        }
    }
    else
    {
    /*	if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, 0);
        }*/
    }

    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}


/*****************************************************************************
 * FUNCTION
 *  EntryClipboardPaste
 * DESCRIPTION
 *  Entry fn for clipboard Paste
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryClipboardPaste(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_id g_id;
    BOOL gdi_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Go back editor screen from two options screen */
#ifdef UI_EMS_SUPPORT
    wgui_inputs_EMS_disalbe_show(MMI_TRUE);
#endif
    gdi_lcd_freeze(TRUE);
    InputMethodScreenCloseFunction();
#ifdef UI_EMS_SUPPORT
    wgui_inputs_EMS_disalbe_show(MMI_FALSE);
#endif

    if (mmi_imc_clipboard_paste() != MMI_IMC_CLIPBOARD_RET_OK)
    {
       /* g_id = mmi_frm_group_get_active_id();
    	if (g_id == GRP_ID_INVALID)
    	{
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_display_popup_with_sg(g_id, (UI_string_type)GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, 0);
        }*/
    }
    gdi_lcd_freeze(gdi_freeze);
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);
}

#endif /* __MMI_CLIPBOARD__ */
/*****************************************************************************************************************/
/*****************************************************************************
 * IME SCREENS and Utility Functions
 *****************************************************************************/

/* COMMON Functions */

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_gen_editor_common_scr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_ime_gen_editor_common_scr_id(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id = 0;
#if defined(__MMI_FRM_HISTORY__)
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (scr_id == SCR_INPUT_METHOD_LIST || scr_id == SCR_SYMBOL_PICKER_SCREEN 
        || scr_id == SCR_INPUT_MODE_LIST || scr_id == SCR_EDIT_NEW_WORD
        || scr_id == SCR_ID_CLIPBOARD_EDIT_OPTION || scr_id == SCR_CONFIG_SMART_INPUT_METHOD
        || scr_id == SCR_INPUT_METHOD_AND_DONE || scr_id == SCR_INPUT_METHOD_OPTIONS
        || scr_id == SCR_INPUT_METHOD_WRITING_LANGUAGES 
        || scr_id == SCR_INPUT_METHOD_MAIN_WRITING_LANGUAGES 
        || scr_id == SCR_INPUT_METHOD_SUB_WRITING_LANGUAGES 
        || scr_id == SCR_INPUT_METHOD_ADVANCED_OPTIONS
        || scr_id == SCR_INPUT_METHOD_KEYBOARD_TYPE  )
    {
        for (i = 0; i < MMI_MAX_EDITOR_COMMON_SCREEN_NUM; i++)
        {
            if (!IsScreenPresent(scr_id + i))
            {
               id = scr_id + i;
               break;
            }
        }

        if (i >= MMI_MAX_EDITOR_COMMON_SCREEN_NUM)
        {
            MMI_ASSERT(0); /* Not enough instance of this common screen */
        }
    }
    else
    {
        MMI_ASSERT(0); /* scr_id is not a editor common screen */
    }
#endif

    return id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_delete_editor_common_scr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_delete_editor_common_scr(U16 scr_id)
{
#if defined(__MMI_FRM_HISTORY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_id, old_id = 0xFFFF;
	MMI_BOOL commscr_active = MMI_FALSE;
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_lcd_freeze(TRUE);
    
	if (mmi_ime_is_editor_common_scr(GetActiveScreenId()))
	{
		commscr_active = MMI_TRUE;
		EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
	}

    while(GetNextScrnIdOf(scr_id, &next_id))
    {
        if (old_id == next_id)
        {
            scr_id = next_id;

            if (!GetNextScrnIdOf(scr_id, &next_id))
            {
                break;
            }
        }
        
        if (mmi_ime_is_editor_common_scr(next_id))
        {
            DeleteScreenIfPresent(next_id);
        }
        else
        {
            break;
        }

        old_id = next_id;
    }

	if (commscr_active)
	{
		mmi_frm_scrn_close_active_id();
	}

    gdi_lcd_freeze(gdi_freeze); /* Freeze lcd to avoid to blt temp screen in GoBackHistory() */

	/* 
	 * If GoBackHistory() was going to idle, we should blt, otherwise maybe no one
	 * will call blt function in the following process
	 */
	if (GetActiveScreenId() == IDLE_SCREEN_ID && commscr_active)
	{
		gdi_lcd_repaint_all(); 
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_delete_editor_common_scr_with_sg
 * DESCRIPTION
 *  Delete IME commonscreen in screen group
 * PARAMETERS
 *  g_id            [IN]         group id
 *  scr_id          [IN]         screen id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_delete_editor_common_scr_with_sg(U16 g_id, U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_id, old_id = SCR_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    next_id = mmi_frm_scrn_get_neighbor_id(g_id, scr_id, MMI_FRM_NODE_AFTER_FLAG);
    while(next_id != SCR_ID_INVALID)
    {
        if (old_id == next_id)
        {
            scr_id = next_id;

            next_id = mmi_frm_scrn_get_neighbor_id(g_id, scr_id, MMI_FRM_NODE_AFTER_FLAG);
            if (next_id == SCR_ID_INVALID)
            {
                break;
            }
        }
        
        if (mmi_ime_is_editor_common_scr(next_id))
        {
            mmi_frm_scrn_close(g_id, next_id);
        }
        else
        {
            break;
        }

        old_id = next_id;
        next_id = mmi_frm_scrn_get_neighbor_id(g_id, scr_id, MMI_FRM_NODE_AFTER_FLAG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_is_editor_common_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ime_is_editor_common_scr(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((scr_id >= SCR_INPUT_METHOD_LIST && scr_id <= SCR_INPUT_METHOD_LIST_END) 
        || (scr_id >= SCR_SYMBOL_PICKER_SCREEN && scr_id <= SCR_SYMBOL_PICKER_SCREEN_END)
        || (scr_id >= SCR_INPUT_MODE_LIST && scr_id <= SCR_INPUT_MODE_LIST_END)
        || (scr_id >= SCR_EDIT_NEW_WORD && scr_id <= SCR_EDIT_NEW_WORD_END)
        || (scr_id >= SCR_ID_CLIPBOARD_EDIT_OPTION && scr_id <= SCR_ID_CLIPBOARD_EDIT_OPTION_END)
        || (scr_id >= SCR_CONFIG_SMART_INPUT_METHOD && scr_id <= SCR_CONFIG_SMART_INPUT_METHOD_END)
        || (scr_id >= SCR_INPUT_METHOD_AND_DONE && scr_id <= SCR_INPUT_METHOD_AND_DONE_END)
        || (scr_id >= SCR_INPUT_METHOD_OPTIONS && scr_id <= SCR_INPUT_METHOD_OPTIONS_END)
        || (scr_id >= SCR_INPUT_METHOD_WRITING_LANGUAGES && scr_id<= SCR_INPUT_METHOD_WRITING_LANGUAGES_END)
        || (scr_id >= SCR_INPUT_METHOD_MAIN_WRITING_LANGUAGES && scr_id<= SCR_INPUT_METHOD_MAIN_WRITING_LANGUAGES_END)
        || (scr_id >= SCR_INPUT_METHOD_SUB_WRITING_LANGUAGES && scr_id<= SCR_INPUT_METHOD_SUB_WRITING_LANGUAGES_END)
        || (scr_id >= SCR_INPUT_METHOD_ADVANCED_OPTIONS && scr_id <= SCR_INPUT_METHOD_ADVANCED_OPTIONS_END)
        || (scr_id >= SCR_INPUT_METHOD_KEYBOARD_TYPE &&  scr_id <= SCR_INPUT_METHOD_KEYBOARD_TYPE_END )
        || (scr_id >= SCR_ID_INPUT_METHOD_VK_POPUP_LIST &&  scr_id <= SCR_ID_INPUT_METHOD_VK_POPUP_LIST_END )
        || (scr_id == SCR_ID_MTV_IME_POPUP_ID))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_is_in_java_screens
 * DESCRIPTION
 * is commonscreens in java 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_ime_commonscreens_is_in_java_screens()
{
/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    return g_ime_commonscreens_is_in_java_screens ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_config_is_java_screens
 * DESCRIPTION
 * config is commonscreens in java Temp solution to be removed in 10.17
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_config_is_java_screens(MMI_BOOL is_in)
{
/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/

    g_ime_commonscreens_is_in_java_screens = is_in;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_register_editor_common_scr_entry_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_register_editor_common_scr_entry_callback(mmi_ime_common_scr_entry_exit_callback entery_functpr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Added for Java */
    g_mmi_ime_common_scr_entry_callback = entery_functpr;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_register_editor_common_scr_exit_callback
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_register_editor_common_scr_exit_callback(mmi_ime_common_scr_entry_exit_callback exit_functpr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Added for Java */
    g_mmi_ime_common_scr_exit_callback = exit_functpr;
}

/*****************************************************************************
 * SYMBOL PIcker
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_is_in_symbol_picker
 * DESCRIPTION
 *  Whether symbol lies insymbol table or not
 * PARAMETERS
 *  U16 ch
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ime_is_in_symbol_picker(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 max;
    U8 **table;
    mmi_imm_input_mode_enum mode = mmi_imm_get_curr_input_mode();
    char str[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str[0] = (U8)ch;
    str[1] = (U8)(ch>>8);
    str[2] = '\0';
    str[3] = '\0';
#if defined(__MMI_LANG_THAI__)
    if ((mode = IMM_INPUT_MODE_MULTITAP_THAI) ||  (mode =  IMM_INPUT_MODE_SMART_THAI))
        {
            max = SYMBOL_PICKER_THAI_SYMBOLS;
            table = (U8**)SymbolPickerThaiSymbols;
        }
#endif
#if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
    if (mode == IMM_INPUT_MODE_MULTITAP_MYANMAR)
    {
        max = SYMBOL_PICKER_MYANMAR_SYMBOLS;
        table = (U8**)SymbolPickerMyanmarSymbols;        
    }
#endif
    if (mmi_imm_is_chinese_input_method(mode))
        {
            max = SYMBOL_PICKER_THAI_SYMBOLS;
            table = (U8**)SymbolPickerChineseSymbols ;
        }
#if defined(__MMI_LANG_ARABIC__)
    else if ((mode == IMM_INPUT_MODE_MULTITAP_ARABIC) ||  (mode ==  IMM_INPUT_MODE_SMART_ARABIC))
        {   
            max  =  SYMBOL_PICKER_DEFAULT_SYMBOLS;    
            table = (U8**)SymbolPickerArabicSymbols;
        }
 #endif 

#if defined(__MMI_LANG_BENGALI__)
    else if ((mode == IMM_INPUT_MODE_MULTITAP_BENGALI) ||  (mode ==  IMM_INPUT_MODE_SMART_BENGALI))
        {   
            max  =  SYMBOL_PICKER_BENGALI_SYMBOLS;    
            table = (U8**)SymbolPickerBengaliSymbols;
        }
 #endif 

    else
        {
            max  =  SYMBOL_PICKER_DEFAULT_SYMBOLS;
            table =  (U8**)SymbolPickerSymbols;

        }

    
    for (i =0 ; i < max; i++)
        {
            if (!mmi_ucs2cmp((S8*) str, (S8*)table[i] ))
            {
                return MMI_TRUE;
            }
        }
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  RegisterSymbolTableScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterSymbolTableScreenEntryCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        SymbolTableScreenEntryCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterSymbolTableScreenExitCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        SymbolTableScreenExitCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Transform_LF_SPACE_Symbol
 * DESCRIPTION
 *  
 * PARAMETERS
 *  symbol      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
UI_character_type Transform_LF_SPACE_Symbol(UI_character_type symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (symbol == 0x0085)
    {
        return 0x000a;
    }
    else if (symbol == 0x0086)
    {
        return 0x0020;
    }
    else
    {
        return symbol;
    }
}

/* End AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type selected_symbol;
    S32 index = GetHighlightedItem();
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    BOOL is_in_matv=MMI_FALSE; /* Because Lcd_freeze won't work on video */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   #if defined(__ATV_SMS_SUPPORT__)
       if( dm_is_fixed_layer_mode_enabled())
            is_in_matv= MMI_TRUE;
    #endif 
    selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                  (((UI_character_type) SymbolPickerDisplaySymbols[index][0]) |
                                   (((UI_character_type) SymbolPickerDisplaySymbols[index][1]) << 8)));
    mmi_fe_disable_proprietary_symbol_display();
    if(is_in_matv)
	{
		gdi_layer_lock_frame_buffer(); 
	}
	else
	{
    gdi_lcd_freeze(TRUE);
	}
    mmi_frm_scrn_close_active_id();
   // mmi_imc_insert_char_by_symbol_picker(selected_symbol);
    if(MMI_FALSE == mmi_imc_insert_char_by_symbol_picker(selected_symbol))
    {
		U16 i = 0;
		g_ime_post_process_data.curr_data_type = MMI_IMC_POST_SYMBOL_DATA;
	    g_ime_post_process_data.curr_data[i++] = selected_symbol;
		g_ime_post_process_data.curr_data[i] = 0;
    }
 
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif
    ClearKeyEvents();
	if(is_in_matv)
	{
		gdi_layer_unlock_frame_buffer(); 
	}
	else
	{
    gdi_lcd_freeze(gdi_freeze);
	}
    gdi_layer_blt_previous(0,0,UI_device_width-1, UI_device_height-1);    

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vrt_canvas_resume();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_disable_proprietary_symbol_display();
    mmi_frm_scrn_close_active_id();
}

extern S16 MMI_current_input_ext_type;
static S16 SymbolFilterFlag = 0;

/* End AP Symbol table */


/*****************************************************************************
 * FUNCTION
 *  EntrySymbolPickerScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySymbolPickerScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(vm_frm_is_active())//in mre editor, screen should be in root group due to mre engine limitation
	{
		//In mre editor, only one screen can be there in mre screen group
		g_id = GRP_ID_ROOT;
	}
	else
	{
    g_id = mmi_frm_group_get_active_id();
	}
    mmi_ime_entry_symbol_picker_screen_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_entry_symbol_picker_screen_with_sg
 * DESCRIPTION
 *  Entry symbol picker screen with screen group
 * PARAMETERS
 *  g_id            [IN]            group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_entry_symbol_picker_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    // for request from Sao Tao start
    if (SymbolTableScreenEntryCallback != NULL)
        SymbolTableScreenEntryCallback();
    // for request from Sao Tao end
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
	    if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_SYMBOL_PICKER_SCREEN);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
    
		EntryNewScreen(scr_id, ExitSymbolPickerScreen, NULL, NULL);
		#if defined(__ATV_SMS_SUPPORT__)
   	/* 	if( !dm_is_fixed_layer_mode_enabled() ) */
   		{
             if(matv_init_fptr_ime !=NULL)
				matv_init_fptr_ime();
   		}
		#endif
	    guiBuffer = GetCurrGuiBuffer(scr_id);
		input_buffer = (U8*)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_SYMBOL_PICKER_SCREEN, ExitSymbolPickerScreen, EntrySymbolPickerScreen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (U8*)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_symbol_picker_history_struct);
	}

	if (input_buffer != NULL)
    {
		MMI_ASSERT(sizeof(mmi_common_screen_symbol_picker_history_struct) == input_buffer_size);
	}	
    
    /* Begin AP Symbol table */
    if (guiBuffer != NULL)
    {
        MMI_current_input_ext_type = SymbolFilterFlag;
    }
    /* enable symbol table character display */
    mmi_fe_enable_proprietary_symbol_display();
    
    /* End AP Symbol table */
    PrepareSymbolTableAndShowCategory(guiBuffer, input_buffer);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(SymbolPickerHandleLSK, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  

    SetLeftSoftkeyFunction(SymbolPickerHandleLSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SymbolPickerHandleRSK, KEY_EVENT_UP);
    #if defined(__COSMOS_MMI_PACKAGE__)
       SetKeyHandler(SymbolPickerHandleRSK, KEY_BACK, KEY_EVENT_UP);
        SetKeyHandler(SymbolPickerHandleLSK, KEY_CSK, KEY_EVENT_UP);
    #endif 
    mmi_frm_scrn_set_key_proc((g_id == GRP_ID_INVALID) ? GRP_ID_ROOT : g_id,
        (g_id == GRP_ID_INVALID) ? scr_id : SCR_SYMBOL_PICKER_SCREEN,
        mmi_common_screen_symbol_picker_key_proc);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_common_screen_symbol_picker_key_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_common_screen_symbol_picker_key_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
    {
	    if (key_evt->key_code == KEY_QWERTY_ENTER && key_evt->key_type == KEY_EVENT_UP)
	    {
            SymbolPickerHandleLSK();
		    return MMI_RET_KEY_HANDLED;
	    }
    }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_common_screen_symbol_picker_from_menu_key_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_common_screen_symbol_picker_from_menu_key_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_ON_KEY)
    {
	    if (key_evt->key_code == KEY_QWERTY_ENTER && key_evt->key_type == KEY_EVENT_UP)
	    {
            SymbolPickerHandleLSKFromMenuList();
		    return MMI_RET_KEY_HANDLED;
	    }
    }
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  PrepareSymbolTableAndShowCategory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  guiBuffer       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void PrepareSymbolTableAndShowCategory(U8 *guiBuffer, U8 *inputBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /* Begin AP Symbol table */
    S32 num_of_no_show_symbols = 0;
    S32 j = 0;

    /* End AP Symbol table */
    UI_character_type symb;
    U8** symbol_table = NULL;
    S32 max_num = 0;

    mmi_common_screen_symbol_picker_history_struct_p history_p = NULL;
//    U16 old_scr_id = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // old_scr_id = GetActiveScreenId();

    if (inputBuffer != NULL)
    {
        history_p = (mmi_common_screen_symbol_picker_history_struct_p)inputBuffer;

        InputMethodScreenCloseFunction = history_p->input_method_screen_close_function;
        InputMethodScreenEntryCallback = history_p->input_method_screen_entry_function;
        InputMethodScreenExitCallback = history_p->input_method_screen_exit_function;
        SymbolTableScreenEntryCallback = history_p->symbol_table_screen_entry_callback;
        SymbolTableScreenExitCallback = history_p->symbol_table_screen_exit_callback;
        
        g_mmi_ime_symbol_table_stack_top = history_p->symbol_table_stack_top;

        g_mmi_ime_default_symbol_table[g_mmi_ime_symbol_table_stack_top] = history_p->default_symbol_table;

        g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top] = history_p->prepare_symbol_table;

        g_mmi_ime_default_symbol_table_max_num[g_mmi_ime_symbol_table_stack_top] = history_p->default_max_num;
        
        g_mmi_ime_common_scr_entry_callback = history_p->entry_callback;

        g_mmi_ime_common_scr_exit_callback = history_p->exit_callback;
        
        memcpy((void *)SymbolPickerDisplaySymbols, (void *)history_p->symbol_list, sizeof(U8 *) * SYMBOL_PICKER_MAX_SYMBOLS);
 
        if (g_mmi_ime_symbol_table_stack_top >= 0)
        {
            max_num = g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top](g_mmi_ime_ap_desired_symbol, 
                SYMBOL_PICKER_MAX_SYMBOLS, 
                g_mmi_ime_default_symbol_table[g_mmi_ime_symbol_table_stack_top], 
                g_mmi_ime_default_symbol_table_max_num[g_mmi_ime_symbol_table_stack_top]);
            
            if (max_num > SYMBOL_PICKER_MAX_SYMBOLS)
                ASSERT(0);
        }
 
        for (j = 0; SymbolPickerDisplaySymbols[j] != NULL; j++);
    }
    else
    {
        switch (mmi_imm_get_curr_input_mode())
        {
            case IMM_INPUT_MODE_SM_MULTITAP_PINYIN:
            case IMM_INPUT_MODE_SM_PINYIN:
            case IMM_INPUT_MODE_TR_BOPOMO:
            case IMM_INPUT_MODE_TR_MULTITAP_BOPOMO:
            case IMM_INPUT_MODE_TR_STROKE:
            case IMM_INPUT_MODE_HK_STROKE:                
            case IMM_INPUT_MODE_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
            case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
            case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:	
            case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:	
				
                symbol_table = (U8**)SymbolPickerChineseSymbols;
                max_num = SYMBOL_PICKER_MAX_CHINESE_SYMBOLS;
                break;
        #if defined(__MMI_LANG_ARABIC__) 
            case IMM_INPUT_MODE_SMART_ARABIC:
            case IMM_INPUT_MODE_MULTITAP_ARABIC:
            case IMM_INPUT_MODE_ARABIC_NUMERIC:
                symbol_table = (U8**)SymbolPickerArabicSymbols;
                max_num = SYMBOL_PICKER_DEFAULT_SYMBOLS;
                break;
        #endif        
        #if defined(__MMI_LANG_THAI__)
            case IMM_INPUT_MODE_MULTITAP_THAI:
            case IMM_INPUT_MODE_SMART_THAI:
                symbol_table = (U8**)SymbolPickerThaiSymbols;
                max_num = SYMBOL_PICKER_THAI_SYMBOLS;
                break;
        #endif
        #if defined(__MMI_LANG_MYANMAR__) && defined(__MMI_CSTAR__)
            case IMM_INPUT_MODE_MULTITAP_MYANMAR:            
                symbol_table = (U8**)SymbolPickerMyanmarSymbols;
                max_num = SYMBOL_PICKER_MYANMAR_SYMBOLS;
                break;
        #endif        

		#if defined(__MMI_LANG_BENGALI__)
			case IMM_INPUT_MODE_MULTITAP_BENGALI:
			case IMM_INPUT_MODE_SMART_BENGALI:
				max_num  =  SYMBOL_PICKER_BENGALI_SYMBOLS;    
				symbol_table = (U8**)SymbolPickerBengaliSymbols;
				break ;
		#endif 

		#if defined(__MMI_LANG_GUJARATI__)
			case IMM_INPUT_MODE_MULTITAP_GUJARATI:
			case IMM_INPUT_MODE_SMART_GUJARATI:
				max_num  =  SYMBOL_PICKER_GURAJATI_SYMBOLS;    
				symbol_table = (U8**)SymbolPickerGujaratiSymbols;
				break ;
		#endif 

            default:
                symbol_table = (U8**)SymbolPickerSymbols;
                max_num = SYMBOL_PICKER_DEFAULT_SYMBOLS;
                break;
        }

        if (g_mmi_ime_symbol_table_stack_top >= 0)
        {
            g_mmi_ime_default_symbol_table_max_num[g_mmi_ime_symbol_table_stack_top] = max_num;

            max_num = g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top](g_mmi_ime_ap_desired_symbol, SYMBOL_PICKER_MAX_SYMBOLS, symbol_table, max_num);
            g_mmi_ime_default_symbol_table[g_mmi_ime_symbol_table_stack_top] = symbol_table;

            if (max_num > SYMBOL_PICKER_MAX_SYMBOLS)
                ASSERT(0);
        }
        j = 0;
        for (i = 0; i < max_num && j < SYMBOL_PICKER_MAX_SYMBOLS - 1; i++)
        {
            if (g_mmi_ime_symbol_table_stack_top >= 0)
            {
                symb = g_mmi_ime_ap_desired_symbol[(i<<2)] | (g_mmi_ime_ap_desired_symbol[(i<<2)+1] << 8);
            }
            else
            {
                symb = (*symbol_table[i] | ((*(symbol_table[i]+1))<<8));
            }
            if (((MMI_current_input_ext_type & INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL) &&  (symb == (U16)NEWLINE_SYMBOL)) ||
                ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD) &&
                        (symb == (U16)EURO_SYMBOL)) ||
                !mmi_imm_test_input(&symb, 1))
            {
                num_of_no_show_symbols++;
                continue;
            }
            else
            {
                if (symb == ((U16)SPACE_SYMBOL))
                {
                    SymbolPickerDisplaySymbols[j] = SymbolPickerSpaceString;
                }
                else if (symb == ((U16)NEWLINE_SYMBOL))
                {
                    SymbolPickerDisplaySymbols[j] = SymbolPickerLFString;
                }
                else
                {
                    if (g_mmi_ime_symbol_table_stack_top >= 0)
                    {
                        SymbolPickerDisplaySymbols[j] = &g_mmi_ime_ap_desired_symbol[(i<<2)];
                    }
                    else
                    {
                        SymbolPickerDisplaySymbols[j] = symbol_table[i];
                    }
                }
                j++;
            }
        }

        SymbolPickerDisplaySymbols[j] = NULL;
    }
        
#if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
			/* Suggestion from category owner to avoid CS, call EnableCenterSoftkey(), before cagetory show API */
				EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
   	     wgui_cat1013_show(
   	     (WCHAR*)GetString(STR_INPUT_METHOD_MENU_SELECT_SYMBOL),
          NULL,
          (WCHAR*)GetString(STR_GLOBAL_OK),
          NULL,
          (WCHAR*)GetString(STR_GLOBAL_BACK),
          NULL,
          j,
          (U8 **) SymbolPickerDisplaySymbols,
          0,
          guiBuffer);
   }
   else
#endif         
   {
    ShowCategory22Screen(
        STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        j,
        (U8 **) SymbolPickerDisplaySymbols,
        0,
        guiBuffer);
   }


    if (g_mmi_ime_common_scr_entry_callback)
        g_mmi_ime_common_scr_entry_callback(0,GetActiveScreenId());
}


/*****************************************************************************
 * FUNCTION
 *  ExitSymbolPickerScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSymbolPickerScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__
    history h;
#endif
    mmi_common_screen_symbol_picker_history_struct_p symbol_picker_history;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    symbol_picker_history = &(mmi_common_screen_history.symbol_picker_history);
    /* disable proprietary symbol character display */
    mmi_fe_disable_proprietary_symbol_display();

    // or request from Sao Tao start
    if (SymbolTableScreenExitCallback != NULL)
        SymbolTableScreenExitCallback();
    // for request from Sao Tao end

    memcpy((void *)symbol_picker_history->symbol_list, (void *)SymbolPickerDisplaySymbols, (sizeof(U8 *) * SYMBOL_PICKER_MAX_SYMBOLS));

    symbol_picker_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    symbol_picker_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    symbol_picker_history->input_method_screen_exit_function = InputMethodScreenExitCallback;
    symbol_picker_history->symbol_table_screen_entry_callback = SymbolTableScreenEntryCallback;
    symbol_picker_history->symbol_table_screen_exit_callback = SymbolTableScreenExitCallback;
    symbol_picker_history->default_symbol_table = g_mmi_ime_default_symbol_table[g_mmi_ime_symbol_table_stack_top];
    symbol_picker_history->symbol_table_stack_top = g_mmi_ime_symbol_table_stack_top;
    symbol_picker_history->prepare_symbol_table = g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top];
    symbol_picker_history->default_max_num =  g_mmi_ime_default_symbol_table_max_num[g_mmi_ime_symbol_table_stack_top];
    symbol_picker_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    symbol_picker_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

    SymbolFilterFlag = MMI_current_input_ext_type;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__   
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = EntrySymbolPickerScreen;

		MMI_ASSERT(sizeof(h.inputBuffer) > sizeof(mmi_common_screen_symbol_picker_history_struct));

		memcpy(h.inputBuffer, symbol_picker_history, sizeof(mmi_common_screen_symbol_picker_history_struct));
    
		GetCategoryHistory(h.guiBuffer);
    
		AddNHistory(h, sizeof(mmi_common_screen_symbol_picker_history_struct));
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_symbol_picker_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)symbol_picker_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleLSKFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleLSKFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type selected_symbol;
    S32 index = GetHighlightedItem();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    selected_symbol = Transform_LF_SPACE_Symbol((UI_character_type)
                                  (((UI_character_type) SymbolPickerDisplaySymbols[index][0]) |
                                   (((UI_character_type) SymbolPickerDisplaySymbols[index][1]) << 8)));
   mmi_fe_disable_proprietary_symbol_display();

if(mmi_frm_group_get_active_id() == 0 )
{

    #if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) 
        mmi_frm_scrn_close_active_id();
    #endif
        mmi_frm_scrn_close_active_id();
}
else
{
#if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) 
	mmi_ime_commonscreens_2_screen_close_including_inputmethod(); 
#else 
    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
#endif
   /*  mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id()); */ 
} 
    mmi_imc_insert_char_by_symbol_picker(selected_symbol);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_reset();
#endif
    ClearKeyEvents();
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    mmi_ime_commonscreens_config_is_java_screens(MMI_FALSE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SymbolPickerHandleRSKFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SymbolPickerHandleRSKFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined (__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    mmi_fe_disable_proprietary_symbol_display();
	mmi_ime_commonscreens_2_screen_close_including_inputmethod();
    //mmi_frm_scrn_close_active_id();

#else
/* this check may go once Java move to screen group   */
    if(mmi_frm_group_get_active_id() == GRP_ID_INVALID)
    {
        if(mmi_ime_commonscreens_is_in_java_screens())
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
			 #if defined(__ATV_SMS_SUPPORT__)
				if( dm_is_fixed_layer_mode_enabled() )
				{
					mmi_frm_scrn_close_active_id();
				}
				else
			#endif
				{
        mmi_frm_go_back_2_history();
				}
    }
    }
    else
    {
        if(mmi_ime_commonscreens_is_in_java_screens())
        {
            mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
        }
    else
    {
			mmi_ime_commonscreens_2_screen_close_including_inputmethod();
           // mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
           // mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
    }
    }

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    mmi_ime_commonscreens_config_is_java_screens(MMI_FALSE);
#endif

#endif
}

/*****************************************************************************
 * FUNCTION
 *  EntrySymbolPickerScreenFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySymbolPickerScreenFromMenuList_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
	    if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_SYMBOL_PICKER_SCREEN);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
    
		EntryNewScreen(scr_id, ExitSymbolPickerScreenFromMenuList, NULL, NULL);
		#if defined(__ATV_SMS_SUPPORT__)
   	/* 	if(!dm_is_fixed_layer_mode_enabled() ) */ 
   		{
           if(matv_init_fptr_ime != NULL)
				matv_init_fptr_ime();
   		}
		#endif
	    guiBuffer = GetCurrGuiBuffer(scr_id);
		input_buffer = (U8*)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_SYMBOL_PICKER_SCREEN, ExitSymbolPickerScreenFromMenuList, EntrySymbolPickerScreenFromMenuList, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (U8*)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_symbol_picker_history_struct);
	}

	if (input_buffer != NULL)
    {
        MMI_ASSERT(sizeof(mmi_common_screen_symbol_picker_history_struct) == input_buffer_size);
	}	
    
    
    if (guiBuffer != NULL)
    {
        MMI_current_input_ext_type = SymbolFilterFlag;
    }
    /* enable symbol table character display */
    mmi_fe_enable_proprietary_symbol_display();


    PrepareSymbolTableAndShowCategory(guiBuffer, input_buffer);

    SetLeftSoftkeyFunction(SymbolPickerHandleLSKFromMenuList, KEY_EVENT_UP);
    SetRightSoftkeyFunction(SymbolPickerHandleRSKFromMenuList, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(SymbolPickerHandleLSKFromMenuList, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  

    mmi_frm_scrn_set_key_proc((g_id == GRP_ID_INVALID) ? GRP_ID_ROOT : g_id,
        (g_id == GRP_ID_INVALID) ? scr_id : SCR_SYMBOL_PICKER_SCREEN, 
        mmi_common_screen_symbol_picker_from_menu_key_proc);
}

/*****************************************************************************
 * FUNCTION
 *  EntrySymbolPickerScreenFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySymbolPickerScreenFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    EntrySymbolPickerScreenFromMenuList_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  ExitSymbolPickerScreenFromMenuList
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSymbolPickerScreenFromMenuList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FRM_HISTORY__ 
    history h;
#endif
    mmi_common_screen_symbol_picker_history_struct_p symbol_picker_history;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    symbol_picker_history = &(mmi_common_screen_history.symbol_picker_history);

    /* disable proprietary symbol character display */
    mmi_fe_disable_proprietary_symbol_display();

    memcpy((void *)symbol_picker_history->symbol_list, (void *)SymbolPickerDisplaySymbols, (sizeof(U8 *) * SYMBOL_PICKER_MAX_SYMBOLS));

    symbol_picker_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    symbol_picker_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    symbol_picker_history->input_method_screen_exit_function = InputMethodScreenExitCallback;
    symbol_picker_history->symbol_table_screen_entry_callback = SymbolTableScreenEntryCallback;
    symbol_picker_history->symbol_table_screen_exit_callback = SymbolTableScreenExitCallback;
    
    symbol_picker_history->default_symbol_table = g_mmi_ime_default_symbol_table[g_mmi_ime_symbol_table_stack_top];
    symbol_picker_history->symbol_table_stack_top = g_mmi_ime_symbol_table_stack_top;
    symbol_picker_history->prepare_symbol_table = g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top];
    symbol_picker_history->default_max_num =  g_mmi_ime_default_symbol_table_max_num[g_mmi_ime_symbol_table_stack_top];
	symbol_picker_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    symbol_picker_history->exit_callback = g_mmi_ime_common_scr_exit_callback;
	
    SymbolFilterFlag = MMI_current_input_ext_type;

	g_id = mmi_frm_group_get_active_id();
#ifdef __MMI_FRM_HISTORY__   
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = EntrySymbolPickerScreenFromMenuList;

		MMI_ASSERT(sizeof(h.inputBuffer) > sizeof(mmi_common_screen_symbol_picker_history_struct));

		memcpy(h.inputBuffer, symbol_picker_history, sizeof(mmi_common_screen_symbol_picker_history_struct));
    
		GetCategoryHistory(h.guiBuffer);
    
		AddNHistory(h, sizeof(mmi_common_screen_symbol_picker_history_struct));
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_symbol_picker_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)symbol_picker_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
}

/* Input method and done */
/*****************************************************************************
 * FUNCTION
 *  SetInputMethodAndDoneCaptionIcon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IconId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetInputMethodAndDoneCaptionIcon(U16 IconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gInputMethodAndDoneCaptionIcon = IconId;
}


/*****************************************************************************
 * FUNCTION
 *  ExitScrForInputMethodAndDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScrForInputMethodAndDone(void)
{
	#ifdef __MMI_FRM_HISTORY__   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = GetExitScrnID();
    currHistory.entryFuncPtr = EntryScrForInputMethodAndDone;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
    /* gInputMethodAndDoneCaptionIcon = 0; */
    #endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_register_symbol_table_callback
 * DESCRIPTION
 *  To register mmi_ime_prepare_symbol_table as the request. 
 *  AP could register the callback function to configure their own symbol table.
 * PARAMETERS
 *  funcptr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_register_symbol_table_callback(mmi_ime_symbol_table_callback funcptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_ime_symbol_table_stack_top + 1 < SYMBOL_TABLE_CUSTOMIZATION_FUNC_NUM)
	{
		g_mmi_ime_prepare_symbol_table[++g_mmi_ime_symbol_table_stack_top] = funcptr;
	}
	else
	{
		ASSERT(0);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_clear_symbol_table_callback
 * DESCRIPTION
 *  clear mmi_ime_prepare_symbol_table. 
 *  If AP call mmi_ime_register_symbol_table_callback, they should unset the callback function 
 *  when exiting editor screen.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_clear_symbol_table_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_ime_symbol_table_stack_top >= 0)
	{
		g_mmi_ime_prepare_symbol_table[g_mmi_ime_symbol_table_stack_top--] = NULL;
	}
	else
	{
		ASSERT(0);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_symbol_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_ime_symbol_check(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8** symbol_table = NULL;
    UI_character_type symb; 
    S32 i;	
    MMI_BOOL ret = MMI_FALSE;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    symbol_table = (U8**)SymbolPickerSymbols;
    for (i = 0; i < SYMBOL_PICKER_DEFAULT_SYMBOLS; i ++)
    {
        symb = (*symbol_table[i] | ((*(symbol_table[i]+1))<<8));
        if (symb == ch)
        {
            ret = MMI_TRUE;
	     break;
        }		
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  HighlightInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightInLineMultilineEditorOption(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nIndex)
    {
        case 0:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(wgui_common_screen_inline_edit_DONE_function, KEY_EVENT_UP);
            SetKeyHandler(wgui_common_screen_inline_edit_DONE_function, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
            SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        case 1:
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
            SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
            SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
            SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            break;
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntryInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInLineMultilineEditorOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n_string[2];    /* Stores the strings id of submenus returned */
    U16 n_Item = 0;         /* Stores no of children in the submenu */
    U8 *data = NULL;          /* Buffer holding history data */
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_inline_edit_DONE_function)
    {
        wgui_common_screen_inline_edit_DONE_function = wgui_inline_edit_DONE_function;
    }
	g_id = mmi_frm_group_get_active_id();
#ifdef __MMI_FRM_HISTORY__
	if (g_id == GRP_ID_INVALID)
	{
		/* 1 Call Exit Handler */
		EntryNewScreen(SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE, ExitInLineMultilineEditorOption, NULL, NULL);

		/* 2 Get current screen to gui buffer  for history purposes */
		data = GetCurrGuiBuffer(SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE);
	}
	else
#else
	{
		/* 1 Call Exit Handler */
		if (mmi_frm_scrn_enter(g_id , SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE, NULL, EntryInLineMultilineEditorOption, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}

		/* 2 Get current screen to gui buffer  for history purposes */
		data = mmi_frm_scrn_get_active_gui_buf();
	}
#endif

    /* 3. Retrieve no of child of menu item to be displayed */
    n_Item = GetNumOfChild(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    GetSequenceStringIds(MENU_INPUT_METHOD_AND_DONE_OPTION_ID, n_string);

    /* 6 Set current parent id */
    SetParentHandler(MENU_INPUT_METHOD_AND_DONE_OPTION_ID);

    /* 8 Display Category Screen */
    ShowCategory529Screen(
        STR_GLOBAL_OPTIONS,
        gInputMethodAndDoneCaptionIcon,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_Item,
        n_string,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        data,
        HighlightInLineMultilineEditorOption,
        (g_id == GRP_ID_INVALID) ? mmi_frm_go_back_2_history : mmi_frm_go_back_2_history_sg);

    if (wgui_inputs_menu_index_in_editor_range() == MMI_FALSE)
    {
        /* 9.Register function with right softkey */
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }
    /* 10. Register Exit handler */
}


#ifdef __MMI_FRM_HISTORY__

/*****************************************************************************
 * FUNCTION
 *  ExitInLineMultilineEditorOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void ExitInLineMultilineEditorOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_IN_LINE_MULTI_LINE_INPUT_METHOD_AND_DONE;
    currHistory.entryFuncPtr = EntryInLineMultilineEditorOption;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    GetCategoryHistory(currHistory.guiBuffer);
    AddHistory(currHistory);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  InputMethodSetKeyHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  IMEModeArray         [IN]   array with supported input mode 
 *  EnglishOnly             [IN]    If EnglishOnly is set    
 *  AP_required            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 InputMethodSetKeyHandler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num = 0;
    mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];///TODO: add define value for max allowed input mode
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    num = mmi_imm_get_curr_allow_input_mode_list(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);

    if (index >= num)
    {
        return -1;
    }
    else
    {
        return mode_array[index];
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetInputModeByIndex
 * DESCRIPTION
 *  index:  Index of input mode list
 * PARAMETERS 
 * RETURNS
 *  
 *****************************************************************************/
mmi_imm_input_mode_enum GetInputModeByIndex(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num = 0;
    mmi_imm_input_mode_enum mode_array[MMI_IMM_MAX_INPUT_METHOD_NUM];///TODO: add define value for max allowed input mode
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    num = mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
#else
    num = mmi_imm_get_curr_allow_input_mode_list(mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);
#endif

    if (index >= num)
    {
        return IMM_INPUT_MODE_NONE;
    }
    else
    {
        return mode_array[index];
    }
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    #if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    mmi_id      g_id;
    #endif 
    
#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    mmi_imm_support_writing_lang_enum desired_wlang;
    mmi_imm_input_mode_enum desired_mode;
#else
    S32 input_mode = -1;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    if (index >= 0)
    {
        BOOL gdi_freeze = gdi_lcd_get_freeze();
        
        //gdi_lcd_freeze(TRUE);
        
        mmi_imm_set_user_desired_writing_language(index);
        
        desired_wlang = mmi_imm_get_user_desired_writing_language();
        desired_mode = mmi_imm_get_user_desired_input_mode();
        /* design change  MAUI_02635344*/
        mmi_imm_update_prefer_writing_language(desired_wlang);

        g_id = mmi_frm_group_get_active_id();
        if (g_id == GRP_ID_INVALID)
        {
            mmi_frm_scrn_close_active_id();
        }
        else
        {
        mmi_ime_commonscreens_screen_close();
        }

        if (mmi_imc_is_connected() &&mmi_imm_get_current_writing_language() != desired_wlang &&
            mmi_imm_get_curr_input_mode() != desired_mode &&
            mmi_imm_is_curr_allow_input_mode(desired_mode))
        {
            mmi_imm_set_current_input_mode(desired_mode);
			mmi_imm_set_current_writing_lang(desired_wlang);
            
            if (mmi_imc_change_input_mode(desired_mode, 0))
            {
                mmi_imc_redraw_screen_by_state();
            }
        }    

        //gdi_lcd_freeze(gdi_freeze);
	    //gdi_lcd_repaint_all();
    
    #if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vrt_canvas_resume();
        }
    #endif
    }
#else
    /*Style 0 _handling for symbol picker inside insert symbol */
    input_mode = InputMethodSetKeyHandler(index);
    if (input_mode == -1)
    {
        EntrySymbolPickerScreenFromMenuList();
    }
    else
    {
        mmi_imm_set_user_desired_input_mode(input_mode);
        InputMethodScreenCloseFunction();
    }
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputModeScreenHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = IMM_INPUT_MODE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_mode = GetInputModeByIndex(index);
    if (input_mode == IMM_INPUT_MODE_NONE)
    {
        EntrySymbolPickerScreenFromMenuList();
    }
    else
    {
        mmi_imm_set_user_desired_input_mode((mmi_imm_input_mode_enum)input_mode);
#if defined (__ATV_SMS_SUPPORT__)
		if( dm_is_fixed_layer_mode_enabled() )
		{
			mmi_frm_scrn_close_active_id();
		}
		else
#endif
		{
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
		}
    }
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenEnglishOnlyHandleLSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenEnglishOnlyHandleLSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 input_mode = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Elvis multitap phonetic input mode */
    input_mode = InputMethodSetKeyHandler(index);
    if (input_mode == -1)
    {
        // index should be check
        EntrySymbolPickerScreenFromMenuList();
        UI_dummy_function();
    }
    else
    {
        mmi_imm_set_user_desired_input_mode((mmi_imm_input_mode_enum)input_mode);
        InputMethodScreenCloseFunction();
    }

}

/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenCloseFunction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenCloseFunction(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenCloseFunction = f;
    }
}

/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenEntryCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenEntryCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  RegisterInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void RegisterInputMethodScreenExitCallback(void (*f) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f != NULL)
    {
        InputMethodScreenExitCallback = f;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResetSymbolTableScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSymbolTableScreenEntryCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SymbolTableScreenEntryCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetSymbolTableScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetSymbolTableScreenExitCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SymbolTableScreenExitCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInputMethodScreenEntryCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInputMethodScreenEntryCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InputMethodScreenEntryCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  ResetInputMethodScreenExitCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ResetInputMethodScreenExitCallback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InputMethodScreenExitCallback = UI_dummy_function;
}


/*****************************************************************************
 * FUNCTION
 *  InputMethodScreenHandleRSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InputMethodScreenHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();

    if (g_id == GRP_ID_INVALID)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_ime_commonscreens_screen_close();
    }
}

/* Input method options SCREENS */
/*****************************************************************************
 * FUNCTION
 *  EntryInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vm_frm_is_active())//in mre editor, screen should be in root group due to mre engine limitation
	{
		//In mre editor, only one screen can be there in mre screen group
		g_id = GRP_ID_ROOT;
	}
	else
	{
    g_id = mmi_frm_group_get_active_id();
	}
    mmi_ime_entry_input_method_screen_with_sg(g_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_entry_input_method_screen_with_sg
 * DESCRIPTION
 *  Entry input method screen with screen group
 * PARAMETERS
 *  g_id            [IN]            group id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_entry_input_method_screen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0;
    mmi_common_screen_input_mode_list_history_struct_p input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    UI_string_type langList[IME_WRITING_LANG_TOTAL];
    S32 i;
#else
    U16 nStrItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    U16 nImageItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    S32 i = 0;
#endif
	S32 temp = 0 ;
    U16 old_scr_id = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scr_id = GetActiveScreenId();

    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_LIST);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
   
		EntryNewScreen(scr_id, ExitInputMethodScreen, NULL, NULL);
		#if defined(__ATV_SMS_SUPPORT__)
  		/*  if( !dm_is_fixed_layer_mode_enabled() ) */ 
   		 {
			if(matv_init_fptr_ime != NULL)
					matv_init_fptr_ime();
   		 }
		#endif
	    guiBuffer = GetCurrGuiBuffer(scr_id);
		input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_LIST, ExitInputMethodScreen, EntryInputMethodScreen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_input_mode_list_history_struct);
	}

    if (input_buffer != NULL)
    {
		MMI_ASSERT(sizeof(mmi_common_screen_input_mode_list_history_struct) == input_buffer_size);
        
        mmi_imm_create_input_method_list(input_buffer->input_type, input_buffer->mode_array);
        
        mmi_imm_set_current_input_mode(input_buffer->input_mode);

#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        mmi_imm_set_current_writing_lang(input_buffer->writing_lang); 
    #endif
    
        MMI_current_input_ext_type = input_buffer->input_ext_type;
        
        InputMethodScreenCloseFunction = input_buffer->input_method_screen_close_function;
        InputMethodScreenEntryCallback = input_buffer->input_method_screen_entry_function;
        InputMethodScreenExitCallback = input_buffer->input_method_screen_exit_function;

        g_mmi_ime_common_scr_entry_callback = input_buffer->entry_callback;
        g_mmi_ime_common_scr_exit_callback = input_buffer->exit_callback;
    }
    
#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)

    i = 0;

    while(g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE)
    {
        if(g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_123)
        {
            g_ime_writing_lang_array[i].lang_str_ptr = (UI_string_type)GetString(STR_ID_IME_WRITING_LANGUAGE_123);
            break;
        }
        i++;
    }
    
    nNumofItem = mmi_imm_get_curr_allow_writing_language_string_list(langList, IME_WRITING_LANG_TOTAL);
    
	/*Hack For Hinglish ime cant give the string becuase of FontRes.c limitations*/
	/*Check mode is hinglish then set string by self*/

	while(g_ime_writing_lang_array[temp].lang_id != IME_WRITING_LANG_NONE)
	{
		if(g_ime_writing_lang_array[temp].lang_id == IME_WRITING_LANG_HABC)
		{
			if(langList[temp] == NULL)
			{
				langList[temp] = L"Hinglish" ;
			}
			break ;
		}
		temp++ ;
	}

#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
        wgui_cat1014_show(
            (WCHAR*)GetString(STR_INPUT_METHOD_WRITING_LANGUAGE),
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_OK),
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            NULL,
            nNumofItem,
            (U8 **) langList,
            0,
            guiBuffer);
          
    }
    else
#endif
    {
    ShowCategory36Screen(
        STR_INPUT_METHOD_WRITING_LANGUAGE,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        (U8 **) langList,
        0,
        guiBuffer);
    }
    
#else /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */
    nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list(nStrItemList, MMI_IMM_MAX_INPUT_METHOD_NUM);

#if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    nStrItemList[nNumofItem] = STR_INPUT_METHOD_MENU_INSERT_SYMBOLS;
    nNumofItem++;
#endif

    for (i = 0; i < nNumofItem; i++)
    {
        nImageItemList[i] = gIndexIconsImageList[i];
        if (gIndexIconsImageList[i] == IMG_GLOBAL_L30)
            break;
    }
    for (i++; i < nNumofItem; i++)
    {
        nImageItemList[i] = 0;
    }

#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
	    wgui_cat1018_show(
             (WCHAR*)GetString(STR_GLOBAL_INPUT_METHOD),
             NULL,
             (WCHAR*)GetString(STR_GLOBAL_OK),
             (PU8)GetImage(IMG_GLOBAL_OK),
             (WCHAR*)GetString(STR_GLOBAL_BACK),
             (PU8)GetImage(IMG_GLOBAL_BACK),
             nNumofItem,
             nStrItemList,
             (PU16) nImageItemList,
             0,
             guiBuffer);
      
   }
  else
#endif
   {
    ShowCategory15Screen(
        STR_GLOBAL_INPUT_METHOD,
        /* gInputMethodAndDoneCaptionIcon */ 0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) nImageItemList,
        LIST_MENU,
        0,
        guiBuffer);
    }
#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) */

    SetLeftSoftkeyFunction(InputMethodScreenHandleLSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(InputMethodScreenHandleRSK, KEY_EVENT_UP);
      #if defined(__COSMOS_MMI_PACKAGE__)
       SetKeyHandler(InputMethodScreenHandleRSK, KEY_BACK, KEY_EVENT_UP);
	   SetKeyHandler(InputMethodScreenHandleLSK, KEY_CSK, KEY_EVENT_UP);
    #endif 
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(InputMethodScreenHandleLSK, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  


    if (g_mmi_ime_common_scr_entry_callback)
        g_mmi_ime_common_scr_entry_callback(old_scr_id,GetActiveScreenId());
}

/*****************************************************************************
 * FUNCTION
 *  EntryInputMethodScreen wrapper for cb manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imc_input_method_screen_handler(mmi_event_struct* param)
{
    EntryInputMethodScreen();
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  ExitInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInputMethodScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__
    history h;
    U16 inputBufferSize;
#endif
    S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);
  if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

	input_method_history->input_type = mmi_imm_get_curr_input_type();

	input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
	input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
	input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

	mode_num = mmi_imm_get_current_allowed_input_mode_num();

	mmi_imm_get_curr_allow_input_mode_list(input_method_history->mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);

	input_method_history->mode_array[mode_num] = IMM_INPUT_MODE_NONE;

    input_method_history->input_mode = mmi_imm_get_curr_input_mode();
    
#if defined(__MMI_IMC_CAPITAL_SWITCH__)||defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    input_method_history->writing_lang = mmi_imm_get_current_writing_language(); 
#endif
    
    input_method_history->input_ext_type = MMI_current_input_ext_type;

    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = EntryInputMethodScreen;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);

		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
    
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
    
		GetCategoryHistory(h.guiBuffer);
    
		AddNHistory(h, inputBufferSize);
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif  
}
#ifdef __MMI_IME_V3__

U16 input_method_str_list[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
mmi_imm_input_mode_enum input_mode_list_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX];
U8 selected_input_method_index ;

void mmi_ime_settings_highlight_current_input_method(S32 index)
{
	selected_input_method_index = (U8)index ;
	return ;
}

void mmi_imesettings_select_input_method_handler(void)
{
	mmi_popup_property_struct callback_popup;
	mmi_imc_popup_common_screen_change_mode_callback(selected_input_method_index);
	mmi_imesettings_save_screen();
	mmi_popup_property_init(& callback_popup);
	callback_popup.parent_id = mmi_frm_group_get_active_id();
	callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
}

void EntryKeyboardInputMethodScr(MMI_ID parent_gid)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
	//U16 temp_init ;
	mmi_imm_input_mode_enum mode;
	S32 i = 0, highlight = 0; 
	S32 count =0;
	WCHAR *list_items[60];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //get total lang number
    count = mmi_imm_get_curr_allow_input_mode_string_list_of_imev3(input_method_str_list,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
    if(mmi_imm_current_handwriting_is_enable())
    {
        input_method_str_list[count]=STR_IME_PEN_INPUT_STYLE_HW;
        count++;
    }
#endif
    if (count < 1)
    {
        return ;
    }
		mmi_imm_get_curr_allow_input_mode_list_of_imev3(input_mode_list_array,MMI_IMC_SELECT_LIST_ITEM_NUM_MAX);
        mode = mmi_imm_get_curr_input_mode();

        i = 0;

		/*Get the new interface to get the highlighted item*/
#if defined(__MMI_IME_VK_TYPE_HANDWRITING__)
		if(mmi_imm_current_handwriting_is_enable())
		{
#if defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
			if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_HANDWRITING)
			{
				highlight = count - 1;
			}
			else
#else
			if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
			{
				highlight = count - 1;
			}
			else
#endif
			{
				highlight = mmi_imc_get_high_light_item_in_list(mode, input_mode_list_array, count);
			}
		}
		else
#endif
        {
            highlight = mmi_imc_get_high_light_item_in_list(mode, input_mode_list_array, count);
        }

		MMI_ASSERT(highlight < count);

        /*while (i < count)
        {
            // we need to check whether we need to show handwriting as highlighted 
            if (mode == input_mode_list_array[i])
            {
                highlight = i;
                break;
            }
            i ++;
        } */

        for(i =0; i<count; i++)
        {
            list_items[i] = (WCHAR *)get_string(input_method_str_list[i]);

           /* if (i == highlighted_item)
            {
                //list_icons[i] = get_image(IMG_ID_VKBD_ACTIVATE_ITEM);
                list_icons[i] = get_image(0);
            }
            else
            {
                list_icons[i] = NULL;
            }*/
        }
    mmi_frm_scrn_enter(parent_gid , SCR_INPUT_LANG_FOLLOW_KEYBRD, NULL, EntryInputModeScreen, MMI_FRM_UNKNOW_SCRN);
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_ime_settings_highlight_current_input_method);
    
    ShowCategory36Screen(
        STR_GLOBAL_INPUT_METHOD,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        (U8 **) list_items,
        highlight,
        pGuiBuffer);

    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_select_input_method_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_select_input_method_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    return;
 }
#else

/*****************************************************************************
 * FUNCTION
 *  EntryInputModeScreen_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInputModeScreen_with_sg(mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*Assuming that not more than 16 lang will be ON on any build*/
	/*Rest two for Numeric and Insert Symbol Mode*/
	/*Two blocks reserved*/
	# define MMI_IMC_SELECT_LIST_ITEM_NUM_MAX_TEMP (16*6 + 2 + 2)

    U8 *guiBuffer;
    U16 nNumofItem = 0;
    mmi_common_screen_input_mode_list_history_struct_p input_buffer;
    U16 input_buffer_size;
    U16 nStrItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    U16 nImageItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    S32 i = 0;
    U16 scr_id = 0;
    U16 old_scr_id = 0 ;
//	UI_image_type title_image;
	//mmi_id current_gid;  
	U8 *nStrItemListstring[MMI_IMM_MAX_INPUT_METHOD_NUM];
	U8 *ListofDescriptors_temp = NULL;
	mmi_imm_input_mode_enum selected_input_mode ;
	mmi_imm_input_mode_enum input_mode_array[MMI_IMC_SELECT_LIST_ITEM_NUM_MAX_TEMP];
	S32 highlighted_item = 0 ;
	U8 temp_count  = 0 ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scr_id = GetActiveScreenId();

    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
	    if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_MODE_LIST);
        
           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }

	    EntryNewScreen(scr_id, ExitInputModeScreen, NULL, NULL);
	    #if defined(__ATV_SMS_SUPPORT__)
   				if( matv_init_fptr_ime !=NULL )
   				{
						matv_init_fptr_ime();
   				}	
		#endif
	    guiBuffer = GetCurrGuiBuffer(scr_id);
	    input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
	//	current_gid = mmi_frm_group_get_active_id();
		/* cui_menu_get_default_title_image(current_gid, &title_image);  The interface to get image from menucui is very prone to errors so commented for some time*/ 
		//title_image=NULL;
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_MODE_LIST, ExitInputModeScreen, EntryInputModeScreen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_input_mode_list_history_struct);
	}
    

    if (input_buffer != NULL)
    {
		MMI_ASSERT(sizeof(mmi_common_screen_input_mode_list_history_struct) == input_buffer_size);
        
        mmi_imm_create_input_method_list(input_buffer->input_type, input_buffer->mode_array);
        
        mmi_imm_set_current_input_mode(input_buffer->input_mode);
        
    #if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        mmi_imm_set_current_writing_lang(input_buffer->writing_lang); 
    #endif
        
        MMI_current_input_ext_type = input_buffer->input_ext_type;
        
        InputMethodScreenCloseFunction = input_buffer->input_method_screen_close_function;
        InputMethodScreenEntryCallback = input_buffer->input_method_screen_entry_function;
        InputMethodScreenExitCallback = input_buffer->input_method_screen_exit_function;

        g_mmi_ime_common_scr_entry_callback = input_buffer->entry_callback;
        g_mmi_ime_common_scr_exit_callback = input_buffer->exit_callback;
    }

#if  !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)

#if defined(__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) 
    nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang(nStrItemList, MMI_IMM_MAX_INPUT_METHOD_NUM);
#else
    nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list(nStrItemList, MMI_IMM_MAX_INPUT_METHOD_NUM);
#endif

#else

#if defined (__MMI_IMC_CAPITAL_SWITCH__) || defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list_of_curr_writing_lang(nStrItemList, MMI_IMM_MAX_INPUT_METHOD_NUM);
#else
    nNumofItem = mmi_imm_get_curr_allow_input_mode_string_list(nStrItemList, MMI_IMM_MAX_INPUT_METHOD_NUM);
#endif

#endif

#if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) && !defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)&& !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    if ( mmi_imm_get_curr_input_type () != IMM_INPUT_TYPE_NUMERIC)
    {
        nStrItemList[nNumofItem] = STR_INPUT_METHOD_MENU_INSERT_SYMBOLS;
        nNumofItem++;
    }
#endif

    for (i = 0; i < nNumofItem; i++)
    {
        nImageItemList[i] = gIndexIconsImageList[i];
		nStrItemListstring[i] = (U8 *)GetString(nStrItemList[i]);
        if (gIndexIconsImageList[i] == IMG_GLOBAL_L30)
            break;
    }
    for (i++; i < nNumofItem; i++)
    {
	nStrItemListstring[i] = (U8 *)GetString(nStrItemList[i]);
        nImageItemList[i] = 0;
    }

	selected_input_mode = mmi_imm_get_curr_input_mode();
	#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
		mmi_imm_get_curr_allow_input_mode_list_of_curr_writing_lang(input_mode_array, MMI_IMC_SELECT_LIST_ITEM_NUM_MAX_TEMP);
	#else
		mmi_imm_get_curr_allow_input_mode_list(input_mode_array, MMI_IMC_SELECT_LIST_ITEM_NUM_MAX_TEMP);
	#endif
	if(selected_input_mode == IMM_INPUT_MODE_NONE)
	{
		highlighted_item = 0 ;
	}
	else
	{
		while (temp_count < nNumofItem)
		{		
			/* we need to check whether we need to show handwriting as highlighted */ 
			if (selected_input_mode == input_mode_array[temp_count])
			{
				highlighted_item = temp_count;
				break;
			}
			temp_count ++;
		}
	}
    #if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
    	/* Suggestion from category owner to avoid CS, call EnableCenterSoftkey(), before cagetory show API */
			EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	    wgui_cat1018_show(
                   (WCHAR*)GetString(STR_GLOBAL_INPUT_METHOD),
                   NULL,
                   (WCHAR*)GetString(STR_GLOBAL_OK),
                   (PU8)GetImage(IMG_GLOBAL_OK),
                   (WCHAR*)GetString(STR_GLOBAL_BACK),
                   (PU8)GetImage(IMG_GLOBAL_BACK),
                   nNumofItem,
                   nStrItemList,
                   (PU16) nImageItemList,
                   highlighted_item,
                   guiBuffer);
      
   }
  else
#endif
  { 
ShowCategory353Screen_ext(
        (U8 *)GetString(STR_GLOBAL_INPUT_METHOD),
        NULL,
        (U8 *)GetString(STR_GLOBAL_OK),
        (U8 *)get_image(IMG_GLOBAL_OK),
        (U8 *)GetString(STR_GLOBAL_BACK),
        (U8 *)get_image(IMG_GLOBAL_BACK),
        nNumofItem,
        (U8 **)nStrItemListstring,
        (PU16) nImageItemList,
        (U8 **)ListofDescriptors_temp,
        LIST_MENU,
        highlighted_item,
        guiBuffer);
	}
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(InputModeScreenHandleLSK, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    SetLeftSoftkeyFunction(InputModeScreenHandleLSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ime_commonscreens_screen_close, KEY_EVENT_UP);
	SetKeyHandler(mmi_ime_commonscreens_screen_close, KEY_BACK, KEY_EVENT_UP);

    if (g_mmi_ime_common_scr_entry_callback)
        g_mmi_ime_common_scr_entry_callback(old_scr_id,GetActiveScreenId());
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_screen_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_screen_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
			mmi_frm_scrn_close_active_id();
	  }
	 else
	 #endif
	 {
		mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
   }
}




/*****************************************************************************
 * FUNCTION
 *  EntryInputModeScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryInputModeScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_id = mmi_frm_group_get_active_id();
#ifdef __MMI_IME_V3__
	EntryKeyboardInputMethodScr(g_id);
#else
    EntryInputModeScreen_with_sg(g_id);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  ExitInputMethodScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitInputModeScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__  
    U16 inputBufferSize;
    history h;
#endif
    S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);
    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();

    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

    mode_num = mmi_imm_get_current_allowed_input_mode_num();
    
    mmi_imm_get_curr_allow_input_mode_list(input_method_history->mode_array, MMI_IMM_MAX_INPUT_METHOD_NUM);

    input_method_history->mode_array[mode_num] = IMM_INPUT_MODE_NONE;

    input_method_history->input_mode = mmi_imm_get_curr_input_mode();
    
#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    input_method_history->writing_lang = mmi_imm_get_current_writing_language(); 
#endif    
    
    input_method_history->input_ext_type = MMI_current_input_ext_type;

    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = EntryInputModeScreen;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);

		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
    
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
    
		GetCategoryHistory(h.guiBuffer);
    
		AddNHistory(h, inputBufferSize);
	}
	else
	#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
}
#if  defined(__MMI_MIXED_LANG_SUPPORT__)
static S32 g_mixed_index = 0 ;
void mmi_ime_commonscreens_mixed_language_hilite_handler(S32 index)
{
	g_mixed_index =  index ;
}

void mmi_ime_commonscreens_mixed_language_select_handler(void)
{
	if(g_mixed_index == 0)
	{
		mmi_ime_commonscreens_entry_main_language_screen();
	}
	else
	{
		mmi_ime_commonscreens_entry_sub_language_screen();
	}
}
void mmi_ime_commonscreens_entry_mixed_language_screen(MMI_ID g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL ;
    U8 i;
    U8 *itemlist[2];
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    entry_ret = mmi_frm_scrn_enter(g_id, SCR_INPUT_METHOD_WRITING_LANGUAGES, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    itemlist[0] = (U8*)GetString(STR_WRITING_LANGUAGE_MAIN);
	itemlist[1] = (U8*)GetString(STR_WRITING_LANGUAGE_SUB);
    RegisterHighlightHandler(mmi_ime_commonscreens_mixed_language_hilite_handler);

    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);

	guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_WRITING_LANGUAGES);
   
    ShowCategory353Screen(
        (U8*)GetString(STR_INPUT_METHOD_WRITING_LANGUAGE),
		NULL,
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OPTIONS,                 /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        itemlist,
        (U16 *)gIndexIconsImageList,
		NULL,
        0,
        0,
		guiBuffer);
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_mixed_language_select_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_commonscreens_mixed_language_select_handler, KEY_EVENT_UP);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_options_menu_handler
 * DESCRIPTION
 *  event handler for imeoptions screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_imc_options_menu_handler(mmi_event_struct *evt , mmi_id g_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
//    S32 list_num = 0;
//    U16 *menu_list;
  //  U16 ItemIDList[10];
  //  U16 menu_count = 0;
   // U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    switch (menu_evt->evt_id)
    {

    case EVT_ID_CUI_MENU_LIST_ENTRY:

        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
        if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_INPUT_METHOD)
        {
#ifdef __MMI_IME_V3__
			EntryKeyboardInputMethodScr(g_id);
#else
            EntryInputModeScreen_with_sg(g_id);
#endif
        }
   #if defined(__MMI_IME_V3__)
		#if defined(__MMI_IME_PLUG_IN_SETTING__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_INPUT_METHOD_SETTING)
        {
          EntryInputMethodSetting();
        }
   #endif
   #endif
    #if defined(__MMI_IME_PLUG_IN_SETTING__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)
        else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_INSERT_SYMBOL)
        {
            mmi_ime_entry_symbol_picker_screen_with_sg(g_id);
        }
    #endif

    #if defined(__MMI_IME_PLUG_IN_SETTING__)
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        #if  defined(__MMI_MIXED_LANG_SUPPORT__)
        else if (menu_evt->highlighted_menu_id == MENU_ID_COMMONSCREENS_IME_MAIN_LANGUAGE)
        {
            
        }
        else if (menu_evt->highlighted_menu_id == MENU_ID_COMMONSCREENS_IME_SUB_LANGUAGE)
        {
            
        }
        #else
        else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
        {
            mmi_ime_commonscreens_entry_main_language_screen_with_sg(g_id);
        }
        #endif
        #endif

        #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
        else if (menu_evt->highlighted_menu_id == MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS)
        {
            mmi_ime_sdk_call_setting_cb(g_id);
        }
        #endif
    #else
    #if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__)
        #if defined(__MMI_IMC_CAPITAL_SWITCH__)
        else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
        {
            mmi_ime_entry_input_method_screen_with_sg(g_id);
        }
        #endif
    #else
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IMC_CAPITAL_SWITCH__)
        else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
        {
            mmi_ime_entry_input_method_screen_with_sg(g_id);
        }
        #endif  
    #endif 
    #endif
#if !defined ( __MMI_IME_V3__ )
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
            else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_ADD_NEW_WORD)
            {
                mmi_imc_entry_add_new_word_screen_with_sg(g_id);
            }
            #endif
            #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD)
            {
                mmi_imc_entry_config_smart_input_method_screen_with_sg(g_id);
            }
            #endif
    
    #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
            if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS)
            {
                mmi_ime_commonscreens_entry_imeoptions_with_sg(g_id);
            }
            #if defined(__MMI_PREFER_WRITING_LANG__) && !defined(__MMI_MIXED_LANG_SUPPORT__)
            if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
            {
                mmi_ime_commonscreens_entry_main_language_screen_with_sg(g_id);
            }
            #endif
    
			#if defined(__MMI_MIXED_LANG_SUPPORT__) && !defined(__MMI_PREFER_WRITING_LANG__)
          
			if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
            {
              	mmi_ime_commonscreens_entry_mixed_language_screen(g_id);
            }
            #endif


            #if defined(__MMI_PREFER_WRITING_LANG__) && defined(__MMI_MIXED_LANG_SUPPORT__)
            if (menu_evt->highlighted_menu_id == MENU_ID_EDITOR_OPT_WRITING_LANGUAGE)
            {
                mmi_ime_commonscreens_entry_writing_language_screen_with_sg(g_id);
            }
            #endif
    
            #if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE)
            {
                mmi_ime_commonscreens_entry_keyboardtype_with_sg(g_id);
            }
            #endif
    
            #if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
            else if (menu_evt->highlighted_menu_id == MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS)
            {
                g_advanced_settings_changed = MMI_FALSE ;
			    g_advanced_settings_menustates_first_enter = MMI_TRUE;
                mmi_ime_commonscreens_entry_advancedoptions_with_sg(g_id);
            }
            #endif
    #endif
#endif
    #endif /* __MMI_IME_PLUG_IN_SETTING__ */
        break;
    default:
        break;
    }
    return ret;
}

#if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_main_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_main_language_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_main_language_screen_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_main_language_screen_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_main_language_screen_with_sg(mmi_id g_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0;
    mmi_common_screen_input_mode_list_history_struct_p input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;
    U16 old_scr_id = 0; 
    UI_string_type nStrItemList[IME_WRITING_LANG_TOTAL];
    //U32 i;
	U16 title_str_id=0;
	#if defined(__ATV_SMS_SUPPORT__)
	   WCHAR* title_str_p;
	#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scr_id = GetActiveScreenId();

    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_MAIN_WRITING_LANGUAGES);
           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
    
        EntryNewScreen(scr_id, mmi_ime_commonscreens_exit_main_language_screen, NULL, NULL);
		#if defined(__ATV_SMS_SUPPORT__)
   				if( matv_init_fptr_ime != NULL )
   				{
						matv_init_fptr_ime();
   				}	
		#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
        input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
        if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_MAIN_WRITING_LANGUAGES, mmi_ime_commonscreens_exit_main_language_screen, mmi_ime_commonscreens_entry_main_language_screen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
        {
            return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
        input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_input_mode_list_history_struct);
	}

    if (input_buffer != NULL)
    {
        MMI_ASSERT(sizeof(mmi_common_screen_input_mode_list_history_struct) == input_buffer_size);
        mmi_imm_create_input_method_list(input_buffer->input_type, input_buffer->mode_array);
        mmi_imm_set_current_input_mode(input_buffer->input_mode);
        mmi_imm_set_current_writing_lang(input_buffer->writing_lang); 
        MMI_current_input_ext_type = input_buffer->input_ext_type;

        InputMethodScreenCloseFunction = input_buffer->input_method_screen_close_function;
        InputMethodScreenEntryCallback = input_buffer->input_method_screen_entry_function;
        InputMethodScreenExitCallback = input_buffer->input_method_screen_exit_function;

        g_mmi_ime_common_scr_entry_callback = input_buffer->entry_callback;
        g_mmi_ime_common_scr_exit_callback = input_buffer->exit_callback;
    }
    
    nNumofItem = mmi_imm_get_curr_allow_writing_language_string_list(nStrItemList, MAX_WRITING_LANG);
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			/* Suggestion from category owner to avoid CS, call EnableCenterSoftkey(), before cagetory show API */
				EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
				#if defined(__MMI_MIXED_LANG_SUPPORT__)
		        title_str_p= (WCHAR*)GetString(STR_WRITING_LANGUAGE_MAIN);
				#else
				title_str_p= (WCHAR*)GetString(STR_INPUT_METHOD_WRITING_LANGUAGE);
				#endif
			wgui_cat1014_show(
		        title_str_p,
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_OK),
                NULL,
                (WCHAR*)GetString(STR_GLOBAL_BACK),
                NULL,
                nNumofItem,
                 (U8 **)nStrItemList,
                0,
                guiBuffer);
		}
		else
		#endif
		{
      #if defined(__MMI_MIXED_LANG_SUPPORT__)
                   	title_str_id = STR_WRITING_LANGUAGE_MAIN;
      #else
                  	title_str_id = STR_INPUT_METHOD_WRITING_LANGUAGE;
      #endif
	ShowCategory36Screen(
                        title_str_id,
                        0, 
                        STR_GLOBAL_OK,
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        nNumofItem, 
                        (U8 **)nStrItemList, 
                        0,
                        guiBuffer);
		}
    SetLeftSoftkeyFunction(mmi_ime_writinglanguage_main_language_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ime_commonscreens_screen_close, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_writinglanguage_main_language_lsk_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  

    if (g_mmi_ime_common_scr_entry_callback)
        g_mmi_ime_common_scr_entry_callback(old_scr_id,GetActiveScreenId());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_main_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_exit_main_language_screen()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__
    U16 inputBufferSize;
    history h;
#endif
    // S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);

    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();

    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

      
    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = mmi_ime_commonscreens_entry_main_language_screen;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);
		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
		GetCategoryHistory(h.guiBuffer);
		AddNHistory(h, inputBufferSize);
		#if defined(__ATV_SMS_SUPPORT__)
			if( dm_is_fixed_layer_mode_enabled() )
			{
   				if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
			}
		#endif
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
    return;


}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_writinglanguage_main_language_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_writinglanguage_main_language_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    //S32 langid =0 ;
    mmi_popup_property_struct callback_popup;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_wlang_change_handler( index);
    #if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			mmi_frm_scrn_close_active_id();
			mmi_mtv_ime_display_popup(STR_GLOBAL_DONE,MMI_EVENT_SUCCESS );
		}
		else
#endif
		{
    
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    mmi_ime_save_screen();
    callback_popup.callback = mmi_ime_commonscreens_screen_close_after_popup2;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
   
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_writinglanguage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_writinglanguage(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if ! defined (__MMI_MIXED_LANG_SUPPORT__)
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_main_language_screen, KEY_EVENT_UP);
	#if defined(__ATV_SMS_SUPPORT__)
   		if( !dm_is_fixed_layer_mode_enabled() )
   		{
    SetKeyHandler(mmi_ime_commonscreens_entry_main_language_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		}
	#else
			SetKeyHandler(mmi_ime_commonscreens_entry_main_language_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	#endif 
    	SetCenterSoftkeyFunction(mmi_ime_commonscreens_entry_main_language_screen, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_writing_language_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_ime_commonscreens_entry_writing_language_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    	SetCenterSoftkeyFunction(mmi_ime_commonscreens_entry_writing_language_screen, KEY_EVENT_UP);
#endif    

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK); 
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
}

#if defined(__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_hint_mainlanguage
 * DESCRIPTION
 *  Hint handler for main language menu in writing language screen (in case mixed language is enabled 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_hint_mainlanguage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lang_id =0;
    S32 i =0;
    mmi_imm_support_writing_lang_enum main_lang_id = mmi_imm_get_main_lang();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (mmi_imm_is_curr_allowed_wlang(main_lang_id))
    {
        while (g_ime_writing_lang_array[i].lang_id != main_lang_id)
        {
            i++;
        }
    }
    if (g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_NONE)
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_NONE));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) g_ime_writing_lang_array[i].lang_str_ptr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_hint_sublanguage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_hint_sublanguage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lang_id =0;
    mmi_imm_support_writing_lang_enum  sub_lang_id = mmi_imm_get_sub_lang();
    mmi_imm_support_writing_lang_enum  main_lang_id = mmi_imm_get_main_lang();
    S32 i =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (g_ime_writing_lang_array[i].lang_id != main_lang_id)
    {
        i++;
    }

    if ( (g_ime_writing_lang_array[i].mixed_lang_support == MMI_FALSE) || ( !mmi_imm_is_curr_allowed_wlang(main_lang_id)) )
    {
            mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_NONE));
            return;
    }

    if (!mmi_imm_is_curr_allowed_wlang(sub_lang_id))
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_NONE));
        return;
    }
    while (g_ime_writing_lang_array[i].lang_id != sub_lang_id)
    {
        i++;
    }
    if ((sub_lang_id == 0xFF) || (g_ime_writing_lang_array[i].lang_id == IME_WRITING_LANG_NONE && g_ime_writing_lang_array[i].mixed_lang_support == MMI_FALSE))
    {
        mmi_ucs2cpy((S8*) hintData[index], GetString(STR_GLOBAL_NONE));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[index], (S8*) g_ime_writing_lang_array[i].lang_str_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_writing_language_screen_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_writing_language_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_writing_language_screen_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_writing_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_writing_language_screen_with_sg(mmi_id g_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nNumofItem;        
    U16 nDispAttribute;     
    U8 *ItemType[2];
    U8 *StringItem[4];
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 scr_id = 0;
    U16 nStrItemList[4];
    U16 nImageItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    U16 i = 0;
    mmi_common_screen_input_mode_list_history_struct_p input_buffer;
    U16 input_buffer_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FRM_HISTORY__)
    if (g_id == GRP_ID_INVALID)
    {
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_WRITING_LANGUAGES);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
        EntryNewScreen(scr_id, mmi_ime_commonscreens_exit_writing_language_screen, NULL, NULL);
        #if defined(__ATV_SMS_SUPPORT__)
   			/* if( !dm_is_fixed_layer_mode_enabled() ) */
   			{
        	  if(matv_init_fptr_ime !=NULL)
							matv_init_fptr_ime();
   			}
			#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
        input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
    }
    else
#endif
    {
        if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_WRITING_LANGUAGES, mmi_ime_commonscreens_exit_writing_language_screen, mmi_ime_commonscreens_entry_writing_language_screen, 0) == MMI_FALSE)
        {
             return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
        input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_input_mode_list_history_struct);
    }
    

    nNumofItem = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);

    nDispAttribute = GetDispAttributeOfItem(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
    GetSequenceStringIds_Ext(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, nStrItemList);
    for (i = 0; i < nNumofItem; i++)
        StringItem[i] = (U8*) GetString(nStrItemList[i]);
    SetParentHandler(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ConstructHintsList(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, ItemType);
#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
        wgui_cat1019_show(
             (WCHAR*)GetString(STR_INPUT_METHOD_WRITING_LANGUAGE),
             NULL,
             (WCHAR*)GetString(STR_GLOBAL_OK),
             (PU8)GetImage(IMG_GLOBAL_OK),
             (WCHAR*)GetString(STR_GLOBAL_BACK),
             (PU8)GetImage(IMG_GLOBAL_BACK),
             nNumofItem,
             StringItem,
             ItemType,
             (PU16) gIndexIconsImageList,        
             0,
             guiBuffer);
      
    }
    else
#endif
    {
    ShowCategory354Screen(
        (U8*) GetString(STR_INPUT_METHOD_WRITING_LANGUAGE),
        STR_INPUT_METHOD_WRITING_LANGUAGE,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        StringItem,
        ItemType,
        (PU16) gIndexIconsImageList,        
        0,
        guiBuffer);
    }

    SetRightSoftkeyFunction(mmi_ime_commonscreens_screen_close, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_writing_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_exit_writing_language_screen()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__
    U16 inputBufferSize;
    history h;
#endif
    S32 mode_num = 0;
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);

    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();
    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

      
    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

    g_id = mmi_frm_group_get_active_id();
    #ifdef __MMI_FRM_HISTORY__  
    if (g_id == GRP_ID_INVALID)
    {
        h.scrnID = GetExitScrnID();
        h.entryFuncPtr = mmi_ime_commonscreens_entry_writing_language_screen;

        inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);
        MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
        memcpy(h.inputBuffer, input_method_history, inputBufferSize);
        GetCategoryHistory(h.guiBuffer);
        AddNHistory(h, inputBufferSize);
    }
    else
    #endif 
    {
        mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
        mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
    }

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
    return;
}

#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) */

#endif /* defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__) */

#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_imeoptions
 * DESCRIPTION
 * Highlight handler for imeoptions  of editor options menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_imeoptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_imeoptions, KEY_EVENT_UP);
    SetKeyHandler(mmi_ime_commonscreens_entry_imeoptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_matv_exit_imeoptions
 * DESCRIPTION
 *  Exit function for imeoptions screen for matv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_matv_exit_imeoptions()
{
	#ifdef __ATV_SMS_SUPPORT__
	    if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_imeoptions
 * DESCRIPTION
 *  Entry screen for imeoptions screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_imeoptions(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_imeoptions_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_imeoptions_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_imeoptions_with_sg(mmi_id g_id)
{ 
   #if !defined (__MMI_IME_V3__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // U16 scr_id = 0;
   	#if defined(__ATV_SMS_SUPPORT__)
    U16 nStrItemList[5] ;
    U8  i;
    MMI_BOOL entry_ret;
    U8 nNumofItem = 5;
	U8 *guiBuffer;
  #endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* We need to show full screen in cas of Java as its not implmenting CUI  :(   .Once  they  implement CUI ,we can remove all
the hilite handlers */
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
	#if defined(__ATV_SMS_SUPPORT__)
			if(matv_init_fptr_ime != NULL)
						matv_init_fptr_ime(); // needs to discuss with the owner of this function
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			EntryNewScreen(SCR_INPUT_METHOD_OPTIONS, mmi_ime_matv_exit_imeoptions, NULL, NULL);
			guiBuffer = GetCurrGuiBuffer(SCR_INPUT_METHOD_OPTIONS);
	    GetSequenceStringIds_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, nStrItemList);
	    nNumofItem = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS);

        SetParentHandler(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
				ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		wgui_list_menu_enable_access_by_shortcut();
		wgui_cat1018_show(
                   (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
                   NULL,
                   (WCHAR*)GetString(STR_GLOBAL_SELECT),
                   (PU8)GetImage(IMG_GLOBAL_OK),
                   (WCHAR*)GetString(STR_GLOBAL_BACK),
                   (PU8)GetImage(IMG_GLOBAL_BACK),
                   nNumofItem,
                   nStrItemList,
                   (PU16) gIndexIconsImageList,
                   0,
                   guiBuffer);
     /*   ShowCategory15Screen(
            STR_INPUT_METHOD_OPTIONS,
            0,
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nNumofItem,
            nStrItemList,           
            (PU16)gIndexIconsImageList,
            LIST_MENU,
            0,
            NULL); */

        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
#endif
}
#endif
#endif
}


#if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
#if  defined(__MMI_MIXED_LANG_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_sublanguage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_sublanguage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_sub_language_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_ime_commonscreens_entry_sub_language_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_writing_language_screen_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_sub_language_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_sub_language_screen_with_sg(g_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_sub_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_sub_language_screen_with_sg(mmi_id g_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0;
    mmi_common_screen_input_mode_list_history_struct_p input_buffer;
    U16 input_buffer_size;
    U16 scr_id = 0;
    U16 old_scr_id = 0; 
    UI_string_type nStrItemList[IME_WRITING_LANG_TOTAL];
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_scr_id = GetActiveScreenId();

    if (InputMethodScreenEntryCallback != NULL)
        InputMethodScreenEntryCallback();
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_SUB_WRITING_LANGUAGES);
           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
  
        EntryNewScreen(scr_id, ExitInputMethodScreen, NULL, NULL);
        guiBuffer = GetCurrGuiBuffer(scr_id);
        input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)GetCurrNInputBuffer(scr_id, &input_buffer_size);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_SUB_WRITING_LANGUAGES, mmi_ime_commonscreens_exit_sub_language_screen, mmi_ime_commonscreens_entry_sub_language_screen, 0) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
		input_buffer = (mmi_common_screen_input_mode_list_history_struct_p)mmi_frm_scrn_get_active_input_buf();
        input_buffer_size = sizeof(mmi_common_screen_input_mode_list_history_struct);
	}

    if (input_buffer != NULL)
    {
        MMI_ASSERT(sizeof(mmi_common_screen_input_mode_list_history_struct) == input_buffer_size);
        mmi_imm_create_input_method_list(input_buffer->input_type, input_buffer->mode_array);
        mmi_imm_set_current_input_mode(input_buffer->input_mode);
        MMI_current_input_ext_type = input_buffer->input_ext_type;
        InputMethodScreenCloseFunction = input_buffer->input_method_screen_close_function;
        InputMethodScreenEntryCallback = input_buffer->input_method_screen_entry_function;
        InputMethodScreenExitCallback = input_buffer->input_method_screen_exit_function;
        g_mmi_ime_common_scr_entry_callback = input_buffer->entry_callback;
        g_mmi_ime_common_scr_exit_callback = input_buffer->exit_callback;
    }
    
    nNumofItem = mmi_imm_get_curr_allow_sub_language_string_list(nStrItemList, MAX_WRITING_LANG);
    ShowCategory36Screen(STR_WRITING_LANGUAGE_SUB, 
                    0, 
                    STR_GLOBAL_OK,
                    IMG_GLOBAL_OK,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    nNumofItem, 
                    (U8 **)nStrItemList, 
                    0,/*mmi_imm_map_wlang_logical_index_ui_index_for_sub(mmi_imm_get_sub_lang()), */
                    guiBuffer);

    SetLeftSoftkeyFunction(mmi_ime_writinglanguage_sub_language_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_writinglanguage_sub_language_lsk_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  


    if (g_mmi_ime_common_scr_entry_callback)
        g_mmi_ime_common_scr_entry_callback(old_scr_id,GetActiveScreenId());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_sub_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_exit_sub_language_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
    U16 inputBufferSize;
    S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);

    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();

    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

      
    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = mmi_ime_commonscreens_entry_sub_language_screen;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);
		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
		GetCategoryHistory(h.guiBuffer);
		AddNHistory(h, inputBufferSize);
	}
	else
	#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_writinglanguage_sub_language_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_writinglanguage_sub_language_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    S32 langid = 0;
    UI_string_type nStrItemList[IME_WRITING_LANG_TOTAL];
    mmi_popup_property_struct callback_popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* in case the sub language is none */
    if (mmi_imm_get_curr_allow_sub_language_string_list(nStrItemList, MAX_WRITING_LANG) > 1)
    {
        langid = mmi_imm_map_wlang_ui_index_sub_lang(index);
        mmi_imm_set_sub_lang(langid);
    }


    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    mmi_ime_save_screen();
    callback_popup.callback = mmi_ime_commonscreens_screen_close_after_popup2;
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_sub_language_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_sub_language_screen_lsk_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetHighlightedItem();
    U8 i = 0;
    U8 j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(g_ime_writing_lang_array[i].lang_id != IME_WRITING_LANG_NONE)
    {
        if (g_ime_writing_lang_array[i].enabled = MMI_TRUE)
        {
            j++;
            if ( j == (index +1))
            break;
        }
        i++;
    }

    mmi_imm_set_sub_lang(g_ime_writing_lang_array[i].lang_id);
    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_newword
 * DESCRIPTION
 *  Hilight handler for highlight new word menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_newword(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_USER_DATABASE__)

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imc_entry_add_new_word_screen, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  

    SetLeftSoftkeyFunction(mmi_imc_entry_add_new_word_screen, KEY_EVENT_UP);
	#if defined(__ATV_SMS_SUPPORT__)
		if(!dm_is_fixed_layer_mode_enabled())
		{
    SetKeyHandler(mmi_imc_entry_add_new_word_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		}	
	#else
			SetKeyHandler(mmi_imc_entry_add_new_word_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	#endif
#endif
}

#if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_advancedoptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_advancedoptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_commonscreens_entry_advancedoptions, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_advancedoptions, KEY_EVENT_UP);
    #if defined(__ATV_SMS_SUPPORT__)
    if(!dm_is_fixed_layer_mode_enabled())
    {
        SetKeyHandler(mmi_ime_commonscreens_entry_advancedoptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }	
    #else
    SetKeyHandler(mmi_ime_commonscreens_entry_advancedoptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedoptions_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_advancedoptions_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_highlighted_advancedimesetting = item_index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedsettings_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_ime_commonscreens_advancedsettings_confirm_callback (mmi_event_struct *evt)
{
   /*--------------------------------------------------------------*/
   /* Local Variables                                                */
   /*--------------------------------------------------------------*/
       
   
   /*--------------------------------------------------------------*/
   /* Code Body                                                      */
   /*--------------------------------------------------------------*/
  switch (evt->evt_id)
   {
       case EVT_ID_ALERT_QUIT :
               {
                       mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct *)evt;

                       switch(alert->result)
                       {
                               case MMI_ALERT_CNFM_YES:
                                             mmi_ime_commonscreens_popup_lsk_done_hdlr();

                                       break;
                               case MMI_ALERT_CNFM_NO:
								   #if defined(__ATV_SMS_SUPPORT__)
   										if( dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime != NULL)
											mmi_frm_go_back_2_history();
										else
										#else
										{
                                     mmi_ime_commonscreens_screen_close_saved();
										}
										#endif 
                                       break;
                       }
               }
       }
   return MMI_RET_OK;
}

void mmi_ime_commonscreens_popup_lsk_done_hdlr(void)
{
	mmi_popup_property_struct callback_popup;
    g_advanced_settings_changed = MMI_TRUE ;
	/* remove confirmation popup */
	mmi_ime_commonscreens_screen_close_saved();
	/* backup screen so that it can be removed in callback */
	mmi_ime_commonscreens_advancedoptions_save();

	/* display popup */
	mmi_popup_property_init(& callback_popup);
	#if defined(__ATV_SMS_SUPPORT__) 
	if(dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime!=NULL)
	callback_popup.parent_id = GRP_ID_ROOT;
	else
	#endif
	{
	callback_popup.parent_id = mmi_frm_group_get_active_id();
	}
	callback_popup.callback = mmi_ime_commonscreens_screen_close_after_popup;
	#if defined(__ATV_SMS_SUPPORT__)
	if( dm_is_fixed_layer_mode_enabled() )
	{
	mmi_mtv_ime_display_popup(STR_GLOBAL_SAVED,MMI_EVENT_SUCCESS );
	}
	else
	#endif /*__ATV_SMS_SUPPORT__*/
	{
	mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
	}
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedoptions_rsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_close_active_group(void)
{
	MMI_ID curr_id = mmi_frm_group_get_active_id();
	mmi_frm_group_close(curr_id);
}

void mmi_ime_commonscreens_advancedoptions_rsk_handler(void)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_popup;
    mmi_confirm_property_init(&confirm_popup,CNFM_TYPE_YESNO);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#if !defined ( __MMI_IME_FTE_ENHANCE__)
//  mmi_ime_commonscreens_screen_close();
//#else

/* On the basis of selection in Popup */
    mmi_ime_save_screen();
    confirm_popup.f_auto_map_empty_softkey = MMI_FALSE;
	#if defined(__ATV_SMS_SUPPORT__) 
             if(dm_is_fixed_layer_mode_enabled())
					confirm_popup.parent_id = GRP_ID_ROOT;
			else
	#endif
	{
    confirm_popup.parent_id = mmi_frm_group_get_active_id() ;
	}
    confirm_popup.callback = mmi_ime_commonscreens_advancedsettings_confirm_callback;
    mmi_confirm_display((UI_string_type)GetString(STR_GLOBAL_SAVE_ASK), MMI_EVENT_QUERY, &confirm_popup);
	
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_ime_commonscreens_popup_lsk_done_hdlr, KEY_EVENT_UP);
	register_center_softkey_to_enter_key();
	redraw_center_softkey();

//#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_advancedoptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_advancedoptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_advancedoptions_with_sg(g_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_advancedoptions_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_advancedoptions_with_sg(mmi_id g_id)
{
#if !defined(__MMI_IME_V3__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
   // mmi_common_screen_input_mode_list_history_struct_p input_buffer;
   // U16 input_buffer_size;
    U16 scr_id = 0;
    U16 nStrItemList[4];
   // U16 nImageItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    U16 i = 0;
//#if defined (__MMI_IME_FTE_ENHANCE__)
    U16 list_num;
    U8* ItemList[4] =  {0,0,0,0};
//#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* Set initial states  Also maintain the order of Menuitem*/
#if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
	if(g_advanced_settings_menustates_first_enter == MMI_TRUE)
	{
    g_advanced_settings_menustates[i] = mmi_imm_is_auto_capitalization_enabled();
	}
    i++;
#endif
#if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
    if(g_advanced_settings_menustates_first_enter == MMI_TRUE)
	{
    g_advanced_settings_menustates[i] = mmi_imm_is_auto_completion_enabled();
	}
    i++;
#endif
#if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
	if(g_advanced_settings_menustates_first_enter == MMI_TRUE)
	{
     g_advanced_settings_menustates[i] = mmi_imm_is_chinese_word_prediction_enabled();
	}
    i++;
#endif
#if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
	if(g_advanced_settings_menustates_first_enter == MMI_TRUE)
	{
    g_advanced_settings_menustates[i] = mmi_imm_is_alphabetic_word_prediction_enabled();
	}
    i++;
#endif




#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_ADVANCED_OPTIONS);
           #if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
           mmi_imm_config_auto_capitalization_setting_changed(MMI_FALSE);
           #endif
           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
        EntryNewScreen(scr_id,mmi_ime_commonscreens_exit_advancedoptions , NULL, NULL);
        #if defined(__ATV_SMS_SUPPORT__)
   		/* if( !dm_is_fixed_layer_mode_enabled() ) */ 
   		{
             if(matv_init_fptr_ime !=NULL)
								matv_init_fptr_ime();
   		}
		#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_ADVANCED_OPTIONS, mmi_ime_commonscreens_exit_advancedoptions, mmi_ime_commonscreens_entry_advancedoptions, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
	}
	GetSequenceStringIds_Ext(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS, nStrItemList);
    SetParentHandler(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
    RegisterHighlightHandler(mmi_ime_commonscreens_advancedoptions_highlight_hdlr);
#if !defined (__MMI_IME_FTE_ENHANCE__)

#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
			/* Suggestion from category owner to avoid CS, call EnableCenterSoftkey(), before cagetory show API */
			EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    	wgui_cat1015_show(
          (WCHAR*)GetString(STR_INPUT_METHOD_ADVANCED_OPTIONS),
          NULL,
          (WCHAR*)GetString(STR_GLOBAL_SAVE),
          NULL,
          (WCHAR*)GetString(STR_GLOBAL_BACK),
          GetImage(IMG_GLOBAL_BACK),
          i, 
          nStrItemList, 
          g_advanced_settings_menustates,
          0, 
          guiBuffer);
    }
    else
#endif
    {
list_num = GetNumOfChild_Ext(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
    for( i = 0; i < list_num ; i ++)
    {
	    ItemList[i] = (U8*) GetString(nStrItemList[i]);
    }
	SetCheckboxToggleRightSoftkeyFunctions(mmi_ime_commonscreens_advancedoptions_rsk_handler,mmi_ime_commonscreens_screen_close);

	ShowCategory140Screen(
        STR_INPUT_METHOD_ADVANCED_OPTIONS,
        0,
        list_num,
        ItemList,
        g_advanced_settings_menustates,
        0,
        guiBuffer);
	}
/*	ShowCategory13Screen(STR_INPUT_METHOD_ADVANCED_OPTIONS, 
                        0, 
                        STR_GLOBAL_SAVE,
                        0,
                        STR_GLOBAL_BACK,                 
                        IMG_GLOBAL_BACK,
                        i, 
                        nStrItemList, 
                        g_advanced_settings_menustates,
                        0, 
                        guiBuffer);
    }
    #ifdef __MMI_TOUCH_SCREEN__                   
    MMI_fixed_list_menu.disable_up_select = MMI_FALSE;                 
    wgui_register_list_tap_callback(mmi_ime_commonscreens_advancedoptions_csk_handler);
    #endif
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_advancedoptions_save, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ime_commonscreens_screen_close, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_MARK_CSK);
    SetCenterSoftkeyFunction(mmi_ime_commonscreens_advancedoptions_csk_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey(); */
#else
list_num = GetNumOfChild_Ext(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
    for( i = 0; i < list_num ; i ++)
    {
	    ItemList[i] = (U8*) GetString(nStrItemList[i]);
    }
	SetCheckboxToggleRightSoftkeyFunctions(mmi_ime_commonscreens_advancedoptions_rsk_handler,mmi_ime_commonscreens_screen_close);
#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
	    wgui_cat1016_show(
            (WCHAR*)GetString(STR_INPUT_METHOD_ADVANCED_OPTIONS),
            NULL,
            list_num,
            (U8 **)ItemList,
            g_advanced_settings_menustates,
            0,
            guiBuffer);
    }
    else
#endif
    {
    ShowCategory140Screen(
        STR_INPUT_METHOD_ADVANCED_OPTIONS,
        0,
        list_num,
        ItemList,
        g_advanced_settings_menustates,
        0,
        guiBuffer);
    }

#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_advancedoptions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_ime_commonscreens_exit_advancedoptions()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__ 
    U16 inputBufferSize;
    history h;
#endif
//    S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);

    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();

    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

      
    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = mmi_ime_commonscreens_entry_advancedoptions;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);
		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
		GetCategoryHistory(h.guiBuffer);
		AddNHistory(h, inputBufferSize);
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
	g_advanced_settings_menustates_first_enter = MMI_FALSE; 
    #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
    return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedoptions_csk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_advancedoptions_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
/* toggle is occuring */

    g_advanced_settings_changed = MMI_TRUE ;


    if ( g_advanced_settings_menustates[g_current_highlighted_advancedimesetting])
    {
        g_advanced_settings_menustates[g_current_highlighted_advancedimesetting] = MMI_FALSE;
    }
    else
    {
        g_advanced_settings_menustates[g_current_highlighted_advancedimesetting] = MMI_TRUE;
    }
    standard_check_list_handle_item_select(g_current_highlighted_advancedimesetting);

    return;
  
}
#if defined(__ATV_SMS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_save_popup_callback
 * DESCRIPTION
 *  Popup callback function needed for matv feature 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_save_popup_callback(void)
{
	/* Needed for synchronizations between matv and normal case */ 
	mmi_frm_go_back_2_history();
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_advancedoptions_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ime_commonscreens_advancedoptions_save()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
# if !defined(__MMI_IME_FTE_ENHANCE__)
    mmi_popup_property_struct callback_popup;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
# if !defined(__MMI_IME_FTE_ENHANCE__)
if(    g_advanced_settings_changed )
{
#endif
    #if defined(__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
        mmi_imm_config_auto_capitalization((MMI_BOOL)g_advanced_settings_menustates[i] ); 
        i++;
    #endif
    #if defined(__MMI_IME_AUTO_COMPLETION_SETTING__)
       mmi_imm_config_auto_completion( (MMI_BOOL)g_advanced_settings_menustates[i] );
        i++;
    #endif

	  
    #if  defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
         mmi_imm_config_chinese_word_prediction((MMI_BOOL)g_advanced_settings_menustates[i]);
        i++;
    #endif

    #if defined(__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
       mmi_imm_config_alphabetic_word_prediction((MMI_BOOL)g_advanced_settings_menustates[i]);
        i++;
    #endif

    mmi_ime_save_screen();
# if !defined(__MMI_IME_FTE_ENHANCE__)
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = mmi_ime_commonscreens_screen_close_after_popup2;
	#if defined(__ATV_SMS_SUPPORT__)
		if( dm_is_fixed_layer_mode_enabled() )
		{
			mmi_frm_scrn_close_active_id();			
			mmi_mtv_ime_display_popup(STR_GLOBAL_SAVED,MMI_EVENT_SUCCESS );
		/* mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_SAVED),MMI_EVENT_SUCCESS);
		    mmi_display_popupcallback((UI_string_type)GetString(STR_GLOBAL_SAVED),MMI_EVENT_SUCCESS, mmi_save_popup_callback);	 */ 
		}
		else
		{
			mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
		}
	#else
		mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
	#endif
#endif
# if !defined(__MMI_IME_FTE_ENHANCE__)
}
else
{
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() )
   		{
			mmi_frm_scrn_close_active_id();
		}
		else
		#endif
		{
    mmi_frm_scrn_close(mmi_frm_group_get_active_id(), mmi_frm_scrn_get_active_id());
		}
}
#endif
}
#endif


#if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_keyboard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_keyboard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_commonscreens_entry_keyboardtype, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_entry_keyboardtype, KEY_EVENT_UP);
	#if defined(__ATV_SMS_SUPPORT__)
   		if(!dm_is_fixed_layer_mode_enabled() )
   		{
    SetKeyHandler(mmi_ime_commonscreens_entry_keyboardtype, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		}
	#else
			SetKeyHandler(mmi_ime_commonscreens_entry_keyboardtype, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_keyboardtype
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_keyboardtype(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    mmi_ime_commonscreens_entry_keyboardtype_with_sg(g_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_entry_keyboardtype
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_entry_keyboardtype_with_sg(mmi_id g_id)
{
#if !defined (__MMI_IME_V3__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem = 0;
   // mmi_common_screen_input_mode_list_history_struct_p input_buffer;
   // U16 input_buffer_size;
    U16 scr_id = 0;
    U16 nStrItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
   // U16 nImageItemList[MMI_IMM_MAX_INPUT_METHOD_NUM];
    S32 i = 0;
  //  U8 ItemListState[4] ={0,0,0,0};
    S32 hilite_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    for ( i = 0 ; i < COMMONSCREENS_KEYPAD_TOTAL ; i ++ )
    {
        g_mmi_ime_commonscreens_keypad_menu[i].is_shown = MMI_TRUE;
        g_mmi_ime_commonscreens_keypad_menu[i].menu_id  = (keypadtype_enum)i;
    }
#if defined(__MMI_FRM_HISTORY__)
	if (g_id == GRP_ID_INVALID)
	{
        if (CheckIsBackHistory())
        {
           scr_id = GetCurrScrnId();
        }
        else
        {
           scr_id = mmi_ime_gen_editor_common_scr_id(SCR_INPUT_METHOD_KEYBOARD_TYPE);

           if (!scr_id)
           {
              MMI_ASSERT(0);
           }
        }
   
        EntryNewScreen(scr_id,mmi_ime_commonscreens_exit_keyboardtype , NULL, NULL);
        #if defined(__ATV_SMS_SUPPORT__)
   			/* if( !dm_is_fixed_layer_mode_enabled() ) */ 
   			{
             if(matv_init_fptr_ime !=NULL)
								matv_init_fptr_ime();
   			}
				#endif
        guiBuffer = GetCurrGuiBuffer(scr_id);
	}
	else
#endif
	{
		if (mmi_frm_scrn_enter(g_id , SCR_INPUT_METHOD_KEYBOARD_TYPE, mmi_ime_commonscreens_exit_keyboardtype, mmi_ime_commonscreens_entry_keyboardtype, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
		{
			return;
		}
		guiBuffer = mmi_frm_scrn_get_active_gui_buf();	
	}
    #if defined(__MMI_TOUCH_SCREEN__) && ( !defined(__MMI_NO_HANDWRITING__) )

        for ( i = 0 ;  g_mmi_ime_commonscreens_keypad_menu[i].menu_id != COMMONSCREENS_KEYPAD_HANDWRITING ; i ++ );

    if ( mmi_imm_get_handwriting_setting())
    {
        mmi_frm_unhide_menu_item(MENU_ID_COMMONSCREENS_KEYPAD_HANDWRITING);
        g_mmi_ime_commonscreens_keypad_menu[i].is_shown = MMI_TRUE;
       
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_COMMONSCREENS_KEYPAD_HANDWRITING);
        g_mmi_ime_commonscreens_keypad_menu[i].is_shown = MMI_FALSE;
    }
    #endif


    GetSequenceStringIds_Ext(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE, nStrItemList);
	nNumofItem = GetNumOfChild_Ext(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE);

    SetParentHandler(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    hilite_index = mmi_imm_get_keyboard_type();
    /* for cases where handwriting is current but i hidden */
    if ( hilite_index >= nNumofItem)
    {
        hilite_index = 0;
    }
#if defined(__ATV_SMS_SUPPORT__)
    if( dm_is_fixed_layer_mode_enabled() )
    {
    	wgui_cat1017_show(
            (WCHAR*)GetString(STR_INPUT_METHOD_KEYBOARD_TYPE),
            NULL,
            (WCHAR*)GetString(STR_GLOBAL_OK),
            (PU8)GetImage(IMG_GLOBAL_OK),
            (WCHAR*)GetString(STR_GLOBAL_BACK),
            (PU8)GetImage(IMG_GLOBAL_BACK),
            nNumofItem, 
            nStrItemList, 
            hilite_index, 
            guiBuffer); 
    }
    else
#endif
    {
	ShowCategory11Screen(STR_INPUT_METHOD_KEYBOARD_TYPE, 
                        0, 
                        STR_GLOBAL_OK,
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        nNumofItem, 
                        nStrItemList, 
                        hilite_index, 
                        guiBuffer);
   	}
    
    SetLeftSoftkeyFunction(mmi_ime_commonscreens_keyboard_lsk_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_ime_commonscreens_screen_close, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_ime_commonscreens_keyboard_lsk_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_exit_keyboardtype
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_exit_keyboardtype(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_common_screen_input_mode_list_history_struct_p input_method_history;
#ifdef __MMI_FRM_HISTORY__
    U16 inputBufferSize;
    history h;
#endif
    //S32 mode_num = 0;
	mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&mmi_common_screen_history, 0, sizeof(mmi_common_screen_history_union));
    input_method_history = &(mmi_common_screen_history.input_method_history);

    if (InputMethodScreenExitCallback != NULL)
        InputMethodScreenExitCallback();

    input_method_history->input_type = mmi_imm_get_curr_input_type();

    input_method_history->input_method_screen_close_function = InputMethodScreenCloseFunction;
    input_method_history->input_method_screen_entry_function = InputMethodScreenEntryCallback;
    input_method_history->input_method_screen_exit_function = InputMethodScreenExitCallback;

      
    input_method_history->entry_callback = g_mmi_ime_common_scr_entry_callback;
    input_method_history->exit_callback = g_mmi_ime_common_scr_exit_callback;

	g_id = mmi_frm_group_get_active_id();
	#ifdef __MMI_FRM_HISTORY__  
	if (g_id == GRP_ID_INVALID)
	{
		h.scrnID = GetExitScrnID();
		h.entryFuncPtr = mmi_ime_commonscreens_entry_keyboardtype;

		inputBufferSize = sizeof(mmi_common_screen_input_mode_list_history_struct);
		MMI_ASSERT(inputBufferSize < sizeof(h.inputBuffer));
		memcpy(h.inputBuffer, input_method_history, inputBufferSize);
		GetCategoryHistory(h.guiBuffer);
		AddNHistory(h, inputBufferSize);
	}
	else
#endif 
	{
		mmi_frm_scrn_set_active_input_buf_size(sizeof(mmi_common_screen_input_mode_list_history_struct));
		mmi_frm_scrn_set_active_input_buf_ptr((U16*)input_method_history);
	}

    if (g_mmi_ime_common_scr_exit_callback)
        g_mmi_ime_common_scr_exit_callback(GetExitScrnID(),GetActiveScreenId());
   #if defined(__ATV_SMS_SUPPORT__)
   if( dm_is_fixed_layer_mode_enabled() )
   {
   			if(matv_exit_fptr_ime != NULL)
					matv_exit_fptr_ime();
   }
	#endif
    return;

}

    

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_keyboard_lsk_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_keyboard_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = GetCurrHiliteID();
    S32 j = -1;
    S32 i = 0;
    mmi_popup_property_struct callback_popup;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for( i = 0 ; i < COMMONSCREENS_KEYPAD_TOTAL ; i++)
    {
        if (g_mmi_ime_commonscreens_keypad_menu[i].is_shown == MMI_TRUE)
        {
            j++;  
            if ( j == index)
            break ;
        }
    }
    mmi_imm_config_keyboard_type((mmi_imm_keypadtype_enum)i);
    mmi_popup_property_init(& callback_popup);
    callback_popup.parent_id = mmi_frm_group_get_active_id();
    callback_popup.callback = mmi_ime_commonscreens_screen_close_after_popup2;
    mmi_ime_save_screen();
   		#if defined(__ATV_SMS_SUPPORT__)
		if( dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime !=NULL)
		{
			 mmi_display_popupcallback((UI_string_type)GetString(STR_GLOBAL_SAVED),MMI_EVENT_SUCCESS,  mmi_save_popup_callback);		
		}
		else
		{
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
		}
	#else
		 mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &callback_popup);
	#endif
}


#endif


#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_highlight_dictionary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_commonscreens_highlight_dictionary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imc_entry_config_smart_input_method_screen, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
 
    SetLeftSoftkeyFunction(mmi_imc_entry_config_smart_input_method_screen, KEY_EVENT_UP);
#if defined(__ATV_SMS_SUPPORT__)
		if(!dm_is_fixed_layer_mode_enabled())
		{
		    SetKeyHandler(mmi_imc_entry_config_smart_input_method_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		}
#else
			SetKeyHandler(mmi_imc_entry_config_smart_input_method_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif 
}
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_options_show_hide_ime_option_menus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ime_options_show_hide_ime_option_menus(cui_menu_event_struct *menu_evt )
{
       // U16 *menu_list;
#if defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) || defined(__MMI_IME_PLUG_IN_SETTING__)
//#if defined(__MMI_IME_PLUG_IN_SETTING__)
    U16 ItemIDList[10];
//#endif
    S32 list_num = 0;
    U8 i = 0;
#endif      
      //  U16 menu_count = 0;
     
#if defined(__MMI_IME_PLUG_IN_SETTING__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__) || defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)
    if ( mmi_imm_get_curr_input_type () == IMM_INPUT_TYPE_NUMERIC)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INSERT_SYMBOL, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INSERT_SYMBOL, MMI_FALSE);
    }
#endif

#if defined(__MMI_IME_PLUG_IN_SETTING__)
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_TRUE);
    }


    #if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
    if (mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
          mmi_frm_unhide_menu_item(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
    }
    else
    {
          mmi_frm_hide_menu_item(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
    }
    #endif

    #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
        mmi_frm_unhide_menu_item(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
    #endif

    list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS);
    
    /* we wont show any options if there are none also if input type is numeric */
    if ((list_num > 0)  && (!(mmi_imm_get_curr_input_type () == IMM_INPUT_TYPE_NUMERIC)))
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_FALSE);
        cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_TRUE);

        if (menu_evt->parent_menu_id == MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS)
        {
            GetSequenceItemIds_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, ItemIDList);
            cui_menu_set_currlist(menu_evt->sender_id, list_num, ItemIDList);
            for (i = 0; i < list_num; i++)
            {
                cui_menu_set_item_string(
                    menu_evt->sender_id,
                    ItemIDList[i],
                    (UI_string_type)GetString(GetStringIdOfItem(ItemIDList[i])));
            }
        }
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_TRUE);
    }
#else
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_USER_DATABASE__) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
#if !defined(__MMI_IME_V3__)        
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_ADD_NEW_WORD, MMI_FALSE);
    #endif
#endif
    
    #if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    
            #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
           #if !defined(__OP01_FWPBW__)  /* For slim project they don't need smart input method option but they can't turnoff the smart input mode macro*/ 
            if (mmi_imm_is_smart_input_mode_valid())
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD, MMI_FALSE);
            }
            else
           #endif 
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD, MMI_TRUE);
            }
            #endif
    
    #endif
    
    
        #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)
              
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_TRUE);
                }
         
            #if defined(__MMI_IMC_CAPITAL_SWITCH__)
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_TRUE);
                }
            #endif
    
         #elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__)
    
                #if defined(__MMI_IMC_CAPITAL_SWITCH__) 
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_TRUE);
                }
                #else
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_TRUE);
                }
                #endif
    
          #elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
    
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_FALSE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_TRUE);
                }
    
        
#if !defined(__MMI_IME_V3__)
                #if defined(__MMI_PREFER_WRITING_LANG__) || defined (__MMI_MIXED_LANG_SUPPORT__)
                if (mmi_imm_get_current_allowed_input_mode_num() > 1)
                {
                      mmi_frm_unhide_menu_item(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
                }
                else
                {
                      mmi_frm_hide_menu_item(MENU_ID_EDITOR_OPT_WRITING_LANGUAGE);
                }
                #endif
                #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
	    #if !defined(__OP01_FWPBW__) /* For slim project they don't need smart input method option but they can't turnoff the smart input mode macro*/
                if (mmi_imm_is_smart_input_mode_valid())
                {
                     mmi_frm_unhide_menu_item(MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD);
                }
                else
            #endif 
                {
                     mmi_frm_hide_menu_item(MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD);
                }
                #endif
    
               #if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
                list_num = GetNumOfChild_Ext(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE);
                if (list_num > 0) 
                {
                     mmi_frm_unhide_menu_item(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE);
                }
                else
                {
                     mmi_frm_hide_menu_item(MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE);
                }
    
              #endif
    
               #if defined (__MMI_IME_INPUT_ADVANCED_SETTING__)
                        list_num = GetNumOfChild_Ext(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
                if (list_num > 0) 
                {
                     mmi_frm_unhide_menu_item(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
                }
                else
                {
                     mmi_frm_hide_menu_item(MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS);
                }
               #endif
    
           /* ADD ime options  menus here */
            list_num = GetNumOfChild_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS);
            
    /* we wont show any options if there are none also if input type is numeric */
            if ((list_num > 0)  && (!mmi_imm_IsInputTypeNumber())) /* The new interface is needed because applications are using input types that are equivalent to numeric */ 
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_FALSE);
                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_TRUE);
    
                if (menu_evt->parent_menu_id == MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS)
                {
                    GetSequenceItemIds_Ext(MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, ItemIDList);
				    cui_menu_set_currlist_title(menu_evt->sender_id, (WCHAR*)GetString(STR_INPUT_METHOD_OPTIONS), NULL);
                    cui_menu_set_currlist(menu_evt->sender_id, list_num, ItemIDList);
                    for (i = 0; i < list_num; i++)
                    {
                            cui_menu_set_item_string(menu_evt->sender_id,
                            ItemIDList[i], (UI_string_type)GetString(GetStringIdOfItem(ItemIDList[i])));
                    }
                }
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS, MMI_TRUE);
            }
#endif
    #else
            if (mmi_imm_get_current_allowed_input_mode_num() > 1) /* for hiding the input method when no style is on, MAUI_02446139 */ 
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_INPUT_METHOD, MMI_TRUE);
            }
         #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_IMC_CAPITAL_SWITCH__)
            if (mmi_imm_get_current_allowed_input_mode_num() > 1)
            {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_FALSE);
            }
            else
            {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_EDITOR_OPT_WRITING_LANGUAGE, MMI_TRUE);
            }
          #endif 
    #endif
#endif /* defined(__MMI_IME_PLUG_IN_SETTING__) */
}

void mmi_ime_save_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   g_active_ime_group = mmi_frm_group_get_active_id() ;
   g_active_ime_screen = mmi_frm_scrn_get_active_id() ; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_screen_close_saved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ime_commonscreens_screen_close_saved()

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime != NULL)
			GoBacknHistory(1);
		else
	#endif 
		
   mmi_frm_scrn_close(g_active_ime_group, g_active_ime_screen); 

 }

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_commonscreens_screen_close_after_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ime_commonscreens_screen_close_after_popup(mmi_event_struct *param)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime != NULL)
   		{
	//GoBacknHistory(1);
			//mmi_frm_scrn_close(g_active_ime_group, g_active_ime_screen);
		}
		else
	#endif
		{
			return 1;//mmi_frm_scrn_close(g_active_ime_group, g_active_ime_screen);
  
		}
 }
mmi_ret mmi_ime_commonscreens_screen_close_after_popup2(mmi_event_struct *param)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__ATV_SMS_SUPPORT__)
   		if( dm_is_fixed_layer_mode_enabled() || matv_init_fptr_ime != NULL)
   		{
	GoBacknHistory(1);
			//mmi_frm_scrn_close(g_active_ime_group, g_active_ime_screen);
 }
		else
	#endif
		{
			return mmi_frm_scrn_close(g_active_ime_group, g_active_ime_screen);

		}
 }

#ifdef __MMI_TOUCH_SCREEN__
/* Handwriting setting */
#define MAX_PEN_COLORS 8

#define DEFAULT_PEN_COLOR 1

#define PHNSET_HANDWRITING_CAPTION1 (CUI_INLINE_ITEM_ID_BASE + 1)
#define PHNSET_HANDWRITING_SELECT1 (CUI_INLINE_ITEM_ID_BASE + 2)
#define PHNSET_HANDWRITING_CAPTION2 (CUI_INLINE_ITEM_ID_BASE + 3)
#define PHNSET_HANDWRITING_COLORSELECT1 (CUI_INLINE_ITEM_ID_BASE + 4)
#if defined (__MMI_IME_V3__)
#define PHNSET_HANDWRITING_CAPTION3 (CUI_INLINE_ITEM_ID_BASE + 5)
#define PHNSET_HANDWRITING_SELECT2 (CUI_INLINE_ITEM_ID_BASE + 6)

#define PHNSET_HANDWRITING_CAPTION4 (CUI_INLINE_ITEM_ID_BASE + 7)
#define PHNSET_HANDWRITING_SELECT4 (CUI_INLINE_ITEM_ID_BASE + 8)

#define PHNSET_HANDWRITING_CAPTION5 (CUI_INLINE_ITEM_ID_BASE + 9)
#define PHNSET_HANDWRITING_SELECT5 (CUI_INLINE_ITEM_ID_BASE + 10)
#endif
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TOUCH_SCREEN__

#if defined(__MMI_IME_FTE_ENHANCE__)
static const color g_pen_color_list[MAX_PEN_COLORS] = 
{
    {0, 255, 255},
    {234, 125, 9},
    {0, 255, 0},
    {255, 255, 0},
    {255, 0, 255},
    {255, 128, 0},
    {0, 0, 128},
    {0, 0, 0}
};

#else
static const color g_pen_color_list[MAX_PEN_COLORS] = 
{
    {0, 255, 255},
    {255, 0, 0},
    {0, 255, 0},
    {255, 255, 0},
    {255, 0, 255},
    {255, 128, 0},
    {0, 0, 128},
    {0, 0, 0}
};

#endif

#endif /* __MMI_TOUCH_SCREEN__ */ 

/* Handwriting setting */
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
static U16 g_pen_speed_str_id_list[3] = 
{
    STR_GLOBAL_FAST,
    STR_GLOBAL_MEDIUM,
    STR_GLOBAL_SLOW
};
#if defined (__MMI_IME_V3__)
static U16 g_pen_width_str_id_list[5] = 
{
    STR_ID_ONE_PIXEL,
    STR_ID_TWO_PIXEL,
    STR_ID_THREE_PIXEL,
	STR_ID_FOUR_PIXEL,
	STR_ID_FIVE_PIXEL
};
//language_follow_keyboard
static U16 g_pen_lang_follow_keyboard[2] = 
{
    STR_GLOBAL_ON,
	STR_GLOBAL_OFF

};

static U32 follow_keybrd_lang_count = 0 ;
static UI_string_type g_pen_follow_keyboard_lang[MAX_WRITING_LANG] ;
static U16 g_pen_hw_on_off[2] = 
{
    STR_GLOBAL_ON,
	STR_GLOBAL_OFF
};
#endif
static const cui_inline_item_caption_struct g_phnset_handwriting_caption1 =
{
    STR_HANDWRITING_PEN_SPEED
};

#if defined (__MMI_IME_V3__)
static const cui_inline_item_caption_struct g_phnset_handwriting_caption4 =
{
    STR_ID_LANG_FOLO_KEYBOARD
};

static const cui_inline_item_caption_struct g_phnset_handwriting_caption5 =
{
    STR_ID_HW_SETTING
};
/* kuldeep_imev3 */
static const cui_inline_item_caption_struct g_phnset_handwriting_caption3 =
{
    STR_ID_HW_WIDTH
};
#endif
static cui_inline_item_select_struct g_phnset_handwriting_select1 = 
{
    3, /* 3 selections: Fast, Medium, Slow */
    0, /* Will be set at run time */
    g_pen_speed_str_id_list
};
#if defined (__MMI_IME_V3__)
static cui_inline_item_select_struct g_phnset_handwriting_select2 = 
{
    5, /* 3 selections: Fast, Medium, Slow */
    0, /* Will be set at run time */
    g_pen_width_str_id_list
};

//language_follow_keyboard
static cui_inline_item_select_struct g_phnset_handwriting_select3 = 
{
    2, /* 3 selections: Fast, Medium, Slow */
    0, /* Will be set at run time */
    g_pen_lang_follow_keyboard
};

static cui_inline_item_select_struct g_phnset_handwriting_select4 = 
{
    2, /* 3 selections: Fast, Medium, Slow */
    0, /* Will be set at run time */
    g_pen_hw_on_off
};
#endif
static const cui_inline_item_caption_struct g_phnset_handwriting_caption2 =
{
    STR_HANDWRITING_PEN_COLOR
};
static cui_inline_item_color_select_struct g_phnset_handwriting_color_select1 =
{
    MAX_PEN_COLORS,
    0, /* Will be set at run time */
    (color*)g_pen_color_list
};
static cui_inline_set_item_struct g_phnset_handwriting_inline_item_data[] = 
{
#if defined (__MMI_IME_V31__)
	{PHNSET_HANDWRITING_CAPTION5, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&g_phnset_handwriting_caption5},
	{PHNSET_HANDWRITING_SELECT5, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_phnset_handwriting_select4},
#endif
    {PHNSET_HANDWRITING_CAPTION1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&g_phnset_handwriting_caption1},
    {PHNSET_HANDWRITING_SELECT1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_phnset_handwriting_select1},
    {PHNSET_HANDWRITING_CAPTION2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&g_phnset_handwriting_caption2},
#if defined (__MMI_IME_V3__)
    {PHNSET_HANDWRITING_COLORSELECT1, CUI_INLINE_ITEM_TYPE_COLOR_SELECT, 0, (void*)&g_phnset_handwriting_color_select1},
    /* kuldeep_imev3 */
	{PHNSET_HANDWRITING_CAPTION3, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&g_phnset_handwriting_caption3},
	{PHNSET_HANDWRITING_SELECT2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_phnset_handwriting_select2},
	//language_follow_keyboard
#if defined (HANDWRITING_OVER_VK)
	{PHNSET_HANDWRITING_CAPTION4, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&g_phnset_handwriting_caption4},
	{PHNSET_HANDWRITING_SELECT4, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_phnset_handwriting_select3}
#endif
#else
    {PHNSET_HANDWRITING_COLORSELECT1, CUI_INLINE_ITEM_TYPE_COLOR_SELECT, 0, (void*)&g_phnset_handwriting_color_select1}
#endif
};
static const cui_inline_struct g_phnset_handwriting_inline = 
{
    sizeof(g_phnset_handwriting_inline_item_data) / sizeof(cui_inline_set_item_struct),
    STR_ID_HW_SETTING,
#ifdef __PLUTO_MMI_PACKAGE__
    MAIN_MENU_TITLE_SETTINGS_ICON,  
#else
	  NULL ,
#endif
    CUI_INLINE_SCREEN_DEFAULT_TEXT,
    NULL,
    g_phnset_handwriting_inline_item_data
};
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__) */

#ifdef __MMI_PREFER_INPUT_METHOD__
extern U8 *inputMethodList[9];
extern U16 currInputMethodIndex;
#endif /* __MMI_PREFER_INPUT_METHOD__ */ 

#if defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__)
extern ime_writing_lang_struct g_ime_writing_lang_array[MAX_WRITING_LANG];
#endif /* defined(__MMI_MIXED_LANG_SUPPORT__) || defined(__MMI_PREFER_WRITING_LANG__) */ 


#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
/*****************************************************************************
 * FUNCTION
 *  SaveHandwritingSetting
 * DESCRIPTION
 *  This function saves pen setting in Settings->PhoneSetup->PenSetting screen
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveHandwritingSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    //MMI_ID *inlinecui_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //inlinecui_id = (MMI_ID*)mmi_frm_group_get_user_data(GRP_ID_PHNSET_HANDWRITING);
    cui_inline_get_value(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT1,
        (void*)&pen_speed);
    cui_inline_get_value(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_COLORSELECT1,
        (void*)&pen_color);    

#if defined (__MMI_IME_V3__)
    cui_inline_get_value(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT2,
        (void*)&stroke_width); 
#if defined (HANDWRITING_OVER_VK)

    cui_inline_get_value(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT4,
        (void*)&is_follow_vk);  
#endif

    cui_inline_get_value(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT5,
        (void*)&is_hw_enable); 
#endif

    /*
    pen_speed = gInlinePenSpeed;
    pen_color = gInlinePenColorIndex;
    */
    mmi_imm_set_pen_speed((mmi_imm_pen_speed_enum)pen_speed);
    
    WriteValue(NVRAM_PEN_COLOR, &(pen_color), DS_BYTE, &pError);
    if (pError != NVRAM_WRITE_SUCCESS)
    {
        MMI_TRACE(MMI_COMMON_TRC_G7_SETTING, MMI_PHNSET_PENSETTING_COLOR_ERROR, pError);
    }
#if defined (__MMI_IME_V3__)
	mmi_imm_handwriting_set_width((U8)stroke_width);
	mmi_imm_handwriting_set_follow_vk_lang((MMI_BOOL)is_follow_vk);
	mmi_imm_handwriting_enable((MMI_BOOL)is_hw_enable);
#endif	
#if !defined(__MMI_IME_PLUTO_SLIM__)
    mmi_popup_display_simple(
        (WCHAR*) GetString(STR_GLOBAL_SAVED),
        MMI_EVENT_SUCCESS,
        GRP_ID_ROOT,
        NULL);
#endif
    mmi_frm_group_close(GRP_ID_PHNSET_HANDWRITING);
}

#if !defined(__MMI_IME_PLUTO_SLIM__)
/*****************************************************************************
 * FUNCTION
 *  EntryScrHandwritingSettingConfirm
 * DESCRIPTION
 *  This function displays pop up to confirm pen settings change before saving them in Settings->PhoneSetup->PenSetting screen
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrHandwritingSettingConfirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
    confirm_arg.callback = NULL;
    confirm_arg.parent_id = GRP_ID_PHNSET_HANDWRITING;
		//mmi_frm_group_get_active_id() ;
    mmi_confirm_display(
        (WCHAR*)GetString(STR_GLOBAL_SAVE_ASK),
		MMI_EVENT_QUERY,
        &confirm_arg);    
}
#endif //#if !defined(__MMI_IME_PLUTO_SLIM__)

/*****************************************************************************
 * FUNCTION
 *  EntryHandWritingSettingScr
 * DESCRIPTION
 *  Entry function for Pen Setting Screen
 * PARAMETERS
 *  void
 *  a(?)        [IN]        
 *  b(?)        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
 void EntryHandWritingSettingScr(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_ID *inlinecui_gid;
	//MMI_ID temp_gp_id ;
	S16 Err = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_PHNSET_HANDWRITING))
	{
	    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_NOT_AVAILABLE, GRP_ID_ROOT, NULL);
        return;
	}
    if (!parent_gid)
	{
	    parent_gid = GRP_ID_ROOT;
	}
   // inlinecui_gid = (MMI_ID*)OslMalloc(sizeof(MMI_ID));
///*
//    temp_gp_id = mmi_frm_group_create_ex(
//        parent_gid/*GRP_ID_ROOT*/,
//        /*GRP_ID_PHNSET_HANDWRITING*/GRP_ID_AUTO_GEN,
//        mmi_phnset_handwriting_proc,
//        (void*)inlinecui_gid,
//		MMI_FRM_NODE_SMART_CLOSE_FLAG);
//    //mmi_frm_group_enter(GRP_ID_PHNSET_HANDWRITING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
//*/

mmi_frm_group_create(
        parent_gid,
        GRP_ID_PHNSET_HANDWRITING,
        mmi_phnset_handwriting_proc,
        NULL);
    mmi_frm_group_enter(GRP_ID_PHNSET_HANDWRITING, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_hw_inlinecui_gid = cui_inline_create(GRP_ID_PHNSET_HANDWRITING, &g_phnset_handwriting_inline);

    pen_speed = (U8)mmi_imm_get_pen_speed();
    
    cui_inline_set_value(g_hw_inlinecui_gid, PHNSET_HANDWRITING_SELECT1, (void*)pen_speed);

	//get the Pen color 
    ReadValue(NVRAM_PEN_COLOR, &(pen_color), DS_BYTE, &Err);
    if (pen_color == 0xFF || Err != NVRAM_READ_SUCCESS || pen_color >= MAX_PEN_COLORS)
    {
        pen_color = DEFAULT_PEN_COLOR;
	}
    cui_inline_set_value(g_hw_inlinecui_gid, PHNSET_HANDWRITING_COLORSELECT1, (void*)pen_color);

    #if defined (__MMI_IME_V3__)
	stroke_width = mmi_imm_handwriting_get_stroke_width();
	cui_inline_set_value(g_hw_inlinecui_gid, PHNSET_HANDWRITING_SELECT2, (void*)stroke_width);

	//language_follow_keyboard
#if defined (HANDWRITING_OVER_VK)
	is_follow_vk = mmi_imm_handwriting_is_follow_vk();
	cui_inline_set_value(g_hw_inlinecui_gid, PHNSET_HANDWRITING_SELECT4, (void*)is_follow_vk);

#endif
	is_hw_enable = mmi_imm_handwriting_is_enable();
	cui_inline_set_value(g_hw_inlinecui_gid, PHNSET_HANDWRITING_SELECT5, (void*)is_hw_enable);
    #endif
    cui_inline_run(g_hw_inlinecui_gid);
}

#if defined (__MMI_IME_V3__)
 static U16 Followkeybrd_highlighted_index ;
 void mmi_ime_settings_highlight_current_keyboard_lang(S32 index)
{
    Followkeybrd_highlighted_index = (U8) index;
    return;
}
extern MMI_ID g_active_imesettings_group ;
extern MMI_ID g_active_imesettings_screen ;

 void mmi_imesettings_select_keyboard_lang_handler(void)
 {
		mmi_popup_property_struct callback_popup;
		mmi_imm_config_handwriting_language(g_pen_follow_keyboard_lang[Followkeybrd_highlighted_index]);
		mmi_imesettings_save_screen();
		mmi_popup_property_init(& callback_popup);
		callback_popup.parent_id = mmi_frm_group_get_active_id();
		callback_popup.callback = mmi_ime_settings_input_mode_screen_popup_handler_for_sg;
		mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &callback_popup);
 }
static void EntryKeyboardLanguageSettingScr_Ext(void);
 void EntryKeyboardLanguageSettingScr(MMI_ID parent_gid)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pGuiBuffer;
	//U16 temp_init ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //get total lang number	
   follow_keybrd_lang_count = mmi_imm_get_handwriting_language_strings(g_pen_follow_keyboard_lang) ;
	MMI_ASSERT(follow_keybrd_lang_count> 0);
   //get all lang strings
  /* for(temp_init = 0 ; temp_init < follow_keybrd_lang_count ; temp_init++)
   {
		g_pen_follow_keyboard_lang[temp_init] = (U8 *)mmi_imm_handwriting_get_language_string(temp_init);
   }*/

   //get highlighted index
   Followkeybrd_highlighted_index = 0 ;
   while(!(mmi_ucs2cmp((char*)g_pen_follow_keyboard_lang[Followkeybrd_highlighted_index], (char*)(mmi_imm_get_handwriting_language())) == 0))
   {
		Followkeybrd_highlighted_index++ ;
		if(Followkeybrd_highlighted_index == MAX_WRITING_LANG)
		{
			Followkeybrd_highlighted_index = 0 ;
			break ;
		}
   }
    //Followkeybrd_highlighted_index = mmi_imm_get_handwriting_language();

    mmi_frm_scrn_enter(parent_gid , SCR_INPUT_LANG_FOLLOW_KEYBRD, NULL, EntryKeyboardLanguageSettingScr_Ext, MMI_FRM_UNKNOW_SCRN);
    pGuiBuffer =  mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_ime_settings_highlight_current_keyboard_lang);
    
    ShowCategory36Screen(
        STR_ID_KEYBRD_LANG,
        NULL,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        follow_keybrd_lang_count,
        (U8 **) g_pen_follow_keyboard_lang,
        Followkeybrd_highlighted_index,
        pGuiBuffer);
  
    SetRightSoftkeyFunction(mmi_ime_settings_back, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imesettings_select_keyboard_lang_handler, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_imesettings_select_keyboard_lang_handler, KEY_EVENT_UP);
    register_center_softkey_to_enter_key();
    redraw_center_softkey();  
    return;
 }

 static void EntryKeyboardLanguageSettingScr_Ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_id = mmi_frm_group_get_active_id();
    EntryKeyboardLanguageSettingScr(g_id);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_commonscreen_update_hw_attributes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
 #ifdef __MMI_IME_V3__
	static void mmi_commonscreen_update_hw_attributes(S32 index);

void mmi_commonscreen_update_hw_attributes(S32 index)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 operation = CUI_INLINE_RESET_ATTRIBUTE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index)
    {
        operation = CUI_INLINE_SET_ATTRIBUTE;
    }
    else
    {
        operation = CUI_INLINE_RESET_ATTRIBUTE;
    }
    cui_inline_set_item_attributes(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT1,
        operation,
        CUI_INLINE_ITEM_DISABLE);


    cui_inline_set_item_attributes(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT2,
        operation,
        CUI_INLINE_ITEM_DISABLE);


    cui_inline_set_item_attributes(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_SELECT4,
        operation,
        CUI_INLINE_ITEM_DISABLE);


    cui_inline_set_item_attributes(
        g_hw_inlinecui_gid,
        PHNSET_HANDWRITING_COLORSELECT1,
        operation,
        CUI_INLINE_ITEM_DISABLE);
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_handwriting_proc
 * DESCRIPTION
 *  Proc function for handwriting inline cui 
 * PARAMETERS
 *  
 * RETURNS
 *  static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_phnset_handwriting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
	{
	case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(mmi_frm_group_get_active_id());
            return MMI_RET_OK;
    	}
    
    case EVT_ID_CUI_INLINE_SUBMIT:
#if defined(__MMI_IME_PLUTO_SLIM__)
        SaveHandwritingSetting();
#else
        EntryScrHandwritingSettingConfirm();
#endif
        return MMI_RET_OK;        
        
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)param;
            U8 pencolor;
            if (notify_event->event_type == CUI_INLINE_NOTIFY_COLOR_SELECT_FOCUS_CHANGED)
        	{
                cui_inline_get_value(
                    notify_event->sender_id,
                    PHNSET_HANDWRITING_COLORSELECT1,
                    (void*)&pencolor);
                if (pencolor != pen_color)
            	{
                cui_inline_set_screen_attributes(
                    mmi_frm_group_get_active_id(),
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_SCREEN_CHANGED);
                cui_inline_redraw_screen(mmi_frm_group_get_active_id());
        	}
        	}
#ifdef __MMI_IME_V3__
			else if(notify_event->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
			{
				S32 index = (S32)notify_event->param;
				if(notify_event->item_id == PHNSET_HANDWRITING_SELECT5)
				{
					mmi_commonscreen_update_hw_attributes(index);
                cui_inline_set_screen_attributes(
                    mmi_frm_group_get_active_id(),
                    CUI_INLINE_SET_ATTRIBUTE,
                    CUI_INLINE_SCREEN_CHANGED);
                cui_inline_redraw_screen(mmi_frm_group_get_active_id());
				}
			}
#endif
            break;
        }
    
    case EVT_ID_GROUP_DEINIT:
        if (param->user_data)
    	{
    	    OslMfree(param->user_data);
            param->user_data = NULL;
    	}
        return MMI_RET_OK;
#if !defined(__MMI_IME_PLUTO_SLIM__)       
    case EVT_ID_ALERT_QUIT:
	{
        mmi_alert_result_evt_struct *confirm_evt = (mmi_alert_result_evt_struct*)param;
        switch (confirm_evt->result)
    	{
    	case MMI_ALERT_CNFM_YES:
            SaveHandwritingSetting();
            break;
            
        case MMI_ALERT_CNFM_NO:    		
            mmi_frm_group_close(GRP_ID_PHNSET_HANDWRITING);
    		break;
            
    	default:
    		break;
    	}
        return MMI_RET_OK;	
	}
#endif//#if !defined(__MMI_IME_PLUTO_SLIM__)        
	default:
        break;		
	}
    return MMI_RET_OK;
}
 

/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHandwritingColor
 * DESCRIPTION
 *  Get handwriting stroke color
 * PARAMETERS
 *  void
 * RETURNS
 *  color
 *****************************************************************************/
color PhnsetGetHandwritingColor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//get the Pen color 
    ReadValue(NVRAM_PEN_COLOR, &(pen_color), DS_BYTE, &Err);
    if (pen_color == 0xFF || Err != NVRAM_READ_SUCCESS || pen_color >= MAX_PEN_COLORS)
    {
        pen_color = DEFAULT_PEN_COLOR;
    }
    MMI_ASSERT(pen_color < MAX_PEN_COLORS);
    return g_pen_color_list[pen_color];
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetHandwritingSpeed
 * DESCRIPTION
 *  Get handwriting speed
 * PARAMETERS
 *  void
 * RETURNS
 *  PHNSET_HANDWRITING_SPEED_ENUM
 *****************************************************************************/
PHNSET_HANDWRITING_SPEED_ENUM PhnsetGetHandwritingSpeed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch ((U8)mmi_imm_get_pen_speed())
    {
        case 0:
            return PHNSET_HANDWRITING_FAST;
        case 1:
            return PHNSET_HANDWRITING_MEDIUM;
        case 2:
            return PHNSET_HANDWRITING_SLOW;
        default:
            MMI_ASSERT(0);
            return PHNSET_HANDWRITING_MEDIUM;
    }
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__) */ 
