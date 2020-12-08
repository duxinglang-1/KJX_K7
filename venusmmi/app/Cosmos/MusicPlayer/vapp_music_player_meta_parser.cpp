/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_music_player_meta_parser.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player meta parser object
 *
 * Author:
 * -------
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "vapp_music_player_meta_parser.h"
#include "vapp_music_player_util.h"

extern "C"
{
#include "meta_tag_api.h"
}

/***************************************************************************** 
 * VappMusicPlayerSoundEffect Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerMetaParser", VappMusicPlayerMetaParser, VfxObject);

VappMusicPlayerMetaParser::VappMusicPlayerMetaParser():
m_parserHdlr(0),
m_parserBuffer(NULL),
m_imageBuffer(NULL),
m_infoBuffer(NULL)
{
}

void VappMusicPlayerMetaParser::onInit()
{
    VfxObject::onInit();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_ONINIT);
}

void VappMusicPlayerMetaParser::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_ONDEINIT);

    /* Free parser handle */
    if(m_parserHdlr)
    {
        meta_parser_release(m_parserHdlr);
    }

    /* Free parser buffer */
    if(m_parserBuffer)
    {
        VFX_FREE_MEM(m_parserBuffer);
    }

    VfxApp *app = findRootApp(this);
    mmi_id appID = app->getGroupId();

    /* Free meta info buffer */
    if(m_infoBuffer)
    {
        applib_asm_free_r(appID, m_infoBuffer);
        m_infoBuffer = NULL;
    }

    /* Free image buffer */
    if(m_imageBuffer)
    {
        applib_asm_free_r(appID, m_imageBuffer);
        m_imageBuffer = NULL;
    }

    VfxObject::onDeinit();
}

VfxBool VappMusicPlayerMetaParser::parseFile(VfxWString &filePath)
{
    VfxU8 parser_ret;

    /* Allocate base memory for meta parser */
    if(m_parserBuffer == NULL)
    {
        VFX_ALLOC_MEM(m_parserBuffer, META_TAG_PARSE_MIN_SIZE, this);
    }

    /* Create parser */
    if(m_parserHdlr == 0)
    {
        parser_ret = meta_parser_create(m_parserBuffer, META_TAG_PARSE_MIN_SIZE, &m_parserHdlr);
        if (parser_ret > 0 && parser_ret < META_TAG_ERR_TOTAL)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_PARSE_FILE_FAIL);
            return VFX_FALSE;
        }
    }

    /* Parse file */
    parser_ret = meta_parse_file(m_parserHdlr, (kal_uint16*)filePath.getBuf());
    if (parser_ret > 0 && parser_ret < META_TAG_ERR_TOTAL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_PARSE_FILE_FAIL);
        return VFX_FALSE;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_PARSE_FILE_OK);
    return VFX_TRUE;
}

