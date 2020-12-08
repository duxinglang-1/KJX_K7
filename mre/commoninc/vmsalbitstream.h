

#ifndef __VM_SAL_BITSTREAM__
#define __VM_SAL_BITSTREAM__
#include "vmswitch.h"
#ifdef __MRE_SAL_BITSTREAM__

#include "vmsys.h"
#include "vmbitstream.h"

/**
 * (SAL 层函数)
 * 以bitstream 方式打开音频资源。
 *
 * @param handle			打开的bitstream 句柄。
 * @param audio_type		音频资源的类型。
 * @param result_callback	音频回调函数。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_open(
	VMINT* handle,
	vm_bitstream_audio_cfg_struct *audio_type,
	vm_bitstream_audio_result_callback callback);

VMINT vm_sal_bitstream_audio_open_pcm(VMINT* handle, vm_bitstream_pcm_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback);

/**
 * (SAL 层函数)
 * 关闭以bitstream 方式打开的音频文件。
 *
 * @param handle			由vm_bitstream_audio_open 打开的bitstream 句柄。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_close(VMINT handle);

/**
 * (SAL 层函数)
 * 根据bitstream 句柄获取音频缓冲结构体。
 *
 * @param handle			打开的bitstream 句柄。
 * @param status			得到的音频缓冲结构体。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_get_buffer_status(
	VMINT handle, 
	vm_bitstream_audio_buffer_status *status);

/**
 * (SAL 层函数)
 * 将指定大小的音频数据写入音频缓冲区内，并通过参数used_size 验证真实写入数据大小。
 *
 * @param handle			打开的bitstream 句柄。
 * @param buffer			待写入音频缓冲区的内存地址指针。
 * @param buffer_size		要写入的缓冲的字节数。
 * @param used_size		实际写入缓冲的字节数。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_put_data(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT 	buffer_size,
	VMUINT	*written);

 /**
 * (SAL 层函数)
 * 将指定时间的音频数据写入音频缓冲区内，如果数据大小超过缓冲区将导致失败。
 *
 * @param handle			打开的bitstream 句柄。
 * @param buffer			待写入音频缓冲区的数据指针。
 * @param buffer_size		要写入的缓冲的大小。
 * @param used_size		要写入缓冲的音频时间(单位：毫秒)。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_put_frame(
	VMINT 	handle,
	VMUINT8 *buffer,
	VMUINT	buffer_size,
	VMUINT 	timestamp);

/**
 * (SAL 层函数)
 * 开始播放BitStream Audio 音频。
 *
 * @param handle			要播放的bitstream 句柄。
 * @param para			播放音频时参数结构体。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_start(
	VMINT handle,
	vm_bitstream_audio_start_param *para);

/**
 * (SAL 层函数)
 * 停止播放BitStream Audio 音频。
 *
 * @param handle			要停止播放的bitstream 句柄。
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_stop(VMINT handle);

/**
 * (SAL 层函数)
 * 获取当前播放时间。
 *
 * @param handle			要获取播放时间的bitstream 句柄。
 * @param current_time		获得的当前播放时间(单位：毫秒)
 *
 * @return				返回VM_BITSTREAM_SUCCEED 表示成功，VM_BITSTREAM_FAILED 为失败。
 */
VMINT vm_sal_bitstream_audio_get_play_time(
	VMINT handle,
	VMUINT* current_time);



VMINT stub_bitstream_audio_open(VMINT* handle, vm_bitstream_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback);
VMINT stub_bitstream_audio_close(VMINT handle);
VMINT stub_bitstream_audio_get_buffer_status(	 VMINT handle, vm_bitstream_audio_buffer_status *status);	 
VMINT stub_bitstream_audio_put_data(VMINT handle,VMUINT8* buffer,VMUINT buffer_size,VMUINT* written);
VMINT stub_bitstream_audio_put_frame(VMINT handle, VMUINT8* buffer, VMUINT buffer_size,VMUINT timestamp);
VMINT stub_bitstream_audio_start(VMINT handle,  vm_bitstream_audio_start_param  *para);
VMINT stub_bitstream_audio_stop(VMINT handle);
VMINT stub_bitstream_audio_get_play_time(VMINT handle, VMUINT* current_time);
#endif /* __VM_SAL_BITSTREAM__ */

#endif

