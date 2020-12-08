
/* Utility functions for smil parsing and mms slide related work */



#ifndef _MMA_SMIL_C
#define _MMA_SMIL_C
#if defined(MMS_SUPPORT)
#include <stdio.h>

#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "wap_ps_struct.h"
#include "mmsadp.h"
#include "custom_wap_config.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
#include "app_datetime.h"

/* PLUTOMMI */
#include "MMI_features.h"
#include "WguiCategoryGprot.h"

/* MSF */
#include "msf_def.h"
#include "msf_core.h"   /* MSF: System core call */
#include "msf_mem.h"
#include "msf_cfg.h"
#include "msf_prsr.h"
#include "msf_chrt.h"
#include "msf_lib.h"
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_chrs.h"   /* MSF: character API */
#include "msm.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"
#include "mms_if.h"
#include "mmsl_if.h"
#include "mltypes.h"
#include "mutils.h"

/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"

//#include "sls_def.h"
//#include "sls_if.h"
//#include "sls_prse.h"

/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_main.h"
#include "mma_mime.h"
#include "mma_msg_struct.h"
#include "mma_parse.h"
#include "mma_create.h"
#include "mma_utilities.h"
#include "mma_interface.h"
#include "mma_xml.h"
#include "mma_msgmgr.h"








#define SLS_SMIL_START      "<smil>\n"
#define SLS_SMIL_END        "</smil>\n"
#define SLS_HEAD_START      "<head>\n"
#define SLS_HEAD_END        "</head>\n"
#define SLS_BODY_START      "<body>\n"
#define SLS_BODY_END        "</body>\n"
#define SLS_PAR_START       "<par dur=\"%dms\">\n"
#define SLS_PAR_END         "</par>\n"
#define SLS_TEXT_T1         "<text src=\"%s\" region=\"%s\" "
#define SLS_TEXT_T2         "begin=\"%lums\" "
#define SLS_TEXT_T3         "end=\"%lums\" "

#define SLS_TEXT_T4         "<param name=\"foregroundcolor\" value=\"%s\" /></text>\n"
#define SLS_TEXT_T5         "/>\n"
#define SLS_TEXT_T6         ">\n"
#define SLS_IMAGE_T1        "<img src=\"%s\" region=\"%s\" "
#define SLS_IMAGE_T2         "begin=\"%lums\" "
#define SLS_IMAGE_T3         "end=\"%lums\" "

#define SLS_IMAGE_T4        "/>\n"
#define SLS_VIDEO_T1        "<video src=\"%s\" region=\"%s\" "
#define SLS_VIDEO_T2        "begin=\"%lums\" "
#define SLS_VIDEO_T3        "end=\"%lums\" "

#define SLS_VIDEO_T4        "/>\n"
#define SLS_AUDIO_T1         "<audio src=\"%s\" "
#define SLS_AUDIO_T2         "begin=\"%lums\" "
#define SLS_AUDIO_T3         "end=\"%lums\" "

#define SLS_AUDIO_T4        "/>\n"

#define SLS_REF_T1         "<ref src=\"%s\" "
#define SLS_REF_T2         "begin=\"%lums\" "
#define SLS_REF_T3         "end=\"%lums\" "
#define SLS_REF_T4        "/>\n"



#define SLS_LAYOUT_START    "<layout>\n"
#define SLS_LAYOUT_END      "</layout>\n"








#ifndef __OP11_MMS_HIDE_ROOTLAYOUT_WIDTH_HEIGHT__
#define SLS_ROOT_LAYOUT_T1  "<root-layout width=\""
#define SLS_ROOT_LAYOUT_T2  "\" height=\""
#define SLS_ROOT_LAYOUT_T3  "\" background-color=\""
#else
#define SLS_ROOT_LAYOUT_T3  "<root-layout background-color=\""
#endif
#define SLS_ROOT_LAYOUT_T4  "\"/>\n"
#define SLS_REGION_T1       "<region id=\""
#define SLS_REGION_T2       "\" width=\""
#define SLS_REGION_T3       "\" height=\""
#define SLS_REGION_T4       "\" left=\""
#define SLS_REGION_T5       "\" top=\""
#define SLS_REGION_T6       "\" "
#define SLS_REGION_T7       "/>\n"

#define SLS_FIT_FILL   "fit=\"fill\""
#define SLS_FIT_HIDDEN "fit=\"hidden\""
#define SLS_FIT_MEET   "fit=\"meet\""
#define SLS_FIT_SCROLL "fit=\"scroll\""
#define SLS_FIT_SLICE  "fit=\"slice\""

#define SLS_PARAM	"<param"
#define SLS_PARAM_NAME	"name=\""
#define SLS_PARAM_VALUE	"value=\""
#define SLS_END_QUOTE	"\""
#define SLS_PARAM_SPACE	" "
#define SLS_PARAM_TEXT_FONT_WEIGHT					"fontWeight"
#define SLS_PARAM_TEXT_FONT_STYLE					"fontStyle"
#define SLS_PARAM_TEXT_FONT_COLOR					"fontColor"
#define SLS_PARAM_TEXT_FONT_SIZE					"fontSize"
#define SLS_PARAM_TEXT_END_QUOTE					"</text>"
#define SLS_PARAM_IMAGE_END_QUOTE					"</img>"
#define SLS_PARAM_AUDIO_END_QUOTE					"</audio>"
#define SLS_PARAM_VIDEO_END_QUOTE					"</video>"
#define SLS_PARAM_REF_END_QUOTE						"</ref>"
#define SLS_PARAM_CLOSE								">\n"



#define SLS_FITSZ sizeof(SLS_FIT_HIDDEN)
#define SLS_INTSZ           (MSF_INT32)8

typedef struct 
{
	const char *colorName;
	const MSF_UINT32 colorValue;
}MmaSmilColor;

const MmaSmilColor MSColorSet[] = SLS_COLOR_SET;
//static const SlsMediaTypeItem slsSupportedMediaTypes[] = SLS_CFG_SUPPORTED_MEDIA_TYPES;




#define SMIL_ATTRVAL_FILL       0x0A00
#define SMIL_ATTRVAL_HIDDEN     0x0A01
#define SMIL_ATTRVAL_MEET       0x0A02
#define SMIL_ATTRVAL_SCROLL     0x0A03
#define SMIL_ATTRVAL_SLICE      0x0A04

#define SMIL_ATTR_PARAM_COLOR	"foregroundcolor"
#define SMIL_ATTR_PARAM_COLOR_  "foreground-color"
#define SLS_MAX_REF_ELEMENTS 6

/* duplicated perhaps for some time */

#define MMA_CHARSET_CHECK_BOM_SIZE 100
#define MMA_TEXT_SIZE_NAME_STR      "fontsize"
#define MMA_TEXT_COLOR_NAME_STR     "foregroundcolor"
#define MMA_TEXT_COLOR__NAME_STR    "foreground-color"
#define MMA_TEXT_STYLE_NAME_STR     "fontstyle"

static const msf_strtable_entry_t smil_Elements_stringTable1[] = {
  {"smil",            SMIL_ELEMENT_SMIL},
  {"head",            SMIL_ELEMENT_HEAD},
  {"meta",            SMIL_ELEMENT_META},
  {"layout",          SMIL_ELEMENT_LAYOUT},
  {"root-layout",     SMIL_ELEMENT_ROOT_LAYOUT},
  {"region",          SMIL_ELEMENT_REGION},
  {"body",            SMIL_ELEMENT_BODY},
  {"par",             SMIL_ELEMENT_PAR},
  {"text",            SMIL_ELEMENT_TEXT},
  {"img",             SMIL_ELEMENT_IMG},
  {"audio",           SMIL_ELEMENT_AUDIO},  
  {"ref",             SMIL_ELEMENT_REF},
  {"video",           SMIL_ELEMENT_VIDEO},
  {"param",           SMIL_ELEMENT_PARAM}
 };






static const unsigned char smil_Elements_hashTable1[] = 
{
  4, 0, 13, 255, 3, 255, 255, 7, 5, 8,
  11, 10, 255, 255, 1, 9, 255, 255, 6, 2,
  12, 255, 255
};

#define SMIL_ELEMENTS_HASH_TABLE_SIZE                 23
#define SMIL_ELEMENTS_STRING_TABLE_SIZE               14
#define SMIL_MAX_ALT_STR_LEN						  20



const msf_strtable_info_t smil_Elements1 = 
{
  smil_Elements_hashTable1,
  SMIL_ELEMENTS_HASH_TABLE_SIZE,
  MSF_TABLE_SEARCH_LINEAR,
  smil_Elements_stringTable1,
  SMIL_ELEMENTS_STRING_TABLE_SIZE
};





static const msf_strtable_entry_t smil_Attributes_stringTable1[] = {
  {"content",			SMIL_ATTRIBUTE_CONTENT},
  {"name",				SMIL_ATTRIBUTE_NAME},
  {"width",				SMIL_ATTRIBUTE_WIDTH},
  {"height",			SMIL_ATTRIBUTE_HEIGHT},
  {"fit",				SMIL_ATTRIBUTE_FIT},
  {"id",				SMIL_ATTRIBUTE_ID},
  {"left",				SMIL_ATTRIBUTE_LEFT},
  {"top",				SMIL_ATTRIBUTE_TOP},
  {"dur",				SMIL_ATTRIBUTE_DUR},
  {"src",				SMIL_ATTRIBUTE_SRC},
  {"region",			SMIL_ATTRIBUTE_REGION},
  {"alt",				SMIL_ATTRIBUTE_ALT},
  {"begin",				SMIL_ATTRIBUTE_BEGIN},
  {"end",				SMIL_ATTRIBUTE_END},
  {"background-color",	SMIL_ATTRIBUTE_BG_COLOR},
  {"value",				SMIL_ATTRIBUTE_VALUE}
};




