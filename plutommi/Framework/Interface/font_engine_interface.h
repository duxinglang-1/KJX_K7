
#ifndef __FONT_ENGINE_INTER_FACE_H__
#define __FONT_ENGINE_INTER_FACE_H__




typedef enum
{
    MMI_FE_FONT_OPEN_FILE_IVALID,
    MMI_FE_FONT_OPEN_MEMORY,
    MMI_FE_FONT_OPEN_FILE_STREAM,
    MMI_FE_FONT_OPEN_ENFB_RESOURCE,
} mmi_fe_font_resource_type_enum;

typedef enum
{
    MMI_FE_FONT_ERR_NONE,
    MMI_FE_FONT_ERR_INVALID_FONT, /* vector font engine use to inform mmi the installed font is a invalid font */
    MMI_FE_FONT_ERR_OUT_OF_MEMORY,  /* vector font engine use to inform mmi the installed font would cause system out of memory */
    MMI_FE_FONT_ERR_OUT_OF_CACHE,  /* vector font engine use to inform mmi the installed font would cause system out of cache */
    MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY, /* vector font engine use to inform mmi the system meory is insufficient */
    MMI_FE_FONT_ERR_INVALID_FONT_PATH,
    MMI_FE_FONT_ERR_INVALID_FILE_ACCESS,
    MMI_FE_FONT_ERR_INIT_TIME_OUT,
    MMI_FE_FONT_ERR_END_OF_ENUM
} mmi_fe_error_code;


/* 
    In cache, we use 8 bit to present the attribute.
    If the attribute is expanded, cache key structure should be changed too.
*/
#define FE_FONT_ATTR_BOLD               (1<<0)
#define FE_FONT_ATTR_ITALIC             (1<<1)
#define FE_FONT_ATTR_OBLIQUE            (1<<2)
#define FE_FONT_ATTR_UNDERLINE          (1<<3)
#define FE_FONT_ATTR_ENGRAVE         (1<<4)
#define FE_FONT_ATTR_BORDER             (1<<5)
#define FE_FONT_ATTR_ANTIALIAS          (1<<6)
/* to indicate the font data belong to proprietary range */
#define FE_FONT_ATTR_PRIVATE (1<<7)

#define FE_GLYPH_ATTR_USING_FONT_ENGINE (1<<0) // we use this flag to identify show glyph should call font engine or not.

#define FE_MAX_FONT_FILE_NUMBER      15
#define FE_MAX_FONT_FAMILY_NUMBER  3

#define FE_TAG_MAKER(a,b,c,d) (U32)((a << 24) | (b << 16) | (c << 8) | d)

/* 
 * because of caceh, the length should be less then 32 (<32).
 * IN IRE, the max cluster len is 10 but we might add ZWJ and ZWNJ in the buffer.
 * in the worst case, the buffer would fill with indic character + (ZWJ | ZWNJ).
 * the cluster length should be double then IRE cluster length.
*/
#define FE_MAX_CLUSTER_LEN 20

typedef U32 FE_OT_FLAG;

/* script tag. the total number of script should be less then 32 (<32) because of the cache */
#define MMI_FE_OT_SCRIPT_BENGALI FE_TAG_MAKER('b','e','n','g') /* for bengali & assamese lang */
#define MMI_FE_OT_SCRIPT_DEVANAGARI FE_TAG_MAKER('d','e','v','a') /* for Hindi and Marathi language */
#define MMI_FE_OT_SCRIPT_GUJARATI FE_TAG_MAKER('g','u','j','r')
#define MMI_FE_OT_SCRIPT_GURMUKHI FE_TAG_MAKER('g','u','r','u') /* for punjabi lang */
#define MMI_FE_OT_SCRIPT_KANNADA FE_TAG_MAKER('k','n','d','a')
#define MMI_FE_OT_SCRIPT_MALAYALAM FE_TAG_MAKER('m','l','y','m')
#define MMI_FE_OT_SCRIPT_ORIYA FE_TAG_MAKER('o','r','y','a')
#define MMI_FE_OT_SCRIPT_SINHALA FE_TAG_MAKER('s','i','n','h')
#define MMI_FE_OT_SCRIPT_TAMIL FE_TAG_MAKER('t','a','m','l')
#define MMI_FE_OT_SCRIPT_TELUEU FE_TAG_MAKER('t','e','l','u')
#define MMI_FE_OT_SCRIPT_THAI FE_TAG_MAKER('t','h','a','i')
#define MMI_FE_OT_SCRIPT_MYANMAR FE_TAG_MAKER('m','y','a','n')
#define MMI_FE_OT_SCRIPT_LAO FE_TAG_MAKER('l','a','o','s')

