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
 *    pixcomfontengine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   font engine related function calls
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
// #include "MMI_include.h"
#include "gdi_mutex.h"
//#include <signal.h>
//#include "FontData.h"
#include "Conversions.h"

#if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_360X640__)
#include "MTKPropFont20.h"
#include "MTKPropFont.h"
#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter20.h"
#include "ZiV7ExtraCharacter14.h"
#endif /* defined(__MMI_ZI_V7__) */ 
#endif /* defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)) */ 

#else /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_360X640__) */ 
#error multiple proprietary font only support under 240x320, 240x400, 320x240, and 320x480
#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_360X640__) */ 

#else /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)

#include "MTKPropFont20.h"
#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))

#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter20.h"
#else 
#include "ZiExtraCharacter20.h"
#endif 

#endif /* defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)) */ 

#else /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */ 

#include "MTKPropFont.h"
#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter14.h"
#else 
#include "ZiExtraCharacter.h"
#endif 
#endif /* defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)) */ 

#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */ 
#endif /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 

#include "PixcomFontEngine.h"

/* For Langauge */
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif 

#include "LangModuleGProt.h"

#include "BIDIDEF.h"
#include "BIDIGProt.h"

//#include "ATHandlerProt.h"
//#include "SSCStringHandle.h"
#include "BIDIDEF.h"
#include "BIDIGProt.h"
#include "Gdi_font.h"
#include "med_utility.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "FontRes.h"
#include "MMI_features.h"
#include "gui_data_types.h"
#include "gdi_include.h"
#include "string.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_at_util_gprot.h"
#include "Unicodexdcl.h"
#include "gui.h"
#include "kal_public_api.h"
#include "SSCStringTable.h"

#include "kal_public_defs.h"
#include "GlobalResDef.h"
#include "limits.h"
#include "gdi_const.h"
#include "gdi_primitive.h"
#include "gui_resource_type.h"
#include "mmi_fw_trc.h"
#include "ArabicGProt.h"
#include "stack_config.h"

#include "drv_gfx_stack_switch_manager.h"
#include "font_engine_interface.h"
#include "dict.h"

#ifdef __MMI_BDF_SW_COMPRESSION__
#include "bfc_decode_api.h"
#endif

#if defined(__MMI_FONT_EFFECTS__)
#include "FontEffects.h"
#include "mmi_rp_app_font_effects_def.h"
#endif /* __MMI_FONT_EFFECTS__ */

#ifdef __MMI_SCRIPT_EASY__
#include "se_mtk.h"
#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
#include "GeneralSettingSrvGprot.h"
#include "LangErrorHandle.h"
#include "Sys_font_info.h"
#endif

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
#include "CustDataRes.h"
#include "CustFontDataHW.h"
#endif

#ifdef __MMI_FONT_GROUP_COMPRESSION__
#include "simple_memory_manager.h"
#undef _WIN32
#include "LzmaDec.h"
#endif

/*****************************************************************************
*  Define
*****************************************************************************/
//#define __FONT_ENGINE_SWLA__
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__FONT_ENGINE_SWLA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    #define FE_SWLA_START(_symbol_)
    #define FE_SWLA_STOP(_symbol_)
#endif

#define FONTENGINE_IRAM_PLACEMENT   0
#define BORDERED_TEXT_NO_BOUNDARY 1     /* MTK justin */

/* transparent color (blue) */
#define TRANSPARENT_COLOR_R 0
#define TRANSPARENT_COLOR_G 0
#define TRANSPARENT_COLOR_B 0xff
#define FE_DISPLAY_FLAG_DATE_CHAR  0x01
#define FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR  0x02
#define FE_DISPLAY_FLAG_UCS2_PROPRIETARY 0x04
#define FE_UCS2_PROPRIETARY_START 0xE000
#define FE_UCS2_PROPRIETARY_END 0xF8FF

#ifndef max
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#endif 
#ifndef min
#define min(a,b)        (((a) < (b)) ? (a) : (b))
#endif 

#define FE_DATA_OFFSET_BIT_SIZE     (8)

#define FE_HASH_CAL(old_value, data)   (((old_value)*1000003)^((U32)(data)))
#define FE_DIV_15(x) ((((x) + 8) * 4369) >> 16)
#define GET_HIGH_4BIT(x) (((x)>>4)&0x0f)
#define GET_LOW_4BIT(x) ((x)&0x0f)
#define SET_HIGH_4BIT(a, d) (*(a) = (*(a)&0x0f) | ((d)<<4))
#define SET_LOW_4BIT(a, d) (*(a) = (*(a)&0xf0) | (d))
#define MULTI_ALPHA_BLEND_4BIT(dst, src) ((dst)+(src)-FE_DIV_15((dst)*(src)))
#define FE_FIND_OFFSET(struct_type, field) (size_t)&(((struct_type*)0)->field)
//#define DATA_SHIFT(x1, y1, x2, y2, w) (((y2)-(y1))*(w)+((x2)-(x1)))
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
#define MMI_PRELOAD_FONT_PATH           ":\\@Font\\"
#define MMI_PRELOAD_FONT_DRIVER         SRV_FMGR_CARD_DRV
#endif
/*****************************************************************************
*  Typedef
*****************************************************************************/
typedef struct
{
    S32 x;
    S32 y;
    S32 char_gap;
    U8 *String;
    S32 len;
    U32 BaseLineHeight;
    U32 Bordered;
    MMI_BOOL enable_truncated;
    U8 *truncated_symbol;
    S32 truncated_symbol_start;
    S32 visible_x_start;
    S32 visible_x_end;
    S32 visible_x1_start;
    S32 visible_x1_end;
    S32 string_width;
    gdi_color border_color;
    gdi_color text_color;
    U32 render_flag;
    S32 max_ascent;
    S32 max_descent;
    U8 assign_direction;
    S32 clip_x1;
    S32 clip_x2;
    S32 clip_y1;
    S32 clip_y2;
    mmi_fe_text_format_struct_p format;
} mmi_fe_showstring_int_param_struct, *mmi_fe_showstring_int_param_struct_p;

typedef struct
{
    S32 x1;
    S32 x2;
    gdi_color c;
}mmi_fe_rech_text_format_underline_info_struct, *mmi_fe_rech_text_format_underline_info_struct_p;

typedef struct
{
    U32 gnCurrentFont; /* current font */
    U32 unicode;   /* char unicode */
}mmi_fe_bf_cache_key;

typedef struct
{
    U16 Width;     /* char width */
    U16 Height;    /* char height */
    U16 Ascent;    /* char ascent */
    U16 Descent;   /* char descent */
    U8 *CharData;  /* char raw data */
    U32 NumChar;   /* char data bytes */
    S32 index;     /* char index */
    U16 DWidth;    /* char DWidth */
    U8 count;      /* char count */
    U32 data[1];
} mmi_fe_bf_cache_info;

typedef struct
{
    dnode_t node_header;
    U8 data;
} mmi_fe_cache_tree_node_struct;

typedef struct mmi_fe_cache_tree_struct
{
    struct mmi_fe_cache_tree_struct *next;
    U32 ref_cnt;
    dict_t dict;
    U8 *memory_used;
    U8 *memory_end;
} mmi_fe_cache_tree_struct;

typedef struct
{
    U32 hash_value;
    U32 len:13;
    U32 lang:5;
    U32 script:5;
    U32 init:1;
    U32 font_attr:8;
    U16 font_size:8;
    U16 family_index:4;
    U16 cache_type:4;
} mmi_fe_cache_key_header_struct;

typedef struct
{
    mmi_fe_cache_key_header_struct header;
    UI_character_type string[MAX_SHOW_STRING_TEXT_LENGTH];
} mmi_fe_cache_key_struct;

typedef struct
{
    S32 adv_w;
    S32 adv_h;
    S32 maxAscent;
    S32 maxDescent;
    S32 baseline;
    S32 pWidth;
    S32 pHeight;
    S32 numofChar;
    S32 cluster_info_len;
    S32 cluster_string_len;
}mmi_fe_cache_string_info_header;

typedef struct
{
    /* display info */    
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 adjustment_x;
#endif
    kal_int16 w; 
    kal_int16 h; 
    kal_int8 adv_x; 
    kal_int8 adv_y;
    kal_int8 bx; 
    kal_int8 by; 
    kal_int8 rx;
    kal_int8 ry;
    
    /* relation flags */
    U32 is_gap :1;    /* to identify if there is gap between current and previous cluster. */
    U32 is_connect :1; /* to identify if current cluster could be put into next line by refering the previous cluster. */
    U32 data_len:4;         
    U32 cluster_len:4;  
    U32 lang_id:4; /* mmi_lm_lang_enum */
}mmi_fe_cache_cluster_info;

typedef struct
{
    mmi_fe_cache_string_info_header string_info_header;
    mmi_fe_cache_cluster_info cluster_info[MAX_SHOW_STRING_TEXT_LENGTH];
    UI_character_type cluster_string[MAX_SHOW_STRING_TEXT_LENGTH];
}mmi_fe_cache_string_info;

typedef struct
{
    U16 str_w;
    U16 str_h;
    U16 maxDescent;
    U16 baseline;
    U16 buf_size;
    U16 effect_buf_size;
    mmi_fe_render_data_struct buf[1];
} mmi_fe_cache_image_info, *mmi_fe_cache_image_info_p;

typedef struct
{
    S16 x_pos;
    S16 y_pos;
} mmi_fe_char_pos_struct;

typedef struct
{
    kal_int8 width;
    kal_int8 height;
    kal_int8 bearing_x;
    kal_int8 bearing_y;
    kal_int8 advance_x;
    U16 bitmap_size;
    U32 bitmap[1];
} mmi_fe_glyph_info, *mmi_fe_glyph_info_p;

typedef struct
{
    mmi_fe_glyph_ot_info posdata;
    mmi_fe_glyph_info glyph_data;
} mmi_fe_text_info, *mmi_fe_text_info_p;

typedef struct
{
    S32 glyph_len;
    mmi_fe_text_info glyph_list[1];
} mmi_fe_cache_node_data_struct;

#define MMI_FE_INIT_TIME_PERIOD KAL_TICKS_5_SEC

typedef enum
{
    MMI_FE_LANG_OTHERS,
    MMI_FE_LANG_INDIC,
    MMI_FE_LANG_THAI,
    MMI_FE_LANG_ARABIC,
    MMI_FE_LANG_NONE
} mmi_fe_lang_id;

typedef enum
{
    MMI_FE_INFO_ONLY,
    MMI_FE_GET_DATA,
    MMI_FE_VALID_CHECK,
    MMI_FE_GLYPH_INDEX
} mmi_fe_font_query_type;

typedef enum
{
    MMI_FE_CACHE_TYPE_CLUSTER_DATA,
    MMI_FE_CACHE_TYPE_STRING_INFO,
    MMI_FE_CACHE_TYPE_STRING_IMAGE,
    MMI_FE_CACHE_TYPE_MAX
}mmi_fe_chche_type;

typedef U32(*mmi_fe_show_string_func) (mmi_fe_showstring_int_param_struct_p param);
typedef U32(*mmi_fe_get_string_width_height_func) (mmi_fe_get_string_info_param_struct_p param);

/*****************************************************************************
*  Global Variables
*****************************************************************************/
U8 gnCurrentFontAttrib = FONTATTRIB_NORMAL;
U8 gbFontType = 0;
U8 gFontEffect = 0;
static U32 fe_display_flag = 0;
static gdi_mutex_struct g_mmi_fe_cache_mutex;
BOOL cancelWidth = 0;

static mmi_fe_color g_mmi_fe_text_color = {0, 0, 0, 100};
static mmi_fe_color g_mmi_fe_text_border_color = {0, 0, 0, 100};

#ifdef __MMI_FE_RICH_TEXT_SUPPORT__
static mmi_fe_rech_text_format_underline_info_struct underline_info[MAX_SHOW_STRING_TEXT_LENGTH] = {0};
#endif

static U32 mmi_fe_get_string_widthheight_int(
        mmi_fe_get_string_info_param_struct_p query,
        U8 *direction,
        fe_save_cluster_info_cb f_save_info,
        void *user_data,
        MMI_BOOL is_BIDI);

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define FE_LOCK gdi_mutex_lock(&g_mmi_fe_cache_mutex)
#define FE_UNLOCK gdi_mutex_unlock(&g_mmi_fe_cache_mutex)
#else /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
#define FE_LOCK
#define FE_UNLOCK
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

#if defined(__MMI_FONT_EFFECTS__)
static U8 mmi_fe_bits_revise_table[256];
static stAdvanceFontAttribute gAdvanceFontAttribute;
static stFontColor gFontEffectColorGroup;
static U8 g_mmi_fe_data_pool_1[MMI_FE_FONT_EFFECT_POOL_SIZE];
static U8 g_mmi_fe_data_pool_2[MMI_FE_FONT_EFFECT_POOL_SIZE];
static U8 g_mmi_fe_data_pool_3[MMI_FE_FONT_EFFECT_POOL_SIZE];
static U8* g_mmi_fe_data_pool_1_ext = NULL;
static U8* g_mmi_fe_data_pool_2_ext = NULL;
static U8* g_mmi_fe_data_pool_3_ext = NULL;
static U16 mmi_fe_font_effect_pool_size = 0;

static S32 degree_x[] = {1, 1, 0, -1, -1, 1, 1, 0, -1, -1};
static S32 degree_y[] = {0, -1, -1, -1, 0, 0, 1, 1, 1, 0};

static S32 gauss_fact1[3] = {11, 20, 11};
static S32 gauss_fact2[5] = {5, 11, 20, 11, 5};
static S32 gauss_fact3[7] = {5, 10, 15, 20, 15, 10, 5};
static S32 gauss_fact4[9] = {4, 8, 12, 17, 20, 17, 12, 8, 4};
static S32 gauss_fact5[11] = {5, 8, 10, 13, 17, 20, 17, 13, 10, 8, 5};
static U8 mmi_fe_effect_img_cache_count[FONT_EFFECT_MAX] = {0, 0, 1, 1, 1, 2, 1, 3, 3};

U8 gSubFontEffect = 0;
U8 gFontAttributeLastNode = 0;
U8 gFontAttributeLastStaticNode = 0;
U8 gFontAttributeTotalNode = 0;

#if defined(__MMI_MAINLCD_480X800__)  /* WVGA */
stFontAttributeNode gFontAttributeNode[MMI_FE_FONT_EFFECT_FINAL_MAX] = 
{
    /* Node 1: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_1,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_1,   /* Shadow Distant */
            SHADOW_RANGE_E1_1,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_1,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_1,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 2: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_2,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_2,   /* Shadow Distant */
            SHADOW_RANGE_E1_2,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_2,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_2,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 3: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_3,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_3,   /* Shadow Distant */
            SHADOW_RANGE_E1_3,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_3,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_3,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 4: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_4,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_4,   /* Shadow Distant */
            SHADOW_RANGE_E1_4,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_4,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_4,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 5: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_5,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_5,   /* Shadow Distant */
            SHADOW_RANGE_E1_5,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_5,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_5,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 6: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_6,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_6,   /* Shadow Distant */
            SHADOW_RANGE_E1_6,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_6,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_6,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 7: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_7,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_7,   /* Shadow Distant */
            SHADOW_RANGE_E1_7,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_7,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_7,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 8: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_8,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_8,   /* Shadow Distant */
            SHADOW_RANGE_E1_8,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_8,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_8,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 9: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_9,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_9,   /* Shadow Distant */
            SHADOW_RANGE_E1_9,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_9,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0, 0, 0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_9,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 10: outer glow */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            OUTERGLOW_RANGE_E2_1,     /* Outer Glow Range */
            OUTERGLOW_TRANSPARENCY_E2_1,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {0, 0,0,0},  /* Shadow Color */
            {255, 0,222,255},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E2_1,     /* Attribute ID */
        FONT_EFFECT_OUTER_GLOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 11: enhanced engraved */
    {
        {
            0,   /* Shadow Degree */
            ENGRAVED_DEGREE_E3_1,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            ENGRAVED_TRANSPARENCY_E3_1,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {255, 0, 0, 0},  /* Upper Engraved Color */
            {255, 255, 255, 255},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E3_1,     /* Attribute ID */
        FONT_EFFECT_ENHANCED_ENGRAVE,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 12: gradient */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            GRADIENT_DIRECTION_E4_1,   /* Gradient Direction */
            GRADIENT_TRANSPARENCY_E4_1,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            0    /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {255, 79, 76, 66},  /* First Gradient Color */
            {255, 153, 149, 136},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E4_1,     /* Attribute ID */
        FONT_EFFECT_GRADIENT,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },
    
    /* Node 13: border */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            BORDER_SIZE_E5_1,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            BORDER_TRANSPARENCY_E5_1    /* Border Transparency */
        },
        {
            {255, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E5_1,     /* Attribute ID */
        FONT_EFFECT_BORDER,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    }
};
#elif defined(__MMI_MAINLCD_320X480__)   /* HVGA */
stFontAttributeNode gFontAttributeNode[MMI_FE_FONT_EFFECT_FINAL_MAX] = 
{
    /* Node 1: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_1,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_1,   /* Shadow Distant */
            SHADOW_RANGE_E1_1,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_1,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_1,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 2: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_2,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_2,   /* Shadow Distant */
            SHADOW_RANGE_E1_2,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_2,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_2,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 3: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_3,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_3,   /* Shadow Distant */
            SHADOW_RANGE_E1_3,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_3,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_3,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 4: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_4,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_4,   /* Shadow Distant */
            SHADOW_RANGE_E1_4,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_4,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_4,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 5: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_5,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_5,   /* Shadow Distant */
            SHADOW_RANGE_E1_5,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_5,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_5,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 6: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_6,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_6,   /* Shadow Distant */
            SHADOW_RANGE_E1_6,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_6,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_6,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 7: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_7,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_7,   /* Shadow Distant */
            SHADOW_RANGE_E1_7,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_7,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_7,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 8: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_8,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_8,   /* Shadow Distant */
            SHADOW_RANGE_E1_8,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_8,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_8,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 9: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_9,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_9,   /* Shadow Distant */
            SHADOW_RANGE_E1_9,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_9,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0, 0, 0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_9,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 10: outer glow */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            OUTERGLOW_RANGE_E2_1,     /* Outer Glow Range */
            OUTERGLOW_TRANSPARENCY_E2_1,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {0, 0,0,0},  /* Shadow Color */
            {255, 0,222,255},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E2_1,     /* Attribute ID */
        FONT_EFFECT_OUTER_GLOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 11: enhanced engraved */
    {
        {
            0,   /* Shadow Degree */
            ENGRAVED_DEGREE_E3_1,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            ENGRAVED_TRANSPARENCY_E3_1,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {255, 0, 0, 0},  /* Upper Engraved Color */
            {255, 255, 255, 255},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E3_1,     /* Attribute ID */
        FONT_EFFECT_ENHANCED_ENGRAVE,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 12: gradient */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            GRADIENT_DIRECTION_E4_1,   /* Gradient Direction */
            GRADIENT_TRANSPARENCY_E4_1,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            0    /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {255, 79, 76, 66},  /* First Gradient Color */
            {255, 153, 149, 136},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E4_1,     /* Attribute ID */
        FONT_EFFECT_GRADIENT,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },
    
    /* Node 13: border */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            BORDER_SIZE_E5_1,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            BORDER_TRANSPARENCY_E5_1    /* Border Transparency */
        },
        {
            {255, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E5_1,     /* Attribute ID */
        FONT_EFFECT_BORDER,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    }
};
#else /* Default */
stFontAttributeNode gFontAttributeNode[MMI_FE_FONT_EFFECT_FINAL_MAX] = 
{
    /* Node 1: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_1,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_1,   /* Shadow Distant */
            SHADOW_RANGE_E1_1,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_1,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_1,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 2: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_2,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_2,   /* Shadow Distant */
            SHADOW_RANGE_E1_2,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_2,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_2,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 3: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_3,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_3,   /* Shadow Distant */
            SHADOW_RANGE_E1_3,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_3,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_3,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 4: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_4,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_4,   /* Shadow Distant */
            SHADOW_RANGE_E1_4,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_4,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_4,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 5: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_5,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_5,   /* Shadow Distant */
            SHADOW_RANGE_E1_5,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_5,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_5,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 6: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_6,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_6,   /* Shadow Distant */
            SHADOW_RANGE_E1_6,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_6,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_6,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 7: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_7,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_7,   /* Shadow Distant */
            SHADOW_RANGE_E1_7,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_7,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0,0,0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_7,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 8: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_8,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_8,   /* Shadow Distant */
            SHADOW_RANGE_E1_8,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_8,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 255, 255, 255},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_8,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 9: drop shadow */
    {
        {
            SHADOW_DEGREE_E1_9,   /* Shadow Degree */
            0,                                         /* Engraved Degree */
            SHADOW_DISTANT_E1_9,   /* Shadow Distant */
            SHADOW_RANGE_E1_9,      /* Shadow Range */
            SHADOW_TRANSPARENCY_E1_9,   /* Shadow Transparency */
            0,     /* Border Size */                                                  
            0,     /* Gradient Direction */
            0,     /* Gradient Transparency */
            0,     /* Outer Glow Range */
            0,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {255, 0, 0, 0},     /* Shadow Color */
            {0, 0,0,0},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E1_9,     /* Attribute ID */
        FONT_EFFECT_DROP_SHADOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 10: outer glow */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            OUTERGLOW_RANGE_E2_1,     /* Outer Glow Range */
            OUTERGLOW_TRANSPARENCY_E2_1,     /* Outer Glow Transparency */
            0,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0,0,0},  /* Border Color */
            {0, 0,0,0},  /* First Gradient Color */
            {0, 0,0,0},  /* Second Gradient Color */
            {0, 0,0,0},  /* Shadow Color */
            {255, 0,222,255},  /* Outer Glow Color */
            {0, 0,0,0},  /* Upper Engraved Color */
            {0, 0,0,0},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E2_1,     /* Attribute ID */
        FONT_EFFECT_OUTER_GLOW,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 11: enhanced engraved */
    {
        {
            0,   /* Shadow Degree */
            ENGRAVED_DEGREE_E3_1,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            ENGRAVED_TRANSPARENCY_E3_1,     /* Engraved Transparency */
            0      /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {255, 0, 0, 0},  /* Upper Engraved Color */
            {255, 255, 255, 255},  /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E3_1,     /* Attribute ID */
        FONT_EFFECT_ENHANCED_ENGRAVE,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },

    /* Node 12: gradient */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            0,   /* Border Size */                                                  
            GRADIENT_DIRECTION_E4_1,   /* Gradient Direction */
            GRADIENT_TRANSPARENCY_E4_1,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            0    /* Border Transparency */
        },
        {
            {0, 0, 0, 0},  /* Border Color */
            {255, 79, 76, 66},  /* First Gradient Color */
            {255, 153, 149, 136},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E4_1,     /* Attribute ID */
        FONT_EFFECT_GRADIENT,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    },
    
    /* Node 13: border */
    {
        {
            0,   /* Shadow Degree */
            0,   /* Engraved Degree */
            0,   /* Shadow Distant */
            0,   /* Shadow Range */
            0,   /* Shadow Transparency */
            BORDER_SIZE_E5_1,   /* Border Size */                                                  
            0,   /* Gradient Direction */
            0,   /* Gradient Transparency */
            0,   /* Outer Glow Range */
            0,   /* Outer Glow Transparency */
            0,   /* Engraved Transparency */
            BORDER_TRANSPARENCY_E5_1    /* Border Transparency */
        },
        {
            {255, 0, 0, 0},  /* Border Color */
            {0, 0, 0, 0},  /* First Gradient Color */
            {0, 0, 0, 0},  /* Second Gradient Color */
            {0, 0, 0, 0},  /* Shadow Color */
            {0, 0, 0, 0},  /* Outer Glow Color */
            {0, 0, 0, 0},  /* Upper Engraved Color */
            {0, 0, 0, 0}   /* Lower Engraved Color */
        },
        MMI_FE_FONT_EFFECT_E5_1,     /* Attribute ID */
        FONT_EFFECT_BORDER,  /* Effect Type */
        0,     /* Node Type, 0: static node, 1: dynamic node */
        NULL        /* Next Node Pointer */
    }
};

#endif

#endif /* __MMI_FONT_EFFECTS__ */

/* extern sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */
extern sLanguageDetails *gLanguageArray;
extern font_group_struct *gfontfamily;

extern BOOL r2lMMIFlag;

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
extern ENFB_Font_Res_Info ENFBFontResInfo[];
#endif

#ifdef __MMI_BIDI_ALG__
extern U8 MMI_bidi_input_type;
U16 show_pwcWord[MAX_SHOW_STRING_TEXT_LENGTH];
U8 show_visual_str[MAX_SHOW_STRING_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
U16 fe_v2l_map[MAX_SHOW_STRING_TEXT_LENGTH];    /* the map from the bidi text to the original text */
U16 fe_l2v_map[MAX_SHOW_STRING_TEXT_LENGTH];    /* the map from the original text to the bidi text */

#endif /* __MMI_BIDI_ALG__ */ 
#ifdef __MMI_ARSHAPING_ENGINE__
static U16 fe_ShaToOrg[MAX_SHOW_STRING_TEXT_LENGTH];
#endif 

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
extern MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered);
extern MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered);
#endif /* __MMI_SUPPORT_DUMP_SCREEN_STRING__ */ 

/* For Font Cache */
CharHashTable charHashTableLatin[LATIN_CHAR_HT_SIZE];
CharHashTable charHashTableOthers[OTHERS_CHAR_HT_SIZE];

extern const sCustFontData gMTKProprietaryFont_small;
extern const sCustFontData gMTKProprietaryFont_medium;
const RangeData *pAMTKProprietaryFont_RangeData;

#ifdef __MMI_FONT_GROUP_COMPRESSION__
#define FONT_LZMA_DECOMP_BUFF_SIZE (16*1024)
kal_uint32 font_lzma_decomp_buff_pool[FONT_LZMA_DECOMP_BUFF_SIZE>>2];
static STSMM _font_lzma_decompress_smm;
U8 gFontGroupCompressionBuf[10240];
#endif

#ifndef __MMI_BDF_SW_COMPRESSION__
static const U32 font_tilt_table[61] = 
{
    0, 0, 0, 0, 0, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 5, 5, 5, 5, 5, 6, 6, 6,
    6, 7, 7, 7, 7, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13
};
#endif

U32 gnCurrentFont;
const sCustFontData *gpCurrentFont = NULL;
extern U16 gMaxDeployedLangs;
extern U16 gCurrLangIndex;

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || defined(__MMI_FONT_GROUP_COMPRESSION__)

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define MMI_FE_CACHE_TREE_BASE_SIZE (100)
#elif defined(__MMI_FONT_GROUP_COMPRESSION__)
#define MMI_FE_CACHE_TREE_BASE_SIZE (50)
#endif

#ifndef __FONT_ENGINE_SLIM__
#define MMI_FE_CACHE_TREE_SIZE      MMI_FE_CACHE_TREE_BASE_SIZE*2*1024  /* default font engine cache size */
#endif

#define MMI_FE_CACHE_TREE_PAGE_SIZE MMI_FE_CACHE_TREE_BASE_SIZE*1024    /* memory from media task, will be free if need */

#ifndef __FONT_ENGINE_SLIM__
#if MMI_FE_CACHE_TREE_SIZE < MMI_FE_CACHE_TREE_PAGE_SIZE
#error "font engine pool size too small"
#endif 
#endif

#ifndef __FONT_ENGINE_SLIM__
#define MAX_CACHE_PAGE_FROM_MED 4
#else
#define MAX_CACHE_PAGE_FROM_MED 6
#endif

#ifndef __FONT_ENGINE_SLIM__
#if defined (__MTK_TARGET__) && defined (GDI_AA_FONT_SUPPORT)

#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
static U32 MMI_FE_CACHE_TREE_DEFAULT_POOL[MMI_FE_CACHE_TREE_SIZE / 4];
#pragma arm section zidata, rwdata  

#else
static U32 MMI_FE_CACHE_TREE_DEFAULT_POOL[MMI_FE_CACHE_TREE_SIZE / 4];
#endif
#endif

static U8 gCachePageCountFromMed = 0;

#ifndef __FONT_ENGINE_SLIM__
static U32 mmi_fe_cache_tree_default_pool_used;
#endif

static mmi_fe_cache_tree_struct *mmi_fe_cache_tree;

#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
static UI_character_type file_path_ucs2[256];
mmi_preload_font_struct g_mmi_preload_font[FE_MAX_FONT_FILE_NUMBER];
static U16 g_mmi_fe_font_file_list_ext[FE_MAX_FONT_FILE_NUMBER];
MMI_BOOL mmi_fe_preload_font_init = MMI_FALSE;
#endif
extern U8 gLanguageMappingArray[];
/*****************************************************************************
*  Global Function
*****************************************************************************/
static U32 mmi_fe_show_string_int(mmi_fe_showstring_int_param_struct_p param);
#ifndef __MMI_SCRIPT_EASY__
#if defined(__MMI_LANG_THAI__)
static S32 mmi_fe_show_thai_char_internal(
            S32 CurrentX,
            S32 CurrentY,
            U16 pre2Ch,
            U16 preCh,
            U16 curCh,
            mmi_fe_showstring_int_param_struct_p param);
#endif /* defined(__MMI_LANG_THAI__) */ 
#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_int_param_struct_p param);
static U32 mmi_fe_get_string_widthheight_indic_internal(mmi_fe_get_string_info_param_struct_p param);
#endif /* defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
#endif /* __MMI_SCRIPT_EASY__ */
//static S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, S32 *LineHeight);
static mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8 *st, U8 *dic, S32 len);
static void GetLangIndex(U8 *pCount, S32 *pnFontIndex, S32 *pnIndex, U32 nCh, U32 *pnBase);
static S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase);
#ifdef __MMI_VECTOR_FONT_KERNING__
static mmi_fe_lang_id mmi_fe_get_lang_id(U32 ch);
#endif
#ifndef __MMI_SCRIPT_EASY__
static void SetFontValues(U32 nFont, U8 arrCount);
#endif /* __MMI_SCRIPT_EASY__ */
static MMI_BOOL mmi_fe_test_display_as_space(U32 ch);
static MMI_BOOL mmi_fe_test_display_as_null(U32 ch);
static U32 Get_CharWidthHeight_internal(
            U32 Ch,
            S32 *pdWidth,
            S32 *pWidth,
            S32 *pHeight,
            S32 *pAscent,
            S32 *pDescent);

#ifndef __MMI_SCRIPT_EASY__

#if defined(__MMI_VECTOR_FONT_KERNING__)
__inline static U32 mmi_fe_get_font_data(
                        U8 type,
                        U16 ch,
                        U8 **ppCharData,
                        U32 *data_attr,
                        S32 *pnWidth,
                        S32 *advance_x,
                        U16 *glyph_width,
                        U16 *glyph_height,
                        S32 *bearing_x,
                        S32 *ascent,
                        S32 *descent,
                            S32 *lsb_delta, 
                            S32 *rsb_delta,
                        MMI_BOOL *valid);
#else
__inline static U32 mmi_fe_get_font_data(
                        U8 type,
                        U16 ch,
                        U8 **ppCharData,
                        U32 *data_attr,
                        S32 *pnWidth,
                        S32 *advance_x,
                        U16 *glyph_width,
                        U16 *glyph_height,
                        S32 *bearing_x,
                        S32 *ascent,
                        S32 *descent,
                        MMI_BOOL *valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
#endif /* __MMI_SCRIPT_EASY__ */
#if defined(__MMI_FONT_EFFECTS__)
void mmi_fe_effect_data_pool_free_notify_callback(void *ptr);

static void mmi_fe_free_effect_data_pool(void);

static MMI_BOOL mmi_fe_alloc_effect_data_pool(U32 size);

static void mmi_fe_create_effect_img_data(
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8 *effect_buf_ptr,
                            U32 effect_buf_size);

static void mmi_fe_show_font_effect_data_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size);

static void mmi_fe_show_font_data_gradient(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static void mmi_fe_show_font_data_drop_shadow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static void mmi_fe_show_font_data_outer_glow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static void mmi_fe_show_font_data_border(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static void mmi_fe_show_font_data_engrave(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static void mmi_fe_show_font_data_gradient_drop_shadow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);
static void mmi_fe_show_font_data_gradient_engrave(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height);

static S32 mmi_fe_data_convert_8bpp(U8* dest, U8* src, S32 width, S32 height, S32 size, MMI_BOOL antialias);
static S32 mmi_fe_data_convert_4bpp(U8* dest, U8* src, S32 width, S32 height, S32 size, MMI_BOOL antialias);
static S32 mmi_fe_data_frame(U8* dest, U8* src, U16* width, U16* height, U16 frame_width);
static void setFontEffectAttribute(void);
static stFontAttributeNode* searchFontEffectAttribute(void);

//static void  mmi_fe_rgb_to_hls(mmi_fe_color color, U8* H, U8* L, U8* S);
#if 0
/* under construction !*/
#endif
//static void mmi_fe_hls_to_rgb(U8 hue, U8 lum, U8 sat, U8* R, U8* G, U8* B);
#endif /* defined(__MMI_FONT_EFFECTS__) */ 

#if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
static S32 mmi_fe_get_block_index(mmi_font_range_offset_struct *rangeOffset, S32 index);
#endif 
#ifdef __MMI_FONT_GROUP_COMPRESSION__
static void mmi_fe_get_group_info(const GroupDetails* groupDetails, U32 offset, U32* encode_size, U32* encode_offset, U32* decode_size, U32* decode_offset);
#endif

#if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)
//static S32 mmi_fe_search_in_prop_font(U32 ch, U32 *pnBase, sFontFamily *font_family, sCustFontData **font_data);
#else /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 
static S32 SearchInPropFont(U32 nCh, U32 *pnBase);

#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
static S32 SearchInZiExtraFont(U32 nCh, U32 *pnBase);
#endif 
#endif /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 

MMI_BOOL mmi_fe_get_language_by_font_data(const sCustFontData *font_data, const U8 *lan_ssc);
U32 mmi_fe_show_string_baseline_ext(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction, mmi_fe_text_format_struct_p format);
U32 mmi_fe_show_string_bordered_baseline_ext(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction, mmi_fe_text_format_struct_p format);
/*****************************************************************************
*  External Function
*****************************************************************************/
#ifdef __MTK_TARGET__
extern kal_uint32 INT_SwitchStackToRun(
                    void *stack_start,
                    kal_uint32 stack_size,
                    kal_func_ptr func,
                    kal_uint32 argc,
                    ...);
extern void kal_check_stack(void);
#endif /* __MTK_TARGET__ */ 

/**************************************************************/

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || defined(__MMI_FONT_GROUP_COMPRESSION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_cmp_fun
 * DESCRIPTION
 *  Compare function for tree node
 * PARAMETERS
 *  a       [IN]        
 *  b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int mmi_fe_cache_tree_cmp_fun(const void *a, const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_cache_key_struct *key_a = (mmi_fe_cache_key_struct*) a;
    mmi_fe_cache_key_struct *key_b = (mmi_fe_cache_key_struct*) b;
#elif defined(__MMI_FONT_GROUP_COMPRESSION__)
    mmi_fe_bf_cache_key *key_a = (mmi_fe_bf_cache_key*) a;
    mmi_fe_bf_cache_key *key_b = (mmi_fe_bf_cache_key*) b;
#endif
    int comp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    comp = key_a->header.len - key_b->header.len;
    if (comp)
        return comp;

    comp = memcmp(
            key_a,
            key_b,
            sizeof(mmi_fe_cache_key_header_struct) + sizeof(UI_character_type) * key_a->header.len);
#elif defined(__MMI_FONT_GROUP_COMPRESSION__)
    comp = memcmp(key_a, key_b, sizeof(mmi_fe_bf_cache_key));
#endif
    return comp;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_free_notify_callback
 * DESCRIPTION
 *  To allocate node for tree
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_cache_tree_free_notify_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __FONT_ENGINE_SLIM__
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree->next;
#else
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;
#endif
    mmi_fe_cache_tree_struct *parent = mmi_fe_cache_tree;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_LOCK;

    for (; tree != NULL; parent = tree, tree = tree->next)
    {
        if ((void*)tree == ptr) /* remove this node from cache_tree_list */
        {
        #ifndef __FONT_ENGINE_SLIM__
            parent->next = tree->next;
            if((ptr < &MMI_FE_CACHE_TREE_DEFAULT_POOL[0]) || (ptr > &MMI_FE_CACHE_TREE_DEFAULT_POOL[MMI_FE_CACHE_TREE_SIZE/4]))
                gCachePageCountFromMed--;
        #else
            if(tree == mmi_fe_cache_tree)
            {
                mmi_fe_cache_tree = mmi_fe_cache_tree->next;
            }
            else
            {
                parent->next = tree->next;
            }

            gCachePageCountFromMed--;
        #endif
            MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_CACHE_FREE, gCachePageCountFromMed);
            FE_UNLOCK;
            return;
        }
    }
    MMI_ASSERT(0);  /* memory leak !! didn't find this memory pointer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_init
 * DESCRIPTION
 *  To allocate node for tree
 * PARAMETERS
 *  tree        [?]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_cache_tree_init(mmi_fe_cache_tree_struct *tree, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size &= ~0x3;

    dict_init(&tree->dict, DICTCOUNT_T_MAX, mmi_fe_cache_tree_cmp_fun);
    tree->ref_cnt = 0;
    tree->next = NULL;
    tree->memory_used = ((U8*) tree) + ((sizeof(mmi_fe_cache_tree_struct) + 3) & (~3));
    tree->memory_end = ((U8*) tree) + size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_alloc_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tree        [?]         
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_fe_cache_tree_node_struct *mmi_fe_cache_tree_alloc_node(mmi_fe_cache_tree_struct *tree, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_node_struct *node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = size & (~3); /* mmi_fe_cache_tree_node_struct already contain 4 bytes bitmap space */
    if (tree->memory_used + size <= tree->memory_end)
    {
        node = (mmi_fe_cache_tree_node_struct*) tree->memory_used;
        tree->memory_used += size;
    }
    return node;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_allocate_page
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_fe_cache_tree_allocate_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = NULL;
    int size = MMI_FE_CACHE_TREE_PAGE_SIZE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __FONT_ENGINE_SLIM__
    /* allocate from static default pool */
    if (mmi_fe_cache_tree_default_pool_used < MMI_FE_CACHE_TREE_SIZE)
    {
        if (mmi_fe_cache_tree_default_pool_used + MMI_FE_CACHE_TREE_PAGE_SIZE < MMI_FE_CACHE_TREE_SIZE)
            size = MMI_FE_CACHE_TREE_PAGE_SIZE;
        else
            size = MMI_FE_CACHE_TREE_SIZE - mmi_fe_cache_tree_default_pool_used;

        /* remain space should large then header + 1 font data cache(128x128x8 bits ) */
        if (size > (sizeof(mmi_fe_cache_tree_struct) + sizeof(mmi_fe_cache_tree_node_struct) + 128 * 128))
        {
            tree =
                (mmi_fe_cache_tree_struct*) (((char*)MMI_FE_CACHE_TREE_DEFAULT_POOL) +
                                              mmi_fe_cache_tree_default_pool_used);
            mmi_fe_cache_tree_default_pool_used += size;
        }
    }
#endif

    /* allocate from media un-used memory, and will be freed if need. */
    if ((tree == NULL)&&(gCachePageCountFromMed < MAX_CACHE_PAGE_FROM_MED))
    {
        size = MMI_FE_CACHE_TREE_PAGE_SIZE;
#if defined(GDI_AA_FONT_SUPPORT)
        tree = (mmi_fe_cache_tree_struct *)med_alloc_temp_ext_mem_noncacheable(size,mmi_fe_cache_tree_free_notify_callback);
#else
        tree = (mmi_fe_cache_tree_struct*) med_alloc_temp_ext_mem(size, mmi_fe_cache_tree_free_notify_callback);
#endif
        if(tree)
            gCachePageCountFromMed++;
        else
            MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_CACHE_ALLOC_FAIL, gCachePageCountFromMed);
    }

    /* try to overdue a cache page */
    if (tree == NULL)
    {
        mmi_fe_cache_tree_struct *T;

#ifndef __FONT_ENGINE_SLIM__
        tree = T = mmi_fe_cache_tree->next;
#else
        tree = T = mmi_fe_cache_tree;
#endif

        for (; T != NULL; T = T->next)
        {
            if (T->ref_cnt < tree->ref_cnt)
                tree = T;
        }

        if (tree)   /* release this node from tree list */
        {
            mmi_fe_cache_tree_free_notify_callback((void*)tree);

#ifndef __FONT_ENGINE_SLIM__
            if(((U32 *)tree < &MMI_FE_CACHE_TREE_DEFAULT_POOL[0]) || ((U32 *)tree > &MMI_FE_CACHE_TREE_DEFAULT_POOL[MMI_FE_CACHE_TREE_SIZE/4]))
#endif
            gCachePageCountFromMed++;

            MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_CACHE_REPLACE, gCachePageCountFromMed);
        }

    }

    if (tree)
    {
        /* attach this tree into cache_tree_list */
        mmi_fe_cache_tree_init(tree, size);
    }
    return tree;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_init
 * DESCRIPTION
 *  To reset vector font cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __FONT_ENGINE_SLIM__
    memset(MMI_FE_CACHE_TREE_DEFAULT_POOL, 0, sizeof(MMI_FE_CACHE_TREE_DEFAULT_POOL));

    mmi_fe_cache_tree = (mmi_fe_cache_tree_struct*) MMI_FE_CACHE_TREE_DEFAULT_POOL;
    mmi_fe_cache_tree_init(mmi_fe_cache_tree, MMI_FE_CACHE_TREE_PAGE_SIZE);
    mmi_fe_cache_tree_default_pool_used = MMI_FE_CACHE_TREE_PAGE_SIZE;
    gCachePageCountFromMed = 0;
#else
    mmi_fe_cache_tree = NULL;
    gCachePageCountFromMed = 0;
#endif
}

#ifdef __MMI_FONT_GROUP_COMPRESSION__
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_bf_cache_tree_find
 * DESCRIPTION
 *  To find font cache
 * PARAMETERS
 *  key             [?]     
 *  data_ptr        [?]     
 *  len             [?]     
 * RETURNS
 *  
 *****************************************************************************/
__inline static BOOL mmi_fe_bf_cache_tree_find(mmi_fe_bf_cache_key *key, mmi_fe_bf_cache_info **data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; tree != NULL; tree = tree->next)
    {
        mmi_fe_cache_tree_node_struct *node = NULL;

        node = (mmi_fe_cache_tree_node_struct*) dict_lookup(&tree->dict, (const void*)key);
        if (node)
        {
            *data_ptr = (mmi_fe_bf_cache_info*) (&node->data + sizeof(mmi_fe_bf_cache_key));
            tree->ref_cnt++;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_save_string_info
 * DESCRIPTION
 *  To save the string info into cache tree
 * PARAMETERS
 *  key                     [?]         
 *  glyph_len               [IN]        
 *  glyph_list              [IN]        
 *  cluster_data_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_bf_cache_tree_save_info(
                        mmi_fe_bf_cache_key *key,
                        mmi_fe_bf_cache_info *info,
                        U32 info_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree;
    mmi_fe_cache_tree_node_struct *node;
    mmi_fe_bf_cache_info *info_data;
    S32 keysize = sizeof(mmi_fe_bf_cache_key);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        tree = mmi_fe_cache_tree;
        node = NULL;
        for (; tree != NULL; tree = tree->next)
        {
            node = mmi_fe_cache_tree_alloc_node(tree, sizeof(mmi_fe_cache_tree_node_struct) + keysize + info_size + info->NumChar);
            if (node)
            {
                memset(node, 0, sizeof(mmi_fe_cache_tree_node_struct) + keysize + info_size + info->NumChar);
                if (key)
                    memcpy(&node->data, key, keysize);
                if (info)
                {
                    info_data = (mmi_fe_bf_cache_info *)(&node->data + keysize);
                    memcpy(info_data, info, info_size);
                    memcpy(info_data->data, info->CharData, info->NumChar);
                    info_data->CharData = (U8 *)info_data->data;
                }

                dnode_init(&node->node_header, node);
                dict_insert(&tree->dict, (dnode_t*) node, (const void*)&node->data);
                return;
            }
        }
        /* not enough memory for current tree list, try to allocate new tree */

        tree = mmi_fe_cache_tree_allocate_page();

        if (tree == NULL)   /* media task didn't have any memory free ! */
            break;

        /* attach this tree into cache_tree_list */
#ifndef __FONT_ENGINE_SLIM__
        tree->next = mmi_fe_cache_tree->next;
        mmi_fe_cache_tree->next = tree;
#else
        tree->next = mmi_fe_cache_tree;
        mmi_fe_cache_tree = tree;
#endif
    }
    while (1);
}
#endif  //#ifdef __MMI_FONT_GROUP_COMPRESSION__

#endif  //#if defined(__MMI_VECTOR_FONT_SUPPORT__) || defined(__MMI_FONT_GROUP_COMPRESSION__)

#ifdef __MMI_VECTOR_FONT_SUPPORT__

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
#include "FontManagerGProt.h" 
#endif 

#define FE_FOUR_BYTE_ALIGN(a) ((((a)+3) >> 2) << 2)

static U32 font_engine_font_attr = 0;
static U8 font_engine_font_size = 0;
static U32 font_engine_font_pixel = 0;
static MMI_BOOL font_engine_antialias = MMI_TRUE;
extern const fe_table_struct *font_engine;

static U32 font_engine_error_code = MMI_FE_FONT_ERR_NONE;


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  font_list       [?]         
 *  font_number     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL dummy_fe_init(U16 *font_list, U8 font_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_set_font_attr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_set_font_attr(U32 attr)
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
 *  dummy_fe_set_font_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_set_font_size(U32 size, U32 attr)
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
 *  dummy_fe_set_font_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_color          [IN]        
 *  border_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_set_font_color(gdi_color text_color, gdi_color border_color)
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
 *  dummy_fe_get_font_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_need_glyph_data      [IN]        
 *  ucs2                    [IN]        
 *  glyph_data              [IN]        
 *  glyph_size              [?]         
 *  glyph_attr              [?]         
 *  glyph_width             [?]         
 *  glyph_height            [?]         
 *  bearing_x               [?]         
 *  bearing_y               [?]         
 *  advance_x               [?]         
 *  advance_y               [?]         
 *  valid                   [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL dummy_fe_get_font_data(
            U8 is_need_glyph_data,
            /* need generate glyph or only need character information */ U16 ucs2,
            U8 **glyph_data,
            U32 *glyph_size,
            /* bytes number of glyph_data */ U32 *glyph_attr,
            /* glyph attribute , used for font engine itself */ U16 *glyph_width,
            U16 *glyph_height,
            S32 *bearing_x,
            S32 *bearing_y,
            /* the offset from origin for glyph */ S32 *advance_x,
            S32 *advance_y,
            /* the offset for next character origin */ MMI_BOOL *valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_set_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL dummy_fe_set_font(U16 resid)
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
 *  dummy_fe_set_antialias
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_set_antialias(MMI_BOOL value)
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
 *  dummy_fe_show_font_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2                [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_attr          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 *  border              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_show_font_data(
        U16 ucs2,
        S32 x,
        S32 y,
        U8 *glyph_ptr,
        U32 glyph_size,
        U32 glyph_attr,
        U16 glyph_width,
        U16 glyph_height,
        U32 border)
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
 *  dummy_fe_get_width_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2        [IN]        
 *  width       [?]         
 *  height      [?]         
 *  ascent      [?]         
 *  descent     [?]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL dummy_fe_get_width_height(U16 ucs2, S32 *width, S32 *height, S32 *ascent, S32 *descent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_get_font_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  font_size       [IN]        
 *  height          [?]         
 *  ascent          [?]         
 *  descent         [?]         
 *  with_attr       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
MMI_BOOL dummy_fe_get_font_info(U16 resid, U32 font_size, S32 *height, S32 *ascent, S32 *descent, MMI_BOOL with_attr)
#else
MMI_BOOL dummy_fe_get_font_info(U32 font_size, S32 *height, S32 *ascent, S32 *descent, MMI_BOOL with_attr)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_shaper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lang            [IN]        
 *  script          [IN]        
 *  text            [IN]        
 *  text_len        [IN]        
 *  start_index     [IN]        
 *  run_len         [IN]        
 *  cluster         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void dummy_fe_shaper(
        U32 lang,
        U32 script,
        UI_string_type text,
        S32 text_len,
        S32 start_index,
        S32 run_len,
        mmi_fe_cluster_info_p cluster)
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
 *  dummy_fe_check_font
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_fe_error_code dummy_fe_check_font(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FE_FONT_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  dummy_fe_get_font_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resid           [IN]        
 *  buffer          [?]         
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_fe_error_code dummy_fe_get_font_name(U16 resid, U8 *buffer, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FE_FONT_ERR_NONE;
}

const fe_table_struct dummy_font_engine = 
{
    MMI_FE_ENGINE_VERSION_09B_FEATURE_SET,
    dummy_fe_init,
    dummy_fe_set_font_attr,
    dummy_fe_set_font_size,
    dummy_fe_set_font_color,
    dummy_fe_get_font_data,
    dummy_fe_show_font_data,
    dummy_fe_get_font_info,
    dummy_fe_set_antialias,
    dummy_fe_set_font,
    dummy_fe_shaper,
    dummy_fe_check_font,
    dummy_fe_get_font_name,
};

const U32 g_mmi_fe_script_table[] = 
{
    MMI_FE_OT_SCRIPT_BENGALI,
    MMI_FE_OT_SCRIPT_DEVANAGARI,
    MMI_FE_OT_SCRIPT_GUJARATI,
    MMI_FE_OT_SCRIPT_GURMUKHI,
    MMI_FE_OT_SCRIPT_KANNADA,
    MMI_FE_OT_SCRIPT_MALAYALAM,
    MMI_FE_OT_SCRIPT_ORIYA,
    MMI_FE_OT_SCRIPT_SINHALA,
    MMI_FE_OT_SCRIPT_TAMIL,
    MMI_FE_OT_SCRIPT_TELUEU,
    MMI_FE_OT_SCRIPT_THAI,
    MMI_FE_OT_SCRIPT_MYANMAR,
    MMI_FE_OT_SCRIPT_LAO,
    /* the end value. all other new script flag should be added before this one. */
    MMI_FE_OT_DEFAULT
};

const U32 g_mmi_fe_lang_table[] = 
{
    MMI_FE_OT_LANG_ASSAMESE,
    MMI_FE_OT_LANG_BENGALI,
    MMI_FE_OT_LANG_GUJARATI,
    MMI_FE_OT_LANG_HINDI,
    MMI_FE_OT_LANG_KANNADA,
    MMI_FE_OT_LANG_MALAYALAM,
    MMI_FE_OT_LANG_MARATHI,
    MMI_FE_OT_LANG_ORIYA,
    MMI_FE_OT_LANG_PUNJABI,
    MMI_FE_OT_LANG_TAMIL,
    MMI_FE_OT_LANG_TELUGU,
    MMI_FE_OT_LANG_THAI,
    MMI_FE_OT_LANG_MYANMAR,
    MMI_FE_OT_LANG_LAO,
    /* the end value. all other new lang flag should be added before this one. */
    MMI_FE_OT_DEFAULT
};


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_font_engine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_font_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(charHashTableLatin, 0, sizeof(charHashTableLatin));
    memset(charHashTableOthers, 0, sizeof(charHashTableOthers));

    font_engine = &dummy_font_engine;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_font_engine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_font_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    font_engine = &font_engine_table;
}
const fe_table_struct *font_engine = &dummy_font_engine;


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_antialias
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_antialias(MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    font_engine_antialias = value;
    if (value)
    {
        font_engine_font_attr |= FE_FONT_ATTR_ANTIALIAS;
    }
    else
    {
        font_engine_font_attr &= (~FE_FONT_ATTR_ANTIALIAS);
    }
    font_engine->set_antialias(value);
    GDI_UNLOCK;
}

#ifndef __MMI_SCRIPT_EASY__
#define MMI_FE_CACHE_KEY(UCS2,FONT_SIZE,FONT_ATTR)  (((U32)UCS2) | (((U32)FONT_SIZE)<<16) | (((U32)FONT_ATTR)<<24) )
#define MMI_FE_STACK_SIZE                            8192

#if defined(__MTK_TARGET__)
static U32 g_mmi_fe_stack[MMI_FE_STACK_SIZE / 4];
#endif 

static U8 g_mmi_fe_font_file_number[FE_MAX_FONT_FAMILY_NUMBER];
static U16 g_mmi_fe_font_file_list[FE_MAX_FONT_FAMILY_NUMBER][FE_MAX_FONT_FILE_NUMBER];

/* to record proprietary font temporially. 
   We would put the priprietary in the end of the font list. 
   We asume only one proprietary font for each family now. */
static U16 g_mmi_fe_private_font_file_list[FE_MAX_FONT_FAMILY_NUMBER];
static U16 *g_mmi_fe_curr_font_list;
static U8 g_mmi_fe_font_family = 0;
static S16 g_mmi_fe_curr_available_font_family = 0;
//static U32 g_mmi_fe_curr_font_file = 0;  /* Useless Now. Add by Yang Cui. */
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
static MMI_BOOL g_mmi_fe_init_check = MMI_FALSE;
static U32 g_mmi_fe_init_timer = 0;
#endif
static mmi_fe_cache_key_struct mmi_fe_key;
static mmi_fe_cache_string_info cache_string_info;

#ifdef __FONT_ENGINE_SLIM__
#define MMI_FE_CLUSTER_POOL_SIZE 64*64/2
#else
#define MMI_FE_CLUSTER_POOL_SIZE 128*128/2
#endif

#if 0//defined (__MTK_TARGET__) && defined (GDI_AA_FONT_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
static U32 g_mmi_fe_cluster_data_pool[MMI_FE_CLUSTER_POOL_SIZE];
#endif

#if defined(__MMI_LANG_THAI__)
static MMI_BOOL mmi_fe_is_thai_character(U16 curCh);
#endif 

static mmi_fe_cache_image_info_p mmi_fe_img_cache_ptr = NULL;
static BOOL mmi_fe_img_cache_mode = MMI_FALSE;

extern S32 mmi_fe_check_font_header(U16 resid, U8 *flag);
extern void mmi_fe_vectorfont_engine_error_handler(mmi_fe_error_code err);
extern void mmi_fe_vectorfont_engine_error(mmi_fe_error_code err);

/* Private family index should be seperated with Normal family index, for support multiple family. Add by Yang Cui. */
static U16 g_mmi_fe_private_font_family = 0; 

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
void mmi_fe_set_char_pos(
        mmi_fe_glyph_ot_info_p pos_info,
        mmi_fe_glyph_info_p glyph_info,
        mmi_fe_char_pos_struct *pos,
        mmi_fe_char_pos_struct *currpos);
#endif

#endif /* __MMI_SCRIPT_EASY__ */

#ifndef __MMI_SCRIPT_EASY__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_preload_font_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_preload_font_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U8 i, j = 0, count, folder_len;
    U8 langSSC[10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_lang_error_bootup_exception_reg_hdlr();
    count = sizeof(system_font)/sizeof(system_font[0]);
    
    kal_wsprintf(file_path_ucs2, "%c%s", MMI_PRELOAD_FONT_DRIVER, MMI_PRELOAD_FONT_PATH);
    folder_len = mmi_ucs2strlen((char *)file_path_ucs2);

    file_handle = FS_Open(file_path_ucs2, FS_OPEN_DIR | FS_READ_ONLY);
        
    /* Folder Exists */
    if (file_handle > 0)
    {
        S32 folderAttribute = FS_GetAttributes(file_path_ucs2);
        if (!(folderAttribute & FS_ATTR_DIR) || !(folderAttribute & FS_ATTR_HIDDEN))
        {
            FS_SetAttributes(file_path_ucs2, FS_ATTR_DIR | FS_ATTR_HIDDEN);	
        }

        FS_Close(file_handle);
    }
    
    for(i=0;i<count;i++)
    {
        if(system_font[i].res_id > IMG_GLOBAL_FONT_MAX)
        {
            kal_wsprintf(&file_path_ucs2[folder_len], "%s", system_font[i].name);
            file_handle = FS_Open(file_path_ucs2, FS_READ_ONLY);
            if (file_handle < 0)    /* failed to open existing file, or file not exists */
            {
                srv_setting_get_initial_language(langSSC);
                if((mmi_lang_support(langSSC) == -1) && strcmp(langSSC, "*#0044#"))
                    srv_setting_set_initial_language("*#0044#");
                return MMI_FALSE;
            }
            else
            {
                g_mmi_preload_font[j].handle = file_handle;
                g_mmi_preload_font[j].res_id = system_font[i].res_id;
                j++;
            }
        }
    }

    memset(gLanguageMappingArray, 1, sizeof(U8)*gMaxDeployedLangs);
    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_multiple_file_init
 * DESCRIPTION
 *  To initialize multitple file cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_multiple_file_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    U16 j = 0, count;
#endif
    S32 family = 0;
    U8 flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_fe_private_font_file_list, 0, sizeof(U16) * FE_MAX_FONT_FAMILY_NUMBER);
    g_mmi_fe_font_file_number[0] = 0;
    g_mmi_fe_font_file_number[1] = 0;
    g_mmi_fe_font_file_number[2] = 0;

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    if(mmi_fe_preload_font_init)
    {
        count = sizeof(system_font)/sizeof(system_font[0]);
        for(i=0; i<count; i++)
        {
            if((system_font[i].res_id >= IMG_GLOBAL_FONT_1) && (system_font[i].res_id <= IMG_GLOBAL_FONT_MAX))
            {
                family = mmi_fe_check_font_header(system_font[i].res_id, &flag);
                if (family != -1 && family <= FE_MAX_FONT_FAMILY_NUMBER)        /* all vector font type should be checked */
                {
                    if (flag)
                    {
                        g_mmi_fe_private_font_file_list[family] = system_font[i].res_id;
                    }
                    else
                    {
                        if (g_mmi_fe_font_file_number[family] + 1 <= FE_MAX_FONT_FILE_NUMBER)
                        {
                            g_mmi_fe_font_file_list[family][g_mmi_fe_font_file_number[family]++] = system_font[i].res_id;
                        }
                    }
                }
            }
            else
            {
                if (j < POP_FONT_FILES_EXT)
                {
                    g_mmi_fe_font_file_list_ext[j++] = system_font[i].res_id;
                }
            }
        }
        /* copy the private font in the end */
        for (i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
        {
            if (g_mmi_fe_private_font_file_list[i] != 0)
            {
                g_mmi_fe_font_file_list[i][g_mmi_fe_font_file_number[i]++] = g_mmi_fe_private_font_file_list[i];
            }
        }

        for (j = 0; j < POP_FONT_FILES_EXT; j++)
        {
            g_mmi_fe_font_file_list[0][g_mmi_fe_font_file_number[0]++] = g_mmi_fe_font_file_list_ext[j];
        }
        g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[g_mmi_fe_font_family];
        return;
    }
#endif

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    for (i = 0; i < POP_FONT_FILES; i++)
    {
        g_mmi_fe_font_file_list[0][g_mmi_fe_font_file_number[0]++] = ENFBFontResInfo[i].res_id;
    }
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[g_mmi_fe_font_family];
    return;
#endif
    for (i = IMG_GLOBAL_FONT_1; i <= IMG_GLOBAL_FONT_MAX; i++)
    {
        family = mmi_fe_check_font_header(i, &flag);
        if (family != -1 && family <= FE_MAX_FONT_FAMILY_NUMBER)        /* all vector font type should be checked */
        {
            if (flag)
            {
                g_mmi_fe_private_font_file_list[family] = i;
            }
            else
            {
                if (g_mmi_fe_font_file_number[family] + 1 <= FE_MAX_FONT_FILE_NUMBER)
                {
                    g_mmi_fe_font_file_list[family][g_mmi_fe_font_file_number[family]++] = i;
                }
            }
        }
    }

    /* copy the private font in the end */
    for (i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
    {
        if (g_mmi_fe_private_font_file_list[i] != 0)
        {
            g_mmi_fe_font_file_list[i][g_mmi_fe_font_file_number[i]++] = g_mmi_fe_private_font_file_list[i];
        }
    }
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[g_mmi_fe_font_family];
    //g_mmi_fe_curr_font_file = 0;

}
#endif /* #ifndef __MMI_SCRIPT_EASY__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_size_to_pixel
 * DESCRIPTION
 *  Convert the size to pixel
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_fe_size_to_pixel(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pixels;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((size & 0x80) == 0)
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
        switch ((size & 0x0F))
        {
            case SMALL_FONT:
                pixels = 14;
                break;
            case MEDIUM_FONT:
                pixels = 20;
                break;
            case LARGE_FONT:
                pixels = 22;
                break;
            case SUBLCD_FONT:
                pixels = 9;
                break;
            case DIALER_FONT:
                pixels = 27;
                break;
            case VIRTUAL_KEYBOARD_FONT:
                pixels = 12;
                break;
            default:
                pixels = 20;
                break;
        }
    #elif defined(__MMI_MAINLCD_320X480__)
        switch ((size & 0x0F))
        {
            case SMALL_FONT:
                pixels = 14;
                break;
            case MEDIUM_FONT:
                pixels = 20;
                break;
            case LARGE_FONT:
                pixels = 24;
                break;
            case SUBLCD_FONT:
                pixels = 9;
                break;
            case DIALER_FONT:
                pixels = 48;
                break;
            case VIRTUAL_KEYBOARD_FONT:
                pixels = 20;
                break;
            case VIRTUAL_KEYBOARD_LARGE_FONT:
                pixels = 30;
                break;
            case NUMBER_1_FONT:
                pixels = 12;
                break;
            case NUMBER_2_FONT:
                pixels = 16;
                break;
            default:
                pixels = 20;
                break;
        }
        
    #elif defined(__MMI_MAINLCD_480X800__)
        switch ((size & 0x0F))
        {
            case SMALL_FONT:
                pixels = 21;
                break;
            case MEDIUM_FONT:
                pixels = 30;
                break;
            case LARGE_FONT:
                pixels = 36;
                break;
            case SUBLCD_FONT:
                pixels = 9;
                break;
            case DIALER_FONT:
                pixels = 48;
                break;
            case VIRTUAL_KEYBOARD_FONT:
                pixels = 20;
                break;
            case VIRTUAL_KEYBOARD_LARGE_FONT:
                pixels = 30;
                break;
            case NUMBER_1_FONT:
                pixels = 12;
                break;
            case NUMBER_2_FONT:
                pixels = 16;
                break;
            default:
                pixels = 20;
                break;
        }
    #else 
        switch ((size & 0x0F))
        {
            case SMALL_FONT:
                pixels = 9;
                break;
            case MEDIUM_FONT:
                pixels = 14;
                break;
            case LARGE_FONT:
                pixels = 16;
                break;
            case SUBLCD_FONT:
                pixels = 9;
                break;
            case DIALER_FONT:
                pixels = 27;
                break;
            case VIRTUAL_KEYBOARD_FONT:
                pixels = 12;
                break;
            default:
                pixels = 20;
                break;
        }

    #endif 
    }
    else
    {
        pixels = size & 0x7f;
#ifdef __FONT_ENGINE_SLIM__
        if(pixels > 64)
            pixels = 64;
#endif
    }
    return pixels;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_font
 * DESCRIPTION
 *  to set font size and attribute
 * PARAMETERS
 *  size        [IN]        
 *  attr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_font(U8 size, U32 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (font_engine_font_size == 0 || font_engine_font_size != size || font_engine_font_attr != attr)
    {
        font_engine_font_attr = attr;
        font_engine_font_size = size;
        font_engine_font_pixel = mmi_fe_size_to_pixel(size);

        if (gFontEffect == FONT_EFFECT_ENGRAVE)
        {
            font_engine_font_attr |= FE_FONT_ATTR_ENGRAVE;
        }
        else
        {
            font_engine_font_attr &= (~FE_FONT_ATTR_ENGRAVE);
        }

        if (font_engine_antialias)
        {
            font_engine_font_attr |= FE_FONT_ATTR_ANTIALIAS;
        }
        else
        {
            font_engine_font_attr &= (~FE_FONT_ATTR_ANTIALIAS);
        }

    #if defined(__MTK_TARGET__) && !defined(__MMI_SCRIPT_EASY__)
        INT_SwitchStackToRun(
            g_mmi_fe_stack,
            MMI_FE_STACK_SIZE,
            (kal_func_ptr) font_engine->set_font_size,
            2,
            font_engine_font_pixel,
            font_engine_font_attr);
    #else /* defined(__MTK_TARGET__) */ 
        font_engine->set_font_size(font_engine_font_pixel, font_engine_font_attr);
    #endif /* defined(__MTK_TARGET__) */ 

    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 

    }
}

#ifndef __MMI_SCRIPT_EASY__
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_glyph_image_mem_merge
 * DESCRIPTION
 *  to font glyph image mem merge by 4bit multi alpha blending
 * PARAMETERS
 *  p_dst_data        [IN]           
 *  p_src_data        [IN]
 *  x       [IN]
 *  y       [IN]
 *  glyph_w       [IN]
 *  glyph_h        [IN]
 *  str_w       [IN]
 *  str_h       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_glyph_image_mem_merge(U8* p_dst_data, U8* p_src_data, U16 x, U16 y, U8 glyph_w, U8 glyph_h, U16 str_w, U16 str_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, src_data, dst_data;
    U8 *dst_ptr, *src_ptr;
    U32 src_data_shift, dst_data_shift;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p_src_data!=NULL && p_dst_data!=NULL && glyph_h<=str_h);
    FE_SWLA_START("GIM");
    j = 0;
    while(j < glyph_h)
    {
        i = 0;
        while(i < glyph_w)
        {
            src_data_shift = j * glyph_w + i;
            src_ptr = p_src_data + (src_data_shift>>1);
            dst_data_shift = (y + j) * str_w + (x + i);
            dst_ptr = p_dst_data + (dst_data_shift>>1);

            if(src_data_shift & 0x1)
                src_data = GET_HIGH_4BIT(*src_ptr);
            else
                src_data = GET_LOW_4BIT(*src_ptr);

            if(src_data != 0)
            {
                if(src_data == 15)
                {
                    if(dst_data_shift & 0x1)
                        SET_HIGH_4BIT(dst_ptr, src_data);
                    else
                        SET_LOW_4BIT(dst_ptr, src_data);
                }
                else
                {
                    if(dst_data_shift & 0x1)
                        dst_data = GET_HIGH_4BIT(*dst_ptr);
                    else
                        dst_data = GET_LOW_4BIT(*dst_ptr);

                    if(dst_data != 15)
                    {
                        if(dst_data == 0)
                        {
                            if(dst_data_shift & 0x1)
                                SET_HIGH_4BIT(dst_ptr, src_data);
                            else
                                SET_LOW_4BIT(dst_ptr, src_data);
                        }
                        else
                        {
                            if(dst_data_shift & 0x1)
                                SET_HIGH_4BIT(dst_ptr, MULTI_ALPHA_BLEND_4BIT(dst_data, src_data));
                            else
                                SET_LOW_4BIT(dst_ptr, MULTI_ALPHA_BLEND_4BIT(dst_data, src_data));
                        }
                    }
                }
            }

            i++;
        }
        j++;
    }
    FE_SWLA_STOP("GIM");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_img_cache_mode
 * DESCRIPTION
 *  to enable string image cache mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_enable_img_cache_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_img_cache_mode = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_img_cache_mode
 * DESCRIPTION
 *  to disable string image cache mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_disable_img_cache_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_img_cache_mode = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_img_cache_mode
 * DESCRIPTION
 *  to get string image cache mode
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
__inline static BOOL mmi_fe_get_img_cache_mode()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_fe_img_cache_mode;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_key_maker
 * DESCRIPTION
 *  To create key
 * PARAMETERS
 *  text        [IN]        
 *  len         [IN]        
 *  lang        [IN]        
 *  attr        [IN]        
 *  size        [IN]        
 *  script      [IN]        
 *  init        [IN]        
 *  key         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_key_maker(
                        UI_string_type text,
                        S32 len,
                        FE_OT_FLAG lang,
                        U32 attr,
                        U8 size,
                        FE_OT_FLAG script,
                        MMI_BOOL init,
                        U8 family_index,
                        mmi_fe_chche_type cache_type,
                        U32 bidi_param,
                        U32 truncated_param,
                        U8 font_effect_id,
                        mmi_fe_text_format_struct_p textformat,
                        mmi_fe_cache_key_struct *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 script_index = 0, lang_index = 0;
    U32 hash_value = FE_HASH_CAL(FE_HASH_CAL(FE_HASH_CAL(FE_HASH_CAL(FE_HASH_CAL(cache_type, attr),size),family_index),lang),script);
    mmi_fe_text_format_struct_p pRechTextFormat = textformat;
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("KMK");
    ASSERT(key);

    if (len > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH)
    {
        len = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
    }

    if(bidi_param)
        hash_value = FE_HASH_CAL(hash_value, bidi_param);

    if(truncated_param)
        hash_value = FE_HASH_CAL(hash_value, truncated_param);

    if(font_effect_id)
        hash_value = FE_HASH_CAL(hash_value, font_effect_id);

    while(pRechTextFormat)
    {
        hash_value = FE_HASH_CAL(FE_HASH_CAL(hash_value, pRechTextFormat->start), pRechTextFormat->end);
        pRechTextFormat = pRechTextFormat->next;
    }

    //memset(key, 0, sizeof(mmi_fe_cache_key_struct));

    script_index = sizeof(g_mmi_fe_script_table)/sizeof(g_mmi_fe_script_table[0]) - 1;
    lang_index = sizeof(g_mmi_fe_lang_table)/sizeof(g_mmi_fe_lang_table[0]) - 1;

    while (g_mmi_fe_script_table[script_index] != script)
    {
        //script_index++;
        script_index--;
    }
    while (g_mmi_fe_lang_table[lang_index] != lang)
    {
        //lang_index++;
        lang_index--;
    }

    key->header.len = (U16) len;
    key->header.font_attr = (U8) attr;
    key->header.font_size = size;
    key->header.lang = lang_index;
    key->header.script = script_index;
    key->header.init = (init == 0 ? 1 : 0);
    key->header.family_index = family_index;
    key->header.cache_type = cache_type;
    memcpy(&key->string, text, len * sizeof(UI_character_type));
    for(i=0;i<len/2;i++)
    {
        hash_value = FE_HASH_CAL(hash_value, ((U32 *)(key->string))[i]);
    }
    key->header.hash_value = hash_value;
    FE_SWLA_STOP("KMK");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_find
 * DESCRIPTION
 *  To find font cache
 * PARAMETERS
 *  key             [?]     
 *  data_ptr        [?]     
 *  len             [?]     
 * RETURNS
 *  
 *****************************************************************************/
__inline static BOOL mmi_fe_cache_tree_find(mmi_fe_cache_key_struct *key, void **data_ptr, S32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("CFD");
    for (; tree != NULL; tree = tree->next)
    {
        mmi_fe_cache_tree_node_struct *node = NULL;
        mmi_fe_cache_node_data_struct *data = NULL;

        node = (mmi_fe_cache_tree_node_struct*) dict_lookup(&tree->dict, (const void*)key);
        if (node)
        {
            if(key->header.cache_type == MMI_FE_CACHE_TYPE_CLUSTER_DATA)
            {
            data =
                (mmi_fe_cache_node_data_struct*) (&node->data + sizeof(mmi_fe_cache_key_header_struct) +
                                                   FE_FOUR_BYTE_ALIGN(key->header.len << 1));
            *data_ptr = (mmi_fe_text_info_p) & data->glyph_list;
            *len = data->glyph_len;
            tree->ref_cnt++;
            }
            else if(key->header.cache_type == MMI_FE_CACHE_TYPE_STRING_INFO)
            {
                *data_ptr =
                    (mmi_fe_cache_string_info*) (&node->data + sizeof(mmi_fe_cache_key_header_struct) +
                                                   FE_FOUR_BYTE_ALIGN(key->header.len << 1));
                tree->ref_cnt++;
            }
            else if(key->header.cache_type == MMI_FE_CACHE_TYPE_STRING_IMAGE)
            {
                *data_ptr =
                    (mmi_fe_cache_image_info*) (&node->data + sizeof(mmi_fe_cache_key_header_struct) +
                                                   FE_FOUR_BYTE_ALIGN(key->header.len << 1));
                tree->ref_cnt++;
            }
            else
                ASSERT(0);

            FE_SWLA_STOP("CFD");
            return MMI_TRUE;
        }
    }
    FE_SWLA_STOP("CFD");
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_save_string_info
 * DESCRIPTION
 *  To save the string info into cache tree
 * PARAMETERS
 *  key                     [?]         
 *  glyph_len               [IN]        
 *  glyph_list              [IN]        
 *  cluster_data_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_tree_save_string_info(
                        mmi_fe_cache_key_struct *key,
                        mmi_fe_cache_string_info *string_info,
                        U32 string_info_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree;
    mmi_fe_cache_tree_node_struct *node;
    S32 keysize = sizeof(mmi_fe_cache_key_header_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("SSI");
    if (key)
    {
        keysize += (FE_FOUR_BYTE_ALIGN(key->header.len << 1));
    }

    do
    {
        tree = mmi_fe_cache_tree;
        node = NULL;
        for (; tree != NULL; tree = tree->next)
        {
            node = mmi_fe_cache_tree_alloc_node(tree, sizeof(mmi_fe_cache_tree_node_struct) + keysize + string_info_size);
            if (node)
            {
                memset(node, 0, sizeof(mmi_fe_cache_tree_node_struct) + keysize + string_info_size);
                if (key)
                    memcpy(&node->data, key, keysize);
                if (string_info)
                {
                    memcpy(&node->data + keysize, string_info, sizeof(string_info->string_info_header));
                    memcpy(&node->data + keysize + sizeof(string_info->string_info_header), string_info->cluster_info, string_info->string_info_header.cluster_info_len*sizeof(mmi_fe_cache_cluster_info));
                    memcpy(&node->data + keysize + sizeof(string_info->string_info_header) + string_info->string_info_header.cluster_info_len*sizeof(mmi_fe_cache_cluster_info), string_info->cluster_string, string_info->string_info_header.cluster_string_len*sizeof(UI_character_type));
                }

                dnode_init(&node->node_header, node);
                dict_insert(&tree->dict, (dnode_t*) node, (const void*)&node->data);
                FE_SWLA_STOP("SSI");
                return;
            }
        }
        /* not enough memory for current tree list, try to allocate new tree */

        tree = mmi_fe_cache_tree_allocate_page();

        if (tree == NULL)   /* media task didn't have any memory free ! */
            break;

        /* attach this tree into cache_tree_list */
#ifndef __FONT_ENGINE_SLIM__
        tree->next = mmi_fe_cache_tree->next;
        mmi_fe_cache_tree->next = tree;
#else
        tree->next = mmi_fe_cache_tree;
        mmi_fe_cache_tree = tree;
#endif
    }
    while (1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_save_cluster_data
 * DESCRIPTION
 *  To save the font data into cache tree
 * PARAMETERS
 *  key                     [?]         
 *  glyph_len               [IN]        
 *  glyph_list              [IN]        
 *  cluster_data_size       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_tree_save_cluster_data(
                        mmi_fe_cache_key_struct *key,
                        S32 glyph_len,
                        mmi_fe_text_info_p glyph_list,
                        U32 cluster_data_size,
                        mmi_fe_text_info_p *nc_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree;
    mmi_fe_cache_tree_node_struct *node;
    mmi_fe_cache_node_data_struct *data;
    S32 keysize = sizeof(mmi_fe_cache_key_header_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("SCD");
    if (key)
    {
        keysize += (FE_FOUR_BYTE_ALIGN(key->header.len << 1));
    }

    do
    {
        tree = mmi_fe_cache_tree;
        node = NULL;
        *nc_text_info = NULL;
        for (; tree != NULL; tree = tree->next)
        {
            node = mmi_fe_cache_tree_alloc_node(tree, sizeof(mmi_fe_cache_tree_node_struct) + keysize + cluster_data_size);
            if (node)
            {
                memset(node, 0, sizeof(mmi_fe_cache_tree_node_struct) + keysize + cluster_data_size);

                data = (mmi_fe_cache_node_data_struct*) (&node->data + keysize);
                if (key)
                    memcpy(&node->data, key, keysize);
                if (glyph_list)
                    memcpy(&data->glyph_list[0], glyph_list, cluster_data_size);
                data->glyph_len = glyph_len;

                *nc_text_info = data->glyph_list;

                dnode_init(&node->node_header, node);
                dict_insert(&tree->dict, (dnode_t*) node, (const void*)&node->data);

                FE_SWLA_STOP("SCD");
                return;
            }
        }
        /* not enough memory for current tree list, try to allocate new tree */

        tree = mmi_fe_cache_tree_allocate_page();

        if (tree == NULL)   /* media task didn't have any memory free ! */
            break;

        /* attach this tree into cache_tree_list */
#ifndef __FONT_ENGINE_SLIM__
        tree->next = mmi_fe_cache_tree->next;
        mmi_fe_cache_tree->next = tree;
#else
        tree->next = mmi_fe_cache_tree;
        mmi_fe_cache_tree = tree;
#endif

    }
    while (1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_alloc_string_image_cache_node
 * DESCRIPTION
 *  To alloc the string image cache node from cache tree
 * PARAMETERS
 *  key                         [IN]         
 *  image_info_size     [IN]        
 *  node                        [OUT]        
 *  image_info              [OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_tree_alloc_string_image_cache_node(
                        mmi_fe_cache_key_struct *key,
                        U32 image_info_size,
                        mmi_fe_cache_tree_node_struct **node,
                        mmi_fe_cache_image_info **image_info,
                        mmi_fe_cache_tree_struct **tree_node
                        )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree;
    S32 keysize = sizeof(mmi_fe_cache_key_header_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("AIC");
    if (key)
    {
        keysize += (FE_FOUR_BYTE_ALIGN(key->header.len << 1));
    }

    do
    {
        tree = mmi_fe_cache_tree;
        *node = NULL;
        *image_info = NULL;
        *tree_node = NULL;
        for (; tree != NULL; tree = tree->next)
        {
            *node = mmi_fe_cache_tree_alloc_node(tree, sizeof(mmi_fe_cache_tree_node_struct) + keysize + image_info_size);
            if (*node)
            {
                memset(*node, 0, sizeof(mmi_fe_cache_tree_node_struct) + keysize + image_info_size);
                if (key)
                    memcpy(&(*node)->data, key, keysize);
                *image_info = (mmi_fe_cache_image_info *)(&(*node)->data + keysize);
                *tree_node = tree;

                FE_SWLA_STOP("AIC");
                return;
            }
        }
        /* not enough memory for current tree list, try to allocate new tree */

        tree = mmi_fe_cache_tree_allocate_page();

        if (tree == NULL)   /* media task didn't have any memory free ! */
            break;

        /* attach this tree into cache_tree_list */
#ifndef __FONT_ENGINE_SLIM__
        tree->next = mmi_fe_cache_tree->next;
        mmi_fe_cache_tree->next = tree;
#else
        tree->next = mmi_fe_cache_tree;
        mmi_fe_cache_tree = tree;
#endif
    }
    while (1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_save_string_image
 * DESCRIPTION
 *  To save the string image into cache tree
 * PARAMETERS
 *  tree                     [IN]         
 *  node               [IN]              
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_cache_tree_save_string_image(
                        mmi_fe_cache_tree_struct *tree,
                        mmi_fe_cache_tree_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("SIC");
    if (node && tree)
    {
        dnode_init(&node->node_header, node);
        dict_insert(&tree->dict, (dnode_t*) node, (const void*)&node->data);
    }
    FE_SWLA_STOP("SIC");
    return;
}

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_restart
 * DESCRIPTION
 *  To add font resource in file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_cache_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __FONT_ENGINE_SLIM__
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree->next;
    //mmi_fe_cache_tree_struct *parent = mmi_fe_cache_tree;
    U32 start_addr = (U32) & MMI_FE_CACHE_TREE_DEFAULT_POOL;
    U32 end_addr = start_addr + sizeof(MMI_FE_CACHE_TREE_DEFAULT_POOL);
#else
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __FONT_ENGINE_SLIM__
    /* to find the one which is allocated from media task */
    while ((U32) tree >= start_addr && (U32) tree < end_addr)
    {
        tree = tree->next;
    }

    /* free the cache from media task */
    while (tree)
    {
        mmi_fe_cache_tree_struct *next = tree->next;

        if (!((U32) tree >= start_addr && (U32) tree < end_addr))
        {
            med_free_temp_ext_mem((void **)&tree);
        }

        tree = next;
    }
#else
    while (tree)
    {
        mmi_fe_cache_tree_struct *next = tree->next;

        med_free_temp_ext_mem((void **)&tree);

        tree = next;
    }
#endif
    mmi_fe_cache_init();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_vectorfont_engine_restart
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_vectorfont_engine_restart(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    U16 freetype_font_res_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER] = {0};
    U8 freetype_font_number = 0;
    int i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    /* reset cache */
    mmi_fe_cache_restart();
    mmi_fe_multiple_file_init();
    g_mmi_fe_font_family = 0;
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[0];
    //g_mmi_fe_curr_font_file = 0xFFFFFFFF;

    /* restart vector font engine without switch stack because stack might be used. */
    for(i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
    {
        for(j = 0; j < g_mmi_fe_font_file_number[i]; j++)
        {
            freetype_font_res_list[freetype_font_number] = g_mmi_fe_font_file_list[i][j];
            freetype_font_number++;
        }
    }

    ret = font_engine->init(freetype_font_res_list, freetype_font_number);
    MMI_ASSERT(ret);

    FE_UNLOCK;
    GDI_UNLOCK;

}
#endif
extern U8 *GetFontResource(U16 ResId, S32 *size);   /* this enfb_handle is the offset of font data in ENFB */
extern S8 *GetImageRaw(U16 ImageId);
extern U8 *GetFontRaw(U16 FontId);


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_font_header
 * DESCRIPTION
 *  To get font family and flag
 * PARAMETERS
 *  resid       [IN]        
 *  flag        [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_fe_check_font_header(U16 resid, U8 *flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *flag = 0;
    res = (U8*) GetFontRaw(resid);
    if (!res)
        return -1;

    if (res[0] == IMAGE_TYPE_TTF)
    {
        *flag = res[3];
        return res[1];
    }
    return -1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_family
 * DESCRIPTION
 *  To change font family (reserved.)
 * PARAMETERS
 *  family_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_family(S32 family_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_fe_font_file_number[family_index] != 0)
    {
        g_mmi_fe_font_family = family_index;
    
        g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[g_mmi_fe_font_family];
    }
    
    //mmi_fe_multiple_file_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_vector_change_active
 * DESCRIPTION
 *  To change active font for vector font engine.
 * PARAMETERS
 *  res_id      [IN]        The resource id for the font
 *  index       [IN]        The index in font array
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_vector_change_active(U16 res_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_mmi_fe_curr_font_file = index;
#if defined(__MTK_TARGET__)
    INT_SwitchStackToRun(g_mmi_fe_stack, MMI_FE_STACK_SIZE, (kal_func_ptr) font_engine->set_font, 1, res_id);
#else 
    font_engine->set_font(res_id);
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_name
 * DESCRIPTION
 *  To add font resource in file system
 * PARAMETERS
 *  resid           [IN]        
 *  buffer          [IN]        
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_fe_error_code mmi_fe_get_font_name(U16 resid, UI_string_type buffer, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_buf[64];
    mmi_fe_error_code err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err = font_engine->get_font_name(resid, temp_buf, buf_size);
    mmi_chset_convert(MMI_CHSET_ASCII, MMI_CHSET_UCS2, (char*)temp_buf, (char*)buffer, buf_size * 2);

    return err;
}

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_reset_font_boot_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  font                [?]         
 *  num                 [IN]        
 *  priority_list       [?]         
 *  init                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_reset_font_boot_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    U16 freetype_font_res_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER] = {0};
    U8 freetype_font_number = 0;
    int i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    /* reset cache */
    mmi_fe_cache_restart();
    mmi_fe_multiple_file_init();
    g_mmi_fe_font_family = 0;
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[0];
    //g_mmi_fe_curr_font_file = 0xFFFFFFFF;

    /* restart vector font engine without switch stack because stack might be used. */
    for(i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
    {
        for(j = 0; j < g_mmi_fe_font_file_number[i]; j++)
        {
            if (g_mmi_fe_font_file_list[i][j] >= IMG_GLOBAL_FONT_1 && g_mmi_fe_font_file_list[i][j] <= IMG_GLOBAL_FONT_MAX)
            {
                freetype_font_res_list[freetype_font_number] = g_mmi_fe_font_file_list[i][j];
                freetype_font_number++;
            }
        }
    }

    ret = font_engine->init(freetype_font_res_list, freetype_font_number);
    MMI_ASSERT(ret);

    FE_UNLOCK;
    GDI_UNLOCK;
    //mmi_font_mgr_reset_all();
    //mmi_font_mgr_reset_error_code();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_add_font_from_file
 * DESCRIPTION
 *  To add font resource in file system
 * PARAMETERS
 *  font                [?]         
 *  num                 [IN]        
 *  priority_list       [?]         
 *  init                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_fe_add_font_from_file(
            mmi_font_mgr_font_file_resource_struct *font,
            S32 num,
            S16 *priority_list,
            MMI_BOOL init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, k = 0;
    U16 temp[FE_MAX_FONT_FAMILY_NUMBER][FE_MAX_FONT_FILE_NUMBER];
    U8 temp_num[FE_MAX_FONT_FAMILY_NUMBER];
    BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    /* reset cache */
    mmi_fe_cache_restart();
    mmi_fe_multiple_file_init();

    /* create font list */
    memcpy(&temp, &g_mmi_fe_font_file_list, sizeof(temp));
    memcpy(&temp_num, &g_mmi_fe_font_file_number, sizeof(temp_num));

    /* TTF on File Disk only installs to Family[0]. By Yang */
    for (i = 0; i <= num && j < FE_MAX_FONT_FILE_NUMBER; i++)
    {
        if (priority_list[i] != -1)
        {
            g_mmi_fe_font_file_list[0][j] = priority_list[i];
            j++;
        }
        else
        {
            for (k = 0; k < temp_num[0]; k++)
            {
                /* MMI_ASSERT(j <= FE_MAX_FONT_FILE_NUMBER); */
                g_mmi_fe_font_file_list[0][j] = temp[0][k];
                j++;
            }
        }
    }
    g_mmi_fe_font_file_number[0] = j;
    g_mmi_fe_font_family = 0;
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[0];
    //g_mmi_fe_curr_font_file = 0xFFFFFFFF;

    /* restart vector font engine */
    if (init)
    {
        U16 freetype_font_res_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER] = {0};
        U8 freetype_font_number = 0;
        int i = 0, j = 0;
        g_mmi_fe_init_check = MMI_TRUE;
        kal_get_time(&g_mmi_fe_init_timer);
        g_mmi_fe_init_timer += MMI_FE_INIT_TIME_PERIOD;

        for(i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
        {
            for(j = 0; j < g_mmi_fe_font_file_number[i]; j++)
            {
                freetype_font_res_list[freetype_font_number] = g_mmi_fe_font_file_list[i][j];
                freetype_font_number++;
            }
        }


    #ifdef __MTK_TARGET__
        ret = INT_SwitchStackToRun(
                g_mmi_fe_stack,
                MMI_FE_STACK_SIZE,
                (kal_func_ptr) font_engine->init,
                2,
                freetype_font_res_list,
                freetype_font_number);
        kal_check_stack();  /* if overflow , assert it */
    #else /* __MTK_TARGET__ */ 
        ret = font_engine->init(freetype_font_res_list, freetype_font_number);
    #endif /* __MTK_TARGET__ */ 
        g_mmi_fe_init_check = MMI_FALSE;

        if (font_engine_error_code == MMI_FE_FONT_ERR_INIT_TIME_OUT ||
            font_engine_error_code == MMI_FE_FONT_ERR_INVALID_FILE_ACCESS ||
            font_engine_error_code == MMI_FE_FONT_ERR_INVALID_FONT_PATH
#ifdef __MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__
            || font_engine_error_code == MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY
#endif
            )
        {
            mmi_font_mgr_error_handler(font_engine_error_code);
            mmi_fe_vectorfont_engine_restart();
            font_engine_error_code = MMI_FE_FONT_ERR_NONE;
            ret = MMI_FALSE;
        }
        else
        {
            MMI_ASSERT(ret);
        }
    }

    mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[0], 0);
    FE_UNLOCK;
    GDI_UNLOCK;
    return (MMI_BOOL)ret;
}
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_stream_handle
 * DESCRIPTION
 * PARAMETERS
 *  resid       [IN]        
 * RETURNS
 *****************************************************************************/
void* mmi_fe_get_font_stream_handle(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_font_mgr_get_font_file_handle(resid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_external_font
 * DESCRIPTION
 * PARAMETERS
 *  handle      [?]         
 *  offset      [IN]        
 *  buffer      [?]         
 *  count       [IN]        
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_fe_is_external_font(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (resid < IMG_GLOBAL_FONT_1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_font
 * DESCRIPTION
 * PARAMETERS
 *  resid       [IN]        
 * RETURNS
 *****************************************************************************/
mmi_fe_error_code mmi_fe_check_font(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    return font_engine->check_font(resid);
#else 
    return MMI_FE_FONT_ERR_NONE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_vectorfont_engine_error
 * DESCRIPTION
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_vectorfont_engine_error(mmi_fe_error_code err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err)
    {
        case MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY:
        case MMI_FE_FONT_ERR_INVALID_FONT_PATH:
        case MMI_FE_FONT_ERR_INVALID_FILE_ACCESS:
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
            font_engine_error_code = err;
    #else /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
            /* when there is no external font resource, assert directly to change system font configuration. */
            MMI_ASSERT(0);
    #endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 

            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_vectorfont_engine_error_handler
 * DESCRIPTION
 * PARAMETERS
 *  err     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_vectorfont_engine_error_handler(mmi_fe_error_code err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err)
    {
        case MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY:
        case MMI_FE_FONT_ERR_INVALID_FONT_PATH:
        case MMI_FE_FONT_ERR_INVALID_FILE_ACCESS:
    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
            /* when there is external font resource, try to reset to apply system font. */
            if (mmi_font_mgr_error_handler(err))
            {
                mmi_fe_vectorfont_engine_restart();
                font_engine_error_code = MMI_FE_FONT_ERR_NONE;
            }
    #else /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
            /* when there is no external font resource, assert directly to change system font configuration. */
            MMI_ASSERT(0);
    #endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 

            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_system_font_number
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
S32 mmi_fe_get_system_font_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_mmi_fe_font_file_number[0]; i++)
    {
        if (g_mmi_fe_font_file_list[0][i] >= IMG_GLOBAL_FONT_1 
        #ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
            && g_mmi_fe_font_file_list[0][i] <= IMG_GLOBAL_FONT_MAX
        #endif
        )
            count++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_font_file_reader
 * DESCRIPTION
 * PARAMETERS
 *  handle      [?]         
 *  offset      [IN]        
 *  buffer      [?]         
 *  count       [IN]        
 * RETURNS
 *****************************************************************************/
unsigned long mmi_fe_font_file_reader(void *handle, unsigned long offset, unsigned char *buffer, unsigned long count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
    unsigned long readCnt;
    U32 curr_time;
    //U32 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (font_engine_error_code)
        return 0;
    font_engine_error_code = mmi_font_mgr_font_file_reader(handle, offset, buffer, count, &readCnt);
    if (font_engine_error_code)
    {
        mmi_fe_vectorfont_engine_error((mmi_fe_error_code)font_engine_error_code);
    }
    else if (g_mmi_fe_init_check)
    {

        kal_get_time(&curr_time);
        if (curr_time > g_mmi_fe_init_timer)
        {
            font_engine_error_code = MMI_FE_FONT_ERR_INIT_TIME_OUT;
            readCnt = 0;
        }

    }
    return readCnt;
#else /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
    MMI_ASSERT(0);
    return 0;
#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_font_file_closer
 * DESCRIPTION
 * PARAMETERS
 *  handle      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_font_file_closer(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
    mmi_font_mgr_font_file_closer(handle);
#else 
    MMI_ASSERT(0);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_resource
 * DESCRIPTION
 * PARAMETERS
 *  ResId           [IN]        
 *  type            [?]         
 *  enfb_handle     [?]         
 *  size            [?]         
 * RETURNS
 *****************************************************************************/
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
U8 *mmi_fe_get_font_resource(U16 ResId, mmi_fe_font_resource_type_enum *type, S32 *offset, S32 *size)
#else
U8 *mmi_fe_get_font_resource(U16 ResId, mmi_fe_font_resource_type_enum *type, S32 *size)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *res = NULL;
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    int i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    if (ResId < IMG_GLOBAL_FONT_1)
    {
        if (mmi_font_mgr_open_font(ResId, size))
        {
            *type = MMI_FE_FONT_OPEN_FILE_STREAM;
            return res;
        }
        else
        {
            *type = MMI_FE_FONT_OPEN_FILE_IVALID;
            return NULL;
        }
    }
    else
#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
    if (ResId > IMG_GLOBAL_FONT_MAX)
    {
        if (mmi_font_mgr_open_font(ResId, size))
        {
            *type = MMI_FE_FONT_OPEN_FILE_STREAM;
            return res;
        }
        else
        {
            *type = MMI_FE_FONT_OPEN_FILE_IVALID;
            return NULL;
        }
    }
    else
#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */
    {
        #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
        for(i=0; i<POP_FONT_FILES; i++)
        {
            if(ResId == ENFBFontResInfo[i].res_id)
            {
                *type = MMI_FE_FONT_OPEN_ENFB_RESOURCE;
                *offset = ENFBFontResInfo[i].offset;
                *size = ENFBFontResInfo[i].size;

                return res;
            }
        }
        ASSERT(0);
        #else
        res = (U8*) GetFontRaw(ResId);
        if (!res)
            return NULL;

        {
            *type = MMI_FE_FONT_OPEN_MEMORY;
            *size = (S32) (res[2])
                | (S32) ((S32) res[3] << 8) | (S32) ((S32) res[4] << 16) | (S32) ((S32) res[5] << 24);
            res += 8;
        }
        #endif
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  GetFontResource
 * DESCRIPTION
 *  To get font resource
 * PARAMETERS
 *  ResId           [IN]        
 *  is_enfb         [?]         
 *  enfb_handle     [?]         
 *  size            [?]         
 * RETURNS
 *  resource pointer
 *****************************************************************************/
U8 *GetFontResource(U16 ResId, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_font_resource_type_enum type;
    U8 *ret = NULL;
    #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    U32 offset;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    ret = mmi_fe_get_font_resource(ResId, &type, &offset, size);
    #else
    ret = mmi_fe_get_font_resource(ResId, &type, size);
    #endif

    switch (type)
    {
        case MMI_FE_FONT_OPEN_MEMORY:
            break;
            /* the old interface is only for system embedded font resource */
        case MMI_FE_FONT_OPEN_FILE_STREAM:
            MMI_ASSERT(0);
            break;
        default:
            MMI_ASSERT(0);
    }

    return ret;
}

#endif /* __MMI_SCRIPT_EASY__ */
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

//extern const font_group_struct g_fontfamily[MAX_FONT_SIZE];

extern const U8* gHWCompressionLv1Table;//U8 g_hw_compression_lv1_table[15];
extern const U8* gHWCompressionLv2Table;//U8 g_hw_compression_lv2_table[256][15];

#if defined(__MMI_BDF_SW_COMPRESSION__)
BFC_DECODER_HANDLE g_decoder;
#endif 

const char* const g_latin_language_country_code_table[] = 
{
    "sw-TZ",    /* __MMI_LANG_SWAHILI__ */
    "en-US",    /* __MMI_LANG_ENGLISH__ */
    "zu-SZ",    /* __MMI_LANG_ZULU__ */
    "xh-ZA",    /* __MMI_LANG_XHOSA__ */
    "tr-TR",    /* __MMI_LANG_TURKISH__ */
    "vi-VN",    /* __MMI_LANG_VIETNAMESE__ */
    "pl-PL",    /* __MMI_LANG_POLISH__ */
    "cs-CZ",    /* __MMI_LANG_CZECH__ */
    "nb-NO",    /* __MMI_LANG_NORWEGIAN__ */
    "fi-FI",    /* __MMI_LANG_FINNISH__ */
    "hu-HU",    /* __MMI_LANG_HUNGARIAN__ */

    "sk-SK",    /* __MMI_LANG_SLOVAK__ */
    "nl-NL",    /* __MMI_LANG_DUTCH__ */
    "sv-SE",    /* __MMI_LANG_SWEDISH__ */
    "hr-HR",    /* __MMI_LANG_CROATIAN__ */
    "ro-RO",    /* __MMI_LANG_ROMANIAN__ */
    "mo-MD",    /* __MMI_LANG_MOLDOVAN__ */
    "sl-SI",    /* __MMI_LANG_SLOVENIAN__ */
    "fr-FR",    /* __MMI_LANG_FRENCH__ */
    "fr-CA",    /* __MMI_LANG_CA_FRENCH__ */
    "lt-LT",    /* __MMI_LANG_LITHUANIAN__ */

    "lv-LV",    /* __MMI_LANG_LATVIAN__ */
    "et-EE",    /* __MMI_LANG_ESTONIAN__ */
    "af-NA",    /* __MMI_LANG_AFRIKAANS__ */
    "az-AZ",    /* __MMI_LANG_AZERBAIJANI__ */
    "ha-HA",    /* __MMI_LANG_HAUSA__ */
    "is-IS",    /* __MMI_LANG_ICELANDIC__ */
    "sr-SR",    /* __MMI_LANG_SERBIAN__ */
    "ig-NG",    /* __MMI_LANG_IGBO__ */
    "es-ES"     /* __MMI_LANG_SPANISH__ */
};

#ifdef __MMI_FONT_GROUP_COMPRESSION__

static void fe_lzma_mem_init(void* buff_ptr, kal_uint32 buff_size)
{
    smmInit(&_font_lzma_decompress_smm, buff_ptr, buff_size);
}

static void *fe_lzma_malloc(void *p, unsigned int size)
{
   return smmMallocAligned(&_font_lzma_decompress_smm, size, 4);
}

static void fe_lzma_free(void *p, void *address)
{
   return;
}

static ISzAlloc fe_lzma_Alloc = {fe_lzma_malloc, fe_lzma_free};

S32 mmi_fe_lzma_uncompress(unsigned char *dest, U32 *destLen, const unsigned char *src, U32 *srcLen)
{
    S32 ret;
    ELzmaStatus status;

    fe_lzma_mem_init(font_lzma_decomp_buff_pool, FONT_LZMA_DECOMP_BUFF_SIZE);
    
    ret = LzmaDecode(dest, destLen, src+LZMA_PROPS_SIZE, srcLen,
             src, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &fe_lzma_Alloc);

    if(ret)
        ASSERT(0);

    return ret;
}

#endif

#if defined(__MMI_BIDI_ALG__)
static MMI_BOOL mmi_fe_check_first_is_r2l(U8 *String)
{
    MMI_BOOL ret = MMI_FALSE;
    U8 dic = 0;
    U16 unicode = 0;

    unicode = String[0];
    unicode |= (String[1] << 8);

    bidi_get_char_type((U8*) (&unicode), &dic);

    if (dic == BIDI_R || dic == AL || dic == AN)
    {
        ret = MMI_TRUE;
    }
        
    return ret;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_pixel_to_size
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  pixel       [IN]        
 * RETURNS
 *****************************************************************************/
U8 mmi_fe_pixel_to_size(U8 pixel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
    if (pixel >= 21)
        return LARGE_FONT;
    if (pixel >= 17)
        return MEDIUM_FONT;
    else
        return SMALL_FONT;
#elif defined(__MMI_MAINLCD_320X480__)
    if (pixel >= 22)
        return LARGE_FONT;
    if (pixel >= 17)
        return MEDIUM_FONT;
    else
        return SMALL_FONT;
#else 
    if (pixel <= 12)
        return SMALL_FONT;
    if (pixel >= 15)
        return LARGE_FONT;

    return MEDIUM_FONT;
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL font_mgr_init = MMI_FALSE;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    BOOL ret;

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_font_mgr_font_file_resource_struct *font_info_ptr = NULL;
    S32 num = 0;
    S16 *priority_list = NULL;
#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 

    U16 freetype_font_res_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER] = {0};
    U8 freetype_font_number = 0;
    int i = 0, j = 0;
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* font engine already init successfully. */
    if (font_mgr_init)
        return;

    gdi_mutex_init(&g_mmi_fe_cache_mutex);

#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)

    mmi_fe_enable_font_engine();

    g_mmi_fe_font_family = 0;

   
    mmi_fe_cache_init();
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
    mmi_fe_preload_font_init = mmi_preload_font_init();
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    font_mgr_init = mmi_font_mgr_init();
    mmi_font_mgr_get_font_info(&font_info_ptr, &num, &priority_list);
    if (num)
    {
        ret = mmi_fe_add_font_from_file(font_info_ptr, num, priority_list, MMI_TRUE);
        return;
    }
#else /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 
    font_mgr_init = MMI_TRUE;
#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */ 

    mmi_fe_multiple_file_init();

    for(i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
    {
        for(j = 0; j < g_mmi_fe_font_file_number[i]; j++)
        {
            freetype_font_res_list[freetype_font_number] = g_mmi_fe_font_file_list[i][j];
            freetype_font_number++;
        }
    }

#ifdef __MTK_TARGET__
    ret = INT_SwitchStackToRun(
            g_mmi_fe_stack,
            MMI_FE_STACK_SIZE,
            (kal_func_ptr) font_engine_table.init,
            2,
            freetype_font_res_list,
            freetype_font_number);
    kal_check_stack();  /* if overflow , assert it */
#else /* __MTK_TARGET__ */ 
    ret = font_engine_table.init(freetype_font_res_list, freetype_font_number);
#endif /* __MTK_TARGET__ */ 

    if (ret)
    {
        mmi_fe_set_antialias(MMI_TRUE);
        mmi_fe_set_font(1, 0);
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* generate font cache */
    mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[0], 0);
#elif defined(__MMI_SCRIPT_EASY__)
    se_mtk_initialize();
    // font set    
    se_mtk_load_profile();   
    mmi_fe_enable_font_engine();
    mmi_fe_set_font(1, 0);
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

#if defined(__MMI_FONT_GROUP_COMPRESSION__)
    mmi_fe_cache_init();
#endif

#if defined(__MMI_BDF_SW_COMPRESSION__)
    bfcDecGetDecoder(&g_decoder);
    bfcDecSetDictionary(g_decoder, (U8*) gHWCompressionLv1Table, (U8*) gHWCompressionLv2Table);
#endif /* defined(__MMI_BDF_SW_COMPRESSION__) */ 
#if defined(__MMI_FONT_EFFECTS__)
    for (i = 0; i < 256; i++)
    {
        S32 j = i;
        S32 k = 0;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j&1; k<<=1;j>>=1;
        k |= j & 1;

        mmi_fe_bits_revise_table[i] = k;
    }
#endif
}

#if defined(__MMI_FONT_EFFECTS__)
extern S32 mmi_res_get_theme_count(void);
extern S32 mmi_res_get_theme_integer(U16 id);
extern S32 mmi_res_get_theme_color(U16 id);
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_init_font_effect_theme(void)
{
    S32 i = 0;
    S32 temp_color;

    //if( gFontAttributeTotalNode == 0)
    {
        gFontAttributeLastStaticNode = MMI_FE_FONT_EFFECT_FINAL_MAX -1 ;
        gFontAttributeTotalNode = MMI_FE_FONT_EFFECT_FINAL_MAX - 1;

        if(mmi_res_get_theme_count() > 0)
        {
            /* shadow effect */
            for(i=0; i < 9 ; i++)
            {
                memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
                memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
                gFontAttributeNode[i].advance_font_attribute.shadow_degree = (S16) mmi_res_get_theme_integer(FE1_1_1_SHADOW_DEGREE + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_distant = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_DISTANT + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_range = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_RANGE + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_transparency = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_TRANSPARENCY + i * 4);
                temp_color = mmi_res_get_theme_color(FE1_1_1_SHADOW_COLOR + i);

                gFontAttributeNode[i].font_color.shadow_color.a = (U8) (temp_color >> 24);
                gFontAttributeNode[i].font_color.shadow_color.r = (U8)(temp_color >> 16);
                gFontAttributeNode[i].font_color.shadow_color.g = (U8)(temp_color >> 8);
                gFontAttributeNode[i].font_color.shadow_color.b = (U8)(temp_color);
            }
            
            /* outer glow effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.outerglow_range = (U8) mmi_res_get_theme_integer(FE2_2_1_OUTER_GLOW_RANGE);
            gFontAttributeNode[i].advance_font_attribute.outerglow_transparency = (U8) mmi_res_get_theme_integer(FE2_2_2_OUTER_GLOW_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE2_2_3_OUTER_GLOW_COLOR);
            gFontAttributeNode[i].font_color.outerglow_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.outerglow_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.outerglow_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.outerglow_color.b = (U8)(temp_color);
            i++;
            
            /* engraved effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.engraved_degree = (S16) mmi_res_get_theme_integer(FE3_3_1_ENGRAVED_DEGREE);
            gFontAttributeNode[i].advance_font_attribute.engraved_transparency = (U8) mmi_res_get_theme_integer(FE3_3_2_ENGRAVED_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE3_3_3_UPPER_ENGRAVED_COLOR);
            gFontAttributeNode[i].font_color.upper_engraved_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.upper_engraved_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.upper_engraved_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.upper_engraved_color.b = (U8)(temp_color);
            temp_color = mmi_res_get_theme_color(FE3_3_4_LOWER_ENGRAVED_COLOR);
            gFontAttributeNode[i].font_color.lower_engraved_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.lower_engraved_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.lower_engraved_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.lower_engraved_color.b = (U8)(temp_color);
            i++;

            /* Gradient effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.gradient_direction = (U8)mmi_res_get_theme_integer(FE4_4_1_GRADIENT_DIRECTION);
            gFontAttributeNode[i].advance_font_attribute.gradient_transparency = (U8)mmi_res_get_theme_integer(FE4_4_2_GRADIENT_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE4_4_3_FIRST_GRADIENT_COLOR);
            gFontAttributeNode[i].font_color.first_gradient_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.first_gradient_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.first_gradient_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.first_gradient_color.b = (U8)(temp_color);
            temp_color = mmi_res_get_theme_color(FE4_4_4_SECOND_GRADIENT_COLOR);
            gFontAttributeNode[i].font_color.second_gradient_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.second_gradient_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.second_gradient_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.second_gradient_color.b = (U8)(temp_color);
            i++;

            /* border effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.border_size = (U8)mmi_res_get_theme_integer(FE5_5_1_BORDER_SIZE);
            gFontAttributeNode[i].advance_font_attribute.border_transparency = (U8)mmi_res_get_theme_integer(FE5_5_2_BORDER_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE5_5_3_BORDER_COLOR);
            gFontAttributeNode[i].font_color.bordered_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.bordered_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.bordered_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.bordered_color.b = (U8)(temp_color);
        }
        
        gFontAttributeNode[gFontAttributeLastStaticNode].next = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_init_font_effect_theme_ext(void)
{
    S32 i = 0;
    S32 temp_color;

    if( gFontAttributeTotalNode == 0)
    {
        gFontAttributeLastStaticNode = MMI_FE_FONT_EFFECT_FINAL_MAX -1 ;
        gFontAttributeTotalNode = MMI_FE_FONT_EFFECT_FINAL_MAX - 1;

        if(mmi_res_get_theme_count() > 0)
        {
            /* shadow effect */
            for(i=0; i < 9 ; i++)
            {
                memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
                memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
                gFontAttributeNode[i].advance_font_attribute.shadow_degree = (S16) mmi_res_get_theme_integer(FE1_1_1_SHADOW_DEGREE + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_distant = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_DISTANT + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_range = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_RANGE + i * 4);
                gFontAttributeNode[i].advance_font_attribute.shadow_transparency = (U8) mmi_res_get_theme_integer(FE1_1_1_SHADOW_TRANSPARENCY + i * 4);
                temp_color = mmi_res_get_theme_color(FE1_1_1_SHADOW_COLOR + i);

                gFontAttributeNode[i].font_color.shadow_color.a = (U8) (temp_color >> 24);
                gFontAttributeNode[i].font_color.shadow_color.r = (U8)(temp_color >> 16);
                gFontAttributeNode[i].font_color.shadow_color.g = (U8)(temp_color >> 8);
                gFontAttributeNode[i].font_color.shadow_color.b = (U8)(temp_color);
            }
            
            /* outer glow effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.outerglow_range = (U8) mmi_res_get_theme_integer(FE2_2_1_OUTER_GLOW_RANGE);
            gFontAttributeNode[i].advance_font_attribute.outerglow_transparency = (U8) mmi_res_get_theme_integer(FE2_2_2_OUTER_GLOW_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE2_2_3_OUTER_GLOW_COLOR);
            gFontAttributeNode[i].font_color.outerglow_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.outerglow_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.outerglow_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.outerglow_color.b = (U8)(temp_color);
            i++;
            
            /* engraved effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.engraved_degree = (S16) mmi_res_get_theme_integer(FE3_3_1_ENGRAVED_DEGREE);
            gFontAttributeNode[i].advance_font_attribute.engraved_transparency = (U8) mmi_res_get_theme_integer(FE3_3_2_ENGRAVED_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE3_3_3_UPPER_ENGRAVED_COLOR);
            gFontAttributeNode[i].font_color.upper_engraved_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.upper_engraved_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.upper_engraved_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.upper_engraved_color.b = (U8)(temp_color);
            temp_color = mmi_res_get_theme_color(FE3_3_4_LOWER_ENGRAVED_COLOR);
            gFontAttributeNode[i].font_color.lower_engraved_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.lower_engraved_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.lower_engraved_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.lower_engraved_color.b = (U8)(temp_color);
            i++;

            /* Gradient effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.gradient_direction = (U8)mmi_res_get_theme_integer(FE4_4_1_GRADIENT_DIRECTION);
            gFontAttributeNode[i].advance_font_attribute.gradient_transparency = (U8)mmi_res_get_theme_integer(FE4_4_2_GRADIENT_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE4_4_3_FIRST_GRADIENT_COLOR);
            gFontAttributeNode[i].font_color.first_gradient_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.first_gradient_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.first_gradient_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.first_gradient_color.b = (U8)(temp_color);
            temp_color = mmi_res_get_theme_color(FE4_4_4_SECOND_GRADIENT_COLOR);
            gFontAttributeNode[i].font_color.second_gradient_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.second_gradient_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.second_gradient_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.second_gradient_color.b = (U8)(temp_color);
            i++;

            /* border effect */
            memset(&(gFontAttributeNode[i].advance_font_attribute), 0, sizeof(stAdvanceFontAttribute));
            memset(&(gFontAttributeNode[i].font_color), 0, sizeof(stFontColor));
            gFontAttributeNode[i].advance_font_attribute.border_size = (U8)mmi_res_get_theme_integer(FE5_5_1_BORDER_SIZE);
            gFontAttributeNode[i].advance_font_attribute.border_transparency = (U8)mmi_res_get_theme_integer(FE5_5_2_BORDER_TRANSPARENCY);
            temp_color = mmi_res_get_theme_color(FE5_5_3_BORDER_COLOR);
            gFontAttributeNode[i].font_color.bordered_color.a = (U8) (temp_color >> 24);
            gFontAttributeNode[i].font_color.bordered_color.r = (U8)(temp_color >> 16);
            gFontAttributeNode[i].font_color.bordered_color.g = (U8)(temp_color >> 8);
            gFontAttributeNode[i].font_color.bordered_color.b = (U8)(temp_color);
        }
        
        gFontAttributeNode[gFontAttributeLastStaticNode].next = NULL;
    }
}
#endif /* defined(__MMI_FONT_EFFECTS__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_space
 * DESCRIPTION
 *  To test if a special character should be displayed as space or not
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_space(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FONT_TEST_CONTROL_CHAR(ch) || FONT_TEST_SPACE_CHAR(ch))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_null
 * DESCRIPTION
 *  To test if a special character should be displayed as zero width character or not
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_null(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0x7f ||
        FONT_TEST_ZERO_WIDTH_CHAR(ch) ||
        FONT_TEST_FORMATTING_CHARS(ch) ||
        FONT_TEST_ZERO_WIDTH_SPACE(ch) ||
        (ch == 0x0085 && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_invalid
 * DESCRIPTION
 *  To test if a special character should be displayed as invalid character (Dec: 65515/ Hex: 0xFFEB) or not
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_invalid(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((FONT_TEST_DATE_CHARS(ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
        (ch == 0x0086 && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_alphabetic_lang_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_fe_test_alphabetic_lang_char(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if ((ch <= 0x2180 || ch >= 0x9eaf) /* && !IRE_INDIC_CHARACTER_UCS2_RANGE(ch) */ )
        return MMI_TRUE;
#else /* defined(__MMI_INDIC_ALG__) */ 
    if ((ch <= 0x2180 || ch >= 0x9eaf))
        return MMI_TRUE;
#endif /* defined(__MMI_INDIC_ALG__) */ 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_ucs2_proprietary_display
 * DESCRIPTION
 *  To enable UCS2 proprietary range (0xE000 - 0xF8FF)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_ucs2_proprietary_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_UCS2_PROPRIETARY;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_ucs2_proprietary_display
 * DESCRIPTION
 *  To disable UCS2 proprietary range (0xE000 - 0xF8FF)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_ucs2_proprietary_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_UCS2_PROPRIETARY);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_date_char_display
 * DESCRIPTION
 *  To enable special date character (133~147 0x85~0x93) display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_DATE_CHAR;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_date_char_display
 * DESCRIPTION
 *  To disable special date character (133~147 0x85~0x93) display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_DATE_CHAR);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_proprietary_symbol_display
 * DESCRIPTION
 *  To enable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_proprietary_symbol_display
 * DESCRIPTION
 *  To disable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  Get_Current_Lang_CountryCode
 * DESCRIPTION
 *  To get current language's country code
 *  This is used to get current language's country code
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 *
 *****************************************************************************/
U8 *Get_Current_Lang_CountryCode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = (U8*) gLanguageArray[gCurrLangIndex].aLangCountryCode;
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_text_color
 * DESCRIPTION
 *  To set text color
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_text_color(mmi_fe_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    g_mmi_fe_text_color = c;
#ifdef __MMI_SCRIPT_EASY__
    {
        extern void se_mtk_set_text_color(color c);
        color cc;
        cc.r = c.r;
        cc.g = c.g;
        cc.b = c.b;
        cc.alpha = c.a;
        se_mtk_set_text_color(cc);
    }
#endif
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_text_border_color
 * DESCRIPTION
 *  To set text border color
 * PARAMETERS
 *  c       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_text_border_color(mmi_fe_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    g_mmi_fe_text_border_color = c;
#ifdef __MMI_SCRIPT_EASY__
    {
        extern  void se_mtk_set_text_border_color(color c);
        color cc;
        cc.r = c.r;
        cc.g = c.g;
        cc.b = c.b;
        cc.alpha = c.a;
        se_mtk_set_text_border_color(cc);
    }
#endif
    GDI_UNLOCK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_text_color
 * DESCRIPTION
 *  To get text color
 * PARAMETERS
 *  void
 * RETURNS
 *  color
 *****************************************************************************/
mmi_fe_color mmi_fe_get_text_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_color ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = g_mmi_fe_text_color;
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_text_border_color
 * DESCRIPTION
 *  To get text border color
 * PARAMETERS
 *  void
 * RETURNS
 *  color
 *****************************************************************************/
mmi_fe_color mmi_fe_get_text_border_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_color ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = g_mmi_fe_text_border_color;
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_vector_font_support
 * DESCRIPTION
 *  To check if vector font is supported on the platform
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fe_is_vector_font_support(void)
{
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
#else /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
    return MMI_FALSE;
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_r2l_state
 * DESCRIPTION
 *  To check if it is on r2l state under current system language
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fe_is_r2l_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = (MMI_BOOL)r2lMMIFlag;
    GDI_UNLOCK;
    return ret;
}
#if defined (__MMI_BIDI_ALG__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_r2l_state
 * DESCRIPTION
 *  To get r2l state under current system language
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fe_get_r2l_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = (MMI_BOOL)r2lMMIFlag;
    GDI_UNLOCK;
    return ret;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_r2l_state
 * DESCRIPTION
 *  To get r2l state under current system language
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_fe_set_r2l_state(MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    r2lMMIFlag = state;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  SetFont
 * DESCRIPTION
 *  To set the fonts.
 *  This is used to set all different type of font with different sizes.
 * PARAMETERS
 *  Font            [IN]        The font attribute
 *  arrCount        [IN]        The font family
 * RETURNS
 *  U8
 *****************************************************************************/
#ifdef __MMI_SCRIPT_EASY__

U8 SetFont(stFontAttribute Font, U8 arrCount)
{
    se_mtk_SetFont(Font, arrCount);
    font_engine_font_pixel = se_mtk_get_character_height();
    return 0;
}

#else /* __MMI_SCRIPT_EASY__ */
U8 SetFont(stFontAttribute Font, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 font_size = Font.size;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    static stFontAttribute prev_Font;
    static U8 prev_arrCount;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if(prev_arrCount == arrCount && memcmp(&prev_Font, &Font, sizeof(stFontAttribute)) == 0)
    {
        FE_UNLOCK;
        GDI_UNLOCK;
        return 0;
    }
    
    prev_arrCount = arrCount;
    memcpy(&prev_Font, &Font, sizeof(stFontAttribute));
#endif

#ifndef __MMI_VECTOR_FONT_SUPPORT__
    if (font_size & 0x80)
    {
        font_size &= 0x7f;
        font_size = mmi_fe_pixel_to_size(font_size);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    gnCurrentFont = font_size;
    gbFontType = Font.smallCaps;
    gnCurrentFontAttrib = 0;
    gFontEffect = FONT_EFFECT_NONE;

    if (gbFontType != 0)
    {
        gbFontType = 0;
    }

    if (Font.bold)
    {
        gnCurrentFontAttrib |= FONTATTRIB_BOLD;
    }
    if (Font.italic)
    {
        gnCurrentFontAttrib |= FONTATTRIB_ITALIC;
    }
    if (Font.oblique)
    {
        gnCurrentFontAttrib |= FONTATTRIB_OBLIQUE;
    }
    if (Font.underline)
    {
        gnCurrentFontAttrib |= FONTATTRIB_UNDERLINE;
    }
    if (Font.smallCaps == 1)
    {
        gnCurrentFontAttrib |= FONTATTRIB_STRIKETHROUGH;
    }
    if (Font.smallCaps == 2)
    {
        gFontEffect = FONT_EFFECT_ENGRAVE;
    }
#if defined(__MMI_FONT_EFFECTS__)
    gSubFontEffect = Font.smallCaps;

    switch (gSubFontEffect)
    {
        case 0:
        case 1:
        case 2:
            break;
        default:
            setFontEffectAttribute();
            break;
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    if (!gnCurrentFontAttrib)
    {
        gnCurrentFontAttrib |= FONTATTRIB_NORMAL;
    }

    SetFontValues(gnCurrentFont, arrCount);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        U32 attr = 0;

        if (Font.bold)
            attr |= FE_FONT_ATTR_BOLD;
        if (Font.italic)
            attr |= FE_FONT_ATTR_ITALIC;
        if (Font.oblique)
            attr |= FE_FONT_ATTR_OBLIQUE;
        if (gFontEffect == FONT_EFFECT_ENGRAVE)
            attr |= FE_FONT_ATTR_ENGRAVE;
        if (Font.underline)
            attr |= FE_FONT_ATTR_UNDERLINE;

        /* Support for Fixed width, Family index = 1; */
        if(Font.type == FONT_TYPE_FIXED_WIDTH)
        {
            mmi_fe_set_family(FONT_FAMILY_FIXED_WIDTH);
        }
        else
        {
            mmi_fe_set_family(FONT_FAMILY_NORMAL);
        }

        if (arrCount < g_mmi_fe_font_file_number[g_mmi_fe_font_family])
        {
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[arrCount], arrCount);
        }
        /* font_engine->set_font_attr(font_engine_font_attr); */
        mmi_fe_set_font((U8) gnCurrentFont, attr);
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    FE_UNLOCK;
    GDI_UNLOCK;
    return 0;
}
#endif /* __MMI_SCRIPT_EASY__ */


/*****************************************************************************
 * FUNCTION
 *  GetFont
 * DESCRIPTION
 *  To get the current font.
 *  This is used to get current font attribute.
 * PARAMETERS
 *  Font            [IN/OUT]        
 *  arrCount        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetFont(stFontAttribute *Font, U8 *arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    memset(Font, 0, sizeof(stFontAttribute));
    *arrCount = 0;
    Font->size = gnCurrentFont;
    Font->smallCaps = gbFontType;

    if ((gnCurrentFontAttrib & FONTATTRIB_BOLD))
    {
        Font->bold = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_ITALIC))
    {
        Font->italic = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_OBLIQUE))
    {
        Font->oblique = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_UNDERLINE))
    {
        Font->underline = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_NORMAL))
    {
    }
    GDI_UNLOCK;

}

#ifndef __MMI_SCRIPT_EASY__
/*****************************************************************************
 * FUNCTION
 *  SetFontValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nFont           [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void SetFontValues(U32 nFont, U8 arrCount)
{
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    return;
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const font_group_struct *font_group = &(gfontfamily[nFont]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * if (gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily] == NULL)
     * return;
     * 
     * if ((gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->nTotalFonts) > nFont)
     * {
     * gpCurrentFont =
     * gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[nFont];
     * }
     * else
     * {
     * gpCurrentFont = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[0];
     * }
     */
    gpCurrentFont = font_group->fontData[arrCount];
#endif 
}
#endif /* __MMI_SCRIPT_EASY__ */ 

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 

#if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))

#if !defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  SearchInZiExtraFont
 * DESCRIPTION
 *  To search a character in the Zi Extra font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
static S32 SearchInZiExtraFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * S16 nFirst = 0;
     * S16 nLast = gZiExtraCharacter.pRangeDetails->nNoOfRanges - 1;
     * S16 nMid;
     */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*    
     * while (nLast >= nFirst)
     * {
     * nMid = (nFirst + nLast) / 2;;
     * if ((nCh >= gZiExtraCharacter_RangeData[nMid].nMin) && (nCh <= gZiExtraCharacter_RangeData[nMid].nMax))
     * {
     * *pnBase = gZiExtraCharacter_RangeData[nMid].nMin;
     * #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
     * return gZiExtraCharacter.pRange->rangeOffset[nMid];
     * #else
     * return gZiExtraCharacter.pRange[nMid];
     * #endif
     * 
     * }
     * if (nCh > gZiExtraCharacter_RangeData[nMid].nMin)
     * {
     * nFirst = nMid + 1;
     * }
     * else
     * {
     * nLast = nMid - 1;
     * }
     * 
     * }
     */
    return -1;
}
#endif /* !defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 
#endif /* defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)) */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_BDF_SW_COMPRESSION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#endif /* 0 */ 

#ifndef __MMI_SCRIPT_EASY__

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_data_internal
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  Ch                  [IN]        
 *  type                [IN]        
 *  ppCharData          [OUT]       
 *  pnWidth             [OUT]       
 *  advance_x           [OUT]       
 *  pnHeight            [OUT]       
 *  glyph_width         [OUT]       
 *  glyph_height        [OUT]       
 *  ascent              [?]         
 *  descent             [?]         
 *  valid               [?]         
 *  Font(?)             [IN]        
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
__inline static U32 mmi_fe_get_font_data_internal(
                        U16 Ch,
                        U8 type,
                        U8 **ppCharData,
                        S32 *pnWidth,
                        S32 *advance_x,
                        U16 *pnHeight,
                        U16 *glyph_width,
                        U16 *glyph_height,
                        S32 *ascent,
                        S32 *descent,
                        MMI_BOOL *valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S32 NumChar = 0;
    S32 index = -1;
    S32 nFontIndex = -1;
    U32 nIndexInList;
    U32 nBase;
    U32 nHashKey = 0;
    CharHashTable *charHashTable;

#if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
    U16 block_index, block_index_next;
#endif 
#ifdef __MMI_FONT_GROUP_COMPRESSION__
    U32 offset, encode_size, encode_offset, decode_size, decode_offset;
    static U32 prev_decode_size = 0, prev_decode_offset = 0;
    mmi_fe_bf_cache_key *key, key_data;
    mmi_fe_bf_cache_info *info;
#endif
    //sCustFontData *extraFontPtr = NULL;

#ifdef __MMI_INDIC_ALG__
    const sCustFontData *CurrentFont = gpCurrentFont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *advance_x = 0;
#endif /* __MMI_INDIC_ALG__ */ 

    if (Ch & 0xFF00)
    {
        charHashTable = charHashTableOthers;
        nHashKey = Ch & OTHERS_CHAR_HT_MASK;
    }
    else
    {
        charHashTable = charHashTableLatin;
        nHashKey = Ch & LATIN_CHAR_HT_MASK;
    }

    /* for character check, we couldn't use cache. */
    if (type != MMI_FE_VALID_CHECK)
    {
        #ifdef __MMI_FONT_GROUP_COMPRESSION__
        key_data.gnCurrentFont = gnCurrentFont;
        key_data.unicode = Ch;
        if(mmi_fe_bf_cache_tree_find(&key_data, &info))
        {
            *ppCharData = info->CharData;
            *pnWidth = info->Width;
            *pnHeight = info->Height;
            *advance_x = (S32) info->DWidth;
            /* usually the character width = data width */
            *glyph_height = *pnHeight;
            *glyph_width = *pnWidth;
            *ascent = info->Ascent;
            *descent = info->Descent;
            if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD))   /* && */
                //     gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                //      !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
            {
            }
            else
            {
                /* when bold word, character width is more one than data width */
                *pnWidth = *pnWidth + 1;
                *advance_x = *advance_x + 1;
            }

            return info->NumChar;
        }
        #else
        if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
        {
            *ppCharData = charHashTable[nHashKey].CharData;
            *pnWidth = charHashTable[nHashKey].Width;
            *pnHeight = charHashTable[nHashKey].Height;
            *advance_x = (S32) charHashTable[nHashKey].DWidth;
            /* usually the character width = data width */
            *glyph_height = *pnHeight;
            *glyph_width = *pnWidth;
            *ascent = charHashTable[nHashKey].Ascent;
            *descent = charHashTable[nHashKey].Descent;
            if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD))   /* && */
                //     gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                //      !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
            {
            }
            else
            {
                /* when bold word, character width is more one than data width */
                *pnWidth = *pnWidth + 1;
                *advance_x = *advance_x + 1;
            }

            return charHashTable[nHashKey].NumChar;
        }
        #endif
    }
    charHashTable[nHashKey].unicode = Ch;
    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);
    charHashTable[nHashKey].count = count;                  /* no use now */
    charHashTable[nHashKey].gnCurrentFont = gnCurrentFont;  /* font size */
    charHashTable[nHashKey].index = index;                  /* is index of range block */

    if (index > -1)
    {

        /* Comments : No error handling is being  done if some characters come that is not
           currently supported then nothing can be displayed */

        /* SetFontValues(nFontIndex, count); */
        charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->nWidth;
        charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->nWidth;
        charHashTable[nHashKey].Height = *pnHeight = gpCurrentFont->nHeight;
        charHashTable[nHashKey].Ascent = *ascent = gpCurrentFont->nAscent;
        charHashTable[nHashKey].Descent = *descent = gpCurrentFont->nDescent;
        nIndexInList = index + (Ch - nBase);

    #ifndef __MMI_BDF_SW_COMPRESSION__
        if (gpCurrentFont->nEquiDistant)
        {
            charHashTable[nHashKey].NumChar = NumChar = gpCurrentFont->nCharBytes;
            //nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].CharData = *ppCharData = (gpCurrentFont->pDataArray + (nIndexInList * NumChar));
        }
        else
    #endif /* __MMI_BDF_SW_COMPRESSION__ */ 
        {
        #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
            //nIndexInList = index + (Ch - nBase);    /* character index */
            block_index = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList);
            block_index_next = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList + 1);

            if (!gpCurrentFont->nEquiDistant)
            {
                charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
                charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->pWidthArray[nIndexInList];
            }
            charHashTable[nHashKey].NumChar = NumChar =
                ((block_index_next << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList + 1])
                - ((block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList]);
            #ifdef __MMI_FONT_GROUP_COMPRESSION__
            offset = (block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList];
            mmi_fe_get_group_info(gpCurrentFont->pGroupDetails, offset, &encode_size, &encode_offset, &decode_size, &decode_offset);
            if(decode_size != prev_decode_size || decode_offset != prev_decode_offset)
                mmi_fe_lzma_uncompress(gFontGroupCompressionBuf, &encode_size, gpCurrentFont->pDataArray + decode_offset, &decode_size);
            charHashTable[nHashKey].CharData = *ppCharData = &gFontGroupCompressionBuf[offset-encode_offset];
            if(block_index_next == (U16)(-1))
            {
                charHashTable[nHashKey].NumChar = NumChar =
                    gpCurrentFont->pGroupDetails->pGroupData[gpCurrentFont->pGroupDetails->nNoOfGroup-1].nOffset
                    - ((block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList]);
            }
            prev_decode_size = decode_size;
            prev_decode_offset = decode_offset;
            key = (mmi_fe_bf_cache_key *)(&charHashTable[nHashKey]);
            info = (mmi_fe_bf_cache_info *)((U8 *)&charHashTable[nHashKey] + sizeof(mmi_fe_bf_cache_key));
            #else
            charHashTable[nHashKey].CharData = *ppCharData =(gpCurrentFont->pDataArray + (block_index << FE_DATA_OFFSET_BIT_SIZE) +
                 gpCurrentFont->pOffsetArray[nIndexInList]);
            #endif

        #else /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
            //nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].NumChar = NumChar =
                (gpCurrentFont->pOffsetArray[nIndexInList + 1] - gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + gpCurrentFont->pOffsetArray[nIndexInList]);
        #endif /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
        }
    #ifdef __MMI_INDIC_ALG__
        if (gpCurrentFont->pDWidthArray)
        {
            *advance_x = (S32) gpCurrentFont->pDWidthArray[nIndexInList];
            charHashTable[nHashKey].DWidth = gpCurrentFont->pDWidthArray[nIndexInList];
        }
        gpCurrentFont = CurrentFont;
    #endif /* __MMI_INDIC_ALG__ */ 
        /* usually the character width = data width */
        *glyph_height = *pnHeight;
        *glyph_width = *pnWidth;
        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD))   /* && */
            //      gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            //      !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {

        }
        else
        {
            /* when bold word, character width is one more than data width */
            *pnWidth = *pnWidth + 1;
            *advance_x = *advance_x + 1;
        }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        #ifdef __MMI_FONT_GROUP_COMPRESSION__
        mmi_fe_bf_cache_tree_save_info(key, info, sizeof(mmi_fe_bf_cache_info));
        #endif
        return NumChar;
    }
#if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)
    else
    {
        /*
         * #if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
         * index = mmi_fe_search_in_prop_font(Ch, &nBase, &gZiExtraCharacterFontFamily, &extraFontPtr);
         * if (index != -1)
         * {
         * charHashTable[nHashKey].Height = *pnHeight = extraFontPtr->nHeight;
         * nIndexInList = index + (Ch - nBase);
         * charHashTable[nHashKey].Width = *pnWidth = extraFontPtr->pWidthArray[nIndexInList];
         * charHashTable[nHashKey].Ascent = *ascent = extraFontPtr->nAscent;
         * charHashTable[nHashKey].Descent = *descent = extraFontPtr->nDescent;
         * charHashTable[nHashKey].NumChar = NumChar =
         * (extraFontPtr->pOffsetArray[nIndexInList + 1] - extraFontPtr->pOffsetArray[nIndexInList]);
         * charHashTable[nHashKey].CharData = *ppCharData =
         * (extraFontPtr->pDataArray + extraFontPtr->pOffsetArray[nIndexInList]);
         * charHashTable[nHashKey].DWidth = *pnWidth;
         * *advance_x = *pnWidth;
         * 
         * }
         * else
         * #endif
         */
        {
            /* index = mmi_fe_search_in_prop_font(Ch, &nBase, &gMTKProprietaryFontFamily, &extraFontPtr); */
            if (index == -1)
            {
                /* ch is junk */
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_INVALID_CHARACTER, Ch);
                Ch = 65515; /* 0x4E01;//0x000F; */
                *valid = MMI_FALSE;
                /* index = mmi_fe_search_in_prop_font(Ch, &nBase, &gMTKProprietaryFontFamily, &extraFontPtr); */
                GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);
                if (index == -1)
                {
                #ifdef __MMI_INDIC_ALG__
                    gpCurrentFont = CurrentFont;
                #endif 
                    *advance_x = 0;
                    *pnWidth = 0;
                    *glyph_height = 0;
                    *glyph_width = 0;
                    *ascent = 0;
                    *descent = 0;
                    return NumChar;
                }
            }
            charHashTable[nHashKey].Height = *pnHeight = gpCurrentFont->nHeight;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].Ascent = *ascent = gpCurrentFont->nAscent;
            charHashTable[nHashKey].Descent = *descent = gpCurrentFont->nDescent;
        #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
            block_index = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList);
            block_index_next = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList + 1);
            charHashTable[nHashKey].NumChar = NumChar =
                ((block_index_next << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList + 1])
                - ((block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList]);
            #ifdef __MMI_FONT_GROUP_COMPRESSION__
            offset = (block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList];
            mmi_fe_get_group_info(gpCurrentFont->pGroupDetails, offset, &encode_size, &encode_offset, &decode_size, &decode_offset);
            if(decode_size != prev_decode_size || decode_offset != prev_decode_offset)
                mmi_fe_lzma_uncompress(gFontGroupCompressionBuf, &encode_size, gpCurrentFont->pDataArray + decode_offset, &decode_size);
            charHashTable[nHashKey].CharData = *ppCharData = &gFontGroupCompressionBuf[offset-encode_offset];
            if(block_index_next == (U16)(-1))
            {
                charHashTable[nHashKey].NumChar = NumChar =
                    gpCurrentFont->pGroupDetails->pGroupData[gpCurrentFont->pGroupDetails->nNoOfGroup-1].nOffset
                    - ((block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList]);
            }
            prev_decode_size = decode_size;
            prev_decode_offset = decode_offset;
            key = (mmi_fe_bf_cache_key *)(&charHashTable[nHashKey]);
            info = (mmi_fe_bf_cache_info *)((U8 *)&charHashTable[nHashKey] + sizeof(mmi_fe_bf_cache_key));
            #else
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + (block_index << FE_DATA_OFFSET_BIT_SIZE) +
                 gpCurrentFont->pOffsetArray[nIndexInList]);
            #endif
        #else /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
            charHashTable[nHashKey].NumChar = NumChar =
                (gpCurrentFont->pOffsetArray[nIndexInList + 1] - gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + gpCurrentFont->pOffsetArray[nIndexInList]);
        #endif /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 

            charHashTable[nHashKey].DWidth = *pnWidth;
            *advance_x = *pnWidth;
        }
    }
#else /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 
    else
    {
        /*
         * #if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
         * index = SearchInZiExtraFont(Ch, &nBase);
         * if (index != -1)
         * {
         * charHashTable[nHashKey].Height = *pnHeight = gZiExtraCharacter.nHeight;
         * nIndexInList = index + (Ch - nBase);
         * charHashTable[nHashKey].Width = *pnWidth = gZiExtraCharacter.pWidthArray[nIndexInList];
         * charHashTable[nHashKey].Ascent = *ascent = gZiExtraCharacter.nAscent;
         * charHashTable[nHashKey].Descent = *descent = gZiExtraCharacter.nDescent;
         * charHashTable[nHashKey].NumChar = NumChar =
         * (gZiExtraCharacter.pOffsetArray[nIndexInList + 1] - gZiExtraCharacter.pOffsetArray[nIndexInList]);
         * charHashTable[nHashKey].CharData = *ppCharData =
         * (gZiExtraCharacter.pDataArray + gZiExtraCharacter.pOffsetArray[nIndexInList]);
         * charHashTable[nHashKey].DWidth = *pnWidth;
         * *advance_x = *pnWidth;
         * 
         * }
         * else
         * #endif
         */
        {
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
                /* ch is junk */
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_INVALID_CHARACTER, Ch);
                Ch = 65515; /* 0x4E01;//0x000F; */
                *valid = MMI_FALSE;
                index = SearchInPropFont(Ch, &nBase);
                if (index == -1)
                {
                #ifdef __MMI_INDIC_ALG__
                    gpCurrentFont = CurrentFont;
                #endif 
                    *advance_x = 0;
                    *pnWidth = 0;
                    *glyph_height = 0;
                    *glyph_width = 0;
                    *ascent = 0;
                    *descent = 0;
                    return NumChar;
                }
            }
            charHashTable[nHashKey].Height = *pnHeight = gMTKProprietaryFont_small.nHeight;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gMTKProprietaryFont_small.pWidthArray[nIndexInList];
            charHashTable[nHashKey].Ascent = *ascent = gMTKProprietaryFont_small.nAscent;
            charHashTable[nHashKey].Descent = *descent = gMTKProprietaryFont_small.nDescent;
        #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
            block_index = mmi_fe_get_block_index(gMTKProprietaryFont_small.pRange, nIndexInList);
            block_index_next = mmi_fe_get_block_index(gMTKProprietaryFont_small.pRange, nIndexInList + 1);
            charHashTable[nHashKey].NumChar = NumChar =
                ((block_index_next << FE_DATA_OFFSET_BIT_SIZE) +
                 gMTKProprietaryFont_small.pOffsetArray[nIndexInList + 1]) - ((block_index << FE_DATA_OFFSET_BIT_SIZE) +
                                                                              gMTKProprietaryFont_small.
                                                                              pOffsetArray[nIndexInList]);
            #ifdef __MMI_FONT_GROUP_COMPRESSION__
            offset = (block_index << FE_DATA_OFFSET_BIT_SIZE) + gMTKProprietaryFont_small.pOffsetArray[nIndexInList];
            mmi_fe_get_group_info(gMTKProprietaryFont_small.pGroupDetails, offset, &encode_size, &encode_offset, &decode_size, &decode_offset);
            if(decode_size != prev_decode_size || decode_offset != prev_decode_offset)
                mmi_fe_lzma_uncompress(gFontGroupCompressionBuf, &encode_size, gMTKProprietaryFont_small.pDataArray + decode_offset, &decode_size);
            charHashTable[nHashKey].CharData = *ppCharData = &gFontGroupCompressionBuf[offset-encode_offset];
            if(block_index_next == (U16)(-1))
            {
                charHashTable[nHashKey].NumChar = NumChar =
                    gpCurrentFont->pGroupDetails->pGroupData[gpCurrentFont->pGroupDetails->nNoOfGroup-1].nOffset
                    - ((block_index << FE_DATA_OFFSET_BIT_SIZE) + gpCurrentFont->pOffsetArray[nIndexInList]);
            }
            prev_decode_size = decode_size;
            prev_decode_offset = decode_offset;
            key = (mmi_fe_bf_cache_key *)(&charHashTable[nHashKey]);
            info = (mmi_fe_bf_cache_info *)((U8 *)&charHashTable[nHashKey] + sizeof(mmi_fe_bf_cache_key));
            #else
            charHashTable[nHashKey].CharData = *ppCharData =
                (gMTKProprietaryFont_small.pDataArray + (block_index << FE_DATA_OFFSET_BIT_SIZE) +
                 gMTKProprietaryFont_small.pOffsetArray[nIndexInList]);
            #endif
        #else /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
            charHashTable[nHashKey].NumChar = NumChar =
                (gMTKProprietaryFont_small.pOffsetArray[nIndexInList + 1] -
                 gMTKProprietaryFont_small.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gMTKProprietaryFont_small.pDataArray + gMTKProprietaryFont_small.pOffsetArray[nIndexInList]);

        #endif /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
            charHashTable[nHashKey].DWidth = *pnWidth;
            *advance_x = *pnWidth;

        }

    }
#endif /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 

#ifdef __MMI_INDIC_ALG__
    gpCurrentFont = CurrentFont;
#endif 
    /* usually the character width = data width */
    *glyph_height = *pnHeight;
    *glyph_width = *pnWidth;
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD))   /* && */
        //      gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
        //     !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {

    }
    else
    {
        /* when bold word, character width is one more than data width */
        *pnWidth = *pnWidth + 1;
        *advance_x = *advance_x + 1;
    }
    #ifdef __MMI_FONT_GROUP_COMPRESSION__
    mmi_fe_bf_cache_tree_save_info(key, info, sizeof(mmi_fe_bf_cache_info));
    #endif
    return NumChar;
}

#if defined(__MMI_VECTOR_FONT_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_active_font
 * DESCRIPTION
 *  To set font active font to the file which the specified ch belong to
 *  the value 0xf present that the file index of the specified ch is unkonw.
 *  Then we would start a loop to find out the index.
 * PARAMETERS
 *  ch                  [IN]        
 *  private_first       [IN]        
 *  U16 the specified character(?)
 * RETURNS
 *  MMI_BOOL to indicate if the ch belong to private font
 *****************************************************************************/
__inline static S32 mmi_fe_set_active_font(U16 ch, MMI_BOOL private_first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data_attr;
    U8 *pCharData;
    U16 glyph_width, glyph_height;
    S32 advance_x, advance_y, bearing_y, bearing_x, glyph_size;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0, rsb_delta = 0; 
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    MMI_BOOL valid;
    //BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (private_first)
    {
        /* set to the last one */
        mmi_fe_vector_change_active(
            g_mmi_fe_private_font_file_list[g_mmi_fe_private_font_family],
            g_mmi_fe_font_file_number[g_mmi_fe_private_font_family] - 1);
        /* check the validness */
    #if defined(__MTK_TARGET__)
        #if defined(__MMI_VECTOR_FONT_KERNING__)
        /* ret = */ INT_SwitchStackToRun(
                g_mmi_fe_stack,
                MMI_FE_STACK_SIZE,
                (kal_func_ptr) font_engine->get_font_data,
                14,
                MMI_FE_VALID_CHECK,
                ch,
                &pCharData,
                &glyph_size,
                &data_attr,
                &glyph_width,
                &glyph_height,
                &bearing_x,
                &bearing_y,
                &advance_x,
                &advance_y,
                &lsb_delta, 
                &rsb_delta,
                &valid);
        #else /* __MMI_VECTOR_FONT_KERNING__ */
        /* ret = */ INT_SwitchStackToRun(
                g_mmi_fe_stack,
                MMI_FE_STACK_SIZE,
                (kal_func_ptr) font_engine->get_font_data,
                12,
                MMI_FE_VALID_CHECK,
                ch,
                &pCharData,
                &glyph_size,
                &data_attr,
                &glyph_width,
                &glyph_height,
                &bearing_x,
                &bearing_y,
                &advance_x,
                &advance_y,
                &valid);
        #endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    #else /* defined(__MTK_TARGET__) */ 
#if defined(__MMI_VECTOR_FONT_KERNING__)
        /* ret = */ font_engine->get_font_data(
                            MMI_FE_VALID_CHECK,
                            ch,
                            &pCharData,
                            &glyph_size,
                            &data_attr,
                            &glyph_width,
                            &glyph_height,
                            &bearing_x,
                            &bearing_y,
                            &advance_x,
                            &advance_y,
                            &lsb_delta, 
                            &rsb_delta,
                            &valid);
#else
        /* ret = */ font_engine->get_font_data( 
                                            MMI_FE_VALID_CHECK,
                                            ch,
                                            &pCharData,
                                            &glyph_size,
                                            &data_attr,
                                            &glyph_width,
                                            &glyph_height,
                                            &bearing_x,
                                            &bearing_y,
                                            &advance_x,
                                            &advance_y, 
                                            &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    #endif /* defined(__MTK_TARGET__) */ 
        if (valid)
        {
            g_mmi_fe_curr_available_font_family = -1;
            return -1;  /* -1 means finded char in private list */
        }
    }

    {
        S32 i = 0;
        S32 family_index = g_mmi_fe_font_family;
        S32 find_from_begin = 0;
        U16 *curr_font_list = g_mmi_fe_curr_font_list;
        U32 count;
        #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        U16 resid_buf[FE_MAX_FONT_FILE_NUMBER] = {0};
        U8 resid_cnt = FE_MAX_FONT_FILE_NUMBER;
        #endif

        while(family_index < FE_MAX_FONT_FAMILY_NUMBER)
        {
        #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
            font_engine->get_font_res_id(ch, resid_buf, &resid_cnt);
            {
                S32 j;
                for(j=0;j<FE_MAX_FONT_FILE_NUMBER;j++)
                {
                    if (curr_font_list[j] >= IMG_GLOBAL_FONT_1 && curr_font_list[j] <= IMG_GLOBAL_FONT_MAX)
                        resid_buf[resid_cnt++] = curr_font_list[j];
                }
                curr_font_list = resid_buf;
                count = resid_cnt;
            }
        #else
            {
                curr_font_list = g_mmi_fe_curr_font_list;
                count = g_mmi_fe_font_file_number[family_index];
            }
        #endif
                
            for (i = 0; i < count; i++)
            {
                //U8 file = (i & 0xf);

                mmi_fe_vector_change_active(curr_font_list[i], i);
            #if defined(__MTK_TARGET__)
                    #if defined(__MMI_VECTOR_FONT_KERNING__)
                /* ret = */ INT_SwitchStackToRun(
                        g_mmi_fe_stack,
                        MMI_FE_STACK_SIZE,
                        (kal_func_ptr) font_engine->get_font_data,
                            14,
                        MMI_FE_VALID_CHECK,
                        ch,
                        &pCharData,
                        &glyph_size,
                        &data_attr,
                        &glyph_width,
                        &glyph_height,
                        &bearing_x,
                        &bearing_y,
                        &advance_x,
                        &advance_y,
                        &lsb_delta, 
                        &rsb_delta,
                        &valid);
                    #else /* __MMI_VECTOR_FONT_KERNING__ */
                /* ret = */ INT_SwitchStackToRun(
                        g_mmi_fe_stack,
                        MMI_FE_STACK_SIZE,
                        (kal_func_ptr) font_engine->get_font_data,
                        12,
                        MMI_FE_VALID_CHECK,
                        ch,
                        &pCharData,
                        &glyph_size,
                        &data_attr,
                        &glyph_width,
                        &glyph_height,
                        &bearing_x,
                        &bearing_y,
                        &advance_x,
                        &advance_y,
                        &valid);
                #endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            #else /* defined(__MTK_TARGET__) */ 
#if defined(__MMI_VECTOR_FONT_KERNING__)
                /* ret = */ font_engine->get_font_data(
                                    MMI_FE_VALID_CHECK,
                                    ch,
                                    &pCharData,
                                    &glyph_size,
                                    &data_attr,
                                    &glyph_width,
                                    &glyph_height,
                                    &bearing_x,
                                    &bearing_y,
                                    &advance_x,
                                    &advance_y,
                                    &lsb_delta, 
                                    &rsb_delta,
                                    &valid);
#else
                /* ret = */ font_engine->get_font_data( 
                                                    MMI_FE_VALID_CHECK,
                                                    ch,
                                                    &pCharData,
                                                    &glyph_size,
                                                    &data_attr,
                                                    &glyph_width,
                                                    &glyph_height,
                                                    &bearing_x,
                                                    &bearing_y,
                                                    &advance_x,
                                                    &advance_y, 
                                                    &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            #endif /* defined(__MTK_TARGET__) */ 
                if (valid)
                {
                #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
                    U16 temp_font_res_id = curr_font_list[i];
                    curr_font_list[i] = curr_font_list[0];
                    curr_font_list[0] = temp_font_res_id;
                #endif

                #if 0//def __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
                    g_mmi_fe_curr_available_font_family = family_index;
                    return family_index;  /* Return family index */
                }
            }
            
            /* Not found in current family. so, Find char from family index == 0 */
            if(find_from_begin == 0)
            {
                family_index = (family_index == 0) ? 1: 0;
                curr_font_list = g_mmi_fe_font_file_list[family_index];
                find_from_begin = 1;
            }
            else
            {
                family_index++;
                family_index = (family_index == g_mmi_fe_font_family) ? family_index++ : family_index;
                curr_font_list = g_mmi_fe_font_file_list[family_index];
            }
        }

       
        MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_INVALID_CHARACTER, ch);

        mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[0], 0);
    }
    return -2; /* -2 means not find in all TTF. */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_shaper
 * DESCRIPTION
 *  To do open type shaping
 * PARAMETERS
 *  lang            [IN]        
 *  text            [IN]        
 *  text_len        [IN]        
 *  start_index     [IN]        
 *  run_len         [IN]        
 *  text_info       [?]         
 * RETURNS
 *  S32 the length of the display buffer
 *****************************************************************************/
S32 mmi_fe_shaper(
        mmi_lm_lang_enum lang,
        UI_string_type text,
        S32 text_len,
        S32 start_index,
        S32 run_len,
        mmi_fe_text_info_p *text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
    S32 i = 0;
    //mmi_fe_cache_key_struct key;
    mmi_fe_cluster_info fe_cluster;
    S32 glyph_len = 0;
    S32 pool_usage = 0; /* pool usage in byte */
    mmi_fe_text_info_p text_p = NULL;
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth, ascent, descent;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0, rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height;
    S32 bearing_x;
    MMI_BOOL valid;
    MMI_BOOL private_first = MMI_FALSE;
    S32 private_font = MMI_FALSE;
    U32 temp_font_attr = font_engine_font_attr;
    MMI_BOOL font_set = MMI_FALSE;
    S32 loop = 0;
    mmi_fe_text_info_p nc_text_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    font_engine_error_code = MMI_FE_FONT_ERR_NONE;
    FE_SWLA_START("SAP");
    do
    {
      REGET:
        {
            switch (lang)
            {
            #if defined(__MMI_LANG_THAI__)
                case MMI_LM_LANG_THAI:
                    ot_lang = MMI_FE_OT_LANG_THAI;
                    ot_script = MMI_FE_OT_SCRIPT_THAI;
                    break;
            #endif
            #if defined(__MMI_INDIC_ALG__)
                case MMI_LM_LANG_INDIC:
                {
                    for (i = 0; i < text_len; i++)
                    {
                        switch (text[i])
                        {
                            case 0x09e4:    /* Bengali */
                            case 0x0a64:    /* Punjabi */
                            case 0x0ae4:    /* Gujarati */
                            case 0x0b64:    /* Oriya */
                            case 0x0be4:    /* Tamil */
                            case 0x0c64:    /* Telugu */
                            case 0x0ce4:    /* Kannada */
                            case 0x0d64:    /* Malayalam */
                                text[i] = 0x0964;
                                break;
                            case 0x09e5:    /* Bengali */
                            case 0x0a65:    /* Punjabi */
                            case 0x0ae5:    /* Gujarati */
                            case 0x0b65:    /* Oriya */
                            case 0x0be5:    /* Tamil */
                            case 0x0c65:    /* Telugu */
                            case 0x0ce5:    /* Kannada */
                            case 0x0d65:    /* Malayalam */
                                text[i] = 0x0965;
                                break;

                        }
                    }
                    switch (ire_get_character_lang_id(text[0]))
                    {
                            /* /TODO: check character lang by enum, and add for marathi or hindi by current language. */
                        case 0x01:  /* IRE_LANGUAGE_ID_HINDI */
                            /* set Hindi as first priority */
                        {
                            U8 *lcc = Get_Current_Lang_CountryCode();

                            if (memcmp(lcc, "mr-IN", 5) == 0)
                            {
                                ot_lang = MMI_FE_OT_LANG_MARATHI;
                                ot_script = MMI_FE_OT_SCRIPT_DEVANAGARI;
                            }
                            else
                            {
                                ot_lang = MMI_FE_OT_LANG_HINDI;
                                ot_script = MMI_FE_OT_SCRIPT_DEVANAGARI;
                            }
                        }
                            break;
                            /* /TODO: check character by enum and add for Bengali or Assamese */
                        case 0x02:  /* IRE_LANGUAGE_ID_BENGALI */
                            /* set Bengali as first priority */
                        {
                            U8 *lcc = Get_Current_Lang_CountryCode();

                            if (memcmp(lcc, "as-IN", 5) == 0)
                            {
                                ot_lang = MMI_FE_OT_LANG_ASSAMESE;
                                ot_script = MMI_FE_OT_SCRIPT_BENGALI;
                            }
                            else
                            {
                                ot_lang = MMI_FE_OT_LANG_BENGALI;
                                ot_script = MMI_FE_OT_SCRIPT_BENGALI;
                            }
                        }
                            break;
                        case 0x03:  /* IRE_LANGUAGE_ID_PUNJABI */
                            ot_lang = MMI_FE_OT_LANG_PUNJABI;
                            ot_script = MMI_FE_OT_SCRIPT_GURMUKHI;
                            break;
                        case 0x04:  /* IRE_LANGUAGE_ID_GUJARATI */
                            ot_lang = MMI_FE_OT_LANG_GUJARATI;
                            ot_script = MMI_FE_OT_SCRIPT_GUJARATI;
                            break;
                        case 0x05:  /* IRE_LANGUAGE_ID_ORIYA */
                            ot_lang = MMI_FE_OT_LANG_ORIYA;
                            ot_script = MMI_FE_OT_SCRIPT_ORIYA;
                            break;
                        case 0x06:  /* IRE_LANGUAGE_ID_TAMIL */
                            ot_lang = MMI_FE_OT_LANG_TAMIL;
                            ot_script = MMI_FE_OT_SCRIPT_TAMIL;
                            break;
                        case 0x07:  /* IRE_LANGUAGE_ID_TELUGU */
                            ot_lang = MMI_FE_OT_LANG_TELUGU;
                            ot_script = MMI_FE_OT_SCRIPT_TELUEU;
                            break;
                        case 0x08:  /* IRE_LANGUAGE_ID_KANNADA */
                            ot_lang = MMI_FE_OT_LANG_KANNADA;
                            ot_script = MMI_FE_OT_SCRIPT_KANNADA;
                            break;
                        case 0x09:  /* IRE_LANGUAGE_ID_MALAYALAM */
                            ot_lang = MMI_FE_OT_LANG_MALAYALAM;
                            ot_script = MMI_FE_OT_SCRIPT_MALAYALAM;
                            break;
                        case 0x0E:  /* IRE_LANGUAGE_ID_MYANMAR */
                            ot_lang = MMI_FE_OT_LANG_MYANMAR;
                            ot_script = MMI_FE_OT_SCRIPT_MYANMAR;
                            break;
                        case 0x0C:  /* IRE_LANGUAGE_ID_LAO */
                            ot_lang = MMI_FE_OT_LANG_LAO;
                            ot_script = MMI_FE_OT_SCRIPT_LAO;
                            break;
                    }
                }
                    break;
            #endif /* defined(__MMI_INDIC_ALG__) */ 
                default:
                    if (mmi_fe_test_display_as_null(text[start_index]))
                        return 0;
                    if (mmi_fe_test_display_as_space(text[start_index]))
                    {
                        text = L" ";
                        run_len = 1;
                        start_index = 0;
                    }
                    if (mmi_fe_test_display_as_invalid(text[start_index]))
                    {
                        text = L"\0xFFEB";
                        run_len = 1;
                        start_index = 0;
                    }
                    break;
            }

            /* 
             *  proprietary font should be checked first if
             *  1. the private flag is enable.
             *  2. the character is in private range.
             *  3. there is private font. 
             */
            if (fe_display_flag & FE_DISPLAY_FLAG_UCS2_PROPRIETARY &&
                (text[start_index] >= FE_UCS2_PROPRIETARY_START && text[start_index] <= FE_UCS2_PROPRIETARY_END) &&
                (g_mmi_fe_private_font_file_list[g_mmi_fe_private_font_family] != 0))
            {
                private_first = MMI_TRUE;
                private_font = mmi_fe_set_active_font(text[start_index], private_first);
                if (private_first && (private_font == -1))
                    temp_font_attr |= FE_FONT_ATTR_PRIVATE;
                font_set = MMI_TRUE;
            }

            /* create key */
            mmi_fe_cache_key_maker(
                text + start_index,
                run_len,
                ot_lang,
                temp_font_attr,
                font_engine_font_size,
                ot_script,
                (MMI_BOOL)start_index,
                g_mmi_fe_font_family,
                MMI_FE_CACHE_TYPE_CLUSTER_DATA,
                0,
                0,
                0,
                NULL,
                &mmi_fe_key);

            /* get from cache */
            ret = (MMI_BOOL)mmi_fe_cache_tree_find(&mmi_fe_key, (void**)text_info, &glyph_len);

            /*  Recovery me !!!! I am just test!!!!  */
        //    ret = 0;

            if (ret)
            {
                if(mmi_fe_get_img_cache_mode())
                {
                    text_p = *text_info;
                    for (i = 0; i < glyph_len; i++)
                    {
                        text_p = (mmi_fe_text_info_p)((U32 *)(*text_info) + pool_usage);
                        pool_usage += (sizeof(mmi_fe_glyph_ot_info) +
                                   sizeof(mmi_fe_glyph_info) + FE_FOUR_BYTE_ALIGN(text_p->glyph_data.bitmap_size)) >> 2;
                    }
                    memcpy((U8 *)g_mmi_fe_cluster_data_pool, (U8 *)(*text_info), pool_usage<<2);

                    *text_info = (mmi_fe_text_info_p)g_mmi_fe_cluster_data_pool;
                }
                g_mmi_fe_curr_available_font_family = mmi_fe_key.header.family_index;
                font_engine_error_code = MMI_FE_FONT_ERR_NONE;
                FE_SWLA_STOP("SAP");
                return glyph_len;
            }
            else
            {
                //S32 family_index = 0;
                if (!font_set)
                {
                    /* It seems should use MMI_FALSE to instead of private_first, because if the font is in private list,
                    font_set will prohibit this branch. */
                    /* This branch means the font is not in private list, so search in normal family list. */
                    /* Wating for issue... for example: if App set family == 1, but the font can be find in private list, so 
                    family == 1 is no effect. */
                    /* family_index =*/ mmi_fe_set_active_font(text[start_index], private_first);
                }
                mmi_fe_cluster_info_init(&fe_cluster);
            #if defined(__MTK_TARGET__)
                ret = (MMI_BOOL)INT_SwitchStackToRun(
                        g_mmi_fe_stack,
                        MMI_FE_STACK_SIZE,
                        (kal_func_ptr) font_engine->shaper,
                        7,
                        ot_lang,
                        ot_script,
                        text,
                        text_len,
                        start_index,
                        run_len,
                        &fe_cluster);
            #else /* defined(__MTK_TARGET__) */ 
                font_engine->shaper(ot_lang, ot_script, text, text_len, start_index, run_len, &fe_cluster);
            #endif /* defined(__MTK_TARGET__) */ 

                /* 
                      Because We already called mmi_fe_set_active_font(), so we can pass MMI_FE_GLYPH_INDEX to
                    mmi_fe_get_font_data(). Or mmi_fe_get_font_data() will call mmi_fe_set_active_font internal.
                      MMI_FE_GLYPH_INDEX needs pass glyph_index, not char unicode.
                      It must call mmi_fe_set_active_font() before call font_engine->get_font_data(), because
                    mmi_fe_set_active_font() will return current available family, which is indicated whether it is 
                    monospace.
                */
                /* update */
                for (i = 0; i < fe_cluster.glyph_len; i++)
                {
                    text_p = (mmi_fe_text_info_p) & g_mmi_fe_cluster_data_pool[pool_usage];
                    memcpy(text_p, &fe_cluster.glyph_buf[i], sizeof(mmi_fe_glyph_ot_info));
#if defined(__MMI_VECTOR_FONT_KERNING__)
                    text_p->glyph_data.bitmap_size = (U16)mmi_fe_get_font_data(
                                                                            MMI_FE_GLYPH_INDEX, 
                                                                            fe_cluster.glyph_buf[i].glyph_index, 
                                                                            & pCharData, 
                                                                            &data_attr, 
                                                                            &pnWidth, 
                                                                            &advance_x, 
                                                                            &glyph_width, 
                                                                            &glyph_height, 
                                                                            &bearing_x, 
                                                                            &ascent, 
                                                                            &descent, 
                                                                            &lsb_delta, 
                                                                            &rsb_delta,
                                                                            &valid);
#else
                    text_p->glyph_data.bitmap_size = (U16) mmi_fe_get_font_data(
                                                            MMI_FE_GLYPH_INDEX,
                                                            fe_cluster.glyph_buf[i].glyph_index,
                                                            &pCharData,
                                                            &data_attr,
                                                            &pnWidth,
                                                            &advance_x,
                                                            &glyph_width,
                                                            &glyph_height,
                                                            &bearing_x,
                                                            &ascent,
                                                            &descent,
                                                            &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 

                    /* error happends, redo */
                    if (font_engine_error_code)
                    {
                        if (font_engine_error_code == MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY ||
                            font_engine_error_code == MMI_FE_FONT_ERR_INIT_TIME_OUT)
                        {
                            mmi_fe_vectorfont_engine_error_handler((mmi_fe_error_code)font_engine_error_code);
                            loop++;
                            if (loop == 2)
                                break;
                            goto REGET;
                        }
                        else
                        {
                            /* MMI_FE_FONT_ERR_INVALID_FONT_PATH &  MMI_FE_FONT_ERR_INVALID_FILE_ACCESS don't care. */
                            font_engine_error_code = MMI_FE_FONT_ERR_NONE;
                        }
                    }

                    text_p->glyph_data.advance_x = (kal_int8) advance_x;
                    if((64<*text && *text<91) || (96< *text && *text<123))
                    {
                        if(advance_x<glyph_width)
                             text_p->glyph_data.advance_x = glyph_width;
                    }

                    /* adjust bearing for some special case. such as only thai up vowel in the cluster. */
                    if (i == 0 && bearing_x < 0)
                    {
                        text_p->glyph_data.bearing_x = 0;
                        text_p->glyph_data.advance_x = text_p->glyph_data.advance_x - bearing_x;
                    }
                    else
                    {
                        text_p->glyph_data.bearing_x = (kal_int8) bearing_x;
                    }
                    text_p->glyph_data.bearing_y = (kal_int8) ascent;
                    text_p->glyph_data.height = (kal_int8) glyph_height;
                    
                 //   if(family_index == FONT_FAMILY_FIXED_WIDTH)
                    {
                    //    text_p->glyph_data.width = (kal_int8) advance_x;
                    }
                //    else
                    {
                        text_p->glyph_data.width = (kal_int8) glyph_width;
                    }
#if defined(__MMI_VECTOR_FONT_KERNING__)
                     text_p->posdata.lsb_delta = (kal_int32)lsb_delta;
                     text_p->posdata.rsb_delta = (kal_int32)rsb_delta;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 

                    if (pool_usage + (text_p->glyph_data.bitmap_size >> 2) < MMI_FE_CLUSTER_POOL_SIZE)
                    {
                        memcpy(&text_p->glyph_data.bitmap, pCharData, text_p->glyph_data.bitmap_size);
                    }
                    else
                    {
                        /* /TODO: process later */
                        MMI_ASSERT(0);
                    }

                    pool_usage += (sizeof(mmi_fe_glyph_ot_info) +
                                   sizeof(mmi_fe_glyph_info) + FE_FOUR_BYTE_ALIGN(text_p->glyph_data.bitmap_size)) >> 2;
                }

                /* save into cache */

                mmi_fe_cache_tree_save_cluster_data(
                    &mmi_fe_key,
                    fe_cluster.glyph_len,
                    (mmi_fe_text_info_p)g_mmi_fe_cluster_data_pool,
                    pool_usage << 2,
                    &nc_text_info);

                if(mmi_fe_get_img_cache_mode() || nc_text_info == NULL)
                    *text_info = (mmi_fe_text_info_p)g_mmi_fe_cluster_data_pool;
                else
                    *text_info = nc_text_info;
            }
            FE_SWLA_STOP("SAP");
            return fe_cluster.glyph_len;
        }
    } while (loop < 2);

    //MMI_ASSERT(0);
}
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_data
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  type                [IN]        
 *  ch                  [IN]        
 *  ppCharData          [OUT]       
 *  data_attr           [?]         
 *  pnWidth             [OUT]       
 *  advance_x           [OUT]       
 *  glyph_width         [OUT]       
 *  glyph_height        [OUT]       
 *  bearing_x           [?]         
 *  ascent              [?]         
 *  descent             [?]         
 *  valid               [?]         
 *  pnHeight(?)         [OUT]       
 *  Font(?)             [IN]        
 *  Ch(?)               [IN]        
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
#if defined(__MMI_VECTOR_FONT_KERNING__)
__inline static U32 mmi_fe_get_font_data(
                            U8 type,
                            U16 ch, 
                            U8 **ppCharData, 
                            U32 *data_attr,
                            S32 *pnWidth, 
                            S32 *advance_x, 
                            U16 *glyph_width, 
                            U16 *glyph_height, 
                            S32 *bearing_x,
                            S32 *ascent, 
                            S32 *descent,
                            S32 *lsb_delta, 
                            S32 *rsb_delta,
                            MMI_BOOL *valid)
#else
__inline static U32 mmi_fe_get_font_data(
                        U8 type,
                        U16 ch,
                        U8 **ppCharData,
                        U32 *data_attr,
                        S32 *pnWidth,
                        S32 *advance_x,
                        U16 *glyph_width,
                        U16 *glyph_height,
                        S32 *bearing_x,
                        S32 *ascent,
                        S32 *descent,
                        MMI_BOOL *valid)
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 dummy_pnHeight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GFD");
    *valid = MMI_TRUE;

    if (type != MMI_FE_GLYPH_INDEX)
    {
        if (mmi_fe_test_display_as_null((U32) ch))
        {
            *ascent = 0;
            *descent = 0;
            *pnWidth = 0;
            *advance_x = 0;
            *glyph_height = 0;
            *glyph_width = 0;
            *data_attr = 0;
#if defined(__MMI_VECTOR_FONT_KERNING__)
            *lsb_delta = 0;
            *rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            return 0;
        }
        if (mmi_fe_test_display_as_space(ch))
        {
            ch = 0x20;
        }
        if (mmi_fe_test_display_as_invalid(ch))
        {
            ch = 0xFFEB;
        }
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        switch (ch)
        {
            case 0x09e4:    /* Bengali */
            case 0x0a64:    /* Punjabi */
            case 0x0ae4:    /* Gujarati */
            case 0x0b64:    /* Oriya */
            case 0x0be4:    /* Tamil */
            case 0x0c64:    /* Telugu */
            case 0x0ce4:    /* Kannada */
            case 0x0d64:    /* Malayalam */
                ch = 0x0964;
                break;
            case 0x09e5:    /* Bengali */
            case 0x0a65:    /* Punjabi */
            case 0x0ae5:    /* Gujarati */
            case 0x0b65:    /* Oriya */
            case 0x0be5:    /* Tamil */
            case 0x0c65:    /* Telugu */
            case 0x0ce5:    /* Kannada */
            case 0x0d65:    /* Malayalam */
                ch = 0x0965;
                break;
        }
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    }
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        U32 glyph_size = 0;
        MMI_BOOL ret = MMI_FALSE;
        S32 bearing_y, advance_y;
        //MMI_BOOL private_first = MMI_FALSE;
        //S32 family_index = 0;

        /* 
         *  proprietary font should be checked first if
         *  1. the private flag is enable.
         *  2. the character is in private range.
         *  3. there is private font. 
         */
/*
        if (fe_display_flag & FE_DISPLAY_FLAG_UCS2_PROPRIETARY &&
            (ch >= FE_UCS2_PROPRIETARY_START && ch <= FE_UCS2_PROPRIETARY_END) &&
            (g_mmi_fe_private_font_file_list[g_mmi_fe_private_font_family] != 0))
        {
            private_first = MMI_TRUE;
        }
*/
        //if (type != MMI_FE_GLYPH_INDEX)
            //family_index = mmi_fe_set_active_font(ch, private_first);

    #if defined(__MTK_TARGET__)
#if defined(__MMI_VECTOR_FONT_KERNING__)
        ret = (MMI_BOOL)INT_SwitchStackToRun(
                    g_mmi_fe_stack, 
                    MMI_FE_STACK_SIZE, 
                    (kal_func_ptr)font_engine->get_font_data, 
                        14,
                    type,
                    ch,
                    ppCharData,
                    &glyph_size,
                    data_attr,
                    glyph_width,
                    glyph_height,
                    bearing_x,
                    &bearing_y,
                    advance_x,
                    &advance_y, 
                    lsb_delta, 
                    rsb_delta,
                    valid);
#else
        ret = (MMI_BOOL)INT_SwitchStackToRun(
                g_mmi_fe_stack,
                MMI_FE_STACK_SIZE,
                (kal_func_ptr) font_engine->get_font_data,
                12,
                type,
                ch,
                ppCharData,
                &glyph_size,
                data_attr,
                glyph_width,
                glyph_height,
                bearing_x,
                &bearing_y,
                advance_x,
                &advance_y,
                valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    #else /* defined(__MTK_TARGET__) */ 
#if defined(__MMI_VECTOR_FONT_KERNING__)
        ret = (MMI_BOOL)font_engine->get_font_data(
                            type,
                            ch,
                            ppCharData,
                            &glyph_size,
                            data_attr,
                            glyph_width,
                            glyph_height,
                            bearing_x,
                            &bearing_y,
                            advance_x,
                            &advance_y,
                                            lsb_delta, 
                                            rsb_delta,
                            valid);
#else
        ret = (MMI_BOOL)font_engine->get_font_data( 
                                            type,
                                            ch,
                                            ppCharData,
                                            &glyph_size,
                                            data_attr,
                                            glyph_width,
                                            glyph_height,
                                            bearing_x,
                                            &bearing_y,
                                            advance_x,
                                            &advance_y, 
                                            valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    #endif /* defined(__MTK_TARGET__) */ 
        if (ret)
        {
            *pnWidth = (*bearing_x > 0 ? *bearing_x : 0) + *glyph_width;
            *ascent = bearing_y;
            *descent = *glyph_height - bearing_y;
            
            //if(family_index == FONT_FAMILY_FIXED_WIDTH)
            //{
             //   *glyph_width = (U16)(*advance_x);
            //}
            FE_SWLA_STOP("GFD");
            return glyph_size;
        }
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    *data_attr = 0; /* don't assign any data attribute */
    *bearing_x = 0;
    /* for bdf font, it is ok to save data into cache in the two case. */
    return mmi_fe_get_font_data_internal(
            ch,
            type,
            ppCharData,
            pnWidth,
            advance_x,
            &dummy_pnHeight,
            glyph_width,
            glyph_height,
            ascent,
            descent,
            valid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_attr          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 *  Bordered            [IN]        
 *  font_attr           [IN]        
 *  text_color          [IN]        
 *  border_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_show_font_data(
                        U16 ch,
                        S32 x,
                        S32 y,
                        U8 *glyph_ptr,
                        U32 glyph_size,
                        U32 glyph_attr,
                        U16 glyph_width,
                        U16 glyph_height,
                        U32 Bordered,
                        U8 font_attr,
                        gdi_color text_color,
                        gdi_color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BDF_SW_COMPRESSION__
    gdi_layer_struct *handle_layer;
    int color_format;
    kal_int32 canvasPitch;
    BFC_RGB_FORMAT_ENUM canvasFormat;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BDF_SW_COMPRESSION__

    gdi_layer_get_active((gdi_handle*) & handle_layer);
    color_format = gdi_get_color_format(gdi_bits_per_pixel(handle_layer->cf));

    /* color_format = gdi_lcd_get_bits_per_pixel(); */
    switch(color_format)
    {
        case GDI_COLOR_FORMAT_16:
                canvasPitch = handle_layer->width * 2;
                canvasFormat = BFC_RGB_FORMAT_RGB565;
            break;

        case GDI_COLOR_FORMAT_24:
                canvasPitch = handle_layer->width * 3;
                canvasFormat = BFC_RGB_FORMAT_RGB888;
            break;

        case GDI_COLOR_FORMAT_32_PARGB:
        case GDI_COLOR_FORMAT_32:
                canvasPitch = handle_layer->width * 4;
                canvasFormat = BFC_RGB_FORMAT_PARGB8888;
            break;

        default:
                canvasPitch = handle_layer->width * 2;
                canvasFormat = BFC_RGB_FORMAT_RGB565;
    }
    bfcDecSetCanvas(
                g_decoder,
                handle_layer->buf_ptr,
                handle_layer->width,
                canvasPitch,
                handle_layer->height,
                canvasFormat);
    /*if (color_format == GDI_COLOR_FORMAT_16)
    {
        bfcDecSetCanvas(
            g_decoder,
            handle_layer->buf_ptr,
            handle_layer->width,
            handle_layer->width * 2,
            handle_layer->height,
            BFC_RGB_FORMAT_RGB565);
    }
    else if (color_format == GDI_COLOR_FORMAT_24)
    {
        bfcDecSetCanvas(
            g_decoder,
            handle_layer->buf_ptr,
            handle_layer->width,
            handle_layer->width * 3,
            handle_layer->height,
            BFC_RGB_FORMAT_RGB888);
    }
    else if (color_format == GDI_COLOR_FORMAT_32_PARGB)
    {
        bfcDecSetCanvas(
            g_decoder,
            handle_layer->buf_ptr,
            handle_layer->width,
            handle_layer->width * 4,
            handle_layer->height,
            BFC_RGB_FORMAT_PARGB8888);
    }
    else if (color_format == GDI_COLOR_FORMAT_32)
    {
        bfcDecSetCanvas(
            g_decoder,
            handle_layer->buf_ptr,
            handle_layer->width,
            handle_layer->width * 4,
            handle_layer->height,
            BFC_RGB_FORMAT_ARGB8888);
    }
    else
    {
        bfcDecSetCanvas(
            g_decoder,
            handle_layer->buf_ptr,
            handle_layer->width,
            handle_layer->width * 2,
            handle_layer->height,
            BFC_RGB_FORMAT_RGB565);
    }*/

    bfcDecSetClipWindow(
        g_decoder,
        handle_layer->clipx1,
        handle_layer->clipy1,
        handle_layer->clipx2 - handle_layer->clipx1 + 1,
        handle_layer->clipy2 - handle_layer->clipy1 + 1);

#endif /* __MMI_BDF_SW_COMPRESSION__ */ 

#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_FONT_EFFECTS__)
    if (glyph_attr & FE_GLYPH_ATTR_USING_FONT_ENGINE)
    {
        switch (gFontEffect)
        {
            case FONT_EFFECT_DROP_SHADOW:
            {
                mmi_fe_show_font_data_drop_shadow(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_OUTER_GLOW:
            {
                mmi_fe_show_font_data_outer_glow(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_ENHANCED_ENGRAVE:
            {
                mmi_fe_show_font_data_engrave(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_GRADIENT:
            {
                mmi_fe_show_font_data_gradient(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_BORDER:
            {
                mmi_fe_show_font_data_border(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_GRADIENT_DROP_SHADOW:
            {
                mmi_fe_show_font_data_gradient_drop_shadow(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
            {
                mmi_fe_show_font_data_gradient_engrave(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height);
                break;
            }
            default:
            {
                FE_SWLA_START("SFD");
                font_engine->show_font_data(
                                ch,
                                x,
                                y,
                                glyph_ptr,
                                glyph_size,
                                glyph_attr,
                                glyph_width,
                                glyph_height,
                                Bordered);
                FE_SWLA_STOP("SFD");
            }
        }
        return;
    }
    
#else /* defined(__MMI_FONT_EFFECTS__) */ 
    if (glyph_attr & FE_GLYPH_ATTR_USING_FONT_ENGINE)
    {
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, glyph_attr, glyph_width, glyph_height, Bordered);
        FE_SWLA_STOP("SFD");
        return;
    }

#endif /* defined(__MMI_FONT_EFFECTS__) */ 
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    if (Bordered == 1 || Bordered == 2)
    {
    #ifndef __MMI_BDF_SW_COMPRESSION__
        gdi_show_char_bordered(
            x,
            y,
            text_color,
            border_color,
            glyph_ptr,
            glyph_size,
            glyph_width,
            glyph_height,
            font_attr,
            MMI_FALSE);
    #else /* __MMI_BDF_SW_COMPRESSION__ */ 
        bfcDecDrawGlyph(g_decoder, glyph_ptr, glyph_width, glyph_height, x, y);
    #endif /* __MMI_BDF_SW_COMPRESSION__ */ 
    }
    else if ((!(gnCurrentFontAttrib & FONTATTRIB_BOLD)) || Bordered == 3)
    {
    #ifdef __MMI_BDF_SW_COMPRESSION__
        bfcDecDrawGlyph(g_decoder, glyph_ptr, glyph_width, glyph_height, x, y);
    #else 
        gdi_show_char(x, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr, MMI_FALSE);
    #endif 
    }
    else
    {
    #ifdef __MMI_BDF_SW_COMPRESSION__
        // Dont need to draw twice for bold style
        //bfcDecDrawGlyph(&g_decoder, glyph_ptr, glyph_width, glyph_height, x + 1 , y);
        bfcDecDrawGlyph(g_decoder, glyph_ptr, glyph_width, glyph_height, x, y);
    #else /* __MMI_BDF_SW_COMPRESSION__ */ 
        gdi_show_char(x + 1, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr, MMI_FALSE);
        gdi_show_char(x, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr, MMI_FALSE);
    #endif /* __MMI_BDF_SW_COMPRESSION__ */ 
    }
}

#if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_block_index
 * DESCRIPTION
 *  To Get block index of  compress data.
 * PARAMETERS
 *  rangeOffset     [?]         
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_fe_get_block_index(mmi_font_range_offset_struct *rangeOffset, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < rangeOffset->num_of_block; i++)
    {
        if (index < (rangeOffset->block_index_array)[i])
        {
            return i;
        }
    }

    return -1;
}
#endif /* defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__) */ 
#endif /* #ifndef __MMI_SCRIPT_EASY__ */

#ifdef __MMI_FONT_GROUP_COMPRESSION__
static void mmi_fe_get_group_info(const GroupDetails* groupDetails, U32 offset, U32* encode_size, U32* encode_offset, U32* decode_size, U32* decode_offset)
{
    S32 i;
    *encode_size = 0;
    *encode_offset= 0;
    *decode_size = 0;
    *decode_offset= 0;

    for(i = 0; i < (groupDetails->nNoOfGroup-1); i++)
    {
        if(offset >= groupDetails->pGroupData[i+1].nOffset)
            *decode_offset += groupDetails->pGroupData[i].nSize;
        else
            break;
    }

    if(i >= (groupDetails->nNoOfGroup-1))
        ASSERT(0);

    *encode_size = groupDetails->pGroupData[i+1].nOffset - groupDetails->pGroupData[i].nOffset;
    *encode_offset = groupDetails->pGroupData[i].nOffset;
    *decode_size = groupDetails->pGroupData[i].nSize - 5;
    
    return;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  GetLangIndex
 * DESCRIPTION
 *  To get the language index of the character.
 * PARAMETERS
 *  pCount          [OUT]       The langugae Index
 *  pnFontIndex     [OUT]       
 *  pnIndex         [OUT]       The offset of the character in the array
 *  nCh             [IN]        The character to look for
 *  pnBase          [OUT]       Base of Character set
 * RETURNS
 *  void
 *****************************************************************************/
static void GetLangIndex(U8 *pCount, S32 *pnFontIndex, S32 *pnIndex, U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* first check the index in the current language. 90% of the cases strings will be from current language */
    U16 nFontCount = 0;
    //sFontFamily *pFontFamily = NULL;
    const font_group_struct *font_group = &(gfontfamily[gnCurrentFont]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pCount = 0;

    nFontCount = 0;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
 //   if (pFontFamily != NULL)
#endif 
    {

        while (nFontCount < font_group->nTotalFonts)
        {

            if (nCh >= font_group->fontData[nFontCount]->pRangeDetails->pRangeData[0].nMin &&
                nCh <=
                font_group->fontData[nFontCount]->pRangeDetails->pRangeData[font_group->fontData[nFontCount]->
                                                                            pRangeDetails->nNoOfRanges - 1].nMax)
            {
                /* pnIndex is index of range block, pnBase is index of character which is start of range block */
                *pnIndex = SearchIndexinList(*pCount, nFontCount, nCh, pnBase);
                if (*pnIndex == -1)
                {
                    ++nFontCount;
                }
                else
                {
                    gpCurrentFont = font_group->fontData[nFontCount];
                    *pnFontIndex = nFontCount;
                    return;
                }

            }   /* if(nCh>=pFontFamily->fontData[nFontCount].pRangeData[0].nMin && */
            else
            {
                ++nFontCount;
            }
        }   /* while(nFontCount < pFontFamily->nTotalFonts) */
    }

    if (*pnIndex == -1)
    {
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SearchIndexinList
 * DESCRIPTION
 *  To search index and base of the character in a language.
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nListIndex      [IN]        
 *  nFontCount      [IN]        
 *  nCh             [IN]        
 *  pnBase          [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
static S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = gfontfamily[gnCurrentFont].fontData[nFontCount]->pRangeDetails->nNoOfRanges - 1;
    const RangeData *pRangeData = gfontfamily[gnCurrentFont].fontData[nFontCount]->pRangeDetails->pRangeData;

#if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
    const U16 *pRange = gfontfamily[gnCurrentFont].fontData[nFontCount]->pRange->rangeOffset;
#else 
    U16 *pRange = gfontfamily[gnCurrentFont].fontData[nFontCount]->pRange;
#endif 
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;
        if ((nCh >= pRangeData[nMid].nMin) && (nCh <= pRangeData[nMid].nMax))
        {
            *pnBase = pRangeData[nMid].nMin;
            return pRange[nMid];

        }
        if (nCh > pRangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}

#if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
/* under construction !*/
        #else 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  SearchInPropFont
 * DESCRIPTION
 *  To search a character in the properitory font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
static S32 SearchInPropFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast = gMTKProprietaryFont_small.pRangeDetails->nNoOfRanges - 1;
    S16 nMid;

    pAMTKProprietaryFont_RangeData = gMTKProprietaryFont_small.pRangeDetails->pRangeData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= pAMTKProprietaryFont_RangeData[nMid].nMin) && (nCh <= pAMTKProprietaryFont_RangeData[nMid].nMax))
        {
            *pnBase = pAMTKProprietaryFont_RangeData[nMid].nMin;
        #if defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_BDF_SW_COMPRESSION__)
            return gMTKProprietaryFont_small.pRange->rangeOffset[nMid];
        #else 
            return gMTKProprietaryFont_small.pRange[nMid];
        #endif 

        }
        if (nCh > pAMTKProprietaryFont_RangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}
#endif /* defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  Get_CharWidthHeight_internal
 * DESCRIPTION
 *  To get the font info of the desired character
 * PARAMETERS
 *  Ch              [IN]        
 *  pdWidth         [OUT]       The dwidth of the character. If the character is not Indic character. The dwidth is equal to width.
 *  pWidth          [OUT]       The width of the ch.
 *  pHeight         [OUT]       The height of the ch.
 *  pAscent         [OUT]       The ascent of the ch.
 *  pDescent        [OUT]       The descent of the ch.
 *  ch(?)           [IN]        
 * RETURNS
 *  FE_GLYPH_ATTR_USING_FONT_ENGINE or 0
 *****************************************************************************/
#ifdef __MMI_SCRIPT_EASY__

U32 Get_CharWidthHeight_internal(U32 Ch, S32 *pdWidth, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    mmi_fe_get_string_info_param_struct query;

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)&Ch;
    query.n = 1;
    query.enableTruncated = MMI_FALSE;
    mmi_fe_get_string_widthheight(&query);
    
    *pWidth = query.pWidth;
    *pHeight = query.pHeight;

    *pDescent = query.pHeight >> 2;
    *pAscent = *pHeight - *pAscent;

    return 0;
}

#else /* __MMI_SCRIPT_EASY__ */
static U32 Get_CharWidthHeight_internal(
            U32 Ch,
            S32 *pdWidth,
            S32 *pWidth,
            S32 *pHeight,
            S32 *pAscent,
            S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height;
    S32 bearing_x;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0;
    S32 rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_KERNING__)
    mmi_fe_get_font_data(
        MMI_FALSE,
        (U16) Ch,
        &pCharData,
        &data_attr,
        &pnWidth,
        &advance_x,
        &glyph_width,
        &glyph_height,
        &bearing_x,
        pAscent,
        pDescent,
        &lsb_delta, 
        &rsb_delta,
        &valid);
#else
    mmi_fe_get_font_data(
        MMI_FALSE,
        (U16) Ch,
        &pCharData,
        &data_attr,
        &pnWidth,
        &advance_x,
        &glyph_width,
        &glyph_height,
        &bearing_x,
        pAscent,
        pDescent,
        &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    *pdWidth = advance_x;
    *pWidth = pnWidth;
    *pHeight = glyph_height;
    return data_attr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_glyph_metrics
 * DESCRIPTION
 *  This is used to get the glyph metrics for a sepcified character.
 *  The font metrics is considered with font attribute.
 *  The caller to use this API should get GDI lock first for thread safe in font engine.
 * PARAMETERS
 *  ch              [IN]        The ucs2 code for the character
 *  matrix          [IN]        
 *  metrics(?)      [OUT]       The metrics for the ch
 * RETURNS
 *  MMI_BOOL        [OUT] to indicate if the character is valid or not.
 *  If it is invalid character, the metrics info is the info for nil character.
 *****************************************************************************/
MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0;
    S32 rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    S32 bearing_x;
    MMI_BOOL valid;
    S32 ascent, descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
#ifndef __MMI_SCRIPT_EASY__
	#if defined(__MMI_VECTOR_FONT_SUPPORT__)
	mmi_fe_set_active_font(ch, MMI_FALSE);
	#endif
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
    mmi_fe_get_font_data(
        MMI_FALSE,
        ch,
        &pCharData,
        &data_attr,
        &pnWidth,
        &advance_x,
        &glyph_width,
        &glyph_height,
        &bearing_x,
        &ascent,
        &descent,
        &lsb_delta, 
        &rsb_delta,
        &valid);
#else
    mmi_fe_get_font_data(
        MMI_FALSE,
        ch,
        &pCharData,
        &data_attr,
        &pnWidth,
        &advance_x,
        &glyph_width,
        &glyph_height,
        &bearing_x,
        &ascent,
        &descent,
        &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    matrix->adv_x = (S16) advance_x;
    matrix->width = glyph_width;
    matrix->height = glyph_height;
    matrix->descent = (S16) descent;
    matrix->ascent = (S16) ascent;
    /* enlarge the font width for italic or qblique if it is bitmap font. */

#ifndef __MMI_BDF_SW_COMPRESSION__
    if ((gnCurrentFontAttrib & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) && data_attr == 0)
    {
        matrix->width += (font_tilt_table[matrix->height]);
    }
    if ((gnCurrentFontAttrib & (FONTATTRIB_BOLD)) && data_attr == 0)
    {
        matrix->width += 1;
    }
#else /* __MMI_BDF_SW_COMPRESSION__ */ 
    {
        U32 style_width = 0;

        bfcDecGetStyleWidth(g_decoder, (BFC_STYLE_ENUM)gnCurrentFontAttrib, matrix->width, matrix->height, (kal_int32 *)&style_width);
        matrix->width = style_width;
    }
#endif /* __MMI_BDF_SW_COMPRESSION__ */ 

    /* add one pixel height for the underline */
    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
    {
        matrix->descent++;
    }
    FE_UNLOCK;
    GDI_UNLOCK;
    return valid;

}
#endif /* __MMI_SCRIPT_EASY__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_LANG_THAI__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_LANG_THAI__) && !defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
/* under construction !*/
/* under construction !*/
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

#ifndef __MMI_SCRIPT_EASY__
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_lang_id
 * DESCRIPTION
 *  To get lang id by input char
 * PARAMETERS
 *  ch          [IN]        
 *  char(?)     [IN]        
 * RETURNS
 *  mmi_fe_lang_id     the enum of the langauge id
 *****************************************************************************/
#ifdef __MMI_VECTOR_FONT_KERNING__
__inline static mmi_fe_lang_id mmi_fe_get_lang_id(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ARSHAPING_ENGINE__
    if (ch < 0x0600)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0x06FF)
        return MMI_FE_LANG_ARABIC;
#endif /* __MMI_ARSHAPING_ENGINE__ */ 

#ifdef __MMI_INDIC_ALG__
    if (ch < 0x0900)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0x0DF4)
        return MMI_FE_LANG_INDIC;
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef __MMI_LANG_THAI__
    if (ch < 0x0E01)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0x0E7F)
        return MMI_FE_LANG_THAI;
#endif /* __MMI_LANG_THAI__ */ 

#ifdef __MMI_INDIC_ALG__
    if (ch < 0xe900)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0xee52)
        return MMI_FE_LANG_INDIC;
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef __MMI_ARSHAPING_ENGINE__
    if (ch < 0xFB50)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0xFDFF)
        return MMI_FE_LANG_ARABIC;
#endif /* __MMI_ARSHAPING_ENGINE__ */ 

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (ch < 0xFE70)
        return MMI_FE_LANG_OTHERS;
    if (ch < 0xFEFF)
        return MMI_FE_LANG_ARABIC;
#endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 
    return MMI_FE_LANG_OTHERS;
}
#endif
#endif /* #ifndef __MMI_SCRIPT_EASY__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string
 * DESCRIPTION
 *  To display string in the screen
 * PARAMETERS
 *  param       [IN]        The input parameter for string display
 * RETURNS
 *  UNIT32  how many character is diaplyed.
 *****************************************************************************/
U32 mmi_fe_show_string(mmi_fe_showstring_info_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param_in;
    U32 ret;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->len <= 0 || param->String == NULL)
    {
        return 0;
    }

    if (param->enable_truncated)
    {
        ret = mmi_font_engine_show_truncated_text(
                param->x,
                param->y,
                param->truncated_width,
                param->String,
                param->truncated_symbol,
                (MMI_BOOL) param->Bordered);
    }
    else
    {

        memset(&param_in, 0, sizeof(mmi_fe_showstring_int_param_struct));
        gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
        param_in.x = param->x;
        param_in.y = param->y;
        param_in.String = param->String;
        param_in.assign_direction = param->assign_direction;
        param_in.BaseLineHeight = param->BaseLineHeight;
        param_in.char_gap = param->char_gap;
        param_in.len = param->len;
        param_in.enable_truncated = MMI_FALSE;
        param_in.truncated_symbol = NULL;
        param_in.visible_x_start = -1;
        param_in.visible_x_end = -1;
        param_in.Bordered = param->Bordered;
        param_in.render_flag = param->render_flag;
        param_in.clip_x1 = clip_x1;
        param_in.clip_x2 = clip_x2;
        param_in.clip_y1 = clip_y1;
        param_in.clip_y2 = clip_y2;
        ret = mmi_fe_show_string_int(&param_in);
    }
    return ret;
}

#ifndef __MMI_SCRIPT_EASY__
#if defined(__MMI_LANG_THAI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_thai_character
 * DESCRIPTION
 *  Check if the character is thai character
 * PARAMETERS
 *  curCh       [IN]        Character to check
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_fe_is_thai_character(U16 curCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((curCh >= 0x0E01 && curCh <= 0x0E7F) || (curCh == 0xF700) || (curCh == 0xF70F))
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
 *  mmi_fe_show_thai_char_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CurrentX            [IN]        
 *  CurrentY            [IN]        
 *  pre2Ch              [IN]        
 *  preCh               [IN]        
 *  curCh               [IN]        
 *  param               [IN]        
 *  Bordered(?)         [IN]        
 *  Font(?)             [IN]        
 *  LineHeight(?)       [IN]        
 *  BackGround(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static S32 mmi_fe_show_thai_char_internal(
                        S32 CurrentX,
                        S32 CurrentY,
                        U16 pre2Ch,
                        U16 preCh,
                        U16 curCh,
                        mmi_fe_showstring_int_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;
    U32 CharDataAttr;
    U32 NumChar;
    S32 nWidth;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent;
    S32 descent;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0; 
    S32 rsb_delta = 0; 
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    S32 bearing_x;
    S32 advance_x;
    S32 iX = CurrentX;
    S32 iY = CurrentY;
    static S32 pre_base_x, pre_up_vowel_x, pre_down_vowel_x;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32) curCh))
        return 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    mmi_trace_screen_char(CurrentX, CurrentY, curCh, 0, param->Bordered);
#endif 

#if defined(__MMI_VECTOR_FONT_KERNING__)
    NumChar = mmi_fe_get_font_data(
                MMI_TRUE,
                curCh,
                &CharData,
                &CharDataAttr,
                &nWidth,
                &advance_x,
                &glyph_width,
                &glyph_height,
                &bearing_x,
                &ascent,
                &descent,
                       &lsb_delta, 
                       &rsb_delta,
                &valid);
#else
    NumChar = mmi_fe_get_font_data(
                       MMI_TRUE, 
                       curCh, 
                       &CharData,
                       &CharDataAttr, 
                       &nWidth, 
                       &advance_x, 
                       &glyph_width, 
                       &glyph_height, 
                       &bearing_x,
                       &ascent, 
                       &descent,
                       &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */

    /* adjust iX and iY for Thai characters */
    if (CharDataAttr == 0 && mmi_fe_is_thai_character(curCh))
    {
        if (IsThaiBaseLineChar(curCh))
        {
            if (IsThaiLongTailChar(preCh))
            {
                iX += 1;
                advance_x += 1;
            }
            //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
            //moved ahead to let the circyle sign on the top of previous or previous2 character
            if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
            {
                iX -= 1;
                advance_x -= 1;
            }
            pre_base_x = iX;
        }
        else if (IsThaiAboveLineChar(curCh))
        {
            /* Above line characters */
            iY -= 1;    /* Reserver 1 pixtel vertical interleaving */
            if (IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh))
            {
                /* Process the X coordinate when combining with other base line characters */
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(preCh))  /* move ahead 3 pixels, */
                {
                    iX -= 3;
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)   /* move ahead 6 pixels */
                {
                    iX -= 2;
                    if (glyph_height <= 17 && (curCh == 0x0e34 || curCh == 0x0e35 || curCh == 0x0e37))
                    {
                        iX -= 1;
                    }
                #if ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    else if (glyph_height == 20)
                    {
                        switch (curCh)
                        {
                            case 0x0e31:
                                iX -= 1;
                                break;
                            case 0x0e34:
                            case 0x0e35:
                            case 0x0e36:
                            case 0x0e37:
                            case 0x0e47:
                                iX = pre_base_x;
                                break;
                        }
                    }
                #if defined(__MMI_MAINLCD_320X480__)
                    else if (glyph_height == 24)
                    {
                        switch (curCh)
                        {
                            case 0x0e4c:
                                iX -= 2;
                                break;
                            case 0x0e31:
                            case 0x0e34:
                            case 0x0e35:
                            case 0x0e36:
                            case 0x0e37:
                            case 0x0e47:
                                iX = pre_base_x;
                                break;
                        }
                    }
                #endif /* defined(__MMI_MAINLCD_320X480__) */ 
                #endif /* ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)) */ 
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
            }
            else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
            {
                if (IsThaiUpVowel(preCh))
                {
                    iY -= 3;
                    iX = pre_up_vowel_x;
                }
                else
                {
                    iX -= ((S32) nWidth);
                }

                if (!IsThaiBaseLineChar(pre2Ch))
                {
                    if (IsThaiBottomLineChar(preCh))
                    {
                        if (iX < pre_down_vowel_x)
                            iX = pre_down_vowel_x;
                    }
                    else if (IsThaiAboveLineChar(preCh))
                    {
                        if (iX < pre_up_vowel_x)
                            iX = pre_up_vowel_x;
                    }
                }
            }

            if (IsThaiUpVowel(curCh))
                pre_up_vowel_x = iX;
        }
        else if (IsThaiBottomLineChar(curCh))
        {
            /* Bottom line characters */
            if (IsThaiBaseLineChar(preCh))
            {
                iX -= ((S32) nWidth);
            }
            pre_down_vowel_x = iX;
        }
        else if (IsThaiToneMark(curCh))
        {
            /* Tone marks */
            iY -= 1;
            if (IsThaiBaseLineChar(preCh) && preCh != 0x0e30)
            {
                iX -= ((S32) nWidth);
                if (preCh == 0x0E33)
                {
                    iY -= 3;    /* move tone mark higher */
                    if (IsThaiBaseLineChar(pre2Ch))
                    {
                        iX -= 7;    /* Move tone mark ahead across the width of */
                    }

                }
                else if (IsThaiLongTailChar(preCh))
                {
                    iX -= 2 /* 3 */ ;   /* move tone mark ahead for 3 pixel */
                #if ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    if (glyph_height == 20 && preCh == 0x0e1b &&
                        (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 1;
                    }
                    else if (glyph_height == 20 && preCh == 0x0e1d &&
                             (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 1;
                    }
                    else if (glyph_height == 20 && preCh == 0x0e1f)
                    {
                        iX -= 1;
                    }
                #if defined(__MMI_MAINLCD_320X480__)
                    else if (glyph_height == 24 && preCh == 0x0e1b &&
                             (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 2;
                    }
                    else if (glyph_height == 24 && preCh == 0x0e1d &&
                             (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 2;
                    }
                    else if (glyph_height == 24 && preCh == 0x0e1f)
                    {
                        iX -= 2;
                    }
                #endif /* defined(__MMI_MAINLCD_320X480__) */ 
                #endif /* ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)) */ 
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)
                {
                    iX -= 2;
                    if (glyph_height <= 17)
                    {
                        if (curCh == 0x0e48 || curCh == 0x0e4b)
                        {
                            iX -= 2;
                        }
                    }
                #if ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    else if (glyph_height == 20)
                    {
                        switch (curCh)
                        {
                            case 0x0e48:
                                iY -= 1;
                                break;
                            case 0x0e49:
                            case 0x0e4a:
                            case 0x0e4b:
                                iX -= 1;
                                break;
                        }
                    }
                #if defined(__MMI_MAINLCD_320X480__)
                    else if (glyph_height == 24)
                    {
                        iX -= 4;
                    }
                #endif /* defined(__MMI_MAINLCD_320X480__) */ 
                #endif /* ! (defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__)) */ 
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0e13 || (preCh == 0x0e19 && glyph_height > 17) || preCh == 0x0e28 || preCh == 0x0e29
                         || preCh == 0x0e2A)
                {
                    iX -= 3;
                }
                else if (preCh == 0x0e19 && glyph_height <= 17)
                {
                    iX -= 1;
                }
            }
            else if (IsThaiSignChar(preCh))
            {

            }
            else if (IsThaiAboveLineChar(preCh))
            {
                iY -= 3;
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }
                else if (pre2Ch == 0x0E0A || pre2Ch == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (pre2Ch == 0x0E2C)
                {
                    iX -= 3;
                }

                if (IsThaiBaseLineChar(pre2Ch))
                {
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else
                {
                    if (iX < pre_up_vowel_x)
                        iX = pre_up_vowel_x;
                }

            }
            else if (IsThaiBottomLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }

                if (IsThaiBaseLineChar(pre2Ch))
                {
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else
                {
                    if (iX < pre_down_vowel_x)
                        iX = pre_down_vowel_x;
                }
            }
            else if (preCh == 0x0E47 || preCh == 0x0E4C)
            {
                /* move the tone mark to next character space */
                iX += ((S32) nWidth);
            }

        }
        else if (IsThaiSignChar(curCh))
        {
            if (IsThaiBaseLineChar(preCh) && IsThaiUpSign(curCh))
            {
                iX -= ((S32) nWidth);
            }
            if (IsThaiLongTailChar(preCh))
            {
                iX -= 2;
            }
            if (!IsThaiBaseLineChar(pre2Ch))
            {
                if (IsThaiBottomLineChar(preCh))
                {
                    if (iX < pre_down_vowel_x)
                        iX = pre_down_vowel_x;
                }
                else if (IsThaiAboveLineChar(preCh))
                {
                    if (iX < pre_up_vowel_x)
                        iX = pre_up_vowel_x;
                }
            }
        }
        //(1)Other cases: For Thai digits and base line sign, the only thing we have to do is moving cursor
        //(2)Show Characters

    }
    {
        iY = iY + (param->BaseLineHeight - ascent);
        iX += bearing_x;
        if (param->max_ascent < ascent)
            param->max_ascent = ascent;
        if (param->max_descent < descent)
            param->max_descent = descent;

        if (param->enable_truncated)
        {
            if (mmi_fe_get_r2l_state())
            {
                if (iX < param->visible_x_start)
                {
                    return advance_x;
                }
                else
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = iX;
                }
            }
            else
            {
                if (iX + nWidth > param->visible_x_end)
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = iX;
                    return advance_x;
                }
            }
        }

        mmi_fe_show_font_data(
            curCh,
            iX,
            iY,
            CharData,
            NumChar,
            CharDataAttr,
            glyph_width,
            glyph_height,
            param->Bordered,
            gnCurrentFontAttrib,
            param->text_color,
            param->border_color);
    }
    return advance_x;
}

#endif /* defined(__MMI_LANG_THAI__) */ 

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_single_cluster_other
 * DESCRIPTION
 *  To display one cluster for common language
 * PARAMETERS
 *  param               [IN]        
 *  text_color          [IN]        
 *  border_color        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_single_cluster_other(
                mmi_fe_show_one_cluster_param_struct_p param,
                gdi_color text_color,
                gdi_color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type curch = 0;
    S32 i;
    U8 *CharData;
    U32 CharDataAttr;
    U32 NumChar;
    S32 nWidth = 0;
    S32 bearing_x;
    S32 advance_x;
    U16 glyph_width = 0;
    U16 glyph_height = 0;
    S32 ascent = 0;
    S32 descent = 0;
    MMI_BOOL bordered = (MMI_BOOL)param->bordered;
    MMI_BOOL valid;
    S32 curX = param->x;
    S32 y_offset;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0; 
    S32 rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < param->len; i++)
    {
        curch = param->string[(i << 1)] | (param->string[(i << 1) + 1] << 8);
#if defined(__MMI_VECTOR_FONT_KERNING__)
        NumChar = mmi_fe_get_font_data(
                    MMI_FE_GET_DATA,
                    curch,
                    &CharData,
                    &CharDataAttr,
                    &nWidth,
                    &advance_x,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &ascent,
                    &descent,
                    &lsb_delta, 
                    &rsb_delta,
                    &valid);
#else
        NumChar = mmi_fe_get_font_data(
                    MMI_FE_GET_DATA,
                    curch,
                    &CharData,
                    &CharDataAttr,
                    &nWidth,
                    &advance_x,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &ascent,
                    &descent,
                    &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */
        y_offset = param->y + (param->baseline - ascent);
        if (i == 0 && bearing_x < 0)
            bearing_x = 0;
        if (NumChar)
            mmi_fe_show_font_data(
                curch,
                curX + bearing_x,
                y_offset,
                CharData,
                NumChar,
                CharDataAttr,
                glyph_width,
                glyph_height,
                bordered,
                gnCurrentFontAttrib,
                text_color,
                border_color);
        curX += advance_x;

    }
}

#endif /* !defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
#if defined(__MMI_VECTOR_FONT_KERNING__)
U16 g_prev_char = 0;
signed long  prev_rsb_delta = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_int
 * DESCRIPTION
 *  To display a string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
void mmi_fe_get_kerning_adjustment(U16 prev_ucs, U16 curr_ucs,S16 *pen_position_x)
{
    signed long kerning_x,kerning_y;
    FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
    //mmi_fe_cache_key_struct key;
    U32 temp_font_attr = font_engine_font_attr;
    mmi_fe_text_info_p text_info;
    S32 glyph_len = 0;

    MMI_BOOL valid;
    S32 pnWidth, ascent, descent, lsb_delta = 0, rsb_delta = 0;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height; 
    S32 bearing_x; 
    U8 *pCharData;
    U32 data_attr;
    U16 curr_glyph_index, prev_glyph_index;
    signed long  p_rsb_delta = 0;
    signed long  p_lsb_delta = 0;
    int adjustment_x;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *pen_position_x = 0;

    prev_glyph_index = font_engine->get_glyph_index(prev_ucs);
    curr_glyph_index = font_engine->get_glyph_index(curr_ucs);
    font_engine->get_font_kerning(prev_glyph_index, curr_glyph_index, &kerning_x, &kerning_y);

    if(prev_glyph_index != 0)
    {
        //mmi_fe_cache_key_maker(&prev_glyph_index, 1, ot_lang, temp_font_attr, font_engine_font_size, ot_script, 1, 0, &key);
        mmi_fe_cache_key_maker(&prev_ucs, 1, ot_lang, temp_font_attr, font_engine_font_size, ot_script, MMI_FALSE, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_CLUSTER_DATA, 0, 0, 0, NULL, &mmi_fe_key);
        if (!(mmi_fe_cache_tree_find(&mmi_fe_key, (void **)&text_info, &glyph_len)))
        {
            mmi_fe_get_font_data(MMI_FE_GLYPH_INDEX, 
                prev_glyph_index, 
                & pCharData, 
                &data_attr, 
                &pnWidth, 
                &advance_x, 
                &glyph_width, 
                &glyph_height, 
                &bearing_x, 
                &ascent, 
                &descent, 
                &p_lsb_delta, 
                &p_rsb_delta,
                &valid);
        }
        else
        {
            p_lsb_delta = ((*text_info).posdata).lsb_delta;
            p_rsb_delta = ((*text_info).posdata).rsb_delta;
        }
    }

    if(curr_glyph_index != 0)
    {
        //mmi_fe_cache_key_maker(&curr_glyph_index, 1, ot_lang, temp_font_attr, font_engine_font_size, ot_script, 1, 0,&key);
        mmi_fe_cache_key_maker(&curr_ucs, 1, ot_lang, temp_font_attr, font_engine_font_size, ot_script, MMI_FALSE, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_CLUSTER_DATA, 0, 0, 0, NULL, &mmi_fe_key);    
        if (!(mmi_fe_cache_tree_find(&mmi_fe_key, (void **)&text_info, &glyph_len)))
        {
            mmi_fe_get_font_data(MMI_FE_GLYPH_INDEX, 
                curr_glyph_index, 
                & pCharData, 
                &data_attr, 
                &pnWidth, 
                &advance_x, 
                &glyph_width, 
                &glyph_height, 
                &bearing_x, 
                &ascent, 
                &descent, 
                &lsb_delta, 
                &rsb_delta,
                &valid);
        }
        else
        {
            lsb_delta = ((*text_info).posdata).lsb_delta;
            rsb_delta = ((*text_info).posdata).rsb_delta;
        }
    }

    adjustment_x = kerning_x / 64;
    kerning_y = kerning_x % 64;
    if(kerning_y > 32)
    {
        adjustment_x = adjustment_x + 1;
    }
    else if(kerning_y < -32)
    {
        adjustment_x = adjustment_x - 1;
    }

    if ( p_rsb_delta - lsb_delta >= 32 )
    {
        adjustment_x  -= 1;
    }
    else if ( p_rsb_delta - lsb_delta < -32 )
    {
        adjustment_x += 1;
    }                                                
    *pen_position_x =*pen_position_x + adjustment_x;       
}
#endif /* __MMI_VECTOR_FONT_KERNING__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_int_core
 * DESCRIPTION
 *  To display a string in the screen
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_string_int_core(mmi_fe_showstring_int_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = param->len;
    S32 curX = 0;
#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    S32 curY = 0;
#endif

#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif 
#if defined(__MMI_BIDI_ALG__)
    MMI_BOOL IS_BIDI = MMI_FALSE;
#endif 
    S32 check_len = 0;
    U8 *temp_string = param->String;
    U8 *String = param->String;
    U16 visual_str_len = 0, visual_cur_pos = 0;
    BIDI_PARAGRAPH_TYPES paratype = P_LTR;
    //S32 lang_string_group = 0;
    //U8 *lang_string_start = NULL;
    S32 x_offset = 0;
    //S32 totalLineHeight = 0;
    gdi_color border_color = 0, text_color;
    U32 render_flag = param->render_flag;
    U8 tempFontAttrib = gnCurrentFontAttrib;
    MMI_BOOL enableTruncated = param->enable_truncated;
    MMI_BOOL drawTwice = MMI_FALSE;
    S32 max_descent = 0, temp_descent;
    MMI_BOOL border;
    //MMI_BOOL font_attr_change = MMI_FALSE;
    MMI_BOOL first_is_r2l = MMI_FALSE;
#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_BIDI_ALG__)
    MMI_BOOL is_shaping_tbl_done = MMI_FALSE;
    MMI_BOOL is_bidi_tbl_done = MMI_FALSE;
#endif
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    mmi_fe_text_format_struct_p pRechTextFormat = NULL;
    //mmi_fe_rech_text_format_underline_info_struct underline_info[MAX_SHOW_STRING_TEXT_LENGTH] = {0};
    mmi_fe_rech_text_format_underline_info_struct_p punderline_info = underline_info;
    U32 numofChar = 0;
    //int i = 0;
#endif

#if defined(__MMI_VECTOR_FONT_KERNING__)
    MMI_BOOL is_kerning_supported = MMI_FALSE;
    S32 adjustment_x = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    BOOL ret = MMI_FALSE;
    U8 cache_cluster_index = 0;
    FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
    mmi_fe_cache_string_info *cache_string_info_p = NULL;
    mmi_fe_cache_cluster_info *cache_cluster_info_p = NULL;
    UI_string_type cacahe_cluster_string_p = NULL;
    S32 cluster_info_len = 0;
    mmi_fe_cache_image_info_p cache_string_image_p = NULL;
    mmi_fe_cache_tree_node_struct *node = NULL;
    mmi_fe_cache_tree_struct *tree = NULL;
    U16 img_buf_size = 0;
    U16 effect_buf_size = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("FES");
    GDI_LOCK;
    FE_LOCK;

#if defined(__MMI_BDF_SW_COMPRESSION__)
    //bfcDecSetDictionary(g_decoder,
    //      gpCurrentFont->lv1_table,
    //      gpCurrentFont->lv2_table);
#endif /* defined(__MMI_BDF_SW_COMPRESSION__) */ 

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    mmi_trace_screen_string(param->x, param->y, String, len, param->Bordered);
#endif 
    if (g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        if (param->Bordered)
        {
            param->Bordered = 0;
            //font_attr_change = MMI_TRUE;
        }
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        if (gFontEffect == FONT_EFFECT_ENGRAVE)
        {
            font_engine_font_attr &= (~FE_FONT_ATTR_ENGRAVE);
            //font_attr_change = MMI_TRUE;
        }
    #endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
    }

    /*if (param->Bordered &&
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->Bordered = 0;
    }*/
    border = (MMI_BOOL)param->Bordered;

    border_color = gdi_act_color_from_rgb(
                    0xff,
                    g_mmi_fe_text_border_color.r,
                    g_mmi_fe_text_border_color.g,
                    g_mmi_fe_text_border_color.b);
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color, border_color);
#endif 

    gnCurrentFontAttrib &= (~(FONTATTRIB_UNDERLINE | FONTATTRIB_STRIKETHROUGH));

    /* initialize */
    param->text_color = text_color;
    param->border_color = border_color;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    pRechTextFormat = param->format;
#endif

    if (len < 0)
    {
        len = mmi_ucs2strlen((const char*)String);
    }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (param->Bordered)
    {
        font_engine_font_attr |= FE_FONT_ATTR_BORDER;
    }
    font_engine->set_font_attr(font_engine_font_attr);
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif

    if(!(param->enable_truncated || pRechTextFormat ) && (font_engine_font_attr&FE_FONT_ATTR_ANTIALIAS))
    {
    #if defined(__MMI_FONT_EFFECTS__)
        if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
        {
            mmi_fe_cache_key_maker((UI_string_type)String, len, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, (MMI_BOOL)0, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_IMAGE, 0, 0, gSubFontEffect, NULL, &mmi_fe_key);
        }
        else
    #endif
        {
            mmi_fe_cache_key_maker((UI_string_type)String, len, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, (MMI_BOOL)0, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_IMAGE, 0, 0, 0, NULL, &mmi_fe_key);
        }
        ret = mmi_fe_cache_tree_find(&mmi_fe_key, (void **)(&cache_string_image_p), NULL);
    }
    
    if(ret)
    {
        if(mmi_fe_get_r2l_state() && !cancelWidth)
            param->x = param->x - cache_string_image_p->str_w + 1;
        
        if (param->BaseLineHeight != (U32) -1)
            param->y = param->y + param->BaseLineHeight - cache_string_image_p->baseline;

        param->BaseLineHeight = cache_string_image_p->baseline;
        
    #if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
        gdi_font_begin(curX, curY, text_color, gnCurrentFontAttrib);
    #endif

    #if defined(__MMI_FONT_EFFECTS__)
        if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
            mmi_fe_show_font_effect_data_ext(
                            0,
                            param->x,
                            param->y,
                            (U8*)(cache_string_image_p->buf),
                            cache_string_image_p->buf_size,
                            cache_string_image_p->str_w,
                            cache_string_image_p->str_h,
                            (U8*)(cache_string_image_p->buf)+cache_string_image_p->buf_size,
                            cache_string_image_p->effect_buf_size);
        else
    #endif
            mmi_fe_show_font_data(
                            0,
                            param->x,
                            param->y,
                            (U8*)(cache_string_image_p->buf),
                            cache_string_image_p->buf_size,
                            FE_GLYPH_ATTR_USING_FONT_ENGINE,
                            cache_string_image_p->str_w,
                            cache_string_image_p->str_h,
                            param->Bordered,
                            gnCurrentFontAttrib,
                            text_color,
                            border_color);
        
        x_offset = param->x + cache_string_image_p->str_w;
        max_descent = cache_string_image_p->maxDescent;
    }
    else
#endif
    {
#if 1//defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__)
    if (len > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH)
        len = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
#endif /* defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__) */ 

    curX = param->x;
#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    curY = param->y;
#endif
    /* cancelWidth = true would be set by editor */

#if defined(__MMI_BIDI_ALG__)
    first_is_r2l = mmi_fe_check_first_is_r2l(String);
#endif


    {
        mmi_fe_get_string_info_param_struct query;
        memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));

        query.String = String;
        query.n = len;
        query.w = param->char_gap;
        //query.enableTruncated = MMI_FALSE;
        query.targetWidth = -1;
        query.assign_direction = param->assign_direction;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        query.format = pRechTextFormat;
#endif

        mmi_fe_get_string_widthheight(&query);

        if (mmi_fe_get_r2l_state() && !cancelWidth)
        {
            if((!first_is_r2l) && (param->enable_truncated == MMI_TRUE))
            {
                /* Adjust x to visable start x */
                curX = param->visible_x_start; 
            }
            else
            {
                curX = param->x - query.pWidth + 1;
            }
        }
        if(!mmi_fe_get_r2l_state() && !cancelWidth)
        {
            if((first_is_r2l) && (param->enable_truncated == MMI_TRUE))
            {
                curX = param->x  + (param->visible_x_end - param->visible_x_start + 1) - query.pWidth + 1;
            }
        }

        if (param->BaseLineHeight == (U32) -1)
        {
            param->BaseLineHeight = query.baseline;
        }

        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        if(!(param->enable_truncated || pRechTextFormat) && (font_engine_font_attr&FE_FONT_ATTR_ANTIALIAS))
        {
            if(query.pWidth < UI_DEVICE_WIDTH*2)
            {
                U16 border_width = 0;
                ret = MMI_TRUE;
                
            #if defined(__MMI_FONT_EFFECTS__)
                if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
                {
                    switch(gFontEffect)
                    {
                        case FONT_EFFECT_DROP_SHADOW:
                        {
                            border_width = gAdvanceFontAttribute.shadow_range;
                            break;
                        }
                        case FONT_EFFECT_OUTER_GLOW:
                        {
                            border_width = gAdvanceFontAttribute.outerglow_range;
                            break;
                        }
                        case FONT_EFFECT_BORDER:
                        {
                            border_width = gAdvanceFontAttribute.border_size;
                            break;
                        }
                        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
                        {
                            border_width = gAdvanceFontAttribute.shadow_range;
                            break;
                        }
                        default:
                            break;
                    }
                    effect_buf_size = FE_FOUR_BYTE_ALIGN(((query.pWidth + 2 * border_width) * (query.pHeight + 2 * border_width) + 1) >> 1) + sizeof(mmi_fe_render_data_struct);
                    ret = mmi_fe_alloc_effect_data_pool(effect_buf_size * 2);
                }
            #endif
                img_buf_size = FE_FOUR_BYTE_ALIGN((query.pWidth * query.pHeight + 1) >> 1) + sizeof(mmi_fe_cache_image_info);

                if(ret)
                {
                #if defined(__MMI_FONT_EFFECTS__)
                    if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
                    {
                        mmi_fe_cache_key_maker((UI_string_type)String, len, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, (MMI_BOOL)0, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_IMAGE, 0, 0, gSubFontEffect, NULL, &mmi_fe_key);
                        mmi_fe_cache_tree_alloc_string_image_cache_node(&mmi_fe_key, img_buf_size + effect_buf_size*mmi_fe_effect_img_cache_count[gFontEffect], &node, &mmi_fe_img_cache_ptr, &tree);
                    }
                    else
                #endif
                    {
                        mmi_fe_cache_key_maker((UI_string_type)String, len, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, (MMI_BOOL)0, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_IMAGE, 0, 0, 0, NULL, &mmi_fe_key);
                        mmi_fe_cache_tree_alloc_string_image_cache_node(&mmi_fe_key, img_buf_size, &node, &mmi_fe_img_cache_ptr, &tree);
                    }

                    if(mmi_fe_img_cache_ptr)
                    {
                        mmi_fe_img_cache_ptr->str_w = query.pWidth;
                        mmi_fe_img_cache_ptr->str_h = query.pHeight;
                        mmi_fe_img_cache_ptr->maxDescent = query.maxDescent;
                        mmi_fe_img_cache_ptr->baseline = query.baseline;
                        mmi_fe_img_cache_ptr->buf->normal_data_size = img_buf_size - sizeof(mmi_fe_cache_image_info);
                        mmi_fe_img_cache_ptr->buf_size = (U32)&(mmi_fe_img_cache_ptr->buf->data[mmi_fe_img_cache_ptr->buf->normal_data_size]) - (U32)mmi_fe_img_cache_ptr->buf;
                        mmi_fe_img_cache_ptr->effect_buf_size = effect_buf_size;
                        mmi_fe_enable_img_cache_mode();
                    }
                #if defined(__MMI_FONT_EFFECTS__)
                    else if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
                        mmi_fe_free_effect_data_pool();
                #endif
                }
            }
        }
        #endif
    }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    mmi_fe_cache_key_maker((UI_string_type)String, len, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, (MMI_BOOL)0, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_INFO, FE_TAG_MAKER('b','i','d','i'), 0, 0, pRechTextFormat, &mmi_fe_key);
    ret = mmi_fe_cache_tree_find(&mmi_fe_key, (void **)&cache_string_info_p, NULL);
#endif

    /* the data passed from editor has been processed by BIDI and shaping. Hence, go to process. */
    if (cancelWidth)
        goto MMI_FE_SHOW_STRING;

#if defined(__MMI_BIDI_ALG__)
    check_len = len;
    while (check_len != 0)
    {
        U8 dic = 0;
        U16 unicode = 0;

        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

    #if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
    #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 

        bidi_get_char_type((U8*) (&unicode), &dic);

        if (dic == BIDI_R || dic == AL || dic == AN || dic == WS)
        {
            IS_BIDI = MMI_TRUE;
        }

        if (IS_BIDI
    #if defined(__MMI_ARSHAPING_ENGINE__)
            && IS_ARABIC
    #endif 
            )
            break;
        temp_string += 2;
    }

#endif /* defined(__MMI_BIDI_ALG__) */ 

    /* shaping */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC)
    {
        mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String, len);
        show_pwcWord[len] = 0;
        len = mmi_ucs2strlen((const char*)show_pwcWord);
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        if (pRechTextFormat)
        {
            S32 i;
            for (i = 0; i < len; i++)
                fe_ShaToOrg[i] = i;
            fe_ShaToOrg[len] = 0;

            ArabicShapeEngine2_ext((U16*) & len, (U16*) show_pwcWord, NULL, fe_ShaToOrg);
            is_shaping_tbl_done = MMI_TRUE;
        }
        else
#endif
        {
            ArabicShapeEngine_ext((U16*) & len, show_pwcWord);
        }
        String = (U8*) & show_pwcWord;
    }
#endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 

    /* bidi */
#if defined(__MMI_BIDI_ALG__)
    if (IS_BIDI || param->assign_direction == BIDI_R)
    {
        if (param->assign_direction == BIDI_R)
        {
            paratype = P_RTL;
        }
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        if (pRechTextFormat)
        {
            bidi_main_ext(
                String,
                (U16) len,
                0,
                show_visual_str,
                &visual_str_len,
                &visual_cur_pos,
                fe_l2v_map,
                fe_v2l_map,
                MMI_FALSE,
                MMI_bidi_input_type,
                MMI_FALSE,
                paratype);
            is_bidi_tbl_done = MMI_TRUE;
        }
        else
#endif
        {
            bidi_main_ext(
                String,
                (U16) len,
                0,
                show_visual_str,
                &visual_str_len,
                &visual_cur_pos,
                NULL,
                NULL,
                MMI_FALSE,
                MMI_bidi_input_type,
                MMI_FALSE,
                paratype);
        }
        String = (U8*) show_visual_str;
    }
    else
    {
        mmi_ucs2ncpy((S8*) show_visual_str, (S8*) String, len);
        String = (U8*) show_visual_str;
    }
#endif /* defined(__MMI_BIDI_ALG__) */

  MMI_FE_SHOW_STRING:

    /* baseline hasn't be got in previous step. */
    /*if (!(mmi_fe_get_r2l_state() && !cancelWidth))
    {
        if (param->BaseLineHeight == (U32)-1)
        {
            S32 baseline = mmi_font_engine_get_baseline_internal(String, len, &totalLineHeight);

            param->BaseLineHeight = baseline;
        }
    }*/

    //lang_string_start = String;
    //lang_string_group = 0;

#ifdef __MMI_BDF_SW_COMPRESSION__
    if (param->Bordered)
    {
        bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)((gnCurrentFontAttrib & ~BFC_STYLE_NORMAL) | BFC_STYLE_BORDER), text_color, border_color);
    }
    else
    {
        bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)((gnCurrentFontAttrib==0) ? gnCurrentFontAttrib|BFC_STYLE_NORMAL : gnCurrentFontAttrib), text_color, border_color);
    }

    
#endif
#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__) 
    gdi_font_begin(curX, curY, text_color, gnCurrentFontAttrib);
#endif 

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    //if (font_attr_change)
    {
        if (param->Bordered)
        {
            font_engine_font_attr |= FE_FONT_ATTR_BORDER;
        }
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

  FE_SHOW_STRING_START:

    /* change param->x to real start x */
    param->x = curX;
    {
        mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
        U8 *str_end;
        U8 *str_start;
        MMI_BOOL show = MMI_TRUE /*, show_prev = MMI_FALSE*/;
        mmi_lm_show_cluster_param show_param;
        S32 x_real_offset = 0;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        U16 curr_ucs_char = 0;
#endif
        //U16 curr_ucs_index;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        U32 start_index = 0;
        U32 end_index = 0;
        stFontAttribute font;
        U8 arrCount;
        mmi_fe_color c= {0};
        MMI_BOOL set_rech_text_format = MMI_FALSE;
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        if(ret)
        {
            cache_cluster_index = 0;
            cluster_info_len = cache_string_info_p->string_info_header.cluster_info_len;
            cache_cluster_info_p = (mmi_fe_cache_cluster_info *)((U8 *)cache_string_info_p + sizeof(cache_string_info_p->string_info_header));
            cacahe_cluster_string_p = (UI_string_type)((U8 *)cache_string_info_p + sizeof(cache_string_info_p->string_info_header) + cache_string_info_p->string_info_header.cluster_info_len*sizeof(mmi_fe_cache_cluster_info));
        }
#endif

        str_start = String;
        str_end = String + len * 2;
        mmi_lm_cluster_init(&prev_cluster);
        mmi_lm_cluster_init(&prev2_cluster);
        mmi_lm_cluster_init(&cluster);
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        memset(underline_info, 0, sizeof(underline_info));
#endif
        
        show_param.cluster = &cluster;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        if(mmi_fe_get_img_cache_mode())
        {
            x_offset = 0;
            show_param.baseline = mmi_fe_img_cache_ptr->baseline;
        }
        else
#endif
        {
            x_offset = curX;
            show_param.baseline = param->BaseLineHeight;
        }
        show_param.y = param->y;
        show_param.bordered = param->Bordered;
        show_param.prev_cluster = &prev_cluster;
        if (!(param->visible_x1_start == -1 && param->visible_x1_end == -1) && param->enable_truncated)
        {
            if (mmi_fe_get_r2l_state())
            {
                x_real_offset = param->visible_x1_start;
            }
            else
            {
                x_real_offset = curX;
            }
        }

        do
        {
            /* /TODO: check the case for r2lmmiflag */

            /* variable initialize */
            show = MMI_TRUE;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
            if(ret && cache_cluster_index < cluster_info_len)
            {
                memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));
                cluster.data_ptr = str_start;

#if defined(__MMI_VECTOR_FONT_KERNING__)
                adjustment_x = cache_cluster_info_p->adjustment_x;
#endif
                cluster.w = cache_cluster_info_p->w;
                cluster.h = cache_cluster_info_p->h;
                cluster.adv_x = cache_cluster_info_p->adv_x;
                cluster.adv_y = cache_cluster_info_p->adv_y;
                cluster.bx = cache_cluster_info_p->bx;
                cluster.by = cache_cluster_info_p->by;
                cluster.rx = cache_cluster_info_p->rx;
                cluster.ry = cache_cluster_info_p->ry;

                cluster.is_gap = cache_cluster_info_p->is_gap;
                cluster.is_connect = cache_cluster_info_p->is_connect;
                cluster.data_len = cache_cluster_info_p->data_len;
                cluster.cluster_len = cache_cluster_info_p->cluster_len;
                cluster.lang_id = cache_cluster_info_p->lang_id;
                
                memcpy(cluster.display_buffer, cacahe_cluster_string_p, cache_cluster_info_p->cluster_len*sizeof(UI_character_type));
                cacahe_cluster_string_p += cache_cluster_info_p->cluster_len;
                cache_cluster_info_p++;
                cache_cluster_index++;
            }
            else
#endif
            {
            #if defined(__MMI_VECTOR_FONT_KERNING__)
                //curr_ucs_char = *str_start;//((String[0]) | (String[1] << 8));
                curr_ucs_char = ((param->String[0]) | (param->String[1] << 8));
                /*curr_ucs_index = */font_engine->get_glyph_index(curr_ucs_char);
                //if(curr_ucs_index == 0)
                {
                    mmi_fe_set_active_font(curr_ucs_char, MMI_FALSE);
                }
                is_kerning_supported = font_engine->is_kerning();
            #endif /* __MMI_VECTOR_FONT_KERNING__ */

                memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
                memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));
                mmi_lm_cluster_init(&cluster);

                cluster.data_ptr = str_start;
                mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);
            }

#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
            pRechTextFormat = param->format;
            if(pRechTextFormat)
            {
                start_index = numofChar;
                end_index = start_index + cluster.data_len;

                   /* Convert the visiual index to logical index for BIDI and Shapping */
            #if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
                if (is_shaping_tbl_done && is_bidi_tbl_done)
                {
                    /* convert index from BIDI and shapping table */
                    start_index = fe_ShaToOrg[fe_v2l_map[numofChar]];
                    if ((fe_v2l_map[numofChar] + cluster.data_len) < len)
                    {
                        end_index = start_index + (fe_ShaToOrg[fe_v2l_map[numofChar] + cluster.data_len] - fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                    else
                    {
                        end_index = start_index + (len - fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__) */ 
            #if defined(__MMI_ARSHAPING_ENGINE__)
                if (is_shaping_tbl_done && !is_bidi_tbl_done)
                {
                    /* convert index from shapping table */
                    start_index = fe_ShaToOrg[numofChar];
                    if ((numofChar + cluster.data_len) < len)
                    {
                        end_index = start_index + (fe_ShaToOrg[numofChar + cluster.data_len] - fe_ShaToOrg[numofChar]);
                    }
                    else
                    {
                        end_index = start_index + (len - fe_ShaToOrg[numofChar]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 
            #if defined(__MMI_BIDI_ALG__)
                if (is_bidi_tbl_done && !is_shaping_tbl_done)
                {
                    /* convert index from BIDI table */
                    start_index = fe_v2l_map[numofChar];
                    end_index = start_index + cluster.data_len;
                }
            #endif /* defined(__MMI_BIDI_ALG__) */ 

                while(pRechTextFormat)
                {
                    if((start_index >= pRechTextFormat->start)&&(end_index <= pRechTextFormat->end))
                    {
                        GetFont(&font, &arrCount);
                        c = mmi_fe_get_text_color();
                        SetFont(pRechTextFormat->font, arrCount);
                        mmi_fe_set_text_color(pRechTextFormat->c);
                        text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
                    #ifdef __MMI_VECTOR_FONT_SUPPORT__
                        font_engine->set_font_color(text_color, border_color);
                    #endif
                        mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);

                        set_rech_text_format = MMI_TRUE;
                        break;
                    }
                    pRechTextFormat = pRechTextFormat->next;
                }
            }
            numofChar += cluster.data_len;
#endif

            temp_descent = cluster.h - cluster.by;
            if (temp_descent > max_descent)
                max_descent = temp_descent;

            if (
                #if defined(__MMI_VECTOR_FONT_SUPPORT__)
                (!mmi_fe_get_img_cache_mode()) && 
                #endif
                (cluster.lang_id != MMI_LM_LANG_OTHERS))
                drawTwice = MMI_TRUE;

            if (prev_cluster.lang_id != MMI_LM_LANG_NONE &&
                ((prev_cluster.lang_id == MMI_LM_LANG_ARABIC && cluster.lang_id != MMI_LM_LANG_ARABIC) ||
                 (prev_cluster.lang_id != MMI_LM_LANG_ARABIC && cluster.lang_id == MMI_LM_LANG_ARABIC)) && !render_flag)
            {
                x_offset++;
                x_real_offset++;
            }

            if (param->visible_x1_start == -1 && param->visible_x1_end == -1)
            {
                if ((x_offset > param->clip_x2 + 1))
                {
                    if (param->enable_truncated)
                    {
                        if (x_offset > param->visible_x_start)
                        {
                            param->truncated_symbol_start = x_offset;
                            break;
                        }
                    }
                    else
                    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
                        if(!mmi_fe_get_img_cache_mode())
                    #endif
                    {
                        break;
                    }
                }
            }
            x_offset += cluster.rx;
            x_real_offset += cluster.rx;

            /* the end of the cluster is in the front of the clip x. */
            if(
                #if defined(__MMI_VECTOR_FONT_SUPPORT__)
                (!mmi_fe_get_img_cache_mode()) && 
                #endif
                (x_offset + cluster.w < param->clip_x1))
            {
                show = MMI_FALSE;
            }

            if (param->enable_truncated)
            {
                /* Ellipsis from tail */
                if (param->visible_x1_start == -1 && param->visible_x1_end == -1)
                {
                   
                    if (x_offset + cluster.w < param->visible_x_start)
                        show = MMI_FALSE;
                    if (first_is_r2l && (x_offset < param->visible_x_start))
                        show = MMI_FALSE;
                    
                    if ((x_offset >= param->visible_x_start) && (first_is_r2l))
                    {

                        param->truncated_symbol_start = x_offset;
                        param->enable_truncated = MMI_FALSE;

                    }
                    if ((x_offset + cluster.adv_x - 1) > param->visible_x_end && !(first_is_r2l))
                    {
                        param->truncated_symbol_start = x_offset;
                        break;
                    }
                }
                else
                {
                    /* Ellipsis from middle */
                    show = MMI_FALSE;
                    if (mmi_fe_get_r2l_state())
                    {
                        if (((x_offset > param->visible_x_start) &&
                             (x_offset < param->visible_x_end)) ||
                            (((x_offset - param->x + cluster.w) >= 0) &&
                             ((x_offset - param->x + cluster.w) < (param->visible_x_end - param->visible_x_start + 1))))
                        {
                            show = MMI_TRUE;
                        }

                        if ((x_offset > param->visible_x1_end) && (param->truncated_symbol_start == 0))
                        {
                            param->truncated_symbol_start = param->visible_x_start;
                            x_real_offset = param->visible_x_start;
                        }
                    }
                    else
                    {
                        if (((x_offset + cluster.w > param->visible_x_start) &&
                             (x_offset + cluster.w < param->visible_x_end)) ||
                            ((param->string_width - (x_offset - param->x) >= 0) &&
                             (param->string_width - (x_offset - param->x) <
                              (param->visible_x1_end - param->visible_x1_start + 1))))
                        {
                            show = MMI_TRUE;
                        }

                        if (((x_offset + cluster.adv_x - 1) > param->visible_x_end) &&
                            (param->truncated_symbol_start == 0))
                        {
                            param->truncated_symbol_start = param->visible_x_end;
                            x_real_offset = param->visible_x1_start;
                        }
                    }
                }
            }

            if (!(param->visible_x1_start == -1 && param->visible_x1_end == -1) && param->enable_truncated)
            {
                show_param.x = x_real_offset;
            }
            else
            {
                show_param.x = x_offset;
            }
        #if defined(__MMI_VECTOR_FONT_KERNING__)
            if(ret && cache_cluster_index <= cluster_info_len)
            {
                show_param.x = show_param.x + adjustment_x;
            }
            else
            {
                signed long kerning_x, kerning_y;
                FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
                //mmi_fe_cache_key_struct key;
                U32 temp_font_attr = font_engine_font_attr;
                mmi_fe_text_info_p text_info;
                S32 glyph_len = 0;
                MMI_BOOL ret = MMI_FALSE;

                MMI_BOOL valid;
                S32 pnWidth, ascent, descent, lsb_delta = 0, rsb_delta = 0;
                S32 advance_x;
                U16 glyph_width;
                U16 glyph_height; 
                S32 bearing_x; 
                U8 *pCharData;
                U32 data_attr;
                U16 curr_glyph_index;
        
                if(is_kerning_supported)
                {
                    if(mmi_fe_get_lang_id(*(show_param.cluster->display_buffer)) == MMI_FE_LANG_OTHERS)
                    {
                        curr_glyph_index = font_engine->get_glyph_index(*(show_param.cluster->display_buffer));
                        font_engine->get_font_kerning(g_prev_char, curr_glyph_index, &kerning_x, &kerning_y);

                        mmi_fe_cache_key_maker((show_param.cluster->display_buffer), 1, ot_lang, temp_font_attr, font_engine_font_size, ot_script, MMI_FALSE, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_CLUSTER_DATA, 0, 0, 0, NULL, &mmi_fe_key);
                        ret = (MMI_BOOL)mmi_fe_cache_tree_find(&mmi_fe_key, (void **)&text_info, &glyph_len);

                        if (ret)
                        {
                            font_engine_error_code = MMI_FE_FONT_ERR_NONE;
                            lsb_delta = ((*text_info).posdata).lsb_delta;
                            rsb_delta = ((*text_info).posdata).rsb_delta;
                        }
                        else
                        {
                            mmi_fe_get_font_data(MMI_FE_GLYPH_INDEX, 
                                curr_glyph_index, 
                                & pCharData, 
                                &data_attr, 
                                &pnWidth, 
                                &advance_x, 
                                &glyph_width, 
                                &glyph_height, 
                                &bearing_x, 
                                &ascent, 
                                &descent, 
                                &lsb_delta, 
                                &rsb_delta,
                                &valid);
                        }

                        adjustment_x = kerning_x/64;
                        kerning_y = kerning_x%64;
                        if(kerning_y>32)
                        {
                            adjustment_x = adjustment_x + 1;
                        }
                        else if(kerning_y<-32)
                        {
                            adjustment_x = adjustment_x - 1;
                        }

                        if ( prev_rsb_delta - lsb_delta >= 32 )
                        {
                            adjustment_x  -= 1;
                        }
                        else if ( prev_rsb_delta - lsb_delta < -32 )
                        {
                            adjustment_x += 1;
                        }

                        prev_rsb_delta = rsb_delta;  
                        show_param.x = show_param.x + adjustment_x; 

                        g_prev_char = curr_glyph_index;
                        kerning_x = kerning_y = 0;
                    }
                }
            }
            if (show)
            {
                mmi_lm_draw_cluster(&show_param);
                x_real_offset += cluster.adv_x + adjustment_x;
            }
            x_offset += cluster.adv_x + adjustment_x;
            //show_prev = show;
            adjustment_x = 0;
            str_start+= cluster.data_len*2;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
            if(set_rech_text_format)
            {
                if (show && pRechTextFormat->font.underline)
                {
                    punderline_info->x1 = show_param.x;
                    punderline_info->x2 = x_offset;
                    punderline_info->c = text_color;
                    punderline_info++;
                }
                SetFont(font, arrCount);
                mmi_fe_set_text_color(c);
                text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
            #ifdef __MMI_VECTOR_FONT_SUPPORT__
                font_engine->set_font_color(text_color, border_color);
            #endif
                set_rech_text_format = MMI_FALSE;
            }
#endif
        } while (str_start < str_end);

#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        if(set_rech_text_format)
        {
            SetFont(font, arrCount);
            mmi_fe_set_text_color(c);
            text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
        #ifdef __MMI_VECTOR_FONT_SUPPORT__
            font_engine->set_font_color(text_color, border_color);
        #endif
            set_rech_text_format = MMI_FALSE;
        }
#endif
    }
    g_prev_char = 0;
    prev_rsb_delta = 0;
#else
            if (show)
            {
                mmi_lm_draw_cluster(&show_param);
                x_real_offset += cluster.adv_x;
            }
            x_offset += cluster.adv_x;
            //show_prev = show;

            str_start += cluster.data_len * 2;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
            if(set_rech_text_format)
            {
                if (show && pRechTextFormat->font.underline)
                {
                    punderline_info->x1 = show_param.x;
                    punderline_info->x2 = x_offset;
                    punderline_info->c = text_color;
                    punderline_info++;
                }
                SetFont(font, arrCount);
                mmi_fe_set_text_color(c);
                text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
            #ifdef __MMI_VECTOR_FONT_SUPPORT__
                font_engine->set_font_color(text_color, border_color);
            #endif
                set_rech_text_format = MMI_FALSE;
            }
#endif
        } while (str_start < str_end);
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        if(set_rech_text_format)
        {
            SetFont(font, arrCount);
            mmi_fe_set_text_color(c);
            text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
        #ifdef __MMI_VECTOR_FONT_SUPPORT__
            font_engine->set_font_color(text_color, border_color);
        #endif
            set_rech_text_format = MMI_FALSE;
        }
#endif
    }
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if(mmi_fe_get_img_cache_mode())
    {
        #if defined(__MMI_FONT_EFFECTS__)
        if((gFontEffect >= FONT_EFFECT_DROP_SHADOW) && (gFontEffect <= FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE))
        {
            mmi_fe_create_effect_img_data(
                (U8*)(mmi_fe_img_cache_ptr->buf),
                mmi_fe_img_cache_ptr->buf_size,
                mmi_fe_img_cache_ptr->str_w,
                mmi_fe_img_cache_ptr->str_h,
                (U8*)(mmi_fe_img_cache_ptr->buf)+mmi_fe_img_cache_ptr->buf_size,
                mmi_fe_img_cache_ptr->effect_buf_size);

            mmi_fe_show_font_effect_data_ext(
                0,
                param->x,
                param->y + param->BaseLineHeight - mmi_fe_img_cache_ptr->baseline,
                (U8*)(mmi_fe_img_cache_ptr->buf),
                mmi_fe_img_cache_ptr->buf_size,
                mmi_fe_img_cache_ptr->str_w,
                mmi_fe_img_cache_ptr->str_h,
                (U8*)(mmi_fe_img_cache_ptr->buf)+mmi_fe_img_cache_ptr->buf_size,
                mmi_fe_img_cache_ptr->effect_buf_size);
            
            mmi_fe_free_effect_data_pool();
        }
        else
        #endif
        mmi_fe_show_font_data(
                        0,
                        param->x,
                        param->y + param->BaseLineHeight - mmi_fe_img_cache_ptr->baseline,
                        (U8*)(mmi_fe_img_cache_ptr->buf),
                        mmi_fe_img_cache_ptr->buf_size,
                        FE_GLYPH_ATTR_USING_FONT_ENGINE,
                        mmi_fe_img_cache_ptr->str_w,
                        mmi_fe_img_cache_ptr->str_h,
                        param->Bordered,
                        gnCurrentFontAttrib,
                        text_color,
                        border_color);

        x_offset = param->x + mmi_fe_img_cache_ptr->str_w;
        
        mmi_fe_cache_tree_save_string_image(tree, node);
        
        mmi_fe_disable_img_cache_mode();
    }
#endif
    }
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    if(pRechTextFormat)
        param->format = pRechTextFormat;
#endif

    if (param->Bordered)
    {
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        font_engine_font_attr &= ~FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
        if (drawTwice)
        {
            /* draw the data inside again */
        #ifdef __MMI_BDF_SW_COMPRESSION__
            bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)((gnCurrentFontAttrib & ~BFC_STYLE_NORMAL) | BFC_STYLE_BORDER), text_color, border_color);
        #endif /* __MMI_BDF_SW_COMPRESSION__ */ 

        #if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
            gdi_font_end();
            gdi_font_begin(curX, curY, text_color, gnCurrentFontAttrib);
        #endif /* __MMI_BDF_SW_COMPRESSION__ */ 
            param->Bordered = 0;
            param->enable_truncated = enableTruncated;

            goto FE_SHOW_STRING_START;
        }
    }
    param->Bordered = border;
    gnCurrentFontAttrib = tempFontAttrib;

#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    punderline_info = underline_info;
    if(punderline_info->x1 && punderline_info->x2)
    {
        while(punderline_info->x1 && punderline_info->x2)
        {
            S32 height_offset;
        
            if(param->max_descent)
                height_offset = param->y + (param->BaseLineHeight + param->max_descent);
            else
                height_offset = param->y + (param->BaseLineHeight + max_descent);

            gdi_draw_line(punderline_info->x1, height_offset, punderline_info->x2 - 1, height_offset, punderline_info->c);

            punderline_info++;
        }
    }
    else
#endif
    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
    {
        S32 height_offset;

        if(param->max_descent)
            height_offset = param->y + (param->BaseLineHeight + param->max_descent);
        else
            height_offset = param->y + (param->BaseLineHeight + max_descent);

        gdi_draw_line(param->x, height_offset, x_offset - 1, height_offset, text_color);
    }
    if (gnCurrentFontAttrib & FONTATTRIB_STRIKETHROUGH)
    {
        S32 height_offset = param->y + ((param->BaseLineHeight + max_descent) >> 1);

        gdi_draw_line(param->x, height_offset, x_offset - 1, height_offset, text_color);
    }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    mmi_fe_img_cache_ptr = NULL;
    if ((g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
         g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G &&
         g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B) && (gFontEffect == FONT_EFFECT_ENGRAVE))
    {
        font_engine_font_attr |= FE_FONT_ATTR_ENGRAVE;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 

    }
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

    UI_UNUSED_PARAMETER(paratype);
    UI_UNUSED_PARAMETER(visual_cur_pos);
    UI_UNUSED_PARAMETER(visual_str_len);
    UI_UNUSED_PARAMETER(temp_string);
    UI_UNUSED_PARAMETER(check_len);

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_end();
#endif 

    FE_UNLOCK;
    GDI_UNLOCK;

    FE_SWLA_STOP("FES");
    return x_offset;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_fe_show_string_int(mmi_fe_showstring_int_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 stackSize;
    void *pStack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    stackSize = FE_STACK_SIZE;
    pStack = drv_gfx_stkmgr_get_stack(stackSize);
    if (pStack)
    {
        INT_SwitchStackToRun(pStack, stackSize, (kal_func_ptr) mmi_fe_show_string_int_core, 1, param);

        drv_gfx_stkmgr_release_stack(pStack);
    }
    else
#endif /* defined(__MTK_TARGET__) */ 
    {
        mmi_fe_show_string_int_core(param);
    }

    return 0;
}

#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_indic_string_internal
 * DESCRIPTION
 *  To display a string in the screen
 *  
 *  This is used to display the string in the screen
 * PARAMETERS
 *  param               [IN]        
 *  x(?)                [IN]        
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 *  y(?)                [IN]        
 *  BackGround(?)       [IN]        
 *  String              [?](?)
 *  NumChar(?)          [IN](?)
 *  CharData(?)         [IN](?)
 *  Background(?)       [IN](?)
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_int_param_struct_p param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //W05.38 Remove GDI_ENTER_CRITICAL_SECTION outside GDI
    //GDI_ENTER_CRITICAL_SECTION(ShowString_internal)
    U8 *CharData;
    U32 NumChar;
    //U32 Counter = 0;
    S32 CurrentX = param->x;
    U32 string_width = 0;
    S32 y = param->y;
    //S32 nXOffset;
    S32 yy = 0;
    U16 unicode = 0;
    gdi_color border_color = param->border_color, text_color = param->text_color;
    S32 len = param->len;
    U8 *String = param->String;
    S32 ascent, descent;

    U32 CharDataAttr;
    S32 nWidth = 0;
    S32 bearing_x;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height;
    MMI_BOOL valid;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0; 
    S32 rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //border_color = param->border_color;
    //text_color = param->text_color;

    /* Error Check */
    if (len == 0)
    {
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    }
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    //CurrentX = param->x;
    //unicode = 0;

    while (len != 0)
    {
        //U16 prev_unicode = 0;

      NEXT:
        len--;

        //prev_unicode = unicode;
        unicode = String[0];
        unicode |= (String[1] << 8);

        if (mmi_fe_test_display_as_space(unicode))
        {
            unicode = 0x20;
        }
        if (mmi_fe_test_display_as_invalid(unicode))
        {
            unicode = 0xFFEB;
        }
        if (mmi_fe_test_display_as_null(unicode))
        {
            String += 2;
            if (len == 0)   /* when the formatting character is the last character in the string */
                break;
            else
                goto NEXT;
        }

#if defined(__MMI_VECTOR_FONT_KERNING__)
        NumChar = mmi_fe_get_font_data(
                    MMI_TRUE,
                    unicode,
                    &CharData,
                    &CharDataAttr,
                    &nWidth,
                    &advance_x,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &ascent,
                    &descent,
                    &lsb_delta, 
                    &rsb_delta,
                    &valid);
#else
        NumChar = mmi_fe_get_font_data(
                    MMI_TRUE,
                    unicode,
                    &CharData,
                    &CharDataAttr,
                    &nWidth,
                    &advance_x,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &ascent,
                    &descent,
                    &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
        //Counter++;

        if (param->max_ascent < ascent)
            param->max_ascent = ascent;
        if (param->max_descent < descent)
            param->max_descent = descent;

        //nXOffset = CurrentX + nWidth;
        ire_get_text_x(&CurrentX, unicode, yy, advance_x, nWidth);

        if ((CurrentX > param->clip_x2 + 1) && !mmi_fe_get_r2l_state())
            break;
        /* to check string width boundary when skiping first pass */
        string_width += nWidth;
        y = param->y + (param->BaseLineHeight - ascent);
        mmi_fe_show_font_data(
            (U16) unicode,
            CurrentX,
            y,
            CharData,
            NumChar,
            CharDataAttr,
            glyph_width,
            glyph_height,
            param->Bordered,
            gnCurrentFontAttrib,
            text_color,
            border_color);
        CurrentX += nWidth;
        String += 2;
    }

    return CurrentX;

}

#endif /* defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
#endif /* #ifndef __MMI_SCRIPT_EASY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_display_direction
 * DESCRIPTION
 *  To get display direction by the content
 * PARAMETERS
 *  st      [IN]        The string input
 *  dic     [OUT]       The display direction get by string content
 *  len     [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8 *st, U8 *dic, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BIDI_ALG__)
    U8 default_direction = 0;
    U16 strongCharType = 0xFFFF;
#endif /* defined(__MMI_BIDI_ALG__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (st == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

#if defined(__MMI_BIDI_ALG__)
    while (len > 0)
    {
        bidi_get_char_type((U8*) st, (U8*) & default_direction);
        if (default_direction == BIDI_R || default_direction == AL || default_direction == AN)
        {
            strongCharType = BIDI_R;
            break;
        }
        else if (default_direction == BIDI_L)
        {
            strongCharType = BIDI_L;
            break;
        }
        st += 2;
        len--;
    }

    if (strongCharType == BIDI_R)
    {
        (*dic) = BIDI_R;
    }
    else
    {
        (*dic) = BIDI_L;
    }

#else /* defined(__MMI_BIDI_ALG__) */ 
    (*dic) = BIDI_L;
#endif /* defined(__MMI_BIDI_ALG__) */ 

    return MMI_FONT_ENGINE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_direction
 * DESCRIPTION
 *  To get display direction by the content
 * PARAMETERS
 *  string      [IN]        The string input
 *  len         [IN]        String length
 * RETURNS
 *  PMT_BIDI_TYPES
 *****************************************************************************/
U8 mmi_fe_get_string_direction(U8 *string, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 retDirection = BIDI_L;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(string, &retDirection, len);

    return retDirection;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_measure_string_by_char_num
 * DESCRIPTION
 *  To get string width by the fixed char width.
 *  the fixed char width is count by the max width of the character.
 *  And the string width is the max char width multiple the numofchar.
 *  The characte of Arabic series, Indic series, Thai and Vietnamese language is not allowed
 *  to be the input.
 * PARAMETERS
 *  st              [IN]        All the character would be displayed as a char in the string.
 *  numofchar       [IN]        The number of character of the string
 *  width           [OUT]       The width
 *  height          [OUT]       The height
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_measure_string_by_char_num(U8 *st, S32 numofchar, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = mmi_ucs2strlen((const char*)st);
    S32 max_w = 0, max_ascent = 0, max_descent = 0;
    S32 w, h, dwidth, ascent, descent;
    S32 i;
    U32 unicode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    for (i = 0; i < len * 2; i += 2)
    {
        unicode = st[i];
        unicode |= (st[i + 1] << 8);
        Get_CharWidthHeight_internal(unicode, &dwidth, &w, &h, &ascent, &descent);
        if (dwidth > w)
            w = dwidth;
        max_w = (w > max_w) ? w : max_w;
        max_ascent = (ascent > max_ascent) ? ascent : max_ascent;
        max_descent = (descent > max_descent) ? descent : max_descent;

    }

    *width = (max_w * numofchar);
    *height = (max_ascent + max_descent);
    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_ellipsis_text
 * DESCRIPTION
 *  Print ellipsis text
 *  If length of text is greater than screen width then the text is truncated.
 *  Current we support ellipsis from middle and from tail according to ellipsis_type
 * PARAMETERS
 *  x                           [IN]        Start x positoin
 *  y                           [IN]        Start Y position
 *  xwidth                      [IN]        Width of text in pixels to display. The border width is not included.
 *  st                          [IN]        Text to display
 *  truncated_symbol            [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  bordered                    [IN]        To indicate if it is border or not
 *  ellipsis_type               [IN]        
 *  mmi_fe_ellipsis_type(?)     [IN]        Ellipsis_type
 * RETURNS
 *  S32                     [OUT]   for checking if the string has been truncated
 *****************************************************************************/
#ifdef __MMI_SCRIPT_EASY__

mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text(
                                        S32 x, 
                                        S32 y,
                                        S32 xwidth, 
                                        U8 *st, 
                                        U8 *truncated_symbol, 
                                        MMI_BOOL bordered, 
                                        mmi_fe_ellipsis_type ellipsis_type)
{
    if (mmi_fe_get_r2l_state() && !cancelWidth)
    {
        mmi_fe_get_string_info_param_struct query;
        query.String = st;
        query.n = gui_strlen((UI_string_type) st);
        query.w = 0;
        query.enableTruncated = MMI_TRUE;
        query.targetWidth = xwidth;

        mmi_fe_get_string_widthheight(&query);
        if (query.pWidth > xwidth)
        {
            query.pWidth = xwidth;
        }
        x = x - query.pWidth + 1;
    }
    return se_mtk_show_truncated_text(x, y, xwidth, st, truncated_symbol, 0, 0, bordered);
}

mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text_ext(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered,
                                    mmi_fe_ellipsis_type ellipsis_type,
                                    S32 assigned_baseline)
{
    mmi_fe_show_ellipsis_text(x, y,xwidth, st, truncated_symbol, bordered, ellipsis_type);
}

#else /* #ifdef __MMI_SCRIPT_EASY__ */
mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered,
                                    mmi_fe_ellipsis_type ellipsis_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_fe_show_ellipsis_text_ext(x, y, xwidth, st, truncated_symbol, bordered, ellipsis_type, -1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_ellipsis_text_ext
 * DESCRIPTION
 *  Print ellipsis text
 *  If length of text is greater than screen width then the text is truncated.
 *  Current we support ellipsis from middle and from tail according to ellipsis_type
 * PARAMETERS
 *  x                           [IN]        Start x positoin
 *  y                           [IN]        Start Y position
 *  xwidth                      [IN]        Width of text in pixels to display. The border width is not included.
 *  st                          [IN]        Text to display
 *  truncated_symbol            [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  bordered                    [IN]        To indicate if it is border or not
 *  ellipsis_type               [IN]        ellipsis type
 *  assigned_baseline           [IN]        assigned baseline, -1 mean use string default base line
 * RETURNS
 *  S32                     [OUT]   for checking if the string has been truncated
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text_ext(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered,
                                    mmi_fe_ellipsis_type ellipsis_type,
                                    S32 assigned_baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_xwidth;     /* the new width after subtract truncated_symbol width from original width */
    S32 symbol_width;   /* the width of turncated symbol string */
    S32 symbol_height;  /* the width of truncated symbol string */
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 baseline = 0;
    mmi_fe_get_string_info_param_struct query;
    S32 len = mmi_ucs2strlen((S8*) st);
    mmi_font_engine_error_message_enum ret = MMI_FONT_ENGINE_TRUNCATION;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    MMI_BOOL first_is_r2l = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for error check */
    if (st == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    mmi_fe_get_display_direction(st, &default_direction, len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    GDI_LOCK;
    /* for check if truncation is necessary */
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = st;
    //query.enableTruncated = MMI_FALSE;
    //query.w = 0;
    query.n = len;
    mmi_fe_get_string_widthheight_varient(&query);

    if (assigned_baseline >= 0)
    {
        baseline = assigned_baseline;
    }
    else
    {
        baseline = query.baseline;
    }

    if (bordered &&
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        bordered = MMI_FALSE;
    }
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

#if defined(__MMI_BIDI_ALG__)
    first_is_r2l = mmi_fe_check_first_is_r2l(st);
#endif

    param.x = x;
    param.y = y;
    param.String = st;
    param.BaseLineHeight = baseline;
    param.Bordered = bordered;
    param.len = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    if (query.pWidth <= xwidth)
    {
        //param.enable_truncated = MMI_FALSE;
        //param.truncated_symbol = NULL;
        param.visible_x_start = -1;
        param.visible_x_end = -1;
        param.visible_x1_start = -1;
        param.visible_x1_end = -1;
        if (bordered)
        {
            mmi_fe_show_string_bordered_baseline(x, y, st, baseline, default_direction);
        }
        else
        {
            mmi_fe_show_string_baseline(x, y, st, baseline, default_direction);
        }
        ret = MMI_FONT_ENGINE_NO_TRUNCATION;
    }
    else
    {
        Get_StringWidthHeight(truncated_symbol, &symbol_width, &symbol_height);
        if (bordered)
        {
            symbol_width += 2;
        }

        new_xwidth = xwidth - symbol_width;
        if (new_xwidth < 0)
        {
            ret = MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE;
        }
        else
        {
            if (ellipsis_type == MMI_FE_ELLIPSIS_TAIL)
            {
                param.enable_truncated = MMI_TRUE;
                param.truncated_symbol = truncated_symbol;

                if (mmi_fe_get_r2l_state())
                {
                    if(first_is_r2l)
                    {
                    param.visible_x_start = x - new_xwidth + 1;
                    param.visible_x_end = x;
                    }
                    else
                    {
                        param.visible_x_start = x - xwidth + 1;
                        param.visible_x_end = param.visible_x_start + new_xwidth - 1;
                    }

                    //param.visible_x1_start = -1;
                    //param.visible_x1_end = -1;
                }
                else
                {
                    if(first_is_r2l)
                    {
                        param.visible_x_start = x + symbol_width - 1;
                        param.visible_x_end = param.visible_x_start + new_xwidth - 1;
                    }
                    else
                    {
                    param.visible_x_start = x;
                    param.visible_x_end = x + new_xwidth - 1;
                    }
                    
                    //param.visible_x1_start = -1;
                    //param.visible_x1_end = -1;
                }
                    param.visible_x1_start = -1;
                    param.visible_x1_end = -1;
                param.y = y;

                mmi_fe_show_string_int(&param);
                if ((!mmi_fe_get_r2l_state() && !(param.truncated_symbol_start > clip_x2 + 1)) ||
                    (mmi_fe_get_r2l_state() && !(param.truncated_symbol_start < clip_x1)))
                {
                    /* display truncated symbol */
                    param.enable_truncated = MMI_FALSE;
                    param.String = truncated_symbol;
                    if(mmi_fe_get_r2l_state())
                    {
                        if(first_is_r2l)
                        {
                            param.x = param.truncated_symbol_start;
                        }
                        else
                        {
                            param.x = param.truncated_symbol_start + symbol_width -1 ;
                        }
                    }
                    else
                    {
                        if(first_is_r2l)
                        {
                            param.x = param.truncated_symbol_start - symbol_width + 1;
                        }
                        else
                        {
                            param.x = param.truncated_symbol_start;
                        }
                    }
                    param.y = y;
                    param.BaseLineHeight = baseline;
                    if (mmi_fe_get_r2l_state())
                        param.x--;
                    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
                        param.max_descent = query.maxDescent;
                    mmi_fe_show_string_int(&param);
                }
            }
            else if (ellipsis_type == MMI_FE_ELLIPSIS_MIDDLE)
            {
                param.enable_truncated = MMI_TRUE;
                param.truncated_symbol = truncated_symbol;
                param.string_width = query.pWidth;

                if (mmi_fe_get_r2l_state())
                {
                    param.visible_x_start = x - new_xwidth / 2 + 1;
                    param.visible_x_end = x;
                    param.visible_x1_start = x - xwidth + 1;
                    param.visible_x1_end = x - xwidth + new_xwidth / 2 + 1;
                }
                else
                {
                    param.visible_x_start = x;
                    param.visible_x_end = x + new_xwidth / 2 - 1;
                    param.visible_x1_start = x + xwidth - new_xwidth / 2 - 1;
                    param.visible_x1_end = x + xwidth - 1;
                }
                param.y = y;

                mmi_fe_show_string_int(&param);
                if ((!mmi_fe_get_r2l_state() && !(param.truncated_symbol_start > clip_x2 + 1)) ||
                    (mmi_fe_get_r2l_state() && !(param.truncated_symbol_start < clip_x1)))
                {
                    /* display truncated symbol */
                    param.enable_truncated = MMI_FALSE;
                    param.String = truncated_symbol;
                    param.x = param.truncated_symbol_start;
                    param.y = y;
                    param.BaseLineHeight = baseline;
                    if (mmi_fe_get_r2l_state())
                        param.x--;
                    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
                        param.max_descent = query.maxDescent;
                    mmi_fe_show_string_int(&param);
                }
            }
        }
    }
    GDI_UNLOCK;
    return ret;

}

#endif /* #ifdef __MMI_SCRIPT_EASY__ */

mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text_format_ext(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered,
                                    mmi_fe_ellipsis_type ellipsis_type,
                                    S32 assigned_baseline,
                                    mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_xwidth;     /* the new width after subtract truncated_symbol width from original width */
    S32 symbol_width;   /* the width of turncated symbol string */
    S32 symbol_height;  /* the width of truncated symbol string */
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 baseline = 0;
    mmi_fe_get_string_info_param_struct query;
    S32 len = mmi_ucs2strlen((S8*) st);
    mmi_font_engine_error_message_enum ret = MMI_FONT_ENGINE_TRUNCATION;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    MMI_BOOL first_is_r2l = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for error check */
    if (st == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    mmi_fe_get_display_direction(st, &default_direction, len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    GDI_LOCK;
    /* for check if truncation is necessary */
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = st;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    query.n = len;
    query.format = format;
    mmi_fe_get_string_widthheight_varient(&query);

    if (assigned_baseline >= 0)
    {
        baseline = assigned_baseline;
    }
    else
    {
        baseline = query.baseline;
    }

    if (bordered &&
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        bordered = MMI_FALSE;
    }
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

#if defined(__MMI_BIDI_ALG__)
    first_is_r2l = mmi_fe_check_first_is_r2l(st);
#endif

    param.x = x;
    param.y = y;
    param.String = st;
    param.BaseLineHeight = baseline;
    param.Bordered = bordered;
    param.len = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;
    param.format = format;

    if (query.pWidth <= xwidth)
    {
        param.enable_truncated = MMI_FALSE;
        param.truncated_symbol = NULL;
        param.visible_x_start = -1;
        param.visible_x_end = -1;
        param.visible_x1_start = -1;
        param.visible_x1_end = -1;
        if (bordered)
        {
            mmi_fe_show_string_bordered_baseline_ext(x, y, st, baseline, default_direction, format);
        }
        else
        {
            mmi_fe_show_string_baseline_ext(x, y, st, baseline, default_direction, format);
        }
        ret = MMI_FONT_ENGINE_NO_TRUNCATION;
    }
    else
    {
        Get_StringWidthHeight(truncated_symbol, &symbol_width, &symbol_height);
        if (bordered)
        {
            symbol_width += 2;
        }

        new_xwidth = xwidth - symbol_width;
        if (new_xwidth < 0)
        {
            ret = MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE;
        }
        else
        {
            if (ellipsis_type == MMI_FE_ELLIPSIS_TAIL)
            {
                param.enable_truncated = MMI_TRUE;
                param.truncated_symbol = truncated_symbol;

                if (mmi_fe_get_r2l_state())
                {
                    if(first_is_r2l)
                    {
                    param.visible_x_start = x - new_xwidth + 1;
                    param.visible_x_end = x;
                    }
                    else
                    {
                        param.visible_x_start = x - xwidth + 1;
                        param.visible_x_end = param.visible_x_start + new_xwidth - 1;
                    }

                    param.visible_x1_start = -1;
                    param.visible_x1_end = -1;
                }
                else
                {
                    if(first_is_r2l)
                    {
                        param.visible_x_start = x + symbol_width - 1;
                        param.visible_x_end = param.visible_x_start + new_xwidth - 1;
                    }
                    else
                    {
                    param.visible_x_start = x;
                    param.visible_x_end = x + new_xwidth - 1;
                    }
                    
                    param.visible_x1_start = -1;
                    param.visible_x1_end = -1;
                }
                param.y = y;

                mmi_fe_show_string_int(&param);
                if ((!mmi_fe_get_r2l_state() && !(param.truncated_symbol_start > clip_x2 + 1)) ||
                    (mmi_fe_get_r2l_state() && !(param.truncated_symbol_start < clip_x1)))
                {
                    /* display truncated symbol */
                    param.enable_truncated = MMI_FALSE;
                    param.String = truncated_symbol;
                    if(mmi_fe_get_r2l_state())
                    {
                        if(first_is_r2l)
                        {
                            param.x = param.truncated_symbol_start;
                        }
                        else
                        {
                            param.x = param.truncated_symbol_start + symbol_width -1 ;
                        }
                    }
                    else
                    {
                        if(first_is_r2l)
                        {
                            param.x = param.truncated_symbol_start - symbol_width + 1;
                        }
                        else
                        {
                    param.x = param.truncated_symbol_start;
                        }
                    }
                    param.y = y;
                    param.BaseLineHeight = baseline;
                    if (mmi_fe_get_r2l_state())
                        param.x--;
                    
                    if(param.format)
                    {
                        param.format->start = 0;
                        param.format->end = mmi_ucs2strlen((const CHAR *)param.String);
                        if(param.format->font.underline)
                            param.max_descent = query.maxDescent;
                    }
                    else if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
                        param.max_descent = query.maxDescent;
                    mmi_fe_show_string_int(&param);
                }
            }
            else if (ellipsis_type == MMI_FE_ELLIPSIS_MIDDLE)
            {
                param.enable_truncated = MMI_TRUE;
                param.truncated_symbol = truncated_symbol;
                param.string_width = query.pWidth;

                if (mmi_fe_get_r2l_state())
                {
                    param.visible_x_start = x - new_xwidth / 2 + 1;
                    param.visible_x_end = x;
                    param.visible_x1_start = x - xwidth + 1;
                    param.visible_x1_end = x - xwidth + new_xwidth / 2 + 1;
                }
                else
                {
                    param.visible_x_start = x;
                    param.visible_x_end = x + new_xwidth / 2 - 1;
                    param.visible_x1_start = x + xwidth - new_xwidth / 2 - 1;
                    param.visible_x1_end = x + xwidth - 1;
                }
                param.y = y;

                mmi_fe_show_string_int(&param);
                if ((!mmi_fe_get_r2l_state() && !(param.truncated_symbol_start > clip_x2 + 1)) ||
                    (mmi_fe_get_r2l_state() && !(param.truncated_symbol_start < clip_x1)))
                {
                    /* display truncated symbol */
                    param.enable_truncated = MMI_FALSE;
                    param.String = truncated_symbol;
                    param.x = param.truncated_symbol_start;
                    param.y = y;
                    param.BaseLineHeight = baseline;
                    if (mmi_fe_get_r2l_state())
                        param.x--;

                    if(param.format)
                    {
                        param.format->start = 0;
                        param.format->end = mmi_ucs2strlen((const CHAR *)param.String);
                        if(param.format->font.underline)
                            param.max_descent = query.maxDescent;
                    }
                    else if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
                        param.max_descent = query.maxDescent;
                    mmi_fe_show_string_int(&param);
                }
            }
        }
    }
    GDI_UNLOCK;
    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_show_truncated_text
 * DESCRIPTION
 *  Print truncated text
 *  If length of text is greater  than screen width then the text is truncated.
 *  The assign truncated symbol are shown at end of text
 * PARAMETERS
 *  x                       [IN]        Start x positoin
 *  y                       [IN]        Start Y position
 *  xwidth                  [IN]        Width of text in pixels to display. The border width is not included.
 *  st                      [IN]        Text to display
 *  truncated_symbol        [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  bordered                [IN]        To indicate if it is border or not
 * RETURNS
 *  S32                     [OUT]   for checking if the string has been truncated
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_fe_show_ellipsis_text(x, y, xwidth, st, truncated_symbol, bordered, MMI_FE_ELLIPSIS_TAIL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned          [IN]        
 *  y_unsigned          [IN]        
 *  String              [?]         [?]
 *  Len                 [IN]        
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 *  BackGround(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_n(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.String = String;
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.BaseLineHeight = (U32)-1;
    //param.Bordered = MMI_FALSE;
    param.len = Len;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_n_baseline
 * DESCRIPTION
 *  To display a string by the assigned baseline.
 * PARAMETERS
 *  x_unsigned                  [IN]        
 *  y_unsigned                  [IN]        
 *  String                      [?]         [?]
 *  Len                         [IN]        
 *  baseline                    [IN]        
 *  x(?)                        [IN]        
 *  Font(?)                     [IN]        
 *  y(?)                        [IN]        
 *  BackGround(?)               [IN]        
 *  default_direction(?)        [IN]        The direction to read the string (R2L or L2R)
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_n_baseline(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len, S32 baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = baseline;
    //param.Bordered = MMI_FALSE;
    param.len = Len;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);

}

U32 mmi_fe_show_string_n_baseline_ext(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len, S32 baseline, mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_FALSE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;
    param.format = format;

    return mmi_fe_show_string_int(&param);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_bordered_n_baseline
 * DESCRIPTION
 *  To display a string with border by the assigned baseline.
 * PARAMETERS
 *  x_unsigned                  [IN]        
 *  y_unsigned                  [IN]        
 *  String                      [?]         [?]
 *  Len                         [IN]        
 *  baseline                    [IN]        
 *  x(?)                        [IN]        
 *  Font(?)                     [IN]        
 *  y(?)                        [IN]        
 *  BackGround(?)               [IN]        
 *  default_direction(?)        [IN]        The direction to read the string (R2L or L2R)
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_n_baseline(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len, S32 baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_TRUE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_baseline
 * DESCRIPTION
 *  To display a string by the assigned baseline.
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  String                  [?]         [?]
 *  baseline                [IN]        
 *  default_direction       [IN]        The direction to read the string (R2L or L2R)
 *  Font(?)                 [IN]        
 *  BackGround(?)           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    //param.Bordered = MMI_FALSE;
    param.len = mmi_ucs2strlen((const char*)String);
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);

}


U32 mmi_fe_show_string_baseline_ext(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction, mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_FALSE;
    param.len = mmi_ucs2strlen((const char*)String);
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;
    param.format = format;

    return mmi_fe_show_string_int(&param);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  String              [?]         [?]
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 *  BackGround(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_ext(S32 x, S32 y, U8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    S32 nLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = (U32)-1;
    //param.Bordered = MMI_FALSE;
    param.len = nLen;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_bordered_baseline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  String                  [?]         [?]
 *  baseline                [IN]        
 *  default_direction       [IN]        
 *  LineHeight(?)           [IN]        
 *  Font(?)                 [IN]        
 *  BackGround(?)           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_TRUE;
    param.len = mmi_ucs2strlen((const char*)String);
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;
    return mmi_fe_show_string_int(&param);

}


U32 mmi_fe_show_string_bordered_baseline_ext(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction, mmi_fe_text_format_struct_p format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_TRUE;
    param.len = mmi_ucs2strlen((const char*)String);
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;
    param.format = format;
    return mmi_fe_show_string_int(&param);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_by_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  String                  [IN]        
 *  default_direction       [IN]        The default direction for the string (R2L or L2R)
 *  LineHeight(?)           [IN]        
 *  Font(?)                 [IN]        
 *  BackGround(?)           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_by_direction(S32 x, S32 y, U8 *String, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    nLen = mmi_ucs2strlen((const char*)String);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = (U32)-1;
    //param.Bordered = MMI_FALSE;
    param.len = nLen;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_bordered
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  String              [?]         [?]
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 *  BackGround(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered(S32 x, S32 y, U8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);

    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = (U32)-1;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    //param.render_flag = 0;

    return mmi_fe_show_string_int(&param);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_bordered_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned          [IN]        
 *  y_unsigned          [IN]        
 *  String              [?]         [?]
 *  Len                 [IN]        
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 *  BackGround(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_n(U32 x_unsigned, U32 y_unsigned, U8 *String, int Len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = (U32)-1;
    param.Bordered = MMI_TRUE;
    param.len = Len;
    //param.enable_truncated = MMI_FALSE;
    //param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    //param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    return mmi_fe_show_string_int(&param);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_bordered_by_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                       [IN]        
 *  y                       [IN]        
 *  String                  [?]         [?]
 *  default_direction       [IN]        
 *  LineHeight(?)           [IN]        
 *  Font(?)                 [IN]        
 *  BackGround(?)           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_by_direction(S32 x, S32 y, U8 *String, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    nLen = mmi_ucs2strlen((const char*)String);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = (U32)-1;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharWidth
 * DESCRIPTION
 *  To get char widths
 *  
 *  This is used to get char widths
 * PARAMETERS
 *  Ch          [IN]        
 *  pWidth      [?]         
 *  pdWidth     [?](?)
 * RETURNS
 *  S32(?)(?)
 *****************************************************************************/
void Get_CharWidth(U32 Ch, S32 *pWidth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dwidth, Height, Ascent, Descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    Get_CharWidthHeight_internal(Ch, &dwidth, pWidth, &Height, &Ascent, &Descent);
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 

    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth_internal
 * DESCRIPTION
 *  To get char number in specified width and gap
 *  This function only work for non-complicated langauge.
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String              [IN]        The string content
 *  width               [IN]        The specifed width to display the string.
 *  checklinebreak      [IN]        To check line break or not.
 *  gap                 [IN]        The gap between each character
 *  number(?)           [OUT]       Number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth_internal(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nwidth = 0, chwidth, chheight;
    U32 nchar = 0, line_break_char_counter = 0;
    U16 ch;
    U8 linebreakflag = 0;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        S16 pen_position_x = 0;
        U16 curr_ucs, prev_ucs = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_wc(&ch, String);
    if (ch == 0)
    {
        return 0;
    }

    do
    {
        mmi_ucs2_to_wc(&ch, String);

        if (checklinebreak)
        {
            linebreakflag = FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(ch);
        }

        if (FONT_TEST_BIDI_CONTROL_CHAR(ch))
        {
            chwidth = 0;
        }
        else
        {
            Get_CharWidthHeight(ch, (S32*) & chwidth, (S32*) & chheight);
            chwidth += gap;
        }
#if defined(__MMI_VECTOR_FONT_KERNING__)
        curr_ucs = ch;
        mmi_fe_get_kerning_adjustment(prev_ucs, curr_ucs, &pen_position_x);
        prev_ucs = curr_ucs;
        chwidth += pen_position_x;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
        nwidth += chwidth;
        String += 2;
        nchar++;
        if (checklinebreak)
        {
            if (UI_STRING_END_OF_STRING_CHARACTER(ch))
            {
                line_break_char_counter = nchar;
            }

            if (linebreakflag)
            {
                line_break_char_counter = nchar;
            }
            /*
             * if (!FONT_TEST_ASCII_CHARACTER(ch))
             * {
             * line_break_char_counter = 0;
             * }
             */
        }

    } while (nwidth <= width && ch != 0 /* && ch != 0x0A && ch != 0x0D */ );

    if (checklinebreak)
    {
        if (line_break_char_counter == 0)
        {
            nchar--;
        }
        else
        {
            nchar = line_break_char_counter;
        }
    }
    else
    {
        nchar--;
    }

    return nchar;

}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth_w
 * DESCRIPTION
 *  To get char number in specified width and gap
 *  This function only work for non-complicated langauge.
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String              [IN]        The string content
 *  width               [IN]        The specifed width to display the string.
 *  checklinebreak      [IN]        To check line break or not.
 *  gap                 [IN]        The gap between each character
 *  number(?)           [OUT]       Number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;
    S32 strwidth = width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                strwidth = strwidth - (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                strwidth = strwidth - (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            strwidth = strwidth - (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            strwidth = strwidth - 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            strwidth = strwidth - (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    ret = Get_CharNumInWidth_internal(String, strwidth, checklinebreak, gap);
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  This function only work for non-complicated langauge.
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String              [IN]        The string content
 *  width               [IN]        The specifed width to display the string.
 *  checklinebreak      [IN]        To check line break or not.
 *  number(?)           [OUT]       Number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;
    U32 strwidth = width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                strwidth = strwidth - (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                strwidth = strwidth - (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            strwidth = strwidth - (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            strwidth = strwidth - 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            strwidth = strwidth - (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    ret = Get_CharNumInWidth_internal(String, strwidth, checklinebreak, 1);
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharWidthHeight_int
 * DESCRIPTION
 *  To get char width and height.
 *  The font attribute is not considered as the propriety to influence the return value.
 *  Before using the API, please setup font.
 * PARAMETERS
 *  Ch          [IN]        
 *  pWidth      [OUT]       The character width. If the character is non-India character, the width would be returned. Othrewise, the dwidth (advance width) would be returned.
 *  pHeight     [OUT]       The height of the character.
 *  ch(?)       [IN]        The character
 * RETURNS
 *  void
 *****************************************************************************/
void Get_CharWidthHeight_int(U32 Ch, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0;
    S32 descent = 0;
    S32 width = 0;
    S32 dwidth = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    Get_CharWidthHeight_internal(Ch, &dwidth, &width, pHeight, &ascent, &descent);
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
    {
        *pWidth = dwidth;
    }
    else
#endif /* defined(__MMI_INDIC_ALG__) */ 
    {
        *pWidth = width;
    }

    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharWidthHeight
 * DESCRIPTION
 *  To get char width and height.
 *  The font attribute is not considered as the propriety to influence the return value.
 *  Before using the API, please setup font.
 * PARAMETERS
 *  Ch          [IN]        
 *  pWidth      [OUT]       The character width. If the character is non-India character, the width would be returned. Othrewise, the dwidth (advance width) would be returned.
 *  pHeight     [OUT]       The height of the character.
 *  ch(?)       [IN]        The character
 * RETURNS
 *  void
 *****************************************************************************/
void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0;
    S32 descent = 0;
    S32 width = 0;
    S32 dwidth = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
#ifndef __MMI_SCRIPT_EASY__
	#if defined(__MMI_VECTOR_FONT_SUPPORT__)
	mmi_fe_set_active_font(Ch, MMI_FALSE);
	#endif
#endif
    Get_CharWidthHeight_internal(Ch, &dwidth, &width, pHeight, &ascent, &descent);
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
    {
        *pWidth = dwidth;
    }
    else
#endif /* defined(__MMI_INDIC_ALG__) */ 
    {
        *pWidth = width;
    }

#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  ReverseBitOrdering
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  nNumber     [IN]        
 *  nSize       [IN]        
 * RETURNS
 *  int
 *****************************************************************************/
unsigned __int64 ReverseBitOrdering(unsigned __int64 nNumber, int nSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned __int64 nNewNo = 1;
    unsigned __int64 nRightMask = nNewNo;
    unsigned __int64 nLeftMask = (unsigned __int64)(nNewNo << (nSize - 1));

    unsigned __int64 nTempNo1 = 0;
    unsigned __int64 nTempNo2 = 0;
    unsigned long nShift = nSize - 1;

    U16 nCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nNewNo = 0;
    if (nNumber)
    {
        for (nCount = 0; nCount < nSize / 2; ++nCount)
        {
            nTempNo1 = nNumber & nRightMask;
            nTempNo2 = nNumber & nLeftMask;

            nTempNo1 = nTempNo1 << nShift;
            nTempNo2 = nTempNo2 >> nShift;
            nTempNo1 = nTempNo1 | nTempNo2;
            nNewNo = nNewNo | nTempNo1;
            nShift -= 2;
            nRightMask = nRightMask << 1;
            nLeftMask = nLeftMask >> 1;
        }
        if (nSize % 2)
        {
            nTempNo1 = nNumber & nRightMask;
            nNewNo = nNewNo | nTempNo1;
        }
    }

    return nNewNo;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharBoundingBox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Ch              [IN]        
 *  pCharWidth      [?]         
 *  pCharHeight     [?]         
 *  pBoxXoffset     [?]         
 *  pBoxYoffset     [?]         
 *  pBoxWidth       [?]         
 *  pBoxHeight      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SCRIPT_EASY__
void Get_CharBoundingBox(U32 Ch, S32 * pCharWidth, S32 * pCharHeight, S32 * pBoxXoffset, S32 * pBoxYoffset,
                         S32 * pBoxWidth, S32 * pBoxHeight)
{
    se_mtk_get_char_extent(Ch, pCharWidth, pCharHeight, pBoxXoffset, pBoxYoffset, pBoxWidth, pBoxHeight);
}

#else
void Get_CharBoundingBox(
        U32 Ch,
        S32 *pCharWidth,
        S32 *pCharHeight,
        S32 *pBoxXoffset,
        S32 *pBoxYoffset,
        S32 *pBoxWidth,
        S32 *pBoxHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data_attr = 1;
    U16 data_height;
    U16 data_width;
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    S32 fx1, fy1, fx2, fy2, x, y;
    U8 *font_data;
    U32 font_data_size;
    S32 char_width;
    S32 ascent = 0, descent = 0;
    S32 dwidth;
    S32 bearing_x;
    MMI_BOOL valid;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        mmi_lm_cluster_info cluster = {0}, prev_cluster = {0}, prev2_cluster = {0};
        cluster.data_ptr = (U8 *)&Ch;
        mmi_lm_get_current_cluster(cluster.data_ptr, cluster.data_ptr, &prev2_cluster, &prev_cluster, &cluster);
        data_width = cluster.w;
        data_height = cluster.h;
    }
#else
    {
        font_data_size = mmi_fe_get_font_data(
                            MMI_FALSE,
                            (U16) Ch,
                            &font_data,
                            &data_attr,
                            &char_width,
                            &dwidth,
                            &data_width,
                            &data_height,
                            &bearing_x,
                            &ascent,
                            &descent,
                            &valid);
    }
#endif

    FE_UNLOCK;
    GDI_UNLOCK;

#if defined(__MMI_BDF_SW_COMPRESSION__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
    {
        int i = 0, j = 0, nIndex = 0;
        unsigned __int64 nCurrent = 0, nMask = 0, bU8 = 0;
        gdi_layer_struct *handle_layer = NULL;
        unsigned __int64 char_buffer[200] = {0};
        U8 glyph_buffer[200] = {0};
        unsigned char nBitsCopied = 0;
        int nSourceBitsCopied = 0;
        int nPadding = 0;
        gdi_color border_color = 0, text_color = 0;

        border_color = gdi_act_color_from_rgb(
                    0xff,
                    g_mmi_fe_text_border_color.r,
                    g_mmi_fe_text_border_color.g,
                    g_mmi_fe_text_border_color.b);
        text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);

        gdi_layer_get_active((gdi_handle*) & handle_layer);
        bfcDecSetAttribute(g_decoder, BFC_STYLE_NORMAL, text_color, border_color);
        bfcDecSetCanvas(g_decoder, (U8*) char_buffer, 100, 8, 100, BFC_RGB_FORMAT_1BPP);
        bfcDecSetClipWindow(g_decoder, 0, 0, 99, 99);

        bfcDecDrawGlyph(g_decoder, (U8*) font_data, char_width, data_height, 0, 0);

        if (char_width % 8) /* char_width == font real width */
            nPadding = 8 - (char_width % 8);
        else
            nPadding = 0;
        for (i = 0; i < data_height; i++)
        {
            /* 
             * Because HW compression will pass the font byte sequence is:
             * Left side of glyph pixel is in little endian(low memory), which is reverse with the 
             * sequence of font engine pass to HW compression.
             * So we should reverse the byte sequence, and make them to "Raw data".
             */
            U8 width_byte = (char_width / 8) + (char_width % 8 ? 1 : 0);
            char *pch = (char *) & char_buffer[i];

            for (j = 0; j < (width_byte / 2); j++)
            {
                char chr = pch[j];

                pch[j] = pch[width_byte - j - 1];
                pch[width_byte - j - 1] = chr;
            }

            nSourceBitsCopied = 0;
            nCurrent = char_buffer[i];
            nCurrent = nCurrent >> nPadding;
            nCurrent = ReverseBitOrdering(nCurrent, char_width);

            nMask = 1;
            for (j = 0; j < char_width; ++j)
            {
                unsigned char nTemp;

                // bU8 = (nCurrent)&nMask;  /* the bit value, get each bit of width data */

                /* glyph_buffer[nIndex]|= (unsigned char)bU8; */

                bU8 = (nCurrent) & nMask;   /* the bit value, get each bit of width data */
                if (bU8 > 0)
                {
                    bU8 = 0x01;
                }
                else
                {
                    bU8 = 0x00;
                }

                bU8 = bU8 << nBitsCopied;   /* Adjust to filled bit position. */
                nTemp = (unsigned char)bU8;
                glyph_buffer[nIndex] |= (unsigned char)nTemp;

                ++nBitsCopied;          /* Note the count of current font data byte bit */
                ++nSourceBitsCopied;    /* Note the count of current width bit */
                nMask = nMask << 1;
                if (nBitsCopied >= 8)
                {
                    ++nIndex;

                    nCurrent = char_buffer[i];

                    nCurrent = nCurrent >> nPadding;
                    nCurrent = ReverseBitOrdering(nCurrent, char_width);

                    nMask = 1 << nSourceBitsCopied;
                    nBitsCopied = 0;
                }
            }
            if (nBitsCopied >= 8)
            {
                ++nIndex;
                nCurrent = char_buffer[i];
                nCurrent = nCurrent >> nPadding;

                nCurrent = ReverseBitOrdering(nCurrent, char_width);

                nBitsCopied = 0;
                nMask = 1 << nSourceBitsCopied;
            }

        }
        font_data_size = nIndex + 1;
        font_data = glyph_buffer;
    }
#endif /* __MMI_BDF_SW_COMPRESSION__ */ 

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    *pCharWidth = data_width;
    *pCharHeight = data_height;

    fx1 = data_width - 1;   /* min X of drawn area */
    fx2 = 0;                /* max X of drawn area */
    fy1 = data_height - 1;  /* min Y of drawn area */
    fy2 = 0;                /* max Y of drawn area */

    x = 0;
    y = 0;
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (data_attr)
    {
        *pBoxXoffset = 0;
        *pBoxYoffset = 0;
        *pBoxWidth = data_width;
        *pBoxHeight = data_height;
        return;
    }
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    while (font_data_size--)
    {
        U8 pattern = *font_data++;

        if (!pattern)
        {
            U32 nTemp;

            x += 8;
            nTemp = x / data_width;
            if (nTemp)
            {
                y += nTemp;
                data_height -= (U16) nTemp;
                if (!data_height)
                {
                    break;
                }
            }

            x %= data_width;
        }
        else
        {
            S32 i;

            for (i = 0; i < 8; i++)
            {
                if (pattern & 1)
                {
                    if (x < fx1)
                    {
                        fx1 = x;
                    }
                    if (y < fy1)
                    {
                        fy1 = y;
                    }
                    if (x > fx2)
                    {
                        fx2 = x;
                    }
                    if (y > fy2)
                    {
                        fy2 = y;
                    }
                }

                x++;
                if (x == (S32) data_width)
                {
                    y++;
                    data_height--;
                    x = 0;
                    if (!data_height)
                    {
                        break;
                    }
                }
                pattern >>= 1;
            }
        }
    }

    MMI_DBG_ASSERT(fx2 >= fx1 && fy2 >= fy1);

    *pBoxXoffset = fx1;
    *pBoxYoffset = fy1;
    *pBoxWidth = fx2 - fx1 + 1;
    *pBoxHeight = fy2 - fy1 + 1;
#endif
}
#endif /* __MMI_SCRIPT_EASY__ */


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight
 * DESCRIPTION
 *  To get string width and height.
 *  The bordered attribute is not considered as an attribute to influence the string width & height.
 * PARAMETERS
 *  String      [IN]        The string content
 *  pWidth      [OUT]       The string width
 *  pHeight     [OUT]       The string height
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    nLen = mmi_ucs2strlen((const char*)String);

    query.String = String;
    //query.checkCompleteWord = MMI_FALSE;
    //query.enableTruncated = MMI_FALSE;
    query.n = nLen;
    //query.w = 0;

    mmi_fe_get_string_widthheight_varient(&query);
    *pWidth = query.pWidth;
    *pHeight = query.pHeight;

#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
}

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_n
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters
 * PARAMETERS
 *  String      [IN]        The string content
 *  n           [IN]        The given number of characters.
 *  pWidth      [OUT]       The string width
 *  pHeight     [OUT]       The string height
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = n;
    //query.enableTruncated = MMI_FALSE;
    //query.w = 0;
    mmi_fe_get_string_widthheight_varient(&query);

    *pWidth = query.pWidth;
    *pHeight = query.pHeight;

#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_multitap
 * DESCRIPTION
 *  To get the multitap string width and height.
 *  The language process would not applied in the string.
 *  We consider each character as a separate character to query its attribute.
 * PARAMETERS
 *  String      [IN]        The string content
 *  w           [IN]        The gap between each character.
 *  pWidth      [OUT]       The string width
 *  pHeight     [OUT]       The string height
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StrWidth = 0;
    S32 Counter = 0;
    S32 nHeight = 0;
    U16 unicode = 0;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        S16 pen_position_x = 0;
        U16 curr_ucs, prev_ucs = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pHeight = 0;
    *pWidth = 0;

    if (String == NULL)
    {
        return;
    }
    GDI_LOCK;
    while (1)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        memcpy(&unicode, String, 2);

        Get_CharWidthHeight_int(unicode, &StrWidth, &nHeight);
        /* Consider the Thai String length is different from others */
#if defined(__MMI_VECTOR_FONT_KERNING__)
        curr_ucs = unicode;
        mmi_fe_get_kerning_adjustment(prev_ucs, curr_ucs, &pen_position_x);
        prev_ucs = curr_ucs;
        StrWidth += pen_position_x;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
        (*pWidth) += (StrWidth + w);
        if (*pHeight < nHeight)
        {
            *pHeight = nHeight;
        }
        Counter++;

        String += 2;
    }
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 

    GDI_UNLOCK;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_w
 * DESCRIPTION
 *  To get string widths and height with the given gap
 * PARAMETERS
 *  String      [IN]        The string content
 *  w           [IN]        The gap between each character
 *  pWidth      [OUT]       The string width
 *  pHeight     [OUT]       The string height
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_w(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen;
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = nLen;
    //query.enableTruncated = MMI_FALSE;
    query.w = w;
    mmi_fe_get_string_widthheight_varient(&query);

    *pWidth = query.pWidth;
    *pHeight = query.pHeight;

#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_wn
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters and the given gap between each character.
 * PARAMETERS
 *  String      [IN]        The string content
 *  w           [IN]        The gap between each character
 *  n           [IN]        The given number of characters.
 *  pWidth      [OUT]       The string width
 *  pHeight     [OUT]       The string height
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_wn(U8 *String, S32 w, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = n;
    //query.enableTruncated = MMI_FALSE;
    query.w = w;
    mmi_fe_get_string_widthheight_varient(&query);

    *pWidth = query.pWidth;
    *pHeight = query.pHeight;
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 *gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_variant
 * DESCRIPTION
 *  To get string widths, height and how many character could be displayed in the spefied width
 *  with a given number of characters and the given gap between each character.
 * PARAMETERS
 *  string                  [?]         
 *  w                       [IN]        The gap between each character
 *  n                       [IN]        The given number of characters.
 *  pWidth                  [OUT]       The string width
 *  pHeight                 [OUT]       The string height
 *  max_width               [IN]        The specified width to display the string.
 *  checkLineBreak          [IN]        To indicate if the line break character should be considered as an end.
 *  checkCompleteWord       [IN]        To indicate if the complete word should be considered.
 *  String(?)               [IN]        The string content
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_StringWidthHeight_variant(
        U8 *string,
        S32 w,
        S32 n,
        S32 *pWidth,
        S32 *pHeight,
        S32 max_width,
        U8 checkLineBreak,
        U8 checkCompleteWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = string;
    query.n = n;
    query.enableTruncated = MMI_TRUE;
    query.w = w;
    query.targetWidth = max_width;
    query.checkCompleteWord = checkCompleteWord;
    query.checklinebreak = checkLineBreak;
    counter = mmi_fe_get_string_widthheight_varient(&query);

    //*pWidth = query.pWidth;
    *pWidth = query.adv_w > query.pWidth ? query.adv_w : query.pWidth;
    *pHeight = query.pHeight;

#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                *pWidth = *pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                *pHeight = *pHeight + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            *pWidth = *pWidth + 2;
            *pHeight = *pHeight + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            *pWidth = *pWidth + (2 * gAdvanceFontAttribute.border_size);
            *pHeight = *pHeight + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 

    return counter;
}

#ifndef __MMI_SCRIPT_EASY__

#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_indic_internal
 * DESCRIPTION
 *  get Indc string information
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_fe_get_string_widthheight_indic_internal(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 prev_base_char_dwidth = 0;
    U32 prev_base_char_width = 0;
    U32 prev_char_dwidth = 0;
    U32 prev_char_width = 0;

    U32 pWidth = 0;
    U32 pWidth_adv = 0;
    U32 Counter = 0;
    U32 n = param->n;
    S32 ascent = 0, descent = 0;
    S32 chWidth, chHeight, chAscent, chDescent, chDwidth;
    U32 curr_char_pos = 0, pre_char_pos = 0, pre_base_char_pos = 0;
    U16 curCh = 0;
    U8 *String = param->String;
    S32 cursorX = 0;
    MMI_BOOL cluster_last_char = (MMI_BOOL)IRE_IS_OFFSET_REQUIRED();
    mmi_fe_glyph_metrics_struct metrics;
    S32 Italic_tilt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IRE_RESET_RENDERING_CORRECTION();
    /*
     * if (!ire_is_indic_rules_parsing())
     * {
     * cluster_last_char = MMI_FALSE;
     * }
     */

    while (Counter < n)
    {
        if (String[0] == 0 && String[1] == 0)
        {
            break;
        }
        curCh = String[1] << 8 | String[0];
        Get_CharWidthHeight_internal((U32) curCh, &chDwidth, &chWidth, &chHeight, &chAscent, &chDescent);
        if (Counter == 0)
        {
            mmi_fe_get_glyph_metrics(curCh, &metrics);
            Italic_tilt = metrics.width - chWidth;
        }
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(curCh))
        {

            {
                curr_char_pos = ire_identify_char_position(curCh);
                switch (curr_char_pos)
                {
                    case IRE_BELOW_AND_POST_BASE_POSITION:
                    case IRE_POSTBASE_POSITION:
                    {
                        /* The width of the character will be returned
                           if any dependent vowel comes as independently */
                        if ((n == 1) && IRE_IS_CHAR_TYPE_DEP_VOWEL(curCh))
                        {
                            pWidth_adv = chWidth;
                            pWidth = chWidth;
                            break;

                        }
                        if ((cluster_last_char == MMI_TRUE) && (Counter == (n - 1)))
                        {
                            (pWidth_adv) += chWidth;
                            pWidth += chWidth;
                            break;

                        }

                        prev_base_char_dwidth = chDwidth;
                        prev_base_char_width = chWidth;
                        pre_base_char_pos = curr_char_pos;
                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;

                        (pWidth) += chDwidth;
                        pWidth_adv += chDwidth;
                        break;

                    }
                    case IRE_POST_BASE_POSITION_REQ_CORRECTION:
                    case IRE_POST_BASE_POSITION_REQ_CORRECTION2:
                    {
                        if ((cluster_last_char == MMI_TRUE) && (Counter == (n - 1)))
                        {
                            (pWidth_adv) += chWidth;
                            (pWidth) += chDwidth;
                            break;

                        }

                        prev_base_char_dwidth = chDwidth;
                        prev_base_char_width = chWidth;
                        pre_base_char_pos = curr_char_pos;
                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;
                        IRE_SET_RENDERING_CORRECTION(curCh);
                        (pWidth) += chDwidth;
                        pWidth_adv += chDwidth;
                        break;
                    }
                        /* The width of the previous base consonant will be taken, 
                           if current character position is above base */
                    case IRE_ABOVE_BASE_POSITION:
                    {

                        S32 temp_move = 0;

                        /* The width of the character will be returned
                           if any sign comes as independently */

                        if ((n == 1) || (Counter == 0))
                        {
                            pWidth_adv = chWidth;
                            pWidth = chWidth;
                            break;

                        }
                        temp_move = (prev_base_char_dwidth < chWidth ? (chWidth - prev_base_char_dwidth) : 0);
                        cursorX = (cursorX < temp_move) ? temp_move : cursorX;

                        /* if (Counter == (n - 1)) */
                        {
                            if ((ire_is_indic_rules_parsing() && (cluster_last_char == MMI_TRUE)) ||
                                (!ire_is_indic_rules_parsing() && IRE_IS_OFFSET_REQUIRED()))
                            {
                                pWidth_adv += temp_move;
                                pWidth += temp_move;

                                pWidth_adv += (prev_base_char_width - prev_base_char_dwidth);
                                pWidth += (prev_base_char_width - prev_base_char_dwidth);
                            }
                        }

                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;

                        break;
                    }
                        /* The width of the previous base consonant will be taken, 
                           if current character position is  below base */
                    case IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE:
                    {
                        S32 temp_move = 0;

                        /* The width of the character will be returned
                           if any sign comes as independently */
                        if ((n == 1) || (Counter == 0))
                        {
                            pWidth_adv = chWidth;
                            pWidth = chWidth;
                            break;

                        }
                        temp_move = (prev_base_char_dwidth < chWidth ? (chWidth - prev_base_char_dwidth) : 0);
                        cursorX = (cursorX < temp_move) ? temp_move : cursorX;

                        if (Counter == (n - 1))
                        {
                            if ((ire_is_indic_rules_parsing() && (cluster_last_char == MMI_TRUE)) ||
                                (!ire_is_indic_rules_parsing() && IRE_IS_OFFSET_REQUIRED()))
                            {
                                pWidth_adv += temp_move;
                                pWidth_adv += (prev_base_char_width - prev_base_char_dwidth);
                                pWidth += temp_move;
                            }
                        }
                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;

                        IRE_RESET_RENDERING_CORRECTION();
                        IRE_RESET_SMALL_CONSONANT_FLAG();
                        break;
                    }

                    case IRE_BELOW_BASE_POSITION:
                    {
                        U32 temp_move = 0;

                        /* The width of the character will be returned
                           if any sign comes as independently */
                        if (n == 1)
                        {
                            pWidth_adv = chWidth;
                            pWidth = chWidth;
                            break;

                        }

                        if ((pre_char_pos == curr_char_pos) || (pre_char_pos == IRE_BELOW_AND_POST_BASE_POSITION)
                            || (pre_char_pos == IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))

                        {
                            (pWidth_adv) += chDwidth;
                            pWidth += chDwidth;
                            break;
                        }
                        if ((IRE_IS_RENDERING_CORRECTION() &&
                             (pre_base_char_pos == IRE_POST_BASE_POSITION_REQ_CORRECTION)) ||
                            (pre_base_char_pos == IRE_POST_BASE_POSITION_REQ_CORRECTION2))
                        {
                            S32 temp_rendering_width = prev_base_char_dwidth - IRE_IS_RENDERING_CORRECTION();
                            S32 temp_dwidth = chDwidth - temp_rendering_width;
                            S32 temp_width = chWidth - temp_rendering_width;

                            pWidth_adv += ((temp_dwidth > 0)) ? temp_dwidth : 0;
                            pWidth += ((temp_width > 0)) ? temp_width : 0;

                            IRE_RESET_RENDERING_CORRECTION();
                            IRE_RESET_SMALL_CONSONANT_FLAG();
                        }
                        else
                        {
                            if (ire_is_indic_rules_parsing())
                            {
                                if ((cluster_last_char == MMI_TRUE) && Counter == (n - 1))
                                {
                                    temp_move = (prev_base_char_width < chWidth ? (chWidth - prev_base_char_width) : 0);
                                    pWidth_adv += (prev_base_char_width - prev_base_char_dwidth);
                                    pWidth_adv += temp_move;
                                    break;
                                }
                            }
                            else
                            {
                                temp_move = (prev_char_width < chWidth ? (chWidth - prev_char_width) : 0);
                                cursorX = (cursorX < temp_move) ? temp_move : cursorX;
                                /* if(IRE_IS_OFFSET_REQUIRED() && (Counter == (n - 1))) */
                                {
                                    pWidth_adv += temp_move;
                                    pWidth_adv += (prev_base_char_width - prev_base_char_dwidth);
                                }
                            }
                        }

                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;

                        break;
                    }
                    default:
                        (pWidth_adv) += chDwidth;
                        pWidth += chDwidth;
                        prev_base_char_dwidth = chDwidth;
                        prev_base_char_width = chWidth;
                        prev_char_dwidth = chDwidth;
                        prev_char_width = chWidth;
                        break;

                }
            }
        }
        else
        {
            /* For non- Indic characters */
            (pWidth) += chWidth;
            prev_base_char_dwidth = chDwidth;
            prev_base_char_width = chWidth;
        }

        if (chAscent > ascent)
            ascent = chAscent;

        if (chDescent > descent)
            descent = chDescent;

        pre_char_pos = curr_char_pos;

        String += 2;
        Counter++;
    }

    param->pWidth = pWidth + Italic_tilt;
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    param->adv_h = param->pHeight;
    param->adv_w = pWidth_adv;
    return Counter;

}

#endif /* defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

#if defined(__MMI_LANG_THAI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_thai
 * DESCRIPTION
 *  get Thai string information by language
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_thai(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
    U8 *str_end;
    U8 *str_start;
    S32 width = 0, adv_w = 0;
    S32 counter = 0;
    MMI_BOOL enableTruncated = param->enableTruncated;
    S32 targetWidth = param->targetWidth;
    S32 ascent = 0, descent = 0;
    S32 chDescent = 0;
    MMI_BOOL truncated = MMI_FALSE;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S16 pen_position_x = 0;
    U16 curr_ucs, prev_ucs = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_end = param->String + param->n * 2;
    mmi_lm_cluster_init(&prev_cluster);
    mmi_lm_cluster_init(&prev2_cluster);
    mmi_lm_cluster_init(&cluster);

    str_start = param->String;

    while (counter < param->n)
    {
        str_start += cluster.data_len * 2;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        width += (cluster.adv_x + cluster.rx) + param->w + pen_position_x;
#else
        width += (cluster.adv_x + cluster.rx) + param->w;
#endif

        memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
        memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));

        mmi_lm_cluster_init(&cluster);
        cluster.data_ptr = str_start;
        mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);
        if (enableTruncated && targetWidth < width + cluster.adv_x)
        {
            truncated = MMI_TRUE;
            break;
        }
        if ((S32) cluster.by > ascent)
            ascent = (S32) cluster.by;

        chDescent = (S32) (cluster.h - cluster.by);
        if (chDescent > descent)
            descent = chDescent;

        counter += cluster.data_len;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        adv_w += (cluster.adv_x + cluster.rx) + pen_position_x;
#else
        adv_w += (cluster.adv_x + cluster.rx);
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
        curr_ucs = *(cluster.display_buffer);
        mmi_fe_get_kerning_adjustment(prev_ucs, curr_ucs, &pen_position_x);
        if(cluster.cluster_len == 1)
        {
            prev_ucs = curr_ucs;
        }
        else
        {
            prev_ucs = (cluster.display_buffer[cluster.cluster_len - 1]);
        }
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    }

    width += ((cluster.adv_x > cluster.w ? cluster.adv_x : cluster.w) + param->w);

    if (enableTruncated && truncated)
    {
        param->enableTruncated = MMI_FALSE;
    }
    param->adv_w = adv_w;
    param->pWidth = width;
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    return counter;

}
#endif /* defined(__MMI_LANG_THAI__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight
 * DESCRIPTION
 *  To get string width height
 * PARAMETERS
 *  query       [IN/OUT]        The query parameter to indicate the input and output
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction;
    S32 return_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_value = mmi_fe_get_string_widthheight_int(query, &default_direction, NULL, NULL, MMI_TRUE);
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
                query->baseline = query->baseline + gAdvanceFontAttribute.shadow_distant;
            }
            else
            {
                query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.shadow_range);
                query->baseline = query->baseline + gAdvanceFontAttribute.shadow_range;
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            query->baseline = query->baseline + gAdvanceFontAttribute.outerglow_range;
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            query->pWidth = query->pWidth + 2;
            query->pHeight = query->pHeight + 2;
            query->baseline = query->baseline + 1;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.border_size);
            query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.border_size);
            query->baseline = query->baseline + gAdvanceFontAttribute.border_size;
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    return return_value;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_varient
 * DESCRIPTION
 *  To get string width height
 * PARAMETERS
 *  query       [IN/OUT]        The query parameter to indicate the input and output
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_varient(mmi_fe_get_string_info_param_struct_p query)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction;
    U32 temp_return = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // should not BIDI if for line breaking
    // for example text in memory buffer is: 
    // "ABCDEFGabcdefg" (Upper case is arabic character, low case is English character)
    // it will display in visual after BIDI as: abcdefgGFEDCBA
    // if we use the string after BIDI to break line, it will be:
    // | efgGFEDCBA|
    // |       abcd|
    // which is wrong, the last character "efg shows on the first line"
    // the right layout of line break should be
    // | abcFEDCBA|
    // |       efg|
    if (query->targetWidth > 0)
    {
        temp_return = mmi_fe_get_string_widthheight_int(query, &default_direction, NULL, NULL, MMI_FALSE);
    }
    else
    {
        temp_return = mmi_fe_get_string_widthheight_int(query, &default_direction, NULL, NULL, MMI_TRUE);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    return temp_return;
}

#endif /* #ifndef __MMI_SCRIPT_EASY__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_ext
 * DESCRIPTION
 *  To get string width height with callback to save all cluster information
 * PARAMETERS
 *  query           [IN/OUT]        The query parameter to indicate the input and output
 *  direction       [OUT]           String direction
 *  f_save_info     [IN]            Save cluster information function
 *  user_data       [IN]            user data  
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_ext(
        mmi_fe_get_string_info_param_struct_p query,
        U8 *direction,
        fe_save_cluster_info_cb f_save_info,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_return = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (f_save_info)
    {
        temp_return = mmi_fe_get_string_widthheight_int(query, direction, f_save_info, user_data, MMI_TRUE);
    }
    else
    {
        temp_return = mmi_fe_get_string_widthheight_int(query, direction, f_save_info, user_data, MMI_FALSE);
    }
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.shadow_distant);
                query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.shadow_distant);
                query->baseline = query->baseline + gAdvanceFontAttribute.shadow_distant;
            }
            else
            {
                query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.shadow_range);
                query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.shadow_range);
                query->baseline = query->baseline + gAdvanceFontAttribute.shadow_range;
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.outerglow_range);
            query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.outerglow_range);
            query->baseline = query->baseline + gAdvanceFontAttribute.outerglow_range;
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            query->pWidth = query->pWidth + 2;
            query->pHeight = query->pHeight + 2;
            query->baseline = query->baseline + 1;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            query->pWidth = query->pWidth + (2 * gAdvanceFontAttribute.border_size);
            query->pHeight = query->pHeight + (2 * gAdvanceFontAttribute.border_size);
            query->baseline = query->baseline + gAdvanceFontAttribute.border_size;
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    return temp_return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_int
 * DESCRIPTION
 *  To get string width height with callback to save all cluster information
 * PARAMETERS
 *  query           [IN/OUT]        The query parameter to indicate the input and output
 *  direction       [OUT]           String direction
 *  f_save_info     [IN]            Save cluster information function
 *  user_data       [IN]            user data  
 *  is_BIDI         [IN]            need BIDI or not
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_int(
        mmi_fe_get_string_info_param_struct_p query,
        U8 *direction,
        fe_save_cluster_info_cb f_save_info,
        void *user_data,
        MMI_BOOL is_BIDI)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 Counter = 0;
    U32 numofChar = 0;
    U32 shapingNumOfChar = 0;
    S32 ascent = 0, descent = 0;
    U8 *String = query->String;
#if defined(__MMI_ARSHAPING_ENGINE__)
    S32 nLenOrg;
#endif
    S32 nLen;
    mmi_fe_get_string_info_param_struct string_part_param;

#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_BIDI_ALG__)
    S32 check_len = 0;  /* used to check every character in the string */
    U8 *temp_string = String;
#endif /* defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_BIDI_ALG__) */ 
    U8 default_direction = BIDI_L;

#if defined(__MMI_BIDI_ALG__)
    MMI_BOOL IS_BIDI = MMI_FALSE;
    BIDI_PARAGRAPH_TYPES paratype = P_RTL;
    U16 visual_str_len = 0, visual_cur_pos = 0;
#endif /* defined(__MMI_BIDI_ALG__) */ 
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif 
    //S32 lang_string_group = 0;
    //U8 *lang_string_start = NULL;
    MMI_BOOL enableTruncated = query->enableTruncated;
    S32 targetWidth = query->targetWidth;
#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_BIDI_ALG__)
    MMI_BOOL is_shaping_tbl_done = MMI_FALSE;
    MMI_BOOL is_bidi_tbl_done = MMI_FALSE;
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
    MMI_BOOL is_kerning_supported = MMI_FALSE;
#endif
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    mmi_fe_text_format_struct_p pRechTextFormat = NULL;
    BOOL text_format_undleline = MMI_FALSE;
#endif
#if (defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__))
    FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
    mmi_fe_cache_string_info *cache_string_info_p = &cache_string_info;
    mmi_fe_cache_cluster_info *cluster_info_p = cache_string_info_p->cluster_info;
    UI_string_type cluster_string_p = cache_string_info_p->cluster_string;
    U32 bidi_param = 0;
    U32 truncated_param = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialization */
    query->pHeight = 0;
    query->pWidth = 0;
    query->baseline = 0;
#if defined(__MMI_ARSHAPING_ENGINE__)
    nLenOrg = query->n;
#endif
    nLen = query->n;
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    pRechTextFormat = query->format;
#endif
    /* error check */
    if (String == NULL || nLen <= 0 || (enableTruncated && targetWidth == 0))
    {
        return numofChar;
    }
    FE_SWLA_START("FEQ");
    GDI_LOCK;
    FE_LOCK;

#if (defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__))
    if(!f_save_info)
    {
        if(is_BIDI)
            bidi_param = FE_TAG_MAKER('b','i','d','i');
        
        if(query->enableTruncated)
        {
            truncated_param = FE_HASH_CAL(truncated_param, targetWidth);

            if(query->checklinebreak)
               truncated_param = FE_HASH_CAL(truncated_param, FE_TAG_MAKER('c','k','l','b'));

            if(query->checkCompleteWord)
               truncated_param = FE_HASH_CAL(truncated_param, FE_TAG_MAKER('c','k','c','w'));
        }
        mmi_fe_cache_key_maker((UI_string_type)query->String, query->n, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, MMI_FALSE, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_INFO, bidi_param, truncated_param, 0, pRechTextFormat, &mmi_fe_key);

        if(mmi_fe_cache_tree_find(&mmi_fe_key, (void **)(&cache_string_info_p), NULL))
        {
            query->adv_w = cache_string_info_p->string_info_header.adv_w;
            query->adv_h = cache_string_info_p->string_info_header.adv_h;
            query->maxAscent = cache_string_info_p->string_info_header.maxAscent;
            query->maxDescent = cache_string_info_p->string_info_header.maxDescent;
            query->baseline = cache_string_info_p->string_info_header.baseline;
            query->pWidth = cache_string_info_p->string_info_header.pWidth;
            query->pHeight = cache_string_info_p->string_info_header.pHeight;

            FE_UNLOCK;
            GDI_UNLOCK;
            FE_SWLA_STOP("FEQ");
            return cache_string_info_p->string_info_header.numofChar;
        }
    }

    memset(&cache_string_info, 0, sizeof(cache_string_info));
#endif

#if 1//defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__)
    if (nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH)
    {
#if defined(__MMI_ARSHAPING_ENGINE__)
        nLenOrg = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
#endif
        nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
    }
#endif /* defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__) */ 

#if defined(__MMI_BIDI_ALG__)
    mmi_fe_get_display_direction(String, &default_direction, nLen);

    temp_string = String;
    check_len = nLen;
    while (check_len != 0)
    {
        U8 dic = 0;
        U16 unicode = 0;

        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

    #if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
    #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 

        bidi_get_char_type((U8*) (&unicode), &dic);

        if (dic == BIDI_R || dic == AL || dic == AN || dic == WS)
        {
            IS_BIDI = MMI_TRUE;
        }

        if (IS_BIDI
    #if defined(__MMI_ARSHAPING_ENGINE__)
            && IS_ARABIC
    #endif 
            )
            break;
        temp_string += 2;
    }

#endif /* defined(__MMI_BIDI_ALG__) */ 

    /* check if shaping is necessary */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC)
    {
        mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String, nLen);
        show_pwcWord[nLen] = 0;
        nLenOrg = nLen = mmi_ucs2strlen((const char*)show_pwcWord);
        if (enableTruncated || f_save_info)
        {
            S32 i;
            for (i = 0; i < nLen; i++)
                fe_ShaToOrg[i] = i;
            fe_ShaToOrg[nLen] = 0;

            ArabicShapeEngine2_ext((U16*) & nLen, (U16*) show_pwcWord, NULL, fe_ShaToOrg);
            is_shaping_tbl_done = MMI_TRUE;
        }
        else
        {
            ArabicShapeEngine_ext((U16*) & nLen, (U16*) show_pwcWord);
        }
        String = (U8*) show_pwcWord;
    }
#endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 

#if defined(__MMI_BIDI_ALG__)
    if (is_BIDI)
    {
        if (IS_BIDI || default_direction == BIDI_R || query->assign_direction == BIDI_R)
        {
            if ((default_direction == BIDI_R) || (query->assign_direction == BIDI_R))
            {
                paratype = P_RTL;
            }
            else
            {
                paratype = P_LTR;
            }
            if (f_save_info)
            {
                bidi_main_ext(
                    String,
                    (U16) nLen,
                    0,
                    show_visual_str,
                    &visual_str_len,
                    &visual_cur_pos,
                    fe_l2v_map,
                    fe_v2l_map,
                    MMI_FALSE,
                    MMI_bidi_input_type,
                    MMI_FALSE,
                    paratype);
                is_bidi_tbl_done = MMI_TRUE;
            }
            else
            {
                bidi_main_ext(
                    String,
                    (U16) nLen,
                    0,
                    show_visual_str,
                    &visual_str_len,
                    &visual_cur_pos,
                    NULL,
                    NULL,
                    MMI_FALSE,
                    MMI_bidi_input_type,
                    MMI_FALSE,
                    paratype);
            }
            String = (U8*) show_visual_str;
        }
        else
        {
            mmi_ucs2ncpy((S8*) show_visual_str, (S8*) String, nLen);
            String = (U8*) show_visual_str;
        }
    }
#endif /* defined(__MMI_BIDI_ALG__) */ 

    //lang_string_start = String;
    //lang_string_group = 0;

    memcpy(&string_part_param, query, sizeof(mmi_fe_get_string_info_param_struct));

    {
        mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
        U8 *str_end;
        U8 *str_start;
        S32 width = 0, adv_w = 0;
        S32 prev_space_width = 0;
        //S32 prev_space_height = 0;
        S32 prev_space_index = -1;
        S32 prev_adv_w = 0;
        S32 prev_ascent = 0, prev_descent = 0;
        S32 chDescent = 0;
#if defined(__MMI_BIDI_ALG__)
        U16 unicodeCheck = 0;
        U8  dicCheck = 0;
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
        S16 pen_position_x = 0;
        U16 curr_ucs, prev_ucs = 0;
        U16 curr_ucs_char;
        //U16 curr_ucs_index;
        S32 adjustment_x = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
        U32 start_index = 0;
        U32 end_index = 0;
#endif

        str_start = String;
        str_end = String + nLen * 2;
        mmi_lm_cluster_init(&prev_cluster);
        mmi_lm_cluster_init(&prev2_cluster);
        mmi_lm_cluster_init(&cluster);
        do
        {
            str_start += cluster.data_len * 2;

        #if defined(__MMI_VECTOR_FONT_KERNING__)
            //curr_ucs_char = *str_start;//((String[0]) | (String[1] << 8));
            curr_ucs_char = ((str_start[0]) | (str_start[1] << 8));
            /*curr_ucs_index = */font_engine->get_glyph_index(curr_ucs_char);
            //if(curr_ucs_index == 0)
            {
                mmi_fe_set_active_font(curr_ucs_char, MMI_FALSE);
            }
            is_kerning_supported = font_engine->is_kerning();
        #endif /* __MMI_VECTOR_FONT_KERNING__ */

            /* variable initialize */
            memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
            memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));
            mmi_lm_cluster_init(&cluster);

            cluster.data_ptr = str_start;
            mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
            pRechTextFormat = query->format;
            if(pRechTextFormat)
            {
                start_index = numofChar;
                end_index = start_index + cluster.data_len;

                   /* Convert the visiual index to logical index for BIDI and Shapping */
            #if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
                if (is_shaping_tbl_done && is_bidi_tbl_done)
                {
                    /* convert index from BIDI and shapping table */
                    start_index = fe_ShaToOrg[fe_v2l_map[numofChar]];
                    if ((fe_v2l_map[numofChar] + cluster.data_len) < nLen)
                    {
                        end_index = start_index + (fe_ShaToOrg[fe_v2l_map[numofChar] + cluster.data_len] - fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                    else
                    {
                        end_index = start_index + (nLenOrg - fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__) */ 
            #if defined(__MMI_ARSHAPING_ENGINE__)
                if (is_shaping_tbl_done && !is_bidi_tbl_done)
                {
                    /* convert index from shapping table */
                    start_index = fe_ShaToOrg[numofChar];
                    if ((numofChar + cluster.data_len) < nLen)
                    {
                        end_index = start_index + (fe_ShaToOrg[numofChar + cluster.data_len] - fe_ShaToOrg[numofChar]);
                    }
                    else
                    {
                        end_index = start_index + (nLenOrg - fe_ShaToOrg[numofChar]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 
            #if defined(__MMI_BIDI_ALG__)
                if (is_bidi_tbl_done && !is_shaping_tbl_done)
                {
                    /* convert index from BIDI table */
                    start_index = fe_v2l_map[numofChar];
                    end_index = start_index + cluster.data_len;
                }
            #endif /* defined(__MMI_BIDI_ALG__) */ 

                while(pRechTextFormat)
                {
                    if((start_index >= pRechTextFormat->start)&&(end_index <= pRechTextFormat->end))
                    {
                        stFontAttribute font;
                        U8 arrCount;
                        mmi_fe_color c;
                        GetFont(&font, &arrCount);
                        c = mmi_fe_get_text_color();
                        if(pRechTextFormat->font.underline == MMI_TRUE)
                            text_format_undleline = MMI_TRUE;
                        SetFont(pRechTextFormat->font, arrCount);
                        mmi_fe_set_text_color(pRechTextFormat->c);
                        mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);
                        SetFont(font, arrCount);
                        mmi_fe_set_text_color(c);
                        break;
                    }
                    pRechTextFormat = pRechTextFormat->next;
                }
            }
#endif
            /* [Vector font] a special process to make sure if the space is in the end of the string, the cursor move would be included. */
        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            if (!cluster.w && cluster.adv_x)
                cluster.w = cluster.adv_x;
        #endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

            if (query->enableTruncated)
            {
                UI_character_type curCh;
                //S32 maxW = cluster.w > cluster.adv_x ? cluster.w : cluster.adv_x;

                curCh = ((cluster.data_ptr[0]) | (cluster.data_ptr[1] << 8));

                if (query->checklinebreak)
                {
                    if (FONT_TEST_NEW_LINE_CHAR(curCh))
                    {
                        goto GET_STRING_WIDTHHEIGH;
                    }
                }
                if (query->checkCompleteWord)
                {
                    /* check disconnect */
                    if (cluster.is_connect == MMI_LM_CLUSTER_ATTR_DISCONNECT)
                    {
                        prev_space_index = numofChar;
                        //prev_space_height = ascent + descent;
                        prev_space_width = width;   /* + cluster.w + query->w + cluster.rx; */
                        prev_ascent = ascent;
                        prev_descent = descent;
                        prev_adv_w = adv_w;         /* + cluster.adv_x + query->w + cluster.rx; */
                    }

                    // word wrapping if operator character
                    // checkCompleteWord = 2 for operator wrapping
                    if (query->checkCompleteWord == 2 && FONT_TEST_OPERATOR_CHAR(curCh))
                    {
                        if (targetWidth >= adv_w + cluster.w)
                        {
                            prev_space_index = numofChar + 1;
                            //prev_space_height = ascent + descent;
                            prev_ascent = ascent;
                            prev_descent = descent;
                            prev_space_width = adv_w + cluster.w + query->w + cluster.rx;
                            prev_adv_w = adv_w + cluster.adv_x + query->w + cluster.rx;
                        }
                        else
                        {
                            prev_space_index = numofChar;
                            //prev_space_height = ascent + descent;
                            prev_ascent = ascent;
                            prev_descent = descent;
                            prev_space_width = width;
                            prev_adv_w = adv_w;
                        }
                    }
                }

                /* Use max value of adv_x and width to do line break */
                if (targetWidth < adv_w + cluster.w/*maxW*/)
                {
                    /* if there is one space in previous, restore the data back to the space. */
                    if (query->checkCompleteWord && prev_space_index > 0)
                    {
                        numofChar = prev_space_index;
                        adv_w = prev_adv_w;
                        width = prev_space_width;
                        ascent = prev_ascent;
                        descent = prev_descent;
                    }
                    goto GET_STRING_WIDTHHEIGH;
                }
            }
            else
            {
                UI_character_type curCh;
                curCh = ((cluster.data_ptr[0]) | (cluster.data_ptr[1] << 8));
                if ((FONT_TEST_NEW_LINE_CHAR(curCh)) && ((numofChar + cluster.data_len) >= nLen))
                {
                    goto GET_STRING_WIDTHHEIGH;
                }
            }
            if ((S32) cluster.by > ascent)
                ascent = (S32) cluster.by;

            chDescent = (S32) (cluster.h - cluster.by);
            if (chDescent > descent)
                descent = chDescent;

            if (((prev_cluster.lang_id == MMI_LM_LANG_ARABIC && cluster.lang_id != MMI_LM_LANG_ARABIC) ||
                 (prev_cluster.lang_id != MMI_LM_LANG_ARABIC && cluster.lang_id == MMI_LM_LANG_ARABIC)))
                adv_w++;

            /* Get cluster info */
            if (f_save_info)
            {
                mmi_fe_cluster_metrics_struct metric;

                memset(&metric, 0, sizeof(mmi_fe_cluster_metrics_struct));
                metric.index = numofChar;
                metric.len = (U8) (cluster.data_len);

                /* Convert the visiual index to logical index for BIDI and Shapping */
            #if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
                if (is_shaping_tbl_done && is_bidi_tbl_done)
                {
                    /* convert index from BIDI and shapping table */
                    metric.index = fe_ShaToOrg[fe_v2l_map[numofChar]];
                    if ((fe_v2l_map[numofChar] + cluster.data_len) < nLen)
                    {
                        metric.len =
                            (U8) (fe_ShaToOrg[fe_v2l_map[numofChar] + cluster.data_len] -
                                  fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                    else
                    {
                        metric.len = (U8) (nLenOrg - fe_ShaToOrg[fe_v2l_map[numofChar]]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__) */ 
            #if defined(__MMI_ARSHAPING_ENGINE__)
                if (is_shaping_tbl_done && !is_bidi_tbl_done)
                {
                    /* convert index from shapping table */
                    metric.index = fe_ShaToOrg[numofChar];
                    if ((numofChar + cluster.data_len) < nLen)
                    {
                        metric.len = (U8) (fe_ShaToOrg[numofChar + cluster.data_len] - fe_ShaToOrg[numofChar]);
                    }
                    else
                    {
                        metric.len = (U8) (nLenOrg - fe_ShaToOrg[numofChar]);
                    }
                }
            #endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 
            #if defined(__MMI_BIDI_ALG__)
                if (is_bidi_tbl_done && !is_shaping_tbl_done)
                {
                    /* convert index from BIDI table */
                    metric.index = fe_v2l_map[numofChar];
                }
            #endif /* defined(__MMI_BIDI_ALG__) */ 

                metric.x = adv_w;
                metric.width = (U8) (cluster.w);
                metric.adv_w = (U8) (cluster.adv_x);
                if (((prev_cluster.lang_id == MMI_LM_LANG_ARABIC && cluster.lang_id != MMI_LM_LANG_ARABIC) ||
                 (prev_cluster.lang_id != MMI_LM_LANG_ARABIC && cluster.lang_id == MMI_LM_LANG_ARABIC)))
                {
                    metric.x--;
                    metric.adv_w++;
                }
            #if defined(__MMI_BIDI_ALG__)
                unicodeCheck = cluster.data_ptr[0];
                unicodeCheck |= (cluster.data_ptr[1] << 8);
                bidi_get_char_type((U8*) (&unicodeCheck), &dicCheck);
                metric.bidi_type = dicCheck;
            #endif
                f_save_info(metric, user_data);

                shapingNumOfChar += metric.len;
            }
            else
            {
                shapingNumOfChar += cluster.data_len;
            }
#if defined(__MMI_VECTOR_FONT_KERNING__)
            if(is_kerning_supported)
            {
                if(mmi_fe_get_lang_id(*(cluster.display_buffer)) == MMI_FE_LANG_OTHERS)
                {
                    curr_ucs = *(cluster.display_buffer);
                    mmi_fe_get_kerning_adjustment(prev_ucs, curr_ucs, &pen_position_x);
                    if(cluster.cluster_len == 1)
                    {
                        prev_ucs = curr_ucs;
                    }
                    else
                    {
                        prev_ucs = (cluster.display_buffer[cluster.cluster_len - 1]);
                    }
                    width = adv_w + cluster.w + query->w + cluster.rx + pen_position_x;
                    adv_w += cluster.adv_x + query->w + cluster.rx + pen_position_x;
                    adjustment_x = pen_position_x;
                }
                else
                {
                    width = adv_w + cluster.w + query->w + cluster.rx;
                    adv_w += cluster.adv_x + query->w + cluster.rx;
                    adjustment_x = 0;
                }
            }
            else
            {
                width = adv_w + cluster.w + query->w + cluster.rx;
                adv_w += cluster.adv_x + query->w + cluster.rx;
                adjustment_x = 0;
            }
#else
            width = adv_w + cluster.w + query->w + cluster.rx;
            adv_w += cluster.adv_x + query->w + cluster.rx;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            
            numofChar += cluster.data_len;

#if (defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__))
            cache_string_info_p->string_info_header.cluster_string_len += cluster.cluster_len;
            cache_string_info_p->string_info_header.cluster_info_len++;

#if defined(__MMI_VECTOR_FONT_KERNING__)
            cluster_info_p->adjustment_x = adjustment_x;
#endif
            cluster_info_p->w = cluster.w;
            cluster_info_p->h = cluster.h;
            cluster_info_p->adv_x = cluster.adv_x;
            cluster_info_p->adv_y = cluster.adv_y;
            cluster_info_p->bx = cluster.bx;
            cluster_info_p->by = cluster.by;
            cluster_info_p->rx = cluster.rx;
            cluster_info_p->ry = cluster.ry;
            
            cluster_info_p->is_gap = cluster.is_gap;
            cluster_info_p->is_connect = cluster.is_connect;
            cluster_info_p->data_len = cluster.data_len;
            cluster_info_p->cluster_len = cluster.cluster_len;
            cluster_info_p->lang_id = cluster.lang_id;

            cluster_info_p++;

            memcpy(cluster_string_p, cluster.display_buffer, cluster.cluster_len*sizeof(UI_character_type));
            cluster_string_p += cluster.cluster_len;
#endif
        } while (numofChar < nLen);
      GET_STRING_WIDTHHEIGH:
        if (!width && adv_w)
            width = adv_w;
        query->adv_w = adv_w;
        query->adv_h = ascent + descent;
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)
        if(g_mmi_fe_curr_available_font_family == FONT_FAMILY_FIXED_WIDTH)
        {
            query->pWidth = adv_w; 
        }
        else
#endif            
        {
            query->pWidth = width;
        }
        query->baseline = ascent;
        query->maxAscent = ascent;
        query->maxDescent = descent;
        query->pHeight = ascent + descent;
    }
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query->pWidth && !query->pHeight)
    {
        S32 zHeight = 0;
        S32 zAscent = 0;
        S32 zDescent = 0;
        mmi_fe_get_char_info_of_common_lang(FONT_PIXEL_SIZE(font_engine_font_pixel), &zHeight, &zAscent, &zDescent);
        query->pHeight = zHeight;
        query->baseline = zAscent;
        query->maxAscent = zAscent;
        query->maxDescent = zDescent;
    }
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
    /* because the underline is drawn in the bottom of the string. */
    if ((gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
#if defined(__MMI_FE_RICH_TEXT_SUPPORT__)
    ||(text_format_undleline)
#endif
        )
    {
        query->pHeight++;
    }
    if (gFontEffect & FONT_EFFECT_ENGRAVE)
    {
        query->pHeight++;
    }

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (f_save_info && is_shaping_tbl_done)
    {
        numofChar = shapingNumOfChar;
    }
    else if (IS_ARABIC && enableTruncated)
    {
        if (numofChar == nLen)
        {
            // return all text length
            numofChar = nLenOrg;
        }
        else
        {
            // return next char's position
            numofChar = fe_ShaToOrg[numofChar];
        }
    }
#endif /* defined(__MMI_ARSHAPING_ENGINE__) */ 

#if (defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__))
    //if(!f_save_info)
    {
        mmi_fe_cache_key_maker((UI_string_type)query->String, query->n, ot_lang, font_engine_font_attr, font_engine_font_size, ot_script, MMI_FALSE, g_mmi_fe_font_family, MMI_FE_CACHE_TYPE_STRING_INFO, bidi_param, truncated_param, 0, pRechTextFormat, &mmi_fe_key);

        if(!mmi_fe_cache_tree_find(&mmi_fe_key, (void **)(&cache_string_info_p), NULL))
        {
            cache_string_info_p->string_info_header.adv_w = query->adv_w;
            cache_string_info_p->string_info_header.adv_h = query->adv_h;
            cache_string_info_p->string_info_header.maxAscent = query->maxAscent;
            cache_string_info_p->string_info_header.maxDescent = query->maxDescent;
            cache_string_info_p->string_info_header.baseline = query->baseline;
            cache_string_info_p->string_info_header.pWidth = query->pWidth;
            cache_string_info_p->string_info_header.pHeight = query->pHeight;
            cache_string_info_p->string_info_header.numofChar = numofChar;

            mmi_fe_cache_tree_save_string_info(&mmi_fe_key, cache_string_info_p, FE_FOUR_BYTE_ALIGN(sizeof(mmi_fe_cache_string_info_header)+sizeof(mmi_fe_cache_cluster_info)*cache_string_info_p->string_info_header.cluster_info_len+sizeof(UI_character_type)*cache_string_info_p->string_info_header.cluster_string_len));
        }
    }
#endif
        
    FE_UNLOCK;
    GDI_UNLOCK;

    if (direction)
    {
        *direction = default_direction;
    }
    FE_SWLA_STOP("FEQ");
    return numofChar;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeight
 * DESCRIPTION
 *  To get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32    the char height
 *****************************************************************************/
S32 Get_CharHeight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    height = font_engine_font_pixel;
#else 
    height = (S32) gpCurrentFont->nHeight;
#endif 
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            height = height + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            height = height + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            height = height + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    GDI_UNLOCK;
    return height;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightofAllType
 * DESCRIPTION
 *  To get char height for current font
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 the height
 *****************************************************************************/
S32 Get_CharDisplayHeightofAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height, ascent, descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
    if (font_engine->get_font_info(0xff, font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#else
    if (font_engine->get_font_info(font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#endif
    {
        ret = height + 2;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        ret = (S32) (gpCurrentFont->nHeight + 2);
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif 
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                ret = ret + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                ret = ret + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            ret = ret + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            ret = ret + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            ret = ret + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharAscent
 * DESCRIPTION
 *  To get char ascent
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the ascent for the char
 *****************************************************************************/
S32 Get_CharAscent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    S32 height, ascent, descent;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
    if (font_engine->get_font_info(0xff, font_engine_font_pixel, &height, &ascent, &descent, MMI_FALSE))
#else
    if (font_engine->get_font_info(font_engine_font_pixel, &height, &ascent, &descent, MMI_FALSE))
#endif
    {
        ret = ascent;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        ret = (S32) gpCurrentFont->nAscent;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);
#endif
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif 
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  Get_CharDescent
 * DESCRIPTION
 *  To get char descent
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the descent for the char
 *****************************************************************************/
S32 Get_CharDescent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height, ascent, descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
    if (font_engine->get_font_info(0xff, font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#else
    if (font_engine->get_font_info(font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#endif
    {
        ret = descent;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        ret = (S32) gpCurrentFont->nDescent;
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayDescentOfAllType
 * DESCRIPTION
 *  To get maximum char descent regardless of language and font attribute for current font
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the descent
 *****************************************************************************/
S32 Get_CharDisplayDescentOfAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height, ascent, descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
    if (font_engine->get_font_info(0xff, font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#else
    if (font_engine->get_font_info(font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#endif
    {
        ret = descent + 1;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        mmi_fe_get_char_info_of_all_lang((U8) gnCurrentFont, &height, &ascent, &descent);
        ret = descent + 1;
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayAscentOfAllType
 * DESCRIPTION
 *  To get maximum char ascent regardless of language and font attribute for current font
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the ascent
 *****************************************************************************/
S32 Get_CharDisplayAscentOfAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height, ascent, descent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
    if (font_engine->get_font_info(0xff, font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#else
    if (font_engine->get_font_info(font_engine_font_pixel, &height, &ascent, &descent, MMI_TRUE))
#endif
    {
        ret = ascent + 1;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        mmi_fe_get_char_info_of_all_lang((U8) gnCurrentFont, &height, &ascent, &descent);
        ret = ascent + 1;
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack();  /* if overflow , assert it */
#endif 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char height regardless of language and font attribute
 * PARAMETERS
 *  size        [IN]        The font size
 * RETURNS
 *  S32  the height
 *****************************************************************************/
S32 Get_CharDisplayHeightOfAllLangAndType(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent, descent, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &descent);
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            height = height + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            height = height + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            height = height + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    GDI_UNLOCK;
    return height + 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_lang
 * DESCRIPTION
 *  Judge whether language uses this font data.
 * PARAMETERS
 *  lang_ssc        [?]         
 *  size            [IN]        
 *  pheight         [?]         
 *  pascent         [?]         
 *  pdescent        [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fe_get_char_info_of_lang(char *lang_ssc, U8 size, S32 *pheight, S32 *pascent, S32 *pdescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //int i = 0;
    const font_group_struct *font_group = NULL;
    S32 nFontCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Search in mtk_gLanguageArray to check if this language is opened. */

    /*for (i = 0; i < gMaxDeployedLangs; i++)
    {
        if (!strcmp((char*)(gLanguageArray[i].aLangCountryCode), lang_ssc))
        {
            break;
        }
    }
    if (i >= gMaxDeployedLangs)
    {
        *pheight = 0;
        *pascent = 0;
        *pdescent = 0;
        return MMI_FALSE;
    }*/
    if (size & 0x80)
    {
        size &= 0x7f;
        size = mmi_fe_pixel_to_size(size);
    }

    font_group = &gfontfamily[size];
    for (nFontCount = 0; nFontCount < font_group->nTotalFonts; nFontCount++)
    {
        if (mmi_fe_get_language_by_font_data((font_group->fontData[nFontCount]), (const U8 *)lang_ssc))
        {
            *pascent = (S32) font_group->fontData[nFontCount]->nAscent;
            *pdescent = (S32) font_group->fontData[nFontCount]->nDescent;
            *pheight = (S32) font_group->fontData[nFontCount]->nHeight;
            return MMI_TRUE;
        }
    }

    *pheight = 0;
    *pascent = 0;
    *pdescent = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_language_by_font_data
 * DESCRIPTION
 *  Judge whether language uses this font data.
 * PARAMETERS
 *  font_data       [?]         
 *  lan_ssc         [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fe_get_language_by_font_data(const sCustFontData *font_data, const U8 *lan_ssc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 language_index = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gMaxDeployedLangs <= 31);
    if (font_data != NULL)
    {
        /* Search in mtk_gLanguageArray to check if this language is opened. */
        for (i = 0; i < gMaxDeployedLangs; i++)
        {
            if (!strcmp((const char *)(gLanguageArray[i].aLangCountryCode), (const char *)lan_ssc))
            {
                break;
            }
        }
        if (i >= gMaxDeployedLangs)
        {
            return MMI_FALSE;
        }

        /* Search in g_latin_language_country_code_table to check if this language is Latin */
        for (i = 0; i < sizeof(g_latin_language_country_code_table) / sizeof(char*); i++)
        {
            if (!strcmp((const char *)g_latin_language_country_code_table[i], (const char *)lan_ssc))
            {
                break;
            }
        }

        /* language_flag is begin with 1, and language_index is begin with 0. */
        if (i < sizeof(g_latin_language_country_code_table) / sizeof(char*))
        {
            language_index = 0;
        }
        else
        {
            /* Not Latin language, so get this language index in gLanguageArray table */
            for (i = 0; i < gMaxDeployedLangs; i++)
            {
                if (!strcmp((const char *)gLanguageArray[i].aLangCountryCode, (const char *)lan_ssc))
                {
                    break;
                }
            }
            if (i < gMaxDeployedLangs)
            {
                language_index = i;
            }
        }
        /* language_flag is begin with 1, and language_index is begin with 0. */
        if (font_data->language_flag & (1 << language_index))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_all_lang
 * DESCRIPTION
 *  To get maximum char height, ascent and descent for a specifed size regardless of language
 * PARAMETERS
 *  size            [IN]        The specified size
 *  pheight         [?]         
 *  pascent         [?]         
 *  pdescent        [?]         
 *  ascent(?)       [OUT]       The ascent
 *  descent(?)      [OUT]       The descent
 *  height(?)       [OUT]       The height
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_get_char_info_of_all_lang(U8 size, S32 *pheight, S32 *pascent, S32 *pdescent)
{
#ifdef __MMI_SCRIPT_EASY__
    se_mtk_get_char_info_of_all_lang(size, pheight, pascent, pdescent);
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    S32 lang_index;
#else
    S32 nFontCount = 0;
    const font_group_struct *font_group = NULL;
    //U8 language_ssc[6] = "th-TH";
#endif
    S32 ascent = 0, descent = 0, max_ascent = 0, max_descent = 0;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    static U8 cache_size = 0;
    static S32 cache_height = 0;
    static S32 cache_ascent = 0;
    static S32 cache_descent = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if(size == cache_size)
    {
        *pheight = cache_height;
        *pascent = cache_ascent;
        *pdescent = cache_descent;

        return;
    }

    cache_size = size;
#endif
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        S32 height = 0;

        GDI_LOCK;
        for (lang_index = 0; lang_index < g_mmi_fe_font_file_number[g_mmi_fe_font_family]; lang_index++)
        {
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
            if (font_engine->get_font_info(g_mmi_fe_curr_font_list[lang_index], mmi_fe_size_to_pixel(size), &height, &ascent, &descent, MMI_FALSE))
#else
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[lang_index], lang_index);
            if (font_engine->get_font_info(mmi_fe_size_to_pixel(size), &height, &ascent, &descent, MMI_FALSE))
#endif
            {
                if (max_ascent < ascent)
                    max_ascent = ascent;
                if (max_descent < descent)
                    max_descent = descent;
            }
        }
        cache_height = *pheight = (max_ascent + max_descent);
        cache_ascent = *pascent = max_ascent;
        cache_descent = *pdescent = max_descent;
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
        GDI_UNLOCK;
        return;
    }
#else /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    if (size & 0x80)
    {
        size &= 0x7f;
        size = mmi_fe_pixel_to_size(size);
    }

    font_group = &gfontfamily[size];
    for (nFontCount = 0; nFontCount < font_group->nTotalFonts; nFontCount++)
    {
        ascent = (S32) font_group->fontData[nFontCount]->nAscent;
        descent = (S32) font_group->fontData[nFontCount]->nDescent;
    #if defined(__MMI_LANG_THAI__)
        /*
         * if (!memcmp(&gLanguageArray[lang_index].aLangCountryCode, "th-TH", 5))
         * {
         * ascent++;
         * }
         */
        if (mmi_fe_get_language_by_font_data((font_group->fontData[nFontCount]), "th-TH"))
        {
            ascent++;
        }
    #endif /* defined(__MMI_LANG_THAI__) */ 
        //mmi_fe_get_language_by_font_data((font_group->fontData[nFontCount]), language_ssc);
        if (ascent > max_ascent)
        {
            max_ascent = ascent;
        }
        if (descent > max_descent)
        {
            max_descent = descent;
        }
    }
    /*
     * #if defined(__MMI_FONT_MULTIPLE_PROPRIETARY_SUPPORT__)
     * pFontFamily = (sFontFamily*)&gMTKProprietaryFontFamily;
     * if (max_ascent < (S32)pFontFamily->fontData[size]->nAscent)
     * {
     * max_ascent = (S32)pFontFamily->fontData[size]->nAscent;
     * }
     * 
     * if (max_descent < (S32)pFontFamily->fontData[size]->nDescent)
     * {
     * max_descent = (S32)pFontFamily->fontData[size]->nDescent;
     * }
     * 
     * #if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
     * pFontFamily = (sFontFamily*)&gZiExtraCharacterFontFamily;
     * if (max_ascent < (S32)pFontFamily->fontData[size]->nAscent)
     * {
     * max_ascent = (S32)pFontFamily->fontData[size]->nAscent;
     * }    
     * if (max_descent < (S32)pFontFamily->fontData[size]->nDescent)
     * {
     * max_descent = (S32)pFontFamily->fontData[size]->nDescent;
     * }
     * #endif
     * 
     * #else
     * if (max_ascent < (S32) gMTKProprietaryFont.nAscent)
     * {
     * max_ascent = (S32) gMTKProprietaryFont.nAscent;
     * }
     * if (max_descent < (S32) gMTKProprietaryFont.nDescent)
     * {
     * max_descent = (S32) gMTKProprietaryFont.nDescent;
     * }
     * 
     * #if defined(__MMI_ZI__) && (defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__))
     * if (max_ascent < (S32) gZiExtraCharacter.nAscent)
     * {
     * max_ascent = (S32) gZiExtraCharacter.nAscent;
     * }
     * if (max_descent < (S32) gZiExtraCharacter.nDescent)
     * {
     * max_descent = (S32) gZiExtraCharacter.nDescent;
     * }
     * #endif // defined(__MMI_ZI__) 
     */
    // #endif

    *pheight = (max_ascent + max_descent);
    *pascent = max_ascent;
    *pdescent = max_descent;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* __MMI_SCRIPT_EASY__ */
}


#ifdef __MMI_SCRIPT_EASY__

void mmi_fe_get_char_info_of_common_lang(U8 size, S32* pheight, S32* pascent, S32* pdescent)
{
    mmi_fe_get_char_info_of_all_lang(size, pheight, pascent, pdescent);
}

#else /* __MMI_SCRIPT_EASY__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_common_lang
 * DESCRIPTION
 *  To get maximum char height, ascent and descent for a specifed size of common language
 * PARAMETERS
 *  size            [IN]        The specified size
 *  pheight         [?]         
 *  pascent         [?]         
 *  pdescent        [?]         
 *  ascent(?)       [OUT]       The ascent
 *  descent(?)      [OUT]       The descent
 *  height(?)       [OUT]       The height
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_get_char_info_of_common_lang(U8 size, S32 *pheight, S32 *pascent, S32 *pdescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    S32 lang_index;
    S32 ascent = 0, descent = 0, max_ascent = 0, max_descent = 0, height = 0;
    S32 ascent0 = 0, descent0 = 0;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        GDI_LOCK;
        for (lang_index = 0; lang_index < g_mmi_fe_font_file_number[g_mmi_fe_font_family]; lang_index++)
        {
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__)
            if (font_engine->get_font_info(g_mmi_fe_curr_font_list[lang_index], mmi_fe_size_to_pixel(size), &height, &ascent, &descent, MMI_FALSE))
#else
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[lang_index], lang_index);
            if (font_engine->get_font_info(mmi_fe_size_to_pixel(size), &height, &ascent, &descent, MMI_FALSE))
#endif
            {
                if (lang_index == 0)
                {
                    ascent0 = ascent;
                    descent0 = descent;
                }

                if (height == mmi_fe_size_to_pixel(size))   /* exclude the special language */
                {
                    if (max_ascent < ascent)
                        max_ascent = ascent;
                    if (max_descent < descent)
                        max_descent = descent;
                }
            }
        }

        if (max_ascent == 0 && max_descent == 0)
        {
            max_ascent = ascent0;
            max_descent = descent0;
        }

        *pheight = (max_ascent + max_descent);
        *pascent = max_ascent;
        *pdescent = max_descent;
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
        GDI_UNLOCK;

        return;
    }
#else /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    mmi_fe_get_char_info_of_all_lang(size, pheight, pascent, pdescent);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
}

#endif /* __MMI_SCRIPT_EASY__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_simply_lang
 * DESCRIPTION
 *  To get maximum char height, ascent and descent for a simply language (English, SC)
 * PARAMETERS
 *  size            [IN]    The specified size
 *  pHeight         [IN]    height         
 *  pAscent         [IN]    ascent 
 *  pDescent        [IN]    descent 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_get_char_info_of_simply_lang(U8 size, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute font = {0};

    mmi_fe_get_string_info_param_struct query;

    static S32 ascent = 0, dscent = 0, height = 0, backup_size = 0;

    static const U16 measureString[] = {0x0041, 0x0067, 0x5BB6, 0}; /* 'Ag¼Ò' */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (backup_size == size && height != 0)
    {
        if (pAscent != NULL)
            *pAscent = ascent;

        if (pDescent != NULL)
            *pDescent = dscent;

        if (pHeight != NULL)
            *pHeight = height;

        return;
    }

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)measureString;
    query.n = mmi_ucs2strlen((const char*)measureString);
    //query.w = 0;

    font.size = size;
    SetFont(font, 0);
    mmi_fe_get_string_widthheight(&query);

    backup_size = size;
    ascent = query.maxAscent;
    dscent = query.maxDescent;
    height = query.pHeight;

    if (pAscent != NULL)
        *pAscent = ascent;

    if (pDescent != NULL)
        *pDescent = dscent;

    if (pHeight != NULL)
        *pHeight = height;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeightOfAllLang
 * DESCRIPTION
 *  To get maximum char height regardless of language
 * PARAMETERS
 *  size        [IN]        The font size
 * RETURNS
 *  S32  the char height
 *****************************************************************************/
S32 Get_CharHeightOfAllLang(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent, descent, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &descent);
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                height = height + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            height = height + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            height = height + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            height = height + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    GDI_UNLOCK;
    return height;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringHeight
 * DESCRIPTION
 *  To get string height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the string height
 *****************************************************************************/
#ifndef __MMI_SCRIPT_EASY__
S32 Get_StringHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine_font_pixel)
    {
        ret = font_engine_font_pixel;
    }
    else
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
    {
        /*
         * pFontFamily = gLanguageArray[gCurrLangIndex].fontfamilyList[gLanguageArray[gCurrLangIndex].nCurrentFamily];
         * ret = (S32) (pFontFamily->fontData[gnCurrentFont]->nHeight);
         */
    }
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                ret = ret + (2 * gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                ret = ret + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            ret = ret + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            ret = ret + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            ret = ret + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    GDI_UNLOCK;
    return ret;
}
#endif /* __MMI_SCRIPT_EASY__ */

/*****************************************************************************
 * FUNCTION
 *  Get_StringLength_InCluster
 * DESCRIPTION
 *  Get the string length in cluster
 * PARAMETERS
 *  input_str       [IN]        
 *  len             [IN]        
 *  base_len        [IN]        
 * RETURNS
 *  U32 - the string length according the clusters
 *****************************************************************************/
U32 Get_StringLength_InCluster(U8 *input_str, U32 len, U32 base_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = base_len; /* Assume the string length in cluster is the same with base_len */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INDIC_ALG__
    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length = 0;
        U32 total_len = 0;

        ire_init_cluster_start_p(input_str);
        ire_init_cluster_end_p(input_str + (len * 2));
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();

        /* This loop takes the string cluster by cluster and renders the string */
        do
        {
            if (total_len >= len)
            {
                /* Parsing the string finished */
                break;
            }

            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (total_len > base_len)
            {
                /* 
                 * the total_len according the clusters is larger than base_len. 
                 * Don't need to paser continually. 
                 */
                break;
            }
        } while (cluster_length);

        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();

        if (total_len > base_len)
        {
            /*
             * The endding character is part of the cluster.
             * We will discard that part.
             */
            val = total_len - cluster_length;
        }
        else
        {
            val = total_len;
        }
    }
#endif /* __MMI_INDIC_ALG__ */ 

    return val;
}


/*****************************************************************************
 * FUNCTION
 *  TestDiffFonts
 * DESCRIPTION
 *  To test the different fonts with diferent sizes.
 *  
 *  This is used to test the different fonts with diferent sizes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *  
 *****************************************************************************/
void TestDiffFonts()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, y = 20;
    stFontAttribute fontInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&fontInfo, 0, sizeof(stFontAttribute));
    fontInfo.bold = 0;
    fontInfo.italic = 0;
    fontInfo.underline = 0;

    fontInfo.size = 9;  /* (size 8..15 FOR type 2..5 ) & (size 9...15 FOR type 1 ) */
    fontInfo.type = 1;  /* 1...5 */

    SetFont(fontInfo, (U8) gCurrLangIndex);

    for (count = 0; count < 2; count++)
    {
        mmi_fe_show_string_ext(0, y, (PU8) "abcdefghij");
        y += 20;

        mmi_fe_show_string_ext(0, y, (PU8) "klmnopqrst");
        y += 20;

        mmi_fe_show_string_ext(0, y, (PU8) "uvwxyz");
        fontInfo.size += 1;
        y += 20;

    }
}


/*****************************************************************************
 * FUNCTION
 *  Get_FontHeight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f               [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __MMI_SCRIPT_EASY__
S32 Get_FontHeight(stFontAttribute f, U8 arrCount)
{
    return se_mtk_get_font_height(f, arrCount);
}
#else /* __MMI_SCRIPT_EASY__ */
S32 Get_FontHeight(stFontAttribute f, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * GDI_LOCK;
     * pFontFamily = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily];
     * ret = (S32) (pFontFamily->fontData[f.size]->nHeight);
     * GDI_UNLOCK;
     */
#if defined(__MMI_FONT_EFFECTS__)
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            if (gAdvanceFontAttribute.shadow_distant > gAdvanceFontAttribute.shadow_range)
            {
                ret = ret + (2 *gAdvanceFontAttribute.shadow_distant);
            }
            else
            {
                ret = ret + (2 * gAdvanceFontAttribute.shadow_range);
            }
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            ret = ret + (2 * gAdvanceFontAttribute.outerglow_range);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            ret = ret + 2;
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            ret = ret + (2 * gAdvanceFontAttribute.border_size);
            break;
        }
    }
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
    return ret;
}
#endif /* __MMI_SCRIPT_EASY__ */

#if !defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(__MMI_LANG_THAI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_query_thai_cluster
 * DESCRIPTION
 *  get Thai cluster information
 * PARAMETERS
 *  cluster     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_query_thai_cluster(mmi_lm_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter = 0;
    UI_character_type curCh = 0, preCh = 0, pre2Ch = 0;
    S32 prev_width = 0;
    S32 prev_height = 0;
    S32 width = 0, height = 0, adv_w = 0;
    mmi_fe_glyph_metrics_struct metrics;
    S32 ascent = 0, descent = 0;
    S32 prev_up_line_width = 0, prev_up_line_adv = 0, prev_bottom_line_width = 0, prev_bottom_line_adv = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (counter < cluster->cluster_len)
    {
        prev_width = width;
        prev_height = height;
        curCh = cluster->display_buffer[counter];
        mmi_fe_get_glyph_metrics(curCh, &metrics);

        if (THAI_CHAR_RANGE(curCh) /* curCh >= THAI_C_KO_KAI && curCh <= THAI_S_KHOMUT */ )
        {
            //curCh = unicode;
            // Base line character, can combinate with above vowels,bottom vowels, tone mark, and sign
            if (IsThaiBaseLineChar(curCh))
            {
                if (IsThaiLongTailChar(preCh))
                {
                    adv_w++;
                }
                //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
                //moved ahead to let the circyle sign on the top of previous or previous2 character
                if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
                {
                    width = (adv_w - 1) + metrics.width;
                    adv_w = adv_w - 1 + metrics.adv_x;
                }
                else
                {
                    width = adv_w + metrics.width;
                    adv_w = adv_w + metrics.adv_x;
                }
            }
            /* For Thai digits and base line sign, the only thing we have to do is moving cursor */
            else if (IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
            {
                width = adv_w + metrics.width;
                adv_w += metrics.adv_x;
            }
            else if (IsThaiToneMark(curCh))
            {
                if (IsThaiSignChar(preCh))
                {
                    /* move the tone two pixel way from the sign. */
                    adv_w += 2;
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                else if (IsThaiBaseLineChar(preCh) && preCh != 0x0e30)
                {

                }
                else if (IsThaiAboveLineChar(preCh))
                {
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        /* check the above line or bottom line char width */
                        if (prev_up_line_adv < metrics.adv_x)
                        {
                            adv_w += (metrics.adv_x - prev_up_line_adv);
                        }
                        if (prev_up_line_width < metrics.width)
                        {
                            prev_up_line_width += (metrics.width - prev_up_line_width);
                        }
                    }
                }
                else if (IsThaiBottomLineChar(preCh))
                {
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        /* check the above line or bottom line char width */
                        if (prev_bottom_line_adv < metrics.adv_x)
                        {
                            adv_w += (metrics.adv_x - prev_bottom_line_adv);
                        }
                        if (prev_bottom_line_width < metrics.width)
                        {
                            prev_bottom_line_width += (metrics.width - prev_bottom_line_width);
                        }

                    }
                }
                else if (preCh == 0x0E47)
                {
                    /* move the tone mark to next character space */
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                else
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
            }
            else if (IsThaiSignChar(curCh))
            {
                if ((IsThaiBaseLineChar(preCh) && IsThaiUpSign(curCh)))
                {
                    /* no increase in with. Because the when the previous character is baseline char, 
                       the sign character would be put in the top of the previous one. */
                }
                else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
                {
                    /* no increase in widht. Because up sign could be put in the same vertical line with up and down vowel. */
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        if (IsThaiBottomLineChar(preCh))
                        {
                            /* check the above line or bottom line char width */
                            if (prev_bottom_line_adv < metrics.adv_x)
                            {
                                adv_w += (metrics.adv_x - prev_bottom_line_adv);
                            }
                            if (prev_bottom_line_width < metrics.width)
                            {
                                prev_bottom_line_width += (metrics.width - prev_bottom_line_width);
                            }
                        }
                        else if (IsThaiAboveLineChar(preCh))
                        {
                            /* check the above line or bottom line char width */
                            if (prev_up_line_adv < metrics.adv_x)
                            {
                                adv_w += (metrics.adv_x - prev_up_line_adv);
                            }
                            if (prev_up_line_width < metrics.width)
                            {
                                prev_up_line_width += (metrics.width - prev_up_line_width);
                            }
                        }
                    }
                }
                else
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
            }
            else if (IsThaiAboveLineChar(curCh))
            {
                if (!(IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh)))
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                metrics.ascent++;
                prev_up_line_width = metrics.width;
                prev_up_line_adv = metrics.adv_x;
            }
            else if (IsThaiToneMark(curCh))
            {
                metrics.ascent++;
            }
            else if (IsThaiBottomLineChar(curCh))
            {
                /* Bottom line characters */
                if (!IsThaiBaseLineChar(preCh))
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                prev_bottom_line_width = metrics.width;
                prev_bottom_line_adv = metrics.adv_x;
            }
        }

        if (metrics.ascent > ascent)
            ascent = metrics.ascent;

        if (metrics.descent > descent)
            descent = metrics.descent;

        counter++;
        pre2Ch = preCh;
        preCh = curCh;
    }
    cluster->w = width;
    cluster->h = ascent + descent;
    cluster->by = ascent;
    cluster->adv_x = adv_w;

}
#endif /* !defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(__MMI_LANG_THAI__) */ 

#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_char_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_info        [IN]        
 *  glyph_info      [IN]        
 *  pos             [?]         
 *  currpos         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_char_pos(
        mmi_fe_glyph_ot_info_p pos_info,
        mmi_fe_glyph_info_p glyph_info,
        mmi_fe_char_pos_struct *pos,
        mmi_fe_char_pos_struct *currpos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos_info->offset < 0)
    {
        //mmi_fe_glyph_ot_info_p baseCharGlyph;
        mmi_fe_char_pos_struct *baseCharPos;

        // baseCharGlyph = pos_info + pos_info->offset;
        baseCharPos = pos + pos_info->offset;
        pos->x_pos = baseCharPos->x_pos + pos_info->pos_x;
        pos->y_pos = baseCharPos->y_pos + (-pos_info->pos_y);
    }
    else if (pos_info->offset == 0)
    {
        pos->x_pos = currpos->x_pos + pos_info->pos_x;
        pos->y_pos = currpos->y_pos + (-pos_info->pos_y);
    }
    else
    {
        MMI_ASSERT(0);
    }
}

#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_query_single_cluster
 * DESCRIPTION
 *  To query one cluster.
 * PARAMETERS
 *  prev_cluster        [IN]        
 *  cluster             [IN]        
 *  param(?)            [IN]        The parameter for one cluster
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_query_single_cluster(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("QCL");
    GDI_LOCK;
    FE_LOCK;
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)
    {
        mmi_fe_text_info_p text_info = NULL;
        S32 i = 0, len = 0, start_index = 0, run_len = 0, cluster_len;
        UI_character_type cluster_text[FE_MAX_CLUSTER_LEN * 2];
        S32 temp_descent = 0;
        mmi_fe_char_pos_struct position[FE_MAX_CLUSTER_LEN];
        S16 descent;
        U8 *pool_ptr;
        mmi_fe_char_pos_struct currpos = {0, 0};
        S32 width = 0, temp_x = 0;

        memset(&position, 0, sizeof(mmi_fe_char_pos_struct) * FE_MAX_CLUSTER_LEN);
        memset(&cluster_text, 0, sizeof(UI_character_type) * FE_MAX_CLUSTER_LEN);
        switch (cluster->lang_id)
        {
        #if defined(__MMI_INDIC_ALG__)
            case MMI_LM_LANG_INDIC:
            {
                UI_character_type prev_ch = 0;
                UI_character_type curr_ch = cluster->data_ptr[0] | (cluster->data_ptr[1] << 8);

                if (prev_cluster)
                    if (prev_cluster->data_ptr)
                        prev_ch = prev_cluster->data_ptr[0] | (prev_cluster->data_ptr[1] << 8);
                if (ire_get_character_lang_id(curr_ch) == ire_get_character_lang_id(prev_ch))
                {
                    memcpy(&cluster_text, prev_cluster->data_ptr, prev_cluster->data_len << 1);
                    memcpy(&cluster_text[prev_cluster->data_len], cluster->data_ptr, cluster->data_len << 1);
                    len = prev_cluster->data_len + cluster->data_len;
                    start_index = prev_cluster->data_len;
                    run_len = cluster->data_len;
                }
                else
                {
                    memcpy(&cluster_text, cluster->data_ptr, cluster->data_len << 1);
                    len = cluster->data_len;
                    start_index = 0;
                    run_len = len;
                }
            }
                break;
        #endif /* defined(__MMI_INDIC_ALG__) */ 
            default:
                memcpy(&cluster_text, cluster->display_buffer, cluster->cluster_len << 1);
                len = cluster->cluster_len;
                start_index = 0;
                run_len = len;
                break;
        }
#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
        cluster_len = mmi_fe_shaper((mmi_lm_lang_enum)cluster->lang_id, cluster_text, len, start_index, run_len, (mmi_fe_text_info_p*) & pool_ptr);
        /* calculate the info */
        if (cluster_len)
        {
            for (i = 0; i < cluster_len; i++)
            {
                text_info = (mmi_fe_text_info_p) pool_ptr;
                mmi_fe_set_char_pos(&text_info->posdata, &text_info->glyph_data, &position[i], &currpos);
                temp_x = position[i].x_pos + text_info->glyph_data.bearing_x;

                if (temp_x < 0)
                    temp_x = 0;
                if (temp_x + text_info->glyph_data.width > width)
                    width = temp_x + text_info->glyph_data.width;
                
#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 

                if (text_info->glyph_data.bearing_y - position[i].y_pos > cluster->by)
                    cluster->by = text_info->glyph_data.bearing_y - position[i].y_pos;
                descent = text_info->glyph_data.height - text_info->glyph_data.bearing_y;
                if (descent > temp_descent)
                    temp_descent = descent;

                if (text_info->posdata.new_advance)
                {
                    currpos.x_pos = currpos.x_pos + text_info->posdata.delta_x;
                }
                else
                {
                    currpos.x_pos = currpos.x_pos + (text_info->posdata.delta_x + text_info->glyph_data.advance_x);
                }

                /* goto next glyph */
                pool_ptr +=
                    (sizeof(mmi_fe_glyph_ot_info) + sizeof(mmi_fe_glyph_info) +
                     FE_FOUR_BYTE_ALIGN(text_info->glyph_data.bitmap_size));
            }
#if defined(__MMI_VECTOR_FONT_KERNING__)
            //g_prev_char = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            cluster->adv_x = currpos.x_pos;
            cluster->w = width;
            cluster->h = cluster->by + temp_descent;

            if (cluster_len > 0 && cluster->adv_x == 0)
            {
                cluster->adv_x = width;
            }
        }
        else
        {
            cluster->w = 0;
            cluster->h = 0;
            cluster->adv_x = 0;
            cluster->adv_y = 0;
            cluster->bx = 0;
            cluster->by = 0;

        }

    }

#else /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

    switch (cluster->lang_id)
    {
    #if defined(__MMI_LANG_THAI__)
        case MMI_LM_LANG_THAI:
        #ifndef __MMI_SCRIPT_EASY__
            mmi_fe_query_thai_cluster(cluster);
        #else
            {
                mmi_fe_get_string_info_param_struct param = {0};
                param.String = (U8*)(cluster->display_buffer);
                param.n = cluster->cluster_len;
                mmi_fe_get_string_widthheight(&param);
                cluster->w = param.pWidth;
                cluster->h = param.pHeight;
                cluster->by = param.baseline;
                cluster->adv_x = param.adv_w;
            }
        #endif /* #ifndef __MMI_SCRIPT_EASY__ */
            break;
    #endif /* defined(__MMI_LANG_THAI__) */ 
    #if defined(__MMI_INDIC_ALG__)
        case MMI_LM_LANG_INDIC:
        {
            mmi_fe_get_string_info_param_struct param = {0};
            #ifdef __MMI_SCRIPT_EASY__
                param.String = (U8*)(cluster->data_ptr);
                param.n = cluster->data_len;
            #else
            U16 disp_cluster[G_MAX + 1];

            if (cluster->data_len == 1)
            {
                disp_cluster[0] = MMI_LM_GET_CHARACTER_FROM_BUFFER(cluster->data_ptr);
                disp_cluster[1] = 0;
                cluster->cluster_len = 1;
            }
            else
            {
                UI_character_type org_data[G_MAX + 1];

                memcpy(&org_data, cluster->data_ptr, cluster->data_len * sizeof(UI_character_type));
                org_data[cluster->data_len] = 0;
                cluster->cluster_len = ire_language_rules(disp_cluster, org_data, cluster->data_len);
                disp_cluster[cluster->cluster_len] = 0;
            }
            if (cluster->cluster_len < MMI_LM_CLUSTER_MAX)
                memcpy(&cluster->display_buffer, disp_cluster, (cluster->cluster_len + 1) << 1);
            param.String = (U8*) (disp_cluster);
            param.n = cluster->cluster_len;
            #endif /* #ifdef __MMI_SCRIPT_EASY__ */ 
        #if defined (__MMI_LANG_TELUGU__)
            IRE_RESET_RENDERING_CORRECTION();
        #endif 
            #ifdef __MMI_SCRIPT_EASY__
                mmi_fe_get_string_widthheight(&param);
            #else
            mmi_fe_get_string_widthheight_indic_internal(&param);
            #endif /* #ifdef __MMI_SCRIPT_EASY__ */
            cluster->w = param.pWidth;
            cluster->h = param.pHeight;
            cluster->by = param.baseline;
            cluster->adv_x = param.adv_w;
        }
            break;
    #endif /* defined(__MMI_INDIC_ALG__) */ 
        default:
        {
            /*----------------------------------------------------------------*/
            /* Local Variables                                                */
            /*----------------------------------------------------------------*/
            S32 i = 0;
            U16 ch;
            S16 temp_ascent = 0;
            S16 temp_descent = 0;
            mmi_fe_glyph_metrics_struct matrix;
            S16 temp_height = 0;
            S16 x = 0;

            /*----------------------------------------------------------------*/
            /* Code Body                                                      */
            /*----------------------------------------------------------------*/
            memset(&matrix, 0, sizeof(matrix));
            for (; i < cluster->cluster_len; i++)
            {
                ch = cluster->display_buffer[i];
                if (i != 0)
                {
                    cluster->w += matrix.adv_x;
                }
                mmi_fe_get_glyph_metrics(ch, &matrix);
                cluster->adv_x += matrix.adv_x;
                if (matrix.ascent > temp_ascent)
                    temp_ascent = matrix.ascent;
                if (matrix.descent > temp_descent)
                    temp_descent = matrix.descent;
                if (temp_height < matrix.height)
                    temp_height = matrix.height;
                x += matrix.adv_x;
            }
            if (cluster->cluster_len == 1 && cluster->adv_x == 0)
            {
                cluster->adv_x += matrix.width;
            }

            cluster->w += matrix.width;
            cluster->h = temp_ascent + temp_descent;
            if (cluster->h < temp_height)
                cluster->h = temp_height;
            cluster->by = temp_ascent;
        }

            break;
    }

#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 

    FE_UNLOCK;
    GDI_UNLOCK;
    FE_SWLA_STOP("QCL");
}


#ifndef __MMI_SCRIPT_EASY__
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_single_cluster_core
 * DESCRIPTION
 *  To display one cluster. The content should be in its display form.
 * PARAMETERS
 *  param       [IN]        The parameter for one cluster
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_single_cluster_core(mmi_fe_show_one_cluster_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    mmi_fe_showstring_int_param_struct show_param;
    U8 tempFontAttrib = gnCurrentFontAttrib;

#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("SCL");
    GDI_LOCK;
    FE_LOCK;
    memset(&show_param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    border_color = gdi_act_color_from_rgb(
                    0xff,
                    g_mmi_fe_text_border_color.r,
                    g_mmi_fe_text_border_color.g,
                    g_mmi_fe_text_border_color.b);
    gnCurrentFontAttrib &= (~(FONTATTRIB_UNDERLINE | FONTATTRIB_STRIKETHROUGH));

#ifdef __MMI_BDF_SW_COMPRESSION__
    if(param->bordered)
    {
        bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)((gnCurrentFontAttrib & ~BFC_STYLE_NORMAL) | BFC_STYLE_BORDER), text_color, border_color);
    }
    else
    {
        bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)gnCurrentFontAttrib, text_color, border_color);
    }
    
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_begin(param->x, param->y, text_color, gnCurrentFontAttrib);
#endif 

    if (param->bordered &&
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R &&
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->bordered = 0;
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color, border_color);
    if (param->bordered && !mmi_fe_get_img_cache_mode())
    {
        font_engine_font_attr |= FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
    }
    {
        S32 i = 0, len = 0;
        mmi_fe_char_pos_struct position[FE_MAX_CLUSTER_LEN];
        mmi_fe_char_pos_struct currpos;
        UI_character_type cluster_buffer[FE_MAX_CLUSTER_LEN];
        mmi_fe_text_info_p text_info = NULL;
        U8 *pool_ptr;
        S32 disp_x;

        currpos.x_pos = param->x;
        currpos.y_pos = param->y;

        memset(cluster_buffer, 0, sizeof(cluster_buffer));
        memcpy(cluster_buffer, param->string, sizeof(UI_character_type) * param->len);
        memset(position, 0, sizeof(position));

        len = mmi_fe_shaper(
                (mmi_lm_lang_enum)param->langid,
                cluster_buffer,
                param->len,
                param->subarray_start,
                param->subarray_len,
                (mmi_fe_text_info_p*) & pool_ptr);
        /* calculate the info */
        for (i = 0; i < len; i++)
        {
            text_info = (mmi_fe_text_info_p) pool_ptr;
            mmi_fe_set_char_pos(&text_info->posdata, &text_info->glyph_data, &position[i], &currpos);
            disp_x = position[i].x_pos + text_info->glyph_data.bearing_x;
            if (disp_x < param->x)
                disp_x = param->x;

#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */

            if(mmi_fe_get_img_cache_mode())
            {
                ASSERT(mmi_fe_img_cache_ptr);
                mmi_fe_glyph_image_mem_merge(
                    (U8*)(mmi_fe_img_cache_ptr->buf->data), 
                    (U8*)(text_info->glyph_data.bitmap) + FE_FIND_OFFSET(mmi_fe_render_data_struct, data), 
                    disp_x, 
                    param->baseline - text_info->glyph_data.bearing_y - text_info->posdata.pos_y, 
                    text_info->glyph_data.width,
                    text_info->glyph_data.height, 
                    mmi_fe_img_cache_ptr->str_w, 
                    mmi_fe_img_cache_ptr->str_h);
            }
            else
            {
                mmi_fe_show_font_data(
                    text_info->posdata.glyph_index,
                    disp_x,
                    (param->baseline - text_info->glyph_data.bearing_y) + position[i].y_pos,
                    (U8*) & text_info->glyph_data.bitmap,
                    text_info->glyph_data.bitmap_size,
                    FE_GLYPH_ATTR_USING_FONT_ENGINE,
                    text_info->glyph_data.width,
                    text_info->glyph_data.height,
                    param->bordered,
                    gnCurrentFontAttrib,
                    text_color,
                    border_color);
            }
            /* mmi_fe_update_char_pos(&fe_cluster.glyph_buf[i], &position[i + 1], &position[i]); */
            if (text_info->posdata.new_advance)
            {
                currpos.x_pos = currpos.x_pos + text_info->posdata.delta_x;
            }
            else
            {
                currpos.x_pos = currpos.x_pos + (text_info->posdata.delta_x + text_info->glyph_data.advance_x);
            }
            /* currpos.y_pos = position[i].y_pos; */

            /* goto next glyph */
            pool_ptr +=
                (sizeof(mmi_fe_glyph_ot_info) + sizeof(mmi_fe_glyph_info) +
                 FE_FOUR_BYTE_ALIGN(text_info->glyph_data.bitmap_size));
        }
    }

    if (param->bordered && !mmi_fe_get_img_cache_mode())
    {
        font_engine_font_attr &= ~FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack();  /* if overflow , assert it */
    #endif 
    }

#else /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    switch (param->langid)
    {
    #if defined(__MMI_LANG_THAI__)
        case MMI_LM_LANG_THAI:
        {
            UI_character_type prech = 0, pre2ch = 0, curch = 0;
            S32 i, char_w = 0;
            S32 string_width = 0;

            show_param.Bordered = param->bordered;
            show_param.BaseLineHeight = param->baseline;
            show_param.text_color = text_color;
            show_param.border_color = border_color;
            for (i = 0; i < param->len; i++)
            {
                curch = param->string[(i << 1)] | (param->string[(i << 1) + 1] << 8);
                char_w = mmi_fe_show_thai_char_internal(
                            param->x + string_width,
                            param->y,
                            pre2ch,
                            prech,
                            ((UI_string_type) param->string)[i],
                            &show_param);
                if (char_w > string_width)
                    string_width = char_w;
                pre2ch = prech;
                prech = curch;
            }
        }
            break;
    #endif /* defined(__MMI_LANG_THAI__) */ 
    #if defined(__MMI_INDIC_ALG__)
        case MMI_LM_LANG_INDIC:
        {
            S32 clip_x1, clip_x2, clip_y1, clip_y2;

            gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
            ire_indic_padding_value(0);
            show_param.String = param->string;
            show_param.len = param->len;
            show_param.x = param->x;
            show_param.y = param->y;
            show_param.text_color = text_color;
            show_param.border_color = border_color;
            show_param.Bordered = param->bordered;
            show_param.BaseLineHeight = param->baseline;
            show_param.clip_x1 = clip_x1;
            show_param.clip_x2 = clip_x2;
            show_param.clip_y1 = clip_y1;
            show_param.clip_y2 = clip_y2;
            if (ire_is_reset_indic_params())
                ire_reset_indic_params();
            mmi_fe_show_indic_string_internal(&show_param);
            ire_indic_padding_def_value();
        }
            break;
    #endif /* defined(__MMI_INDIC_ALG__) */ 
        default:
        {
            mmi_fe_show_single_cluster_other(param, text_color, border_color);
        }
            break;
    }
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    gnCurrentFontAttrib = tempFontAttrib;

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_end();
#endif 

    FE_UNLOCK;
    GDI_UNLOCK;
    FE_SWLA_STOP("SCL");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_single_cluster
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_single_cluster(mmi_fe_show_one_cluster_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 stackSize;
    void *pStack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    stackSize = FE_STACK_SIZE;
    pStack = drv_gfx_stkmgr_get_stack(stackSize);
    if (pStack)
    {
        INT_SwitchStackToRun(pStack, stackSize, (kal_func_ptr) mmi_fe_show_single_cluster_core, 1, param);

        drv_gfx_stkmgr_release_stack(pStack);
    }
    else
#endif /* defined(__MTK_TARGET__) */ 
    {
        mmi_fe_show_single_cluster_core(param);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_string
 * DESCRIPTION
 *  To check the input string if the first len character is supported in current font configuration
 * PARAMETERS
 *  font        [IN]        
 *  string      [IN]        The desired string
 *  len         [IN]        The first len character should be checked.
 * RETURNS
 *  MMI_BOOL           the validness of the string
 *****************************************************************************/
MMI_BOOL mmi_fe_check_string(stFontAttribute font, U8 *string, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Ch;
    U32 data_attr;
    U8 *pCharData;
    U16 dataWidth, dataHeight;
    S32 nWidth, nDWidth, ascent, descent, bearing_x;
    MMI_BOOL valid;
    S32 index;
    MMI_BOOL ret = MMI_TRUE;
#if defined(__MMI_VECTOR_FONT_KERNING__)
    S32 lsb_delta = 0; 
    S32 rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    for (index = 0; index < len; index++)
    {
        Ch = string[0] | (string[1] << 8);
        string += 2;

#if defined(__MMI_VECTOR_FONT_KERNING__)
        mmi_fe_get_font_data(
            MMI_FE_VALID_CHECK,
            Ch,
            &pCharData,
            &data_attr,
            &nWidth,
            &nDWidth,
            &dataWidth,
            &dataHeight,
            &bearing_x,
            &ascent,
            &descent,
            &lsb_delta, 
            &rsb_delta,
            &valid);
#else
        mmi_fe_get_font_data(
            MMI_FE_VALID_CHECK,
            Ch,
            &pCharData,
            &data_attr,
            &nWidth,
            &nDWidth,
            &dataWidth,
            &dataHeight,
            &bearing_x,
            &ascent,
            &descent,
            &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
        if (!valid)
        {
            ret = MMI_FALSE;
            break;
        }
    }
    FE_UNLOCK;
    GDI_UNLOCK;
    return ret;
}

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define FE_CELL_DIFF_HALF(a, b)  ((a) >= (b) ? (((a) - (b)) - (((a)-(b))>>1)) : 0)
#else 
#define FE_CELL_DIFF_HALF(a, b)  ((a) >= (b) ? (((a)-(b))>>1) : 0)
#endif 
#define FE_CELL_DIFF_THREE_FOURTH(a, b) ((a) >= (b)? (((a) - (b)) - (((a) - (b))>>2)) : 0)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_with_bounding_box
 * DESCRIPTION
 *  show character inside the bounding box with the specified font size
 * PARAMETERS
 *  x           [IN]        The x position
 *  y           [IN]        The y position
 *  width       [IN]        The bounding box width
 *  height      [IN]        The bounding box height
 *  ch          [IN]        The specified character
 *  type        [IN]        Aligh type
 *  Font        [IN]        The max font size
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_char_with_bounding_box(
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U16 ch,
        mmi_fe_align_type type,
        stFontAttribute Font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 glyph_width, glyph_height, bbox_x, bbox_y, bbox_width, bbox_height /*, diff_w, diff_h*/ ;
    U8 arrCount = 0;
    S32 char_x, char_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    /* for the case using enum, change it to pixel size. */
    if (Font.size < 6)
        Font.size = FONT_PIXEL_SIZE(mmi_fe_size_to_pixel(Font.size));
    do
#endif /* defined(__MMI_VECTOR_FONT_SUPPORT__) */ 
    {
        SetFont(Font, arrCount);
        Get_CharBoundingBox(ch, &glyph_width, &glyph_height, &bbox_x, &bbox_y, &bbox_width, &bbox_height);
        /* leave 2 as the border */
        //diff_w = bbox_width - width;
        //diff_h = bbox_height - height;
        Font.size -= 2;
    }
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    while (bbox_width > width || bbox_height > height);
#endif 

    switch (type)
    {
        case MMI_FE_ALIGN_BOTTOM:   /* bottom align */
            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_THREE_FOURTH(height, bbox_height) - bbox_y;
            break;
        case MMI_FE_ALIGN_TOP:
            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_HALF(height, glyph_height);
            break;
        default:                    /* center align */

            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_HALF(height, bbox_height) - bbox_y;

            /* HACK. the number of remaing pixels is odd. */
            /* It is not always correct depending on the baseline of the font database */
            /* The magic number bbox_y + "1" can be modified */
            if (((height - bbox_height) & 1) && (bbox_y > glyph_height - bbox_height - bbox_y))
            {
                char_y++;
            }
            break;
    }

    mmi_fe_show_char_at_xy(char_x, char_y, ch);

    FE_UNLOCK;
    GDI_UNLOCK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_at_xy
 * DESCRIPTION
 *  To display the character at a specifed position.
 *  Rendering rule would not be considered to adjuest the x,y position.
 * PARAMETERS
 *  x       [IN]        The x position
 *  y       [IN]        The y position
 *  ch      [IN]        The specified character
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_char_at_xy(S32 x, S32 y, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
    U8 *CharData;
    U32 CharDataAttr;
    U32 NumChar;
    S32 nWidth;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent;
    S32 descent;
    S32 bearing_x;
    S32 advance_x;
    MMI_BOOL valid;
#endif
    gdi_color text_color;
#ifdef __MMI_BDF_SW_COMPRESSION__
    gdi_color border_color;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32) ch))
        return;
    GDI_LOCK;
    FE_LOCK;
#ifdef __MMI_BDF_SW_COMPRESSION__
    border_color = gdi_act_color_from_rgb(
                    0xff,
                    g_mmi_fe_text_border_color.r,
                    g_mmi_fe_text_border_color.g,
                    g_mmi_fe_text_border_color.b);
#endif
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color, 0);
#endif 

    if (mmi_fe_test_display_as_space(ch))
    {
        ch = 0x20;
    }
    if (mmi_fe_test_display_as_invalid(ch))
    {
        ch = 0xFFEB;
    }

#ifdef __MMI_BDF_SW_COMPRESSION__
    bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)gnCurrentFontAttrib, text_color, border_color);
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_begin(x, y, text_color, gnCurrentFontAttrib);
#endif

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        mmi_lm_cluster_info cluster = {0}, prev_cluster = {0}, prev2_cluster = {0};
        mmi_lm_show_cluster_param show_param = {0};
        show_param.x = x;
        show_param.y = y;
        show_param.cluster = &cluster;
        show_param.prev_cluster = &prev_cluster;
        cluster.data_ptr = (U8 *)&ch;
        mmi_lm_get_current_cluster(cluster.data_ptr, cluster.data_ptr, &prev2_cluster, &prev_cluster, &cluster);
        show_param.baseline = cluster.by;
        mmi_lm_draw_cluster(&show_param);
    }
#else
    {
        NumChar = mmi_fe_get_font_data(
                    MMI_TRUE,
                    ch,
                    &CharData,
                    &CharDataAttr,
                    &nWidth,
                    &advance_x,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &ascent,
                    &descent,
                    &valid);

        mmi_fe_show_font_data(
            ch,
            x,
            y,
            CharData,
            NumChar,
            CharDataAttr,
            glyph_width,
            glyph_height,
            0,
            gnCurrentFontAttrib,
            text_color,
            0);
    }
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_end();
#endif 
    FE_UNLOCK;
    GDI_UNLOCK;
}
#endif /* __MMI_SCRIPT_EASY__ */

const L2RLangSSC l2RLangSSC[] = 
{
    SSC_ARABIC,
    SSC_PERSIAN,
    SSC_URDU,
    SSC_HEBREW
};


/*****************************************************************************
 * FUNCTION
 *  IsL2RMMIStyle
 * DESCRIPTION
 *  To check if current langauge should be rendered from R2L or L2R
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
BOOL IsL2RMMIStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = 0;
    //U8 temp_str1[30];
    //U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);

    for (index = 0; index < (sizeof(l2RLangSSC) / sizeof(l2RLangSSC[0])); index++)
    {
        //mmi_asc_to_ucs2((S8*) temp_str2, (S8*) l2RLangSSC[index].sscString);
        /* pTemp = (U8 *) temp_str; */

        //if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        if(strcmp((char *)gLanguageArray[gCurrLangIndex].aLangSSC, l2RLangSSC[index].sscString) == 0)
        {
            return MMI_TRUE;
        }

    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  ShowDebugStringInt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  String              [?]         [?]
 *  len                 [IN]        
 *  Bordered            [IN]        
 *  LineHeight(?)       [IN]        
 *  Font(?)             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowDebugStringInt(S32 x, S32 y, U8 *String, S32 len, U32 Bordered)
{
#ifndef __MMI_SCRIPT_EASY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;

    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    S32 nWidth;
    U16 unicode;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent;
    S32 descent;
    S32 advance_x;
    U16 nHeight;
    gdi_color border_color = 0, text_color;
    MMI_BOOL valid;
#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_VECTOR_FONT_KERNING__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
  //  mmi_fe_disable_font_engine();
#endif 
    if (Bordered)
        border_color = gdi_act_color_from_rgb(
                        0xff,
                        g_mmi_fe_text_border_color.r,
                        g_mmi_fe_text_border_color.g,
                        g_mmi_fe_text_border_color.b);
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color, border_color);
#endif 

#ifdef __MMI_BDF_SW_COMPRESSION__
    /* Fatal error happen before font engine init
    Please set break point @ kal_fatal_error_handler and check fatal error first */
    MMI_ASSERT(g_decoder != NULL);
    bfcDecSetAttribute(g_decoder, (BFC_STYLE_ENUM)gnCurrentFontAttrib, text_color, border_color);
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_begin(x, y, text_color, gnCurrentFontAttrib);
#endif 

    gnCurrentFont = 0;
        
    CurrentX = x;
    while (len != 0)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        len--;

        unicode = String[0];
        unicode |= (String[1] << 8);

        if (mmi_fe_test_display_as_space(unicode))
        {
            unicode = 0x20;
        }
        if (mmi_fe_test_display_as_invalid(unicode))
        {
            unicode = 0xFFEB;
        }

#if 0 //defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_VECTOR_FONT_KERNING__ */
        NumChar = mmi_fe_get_font_data_internal(
                    unicode,
                    MMI_FE_GET_DATA,
                    &CharData,
                    &nWidth,
                    &advance_x,
                    &nHeight,
                    &glyph_width,
                    &glyph_height,
                    &ascent,
                    &descent,
                    &valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */

        Counter++;
        mmi_fe_show_font_data(
            unicode,
            CurrentX,
            y,
            CharData,
            NumChar,
            0,
            glyph_width,
            glyph_height,
            Bordered,
            gnCurrentFontAttrib,
            text_color,
            border_color);
#if 0//defined(__MMI_VECTOR_FONT_KERNING__)
/* under construction !*/
/* under construction !*/
#else /* __MMI_VECTOR_FONT_KERNING__ */
        CurrentX += nWidth;
#endif /* __MMI_VECTOR_FONT_KERNING__ */
        String += 2;
    }

#if defined(__MMI_VECTOR_FONT_SUPPORT__) || !defined(__MMI_BDF_SW_COMPRESSION__)
    gdi_font_end();
#endif 

    return CurrentX;
#else
    S32 w, h;
    if(len < 0)
        len = mmi_ucs2strlen((const S8*)String);
    gui_measure_string_n((UI_string_type)String, len, &w, &h);
    gui_move_text_cursor(x, y);
    if(Bordered)
        gui_print_bordered_text_n((UI_string_type)String, len);
    else
        gui_print_text_n((UI_string_type)String, len);
       
    return x + w;
#endif /* __MMI_SCRIPT_EASY__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info
 * DESCRIPTION
 *  To get the font info of the desired character
 * PARAMETERS
 *  Ch              [IN]        
 *  pWidth          [OUT]       The width of the ch.
 *  pDwidth         [?]         
 *  pHeight         [OUT]       The height of the ch.
 *  Ascent          [?]         
 *  Descent         [?]         
 *  pAscent(?)      [OUT]       The ascent of the ch.
 *  pDescent(?)     [OUT]       The descent of the ch.
 *  pdWidth(?)      [OUT]       The dwidth of the character. If the character is not Indic character. The dwidth is equal to width.
 *  ch(?)           [IN]        
 * RETURNS
 *  FE_GLYPH_ATTR_USING_FONT_ENGINE or 0
 *****************************************************************************/
U32 mmi_fe_get_char_info(U32 Ch, S32 *pWidth, S32 *pDwidth, S32 *pHeight, S32 *Ascent, S32 *Descent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = (U32)-1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    ret = Get_CharWidthHeight_internal(Ch, pDwidth, pWidth, pHeight, Ascent, Descent);
    FE_UNLOCK;
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ShowDebugString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  String          [?]         [?]
 *  len             [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowDebugString(S32 x, S32 y, stFontAttribute Font, U8 *String, S32 len, U32 LineHeight, U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ShowDebugStringInt(x, y, String, len, Bordered);
}


/*****************************************************************************
 * FUNCTION
 *  IsChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;
    U8 ch_ssc[2][SSC_SIZE] = {{SSC_SCHINESE}, {SSC_TCHINESE}};
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<2;i++)
    {
        if(strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, (char *)ch_ssc[i]) == 0)
            return 1;
    }
    /*if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }*/

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsEnglishSet
 * DESCRIPTION
 *  This function checks whether the current language is set as English or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsEnglishSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_AUTO) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsTrChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as traditional
 *  Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsTrChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsSmChineseSet
 * DESCRIPTION
 *  This function checks whether the current language is set as simplified
 *  Chinese or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
pBOOL IsSmChineseSet(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    return 0;
}

#ifdef __MMI_VECTOR_FONT_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_print_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_cache_print_all()
{
#ifndef __MMI_SCRIPT_EASY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;
    mmi_fe_cache_tree_node_struct *node = NULL;
    mmi_fe_cache_node_data_struct *data = NULL;
    mmi_fe_text_info_p data_ptr;
    mmi_fe_cache_key_struct *key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; tree != NULL; tree = tree->next)
    {
        node = (mmi_fe_cache_tree_node_struct*) dict_first(&tree->dict);
        if (node == NULL)
            continue;

        do
        {
            key = (mmi_fe_cache_key_struct*) & node->data;

            if(key->header.cache_type == MMI_FE_CACHE_TYPE_CLUSTER_DATA)
            {
                data =
                    (mmi_fe_cache_node_data_struct*) (&node->data + sizeof(mmi_fe_cache_key_header_struct) +
                                                       FE_FOUR_BYTE_ALIGN(key->header.len << 2));
                data_ptr = (mmi_fe_text_info_p) & data->glyph_list;
                kal_prompt_trace(
                    MOD_MMI_FW,
                    "key: type = %d, size = %d, attr = %d, ucs2 = %x; data: width = %d, height = %d\r\n",
                    key->header.cache_type,
                    key->header.font_size & 0x7f,
                    key->header.font_attr,
                    key->string[0],
                    data_ptr->glyph_data.width,
                    data_ptr->glyph_data.height);
            }
            else if(key->header.cache_type == MMI_FE_CACHE_TYPE_STRING_INFO)
            {

            }
            else if(key->header.cache_type == MMI_FE_CACHE_TYPE_STRING_IMAGE)
            {

            }
            else
                ASSERT(0);

            node = (mmi_fe_cache_tree_node_struct*) dict_next(&tree->dict, (dnode_t*) node);
        } while (node);
    }
    return;
#endif /*__MMI_SCRIPT_EASY__*/
}
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
/***********************************************************************************************************************************/
/****************************************Font Effect's Start*********************************************************************/
/***********************************************************************************************************************************/
#if defined(__MMI_FONT_EFFECTS__)


/*****************************************************************************
 * FUNCTION
 *  setFontEffectAttribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void setFontEffectAttribute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttributeNode *fontAttributeNodePtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontAttributeNodePtr = searchFontEffectAttribute();
    if (fontAttributeNodePtr != NULL)
    {
        gFontEffectColorGroup = fontAttributeNodePtr->font_color;
        gAdvanceFontAttribute = fontAttributeNodePtr->advance_font_attribute;
        gFontEffect = fontAttributeNodePtr->effect_type;
    }
    else
    {
        /* error */
        //gFontEffectColorGroup = fontAttributeNodePtr->font_color;
        //gAdvanceFontAttribute = fontAttributeNodePtr->advance_font_attribute;
        gFontEffect = FONT_EFFECT_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  searchFontEffectAttribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static stFontAttributeNode* searchFontEffectAttribute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    stFontAttributeNode *nodeptr = gFontAttributeNode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i <= gFontAttributeTotalNode; i++)
    {
        if (gSubFontEffect == nodeptr->attribute_id)
        {
            return nodeptr;
        }
        if (nodeptr->node_type == 0 && nodeptr->next == NULL)
        {
            nodeptr = nodeptr++;
        }
        else if (nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  searchFontEffectAttribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL isFontEffectAttributeIdValid(U8 attribute_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    stFontAttributeNode *nodeptr = gFontAttributeNode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(attribute_id < MMI_FE_FONT_EFFECT_MAX)
        return MMI_FALSE;
    for(i = 0; i <= gFontAttributeTotalNode; i++)
    {
        if (nodeptr->attribute_id == attribute_id)
        {
            return MMI_FALSE;
        }
        if (nodeptr->node_type == 0 && nodeptr->next == NULL)
        {
            nodeptr = nodeptr++;
        }
        else if (nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  addFontEffectAttributeNode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attribute_node      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 addFontEffectAttributeNode(stFontAttributeNode *attribute_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 i = 0;
    stFontAttributeNode *nodeptr = NULL;
    U8 temp_node_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(attribute_node != NULL);

    if(gFontAttributeTotalNode > 251)
        return 0;

    temp_node_id = gFontAttributeTotalNode + FONTS_EFFECT_NODE_START + 1;
    
    if(temp_node_id > 255 || temp_node_id < (FONTS_EFFECT_NODE_START + 1))
        temp_node_id = MMI_FE_FONT_EFFECT_MAX + 1;

    while(1)
    {
        if(isFontEffectAttributeIdValid(temp_node_id))
        {
            break;
        }
        else
        {
            temp_node_id++;
        }
    }
    MMI_ASSERT(MMI_FE_FONT_EFFECT_MAX - 1 < temp_node_id);
    attribute_node->attribute_id = temp_node_id;
    attribute_node->next = NULL;
    attribute_node->node_type = 1;

    if(gFontAttributeNode[gFontAttributeLastStaticNode].next == NULL || gFontAttributeLastStaticNode == gFontAttributeTotalNode)
    {
        gFontAttributeNode[gFontAttributeLastStaticNode].next = attribute_node;
    }
    else
    {
        nodeptr = gFontAttributeNode[gFontAttributeLastStaticNode].next;
        while (nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
        }
        nodeptr->next = attribute_node;
    }

    gFontAttributeTotalNode++;
    ASSERT(gFontAttributeTotalNode >= MMI_FE_FONT_EFFECT_FINAL_MAX - 1);
    return attribute_node->attribute_id;
}


/*****************************************************************************
 * FUNCTION
 *  removeFontEffectAttributeNode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL removeFontEffectAttributeNode(U8 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttributeNode *nodeptr = NULL, *prevnode = NULL;
    U8 found = 0, first = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(256 > node_id );
    MMI_ASSERT(MMI_FE_FONT_EFFECT_MAX - 1 < node_id );

    if(node_id == 0)
        return MMI_FALSE;

    if(gFontAttributeNode[gFontAttributeLastStaticNode].next == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        nodeptr = gFontAttributeNode[gFontAttributeLastStaticNode].next;
        do
        {
            if (nodeptr->attribute_id == node_id)
            {
                found = 1;
                if (first == 0)
                {
                    gFontAttributeNode[gFontAttributeLastStaticNode].next = nodeptr->next;
                }
                else
                {
                    prevnode->next = nodeptr->next;
                }
                break;
            }
            prevnode = nodeptr;
            nodeptr = nodeptr->next;
            first++;
        }while(nodeptr != NULL);
    }
    if (found == 1)
    {
        gFontAttributeTotalNode--;
        ASSERT(gFontAttributeTotalNode >= MMI_FE_FONT_EFFECT_FINAL_MAX - 1);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_effect_data_pool_free_notify_callback
 * DESCRIPTION
 *  To allocate effect data pool for tree
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_effect_data_pool_free_notify_callback(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_LOCK;

    if(ptr == g_mmi_fe_data_pool_1_ext)
    {
        g_mmi_fe_data_pool_1_ext = NULL;
    }
    else if(ptr == g_mmi_fe_data_pool_2_ext)
    {
        g_mmi_fe_data_pool_2_ext = NULL;
    }
    else if(ptr == g_mmi_fe_data_pool_3_ext)
    {
        g_mmi_fe_data_pool_3_ext = NULL;
    }
    else
        MMI_ASSERT(0);

    mmi_fe_font_effect_pool_size = 0;

    FE_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_free_effect_data_pool
 * DESCRIPTION
 *  to free font effect data pool working buffer
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_free_effect_data_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("FEP");
    if(g_mmi_fe_data_pool_1_ext)
    {
        med_free_temp_ext_mem((void **)&g_mmi_fe_data_pool_1_ext);
        g_mmi_fe_data_pool_1_ext = NULL;
    }

    if(g_mmi_fe_data_pool_2_ext)
    {
        med_free_temp_ext_mem((void **)&g_mmi_fe_data_pool_2_ext);
        g_mmi_fe_data_pool_2_ext = NULL;
    }

    if(g_mmi_fe_data_pool_3_ext)
    {
        med_free_temp_ext_mem((void **)&g_mmi_fe_data_pool_3_ext);
        g_mmi_fe_data_pool_3_ext = NULL;
    }

    mmi_fe_font_effect_pool_size = 0;
    FE_SWLA_STOP("FEP");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_alloc_effect_data_pool
 * DESCRIPTION
 *  to alloc font effect data pool working buffer
 * PARAMETERS
 *  size        [IN]                     
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_fe_alloc_effect_data_pool(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("AEP");
    if(g_mmi_fe_data_pool_1_ext == NULL)
    {
    #if defined(GDI_AA_FONT_SUPPORT)
        g_mmi_fe_data_pool_1_ext = (U8 *)med_alloc_temp_ext_mem_noncacheable(size, mmi_fe_effect_data_pool_free_notify_callback);
    #else
        g_mmi_fe_data_pool_1_ext = (U8*) med_alloc_temp_ext_mem(size, mmi_fe_effect_data_pool_free_notify_callback);
    #endif
    }

    if(g_mmi_fe_data_pool_2_ext == NULL)
    {
    #if defined(GDI_AA_FONT_SUPPORT)
        g_mmi_fe_data_pool_2_ext = (U8 *)med_alloc_temp_ext_mem_noncacheable(size, mmi_fe_effect_data_pool_free_notify_callback);
    #else
        g_mmi_fe_data_pool_2_ext = (U8*) med_alloc_temp_ext_mem(size, mmi_fe_effect_data_pool_free_notify_callback);
    #endif
    }

    if(g_mmi_fe_data_pool_3_ext == NULL)
    {
    #if defined(GDI_AA_FONT_SUPPORT)
        g_mmi_fe_data_pool_3_ext = (U8 *)med_alloc_temp_ext_mem_noncacheable(size, mmi_fe_effect_data_pool_free_notify_callback);
    #else
        g_mmi_fe_data_pool_3_ext = (U8*) med_alloc_temp_ext_mem(size, mmi_fe_effect_data_pool_free_notify_callback);
    #endif
    }
    
    if(g_mmi_fe_data_pool_1_ext && g_mmi_fe_data_pool_2_ext && g_mmi_fe_data_pool_3_ext)
    {
        mmi_fe_font_effect_pool_size = size;
        ret = MMI_TRUE;
    }
    else
        mmi_fe_free_effect_data_pool();

    FE_SWLA_STOP("AEP");

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_gradient(
                U8 *glyph_ptr,
                U32 glyph_size,
                U16 glyph_width,
                U16 glyph_height,
                U8 *effect_buf_ptr,
                U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count_i, count_j;
    mmi_fe_render_data_struct *render;
    S32 data_size = 0;
    U32 factor = 0;
    U32 factor1, factor2;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(//gAdvanceFontAttribute. gradient_transparency < 0 || 
            gAdvanceFontAttribute. gradient_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    if (glyph_width == 0 || glyph_height == 0)
    {
        return;
    }
    render = (mmi_fe_render_data_struct*) glyph_ptr;

    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    if (gAdvanceFontAttribute.gradient_direction == MMI_FE_GRADIENT_DIRECTION_VERTICAL)
    {
        factor = MAX_GRAY_LEVEL / glyph_height;
        factor1 = factor;
        factor2 = 0;
        for (count_i = 0; count_i < glyph_height; count_i++)
        {
            for (count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * ((factor1 * 100)/MAX_GRAY_LEVEL)) / 100;
                pool_3[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * (((MAX_GRAY_LEVEL - factor2) * 100)/MAX_GRAY_LEVEL)) / 100;

                pool_2[(count_i * glyph_width) + count_j] =  pool_2[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
                pool_3[(count_i * glyph_width) + count_j] = pool_3[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
            }
            factor1 = factor1 + factor;
            factor2 = factor2 + factor;
        }
    }
    else if (gAdvanceFontAttribute.gradient_direction == MMI_FE_GRADIENT_DIRECTION_HORIZONTAL)
    {
        factor = MAX_GRAY_LEVEL / glyph_width;
        for (count_i = 0; count_i < glyph_height; count_i++)
        {
            factor1 = factor;
            factor2 = 0;
            for (count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * ((factor1 * 100)/MAX_GRAY_LEVEL)) / 100;
                pool_3[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * (((MAX_GRAY_LEVEL - factor2) * 100) / MAX_GRAY_LEVEL)) / 100;

                pool_2[(count_i * glyph_width) + count_j] = pool_2[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
                pool_3[(count_i * glyph_width) + count_j] = pool_3[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;

                factor1 = factor1 + factor;
                factor2 = factor2 + factor;
            }
        }
    }

    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, glyph_width * glyph_height, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);
    memcpy(effect_buf_ptr, pool_1, glyph_size);

    memset(pool_1, 0, pool_size);

    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size + 3) & (~3);
    effect_buf_ptr += effect_buf_size;
    memcpy(effect_buf_ptr, pool_1, glyph_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_drop_shadow
 * DESCRIPTION
 *  To show drop shadow character at the desired x, y position by the attributes.
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_drop_shadow(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i, count_j, count_k;
    S32* gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.shadow_range;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(//gAdvanceFontAttribute.shadow_range < 0 || 
            gAdvanceFontAttribute.shadow_range > 5 || 
            //gAdvanceFontAttribute.shadow_distant < 0 || 
            gAdvanceFontAttribute.shadow_distant > 5 || 
            drop_shadow_degree < -180 || 
            drop_shadow_degree > 180 ||
            //gAdvanceFontAttribute.shadow_transparency < 0 ||
            gAdvanceFontAttribute.shadow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    
    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        gauss_fact = gauss_fact_array[gAdvanceFontAttribute.shadow_range - 1];

        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);
        memset(pool_3, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j=0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < gAdvanceFontAttribute.shadow_range * 2 + 1; count_k++)
                {
                    if ( 0 <= ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.shadow_range*2 + 1) - 1) >> 1) + count_k)];
                        sumr += gray * gauss_fact[count_k];
                    }
                }
                if ( gauss_sum != 0)
                {
                    pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_2, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < (gAdvanceFontAttribute.shadow_range * 2 + 1); count_k++)
                {
                    if ( 0 <= (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_3[((count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1)-1) >> 1) + count_k) * temp_glyph_width) + count_j];
                        sumr += gray *gauss_fact[count_k];
                    }
                }
                if ( sumr != 0)
                {
                    pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_3, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_3, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
    }
    else
    {
        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        for(count_i = 0; count_i < glyph_height; count_i++)
        {
            for(count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_2, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_outer_glow(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count_i,  count_j, count_k;
    S32 *gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.outerglow_range;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(//gAdvanceFontAttribute.outerglow_range < 0 || 
        gAdvanceFontAttribute.outerglow_range > 5 || 
        //gAdvanceFontAttribute.outerglow_transparency < 0 || 
        gAdvanceFontAttribute.outerglow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    gauss_fact = gauss_fact_array[gAdvanceFontAttribute.outerglow_range - 1];

    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.outerglow_range * 2 + 1); count_k++)
            {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k)) &&   ((count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1)-1)>>1) + count_k)) < temp_glyph_width)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k)];
                    sumr += gray * gauss_fact[count_k];
                }
            }
            if ( gauss_sum != 0)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr/gauss_sum & 0xFF);
            }
            gauss_sum = 0;
        } 
    }

    memset(pool_2, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.outerglow_range * 2 + 1); count_k++)
            {
                if ( 0 <= (count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) -1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_3[((count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) -1) >> 1) + count_k) * temp_glyph_width) + count_j ];
                    sumr += gray *gauss_fact[count_k];
                }
            }
            if ( gauss_sum != 0)
            {
                pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr/gauss_sum & 0xFF);
            }
            gauss_sum = 0;
        } 
    }

    memset(pool_3, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.outerglow_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, temp_glyph_width, temp_glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);
    memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_engrave(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count_i,  count_j /*, count_k*/;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gAdvanceFontAttribute.engraved_degree < -180 ||
        gAdvanceFontAttribute.engraved_degree > 180 ||
        //gAdvanceFontAttribute.engraved_transparency < 0 || 
        gAdvanceFontAttribute.engraved_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    for(count_i = 0; count_i < glyph_height; count_i++)
    {
        for(count_j = 0; count_j < glyph_width; count_j++)
        {
            pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.engraved_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);

    memcpy(effect_buf_ptr, pool_1, glyph_size);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_border(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i,  count_j,  count_k;
    //U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.border_size;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (//gAdvanceFontAttribute.border_size < 0 || 
        gAdvanceFontAttribute.border_size > 5 || 
        //gAdvanceFontAttribute.border_transparency < 0 ||
        gAdvanceFontAttribute.border_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*)glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.border_size * 2 + 1); count_k++)
            {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                {
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)];
                    sumr = gray > sumr?gray:sumr;
                }
            }
            if ( sumr != 0)
            {
                pool_3[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr);
            }
            else
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (0x00);
            }
            //gauss_sum = 0;
        } 
    }

    memset(pool_2, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.border_size * 2 + 1); count_k++)
            {
                if ( 0 <= (count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                {
                    gray = pool_3[((count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) * temp_glyph_width) + count_j ];
                    sumr = gray > sumr ? gray:sumr;
                }
            }
            if ( sumr != 0)
            {
                pool_2[(count_i * temp_glyph_width) + count_j] = (U8) (sumr);
            }
            else
            {
                pool_2[(count_i * temp_glyph_width) + count_j] = (U8) (0x00);
            }
            //gauss_sum = 0;
        } 
    }

    memset(pool_3, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.border_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;

    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, temp_glyph_width, temp_glyph_height, data_size, font_engine_antialias);
    
    memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_drop_shadow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_gradient_drop_shadow(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i, count_j, count_k;
    S32* gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.shadow_range;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(//gAdvanceFontAttribute.shadow_range < 0 || 
            gAdvanceFontAttribute.shadow_range > 5 || 
            //gAdvanceFontAttribute.shadow_distant < 0 || 
            gAdvanceFontAttribute.shadow_distant > 5 || 
            drop_shadow_degree < -180 || 
            drop_shadow_degree > 180 ||
            //gAdvanceFontAttribute.shadow_transparency < 0 ||
            gAdvanceFontAttribute.shadow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    
    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        gauss_fact = gauss_fact_array[gAdvanceFontAttribute.shadow_range - 1];

        memset(pool_1,0, pool_size);
        memset(pool_2,0, pool_size);
        memset(pool_3,0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j=0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < gAdvanceFontAttribute.shadow_range * 2 + 1; count_k++)
                {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.shadow_range*2 + 1) - 1) >> 1) + count_k)];
                    sumr += gray * gauss_fact[count_k];
                    }
                }
                if ( gauss_sum != 0)
                {
                    pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_2, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < (gAdvanceFontAttribute.shadow_range * 2 + 1); count_k++)
                {
                    if ( 0 <= (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_3[((count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1)-1) >> 1) + count_k) * temp_glyph_width) + count_j];
                        sumr += gray *gauss_fact[count_k];
                    }
                }
                if ( sumr != 0)
                {
                    pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_3,0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_3, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        
        memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
    }
    else
    {
        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        for(count_i = 0; count_i < glyph_height; count_i++)
        {
            for(count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_2, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);

        memcpy(effect_buf_ptr, pool_1, (render->normal_data_size + sizeof(render)));
    }

    mmi_fe_create_img_data_gradient(glyph_ptr,
                                    glyph_size,
                                    glyph_width,
                                    glyph_height,
                                    effect_buf_ptr+effect_buf_size,
                                    effect_buf_size);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_engrave
 * DESCRIPTION
 *  To show gradient engraved character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_img_data_gradient_engrave(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count_i,  count_j /*, count_k*/;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(gAdvanceFontAttribute.engraved_degree < -180 ||
        gAdvanceFontAttribute.engraved_degree < 180 ||
        //gAdvanceFontAttribute.engraved_transparency < 0 ||
        gAdvanceFontAttribute.engraved_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    pool_1 = g_mmi_fe_data_pool_1_ext;
    pool_2 = g_mmi_fe_data_pool_2_ext;
    pool_3 = g_mmi_fe_data_pool_3_ext;
    pool_size = mmi_fe_font_effect_pool_size;

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    for(count_i = 0; count_i < glyph_height; count_i++)
    {
        for(count_j = 0; count_j < glyph_width; count_j++)
        {
            pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.engraved_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);

    memcpy(effect_buf_ptr, pool_1, glyph_size);

    mmi_fe_create_img_data_gradient(glyph_ptr,
                                    glyph_size,
                                    glyph_width,
                                    glyph_height,
                                    effect_buf_ptr+effect_buf_size,
                                    effect_buf_size);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_engrave
 * DESCRIPTION
 *  To show gradient engraved character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_create_effect_img_data(
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("CID");
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        {
            mmi_fe_create_img_data_drop_shadow(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            mmi_fe_create_img_data_outer_glow(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        {
            mmi_fe_create_img_data_engrave(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT:
        {
            mmi_fe_create_img_data_gradient(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            mmi_fe_create_img_data_border(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            mmi_fe_create_img_data_gradient_drop_shadow(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            mmi_fe_create_img_data_gradient_engrave(glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        default:
        {
            break;
        }
    }
    FE_SWLA_STOP("CID");
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient_ext(
                U16 ch,
                S32 x,
                S32 y,
                U8 *glyph_ptr,
                U32 glyph_size,
                U16 glyph_width,
                U16 glyph_height,
                U8* effect_buf_ptr,
                U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDT");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.first_gradient_color.a,
                    gFontEffectColorGroup.first_gradient_color.r,
                    gFontEffectColorGroup.first_gradient_color.g,
                    gFontEffectColorGroup.first_gradient_color.b);
    font_engine->set_font_color(text_color, border_color);

    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, effect_buf_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.second_gradient_color.a,
                                                            gFontEffectColorGroup.second_gradient_color.r,
                                                            gFontEffectColorGroup.second_gradient_color.g,
                                                            gFontEffectColorGroup.second_gradient_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, effect_buf_ptr+effect_buf_size, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("GDT");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_drop_shadow
 * DESCRIPTION
 *  To show drop shadow character at the desired x, y position by the attributes.
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_drop_shadow_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    U16 border_width = gAdvanceFontAttribute.shadow_range;
    S32 x1, y1;
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("DSD");
    if(drop_shadow_degree > 0)
    {
        drop_shadow_degree = drop_shadow_degree -180;
    }
    else
    {
        drop_shadow_degree = drop_shadow_degree +180;
    }
    if(drop_shadow_degree > 0)
    {
        if((drop_shadow_degree % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-drop_shadow_degree) % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
        }
    }

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x - border_width + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y - border_width + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        effect_buf_ptr, 
                                                        effect_buf_size, 
                                                        0, 
                                                        glyph_width + 2 * border_width, 
                                                        glyph_height + 2 * border_width, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }
    else
    {
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        effect_buf_ptr, 
                                                        glyph_size, 
                                                        0, 
                                                        glyph_width, 
                                                        glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color, border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("DSD");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_outer_glow_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    U16 border_width = gAdvanceFontAttribute.outerglow_range;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("OTG");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.outerglow_color.a,
                                                            gFontEffectColorGroup.outerglow_color.r,
                                                            gFontEffectColorGroup.outerglow_color.g,
                                                            gFontEffectColorGroup.outerglow_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x-border_width, y-border_width, effect_buf_ptr, effect_buf_size, 0, glyph_width+2*border_width, glyph_height+2*border_width, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("OTG");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_engrave_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    S32 x1,y1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("EGV");
    if(gAdvanceFontAttribute.engraved_degree > 0)
    {
        if((gAdvanceFontAttribute.engraved_degree % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-gAdvanceFontAttribute.engraved_degree) % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.upper_engraved_color.a,
                                                            gFontEffectColorGroup.upper_engraved_color.r,
                                                            gFontEffectColorGroup.upper_engraved_color.g,
                                                            gFontEffectColorGroup.upper_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + x1, y + y1, effect_buf_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.lower_engraved_color.a,
                                                            gFontEffectColorGroup.lower_engraved_color.r,
                                                            gFontEffectColorGroup.lower_engraved_color.g,
                                                            gFontEffectColorGroup.lower_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x - x1, y - y1, effect_buf_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("EGV");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_border_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    U16 border_width = gAdvanceFontAttribute.border_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("BOD");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.bordered_color.a,
                                                            gFontEffectColorGroup.bordered_color.r,
                                                            gFontEffectColorGroup.bordered_color.g,
                                                            gFontEffectColorGroup.bordered_color.b);
    font_engine->set_font_color(text_color, border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, effect_buf_ptr, effect_buf_size, 0, glyph_width+2*border_width, glyph_height+2*border_width, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color, border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + border_width, y + border_width, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("BOD");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_drop_shadow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient_drop_shadow_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    U16 border_width = gAdvanceFontAttribute.shadow_range;
    S32 x1,y1;
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDS");
    if(drop_shadow_degree > 0)
    {
        drop_shadow_degree = drop_shadow_degree -180;
    }
    else
    {
        drop_shadow_degree = drop_shadow_degree +180;
    }
    if(drop_shadow_degree > 0)
    {
        if((drop_shadow_degree % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-drop_shadow_degree) % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
        }
    }

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x - border_width + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y - border_width + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        effect_buf_ptr, 
                                                        effect_buf_size, 
                                                        0, 
                                                        glyph_width+2*border_width, 
                                                        glyph_height+2*border_width, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }
    else
    {
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        effect_buf_ptr, 
                                                        glyph_size, 
                                                        0, 
                                                        glyph_width, 
                                                        glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }

    mmi_fe_show_font_data_gradient_ext(ch,
                                                        x,
                                                        y,
                                                        glyph_ptr,
                                                        glyph_size,
                                                        glyph_width,
                                                        glyph_height,
                                                        effect_buf_ptr+effect_buf_size,
                                                        effect_buf_size);
    FE_SWLA_STOP("GDS");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_engrave
 * DESCRIPTION
 *  To show gradient engraved character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient_engrave_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8 *glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    S32 x1,y1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDE");
    if(gAdvanceFontAttribute.engraved_degree > 0)
    {
        if((gAdvanceFontAttribute.engraved_degree % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-gAdvanceFontAttribute.engraved_degree) % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.upper_engraved_color.a,
                                                            gFontEffectColorGroup.upper_engraved_color.r,
                                                            gFontEffectColorGroup.upper_engraved_color.g,
                                                            gFontEffectColorGroup.upper_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + x1, y + y1, effect_buf_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.lower_engraved_color.a,
                                                            gFontEffectColorGroup.lower_engraved_color.r,
                                                            gFontEffectColorGroup.lower_engraved_color.g,
                                                            gFontEffectColorGroup.lower_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x - x1, y - y1, effect_buf_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    mmi_fe_show_font_data_gradient_ext(ch,
                                                        x,
                                                        y,
                                                        glyph_ptr,
                                                        glyph_size,
                                                        glyph_width,
                                                        glyph_height,
                                                        effect_buf_ptr+effect_buf_size,
                                                        effect_buf_size);
    FE_SWLA_STOP("GDE");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_engrave
 * DESCRIPTION
 *  To show gradient engraved character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_effect_data_ext(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height,
                            U8* effect_buf_ptr,
                            U32 effect_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("SFE");
    switch (gFontEffect)
    {
        case FONT_EFFECT_DROP_SHADOW:
        {
            mmi_fe_show_font_data_drop_shadow_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_OUTER_GLOW:
        {
            mmi_fe_show_font_data_outer_glow_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_ENHANCED_ENGRAVE:
        {
            mmi_fe_show_font_data_engrave_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT:
        {
            mmi_fe_show_font_data_gradient_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_BORDER:
        {
            mmi_fe_show_font_data_border_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT_DROP_SHADOW:
        {
            mmi_fe_show_font_data_gradient_drop_shadow_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
        {
            mmi_fe_show_font_data_gradient_engrave_ext(ch, x, y, glyph_ptr, glyph_size, glyph_width, glyph_height, effect_buf_ptr, effect_buf_size);
            break;
        }
        default:
        {
            break;
        }
    }
    FE_SWLA_STOP("SFE");
    return;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient(
                U16 ch,
                S32 x,
                S32 y,
                U8 *glyph_ptr,
                U32 glyph_size,
                U16 glyph_width,
                U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count_i, count_j;
    gdi_color border_color = 0, text_color;
    mmi_fe_render_data_struct *render;
    S32 data_size = 0;
    U32 factor = 0;
    U32 factor1, factor2;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDT");
    if(//gAdvanceFontAttribute. gradient_transparency < 0 || 
            gAdvanceFontAttribute. gradient_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    if (glyph_width == 0 || glyph_height == 0)
    {
        return;
    }
    render = (mmi_fe_render_data_struct*) glyph_ptr;

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    if (gAdvanceFontAttribute.gradient_direction == MMI_FE_GRADIENT_DIRECTION_VERTICAL)
    {
        factor = MAX_GRAY_LEVEL / glyph_height;
        factor1 = factor;
        factor2 = 0;
        for (count_i = 0; count_i < glyph_height; count_i++)
        {
            for (count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * ((factor1 * 100)/MAX_GRAY_LEVEL)) / 100;
                pool_3[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * (((MAX_GRAY_LEVEL - factor2) * 100)/MAX_GRAY_LEVEL)) / 100;

                pool_2[(count_i * glyph_width) + count_j] =  pool_2[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
                pool_3[(count_i * glyph_width) + count_j] = pool_3[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
            }
            factor1 = factor1 + factor;
            factor2 = factor2 + factor;
        }
    }
    else if (gAdvanceFontAttribute.gradient_direction == MMI_FE_GRADIENT_DIRECTION_HORIZONTAL)
    {
        factor = MAX_GRAY_LEVEL / glyph_width;
        for (count_i = 0; count_i < glyph_height; count_i++)
        {
            factor1 = factor;
            factor2 = 0;
            for (count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * ((factor1 * 100)/MAX_GRAY_LEVEL)) / 100;
                pool_3[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * (((MAX_GRAY_LEVEL - factor2) * 100) / MAX_GRAY_LEVEL)) / 100;

                pool_2[(count_i * glyph_width) + count_j] = pool_2[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;
                pool_3[(count_i * glyph_width) + count_j] = pool_3[(count_i * glyph_width) + count_j] * (gAdvanceFontAttribute.gradient_transparency + 1) / 100;

                factor1 = factor1 + factor;
                factor2 = factor2 + factor;
            }
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.first_gradient_color.a,
                    gFontEffectColorGroup.first_gradient_color.r,
                    gFontEffectColorGroup.first_gradient_color.g,
                    gFontEffectColorGroup.first_gradient_color.b);
    font_engine->set_font_color(text_color, border_color);

    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, glyph_width * glyph_height, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");

    memset(pool_1, 0, pool_size);
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.second_gradient_color.a,
                                                            gFontEffectColorGroup.second_gradient_color.r,
                                                            gFontEffectColorGroup.second_gradient_color.g,
                                                            gFontEffectColorGroup.second_gradient_color.b);
    font_engine->set_font_color(text_color,border_color);

    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size + 3) & (~3);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("GDT");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_drop_shadow
 * DESCRIPTION
 *  To show drop shadow character at the desired x, y position by the attributes.
 * PARAMETERS
 *  ch                  [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  glyph_ptr           [?]         
 *  glyph_size          [IN]        
 *  glyph_width         [IN]        
 *  glyph_height        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_drop_shadow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i, count_j, count_k;
    gdi_color border_color = 0, text_color;
    S32* gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.shadow_range;
    S32 x1, y1;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("DSD");
    if(//gAdvanceFontAttribute.shadow_range < 0 || 
            gAdvanceFontAttribute.shadow_range > 5 || 
            //gAdvanceFontAttribute.shadow_distant < 0 || 
            gAdvanceFontAttribute.shadow_distant > 5 || 
            drop_shadow_degree < -180 || 
            drop_shadow_degree > 180 ||
            //gAdvanceFontAttribute.shadow_transparency < 0 ||
            gAdvanceFontAttribute.shadow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    if(drop_shadow_degree > 0)
    {
        drop_shadow_degree = drop_shadow_degree -180;
    }
    else
    {
        drop_shadow_degree = drop_shadow_degree +180;
    }
    if(drop_shadow_degree > 0)
    {
        if((drop_shadow_degree % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-drop_shadow_degree) % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
        }
    }

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        gauss_fact = gauss_fact_array[gAdvanceFontAttribute.shadow_range - 1];

        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);
        memset(pool_3, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j=0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < gAdvanceFontAttribute.shadow_range * 2 + 1; count_k++)
                {
                    if ( 0 <= ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.shadow_range*2 + 1) - 1) >> 1) + count_k)];
                        sumr += gray * gauss_fact[count_k];
                    }
                }
                if ( gauss_sum != 0)
                {
                    pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_2, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < (gAdvanceFontAttribute.shadow_range * 2 + 1); count_k++)
                {
                    if ( 0 <= (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_3[((count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1)-1) >> 1) + count_k) * temp_glyph_width) + count_j];
                        sumr += gray *gauss_fact[count_k];
                    }
                }
                if ( sumr != 0)
                {
                    pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_3, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_3, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x - border_width + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y - border_width + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        pool_1, 
                                                        (render->normal_data_size + sizeof(render)), 
                                                        0, 
                                                        temp_glyph_width, 
                                                        temp_glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");

    }
    else
    {
        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        for(count_i = 0; count_i < glyph_height; count_i++)
        {
            for(count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_2, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        pool_1, 
                                                        (render->normal_data_size + sizeof(render)), 
                                                        0, 
                                                        glyph_width, 
                                                        glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color, border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("DSD");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_outer_glow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count_i,  count_j, count_k;
    gdi_color border_color = 0, text_color;
    S32 *gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.outerglow_range;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("OTG");
    if(//gAdvanceFontAttribute.outerglow_range < 0 || 
        gAdvanceFontAttribute.outerglow_range > 5 || 
        //gAdvanceFontAttribute.outerglow_transparency < 0 || 
        gAdvanceFontAttribute.outerglow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    gauss_fact = gauss_fact_array[gAdvanceFontAttribute.outerglow_range - 1];

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.outerglow_range * 2 + 1); count_k++)
            {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k)) &&   ((count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1)-1)>>1) + count_k)) < temp_glyph_width)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k)];
                    sumr += gray * gauss_fact[count_k];
                }
            }
            if ( gauss_sum != 0)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr/gauss_sum & 0xFF);
            }
            gauss_sum = 0;
        } 
    }

    memset(pool_2, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.outerglow_range * 2 + 1); count_k++)
            {
                if ( 0 <= (count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) -1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_3[((count_i - (((gAdvanceFontAttribute.outerglow_range * 2 + 1) -1) >> 1) + count_k) * temp_glyph_width) + count_j ];
                    sumr += gray *gauss_fact[count_k];
                }
            }
            if ( gauss_sum != 0)
            {
                pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr/gauss_sum & 0xFF);
            }
            gauss_sum = 0;
        } 
    }

    memset(pool_3, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.outerglow_transparency) / 100;
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.outerglow_color.a,
                                                            gFontEffectColorGroup.outerglow_color.r,
                                                            gFontEffectColorGroup.outerglow_color.g,
                                                            gFontEffectColorGroup.outerglow_color.b);
    font_engine->set_font_color(text_color,border_color);

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, temp_glyph_width, temp_glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x-border_width, y-border_width, pool_1, (render->normal_data_size + sizeof(render)), 0, temp_glyph_width, temp_glyph_height, 0);
    FE_SWLA_STOP("SFD");
    /*text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.text_color.a,
                                                            gFontEffectColorGroup.text_color.r,
                                                            gFontEffectColorGroup.text_color.g,
                                                            gFontEffectColorGroup.text_color.b);*/
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("OTG");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_engrave(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    S32 x1,y1;
    int count_i,  count_j /*, count_k*/;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("EGV");
    if(gAdvanceFontAttribute.engraved_degree < -180 ||
        gAdvanceFontAttribute.engraved_degree > 180 ||
        //gAdvanceFontAttribute.engraved_transparency < 0 || 
        gAdvanceFontAttribute.engraved_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    for(count_i = 0; count_i < glyph_height; count_i++)
    {
        for(count_j = 0; count_j < glyph_width; count_j++)
        {
            pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.engraved_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);

    if(gAdvanceFontAttribute.engraved_degree > 0)
    {
        if((gAdvanceFontAttribute.engraved_degree % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-gAdvanceFontAttribute.engraved_degree) % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.upper_engraved_color.a,
                                                            gFontEffectColorGroup.upper_engraved_color.r,
                                                            gFontEffectColorGroup.upper_engraved_color.g,
                                                            gFontEffectColorGroup.upper_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + x1, y + y1, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.lower_engraved_color.a,
                                                            gFontEffectColorGroup.lower_engraved_color.r,
                                                            gFontEffectColorGroup.lower_engraved_color.g,
                                                            gFontEffectColorGroup.lower_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x - x1, y - y1, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");

    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("EGV");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_outer_glow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_border(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i,  count_j,  count_k;
    gdi_color border_color = 0, text_color;
    //U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.border_size;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("BOD");
    if (//gAdvanceFontAttribute.border_size < 0 || 
        gAdvanceFontAttribute.border_size > 5 || 
        //gAdvanceFontAttribute.border_transparency < 0 ||
        gAdvanceFontAttribute.border_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*)glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.border_size * 2 + 1); count_k++)
            {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                {
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k)];
                    sumr = gray > sumr?gray:sumr;
                }
            }
            if ( sumr != 0)
            {
                pool_3[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr);
            }
            else
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (0x00);
            }
            //gauss_sum = 0;
        } 
    }

    memset(pool_2, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            sumr = 0;
            for(count_k = 0; count_k < (gAdvanceFontAttribute.border_size * 2 + 1); count_k++)
            {
                if ( 0 <= (count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                {
                    gray = pool_3[((count_i - (((gAdvanceFontAttribute.border_size * 2 + 1) - 1) >> 1) + count_k) * temp_glyph_width) + count_j ];
                    sumr = gray > sumr ? gray:sumr;
                }
            }
            if ( sumr != 0)
            {
                pool_2[(count_i * temp_glyph_width) + count_j] = (U8) (sumr);
            }
            else
            {
                pool_2[(count_i * temp_glyph_width) + count_j] = (U8) (0x00);
            }
            //gauss_sum = 0;
        } 
    }

    memset(pool_3, 0, pool_size);
    for(count_i = 0; count_i < temp_glyph_height; count_i++)
    {
        for(count_j = 0; count_j < temp_glyph_width; count_j++)
        {
            pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.border_transparency) / 100;
        }
    }

    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.bordered_color.a,
                                                            gFontEffectColorGroup.bordered_color.r,
                                                            gFontEffectColorGroup.bordered_color.g,
                                                            gFontEffectColorGroup.bordered_color.b);
    font_engine->set_font_color(text_color, border_color);

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;

    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_3, temp_glyph_width, temp_glyph_height, data_size, font_engine_antialias);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x, y, pool_1, (render->normal_data_size + sizeof(render)), 0, temp_glyph_width, temp_glyph_height, 0);
    FE_SWLA_STOP("SFD");
    
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    font_engine->set_font_color(text_color, border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + border_width, y + border_width, glyph_ptr, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    FE_SWLA_STOP("BOD");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_drop_shadow
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient_drop_shadow(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count_i, count_j, count_k;
    gdi_color border_color = 0, text_color;
    S32* gauss_fact;
    U32 gauss_sum = 0;
    U32 sumr = 0;
    U8 gray;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U16 temp_glyph_width = glyph_width, temp_glyph_height = glyph_height, border_width = gAdvanceFontAttribute.shadow_range;
    S32 x1,y1;
    S32* gauss_fact_array[5] = {gauss_fact1, gauss_fact2, gauss_fact3, gauss_fact4, gauss_fact5};
    S16 drop_shadow_degree = gAdvanceFontAttribute.shadow_degree;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDS");
    if(//gAdvanceFontAttribute.shadow_range < 0 || 
            gAdvanceFontAttribute.shadow_range > 5 || 
            //gAdvanceFontAttribute.shadow_distant < 0 || 
            gAdvanceFontAttribute.shadow_distant > 5 || 
            drop_shadow_degree < -180 || 
            drop_shadow_degree > 180 ||
            //gAdvanceFontAttribute.shadow_transparency < 0 ||
            gAdvanceFontAttribute.shadow_transparency > 100)
    {
        MMI_ASSERT(0);
    }
    
    if(drop_shadow_degree > 0)
    {
        drop_shadow_degree = drop_shadow_degree -180;
    }
    else
    {
        drop_shadow_degree = drop_shadow_degree +180;
    }
    if(drop_shadow_degree > 0)
    {
        if((drop_shadow_degree % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[drop_shadow_degree / ANGLE_ROTATION];
            y1 = degree_y[drop_shadow_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-drop_shadow_degree) % ANGLE_ROTATION) > ANGLE_ROTATION / 2)
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-drop_shadow_degree) / ANGLE_ROTATION + 5];
        }
    }

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    if(gAdvanceFontAttribute.shadow_range != 0)
    {
        gauss_fact = gauss_fact_array[gAdvanceFontAttribute.shadow_range - 1];

        memset(pool_1,0, pool_size);
        memset(pool_2,0, pool_size);
        memset(pool_3,0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        data_size = mmi_fe_data_frame(pool_2, pool_1, &temp_glyph_width, &temp_glyph_height, border_width);

        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j=0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < gAdvanceFontAttribute.shadow_range * 2 + 1; count_k++)
                {
                if ( 0 <= ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) && ((count_j - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k)) < temp_glyph_width)
                {
                    gauss_sum = gauss_sum + gauss_fact[count_k];
                    gray = pool_2[( count_i * temp_glyph_width) + (count_j - (((gAdvanceFontAttribute.shadow_range*2 + 1) - 1) >> 1) + count_k)];
                    sumr += gray * gauss_fact[count_k];
                    }
                }
                if ( gauss_sum != 0)
                {
                    pool_3[(count_i * temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_2, 0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                sumr = 0;
                for(count_k = 0; count_k < (gAdvanceFontAttribute.shadow_range * 2 + 1); count_k++)
                {
                    if ( 0 <= (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) && (count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1) - 1) >> 1) + count_k) < temp_glyph_height)
                    {
                        gauss_sum = gauss_sum + gauss_fact[count_k];
                        gray = pool_3[((count_i - (((gAdvanceFontAttribute.shadow_range * 2 + 1)-1) >> 1) + count_k) * temp_glyph_width) + count_j];
                        sumr += gray *gauss_fact[count_k];
                    }
                }
                if ( sumr != 0)
                {
                    pool_2[(count_i *  temp_glyph_width) + count_j] = (U8) (sumr / gauss_sum & 0xFF);
                }
                gauss_sum = 0;
            } 
        }

        memset(pool_3,0, pool_size);
        for(count_i = 0; count_i < temp_glyph_height; count_i++)
        {
            for(count_j = 0; count_j < temp_glyph_width; count_j++)
            {
                pool_3[(count_i * temp_glyph_width) + count_j] = (pool_2[(count_i * temp_glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }

        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_3, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x - border_width + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y - border_width + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        pool_1, 
                                                        (render->normal_data_size + sizeof(render)), 
                                                        0, 
                                                        temp_glyph_width, 
                                                        temp_glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }
    else
    {
        memset(pool_1, 0, pool_size);
        memset(pool_2, 0, pool_size);

        render = (mmi_fe_render_data_struct*) glyph_ptr;
        data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, glyph_size, font_engine_antialias);

        for(count_i = 0; count_i < glyph_height; count_i++)
        {
            for(count_j = 0; count_j < glyph_width; count_j++)
            {
                pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.shadow_transparency) / 100;
            }
        }
        text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.shadow_color.a,
                                                                gFontEffectColorGroup.shadow_color.r,
                                                                gFontEffectColorGroup.shadow_color.g,
                                                                gFontEffectColorGroup.shadow_color.b);
        font_engine->set_font_color(text_color, border_color);

        memset(pool_1, 0, pool_size);
        render = (mmi_fe_render_data_struct*) pool_1;
        render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), 
                                                                                                        pool_2, 
                                                                                                        temp_glyph_width, 
                                                                                                        temp_glyph_height, 
                                                                                                        data_size, 
                                                                                                        font_engine_antialias);

        render->normal_data_size = (render->normal_data_size + 3) & (~3);
        FE_SWLA_START("SFD");
        font_engine->show_font_data(ch, 
                                                        x + (x1 * gAdvanceFontAttribute.shadow_distant), 
                                                        y + (y1 * gAdvanceFontAttribute.shadow_distant), 
                                                        pool_1, 
                                                        (render->normal_data_size + sizeof(render)), 
                                                        0, 
                                                        glyph_width, 
                                                        glyph_height, 
                                                        0);
        FE_SWLA_STOP("SFD");
    }

    mmi_fe_show_font_data_gradient(ch,
                                                        x,
                                                        y,
                                                        glyph_ptr,
                                                        glyph_size,
                                                        glyph_width,
                                                        glyph_height);
    FE_SWLA_STOP("GDS");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data_gradient_engrave
 * DESCRIPTION
 *  To show gradient engraved character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_font_data_gradient_engrave(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U16 glyph_width,
                            U16 glyph_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    S32 x1,y1;
    int count_i,  count_j /*, count_k*/;
    S32 data_size = 0;
    mmi_fe_render_data_struct *render;
    U8 *pool_1 = NULL, *pool_2 = NULL, *pool_3 = NULL;
    U16 pool_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_SWLA_START("GDE");
    if(gAdvanceFontAttribute.engraved_degree < -180 ||
        gAdvanceFontAttribute.engraved_degree < 180 ||
        //gAdvanceFontAttribute.engraved_transparency < 0 ||
        gAdvanceFontAttribute.engraved_transparency > 100)
    {
        MMI_ASSERT(0);
    }

    if(mmi_fe_font_effect_pool_size)
    {
        pool_1 = g_mmi_fe_data_pool_1_ext;
        pool_2 = g_mmi_fe_data_pool_2_ext;
        pool_3 = g_mmi_fe_data_pool_3_ext;
        pool_size = mmi_fe_font_effect_pool_size;
    }
    else
    {
        pool_1 = g_mmi_fe_data_pool_1;
        pool_2 = g_mmi_fe_data_pool_2;
        pool_3 = g_mmi_fe_data_pool_3;
        pool_size = sizeof(g_mmi_fe_data_pool_1);
    }

    memset(pool_1, 0, pool_size);
    memset(pool_2, 0, pool_size);
    memset(pool_3, 0, pool_size);

    render = (mmi_fe_render_data_struct*) glyph_ptr;
    data_size = mmi_fe_data_convert_8bpp(pool_1, render->data, glyph_width, glyph_height, render->normal_data_size, font_engine_antialias);

    for(count_i = 0; count_i < glyph_height; count_i++)
    {
        for(count_j = 0; count_j < glyph_width; count_j++)
        {
            pool_2[(count_i * glyph_width) + count_j] = (pool_1[(count_i * glyph_width) + count_j] * gAdvanceFontAttribute.engraved_transparency) / 100;
        }
    }

    memset(pool_1, 0, pool_size);
    render = (mmi_fe_render_data_struct*) pool_1;
    render->normal_data_size = mmi_fe_data_convert_4bpp(&(render->data[0]), pool_2, glyph_width, glyph_height, data_size, font_engine_antialias);
    render->normal_data_size = (render->normal_data_size+3) & (~3);

    if(gAdvanceFontAttribute.engraved_degree > 0)
    {
        if((gAdvanceFontAttribute.engraved_degree % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION + 1];
        }
        else 
        {
            x1 = degree_x[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
            y1 = degree_y[gAdvanceFontAttribute.engraved_degree / ANGLE_ROTATION];
        }
    }
    else
    {
        if(((-gAdvanceFontAttribute.engraved_degree) % ANGLE_ROTATION) > (ANGLE_ROTATION / 2))
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 1 + 5];
        }
        else 
        {
            x1 = degree_x[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
            y1 = degree_y[(-gAdvanceFontAttribute.engraved_degree) / ANGLE_ROTATION + 5];
        }
    }



    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.upper_engraved_color.a,
                                                            gFontEffectColorGroup.upper_engraved_color.r,
                                                            gFontEffectColorGroup.upper_engraved_color.g,
                                                            gFontEffectColorGroup.upper_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x + x1, y + y1, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    text_color = gdi_act_color_from_rgb(gFontEffectColorGroup.lower_engraved_color.a,
                                                            gFontEffectColorGroup.lower_engraved_color.r,
                                                            gFontEffectColorGroup.lower_engraved_color.g,
                                                            gFontEffectColorGroup.lower_engraved_color.b);
    font_engine->set_font_color(text_color,border_color);
    FE_SWLA_START("SFD");
    font_engine->show_font_data(ch, x - x1, y - y1, pool_1, glyph_size, 0, glyph_width, glyph_height, 0);
    FE_SWLA_STOP("SFD");
    mmi_fe_show_font_data_gradient(ch,
                                                        x,
                                                        y,
                                                        glyph_ptr,
                                                        glyph_size,
                                                        glyph_width,
                                                        glyph_height);
    FE_SWLA_STOP("GDE");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_data_convert_8bpp
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_fe_data_convert_8bpp(U8* dest, U8* src, S32 width, S32 height, S32 size, MMI_BOOL antialias)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 inc1 = 0, inc2 = 1;
    S32 i, j, k;
    S32 data_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (antialias)
    {
        for(j=0;j<size;j++)
        {
            dest[inc1] = (((*src) & 0x0F)<<4);
            dest[inc2] =((((*src)>>4) & 0x0F)<<4);
            inc1 += 2;
            inc2 += 2;
            data_size +=2;
            src++;
        }
    }
    else
    {
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                for(k=0;k<8;k++)
                {
                    *(dest++) = (*src & (1<<k));
                }
                src++;
            }
        }
    }
    return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_data_convert_4bpp
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_fe_data_convert_4bpp(U8* dest, U8* src, S32 width, S32 height, S32 size, MMI_BOOL antialias)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 glyph_size = 0;
    int i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (antialias)
    {
        for(i=0;i<size;i+=2)
        {
            *dest++ = (src[1]&0xf0) | (src[0] >> 4);
            src+=2;
        }
        /*for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                *dest++ = (src[1]&0xf0) | (src[0] >> 4);
                src+=2;
            }
        }*/
        glyph_size = (size +1)>>1;
    }
    else
    {
        S32 pitch = width<<3;
        int skip_padding = ((pitch<<3) - width)>>3;
        int shift = 0;
        int base_shift = (8-width) & 0x7;

        glyph_size = (width*height+7)>>3;

        memset(dest,0,glyph_size);
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j+=8)
            {
                U32 s = (U32)(*src++);
                if(s)
                {
                    if(shift)
                    {
                        s <<= shift;
                        *dest++ |= mmi_fe_bits_revise_table[s>>8];
                        *dest   |= mmi_fe_bits_revise_table[s&0xff];
                    }
                    else
                        *dest++ |= mmi_fe_bits_revise_table[s];
                }
                else
                    dest++;
            }
            if(base_shift && !shift) dest--;
            if((shift+=base_shift) >8) dest--;
            shift&=0x7;
            src+=skip_padding;
        }
    }
    return glyph_size;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_data_frame
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_fe_data_frame(U8* dest, U8* src, U16* width, U16* height, U16 frame_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* ptr;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = dest;
    for(i=0;i<frame_width;i++)
    {
        memset(ptr,0,(frame_width + *width + frame_width));
        ptr = ptr + (frame_width + *width + frame_width);
    }

    for(i=0;i<*height;i++)
    {
        memset(ptr,0,frame_width);
        ptr = ptr + frame_width;

        memcpy(ptr,src,*width);
        ptr = ptr + *width;
        src = src + *width;

        memset(ptr,0,frame_width);
        ptr = ptr + frame_width;
    }

    for(i=0;i<frame_width;i++)
    {
        memset(ptr,0,(frame_width + *width + frame_width));
        ptr = ptr + (frame_width + *width + frame_width);
    }
    *width = frame_width + *width + frame_width;
    *height = frame_width + *height + frame_width;
    return (*width * *height);
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* defined(__MMI_FONT_EFFECTS__) */ 
/***********************************************************************************************************************************/
/*****************************************Font Effect's End*********************************************************************/
/***********************************************************************************************************************************/
BOOL mmi_fe_check_single_color_buffer_can_create(BOOL border)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    
    #if defined(__MMI_FONT_EFFECTS__)
    if(gFontEffect != FONT_EFFECT_NONE)
    {
        switch(gFontEffect)
        {
            case FONT_EFFECT_DROP_SHADOW:
            if (!(gFontEffectColorGroup.shadow_color.r == g_mmi_fe_text_color.r &&
                gFontEffectColorGroup.shadow_color.g == g_mmi_fe_text_color.g && 
                gFontEffectColorGroup.shadow_color.b == g_mmi_fe_text_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_OUTER_GLOW:
            if (!(gFontEffectColorGroup.outerglow_color.r == g_mmi_fe_text_color.r &&
                gFontEffectColorGroup.outerglow_color.g == g_mmi_fe_text_color.g && 
                gFontEffectColorGroup.outerglow_color.b == g_mmi_fe_text_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_ENHANCED_ENGRAVE:
            if (!(gFontEffectColorGroup.upper_engraved_color.r == g_mmi_fe_text_color.r &&
                gFontEffectColorGroup.upper_engraved_color.g == g_mmi_fe_text_color.g && 
                gFontEffectColorGroup.upper_engraved_color.b == g_mmi_fe_text_color.b))
            {
                ret = MMI_FALSE;
            }
            else if(!(gFontEffectColorGroup.lower_engraved_color.r == g_mmi_fe_text_color.r &&
                    gFontEffectColorGroup.lower_engraved_color.g == g_mmi_fe_text_color.g && 
                    gFontEffectColorGroup.lower_engraved_color.b == g_mmi_fe_text_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_GRADIENT:
            if (!(gFontEffectColorGroup.first_gradient_color.r == gFontEffectColorGroup.second_gradient_color.r &&
                gFontEffectColorGroup.first_gradient_color.g == gFontEffectColorGroup.second_gradient_color.g && 
                gFontEffectColorGroup.first_gradient_color.b == gFontEffectColorGroup.second_gradient_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_BORDER:
            if (!(gFontEffectColorGroup.bordered_color.r == g_mmi_fe_text_color.r &&
                gFontEffectColorGroup.bordered_color.g == g_mmi_fe_text_color.g && 
                gFontEffectColorGroup.bordered_color.b == g_mmi_fe_text_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_GRADIENT_DROP_SHADOW:
            if (!(gFontEffectColorGroup.first_gradient_color.r == gFontEffectColorGroup.second_gradient_color.r &&
                gFontEffectColorGroup.first_gradient_color.g == gFontEffectColorGroup.second_gradient_color.g && 
                gFontEffectColorGroup.first_gradient_color.b == gFontEffectColorGroup.second_gradient_color.b))
            {
                ret = MMI_FALSE;
            }
            else if (!(gFontEffectColorGroup.shadow_color.r == gFontEffectColorGroup.first_gradient_color.r &&
                    gFontEffectColorGroup.shadow_color.g == gFontEffectColorGroup.first_gradient_color.g && 
                    gFontEffectColorGroup.shadow_color.b == gFontEffectColorGroup.first_gradient_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            case FONT_EFFECT_GRADIENT_ENHANCED_ENGRAVE:
            if (!(gFontEffectColorGroup.first_gradient_color.r == gFontEffectColorGroup.second_gradient_color.r &&
                gFontEffectColorGroup.first_gradient_color.g == gFontEffectColorGroup.second_gradient_color.g && 
                gFontEffectColorGroup.first_gradient_color.b == gFontEffectColorGroup.second_gradient_color.b))
            {
                ret = MMI_FALSE;
            }
            else if (!(gFontEffectColorGroup.upper_engraved_color.r == gFontEffectColorGroup.lower_engraved_color.r &&
                    gFontEffectColorGroup.upper_engraved_color.g == gFontEffectColorGroup.lower_engraved_color.g && 
                    gFontEffectColorGroup.upper_engraved_color.b == gFontEffectColorGroup.lower_engraved_color.b))
            {
                ret = MMI_FALSE;
            }
            else if(!(gFontEffectColorGroup.first_gradient_color.r == gFontEffectColorGroup.upper_engraved_color.r &&
                    gFontEffectColorGroup.first_gradient_color.g == gFontEffectColorGroup.upper_engraved_color.g && 
                    gFontEffectColorGroup.first_gradient_color.b == gFontEffectColorGroup.upper_engraved_color.b))
            {
                ret = MMI_FALSE;
            }
                break;
            default:
                break;
        }
    }
    #endif

    if(gnCurrentFontAttrib & (FONTATTRIB_UNDERLINE | FONTATTRIB_STRIKETHROUGH))
    {
        ret = MMI_FALSE;
    }
    else if (border || gFontEffect == FONT_EFFECT_ENGRAVE)
    {
        if (!(g_mmi_fe_text_border_color.r == g_mmi_fe_text_color.r &&
            g_mmi_fe_text_border_color.g == g_mmi_fe_text_color.g && g_mmi_fe_text_border_color.b == g_mmi_fe_text_color.b))
        {
            ret = MMI_FALSE;
        }
    }

    GDI_UNLOCK;

    return ret;
}
/*-----------------------------------------------------------------------*/
/*--------------------------- *** End *** -------------------------------*/
/*-----------------------------------------------------------------------*/
#ifdef __MMI_SCRIPT_EASY__
extern stFontAttribute g_font_engine_attr;
static void fe_showstring_param_to_se_mtk_showstring_param(mmi_fe_showstring_int_param_struct_p fe_param, se_mtk_showstring_param_struct_p se_param)
{    
    memset(se_param, 0, sizeof(*se_param));
    se_param->x = fe_param->x;
    se_param->y = fe_param->y;
    se_param->char_gap = fe_param->char_gap;
    //se_param->Font = g_font_engine_attr; 
    se_param->BackGround = 0; //?
    se_param->String = fe_param->String;
    se_param->len = fe_param->len;
    se_param->BaseLineHeight = fe_param->BaseLineHeight;
    se_param->Bordered = fe_param->Bordered;
    se_param->enable_truncated = fe_param->enable_truncated;
    se_param->truncated_symbol = fe_param->truncated_symbol;
    se_param->truncated_symbol_start = fe_param->truncated_symbol_start;
    se_param->visible_x_start = fe_param->visible_x_start;
    se_param->visible_x_end = fe_param->visible_x_end;
    se_param->assign_direction = fe_param->assign_direction;
    se_param->LineHeight = 0; //
    se_param->LineHeightDiff = 0;//?
    se_param->border_color = fe_param->border_color;
    se_param->text_color = fe_param->text_color;
    se_param->font_attr = 0; //
    se_param->render_flag = fe_param->render_flag;    
}

static U32 mmi_fe_show_string_int_internal(mmi_fe_showstring_int_param_struct_p param)
{
    se_mtk_showstring_param_struct se_param;    
    fe_showstring_param_to_se_mtk_showstring_param(param, &se_param);
    return se_mtk_show_string_ext(&se_param);
}

static U32 mmi_fe_show_string_int(mmi_fe_showstring_int_param_struct_p param)
{
    if (mmi_fe_get_r2l_state() && !cancelWidth)
    {
        mmi_fe_get_string_info_param_struct query;
        query.String = param->String;
        query.n = param->len;
        query.w = param->char_gap;
        query.enableTruncated = MMI_FALSE;
        query.targetWidth = -1;

        mmi_fe_get_string_widthheight(&query);
        param->x = param->x - query.pWidth + 1;
    }

    return mmi_fe_show_string_int_internal(param);
}

void mmi_fe_show_char_at_xy(S32 x, S32 y, U16 ch)
{
    se_mtk_print_character_at_xy(ch, x, y);
}

U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
{
    return se_mtk_get_string_widthheight(query);
}

void mmi_fe_show_single_cluster(mmi_fe_show_one_cluster_param_struct_p param)
{
    mmi_fe_showstring_int_param_struct fe_param;

    memset(&fe_param, 0, sizeof(fe_param));
    
    fe_param.Bordered = param->bordered;
    fe_param.String = param->string;
    fe_param.len = param->len;
    fe_param.x = param->x;
    fe_param.y = param->y;
    mmi_fe_show_string_int_internal(&fe_param);
}

MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix)
{    
    int width, height;
    se_mtk_measure_character(ch, &width, &height);
    matrix->width = (U16)width;
    matrix->height = (U16)height;
    matrix->descent = matrix->height >> 2;
    matrix->ascent = matrix->height - matrix->descent;
    matrix->adv_x = matrix->width;
    
    return MMI_TRUE;
}

MMI_BOOL mmi_fe_check_string(stFontAttribute font, U8* string, S32 len)
{
    return MMI_TRUE;
}

U32 mmi_fe_get_string_widthheight_varient(mmi_fe_get_string_info_param_struct_p query)
{
    return mmi_fe_get_string_widthheight(query);
}

#endif


