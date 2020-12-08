#ifndef _VM_SAL_VIDEO_H
#define _VM_SAL_VIDEO_H
#include "vmswitch.h"
#ifdef __MRE_SAL_VIDEO__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmvideo.h"

	#include "vmsys.h"

 /**
 *	打开视频文件	
 *	@param filename			完整路径及文件名。
 *    @param open_result_callback	回调函数。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 打开文件成功。
 *  		VM_VIDEO_ERR_DRM_PROHIBITED : 不能打开视频文件因drm被禁止。
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : 不能打开视频因内存不足。
 *  		VM_VIDEO_ERR_FILE_TOO_LARGE : 不能打开视频因文件太大。
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : 不能打开视频因帧率太高。
 *		VM_VIDEO_ERR_INVALID_RESOULTION: 不能打开视频因分辨率不对。
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : 其它原因不能打开视频。
 */
 VMINT stub_video_open_file(
                    const VMWSTR filename,
                    vm_video_open_result_callback open_result_callback);


 /**
 *	关闭视频文件。	
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 关闭文件成功。
 *  		VM_VIDEO_FAILED : 关闭文件失败。
 */
 VMINT stub_video_close_file(void);


 /**
 *	使用指定缓存数据打开视频。
 *    @param buffer	视频缓存数据指针。
 *    @param buffer_len	缓存长度。
 *    @param info		得到的视频信息结构。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 打开成功。
 *  		VM_VIDEO_ERR_MEMORY_INSUFFICIENT : 没有足够内存打开失败。
 *  		VM_VIDEO_ERR_FRAMERATE_TOO_HIGH : 帧率太高打开失败。
 *  		VM_VIDEO_ERR_OPEN_FILE_FAILED : 打开失败。
 */
  VMINT stub_video_open_buffer(
                    const VMUSTR buffer,
                    const VMUINT buffer_len,
                    vm_video_info_struct *info);
 
                    
 /**
 *	关闭视频缓存数据，与vm_video_open_buffer成对使用。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 关闭文件成功。
 *  		VM_VIDEO_FAILED : 关闭文件失败。
 */
 VMINT stub_video_close_buffer(void);


 /**
 *	打开视频（根据平台特性支持3gp/mp4）。
 *    播放接口需要知道层的叠放顺序，因此请保证使用前已进行过vm_graphic_flush_layer操作，否则可能花屏。
 *    @param player_layer_handle		播放层的句柄（建议使用第一次创建层时返回的句柄）。
 *   @param base_layer_handle		工具层的句柄（建议使用第二次创建层时返回的句柄）。
 *    @param repeat_count			重复播放次数，0表示重复播放。
 *    @param is_play_audio			是否播放音频（TRUE/FALSE ）。
 *    @param audio_path			音频播放路径（使用vmmm.h中定义，如VM_DEVICE_SPEAKER2）。
 *    @param rotate				旋转角度（如：VM_VIDEO_LCD_ROTATE_0）。
 *    @param play_finish_callback		回调函数。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 开始播放成功。
 *  		VM_VIDEO_ERR_DRM_PROHIBITED :因数字版权不能打开视频文件。
 *  		VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH : 数据不足以用来播放。
 *  		VM_VIDEO_ERR_PLAY_FAILED : 播放失败。
 */
 VMINT stub_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_visual_update,
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    VMUINT16 rotate, 
                    VMUINT16 play_speed,
                    vm_video_finish_callback play_finish_callback);


/**
 *	 停止播放。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 关闭文件成功。
 *		VM_VIDEO_FAILED : 停止失败。
 */
 VMINT stub_video_stop(void);



 /**
 *	定位视频到指定时间点并显示此时间点画面。
 *    @param time		时间 （毫秒）。
 *    @param player_layer_handle		播放层句柄。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT stub_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle);


 /**
 *	抓图保存为指定的文件，文件格式JPEG。
 *    @param player_layer_handle		播放层句柄。
 *    @param file_name			保存的文件名(UCS2)。.
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 抓图成功。
 *  		VM_VIDEO_ERR_SNAPSHOT_DISK_FULL : 磁盘已满，抓图失败。
 *  		VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION : 写保护，抓图失败。
 * 		VM_VIDEO_ERR_SNAPSHOT_FAILED : 抓图失败。
 */
 VMINT stub_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name);



 /**
 *	设置亮度，关闭后不保存。
 *    @param brightness			亮度值（如:VM_VIDEO_BRIGHTNESS_0 ）。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT stub_video_set_brightness(VMUINT16 brightness);


 /**
 *	 设置对比度，关闭后不保存。
 *    @param contrast			亮度值(如:VM_VIDEO_CONTRAST_0)。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT stub_video_set_contrast(VMUINT16 contrast);



 /**
 *	 得到目前的播放时间。
 *    @param cur_play_time			返回当前播放时间。
 *	@return 			
 *  		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
 VMINT stub_video_get_cur_play_time(VMUINT64 *cur_play_time); 

/**
 *	根据URL 来打开流媒体视频(将把调用的MREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param url			要打开的视频URL。
 *
 *	@return
 *		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
VMINT vm_sal_video_play_stream_from_rtsp_link(VMWSTR url);

/**
 *	打开sdp 格式的流媒体视频(将把调用的MREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param filename		打开sdp 格式的文件。
 *	@param is_short		是否为8.3 格式的短文件名。TURE为是，FALSE为否。	
 *
 *	@return
 *		VM_VIDEO_SUCCESS : 成功。
 *		VM_VIDEO_FAILED :失败。
 */
VMINT vm_sal_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short);


/*
* 背景音乐挂起
*/

/*
* 背景音乐resume
*/


#ifdef __cplusplus
}
#endif

#endif

#endif
