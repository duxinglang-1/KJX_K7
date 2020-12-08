#ifdef __VIDEO_SUBTITLE_SUPPORT__

#ifndef __SUBTITLE_FONT_H__
#define __SUBTITLE_FONT_H__
#include "subtitlefont_if.h"

extern void fe_subtitle_open(void **pprHandle);
extern void fe_subtitle_close(void **pprHandle);
extern void fe_subtitle_init(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam);
extern void fe_subtitle_set_property(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam); 
extern void fe_subtitle_draw(void *prHandle);
extern void fe_subtitle_deinit(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam);
extern void fe_subtitle_get_property(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam);
extern subtitle_fontengine_struct *subtitle_fontengine_get_table(void);

#endif//__SUBTITLE_FONT_H__

#endif
