#ifndef __SWJD_SW_RESIZE_Y2R_6666_H__
#define __SWJD_SW_RESIZE_Y2R_6666_H__

#include "swjd_fragment_processor.h"

#ifdef __cplusplus
extern "C" {
#endif

FRAG_PROCESSOR_STATUS_ENUM _frag_proc_func_yuv4xx_to_argb6666_no_resize(SWJD_FRAGMENT_PROCESSOR *pProcessor,
                                                                        kal_int32               dstWidth,
                                                                        kal_int32               dstHeight);


FRAG_PROCESSOR_STATUS_ENUM _frag_proc_func_yuv4xx_to_argb6666_bilinear(SWJD_FRAGMENT_PROCESSOR  *pProcessor,
                                                                       kal_int32                dstWidth,
                                                                       kal_int32                dstHeight);

#ifdef __cplusplus
}
#endif

#endif  // __SWJD_SW_RESIZE_Y2R_6666_H__
