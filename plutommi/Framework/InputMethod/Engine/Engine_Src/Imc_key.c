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
 *    Imc_key.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "mmi_include.h"

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#include "ImeQwertyProt.h"
#endif

#include "IMERes.h"

#include "wgui_softkeys.h"
#include "CommonScreens.h"

#include "Word_engine.h"

#include "Multitap_engine.h"
#include "Imc_symbol.h"
#include "Imc.h"
#include "Imui.h"
#include "ImmProt.h"
#include "Imc_key.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "Imc_pen.h"
#endif

#ifdef __MMI_VUI_ENGINE__
#include "framework\vadp_p2v_uc.h"
#include "ime\vadp_p2v_input_server_interface.h"
#endif


/* RHR ADD */
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "ImeGprot.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_categories_list.h"
#include "Imc_config.h"
#include "gdi_include.h"
#include "kal_release.h"
#include "gui.h"
#include "string.h"
#include "mmi_frm_input_gprot.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_cb_mgr_gprot.h"
#include "wgui_include.h"
#include "gui_buttons.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_res.h"
#include "mmi_frm_events_gprot.h"
#include "gui_inputs.h"
#include "gui_effect_oem.h"
//#include "vmsys.h"
#include "wgui_inputs.h"
#include "wgui_categories_inputs.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_rp_app_uiframework_def.h"

#ifdef __MMI_IME_PLUG_IN__
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif

/*****************************************************************************
 *  Define
 *****************************************************************************/

#define __MMI_DEFAULT_SOFTKEY_LAYOUT
#define MMI_IMC_KEY_MULTITAP_TIMER 500

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)
#define MMI_IMC_KEY_SMART_ALPHABETIC_WORD_RESELECTION_LAUNCH_TIMER (1000)
#endif


/*****************************************************************************
 *  Typedef
 *****************************************************************************/

typedef MMI_BOOL    (*mmi_imc_key_handler_funcptr)( mmi_imc_key_custom_value key_code, U16 event_type );
typedef MMI_BOOL    (*mmi_imc_qwerty_key_handler_funcptr)(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
typedef void        (*mmi_imc_key_timeout_funcptr)( void );
typedef MMI_BOOL (*mmi_imc_symbol_key_check_funcptr)( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code );
typedef S32 (*mmi_imc_key_get_candidate_funcptr)(S32 index);
typedef S32 (*mmi_imc_key_get_composition_funcptr)(S32 index);
typedef S32 (*mmi_imc_key_get_associative_funcptr)(S32 index);


/*****************************************************************************
 *  Define
 *****************************************************************************/

#define MMI_IMC_KEY_MULTITAP_TIMEOUT_DURATION   (1000)
#define MMI_IMC_KEY_FLAG_TIMER_STARTED          (0x01)

/*****************************************************************************
 * Typedef 
 *****************************************************************************/


typedef struct
{
#if  !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)  || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
    mmi_imc_key_handler_funcptr     key_down_handler;
    mmi_imc_key_handler_funcptr     key_up_handler;
    mmi_imc_key_handler_funcptr     key_repeat_handler;
    mmi_imc_key_handler_funcptr     key_long_handler;
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    mmi_imc_qwerty_key_handler_funcptr    qwerty_key_down_handler;
    mmi_imc_qwerty_key_handler_funcptr    qwerty_key_up_handler;
    mmi_imc_qwerty_key_handler_funcptr    qwerty_key_long_press_handler;
    mmi_imc_qwerty_key_handler_funcptr    qwerty_key_repeat_handler;
#endif
    U16 curr_mmi_key_code;
    U16 curr_mmi_key_type;
    mmi_imc_key_custom_value        last_imc_key_code;
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    U16  ucs2_value;
    U32  last_ucs2_value;
    U32  curr_special_key_flag;  
    U32  special_key_flag;
#endif
}   mmi_imc_key_info_struct, *mmi_imc_key_info_struct_p;

typedef struct
{
    S32 spell_multitap_index;
    mmi_imc_key_info_struct             key_info;
#if defined(__MMI_IME_MAGIC_ONE__)
    mmi_imc_key_info_struct            key_info_backup;
#endif
    mmi_imm_input_mode_enum curr_mode;
    const sIMEModeDetails               *curr_mode_details;
    mmi_imc_global_data_struct_p        global_data_ptr;
    mmi_imc_symbol_key_check_funcptr key_check_funcptr;
	mmi_imc_pre_key_handler  pre_key_handler;     
}   mmi_imc_key_object_struct, *mmi_imc_key_object_struct_p;

/*****************************************************************************
 * Local functions
 *****************************************************************************/

/* common functions*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static S16 mmi_imc_key_get_opposite_key_for_stroke(S16 mmi_key_code);
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_CSTAR_PHRASE_INPUT__)
static void mmi_imc_key_insert_comp(void);
#endif

U32  mmi_imc_key_send_message( U8 msg_id, U32 param_0, U32 param_1 );  
static U32  mmi_imc_key_send_ui_message( U8 msg_id, U32 param_0, U32 param_1 );

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static mmi_imc_key_custom_value mmi_imc_qwerty_key_translate_event( mmi_keypads_enum key_code, mmi_key_types_enum event_type, U16 ucs2_value, U32 special_flag );
#endif
#if  !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
static mmi_imc_key_custom_value mmi_imc_key_translate_event( mmi_keypads_enum key_code, mmi_key_types_enum event_type );
static mmi_ret mmi_imc_key_non_qwerty_key_proc(mmi_event_struct *evt);
#endif 

static mmi_imc_key_custom_value mmi_imc_key_translate_arrow_key(mmi_keypads_enum key_code);
static mmi_imc_key_custom_value mmi_imc_key_translate_pound_key(mmi_key_types_enum event_type);
static mmi_imc_key_custom_value mmi_imc_key_translate_star_key(mmi_key_types_enum event_type);
 

static UI_string_type mmi_imc_key_extract_candidate_by_index(S32 index);
static MMI_BOOL mmi_imc_key_add_symbol(U16 sym);
static MMI_BOOL mmi_imc_key_add_key_symbol(mmi_imc_key_custom_value sym);
static U16      mmi_imc_key_get_symbol_by_imc_key(mmi_imc_key_custom_value sym);

static mmi_imc_key_custom_value  mmi_imc_key_custom_mapping( mmi_keypads_enum mmi_key );


/* function to attach key handler */
static void mmi_imc_key_attach_smart_alphabetic_key_handler(void);
static void mmi_imc_key_attach_multitap_alphabetic_key_handler(void);
static void mmi_imc_key_attach_smart_phonetic_key_handler(void);
static void mmi_imc_key_attach_multitap_phonetic_key_handler(void);
static void mmi_imc_key_attach_stroke_key_handler(void);

/* multitap alphabetic multitap functions */

static MMI_BOOL mmi_imc_key_multitap_alphabetic_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_multitap_alphabetic_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_multitap_alphabetic_long_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_multitap_alphabetic_timeout_callback( void );
static MMI_BOOL mmi_imc_key_alphabeitc_get_multitap_candidate(S32 index);

/* smart alphabetic functions */
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_smart_alphabetic_delete_candidate(void);
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
static void mmi_imc_key_samrt_alphabetic_update_input_area(MMI_BOOL add_space);
static void mmi_imc_key_smart_alphabetic_recover_input(void);
static MMI_BOOL mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_BOOL space);
static void mmi_imc_key_smart_alphabetic_remove_input(S32 index);
static MMI_BOOL mmi_imc_key_smart_phonetic_delete_confirm_string(S32 len);
static void mmi_imc_key_smart_alphabetic_move_to_begin(void);
#endif

#if defined(__MMI_IME_USER_DATABASE__)
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
static void mmi_imc_key_smart_alphabetic_add_new_word_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_smart_alphabetic_add_new_word_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_smart_alphabetic_add_new_word_key_long_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_smart_alphabetic_add_new_word_timeout_callback( void );
static void mmi_imc_key_add_new_word_update_input_area(S32 highlight_start_index, S32 highlight_num, S32 cursor_index);
#endif
static void mmi_imc_insert_char_into_string(UI_string_type str_ptr, UI_character_type char_code, S32 index);
static void mmi_imc_delete_char_from_string(UI_string_type str_ptr, S32 index);
static MMI_BOOL mmi_imc_key_is_new_word_cursor_movement_disabled(void);
#endif

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
S32 mmi_imc_key_smart_alphabetic_get_associated_words(UI_string_type str, S32 index);
#endif

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)  
static void mmi_imc_key_start_smart_alphabetic_word_reselection(void);
static void mmi_imc_key_cancel_smart_alphabetic_word_reselection(void);
#endif


/* multitap phonetic functions */
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_multitap_phonetic_get_composition(mmi_imc_key_custom_value key_code);
static MMI_BOOL mmi_imc_key_get_multitap_next_candidate(void);
static MMI_BOOL mmi_imc_key_insert_multitap_char_by_index(S32 index);
static void mmi_imc_key_multitap_phoetic_timeout_callback(void);
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
static MMI_BOOL mmi_imc_key_multitap_phonetic_select_candidate(void);
static S32 mmi_imc_key_multitap_phonetic_get_candidate(void);
static S32 mmi_imc_key_multitap_phoetic_get_candidate_with_tone(void);
#endif
static S32 mmi_imc_key_phonetic_key_query_candidate_with_tone(U16 tone);

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
static S32 mmi_imc_key_stroke_first_symbol( mmi_imc_key_custom_value key_code, U16 event_type );
#endif

/* stroke functions */
static MMI_BOOL mmi_imc_key_stroke_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_stroke_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_stroke_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static U16 mmi_imc_key_stroke_get_sym_by_key(U8 key_code);
static U16 mmi_imc_key_stroke_get_code_by_key(U8 key_code);

/* smart phonetic functions */
static MMI_BOOL mmi_imc_key_smart_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_smart_phonetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_smart_phonetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
S32 mmi_imc_key_smart_phonetic_get_candidate(MMI_BOOL match_comp);
static MMI_BOOL mmi_imc_key_smart_phonetic_select_candidate(void);
static MMI_BOOL mmi_imc_key_smart_phonetic_insert_key(mmi_imc_key_custom_value key_code);
static MMI_BOOL mmi_imc_key_smart_phonetic_delete_key(void);
static MMI_BOOL mmi_imc_key_smart_phonetic_move_key_buffer_cursor(MMI_BOOL dic);
static void mmi_imc_key_smart_phonetic_update_input_area(void);

#else
S32 mmi_imc_key_smart_phonetic_get_composition(S32 index);
#endif

/* direct input functions */
static MMI_BOOL mmi_imc_key_direct_input_handler( mmi_imc_key_custom_value key_code, U16 event_type );


static MMI_BOOL mmi_imc_key_direct_input_key_check( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code );

static void mmi_imc_key_common_clear_key_handler(void);
static MMI_BOOL mmi_imc_key_editor_empty(void);

/* common function to add or delete key symbol into key buffer */
static MMI_BOOL mmi_imc_key_add_key_element(mmi_imc_key_custom_value key_code);
static MMI_BOOL mmi_imc_key_delete_key_element(void);
static S32 mmi_imc_key_get_candidate_prev_page(void);
static S32 mmi_imc_key_get_candidate_next_page(void);

/* common function for Chinese input method */
#if 0
/* under construction !*/
#endif
static void mmi_imc_key_change_input_mode(void);
static void mmi_imc_key_entry_symbol_picker(void);
static void mmi_imc_key_switch_between_smart_and_multitap(void);
static void mmi_imc_key_process_before_changing_input_mode(void);


#if defined(__MMI_IMC_CAPITAL_SWITCH__)
static void mmi_imc_key_input_method_screen_close_function(void);
#if !defined(__MMI_IME_AUTO_CAPITALIZATION__)
static MMI_BOOL mmi_imc_key_are_the_two_cases_same_in_current_page(mmi_ime_word_capital_state_enum case1, mmi_ime_word_capital_state_enum case2);
#endif
#endif


#if defined(__MMI_IME_MAGIC_ONE__)
static void mmi_imc_key_magic_state_update_candidate(void);
static S32 mmi_imc_key_magic_state_get_candidate(MMI_BOOL focus);
static MMI_BOOL mmi_imc_key_magic_state_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_magic_state_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_magic_state_key_long_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static void mmi_imc_key_change_to_magic_one_state(void);
static void mmi_imc_key_magic_state_chage_cand_cap(void);

#endif


static MMI_BOOL mmi_imc_key_phone_number_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_phone_number_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_phone_number_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type );
static MMI_BOOL mmi_imc_key_phone_number_key_repeat_handler( mmi_imc_key_custom_value key_code, U16 event_type );


#if defined(__MMI_TOUCH_SCREEN__)
static void mmi_imc_key_rsk_pen_up_post_handler(void);
static void mmi_imc_key_delete_hand_writing_cand_timer(void);
#endif

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static MMI_BOOL mmi_imc_key_qwerty_group_key_down_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_group_key_up_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_group_key_long_press_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_group_key_repeat_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_down_event(void);
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_up_event(void);
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_long_press_event(void);
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_repeat_event(void);

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
#endif

static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_valuee, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_stroke_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_direct_input_key_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_common_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_common_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

static MMI_BOOL mmi_imc_key_qwerty_num_lock_change_input_mode(void);

static void mmi_imc_key_set_shift_caps(U32  special_key, MMI_BOOL  lock);

static void mmi_imc_key_confirm_word_callback(void);

static void mmi_imc_key_qwerty_special_key_flag_change_callback(U32 special_key_flag, U32 special_key_lock_flag); 

static void mmi_imc_key_qwerty_special_key_status_update_timer_callback(void);

static MMI_BOOL mmi_imc_key_qwerty_multitap_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code);

static MMI_BOOL mmi_imc_key_qwerty_phonetic_fn_input_symbol(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag);

#if defined __MMI_XT9__
static S32 mmi_imc_handle_fn_key_in_smart_mode(mmi_imc_key_custom_value key_code);
#endif

#endif /* #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ */

static MMI_BOOL mmi_imc_key_is_key_symbol(mmi_imc_key_custom_value key_code);

static MMI_BOOL mmi_imc_key_fast_number_input(mmi_keypads_enum key_code);

static void mmi_imc_key_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);

static void mmi_imc_key_get_current_key_info(U16 *keyCode, U16 *keyType);

static mmi_ret mmi_imc_key_rsk_up_post_handler(mmi_event_struct * evt);

/*****************************************************************************
 * Local variables
 *****************************************************************************/

/* We will register the required keys when activating key inputs */
static const U16    g_imc_key_required_key_code[] = 
{
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_STAR,
    KEY_POUND,
};

/*****************************************************************************
 * Local variables
 *****************************************************************************/
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
extern const U8 *SymbolPickerSymbols[];
#endif
static MMI_BOOL char_inserted=MMI_FALSE;
static mmi_imc_key_object_struct    g_imc_key;
static mmi_imui_message_struct       g_imui_msg;
void (*g_imc_key_inputbox_LSK_function) (void) = NULL;
void (*g_imc_key_inputbox_RSK_function) (void) = NULL;
static UI_string_type g_imc_key_lsk_text = NULL;
static UI_string_type g_imc_key_rsk_text = NULL;
 
//#if defined(__MMI_WGUI_CSK_ENABLE__)
void (*g_imc_key_inputbox_CSK_function) (void) = NULL;
static UI_string_type g_imc_key_csk_text = NULL;
static PU8 g_imc_key_csk_icon = NULL;
//static MMI_BOOL g_is_csk_registered_to_enter_key = MMI_FALSE;
//#endif

#if /*defined(__MMI_WGUI_CSK_ENABLE__) && */defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_320X480__)
static MMI_BOOL g_imc_key_is_csk_registered_to_ime = MMI_FALSE;
#endif

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
static U16 g_imc_key_active_editor_screen_id = 0;
#endif

 
#if defined(__MMI_MULTITAP_KEY_0__)
static MMI_BOOL g_is_zero_inserted = MMI_FALSE;
#endif
 
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
UI_character_type g_previous_word_buf[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
UI_character_type * mmi_imc_get_previous_word_buffer();
#endif
 
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
static mmi_imm_input_mode_enum g_imc_key_num_lock_pre_input_mode = IMM_INPUT_MODE_NONE;
static MMI_BOOL g_imc_key_special_key_hint_redrawing_flag = MMI_FALSE;
static U32 g_imc_key_multitap_special_key_flag = 0;
#endif

static MMI_BOOL g_imc_key_pound_is_insert_by_current_key_down = MMI_FALSE;

static mmi_imc_state_enum g_imc_key_down_state = MMI_IMC_STATE_NONE;

static S32 g_imc_key_down_text_length = 0;

static MMI_BOOL g_imc_key_is_editor_in_replace_mode_on_key_down = MMI_FALSE;

static S32 g_imc_directly_input_multitap_string_length = 0;

static S32 g_imc_key_cand_length_before_key_down = 0;

static MMI_BOOL g_imc_key_is_softkeys_changeable = MMI_TRUE;
 /*****************************************************************************
  * External function
  *****************************************************************************/
extern void (*wgui_register_multiline_inputbox_up_down_key_handler) (void);

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)

#define mmi_imc_key_sotre_key_info(key_buf, length, cursor)\
{\
    memcpy(key_buf, g_imc_key.global_data_ptr->key_buffer, sizeof(U16)*g_imc_key.global_data_ptr->key_element_length);\
    length = g_imc_key.global_data_ptr->key_element_length;\
    cursor = g_imc_key.global_data_ptr->key_buffer_cusor;\
}

#define mmi_imc_key_resotre_key_info(key_buf, length, cursor)\
{\
    memcpy(g_imc_key.global_data_ptr->key_buffer, key_buf, sizeof(U16)*length);\
    g_imc_key.global_data_ptr->key_element_length = length;\
    g_imc_key.global_data_ptr->key_buffer_cusor = cursor;\
}

#endif

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_get_opposite_key_for_stroke
 * DESCRIPTION
 *  get opposite key code 
 * PARAMETERS
 *  mmi_key_code		[IN]:   current key code
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mmi_imc_key_get_opposite_key_for_stroke(S16 mmi_key_code)
{
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
	mmi_imm_input_mode_enum cur_input_mode = mmi_imm_get_curr_input_mode();
	if(cur_input_mode == IMM_INPUT_MODE_SM_STROKE || cur_input_mode == IMM_INPUT_MODE_TR_STROKE)
	{
		return mmi_imm_qwerty_get_opposite_key_code(mmi_key_code);
	}
	else
	{
		return mmi_key_code;
	}
#else
	return mmi_key_code;	
#endif
}
#endif

#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_CSTAR_PHRASE_INPUT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_insert_comp
 * DESCRIPTION
 *  insert compsition when candidate box is empty
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imc_key_insert_comp(void)
{
	S32 i;
	UI_string_type cand_str;
	S32 count;
	BOOL lcd_freeze;
	UI_character_type comp_buff[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];

	memcpy(&comp_buff[0], g_imc_key.global_data_ptr->comp_buff, sizeof(UI_character_type) * MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                
	cand_str = mmi_imc_get_candidate_by_index(&comp_buff[0], 0);

if (cand_str)
{
	lcd_freeze = gdi_lcd_get_freeze();
	mmi_imc_gdi_lcd_freeze(MMI_TRUE); 

	count =  mmi_ucs2strlen((const S8 *)cand_str);

	for (i = 0; i < count; i++)
	{
		/* in case editor is already full we need not check further */ 
		if(!mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)cand_str[i], 0))
		break;
	}

	mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	mmi_imc_redraw_screen_by_state();
	mmi_imc_gdi_lcd_freeze(lcd_freeze);
	mmi_imc_repaint_screen();
}
}
#endif

void mmi_imc_delete_all()
{

    if (!mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_ALL, 0, 0);
    }
    else
    {
        UI_editor_play_tone_cannot_change();
    }    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_change_direct_input_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imc_direct_input_key_change_mode( const sIMEModeDetails *mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum mode_id = mode_details_ptr->imm_mode_id;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mode_id)
    {
        case IMM_INPUT_MODE_PHONE_NUMBER:
        case IMM_INPUT_MODE_SIM_NUMERIC:
        case IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR:
        /*#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
            ret = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
        #else

    #if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
        ret = MMI_TRUE;
    else
        ret = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
    #endif
            ret = MMI_TRUE;
        #endif*/
#if defined (__COSMOS_MMI_PACKAGE__)
                ret = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
            #else
             #if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
                ret = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
        #else
          ret = MMI_TRUE;
       #endif
        #endif
            break;
        case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
        case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
        case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:			
            ret = mmi_ime_word_change_mode( mode_details_ptr, reserved );
            break;
        default:
            ret = MMI_TRUE;
            break;
    }
    return ret;
}


void mmi_imc_key_handle_mode_change_key()
{
#if ((defined __MMI_COSMOS_KEYPAD_BAR__ || defined  __MMI_COSMOS_KEYPAD_SLIDER__) && !defined(__MMI_IME_V3__))
    mmi_imc_show_inputmode_list();
#else
    mmi_imc_key_change_input_mode();
#endif
    return ;
	
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_phone_number_key_down_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_imc_key_phone_number_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type char_code;
    mmi_imc_state_enum curr_state;
#if defined(__MMI_TOUCH_SCREEN__)
	mmi_imm_input_mode_enum old_mode;
#endif
     BOOL lcd_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    if(mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {
        if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
        {
            /* for arrow key, do nothing. */
            return MMI_TRUE;
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_change_input_mode();
            return MMI_TRUE;
        }

        old_mode = mmi_imm_get_curr_input_mode();

        mmi_imc_pen_confirm_handwriting_selection(); 

        if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;
        }

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

        /* In canceling timer, input mode may be changed by WCSS */
        if (old_mode != mmi_imm_get_curr_input_mode())
        {
            return MMI_TRUE;
        }

        mmi_imc_redraw_screen_by_state();
        return MMI_TRUE;
    }
#endif
    curr_state = mmi_imc_get_state();


#if defined(__MMI_MULTITAP_KEY_0__) 
    if (key_code == MMI_IMC_KEY_SYM_0)
    {
        switch (curr_state)
        {
        case MMI_IMC_STATE_INITIAL:
            mmi_imc_key_direct_input_handler(key_code, event_type);
            break;
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_delete_timer();
            mmi_imc_key_phone_number_key_repeat_handler(key_code, event_type);
            break;
        }

    }
    else if ( key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_9 )
    {
        if (curr_state == MMI_IMC_STATE_MULTITAP)
        {
            mmi_imc_cancel_timer();
        }
        mmi_imc_key_direct_input_handler(key_code, event_type);
    }
#else
    if ( key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9 )
    {
        if (curr_state == MMI_IMC_STATE_MULTITAP)
        {
            mmi_imc_cancel_timer();
        }
        mmi_imc_key_direct_input_handler(key_code, event_type);
    }
#endif    
    else if (key_code == MMI_IMC_KEY_SYM_POUND)
    {
        if (curr_state == MMI_IMC_STATE_MULTITAP)
        {
            mmi_imc_cancel_timer();
        }
        char_code = (UI_character_type)('#');
        if (mmi_imm_test_input(&char_code, 1))
        {
            g_imc_key_pound_is_insert_by_current_key_down = (MMI_BOOL)mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR, char_code, 0 );
            /* putting this check as if directlt set intial state , in dialer search FTE softkey gets painted over vk */   
            if (curr_state != MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
			mmi_imc_redraw_ime_indicator();
        }

    }
    else if (key_code == MMI_IMC_KEY_LEFT || key_code == MMI_IMC_KEY_RIGHT
        || key_code == MMI_IMC_KEY_UP || key_code == MMI_IMC_KEY_DOWN)
    {
        if (curr_state == MMI_IMC_STATE_MULTITAP)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            mmi_imc_cancel_timer();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
        }

        mmi_imc_key_common_arrow_key_handler(key_code, g_imc_key.key_info.curr_mmi_key_type);
        mmi_imc_redraw_screen_by_state();
    }
    else if (key_code == MMI_IMC_KEY_SYM_STAR)
    {
#if defined(__MMI_MULTITAP_KEY_0__)
        if (curr_state == MMI_IMC_STATE_MULTITAP)
        {
            mmi_imc_cancel_timer();
        }
        char_code = (UI_character_type)('*');
        if (mmi_imm_test_input(&char_code, 1))
        {
            mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR, char_code, 0 );
        }
#else
        switch (curr_state)
        {
        case MMI_IMC_STATE_INITIAL:
            /* insert the new candidate */
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            /* add symbol into symbol buffer */
            mmi_imc_key_add_key_symbol(key_code);
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
            /* get candidate if valid symbol */
            if (mmi_imc_key_alphabeitc_get_multitap_candidate(0))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);
                /* update candidate buffer */
                //mmi_imui_send_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX);                    
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else
            {
                g_imc_key.global_data_ptr->symb_count = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
            }
            break;
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_delete_timer();
            if (g_imc_key.global_data_ptr->symb_buff[0] != mmi_imc_key_get_symbol_by_imc_key(key_code))
            {
                /* confirm current input */
                mmi_imc_key_multitap_alphabetic_input_confirm();
                /* add new symbol */
                g_imc_key.global_data_ptr->symb_count = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                mmi_imc_key_add_key_symbol(key_code);
                mmi_imc_key_alphabeitc_get_multitap_candidate(0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
            }
            else
            {
                /* get new candidate */
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_get_multitap_next_candidate();
                /* replace the old candidate with the new one. */                
                mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_redraw_screen_by_state();
            }
            break;
        default:
            ASSERT(0);
            break;
        }
#endif

    }
    else if (key_code == MMI_IMC_KEY_CLEAR)
    {
        switch (curr_state)
        {
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            if (g_imc_key.global_data_ptr->cand_length > 0)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, g_imc_key.global_data_ptr->cand_length, 0);
            }
            else if (g_imc_key.global_data_ptr->cand_length == 0 && 
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX, 0, 0))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            }
            mmi_imc_cancel_timer();
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            break;
        case MMI_IMC_STATE_INITIAL:
            mmi_imc_key_common_clear_key_handler();
            break;
        default:
            break;
        }
    }
    else if (key_code == MMI_IMC_KEY_LSK)
    {
        switch (curr_state)
        {
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_cancel_timer();
            break;
        }
    }
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_change_input_mode();
            return MMI_TRUE;
        }
        else 
        {
            char_code = (UI_character_type)(g_imc_key.key_info.ucs2_value);

            if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR)
            {
                if (char_code == L'+' || char_code == L'p' || char_code ==  L'?')
                {

                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'+'))
                {
                    char_code = L'+';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'p'))
                {
                    char_code = L'p';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'?'))
                {
                    char_code = L'?';
                }
                else
                {
                    char_code = 0;
                }
            }
            else if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SIM_NUMERIC)
            {
                if (char_code == L'+' || char_code == L'#' || char_code ==  L'*')
                {

                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'+'))
                {
                    char_code = L'+';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'#'))
                {
                    char_code = L'#';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'*'))
                {
                    char_code = L'*';
                }
                else
                {
                    char_code = 0;
                }
            }
            else if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER)
            {
                if (char_code == L'+' || char_code == L'p' || char_code ==  L'w')
                {

                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'+'))
                {
                    char_code = L'+';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'p'))
                {
                    char_code = L'p';
                }
                else if (mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, L'w'))
                {
                    char_code = L'w';
                }
                else
                {
                    char_code = 0;
                }
            }
            else
            {
                char_code = 0;
            }

            if (char_code != 0)
            {
                if (mmi_imm_test_input(&char_code, 1))
                {
                    mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR, (U32)char_code, 0 );
                }
            }
        }
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_phone_number_key_up_handler
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_imc_key_phone_number_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_MULTITAP_KEY_0__) && (!defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined __MMI_COSMOS_KEYPAD_SLIDER__)
        g_is_zero_inserted = MMI_FALSE;
#endif

    g_imc_key_pound_is_insert_by_current_key_down = MMI_FALSE;

#if defined(__MMI_TOUCH_SCREEN__)
    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_select_candidate_from_candidate_box();
            mmi_imc_redraw_screen_by_state();
        }
        return MMI_TRUE;
    }
#endif
#if  !defined __MMI_QWERTY_KEYPAD_SUPPORT__     || defined __MMI_COSMOS_KEYPAD_SLIDER__
        if (key_code == MMI_IMC_KEY_SYM_0)
        {
            #if defined(__MMI_MULTITAP_KEY_0__)
            if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_start_timer(
                    MMI_IMC_KEY_MULTITAP_TIMER, 
                    mmi_imc_key_multitap_alphabetic_timeout_callback,             
                    mmi_imc_key_multitap_alphabetic_timeout_callback);
            }
            #endif
        }
        else if (key_code == MMI_IMC_KEY_SYM_STAR)
        {
#if defined(__MMI_MULTITAP_KEY_0__)
#else
            mmi_imc_delete_timer();
            mmi_imc_start_timer(
                MMI_IMC_KEY_MULTITAP_TIMER, 
                mmi_imc_key_multitap_alphabetic_timeout_callback,             
                mmi_imc_key_multitap_alphabetic_timeout_callback);
#endif

    }
#endif /*#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__ */
    if (key_code == MMI_IMC_KEY_LSK)
    {
        switch (mmi_imc_get_state())
        {
        case MMI_IMC_STATE_INITIAL:
            g_imc_key_inputbox_LSK_function();
            break;
        case MMI_IMC_STATE_MULTITAP:
            mmi_imc_cancel_timer();
            g_imc_key_inputbox_LSK_function();
            break;
        default:
            break;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_phone_number_key_long_press_handler
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_imc_key_phone_number_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
BOOL lcd_freeze = gdi_lcd_get_freeze();
#if defined(__MMI_MULTITAP_KEY_0__) /*&& (!defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined __MMI_COSMOS_KEYPAD_SLIDER__)*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if (key_code == MMI_IMC_KEY_SYM_0)
        {
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            /* add symbol into symbol buffer */
            mmi_imc_key_add_key_symbol(key_code);
            /* get candidate if valid symbol */
            #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
            #endif
            if (mmi_imc_key_alphabeitc_get_multitap_candidate(0) && g_is_zero_inserted)
            {
                g_is_zero_inserted = MMI_FALSE;
                if (g_imc_key.global_data_ptr->cand_count > 1)
                {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);

                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                g_imc_key.global_data_ptr->cand_length = mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, L'0', 0);

                mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                mmi_imc_start_timer(
                    MMI_IMC_KEY_MULTITAP_TIMER*2, 
                    mmi_imc_key_multitap_alphabetic_timeout_callback,             
                    mmi_imc_key_multitap_alphabetic_timeout_callback);
                mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);
                /* update candidate buffer */
                //mmi_imui_send_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX);                    
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, g_imc_key.global_data_ptr->cand_buff[0], 1);
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
        else
        {
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            if (g_imc_key.global_data_ptr->cand_count > 1)
            {
                /* insert the new candidate */
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);
                /* update candidate buffer */
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, g_imc_key.global_data_ptr->cand_buff[0], 1);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_redraw_screen_by_state();
            }
        }

    }
#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (key_code == MMI_IMC_KEY_CHANGE_LANGUAGE)
    {
        if (g_imc_key_pound_is_insert_by_current_key_down)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            g_imc_key_pound_is_insert_by_current_key_down = MMI_FALSE;
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
        }
        mmi_imc_key_entry_change_language_screen();
        return MMI_TRUE;
    }
#endif

    if (key_code == MMI_IMC_KEY_CHANGE_MODE)
    {
        if (g_imc_key_pound_is_insert_by_current_key_down)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            g_imc_key_pound_is_insert_by_current_key_down = MMI_FALSE;
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
        }
	#if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        return MMI_TRUE;
    }
     else if (key_code == MMI_IMC_KEY_CLEAN)
     {
        mmi_imc_delete_all();
        return MMI_TRUE;
     }
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_phone_number_key_repeat_handler
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_imc_key_phone_number_key_repeat_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_KEY_0__) /*&&(!defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined __MMI_COSMOS_KEYPAD_SLIDER__)*/
    if (key_code == MMI_IMC_KEY_SYM_0)
    {
        if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
        {
            /* get new candidate */
            mmi_imc_key_get_multitap_next_candidate();
            mmi_imc_restart_timer(
                    MMI_IMC_KEY_MULTITAP_TIMER, 
                    mmi_imc_key_multitap_alphabetic_timeout_callback,             
                    mmi_imc_key_multitap_alphabetic_timeout_callback);
            /* replace the old candidate with the new one. */                
            mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
            mmi_imc_redraw_screen_by_state();        
        }
    }
    else
    {
        return mmi_imc_key_phone_number_key_down_handler(key_code,event_type);

    }
#else
    return mmi_imc_key_phone_number_key_down_handler(key_code,event_type);
#endif

    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_direct_input_handler
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static void mmi_imc_key_attach_direct_input_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_imm_get_curr_input_mode())
    {
    case IMM_INPUT_MODE_PHONE_NUMBER:
    case IMM_INPUT_MODE_SIM_NUMERIC:
    case IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR:

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__

        {
            mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
            g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_phone_number_key_down_handler;
            g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_phone_number_key_up_handler;
            g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_phone_number_key_long_press_handler;
            g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_phone_number_key_repeat_handler;
        }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
        {
            g_imc_key.key_info.key_down_handler = mmi_imc_key_phone_number_key_down_handler;
            g_imc_key.key_info.key_up_handler = mmi_imc_key_phone_number_key_up_handler;
            g_imc_key.key_info.key_long_handler = mmi_imc_key_phone_number_key_long_press_handler;
            g_imc_key.key_info.key_repeat_handler = mmi_imc_key_phone_number_key_repeat_handler;
        }
#endif
        break;
    case IMM_INPUT_MODE_123:
    case IMM_INPUT_MODE_123_SYMBOLS:
    case IMM_INPUT_MODE_SIGNED_123:
    case IMM_INPUT_MODE_FLOAT_123:
    case IMM_INPUT_MODE_SIGNED_FLOAT_123:
    case IMM_INPUT_MODE_ARABIC_NUMERIC:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

    case IMM_INPUT_MODE_KEYPAD_NUMERIC:

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
        {
            mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
            #if defined __MMI_COSMOS_KEYPAD_BAR__
             mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
          #elif defined(__MMI_COSMOS_KEYPAD_SLIDER__) 
          if(mmi_imc_get_slider_status()== CLOSE)
	       {
          mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
	       }
	       else
	       {
           mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
        	}
          #endif
            g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_direct_input_key_handler;
            g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_direct_input_key_handler;
            g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_direct_input_key_handler;
            g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_direct_input_key_handler;
        }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
        {
            g_imc_key.key_info.key_down_handler = mmi_imc_key_direct_input_handler;
            g_imc_key.key_info.key_up_handler = mmi_imc_key_direct_input_handler;
            g_imc_key.key_info.key_long_handler = mmi_imc_key_direct_input_handler;
            g_imc_key.key_info.key_repeat_handler = mmi_imc_key_direct_input_handler;
        }
#endif
        break;


    }

}

/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_rsk_function
* DESCRIPTION
*  
* PARAMETERS
*  f       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_rsk_function(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        g_imc_key_inputbox_RSK_function = UI_dummy_function;
    }
    else
#endif
    {
        g_imc_key_inputbox_RSK_function = f;
    }
}


/*#if defined(__MMI_WGUI_CSK_ENABLE__)*/
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_setup_csk_function
* DESCRIPTION
*  
* PARAMETERS
*  f       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_csk_function(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        g_imc_key_inputbox_CSK_function = UI_dummy_function;
    }
    else
#endif
    {
        g_imc_key_inputbox_CSK_function = f;
    } 

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_MAINLCD_320X480__)
    if (f != mmi_imc_key_change_input_mode && g_imc_key_is_csk_registered_to_ime) 
    {
        g_imc_key_is_csk_registered_to_ime = MMI_FALSE;
    }
#endif
}
//#endif
 /* #if defined(__MMI_WGUI_CSK_ENABLE__) */


/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_lsk_function
* DESCRIPTION
*  
* PARAMETERS
*  f       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_lsk_function(FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        g_imc_key_inputbox_LSK_function = UI_dummy_function;
    }
    else
#endif
    {
        g_imc_key_inputbox_LSK_function = f;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_custom_mapping
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value  mmi_imc_key_custom_mapping( mmi_keypads_enum mmi_key )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( mmi_key >= KEY_0 && mmi_key <= KEY_9 )
    {
        return (mmi_imc_key_custom_value)(MMI_IMC_KEY_SYM_0 + (mmi_key - KEY_0));
    }

    else if ( mmi_key == KEY_QWERTY)
        return  MMI_IMC_KEY_SYM_QWERTY;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    else if ( mmi_key >= KEY_A && mmi_key <= KEY_Z )
    {
        return (mmi_imc_key_custom_value)(MMI_IMC_KEY_SYM_A + (mmi_key - KEY_A));
    }
    else if (mmi_key == KEY_PERIOD)
    {
        return MMI_IMC_KEY_SYM_PERIOD;
    }

    else if (mmi_key == KEY_DOLLAR)
    {
        return MMI_IMC_KEY_SYM_DOLLAR;
    }
    else if (mmi_key == KEY_QUESTION)
    {
        return MMI_IMC_KEY_SYM_QUESTION;
    }
    else if (mmi_key == KEY_SYMBOL)
    {
        return MMI_IMC_KEY_SYMBOL_PICKER;
    }
    else if ( mmi_key == KEY_SPACE )
    {
        return MMI_IMC_KEY_SPACE;
    }
    else if ( mmi_key == KEY_NUM_LOCK)
    {
        return MMI_IMC_KEY_NUM_LOCK;
    }
    else if ( mmi_key == KEY_CLEAR)
    {
        return MMI_IMC_KEY_CLEAR;
    }
#endif
    else if ( mmi_key == KEY_UP_ARROW )
    {
        return MMI_IMC_KEY_UP;
    }
    else if ( mmi_key == KEY_DOWN_ARROW )
    {
        return MMI_IMC_KEY_DOWN;
    }
    else if ( mmi_key == KEY_LEFT_ARROW )
    {
        return MMI_IMC_KEY_LEFT;
    }
    else if ( mmi_key == KEY_RIGHT_ARROW )
    {
        return MMI_IMC_KEY_RIGHT;
    }
    else if ( mmi_key == KEY_LSK )
    {
#if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT)
        return MMI_IMC_KEY_CONFIRM; /* Confirm */
#else /* #if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT) */
        return MMI_IMC_KEY_CANCEL; /* Cancel */
#endif /* #if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT) */
    }
    else if ( mmi_key == KEY_RSK )
    {
#if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT)
        return MMI_IMC_KEY_CANCEL; /* Cancel */
#else /* #if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT) */
        return MMI_IMC_KEY_CONFIRM; /* Confirm */
#endif /* #if defined(__MMI_DEFAULT_SOFTKEY_LAYOUT) */
    }
    else if ( mmi_key == KEY_CLEAR )
    {
        return MMI_IMC_KEY_CLEAR;
    }
    else if ( mmi_key == KEY_POUND )
    {
        return MMI_IMC_KEY_SYM_POUND; /* Pound */
    }
    else if ( mmi_key == KEY_STAR )
    {
        return MMI_IMC_KEY_SYM_STAR; /* Star */
    }
    return MMI_IMC_KEY_INVALID;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_translate_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_key_translate_arrow_key(mmi_keypads_enum key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value imc_key_code = MMI_IMC_KEY_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
    case KEY_UP_ARROW:
        imc_key_code = MMI_IMC_KEY_UP;
        break;
    case KEY_DOWN_ARROW:
        imc_key_code = MMI_IMC_KEY_DOWN;
        break;
    case KEY_RIGHT_ARROW:
        imc_key_code = MMI_IMC_KEY_RIGHT;
        break;
    case KEY_LEFT_ARROW:
        imc_key_code = MMI_IMC_KEY_LEFT;
        break;    
    }

    if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL 
        && mmi_imc_get_state() != MMI_IMC_STATE_WORD_HIGHLIGHTED
        && mmi_imc_get_state() != MMI_IMC_STATE_MULTITAP)	
    {
        if (mmi_imm_test_r2l_input())
        {
            if (imc_key_code == MMI_IMC_KEY_LEFT)
            {
                imc_key_code = MMI_IMC_KEY_RIGHT;
            }
            else if (imc_key_code == MMI_IMC_KEY_RIGHT)
            {
                imc_key_code = MMI_IMC_KEY_LEFT;
            }
        }
    }

    return imc_key_code;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_translate_pound_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_key_translate_pound_key(mmi_key_types_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    MMI_BOOL is_change_lang_disabled = MMI_FALSE;
#if	!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && defined(__MMI_IME_USER_DATABASE__)
    UI_string_type str_ptr = NULL;
#endif
#endif
    mmi_imc_key_custom_value imc_key =  MMI_IMC_KEY_SYM_POUND;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)     || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    is_change_lang_disabled = mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0);
#endif

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (event_type == KEY_EVENT_UP)
    {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
                || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
                return MMI_IMC_KEY_CAPTITAL_SWITCH;
            }
            else
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
        }
        else
        {
            return MMI_IMC_KEY_INVALID;
        }
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */

#if !defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
            || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
        {
#if defined(__MMI_IME_USER_DATABASE__)
            str_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

            if (str_ptr != NULL)
            {
                if (str_ptr[0] != MMI_IME_USER_DATABASE_NEW_WORD)
                {
                    return MMI_IMC_KEY_CAPTITAL_SWITCH;
                }
            }	
#else
            return MMI_IMC_KEY_CAPTITAL_SWITCH;
#endif
        }
#endif	
        if (mmi_imm_get_current_writing_language() != IME_WRITING_LANG_TH
            && mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            return MMI_IMC_KEY_CHANGE_MODE;
        }
    }
    else if (event_type == KEY_LONG_PRESS && !is_change_lang_disabled
        && mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
        return MMI_IMC_KEY_CHANGE_LANGUAGE;
    }
#else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
    if ((event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT) && 
        mmi_imm_get_current_allowed_input_mode_num() > 1 &&
        !g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key) )
    {
        return MMI_IMC_KEY_CHANGE_MODE;
    }
    if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key) && 
        event_type == KEY_LONG_PRESS && 
        mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
        return MMI_IMC_KEY_CHANGE_MODE;
    }
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
#else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (event_type == KEY_EVENT_UP)
    {
				#if defined(__MMI_GUOBI__)
        if(mmi_imm_is_seemless_switching_enable() && (mmi_imc_get_state()==MMI_IMC_STATE_SPELL_INPUTING&&(g_imc_key.global_data_ptr->cand_select==0&&( g_imc_key.global_data_ptr->comp_buff[0]>='2'&&g_imc_key.global_data_ptr->comp_buff[0]<='9'))))
        {
         return MMI_IMC_KEY_SEEMLESS_SWITCH;
        }
				#endif
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
            if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
                || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
			#if defined(__MMI_IME_V3__)  //MAUI_03187687
				return MMI_IMC_KEY_CHANGE_MODE;
			#else
                return MMI_IMC_KEY_CAPTITAL_SWITCH;
			#endif
            }
            else
             #endif
            {
                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if(g_imc_key.curr_mode==IMM_INPUT_MODE_TR_STROKE||g_imc_key.curr_mode==IMM_INPUT_MODE_SM_STROKE||g_imc_key.curr_mode==IMM_INPUT_MODE_123_SYMBOLS)
                {
                  return MMI_IMC_KEY_INVALID;
                }
                #endif
                return MMI_IMC_KEY_CHANGE_MODE;
            }
        }
        else
        {
            return MMI_IMC_KEY_INVALID;
        }
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */

#if !defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE
            || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
        {
#if defined(__MMI_IME_USER_DATABASE__)
            str_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

            if (str_ptr != NULL)
            {
                if (str_ptr[0] != MMI_IME_USER_DATABASE_NEW_WORD)
                {
                    return MMI_IMC_KEY_CAPTITAL_SWITCH;
                }
            }	
#else
            return MMI_IMC_KEY_CAPTITAL_SWITCH;
#endif
        }
#endif

        if (mmi_imm_get_current_allowed_input_mode_num() > 1)
        {
            return MMI_IMC_KEY_CHANGE_MODE;
        }
    }
#if defined(__MMI_IME_V3__) && (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
	else if(event_type == KEY_LONG_PRESS)
	{
		return MMI_IMC_KEY_CHANGE_MODE;
	}
#else
    else if (event_type == KEY_LONG_PRESS && !is_change_lang_disabled
        && mmi_imm_get_current_allowed_writing_language_num() > 1)
    {
        return MMI_IMC_KEY_CHANGE_LANGUAGE;
    }
#endif
#else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */

#if defined(__MMI_IME_V3__)
	if(event_type == KEY_EVENT_UP || event_type == KEY_LONG_PRESS)
	{
		return MMI_IMC_KEY_CHANGE_MODE;
	}
#else

    if ((event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        && mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
        return MMI_IMC_KEY_CHANGE_MODE;
    }
    else if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key) && 
        event_type == KEY_LONG_PRESS && 
        mmi_imm_get_current_allowed_input_mode_num() > 1)
    {
        return MMI_IMC_KEY_CHANGE_MODE;
    }
#endif /* defined(__MMI_IME_V3__)*/
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */
#endif /*#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__ */

    return MMI_IMC_KEY_INVALID;

}
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_translate_symbol_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_key_translate_symbol_key(mmi_key_types_enum event_type)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
#if defined(__MMI_IME_V3__)
	if (mmi_imc_is_symbol_picker_disable() && (event_type != KEY_LONG_PRESS))
	{
		return MMI_IMC_KEY_INVALID;  //long press used for switch mutitap and smart
	}

	if (KEY_EVENT_UP == event_type)
	{
		return MMI_IMC_KEY_SYMBOL_PICKER;
	}
	else if (KEY_LONG_PRESS == event_type)
	{
		return MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP;
	}
	else
	{
		return MMI_IMC_KEY_INVALID;
	}
#else
	if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
	{
		return MMI_IMC_KEY_SYMBOL_PICKER;
	}
	else
	{
		return MMI_IMC_KEY_INVALID;
	}
#endif		
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_translate_star_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_key_translate_star_key(mmi_key_types_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
    mmi_imc_key_custom_value imc_key =  MMI_IMC_KEY_SYM_STAR;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_is_symbol_picker_disable() && event_type != KEY_LONG_PRESS) 
    {
        /* Long press may be used to switch between smart and multitap modes */
        return MMI_IMC_KEY_INVALID;
    } 

    if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_123
        && mmi_imm_get_curr_input_type() != IMM_INPUT_TYPE_NUMERIC_SYMBOL)
    {
        return MMI_IMC_KEY_INVALID;
    }

#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (event_type == KEY_EVENT_UP)
    {        
        if (!g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key) )
        {
            return MMI_IMC_KEY_SYMBOL_PICKER;
        }
    }
    else if (event_type == KEY_LONG_PRESS && g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
    {
        return MMI_IMC_KEY_SYMBOL_PICKER;
    }
    else if (event_type == KEY_LONG_PRESS)
    {
        return MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP;
    }
#else /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
    if (event_type == KEY_EVENT_UP && !g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
    {        
        return MMI_IMC_KEY_SYMBOL_PICKER;
    }
    else if (event_type == KEY_LONG_PRESS && g_imc_key.key_info.key_long_handler != mmi_imc_key_phone_number_key_long_press_handler)
    {
        return MMI_IMC_KEY_SYMBOL_PICKER;
    }
    else if (event_type == KEY_LONG_PRESS)
    {
        return MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP;
    }
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */
#else /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
    if (event_type == KEY_EVENT_UP)
    {
        return MMI_IMC_KEY_SYMBOL_PICKER;
    }
    else if (event_type == KEY_LONG_PRESS)
    {
		#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
		if(mmi_imm_get_curr_input_mode() ==IMM_INPUT_MODE_MULTITAP_BENGALI)
			
		{
			if(mmi_imc_get_state()==MMI_IMC_STATE_INITIAL && char_inserted)
			{
			mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
			char_inserted=MMI_FALSE;
			}
        return MMI_IMC_KEY_SYMBOL_PICKER ;
		}
		else
		#endif
		{
        return MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP;
    }
    }
#endif
#endif /* defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__) */

    return MMI_IMC_KEY_INVALID;
}

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_COSMOS_KEYPAD_SLIDER__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_translate_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_key_translate_event( mmi_keypads_enum key_code, mmi_key_types_enum event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value imc_key =  mmi_imc_key_custom_mapping(key_code);
    mmi_imc_state_enum state = mmi_imc_get_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (key_code == KEY_ENTER)
    {
        key_code = KEY_LSK;
    }

    switch(state)
    {
    case MMI_IMC_STATE_NONE:
        ASSERT(0);
        break;
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (key_code >= KEY_1 && key_code <= KEY_9)
            {
#ifdef __MMI_CSTAR_PHRASE_INPUT__
                /* no selection by digit label! */
                return imc_key;
#else
                /* to insert the candidate directly */
                return (key_code - KEY_1) + MMI_IMC_KEY_CHAR_1;
#endif
            }

            else  if ( key_code == KEY_QWERTY)
                return  MMI_IMC_KEY_SYM_QWERTY;

            else if (key_code == KEY_STAR)
            {
                return MMI_IMC_KEY_COMPOSITION_SELECT;
            }
            else if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }

            if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
            {
                return mmi_imc_key_translate_arrow_key(key_code);
            }
            else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }

        }
        if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
            if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                return MMI_IMC_KEY_CLEAR;
            }
            }
            else
            {
            if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }                           

            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        break;
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            if (key_code == KEY_STAR)
            {
                return MMI_IMC_KEY_COMPOSITION_SELECT;
            }

            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }

            if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
            {
                return mmi_imc_key_translate_arrow_key(key_code);
            }
            else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }

        }
        if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            else if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
            if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                return MMI_IMC_KEY_CLEAR;
            }
            }
            else
            {
            if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }                         

            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        break;
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
            {
                return mmi_imc_key_translate_arrow_key(key_code);
            }
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (key_code == KEY_0)
            {
                return MMI_IMC_KEY_SPACE;
            }
            else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }

        }
        if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        if (event_type == KEY_LONG_PRESS)
        {
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        break;
#endif        
    case MMI_IMC_STATE_INPUT:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
            {
                return mmi_imc_key_translate_arrow_key(key_code);
            }
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }
            else 
            {
                if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }
        }
        if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {   
            if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
                           

            if (key_code == KEY_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        break;
    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:	
    case MMI_IMC_STATE_HAND_WRITING_CAND:
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (key_code == KEY_LSK || key_code == KEY_ENTER)
                {
                    if (state == MMI_IMC_STATE_INITIAL)
                        return MMI_IMC_KEY_LSK;
                    else
                        return MMI_IMC_KEY_CONFIRM;
                }
                else if (imc_key == MMI_IMC_KEY_SYM_0)
                {
                    return MMI_IMC_KEY_SPACE;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }


                else if ( key_code == KEY_QWERTY)
                    return  MMI_IMC_KEY_SYM_QWERTY;

            }
        }
        else if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (key_code == KEY_CLEAR)
            {
                return MMI_IMC_KEY_CLEAN;
            }
            else if (key_code >= KEY_0 && key_code <= KEY_9)
            {
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER ||
                    mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR ||
                    mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SIM_NUMERIC)
                {
                    return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_SYM_0);
                }
                else
                {
                    return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
                }
            }

            else if ( key_code == KEY_QWERTY)
                return  MMI_IMC_KEY_SYM_QWERTY;

            else if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            else if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            else if (key_code == KEY_STAR)
            {
				#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
				if(mmi_imm_get_curr_input_mode() !=IMM_INPUT_MODE_MULTITAP_BENGALI)
                return mmi_imc_key_translate_star_key(event_type);
                #else
				return mmi_imc_key_translate_star_key(event_type);
				#endif
            }
            else
            {
                if (((mmi_imm_get_curr_input_type()) & IMM_INPUT_TYPE_EXT_PASSWORD))
                {
                    if (key_code >= KEY_0 && key_code <= KEY_9)
                    {
                        if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER ||
                            mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR ||
                            mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SIM_NUMERIC)
                        {
                            return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_SYM_0);
                        }
                        else
                        {
                            return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
                        }
                    }

                    else if ( key_code == KEY_QWERTY)
                        return  MMI_IMC_KEY_SYM_QWERTY;

                }
            }
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
#if defined(__MMI_IME_MAGIC_ONE__)
            if (mmi_imc_get_magic_key_down() && mmi_ime_word_is_symbol_key(IMM_INPUT_MODE_MAGIC_NUMBER, imc_key))
            {
                return imc_key;
            }
            else
#endif
                if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
                {
                    return imc_key;
                }
                else
                {
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
                    if (mmi_imc_is_floating_candidate_box_enabled() &&
                        (mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) &&
                        mmi_imc_key_translate_arrow_key(key_code) == MMI_IMC_KEY_RIGHT)
                    {
                        return MMI_IMC_KEY_SPACE;
                    }
#endif
                    if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                    {
                        return mmi_imc_key_translate_arrow_key(key_code);
                    }
                    else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                    {
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_MAGIC_ONE__)
                        if (state == MMI_IMC_STATE_PRE_SMART_CANDIDATE && mmi_imc_check_magic_state())
                            return MMI_IMC_KEY_CAPTITAL_SWITCH;
                        else
#endif
#endif
                            return mmi_imc_key_translate_star_key(event_type);
                    }
                    else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                    {
                        return mmi_imc_key_translate_pound_key(event_type);
                    }
                    else if (imc_key == MMI_IMC_KEY_SYM_0)
                    {
                        return MMI_IMC_KEY_SPACE;
                    }


                    else if ( key_code == KEY_QWERTY)
                        return  MMI_IMC_KEY_SYM_QWERTY;


                    else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                    {
                        if (key_code == KEY_RSK)
                        {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                            return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                            return MMI_IMC_KEY_RSK;
#endif
                        }
                        else if (key_code == KEY_CLEAR)
                        {
                            return MMI_IMC_KEY_CLEAR;
                        }
                    }
           else if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }

                }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
            if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                return MMI_IMC_KEY_CLEAR;
            }
            }
            else
            {
            if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }               
        }

        break;
    case MMI_IMC_STATE_MULTITAP:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (key_code == KEY_LSK)
                {
                    return MMI_IMC_KEY_LSK;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {   
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (key_code == KEY_CLEAR)
            {
                return MMI_IMC_KEY_CLEAN;
            }
            else if (key_code <= KEY_0 && key_code >= KEY_9)
            {
                return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
            }

            else if ( key_code == KEY_QWERTY)
                return  MMI_IMC_KEY_SYM_QWERTY;

            else if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            else if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            else if (key_code == KEY_LSK)
            {
                return MMI_IMC_KEY_LSK;
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        break;
    case MMI_IMC_STATE_SPELL_INPUTING:
    case MMI_IMC_STATE_SPELL_MULTITAP:
    case MMI_IMC_STATE_VK_CAND:
    case MMI_IMC_STATE_VK_CAND_MULTITAP:    
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
                    if (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
                    {
                        return MMI_IMC_KEY_TONE_CHANGE;
                    }
                    else
#endif                            
#endif
                        return mmi_imc_key_translate_star_key(event_type);
                }
                if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_MULTITAP || 
                mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND || 
                mmi_imc_get_state() ==MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                if (!g_imc_key.key_check_funcptr)
                {
                    return MMI_IMC_KEY_INVALID;
                }
                if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
                {
                    return imc_key;
                }                
            }
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (key_code == KEY_STAR)
            {
				//FTE2.0 MAUI_03124749 Star key will work as tone change when key_down
			#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
			#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
				if (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
				{
						return MMI_IMC_KEY_INVALID;
				}
			#endif
			#endif
                return mmi_imc_key_translate_star_key(event_type);
            }

            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }

        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
     if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
                                          
        }
        break;
    case MMI_IMC_STATE_CAND_SELECTING:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)

			if (key_code >= KEY_1 && key_code<= KEY_9)
            {
                return MMI_IMC_KEY_CHAR_1 + (key_code - KEY_1);
            }
#endif
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
                {
                    return imc_key;
                } 
          /*  if ((MMI_IMC_CANDIDATE_BOX_STYLE & MMI_IMUI_SELECTION_AREA_STYLE_LABEL))
            {
                if (key_code >= KEY_1 && key_code<= KEY_9)
                {
                    return MMI_IMC_KEY_CHAR_1 + (key_code - KEY_1);
                }*/
            

                else if ( key_code == KEY_QWERTY)
                    return  MMI_IMC_KEY_SYM_QWERTY;

            //}
            
#if !defined(__MMI_IME_TONE_IN_STAR_KEY__)
            else if (imc_key >= MMI_IMC_KEY_SYM_0 && imc_key <= MMI_IMC_KEY_SYM_9)
            {
                return imc_key; /* For tone marks */
            }
#endif
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
                    if (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_STROKE ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_HK_STROKE ||                              
                        g_imc_key.curr_mode == IMM_INPUT_MODE_TR_STROKE)
                    {
                        return MMI_IMC_KEY_TONE_CHANGE;
                    }
                    else
#endif
#endif
                        return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
                else if (imc_key == MMI_IMC_KEY_SYM_STAR && 
                    (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_STROKE ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_HK_STROKE ||                              
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_STROKE))
                {
                    return MMI_IMC_KEY_TONE_CHANGE;
                }
#endif
#endif
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {    
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
          else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
				//FTE2.0 MAUI_03124749 Star key will work as tone change when key_down
				#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
				#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
                if (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_STROKE ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_HK_STROKE ||                              
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_STROKE)
                {
                    return MMI_IMC_KEY_INVALID;
                }
				#endif
				#endif
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
       if (key_code == KEY_RSK)
            {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                    return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                    return MMI_IMC_KEY_RSK;
#endif
                }
                else if (key_code == KEY_CLEAR)
                {
                return MMI_IMC_KEY_CLEAR;
            }
            }
            else
            {
       if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }                            
        }

        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (!g_imc_key.key_check_funcptr)
            {
                return MMI_IMC_KEY_INVALID;
            }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
           /* if ((MMI_IMC_CANDIDATE_BOX_STYLE & MMI_IMUI_SELECTION_AREA_STYLE_LABEL))
            {
                if (key_code >= KEY_1 && key_code<= KEY_9)
                {
                    return MMI_IMC_KEY_CHAR_1 + (key_code - KEY_1);
                }*/

                else if ( key_code == KEY_QWERTY)
                    return  MMI_IMC_KEY_SYM_QWERTY;

           // }
            if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, imc_key))
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (key_code == KEY_0)
                {
                    return MMI_IMC_KEY_SPACE;
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
			else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        break;
    case MMI_IMC_STATE_HAND_WRITING:
        break;
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECTING_GRID:
	case MMI_IMC_STATE_SPELL_INPUTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
	case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
	#if defined(__MMI_CSTAR_PHRASE_INPUT__)
	case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
	#endif
		if(event_type == KEY_EVENT_DOWN || event_type == KEY_LONG_PRESS)
		{
		  if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
		}
		break;
	#endif

    case MMI_IMC_STATE_PREDICTING:
        break;

#if defined(__MMI_IME_USER_DATABASE__) && (!defined(__MMI_QWERTY_KEYPAD_SUPPORT__)|| defined(__MMI_COSMOS_KEYPAD_SLIDER__))
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (mmi_ime_multitap_is_symbol_key(mmi_ime_get_current_multitap_input_mode(), imc_key))
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (key_code == KEY_LSK)
                {
                    return MMI_IMC_KEY_LSK;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
#if defined(__MMI_IME_FTE_ENHANCE__) 
                        return MMI_IMC_KEY_CLEAR;  /* As for FTE we need alphanumeric support */
#else
                        return MMI_IMC_KEY_RSK;
#endif
                    }
                    else if (key_code == KEY_CLEAR)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
								else if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
        }
        else if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (key_code == KEY_CLEAR || key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_CLEAN;
            }
            else if (key_code <= KEY_0 && key_code >= KEY_9)
            {
                return ((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
            }

            else if ( key_code == KEY_QWERTY)
                return  MMI_IMC_KEY_SYM_QWERTY;

            else if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (mmi_ime_multitap_is_symbol_key(mmi_ime_get_current_multitap_input_mode(), imc_key))
            {
                return imc_key;
            }
            else if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_LSK;
            }
            else if (key_code == KEY_RSK)
            {
                return MMI_IMC_KEY_RSK;
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
            if (key_code == KEY_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
        }
        break;

#endif /* defined(__MMI_IME_USER_DATABASE__) */     

    default:
        break;

    }

    return MMI_IMC_KEY_INVALID;
}
#endif /* #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ */


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_init
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_init( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset( &g_imc_key, 0x0, sizeof(mmi_imc_key_object_struct) );
    g_imc_key.key_info.curr_mmi_key_code    = KEY_INVALID;
    g_imc_key.key_info.curr_mmi_key_type    = KEY_EVENT_DOWN;
    g_imc_key.key_info.last_imc_key_code    = MMI_IMC_KEY_INVALID;
    g_imc_key.pre_key_handler = NULL;

    /* attach data buffer */
    g_imc_key.global_data_ptr = mmi_imc_get_global_data();

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_register_ime_keys
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_register_ime_keys( void )
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_DOWN );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_UP );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_REPEAT );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_LONG_PRESS);
#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
#endif
        {
            MMI_WGUI_SET_KEY_PROC(mmi_imc_key_qwerty_key_proc, NULL);
        }
    }
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    else
#endif
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        mmi_imc_key_set_group_key_handler( mmi_imc_key_group_key_down, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_DOWN );
        mmi_imc_key_set_group_key_handler( mmi_imc_key_group_key_up, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_UP );
        mmi_imc_key_set_group_key_handler( mmi_imc_key_group_key_repeat, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_REPEAT );
        mmi_imc_key_set_group_key_handler( mmi_imc_key_group_key_long, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_LONG_PRESS);
#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
#endif
        {
            MMI_WGUI_SET_KEY_PROC(mmi_imc_key_non_qwerty_key_proc, NULL);
        }
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_activate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_activate( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const sIMEModeDetails *mode_detail = g_imc_key.curr_mode_details;
    U16         lang_attr;
    U16         mode_attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang_attr = mode_detail->Lang_Special_Attrib;
    mode_attr = mode_detail->Mode_Special_Attrib;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
    mmi_frm_qwerty_register_customized_special_key_flag_change_callback(mmi_imc_key_qwerty_special_key_flag_change_callback);
#endif

    /* attach key handler */
    if ( lang_attr & IME_LANG_ATTR_ALPHABETIC )
    {
        if ( mode_attr & IME_MODE_ATTR_MULTITAP )
        {
            mmi_imc_key_attach_multitap_alphabetic_key_handler();
        }
        else if ( mode_attr & IME_MODE_ATTR_SMART )
        {
            mmi_imc_key_attach_smart_alphabetic_key_handler();
        }
    }
    else if ( lang_attr & IME_LANG_ATTR_PHONETIC )
    {
        if ( mode_attr & IME_MODE_ATTR_MULTITAP )
        {
            mmi_imc_key_attach_multitap_phonetic_key_handler();
        }
        else if ( mode_attr & IME_MODE_ATTR_SMART )
        {
            mmi_imc_key_attach_smart_phonetic_key_handler();
        }
    }
    else if ( lang_attr & IME_LANG_ATTR_STROKE )
    {
        if (!(mode_attr & IME_MODE_ATTR_DIRECT))
        {
            mmi_imc_key_attach_stroke_key_handler();
        }
        else
        {
            mmi_imc_key_attach_direct_input_handler();
        }
    }
    else if ( lang_attr & IME_LANG_ATTR_NUMBERIC )
    {
        mmi_imc_key_attach_direct_input_handler();

    }
    else if ( lang_attr & IME_LANG_ATTR_SYMBOLIC )
    {
    } 

    if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_MULTITAP_STATE, 0, 0);
        mmi_imc_delete_timer();
        mmi_imc_start_timer(
            MMI_IMC_KEY_MULTITAP_TIMER*5, 
            mmi_imc_key_multitap_alphabetic_timeout_callback,             
            mmi_imc_key_multitap_alphabetic_timeout_callback);
    }
    else
    {
        g_imc_key.key_info.last_imc_key_code    = MMI_IMC_KEY_INVALID;
    }

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        g_imc_key_inputbox_LSK_function = UI_dummy_function;
        g_imc_key_inputbox_RSK_function = UI_dummy_function;
//#if defined(__MMI_WGUI_CSK_ENABLE__)
        g_imc_key_inputbox_CSK_function = UI_dummy_function;
//#endif
    } 
#endif    

}


/*****************************************************************************
* FUNCTION
*  imc_key_exit_editor
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_deactivate( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        g_imc_key.key_info.qwerty_key_down_handler     = NULL;
        g_imc_key.key_info.qwerty_key_up_handler       = NULL;
        g_imc_key.key_info.qwerty_key_repeat_handler   = NULL;
        g_imc_key.key_info.qwerty_key_long_press_handler     = NULL;
    }
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    else
#endif
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        g_imc_key.key_info.key_down_handler     = NULL;
        g_imc_key.key_info.key_up_handler       = NULL;
        g_imc_key.key_info.key_repeat_handler   = NULL;
        g_imc_key.key_info.key_long_handler     = NULL;
    }
#endif



    g_imc_key.key_info.curr_mmi_key_code    = KEY_INVALID;
    g_imc_key.key_info.curr_mmi_key_type    = KEY_EVENT_DOWN;

    g_imc_key.pre_key_handler               = NULL;

    g_imc_key_pound_is_insert_by_current_key_down = MMI_FALSE;

    g_imc_key_is_softkeys_changeable = MMI_TRUE;

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {

        mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
        mmi_imm_qwerty_change_lang(IME_WRITING_LANG_ABC);
        mmi_imm_set_special_key_icon(0, 0);
        mmi_frm_qwerty_clear_customized_special_key_flag_change_callback();
        mmi_frm_qwerty_reset_key_status();
    }
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    else
#endif
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_DOWN );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_EVENT_UP );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_LONG_PRESS );
        mmi_imc_key_set_group_key_handler( NULL, (PU16)g_imc_key_required_key_code,
            sizeof(g_imc_key_required_key_code)/sizeof(U16), KEY_REPEAT );
    }
#endif

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
        mmi_imm_qwerty_change_lang(IME_WRITING_LANG_ABC);
        mmi_imm_set_special_key_icon(0, 0);
        mmi_frm_qwerty_clear_customized_special_key_flag_change_callback();
        mmi_frm_qwerty_reset_key_status();
    }
#endif /* #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    //  g_imc_key_num_lock_pre_input_mode = IMM_INPUT_MODE_NONE;
    mmi_frm_qwerty_set_invalid_customized_special_key(0);
    g_imc_key_special_key_hint_redrawing_flag = MMI_FALSE;
    g_imc_key_multitap_special_key_flag = 0;
#endif

//#if defined(__MMI_WGUI_CSK_ENABLE__) 
  //  g_is_csk_registered_to_enter_key = MMI_FALSE; 
//#endif



}


/*****************************************************************************
* FUNCTION
*  imc_finalize_all
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_deinit( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


//MMI_BOOL mmi_ime_multitap_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code );
/*****************************************************************************
* FUNCTION
*  imc_initialize_all
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL    ret_val = MMI_FALSE;
    U16         lang_attr;
    U16         mode_attr;
#if defined(__MMI_IME_USER_DATABASE__)
    mmi_imui_message_struct imui_msg;
#endif
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) 
    const sIMEModeDetails * temp_mode_details_ptr;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( NULL == mode_details_ptr )
        return MMI_FALSE;

    /* reset data */
    g_imc_key.spell_multitap_index = -1;

    lang_attr = mode_details_ptr->Lang_Special_Attrib;
    mode_attr = mode_details_ptr->Mode_Special_Attrib;

    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_NONE;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    {
        ret_val = mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
    }
    {
        if ( lang_attr & IME_LANG_ATTR_ALPHABETIC )
        {
            if ( mode_attr & IME_MODE_ATTR_MULTITAP )
            {
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__) 

                if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
                {
                    temp_mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, IME_MODE_ATTR_LOWERCASE);

                    MMI_ASSERT(temp_mode_details_ptr);
				#if defined (__COSMOS_MMI_PACKAGE__)
                    ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
                #elif defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
					ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
				#endif
                }      
                else
#endif
                {
                #if defined (__COSMOS_MMI_PACKAGE__)
                    ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
                #elif defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
					ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
				#endif
                }
            }
        }
    }

#endif


    if ( lang_attr & IME_LANG_ATTR_ALPHABETIC )
    {
        if ( mode_attr & IME_MODE_ATTR_MULTITAP )
        {
#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) 
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__) 

            if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            {
                temp_mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(mode_details_ptr->imm_mode_id, IME_MODE_ATTR_LOWERCASE);

                MMI_ASSERT(temp_mode_details_ptr);

                ret_val = mmi_ime_multitap_change_mode( temp_mode_details_ptr, reserved );
            }      
            else
#endif
            {
                ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
            }
#endif
#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
            if(mmi_imc_get_slider_status()== OPEN)
#endif
            {
                ret_val = mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
            }
#endif

            if (ret_val )
            {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status()== OPEN)
#endif
                {
                    mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
                }
#endif
            }    

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
            g_imc_key.key_check_funcptr = mmi_ime_multitap_is_symbol_key;
#endif
#if defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
            g_imc_key.key_check_funcptr = mmi_imc_key_qwerty_multitap_is_symbol_key;
#endif
        }
        else if ( mode_attr & IME_MODE_ATTR_SMART )
        {
            /* There is not first upper case mode in word engine, */
            /* we use the lower case mode to get candidates       */
#if defined(__MMI_SMART_FIRST_UPPERCASE__) 
            if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
            {
                temp_mode_details_ptr = mmi_imm_get_corresponding_smart_lower_case_mode(mode_details_ptr->imm_mode_id);

                MMI_ASSERT(temp_mode_details_ptr);

                ret_val = mmi_ime_word_change_mode( temp_mode_details_ptr, reserved );

                mmi_ime_word_change_word_case(MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER);
            }      
            else
#endif
            {
                ret_val = mmi_ime_word_change_mode( mode_details_ptr, reserved );
            }

            if (ret_val)
            {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status()== OPEN)
#endif
                {                    
                    mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
                }
#endif
            }    

            g_imc_key.key_check_funcptr = mmi_ime_word_is_symbol_key;

#if defined(__MMI_IME_USER_DATABASE__)
            imui_msg.message_id = MMI_IMUI_MESSAGE_SET_NEW_WORD_PROMPT;
            imui_msg.param_0 = (U32)mmi_imm_get_new_word_string_by_language(mode_details_ptr->lang_id);
            mmi_imui_send_message(&imui_msg, NULL);
#endif
        }

        if ( mode_attr & IME_MODE_ATTR_UPPERCASE )
        {
            g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            g_imc_key.global_data_ptr->capital_lock = MMI_TRUE;
#endif
        }
        else if ( mode_attr & IME_MODE_ATTR_LOWERCASE )
        {
            g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            g_imc_key.global_data_ptr->capital_lock = MMI_TRUE;
#endif
        }
        else if ( mode_attr & IME_MODE_ATTR_TITLECASE )
        {
            g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            g_imc_key.global_data_ptr->capital_lock = MMI_FALSE;
#endif
        }

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
        mmi_imc_set_caps_seq_by_cur_state(0);
#endif
    }
    else if ( lang_attr & IME_LANG_ATTR_PHONETIC )
    {
        ret_val = mmi_ime_word_change_mode( mode_details_ptr, reserved );        
        g_imc_key.key_check_funcptr = mmi_ime_word_is_symbol_key;
        if ( mode_attr & IME_MODE_ATTR_MULTITAP )
        {
            /* init multitap engine for composition input */
            if (ret_val)
            {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
#endif
#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                ret_val = mmi_ime_multitap_change_mode( mode_details_ptr, reserved );
#endif
            }            
        }
        else if ( mode_attr & IME_MODE_ATTR_SMART )
        {
            if (ret_val)
            {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
#endif
            }        
        }

#if defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_SM_PINYIN)
        {
            imui_msg.message_id = MMI_IMUI_MESSAGE_SET_NEW_WORD_PROMPT;
            imui_msg.param_0 = (U32)mmi_imm_get_new_word_string_by_language(IME_WRITING_LANG_ABC);
            mmi_imui_send_message(&imui_msg, NULL);
        }
#endif
    }
    else if ( (lang_attr & IME_LANG_ATTR_STROKE) )
    {
        if (!(mode_attr & IME_MODE_ATTR_DIRECT))
        {
            ret_val = mmi_ime_word_change_mode( mode_details_ptr, reserved );        
            g_imc_key.key_check_funcptr = mmi_ime_word_is_symbol_key;
        }
        else
        {
            ret_val = mmi_imc_direct_input_key_change_mode( mode_details_ptr, reserved );
            g_imc_key.key_check_funcptr = mmi_imc_key_direct_input_key_check;
        }

        if (ret_val)
        {
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            mmi_imm_qwerty_change_lang(mode_details_ptr->lang_id);
#endif
        }    

#if defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        imui_msg.message_id = MMI_IMUI_MESSAGE_SET_NEW_WORD_PROMPT;
        imui_msg.param_0 = (U32)mmi_imm_get_new_word_string_by_language(IME_WRITING_LANG_ABC);
        mmi_imui_send_message(&imui_msg, NULL);
#endif
    }
    else if ( lang_attr & IME_LANG_ATTR_NUMBERIC )
    {
        ret_val = mmi_imc_direct_input_key_change_mode( mode_details_ptr, reserved );
        g_imc_key.key_check_funcptr = mmi_imc_key_direct_input_key_check;
    }
    else if ( lang_attr & IME_LANG_ATTR_SYMBOLIC )
    {
        ret_val = MMI_TRUE;
    }

    if ( ret_val == MMI_FALSE )
        return MMI_FALSE;

    g_imc_key.curr_mode_details = mode_details_ptr;

    g_imc_key.curr_mode = mmi_imm_get_curr_input_mode();
    g_imc_key.global_data_ptr->cand_length = 0;
    g_imc_key.global_data_ptr->tone = MMI_IMC_SYMB_TONE_NONE;

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {

        /*if current mode is not symbol or number  and premode is not allowed MAUI_02651437 */
        if (!((g_imc_key.curr_mode_details->imm_mode_id == IMM_INPUT_MODE_123_SYMBOLS)
            || (g_imc_key.curr_mode_details->imm_mode_id == IMM_INPUT_MODE_PHONE_NUMBER)))
        {
            g_imc_key_num_lock_pre_input_mode = IMM_INPUT_MODE_NONE;
        } 
        mmi_frm_qwerty_reset_key_status();
        mmi_imm_config_special_key_validation(mode_details_ptr);
    }
#endif

    /*TODO: attach key handlers*/

    if (!mmi_imc_is_key_disabled())
    {
        mmi_imc_key_register_ime_keys();
    }
    mmi_imc_key_activate(); 
    //mmi_imc_key_set_softkey();
    mmi_imc_key_set_csk();
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_add_symbol_buffer
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_add_key_symbol(mmi_imc_key_custom_value key_sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 sym = mmi_imc_key_get_symbol_by_imc_key(key_sym);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined __MMI_XT9__

    if (sym < MMI_IMC_KEY_BASE)
        return MMI_FALSE;
#else

    if (sym < MMI_IMC_SYMB_KEY_BASE)
        return MMI_FALSE;
#endif

    if (mmi_imc_key_add_symbol(sym))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_add_symbol
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_add_symbol(U16 sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->symb_count < MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
    {
        g_imc_key.global_data_ptr->symb_buff[g_imc_key.global_data_ptr->symb_count] =(U16)sym;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        g_imc_key.global_data_ptr->special_key_flag_table[g_imc_key.global_data_ptr->symb_count] = g_imc_key.key_info.curr_special_key_flag;
#endif
        g_imc_key.global_data_ptr->symb_count++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_symbol_by_imc_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static U16 mmi_imc_key_get_symbol_by_imc_key(mmi_imc_key_custom_value sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_XT9__

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)

    return (sym - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;
#endif
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__

    if (mmi_imm_is_current_mode_smart())
    {
        return (sym - MMI_IMC_KEY_BASE);
    }
    else
    {
        return (sym - MMI_IMC_KEY_BASE + MMI_IMC_SYMB_KEY_BASE);
    }


#endif

#else

    return (sym - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;

#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_remove_symbol
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_remove_symbol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->symb_count)
    {
        g_imc_key.global_data_ptr->symb_count--;
        g_imc_key.global_data_ptr->symb_buff[g_imc_key.global_data_ptr->symb_count] = 0;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        g_imc_key.global_data_ptr->special_key_flag_table[g_imc_key.global_data_ptr->symb_count] = 0;
#endif
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_associative_next_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_associative_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1] == 0)
    {
        g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
    }
    else
    {
        g_imc_key.global_data_ptr->cand_page ++;

        mmi_imc_change_candidate_box_page();

#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count + (g_imc_key.global_data_ptr->cand_count + 2) % 2) / 2 - 1;
#else
        g_imc_key.global_data_ptr->cand_select = 0;
#endif
    }
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
    return cand_count;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_associative_prev_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_associative_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.global_data_ptr->cand_page)
    {
        g_imc_key.global_data_ptr->cand_page --;
        mmi_imc_change_candidate_box_page();

#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count + (g_imc_key.global_data_ptr->cand_count + 2) % 2) / 2 - 1;
#else
        g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
#endif
    }
    else
    {
        g_imc_key.global_data_ptr->cand_select = 0;
    }
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                

    return cand_count;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_candidate_next_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_candidate_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    mmi_imc_state_enum state = mmi_imc_get_state();
    U8 page = g_imc_key.global_data_ptr->cand_page;
    U8 index = g_imc_key.global_data_ptr->cand_select;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->cand_count == 0)
        return 0;
    if (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1] == 0)
    {
#if defined(__MMI_IME_CANDIDATE_FILTER__) 
        if (g_imc_key.global_data_ptr->cand_filter && 
            g_imc_key.global_data_ptr->cand_count == 1 &&
            g_imc_key.global_data_ptr->cand_page == 0)
        {
            g_imc_key.global_data_ptr->cand_page ++;

            if (mmi_imc_change_candidate_box_page())
            {
                if (state != MMI_IMC_STATE_HAND_WRITING_CAND && 
                    state != MMI_IMC_STATE_SMART_CANDIDATE && 
                    state != MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
                    g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count - 1) / 2;
#else
                    g_imc_key.global_data_ptr->cand_select = 0;
#endif
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_select = 0;        
                }   
            }
            else
            {
                g_imc_key.global_data_ptr->cand_page--;

                mmi_imc_change_candidate_box_page();

                if (state != MMI_IMC_STATE_HAND_WRITING_CAND && 
                    state != MMI_IMC_STATE_SMART_CANDIDATE && 
                    state != MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
                {
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
                    g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count - 1) / 2;
#else
                    g_imc_key.global_data_ptr->cand_select = 0;
#endif
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_select = 0;        
                }
            }
        }
        else
#endif /* #if defined(__MMI_IME_CANDIDATE_FILTER__) */
        {
            g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
        }
    }
    else
    {
        g_imc_key.global_data_ptr->cand_page ++;

        mmi_imc_change_candidate_box_page();

        if (state != MMI_IMC_STATE_SMART_CANDIDATE && 
            state != MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC &&
            state != MMI_IMC_STATE_HAND_WRITING_CAND)
        {
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
            g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count - 1) / 2;
#else
            g_imc_key.global_data_ptr->cand_select = 0;
#endif
        }
        else
        {
            g_imc_key.global_data_ptr->cand_select = 0;        
        }
    }
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {   
        mmi_imc_pen_change_hw_cand_index();
    }
#endif

    if ((state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC || state == MMI_IMC_STATE_SMART_CANDIDATE || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) &&
        (page != g_imc_key.global_data_ptr->cand_page || index != g_imc_key.global_data_ptr->cand_select))
    {
        mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
    }
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
    return cand_count;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_candidate_prev_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_candidate_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    mmi_imc_state_enum state = mmi_imc_get_state();
    U8 page = g_imc_key.global_data_ptr->cand_page;
    U8 index = g_imc_key.global_data_ptr->cand_select;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_imc_key.global_data_ptr->cand_count == 0)
        return 0;
    if (g_imc_key.global_data_ptr->cand_page)
    {
        g_imc_key.global_data_ptr->cand_page --;

        mmi_imc_change_candidate_box_page();
        if (state != MMI_IMC_STATE_HAND_WRITING_CAND && 
            state != MMI_IMC_STATE_SMART_CANDIDATE && 
            state != MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
        {
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
            g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count - 1) / 2;
#else
            g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
#endif
        }
        else
        {
            g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
        }
    }
    else
    {
        g_imc_key.global_data_ptr->cand_select = 0;
    }

#if defined(__MMI_TOUCH_SCREEN__) && !defined(__NO_HANDWRITING__)
    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {   
        mmi_imc_pen_change_hw_cand_index();    
    }
#endif


    if ((state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC || state == MMI_IMC_STATE_SMART_CANDIDATE || state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) &&
        (page != g_imc_key.global_data_ptr->cand_page || index != g_imc_key.global_data_ptr->cand_select))
    {
        mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
    }

    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                

    return cand_count;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_composition_next_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_composition_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 comp_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.global_data_ptr->comp_first_index[g_imc_key.global_data_ptr->comp_page + 1] == 0)
    {
        g_imc_key.global_data_ptr->comp_select = g_imc_key.global_data_ptr->comp_count - 1;
    }
    else
    {
        g_imc_key.global_data_ptr->comp_page ++;
        g_imc_key.global_data_ptr->comp_select = 0;
        mmi_imc_change_composition_box_page();

    }    
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->comp_select, 0);
    return comp_count;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_composition_prev_page
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_get_composition_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 comp_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.global_data_ptr->comp_page)
    {
        g_imc_key.global_data_ptr->comp_page --;
        mmi_imc_change_composition_box_page();
        g_imc_key.global_data_ptr->comp_select = g_imc_key.global_data_ptr->comp_count - 1;
    }
    else
    {
        g_imc_key.global_data_ptr->comp_select = 0;
    }
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, (U32)g_imc_key.global_data_ptr->comp_select, 0);
    return comp_count;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_get_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imc_key_smart_alphabetic_get_candidate(S32 index)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct query_param;
    mmi_ime_query_result_struct result_param;
    S32 cand_insert = 0;
#if defined(__MMI_IME_CANDIDATE_FILTER__)
    MMI_BOOL cand_offset = MMI_FALSE;
#endif
    MMI_BOOL start_from_begin = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query_param, 0, sizeof(query_param));

    /* get candidate by symbol buffer */
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
    if (mmi_imc_is_floating_candidate_box_enabled())
    {
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN_VER;
    }
    else
#endif
    {
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_LATIN;
    }
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	if( mmi_imc_is_grid_state() )
	{
		 query_param.desired_cnt =MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
	}
	#endif
    query_param.elembuf_cnt = g_imc_key.global_data_ptr->symb_count;
    query_param.elembuf_ptr = g_imc_key.global_data_ptr->symb_buff;
    query_param.first_index = index;
#if defined(__MMI_IME_CANDIDATE_FILTER__)
    if (g_imc_key.global_data_ptr->cand_filter && index == 0 && !g_imc_key.global_data_ptr->cand_page)
    {
        S32 cand_len = mmi_ucs2strlen((const S8*)g_imc_key.global_data_ptr->cand_check);
        /* move the start position behind */
        result_param.result_buffer = g_imc_key.global_data_ptr->cand_buff + cand_len + 1;
        memcpy(
            g_imc_key.global_data_ptr->cand_buff,
            g_imc_key.global_data_ptr->cand_check,
            cand_len *sizeof(UI_character_type));
        g_imc_key.global_data_ptr->cand_buff[cand_len] = '\0';
        cand_offset = MMI_TRUE;
        query_param.desired_cnt--;
        g_imc_key.global_data_ptr->filter_page = 0xff;
    }
    else
#endif
    {
        result_param.result_buffer = g_imc_key.global_data_ptr->cand_buff;
    }
#if defined(__MMI_IME_CANDIDATE_FILTER__)
    if (g_imc_key.global_data_ptr->cand_filter && g_imc_key.global_data_ptr->cand_count == 1 && g_imc_key.global_data_ptr->cand_page)
    {
        start_from_begin = MMI_TRUE;
    }
#endif

    mmi_imc_get_candidates_from_word_engine(&query_param, &result_param);

    if (result_param.result_cnt > 0)
    {
#if defined(__MMI_IME_CANDIDATE_FILTER__) && defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (g_imc_key.global_data_ptr->cand_filter)
        {
            if (index == 0 && result_param.result_cnt == 1 && *result_param.result_buffer == MMI_IME_USER_DATABASE_NEW_WORD)
            {
                if (g_imc_key.global_data_ptr->filter_page == 0xff)
                {
                    return 0; 
                }
                else
                {
                    result_param.result_cnt = 0;
                }
            }
        }
#endif

        if (index == 0 && !start_from_begin)
        {
            g_imc_key.global_data_ptr->cand_select = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
#if defined(__MMI_IME_CANDIDATE_FILTER__)
            if (cand_offset)
            {
                result_param.result_cnt ++;
            }
#endif
#if defined(__MMI_IME_USER_DATABASE__)
            memset(g_imc_key.global_data_ptr->first_candidate, 0, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));
            MMI_ASSERT(mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->cand_buff) <= MMI_IMC_MAX_KEY_BUFFER_SIZE);
            memcpy(g_imc_key.global_data_ptr->first_candidate, &g_imc_key.global_data_ptr->cand_buff[0], sizeof(UI_character_type) * (mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->cand_buff) + 1));
#endif
        }

#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
        if (mmi_imc_is_floating_candidate_box_enabled())
        {
            cand_insert = mmi_imc_update_candidate_box_by_query_result_ext(g_imc_key.global_data_ptr->cand_buff, result_param.result_cnt, MMI_FALSE, MMI_TRUE);
        }
        else
#endif
        {
            cand_insert = mmi_imc_update_candidate_box_by_query_result(g_imc_key.global_data_ptr->cand_buff, result_param.result_cnt, result_param.next_page);
        }

#if defined(__MMI_IME_CANDIDATE_FILTER__)
        if (g_imc_key.global_data_ptr->cand_filter)
        {
            if (g_imc_key.global_data_ptr->cand_page == 0)
            {
                /* because there is one candidate inserted as the first candidate, we have to reduce candidate first index of each page. */
                if (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1])
                {
                    g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1]--;
                }        
            }
        }
#endif


    }

    return cand_insert;
#endif
}



/* Handlers Atttaching routines */
/* because of projects which may have sliding qwerty , this may seem a bit complicated */

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_smart_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_attach_smart_alphabetic_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
    {
#if defined (__MMI_XT9__)  || defined(__MMI_IME_V3__)
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_smart_alphabetic_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_smart_alphabetic_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_smart_alphabetic_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_smart_alphabetic_key_repeat_handler;
#else
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_repeat_handler;

#endif         
    }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {

        g_imc_key.key_info.key_down_handler = mmi_imc_key_smart_alphabetic_key_down_handler;
        g_imc_key.key_info.key_up_handler = mmi_imc_key_smart_alphabetic_key_up_handler;
        g_imc_key.key_info.key_long_handler = mmi_imc_key_smart_alphabetic_key_long_press_handler;
        g_imc_key.key_info.key_repeat_handler = mmi_imc_key_smart_alphabetic_key_down_handler;

    }
#endif
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_smart_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_attach_multitap_alphabetic_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
    {
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_multitap_alphabetic_key_repeat_handler;

    }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        g_imc_key.key_info.key_down_handler = mmi_imc_key_multitap_alphabetic_down_handler;
        g_imc_key.key_info.key_up_handler = mmi_imc_key_multitap_alphabetic_up_handler;
        g_imc_key.key_info.key_long_handler = mmi_imc_key_multitap_alphabetic_long_handler;
        g_imc_key.key_info.key_repeat_handler = mmi_imc_key_multitap_alphabetic_down_handler;
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_smart_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_attach_smart_phonetic_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
    {          
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_phonetic_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_phonetic_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_phonetic_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_phonetic_key_repeat_handler;

    }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        g_imc_key.key_info.key_down_handler = mmi_imc_key_smart_phonetic_key_down_handler;
        g_imc_key.key_info.key_up_handler = mmi_imc_key_smart_phonetic_key_up_handler;
        g_imc_key.key_info.key_long_handler = mmi_imc_key_smart_phonetic_key_long_press_handler;
        g_imc_key.key_info.key_repeat_handler = mmi_imc_key_smart_phonetic_key_down_handler;
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_smart_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_attach_multitap_phonetic_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_IME_MULTITAP_PHONETIC_INPUT__)

#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
    {
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_phonetic_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_phonetic_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_phonetic_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_phonetic_key_repeat_handler;

    }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        g_imc_key.key_info.key_down_handler = mmi_imc_key_multitap_phonetic_key_down_handler;
        g_imc_key.key_info.key_up_handler = mmi_imc_key_multitap_phonetic_key_up_handler;
        g_imc_key.key_info.key_long_handler = mmi_imc_key_multitap_phonetic_key_long_press_handler;
        g_imc_key.key_info.key_repeat_handler = mmi_imc_key_multitap_phonetic_key_down_handler;
    }
#endif

#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_attach_smart_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_attach_stroke_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if defined __MMI_QWERTY_KEYPAD_SUPPORT__
    {
        mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
        g_imc_key.key_info.qwerty_key_down_handler = mmi_imc_key_qwerty_stroke_key_down_handler;
        g_imc_key.key_info.qwerty_key_up_handler = mmi_imc_key_qwerty_stroke_key_up_handler;
        g_imc_key.key_info.qwerty_key_long_press_handler = mmi_imc_key_qwerty_stroke_key_long_press_handler;
        g_imc_key.key_info.qwerty_key_repeat_handler = mmi_imc_key_qwerty_stroke_key_repeat_handler;

    }
#endif

#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    {
        g_imc_key.key_info.key_down_handler = mmi_imc_key_stroke_key_down_handler;
        g_imc_key.key_info.key_up_handler = mmi_imc_key_stroke_key_up_handler;
        g_imc_key.key_info.key_long_handler = mmi_imc_key_stroke_key_long_press_handler;
        g_imc_key.key_info.key_repeat_handler = mmi_imc_key_stroke_key_down_handler;

    }
#endif

}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_timeout_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_multitap_alphabetic_timeout_callback( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    mmi_imc_gdi_lcd_freeze(MMI_TRUE);
    mmi_imc_key_multitap_alphabetic_input_confirm();
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
#if defined(__MMI_IME_V3__)
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__)
    if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON))
    {
         mmi_imc_pen_process_vk_state_after_confirm_candidate();
    }
	else
#endif
	{
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
		if(!mmi_imm_is_auto_capitalization_valid())
#endif
		{
			if(g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
			{
				g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
				//mmi_imc_pen_set_gui_state(IME_MODE_ATTR_LOWERCASE);
				mmi_imc_change_input_mode_according_to_capital_state(g_imc_key.global_data_ptr->capital_state);
				//mmi_imc_pen_send_ui_message(MMI_IMUI_MESSAGE_INVALIDATE_VK,0,0,NULL);
			}
		}
	}
#endif
    mmi_imc_redraw_screen_by_state();
    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    mmi_imc_repaint_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_input_confirm
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_multitap_alphabetic_input_confirm( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    mmi_ime_multitap_confirm();
#endif
    str = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

    mmi_imc_print_string_inserted_to_editor(str, mmi_ucs2strlen((const S8 *)str));

    /* cancel editor multitap state */
    mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
	g_imc_key_down_state = MMI_IMC_STATE_INITIAL;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_alphabeitc_get_multitap_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_alphabeitc_get_multitap_candidate(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_multitap_query_param_struct q_param;
    mmi_ime_multitap_query_result_struct r_param;
    MMI_BOOL result = MMI_FALSE;
   
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    mmi_imm_input_mode_enum mode;
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    U8 temp_cand_count;
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    UI_character_type temp_cand_buf[MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM * 2 + 1];
    U32 temp_special_key_flag = 0;
    S32 i,j;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)	
	mmi_fe_enable_proprietary_symbol_display();
	#endif
#if defined  __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        q_param.desired_cnt = MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM;

        r_param.result_buffer = g_imc_key.global_data_ptr->cand_buff;

        if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER
            && g_imc_key_multitap_special_key_flag == 0) 
        {
            temp_special_key_flag = MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT;
        }    
        else
        {
            temp_special_key_flag = g_imc_key_multitap_special_key_flag;
        }    

        r_param.result_count = mmi_imm_qwerty_get_multitap_chars(g_imc_key.key_info.curr_mmi_key_code, 
            temp_special_key_flag,
            temp_cand_buf,
            MMI_IMM_QWERTY_MAX_ATTRIBUTE_NUM * 2);
        for (i = 0, j = 0; i < r_param.result_count; i++)
        {
            if (mmi_imc_candidate_check(&temp_cand_buf[i * 2], 1))
            {
                r_param.result_buffer[j++] = temp_cand_buf[i * 2];
                r_param.result_buffer[j++] = 0;
            }
        }

        r_param.result_count = j / 2;

        if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER)
        {
            temp_cand_count = g_imc_key.global_data_ptr->cand_count;
            g_imc_key.global_data_ptr->cand_count = r_param.result_count;
            mmi_imc_change_candidate_list_caps(MMI_IME_WORD_CAPITAL_STATE_UPPER);
            g_imc_key.global_data_ptr->cand_count = temp_cand_count;
        }

        r_param.next_page = MMI_FALSE;

        if (r_param.result_count > 0)
        {
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }

#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    else
#endif
#endif
    {

#if !defined  __MMI_QWERTY_KEYPAD_SUPPORT__    || defined  __MMI_COSMOS_KEYPAD_SLIDER__
    q_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_MULTITP;
        q_param.elembuf_ptr = (PU16)(&(g_imc_key.global_data_ptr->symb_buff));
        q_param.elembuf_cnt = 1;
        q_param.first_index = index;

        /* query check */
        if (q_param.first_index < 0)
            return MMI_FALSE;

        r_param.result_buffer = g_imc_key.global_data_ptr->cand_buff;

        result = mmi_ime_multitap_get_candidate(&q_param, &r_param);

#endif
    }
    #if defined (__COSMOS_MMI_PACKAGE__)
if((mmi_imm_get_curr_input_mode() ==IMM_INPUT_MODE_PHONE_NUMBER ))
    {
        q_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_MULTITP;
        q_param.elembuf_ptr = (PU16)(&(g_imc_key.global_data_ptr->symb_buff));
        q_param.elembuf_cnt = 1;
        q_param.first_index = index;

        /* query check */
        if (q_param.first_index < 0)
            return MMI_FALSE;

        r_param.result_buffer = g_imc_key.global_data_ptr->cand_buff;

        result = mmi_ime_multitap_get_candidate(&q_param, &r_param);
    }
#endif
    /* set candidate select to the first candidate of the page */
    g_imc_key.global_data_ptr->cand_select = 0;

    /* invalid input */
    if (!result)
    {
        /* reset global data */
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
        mmi_ime_multitap_confirm();
#endif

        g_imc_key.global_data_ptr->cand_buff[0] = 0;
        g_imc_key.global_data_ptr->cand_count = 0;
        g_imc_key.global_data_ptr->comp_count = 0;
        return MMI_FALSE;
    }

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
    if (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
    {
        temp_cand_count = g_imc_key.global_data_ptr->cand_count;
        g_imc_key.global_data_ptr->cand_count = r_param.result_count;
        mmi_imc_change_candidate_list_caps(g_imc_key.global_data_ptr->capital_state);
        g_imc_key.global_data_ptr->cand_count = temp_cand_count;
    }
#endif

    mode = mmi_imm_get_curr_input_mode();
    if (!(mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EXT_PASSWORD) 
        && (result && r_param.result_count == 1 && g_imc_key.global_data_ptr->cand_page == 0 &&
        ((q_param.desired_cnt == 1 && r_param.next_page == MMI_FALSE) 
        || q_param.desired_cnt > 1))
#if defined(__MMI_MULTITAP_KEY_0__)
        && !(mode == IMM_INPUT_MODE_PHONE_NUMBER ||
        mode == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR ||
        mode == IMM_INPUT_MODE_SIM_NUMERIC)
#endif
        )
    {
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);
        g_imc_directly_input_multitap_string_length = mmi_ucs2strlen((const S8*)&g_imc_key.global_data_ptr->cand_buff[0]);
        char_inserted = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)(&g_imc_key.global_data_ptr->cand_buff[0]), MMI_FALSE);
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
        g_imc_key.global_data_ptr->cand_buff[0] = 0;
        g_imc_key.global_data_ptr->cand_count = 0;
        g_imc_key.global_data_ptr->comp_count = 0;
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ 
        mmi_ime_multitap_confirm();
#endif
        return MMI_FALSE;
    }
    else if (result)
    {
#if defined(__MMI_MULTITAP_KEY_0__)
 //       if((mode !=IMM_INPUT_MODE_SIM_NUMERIC)  && (mode !=IMM_INPUT_MODE_PHONE_NUMBER ) && ( mode !=   IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR))
         if((mode !=IMM_INPUT_MODE_SIM_NUMERIC))
        {
#endif
            /* set the select candidate as the first candidate in candidate box */
            g_imc_key.global_data_ptr->cand_select = 0;
            mmi_imc_update_candidate_box_by_query_result(r_param.result_buffer, (U8)r_param.result_count, r_param.next_page);
#if defined(__MMI_MULTITAP_KEY_0__)
        }
#endif
        return MMI_TRUE;
    }

    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_get_composition
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_get_composition(mmi_imc_key_custom_value key_code)
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_multitap_query_param_struct q_param;
    mmi_ime_multitap_query_result_struct r_param;
    MMI_BOOL result = MMI_FALSE;
    /* to store composition temporarily */
    UI_character_type composition_buf[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
    S32 i = 0;
    U16 key_sym = (key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;
    S32 try_count = 0;
    S32 index = g_imc_key.spell_multitap_index + 1;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    S32 comp_count = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) 
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        comp_count = (S32)mmi_imm_qwerty_get_multitap_chars(g_imc_key.key_info.curr_mmi_key_code,
            0,//g_imc_key.key_info.curr_special_key_flag,
            composition_buf,
            MMI_IMC_MAX_COMPOSITION_BUFFSIZE - 1);

        if (!comp_count)
        {
            return MMI_FALSE;
        }
    }
#endif

    for (try_count = 0; try_count <5; try_count++)
    {
        q_param.desired_cnt = 1;
        q_param.elembuf_ptr = (PU16)(&key_sym);
        q_param.elembuf_cnt = 1;
        q_param.first_index = (index % 5);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
        if(mmi_imc_get_slider_status()== OPEN)
#endif
        {

            if (index < comp_count)
            {
                r_param.result_buffer = mmi_imc_get_candidate_by_index(composition_buf, (U8)index);
                result = MMI_TRUE;
            }
            else
            {
                result = MMI_FALSE;
            }
        }
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
        else
#endif
#endif

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)  || defined __MMI_COSMOS_KEYPAD_SLIDER__
        {
            r_param.result_buffer = composition_buf;

            result = mmi_ime_multitap_get_candidate(&q_param, &r_param);
        }
#endif /* #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */

        index ++;

        g_imc_key.global_data_ptr->comp_select = 0;

        if (result)
        {
#if !defined(__MMI_VIRTUAL_KEYBOARD__)
#if (!defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || defined(__MMI_CSTAR_PHRASE_INPUT__))
            /* update symbol buffer */
            g_imc_key.global_data_ptr->comp_buff[g_imc_key.global_data_ptr->symb_count] = r_param.result_buffer[0];
            g_imc_key.global_data_ptr->comp_buff[g_imc_key.global_data_ptr->symb_count+1] = 0;

            g_imc_key.global_data_ptr->comp_select = 0;
            if (mmi_imc_change_highlighted_composition_from_composition_box(0))
            {
                /* the composition is valid, update composition buffer */
                mmi_imc_update_composition_box_by_query_result_ext(g_imc_key.global_data_ptr->comp_buff, 1, MMI_FALSE, MMI_TRUE);
                g_imc_key.spell_multitap_index = q_param.first_index;
                /* update composition buffer by symbol */
                for (i = 0; i < g_imc_key.global_data_ptr->symb_count + 1; i++)
                {
                    g_imc_key.global_data_ptr->symb_buff[i] = mmi_ime_word_code_to_symbol(g_imc_key.global_data_ptr->comp_buff[i]);
                }
                return MMI_TRUE;
            }
            else
            {
                /* recover the data */
                g_imc_key.global_data_ptr->comp_buff[g_imc_key.global_data_ptr->symb_count] = '\0';
            }
#else
            /* add symbol into symbol buffer temp */
            if (g_imc_key.global_data_ptr->symb_count + 1 < MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
            {
                g_imc_key.global_data_ptr->symb_buff[g_imc_key.global_data_ptr->symb_count++] = mmi_ime_word_code_to_symbol(r_param.result_buffer[0]);
                if (mmi_imc_key_multitap_phonetic_get_candidate())
                {
                    /*  */
                    g_imc_key.global_data_ptr->symb_count--;
                    g_imc_key.spell_multitap_index = q_param.first_index;
                    return MMI_TRUE;
                }
                else
                {
                    /* recover input */
                    g_imc_key.global_data_ptr->symb_count--;
                }
            }
#endif
#else
            /* add vk text */
            if (mmi_imc_pen_vk_insert_char(r_param.result_buffer[0]))
            {
                g_imc_key.spell_multitap_index = q_param.first_index;

                /* symbol counter is increaded in mmi_imc_pen_vk_insert_char but *
                * the multitap state didn't be confirmed.                                  *
                * Hence, decrease symbol counter.                                         */
                g_imc_key.global_data_ptr->symb_count --;
                return MMI_TRUE;
            }
#endif
        }
    }

    UI_UNUSED_PARAMETER(i);

    return MMI_FALSE;
#endif //#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_multitap_candidate
* DESCRIPTION
*  to get next canididate by the key code.
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_get_multitap_next_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 first_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check current page */
    if ((g_imc_key.global_data_ptr->cand_select + 1) < g_imc_key.global_data_ptr->cand_count)
    {
        g_imc_key.global_data_ptr->cand_select += 1;
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));               
        return MMI_TRUE;
    }
    else
    {
        /* get next page */
        first_index = g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1];

        if (first_index != 0)
        {
            g_imc_key.global_data_ptr->cand_page ++;
            if (mmi_imc_key_alphabeitc_get_multitap_candidate(first_index))
            {
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));     
                return MMI_TRUE;
            }
        }
        /* get the first page */
        g_imc_key.global_data_ptr->cand_page = 0;
        mmi_imc_key_alphabeitc_get_multitap_candidate(0);
        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));     
    }
    return MMI_TRUE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_insert_multitap_char
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_insert_multitap_char_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type cand = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cand = mmi_imc_key_extract_candidate_by_index(index);

    if (cand != NULL)
    {
#if defined (__MMI_MULTIGRAPH_SUPPORT__)
        if (mmi_ucs2strlen((const S8*)cand)>=2)
        {
            S32 result = 0;
            result = mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_STRING, (U32)cand, 0);
            if(result >= 0)
                g_imc_key.global_data_ptr->cand_length = result;
            return MMI_TRUE;
        }
        else
#endif
        {
            g_imc_key.global_data_ptr->cand_length = mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, cand[0], 0);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_delete_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_delete_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* clear original candidate */
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)   
    if (g_imc_key.global_data_ptr->cand_length)
    {
        /* delete from input area */
        mmi_imc_input_area_delete_string(g_imc_key.global_data_ptr->cand_length);
    }
#else /* defined(__MMI_IME_SMART_WITH_INPUT_AREA__) */
    if (g_imc_key.global_data_ptr->cand_length)
    {
        /* delete from editor */
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, g_imc_key.global_data_ptr->cand_length, 0);
    }
#endif /* defined(__MMI_IME_SMART_WITH_INPUT_AREA__) */
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_insert_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imc_key_smart_alphabetic_insert_candidate(S32 cand_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_len = 0;
    UI_string_type cand = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    BOOL lcd_freeze = gdi_lcd_get_freeze();
    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

    /* get candidate address in candidate buffer by index */
    cand = mmi_imc_key_extract_candidate_by_index(cand_index);

    /* insert candidate */
#if !defined(__MMI_IME_SMART_WITH_INPUT_AREA__) || defined(__MMI_CSTAR_PHRASE_INPUT__)

    if (cand != NULL)
    {
#if defined(__MMI_IME_USER_DATABASE__)
        if (*cand == MMI_IME_USER_DATABASE_NEW_WORD)
        {
            mmi_imc_key_smart_alphabetic_delete_candidate();
            total_len = 0;
        }
        else
#endif /* defined(__MMI_IME_USER_DATABASE__) */
        {
            total_len = mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, (U32)g_imc_key.global_data_ptr->cand_length, (U32)cand);
        }
    }
    else
    {
        mmi_imc_key_smart_alphabetic_delete_candidate();
        total_len = 0;
    }

    g_imc_key.global_data_ptr->cand_length = total_len;

    if (!total_len)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
    }

#else
    /* clear original candidate */
    mmi_imc_key_smart_alphabetic_delete_candidate();

    memcpy(g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index], cand, sizeof(UI_character_type) * (mmi_ucs2strlen((const S8*)cand) + 1));
    mmi_imc_key_samrt_alphabetic_update_input_area(MMI_FALSE);
#endif

    mmi_imc_gdi_lcd_freeze(lcd_freeze);

    return total_len;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_extract_candidate_by_index
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static UI_string_type mmi_imc_key_extract_candidate_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i =0;
    S32 j =0;
    UI_string_type cand = NULL;
    
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
	UI_string_type temp_cand = (UI_string_type)SymbolPickerSymbols[35];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > g_imc_key.global_data_ptr->cand_count)
        return NULL;

    /* initialize */
    cand = g_imc_key.global_data_ptr->cand_buff;

    while (i < index)    
    {
        while (g_imc_key.global_data_ptr->cand_buff[j] != 0 && j + 1 < MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
            j ++;

        if ((j + 1) < MMI_IMC_MAX_CANDIDATE_BUFFSIZE)
        {
            j++;
            i ++;
            cand = &g_imc_key.global_data_ptr->cand_buff[j];
        }
        else
        {
            break;
        }
    }
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
	if(cand[0] == 0x0085)
	{
		return temp_cand;
	}
#endif
    return cand;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_csk
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_set_csk(void)
{

}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_rsk_pen_up_post_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_rsk_pen_up_post_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
    redraw_right_softkey();
    mmi_imc_pen_softkey_up_post_hdlr(NULL);
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_rsk_up_post_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_ret mmi_imc_key_rsk_up_post_handler(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->key_type == KEY_EVENT_UP && key_evt->key_code == KEY_RSK)
    {
        if (mmi_imc_is_connected())
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            
            //for winguo search app, winguo already draw it, shoule skip wgui redraw_right_softkey in special case
			      if (mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE, 0xff, 0) != 0xff) 
                redraw_right_softkey();
        }

        mmi_frm_cb_dereg_event(EVT_ID_POST_KEY_EVT_ROUTING, mmi_imc_key_rsk_up_post_handler, NULL);

#if defined(__MMI_TOUCH_SCREEN__)
        mmi_imc_pen_softkey_up_post_hdlr(NULL);
#endif
    }

    return MMI_RET_OK;;
}


/*****************************************************************************
* FUNCTION
*  mmi_immc_config_softkeys_changeable
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_immc_config_softkeys_changeable(MMI_BOOL is_changeable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key_is_softkeys_changeable = is_changeable;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_softkey
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_set_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum state = mmi_imc_get_state();
    U16 key_code, key_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_key_is_softkeys_changeable)
    {
        return;
    }

    mmi_imc_key_get_current_key_info( (PU16)(&key_code), (PU16)(&key_type) );
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    if (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) && !mmi_imc_is_vk_disabled())
    {
        disable_softkey_background();
        set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
        set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
        set_softkey_flags_on(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_CENTER_SOFTKEY);
        wgui_icon_bar_set_flags_on(GUI_ICON_BAR_FLAG_DISABLE_DISPLAY);
    }
    else
    {
        set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_LEFT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_RIGHT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_DISABLE_TEXT_DISPLAY, MMI_CENTER_SOFTKEY);
        enable_softkey_background();
        wgui_icon_bar_set_flags_off(GUI_ICON_BAR_FLAG_DISABLE_DISPLAY);
    }
#endif

    switch(state)
    {
    case MMI_IMC_STATE_NONE:
        ASSERT(0);
        break;
    case MMI_IMC_STATE_INITIAL:
        mmi_imc_key_set_softkey_function(g_imc_key_inputbox_LSK_function, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_REPEAT, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_set_key_handler(UI_dummy_function, KEY_RSK, KEY_EVENT_REPEAT);
        mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
        if(mmi_imc_get_csk_config())
        {
        mmi_imc_key_set_softkey_function(g_imc_key_inputbox_CSK_function, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
        mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
        mmi_imc_key_set_softkey_label(g_imc_key_csk_text, MMI_CENTER_SOFTKEY);
        mmi_imc_key_set_softkey_icon(g_imc_key_csk_icon, MMI_CENTER_SOFTKEY);
        }

        /* reset arrow key handler */
        mmi_imc_key_set_key_handler(UI_dummy_function, KEY_UP_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(UI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(UI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_clear_key_handler(KEY_UP_ARROW, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_DOWN_ARROW, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_RIGHT_ARROW, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_LEFT_ARROW, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_VOL_UP, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_VOL_DOWN, KEY_REPEAT);
        mmi_imc_key_clear_key_handler(KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
        mmi_imc_key_clear_key_handler(KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);

#ifdef __MMI_CLIPBOARD__
#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            //MMI_ASSERT(0); /* Venus doesn't support Clipboard functions in IME module */
        }
        else
#endif
            if (mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR, 0, 0))
            {
                mmi_imc_key_set_softkey_function(g_imc_key_inputbox_RSK_function, KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
                mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_LONG_PRESS, MMI_RIGHT_SOFTKEY);
                mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
            else
#endif /* __MMI_CLIPBOARD__ */
            {
                if (key_code == KEY_RSK && key_type == KEY_EVENT_DOWN)
                {
                    mmi_frm_cb_reg_event(EVT_ID_POST_KEY_EVT_ROUTING, mmi_imc_key_rsk_up_post_handler, NULL);
#if defined(__MMI_TOUCH_SCREEN__)
                    mmi_imc_pen_softkey_up_post_hdlr(mmi_imc_key_rsk_pen_up_post_handler);
#endif
                }
                else
                {	
                    mmi_frm_cb_dereg_event(EVT_ID_POST_KEY_EVT_ROUTING, mmi_imc_key_rsk_up_post_handler, NULL);
#if defined(__MMI_TOUCH_SCREEN__)
                    mmi_imc_pen_softkey_up_post_hdlr(NULL);
#endif
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
                }
            }

            if (wgui_register_multiline_inputbox_up_down_key_handler != NULL)
            {
                wgui_register_multiline_inputbox_up_down_key_handler();
            }
            break;
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_SPELL_INPUTING:
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_SPELL_MULTITAP:
    case MMI_IMC_STATE_VK_CAND_MULTITAP:
    case MMI_IMC_STATE_VK_CAND:
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
    case MMI_IMC_STATE_HAND_WRITING_CAND:    
    case MMI_IMC_STATE_MULTITAP:
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
    case MMI_IMC_STATE_INPUT:
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
    case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:	
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:


        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_VOL_UP, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_VOL_DOWN, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_VOL_UP, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_long, KEY_VOL_UP, KEY_EVENT_LONG_PRESS);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_long, KEY_VOL_DOWN, KEY_EVENT_LONG_PRESS);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_VOL_UP, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_VOL_DOWN, KEY_REPEAT);

#if defined(__MMI_TOUCH_SCREEN__)
        if (state == MMI_IMC_STATE_HAND_WRITING_CAND)
        {
            mmi_imc_key_set_softkey_function(mmi_imc_key_delete_hand_writing_cand_timer, KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
            mmi_imc_key_set_softkey_function(mmi_imc_key_delete_hand_writing_cand_timer, KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
        }
        else
#endif
            if (state == MMI_IMC_STATE_WORD_HIGHLIGHTED)
            {
                mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_down, KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
                mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_down, KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
            }
            else
            {
                mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_LEFT_SOFTKEY);
                mmi_imc_key_set_softkey_function(UI_dummy_function, KEY_EVENT_DOWN, MMI_CENTER_SOFTKEY);
            }

            mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);

            if ((state != MMI_IMC_STATE_MULTITAP && state != MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)&&mmi_imc_get_csk_config()) /* Don't need to replace App's CSK when multitap state */
            {
                mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);
                mmi_imc_key_set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
                mmi_imc_key_set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
            }
            mmi_imc_key_register_softkey_handler(MMI_CENTER_SOFTKEY);

            if (!mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
            mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_down, KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
            mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_long, KEY_EVENT_LONG_PRESS, MMI_RIGHT_SOFTKEY);
            mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
            }
            else
            {
                mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_DOWN);
                mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_CLEAR, KEY_EVENT_UP);
                mmi_imc_key_set_key_handler(mmi_imc_key_group_key_long, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
            }

            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

            mmi_imc_key_set_key_handler(UI_dummy_function, KEY_UP_ARROW, KEY_EVENT_UP);
            mmi_imc_key_set_key_handler(UI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_UP);
            mmi_imc_key_set_key_handler(UI_dummy_function, KEY_UP_ARROW, KEY_EVENT_LONG_PRESS);
            mmi_imc_key_set_key_handler(UI_dummy_function, KEY_DOWN_ARROW, KEY_EVENT_LONG_PRESS);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_UP_ARROW, KEY_EVENT_REPEAT);

            if (state != MMI_IMC_STATE_WORD_HIGHLIGHTED)
            {
                mmi_imc_key_set_key_handler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                mmi_imc_key_set_key_handler(UI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_UP);
                mmi_imc_key_set_key_handler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);
                mmi_imc_key_set_key_handler(UI_dummy_function, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);

              //  if(state == MMI_IMC_STATE_NEW_WORD_INITIAL || state == MMI_IMC_STATE_NEW_WORD_MULTITAP) 
                {
                    mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
                    mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
                }
              /*  else
                {
                    mmi_imc_key_clear_key_handler(KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
                    mmi_imc_key_clear_key_handler(KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
                }*/
            }

            break;
    case MMI_IMC_STATE_HAND_WRITING:
        break;
    case MMI_IMC_STATE_PREDICTING:
        break;
#ifdef __MMI_CLIPBOARD__
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
    case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
    case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:

#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            MMI_ASSERT(0); /* Venus doesn't support Clipboard functions in IME module */
        }
#endif

        mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_CENTER_SOFTKEY);

        if (!mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {
        mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_down, KEY_EVENT_DOWN, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_long, KEY_EVENT_LONG_PRESS, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_set_softkey_function(mmi_imc_key_group_key_up, KEY_EVENT_UP, MMI_RIGHT_SOFTKEY);
        }
        else
        {
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_DOWN);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_UP);
            mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_CLEAR, KEY_EVENT_LONG_PRESS);
        }

        if (state == MMI_IMC_STATE_CLIPBOARD_MARK_TEXT)
        {
            mmi_imc_key_set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
            mmi_imc_key_set_softkey_icon(get_image(IMG_GLOBAL_OPTION_CSK), MMI_CENTER_SOFTKEY);
        }
        else if (state == MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS)
        {
            mmi_imc_key_set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
            mmi_imc_key_set_softkey_icon(get_image(IMG_GLOBAL_COMMON_CSK), MMI_CENTER_SOFTKEY);
        }
        else
        {
            mmi_imc_key_set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
            mmi_imc_key_set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
        }

        mmi_imc_key_register_softkey_handler(MMI_CENTER_SOFTKEY);

        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_VOL_UP, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_UP_ARROW, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_VOL_UP, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_up, KEY_VOL_DOWN, KEY_EVENT_UP);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_UP_ARROW, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_DOWN_ARROW, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_RIGHT_ARROW, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_LEFT_ARROW, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_VOL_UP, KEY_REPEAT);
        mmi_imc_key_set_key_handler(mmi_imc_key_group_key_repeat, KEY_VOL_DOWN, KEY_REPEAT);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        MMI_WGUI_SET_KEY_PROC(mmi_imc_key_qwerty_key_proc, NULL);
#endif
        break;
#endif /* __MMI_CLIPBOARD__ */

    default:
#ifdef __MMI_IME_PLUG_IN__
        if (mmi_imc_is_in_custom_state(state))
        {
            mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_SET_SOFTKEY_BY_STATE, (U32)state, 0);
        }
#endif    
        break;
    }    


}

#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_delete_hand_writing_cand_timer
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
static void mmi_imc_key_delete_hand_writing_cand_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_delete_timer();
}
#endif /* #if defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_redraw_softkey
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void     mmi_imc_key_redraw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum state = mmi_imc_get_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_set_softkey();

    mmi_imc_key_set_csk();

    if (mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_SOFTKEY_HIDE, 0, 0) == MMI_TRUE || (g_dm_data.s32flags & DM_NO_SOFTKEY))
    {
        return;
    }

    if( mmi_imc_get_csk_config())
    {
    redraw_softkey(MMI_CENTER_SOFTKEY);
    }

    switch(state)
    {
    case MMI_IMC_STATE_NONE:
        ASSERT(0);
        break;
    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:
    case MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING:
    case MMI_IMC_STATE_HAND_WRITING:
    case MMI_IMC_STATE_PASSWORD_PREVIEW:
        mmi_imc_key_set_softkey_label(g_imc_key_lsk_text, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_icon(NULL, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_icon(g_imc_key_csk_icon, MMI_CENTER_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
         if( mmi_imc_get_csk_config())
          {
        mmi_imc_key_show_softkey(MMI_CENTER_SOFTKEY);
         }
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
#ifdef __MMI_CLIPBOARD__
        if (mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_READ_ONLY_EDITOR, 0, 0))
        {
            mmi_imc_key_set_softkey_label(g_imc_key_rsk_text, MMI_RIGHT_SOFTKEY);
        }
#endif /* __MMI_CLIPBOARD__ */
        mmi_imc_key_set_softkey_icon(NULL, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);

        break;
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_SPELL_INPUTING:
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_SPELL_MULTITAP:
    case MMI_IMC_STATE_VK_CAND:
    case MMI_IMC_STATE_VK_CAND_MULTITAP:
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
    case MMI_IMC_STATE_HAND_WRITING_CAND:
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
    case MMI_IMC_STATE_INPUT:    
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (state == MMI_IMC_STATE_NEW_WORD_INITIAL || state == MMI_IMC_STATE_NEW_WORD_MULTITAP)
        {
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_SAVE), MMI_LEFT_SOFTKEY);
        }
        else
        {	
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_SELECT), MMI_LEFT_SOFTKEY);
        }	
        mmi_imc_key_set_softkey_icon(NULL, MMI_LEFT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
        if (!mmi_frm_kbd_is_key_supported(KEY_CLEAR))
        {

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
        if (
		#if !defined(__MMI_IME_V3__)
			state == MMI_IMC_STATE_SMART_CANDIDATE ||
		#endif
            state == MMI_IMC_STATE_CAND_SELECTING ||
            state == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT ||
            state == MMI_IMC_STATE_PRE_ASSOC_SELECTING ||
            state == MMI_IMC_STATE_ASSOC_SELECTING)
        {
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);            
        }
        else
        {
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR), MMI_RIGHT_SOFTKEY);

        }
#else
        if (state == MMI_IMC_STATE_CAND_SELECTING && 
            (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
            g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
            g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
            g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN))
        {
            if (g_imc_key.global_data_ptr->tone != MMI_IMC_SYMB_TONE_NONE)
            {
                mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR), MMI_RIGHT_SOFTKEY);
            }
            else
            {
                mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);            
            }
        }
        else if (state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC ||
            state == MMI_IMC_STATE_ASSOC_SELECTING)
        {
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);
        }
        else
        {
            mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR), MMI_RIGHT_SOFTKEY);
        }
#endif

#if defined(__MMI_IME_USER_DATABASE__)
        if (state == MMI_IMC_STATE_NEW_WORD_INITIAL || state == MMI_IMC_STATE_NEW_WORD_MULTITAP)
        {
            if (g_imc_key.global_data_ptr->new_word[0])
            {
                mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CLEAR), MMI_RIGHT_SOFTKEY); 
            }
            else
            {
                mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY); 
            }
        }
#endif

        mmi_imc_key_set_softkey_icon(NULL, MMI_RIGHT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        }
        
        break;
    case MMI_IMC_STATE_MULTITAP:
    case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:	
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
    case MMI_IMC_STATE_PREDICTING:
        break;
#ifdef __MMI_CLIPBOARD__ 
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
        mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_OPTIONS), MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
    case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
        mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_START), MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
    case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:
        mmi_imc_key_set_softkey_label(NULL, MMI_LEFT_SOFTKEY);
        mmi_imc_key_set_softkey_label((UI_string_type) get_string(STR_GLOBAL_CANCEL), MMI_RIGHT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_LEFT_SOFTKEY);
        mmi_imc_key_show_softkey(MMI_RIGHT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_LEFT_SOFTKEY);
        mmi_imc_key_register_softkey_handler(MMI_RIGHT_SOFTKEY);
        break;
#endif /* __MMI_CLIPBOARD__ */

    default:
#ifdef __MMI_IME_PLUG_IN__
        if (mmi_imc_is_in_custom_state(state))
        {
            mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_REDRAW_SOFTKEY_BY_STATE, (U32)state, 0);
        }
#endif    
        break;
    }  
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_softkey_function
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_set_softkey_function(f, k, key);
    }
    else
#endif
    {
        set_softkey_function(f, k, key);
    }

}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_clear_softkey_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_clear_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        clear_softkey_handler(key);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_group_key_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
static void mmi_imc_key_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_set_group_key_handler(funcPtr, keyCodes, len, keyType);
    }
    else
#endif
    {
        SetGroupKeyHandler(funcPtr, keyCodes, len, keyType);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_softkey_label
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_set_softkey_label(UI_string_type s, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        set_softkey_label_for_IME(s, key);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_softkey_icon
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_set_softkey_icon(PU8 icon, WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        wgui_softkey_set_icon_for_IME(icon, key);
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_show_softkey
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_show_softkey(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        redraw_softkey(key);
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_register_softkey_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_register_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
    }
    else
#endif
    {
        register_softkey_handler(key);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_key_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_set_key_handler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_set_key_handler(funcPtr, keyCode, keyType);
    }
    else
#endif
    {
        SetKeyHandler(funcPtr, keyCode, keyType);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_key_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
FuncPtr mmi_imc_key_get_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        return vadp_p2v_get_key_handler(keyCode, keyType);
    }
    else
#endif
    {
        return GetKeyHandler(keyCode, keyType);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_clear_key_handler
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_clear_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_clear_key_handler(keyCode, keyType);
    }
    else
#endif
    {
        ClearKeyHandler(keyCode, keyType);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_current_key_info
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
static void mmi_imc_key_get_current_key_info(U16 *keyCode, U16 *keyType)
{
#if defined(__MMI_VUI_ENGINE__)
    if (vadp_p2v_uc_is_in_venus())
    {
        vadp_p2v_get_current_key_info(keyCode, keyType);
    }
    else
#endif
    {
        GetkeyInfo(keyCode, keyType);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_lsk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_lsk_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key_lsk_text =  MMI_softkeys[MMI_LEFT_SOFTKEY].text;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_rsk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_rsk_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key_rsk_text =  MMI_softkeys[MMI_RIGHT_SOFTKEY].text;
}

//#if defined(__MMI_WGUI_CSK_ENABLE__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_csk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_csk_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key_csk_text =  MMI_softkeys[MMI_CENTER_SOFTKEY].text;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_setup_csk_icon
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  void
*****************************************************************************/
void mmi_imc_key_setup_csk_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key_csk_icon = get_softkey_icon(MMI_CENTER_SOFTKEY);
}
//#endif 
/* #if defined(__MMI_WGUI_CSK_ENABLE__) */


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_alphabetic_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum old_mode = mmi_imm_get_curr_input_mode();
    MMI_BOOL is_last_position = MMI_FALSE;
 
    MMI_BOOL ret = MMI_FALSE;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //printf("mmi_imc_key_multitap_alphabetic_down_handler\n");
	if (key_code == MMI_IMC_KEY_SYM_PERIOD)
    {
        mmi_imc_key_smart_alphabetic_confirm_candidate();
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, '.', 0);
        mmi_imc_redraw_screen_by_state();
        return MMI_TRUE;         
    }
    switch(mmi_imc_get_state())
    {
#if defined(__MMI_TOUCH_SCREEN__)
        case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                is_last_position = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);

                mmi_imc_pen_confirm_handwriting_selection();

                if (!is_last_position)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
                return MMI_TRUE;
            }
            if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
            {
                /* for arrow key, do nothing. */
                return MMI_TRUE;
            }
            if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }

            mmi_imc_pen_confirm_handwriting_selection(); /* no break */

            /* In canceling timer, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                return MMI_TRUE;
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            break;
#endif
        case MMI_IMC_STATE_INITIAL:
            /* insert the new candidate */
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;

            if (mmi_imc_key_is_key_symbol(key_code))
            {
                /* add symbol into symbol buffer */
                mmi_imc_key_add_key_symbol(key_code);
                /* get candidate if valid symbol */

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
                if(mmi_imc_get_slider_status()== OPEN)
#endif
                {
                    g_imc_key_multitap_special_key_flag = g_imc_key.key_info.curr_special_key_flag;

                    if ((g_imc_key_multitap_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT) || 
                        (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE) ||
                        (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                        )
                    {
                        g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
                    }
                    else
                    {
                        g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                    }    
                }
#endif

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                mmi_imc_key_change_candidate_case_by_previous_string();
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                if (mmi_imc_key_alphabeitc_get_multitap_candidate(0))
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);

                    /* update candidate buffer */
                    //mmi_imui_send_message(MMI_IMUI_MESSAGE_UPDATE_CANDIDATE_BOX);

                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
                else
                {
                    g_imc_key.global_data_ptr->symb_count = 0;
                    g_imc_key.global_data_ptr->cand_page = 0;
				#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
					if(!mmi_imm_is_auto_capitalization_valid())
				#endif
					{
						if(g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
						{
							g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
							mmi_imc_change_input_mode_according_to_capital_state(g_imc_key.global_data_ptr->capital_state); 
						}
					}
                }
            }
            else
            {
                /* invalid symbol, do other process */
                switch (key_code)
                {
                case MMI_IMC_KEY_UP:
                case MMI_IMC_KEY_DOWN:
                case MMI_IMC_KEY_LEFT:
                case MMI_IMC_KEY_RIGHT:
                    /* confirm current input */
                    mmi_imc_key_common_arrow_key_handler(key_code, g_imc_key.key_info.curr_mmi_key_type);
                    break;
                case MMI_IMC_KEY_CHANGE_MODE:
                    mmi_imc_key_handle_mode_change_key();
                    break;
                case MMI_IMC_KEY_SYMBOL_PICKER:
                    mmi_imc_key_entry_symbol_picker();
                    break;
                case MMI_IMC_KEY_LSK:
                    mmi_imc_key_multitap_alphabetic_input_confirm();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    g_imc_key_inputbox_LSK_function();
                    break;
                case MMI_IMC_KEY_RSK:
                    mmi_imc_key_multitap_alphabetic_input_confirm();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    break;
                case MMI_IMC_KEY_CLEAR:
                    mmi_imc_key_common_clear_key_handler();
                    break;
                }

            }
            ret = MMI_TRUE;
            break;
        case MMI_IMC_STATE_MULTITAP:

            if (mmi_imc_key_is_key_symbol(key_code))
            {
                mmi_imc_delete_timer();
                if (g_imc_key.global_data_ptr->symb_buff[0] != mmi_imc_key_get_symbol_by_imc_key(key_code)
                    || ((mmi_imm_get_curr_input_type() & IMM_INPUT_TYPE_EXT_PASSWORD) 
                    && g_imc_key.global_data_ptr->cand_count == 1 && g_imc_key.global_data_ptr->cand_page == 0))
                {
                    mmi_imm_input_mode_enum old_mode;
                    mmi_imc_ui_style_param_struct bkup_ui_param;
				#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
					if(!mmi_imm_is_auto_capitalization_valid())
				#endif
					{
						if(g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
						{
							g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
							mmi_imc_change_input_mode_according_to_capital_state(g_imc_key.global_data_ptr->capital_state);
						}
					}
					old_mode = mmi_imm_get_curr_input_mode();
                    /* confirm current input */
                    g_imc_key.global_data_ptr->symb_count = 0;

                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                    mmi_imc_get_ui_style_param(&bkup_ui_param);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_multitap_alphabetic_input_confirm();
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_ui_style_param(&bkup_ui_param);

                    g_imc_key_down_state = MMI_IMC_STATE_INITIAL;

                    /* Must call mmi_imc_redraw_screen_by_state() in the following process */

                    if (old_mode != mmi_imm_get_curr_input_mode())
                    {
                        mmi_imc_get_ui_style_param(&bkup_ui_param);
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_set_ui_style_param(&bkup_ui_param);

                        mmi_imc_redraw_screen_by_state();

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                        mmi_imc_key_group_key_down();
#endif
                    }
                    else
                    {
                        /* add new symbol */
                        mmi_imc_key_add_key_symbol(key_code);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                        g_imc_key_multitap_special_key_flag = g_imc_key.key_info.curr_special_key_flag;

                        if ((g_imc_key_multitap_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT) || 
                            (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE) ||
                            (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
                            )
                        {
                            g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
                        }
                        else
                        {
                            g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                        }    
#endif

#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                        mmi_imc_key_change_candidate_case_by_previous_string();
#endif
                            if(g_imc_key.key_info.last_imc_key_code != key_code)
                            {
                            g_imc_key.global_data_ptr->cand_page=0;
                            }
                        if (mmi_imc_key_alphabeitc_get_multitap_candidate(0))
                        {
                            mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                            mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                            mmi_imc_set_state(MMI_IMC_STATE_MULTITAP);
                            mmi_imc_redraw_screen_by_state();
                        }
                        else
                        {
                            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                            mmi_imc_redraw_screen_by_state();
                        }
                    }
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
                else
                {
#if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    mmi_imc_key_change_candidate_case_by_previous_string();
#endif
                    /* get new candidate */
                    mmi_imc_key_get_multitap_next_candidate();
                    /* replace the old candidate with the new one. */                
                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_insert_multitap_char_by_index(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }

            }
            else
            {
                /* do other process by key 
                On clear Key press  cancel timer is needed after multitap to handle multigraphs */
                switch (key_code)
                {
                case MMI_IMC_KEY_UP:
                case MMI_IMC_KEY_DOWN:
                case MMI_IMC_KEY_LEFT:
                case MMI_IMC_KEY_RIGHT:
                    mmi_imc_cancel_timer();
                    mmi_imc_key_common_arrow_key_handler(key_code, g_imc_key.key_info.curr_mmi_key_type);
                    mmi_imc_redraw_screen_by_state();
                    break;
                case MMI_IMC_KEY_CHANGE_MODE:
                    mmi_imc_cancel_timer();
                    mmi_imc_key_handle_mode_change_key();
                    break;
                case MMI_IMC_KEY_SYMBOL_PICKER:
                    mmi_imc_cancel_timer();
                    mmi_imc_key_entry_symbol_picker();
                    break;
                case MMI_IMC_KEY_CLEAR:
                    /* Removed assumption that multitap candidate is 1 character long to handle multigraphs*/
                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                    if (g_imc_key.global_data_ptr->cand_length > 0)
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, g_imc_key.global_data_ptr->cand_length, 0);
                    }
                    else if (g_imc_key.global_data_ptr->cand_length == 0 && 
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_HIDE_MULTITAP_CANDIDATE_BOX, 0, 0))
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                    }
                    mmi_imc_cancel_timer();

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)		
                    g_imc_key.global_data_ptr->dead_char = 0;
#endif    

                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                    break;
                }
            }
            ret = MMI_TRUE;
            break;
        default:

            break;

    }

    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_alphabetic_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {

    case MMI_IMC_STATE_MULTITAP:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            mmi_imc_delete_timer();
            mmi_imc_start_timer(
                MMI_IMC_KEY_MULTITAP_TIMER, 
                mmi_imc_key_multitap_alphabetic_timeout_callback,             
                mmi_imc_key_multitap_alphabetic_timeout_callback);
        }
        if (key_code == MMI_IMC_KEY_LSK)
        {
            mmi_imc_cancel_timer();
            g_imc_key_inputbox_LSK_function();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_cancel_timer();
            mmi_imc_key_entry_symbol_picker();
        }
        ret = MMI_TRUE;
        break;
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {

            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        ret = MMI_TRUE;
        break;
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_pen_confirm_handwriting_selection();
        }            
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        ret = MMI_TRUE;
        break;
#endif
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_long_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_alphabetic_long_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {

    case MMI_IMC_KEY_CLEAN:
        mmi_imc_delete_all();
        break;


    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        ret = MMI_TRUE;
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
	#if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else
        mmi_imc_key_change_input_mode();
	#endif
        ret = MMI_TRUE;
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    case MMI_IMC_KEY_CHANGE_LANGUAGE:
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        ret = MMI_TRUE;
        break;
#endif
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    U8 old_page = g_imc_key.global_data_ptr->cand_page;
    U8 old_index = g_imc_key.global_data_ptr->cand_select;
    S32 cand_insert = 0;
#endif
     BOOL lcd_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
            mmi_imc_key_smart_alphabetic_confirm_candidate();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_redraw_screen_by_state();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CAPTITAL_SWITCH)
        {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
            cand_insert = mmi_imc_key_smart_alphabetic_get_candidate(g_imc_key.global_data_ptr->cand_first_index[old_page]);

                g_imc_key.global_data_ptr->cand_select = old_index;

                if (cand_insert > 0)
                {
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);     
                    #if defined(__MMI_IME_USER_DATABASE__)    
                    if(g_imc_key.global_data_ptr->cand_buff[0]==MMI_IME_USER_DATABASE_NEW_WORD)
                    {
                         mmi_imc_key_handle_mode_change_key();
                   }
                   else
                   	#endif
                   	{
                    mmi_imc_select_candidate_from_candidate_box();
                  	}
            if (g_imc_key.global_data_ptr->capital_state != MMI_IME_WORD_CAPITAL_STATE_NONE && 
                g_imc_key.global_data_ptr->capital_state != MMI_IME_WORD_CAPITAL_STATE_MAX)
            {
                mmi_ime_word_capital_state_enum temp_state;
                const sIMEModeDetails *mode_details_ptr = NULL;

                if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER ||
                    g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
                {
                    temp_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                }
                else
                {
                    temp_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
                }

                mode_details_ptr = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(), temp_state);

                if (mode_details_ptr && mmi_imm_is_curr_allow_input_mode(mode_details_ptr->imm_mode_id))
                {
                    g_imc_key.global_data_ptr->capital_state = temp_state;

                    mmi_imc_set_caps_seq_by_cur_state(g_imc_key.global_data_ptr->symb_count);
                     mmi_imm_set_current_input_mode(mode_details_ptr->imm_mode_id);
                   
           
                    g_imc_key.global_data_ptr->capital_lock = MMI_TRUE;

                    mmi_imc_redraw_ime_indicator();
                }



                    mmi_imc_redraw_screen_by_state();
                }

            }
#else /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */
            if (mmi_imc_key_are_the_two_cases_same_in_current_page(MMI_IME_WORD_CAPITAL_STATE_UPPER, MMI_IME_WORD_CAPITAL_STATE_LOWER))
            { 
                return MMI_TRUE;
            }
            else if (mmi_imc_key_are_the_two_cases_same_in_current_page(MMI_IME_WORD_CAPITAL_STATE_LOWER, MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
            {
                if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER)
                {
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                }
                else if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE
                    || g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_LOWER
                    || g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
                {
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
                }
            }
            else if (mmi_imc_key_are_the_two_cases_same_in_current_page(MMI_IME_WORD_CAPITAL_STATE_UPPER, MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER))
            {
                if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_UPPER
                    || g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
                {
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                }
                else if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE
                    || g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_LOWER)
                {
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
                }
            }
            else
            {
                if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_NONE)
                {
#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
#else
                    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
#endif
                }
                else
                {
					const sIMEModeDetails *mode_details_ptr = mmi_imm_get_input_mode_array_item(mmi_imm_get_current_input_mode());
                    g_imc_key.global_data_ptr->capital_state ++;

#if !defined(__MMI_SMART_FIRST_UPPERCASE__) && !defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
                    if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
                        g_imc_key.global_data_ptr->capital_state ++;
#endif
					if(mode_details_ptr->lang_id == IME_WRITING_LANG_HABC && g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER)
					{
						g_imc_key.global_data_ptr->capital_state ++;
					}

                    if (g_imc_key.global_data_ptr->capital_state == MMI_IME_WORD_CAPITAL_STATE_MAX)
                        g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
                }
            }

            old_page = g_imc_key.global_data_ptr->cand_page;
            old_index = g_imc_key.global_data_ptr->cand_select;


#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
            if (mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC)
            {
                cand_insert = mmi_imc_key_smart_alphabetic_get_associated_words(&g_previous_word_buf[0], g_imc_key.global_data_ptr->cand_first_index[old_page]);

                g_imc_key.global_data_ptr->cand_select = old_index;

                if (cand_insert > 0)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);

                    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC);

                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);     
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }

                mmi_imc_redraw_screen_by_state();
            }
            else
#endif  
            {
                cand_insert = mmi_imc_key_smart_alphabetic_get_candidate(g_imc_key.global_data_ptr->cand_first_index[old_page]);

                g_imc_key.global_data_ptr->cand_select = old_index;

                if (cand_insert > 0)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);     
                    mmi_imc_redraw_screen_by_state();
                }
            }
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */
        }
#endif /* __MMI_IMC_CAPITAL_SWITCH__ */

        break;
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)  	
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:	
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_delete_timer();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            g_imc_key_inputbox_LSK_function();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_delete_timer();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif	
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_pen_confirm_handwriting_selection();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_pen_confirm_handwriting_selection();
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
    case MMI_IMC_STATE_INPUT:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
#if defined(__MMI_IME_USER_DATABASE__)
            mmi_imc_update_word_frequency_for_string(g_imc_key.global_data_ptr->input_buff);
#endif
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->input_buff, MMI_FALSE);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);                
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();

        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif

#if defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_imc_key_smart_alphabetic_add_new_word_key_up_handler(key_code, event_type);
        break;
#endif

    default:
        break;
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    if (key_code == MMI_IMC_KEY_CHANGE_LANGUAGE)
    {
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        return MMI_TRUE;
    }
#endif

#if defined(__MMI_IME_USER_DATABASE__) && defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    if (mmi_imc_get_state() == MMI_IMC_STATE_NEW_WORD_INITIAL || mmi_imc_get_state() == MMI_IMC_STATE_NEW_WORD_MULTITAP)
    {
        mmi_imc_key_smart_alphabetic_add_new_word_key_long_handler(key_code, event_type);
        return MMI_TRUE;
    }
#endif 


    switch (key_code)
    {
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
	#if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
    case MMI_IMC_KEY_CLEAR:
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);

        if (g_imc_key.global_data_ptr->cand_length)
        {
            mmi_imc_key_smart_alphabetic_delete_candidate();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, (U32)MMI_TRUE, 0);
        }

        /*the below API is to reset the first upper flag in case of long press clear*/
#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__) && defined (__MMI_XT9__) 
        mmi_ime_word_reset_first_upper_flag();
#endif

	#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_is_grid_state())
		{
			//show vk, as no more symbol left
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
		}
	#endif
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();

        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();

        break;
    #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    case MMI_IMC_KEY_CLEAN:
                mmi_imc_delete_all();
                break;
    #endif
    default:
        break;
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_backup_key_seq
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_BOOL space)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type cand = NULL;
    S32 cand_len = 0;
    S32 i =0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_imc_key.global_data_ptr->key_seq_index) >= MMI_IMC_MAX_KEY_SEQUENCE_RECORD)
    {
        return MMI_FALSE;
    }
    else
    {

        if (g_imc_key.global_data_ptr->symb_count == 0 && 
            g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num)
        {
            /* there is no input in current key sequence. Move the key seq behind to the previous one */
            for (i = g_imc_key.global_data_ptr->key_seq_index; i < g_imc_key.global_data_ptr->key_seq_num - 1; i ++)
            {
                memcpy(
                    g_imc_key.global_data_ptr->key_buffer_backup[i], 
                    g_imc_key.global_data_ptr->key_buffer_backup[i + 1], 
                    g_imc_key.global_data_ptr->key_len_backup[i + 1] * sizeof(U16));
                g_imc_key.global_data_ptr->key_len_backup[i] = g_imc_key.global_data_ptr->key_len_backup[i + 1];

                cand = g_imc_key.global_data_ptr->select_cand[i + 1];
                cand_len = mmi_ucs2strlen((const S8*)cand);
                memcpy(
                    g_imc_key.global_data_ptr->select_cand[i],
                    cand,
                    cand_len*sizeof(UI_character_type));
                g_imc_key.global_data_ptr->select_cand[i][cand_len] = 0;
            }
            g_imc_key.global_data_ptr->key_seq_num --;
        }
        else
        {
            cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
#if defined(__MMI_IME_USER_DATABASE__)
            /* new word candidate */
            if (cand[0] == MMI_IME_USER_DATABASE_NEW_WORD)
            {
                ASSERT(0);
            }
            //mmi_ime_word_update_word_frequency(g_imc_key.curr_mode, cand);
#endif
            memcpy(
                g_imc_key.global_data_ptr->key_buffer_backup[g_imc_key.global_data_ptr->key_seq_index], 
                g_imc_key.global_data_ptr->symb_buff, 
                g_imc_key.global_data_ptr->symb_count * sizeof(U16));
            g_imc_key.global_data_ptr->key_len_backup[g_imc_key.global_data_ptr->key_seq_index] = g_imc_key.global_data_ptr->symb_count;

            cand_len = mmi_ucs2strlen((const S8*)cand);
            memcpy(
                g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index],
                cand,
                cand_len*sizeof(UI_character_type));
            g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index][cand_len] = '\0';

            if (space && g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num - 1)
            {
                for (i = g_imc_key.global_data_ptr->key_seq_num; i > g_imc_key.global_data_ptr->key_seq_index + 1; i --)
                {
                    memcpy(
                        g_imc_key.global_data_ptr->key_buffer_backup[i], 
                        g_imc_key.global_data_ptr->key_buffer_backup[i - 1], 
                        g_imc_key.global_data_ptr->key_len_backup[i - 1] * sizeof(U16));
                    g_imc_key.global_data_ptr->key_len_backup[i] = g_imc_key.global_data_ptr->key_len_backup[i - 1];

                    cand = g_imc_key.global_data_ptr->select_cand[i - 1];
                    cand_len = mmi_ucs2strlen((const S8*)cand);
                    memcpy(
                        g_imc_key.global_data_ptr->select_cand[i],
                        cand,
                        cand_len*sizeof(UI_character_type));
                    g_imc_key.global_data_ptr->select_cand[i][cand_len] = 0;
                }
                g_imc_key.global_data_ptr->key_buffer_backup[g_imc_key.global_data_ptr->key_seq_index + 1][0] = 0;
                g_imc_key.global_data_ptr->key_len_backup[g_imc_key.global_data_ptr->key_seq_index + 1]= 0;
                g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index + 1][0] = 0;
                g_imc_key.global_data_ptr->key_seq_num ++;
            }

        }
        g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
        return MMI_TRUE;
    }
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_samrt_alphabetic_update_input_area
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_samrt_alphabetic_update_input_area(MMI_BOOL add_space)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 index = g_imc_key.global_data_ptr->key_seq_index;
    UI_string_type cand = NULL;
    S32 highlight_start = 0;
    S32 highlight_num = 0;
    S32 num = 0;
    S32 cursor = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key.global_data_ptr->input_length = 0;
    num = g_imc_key.global_data_ptr->key_seq_num;
    for (i = 0; i < num; i ++)
    {
        cand = g_imc_key.global_data_ptr->select_cand[i];

#if defined(__MMI_IME_USER_DATABASE__)
        if (*cand == MMI_IME_USER_DATABASE_NEW_WORD)
        {
            cand = g_imc_key.global_data_ptr->first_candidate;
        }
#endif

        if (index == i)
        {
            highlight_start = g_imc_key.global_data_ptr->input_length;
            highlight_num = mmi_ucs2strlen((const S8*) cand);
            cursor = highlight_start + highlight_num;
        }

        mmi_imc_input_area_add_string(cand);

        if (i != num - 1)
        {
            mmi_imc_input_area_add_space();
        }
        else if (add_space)
        {
            mmi_imc_input_area_add_space();
        }
    }
    g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_length] = '\0';
    if (mmi_imc_get_state() == MMI_IMC_STATE_INPUT &&
        g_imc_key.global_data_ptr->key_seq_index == g_imc_key.global_data_ptr->key_seq_num)
        cursor = g_imc_key.global_data_ptr->input_length;
    mmi_imc_update_input_area(highlight_start, highlight_num, 0, 0, cursor);
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_recover_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_recover_input(void)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type old_cand;
    S32 old_cand_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_cand = g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index];
    old_cand_len = mmi_ucs2strlen((const S8*) old_cand);
    /* restore symbol buffer */
    memcpy(
        g_imc_key.global_data_ptr->symb_buff, 
        g_imc_key.global_data_ptr->key_buffer_backup[g_imc_key.global_data_ptr->key_seq_index],
        sizeof(U16)* g_imc_key.global_data_ptr->key_len_backup[g_imc_key.global_data_ptr->key_seq_index]);
    g_imc_key.global_data_ptr->symb_count = g_imc_key.global_data_ptr->key_len_backup[g_imc_key.global_data_ptr->key_seq_index];

    /* insert the selected candidate as the first candidate */
    memcpy(
        g_imc_key.global_data_ptr->cand_buff,
        old_cand,
        old_cand_len *sizeof(UI_character_type));
    g_imc_key.global_data_ptr->cand_buff[old_cand_len] = '\0';
    /* store the filtered candidate  */
    memcpy(
        g_imc_key.global_data_ptr->cand_check,
        old_cand,
        old_cand_len *sizeof(UI_character_type));
    g_imc_key.global_data_ptr->cand_check[old_cand_len] = '\0';

    g_imc_key.global_data_ptr->cand_filter = MMI_TRUE;

    /* reset candidate data */
    mmi_imc_reset_candidate_valid_flag();
    g_imc_key.global_data_ptr->cand_page = 0;
    g_imc_key.global_data_ptr->cand_select = 0;

    mmi_imc_key_smart_alphabetic_get_candidate(0);
    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
    mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_remove_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_remove_input(S32 index)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    UI_string_type cand = NULL;
    S32 num = 0;
    S32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = g_imc_key.global_data_ptr->key_seq_num - 1;
    for (i = index; i < num; i ++)
    {
        cand = g_imc_key.global_data_ptr->select_cand[i + 1];
        len = g_imc_key.global_data_ptr->key_len_backup[i + 1];
        g_imc_key.global_data_ptr->key_len_backup[i] = len;
        memcpy(
            g_imc_key.global_data_ptr->key_buffer_backup[i],
            g_imc_key.global_data_ptr->key_buffer_backup[i + 1],
            sizeof(U16) * len);
        len = mmi_ucs2strlen((const S8*)cand) + 1;
        memcpy(
            g_imc_key.global_data_ptr->select_cand[i],
            cand,
            sizeof(UI_character_type)*len);
    }

    g_imc_key.global_data_ptr->key_len_backup[num] = 0;
    memset(
        g_imc_key.global_data_ptr->key_buffer_backup[num],
        0,
        sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);
    memset(g_imc_key.global_data_ptr->select_cand[num], 0, sizeof(UI_character_type)*(MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));
    g_imc_key.global_data_ptr->key_seq_num --;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_move_to_begin
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_move_to_begin(void)
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_string_type cand = NULL;
    S32 cand_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_seq_num > MMI_IMC_MAX_KEY_SEQUENCE_RECORD)
        return;
    if (g_imc_key.global_data_ptr->symb_count == 0)
        return;
    for (i = g_imc_key.global_data_ptr->key_seq_num; i > 0; i --)
    {
        memcpy(
            g_imc_key.global_data_ptr->key_buffer_backup[i], 
            g_imc_key.global_data_ptr->key_buffer_backup[i-1], 
            g_imc_key.global_data_ptr->key_len_backup[i-1] * sizeof(U16));
        g_imc_key.global_data_ptr->key_len_backup[i] = g_imc_key.global_data_ptr->key_len_backup[i-1];

        cand = g_imc_key.global_data_ptr->select_cand[i-1];
        cand_len = mmi_ucs2strlen((const S8*)cand);
        memcpy(
            g_imc_key.global_data_ptr->select_cand[i],
            cand,
            cand_len*sizeof(UI_character_type));
        g_imc_key.global_data_ptr->select_cand[i][cand_len] = 0;
    }
    memcpy(
        g_imc_key.global_data_ptr->key_buffer_backup[1], 
        g_imc_key.global_data_ptr->symb_buff, 
        g_imc_key.global_data_ptr->symb_count * sizeof(U16));
    g_imc_key.global_data_ptr->key_len_backup[1] = g_imc_key.global_data_ptr->symb_count;

    cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
    cand_len = mmi_ucs2strlen((const S8*)cand);
    memcpy(
        g_imc_key.global_data_ptr->select_cand[1],
        cand,
        cand_len*sizeof(UI_character_type));
    g_imc_key.global_data_ptr->select_cand[1][cand_len] = 0;

    g_imc_key.global_data_ptr->key_element_length = 0;
    g_imc_key.global_data_ptr->symb_count = 0;
    g_imc_key.global_data_ptr->cand_page = 0;
    g_imc_key.global_data_ptr->cand_select = 0;
    mmi_imc_reset_candidate_valid_flag();
    mmi_imc_set_state(MMI_IMC_STATE_INPUT);
    mmi_imc_update_candidate_as_null();
    mmi_imc_update_input_area(0, 0, 0, 0, 0);
    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
    g_imc_key.global_data_ptr->key_seq_num++;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = -1;
    S32 cand_index = 0;
    UI_string_type cand;
    S32 cand_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (key_code != MMI_IMC_KEY_SYM_0 && mmi_imc_key_is_key_symbol(key_code))
        {
            cand_index = key_code - MMI_IMC_KEY_SYM_1;
            if (cand_index <  g_imc_key.global_data_ptr->cand_count)
            {
#if defined(__MMI_IME_MAGIC_ONE__)
                if (mmi_imc_check_magic_state())
                {
                    g_imc_key.global_data_ptr->cand_select = cand_index;
                    mmi_imc_key_smart_alphabetic_insert_candidate(cand_index);
                    mmi_imc_select_candidate_from_candidate_box();
                    mmi_imc_redraw_screen_by_state();                        
                }
                else
#endif
                {
                    cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, (U8)cand_index);

#if defined(__MMI_IME_USER_DATABASE__)
                    if (*cand == MMI_IME_USER_DATABASE_NEW_WORD)
                    {
                        g_imc_key.global_data_ptr->cand_select = cand_index;
                        mmi_imc_select_candidate_from_candidate_box();
                        mmi_imc_redraw_screen_by_state();        
                    }
                    else
#endif /* defined(__MMI_IME_USER_DATABASE__) */
                    {
                        cand_len = (mmi_ucs2strlen((const S8*)cand) + 1); /* add null */
                        memcpy(
                            g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index],
                            cand,
                            cand_len*sizeof(UI_character_type));
                        g_imc_key.global_data_ptr->cand_select = 0;
                        g_imc_key.global_data_ptr->cand_page = 0;

                        /* set filter rule */
                        memcpy(
                            g_imc_key.global_data_ptr->cand_check,
                            cand,
                            cand_len*sizeof(UI_character_type));
                        g_imc_key.global_data_ptr->cand_check[cand_len] = '\0';

                        g_imc_key.global_data_ptr->cand_filter = MMI_TRUE;
                        /* reset candidate check rule */
                        mmi_imc_reset_candidate_valid_flag();
                        /* reget candidate */
                        mmi_imc_key_smart_alphabetic_get_candidate(0);
                        mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);    
                        mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                    }
                }

            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);                            
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* back to previous state */
            g_imc_key.global_data_ptr->cand_select = 0;
            g_imc_key.global_data_ptr->cand_page = 0;

            cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);

            if (cand_count)
            {
                mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
            }
            else
            {
                ASSERT(0);
            }
            mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CAPTITAL_SWITCH)
        {

        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {

#if defined(__MMI_IME_USER_DATABASE__)
                /* When highlight on "new word", space event is not allowed. */
                cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
                if (cand[0] == MMI_IME_USER_DATABASE_NEW_WORD)
                {
                    return;
                }
#endif
                if (mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_TRUE))
                {                   
                    mmi_imc_set_state(MMI_IMC_STATE_INPUT);
                    g_imc_key.global_data_ptr->key_seq_index ++;
                    mmi_imc_key_samrt_alphabetic_update_input_area(MMI_TRUE);
                    /* to reset the global data */
                    g_imc_key.global_data_ptr->cand_length = 0;
                    mmi_imc_reset_global_data();
                    mmi_imc_update_candidate_as_null();
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    /* insert input area data into editor */
                    mmi_imc_key_send_message(
                        MMI_IMC_MESSAGE_INSERT_STRING, 
                        (U32)g_imc_key.global_data_ptr->input_buff, 
                        (U32)mmi_ucs2strlen((const S8*)g_imc_key.global_data_ptr->input_buff));
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }            
            }
        }
        break;
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            if (g_imc_key.global_data_ptr->input_length < MMI_IMC_MAX_INPUT_STRING_SIZE && 
                mmi_imc_key_add_key_symbol(key_code))
            {
                MMI_BOOL old_cand_filter = g_imc_key.global_data_ptr->cand_filter;
                g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                if (cand_count)
                {
                    g_imc_key.global_data_ptr->filter_page = 0xff;
                    mmi_imc_key_add_key_element(key_code);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    g_imc_key.global_data_ptr->cand_filter = old_cand_filter;
                    mmi_imc_key_remove_symbol();
                }
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* symbol buffer is full. Do nothing */
            }
        }
        else if (key_code == MMI_IMC_KEY_UP)
        {
#if defined(__MMI_IME_MAGIC_ONE__)
            if (mmi_imc_check_magic_state())
            {
                mmi_imc_key_magic_state_chage_cand_cap();
            }
            else
#endif
                /* move focus to candidate area */
                mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_DOWN)
        {
            /* move focus to candidate area */
            mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num - 1)
            {
                mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_FALSE);
                if (!g_imc_key.global_data_ptr->key_seq_index && !g_imc_key.global_data_ptr->symb_count)
                {
                }
                else
                {
                    g_imc_key.global_data_ptr->key_seq_index ++;
                }
                mmi_imc_key_smart_alphabetic_recover_input();
            }
            else
            {
                /* move focus to candidate area */
                mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                mmi_imc_common_arrow_key_handler(key_code, KEY_EVENT_DOWN);
            }
            mmi_imc_redraw_screen_by_state();

        }
        else if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->key_seq_index > 0)
            {
                mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_FALSE);
                g_imc_key.global_data_ptr->key_seq_index --;
                mmi_imc_key_smart_alphabetic_recover_input();
                mmi_imc_redraw_screen_by_state();
            }
            else if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
                g_imc_key.global_data_ptr->filter_page = 0xff;
                mmi_imc_key_smart_alphabetic_move_to_begin();
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* remove the last symbol */
            g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
            g_imc_key.global_data_ptr->filter_page = 0xff;
            if (mmi_imc_key_remove_symbol())
            {
                if (!g_imc_key.global_data_ptr->symb_count)
                {
                    g_imc_key.global_data_ptr->cand_length = 0;
                    if (g_imc_key.global_data_ptr->key_seq_num == 1)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                    else
                    {
                        mmi_imc_key_smart_alphabetic_remove_input(g_imc_key.global_data_ptr->key_seq_index);                                
                        if (g_imc_key.global_data_ptr->key_seq_index)
                        {
                            g_imc_key.global_data_ptr->key_seq_index --;
                        }
                        mmi_imc_key_smart_alphabetic_recover_input();
                    }
                }
                else
                {
                    cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                }

                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
#if defined(__MMI_IME_MAGIC_ONE__)
        else if (key_code == MMI_IMC_KEY_CAPTITAL_SWITCH)
        {
            if (mmi_imc_check_magic_state())
            {
                mmi_imc_key_magic_state_chage_cand_cap();
            }
        }
#endif
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                if (mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_TRUE))
                {                   
                    mmi_imc_set_state(MMI_IMC_STATE_INPUT);
                    g_imc_key.global_data_ptr->key_seq_index ++;
                    if (g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num)
                    {
                        mmi_imc_key_samrt_alphabetic_update_input_area(MMI_FALSE);                    
                    }
                    else
                    {
                        mmi_imc_key_samrt_alphabetic_update_input_area(MMI_TRUE);
                    }
                    /* to reset the global data */
                    g_imc_key.global_data_ptr->cand_length = 0;
                    mmi_imc_reset_global_data();
                    mmi_imc_update_candidate_as_null();
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    /* insert input area data into editor */
                    mmi_imc_key_send_message(
                        MMI_IMC_MESSAGE_INSERT_STRING, 
                        (U32)g_imc_key.global_data_ptr->input_buff, 
                        (U32)mmi_ucs2strlen((const S8*)g_imc_key.global_data_ptr->input_buff));
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }
            }            
        }
        break;
    case MMI_IMC_STATE_INITIAL:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            if (g_imc_key.global_data_ptr->input_length < MMI_IMC_MAX_INPUT_STRING_SIZE && 
                mmi_imc_key_add_key_symbol(key_code) && 
                g_imc_key.global_data_ptr->key_seq_index < MMI_IMC_MAX_KEY_SEQUENCE_RECORD)
            {
                g_imc_key.global_data_ptr->cand_filter = 0;
                g_imc_key.global_data_ptr->filter_page = 0xff;
			#if defined(__MMI_IME_FLOATING_CAND_BOX__)    /*FTE2.0*/
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
			#endif
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                if (cand_count)
                {
                    g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length ++] = key_code;
                    g_imc_key.global_data_ptr->cand_select = 0;
                    g_imc_key.global_data_ptr->key_seq_num ++;
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    mmi_imc_key_remove_symbol();
                }                    
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* symbol buffer is full. Do nothing */
            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT ||
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            /* cursor moving */
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* if editor is empty, execute the rsk function of ap */
            /* otherwise, clear one character */
            mmi_imc_key_common_clear_key_handler();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
        }
        break;
    case MMI_IMC_STATE_INPUT:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            S32 key_seq_check = MMI_IMC_MAX_KEY_SEQUENCE_RECORD;
            if (g_imc_key.global_data_ptr->key_seq_index && g_imc_key.global_data_ptr->key_seq_index != g_imc_key.global_data_ptr->key_seq_num)
            {
                key_seq_check++;
            }
            if ( g_imc_key.global_data_ptr->input_length < MMI_IMC_MAX_INPUT_STRING_SIZE &&
                g_imc_key.global_data_ptr->key_seq_index < MMI_IMC_MAX_KEY_SEQUENCE_RECORD && 
                g_imc_key.global_data_ptr->key_seq_num < key_seq_check &&
                mmi_imc_key_add_key_symbol(key_code))
            {
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                if (cand_count)
                {
                    if (g_imc_key.global_data_ptr->key_seq_index == g_imc_key.global_data_ptr->key_seq_num)
                        g_imc_key.global_data_ptr->key_seq_num ++;
                    g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length ++] = key_code;
                    g_imc_key.global_data_ptr->cand_select = 0;
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    mmi_imc_key_remove_symbol();
                }                    
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* symbol buffer is full. Do nothing */
            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (g_imc_key.global_data_ptr->key_seq_index > 0)
            {
                mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_FALSE);
                g_imc_key.global_data_ptr->key_seq_index --;
                mmi_imc_key_smart_alphabetic_recover_input();
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (!g_imc_key.global_data_ptr->key_seq_index && !g_imc_key.global_data_ptr->symb_count)
            {
                mmi_imc_key_smart_alphabetic_remove_input(g_imc_key.global_data_ptr->key_seq_index);
                mmi_imc_key_smart_alphabetic_recover_input();
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
            }
            else if (g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num - 1)
            {
                mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_FALSE);
                if (g_imc_key.global_data_ptr->symb_count == 0 && 
                    g_imc_key.global_data_ptr->key_seq_index < g_imc_key.global_data_ptr->key_seq_num)
                {
                    /* there is no input in current key sequence. Move the key seq behind to the previous one */
                }
                else
                {
                    g_imc_key.global_data_ptr->key_seq_index ++;
                }
                mmi_imc_key_smart_alphabetic_recover_input();
                mmi_imc_redraw_screen_by_state();
            }

        }
        else if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->key_seq_index > 0)
            {
                mmi_imc_key_smart_alphabetic_backup_key_seq(MMI_FALSE);
                g_imc_key.global_data_ptr->key_seq_index --;
                mmi_imc_key_smart_alphabetic_recover_input();
                mmi_imc_redraw_screen_by_state();
            }

        }

        break;
#if defined(__MMI_IME_USER_DATABASE__)
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_imc_key_smart_alphabetic_add_new_word_key_down_handler(key_code, event_type);
        break;
#endif

    default:
        break;
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}


#else

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_alphabetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = -1;
    mmi_imm_input_mode_enum old_mode;
#if defined(__MMI_IME_USER_DATABASE__)
    UI_string_type temp_ptr = NULL;
#endif
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)
    MMI_BOOL is_locked = MMI_FALSE;
#endif
     BOOL lcd_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#if defined __MMI_XT9__
    S32 temp =  mmi_imc_handle_fn_key_in_smart_mode(key_code);
    if(temp == 1) /* these checks are to check if to return true, false or send the control down */
        return MMI_TRUE;
    else if(temp == 2)
        return MMI_FALSE;
#endif
#endif
	if(key_code == MMI_IMC_KEY_FN)
	{
		U16 symbol = 0x20;
		if(mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
		{
			//mmi_imc_key_smart_alphabetic_confirm_candidate();
			mmi_imc_select_candidate_from_candidate_box();
			mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, symbol, 0);
			mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
			mmi_imc_redraw_screen_by_state();
		}
		return MMI_TRUE; 
	}

    /* This is a hack because kdb for english doesnot have key_0 or symbol */
    /*the below check wont work for thai because there are keys mapped for 0 in thai */

    if(!mmi_ime_word_is_symbol_key(mmi_imm_get_curr_input_mode(),key_code))
    {
        if (key_code == MMI_IMC_KEY_SYM_PERIOD)
        {
			if(mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
			{
				mmi_imc_key_smart_alphabetic_confirm_candidate();
				mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
			}
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, '.', 0);
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;         
        }
        else if (key_code == MMI_IMC_KEY_SYM_0)
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, '0', 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;         
        }
    }
    /*the below chwck is to handle the 0 key in thai on Qwerty support*/
#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__) 
#if defined __MMI_COSMOS_KEYPAD_SLIDER__
    if(mmi_imc_get_slider_status()== OPEN)
#endif
    {
        if (key_code == MMI_IMC_KEY_SYM_0)
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, '0', 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;         
        }
    }
#endif
/*MAUI_03159162 FN key function not working in smart qwerty*/
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_IME_V3__)
if((g_imc_key.key_info.curr_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN) && (TRUE == mmi_imc_key_is_key_symbol(key_code)))
{
	g_imc_key_multitap_special_key_flag = g_imc_key.key_info.curr_special_key_flag;
	mmi_imc_key_alphabeitc_get_multitap_candidate(0);
	mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	mmi_imc_redraw_screen_by_state();
	return MMI_TRUE;
}
#endif

    g_imc_key_cand_length_before_key_down = g_imc_key.global_data_ptr->cand_length;

    switch(mmi_imc_get_state())
    {
#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
		 if (key_code == MMI_IMC_KEY_CLEAR)
        {
			mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
			mmi_imc_key_common_clear_key_handler();  
		}
		break;
	case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
        if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* remove the last symbol */
#if defined(__MMI_IME_CANDIDATE_FILTER__)
            g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
            g_imc_key.global_data_ptr->filter_page = 0xff;
#endif
            if (mmi_imc_key_remove_symbol())
            {
                g_imc_key.global_data_ptr->cand_select = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                /* when all key sequence is cleared.. */
                if (!cand_count && !g_imc_key.global_data_ptr->symb_count)
                {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    mmi_imc_set_caps_seq_by_cur_state(g_imc_key.global_data_ptr->symb_count);
#endif
                    /* the below check is so that candidate gets converted to small case even if the candidate is 
                    not selected*/
#if defined (__MMI_XT9__) 
#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__)
                    mmi_ime_word_reset_first_upper_flag();
#endif
#endif

                    /* clear the high light of editor. */
                    if (g_imc_key.global_data_ptr->cand_length)
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, g_imc_key.global_data_ptr->cand_length, (U32)L"");
                    }

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);

                    g_imc_key.global_data_ptr->cand_length = 0;
					//show vk, as no more symbol left
					mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
					mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);

                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
                else
                {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    mmi_imc_set_caps_seq_by_cur_state(g_imc_key.global_data_ptr->symb_count);
#endif

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);
            }
        }
		break;
#endif
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
#if defined(__MMI_IME_USER_DATABASE__)
            temp_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, 0);

            if (temp_ptr != NULL)
            {
                if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
                {
                    return MMI_TRUE; /* After "Spell word" came out, don't accept more symbol keys */
                }
            }
#endif

#if defined(__MMI_IME_CANDIDATE_FILTER__)
            g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
            g_imc_key.global_data_ptr->filter_page = 0xff;
#endif

            if (mmi_imc_key_add_key_symbol(key_code))
            {
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                if (cand_count)
                {
                    mmi_imc_key_add_key_element(key_code);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    mmi_imc_key_remove_symbol();
                }
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* symbol buffer is full. Do nothing */
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if (key_code == MMI_IMC_KEY_LEFT && mmi_imc_is_floating_candidate_box_enabled())
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);


                if (mmi_imm_test_r2l_input())
                {
                    // mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_END, 0, 0);
                }
                else
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START, 0, 0);
                }
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else
#endif /* #if defined(__MMI_IME_VERTICAL_CAND_BOX__) */
            {
                U8 page = g_imc_key.global_data_ptr->cand_page;
                U8 index = g_imc_key.global_data_ptr->cand_select;

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
                if (page != g_imc_key.global_data_ptr->cand_page || index != g_imc_key.global_data_ptr->cand_select)
                {
                    mmi_imc_redraw_screen_by_state();
                }
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* remove the last symbol */
#if defined(__MMI_IME_CANDIDATE_FILTER__)
            g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;
            g_imc_key.global_data_ptr->filter_page = 0xff;
#endif
            if (mmi_imc_key_remove_symbol())
            {
                g_imc_key.global_data_ptr->cand_select = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                /* when all key sequence is cleared.. */
                if (!cand_count && !g_imc_key.global_data_ptr->symb_count)
                {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    mmi_imc_set_caps_seq_by_cur_state(g_imc_key.global_data_ptr->symb_count);
#endif
                    /* the below check is so that candidate gets converted to small case even if the candidate is 
                    not selected*/
#if defined (__MMI_XT9__) 
#if defined (__MMI_QWERTY_KEYPAD_SUPPORT__)
                    mmi_ime_word_reset_first_upper_flag();
#endif
#endif

                    /* clear the high light of editor. */
                    if (g_imc_key.global_data_ptr->cand_length)
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, g_imc_key.global_data_ptr->cand_length, (U32)L"");
                    }

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);

                    g_imc_key.global_data_ptr->cand_length = 0;
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
                else
                {
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                    mmi_imc_set_caps_seq_by_cur_state(g_imc_key.global_data_ptr->symb_count);
#endif

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CAPTITAL_SWITCH)
        {
            mmi_imc_key_change_input_mode();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
#if defined(__MMI_IME_USER_DATABASE__)
                temp_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

                if (temp_ptr!= NULL)
                {
                    if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
#endif

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
                mmi_ucs2cpy((S8 *)&g_previous_word_buf[0], (const S8 *)temp_ptr);
#endif

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                mmi_imc_key_smart_alphabetic_confirm_candidate();
                /* add space */
                /*Space will be added during confirmation*/

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                {
                    mmi_event_struct evt;

                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);

                    MMI_FRM_CB_EMIT_EVENT(&evt);
                }
#else
                mmi_imc_key_change_candidate_case_by_previous_string();
#endif
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                if (mmi_imc_key_smart_alphabetic_get_associated_words(&g_previous_word_buf[0], 0) > 0)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);

                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);

                    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC);
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
#else
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
#endif

                mmi_imc_gdi_lcd_freeze(lcd_freeze);   

                mmi_imc_redraw_screen_by_state();
            }
        }
        break;
#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            if (mmi_imc_key_add_key_symbol(key_code))
            {
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
                mmi_imc_key_change_candidate_case_by_previous_string();
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);

                if (cand_count)
                {
                    g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length ++] = key_code;
                    g_imc_key.global_data_ptr->cand_select = 0;
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    mmi_imc_key_remove_symbol();
                }                    
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* symbol buffer is full. Do nothing */
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT ||
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if (key_code == MMI_IMC_KEY_LEFT && mmi_imc_is_floating_candidate_box_enabled())
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                if (mmi_imm_test_r2l_input())
                {
                    // mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_END, 0, 0);
                }
                else
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR_TO_HIGHLIGHT_START, 0, 0);
                }                    
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else
#endif /* #if defined(__MMI_IME_VERTICAL_CAND_BOX__) */
            {
                /* cursor moving */
                U8 page = g_imc_key.global_data_ptr->cand_page;
                U8 index = g_imc_key.global_data_ptr->cand_select;
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
                if (page != g_imc_key.global_data_ptr->cand_page || index != g_imc_key.global_data_ptr->cand_select)
                {
                    mmi_imc_redraw_screen_by_state();
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
            mmi_imc_key_smart_alphabetic_delete_candidate();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
#if defined(__MMI_ZI__)
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
#if defined(__MMI_IME_USER_DATABASE__)
                temp_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

                if (temp_ptr!= NULL)
                {
                    if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
#endif

                mmi_ucs2cpy((S8 *)&g_previous_word_buf[0], (const S8 *)temp_ptr);

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                mmi_imc_key_smart_alphabetic_confirm_candidate();

                /* add space */
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
                {
                    mmi_event_struct evt;

                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_IME_CURSOR_UPDATED);

                    MMI_FRM_CB_EMIT_EVENT(&evt);
                }
#else
                mmi_imc_key_change_candidate_case_by_previous_string();
#endif
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                if (mmi_imc_key_smart_alphabetic_get_associated_words(&g_previous_word_buf[0], 0) > 0)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);

                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);

                    mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC);
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);

                mmi_imc_redraw_screen_by_state();
            }
        }
#else /* T9 can't support continuously word prediction, because T9 need a very large text buffer */
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                /* since we might confirm , and if floating UI is there , that can cause first removal of part of hilight overlapping the candidate part and then the candidate part */
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
                {
                    mmi_imc_key_smart_alphabetic_confirm_candidate();
                }

                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
#endif
        break;
#endif /* #if defined(__MMI_ALPHABETIC_WORD_PREDICTION__) */
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
        {
            /* for arrow key, do nothing. */
            return MMI_TRUE;
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
            return MMI_TRUE;
        }

        old_mode = mmi_imm_get_curr_input_mode();

        mmi_imc_pen_confirm_handwriting_selection(); /* no break */

        /* In canceling timer, input mode may be changed by WCSS */
        if (old_mode != mmi_imm_get_curr_input_mode())
        {
            return MMI_TRUE;
        }

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        break;
#endif
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)          
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:

        mmi_imc_delete_timer();

        if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
        {
            if (key_code == MMI_IMC_KEY_CLEAR)
            {
                UI_buffer_type start_p = NULL, end_p = NULL;
                S32 str_len = 0, i, temp_len;
                UI_character_type c;

                str_len = (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD, (U32)&start_p, (U32)&end_p);

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                if (str_len && start_p && end_p)
                {
                    temp_len = str_len;

                    for (i = 0; i < temp_len; i++)
                    {
                        c = (UI_character_type)((*((start_p)+0))|((*((start_p)+1))<<8));

                        if (c == 0x1b)
                        {
                            str_len--;
                        }

                        start_p += 2;
                    }

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, (U32)str_len, 0);
                }

                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);

                mmi_imc_gdi_lcd_freeze(lcd_freeze);

                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE;
            }
            else if ((key_code == MMI_IMC_KEY_SPACE) ||(key_code == MMI_IMC_KEY_CHANGE_MODE))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            }
        }

#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) */     


    case MMI_IMC_STATE_INITIAL:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) 
            if (mmi_imc_get_state() == MMI_IMC_STATE_WORD_HIGHLIGHTED)
            {
                UI_buffer_type start_p = NULL, end_p = NULL;
                S32 str_len = 0, i, temp_len;
                UI_character_type c;

                str_len = (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD, (U32)&start_p, (U32)&end_p);

                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                is_locked = MMI_TRUE;

                if (str_len && start_p && end_p)
                {
                    temp_len = str_len;

                    for (i = 0; i < temp_len; i++)
                    {
                        c = (UI_character_type)((*((start_p)+0))|((*((start_p)+1))<<8));

                        if (c == 0x1b)
                        {
                            str_len--;
                        }

                        start_p += 2;
                    }

                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, (U32)str_len, 1);
                }

                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_REDRAW, 0, 0);

                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }
#endif

            if (mmi_imc_key_add_key_symbol(key_code))
            {
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
                mmi_imc_key_change_candidate_case_by_previous_string();
#endif

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                cand_count = mmi_imc_key_smart_alphabetic_get_candidate(0);
                if (cand_count)
                {
                    g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length ++] = key_code;
                    g_imc_key.global_data_ptr->cand_select = 0;
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                }
                else
                {
                    /* remove the new symbol and reget candidate*/
                    mmi_imc_key_remove_symbol();
                }                    
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }

#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) 
            if (is_locked)
            {
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
#endif
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            ///TODO: ailsa temp fix
            if (g_imc_key_inputbox_LSK_function)                
                g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT ||
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            /* cursor moving */
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* if editor is empty, execute the rsk function of ap */
            /* otherwise, clear one character */
            mmi_imc_key_common_clear_key_handler();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
            mmi_imc_redraw_screen_by_state();
        }
        break;

    default:
        break;
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
}

#endif


#if defined(__MMI_IME_CANDIDATE_FILTER__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_filter_candidate
* DESCRIPTION
*  to check the cand is valid or not
* PARAMETERS
*  cand [UI_string_type] the candidate would be checked
* RETURNS
*  MMI_BOOL the validness of the candidate. If MMI_TRUE: the candidate is valid. otherwise, the candidate is invalid.
*****************************************************************************/
MMI_BOOL mmi_imc_key_smart_alphabetic_filter_candidate(UI_string_type cand)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->cand_filter)
    {
        if (!mmi_ucs2icmp((const S8*) cand, (const S8*)g_imc_key.global_data_ptr->cand_check))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}
#endif /* #if defined(__MMI_IME_CANDIDATE_FILTER__) */


#if defined(__MMI_IME_USER_DATABASE__)
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_add_new_word_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_add_new_word_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_multitap_query_param_struct q_param;
    mmi_ime_multitap_query_result_struct r_param;
    U16 symb;
    MMI_BOOL result = MMI_FALSE, is_duplicated = MMI_FALSE;
    S32 i = 0, j = 0, k;
    UI_character_type     temp_multitap_buffer[MULTITAP_MAX_KEY_CHAR * 4];
    S32 temp_len = 0;
    UI_character_type char_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
        /* insert the new candidate */
        g_imc_key.global_data_ptr->active_multitap = 0;
        g_imc_key.global_data_ptr->multitap_buffer[0] = 0;
        g_imc_key.global_data_ptr->multitap_buffer_len = 0;

        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            if (mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->new_word) == MMI_IMC_MAX_KEY_NUM)
            {
				UI_editor_play_tone_cannot_insert();
                return; /* String buffer is full */
            }

            if (key_code == MMI_IMC_KEY_SYM_0)
            {
                if (!(g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
                {
                    mmi_imc_insert_char_into_string(g_imc_key.global_data_ptr->new_word, 
                        '0',
                        g_imc_key.global_data_ptr->char_index++);

                    mmi_imc_key_add_new_word_update_input_area(g_imc_key.global_data_ptr->char_index, 0, g_imc_key.global_data_ptr->char_index);
                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));

                }
            }
            else
            {
                symb = (key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;

                g_imc_key.global_data_ptr->multitap_key_code = key_code;

                q_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_MULTITP;
                q_param.elembuf_ptr = (PU16)(&symb);
                q_param.elembuf_cnt = 1;
                q_param.first_index = 0;

                r_param.result_buffer = g_imc_key.global_data_ptr->multitap_buffer;

                result = mmi_ime_multitap_get_candidate(&q_param, &r_param);

                if (!(g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) && result)
                {   
                    /* In magic one, we should fill the multitap buffer with lowercase and uppercase characters*/
#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                    mmi_ime_multitap_confirm();
#endif

                    temp_len = r_param.result_count;

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                    mmi_ime_multitap_change_mode(mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC), 0);
#endif

                    r_param.result_buffer = temp_multitap_buffer;

                    result = mmi_ime_multitap_get_candidate(&q_param, &r_param);

                    k = temp_len * 2;

                    if (result)
                    {
                        for (i = 0; i < r_param.result_count; i++)
                        {
                            char_code = temp_multitap_buffer[i * 2];

                            is_duplicated = MMI_FALSE;

                            for (j = 0; j < temp_len; j++)
                            {
                                if (char_code == g_imc_key.global_data_ptr->multitap_buffer[j * 2])
                                {
                                    is_duplicated = MMI_TRUE;
                                    break;
                                }
                            }

                            if (!is_duplicated)
                            {
                                g_imc_key.global_data_ptr->multitap_buffer[k] = char_code;
                                g_imc_key.global_data_ptr->multitap_buffer[k + 1] = 0;
                                k += 2;
                            }
                        }
                    }

                    r_param.result_count = k / 2;

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                    mmi_ime_multitap_confirm();

                    mmi_ime_multitap_change_mode(mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC), 0);
#endif
                }

                if (result)
                {
                    g_imc_key.global_data_ptr->multitap_buffer_len = r_param.result_count;

                    mmi_imc_insert_char_into_string(g_imc_key.global_data_ptr->new_word, 
                        g_imc_key.global_data_ptr->multitap_buffer[0],
                        g_imc_key.global_data_ptr->char_index);

                    mmi_imc_key_add_new_word_update_input_area(g_imc_key.global_data_ptr->char_index, 1, g_imc_key.global_data_ptr->char_index + 1);

                    mmi_imc_set_state(MMI_IMC_STATE_NEW_WORD_MULTITAP);

                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                }
                else
                {
                    g_imc_key.global_data_ptr->multitap_buffer[0] = 0;
                    g_imc_key.global_data_ptr->active_multitap = 0;
                }
            }
        }
        else
        {
            /* invalid symbol, do other process */
            switch (key_code)
            {
            case MMI_IMC_KEY_LEFT:
                if (g_imc_key.global_data_ptr->char_index > 0 && !mmi_imc_key_is_new_word_cursor_movement_disabled())
                {
                    g_imc_key.global_data_ptr->char_index--;

                    mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                }
                break;

            case MMI_IMC_KEY_RIGHT:
                if (g_imc_key.global_data_ptr->char_index + 1 <= mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->new_word)
                    && !mmi_imc_key_is_new_word_cursor_movement_disabled())
                {
                    g_imc_key.global_data_ptr->char_index++;

                    mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                }
                break;

            case MMI_IMC_KEY_CHANGE_MODE:
                mmi_imc_key_change_input_mode();
                break;

            case MMI_IMC_KEY_LSK:
                //mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                //mmi_imc_redraw_screen_by_state();
                break;

            case MMI_IMC_KEY_RSK:
            case MMI_IMC_KEY_CLEAR:
                if (g_imc_key.global_data_ptr->char_index > 0)
                {
                    mmi_imc_delete_char_from_string(g_imc_key.global_data_ptr->new_word, g_imc_key.global_data_ptr->char_index - 1);

                    g_imc_key.global_data_ptr->char_index--;

                    mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                }
                else 
                {
                    if (!mmi_frm_kbd_is_key_supported(KEY_CLEAR) || (mmi_frm_kbd_is_key_supported(KEY_CLEAR) && (key_code == MMI_IMC_KEY_RSK)))
                    {
                        if (!g_imc_key.global_data_ptr->new_word[0])
                        {
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
                            g_imc_key.global_data_ptr->symb_count = 0;

                            for (i = 0; g_imc_key.global_data_ptr->first_candidate[i]; i++)
                            {
                                if (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                                {
                                    g_imc_key.global_data_ptr->symb_buff[i] = (U16)mmi_ime_word_map_char_to_symbol(g_imc_key.curr_mode, g_imc_key.global_data_ptr->first_candidate[i]);
                                }
                                else
                                {
                                    g_imc_key.global_data_ptr->symb_buff[i] = (U16)mmi_ime_word_map_char_to_symbol(IMM_INPUT_MODE_SMART_LOWERCASE_ABC, g_imc_key.global_data_ptr->first_candidate[i]);
                                }
                                g_imc_key.global_data_ptr->symb_count++;
                            }

                            memcpy(g_imc_key.global_data_ptr->cand_check, g_imc_key.global_data_ptr->first_candidate, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));

                            g_imc_key.global_data_ptr->cand_filter = MMI_TRUE;

                            mmi_imc_reset_candidate_valid_flag();

                            g_imc_key.global_data_ptr->cand_page = 0;

                            mmi_imc_key_smart_alphabetic_get_candidate(0);

                            memcpy(&(g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index][0]), g_imc_key.global_data_ptr->first_candidate, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));

                            mmi_imc_key_samrt_alphabetic_update_input_area(MMI_FALSE);

                            mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
#else

                            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

#endif

                            mmi_imc_redraw_screen_by_state();
                        }
                }
                }
                break;

            default:
                break;
            }

        }
        break;
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:

        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            if (g_imc_key.global_data_ptr->multitap_key_code != key_code)
            {
                /* confirm current input */
                mmi_imc_cancel_timer();

                if (mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->new_word) == MMI_IMC_MAX_KEY_NUM)
                {
                    return; /* String buffer is full */
                }

                if (key_code == MMI_IMC_KEY_SYM_0)
                {
                    if (!(g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC))
                    {
                        mmi_imc_insert_char_into_string(g_imc_key.global_data_ptr->new_word, 
                            '0',
                            g_imc_key.global_data_ptr->char_index++);

                        mmi_imc_key_add_new_word_update_input_area(g_imc_key.global_data_ptr->char_index, 0, g_imc_key.global_data_ptr->char_index);
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                    }
                }
                else
                {	
                    g_imc_key.global_data_ptr->multitap_buffer[0] = 0;
                    g_imc_key.global_data_ptr->active_multitap = 0;

                    /* add new symbol */
                    symb = (key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;

                    g_imc_key.global_data_ptr->multitap_key_code = key_code;

                    q_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_MULTITP;
                    q_param.elembuf_ptr = (PU16)(&symb);
                    q_param.elembuf_cnt = 1;
                    q_param.first_index = 0;

                    r_param.result_buffer = g_imc_key.global_data_ptr->multitap_buffer;

                    result = mmi_ime_multitap_get_candidate(&q_param, &r_param);

                    if (!(g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) && result)
                    {   
                        /* In magic one, we should fill the multitap buffer with lowercase and uppercase characters*/
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                        mmi_ime_multitap_confirm();
#endif

                        temp_len = r_param.result_count;

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                        mmi_ime_multitap_change_mode(mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC), 0);
#endif
                        r_param.result_buffer = temp_multitap_buffer;

                        result = mmi_ime_multitap_get_candidate(&q_param, &r_param);

                        k = temp_len * 2;

                        if (result)
                        {
                            for (i = 0; i < r_param.result_count; i++)
                            {
                                char_code = temp_multitap_buffer[i * 2];

                                is_duplicated = MMI_FALSE;

                                for (j = 0; j < temp_len; j++)
                                {
                                    if (char_code == g_imc_key.global_data_ptr->multitap_buffer[j * 2])
                                    {
                                        is_duplicated = MMI_TRUE;
                                        break;
                                    }
                                }

                                if (!is_duplicated)
                                {
                                    g_imc_key.global_data_ptr->multitap_buffer[k] = char_code;
                                    g_imc_key.global_data_ptr->multitap_buffer[k + 1] = 0;
                                    k += 2;
                                }
                            }
                        }

                        r_param.result_count = k / 2;

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                        mmi_ime_multitap_confirm();

                        mmi_ime_multitap_change_mode(mmi_imm_get_input_mode_array_item(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC), 0);
#endif
                    }

                    if (result)
                    {
                        g_imc_key.global_data_ptr->multitap_buffer_len = r_param.result_count;

                        mmi_imc_insert_char_into_string(g_imc_key.global_data_ptr->new_word, 
                            g_imc_key.global_data_ptr->multitap_buffer[0],
                            g_imc_key.global_data_ptr->char_index);

                        mmi_imc_key_add_new_word_update_input_area(g_imc_key.global_data_ptr->char_index, 1, g_imc_key.global_data_ptr->char_index + 1);

                        mmi_imc_set_state(MMI_IMC_STATE_NEW_WORD_MULTITAP);

                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                    }
                    else
                    {
                        g_imc_key.global_data_ptr->multitap_buffer[0] = 0;
                        g_imc_key.global_data_ptr->active_multitap = 0;
                    }
                }
            }
            else
            {
                /* get new candidate */
                mmi_imc_delete_timer();

                if (g_imc_key.global_data_ptr->active_multitap < g_imc_key.global_data_ptr->multitap_buffer_len - 1)
                {
                    g_imc_key.global_data_ptr->active_multitap++;
                }
                else
                {
                    g_imc_key.global_data_ptr->active_multitap = 0;
                }

                g_imc_key.global_data_ptr->new_word[g_imc_key.global_data_ptr->char_index] = g_imc_key.global_data_ptr->multitap_buffer[g_imc_key.global_data_ptr->active_multitap * 2];

                mmi_imc_key_add_new_word_update_input_area(g_imc_key.global_data_ptr->char_index, 1, g_imc_key.global_data_ptr->char_index + 1);

                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
            }

        }
        else
        {
            /* do other process by key */
            mmi_imc_cancel_timer();
            switch (key_code)
            {
            case MMI_IMC_KEY_UP:
            case MMI_IMC_KEY_DOWN:
            case MMI_IMC_KEY_LEFT:
            case MMI_IMC_KEY_RIGHT:
                break;

            case MMI_IMC_KEY_CHANGE_MODE:
                mmi_imc_key_change_input_mode();
                break;

            case MMI_IMC_KEY_LSK:
                break;    

            case MMI_IMC_KEY_RSK:
            case MMI_IMC_KEY_CLEAR:
                mmi_imc_delete_char_from_string(g_imc_key.global_data_ptr->new_word, g_imc_key.global_data_ptr->char_index - 1);

                g_imc_key.global_data_ptr->char_index--;

                mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));

                break;

            default:
                break;
            }
        }
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_add_new_word_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_add_new_word_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {

    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            mmi_imc_restart_timer(
                MMI_IMC_KEY_MULTITAP_TIMER, 
                mmi_imc_key_smart_alphabetic_add_new_word_timeout_callback,             
                mmi_imc_key_smart_alphabetic_add_new_word_timeout_callback);
            return;
        }
        if (key_code == MMI_IMC_KEY_LSK)
        {
            mmi_imc_cancel_timer();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
            return;
        }
		    if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
		    {
			      mmi_imc_key_entry_symbol_picker();
			      return;
		    }
      
        /* No break */
    case MMI_IMC_STATE_NEW_WORD_INITIAL:
        if (key_code == MMI_IMC_KEY_LSK)
        {
            if (!g_imc_key.global_data_ptr->new_word[0])
            {
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
                if (g_imc_key.global_data_ptr->key_seq_num)
                {
                    g_imc_key.global_data_ptr->cand_filter = MMI_FALSE;

                    mmi_imc_key_smart_alphabetic_remove_input(g_imc_key.global_data_ptr->key_seq_index);

                    if (g_imc_key.global_data_ptr->key_seq_num)
                    {
                        if (g_imc_key.global_data_ptr->key_seq_index)
                        {
                            g_imc_key.global_data_ptr->key_seq_index--;
                        }

                        mmi_imc_key_smart_alphabetic_recover_input();
                    }
                    else
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                }
                else
#endif
                {	
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }

                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                if (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                {
                    mmi_ime_word_add_new_word(g_imc_key.curr_mode, g_imc_key.global_data_ptr->new_word);
                }
                else
                {
                    mmi_ime_word_add_new_word(IMM_INPUT_MODE_SMART_LOWERCASE_ABC, g_imc_key.global_data_ptr->new_word);
                }

                #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
                if (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
                {
                    g_imc_key.global_data_ptr->symb_count = 0;

                    for (i = 0; g_imc_key.global_data_ptr->new_word[i]; i++)
                    {
                        g_imc_key.global_data_ptr->symb_buff[i] = (U16)mmi_ime_word_map_char_to_symbol(g_imc_key.curr_mode, g_imc_key.global_data_ptr->new_word[i]);
                        g_imc_key.global_data_ptr->symb_count++;
                    }

                    memcpy(g_imc_key.global_data_ptr->cand_check, g_imc_key.global_data_ptr->new_word, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));

                    g_imc_key.global_data_ptr->cand_filter = MMI_TRUE;

                    mmi_imc_reset_candidate_valid_flag();

                    g_imc_key.global_data_ptr->cand_page = 0;

                    mmi_imc_key_smart_alphabetic_get_candidate(0);

                    memcpy(&(g_imc_key.global_data_ptr->select_cand[g_imc_key.global_data_ptr->key_seq_index][0]), g_imc_key.global_data_ptr->new_word, sizeof(UI_character_type) * (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1));

                    mmi_imc_key_samrt_alphabetic_update_input_area(MMI_FALSE);

                    mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
                }
                else
#endif	
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->new_word, MMI_TRUE);

                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }

                mmi_imc_redraw_screen_by_state();
            }
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
		    else if(key_code == MMI_IMC_KEY_SYMBOL_PICKER)
		    {
			      mmi_imc_key_entry_symbol_picker();
		    }
        break;

    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_add_new_word_long_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_add_new_word_key_long_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
    case MMI_IMC_KEY_CLEAN:
        if (mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->new_word) > 0)
        {
            memset(g_imc_key.global_data_ptr->new_word, 0, (MMI_IMC_MAX_KEY_BUFFER_SIZE + 1) * sizeof(UI_character_type));

            g_imc_key.global_data_ptr->char_index = 0;

            mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
        }
        break;
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
        mmi_imc_key_change_input_mode();
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_alphabetic_add_new_word_timeout_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_alphabetic_add_new_word_timeout_callback( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
    mmi_ime_multitap_confirm();
#endif

    g_imc_key.global_data_ptr->char_index++;

    mmi_imc_key_add_new_word_update_input_area(0, 0, g_imc_key.global_data_ptr->char_index);

    mmi_imc_set_state(MMI_IMC_STATE_NEW_WORD_INITIAL);

    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_add_new_word_update_input_area
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_add_new_word_update_input_area(S32 highlight_start_index, S32 highlight_num, S32 cursor_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imui_message_struct imui_msg;
    mmi_imui_update_input_area_struct input_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    input_area.str_ptr = g_imc_key.global_data_ptr->new_word;
    input_area.highlight_start_index =  highlight_start_index;
    input_area.highlight_num = highlight_num;
    input_area.wave_start_index = 0;
    input_area.wave_num = 0;
    input_area.cursor_index = cursor_index;
    input_area.flags = 0;

    if (mmi_imm_test_r2l_input())
    {   
        input_area.flags |= MMI_IMUI_INPUT_AREA_FLAG_R2L;
    }

    imui_msg.message_id = MMI_IMUI_MESSAGE_UPDATE_INPUT_AREA;
    imui_msg.param_0 = (U32)(&input_area);

    mmi_imui_send_message(&imui_msg, NULL);
}
#endif /* #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) */

/*****************************************************************************
* FUNCTION
*  mmi_imc_insert_char_into_string
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_insert_char_into_string(UI_string_type str_ptr, UI_character_type char_code, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_len = mmi_ucs2strlen((const S8 *)str_ptr);

    if (index > str_len)
    {
        return;
    }

    for (i = str_len - 1; i >= index; i --)
    {
        str_ptr[i + 1] = str_ptr[i];
    }

    str_ptr[index] = char_code;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_delete_char_from_string
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_delete_char_from_string(UI_string_type str_ptr, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    str_len = mmi_ucs2strlen((const S8 *)str_ptr);

    if (index >= str_len)
    {
        return;
    }

    for (i = index; i < str_len; i++)
    {
        str_ptr[i] = str_ptr[i + 1];
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_is_new_word_cursor_movement_disabled
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_is_new_word_cursor_movement_disabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imm_get_curr_input_mode())
    {
    case IMM_INPUT_MODE_SMART_ARABIC:
    case IMM_INPUT_MODE_SMART_PERSIAN:
    case IMM_INPUT_MODE_SMART_THAI:
    case IMM_INPUT_MODE_SMART_HINDI:
    case IMM_INPUT_MODE_SMART_BENGALI:
        return MMI_TRUE;
    default:
        return MMI_FALSE;
    }

    return MMI_FALSE;
}

#endif /* defined(__MMI_IME_USER_DATABASE__) */


#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_get_associated_words
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imc_key_smart_alphabetic_get_associated_words(UI_string_type str, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_len = 0;
    S32 cand_count = 0;
    mmi_ime_query_param_struct   query_param = {0};
    mmi_ime_query_result_struct  query_result = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_imm_is_alphabetic_word_prediction_enabled())
    {
        return 0;
    }

    cand_len = mmi_ucs2strlen((const S8*)str);

    MMI_ASSERT(cand_len <= MMI_IMC_MAX_PRE_STRING_LEN);

    memcpy(&g_imc_key.global_data_ptr->pre_string[0], str, sizeof(UI_character_type) * (cand_len));

    g_imc_key.global_data_ptr->pre_string[cand_len] = 0;

    query_param.pre_string = g_imc_key.global_data_ptr->pre_string;
    query_param.first_index = index;
    query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    query_result.result_buffer = g_imc_key.global_data_ptr->cand_buff;

    if (g_imc_key.global_data_ptr->capital_state != MMI_IME_WORD_CAPITAL_STATE_NONE)
    {
        mmi_ime_word_change_word_case(g_imc_key.global_data_ptr->capital_state);
    }

    mmi_imc_get_associates_from_word_engine(&query_param, &query_result);

    if (query_result.result_cnt > 0)
    {
        if (index == 0)
        {
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->cand_first_index[0] = 0;
            g_imc_key.global_data_ptr->cand_select= 0;
        }

        cand_count = mmi_imc_update_candidate_box_by_query_result_ext(query_result.result_buffer, query_result.result_cnt, query_result.next_page, MMI_TRUE);
    }

    return cand_count;

}
#endif /* #if defined(__MMI_ALPHABETIC_WORD_PREDICTION__) */


#if defined(__MMI_SMART_ALPHABETIC_RESELECTION__)  
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_highlight_alphabetic_word
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_highlight_alphabetic_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING
        || mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
    {
        mmi_imc_cancel_timer();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
    }
    else
    {
        mmi_imc_delete_timer();
    }

    mmi_imc_start_timer(MMI_IMC_KEY_SMART_ALPHABETIC_WORD_RESELECTION_LAUNCH_TIMER, 
        mmi_imc_key_start_smart_alphabetic_word_reselection,
        NULL);

    mmi_imc_set_state(MMI_IMC_STATE_WORD_HIGHLIGHTED);

    mmi_imc_key_redraw_softkey();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_unhighlight_alphabetic_word
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_unhighlight_alphabetic_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_delete_timer();

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    mmi_imc_key_redraw_softkey();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_start_smart_alphabetic_word_reselection
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_start_smart_alphabetic_word_reselection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_buffer_type start_p = NULL, end_p = NULL;
    S32 str_len, i, j, temp_str_len;
    U16 sym;
    UI_character_type c = 0;
    U8 symb_count_bk = 0;
    mmi_imc_ui_style_param_struct bkup_ui_param;
    mmi_imui_param_struct backup_imui_param;
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
    MMI_BOOL hw_state = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    temp_str_len = (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_HIGHLIGHT_WORD, (U32)&start_p, (U32)&end_p);

    str_len = temp_str_len;

    if (str_len > 0 && str_len <= MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE)
    {
        mmi_imc_reset_global_data();

        MMI_ASSERT(start_p);

        for (i = 0; i < str_len; i++)
        {
            c = (UI_character_type)((*((start_p + i * ENCODING_LENGTH)+0))|((*((start_p + i * ENCODING_LENGTH)+1))<<8)); 

            if (c == 0x1b) /* For the special case of ems extention char */
            {
                continue;
            }

            sym = mmi_ime_word_map_char_to_symbol(g_imc_key.curr_mode_details->imm_mode_id, c); 

            if (sym != MMI_IMC_SYMB_KEY_INVALID)
            {
                if (g_imc_key.key_check_funcptr)
                {
                    if (g_imc_key.key_check_funcptr(g_imc_key.curr_mode, sym - MMI_IMC_SYMB_KEY_BASE + MMI_IMC_KEY_BASE))
                    {
                        mmi_imc_key_add_symbol(sym);
                    }
                    else
                    {
                        return;
                    }
                }
                else
                {
                    mmi_imc_key_add_symbol(sym);
                }
            }
            else
            {
                return;
            }
        }

        for (i = 0, j = 0; i < str_len; i++)
        {
            c = (UI_character_type)((*((start_p + i * ENCODING_LENGTH)+0))|((*((start_p + i * ENCODING_LENGTH)+1))<<8)); 

            if (c != 0x1b)
            {
                g_imc_key.global_data_ptr->cand_check[j++] = c;
            }
            else
            {
                temp_str_len--;
            }
        }

        str_len = j;

        g_imc_key.global_data_ptr->cand_check[str_len] = 0;

        g_imc_key.global_data_ptr->cand_filter = MMI_TRUE;

        g_imc_key.global_data_ptr->filter_page = 0xff;

        mmi_imc_reset_candidate_valid_flag();

        g_imc_key.global_data_ptr->cand_page = 0;

        g_imc_key.global_data_ptr->cand_length = str_len;

#if defined(__MMI_SMART_FIRST_UPPERCASE__)
        mmi_imc_key_change_candidate_case_by_previous_string();
#endif

        symb_count_bk = g_imc_key.global_data_ptr->symb_count;

        for (i = 1; i < symb_count_bk; i++)
        {
            g_imc_key.global_data_ptr->symb_count = i;

            if (mmi_imc_key_smart_alphabetic_get_candidate(0) > 0)
            {
                continue;
            }
            else
            {
                mmi_imc_reset_global_data();
                return;
            }
        }

        g_imc_key.global_data_ptr->symb_count = symb_count_bk;

        mmi_imc_get_ui_style_param(&bkup_ui_param);

        mmi_imc_get_imui_parameters(&backup_imui_param);

#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
        hw_state = mmi_imc_get_single_block_handwriting_state();
#endif      

        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
#endif
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

        if (mmi_imc_key_smart_alphabetic_get_candidate(0) > 0)
        {
            g_imc_key.global_data_ptr->cand_select = 0;
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
            mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
            mmi_imc_redraw_screen_by_state();
        }
        else
        {
            mmi_imc_reset_global_data();
            mmi_imc_set_ui_style_param(&bkup_ui_param);
            mmi_imc_set_imui_parameters(&backup_imui_param);
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) && !defined(__NO_HANDWRITING__)
            if (hw_state && !mmi_imc_get_single_block_handwriting_state())
            {
			   	mmi_imc_pen_vk_enable_single_block_hw();
            }
            else if (!hw_state && mmi_imc_get_single_block_handwriting_state())
            {
                mmi_imc_pen_stop_singleblock_handwriting();
            }
#endif
            mmi_imc_set_state(MMI_IMC_STATE_WORD_HIGHLIGHTED);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_cancel_smart_alphabetic_word_reselection
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_cancel_smart_alphabetic_word_reselection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
}
#endif /* #if defined(__MMI_SMART_ALPHABETIC_RESELECTION__) */


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_confirm_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_smart_alphabetic_confirm_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = NULL;
    UI_character_type temp_cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];
    mmi_imc_state_enum state = mmi_imc_get_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this check can be made generic after some testing */
    /* the qwerty handler of xt9 will force vk again .To be secure using vk1 macro as well */
#if defined __MMI_XT9__
#if !defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
    mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
#endif
    str = mmi_imc_get_select_string_from_candidate_box();
    memset(temp_cand_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
    memcpy(&temp_cand_buff[0], str, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
    mmi_imc_select_candidate_from_candidate_box();
    if(state == MMI_IMC_STATE_SMART_CANDIDATE)
	{
	  #if defined(__MMI_IME_USER_DATABASE__)
	     if (*temp_cand_buff != MMI_IME_USER_DATABASE_NEW_WORD)
          #endif
                 {
	   //need to append space
	           if( (g_imc_key.curr_mode_details->Lang_Special_Attrib & (IME_LANG_ATTR_ALPHABETIC | IME_LANG_ATTR_ENGLISH_ONLY)))
		      {       
		       #if defined(__MMI_IME_V3__)     
			 if(mmi_imm_is_auto_space_enabled())
			#endif
			{
			       mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
			}
		       }
		 }
	}
#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
   if(!mmi_imm_is_auto_capitalization_valid())
#endif
   {
		if(g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
        {
			g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
            mmi_imc_change_input_mode_according_to_capital_state(g_imc_key.global_data_ptr->capital_state);
        }
   }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_USER_DATABASE__)
    UI_string_type temp_ptr = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)
    return MMI_FALSE;
#endif

#if defined(__MMI_IME_USER_DATABASE__)

    temp_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);

    if (temp_ptr != NULL)
    {
        if (*temp_ptr == MMI_IME_USER_DATABASE_NEW_WORD)
        {
            return MMI_FALSE; /* "Spell word" can not be confirmed when interrupt */
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }

#else

    return MMI_TRUE;

#endif
}


#if defined(__MMI_VIRTUAL_KEYBOARD__) //&& !defined(__MMI_IME_FTE_ENHANCE__)
/* __MMI_CSTAR_PHRASE_INPUT__ */
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_multitap_phonetic_select_candidate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_select_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
    S32 cand_match_len = g_imc_key.global_data_ptr->cand_match_len[g_imc_key.global_data_ptr->cand_select];
    S32 sym_remind = 0;
    S32 i = 0;
#if defined(__MMI_IME_USER_DATABASE__)
	UI_character_type new_word[MMI_IMC_MAX_INPUT_BUFFSIZE + 1];
	S32 str_len;
#endif
    UI_character_type symb[2] = {0}; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cand_match_len >= g_imc_key.global_data_ptr->symb_count)
    {
        /* insert confirm input in the input area first then insert the candidate */
        g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_confirm_length] = '\0';
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->input_buff, MMI_FALSE);
        /* all key input are confirmed. */
    #if defined(__MMI_IME_USER_DATABASE__)
		memset(&new_word[0], 0, sizeof(UI_character_type) * (MMI_IMC_MAX_INPUT_BUFFSIZE + 1));
		str_len = mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->input_buff);
		memcpy(&new_word[0], g_imc_key.global_data_ptr->input_buff, sizeof(UI_character_type) * (str_len));
        memcpy(&new_word[str_len], cand, sizeof(UI_character_type) * (mmi_ucs2strlen((const S8 *)cand)));
		mmi_ime_word_add_new_word(g_imc_key.curr_mode, new_word);
    #endif
        mmi_imc_select_candidate_from_candidate_box();
        mmi_imc_reset_input_area();
        return MMI_TRUE;
    }
    else
    {   
        /* update input area */
        mmi_imc_input_area_delete_string( g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        mmi_imc_input_area_add_string(cand);
        g_imc_key.global_data_ptr->input_confirm_length+= mmi_ucs2strlen((const S8*)cand);
        
        /* update symbol buffer */
        sym_remind = g_imc_key.global_data_ptr->symb_count - cand_match_len;
        for (i = 0; i < sym_remind; i ++)
        {
            g_imc_key.global_data_ptr->symb_buff[i] = g_imc_key.global_data_ptr->symb_buff[cand_match_len + i];
            g_imc_key.global_data_ptr->symb_buff[cand_match_len + i] = 0;
            symb[0] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);
            mmi_imc_input_area_add_string(symb);
        }
        g_imc_key.global_data_ptr->symb_buff[sym_remind] = 0;
        g_imc_key.global_data_ptr->symb_count = sym_remind;
        if (mmi_imc_key_multitap_phonetic_get_candidate())
        {
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
        }
        else
        {
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->cand_select = 0;
            g_imc_key.global_data_ptr->cand_count = 0;
            g_imc_key.global_data_ptr->cand_buff[0] = '\0';
            mmi_imc_update_candidate_as_null();
            mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
            mmi_imc_redraw_screen_by_state();
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_multitap_phonetic_get_candidate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_imc_key_multitap_phonetic_get_candidate(void)
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = 0;
    mmi_ime_query_param_struct param_ptr;
    mmi_ime_query_result_struct result_ptr;
    UI_character_type input_symbol[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr.elembuf_cnt = g_imc_key.global_data_ptr->symb_count;
    param_ptr.elembuf_ptr = g_imc_key.global_data_ptr->symb_buff;
    param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    param_ptr.first_index = 0;
    param_ptr.tone_value = g_imc_key.global_data_ptr->tone;
    result_ptr.result_buffer = g_imc_key.global_data_ptr->cand_buff;
    result_ptr.match_length_table = g_imc_key.global_data_ptr->cand_match_len;

    mmi_ime_word_get_candidates(&param_ptr, &result_ptr);

    if (result_ptr.result_cnt)
    {
        mmi_imc_input_area_delete_string(g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        for (i = 0; i < g_imc_key.global_data_ptr->symb_count; i ++)
        {
            input_symbol[i] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);
        }
        input_symbol[g_imc_key.global_data_ptr->symb_count] = '\0';
        mmi_imc_input_area_add_string(input_symbol);
        g_imc_key.global_data_ptr->cand_page = 0;
        g_imc_key.global_data_ptr->cand_select = 0;
        count = mmi_imc_update_candidate_box_by_query_result(g_imc_key.global_data_ptr->cand_buff, result_ptr.result_cnt, result_ptr.next_page);
        mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_length);
    }
    return count;
#endif //#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum cur_state = mmi_imc_get_state();
    mmi_imm_input_mode_enum old_mode;
    MMI_BOOL is_last_position = MMI_FALSE, ret_value = MMI_TRUE;
    U8 i=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    switch(cur_state)
    {
#if defined(__MMI_TOUCH_SCREEN__)
		case MMI_IMC_STATE_CAND_SELECTING_GRID:
			 if (key_code == MMI_IMC_KEY_CLEAR)
             {
                if (mmi_imc_key_remove_symbol())
                {
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
						mmi_imc_change_state_from_grid_to_initial();                       
                    }
                    else
                    {
                        if (mmi_imc_pen_set_vk_candidate())
                        {
                            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
                            mmi_imc_redraw_screen_by_state();
                        }
                        else 
                        {	
							mmi_imc_change_state_from_grid_to_initial();                       
                        }
                    }
                }    
            }
			break;
		case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
		if (key_code == MMI_IMC_KEY_CLEAR)
		{
			mmi_imc_change_state_from_grid_to_initial();
		}
			break;
        case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                is_last_position = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);

                mmi_imc_pen_confirm_handwriting_selection();

                if (!is_last_position)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
                return MMI_TRUE;
            }
            if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
            {
                /* for arrow key, do nothing. */
                return MMI_TRUE;
            }
            if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }

            old_mode = mmi_imm_get_curr_input_mode();

            mmi_imc_pen_confirm_handwriting_selection(); /* no break */

            /* In canceling timer, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                return MMI_TRUE;
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            break;
#endif
        case MMI_IMC_STATE_INITIAL:
        case MMI_IMC_STATE_VK_CAND:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                /* get candidate if valid symbol */
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                /* there is no valid composition by the key sequence. */                
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }            
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
               /*Adjusting symbol count for cand state*/
                for(i=0;g_imc_key.global_data_ptr->symb_buff[i]!=0;i++)
                {
                /*increase the counter to get get correct symbol count */
                }
                g_imc_key.global_data_ptr->symb_count=i;
                if (mmi_imc_key_remove_symbol())
                {
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
                        mmi_imc_pen_update_display_area_by_sym_buffer();
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                    else
                    {
                        mmi_imc_pen_set_vk_candidate();
                    }
                    mmi_imc_redraw_screen_by_state();
                }
                else if (cur_state == MMI_IMC_STATE_INITIAL)
                {
                    mmi_imc_key_common_clear_key_handler();
                }
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                if (cur_state == MMI_IMC_STATE_INITIAL)
                {
                    if (mmi_imm_test_input((UI_string_type)L" ", 1))
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                        mmi_imc_redraw_screen_by_state();
                    }
                }
                else
                {
                    mmi_imc_cancel_timer();

                    if (g_imc_key.global_data_ptr->cand_count > 0)
                    {
                        mmi_imc_select_candidate_from_candidate_box();
                        mmi_imc_redraw_screen_by_state();
                    }
                }
            }
            break;
        case MMI_IMC_STATE_VK_CAND_MULTITAP:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
                if (g_imc_key.key_info.last_imc_key_code != key_code)
                {
                    /* confirm current input */
                    mmi_imc_cancel_timer();
                    g_imc_key.spell_multitap_index = -1;
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__
                    mmi_ime_multitap_confirm();
#endif
                    mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
                    mmi_imc_key_add_key_element(g_imc_key.key_info.last_imc_key_code);
                }
                else
                {
                    mmi_imc_delete_timer();
                    /* get new candidate */
                }
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                else if (g_imc_key.spell_multitap_index)
                {
                    /* try again. */
                    g_imc_key.spell_multitap_index = -1;
                    if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                    {
                        /* state not change. */
                        mmi_imc_redraw_screen_by_state();
                        return MMI_TRUE;
                    }                    
                }
                break;
            }
            /* confirm current input */
            mmi_imc_cancel_timer();
            if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
				/*Adjusting symbol count for cand state*/  
                for(i=0;g_imc_key.global_data_ptr->symb_buff[i]!=0;i++)
                {
                /*increase the counter to get get correct symbol count */
                }
                g_imc_key.global_data_ptr->symb_count=i;
                if (mmi_imc_key_remove_symbol())
                {
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
                        mmi_imc_pen_update_display_area_by_sym_buffer();
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                    else
                    {
                        mmi_imc_pen_set_vk_candidate();
                    }
                }
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            break;
        case MMI_IMC_STATE_ASSOC_SELECTING:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
                /* reset all data and start a new input */
                g_imc_key.global_data_ptr->key_element_length = 0;
                mmi_imc_reset_global_data();
                g_imc_key.global_data_ptr->symb_count = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                /* get candidate if valid symbol */
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP); 
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                /* there is no valid composition by the key sequence. */                
                g_imc_key.global_data_ptr->symb_count = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();                
            }            
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                    mmi_imc_redraw_screen_by_state();
                }
            }

            break;
    }

    return ret_value;
#endif //(defined __MMI_IME_MULTITAP_PHONETIC_INPUT__)
}

#else

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_select_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_select_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
    S32 cand_match_len = g_imc_key.global_data_ptr->cand_match_len[g_imc_key.global_data_ptr->cand_select];
    S32 sym_remind = 0;
    S32 i = 0;
#if defined(__MMI_IME_USER_DATABASE__)
    UI_character_type new_word[MMI_IMC_MAX_INPUT_BUFFSIZE + 1];
    S32 str_len;
#endif
    UI_character_type symb[2] = {0}; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cand_match_len >= g_imc_key.global_data_ptr->symb_count)
    {
        /* insert confirm input in the input area first then insert the candidate */
        g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_confirm_length] = '\0';
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->input_buff, MMI_FALSE);
        /* all key input are confirmed. */
#if defined(__MMI_IME_USER_DATABASE__)
        memset(&new_word[0], 0, sizeof(UI_character_type) * (MMI_IMC_MAX_INPUT_BUFFSIZE + 1));
        str_len = mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->input_buff);
        memcpy(&new_word[0], g_imc_key.global_data_ptr->input_buff, sizeof(UI_character_type) * (str_len));
        memcpy(&new_word[str_len], cand, sizeof(UI_character_type) * (mmi_ucs2strlen((const S8 *)cand)));
        mmi_ime_word_add_new_word(g_imc_key.curr_mode, new_word);
#endif
        mmi_imc_select_candidate_from_candidate_box();
        mmi_imc_reset_input_area();
        return MMI_TRUE;
    }
    else
    {   
        /* update input area */
        mmi_imc_input_area_delete_string( g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        mmi_imc_input_area_add_string(cand);
        g_imc_key.global_data_ptr->input_confirm_length+= mmi_ucs2strlen((const S8*)cand);

        /* update symbol buffer */
        sym_remind = g_imc_key.global_data_ptr->symb_count - cand_match_len;
        for (i = 0; i < sym_remind; i ++)
        {
            g_imc_key.global_data_ptr->symb_buff[i] = g_imc_key.global_data_ptr->symb_buff[cand_match_len + i];
            g_imc_key.global_data_ptr->symb_buff[cand_match_len + i] = 0;
            symb[0] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);
            mmi_imc_input_area_add_string(symb);
        }
        g_imc_key.global_data_ptr->symb_buff[sym_remind] = 0;
        g_imc_key.global_data_ptr->symb_count = sym_remind;
        if (mmi_imc_key_multitap_phonetic_get_candidate())
        {
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
        }
        else
        {
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->cand_select = 0;
            g_imc_key.global_data_ptr->cand_count = 0;
            g_imc_key.global_data_ptr->cand_buff[0] = '\0';
            mmi_imc_update_candidate_as_null();
            mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
            mmi_imc_redraw_screen_by_state();
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_get_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_multitap_phonetic_get_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 count = 0;
    mmi_ime_query_param_struct param_ptr;
    mmi_ime_query_result_struct result_ptr;
    UI_character_type input_symbol[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param_ptr.elembuf_cnt = g_imc_key.global_data_ptr->symb_count;
    param_ptr.elembuf_ptr = g_imc_key.global_data_ptr->symb_buff;
    param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    param_ptr.first_index = 0;
    param_ptr.tone_value = g_imc_key.global_data_ptr->tone;
    result_ptr.result_buffer = g_imc_key.global_data_ptr->cand_buff;
    result_ptr.match_length_table = g_imc_key.global_data_ptr->cand_match_len;

    mmi_ime_word_get_candidates(&param_ptr, &result_ptr);

    if (result_ptr.result_cnt)
    {
        mmi_imc_input_area_delete_string(g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        for (i = 0; i < g_imc_key.global_data_ptr->symb_count; i ++)
        {
            input_symbol[i] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);
        }
        input_symbol[g_imc_key.global_data_ptr->symb_count] = '\0';
        mmi_imc_input_area_add_string(input_symbol);
        g_imc_key.global_data_ptr->cand_page = 0;
        g_imc_key.global_data_ptr->cand_select = 0;
        count = mmi_imc_update_candidate_box_by_query_result(g_imc_key.global_data_ptr->cand_buff, result_ptr.result_cnt, result_ptr.next_page);
        mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_length);
    }
    return count;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phoetic_get_candidate_with_tone
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_multitap_phoetic_get_candidate_with_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tone_mark = MMI_IMC_SYMB_TONE_NONE;
    U16 prev_symb;
    S32 i;
    MMI_BOOL new_symb = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imc_key.global_data_ptr->symb_count)
    {
        return 0;
    }
    prev_symb = g_imc_key.global_data_ptr->symb_buff[g_imc_key.global_data_ptr->symb_count-1];

    if (MMI_IMC_IS_SYMB_TONE(prev_symb))
    {
        tone_mark = prev_symb;
        g_imc_key.global_data_ptr->symb_count--;
    }
    else
    {
        new_symb = MMI_TRUE;
    }

    for (i = 0; i < 5 ;i ++)
    {
        tone_mark = ((tone_mark+ 1) - MMI_IMC_SYMB_TONE_1) % 5 + MMI_IMC_SYMB_TONE_1;
        g_imc_key.global_data_ptr->symb_buff[g_imc_key.global_data_ptr->symb_count++] = tone_mark;
        if (mmi_imc_key_multitap_phonetic_get_candidate())
        {
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            return g_imc_key.global_data_ptr->cand_count;
        }
        else
        {
            g_imc_key.global_data_ptr->symb_count--;
        }
    }
    if (!new_symb)
        g_imc_key.global_data_ptr->symb_count++;
    return 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defiend(__MMI_IME_MULTITAP_PHONETIC_INPUT__)  && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum cur_state = mmi_imc_get_state();
    S32 cand_index;
    MMI_BOOL ret_value = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(cur_state)
    {
    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
			#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
			#endif
            /* get candidate if valid symbol */
            if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
            {
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP);
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE;
            }
            /* there is no valid composition by the key sequence. */                
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.spell_multitap_index = -1;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }            
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (mmi_imc_key_remove_symbol())
            {
                /* update composition buffer by symbol */
                if (g_imc_key.global_data_ptr->symb_count == 0)
                {
                    if (!g_imc_key.global_data_ptr->input_confirm_length)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        mmi_imc_input_area_delete_string(1);
                        /* to reset the global data */
                        mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_length);
                        mmi_imc_reset_global_data();
                        mmi_imc_update_candidate_as_null();
                        //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
						mmi_imc_redraw_imui(mmi_imc_get_current_floating_imui_control_set()); 
                    }
                }
                else if (mmi_imc_key_multitap_phonetic_get_candidate())
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
					mmi_imc_redraw_imui(mmi_imc_get_current_floating_imui_control_set()); 
                }
                else
                {
                    ASSERT(0);
                }
            }
            else if (g_imc_key.global_data_ptr->input_confirm_length)
            {
                if (g_imc_key.global_data_ptr->input_confirm_length > 1)
                {
                    mmi_imc_input_area_delete_string(1);
                    mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_length);
                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (cur_state == MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_key_common_clear_key_handler();
            }
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->symb_count && g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
                //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
				mmi_imc_redraw_imui(mmi_imc_get_current_floating_imui_control_set()); 
            }
        }
        else if (key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            if (g_imc_key.global_data_ptr->symb_count && g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
				mmi_imc_redraw_imui(mmi_imc_get_current_floating_imui_control_set()); 
            }
        }
        else if (key_code == MMI_IMC_KEY_TONE_CHANGE)
        {
            mmi_imc_key_multitap_phoetic_get_candidate_with_tone();
        }
        break;
    case MMI_IMC_STATE_SPELL_MULTITAP:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            if (g_imc_key.key_info.last_imc_key_code != key_code)
            {
                /* confirm current input */
                mmi_imc_cancel_timer();
                g_imc_key.spell_multitap_index = -1;
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__		
                mmi_ime_multitap_confirm();
#endif
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);   
                mmi_imc_key_add_key_element(g_imc_key.key_info.last_imc_key_code);
            }
            else
            {
                mmi_imc_delete_timer();
                /* get new candidate */
            }
            if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
            {
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP);      
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE;
            }
            else if (g_imc_key.spell_multitap_index)
            {
                /* try again. */
                g_imc_key.spell_multitap_index = -1;
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    /* state not change. */
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }                    
            }
            break;
        }
        /* confirm current input */
        mmi_imc_cancel_timer();
        if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->symb_count)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            }
        }
        else if (key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            if (g_imc_key.global_data_ptr->symb_count)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            }
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
			/*Adjusting symbol count for cand state*/
			U16 i;
            for(i=0;g_imc_key.global_data_ptr->symb_buff[i]!=0;i++)
            {
                /*increase the counter to get get correct symbol count */
            }
            g_imc_key.global_data_ptr->symb_count=i;
            if (mmi_imc_key_remove_symbol())
            {
                /* update composition buffer by symbol */
                if (g_imc_key.global_data_ptr->symb_count == 0)
                {
                    if (!g_imc_key.global_data_ptr->input_confirm_length)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        mmi_imc_input_area_delete_string(1);
                        /* to reset the global data */
                        mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_length);
                        mmi_imc_reset_global_data();
                        mmi_imc_update_candidate_as_null();
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                    }
                }
                else if (mmi_imc_key_multitap_phonetic_get_candidate())
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                }
                else
                {
                    ASSERT(0);
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_TONE_CHANGE)
        {           
            mmi_imc_key_multitap_phoetic_get_candidate_with_tone();
        }
        break;
    case MMI_IMC_STATE_CAND_SELECTING:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            cand_index = key_code - MMI_IMC_KEY_CHAR_1;
            if (cand_index < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = cand_index;
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_multitap_phonetic_select_candidate();
                mmi_imc_gdi_lcd_freeze(MMI_FALSE);
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (g_imc_key.global_data_ptr->tone != MMI_IMC_SYMB_TONE_NONE)
            {
                g_imc_key.global_data_ptr->tone = MMI_IMC_SYMB_TONE_NONE;
                mmi_imc_key_phonetic_key_query_candidate_with_tone(MMI_IMC_SYMB_TONE_NONE);
            }
            else
            {
                mmi_imc_key_multitap_phonetic_get_candidate();
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
            }
            //mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
			mmi_imc_redraw_imui(mmi_imc_get_current_floating_imui_control_set());
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if(key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        break;
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            /* reset all data and start a new input */
            g_imc_key.global_data_ptr->key_element_length = 0;
            mmi_imc_reset_global_data();
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.spell_multitap_index = -1;
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

            /* get candidate if valid symbol */
            if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
            {
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP); 
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE;
            }
            /* there is no valid composition by the key sequence. */                
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.spell_multitap_index = -1;
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if(key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }            
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }

        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            S32 cand_select = (key_code - MMI_IMC_KEY_CHAR_1);
            if (cand_select < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = cand_select;
     
                
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_gdi_lcd_freeze(MMI_FALSE);

                mmi_imc_redraw_screen_by_state();
            }
        }
		else if (mmi_imc_key_is_key_symbol(key_code)) 
        {
            /* reset all data and start a new input */
            g_imc_key.global_data_ptr->key_element_length = 0;
            mmi_imc_reset_global_data();
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.spell_multitap_index = -1;
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

            /* get candidate if valid symbol */
            if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
            {
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP); 
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE;
            }
            /* there is no valid composition by the key sequence. */                
            g_imc_key.global_data_ptr->symb_count = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.spell_multitap_index = -1;
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
		#if defined(__MMI_IME_V3__)
			mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state(); 
		#else
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->cand_select = 0;
            mmi_imc_change_candidate_box_page();
            mmi_imc_set_state(MMI_IMC_STATE_PRE_ASSOC_SELECTING);
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
		#endif
        }            
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                mmi_imc_redraw_screen_by_state();
            }
        }

        break;
    }

    return ret_value;
#endif //(defined __MMI_IME_MULTITAP_PHONETIC_INPUT__)
}



#else


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tone_mark;
    mmi_imc_state_enum cur_state = mmi_imc_get_state();
    MMI_BOOL ret_value = MMI_TRUE;
    mmi_imm_input_mode_enum old_mode;
    MMI_BOOL is_last_position = MMI_FALSE;
                BOOL lcd_freeze = gdi_lcd_get_freeze();
    U8 i=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(cur_state)
    {
#if defined(__MMI_TOUCH_SCREEN__)
        case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                is_last_position = mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);

                mmi_imc_pen_confirm_handwriting_selection();

                if (!is_last_position)
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                }

                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
                return MMI_TRUE;
            }
            if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
            {
                /* for arrow key, do nothing. */
                return MMI_TRUE;
            }
            if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }

            old_mode = mmi_imm_get_curr_input_mode();

            mmi_imc_pen_confirm_handwriting_selection(); /* no break */

            /* In canceling timer, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                return MMI_TRUE;
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            break;
#endif
        case MMI_IMC_STATE_INITIAL:
        case MMI_IMC_STATE_SPELL_INPUTING:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
                /* get candidate if valid symbol */
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    if (cur_state != MMI_IMC_STATE_VK_CAND)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP); 
                    }
                    else
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                    }
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                /* there is no valid composition by the key sequence. */                
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }            
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                 /*Adjusting symbol count for cand state*/
                for(i=0;g_imc_key.global_data_ptr->symb_buff[i]!=0;i++)
                {
                /*increase the counter to get get correct symbol count */
                }
                g_imc_key.global_data_ptr->symb_count=i;
                if (mmi_imc_key_remove_symbol())
                {
                    /* update composition buffer by symbol */
                    g_imc_key.global_data_ptr->cand_select = 0;
                    g_imc_key.global_data_ptr->comp_buff[g_imc_key.global_data_ptr->symb_count] = '\0';
                    if(g_imc_key.global_data_ptr->comp_buff[0])
                    {
                    mmi_imc_update_composition_box_by_query_result_ext(g_imc_key.global_data_ptr->comp_buff, 1, MMI_FALSE, MMI_TRUE);
                    }                   

                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                    else if (mmi_imc_change_highlighted_composition_from_composition_box(0))
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    }
                    else
                    {
                        ASSERT(0);
                    }
                    mmi_imc_redraw_screen_by_state();
                }
                else if (cur_state == MMI_IMC_STATE_INITIAL)
                {
                    mmi_imc_key_common_clear_key_handler();
                }
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if ((key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN) && cur_state == MMI_IMC_STATE_VK_CAND)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_DOWN && cur_state == MMI_IMC_STATE_SPELL_INPUTING)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_SPACE && cur_state == MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
            break;
        case MMI_IMC_STATE_SPELL_MULTITAP:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
                if (g_imc_key.key_info.last_imc_key_code != key_code)
                {
                    /* confirm current input */
                    mmi_imc_cancel_timer();
                    g_imc_key.spell_multitap_index = -1;
#if! defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__		
                    mmi_ime_multitap_confirm();
#endif
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);   
                    mmi_imc_key_add_key_element(g_imc_key.key_info.last_imc_key_code);
                }
                else
                {
                    mmi_imc_delete_timer();
                    /* get new candidate */
                }
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP);      
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                else if (g_imc_key.spell_multitap_index >= 0)
                {
                    /* try again. */
                    g_imc_key.spell_multitap_index = -1;
                    if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                    {
                        /* state not change. */
                        mmi_imc_redraw_screen_by_state();
                        return MMI_TRUE;
                    }                    
                    else
                    {
                        MMI_ASSERT(0);    
                    }    
                }
                break;
            }
            /* confirm current input */
            mmi_imc_cancel_timer();

            if ((key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN) && mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_DOWN && mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
				/*Adjusting symbol count for cand state*/  
                for(i=0;g_imc_key.global_data_ptr->symb_buff[i]!=0;i++)
                {
                /*increase the counter to get get correct symbol count */
                }
                g_imc_key.global_data_ptr->symb_count=i;
                if (mmi_imc_key_remove_symbol())
                {
                    /* update composition buffer by symbol */
                    g_imc_key.global_data_ptr->cand_select = 0;
                    g_imc_key.global_data_ptr->comp_buff[g_imc_key.global_data_ptr->symb_count] = '\0';
                      if(g_imc_key.global_data_ptr->comp_buff[0])
                    {
                    mmi_imc_update_composition_box_by_query_result_ext(g_imc_key.global_data_ptr->comp_buff, 1, MMI_FALSE, MMI_TRUE);
                     }
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                    else if (mmi_imc_change_highlighted_composition_from_composition_box(0))
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    }
                    else
                    {
                        ASSERT(0);
                    }
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            break;
        case MMI_IMC_STATE_CAND_SELECTING:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
                /* get candidate if valid symbol */
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    if (cur_state != MMI_IMC_STATE_VK_CAND)
                {
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP); 
                    }
                    else
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_VK_CAND_MULTITAP);
                    }
                        mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                    }
                /* there is no valid composition by the key sequence. */                
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                if (g_imc_key.global_data_ptr->tone != MMI_IMC_SYMB_TONE_NONE)
                {
                    g_imc_key.global_data_ptr->tone = MMI_IMC_SYMB_TONE_NONE;
                    mmi_imc_key_phonetic_key_query_candidate_with_tone(MMI_IMC_SYMB_TONE_NONE);
                }
                else
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                }
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if(key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
            else if (key_code == MMI_IMC_KEY_TONE_CHANGE)
            {
                S32 i;
                tone_mark = g_imc_key.global_data_ptr->tone;
                for (i = 0; i < 5; i ++)
                {
                    tone_mark = ((tone_mark+ 1) - MMI_IMC_SYMB_TONE_1) % 5 + MMI_IMC_SYMB_TONE_1;
                    if (mmi_imc_key_phonetic_key_query_candidate_with_tone(tone_mark))
                    {
                        g_imc_key.global_data_ptr->tone = tone_mark;
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                        break;
                    }
                }
            }
#endif
            break;
        case MMI_IMC_STATE_ASSOC_SELECTING:
            if (mmi_imc_key_is_key_symbol(key_code))
            {
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if (g_imc_key.key_info.ucs2_value == L'0')
                {
                    return MMI_TRUE;
                }
#endif
                /* reset all data and start a new input */
                g_imc_key.global_data_ptr->key_element_length = 0;
                mmi_imc_reset_global_data();
                g_imc_key.global_data_ptr->symb_count = 0;
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.spell_multitap_index = -1;
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                /* get candidate if valid symbol */
                if (mmi_imc_key_multitap_phonetic_get_composition(key_code))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_MULTITAP); 
                    mmi_imc_redraw_screen_by_state();
                    return MMI_TRUE;
                }
                else
                {
                    /* there is no valid composition by the key sequence. */                
                    g_imc_key.global_data_ptr->symb_count = 0;
                    g_imc_key.global_data_ptr->cand_page = 0;
                    g_imc_key.spell_multitap_index = -1;
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();                
            }            
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                    mmi_imc_redraw_screen_by_state();
                }
            }

            break;
    }

    return ret_value;
#endif //(defined __MMI_IME_MULTITAP_PHONETIC_INPUT__)
}

#endif
#endif


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_phonetic_key_query_candidate_with_tone
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_phonetic_key_query_candidate_with_tone(U16 tone)
{
#if (defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0; 
    mmi_ime_query_param_struct query;
    mmi_ime_query_result_struct result;
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query.elembuf_ptr = g_imc_key.global_data_ptr->symb_buff;
    query.elembuf_cnt = g_imc_key.global_data_ptr->symb_count;
    query.tone_value = tone;
    query.first_index = 0;
    query.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    result.result_buffer = g_imc_key.global_data_ptr->cand_buff;

    mmi_ime_word_get_candidates(&query, &result);

    if (result.result_cnt)
    {
        g_imc_key.global_data_ptr->cand_page = 0;
        cand_count = mmi_imc_update_candidate_box_by_query_result(result.result_buffer, result.result_cnt, result.next_page);
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc_key.global_data_ptr->cand_select = (g_imc_key.global_data_ptr->cand_count - 1) / 2;
#else
        g_imc_key.global_data_ptr->cand_select = 0;
#endif
        g_imc_key.global_data_ptr->tone = tone;
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
        /* update composition area */
        for (i = 0; i < g_imc_key.global_data_ptr->symb_count; i++)
        {
            g_imc_key.global_data_ptr->comp_buff[i] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);            
        }
        if (tone != MMI_IMC_SYMB_TONE_NONE)
        {
            g_imc_key.global_data_ptr->comp_buff[i] = mmi_ime_word_symbol_to_code(tone);
            i++;
        }
        g_imc_key.global_data_ptr->comp_buff[i] = '\0';
        mmi_imc_update_composition_box_by_query_result_ext(g_imc_key.global_data_ptr->comp_buff, 1, MMI_FALSE, MMI_TRUE);
    }
    return cand_count;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
            BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

    case MMI_IMC_STATE_SPELL_MULTITAP:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            mmi_imc_delete_timer();
            mmi_imc_start_timer(
                MMI_IMC_KEY_MULTITAP_TIMER, 
                mmi_imc_key_multitap_phoetic_timeout_callback,             
                mmi_imc_key_multitap_phoetic_timeout_callback);
        }
        else if (key_code == MMI_IMC_KEY_CONFIRM)
        {
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            mmi_imc_cancel_timer();
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            mmi_imc_key_multitap_phonetic_select_candidate();
            mmi_imc_redraw_screen_by_state();
#else
            mmi_imc_cancel_timer();
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            mmi_imc_redraw_screen_by_state();
#endif
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
    case MMI_IMC_STATE_VK_CAND_MULTITAP:
        if (mmi_imc_key_is_key_symbol(key_code))
        {
            mmi_imc_delete_timer();
            mmi_imc_start_timer(
                MMI_IMC_KEY_MULTITAP_TIMER, 
                mmi_imc_key_multitap_phoetic_timeout_callback,             
                mmi_imc_key_multitap_phoetic_timeout_callback);
        }
        else if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_cancel_timer();

            if (g_imc_key.global_data_ptr->cand_count > 0)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                mmi_imc_redraw_screen_by_state();
            }
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        break;
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
            if (g_imc_key.global_data_ptr->symb_count == 0)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32) g_imc_key.global_data_ptr->input_buff, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
            else if (g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
				mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_multitap_phonetic_select_candidate();
				mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_redraw_screen_by_state();
            }
#else
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_redraw_screen_by_state();
            }
#endif
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    case MMI_IMC_STATE_CAND_SELECTING:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_key_multitap_phonetic_select_candidate();
            mmi_imc_redraw_screen_by_state();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
			mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            mmi_imc_select_candidate_from_candidate_box();
			mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
            mmi_imc_redraw_screen_by_state();
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;            
#else
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_ASSOC_SELECTING:
#endif
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_STATE_HAND_WRITING_CAND:
#endif
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);

            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
            mmi_imc_select_candidate_from_candidate_box();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);

            mmi_imc_redraw_screen_by_state();

            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    case MMI_IMC_STATE_VK_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (g_imc_key.global_data_ptr->cand_count > 0)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                mmi_imc_pen_update_display_area_by_sym_buffer();
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phonetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_multitap_phonetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))

    switch (key_code)
    {
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
    #if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
    case MMI_IMC_KEY_CLEAR:
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        break;
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    case MMI_IMC_KEY_CLEAN:
                mmi_imc_delete_all();
                break;
#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    case MMI_IMC_KEY_CHANGE_LANGUAGE:
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        break;
#endif
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_multitap_phoetic_timeout_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_multitap_phoetic_timeout_callback(void)
{
#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key.spell_multitap_index = -1;
    g_imc_key.global_data_ptr->symb_count ++;
    if (mmi_imc_get_state() != MMI_IMC_STATE_VK_CAND_MULTITAP)
    {
        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
    }
#if defined(__MMI_TOUCH_SCREEN__)
    else
    {
        mmi_imc_set_state(MMI_IMC_STATE_VK_CAND);
    }
#endif
#endif //#if defined(__MMI_IME_MULTITAP_PHONETIC_INPUT__) || (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) && defined(__MMI_LANG_SM_CHINESE__))
}


#if defined(__MMI_IME_MAGIC_ONE__)

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_update_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_magic_state_update_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_len = 0;
    UI_string_type cand = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
    if (mmi_imc_get_state() == MMI_IMC_STATE_PRE_SMART_CANDIDATE)
        cand_len = mmi_ucs2strlen((const S8*) cand);
   #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
    mmi_imc_input_area_delete_string(g_imc_key.global_data_ptr->input_length);
    mmi_imc_input_area_add_string(cand);
    mmi_imc_update_input_area(
        0, 
        cand_len, 
        0, 
        0,
        g_imc_key.global_data_ptr->input_length);
    #endif
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, (U32)g_imc_key.global_data_ptr->cand_select, 0);

}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_get_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_magic_state_get_candidate(MMI_BOOL focus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct param = {0};
    mmi_ime_query_result_struct result = {0};
    S32 cand_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set key input */
    param.elembuf_ptr = g_imc_key.global_data_ptr->key_buffer;
    param.elembuf_cnt = g_imc_key.global_data_ptr->key_element_length;
    /* set candidate */
    param.first_index = g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page];
    param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;

    /* set result */
    result.result_buffer = g_imc_key.global_data_ptr->cand_buff;

    mmi_ime_word_get_candidates(&param, &result);

    /* update data */
    if (result.result_cnt)
    {
        g_imc_key.global_data_ptr->cand_select = 0;
        cand_count = mmi_imc_update_candidate_box_by_query_result(
            result.result_buffer, 
            result.result_cnt, 
            result.next_page);
        if (focus)
            mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
        else
            mmi_imc_set_state(MMI_IMC_STATE_PRE_SMART_CANDIDATE);
        mmi_imc_key_magic_state_update_candidate();
    }
    else
    {
        ASSERT(0);
    }
    return cand_count;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_magic_state_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum cur_state = MMI_IMC_STATE_NONE;
    MMI_BOOL magic_state = MMI_FALSE;
    UI_string_type cand = NULL;
    S32 cand_index = 0;
    U32 control_set = (MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_state = mmi_imc_get_state();
    magic_state = mmi_imc_check_magic_state();
    switch(cur_state)
    {
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
        }
        else
        {
            /* phonetic symbol picker state. */
            if (key_code == MMI_IMC_KEY_RIGHT)
            {
                if (g_imc_key.global_data_ptr->cand_select < g_imc_key.global_data_ptr->cand_count - 1)
                {
                    g_imc_key.global_data_ptr->cand_select ++;
                    mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                    mmi_imc_key_magic_state_update_candidate();
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (key_code == MMI_IMC_KEY_LEFT)
            {
                mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_set_state(MMI_IMC_STATE_SMART_CANDIDATE);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9)
            {
                mmi_imc_change_to_magic_state();
                /* process key event. */
                mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);       
                mmi_imc_redraw_screen_by_state();
            }
        }
        break;
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
        }
        else
        {
            /* phonetic symbol picker state. */
            if (key_code == MMI_IMC_KEY_RIGHT)
            {
                if (g_imc_key.global_data_ptr->cand_select < g_imc_key.global_data_ptr->cand_count - 1)
                {
                    g_imc_key.global_data_ptr->cand_select ++;
                    mmi_imc_key_magic_state_update_candidate();
                }
                else if (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1])
                {
                    g_imc_key.global_data_ptr->cand_page ++;
                    /* goto next page */
                    mmi_imc_key_magic_state_get_candidate(MMI_TRUE);                        
                }
                mmi_imc_redraw_imui(control_set);
            }
            else if (key_code == MMI_IMC_KEY_LEFT)
            {
                if (g_imc_key.global_data_ptr->cand_select > 0)
                {
                    g_imc_key.global_data_ptr->cand_select --;
                    mmi_imc_key_magic_state_update_candidate();
                }
                else if (g_imc_key.global_data_ptr->cand_page > 0)
                {
                    g_imc_key.global_data_ptr->cand_page --;
                    /* goto previous page. */
                    mmi_imc_key_magic_state_get_candidate(MMI_TRUE);
                    g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
                    mmi_imc_key_magic_state_update_candidate();
                }
                mmi_imc_redraw_imui(control_set);
            }
            else if (key_code == MMI_IMC_KEY_DOWN)
            {
                if (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1])
                {
                    /* there is remaining page. */
                    g_imc_key.global_data_ptr->cand_page ++;
                    mmi_imc_key_magic_state_get_candidate(MMI_TRUE);
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_select = g_imc_key.global_data_ptr->cand_count - 1;
                    mmi_imc_key_magic_state_update_candidate();
                }
                mmi_imc_redraw_imui(control_set);
            }
            else if (key_code == MMI_IMC_KEY_UP)
            {
                if (g_imc_key.global_data_ptr->cand_page)
                {
                    /* goto previous page. */
                    g_imc_key.global_data_ptr->cand_page --;
                    mmi_imc_key_magic_state_get_candidate(MMI_TRUE);
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_select = 0;
                    mmi_imc_key_magic_state_update_candidate();
                }
                mmi_imc_redraw_imui(control_set);
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.global_data_ptr->cand_select = 0;
                mmi_imc_key_magic_state_get_candidate(MMI_FALSE);
                mmi_imc_redraw_imui(control_set);
            }
            else if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_9)
            {
                cand_index = key_code - MMI_IMC_KEY_SYM_1;
                if (cand_index >= 0 && cand_index < g_imc_key.global_data_ptr->cand_count)
                {
                    cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, (U8)cand_index);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)cand, mmi_ucs2strlen((const S8*)cand));
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
        }
        break;
    default:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
        }
        else
        {
            ASSERT(0);
        }
        break;
    }

    if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        if (magic_state)
        {
            mmi_imc_back_from_magic_state();        
        }
        else
        {
            memcpy(&g_imc_key.key_info, &g_imc_key.key_info_backup, sizeof(mmi_imc_key_info_struct));
        }
        mmi_imc_set_magic_key_down(MMI_FALSE);
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_magic_state_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum cur_state = MMI_IMC_STATE_NONE;
    MMI_BOOL magic_state = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_state = mmi_imc_get_state();
    magic_state = mmi_imc_check_magic_state();
    switch(cur_state)
    {
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_up_handler(key_code, event_type);
        }
        else
        {
            /* phonetic symbol picker state. */
            if (key_code == MMI_IMC_KEY_CONFIRM)
            {
                    #if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)(g_imc_key.global_data_ptr->input_buff), (U32)(g_imc_key.global_data_ptr->input_length));
                    #endif
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE || key_code == MMI_IMC_KEY_CHANGE_LANGUAGE)
            {
                mmi_imc_key_smart_alphabetic_key_up_handler(key_code, event_type);
                return MMI_TRUE;
            }
        }
        break;
    default:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_up_handler(key_code, event_type);
        }
        else
        {
            ASSERT(0);
        }
        break;
    }

    if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        if (magic_state)
        {
            mmi_imc_back_from_magic_state();        
        }
        else
        {
            memcpy(&g_imc_key.key_info, &g_imc_key.key_info_backup, sizeof(mmi_imc_key_info_struct));
        }
        mmi_imc_set_magic_key_down(MMI_FALSE);
    }

    return MMI_TRUE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_key_long_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_magic_state_key_long_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum cur_state = MMI_IMC_STATE_NONE;
    MMI_BOOL magic_state = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_state = mmi_imc_get_state();
    magic_state = mmi_imc_check_magic_state();
    switch(cur_state)
    {
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_PRE_SMART_CANDIDATE:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_long_press_handler(key_code, event_type);
        }
        else
        {
            if (key_code == MMI_IMC_KEY_CHANGE_MODE || key_code == MMI_IMC_KEY_CHANGE_LANGUAGE)
            {
                mmi_imc_key_smart_alphabetic_key_long_press_handler(key_code, event_type);
            }
            /* phonetic symbol picker state. */
        }
        break;
    default:
        if (magic_state)
        {
            mmi_imc_key_smart_alphabetic_key_long_press_handler(key_code, event_type);
        }
        else
        {
            ASSERT(0);
        }
        break;
    }

    if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
    {
        if (magic_state)
        {
            mmi_imc_back_from_magic_state();        
        }
        else
        {
            memcpy(&g_imc_key.key_info, &g_imc_key.key_info_backup, sizeof(mmi_imc_key_info_struct));
        }
        mmi_imc_set_magic_key_down(MMI_FALSE);
    }

    return MMI_TRUE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_change_to_magic_one_state
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_change_to_magic_one_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_imc_key.key_info_backup, &g_imc_key.key_info, sizeof(mmi_imc_key_info_struct));
    g_imc_key.key_info.key_down_handler = mmi_imc_key_magic_state_key_down_handler;
    g_imc_key.key_info.key_up_handler = mmi_imc_key_magic_state_key_up_handler;
    g_imc_key.key_info.key_long_handler = mmi_imc_key_magic_state_key_long_handler;
    g_imc_key.key_info.key_repeat_handler = mmi_imc_key_magic_state_key_down_handler;
    g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_magic_state_chage_cand_cap
* DESCRIPTION
*  change candidate capital status 
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_magic_state_chage_cand_cap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_word_capital_state_enum state = g_imc_key.global_data_ptr->capital_state;
    S32 cand_cnt = g_imc_key.global_data_ptr->cand_count;
    MMI_BOOL next_page = (g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page + 1] > 0? MMI_TRUE: MMI_FALSE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->symb_count == 1 && g_imc_key.global_data_ptr->symb_buff[0] == MMI_IMC_SYMB_KEY_1)
        return;

    if (state == MMI_IME_WORD_CAPITAL_STATE_NONE)
    {
        state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
    }
    else
    {
        state ++;
        if (state == MMI_IME_WORD_CAPITAL_STATE_MAX)
            state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    }

    /* special case for the candidiate lenght is 1. MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER would be skipped. */
    if ((g_imc_key.global_data_ptr->symb_count == 1 || 
        (g_imc_key.global_data_ptr->symb_buff[0] == MMI_IMC_SYMB_KEY_0 || g_imc_key.global_data_ptr->symb_buff[0] == MMI_IMC_SYMB_KEY_1) ||
        (g_imc_key.global_data_ptr->symb_count == 2 && (g_imc_key.global_data_ptr->symb_buff[1] == MMI_IMC_SYMB_KEY_0 || g_imc_key.global_data_ptr->symb_buff[1] == MMI_IMC_SYMB_KEY_1)))
        && state == MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER ) 
    {
        state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
    }

    g_imc_key.global_data_ptr->capital_state = state;
    mmi_imc_change_candidate_list_caps(state);
    mmi_imc_update_candidate_box_by_query_result(g_imc_key.global_data_ptr->cand_buff, (U8)cand_cnt, next_page);
    mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);
    mmi_imc_redraw_screen_by_state();

}
#endif

#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_insert_key
* DESCRIPTION
*  insert the key_code into the key buffer at global_data.key_buffer_cursor and cursor index increase one.
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_insert_key(mmi_imc_key_custom_value key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_symbol_key_enum sym = (key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE;    
    S32 i =0;
    S32 space_check = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->input_length >= MMI_IMC_MAX_INPUT_STRING_SIZE)
        return MMI_FALSE;
    if (g_imc_key.global_data_ptr->key_element_length + 1 < MMI_IMC_MAX_KEY_BUFFER_SIZE)
    {
        /* Key 0 is not allowed in the begining */
        if (g_imc_key.global_data_ptr->key_buffer_cusor == 0 && sym == MMI_IMC_SYMB_KEY_0)
        {
            return MMI_FALSE;
        }

        if (g_imc_key.global_data_ptr->key_buffer_cusor == g_imc_key.global_data_ptr->key_element_length)
        {
            /* if previous symbol is 0 and cur symbol is 0, do nothing */
            if (g_imc_key.global_data_ptr->key_buffer_cusor &&
                g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 1] == MMI_IMC_SYMB_KEY_0 &&
                sym == MMI_IMC_SYMB_KEY_0)
            {
                return MMI_FALSE;
            }                
            /* cursor in the end of the key buffer */
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] = sym;
        }
        else
        {
            /* contiguous 0 in the end is not allowed */
            if (sym == MMI_IMC_SYMB_KEY_0 &&
                g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] == MMI_IMC_SYMB_KEY_0 &&
                g_imc_key.global_data_ptr->key_buffer_cusor == g_imc_key.global_data_ptr->key_element_length)
            {
                return MMI_FALSE;    
            }
            if (g_imc_key.global_data_ptr->key_buffer_cusor == 0 && 
                g_imc_key.global_data_ptr->key_element_length && 
                g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] != MMI_IMC_SYMB_KEY_0)
            {
                /* cursor is in the begining and there are symbol in the following. */
                space_check = 2;
                if (g_imc_key.global_data_ptr->key_element_length > MMI_IMC_MAX_KEY_BUFFER_SIZE - 2)
                    return MMI_FALSE;
            }
            else if (g_imc_key.global_data_ptr->key_buffer_cusor && g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 1] == MMI_IMC_SYMB_KEY_0)
            {
                /* if previous symbol is 0 and current symbol is not 0, add another 0 between surrent symbol and the next symbol */
                space_check = 2;
                if (g_imc_key.global_data_ptr->key_element_length > MMI_IMC_MAX_KEY_BUFFER_SIZE - 2)
                    return MMI_FALSE;
            }

            for (i = (g_imc_key.global_data_ptr->key_element_length + space_check - 1); i > g_imc_key.global_data_ptr->key_buffer_cusor; i--)
            {
                g_imc_key.global_data_ptr->key_buffer[i] = g_imc_key.global_data_ptr->key_buffer[i - space_check]; 
            }
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] = sym; 
            if (space_check == 2)
                g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor + 1] = MMI_IMC_SYMB_KEY_0;
        }
        g_imc_key.global_data_ptr->key_buffer_cusor ++;
        g_imc_key.global_data_ptr->key_element_length += space_check;
        return MMI_TRUE;
    }
    return MMI_FALSE;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_delete_key
* DESCRIPTION
*  delete the key element in the cursor
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_delete_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 i =0;
    S32 check_space = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_buffer_cusor > 1 &&
        g_imc_key.global_data_ptr->key_buffer_cusor < g_imc_key.global_data_ptr->key_element_length)
    {
        if (g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 1] == MMI_IMC_SYMB_KEY_0)
        {
            g_imc_key.global_data_ptr->key_buffer_cusor --;
            return MMI_TRUE;
        }
    }

    if (g_imc_key.global_data_ptr->key_element_length)
    {
        if (g_imc_key.global_data_ptr->key_buffer_cusor > 1 && 
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 2] == MMI_IMC_SYMB_KEY_0)
            check_space = 2;
        if (g_imc_key.global_data_ptr->key_buffer_cusor == 1 && 
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] == MMI_IMC_SYMB_KEY_0)
            check_space = 2;

        if (g_imc_key.global_data_ptr->key_buffer_cusor == g_imc_key.global_data_ptr->key_element_length)
        {
            /* cursor in the end of the key buffer */
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] = 0;
        }
        else
        {

            for (i = g_imc_key.global_data_ptr->key_buffer_cusor - 1; i < g_imc_key.global_data_ptr->key_element_length; i++)
            {
                g_imc_key.global_data_ptr->key_buffer[i] = g_imc_key.global_data_ptr->key_buffer[i + check_space]; 
            }
        }
        g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length - 1] = 0;
        if (check_space == 2)
            g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_element_length - 2] = 0;

        g_imc_key.global_data_ptr->key_element_length -= check_space;
        g_imc_key.global_data_ptr->key_buffer_cusor -= check_space;

        /* when current composition is clean and goto previous composition, delete the space between current comp and previous comp */

        ret = MMI_TRUE;
    }

    if (g_imc_key.global_data_ptr->key_buffer_cusor < 0)
        g_imc_key.global_data_ptr->key_buffer_cusor = 0;
    if (g_imc_key.global_data_ptr->key_element_length < 0)
        g_imc_key.global_data_ptr->key_element_length = 0;

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_update_input_area
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_smart_phonetic_update_input_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    mmi_imc_state_enum state = MMI_IMC_STATE_NONE;
    S32 cursor = 0;
    MMI_BOOL highlight = MMI_FALSE;
    S32 highlight_start = 0, highlight_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_CSTAR_PHRASE_INPUT__
    state = mmi_imc_get_state();
    highlight = MMI_FALSE;
    switch (state)
    {
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
        highlight = MMI_TRUE;
        cursor = g_imc_key.global_data_ptr->input_confirm_length + g_imc_key.global_data_ptr->key_buffer_cusor;
        break;
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
        cursor = g_imc_key.global_data_ptr->input_confirm_length;
        break;
    }

    /* after space (key 0) is inserted, no highlight. */
    if (g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 1] == MMI_IMC_SYMB_KEY_0)
        highlight = MMI_FALSE;

    if (highlight)
    {
        if (g_imc_key.global_data_ptr->key_buffer_cusor)
        {
            /* check the previous symbol to get symbol count */
            index = g_imc_key.global_data_ptr->key_buffer_cusor;
            do 
            {
                index --;
            } while (index > 0 && g_imc_key.global_data_ptr->key_buffer[index - 1] != MMI_IMC_SYMB_KEY_0);
            highlight_start = g_imc_key.global_data_ptr->input_confirm_length + index;
            highlight_len = g_imc_key.global_data_ptr->key_buffer_cusor - index;
        }
        else
        {
            highlight_len = g_imc_key.global_data_ptr->input_confirm_length;
        }
    }
    #endif
    mmi_imc_update_input_area(
        highlight_start, 
        highlight_len, 
        g_imc_key.global_data_ptr->input_confirm_length, 
        g_imc_key.global_data_ptr->cand_match_len[g_imc_key.global_data_ptr->cand_select],
        cursor);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_delete_confirm_string
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_delete_confirm_string(S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 unconfirm_len = 0;
    S32 old_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imc_key.global_data_ptr->input_confirm_length)
    {
        return MMI_FALSE;
    }
    else
    {
        if (len >  g_imc_key.global_data_ptr->input_confirm_length)
            len =  g_imc_key.global_data_ptr->input_confirm_length;

        old_index = g_imc_key.global_data_ptr->input_confirm_length;
        g_imc_key.global_data_ptr->input_confirm_length -= len;
        g_imc_key.global_data_ptr->input_length -= len;

        unconfirm_len = g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length;

        while (i < unconfirm_len)
        {
            g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_confirm_length + i] = g_imc_key.global_data_ptr->input_buff[old_index + i];
            i ++;
        }

        g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_length] = 0;
    }
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_delete_key
* DESCRIPTION
*  move the cursor of key buffer
*  For example:
*    key buffer : abc def| ghi
*    if  moving ahead: abc| def ghi
*    if  moving behind: abc def ghi|
* PARAMETERS
*   MMI_BOOL direction: MMI_TRUE: move ahead MMI_FALSE: move behind
* RETURNS
*   if the action success, return MMI_TRUE, else return MMI_FALSE
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_move_key_buffer_cursor(MMI_BOOL dic)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dic)
    {
        /* move ahead */
        if (!g_imc_key.global_data_ptr->key_buffer_cusor)
            return MMI_FALSE;
        do 
        {
            g_imc_key.global_data_ptr->key_buffer_cusor --;

        }while (g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] != MMI_IMC_SYMB_KEY_0 &&
            g_imc_key.global_data_ptr->key_buffer_cusor > 0);


    }
    else
    {
        /* move behind */
        if (g_imc_key.global_data_ptr->key_buffer_cusor == g_imc_key.global_data_ptr->key_element_length)
            return MMI_FALSE;
        do 
        {
            g_imc_key.global_data_ptr->key_buffer_cusor ++;
        } while ( g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] != MMI_IMC_SYMB_KEY_0 &&
            g_imc_key.global_data_ptr->key_buffer_cusor != g_imc_key.global_data_ptr->key_element_length);
    }

    /* update input area */
    mmi_imc_key_smart_phonetic_update_input_area();
    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_INPUT_SET_FOCUS, 0, 0);
    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_get_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
 S32 mmi_imc_key_smart_phonetic_get_candidate(MMI_BOOL match_comp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct param = {0};
    mmi_ime_query_result_struct result = {0};
    UI_character_type sym[MMI_IMC_MAX_KEY_NUM] = {0};
    S32 cand_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set key input */
    param.elembuf_ptr = g_imc_key.global_data_ptr->key_buffer;
    param.elembuf_cnt = g_imc_key.global_data_ptr->key_element_length;
    /* set composition */
    if (!match_comp)
    {
        param.composition_index = 0xff;
        g_imc_key.global_data_ptr->comp_page = 0;
        g_imc_key.global_data_ptr->comp_select = 0;
    }
    else if(mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT || mmi_imc_get_state() == MMI_IMC_STATE_SPELL_INPUTING_GRID || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT) //slanting
    {
        param.composition_index = g_imc_key.global_data_ptr->comp_first_index[g_imc_key.global_data_ptr->comp_page] + g_imc_key.global_data_ptr->comp_select;
		mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, (U32)param.composition_index, 0);
    }
    param.composition_first_index = g_imc_key.global_data_ptr->comp_first_index[g_imc_key.global_data_ptr->comp_page];
    param.composition_desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
		 param.composition_desired_cnt =MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
	}
	#endif
    /* set candidate */
    param.first_index = g_imc_key.global_data_ptr->cand_first_index[g_imc_key.global_data_ptr->cand_page];
    param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    param.tone_value = MMI_IMC_SYMB_TONE_NONE;

    /* set result */
    result.composition_buffer = g_imc_key.global_data_ptr->comp_buff;
    result.result_buffer = g_imc_key.global_data_ptr->cand_buff;
    result.symbol_string = sym;
    result.match_length_table = g_imc_key.global_data_ptr->cand_match_len;
#if defined(__MMI_IME_CANDIDATE_GRID__)
	if( mmi_imc_is_grid_state() )
	{
		 param.desired_cnt =MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
		 mmi_imc_get_candidates_from_word_engine(&param, &result);
	}
	else
	{
		mmi_ime_word_get_candidates(&param, &result);
	}
#else
    mmi_ime_word_get_candidates(&param, &result);
#endif

    /* update data */
    if (result.result_cnt)
    {
        g_imc_key.global_data_ptr->cand_select = 0;
        g_imc_key.global_data_ptr->cand_page = 0;

        cand_count = mmi_imc_update_candidate_box_by_query_result(
            result.result_buffer, 
            result.result_cnt, 
            result.next_page);

        mmi_imc_update_composition_box_by_query_result(
            result.composition_buffer, 
            result.composition_result_cnt, 
            result.composition_next_page);

        if (!match_comp)
        {
            g_imc_key.global_data_ptr->comp_select = (U8)(-1);
            mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, (U32)(-1), 0);
        }


        mmi_imc_input_area_delete_string(g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        mmi_imc_input_area_add_string(sym);
#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID)
		{
			// do nothing
			;
		}
		else

#endif
		{
        mmi_imc_set_state(MMI_IMC_STATE_SPELL_WITH_INPUT);
		}
        mmi_imc_key_smart_phonetic_update_input_area();
    }
    return cand_count;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_select_candidate
* DESCRIPTION
* PARAMETERS
* RETURNS
*  MMI_BOOL  MMI_TRUE: all input are confirmed, MMI_FALSE: there are reminding key input
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_select_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type cand = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, g_imc_key.global_data_ptr->cand_select);
    S32 cand_match_len = g_imc_key.global_data_ptr->cand_match_len[g_imc_key.global_data_ptr->cand_select];
    S32 key_remind = 0;
    S32 i = 0;
#if defined(__MMI_IME_USER_DATABASE__)
    UI_character_type new_word[MMI_IMC_MAX_INPUT_BUFFSIZE + 1];
    S32 str_len;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length == 0
    #ifdef __MMI_CSTAR_PHRASE_INPUT__
    || cand_match_len == 0
    #endif
    )
    {
        g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_confirm_length] = '\0';
#if defined(__MMI_IME_USER_DATABASE__)
        str_len = g_imc_key.global_data_ptr->input_confirm_length;
        memcpy(&new_word[0], g_imc_key.global_data_ptr->input_buff, sizeof(UI_character_type) * (str_len));
        new_word[str_len] = '\0';
        mmi_ime_word_add_new_word(g_imc_key.curr_mode, new_word);
#endif
        mmi_imc_select_candidate_from_candidate_box();
        mmi_imc_reset_input_area();
        return MMI_TRUE;    
    }
    else if (cand_match_len >= g_imc_key.global_data_ptr->key_element_length)
    {
        /* insert confirm input in the input area first then insert the candidate */
        g_imc_key.global_data_ptr->input_buff[g_imc_key.global_data_ptr->input_confirm_length] = '\0';
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->input_buff, MMI_FALSE);
        /* all key input are confirmed. */
#if defined(__MMI_IME_USER_DATABASE__)
        memset(&new_word[0], 0, sizeof(UI_character_type) * (MMI_IMC_MAX_INPUT_BUFFSIZE + 1));
        str_len = mmi_ucs2strlen((const S8 *)g_imc_key.global_data_ptr->input_buff);
        memcpy(&new_word[0], g_imc_key.global_data_ptr->input_buff, sizeof(UI_character_type) * (str_len));
        memcpy(&new_word[str_len], cand, sizeof(UI_character_type) * (mmi_ucs2strlen((const S8 *)cand)));
        mmi_ime_word_add_new_word(g_imc_key.curr_mode, new_word);
#endif
        mmi_imc_select_candidate_from_candidate_box();
        mmi_imc_reset_input_area();
        return MMI_TRUE;
    }
    else
    {

        /* update input area */
        mmi_imc_input_area_delete_string( g_imc_key.global_data_ptr->input_length - g_imc_key.global_data_ptr->input_confirm_length);
        mmi_imc_input_area_add_string(cand);
        g_imc_key.global_data_ptr->input_confirm_length+= mmi_ucs2strlen((const S8*)cand);

        /* update key buffer */
        key_remind = g_imc_key.global_data_ptr->key_element_length - cand_match_len;
        for (i = 0; i < key_remind; i ++)
        {
            g_imc_key.global_data_ptr->key_buffer[i] = g_imc_key.global_data_ptr->key_buffer[cand_match_len + i];
            g_imc_key.global_data_ptr->key_buffer[cand_match_len + i] = 0;
        }
        g_imc_key.global_data_ptr->key_buffer[key_remind] = 0;
        g_imc_key.global_data_ptr->key_element_length = key_remind;
        g_imc_key.global_data_ptr->key_buffer_cusor -= cand_match_len;
        if (g_imc_key.global_data_ptr->key_buffer_cusor < 0)
            g_imc_key.global_data_ptr->key_buffer_cusor = 0;
        /* reset data and reget candidate */
        g_imc_key.global_data_ptr->cand_select = 0;
        g_imc_key.global_data_ptr->comp_select = 0;
        g_imc_key.global_data_ptr->cand_page = 0;
        g_imc_key.global_data_ptr->comp_page = 0;
        g_imc_key.global_data_ptr->cand_first_index[0] = 0;
        g_imc_key.global_data_ptr->comp_first_index[0] = 0;
        mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE);
        mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
        mmi_imc_key_smart_phonetic_update_input_area();
        return MMI_FALSE;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_smart_phonetic_comp_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length == 0)
        return 0;

    if (g_imc_key.global_data_ptr->comp_select == 0xff)
    {
        g_imc_key.global_data_ptr->comp_select = 0;

    } 
    else if (g_imc_key.global_data_ptr->comp_select + 1 < g_imc_key.global_data_ptr->comp_count)
    {
        g_imc_key.global_data_ptr->comp_select ++;
    }
    else if (g_imc_key.global_data_ptr->comp_first_index[g_imc_key.global_data_ptr->comp_page + 1])
    {
        g_imc_key.global_data_ptr->comp_page ++;
        g_imc_key.global_data_ptr->comp_select = 0;

    }
    else
    {
        g_imc_key.global_data_ptr->comp_page = 0;
        g_imc_key.global_data_ptr->comp_select = 0;
    }

    /* reset cand info */
    g_imc_key.global_data_ptr->cand_select = 0;
    g_imc_key.global_data_ptr->cand_page = 0;
    memset(g_imc_key.global_data_ptr->cand_first_index, 0, sizeof(MMI_IMC_MAX_CANDIDATE_PAGE));

    cand_cnt = mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
    mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
    mmi_imc_update_input_area(0, 0, 0, 0, g_imc_key.global_data_ptr->input_confirm_length);
    mmi_imc_redraw_screen_by_state();


    return cand_cnt;
}


#if defined(__MMI_CSTAR_PHRASE_INPUT__)
S32 mmi_imc_key_change_highlighted_composition_cstar_style(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length == 0)
        return 0;

    if (index == 0xff)
    {
        g_imc_key.global_data_ptr->comp_select = 0;
    
    } 
    else
    {
        g_imc_key.global_data_ptr->comp_select = index;
    }
    
    /* reset cand info */
    g_imc_key.global_data_ptr->cand_select = 0;
    g_imc_key.global_data_ptr->cand_page = 0;
    memset(g_imc_key.global_data_ptr->cand_first_index, 0, sizeof(MMI_IMC_MAX_CANDIDATE_PAGE));
    
    cand_cnt = mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
	if(mmi_imc_get_state() != MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID) //slanting
	{
		mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
	}
    mmi_imc_redraw_screen_by_state();


    return cand_cnt;
}

static S32 mmi_imc_key_smart_phonetic_comp_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length == 0)
        return 0;

    if (!g_imc_key.global_data_ptr->comp_first_index[g_imc_key.global_data_ptr->comp_page + 1])
    {
        g_imc_key.global_data_ptr->comp_select = g_imc_key.global_data_ptr->comp_count - 1;
    }
    else
    {
        g_imc_key.global_data_ptr->comp_page ++;
        g_imc_key.global_data_ptr->comp_select = 0;
    }
    
    /* reset cand info */
    g_imc_key.global_data_ptr->cand_select = 0;
    g_imc_key.global_data_ptr->cand_page = 0;
    memset(g_imc_key.global_data_ptr->cand_first_index, 0, sizeof(MMI_IMC_MAX_CANDIDATE_PAGE));
    
    cand_cnt = mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(!mmi_imc_is_grid_state())
	{
		mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
	}
#endif
    mmi_imc_redraw_screen_by_state();


    return cand_cnt;
}

static S32 mmi_imc_key_smart_phonetic_comp_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_cnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length == 0)
        return 0;

    if (!g_imc_key.global_data_ptr->comp_page)
    {
        g_imc_key.global_data_ptr->comp_select = 0;
    }
    else
    {
        g_imc_key.global_data_ptr->comp_page--;
        g_imc_key.global_data_ptr->comp_select = 0;
    }
    
    /* reset cand info */
    g_imc_key.global_data_ptr->cand_select = 0;
    g_imc_key.global_data_ptr->cand_page = 0;
    memset(g_imc_key.global_data_ptr->cand_first_index, 0, sizeof(MMI_IMC_MAX_CANDIDATE_PAGE));
    
    cand_cnt = mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
	if(mmi_imc_get_state() != MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID)  //slanting
	{
		mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
	}
	else
	{
		mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, (U32)g_imc_key.global_data_ptr->comp_select, 0);
	}
    mmi_imc_redraw_screen_by_state();

    return cand_cnt;
}

MMI_BOOL mmi_imc_key_smart_phonetic_candidate_select(void)
{
    return mmi_imc_key_smart_phonetic_select_candidate();
}

void mmi_imc_key_commit_input_box_content(void)
{
    if (g_imc_key.global_data_ptr->input_length)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)g_imc_key.global_data_ptr->input_buff, MMI_FALSE);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_get_composition
* DESCRIPTION
*  To get composition by current key symbol and the index
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imc_key_smart_phonetic_get_composition(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 composition_count = 0;
    mmi_ime_query_param_struct param_ptr;
    mmi_ime_query_result_struct result_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rest local variable */
    memset(&param_ptr, 0, sizeof(param_ptr));   
    memset(&result_ptr, 0, sizeof(result_ptr));

    /* initialize parameter */
    param_ptr.elembuf_ptr = g_imc_key.global_data_ptr->key_buffer;
    param_ptr.elembuf_cnt = g_imc_key.global_data_ptr->key_element_length;
    param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    result_ptr.result_buffer = g_imc_key.global_data_ptr->comp_buff;
    mmi_ime_word_get_spellings(&param_ptr, &result_ptr);    

    if (result_ptr.result_cnt)
    {
        g_imc_key.global_data_ptr->comp_select = 0;
        g_imc_key.global_data_ptr->comp_page = 0;
        composition_count = mmi_imc_update_composition_box_by_query_result(result_ptr.result_buffer, result_ptr.result_cnt, result_ptr.next_page);
    }
    return composition_count;
}


#endif

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	BOOL lcd_freeze = gdi_lcd_get_freeze();
    U16 key_buffer[MMI_IMC_MAX_KEY_BUFFER_SIZE];
    S32 key_length = 0;
    S32 key_cursor = 0;
  
    #if defined(__MMI_CSTAR_PHRASE_INPUT__)
        S32 cand_count = 0;
        S32 comp_count = 0;
    #endif
 

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            g_imc_key.global_data_ptr->key_element_length = 0;
            /* special case for inserting space for initital state */
            if (key_code == MMI_IMC_KEY_SYM_0)
            {
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    /* add space */
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                }                
                break;
            }
            mmi_imc_key_sotre_key_info((&key_buffer), key_length, key_cursor);
            if (mmi_imc_key_smart_phonetic_insert_key(key_code))
            {
#if defined(__MMI_IME_MAGIC_ONE__)
                if (mmi_ime_word_is_magic_key(g_imc_key.curr_mode, key_code)
                    && mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_SMART_LOWERCASE_ABC))
                {
                    mmi_imc_key_add_key_symbol(key_code);
                    mmi_imc_set_magic_key_down(MMI_TRUE);
				#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
                #endif
                    mmi_imc_key_magic_state_get_candidate(MMI_FALSE);
                    mmi_imc_key_change_to_magic_one_state();
                    mmi_imc_redraw_screen_by_state();                        
                }
                else
#endif
                {
                #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
                #endif
                
                #if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
                #endif
                    if (mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE))
                    {
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        mmi_imc_key_resotre_key_info(&key_buffer, key_length, key_cursor);
                    }
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT ||
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            /* cursor moving */
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
        }
        else if (key_code == MMI_IMC_KEY_CANCEL)
        {
            /* if editor is empty, execute the rsk function of ap */

            /* otherwise, clear one character */
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_key_common_clear_key_handler();    
        }
        else if (key_code == MMI_IMC_KEY_RSK)
        {

        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
        }
        break;
#if defined(__MMI_TOUCH_SCREEN__)
		case MMI_IMC_STATE_SPELL_INPUTING_GRID:
		case MMI_IMC_STATE_CAND_SELECTING_GRID:
			 if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_key_remove_symbol();
                if (g_imc_key.global_data_ptr->symb_count == 0)
                {
					mmi_imc_pen_update_display_area_by_sym_buffer();
					mmi_imc_change_state_from_grid_to_initial();
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_page = 0;
                    g_imc_key.global_data_ptr->cand_select = 0;                    
                    mmi_imc_pen_set_vk_candidate();
					mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
					mmi_imc_redraw_screen_by_state();
                 }
            }
			break;
	case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
		if (key_code == MMI_IMC_KEY_CLEAR)
		{
			mmi_imc_change_state_from_grid_to_initial();
		}
			break;
#endif
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            g_imc_key.global_data_ptr->key_element_length = 0;
            /* special case for inserting space for initital state */
            if (key_code == MMI_IMC_KEY_SYM_0)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    /* add space */
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                } 
                mmi_imc_redraw_screen_by_state();
                break;
            }
            mmi_imc_reset_input_area();
            mmi_imc_reset_key_seq_data();
            mmi_imc_key_sotre_key_info((&key_buffer), key_length, key_cursor);
            if (mmi_imc_key_smart_phonetic_insert_key(key_code))
            {
#if defined(__MMI_IME_MAGIC_ONE__)
                if (mmi_ime_word_is_magic_key(g_imc_key.curr_mode, key_code)
                    && mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_SMART_LOWERCASE_ABC))
                {
                    mmi_imc_key_add_key_symbol(key_code);
                    mmi_imc_set_magic_key_down(MMI_TRUE);
                    mmi_imc_key_magic_state_get_candidate(MMI_FALSE);
                    mmi_imc_key_change_to_magic_one_state();
                    mmi_imc_redraw_screen_by_state();                        
                }
                else
#endif
                {
                    g_imc_key.global_data_ptr->comp_page = 0;
                    g_imc_key.global_data_ptr->cand_page = 0;
                    if (mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE))
                    {
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        mmi_imc_key_resotre_key_info(&key_buffer, key_length, key_cursor);
                    }
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
            /* highlight moving */
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if (key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_RSK)
        {

        }
        break;
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
	#if defined(__MMI_IME_CANDIDATE_GRID__)
	#if defined(__MMI_CSTAR_PHRASE_INPUT__)
		case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
	#endif
	#endif
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            if (key_code == MMI_IMC_KEY_SYM_0)
            {
                if (g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor] == MMI_IMC_SYMB_KEY_0)
                {

                    g_imc_key.global_data_ptr->key_buffer_cusor ++;
                    /* update input area */
                    mmi_imc_key_smart_phonetic_update_input_area();
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_INPUT_SET_FOCUS, 0, 0);
                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                    break;
                }
                else if (g_imc_key.global_data_ptr->key_buffer_cusor && 
                    g_imc_key.global_data_ptr->key_buffer[g_imc_key.global_data_ptr->key_buffer_cusor - 1] == MMI_IMC_SYMB_KEY_0)
                {
                    return MMI_TRUE;
                }
            }
            if (!g_imc_key.global_data_ptr->key_element_length && key_code == MMI_IMC_KEY_SYM_1)
                return MMI_TRUE;
            mmi_imc_key_sotre_key_info((&key_buffer), key_length, key_cursor);
            if (mmi_imc_key_smart_phonetic_insert_key(key_code))
            {
                if (mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE))
                {
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    mmi_imc_key_resotre_key_info(&key_buffer, key_length, key_cursor);
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_COMPOSITION_SELECT)
        {
            mmi_imc_key_smart_phonetic_comp_change();
            /*g_imc_key.global_data_ptr->comp_select = 0;                
            mmi_imc_key_smart_phonetic_get_candidate(MMI_TRUE);
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
            mmi_imc_redraw_screen_by_state();*/
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_UP)
        {
            if (g_imc_key.global_data_ptr->key_element_length)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
                mmi_imc_key_smart_phonetic_update_input_area();
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_DOWN)
        {
            if (g_imc_key.global_data_ptr->key_element_length)
            {
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
                mmi_imc_key_smart_phonetic_update_input_area();
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->key_element_length)
            {
                if (g_imc_key.global_data_ptr->key_buffer_cusor == g_imc_key.global_data_ptr->key_element_length)
                {
                    mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECT_WITH_INPUT);
                    mmi_imc_key_common_arrow_key_handler(key_code, event_type);
                    mmi_imc_key_smart_phonetic_update_input_area();
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    mmi_imc_key_smart_phonetic_move_key_buffer_cursor(MMI_FALSE);
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->key_element_length)
            {
                mmi_imc_key_smart_phonetic_move_key_buffer_cursor(MMI_TRUE);
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (g_imc_key.global_data_ptr->key_buffer_cusor)
            {
                mmi_imc_key_smart_phonetic_delete_key();
                if (g_imc_key.global_data_ptr->key_element_length == 0)
                {
                    if (g_imc_key.global_data_ptr->input_confirm_length != 0)
                    {
                        mmi_imc_input_area_delete_string(1);
                        mmi_imc_key_smart_phonetic_update_input_area();
                        mmi_imc_reset_global_data();
					#if defined(__MMI_IME_CANDIDATE_GRID__)
						if(mmi_imc_is_grid_state())
						{
							mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
							mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
						}
					#endif
						mmi_imc_update_candidate_as_null();
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_WITH_INPUT);
                    }
                    else
                    {
						#if defined(__MMI_IME_CANDIDATE_GRID__)
						if(mmi_imc_is_grid_state())
						{
							mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
							mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
						}
						#endif
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    }
                }
                else
                {
                    g_imc_key.global_data_ptr->comp_page = 0;
                    g_imc_key.global_data_ptr->comp_select = 0;
                    g_imc_key.global_data_ptr->cand_page = 0;
                    g_imc_key.global_data_ptr->cand_select = 0;
                    mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE);
                }
                mmi_imc_redraw_screen_by_state();
            }
            else
            {
                /* delete the string which has been confirmed. */
                mmi_imc_key_smart_phonetic_delete_confirm_string(1);
                if (!g_imc_key.global_data_ptr->input_confirm_length && !g_imc_key.global_data_ptr->key_element_length)
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    mmi_imc_key_smart_phonetic_update_input_area();
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_INPUT_SET_FOCUS, 0, 0);
                    mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_INPUT_AREA));
                }
            }
        }
        break;
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            S32 cand_select = (key_code - MMI_IMC_KEY_CHAR_1);
            if (cand_select < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = cand_select;
				mmi_imc_gdi_lcd_freeze(TRUE);
                mmi_imc_key_smart_phonetic_select_candidate();
				mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_redraw_screen_by_state();
            }
        }

#ifdef __MMI_CSTAR_PHRASE_INPUT__
        else if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_9)
            {
                mmi_imc_set_state(MMI_IMC_STATE_SPELL_WITH_INPUT);
                mmi_imc_key_smart_phonetic_key_down_handler(key_code, event_type);
            }
#endif
        else if (key_code == MMI_IMC_KEY_COMPOSITION_SELECT)
        {
            mmi_imc_key_smart_phonetic_comp_change();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            g_imc_key.global_data_ptr->comp_select = (U8)(-1);
            g_imc_key.global_data_ptr->cand_select = 0;
            g_imc_key.global_data_ptr->comp_page = 0;
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->key_buffer_cusor = g_imc_key.global_data_ptr->key_element_length;
            mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->comp_select, 0);
            mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
            mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE);
#ifdef __MMI_CSTAR_PHRASE_INPUT__
            /* append extra backspace. last clear is only state change! */
            mmi_imc_key_smart_phonetic_key_down_handler(key_code, event_type);
#endif
            mmi_imc_redraw_screen_by_state();                
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT || 
            key_code == MMI_IMC_KEY_UP || 
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_screen_by_state();                
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            S32 cand_select = (key_code - MMI_IMC_KEY_CHAR_1);
            if (cand_select < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = cand_select;
				mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_smart_phonetic_select_candidate();
				mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_redraw_screen_by_state();
            }
        }
	#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__MMI_TOUCH_SCREEN__) /* MAUI_03162483*/
		if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_9)
			{
				S32 cand_select = (key_code - MMI_IMC_KEY_SYM_1);
				if (cand_select < g_imc_key.global_data_ptr->cand_count)
				{
					g_imc_key.global_data_ptr->cand_select = cand_select;
					mmi_imc_gdi_lcd_freeze(MMI_TRUE);
					mmi_imc_key_smart_phonetic_select_candidate();
					mmi_imc_gdi_lcd_freeze(lcd_freeze);
					mmi_imc_redraw_screen_by_state();
				}
			}
	#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_CSTAR_PHRASE_INPUT__)
        else if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            g_imc_key.global_data_ptr->key_element_length = 0;
            /* special case for inserting space for initital state */
            if (key_code == MMI_IMC_KEY_SYM_0)
            {
                 if (mmi_imm_test_input((UI_string_type)L" ", 1))
                 {
                     /* add space */
                     mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                 }                
                 break;
             }
             mmi_imc_key_sotre_key_info((&key_buffer), key_length, key_cursor);
             if (mmi_imc_key_smart_phonetic_insert_key(key_code))
             {
#if defined(__MMI_IME_MAGIC_ONE__)
                 if (mmi_ime_word_is_magic_key(g_imc_key.curr_mode, key_code)
				    && mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_SMART_LOWERCASE_ABC))
                 {
                     mmi_imc_key_add_key_symbol(key_code);
                     mmi_imc_set_magic_key_down(MMI_TRUE);
                     mmi_imc_key_magic_state_get_candidate(MMI_FALSE);
                     mmi_imc_key_change_to_magic_one_state();
                     mmi_imc_redraw_screen_by_state();                        
                 }
                 else
#endif
                 {
                     if (mmi_imc_key_smart_phonetic_get_candidate(MMI_FALSE))
                     {
                         mmi_imc_redraw_screen_by_state();
                     }
                     else
                     {
                         mmi_imc_key_resotre_key_info(&key_buffer, key_length, key_cursor);
                     }
                 }
              }
        }
#endif 
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {

            #if defined (__MMI_CSTAR_PHRASE_INPUT__)   
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            #else
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.global_data_ptr->cand_select = 0;
                mmi_imc_change_candidate_box_page();
                mmi_imc_set_state(MMI_IMC_STATE_PRE_ASSOC_SELECTING);
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            #endif
            
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT || 
            key_code == MMI_IMC_KEY_UP || 
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_screen_by_state();                
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

        
#if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_CSTAR_PHRASE_INPUT__)   
                case MMI_IMC_STATE_VK_CAND:
                    if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
                    {
                        U8 symb_count;
                        UI_character_type comp_buff[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
                        U16 symb_buff[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
                        U16 key_buffer[MMI_IMC_MAX_KEY_BUFFER_SIZE];
                        S32 key_element_length;
                        U8 comp_select, comp_page;
        
        
                        symb_count = g_imc_key.global_data_ptr->symb_count;
                        key_element_length = g_imc_key.global_data_ptr->key_element_length;    
                        comp_select = g_imc_key.global_data_ptr->comp_select;
                        comp_page = g_imc_key.global_data_ptr->comp_page;
                        memcpy(comp_buff, &g_imc_key.global_data_ptr->comp_buff[0], sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                        memcpy(symb_buff, &g_imc_key.global_data_ptr->symb_buff[0], sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                        memcpy(key_buffer, &g_imc_key.global_data_ptr->key_buffer[0], sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);
        
                        /* reset all data and start a new input */
                        g_imc_key.global_data_ptr->key_element_length = 0;
        
                        g_imc_key.global_data_ptr->symb_count = 0;
                        /* clear vk display area */
                        mmi_imc_pen_update_display_area_by_sym_buffer();
                        if (mmi_imc_key_add_key_element(key_code))
                        {
                            mmi_imc_ui_style_param_struct bkup_ui_param;
        
                            mmi_imc_get_ui_style_param(&bkup_ui_param);
        
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                            comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                            if (comp_count)
                            {
                                /* get candidate */
                                cand_count = mmi_imc_change_highlighted_composition_from_composition_box(0);
                                mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                                mmi_imc_redraw_screen_by_state();
                            }
                            else
                            {
                                g_imc_key.global_data_ptr->symb_count = symb_count;
                                g_imc_key.global_data_ptr->key_element_length = key_element_length;    
                                g_imc_key.global_data_ptr->comp_select = comp_select;
                                g_imc_key.global_data_ptr->comp_page = comp_page;
                                memcpy(&g_imc_key.global_data_ptr->comp_buff[0], comp_buff, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                                memcpy(&g_imc_key.global_data_ptr->symb_buff[0], symb_buff, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                                memcpy(&g_imc_key.global_data_ptr->key_buffer[0], key_buffer, sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);
        
                                mmi_imc_set_ui_style_param(&bkup_ui_param);
        
                                mmi_imc_pen_update_display_area_by_sym_buffer();
                            }
                        }
                        else
                        {
                            g_imc_key.global_data_ptr->symb_count = symb_count;
                            g_imc_key.global_data_ptr->key_element_length = key_element_length;   
                            g_imc_key.global_data_ptr->comp_select = comp_select;
                            g_imc_key.global_data_ptr->comp_page = comp_page;
                            memcpy(&g_imc_key.global_data_ptr->comp_buff[0], comp_buff, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                            memcpy(&g_imc_key.global_data_ptr->symb_buff[0], symb_buff, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                            memcpy(&g_imc_key.global_data_ptr->key_buffer[0], key_buffer, sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);
                        }
                    }
                    else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
                    {
                        mmi_imc_key_handle_mode_change_key();
                    }
                    else if (key_code == MMI_IMC_KEY_RIGHT || 
                        key_code == MMI_IMC_KEY_LEFT ||
                        key_code == MMI_IMC_KEY_UP ||
                        key_code == MMI_IMC_KEY_DOWN)
                    {
                        mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                        mmi_imc_redraw_screen_by_state();
                    }
                    else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
                    {
                        mmi_imc_key_entry_symbol_picker();
                        return MMI_TRUE;
                    }
                    else if (key_code == MMI_IMC_KEY_CLEAR)
                    {
                        mmi_imc_key_remove_symbol();
                        if (g_imc_key.global_data_ptr->symb_count == 0)
                        {
                            mmi_imc_pen_update_display_area_by_sym_buffer();
                            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        }
                        else
                        {
                            g_imc_key.global_data_ptr->cand_page = 0;
                            g_imc_key.global_data_ptr->cand_select = 0;                    
                            mmi_imc_pen_set_vk_candidate();
                        }
                        mmi_imc_redraw_screen_by_state();
                    }
                    break;
#endif


    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
    #if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
    case MMI_IMC_KEY_CLEAR:
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        break;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    case MMI_IMC_KEY_CHANGE_LANGUAGE:
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        break;
#endif
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze(); //FTE2.0

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_code == MMI_IMC_KEY_CHANGE_MODE)
    {
        mmi_imc_key_handle_mode_change_key();
        return MMI_TRUE;
    }

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
			mmi_imc_gdi_lcd_freeze(MMI_TRUE); //FTE2.0 MAUI_03124885
            mmi_imc_key_smart_phonetic_select_candidate();
			mmi_imc_gdi_lcd_freeze(lcd_freeze); //FTE2.0
            mmi_imc_redraw_screen_by_state();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

    #if defined(__MMI_VIRTUAL_KEYBOARD__) && defined(__MMI_CSTAR_PHRASE_INPUT__)  
    case MMI_IMC_STATE_VK_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                mmi_imc_pen_update_display_area_by_sym_buffer();
                mmi_imc_redraw_screen_by_state();
            }
			else if (g_imc_key.global_data_ptr->comp_count)
			{
				mmi_imc_key_insert_comp();
			}
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif
    

    }

    return MMI_TRUE;
}

#else

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_get_composition
* DESCRIPTION
*  To get composition by current key symbol and the index
* PARAMETERS
* RETURNS
*****************************************************************************/
S32 mmi_imc_key_smart_phonetic_get_composition(S32 index)
{
#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 composition_count = 0;
    mmi_ime_query_param_struct param_ptr;
    mmi_ime_query_result_struct result_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rest local variable */
    memset(&param_ptr, 0, sizeof(param_ptr));   
    memset(&result_ptr, 0, sizeof(result_ptr));

    /* initialize parameter */
    param_ptr.elembuf_ptr = g_imc_key.global_data_ptr->key_buffer;
    param_ptr.elembuf_cnt = g_imc_key.global_data_ptr->key_element_length;
    param_ptr.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;
    result_ptr.result_buffer = g_imc_key.global_data_ptr->comp_buff;
    mmi_ime_word_get_spellings(&param_ptr, &result_ptr);    

    if (result_ptr.result_cnt)
    {
        g_imc_key.global_data_ptr->comp_select = 0;
        g_imc_key.global_data_ptr->comp_page = 0;
        composition_count = mmi_imc_update_composition_box_by_query_result(result_ptr.result_buffer, result_ptr.result_cnt, result_ptr.next_page);
    }
    return composition_count;
#endif //#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 comp_count = 0;
    U16 tone_mark;
    mmi_imm_input_mode_enum old_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    switch(mmi_imc_get_state())
    {
#if defined(__MMI_TOUCH_SCREEN__)
        case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
            {
                /* for arrow key, do nothing. */
                return MMI_TRUE;
            }

            if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }

            old_mode = mmi_imm_get_curr_input_mode();

            mmi_imc_pen_confirm_handwriting_selection(); /* no break */

            /* In canceling timer, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                return MMI_TRUE;
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            break;
#endif
        case MMI_IMC_STATE_INITIAL:
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
            {
                g_imc_key.global_data_ptr->key_element_length = 0;
                if (mmi_imc_key_add_key_element(key_code))
                {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the key */
                        mmi_imc_key_delete_key_element();
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_LSK)
            {
                g_imc_key_inputbox_LSK_function();
            }
            else if (key_code == MMI_IMC_KEY_RIGHT ||
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                /* cursor moving */
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            }
            else if (key_code == MMI_IMC_KEY_CANCEL)
            {
                /* if editor is empty, execute the rsk function of ap */

                /* otherwise, clear one character */
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_key_common_clear_key_handler();    
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
            break;
#if defined(__MMI_IME_CANDIDATE_GRID__) && defined(__MMI_TOUCH_SCREEN__)
		case MMI_IMC_STATE_SPELL_INPUTING_GRID:
		case MMI_IMC_STATE_CAND_SELECTING_GRID:
			 if (key_code == MMI_IMC_KEY_CLEAR)
            {
				if(mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY)
				{
					 mmi_imc_key_remove_symbol();
					if (g_imc_key.global_data_ptr->symb_count == 0)
					{
						mmi_imc_pen_update_display_area_by_sym_buffer();
						mmi_imc_change_state_from_grid_to_initial();
					}
					else
					{
						g_imc_key.global_data_ptr->cand_page = 0;
						g_imc_key.global_data_ptr->cand_select = 0;                    
						mmi_imc_pen_set_vk_candidate();
						mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
						mmi_imc_redraw_screen_by_state();
					}
				}
				else
				{
                if (mmi_imc_key_delete_key_element())
                {
                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                    g_imc_key.global_data_ptr->comp_page = 0;
                    g_imc_key.global_data_ptr->comp_select = 0;
                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING_GRID);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        g_imc_key.global_data_ptr->symb_count = 0;
						mmi_imc_change_state_from_grid_to_initial();                   
                    }

                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
            }
            }
            break;
		case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
		case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
		case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
		#if defined(__MMI_CSTAR_PHRASE_INPUT__)
		case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
		#endif
			 if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_key_common_clear_key_handler();    
            }
			break;
		#endif
        case MMI_IMC_STATE_CAND_SELECTING:
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
            {
#if !defined(__MMI_IME_TONE_IN_STAR_KEY__)
                /* if no tone has been added, add tone mark into symbol buffer */
                tone_mark = ((key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_TONE_BASE);
                if ( tone_mark >= MMI_IMC_SYMB_TONE_1 && tone_mark < MMI_IMC_SYMB_TONE_MAX && g_imc_key.global_data_ptr->tone == MMI_IMC_SYMB_TONE_NONE)
                {
                    if (mmi_imc_key_phonetic_key_query_candidate_with_tone(tone_mark))
                    {
                        g_imc_key.global_data_ptr->tone = tone_mark;
                        mmi_imc_redraw_screen_by_state();
                    }
                }
#endif
            }
            else if (key_code == MMI_IMC_KEY_LSK)
            {
                /*  */
            }
            else if (key_code == MMI_IMC_KEY_UP)
            {
                if (!g_imc_key.global_data_ptr->cand_page && !g_imc_key.global_data_ptr->cand_select && g_imc_key.global_data_ptr->tone == MMI_IMC_SYMB_TONE_NONE)
                {
                    /* back to spell input state and restore the status. */
                    mmi_imc_key_smart_phonetic_get_composition(0);
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    g_imc_key.global_data_ptr->comp_page = g_imc_key.global_data_ptr->old_comp_page;
                    mmi_imc_change_composition_box_page();
                    /* get candidate */
                    g_imc_key.global_data_ptr->comp_select = g_imc_key.global_data_ptr->old_comp_select;
                    mmi_imc_change_highlighted_composition_from_composition_box(0);
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->comp_select, 0);
                    mmi_imc_redraw_screen_by_state();

                }
                else
                {
                    mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                    mmi_imc_redraw_screen_by_state();                
                }
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                if (g_imc_key.global_data_ptr->tone != MMI_IMC_SYMB_TONE_NONE)
                {
                    g_imc_key.global_data_ptr->tone = MMI_IMC_SYMB_TONE_NONE;
                    mmi_imc_key_phonetic_key_query_candidate_with_tone(MMI_IMC_SYMB_TONE_NONE);
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    /* back to spell input state and restore the status. */
                    mmi_imc_key_smart_phonetic_get_composition(0);
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    g_imc_key.global_data_ptr->comp_page = g_imc_key.global_data_ptr->old_comp_page;
                    mmi_imc_change_composition_box_page();
                    /* get candidate */
                    g_imc_key.global_data_ptr->comp_select = g_imc_key.global_data_ptr->old_comp_select;
                    mmi_imc_change_highlighted_composition_from_composition_box(0);
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->comp_select, 0);
                    mmi_imc_redraw_screen_by_state();
                }
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
            else if (key_code == MMI_IMC_KEY_TONE_CHANGE)
            {
                S32 i;
                tone_mark = g_imc_key.global_data_ptr->tone;
                for (i = 0; i < 5; i ++)
                {
                    tone_mark = ((tone_mark+ 1) - MMI_IMC_SYMB_TONE_1) % 5 + MMI_IMC_SYMB_TONE_1;
                    if (mmi_imc_key_phonetic_key_query_candidate_with_tone(tone_mark))
                    {
                        g_imc_key.global_data_ptr->tone = tone_mark;
                        mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_COMPOSITION_AREA) | MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
                        break;
                    }
                }
            }
#endif
            break;
        case MMI_IMC_STATE_SPELL_INPUTING:
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
            {
                if (mmi_imc_key_add_key_element(key_code))
                {
                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the key */
                        mmi_imc_key_delete_key_element();
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_select_composition_from_composition_box();
                mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                if (mmi_imc_key_delete_key_element())
                {
                    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

                    g_imc_key.global_data_ptr->comp_page = 0;
                    g_imc_key.global_data_ptr->comp_select = 0;
                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        g_imc_key.global_data_ptr->symb_count = 0;
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();                    
                    }

                    mmi_imc_gdi_lcd_freeze(lcd_freeze);
                    mmi_imc_repaint_screen();
                }
            }
            break;
        case MMI_IMC_STATE_ASSOC_SELECTING:
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
            {
                /* reset all data and start a new input */
                g_imc_key.global_data_ptr->key_element_length = 0;

                mmi_imc_reset_global_data();

                if (mmi_imc_key_add_key_element(key_code))
                {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the key */
                        mmi_imc_key_delete_key_element();
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();                
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }            
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                    mmi_imc_redraw_screen_by_state();
                }
            }
            break;
#if defined(__MMI_VIRTUAL_KEYBOARD__) 
        case MMI_IMC_STATE_VK_CAND:
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
            {
                U8 symb_count;
                UI_character_type comp_buff[MMI_IMC_MAX_COMPOSITION_BUFFSIZE];
                U16 symb_buff[MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE];
                U16 key_buffer[MMI_IMC_MAX_KEY_BUFFER_SIZE];
                S32 key_element_length;
                U8 comp_select, comp_page;


                symb_count = g_imc_key.global_data_ptr->symb_count;
                key_element_length = g_imc_key.global_data_ptr->key_element_length;    
                comp_select = g_imc_key.global_data_ptr->comp_select;
                comp_page = g_imc_key.global_data_ptr->comp_page;
                memcpy(comp_buff, &g_imc_key.global_data_ptr->comp_buff[0], sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                memcpy(symb_buff, &g_imc_key.global_data_ptr->symb_buff[0], sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                memcpy(key_buffer, &g_imc_key.global_data_ptr->key_buffer[0], sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);

                /* reset all data and start a new input */
                g_imc_key.global_data_ptr->key_element_length = 0;

                g_imc_key.global_data_ptr->symb_count = 0;
                /* clear vk display area */
                mmi_imc_pen_update_display_area_by_sym_buffer();
                if (mmi_imc_key_add_key_element(key_code))
                {
                    mmi_imc_ui_style_param_struct bkup_ui_param;

                    mmi_imc_get_ui_style_param(&bkup_ui_param);

#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        g_imc_key.global_data_ptr->symb_count = symb_count;
                        g_imc_key.global_data_ptr->key_element_length = key_element_length;    
                        g_imc_key.global_data_ptr->comp_select = comp_select;
                        g_imc_key.global_data_ptr->comp_page = comp_page;
                        memcpy(&g_imc_key.global_data_ptr->comp_buff[0], comp_buff, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                        memcpy(&g_imc_key.global_data_ptr->symb_buff[0], symb_buff, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                        memcpy(&g_imc_key.global_data_ptr->key_buffer[0], key_buffer, sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);

                        mmi_imc_set_ui_style_param(&bkup_ui_param);

                        mmi_imc_pen_update_display_area_by_sym_buffer();
                    }
                }
                else
                {
                    g_imc_key.global_data_ptr->symb_count = symb_count;
                    g_imc_key.global_data_ptr->key_element_length = key_element_length;   
                    g_imc_key.global_data_ptr->comp_select = comp_select;
                    g_imc_key.global_data_ptr->comp_page = comp_page;
                    memcpy(&g_imc_key.global_data_ptr->comp_buff[0], comp_buff, sizeof(UI_character_type)*MMI_IMC_MAX_COMPOSITION_BUFFSIZE);
                    memcpy(&g_imc_key.global_data_ptr->symb_buff[0], symb_buff, sizeof(U16)*MMI_IMC_MAX_INPUT_SYMBOL_BUFFSIZE);
                    memcpy(&g_imc_key.global_data_ptr->key_buffer[0], key_buffer, sizeof(U16)*MMI_IMC_MAX_KEY_BUFFER_SIZE);
                }
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_key_remove_symbol();
                if (g_imc_key.global_data_ptr->symb_count == 0)
                {
                    mmi_imc_pen_update_display_area_by_sym_buffer();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
                else
                {
                    g_imc_key.global_data_ptr->cand_page = 0;
                    g_imc_key.global_data_ptr->cand_select = 0;                    
                    mmi_imc_pen_set_vk_candidate();
                }
                mmi_imc_redraw_screen_by_state();
            }
            break;
#endif

    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
    #if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        break;
    case MMI_IMC_KEY_SWITCH_BETWEEN_SMART_AND_MULTITAP:
        mmi_imc_key_switch_between_smart_and_multitap();
        break;
    case MMI_IMC_KEY_CLEAR:
	#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_is_grid_state())
		{
			//show vk, as no more symbol left
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
			mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
		}
	#endif
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        break;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    case MMI_IMC_KEY_CHANGE_LANGUAGE:
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        break;
#endif
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_smart_phonetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_smart_phonetic_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     BOOL lcd_freeze = gdi_lcd_get_freeze();
     mmi_ime_query_param_struct query_param;
    mmi_ime_query_result_struct query_result;
     S32 comp_count = 0,cand_count=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_ASSOC_SELECTING:
#if defined(__MMI_TOUCH_SCREEN__)
    case MMI_IMC_STATE_HAND_WRITING_CAND:
#endif
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_select_composition_from_composition_box();
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            mmi_imc_redraw_screen_by_state();

        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        #if defined(__MMI_GUOBI__)
        if(key_code==MMI_IMC_KEY_SEEMLESS_SWITCH)
        {
             query_result.result_buffer = g_imc_key.global_data_ptr->cand_buff;
        mmi_ime_word_get_seamless_switch_candidate(&query_param,&query_result);
        if(g_imc_key.global_data_ptr->cand_buff[0])
        {
          mmi_imc_select_composition_from_composition_box();
        mmi_imc_update_candidate_box_by_query_result(query_result.result_buffer, query_result.result_cnt, query_result.next_page);
        mmi_imc_redraw_screen_by_state();
        
        }
        else
        {
               #if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif

                    comp_count = mmi_imc_key_smart_phonetic_get_composition(0);
                    if (comp_count)
                    {
                        /* get candidate */
                        cand_count = mmi_imc_change_highlighted_composition_from_composition_box(0);
                        mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                        mmi_imc_redraw_screen_by_state();
                    }
        }
        }
        #endif
        break;
#if defined(__MMI_VIRTUAL_KEYBOARD__)
    case MMI_IMC_STATE_VK_CAND:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (g_imc_key.global_data_ptr->cand_count)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_FALSE, 0);
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CONFIG_EDITOR_SHOW, MMI_TRUE, 0);
                mmi_imc_pen_update_display_area_by_sym_buffer();
                mmi_imc_redraw_screen_by_state();
            }
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
#endif
    }

    return MMI_TRUE;
#endif //#if defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_get_code_by_key
* DESCRIPTION
*  to get stroke UCS2 code by key input.
* PARAMETERS
*  
* RETURNS
*  U16  if the key sequence if valid, return UCS2 code, else return 0.
*****************************************************************************/
static U16 mmi_imc_key_stroke_get_code_by_key(U8 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct query_param;
    mmi_ime_query_result_struct result_param;
    U16 key_buff[MMI_IMC_MAX_KEY_BUFFER_SIZE];
    UI_character_type stroke_char_buff[MMI_IMC_MAX_KEY_BUFFER_SIZE];
    mmi_imc_symbol_key_enum key_sym = (mmi_imc_symbol_key_enum)((key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query_param, 0, sizeof(query_param));
    memset(&result_param, 0, sizeof(result_param));
    memset(key_buff, 0, MMI_IMC_MAX_KEY_BUFFER_SIZE* sizeof(U8));
    memset(stroke_char_buff, 0, MMI_IMC_MAX_KEY_BUFFER_SIZE*sizeof(UI_character_type));

    key_buff[0] = key_sym;
    /* get word engine query symbol */
    /* transfer key symbol to unicode */
    query_param.elembuf_ptr = key_buff;
    query_param.elembuf_cnt = 1;
    result_param.result_buffer = stroke_char_buff;
    mmi_ime_word_get_spellings(&query_param, &result_param);    


    if (!result_param.result_cnt)
        return 0;

    return stroke_char_buff[0];
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_get_sym_by_key
* DESCRIPTION
*  to get word engine query symbol by key input.
* PARAMETERS
*  
* RETURNS
*  U16  if the key sequence if valid, return stroke symbol, else return 0.
*****************************************************************************/
static U16 mmi_imc_key_stroke_get_sym_by_key(U8 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type stroke_char = 0;
    U16 stroke_sym = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stroke_char = mmi_imc_key_stroke_get_code_by_key(key_code);   

    if (stroke_char)
    {
        stroke_sym = mmi_ime_word_code_to_symbol(stroke_char);
    }

    return stroke_sym;

}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_get_candidate
* DESCRIPTION
*  to get candidate by symbol buffer. if the stroke composition is valid, update composition area.
* PARAMETERS
*  
* RETURNS
*  MMI_BOOL  if the key sequence if valid, return MMI_TRUE, else return MMI_FALSE.
*****************************************************************************/
 S32 mmi_imc_key_stroke_get_candidate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_query_param_struct query_param = {0};
    mmi_ime_query_result_struct result_param = {0};    
    S32 cand_count = 0;
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query_param, 0, sizeof(query_param));
    memset(&result_param, 0, sizeof(result_param));

    /* get candidate by symbol buffer. */
    query_param.elembuf_ptr = g_imc_key.global_data_ptr->symb_buff;
    query_param.elembuf_cnt = g_imc_key.global_data_ptr->symb_count;
    query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_CHINESE;

    query_param.tone_value = MMI_IMC_SYMB_TONE_NONE;
    query_param.first_index = 0;

    result_param.result_buffer = g_imc_key.global_data_ptr->cand_buff;

#if defined(__MMI_IME_CANDIDATE_GRID__)
	if(mmi_imc_is_grid_state())
	{
        query_param.desired_cnt = MMI_IMC_MAX_CANDIDATE_IN_ONE_PAGE_GRID;
		mmi_imc_get_candidates_from_word_engine(&query_param, &result_param);
	}
	else
	{
		mmi_ime_word_get_candidates(&query_param, &result_param);
	}
#else
    mmi_ime_word_get_candidates(&query_param, &result_param);
#endif

    if (result_param.result_cnt)
    {
        /* reset global data */
        g_imc_key.global_data_ptr->cand_page = 0;
        g_imc_key.global_data_ptr->cand_select = 0;
        cand_count = mmi_imc_update_candidate_box_by_query_result(
            result_param.result_buffer, 
            result_param.result_cnt, 
            result_param.next_page);
#if defined(__MMI_IME_CANDIDATE_BOX_STYLE_FOCUS_ON_CENTER__)
        g_imc_key.global_data_ptr->cand_select = (cand_count- 1) / 2;
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
#endif

        /* fill composition buffer */
        for (i = 0; i < g_imc_key.global_data_ptr->symb_count; i ++)
        {
            g_imc_key.global_data_ptr->comp_buff[i] = mmi_ime_word_symbol_to_code(g_imc_key.global_data_ptr->symb_buff[i]);
        }
        g_imc_key.global_data_ptr->comp_buff[i] = '\0';
        g_imc_key.global_data_ptr->comp_count = 1;

        /* update composition area */
        mmi_imc_update_composition_box_by_query_result_ext(
            g_imc_key.global_data_ptr->comp_buff, 
            1, 
            MMI_FALSE,
            MMI_TRUE);

    }

    return cand_count;
}


#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__) && !defined(__MMI_CSTAR_PHRASE_INPUT__)

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_first_symbol
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_key_stroke_first_symbol( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key.global_data_ptr->key_element_length = 0;
    g_imc_key.global_data_ptr->symb_count = 0;
#if defined(__MMI_IME_MAGIC_ONE__)
    if (mmi_ime_word_is_magic_key(g_imc_key.curr_mode, key_code)
        && mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_SMART_LOWERCASE_ABC))
    {                    
        mmi_imc_key_add_key_element(key_code);
        mmi_imc_set_magic_key_down(MMI_TRUE);
        #if defined(__MMI_IME_FLOATING_CAND_BOX__)
			mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
		#endif
        mmi_imc_key_magic_state_get_candidate(MMI_FALSE);
        mmi_imc_key_change_to_magic_one_state();
        mmi_imc_redraw_screen_by_state();
        cand_count = g_imc_key.global_data_ptr->cand_count;
    }
    else
#endif
    {
        if (mmi_imc_key_add_symbol(mmi_imc_key_stroke_get_sym_by_key((U8)key_code)))
        {
            {
			#if defined(__MMI_IME_FLOATING_CAND_BOX__)
				mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
			#endif
                cand_count = mmi_imc_key_stroke_get_candidate();
                if (cand_count)
                {
                    mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    /* invalid input, remove the key */
                    mmi_imc_key_delete_key_element();
                }
            }
        }
        else
        {

        }
    }
    return cand_count;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_stroke_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_STROKE_INPUT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    S32 index = 0;
	BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            mmi_imc_key_stroke_first_symbol(key_code, event_type );
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            g_imc_key_inputbox_LSK_function();
        }
        else if (key_code == MMI_IMC_KEY_RIGHT ||
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            /* cursor moving */
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
        }
        else if (key_code == MMI_IMC_KEY_CANCEL)
        {
            /* if editor is empty, execute the rsk function of ap */

            /* otherwise, clear one character */
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_key_common_clear_key_handler();
        }

        break;
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            if (mmi_imc_key_add_symbol(mmi_imc_key_stroke_get_sym_by_key((U8)key_code)))
            {
                cand_count = mmi_imc_key_stroke_get_candidate();
                if (cand_count)
                {
                    mmi_imc_redraw_screen_by_state();
                }
                else
                {
                    /* invalid input, remove the symbol */
                    mmi_imc_key_remove_symbol();
                }
            }
            else
            {

            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            /*  */
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            /* for key up, no action */
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            if (key_code == MMI_IMC_KEY_RIGHT)
            {
                /* move highlight only for key right */
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);    
            }
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_CANCEL)
        {
            /* if editor is empty, execute the rsk function of ap */

            /* otherwise, clear one character */
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (mmi_imc_key_remove_symbol())
            {
                if (g_imc_key.global_data_ptr->symb_count == 0)
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();                        
                }
                else
                {
                    cand_count = mmi_imc_key_stroke_get_candidate();
                    if (cand_count)
                    {
                        mmi_imc_redraw_screen_by_state();
                    }
                    else 
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();                        
                    }
                }
            }

        }
        break;
    case MMI_IMC_STATE_CAND_SELECTING:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            index = key_code - MMI_IMC_KEY_CHAR_1;
            if (index < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = index;
				mmi_imc_gdi_lcd_freeze(TRUE);
                mmi_imc_select_candidate_from_candidate_box();
				mmi_imc_gdi_lcd_freeze(gdi_freeze);
                mmi_imc_redraw_screen_by_state();
            }
        }
        else if (key_code == MMI_IMC_KEY_LSK)
        {
            /*  */
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_CANCEL)
        {
            /* if editor is empty, execute the rsk function of ap */

            /* otherwise, clear one character */
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            /* set candidate back to the first page and the first candidate */
            g_imc_key.global_data_ptr->cand_page = 0;
            g_imc_key.global_data_ptr->cand_select = 0;
            mmi_imc_change_candidate_box_page();
            mmi_imc_set_state(MMI_IMC_STATE_SPELL_INPUTING);
            mmi_imc_redraw_screen_by_state();
        }
        break;
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
        {
            mmi_imc_key_stroke_first_symbol(key_code, event_type );
        }
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_set_state(MMI_IMC_STATE_ASSOC_SELECTING);
            if (key_code == MMI_IMC_KEY_RIGHT)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);    
            }
            mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();                
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)0x20, 0);
                mmi_imc_redraw_screen_by_state();
            }
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (key_code >= MMI_IMC_KEY_CHAR_1 && key_code <= MMI_IMC_KEY_CHAR_9)
        {
            index = key_code - MMI_IMC_KEY_CHAR_1;
            if (index < g_imc_key.global_data_ptr->cand_count)
            {
                g_imc_key.global_data_ptr->cand_select = index;
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_redraw_screen_by_state();
            }
        }
	#if defined(__MMI_IME_FTE_ENHANCE__) && !defined(__MMI_TOUCH_SCREEN__)
		if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_9)
			{
				S32 cand_select = (key_code - MMI_IMC_KEY_SYM_1);
				if (cand_select < g_imc_key.global_data_ptr->cand_count)
				{
					g_imc_key.global_data_ptr->cand_select = cand_select;
					mmi_imc_gdi_lcd_freeze(MMI_TRUE);
					mmi_imc_key_smart_phonetic_select_candidate();
					mmi_imc_gdi_lcd_freeze(gdi_freeze);
					mmi_imc_redraw_screen_by_state();
				}
			}
	#endif

#ifdef __MMI_CSTAR_PHRASE_INPUT__
        else if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)            
        {
            mmi_imc_key_stroke_first_symbol(key_code, event_type);            
        }
#endif
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {

          #if defined (__MMI_CSTAR_PHRASE_INPUT__)   
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            #else
                g_imc_key.global_data_ptr->cand_page = 0;
                g_imc_key.global_data_ptr->cand_select = 0;
                mmi_imc_change_candidate_box_page();
                mmi_imc_set_state(MMI_IMC_STATE_PRE_ASSOC_SELECTING);
                mmi_imc_redraw_imui(MMI_IMUI_CONTROL_MASK(MMI_IMUI_CANDIDATE_AREA));
            #endif

        }
        break;
    case MMI_IMC_STATE_VK_CAND:
        break;
    }

    return MMI_TRUE;
#endif //#if  defined(__MMI_IME_STROKE_INPUT__)
}

#else
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_stroke_key_down_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_STROKE_INPUT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cand_count = 0;
    mmi_imm_input_mode_enum old_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(mmi_imc_get_state())
    {
		
#if defined(__MMI_TOUCH_SCREEN__)
#if defined(__MMI_IME_CANDIDATE_GRID__)	
		case MMI_IMC_STATE_CAND_SELECTING_GRID:
			 if (mmi_imc_key_remove_symbol())
                {
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
						mmi_imc_change_state_from_grid_to_initial();                        
                    }
                    else
                    {
                        cand_count = mmi_imc_key_stroke_get_candidate();
                        if (cand_count)
                        {
                            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING_GRID);
                            mmi_imc_redraw_screen_by_state();
                        }
                        else 
                        {
							mmi_imc_change_state_from_grid_to_initial();                       
                        }
                    }
                }
			 
			break;
		case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
		if (key_code == MMI_IMC_KEY_CLEAR)
		{
			mmi_imc_change_state_from_grid_to_initial();
		}
			break;
#endif
        case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_pen_confirm_handwriting_selection();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                return MMI_TRUE;
            }
            if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
            {
                /* for arrow key, do nothing. */
                return MMI_TRUE;
            }
            if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
                return MMI_TRUE;
            }

            old_mode = mmi_imm_get_curr_input_mode();

            mmi_imc_pen_confirm_handwriting_selection(); /* no break */

            /* In canceling timer, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                return MMI_TRUE;
            }

            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
            break;
#endif
        case MMI_IMC_STATE_INITIAL:
#if defined __MMI_XT9__
            if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_6)
#else
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
#endif
            {
                g_imc_key.global_data_ptr->key_element_length = 0;
                g_imc_key.global_data_ptr->symb_count = 0;
                if (mmi_imc_key_add_symbol(mmi_imc_key_stroke_get_sym_by_key((U8)key_code)))
                {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                    cand_count = mmi_imc_key_stroke_get_candidate();
                    if (cand_count)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the key */
                        mmi_imc_key_remove_symbol();
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_LSK)
            {
                g_imc_key_inputbox_LSK_function();
            }
            else if (key_code == MMI_IMC_KEY_RIGHT ||
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                /* cursor moving */
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            }
            else if (key_code == MMI_IMC_KEY_CANCEL)
            {
                /* if editor is empty, execute the rsk function of ap */

                /* otherwise, clear one character */
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_SET_KEY, 0, 0);
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_key_common_clear_key_handler();
            }
            break;
        case MMI_IMC_STATE_CAND_SELECTING:
#if defined __MMI_XT9__
            if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_6)
#else
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
#endif
            {
                if (mmi_imc_key_add_symbol(mmi_imc_key_stroke_get_sym_by_key((U8)key_code)))
                {
                    cand_count = mmi_imc_key_stroke_get_candidate();
                    if (cand_count)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the symbol */
                        mmi_imc_key_remove_symbol();
                        /*the below api is to make sure the list is generated with (count-1) */
#if defined __MMI_XT9__
                        mmi_imc_key_stroke_get_candidate();
#endif
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_LSK)
            {
                /*  */
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CANCEL)
            {
                /* if editor is empty, execute the rsk function of ap */

                /* otherwise, clear one character */
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
                return MMI_TRUE;
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                if (mmi_imc_key_remove_symbol())
                {
                    if (g_imc_key.global_data_ptr->symb_count == 0)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();                        
                    }
                    else
                    {
                        cand_count = mmi_imc_key_stroke_get_candidate();
                        if (cand_count)
                        {
                            mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                            mmi_imc_redraw_screen_by_state();
                        }
                        else 
                        {
                            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                            mmi_imc_redraw_screen_by_state();                        
                        }
                    }
                }
            }
            else if (key_code == MMI_IMC_KEY_RSK)
            {

            }
            break;
        case MMI_IMC_STATE_ASSOC_SELECTING:
#if defined __MMI_XT9__
            if (key_code >= MMI_IMC_KEY_SYM_1 && key_code <= MMI_IMC_KEY_SYM_6)
#else
            if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
#endif
            {
                if (mmi_imc_key_add_symbol(mmi_imc_key_stroke_get_sym_by_key((U8)key_code)))
                {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#endif
                    cand_count = mmi_imc_key_stroke_get_candidate();
                    if (cand_count)
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING);
                        mmi_imc_redraw_screen_by_state();
                    }
                    else
                    {
                        /* invalid input, remove the symbol */
                        mmi_imc_key_remove_symbol();
                    }
                }
                else
                {

                }
            }
            else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
            }
            else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
            {
                mmi_imc_key_handle_mode_change_key();
            }
            else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
            {
                mmi_imc_key_entry_symbol_picker();
            }
            else if (key_code == MMI_IMC_KEY_CLEAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();                
            }
            else if (key_code == MMI_IMC_KEY_SPACE)
            {
                if (mmi_imm_test_input((UI_string_type)L" ", 1))
                {
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                    mmi_imc_redraw_screen_by_state();
                }
            }
            break;
        case MMI_IMC_STATE_VK_CAND:
            break;
    }

#endif // defined(__MMI_IME_STROKE_INPUT__)
	return MMI_TRUE;
}

#endif


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_stroke_key_up_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_STROKE_INPUT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_PRE_ASSOC_SELECTING:
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_ASSOC_SELECTING:
    case MMI_IMC_STATE_HAND_WRITING_CAND:
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);
            mmi_imc_select_candidate_from_candidate_box();
            mmi_imc_redraw_screen_by_state();
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }

        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;

    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        break;
    }

#endif //#if  defined(__MMI_IME_STROKE_INPUT__)
	return MMI_TRUE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_stroke_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_stroke_key_long_press_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
#if defined(__MMI_IME_STROKE_INPUT__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_code)
    {
    case MMI_IMC_KEY_SYMBOL_PICKER:
        mmi_imc_key_entry_symbol_picker();
        break;
    case MMI_IMC_KEY_CHANGE_MODE:
    #if defined(__MMI_IME_V3__)
		mmi_imc_show_inputmode_list();
	#else 
        mmi_imc_key_change_input_mode();
	#endif
        break;
    case MMI_IMC_KEY_CLEAR:
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        break;
   #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    case MMI_IMC_KEY_CLEAN:
                mmi_imc_delete_all();
                break;
   #endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    case MMI_IMC_KEY_CHANGE_LANGUAGE:
        mmi_imc_key_entry_change_language_screen();
        ClearKeyEvents();
        break;
#endif
    }

#endif //defined(__MMI_IME_STROKE_INPUT__)
	return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_direct_input_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_direct_input_key_check( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (input_mode)
    {
    case IMM_INPUT_MODE_123_SYMBOLS:
    case IMM_INPUT_MODE_ARABIC_NUMERIC:
    case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
    case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:			
    case IMM_INPUT_MODE_123:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9)
            result = MMI_TRUE;
        break;
    default:
        if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9 || key_code == MMI_IMC_KEY_SYM_STAR || key_code == MMI_IMC_KEY_SYM_POUND)
            result = MMI_TRUE;
        break;
    }
    return result;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_direct_input_password_confirm
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_direct_input_password_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    mmi_imc_redraw_screen_by_state();
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_direct_input_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_direct_input_handler( mmi_imc_key_custom_value key_code, U16 event_type )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type first_char;
    UI_character_type   char_code;
    mmi_imm_input_mode_enum	curr_mode = mmi_imm_get_curr_input_mode();
#if defined(__MMI_TOUCH_SCREEN__)
    MMI_BOOL is_last_position = MMI_FALSE;
    mmi_imm_input_mode_enum old_mode;
#endif
    MMI_BOOL password_mode = MMI_FALSE, ret = MMI_FALSE;
    U8 insert_msg = MMI_IMC_MESSAGE_INSERT_CHAR;
            BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__)
    if(mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {
        if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);

            is_last_position = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);

            mmi_imc_pen_confirm_handwriting_selection();

            if (!is_last_position)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            }

            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_pen_confirm_handwriting_selection();
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;
        }
        else if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
        {
            /* for arrow key, do nothing. */
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
            return MMI_TRUE;
        }

        old_mode = mmi_imm_get_curr_input_mode();

        mmi_imc_pen_confirm_handwriting_selection(); 

        /* In canceling timer, input mode may be changed by WCSS */
        if (old_mode != mmi_imm_get_curr_input_mode())
        {
            return MMI_TRUE;
        }

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        return MMI_TRUE;
    }
#endif

    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD)
        || (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        password_mode = MMI_TRUE;
    }

    if ( event_type == KEY_EVENT_DOWN || event_type == KEY_REPEAT )
    {
        if (password_mode)
        {
            insert_msg = MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR;
        }

        if ( key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9 )
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                g_imc_key_down_state = MMI_IMC_STATE_INITIAL;
            }

            if (insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            }

            switch(curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
                first_char = (UI_character_type)mmi_imc_key_send_message( MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION, 0, 0 );
                if (first_char == (UI_character_type) '-')
                    /* return if insertion is for first place*/
                    /* for non '-' characters ensures that they are not being inserted before - sign */
                {
                    if(!mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR, (U32)&first_char, 0))
                    {
                        UI_editor_play_tone_cannot_insert();
                        return MMI_FALSE;
                    }
                }
                char_code = (UI_character_type)('0' + (key_code - MMI_IMC_KEY_SYM_0));
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );

                break;


            case IMM_INPUT_MODE_ARABIC_NUMERIC:
                char_code = (UI_character_type)(0x0660 + (key_code - MMI_IMC_KEY_SYM_0));
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );
                break;
            case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:					
                char_code = (UI_character_type)mmi_imc_key_stroke_get_code_by_key((U8)key_code);
                if ((!mmi_ime_word_is_wildcard(char_code)) && (char_code != 0))
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );
                }
                else if (key_code == MMI_IMC_KEY_SYM_0)
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, 0x20, 0 );                    
                }
                break;
            default:
                char_code = (UI_character_type)('0' + (key_code - MMI_IMC_KEY_SYM_0));

#if defined(__MMI_MULTITAP_KEY_0__)
                if (key_code == MMI_IMC_KEY_SYM_0)
                {
                    g_is_zero_inserted = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
                    ret = g_is_zero_inserted;
                }
                else
#endif
                {
                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
						mmi_imc_redraw_ime_indicator();
                    }	
                }

                break;
            }

            if (ret && insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP);
                mmi_imc_print_string_inserted_to_editor((UI_string_type)&char_code, 1);
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            }
        }
        else if (key_code == MMI_IMC_KEY_SYM_STAR)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }

            if (insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            }

            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
                /* insert '-' if necessary */          
                first_char = (UI_character_type)mmi_imc_key_send_message( MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION, 0, 0 );
                if (first_char == (UI_character_type) '-')
                {
                    /* negative to positive */
                    ret = (MMI_BOOL)mmi_imc_key_send_message( MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION, 0, 0 );
                }
                else
                {
                    char_code = (UI_character_type)('-');
                    ret = (MMI_BOOL)mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION, 0, char_code );
                }
                break;
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
                char_code = (UI_character_type)('*');
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
                break;
            default:
                break;
            }

            if (ret && insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP);
                mmi_imc_print_string_inserted_to_editor((UI_string_type)&char_code, 1);
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            }
        }
        else if (key_code == MMI_IMC_KEY_SYM_POUND)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            }

            if (insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            }

            switch (curr_mode)
            {
            case IMM_INPUT_MODE_FLOAT_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
                /* insert '.' if necessary */
                char_code = (UI_character_type)('.');

                if (mmi_imm_test_input(&char_code, 1))
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
                }
                else
                {
                    UI_editor_play_tone_cannot_insert();
                }    
                break;
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
                char_code = (UI_character_type)('#');
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );                
                break;
            }

            if (ret && insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP);
                mmi_imc_print_string_inserted_to_editor((UI_string_type)&char_code, 1);
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            }
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if ((key_code == MMI_IMC_KEY_LEFT || key_code == MMI_IMC_KEY_RIGHT 
            || key_code == MMI_IMC_KEY_UP || key_code == MMI_IMC_KEY_DOWN) 
            && mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);

            mmi_imc_cancel_timer();

            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_screen_by_state();

            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
        }
    }
    else if (event_type == KEY_EVENT_UP)
    {
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_cancel_timer();
                g_imc_key_inputbox_LSK_function();
            }
            else
            {	
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_redraw_screen_by_state();
            }      
        }      
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        else if (password_mode)
        {                        
            /* start timer to confirm the input. */
            mmi_imc_start_timer(MMI_IMC_KEY_MULTITAP_TIMER, mmi_imc_key_direct_input_password_confirm, mmi_imc_key_direct_input_password_confirm);
        }
    }
    else if (event_type == KEY_LONG_PRESS)
    {
        switch (key_code)
        {
        case MMI_IMC_KEY_SYMBOL_PICKER:
            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
            case IMM_INPUT_MODE_FLOAT_123:
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
            case IMM_INPUT_MODE_123:
                break;
            default:
                mmi_imc_key_entry_symbol_picker();
                break;
            }
            break;
        case MMI_IMC_KEY_CHANGE_MODE:
            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
            case IMM_INPUT_MODE_FLOAT_123:
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
            case IMM_INPUT_MODE_123:
                break;
            default:
			#if defined(__MMI_IME_V3__)
				mmi_imc_show_inputmode_list();
			#else 
				mmi_imc_key_change_input_mode();
			#endif
                break;
            }
            break;
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
        case MMI_IMC_KEY_CHANGE_LANGUAGE:
            mmi_imc_key_entry_change_language_screen();
            ClearKeyEvents();
            break;
#endif
        }    
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_editor_empty
* DESCRIPTION
*  To check if editor is empty or not
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_editor_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0);
    return result;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_common_clear_key_handler
* DESCRIPTION
*  clear key handler for common behavior
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_common_clear_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imc_key_editor_empty())
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
		#if defined(__MMI_IME_CANDIDATE_GRID__)
		if(mmi_imc_is_grid_state())
		#endif
		{
        //mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
    }
    }
    else
    {

    }

}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_common_arrow_key_handler
* DESCRIPTION
*  Only for change highlight index in the same page
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_common_arrow_key_handler(mmi_imc_key_custom_value key_code, U16 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize */

    switch(mmi_imc_get_state())
    {
		#if defined(__MMI_IME_CANDIDATE_GRID__) && (!defined(__MMI_CSTAR__) || defined(__MMI_IME_V3__))
	case MMI_IMC_STATE_SPELL_INPUTING_GRID:
		#endif
    case MMI_IMC_STATE_SPELL_INPUTING:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->comp_select - 1 >= 0)
            {
                g_imc_key.global_data_ptr->comp_select--;
            }
            else
            {
                mmi_imc_key_get_composition_prev_page();
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->comp_select + 1 <= g_imc_key.global_data_ptr->comp_count - 1)
            {
                g_imc_key.global_data_ptr->comp_select++;
            }
            else
            {
                mmi_imc_key_get_composition_next_page();
            }
        }
        else if ( (key_code == MMI_IMC_KEY_UP)|| (key_code == MMI_IMC_KEY_PAGE_UP) )
        {
            mmi_imc_key_get_composition_prev_page();
        }
        else if ((key_code == MMI_IMC_KEY_DOWN) || (key_code == MMI_IMC_KEY_PAGE_DOWN))
        {
            mmi_imc_key_get_composition_next_page();
        }
        else
        {
            ASSERT(0);
        }
        mmi_imc_change_highlighted_composition_from_composition_box(0);

        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_COMPOSITION_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->comp_select, 0);

        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->cand_select - 1 >= 0)
            {
                g_imc_key.global_data_ptr->cand_select--;
            }
            else
            {
                mmi_imc_key_get_associative_prev_page();
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->cand_select + 1 <= g_imc_key.global_data_ptr->cand_count - 1)
            {
                g_imc_key.global_data_ptr->cand_select++;
            }
            else
            {
                mmi_imc_key_get_associative_next_page();
            }
        }
        else if ((key_code == MMI_IMC_KEY_UP)|| (key_code == MMI_IMC_KEY_PAGE_UP))
        {
            mmi_imc_key_get_associative_prev_page();
        }
        else if ((key_code == MMI_IMC_KEY_DOWN) || (key_code == MMI_IMC_KEY_PAGE_DOWN))
        {
            mmi_imc_key_get_associative_next_page();
        }
        else
        {
            ASSERT(0);
        }
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
        break;
    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_HAND_WRITING_CAND:
    case MMI_IMC_STATE_SPELL_WITH_INPUT:
    case MMI_IMC_STATE_CAND_SELECT_WITH_INPUT:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if (!((mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) && 
                mmi_imc_is_floating_candidate_box_enabled()))
#endif
            {
                if (g_imc_key.global_data_ptr->cand_select - 1 >= 0)
                {
                    mmi_imc_change_highlighted_candidate_from_candidate_box((U8)(g_imc_key.global_data_ptr->cand_select - 1));
                    g_imc_key.global_data_ptr->cand_select--;
                }
                else
                {
                    mmi_imc_key_get_candidate_prev_page();
                }
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if (!((mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) && 
                mmi_imc_is_floating_candidate_box_enabled()))
#endif
            {
                if (g_imc_key.global_data_ptr->cand_select + 1 <= g_imc_key.global_data_ptr->cand_count - 1)
                {
                    mmi_imc_change_highlighted_candidate_from_candidate_box((U8)(g_imc_key.global_data_ptr->cand_select + 1));
                    g_imc_key.global_data_ptr->cand_select++;
                }
                else
                {
                    mmi_imc_key_get_candidate_next_page();
                }
            }
        }
        else if ((key_code == MMI_IMC_KEY_UP)|| (key_code == MMI_IMC_KEY_PAGE_UP))
        {
#ifdef __MMI_CSTAR_PHRASE_INPUT__
        if ((mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT) 
            && mmi_imui_get_active_control() == MMI_IMUI_COMPOSITION_AREA)
        {
            mmi_imc_key_smart_phonetic_comp_prev_page();
        }
        else
#endif
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if ((mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) && 
                mmi_imc_is_floating_candidate_box_enabled())
            {
                if (g_imc_key.global_data_ptr->cand_select - 1 >= 0)
                {
                    mmi_imc_change_highlighted_candidate_from_candidate_box((U8)(g_imc_key.global_data_ptr->cand_select - 1));
                    g_imc_key.global_data_ptr->cand_select--;
                }
            }
            else
#endif
            {
                mmi_imc_key_get_candidate_prev_page();
            }
        }
        else if ((key_code == MMI_IMC_KEY_DOWN)|| (key_code == MMI_IMC_KEY_PAGE_DOWN))
        {
#ifdef __MMI_CSTAR_PHRASE_INPUT__
        if ((mmi_imc_get_state() == MMI_IMC_STATE_SPELL_WITH_INPUT || mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT) 
            && mmi_imui_get_active_control() == MMI_IMUI_COMPOSITION_AREA)
        {
            mmi_imc_key_smart_phonetic_comp_next_page();
        }
        else
#endif
#if defined(__MMI_IME_VERTICAL_CAND_BOX__)
            if ((mmi_imc_get_state() == MMI_IMC_STATE_SMART_CANDIDATE || mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC) && 
                mmi_imc_is_floating_candidate_box_enabled())
            {
                if (g_imc_key.global_data_ptr->cand_select + 1 <= g_imc_key.global_data_ptr->cand_count - 1)
                {
                    mmi_imc_change_highlighted_candidate_from_candidate_box((U8)(g_imc_key.global_data_ptr->cand_select + 1));
                    g_imc_key.global_data_ptr->cand_select++;
                }
            }
            else
#endif
            {
                mmi_imc_key_get_candidate_next_page();
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
        break;
   	#if defined(__MMI_IME_CANDIDATE_GRID__) && (defined(__MMI_CSTAR__) && !defined(__MMI_IME_V3__))
		case MMI_IMC_STATE_SPELL_INPUTING_GRID:
		
			if(key_code == MMI_IMC_KEY_PAGE_DOWN)
			{
			    mmi_imc_key_get_candidate_next_page();
			}
			else
			{
				mmi_imc_key_get_candidate_prev_page();
			}
		break;
		#endif
		#if defined(__MMI_IME_CANDIDATE_GRID__)
	case MMI_IMC_STATE_CAND_SELECTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX:
	case MMI_IMC_STATE_ASSOC_SELECTING_GRID:
	case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
	#if defined(__MMI_CSTAR_PHRASE_INPUT__)
	case  MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID:
	#endif
		if(key_code == MMI_IMC_KEY_PAGE_DOWN) //slanting
		{
		#ifdef __MMI_CSTAR_PHRASE_INPUT__
			if ((mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID) 
				&& mmi_imui_get_active_control() == MMI_IMUI_COMPOSITION_AREA)
			{
				mmi_imc_key_smart_phonetic_comp_next_page();
			}
			else
		#endif
			{
				mmi_imc_key_get_candidate_next_page();
			}
		}
		else if(key_code == MMI_IMC_KEY_PAGE_UP)
		{
		#ifdef __MMI_CSTAR_PHRASE_INPUT__
			if ((mmi_imc_get_state() == MMI_IMC_STATE_CAND_SELECT_WITH_INPUT_GRID) 
				&& mmi_imui_get_active_control() == MMI_IMUI_COMPOSITION_AREA)
			{
				 mmi_imc_key_smart_phonetic_comp_prev_page();
			}
			else
		#endif
			{
				mmi_imc_key_get_candidate_prev_page();
			}
		}
		break;
		#endif
    case MMI_IMC_STATE_SPELL_MULTITAP:
        mmi_imc_set_state(MMI_IMC_STATE_CAND_SELECTING); /* No break; */
    case MMI_IMC_STATE_CAND_SELECTING:
    case MMI_IMC_STATE_PREDICTING:
    case MMI_IMC_STATE_VK_CAND:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->cand_select - 1 >= 0)
            {
                g_imc_key.global_data_ptr->cand_select--;
            }
            else
            {
                mmi_imc_key_get_candidate_prev_page();
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->cand_select + 1 <= g_imc_key.global_data_ptr->cand_count - 1)
            {
                g_imc_key.global_data_ptr->cand_select++;
            }
            else
            {
                mmi_imc_key_get_candidate_next_page();
            }
        }
        else if ((key_code == MMI_IMC_KEY_UP)|| (key_code == MMI_IMC_KEY_PAGE_UP))
        {
            mmi_imc_key_get_candidate_prev_page();
        }
        else if ((key_code == MMI_IMC_KEY_DOWN)|| (key_code == MMI_IMC_KEY_PAGE_DOWN))
        {
            mmi_imc_key_get_candidate_next_page();
        }
        else
        {
            ASSERT(0);
        }
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                

        break;
    case MMI_IMC_STATE_MULTITAP:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
            if (g_imc_key.global_data_ptr->cand_select - 1 >= 0)
            {
                g_imc_key.global_data_ptr->cand_select--;
            }
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            if (g_imc_key.global_data_ptr->cand_select + 1 <= g_imc_key.global_data_ptr->cand_count - 1)
            {
                g_imc_key.global_data_ptr->cand_select++;
            }
        }
        mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CANDIDATE_BOX_CHANGE_INDEX, g_imc_key.global_data_ptr->cand_select, 0);                
        break;
    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:
        if (key_code == MMI_IMC_KEY_LEFT)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_LEFT, 1);
        }
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_RIGHT, 1);
        }
        else if (key_code == MMI_IMC_KEY_UP)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_UP, 1);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        else if (key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MOVE_CURSOR, MMI_IMC_EDITOR_CURSOR_DOWN, 1);
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_redraw_screen_by_state();
        }
        break;
    default:
        break;
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_add_key_element
* DESCRIPTION
*  translate imc key code to ime key symbol and then store into key buffer
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_add_key_element(mmi_imc_key_custom_value key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_symbol_key_enum sym = (mmi_imc_symbol_key_enum)((key_code - MMI_IMC_KEY_BASE) + MMI_IMC_SYMB_KEY_BASE);


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length + 1 < MMI_IMC_MAX_KEY_BUFFER_SIZE)
    {
        g_imc_key.global_data_ptr->key_buffer[ g_imc_key.global_data_ptr->key_element_length] = sym;
        g_imc_key.global_data_ptr->key_element_length ++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_delete_key_element
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_delete_key_element(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_imc_key.global_data_ptr->key_element_length)
    {
        g_imc_key.global_data_ptr->key_buffer[ --g_imc_key.global_data_ptr->key_element_length] = 0;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_down
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_down( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        ClearKeyEvents();
        return;
    }
#endif

    mmi_imc_key_get_current_key_info( (PU16)(&g_imc_key.key_info.curr_mmi_key_code), (PU16)(&g_imc_key.key_info.curr_mmi_key_type) );

    mmi_imc_key_group_key_down_int(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type);
}



/*****************************************************************************
* FUNCTION
*  multitap_change_state
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_up( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     #if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_VIRTUAL_KEYBOARD__)
    MMI_ID pre_gid, pre_sid, cur_gid, cur_sid;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_VIRTUAL_KEYBOARD__)
mmi_frm_get_active_scrn_id(&pre_gid, &pre_sid);
#endif
    mmi_imc_key_get_current_key_info( (PU16)(&g_imc_key.key_info.curr_mmi_key_code), (PU16)(&g_imc_key.key_info.curr_mmi_key_type) );

    mmi_imc_key_group_key_up_int(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type);
    #if defined(__MMI_IME_FTE_ENHANCE__)&& defined(__MMI_VIRTUAL_KEYBOARD__)
mmi_frm_get_active_scrn_id(&cur_gid, &cur_sid);
if (pre_gid == cur_gid && pre_sid == cur_sid)
    {
    
        mmi_imc_pen_reset_pen_repeat_event();
    
}
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_repeat
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_repeat( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_key_get_current_key_info( (PU16)(&g_imc_key.key_info.curr_mmi_key_code), (PU16)(&g_imc_key.key_info.curr_mmi_key_type) );

    mmi_imc_key_group_key_repeat_int(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_long
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_long( void )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_key_get_current_key_info( (PU16)(&g_imc_key.key_info.curr_mmi_key_code), (PU16)(&g_imc_key.key_info.curr_mmi_key_type) );

    mmi_imc_key_group_key_long_int(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type);
}


#if !defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_non_qwerty_key_proc
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_ret mmi_imc_key_non_qwerty_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        ClearKeyEvents();
        return MMI_RET_KEY_HANDLED;
    }
#endif

#if !defined(__COSMOS_MMI__)
    if (key_evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (MMI_TRUE == mmi_imc_key_routing_event_handler(
            key_evt->key_code,
            key_evt->key_type,
            key_evt->ucs2_value,
            key_evt->special_key_flag))
        {
            return MMI_RET_KEY_HANDLED;
        }                            
    }
#else
	#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
			if(mmi_imc_get_slider_status()== CLOSE)
			{
				mmi_imc_process_simulated_slider_event(OPEN);
			}
	#endif
#endif


    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_routing_event_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_routing_event_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    FuncPtr key_handler = GetKeyHandler(mmi_key_code, mmi_key_type);
    static MMI_BOOL softkey_down_on_initial_state = MMI_FALSE;
    mmi_imc_state_enum curr_state = mmi_imc_get_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* for all other key which is not controlled by IME. */
    if (key_handler != NULL && !(key_handler == mmi_imc_key_group_key_down
        || key_handler == mmi_imc_key_group_key_up || key_handler == mmi_imc_key_group_key_long
        || key_handler == mmi_imc_key_group_key_repeat))
    {
        /* delete ime timer for word prediction. */
        if (curr_state == MMI_IMC_STATE_INITIAL)
            mmi_imc_delete_timer();
    }

#if (defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__))
    if (mmi_key_code != KEY_END &&
        (mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON) 
#if defined(__MMI_IME_CANDIDATE_GRID__)
           || mmi_imc_is_grid_state() 
#endif
		) && ((mmi_key_code != KEY_UP_ARROW &&  mmi_key_code != KEY_VOL_UP && mmi_key_code != KEY_VOL_DOWN &&
        mmi_key_code != KEY_DOWN_ARROW && mmi_key_code != KEY_LEFT_ARROW && mmi_key_code != KEY_RIGHT_ARROW&&mmi_key_code != KEY_POWER)))
    {
        if (mmi_key_code == KEY_RSK || mmi_key_code == KEY_LSK || mmi_key_code == KEY_CSK)
        {
            if (mmi_key_type == KEY_EVENT_DOWN)
            {

                if (curr_state == MMI_IMC_STATE_INITIAL )
                {
                    mmi_imc_delete_timer();
                    softkey_down_on_initial_state = MMI_TRUE;
                }
		else if(curr_state == MMI_IMC_STATE_PASSWORD_PREVIEW)
		{
		    mmi_imc_cancel_timer();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                    softkey_down_on_initial_state = MMI_TRUE;
		}

                else if (curr_state == MMI_IMC_STATE_WORD_HIGHLIGHTED )
                {
                    mmi_imc_delete_timer();
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                    softkey_down_on_initial_state = MMI_TRUE;
                }
                else if (curr_state == MMI_IMC_STATE_MULTITAP)
                {
                    mmi_imc_delete_timer();
                    mmi_imc_key_multitap_alphabetic_input_confirm();
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
                    softkey_down_on_initial_state = MMI_TRUE;
                }
#if defined(__MMI_IME_CANDIDATE_GRID__)
				else if(mmi_imc_is_grid_state())
				{
					if(curr_state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC)
					{
						if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
						{
							mmi_imc_key_smart_alphabetic_confirm_candidate();
						}
					}
					else if(curr_state == MMI_IMC_STATE_CAND_SELECTING_GRID_WITHOUT_COMP_BOX)
					{
						mmi_imc_pen_confirm_handwriting_selection();
					}
					mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                    mmi_imc_redraw_screen_by_state();
					g_imc_prev_state_is_grid = MMI_TRUE;
                    softkey_down_on_initial_state = MMI_TRUE;
				}
#endif


#if !defined(__NO_HANDWRITING__)
                else if (curr_state == MMI_IMC_STATE_HAND_WRITING)
                {
                    mmi_imc_delete_timer();
                    softkey_down_on_initial_state = MMI_TRUE;
                    mmi_imc_key_send_ui_message(MMI_IMUI_MESSAGE_CLEAR_STROKE, 0, 0);
                    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                }
#if defined(__MMI_TOUCH_SCREEN__)
                else if (curr_state == MMI_IMC_STATE_HAND_WRITING_CAND)
                {
                      
                  UI_string_type str = NULL;
		  UI_character_type temp_cand_buff[MMI_IMC_MAX_CANDIDATE_BUFFSIZE];
                  BOOL lcd_freeze = gdi_lcd_get_freeze();
		  mmi_imc_state_enum state = mmi_imc_get_state();
		  mmi_imc_gdi_lcd_freeze(MMI_TRUE); 
                  str = mmi_imc_get_select_string_from_candidate_box();
		  memset(temp_cand_buff, 0, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
		  memcpy(&temp_cand_buff[0], str, sizeof(UI_character_type) * MMI_IMC_MAX_CANDIDATE_BUFFSIZE);
                  mmi_imc_select_candidate_from_candidate_box();
                  mmi_imc_redraw_screen_by_state();
                  mmi_imc_gdi_lcd_freeze(lcd_freeze);
                  gdi_lcd_repaint_all();
                  softkey_down_on_initial_state = MMI_FALSE;
                      if(mmi_key_code == KEY_LSK || mmi_key_code == KEY_CSK)
                      {
                          ClearKeyEvents();
                      }
                }
#endif
#endif
                else
                {
                    softkey_down_on_initial_state = MMI_FALSE;
                }
            }

            if (softkey_down_on_initial_state)
            {
                ret = MMI_TRUE;
                if (mmi_key_type == KEY_EVENT_UP)
                {
                    mmi_imc_vk_present_enum vk_status = mmi_imc_get_vk_present();  /* Add */
#if !defined(__NO_HANDWRITING__)
                    if (curr_state == MMI_IMC_STATE_HAND_WRITING)
                    {
                        mmi_imc_pen_stop_singleblock_handwriting();
                    }
#endif
                    mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
                    mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
                    mmi_imc_set_vk_present (MMI_IMC_VK_PRESENT_DEFAULT);    /* Add */
                    mmi_imc_redraw_screen_by_state();
                    mmi_imc_set_vk_present(vk_status); /* Add */
                
                }
            }
        }
        else if (mmi_key_type == KEY_EVENT_DOWN)
        {
            mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_VK_ON);
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_clean_force_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON);
#endif
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif

#if defined(__MMI_TOUCH_SCREEN__)
            if (curr_state == MMI_IMC_STATE_HAND_WRITING_CAND)
            {
                mmi_imc_pen_confirm_handwriting_selection();

                return MMI_FALSE;
            }
            else if(curr_state == MMI_IMC_STATE_HAND_WRITING&&mmi_key_code == KEY_SEND)
            {
                        mmi_imc_delete_timer();
            }
#endif

            if (mmi_imm_get_keyboard_type() == IMM_KEYPAD_QWERTY &&
                (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC) &&
                (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_SMART))
            {
                if (curr_state != MMI_IMC_STATE_INITIAL)
                {
                    mmi_imc_key_custom_value imc_key = mmi_imc_key_custom_mapping((mmi_keypads_enum)mmi_key_code);

#ifdef __MMI_CLIPBOARD__
                    if (mmi_imc_is_clipboard_state())
                    {
                        mmi_imc_clipboard_go_back_to_initial();
                    }
                    else
#endif
                    {
                        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                        mmi_imc_redraw_screen_by_state();
                    }

                    if (g_imc_key.key_check_funcptr && 
                        g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
                    {
                        ClearKeyEvents();
                        ret = MMI_TRUE;
                    }
                    else
                    {
                        ret = MMI_FALSE;
                    }    
                }
                else
                {
                    mmi_imc_redraw_screen_by_state();
                    ret = MMI_FALSE;
                }    
            }
            else
            {
                mmi_imc_key_send_ui_message(MMI_IMUI_SET_FLOATING_CANDIDATE_BOX, 0, 0);

                /* 
                * Can not call mmi_imc_redraw_screen_by_state() directly, because
                * it may blt temp screen to LCD
                */
                gui_start_timer(0, mmi_imc_redraw_screen_by_state);
                ret = MMI_FALSE;
            }
        }
    }
#endif	
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
	if(mmi_imc_get_slider_status()== CLOSE)
	{
		if(mmi_imc_get_ui_style(MMI_IMC_UI_STYLE_VK_ON)&& mmi_key_code == KEY_CSK && mmi_imc_get_state() != MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS)
		{
			ret = MMI_TRUE;
		}
		mmi_imc_process_simulated_slider_event(OPEN);
	}
#endif
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_is_user_switching_input_device
* DESCRIPTION
* is user moving from vk to hard keys to keys which needs us to confirm previous input
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_is_user_switching_input_device(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (key_code == KEY_QWERTY)
        return MMI_FALSE;

    /* hard board keys */
    switch(key_code)
    {

    case KEY_VOL_UP:
    case KEY_VOL_DOWN:
    case KEY_RSK:
    case KEY_LSK:
    case KEY_LEFT_ARROW:
    case KEY_RIGHT_ARROW:
    case KEY_UP_ARROW:
    case KEY_DOWN_ARROW:
        return MMI_FALSE;

    default:
        return MMI_TRUE;
    }

}
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_down_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_down_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  imc_key_code;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
#endif
        BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for devices with both touch and keyboard */
#if defined __MMI_XT9__
    if(mmi_imc_key_is_user_switching_input_device(key_code) && (g_imc_key.global_data_ptr->symb_buff[0] == MMI_IMC_KEY_SYM_QWERTY))
        /* user switches from smart alphabetic qwerty to smart 12 key hard*/
    {
        mmi_imc_key_smart_alphabetic_confirm_candidate();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        /* if user is now using vk ; the vk should be hidden*/
        mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON,MMI_FALSE);
        mmi_imc_redraw_screen_by_state();
    }
#endif

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return;
        }
    }

    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING
        || mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
    {
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);
        mmi_imc_cancel_timer();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = key_code;
    sdk_key_event.mmi_key_type = key_type;
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, 0) == 1)
    {
        return;
    }
    else
#endif
    {
        g_imc_key_down_state = mmi_imc_get_state();

        g_imc_key_down_text_length = (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_TEXT_LENGTH, 0, 0);

        g_imc_key_is_editor_in_replace_mode_on_key_down = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE, 0, 0);

        imc_key_code = mmi_imc_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type);

        if ( NULL != g_imc_key.key_info.key_down_handler )
        {
            if ( imc_key_code != MMI_IMC_KEY_INVALID)
            {
                if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
                {
                    mmi_imc_cancel_timer();
                }

                g_imc_key.key_info.key_down_handler( imc_key_code, g_imc_key.key_info.curr_mmi_key_type );

                g_imc_key.key_info.last_imc_key_code = imc_key_code;

            }
        }
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_up_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_up_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  imc_key_code;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = key_code;
    sdk_key_event.mmi_key_type = key_type;
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, 0) == 1)
    {
        return;
    }
    else
#endif
    {
        imc_key_code = mmi_imc_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type);

        if ( NULL != g_imc_key.key_info.key_up_handler )
        {
            if ( imc_key_code != MMI_IMC_KEY_INVALID)
            {
                g_imc_key.key_info.key_up_handler( imc_key_code, g_imc_key.key_info.curr_mmi_key_type );

                g_imc_key.key_info.last_imc_key_code = imc_key_code;
                /* set key handler by state */
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_long_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_long_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  imc_key_code;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;


    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = key_code;
    sdk_key_event.mmi_key_type = key_type;
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, 0) == 1)
    {
        return;
    }
    else
#endif
    {
        if (!mmi_imc_key_fast_number_input((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code))
        {
            imc_key_code = mmi_imc_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type);


            if ( NULL != g_imc_key.key_info.key_long_handler )
            {
                if ( imc_key_code != MMI_IMC_KEY_INVALID)
                {
                    g_imc_key.key_info.key_long_handler( imc_key_code, g_imc_key.key_info.curr_mmi_key_type );

                    g_imc_key.key_info.last_imc_key_code = imc_key_code;

                }
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_repeat_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_repeat_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  imc_key_code;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;


    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = key_code;
    sdk_key_event.mmi_key_type = key_type;
    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, 0) == 1)
    {
        return;
    }
    else
#endif
    {
        imc_key_code = mmi_imc_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type);

        if ( NULL != g_imc_key.key_info.key_repeat_handler )
        {
            if ( imc_key_code != MMI_IMC_KEY_INVALID)
            {
                g_imc_key.key_info.key_repeat_handler( imc_key_code, g_imc_key.key_info.curr_mmi_key_type );

                g_imc_key.key_info.last_imc_key_code = imc_key_code;

            }
        }
    }
}

#else
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_down_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_down_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        g_imc_key.key_info.curr_mmi_key_code = KEY_LSK;

    }

    if (!(g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK))
    {
        return;
    }

    g_imc_key.key_info.ucs2_value= 0;

    mmi_imc_key_qwerty_dispatch_key_down_event();
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_up_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_up_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        g_imc_key.key_info.curr_mmi_key_code = KEY_LSK;

    }


    if (!(g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK))
    {
        return;
    }

    g_imc_key.key_info.ucs2_value= 0;

    mmi_imc_key_qwerty_dispatch_key_up_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_repeat_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_repeat_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        g_imc_key.key_info.curr_mmi_key_code = KEY_LSK;

    }


    if (!(g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK))
    {
        return;
    }

    g_imc_key.key_info.ucs2_value= 0;

    mmi_imc_key_qwerty_dispatch_key_repeat_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_group_key_long_int
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_group_key_long_int(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = key_code;
    g_imc_key.key_info.curr_mmi_key_type = key_type;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        g_imc_key.key_info.curr_mmi_key_code = KEY_LSK;

    }


    if (!(g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK))
    {
        return;
    }

    g_imc_key.key_info.ucs2_value= 0;

    mmi_imc_key_qwerty_dispatch_key_long_press_event();
}

#endif /* #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ */



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_fast_number_input
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_fast_number_input(mmi_keypads_enum key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_fast_input_valid = MMI_FALSE;
    UI_character_type num_char = 0;
        BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* for magic one , currently feature is not supported */
#if defined(__MMI_IME_MAGIC_ONE__)

    if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_PINYIN ||
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_TR_STROKE ||
        mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SM_STROKE)
        return MMI_FALSE;
#endif


    if (g_imc_key_down_state == MMI_IMC_STATE_INITIAL || g_imc_key_down_state == MMI_IMC_STATE_WORD_HIGHLIGHTED ||
        g_imc_key_down_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC || g_imc_key_down_state == MMI_IMC_STATE_PRE_ASSOC_SELECTING ||
        g_imc_key_down_state == MMI_IMC_STATE_ASSOC_SELECTING)
    {
        if (g_imc_key_down_state == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC &&
            mmi_imc_get_state() == MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC &&
            key_code == KEY_0)
        {
            return MMI_FALSE; /* For the special case of alphabetic word prediction */
        }  

        if (!(g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_NUMBERIC) &&
            (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL || 
            (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC) ||
            (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_STROKE) ||
            (g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)))
        {
            if ((key_code >= KEY_0 && key_code <= KEY_9)
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                || (mmi_imm_qwerty_get_opposite_key_code(key_code) >= KEY_0 && mmi_imm_qwerty_get_opposite_key_code(key_code) <= KEY_9)
#endif
                )
            {
                is_fast_input_valid = MMI_TRUE;
            }

            else if ( key_code == KEY_QWERTY)
                return  MMI_TRUE;

        }
    }

    if (is_fast_input_valid)
    {
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        if (!(key_code >= KEY_0 && key_code <= KEY_9))
        {
            key_code = (mmi_keypads_enum)mmi_imm_qwerty_get_opposite_key_code(key_code);
        }
#endif

        num_char = (L'0' + key_code - KEY_0);

        if (!mmi_imm_test_input(&num_char, 1))
        {
            return MMI_FALSE;
        }
        else if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP || 
            mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
        {
            if (!mmi_imc_key_send_message(MMI_IMC_MESSAGE_CHECK_MULTITAP_STATE, 0, 0))
            {
                return MMI_FALSE;
            }
        }

        mmi_imc_delete_timer();

        mmi_imc_gdi_lcd_freeze(MMI_TRUE);

        switch (mmi_imc_get_state())
        {
        case MMI_IMC_STATE_MULTITAP:
        case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:

            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, (U32)num_char, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            break;

        case MMI_IMC_STATE_SMART_CANDIDATE:
#if defined(__MMI_IME_SMART_WITH_INPUT_AREA__)   
            {
                UI_character_type temp_string[2];

                temp_string[0] = num_char;
                temp_string[1] = 0;
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, (U32)1, (U32)temp_string);
                mmi_imc_key_smart_alphabetic_confirm_candidate();
            }

#else    
            if (g_imc_key.global_data_ptr->cand_length)
            {
                UI_character_type temp_string[2];

                temp_string[0] = num_char;
                temp_string[1] = 0;

                mmi_imc_key_send_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, (U32)g_imc_key.global_data_ptr->cand_length, (U32)temp_string);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            }
#endif	
            break;

        case MMI_IMC_STATE_SPELL_MULTITAP:
        case MMI_IMC_STATE_SPELL_INPUTING:
        case MMI_IMC_STATE_VK_CAND_MULTITAP:        
            g_imc_key.spell_multitap_index = -1;
#if!defined __MMI_QWERTY_KEYPAD_SUPPORT__ || defined __MMI_COSMOS_KEYPAD_SLIDER__		
            mmi_ime_multitap_confirm();
#endif
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)num_char, 0);
            break;

        case MMI_IMC_STATE_INITIAL:
            if (g_imc_key_down_text_length < (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_TEXT_LENGTH, 0, 0) ||
                (g_imc_key_is_editor_in_replace_mode_on_key_down && !mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE, 0, 0)))
            {
                if ((g_imc_key.curr_mode_details->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC) &&
                    (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP))
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, (U32)g_imc_directly_input_multitap_string_length, 0);    
                }
                else
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);    
                }
            }
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)num_char, 0);
            break;

        default:
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, (U32)num_char, 0);
            break;
        }

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

        mmi_imc_redraw_screen_by_state();

        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
       #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
       ClearKeyEvents(); /* Clear following repeat key events, otherwise repeat key events may be change to down events */
       #endif
/*in order to restore new behavior need to follow repeat behavior*/
    //    mmi_imc_key_set_key_handler(NULL,key_code ,KEY_EVENT_REPEAT);
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
        mmi_imc_pen_clear_pen_repeat_event();
#endif
        return MMI_TRUE;
    }
    else
    {
        
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_send_message
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U32  mmi_imc_key_send_message( U8 msg_id, U32 param_0, U32 param_1 )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_message_struct imc_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    imc_msg.message_id    = msg_id;
    imc_msg.param_0       = param_0;
    imc_msg.param_1       = param_1;
    return mmi_imc_send_message( &imc_msg );
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_send_ui_message
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static U32  mmi_imc_key_send_ui_message( U8 msg_id, U32 param_0, U32 param_1 )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imui_msg.message_id    = msg_id;
    g_imui_msg.param_0       = param_0;
    g_imui_msg.param_1       = param_1;
    return mmi_imui_send_message( &g_imui_msg, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_change_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_change_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    if (mmi_imm_get_current_allowed_input_mode_num() <= 1
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
        || (mmi_imm_get_input_mode_num_in_current_writing_language() <=1 
        && !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0))
#endif
        )
    {
        return;
    }

    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

    mmi_imc_key_process_before_changing_input_mode();

//#if defined(__MMI_IME_V3__) && (!defined(__MMI_NORMAL_KEYPAD__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
//#if defined(__MMI_IME_V3__) && (defined(__MMI_QWERTY_KEYPAD_SUPPORT__) || defined(__MMI_IME_VK_TYPE_QWERTY__) || defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
#if defined(__MMI_IME_V3__) && !defined(__MMI_NORMAL_KEYPAD__)
	#ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_3__
		if(mmi_imc_pen_vk_event_change_mode(MMI_PEN_EVENT_UP)) //change mode from keypad need to change vk type too
	#else
		if(mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
	#endif
#else
    if (mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
#endif
	{
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
	}

    mmi_imc_redraw_screen_by_state();

    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    mmi_imc_repaint_screen();

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_entry_symbol_picker
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_entry_symbol_picker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code;
    U16 key_event;
    mmi_imc_key_custom_value imc_key;
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_imc_is_symbol_picker_disable())
    {
        mmi_imc_key_get_current_key_info((PU16)(&key_code), (PU16)(&key_event));
        imc_key =  mmi_imc_key_custom_mapping((mmi_keypads_enum)key_code);
#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
#endif
        {
            mmi_imc_gdi_lcd_freeze(TRUE);
        }

        switch (mmi_imc_get_state())
        {
        case MMI_IMC_STATE_MULTITAP:
           // if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
            {
                mmi_imc_cancel_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);                
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
		mmi_imc_redraw_screen_by_state();
            }
         //   else
            {
           //     mmi_imc_key_multitap_alphabetic_input_confirm();
            }
            break;

        case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:
            mmi_imc_cancel_timer();
            break;

        case MMI_IMC_STATE_SMART_CANDIDATE:
        case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
            if (key_event == KEY_LONG_PRESS && g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key)
                && g_imc_key.global_data_ptr->cand_length > g_imc_key_cand_length_before_key_down
                && g_imc_key_cand_length_before_key_down >= 0)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, 
                    g_imc_key.global_data_ptr->cand_length - g_imc_key_cand_length_before_key_down, 
                    0);
            }
            break;

#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
        case MMI_IMC_STATE_NEW_WORD_MULTITAP:
            mmi_ime_multitap_confirm();
            break;
#endif

        default:
            break;

        }
/* dont see and reason for this */
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
     //   mmi_imc_pen_open_symbol_lock();
#endif /* defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__) */

//#if defined __MMI_COSMOS_KEYPAD_BAR__ || defined  __MMI_COSMOS_KEYPAD_SLIDER__
#if defined(__MMI_VUI_ENGINE__)
        if (vadp_p2v_uc_is_in_venus())
        {
            vadp_p2v_show_symbol_picker();
        }
        else
#endif
//#endif
        {
            EntrySymbolPickerScreen();
        }
#if defined(__MMI_VUI_ENGINE__)
        if (!vadp_p2v_uc_is_in_venus())
#endif
        {
            mmi_imc_gdi_lcd_freeze(gdi_freeze);
            mmi_imc_repaint_screen();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_process_before_changing_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_process_before_changing_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code;
    U16 key_event;
    BOOL lcd_freeze = gdi_lcd_get_freeze();
    mmi_imc_key_custom_value imc_key;
    mmi_imm_input_mode_enum old_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    old_mode = mmi_imm_get_curr_input_mode();

    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

    mmi_imc_cancel_timer();

    /* In canceling timer, input mode may be changed by WCSS */
    if (old_mode != mmi_imm_get_curr_input_mode())
    {
        if (mmi_imm_set_current_input_mode(old_mode) == MMI_FALSE)
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return;
        }
        else
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
        }    
    }
    else
    {
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
    }  

    mmi_imc_key_get_current_key_info((PU16)(&key_code), (PU16)(&key_event));
    imc_key =  mmi_imc_key_custom_mapping((mmi_keypads_enum)key_code);

    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_MULTITAP:
        if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
        {
            old_mode = mmi_imm_get_curr_input_mode();

            mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
      #if !defined(__MMI_MULTITAP_BANGLA_SPEC__)
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);            
      #endif
            /* In the above processes, input mode may be changed by WCSS */
            if (old_mode != mmi_imm_get_curr_input_mode())
            {
                mmi_imm_set_current_input_mode(old_mode);
            }
        }
        else
        {
            mmi_imc_key_multitap_alphabetic_input_confirm();
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key)
            && g_imc_key.global_data_ptr->cand_length > g_imc_key_cand_length_before_key_down
            && g_imc_key_cand_length_before_key_down >= 0)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, 
                g_imc_key.global_data_ptr->cand_length - g_imc_key_cand_length_before_key_down, 
                0);
        }
        else if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
        }
        break;
	case MMI_IMC_STATE_PRE_SMART_CANDIDATE: //MAUI_03151284
		{
			mmi_imc_key_smart_alphabetic_confirm_candidate();
		}
    case MMI_IMC_STATE_WORD_HIGHLIGHTED:
        mmi_imc_delete_timer();
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
        break;

#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_ime_multitap_confirm();
        break;
#endif
    default:
        break;
    }

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_switch_between_smart_and_multitap
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_switch_between_smart_and_multitap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum input_mode = IMM_INPUT_MODE_NONE;
    const sIMEModeDetails * mode_details_ptr;
    U16 mode_case;
        BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imm_get_current_allowed_input_mode_num() <= 1
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
        || (mmi_imm_get_input_mode_num_in_current_writing_language() <=1 
        && !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0))
#endif
        )
    {
        return;
    }

    mode_case = g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_CASE_MASK;

#if defined(__MMI_IME_AUTO_CAPITALIZATION__)
    if (mmi_imm_is_auto_capitalization_valid() && !mmi_imm_is_curr_capital_state_of_curr_input_mode())
    {
        switch(g_imc_key.global_data_ptr->capital_state)
        {
        case MMI_IME_WORD_CAPITAL_STATE_UPPER:
            mode_case = IME_MODE_ATTR_UPPERCASE;
            break;

        case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:
            mode_case = IME_MODE_ATTR_TITLECASE;
            break;

        case MMI_IME_WORD_CAPITAL_STATE_LOWER:
            mode_case = IME_MODE_ATTR_LOWERCASE;
            break;

        default:
            break;
        }
    }
#endif /* #if defined(__MMI_IME_AUTO_CAPITALIZATION__) */

    if (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
    {
        mode_details_ptr = mmi_imm_get_corresponding_smart_mode(g_imc_key.curr_mode_details->imm_mode_id, mode_case);

        if (mode_details_ptr)
        {
            input_mode = mode_details_ptr->imm_mode_id;
        }
    }
    else if (g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
    {
        mode_details_ptr = mmi_imm_get_corresponding_multitap_mode(g_imc_key.curr_mode_details->imm_mode_id, mode_case);

        if (mode_details_ptr)
        {
            input_mode = mode_details_ptr->imm_mode_id;
        }
    }

    if (input_mode != IMM_INPUT_MODE_NONE
        && mmi_imm_is_curr_allow_input_mode(input_mode))
    {
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);

        mmi_imc_key_process_before_changing_input_mode();

        mmi_imm_set_current_input_mode(input_mode);

        if (mmi_imc_change_input_mode(input_mode, 0))
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
        }

        mmi_imc_redraw_screen_by_state();

        ClearKeyEvents();

        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_last_imc_key_code
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
U16 mmi_imc_key_get_last_imc_key_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key.key_info.curr_mmi_key_code;  
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_last_translated_imc_key_code
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imc_key_custom_value mmi_imc_key_get_last_translated_imc_key_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key.key_info.last_imc_key_code;  
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_set_pre_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_set_pre_key_handler(mmi_imc_pre_key_handler key_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imc_key.pre_key_handler = key_handler;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_pre_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_imc_pre_key_handler mmi_imc_key_get_pre_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key.pre_key_handler;
}


#ifdef __MMI_CLIPBOARD__ 
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_clipboard_mark_text
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void mmi_imc_key_clipboard_mark_text(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_code == KEY_LEFT_ARROW)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_LEFT, (U32)&g_imc_clipboard_data);
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data.ccp_start_cursor_p, (U32)&g_imc_clipboard_data.ccp_end_cursor_p);
    }
    else if (key_code == KEY_RIGHT_ARROW)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_RIGHT, (U32)&g_imc_clipboard_data);
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data.ccp_start_cursor_p, (U32)&g_imc_clipboard_data.ccp_end_cursor_p);
    }
    else if (key_code == KEY_UP_ARROW || key_code == KEY_VOL_UP)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_UP, (U32)&g_imc_clipboard_data);
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data.ccp_start_cursor_p, (U32)&g_imc_clipboard_data.ccp_end_cursor_p);
    }
    else if (key_code == KEY_DOWN_ARROW || key_code == KEY_VOL_DOWN)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_DOWN, (U32)&g_imc_clipboard_data);
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MARK_TEXT, (U32)&g_imc_clipboard_data.ccp_start_cursor_p, (U32)&g_imc_clipboard_data.ccp_end_cursor_p);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_clipboard_locate_cursor
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void mmi_imc_key_clipboard_locate_cursor(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_code == KEY_LEFT_ARROW)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_LEFT, 0);
    }
    else if (key_code == KEY_RIGHT_ARROW)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_RIGHT, 0);
    }
    else if (key_code == KEY_UP_ARROW || key_code == KEY_VOL_UP)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_UP, 0);
    }
    else if (key_code == KEY_DOWN_ARROW || key_code == KEY_VOL_DOWN)
    {
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_MOVE_CORSOR, MMI_IMC_EDITOR_CURSOR_DOWN, 0);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_clipboard_mark_text_pre_key_handler
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
MMI_BOOL mmi_imc_key_clipboard_pre_key_handler(U16 key_code, U16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL is_password_editor;
    S32 i = 0;
    S32 char_num = 0;
    U32 delay = 0;
    U32 begin_tick = 0;
    U32 end_tick = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Don't mark text when editor type is password because we don't support copy password for security */
    is_password_editor = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_IS_PASSWORD_EDITOR, 0, 0);
    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
        if (key_type == KEY_EVENT_DOWN)
        {
            if (((key_code == KEY_LEFT_ARROW) || (key_code == KEY_RIGHT_ARROW) ||
                (key_code == KEY_UP_ARROW) || (key_code == KEY_DOWN_ARROW) ||
                (key_code == KEY_VOL_UP) || (key_code == KEY_VOL_DOWN)) &&
                !is_password_editor)
            {
                mmi_imc_key_clipboard_mark_text(key_code);
            }
            else if ((key_code != KEY_LSK) && (key_code != KEY_ENTER) && (key_code != KEY_RSK))
            {
                mmi_imc_clipboard_go_back_to_initial();
                return MMI_FALSE;
            }
        }
        else if (key_type == KEY_LONG_PRESS)
        {
            g_wgui_inputs_repeat_count = 0;
        }
        else if (key_type == KEY_REPEAT)
        {
            if (((key_code == KEY_LEFT_ARROW) || (key_code == KEY_RIGHT_ARROW) ||
                (key_code == KEY_UP_ARROW) || (key_code == KEY_DOWN_ARROW) ||
                (key_code == KEY_VOL_UP) || (key_code == KEY_VOL_DOWN)) &&
                !is_password_editor)
            {
                kal_get_time(&begin_tick);
                mmi_imc_key_clipboard_mark_text(key_code);
                kal_get_time(&end_tick);
                end_tick -= begin_tick;
                end_tick = kal_ticks_to_milli_secs(end_tick);

                if ((end_tick < WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME) &&
                    (g_wgui_inputs_repeat_count < WGUI_INPUTS_MAX_REPEAT_COUNT))
                {
                    /* Normal speed (100ms per char) */
                    delay = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME - end_tick;
                    end_tick = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME;
                }
                else if (end_tick < WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME)
                {
                    /* Fastest speed (50ms per char) */
                    delay = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME - end_tick;
                    end_tick = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME;
                }

                char_num = WGUI_INPUTS_KPD_REPEAT_PERIOD / end_tick;

                for (i = 0; i < char_num - 1; i++)
                {
                    if (delay > 0)
                    {
                        kal_sleep_task(kal_milli_secs_to_ticks(delay));
                    }
                    mmi_imc_key_clipboard_mark_text(key_code);
                }
                g_wgui_inputs_repeat_count++;
            }
        }
        else if (key_type == KEY_EVENT_UP)
        {
            if ((key_code == KEY_LSK) || (key_code == KEY_ENTER))
            {
                mmi_imc_clipboard_show_option_menu();
            }
            else if (key_code == KEY_RSK)
            {
                mmi_imc_clipboard_go_back_to_initial();
            }
            else if ((key_code != KEY_LEFT_ARROW) && (key_code != KEY_RIGHT_ARROW) && 
                (key_code != KEY_UP_ARROW) && (key_code != KEY_DOWN_ARROW) &&
                (key_code != KEY_VOL_UP) && (key_code != KEY_VOL_DOWN))
            {
                mmi_imc_clipboard_go_back_to_initial();
                return MMI_FALSE;
            }
        }
        ret = MMI_TRUE;
        break;       
    case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
        if (key_type == KEY_EVENT_DOWN)
        {
            if ((key_code == KEY_LEFT_ARROW) || (key_code == KEY_RIGHT_ARROW) ||
                (key_code == KEY_UP_ARROW) || (key_code == KEY_DOWN_ARROW) ||
                (key_code == KEY_VOL_UP) || (key_code == KEY_VOL_DOWN))
            {
                mmi_imc_key_clipboard_locate_cursor(key_code);
            }
            else if ((key_code != KEY_LSK) && (key_code != KEY_ENTER) && (key_code != KEY_RSK))
            {
                mmi_imc_clipboard_go_back_to_initial();
                return MMI_FALSE;
            }
        }
        else if (key_type == KEY_LONG_PRESS)
        {
            g_wgui_inputs_repeat_count = 0;
        }
        else if (key_type == KEY_REPEAT)
        {
            if ((key_code == KEY_LEFT_ARROW) || (key_code == KEY_RIGHT_ARROW) ||
                (key_code == KEY_UP_ARROW) || (key_code == KEY_DOWN_ARROW) ||
                (key_code == KEY_VOL_UP) || (key_code == KEY_VOL_DOWN))
            {
                kal_get_time(&begin_tick);
                mmi_imc_key_clipboard_locate_cursor(key_code);
                kal_get_time(&end_tick);
                end_tick -= begin_tick;
                end_tick = kal_ticks_to_milli_secs(end_tick);

                if ((end_tick < WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME) &&
                    (g_wgui_inputs_repeat_count < WGUI_INPUTS_MAX_REPEAT_COUNT))
                {
                    /* Normal speed (100ms per char) */
                    delay = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME - end_tick;
                    end_tick = WGUI_INPUTS_QUICK_DEL_NAV_PER_CHAR_TIME;
                }
                else if (end_tick < WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME)
                {
                    /* Fastest speed (50ms per char) */
                    delay = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME - end_tick;
                    end_tick = WGUI_INPUTS_QUICK_DEL_NAV_MIN_CHAR_TIME;
                }

                char_num = WGUI_INPUTS_KPD_REPEAT_PERIOD / end_tick;

                for (i = 0; i < char_num - 1; i++)
                {
                    if (delay > 0)
                    {
                        kal_sleep_task(kal_milli_secs_to_ticks(delay));
                    }
                    mmi_imc_key_clipboard_locate_cursor(key_code);
                }
                g_wgui_inputs_repeat_count++;
            }
        }
        else if (key_type == KEY_EVENT_UP)
        {
            if ((key_code == KEY_LSK) || (key_code == KEY_ENTER))
            {
                mmi_imc_clipboard_enter_mark_text_state(MARK_TEXT_BY_KEY);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLIPBOARD_SET_START_CURSOR_P, (U32)&g_imc_clipboard_data, 0);

                mmi_imc_clipboard_redraw_screen_by_state();

                if ((wgui_inputs_get_editor_handler()->input_box_type == MMI_EDITOR_INLINE_INPUT_BOX) &&
                    (wgui_inputs_get_editor_handler()->input_box_sub_type == MMI_EDITOR_INLINE_MULTILINE_INPUT_BOX))
                {
                    wgui_inputs_ml_set_style(UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT, 0);
                }
            }
            else if (key_code == KEY_RSK)
            {
                mmi_imc_clipboard_go_back_to_initial();
            }
            else if ((key_code != KEY_LEFT_ARROW) && (key_code != KEY_RIGHT_ARROW) &&
                (key_code != KEY_UP_ARROW) && (key_code != KEY_DOWN_ARROW) &&
                (key_code != KEY_VOL_UP) && (key_code != KEY_VOL_DOWN))
            {
                mmi_imc_clipboard_go_back_to_initial();
                return MMI_FALSE;
            }
        }
        ret = MMI_TRUE;
        break;
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
    case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:
        if (key_type == KEY_EVENT_UP)
        {
            mmi_imc_clipboard_go_back_to_initial();
        }
        ret = MMI_TRUE;
        break;
    default:
        break;
    }
    return ret;
}
#endif /* __MMI_CLIPBOARD__ */


#if defined(__MMI_IMC_CAPITAL_SWITCH__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_entry_change_language_screen
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_entry_change_language_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code;
    U16 key_event;
    mmi_imc_key_custom_value imc_key;
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imm_get_current_allowed_writing_language_num() <= 1)
    {
        return;
    }

    mmi_imc_key_get_current_key_info((PU16)(&key_code), (PU16)(&key_event));
    imc_key =  mmi_imc_key_custom_mapping(key_code);

    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_MULTITAP:
       // if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
        {
            mmi_imc_cancel_timer();
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);            
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);         
            mmi_imc_redraw_screen_by_state();
        }
      //  else
        {
       //     mmi_imc_key_multitap_alphabetic_input_confirm();
        }
        break;

    case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:
        mmi_imc_cancel_timer();	
        break;

    case MMI_IMC_STATE_SMART_CANDIDATE:
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
        if (key_event == KEY_LONG_PRESS && g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key)
            && g_imc_key.global_data_ptr->cand_length > g_imc_key_cand_length_before_key_down
            && g_imc_key_cand_length_before_key_down >= 0)
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_STRING, 
                g_imc_key.global_data_ptr->cand_length - g_imc_key_cand_length_before_key_down, 
                0);
        }
        else if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
             mmi_imc_redraw_screen_by_state();
        }
        break;
#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_ime_multitap_confirm();
        break;
#endif
    default:
        break;
    }

    if (mmi_frm_group_get_active_id() != GRP_ID_INVALID)
    {
        g_imc_key_active_editor_screen_id = 0;
    }
    else
    {
        g_imc_key_active_editor_screen_id = GetActiveScreenId();
    }

    RegisterInputMethodScreenCloseFunction(mmi_imc_key_input_method_screen_close_function);

    /* in case of thai , user has put in a character also befor moving on to wlang selection screen
    Thus stopping this */
    mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);

    mmi_imc_gdi_lcd_freeze(lcd_freeze);
#if defined(__MMI_VUI_ENGINE__)

#if defined(__MMI_IME_FTE_ENHANCE__)&& (defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__))

    if (vadp_p2v_uc_is_in_venus())
    {
        mmi_imc_show_wlang_list();
    }
    else
#endif
#endif
    {
#if defined(__MMI_IME_V3__) && (!defined(__MMI_NORMAL_KEYPAD__) && !defined(__MMI_IME_VK_TYPE_QWERTY__) && !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
        mmi_imc_show_inputmode_list();
#else
        EntryInputMethodScreen();
#endif
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_input_method_screen_close_function
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static void mmi_imc_key_input_method_screen_close_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_imc_key_active_editor_screen_id)
    {
        GoBackHistory();
    }
    else
    {
    #ifdef __MMI_FRM_HISTORY__
        GoBackToHistory(g_imc_key_active_editor_screen_id);
    #endif
    }
}

#if !defined(__MMI_IME_AUTO_CAPITALIZATION__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_is_first_uppercase_same_with_uppercase
* DESCRIPTION
* PARAMETERS
* RETURNS
****************************************************************************/
static MMI_BOOL mmi_imc_key_are_the_two_cases_same_in_current_page(mmi_ime_word_capital_state_enum case1, mmi_ime_word_capital_state_enum case2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, str_len;
    UI_string_type str_ptr = NULL;
    UI_character_type temp_buffer1[MMI_IMC_MAX_KEY_BUFFER_SIZE * 2], temp_buffer2[MMI_IMC_MAX_KEY_BUFFER_SIZE * 2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_imc_key.global_data_ptr->cand_count; i++)
    {
        str_ptr = mmi_imc_get_candidate_by_index(g_imc_key.global_data_ptr->cand_buff, (U8)i);

        str_len = mmi_ucs2strlen((const S8*)str_ptr);

        MMI_ASSERT(str_len < (MMI_IMC_MAX_KEY_BUFFER_SIZE * 2));

        memcpy(temp_buffer1, str_ptr, sizeof(UI_character_type) * (str_len + 1));

        memcpy(temp_buffer2, str_ptr, sizeof(UI_character_type) * (str_len + 1));

        mmi_imc_change_alphabetic_candidate_case(temp_buffer1, case1);

        mmi_imc_change_alphabetic_candidate_case(temp_buffer2, case2);

        if (mmi_ucs2cmp((const S8 *)temp_buffer1, (const S8 *)temp_buffer2) != 0)
        {
            return MMI_FALSE;
        }	
    }

    return MMI_TRUE;
}

#endif
#endif /* defined(__MMI_IMC_CAPITAL_SWITCH__) */

#if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_change_candidate_case_by_previous_string
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void mmi_imc_key_change_candidate_case_by_previous_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if !defined(__MMI_IME_AUTO_CAPITALIZATION__) && !defined(__MMI_IME_SLIM__)
    if (!(g_imc_key.curr_mode_details->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE))
    {
        return;
    }

    g_imc_key.global_data_ptr->capital_state = mmi_imc_get_candidate_case_before_candidate();
#endif /* #if !defined(__MMI_IME_AUTO_CAPITALIZATION__) */
}
#endif /* defined(__MMI_SMART_FIRST_UPPERCASE__) */


/*****************************************************************************
* FUNCTION
*  mmi_imc_setup_lsk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  UI_string_type
*****************************************************************************/
UI_string_type mmi_imc_key_get_lsk_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key_lsk_text;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_rsk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  UI_string_type
*****************************************************************************/
UI_string_type mmi_imc_key_get_rsk_text(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key_rsk_text;
}


//#if defined(__MMI_WGUI_CSK_ENABLE__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_csk_text
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  UI_string_type
*****************************************************************************/
UI_string_type mmi_imc_key_get_csk_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_imc_key_csk_text;

}
//#endif
 /* #if defined(__MMI_WGUI_CSK_ENABLE__) */

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_is_key_symbol
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_is_key_symbol(mmi_imc_key_custom_value key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (key_code >= MMI_IMC_KEY_SYM_0 && key_code < MMI_IMC_KEY_SYM_END)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else


    if(key_code == MMI_IMC_KEY_SYM_QWERTY)
        return MMI_TRUE;

    if (key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_POUND)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_reset_ime_state
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  MMI_BOOL
*****************************************************************************/
void mmi_imc_key_reset_ime_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_state_enum prev_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_imc_cancel_timer();

    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_MULTITAP:
        mmi_imc_key_multitap_alphabetic_input_confirm();

        break;
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
#if defined __MMI_IME_CANDIDATE_GRID__
	case MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC:
    case MMI_IMC_STATE_SPELL_INPUTING_GRID:
#endif
        prev_state = mmi_imc_get_state();
        if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
        }
#if defined __MMI_IME_CANDIDATE_GRID__
        if(prev_state == MMI_IMC_STATE_CAND_SELECTING_GRID_ALPHABETIC
            || prev_state == MMI_IMC_STATE_SPELL_INPUTING_GRID)
        {
            mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
            mmi_imc_config_force_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_TRUE);
        }
#endif
        break;

    case MMI_IMC_STATE_WORD_HIGHLIGHTED:
        mmi_imc_delete_timer();
        mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, MMI_TRUE, 0);
        break;

#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_ime_multitap_confirm();
        break;
#endif
#ifdef __MMI_CLIPBOARD__	
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT:
    case MMI_IMC_STATE_CLIPBOARD_MARK_TEXT_BY_PEN:
    case MMI_IMC_STATE_CLIPBOARD_LOCATE_START_POS:
    case MMI_IMC_STATE_CLIPBOARD_FLOATING_MENU:
        mmi_imc_clipboard_go_back_to_initial();
        break;
#endif /* __MMI_CLIPBOARD__ */	
    default:
        break;
    }

}

#if defined(__MMI_ALPHABETIC_WORD_PREDICTION__)
/*****************************************************************************
* FUNCTION
*  mmi_imc_get_previous_word_buffer
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  MMI_BOOL
*****************************************************************************/

UI_character_type * mmi_imc_get_previous_word_buffer()
{
    return g_previous_word_buf;
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_imc_key_is_current_symbol_key
* DESCRIPTION
* PARAMETERS    
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_imc_key_is_current_symbol_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__ 
    if (g_imc_key.key_check_funcptr)
    {
        return (MMI_BOOL)g_imc_key.key_check_funcptr(g_imc_key.curr_mode_details->imm_mode_id, mmi_imc_key_custom_mapping(mmi_key_code));
    }
    else
    {
        return MMI_FALSE;
    } 
#else
    return mmi_imc_key_is_key_symbol(mmi_imc_key_custom_mapping(mmi_key_code));
#endif
}


#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_key_proc
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
mmi_ret mmi_imc_key_qwerty_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (MMI_TRUE == mmi_imc_key_qwerty_group_key_handler(
            key_evt->key_code,
            key_evt->key_type,
            key_evt->ucs2_value,
            key_evt->special_key_flag))
        {
            return MMI_RET_KEY_HANDLED;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_group_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
MMI_BOOL mmi_imc_key_qwerty_group_key_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr key_handler = NULL;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_imc_is_connected())
    {
        return MMI_FALSE;
    }    

#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (mmi_key_type == KEY_EVENT_DOWN &&
        gui_screen_smooth_scrolling_in_freerun())
    {
        gui_ssp_pen_up_dummy();
        ClearKeyEvents();
        return MMI_TRUE;
    }
#endif

    key_handler = mmi_imc_key_get_key_handler(mmi_key_code, mmi_key_type);

    /* for all other key which is not controlled by IME. */
    if (key_handler != NULL && !(key_handler == mmi_imc_key_group_key_down
        || key_handler == mmi_imc_key_group_key_up || key_handler == mmi_imc_key_group_key_long
        || key_handler == mmi_imc_key_group_key_repeat))
    {
        if (g_imc_key_special_key_hint_redrawing_flag)
        {
            mmi_imc_redraw_ime_indicator();

            g_imc_key_special_key_hint_redrawing_flag = MMI_FALSE;
        }

        /* delete ime timer for word prediction. */
        if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
            mmi_imc_delete_timer();
        return MMI_FALSE;
    }


    special_key_flag = mmi_frm_qwerty_get_customized_special_key_flag();

    if (mmi_imc_get_state() == MMI_IMC_STATE_MULTITAP)
    {
        if (g_imc_key_multitap_special_key_flag != special_key_flag)
        {
            ucs2_value = MMI_QWERTY_GET_UCS2_CODE(mmi_imm_qwerty_get_translated_key_code_of_current_lang(mmi_key_code, g_imc_key_multitap_special_key_flag));
        }
    }

    if (mmi_key_type == KEY_EVENT_DOWN)
    {
        ret = mmi_imc_key_qwerty_group_key_down_handler(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
    }
    else if (mmi_key_type == KEY_EVENT_UP)
    {
        ret = mmi_imc_key_qwerty_group_key_up_handler(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
    }
    else if (mmi_key_type == KEY_EVENT_LONG_PRESS)
    {
        ret = mmi_imc_key_qwerty_group_key_long_press_handler(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
    }
    else if (mmi_key_type == KEY_EVENT_REPEAT)
    {
        ret = mmi_imc_key_qwerty_group_key_repeat_handler(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag);
    }

    if (g_imc_key_special_key_hint_redrawing_flag && mmi_imc_is_connected())
    {
        mmi_imc_redraw_ime_indicator();
    }

    g_imc_key_special_key_hint_redrawing_flag = MMI_FALSE;

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_qwerty_key_translate_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static mmi_imc_key_custom_value mmi_imc_qwerty_key_translate_event( mmi_keypads_enum key_code, mmi_key_types_enum event_type, U16 ucs2_value, U32 special_flag )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_keypads_enum key_opposite;
    mmi_imc_key_custom_value imc_key =  mmi_imc_key_custom_mapping(key_code);
    mmi_imc_state_enum state = mmi_imc_get_state();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (key_code == KEY_ENTER)
    {
        key_code = KEY_LSK;
    }
/*this is a temp fix need to be modified*/
       if(mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER)
       {
           key_opposite = (mmi_keypads_enum)mmi_imm_qwerty_get_opposite_key_code(key_code);
       if(g_imc_key.key_info.curr_special_key_flag==MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN&&(key_opposite==KEY_W||key_opposite==KEY_P))
       {
      imc_key =  mmi_imc_key_custom_mapping(key_opposite);
      if(key_opposite==KEY_W)
      {
          g_imc_key.key_info.ucs2_value='w';
       }
      else if(key_opposite==KEY_P)
      {
      g_imc_key.key_info.ucs2_value='p';
      }
       }
       }
    switch(state)
    {
    case MMI_IMC_STATE_NONE:
        ASSERT(0);
        break;

    case MMI_IMC_STATE_INITIAL:
    case MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP:	
    case MMI_IMC_STATE_HAND_WRITING_CAND:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (key_code == KEY_LSK || key_code == KEY_ENTER)
                {
                    if (state == MMI_IMC_STATE_INITIAL)
                        return MMI_IMC_KEY_LSK;
                    else
                        return MMI_IMC_KEY_CONFIRM;
                }
                else if (imc_key == MMI_IMC_KEY_SYM_0)
                {
                    return MMI_IMC_KEY_SPACE;
                }
                else if (key_code == KEY_QWERTY_ENTER)
                {
                    return MMI_IMC_KEY_NEW_LINE;
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    //return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_FN)
                {
                    return MMI_IMC_KEY_FN;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (key_code == KEY_CLEAR)
            {
                return MMI_IMC_KEY_CLEAN;
            }
		#if defined(__MMI_IME_V3__)
			else if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            else if (key_code >= KEY_0 && key_code <= KEY_9)
            {
                if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER ||
                    mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR ||
                    mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_SIM_NUMERIC)
                {
                    return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_SYM_0);
                }
                else
                {
                    return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
                }
            }

            else if (key_code == KEY_BACKSPACE)
            {
                return MMI_IMC_KEY_CLEAN;
            }
            else if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
            else if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif
#if defined(__MMI_IME_V3__)
			else if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
#endif
            else
            {
                if (state == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
                {
                    return imc_key;
                }
            }
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_0)
                {
                    return MMI_IMC_KEY_SPACE;
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    //return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_QWERTY_ENTER)
                {
                    return MMI_IMC_KEY_NEW_LINE;
                }
				else if (key_code == KEY_FN)
                {
                    return MMI_IMC_KEY_FN;
                } 
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER || key_code == KEY_QWERTY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_RSK;
                }
                else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else
            {
            if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }               
        }

        break;
    case MMI_IMC_STATE_MULTITAP:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    //return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_LSK)
                {
                    return MMI_IMC_KEY_LSK;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
    					 else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_LONG_PRESS)
        {
            if (key_code == KEY_CLEAR)
            {
                return MMI_IMC_KEY_CLEAN;
            }
            else if (key_code <= KEY_0 && key_code >= KEY_9)
            {
                return (mmi_imc_key_custom_value)((key_code - KEY_0) + MMI_IMC_KEY_CHAR_0);
            }
            else if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			else if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            else if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else if (key_code == KEY_LSK)
            {
                return MMI_IMC_KEY_LSK;
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif
        }
        break;
    case MMI_IMC_STATE_SPELL_INPUTING:
    case MMI_IMC_STATE_SPELL_MULTITAP:
    case MMI_IMC_STATE_VK_CAND:
    case MMI_IMC_STATE_VK_CAND_MULTITAP:    
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    //return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_FN)
                {
                    return MMI_IMC_KEY_FN;
                }    
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
             #endif
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_SPELL_MULTITAP || 
                mmi_imc_get_state() == MMI_IMC_STATE_VK_CAND || 
                mmi_imc_get_state() ==MMI_IMC_STATE_VK_CAND_MULTITAP)
            {
                if (ucs2_value != 0)
                {
                    return imc_key;
                }               
            }
            if (key_code == KEY_LSK || key_code == KEY_ENTER || key_code == KEY_QWERTY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }

		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif

        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_RSK;
                }
                else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
            {
                return MMI_IMC_KEY_CLEAR;
            }
                                            
            #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
             #endif
        }
        break;
    case MMI_IMC_STATE_CAND_SELECTING:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if ((MMI_IMC_CANDIDATE_BOX_STYLE & MMI_IMUI_SELECTION_AREA_STYLE_LABEL))
            {
                if (key_code >= KEY_1 && key_code<= KEY_9)
                {
                    return (mmi_imc_key_custom_value)(MMI_IMC_KEY_CHAR_1 + (key_code - KEY_1));
                }
            }
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
#if !defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
                    if (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_SM_STROKE ||
                        g_imc_key.curr_mode == IMM_INPUT_MODE_HK_STROKE ||                              
                        g_imc_key.curr_mode == IMM_INPUT_MODE_TR_STROKE)
                    {
                        return MMI_IMC_KEY_TONE_CHANGE;
                    }
                    else
#endif
#endif
                        return mmi_imc_key_translate_star_key(event_type);
                }
                else if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    //return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_FN)
                {
                    return MMI_IMC_KEY_FN;
                } 
#if defined(__MMI_MULTITAP_FOR_STAR_AND_POUND__)
#if defined(__MMI_IME_TONE_IN_STAR_KEY__)
                else if (imc_key == MMI_IMC_KEY_SYM_STAR && 
                    (g_imc_key.curr_mode == IMM_INPUT_MODE_TR_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_SM_STROKE ||
                    g_imc_key.curr_mode == IMM_INPUT_MODE_HK_STROKE ||                              
                    g_imc_key.curr_mode == IMM_INPUT_MODE_TR_STROKE))
                {
                    return MMI_IMC_KEY_TONE_CHANGE;
                }
#endif
#endif
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
             #endif
            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER || key_code == KEY_QWERTY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
            if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
            {
                if (key_code == KEY_RSK)
                {
                    return MMI_IMC_KEY_RSK;
                }
                else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
            }
            else
            {
            if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
            {
                return MMI_IMC_KEY_CLEAR;
            }
            }
                           
            #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                if (key_code == KEY_CLEAR)
                {
                    return MMI_IMC_KEY_CLEAR;
                }
             #endif
        }

        break;
    case MMI_IMC_STATE_ASSOC_SELECTING:
        if (event_type == KEY_EVENT_DOWN || event_type == KEY_EVENT_REPEAT)
        {
            if ((MMI_IMC_CANDIDATE_BOX_STYLE & MMI_IMUI_SELECTION_AREA_STYLE_LABEL))
            {
                if (key_code >= KEY_1 && key_code<= KEY_9)
                {
                    return (mmi_imc_key_custom_value)(MMI_IMC_KEY_CHAR_1 + (key_code - KEY_1));
                }
            }
            if (ucs2_value != 0)
            {
                return imc_key;
            }
            else
            {
                if (mmi_imc_key_translate_arrow_key(key_code) != MMI_IMC_KEY_INVALID)
                {
                    return mmi_imc_key_translate_arrow_key(key_code);
                }
                else if (key_code == KEY_0)
                {
                    return MMI_IMC_KEY_SPACE;
                }
                else if (imc_key == MMI_IMC_KEY_SYM_STAR)
                {
                    return mmi_imc_key_translate_star_key(event_type);
                }
                if (imc_key == MMI_IMC_KEY_SYM_POUND)
                {
                    return mmi_imc_key_translate_pound_key(event_type);
                }
#if !defined(__MMI_IMC_CAPITAL_SWITCH__)
                else if (key_code == KEY_QWERTY_MENU)
                {
                    return MMI_IMC_KEY_CHANGE_MODE;
                }
#endif
                else if (key_code == KEY_SYMBOL)
                {
                    // return MMI_IMC_KEY_SYMBOL_PICKER;
					return mmi_imc_key_translate_symbol_key(event_type);
                }
                else if (key_code == KEY_NUM_LOCK)
                {
                    return MMI_IMC_KEY_NUM_LOCK;
                }
                else if (key_code == KEY_FN)
                {
                    return MMI_IMC_KEY_FN;
                }
                else if (mmi_frm_kbd_is_key_supported(KEY_CLEAR))
                {
                    if (key_code == KEY_RSK)
                    {
                        return MMI_IMC_KEY_RSK;
                    }
                    else if (key_code == KEY_CLEAR || key_code == KEY_BACKSPACE)
                    {
                        return MMI_IMC_KEY_CLEAR;
                    }
                }
                else if (key_code == KEY_RSK || key_code == KEY_BACKSPACE)
                {
                    return MMI_IMC_KEY_CLEAR;
                }

            }
        }
        else if (event_type == KEY_EVENT_UP)
        {
            if (key_code == KEY_LSK || key_code == KEY_ENTER || key_code == KEY_QWERTY_ENTER)
            {
                return MMI_IMC_KEY_CONFIRM;
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU)
            {
                return MMI_IMC_KEY_CHANGE_MODE;
            }
#endif
        }
        else if (event_type == KEY_LONG_PRESS)
        {
            if (imc_key == MMI_IMC_KEY_SYM_STAR)
            {
                return mmi_imc_key_translate_star_key(event_type);
            }
		#if defined(__MMI_IME_V3__)
			if (key_code == KEY_SYMBOL)
			{
				return mmi_imc_key_translate_symbol_key(event_type);
			}
		#endif
		#if defined(__MMI_IME_V3__)
			else if(key_code == KEY_QWERTY_MENU)
			{
				return MMI_IMC_KEY_CHANGE_MODE;
			}
		#endif
            if (imc_key == MMI_IMC_KEY_SYM_POUND)
            {
                return mmi_imc_key_translate_pound_key(event_type);
            }
#if defined(__MMI_IMC_CAPITAL_SWITCH__)
            else if (key_code == KEY_QWERTY_MENU &&
                !mmi_imc_key_send_message(MMI_IMC_MESSGAE_IS_WRITING_LANG_SELECTION_SCREEN_DISABLED, 0, 0) && 
                mmi_imm_get_current_allowed_writing_language_num() > 1)
            {
                return MMI_IMC_KEY_CHANGE_LANGUAGE;
            }
#endif
        }
        break;
    case MMI_IMC_STATE_HAND_WRITING:
        break;
    case MMI_IMC_STATE_PREDICTING:
        break;

    default:
        break;

    }

    return MMI_IMC_KEY_INVALID;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_group_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_group_key_down_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = mmi_key_code;
    g_imc_key.key_info.curr_mmi_key_type = mmi_key_type;
    g_imc_key.key_info.ucs2_value= ucs2_value;
    g_imc_key.key_info.curr_special_key_flag= special_key_flag;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        return MMI_FALSE;
    }
#if defined(__MMI_COSMOS_KEYPAD_SUPPORT_VK__)
		if(mmi_imc_get_slider_status()== CLOSE)
		{
			mmi_imc_process_simulated_slider_event(OPEN);
			// special case for changing input from vk to keypad in stroke input mode
			g_imc_key.key_info.curr_mmi_key_code = mmi_imc_key_get_opposite_key_for_stroke(mmi_key_code);
		}
#endif
    return mmi_imc_key_qwerty_dispatch_key_down_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_group_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_group_key_up_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = mmi_key_code;
    g_imc_key.key_info.curr_mmi_key_type = mmi_key_type;
    g_imc_key.key_info.ucs2_value= ucs2_value;
    g_imc_key.key_info.curr_special_key_flag= special_key_flag;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        return MMI_FALSE;
    }



    return mmi_imc_key_qwerty_dispatch_key_up_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_group_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_group_key_long_press_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = mmi_key_code;
    g_imc_key.key_info.curr_mmi_key_type = mmi_key_type;
    g_imc_key.key_info.ucs2_value= ucs2_value;
    g_imc_key.key_info.curr_special_key_flag= special_key_flag;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        return MMI_FALSE;
    }


    return mmi_imc_key_qwerty_dispatch_key_long_press_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_group_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_group_key_repeat_handler(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_imc_key.key_info.curr_mmi_key_code = mmi_key_code;
    g_imc_key.key_info.curr_mmi_key_type = mmi_key_type;
    g_imc_key.key_info.ucs2_value= ucs2_value;
    g_imc_key.key_info.curr_special_key_flag= special_key_flag;

    if (g_imc_key.key_info.curr_mmi_key_code == KEY_LSK 
        || g_imc_key.key_info.curr_mmi_key_code == KEY_RSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_CSK
        || g_imc_key.key_info.curr_mmi_key_code == KEY_ENTER)
    {
        return MMI_FALSE;
    }


    return mmi_imc_key_qwerty_dispatch_key_repeat_event();
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_dispatch_key_down_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_down_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  key_code;
    MMI_BOOL ret = MMI_FALSE;
        BOOL lcd_freeze = gdi_lcd_get_freeze();

#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
    mmi_ime_sdk_key_event_special_data_struct sdk_special_key;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return MMI_TRUE;
        }
    }

    if (mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING
        || mmi_imc_get_state() == MMI_IMC_STATE_MULTI_BLOCK_HAND_WRITING)
    {
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);
        mmi_imc_cancel_timer();
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = g_imc_key.key_info.curr_mmi_key_code;
    sdk_key_event.mmi_key_type = g_imc_key.key_info.curr_mmi_key_type;
    sdk_special_key.special_key_flag = g_imc_key.key_info.special_key_flag;
    sdk_special_key.ucs2_code = g_imc_key.key_info.ucs2_value;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, (U32)&sdk_special_key) == 1)
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        g_imc_key_down_state = mmi_imc_get_state();

        g_imc_key_down_text_length = (S32)mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_TEXT_LENGTH, 0, 0);

        g_imc_key_is_editor_in_replace_mode_on_key_down = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_EDITOR_IN_REPLACE_MODE, 0, 0);

        key_code = mmi_imc_qwerty_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, 
            (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type, 
            g_imc_key.key_info.ucs2_value, 
            g_imc_key.key_info.curr_special_key_flag);

        if ( NULL != g_imc_key.key_info.qwerty_key_down_handler )
        {
            if ( key_code != MMI_IMC_KEY_INVALID)
            {
                if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL)
                {
                    mmi_imc_cancel_timer();
                }

                ret = mmi_imc_key_qwerty_common_key_down_handler(key_code, KEY_EVENT_DOWN, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);

                if (!ret)
                {
                    ret = g_imc_key.key_info.qwerty_key_down_handler(key_code, KEY_EVENT_DOWN, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);
                }

                g_imc_key.key_info.last_imc_key_code = key_code;
                g_imc_key.key_info.last_ucs2_value = g_imc_key.key_info.ucs2_value;
                g_imc_key.key_info.special_key_flag = g_imc_key.key_info.curr_special_key_flag;
            }
        }
    }
    return ret;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_dispatch_key_up_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_up_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  key_code;
    MMI_BOOL ret = MMI_FALSE;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
    mmi_ime_sdk_key_event_special_data_struct sdk_special_key;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return MMI_TRUE;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = g_imc_key.key_info.curr_mmi_key_code;
    sdk_key_event.mmi_key_type = g_imc_key.key_info.curr_mmi_key_type;
    sdk_special_key.special_key_flag = g_imc_key.key_info.special_key_flag;
    sdk_special_key.ucs2_code = g_imc_key.key_info.ucs2_value;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, (U32)&sdk_special_key) == 1)
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        key_code = mmi_imc_qwerty_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, 
            (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type, 
            g_imc_key.key_info.ucs2_value, 
            g_imc_key.key_info.curr_special_key_flag);

        if ( NULL != g_imc_key.key_info.qwerty_key_up_handler )
        {
            if ( key_code != MMI_IMC_KEY_INVALID)
            {            
                ret = g_imc_key.key_info.qwerty_key_up_handler(key_code, KEY_EVENT_UP, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);

                g_imc_key.key_info.last_imc_key_code = key_code;
                g_imc_key.key_info.last_ucs2_value = g_imc_key.key_info.ucs2_value;
                g_imc_key.key_info.special_key_flag = g_imc_key.key_info.curr_special_key_flag;
            }
        }
    }
    return ret;


}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_dispatch_key_long_press_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_long_press_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  key_code;
    MMI_BOOL ret = MMI_FALSE;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
    mmi_ime_sdk_key_event_special_data_struct sdk_special_key;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return MMI_TRUE;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = g_imc_key.key_info.curr_mmi_key_code;
    sdk_key_event.mmi_key_type = g_imc_key.key_info.curr_mmi_key_type;
    sdk_special_key.special_key_flag = g_imc_key.key_info.special_key_flag;
    sdk_special_key.ucs2_code = g_imc_key.key_info.ucs2_value;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, (U32)&sdk_special_key) == 1)
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        if (!mmi_imc_key_fast_number_input((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code))
        {
            key_code = mmi_imc_qwerty_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, 
                (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type, 
                g_imc_key.key_info.ucs2_value, 
                g_imc_key.key_info.curr_special_key_flag);

            if ( NULL != g_imc_key.key_info.qwerty_key_long_press_handler )
            {
                if ( key_code != MMI_IMC_KEY_INVALID)
                {            
                    ret = g_imc_key.key_info.qwerty_key_long_press_handler(key_code, KEY_EVENT_LONG_PRESS, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);

                    g_imc_key.key_info.last_imc_key_code = key_code;
                    g_imc_key.key_info.last_ucs2_value = g_imc_key.key_info.ucs2_value;
                    g_imc_key.key_info.special_key_flag = g_imc_key.key_info.curr_special_key_flag;
                }
            }
        }
    }
    return ret;

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_dispatch_key_repeat_event
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_dispatch_key_repeat_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_key_custom_value  key_code;
    MMI_BOOL ret = MMI_FALSE;
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_key_event_data_struct sdk_key_event;
    mmi_ime_sdk_key_event_special_data_struct sdk_special_key;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key.pre_key_handler != NULL)
    {
        if (g_imc_key.pre_key_handler(g_imc_key.key_info.curr_mmi_key_code, g_imc_key.key_info.curr_mmi_key_type))
        {
            return MMI_TRUE;
        }
    }

#ifdef __MMI_IME_PLUG_IN__
    sdk_key_event.mmi_key_code = g_imc_key.key_info.curr_mmi_key_code;
    sdk_key_event.mmi_key_type = g_imc_key.key_info.curr_mmi_key_type;
    sdk_special_key.special_key_flag = g_imc_key.key_info.special_key_flag;
    sdk_special_key.ucs2_code = g_imc_key.key_info.ucs2_value;

    if (mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_KEY_EVENT, (U32)&sdk_key_event, (U32)&sdk_special_key) == 1)
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        key_code = mmi_imc_qwerty_key_translate_event((mmi_keypads_enum)g_imc_key.key_info.curr_mmi_key_code, 
            (mmi_key_types_enum)g_imc_key.key_info.curr_mmi_key_type, 
            g_imc_key.key_info.ucs2_value, 
            g_imc_key.key_info.curr_special_key_flag);

        if ( NULL != g_imc_key.key_info.qwerty_key_repeat_handler )
        {
            if ( key_code != MMI_IMC_KEY_INVALID)
            {            
                if (g_imc_key.key_info.qwerty_key_repeat_handler == g_imc_key.key_info.qwerty_key_down_handler)
                {
                    ret = mmi_imc_key_qwerty_common_key_down_handler(key_code, KEY_EVENT_DOWN, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);
                }
                else
                {
                    ret = mmi_imc_key_qwerty_common_key_repeat_handler(key_code, KEY_EVENT_REPEAT, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);
                }

                if (!ret)
                {
                    ret = g_imc_key.key_info.qwerty_key_repeat_handler(key_code, KEY_EVENT_REPEAT, g_imc_key.key_info.ucs2_value, g_imc_key.key_info.curr_special_key_flag);
                }

                g_imc_key.key_info.last_imc_key_code = key_code;
                g_imc_key.key_info.last_ucs2_value = g_imc_key.key_info.ucs2_value;
                g_imc_key.key_info.special_key_flag = g_imc_key.key_info.curr_special_key_flag;
            }
        }
    }
    return ret;

}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_smart_alphabetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_smart_alphabetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_smart_alphabetic_key_up_handler(key_code, event_type);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_smart_alphabetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_smart_alphabetic_key_long_press_handler(key_code, event_type);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_smart_alphabetic_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_smart_alphabetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_smart_alphabetic_key_down_handler(key_code, event_type);
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_multitap_alphabetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_key_multitap_alphabetic_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_multitap_alphabetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_multitap_alphabetic_up_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_multitap_alphabetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_multitap_alphabetic_long_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_multitap_alphabetic_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_multitap_alphabetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_key_multitap_alphabetic_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phonetic_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (special_key_flag)
    {
         mmi_imc_key_qwerty_phonetic_fn_input_symbol(key_code, event_type, ucs2_value, special_key_flag);
        
        
        return MMI_TRUE;
    }


    return mmi_imc_key_multitap_phonetic_key_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phonetic_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_multitap_phonetic_key_up_handler(key_code, event_type);    

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phonetic_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_multitap_phonetic_key_long_press_handler(key_code, event_type);    

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phonetic_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phonetic_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_key_qwerty_phonetic_fn_input_symbol(key_code, event_type, ucs2_value, special_key_flag))
    {
        return MMI_TRUE;
    }

    return mmi_imc_key_multitap_phonetic_key_down_handler(key_code, event_type);

}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_stroke_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_imc_key_qwerty_phonetic_fn_input_symbol(key_code, event_type, ucs2_value, special_key_flag))
    {
        return MMI_TRUE;
    }

    return mmi_imc_key_stroke_key_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_stroke_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_stroke_key_up_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_stroke_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_stroke_key_long_press_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_stroke_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_stroke_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_key_qwerty_phonetic_fn_input_symbol(key_code, event_type, ucs2_value, special_key_flag))
    {
        return MMI_TRUE;
    }

    return mmi_imc_key_stroke_key_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_direct_input_key_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_direct_input_key_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type first_char;
    UI_character_type   char_code;
    mmi_imm_input_mode_enum	curr_mode = mmi_imm_get_curr_input_mode();
#if defined(__MMI_TOUCH_SCREEN__)
    MMI_BOOL is_last_position = MMI_FALSE;
    mmi_imm_input_mode_enum old_mode;
#endif
    MMI_BOOL password_mode = MMI_FALSE, ret = MMI_FALSE;
    U8 insert_msg = MMI_IMC_MESSAGE_INSERT_CHAR;
            BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
            if(key_code>=MMI_IMC_KEY_SYM_0&&key_code<=MMI_IMC_KEY_SYM_9)
            {
#if defined(__MMI_IME_FLOATING_CAND_BOX__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_FLOAT_ON, MMI_TRUE);
#endif
#if defined(__MMI_IME_FTE_ENHANCE__) && defined(__MMI_VIRTUAL_KEYBOARD__)
                mmi_imc_config_ui_style(MMI_IMC_UI_STYLE_VK_ON, MMI_FALSE);
                mmi_imc_redraw_screen_by_state();
#endif
            }
#if defined(__MMI_TOUCH_SCREEN__)
    if(mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
    {
        if (key_code == MMI_IMC_KEY_CLEAR)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);

            is_last_position = (MMI_BOOL)mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);

            mmi_imc_pen_confirm_handwriting_selection();

            if (!is_last_position)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
            }

            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            mmi_imc_pen_confirm_handwriting_selection();
            mmi_imc_redraw_screen_by_state();
            return MMI_TRUE;
        }
        else if (key_code >= MMI_IMC_KEY_UP && key_code <= MMI_IMC_KEY_RIGHT)
        {
            /* for arrow key, do nothing. */
            return MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
            return MMI_TRUE;
        }
        #if defined(__MMI_IMC_CAPITAL_SWITCH__)
        else if(key_code== MMI_IMC_KEY_CHANGE_LANGUAGE)
            mmi_imc_key_entry_change_language_screen();
            ClearKeyEvents();
        #endif

        old_mode = mmi_imm_get_curr_input_mode();

        mmi_imc_pen_confirm_handwriting_selection(); 

        /* In canceling timer, input mode may be changed by WCSS */
        if (old_mode != mmi_imm_get_curr_input_mode())
        {
            return MMI_TRUE;
        }

        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        return MMI_TRUE;
    }
#endif

    if ((mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD)
        || (mmi_imm_get_curr_input_type() == IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        password_mode = MMI_TRUE;
    }

    if ( event_type == KEY_EVENT_DOWN || event_type == KEY_REPEAT )
    {
        if (password_mode)
        {
            insert_msg = MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR;
        }

        if ( key_code >= MMI_IMC_KEY_SYM_0 && key_code <= MMI_IMC_KEY_SYM_9 )
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                g_imc_key_down_state = MMI_IMC_STATE_INITIAL;
            }

            if (insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            }

            switch(curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
                first_char = (UI_character_type)mmi_imc_key_send_message( MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION, 0, 0 );
                if (first_char == (UI_character_type) '-')
                    /* return if insertion is for first place*/
                    /* for non '-' characters ensures that they are not being inserted before - sign */
                {
                    if(!mmi_imc_key_send_message(MMI_IMC_MESSAGE_GET_PREVIOUS_CHAR, (U32)&first_char, 0))
                    {
                        UI_editor_play_tone_cannot_insert();
                        return MMI_FALSE;
                    }
                }
                char_code = (UI_character_type)('0' + (key_code - MMI_IMC_KEY_SYM_0));
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );
                break;
            case IMM_INPUT_MODE_ARABIC_NUMERIC:
                char_code = (UI_character_type)(0x0660 + (key_code - MMI_IMC_KEY_SYM_0));
                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );
                break;
            case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
            case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:

                if (g_imc_key.key_info.curr_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)ucs2_value, 0 );
                }
                else
                {
                    char_code = (UI_character_type)mmi_imc_key_stroke_get_code_by_key((U8)key_code);
                    if ((!mmi_ime_word_is_wildcard(char_code)) && (char_code != 0))
                    {
                        ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (U32)char_code, 0 );
                    }
                }
                break;
            default:
                char_code = (UI_character_type)('0' + (key_code - MMI_IMC_KEY_SYM_0));

                ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );

                break;
            }

            if (ret && insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP);
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            }
        }
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
        else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
            mmi_imc_key_entry_symbol_picker();
            return MMI_TRUE;
        }
        else if ((key_code == MMI_IMC_KEY_LEFT || key_code == MMI_IMC_KEY_RIGHT 
            || key_code == MMI_IMC_KEY_UP || key_code == MMI_IMC_KEY_DOWN) 
            && mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
        {
            mmi_imc_gdi_lcd_freeze(MMI_TRUE);

            mmi_imc_cancel_timer();

            mmi_imc_key_common_arrow_key_handler(key_code, event_type);
            mmi_imc_redraw_screen_by_state();

            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
            }
        }
        else 
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_delete_timer();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                g_imc_key_down_state = MMI_IMC_STATE_INITIAL;
            }

            if (insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
            }

            char_code = g_imc_key.key_info.ucs2_value;

            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
                /* insert '-' if necessary */          
                if (char_code == (UI_character_type)('-') || mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, (UI_character_type)('-')))
                {
                    first_char = (UI_character_type)mmi_imc_key_send_message( MMI_IMC_MESSAGE_GET_CHAR_AT_DESIRED_POSITION, 0, 0 );
                    if (first_char == (UI_character_type) '-')
                    {
                        /* negative to positive */
                        ret = (MMI_BOOL)mmi_imc_key_send_message( MMI_IMC_MESSAGE_DELETE_CHAR_AT_DESIRED_POSITION, 0, 0 );
                    }
                    else
                    {
                        ret = (MMI_BOOL)mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR_AT_DESIRED_POSITION, 0, (UI_character_type) '-' );
                    }
                }
                else if (curr_mode == IMM_INPUT_MODE_SIGNED_FLOAT_123)
                {
                    if (char_code == (UI_character_type)('.') || mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, (UI_character_type)('.')))
                    {
                        if (mmi_imm_test_input(&char_code, 1))
                        {
                            ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (UI_character_type)('.'), 0 );
                        }
                        else
                        {
                            UI_editor_play_tone_cannot_insert();
                        }
                    }
                }
                break;
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
                if (char_code == (UI_character_type)('*') || mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, (UI_character_type)('*')))
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (UI_character_type)('*'), 0 );
                }
                else if (char_code == (UI_character_type)('#') || mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, (UI_character_type)('#')))
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (UI_character_type)('#'), 0 );         
                }
                break;

            case IMM_INPUT_MODE_FLOAT_123:
                /* insert '.' if necessary */
                if (char_code == (UI_character_type)('.') || mmi_imm_qwerty_is_valid_character_by_mmi_key(g_imc_key.key_info.curr_mmi_key_code, (UI_character_type)('.')))
                {
                    ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, (UI_character_type)('.'), 0 );
                }
                break;

            default:
                if (mmi_imc_get_state() == MMI_IMC_STATE_INITIAL && char_code == 0x20)
                {
                    if (mmi_imm_test_input((UI_string_type)L" ", 1))
                    {
                        mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                    }
                }
                else if ((g_imc_key.key_info.curr_special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN) && char_code != 0 )
                {
                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        ret = (MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
                    }
                }
                else if (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_123_SYMBOLS
                    && g_imc_key.key_info.curr_mmi_key_code == KEY_PERIOD)
                {
                    char_code = L'.';

                    if (mmi_imm_test_input(&char_code, 1))
                    {
                        ret =(MMI_BOOL)mmi_imc_key_send_message( insert_msg, char_code, 0 );
                    }
                }
                break;
            }

            if (ret && insert_msg == MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR)
            {
                mmi_imc_set_state(MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP);
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
            }
        }
    }
    else if (event_type == KEY_EVENT_UP)
    {
        if (key_code == MMI_IMC_KEY_CONFIRM)
        {
            if (mmi_imc_get_state() == MMI_IMC_STATE_NUMERIC_PASSWORD_MULTITAP)
            {
                mmi_imc_cancel_timer();
                g_imc_key_inputbox_LSK_function();
            }
            else
            {	
                mmi_imc_select_candidate_from_candidate_box();
                mmi_imc_redraw_screen_by_state();
            }      
        }      
        else if (key_code == MMI_IMC_KEY_CHANGE_MODE)
        {
            mmi_imc_key_handle_mode_change_key();
        }
		else if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            mmi_imc_key_entry_symbol_picker();
        }
        else if (password_mode)
        {                        
            /* start timer to confirm the input. */
            mmi_imc_start_timer(MMI_IMC_KEY_MULTITAP_TIMER, mmi_imc_key_direct_input_password_confirm, mmi_imc_key_direct_input_password_confirm);
        }
    }
    else if (event_type == KEY_LONG_PRESS)
    {
        switch (key_code)
        {
        case MMI_IMC_KEY_SYMBOL_PICKER:
            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
            case IMM_INPUT_MODE_FLOAT_123:
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
            case IMM_INPUT_MODE_123:
                break;
            default:
                mmi_imc_key_entry_symbol_picker();
                break;
            }
            break;
        case MMI_IMC_KEY_CHANGE_MODE:
            switch (curr_mode)
            {
            case IMM_INPUT_MODE_SIGNED_123:
            case IMM_INPUT_MODE_SIGNED_FLOAT_123:
            case IMM_INPUT_MODE_FLOAT_123:
            case IMM_INPUT_MODE_KEYPAD_NUMERIC:
            case IMM_INPUT_MODE_123:
                break;
            default:
            #if defined(__MMI_IME_V3__)
				mmi_imc_show_inputmode_list();
			#else 
				mmi_imc_key_change_input_mode();
			#endif
                break;
            }
            break;
        case MMI_IMC_KEY_CLEAN:
                mmi_imc_delete_all();
                break;

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
        case MMI_IMC_KEY_CHANGE_LANGUAGE:
            mmi_imc_key_entry_change_language_screen();
            break;
#endif
        }    
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phone_number_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_key_phone_number_key_down_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phone_number_key_up_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_up_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_imc_key_phone_number_key_up_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phone_number_key_long_press_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_long_press_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_imc_key.key_info.ucs2_value!='0')
     { 
        return mmi_imc_key_phone_number_key_long_press_handler(key_code, event_type);
     } 
   else
        return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_phone_number_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phone_number_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return mmi_imc_key_phone_number_key_repeat_handler(key_code, event_type);

}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_get_mmi_key_code_of_symbol_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
S16 mmi_imc_key_get_mmi_key_code_of_symbol_key(mmi_imc_symbol_key_enum symbol_key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (symbol_key >= MMI_IMC_SYMB_KEY_0 && symbol_key <= MMI_IMC_SYMB_KEY_POUND)
    {
        return (symbol_key - MMI_IMC_SYMB_KEY_0 + KEY_0);
    }
    else if (symbol_key >= MMI_IMC_SYMB_KEY_A && symbol_key <= MMI_IMC_SYMB_KEY_Z)
    {
        return (symbol_key - MMI_IMC_SYMB_KEY_A + KEY_A);
    }
    else if (symbol_key == MMI_IMC_SYMB_KEY_PERIOD)
    {
        return KEY_PERIOD;
    }
    else
    {
        return KEY_INVALID;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_common_key_down_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_common_key_down_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 temp=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_XT9__
    temp = mmi_imc_handle_fn_key_in_smart_mode(key_code);
    if(temp == 1)
        return MMI_TRUE;
    else if(temp == 2)
        return MMI_FALSE;
#endif

    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_NEW_LINE)
        {
            if (mmi_imm_test_input((UI_string_type)L"\n", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }
        else if (key_code == MMI_IMC_KEY_CLEAR)
        {
            if (!mmi_imc_key_editor_empty())
            {
                if (!mmi_imc_key_send_message(MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED, 1, 0))
                {
                    mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                    mmi_imc_redraw_screen_by_state();
                }
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_change();
            }
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }
        break;

    case MMI_IMC_STATE_MULTITAP:
        if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_key_multitap_alphabetic_input_confirm();
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }

        break;


    case MMI_IMC_STATE_SMART_CANDIDATE :

        if (key_code == MMI_IMC_KEY_NEW_LINE)
        {
            if (mmi_imm_test_input((UI_string_type)L"\n", 1))
            {
                mmi_imc_key_smart_alphabetic_confirm_candidate();
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
                mmi_imc_redraw_screen_by_state();
                ret = MMI_TRUE;  
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }

#if defined __MMI_COSMOS_KEYPAD_BAR__ || defined  __MMI_COSMOS_KEYPAD_SLIDER__
        else if (key_code == MMI_IMC_KEY_RIGHT || 
            key_code == MMI_IMC_KEY_LEFT ||
            key_code == MMI_IMC_KEY_UP ||
            key_code == MMI_IMC_KEY_DOWN)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select);                            
            mmi_imc_redraw_screen_by_state();
			ret = MMI_TRUE; 
        }
#else
        else if (key_code == MMI_IMC_KEY_RIGHT)
        {
            mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
            mmi_imc_key_smart_alphabetic_insert_candidate(g_imc_key.global_data_ptr->cand_select); 
			mmi_imc_redraw_screen_by_state();
            ret = MMI_TRUE;  
        }
#endif
        break;

    default:
        break;
    }

    if (!ret)
    {
        if (key_code == MMI_IMC_KEY_SYMBOL_PICKER)
        {
            if (!(mmi_imc_is_symbol_picker_disable()
                || (mmi_imm_get_curr_input_mode() == IMM_INPUT_MODE_123
                && mmi_imm_get_curr_input_type() != IMM_INPUT_TYPE_NUMERIC_SYMBOL)||mmi_imm_get_curr_input_mode() ==IMM_INPUT_MODE_SIGNED_123||mmi_imm_get_curr_input_type() ==IMM_INPUT_TYPE_DECIMAL_NUMERIC))
            {
                mmi_imc_key_entry_symbol_picker();
            }
            ret = MMI_TRUE;
        }
        else if (key_code == MMI_IMC_KEY_NUM_LOCK)
        {
            ret = mmi_imc_key_qwerty_num_lock_change_input_mode();
        }
    }

    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_common_key_repeat_handler
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_common_key_repeat_handler(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mmi_imc_get_state())
    {
    case MMI_IMC_STATE_INITIAL:
        if (key_code == MMI_IMC_KEY_NEW_LINE)
        {
            if (mmi_imm_test_input((UI_string_type)L"\n", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_NEW_LINE, 0, 0);
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }
        else if (key_code == MMI_IMC_KEY_SPACE)
        {
            if (mmi_imm_test_input((UI_string_type)L" ", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, 0x20, 0);
                ret = MMI_TRUE;
            }
            else
            {
                UI_editor_play_tone_cannot_insert();
            }
        }
        break;
    default:
        break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_num_lock_change_input_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_num_lock_change_input_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imm_input_mode_enum current_mode = mmi_imm_get_curr_input_mode();
    mmi_imm_input_mode_enum next_mode = IMM_INPUT_MODE_NONE;
    U16 key_code;
    U16 key_event;
    mmi_imc_key_custom_value imc_key;
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_imm_is_change_input_mode_enabled())
    {
        return MMI_FALSE;
    }

    if (current_mode == IMM_INPUT_MODE_123_SYMBOLS
        || current_mode == IMM_INPUT_MODE_PHONE_NUMBER)
    {
        if (g_imc_key_num_lock_pre_input_mode != IMM_INPUT_MODE_NONE
            && g_imc_key_num_lock_pre_input_mode != IMM_INPUT_MODE_123_SYMBOLS
            && g_imc_key_num_lock_pre_input_mode != IMM_INPUT_MODE_PHONE_NUMBER)
        {
            next_mode = g_imc_key_num_lock_pre_input_mode;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        if (mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_123_SYMBOLS))
        {
            next_mode = IMM_INPUT_MODE_123_SYMBOLS;
        }
        else if (mmi_imm_is_curr_allow_input_mode(IMM_INPUT_MODE_PHONE_NUMBER))
        {
            next_mode = IMM_INPUT_MODE_PHONE_NUMBER;
        }
        else
        {
            return MMI_FALSE;
        }
    }

    mmi_imc_gdi_lcd_freeze(MMI_TRUE);

    mmi_imc_cancel_timer();

    /* In canceling timer, input mode may be changed by WCSS */
    if (current_mode != mmi_imm_get_curr_input_mode())
    {
        if (mmi_imm_set_current_input_mode(current_mode) == MMI_FALSE)
        {
            mmi_imc_gdi_lcd_freeze(lcd_freeze);
            mmi_imc_repaint_screen();
            return MMI_FALSE;
        }
    }

    mmi_imc_key_get_current_key_info((PU16)(&key_code), (PU16)(&key_event));
    imc_key =  mmi_imc_key_custom_mapping((mmi_keypads_enum)key_code);

    switch (mmi_imc_get_state())
    {
    case MMI_IMC_STATE_MULTITAP:
        if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);            
        }
        else
        {
            mmi_imc_key_multitap_alphabetic_input_confirm();
        }
        break;
    case MMI_IMC_STATE_ASSOC_SELECTING_ALPHABETIC:
    case MMI_IMC_STATE_SMART_CANDIDATE:
        if (g_imc_key.key_check_funcptr(mmi_imm_get_curr_input_mode(),imc_key))
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_CLEAR_HILIGHT, 0, 0);
            mmi_imc_key_smart_alphabetic_delete_candidate();
        }
        else if (mmi_imc_key_smart_alphabetic_can_candidate_be_confirmed_by_interrupt())
        {
            mmi_imc_key_smart_alphabetic_confirm_candidate();
        }
        break;
#if defined(__MMI_IME_USER_DATABASE__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)	
    case MMI_IMC_STATE_NEW_WORD_MULTITAP:
        mmi_ime_multitap_confirm();
        break;
#endif
    default:
        break;
    }

    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);

    if (next_mode == IMM_INPUT_MODE_NONE)
    {
        if (mmi_imc_change_input_mode(mmi_imm_get_next_mode(), 0))
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
        }
    }
    else
    {
        mmi_imm_set_current_input_mode(next_mode);

        if (mmi_imc_change_input_mode(next_mode, 0))
        {
            mmi_imc_key_send_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
        }

        if (next_mode == IMM_INPUT_MODE_123_SYMBOLS
            || next_mode == IMM_INPUT_MODE_PHONE_NUMBER)
        { 
            /* We will reset g_imc_key_num_lock_pre_input_mode in mmi_imc_key_change_mode() */
            /* So we can only preserve the previous input mode after changing input mode */
            g_imc_key_num_lock_pre_input_mode = current_mode; 
        }
    }

    mmi_imc_redraw_screen_by_state();

    mmi_imc_gdi_lcd_freeze(lcd_freeze);
    mmi_imc_repaint_screen();

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_confirm_word_callback
 * DESCRIPTION
 *	confirm word and set the state to be initial
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_imc_key_confirm_word_callback(void)
{
 /* NEED TO MOVE THIS TO IMC */

#ifdef __MMI_CLIPBOARD__
    if (mmi_imc_is_clipboard_state())
    {
        mmi_imc_clipboard_go_back_to_initial();
    }
    else
#endif
	{
    mmi_imc_key_smart_alphabetic_confirm_candidate();
    mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
	}
    mmi_imc_redraw_screen_by_state();    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_imc_key_set_shift_caps
 * DESCRIPTION
 * change the word engine case according to special key status
 * PARAMETERS
 * special_key		[IN]		current special key status:
 *								MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT
 *
 * lock				[IN]		TRUE OR FALSE
 * RETURNS
 *****************************************************************************/
static void mmi_imc_key_set_shift_caps(U32  special_key, MMI_BOOL  lock)
{

  /*----------------------------------------------------------------*/
  /* Local Variables                                                */
  /*----------------------------------------------------------------*/
	static mmi_ime_word_capital_state_enum pre_capital_state = MMI_IME_WORD_CAPITAL_STATE_NONE;
	const sIMEModeDetails * mode_detail;
	U16         mode_attr;
	mode_attr = g_imc_key.curr_mode_details->Mode_Special_Attrib;
	 
  /*----------------------------------------------------------------*/
  /* Code Body                                                      */
  /*----------------------------------------------------------------*/
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	mmi_imm_config_special_key_validation(mmi_imm_get_input_mode_array_item(mmi_imm_get_curr_input_mode()));
	if((mmi_frm_qwerty_get_invalid_customized_special_key() & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT))
	{
		return;
	}
#endif
#if defined(__MMI_CSTAR__)
	
	if (special_key == MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT)
	{	
		/* Abc */
  		if (!lock)
		{	mmi_imc_key_confirm_word_callback();
			mmi_ime_word_change_word_case(MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER);
			g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
			mode_detail = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(),MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER);
			mmi_imm_set_current_input_mode(mode_detail->imm_mode_id);
			pre_capital_state = MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER;
			return ;
		}
		/* ABC */
		else
		{   mmi_imc_key_confirm_word_callback();          
			mmi_ime_word_change_word_case(MMI_IME_WORD_CAPITAL_STATE_UPPER);
			g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
			mode_detail = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(),MMI_IME_WORD_CAPITAL_STATE_UPPER);
			mmi_imm_set_current_input_mode(mode_detail->imm_mode_id);
			pre_capital_state = MMI_IME_WORD_CAPITAL_STATE_UPPER;
			return ;
		}
	}
	if ( special_key !=  MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_SHIFT && pre_capital_state != MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER && (mode_attr& IME_MODE_ATTR_SMART))
    {
		mmi_imc_key_confirm_word_callback();
        mmi_ime_word_change_word_case(MMI_IME_WORD_CAPITAL_STATE_LOWER);
		g_imc_key.global_data_ptr->capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
		mode_detail = mmi_imm_get_corresponding_mode_by_mode_and_capital_state(mmi_imm_get_curr_input_mode(),MMI_IME_WORD_CAPITAL_STATE_LOWER);
		mmi_imm_set_current_input_mode(mode_detail->imm_mode_id);
		pre_capital_state = MMI_IME_WORD_CAPITAL_STATE_LOWER;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_special_key_flag_change_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_qwerty_special_key_flag_change_callback(U32 special_key_flag, U32 special_key_lock_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_IME_PLUG_IN__
    mmi_ime_sdk_special_key_status_struct special_key_status;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imm_set_special_key_icon(special_key_flag, special_key_lock_flag);
#if defined (__MMI_XT9__)
    /* Need to set the special flags in xT9 mode*/
    if ((mmi_imc_get_state()==MMI_IMC_STATE_SMART_CANDIDATE)||(mmi_imc_get_state()==MMI_IMC_STATE_INITIAL))
    {
        mmi_ime_word_set_shift_caps(special_key_flag, special_key_lock_flag);
    }
#endif
    if (!g_imc_key_special_key_hint_redrawing_flag)
    {
        gui_start_timer(0, mmi_imc_key_qwerty_special_key_status_update_timer_callback); /* Can not use mmi_imc_start_timer() */
        g_imc_key_special_key_hint_redrawing_flag = MMI_TRUE;
    }
#if defined(__MMI_IME_V3__) && defined (__MMI_CSTAR__)
	mmi_imc_key_set_shift_caps(special_key_flag, special_key_lock_flag);
#endif

#ifdef __MMI_IME_PLUG_IN__
    special_key_status.special_key_flag = special_key_flag;
    special_key_status.special_key_lock_flags = special_key_lock_flag;

    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_SPECIAL_KEY_STATUS_CHANGED, (U32)&special_key_status, 0);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_special_key_status_update_timer_callback
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static void mmi_imc_key_qwerty_special_key_status_update_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_imc_key_special_key_hint_redrawing_flag && mmi_imc_is_connected())
    {
        mmi_imc_redraw_ime_indicator();

        g_imc_key_special_key_hint_redrawing_flag = MMI_FALSE;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_imc_key_qwerty_multitap_is_symbol_key
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_multitap_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_imc_key_is_key_symbol(key_code))
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
*  mmi_imc_key_qwerty_phonetic_fn_input_symbol
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static MMI_BOOL mmi_imc_key_qwerty_phonetic_fn_input_symbol(mmi_imc_key_custom_value key_code, U16 event_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_code == MMI_IMC_KEY_FN && mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
    {
        mmi_imc_gdi_lcd_freeze(MMI_TRUE);
        mmi_imc_cancel_timer();
        g_imc_key.spell_multitap_index = -1;
        mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
        mmi_imc_redraw_screen_by_state();
        mmi_imc_gdi_lcd_freeze(lcd_freeze);
        mmi_imc_repaint_screen();
        return MMI_TRUE;
    }   
    else if ((special_key_flag & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
        && ucs2_value != 0)
    {
#if defined(__MMI_TOUCH_SCREEN__)
        if(mmi_imc_get_state() == MMI_IMC_STATE_HAND_WRITING_CAND)
        {
            mmi_imc_pen_confirm_handwriting_selection(); 
        }
#endif

        if (mmi_imm_test_input(&ucs2_value, 1))
        {
            if (mmi_imc_get_state() != MMI_IMC_STATE_INITIAL)
            {
                mmi_imc_gdi_lcd_freeze(MMI_TRUE);
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, ucs2_value, 0);
                mmi_imc_set_state(MMI_IMC_STATE_INITIAL);
                mmi_imc_redraw_screen_by_state();
                mmi_imc_gdi_lcd_freeze(lcd_freeze);
                mmi_imc_repaint_screen();
            }
            else
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, ucs2_value, 0);
            }

            return MMI_TRUE;
        }
    }
    else if (key_code == MMI_IMC_KEY_RIGHT || 
                key_code == MMI_IMC_KEY_LEFT ||
                key_code == MMI_IMC_KEY_UP ||
                key_code == MMI_IMC_KEY_DOWN)
            {
                mmi_imc_key_common_arrow_key_handler(key_code, event_type);                
                mmi_imc_redraw_screen_by_state();
                return MMI_TRUE; 
           }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  mmi_imc_handle_fn_key_in_smart_mode
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
static S32 mmi_imc_handle_fn_key_in_smart_mode(mmi_imc_key_custom_value key_code)
{
    /* passing to xt9 adaptation for smart input function key */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 symbol = 0x20;
    S32 ret = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined __MMI_XT9__

    if ( key_code >= MMI_IMC_KEY_SYM_A && key_code <= MMI_IMC_KEY_SYM_PERIOD )
    {
        if(  (IMG_IME_QWERTY_FN_LOCK == mmi_imm_get_special_key_icon() ) || (IMG_IME_QWERTY_FN == mmi_imm_get_special_key_icon()) )
            /* we need to directly insert the common symbol */           
        {

            symbol = mmi_imm_qwerty_get_translated_key_code_of_current_lang( mmi_imc_key_get_mmi_key_code_of_symbol_key(key_code + MMI_IMC_SYMB_KEY_A - MMI_IMC_KEY_SYM_A ),MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN);
            if (mmi_imm_test_input((UI_string_type)L"0", 1))
            {
                mmi_imc_key_send_message(MMI_IMC_MESSAGE_INSERT_CHAR, symbol, 0);
                return 1; //MMI_TRUE/* this is to signify that we cannot insert but have consumed the key so no need to forward to specific handlers */
            }   
            else
            {
                UI_editor_play_tone_cannot_insert();
                return 2;   //MMI_FALSE
            }
        }
    }
#endif
	return ret;
}

#endif /* #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ */


