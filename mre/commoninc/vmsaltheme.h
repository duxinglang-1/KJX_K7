#ifndef VMSALTHEME_H_
#define VMSALTHEME_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif


/**
 * (SAL 层函数)
 * 将指定的主题包设置为当前主题。
 *
 * @param file_name 	要设置为当前主题的包名(注意：只是file name，不是full path)。
 *
 * @return 			返回TRUE 设置成功，否则设置失败。
 */
VMINT vm_sal_set_active_theme(VMUSTR file_name);


/**
 * (SAL 层函数)
 * 将指定的图片设置为当前墙纸。
 *
 * @param file_name 	要设置为当前墙纸的文件名。
 *
 * @return 			返回TRUE 设置成功，否则设置失败。
 */
VMINT vm_sal_set_active_wallpaper(VMUSTR file_name);

#ifdef __cplusplus
}
#endif

#endif /* VMSALTHEME_H_ */
