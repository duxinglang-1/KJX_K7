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
 * Res_PhoneSeetting.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "SettingResDef.h"
#include "WallpaperResDef.h"
#include "mmi_phnset_dispchar.h"
#include "ScreenSaverDefs.h"
#include "PowerOnOffDisplayDefs.h"
#include "PhoneSetupResList.h"

#include <dirent.h>
//#include "GlobalDefs.h"

#include "PopulateRes.h"  /* for PopulateThemes() */
//#include "ScheduledPowerOnOffResDef.h"


#define ISCATEGORY(x) (category & (1 << x))


FILE *res_log;  /* for log */

void PopulateDisplayChar(void);



/*****************************************************************************
 * FUNCTION
 *  PopulatePhoneSettingSpecialRes
 * DESCRIPTION
 *  mainly for autogen resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/


void PopulatePhoneSettingSpecialRes(void)

{

#ifdef __MMI_MOTION_MAINMENU__
    {
        int i = 0;
        int mainmenu_position = sizeof(CUST_IMG_PATH "\\\\MainLCD\\\\SWFlash\\\\MAINMENU_TOUCH_");
        char mainmenu_path[] = CUST_IMG_PATH "\\\\MainLCD\\\\SWFlash\\\\MAINMENU_TOUCH_01.vis";

        for (i = 0; i < PHNSET_MOTION_MAINMENU_NUM; i++)
        {
            mainmenu_path[mainmenu_position] = '1' + i;
            ADD_APPLICATION_IMAGE3((IMG_ID_SWFLASH_MAINMENU1 + i), mainmenu_path, "SWFlash category 9 - need dl.");
        }
    }
#endif /* __MMI_MOTION_MAINMENU__ */

#ifdef __MMI_MOTION_DIAL__
    {
        int i = 0;
        int dialer_position = sizeof(CUST_IMG_PATH"\\\\MainLCD\\\\SWFlash\\\\DIALER_");
        char dialer_path[] = CUST_IMG_PATH"\\\\MainLCD\\\\SWFlash\\\\DIALER_01.vis";
        
        for (i = 0; i < PHNSET_MOTION_DIAL_NUM; i++)
        {
            dialer_path[dialer_position] = '1' + i;
            ADD_APPLICATION_IMAGE3((IMG_ID_SWFLASH_DIALER1 + i), dialer_path, "SWFlash category 9 - need dl.");
        }
    }
#endif /* __MMI_MOTION_DIAL__ */  

    PopulateDisplayChar();

}


/*****************************************************************************
 * FUNCTION
 *  AutoGenDispCharRes
 * DESCRIPTION
 *  Automatically generate all display char. resources.
 * PARAMETERS
 *  void
 * RETURNS
 *  True: success; False: can't open the folder of all images
 *****************************************************************************/
#ifndef LOW_COST_SUPPORT
MMI_BOOL AutoGenDispCharRes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, category;
    int wpCount = 0, subCount = 0, ssCountImg = 0, ssCountVdo = 0;
    int onCountImg = 0, onCountVdo = 0, offCountImg = 0, offCountVdo = 0;
    int analogExist = 0, digitExist = 0, themeExit = 0, swflashCount = 0;

    int wpStart = IMG_WALLPAPER_START;
    int subStart = IMG_WALLPAPER_START + MMI_MAX_DISPCHAR_IMG;
    int ssStartImg = IMG_SCREENSAVER_START;
    int ssStartVdo = IMG_SCREENSAVER_START + MMI_MAX_DISPCHAR_IMG;
    int onStartImg = IMG_ID_PHNSET_ON_OFF_START;
    int onStartVdo = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM;
    int offStartImg = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM + MMI_MAX_DISPCHAR_VDO;
    int offStartVdo = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM*2 + MMI_MAX_DISPCHAR_VDO;
    int otherStart = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM*2 + MMI_MAX_DISPCHAR_VDO*2;
    int swflashStart = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM*3 + MMI_MAX_DISPCHAR_VDO*2;

    char *wpStr;
    char *subStr;
    char *ssStrImg;
    char *ssStrVdo;
    char *onStrImg;
    char *onStrVdo;
    char *offStrImg;
    char *offStrVdo;
    char tmpPath[FILENAME_MAX], id_to_str[150];
    #if 0
