#ifndef __VAPP_WALLPAPER_DECODER_H__
#define __VAPP_WALLPAPER_DECODER_H__

#ifdef __cplusplus
extern "C"{
#endif

#include "ivlw_common.h"
#include "ivlw_decoder.h"
#include "lwp_decoder.h"

#include "fsal.h"
#include "fs_gprot.h"

typedef enum
{
    VAPP_WP_DEC_STATUS_OK,
    VAPP_WP_DEC_STATUS_NG,
}VAPP_WP_DEC_STATUS;

typedef enum
{
   VAPP_WP_RGB565,
   VAPP_WP_RGB888
}VAPP_WP_COLOR_FORMAT;

typedef enum
{
   VAPP_WP_READ_FILE_SYNC = 0,
   VAPP_WP_READ_FILE_ASYNC,
   VAPP_WP_READ_FILE_RSVD

}VAPP_WP_READ_FILE_MODE_ENUM;

typedef void (*wallpaper_async_get_frame_callback)(VAPP_WP_DEC_STATUS error_code, void *callback_para);
typedef IVLW_DECODER_HANDLE VAPP_WP_DECODER_HANDLE;

extern int wallpaperDecGetTypeFromFileName(WCHAR* fileName);

extern void wallpaperDecSetType(int useABM);

VAPP_WP_DEC_STATUS wallpaperDecGetHandle(VAPP_WP_DECODER_HANDLE** handlePtr);

VAPP_WP_DEC_STATUS wallpaperDecReleaseHandle(VAPP_WP_DECODER_HANDLE** handle);

VAPP_WP_DEC_STATUS wallpaperDecSetSrcFile(VAPP_WP_DECODER_HANDLE* handle, STFSAL *fp);

VAPP_WP_DEC_STATUS
wallpaperDecSetAllocAndFree(
   VAPP_WP_DECODER_HANDLE* handle,
   alloc_func alloc_func,
   free_func free_func);

VAPP_WP_DEC_STATUS
wallpaperDecQuerySrcResolution(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int* width,
   unsigned int* height);

VAPP_WP_DEC_STATUS
wallpaperDecQuerySrcFormat(
   VAPP_WP_DECODER_HANDLE* handle,
   VAPP_WP_COLOR_FORMAT *colorFormat);


VAPP_WP_DEC_STATUS
wallpaperDecSetDstFormat(
   VAPP_WP_DECODER_HANDLE* handle,
   VAPP_WP_COLOR_FORMAT colorFormat);

VAPP_WP_DEC_STATUS
wallpaperDecQueryFrameCount(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int *frameCnt);

VAPP_WP_DEC_STATUS
wallpaperDecQueryPartitionCount(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int *partitionCnt);

VAPP_WP_DEC_STATUS
wallpaperDecQueryPartitionInfo(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int partitionIdx,
   unsigned int *frame_count,
   unsigned int *frame_start_index);

VAPP_WP_DEC_STATUS
wallpaperDecQuerySrcFrameBufSize(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int frame_index,
   unsigned int *buf_size);

//VAPP_WP_DEC_STATUS
//vapp_wallpaperDecQueryDstFrameBufSize(
//   VAPP_WP_DECODER_HANDLE* handle,
//   unsigned int *buf_size);

VAPP_WP_DEC_STATUS
wallpaperDecQueryFrameHeaderLength(
   VAPP_WP_DECODER_HANDLE* handle,
   unsigned int *frame_header_len);

VAPP_WP_DEC_STATUS
wallpaperDecGetFrameSrcBuf(
   VAPP_WP_DECODER_HANDLE *handle,
   VAPP_WP_READ_FILE_MODE_ENUM read_mode,
   unsigned int frame_index,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned int *actual_rd_size,
   wallpaper_async_get_frame_callback  callback,
   void *param);

VAPP_WP_DEC_STATUS
wallpaperDecAbortGetFrameSrcBuf(
   VAPP_WP_DECODER_HANDLE *handle);

VAPP_WP_DEC_STATUS
wallpaperDecGetFramePixelData(
   VAPP_WP_DECODER_HANDLE *handle,
   unsigned char* src_buf,
   unsigned int src_buf_size,
   unsigned char* dstBuf,
   unsigned int dst_buf_size);

#ifdef __cplusplus
}       // __cplusplus extern "C"
#endif

#endif //__VAPP_WP_DECODER_H__