static const unsigned char smil_Attributes_hashTable1[] = 
{
  11, 255, 255, 3, 15, 1, 12, 13, 255, 9,
  10, 7, 255, 8, 255, 0, 255, 255, 5, 2,
  14, 255, 255, 255, 255, 4, 255, 255, 6
};

#define SMIL_ATTR_HASH_TABLE_SIZE                 29
#define SMIL_ATTR_STRING_TABLE_SIZE               16



const msf_strtable_info_t smil_Attributes1 = {
  smil_Attributes_hashTable1,
  SMIL_ATTR_HASH_TABLE_SIZE,
  MSF_TABLE_SEARCH_LINEAR,
  smil_Attributes_stringTable1,
  SMIL_ATTR_STRING_TABLE_SIZE
};




static const msf_strtable_entry_t smil_Attrvals_stringTable1[] = {
  {"fill",            SMIL_ATTRVAL_FILL},
  {"hidden",          SMIL_ATTRVAL_HIDDEN},
  {"meet",            SMIL_ATTRVAL_MEET},
  {"scroll",          SMIL_ATTRVAL_SCROLL},
  {"slice",           SMIL_ATTRVAL_SLICE}
};




static const unsigned char smil_Attrvals_hashTable1[] = {
  3, 2, 1, 255, 255, 0, 4
};

#define SMIL_ATTR_VAL_HASH_TABLE_SIZE                 7
#define SMIL_ATTR_VAL_STRING_TABLE_SIZE               5



const msf_strtable_info_t smil_Attrvals1 = {
  smil_Attrvals_hashTable1,
  SMIL_ATTR_VAL_HASH_TABLE_SIZE,
  MSF_TABLE_SEARCH_LINEAR,
  smil_Attrvals_stringTable1,
  SMIL_ATTR_VAL_STRING_TABLE_SIZE
};



const unsigned char smil_Element_table1[] = {
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT, 
  MSF_PRSR_CANCELSPACE | MSF_PRSR_TEXT  
};


const MSF_UINT16 smil_AttributeTypes1[] = {
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_ENUM_A, 
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_ID,     
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_IDREF,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
  MSF_PRSR_TYPE_CDATA,  
};





#define DEFAULT_DURATION 3
#define STR_SIZE 32

/* The structures are declared for the Mms/Smil creation */














static int initCallback (msf_prsr_parserData_t*  p, msf_prsr_decoderData_t* d,
	const char* doctype_str, int len, int  wbxml_code, int charset);
static int piCallback(void* userData, msf_prsr_parser_t* parser, 
	const char* target,  const char* data, 
	 const char* end);
static void storeSlideElementInfo(SmilMediaObject *medObj, int type, 
    const msf_prsr_attribute_t* attrs, int numAttrs);
static SmilMediaObject* allocMediaObj(InstanceData *ctx);
static char *getStrAttr(const msf_prsr_attribute_t *attr, int numAttrs, int type, InstanceData *ctx);
static int startElementCallback(void* userData, int type, 
	msf_prsr_attribute_t* attrs, int numAttrs);

static int endElementCallback(void* userData);
static int charDataCallback(void* userData, const char* s, int len, int mode);
static void elementStackInit(InstanceData *ctx);

static void getRegions(const msf_prsr_attribute_t* attrs, int numAttrs, InstanceData *ctx);
int mma_generate_region_from_SMILctx(char *regionId, mma_mms_object_area_struct *objectRegion, InstanceData *ctx);
void MmaFreeParamList(MSF_UINT8 modId, SlsParameterList **slideParamList);
mma_result_enum addSlsParamListElement1(SlsParameterList **paramlisthead, char *name, char *value, InstanceData *ctx);
static void copySlsRegion(const SlsRegion *source, SlsRegion *dest);
static void copySlsRootLayout(const SlsRootLayout *source, SlsRootLayout *dest);
static void sls_itoacol(MSF_UINT32 color, char *s);
static MSF_BOOL copySlsMediaObj(MSF_UINT8 modId, const SlsMediaObject *source, 
	SlsMediaObject *dest);
static MSF_BOOL copyRefMediaObj(MSF_UINT8 modId, const SlsMediaObject *refList, 
	SlsMediaObject **refItemList);
mma_result_enum slscpyParamListInfo(MSF_UINT8 modId,SlsParameterList *rootParamList,SlsParameterList **slideparamList,MSF_UINT32 *count);

void smilgetParamAttributelength(SlsParameterList  *list, MSF_UINT32 *size);
mma_region_fit_enum getFitAtr(MSF_UINT32 val);
static void sls_itoa(SlsSizeValue val, char *s);
static void sls_reverse(char *s);
static MSF_UINT32 getSec(MSF_UINT32 value, const char *e);
static MSF_UINT32 colorSTOI(const char *colorStrVal);
void smilAddRefItemList(SlsMediaObject  *list,char **Buff);
void slsgetParamAttributelength(SlsParameterList  *list, MSF_UINT32 *size);




mma_result_enum mma_parse_sml(InstanceData *instData)
{


    msf_prsr_parser_t  *parser;   
    int                 result;
    int                 handle = 0;
    int                 handleType;
    void               *userData;
	mma_result_enum		ret;

    
InstanceData *ctx = instData;

	
    parser = msf_prsr_create (ctx->memId,
	    NULL,
        initCallback,
        piCallback,
        MSF_PRSR_BUFFER,
        (char*)ctx->smilData,
        (int)strlen((const char*)ctx->smilData) + 1,
        handle,
        SMA_PARSE_BUFFER_INITIAL_SIZE, 
        MSF_CHARSET_UTF_8,
        MSF_CHARSET_ASCII,
        TRUE);

	
	ctx->smilData = NULL;
    
    
    elementStackInit(ctx);
    
	
    do
    {
        result = msf_prsr_parse(parser);
    }
    while (MSF_PRSR_STATUS_MORE_TO_DO == result);
    
	
    
    
    elementStackInit(ctx);
	
    (void)msf_prsr_delete(parser, &handle, &handleType, &userData);
     
	if (result == MSF_PRSR_STATUS_PARSING_COMPLETED)
	{
		
		ret = MMA_RESULT_OK;
	}
	else if (result == MSF_PRSR_ERROR_APPLICATION)
	{
		
		ret = MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;
	} 
	else
	{
		
		ret = MMA_RESULT_FAIL_PARSE;
	}
		
	return ret;

}




static void pushElement(InstanceData *ctx, int type)
{
    if ((ctx->stackP + 1) == (ctx->elementStack + MAX_ELEM_DEPTH))
    {
        
    }
    else if (SMIL_ELEMENT_NOT_VALID == *ctx->stackP)
    {
        *ctx->stackP = type;
    }
    else
    {
        *++ctx->stackP = type;
    }
} 






static int popElement(InstanceData *ctx)
{
    if (ctx->stackP == ctx->elementStack)
    {
        int i = *ctx->stackP;
        *ctx->stackP = SMIL_ELEMENT_NOT_VALID;
        return i;
    }
    else
    {
        return *ctx->stackP--;
    }
} 






static void elementStackInit(InstanceData *ctx)
{
    ctx->stackP = ctx->elementStack;
    *ctx->stackP = SMIL_ELEMENT_NOT_VALID;
} 



static int initCallback (msf_prsr_parserData_t*  p, msf_prsr_decoderData_t* d,
	const char* doctype_str, int len, int  wbxml_code, int charset)
{
    p->startHandler     = startElementCallback;
    p->endHandler       = endElementCallback;
    p->charHandler      = charDataCallback;
    p->attributes       = &smil_Attributes1;
    p->attributeType    = smil_AttributeTypes1;
    p->elements         = &smil_Elements1;
    p->elementTable     = smil_Element_table1;
    p->attrvals         = &smil_Attrvals1;

    (void)d;
    (void)doctype_str;
    (void)wbxml_code;
    (void)charset;
    (void)len;
    return MSF_PRSR_APPLICATION_OK;
} 





static int piCallback(void* userData, msf_prsr_parser_t* parser, 
	const char* target,  const char* data, 
	 const char* end)
{
    (void)userData;
    (void)parser;
    (void)target;
    (void)data;
    (void)end;
    return MSF_PRSR_APPLICATION_OK;
} 