/* lang tag. the total number of lang should be less then 32 (<32) because of the cache */
#define MMI_FE_OT_LANG_ASSAMESE FE_TAG_MAKER('A','S','M',' ')
#define MMI_FE_OT_LANG_BENGALI FE_TAG_MAKER('B','E','N',' ')
#define MMI_FE_OT_LANG_GUJARATI FE_TAG_MAKER('G','U','J',' ')
#define MMI_FE_OT_LANG_HINDI FE_TAG_MAKER('H','I','N',' ')
#define MMI_FE_OT_LANG_KANNADA FE_TAG_MAKER('K','A','N',' ')
#define MMI_FE_OT_LANG_MALAYALAM FE_TAG_MAKER('M','A','L',' ')
#define MMI_FE_OT_LANG_MARATHI FE_TAG_MAKER('M','A','R',' ')
#define MMI_FE_OT_LANG_ORIYA FE_TAG_MAKER('O','R','I',' ')
#define MMI_FE_OT_LANG_PUNJABI FE_TAG_MAKER('P','A','N',' ')
#define MMI_FE_OT_LANG_TAMIL FE_TAG_MAKER('P','A','N',' ')
#define MMI_FE_OT_LANG_TELUGU FE_TAG_MAKER('T','A','M',' ')
#define MMI_FE_OT_LANG_THAI FE_TAG_MAKER('T','H','A',' ')
#define MMI_FE_OT_LANG_MYANMAR FE_TAG_MAKER('M','Y','A',' ')
#define MMI_FE_OT_LANG_LAO FE_TAG_MAKER('L','A','O',' ')

#define MMI_FE_OT_DEFAULT FE_TAG_MAKER('D','F','L','T')

#define MMI_FE_ENGINE_VERSION_08B_FEATURE_SET 1
#define MMI_FE_ENGINE_VERSION_09A_FEATURE_SET 2
#define MMI_FE_ENGINE_VERSION_09B_FEATURE_SET 3


/*
Horizontal: (advance_y is not used )
       
          --> bearingX
BearingY ^    OO
         |    OO
         |    OO
         |    OO
---------*----OO----*-------------
   Origin|    OO      next Origin
         | OO OO
         |  OOO
         |---------> advance_x


Vertical: (advance_x is not used )

          --> bearingX
BearingY ^    OO
         |    OO
         |    OO
         |    OO
---------*----OO-----------------
   Origin|    OO      |
         | OO OO      |
         |  OOO       |
next     |            |
Origin   *            v  advance_y
         |

*/

typedef struct
{
    U16 glyph_index;
    kal_int8 offset;
    /* 
     *  When the attribute is set, use the delta_x instead of the original advance.
     *  If it is not set, the delta_x should add with the original advance.
    */
    kal_int8 new_advance;
    kal_int8 pos_x; /* adjust for pos_x */
    kal_int8 pos_y; /* adjust for pos_y */
    kal_int8 delta_x; /* adjust for advance_x */
    kal_int8 delta_y; /* adjust for advance_y */
#if defined(__MMI_VECTOR_FONT_KERNING__)
    kal_int32 lsb_delta; /* lsb_delta */
    kal_int32 rsb_delta; /* rsb_delta */
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
} mmi_fe_glyph_ot_info, *mmi_fe_glyph_ot_info_p;

