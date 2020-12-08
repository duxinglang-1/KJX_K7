
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#include "gui_text_frame.h"

#include "PixcomFontEngine.h"

#include "Conversions.h"
#include "gd_primitive.h"
#include "subtitleFont_if.h"
#include "subtitleFont.h"
#include "Fonteffects.h"

//operation&flags
typedef struct
{
    gui_text_frame_struct text_frame;
    mmi_chset_enum encoding;
} SUBTITLE_HANDLE;

#define SUBTITLE_MAX_STRING_LENS   256

static stFontAttribute subtitle_font;
static U8 text[SUBTITLE_MAX_STRING_LENS];
static gdi_handle text_layer_handle;
static SUBTITLE_HANDLE subtitle_handle;

subtitle_fontengine_struct subtitle_fontengine;
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
subtitle_fontengine_struct *subtitle_fontengine_get_table(void)
{
	subtitle_fontengine.pfnOpen = fe_subtitle_open;
	subtitle_fontengine.pfnClose = fe_subtitle_close;
	subtitle_fontengine.pfnDraw = fe_subtitle_draw;
	subtitle_fontengine.pfnInit = fe_subtitle_init;
	subtitle_fontengine.pfnDeinit = fe_subtitle_deinit;
	subtitle_fontengine.pfnSetProp = fe_subtitle_set_property;
	subtitle_fontengine.pfnGetProp = fe_subtitle_get_property;
	return &subtitle_fontengine;
}

void fe_subtitle_open(void **pprHandle)
{
	*pprHandle = (void*)&subtitle_handle;
}

void fe_subtitle_close(void **pprHandle)
{
	*pprHandle = NULL;
}


//init subtile handle,set 0
void fe_subtitle_init(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam)
{

	memset(prHandle,0,sizeof(SUBTITLE_HANDLE));
	((SUBTITLE_HANDLE*)prHandle)->text_frame.font = &subtitle_font;
    ((SUBTITLE_HANDLE*)prHandle)->text_frame.text = (UI_string_type)text;
	memset(((SUBTITLE_HANDLE*)prHandle)->text_frame.font, 0, sizeof(stFontAttribute));
	text_layer_handle = 0;
}




