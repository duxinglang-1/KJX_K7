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
 *    idp_scen_common_mt6252.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
 *    Extract common port of vr, ic, pv scen for code shrinking.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 13 2012 peter.wang
 * removed!
 * .
 * 
 * 09 24 2012 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 *
 * 06 12 2012 peter.wang
 * removed!
 * .
 *
 * 05 25 2012 peter.wang
 * removed!
 * .
 *
 * 04 18 2012 peter.wang
 * removed!
 * .
 *
 * 02 24 2012 peter.wang
 * removed!
 * .
 *
 * 02 19 2012 peter.wang
 * removed!
 * .
 *
 * 02 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 16 2011 peter.wang
 * removed!
 * .
 *
 * 09 15 2011 peter.wang
 * removed!
 * .
 *
 * 05 17 2011 peter.wang
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
 * macros and options
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"

#if defined(DRV_IDP_6252_SERIES)

#include <mt6252/idp_engines.h>

#include <idp_cam_if.h>
#include <idp_camera_preview.h>

#if defined(IDP_MM_COLOR_SUPPORT)
#include <color_api.h>
#include <color_enum.h>
#include <color_structure.h>
#endif

/****************************************************************************
 * external symbols
 ****************************************************************************/


/****************************************************************************
 * local typedef
 ****************************************************************************/


/****************************************************************************
 * common variables
 ****************************************************************************/
// this flag is used to indicate whether MDP triple display buffer is enabled or not
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
kal_bool _idp_scen_triple_display_buffer_enable = KAL_FALSE;
kal_uint32 _idp_scen_display_buffer_addr[3];
kal_uint32 _idp_scen_display_buffer_cnt = 0;
#endif

// this buffer used for delay one frame trigger LCD display
#if defined(__ATV_SUPPORT__)
kal_uint32 completed_display_buffer_count = 0;
#endif

#if defined(IDP_MM_COLOR_SUPPORT)
COLOR_HANDLE mm_color_handle;
#endif

/****************************************************************************
 * Callback function bodies
 ****************************************************************************/
#if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
kal_bool idp_scen_acquire_write_buffer(void)
{
    CAL_CALLBACK_ID_ENUM eCBID;

    if (KAL_TRUE == _idp_scen_triple_display_buffer_enable)
    {
        CAL_BUFFER_CB_STRUCT rFrmDoneCBArg;
        // enable acquire next buffer process only
        rFrmDoneCBArg.EnableReleaseWriteBuffer= KAL_FALSE;
        rFrmDoneCBArg.EnableAcquireWriteBuffer= KAL_TRUE;

        // current preview and video encode frame done do the same thing in cal_cb
        // maybe different if design change
        // now only preview have triple buffer.
        if (1)
        {
            eCBID = IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE;
        }
        else
        {
            eCBID = IDPCAL_CBID_VIDEO_ENCODE_PREVIEW_DISPLAY_FRM_DONE;
        }

        pfIDP_CAL_CB(eCBID , &rFrmDoneCBArg, sizeof(CAL_BUFFER_CB_STRUCT));
        // record next buffer address for triple display buffer
        if (NULL != rFrmDoneCBArg.NextFrameBufferAddr)
        {
            if (_idp_scen_display_buffer_cnt < 3) // mdp only hold 1 or 2
            {
                _idp_scen_display_buffer_addr[_idp_scen_display_buffer_cnt] = rFrmDoneCBArg.NextFrameBufferAddr;    
                _idp_scen_display_buffer_cnt++;
            }
        }
    }
    return KAL_TRUE;
}
#endif

/****************************************************************************
 * common function bodies
 ****************************************************************************/ 
kal_bool
idp_common_open_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    kal_bool result;

    // open crz
    result = idp_resz_crz_open(&(owner->crz_key));
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    //owner->have_config_resz_crz = KAL_FALSE;

    kal_mem_set(&crz_struct, 0x0, sizeof(idp_resz_crz_struct));

    // open rotdma0
    result = idp_imgdma_rotdma0_open(&(owner->irt0_key));
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    owner->have_config_imgdma_irt0 = KAL_FALSE;

    kal_mem_set(&rotdma0_struct, 0x0, sizeof(idp_imgdma_rotdma0_struct));

#endif
    return KAL_TRUE;
}



kal_bool
idp_common_stop_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    idp_resz_crz_stop(owner->crz_key, &crz_struct);
    idp_imgdma_rotdma0_stop(owner->irt0_key, &rotdma0_struct);
#endif

    return KAL_TRUE;
}



kal_bool
idp_common_start_input_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    idp_resz_crz_start(owner->crz_key, &crz_struct);
#endif

    return KAL_TRUE;
}



kal_bool
idp_common_start_output_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    idp_imgdma_rotdma0_start(owner->irt0_key, &rotdma0_struct);
#endif

    return KAL_TRUE;
}