typedef struct
{
    mmi_fe_glyph_ot_info glyph_buf[FE_MAX_CLUSTER_LEN]; /* the glyph index for the cluster */
    U16 glyph_len; /* length of the glyph buffer */
} mmi_fe_cluster_info, *mmi_fe_cluster_info_p;

#define mmi_fe_cluster_info_init(a) memset(a, 0, sizeof(mmi_fe_cluster_info))

typedef struct 
{
    S32 version_number;
    MMI_BOOL (*init)(U16* font_list, U8 font_number);
    void (*set_font_attr)   (U32 attr);
    void (*set_font_size)   (U32 size, U32 attr); /* pixels */
    void (*set_font_color)  (gdi_color text_color,gdi_color border_color);
#if defined(__MMI_VECTOR_FONT_KERNING__)
    MMI_BOOL (*get_font_data)   (U8 is_need_glyph_data, /* 0: font data is not necessary. 1: get font data. 2: font check. 3: the ucs2 code is glyph index */
                             U16 ucs2,
                             U8** glyph_data,
                             U32 *glyph_size, /* bytes number of glyph_data */
                             U32 *glyph_attr, /* glyph attribute , used for font engine itself */
                             U16 *glyph_width,U16 *glyph_height,
                             S32 *bearing_x,S32 *bearing_y,  /* the offset from origin for glyph */
                             S32 *advance_x,S32 *advance_y,   /* the offset for next character origin */
                            S32 *lsb_delta,
                            S32 *rsb_delta,
                             MMI_BOOL* valid /*  */
                             );
#else
    MMI_BOOL (*get_font_data)   (U8 is_need_glyph_data, /* 0: font data is not necessary. 1: get font data. 2: font check. 3: the ucs2 code is glyph index */
                             U16 ucs2,
                             U8** glyph_data,
                             U32 *glyph_size, /* bytes number of glyph_data */
                             U32 *glyph_attr, /* glyph attribute , used for font engine itself */
                             U16 *glyph_width,U16 *glyph_height,
                             S32 *bearing_x,S32 *bearing_y,  /* the offset from origin for glyph */
                             S32 *advance_x,S32 *advance_y,   /* the offset for next character origin */
                             MMI_BOOL* valid /*  */
                             );
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    
    void (*show_font_data)  (U16 ucs2, 
                             S32 x,S32 y,
                             U8* glyph_ptr,
                             U32 glyph_size,
                             U32 glyph_attr,
                             U16 glyph_width,
                             U16 glyph_height,
                             U32 bordered_attr);
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
    MMI_BOOL (*get_font_info)(U16 resid, U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr);
#else
    MMI_BOOL (*get_font_info)(U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr);
#endif
    void (*set_antialias)(MMI_BOOL value);
    MMI_BOOL (*set_font)(U16 resid);  /* change active font to sepcific font resource */
    /* to do shapping */
    void (*shaper)(U32 lang, U32 script, UI_string_type text, S32 text_len, S32 start_index, S32 run_len, mmi_fe_cluster_info_p cluster);
    mmi_fe_error_code (*check_font)(U16 resid);
    mmi_fe_error_code (*get_font_name)(U16 resid, U8* buffer, S32 buf_size);
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
    MMI_BOOL (*get_font_res_id)(U16 ucs2, U16* res_id, U8* num);
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
    MMI_BOOL (*get_font_kerning) (U16 left_ucs2, U16 right_ucs2, signed long *x, signed long *y);
    U16 (*get_glyph_index)(U16 ucs2);
    MMI_BOOL (*is_kerning) (void);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
} fe_table_struct;

extern const fe_table_struct font_engine_table;

#endif


