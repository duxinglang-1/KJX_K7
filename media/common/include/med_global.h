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
 * med_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global definitions of media task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT
#ifndef _MED_GLOBAL_H
#define _MED_GLOBAL_H

#if !defined(MED_MEM_CHECK)
#include "kal_release.h"
#include "kal_general_types.h"
#include "fs_type.h"
#endif

#include "lcd_Sw_inc.h"

#include "jpeg_mem.h"
#include "cal_mem_def.h"
#include "drv_sw_features_mdp.h"

#if defined(__VIDEO_ARCHI_V2__)
#include "video_memory_usage_v2.h"
#endif
#include "media_provider_mem_usage.h"
#include "media_session_mem_usage.h"
#include "cal_feature_option.h"
/* for Catcher to inject test messages */
#define TST_HANDLER
/* for vm logging */
// #define VM_LOG

#define MAXOF(a,b) (((a)>(b))? (a):(b))
#define MINOF(a,b) (((a)<(b))? (a):(b))

#ifdef  AUD_REC_ENABLE
#define __AUD_REC_INTENSITY__
#endif

#ifdef __CLKG_DEFINE__
#define __MM_POWER_CTRL__
#endif

#ifdef __MEDIA_VT__
/* under construction !*/
#endif

#if defined(__MTV_SUPPORT__)
#define __MED_MTV_MOD__
#endif

#if defined(__ATV_SUPPORT__)
#define __MED_ATV_MOD__
#endif


#ifdef __CTM_SUPPORT__
#define __MED_CTM_MOD__
#endif 

#ifdef __ECALL_SUPPORT__
#define __MED_ECALL_MOD__
#endif


#if defined( __BT_HFG_PROFILE__ )
#define __MED_BT_HFP_MOD__

#if defined(__BT_AUDIO_VIA_SCO__)
#define __MED_BT_AUDIO_VIA_SCO__
#endif

#if defined(__BT_FM_VIA_SCO__)
#define __MED_BT_FM_VIA_SCO__
#endif

#endif /* #if defined( __BT_HFG_PROFILE__ ) */

#if defined(__BT_A2DP_PROFILE__)
#define __MED_BT_A2DP_MOD__
#endif 

#if defined(__MED_BT_HFP_MOD__) || defined(__MED_BT_A2DP_MOD__)
#define __MED_BT_MOD__
#endif 

#ifdef __MED_IMY_EVENT__
#if defined(PLUTO_MMI)
#define __MMI_SUPPORT_BACKLIGHT_SYNC__
#define __MMI_SUPPORT_LED_SYNC__
#define __MMI_SUPPORT_VIBRATOR_SYNC__
#elif defined(NEPTUNE_MMI)
#define __MMI_SUPPORT_BACKLIGHT_SYNC__
#define __MMI_SUPPORT_VIBRATOR_SYNC__
#endif /* defined(PLUTO_MMI) */ 
#endif /*__MED_IMY_EVENT__*/

#if defined(PLUTO_MMI) || defined(EXTERNAL_MMI)
#define __16_LEVEL_AUDIO_VOLUME__
#endif

#if defined(__POC__)
#define __MED_POC_MOD__
#endif 

#if (defined(__INTEGRATED_PLAYER__) || defined(__INTEGRATED_PLAYER_DB_VF__) || defined(__INTEGRATED_PLAYER_FTE_DB__) || defined(__INTEGRATED_PLAYER_DB__) || defined(__COSMOS_MUSICPLY__))
#define __META_DATA_PARSE_SUPPORT_ID3V1__
#endif

#if !defined(NEPTUNE_MMI)
#ifndef __RICH_AUDIO_PROFILE__
#define __RICH_AUDIO_PROFILE__
#endif
#endif

#if defined(__RICH_AUDIO_PROFILE__) /* (1)Spectrum (2)Build Cache, (3)ID3 Parser */
/*
*   BEG:ADD META DATA PARSER COMPILE OPTION
*/
#define __META_DATA_PARSE_SUPPORT_ID3V2__
#define __META_DATA_PARSE_SUPPORT_APE__
#define __META_DATA_PARSE_SUPPORT_LYRICS_EXT__
/*
*   AUDIO DRIVER CAN PARSER AUDIO INFORMATION FROM RAW DATA HEADER
*   AND DRIVER WILL DO DEFAULT PARSER FOR TWO META DATA FORMAT 
*       UDTA: USER DATA BOX USED IN MP4/3GP
*       WM:   WINDOWS META FORMAT  
*/
#define __META_DATA_PARSE_SUPPORT_DRIVER__  

#if defined (__DRM_SUPPORT__)
#define __META_DATA_PARSE_SUPPORT_DCF__     /*DRM META DATA*/
#endif

#if defined(__META_DATA_PARSE_SUPPORT_ID3V2__) || \
    defined(__META_DATA_PARSE_SUPPORT_ID3V1__) || \
    defined(__META_DATA_PARSE_SUPPORT_APE__) || \
    defined(__META_DATA_PARSE_SUPPORT_DCF__) || \
    defined(__META_DATA_PARSE_SUPPORT_DRIVER__) 
#define __META_DATA_PARSE_API__

#endif
/*
*   END:ADD META DATA PARSER COMPILE OPTION 
*/
#endif /* __RICH_AUDIO_PROFILE__ */

#if defined(AMR_CODEC)
#define AMR_DECODE
#endif 

/* Apply slim audio profile for Neptune MMI only */
#if defined(MED_LOW) || defined(MED_MODEM)
#if defined(NEPTUNE_MMI)
#define SLIM_AUDIO_PROFILE
#endif
#endif 

#if defined(PURE_AUDIO_SUPPORT)
#define MED_PURE_AUDIO
#endif

#if defined(MED_PURE_AUDIO) || defined(__RM_DEC_SUPPORT__) || defined(M4A_DECODE) || defined(__FLV_FILE_FORMAT_SUPPORT__)
#define __MED_MPL_PLAYER__
#endif

#if defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)
#define __MED_CAM_MOD__

#ifdef WEBCAM_SUPPORT
#define __MED_WEBCAM_MOD__
#endif 

#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#define __MED_CAM_XENON_FLASH_SUPPORT__
#endif

#ifndef __LOW_COST_SUPPORT_COMMON__
#define __MED_CAM_BUSTSHOT_SUPPORT__
#endif

#ifdef __CAL_CAPTURE_MODE_BSS_SUPPORT__
#define __MED_CAM_BESTSHOT_SUPPORT__
#endif

#ifdef __CAL_CAPTURE_MODE_EV_BRACKET_SUPPORT__
#define __MED_CAM_EV_BRACKET_SUPPORT__
#endif

#if defined(__AUTOCAP_PANORAMA_SUPPORT__)
#define __MED_CAM_PANORAMA_VIEW_SUPPORT__
#endif

#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#define __MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__
#endif

#if defined(__3D_IMAGE_SUPPORT__)
#define __MED_CAM_3D_IMAGE_SUPPORT__
#endif

#if defined(__CAMERA_GYRO_SUPPORT__)
#define __MED_CAM_CAMERA_GYRO_SUPPORT__
#endif

#ifdef __HIGH_DYNAMIC_RANGE_SUPPORT__
#define __MED_CAM_HDR_SUPPORT__
#endif

#if defined(__MED_CAM_BUSTSHOT_SUPPORT__) || defined(__MED_CAM_BESTSHOT_SUPPORT__) || defined(__MED_CAM_EV_BRACKET_SUPPORT__) || defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__)
#define __MED_CAM_MUTILSHOT_SUPPORT__
#endif

#if defined(__FACE_DETECTION_SUPPORT__)
#define __MED_CAM_FD_SUPPORT__
#endif

#if defined(AF_SUPPORT)
#define __CAM_AUTO_FOCUS__
#endif 

#ifndef __LOW_COST_SUPPORT_COMMON__
#define __MED_CAM_PROFILING_SUPPORT__
#define __MED_CAM_GET_PREDICT_IMGSIZE_SUPPORT__
#endif

#ifndef __LOW_COST_SUPPORT_ULC__
#define __MED_CAM_GET_BUFFER_CONTENT_SUPPORT__
#endif

#endif /* defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__) */ 

#if defined(TV_OUT_SUPPORT)
#define __MED_TVO_MOD__
#endif 

#if defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE)
// no longer used after 11A
//#define __MED_IMG_MOD__
#endif 

#if defined (MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__) || defined(__FLV_FILE_FORMAT_SUPPORT__) || defined(MP4_ENCODE) || defined(MJPG_ENCODE)
    #define __MED_VID_MOD__

    #if defined (MP4_DECODE) || defined(MJPG_DECODE) || defined(__RM_DEC_SUPPORT__) || defined(__FLV_FILE_FORMAT_SUPPORT__)
        #define __MED_VID_DEC_MOD__
        #ifdef PGDL_SUPPORT
            #define __MED_VID_PDL_MOD__
        #endif
    #endif

    #if (defined (MP4_ENCODE) || defined(MJPG_ENCODE)) && (defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__))
        #define __MED_VID_ENC_MOD__
    #endif



#endif



#if defined(DSP_WT_SYN)
    /* For play midi, imelody*/
    #define __MED_DSP_WT_SYN__

    /* Multiple player control, not used in neptune project */
    #if !defined(NEPTUNE_MMI)
        #define __MED_MMA_MOD__

        #if defined(__J2ME__)
            #define __MED_MMA_EXTRA_CTRL__ /* Extra MMA control for Midi, tone */
        #endif
    #endif
#endif

#if defined (FM_RADIO_ENABLE)
#define __MED_FMR_MOD__
#endif 

#if defined(AUD_REC_ENABLE)
#define __MED_AUD_REC_MOD__
#endif 

#if !defined(FMT_NOT_PRESENT)
#define __MED_AUD_FS_ACCESS__   /*Can playback audio from file system */
#endif 

#if defined(VR_ENABLE)
#define __MED_VR_MOD__
#endif 

#if defined(VRSI_ENABLE)
#define __MED_VRSI_MOD__
#endif 

#if defined(BGSND_ENABLE)
#define __MED_SND_MOD__
#endif 

#if defined(__BES_TS_SUPPORT__)
#define __MED___BES_TS_SUPPORT____
#endif

#if defined(__BES_LIVE_SUPPORT__)
#define __MED___BES_LIVE_SUPPORT____
#endif

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
#define __MED_AUD_SURROUND__
#endif

#if defined(__BES_EQ_SUPPORT__)
#define __MED_AUD_EQUALIZER__
#endif

#if defined(__BES_BASS_SUPPORT__)
#define __MED_AUD_BASS_ENHANCE__
#endif

#if defined(__BES_LOUDNESS_SUPPORT__)
#define __MED_AUD_LOUDNESS__
#endif

/* Either turn on (1)time stretch (2)reverb (3)3D surround (4)equalizer (5) bass enhancement (6) loudness*/
#if defined(__BES_TS_SUPPORT__) || defined(__BES_LIVE_SUPPORT__) || defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) || defined(__BES_EQ_SUPPORT__) || defined(__BES_BASS_SUPPORT__) || defined(__BES_LOUDNESS_SUPPORT__)
#define __MED_AUD_AUDIO_EFFECT__
#endif

#ifdef DEDI_AMR_REC
#define DEDI_AMR_REC_BUFFER
#endif 

#if defined (__POC__) || defined (STREAM_SUPPORT) || defined (__VOIP__)
#define __MED_RTP_MOD__
#endif 

#if defined(STREAM_SUPPORT)
#define __MED_STREAM_MOD__
    #if defined(__VIDEO_ARCHI_V2__)
    #define __MED_STREAM_DEPACK__
    #endif
    #if defined(__VIDEO_ARCHI_V2__) && defined(__MED_STREAM_DEPACK__)
        #define __MED_STREAM_WITH_V2__
    #endif

    #if defined(__H264_DEC_HW_SUPPORT__) || defined(__H264_DEC_SW_SUPPORT__)
        #ifndef __STREAM_H264_SUPPORT__
            #define __STREAM_H264_SUPPORT__
        #endif
    #endif    
#endif  /* defined(STREAM_SUPPORT) */

#if defined(__BITSTREAM_API_SUPPORT__)
#define __MED_BITSTREAM_MOD__
#endif /* __BITSTREAM_API_SUPPORT__ */

#if defined(__GENERAL_TTS__)
#define __MED_GENERAL_TTS__
#endif

#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#define __MED_MEM_CACHEABLE_SUPPORT__
#endif

#ifdef __STREAM_REC_SUPPORT__
#define __STREAM_REC_MOD__
#endif

#define SET_VOLUME_WHEN_PLAY

#define  AUD_IDLE  0

#define  AUD_VM_IDLE                0
#define  AUD_VM_RECORD              1

/* audio state */
#define  AUD_MEDIA_IDLE             0
#define  AUD_MEDIA_PLAY             30
#define  AUD_MEDIA_PLAY_PAUSED      32

#define  AUD_MEDIA_RECORD           33
#define  AUD_MEDIA_RECORD_PAUSED    34
#define  AUD_MEDIA_SEEK_PAUSED      35

#define  AUD_MEDIA_UNDERFLOW        36
#define  AUD_MEDIA_WAIT_RECORD      39


/* audio post process state */
#define  AUD_EFFECT_UNSET     0 /* Parameter not set */
#define  AUD_EFFECT_OFF    1
#define  AUD_EFFECT_ON        2
//#define  AUD_EFFECT_INT       3 /* Interrupt */

/* camera state */
#define CAM_IDLE                0
#define CAM_READY               1
#define CAM_PREVIEW             2
#define CAM_CAPTURE             3
#define CAM_HDR                 4
#define CAM_MAV                 5


/* image state */
#define IMG_IDLE        0
#define IMG_JPG_DECODE      1
#define IMG_JPG_ENCODE      2
#define IMG_GIF_DECODE       3
#define IMG_GIF_V2_DECODE 4
#define IMG_PNG_DECODE     5


typedef enum {
    VID_IDLE,
    VID_PREVIEW,
    VID_RECORD,
    VID_RECORD_FINISH,
    VID_RECORD_PAUSED,
    VID_OPEN_FILE,
    VID_FILE_READY,
    VID_PLAY_INIT,
    VID_PLAY,
    VID_AUDIO_PLAY_FINISH,
    VID_AUDIO_PLAY_ERROR,
    VID_VISUAL_PLAY_FINISH,
    VID_PLAY_PAUSED,
    VID_FILE_MERGE,
    VID_SEEK,
    VID_PLAY_STOP_VISUAL,
    VID_RECORD_STOP_VISUAL,
    VID_DELAY_OPEN,
    VID_RECORD_ABORTING,
    VID_PLAY_ABORTING,
    VID_START_PREVIEW,
    VID_FILE_MERGE_STOPPING,
    VID_PDL_META_BUFFERING,
    VID_VIDEO_PLAY_UNDERFLOW,
    VID_EDITOR_FILE_MERGE,
    VID_EDITOR_MERGE_STOPPING,
    VID_RECORD_UPDATE_BLT_PAUSED,
    VID_RECORD_UPDATE_BLT_PAUSED_ASYNC,
    VID_PLAY_CLOSE_VISUAL,
    VID_READY
} vid_state_enum;

typedef enum {
    VID_AUD_IDLE,
    VID_AUD_PLAY_NORMAL,
    VID_AUD_PLAY_HIGH_SPEED,
    VID_AUD_PLAY_DUMMY,
    VID_AUD_RECORD,
    VID_AUD_RECORD_PAUSED,
    VID_AUD_PLAY_UNDERFLOW
} vid_aud_state_enum;


/* Web camera state */
#define WEBCAM_IDLE             0
#define WEBCAM_START_PREVIEW    1
#define WEBCAM_PREVIEW          2
#define WEBCAM_CAPTURE          3
#define WEBCAM_PAUSING          4
#define WEBCAM_PAUSED           5
#define WEBCAM_STOPPING         6
#define WEBCAM_PAUSE_CONNECT    7

/* TV output state */
#define TVO_IDLE        0
#define TVO_DETECTION  1
#define TVO_READY      2
#define TVO_UPDATE      3

#define INVALID_VM_ID      255
#define MAX_FILE_NAME_LEN  261
#define MAX_VM_LOG_LEN  (200*1024)
#define IMY_DEFAULT_INSTRUMENT   74     /* Flute */

