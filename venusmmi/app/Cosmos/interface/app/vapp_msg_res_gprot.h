#ifndef __VAPP_MSG_RES_GPROT_H__
#define __VAPP_MSG_RES_GPROT_H__

#include "mmi_features.h"
#include "custresdef.h"

#if defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)
    #define MSG_HEAP_SIZE (400*1024)
#else
    #if !defined(__LOW_COST_SUPPORT_COMMON__) && defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)
        #define MSG_HEAP_SIZE (600*1024)
    #else
        #define MSG_HEAP_SIZE (500*1024)
    #endif
#endif

#endif /*__VAPP_MSG_RES_GPROT_H__*/