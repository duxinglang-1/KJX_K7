#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_cmn.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code for common functionlity.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include <stdlib.h>

#include "bam_cmn.h"
#include "bam_main.h"
#include "bam_win.h"

#include "msf_chrt.h"
#include "msf_core.h"
#include "msf_log.h"
#include "msf_wid.h"

/************************************************************
 * Type definitions
 ************************************************************/

/************************************************************
 * Global variables
 ************************************************************/
static long int bam_cmn_handle;

/************************************************************
 * Function declarations
 ************************************************************/

/************************************************************
 * Functions
 ************************************************************/


/*****************************************************************************
 * FUNCTION
 *  bam_cmn_init
 * DESCRIPTION
 *  Initialize current address and homepage.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_cmn_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bam_cmn_handle = 1;
}


/*****************************************************************************
 * FUNCTION
 *  bam_widget_create_screen
 * DESCRIPTION
 *  This function create and initializes a MSF Screen, which the BAM uses to
 *  display menus and content.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void bam_widget_create_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfScreenHandle screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen = MSF_WIDGET_SCREEN_CREATE(MSF_MODID_BAM,0, 0);

    if (screen == 0)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_BAM, BAM_CMN_D4871623DC8427ADC571E10B0C9084BC,
                         "BAM: Create screen failed\n"));
    }
    else
    {
        bam_win_init(screen);
    }
//#endif
}


/*****************************************************************************
 * FUNCTION
 *  bam_cmn_new_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
long int bam_cmn_new_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bam_cmn_handle++;
}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  bam_cmn_remove_trailing_space
 * DESCRIPTION
 *  Remove the trailing_spaces of the input string.
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *bam_cmn_remove_trailing_space(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return 0;
    }

    len = msf_cmmn_skip_trailing_blanks(str, strlen(str));
    return msf_cmmn_strndup(MSF_MODID_BAM, str, len);
}

#endif 
/*****************************************************************************
 * FUNCTION
 *  bam_cmn_set_bits
 * DESCRIPTION
 *  Treat the "data" as an unsigned array of bits, most significant bit
 *  first, and set the indicated bit range to the given value.  "num_of_bits"
 *  must not be larger than 32.  The value must fit in that number of bits.
 * PARAMETERS
 *  data        [OUT]       The target array of bits
 *  num_of_bits     [IN]        Must not be larger than 32
 *  value       [IN]        The value to be set into the target array
 * RETURNS
 *  void
 *****************************************************************************/
void bam_cmn_set_bits(MSF_INT8 *data, MSF_UINT32 num_of_bits, MSF_UINT32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 bit_position;
	MSF_UINT8 *userdata = (MSF_UINT8 *)data;
    long position;
    unsigned long masking;
    int shiftingwidth;
    int tot_bits;
    int con;
	int octet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    masking = (1 << num_of_bits) - 1;


    bit_position = 0;
    position = 0;
    bit_position = 0;
	octet=8;

    
    if (bit_position + num_of_bits <= octet)
    {
       
        shiftingwidth = octet - (bit_position + num_of_bits);
        
        con = userdata[position] & ~(masking << shiftingwidth);
        con |= value << shiftingwidth;
        userdata[position] = con;
        return;
    }

    
    while (bit_position + num_of_bits > octet)
    {
        
        tot_bits = octet - bit_position;
        
        shiftingwidth = num_of_bits - tot_bits;
        
        masking = (1 << tot_bits) - 1;
       
        con = (value >> shiftingwidth) & masking;
       
        userdata[position] = (unsigned char)((userdata[position] & ~masking) | con);
        num_of_bits -= (octet - bit_position);
        bit_position = 0;
        position++;
    }

   
    masking = (1 << num_of_bits) - 1;
    shiftingwidth = octet - num_of_bits;
    con = userdata[position] & ~(masking << shiftingwidth);
    con |= value << shiftingwidth;
    userdata[position] = con;
}


/*****************************************************************************
 * FUNCTION
 *  bam_cmn_get_bits
 * DESCRIPTION
 *  Treat the "data" as an unsigned array of bits, most significant bit
 *  first, and return the indicated bit range as an integer.  "num_of_bits"
 *  must not be larger than 32.
 * PARAMETERS
 *  data        [IN]        An unsigned array of bits
 *  num_of_bits     [IN]        Must not be larger than 32
 * RETURNS
 *  Return the indicated bit range as an integer.
 *****************************************************************************/
MSF_UINT32 bam_cmn_get_bits(MSF_INT8 *data, MSF_INT32 num_of_bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 bit_position;
	MSF_UINT8 *userdata = (MSF_UINT8 *)data;
    long position;
    long result;
    int masking;
    int shiftingwidth;
	int octet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bit_position = 0;
    position = 0;
    bit_position = 0;
	octet=8;

    masking = -1;

   
    if (bit_position + num_of_bits <= octet)
    {
       
        shiftingwidth = octet - (bit_position + num_of_bits);
        return (userdata[position] >> shiftingwidth) & masking;
    }

    
    result = 0;

    while (bit_position + num_of_bits > octet)
    {
        result = (result << octet) | userdata[position];
        num_of_bits -= (octet - bit_position);
        bit_position = 0;
        position++;
       
    }

    result <<= num_of_bits;
    result |= userdata[position] >> (octet - num_of_bits);
    return result & masking;
}

MSF_UINT8
bam_cmn_get_address (const char *s, unsigned char *addr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int         i, j, len;
	int         tmpaddr[4];
	char        tmp[8];
	const char *q;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (strlen (s) == 0) 
	{
		return 0;
	}
	if (!ct_isdigit (s[0])) 
	{
		return 0;
	}

	for (i = 0; i < 4; i++)
	{
		tmpaddr[i] = 0;
	}

	for (i = 0; i < 4; i++) 
	{
		q = strchr (s, '.');
		if (q == NULL) 
		{
			if (i != 3)
			{
				return 0;
			}
			len = strlen (s);
		}
		else
		{
			len = q - s;
		}
		if ((len == 0) || (len > 3))
		{
			return 0;
		}
		for (j = 0; j < len; j++) 
		{
			if (!ct_isdigit (s[j]))
			{
				return 0;
			}
			tmp[j] = s[j];
		}
		tmp[len] = '\0';
		tmpaddr[i] = atoi (tmp);
		if (tmpaddr[i] > 255)
		{
			return 0;
		}
		if (q != NULL) 
		{
			s = q + 1;
		}
	}

	for (i = 0; i < 4; i++) 
	{
		addr[i] = (MSF_UINT8)tmpaddr[i];
	}

	return 4;
}

#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
void bam_cmn_hold_bearer(MSF_INT32 net_acc_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0    
/* under construction !*/
#endif

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Subcribe MSF_EVNT_NETWORK_BEARER */
 #if 0 
/* under construction !*/
#if 0    
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
}


void bam_cmn_release_bearer(MSF_INT32 net_acc_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Unsubcribe MSF_EVNT_NETWORK_BEARER */
//    MSF_EVNT_UNSUBSCRIBE(MSF_MODID_BAM, BAM_MAIN_REQID_SYSTEM_EVENT_2, MSF_EVNT_NETWORK_BEARER);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
#endif /* recent pages */

#endif /*OBIGO_Q03C_BROWSER*/