/******************************************************
 * 1. Audio static ring buffer (2 bytes per unit)
 ******************************************************/
#ifdef SLIM_AUDIO_PROFILE
      #define AUD_RING_BUFFER_LEN     (2304)  /*4608*/
#else /* SLIM_AUDIO_PROFILE */
    #if !defined(__LOW_COST_SUPPORT_COMMON__)
        #define AUD_RING_BUFFER_LEN     (32*1024) /* 64k */
    #else
        #define AUD_RING_BUFFER_LEN     (8*1024)  /* 16k */
    #endif
#endif /* SLIM_AUDIO_PROFILE */

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)
    #define VID_RING_BUFFER_LEN         (16*1024) /* 32k */
#else
    #define VID_RING_BUFFER_LEN         (0)
#endif

/* Determine MED ring buffer length (2 bytes per unit) */
#if VID_RING_BUFFER_LEN > AUD_RING_BUFFER_LEN
    #define MED_RING_BUFFER_LEN (VID_RING_BUFFER_LEN)
#else
    #define MED_RING_BUFFER_LEN (AUD_RING_BUFFER_LEN)
#endif

/* Define ring buffer size (1 byte per unit) */
#define AUD_RING_BUFFER_SIZE (AUD_RING_BUFFER_LEN * 2)
#define VID_RING_BUFFER_SIZE (VID_RING_BUFFER_LEN * 2)
#define MED_RING_BUFFER_SIZE (MED_RING_BUFFER_LEN * 2)

#if defined(MED_PURE_AUDIO) || defined(M4A_DECODE)
#define MED_MP4_RING_BUFFER_SIZE MP4_MP_AUDIO_MEM_SIZE
#else
#define MED_MP4_RING_BUFFER_SIZE 0
#endif

/******************************************************
 * 2. Audio Feature (No background play)
 ******************************************************/
/* VRSD */
#if defined(__MED_VR_MOD__)
    #define AUD_MED_VRSD_EXT_MEM_SIZE (19*1024) /* Actual 19232 bytes */
#else
    #define AUD_MED_VRSD_EXT_MEM_SIZE (0)
#endif

/* VRSI */
#if defined(VRSI_ENABLE)
    #define AUD_MED_VRSI_EXT_MEM_SIZE (450*1024)
#else
    #define AUD_MED_VRSI_EXT_MEM_SIZE (0)
#endif

/* CTM */
#if defined(__MED_CTM_MOD__)
    #define AUD_MED_CTM_EXT_MEM_SIZE (9*1024)  /* Actual: 8184(Driver) + 61(MED) bytes */
#else
    #define AUD_MED_CTM_EXT_MEM_SIZE (0)
#endif

/* VM : for VM record ring buffer */
#if __VM_CODEC_SUPPORT__
    #define AUD_MED_VM_EXT_MEM_SIZE (12*1024)  /* 12K bytes */
#else
    #define AUD_MED_VM_EXT_MEM_SIZE (0)
#endif

/******************************************************
 * 3. Audio MED (Background Play)
 ******************************************************/
#ifndef MMA_MAX_NUM
    #define MMA_MAX_NUM        (12)
#endif /* MMA_MAX_NUM */

#if defined(LOW_COST_SUPPORT)
    #define AUD_PROC_BUF_SIZE  (512)
#else
    #define AUD_PROC_BUF_SIZE  (1024)
    #define AUD_PROC_USE_EXT_MEM /* Use external memory as proc buffer */
#endif

 /* Buffer for playing imelody from file. Size config in make file */
#define AUD_MELODY_BUFFER_LEN (MAX_MELODY_BUF_LEN)

 /* Maximum size for midi file playback. Size config in make file */
#if defined(MAX_MIDI_FILE_SIZE)
    #define AUD_MIDI_FILE_SIZE (MAX_MIDI_FILE_SIZE)
#else
    #define AUD_MIDI_FILE_SIZE (2*1024*1024) /* 2M */
#endif

 /* Buffer for audio driver to process midi files */
#if defined(__MED_DSP_WT_SYN__)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_SMF_WORKING_BUF (6*1024)
        #define AUD_SMF_WORKING_SYN_BUF (24*1024)
    #else
        #define AUD_SMF_WORKING_BUF (1600)
        #define AUD_SMF_WORKING_SYN_BUF (0)
    #endif
#else
    #define AUD_SMF_WORKING_BUF (0)
    #define AUD_SMF_WORKING_SYN_BUF (0)
#endif

/* JWave */
#if MMA_MAX_NUM < 4
    #define MMA_WAV_MAX_NUM        MMA_MAX_NUM
    #define MMA_SMF_MAX_NUM        (0)
#else
    #define MMA_WAV_MAX_NUM        (4)
    #if MMA_MAX_NUM < 8
        #define MMA_SMF_MAX_NUM    (MMA_MAX_NUM-4)
    #else
        #define MMA_SMF_MAX_NUM    (4)
    #endif
#endif

#if defined(DSP_WT_SYN) && defined(__MED_MMA_MOD__)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_MMA_WAV_WORKING_BUF (28*1024*MMA_WAV_MAX_NUM) /* 60K (WAV+Mixer) * n instances */
    #else
        #define AUD_MMA_WAV_WORKING_BUF (48*54*MMA_WAV_MAX_NUM) /* Actual: 48(K sampling rate) * 54 * n instances */
    #endif
#else
    #define AUD_MMA_WAV_WORKING_BUF  (0)
#endif

/* JMidi */
#if defined(__MED_MMA_MOD__)
    #if defined(__AUD_SW_CODEC__)
        #if (MMA_MAX_NUM > MMA_WAV_MAX_NUM)
           #define AUD_MMA_SMF_WORKING_BUF (AUD_SMF_WORKING_BUF * (MMA_MAX_NUM-MMA_WAV_MAX_NUM) + AUD_SMF_WORKING_SYN_BUF) /* MIDIs+TONEs+IMYs - WAVs */
        #else
           #define AUD_MMA_SMF_WORKING_BUF (0)
        #endif
    #else
        #define AUD_MMA_SMF_WORKING_BUF (AUD_SMF_WORKING_BUF * MMA_SMF_MAX_NUM) /* Support 4 midi playback */
    #endif
#else
    #define AUD_MMA_SMF_WORKING_BUF (0)
#endif

/* Mixer */
#if defined(__MED_MMA_MOD__) && defined(__AUD_SW_CODEC__) && defined(__LOW_COST_SUPPORT_COMMON__)
    #define AUD_MMA_MIXER_WORKING_BUF (2*1024)
#else
    #define AUD_MMA_MIXER_WORKING_BUF (0)
#endif

/* General TTS */
#if defined(IFLY_TTS)
    #define AUD_MED_TTS_EXT_MEM_SIZE (156*1024)
#elif defined(CYBERON_DIC_TTS)
    #define AUD_MED_TTS_EXT_MEM_SIZE (86*1024)
#elif defined(SINOVOICE_TTS)
    #define AUD_MED_TTS_EXT_MEM_SIZE (186*1024)
#else
    #define AUD_MED_TTS_EXT_MEM_SIZE (0)
#endif

/* To play 3GP, MP4, M4A files with MPL player, this is the memory for container 
   other MPL formats will use MED memory */
#if defined(MED_PURE_AUDIO) || defined(M4A_DECODE)
    #define AUD_MED_MP4_PARSER_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MP4_MP_CORE_MEM_SIZE)
#else
    #define AUD_MED_MP4_PARSER_MEM_SIZE (0)
#endif

/* Auto build cache (10A afterward) */
#if !defined(MED_V_NOT_PRESENT)
    #if defined(LOW_COST_SUPPORT)
        #define AUD_MED_BUILD_CACHE_BUF_SIZE (4096)
    #else
        #define AUD_MED_BUILD_CACHE_BUF_SIZE (16384)
    #endif
        #define AUD_MED_BUILD_CACHE_NORMAL_BUF_SIZE (16384)
#else
    #define AUD_MED_BUILD_CACHE_BUF_SIZE (0)
#endif

/* MPL players/recorders (10A afterward) */
#if defined(SLIM_AUDIO_PROFILE) || !defined(__MED_MMA_MOD__)
    #define AUD_MED_MPL_OBJ_BUF_SIZE (256)
#else
    #define AUD_MED_MPL_OBJ_BUF_SIZE (1024)
#endif

/* FS buffer (10A afterward) */
#if defined(AUD_PROC_USE_EXT_MEM)
    #define AUD_MED_PROC_BUF_SIZE (AUD_PROC_BUF_SIZE)
#else
    #define AUD_MED_PROC_BUF_SIZE (0) /* Use control buffer */
#endif

/******************************************************
 * 4. Audio Driver (Background Play)
 ******************************************************/
/* DSP code dynamically decompress */
#if defined(__DSP_COMPRESS_7Z__)
    #define AUD_DRV_DSP_EXT_MEM_SIZE (32*1024) /* DSP code 16KB, lzma working buffer 16KB */
    #define AUD_DRV_DSP_NR_EXT_MEM_SIZE (46*1024) /* DSP NR code 30KB, lzma working buffer 16KB */
  #if defined(WT20K)
    #define AUD_DRV_DSP_WT_EXT_MEM_SIZE (36*1024)
  #else
    #define AUD_DRV_DSP_WT_EXT_MEM_SIZE (32*1024)
  #endif
#else
    #define AUD_DRV_DSP_EXT_MEM_SIZE (0)
    #define AUD_DRV_DSP_NR_EXT_MEM_SIZE (0)
    #define AUD_DRV_DSP_WT_EXT_MEM_SIZE (0)
#endif

#if defined(__AUD_SW_CODEC__)
    #define AUD_DRV_DSP_EXT_MEM_SIZE_MP3 (0)
#else
    #define AUD_DRV_DSP_EXT_MEM_SIZE_MP3 AUD_DRV_DSP_EXT_MEM_SIZE
#endif

/* Will be concurrently used with audio codec */
#if defined(__BT_AUDIO_VIA_SCO__) || defined(__BT_A2DP_PROFILE__)
    #define AUD_DRV_BT_EXT_MEM_SIZE (16*1024) /* SCO/A2DP buffer: 16384 bytes */
#else
    #define AUD_DRV_BT_EXT_MEM_SIZE (0)
#endif

#if defined(__MCU_DTMF_SUPPORT__) && !defined( MED_MODEM )
    #define AUD_DRV_SW_DTMF_EXT_MEM_SIZE (8424) /*SW DTMF Working and Buffer memory : 8424 bytes*/
#else
    #define AUD_DRV_SW_DTMF_EXT_MEM_SIZE (0)
#endif

/* Currently only used in call, exclusively used with audio codec  */
#if defined(__MED_SND_MOD__)
    #define AUD_DRV_BGSND_EXT_MEM_SIZE (10*1024) /* Actual: 8321 bytes */
#else
    #define AUD_DRV_BGSND_EXT_MEM_SIZE (0)
#endif

#if defined(WAV_CODEC)
    #if defined(__AUD_SW_CODEC__)
        #if defined(__DRA_DECODE_SUPPORT__)
            #define AUD_DRV_WAV_EXT_MEM_SIZE (54*1024) /* 59300: dra playback */
        #else
            #define AUD_DRV_WAV_EXT_MEM_SIZE (19*1024) /* 22764: wav/pcm playback */
        #endif    
    #else
        #if defined(__DRA_DECODE_SUPPORT__)
            #define AUD_DRV_WAV_EXT_MEM_SIZE (77*1024) /* bitstream buffer: 1k + pcm buffer: 4k + pcm ring buffer: 32k + DRM working buffer: 40k */
        #else
            #define AUD_DRV_WAV_EXT_MEM_SIZE (0)
        #endif
    #endif
#else
    #define AUD_DRV_WAV_EXT_MEM_SIZE (0)
#endif /* WAV_CODEC */

#if defined(DAF_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_DAF_EXT_MEM_SIZE (49*1024)
    #elif defined(SLIM_AUDIO_PROFILE)
        #define AUD_DRV_DAF_EXT_MEM_SIZE (0)        
    #else
        #define AUD_DRV_DAF_EXT_MEM_SIZE (4608)
    #endif
#else
    #define AUD_DRV_DAF_EXT_MEM_SIZE (0)
#endif /* DAF_DECODE */

#if defined(__VORBIS_DECODE__)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_VORBIS_EXT_MEM_SIZE (101688)
    #elif defined(__VORBIS_DECODE_SLIM__)
        #define AUD_DRV_VORBIS_EXT_MEM_SIZE (51336)
#else
        #define AUD_DRV_VORBIS_EXT_MEM_SIZE (88064)
#endif
#else
    #define AUD_DRV_VORBIS_EXT_MEM_SIZE (0)
#endif /* __VORBIS_DECODE__ */

#if defined(__FLAC_DECODE__)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_FLAC_EXT_MEM_SIZE (88612)  /*parser+decoder*/
    #else
       #define AUD_DRV_FLAC_EXT_MEM_SIZE (0)
   #endif
#else
     #define AUD_DRV_FLAC_EXT_MEM_SIZE (0)
#endif


#if defined(__VORBIS_ENCODE__)
    #define AUD_DRV_VORBIS_RECORD_EXT_MEM_SIZE   (62020) /* VORBIS Record: 62020 bytes */
#else
    #define AUD_DRV_VORBIS_RECORD_EXT_MEM_SIZE   (0)
#endif /* VORBIS_ENCODE */

#if defined(AAC_PLUS_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_AAC_SBR_EXT_MEM_SIZE (36*1024) /* AAC + SBR = 43352 + 41396 = 84748 */
    #else
        #define AUD_DRV_AAC_SBR_EXT_MEM_SIZE (25*1024) /* Actual: 24968 bytes for SBR */
    #endif
#else
    #define AUD_DRV_AAC_SBR_EXT_MEM_SIZE (0)
#endif

#if defined(AAC_PLUS_PS_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_AAC_PS_EXT_MEM_SIZE (5*1024) /* AAC + SBR + PS = 43352 + 41396 + 4696 = 89444 */
    #else
        #define AUD_DRV_AAC_PS_EXT_MEM_SIZE (25*1024) /* Actual: 25560 bytes for PS */
    #endif
#else
    #define AUD_DRV_AAC_PS_EXT_MEM_SIZE (0)
#endif

#if defined(AWB_PLUS_DECODE)
    #define AUD_DRV_AWB_PLUS_EXT_MEM_SIZE (54*1024) /* Actual: 54328 bytes */
#else
    #define AUD_DRV_AWB_PLUS_EXT_MEM_SIZE (0)
#endif

#if defined(__APE_DECODE__)
    #define AUD_DRV_APE_EXT_MEM_SIZE (69*1024) /* Actual: 69656 bytes */
#else
    #define AUD_DRV_APE_EXT_MEM_SIZE (0)
#endif

#if defined(__I2S_INPUT_MODE_SUPPORT__) && !defined(__I2S_INPUT_MODE_WITHOUT_APM__)
    #if defined(__VORBIS_ENCODE__)
        #define AUD_DRV_I2S_EXT_MEM_SIZE (76452) /* vorbis encoding buffer: 16384 bytes + downsampler: 2144 bytes + vorbis encoder: 57924 bytes */
    #elif defined(__DAF_ENCODE__)
        #define AUD_DRV_I2S_EXT_MEM_SIZE (46492) /* MP3 working buffer: 16384 bytes + 3rd party library: 30108 bytes */
    #else
        #define AUD_DRV_I2S_EXT_MEM_SIZE (26952) /* I2S encoding buffer: 16384 bytes + downsampler: 2144 bytes + amr encoder: 8424 bytes */
    #endif
#elif defined(__I2S_INPUT_MODE_WITHOUT_APM__) && defined(__I2S_WAV_RECORD__)
    #define AUD_DRV_I2S_EXT_MEM_SIZE (4096)
#else
    #define AUD_DRV_I2S_EXT_MEM_SIZE (0)
#endif /* __I2S_INPUT_MODE_SUPPORT__ */