static int getIntAttr(const msf_prsr_attribute_t *attr, int numAttrs, int type,
	MSF_UINT16 *sResult, MSF_UINT32  *lResult, char **extra)
{
    char value[STR_SIZE];
    int i;
    
    while (numAttrs--)
    {
        if (attr->type == type)
        {
            if (MSF_PRSR_ATTRVAL_STR == attr->flag)
            {
                if (attr->u.s)
                {
                    for (i = 0; i < STR_SIZE && 
                        attr->u.s[i] && ct_isdigit(attr->u.s[i]); i++)
                    {
                        value[i] = attr->u.s[i];
                    }
                    if (i == STR_SIZE)
                    {
                        value[STR_SIZE - 1] = 0;
                    }
                    else
                    {
                        value[i] = 0;
                    }
                    if (sResult)
                    {
                    *sResult = (MSF_UINT16)atoi(value);
                    }
					if (lResult)
					{
						*lResult = (MSF_UINT32)atol(value);
					}
                    if (attr->u.s[i])
                    {
                        *extra = attr->u.s + i;
                    }
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
			if (MSF_PRSR_ATTRVAL_INT == attr->flag)
            {
				if (attr->u.i)
                {
					*lResult = (MSF_UINT32)attr->u.i;
					if (NULL != sResult)
					{
						sResult = 0;
					}
					return 1;
				}
			}
        }
        attr++;
    }
    return 0;
} 



static MSF_BOOL isDupMediaObj(SmilMediaObject *obj, InstanceData *ctx)
{
    SmilMediaObject    *medObj = ctx->parList[ctx->slidePointer].mobj;
    if (obj == NULL)
    {
        return FALSE;
    }
    while (medObj)
    {
        if (medObj != obj && medObj->mediaObjectElement == obj->mediaObjectElement)
        {
            if ((obj->src && medObj->src && strcmp(obj->src, medObj->src) == 0) && 
                ((obj->region && medObj->region && strcmp(obj->region, medObj->region) == 0) || 
                 (obj->region == NULL && medObj->region == NULL)) &&
                (obj->begin == medObj->begin) && (obj->end == medObj->end) && (obj->dur == medObj->dur))
            {
                return TRUE;
            }
        }
        medObj = medObj->next;
    }
    return FALSE;
}



static int startElementCallback(void* userData, int type, 
	msf_prsr_attribute_t* attrs, int numAttrs)
{
    static SmilMediaObject    *medObj;
    char *e = NULL;
	static MSF_BOOL noOfSlidesExeedsMax = FALSE;
	char *tmpStr;
	char *paramName;
	char *paramValue;
	char *temp = NULL;
	   
	    mms_mma_queue_struct *entry = mma_parse_get_active_task();
		mma_parse_info_struct *info = (mma_parse_info_struct*) entry->data;	
		InstanceData *ctx = &info->ctx;
	
	(void)userData;

	




    switch (*ctx->stackP)
    {
    case SMIL_ELEMENT_SMIL:
        noOfSlidesExeedsMax = FALSE;
        break;
    case SMIL_ELEMENT_BODY:
        if (SMIL_ELEMENT_PAR == type)
        {
            
            if (MAX_NO_OF_SLIDES == ctx->slidePointer)
            {
                
				noOfSlidesExeedsMax = TRUE;
				break;                
            }

            
            
            ctx->parList[ctx->slidePointer].used = 1;
            
            
            e = NULL;
            if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_DUR, 0,
                &ctx->parList[ctx->slidePointer].dur, &e))
            {
                
                ctx->parList[ctx->slidePointer].dur = 0;
            }
            else
			{
				ctx->parList[ctx->slidePointer].dur = getSec(ctx->parList[ctx->slidePointer].dur, e);     
			}
      
        }
        break;
    case SMIL_ELEMENT_PAR:
		if (noOfSlidesExeedsMax)
		{
			break;
		}
        if (SMIL_ELEMENT_IMG == type )
        {
            medObj = allocMediaObj(ctx);
            medObj->mediaObjectElement = SMIL_MEDIA_OBJECT_IMG;
            medObj->src = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_SRC,ctx);
            temp = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ALT, ctx);
			if(temp)
			{
				medObj->alt = msf_cmmn_strndup(ctx->memId, temp, SMIL_MAX_ALT_STR_LEN);
			}
			MSF_MEM_FREE(ctx->memId, temp);
            storeSlideElementInfo(medObj, SMIL_ELEMENT_IMG, attrs, numAttrs);
			
			 
#if (SLS_EXTENDED_HANDLING_OF_REGIONS == 1)
			{
				if (ctx->regions == NULL)
				{
					
					medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
				}
				else
				{
				char* tempRegion = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION,ctx);
				Regions *tempCtxRegion = ctx->regions;
				int findImage = 0;
				
				
				while(tempCtxRegion &&  tempRegion && msf_cmmn_strcmp_nc(tempRegion,tempCtxRegion->id))
				{
					
					if(!findImage)
					{
						findImage = !msf_cmmn_strcmp_nc("Image",tempCtxRegion->id);
					}
					tempCtxRegion = tempCtxRegion->next;
				}

				
				if(tempCtxRegion == NULL)
				{
					
					if(findImage)
					{
						
						medObj->region = msf_cmmn_strdup(ctx->memId,"Image");
					}
					else
					{
						
						medObj->region = msf_cmmn_strdup(ctx->memId,ctx->regions->id);
					}					
					MSF_MEM_FREE(ctx->memId, tempRegion);
				}
				else
				{
					
					medObj->region = tempRegion;
				}
			}
			}
#else 
            medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
#endif
        }
		else if (SMIL_ELEMENT_VIDEO == type )
        {
            medObj = allocMediaObj(ctx);
            medObj->mediaObjectElement = SMIL_MEDIA_OBJECT_VIDEO;
            medObj->src = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_SRC, ctx);
            temp = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ALT, ctx);
			if(temp)
			{
				medObj->alt = msf_cmmn_strndup(ctx->memId, temp, SMIL_MAX_ALT_STR_LEN);
			}
			MSF_MEM_FREE(ctx->memId, temp);
            medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
            storeSlideElementInfo(medObj, SMIL_ELEMENT_VIDEO, attrs, numAttrs);

        }
        else if (SMIL_ELEMENT_TEXT == type )
        {
            medObj = allocMediaObj(ctx);
            medObj->mediaObjectElement = SMIL_MEDIA_OBJECT_TEXT;
            medObj->src = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_SRC, ctx);
            temp = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ALT, ctx);
			if(temp)
			{
				medObj->alt = msf_cmmn_strndup(ctx->memId, temp, SMIL_MAX_ALT_STR_LEN);
			}
			MSF_MEM_FREE(ctx->memId, temp);
            storeSlideElementInfo(medObj, SMIL_ELEMENT_TEXT, attrs, numAttrs);

            
			
			
			 
#if (SLS_EXTENDED_HANDLING_OF_REGIONS == 1)
			{
				if (ctx->regions == NULL)
				{
					
					medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
				}
				else
				{
				char* tempRegion = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
				Regions *tempCtxRegion = ctx->regions;
				int findText = 0;
				
				
				while(tempCtxRegion && tempRegion && msf_cmmn_strcmp_nc(tempRegion,tempCtxRegion->id))
				{
					
					if(!findText)
					{
						findText = !msf_cmmn_strcmp_nc("Text",tempCtxRegion->id);
					}
					tempCtxRegion = tempCtxRegion->next;
				}

				
				if(tempCtxRegion == NULL)
				{
					
					if(findText)
					{
						
						medObj->region = msf_cmmn_strdup(ctx->memId,"Text");
					}
					else
					{
						
						medObj->region = msf_cmmn_strdup(ctx->memId,ctx->regions->id);
					}					
					MSF_MEM_FREE(ctx->memId, tempRegion);
				}
				else
				{
					
					medObj->region = tempRegion;
				}
			}
			}
#else 
            medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
#endif 
		}

        else if (SMIL_ELEMENT_AUDIO == type )
        {
            medObj = allocMediaObj(ctx);
            medObj->mediaObjectElement = SMIL_MEDIA_OBJECT_AUDIO;
            medObj->src = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_SRC, ctx);
            temp = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ALT, ctx);
			if(temp)
			{
				medObj->alt = msf_cmmn_strndup(ctx->memId, temp, SMIL_MAX_ALT_STR_LEN);
			}
			MSF_MEM_FREE(ctx->memId, temp);
            storeSlideElementInfo(medObj, SMIL_ELEMENT_AUDIO, attrs, numAttrs);
        }

        else if (SMIL_ELEMENT_REF == type  && ctx->refMediaCount++ < SLS_MAX_REF_ELEMENTS)
        {
            medObj = allocMediaObj(ctx);
            medObj->mediaObjectElement = SMIL_MEDIA_OBJECT_REF;
            medObj->src = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_SRC, ctx);
            temp = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ALT, ctx);
			if(temp)
			{
				medObj->alt = msf_cmmn_strndup(ctx->memId, temp, SMIL_MAX_ALT_STR_LEN);
			}

			MSF_MEM_FREE(ctx->memId, temp);
            medObj->region = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_REGION, ctx);
            storeSlideElementInfo(medObj, SMIL_ELEMENT_REF, attrs, numAttrs);
        }

        if (isDupMediaObj(medObj, ctx))
        {
            SmilMediaObject    *list = ctx->parList[ctx->slidePointer].mobj;
            while (list)
            {
                if (list->next == medObj)
                {
                    list->next = medObj->next;
                    break;
                }
                list = list->next;
            }

            if (medObj != NULL)
            {
                MSF_MEM_FREE(ctx->memId, medObj->src);
                MSF_MEM_FREE(ctx->memId, medObj->alt);
                MSF_MEM_FREE(ctx->memId, medObj->region);
                MSF_MEM_FREE(ctx->memId, medObj);
                medObj = NULL;
            }
        }
        break;
	case SMIL_ELEMENT_TEXT:
	case SMIL_ELEMENT_IMG:
	case SMIL_ELEMENT_VIDEO:
	case SMIL_ELEMENT_AUDIO:


		{
			if (SMIL_ELEMENT_PARAM == type)
			{
				paramName = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_NAME, ctx);
				paramValue = NULL;
				paramValue = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_VALUE, ctx);
				if(paramName == NULL || paramValue == NULL)
				{
					if (paramName != NULL)
					{
						MSF_MEM_FREE(ctx->memId, paramName);
					}
					if (paramValue != NULL)
					{
						MSF_MEM_FREE(ctx->memId, paramValue);
					}
					break;
				}
				if ( (msf_cmmn_strcmp_nc(paramName, SMIL_ATTR_PARAM_COLOR) == 0) || (msf_cmmn_strcmp_nc(paramName, SMIL_ATTR_PARAM_COLOR_) == 0) )
					
				{
					medObj->color = colorSTOI((const char *)paramValue);
				}
				else if (MMA_RESULT_OK != addSlsParamListElement1(&medObj->tmpParamList, paramName, paramValue, ctx))
				{
					if (paramName != NULL)
					{
						MSF_MEM_FREE(ctx->memId, paramName);
					}
					if (paramValue != NULL)
					{
						MSF_MEM_FREE(ctx->memId, paramValue);
					}
					break;
				}
			}
		}
		break;
    case SMIL_ELEMENT_LAYOUT:
		if (noOfSlidesExeedsMax)
		{
			break;
		}		
        if (SMIL_ELEMENT_ROOT_LAYOUT == type)
        {
            e = NULL;
            if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_WIDTH,
                &info->root_layout.cx.value, 0, &e))
            {
                 info->root_layout.cx.value = 0;
            }
            else
            {				
                if (e && *e == '%')
                {
                    info->root_layout.cx.type = SLS_REL;
                }
                else
                {
                    info->root_layout.cx.type = SLS_ABS;
                }
            }
            e = NULL;
            if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_HEIGHT,
                &info->root_layout.cy.value, 0, &e))
            {
               info->root_layout.cy.value = 0;
            }
            else
            {					
                if (e && *e == '%')
                {
                    info->root_layout.cy.type = SLS_REL;
                }
                else
                {
                   info->root_layout.cy.type = SLS_ABS;
                }
            }

			tmpStr = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_BG_COLOR, ctx);
			 info->root_layout.bgColor = colorSTOI((const char *)tmpStr);
			  if (info->root_layout.bgColor == SLS_COLOR_NOT_USED)
				 {
					    info->root_layout.bgColor = MMA_CFG_SMIL_BG_COLOR;
				  }
			 
            MSF_MEM_FREE(ctx->memId, tmpStr);
        }
        if (SMIL_ELEMENT_REGION == type)
        {
            getRegions(attrs, numAttrs, ctx);
        }
        break;
    default:
        break;
    }

    pushElement(ctx, type);

    if (numAttrs)
    {
        msf_prsr_free_attributes(ctx->memId, attrs, numAttrs); 
    }
    return MSF_PRSR_APPLICATION_OK;
} 





