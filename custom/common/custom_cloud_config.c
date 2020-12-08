#include "MMI_features.h"

#ifdef __MMI_SSO__
#include "custom_cloud_config.h"

kal_bool custom_cloud_using_card_memory(void)
{
    return KAL_TRUE;
}
#endif