kal_bool
idp_common_is_busy_hook(
    idp_owner_t const * const owner,
    kal_bool * const busy)
{
#if defined(__MTK_TARGET__)

    idp_imgdma_rotdma0_is_busy(owner->irt0_key, busy, &rotdma0_struct);

    if (KAL_TRUE == (*busy))
    {
        return KAL_TRUE;
    }

    idp_resz_crz_is_busy(owner->crz_key, busy, &crz_struct);

#endif

    return KAL_TRUE;
}



kal_bool
idp_common_is_in_use_hook(void)
{
#if defined(__MTK_TARGET__)
    if (KAL_TRUE == idp_resz_crz_is_in_use())
    { 
        return KAL_TRUE; 
    }

    if (KAL_TRUE == idp_imgdma_rotdma0_is_in_use())
    { 
        return KAL_TRUE; 
    }
#endif

    return KAL_FALSE;
}



kal_bool
idp_common_query_hook(
    idp_owner_t * const owner,
    va_list ap)
{
    kal_uint32 para_type;
    kal_bool finish = KAL_FALSE;
    IDP_CAL_QUERY_TYPE_T eTypeTmp = IDP_CAL_QUERY_PATH_SUPPORT;
    img_rot_angle_enum_t eDesiredAngleTmp = IMG_ROT_ANGLE_0;

    while (KAL_FALSE == finish)
    {
        para_type = va_arg(ap, kal_uint32);

        switch (para_type)
        {
            case 0:
                finish = KAL_TRUE;
                break;

            case IDP_CAMERA_PREVIEW_QUERY_TYPE:
            //case IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_TYPE:
            //case IDP_VIDEO_ENCODE_QUERY_TYPE:
                eTypeTmp = (IDP_CAL_QUERY_TYPE_T) va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_QUERY_ARG_PATH:
            //case IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_PATH:
            //case IDP_VIDEO_ENCODE_QUERY_ARG_PATH:

            case IDP_CAMERA_PREVIEW_QUERY_ARG_CLR_FMT:
            //case IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_CLR_FMT:
            //case IDP_VIDEO_ENCODE_QUERY_ARG_CLR_FMT:
                va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_QUERY_ARG_DESIRED_ANGLE:
            //case IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_ARG_DESIRED_ANGLE:
            //case IDP_VIDEO_ENCODE_QUERY_ARG_DESIRED_ANGLE:
                eDesiredAngleTmp = (img_rot_angle_enum_t) va_arg(ap, kal_uint32);
                break;

            case IDP_CAMERA_PREVIEW_QUERY_RESULT:
            //case IDP_CAMERA_CAPTURE_TO_JPEG_QUERY_RESULT:
            //case IDP_VIDEO_ENCODE_QUERY_RESULT:
                {
                    kal_uint32 * const pu4Result = va_arg(ap, kal_uint32*);

                    if (eTypeTmp == IDP_CAL_QUERY_PATH_SUPPORT)
                    {
                        #if defined(MT6252H) || defined(MT6252)
                        //MT6252 MDP hardware only supports display path, main image path
                        (*pu4Result) = (kal_uint32) KAL_FALSE;
                        #elif defined(MT6250) || defined(MT6260)
                        //MT6250 MDP need pp path
                        (*pu4Result) = (kal_uint32) KAL_TRUE;
                        #endif
                    }
                    else if (eTypeTmp == IDP_CAL_QUERY_ROT_CAP)
                    {
                        // 90, 270, MT6252 display rotator only supports rotation CC 90 with mirror
                        (*pu4Result) = ((eDesiredAngleTmp & 0x01 == 0x01) ? (kal_uint32) IMG_MIRROR_ROT_ANGLE_90 : (kal_uint32) IMG_ROT_ANGLE_0);
                    }
                  #if defined(MDP_SUPPORT_CP_TRIPLE_DISPLAY_BUFFER)
                    else if (eTypeTmp == IDP_CAL_QUERY_FRAME_DONE_CB_FUNC)
                    {
                        (*pu4Result) = (kal_uint32)idp_scen_acquire_write_buffer;
                    }
                  #endif
                }
                break;

            default:
                return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}


kal_bool
idp_dummy_hook(
    idp_owner_t * const owner)
{
    return KAL_TRUE;
}



void
idp_dummy_hook2(
    idp_owner_t * const owner)
{
}


kal_bool
idp_dummy_hook3(void)
{
    return KAL_TRUE;
}


void idp_config_crz_crop(
    kal_uint16 image_src_width,
    kal_uint16 image_src_height,
    kal_uint16 crop_width,
    kal_uint16 crop_height)
{
    crz_struct.crop_left1 = (image_src_width - crop_width) >> 1;
    crz_struct.crop_right1 = crz_struct.crop_left1 + (crop_width - 1);
    crz_struct.crop_top1 = (image_src_height - crop_height) >> 1;
    crz_struct.crop_bottom1 = crz_struct.crop_top1 + (crop_height - 1);
}

#endif  // #if defined(DRV_IDP_6252_SERIES)