static int endElementCallback(void* userData)
{

	 mms_mma_queue_struct *entry = mma_parse_get_active_task();
	 mma_parse_info_struct *info = (mma_parse_info_struct*) entry->data;	
	 InstanceData *ctx = &info->ctx;

    (void)userData;
    
    if (SMIL_ELEMENT_PAR == *ctx->stackP)
    {
        
        ctx->slidePointer++;
    } 
	if (ctx->slidePointer > MAX_NO_OF_SLIDES)
	{
		
		return MSF_PRSR_APPLICATION_ERROR;
	}
	else
	{
		(void)popElement(ctx);
		return MSF_PRSR_APPLICATION_OK;
	} 

}





static char *getStrAttr(const msf_prsr_attribute_t *attr, int numAttrs, int type, InstanceData *ctx)
{
    while (numAttrs--)
    {
        if (attr->type == type)
        {
            if (MSF_PRSR_ATTRVAL_STR == attr->flag)
            {
                if (attr->u.s)
                {
                    return msf_cmmn_strdup(ctx->memId, attr->u.s);
                }
                else
                {
                    return NULL;
                }
            }
        }
        attr++;
    }
    return NULL;
} 




static MSF_UINT32 getSec(MSF_UINT32 value, const char *e)
{
    MSF_UINT32 sec = 0;

    if (!e)
    {
        if (value > 1000)
        {
            sec = value / 1000;
        }
        else
        {
            sec = value;
        }
    }
    else 
    {
        switch (*e)
        {
        case 'h':
            sec = (value * 3600);
            break;
        case 'm':
            if (*(e + 1) == 's')
            {
                sec = (value > 0 && value < 1000) ? 1 : value / 1000;
            }
            else if (!msf_cmmn_strncmp_nc("minute", e, MIN(strlen("minute"), strlen(e))))
            {
                sec = (value * 60);
            }
            break;
            
        case 's':
            sec = value;
            break;
        default:
            break;
        }
    }
    return sec;
}




static SmilMediaObject* allocMediaObj(InstanceData *ctx)
{
    SmilMediaObject    *medObj = ctx->parList[ctx->slidePointer].mobj;
    
    if (medObj == NULL)
    {
        ctx->parList[ctx->slidePointer].mobj = 
            MSF_MEM_ALLOC(ctx->memId, sizeof(SmilMediaObject));
        ctx->parList[ctx->slidePointer].mobj->next = NULL;
        ctx->parList[ctx->slidePointer].mobj->src = NULL;
        ctx->parList[ctx->slidePointer].mobj->alt = NULL;
        ctx->parList[ctx->slidePointer].mobj->region = NULL;
        ctx->parList[ctx->slidePointer].mobj->begin = 0;
        ctx->parList[ctx->slidePointer].mobj->end = 0;
        ctx->parList[ctx->slidePointer].mobj->dur = 0;

		ctx->parList[ctx->slidePointer].mobj->color = SLS_COLOR_NOT_USED;
		ctx->parList[ctx->slidePointer].mobj->tmpParamList = NULL;

        return ctx->parList[ctx->slidePointer].mobj;
    }
    else
    {		
        while (medObj->next != NULL)
        {
            medObj = medObj->next;
        }
        medObj->next = MSF_MEM_ALLOC(ctx->memId, sizeof(SmilMediaObject));
        medObj = medObj->next;
        medObj->next = NULL;
        medObj->src = NULL;
        medObj->alt = NULL;
        medObj->region = NULL;
        medObj->begin = 0;
        medObj->end = 0;
        medObj->dur = 0;

		medObj->color = SLS_COLOR_NOT_USED;
		medObj->tmpParamList = NULL;

        return medObj;
    } 
} 





static void storeSlideElementInfo(SmilMediaObject *medObj, int type, 
    const msf_prsr_attribute_t* attrs, int numAttrs)
{
    char *e = NULL;

    if (getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_BEGIN, 
        0, &medObj->begin, &e))
    {
        medObj->begin = getSec(medObj->begin, e);
    }
    else
    {
        medObj->begin = 0;
    }
    
    if (getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_END, 
        NULL, &medObj->end, &e))
    {
        medObj->end = getSec(medObj->end, e);
    }
    else
    {
        medObj->end = 0;
    }

    if (getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_DUR, 
        NULL, &medObj->dur, &e))
    {
        medObj->dur = getSec(medObj->dur, e);
    }
    else
    {
        medObj->dur = 0;
    }
}





static MSF_UINT32 colorSTOI(const char *colorStrVal)
{
	MSF_UINT32 color = 0;
	int index = 0;
	unsigned char tmp1;
	unsigned char tmp2;
	unsigned char tmp3;

	if (colorStrVal == NULL)
	{
		return SLS_COLOR_NOT_USED;
	} 

	
	if (colorStrVal[0] == SLS_HASH_MARK)
	{
		
		if (!msf_cmmn_hex2byte(&colorStrVal[1], &tmp1) || 
			!msf_cmmn_hex2byte(&colorStrVal[3], &tmp2) ||
			!msf_cmmn_hex2byte(&colorStrVal[5], &tmp3))
		{
			return SLS_COLOR_NOT_USED;
		}
		else
		{
			color+= tmp1 << 16;
			color+= tmp2 << 8;
			color+= tmp3;
		} 

	}
	else
	{
		

		while (MSColorSet[index].colorName != NULL)
		{
			if (0 == msf_cmmn_strcmp_nc(MSColorSet[index].colorName, colorStrVal))
			{
				return MSColorSet[index].colorValue;
			} 
			index++;
		} 

		
		color = SLS_COLOR_NOT_USED;
	} 
	return color;
} 



mma_region_fit_enum getFitAtr(MSF_UINT32 val)
{
	switch (val)
	{
	case 0x0A00:
		return MMA_REGION_FIT_FILL;
	case 0x0A01:
		return MMA_REGION_FIT_HIDDEN;
	case 0x0A02:
		return MMA_REGION_FIT_MEET;
	case 0x0A03:
		return MMA_REGION_FIT_SCROLL;
	case 0x0A04:
		return MMA_REGION_FIT_SLICE;
	default:
		return MMA_REGION_FIT_NONE;
	}
} 






 int mma_get_no_of_slides(InstanceData ctx)
{
    int i = 0/*,  pass = 0*/;
    SmilMediaObject *mo;
 /* MSF_UINT32 charset = MSF_CHARSET_UNKNOWN, offset, size;
	SlsMediaType type;
	char *fileName, *boundary, *mimeType; */

    while ((i < MAX_NO_OF_SLIDES) && ctx.parList[i].used)
    {
        mo = ctx.parList[i].mobj;
        if (mo)
        {
            if ((SMIL_MEDIA_OBJECT_AUDIO == mo->mediaObjectElement || 
                SMIL_MEDIA_OBJECT_IMG    == mo->mediaObjectElement ||
				SMIL_MEDIA_OBJECT_VIDEO  == mo->mediaObjectElement ||
                SMIL_MEDIA_OBJECT_TEXT   == mo->mediaObjectElement) &&
                mo->src)
            {
              //  pass = 1;
            } 
            else if ((SMIL_MEDIA_OBJECT_REF == mo->mediaObjectElement) && 
                (NULL != mo->src) /*&& (TRUE == getMediaObject(mo->src, &offset, 
                &size, &type, &charset, &fileName, &boundary, &mimeType))*/)
            {/*
                
                for (j = 0; SLS_NOT_USED != slsSupportedMediaTypes[j].mediaType; j++)
                {
                    if (slsSupportedMediaTypes[j].mediaType == type)
                    {
                        pass = 1;
                        switch (slsSupportedMediaTypes[j].objectType)
                        {
                        case SLS_OBJECT_TYPE_TEXT: 
						case SLS_OBJECT_TYPE_IMAGE:
						case SLS_OBJECT_TYPE_AUDIO:
						case SLS_OBJECT_TYPE_VIDEO:
						case SLS_OBJECT_TYPE_DRM:
                          //  mo->mediaObjectElement = SMIL_MEDIA_OBJECT_TEXT; 
                            break;
                        case SLS_OBJECT_TYPE_IMAGE:
                            mo->mediaObjectElement = SMIL_MEDIA_OBJECT_IMG;
                            break;
                        case SLS_OBJECT_TYPE_AUDIO:
                            mo->mediaObjectElement = SMIL_MEDIA_OBJECT_AUDIO;
                            break;
                        case SLS_OBJECT_TYPE_VIDEO:
                            mo->mediaObjectElement = SMIL_MEDIA_OBJECT_VIDEO;
                            break;
                        case SLS_OBJECT_TYPE_DRM:       
                        default:
                            pass = 0;
                            break;
                        }                         
                    } 
                } 
     */   } 
    } 
        else if (i == 0)
    {
           // pass = 1;
    }
        i++;
    } 
    return i > 0 ? i : 0;

} 

