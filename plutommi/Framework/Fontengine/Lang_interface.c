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

/*******************************************************************************
* Filename:
* ---------
*  FontRes.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*  
*
*/
/**************************************************************
FILENAME	: Lang_interface.c
PURPOSE		: interface to lang details
REMARKS		: nil
AUTHOR		: 
DATE		: .
**************************************************************/

#include "fontres.h"
#include "string.h"
#include "lang_interface.h"

extern U16 gMaxDeployedLangs;
extern sLanguageDetails* gLanguageArray;
extern U16 gCurrLangIndex;
extern sFontFamily pluto_en_standardFamily;
extern U8 gLanguageMappingArray[];
#define  MAX_LANGUAGES     30


U8 g_name_undefined[] ={(char)0x55,(char)0x00,(char)0x6e,(char)0x00,(char)0x64,(char)0x00,(char)0x65,(char)0x00,(char)0x66,(char)0x00,(char)0x69,(char)0x00,(char)0x6e,(char)0x00,(char)0x65,(char)0x00,(char)0x64,(char)0x00,(char)0x00};



/*****************************************************************************
* FUNCTION
*  mmi_li_get_lcc
* DESCRIPTION
*  To get lcc code respective to iso code..
* PARAMETERS
*  iso            [IN]        
*  lcc        [OUT]        
* RETURNS
*  void
*****************************************************************************/
void mmi_li_get_lcc(U32 iso,U8 * * lcc)
{
	U8 temp[4];
	U8 count=0;
	U8 max_langs = gMaxDeployedLangs;


	while(count<3)
	{
		temp[count]=(iso&0xff);
		iso=iso>>8;
		count++;
	}
	temp[3]='\0';

	count=0;

	while(count<max_langs)
	{
		if((char *)strcmp((char *)gLanguageArray[count].aLangIsoCode, (char *)temp)==0)
		{
         *lcc = gLanguageArray[count].aLangCountryCode;
		return;}
		else
			count++;
	}

}


/*****************************************************************************
* FUNCTION
*  mmi_li_Get_Current_LCC
* DESCRIPTION
*  To get the current lcc code.
* PARAMETERS
*  lcc            [OUT]        
* RETURNS
*  
*****************************************************************************/
void mmi_li_Get_Current_LCC(U8 * * lcc)
{
    *lcc = gLanguageArray[gCurrLangIndex].aLangCountryCode;
	return;
}

/*****************************************************************************
* FUNCTION
*  mmi_li_get_lang_name
* DESCRIPTION
*  To get string name of the language corresponding to iso code.
* PARAMETERS
*  iso            [IN]        
*  name        [OUT]        
* RETURNS
*  
*****************************************************************************/
void mmi_li_get_lang_name(U32 iso,U8 * * name)
{

	U8 temp[4];
	U8 count=0;
	U8 max_langs = gMaxDeployedLangs;


	while(count<3)
	{
		temp[count]=(iso&0xff);
		iso=iso>>8;
		count++;
	}
	temp[3]='\0';
	
	if(strcmp((char *)temp, "und")==0)
		{
			*name = g_name_undefined;
			return;
		}

	count=0;

	while(count<max_langs)
	{
		if(strcmp((char *)gLanguageArray[count].aLangIsoCode, (char *)temp)==0)
		{
			if(strcmp((char *)temp, "chi")==0)
			{
				*name = gLanguageArray[count].aName+4;
			}
		  else
			{
        *name = gLanguageArray[count].aName;
			}
		return;
		}
		else
			count++;
	}
}

U32 mmi_li_is_lcc_supported(U32 iso)
{
	U8 temp[4];
	U8 count=0;
	U8 max_langs = gMaxDeployedLangs;


	while(count<3)
	{
		temp[count]=(iso&0xff);
		iso=iso>>8;
		count++;
	}
	temp[3]='\0';
	if(strcmp((char *)temp, "und")==0)
		return 1;

	count=0;

	while(count<max_langs)
	{
		if(strcmp((char *)gLanguageArray[count].aLangIsoCode, (char *)temp)==0 && gLanguageMappingArray[count])
				return 1;
		else
			count++;
	}
	return 0;
}
void mmi_li_get_ssc_by_lcc(const U8 *lcc, U8 **ssc)
{
    U8 count=0;
    
    while(count<gMaxDeployedLangs)
    {
        if(strcmp((char *)gLanguageArray[count].aLangCountryCode, (char *)lcc)==0)
        {
            *ssc = gLanguageArray[count].aLangSSC;
            return;
        }
        else
            count++;
    }
}

void mmi_li_get_ssc_by_langname(const U8 *langname, U8 **ssc)
{
    U8 count=0;
    
    while(count<gMaxDeployedLangs)
    {
        if(strcmp((char *)gLanguageArray[count].aName, (char *)langname)==0)
        {
            *ssc = gLanguageArray[count].aLangSSC;
            return;
        }
        else
            count++;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_lang_support
* DESCRIPTION
*  To get the current lcc code.
* PARAMETERS
*  ssc            [in]        
* RETURNS
*  
*****************************************************************************/
S16 mmi_lang_support(const U8 *ssc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(ssc)
    {
        for(i=0; i<gMaxDeployedLangs; i++)
        {
            if(!strcmp((char *)gLanguageArray[i].aLangSSC, (char *)ssc) && gLanguageMappingArray[i])
                return i;
        }
    }
    return -1;
}
