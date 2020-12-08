#ifndef _MMA_SMIL_H
#define _MMA_SMIL_H

#include "mma_api.h"
#include "mma_struct.h"


#define SMIL_ELEMENT_AUDIO         0x00
#define SMIL_ELEMENT_BODY          0x01
#define SMIL_ELEMENT_HEAD          0x02
#define SMIL_ELEMENT_IMG           0x03
#define SMIL_ELEMENT_LAYOUT        0x04
#define SMIL_ELEMENT_META          0x05
#define SMIL_ELEMENT_PAR           0x06
#define SMIL_ELEMENT_REF           0x07
#define SMIL_ELEMENT_REGION        0x08
#define SMIL_ELEMENT_ROOT_LAYOUT   0x09
#define SMIL_ELEMENT_SMIL          0x0A
#define SMIL_ELEMENT_TEXT          0x0B
#define SMIL_ELEMENT_VIDEO         0x0C
#define SMIL_ELEMENT_PARAM         0x0D
#define SMIL_ELEMENT_NOT_VALID     0xFF



#define SMIL_ATTRIBUTE_BEGIN        0x00
#define SMIL_ATTRIBUTE_ALT          0x01
#define SMIL_ATTRIBUTE_CONTENT      0x02
#define SMIL_ATTRIBUTE_DUR          0x03
#define SMIL_ATTRIBUTE_END          0x04
#define SMIL_ATTRIBUTE_FIT          0x05
#define SMIL_ATTRIBUTE_HEIGHT       0x06
#define SMIL_ATTRIBUTE_ID           0x07
#define SMIL_ATTRIBUTE_LEFT         0x08
#define SMIL_ATTRIBUTE_NAME         0x09
#define SMIL_ATTRIBUTE_REGION       0x0A
#define SMIL_ATTRIBUTE_SRC          0x0B
#define SMIL_ATTRIBUTE_TOP          0x0C
#define SMIL_ATTRIBUTE_WIDTH        0x0D
#define SMIL_ATTRIBUTE_BG_COLOR		0x0E
#define SMIL_ATTRIBUTE_VALUE		0x0F

typedef enum
{
	SMIL_PARSE_OK,
	SMIL_PARSE_ERROR_TO_MANY_SLIDES,
	SMIL_PARSE_ERROR_UNKNOWN
} MmaSmilParseResult;


#define SLS_HASH_MARK       '#'

typedef struct
{
    const MSF_UINT32 mmsCharset;    
    const MSF_UINT32 msfCharset;   
}SlsCharsetItem;





typedef enum
{
    SLS_OBJECT_TYPE_NONE,       
    SLS_OBJECT_TYPE_TEXT,      
    SLS_OBJECT_TYPE_IMAGE,     
    SLS_OBJECT_TYPE_AUDIO,     
    SLS_OBJECT_TYPE_VIDEO,      
	SLS_OBJECT_TYPE_ATTACMENT,  
	SLS_OBJECT_TYPE_DRM        
    ,SLS_OBJECT_TYPE_REF

}SlsMediaObjectType;




#define SMA_PARSE_BUFFER_INITIAL_SIZE   100

#define MAX_NO_OF_SLIDES 20
#define MAX_ELEM_DEPTH   10

// #define SLS_MAX_ALT_ATTR_LEN 40

// #define SLS_SMIL_ATTR_FIT_MAX_LEN 10

#define SLS_PARAM_MAX_NAME_VALUE_LENGTH	30

#define SLS_MAX_SMIL_BUFFER_SIZE (10 * 1024)

#define SLS_SIZE_NOT_USED    0xFFFF

//used at the time of MMs creation is it to be used
typedef enum 
{
    SLS_TEXT_PLAIN = 0x01,      //*!< Plain text 
    SLS_IMAGE_WBMP,             //*!< Wireless bitmap image  
    SLS_IMAGE_JPG,              //*!< JPG image 
    SLS_IMAGE_GIF,              //*!< GIF image  
    SLS_IMAGE_PNG,              //*!< PNG image  
    SLS_IMAGE_BMP,              //*!< BMP image 
  //  SLS_IMAGE_TIFF,             /*!< TIFF image 
    SLS_DRM_MESSAGE,            //*!< application/vnd.oma.drm.message 
    SLS_DRM_CONTENT,            //*!< application/vnd.oma.drm.content  
    SLS_TEXT_X_VCARD,			//*!< V-Card  
    SLS_TEXT_X_VCAL,			//*!< V-Cal  
    SLS_VIDEO_3GP,              //*!< 3GP video 
    SLS_VIDEO_MP4,              //*!< MPEG4 video 
    SLS_VIDEO_MPEG,             //*!< MPEG/MPEG4 video 
    SLS_VIDEO_AVI,              //*!< AVI video 
    SLS_VIDEO_H263,             //*!< H263 video 
    SLS_AUDIO_MP3,              //*!< MP3 audio  
    SLS_AUDIO_AMR,              //*!< AMR audio  
    SLS_AUDIO_AWB,
    SLS_AUDIO_WMA,
    SLS_AUDIO_AAC,
    SLS_AUDIO_M4A,
    SLS_AUDIO_AIFF,
    SLS_AUDIO_BASIC,

    SLS_AUDIO_WAV,              //*!< WAV audio 
    SLS_AUDIO_VM,
    SLS_AUDIO_MIDI,             //*!< Midi audio 
    SLS_AUDIO_SMAF,
    SLS_AUDIO_IMY,             //*!< iMelody audio 
    SLS_UNKNOWN,                //*!< Unknown media type 
    SLS_NOT_USED                //*!< Media is not used  
} SlsMediaType;