mma_result_enum addSlsParamListElement1(SlsParameterList **paramlisthead, char *name, char *value, InstanceData *ctx)
{
	SlsParameterList *tmpListPtr     = NULL;
           
    if(strlen(name)==0 || strlen(value)==0 || strlen(name) > SLS_PARAM_MAX_NAME_VALUE_LENGTH || strlen(value) > SLS_PARAM_MAX_NAME_VALUE_LENGTH)
	{
		return MMA_RESULT_FAIL ;
	}
	if (*paramlisthead == NULL)
    {
        *paramlisthead = MSF_MEM_CALLOC(ctx->memId, 1, sizeof(SlsParameterList));
		if(NULL == *paramlisthead)
		{
			return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY ;
		}
        tmpListPtr = *paramlisthead;
    }
    else
    {
        tmpListPtr = *paramlisthead;

        while (tmpListPtr->next != NULL)
        {
            tmpListPtr = tmpListPtr->next;
        } 
        
        tmpListPtr->next = MSF_MEM_CALLOC(ctx->memId, 1, sizeof(SlsParameterList));
        tmpListPtr = tmpListPtr->next;
		if(NULL == tmpListPtr)
		{
			return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY ;
		}
    } 
    tmpListPtr->param.name = name;
    tmpListPtr->param.value = value;
	return MMA_RESULT_OK;
}


static int charDataCallback(void* userData, const char* s, int len, int mode)
{
    (void)userData;
    (void)s;
    (void)len;
    (void)mode;
    return MSF_PRSR_APPLICATION_OK;
} 



static void getRegions(const msf_prsr_attribute_t* attrs, int numAttrs, InstanceData *ctx)
{
    Regions *reg = ctx->regions;
    char *e = NULL;
	MSF_UINT32 tmpFit = 0;

    
    if (!ctx->regions)
    {
        ctx->regions = MSF_MEM_ALLOC(ctx->memId, sizeof(Regions));
        reg = ctx->regions;
    }
    else
    {
        char *id = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ID, ctx);

        while (reg->next)
        {
            if (strcmp(id, reg->id) == 0)  /* region name duplicated, return */
            {
                MSF_MEM_FREE(ctx->memId, id);
                return;
            }

            reg = reg->next;
        }
        if (strcmp(id, reg->id) == 0)  /* region name duplicated, return */
        {
            MSF_MEM_FREE(ctx->memId, id);
            return;
        }
        MSF_MEM_FREE(ctx->memId, id);

        reg->next = MSF_MEM_ALLOC(ctx->memId, sizeof(Regions));
        reg = reg->next;
    }
    
    reg->id = NULL;
    reg->position.cx.value = 0;
    reg->position.cy.value = 0;
    reg->position.cx.type = SLS_ABS;
    reg->position.cy.type = SLS_ABS;
    reg->size.cx.value = 0;
    reg->size.cy.value = 0;
    reg->size.cx.type = SLS_ABS;            
    reg->size.cy.type = SLS_ABS;		
    reg->next = NULL;
    
    

    
    reg->id = getStrAttr(attrs, numAttrs, SMIL_ATTRIBUTE_ID, ctx);

    
    if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_LEFT,
        &reg->position.cx.value, 0,  &e))
    {      
        reg->position.cx.value = 0;
    }
    else
    {
        if (e && *e == '%')
        {
            reg->position.cx.type = SLS_REL;
        }
        else
        {
            reg->position.cx.type = SLS_ABS;
        }
    }
    e = NULL;
    if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_TOP,
        &reg->position.cy.value, 0, &e))
    {
        reg->position.cy.value = 0;
    }            
    else
    {
        if (e && *e == '%')
        {
            reg->position.cy.type = SLS_REL;
        }
        else
        {
            reg->position.cy.type = SLS_ABS;
        }
    }
    
    e = NULL;
    if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_WIDTH,
        &reg->size.cx.value, 0, &e))
    {
        reg->size.cx.value = SLS_SIZE_NOT_USED;
    }
    else
    {
        if (e && *e == '%')
        {
            reg->size.cx.type = SLS_REL;
        }
        else
        {
            reg->size.cx.type = SLS_ABS;
        }
    }
    e = NULL;
    if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_HEIGHT,
        &reg->size.cy.value, 0, &e))
    {
        reg->size.cy.value = SLS_SIZE_NOT_USED;
    }            
    else
    {
        if (e && *e == '%')
        {
            reg->size.cy.type = SLS_REL;
        }
        else
        {
            reg->size.cy.type = SLS_ABS;
        }
    }
		
	if (!getIntAttr(attrs, numAttrs, SMIL_ATTRIBUTE_FIT, 0,
        &tmpFit, &e))
    {
        reg->fit = MMA_REGION_FIT_NONE;
    }
	else
	{
		reg->fit = getFitAtr(tmpFit);
	}
} 


 



int mma_generate_region_from_SMILctx(char *regionId, mma_mms_object_area_struct *objectRegion, InstanceData *ctx)
{
    Regions *region = NULL;
    char *str = NULL;
	int found = 0;
		 

      region = ctx->regions;

    
    objectRegion->x.type = MMA_MMS_TIME_ABSOLUTE;
    objectRegion->x.value = 0;

    objectRegion->y.type = MMA_MMS_TIME_ABSOLUTE;
    objectRegion->y.value = 0;

    objectRegion->w.type = MMA_MMS_TIME_ABSOLUTE;
    objectRegion->w.value = SLS_SIZE_NOT_USED;

    objectRegion->y.type = MMA_MMS_TIME_ABSOLUTE;
    objectRegion->y.value = SLS_SIZE_NOT_USED;
 
	if (regionId == NULL || *regionId == '\0' || region == NULL)
    {
        return 0;
    }

    str = regionId;
    
    while (region != NULL && objectRegion != NULL) 
    {
        if (!msf_cmmn_strcmp_nc(region->id, str))
        {
			objectRegion->x.type = (region->position.cx.type == 0) ? MMA_MMS_TIME_ABSOLUTE : MMA_MMS_TIME_RELATIVE;
			objectRegion->x.value = region->position.cx.value;

			objectRegion->y.type = (region->position.cy.type == 0) ? MMA_MMS_TIME_ABSOLUTE : MMA_MMS_TIME_RELATIVE;
			objectRegion->y.value = region->position.cy.value;

			objectRegion->w.type = (region->size.cx.type == 0) ? MMA_MMS_TIME_ABSOLUTE : MMA_MMS_TIME_RELATIVE;
			objectRegion->w.value = region->size.cx.value;

			objectRegion->h.type = (region->size.cy.type == 0) ? MMA_MMS_TIME_ABSOLUTE : MMA_MMS_TIME_RELATIVE;
			objectRegion->h.value = region->size.cy.value;

			found = 1;		/*a valid region is found*/
           // objectRegion->size = region->size;
			//objectRegion->fit = region->fit;
            //objectRegion->is_valid = 1;
        } 
        region = region->next;
    } 
    
    return found;
} 	









void mma_parse_free_smil_ctx(InstanceData *ctx)
{
	int i = 0;
    SmilMediaObject *mo;
    SmilMediaObject *tmp;
    Regions *reg = ctx->regions;
    
	if (ctx->smilData != NULL)
    {
        MSF_MEM_FREE(ctx->memId, ctx->smilData);
        ctx->smilData = NULL;
    }

    
    while (reg)
    {
        ctx->regions = reg->next;
        MSF_MEM_FREE(ctx->memId, reg->id);
        MSF_MEM_FREE(ctx->memId, reg);
        reg = ctx->regions;
    }
    ctx->regions = NULL;
    ctx->slidePointer = 0;

    
  
    
    
    i = 0;
    while ((i < MAX_NO_OF_SLIDES) && ctx->parList[i].used)
    {
        mo = ctx->parList[i].mobj;
        while (mo)
        {
            if (mo->src)
            {
                MSF_MEM_FREE(ctx->memId, mo->src);
            }
            if (mo->alt)
            {
                MSF_MEM_FREE(ctx->memId, mo->alt);
            }
            if (mo->region)
            {
                MSF_MEM_FREE(ctx->memId, mo->region);
            }

            mo->begin = 0;
            mo->end = 0;
            mo->dur = 0;

          

	    MmaFreeParamList(ctx->memId,&mo->tmpParamList);

            tmp = mo;
            mo = mo->next;
            MSF_MEM_FREE(ctx->memId, tmp);
        } 
        ctx->parList[i].dur = 0;
        ctx->parList[i].used = 0;
        ctx->parList[i].mobj = NULL;
        i++;
    } 
	
	if(ctx->parList)
	{
		MMA_FREE(ctx->parList);
	}
	if(ctx->elementStack)
	{
		MMA_FREE(ctx->elementStack);
	}   
	
	
	
}