/* under construction !*/
    #endif
    PHNSET_TYPE_DISP fileType;
    DIR *dir;
    struct dirent *ent;
    FILE *targetHeader;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if 0
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

    if ((dir = opendir(CUST_IMG_PATH "\\\\DispChar")) == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        char *dispStr[MMI_PHNSET_TYPE_MAX + 3]; /* 3 = on + off + ss vdo */
        fprintf(res_log, "\n\nSuccess to open the directory: %s\n", CUST_IMG_PATH "\\\\DispChar");

        targetHeader = fopen("..\\..\\MMI\\Setting\\SettingInc\\PhoneSetupResList.h", "w+");
    #ifdef __MMI_ANALOG_CLOCK__
        fprintf(res_log, "__MMI_ANALOG_CLOCK__\n");
    #endif 
    #ifdef __MMI_DIGITAL_CLOCK__
        fprintf(res_log, "__MMI_DIGITAL_CLOCK__\n");
    #endif 
    #ifdef __MMI_THEMES_V2_SUPPORT__
        fprintf(res_log, "__MMI_THEMES_V2_SUPPORT__\n");
    #endif 
    #ifdef __MMI_SUB_WALLPAPER__
        fprintf(res_log, "__MMI_SUB_WALLPAPER__\n");
    #endif 
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        fprintf(res_log, "__MMI_POWER_ON_OFF_DISPLAY__\n");
    #endif 
    #ifdef __MMI_VIDEO_PLAYER__
        fprintf(res_log, "__MMI_VIDEO_PLAYER__\n");
    #endif 
    #if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
        fprintf(res_log, "__MMI_VIDEO_RECORDER__\n");
    #endif 
    #ifdef __MMI_SCREENSAVER_DISPLAY_VIDEO__
        fprintf(res_log, "__MMI_SCREENSAVER_DISPLAY_VIDEO__\n");
    #endif 
    #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
        fprintf(res_log, "__MMI_POWER_ON_OFF_DISPLAY_VIDEO__\n");
    #endif 
    #ifdef __MMI_SWFLASH__
        fprintf(res_log, "__MMI_SWFLASH__\n");
    #endif 
    #ifdef SVG_SUPPORT
        fprintf(res_log, "SVG_SUPPORT\n");
    #endif 

        /* Allocate Output Buffer for PhoneSetupResList.h */
        for(i = 0; i < (MMI_PHNSET_TYPE_MAX + 3); i++)
        {
            dispStr[i] = (char *) malloc(600);
        }
        wpStr =     dispStr[MMI_PHNSET_TYPE_WP];
        sprintf(wpStr, "    IMG_ID_PHNSET_WP_START = IMG_WALLPAPER_START,\n");

    #ifdef __MMI_SUB_WALLPAPER__
        subStr =    dispStr[MMI_PHNSET_TYPE_SUB_WP];
        sprintf(subStr, "    IMG_ID_PHNSET_SUB_WP_START = IMG_WALLPAPER_START + MMI_MAX_DISPCHAR_IMG,\n");
    #endif
    
        ssStrImg =  dispStr[MMI_PHNSET_TYPE_SS];
        sprintf(ssStrImg, "    IMG_ID_PHNSET_SS_START = IMG_SCREENSAVER_START,\n");
        
        ssStrVdo =  dispStr[MMI_PHNSET_TYPE_MAX + 0];
        sprintf(ssStrVdo, "    IMG_ID_PHNSET_SS_VDO_START = IMG_SCREENSAVER_START + MMI_MAX_DISPCHAR_IMG,\n");

    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        onStrImg =  dispStr[MMI_PHNSET_TYPE_PWRON];
        sprintf(onStrImg, "    IMG_ID_PHNSET_ON_START = IMG_ID_PHNSET_ON_OFF_START,\n");
        
        onStrVdo =  dispStr[MMI_PHNSET_TYPE_MAX + 1];
        sprintf(onStrVdo, "    IMG_ID_PHNSET_ON_VDO_START = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM,\n");

        offStrImg = dispStr[MMI_PHNSET_TYPE_PWROFF];
        sprintf(offStrImg, "    IMG_ID_PHNSET_OFF_START = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM + MMI_MAX_DISPCHAR_VDO,\n");

        offStrVdo = dispStr[MMI_PHNSET_TYPE_MAX + 2];
        sprintf(offStrVdo, "    IMG_ID_PHNSET_OFF_VDO_START = IMG_ID_PHNSET_ON_OFF_START + MMI_MAX_DISPCHAR_ANM + MMI_MAX_DISPCHAR_VDO + MMI_MAX_DISPCHAR_ANM,\n");
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */

        while ((ent = readdir(dir)) != NULL)
        {
            category = 0;
            fprintf(res_log, "Process file: %s\n", ent->d_name);

            for (i = 0; i < FILENAME_MAX; i++)
            {
                tmpPath[i] = toupper(ent->d_name[i]);
            }

            if (!strcmp(tmpPath, ".") || !strcmp(tmpPath, ".."))
            {
                continue;
            }

            /* Determain dispchar type */
            for(i = 0; i < MMI_PHNSET_TYPE_MAX; i++)
            {
                if(strstr(tmpPath, "WP"))
                {
                #ifdef __MMI_RES_TYPE_WALLPAPER__
                    if(strstr(tmpPath, __MMI_RES_TYPE_WALLPAPER__))
                #endif
                    {
                    category |= 1 << MMI_PHNSET_TYPE_WP;
                    }
                }
                
            #ifdef __MMI_SUB_WALLPAPER__
                if(strstr(tmpPath, "SUB"))
                {
                #ifdef __MMI_RES_TYPE_SUBLCD_WALLPAPER__
                    if(strstr(tmpPath, __MMI_RES_TYPE_SUBLCD_WALLPAPER__))
                #endif
                    {
                    category |= 1 << MMI_PHNSET_TYPE_SUB_WP;
                    }
                }
            #endif
            
                if(strstr(tmpPath, "SS"))
                {
                #ifdef __MMI_RES_TYPE_WALLPAPER__
                    if(strstr(tmpPath, __MMI_RES_TYPE_WALLPAPER__))
                #endif
                    {
                    category |= 1 << MMI_PHNSET_TYPE_SS;
                    }
                }

            #ifdef __MMI_POWER_ON_OFF_DISPLAY__
                if(strstr(tmpPath, "ON"))
                {
                #ifdef __MMI_RES_TYPE_POWER_ONOFF__
                    if(strstr(tmpPath, __MMI_RES_TYPE_POWER_ONOFF__))
                #endif
                    {
                    category |= 1 << MMI_PHNSET_TYPE_PWRON;
                    }
                }
                
                if(strstr(tmpPath, "OFF"))
                {
                #ifdef __MMI_RES_TYPE_POWER_ONOFF__
                    if(strstr(tmpPath, __MMI_RES_TYPE_POWER_ONOFF__))
                #endif
                    {
                    category |= 1 << MMI_PHNSET_TYPE_PWROFF;
                    }
                }
            #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */
            }
            

            /* Determain media type */
            if (strstr(tmpPath, ".MP4") || strstr(tmpPath, ".AVI"))
            {
                fileType = PHNSET_TYPE_DISP_VIDEO;
                fprintf(res_log, "    Add a Video\n");
            }
            else if (strstr(tmpPath, ".VIS") || strstr(tmpPath, ".CMP") || strstr(tmpPath, ".MSF"))
        #if 0                
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
        #else
            {
                continue;
            }
        #endif
        #if !defined(__M3D_SUPPORT__)
            else if (strstr(tmpPath, ".M3D"))
            {
                continue;
            }
        #endif
        #if !defined(SVG_SUPPORT)
            else if (strstr(tmpPath, ".SVG"))
            {
                continue;
            }
        #endif
        #ifdef __MMI_ANALOG_CLOCK__
            /* generate  analog clock resource */
            else if (strstr(tmpPath, "ANALOG"))
            {
                fprintf(res_log, "    Add Analog Clock\n");
                fprintf(
                    res_log,
                    "                ADD_APPLICATION_IMAGE4(IMG_ID_DISPCHAR_ANALOG_CLK=%d, %s, MB=%d)\n",
                    otherStart + 1,
                    tmpPath,
                    MMI_TRUE);

                ADD_APPLICATION_IMAGE4(
                    otherStart + 1,
                    "IMG_ID_DISPCHAR_ANALOG_CLK",
                    CUST_IMG_PATH "\\\\DispChar\\\\",
                    tmpPath,
                    "Associate to DispChar",
                    MMI_TRUE);
                continue;
            }
        #endif /* __MMI_ANALOG_CLOCK__ */ 
            
        #ifdef __MMI_DIGITAL_CLOCK__
            /* generate  digital clock resource */
            else if (strstr(tmpPath, "DIGITAL"))
            {
                fprintf(res_log, "    Add Digital Clock\n");
                fprintf(
                    res_log,
                    "                ADD_APPLICATION_IMAGE4(IMG_ID_DISPCHAR_DIGITAL_CLK=%d, %s, MB=%d)\n",
                    otherStart + 1,
                    tmpPath,
                    MMI_TRUE);

                ADD_APPLICATION_IMAGE4(
                    otherStart + 1,
                    "IMG_ID_DISPCHAR_DIGITAL_CLK",
                    CUST_IMG_PATH "\\\\DispChar\\\\",
                    tmpPath,
                    "Associate to DispChar",
                    MMI_TRUE);
                continue;

            }
        #endif /* __MMI_DIGITAL_CLOCK__ */ 
            else
            {
                fileType = PHNSET_TYPE_DISP_IMAGE;
                fprintf(res_log, "    Add an image\n");
            }
                

            /* generate wallpaper resource */
            if (fileType == PHNSET_TYPE_DISP_IMAGE && ISCATEGORY(MMI_PHNSET_TYPE_WP))
            {
#if defined __MMI_RES_TYPE_WALLPAPER__
                if (strstr(tmpPath, __MMI_RES_TYPE_WALLPAPER__))
#endif
                {
                /* Current Wallpaper ID */
                int curr_id = wpStart + wpCount;

                /* Turn the image ID into string */
                sprintf(id_to_str, "IMG_ID_PHNSET_WP_%d", wpCount);

                /* log */
                fprintf(res_log, "        Add to wallpaper\n");
                fprintf(
                    res_log,
                    "                ADD_APPLICATION_IMAGE4(%s=%d, %s, MB=%d)\n",
                    id_to_str,
                    curr_id,
                    tmpPath,
                    MMI_TRUE);

                /* Populate the image */
                ADD_APPLICATION_IMAGE4(
                    curr_id,
                    id_to_str,
                    CUST_IMG_PATH "\\\\DispChar\\\\",
                    tmpPath,
                    "Associate to DispChar",
                    MMI_TRUE);

                /* add the string ID associated to the image */
                if(wpCount)
                    sprintf(id_to_str, "    IMG_ID_PHNSET_WP_%d,\n", wpCount);
                else
                    sprintf(id_to_str, "    IMG_ID_PHNSET_WP_%d = IMG_ID_PHNSET_WP_START,\n", wpCount);
                strcat(wpStr, id_to_str);
                
                wpCount++;
                
            }

            }

        #ifdef __MMI_SUB_WALLPAPER__
            /* generate  sub wallpaper resource */
            if (fileType == PHNSET_TYPE_DISP_IMAGE && ISCATEGORY(MMI_PHNSET_TYPE_SUB_WP))
            {
#if defined __MMI_RES_TYPE_SUBLCD_WALLPAPER__
                if (strstr(tmpPath, __MMI_RES_TYPE_SUBLCD_WALLPAPER__))
#endif
                {
                /* Current image ID */
                int curr_id = subStart + subCount;
            
                /* Turn the image ID into string */
                sprintf(id_to_str, "IMG_ID_PHNSET_SUB_WP_%d", subCount);
            
                /* log */
                fprintf(res_log, "        Add to sub-wallpaper\n");
                fprintf(
                    res_log,
                    "                ADD_APPLICATION_IMAGE4(%s=%d, %s, MB=%d)\n",
                    id_to_str,
                    curr_id,
                    tmpPath,
                    MMI_TRUE);
            
                /* Populate the image */
                ADD_APPLICATION_IMAGE4(
                    curr_id,
                    id_to_str,
                    CUST_IMG_PATH "\\\\DispChar\\\\",
                    tmpPath,
                    "Associate to DispChar",
                    MMI_TRUE);
            
                /* add the string ID associated to the image */
                if(subCount)
                    sprintf(id_to_str, "    IMG_ID_PHNSET_SUB_WP_%d,\n", subCount);
                else
                    sprintf(id_to_str, "    IMG_ID_PHNSET_SUB_WP_%d = IMG_ID_PHNSET_SUB_WP_START,\n", subCount);
                strcat(subStr, id_to_str);
                
                subCount++;
                }           
            }
        #endif /* __MMI_SUB_WALLPAPER__ */ 

            /* generate  screen saver resource */
            if (ISCATEGORY(MMI_PHNSET_TYPE_SS))
            {
#if defined __MMI_RES_TYPE_SCREEN_SAVER__
                if (strstr(tmpPath, __MMI_RES_TYPE_SCREEN_SAVER__))
#elif defined __MMI_RES_TYPE_WALLPAPER__
                if (strstr(tmpPath, __MMI_RES_TYPE_WALLPAPER__))
#endif    
                {
                /* Current resource ID */
                int curr_id;
                fprintf(res_log, "        Add to screen saver\n");
    
                if (fileType == PHNSET_TYPE_DISP_IMAGE)
                {
                    curr_id = ssStartImg + ssCountImg;
                    
                    /* Turn the image ID into string */
                    sprintf(id_to_str, "IMG_ID_PHNSET_SS_%d", ssCountImg);
                    fprintf(
                        res_log,
                        "                ADD_APPLICATION_IMAGE4(%s=%d, %s, MB=%d)\n",
                        id_to_str,
                        curr_id,
                        tmpPath,
                        MMI_TRUE);

                    /* Populate the image */
                    ADD_APPLICATION_IMAGE4(
                        curr_id,
                        id_to_str,
                        CUST_IMG_PATH "\\\\DispChar\\\\",
                        tmpPath,
                        "Associate to DispChar",
                        MMI_TRUE);

                    /* add the string ID associated to the image */
                    if(ssCountImg)
                        sprintf(id_to_str, "    IMG_ID_PHNSET_SS_%d,\n", ssCountImg);
                    else
                        sprintf(id_to_str, "    IMG_ID_PHNSET_SS_%d = IMG_ID_PHNSET_SS_START,\n", ssCountImg);

                    strcat(ssStrImg, id_to_str);
                    
                    ssCountImg++;
                }
                else
                {
                    curr_id = ssStartVdo + ssCountVdo;
                    
                    /* Turn the image ID into string */
                    sprintf(id_to_str, "IMG_ID_PHNSET_SS_VDO_%d", ssCountVdo);
                    fprintf(
                        res_log,
                        "                ADD_APPLICATION_MEDIA4(%s=%d, %s, MB=%d)\n",
                        id_to_str,
                        curr_id,
                        tmpPath,
                        MMI_TRUE);

                    /* Populate the image */
                    ADD_APPLICATION_MEDIA4(
                        curr_id,
                        id_to_str,
                        CUST_IMG_PATH "\\\\DispChar\\\\",
                        tmpPath,
                        "Associate to DispChar",
                        MMI_TRUE);

                    /* add the string ID associated to the image */
                    if(ssCountVdo)
                        sprintf(id_to_str, "    IMG_ID_PHNSET_SS_VDO_%d,\n", ssCountVdo);
                    else
                        sprintf(id_to_str, "    IMG_ID_PHNSET_SS_VDO_%d = IMG_ID_PHNSET_SS_VDO_START,\n", ssCountVdo);

                    strcat(ssStrVdo, id_to_str);
                    
                    ssCountVdo++;

                }
                }
            }

            
        #ifdef __MMI_POWER_ON_OFF_DISPLAY__
            /* generate  power on display resource */
            if (ISCATEGORY(MMI_PHNSET_TYPE_PWRON) || ISCATEGORY(MMI_PHNSET_TYPE_PWROFF))
            {
			#if defined __MMI_RES_TYPE_POWER_ONOFF__
                if (strstr(tmpPath, __MMI_RES_TYPE_POWER_ONOFF__))
			#endif
                {
                /* Current resource ID */
                int curr_id, tmpType;
                int *tmpCount = NULL;
                char *tmpStr = NULL;
                char *tmpSuffix[]=
                {
                    "ON\0",      /* 0 */
                    "ON_VDO\0",  /* 1 */
                    "OFF\0",     /* 2 */
                    "OFF_VDO\0", /* 3 */
                    ""
                };
                 
                 if (ISCATEGORY(MMI_PHNSET_TYPE_PWRON))
                 {
                     fprintf(res_log, "        Add to PWR ON display\n");
                     if (fileType == PHNSET_TYPE_DISP_IMAGE)
                     {
                        curr_id = onStartImg + onCountImg;
                        sprintf(id_to_str, "IMG_ID_PHNSET_ON_%d", onCountImg);
                        tmpCount = &onCountImg;
                        tmpStr = onStrImg;
                        tmpType = 0;
                     }
                     else
                     {
                        curr_id = onStartVdo + onCountVdo;
                        sprintf(id_to_str, "IMG_ID_PHNSET_ON_VDO_%d", onCountVdo);
                        tmpCount = &onCountVdo;
                        tmpStr = onStrVdo;
                        tmpType = 1;
                     } 

                     if (fileType == PHNSET_TYPE_DISP_IMAGE)
                     {
                         fprintf(
                             res_log,
                             "                ADD_APPLICATION_IMAGE4(%s=%d, %s, MB=%d)\n",
                             id_to_str,
                             curr_id,
                             tmpPath,
                             MMI_TRUE);
                     
                         /* Populate the image */
                         ADD_APPLICATION_IMAGE4(
                             curr_id,
                             id_to_str,
                             CUST_IMG_PATH "\\\\DispChar\\\\",
                             tmpPath,
                             "Associate to DispChar",
                             MMI_TRUE);
                        
                     }
                     else
                     {
                         fprintf(
                             res_log,
                             "                ADD_APPLICATION_MEDIA4(%s=%d, %s, MB=%d)\n",
                             id_to_str,
                             curr_id,
                             tmpPath,
                             MMI_TRUE);
                     
                         /* Populate the image */
                         ADD_APPLICATION_MEDIA4(
                             curr_id,
                             id_to_str,
                             CUST_IMG_PATH "\\\\DispChar\\\\",
                             tmpPath,
                             "Associate to DispChar",
                             MMI_TRUE);
                     }

                     /* add the string ID associated to the image */
                     if(*tmpCount)
                         sprintf(id_to_str, "    IMG_ID_PHNSET_%s_%d,\n", tmpSuffix[tmpType], *tmpCount);
                     else
                         sprintf(id_to_str, "    IMG_ID_PHNSET_%s_%d = IMG_ID_PHNSET_%s_START,\n", tmpSuffix[tmpType], *tmpCount, tmpSuffix[tmpType]);
                      
                      strcat(tmpStr, id_to_str);
                      (*tmpCount)++;
                     
                 }

                 if (ISCATEGORY(MMI_PHNSET_TYPE_PWROFF))
                 {
                     fprintf(res_log, "        Add to PWR OFF display\n");
                     if (fileType == PHNSET_TYPE_DISP_IMAGE)
                     {
                        curr_id = offStartImg + offCountImg;
                        sprintf(id_to_str, "IMG_ID_PHNSET_OFF_%d", offCountImg);
                        tmpCount = &offCountImg;
                        tmpStr = offStrImg;
                        tmpType = 2;
                     }
                     else
                     {
                        curr_id = onStartVdo + onCountVdo;
                        sprintf(id_to_str, "IMG_ID_PHNSET_OFF_VDO_%d", offCountVdo);
                        tmpCount = &offCountVdo;
                        tmpStr = offStrVdo;
                        tmpType = 3;
                     }  

                     if (fileType == PHNSET_TYPE_DISP_IMAGE)
                     {
                         fprintf(
                             res_log,
                             "                ADD_APPLICATION_IMAGE4(%s=%d, %s, MB=%d)\n",
                             id_to_str,
                             curr_id,
                             tmpPath,
                             MMI_TRUE);
                     
                         /* Populate the image */
                         ADD_APPLICATION_IMAGE4(
                             curr_id,
                             id_to_str,
                             CUST_IMG_PATH "\\\\DispChar\\\\",
                             tmpPath,
                             "Associate to DispChar",
                             MMI_TRUE);
                        
                     }
                     else
                     {
                         fprintf(
                             res_log,
                             "                ADD_APPLICATION_MEDIA4(%s=%d, %s, MB=%d)\n",
                             id_to_str,
                             curr_id,
                             tmpPath,
                             MMI_TRUE);
                     
                         /* Populate the image */
                         ADD_APPLICATION_MEDIA4(
                             curr_id,
                             id_to_str,
                             CUST_IMG_PATH "\\\\DispChar\\\\",
                             tmpPath,
                             "Associate to DispChar",
                             MMI_TRUE);
                         
                     
                     }

                 /* add the string ID associated to the image */
                 if(*tmpCount)
                     sprintf(id_to_str, "    IMG_ID_PHNSET_%s_%d,\n", tmpSuffix[tmpType], *tmpCount);
                 else
                     sprintf(id_to_str, "    IMG_ID_PHNSET_%s_%d = IMG_ID_PHNSET_%s_START,\n", tmpSuffix[tmpType], *tmpCount, tmpSuffix[tmpType]);
                  
                  
                  strcat(tmpStr, id_to_str);
                  (*tmpCount)++;
                     
                 }
                }
            }
        #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

        }

        closedir(dir);
        fprintf(res_log, "Success to generate image/video resource\n");
        fprintf(res_log, "Success to process the directory: %s\n", CUST_IMG_PATH "\\\\DispChar");

        fprintf(targetHeader, \
        "/*****************************************************************************\n"\
        "*  Copyright Statement:\n"\
        "*  --------------------\n"\
        "*  This software is protected by Copyright and the information contained\n"\
        "*  herein is confidential. The software may not be copied and the information\n"\
        "*  contained herein may not be used or disclosed except with the written\n"\
        "*  permission of MediaTek Inc. (C) 2006\n"\
        "*\n"\
        "*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES\n"\
        "*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS (\"MEDIATEK SOFTWARE\")\n"\
        "*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON\n"\
        "*  AN \"AS-IS\" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,\n"\
        "*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF\n"\
        "*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.\n"\
        "*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE\n"\
        "*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR\n"\
        "*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH\n"\
        "*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO\n"\
        "*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S\n"\
        "*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.\n"\
        "*\n"\
        "*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE\n"\
        "*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,\n"\
        "*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,\n"\
        "*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO\n"\
        "*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. \n"\
        "*\n"\
        "*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE\n"\
        "*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF\n"\
        "*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND\n"\
        "*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER\n"\
        "*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).\n"\
        "*\n"\
        "*****************************************************************************/\n"\
        "\n"\
        "/*****************************************************************************\n"\
        " *\n"\
        " * Filename:\n"\
        " * ---------\n"\
        " * PhoneSetupResList.h\n"\
        " *\n"\
        " * Project:\n"\
        " * --------\n"\
        " *   MAUI\n"\
        " *\n"\
        " * Description:\n"\
        " * ------------\n"\
        " *   This file is intends for Resource IDs for the Display Characteristic\n"\
        " *\n"\
        " * Author:\n"\
        " * -------\n"\
        " * Cylen Yao (mtk00911)\n"\
        " *\n"\
        " *============================================================================\n"\
        " *\n"\
        " * This file is automatically generated by the resource gen procedure\n"\
        " *\n"\
        " ****************************************************************************/\n"\
        "#ifndef PHONESETUPRESLIST_H\n"\
        "#define PHONESETUPRESLIST_H\n");
            
        fprintf(targetHeader, "typedef enum\n{\n");
        /* Output wallpaper enum id */
        fprintf(targetHeader, "%s", wpStr);
        fprintf(targetHeader, "    IMG_ID_PHNSET_WP_MAX = IMG_ID_PHNSET_WP_START + __MMI_WALLPAPER_NUM__ - 1,\n\n", wpCount - 1);
    #ifdef __MMI_SUB_WALLPAPER__
        /* Output sub-wallpaper enum id */
        fprintf(targetHeader, "%s", subStr);
        fprintf(targetHeader, "    IMG_ID_PHNSET_SUB_WP_MAX = IMG_ID_PHNSET_SUB_WP_START + __MMI_WALLPAPER_NUM__ - 1,\n\n", subCount - 1);
    #endif /* __MMI_SUB_WALLPAPER__ */
    
        /* Output screensaver enum id */
        /* image */
        fprintf(targetHeader, "%s", ssStrImg);
        fprintf(targetHeader, "    IMG_ID_PHNSET_SS_MAX = IMG_ID_PHNSET_SS_START + __MMI_WALLPAPER_NUM__ - 1,\n\n", ssCountImg - 1);
        /* video */
        fprintf(targetHeader, "%s", ssStrVdo);
        fprintf(targetHeader, "    IMG_ID_PHNSET_SS_VDO_MAX = IMG_ID_PHNSET_SS_VDO_%d,\n\n", ssCountVdo - 1);

        
        fprintf(targetHeader, "#if defined(__MMI_POWER_ON_OFF_DISPLAY__)\n");
        /* Output pwron disp enum id */
        /* image */
        fprintf(targetHeader, "%s", onStrImg);
        fprintf(targetHeader, "    IMG_ID_PHNSET_ON_MAX = IMG_ID_PHNSET_ON_START + __MMI_WALLPAPER_NUM__ - 1,\n\n", onCountImg - 1);
        /* video */
        fprintf(targetHeader, "%s", onStrVdo);
        fprintf(targetHeader, "    IMG_ID_PHNSET_ON_VDO_MAX = IMG_ID_PHNSET_ON_VDO_%d,\n\n", onCountVdo - 1);
        
        /* Output pwroff disp enum id */
        /* image */
        fprintf(targetHeader, "%s", offStrImg);
        fprintf(targetHeader, "    IMG_ID_PHNSET_OFF_MAX = IMG_ID_PHNSET_OFF_START + __MMI_WALLPAPER_NUM__ - 1,\n\n", offCountImg - 1);        
        /* video */
        fprintf(targetHeader, "%s", offStrVdo);
        fprintf(targetHeader, "    IMG_ID_PHNSET_OFF_VDO_MAX = IMG_ID_PHNSET_OFF_VDO_%d,\n\n", offCountVdo - 1);        

        fprintf(targetHeader, "#else /* __MMI_POWER_ON_OFF_DISPLAY__ */\n");

        fprintf(targetHeader, "    IMG_ID_PHNSET_ON_ANIMATION_DEFAULT = IMG_ID_PHNSET_ON_OFF_START,\n");
        fprintf(targetHeader, "    IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,\n");

        fprintf(targetHeader, "#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */\n");

        /* Output other enum id */
        fprintf(targetHeader, ""\    
        "    /* Other images */\n"\
        "    IMG_ID_DISPCHAR_OTHER_START,\n"\
        "#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__\n"\
        "#ifdef __MMI_ANALOG_CLOCK__\n"\
        "    IMG_ID_DISPCHAR_ANALOG_CLK = IMG_ID_DISPCHAR_OTHER_START + 1,\n"\
        "#endif /* __MMI_ANALOG_CLOCK__ */\n"\
        "#ifdef __MMI_DIGITAL_CLOCK__\n"\
        "    IMG_ID_DISPCHAR_DIGITAL_CLK = IMG_ID_DISPCHAR_OTHER_START + 2,\n"\
        "#endif /* __MMI_DIGITAL_CLOCK__ */\n"\
        "#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */\n"\
        "\n"\
        "    IMG_ID_DISPCHAR_THEME_WALLPAPER,\n"\
        "#ifdef __MMI_THEMES_V2_SUPPORT__\n"\
        "    IMG_ID_DISPCHAR_THEME_SCREENSAVER,\n"\
        "#endif \n"\
        "\n"\
        "    IMG_ID_DISPCHAR_OTHER_MAX,\n");


        /* Output SWFlash enum id */
        fprintf(targetHeader, "    IMG_ID_DISPCHAR_SWFLASH_START,\n");
        if(swflashCount)
            fprintf(targetHeader, "    IMG_ID_DISPCHAR_SWFLASH_0 = IMG_ID_DISPCHAR_SWFLASH_START,\n");
        
        for(i = 0; i < swflashCount; i++)
        {
            fprintf(targetHeader, "    IMG_ID_DISPCHAR_SWFLASH_%d,\n", i);    
        }
        
        if(swflashCount)
            fprintf(targetHeader, "    IMG_ID_DISPCHAR_SWFLASH_MAX = IMG_ID_DISPCHAR_SWFLASH_%d,\n", swflashCount -1);
        else
            fprintf(targetHeader, "    IMG_ID_DISPCHAR_SWFLASH_MAX = IMG_ID_DISPCHAR_SWFLASH_START,\n");
        

        fprintf(targetHeader, "    IMG_ID_PHNSET_MAX\n");
        fprintf(targetHeader, "}phnset_dispchar_enum; \n\n");
        fprintf(targetHeader, ""\
        "#ifdef __MMI_SWFLASH__\n"\
        "#define MAX_DISPCHAR_SWFLASH       (IMG_ID_DISPCHAR_SWFLASH_MAX - IMG_ID_DISPCHAR_SWFLASH_START + 1)\n"\
        "#else\n"\
        "#define MAX_DISPCHAR_SWFLASH       0\n"\
        "#endif /* __MMI_FLASH__ */\n"\
        "        \n"\
        "#define MAX_OTHER_WALLPAPER      (IMG_ID_DISPCHAR_OTHER_MAX - IMG_ID_DISPCHAR_OTHER_START -1)\n"\
        "#define MAX_OTHER_SCREENSAVER    MAX_OTHER_WALLPAPER\n"\
        "        \n"\
        "#ifdef __MMI_DISPCHAR_M3D__\n"\
        "#define MAX_WALLPAPER_IMG        (IMG_ID_PHNSET_WP_MAX - IMG_ID_PHNSET_WP_START + 1 + MAX_OTHER_WALLPAPER + MAX_DISPCHAR_SWFLASH + 3)\n"\
        "#else\n"\
        "#define MAX_WALLPAPER_IMG        (IMG_ID_PHNSET_WP_MAX - IMG_ID_PHNSET_WP_START + 1 + MAX_OTHER_WALLPAPER + MAX_DISPCHAR_SWFLASH)\n"\
        "#endif /* __MMI_DISPCHAR_M3D__ */\n"\
        "        \n"\
        "#define MAX_DL_WPSS_NUMBERS      MAXIMUM_DOWNLOAD_IMAGES\n"\
        "#define MAX_SUB_WALLPAPER_IMG    (IMG_ID_PHNSET_SUB_WP_MAX - IMG_ID_PHNSET_SUB_WP_START + 1)\n"\
        "        \n"\
        "#define MAX_SCREENSAVER_IMG      (IMG_ID_PHNSET_SS_MAX - IMG_ID_PHNSET_SS_START + 1 + MAX_OTHER_SCREENSAVER + MAX_DISPCHAR_SWFLASH)\n"\
        "#if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)\n"\
        "#define MAX_SCREENSAVER_VDO      (IMG_ID_PHNSET_SS_VDO_MAX-IMG_ID_PHNSET_SS_VDO_START + 1)\n"\
        "#else \n"\
        "#define MAX_SCREENSAVER_VDO      0\n"\
        "#endif \n"\
        "        \n"\
        "#ifdef __MMI_POWER_ON_OFF_DISPLAY__\n"\
        "#define MAX_POWER_ON_IMG         (IMG_ID_PHNSET_ON_MAX-IMG_ID_PHNSET_ON_START + 1 + MAX_DISPCHAR_SWFLASH)\n"\
        "#if defined(__MMI_POWER_ON_OFF_DISPLAY_VIDEO__) && defined(__MTK_TARGET__)\n"\
        "#define MAX_POWER_ON_VDO         (IMG_ID_PHNSET_ON_VDO_MAX-IMG_ID_PHNSET_ON_VDO_START + 1)\n"\
        "#else \n"\
        "#define MAX_POWER_ON_VDO         0\n"\
        "#endif \n"\
        "#define MAX_POWER_OFF_IMG        MAX_POWER_ON_IMG\n"\
        "#define MAX_POWER_OFF_VDO        MAX_POWER_ON_VDO\n"\
        "#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ \n"\
        "#endif /* PHONESETUPRESLIST_H */ \n");


        fclose(targetHeader);
        /* Free Output Buffer for PhoneSetupResList.h */
        for(i = 0; i < (MMI_PHNSET_TYPE_MAX + 3); i++)
        {
            free(dispStr[i]);
        }

        fprintf(res_log, "Success to generate PhoneSetupResList.h\n");

        return MMI_TRUE;
    }
}
#endif /* LOW_COST_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  PopulateDisplayChar
 * DESCRIPTION
 *  Populate all display char. resources.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateDisplayChar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#ifdef __MMI_THEMES_V2_SUPPORT__
  #ifdef __MMI_RES_TYPE_WALLPAPER__
	ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_THEME_WALLPAPER, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_WALLPAPER__, "wallpaper download");
  #else
	ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_THEME_WALLPAPER, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01.gif", "wallpaper download");
  #endif

  #ifdef __MMI_RES_TYPE_SCREEN_SAVER__
	ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_THEME_SCREENSAVER, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_SCREEN_SAVER__, "wallpaper download");
  #elif defined __MMI_RES_TYPE_WALLPAPER__
	ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_THEME_SCREENSAVER, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01."__MMI_RES_TYPE_WALLPAPER__, "wallpaper download");
  #else
	ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_THEME_SCREENSAVER, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Wallpaper\\\\WALL01.gif", "wallpaper download");
  #endif 
