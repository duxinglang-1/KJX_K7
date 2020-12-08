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
 *  SatIconSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for SAT feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifndef __SAT_DISABLE_ICON_SUPPORT__

#ifndef SATICONSRV_C
#define SATICONSRV_C

#include "MMIDataType.h"
#include "mmi_msg_struct.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "sim_common_enums.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_const.h"
#include "gui_resource_type.h"
#include "gdi_include.h"

#include "ProtocolEvents.h"
#include "SatSrvGprot.h"
#include "SatSrv.h"

#define SRV_SAT_BASIC_IMAGE         0x11
#define SRV_SAT_COLOR_IMAGE         0x21
#define SRV_SAT_TRANSPARENT_IMAGE   0x22

typedef enum
{
    SRV_SAT_STAGE_IDLE,
    SRV_SAT_STAGE_READ_INFO,
    SRV_SAT_STAGE_READ_INSTANCE,
    SRV_SAT_STAGE_READ_DATA,
    SRV_SAT_STAGE_READ_CLUT
} srv_sat_stage_enum;

typedef struct
{
    U8 number;
    U8 width;
    U8 height;
    U8 coding;
    U16 instance;
    U16 offset;
    U16 length;
    U8 cycle;
    U8 current;
} srv_sat_image_instance_struct;

typedef struct
{
    U8 red;
    U8 green;
    U8 blue;
} srv_sat_color_struct;

typedef struct
{
    U8 number;
    U16 location;
    U16 length;
    U8 cycle;
    U8 current;
    srv_sat_color_struct *data;
} srv_sat_image_clut_struct;

typedef struct
{
    U8 icon_id;
    U8 *icon_data;
    srv_sat_do_icon_callback_type callback;
    void *user_data;
    srv_sat_stage_enum stage;
    srv_sat_image_instance_struct *image_instance;
    U8 *image_data;
    srv_sat_image_clut_struct *image_clut;
} srv_sat_image_struct;

/* 
 * Local Variable
 */
static srv_sat_image_struct g_srv_sat_image[SRV_SAT_TOTAL];

/* 
 * Local Function
 */