#if defined(AMR_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_AMR_PLAYBACK_EXT_MEM_SIZE (14*1024) /* AMR Playback: 15060 bytes */
        #define AUD_DRV_AMR_RECORD_EXT_MEM_SIZE   (10024) /* AMR Record: 10024 bytes */
    #else
        #define AUD_DRV_AMR_PLAYBACK_EXT_MEM_SIZE (0)     /* AMR Playback: 0 bytes */
        #if !defined(DYNAMIC_CODE_MANAGER) && defined(DEDI_AMR_REC_BUFFER)
            #define AUD_DRV_AMR_RECORD_EXT_MEM_SIZE (10024) /* AMR Record: 10024 bytes */
        #else
            #define AUD_DRV_AMR_RECORD_EXT_MEM_SIZE (0)
        #endif
    #endif
#else
    #define AUD_DRV_AMR_PLAYBACK_EXT_MEM_SIZE (0)
    #define AUD_DRV_AMR_RECORD_EXT_MEM_SIZE   (0)
#endif /* AMR_DECODE */

#if defined(AMRWB_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_AWB_EXT_MEM_SIZE (12*1024) /* AWB Playback: 13380 bytes */
    #else
        #define AUD_DRV_AWB_EXT_MEM_SIZE (0)
    #endif
#else
    #define AUD_DRV_AWB_EXT_MEM_SIZE (0)
#endif /* AMRWB_DECODE */

#if defined(AAC_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define AUD_DRV_AAC_EXT_MEM_SIZE (39*1024)
    #else
        #define AUD_DRV_AAC_EXT_MEM_SIZE (0)
    #endif
#else
    #define AUD_DRV_AAC_EXT_MEM_SIZE (0)
#endif /* AAC_DECODE */

/* APM */
#if defined(__BES_LIVE_SUPPORT__) || defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) || defined(AUD_VOCAL_REMOVAL) || defined(AUD_PITCH_SHIFTING) || defined(__TC01_OAEP_SUPPORT__)
   #define AUD_DRV_APM_LEVEL1_MEM_SIZE  (16724)
#elif defined(__BES_EQ_SUPPORT__) && !defined(__NON_SW_EQ_SUPPORT__)
   #define AUD_DRV_APM_LEVEL1_MEM_SIZE  (384+6144)
#else
   #define AUD_DRV_APM_LEVEL1_MEM_SIZE  (0)
#endif

#if defined(__BES_BASS_SUPPORT__)
   #define AUD_DRV_APM_LEVEL2_MEM_SIZE  (200+4096)
#else
   #define AUD_DRV_APM_LEVEL2_MEM_SIZE  (0)
#endif

#if defined(__AUDIO_ULTRA_SLIM__) && ( defined(__BT_AUDIO_VIA_SCO__) || defined(__BT_A2DP_PROFILE__) )
   // Restrict the concurrency of Loudness and BT
   #define AUD_DRV_APM_LEVEL3_MEM_SIZE  (0)
   #define AUD_DRV_APM_LEVEL4_MEM_SIZE  (0)
#elif defined(__BES_LOUDNESS_SUPPORT__) && !defined(__ACF_DSP_IIR_SUPPORT__)
   #define AUD_DRV_APM_LEVEL3_MEM_SIZE  (9608)
   #define AUD_DRV_APM_LEVEL4_MEM_SIZE  (0)
#else
   #define AUD_DRV_APM_LEVEL3_MEM_SIZE  (0)
   #if defined(__BT_AUDIO_VIA_SCO__)
      #define AUD_DRV_APM_LEVEL4_MEM_SIZE  (3200)
   #elif defined(__BT_A2DP_PROFILE__)
      #define AUD_DRV_APM_LEVEL4_MEM_SIZE  (1632)
   #else
      #define AUD_DRV_APM_LEVEL4_MEM_SIZE  (0)
   #endif
#endif

#if defined(__LOW_COST_SUPPORT_COMMON__) && (defined(__BT_AUDIO_VIA_SCO__) || defined(__AUD_SW_CODEC__)) && !defined(__AUDIO_ULTRA_SLIM__)
   #define AUD_DRV_APM_BLISRC_MEM_SIZE  (27*1024)
#else
   #define AUD_DRV_APM_BLISRC_MEM_SIZE  (0)
#endif

#if defined(__AUD_SW_CODEC__)
   #if defined(__BES_TS_SUPPORT__)
      #define AUD_DRV_APM_TS_MEM_SIZE  (14568+2304)
   #else
      #define AUD_DRV_APM_TS_MEM_SIZE  (0)
   #endif

   #if defined(__LOW_COST_SUPPORT_COMMON__)
      #define AUD_DRV_APM_SINK_MEM_SIZE  (14*1024)
   #else
      #define AUD_DRV_APM_SINK_MEM_SIZE  (26*1024)
   #endif

   #define AUD_DRV_APM_EXT_MEM_SIZE  (AUD_DRV_APM_LEVEL1_MEM_SIZE + AUD_DRV_APM_LEVEL2_MEM_SIZE + AUD_DRV_APM_LEVEL3_MEM_SIZE + AUD_DRV_APM_LEVEL4_MEM_SIZE + AUD_DRV_APM_TS_MEM_SIZE + AUD_DRV_APM_SINK_MEM_SIZE + AUD_DRV_APM_BLISRC_MEM_SIZE)
#else
   #if defined(DYNAMIC_CODE_MANAGER)
      #define AUD_DRV_APM_EXT_MEM_SIZE  (AUD_DRV_APM_LEVEL2_MEM_SIZE + AUD_DRV_APM_LEVEL3_MEM_SIZE + AUD_DRV_APM_BLISRC_MEM_SIZE)
   #else
      #define AUD_DRV_APM_EXT_MEM_SIZE  (AUD_DRV_APM_LEVEL1_MEM_SIZE + AUD_DRV_APM_LEVEL2_MEM_SIZE + AUD_DRV_APM_LEVEL3_MEM_SIZE + AUD_DRV_APM_LEVEL4_MEM_SIZE + AUD_DRV_APM_BLISRC_MEM_SIZE)
   #endif
#endif

#if (defined(__DSP_COMPRESS_7Z__) && defined(WT20K)) && !defined(__AUD_SW_CODEC__)
   #define AUD_DRV_APM_MIDI_EXT_MEM_SIZE (AUD_DRV_APM_EXT_MEM_SIZE + 20*1024)
#else
   #define AUD_DRV_APM_MIDI_EXT_MEM_SIZE AUD_DRV_APM_EXT_MEM_SIZE
#endif

/******************************************************
 * 5. Begin to count AUDIO EXT MEM size
 ******************************************************/
#define AUD_MED_OVERHEAD (4)


/* Working buffer */
#define AUD_WORKING_BUFFER_VRSD         (AUD_MED_VRSD_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_VRSI         (AUD_MED_VRSI_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_TTS          (AUD_MED_TTS_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_CTM          (AUD_MED_CTM_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_BGSND        (AUD_DRV_BGSND_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_MMA          (AUD_MMA_SMF_WORKING_BUF + AUD_MMA_WAV_WORKING_BUF + AUD_MMA_MIXER_WORKING_BUF)
#define AUD_WORKING_BUFFER_WAV          (AUD_DRV_WAV_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_MP3          (AUD_DRV_DAF_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_AAC          (AUD_DRV_AAC_EXT_MEM_SIZE + AUD_DRV_AAC_SBR_EXT_MEM_SIZE + AUD_DRV_AAC_PS_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_AMR          (AUD_DRV_AMR_PLAYBACK_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_AWB          (AUD_DRV_AWB_EXT_MEM_SIZE + AUD_DRV_AWB_PLUS_EXT_MEM_SIZE)
/*MP4,3GP,M4A might contains AAC,AMR,AWB audio*/
#define AUD_WORKING_BUFFER_MP4          (AUD_MED_MP4_PARSER_MEM_SIZE + MAXOF( MAXOF(AUD_WORKING_BUFFER_AAC,AUD_WORKING_BUFFER_AMR), AUD_WORKING_BUFFER_AWB))
#define AUD_WORKING_BUFFER_APE          (AUD_DRV_APE_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_VORBIS       (AUD_DRV_VORBIS_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_FLAC         (AUD_DRV_FLAC_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_I2S_REC      (AUD_DRV_I2S_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_AMR_REC      (AUD_DRV_AMR_RECORD_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_VORBIS_REC   (AUD_DRV_VORBIS_RECORD_EXT_MEM_SIZE)
#define AUD_WORKING_BUFFER_MIDI_FILE    (AUD_SMF_WORKING_BUF)
#define AUD_WORKING_BUFFER_IMY_DATA     (AUD_MELODY_BUFFER_LEN)
#define AUD_WORKING_BUFFER_MIDI_DATA    (AUD_MELODY_BUFFER_LEN + AUD_SMF_WORKING_BUF)


/* Audio memory use cases:              [Overhead]        + [BT]                    + [SW DTMF]                    + [DSP Decompression and Audio Post-Process]                        + [Working buffer]             + [MPL Object buffer]      + [FS buffer]           + [Build Cache buffer]          + [Ring Buffer] */
#define MAX_AUD_MEM_SIZE_SPEECH         (AUD_MED_OVERHEAD +                       0 +                            0 + MAXOF(AUD_DRV_DSP_NR_EXT_MEM_SIZE, AUD_DRV_DSP_EXT_MEM_SIZE))        /* Speech */
#define MAX_AUD_MEM_SIZE_VRSD           (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE +                            0 +                                                            0      + AUD_WORKING_BUFFER_VRSD)  /* VRSD */
#define MAX_AUD_MEM_SIZE_VRSI           (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE +                            0 +                                                            0      + AUD_WORKING_BUFFER_VRSI)  /* VRSI */
#define MAX_AUD_MEM_SIZE_TTS            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE +                            0 + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,                           0)      + AUD_WORKING_BUFFER_TTS)   /* TTS */
#define MAX_AUD_MEM_SIZE_CTM            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE +                            0 + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,                           0)      + AUD_WORKING_BUFFER_CTM)   /* CTM */
#define MAX_AUD_MEM_SIZE_BKSND          (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE +                            0 + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,                           0)      + AUD_WORKING_BUFFER_BGSND) /* Background sound */   
#define MAX_AUD_MEM_SIZE_MMA            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_WT_EXT_MEM_SIZE, AUD_DRV_APM_MIDI_EXT_MEM_SIZE) + AUD_WORKING_BUFFER_MMA       + AUD_MED_MPL_OBJ_BUF_SIZE) /* Multiple player */
#define MAX_AUD_MEM_SIZE_WAV            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_WAV       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE + AUD_MED_BUILD_CACHE_BUF_SIZE + MED_RING_BUFFER_SIZE)  /* WAV */
#define MAX_AUD_MEM_SIZE_MP3            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE_MP3,AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_MP3       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE + AUD_MED_BUILD_CACHE_BUF_SIZE + MED_RING_BUFFER_SIZE)  /* MP3 */
#define MAX_AUD_MEM_SIZE_MP4            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_MP4       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE +                            0 + MED_MP4_RING_BUFFER_SIZE) /* MP4 */
#define MAX_AUD_MEM_SIZE_AAC            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_AAC       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE + AUD_MED_BUILD_CACHE_BUF_SIZE + MED_RING_BUFFER_SIZE)  /* AAC */
#define MAX_AUD_MEM_SIZE_AMR            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_AMR       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE + AUD_MED_BUILD_CACHE_BUF_SIZE + MED_RING_BUFFER_SIZE)  /* AMR */
#define MAX_AUD_MEM_SIZE_AWB            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_AWB       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE + AUD_MED_BUILD_CACHE_BUF_SIZE + MED_RING_BUFFER_SIZE)  /* AWB */
#define MAX_AUD_MEM_SIZE_APE            (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_APE       + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE +                            0 + MED_RING_BUFFER_SIZE)  /* APE */
#define MAX_AUD_MEM_SIZE_VORBIS         (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_VORBIS    + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE +                            0 + MED_RING_BUFFER_SIZE)  /* Vorbis */
#define MAX_AUD_MEM_SIZE_FLAC           (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_FLAC      + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE +                            0 + MED_RING_BUFFER_SIZE)  /* Flac */
#define MAX_AUD_MEM_SIZE_I2S_REC        (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_EXT_MEM_SIZE,    AUD_DRV_APM_EXT_MEM_SIZE)      + AUD_WORKING_BUFFER_I2S_REC   + AUD_MED_MPL_OBJ_BUF_SIZE +                     0 +                            0 + MED_RING_BUFFER_SIZE)  /* I2S record */
#define MAX_AUD_MEM_SIZE_AMR_REC        (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_NR_EXT_MEM_SIZE,                        0)      + AUD_WORKING_BUFFER_AMR_REC   + AUD_MED_MPL_OBJ_BUF_SIZE +                     0 +                            0 + MED_RING_BUFFER_SIZE)  /* AMR record */
#define MAX_AUD_MEM_SIZE_VORBIS_REC     (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_NR_EXT_MEM_SIZE,                        0)      + AUD_WORKING_BUFFER_VORBIS_REC+ AUD_MED_MPL_OBJ_BUF_SIZE +                     0 +                            0 + MED_RING_BUFFER_SIZE)  /* VORBIS record */
#ifdef MIDFILE_PLAY_SUPPORT
#define MAX_AUD_MEM_SIZE_MIDI_FILE      (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_WT_EXT_MEM_SIZE, AUD_DRV_APM_MIDI_EXT_MEM_SIZE) + AUD_WORKING_BUFFER_MIDI_FILE + AUD_MED_MPL_OBJ_BUF_SIZE + AUD_MED_PROC_BUF_SIZE) /* MIDI file playback */
#define MAX_AUD_MEM_SIZE_IMY_DATA       (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_WT_EXT_MEM_SIZE, AUD_DRV_APM_MIDI_EXT_MEM_SIZE) + AUD_WORKING_BUFFER_IMY_DATA  + AUD_MED_MPL_OBJ_BUF_SIZE) /* IMY data playback */
#define MAX_AUD_MEM_SIZE_MIDI_DATA      (AUD_MED_OVERHEAD) /* MIDI/IMY data playback - don't care */
#else
#define MAX_AUD_MEM_SIZE_MIDI_FILE      (AUD_MED_OVERHEAD) /* MIDI file playback - don't care */
#define MAX_AUD_MEM_SIZE_IMY_DATA       (AUD_MED_OVERHEAD) /* IMY data playback - don't care */
#define MAX_AUD_MEM_SIZE_MIDI_DATA      (AUD_MED_OVERHEAD + AUD_DRV_BT_EXT_MEM_SIZE + AUD_DRV_SW_DTMF_EXT_MEM_SIZE + MAXOF(AUD_DRV_DSP_WT_EXT_MEM_SIZE, AUD_DRV_APM_MIDI_EXT_MEM_SIZE) + AUD_WORKING_BUFFER_MIDI_DATA + AUD_MED_MPL_OBJ_BUF_SIZE) /* MIDI/IMY data playback */
#endif
#define MAX_AUD_MEM_SIZE_VM             (AUD_MED_OVERHEAD + AUD_MED_VM_EXT_MEM_SIZE)

#define AUD_EXT_MEM_SIZE 0 /* Extract AUD memory from MED memory pool */

/******************************************************
 * MED shared memory usage definition 
 ******************************************************/
#define MED_DIRECT_SENSOR_INT_SIZE (704)

#if defined(__MP4_ENC_SW_SUPPORT__) || defined(__H264_DEC_SW_SUPPORT__)
#define MED_INT_STACK_MEM_SIZE (4096)
#else
#define MED_INT_STACK_MEM_SIZE (2800)
#endif

/**
 * when turn on debug on, adm need around 200K to log some information, 
 * so we enlarge MEM_OVERHEAD to 384 bytes */
#if defined(__MED_MEM_DEBUG_ON__)
    #define MEM_AUD_OVERHEAD (1024)
    #define MEM_OVERHEAD     (384)
    #define MEM_EXT_OVERHEAD (1024)
#else
    #define MEM_AUD_OVERHEAD (256)
    #define MEM_OVERHEAD     (256)
    #define MEM_EXT_OVERHEAD (256)
#endif /* __MED_MEM_DEBUG_ON__ */


/******************************************************
 * 1. WEBCAM support
 ******************************************************/
#if defined(WEBCAM_SUPPORT)
#define MAX_MED_WEBCAM_EXT_MEM_SIZE (CAL_WEBCAM_JPEG_BUFFER_SIZE + CAL_WEBCAM_EXT_MEM_SIZE)
#else
#define MAX_MED_WEBCAM_EXT_MEM_SIZE (0)
#endif