void MmaFreeParamList(MSF_UINT8 modId, SlsParameterList **slideParamList)
{
	SlsParameterList	*tmpSlideParamList;

	while(*slideParamList != NULL)
	{
		tmpSlideParamList = *slideParamList;
		*slideParamList = (*slideParamList)->next;
		MSF_MEM_FREE(modId,tmpSlideParamList->param.name);
		MSF_MEM_FREE(modId,tmpSlideParamList->param.value);
		MSF_MEM_FREE(modId,tmpSlideParamList);
	}
}




















static void copySlsRegion(const SlsRegion *source, SlsRegion *dest)
{
    if (source == NULL || dest == NULL) 
    {
        /* no input */
        return;
    } /* if */
    
    dest->position.cx.type = source->position.cx.type;
    dest->position.cx.value= source->position.cx.value;
    dest->position.cy.type = source->position.cy.type;
    dest->position.cy.value= source->position.cy.value;
    dest->size.cx.type = source->size.cx.type;
    dest->size.cx.value= source->size.cx.value;
    dest->size.cy.type = source->size.cy.type;
    dest->size.cy.value= source->size.cy.value;
	dest->fit= source->fit;
} /* copySlsRegion */




static void copySlsRootLayout(const SlsRootLayout *source, SlsRootLayout *dest)
{
	if (source == NULL || dest == NULL) 
    {
       
        return;
    } 

	dest->bgColor = source->bgColor;
	dest->cx.type = source->cx.type;
	dest->cx.value = source->cx.value;
	dest->cy.type = source->cy.type;
	dest->cy.value = source->cy.value;
} 






















static MSF_BOOL copySlsMediaObj(MSF_UINT8 modId, const SlsMediaObject *source, 
	SlsMediaObject *dest)
{
	MSF_BOOL ret = TRUE;

    if (dest == NULL) 
    {
        
        return FALSE;
    } 
	
	memset(dest, 0x00, sizeof(SlsMediaObject));
	if (source == NULL)
	{
		
		dest->type = SLS_NOT_USED;
		return TRUE;
	} 
	
	dest->beginT = source->beginT;
	dest->color = source->color;
	dest->endT = source->endT;
	dest->region = msf_cmmn_strdup(modId, source->region);
	dest->src = msf_cmmn_strdup(modId, source->src);
	dest->type = source->type;
	
	if ((dest->region == NULL) && (source->region != NULL))
	{
		
		if (dest->src != NULL)
		{
			MSF_MEM_FREE(modId, dest->src);
			dest->src = NULL;
			ret = FALSE;
		} 
	} 
	if ((dest->src == NULL) && (source->src != NULL))
	{
		
		if (dest->region != NULL)
		{
			MSF_MEM_FREE(modId, dest->region);
			dest->region = NULL;
			return FALSE;
		} 
	} 
if(source->slsparamList != NULL)
{
	slscpyParamListInfo(modId,source->slsparamList,&dest->slsparamList,NULL);
}

	return ret;
} 



mma_result_enum slscpyParamListInfo(MSF_UINT8 modId,SlsParameterList *rootParamList,SlsParameterList **slideparamList,MSF_UINT32 *count)
{
	SlsParameterList *tmpParamList = NULL;
	
	while(rootParamList)
	{
		if(rootParamList->param.name!=NULL
			&& rootParamList->param.value!=NULL)
		{
			if(*slideparamList == NULL)
			{
				*slideparamList = MSF_MEM_ALLOC(modId, sizeof(SlsParameterList));
				tmpParamList = *slideparamList;
			}
			else
			{
				tmpParamList = *slideparamList;
				while(tmpParamList->next != NULL)
				{
					tmpParamList = tmpParamList->next;
				}
				tmpParamList->next = MSF_MEM_ALLOC(modId, sizeof(SlsParameterList));
				tmpParamList = tmpParamList->next;
			}
			if (tmpParamList == NULL)
			{
				return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
			}
			memset(tmpParamList , 0x00, sizeof(SlsParameterList));
			tmpParamList->param.name = msf_cmmn_strdup(modId,(const char *)rootParamList->param.name);
			tmpParamList->param.value = msf_cmmn_strdup(modId,(const char *)rootParamList->param.value);
			if(count)
			{
				(*count)++;
			}
		}
		rootParamList = rootParamList->next;
	}
	return MMA_RESULT_OK;
}






static MSF_BOOL copyRefMediaObj(MSF_UINT8 modId, const SlsMediaObject *refList, 
	SlsMediaObject **refItemList)
{
	MSF_BOOL ret = TRUE;
	SlsMediaObject *tempRefItemList = NULL;

    if (refItemList == NULL) 
    {
       return FALSE;
    } 
	while(refList != NULL)
	{
		if(*refItemList == NULL)
		{
			*refItemList = MSF_MEM_ALLOC(modId, sizeof(SlsMediaObject));
			tempRefItemList = *refItemList;
		}
		else
		{
			tempRefItemList = *refItemList;
			while(tempRefItemList->next != NULL)
			{
				tempRefItemList = tempRefItemList->next;
			}
			tempRefItemList->next = MSF_MEM_ALLOC(modId, sizeof(SlsMediaObject));
			tempRefItemList = tempRefItemList->next;
		}
		if (tempRefItemList == NULL)
		{
			return FALSE;
		}
		memset(tempRefItemList , 0x00, sizeof(SlsMediaObject));
		
		tempRefItemList->type =	refList->type;
		tempRefItemList->beginT = refList->beginT;
		tempRefItemList->endT =	refList->endT;
		tempRefItemList->color = refList->color;
		tempRefItemList->duration =	refList->duration;
		tempRefItemList->region = msf_cmmn_strdup(modId,refList->region);

		//if(NULL == tempRefItemList->region)
		//{
			//return FALSE;
		//}
		tempRefItemList->src = msf_cmmn_strdup(modId,refList->src);

		if(NULL == tempRefItemList->src)
		{
			MSF_MEM_FREE(modId, tempRefItemList->region);
			return FALSE;
		}
		if(refList->slsparamList != NULL)
		{
			slscpyParamListInfo(modId,refList->slsparamList,&tempRefItemList->slsparamList,NULL);
		}
		refList = refList->next;
	}
	return ret;
}



void smilgetParamAttributelength(SlsParameterList  *list, MSF_UINT32 *size)
{
	while(list != NULL)
	{
		if(list->param.name)
		{
			*size += strlen(list->param.name);
		}
		if(list->param.name)
		{
			*size += strlen(list->param.name);
		}
		list = list->next;
	}
}



void smilconcatParamList(SlsParameterList  *list,char **Buff)
{
	while(list != NULL)
	{
		if(list->param.name)
		{
			strcat(*Buff, SLS_PARAM);
			strcat(*Buff, SLS_PARAM_SPACE);
			strcat(*Buff, SLS_PARAM_NAME);
			strcat(*Buff, list->param.name);
			strcat(*Buff, SLS_END_QUOTE);
			strcat(*Buff, SLS_PARAM_SPACE);
		}
		if(list->param.value)
		{
			strcat(*Buff, SLS_PARAM_VALUE);
			strcat(*Buff, list->param.value);
			strcat(*Buff, SLS_END_QUOTE);
			strcat(*Buff, SLS_TEXT_T5);
		}
		list = list->next;
	}
}	


static void sls_itoacol(MSF_UINT32 color, char *s)
{
    
    s[0] = SLS_HASH_MARK;

 
    msf_cmmn_byte2hex((unsigned char)(color>>16), &(s[1]));
    msf_cmmn_byte2hex((unsigned char)(color>>8), &(s[3]));
    msf_cmmn_byte2hex((unsigned char)color, &(s[5]));
    s[7] = MSF_EOS;
} 








static void sls_itoa(SlsSizeValue val, char *s)
{
    int i;
    int n = val.value;
    char *c;
    
    c = s;
    if ((i = n) < 0)
    {
        n = -n;
    }
    do 
    {
        *c++ = (char)(n % 10 + '0');
    } while ((n = n / 10) > 0);
    if (i < 0)
    {
        *c++ = '-';
    }

    *c = '\0';

    sls_reverse(s);

    if (val.type == SLS_REL)
    {
        *c++ = '%';
        *c = '\0';
    }
}


static void sls_reverse(char *s)
{
    char *j;
    int c;

    j = s + strlen(s) - 1;
    while(s < j) 
    {
        c = *s;
        *s++ = *j;
        *j-- = (char)c;
    }
}

void smilgetRefAttributeLength(SlsMediaObject  *list, MSF_UINT32 *size)
{
	while(list != NULL)
	{
		*size += sizeof(SLS_REF_T1) + sizeof(SLS_REF_T2) +
            sizeof(SLS_REF_T3) + sizeof(SLS_REF_T4) +
            strlen(list->src) + 2*SLS_INTSZ; 
		slsgetParamAttributelength(list->slsparamList,size);
		list = list->next;
	}
}






void slsgetParamAttributelength(SlsParameterList  *list, MSF_UINT32 *size)
{
	while(list != NULL)
	{
		if(list->param.name)
		{
			*size += strlen(list->param.name);
		}
		if(list->param.name)
		{
			*size += strlen(list->param.name);
		}
		list = list->next;
	}
}













mma_result_enum mma_smil_createSmil(MSF_UINT8 modId, SlsCreateSmilHandle *handle,
    const SlsRootLayout *rootlayout)
{
    SlsCreateSmilData *p;


    *handle = MSF_MEM_ALLOC(modId, sizeof(SlsCreateSmilData));
    p = (SlsCreateSmilData*)*handle;
    p->regionList = NULL;
    p->rootLayout = NULL;
    p->slideList = NULL;
    
    if (rootlayout)
    {
        p->rootLayout = MSF_MEM_ALLOC(modId, sizeof(SlsRootLayout));
        if (!p->rootLayout)
        {
            return MMA_RESULT_FAIL;
        }
        copySlsRootLayout(rootlayout, p->rootLayout);
    } 


    return MMA_RESULT_OK;
}