#define SLS_CFG_SUPPORTED_CHARSET {             \
    {MMS_US_ASCII,      MSF_CHARSET_ASCII},     \
    {MMS_UTF8,          MSF_CHARSET_UTF_8},     \
    {MMS_ISO_8859_1,    MSF_CHARSET_ISO_8859_1},\
    {MMS_ISO_8859_1,    MSF_CHARSET_LATIN_1},   \
    {MMS_UCS2,          MSF_CHARSET_UCS_2},     \
    {MMS_UTF16BE,       MSF_CHARSET_UTF_16BE},  \
    {MMS_UTF16LE,       MSF_CHARSET_UTF_16LE},  \
    {MMS_UTF16,         MSF_CHARSET_UTF_16},    \
                                                \
         \
    {MMS_UNKNOWN_CHARSET, MSF_CHARSET_UNKNOWN}}






	#define SLS_COLOR_SET {\
	{"white",		0xFFFFFF},\
	{"silver",		0xC0C0C0},\
	{"gray",		0x808080},\
	{"black",		0x000000},\
	{"yellow",		0xFFFF00},\
	{"fuchsia",		0xFF00FF},\
	{"red",			0xFF0000},\
	{"maroon",		0x800000},\
	{"lime",		0x00FF00},\
	{"olive",		0x808000},\
	{"green",		0x008000},\
	{"purple",		0x800080},\
	{"aqua",		0x00FFFF},\
	{"teal",		0x008080},\
	{"blue",		0x0000FF},\
	{"navy",		0x000080},\
	{NULL,			SLS_COLOR_NOT_USED}}













#define SLS_ABS              0  /*!< Value is absolute */ 
#define SLS_REL              1  /*!< Value is relative */ 

/*! Max length for filename of a media object */
//#define SLS_MAX_MO_FILE_NAME_LEN 16

/*! Used when setting colors for root-layout and text when no color needs to be
    set */
#define SLS_COLOR_NOT_USED      (0xFF000000)



typedef struct
{
    MSF_UINT16 value; /*!< The value */
    MSF_UINT16 type;  /*!< Absolute or relative (%) position*/
} SlsSizeValue;

/*! \struct SlsSize
 *  \brief This type is used for either size or position of windows.
 */
typedef struct
{
    SlsSizeValue  cx;     /*!< Horizontal size or position */
    SlsSizeValue  cy;     /*!< Vertical size or position   */
}SlsSize;

/*! \struct SlsRootLayout
 *  \brief This type is used to present the root layout data.
 */
typedef struct
{
    MSF_UINT32    bgColor;  /*!< The background color for the display */
    SlsSizeValue  cx;       /*!< Horizontal size or position */
    SlsSizeValue  cy;       /*!< Vertical size or position   */
}SlsRootLayout;


typedef struct
{
    SlsSize    position;   /*!< Position from top/left		   */
    SlsSize    size;       /*!< Size of region				   */
	MSF_UINT16 is_valid;
	mma_region_fit_enum    fit;		/*!< fit attribute, used for image */
}SlsRegion;

/*! \enum SlsTextSize
 *  \brief Defines the different font sizes
 */
typedef enum
{
    SLS_TEXT_SIZE_DEFAULT,
    SLS_TEXT_SIZE_NORMAL,
    SLS_TEXT_SIZE_SMALL,
    SLS_TEXT_SIZE_VERY_SMALL
}SlsTextSize;



typedef struct
{
	char	*name;
	char	*value;
}SlsParameter;
typedef struct SlsParamList
{
    SlsParameter            param;
    struct SlsParamList   *next;
}SlsParameterList;





