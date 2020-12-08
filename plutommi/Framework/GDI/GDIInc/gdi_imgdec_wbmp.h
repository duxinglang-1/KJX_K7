/* gdi_imgdec_wbmp.h */
#ifndef _GDI_IMGDEC_WBMP_H_
#define _GDI_IMGDEC_WBMP_H_

#include "gdi_imgdec_internal.h"
#include "gdi_imgdec_bytestream.h"
#include "gdi_imgdec_resizer.h"

typedef struct
{
    GDI_IMGDEC_BASE_STRUCT

    gdi_imgdec_resizer_struct resizer;
    
    gdi_imgdec_bytestream_struct bs;
} gdi_imgdec_wbmp_struct;

extern void gdi_imgdec_wbmp_init(gdi_imgdec_wbmp_struct *dec, gdi_handle out_layer, BOOL *is_aborted, U32 flag);
extern void gdi_imgdec_wbmp_deinit(gdi_imgdec_wbmp_struct *dec);
extern GDI_RESULT gdi_image_wbmp_draw_internal(gdi_imgdec_wbmp_struct *dec, S32 sx, S32 sy, S32 resized_width, S32 resized_height, U32 aspect_flag);
extern GDI_RESULT gdi_imgdec_wbmp_get_dimension(U8 *src, U32 size, S32 *width, S32 *height);


#endif