/******************************************************
 * 2. Video Recorder/Player
 ******************************************************/
#if defined(__MED_VID_ENC_MOD__)
    #ifdef MDP_SUPPORT_VR_TRIPLE_DISPLAY_BUFFER
        #define MED_VID_PREVIEW_BUFFER_SIZE (LCD_WIDTH*LCD_HEIGHT*2*2)
    #else
        #define MED_VID_PREVIEW_BUFFER_SIZE (LCD_WIDTH*LCD_HEIGHT*2)
    #endif
    #ifdef __VIDEO_STANDALONE_MEMORY__
        #define MAX_VID_ENC_EXT_MEM_SIZE (CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)
        #define MAX_VID_ENC_CIF_EXT_MEM_SIZE (CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)
    #else
        #define MAX_VID_ENC_EXT_MEM_SIZE (VIDEO_V2_ENC_EXT_MEMORY + CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)

        #ifdef VIDEO_V2_ENC_CIF_EXT_MEMORY
            #if VIDEO_V2_ENC_CIF_EXT_MEMORY > VIDEO_V2_ENC_EXT_MEMORY
                #define MAX_VID_ENC_CIF_EXT_MEM_SIZE (VIDEO_V2_ENC_EXT_MEMORY + CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)
            #else
                #define MAX_VID_ENC_CIF_EXT_MEM_SIZE (VIDEO_V2_ENC_CIF_EXT_MEMORY + CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)
            #endif
        #else
            #define MAX_VID_ENC_CIF_EXT_MEM_SIZE (VIDEO_V2_ENC_EXT_MEMORY + CAL_VIDEO_EXT_MEMORY_SIZE + MED_VID_PREVIEW_BUFFER_SIZE)
        #endif
    #endif
#else
    #define MAX_VID_ENC_EXT_MEM_SIZE   (0)
    #define MAX_VID_ENC_CIF_EXT_MEM_SIZE (0)    
#endif /* defined(__MED_VID_ENC_MOD__) */ 


#if defined(MP4_DECODE) || defined(MP4_ENCODE) || defined(__RM_DEC_SUPPORT__) || defined(MJPG_DECODE)
    #define MAX_VID_DEC_EXT_MEM_SIZE (VIDEO_V2_DEC_EXT_MEMORY)    
#else
    #define MAX_VID_DEC_EXT_MEM_SIZE (0)   
#endif

/******************************************************
 * 2.1 MJPG Codec
 ******************************************************/
#if defined(MJPG_ENCODE)
    #define MAX_VID_MJPG_ENC_EXT_MEM_SIZE    (VIDEO_V2_AVI_FW_EXT_MEMORY)
#else
    #define MAX_VID_MJPG_ENC_EXT_MEM_SIZE   (0)  /* External decode memory size for hardware engine buffer */
#endif
        
#if defined(MP4_ENCODE) 
    #define MP4_RECORDER_CNTX_MEM_SIZE (5*1024)
    #define MP4_ENCODE_MERGE_BUFFER_SIZE    (100 * 1024) 

    #define MED_VID_ENCODE_FSAL_BUFFER_SIZE (4*1024)
    #define MED_VID_ENCODE_FSAL_BUFFER_COUNT (4)
    #define MED_VID_ENCODE_FSAL_BUFFER_TOTAL_SIZE (MED_VID_ENCODE_FSAL_BUFFER_COUNT*MED_VID_ENCODE_FSAL_BUFFER_SIZE)
    #define MED_VID_ENCODE_FW_BUFFER_SIZE (VIDEO_V2_MP4_FW_EXT_MEMORY)

    #ifdef __VIDEO_STANDALONE_MEMORY__
    #define MAX_VID_MP4_ENC_EXT_MEM_SIZE (0)
    #define MAX_VID_MP4_ENC_STANDALONE_EXT_MEM_SIZE (MED_VID_ENCODE_FW_BUFFER_SIZE)
    #else
    #define MAX_VID_MP4_ENC_EXT_MEM_SIZE (MED_VID_ENCODE_FW_BUFFER_SIZE)
    #define MAX_VID_MP4_ENC_STANDALONE_EXT_MEM_SIZE (0)
    #endif
#else
    #define MP4_ENCODE_MERGE_BUFFER_SIZE    (0) 
    #define MED_VID_ENCODE_FSAL_BUFFER_SIZE (0)
    #define MED_VID_ENCODE_FSAL_BUFFER_COUNT (0)
    #define MED_VID_ENCODE_FSAL_BUFFER_TOTAL_SIZE (0)
    #define MED_VID_ENCODE_FW_BUFFER_SIZE (0)
    #define MAX_VID_MP4_ENC_EXT_MEM_SIZE (0)
    #define MAX_VID_MP4_ENC_STANDALONE_EXT_MEM_SIZE (0)
#endif

// MAX File Merge memory usage
#if MAX_VID_MP4_ENC_EXT_MEM_SIZE > MAX_VID_MJPG_ENC_EXT_MEM_SIZE
    #define MAX_VID_FILE_MERGE_EXT_MEM_SIZE (MAX_VID_MP4_ENC_EXT_MEM_SIZE)
#else
    #define MAX_VID_FILE_MERGE_EXT_MEM_SIZE (MAX_VID_MJPG_ENC_EXT_MEM_SIZE)    
#endif

// MAX Recorder memory usage
#if (MAX_VID_ENC_EXT_MEM_SIZE > MAX_VID_FILE_MERGE_EXT_MEM_SIZE)
    #define MAX_MED_VID_ENC_EXT_MEM_SIZE (MAX_VID_ENC_EXT_MEM_SIZE)    
#else
    #define MAX_MED_VID_ENC_EXT_MEM_SIZE (MAX_VID_FILE_MERGE_EXT_MEM_SIZE)     
#endif

// MAX Recorder CIF memory usage
#if (MAX_VID_ENC_CIF_EXT_MEM_SIZE > MAX_VID_FILE_MERGE_EXT_MEM_SIZE)
    #define MAX_MED_VID_ENC_CIF_EXT_MEM_SIZE (MAX_VID_ENC_CIF_EXT_MEM_SIZE)    
#else
    #define MAX_MED_VID_ENC_CIF_EXT_MEM_SIZE (MAX_VID_FILE_MERGE_EXT_MEM_SIZE)     
#endif

#define MAX_MED_VID_BG_EXT_MEM_SIZE (MAX_VID_FILE_MERGE_EXT_MEM_SIZE)

#ifdef __VIDEO_STANDALONE_MEMORY__
    #define MED_VID_MEM_SIZE (MAX_VID_MP4_ENC_STANDALONE_EXT_MEM_SIZE + VIDEO_V2_ENC_EXT_MEMORY)
#else
    #define MED_VID_MEM_SIZE (0)
#endif

/******************************************************
 * 2.2 MED video Context Size
 ******************************************************/
#if defined(__VIDEO_ARCHI_V2__)

#if defined(__MED_STREAM_MOD__)
    #define STREAMING_PROVIDER_MEM_SIZE (16 * 1024)
#else
    #define STREAMING_PROVIDER_MEM_SIZE (0)
#endif

/* Media provider core memory: foreground core + background core */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_CORE[MP4_MP_CORE_MEM_SIZE];
#endif
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_CORE[AVI_MP_CORE_MEM_SIZE];
#endif
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_CORE[FLV_MP_CORE_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_CORE[RM_MP_CORE_MEM_SIZE];
#endif

#if defined(__MKV_FILE_FORMAT_SUPPORT__)
    kal_uint8 MKV_MP_CORE[MKV_MP_CORE_MEM_SIZE];
#endif

#if defined(__MED_STREAM_MOD__)
    kal_uint8 STREAMING_MP_CORE[STREAMING_PROVIDER_MEM_SIZE + STREAMING_MP_CORE_MEM_SIZE];
#endif

/* two concurrent: if use mmi new memory. med doesn't need to handle concurrent case */
#ifndef __MED_IN_ASM__
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_RM_MP_CORE[RM_MP_CORE_MEM_SIZE*2];
#endif
#if defined(MP4_DECODE) && defined(__RM_DEC_SUPPORT__)
    kal_uint8 MP4_RM_MP_CORE[MP4_MP_CORE_MEM_SIZE + RM_MP_CORE_MEM_SIZE];
#endif

#if defined(__MKV_FILE_FORMAT_SUPPORT__) && defined(__RM_DEC_SUPPORT__)
    kal_uint8 MKV_RM_MP_CORE[MKV_MP_CORE_MEM_SIZE + RM_MP_CORE_MEM_SIZE];
#endif

#if defined(MP4_DECODE) && defined(__MED_STREAM_MOD__)
    kal_uint8 MP4_STREAMING_MP_CORE[MP4_MP_CORE_MEM_SIZE + STREAMING_PROVIDER_MEM_SIZE + STREAMING_MP_CORE_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__) && defined(__MED_STREAM_MOD__)
    kal_uint8 RM_STREAMING_MP_CORE[RM_MP_CORE_MEM_SIZE + STREAMING_PROVIDER_MEM_SIZE + STREAMING_MP_CORE_MEM_SIZE];
#endif
#endif /* __MED_IN_ASM__ */
} vid_mp_core_union;

/* Media provider video memory */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_VIDEO[MP4_MP_VIDEO_MEM_SIZE];
#endif /* MP4_DECODE */
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_VIDEO[AVI_MP_VIDEO_MEM_SIZE];
#endif /* MJPG_DECODE */
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_VIDEO[FLV_MP_VIDEO_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_VIDEO[RM_MP_VIDEO_MEM_SIZE];
#endif /* __RM_DEC_SUPPORT__ */
#if defined(__MKV_FILE_FORMAT_SUPPORT__)
    kal_uint8 MKV_MP_VIDEO[MKV_MP_VIDEO_MEM_SIZE];
#endif
#if defined(__MED_STREAM_MOD__)
    kal_uint8 STREAMING_MP_VIDEO[STREAMING_MP_VIDEO_MEM_SIZE];
#endif /* __MED_STREAM_MOD__ */
} vid_mp_video_union;

/* Media provider audio memory */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_AUDIO[MP4_MP_AUDIO_MEM_SIZE];
#endif /* MP4_DECODE */
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_AUDIO[AVI_MP_AUDIO_MEM_SIZE];
#endif /* MJPG_DECODE */
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_AUDIO[FLV_MP_AUDIO_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_AUDIO[RM_MP_AUDIO_MEM_SIZE];
#endif /* __RM_DEC_SUPPORT__ */
#if defined(__MKV_FILE_FORMAT_SUPPORT__)
    kal_uint8 MKV_MP_AUDIO[MKV_MP_AUDIO_MEM_SIZE];
#endif
#if defined(__MED_STREAM_MOD__)
    kal_uint8 STREAMING_MP_AUDIO[STREAMING_MP_AUDIO_MEM_SIZE];
#endif /* __MED_STREAM_MOD__ */
} vid_mp_audio_union;

#ifdef __VIDEO_SUBTITLE_SUPPORT__
/* Media provider subtitle memory */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_SUBTITLE[1 + MP4_MP_SUBTITLE_MEM_SIZE];
#endif /* MP4_DECODE */
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_SUBTITLE[1 + AVI_MP_SUBTITLE_MEM_SIZE];
#endif /* MJPG_DECODE */
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_SUBTITLE[1 + FLV_MP_SUBTITLE_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_SUBTITLE[1 + RM_MP_SUBTITLE_MEM_SIZE];
#endif /* __RM_DEC_SUPPORT__ */
#if defined(__MKV_FILE_FORMAT_SUPPORT__)
    kal_uint8 MKV_MP_SUBTITLE[1 + MKV_MP_SUBTITLE_MEM_SIZE];
#endif
#if defined(__MED_STREAM_MOD__)
    kal_uint8 STREAMING_MP_SUBTITLE[1 + STREAMING_MP_SUBTITLE_MEM_SIZE];
#endif /* __MED_STREAM_MOD__ */
} vid_mp_subtitle_union;
#endif /* __VIDEO_SUBTITLE_SUPPORT__ */

#define MEDIA_PROVIDER_MEM_SIZE (sizeof(vid_mp_core_union) + sizeof(vid_mp_video_union) + sizeof(vid_mp_audio_union))
#define MEDIA_PROVIDER_V_MEM_SIZE (sizeof(vid_mp_core_union) + sizeof(vid_mp_video_union))
#define MEDIA_PROVIDER_A_MEM_SIZE (sizeof(vid_mp_core_union) + sizeof(vid_mp_audio_union))
#define MEDIA_PROVIDER_CORE_MEM_SIZE (sizeof(vid_mp_core_union))

#ifdef __VIDEO_SUBTITLE_SUPPORT__
#define MEDIA_PROVIDER_SUBTITLE_MEM_SIZE (sizeof(vid_mp_core_union) + sizeof(vid_mp_video_union) + sizeof(vid_mp_audio_union) + sizeof(vid_mp_subtitle_union))
#else
#define MEDIA_PROVIDER_SUBTITLE_MEM_SIZE (MEDIA_PROVIDER_MEM_SIZE)
#endif

#if defined(MP4_DECODE)
#define MEDIA_PROVIDER_MP4_MEM_SIZE (MP4_MP_CORE_MEM_SIZE + MP4_MP_VIDEO_MEM_SIZE + MP4_MP_AUDIO_MEM_SIZE)
#else
#define MEDIA_PROVIDER_MP4_MEM_SIZE (0)
#endif


/* ADM static overhead: 300. ADM dynamic overhead: 20. */
#if !defined(__MED_IN_ASM__) && (defined(__MED_STREAM_MOD__) || defined(__RM_DEC_SUPPORT__))
#define MEDIA_VID_MEM_SIZE (MEDIA_SESSION_MEM_SIZE*2 + MEDIA_PROVIDER_MEM_SIZE + 300 + 20 * 10)
#define MEDIA_VID_SUBTITLE_MEM_SIZE (MEDIA_SESSION_MEM_SIZE*2 + MEDIA_PROVIDER_SUBTITLE_MEM_SIZE + 300 + 20 * 10)
#else
#define MEDIA_VID_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_MEM_SIZE + 300 + 20 * 10)
#define MEDIA_VID_SUBTITLE_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_SUBTITLE_MEM_SIZE + 300 + 20 * 10)
#endif

#define MEDIA_VID_V_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_V_MEM_SIZE  + 300 + 20 * 5)
#define MEDIA_VID_A_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_A_MEM_SIZE  + 300 + 20 * 4)
#define MEDIA_VID_MP4_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_MP4_MEM_SIZE + 300 + 20 * 10)
#define MEDIA_VID_INFO_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_CORE_MEM_SIZE + 300 + 20 * 2)

#else /* defined(__VIDEO_ARCHI_V2__) */
#define MEDIA_VID_MEM_SIZE (0)
#define MEDIA_VID_SUBTITLE_MEM_SIZE (0)
#define MEDIA_VID_V_MEM_SIZE (0)
#define MEDIA_VID_A_MEM_SIZE (0)
#define MEDIA_VID_MP4_MEM_SIZE (0)
#define MEDIA_VID_INFO_MEM_SIZE (0)

#endif /* defined(__VIDEO_ARCHI_V2__) */


#if defined(__VIDEO_ARCHI_V2__) 
/****************************************************
 * video preview
 ****************************************************/
/* Media provider preivew core memory */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_PREVIEW_CORE[MP4_MP_CORE_PREVIEW_MEM_SIZE];
#endif
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_PREVIEW_CORE[AVI_MP_CORE_PREVIEW_MEM_SIZE];
#endif
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_PREVIEW_CORE[FLV_MP_CORE_PREVIEW_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_PREVIEW_CORE[RM_MP_CORE_PREVIEW_MEM_SIZE];
#endif
} vid_mp_preview_core_union;

/* Media provider preview video memory */
typedef union
{
#if defined(MP4_DECODE)
    kal_uint8 MP4_MP_PREVIEW_VIDEO[MP4_MP_VIDEO_PREVIEW_MEM_SIZE];
#endif
#if defined(MJPG_DECODE)
    kal_uint8 AVI_MP_PREVIEW_VIDEO[AVI_MP_VIDEO_PREVIEW_MEM_SIZE];
#endif
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
    kal_uint8 FLV_MP_PREVIEW_VIDEO[FLV_MP_VIDEO_PREVIEW_MEM_SIZE];
#endif
#if defined(__RM_DEC_SUPPORT__)
    kal_uint8 RM_MP_PREVIEW_VIDEO[RM_MP_VIDEO_PREVIEW_MEM_SIZE];
#endif
} vid_mp_preview_video_union;