mma_result_enum mma_smil_createRegion(MSF_UINT8        modId,
                           const SlsCreateSmilHandle *handle,
                           const SlsRegion *region,
                           const char      *name)
{	
    SlsRegionListNode *nodeP;
	SlsCreateSmilData *p = (SlsCreateSmilData*)*handle;
    mma_result_enum          result = MMA_RESULT_OK;		
    


    
    if (!region || !name)
    {
        result = MMA_RESULT_FAIL;
    }
 
    else if (!p)
    {
        result = MMA_SMIL_RESULT_SMIL_NOT_CREATED;
    }
    else
    {
       
        if (p->regionList)
        {
            nodeP = p->regionList;
            while (nodeP->next)
            {
                nodeP = nodeP->next;
            }
            
			nodeP->next = MSF_MEM_ALLOC(modId, sizeof(SlsRegionListNode));
            if (nodeP->next == NULL)
            {
                result = MMA_RESULT_FAIL;
            }
            nodeP = nodeP->next;
        }
        else
        {
            p->regionList = MSF_MEM_ALLOC(modId, sizeof(SlsRegionListNode));
            if (p->regionList == NULL)
            {
                result = MMA_RESULT_FAIL;
            }        
            nodeP = p->regionList;
        }
        nodeP->next = NULL;

        copySlsRegion(region, &(nodeP->data));
        nodeP->name = msf_cmmn_strdup(modId, name);
        if(nodeP->name == NULL)
        {
            result = MMA_RESULT_FAIL;
        }
    }


    return result;
}



mma_result_enum mma_smil_createSlide(MSF_UINT8       modId,
                          const SlsCreateSmilHandle *handle,
                          MSF_INT32            duration,
                          const SlsMediaObject *text,    
                          const SlsMediaObject *image,   
                          const SlsMediaObject *video,
                          const SlsMediaObject *audio,
						  const SlsMediaObject *refList)
{
    SlsCreateSmilData *p = (SlsCreateSmilData*)*handle;
    SlsSlideList      *list = p->slideList;
    mma_result_enum          result = MMA_RESULT_OK;



   

    if (p == NULL)
    {
        result = MMA_SMIL_RESULT_SMIL_NOT_CREATED;
    }
//	else if (text == NULL && image == NULL && audio == NULL && video == NULL)    
//    {
//        result = MMA_SMIL_RESULT_MISSING_MEDIA_OBJECTS;
//    }
	else if ((text != NULL && text->src  == NULL && text->region == NULL) ||
        (image != NULL && image->src == NULL && image->region == NULL) ||
        (video != NULL && video->src == NULL && video->region == NULL) ||
        (audio != NULL && audio->src == NULL))
	{
        result = MMA_SMIL_RESULT_MISSING_MEDIA_OBJECT_SRC;
    }
    else
    {
    
        if (p->slideList == NULL)
        {
            p->slideList = MSF_MEM_ALLOC(modId, sizeof(SlsSlideList));
            if (p->slideList == NULL)
            {
                return MMA_RESULT_FAIL;
            }
            list = p->slideList;
        }
        else
        {
            while (list->next != NULL)
            {
                list = list->next;
            }
            list->next = MSF_MEM_ALLOC(modId, sizeof(SlsSlideList));
            if (list->next == NULL)
            {
                return MMA_RESULT_FAIL;
            }
            list = list->next;      
        }
        list->next = NULL;
		memset(list ,0 ,sizeof(SlsSlideList));
        
        list->duration = duration;


  
        if (!copySlsMediaObj(modId, text, &(list->text)))
		{
			return MMA_RESULT_FAIL;
		} 

		if (!copySlsMediaObj(modId, image, &(list->image)))
		{
			return MMA_RESULT_FAIL;
		} 

        if (!copySlsMediaObj(modId, video, &(list->video)))
		{
			return MMA_RESULT_FAIL;
		} 

		if (!copySlsMediaObj(modId, audio, &(list->audio)))
		{
			return MMA_RESULT_FAIL;
		}

		if (!copyRefMediaObj(modId, refList, &(list->refList)))
		{
			return MMA_RESULT_FAIL;
		} 

    }

    return result;
}