srv_plst_media_details_struct* VappMusicPlayerMetaParser::getAudioInfo(void)
{
    VfxU8 parser_ret;
    srv_plst_media_details_struct *details;
    meta_tag_music_info_struct* music_info_p = NULL;

    /* Need to parse file and create handle first */
    if(m_parserHdlr == 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_AUDIO_INFO_FAIL);
        return NULL;
    }

    VfxApp *app = findRootApp(this);
    mmi_id appID = app->getGroupId();

    /* Allocate foreground memory to get meta info from meta */
    if(m_infoBuffer != NULL)
    {
        applib_asm_free_r(appID, m_infoBuffer);
    }    
    m_infoBuffer = applib_asm_alloc_nc_r(appID, sizeof(srv_plst_media_details_struct));
    kal_mem_set(m_infoBuffer, 0, sizeof(srv_plst_media_details_struct));

    /* get "music info" struct. */
    parser_ret = meta_get_music_info(m_parserHdlr, &music_info_p);
    if(META_TAG_ERR_NONE != parser_ret)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_AUDIO_INFO_FAIL);

        applib_asm_free_r(appID, m_infoBuffer);
        m_infoBuffer = NULL;
        return NULL;
    }

    /* Copy data to buffer, currently only copy data need by music player */
    details = reinterpret_cast<srv_plst_media_details_struct*>(m_infoBuffer);

    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0 &&
       (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
    {
        mmi_ucs2ncpy((CHAR*)details->artist, 
               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
               META_TAG_FRAME_MAX_LEN);
        details->artist[(music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1)] = 0;
    }

    if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0 && 
      (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)                    
    {
        mmi_ucs2ncpy((CHAR*)details->album, 
               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
               META_TAG_FRAME_MAX_LEN);
        details->album[(music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1)] = 0;
    }

    if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0 && 
      (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
    {
        mmi_ucs2ncpy((CHAR*)details->title, 
               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
               META_TAG_FRAME_MAX_LEN);
        details->title[(music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1)] = 0;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_AUDIO_INFO_OK);

    return details;
}

VfxBool VappMusicPlayerMetaParser::getCover(VfxS32 dest_width, VfxS32 dest_height, VfxImageBuffer &imgBuf, VfxBool noBG)
{
    VfxU8 parser_ret;
    meta_tag_img_info_struct* image_info_p = NULL;
    void *meta_img_buffer;
    GDI_RESULT gdi_result;
    S32 w, h; 
    gdi_handle src_layer;

    /* Need to parse file and create handle first */
    if(m_parserHdlr == 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        return VFX_FALSE;
    }

    /* Get cover image info */
    meta_get_attach_cover_info(m_parserHdlr, &image_info_p);
    if((image_info_p->data_size == 0) || (image_info_p->data_size > VAPP_MUSICPLY_META_FILE_IMAGE_SIZE))
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        return VFX_FALSE;
    }

    /* Allocate foreground memory to get image from meta */
    VfxApp *app = findRootApp(this);
    mmi_id appID = app->getGroupId();

    meta_img_buffer = applib_asm_alloc_nc_r(appID, image_info_p->data_size);

    if (meta_img_buffer == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        return VFX_FALSE;
    }

    /* Copy image to buffer */
    parser_ret = meta_get_attach_cover_data(m_parserHdlr, (kal_uint8*)meta_img_buffer, image_info_p->data_size);
    if (parser_ret > 0 && parser_ret < META_TAG_ERR_TOTAL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        applib_asm_free_r(appID, meta_img_buffer);
        return VFX_FALSE;
    }

    /* Get image type */
    VfxU8 gdi_img_type = GDI_IMAGE_TYPE_INVALID;    
    switch(image_info_p->mime_type)
    {
        case META_TAG_IMG_PNG :    
            gdi_img_type = GDI_IMAGE_TYPE_PNG; break;
        case META_TAG_IMG_JPG:     
            gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
        case META_TAG_IMG_JPEG:   
            gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
        case META_TAG_IMG_GIF:  
            gdi_img_type = GDI_IMAGE_TYPE_GIF; break;
        case META_TAG_IMG_BMP:  
            gdi_img_type = GDI_IMAGE_TYPE_BMP; break;
        default:             
            break;
    }

    /* Get source image dimension */
    gdi_result = gdi_image_get_dimension_mem(gdi_img_type, reinterpret_cast<U8*>(meta_img_buffer), image_info_p->data_size, &w, &h);
    if(gdi_result != GDI_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        applib_asm_free_r(appID, meta_img_buffer);
        return VFX_FALSE;
    }

    /* Define destination image size */
    S32 x = 0, y = 0, resize_w = w, resize_h = h;
    if (w > dest_width || h > dest_height)
    {
        gdi_image_util_fit_bbox(dest_width, dest_height, w, h, &x, &y, &resize_w, &resize_h);
    }
    else if (!noBG)
    {
        if ((w <= dest_width && h <= dest_height))
        {
            VfxS32 s = vfxMax(w, h);
            gdi_image_util_fit_bbox(s, s, dest_width, dest_height, &x, &y, &dest_width, &dest_height);
        }
        
        gdi_image_util_fit_bbox(dest_width, dest_height, w, h, &x, &y, &resize_w, &resize_h);
    }
    
    VfxU32 bufferSize, offsetX, offsetY, tarWidth, tarHeight;
    if (noBG)
    {
		offsetX = 0;
        offsetY = 0;
		tarWidth = resize_w;
		tarHeight = resize_h;
    }
    else
    {
        offsetX = x;
        offsetY = y;
		tarWidth = dest_width;
		tarHeight = dest_height;
    }

	bufferSize = tarWidth * tarHeight * 2;

    if(bufferSize == 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        applib_asm_free_r(appID, meta_img_buffer);
        return VFX_FALSE;
    }

    /* Allocate memory for resize image */
    if(m_imageBuffer != NULL)
    {
        applib_asm_free_r(appID, m_imageBuffer);
    }
    m_imageBuffer = applib_asm_alloc_nc_r(appID, bufferSize);

    if (m_imageBuffer == NULL)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        applib_asm_free_r(appID, meta_img_buffer);
        return VFX_FALSE;
    }

    /* Create layer */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        tarWidth,
        tarHeight,
        &src_layer,
        reinterpret_cast<U8*>(m_imageBuffer),
        bufferSize);   

    /* Resize image and push to layer */
    gdi_layer_push_and_set_active(src_layer);
    gdi_push_and_set_alpha_blending_source_layer(src_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_result = gdi_image_draw_resized_mem(offsetX, offsetY, resize_w, resize_h, reinterpret_cast<U8*>(meta_img_buffer), gdi_img_type, image_info_p->data_size);

    gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(src_layer);

    /* Free memory and parser */
    applib_asm_free_r(appID, meta_img_buffer);

    if(gdi_result < GDI_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        /* Free image buffer */
        applib_asm_free_r(appID, m_imageBuffer);
        m_imageBuffer = NULL;
        return VFX_FALSE;
    }

    /* Assign resize image buffer to image buffer */
    imgBuf.pitchBytes = tarWidth * 2;
    imgBuf.width = tarWidth;
    imgBuf.height = tarHeight;
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    imgBuf.ptr = (VfxU8*)m_imageBuffer;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_OK, dest_width, dest_height, tarWidth, tarHeight, noBG);

    return VFX_TRUE; 
}




#endif //__COSMOS_MUSICPLY__