#if defined(MP4_DECODE) && (MP4_MP_AUDIO_PREVIEW_MEM_SIZE != 0)
    #error "MP4_MP_AUDIO_PREVIEW_MEM_SIZE should be zero"
#endif
#if defined(MJPG_DECODE) && (AVI_MP_AUDIO_PREVIEW_MEM_SIZE != 0)
    #error "AVI_MP_AUDIO_PREVIEW_MEM_SIZE should be zero"
#endif
#if defined(__FLV_FILE_FORMAT_SUPPORT__) && (FLV_MP_AUDIO_PREVIEW_MEM_SIZE != 0)
    #error "FLV_MP_AUDIO_PREVIEW_MEM_SIZE should be zero"
#endif
#if defined(__RM_DEC_SUPPORT__) && (RM_MP_AUDIO_PREVIEW_MEM_SIZE != 0)
    #error "RM_MP_AUDIO_PREVIEW_MEM_SIZE should be zero"
#endif

#define MEDIA_PROVIDER_PREVIEW_MEM_SIZE (sizeof(vid_mp_preview_core_union) + sizeof(vid_mp_preview_video_union))
#define MEDIA_VID_PREVIEW_MEM_SIZE (MEDIA_SESSION_MEM_SIZE + MEDIA_PROVIDER_PREVIEW_MEM_SIZE + 300 + 20 * 10)

#else /* defined(__VIDEO_ARCHI_V2__) */
#define MEDIA_VID_PREVIEW_MEM_SIZE (0)
#endif /* defined(__VIDEO_ARCHI_V2__) */


/************************************************************************************
 * 2.4 MAX VID DECODE MEMORY
 ************************************************************************************/

#if defined(__VIDEO_ARCHI_V2__)    
    #define MAX_MED_VID_DEC_EXT_MEM_SIZE (VIDEO_V2_DEC_EXT_MEMORY + MEDIA_VID_MEM_SIZE)
    #ifdef __VIDEO_SUBTITLE_SUPPORT__    
        #define MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE (VIDEO_V2_DEC_N_SUBTITLE_EXT_MEMORY + MEDIA_VID_SUBTITLE_MEM_SIZE)
    #else
        #define MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE (MAX_MED_VID_DEC_EXT_MEM_SIZE)
    #endif
    #define MAX_MED_VID_DEC_QVGA_EXT_MEM_SIZE (VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY + MEDIA_VID_MEM_SIZE)
    #define MAX_MED_VID_DEC_CIF_EXT_MEM_SIZE (VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY + MEDIA_VID_MEM_SIZE)
    #define MAX_MED_VID_DEC_PREVIEW_EXT_MEM_SIZE (VIDEO_V2_PREVIEW_DEC_EXT_MEMORY + MEDIA_VID_PREVIEW_MEM_SIZE)
    #define MAX_MED_VID_DEC_INFO_EXT_MEM_SIZE (MEDIA_VID_INFO_MEM_SIZE)
    #define MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE (VIDEO_V2_DEC_MPEG4_EXT_MEMORY + MEDIA_VID_MP4_MEM_SIZE)
    #define MAX_MED_VID_DEC_QVGA_MPEG4SP_EXT_MEM_SIZE (VIDEO_V2_QVGA_MPEG4SP_DEC_EXT_MEMORY + MEDIA_VID_MEM_SIZE)
    #define MAX_MED_VID_DEC_V_EXT_MEM_SIZE (VIDEO_V2_DEC_EXT_MEMORY + MEDIA_VID_V_MEM_SIZE)
    #define MAX_MED_VID_DEC_A_EXT_MEM_SIZE (MEDIA_VID_A_MEM_SIZE)

#else /* defined(__VIDEO_ARCHI_V2__) */
    #define MAX_MED_VID_DEC_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_QVGA_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_CIF_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_PREVIEW_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_INFO_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_QVGA_MPEG4SP_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_V_EXT_MEM_SIZE (0)
    #define MAX_MED_VID_DEC_A_EXT_MEM_SIZE (0)

#endif /* defined(__VIDEO_ARCHI_V2__) */

#define MED_VDOPLY_FG_MEM (MAX_MED_VID_DEC_EXT_MEM_SIZE)
#define MED_VDOPLY_BASE_MEM (0)

#define MED_VDOPLY_SUBTITLE_FG_MEM (MAX_MED_VID_DEC_SUBTITLE_EXT_MEM_SIZE)
#define MED_VDOPLY_SUBTITLE_BASE_MEM (0)

#define MED_VDOPLY_QVGA_FG_MEM (MAX_MED_VID_DEC_QVGA_EXT_MEM_SIZE)
#define MED_VDOPLY_QVGA_BASE_MEM (0)

#define MED_VDOPLY_CIF_FG_MEM (MAX_MED_VID_DEC_CIF_EXT_MEM_SIZE)
#define MED_VDOPLY_CIF_BASE_MEM (0)

#define MED_VDOPLY_PREVIEW_FG_MEM (MAX_MED_VID_DEC_PREVIEW_EXT_MEM_SIZE)
#define MED_VDOPLY_PREVIEW_BASE_MEM (0)

#define MED_VDOPLY_INFO_FG_MEM (MAX_MED_VID_DEC_INFO_EXT_MEM_SIZE)
#define MED_VDOPLY_INFO_BASE_MEM (0)

#define MED_VDOPLY_MP4_FG_MEM (MAX_MED_VID_DEC_MP4_EXT_MEM_SIZE)
#define MED_VDOPLY_MP4_BASE_MEM (0)

#define MED_VDOPLY_QVGA_MPEG4SP_FG_MEM (MAX_MED_VID_DEC_QVGA_MPEG4SP_EXT_MEM_SIZE)
#define MED_VDOPLY_QVGA_MPEG4SP_BASE_MEM (0)

#define MED_VDOPLY_V_FG_MEM (MAX_MED_VID_DEC_V_EXT_MEM_SIZE)
#define MED_VDOPLY_V_BASE_MEM (0)

#define MED_VDOPLY_A_FG_MEM  (0)
#define MED_VDOPLY_A_BASE_MEM (MAX_MED_VID_DEC_A_EXT_MEM_SIZE)

/**************************************************************************************************************
 * 3. Camera capture 
 * External : MAX(MAX_CAM_FILE_BUFFER_LEN (isp),
                 (LCD_WIDTH*LCD_HEIGHT*2 + YUV_BUFFER | MAX_IMG_ENC_EXT_MEM_SIZE)
 * Internal : MAX(MAX_CAM_CAP_INT_MEM_SIZE,MAX_IMG_ENC_INT_MEM_SIZE)
 **************************************************************************************************************/
#if defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)

#if ((defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__)&& !defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__)) || defined(__ZERO_SHUTTER_DELAY_SUPPORT__))
  #if (defined(__ZERO_SHUTTER_DELAY_SUPPORT__)&&defined(__CAL_ADVANCED_IMAGE_EFFECT_SUPPORT__)) //For Lomo+Color Accent effect
    #define CAM_GDI_BLTDB_BUFFER_SIZE (LCD_WIDTH*LCD_HEIGHT*2*4)
  #else
    #define CAM_GDI_BLTDB_BUFFER_SIZE (LCD_WIDTH*LCD_HEIGHT*2*3)
  #endif
#else
    #define CAM_GDI_BLTDB_BUFFER_SIZE (0)
#endif

    #define MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE  (160*120*3)
    
    #define MAX_CAM_FILE_BUFFER_LEN             (MAX_STILL_CAPTURE_JPEG_BUFF_SIZE) 
    #define MAX_CAM_CAPTURE_ISP_BUF_SIZE        (CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE)
    #define MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE   (CAL_STILL_CAPTURE_EXT_MEMORY_SIZE)
    #define MAX_CAM_CAPTURE_ISP_TOTAL_BUF_SIZE  (MAX_CAM_CAPTURE_ISP_BUF_SIZE + MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE)
    #define MAX_MED_CAM_CAP_ISP_EXT_MEM_SIZE    (MAX_CAM_CAPTURE_ISP_TOTAL_BUF_SIZE + CAM_GDI_BLTDB_BUFFER_SIZE + MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE)

    #define MAX_CAM_CAPTURE_LCD_FILE_BUFFER_LEN     (MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE)
    #define MIN_CAM_CAPTURE_LCD_ISP_BUF_SIZE        (CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_MIN_SIZE)
    #define MAX_CAM_CAPTURE_LCD_ISP_BUF_SIZE        (CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_SIZE)
    #define MAX_CAM_CAPTURE_LCD_ISP_WORK_BUF_SIZE   (CAL_STILL_CAPTURE_LCD_IMAGE_EXT_MEMORY_SIZE)
    #define MAX_CAM_CAPTURE_LCD_ISP_TOTAL_BUF_SIZE  (MAX_CAM_CAPTURE_LCD_ISP_BUF_SIZE + MAX_CAM_CAPTURE_LCD_ISP_WORK_BUF_SIZE)
    #define MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE        (MAX_CAM_CAPTURE_LCD_ISP_TOTAL_BUF_SIZE + CAM_GDI_BLTDB_BUFFER_SIZE + MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE)

    #define MAX_CAM_CAPTURE_VGA_ISP_BUF_SIZE        (CAL_STILL_CAPTURE_VGA_IMAGE_BUFF_SIZE)
    #define MAX_CAM_CAPTURE_VGA_ISP_WORK_BUF_SIZE   (CAL_STILL_CAPTURE_VGA_IMAGE_EXT_MEMORY_SIZE)
    #define MAX_CAM_CAPTURE_VGA_ISP_TOTAL_BUF_SIZE  (MAX_CAM_CAPTURE_VGA_ISP_BUF_SIZE + MAX_CAM_CAPTURE_VGA_ISP_WORK_BUF_SIZE)
    #define MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE        (MAX_CAM_CAPTURE_VGA_ISP_TOTAL_BUF_SIZE + CAM_GDI_BLTDB_BUFFER_SIZE + MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE)
    
    #if(MAX_MED_CAM_CAP_ISP_EXT_MEM_SIZE > MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE)
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE    MAX_MED_CAM_CAP_ISP_EXT_MEM_SIZE
    #else    
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE    MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE
    #endif    

    #if(MAX_MED_CAM_CAP_EXT_MEM_SIZE < MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE)
        #undef MAX_MED_CAM_CAP_EXT_MEM_SIZE
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE    MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE
    #endif
    
#else /* no ISP & no DIRECT_SENSOR */
#define MAX_CAM_FILE_BUFFER_LEN                 (0)   /* Image file buffer size for camera capture */
#define MAX_CAM_CAP_EXT_MEM_SIZE                (0)
#define MAX_MED_CAM_CAP_EXT_MEM_SIZE            (0)
#define MAX_CAM_CAPTURE_ISP_BUF_SIZE            (0)
#define MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE       (0)
#define MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE      (0)
#define MAX_CAM_CAPTURE_LCD_ISP_BUF_SIZE        (0)
#define MAX_CAM_CAPTURE_LCD_ISP_WORK_BUF_SIZE   (0)
#define MAX_CAM_CAPTURE_VGA_ISP_BUF_SIZE        (0)
#define MAX_CAM_CAPTURE_VGA_ISP_WORK_BUF_SIZE   (0)
#define MAX_MED_CAM_CAP_VGA_EXT_MEM_SIZE        (0)
#define MAX_MED_CAM_CAP_LCD_EXT_MEM_SIZE        (0)
#endif


/**************************************************************
 * 4. Streaming
 **************************************************************/

#define STREAMING_MSG_HDLR_MEM_SIZE 1024

#define SMP_CORE_MEM_SIZE       (STREAMING_PROVIDER_MEM_SIZE)
#define SMP_AUDIO_MEM_SIZE      (32*1024)
#define SMP_VIDEO_MEM_SIZE      (64*1024)

#define MED_STREAMING_FG_MEM (VIDEO_V2_DEC_EXT_MEMORY + SMP_VIDEO_MEM_SIZE + STREAMING_MP_VIDEO_MEM_SIZE + 20*2)
#define MED_STREAMING_BASE_MEM (STREAMING_MSG_HDLR_MEM_SIZE + MEDIA_SESSION_MEM_SIZE + SMP_CORE_MEM_SIZE + SMP_AUDIO_MEM_SIZE + STREAMING_MP_CORE_MEM_SIZE + STREAMING_MP_AUDIO_MEM_SIZE + 300 + 20*6)

#define MED_STREAMING_QVGA_FG_MEM (VIDEO_V2_UPTOQVGA_DEC_EXT_MEMORY + SMP_VIDEO_MEM_SIZE + STREAMING_MP_VIDEO_MEM_SIZE + 20*2)
#define MED_STREAMING_QVGA_BASE_MEM (MED_STREAMING_BASE_MEM)

#define MED_STREAMING_CIF_FG_MEM (VIDEO_V2_UPTOCIF_DEC_EXT_MEMORY + SMP_VIDEO_MEM_SIZE + STREAMING_MP_VIDEO_MEM_SIZE + 20*2)
#define MED_STREAMING_CIF_BASE_MEM (MED_STREAMING_BASE_MEM)

#if defined(STREAM_SUPPORT)
    #define MAX_STREAMING_EXT_MEM_SIZE (MED_STREAMING_FG_MEM + MED_STREAMING_BASE_MEM)
    #define MAX_STREAMING_QVGA_EXT_MEM_SIZE (MED_STREAMING_QVGA_FG_MEM + MED_STREAMING_QVGA_BASE_MEM)
    #define MAX_STREAMING_CIF_EXT_MEM_SIZE (MED_STREAMING_CIF_FG_MEM + MED_STREAMING_CIF_BASE_MEM)
#else
    #define MAX_STREAMING_EXT_MEM_SIZE (0)
    #define MAX_STREAMING_QVGA_EXT_MEM_SIZE (0)
    #define MAX_STREAMING_CIF_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 5. 3D game 
 **************************************************************/
#if defined(GAME_ENGINE)
#define MAX_3D_GAME_EXT_MEM_SIZE (1200*1024)
#else
#define MAX_3D_GAME_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 6. VOIP
 **************************************************************/
#if defined(VOIP_SUPPORT)
#define MAX_VOIP_EXT_MEM_SIZE (100)
#else
#define MAX_VOIP_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 7. MobileTV
 **************************************************************/
#if !defined(__MTV_SUPPORT__) && !defined(__ATV_SUPPORT__)
    #define MTV_BG_RECORD_MEM_SIZE (0)
#endif


#if (defined(__MTV_SUPPORT__) && !defined(__H264_DEC_SW_SUPPORT__)) || (defined(__ATV_SUPPORT__) && defined(__ATV_RECORD_SUPPORT__))
    #define __MTV_REC_SUPPORT__
#endif

#if (defined(__MTV_SUPPORT__) && !defined(__H264_DEC_SW_SUPPORT__))
    #define __MTV_TS_SUPPORT__
#endif

/******** TDMB ********/
#define MAX_TDMB_EXT_MEM_SIZE (0)   // phase out

/******** CMMB ********/
#define CMMB_ESG_MEM_SIZE (342*1024)

#if defined(__CMMB_CAS_MBBMS_SUPPORT__)
    #define MBBMS_ESG_MEM_SIZE (384*1024 + 512) // add ADM overhead
#else
    #define MBBMS_ESG_MEM_SIZE (0)
#endif

#if defined(__CMMB_DS_SUPPORT__)
    #define CMMB_DS_MEM_SIZE   (2*1024*1024)
#else
    #define CMMB_DS_MEM_SIZE   (0)
#endif
#define MTV_PLAYER_MEM_SIZE (32 * 1024)

#if defined(__CMMB_SUPPORT__)
    /* used in med_mem.h */
    #define MTV_BG_RECORD_MEM_SIZE ((512*1024) + CMMB_ESG_MEM_SIZE + MBBMS_ESG_MEM_SIZE + CMMB_DS_MEM_SIZE + 512)   // add overhead
