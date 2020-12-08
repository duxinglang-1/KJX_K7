#include "vapp_wallpaper_video_decoder.h"
#include "MMIDataType.h"
#include "FileMgrSrvGprot.h"
#include "Unicodexdcl.h"

#define IVLW_ABM_WORKAROUND
#if defined(IVLW_ABM_WORKAROUND)
#include "gdi_image_alpha_bmp_v2.h"
static IVLW_DEC_STATUS
_ivlwAB2Decode(
   IVLW_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
   int ret = 0;
   gdi_image_ab2_info_struct info;
   gdi_image_ab2_img_buf_struct img_buf;

   gdi_image_ab2_read_header(&info, src_buf);
   img_buf.pixel_bytes = 2;
   img_buf.cf = GDI_COLOR_FORMAT_16;
   if (IVLW_COLOR_RGB888 == handle->output_format)
   {
      img_buf.pixel_bytes = 3;
      img_buf.cf = GDI_COLOR_FORMAT_24;
   }
   img_buf.ptr = (U8 *)dstBuf;
   img_buf.pitch_bytes = info.width * img_buf.pixel_bytes;

   /* gdi_image_ab2_draw_to_buf_internal
     ** This function will process BMP R/B channel swap. Thus for AB2 encoder part,
     ** we don't need to do R/B channel swap. Otherwise, the output result will be wrong.
     */
   ret = gdi_image_ab2_draw_to_buf_decode_mode(&img_buf,
                              0, 0, src_buf,
                              GDI_IMAGE_AB2_DECODE_MODE_OUTPUT);
   if (GDI_SUCCEED != ret)
   {
      return IVLW_DEC_STATUS_FAIL;
   }
   return IVLW_DEC_STATUS_OK;
}
#endif

static int g_use_abm = 0;
wallpaper_async_get_frame_callback g_vapp_wallpaper_fs_cb;

extern int wallpaperDecGetTypeFromFileName(WCHAR* fileName)
{
    WCHAR *ext = (WCHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)fileName);
    if(0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"mwp", 3) ||
       0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"ivlw", 3) ||
       0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"rwp", 3))
    {
        return 1;
    }
    else if(0 == mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"lwp", 3))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

extern void wallpaperDecSetType(int useABM)
{
    g_use_abm = useABM;
}

static IVLW_COLOR_FORMAT getIVLWColorFormat(VAPP_WP_COLOR_FORMAT wpFormat)
{
    switch(wpFormat)
    {
    case VAPP_WP_RGB565:
        return IVLW_COLOR_RGB565;
    case VAPP_WP_RGB888:
        return IVLW_COLOR_RGB888;
    default:
        ASSERT(0);
        return IVLW_COLOR_RGB565;
    }
}


static IVLW_FILE_ACCESS_MODE_ENUM getIVLWFileMode(VAPP_WP_READ_FILE_MODE_ENUM mode)
{
    switch(mode)
    {
    case VAPP_WP_READ_FILE_SYNC:
        return IVLW_READ_FILE_SYNC;
    case VAPP_WP_READ_FILE_ASYNC:
        return IVLW_READ_FILE_ASYNC;
    case VAPP_WP_READ_FILE_RSVD:
        return IVLW_READ_FILE_RSVD;
    default:
        ASSERT(0);
        return IVLW_READ_FILE_SYNC;
    }
}

static LWP_READ_FILE_MODE_ENUM getLWPFileMode(VAPP_WP_READ_FILE_MODE_ENUM mode)
{
    switch(mode)
    {
    case VAPP_WP_READ_FILE_SYNC:
        return LWP_READ_FILE_SYNC;
    case VAPP_WP_READ_FILE_ASYNC:
        return LWP_READ_FILE_ASYNC;
    case VAPP_WP_READ_FILE_RSVD:
        return LWP_READ_FILE_RSVD;
    default:
        ASSERT(0);
        return LWP_READ_FILE_SYNC;
    }
}

void _async_get_frame_callback(IVLW_DEC_STATUS error_code, void *callback_para)
{
    if (NULL == g_vapp_wallpaper_fs_cb)
    {
       return;
    }

    if(g_use_abm)
    {
        if(error_code != IVLW_DEC_STATUS_OK)
            g_vapp_wallpaper_fs_cb(VAPP_WP_DEC_STATUS_NG, callback_para);
        else
            g_vapp_wallpaper_fs_cb(VAPP_WP_DEC_STATUS_OK, callback_para);
    }
    else
    {
        if(error_code != LWP_STATUS_OK)
            g_vapp_wallpaper_fs_cb(VAPP_WP_DEC_STATUS_NG, callback_para);
        else
            g_vapp_wallpaper_fs_cb(VAPP_WP_DEC_STATUS_OK, callback_para);
    }
}