#endif /* __MMI_THEMES_V2_SUPPORT__ */    

#ifdef __PLUTO_MMI_PACKAGE__
  #ifdef __MMI_VUI_SHELL_MULTI_PAGE__
    ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_WP_START, CUST_IMG_PATH "\\\\MainLCD\\\\VUI\\\\Shell\\\\Common\\\\Home_bg.png", "Shell home screen default wallpaper");
  #endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

  #ifdef __MMI_VUI_HOMESCREEN__
    ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_WP_START, 
  				#ifdef __MMI_VUI_HOMESCREEN_LITE_DISPLAY__
					CUST_IMG_PATH "\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Venus_wall01.bmp",
  				#else
        			CUST_IMG_PATH "\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Venus_wall01.jpg",
  				#endif /* __MMI_VUI_HOMESCREEN_LITE_DISPLAY__ */
        			"VENUS UI idle default wallpaper");
  #endif /* __MMI_VUI_HOMESCREEN__ */
#endif

	if (!res_log)
    {
        res_log = fopen("PhnsetAutoGen.log", "w+");
    }

#ifndef LOW_COST_SUPPORT
    if (!AutoGenDispCharRes())
#endif
    {
    #if defined(__MMI_DISPCHAR_M3D__)
        int max_m3d = 3;
    #else 
        int max_m3d = 0;
    #endif 
    	int j = 0;

        fprintf(res_log, "Can't open the directory: %s\n", CUST_IMG_PATH "\\\\DispChar");

        /* Generate Wallpaper Images */
    #ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
     #ifdef __MMI_ANALOG_CLOCK__
        fprintf(
            res_log,
            "                ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_ANALOG_CLK=%d, path=%s)\n",
            IMG_ID_DISPCHAR_ANALOG_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\analog."__MMI_RES_TYPE_WALLPAPER__);
      #ifdef __MMI_RES_TYPE_WALLPAPER__
        ADD_APPLICATION_IMAGE3(
            IMG_ID_DISPCHAR_ANALOG_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\analog."__MMI_RES_TYPE_WALLPAPER__,
            "Image associated with Wallpaper.");
      #else
        ADD_APPLICATION_IMAGE3(
            IMG_ID_DISPCHAR_ANALOG_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\analog.gif",
            "Image associated with Wallpaper.");
      #endif /* __MMI_RES_TYPE_WALLPAPER__ */
     #endif /* __MMI_ANALOG_CLOCK__ */ 

     #ifdef __MMI_DIGITAL_CLOCK__
        fprintf(
            res_log,
            "                ADD_APPLICATION_IMAGE3(IMG_ID_DISPCHAR_DIGITAL_CLK=%d, path=%s)\n",
            IMG_ID_DISPCHAR_DIGITAL_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\digital."__MMI_RES_TYPE_WALLPAPER__);
      #ifdef __MMI_RES_TYPE_WALLPAPER__
        ADD_APPLICATION_IMAGE3(
            IMG_ID_DISPCHAR_DIGITAL_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\digital."__MMI_RES_TYPE_WALLPAPER__,
            "Image associated with Wallpaper.");
      #else
        ADD_APPLICATION_IMAGE3(
            IMG_ID_DISPCHAR_DIGITAL_CLK,
            CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\digital.gif",
            "Image associated with Wallpaper.");
      #endif /* __MMI_RES_TYPE_WALLPAPER__ */
     #endif /* __MMI_DIGITAL_CLOCK__ */ 
    #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

#ifdef __MMI_POWER_ON_OFF_DISPLAY__	
	fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_0=%d, path=%s)\n",IMG_ID_PHNSET_ON_START,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\POON."__MMI_RES_TYPE_POWER_ONOFF__);
    fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_0=%d, path=%s)\n",IMG_ID_PHNSET_OFF_START,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\pooff."__MMI_RES_TYPE_POWER_ONOFF__);
  #if defined(__MMI_FTE_SUPPORT__) &&!defined(__OP01__) && !defined(__OP02__) && !defined(__OP11__)
    ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_START, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\POONOFF.gif","Power ON image");
	ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_START,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\POONOFF.gif","Power OFF image");
  #elif defined(__MMI_RES_TYPE_POWER_ONOFF__)
    ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_START, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\POON."__MMI_RES_TYPE_POWER_ONOFF__,"Power ON image");
	ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_START,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\pooff."__MMI_RES_TYPE_POWER_ONOFF__,"Power OFF image");
  #else
	ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_START, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\POON.gif","Power ON image");
	ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_START,CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\pooff.gif","Power OFF image");
  #endif/* __MMI_RES_TYPE_POWER_ONOFF__ */
 #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */

    fprintf(res_log, "==Begin auto generate image resource==\n");