mma_result_enum mma_smil_generateSmil(MSF_UINT8 modId, 
    const SlsCreateSmilHandle *handle, char **buffer)
{
    MSF_UINT32 size = 0;
    char tmp[256+271];  //* 271 = 261 FMGR_MAX_PATH_LEN +10 ("\external\")
    char tmpStrIntsz[SLS_INTSZ];
    SlsCreateSmilData *p = (SlsCreateSmilData*)*handle;
    SlsSlideList *list = NULL;
    SlsRegionListNode *regionNode = NULL;
    mma_result_enum result = MMA_RESULT_OK;
	MSF_UINT8 slideCnt = 0;
 

    //* Check state 
    if (p == NULL)
    {
        return MMA_SMIL_RESULT_SMIL_NOT_CREATED;
    }
	list = p->slideList;
	regionNode = p->regionList;
    
    //* Get size for buffer 
    size = sizeof(SLS_SMIL_START) + sizeof(SLS_SMIL_END) + 
        sizeof(SLS_HEAD_START) + sizeof(SLS_HEAD_END) +
        sizeof(SLS_LAYOUT_START) + sizeof(SLS_LAYOUT_END) +
        sizeof(SLS_BODY_START) + sizeof(SLS_BODY_END);
    
	if (p->rootLayout != NULL)
    {
     #ifndef __OP11_MMS_HIDE_ROOTLAYOUT_WIDTH_HEIGHT__   
		size += sizeof(SLS_ROOT_LAYOUT_T1) + sizeof(SLS_ROOT_LAYOUT_T2) +
            sizeof(SLS_ROOT_LAYOUT_T3) + sizeof(SLS_ROOT_LAYOUT_T4) + 
            SLS_INTSZ + SLS_INTSZ + SLS_INTSZ;
	#else
		size += sizeof(SLS_ROOT_LAYOUT_T3) + sizeof(SLS_ROOT_LAYOUT_T4) + 
            SLS_INTSZ + SLS_INTSZ + SLS_INTSZ;
	#endif
    }


    while (regionNode != NULL)
    {
        size += sizeof(SLS_REGION_T1) + sizeof(SLS_REGION_T2) + 
            sizeof(SLS_REGION_T3) + sizeof(SLS_REGION_T4) + 
            sizeof(SLS_REGION_T5) + sizeof(SLS_REGION_T6) + sizeof(SLS_REGION_T7) +
            strlen(regionNode->name) + 4*SLS_INTSZ;
        if (regionNode->data.fit != MMA_REGION_FIT_NONE)
        {
          size += SLS_FITSZ;
        }
        regionNode = regionNode->next;
    }
 
    while (list != NULL && (slideCnt < MAX_NO_OF_SLIDES))
    {
        size += sizeof(SLS_PAR_START) + SLS_INTSZ + sizeof(SLS_PAR_END);
        if (list->text.type != SLS_NOT_USED)
        {
            size += sizeof(SLS_TEXT_T1) + sizeof(SLS_TEXT_T2) + 
                sizeof(SLS_TEXT_T3) + sizeof(SLS_TEXT_T4) + sizeof(SLS_TEXT_T5) +
                strlen(list->text.src) + strlen(list->text.region) + 
                3*SLS_INTSZ;
			smilgetParamAttributelength(list->text.slsparamList,&size);
       }
        if (list->audio.type != SLS_NOT_USED)
        {
			size += sizeof(SLS_AUDIO_T1) + sizeof(SLS_AUDIO_T2) +
                sizeof(SLS_AUDIO_T3) + sizeof(SLS_AUDIO_T4) +
                strlen(list->audio.src) + 2*SLS_INTSZ; 
			smilgetParamAttributelength(list->audio.slsparamList,&size);
		}        
		if ((list->image.type != SLS_NOT_USED))
        {
            size += sizeof(SLS_IMAGE_T1) + sizeof(SLS_IMAGE_T2) + 
                sizeof(SLS_IMAGE_T3) + sizeof(SLS_IMAGE_T4) +
                strlen(list->image.src) + strlen(list->image.region) + 2*SLS_INTSZ;
			smilgetParamAttributelength(list->image.slsparamList,&size);
		}
		if ((list->video.type != SLS_NOT_USED))
        {
            size += sizeof(SLS_VIDEO_T1) + sizeof(SLS_VIDEO_T2) + 
                sizeof(SLS_VIDEO_T3) + sizeof(SLS_VIDEO_T4) +
                strlen(list->video.src) + strlen(list->video.region) + 2*SLS_INTSZ;
			smilgetParamAttributelength(list->video.slsparamList,&size);
		}
		smilgetRefAttributeLength(list->refList ,&size);

        list = list->next;
		slideCnt++;
    }

    //* Alloc space 
    *buffer = MSF_MEM_ALLOC(modId, size + 1);  
    if (*buffer == NULL)
    {
        return MMA_RESULT_FAIL;
    }

    //* Copy data 
    strcpy(*buffer, SLS_SMIL_START);
    strcat(*buffer, SLS_HEAD_START);
    strcat(*buffer, SLS_LAYOUT_START);

    //* Copy rootlayout 
    if (p->rootLayout != NULL)
    {
    #ifndef __OP11_MMS_HIDE_ROOTLAYOUT_WIDTH_HEIGHT__    
		strcat(*buffer, SLS_ROOT_LAYOUT_T1);
        sls_itoa(p->rootLayout->cx, tmp);
        strcat(*buffer, tmp);
        strcat(*buffer, SLS_ROOT_LAYOUT_T2);
        sls_itoa(p->rootLayout->cy, tmp);
        strcat(*buffer, tmp);
	#endif
        //* Append the root-layout color if defined 
        if (SLS_COLOR_NOT_USED != p->rootLayout->bgColor)
        {
            strcat(*buffer, SLS_ROOT_LAYOUT_T3);
            sls_itoacol(p->rootLayout->bgColor, tmp);
            strcat(*buffer, tmp);
        }
        strcat(*buffer, SLS_ROOT_LAYOUT_T4);
    }

    //* Copy regions 
    regionNode = p->regionList;
    while (regionNode != NULL)
    {
        strcat(*buffer, SLS_REGION_T1);
        strcat(*buffer, regionNode->name);
        strcat(*buffer, SLS_REGION_T2);
        sls_itoa(regionNode->data.size.cx, tmp);
        strcat(*buffer, tmp);
        strcat(*buffer, SLS_REGION_T3);
        sls_itoa(regionNode->data.size.cy, tmp);
        strcat(*buffer, tmp);
        strcat(*buffer, SLS_REGION_T4);
        sls_itoa(regionNode->data.position.cx, tmp);
        strcat(*buffer, tmp);
        strcat(*buffer, SLS_REGION_T5);
        sls_itoa(regionNode->data.position.cy, tmp);
        strcat(*buffer, tmp);
        strcat(*buffer, SLS_REGION_T6);

        switch (regionNode->data.fit)
        {
            case MMA_REGION_FIT_FILL:
              strcat(*buffer, SLS_FIT_FILL);
              break;
            case MMA_REGION_FIT_HIDDEN:
              strcat(*buffer, SLS_FIT_HIDDEN);
              break;
            case MMA_REGION_FIT_MEET:
              strcat(*buffer, SLS_FIT_MEET);
              break;
            case MMA_REGION_FIT_SCROLL:
              strcat(*buffer, SLS_FIT_SCROLL);
              break;
            case MMA_REGION_FIT_SLICE:
              strcat(*buffer, SLS_FIT_SLICE);
              break;
            case MMA_REGION_FIT_NONE:
            default:
              break;
        }
        strcat(*buffer, SLS_REGION_T7);
        regionNode = regionNode->next;
    }

    strcat(*buffer, SLS_LAYOUT_END);
    strcat(*buffer, SLS_HEAD_END);
    strcat(*buffer, SLS_BODY_START);

    //* Copy slides 
    list = p->slideList;
    slideCnt = 0;

    while (list != NULL && (slideCnt < MAX_NO_OF_SLIDES))
    {
        //* Copy duration 
        sprintf(tmp, SLS_PAR_START, list->duration);
        strcat(*buffer, tmp);
        
        //* Copy text MO 
        if (list->text.type != SLS_NOT_USED)
        {
            sprintf(tmp, SLS_TEXT_T1, list->text.src, list->text.region);
            strcat(*buffer, tmp);
            //* the begin param 
            if (0 != list->text.beginT)
            {
                sprintf(tmp, SLS_TEXT_T2, list->text.beginT);
                strcat(*buffer, tmp);
            }
            if (0 != list->text.endT)
            {
                sprintf(tmp, SLS_TEXT_T3, list->text.endT);
                strcat(*buffer, tmp);
            }
			if(list->text.slsparamList != NULL)
			{
				strcat(*buffer, SLS_TEXT_T6);
				smilconcatParamList(list->text.slsparamList,buffer);
			}
			if (SLS_COLOR_NOT_USED == list->text.color)
            {
              	if(list->text.slsparamList == NULL)
                {
					strcat(*buffer, SLS_TEXT_T5);
				}
				else
				{
					strcat(*buffer, SLS_PARAM_TEXT_END_QUOTE);
				}
            }
            else
            {
                if(list->text.slsparamList == NULL)
                {
					strcat(*buffer, SLS_TEXT_T6);
				}
                sls_itoacol(list->text.color, tmpStrIntsz);
                sprintf(tmp, SLS_TEXT_T4, tmpStrIntsz);
                strcat(*buffer, tmp);
            }
		}        
		if (list->image.type != SLS_NOT_USED)
        {
            sprintf(tmp, SLS_IMAGE_T1, list->image.src, list->image.region);
            strcat(*buffer, tmp);
            //* begin time 
            if (0 != list->image.beginT)
            {
                sprintf(tmp, SLS_IMAGE_T2, list->image.beginT);
                strcat(*buffer, tmp);
            }
            if (0 != list->image.endT)
            {
                sprintf(tmp, SLS_IMAGE_T3, list->image.endT);
                strcat(*buffer, tmp);
            }
            //* Append the end tag 
			if(list->image.slsparamList == NULL)
			{
				strcat(*buffer, SLS_IMAGE_T4);
			}
			else
			{
				strcat(*buffer, SLS_PARAM_CLOSE);
				smilconcatParamList(list->image.slsparamList,buffer);
				strcat(*buffer, SLS_PARAM_IMAGE_END_QUOTE);
			}
		}
        if (list->audio.type != SLS_NOT_USED)
        {
            sprintf(tmp, SLS_AUDIO_T1, list->audio.src);
            strcat(*buffer, tmp);
          //* begin time 
            if (0 != list->audio.beginT)
            {
                sprintf(tmp, SLS_AUDIO_T2, list->audio.beginT);
                strcat(*buffer, tmp);
            }
          //* End time 
            if (0 != list->audio.endT)
            {
                sprintf(tmp, SLS_AUDIO_T3, list->audio.endT);
                strcat(*buffer, tmp);
            }
            //* Append the end tag 
			if(list->audio.slsparamList == NULL)
			{
				strcat(*buffer, SLS_AUDIO_T4);
			}
			else
			{
				strcat(*buffer, SLS_PARAM_CLOSE);
				smilconcatParamList(list->audio.slsparamList,buffer);
				strcat(*buffer, SLS_PARAM_AUDIO_END_QUOTE);
			}
		}
		if (list->video.type != SLS_NOT_USED)
        {
            sprintf(tmp, SLS_VIDEO_T1, list->video.src, list->video.region);
            strcat(*buffer, tmp);
          
            if (0 != list->video.beginT)
            {
                sprintf(tmp, SLS_VIDEO_T2, list->video.beginT);
                strcat(*buffer, tmp);
            }
          
            if (0 != list->video.endT)
            {
                sprintf(tmp, SLS_VIDEO_T3, list->video.endT);
                strcat(*buffer, tmp);
            }
            
			if(list->video.slsparamList == NULL)
			{
				strcat(*buffer, SLS_VIDEO_T4);
			}
			else
			{
				strcat(*buffer, SLS_PARAM_CLOSE);
				smilconcatParamList(list->video.slsparamList,buffer);
				strcat(*buffer, SLS_PARAM_VIDEO_END_QUOTE);
			}
		}
		smilAddRefItemList(list->refList,buffer);
        strcat(*buffer, SLS_PAR_END);
        list = list->next;
		slideCnt++;
    }

    strcat(*buffer, SLS_BODY_END);
    strcat(*buffer, SLS_SMIL_END);

   
    result = mma_smil_cancelCreateSmil(modId, handle);


    return result;
}




mma_result_enum mma_smil_cancelCreateSmil(MSF_UINT8 modId, 
                               const SlsCreateSmilHandle *handle)
{
    SlsSlideList *list;
    SlsRegionListNode *nodeP;
    SlsCreateSmilData *p = (SlsCreateSmilData*)*handle;



    /* Clean up data */
    if (p->rootLayout)
    {
        MSF_MEM_FREE(modId, p->rootLayout);
    }

    while (p->regionList)
    {
        nodeP = p->regionList->next;
        MSF_MEM_FREE(modId, p->regionList->name);
        MSF_MEM_FREE(modId, p->regionList);
        p->regionList = nodeP;
    }
    
    while (p->slideList)
    {
        list = p->slideList->next;
        if (p->slideList->text.type !=  SLS_NOT_USED)
        {
            MSF_MEM_FREE(modId, p->slideList->text.src);
            MSF_MEM_FREE(modId, p->slideList->text.region);
        }
        if (p->slideList->image.type !=  SLS_NOT_USED)
        {
            MSF_MEM_FREE(modId, p->slideList->image.src);
            MSF_MEM_FREE(modId, p->slideList->image.region);
        }
        if (p->slideList->audio.type !=  SLS_NOT_USED)
        {
            MSF_MEM_FREE(modId, p->slideList->audio.src);
        }

        MSF_MEM_FREE(modId, p->slideList);
        p->slideList = list;
    }
    
    MSF_MEM_FREE(modId, p);


    
    return MMA_RESULT_OK;
}




void smilAddRefItemList(SlsMediaObject  *list,char **Buff)
{
	char tmp[256+271]; 

	while(list != NULL)
	{
		 sprintf(tmp, SLS_REF_T1, list->src);
            strcat(*Buff, tmp);
            /* begin time */
            if (0 != list->beginT)
            {
                sprintf(tmp, SLS_REF_T2, list->beginT);
                strcat(*Buff, tmp);
            }
            /* End time */
            if (0 != list->endT)
            {
                sprintf(tmp, SLS_REF_T3, list->endT);
                strcat(*Buff, tmp);
            }
            /* Append the end tag */
			if(list->slsparamList == NULL)
			{
				strcat(*Buff, SLS_REF_T4);
			}
			else
			{
				strcat(*Buff, SLS_PARAM_CLOSE);
				smilconcatParamList(list->slsparamList,Buff);
				strcat(*Buff, SLS_PARAM_REF_END_QUOTE);
			}
		list = list->next;
	}
}	
#endif /* defined(MMS_SUPPORT) */
#endif /* _MMA_CREATE_C */