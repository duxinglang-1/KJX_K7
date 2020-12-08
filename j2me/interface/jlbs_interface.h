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
 * jlbs_interface.h
 *
 * Project:
 * --------
 *  MAUI
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _JLBS_INTERFACE_H
#define _JLBS_INTERFACE_H

//#ifdef SUPPORT_JSR_179
#include "uart_sw.h"
#include "mdi_gps.h"

#define JLBS_GPS_MAX_RAW_DATA_LEN MDI_GPS_RAW_DATA_PER_CB

typedef struct
{
    LOCAL_PARA_HDR
    int op_type;
    int handle;
    int mode;
    int agps_type;
    void *update_callback;
} jlbs_gps_set_agps_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    int handle;
    int result;
} jlbs_gps_set_agps_rsp_struct;

typedef struct
{
    double latitude;
    double longitude;
    float altitude;
    float horizontalAccuracy;
    float verticalAccuracy;
    float speed;
    float course;
    double timestamp;
} jlbs_gps_nmea_data_struct;

typedef enum
{
    JLBS_GPS_OK = 0,
    JLBS_GPS_ERROR = -1,
    JLBS_GPS_NOT_AVAILABLE = -2,
    JLBS_GPS_ALREADY_OPENED = -3,
    JLBS_GPS_OUT_OF_MEMORY = -4,
    JLBS_GPS_SERVICE_OFF = -5,
    JLBS_GPS_END
} jlbs_gps_result_enum;

typedef enum
{
    JLBS_GPS_TYPE_LOCATION,
    JLBS_GPS_TYPE_RAW_DATA,
    JLBS_GPS_TYPE_END
} jlbs_gps_data_type_enum;

typedef enum
{
    JLBS_GPS_NMEA_GPGGA,
    JLBS_GPS_NMEA_GPRMC,
    JLBS_GPS_NMEA_GPGSA,
    JLBS_GPS_NMEA_GPGLL,
    JLBS_GPS_NMEA_GPVTG,
    JLBS_GPS_NMEA_GPGSV,
    JLBS_GPS_NMEA_END
} jlbs_gps_supported_nmea_sentence_enum;

typedef enum
{
    JLBS_GPS_USAGE_GPS,
#ifdef __AGPS_USER_PLANE__
    JLBS_GPS_USAGE_AGPS_USER_PLANE,
#endif
#ifdef __AGPS_CONTROL_PLANE__
    JLBS_GPS_USAGE_AGPS_CONTROL_PLANE,
#endif
    JLBS_GPS_USAGE_END
} jlbs_gps_usage_type_enum;

/* Functions */
extern kal_int32 jlbs_gps_open(kal_uint8 type, void (*callback_ptr)(void));
extern kal_int32 jlbs_gps_close(kal_int32 handle);
extern kal_int32 jlbs_gps_getRawData(kal_int32 handle, kal_char *buffer, kal_uint16 length);
extern kal_int32 jlbs_gps_getLocation(kal_int32 handle, jlbs_gps_nmea_data_struct *nmea_data);
extern kal_int32 jlbs_gps_is_need_cost(void);

//#endif /* SUPPORT_JSR_179 */

#endif /* _JLBS_INTERFACE_H */ 

