#ifndef _VAPP_MOVIE_THEATER_GPROT_H_
#define _VAPP_MOVIE_THEATER_GPROT_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include "gdi_include.h"
#include "MotSrvGprot.h"

#if defined(__MMI_MAINLCD_480X800__)
    #define VAPP_MOVIE_THEATER_CACHE_SIZE 20
#elif defined(__MMI_MAINLCD_320X480__)
    #define VAPP_MOVIE_THEATER_CACHE_SIZE 15
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define VAPP_MOVIE_THEATER_CACHE_SIZE 12
#else
    #define VAPP_MOVIE_THEATER_CACHE_SIZE 12
#endif

#define VAPP_MOVIE_THEATER_THUMBNAIL_RES_SIZE (SRV_MOT_THUMBNAIL_SIZE + 8)

/*****************************************************************************
 * Memory configurations
 *****************************************************************************/
#define VAPP_MOVIE_THEATER_INDEX_FG_MEM (0)
#define VAPP_MOVIE_THEATER_CATEGORY_FG_MEM (VAPP_MOVIE_THEATER_CACHE_SIZE * SRV_MOT_THUMBNAIL_SIZE)
#define VAPP_MOVIE_THEATER_DETAIL_FG_MEM (VAPP_MOVIE_THEATER_THUMBNAIL_RES_SIZE)


/*****************************************************************************
 * Launch functions
 *****************************************************************************/

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _VAPP_MOVIE_THEATER_GPROT_H_ */
