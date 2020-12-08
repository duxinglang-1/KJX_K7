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
 * Jvm_vcomml.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define constances and enum values
 *   of JAL invocation by virtual com port related routines.
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef  _JVM_VCOMM_H_
#define  _JVM_VCOMM_H_
#include "MMI_features.h"
#if (defined(__JAVA_MANAGER__)&&!defined(J2ME_SLIM_MEMORY_SUPPORT))
    #ifndef __JAVA_VIRTUAL_COMM__
    #define __JAVA_VIRTUAL_COMM__
    #endif
#endif

#ifdef __JAVA_VIRTUAL_COMM__

#include "jal.h"
#include "jal_internal.h"
#include "FileManagerGProt.h"
#include "jam_msg_handler.h"

#define MAX_VIRTUAL_COMM_PORT_SUPPORT 1
#define JAVA_VCOMM_MAX_BUFFER_SIZE (256)

typedef enum
{
    PKG_TYPE_REQ=0,
    PKG_TYPE_RSP,
    PKG_TYPE_IND,
    PKG_TYPE_DATA
}SessionType;

typedef enum
{
    SEV_TYPE_SEND_KEYS=0,
    SEV_TYPE_SAVE_TO_FILE,
    SEV_TYPE_GET_VIBRATOR,
    SEV_TYPE_GET_BACKLIGHT,
    SEV_TYPE_SNAPSHOT
}ServiceType;

typedef struct
{
    SessionType sessionType;
    ServiceType serviceType;
    kal_char*     pdata;
}SessionPkg;
typedef enum
{
    SESSION_MODE_MESSAGE,
    SESSION_MODE_FILE_TRANS
}SessionMode;
typedef struct
{
    kal_int8     port;
    kal_bool    isOpened;
    kal_bool    isDataReady;
    kal_bool    isReceivedDown;
    SessionMode sessionMode;
    kal_uint16  currReceLen;
    kal_uint16  currSendLen;
    kal_int32  flieLen;
    kal_uint32  fliePos;
    kal_int32  fileHandler;
    kal_char*   sendBuffer;
    kal_char*   receBuffer;
} vcomm_context_struct;
extern kal_bool java_vcomm_opened;
extern kal_bool java_vcomm_open(kal_uint32 port);
extern kal_int32 java_vcomm_read(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len);
extern kal_int32 java_vcomm_write(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len);
extern kal_bool java_vcomm_close(kal_uint32 port);
#endif

#endif // _JVM_VCOMM_H_



