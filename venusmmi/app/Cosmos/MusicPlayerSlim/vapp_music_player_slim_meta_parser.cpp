
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#include "vapp_music_player_slim_meta_parser.h"
#include "vapp_music_player_slim_util.h"

/***************************************************************************** 
 * VappMusicPlayerSoundEffect Implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappMusicPlayerMetaParser", VappMusicPlayerMetaParser, VfxObject);

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

artist_info_struct* VappMusicPlayerMetaParser::getAudioInfo(void)
{
    VfxU8 parser_ret;
    artist_info_struct *artist;
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
    m_infoBuffer = applib_asm_alloc_nc_r(appID, sizeof(artist_info_struct));
    kal_mem_set(m_infoBuffer, 0, sizeof(artist_info_struct));

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
    artist = reinterpret_cast<artist_info_struct*>(m_infoBuffer);

    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0 &&
       (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
    {
        mmi_ucs2ncpy((CHAR*)artist->artist, 
               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
               META_TAG_FRAME_MAX_LEN);
        artist->artist[(music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1)] = 0;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_AUDIO_INFO_OK);

    return artist;
}

VfxBool VappMusicPlayerMetaParser::getCover(VfxS32 dest_width, VfxS32 dest_height, VfxImageBuffer &imgBuf, VfxBool noBG)
{
    VfxU8 parser_ret;
    meta_tag_img_info_struct* image_info_p = NULL;
    void *meta_img_buffer;
    GDI_RESULT gdi_result;
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
	//mmi_id appID = app->getCallerId();

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

    /* Define destination image size */
    S32 x = 0, y = 0, resize_w, resize_h;

    /* Get source image dimension */
    gdi_result = gdi_image_get_dimension_mem(gdi_img_type, reinterpret_cast<U8*>(meta_img_buffer), image_info_p->data_size, &resize_w, &resize_h);
    if(gdi_result != GDI_SUCCEED)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_FAIL, dest_width, dest_height, noBG);
        applib_asm_free_r(appID, meta_img_buffer);
        return VFX_FALSE;
    }

        gdi_image_util_fit_bbox(dest_width, dest_height, resize_w, resize_h, &x, &y, &resize_w, &resize_h);

    VfxU32 bufferSize = resize_w * resize_h * 2;
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
        resize_w,
        resize_h,
        &src_layer,
        reinterpret_cast<U8*>(m_imageBuffer),
        bufferSize);   

    /* Resize image and push to layer */
    gdi_layer_push_and_set_active(src_layer);
    gdi_push_and_set_alpha_blending_source_layer(src_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_result = gdi_image_draw_resized_mem(0, 0, resize_w, resize_h, reinterpret_cast<U8*>(meta_img_buffer), gdi_img_type, image_info_p->data_size);

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
    imgBuf.pitchBytes = resize_w * 2;
    imgBuf.width = resize_w;
    imgBuf.height = resize_h;
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    imgBuf.ptr = (VfxU8*)m_imageBuffer;

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_MUSICPLY_META_PARSER_GET_COVER_OK, dest_width, dest_height, resize_w, resize_h, noBG);

    return VFX_TRUE; 
}




#endif //__MMI_MUSIC_PLAYER_SLIM__

