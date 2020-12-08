#ifndef __VAPP_MSG_FEATRUES_H__
#define __VAPP_MSG_FEATRUES_H__

#include "MMI_features.h"

#if defined(__MMI_MMS_SETTING__) &&  (__MMI_MMS_SETTING__ == MMS_SETTING_FULL )     
    #define __MMI_MMS_SETTING_SENDING_VALIDITY__
    #define __MMI_MMS_SETTING_SENDING_PRIORITY__
    #define __MMI_MMS_SETTING_COMPOSE_CREATION__
    #define __MMI_MMS_SETTING_DELIVERY_TIME__

    #define __MMI_MMS_SETTING_COMPOSE_SLIDE__
    #define __MMI_MMS_SETTING_ADVERTISEMENT__
    #define __MMI_MMS_SETTING_ANONYMOUS__
    #define __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__

    #define __MMI_MMS_SETTING_RETRIEVAL_HOME_NETWORK__
    #define __MMI_MMS_SETTING_RETRIEVAL_ROAMING_NETWORK__
    #define __MMI_MMS_SETTING_DATA_ACCOUNT__

    
#elif defined(__MMI_MMS_SETTING__) && (__MMI_MMS_SETTING__ == MMS_SETTING_OMA_ONLY)
    #define __MMI_MMS_SETTING_SENDING_VALIDITY__
    #define __MMI_MMS_SETTING_SENDING_PRIORITY__
    //#define __MMI_MMS_SETTING_COMPOSE_CREATION__
    #define __MMI_MMS_SETTING_DELIVERY_TIME__

    #define __MMI_MMS_SETTING_DATA_ACCOUNT__
#else
    /* turn all mms settng feature OFF */
#endif

#if ((defined(__MMI_MMS_SETTING__) && (__MMI_MMS_SETTING__ == MMS_SETTING_FULL || __MMI_MMS_SETTING__ == MMS_SETTING_OMA_ONLY)) || \
    !defined (__COSMOS_NO_USER_DRIVE__))
    #ifndef __MMI_MMS_SETTING_PAGE__
    #define __MMI_MMS_SETTING_PAGE__
    #endif
#endif

#ifdef __MMI_MESSAGE_SLIM__
    #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
    #define __MMI_MMS_COSMOS_VIDEO_SLIM__
    #endif
#endif

#if (!defined (__MMI_SMS_SLIM__))
	#ifndef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
	#define __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
	#endif
	#ifndef __MMI_SMS_MESSAGE_TYPE_SUPPORT__
	#define __MMI_SMS_MESSAGE_TYPE_SUPPORT__
	#endif
	#ifndef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
	#define __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
	#endif	     
#endif /* __MMI_SMS_SLIM__ */

#endif /* __VAPP_MSG_FEATRUES_H__ */