#else
    #define MTV_BG_RECORD_MEM_SIZE (0)
#endif

#define MED_MTV_FG_MEM (MTV_PLAYER_MEM_SIZE + VIDEO_V2_QVGA_DEC_EXT_MEMORY + STREAMING_MP_CORE_MEM_SIZE + STREAMING_MP_VIDEO_MEM_SIZE + STREAMING_MP_AUDIO_MEM_SIZE)
#define MED_MTV_BASE_MEM (MBBMS_ESG_MEM_SIZE + MTV_BG_RECORD_MEM_SIZE)

#if defined(__CMMB_SUPPORT__)
    #define MAX_CMMB_EXT_MEM_SIZE (MED_MTV_FG_MEM + MED_MTV_BASE_MEM)
#else
    #define MAX_CMMB_EXT_MEM_SIZE (0)
#endif


/******** ATV ********/
#if defined(__ATV_RECORD_SUPPORT__)
    #define MAX_ATV_ENC_EXT_MEM_SIZE (MAX_MED_VID_ENC_EXT_MEM_SIZE)
#else
    #define MAX_ATV_ENC_EXT_MEM_SIZE (0)
#endif

/* venus app setting */
#define ATV_CORE_MEM_SIZE (64*1024) // sync with mtv_custom.h
#define ATV_PLAYER_VIDEO_MEM_SIZE (LCD_WIDTH * LCD_HEIGHT * 2 * 2)    // player preview buffer memory, buffer 2 & 3

#define MED_ATV_FG_MEM (ATV_PLAYER_VIDEO_MEM_SIZE)
#define MED_ATV_BASE_MEM (ATV_CORE_MEM_SIZE)

#define MED_ATV_REC_FG_MEM (ATV_PLAYER_VIDEO_MEM_SIZE + MAX_VID_ENC_EXT_MEM_SIZE)   // player preview + CAL/MPL recording buffer
#define MED_ATV_REC_BASE_MEM (ATV_CORE_MEM_SIZE + MAX_VID_MP4_ENC_EXT_MEM_SIZE) // ATV core + MPL recorder for saving

/* pluto setting */
#if defined(__ATV_SUPPORT__)
    #define MAX_ATV_EXT_MEM_SIZE (MED_ATV_FG_MEM + MED_ATV_BASE_MEM + MAX_ATV_ENC_EXT_MEM_SIZE)
#else
    #define MAX_ATV_EXT_MEM_SIZE (0)
#endif

/**************************************************************
 * 8. FS SORT SUPPORT
 **************************************************************/
#if !defined(MED_MEM_CHECK)
#if defined(__FS_SORT_SUPPORT__)
#ifndef FS_SORT_MAX_ENTRY 
#error "FS_SORT_MAX_ENTRY should be defined"
#endif
#define MAX_FS_SORT_MEM_SIZE FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY) + FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY)
#else
#define MAX_FS_SORT_MEM_SIZE (0)
#endif
#else
#define MAX_FS_SORT_MEM_SIZE (0)
#endif


/**************************************************************
 * 9. Camera Preview with Face Detection
 **************************************************************/
#if defined(ISP_SUPPORT)
    #define MAX_CAM_PREVIEW_BASIC_MEM_SIZE (((LCD_WIDTH * LCD_HEIGHT * 2 + 31) >> 5) << 5)
  #if defined(__LOW_COST_SUPPORT_COMMON__) // Low cost dosen't need tripple buffer.
    #define MAX_CAM_PREVIEW_EXT_MEM_SIZE ((CAL_PREVIEW_EXT_MEMORY_SIZE) + (CAL_PP_PREVIEW_EXT_MEMORY_SIZE) + MAX_CAM_PREVIEW_BASIC_MEM_SIZE)
  #else
    #define MAX_CAM_PREVIEW_EXT_MEM_SIZE ((CAL_PREVIEW_EXT_MEMORY_SIZE) + (CAL_PP_PREVIEW_EXT_MEMORY_SIZE) + MAX_CAM_PREVIEW_BASIC_MEM_SIZE*2)
  #endif
#else
    #define MAX_CAM_PREVIEW_BASIC_MEM_SIZE (0)
    #define MAX_CAM_PREVIEW_EXT_MEM_SIZE   (0)
#endif

#define MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE (MAX_CAM_PREVIEW_EXT_MEM_SIZE)
#define MAX_MED_CAM_PREVIEW_INT_MEM_SIZE (0)

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MED_BITSTREAM_MOD__
    #if defined(__SW_VIDEO_ADV_RESIZER_SUPPORT__)
/* under construction !*/
    #else 
/* under construction !*/
    #endif 
#else  /* __MED_BITSTREAM_MOD__ */
/* under construction !*/
#endif /* __MED_BITSTREAM_MOD__ */
#endif

/**************************************************************
 * 10. Camera Panorama Support
 **************************************************************/
#if defined(__MED_CAM_PANORAMA_VIEW_SUPPORT__) && \
   (defined(__MED_IN_ASM__) || \
   (!defined(__PANORAMA_STITCH_USE_APPMEM__) && !defined(OPERA_BROWSER)))
    #define CAM_BG_STITCH_EXT_MEM_SIZE      (CAL_PP_BG_EXT_MEMORY_SIZE)
    #define MAX_CAM_PANORAMA_EXT_MEM_SIZE   (CAL_PP_SCENARIO_EXT_MEMORY_SIZE) /* Panorama image buffer */
#else
    #define CAM_BG_STITCH_EXT_MEM_SIZE      (0)
    #define MAX_CAM_PANORAMA_EXT_MEM_SIZE   (0)
#endif

#define MED_CAM_PANORAMA_STITCH_SIZE    (CAL_PP_SCENARIO_EXT_MEMORY_SIZE)   /* Panorama image buffer */
#define MED_CAM_BG_STITCH_EXT_MEM_SIZE  (CAL_PP_BG_EXT_MEMORY_SIZE)         /* Panorama bg stitch buffer */
    

/**************************************************************
 * 11. VT
 **************************************************************/
#define MDI_VT_SRV_FACTOR    (3*2)
#if defined(__MED_VCALL_MOD__)
    #include "Video_memory_usage_v2.h"
    #include "Cal_mem_def.h"	
#ifndef __OP01__    
    #define MAX_VT_BASIC_MEM_SIZE ((VIDEO_V2_VT_EXT_MEMORY + 8) + CAL_VT_EXT_MEMORY_SIZE + 5*1024)
#else    
    #define MAX_VT_BASIC_MEM_SIZE ((VIDEO_V2_VT_EXT_MEMORY + 8) + CAL_VT_EXT_MEMORY_SIZE + 5*1024 + (((LCD_WIDTH * LCD_HEIGHT * 2 + 31) >> 5) << 5))
#endif    
    #define MAX_VT_EXT_MEM_SIZE (0)
#else
    #define MAX_VT_BASIC_MEM_SIZE (0)
    #define MAX_VT_EXT_MEM_SIZE   (0)
#endif

 
/**************************************************************
 * 12. Camera HDR Support
 **************************************************************/
#if defined(__MED_CAM_HDR_SUPPORT__)
    #define CAM_HDR_QUICKVIEW_EXT_SIZE          (((LCD_WIDTH * LCD_HEIGHT * 2 + 31) >> 5) << 5)
    #define CAM_HDR_SRC_ISP_EXT_MEM_SIZE        (MAX_STILL_CAPTURE_JPEG_BUFF_SIZE) //(CAL_STILL_CAPTURE_MAIN_IMAGE_BUFF_SIZE)
    #define CAM_HDR_SRC_LCD_EXT_MEM_SIZE        (MAX_STILL_CAPTURE_LCD_IMAGE_JPEG_BUFF_SIZE) //CAL_STILL_CAPTURE_LCD_IMAGE_BUFF_SIZE

    #if (CAM_HDR_SRC_ISP_EXT_MEM_SIZE) > (CAM_HDR_SRC_LCD_EXT_MEM_SIZE)
        #define CAM_HDR_SRC_EXT_MEM_SIZE    CAM_HDR_SRC_ISP_EXT_MEM_SIZE
    #else
        #define CAM_HDR_SRC_EXT_MEM_SIZE    CAM_HDR_SRC_LCD_EXT_MEM_SIZE
    #endif    
    
	#if (MAX_CAM_CAPTURE_ISP_BUF_SIZE+MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE) > (CAM_HDR_SRC_EXT_MEM_SIZE+CAL_PP_SCENARIO_EXT_MEMORY_SIZE)
		#define CAM_HDR_TOTAL_BUF_SIZE	(MAX_CAM_CAPTURE_ISP_BUF_SIZE+MAX_CAM_CAPTURE_ISP_WORK_BUF_SIZE)
    #else
		#define CAM_HDR_TOTAL_BUF_SIZE	(CAM_HDR_SRC_EXT_MEM_SIZE+CAL_PP_SCENARIO_EXT_MEMORY_SIZE)
    #endif
    #define MAX_CAM_HDR_EXT_MEM_SIZE        	(CAM_HDR_TOTAL_BUF_SIZE + CAM_HDR_QUICKVIEW_EXT_SIZE + MAX_CAM_CAPTURE_THUMBNAIL_BUF_SIZE)
    #define MAX_CAM_HDR_WORKING_EXT_MEM_SIZE    (CAL_PP_SCENARIO_EXT_MEMORY_SIZE)
#else
    #define CAM_HDR_QUICKVIEW_EXT_SIZE      (0)
    #define CAM_HDR_SRC_EXT_MEM_SIZE        (0)
    #define MAX_CAM_HDR_EXT_MEM_SIZE        (0)
    #define MAX_CAM_HDR_WORKING_EXT_MEM_SIZE    (0)
#endif
     
/**************************************************************
 * 13. Camera MAV Support
 **************************************************************/
#if defined(__MED_CAM_MULTIPLE_ANGLE_VIEW_SUPPORT__)||defined(__MED_CAM_3D_IMAGE_SUPPORT__)
    #define MAX_CAM_MAV_WORKING_EXT_MEM_SIZE    (CAL_PP_MAV_SCENARIO_EXT_MEMORY_SIZE)
#else
    #define MAX_CAM_MAV_WORKING_EXT_MEM_SIZE    (0)
#endif

/**************************************************************
 * Internal Ram
 * 1. DEDI AMR REC.
 **************************************************************/
#if defined(DEDI_AMR_REC_BUFFER) 
#define MAX_DEDI_AMR_REC_BUFFER (6108)
#else
#define MAX_DEDI_AMR_REC_BUFFER (0)
#endif

#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE-AUD_MELODY_BUFFER_LEN-MAX_IMG_DEC_FILE_BUFFER_LEN)

/**************************************************************
 * Service memory configuration
 **************************************************************/
/* Audio */
#define MEDIA_MEM_OVERHEAD (1024)

/* +1 to avoid union array size to be 0 */
#define MEDIA_MEM_ALIGN_TO_4(_x)  (((_x + 1) + 3) & ~3)

#if defined(__RM_DEC_SUPPORT__)
    #define MED_AUD_PLY_BASE_MEM_RM      (MEDIA_SESSION_MEM_SIZE + RM_MP_CORE_MEM_SIZE + RM_MP_AUDIO_MEM_SIZE + MEDIA_MEM_OVERHEAD)
    #define MED_AUD_INFO_BASE_MEM_RM     (MEDIA_SESSION_MEM_SIZE + RM_MP_CORE_MEM_SIZE)
#else
    #define MED_AUD_PLY_BASE_MEM_RM      (0)
    #define MED_AUD_INFO_BASE_MEM_RM     (0)
#endif
    #define MED_AUD_PLY_FG_MEM_RM        (0)
    #define MED_AUD_INFO_FG_MEM_RM       (0)


#ifdef __FLV_FILE_FORMAT_SUPPORT__
    #define MED_AUD_PLY_BASE_MEM_FLV     (MEDIA_SESSION_MEM_SIZE + FLV_MP_CORE_MEM_SIZE + FLV_MP_AUDIO_MEM_SIZE + MEDIA_MEM_OVERHEAD)
    #define MED_AUD_INFO_BASE_MEM_FLV    (MEDIA_SESSION_MEM_SIZE + FLV_MP_CORE_MEM_SIZE)
#else
    #define MED_AUD_PLY_BASE_MEM_FLV     (0)
    #define MED_AUD_INFO_BASE_MEM_FLV    (0)
#endif
    #define MED_AUD_PLY_FG_MEM_FLV       (0)
    #define MED_AUD_INFO_FG_MEM_FLV      (0)


/*defines the INFO memory for XXX_GetContentDescInfo*/
#if defined(MED_PURE_AUDIO) || defined(M4A_DECODE)
    #define MED_AUD_INFO_BASE_MEM_MP4 (MEDIA_SESSION_MEM_SIZE + MP4_MP_CORE_MEM_SIZE)
#else
    #define MED_AUD_INFO_BASE_MEM_MP4 (0)
#endif

#if defined(AAC_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_AAC 1560
    #else
        #define MED_AUD_INFO_BASE_MEM_AAC 1560
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_AAC 0
#endif /*AAC_DECODE*/

#if defined(AMR_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_AMR 0
    #else
        #define MED_AUD_INFO_BASE_MEM_AMR 1500
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_AMR 0
#endif /*AMR_DECODE*/

#if defined(DAF_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_DAF 6376
    #else
        #define MED_AUD_INFO_BASE_MEM_DAF 6312
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_DAF 0
#endif /*DAF_DECODE*/

#if defined(WMA_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_WMA 0
    #else
        #define MED_AUD_INFO_BASE_MEM_WMA 1560
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_WMA 0
#endif /*WMA_DECODE*/

#if defined(AU_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_AU 1216
    #else
        #define MED_AUD_INFO_BASE_MEM_AU 1704
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_AU 0
#endif /*AU_DECODE*/

#if defined(AIFF_DECODE)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_AIFF 1216
    #else
        #define MED_AUD_INFO_BASE_MEM_AIFF 1704
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_AIFF 0
#endif /*AIFF_DECODE*/

#if defined(WAV_CODEC)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_WAV 1216
    #else
        #define MED_AUD_INFO_BASE_MEM_WAV 1704
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_WAV 0
#endif /*WAV_CODEC*/

#if defined(__APE_DECODE__)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_APE 2048
    #else
        #define MED_AUD_INFO_BASE_MEM_APE 2152
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_APE 0
#endif /*__APE_DECODE__*/

#if defined(__VORBIS_DECODE__)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_VORBIS 20480
    #else
        #define MED_AUD_INFO_BASE_MEM_VORBIS 20480
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_VORBIS 0
#endif /*__VORBIS_DECODE__*/

#if defined(__FLAC_DECODE__)
    #if defined(__AUD_SW_CODEC__)
        #define MED_AUD_INFO_BASE_MEM_FLAC  (436)
    #else
       #define MED_AUD_INFO_BASE_MEM_FLAC (0)
    #endif
#else
    #define MED_AUD_INFO_BASE_MEM_FLAC (0)
#endif 



/* Currently RM and FLV's INFO memory needs to query from MED/APP ASM*/
typedef union
{
    kal_uint8 MED_AUD_PLY_RM[MEDIA_MEM_ALIGN_TO_4(MED_AUD_PLY_BASE_MEM_RM)];
    kal_uint8 MED_AUD_PLY_FLV[MEDIA_MEM_ALIGN_TO_4(MED_AUD_PLY_BASE_MEM_FLV)];
} med_aud_ply_base_union;

typedef union
{
    kal_uint8 MED_AUD_INFO_RM[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_RM)];
    kal_uint8 MED_AUD_INFO_FLV[MEDIA_MEM_ALIGN_TO_4(MED_AUD_INFO_BASE_MEM_FLV)];
} med_aud_info_base_union;

#define MED_AUD_PLY_BASE_MEM sizeof(med_aud_ply_base_union)
#define MED_AUD_PLY_FG_MEM 0
#define MED_AUD_INFO_BASE_MEM sizeof(med_aud_info_base_union)
#define MED_AUD_INFO_FG_MEM 0

/*==== MACROS ========*/

