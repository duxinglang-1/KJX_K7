/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * custom_config_account.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to configure data account.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TCPIP__

#include "custom_config_account.h"
#include "custom_data_account.h"

#include "kal_general_types.h"

#ifndef __DA_MEMORY_CUT__
#if defined(__DA_SMART_SELECTION_SUPPORT__)
#ifdef __MMI_GPRS_FEATURES__
static const custom_dtcnt_prof_gprs_struct g_config_account_gprs[] = 
{    
    /* CMCC CMWAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile WAP", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 

    /* CMCC CMNET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile Internet", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"cmnet"
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 
    
    /* CMCC DM */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_DM_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China DM", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_DM, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"cmwap"
    },

    /* CHT GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT WAP", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"emome"
    },

    /* CHT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT MMS", /* Account Name */
            "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"emome"
    },

    /* CHT INTERNET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT Internet", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"internet"
    },

    /* AIRTEL GPRS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel", /* Account Name */
            "http://www.google.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "202.56.231.117", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelgprs.com"
    },

    /* AIRTEL GPRS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel WAP", /* Account Name */
            "http://www.google.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "202.56.231.117", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelgprs.com"
    },

    /* AIRTEL MMS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel MMS", /* Account Name */
            "http://100.1.201.171:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            "100.1.201.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelmms.com"
    },
#ifndef __SLIM_NWK_PROFILE__
    /* AIRTEL MMS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel WAP MMS", /* Account Name */
            "http://100.1.201.171:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "100.1.201.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelmms.com"
    },
    
    /* HUTCH GPRS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch", /* Account Name */
            "http://www.hutchworld.co.in", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            9401, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },    


    /* HUTCH GPRS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch WAP", /* Account Name */
            "http://www.hutchworld.co.in", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },


    /* HUTCH MMS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch MMS", /* Account Name */
            "http://mms1.live.vodafone.in/mms/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            9401, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },
    
    /* HUTCH MMS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch WAP MMS", /* Account Name */
            "http://mms1.live.vodafone.in/mms/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS | DTCNT_APPTYPE_MRE_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },
#endif
    /* OGDR IMPS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"OrangeWorld", /* Account Name */
            "http://www.orange.fr", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "orange", "orange"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "192.168.10.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_IMPS, /* app type */
            "20801" /* SIM ID */
        },

        (const kal_uint8*)"orange"
    },

    /* CU GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom WAP", /* Account Name */
            "http://wap.uni-info.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46001" /* SIM ID */
        },

        (const kal_uint8*)"uniwap"
    },
    
    /* CU MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom MMS", /* Account Name */
            "http://mmsc.myuni.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46001" /* SIM ID */
        },

        (const kal_uint8*)"uniwap"
    },

    /* CU Uninet */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom Uninet", /* Account Name */
            "http://wap.uni-info.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            0, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46001" /* SIM ID */
        },
        (const kal_uint8*)"uninet"
    },

    /* FET GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET", /* Account Name */
            "http://mobile.fetnet.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"fetnet01"
    },

    /* FET GPRS 2*/
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET GPRS", /* Account Name */
            "http://www.myfetbravo.com.tw", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"internet"
    },

    /* FET MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"fetnet01"
    },
    
    /* TWN GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN", /* Account Name */
            "http://ewap", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            0, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_DEF | DTCNT_APPTYPE_PUSH, /* app type */
            "46697" /* SIM ID */
        },

        (const kal_uint8*)"internet"
    },

    /* TWN MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46697" /* SIM ID */
        },
        (const kal_uint8*)"mms"
    },
    
    /* for KGT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"KGT MMS", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46688" /* SIM ID */
        },

        (const kal_uint8*)"kgtmms"
    },

    /* for TAT GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TAT", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_NONE, /* app type */
            "46699" /* SIM ID */
        },
        (const kal_uint8*)"hank"
    }
};
#endif

#ifdef __TCPIP_OVER_CSD__
static const custom_dtcnt_prof_csd_struct g_config_account_csd[] = 
{
    /* CMCC WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CHT WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT CSD", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* CHT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT CSD MMS", /* Account Name */
            "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* FET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET CSD", /* Account Name */
            "http://mobile.fetnet.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* FET MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET CSD MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN CSD", /* Account Name */
            "http://ewap", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN CSD MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* TAT */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TAT CSD", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_NONE, /* app type */
            "46699" /* SIM ID */
        },
        
        (const kal_uint8*)"0931777777",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    }                
};
#endif

#else /* __DA_SMART_SELECTION_SUPPORT__ */

#ifdef __MMI_GPRS_FEATURES__
static const custom_dtcnt_prof_gprs_struct g_config_account_gprs[1];
#if 0 /* comment predefined account */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __TCPIP_OVER_CSD__
static const custom_dtcnt_prof_csd_struct g_config_account_csd[1];
#if 0 /* comment predefined account */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif /* __DA_SMART_SELECTION_SUPPORT__ */

#define CUSTOM_TABLE_SIZE(a)    sizeof(a)/sizeof(a[0])


/*****************************************************************************
 * FUNCTION
 *  custom_config_get_gprs_account
 * DESCRIPTION
 *  get gprs bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_gprs_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    static kal_int32 gprs_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_gprs);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    if (gprs_num < max_size)
    {
        return (void*)&g_config_account_gprs[gprs_num++];
    }
    gprs_num = 0;
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  custom_config_get_csd_account
 * DESCRIPTION
 *  get csd bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_csd_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP_OVER_CSD__
    static kal_int32 csd_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_csd);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP_OVER_CSD__   
    if (csd_num < max_size)
    {
        return (void*)&g_config_account_csd[csd_num++];
    }
    csd_num = 0;
#endif    
    return NULL;    
}


#endif  //__DA_MEMORY_CUT__

/*****************************************************************************
 * FUNCTION
 *  custom_config_get_account
 * DESCRIPTION
 *  get bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
void *custom_config_get_account(kal_int32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DA_MEMORY_CUT__
    return NULL;
#else
    if (type == CUSTOM_DATA_ACCOUNT_BEARER_GPRS)
    {
        return custom_config_get_gprs_account();
    }

    return custom_config_get_csd_account();
#endif
}

#endif /* __TCPIP__ */ 



