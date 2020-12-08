#ifndef VMTHEME_H_
#define VMTHEME_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/* vmtheme return code */
typedef enum
{	
	VM_WALLPAPER_ERR_BASE_LAYER_EXIST = -4,	//基层还存在
	VM_WALLPAPER_MIBR_NOT_FORE,				//应用在后台状态
	VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE,  //不支持的 图片类型
	VM_WALLPAPER_ERR_WRONG_PARAM,			//参数错误
	VM_WALLPAPER_SUCCEED					//0
}vm_theme_result;

/*
 * @设置手机的墙纸，不通过手机本地设置墙纸。
 * @设置墙纸必须为前台状态，后台运行的状态调用该接口无效。 
 * @墙纸的格式暂时只支持 "BMP"，"GIF"，"JPG" 三种图片格式，
 * @调用该接口之前必须要删除所有的层
 * @param file_name	 存放墙纸图片的全路径，最长为259字符
 * @容易出现设置失败的地方有 图片的大小，还有图片的宽高 
 *
 * @return	返回VM_WALLPAPER_SUCCEED表示操作成功。
 * @return	返回VM_WALLPAPER_ERR_WRONG_PARAM表示路径的编码格式不正确或者路径为空或者文件不存在，或者手机系统盘内存不足
 * @return	返回VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE不支持的图片类型
 * @return	返回VM_WALLPAPER_ERR_BASE_LAYER_EXIST基层还存在不可以设置墙纸
 * @return	返回VM_WALLPAPER_MIBR_NOT_FORE 应用处在后台状态 
 */
VMINT vm_set_active_wallpaper(VMWCHAR* file_name);


#ifdef __cplusplus
}
#endif

#endif /* VMTHEME_H_ */