#if defined(__MMI_WALLPAPER_NUM__) && (__MMI_WALLPAPER_NUM__)
	for (i = 0; i < __MMI_WALLPAPER_NUM__; i++)
#else
	for (i = 0; i < MAX_WALLPAPER_IMG - MAX_OTHER_WALLPAPER; i++)
#endif
    {
    #ifdef __MMI_RES_TYPE_WALLPAPER__
      #ifndef __COSMOS_MMI__
        char gif_path[] = CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\wall01."__MMI_RES_TYPE_WALLPAPER__;
      #else
        char gif_path[] = RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\wp_01."__MMI_RES_TYPE_WALLPAPER__;
        char wp_thumb_path[] = RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\thumbnail\\\\wp_thumb_01."__MMI_RES_TYPE_WALLPAPER__;
      #endif
    
    #else
    
      #ifndef __COSMOS_MMI__
        char gif_path[] = CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\wall01.gif";
      #else
        char gif_path[] = RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\wp_01.gif";
        char wp_thumb_path[] = RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\thumbnail\\\\wp_thumb_01.gif";
      #endif

    #endif
        char m3d_path[] = CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\M3D\\\\m3d01.m3d";

        char *path = NULL;
        int position = 0;
	#ifndef __COSMOS_MMI__
        int gif_position = sizeof(CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\wall");
	#else
        int gif_position = sizeof(RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\wp_");
        int thumb_position = sizeof(RES_IMG_ROOT "\\\\Wallpaper\\\\WP_Static\\\\thumbnail\\\\wp_thumb_");
	#endif
        int m3d_position = sizeof(CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\M3D\\\\m3d");
        
        if (i < (MAX_WALLPAPER_IMG - MAX_OTHER_WALLPAPER))
        {
            position = gif_position;

            path = &gif_path[0];

            {
                path[position - 1] = '0' + (i + 1)/10;
                path[position] = '0' + (i + 1)%10;
			#ifdef __COSMOS_MMI__
                wp_thumb_path[thumb_position - 1] = '0' + (i + 1)/10;
                wp_thumb_path[thumb_position] = '0' + (i + 1)%10;                    
			#endif
			#if 0
				/* under construction !*/
				/* under construction !*/
				/* under construction !*/
				/* under construction !*/
				/* under construction !*/
			#endif
            }
        }
        else
        {
            position = m3d_position;
            path = &m3d_path[0];

        #if defined(__MMI_DISPCHAR_M3D_FISH__)
            path[position] = '1' + j;
        #elif defined(__MMI_DISPCHAR_M3D_PENGUIN__)
            path[position] = '4' + j;
        #elif defined(__MMI_DISPCHAR_M3D_BALL__)
            path[position] = '7' + j;
        #endif 
        	j++;
        }

        ADD_APPLICATION_IMAGE3((IMG_ID_PHNSET_WP_START + i), path, "Image associated with wallpaer.");
        fprintf(res_log, "    WALLPAPER: ADD_APPLICATION_IMAGE3(%d, %s)\n", (IMG_ID_PHNSET_WP_START + i), path);
    #ifdef __COSMOS_MMI__            
        ADD_APPLICATION_IMAGE3((IMG_ID_PHNSET_WP_THUMB_START + i), wp_thumb_path, "Image associated with wallpaer.");
        fprintf(res_log, "    WALLPAPER THUMB: ADD_APPLICATION_IMAGE3(%d, %s)\n", (IMG_ID_PHNSET_WP_THUMB_START + i), wp_thumb_path);        
    #endif
    #ifndef __COSMOS_MMI__   
    #ifdef __MMI_SCREEN_SAVER__         
        ADD_APPLICATION_IMAGE3((IMG_ID_PHNSET_SS_START + i), path, "Image associated with screensaver.");
        fprintf(res_log, "    SCREENSAVER: ADD_APPLICATION_IMAGE3(%d, %s)\n", (IMG_ID_PHNSET_SS_START + i), path);
    #endif
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        gif_path[gif_position - 1] = '0' + (i + 1)/10;
        gif_path[gif_position] = '0' + (i + 1)%10;
        ADD_APPLICATION_IMAGE3((IMG_ID_PHNSET_ON_START + i + 1), gif_path, "Image associated with poweron disp.");
        fprintf(res_log, "    POWER ON DISPLAY: ADD_APPLICATION_IMAGE3(%d, %s)\n", (IMG_ID_PHNSET_ON_START + i + 1), gif_path);
        ADD_APPLICATION_IMAGE3((IMG_ID_PHNSET_OFF_START + i + 1), gif_path, "Image associated with poweroff disp.");
        fprintf(res_log, "    POWER OFF DISPLAY: ADD_APPLICATION_IMAGE3(%d, %s)\n", (IMG_ID_PHNSET_OFF_START + i + 1), gif_path);
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
    #endif
    }

    #if 0
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SWFLASH__ */
    
        /* Generate Sub Wallpaper images */
    #ifdef __MMI_SUB_WALLPAPER__
        #ifdef __MMI_RES_TYPE_SUBLCD_WALLPAPER__ 
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_0,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall01."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_1,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall02."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_2,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall03."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_3,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall04."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_4,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall05."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_5,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall06."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_6,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall07."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_7,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall08."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_8,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall09."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_9,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall10."__MMI_RES_TYPE_SUBLCD_WALLPAPER__,
                "Image associated with wallpaper.");
        #else
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_0,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall01.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_1,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall02.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_2,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall03.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_3,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall04.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_4,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall05.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_5,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall06.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_6,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall07.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_7,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall08.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_8,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall09.gif",
                "Image associated with wallpaper.");
            ADD_APPLICATION_IMAGE3(
                IMG_ID_PHNSET_SUB_WP_9,
                CUST_IMG_PATH "\\\\SubLCD\\\\WallPaper\\\\wall10.gif",
                "Image associated with wallpaper.");
        #endif /* __MMI_RES_TYPE_SUBLCD_WALLPAPER__ */ 
    #endif /* __MMI_SUB_WALLPAPER__ */ 

    #ifdef __MMI_SCREEN_SAVER__
    #if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(MJPG_DECODE)
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_SS_VDO_START,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.avi");
    #elif defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(MP4_DECODE)
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_SS_VDO_START,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.mp4");
    #endif 
    #endif /* __MMI_SCREEN_SAVER__ */

        /* Generate Power on/off display images */
    #ifndef __MMI_POWER_ON_OFF_DISPLAY__
    #ifdef LOW_COST_SUPPORT
#if defined(__OLED_BW_MMI__)// baiwenlin 20130831  
#if defined(__MMI_MAINLCD_128X36__)
#if defined(__NEUTRAL_LOGO__)
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_ON_ANIMATION_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\poon_1.bmp");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\poon_1.bmp",
            "Power ON image");
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\pooff.bmp",
            "Power OFF image");