typedef struct SlsMediaObject_t
{
    SlsMediaType    type;    /*!< Type of MO */
    char            *region; /*!< Name of the region to use for this MO  */
    char            *src;    /*!< Reference to the MO */
    MSF_UINT32      beginT;  /*!< The start-time, 0 if not used */
    MSF_UINT32      endT;    /*!< The stop-time, 0 if not used */
    MSF_UINT32      color;   /*!< Color - only used for text color at the time */
	SlsParameterList    *slsparamList;
	MSF_UINT32      duration;
#ifdef MTK_TMP_PATCH
	struct SlsMediaObject_t	*next;
#endif
} SlsMediaObject;



typedef struct SlsSlideListSt
{
    int                            duration;
    SlsMediaObject      text;    
    SlsMediaObject      image;   
	SlsMediaObject      video;   
    SlsMediaObject      audio;
	SlsMediaObject		*refList;		
    struct SlsSlideListSt *next;
} SlsSlideList;


typedef struct SlsRegionListNode
{
    SlsRegion           data;
    char               *name;
    struct SlsRegionListNode  *next;
}SlsRegionListNode;

typedef struct SlsCreateSmilData
{
    SlsRootLayout       *rootLayout;
    SlsRegionListNode   *regionList;
    SlsSlideList        *slideList;
}SlsCreateSmilData;




typedef struct Regions
{
    char    *id;         
    SlsSize  position;   
    SlsSize  size;       
	mma_region_fit_enum	 fit;		 
    struct Regions *next; 
} Regions;

typedef struct   
{
    const SlsMediaType       mediaType;         
    const char               *mimeType;         
    const MmsKnownMediaType  mmsMediaType;      
    const SlsMediaObjectType objectType;        
}SlsMediaTypeItem;


typedef enum 
{
    
    SMIL_MEDIA_OBJECT_AUDIO = 0,
    SMIL_MEDIA_OBJECT_IMG,
    SMIL_MEDIA_OBJECT_REF,
    SMIL_MEDIA_OBJECT_TEXT,
    SMIL_MEDIA_OBJECT_VIDEO
} SmilMediaObjectElement;


typedef struct SmilMediaObjectSt
{
    
    SmilMediaObjectElement mediaObjectElement;
	char				*src;
	char				*alt;
	char				*region;
	MSF_UINT32			color;
	MSF_UINT32			begin; 
	MSF_UINT32			end; 
	MSF_UINT32			dur;
	SlsParameterList	*tmpParamList;
	struct SmilMediaObjectSt *next;
}SmilMediaObject;

typedef struct
{
    SmilMediaObject *mobj;
    MSF_UINT32 dur;
    MSF_UINT8  used;
} SmilPar;


typedef struct
{
	
  //  MSF_UINT8               client;
	MSF_UINT32				noUnrefItems;
    SmilPar*                 parList;
    Regions					*regions;		
    int                     slidePointer;	/*parsing purpose*/
    int*                     elementStack;	/*parsing purpose*/
    int						*stackP;		
    int						smilBodyPartNumber;	/*position at which smil lies in the mms PDU*/
    MSF_UINT32              smilSize;
    unsigned char			*smilData;/*buffer to read smil*/
	 MSF_UINT8               memId;  /* MOD_ID from where memory need to be allocated  */
	 int					refMediaCount;
} InstanceData;



typedef void* SlsCreateSmilHandle;


mma_result_enum mma_smil_createSmil(MSF_UINT8 modId, SlsCreateSmilHandle *handle,
    const SlsRootLayout *rootlayout);

mma_result_enum mma_smil_createRegion(MSF_UINT8 modId, 
    const SlsCreateSmilHandle *handle, const SlsRegion *region,
    const char *name);


mma_result_enum mma_smil_cancelCreateSmil(MSF_UINT8 modId,
    const SlsCreateSmilHandle *handle);


mma_result_enum mma_smil_createSlide(MSF_UINT8  modId,
    const SlsCreateSmilHandle *handle, MSF_INT32 duration,
    const SlsMediaObject *text, const SlsMediaObject *image,
    const SlsMediaObject *video, const SlsMediaObject *audio,
	const SlsMediaObject *refList);  

int mma_generate_region_from_SMILctx(char *regionId, mma_mms_object_area_struct *objectRegion, InstanceData *ctx);
 
mma_result_enum mma_smil_generateSmil(MSF_UINT8 modId,
    const SlsCreateSmilHandle *handle, char **buffer);

 
extern mma_result_enum mma_parse_sml(InstanceData *instData);
extern int mma_get_no_of_slides(InstanceData ctx);
extern void mma_parse_free_smil_ctx(InstanceData *ctx);

#endif /* _MMA_SMIL_H */ 