void fe_subtitle_set_property(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam)
{

    gdi_color_format color_fmt;

	int ucs2_len = 0;

	switch (eOP)
	{
		case SUBTITLE_OP_ENCODING:
		{
			//ending UTF8 TO UNICODE
			mmi_chset_enum eMmiEncoding = CHSET_BASE;
            SUBTITLE_ENCODING_T eSubtitleEncoding = *(SUBTITLE_ENCODING_T*)pvParam;
            switch (eSubtitleEncoding)
            {
	            case SUBTITLE_ENCODING_UTF8:
	                eMmiEncoding = MMI_CHSET_UTF8;
	                break;

            default:
                ASSERT(0);
                break;
            }
			((SUBTITLE_HANDLE*)prHandle)->encoding = eMmiEncoding;


		}
            break;
		case SUBTITLE_OP_HORIZONTAL_ALIGNMENT:

		{
				//set SUBTITLE_HORIZONTAL_ALIGNMENT_T
			if(*((SUBTITLE_HORIZONTAL_ALIGNMENT_T*)pvParam) == SUBTITLE_HORIZONTAL_ALIGNMENT_CENTER)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_H_ALIGN_CENTER;


			if(*((SUBTITLE_HORIZONTAL_ALIGNMENT_T*)pvParam) == SUBTITLE_HORIZONTAL_ALIGNMENT_LEFT)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_H_ALIGN_LEFT;

			if(*((SUBTITLE_HORIZONTAL_ALIGNMENT_T*)pvParam) == SUBTITLE_HORIZONTAL_ALIGNMENT_RIGHT)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_H_ALIGN_RIGHT;
		}
			break;
		case SUBTITLE_OP_VERTICAL_ALIGNMENT:
		{
			//set SUBTITLE_VERTICAL_ALIGNMENT_T
			if(*((SUBTITLE_VERTICAL_ALIGNMENT_T*)pvParam) == SUBTITLE_VERTICAL_ALIGNMENT_CENTER)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_V_ALIGN_CENTER;

			if(*((SUBTITLE_VERTICAL_ALIGNMENT_T*)pvParam) == SUBTITLE_VERTICAL_ALIGNMENT_TOP)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_V_ALIGN_TOP;

			if(*((SUBTITLE_VERTICAL_ALIGNMENT_T*)pvParam) == SUBTITLE_VERTICAL_ALIGNMENT_BOTTOM)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_V_ALIGN_BOTTOM;
		}
            break;
		case SUBTITLE_OP_FONT_COLOR:
		{
			memcpy(&(((SUBTITLE_HANDLE*)prHandle)->text_frame.text_color), pvParam,sizeof(color));
		}
            break;
		case SUBTITLE_OP_FONT_SIZE:
		{
			((SUBTITLE_HANDLE*)prHandle)->text_frame.font->size = FONT_PIXEL_SIZE(*(U8*)pvParam);
				
		}
            break;
		case SUBTITLE_OP_FONT_STYLE:
		{
			//font attribute
			if(*((SUBTITLE_STYLE_T*)pvParam) & SUBTITLE_STYLE_BORDER)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.isBorder = KAL_TRUE;

			if(*((SUBTITLE_STYLE_T*)pvParam)& SUBTITLE_STYLE_BOLD)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.font->bold = 1;	/* bold style */

			if(*((SUBTITLE_STYLE_T*)pvParam) & SUBTITLE_STYLE_ITALIC)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.font->italic = 1;	 /* italic style */

			if(*((SUBTITLE_STYLE_T*)pvParam) & SUBTITLE_STYLE_UNDERLINE)
				((SUBTITLE_HANDLE*)prHandle)->text_frame.font->underline = 1;  /* underline style */
		}
			break;
#if defined(__MMI_FONT_EFFECTS__)			
		case SUBTITLE_OP_FONT_EFFECT:
		{
			//font effect
			switch (*((SUBTITLE_FONT_EFFECT_T*)pvParam))
			{

				case SUBTITLE_EFFECT_SHADOW_1:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps = MMI_FE_FONT_EFFECT_E1_1;
				}
				break;
				case SUBTITLE_EFFECT_SHADOW_2:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps = MMI_FE_FONT_EFFECT_E1_2;
				}
				break;
				case SUBTITLE_EFFECT_SHADOW_3:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps = MMI_FE_FONT_EFFECT_E1_3;
				}
				break;
				case SUBTITLE_EFFECT_SHADOW_4:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps = MMI_FE_FONT_EFFECT_E1_4;
				}
				break;
				case SUBTITLE_EFFECT_SHADOW_5:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E1_5;
				}
				break;
 				case SUBTITLE_EFFECT_SHADOW_6:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E1_6;
 				}
				break;

 				case SUBTITLE_EFFECT_SHADOW_7:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E1_7;
 				}
				break;
 				case SUBTITLE_EFFECT_SHADOW_8:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E1_8;
 				}
				break;

 				case SUBTITLE_EFFECT_SHADOW_9:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E1_9;
 				}
				break;
				case SUBTITLE_EFFECT_OUTER_GLOW_1:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E2_1;
				}
				break;
				case SUBTITLE_EFFECT_ENGRAVED_1:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E3_1;
				}
				break;
				case SUBTITLE_EFFECT_GRADIENT_1:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E4_1;
				}
				break;
				case SUBTITLE_EFFECT_BORDERED_1:
				{
					((SUBTITLE_HANDLE*)prHandle)->text_frame.font->smallCaps |= MMI_FE_FONT_EFFECT_E5_1;
				}
				break;
			}

		}
			break;
