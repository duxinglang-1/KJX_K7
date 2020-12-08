/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_error.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_ERROR_H
#define _MTV_ERROR_H

#ifndef _FS_ERRNO_H
#include "fs_errcode.h"
#endif

typedef enum mtv_result_t
{
    /* success code */

    MTV_S_OK                = 0,
    MTV_S_FALSE             = 1,
    MTV_S_ASYNC             = 2,   /**< The operation will be done asynchronously */
    MTV_S_SLOW              = 3,   /**< The operation succeeded but done slowly */

    /* ESG success code */
    MTV_S_DUPLICATE     = 4,
    MTV_S_COMPLETE      = 5,
    MTV_S_ONE_DATA_TYPE_COMPLETE    = 6,
    MTV_S_INVALID_PACKET            = 7,
    MTV_S_OUT_OF_ORDER_PACKET       = 8,

    /* CA success code */
    MTV_S_OK_CUMULATING                 = 9,
    MTV_S_FINISH_DESCRAMBLE_DIRECT_USE  = 10,
    MTV_S_FINISH_DESCRAMBLE             = 11,
    MTV_S_OK_OVER_LIMIT                 = 12,

    /* Upgrade */
    MTV_S_OK_UPGRADE_NONE      = 13,
    MTV_S_OK_UPGRADE_NEED      = 14,
    MTV_S_OK_UPGRADE_MANDATORY = 15,

    /* generic errors */
    MTV_E_RESERVED           = -1,
    MTV_E_FAIL               = -2,
    MTV_E_WRONG_STATE        = -3,
    MTV_E_INVALID_PARAM      = -4,
    MTV_E_RESOURCE_CONFLICT  = -5,
    MTV_E_NOT_IMPLEMENTED    = -6,
    MTV_E_OVER_LIMIT         = -7,
    MTV_E_OUT_OF_MEMORY      = -8,
    MTV_E_BUSY               = -9,
    MTV_E_ABORTED            = -10,
    MTV_E_CORRUPTED_DATA     = -11,
    MTV_E_NO_MORE_DATA       = -12,
    MTV_E_UNSUPPORTED_FORMAT = -13,
    MTV_E_ACCESS_DENIED      = -14,
    MTV_E_NO_ECM             = -15,
    MTV_E_TIMEOUT            = -16,
    MTV_E_CITY_DETECT_FAIL   = -17,
    MTV_E_FRAME_RATE_TOO_HIGH = -18,

    /* SPI errors */

    MTV_SPI_E_INTERNAL_ERROR  = -200,           /**< Internal error of SPI */
    MTV_SPI_E_NO_MORE_SERVICE = -201,           /**< No more service is allowed to start */
    MTV_SPI_E_INVALID_SERVICE = -202,           /**< Invalid service is specified */
    MTV_SPI_E_ALREADY_STARTED = -203,           /**< The service is already started */
    MTV_SPI_E_UNSUPPORTED_SERVICE_TYPE = -204,  /**< Unsupported service type */

    /* Decoder errors */

    MTV_DEC_E_VIDEO           = -300,           /**< generic video decoder error */
    MTV_DEC_E_AUDIO           = -301,           /**< generic audio decoder error */
    MTV_DEC_E_INVALID_CONFIG  = -302,           /**< invalid decoder configuration is specified */
    MTV_DEC_E_INVALID_AU      = -303,           /**< invalid access unit is detected */

    /* I/O errors = MTV_IO_E_BASE + fs_error */

    MTV_IO_E_BASE           = -1000,
    MTV_IO_E_DISK_FULL      = MTV_IO_E_BASE + FS_DISK_FULL,
    MTV_IO_E_DEVICE_BUSY    = MTV_IO_E_BASE + FS_DEVICE_BUSY,
    MTV_IO_E_MEDIA_CHANGED  = MTV_IO_E_BASE + FS_MEDIA_CHANGED,
    MTV_IO_E_ROOT_DIR_FULL  = MTV_IO_E_BASE + FS_ROOT_DIR_FULL,
    MTV_IO_E_WRITE_TOO_SLOW = MTV_IO_E_BASE + FS_OUT_OF_BUFFERS,
    MTV_IO_E_READ_ERROR     = MTV_IO_E_BASE + FS_MSDC_READ_SECTOR_ERROR,
    MTV_IO_E_WRITE_ERROR    = MTV_IO_E_BASE + FS_MSDC_WRITE_SECTOR_ERROR,
    MTV_IO_E_INVALID_FILE_HANDLE = MTV_IO_E_BASE + FS_INVALID_FILE_HANDLE

} mtv_result_t;

#endif /* _MTV_ERROR_H */