static void srv_sat_read_file_info_req(srv_sat_enum sat_id);
static void srv_sat_read_binary_req(srv_sat_enum sat_id, U16 offset, U16 length, U16 instance);
static void srv_sat_read_record_req(srv_sat_enum sat_id, U16 record, U16 length);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_read_file_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_read_file_info_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_rsp_struct *file_info;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_image_struct *image = &g_srv_sat_image[sat_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_info = (mmi_smu_read_file_info_rsp_struct*) info;

    if (file_info->access_id != 0xF0)
    {
        return;
    }

    switch (image->stage)
    {
        case SRV_SAT_STAGE_READ_INFO:
            if (file_info->result.flag == L4C_OK)
            {
                if (file_info->file_size != 0 && file_info->num_of_rec != 0)
                {
                    image->stage = SRV_SAT_STAGE_READ_INSTANCE;
                    srv_sat_read_record_req(
                        sat_id,
                        image->icon_id,
                        (U16) (file_info->file_size / file_info->num_of_rec));
                }
                else
                {
                    srv_sat_do_icon_callback(sat_id, MMI_FALSE);
                }
            }
            else
            {
                srv_sat_do_icon_callback(sat_id, MMI_FALSE);
            }
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_read_file_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_read_file_info_req(srv_sat_enum sat_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_file_info_req_struct *data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_FILE_INFO_RSP, (PsIntFuncPtr) srv_sat_read_file_info_rsp, MMI_TRUE);

    data_ptr = (mmi_smu_read_file_info_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_file_info_req_struct));
    data_ptr->file_idx = FILE_IMG_IDX;
    memset(data_ptr->path, 0, 6 * sizeof(U8));
    data_ptr->access_id = 0xF0;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SMU_READ_FILE_INFO_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_read_sim_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_read_sim_rsp(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_rsp_struct *sim_data;
    srv_sat_enum sat_id = L4CID_2_SATID((module_type) mod_src);
    srv_sat_image_struct *image = &g_srv_sat_image[sat_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_data = (mmi_smu_read_sim_rsp_struct*) info;

    if (sim_data->access_id != 0xF1)
    {
        return;
    }

    switch (image->stage)
    {
        case SRV_SAT_STAGE_READ_INSTANCE:
            if (sim_data->result.flag == L4C_OK)
            {
                if (sim_data->length && sim_data->data[0])
                {
                    image->image_instance = (srv_sat_image_instance_struct*) OslMalloc(sizeof(srv_sat_image_instance_struct));
                    image->image_instance->number = 1;
                    image->image_instance->width = sim_data->data[1];
                    image->image_instance->height = sim_data->data[2];
                    image->image_instance->coding = sim_data->data[3];

                    if (image->image_instance->width == 0 || image->image_instance->height == 0)
                    {
                        srv_sat_do_icon_callback(sat_id, MMI_FALSE);
                        return;
                    }

                    image->image_instance->instance = sim_data->data[4];
                    image->image_instance->instance = (image->image_instance->instance << 8) + sim_data->data[5];

                    image->image_instance->offset = sim_data->data[6];
                    image->image_instance->offset = (image->image_instance->offset << 8) + sim_data->data[7];

                    image->image_instance->length = sim_data->data[8];
                    image->image_instance->length = (image->image_instance->length << 8) + sim_data->data[9];

                    if (image->image_instance->length == 0 || image->image_instance->length > 2048)
                    {
                        srv_sat_do_icon_callback(sat_id, MMI_FALSE);
                        return;
                    }

                    if ((image->image_instance->length % 255) == 0 && (image->image_instance->length / 255) > 0)
                    {
                        image->image_instance->cycle = image->image_instance->length / 255 - 1;
                    }
                    else
                    {
                        image->image_instance->cycle = image->image_instance->length / 255;
                    }

                    image->image_instance->current = 0;

                    image->stage = SRV_SAT_STAGE_READ_DATA;
                    srv_sat_read_binary_req(
                        sat_id,
                        image->image_instance->offset,
                        image->image_instance->cycle ? 255 : image->image_instance->length,
                        image->image_instance->instance);
                }
                else
                {
                    srv_sat_do_icon_callback(sat_id, MMI_FALSE);
                }
            }
            else
            {
                srv_sat_do_icon_callback(sat_id, MMI_FALSE);
            }
            break;

        case SRV_SAT_STAGE_READ_DATA:
            if (sim_data->result.flag == L4C_OK)
            {
                if (!image->image_data)
                {
                    image->image_data = (U8*) OslMalloc(image->image_instance->length * sizeof(U8));
                }

                memcpy(
                    image->image_data + image->image_instance->current * 255,
                    sim_data->data,
                    sim_data->length);

                if (image->image_instance->current == image->image_instance->cycle)
                {
                    if (image->image_instance->coding != SRV_SAT_BASIC_IMAGE)
                    {
                        image->image_clut = (srv_sat_image_clut_struct*) OslMalloc(sizeof(srv_sat_image_clut_struct));
                        image->image_clut->number = image->image_data[2];
                        image->image_clut->location = image->image_data[4];
                        image->image_clut->location = (image->image_clut->location << 8) + image->image_data[5];
                        image->image_clut->length = (image->image_data[3] ? image->image_data[3] : 256) * sizeof(srv_sat_color_struct);
                        image->image_clut->data = (srv_sat_color_struct*) OslMalloc(image->image_clut->length * sizeof(U8));

                        if ((image->image_clut->length % 255) == 0 && (image->image_clut->length / 255) > 0)
                        {
                            image->image_clut->cycle = image->image_clut->length / 255 - 1;
                        }
                        else
                        {
                            image->image_clut->cycle = image->image_clut->length / 255;
                        }

                        image->image_clut->current = 0;

                        image->stage = SRV_SAT_STAGE_READ_CLUT;
                        srv_sat_read_binary_req(
                            sat_id,
                            image->image_clut->location,
                            image->image_clut->cycle ? 255 : image->image_clut->length,
                            image->image_instance->instance);
                    }
                    else
                    {
                        srv_sat_do_icon_callback(sat_id, MMI_TRUE);
                    }
                }
                else
                {
                    image->image_instance->current++;
                    image->stage = SRV_SAT_STAGE_READ_DATA;
                    if (image->image_instance->current == image->image_instance->cycle)
                    {
                        srv_sat_read_binary_req(
                            sat_id,
                            image->image_instance->offset + image->image_instance->current * 255,
                            image->image_instance->length - image->image_instance->current * 255,
                            image->image_instance->instance);
                    }
                    else
                    {
                        srv_sat_read_binary_req(
                            sat_id,
                            image->image_instance->offset + image->image_instance->current * 255,
                            255,
                            image->image_instance->instance);
                    }
                }
            }
            else
            {
                srv_sat_do_icon_callback(sat_id, MMI_FALSE);
            }
            break;

        case SRV_SAT_STAGE_READ_CLUT:
            if (sim_data->result.flag == L4C_OK)
            {
                memcpy(
                    image->image_clut->data + (image->image_clut->current * 255 / sizeof(srv_sat_color_struct)),
                    sim_data->data,
                    sim_data->length);

                if (image->image_clut->current == image->image_clut->cycle)
                {
                    srv_sat_do_icon_callback(sat_id, MMI_TRUE);
                }
                else
                {
                    image->image_clut->current++;
                    image->stage = SRV_SAT_STAGE_READ_CLUT;
                    if (image->image_clut->current == image->image_clut->cycle)
                    {
                        srv_sat_read_binary_req(
                            sat_id,
                            image->image_clut->location + image->image_clut->current * 255,
                            image->image_clut->length - image->image_clut->current * 255,
                            image->image_instance->instance);
                    }
                    else
                    {
                        srv_sat_read_binary_req(
                            sat_id,
                            image->image_clut->location + image->image_clut->current * 255,
                            255,
                            image->image_instance->instance);
                    }
                }
            }
            else
            {
                srv_sat_do_icon_callback(sat_id, MMI_FALSE);
            }
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_read_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  record      [IN]        
 *  length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_read_record_req(srv_sat_enum sat_id, U16 record, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_req_struct *data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, (PsIntFuncPtr) srv_sat_read_sim_rsp, MMI_TRUE);

    data_ptr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    data_ptr->file_idx = FILE_IMG_IDX;
    data_ptr->para = record;
    data_ptr->length = length;
    memset(data_ptr->path, 0, 6 * sizeof(U8));
    data_ptr->access_id = 0xF1;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SMU_READ_SIM_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_read_binary_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  offset      [IN]        
 *  length      [IN]        
 *  instance    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sat_read_binary_req(srv_sat_enum sat_id, U16 offset, U16 length, U16 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_read_sim_req_struct *data_ptr;
    U8 path[6] = {0x7F, 0x10, 0x5F, 0x50, 0x4F, 0x01};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(PRT_MMI_SMU_READ_SIM_RSP, (PsIntFuncPtr) srv_sat_read_sim_rsp, MMI_TRUE);

    data_ptr = (mmi_smu_read_sim_req_struct*) OslConstructDataPtr(sizeof(mmi_smu_read_sim_req_struct));
    data_ptr->file_idx = FILE_NONE;
    data_ptr->para = offset;
    data_ptr->length = length;
    path[5] += instance - 0x4F01;
    memcpy(data_ptr->path, path, 6 * sizeof(U8));
    data_ptr->access_id = 0xF1;

    mmi_frm_send_ilm(SATID_2_L4CID(sat_id), PRT_MMI_SMU_READ_SIM_REQ, (oslParaType*) data_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_icon_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_do_icon_callback(srv_sat_enum sat_id, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_image_struct *image = &g_srv_sat_image[sat_id];
    S32 width, height;
    S32 bmp_data_size, bmp_info_size, bmp_file_size;
    S32 image_data_size, i;
    U8 *image_data_ptr, *image_body_ptr;
    U16 black, white, pixel_data;
    U8 bit_count, bit_index, clut_index, j;
    U8 bit_mask, bit_mask1, bit_mask2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        width = image->image_instance->width;
        height = image->image_instance->height;
        bmp_data_size = width * height * 2;
        bmp_info_size = 13 + bmp_data_size;
        bmp_file_size = 8 + bmp_info_size;

        if (bmp_file_size <= 2048 && width == image->image_data[0] && height == image->image_data[1])
        {
            image->icon_data = (U8*) OslMalloc(bmp_file_size * sizeof(U8));
            memset(image->icon_data, 0, bmp_file_size * sizeof(U8));
            image->icon_data[0] = IMAGE_TYPE_DEVICE_BITMAP;
            image->icon_data[1] = 1;
            image->icon_data[2] = bmp_info_size & 0xFF;
            image->icon_data[3] = (bmp_info_size >> 8) & 0xFF;
            image->icon_data[4] = (bmp_info_size >> 16) & 0xFF;
            image->icon_data[5] = height & 0xFF;
            image->icon_data[6] = ((height >> 8) & 0x0F) | ((width & 0x0F) << 4);
            image->icon_data[7] = (width >> 4) & 0xFF;
            image->icon_data[8] = width & 0xFF;
            image->icon_data[12] = height & 0xFF;
            image->icon_data[16] = 0x10;
            image->icon_data[17] = (width * 2) & 0xFF;
            image->icon_data[18] = ((width * 2) >> 8) & 0xFF;

            image_data_size = width * height;
            image_data_ptr = image->icon_data + 8 + 13;

            if (image->image_instance->coding == SRV_SAT_BASIC_IMAGE)
            {
                white = gdi_act_color_from_rgb(255, 255, 255, 255);
                black = gdi_act_color_from_rgb(255, 0, 0, 0);
                for (i = 0; i < image_data_size; i++)
                {
                    pixel_data = (*(image->image_data + 2 + i / 8) >> (7 - (i % 8))) & 0x01 ? black : white;
                    *(image_data_ptr + 2 * i) = pixel_data & 0xFF;
                    *(image_data_ptr + 2 * i + 1) = (pixel_data >> 8) & 0xFF;
                }
            }
            else if (image->image_instance->coding == SRV_SAT_COLOR_IMAGE || image->image_instance->coding == SRV_SAT_TRANSPARENT_IMAGE)
            {
                bit_count = *(image->image_data + 2);
                bit_index = 0;
                bit_mask = 0x01;
                for (i = 0; i < bit_count; i++)
                {
                    bit_mask = 2 * bit_mask;
                }
                bit_mask = bit_mask - 1;
                image_body_ptr = image->image_data + 6;
                for (i = 0; i < image_data_size; i++)
                {
                    if ((bit_count + bit_index) < 8)
                    {
                        clut_index = ((*image_body_ptr) >> (8 - bit_count - bit_index)) & bit_mask;
                        bit_index = bit_index + bit_count;
                    }
                    else
                    {
                        bit_mask1 = 0x01;
                        for (j = 0; j < 8 - bit_index; j++)
                        {
                            bit_mask1 = 2 * bit_mask1;
                        }
                        bit_mask1 = bit_mask1 - 1;
                        if ((8 - bit_count - bit_index) == 0)
                        {
                            clut_index = (*image_body_ptr) & bit_mask1;
                        }
                        else
                        {
                            bit_mask2 = 0x01;
                            for (j = 0; j < bit_count + bit_index - 8; j++)
                            {
                                bit_mask2 = 2 * bit_mask2;
                            }
                            bit_mask2 = bit_mask2 - 1;
                            clut_index = ((*image_body_ptr) & bit_mask1) + (((*image_body_ptr + 1) >> (8 - (bit_count + bit_index - 8))) & bit_mask2);
                        }
                        image_body_ptr++;
                        bit_index = (bit_index + bit_count) % 8;
                    }

                    if (image->image_instance->coding == SRV_SAT_TRANSPARENT_IMAGE &&
                        clut_index == image->image_clut->number - 1)
                    {
                        pixel_data = DEVICE_BMP_TRANSPARENT_COLOR_16;
                    }
                    else
                    {
                        pixel_data = gdi_act_color_from_rgb(
                                        255,
                                        image->image_clut->data[clut_index].red,
                                        image->image_clut->data[clut_index].green,
                                        image->image_clut->data[clut_index].blue);
                    }

                    *(image_data_ptr + 2 * i) = pixel_data & 0xFF;
                    *(image_data_ptr + 2 * i + 1) = (pixel_data >> 8) & 0xFF;
                }
            }
        }
        else
        {
            result = MMI_FALSE;
        }
    }

    if (image->image_instance)
    {
        OslMfree(image->image_instance);
        image->image_instance = NULL;
    }
    if (image->image_data)
    {
        OslMfree(image->image_data);
        image->image_data = NULL;
    }
    if (image->image_clut)
    {
        if (image->image_clut->data)
        {
            OslMfree(image->image_clut->data);
            image->image_clut->data = NULL;
        }
        OslMfree(image->image_clut);
        image->image_clut = NULL;
    }
    image->callback(sat_id, result, image->icon_data, image->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 *  icon_id     [IN]        
 *  callback    [IN]        
 *  user_data   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sat_do_icon(srv_sat_enum sat_id, U8 icon_id, srv_sat_do_icon_callback_type callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_image_struct *image = &g_srv_sat_image[sat_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_srv_sat_image[sat_id], 0x00, sizeof(srv_sat_image_struct));
    image->icon_id = icon_id;
    image->callback = callback;
    image->user_data = user_data;
    image->stage = SRV_SAT_STAGE_READ_INFO;
    srv_sat_read_file_info_req(sat_id);
}

#endif /* SATICONSRV_C */
#endif /* __SAT_DISABLE_ICON_SUPPORT__ */