#ifdef PRODUCTION_RELEASE
#define MED_FUNC_ENTRY(X)
#define MED_MEM_INFO(v,w,x,y,z)
#define MED_FREE_MEM_INFO(x,y,z)
#define MED_MEM_FRAGMENTATION(x,y,z,a)
#define MED_MEM_CONCURRENT(x,y,z,a) 
#define MED_MEM_INFO_INT(v,w,x,y,z)    
#define MED_FREE_MEM_INFO_INT(x,y,z)   
#define MED_MEM_FRAGMENTATION_INT(x,y,z,a)
#define MED_MEM_CONCURRENT_INT(x,y,z,a)
#define MED_MEM_INFO_AUD(v,w,x,y,z)    
#define MED_FREE_MEM_INFO_AUD(x,y,z)   
#define MED_MEM_FRAGMENTATION_AUD(x,y,z,a)
#define MED_MEM_CONCURRENT_AUD(x,y,z,a)
#else /* PRODUCTION_RELEASE */ 
#define __AUD_TRACE_ON__
#define __CAM_TRACE_ON__
#define __IMG_TRACE_ON__
#define __VID_TRACE_ON__
#define __CTM_TRACE_ON__
#define __ECALL_TRACE_ON__
#define __WEBCAM_TRACE_ON__
#define __TVO_TRACE_ON__
#define __BT_A2DP_TRACE_ON__
#define __BT_HFP_TRACE_ON__
#define __RTP_TRACE_ON__
#define __STREAM_TRACE_ON__
#define __MTV_TRACE_ON__
#define __VCALL_TRACE_ON__
#define __VIDCLIP_TRACE_ON__

#define MED_FUNC_ENTRY(X)    kal_trace(TRACE_FUNC, X);
#define MED_MEM_INFO(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO, v, w, x, y, z);
#define MED_FREE_MEM_INFO(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO, x, y, z);
#define MED_MEM_FRAGMENTATION(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION, x, y, z, a);
#define MED_MEM_CONCURRENT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT, x, y, z, a);
#define MED_MEM_INFO_INT(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO_INT, v, w, x, y, z);
#define MED_FREE_MEM_INFO_INT(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO_INT, x, y, z);
#define MED_MEM_FRAGMENTATION_INT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION_INT, x, y, z, a);
#define MED_MEM_CONCURRENT_INT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT_INT, x, y, z, a);
#define MED_MEM_INFO_AUD(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO_AUD, v, w, x, y, z);
#define MED_FREE_MEM_INFO_AUD(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO_AUD, x, y, z);
#define MED_MEM_FRAGMENTATION_AUD(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION_AUD, x, y, z, a);
#define MED_MEM_CONCURRENT_AUD(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT_AUD, x, y, z, a);
#endif /* PRODUCTION_RELEASE */ 

#ifdef __AUD_TRACE_ON__
#define AUD_FUNC_ENTRY(X)                       kal_trace(TRACE_GROUP_1, X);
#define AUD_FUNC_ENTRY1(F, x)                   kal_trace(TRACE_GROUP_1, F, x);
#define AUD_FUNC_ENTRY2(F, x, y)                kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_FUNC_ENTRY3(F, x, y, z)             kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_STATE_TRACE(s)                      kal_trace(TRACE_STATE, AUD_STATE_TRC, s);
#define AUD_VALUE_TRACE(x,y,z)                  kal_trace(TRACE_GROUP_1, AUD_VALUE_TRC, x, y, z);
#define AUD_VALUE2_TRACE(x,y)                   kal_trace(TRACE_GROUP_1, AUD_VALUE2_TRC, x, y);
#define AUD_VALUE1_TRACE(x)                     kal_trace(TRACE_GROUP_1, AUD_VALUE1_TRC, x);

#define AUD_TRACE_VOLUME(x,y,z)                 kal_trace(TRACE_GROUP_1, AUD_VOLUME_TRC, x, y, z);
#define AUD_TRACE_PATH(x,y)                     kal_trace(TRACE_GROUP_1, AUD_PATH_TRC, x, y);
#define AUD_WAIT_EVT(x,y)                       kal_trace(TRACE_GROUP_1, AUD_WAIT_EVT_TRC, x, y);
#define AUD_SET_EVT(x,y)                        kal_trace(TRACE_GROUP_1, AUD_SET_EVT_TRC, x, y);
#define AUD_RESULT_TRACE(x)                     kal_trace(TRACE_INFO, AUD_RESULT_TRC, x);
#define AUD_ALLOC_RING_BUF_TRACE(x,y,z)         kal_trace(TRACE_INFO, AUD_ALLOC_RING_BUF_TRC, x, y, z);
#define AUD_FREE_RING_BUF_TRACE(x,y)            kal_trace(TRACE_INFO, AUD_FREE_RING_BUF_TRC, x, y);
#define AUD_MODULE_TONE_TRACE(x,y,z,l)          kal_trace(TRACE_INFO, AUD_MODULE_TONE_TRC, x, y, z, l);
#define AUD_MODULE_KEYTONE_TRACE(x,y,z)         kal_trace(TRACE_INFO, AUD_MODULE_KEYTONE_TRC, x, y, z);
#define AUD_MODULE_AUDIO_TRACE(x,y,z,l)         kal_trace(TRACE_INFO, AUD_MODULE_AUDIO_TRC, x, y, z, l);
#define AUD_MODULE_MEDIA_TRACE(x,y,z,l)         kal_trace(TRACE_INFO, AUD_MODULE_MEDIA_TRC, x, y, z, l);
#define AUD_MODULE_MEDIA2_TRACE(x,y,l)          kal_trace(TRACE_INFO, AUD_MODULE_MEDIA2_TRC, x, y, l);
#define AUD_MODULE_MELODY_TRACE(x,y,z,l)        kal_trace(TRACE_INFO, AUD_MODULE_MELODY_TRC, x, y, z, l);
#define AUD_MODULE_MMA_TRACE(x,y,z,l)           kal_trace(TRACE_INFO, AUD_MODULE_MMA_TRC, x, y, z, l);
#define AUD_MODULE_MMA2_TRACE(x,y,l)            kal_trace(TRACE_INFO, AUD_MODULE_MMA2_TRC, x, y, l);
#define AUD_MODULE_BUILD_CACHE_TRACE(x,y,z,l)   kal_trace(TRACE_INFO, AUD_MODULE_BUILD_CACHE_TRC, x, y, z, l);
#define AUD_MODULE_BUILD_CACHE2_TRACE(x,y,l)    kal_trace(TRACE_INFO, AUD_MODULE_BUILD_CACHE2_TRC, x, y, l);
#define AUD_MODULE_BUILD_CACHE1_TRACE(x,l)      kal_trace(TRACE_INFO, AUD_MODULE_BUILD_CACHE1_TRC, x, l);

#define AUD_MODULE_RECORD_TRACE(x,l)            kal_trace(TRACE_INFO, AUD_MODULE_RECORD_TRC, x, l);
#define AUD_MODULE_VM_TRACE(x,y,z,l)            kal_trace(TRACE_INFO, AUD_MODULE_VM_TRC, x, y, z, l);
#define AUD_MODULE_FM_RADIO_TRACE(x,y,z,l)      kal_trace(TRACE_INFO, AUD_MODULE_FM_RADIO_TRC, x, y, z, l);
#define AUD_MODULE_BT_A2DP_TRACE(x,y,z,l)       kal_trace(TRACE_INFO, AUD_MODULE_BT_A2DP_TRC, x, y, z, l);
#define AUD_MODULE_BT_HTP_TRACE(x,y,z,l)        kal_trace(TRACE_INFO, AUD_MODULE_BT_HTP_TRC, x, y, z, l);
#define AUD_MODULE_VRSD_TRACE(x,y,z,l)          kal_trace(TRACE_INFO, AUD_MODULE_VRSD_TRC, x, y, z, l);
#define AUD_MODULE_VRSI_TRACE(x,y,z,l)          kal_trace(TRACE_INFO, AUD_MODULE_VRSI_TRC, x, y, z, l);
#define AUD_MODULE_TTS_TRACE(x,y,z,l)           kal_trace(TRACE_INFO, AUD_MODULE_TTS_TRC, x, y, z, l);
#define AUD_MODULE_MODIS_TRACE(x,y,z,l)         kal_trace(TRACE_INFO, AUD_MODULE_MODIS_TRC, x, y, z, l);

#define AUD_MODULE_UTILITY2_TRACE(x,y,l)        kal_trace(TRACE_INFO, AUD_MODULE_UTILITY2_TRC, x, y, l);
#define AUD_MODULE_UTILITY1_TRACE(x,l)          kal_trace(TRACE_INFO, AUD_MODULE_UTILITY1_TRC, x, l);

#define AUD_MODULE_SPEECH_TRACE(x,y,z,l)        kal_trace(TRACE_INFO, AUD_MODULE_SPEECH_TRC, x, y, z, l);
#define AUD_PLAYER_MEDIA_TRACE(x,y,z,l)         kal_trace(TRACE_INFO, AUD_PLAYER_MEDIA_TRC, x, y, z, l);
#define AUD_PLAYER_MEDIA2_TRACE(x,y,l)          kal_trace(TRACE_INFO, AUD_PLAYER_MEDIA2_TRC, x, y, l);
#define AUD_PLAYER_MEDIA1_TRACE(x,l)            kal_trace(TRACE_INFO, AUD_PLAYER_MEDIA1_TRC, x, l);

#define AUD_PLAYER_MMA_TRACE(x,y,z,l)           kal_trace(TRACE_INFO, AUD_PLAYER_MMA_TRC, x, y, z, l);
#define AUD_PLAYER_MMA2_TRACE(x,y,l)            kal_trace(TRACE_INFO, AUD_PLAYER_MMA2_TRC, x, y, l);
#define AUD_PLAYER_MP4_TRACE(x,y,z,l)           kal_trace(TRACE_INFO, AUD_PLAYER_MP4_TRC, x, y, z, l);
#define AUD_PLAYER_RM_TRACE(x,y,z,l)            kal_trace(TRACE_INFO, AUD_PLAYER_RM_TRC, x, y, z, l);
#define AUD_PLAYER_MODIS_TRACE(x,y,z,l)         kal_trace(TRACE_INFO, AUD_PLAYER_MODIS_TRC, x, y, z, l);
#define AUD_RECORDER_MEDIA_TRACE(x,y,z,l)       kal_trace(TRACE_INFO, AUD_RECORDER_MEDIA_TRC, x, y, z, l);
#define AUD_RECORDER_MEDIA2_TRACE(x,y,l)        kal_trace(TRACE_INFO, AUD_RECORDER_MEDIA2_TRC, x, y, l);
#define AUD_RECORDER_MEDIA1_TRACE(x,l)          kal_trace(TRACE_INFO, AUD_RECORDER_MEDIA1_TRC, x, l);

#define AUD_RECORDER_MODIS_TRACE(x,y,z,l)       kal_trace(TRACE_INFO, AUD_RECORDER_MODIS_TRC, x, y, z, l);
#define AUD_TRIM_TRACE(x,y,z,l)                 kal_trace(TRACE_INFO, AUD_TRIM_TRC, x, y, z, l);
#else /* __AUD_TRACE_ON__ */ 
#define AUD_FUNC_ENTRY(X)
#define AUD_FUNC_ENTRY1(F, x)
#define AUD_FUNC_ENTRY2(F, x, y)
#define AUD_FUNC_ENTRY3(F, x, y, z)
#define AUD_STATE_TRACE(s)
#define AUD_VALUE_TRACE(x,y,z)
#define AUD_VALUE2_TRACE(x,y)
#define AUD_VALUE1_TRACE(x)

#define AUD_TRACE_VOLUME(x,y,z)
#define AUD_TRACE_PATH(x,y)
#define AUD_WAIT_EVT(x,y)
#define AUD_SET_EVT(x,y)
#define AUD_RESULT_TRACE(x)
#define AUD_ALLOC_RING_BUF_TRACE(x,y,z)
#define AUD_FREE_RING_BUF_TRACE(x,y)
#define AUD_MODULE_TONE_TRACE(x,y,z,l)
#define AUD_MODULE_KEYTONE_TRACE(x,y,z)
#define AUD_MODULE_AUDIO_TRACE(x,y,z,l)
#define AUD_MODULE_MEDIA_TRACE(x,y,z,l)
#define AUD_MODULE_MEDIA2_TRACE(x,y,l)
#define AUD_MODULE_MELODY_TRACE(x,y,z,l)
#define AUD_MODULE_MMA_TRACE(x,y,z,l)
#define AUD_MODULE_MMA2_TRACE(x,y,l)
#define AUD_MODULE_BUILD_CACHE_TRACE(x,y,z,l)
#define AUD_MODULE_BUILD_CACHE2_TRACE(x,y,l)
#define AUD_MODULE_BUILD_CACHE1_TRACE(x,l)

#define AUD_MODULE_RECORD_TRACE(x,l)
#define AUD_MODULE_VM_TRACE(x,y,z,l)
#define AUD_MODULE_FM_RADIO_TRACE(x,y,z,l)
#define AUD_MODULE_BT_A2DP_TRACE(x,y,z,l)
#define AUD_MODULE_BT_HTP_TRACE(x,y,z,l)
#define AUD_MODULE_VRSD_TRACE(x,y,z,l)
#define AUD_MODULE_VRSI_TRACE(x,y,z,l)
#define AUD_MODULE_TTS_TRACE(x,y,z,l)
#define AUD_MODULE_MODIS_TRACE(x,y,z,l)
#define AUD_MODULE_UTILITY2_TRACE(x,y,l)
#define AUD_MODULE_UTILITY1_TRACE(x,l)
#define AUD_MODULE_SPEECH_TRACE(x,y,z,l)
#define AUD_PLAYER_MEDIA_TRACE(x,y,z,l)
#define AUD_PLAYER_MEDIA2_TRACE(x,y,l)
#define AUD_PLAYER_MEDIA1_TRACE(x,l)
#define AUD_PLAYER_MMA_TRACE(x,y,z,l)
#define AUD_PLAYER_MMA2_TRACE(x,y,l)
#define AUD_PLAYER_MP4_TRACE(x,y,z,l)
#define AUD_PLAYER_RM_TRACE(x,y,z,l)
#define AUD_PLAYER_MODIS_TRACE(x,y,z,l)
#define AUD_RECORDER_MEDIA_TRACE(x,y,z,l)
#define AUD_RECORDER_MEDIA2_TRACE(x,y,l)
#define AUD_RECORDER_MEDIA1_TRACE(x,l)
#define AUD_RECORDER_MODIS_TRACE(x,y,z,l)
#define AUD_TRIM_TRACE(x,y,z,l)
#endif /* __AUD_TRACE_ON__ */


#ifdef __CAM_TRACE_ON__
#define CAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_2, X);
#define CAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CAM_STATE, s);
#define CAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_2, CAM_CHECK_VALUE, x, y, z);
#define CAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_WAIT_EVT_TRC, x, y);
#define CAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_SET_EVT_TRC, x, y);
#define CAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, CAM_RESULT, x, y, z);
#define CAM_BUFFER_TRACE(x)     kal_trace(TRACE_INFO,CAM_BUFFER,x);
#define CAM_QR_RESULT_TRACE(x)  kal_trace(TRACE_INFO,CAM_QR_RESULT,x);
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) kal_trace(TRACE_INFO,CAM_CLOSE_IMG_RESULT,x);
#else /* __CAM_TRACE_ON__ */ 
#define CAM_FUNC_ENTRY(X)
#define CAM_STATE_TRACE(s)
#define CAM_VALUE_TRACE(x,y,z)
#define CAM_WAIT_EVT(x,y)
#define CAM_SET_EVT(x,y)
#define CAM_RESULT_TRACE(x,y,z)
#define CAM_BUFFER_TRACE(x)     
#define CAM_QR_RESULT_TRACE(x)  
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) 
#endif /* __CAM_TRACE_ON__ */ 

#ifdef __IMG_TRACE_ON__
#define IMG_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_3, X);
#define IMG_STATE_TRACE(s)    kal_trace(TRACE_STATE, IMG_STATE, s);
#define IMG_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_3, IMG_CHECK_VALUE, x, y, z);
#define IMG_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_WAIT_EVT_TRC, x, y);
#define IMG_SET_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_SET_EVT_TRC, x, y);
#define IMG_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, IMG_RESULT, x, y, z);
#else /* __IMG_TRACE_ON__ */ 
#define IMG_FUNC_ENTRY(X)
#define IMG_STATE_TRACE(s)
#define IMG_VALUE_TRACE(x,y,z)
#define IMG_WAIT_EVT(x,y)
#define IMG_SET_EVT(x,y)
#define IMG_RESULT_TRACE(x,y,z)
#endif /* __IMG_TRACE_ON__ */ 