VAPP_WP_DEC_STATUS wallpaperDecGetHandle(VAPP_WP_DECODER_HANDLE** handlePtr)
{
    if(g_use_abm)
    {

        IVLW_DEC_STATUS ret = ivlwDecGetHandle(handlePtr);

    #if defined(IVLW_ABM_WORKAROUND)
        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;

        ret = ivlwDecSetDecodeFunc(*handlePtr, _ivlwAB2Decode);
    #endif

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {

        LWP_DEC_STATUS ret = lwpDecGetHandle((LWP_DECODER_HANDLE **)handlePtr);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
}

VAPP_WP_DEC_STATUS wallpaperDecReleaseHandle(VAPP_WP_DECODER_HANDLE** handle)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecReleaseHandle(handle);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecReleaseHandle((LWP_DECODER_HANDLE **)handle);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecSetSrcFile(VAPP_WP_DECODER_HANDLE* handle, STFSAL *fp)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetSrcFile(handle,fp);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {

        LWP_DEC_STATUS ret = lwpDecSetSrcFile((LWP_DECODER_HANDLE *)handle,fp);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecSetAllocAndFree(VAPP_WP_DECODER_HANDLE* handle, alloc_func alloc_func, free_func free_func)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetAllocAndFree(handle,alloc_func,free_func);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecSetAllocAndFree((LWP_DECODER_HANDLE *)handle,alloc_func,free_func);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecQuerySrcResolution(VAPP_WP_DECODER_HANDLE* handle, unsigned int* width, unsigned int* height)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQuerySrcResolution(handle,width,height);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcResolution((LWP_DECODER_HANDLE *)handle,width,height);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecQuerySrcFormat(VAPP_WP_DECODER_HANDLE* handle, VAPP_WP_COLOR_FORMAT *colorFormat)
{
    if(g_use_abm)
    {
        (*colorFormat) = VAPP_WP_RGB565;

        return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcFormat((LWP_DECODER_HANDLE *)handle, (LWP_DEC_COLOR_FORMAT *)colorFormat);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecSetDstFormat(VAPP_WP_DECODER_HANDLE* handle, VAPP_WP_COLOR_FORMAT colorFormat)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecSetDstFormat(handle, getIVLWColorFormat(colorFormat));

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        return VAPP_WP_DEC_STATUS_OK;
    }
}


VAPP_WP_DEC_STATUS wallpaperDecQueryFrameCount(VAPP_WP_DECODER_HANDLE* handle, unsigned int *frameCnt)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryFrameCount(handle, frameCnt);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameCount((LWP_DECODER_HANDLE *)handle, frameCnt);

        if(ret != LWP_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}


VAPP_WP_DEC_STATUS wallpaperDecQueryPartitionCount(VAPP_WP_DECODER_HANDLE* handle, unsigned int *partitionCnt)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryPartitionCount(handle, partitionCnt);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        (*partitionCnt) = 1;

        return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecQueryPartitionInfo(VAPP_WP_DECODER_HANDLE* handle, unsigned int partitionIdx, unsigned int *frame_count, unsigned int *frame_start_index)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryPartitionInfo(handle, partitionIdx, frame_count, frame_start_index);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameCount((LWP_DECODER_HANDLE *)handle, frame_count);

        (*frame_start_index) = 0;

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecQuerySrcFrameBufSize(VAPP_WP_DECODER_HANDLE* handle, unsigned int frame_index, unsigned int *buf_size)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQuerySrcFrameBufSize(handle, frame_index, buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQuerySrcFrameBufSize((LWP_DECODER_HANDLE *)handle, frame_index, buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS wallpaperDecQueryFrameHeaderLength(VAPP_WP_DECODER_HANDLE* handle, unsigned int *frame_header_len)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecQueryFrameHeaderLength(handle, frame_header_len);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecQueryFrameHeaderLength((LWP_DECODER_HANDLE *)handle, frame_header_len);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}


VAPP_WP_DEC_STATUS
wallpaperDecGetFrameSrcBuf(
   VAPP_WP_DECODER_HANDLE *handle,
   VAPP_WP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   wallpaper_async_get_frame_callback  callback,
   void *param)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret;

        g_vapp_wallpaper_fs_cb = callback;
        ret = ivlwDecGetFrameSrcBuf(
                    handle,
                    getIVLWFileMode(read_mode),
                    frame_index,
                    src_buf,
                    src_buf_size,
                    actual_rd_size,
                    _async_get_frame_callback,
                    param);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret;

        g_vapp_wallpaper_fs_cb = callback;
        ret = lwpDecGetFrameSrcBuf(
                    (LWP_DECODER_HANDLE *)handle,
                    getLWPFileMode(read_mode),
                    frame_index,
                    src_buf,
                    src_buf_size,
                    actual_rd_size,
                    (lwp_async_get_frame_callback)_async_get_frame_callback,
                    param);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

VAPP_WP_DEC_STATUS
wallpaperDecAbortGetFrameSrcBuf(
   VAPP_WP_DECODER_HANDLE *handle)
{
    IVLW_DEC_STATUS ret = IVLW_DEC_STATUS_OK;
    if(g_use_abm)
    {
        extern IVLW_DEC_STATUS ivlwDecAbortGetFrameSrcBuf(IVLW_DECODER_HANDLE *handle);
        ret = ivlwDecAbortGetFrameSrcBuf((IVLW_DECODER_HANDLE*)handle);
        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
    else
    {
        return VAPP_WP_DEC_STATUS_OK;
    }
}


VAPP_WP_DEC_STATUS
wallpaperDecGetFramePixelData(
   VAPP_WP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size)
{
    if(g_use_abm)
    {
        IVLW_DEC_STATUS ret = ivlwDecGetFramePixelData(
                                    handle,
                                    src_buf,
                                    src_buf_size,
                                    dstBuf,
                                    dst_buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;

    }
    else
    {
        LWP_DEC_STATUS ret = lwpDecGetFramePixelData(
                                    (LWP_DECODER_HANDLE *)handle,
                                    src_buf,
                                    src_buf_size,
                                    dstBuf,
                                    dst_buf_size);

        if(ret != IVLW_DEC_STATUS_OK)
            return VAPP_WP_DEC_STATUS_NG;
        else
            return VAPP_WP_DEC_STATUS_OK;
    }
}