#else /*__NEUTRAL_LOGO__*/
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_ON_ANIMATION_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\poon.bmp");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\poon.bmp",
            "Power ON image");
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\pooff.bmp",
            "Power OFF image");
#endif /* __NEUTRAL_LOGO__ */
#elif defined(__MMI_MAINLCD_128X64__)				
#if defined(__NEUTRAL_LOGO__)
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_ON_ANIMATION_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\poon_1.bmp");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\poon_1.bmp",
            "Power ON image");
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\pooff.bmp",
            "Power OFF image");
#else /*__NEUTRAL_LOGO__*/
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_ON_ANIMATION_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\poon.bmp");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\poon.bmp",
            "Power ON image");
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            "..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\pooff.bmp",
            "Power OFF image");
#endif /* __NEUTRAL_LOGO__ */
#endif /* __MMI_MAINLCD_128X36__ */
#else /*__OLED_BW_MMI__*/
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_ON_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_ON_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__,
            "Power ON image");
        fprintf(res_log, "                ADD_APPLICATION_IMAGE3(IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT=%d, path=%s)\n",IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT, CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__);
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo." __MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__,
            "Power OFF image");
#endif /* __OLED_BW_MMI__ */
    #else /* LOW_COST_SUPPORT */
	#if defined(__MMI_FTE_SUPPORT__) && !defined(__OP01__) && !defined(__OP02__) && !defined(__OP11__)
	        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\POONOFF.gif",
            "Power ON image");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\POONOFF.gif",
            "Power OFF image");
	#elif defined(__MMI_RES_TYPE_POWER_ONOFF__) /* __MMI_FTE_SUPPORT__ */
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\POON."__MMI_RES_TYPE_POWER_ONOFF__,
            "Power ON image");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\pooff."__MMI_RES_TYPE_POWER_ONOFF__,
            "Power OFF image");
    #else /* __MMI_FTE_SUPPORT__ */
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_ON_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\POON.gif",
            "Power ON image");
        ADD_APPLICATION_IMAGE3(
            IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\poweronoff\\\\pooff.gif",
            "Power OFF image");
    #endif /* __MMI_FTE_SUPPORT__ */
    #endif /* LOW_COST_SUPPORT */    
    #elif defined( __MMI_POWER_ON_OFF_DISPLAY_VIDEO__) && defined(MJPG_DECODE)
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_ON_VDO_0,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.avi");
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_OFF_VDO_0,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.avi");
    #elif defined( __MMI_POWER_ON_OFF_DISPLAY_VIDEO__) && defined(MP4_DECODE)
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_ON_VDO_0,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.mp4");
        ADD_APPLICATION_MEDIA(
            IMG_ID_PHNSET_OFF_VDO_0,
            CUST_IMG_PATH "\\\\MainLCD\\\\Active\\\\Poweronoff\\\\PWRONOFF.mp4");
    #endif 
	#if (defined (__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) || (defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__))
	    ADD_APPLICATION_MEDIA(
	    IMG_ID_VIDEO_WP_VDO_0,
	    CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\WallPaper\\\\VDO_WP01.3gp");
	#endif /* video wallpaper feature */
    }

    fclose(res_log);

}