#ifdef __VID_TRACE_ON__
#define VID_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_4, X);
#define VID_STATE_TRACE(s)    kal_trace(TRACE_STATE, VID_STATE, s);
#define VID_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_4, VID_CHECK_VALUE, x, y, z);
#define VID_FILE_TRACE(a,b,c,d,e,f)    kal_trace(TRACE_GROUP_4, VID_FILE_INFO, a, b, c, d, e, f);
#define VID_VIS_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_VIS_ERROR, x, y);                          \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_AUD_ERROR_TRACE(x,y)    kal_trace(TRACE_INFO, VID_AUD_ERROR, x, y);
#define VID_PARSE_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_PARSE_ERROR, x, y);                      \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_FSAL_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_FSAL_ERROR, x, y);                        \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, VID_RESULT, x, y, z);
#define VID_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_WAIT_EVT_TRC, x, y);
#define VID_SET_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_SET_EVT_TRC, x, y);
#define VID_TRACE kal_trace
#else /* __VID_TRACE_ON__ */ 
#define VID_FUNC_ENTRY(X)
#define VID_STATE_TRACE(s)
#define VID_VALUE_TRACE(x,y,z)
#define VID_FILE_TRACE(a,b,c,d,e,f)
#define VID_VIS_ERROR_TRACE(x,y)
#define VID_AUD_ERROR_TRACE(x,y)
#define VID_PARSE_ERROR_TRACE(x,y)
#define VID_FSAL_ERROR_TRACE(x,y)
#define VID_RESULT_TRACE(x,y,z)
#define VID_WAIT_EVT(x,y)
#define VID_SET_EVT(x,y)
#define VID_TRACE if (0) kal_trace
#endif /* __VID_TRACE_ON__ */ 

#ifdef __WEBCAM_TRACE_ON__
#define WEBCAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_6, X);
#define WEBCAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, WEBCAM_STATE, s);
#define WEBCAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_6, WEBCAM_CHECK_VALUE, x, y, z);
#define WEBCAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_WAIT_EVT_TRC, x, y);
#define WEBCAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_SET_EVT_TRC, x, y);
#define WEBCAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, WEBCAM_RESULT, x, y, z);
#else /* __WEBCAM_TRACE_ON__ */ 
#define WEBCAM_FUNC_ENTRY(X)
#define WEBCAM_STATE_TRACE(s)
#define WEBCAM_VALUE_TRACE(x,y,z)
#define WEBCAM_WAIT_EVT(x,y)
#define WEBCAM_SET_EVT(x,y)
#define WEBCAM_RESULT_TRACE(x,y,z)
#endif /* __WEBCAM_TRACE_ON__ */ 

#ifdef __TVO_TRACE_ON__
#define TVO_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_5, X);
#define TVO_STATE_TRACE(s)    kal_trace(TRACE_STATE, TVO_STATE, s);
#define TVO_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_5, TVO_CHECK_VALUE, x, y, z);
#define TVO_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_WAIT_EVT_TRC, x, y);
#define TVO_SET_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_SET_EVT_TRC, x, y);
#define TVO_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, TVO_RESULT, x, y, z);
#else /* __TVO_TRACE_ON__ */ 
#define TVO_FUNC_ENTRY(X)
#define TVO_STATE_TRACE(s)
#define TVO_VALUE_TRACE(x,y,z)
#define TVO_WAIT_EVT(x,y)
#define TVO_SET_EVT(x,y)
#define TVO_RESULT_TRACE(x,y,z)
#endif /* __TVO_TRACE_ON__ */ 

#ifdef __CTM_TRACE_ON__
#define CTM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define CTM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CTM_STATE, s);
#define CTM_VALUE_TRACE(x)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUE, x);
#define CTM_VALUES_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUES, x, y, z);
#define CTM_READ_TEXT_TRACE1(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_1, x, y, z);
#define CTM_READ_TEXT_TRACE2(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_2, x, y, z);
#else /* __CTM_TRACE_ON__ */ 
#define CTM_FUNC_ENTRY(X)
#define CTM_STATE_TRACE(s)
#define CTM_VALUE_TRACE(x)
#define CTM_VALUES_TRACE(x,y,z)
#define CTM_READ_TEXT_TRACE1(x,y,z)
#define CTM_READ_TEXT_TRACE2(x,y,z)
#endif /* __CTM_TRACE_ON__ */ 

#ifdef __ECALL_TRACE_ON__
#define ECALL_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define ECALL_VALUE_TRACE(x)    kal_trace(TRACE_GROUP_1, AUD_ECALL_CHECK_VALUE, x);
#else /* __ECALL_TRACE_ON__ */ 
#define ECALL_FUNC_ENTRY(X)
#define ECALL_VALUE_TRACE(x)
#endif /* __ECALL_TRACE_ON__ */ 


#ifdef __BT_A2DP_TRACE_ON__
#define AUD_BT_A2DP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_A2DP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_A2DP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_A2DP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_A2DP_STATE, s);
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_A2DP_CHECK_VALUE, x, y, z);
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_A2DP_TRACE_ON__ */ 
#define AUD_BT_A2DP_FUNC_ENTRY(X)
#define AUD_BT_A2DP_FUNC_ENTRY1(F,x)
#define AUD_BT_A2DP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_A2DP_STATE_TRACE(s)
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_A2DP_TRACE_ON__ */ 

#ifdef __BT_HFP_TRACE_ON__
#define AUD_BT_HFP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_HFP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_HFP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)    kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_BT_HFP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_HFP_STATE, s);
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_HFP_CHECK_VALUE, x, y, z);
#define AUD_BT_HFP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_HFP_TRACE_ON__ */ 
#define AUD_BT_HFP_FUNC_ENTRY(X)
#define AUD_BT_HFP_FUNC_ENTRY1(F,x)
#define AUD_BT_HFP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)
#define AUD_BT_HFP_STATE_TRACE(s)
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)
#define AUD_BT_HFP_FUNC_TRACE1(F,x)
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_HFP_TRACE_ON__ */ 

#ifdef __RTP_TRACE_ON__
#define RTP_RETURN_TRACE(x)                     kal_trace(TRACE_GROUP_1, RTP_CHECK_RETURN, x)
#define RTP_VALUE_TRACE(x)                      kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUE, x)
#define RTP_VALUES_TRACE(x,y,z)                 kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUES, x, y, z)
#define RTP_GET_VALUE_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RTP_GET_VALUE, x, y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)    kal_trace(TRACE_GROUP_1, RTP_CHECK_CODEC, a, b, c, d, e, f, g, h, i, j)
#define RTP_PTIME_TRACE(x,y)                    kal_trace(TRACE_GROUP_1, RTP_CHECK_PTIME_MAXPTIME, x, y)
#define RTP_IDLE_TRACE                          kal_trace(TRACE_GROUP_1, RTP_CHECK_IDLE)
#define RTP_ENCODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_ENCODE)
#define RTP_DECODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_DECODE)
#define RTP_ENDECODING_TRACE                    kal_trace(TRACE_GROUP_1, RTP_CHECK_ENDECODE)
#define RTP_DATA_LOST_TRACE(x)                  kal_trace(TRACE_GROUP_1, RTP_ERROR_PACKET_LOST, x)
#define RTP_DATA_SEND_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_SENT_PACKET, x, y)
#define RTP_DATA_RECV_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECV_PACKET, x, y)
#define RTP_DATA_PLAY_TRACE(x,y,z)              kal_trace(TRACE_GROUP_1, RTP_CHECK_PLAY_PACKET, x, y, z)
#define RTP_DATA_RECORD_TRACE(x)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECORD_PACKET, x)
#else /* __RTP_TRACE_ON__ */ 
#define RTP_RETURN_TRACE(x)
#define RTP_VALUE_TRACE(x)
#define RTP_VALUES_TRACE(x,y,z)
#define RTP_GET_VALUE_TRACE(x,y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)
#define RTP_PTIME_TRACE(x,y)
#define RTP_IDLE_TRACE
#define RTP_ENCODING_TRACE
#define RTP_DECODING_TRACE
#define RTP_ENDECODING_TRACE
#define RTP_DATA_LOST_TRACE(x)
#define RTP_DATA_SEND_TRACE(x,y)
#define RTP_DATA_RECV_TRACE(x,y)
#define RTP_DATA_PLAY_TRACE(x,y,z)
#define RTP_DATA_RECORD_TRACE(x)
#endif /* __RTP_TRACE_ON__ */ 

#ifdef __STREAM_TRACE_ON__
#define STREAM_RETURN_TRACE(x)                      kal_trace(TRACE_GROUP_1, STREAM_CHECK_RETURN, x)
#define STREAM_VALUE_TRACE(x)                       kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUE, x)
#define STREAM_VALUES_TRACE(x,y,z)                  kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUES, x, y, z)
#define STREAM_FUNC_LOG(TAG)                        kal_trace(TRACE_FUNC, TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)                   kal_trace(TRACE_FUNC, TAG, VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_FUNC, TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)                  kal_trace(TRACE_STATE, TAG, VAR)
#define STREAM_INFO_LOG(TAG)                        kal_trace(TRACE_INFO, TAG)
#define STREAM_INFO_LOG2(TAG, VAR)                  kal_trace(TRACE_INFO, TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_INFO, TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)           kal_trace(TRACE_INFO, TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)        kal_trace(TRACE_INFO, TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)     kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)  kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)

#define STREAM_WARNING_LOG(TAG)                     kal_trace(TRACE_WARNING, TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)               kal_trace(TRACE_WARNING, TAG, VAR)
#define STREAM_ERROR_LOG(TAG)                       kal_trace(TRACE_ERROR, TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)                 kal_trace(TRACE_ERROR, TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)           kal_trace(TRACE_ERROR, TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)                      kal_prompt_trace(MOD_MED,"%s,%d:%s",__FILE__,__LINE__,x)
#else /* __STREAM_TRACE_ON__ */ 
#define STREAM_RETURN_TRACE(x)
#define STREAM_VALUE_TRACE(x)
#define STREAM_VALUES_TRACE(x,y,z)
#define STREAM_FUNC_LOG(TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)
#define STREAM_INFO_LOG(TAG)
#define STREAM_INFO_LOG2(TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)
#define STREAM_WARNING_LOG(TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG(TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)
#endif /* __STREAM_TRACE_ON__ */ 

#ifdef __MTV_TRACE_ON__
#define MTV_TRACE kal_trace
#else /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE if (0) kal_trace
#endif /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE_GROUP_DEMOD   TRACE_FUNC
#define MTV_TRACE_GROUP_DEMUX   TRACE_FUNC
#define MTV_TRACE_GROUP_BE      TRACE_INFO

/* audio */
#define AUD_ENTER_STATE(_s_) AUD_STATE_TRACE(_s_)\
                              (aud_context_p->state = _s_)

#define AUD_IN_STATE(_s_) (aud_context_p->state == _s_)
#ifdef __MED_CAM_MOD__
/* camera */
#define CAM_ENTER_STATE(_s_) CAM_STATE_TRACE(_s_)\
                              (cam_context_p->state = _s_)

#define CAM_IN_STATE(_s_) (cam_context_p->state == _s_)

#define CAM_PANO_IN_STATE(_s_) (cam_context_p->pano_state == _s_)
#define CAM_PANO_ENTER_STATE(_s_) (cam_context_p->pano_state = _s_)


#endif /* __MED_CAM_MOD__ */ 

#ifdef __MED_IMG_MOD__
/* image */
#define IMG_ENTER_STATE(_s_) IMG_STATE_TRACE(_s_)\
                              (img_context_p->state = _s_)

#define IMG_IN_STATE(_s_) (img_context_p->state == _s_)
#endif /* __MED_IMG_MOD__ */ 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)

#define VID_ENTER_STATE(_s_) vid_enter_state(_s_,__LINE__)

#define VID_IN_STATE(_s_)       (vid_context_p->state == _s_)

#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 

#if defined (__MED_WEBCAM_MOD__)
/* web camera */
#define WEBCAM_ENTER_STATE(_s_)  WEBCAM_STATE_TRACE(_s_)\
                              (webcam_context_p->state = _s_)

#define WEBCAM_IN_STATE(_s_) (webcam_context_p->state == _s_)
#endif /* defined (__MED_WEBCAM_MOD__) */ 

#if defined (__MED_TVO_MOD__)
/* tv output */
#define TVO_ENTER_STATE(_s_)  (tvo_context_p->state = _s_)

#define TVO_IN_STATE(_s_) (tvo_context_p->state == _s_)
#endif /* defined (__MED_TVO_MOD__) */ 

#ifdef __MED_CTM_MOD__
#define CTM_ENTER_STATE(_s_)  do { CTM_STATE_TRACE(_s_) \
                  aud_ctm_ctx.state = (_s_); } while(0)
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_BT_A2DP_MOD__
#define AUD_BT_A2DP_ENTER_STATE(_s_) AUD_BT_A2DP_STATE_TRACE(_s_)\
                  (aud_bt_a2dp_ctx.state = _s_)

#define AUD_BT_A2DP_IN_STATE(_s_) (aud_bt_a2dp_ctx.state == _s_)
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __MED_BT_HFP_MOD__
#define AUD_BT_HFP_ENTER_STATE(_s_) AUD_BT_HFP_STATE_TRACE(_s_)\
                  (aud_bt_hfp_ctx.state = _s_)

#define AUD_BT_HFP_IN_STATE(_s_) (aud_bt_hfp_ctx.state == _s_)
#endif /* __MED_BT_HFP_MOD__ */ 


#ifdef __MED_BITSTREAM_MOD__

#define BITSTREAM_RECORD_TRACE(x, y, z, l)             kal_trace(TRACE_GROUP_1, BITSTREAM_RECORD_TRC, x, y, z, l);
#define BITSTREAM_AUD_VALUE_TRACE3(x, y, z, l)         kal_trace(TRACE_GROUP_1, BITSTREAM_TRC_AUD_TRACE_VALUE, x, y, z, l);

#define BITSTREAM_RETURN_TRACE(x)                      kal_trace(TRACE_GROUP_1, BITSTREAM_CHECK_RETURN, x)
#define BITSTREAM_VALUE_TRACE(x)                       kal_trace(TRACE_GROUP_1, BITSTREAM_CHECK_VALUE, x)

#define BITSTREAM_FUNC_LOG(TAG)                        kal_trace(TRACE_FUNC, TAG)
#define BITSTREAM_FUNC_LOG2(TAG,VAR)                   kal_trace(TRACE_FUNC, TAG, VAR)
#define BITSTREAM_FUNC_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define BITSTREAM_STATE_LOG(TAG, VAR)                  kal_trace(TRACE_STATE, TAG, VAR)
#define BITSTREAM_INFO_LOG(TAG)                        kal_trace(TRACE_INFO, TAG)
#define BITSTREAM_INFO_LOG2(TAG, VAR)                  kal_trace(TRACE_INFO, TAG, VAR)
#define BITSTREAM_INFO_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define BITSTREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_INFO, TAG, VAR1, VAR2, VAR3)
#define BITSTREAM_INFO_LOG5(TAG, A, B, C, D)           kal_trace(TRACE_INFO, TAG, A, B, C, D)
#define BITSTREAM_INFO_LOG6(TAG, A, B, C, D, E)        kal_trace(TRACE_INFO, TAG, A, B, C, D, E)

#define BITSTREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)  kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G)

#define BITSTREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)
#define BITSTREAM_PROMPT_TRACE(x)                      kal_prompt_trace(MOD_MED,"%s,%d:%s",__FILE__,__LINE__,x)

#endif /* __MED_BITSTREAM_MOD__ */

/*==== TYPES =========*/
typedef enum
{
    MED_NVRAM_IDLE,
    MED_POWERON_READING_NVRAM,
    MED_POWERON_READING_NVRAM_FINISH
}
med_nvram_state_enum;

#endif /* _MED_GLOBAL_H */ 

#endif /* MED_NOT_PRESENT */ 