#endif			
		case SUBTITLE_OP_STRING:
		{
			if(((SUBTITLE_HANDLE*)prHandle)->encoding == MMI_CHSET_UTF8)
			{

				*((kal_uint8*)pvParam + u4SizeOfParam ) = 0x00;

				 ucs2_len = mmi_charset_utf8_to_ucs2_length_in_bytes((kal_uint8*)pvParam) + ENCODING_LENGTH;
				
				 if(ucs2_len > SUBTITLE_MAX_STRING_LENS)
				 	
				     mmi_chset_utf8_to_ucs2_string((U8*) ((SUBTITLE_HANDLE*)prHandle)->text_frame.text, SUBTITLE_MAX_STRING_LENS, (kal_uint8*)pvParam);
				 else
		 		 	 mmi_chset_utf8_to_ucs2_string((U8*) ((SUBTITLE_HANDLE*)prHandle)->text_frame.text, ucs2_len, (kal_uint8*)pvParam);
			}
			else
			{
				mmi_chset_enum encoding_type = MMI_CHSET_UCS2;

					encoding_type = mmi_chset_guess(
						(char*)pvParam,
						u4SizeOfParam,
						CHSET_BASE,
						CHSET_GUESS_ALL);

					 mmi_chset_convert(
						encoding_type,
						MMI_CHSET_UCS2,
						(char*)pvParam,
						(char*)((SUBTITLE_HANDLE*)prHandle)->text_frame.text,
						SUBTITLE_MAX_STRING_LENS);
			}

		}
            break;
		case SUBTITLE_OP_BOUNDARY_RECT:
		{
			((SUBTITLE_HANDLE*)prHandle)->text_frame.x = 0;
			((SUBTITLE_HANDLE*)prHandle)->text_frame.y = 0;
		    color_fmt = GDI_COLOR_FORMAT_32;			

			((SUBTITLE_HANDLE*)prHandle)->text_frame.width = ((SUBTITLE_BOUNDARY_RECT_T *)pvParam)->u4Width;
		    ((SUBTITLE_HANDLE*)prHandle)->text_frame.height = ((SUBTITLE_BOUNDARY_RECT_T *)pvParam)->u4Height;
               
				gdi_layer_create_cf_using_outside_memory(color_fmt, 
	                ((SUBTITLE_HANDLE*)prHandle)->text_frame.x,
	                ((SUBTITLE_HANDLE*)prHandle)->text_frame.y,
	                ((SUBTITLE_HANDLE*)prHandle)->text_frame.width,
	                ((SUBTITLE_HANDLE*)prHandle)->text_frame.height,
	                &text_layer_handle,
                   (U8*) (((SUBTITLE_BOUNDARY_RECT_T *)pvParam)->pu1Buffer),
	                (S32)(((SUBTITLE_BOUNDARY_RECT_T *)pvParam)->u4BufferSize));


		}
			break;

		default:
			break;
	}

}

void fe_subtitle_get_property(void *prHandle,SUBTITLE_OP_T eOP,void *pvParam, kal_uint32 u4SizeOfParam)
{

}

void fe_subtitle_draw(void *prHandle)
{

    ((SUBTITLE_HANDLE*)prHandle)->text_frame.isNeedUpdate = MMI_TRUE;
	//((SUBTITLE_HANDLE*)prHandle)->text_frame.flags |= GUI_TEXT_FRAME_NOT_USE_CACHE;

    gdi_layer_push_and_set_active(text_layer_handle);

	gui_text_frame_show( &(((SUBTITLE_HANDLE*)prHandle)->text_frame));
	
	gdi_layer_pop_and_restore_active();

	gdi_layer_free(text_layer_handle);
	memset(((SUBTITLE_HANDLE*)prHandle)->text_frame.text,0,SUBTITLE_MAX_STRING_LENS);//ctt test

	memset(&text,0,SUBTITLE_MAX_STRING_LENS);


}


void fe_subtitle_deinit(void *prHandle,void *pvParam, kal_uint32 u4SizeOfParam)
{

}
#endif

