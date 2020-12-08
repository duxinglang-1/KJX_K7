/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   image_sensor_S5K5CAGA.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Image sensor driver function
 *
 * Author: Qihao Geng (mtk70548)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "isp_comm_if.h"
#include "camera_sccb.h"
#include "image_sensor.h"
#include "cal_comm_def.h"
#include "isp_if.h"



//extern const char gpio_flashlight_en_pin;
#if (defined(__CATS_SUPPORT__)||defined(__ATA_SUPPORT__))
const unsigned char CATSTestPattern[] = { 0 };
#endif

#ifdef S5K5CAGA_LOAD_FROM_T_FLASH
    #include "med_api.h"
    #include "med_utility.h"

    S5K5CAGA_initial_set_struct S5K5CAGA_Init_Reg[4000];
    WCHAR S5K5CAGA_set_file_name[256] = {0};
#endif

#ifdef S5K5CAGA_LOAD_FROM_T_FLASH
/*************************************************************************
* FUNCTION
*	S5K5CAGA_Initialize_from_T_Flash
*
* DESCRIPTION
*	Read the initialize setting from t-flash or user disk to speed up image quality tuning.
*
* PARAMETERS
*	None
*
* RETURNS
*	kal_uint8 - 0 : Load setting fail, 1 : Load setting successfully.
*
*************************************************************************/

static kal_uint8 S5K5CAGA_Initialize_from_T_Flash()
{
	FS_HANDLE fp = -1;				/* Default, no file opened. */
	kal_uint8 *data_buff = NULL;
	kal_uint8 *curr_ptr = NULL;
	kal_uint32 file_size = 0;
	kal_uint32 bytes_read = 0;
	kal_uint32 i = 0, j = 0;
	kal_uint8 func_ind[3] = {0};	/* CamWriteCmosSensor or DLY */

	kal_mem_cpy(S5K5CAGA_set_file_name, L"C:\\S5K5CAGA_Initialize_Setting.Bin", sizeof(L"C:\\S5K5CAGA_Initialize_Setting.Bin"));

	/* Search the setting file in all of the user disk. */
	curr_ptr = (kal_uint8 *)S5K5CAGA_set_file_name;
	while (fp < 0)
	{
		if ((*curr_ptr >= 'c' && *curr_ptr <= 'z') || (*curr_ptr >= 'C' && *curr_ptr <= 'Z'))
		{
			fp = FS_Open(S5K5CAGA_set_file_name, FS_READ_ONLY);
			if (fp >= 0)
			{
				break;			/* Find the setting file. */
			}

			*curr_ptr = *curr_ptr + 1;
		}
		else
		{
			break ;
		}
	}
	

	if (fp < 0)		/* Error handle */
	{
		S5K5CAGA_TRACE("!!! Warning, Can't find the initial setting file!!!");
	
		return 0;
	}

	FS_GetFileSize(fp, &file_size);
	if (file_size < 20)
	{
		S5K5CAGA_TRACE("!!! Warning, Invalid setting file!!!");
	
		return 0;			/* Invalid setting file. */
	}

	//data_buff =(kal_uint8 *) med_alloc_ext_mem(file_size);
	data_buff = (kal_uint8 *)med_alloc_asm_mem_framebuffer(0, file_size);
	if (data_buff == NULL)
	{
		S5K5CAGA_TRACE("!!! Warning, Memory not enoughed...");

		return 0;				/* Memory not enough */
	}
	FS_Read(fp, data_buff, file_size, &bytes_read);

	/* Start parse the setting witch read from t-flash. */
	curr_ptr = data_buff;
	while (curr_ptr < (data_buff + file_size))
	{
		while ((*curr_ptr == ' ') || (*curr_ptr == '\t'))/* Skip the Space & TAB */
			curr_ptr++;				

		if (((*curr_ptr) == '/') && ((*(curr_ptr + 1)) == '*'))
		{
			while (!(((*curr_ptr) == '*') && ((*(curr_ptr + 1)) == '/')))
			{
				curr_ptr++;		/* Skip block comment code. */
			}

			while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
			{
				curr_ptr++;
			}

			curr_ptr += 2;						/* Skip the enter line */
			
			continue ;
		}
		
		if (((*curr_ptr) == '/') || ((*curr_ptr) == '{') || ((*curr_ptr) == '}'))		/* Comment line, skip it. */
		{
			while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
			{
				curr_ptr++;
			}

			curr_ptr += 2;						/* Skip the enter line */

			continue ;
		}
		/* This just content one enter line. */
		if (((*curr_ptr) == 0x0D) && ((*(curr_ptr + 1)) == 0x0A))
		{
			curr_ptr += 2;
			continue ;
		}

		kal_mem_cpy(func_ind, curr_ptr, 3);
		curr_ptr += 4;					/* Skip "CamWriteCmosSensor(" or "DLY(" */
		if (strcmp((const char *)func_ind, "REG") == 0)		/* CamWriteCmosSensor */
		{
			S5K5CAGA_Init_Reg[i].op_code = S5K5CAGA_OP_CODE_REG;
			
			S5K5CAGA_Init_Reg[i].init_reg = strtol((const char *)curr_ptr, NULL, 16);
			curr_ptr += S5K5CAGA_REG_SKIP;	/* Skip "0x0000, " */
			
			S5K5CAGA_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 16);
			curr_ptr += S5K5CAGA_VAL_SKIP;	/* Skip "0x0000);" */
		}
		else									/* DLY */
		{
			/* Need add delay for this setting. */
			S5K5CAGA_Init_Reg[i].op_code = S5K5CAGA_OP_CODE_DLY;
			
			S5K5CAGA_Init_Reg[i].init_reg = 0xFF;
			S5K5CAGA_Init_Reg[i].init_val = strtol((const char *)curr_ptr, NULL, 10);	/* Get the delay ticks, the delay should less then 50 */
		}
		i++;
		

		/* Skip to next line directly. */
		while (!((*curr_ptr == 0x0D) && (*(curr_ptr+1) == 0x0A)))
		{
			curr_ptr++;
		}
		curr_ptr += 2;
	}

	/* (0xFFFF, 0xFFFF) means the end of initial setting. */
	S5K5CAGA_Init_Reg[i].op_code = S5K5CAGA_OP_CODE_END;
	S5K5CAGA_Init_Reg[i].init_reg = 0xFF;
	S5K5CAGA_Init_Reg[i].init_val = 0xFF;
	i++;
	
	S5K5CAGA_TRACE("%d register read...", i-1);

	//med_free_ext_mem((void **)&data_buff);
	med_free_asm_mem(0, (void **)&data_buff);
	FS_Close(fp);

	S5K5CAGA_TRACE("Start apply initialize setting.");
	/* Start apply the initial setting to sensor. */
	for (j=0; j<i; j++)
	{
		if (S5K5CAGA_Init_Reg[j].op_code == S5K5CAGA_OP_CODE_END)	/* End of the setting. */
		{
			break ;
		}
		else if (S5K5CAGA_Init_Reg[j].op_code == S5K5CAGA_OP_CODE_DLY)
		{
			kal_sleep_task(S5K5CAGA_Init_Reg[j].init_val);		/* Delay */
		}
		else if (S5K5CAGA_Init_Reg[j].op_code == S5K5CAGA_OP_CODE_REG)
		{
			CamWriteCmosSensor(S5K5CAGA_Init_Reg[j].init_reg, S5K5CAGA_Init_Reg[j].init_val);
		}
		else
		{
			ASSERT(0);
		}
	}

	S5K5CAGA_TRACE("%d register applied...", j);

	return 1;	
}
#endif


kal_uint16 S5K5CAGAReadRegister(kal_uint16 addr)                           
{                                             
    kal_uint16 temp;                          

    CamWriteCmosSensor(0x002C, 0x7000);                            
    CamWriteCmosSensor(0x002E, addr); 

    temp = CamReadCmosSensor(0x0f12); 

    kal_prompt_trace(MOD_ENG, "addr:%x,value:%x", addr,temp);              

    return temp;                              

}     


kal_uint32 S5K5CAGAReadShutter()
{
    kal_uint32 shutter_low = 0, shutter_high = 0;

    /* Shutter * 10 / 4(us) will the actual exposure time, ex, 0x8F24 = 91.6ms */
    CamWriteCmosSensor(0x002C, 0x7000);
    CamWriteCmosSensor(0x002E, 0x23e8);     /* Shutter Low */
    shutter_low = CamReadCmosSensor(0x0f12);  
    CamWriteCmosSensor(0x002E, 0x23eA);     /* Shutter High */
    shutter_high = CamReadCmosSensor(0x0f12);

    S5K5CAGA_TRACE("shutter_low = %x, shutter_high = %x", shutter_low, shutter_high);

    return (shutter_low | (shutter_high<<16)) / 4;
}

kal_uint32 S5K5CAGAReadGain()
{
    kal_uint32 analog_gain = 0, digital_gain = 0;

    CamWriteCmosSensor(0x002C, 0x7000);
    CamWriteCmosSensor(0x002E, 0x23EC);     /* Analog Gain, 0x100 - 1x */
    analog_gain = CamReadCmosSensor(0x0f12);  
    CamWriteCmosSensor(0x002E, 0x23EE);     /* Digital Gain, 0x100 - 1x */
    digital_gain = CamReadCmosSensor(0x0f12);  

    S5K5CAGA_TRACE("analog_gain = %x, digital_gain = %x", analog_gain, digital_gain);

    /* (analog_gain or digital_gain)  * 128 / 256 equal to (analog_gain or digital_gain) / 2 */
    analog_gain /= 2;
    digital_gain /= 2;

    return ((analog_gain * digital_gain) / 128);
}



/*************************************************************************
* FUNCTION
*    S5K5CAGASetMirror
*
* DESCRIPTION
*    This function set the mirror to the CMOS sensor
*
* PARAMETERS
*    Mirror
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGASetMirror(kal_uint8 Mirror)
{
    CamWriteCmosSensor(0x0028, 0x7000);
    // CamWriteCmosSensor(0x002a, 0x0296); 

    switch (Mirror)   //  MTK改善流程 20110923                       
    {                                         
        case IMAGE_SENSOR_MIRROR_NORMAL:                     
            CamWriteCmosSensor(0x002A,0x0296); //#REG_0TC_PCFG_uPrevMirror                                                                                                                     
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x002A,0x02C6); //#REG_1TC_PCFG_uPrevMirror                                                                                                                     
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x002A,0x02F6); //#REG_2TC_PCFG_uPrevMirror                                                                                                                     
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x002A,0x0326); //#REG_3TC_PCFG_uPrevMirror                                                                                                                     
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x002A,0x0356); //#REG_4TC_PCFG_uPrevMirror                                                                                                                     
            CamWriteCmosSensor(0x0F12,0x0000);                          
            CamWriteCmosSensor(0x0F12,0x0000);                          
        break;                             
        case IMAGE_SENSOR_MIRROR_H:                   
            CamWriteCmosSensor(0x002A,0x0296);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x002A,0x02C6);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x002A,0x02F6);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x002A,0x0326);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x002A,0x0356);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
            CamWriteCmosSensor(0x0F12,0x0001);                          
        break;
        case IMAGE_SENSOR_MIRROR_V:                   
            CamWriteCmosSensor(0x002A,0x0296);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x002A,0x02C6);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x002A,0x02F6);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x002A,0x0326);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x002A,0x0356);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
            CamWriteCmosSensor(0x0F12,0x0002);                          
        break;
        case IMAGE_SENSOR_MIRROR_HV:                  
            CamWriteCmosSensor(0x002A,0x0296);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x002A,0x02C6);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x002A,0x02F6);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x002A,0x0326);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x002A,0x0356);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
            CamWriteCmosSensor(0x0F12,0x0003);                          
        break;
        default:                               
            ASSERT(0);                         
        break;                             
    }                                         
                                  
    //Update mirror settings
    CamWriteCmosSensor(0x002A,0x0240); //#REG_TC_GP_PrevOpenAfterChange
    CamWriteCmosSensor(0x0F12,0x0001);
    CamWriteCmosSensor(0x002A,0x0230); //#REG_TC_GP_NewConfigSync
    CamWriteCmosSensor(0x0F12,0x0001);
    CamWriteCmosSensor(0x002A,0x023E); //#REG_TC_GP_PrevConfigChanged
    CamWriteCmosSensor(0x0F12,0x0001);
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAAeEnable
*
* DESCRIPTION
*    disable/enable AE
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAAeEnable(kal_bool Enable)
{
    kal_uint16 temp_reg;

    CamWriteCmosSensor(0x002C, 0x7000);	
    CamWriteCmosSensor(0x002E, 0x04D2);

    temp_reg = CamReadCmosSensor(0X0F12);
    S5K5CAGA_TRACE("[AE] Bypass = %d, Enable = %d", S5K5CAGASensor.BypassAe, Enable);
    
    if (S5K5CAGASensor.BypassAe)
    {
        Enable = KAL_FALSE;
    }

    if (Enable)
    {
        temp_reg |= (0x0002);
    }
    else
    {
        temp_reg &= (~0x0002); 
    }

    CamWriteCmosSensor(0x0028, 0x7000);	
    CamWriteCmosSensor(0x002A, 0x04D2);
    CamWriteCmosSensor(0x0f12, temp_reg);
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAAwbEnable
*
* DESCRIPTION
*    disable/enable awb
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAAwbEnable(kal_bool Enable)
{
    kal_uint16 temp_reg;

    CamWriteCmosSensor(0x002C, 0x7000); 
    CamWriteCmosSensor(0x002E, 0x04D2);

    temp_reg = CamReadCmosSensor(0X0F12);
    S5K5CAGA_TRACE("[AWB] Bypass = %d, Enable = %d", S5K5CAGASensor.BypassAwb, Enable);

    if (S5K5CAGASensor.BypassAwb)
    {
        Enable = KAL_FALSE;
    }

    if (Enable)
    {
        temp_reg |= (0x0008);
    }
    else
    {
        temp_reg &= (~0x0008); 
    }

    CamWriteCmosSensor(0x0028, 0x7000); 
    CamWriteCmosSensor(0x002A, 0x04D2);
    CamWriteCmosSensor(0x0f12, temp_reg);



}

/*************************************************************************
* FUNCTION
*    S5K5CAGASetDummy
*
* DESCRIPTION
*    This function add DummyPixel and DummyLine.
*
* PARAMETERS
*    DummyPixel
*    DummyLine
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGASetDummy(kal_uint16 DummyPixel, kal_uint16 DummyLine)
{
  
}

/*************************************************************************
* FUNCTION
*    S5K5CAGANightMode
*
* DESCRIPTION
*    This function set night mode to sensor.
*
* PARAMETERS
*    Enable
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGANightMode(kal_bool Enable)
{
    S5K5CAGASensor.NightMode = Enable;
    
    if (KAL_TRUE == S5K5CAGASensor.VideoMode)
    {
        S5K5CAGA_TRACE("[Preview]video frame rate = %d", S5K5CAGASensor.Fps);
        /* The video frame rate if provide from cal. */
        if (S5K5CAGASensor.Fps >= 300)      /* Max up to 30fps */
        {
            S5K5CAGASensor.Fps = 300;
        }
        if (S5K5CAGASensor.Fps <= 10)      /* Min down to 1fps */
        {
            S5K5CAGASensor.Fps = 10;
        }
    }

    CamWriteCmosSensor(0xFCFC, 0xD000); 
    CamWriteCmosSensor(0x0028, 0x7000);
	CamWriteCmosSensor(0x002A, 0x0288);	//#REG_0TC_PCFG_usMaxFrTimeMsecMult10 
    if (Enable) 																																																																																																																																																																																																																																											
    {
        if (S5K5CAGASensor.VideoMode)																																																																																																																																														   
        {
            CamWriteCmosSensor(0x0F12, ((1000 * 10 * 10) / S5K5CAGASensor.Fps)); //#REG_0TC_PCFG_usMaxFrTimeMsecMult10
            CamWriteCmosSensor(0x0F12, ((1000 * 10 * 10) / S5K5CAGASensor.Fps)); //#REG_0TC_PCFG_usMinFrTimeMsecMult10
        }
        else		
        {
            CamWriteCmosSensor(0x0F12, S5K5CAGA_CAM_NIT_MAX_FR_TIME); //#REG_0TC_PCFG_usMaxFrTimeMsecMult10
            CamWriteCmosSensor(0x0F12, S5K5CAGA_CAM_NIT_MIN_FR_TIME); //#REG_0TC_PCFG_usMinFrTimeMsecMult10

            //CamWriteCmosSensor(0x002A, 0x1680);	//Set Shutter Speed
            //CamWriteCmosSensor(0x0F12, 0x1340);	// #evt1_lt_uMaxExp4 340ms
            //CamWriteCmosSensor(0x0F12, 0x0002);
            //CamWriteCmosSensor(0x002A, 0x1688);
            //CamWriteCmosSensor(0x0F12, 0x1340);	// #evt1_lt_uCapMaxExp4 340ms
            //CamWriteCmosSensor(0x0F12, 0x0002);

            // Set gain
            //CamWriteCmosSensor(0x002A, 0x168E);
            //CamWriteCmosSensor(0x0F12, 0x0A00); // #evt1_lt_uMaxAnGain4
        }
        CamWriteCmosSensor(0x002A, 0x0838);
        CamWriteCmosSensor(0x0F12, 0x0A64);
    																																																																																																																																																																																																																																   
    }		 
    else
    {	
        if (S5K5CAGASensor.VideoMode)																																																																																																																																																																																																										   
        {
            CamWriteCmosSensor(0x0F12, ((1000 * 10 * 10) / S5K5CAGASensor.Fps)); //#REG_0TC_PCFG_usMaxFrTimeMsecMult10
            CamWriteCmosSensor(0x0F12, ((1000 * 10 * 10) / S5K5CAGASensor.Fps)); //#REG_0TC_PCFG_usMinFrTimeMsecMult10
        }
        else	
        {
            CamWriteCmosSensor(0x0F12, S5K5CAGA_CAM_NOM_MAX_FR_TIME); //#REG_0TC_PCFG_usMaxFrTimeMsecMult10
            CamWriteCmosSensor(0x0F12, S5K5CAGA_CAM_NOM_MIN_FR_TIME); //#REG_0TC_PCFG_usMinFrTimeMsecMult10

            //CamWriteCmosSensor(0x002A, 0x1680);	//Set Shutter Speed
            //CamWriteCmosSensor(0x0F12, 0xBB80);	// #evt1_lt_uMaxExp4 120ms
            //CamWriteCmosSensor(0x0F12, 0x0000);
            //CamWriteCmosSensor(0x002A, 0x1688);
            //CamWriteCmosSensor(0x0F12, 0xBB80);	// #evt1_lt_uCapMaxExp4 120ms
            //CamWriteCmosSensor(0x0F12, 0x0000);

            // Set gain
            //CamWriteCmosSensor(0x002A, 0x168E);
            //CamWriteCmosSensor(0x0F12, 0x0800); //04CC// #evt1_lt_uMaxAnGain4 
        }

        CamWriteCmosSensor(0x002A, 0x0838);
        CamWriteCmosSensor(0x0F12, 0x0064);
    }		 

    CamWriteCmosSensor(0x002A, 0x023C);
    CamWriteCmosSensor(0x0F12, 0x0000); // #REG_TC_GP_ActivePrevConfig // Select preview configuration_0
    
    CamWriteCmosSensor(0x002A, 0x0240);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_PrevOpenAfterChange
    CamWriteCmosSensor(0x002A, 0x0230);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_NewConfigSync // Update preview configuration
    CamWriteCmosSensor(0x002A, 0x023E);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_PrevConfigChanged
}

/*************************************************************************
* FUNCTION
*    S5K5CAGASceneMode
*
* DESCRIPTION
*    This function get/set scene mode of sensor.
*
* PARAMETERS
*    IsCam: camera scene mode or not
*    In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGASceneMode(kal_bool IsCam, P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT SceneMode = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
    SceneMode->IsSupport = KAL_TRUE;
    SceneMode->ItemCount = 2;
    if (IsCam)
    {
      SceneMode->SupportItem[0] = CAM_AUTO_DSC;
      SceneMode->SupportItem[1] = CAM_NIGHTSCENE;
    }
    else
    {
      //SceneMode->SupportItem[0] = CAM_VIDEO_AUTO;
      //SceneMode->SupportItem[1] = CAM_VIDEO_NIGHT;

	  SceneMode->SupportItem[0] = CAM_VIDEO_NIGHT;
      SceneMode->SupportItem[1] = CAM_VIDEO_AUTO;
    }
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {
    kal_bool Enable;
    
    if (CAM_NIGHTSCENE == In->FeatureSetValue || CAM_VIDEO_NIGHT == In->FeatureSetValue)
    {
      Enable = KAL_TRUE;
    }
    else
    {
      Enable = KAL_FALSE;
    }
	kal_prompt_trace(MOD_ENG,"feather control");
   // S5K5CAGANightMode(Enable);
	
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAEv
*
* DESCRIPTION
*    Exposure setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGAEv(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Exposure = &Out->FeatureInfo.FeatureEnum;
    
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        
        Exposure->IsSupport = KAL_TRUE;
        Exposure->ItemCount = 9;
        Exposure->SupportItem[0] = CAM_EV_NEG_4_3;
        Exposure->SupportItem[1] = CAM_EV_NEG_3_3;
        Exposure->SupportItem[2] = CAM_EV_NEG_2_3;
        Exposure->SupportItem[3] = CAM_EV_NEG_1_3;
        Exposure->SupportItem[4] = CAM_EV_ZERO;
        Exposure->SupportItem[5] = CAM_EV_POS_1_3;
        Exposure->SupportItem[6] = CAM_EV_POS_2_3;
        Exposure->SupportItem[7] = CAM_EV_POS_3_3;
        Exposure->SupportItem[8] = CAM_EV_POS_4_3;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {

    S5K5CAGA_TRACE("[EV] = %d", In->FeatureSetValue);
    
    S5K5CAGASensor.Exposure = In->FeatureSetValue;

    /* Control exposure value (EV) in 8:8 format. Value should be in the range of -2 : 2, 
        where 2 translates to 0x400 and -2 translates to 0x40 */
    CamWriteCmosSensor(0xFCFC, 0xD000); 
	CamWriteCmosSensor(0x0028, 0x7000);
	CamWriteCmosSensor(0x002A, 0x0218);	  // REG_TC_UserExposureVal88  
    switch (S5K5CAGASensor.Exposure)
    {

		case CAM_EV_NEG_4_3:					
			CamWriteCmosSensor(0x0F12, 0x0040);  // EV-2
			break;
		case CAM_EV_NEG_3_3:				   
			CamWriteCmosSensor(0x0F12, 0x0060);  // TODO: EV-1.5
			break;
		case CAM_EV_NEG_2_3:				   
			CamWriteCmosSensor(0x0F12, 0x0080);  // EV-1
			break;
		case CAM_EV_NEG_1_3:				   
			CamWriteCmosSensor(0x0F12, 0x00C0);  // TODO:  EV-0.5
			break;
		case CAM_EV_ZERO:				   
			CamWriteCmosSensor(0x0F12, 0x0100); // Default Value, 0
			break;
		case CAM_EV_POS_1_3:				
			CamWriteCmosSensor(0x0F12, 0x0180);  // TODO:  EV0.5
			break;
		case CAM_EV_POS_2_3:				   
			CamWriteCmosSensor(0x0F12, 0x0200);  // EV1
			break;
		case CAM_EV_POS_3_3:					
			CamWriteCmosSensor(0x0F12, 0x0300);  // TODO:  EV1.5
		    break;
		case CAM_EV_POS_4_3:				   
			CamWriteCmosSensor(0x0F12, 0x0400);  // EV2
			break;
		default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;

    }
  }
  return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAContrast
*
* DESCRIPTION
*    Contrast setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGAContrast(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Contrast = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Contrast->IsSupport = KAL_TRUE;
        Contrast->ItemCount = 3;
        Contrast->SupportItem[0] = CAM_CONTRAST_HIGH;
        Contrast->SupportItem[1] = CAM_CONTRAST_MEDIUM;
        Contrast->SupportItem[2] = CAM_CONTRAST_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        S5K5CAGA_TRACE("[Contrast] = %d (0-L, 1-M, 2-H)", In->FeatureSetValue);
        
        S5K5CAGASensor.Contrast = In->FeatureSetValue;
        switch (In->FeatureSetValue)
        {
        case CAM_CONTRAST_HIGH:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x020E);					 
            CamWriteCmosSensor(0x0F12, 0x007F);	//REG_TC_UserContrast     
            break;
        case CAM_CONTRAST_MEDIUM: 
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x020E);					 
            CamWriteCmosSensor(0x0F12, 0x0000);	//REG_TC_UserContrast     
            break;
        case CAM_CONTRAST_LOW:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x020E);					 
            CamWriteCmosSensor(0x0F12, 0xFFC0);	//REG_TC_UserContrast     
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   S5K5CAGASaturation
*
* DESCRIPTION
*   Saturation setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGASaturation(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Saturation = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Saturation->IsSupport = KAL_TRUE;
        Saturation->ItemCount = 3;
        Saturation->SupportItem[0] = CAM_SATURATION_HIGH;
        Saturation->SupportItem[1] = CAM_SATURATION_MEDIUM;
        Saturation->SupportItem[2] = CAM_SATURATION_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        S5K5CAGA_TRACE("[Saturation] = %d (0-L, 1-M, 2-H)", In->FeatureSetValue);
        
        S5K5CAGASensor.Saturation = In->FeatureSetValue;

        switch (In->FeatureSetValue)
        {
        case CAM_SATURATION_HIGH:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x0210);					 
            CamWriteCmosSensor(0x0F12, 0x007F);	//REG_TC_UserSaturation     
            break;
        case CAM_SATURATION_MEDIUM:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x0210);					 
            CamWriteCmosSensor(0x0F12, 0x0000);	//REG_TC_UserSaturation     
            break;
        case CAM_SATURATION_LOW:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x0210);					 
            CamWriteCmosSensor(0x0F12, 0xFFC0);	//REG_TC_UserSaturation     
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*   S5K5CAGASharpness
*
* DESCRIPTION
*   Sharpness setting.
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGASharpness(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT Sharpness = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Sharpness->IsSupport = KAL_TRUE;
        Sharpness->ItemCount = 3;
        Sharpness->SupportItem[0] = CAM_SHARPNESS_HIGH;
        Sharpness->SupportItem[1] = CAM_SHARPNESS_MEDIUM;
        Sharpness->SupportItem[2] = CAM_SHARPNESS_LOW;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {	
        S5K5CAGA_TRACE("[Sharpness] = %d (0-L, 1-M, 2-H)", In->FeatureSetValue);
        
        S5K5CAGASensor.Sharpness = In->FeatureSetValue;

        switch (In->FeatureSetValue)
        {
        case CAM_SHARPNESS_HIGH:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x0212);					 
            CamWriteCmosSensor(0x0F12, 0x007F);	//REG_TC_UserSharpBlur 	
            break;
        case CAM_SHARPNESS_MEDIUM:
            CamWriteCmosSensor(0x0028, 0x7000);					 
            CamWriteCmosSensor(0x002A, 0x0212);					 
            CamWriteCmosSensor(0x0F12, 0x0000);	//REG_TC_UserSharpBlur 	
        case CAM_SHARPNESS_LOW:
            CamWriteCmosSensor(0x0028, 0x7000); 				  
            CamWriteCmosSensor(0x002A, 0x0212); 				  
            CamWriteCmosSensor(0x0F12, 0xFFC0);  //REG_TC_UserSharpBlur	 
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAWb
*
* DESCRIPTION
*    Wb setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGAWb(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Wb = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Wb->IsSupport = KAL_TRUE;
    Wb->ItemCount = 5;
    Wb->SupportItem[0] = CAM_WB_AUTO;
    Wb->SupportItem[1] = CAM_WB_CLOUD;
    Wb->SupportItem[2] = CAM_WB_DAYLIGHT;
    Wb->SupportItem[3] = CAM_WB_INCANDESCENCE;
    Wb->SupportItem[4] = CAM_WB_FLUORESCENT;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {

    S5K5CAGA_TRACE("[WB] = %d", In->FeatureSetValue);

    S5K5CAGASensor.Wb = In->FeatureSetValue;

	switch (S5K5CAGASensor.Wb)
	{
		case CAM_WB_AUTO:
			//============================================
			//	MWB off (Change to Auto mode)             
			//============================================
			//CamWriteCmosSensor(0xFCFC, 0xD000); 
        	//CamWriteCmosSensor(0x0028, 0x7000); 	// Set page                         
        	//CamWriteCmosSensor(0x002A, 0x04D2); 	// REG_TC_DBG_ AutoAlgEnBits
			//CamWriteCmosSensor(0x0F12, 0x067F); 	// #REG_TC_DBG_AutoAlgEnBits, AWB On
			S5K5CAGAAwbEnable(KAL_TRUE);
			break;

		case CAM_WB_CLOUD:	
			//======================================================================
			//	MWB : Cloudy_D65                                         
			//======================================================================
			//CamWriteCmosSensor(0xFCFC, 0xD000); 
        	//CamWriteCmosSensor(0x0028, 0x7000); 	// Set page                         
        	//CamWriteCmosSensor(0x002A, 0x04D2); 	// REG_TC_DBG_ AutoAlgEnBits
			//CamWriteCmosSensor(0x0F12, 0x0677);     //#REG_TC_DBG_AutoAlgEnBits,AWBOff
			S5K5CAGAAwbEnable(KAL_FALSE);

            CamWriteCmosSensor(0x0028, 0x7000); 
			CamWriteCmosSensor(0x002A, 0x04A0);
			CamWriteCmosSensor(0x0F12, 0x0128); //#REG_SF_USER_Rgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0100); //#REG_SF_USER_Ggain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x01AB); //#REG_SF_USER_Bgain
			CamWriteCmosSensor(0x0F12, 0x0001);                          
			                                             
			break;     
     
		case CAM_WB_DAYLIGHT:
			//==============================================
			//	MWB : sun&daylight_D50                      
			//==============================================
			//CamWriteCmosSensor(0xFCFC, 0xD000); 
        	//CamWriteCmosSensor(0x0028, 0x7000); 	// Set page                         
        	//CamWriteCmosSensor(0x002A, 0x04D2); 	// REG_TC_DBG_ AutoAlgEnBits
			//CamWriteCmosSensor(0x0F12, 0x0677);     //#REG_TC_DBG_AutoAlgEnBits,AWBOff
			S5K5CAGAAwbEnable(KAL_FALSE);

            CamWriteCmosSensor(0x0028, 0x7000); 
			CamWriteCmosSensor(0x002A, 0x04A0);
			CamWriteCmosSensor(0x0F12, 0x0166); //#REG_SF_USER_Rgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0100); //#REG_SF_USER_Ggain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0145); //#REG_SF_USER_Bgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			break;

		case CAM_WB_INCANDESCENCE:
			//==============================================                                       
			//	MWB : Incand_Tungsten                       
			//==============================================
			//CamWriteCmosSensor(0xFCFC, 0xD000); 
        	//CamWriteCmosSensor(0x0028, 0x7000); 	// Set page                         
        	//CamWriteCmosSensor(0x002A, 0x04D2); 	// REG_TC_DBG_ AutoAlgEnBits
			//CamWriteCmosSensor(0x0F12, 0x0677);     //#REG_TC_DBG_AutoAlgEnBits,AWBOff
			S5K5CAGAAwbEnable(KAL_FALSE);

            CamWriteCmosSensor(0x0028, 0x7000); 
			CamWriteCmosSensor(0x002A, 0x04A0);
			CamWriteCmosSensor(0x0F12, 0x0126); //#REG_SF_USER_Rgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0100); //#REG_SF_USER_Ggain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0105); //#REG_SF_USER_Bgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			break;

		case CAM_WB_FLUORESCENT:
			//==================================================================
			//	MWB : Florescent_TL84                             
			//==================================================================
			//CamWriteCmosSensor(0xFCFC, 0xD000); 
        	//CamWriteCmosSensor(0x0028, 0x7000); 	// Set page                         
        	//CamWriteCmosSensor(0x002A, 0x04D2); 	// REG_TC_DBG_ AutoAlgEnBits
			//CamWriteCmosSensor(0x0F12, 0x0777);     //#REG_TC_DBG_AutoAlgEnBits,AWBOff
			S5K5CAGAAwbEnable(KAL_FALSE);

            CamWriteCmosSensor(0x0028, 0x7000); 
			CamWriteCmosSensor(0x002A, 0x04A0);
			CamWriteCmosSensor(0x0F12, 0x0145); //#REG_SF_USER_Rgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x0100); //#REG_SF_USER_Ggain
			CamWriteCmosSensor(0x0F12, 0x0001);
			CamWriteCmosSensor(0x0F12, 0x01EB); //#REG_SF_USER_Bgain
			CamWriteCmosSensor(0x0F12, 0x0001);
			break;

		default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;  
		
	}
    
  }
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAEffect
*
* DESCRIPTION
*    Effect setting.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGAEffect(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
  if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
  {
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Effect = &Out->FeatureInfo.FeatureEnum;
    
    Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
    Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
    Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
    Effect->IsSupport = KAL_TRUE;
    Effect->ItemCount = 8;
    Effect->SupportItem[0] = CAM_EFFECT_ENC_NORMAL;
    Effect->SupportItem[1] = CAM_EFFECT_ENC_GRAYSCALE;
    Effect->SupportItem[2] = CAM_EFFECT_ENC_GRAYINV;
    Effect->SupportItem[3] = CAM_EFFECT_ENC_COLORINV;
    Effect->SupportItem[4] = CAM_EFFECT_ENC_SEPIA;
    Effect->SupportItem[5] = CAM_EFFECT_ENC_SEPIABLUE;
    Effect->SupportItem[6] = CAM_EFFECT_ENC_SKETCH;
    Effect->SupportItem[7] = CAM_EFFECT_ENC_EMBOSSMENT;
  }
  else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
  {

    S5K5CAGA_TRACE("[Effect] = %d", In->FeatureSetValue);
    
    S5K5CAGASensor.Effect = In->FeatureSetValue;

    CamWriteCmosSensor(0xFCFC, 0xD000); 
	CamWriteCmosSensor(0x0028, 0x7000);
	CamWriteCmosSensor(0x002a, 0x021e);
	switch (S5K5CAGASensor.Effect)
	{
		case CAM_EFFECT_ENC_NORMAL:
			CamWriteCmosSensor(0x0F12, 0x0000); // Normal, 
			break;
		case CAM_EFFECT_ENC_GRAYSCALE:
			CamWriteCmosSensor(0x0F12, 0x0001); // Monochrome (Black & White)
			break;
        case CAM_EFFECT_ENC_GRAYINV:
			CamWriteCmosSensor(0x0F12, 0x0002); // Negative Mono
			break;
        case CAM_EFFECT_ENC_COLORINV:
			CamWriteCmosSensor(0x0F12, 0x0003); // Negative Color
			break;
		case CAM_EFFECT_ENC_SEPIA:
			CamWriteCmosSensor(0x0F12, 0x0004); // Sepia
			break;
		case CAM_EFFECT_ENC_SEPIABLUE:
			CamWriteCmosSensor(0x0F12, 0x0005); // Aqua (Sepia Blue)
			break;
		case CAM_EFFECT_ENC_SKETCH:
			CamWriteCmosSensor(0x0F12, 0x0006); // Sketch
			break; 
        case CAM_EFFECT_ENC_EMBOSSMENT:
            CamWriteCmosSensor(0x0F12, 0x0008); // Emboss Mono
            break;
		default:
			return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
	}
  	}
 
  return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAInitialSetting
*
* DESCRIPTION
*    This function initialize the registers of CMOS sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAInitialSetting(void)
{
    //=======================================================================================
    //# ARM GO																																								
    //# Direct mode																																						
    //=======================================================================================
    CamWriteCmosSensor(0xFCFC, 0xD000);																												
    CamWriteCmosSensor(0x0010, 0x0001); // Reset 																							
    CamWriteCmosSensor(0x1030, 0x0000); // Clear host interrupt so main will wait							
    CamWriteCmosSensor(0x0014, 0x0001); // ARM go																							
    kal_sleep_task(4);      // Actually delay 13.845ms , 10ms delay is enough for ARM go
    
    //=======================================================================================
    // Start T&P part																																					
    // DO NOT DELETE T&P SECTION COMMENTS! They are required to debug T&P related issues.			
    // svn://transrdsrv/svn/svnroot/System/Software/tcevb/SDK+FW/ISP_5CA/Firmware							
    // Rev: 33047-33047																																				
    // Signature:																																							
    // md5 6254dfca66adca40485075c9b910ba19 .btp 																							
    // md5 cfb4ae7a2d8ae0084b859906a6b2a12c .htp 																							
    // md5 eef3c9ff422110ae87ecc792a436d69e .RegsMap.h																				
    // md5 e18c15b6de4bae04b1e75aef7c2317ea .RegsMap.bin 																			
    // md5 506b4144bd48cdb79cbecdda4f7176ba .base.RegsMap.h																		
    // md5 fd8f92f13566c1a788746b23691c5f5f .base.RegsMap.bin																	
    //=======================================================================================
    CamWriteCmosSensor(0x0028, 0x7000); 
    CamWriteCmosSensor(0x002A, 0x2CF8); 
    CamWriteCmosSensor(0x0F12, 0xB510); 
    CamWriteCmosSensor(0x0F12, 0x4827); 
    CamWriteCmosSensor(0x0F12, 0x21C0); 
    CamWriteCmosSensor(0x0F12, 0x8041); 
    CamWriteCmosSensor(0x0F12, 0x4825); 
    CamWriteCmosSensor(0x0F12, 0x4A26); 
    CamWriteCmosSensor(0x0F12, 0x3020); 
    CamWriteCmosSensor(0x0F12, 0x8382); 
    CamWriteCmosSensor(0x0F12, 0x1D12); 
    CamWriteCmosSensor(0x0F12, 0x83C2); 
    CamWriteCmosSensor(0x0F12, 0x4822); 
    CamWriteCmosSensor(0x0F12, 0x3040); 
    CamWriteCmosSensor(0x0F12, 0x8041); 
    CamWriteCmosSensor(0x0F12, 0x4821); 
    CamWriteCmosSensor(0x0F12, 0x4922); 
    CamWriteCmosSensor(0x0F12, 0x3060); 
    CamWriteCmosSensor(0x0F12, 0x8381); 
    CamWriteCmosSensor(0x0F12, 0x1D09); 
    CamWriteCmosSensor(0x0F12, 0x83C1); 
    CamWriteCmosSensor(0x0F12, 0x4821); 
    CamWriteCmosSensor(0x0F12, 0x491D); 
    CamWriteCmosSensor(0x0F12, 0x8802); 
    CamWriteCmosSensor(0x0F12, 0x3980); 
    CamWriteCmosSensor(0x0F12, 0x804A); 
    CamWriteCmosSensor(0x0F12, 0x8842); 
    CamWriteCmosSensor(0x0F12, 0x808A); 
    CamWriteCmosSensor(0x0F12, 0x8882); 
    CamWriteCmosSensor(0x0F12, 0x80CA); 
    CamWriteCmosSensor(0x0F12, 0x88C2); 
    CamWriteCmosSensor(0x0F12, 0x810A); 
    CamWriteCmosSensor(0x0F12, 0x8902); 
    CamWriteCmosSensor(0x0F12, 0x491C); 
    CamWriteCmosSensor(0x0F12, 0x80CA); 
    CamWriteCmosSensor(0x0F12, 0x8942); 
    CamWriteCmosSensor(0x0F12, 0x814A); 
    CamWriteCmosSensor(0x0F12, 0x8982); 
    CamWriteCmosSensor(0x0F12, 0x830A); 
    CamWriteCmosSensor(0x0F12, 0x89C2); 
    CamWriteCmosSensor(0x0F12, 0x834A); 
    CamWriteCmosSensor(0x0F12, 0x8A00); 
    CamWriteCmosSensor(0x0F12, 0x4918); 
    CamWriteCmosSensor(0x0F12, 0x8188); 
    CamWriteCmosSensor(0x0F12, 0x4918); 
    CamWriteCmosSensor(0x0F12, 0x4819); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xFA0E); 
    CamWriteCmosSensor(0x0F12, 0x4918); 
    CamWriteCmosSensor(0x0F12, 0x4819); 
    CamWriteCmosSensor(0x0F12, 0x6341); 
    CamWriteCmosSensor(0x0F12, 0x4919); 
    CamWriteCmosSensor(0x0F12, 0x4819); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xFA07); 
    CamWriteCmosSensor(0x0F12, 0x4816); 
    CamWriteCmosSensor(0x0F12, 0x4918); 
    CamWriteCmosSensor(0x0F12, 0x3840); 
    CamWriteCmosSensor(0x0F12, 0x62C1); 
    CamWriteCmosSensor(0x0F12, 0x4918); 
    CamWriteCmosSensor(0x0F12, 0x3880); 
    CamWriteCmosSensor(0x0F12, 0x63C1); 
    CamWriteCmosSensor(0x0F12, 0x4917); 
    CamWriteCmosSensor(0x0F12, 0x6301); 
    CamWriteCmosSensor(0x0F12, 0x4917); 
    CamWriteCmosSensor(0x0F12, 0x3040); 
    CamWriteCmosSensor(0x0F12, 0x6181); 
    CamWriteCmosSensor(0x0F12, 0x4917); 
    CamWriteCmosSensor(0x0F12, 0x4817); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9F7); 
    CamWriteCmosSensor(0x0F12, 0x4917); 
    CamWriteCmosSensor(0x0F12, 0x4817); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9F3); 
    CamWriteCmosSensor(0x0F12, 0x4917); 
    CamWriteCmosSensor(0x0F12, 0x4817); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9EF); 
    CamWriteCmosSensor(0x0F12, 0xBC10); 
    CamWriteCmosSensor(0x0F12, 0xBC08); 
    CamWriteCmosSensor(0x0F12, 0x4718); 
    CamWriteCmosSensor(0x0F12, 0x1100); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x267C); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x2CE8); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x3274); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xF400); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0xF520); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x2DF1); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x89A9); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x2E43); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x0140); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2E7D); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xB4F7); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x2F07); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2F2B); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2FD1); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2FE5); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2FB9); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x013D); 
    CamWriteCmosSensor(0x0F12, 0x0001); 
    CamWriteCmosSensor(0x0F12, 0x306B); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x5823); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x30B9); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xD789); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0xB570); 
    CamWriteCmosSensor(0x0F12, 0x6804); 
    CamWriteCmosSensor(0x0F12, 0x6845); 
    CamWriteCmosSensor(0x0F12, 0x6881); 
    CamWriteCmosSensor(0x0F12, 0x6840); 
    CamWriteCmosSensor(0x0F12, 0x2900); 
    CamWriteCmosSensor(0x0F12, 0x6880); 
    CamWriteCmosSensor(0x0F12, 0xD007); 
    CamWriteCmosSensor(0x0F12, 0x49C3); 
    CamWriteCmosSensor(0x0F12, 0x8949); 
    CamWriteCmosSensor(0x0F12, 0x084A); 
    CamWriteCmosSensor(0x0F12, 0x1880); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9BA); 
    CamWriteCmosSensor(0x0F12, 0x80A0); 
    CamWriteCmosSensor(0x0F12, 0xE000); 
    CamWriteCmosSensor(0x0F12, 0x80A0); 
    CamWriteCmosSensor(0x0F12, 0x88A0); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD010); 
    CamWriteCmosSensor(0x0F12, 0x68A9); 
    CamWriteCmosSensor(0x0F12, 0x6828); 
    CamWriteCmosSensor(0x0F12, 0x084A); 
    CamWriteCmosSensor(0x0F12, 0x1880); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9AE); 
    CamWriteCmosSensor(0x0F12, 0x8020); 
    CamWriteCmosSensor(0x0F12, 0x1D2D); 
    CamWriteCmosSensor(0x0F12, 0xCD03); 
    CamWriteCmosSensor(0x0F12, 0x084A); 
    CamWriteCmosSensor(0x0F12, 0x1880); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9A7); 
    CamWriteCmosSensor(0x0F12, 0x8060); 
    CamWriteCmosSensor(0x0F12, 0xBC70); 
    CamWriteCmosSensor(0x0F12, 0xBC08); 
    CamWriteCmosSensor(0x0F12, 0x4718); 
    CamWriteCmosSensor(0x0F12, 0x2000); 
    CamWriteCmosSensor(0x0F12, 0x8060); 
    CamWriteCmosSensor(0x0F12, 0x8020); 
    CamWriteCmosSensor(0x0F12, 0xE7F8); 
    CamWriteCmosSensor(0x0F12, 0xB510); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF9A2); 
    CamWriteCmosSensor(0x0F12, 0x48B2); 
    CamWriteCmosSensor(0x0F12, 0x8A40); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD00C); 
    CamWriteCmosSensor(0x0F12, 0x48B1); 
    CamWriteCmosSensor(0x0F12, 0x49B2); 
    CamWriteCmosSensor(0x0F12, 0x8800); 
    CamWriteCmosSensor(0x0F12, 0x4AB2); 
    CamWriteCmosSensor(0x0F12, 0x2805); 
    CamWriteCmosSensor(0x0F12, 0xD003); 
    CamWriteCmosSensor(0x0F12, 0x4BB1); 
    CamWriteCmosSensor(0x0F12, 0x795B); 
    CamWriteCmosSensor(0x0F12, 0x2B00); 
    CamWriteCmosSensor(0x0F12, 0xD005); 
    CamWriteCmosSensor(0x0F12, 0x2001); 
    CamWriteCmosSensor(0x0F12, 0x8008); 
    CamWriteCmosSensor(0x0F12, 0x8010); 
    CamWriteCmosSensor(0x0F12, 0xBC10); 
    CamWriteCmosSensor(0x0F12, 0xBC08); 
    CamWriteCmosSensor(0x0F12, 0x4718); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD1FA); 
    CamWriteCmosSensor(0x0F12, 0x2000); 
    CamWriteCmosSensor(0x0F12, 0x8008); 
    CamWriteCmosSensor(0x0F12, 0x8010); 
    CamWriteCmosSensor(0x0F12, 0xE7F6); 
    CamWriteCmosSensor(0x0F12, 0xB5F8); 
    CamWriteCmosSensor(0x0F12, 0x2407); 
    CamWriteCmosSensor(0x0F12, 0x2C06); 
    CamWriteCmosSensor(0x0F12, 0xD035); 
    CamWriteCmosSensor(0x0F12, 0x2C07); 
    CamWriteCmosSensor(0x0F12, 0xD033); 
    CamWriteCmosSensor(0x0F12, 0x48A3); 
    CamWriteCmosSensor(0x0F12, 0x8BC1); 
    CamWriteCmosSensor(0x0F12, 0x2900); 
    CamWriteCmosSensor(0x0F12, 0xD02A); 
    CamWriteCmosSensor(0x0F12, 0x00A2); 
    CamWriteCmosSensor(0x0F12, 0x1815); 
    CamWriteCmosSensor(0x0F12, 0x4AA4); 
    CamWriteCmosSensor(0x0F12, 0x6DEE); 
    CamWriteCmosSensor(0x0F12, 0x8A92); 
    CamWriteCmosSensor(0x0F12, 0x4296); 
    CamWriteCmosSensor(0x0F12, 0xD923); 
    CamWriteCmosSensor(0x0F12, 0x0028); 
    CamWriteCmosSensor(0x0F12, 0x3080); 
    CamWriteCmosSensor(0x0F12, 0x0007); 
    CamWriteCmosSensor(0x0F12, 0x69C0); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF96B); 
    CamWriteCmosSensor(0x0F12, 0x1C71); 
    CamWriteCmosSensor(0x0F12, 0x0280); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF967); 
    CamWriteCmosSensor(0x0F12, 0x0006); 
    CamWriteCmosSensor(0x0F12, 0x4898); 
    CamWriteCmosSensor(0x0F12, 0x0061); 
    CamWriteCmosSensor(0x0F12, 0x1808); 
    CamWriteCmosSensor(0x0F12, 0x8D80); 
    CamWriteCmosSensor(0x0F12, 0x0A01); 
    CamWriteCmosSensor(0x0F12, 0x0600); 
    CamWriteCmosSensor(0x0F12, 0x0E00); 
    CamWriteCmosSensor(0x0F12, 0x1A08); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF96A); 
    CamWriteCmosSensor(0x0F12, 0x0002); 
    CamWriteCmosSensor(0x0F12, 0x6DE9); 
    CamWriteCmosSensor(0x0F12, 0x6FE8); 
    CamWriteCmosSensor(0x0F12, 0x1A08); 
    CamWriteCmosSensor(0x0F12, 0x4351); 
    CamWriteCmosSensor(0x0F12, 0x0300); 
    CamWriteCmosSensor(0x0F12, 0x1C49); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF953); 
    CamWriteCmosSensor(0x0F12, 0x0401); 
    CamWriteCmosSensor(0x0F12, 0x0430); 
    CamWriteCmosSensor(0x0F12, 0x0C00); 
    CamWriteCmosSensor(0x0F12, 0x4301); 
    CamWriteCmosSensor(0x0F12, 0x61F9); 
    CamWriteCmosSensor(0x0F12, 0xE004); 
    CamWriteCmosSensor(0x0F12, 0x00A2); 
    CamWriteCmosSensor(0x0F12, 0x4990); 
    CamWriteCmosSensor(0x0F12, 0x1810); 
    CamWriteCmosSensor(0x0F12, 0x3080); 
    CamWriteCmosSensor(0x0F12, 0x61C1); 
    CamWriteCmosSensor(0x0F12, 0x1E64); 
    CamWriteCmosSensor(0x0F12, 0xD2C5); 
    CamWriteCmosSensor(0x0F12, 0x2006); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF959); 
    CamWriteCmosSensor(0x0F12, 0x2007); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF956); 
    CamWriteCmosSensor(0x0F12, 0xBCF8); 
    CamWriteCmosSensor(0x0F12, 0xBC08); 
    CamWriteCmosSensor(0x0F12, 0x4718); 
    CamWriteCmosSensor(0x0F12, 0xB510); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF958); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD00A); 
    CamWriteCmosSensor(0x0F12, 0x4881); 
    CamWriteCmosSensor(0x0F12, 0x8B81); 
    CamWriteCmosSensor(0x0F12, 0x0089); 
    CamWriteCmosSensor(0x0F12, 0x1808); 
    CamWriteCmosSensor(0x0F12, 0x6DC1); 
    CamWriteCmosSensor(0x0F12, 0x4883); 
    CamWriteCmosSensor(0x0F12, 0x8A80); 
    CamWriteCmosSensor(0x0F12, 0x4281); 
    CamWriteCmosSensor(0x0F12, 0xD901); 
    CamWriteCmosSensor(0x0F12, 0x2001); 
    CamWriteCmosSensor(0x0F12, 0xE7A1); 
    CamWriteCmosSensor(0x0F12, 0x2000); 
    CamWriteCmosSensor(0x0F12, 0xE79F); 
    CamWriteCmosSensor(0x0F12, 0xB5F8); 
    CamWriteCmosSensor(0x0F12, 0x0004); 
    CamWriteCmosSensor(0x0F12, 0x4F80); 
    CamWriteCmosSensor(0x0F12, 0x227D); 
    CamWriteCmosSensor(0x0F12, 0x8938); 
    CamWriteCmosSensor(0x0F12, 0x0152); 
    CamWriteCmosSensor(0x0F12, 0x4342); 
    CamWriteCmosSensor(0x0F12, 0x487E); 
    CamWriteCmosSensor(0x0F12, 0x9000); 
    CamWriteCmosSensor(0x0F12, 0x8A01); 
    CamWriteCmosSensor(0x0F12, 0x0848); 
    CamWriteCmosSensor(0x0F12, 0x1810); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF91D); 
    CamWriteCmosSensor(0x0F12, 0x210F); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF940); 
    CamWriteCmosSensor(0x0F12, 0x497A); 
    CamWriteCmosSensor(0x0F12, 0x8C49); 
    CamWriteCmosSensor(0x0F12, 0x090E); 
    CamWriteCmosSensor(0x0F12, 0x0136); 
    CamWriteCmosSensor(0x0F12, 0x4306); 
    CamWriteCmosSensor(0x0F12, 0x4979); 
    CamWriteCmosSensor(0x0F12, 0x2C00); 
    CamWriteCmosSensor(0x0F12, 0xD003); 
    CamWriteCmosSensor(0x0F12, 0x2001); 
    CamWriteCmosSensor(0x0F12, 0x0240); 
    CamWriteCmosSensor(0x0F12, 0x4330); 
    CamWriteCmosSensor(0x0F12, 0x8108); 
    CamWriteCmosSensor(0x0F12, 0x4876); 
    CamWriteCmosSensor(0x0F12, 0x2C00); 
    CamWriteCmosSensor(0x0F12, 0x8D00); 
    CamWriteCmosSensor(0x0F12, 0xD001); 
    CamWriteCmosSensor(0x0F12, 0x2501); 
    CamWriteCmosSensor(0x0F12, 0xE000); 
    CamWriteCmosSensor(0x0F12, 0x2500); 
    CamWriteCmosSensor(0x0F12, 0x4972); 
    CamWriteCmosSensor(0x0F12, 0x4328); 
    CamWriteCmosSensor(0x0F12, 0x8008); 
    CamWriteCmosSensor(0x0F12, 0x207D); 
    CamWriteCmosSensor(0x0F12, 0x00C0); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF92E); 
    CamWriteCmosSensor(0x0F12, 0x2C00); 
    CamWriteCmosSensor(0x0F12, 0x496E); 
    CamWriteCmosSensor(0x0F12, 0x0328); 
    CamWriteCmosSensor(0x0F12, 0x4330); 
    CamWriteCmosSensor(0x0F12, 0x8108); 
    CamWriteCmosSensor(0x0F12, 0x88F8); 
    CamWriteCmosSensor(0x0F12, 0x2C00); 
    CamWriteCmosSensor(0x0F12, 0x01AA); 
    CamWriteCmosSensor(0x0F12, 0x4310); 
    CamWriteCmosSensor(0x0F12, 0x8088); 
    CamWriteCmosSensor(0x0F12, 0x9800); 
    CamWriteCmosSensor(0x0F12, 0x8A01); 
    CamWriteCmosSensor(0x0F12, 0x486A); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8F1); 
    CamWriteCmosSensor(0x0F12, 0x496A); 
    CamWriteCmosSensor(0x0F12, 0x8809); 
    CamWriteCmosSensor(0x0F12, 0x4348); 
    CamWriteCmosSensor(0x0F12, 0x0400); 
    CamWriteCmosSensor(0x0F12, 0x0C00); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF918); 
    CamWriteCmosSensor(0x0F12, 0x0020); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF91D); 
    CamWriteCmosSensor(0x0F12, 0x4866); 
    CamWriteCmosSensor(0x0F12, 0x7004); 
    CamWriteCmosSensor(0x0F12, 0xE7A3); 
    CamWriteCmosSensor(0x0F12, 0xB510); 
    CamWriteCmosSensor(0x0F12, 0x0004); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF91E); 
    CamWriteCmosSensor(0x0F12, 0x6020); 
    CamWriteCmosSensor(0x0F12, 0x4963); 
    CamWriteCmosSensor(0x0F12, 0x8B49); 
    CamWriteCmosSensor(0x0F12, 0x0789); 
    CamWriteCmosSensor(0x0F12, 0xD001); 
    CamWriteCmosSensor(0x0F12, 0x0040); 
    CamWriteCmosSensor(0x0F12, 0x6020); 
    CamWriteCmosSensor(0x0F12, 0xE74C); 
    CamWriteCmosSensor(0x0F12, 0xB510); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF91B); 
    CamWriteCmosSensor(0x0F12, 0x485F); 
    CamWriteCmosSensor(0x0F12, 0x8880); 
    CamWriteCmosSensor(0x0F12, 0x0601); 
    CamWriteCmosSensor(0x0F12, 0x4854); 
    CamWriteCmosSensor(0x0F12, 0x1609); 
    CamWriteCmosSensor(0x0F12, 0x8141); 
    CamWriteCmosSensor(0x0F12, 0xE742); 
    CamWriteCmosSensor(0x0F12, 0xB5F8); 
    CamWriteCmosSensor(0x0F12, 0x000F); 
    CamWriteCmosSensor(0x0F12, 0x4C55); 
    CamWriteCmosSensor(0x0F12, 0x3420); 
    CamWriteCmosSensor(0x0F12, 0x2500); 
    CamWriteCmosSensor(0x0F12, 0x5765); 
    CamWriteCmosSensor(0x0F12, 0x0039); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF913); 
    CamWriteCmosSensor(0x0F12, 0x9000); 
    CamWriteCmosSensor(0x0F12, 0x2600); 
    CamWriteCmosSensor(0x0F12, 0x57A6); 
    CamWriteCmosSensor(0x0F12, 0x4C4C); 
    CamWriteCmosSensor(0x0F12, 0x42AE); 
    CamWriteCmosSensor(0x0F12, 0xD01B); 
    CamWriteCmosSensor(0x0F12, 0x4D54); 
    CamWriteCmosSensor(0x0F12, 0x8AE8); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD013); 
    CamWriteCmosSensor(0x0F12, 0x484D); 
    CamWriteCmosSensor(0x0F12, 0x8A01); 
    CamWriteCmosSensor(0x0F12, 0x8B80); 
    CamWriteCmosSensor(0x0F12, 0x4378); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8B5); 
    CamWriteCmosSensor(0x0F12, 0x89A9); 
    CamWriteCmosSensor(0x0F12, 0x1A41); 
    CamWriteCmosSensor(0x0F12, 0x484E); 
    CamWriteCmosSensor(0x0F12, 0x3820); 
    CamWriteCmosSensor(0x0F12, 0x8AC0); 
    CamWriteCmosSensor(0x0F12, 0x4348); 
    CamWriteCmosSensor(0x0F12, 0x17C1); 
    CamWriteCmosSensor(0x0F12, 0x0D89); 
    CamWriteCmosSensor(0x0F12, 0x1808); 
    CamWriteCmosSensor(0x0F12, 0x1280); 
    CamWriteCmosSensor(0x0F12, 0x8961); 
    CamWriteCmosSensor(0x0F12, 0x1A08); 
    CamWriteCmosSensor(0x0F12, 0x8160); 
    CamWriteCmosSensor(0x0F12, 0xE003); 
    CamWriteCmosSensor(0x0F12, 0x88A8); 
    CamWriteCmosSensor(0x0F12, 0x0600); 
    CamWriteCmosSensor(0x0F12, 0x1600); 
    CamWriteCmosSensor(0x0F12, 0x8160); 
    CamWriteCmosSensor(0x0F12, 0x200A); 
    CamWriteCmosSensor(0x0F12, 0x5E20); 
    CamWriteCmosSensor(0x0F12, 0x42B0); 
    CamWriteCmosSensor(0x0F12, 0xD011); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8AB); 
    CamWriteCmosSensor(0x0F12, 0x1D40); 
    CamWriteCmosSensor(0x0F12, 0x00C3); 
    CamWriteCmosSensor(0x0F12, 0x1A18); 
    CamWriteCmosSensor(0x0F12, 0x214B); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF897); 
    CamWriteCmosSensor(0x0F12, 0x211F); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8BA); 
    CamWriteCmosSensor(0x0F12, 0x210A); 
    CamWriteCmosSensor(0x0F12, 0x5E61); 
    CamWriteCmosSensor(0x0F12, 0x0FC9); 
    CamWriteCmosSensor(0x0F12, 0x0149); 
    CamWriteCmosSensor(0x0F12, 0x4301); 
    CamWriteCmosSensor(0x0F12, 0x483D); 
    CamWriteCmosSensor(0x0F12, 0x81C1); 
    CamWriteCmosSensor(0x0F12, 0x9800); 
    CamWriteCmosSensor(0x0F12, 0xE74A); 
    CamWriteCmosSensor(0x0F12, 0xB5F1); 
    CamWriteCmosSensor(0x0F12, 0xB082); 
    CamWriteCmosSensor(0x0F12, 0x2500); 
    CamWriteCmosSensor(0x0F12, 0x483A); 
    CamWriteCmosSensor(0x0F12, 0x9001); 
    CamWriteCmosSensor(0x0F12, 0x2400); 
    CamWriteCmosSensor(0x0F12, 0x2028); 
    CamWriteCmosSensor(0x0F12, 0x4368); 
    CamWriteCmosSensor(0x0F12, 0x4A39); 
    CamWriteCmosSensor(0x0F12, 0x4925); 
    CamWriteCmosSensor(0x0F12, 0x1887); 
    CamWriteCmosSensor(0x0F12, 0x1840); 
    CamWriteCmosSensor(0x0F12, 0x9000); 
    CamWriteCmosSensor(0x0F12, 0x9800); 
    CamWriteCmosSensor(0x0F12, 0x0066); 
    CamWriteCmosSensor(0x0F12, 0x9A01); 
    CamWriteCmosSensor(0x0F12, 0x1980); 
    CamWriteCmosSensor(0x0F12, 0x218C); 
    CamWriteCmosSensor(0x0F12, 0x5A09); 
    CamWriteCmosSensor(0x0F12, 0x8A80); 
    CamWriteCmosSensor(0x0F12, 0x8812); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8CA); 
    CamWriteCmosSensor(0x0F12, 0x53B8); 
    CamWriteCmosSensor(0x0F12, 0x1C64); 
    CamWriteCmosSensor(0x0F12, 0x2C14); 
    CamWriteCmosSensor(0x0F12, 0xDBF1); 
    CamWriteCmosSensor(0x0F12, 0x1C6D); 
    CamWriteCmosSensor(0x0F12, 0x2D03); 
    CamWriteCmosSensor(0x0F12, 0xDBE6); 
    CamWriteCmosSensor(0x0F12, 0x9802); 
    CamWriteCmosSensor(0x0F12, 0x6800); 
    CamWriteCmosSensor(0x0F12, 0x0600); 
    CamWriteCmosSensor(0x0F12, 0x0E00); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8C5); 
    CamWriteCmosSensor(0x0F12, 0xBCFE); 
    CamWriteCmosSensor(0x0F12, 0xBC08); 
    CamWriteCmosSensor(0x0F12, 0x4718); 
    CamWriteCmosSensor(0x0F12, 0xB570); 
    CamWriteCmosSensor(0x0F12, 0x6805); 
    CamWriteCmosSensor(0x0F12, 0x2404); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8C5); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD103); 
    CamWriteCmosSensor(0x0F12, 0xF000); 
    CamWriteCmosSensor(0x0F12, 0xF8C9); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x2400); 
    CamWriteCmosSensor(0x0F12, 0x3540); 
    CamWriteCmosSensor(0x0F12, 0x88E8); 
    CamWriteCmosSensor(0x0F12, 0x0500); 
    CamWriteCmosSensor(0x0F12, 0xD403); 
    CamWriteCmosSensor(0x0F12, 0x4822); 
    CamWriteCmosSensor(0x0F12, 0x89C0); 
    CamWriteCmosSensor(0x0F12, 0x2800); 
    CamWriteCmosSensor(0x0F12, 0xD002); 
    CamWriteCmosSensor(0x0F12, 0x2008); 
    CamWriteCmosSensor(0x0F12, 0x4304); 
    CamWriteCmosSensor(0x0F12, 0xE001); 
    CamWriteCmosSensor(0x0F12, 0x2010); 
    CamWriteCmosSensor(0x0F12, 0x4304); 
    CamWriteCmosSensor(0x0F12, 0x481F); 
    CamWriteCmosSensor(0x0F12, 0x8B80); 
    CamWriteCmosSensor(0x0F12, 0x0700); 
    CamWriteCmosSensor(0x0F12, 0x0F81); 
    CamWriteCmosSensor(0x0F12, 0x2001); 
    CamWriteCmosSensor(0x0F12, 0x2900); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x4304); 
    CamWriteCmosSensor(0x0F12, 0x491C); 
    CamWriteCmosSensor(0x0F12, 0x8B0A); 
    CamWriteCmosSensor(0x0F12, 0x42A2); 
    CamWriteCmosSensor(0x0F12, 0xD004); 
    CamWriteCmosSensor(0x0F12, 0x0762); 
    CamWriteCmosSensor(0x0F12, 0xD502); 
    CamWriteCmosSensor(0x0F12, 0x4A19); 
    CamWriteCmosSensor(0x0F12, 0x3220); 
    CamWriteCmosSensor(0x0F12, 0x8110); 
    CamWriteCmosSensor(0x0F12, 0x830C); 
    CamWriteCmosSensor(0x0F12, 0xE691); 
    CamWriteCmosSensor(0x0F12, 0x0C3C); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x3274); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x26E8); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x6100); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x6500); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x1A7C); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x1120); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xFFFF); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x3374); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x1D6C); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x167C); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xF400); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x2C2C); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x40A0); 
    CamWriteCmosSensor(0x0F12, 0x00DD); 
    CamWriteCmosSensor(0x0F12, 0xF520); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x2C29); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x1A54); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x1564); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xF2A0); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x2440); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x05A0); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x2894); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0x1224); 
    CamWriteCmosSensor(0x0F12, 0x7000); 
    CamWriteCmosSensor(0x0F12, 0xB000); 
    CamWriteCmosSensor(0x0F12, 0xD000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x1A3F); 
    CamWriteCmosSensor(0x0F12, 0x0001); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xF004); 
    CamWriteCmosSensor(0x0F12, 0xE51F); 
    CamWriteCmosSensor(0x0F12, 0x1F48); 
    CamWriteCmosSensor(0x0F12, 0x0001); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x24BD); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x36DD); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xB4CF); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xB5D7); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x36ED); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xF53F); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xF5D9); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x013D); 
    CamWriteCmosSensor(0x0F12, 0x0001); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xF5C9); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xFAA9); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x3723); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0x5823); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xD771); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x4778); 
    CamWriteCmosSensor(0x0F12, 0x46C0); 
    CamWriteCmosSensor(0x0F12, 0xC000); 
    CamWriteCmosSensor(0x0F12, 0xE59F); 
    CamWriteCmosSensor(0x0F12, 0xFF1C); 
    CamWriteCmosSensor(0x0F12, 0xE12F); 
    CamWriteCmosSensor(0x0F12, 0xD75B); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    CamWriteCmosSensor(0x0F12, 0x8117); 
    CamWriteCmosSensor(0x0F12, 0x0000); 
    // //================================ ===================================================  
    // // Parameters Defined in T&P: 																													
    // // Mon_SARR_usGammaLutRGBInterpolate		  120 700005A0 ARRAY														
    // // Mon_SARR_usGammaLutRGBInterpolate[0][0]	   2 700005A0 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][1]	   2 700005A2 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][2]	   2 700005A4 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][3]	   2 700005A6 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][4]	   2 700005A8 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][5]	   2 700005AA SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][6]	   2 700005AC SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][7]	   2 700005AE SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][8]	   2 700005B0 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][9]	   2 700005B2 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[0][10]	2 700005B4 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][11]	2 700005B6 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][12]	2 700005B8 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][13]	2 700005BA SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][14]	2 700005BC SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][15]	2 700005BE SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][16]	2 700005C0 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][17]	2 700005C2 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][18]	2 700005C4 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[0][19]	2 700005C6 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][0]	   2 700005C8 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][1]	   2 700005CA SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][2]	   2 700005CC SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][3]	   2 700005CE SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][4]	   2 700005D0 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][5]	   2 700005D2 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][6]	   2 700005D4 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][7]	   2 700005D6 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][8]	   2 700005D8 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][9]	   2 700005DA SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[1][10]	2 700005DC SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][11]	2 700005DE SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][12]	2 700005E0 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][13]	2 700005E2 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][14]	2 700005E4 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][15]	2 700005E6 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][16]	2 700005E8 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][17]	2 700005EA SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][18]	2 700005EC SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[1][19]	2 700005EE SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][0]	   2 700005F0 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][1]	   2 700005F2 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][2]	   2 700005F4 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][3]	   2 700005F6 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][4]	   2 700005F8 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][5]	   2 700005FA SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][6]	   2 700005FC SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][7]	   2 700005FE SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][8]	   2 70000600 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][9]	   2 70000602 SHORT 												
    // // Mon_SARR_usGammaLutRGBInterpolate[2][10]	2 70000604 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][11]	2 70000606 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][12]	2 70000608 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][13]	2 7000060A SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][14]	2 7000060C SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][15]	2 7000060E SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][16]	2 70000610 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][17]	2 70000612 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][18]	2 70000614 SHORT													
    // // Mon_SARR_usGammaLutRGBInterpolate[2][19]	2 70000616 SHORT													
    // // TnP_SvnVersion 						2 7000326C SHORT																					
    // // Tune_TP							  268 70003274 STRUCT																						
    // // Tune_TP_IO_DrivingCurrent_D0_D4_cs10		2 70003274 SHORT														
    // // Tune_TP_IO_DrivingCurrent_D9_D5_cs10		2 70003276 SHORT														
    // // Tune_TP_IO_DrivingCurrent_GPIO_cd10	   2 70003278 SHORT 														
    // // Tune_TP_IO_DrivingCurrent_CLKs_cd10	   2 7000327A SHORT 														
    // // Tune_TP_atop_dblr_reg_1				   2 7000327C SHORT 																	
    // // Tune_TP_atop_dblr_reg_3				   2 7000327E SHORT 																	
    // // Tune_TP_atop_ramp_reg_1				   2 70003280 SHORT 																	
    // // Tune_TP_atop_ramp_reg_2				   2 70003282 SHORT 																	
    // // Tune_TP_atop_rmp_offset_sig			   2 70003284 SHORT 																
    // // Tune_TP_bEnablePrePostGammaAfControl		2 70003286 SHORT														
    // // Tune_TP_seti						   240 70003288 STRUCT																			
    // // SARR_usDualGammaLutRGBIndoor			  120 70003288 ARRAY															
    // // SARR_usDualGammaLutRGBIndoor[0][0] 	   2 70003288 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][1] 	   2 7000328A SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][2] 	   2 7000328C SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][3] 	   2 7000328E SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][4] 	   2 70003290 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][5] 	   2 70003292 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][6] 	   2 70003294 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][7] 	   2 70003296 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][8] 	   2 70003298 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][9] 	   2 7000329A SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][10]	   2 7000329C SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][11]	   2 7000329E SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][12]	   2 700032A0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][13]	   2 700032A2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][14]	   2 700032A4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][15]	   2 700032A6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][16]	   2 700032A8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][17]	   2 700032AA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][18]	   2 700032AC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[0][19]	   2 700032AE SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][0] 	   2 700032B0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][1] 	   2 700032B2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][2] 	   2 700032B4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][3] 	   2 700032B6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][4] 	   2 700032B8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][5] 	   2 700032BA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][6] 	   2 700032BC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][7] 	   2 700032BE SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][8] 	   2 700032C0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][9] 	   2 700032C2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][10]	   2 700032C4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][11]	   2 700032C6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][12]	   2 700032C8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][13]	   2 700032CA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][14]	   2 700032CC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][15]	   2 700032CE SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][16]	   2 700032D0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][17]	   2 700032D2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][18]	   2 700032D4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[1][19]	   2 700032D6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][0] 	   2 700032D8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][1] 	   2 700032DA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][2] 	   2 700032DC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][3] 	   2 700032DE SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][4] 	   2 700032E0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][5] 	   2 700032E2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][6] 	   2 700032E4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][7] 	   2 700032E6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][8] 	   2 700032E8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][9] 	   2 700032EA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][10]	   2 700032EC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][11]	   2 700032EE SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][12]	   2 700032F0 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][13]	   2 700032F2 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][14]	   2 700032F4 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][15]	   2 700032F6 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][16]	   2 700032F8 SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][17]	   2 700032FA SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][18]	   2 700032FC SHORT 														
    // // SARR_usDualGammaLutRGBIndoor[2][19]	   2 700032FE SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor			  120 70003300 ARRAY															
    // // SARR_usDualGammaLutRGBOutdoor[0][0]	   2 70003300 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][1]	   2 70003302 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][2]	   2 70003304 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][3]	   2 70003306 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][4]	   2 70003308 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][5]	   2 7000330A SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][6]	   2 7000330C SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][7]	   2 7000330E SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][8]	   2 70003310 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][9]	   2 70003312 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[0][10]		2 70003314 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][11]		2 70003316 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][12]		2 70003318 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][13]		2 7000331A SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][14]		2 7000331C SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][15]		2 7000331E SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][16]		2 70003320 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][17]		2 70003322 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][18]		2 70003324 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[0][19]		2 70003326 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][0]	   2 70003328 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][1]	   2 7000332A SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][2]	   2 7000332C SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][3]	   2 7000332E SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][4]	   2 70003330 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][5]	   2 70003332 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][6]	   2 70003334 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][7]	   2 70003336 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][8]	   2 70003338 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][9]	   2 7000333A SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[1][10]		2 7000333C SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][11]		2 7000333E SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][12]		2 70003340 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][13]		2 70003342 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][14]		2 70003344 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][15]		2 70003346 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][16]		2 70003348 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][17]		2 7000334A SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][18]		2 7000334C SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[1][19]		2 7000334E SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][0]	   2 70003350 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][1]	   2 70003352 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][2]	   2 70003354 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][3]	   2 70003356 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][4]	   2 70003358 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][5]	   2 7000335A SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][6]	   2 7000335C SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][7]	   2 7000335E SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][8]	   2 70003360 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][9]	   2 70003362 SHORT 														
    // // SARR_usDualGammaLutRGBOutdoor[2][10]		2 70003364 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][11]		2 70003366 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][12]		2 70003368 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][13]		2 7000336A SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][14]		2 7000336C SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][15]		2 7000336E SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][16]		2 70003370 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][17]		2 70003372 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][18]		2 70003374 SHORT														
    // // SARR_usDualGammaLutRGBOutdoor[2][19]		2 70003376 SHORT														
    // // Tune_TP_reserved						2 70003378 SHORT																				
    // // Tune_TP_atop_dbus_reg					2 7000337A SHORT																			
    // // Tune_TP_dblr_base_freq_mhz 			   2 7000337C SHORT 																
    // // Tune_TP_GL_sen_sOfs					   2 7000337E SHORT 																		
    // //																																											
    // // End T&P part																																				
    //========================================================																
    // CIs/APs/An setting		- 400LsB sYsCLK 32MHz																							
    //========================================================																
    // This regis are for FACTORY ONLY. If you change it without prior notification, 					
    // YOU are REsIBLE for the FAILURE that will happen in the future.												
    //========================================================					
    CamWriteCmosSensor(0x002A, 0x157A);																												
    CamWriteCmosSensor(0x0F12, 0x0001);																												
    CamWriteCmosSensor(0x002A, 0x1578);																												
    CamWriteCmosSensor(0x0F12, 0x0001);																												
    CamWriteCmosSensor(0x002A, 0x1576);																												
    CamWriteCmosSensor(0x0F12, 0x0020);																												
    CamWriteCmosSensor(0x002A, 0x1574);																												
    CamWriteCmosSensor(0x0F12, 0x0006);																												
    CamWriteCmosSensor(0x002A, 0x156E);																												
    CamWriteCmosSensor(0x0F12, 0x0001); // slope calibration tolerance in units of 1/256 			
    CamWriteCmosSensor(0x002A, 0x1568);																												
    CamWriteCmosSensor(0x0F12, 0x00FC);	
    
    //ADC control																																							
    CamWriteCmosSensor(0x002A, 0x155A);																												
    CamWriteCmosSensor(0x0F12, 0x01CC); //ADC sAT of 450mV for 10bit default in EVT1 					
    CamWriteCmosSensor(0x002A, 0x157E);																												
    CamWriteCmosSensor(0x0F12, 0x0C80); // 3200 Max. Reset ramp DCLK counts (default 2048 0x8
    CamWriteCmosSensor(0x0F12, 0x0578); // 1400 Max. Reset ramp DCLK counts for x3.5 					
    CamWriteCmosSensor(0x002A, 0x157C);																												
    CamWriteCmosSensor(0x0F12, 0x0190); // 400 Reset ramp for x1 in DCLK counts								
    CamWriteCmosSensor(0x002A, 0x1570);																												
    CamWriteCmosSensor(0x0F12, 0x00A0); // 160 LsB																						
    CamWriteCmosSensor(0x0F12, 0x0010); // reset threshold																		
    CamWriteCmosSensor(0x002A, 0x12C4);																												
    CamWriteCmosSensor(0x0F12, 0x006A); // 106 additional timing columns.											
    CamWriteCmosSensor(0x002A, 0x12C8);																												
    CamWriteCmosSensor(0x0F12, 0x08AC); // 2220 ADC columns in normal mode including Hold & L
    CamWriteCmosSensor(0x0F12, 0x0050); // 80 addition of ADC columns in Y-ave mode (default 
    CamWriteCmosSensor(0x002A, 0x1696); // based on APs guidelines														
    CamWriteCmosSensor(0x0F12, 0x0000); // based on APs guidelines														
    CamWriteCmosSensor(0x0F12, 0x0000); // default. 1492 used for ADC dark characteristics		
    CamWriteCmosSensor(0x0F12, 0x00C6); // default. 1492 used for ADC dark characteristics		
    CamWriteCmosSensor(0x0F12, 0x00C6);	

    CamWriteCmosSensor(0x002A, 0x12B8); //RED SUN
    // S5K5CAGA_write_cmos_sensor(0x0F12, 0x1000);
    CamWriteCmosSensor(0x0F12, 0x1600);

    CamWriteCmosSensor(0x002A, 0x1690); // when set double sampling is activated - requires d  
    CamWriteCmosSensor(0x0F12, 0x0001);																												
    CamWriteCmosSensor(0x002A, 0x12B0); // comp and pixel bias control 0xF40E - default for E
    CamWriteCmosSensor(0x0F12, 0x0055); // comp and pixel bias control 0xF40E for binning mod
    CamWriteCmosSensor(0x0F12, 0x005A);																												
    CamWriteCmosSensor(0x002A, 0x337A); // [7] - is used for rest-only mode (EVT0 value is 0x
    CamWriteCmosSensor(0x0F12, 0x0006);																												
    CamWriteCmosSensor(0x0F12, 0x0068);																												
    CamWriteCmosSensor(0x002A, 0x169E);																												
    CamWriteCmosSensor(0x0F12, 0x0007);																												
    CamWriteCmosSensor(0x002A, 0x0BF6);																												
    CamWriteCmosSensor(0x0F12, 0x0000);																												
    CamWriteCmosSensor(0x002A, 0x327C);																												
    CamWriteCmosSensor(0x0F12, 0x1000);																												
    CamWriteCmosSensor(0x0F12, 0x6998);																												
    CamWriteCmosSensor(0x0F12, 0x0078);																												
    CamWriteCmosSensor(0x0F12, 0x04FE);																												
    CamWriteCmosSensor(0x0F12, 0x8800);			

    // IO Driving current condig.
    CamWriteCmosSensor(0x002A, 0x3274);		
    /*	0x70003274
	cregs_d0_d4_cd10	R/W [9:8]	d0_4_con_cd10 ? 
								00 ? 2mA
								01 ? 4mA
								10 ? 6mA
								11 ? 8mA
							[7:6]	d0_3_con_cd10 ?
							[5:4]	d0_2_con_cd10 ?
							[3:2]	d0_1_con_cd10 ?
							[1:0]	d0_0_con_cd10 ?
	*/
    CamWriteCmosSensor(0x0F12, 0x0155); //set IO driving current 2mA for Gs500	
    /*	0x70003276
	cregs_d5_d9_cd10	R/W [9:8]	d0_9_con_cd10 ? 
								00 ? 2mA
								01 ? 4mA
								10 ? 6mA
								11 ? 8mA
							[7:6]	d0_8_con_cd10 ?
							[5:4]	d0_7_con_cd10 ?
							[3:2]	d0_6_con_cd10 ?
							[1:0]	d0_5_con_cd10 ?
	*/
    CamWriteCmosSensor(0x0F12, 0x0155); //set IO driving current 		
    /*	0x70003278	 */
    CamWriteCmosSensor(0x0F12, 0x1555); //set IO driving current 		
    /*	0x7000327A
	cregs_clks_output_cd10	R/W [11:10] SDA_cd10 - Sda pad cd1/cd0 control { Sda_cd1, Sda_cd0}.
								[9:8]	SCL_cd10 - Scl pad cd1/cd0 control { Scl_cd1, Scl_cd0}.
								[7:6]	Pclk_cd10 ? PCLK pad cd1/cd0 control { Pclk _cd1, Pclk _cd0}.
								[5:4]	reserved
								[3:2]	Vsync_cd10 ? Sdat pad cd1/cd0 control { Sdat _cd1, Sdat _cd0}.
								[1:0]	Hsync_cd10 ? Hsync pad cd1/cd0 control { Hsync _cd1, Hsync _cd0}.
	*/
    CamWriteCmosSensor(0x0F12, 0x0555); //set IO driving current 	
    
    CamWriteCmosSensor(0x0028, 0x7000);																												
    CamWriteCmosSensor(0x002A, 0x0572);																												
    CamWriteCmosSensor(0x0F12, 0x0007); //#skl_usConfigStbySettings // Enable T&P code after 		   
    																																													
    CamWriteCmosSensor(0x0028, 0x7000);																												
    CamWriteCmosSensor(0x002A, 0x12D2);																												
    CamWriteCmosSensor(0x0F12, 0x0003); //senHal_pContSenModesRegsArray[0][0]2 700012D2				
    CamWriteCmosSensor(0x0F12, 0x0003); //senHal_pContSenModesRegsArray[0][1]2 700012D4				
    CamWriteCmosSensor(0x0F12, 0x0003); //senHal_pContSenModesRegsArray[0][2]2 700012D6				
    CamWriteCmosSensor(0x0F12, 0x0003); //senHal_pContSenModesRegsArray[0][3]2 700012D8				
    CamWriteCmosSensor(0x0F12, 0x0884); //senHal_pContSenModesRegsArray[1][0]2 700012DA				
    CamWriteCmosSensor(0x0F12, 0x08CF); //senHal_pContSenModesRegsArray[1][1]2 700012DC				
    CamWriteCmosSensor(0x0F12, 0x0500); //senHal_pContSenModesRegsArray[1][2]2 700012DE				
    CamWriteCmosSensor(0x0F12, 0x054B); //senHal_pContSenModesRegsArray[1][3]2 700012E0				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[2][0]2 700012E2				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[2][1]2 700012E4				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[2][2]2 700012E6				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[2][3]2 700012E8				
    CamWriteCmosSensor(0x0F12, 0x0885); //senHal_pContSenModesRegsArray[3][0]2 700012EA				
    CamWriteCmosSensor(0x0F12, 0x0467); //senHal_pContSenModesRegsArray[3][1]2 700012EC				
    CamWriteCmosSensor(0x0F12, 0x0501); //senHal_pContSenModesRegsArray[3][2]2 700012EE				
    CamWriteCmosSensor(0x0F12, 0x02A5); //senHal_pContSenModesRegsArray[3][3]2 700012F0				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[4][0]2 700012F2				
    CamWriteCmosSensor(0x0F12, 0x046A); //senHal_pContSenModesRegsArray[4][1]2 700012F4				
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[4][2]2 700012F6				
    CamWriteCmosSensor(0x0F12, 0x02A8); //senHal_pContSenModesRegsArray[4][3]2 700012F8				
    CamWriteCmosSensor(0x0F12, 0x0885); //senHal_pContSenModesRegsArray[5][0]2 700012FA				
    CamWriteCmosSensor(0x0F12, 0x08D0); //senHal_pContSenModesRegsArray[5][1]2 700012FC				
    CamWriteCmosSensor(0x0F12, 0x0501); //senHal_pContSenModesRegsArray[5][2]2 700012FE				
    CamWriteCmosSensor(0x0F12, 0x054C); //senHal_pContSenModesRegsArray[5][3]2 70001300				
    CamWriteCmosSensor(0x0F12, 0x0006); //senHal_pContSenModesRegsArray[6][0]2 70001302				
    CamWriteCmosSensor(0x0F12, 0x0020); //senHal_pContSenModesRegsArray[6][1]2 70001304				
    CamWriteCmosSensor(0x0F12, 0x0006); //senHal_pContSenModesRegsArray[6][2]2 70001306				
    CamWriteCmosSensor(0x0F12, 0x0020); //senHal_pContSenModesRegsArray[6][3]2 70001308				
    CamWriteCmosSensor(0x0F12, 0x0881); //senHal_pContSenModesRegsArray[7][0]2 7000130A				
    CamWriteCmosSensor(0x0F12, 0x0463); //senHal_pContSenModesRegsArray[7][1]2 7000130C				
    CamWriteCmosSensor(0x0F12, 0x04FD); //senHal_pContSenModesRegsArray[7][2]2 7000130E				
    CamWriteCmosSensor(0x0F12, 0x02A1); //senHal_pContSenModesRegsArray[7][3]2 70001310				
    CamWriteCmosSensor(0x0F12, 0x0006); //senHal_pContSenModesRegsArray[8][0]2 70001312				
    CamWriteCmosSensor(0x0F12, 0x0489); //senHal_pContSenModesRegsArray[8][1]2 70001314				
    CamWriteCmosSensor(0x0F12, 0x0006); //senHal_pContSenModesRegsArray[8][2]2 70001316				
    CamWriteCmosSensor(0x0F12, 0x02C7); //senHal_pContSenModesRegsArray[8][3]2 70001318				
    CamWriteCmosSensor(0x0F12, 0x0881); //senHal_pContSenModesRegsArray[9][0]2 7000131A				
    CamWriteCmosSensor(0x0F12, 0x08CC); //senHal_pContSenModesRegsArray[9][1]2 7000131C				
    CamWriteCmosSensor(0x0F12, 0x04FD); //senHal_pContSenModesRegsArray[9][2]2 7000131E				
    CamWriteCmosSensor(0x0F12, 0x0548); //senHal_pContSenModesRegsArray[9][3]2 70001320				
    CamWriteCmosSensor(0x0F12, 0x03A2); //senHal_pContSenModesRegsArray[10][0] 2 70001322			
    CamWriteCmosSensor(0x0F12, 0x01D3); //senHal_pContSenModesRegsArray[10][1] 2 70001324			
    CamWriteCmosSensor(0x0F12, 0x01E0); //senHal_pContSenModesRegsArray[10][2] 2 70001326			
    CamWriteCmosSensor(0x0F12, 0x00F2); //senHal_pContSenModesRegsArray[10][3] 2 70001328			
    CamWriteCmosSensor(0x0F12, 0x03F2); //senHal_pContSenModesRegsArray[11][0] 2 7000132A			
    CamWriteCmosSensor(0x0F12, 0x0223); //senHal_pContSenModesRegsArray[11][1] 2 7000132C			
    CamWriteCmosSensor(0x0F12, 0x0230); //senHal_pContSenModesRegsArray[11][2] 2 7000132E			
    CamWriteCmosSensor(0x0F12, 0x0142); //senHal_pContSenModesRegsArray[11][3] 2 70001330			
    CamWriteCmosSensor(0x0F12, 0x03A2); //senHal_pContSenModesRegsArray[12][0] 2 70001332			
    CamWriteCmosSensor(0x0F12, 0x063C); //senHal_pContSenModesRegsArray[12][1] 2 70001334			
    CamWriteCmosSensor(0x0F12, 0x01E0); //senHal_pContSenModesRegsArray[12][2] 2 70001336			
    CamWriteCmosSensor(0x0F12, 0x0399); //senHal_pContSenModesRegsArray[12][3] 2 70001338			
    CamWriteCmosSensor(0x0F12, 0x03F2); //senHal_pContSenModesRegsArray[13][0] 2 7000133A			
    CamWriteCmosSensor(0x0F12, 0x068C); //senHal_pContSenModesRegsArray[13][1] 2 7000133C			
    CamWriteCmosSensor(0x0F12, 0x0230); //senHal_pContSenModesRegsArray[13][2] 2 7000133E			
    CamWriteCmosSensor(0x0F12, 0x03E9); //senHal_pContSenModesRegsArray[13][3] 2 70001340			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[14][0] 2 70001342			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[14][1] 2 70001344			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[14][2] 2 70001346			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[14][3] 2 70001348			
    CamWriteCmosSensor(0x0F12, 0x003C); //senHal_pContSenModesRegsArray[15][0] 2 7000134A			
    CamWriteCmosSensor(0x0F12, 0x003C); //senHal_pContSenModesRegsArray[15][1] 2 7000134C			
    CamWriteCmosSensor(0x0F12, 0x003C); //senHal_pContSenModesRegsArray[15][2] 2 7000134E			
    CamWriteCmosSensor(0x0F12, 0x003C); //senHal_pContSenModesRegsArray[15][3] 2 70001350			
    CamWriteCmosSensor(0x0F12, 0x01D3); //senHal_pContSenModesRegsArray[16][0] 2 70001352			
    CamWriteCmosSensor(0x0F12, 0x01D3); //senHal_pContSenModesRegsArray[16][1] 2 70001354			
    CamWriteCmosSensor(0x0F12, 0x00F2); //senHal_pContSenModesRegsArray[16][2] 2 70001356			
    CamWriteCmosSensor(0x0F12, 0x00F2); //senHal_pContSenModesRegsArray[16][3] 2 70001358			
    CamWriteCmosSensor(0x0F12, 0x020B); //senHal_pContSenModesRegsArray[17][0] 2 7000135A			
    CamWriteCmosSensor(0x0F12, 0x024A); //senHal_pContSenModesRegsArray[17][1] 2 7000135C			
    CamWriteCmosSensor(0x0F12, 0x012A); //senHal_pContSenModesRegsArray[17][2] 2 7000135E			
    CamWriteCmosSensor(0x0F12, 0x0169); //senHal_pContSenModesRegsArray[17][3] 2 70001360			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[18][0] 2 70001362			
    CamWriteCmosSensor(0x0F12, 0x046B); //senHal_pContSenModesRegsArray[18][1] 2 70001364			
    CamWriteCmosSensor(0x0F12, 0x0002); //senHal_pContSenModesRegsArray[18][2] 2 70001366			
    CamWriteCmosSensor(0x0F12, 0x02A9); //senHal_pContSenModesRegsArray[18][3] 2 70001368			
    CamWriteCmosSensor(0x0F12, 0x0419); //senHal_pContSenModesRegsArray[19][0] 2 7000136A			
    CamWriteCmosSensor(0x0F12, 0x04A5); //senHal_pContSenModesRegsArray[19][1] 2 7000136C			
    CamWriteCmosSensor(0x0F12, 0x0257); //senHal_pContSenModesRegsArray[19][2] 2 7000136E			
    CamWriteCmosSensor(0x0F12, 0x02E3); //senHal_pContSenModesRegsArray[19][3] 2 70001370			
    CamWriteCmosSensor(0x0F12, 0x0630); //senHal_pContSenModesRegsArray[20][0] 2 70001372			
    CamWriteCmosSensor(0x0F12, 0x063C); //senHal_pContSenModesRegsArray[20][1] 2 70001374			
    CamWriteCmosSensor(0x0F12, 0x038D); //senHal_pContSenModesRegsArray[20][2] 2 70001376			
    CamWriteCmosSensor(0x0F12, 0x0399); //senHal_pContSenModesRegsArray[20][3] 2 70001378			
    CamWriteCmosSensor(0x0F12, 0x0668); //senHal_pContSenModesRegsArray[21][0] 2 7000137A			
    CamWriteCmosSensor(0x0F12, 0x06B3); //senHal_pContSenModesRegsArray[21][1] 2 7000137C			
    CamWriteCmosSensor(0x0F12, 0x03C5); //senHal_pContSenModesRegsArray[21][2] 2 7000137E			
    CamWriteCmosSensor(0x0F12, 0x0410); //senHal_pContSenModesRegsArray[21][3] 2 70001380			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[22][0] 2 70001382			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[22][1] 2 70001384			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[22][2] 2 70001386			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[22][3] 2 70001388			
    CamWriteCmosSensor(0x0F12, 0x03A2); //senHal_pContSenModesRegsArray[23][0] 2 7000138A			
    CamWriteCmosSensor(0x0F12, 0x01D3); //senHal_pContSenModesRegsArray[23][1] 2 7000138C			
    CamWriteCmosSensor(0x0F12, 0x01E0); //senHal_pContSenModesRegsArray[23][2] 2 7000138E			
    CamWriteCmosSensor(0x0F12, 0x00F2); //senHal_pContSenModesRegsArray[23][3] 2 70001390			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[24][0] 2 70001392			
    CamWriteCmosSensor(0x0F12, 0x0461); //senHal_pContSenModesRegsArray[24][1] 2 70001394			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[24][2] 2 70001396			
    CamWriteCmosSensor(0x0F12, 0x029F); //senHal_pContSenModesRegsArray[24][3] 2 70001398			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[25][0] 2 7000139A			
    CamWriteCmosSensor(0x0F12, 0x063C); //senHal_pContSenModesRegsArray[25][1] 2 7000139C			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[25][2] 2 7000139E			
    CamWriteCmosSensor(0x0F12, 0x0399); //senHal_pContSenModesRegsArray[25][3] 2 700013A0			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[26][0] 2 700013A2			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[26][1] 2 700013A4			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[26][2] 2 700013A6			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[26][3] 2 700013A8			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[27][0] 2 700013AA			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[27][1] 2 700013AC			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[27][2] 2 700013AE			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[27][3] 2 700013B0			
    CamWriteCmosSensor(0x0F12, 0x020C); //senHal_pContSenModesRegsArray[28][0] 2 700013B2			
    CamWriteCmosSensor(0x0F12, 0x024B); //senHal_pContSenModesRegsArray[28][1] 2 700013B4			
    CamWriteCmosSensor(0x0F12, 0x012B); //senHal_pContSenModesRegsArray[28][2] 2 700013B6			
    CamWriteCmosSensor(0x0F12, 0x016A); //senHal_pContSenModesRegsArray[28][3] 2 700013B8			
    CamWriteCmosSensor(0x0F12, 0x039F); //senHal_pContSenModesRegsArray[29][0] 2 700013BA			
    CamWriteCmosSensor(0x0F12, 0x045E); //senHal_pContSenModesRegsArray[29][1] 2 700013BC			
    CamWriteCmosSensor(0x0F12, 0x01DD); //senHal_pContSenModesRegsArray[29][2] 2 700013BE			
    CamWriteCmosSensor(0x0F12, 0x029C); //senHal_pContSenModesRegsArray[29][3] 2 700013C0			
    CamWriteCmosSensor(0x0F12, 0x041A); //senHal_pContSenModesRegsArray[30][0] 2 700013C2			
    CamWriteCmosSensor(0x0F12, 0x04A6); //senHal_pContSenModesRegsArray[30][1] 2 700013C4			
    CamWriteCmosSensor(0x0F12, 0x0258); //senHal_pContSenModesRegsArray[30][2] 2 700013C6			
    CamWriteCmosSensor(0x0F12, 0x02E4); //senHal_pContSenModesRegsArray[30][3] 2 700013C8			
    CamWriteCmosSensor(0x0F12, 0x062D); //senHal_pContSenModesRegsArray[31][0] 2 700013CA			
    CamWriteCmosSensor(0x0F12, 0x0639); //senHal_pContSenModesRegsArray[31][1] 2 700013CC			
    CamWriteCmosSensor(0x0F12, 0x038A); //senHal_pContSenModesRegsArray[31][2] 2 700013CE			
    CamWriteCmosSensor(0x0F12, 0x0396); //senHal_pContSenModesRegsArray[31][3] 2 700013D0			
    CamWriteCmosSensor(0x0F12, 0x0669); //senHal_pContSenModesRegsArray[32][0] 2 700013D2			
    CamWriteCmosSensor(0x0F12, 0x06B4); //senHal_pContSenModesRegsArray[32][1] 2 700013D4			
    CamWriteCmosSensor(0x0F12, 0x03C6); //senHal_pContSenModesRegsArray[32][2] 2 700013D6			
    CamWriteCmosSensor(0x0F12, 0x0411); //senHal_pContSenModesRegsArray[32][3] 2 700013D8			
    CamWriteCmosSensor(0x0F12, 0x087C); //senHal_pContSenModesRegsArray[33][0] 2 700013DA			
    CamWriteCmosSensor(0x0F12, 0x08C7); //senHal_pContSenModesRegsArray[33][1] 2 700013DC			
    CamWriteCmosSensor(0x0F12, 0x04F8); //senHal_pContSenModesRegsArray[33][2] 2 700013DE			
    CamWriteCmosSensor(0x0F12, 0x0543); //senHal_pContSenModesRegsArray[33][3] 2 700013E0			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[34][0] 2 700013E2			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[34][1] 2 700013E4			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[34][2] 2 700013E6			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[34][3] 2 700013E8			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[35][0] 2 700013EA			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[35][1] 2 700013EC			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[35][2] 2 700013EE			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[35][3] 2 700013F0			
    CamWriteCmosSensor(0x0F12, 0x020F); //senHal_pContSenModesRegsArray[36][0] 2 700013F2			
    CamWriteCmosSensor(0x0F12, 0x024E); //senHal_pContSenModesRegsArray[36][1] 2 700013F4			
    CamWriteCmosSensor(0x0F12, 0x012E); //senHal_pContSenModesRegsArray[36][2] 2 700013F6			
    CamWriteCmosSensor(0x0F12, 0x016D); //senHal_pContSenModesRegsArray[36][3] 2 700013F8			
    CamWriteCmosSensor(0x0F12, 0x039F); //senHal_pContSenModesRegsArray[37][0] 2 700013FA			
    CamWriteCmosSensor(0x0F12, 0x045E); //senHal_pContSenModesRegsArray[37][1] 2 700013FC			
    CamWriteCmosSensor(0x0F12, 0x01DD); //senHal_pContSenModesRegsArray[37][2] 2 700013FE			
    CamWriteCmosSensor(0x0F12, 0x029C); //senHal_pContSenModesRegsArray[37][3] 2 70001400			
    CamWriteCmosSensor(0x0F12, 0x041D); //senHal_pContSenModesRegsArray[38][0] 2 70001402			
    CamWriteCmosSensor(0x0F12, 0x04A9); //senHal_pContSenModesRegsArray[38][1] 2 70001404			
    CamWriteCmosSensor(0x0F12, 0x025B); //senHal_pContSenModesRegsArray[38][2] 2 70001406			
    CamWriteCmosSensor(0x0F12, 0x02E7); //senHal_pContSenModesRegsArray[38][3] 2 70001408			
    CamWriteCmosSensor(0x0F12, 0x062D); //senHal_pContSenModesRegsArray[39][0] 2 7000140A			
    CamWriteCmosSensor(0x0F12, 0x0639); //senHal_pContSenModesRegsArray[39][1] 2 7000140C			
    CamWriteCmosSensor(0x0F12, 0x038A); //senHal_pContSenModesRegsArray[39][2] 2 7000140E			
    CamWriteCmosSensor(0x0F12, 0x0396); //senHal_pContSenModesRegsArray[39][3] 2 70001410			
    CamWriteCmosSensor(0x0F12, 0x066C); //senHal_pContSenModesRegsArray[40][0] 2 70001412			
    CamWriteCmosSensor(0x0F12, 0x06B7); //senHal_pContSenModesRegsArray[40][1] 2 70001414			
    CamWriteCmosSensor(0x0F12, 0x03C9); //senHal_pContSenModesRegsArray[40][2] 2 70001416			
    CamWriteCmosSensor(0x0F12, 0x0414); //senHal_pContSenModesRegsArray[40][3] 2 70001418			
    CamWriteCmosSensor(0x0F12, 0x087C); //senHal_pContSenModesRegsArray[41][0] 2 7000141A			
    CamWriteCmosSensor(0x0F12, 0x08C7); //senHal_pContSenModesRegsArray[41][1] 2 7000141C			
    CamWriteCmosSensor(0x0F12, 0x04F8); //senHal_pContSenModesRegsArray[41][2] 2 7000141E			
    CamWriteCmosSensor(0x0F12, 0x0543); //senHal_pContSenModesRegsArray[41][3] 2 70001420			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[42][0] 2 70001422			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[42][1] 2 70001424			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[42][2] 2 70001426			
    CamWriteCmosSensor(0x0F12, 0x0040); //senHal_pContSenModesRegsArray[42][3] 2 70001428			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[43][0] 2 7000142A			
    CamWriteCmosSensor(0x0F12, 0x01D0); //senHal_pContSenModesRegsArray[43][1] 2 7000142C			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[43][2] 2 7000142E			
    CamWriteCmosSensor(0x0F12, 0x00EF); //senHal_pContSenModesRegsArray[43][3] 2 70001430			
    CamWriteCmosSensor(0x0F12, 0x020F); //senHal_pContSenModesRegsArray[44][0] 2 70001432			
    CamWriteCmosSensor(0x0F12, 0x024E); //senHal_pContSenModesRegsArray[44][1] 2 70001434			
    CamWriteCmosSensor(0x0F12, 0x012E); //senHal_pContSenModesRegsArray[44][2] 2 70001436			
    CamWriteCmosSensor(0x0F12, 0x016D); //senHal_pContSenModesRegsArray[44][3] 2 70001438			
    CamWriteCmosSensor(0x0F12, 0x039F); //senHal_pContSenModesRegsArray[45][0] 2 7000143A			
    CamWriteCmosSensor(0x0F12, 0x045E); //senHal_pContSenModesRegsArray[45][1] 2 7000143C			
    CamWriteCmosSensor(0x0F12, 0x01DD); //senHal_pContSenModesRegsArray[45][2] 2 7000143E			
    CamWriteCmosSensor(0x0F12, 0x029C); //senHal_pContSenModesRegsArray[45][3] 2 70001440			
    CamWriteCmosSensor(0x0F12, 0x041D); //senHal_pContSenModesRegsArray[46][0] 2 70001442			
    CamWriteCmosSensor(0x0F12, 0x04A9); //senHal_pContSenModesRegsArray[46][1] 2 70001444			
    CamWriteCmosSensor(0x0F12, 0x025B); //senHal_pContSenModesRegsArray[46][2] 2 70001446			
    CamWriteCmosSensor(0x0F12, 0x02E7); //senHal_pContSenModesRegsArray[46][3] 2 70001448			
    CamWriteCmosSensor(0x0F12, 0x062D); //senHal_pContSenModesRegsArray[47][0] 2 7000144A			
    CamWriteCmosSensor(0x0F12, 0x0639); //senHal_pContSenModesRegsArray[47][1] 2 7000144C			
    CamWriteCmosSensor(0x0F12, 0x038A); //senHal_pContSenModesRegsArray[47][2] 2 7000144E			
    CamWriteCmosSensor(0x0F12, 0x0396); //senHal_pContSenModesRegsArray[47][3] 2 70001450			
    CamWriteCmosSensor(0x0F12, 0x066C); //senHal_pContSenModesRegsArray[48][0] 2 70001452			
    CamWriteCmosSensor(0x0F12, 0x06B7); //senHal_pContSenModesRegsArray[48][1] 2 70001454			
    CamWriteCmosSensor(0x0F12, 0x03C9); //senHal_pContSenModesRegsArray[48][2] 2 70001456			
    CamWriteCmosSensor(0x0F12, 0x0414); //senHal_pContSenModesRegsArray[48][3] 2 70001458			
    CamWriteCmosSensor(0x0F12, 0x087C); //senHal_pContSenModesRegsArray[49][0] 2 7000145A			
    CamWriteCmosSensor(0x0F12, 0x08C7); //senHal_pContSenModesRegsArray[49][1] 2 7000145C			
    CamWriteCmosSensor(0x0F12, 0x04F8); //senHal_pContSenModesRegsArray[49][2] 2 7000145E			
    CamWriteCmosSensor(0x0F12, 0x0543); //senHal_pContSenModesRegsArray[49][3] 2 70001460			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[50][0] 2 70001462			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[50][1] 2 70001464			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[50][2] 2 70001466			
    CamWriteCmosSensor(0x0F12, 0x003D); //senHal_pContSenModesRegsArray[50][3] 2 70001468			
    CamWriteCmosSensor(0x0F12, 0x01D2); //senHal_pContSenModesRegsArray[51][0] 2 7000146A			
    CamWriteCmosSensor(0x0F12, 0x01D2); //senHal_pContSenModesRegsArray[51][1] 2 7000146C			
    CamWriteCmosSensor(0x0F12, 0x00F1); //senHal_pContSenModesRegsArray[51][2] 2 7000146E			
    CamWriteCmosSensor(0x0F12, 0x00F1); //senHal_pContSenModesRegsArray[51][3] 2 70001470			
    CamWriteCmosSensor(0x0F12, 0x020C); //senHal_pContSenModesRegsArray[52][0] 2 70001472			
    CamWriteCmosSensor(0x0F12, 0x024B); //senHal_pContSenModesRegsArray[52][1] 2 70001474			
    CamWriteCmosSensor(0x0F12, 0x012B); //senHal_pContSenModesRegsArray[52][2] 2 70001476			
    CamWriteCmosSensor(0x0F12, 0x016A); //senHal_pContSenModesRegsArray[52][3] 2 70001478			
    CamWriteCmosSensor(0x0F12, 0x03A1); //senHal_pContSenModesRegsArray[53][0] 2 7000147A			
    CamWriteCmosSensor(0x0F12, 0x0460); //senHal_pContSenModesRegsArray[53][1] 2 7000147C			
    CamWriteCmosSensor(0x0F12, 0x01DF); //senHal_pContSenModesRegsArray[53][2] 2 7000147E			
    CamWriteCmosSensor(0x0F12, 0x029E); //senHal_pContSenModesRegsArray[53][3] 2 70001480			
    CamWriteCmosSensor(0x0F12, 0x041A); //senHal_pContSenModesRegsArray[54][0] 2 70001482			
    CamWriteCmosSensor(0x0F12, 0x04A6); //senHal_pContSenModesRegsArray[54][1] 2 70001484			
    CamWriteCmosSensor(0x0F12, 0x0258); //senHal_pContSenModesRegsArray[54][2] 2 70001486			
    CamWriteCmosSensor(0x0F12, 0x02E4); //senHal_pContSenModesRegsArray[54][3] 2 70001488			
    CamWriteCmosSensor(0x0F12, 0x062F); //senHal_pContSenModesRegsArray[55][0] 2 7000148A			
    CamWriteCmosSensor(0x0F12, 0x063B); //senHal_pContSenModesRegsArray[55][1] 2 7000148C			
    CamWriteCmosSensor(0x0F12, 0x038C); //senHal_pContSenModesRegsArray[55][2] 2 7000148E			
    CamWriteCmosSensor(0x0F12, 0x0398); //senHal_pContSenModesRegsArray[55][3] 2 70001490			
    CamWriteCmosSensor(0x0F12, 0x0669); //senHal_pContSenModesRegsArray[56][0] 2 70001492			
    CamWriteCmosSensor(0x0F12, 0x06B4); //senHal_pContSenModesRegsArray[56][1] 2 70001494			
    CamWriteCmosSensor(0x0F12, 0x03C6); //senHal_pContSenModesRegsArray[56][2] 2 70001496			
    CamWriteCmosSensor(0x0F12, 0x0411); //senHal_pContSenModesRegsArray[56][3] 2 70001498			
    CamWriteCmosSensor(0x0F12, 0x087E); //senHal_pContSenModesRegsArray[57][0] 2 7000149A			
    CamWriteCmosSensor(0x0F12, 0x08C9); //senHal_pContSenModesRegsArray[57][1] 2 7000149C			
    CamWriteCmosSensor(0x0F12, 0x04FA); //senHal_pContSenModesRegsArray[57][2] 2 7000149E			
    CamWriteCmosSensor(0x0F12, 0x0545); //senHal_pContSenModesRegsArray[57][3] 2 700014A0			
    CamWriteCmosSensor(0x0F12, 0x03A2); //senHal_pContSenModesRegsArray[58][0] 2 700014A2			
    CamWriteCmosSensor(0x0F12, 0x01D3); //senHal_pContSenModesRegsArray[58][1] 2 700014A4			
    CamWriteCmosSensor(0x0F12, 0x01E0); //senHal_pContSenModesRegsArray[58][2] 2 700014A6			
    CamWriteCmosSensor(0x0F12, 0x00F2); //senHal_pContSenModesRegsArray[58][3] 2 700014A8			
    CamWriteCmosSensor(0x0F12, 0x03AF); //senHal_pContSenModesRegsArray[59][0] 2 700014AA			
    CamWriteCmosSensor(0x0F12, 0x01E0); //senHal_pContSenModesRegsArray[59][1] 2 700014AC			
    CamWriteCmosSensor(0x0F12, 0x01ED); //senHal_pContSenModesRegsArray[59][2] 2 700014AE			
    CamWriteCmosSensor(0x0F12, 0x00FF); //senHal_pContSenModesRegsArray[59][3] 2 700014B0			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[60][0] 2 700014B2			
    CamWriteCmosSensor(0x0F12, 0x0461); //senHal_pContSenModesRegsArray[60][1] 2 700014B4			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[60][2] 2 700014B6			
    CamWriteCmosSensor(0x0F12, 0x029F); //senHal_pContSenModesRegsArray[60][3] 2 700014B8			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[61][0] 2 700014BA			
    CamWriteCmosSensor(0x0F12, 0x046E); //senHal_pContSenModesRegsArray[61][1] 2 700014BC			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[61][2] 2 700014BE			
    CamWriteCmosSensor(0x0F12, 0x02AC); //senHal_pContSenModesRegsArray[61][3] 2 700014C0			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[62][0] 2 700014C2			
    CamWriteCmosSensor(0x0F12, 0x063C); //senHal_pContSenModesRegsArray[62][1] 2 700014C4			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[62][2] 2 700014C6			
    CamWriteCmosSensor(0x0F12, 0x0399); //senHal_pContSenModesRegsArray[62][3] 2 700014C8			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[63][0] 2 700014CA			
    CamWriteCmosSensor(0x0F12, 0x0649); //senHal_pContSenModesRegsArray[63][1] 2 700014CC			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[63][2] 2 700014CE			
    CamWriteCmosSensor(0x0F12, 0x03A6); //senHal_pContSenModesRegsArray[63][3] 2 700014D0			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[64][0] 2 700014D2			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[64][1] 2 700014D4			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[64][2] 2 700014D6			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[64][3] 2 700014D8			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[65][0] 2 700014DA			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[65][1] 2 700014DC			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[65][2] 2 700014DE			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[65][3] 2 700014E0			
    CamWriteCmosSensor(0x0F12, 0x03AA); //senHal_pContSenModesRegsArray[66][0] 2 700014E2			
    CamWriteCmosSensor(0x0F12, 0x01DB); //senHal_pContSenModesRegsArray[66][1] 2 700014E4			
    CamWriteCmosSensor(0x0F12, 0x01E8); //senHal_pContSenModesRegsArray[66][2] 2 700014E6			
    CamWriteCmosSensor(0x0F12, 0x00FA); //senHal_pContSenModesRegsArray[66][3] 2 700014E8			
    CamWriteCmosSensor(0x0F12, 0x03B7); //senHal_pContSenModesRegsArray[67][0] 2 700014EA			
    CamWriteCmosSensor(0x0F12, 0x01E8); //senHal_pContSenModesRegsArray[67][1] 2 700014EC			
    CamWriteCmosSensor(0x0F12, 0x01F5); //senHal_pContSenModesRegsArray[67][2] 2 700014EE			
    CamWriteCmosSensor(0x0F12, 0x0107); //senHal_pContSenModesRegsArray[67][3] 2 700014F0			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[68][0] 2 700014F2			
    CamWriteCmosSensor(0x0F12, 0x0469); //senHal_pContSenModesRegsArray[68][1] 2 700014F4			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[68][2] 2 700014F6			
    CamWriteCmosSensor(0x0F12, 0x02A7); //senHal_pContSenModesRegsArray[68][3] 2 700014F8			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[69][0] 2 700014FA			
    CamWriteCmosSensor(0x0F12, 0x0476); //senHal_pContSenModesRegsArray[69][1] 2 700014FC			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[69][2] 2 700014FE			
    CamWriteCmosSensor(0x0F12, 0x02B4); //senHal_pContSenModesRegsArray[69][3] 2 70001500			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[70][0] 2 70001502			
    CamWriteCmosSensor(0x0F12, 0x0644); //senHal_pContSenModesRegsArray[70][1] 2 70001504			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[70][2] 2 70001506			
    CamWriteCmosSensor(0x0F12, 0x03A1); //senHal_pContSenModesRegsArray[70][3] 2 70001508			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[71][0] 2 7000150A			
    CamWriteCmosSensor(0x0F12, 0x0651); //senHal_pContSenModesRegsArray[71][1] 2 7000150C			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[71][2] 2 7000150E			
    CamWriteCmosSensor(0x0F12, 0x03AE); //senHal_pContSenModesRegsArray[71][3] 2 70001510			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[72][0] 2 70001512			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[72][1] 2 70001514			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[72][2] 2 70001516			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[72][3] 2 70001518			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[73][0] 2 7000151A			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[73][1] 2 7000151C			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[73][2] 2 7000151E			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[73][3] 2 70001520			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[74][0] 2 70001522			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[74][1] 2 70001524			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[74][2] 2 70001526			
    CamWriteCmosSensor(0x0F12, 0x0001); //senHal_pContSenModesRegsArray[74][3] 2 70001528			
    CamWriteCmosSensor(0x0F12, 0x000F); //senHal_pContSenModesRegsArray[75][0] 2 7000152A			
    CamWriteCmosSensor(0x0F12, 0x000F); //senHal_pContSenModesRegsArray[75][1] 2 7000152C			
    CamWriteCmosSensor(0x0F12, 0x000F); //senHal_pContSenModesRegsArray[75][2] 2 7000152E			
    CamWriteCmosSensor(0x0F12, 0x000F); //senHal_pContSenModesRegsArray[75][3] 2 70001530			
    CamWriteCmosSensor(0x0F12, 0x05AD); //senHal_pContSenModesRegsArray[76][0] 2 70001532			
    CamWriteCmosSensor(0x0F12, 0x03DE); //senHal_pContSenModesRegsArray[76][1] 2 70001534			
    CamWriteCmosSensor(0x0F12, 0x030A); //senHal_pContSenModesRegsArray[76][2] 2 70001536			
    CamWriteCmosSensor(0x0F12, 0x021C); //senHal_pContSenModesRegsArray[76][3] 2 70001538			
    CamWriteCmosSensor(0x0F12, 0x062F); //senHal_pContSenModesRegsArray[77][0] 2 7000153A			
    CamWriteCmosSensor(0x0F12, 0x0460); //senHal_pContSenModesRegsArray[77][1] 2 7000153C			
    CamWriteCmosSensor(0x0F12, 0x038C); //senHal_pContSenModesRegsArray[77][2] 2 7000153E			
    CamWriteCmosSensor(0x0F12, 0x029E); //senHal_pContSenModesRegsArray[77][3] 2 70001540			
    CamWriteCmosSensor(0x0F12, 0x07FC); //senHal_pContSenModesRegsArray[78][0] 2 70001542			
    CamWriteCmosSensor(0x0F12, 0x0847); //senHal_pContSenModesRegsArray[78][1] 2 70001544			
    CamWriteCmosSensor(0x0F12, 0x0478); //senHal_pContSenModesRegsArray[78][2] 2 70001546			
    CamWriteCmosSensor(0x0F12, 0x04C3); //senHal_pContSenModesRegsArray[78][3] 2 70001548			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[79][0] 2 7000154A			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[79][1] 2 7000154C			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[79][2] 2 7000154E			
    CamWriteCmosSensor(0x0F12, 0x0000); //senHal_pContSenModesRegsArray[79][3] 2 70001550			
    																																													
    																																													
    //=======================================================================================
    //=======================================================================================
    //#Analog Setting END																																			
    //=======================================================================================
    CamWriteCmosSensor(0x002A, 0x01D4);																												
    CamWriteCmosSensor(0x0F12, 0x0000); //#REG_TC_IPRM_AuxGpios : 0 - no Flash																   
    CamWriteCmosSensor(0x002A, 0x01DE);																												
    CamWriteCmosSensor(0x0F12, 0x0003); //#REG_TC_IPRM_CM_Init_AfModeType : 3 - AFD_VCM_I2C													   
    CamWriteCmosSensor(0x0F12, 0x0000); //#REG_TC_IPRM_CM_Init_PwmConfig1 : 0 - no PWM														   
    CamWriteCmosSensor(0x002A, 0x01E4);																												
    CamWriteCmosSensor(0x0F12, 0x0000); //#REG_TC_IPRM_CM_Init_GpioConfig1 : 0 - no GPIO 													   
    CamWriteCmosSensor(0x002A, 0x01E8);																												
    CamWriteCmosSensor(0x0F12, 0x200C); //#REG_TC_IPRM_CM_Init_Mi2cBits : MSCL - GPIO1 MSDA - GPIO2 Device ID (0C)
    CamWriteCmosSensor(0x0F12, 0x0190); //#REG_TC_IPRM_CM_Init_Mi2cRateKhz : MI2C Speed - 400KHz
    ////============================== ==============================											   
    //// AF Parameter setting																								
    ////============================================================ 											   
    //// AF Window Settings																									
    CamWriteCmosSensor(0x002A, 0x025A);																			
    CamWriteCmosSensor(0x0F12, 0x0100); //#REG_TC_AF_FstWinStartX										   
    CamWriteCmosSensor(0x0F12, 0x00E3); //#REG_TC_AF_FstWinStartY										   
    CamWriteCmosSensor(0x0F12, 0x0200); //#REG_TC_AF_FstWinSizeX 										   
    CamWriteCmosSensor(0x0F12, 0x0238); //#REG_TC_AF_FstWinSizeY 										   
    CamWriteCmosSensor(0x0F12, 0x018C); //#REG_TC_AF_ScndWinStartX										   
    CamWriteCmosSensor(0x0F12, 0x0166); //#REG_TC_AF_ScndWinStartY										   
    CamWriteCmosSensor(0x0F12, 0x00E6); //#REG_TC_AF_ScndWinSizeX										   
    CamWriteCmosSensor(0x0F12, 0x0132); //#REG_TC_AF_ScndWinSizeY										   
    CamWriteCmosSensor(0x0F12, 0x0001); //#REG_TC_AF_WinSizesUpdated 									   
    //// AF Setot Settings																									
    CamWriteCmosSensor(0x002A, 0x0586);																			
    CamWriteCmosSensor(0x0F12, 0x00FF); //#skl_af_StatOvlpExpFactor										   
    //// AF Scene Settings																									
    CamWriteCmosSensor(0x002A, 0x115E);																			
    CamWriteCmosSensor(0x0F12, 0x0003); //#af_scene_usSaturatedScene 									   
    //// AF Fine Search Settings 																						
    CamWriteCmosSensor(0x002A, 0x10D4);																			
    CamWriteCmosSensor(0x0F12, 0x1000); //#FineSearch Disable //#af_search_usSingleAfFlags
    CamWriteCmosSensor(0x002A, 0x10DE);																
    CamWriteCmosSensor(0x0F12, 0x0004); //#af_search_usFinePeakCount 						   
    CamWriteCmosSensor(0x002A, 0x106C);																
    CamWriteCmosSensor(0x0F12, 0x0202); //#af_pos_usFineStepNumSize							   
    //// AF Peak Threshold Setting																		  
    CamWriteCmosSensor(0x002A, 0x10CA); //#af_search_usPeakThr								   
    CamWriteCmosSensor(0x0F12, 0x00C0);																
    //// AF Default Position 																					
    CamWriteCmosSensor(0x002A, 0x1060);																
    CamWriteCmosSensor(0x0F12, 0x0000);//#af_pos_usHomePos									   
    CamWriteCmosSensor(0x0F12, 0x783C);//#af_pos_usLowConfPos								   
    //// AF LowConfThr Setting																				
    CamWriteCmosSensor(0x002A, 0x10F4); //#LowEdgeBoth GRAD									   
    CamWriteCmosSensor(0x0F12, 0x0280);																
    CamWriteCmosSensor(0x002A, 0x1100); //#LowLight HPF										   
    CamWriteCmosSensor(0x0F12, 0x03A0);																
    CamWriteCmosSensor(0x0F12, 0x0320);																
    CamWriteCmosSensor(0x002A, 0x1134);																
    CamWriteCmosSensor(0x0F12, 0x0030); //#af_stat_usMinStatVal								   
    //// AF low Br Th																									
    CamWriteCmosSensor(0x002A, 0x1154);//#normBrThr											   
    CamWriteCmosSensor(0x0F12, 0x0060);																
    //// AF Ploicy																										
    CamWriteCmosSensor(0x002A, 0x10E2);																
    CamWriteCmosSensor(0x0F12, 0x0000); //#af_search_usCapturePolicy: Focus_Priority, 0002 : Shutter_Priority_Fixed, 0001 : Shutter_Priority_Last_BFP 0000: Shutter_Priority_Current
    CamWriteCmosSensor(0x002A, 0x1072);																							
    CamWriteCmosSensor(0x0F12, 0x003C); //#af_pos_usCaptureFixedPos//#0x0008 				
    //// AF Lens Position Table Settings 																						
    CamWriteCmosSensor(0x002A, 0x1074);																							
    CamWriteCmosSensor(0x0F12, 0x0010); //#af_pos_usTableLastInd//#16 Steps 091222	   
    CamWriteCmosSensor(0x0F12, 0x003C); //#af_pos_usTable_0_//#af_pos_usTable				
    CamWriteCmosSensor(0x0F12, 0x003F); //#af_pos_usTable_1_ 					
    CamWriteCmosSensor(0x0F12, 0x0042); //#af_pos_usTable_2_ 					
    CamWriteCmosSensor(0x0F12, 0x0045); //#af_pos_usTable_3_ 					
    CamWriteCmosSensor(0x0F12, 0x0048); //#af_pos_usTable_4_ 					
    CamWriteCmosSensor(0x0F12, 0x004B); //#af_pos_usTable_5_ 					
    CamWriteCmosSensor(0x0F12, 0x004E); //#af_pos_usTable_6_ 					
    CamWriteCmosSensor(0x0F12, 0x0051); //#af_pos_usTable_7_ 					
    CamWriteCmosSensor(0x0F12, 0x0054); //#af_pos_usTable_8_ 					
    CamWriteCmosSensor(0x0F12, 0x0057); //#af_pos_usTable_9_ 					
    CamWriteCmosSensor(0x0F12, 0x005A); //#af_pos_usTable_10_					
    CamWriteCmosSensor(0x0F12, 0x005E); //#af_pos_usTable_11_					
    CamWriteCmosSensor(0x0F12, 0x0061); //#af_pos_usTable_12_					
    CamWriteCmosSensor(0x0F12, 0x0064); //#af_pos_usTable_13_					
    CamWriteCmosSensor(0x0F12, 0x0068); //#af_pos_usTable_14_					
    CamWriteCmosSensor(0x0F12, 0x006C); //#af_pos_usTable_15_					
    CamWriteCmosSensor(0x0F12, 0x0078); //#af_pos_usTable_16_					
    CamWriteCmosSensor(0x002A, 0x0252);																
    CamWriteCmosSensor(0x0F12, 0x0003); //#init												
    //============================================================				   
    // ISP-FE Setting																									
    //============================================================				   
    CamWriteCmosSensor(0x002A, 0x158A);																
    CamWriteCmosSensor(0x0F12, 0xEAF0);																
    CamWriteCmosSensor(0x002A, 0x15C6);																
    CamWriteCmosSensor(0x0F12, 0x0020);																
    CamWriteCmosSensor(0x0F12, 0x0060);																
    CamWriteCmosSensor(0x002A, 0x15BC);																
    CamWriteCmosSensor(0x0F12, 0x0200); // added by Shy. 							
    //Analog Offset for MSM																						
    CamWriteCmosSensor(0x002A, 0x1608);																
    CamWriteCmosSensor(0x0F12, 0x0100); // #gisp_msm_sAnalogOffset[0]   
    CamWriteCmosSensor(0x0F12, 0x0100); // #gisp_msm_sAnalogOffset[1]   
    CamWriteCmosSensor(0x0F12, 0x0100); // #gisp_msm_sAnalogOffset[2]   
    CamWriteCmosSensor(0x0F12, 0x0100); // #gisp_msm_sAnalogOffset[3]   
    //=================================================================================================															   
    //#ISP-FE Setting END																																								
    //=================================================================================================															   
    //=================================================================================================															   
    //#Frame rate setting																																								
    //=================================================================================================															   
    //#How to set																																												
    //#1. Exposure value 																																								
    //#dec2hex((1 / (frame rate you want(ms))) * 100d * 4d)																											   
    //#2. Analog Digital gain																																						
    //#dec2hex((Analog gain you want) * 256d) 开始时钟设置																											   
    //=================================================================================================															   
    //Set preview exposure time																																					
    CamWriteCmosSensor(0x002A, 0x0530);																																	
    CamWriteCmosSensor(0x0F12, 0x1A0A); //#lt_uMaxExp1 60ms																									   
    CamWriteCmosSensor(0x002A, 0x0534);																																	
    CamWriteCmosSensor(0x0F12, 0x6590); //#lt_uMaxExp2 65ms																									   
    CamWriteCmosSensor(0x002A, 0x167C);																																	
    CamWriteCmosSensor(0x0F12, 0x8CA0); //#evt1_lt_uMaxExp3 90ms 																							   
    CamWriteCmosSensor(0x002A, 0x1680);																																	
    CamWriteCmosSensor(0x0F12, 0x3880); //0xABE0); //#evt1_lt_uMaxExp4 110ms   更改帧率的限制																   
    CamWriteCmosSensor(0x0F12, 0x0001);	//SANDY oppo dengnanwei 更改noight mode 	  20110927																   
    																																																		
    // Set capture exposure time 																																				
    CamWriteCmosSensor(0x002A, 0x0538);																																	
    CamWriteCmosSensor(0x0F12, 0x1A0A); //#lt_uCapMaxExp1 60ms																								   
    CamWriteCmosSensor(0x002A, 0x053C);																																	
    CamWriteCmosSensor(0x0F12, 0x6590); //#lt_uCapMaxExp2 65ms																								   
    CamWriteCmosSensor(0x002A, 0x1684);																																	
    CamWriteCmosSensor(0x0F12, 0x8CA0); //#evt1_lt_uCapMaxExp3 90ms																							   
    CamWriteCmosSensor(0x002A, 0x1688);																																	
    CamWriteCmosSensor(0x0F12, 0x3880); //0xABE0); //#evt1_lt_uCapMaxExp4 110ms	   同上 																	   
    CamWriteCmosSensor(0x0F12, 0x0001); //SANDY oppo dengnanwei	更改noight mode   20110927																	   
    																																																		
    //Set gain																																													
    CamWriteCmosSensor(0x002A, 0x0540);																																	
    CamWriteCmosSensor(0x0F12, 0x01B3); //#lt_uMaxAnGain1																									   
    CamWriteCmosSensor(0x0F12, 0x01D0); //#lt_uMaxAnGain2																									   
    CamWriteCmosSensor(0x002A, 0x168C);																																	
    CamWriteCmosSensor(0x0F12, 0x02D0); //#evt1_lt_uMaxAnGain3																								   
    CamWriteCmosSensor(0x0F12, 0x0800); //#evt1_lt_uMaxAnGain4																								   
    CamWriteCmosSensor(0x002A, 0x0544);																																	
    CamWriteCmosSensor(0x0F12, 0x0100); //#lt_uMaxDigGain																									   
    CamWriteCmosSensor(0x0F12, 0x8000); //0x0800); //#lt_uMaxTotGain    增大TotGain 的限制值 																   
    CamWriteCmosSensor(0x002A, 0x1694);																																	
    CamWriteCmosSensor(0x0F12, 0x0001);																																	
    CamWriteCmosSensor(0x002A, 0x021A);																																	
    CamWriteCmosSensor(0x0F12, 0x0000);	//MBR off// 																										   
    																																																		
    																																																		
    //================================================================================================																   
    // SET AE																																														
    //================================================================================================																   
    // AE target 																																												
    																																																		
    CamWriteCmosSensor(0x002A, 0x0F70);																																	
    CamWriteCmosSensor(0x0F12, 0x0042);	////002C //#TVAR_ae_BrAve 091222																					   
    //AE variation																																											
    CamWriteCmosSensor(0x002A, 0x051A);																																	
    CamWriteCmosSensor(0x0F12, 0x0111); //lt_uLimitHigh																										   
    CamWriteCmosSensor(0x0F12, 0x00F0); //lt_uLimitLow																										   
    // AE mode																																													
    CamWriteCmosSensor(0x002A, 0x0F76);																																	
    CamWriteCmosSensor(0x0F12, 0x000F); //Disable illumination & contrast   // #ae_StatMode																	   
    // AE weight 																																												
    CamWriteCmosSensor(0x002A, 0x0F7E);																																	
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_0_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_1_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_2_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_3_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_4_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_5_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_6_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_7_																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_8_																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_9_																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_10																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_11																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_12																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_13																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_14																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_15																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_16																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_17																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_18																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_19																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_20																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_21																								   
    CamWriteCmosSensor(0x0F12, 0x0303); // #ae_WeightTbl_16_22																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_23																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_24																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_25																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_26																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_27																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_28																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_29																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_30																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #ae_WeightTbl_16_31																								   
    																																																		
    //================================================================================================																   
    // SET FLICKER																																											
    //================================================================================================																   
    CamWriteCmosSensor(0x002A, 0x0C18);																																	
    CamWriteCmosSensor(0x0F12, 0x0000); // 0001: 60Hz start auto / 0000: 50Hz start auto 																	   
    CamWriteCmosSensor(0x002A, 0x04D2);																																	
    CamWriteCmosSensor(0x0F12, 0x067F);																																	
    																																																		
    //================================================================================================																   
    // SET GAS																																													
    //================================================================================================																   
    // GAS alpha 																																												
    // R,0xGr,0xGb,0xB per light source																																	  
    																																																		
    CamWriteCmosSensor(0x002A, 0x06CE);																																	
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[0] // Horizon																					   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[1] 																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[2] 																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[3] 																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[4] // IncandA																					   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[4] // IncandA																					   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[5] 																							   
    CamWriteCmosSensor(0x0F12, 0x00C0); // #TVAR_ash_GASAlpha[6] 																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[8] // WW																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[9] 																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[10]																							   
    CamWriteCmosSensor(0x0F12, 0x00E0); // #TVAR_ash_GASAlpha[11]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[12]// CWF																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[13]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[14]																							   
    CamWriteCmosSensor(0x0F12, 0x00E0); // #TVAR_ash_GASAlpha[15]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[16]// D50																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[17]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[18]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[19]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[20]// D65																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[21]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[22]																							   
    CamWriteCmosSensor(0x0F12, 0x00E0); // #TVAR_ash_GASAlpha[23]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[24]// D75																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[25]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[26]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASAlpha[27]																							   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASOutdoorAlpha[0] // Outdoor																			   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASOutdoorAlpha[1]																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASOutdoorAlpha[2]																						   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_GASOutdoorAlpha[3]																						   
    // GAS beta																																													
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[0]// Horizon 																						   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[1]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[2]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[3]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[4]// IncandA 																						   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[5]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[6]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[7]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[8]// WW																								   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[9]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[10]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[11]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[12] // CWF																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[13]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[14]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[15]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[16] // D50																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[17]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[18]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[19]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[20] // D65																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[21]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[22]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[23]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[24] // D75																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[25]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[26]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASBeta[27]																									   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASOutdoorBeta[0] // Outdoor 																				   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASOutdoorBeta[1]																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASOutdoorBeta[2]																							   
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_GASOutdoorBeta[3]																							   
    CamWriteCmosSensor(0x002A, 0x06B4);																																	
    CamWriteCmosSensor(0x0F12, 0x0000); // #wbt_bUseOutdoorASH ON:1 OFF:0																					   
    // Parabloic function																																								
    CamWriteCmosSensor(0x002A, 0x075A);																																	
    CamWriteCmosSensor(0x0F12, 0x0000); // #ash_bParabolicEstimation 																						   
    CamWriteCmosSensor(0x0F12, 0x0400); // #ash_uParabolicCenterX																							   
    CamWriteCmosSensor(0x0F12, 0x0300); // #ash_uParabolicCenterY																							   
    CamWriteCmosSensor(0x0F12, 0x0010); // #ash_uParabolicScalingA																							   
    CamWriteCmosSensor(0x0F12, 0x0011); // #ash_uParabolicScalingB																							   
    //ash_CGrasAlphas																																										
    CamWriteCmosSensor(0x002A, 0x06C6);																																	
    CamWriteCmosSensor(0x0F12, 0x0100);	//ash_CGrasAlphas[0]																								   
    CamWriteCmosSensor(0x0F12, 0x0100);	//ash_CGrasAlphas[1]																								   
    CamWriteCmosSensor(0x0F12, 0x0100);	//ash_CGrasAlphas[2]																								   
    CamWriteCmosSensor(0x0F12, 0x0100);	//ash_CGrasAlphas[3]																								   
    CamWriteCmosSensor(0x002A, 0x0E3C);																																	
    CamWriteCmosSensor(0x0F12, 0x00C0); //#awbb_Alpha_Comp_Mode																								   
    CamWriteCmosSensor(0x002A, 0x074E);																																	
    CamWriteCmosSensor(0x0F12, 0x0000); //#ash_bLumaMode //use Beta : 0001 not use Beta : 0000																   
    // GAS LUT start address // 7000_347C																																  
    CamWriteCmosSensor(0x002A, 0x0754);																																	
    CamWriteCmosSensor(0x0F12, 0x347C);																																	
    CamWriteCmosSensor(0x0F12, 0x7000);																																	
    // GAS LUT																																													
    CamWriteCmosSensor(0x002A, 0x347C);																																	
    CamWriteCmosSensor(0x0F12, 0x01A7); // #TVAR_ash_pGAS[0] 																								   
    CamWriteCmosSensor(0x0F12, 0x016B); // #TVAR_ash_pGAS[1] 																								   
    CamWriteCmosSensor(0x0F12, 0x0138); // #TVAR_ash_pGAS[2] 																								   
    CamWriteCmosSensor(0x0F12, 0x010E); // #TVAR_ash_pGAS[3] 																								   
    CamWriteCmosSensor(0x0F12, 0x00EB); // #TVAR_ash_pGAS[4] 																								   
    CamWriteCmosSensor(0x0F12, 0x00D4); // #TVAR_ash_pGAS[5] 																								   
    CamWriteCmosSensor(0x0F12, 0x00C6); // #TVAR_ash_pGAS[6] 																								   
    CamWriteCmosSensor(0x0F12, 0x00CD); // #TVAR_ash_pGAS[7] 																								   
    CamWriteCmosSensor(0x0F12, 0x00E2); // #TVAR_ash_pGAS[8] 																								   
    CamWriteCmosSensor(0x0F12, 0x0107); // #TVAR_ash_pGAS[9] 																								   
    CamWriteCmosSensor(0x0F12, 0x0136); // #TVAR_ash_pGAS[10]																								   
    CamWriteCmosSensor(0x0F12, 0x0173); // #TVAR_ash_pGAS[11]																								   
    CamWriteCmosSensor(0x0F12, 0x01A7); // #TVAR_ash_pGAS[12]																								   
    CamWriteCmosSensor(0x0F12, 0x0180); // #TVAR_ash_pGAS[13]																								   
    CamWriteCmosSensor(0x0F12, 0x013D); // #TVAR_ash_pGAS[14]																								   
    CamWriteCmosSensor(0x0F12, 0x00FF); // #TVAR_ash_pGAS[15]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[16]																								   
    CamWriteCmosSensor(0x0F12, 0x00A5); // #TVAR_ash_pGAS[17]																								   
    CamWriteCmosSensor(0x0F12, 0x008D); // #TVAR_ash_pGAS[18]																								   
    CamWriteCmosSensor(0x0F12, 0x0084); // #TVAR_ash_pGAS[19]																								   
    CamWriteCmosSensor(0x0F12, 0x008C); // #TVAR_ash_pGAS[20]																								   
    CamWriteCmosSensor(0x0F12, 0x00A4); // #TVAR_ash_pGAS[21]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[22]																								   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_pGAS[23]																								   
    CamWriteCmosSensor(0x0F12, 0x0145); // #TVAR_ash_pGAS[24]																								   
    CamWriteCmosSensor(0x0F12, 0x0189); // #TVAR_ash_pGAS[25]																								   
    CamWriteCmosSensor(0x0F12, 0x014F); // #TVAR_ash_pGAS[26]																								   
    CamWriteCmosSensor(0x0F12, 0x010F); // #TVAR_ash_pGAS[27]																								   
    CamWriteCmosSensor(0x0F12, 0x00C9); // #TVAR_ash_pGAS[28]																								   
    CamWriteCmosSensor(0x0F12, 0x0094); // #TVAR_ash_pGAS[29]																								   
    CamWriteCmosSensor(0x0F12, 0x0069); // #TVAR_ash_pGAS[30]																								   
    CamWriteCmosSensor(0x0F12, 0x004F); // #TVAR_ash_pGAS[31]																								   
    CamWriteCmosSensor(0x0F12, 0x0043); // #TVAR_ash_pGAS[32]																								   
    CamWriteCmosSensor(0x0F12, 0x004B); // #TVAR_ash_pGAS[33]																								   
    CamWriteCmosSensor(0x0F12, 0x0067); // #TVAR_ash_pGAS[34]																								   
    CamWriteCmosSensor(0x0F12, 0x0092); // #TVAR_ash_pGAS[35]																								   
    CamWriteCmosSensor(0x0F12, 0x00D0); // #TVAR_ash_pGAS[36]																								   
    CamWriteCmosSensor(0x0F12, 0x011D); // #TVAR_ash_pGAS[37]																								   
    CamWriteCmosSensor(0x0F12, 0x015F); // #TVAR_ash_pGAS[38]																								   
    CamWriteCmosSensor(0x0F12, 0x012F); // #TVAR_ash_pGAS[39]																								   
    CamWriteCmosSensor(0x0F12, 0x00EE); // #TVAR_ash_pGAS[40]																								   
    CamWriteCmosSensor(0x0F12, 0x00A5); // #TVAR_ash_pGAS[41]																								   
    CamWriteCmosSensor(0x0F12, 0x006A); // #TVAR_ash_pGAS[42]																								   
    CamWriteCmosSensor(0x0F12, 0x003C); // #TVAR_ash_pGAS[43]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[44]																								   
    CamWriteCmosSensor(0x0F12, 0x001B); // #TVAR_ash_pGAS[45]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[46]																								   
    CamWriteCmosSensor(0x0F12, 0x003F); // #TVAR_ash_pGAS[47]																								   
    CamWriteCmosSensor(0x0F12, 0x006F); // #TVAR_ash_pGAS[48]																								   
    CamWriteCmosSensor(0x0F12, 0x00AE); // #TVAR_ash_pGAS[49]																								   
    CamWriteCmosSensor(0x0F12, 0x00FF); // #TVAR_ash_pGAS[50]																								   
    CamWriteCmosSensor(0x0F12, 0x014A); // #TVAR_ash_pGAS[51]																								   
    CamWriteCmosSensor(0x0F12, 0x011D); // #TVAR_ash_pGAS[52]																								   
    CamWriteCmosSensor(0x0F12, 0x00D4); // #TVAR_ash_pGAS[53]																								   
    CamWriteCmosSensor(0x0F12, 0x008A); // #TVAR_ash_pGAS[54]																								   
    CamWriteCmosSensor(0x0F12, 0x0050); // #TVAR_ash_pGAS[55]																								   
    CamWriteCmosSensor(0x0F12, 0x0023); // #TVAR_ash_pGAS[56]																								   
    CamWriteCmosSensor(0x0F12, 0x000B); // #TVAR_ash_pGAS[57]																								   
    CamWriteCmosSensor(0x0F12, 0x0005); // #TVAR_ash_pGAS[58]																								   
    CamWriteCmosSensor(0x0F12, 0x000F); // #TVAR_ash_pGAS[59]																								   
    CamWriteCmosSensor(0x0F12, 0x0029); // #TVAR_ash_pGAS[60]																								   
    CamWriteCmosSensor(0x0F12, 0x005A); // #TVAR_ash_pGAS[61]																								   
    CamWriteCmosSensor(0x0F12, 0x009B); // #TVAR_ash_pGAS[62]																								   
    CamWriteCmosSensor(0x0F12, 0x00EE); // #TVAR_ash_pGAS[63]																								   
    CamWriteCmosSensor(0x0F12, 0x0139); // #TVAR_ash_pGAS[64]																								   
    CamWriteCmosSensor(0x0F12, 0x0118); // #TVAR_ash_pGAS[65]																								   
    CamWriteCmosSensor(0x0F12, 0x00D0); // #TVAR_ash_pGAS[66]																								   
    CamWriteCmosSensor(0x0F12, 0x0082); // #TVAR_ash_pGAS[67]																								   
    CamWriteCmosSensor(0x0F12, 0x0046); // #TVAR_ash_pGAS[68]																								   
    CamWriteCmosSensor(0x0F12, 0x001C); // #TVAR_ash_pGAS[69]																								   
    CamWriteCmosSensor(0x0F12, 0x0007); // #TVAR_ash_pGAS[70]																								   
    CamWriteCmosSensor(0x0F12, 0x0000); // #TVAR_ash_pGAS[71]																								   
    CamWriteCmosSensor(0x0F12, 0x0009); // #TVAR_ash_pGAS[72]																								   
    CamWriteCmosSensor(0x0F12, 0x0026); // #TVAR_ash_pGAS[73]																								   
    CamWriteCmosSensor(0x0F12, 0x0056); // #TVAR_ash_pGAS[74]																								   
    CamWriteCmosSensor(0x0F12, 0x009A); // #TVAR_ash_pGAS[75]																								   
    CamWriteCmosSensor(0x0F12, 0x00EF); // #TVAR_ash_pGAS[76]																								   
    CamWriteCmosSensor(0x0F12, 0x013F); // #TVAR_ash_pGAS[77]																								   
    CamWriteCmosSensor(0x0F12, 0x0118); // #TVAR_ash_pGAS[78]																								   
    CamWriteCmosSensor(0x0F12, 0x00D8); // #TVAR_ash_pGAS[79]																								   
    CamWriteCmosSensor(0x0F12, 0x008B); // #TVAR_ash_pGAS[80]																								   
    CamWriteCmosSensor(0x0F12, 0x0053); // #TVAR_ash_pGAS[81]																								   
    CamWriteCmosSensor(0x0F12, 0x0029); // #TVAR_ash_pGAS[82]																								   
    CamWriteCmosSensor(0x0F12, 0x0012); // #TVAR_ash_pGAS[83]																								   
    CamWriteCmosSensor(0x0F12, 0x000B); // #TVAR_ash_pGAS[84]																								   
    CamWriteCmosSensor(0x0F12, 0x0016); // #TVAR_ash_pGAS[85]																								   
    CamWriteCmosSensor(0x0F12, 0x0032); // #TVAR_ash_pGAS[86]																								   
    CamWriteCmosSensor(0x0F12, 0x0065); // #TVAR_ash_pGAS[87]																								   
    CamWriteCmosSensor(0x0F12, 0x00AA); // #TVAR_ash_pGAS[88]																								   
    CamWriteCmosSensor(0x0F12, 0x00FD); // #TVAR_ash_pGAS[89]																								   
    CamWriteCmosSensor(0x0F12, 0x014A); // #TVAR_ash_pGAS[90]																								   
    CamWriteCmosSensor(0x0F12, 0x0133); // #TVAR_ash_pGAS[91]																								   
    CamWriteCmosSensor(0x0F12, 0x00F0); // #TVAR_ash_pGAS[92]																								   
    CamWriteCmosSensor(0x0F12, 0x00A8); // #TVAR_ash_pGAS[93]																								   
    CamWriteCmosSensor(0x0F12, 0x006B); // #TVAR_ash_pGAS[94]																								   
    CamWriteCmosSensor(0x0F12, 0x0045); // #TVAR_ash_pGAS[95]																								   
    CamWriteCmosSensor(0x0F12, 0x002D); // #TVAR_ash_pGAS[96]																								   
    CamWriteCmosSensor(0x0F12, 0x0027); // #TVAR_ash_pGAS[97]																								   
    CamWriteCmosSensor(0x0F12, 0x0032); // #TVAR_ash_pGAS[98]																								   
    CamWriteCmosSensor(0x0F12, 0x0051); // #TVAR_ash_pGAS[99]																								   
    CamWriteCmosSensor(0x0F12, 0x0084); // #TVAR_ash_pGAS[100]																								   
    CamWriteCmosSensor(0x0F12, 0x00CA); // #TVAR_ash_pGAS[101]																								   
    CamWriteCmosSensor(0x0F12, 0x011D); // #TVAR_ash_pGAS[102]																								   
    CamWriteCmosSensor(0x0F12, 0x0168); // #TVAR_ash_pGAS[103]																								   
    CamWriteCmosSensor(0x0F12, 0x0155); // #TVAR_ash_pGAS[104]																								   
    CamWriteCmosSensor(0x0F12, 0x0119); // #TVAR_ash_pGAS[105]																								   
    CamWriteCmosSensor(0x0F12, 0x00CE); // #TVAR_ash_pGAS[106]																								   
    CamWriteCmosSensor(0x0F12, 0x0098); // #TVAR_ash_pGAS[107]																								   
    CamWriteCmosSensor(0x0F12, 0x0072); // #TVAR_ash_pGAS[108]																								   
    CamWriteCmosSensor(0x0F12, 0x005B); // #TVAR_ash_pGAS[109]																								   
    CamWriteCmosSensor(0x0F12, 0x0053); // #TVAR_ash_pGAS[110]																								   
    CamWriteCmosSensor(0x0F12, 0x005F); // #TVAR_ash_pGAS[111]																								   
    CamWriteCmosSensor(0x0F12, 0x0082); // #TVAR_ash_pGAS[112]																								   
    CamWriteCmosSensor(0x0F12, 0x00B5); // #TVAR_ash_pGAS[113]																								   
    CamWriteCmosSensor(0x0F12, 0x00F8); // #TVAR_ash_pGAS[114]																								   
    CamWriteCmosSensor(0x0F12, 0x0146); // #TVAR_ash_pGAS[115]																								   
    CamWriteCmosSensor(0x0F12, 0x018F); // #TVAR_ash_pGAS[116]																								   
    CamWriteCmosSensor(0x0F12, 0x0187); // #TVAR_ash_pGAS[117]																								   
    CamWriteCmosSensor(0x0F12, 0x0144); // #TVAR_ash_pGAS[118]																								   
    CamWriteCmosSensor(0x0F12, 0x0104); // #TVAR_ash_pGAS[119]																								   
    CamWriteCmosSensor(0x0F12, 0x00D3); // #TVAR_ash_pGAS[120]																								   
    CamWriteCmosSensor(0x0F12, 0x00B0); // #TVAR_ash_pGAS[121]																								   
    CamWriteCmosSensor(0x0F12, 0x009D); // #TVAR_ash_pGAS[122]																								   
    CamWriteCmosSensor(0x0F12, 0x0095); // #TVAR_ash_pGAS[123]																								   
    CamWriteCmosSensor(0x0F12, 0x00A2); // #TVAR_ash_pGAS[124]																								   
    CamWriteCmosSensor(0x0F12, 0x00C3); // #TVAR_ash_pGAS[125]																								   
    CamWriteCmosSensor(0x0F12, 0x00F3); // #TVAR_ash_pGAS[126]																								   
    CamWriteCmosSensor(0x0F12, 0x012F); // #TVAR_ash_pGAS[127]																								   
    CamWriteCmosSensor(0x0F12, 0x0179); // #TVAR_ash_pGAS[128]																								   
    CamWriteCmosSensor(0x0F12, 0x01BB); // #TVAR_ash_pGAS[129]																								   
    CamWriteCmosSensor(0x0F12, 0x01AF); // #TVAR_ash_pGAS[130]																								   
    CamWriteCmosSensor(0x0F12, 0x017B); // #TVAR_ash_pGAS[131]																								   
    CamWriteCmosSensor(0x0F12, 0x013F); // #TVAR_ash_pGAS[132]																								   
    CamWriteCmosSensor(0x0F12, 0x0116); // #TVAR_ash_pGAS[133]																								   
    CamWriteCmosSensor(0x0F12, 0x00F6); // #TVAR_ash_pGAS[134]																								   
    CamWriteCmosSensor(0x0F12, 0x00E4); // #TVAR_ash_pGAS[135]																								   
    CamWriteCmosSensor(0x0F12, 0x00DF); // #TVAR_ash_pGAS[136]																								   
    CamWriteCmosSensor(0x0F12, 0x00EB); // #TVAR_ash_pGAS[137]																								   
    CamWriteCmosSensor(0x0F12, 0x010B); // #TVAR_ash_pGAS[138]																								   
    CamWriteCmosSensor(0x0F12, 0x0134); // #TVAR_ash_pGAS[139]																								   
    CamWriteCmosSensor(0x0F12, 0x016C); // #TVAR_ash_pGAS[140]																								   
    CamWriteCmosSensor(0x0F12, 0x01B2); // #TVAR_ash_pGAS[141]																								   
    CamWriteCmosSensor(0x0F12, 0x01EB); // #TVAR_ash_pGAS[142]																								   
    CamWriteCmosSensor(0x0F12, 0x017A); // #TVAR_ash_pGAS[143]																								   
    CamWriteCmosSensor(0x0F12, 0x013A); // #TVAR_ash_pGAS[144]																								   
    CamWriteCmosSensor(0x0F12, 0x0107); // #TVAR_ash_pGAS[145]																								   
    CamWriteCmosSensor(0x0F12, 0x00E2); // #TVAR_ash_pGAS[146]																								   
    CamWriteCmosSensor(0x0F12, 0x00C0); // #TVAR_ash_pGAS[147]																								   
    CamWriteCmosSensor(0x0F12, 0x00A8); // #TVAR_ash_pGAS[148]																								   
    CamWriteCmosSensor(0x0F12, 0x009C); // #TVAR_ash_pGAS[149]																								   
    CamWriteCmosSensor(0x0F12, 0x00A2); // #TVAR_ash_pGAS[150]																								   
    CamWriteCmosSensor(0x0F12, 0x00B4); // #TVAR_ash_pGAS[151]																								   
    CamWriteCmosSensor(0x0F12, 0x00D5); // #TVAR_ash_pGAS[152]																								   
    CamWriteCmosSensor(0x0F12, 0x00FA); // #TVAR_ash_pGAS[153]																								   
    CamWriteCmosSensor(0x0F12, 0x0131); // #TVAR_ash_pGAS[154]																								   
    CamWriteCmosSensor(0x0F12, 0x0162); // #TVAR_ash_pGAS[155]																								   
    CamWriteCmosSensor(0x0F12, 0x015A); // #TVAR_ash_pGAS[156]																								   
    CamWriteCmosSensor(0x0F12, 0x0113); // #TVAR_ash_pGAS[157]																								   
    CamWriteCmosSensor(0x0F12, 0x00DA); // #TVAR_ash_pGAS[158]																								   
    CamWriteCmosSensor(0x0F12, 0x00AE); // #TVAR_ash_pGAS[159]																								   
    CamWriteCmosSensor(0x0F12, 0x0089); // #TVAR_ash_pGAS[160]																								   
    CamWriteCmosSensor(0x0F12, 0x006E); // #TVAR_ash_pGAS[161]																								   
    CamWriteCmosSensor(0x0F12, 0x0065); // #TVAR_ash_pGAS[162]																								   
    CamWriteCmosSensor(0x0F12, 0x006C); // #TVAR_ash_pGAS[163]																								   
    CamWriteCmosSensor(0x0F12, 0x0081); // #TVAR_ash_pGAS[164]																								   
    CamWriteCmosSensor(0x0F12, 0x00A2); // #TVAR_ash_pGAS[165]																								   
    CamWriteCmosSensor(0x0F12, 0x00CD); // #TVAR_ash_pGAS[166]																								   
    CamWriteCmosSensor(0x0F12, 0x0108); // #TVAR_ash_pGAS[167]																								   
    CamWriteCmosSensor(0x0F12, 0x014C); // #TVAR_ash_pGAS[168]																								   
    CamWriteCmosSensor(0x0F12, 0x0131); // #TVAR_ash_pGAS[169]																								   
    CamWriteCmosSensor(0x0F12, 0x00EF); // #TVAR_ash_pGAS[170]																								   
    CamWriteCmosSensor(0x0F12, 0x00B1); // #TVAR_ash_pGAS[171]																								   
    CamWriteCmosSensor(0x0F12, 0x0080); // #TVAR_ash_pGAS[172]																								   
    CamWriteCmosSensor(0x0F12, 0x0058); // #TVAR_ash_pGAS[173]																								   
    CamWriteCmosSensor(0x0F12, 0x003F); // #TVAR_ash_pGAS[174]																								   
    CamWriteCmosSensor(0x0F12, 0x0034); // #TVAR_ash_pGAS[175]																								   
    CamWriteCmosSensor(0x0F12, 0x003B); // #TVAR_ash_pGAS[176]																								   
    CamWriteCmosSensor(0x0F12, 0x0052); // #TVAR_ash_pGAS[177]																								   
    CamWriteCmosSensor(0x0F12, 0x0078); // #TVAR_ash_pGAS[178]																								   
    CamWriteCmosSensor(0x0F12, 0x00AB); // #TVAR_ash_pGAS[179]																								   
    CamWriteCmosSensor(0x0F12, 0x00EB); // #TVAR_ash_pGAS[180]																								   
    CamWriteCmosSensor(0x0F12, 0x012A); // #TVAR_ash_pGAS[181]																								   
    CamWriteCmosSensor(0x0F12, 0x0115); // #TVAR_ash_pGAS[182]																								   
    CamWriteCmosSensor(0x0F12, 0x00D3); // #TVAR_ash_pGAS[183]																								   
    CamWriteCmosSensor(0x0F12, 0x0094); // #TVAR_ash_pGAS[184]																								   
    CamWriteCmosSensor(0x0F12, 0x005F); // #TVAR_ash_pGAS[185]																								   
    CamWriteCmosSensor(0x0F12, 0x0035); // #TVAR_ash_pGAS[186]																								   
    CamWriteCmosSensor(0x0F12, 0x001D); // #TVAR_ash_pGAS[187]																								   
    CamWriteCmosSensor(0x0F12, 0x0014); // #TVAR_ash_pGAS[188]																								   
    CamWriteCmosSensor(0x0F12, 0x001C); // #TVAR_ash_pGAS[189]																								   
    CamWriteCmosSensor(0x0F12, 0x0033); // #TVAR_ash_pGAS[190]																								   
    CamWriteCmosSensor(0x0F12, 0x005D); // #TVAR_ash_pGAS[191]																								   
    CamWriteCmosSensor(0x0F12, 0x0093); // #TVAR_ash_pGAS[192]																								   
    CamWriteCmosSensor(0x0F12, 0x00D5); // #TVAR_ash_pGAS[193]																								   
    CamWriteCmosSensor(0x0F12, 0x011C); // #TVAR_ash_pGAS[194]																								   
    CamWriteCmosSensor(0x0F12, 0x0105); // #TVAR_ash_pGAS[195]																								   
    CamWriteCmosSensor(0x0F12, 0x00BB); // #TVAR_ash_pGAS[196]																								   
    CamWriteCmosSensor(0x0F12, 0x007C); // #TVAR_ash_pGAS[197]																								   
    CamWriteCmosSensor(0x0F12, 0x004A); // #TVAR_ash_pGAS[198]																								   
    CamWriteCmosSensor(0x0F12, 0x001F); // #TVAR_ash_pGAS[199]																								   
    CamWriteCmosSensor(0x0F12, 0x0008); // #TVAR_ash_pGAS[200]																								   
    CamWriteCmosSensor(0x0F12, 0x0003); // #TVAR_ash_pGAS[201]																								   
    CamWriteCmosSensor(0x0F12, 0x000B); // #TVAR_ash_pGAS[202]																								   
    CamWriteCmosSensor(0x0F12, 0x0025); // #TVAR_ash_pGAS[203]																								   
    CamWriteCmosSensor(0x0F12, 0x004E); // #TVAR_ash_pGAS[204]																								   
    CamWriteCmosSensor(0x0F12, 0x0084); // #TVAR_ash_pGAS[205]																								   
    CamWriteCmosSensor(0x0F12, 0x00C9); // #TVAR_ash_pGAS[206]																								   
    CamWriteCmosSensor(0x0F12, 0x0110); // #TVAR_ash_pGAS[207]																								   
    CamWriteCmosSensor(0x0F12, 0x00FD); // #TVAR_ash_pGAS[208]																								   
    CamWriteCmosSensor(0x0F12, 0x00B6); // #TVAR_ash_pGAS[209]																								   
    CamWriteCmosSensor(0x0F12, 0x0075); // #TVAR_ash_pGAS[210]																								   
    CamWriteCmosSensor(0x0F12, 0x0041); // #TVAR_ash_pGAS[211]																								   
    CamWriteCmosSensor(0x0F12, 0x001A); // #TVAR_ash_pGAS[212]																								   
    CamWriteCmosSensor(0x0F12, 0x0005); // #TVAR_ash_pGAS[213]																								   
    CamWriteCmosSensor(0x0F12, 0x0000); // #TVAR_ash_pGAS[214]																								   
    CamWriteCmosSensor(0x0F12, 0x0008); // #TVAR_ash_pGAS[215]																								   
    CamWriteCmosSensor(0x0F12, 0x0023); // #TVAR_ash_pGAS[216]																								   
    CamWriteCmosSensor(0x0F12, 0x004C); // #TVAR_ash_pGAS[217]																								   
    CamWriteCmosSensor(0x0F12, 0x0086); // #TVAR_ash_pGAS[218]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[219]																								   
    CamWriteCmosSensor(0x0F12, 0x0117); // #TVAR_ash_pGAS[220]																								   
    CamWriteCmosSensor(0x0F12, 0x00FA); // #TVAR_ash_pGAS[221]																								   
    CamWriteCmosSensor(0x0F12, 0x00B8); // #TVAR_ash_pGAS[222]																								   
    CamWriteCmosSensor(0x0F12, 0x007A); // #TVAR_ash_pGAS[223]																								   
    CamWriteCmosSensor(0x0F12, 0x0048); // #TVAR_ash_pGAS[224]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[225]																								   
    CamWriteCmosSensor(0x0F12, 0x000F); // #TVAR_ash_pGAS[226]																								   
    CamWriteCmosSensor(0x0F12, 0x0009); // #TVAR_ash_pGAS[227]																								   
    CamWriteCmosSensor(0x0F12, 0x0013); // #TVAR_ash_pGAS[228]																								   
    CamWriteCmosSensor(0x0F12, 0x002F); // #TVAR_ash_pGAS[229]																								   
    CamWriteCmosSensor(0x0F12, 0x005A); // #TVAR_ash_pGAS[230]																								   
    CamWriteCmosSensor(0x0F12, 0x0092); // #TVAR_ash_pGAS[231]																								   
    CamWriteCmosSensor(0x0F12, 0x00D7); // #TVAR_ash_pGAS[232]																								   
    CamWriteCmosSensor(0x0F12, 0x011F); // #TVAR_ash_pGAS[233]																								   
    CamWriteCmosSensor(0x0F12, 0x010B); // #TVAR_ash_pGAS[234]																								   
    CamWriteCmosSensor(0x0F12, 0x00CB); // #TVAR_ash_pGAS[235]																								   
    CamWriteCmosSensor(0x0F12, 0x008F); // #TVAR_ash_pGAS[236]																								   
    CamWriteCmosSensor(0x0F12, 0x005D); // #TVAR_ash_pGAS[237]																								   
    CamWriteCmosSensor(0x0F12, 0x003B); // #TVAR_ash_pGAS[238]																								   
    CamWriteCmosSensor(0x0F12, 0x0027); // #TVAR_ash_pGAS[239]																								   
    CamWriteCmosSensor(0x0F12, 0x0021); // #TVAR_ash_pGAS[240]																								   
    CamWriteCmosSensor(0x0F12, 0x002C); // #TVAR_ash_pGAS[241]																								   
    CamWriteCmosSensor(0x0F12, 0x0048); // #TVAR_ash_pGAS[242]																								   
    CamWriteCmosSensor(0x0F12, 0x0074); // #TVAR_ash_pGAS[243]																								   
    CamWriteCmosSensor(0x0F12, 0x00AE); // #TVAR_ash_pGAS[244]																								   
    CamWriteCmosSensor(0x0F12, 0x00F2); // #TVAR_ash_pGAS[245]																								   
    CamWriteCmosSensor(0x0F12, 0x0137); // #TVAR_ash_pGAS[246]																								   
    CamWriteCmosSensor(0x0F12, 0x012B); // #TVAR_ash_pGAS[247]																								   
    CamWriteCmosSensor(0x0F12, 0x00EB); // #TVAR_ash_pGAS[248]																								   
    CamWriteCmosSensor(0x0F12, 0x00AF); // #TVAR_ash_pGAS[249]																								   
    CamWriteCmosSensor(0x0F12, 0x0081); // #TVAR_ash_pGAS[250]																								   
    CamWriteCmosSensor(0x0F12, 0x0061); // #TVAR_ash_pGAS[251]																								   
    CamWriteCmosSensor(0x0F12, 0x004D); // #TVAR_ash_pGAS[252]																								   
    CamWriteCmosSensor(0x0F12, 0x0047); // #TVAR_ash_pGAS[253]																								   
    CamWriteCmosSensor(0x0F12, 0x0053); // #TVAR_ash_pGAS[254]																								   
    CamWriteCmosSensor(0x0F12, 0x0072); // #TVAR_ash_pGAS[255]																								   
    CamWriteCmosSensor(0x0F12, 0x009B); // #TVAR_ash_pGAS[256]																								   
    CamWriteCmosSensor(0x0F12, 0x00D4); // #TVAR_ash_pGAS[257]																								   
    CamWriteCmosSensor(0x0F12, 0x0113); // #TVAR_ash_pGAS[258]																								   
    CamWriteCmosSensor(0x0F12, 0x0157); // #TVAR_ash_pGAS[259]																								   
    CamWriteCmosSensor(0x0F12, 0x0153); // #TVAR_ash_pGAS[260]																								   
    CamWriteCmosSensor(0x0F12, 0x010E); // #TVAR_ash_pGAS[261]																								   
    CamWriteCmosSensor(0x0F12, 0x00DA); // #TVAR_ash_pGAS[262]																								   
    CamWriteCmosSensor(0x0F12, 0x00AD); // #TVAR_ash_pGAS[263]																								   
    CamWriteCmosSensor(0x0F12, 0x0091); // #TVAR_ash_pGAS[264]																								   
    CamWriteCmosSensor(0x0F12, 0x0082); // #TVAR_ash_pGAS[265]																								   
    CamWriteCmosSensor(0x0F12, 0x007B); // #TVAR_ash_pGAS[266]																								   
    CamWriteCmosSensor(0x0F12, 0x008A); // #TVAR_ash_pGAS[267]																								   
    CamWriteCmosSensor(0x0F12, 0x00A6); // #TVAR_ash_pGAS[268]																								   
    CamWriteCmosSensor(0x0F12, 0x00CD); // #TVAR_ash_pGAS[269]																								   
    CamWriteCmosSensor(0x0F12, 0x0100); // #TVAR_ash_pGAS[270]																								   
    CamWriteCmosSensor(0x0F12, 0x013D); // #TVAR_ash_pGAS[271]																								   
    CamWriteCmosSensor(0x0F12, 0x0183); // #TVAR_ash_pGAS[272]																								   
    CamWriteCmosSensor(0x0F12, 0x0175); // #TVAR_ash_pGAS[273]																								   
    CamWriteCmosSensor(0x0F12, 0x013D); // #TVAR_ash_pGAS[274]																								   
    CamWriteCmosSensor(0x0F12, 0x0107); // #TVAR_ash_pGAS[275]																								   
    CamWriteCmosSensor(0x0F12, 0x00E5); // #TVAR_ash_pGAS[276]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[277]																								   
    CamWriteCmosSensor(0x0F12, 0x00BA); // #TVAR_ash_pGAS[278]																								   
    CamWriteCmosSensor(0x0F12, 0x00B9); // #TVAR_ash_pGAS[279]																								   
    CamWriteCmosSensor(0x0F12, 0x00C5); // #TVAR_ash_pGAS[280]																								   
    CamWriteCmosSensor(0x0F12, 0x00E4); // #TVAR_ash_pGAS[281]																								   
    CamWriteCmosSensor(0x0F12, 0x0108); // #TVAR_ash_pGAS[282]																								   
    CamWriteCmosSensor(0x0F12, 0x0138); // #TVAR_ash_pGAS[283]																								   
    CamWriteCmosSensor(0x0F12, 0x0175); // #TVAR_ash_pGAS[284]																								   
    CamWriteCmosSensor(0x0F12, 0x01AC); // #TVAR_ash_pGAS[285]																								   
    CamWriteCmosSensor(0x0F12, 0x015E); // #TVAR_ash_pGAS[286]																								   
    CamWriteCmosSensor(0x0F12, 0x0123); // #TVAR_ash_pGAS[287]																								   
    CamWriteCmosSensor(0x0F12, 0x00F0); // #TVAR_ash_pGAS[288]																								   
    CamWriteCmosSensor(0x0F12, 0x00D0); // #TVAR_ash_pGAS[289]																								   
    CamWriteCmosSensor(0x0F12, 0x00B4); // #TVAR_ash_pGAS[290]																								   
    CamWriteCmosSensor(0x0F12, 0x00A3); // #TVAR_ash_pGAS[291]																								   
    CamWriteCmosSensor(0x0F12, 0x009F); // #TVAR_ash_pGAS[292]																								   
    CamWriteCmosSensor(0x0F12, 0x00A9); // #TVAR_ash_pGAS[293]																								   
    CamWriteCmosSensor(0x0F12, 0x00C1); // #TVAR_ash_pGAS[294]																								   
    CamWriteCmosSensor(0x0F12, 0x00E5); // #TVAR_ash_pGAS[295]																								   
    CamWriteCmosSensor(0x0F12, 0x010D); // #TVAR_ash_pGAS[296]																								   
    CamWriteCmosSensor(0x0F12, 0x0147); // #TVAR_ash_pGAS[297]																								   
    CamWriteCmosSensor(0x0F12, 0x017A); // #TVAR_ash_pGAS[298]																								   
    CamWriteCmosSensor(0x0F12, 0x0140); // #TVAR_ash_pGAS[299]																								   
    CamWriteCmosSensor(0x0F12, 0x00FD); // #TVAR_ash_pGAS[300]																								   
    CamWriteCmosSensor(0x0F12, 0x00C8); // #TVAR_ash_pGAS[301]																								   
    CamWriteCmosSensor(0x0F12, 0x009D); // #TVAR_ash_pGAS[302]																								   
    CamWriteCmosSensor(0x0F12, 0x007F); // #TVAR_ash_pGAS[303]																								   
    CamWriteCmosSensor(0x0F12, 0x006A); // #TVAR_ash_pGAS[304]																								   
    CamWriteCmosSensor(0x0F12, 0x0066); // #TVAR_ash_pGAS[305]																								   
    CamWriteCmosSensor(0x0F12, 0x0073); // #TVAR_ash_pGAS[306]																								   
    CamWriteCmosSensor(0x0F12, 0x008C); // #TVAR_ash_pGAS[307]																								   
    CamWriteCmosSensor(0x0F12, 0x00B1); // #TVAR_ash_pGAS[308]																								   
    CamWriteCmosSensor(0x0F12, 0x00DF); // #TVAR_ash_pGAS[309]																								   
    CamWriteCmosSensor(0x0F12, 0x011C); // #TVAR_ash_pGAS[310]																								   
    CamWriteCmosSensor(0x0F12, 0x0163); // #TVAR_ash_pGAS[311]																								   
    CamWriteCmosSensor(0x0F12, 0x011B); // #TVAR_ash_pGAS[312]																								   
    CamWriteCmosSensor(0x0F12, 0x00DB); // #TVAR_ash_pGAS[313]																								   
    CamWriteCmosSensor(0x0F12, 0x00A0); // #TVAR_ash_pGAS[314]																								   
    CamWriteCmosSensor(0x0F12, 0x0074); // #TVAR_ash_pGAS[315]																								   
    CamWriteCmosSensor(0x0F12, 0x0051); // #TVAR_ash_pGAS[316]																								   
    CamWriteCmosSensor(0x0F12, 0x003C); // #TVAR_ash_pGAS[317]																								   
    CamWriteCmosSensor(0x0F12, 0x0035); // #TVAR_ash_pGAS[318]																								   
    CamWriteCmosSensor(0x0F12, 0x003F); // #TVAR_ash_pGAS[319]																								   
    CamWriteCmosSensor(0x0F12, 0x005A); // #TVAR_ash_pGAS[320]																								   
    CamWriteCmosSensor(0x0F12, 0x0082); // #TVAR_ash_pGAS[321]																								   
    CamWriteCmosSensor(0x0F12, 0x00B8); // #TVAR_ash_pGAS[322]																								   
    CamWriteCmosSensor(0x0F12, 0x00F9); // #TVAR_ash_pGAS[323]																								   
    CamWriteCmosSensor(0x0F12, 0x0139); // #TVAR_ash_pGAS[324]																								   
    CamWriteCmosSensor(0x0F12, 0x0101); // #TVAR_ash_pGAS[325]																								   
    CamWriteCmosSensor(0x0F12, 0x00C2); // #TVAR_ash_pGAS[326]																								   
    CamWriteCmosSensor(0x0F12, 0x0087); // #TVAR_ash_pGAS[327]																								   
    CamWriteCmosSensor(0x0F12, 0x0056); // #TVAR_ash_pGAS[328]																								   
    CamWriteCmosSensor(0x0F12, 0x002F); // #TVAR_ash_pGAS[329]																								   
    CamWriteCmosSensor(0x0F12, 0x001B); // #TVAR_ash_pGAS[330]																								   
    CamWriteCmosSensor(0x0F12, 0x0015); // #TVAR_ash_pGAS[331]																								   
    CamWriteCmosSensor(0x0F12, 0x001E); // #TVAR_ash_pGAS[332]																								   
    CamWriteCmosSensor(0x0F12, 0x0039); // #TVAR_ash_pGAS[333]																								   
    CamWriteCmosSensor(0x0F12, 0x0064); // #TVAR_ash_pGAS[334]																								   
    CamWriteCmosSensor(0x0F12, 0x009A); // #TVAR_ash_pGAS[335]																								   
    CamWriteCmosSensor(0x0F12, 0x00DD); // #TVAR_ash_pGAS[336]																								   
    CamWriteCmosSensor(0x0F12, 0x0124); // #TVAR_ash_pGAS[337]																								   
    CamWriteCmosSensor(0x0F12, 0x00F5); // #TVAR_ash_pGAS[338]																								   
    CamWriteCmosSensor(0x0F12, 0x00B0); // #TVAR_ash_pGAS[339]																								   
    CamWriteCmosSensor(0x0F12, 0x0074); // #TVAR_ash_pGAS[340]																								   
    CamWriteCmosSensor(0x0F12, 0x0044); // #TVAR_ash_pGAS[341]																								   
    CamWriteCmosSensor(0x0F12, 0x001D); // #TVAR_ash_pGAS[342]																								   
    CamWriteCmosSensor(0x0F12, 0x0008); // #TVAR_ash_pGAS[343]																								   
    CamWriteCmosSensor(0x0F12, 0x0003); // #TVAR_ash_pGAS[344]																								   
    CamWriteCmosSensor(0x0F12, 0x000D); // #TVAR_ash_pGAS[345]																								   
    CamWriteCmosSensor(0x0F12, 0x0028); // #TVAR_ash_pGAS[346]																								   
    CamWriteCmosSensor(0x0F12, 0x0051); // #TVAR_ash_pGAS[347]																								   
    CamWriteCmosSensor(0x0F12, 0x0087); // #TVAR_ash_pGAS[348]																								   
    CamWriteCmosSensor(0x0F12, 0x00CB); // #TVAR_ash_pGAS[349]																								   
    CamWriteCmosSensor(0x0F12, 0x0112); // #TVAR_ash_pGAS[350]																								   
    CamWriteCmosSensor(0x0F12, 0x00F4); // #TVAR_ash_pGAS[351]																								   
    CamWriteCmosSensor(0x0F12, 0x00AF); // #TVAR_ash_pGAS[352]																								   
    CamWriteCmosSensor(0x0F12, 0x0072); // #TVAR_ash_pGAS[353]																								   
    CamWriteCmosSensor(0x0F12, 0x0040); // #TVAR_ash_pGAS[354]																								   
    CamWriteCmosSensor(0x0F12, 0x001A); // #TVAR_ash_pGAS[355]																								   
    CamWriteCmosSensor(0x0F12, 0x0006); // #TVAR_ash_pGAS[356]																								   
    CamWriteCmosSensor(0x0F12, 0x0000); // #TVAR_ash_pGAS[357]																								   
    CamWriteCmosSensor(0x0F12, 0x0009); // #TVAR_ash_pGAS[358]																								   
    CamWriteCmosSensor(0x0F12, 0x0023); // #TVAR_ash_pGAS[359]																								   
    CamWriteCmosSensor(0x0F12, 0x004C); // #TVAR_ash_pGAS[360]																								   
    CamWriteCmosSensor(0x0F12, 0x0085); // #TVAR_ash_pGAS[361]																								   
    CamWriteCmosSensor(0x0F12, 0x00C6); // #TVAR_ash_pGAS[362]																								   
    CamWriteCmosSensor(0x0F12, 0x0110); // #TVAR_ash_pGAS[363]																								   
    CamWriteCmosSensor(0x0F12, 0x00F5); // #TVAR_ash_pGAS[364]																								   
    CamWriteCmosSensor(0x0F12, 0x00B8); // #TVAR_ash_pGAS[365]																								   
    CamWriteCmosSensor(0x0F12, 0x007C); // #TVAR_ash_pGAS[366]																								   
    CamWriteCmosSensor(0x0F12, 0x004C); // #TVAR_ash_pGAS[367]																								   
    CamWriteCmosSensor(0x0F12, 0x0027); // #TVAR_ash_pGAS[368]																								   
    CamWriteCmosSensor(0x0F12, 0x0011); // #TVAR_ash_pGAS[369]																								   
    CamWriteCmosSensor(0x0F12, 0x000A); // #TVAR_ash_pGAS[370]																								   
    CamWriteCmosSensor(0x0F12, 0x0013); // #TVAR_ash_pGAS[371]																								   
    CamWriteCmosSensor(0x0F12, 0x002C); // #TVAR_ash_pGAS[372]																								   
    CamWriteCmosSensor(0x0F12, 0x0055); // #TVAR_ash_pGAS[373]																								   
    CamWriteCmosSensor(0x0F12, 0x008A); // #TVAR_ash_pGAS[374]																								   
    CamWriteCmosSensor(0x0F12, 0x00CD); // #TVAR_ash_pGAS[375]																								   
    CamWriteCmosSensor(0x0F12, 0x0110); // #TVAR_ash_pGAS[376]																								   
    CamWriteCmosSensor(0x0F12, 0x010D); // #TVAR_ash_pGAS[377]																								   
    CamWriteCmosSensor(0x0F12, 0x00D1); // #TVAR_ash_pGAS[378]																								   
    CamWriteCmosSensor(0x0F12, 0x0096); // #TVAR_ash_pGAS[379]																								   
    CamWriteCmosSensor(0x0F12, 0x0064); // #TVAR_ash_pGAS[380]																								   
    CamWriteCmosSensor(0x0F12, 0x0041); // #TVAR_ash_pGAS[381]																								   
    CamWriteCmosSensor(0x0F12, 0x002B); // #TVAR_ash_pGAS[382]																								   
    CamWriteCmosSensor(0x0F12, 0x0022); // #TVAR_ash_pGAS[383]																								   
    CamWriteCmosSensor(0x0F12, 0x002A); // #TVAR_ash_pGAS[384]																								   
    CamWriteCmosSensor(0x0F12, 0x0043); // #TVAR_ash_pGAS[385]																								   
    CamWriteCmosSensor(0x0F12, 0x006C); // #TVAR_ash_pGAS[386]																								   
    CamWriteCmosSensor(0x0F12, 0x00A0); // #TVAR_ash_pGAS[387]																								   
    CamWriteCmosSensor(0x0F12, 0x00DF); // #TVAR_ash_pGAS[388]																								   
    CamWriteCmosSensor(0x0F12, 0x0122); // #TVAR_ash_pGAS[389]																								   
    CamWriteCmosSensor(0x0F12, 0x012E); // #TVAR_ash_pGAS[390]																								   
    CamWriteCmosSensor(0x0F12, 0x00F3); // #TVAR_ash_pGAS[391]																								   
    CamWriteCmosSensor(0x0F12, 0x00B7); // #TVAR_ash_pGAS[392]																								   
    CamWriteCmosSensor(0x0F12, 0x008B); // #TVAR_ash_pGAS[393]																								   
    CamWriteCmosSensor(0x0F12, 0x006C); // #TVAR_ash_pGAS[394]																								   
    CamWriteCmosSensor(0x0F12, 0x0052); // #TVAR_ash_pGAS[395]																								   
    CamWriteCmosSensor(0x0F12, 0x004A); // #TVAR_ash_pGAS[396]																								   
    CamWriteCmosSensor(0x0F12, 0x0051); // #TVAR_ash_pGAS[397]																								   
    CamWriteCmosSensor(0x0F12, 0x006C); // #TVAR_ash_pGAS[398]																								   
    CamWriteCmosSensor(0x0F12, 0x0090); // #TVAR_ash_pGAS[399]																								   
    CamWriteCmosSensor(0x0F12, 0x00C1); // #TVAR_ash_pGAS[400]																								   
    CamWriteCmosSensor(0x0F12, 0x00FF); // #TVAR_ash_pGAS[401]																								   
    CamWriteCmosSensor(0x0F12, 0x013F); // #TVAR_ash_pGAS[402]																								   
    CamWriteCmosSensor(0x0F12, 0x0162); // #TVAR_ash_pGAS[403]																								   
    CamWriteCmosSensor(0x0F12, 0x011C); // #TVAR_ash_pGAS[404]																								   
    CamWriteCmosSensor(0x0F12, 0x00E8); // #TVAR_ash_pGAS[405]																								   
    CamWriteCmosSensor(0x0F12, 0x00BD); // #TVAR_ash_pGAS[406]																								   
    CamWriteCmosSensor(0x0F12, 0x009F); // #TVAR_ash_pGAS[407]																								   
    CamWriteCmosSensor(0x0F12, 0x008B); // #TVAR_ash_pGAS[408]																								   
    CamWriteCmosSensor(0x0F12, 0x0080); // #TVAR_ash_pGAS[409]																								   
    CamWriteCmosSensor(0x0F12, 0x0088); // #TVAR_ash_pGAS[410]																								   
    CamWriteCmosSensor(0x0F12, 0x009F); // #TVAR_ash_pGAS[411]																								   
    CamWriteCmosSensor(0x0F12, 0x00C0); // #TVAR_ash_pGAS[412]																								   
    CamWriteCmosSensor(0x0F12, 0x00ED); // #TVAR_ash_pGAS[413]																								   
    CamWriteCmosSensor(0x0F12, 0x0124); // #TVAR_ash_pGAS[414]																								   
    CamWriteCmosSensor(0x0F12, 0x0169); // #TVAR_ash_pGAS[415]																								   
    CamWriteCmosSensor(0x0F12, 0x018D); // #TVAR_ash_pGAS[416]																								   
    CamWriteCmosSensor(0x0F12, 0x0151); // #TVAR_ash_pGAS[417]																								   
    CamWriteCmosSensor(0x0F12, 0x011D); // #TVAR_ash_pGAS[418]																								   
    CamWriteCmosSensor(0x0F12, 0x00FD); // #TVAR_ash_pGAS[419]																								   
    CamWriteCmosSensor(0x0F12, 0x00E0); // #TVAR_ash_pGAS[420]																								   
    CamWriteCmosSensor(0x0F12, 0x00C8); // #TVAR_ash_pGAS[421]																								   
    CamWriteCmosSensor(0x0F12, 0x00C1); // #TVAR_ash_pGAS[422]																								   
    CamWriteCmosSensor(0x0F12, 0x00C6); // #TVAR_ash_pGAS[423]																								   
    CamWriteCmosSensor(0x0F12, 0x00DC); // #TVAR_ash_pGAS[424]																								   
    CamWriteCmosSensor(0x0F12, 0x00F9); // #TVAR_ash_pGAS[425]																								   
    CamWriteCmosSensor(0x0F12, 0x0122); // #TVAR_ash_pGAS[426]																								   
    CamWriteCmosSensor(0x0F12, 0x015B); // #TVAR_ash_pGAS[427]																								   
    CamWriteCmosSensor(0x0F12, 0x0194); // #TVAR_ash_pGAS[428]																								   
    CamWriteCmosSensor(0x0F12, 0x012D); // #TVAR_ash_pGAS[429]																								   
    CamWriteCmosSensor(0x0F12, 0x00F9); // #TVAR_ash_pGAS[430]																								   
    CamWriteCmosSensor(0x0F12, 0x00D1); // #TVAR_ash_pGAS[431]																								   
    CamWriteCmosSensor(0x0F12, 0x00B4); // #TVAR_ash_pGAS[432]																								   
    CamWriteCmosSensor(0x0F12, 0x009A); // #TVAR_ash_pGAS[433]																								   
    CamWriteCmosSensor(0x0F12, 0x008E); // #TVAR_ash_pGAS[434]																								   
    CamWriteCmosSensor(0x0F12, 0x0089); // #TVAR_ash_pGAS[435]																								   
    CamWriteCmosSensor(0x0F12, 0x0094); // #TVAR_ash_pGAS[436]																								   
    CamWriteCmosSensor(0x0F12, 0x00A8); // #TVAR_ash_pGAS[437]																								   
    CamWriteCmosSensor(0x0F12, 0x00CB); // #TVAR_ash_pGAS[438]																								   
    CamWriteCmosSensor(0x0F12, 0x00EF); // #TVAR_ash_pGAS[439]																								   
    CamWriteCmosSensor(0x0F12, 0x011D); // #TVAR_ash_pGAS[440]																								   
    CamWriteCmosSensor(0x0F12, 0x0145); // #TVAR_ash_pGAS[441]																								   
    CamWriteCmosSensor(0x0F12, 0x0114); // #TVAR_ash_pGAS[442]																								   
    CamWriteCmosSensor(0x0F12, 0x00DA); // #TVAR_ash_pGAS[443]																								   
    CamWriteCmosSensor(0x0F12, 0x00AA); // #TVAR_ash_pGAS[444]																								   
    CamWriteCmosSensor(0x0F12, 0x0087); // #TVAR_ash_pGAS[445]																								   
    CamWriteCmosSensor(0x0F12, 0x006C); // #TVAR_ash_pGAS[446]																								   
    CamWriteCmosSensor(0x0F12, 0x005D); // #TVAR_ash_pGAS[447]																								   
    CamWriteCmosSensor(0x0F12, 0x005A); // #TVAR_ash_pGAS[448]																								   
    CamWriteCmosSensor(0x0F12, 0x0064); // #TVAR_ash_pGAS[449]																								   
    CamWriteCmosSensor(0x0F12, 0x007B); // #TVAR_ash_pGAS[450]																								   
    CamWriteCmosSensor(0x0F12, 0x009B); // #TVAR_ash_pGAS[451]																								   
    CamWriteCmosSensor(0x0F12, 0x00C3); // #TVAR_ash_pGAS[452]																								   
    CamWriteCmosSensor(0x0F12, 0x00FD); // #TVAR_ash_pGAS[453]																								   
    CamWriteCmosSensor(0x0F12, 0x0135); // #TVAR_ash_pGAS[454]																								   
    CamWriteCmosSensor(0x0F12, 0x00F3); // #TVAR_ash_pGAS[455]																								   
    CamWriteCmosSensor(0x0F12, 0x00BB); // #TVAR_ash_pGAS[456]																								   
    CamWriteCmosSensor(0x0F12, 0x0087); // #TVAR_ash_pGAS[457]																								   
    CamWriteCmosSensor(0x0F12, 0x0061); // #TVAR_ash_pGAS[458]																								   
    CamWriteCmosSensor(0x0F12, 0x0045); // #TVAR_ash_pGAS[459]																								   
    CamWriteCmosSensor(0x0F12, 0x0035); // #TVAR_ash_pGAS[460]																								   
    CamWriteCmosSensor(0x0F12, 0x002E); // #TVAR_ash_pGAS[461]																								   
    CamWriteCmosSensor(0x0F12, 0x0037); // #TVAR_ash_pGAS[462]																								   
    CamWriteCmosSensor(0x0F12, 0x004E); // #TVAR_ash_pGAS[463]																								   
    CamWriteCmosSensor(0x0F12, 0x0070); // #TVAR_ash_pGAS[464]																								   
    CamWriteCmosSensor(0x0F12, 0x00A0); // #TVAR_ash_pGAS[465]																								   
    CamWriteCmosSensor(0x0F12, 0x00DB); // #TVAR_ash_pGAS[466]																								   
    CamWriteCmosSensor(0x0F12, 0x010F); // #TVAR_ash_pGAS[467]																								   
    CamWriteCmosSensor(0x0F12, 0x00D7); // #TVAR_ash_pGAS[468]																								   
    CamWriteCmosSensor(0x0F12, 0x00A5); // #TVAR_ash_pGAS[469]																								   
    CamWriteCmosSensor(0x0F12, 0x006D); // #TVAR_ash_pGAS[470]																								   
    CamWriteCmosSensor(0x0F12, 0x0045); // #TVAR_ash_pGAS[471]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[472]																								   
    CamWriteCmosSensor(0x0F12, 0x0017); // #TVAR_ash_pGAS[473]																								   
    CamWriteCmosSensor(0x0F12, 0x0012); // #TVAR_ash_pGAS[474]																								   
    CamWriteCmosSensor(0x0F12, 0x001A); // #TVAR_ash_pGAS[475]																								   
    CamWriteCmosSensor(0x0F12, 0x0030); // #TVAR_ash_pGAS[476]																								   
    CamWriteCmosSensor(0x0F12, 0x0054); // #TVAR_ash_pGAS[477]																								   
    CamWriteCmosSensor(0x0F12, 0x0084); // #TVAR_ash_pGAS[478]																								   
    CamWriteCmosSensor(0x0F12, 0x00C0); // #TVAR_ash_pGAS[479]																								   
    CamWriteCmosSensor(0x0F12, 0x00FB); // #TVAR_ash_pGAS[480]																								   
    CamWriteCmosSensor(0x0F12, 0x00CB); // #TVAR_ash_pGAS[481]																								   
    CamWriteCmosSensor(0x0F12, 0x0091); // #TVAR_ash_pGAS[482]																								   
    CamWriteCmosSensor(0x0F12, 0x005B); // #TVAR_ash_pGAS[483]																								   
    CamWriteCmosSensor(0x0F12, 0x0033); // #TVAR_ash_pGAS[484]																								   
    CamWriteCmosSensor(0x0F12, 0x0013); // #TVAR_ash_pGAS[485]																								   
    CamWriteCmosSensor(0x0F12, 0x0004); // #TVAR_ash_pGAS[486]																								   
    CamWriteCmosSensor(0x0F12, 0x0003); // #TVAR_ash_pGAS[487]																								   
    CamWriteCmosSensor(0x0F12, 0x000A); // #TVAR_ash_pGAS[488]																								   
    CamWriteCmosSensor(0x0F12, 0x001F); // #TVAR_ash_pGAS[489]																								   
    CamWriteCmosSensor(0x0F12, 0x0043); // #TVAR_ash_pGAS[490]																								   
    CamWriteCmosSensor(0x0F12, 0x0070); // #TVAR_ash_pGAS[491]																								   
    CamWriteCmosSensor(0x0F12, 0x00AC); // #TVAR_ash_pGAS[492]																								   
    CamWriteCmosSensor(0x0F12, 0x00E6); // #TVAR_ash_pGAS[493]																								   
    CamWriteCmosSensor(0x0F12, 0x00C7); // #TVAR_ash_pGAS[494]																								   
    CamWriteCmosSensor(0x0F12, 0x008D); // #TVAR_ash_pGAS[495]																								   
    CamWriteCmosSensor(0x0F12, 0x0057); // #TVAR_ash_pGAS[496]																								   
    CamWriteCmosSensor(0x0F12, 0x002E); // #TVAR_ash_pGAS[497]																								   
    CamWriteCmosSensor(0x0F12, 0x0010); // #TVAR_ash_pGAS[498]																								   
    CamWriteCmosSensor(0x0F12, 0x0003); // #TVAR_ash_pGAS[499]																								   
    CamWriteCmosSensor(0x0F12, 0x0000); // #TVAR_ash_pGAS[500]																								   
    CamWriteCmosSensor(0x0F12, 0x0006); // #TVAR_ash_pGAS[501]																								   
    CamWriteCmosSensor(0x0F12, 0x001A); // #TVAR_ash_pGAS[502]																								   
    CamWriteCmosSensor(0x0F12, 0x003C); // #TVAR_ash_pGAS[503]																								   
    CamWriteCmosSensor(0x0F12, 0x006B); // #TVAR_ash_pGAS[504]																								   
    CamWriteCmosSensor(0x0F12, 0x00A7); // #TVAR_ash_pGAS[505]																								   
    CamWriteCmosSensor(0x0F12, 0x00E4); // #TVAR_ash_pGAS[506]																								   
    CamWriteCmosSensor(0x0F12, 0x00C5); // #TVAR_ash_pGAS[507]																								   
    CamWriteCmosSensor(0x0F12, 0x0094); // #TVAR_ash_pGAS[508]																								   
    CamWriteCmosSensor(0x0F12, 0x0060); // #TVAR_ash_pGAS[509]																								   
    CamWriteCmosSensor(0x0F12, 0x0038); // #TVAR_ash_pGAS[510]																								   
    CamWriteCmosSensor(0x0F12, 0x001D); // #TVAR_ash_pGAS[511]																								   
    CamWriteCmosSensor(0x0F12, 0x000D); // #TVAR_ash_pGAS[512]																								   
    CamWriteCmosSensor(0x0F12, 0x000A); // #TVAR_ash_pGAS[513]																								   
    CamWriteCmosSensor(0x0F12, 0x0010); // #TVAR_ash_pGAS[514]																								   
    CamWriteCmosSensor(0x0F12, 0x0023); // #TVAR_ash_pGAS[515]																								   
    CamWriteCmosSensor(0x0F12, 0x0044); // #TVAR_ash_pGAS[516]																								   
    CamWriteCmosSensor(0x0F12, 0x0072); // #TVAR_ash_pGAS[517]																								   
    CamWriteCmosSensor(0x0F12, 0x00AB); // #TVAR_ash_pGAS[518]																								   
    CamWriteCmosSensor(0x0F12, 0x00E5); // #TVAR_ash_pGAS[519]																								   
    CamWriteCmosSensor(0x0F12, 0x00DB); // #TVAR_ash_pGAS[520]																								   
    CamWriteCmosSensor(0x0F12, 0x00AB); // #TVAR_ash_pGAS[521]																								   
    CamWriteCmosSensor(0x0F12, 0x0077); // #TVAR_ash_pGAS[522]																								   
    CamWriteCmosSensor(0x0F12, 0x004D); // #TVAR_ash_pGAS[523]																								   
    CamWriteCmosSensor(0x0F12, 0x0034); // #TVAR_ash_pGAS[524]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[525]																								   
    CamWriteCmosSensor(0x0F12, 0x001F); // #TVAR_ash_pGAS[526]																								   
    CamWriteCmosSensor(0x0F12, 0x0024); // #TVAR_ash_pGAS[527]																								   
    CamWriteCmosSensor(0x0F12, 0x0038); // #TVAR_ash_pGAS[528]																								   
    CamWriteCmosSensor(0x0F12, 0x005A); // #TVAR_ash_pGAS[529]																								   
    CamWriteCmosSensor(0x0F12, 0x0084); // #TVAR_ash_pGAS[530]																								   
    CamWriteCmosSensor(0x0F12, 0x00BB); // #TVAR_ash_pGAS[531]																								   
    CamWriteCmosSensor(0x0F12, 0x00F4); // #TVAR_ash_pGAS[532]																								   
    CamWriteCmosSensor(0x0F12, 0x00FC); // #TVAR_ash_pGAS[533]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[534]																								   
    CamWriteCmosSensor(0x0F12, 0x0096); // #TVAR_ash_pGAS[535]																								   
    CamWriteCmosSensor(0x0F12, 0x0072); // #TVAR_ash_pGAS[536]																								   
    CamWriteCmosSensor(0x0F12, 0x0059); // #TVAR_ash_pGAS[537]																								   
    CamWriteCmosSensor(0x0F12, 0x0047); // #TVAR_ash_pGAS[538]																								   
    CamWriteCmosSensor(0x0F12, 0x0041); // #TVAR_ash_pGAS[539]																								   
    CamWriteCmosSensor(0x0F12, 0x0046); // #TVAR_ash_pGAS[540]																								   
    CamWriteCmosSensor(0x0F12, 0x005D); // #TVAR_ash_pGAS[541]																								   
    CamWriteCmosSensor(0x0F12, 0x0079); // #TVAR_ash_pGAS[542]																								   
    CamWriteCmosSensor(0x0F12, 0x00A4); // #TVAR_ash_pGAS[543]																								   
    CamWriteCmosSensor(0x0F12, 0x00D8); // #TVAR_ash_pGAS[544]																								   
    CamWriteCmosSensor(0x0F12, 0x010D); // #TVAR_ash_pGAS[545]																								   
    CamWriteCmosSensor(0x0F12, 0x012B); // #TVAR_ash_pGAS[546]																								   
    CamWriteCmosSensor(0x0F12, 0x00F3); // #TVAR_ash_pGAS[547]																								   
    CamWriteCmosSensor(0x0F12, 0x00C7); // #TVAR_ash_pGAS[548]																								   
    CamWriteCmosSensor(0x0F12, 0x00A2); // #TVAR_ash_pGAS[549]																								   
    CamWriteCmosSensor(0x0F12, 0x008B); // #TVAR_ash_pGAS[550]																								   
    CamWriteCmosSensor(0x0F12, 0x007E); // #TVAR_ash_pGAS[551]																								   
    CamWriteCmosSensor(0x0F12, 0x0074); // #TVAR_ash_pGAS[552]																								   
    CamWriteCmosSensor(0x0F12, 0x007A); // #TVAR_ash_pGAS[553]																								   
    CamWriteCmosSensor(0x0F12, 0x008C); // #TVAR_ash_pGAS[554]																								   
    CamWriteCmosSensor(0x0F12, 0x00A7); // #TVAR_ash_pGAS[555]																								   
    CamWriteCmosSensor(0x0F12, 0x00CC); // #TVAR_ash_pGAS[556]																								   
    CamWriteCmosSensor(0x0F12, 0x00FF); // #TVAR_ash_pGAS[557]																								   
    CamWriteCmosSensor(0x0F12, 0x0132); // #TVAR_ash_pGAS[558]																								   
    CamWriteCmosSensor(0x0F12, 0x014F); // #TVAR_ash_pGAS[559]																								   
    CamWriteCmosSensor(0x0F12, 0x0122); // #TVAR_ash_pGAS[560]																								   
    CamWriteCmosSensor(0x0F12, 0x00F2); // #TVAR_ash_pGAS[561]																								   
    CamWriteCmosSensor(0x0F12, 0x00D9); // #TVAR_ash_pGAS[562]																								   
    CamWriteCmosSensor(0x0F12, 0x00C2); // #TVAR_ash_pGAS[563]																								   
    CamWriteCmosSensor(0x0F12, 0x00B3); // #TVAR_ash_pGAS[564]																								   
    CamWriteCmosSensor(0x0F12, 0x00AB); // #TVAR_ash_pGAS[565]																								   
    CamWriteCmosSensor(0x0F12, 0x00B0); // #TVAR_ash_pGAS[566]																								   
    CamWriteCmosSensor(0x0F12, 0x00C0); // #TVAR_ash_pGAS[567]																								   
    CamWriteCmosSensor(0x0F12, 0x00D8); // #TVAR_ash_pGAS[568]																								   
    CamWriteCmosSensor(0x0F12, 0x00FA); // #TVAR_ash_pGAS[569]																								   
    CamWriteCmosSensor(0x0F12, 0x012A); // #TVAR_ash_pGAS[570]																								   
    CamWriteCmosSensor(0x0F12, 0x0152); // #TVAR_ash_pGAS[571]																								   
    //  param_end TVAR_ash_pGAS																																					
    CamWriteCmosSensor(0x002A, 0x0D30);																																	
    CamWriteCmosSensor(0x0F12, 0x02A7); //#awbb_GLocusR																										   
    CamWriteCmosSensor(0x0F12, 0x0343); //#awbb_GLocusB																										   
    //  param_start TVAR_ash_AwbAshCord																																	  
    CamWriteCmosSensor(0x002A, 0x06B8);																																	
    CamWriteCmosSensor(0x0F12, 0x00E0); // #TVAR_ash_AwbAshCord_0_																							   
    CamWriteCmosSensor(0x0F12, 0x010A); //010A // #TVAR_ash_AwbAshCord_1_																					   
    CamWriteCmosSensor(0x0F12, 0x0120); //0120 // #TVAR_ash_AwbAshCord_2_																					   
    CamWriteCmosSensor(0x0F12, 0x0142); //0142 // #TVAR_ash_AwbAshCord_3_																					   
    CamWriteCmosSensor(0x0F12, 0x0160); // #TVAR_ash_AwbAshCord_4_																							   
    CamWriteCmosSensor(0x0F12, 0x018A); // #TVAR_ash_AwbAshCord_5_																							   
    CamWriteCmosSensor(0x0F12, 0x01A8); // #TVAR_ash_AwbAshCord_6_																							   
    																																																		
    //============================================================																									   
    //End GAS																																														
    																																																		
    																																																		
    																																																		
    //================================================================================================																   
    // SET CCM																																													
    //================================================================================================																   
    // CCM start address // 7000_33A4																																		
    																																																		
    CamWriteCmosSensor(0x002A, 0x0698);																																	
    CamWriteCmosSensor(0x0F12, 0x33A4);																																	
    CamWriteCmosSensor(0x0F12, 0x7000);																																	
    // Horizon																																													
    CamWriteCmosSensor(0x002A, 0x33A4);																																	
    CamWriteCmosSensor(0x0F12, 0x01C3); //01CB //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFF58); //FF8E //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFD2 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFF4E); //FF64 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x01A8); //01B2 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFF1E); //FF35 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFFCA); //FFDF //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFFD5); //FFE9 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x01E4); //01BD //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x010D); //011C //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x00DE); //011B //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFEB1); //FF43 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x019D); //019D //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //FF4C //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x01CC); //01CC //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0xFF90); //FF33 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x01DC); //0173 //#TVAR_wbt_pBaseCcms 																						   
    CamWriteCmosSensor(0x0F12, 0x0178); //#TVAR_wbt_pBaseCcms																								   
    // Inca																																															
    CamWriteCmosSensor(0x0F12, 0x01C3); //0206 //01C8 //#TVAR_wbt_pBaseCcms[18]																				   
    CamWriteCmosSensor(0x0F12, 0xFF58); //FF84 //FF7F //#TVAR_wbt_pBaseCcms[19]																				   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFC7 //FFE4 //#TVAR_wbt_pBaseCcms[20]																				   
    CamWriteCmosSensor(0x0F12, 0xFF4E); //FF42 //FF64 //#TVAR_wbt_pBaseCcms[21]																				   
    CamWriteCmosSensor(0x0F12, 0x01A8); //0319 //01B2 //#TVAR_wbt_pBaseCcms[22]																				   
    CamWriteCmosSensor(0x0F12, 0xFF1E); //FEEE //FF35 //#TVAR_wbt_pBaseCcms[23]																				   
    CamWriteCmosSensor(0x0F12, 0xFFCA); //001F //FFDF //#TVAR_wbt_pBaseCcms[24]																				   
    CamWriteCmosSensor(0x0F12, 0xFFD5); //001E //FFE9 //#TVAR_wbt_pBaseCcms[25]																				   
    CamWriteCmosSensor(0x0F12, 0x01E4); //0396 //01BD //#TVAR_wbt_pBaseCcms[26]																				   
    CamWriteCmosSensor(0x0F12, 0x010D); //0184 //011C //#TVAR_wbt_pBaseCcms[27]																				   
    CamWriteCmosSensor(0x0F12, 0x00DE); //018A //011B //#TVAR_wbt_pBaseCcms[28]																				   
    CamWriteCmosSensor(0x0F12, 0xFEB1); //FDBA //FF43 //#TVAR_wbt_pBaseCcms[29]																				   
    CamWriteCmosSensor(0x0F12, 0x019D); //0215 //019D //#TVAR_wbt_pBaseCcms[30]																				   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //FEC1 //FF4C //#TVAR_wbt_pBaseCcms[31]																				   
    CamWriteCmosSensor(0x0F12, 0x01CC); //0356 //01CC //#TVAR_wbt_pBaseCcms[32]																				   
    CamWriteCmosSensor(0x0F12, 0xFF90); //FF89 //FF33 //#TVAR_wbt_pBaseCcms[33]																				   
    CamWriteCmosSensor(0x0F12, 0x01DC); //021A //0173 //#TVAR_wbt_pBaseCcms[34]																				   
    CamWriteCmosSensor(0x0F12, 0x0178); //008E //012F //#TVAR_wbt_pBaseCcms[35]																				   
    // WW																																																
    CamWriteCmosSensor(0x0F12, 0x01C3); //01C8 //#TVAR_wbt_pBaseCcms[36] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF58); //FF7F //#TVAR_wbt_pBaseCcms[37] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFE4 //#TVAR_wbt_pBaseCcms[38] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF4E); //FF64 //#TVAR_wbt_pBaseCcms[39] 																					   
    CamWriteCmosSensor(0x0F12, 0x01A8); //01B2 //#TVAR_wbt_pBaseCcms[40] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF1E); //FF35 //#TVAR_wbt_pBaseCcms[41] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFB8); //FFDF //#TVAR_wbt_pBaseCcms[42] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFE9 //#TVAR_wbt_pBaseCcms[43] 																					   
    CamWriteCmosSensor(0x0F12, 0x01D2); //01BD //#TVAR_wbt_pBaseCcms[44] 																					   
    CamWriteCmosSensor(0x0F12, 0x0110); //011C //#TVAR_wbt_pBaseCcms[45] 																					   
    CamWriteCmosSensor(0x0F12, 0x010F); //011B //#TVAR_wbt_pBaseCcms[46] 																					   
    CamWriteCmosSensor(0x0F12, 0xFECD); //FF43 //#TVAR_wbt_pBaseCcms[47] 																					   
    CamWriteCmosSensor(0x0F12, 0x019D); //019D //#TVAR_wbt_pBaseCcms[48] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //FF4C //#TVAR_wbt_pBaseCcms[49] 																					   
    CamWriteCmosSensor(0x0F12, 0x01CC); //01CC //#TVAR_wbt_pBaseCcms[50] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF90); //FF33 //#TVAR_wbt_pBaseCcms[51] 																					   
    CamWriteCmosSensor(0x0F12, 0x01DC); //0173 //#TVAR_wbt_pBaseCcms[52] 																					   
    CamWriteCmosSensor(0x0F12, 0x0178); //012F //#TVAR_wbt_pBaseCcms[53] 																					   
    // CWF																																															
    CamWriteCmosSensor(0x0F12, 0x01C3); //01C8 //#TVAR_wbt_pBaseCcms[54] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF58); //FF7F //#TVAR_wbt_pBaseCcms[55] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFE4 //#TVAR_wbt_pBaseCcms[56] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF4E); //FF64 //#TVAR_wbt_pBaseCcms[57] 																					   
    CamWriteCmosSensor(0x0F12, 0x01A8); //01B2 //#TVAR_wbt_pBaseCcms[58] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF1E); //FF35 //#TVAR_wbt_pBaseCcms[59] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFB8); //FFDF //#TVAR_wbt_pBaseCcms[60] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFC3); //FFE9 //#TVAR_wbt_pBaseCcms[61] 																					   
    CamWriteCmosSensor(0x0F12, 0x01D2); //01BD //#TVAR_wbt_pBaseCcms[62] 																					   
    CamWriteCmosSensor(0x0F12, 0x0110); //011C //#TVAR_wbt_pBaseCcms[63] 																					   
    CamWriteCmosSensor(0x0F12, 0x010F); //011B //#TVAR_wbt_pBaseCcms[64] 																					   
    CamWriteCmosSensor(0x0F12, 0xFECD); //FF43 //#TVAR_wbt_pBaseCcms[65] 																					   
    CamWriteCmosSensor(0x0F12, 0x019D); //019D //#TVAR_wbt_pBaseCcms[66] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //FF4C //#TVAR_wbt_pBaseCcms[67] 																					   
    CamWriteCmosSensor(0x0F12, 0x01CC); //01CC //#TVAR_wbt_pBaseCcms[68] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF90); //FF33 //#TVAR_wbt_pBaseCcms[69] 																					   
    CamWriteCmosSensor(0x0F12, 0x01DC); //0173 //#TVAR_wbt_pBaseCcms[70] 																					   
    CamWriteCmosSensor(0x0F12, 0x0178); //012F //#TVAR_wbt_pBaseCcms[71] 																					   
    // D50																																															
    CamWriteCmosSensor(0x0F12, 0x01C8); //#TVAR_wbt_pBaseCcms[72]																							   
    CamWriteCmosSensor(0x0F12, 0xFF7F); //#TVAR_wbt_pBaseCcms[73]																							   
    CamWriteCmosSensor(0x0F12, 0xFFE4); //#TVAR_wbt_pBaseCcms[74]																							   
    CamWriteCmosSensor(0x0F12, 0xFEFE); //#TVAR_wbt_pBaseCcms[75]																							   
    CamWriteCmosSensor(0x0F12, 0x0248); //#TVAR_wbt_pBaseCcms[76]																							   
    CamWriteCmosSensor(0x0F12, 0xFEBA); //#TVAR_wbt_pBaseCcms[77]																							   
    CamWriteCmosSensor(0x0F12, 0xFFC0); //#TVAR_wbt_pBaseCcms[78]																							   
    CamWriteCmosSensor(0x0F12, 0xFFCC); //#TVAR_wbt_pBaseCcms[79]																							   
    CamWriteCmosSensor(0x0F12, 0x01F9); //#TVAR_wbt_pBaseCcms[80]																							   
    CamWriteCmosSensor(0x0F12, 0x0085);	///01B4//011C //#TVAR_wbt_pBaseCcms[81] 																			   
    CamWriteCmosSensor(0x0F12, 0x00E9);	///0182//011B //#TVAR_wbt_pBaseCcms[82] 																			   
    CamWriteCmosSensor(0x0F12, 0xFE9D);	///FF37//FF43 //#TVAR_wbt_pBaseCcms[83] 																			   
    CamWriteCmosSensor(0x0F12, 0x019D); //#TVAR_wbt_pBaseCcms[84]																							   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //#TVAR_wbt_pBaseCcms[85]																							   
    CamWriteCmosSensor(0x0F12, 0x01CC); //#TVAR_wbt_pBaseCcms[86]																							   
    CamWriteCmosSensor(0x0F12, 0xFF33); //#TVAR_wbt_pBaseCcms[87]																							   
    CamWriteCmosSensor(0x0F12, 0x0173); //#TVAR_wbt_pBaseCcms[88]																							   
    CamWriteCmosSensor(0x0F12, 0x012F); //#TVAR_wbt_pBaseCcms[89]																							   
    // D65																																															
    CamWriteCmosSensor(0x0F12, 0x01C8); //01C8 //#TVAR_wbt_pBaseCcms[90] 																					   
    CamWriteCmosSensor(0x0F12, 0xFF7F); //FF7F //#TVAR_wbt_pBaseCcms[91] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFE4); //FFE4 //#TVAR_wbt_pBaseCcms[92] 																					   
    CamWriteCmosSensor(0x0F12, 0xFEFE); //FF64 //#TVAR_wbt_pBaseCcms[93] 																					   
    CamWriteCmosSensor(0x0F12, 0x0248); //01B2 //#TVAR_wbt_pBaseCcms[94] 																					   
    CamWriteCmosSensor(0x0F12, 0xFEBA); //FF35 //#TVAR_wbt_pBaseCcms[95] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFC0); //FFDF //#TVAR_wbt_pBaseCcms[96] 																					   
    CamWriteCmosSensor(0x0F12, 0xFFCC); //FFE9 //#TVAR_wbt_pBaseCcms[97] 																					   
    CamWriteCmosSensor(0x0F12, 0x01F9); //01BD //#TVAR_wbt_pBaseCcms[98] 																					   
    CamWriteCmosSensor(0x0F12, 0x0085);	///01B4//011C //#TVAR_wbt_pBaseCcms[99] 																			   
    CamWriteCmosSensor(0x0F12, 0x00E9);	///0182//011B //#TVAR_wbt_pBaseCcms[100]																			   
    CamWriteCmosSensor(0x0F12, 0xFE9D);	///FF37//FF43 //#TVAR_wbt_pBaseCcms[101]																			   
    CamWriteCmosSensor(0x0F12, 0x019D); //019D //#TVAR_wbt_pBaseCcms[102]																					   
    CamWriteCmosSensor(0x0F12, 0xFF4C); //FF4C //#TVAR_wbt_pBaseCcms[103]																					   
    CamWriteCmosSensor(0x0F12, 0x01CC); //01CC //#TVAR_wbt_pBaseCcms[104]																					   
    CamWriteCmosSensor(0x0F12, 0xFF33); //FF33 //#TVAR_wbt_pBaseCcms[105]																					   
    CamWriteCmosSensor(0x0F12, 0x0173); //0173 //#TVAR_wbt_pBaseCcms[106]																					   
    CamWriteCmosSensor(0x0F12, 0x012F); //012F //#TVAR_wbt_pBaseCcms[107]																					   
    // Outdoor CCM address // 7000_3380																																	  
    CamWriteCmosSensor(0x002A, 0x06A0);																																	
    CamWriteCmosSensor(0x0F12, 0x3380);																																	
    CamWriteCmosSensor(0x0F12, 0x7000);																																	
    // Outdoor CCM																																											
    CamWriteCmosSensor(0x002A, 0x3380);	//																															
    CamWriteCmosSensor(0x0F12, 0x01E0);	///01DA//01EF//01EB//01DF//01D6//01E0 //#TVAR_wbt_pOutdoorCcm[0]	
    CamWriteCmosSensor(0x0F12, 0xFF80);	///FF95//FF84//FF68//FF70//FF6D//FF80 //#TVAR_wbt_pOutdoorCcm[1]	
    CamWriteCmosSensor(0x0F12, 0xFFD0);	///FFBA//FFB7//FFD7//FFDC//FF9D//FFD0 //#TVAR_wbt_pOutdoorCcm[2]	
    CamWriteCmosSensor(0x0F12, 0xFF61);	///FEA1//FEDE//FEA2//FEFE//FF4C//FF61 //#TVAR_wbt_pOutdoorCcm[3]	
    CamWriteCmosSensor(0x0F12, 0x01BD);	///02BE//0291//0319//0248//01A8//01BD //#TVAR_wbt_pOutdoorCcm[4]	
    CamWriteCmosSensor(0x0F12, 0xFF34);	///FE4C//FE91//FE45//FEBA//FF1F//FF34 //#TVAR_wbt_pOutdoorCcm[5]	
    CamWriteCmosSensor(0x0F12, 0xFFFE);	///FF7A//FF7A//FF7A//FF87//FF77//FFFE //#TVAR_wbt_pOutdoorCcm[6]	
    CamWriteCmosSensor(0x0F12, 0xFFF6);	///FF9F//FF9F//FF9F//FFB7//FFA6//FFF6 //#TVAR_wbt_pOutdoorCcm[7]	
    CamWriteCmosSensor(0x0F12, 0x019D);	///01DE//01DE//01DE//01E1//01C6//019D //#TVAR_wbt_pOutdoorCcm[8]	
    CamWriteCmosSensor(0x0F12, 0x0107);	///00BE//0087//FFE2//01B4//013D//0107 //#TVAR_wbt_pOutdoorCcm[9]	
    CamWriteCmosSensor(0x0F12, 0x010F);	///0122//00B5//00B1//0182//010E//010F //#TVAR_wbt_pOutdoorCcm[10]	
    CamWriteCmosSensor(0x0F12, 0xFF67);	///FED2//FE6B//FDB1//FF37//FEE3//FF67 //#TVAR_wbt_pOutdoorCcm[11]	
    CamWriteCmosSensor(0x0F12, 0x016C);	///019D//019D//019D//019D//0112//016C //#TVAR_wbt_pOutdoorCcm[12]	
    CamWriteCmosSensor(0x0F12, 0xFF54);	///FF4C//FF4C//FF4C//FF4C//FEE8//FF54 //#TVAR_wbt_pOutdoorCcm[13]	
    CamWriteCmosSensor(0x0F12, 0x01FC);	///01CC//01CC//01CC//01CC//013C//01FC //#TVAR_wbt_pOutdoorCcm[14]	
    CamWriteCmosSensor(0x0F12, 0xFF82);	///FF18//FF32//FF33//FF0E//FEE2//FF82 //#TVAR_wbt_pOutdoorCcm[15]	
    CamWriteCmosSensor(0x0F12, 0x015D);	///0178//0169//0173//017D//013E//015D //#TVAR_wbt_pOutdoorCcm[16]	
    CamWriteCmosSensor(0x0F12, 0x00FD);	///0146//013B//012F//014A//010F//00FD //#TVAR_wbt_pOutdoorCcm[17]	
    CamWriteCmosSensor(0x002A, 0x06A6);																			
    CamWriteCmosSensor(0x0F12, 0x00D8); // #SARR_AwbCcmCord_0_											  
    CamWriteCmosSensor(0x0F12, 0x00FC); // #SARR_AwbCcmCord_1_											  
    CamWriteCmosSensor(0x0F12, 0x0120); // #SARR_AwbCcmCord_2_											  
    CamWriteCmosSensor(0x0F12, 0x014C); // #SARR_AwbCcmCord_3_											  
    CamWriteCmosSensor(0x0F12, 0x0164); // #SARR_AwbCcmCord_4_											  
    CamWriteCmosSensor(0x0F12, 0x018A); // #SARR_AwbCcmCord_5_											  
    //EDISONCUT START																												
    //#Indoor boundary																											
    CamWriteCmosSensor(0x002A, 0x0C48);																			
    CamWriteCmosSensor(0x0F12, 0x0384); //awbb_IndoorGrZones_m_BGrid[0]									   
    CamWriteCmosSensor(0x0F12, 0x03A4); //awbb_IndoorGrZones_m_BGrid[1]									   
    CamWriteCmosSensor(0x0F12, 0x034C); //awbb_IndoorGrZones_m_BGrid[2]									   
    CamWriteCmosSensor(0x0F12, 0x0388); //awbb_IndoorGrZones_m_BGrid[3]									   
    CamWriteCmosSensor(0x0F12, 0x0314); //awbb_IndoorGrZones_m_BGrid[4]									   
    CamWriteCmosSensor(0x0F12, 0x035E); //awbb_IndoorGrZones_m_BGrid[5]									   
    CamWriteCmosSensor(0x0F12, 0x02DA); //awbb_IndoorGrZones_m_BGrid[6]									   
    CamWriteCmosSensor(0x0F12, 0x0338); //awbb_IndoorGrZones_m_BGrid[7]									   
    CamWriteCmosSensor(0x0F12, 0x029C); //awbb_IndoorGrZones_m_BGrid[8]									   
    CamWriteCmosSensor(0x0F12, 0x0318); //awbb_IndoorGrZones_m_BGrid[9]									   
    CamWriteCmosSensor(0x0F12, 0x027A); //awbb_IndoorGrZones_m_BGrid[10] 								   
    CamWriteCmosSensor(0x0F12, 0x02F6); //awbb_IndoorGrZones_m_BGrid[11] 								   
    CamWriteCmosSensor(0x0F12, 0x0260); //awbb_IndoorGrZones_m_BGrid[12] 								   
    CamWriteCmosSensor(0x0F12, 0x02C8); //awbb_IndoorGrZones_m_BGrid[13] 								   
    CamWriteCmosSensor(0x0F12, 0x0246); //awbb_IndoorGrZones_m_BGrid[14] 								   
    CamWriteCmosSensor(0x0F12, 0x02AC); //awbb_IndoorGrZones_m_BGrid[15] 								   
    CamWriteCmosSensor(0x0F12, 0x022E); //awbb_IndoorGrZones_m_BGrid[16] 								   
    CamWriteCmosSensor(0x0F12, 0x029C); //awbb_IndoorGrZones_m_BGrid[17] 								   
    CamWriteCmosSensor(0x0F12, 0x0216); //awbb_IndoorGrZones_m_BGrid[18] 								   
    CamWriteCmosSensor(0x0F12, 0x0290); //awbb_IndoorGrZones_m_BGrid[19] 								   
    CamWriteCmosSensor(0x0F12, 0x0200); //awbb_IndoorGrZones_m_BGrid[20] 								   
    CamWriteCmosSensor(0x0F12, 0x0286); //awbb_IndoorGrZones_m_BGrid[21] 								   
    CamWriteCmosSensor(0x0F12, 0x01E2); //awbb_IndoorGrZones_m_BGrid[22] 								   
    CamWriteCmosSensor(0x0F12, 0x0272); //awbb_IndoorGrZones_m_BGrid[23] 								   
    CamWriteCmosSensor(0x0F12, 0x01D8); //awbb_IndoorGrZones_m_BGrid[24] 								   
    CamWriteCmosSensor(0x0F12, 0x025C); //awbb_IndoorGrZones_m_BGrid[25] 								   
    CamWriteCmosSensor(0x0F12, 0x01D8); //awbb_IndoorGrZones_m_BGrid[26] 								   
    CamWriteCmosSensor(0x0F12, 0x0248); //awbb_IndoorGrZones_m_BGrid[27] 								   
    CamWriteCmosSensor(0x0F12, 0x01F2); //awbb_IndoorGrZones_m_BGrid[28] 								   
    CamWriteCmosSensor(0x0F12, 0x0230); //awbb_IndoorGrZones_m_BGrid[29] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[30] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[31] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[32] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[33] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[34] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[35] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[36] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[37] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[38] 								   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_IndoorGrZones_m_BGrid[39] 								   
    //param_end awbb_IndoorGrZones_m_BGrid																		   
    CamWriteCmosSensor(0x0F12, 0x0005); //awbb_IndoorGrZones_m_GridStep									   
    //CamWriteCmosSensor(0x0F12, 0x0000);																		
    CamWriteCmosSensor(0x002A, 0x0CA0);																			
    CamWriteCmosSensor(0x0F12, 0x0126); //awbb_IndoorGrZones_m_Boffs 									   
    //CamWriteCmosSensor(0x0F12, 0x0000);																		
    //  param_start awbb_OutdoorGrZones_m_BGrid																	   
    CamWriteCmosSensor(0x002A, 0x0CA4);																			
    CamWriteCmosSensor(0x0F12, 0x0272); //025C//025C//0272//0272//0294 //#awbb_OutdoorGrZones_m_BGrid[0] 							
    CamWriteCmosSensor(0x0F12, 0x028A); //0292//0292//028A//028A//02AB //#awbb_OutdoorGrZones_m_BGrid[1] 							
    CamWriteCmosSensor(0x0F12, 0x0246); //023E//023E//0246//0246//0269 //#awbb_OutdoorGrZones_m_BGrid[2] 							
    CamWriteCmosSensor(0x0F12, 0x0282); //029C//029C//0293//0282//02A2 //#awbb_OutdoorGrZones_m_BGrid[3] 							
    CamWriteCmosSensor(0x0F12, 0x0230); //0226//0226//021D//0230//0251 //#awbb_OutdoorGrZones_m_BGrid[4] 							
    CamWriteCmosSensor(0x0F12, 0x0278); //028E//028E//0286//0278//0299 //#awbb_OutdoorGrZones_m_BGrid[5] 							
    CamWriteCmosSensor(0x0F12, 0x0214); //0210//0210//0208//0214//0237 //#awbb_OutdoorGrZones_m_BGrid[6] 							
    CamWriteCmosSensor(0x0F12, 0x0268); //0282//0282//0279//0268//028B //#awbb_OutdoorGrZones_m_BGrid[7] 							
    CamWriteCmosSensor(0x0F12, 0x01F8); //01F2//01F2//01E9//01F8//0219 //#awbb_OutdoorGrZones_m_BGrid[8] 							
    CamWriteCmosSensor(0x0F12, 0x025C); //0274//0274//026C//025C//027C //#awbb_OutdoorGrZones_m_BGrid[9] 							
    CamWriteCmosSensor(0x0F12, 0x01EC); //01E2//01EA//01E1//01EC//020F //#awbb_OutdoorGrZones_m_BGrid[10]							
    CamWriteCmosSensor(0x0F12, 0x0246); //025E//025E//0256//0246//0269 //#awbb_OutdoorGrZones_m_BGrid[11]							
    CamWriteCmosSensor(0x0F12, 0x0206); //01D2//01E6//01DD//0206//0228 //#awbb_OutdoorGrZones_m_BGrid[12]							
    CamWriteCmosSensor(0x0F12, 0x0228); //024A//024A//0241//0228//0248 //#awbb_OutdoorGrZones_m_BGrid[13]							
    CamWriteCmosSensor(0x0F12, 0x0000); //01D6//01FE//01F5//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[14]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0238//0230//0228//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[15]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[16]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[17]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[18]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[19]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[20]							
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[21]							
    //  param_end 00000000awbb_OutdoorGrZones_m_BGrid																																	
    //CamWriteCmosSensor(0x0F12, 00000x00000000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[22]			   
    //CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000//0000//0000//0000 //#awbb_OutdoorGrZones_m_BGrid[23]						  
    CamWriteCmosSensor(0x0F12, 0x0005); //#awbb_OutdoorGrZones_m_GridStep											
    CamWriteCmosSensor(0x002A, 0x0CDC);																												
    CamWriteCmosSensor(0x0F12, 0x0206); //01F8 //0206 //0220 //#awbb_OutdoorGrZones_m_Boffs									   
    //#Outdoor detection zone																																	
    CamWriteCmosSensor(0x002A, 0x0D88);																												
    CamWriteCmosSensor(0x0F12, 0xFFB6); //#awbb_OutdoorDetectionZone_m_BGrid[0]_m_left										   
    CamWriteCmosSensor(0x0F12, 0x00B6); //#awbb_OutdoorDetectionZone_m_BGrid[0]_m_right										   
    CamWriteCmosSensor(0x0F12, 0xFF38); //#awbb_OutdoorDetectionZone_m_BGrid[1]_m_left										   
    CamWriteCmosSensor(0x0F12, 0x0118); //#awbb_OutdoorDetectionZone_m_BGrid[1]_m_right										   
    CamWriteCmosSensor(0x0F12, 0xFEF1); //#awbb_OutdoorDetectionZone_m_BGrid[2]_m_left										   
    CamWriteCmosSensor(0x0F12, 0x015F); //#awbb_OutdoorDetectionZone_m_BGrid[2]_m_right										   
    CamWriteCmosSensor(0x0F12, 0xFEC0); //#awbb_OutdoorDetectionZone_m_BGrid[3]_m_left										   
    CamWriteCmosSensor(0x0F12, 0x0199); //#awbb_OutdoorDetectionZone_m_BGrid[3]_m_right										   
    CamWriteCmosSensor(0x0F12, 0xFE91); //#awbb_OutdoorDetectionZone_m_BGrid[4]_m_left										   
    CamWriteCmosSensor(0x0F12, 0x01CF); //#awbb_OutdoorDetectionZone_m_BGrid[4]_m_right										   
    CamWriteCmosSensor(0x0F12, 0x1388); //#awbb_OutdoorDetectionZone_ZInfo_m_AbsGridStep 									   
    CamWriteCmosSensor(0x0F12, 0x0000);																												
    CamWriteCmosSensor(0x0F12, 0x0005); //#awbb_OutdoorDetectionZone_ZInfo_m_GridSz											   
    CamWriteCmosSensor(0x0F12, 0x0000);																												
    CamWriteCmosSensor(0x0F12, 0x1630); //1387 //#awbb_OutdoorDetectionZone_ZInfo_m_NBoffs									   
    CamWriteCmosSensor(0x0F12, 0x0000);																												
    CamWriteCmosSensor(0x0F12, 0x1631); //1388 //#awbb_OutdoorDetectionZone_ZInfo_m_MaxNB									   
    CamWriteCmosSensor(0x0F12, 0x0000);																												
    //  param_start awbb_LowBrGrZones_m_BGrid																									
    CamWriteCmosSensor(0x002A, 0x0CE0);																												
    CamWriteCmosSensor(0x0F12, 0x036E); //awbb_LowBrGrZones_m_BGrid[0]														   
    CamWriteCmosSensor(0x0F12, 0x03D0); //awbb_LowBrGrZones_m_BGrid[1]														   
    CamWriteCmosSensor(0x0F12, 0x02E6); //awbb_LowBrGrZones_m_BGrid[2]														   
    CamWriteCmosSensor(0x0F12, 0x03A8); //awbb_LowBrGrZones_m_BGrid[3]														   
    CamWriteCmosSensor(0x0F12, 0x0274); //awbb_LowBrGrZones_m_BGrid[4]														   
    CamWriteCmosSensor(0x0F12, 0x035A); //awbb_LowBrGrZones_m_BGrid[5]														   
    CamWriteCmosSensor(0x0F12, 0x022E); //awbb_LowBrGrZones_m_BGrid[6]														   
    CamWriteCmosSensor(0x0F12, 0x0316); //awbb_LowBrGrZones_m_BGrid[7]														   
    CamWriteCmosSensor(0x0F12, 0x01FE); //awbb_LowBrGrZones_m_BGrid[8]														   
    CamWriteCmosSensor(0x0F12, 0x02D4); //awbb_LowBrGrZones_m_BGrid[9]														   
    CamWriteCmosSensor(0x0F12, 0x01D6); //awbb_LowBrGrZones_m_BGrid[10]														   
    CamWriteCmosSensor(0x0F12, 0x02B0); //awbb_LowBrGrZones_m_BGrid[11]														   
    CamWriteCmosSensor(0x0F12, 0x01BA); //awbb_LowBrGrZones_m_BGrid[12]														   
    CamWriteCmosSensor(0x0F12, 0x0292); //awbb_LowBrGrZones_m_BGrid[13]														   
    CamWriteCmosSensor(0x0F12, 0x01B4); //awbb_LowBrGrZones_m_BGrid[14]														   
    CamWriteCmosSensor(0x0F12, 0x0268); //awbb_LowBrGrZones_m_BGrid[15]														   
    CamWriteCmosSensor(0x0F12, 0x01D8); //awbb_LowBrGrZones_m_BGrid[16]														   
    CamWriteCmosSensor(0x0F12, 0x0204); //awbb_LowBrGrZones_m_BGrid[17]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[18]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[19]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[20]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[21]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[22]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_LowBrGrZones_m_BGrid[23]														   
    //  param_end awbb_LowBrGrZones_m_BGrid																										
    CamWriteCmosSensor(0x0F12, 0x0006); //awbb_LowBrGrZones_m_GridStep														   
    //CamWriteCmosSensor(0x0F12, 0x0000);																											
    CamWriteCmosSensor(0x002A, 0x0D18);																												
    CamWriteCmosSensor(0x0F12, 0x0114); //awbb_LowBrGrZones_m_Boffs															   
    //CamWriteCmosSensor(0x0F12, 0x0000);																											
    //AWB ETC																																									
    CamWriteCmosSensor(0x002A, 0x0D1C);																												
    CamWriteCmosSensor(0x0F12, 0x0342); //awbb_CrclLowT_R_c																		  
    //CamWriteCmosSensor(0x0F12, 0x0000);																											
    CamWriteCmosSensor(0x002A, 0x0D20);																												
    CamWriteCmosSensor(0x0F12, 0x0162); //awbb_CrclLowT_B_c																		  
    //CamWriteCmosSensor(0x0F12, 0x0000);																											
    CamWriteCmosSensor(0x002A, 0x0D24);																												
    CamWriteCmosSensor(0x0F12, 0x6184); //awbb_CrclLowT_Rad_c																	  
    //CamWriteCmosSensor(0x0F12, 0x0000);																											
    CamWriteCmosSensor(0x002A, 0x0D2C);																												
    CamWriteCmosSensor(0x0F12, 0x0133); //awbb_IntcR 																					
    CamWriteCmosSensor(0x0F12, 0x0117); //awbb_IntcB 																					
    CamWriteCmosSensor(0x002A, 0x0D28);																												
    CamWriteCmosSensor(0x0F12, 0x0269); //#awbb_OutdoorWP_r																		  
    CamWriteCmosSensor(0x0F12, 0x0240); //#awbb_OutdoorWP_b																		  
    CamWriteCmosSensor(0x002A, 0x0E4C);																												
    CamWriteCmosSensor(0x0F12, 0x0000); //#awbboost_useBoosting4Outdoor														   
    CamWriteCmosSensor(0x002A, 0x0D4C);																												
    CamWriteCmosSensor(0x0F12, 0x0187); //#awbb_GamutWidthThr1																   
    CamWriteCmosSensor(0x0F12, 0x00CF); //#awbb_GamutHeightThr1																   
    CamWriteCmosSensor(0x0F12, 0x000D); //#awbb_GamutWidthThr2																   
    CamWriteCmosSensor(0x0F12, 0x000A); //#awbb_GamutHeightThr2																   
    CamWriteCmosSensor(0x002A, 0x0D5C);																												
    CamWriteCmosSensor(0x0F12, 0x7FFF); //#awbb_LowTempRB																			
    CamWriteCmosSensor(0x0F12, 0x0050); //#awbb_LowTemp_RBzone																   
    CamWriteCmosSensor(0x002A, 0x0D46);																												
    CamWriteCmosSensor(0x0F12, 0x0520); //#awbb_MvEq_RBthresh																	  
    CamWriteCmosSensor(0x002A, 0x0D4A);																												
    CamWriteCmosSensor(0x0F12, 0x000A); //#awbb_MovingScale10																	  
    CamWriteCmosSensor(0x002A, 0x0E3E);																												
    CamWriteCmosSensor(0x0F12, 0x0000); //#awbb_rpl_InvalidOutdoor off														   
    //Adding for improving the AWB blinking. 																									
    //#AWB initial point 																																			
    CamWriteCmosSensor(0x002A, 0x0E44);																												
    CamWriteCmosSensor(0x0F12, 0x05CC); //#define awbb_GainsInit_0_															   
    CamWriteCmosSensor(0x0F12, 0x0400); //#define awbb_GainsInit_1_															   
    CamWriteCmosSensor(0x0F12, 0x0655); //#define awbb_GainsInit_2_															   
    //#Set AWB global offset 																																	
    CamWriteCmosSensor(0x002A, 0x0E36);																												
    CamWriteCmosSensor(0x0F12, 0x0000); //#awbb_RGainOff 																			
    CamWriteCmosSensor(0x0F12, 0x0000); //#awbb_BGainOff 																			
    CamWriteCmosSensor(0x0F12, 0x0000); //#awbb_GGainOff 										//Grid Correction Settings - new
    //================================================================================================			
    //#SET GRID OFFSET																																											
    //================================================================================================			
    //Grid Correction																										   
    //  param_start awbb_GridCorr_R																							   
    CamWriteCmosSensor(0x002A, 0x0DD4);																				   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[0] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[1] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[2] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[3] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[4] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[5] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[6] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[7] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[8] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[9] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[10]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[11]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[12]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[13]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[14]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[15]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[16]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_R[17]														   
    //  param_end awbb_GridCorr_R																							   
    //  param_start awbb_GridCorr_B																							   
    CamWriteCmosSensor(0x002A, 0x0DF8);																				   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[0] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[1] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[2] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[3] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[4] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[5] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[6] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[7] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[8] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[9] 														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[10]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[11]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[12]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[13]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[14]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[15]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[16]														   
    CamWriteCmosSensor(0x0F12, 0x0000); //awbb_GridCorr_B[17]														   
    //  param_end awbb_GridCorr_B																							   
    //  param_start awbb_GridConst_1 																						   
    CamWriteCmosSensor(0x002A, 0x0E1C);																				   
    CamWriteCmosSensor(0x0F12, 0x030A); //awbb_GridConst_1[0]														   
    CamWriteCmosSensor(0x0F12, 0x0340); //awbb_GridConst_1[1]														   
    CamWriteCmosSensor(0x0F12, 0x0374); //awbb_GridConst_1[2]														   
    //  param_end awbb_GridConst_1																							   
    //  param_start awbb_GridConst_2 																						   
    CamWriteCmosSensor(0x002A, 0x0E22);																				   
    CamWriteCmosSensor(0x0F12, 0x0DE7);	//awbb_GridConst_2[0]														   
    CamWriteCmosSensor(0x0F12, 0x0E46);	//awbb_GridConst_2[1]														   
    CamWriteCmosSensor(0x0F12, 0x0EA6);	//awbb_GridConst_2[2]														   
    CamWriteCmosSensor(0x0F12, 0x0F0E);	//awbb_GridConst_2[3]														   
    CamWriteCmosSensor(0x0F12, 0x0F6C);	//awbb_GridConst_2[4]														   
    CamWriteCmosSensor(0x0F12, 0x0FD9);	//awbb_GridConst_2[5]														   
    //  param_end awbb_GridConst_2																							   
    CamWriteCmosSensor(0x002A, 0x0E2E);																				   
    CamWriteCmosSensor(0x0F12, 0x00B4);	//awbb_GridCoeff_R_1														   
    CamWriteCmosSensor(0x0F12, 0x00B6);	//awbb_GridCoeff_B_1														   
    CamWriteCmosSensor(0x0F12, 0x0049);	//awbb_GridCoeff_R_2														   
    CamWriteCmosSensor(0x0F12, 0x00F5);	//awbb_GridCoeff_B_2														   
    CamWriteCmosSensor(0x002A, 0x0E4A);																				   
    CamWriteCmosSensor(0x0F12, 0x0002);																				   
    																															
    //================================ ================================================================											   
    // SET GAMMA 																																												
    //================================ ================================================================											   
    //Our //old //STW																																										
    //===============================================================================================											   
    																																																		
    CamWriteCmosSensor(0x002A, 0x3288);																																	
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000 //#SARR_usDualGammaLutRGBIndoor_0__0_ 0x70003288									   
    CamWriteCmosSensor(0x0F12, 0x0004); //0008//0004 //#SARR_usDualGammaLutRGBIndoor_0__1_ 0x7000328A									   
    CamWriteCmosSensor(0x0F12, 0x000C); //0013//0010 //#SARR_usDualGammaLutRGBIndoor_0__2_ 0x7000328C									   
    CamWriteCmosSensor(0x0F12, 0x0024); //002C//002A //#SARR_usDualGammaLutRGBIndoor_0__3_ 0x7000328E									   
    CamWriteCmosSensor(0x0F12, 0x006E); ///0062//0062 //#SARR_usDualGammaLutRGBIndoor_0__4_ 0x70003290									   
    CamWriteCmosSensor(0x0F12, 0x00D1); ///00CD//00D5 //#SARR_usDualGammaLutRGBIndoor_0__5_ 0x70003292									   
    CamWriteCmosSensor(0x0F12, 0x0119); ///0129//0138 //#SARR_usDualGammaLutRGBIndoor_0__6_ 0x70003294									   
    CamWriteCmosSensor(0x0F12, 0x0139); ///0151//0161 //#SARR_usDualGammaLutRGBIndoor_0__7_ 0x70003296									   
    CamWriteCmosSensor(0x0F12, 0x0157); ///0174//0186 //#SARR_usDualGammaLutRGBIndoor_0__8_ 0x70003298									   
    CamWriteCmosSensor(0x0F12, 0x018E); ///01AA//01BC //#SARR_usDualGammaLutRGBIndoor_0__9_ 0x7000329A									   
    CamWriteCmosSensor(0x0F12, 0x01C3); ///01D7//01E8 //#SARR_usDualGammaLutRGBIndoor_0__10_ 0x7000329C									   
    CamWriteCmosSensor(0x0F12, 0x01F3); ///01FE//020F //#SARR_usDualGammaLutRGBIndoor_0__11_ 0x7000329E									   
    CamWriteCmosSensor(0x0F12, 0x021F); //0221//0232 //#SARR_usDualGammaLutRGBIndoor_0__12_ 0x700032A0									   
    CamWriteCmosSensor(0x0F12, 0x0269); //025D//0273 //#SARR_usDualGammaLutRGBIndoor_0__13_ 0x700032A2									   
    CamWriteCmosSensor(0x0F12, 0x02A6); //0291//02AF //#SARR_usDualGammaLutRGBIndoor_0__14_ 0x700032A4									   
    CamWriteCmosSensor(0x0F12, 0x02FF); //02EB//0309 //#SARR_usDualGammaLutRGBIndoor_0__15_ 0x700032A6									   
    CamWriteCmosSensor(0x0F12, 0x0351); //033A//0355 //#SARR_usDualGammaLutRGBIndoor_0__16_ 0x700032A8									   
    CamWriteCmosSensor(0x0F12, 0x0395); //0380//0394 //#SARR_usDualGammaLutRGBIndoor_0__17_ 0x700032AA									   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03C2//03CE //#SARR_usDualGammaLutRGBIndoor_0__18_ 0x700032AC									   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF//03FF //#SARR_usDualGammaLutRGBIndoor_0__19_ 0x700032AE									   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000 //#SARR_usDualGammaLutRGBIndoor_1__0_ 0x700032B0									   
    CamWriteCmosSensor(0x0F12, 0x0004); //0008//0004 //#SARR_usDualGammaLutRGBIndoor_1__1_ 0x700032B2									   
    CamWriteCmosSensor(0x0F12, 0x000C); //0013//0010 //#SARR_usDualGammaLutRGBIndoor_1__2_ 0x700032B4									   
    CamWriteCmosSensor(0x0F12, 0x0024); //002C//002A //#SARR_usDualGammaLutRGBIndoor_1__3_ 0x700032B6									   
    CamWriteCmosSensor(0x0F12, 0x006E); //#SARR_usDualGammaLutRGBOutdoor_0__4_ 0x70003308												   
    CamWriteCmosSensor(0x0F12, 0x00D1); //#SARR_usDualGammaLutRGBOutdoor_0__5_ 0x7000330A												   
    CamWriteCmosSensor(0x0F12, 0x0119); //#SARR_usDualGammaLutRGBOutdoor_0__6_ 0x7000330C												   
    CamWriteCmosSensor(0x0F12, 0x0139); //#SARR_usDualGammaLutRGBOutdoor_0__7_ 0x7000330E												   
    CamWriteCmosSensor(0x0F12, 0x0157); //#SARR_usDualGammaLutRGBOutdoor_0__8_ 0x70003310												   
    CamWriteCmosSensor(0x0F12, 0x018E); //#SARR_usDualGammaLutRGBOutdoor_0__9_ 0x70003312												   
    CamWriteCmosSensor(0x0F12, 0x01C3); //#SARR_usDualGammaLutRGBOutdoor_0__10_0x70003314												   
    CamWriteCmosSensor(0x0F12, 0x01F3); //#SARR_usDualGammaLutRGBOutdoor_0__11_0x70003316												   
    CamWriteCmosSensor(0x0F12, 0x021F); //0221//0232 //#SARR_usDualGammaLutRGBIndoor_1__12_ 0x700032C8									   
    CamWriteCmosSensor(0x0F12, 0x0269); //025D//0273 //#SARR_usDualGammaLutRGBIndoor_1__13_ 0x700032CA									   
    CamWriteCmosSensor(0x0F12, 0x02A6); //0291//02AF //#SARR_usDualGammaLutRGBIndoor_1__14_ 0x700032CC									   
    CamWriteCmosSensor(0x0F12, 0x02FF); //02EB//0309 //#SARR_usDualGammaLutRGBIndoor_1__15_ 0x700032CE									   
    CamWriteCmosSensor(0x0F12, 0x0351); //033A//0355 //#SARR_usDualGammaLutRGBIndoor_1__16_ 0x700032D0									   
    CamWriteCmosSensor(0x0F12, 0x0395); //0380//0394 //#SARR_usDualGammaLutRGBIndoor_1__17_ 0x700032D2									   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03C2//03CE //#SARR_usDualGammaLutRGBIndoor_1__18_ 0x700032D4									   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF//03FF //#SARR_usDualGammaLutRGBIndoor_1__19_ 0x700032D6									   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000//0000 //#SARR_usDualGammaLutRGBIndoor_2__0_ 0x700032D8									   
    CamWriteCmosSensor(0x0F12, 0x0004); //0008//0004 //#SARR_usDualGammaLutRGBIndoor_2__1_ 0x700032DA									   
    CamWriteCmosSensor(0x0F12, 0x000C); //0013//0010 //#SARR_usDualGammaLutRGBIndoor_2__2_ 0x700032DC									   
    CamWriteCmosSensor(0x0F12, 0x0024); //002C//002A //#SARR_usDualGammaLutRGBIndoor_2__3_ 0x700032DE									   
    CamWriteCmosSensor(0x0F12, 0x006E); //#SARR_usDualGammaLutRGBOutdoor_1__4_ 0x70003330												   
    CamWriteCmosSensor(0x0F12, 0x00D1); //#SARR_usDualGammaLutRGBOutdoor_1__5_ 0x70003332												   
    CamWriteCmosSensor(0x0F12, 0x0119); //#SARR_usDualGammaLutRGBOutdoor_1__6_ 0x70003334												   
    CamWriteCmosSensor(0x0F12, 0x0139); //#SARR_usDualGammaLutRGBOutdoor_1__7_ 0x70003336												   
    CamWriteCmosSensor(0x0F12, 0x0157); //#SARR_usDualGammaLutRGBOutdoor_1__8_ 0x70003338												   
    CamWriteCmosSensor(0x0F12, 0x018E); //#SARR_usDualGammaLutRGBOutdoor_1__9_ 0x7000333A												   
    CamWriteCmosSensor(0x0F12, 0x01C3); //#SARR_usDualGammaLutRGBOutdoor_1__10_0x7000333C												   
    CamWriteCmosSensor(0x0F12, 0x01F3); //#SARR_usDualGammaLutRGBOutdoor_1__11_0x7000333E												   
    CamWriteCmosSensor(0x0F12, 0x021F); //0221//0232 //#SARR_usDualGammaLutRGBIndoor_2__12_ 0x700032F0									   
    CamWriteCmosSensor(0x0F12, 0x0269); //025D//0273 //#SARR_usDualGammaLutRGBIndoor_2__13_ 0x700032F2									   
    CamWriteCmosSensor(0x0F12, 0x02A6); //0291//02AF //#SARR_usDualGammaLutRGBIndoor_2__14_ 0x700032F4									   
    CamWriteCmosSensor(0x0F12, 0x02FF); //02EB//0309 //#SARR_usDualGammaLutRGBIndoor_2__15_ 0x700032F6									   
    CamWriteCmosSensor(0x0F12, 0x0351); //033A//0355 //#SARR_usDualGammaLutRGBIndoor_2__16_ 0x700032F8									   
    CamWriteCmosSensor(0x0F12, 0x0395); //0380//0394 //#SARR_usDualGammaLutRGBIndoor_2__17_ 0x700032FA									   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03C2//03CE //#SARR_usDualGammaLutRGBIndoor_2__18_ 0x700032FC									   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF//03FF //#SARR_usDualGammaLutRGBIndoor_2__19_ 0x700032FE									   
    CamWriteCmosSensor(0x0F12, 0x0000); //#SARR_usDualGammaLutRGBOutdoor_0__0_ 0x70003300												   
    CamWriteCmosSensor(0x0F12, 0x0004); //#SARR_usDualGammaLutRGBOutdoor_0__1_ 0x70003302												   
    CamWriteCmosSensor(0x0F12, 0x000C); //#SARR_usDualGammaLutRGBOutdoor_0__2_ 0x70003304												   
    CamWriteCmosSensor(0x0F12, 0x0024); //#SARR_usDualGammaLutRGBOutdoor_0__3_ 0x70003306												   
    CamWriteCmosSensor(0x0F12, 0x006E); //#SARR_usDualGammaLutRGBOutdoor_0__4_ 0x70003308												   
    CamWriteCmosSensor(0x0F12, 0x00D1); //#SARR_usDualGammaLutRGBOutdoor_0__5_ 0x7000330A												   
    CamWriteCmosSensor(0x0F12, 0x0119); //#SARR_usDualGammaLutRGBOutdoor_0__6_ 0x7000330C												   
    CamWriteCmosSensor(0x0F12, 0x0139); //#SARR_usDualGammaLutRGBOutdoor_0__7_ 0x7000330E												   
    CamWriteCmosSensor(0x0F12, 0x0157); //#SARR_usDualGammaLutRGBOutdoor_0__8_ 0x70003310												   
    CamWriteCmosSensor(0x0F12, 0x018E); //#SARR_usDualGammaLutRGBOutdoor_0__9_ 0x70003312												   
    CamWriteCmosSensor(0x0F12, 0x01C3); //#SARR_usDualGammaLutRGBOutdoor_0__10_0x70003314												   
    CamWriteCmosSensor(0x0F12, 0x01F3); //#SARR_usDualGammaLutRGBOutdoor_0__11_0x70003316												   
    CamWriteCmosSensor(0x0F12, 0x021F); //#SARR_usDualGammaLutRGBOutdoor_0__12_0x70003318												   
    CamWriteCmosSensor(0x0F12, 0x0269); //#SARR_usDualGammaLutRGBOutdoor_0__13_0x7000331A												   
    CamWriteCmosSensor(0x0F12, 0x02A6); //#SARR_usDualGammaLutRGBOutdoor_0__14_0x7000331C												   
    CamWriteCmosSensor(0x0F12, 0x02FF); //#SARR_usDualGammaLutRGBOutdoor_0__15_0x7000331E												   
    CamWriteCmosSensor(0x0F12, 0x0351); //#SARR_usDualGammaLutRGBOutdoor_0__16_0x70003320												   
    CamWriteCmosSensor(0x0F12, 0x0395); //037C);//0380 //#SARR_usDualGammaLutRGBOutdoor_0__17_0x70003322								   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03AF);//03C2 //#SARR_usDualGammaLutRGBOutdoor_0__18_0x70003324								   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03E0);//03FF //#SARR_usDualGammaLutRGBOutdoor_0__19_0x70003326								   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000);//0000 //#SARR_usDualGammaLutRGBOutdoor_1__0_ 0x70003328								   
    CamWriteCmosSensor(0x0F12, 0x0004); //#SARR_usDualGammaLutRGBOutdoor_1__1_ 0x7000332A												   
    CamWriteCmosSensor(0x0F12, 0x000C); //#SARR_usDualGammaLutRGBOutdoor_1__2_ 0x7000332C												   
    CamWriteCmosSensor(0x0F12, 0x0024); //#SARR_usDualGammaLutRGBOutdoor_1__3_ 0x7000332E												   
    CamWriteCmosSensor(0x0F12, 0x006E); //#SARR_usDualGammaLutRGBOutdoor_1__4_ 0x70003330												   
    CamWriteCmosSensor(0x0F12, 0x00D1); //#SARR_usDualGammaLutRGBOutdoor_1__5_ 0x70003332												   
    CamWriteCmosSensor(0x0F12, 0x0119); //#SARR_usDualGammaLutRGBOutdoor_1__6_ 0x70003334												   
    CamWriteCmosSensor(0x0F12, 0x0139); //#SARR_usDualGammaLutRGBOutdoor_1__7_ 0x70003336												   
    CamWriteCmosSensor(0x0F12, 0x0157); //#SARR_usDualGammaLutRGBOutdoor_1__8_ 0x70003338												   
    CamWriteCmosSensor(0x0F12, 0x018E); //#SARR_usDualGammaLutRGBOutdoor_1__9_ 0x7000333A												   
    CamWriteCmosSensor(0x0F12, 0x01C3); //#SARR_usDualGammaLutRGBOutdoor_1__10_0x7000333C												   
    CamWriteCmosSensor(0x0F12, 0x01F3); //#SARR_usDualGammaLutRGBOutdoor_1__11_0x7000333E												   
    CamWriteCmosSensor(0x0F12, 0x021F); //#SARR_usDualGammaLutRGBOutdoor_1__12_0x70003340												   
    CamWriteCmosSensor(0x0F12, 0x0269); //#SARR_usDualGammaLutRGBOutdoor_1__13_0x70003342												   
    CamWriteCmosSensor(0x0F12, 0x02A6); //#SARR_usDualGammaLutRGBOutdoor_1__14_0x70003344												   
    CamWriteCmosSensor(0x0F12, 0x02FF); //#SARR_usDualGammaLutRGBOutdoor_1__15_0x70003346												   
    CamWriteCmosSensor(0x0F12, 0x0351); //#SARR_usDualGammaLutRGBOutdoor_1__16_0x70003348												   
    CamWriteCmosSensor(0x0F12, 0x0395); //037C);//0380 //#SARR_usDualGammaLutRGBOutdoor_1__17_0x7000334A								   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03AF);//03C2 //#SARR_usDualGammaLutRGBOutdoor_1__18_0x7000334C								   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03E0);//03FF //#SARR_usDualGammaLutRGBOutdoor_1__19_0x7000334E								   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000 //#SARR_usDualGammaLutRGBOutdoor_2__0_ 0x70003350 										   
    CamWriteCmosSensor(0x0F12, 0x0004); //#SARR_usDualGammaLutRGBOutdoor_2__1_ 0x70003352												   
    CamWriteCmosSensor(0x0F12, 0x000C); //#SARR_usDualGammaLutRGBOutdoor_2__2_ 0x70003354												   
    CamWriteCmosSensor(0x0F12, 0x0024); //#SARR_usDualGammaLutRGBOutdoor_2__3_ 0x70003356												   
    CamWriteCmosSensor(0x0F12, 0x006E); //#SARR_usDualGammaLutRGBOutdoor_2__4_ 0x70003358												   
    CamWriteCmosSensor(0x0F12, 0x00D1); //#SARR_usDualGammaLutRGBOutdoor_2__5_ 0x7000335A												   
    CamWriteCmosSensor(0x0F12, 0x0119); //#SARR_usDualGammaLutRGBOutdoor_2__6_ 0x7000335C												   
    CamWriteCmosSensor(0x0F12, 0x0139); //#SARR_usDualGammaLutRGBOutdoor_2__7_ 0x7000335E												   
    CamWriteCmosSensor(0x0F12, 0x0157); //#SARR_usDualGammaLutRGBOutdoor_2__8_ 0x70003360												   
    CamWriteCmosSensor(0x0F12, 0x018E); //#SARR_usDualGammaLutRGBOutdoor_2__9_ 0x70003362												   
    CamWriteCmosSensor(0x0F12, 0x01C3); //#SARR_usDualGammaLutRGBOutdoor_2__10_0x70003364												   
    CamWriteCmosSensor(0x0F12, 0x01F3); //#SARR_usDualGammaLutRGBOutdoor_2__11_0x70003366												   
    CamWriteCmosSensor(0x0F12, 0x021F); //#SARR_usDualGammaLutRGBOutdoor_2__12_0x70003368												   
    CamWriteCmosSensor(0x0F12, 0x0269); //#SARR_usDualGammaLutRGBOutdoor_2__13_0x7000336A												   
    CamWriteCmosSensor(0x0F12, 0x02A6); //#SARR_usDualGammaLutRGBOutdoor_2__14_0x7000336C												   
    CamWriteCmosSensor(0x0F12, 0x02FF); //#SARR_usDualGammaLutRGBOutdoor_2__15_0x7000336E												   
    CamWriteCmosSensor(0x0F12, 0x0351); //#SARR_usDualGammaLutRGBOutdoor_2__16_0x70003370												   
    CamWriteCmosSensor(0x0F12, 0x0395); //037C);//0380 //#SARR_usDualGammaLutRGBOutdoor_2__17_0x70003372								   
    CamWriteCmosSensor(0x0F12, 0x03CE); //03AF);//03C2 //#SARR_usDualGammaLutRGBOutdoor_2__18_0x70003374								   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03E0);//03FF //#SARR_usDualGammaLutRGBOutdoor_2__19_0x70003376								   
    																																																		
    																																																		
    																																																		
    //================================ ================================================================											   
    // SET AFIT																																													
    //================================ ================================================================											   
    // Noise index																																											
    //===============================================================================================											   
    																																																		
    CamWriteCmosSensor(0x002A, 0x0764);																																	
    CamWriteCmosSensor(0x0F12, 0x0049); // #afit_uNoiseIndInDoor[0] // 64																   
    CamWriteCmosSensor(0x0F12, 0x00A5); ////#afit_uNoiseIndInDoor[1] //#99																   
    CamWriteCmosSensor(0x0F12, 0x016B); ////#afit_uNoiseIndInDoor[2] //#187																   
    CamWriteCmosSensor(0x0F12, 0x0226); ////#afit_uNoiseIndInDoor[3] //#403->380 														   
    CamWriteCmosSensor(0x0F12, 0x02EA); ////#afit_uNoiseIndInDoor[4] //#700																   
    // AFIT table start address // 700 _07C4 																														
    CamWriteCmosSensor(0x002A, 0x0770);																																	
    CamWriteCmosSensor(0x0F12, 0x07C4);																																	
    CamWriteCmosSensor(0x0F12, 0x7000);																																	
    // AFIT table (Variables)																																						
    CamWriteCmosSensor(0x002A, 0x07C4); //																															
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[0]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[1]															   
    CamWriteCmosSensor(0x0F12, 0xFFA0); ///0003//000A//0005 //#TVAR_afit_pBaseVals[2]// lowlight noise									   
    CamWriteCmosSensor(0x0F12, 0x0005); ///0000//0000//0000 //#TVAR_afit_pBaseVals[3]													   
    CamWriteCmosSensor(0x0F12, 0xFFF6); ///0000//0000//0000 //#TVAR_afit_pBaseVals[4]													   
    CamWriteCmosSensor(0x0F12, 0x00C4); ///001E//001E//00C4 //#TVAR_afit_pBaseVals[5]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[6]													   
    CamWriteCmosSensor(0x0F12, 0x009C); ///009C//009C//009C //#TVAR_afit_pBaseVals[7]													   
    CamWriteCmosSensor(0x0F12, 0x017C); ///017C//017C//017C //#TVAR_afit_pBaseVals[8]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[9]													   
    CamWriteCmosSensor(0x0F12, 0x000C); ///000C//000C//000C //#TVAR_afit_pBaseVals[10]													   
    CamWriteCmosSensor(0x0F12, 0x0010); ///0010//0010//0010 //#TVAR_afit_pBaseVals[11]													   
    CamWriteCmosSensor(0x0F12, 0x012C); ///0104//0104//012C //#TVAR_afit_pBaseVals[12]													   
    CamWriteCmosSensor(0x0F12, 0x03E8); ///03E8//03E8//03E8 //#TVAR_afit_pBaseVals[13]													   
    CamWriteCmosSensor(0x0F12, 0x0046); ///0023//0023//0046 //#TVAR_afit_pBaseVals[14]													   
    CamWriteCmosSensor(0x0F12, 0x005A); ///012C//012C//005A //#TVAR_afit_pBaseVals[15]													   
    CamWriteCmosSensor(0x0F12, 0x0070); ///0070//0070//0070 //#TVAR_afit_pBaseVals[16]													   
    CamWriteCmosSensor(0x0F12, 0x0019); ///0004//0004//0019 //#TVAR_afit_pBaseVals[17]													   
    CamWriteCmosSensor(0x0F12, 0x0019); ///0004//0004//0019 //#TVAR_afit_pBaseVals[18]													   
    CamWriteCmosSensor(0x0F12, 0x01AA); ///01AA//01AA//01AA //#TVAR_afit_pBaseVals[19]													   
    CamWriteCmosSensor(0x0F12, 0x0064); ///0064//0064//0064 //#TVAR_afit_pBaseVals[20]													   
    CamWriteCmosSensor(0x0F12, 0x0064); ///0064//0064//0064 //#TVAR_afit_pBaseVals[21]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[22]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[23]													   
    CamWriteCmosSensor(0x0F12, 0x0032); ///002A//002A//0032 //#TVAR_afit_pBaseVals[24]													   
    CamWriteCmosSensor(0x0F12, 0x0012); ///0024//0024//0012 //#TVAR_afit_pBaseVals[25]													   
    CamWriteCmosSensor(0x0F12, 0x002A); //002A); // // #TVAR_afit_pBaseVals[26]															   
    CamWriteCmosSensor(0x0F12, 0x0024); //0024); //// #TVAR_afit_pBaseVals[27]															   
    CamWriteCmosSensor(0x0F12, 0x002A); //002A); // // #TVAR_afit_pBaseVals[28]															   
    CamWriteCmosSensor(0x0F12, 0x0024); //0024); //// #TVAR_afit_pBaseVals[29]															   
    CamWriteCmosSensor(0x0F12, 0x0A24); ///0A0F//0A0F//0A24 //#TVAR_afit_pBaseVals[30]													   
    CamWriteCmosSensor(0x0F12, 0x1701); //1701); //// #TVAR_afit_pBaseVals[31]															   
    CamWriteCmosSensor(0x0F12, 0x0229); //0229); //// #TVAR_afit_pBaseVals[32]															   
    CamWriteCmosSensor(0x0F12, 0x1403); //// #TVAR_afit_pBaseVals[33]																		  
    CamWriteCmosSensor(0x0F12, 0x0000); //// #TVAR_afit_pBaseVals[34]																		  
    CamWriteCmosSensor(0x0F12, 0x0000); //// #TVAR_afit_pBaseVals[35]																		  
    CamWriteCmosSensor(0x0F12, 0x0000); //// #TVAR_afit_pBaseVals[36]																		  
    CamWriteCmosSensor(0x0F12, 0x00FF); //// #TVAR_afit_pBaseVals[37]																		  
    CamWriteCmosSensor(0x0F12, 0x043B); ///053B//053B//043B //#TVAR_afit_pBaseVals[38]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///0505//0505//1414 //#TVAR_afit_pBaseVals[39]													   
    CamWriteCmosSensor(0x0F12, 0x0301); ///0301//0301//0301 //#TVAR_afit_pBaseVals[40]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///8007//8007//FF07 //#TVAR_afit_pBaseVals[41]													   
    CamWriteCmosSensor(0x0F12, 0x051E); ///051E//051E//051E //#TVAR_afit_pBaseVals[42]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[43]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///0F0F//0F0F//0F0F //#TVAR_afit_pBaseVals[44]													   
    CamWriteCmosSensor(0x0F12, 0x0A05); ///0A05//0A05//0A05 //#TVAR_afit_pBaseVals[45]													   
    CamWriteCmosSensor(0x0F12, 0x0A3C); ///2428//103C//0A3C //#TVAR_afit_pBaseVals[46]													   
    CamWriteCmosSensor(0x0F12, 0x0A28); ///1E14//0A28//0A28 //#TVAR_afit_pBaseVals[47]													   
    CamWriteCmosSensor(0x0F12, 0x0002); //0002//0002//0002 //#TVAR_afit_pBaseVals[48]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); //00FF//00FF//00FF //#TVAR_afit_pBaseVals[49]													   
    CamWriteCmosSensor(0x0F12, 0x1102); //1002//1002//1102 //#TVAR_afit_pBaseVals[50]													   
    CamWriteCmosSensor(0x0F12, 0x001B); //001B); //// #TVAR_afit_pBaseVals[51]															   
    CamWriteCmosSensor(0x0F12, 0x0900); //0900); //// #TVAR_afit_pBaseVals[52]															   
    CamWriteCmosSensor(0x0F12, 0x0600); //0600); //// #TVAR_afit_pBaseVals[53]															   
    CamWriteCmosSensor(0x0F12, 0x0504); //0504); //// #TVAR_afit_pBaseVals[54]															   
    CamWriteCmosSensor(0x0F12, 0x0305); //0305); //// #TVAR_afit_pBaseVals[55]															   
    CamWriteCmosSensor(0x0F12, 0x3C03); ///5A03//5A03//3C03 //#TVAR_afit_pBaseVals[56]													   
    CamWriteCmosSensor(0x0F12, 0x006E); ///006E//006E//006E //#TVAR_afit_pBaseVals[57]													   
    CamWriteCmosSensor(0x0F12, 0x0178); ///0A78//0A78//0178 //#TVAR_afit_pBaseVals[58]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[59]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///3232//3232//1414 //#TVAR_afit_pBaseVals[60]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[61]													   
    CamWriteCmosSensor(0x0F12, 0x5002); ///5001//5001//5002 //#TVAR_afit_pBaseVals[62]													   
    CamWriteCmosSensor(0x0F12, 0x7850); ///8C50//7850//7850 //#TVAR_afit_pBaseVals[63]													   
    CamWriteCmosSensor(0x0F12, 0x2878); ///288C//2878//2878 //#TVAR_afit_pBaseVals[64]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); //0A00); //// #TVAR_afit_pBaseVals[65]															   
    CamWriteCmosSensor(0x0F12, 0x1403); //1403); //// #TVAR_afit_pBaseVals[66]															   
    CamWriteCmosSensor(0x0F12, 0x1E0C); ///1E07//1E07//1E0C //#TVAR_afit_pBaseVals[67]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///070A//070A//070A //#TVAR_afit_pBaseVals[68]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[69]													   
    CamWriteCmosSensor(0x0F12, 0x4104); ///3C04//5004//4104 //#TVAR_afit_pBaseVals[70]													   
    CamWriteCmosSensor(0x0F12, 0x123C); ///0F2C//0F40//123C //#TVAR_afit_pBaseVals[71]													   
    CamWriteCmosSensor(0x0F12, 0x4012); ///400F//400F//4012 //#TVAR_afit_pBaseVals[72]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[73]													   
    CamWriteCmosSensor(0x0F12, 0x1E03); ///3203//3203//1E03 //#TVAR_afit_pBaseVals[74]													   
    CamWriteCmosSensor(0x0F12, 0x011E); ///0132//0132//011E //#TVAR_afit_pBaseVals[75]													   
    CamWriteCmosSensor(0x0F12, 0x0201); //0201); //// #TVAR_afit_pBaseVals[76]															   
    CamWriteCmosSensor(0x0F12, 0x5050); //5050); //// #TVAR_afit_pBaseVals[77]															   
    CamWriteCmosSensor(0x0F12, 0x3C3C); //3C3C); //// #TVAR_afit_pBaseVals[78]															   
    CamWriteCmosSensor(0x0F12, 0x0028); //0028); //// #TVAR_afit_pBaseVals[79]															   
    CamWriteCmosSensor(0x0F12, 0x030A); //030A); //// #TVAR_afit_pBaseVals[80]															   
    CamWriteCmosSensor(0x0F12, 0x0714); //0714); //// #TVAR_afit_pBaseVals[81]															   
    CamWriteCmosSensor(0x0F12, 0x0A1E); //0A1E); //// #TVAR_afit_pBaseVals[82]															   
    CamWriteCmosSensor(0x0F12, 0xFF07); //FF07); //// #TVAR_afit_pBaseVals[83]															   
    CamWriteCmosSensor(0x0F12, 0x0432); //0432); //// #TVAR_afit_pBaseVals[84]															   
    CamWriteCmosSensor(0x0F12, 0x4050); //4050); //// #TVAR_afit_pBaseVals[85]															   
    CamWriteCmosSensor(0x0F12, 0x0F0F); //0F0F); //// #TVAR_afit_pBaseVals[86]															   
    CamWriteCmosSensor(0x0F12, 0x0440); //0440); //// #TVAR_afit_pBaseVals[87]															   
    CamWriteCmosSensor(0x0F12, 0x0302); //0302); //// #TVAR_afit_pBaseVals[88]															   
    CamWriteCmosSensor(0x0F12, 0x1E1E); ///3232//3232//1E1E //#TVAR_afit_pBaseVals[89]													   
    CamWriteCmosSensor(0x0F12, 0x0101); //0101); //// #TVAR_afit_pBaseVals[90]															   
    CamWriteCmosSensor(0x0F12, 0x5002); //5002); //// #TVAR_afit_pBaseVals[91]															   
    CamWriteCmosSensor(0x0F12, 0x3C50); //3C50); //// #TVAR_afit_pBaseVals[92]															   
    CamWriteCmosSensor(0x0F12, 0x283C); //283C); //// #TVAR_afit_pBaseVals[93]															   
    CamWriteCmosSensor(0x0F12, 0x0A00); //0A00); //// #TVAR_afit_pBaseVals[94]															   
    CamWriteCmosSensor(0x0F12, 0x1403); //1403); //// #TVAR_afit_pBaseVals[95]															   
    CamWriteCmosSensor(0x0F12, 0x1E07); //1E07); //// #TVAR_afit_pBaseVals[96]															   
    CamWriteCmosSensor(0x0F12, 0x070A); //070A); //// #TVAR_afit_pBaseVals[97]															   
    CamWriteCmosSensor(0x0F12, 0x32FF); //32FF); //// #TVAR_afit_pBaseVals[98]															   
    CamWriteCmosSensor(0x0F12, 0x5004); //5004); //// #TVAR_afit_pBaseVals[99]															   
    CamWriteCmosSensor(0x0F12, 0x0F40); //0F40); //// #TVAR_afit_pBaseVals[100]															   
    CamWriteCmosSensor(0x0F12, 0x400F); //400F); //// #TVAR_afit_pBaseVals[101]															   
    CamWriteCmosSensor(0x0F12, 0x0204); //0204); //// #TVAR_afit_pBaseVals[102]															   
    CamWriteCmosSensor(0x0F12, 0x0003); //0003); //// #TVAR_afit_pBaseVals[103]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[104]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[105]															   
    CamWriteCmosSensor(0x0F12, 0x0000); ///000A//0014//0014 //#TVAR_afit_pBaseVals[106]													   
    CamWriteCmosSensor(0x0F12, 0x0005); ///0000//0000//0000 //#TVAR_afit_pBaseVals[107]													   
    CamWriteCmosSensor(0x0F12, 0xFFF6); ///0000//0000//0000 //#TVAR_afit_pBaseVals[108]													   
    CamWriteCmosSensor(0x0F12, 0x00C4); ///001E//001E//00C4 //#TVAR_afit_pBaseVals[109]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[110]													   
    CamWriteCmosSensor(0x0F12, 0x009C); ///009C//009C//009C //#TVAR_afit_pBaseVals[111]													   
    CamWriteCmosSensor(0x0F12, 0x017C); ///017C//017C//017C //#TVAR_afit_pBaseVals[112]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[113]													   
    CamWriteCmosSensor(0x0F12, 0x000C); ///000C//000C//000C //#TVAR_afit_pBaseVals[114]													   
    CamWriteCmosSensor(0x0F12, 0x0010); ///0010//0010//0010 //#TVAR_afit_pBaseVals[115]													   
    CamWriteCmosSensor(0x0F12, 0x012C); ///0104//0104//012C //#TVAR_afit_pBaseVals[116]													   
    CamWriteCmosSensor(0x0F12, 0x03E8); ///03E8//03E8//03E8 //#TVAR_afit_pBaseVals[117]													   
    CamWriteCmosSensor(0x0F12, 0x0046); ///0023//0023//0046 //#TVAR_afit_pBaseVals[118]													   
    CamWriteCmosSensor(0x0F12, 0x005A); ///012C//012C//005A //#TVAR_afit_pBaseVals[119]													   
    CamWriteCmosSensor(0x0F12, 0x0070); ///0070//0070//0070 //#TVAR_afit_pBaseVals[120]													   
    CamWriteCmosSensor(0x0F12, 0x000F); ///0004//0004//000F //#TVAR_afit_pBaseVals[121]													   
    CamWriteCmosSensor(0x0F12, 0x000F); ///0004//0004//000F //#TVAR_afit_pBaseVals[122]													   
    CamWriteCmosSensor(0x0F12, 0x01AA); ///01AA//01AA//01AA //#TVAR_afit_pBaseVals[123]													   
    CamWriteCmosSensor(0x0F12, 0x003C); ///001E//001E//003C //#TVAR_afit_pBaseVals[124]													   
    CamWriteCmosSensor(0x0F12, 0x003C); ///001E//001E//003C //#TVAR_afit_pBaseVals[125]													   
    CamWriteCmosSensor(0x0F12, 0x0005); ///0005//0005//0005 //#TVAR_afit_pBaseVals[126]													   
    CamWriteCmosSensor(0x0F12, 0x0005); ///0005//0005//0005 //#TVAR_afit_pBaseVals[127]													   
    CamWriteCmosSensor(0x0F12, 0x0046); ///002A//002A//0046 //#TVAR_afit_pBaseVals[128]													   
    CamWriteCmosSensor(0x0F12, 0x0019); ///0024//0024//0019 //#TVAR_afit_pBaseVals[129]													   
    CamWriteCmosSensor(0x0F12, 0x002A); ///002A//002A//002A //#TVAR_afit_pBaseVals[130]													   
    CamWriteCmosSensor(0x0F12, 0x0024); ///0024//0024//0024 //#TVAR_afit_pBaseVals[131]													   
    CamWriteCmosSensor(0x0F12, 0x002A); ///002A//002A//002A //#TVAR_afit_pBaseVals[132]													   
    CamWriteCmosSensor(0x0F12, 0x0024); ///0024//0024//0024 //#TVAR_afit_pBaseVals[133]													   
    CamWriteCmosSensor(0x0F12, 0x0A24); ///0A0F//0A0F//0A24 //#TVAR_afit_pBaseVals[134]													   
    CamWriteCmosSensor(0x0F12, 0x1701); ///1701//1701//1701 //#TVAR_afit_pBaseVals[135]													   
    CamWriteCmosSensor(0x0F12, 0x0229); ///0229//0229//0229 //#TVAR_afit_pBaseVals[136]													   
    CamWriteCmosSensor(0x0F12, 0x1403); ///1403//1403//1403 //#TVAR_afit_pBaseVals[137]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[138]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[139]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0101//0101//0000 //#TVAR_afit_pBaseVals[140]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); ///00FF//00FF//00FF //#TVAR_afit_pBaseVals[141]													   
    CamWriteCmosSensor(0x0F12, 0x043B); ///053B//053B//043B //#TVAR_afit_pBaseVals[142]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///0505//0505//1414 //#TVAR_afit_pBaseVals[143]													   
    CamWriteCmosSensor(0x0F12, 0x0301); ///0301//0301//0301 //#TVAR_afit_pBaseVals[144]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///8007//8007//FF07 //#TVAR_afit_pBaseVals[145]													   
    CamWriteCmosSensor(0x0F12, 0x051E); ///051E//051E//051E //#TVAR_afit_pBaseVals[146]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[147]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///0F0F//0F0F//0F0F //#TVAR_afit_pBaseVals[148]													   
    CamWriteCmosSensor(0x0F12, 0x0A03); ///0A04//0A04//0A03 //#TVAR_afit_pBaseVals[149]													   
    CamWriteCmosSensor(0x0F12, 0x0A3C); ///2428//103C//0A3C //#TVAR_afit_pBaseVals[150]													   
    CamWriteCmosSensor(0x0F12, 0x0A28); ///1E14//0A28//0A28 //#TVAR_afit_pBaseVals[151]													   
    CamWriteCmosSensor(0x0F12, 0x0002); ///0002//0002//0002 //#TVAR_afit_pBaseVals[152]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); ///00FF//00FF//00FF //#TVAR_afit_pBaseVals[153]													   
    CamWriteCmosSensor(0x0F12, 0x1102); ///1002//1002//1102 //#TVAR_afit_pBaseVals[154]													   
    CamWriteCmosSensor(0x0F12, 0x001B); ///001D//001D//001B //#TVAR_afit_pBaseVals[155]													   
    CamWriteCmosSensor(0x0F12, 0x0900); ///0900//0900//0900 //#TVAR_afit_pBaseVals[156]													   
    CamWriteCmosSensor(0x0F12, 0x0600); ///0600//0600//0600 //#TVAR_afit_pBaseVals[157]													   
    CamWriteCmosSensor(0x0F12, 0x0504); ///0504//0504//0504 //#TVAR_afit_pBaseVals[158]													   
    CamWriteCmosSensor(0x0F12, 0x0305); ///0305//0305//0305 //#TVAR_afit_pBaseVals[159]													   
    CamWriteCmosSensor(0x0F12, 0x4603); ///5F03//5F03//4603 //#TVAR_afit_pBaseVals[160]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[161]													   
    CamWriteCmosSensor(0x0F12, 0x0180); ///0080//0080//0180 //#TVAR_afit_pBaseVals[162]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[163]													   
    CamWriteCmosSensor(0x0F12, 0x1919); ///3232//3232//1919 //#TVAR_afit_pBaseVals[164]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[165]													   
    CamWriteCmosSensor(0x0F12, 0x3C02); ///2A01//2A01//3C02 //#TVAR_afit_pBaseVals[166]													   
    CamWriteCmosSensor(0x0F12, 0x643C); ///4632//3232//643C //#TVAR_afit_pBaseVals[167]													   
    CamWriteCmosSensor(0x0F12, 0x2864); ///2844//2830//2864 //#TVAR_afit_pBaseVals[168]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[169]													   
    CamWriteCmosSensor(0x0F12, 0x1403); ///1403//1403//1403 //#TVAR_afit_pBaseVals[170]													   
    CamWriteCmosSensor(0x0F12, 0x1E0C); ///1E07//1E07//1E0C //#TVAR_afit_pBaseVals[171]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///070A//070A//070A //#TVAR_afit_pBaseVals[172]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[173]													   
    CamWriteCmosSensor(0x0F12, 0x4104); ///3C04//5004//4104 //#TVAR_afit_pBaseVals[174]													   
    CamWriteCmosSensor(0x0F12, 0x123C); ///0F2C//0F40//123C //#TVAR_afit_pBaseVals[175]													   
    CamWriteCmosSensor(0x0F12, 0x4012); ///400F//400F//4012 //#TVAR_afit_pBaseVals[176]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[177]													   
    CamWriteCmosSensor(0x0F12, 0x1E03); ///3203//3203//1E03 //#TVAR_afit_pBaseVals[178]													   
    CamWriteCmosSensor(0x0F12, 0x011E); ///0132//0132//011E //#TVAR_afit_pBaseVals[179]													   
    CamWriteCmosSensor(0x0F12, 0x0201); ///0101//0101//0201 //#TVAR_afit_pBaseVals[180]													   
    CamWriteCmosSensor(0x0F12, 0x3232); ///262A//262A//3232 //#TVAR_afit_pBaseVals[181]													   
    CamWriteCmosSensor(0x0F12, 0x3C3C); ///3032//3032//3C3C //#TVAR_afit_pBaseVals[182]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[183]													   
    CamWriteCmosSensor(0x0F12, 0x030A); ///030A//030A//030A //#TVAR_afit_pBaseVals[184]													   
    CamWriteCmosSensor(0x0F12, 0x0714); ///0714//0714//0714 //#TVAR_afit_pBaseVals[185]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[186]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///FF07//FF07//FF07 //#TVAR_afit_pBaseVals[187]													   
    CamWriteCmosSensor(0x0F12, 0x0432); ///0432//0432//0432 //#TVAR_afit_pBaseVals[188]													   
    CamWriteCmosSensor(0x0F12, 0x4050); ///4050//4050//4050 //#TVAR_afit_pBaseVals[189]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///0F0F//0F0F//0F0F //#TVAR_afit_pBaseVals[190]													   
    CamWriteCmosSensor(0x0F12, 0x0440); ///0440//0440//0440 //#TVAR_afit_pBaseVals[191]													   
    CamWriteCmosSensor(0x0F12, 0x0302); ///0302//0302//0302 //#TVAR_afit_pBaseVals[192]													   
    CamWriteCmosSensor(0x0F12, 0x1E1E); ///3232//3232//1E1E //#TVAR_afit_pBaseVals[193]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[194]													   
    CamWriteCmosSensor(0x0F12, 0x3202); ///2A01//2A01//3202 //#TVAR_afit_pBaseVals[195]													   
    CamWriteCmosSensor(0x0F12, 0x3C32); ///3226//3226//3C32 //#TVAR_afit_pBaseVals[196]													   
    CamWriteCmosSensor(0x0F12, 0x283C); ///2830//2830//283C //#TVAR_afit_pBaseVals[197]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[198]													   
    CamWriteCmosSensor(0x0F12, 0x1403); ///1403//1403//1403 //#TVAR_afit_pBaseVals[199]													   
    CamWriteCmosSensor(0x0F12, 0x1E07); ///1E07//1E07//1E07 //#TVAR_afit_pBaseVals[200]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///070A//070A//070A //#TVAR_afit_pBaseVals[201]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[202]													   
    CamWriteCmosSensor(0x0F12, 0x5004); ///5004//5004//5004 //#TVAR_afit_pBaseVals[203]													   
    CamWriteCmosSensor(0x0F12, 0x0F40); ///0F40//0F40//0F40 //#TVAR_afit_pBaseVals[204]													   
    CamWriteCmosSensor(0x0F12, 0x400F); ///400F//400F//400F //#TVAR_afit_pBaseVals[205]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[206]													   
    CamWriteCmosSensor(0x0F12, 0x0003); ///0003//0003//0003 //#TVAR_afit_pBaseVals[207]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[208]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[209]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0019//0019//0019 //#TVAR_afit_pBaseVals[210]													   
    CamWriteCmosSensor(0x0F12, 0x0005); ///0000//0000//0000 //#TVAR_afit_pBaseVals[211]													   
    CamWriteCmosSensor(0x0F12, 0xFFF6); ///0000//0000//0000 //#TVAR_afit_pBaseVals[212]													   
    CamWriteCmosSensor(0x0F12, 0x00C4); ///001E//001E//00C4 //#TVAR_afit_pBaseVals[213]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF); //// #TVAR_afit_pBaseVals[214]															   
    CamWriteCmosSensor(0x0F12, 0x009C); //009C); //// #TVAR_afit_pBaseVals[215]															   
    CamWriteCmosSensor(0x0F12, 0x017C); //017C); //// #TVAR_afit_pBaseVals[216]															   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF); //// #TVAR_afit_pBaseVals[217]															   
    CamWriteCmosSensor(0x0F12, 0x000C); //000C); //// #TVAR_afit_pBaseVals[218]															   
    CamWriteCmosSensor(0x0F12, 0x0010); //0010); //// #TVAR_afit_pBaseVals[219]															   
    CamWriteCmosSensor(0x0F12, 0x012C); //012C); //// #TVAR_afit_pBaseVals[220]															   
    CamWriteCmosSensor(0x0F12, 0x03E8); //03E8); //// #TVAR_afit_pBaseVals[221]															   
    CamWriteCmosSensor(0x0F12, 0x0046); //0046); //// #TVAR_afit_pBaseVals[222]															   
    CamWriteCmosSensor(0x0F12, 0x0078); //0078); //// #TVAR_afit_pBaseVals[223]															   
    CamWriteCmosSensor(0x0F12, 0x0070); //0070); //// #TVAR_afit_pBaseVals[224]															   
    CamWriteCmosSensor(0x0F12, 0x0004); //0004); //// #TVAR_afit_pBaseVals[225]															   
    CamWriteCmosSensor(0x0F12, 0x0004); //0004); //// #TVAR_afit_pBaseVals[226]															   
    CamWriteCmosSensor(0x0F12, 0x01AA); //01AA); //// #TVAR_afit_pBaseVals[227]															   
    CamWriteCmosSensor(0x0F12, 0x001E); //001E); //// #TVAR_afit_pBaseVals[228]															   
    CamWriteCmosSensor(0x0F12, 0x001E); //001E); //// #TVAR_afit_pBaseVals[229]															   
    CamWriteCmosSensor(0x0F12, 0x0005); //0005); //// #TVAR_afit_pBaseVals[126]															   
    CamWriteCmosSensor(0x0F12, 0x0005); //0005); //// #TVAR_afit_pBaseVals[127]															   
    CamWriteCmosSensor(0x0F12, 0x0064); ///0032//0032//0064 //#TVAR_afit_pBaseVals[232]													   
    CamWriteCmosSensor(0x0F12, 0x001B); ///0028//0028//001B //#TVAR_afit_pBaseVals[233]													   
    CamWriteCmosSensor(0x0F12, 0x002A); ///0032//0032//002A //#TVAR_afit_pBaseVals[234]													   
    CamWriteCmosSensor(0x0F12, 0x0024); ///0028//0028//0024 //#TVAR_afit_pBaseVals[235]													   
    CamWriteCmosSensor(0x0F12, 0x002A); ///0032//0032//002A //#TVAR_afit_pBaseVals[236]													   
    CamWriteCmosSensor(0x0F12, 0x0024); ///0028//0028//0024 //#TVAR_afit_pBaseVals[237]													   
    CamWriteCmosSensor(0x0F12, 0x0A24); ///0A0F//0A0F//0A24 //#TVAR_afit_pBaseVals[238]													   
    CamWriteCmosSensor(0x0F12, 0x1701); //1701); //// #TVAR_afit_pBaseVals[135]															   
    CamWriteCmosSensor(0x0F12, 0x0229); //0229); //// #TVAR_afit_pBaseVals[136]															   
    CamWriteCmosSensor(0x0F12, 0x1403); //1403); //// #TVAR_afit_pBaseVals[137]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[138]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[139]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[140]															   
    CamWriteCmosSensor(0x0F12, 0x00FF); //00FF); //// #TVAR_afit_pBaseVals[141]															   
    CamWriteCmosSensor(0x0F12, 0x043B); ///043B//043B//043B //#TVAR_afit_pBaseVals[246]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///0505//0505//1414 //#TVAR_afit_pBaseVals[247]													   
    CamWriteCmosSensor(0x0F12, 0x0301); ///0301//0301//0301 //#TVAR_afit_pBaseVals[248]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///8007//8007//FF07 //#TVAR_afit_pBaseVals[249]													   
    CamWriteCmosSensor(0x0F12, 0x051E); ///051E//051E//051E //#TVAR_afit_pBaseVals[250]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[251]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///0F0F//0F0F//0F0F //#TVAR_afit_pBaseVals[252]													   
    CamWriteCmosSensor(0x0F12, 0x0A03); ///0A03//0A03//0A03 //#TVAR_afit_pBaseVals[253]													   
    CamWriteCmosSensor(0x0F12, 0x0A3C); ///0A46//0A3C//0A3C //#TVAR_afit_pBaseVals[254]													   
    CamWriteCmosSensor(0x0F12, 0x0528); ///0532//0528//0528 //#TVAR_afit_pBaseVals[255]													   
    CamWriteCmosSensor(0x0F12, 0x0002); ///0002//0002//0002 //#TVAR_afit_pBaseVals[256]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); //00FF//00FF//00FF //#TVAR_afit_pBaseVals[153]													   
    CamWriteCmosSensor(0x0F12, 0x1102); //1002//1002//1102 //#TVAR_afit_pBaseVals[154]													   
    CamWriteCmosSensor(0x0F12, 0x001B); //001B); //// #TVAR_afit_pBaseVals[155]															   
    CamWriteCmosSensor(0x0F12, 0x0900); //0900); //// #TVAR_afit_pBaseVals[156]															   
    CamWriteCmosSensor(0x0F12, 0x0600); //0600); //// #TVAR_afit_pBaseVals[157]															   
    CamWriteCmosSensor(0x0F12, 0x0504); //0504); //// #TVAR_afit_pBaseVals[158]															   
    CamWriteCmosSensor(0x0F12, 0x0305); //0305//0305//0305 //#TVAR_afit_pBaseVals[159]													   
    CamWriteCmosSensor(0x0F12, 0x4603); ///6902//6902//4603 //#TVAR_afit_pBaseVals[264]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[265]													   
    CamWriteCmosSensor(0x0F12, 0x0180); ///0080//0080//0180 //#TVAR_afit_pBaseVals[266]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[267]													   
    CamWriteCmosSensor(0x0F12, 0x2323); ///2D2D//2D2D//2323 //#TVAR_afit_pBaseVals[268]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[269]													   
    CamWriteCmosSensor(0x0F12, 0x2A02); ///2001//2001//2A02 //#TVAR_afit_pBaseVals[270]													   
    CamWriteCmosSensor(0x0F12, 0x3C2A); ///1926//2026//3C2A //#TVAR_afit_pBaseVals[271]													   
    CamWriteCmosSensor(0x0F12, 0x283C); ///2818//281E//283C //#TVAR_afit_pBaseVals[272]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[273]													   
    CamWriteCmosSensor(0x0F12, 0x1403); ///0A03//0A03//1403 //#TVAR_afit_pBaseVals[274]													   
    CamWriteCmosSensor(0x0F12, 0x1E0C); ///1E0A//1E0A//1E0C //#TVAR_afit_pBaseVals[275]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///070A//070A//070A //#TVAR_afit_pBaseVals[276]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[277]													   
    CamWriteCmosSensor(0x0F12, 0x4B04); ///5A04//5004//4B04 //#TVAR_afit_pBaseVals[278]													   
    CamWriteCmosSensor(0x0F12, 0x0F40); ///0F4A//0F40//0F40 //#TVAR_afit_pBaseVals[279]													   
    CamWriteCmosSensor(0x0F12, 0x400F); ///400F//400F//400F //#TVAR_afit_pBaseVals[280]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[281]													   
    CamWriteCmosSensor(0x0F12, 0x2303); ///3203//3203//2303 //#TVAR_afit_pBaseVals[282]													   
    CamWriteCmosSensor(0x0F12, 0x0123); ///0132//0132//0123 //#TVAR_afit_pBaseVals[283]													   
    CamWriteCmosSensor(0x0F12, 0x0201); ///0101//0101//0201 //#TVAR_afit_pBaseVals[284]													   
    CamWriteCmosSensor(0x0F12, 0x262A); ///1C20//1C20//262A //#TVAR_afit_pBaseVals[285]													   
    CamWriteCmosSensor(0x0F12, 0x2C2C); ///1C1E//1C1E//2C2C //#TVAR_afit_pBaseVals[286]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[287]													   
    CamWriteCmosSensor(0x0F12, 0x030A); //030A); //// #TVAR_afit_pBaseVals[184]															   
    CamWriteCmosSensor(0x0F12, 0x0714); //0714); //// #TVAR_afit_pBaseVals[185]															   
    CamWriteCmosSensor(0x0F12, 0x0A1E); //0A1E); //// #TVAR_afit_pBaseVals[186]															   
    CamWriteCmosSensor(0x0F12, 0xFF07); //FF07); //// #TVAR_afit_pBaseVals[187]															   
    CamWriteCmosSensor(0x0F12, 0x0432); //0432); //// #TVAR_afit_pBaseVals[188]															   
    CamWriteCmosSensor(0x0F12, 0x4050); //4050); //// #TVAR_afit_pBaseVals[189]															   
    CamWriteCmosSensor(0x0F12, 0x0F0F); //0F0F); //// #TVAR_afit_pBaseVals[190]															   
    CamWriteCmosSensor(0x0F12, 0x0440); //0440); //// #TVAR_afit_pBaseVals[191]															   
    CamWriteCmosSensor(0x0F12, 0x0302); //0302); //// #TVAR_afit_pBaseVals[192]															   
    CamWriteCmosSensor(0x0F12, 0x2323); ///3232//3232//2323 //#TVAR_afit_pBaseVals[297]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[298]													   
    CamWriteCmosSensor(0x0F12, 0x2A02); ///2001//2001//2A02 //#TVAR_afit_pBaseVals[299]													   
    CamWriteCmosSensor(0x0F12, 0x2C26); ///1E1C//1E1C//2C26 //#TVAR_afit_pBaseVals[300]													   
    CamWriteCmosSensor(0x0F12, 0x282C); ///281C//281C//282C //#TVAR_afit_pBaseVals[301]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[302]													   
    CamWriteCmosSensor(0x0F12, 0x1403); //1403); //// #TVAR_afit_pBaseVals[199]															   
    CamWriteCmosSensor(0x0F12, 0x1E07); //1E07); //// #TVAR_afit_pBaseVals[200]															   
    CamWriteCmosSensor(0x0F12, 0x070A); //070A); //// #TVAR_afit_pBaseVals[201]															   
    CamWriteCmosSensor(0x0F12, 0x32FF); //32FF); //// #TVAR_afit_pBaseVals[202]															   
    CamWriteCmosSensor(0x0F12, 0x5004); //5004); //// #TVAR_afit_pBaseVals[203]															   
    CamWriteCmosSensor(0x0F12, 0x0F40); //0F40); //// #TVAR_afit_pBaseVals[204]															   
    CamWriteCmosSensor(0x0F12, 0x400F); //400F); //// #TVAR_afit_pBaseVals[205]															   
    CamWriteCmosSensor(0x0F12, 0x0204); //0204); //// #TVAR_afit_pBaseVals[206]															   
    CamWriteCmosSensor(0x0F12, 0x0003); //0003); //// #TVAR_afit_pBaseVals[207]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[208]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[209]															   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0019//0019//0019 //#TVAR_afit_pBaseVals[314]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[315]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[316]													   
    CamWriteCmosSensor(0x0F12, 0x00C4); ///001E//001E//00C4 //#TVAR_afit_pBaseVals[317]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[318]													   
    CamWriteCmosSensor(0x0F12, 0x009C); //009C); //// #TVAR_afit_pBaseVals[215]															   
    CamWriteCmosSensor(0x0F12, 0x017C); //017C); //// #TVAR_afit_pBaseVals[216]															   
    CamWriteCmosSensor(0x0F12, 0x03FF); //03FF); //// #TVAR_afit_pBaseVals[217]															   
    CamWriteCmosSensor(0x0F12, 0x000C); //000C); //// #TVAR_afit_pBaseVals[218]															   
    CamWriteCmosSensor(0x0F12, 0x0010); ///0010//0010//0010 //#TVAR_afit_pBaseVals[323]													   
    CamWriteCmosSensor(0x0F12, 0x00C8); ///012C//012C//00C8 //#TVAR_afit_pBaseVals[324]													   
    CamWriteCmosSensor(0x0F12, 0x0384); ///03E8//03E8//0384 //#TVAR_afit_pBaseVals[325]													   
    CamWriteCmosSensor(0x0F12, 0x0046); ///0050//0050//0046 //#TVAR_afit_pBaseVals[326]													   
    CamWriteCmosSensor(0x0F12, 0x0082); ///00C8//00C8//0082 //#TVAR_afit_pBaseVals[327]													   
    CamWriteCmosSensor(0x0F12, 0x0070); ///0070//0070//0070 //#TVAR_afit_pBaseVals[328]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0004//0004//0000 //#TVAR_afit_pBaseVals[329]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0004//0004//0000 //#TVAR_afit_pBaseVals[330]													   
    CamWriteCmosSensor(0x0F12, 0x01AA); ///01AA//01AA//01AA //#TVAR_afit_pBaseVals[331]													   
    CamWriteCmosSensor(0x0F12, 0x001E); ///0014//0014//001E //#TVAR_afit_pBaseVals[332]													   
    CamWriteCmosSensor(0x0F12, 0x001E); ///0014//0014//001E //#TVAR_afit_pBaseVals[333]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[334]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[335]													   
    CamWriteCmosSensor(0x0F12, 0x010E); ///0032//0032//010E //#TVAR_afit_pBaseVals[336]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0023//0023//0028 //#TVAR_afit_pBaseVals[337]													   
    CamWriteCmosSensor(0x0F12, 0x0032); ///0032//0032//0032 //#TVAR_afit_pBaseVals[338]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[339]													   
    CamWriteCmosSensor(0x0F12, 0x0032); ///0032//0032//0032 //#TVAR_afit_pBaseVals[340]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[341]													   
    CamWriteCmosSensor(0x0F12, 0x0A24); ///0A0F//0A0F//0A24 //#TVAR_afit_pBaseVals[342]													   
    CamWriteCmosSensor(0x0F12, 0x1701); ///1701//1701//1701 //#TVAR_afit_pBaseVals[343]													   
    CamWriteCmosSensor(0x0F12, 0x0229); //0229); //// #TVAR_afit_pBaseVals[240]															   
    CamWriteCmosSensor(0x0F12, 0x1403); //1403); //// #TVAR_afit_pBaseVals[241]															   
    CamWriteCmosSensor(0x0F12, 0x0000); //0000); //// #TVAR_afit_pBaseVals[242]															   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[347]													   
    CamWriteCmosSensor(0x0F12, 0x0504); ///0404//0404//0504 //#TVAR_afit_pBaseVals[348]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); ///00FF//00FF//00FF //#TVAR_afit_pBaseVals[349]													   
    CamWriteCmosSensor(0x0F12, 0x043B); ///033B//033B//043B //#TVAR_afit_pBaseVals[350]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///0505//0505//1414 //#TVAR_afit_pBaseVals[351]													   
    CamWriteCmosSensor(0x0F12, 0x0301); ///0301//0301//0301 //#TVAR_afit_pBaseVals[352]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///8007//8007//FF07 //#TVAR_afit_pBaseVals[353]													   
    CamWriteCmosSensor(0x0F12, 0x051E); ///051E//051E//051E //#TVAR_afit_pBaseVals[354]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[355]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///0F0F//0F0F//0F0F //#TVAR_afit_pBaseVals[356]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A03//0A03//0A00 //#TVAR_afit_pBaseVals[357]													   
    CamWriteCmosSensor(0x0F12, 0x0A3C); ///0A46//0A3C//0A3C //#TVAR_afit_pBaseVals[358]													   
    CamWriteCmosSensor(0x0F12, 0x0532); ///0532//0828//0532 //#TVAR_afit_pBaseVals[359]													   
    CamWriteCmosSensor(0x0F12, 0x0002); ///0002//0002//0002 //#TVAR_afit_pBaseVals[360]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); ///00FF//00FF//00FF //#TVAR_afit_pBaseVals[361]													   
    CamWriteCmosSensor(0x0F12, 0x1002); ///1002//1002//1002 //#TVAR_afit_pBaseVals[362]													   
    CamWriteCmosSensor(0x0F12, 0x001E); ///001D//001D//001E //#TVAR_afit_pBaseVals[363]													   
    CamWriteCmosSensor(0x0F12, 0x0900); ///0900//0900//0900 //#TVAR_afit_pBaseVals[364]													   
    CamWriteCmosSensor(0x0F12, 0x0600); ///0600//0600//0600 //#TVAR_afit_pBaseVals[365]													   
    CamWriteCmosSensor(0x0F12, 0x0504); ///0504//0504//0504 //#TVAR_afit_pBaseVals[366]													   
    CamWriteCmosSensor(0x0F12, 0x0305); ///0305//0305//0305 //#TVAR_afit_pBaseVals[367]													   
    CamWriteCmosSensor(0x0F12, 0x4602); ///6F02//6F02//4602 //#TVAR_afit_pBaseVals[368]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[369]													   
    CamWriteCmosSensor(0x0F12, 0x0180); ///0080//0080//0180 //#TVAR_afit_pBaseVals[370]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[371]													   
    CamWriteCmosSensor(0x0F12, 0x2328); ///323C//323C//2328 //#TVAR_afit_pBaseVals[372]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[373]													   
    CamWriteCmosSensor(0x0F12, 0x2A02); ///1A01//1A01//2A02 //#TVAR_afit_pBaseVals[374]													   
    CamWriteCmosSensor(0x0F12, 0x2228); ///141E//1A1E//2228 //#TVAR_afit_pBaseVals[375]													   
    CamWriteCmosSensor(0x0F12, 0x2822); ///2812//2818//2822 //#TVAR_afit_pBaseVals[376]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[377]													   
    CamWriteCmosSensor(0x0F12, 0x1903); ///1403//1403//1903 //#TVAR_afit_pBaseVals[378]													   
    CamWriteCmosSensor(0x0F12, 0x1E0F); ///1905//1905//1E0F //#TVAR_afit_pBaseVals[379]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///060E//060E//070A //#TVAR_afit_pBaseVals[380]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[381]													   
    CamWriteCmosSensor(0x0F12, 0x9604); ///5A04//5004//9604 //#TVAR_afit_pBaseVals[382]													   
    CamWriteCmosSensor(0x0F12, 0x0F42); ///144A//1440//0F42 //#TVAR_afit_pBaseVals[383]													   
    CamWriteCmosSensor(0x0F12, 0x400F); ///4015//4015//400F //#TVAR_afit_pBaseVals[384]													   
    CamWriteCmosSensor(0x0F12, 0x0504); ///0204//0204//0504 //#TVAR_afit_pBaseVals[385]													   
    CamWriteCmosSensor(0x0F12, 0x2805); ///3C03//3C03//2805 //#TVAR_afit_pBaseVals[386]													   
    CamWriteCmosSensor(0x0F12, 0x0123); ///013C//013C//0123 //#TVAR_afit_pBaseVals[387]													   
    CamWriteCmosSensor(0x0F12, 0x0201); ///0101//0101//0201 //#TVAR_afit_pBaseVals[388]													   
    CamWriteCmosSensor(0x0F12, 0x2024); ///141A//141A//2024 //#TVAR_afit_pBaseVals[389]													   
    CamWriteCmosSensor(0x0F12, 0x1C1C); ///181A//181A//1C1C //#TVAR_afit_pBaseVals[390]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[391]													   
    CamWriteCmosSensor(0x0F12, 0x030A); ///030A//030A//030A //#TVAR_afit_pBaseVals[392]													   
    CamWriteCmosSensor(0x0F12, 0x0A0A); ///0614//0614//0A0A //#TVAR_afit_pBaseVals[393]													   
    CamWriteCmosSensor(0x0F12, 0x0A2D); ///0A19//0A19//0A2D //#TVAR_afit_pBaseVals[394]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///FF06//FF06//FF07 //#TVAR_afit_pBaseVals[395]													   
    CamWriteCmosSensor(0x0F12, 0x0432); ///0432//0432//0432 //#TVAR_afit_pBaseVals[396]													   
    CamWriteCmosSensor(0x0F12, 0x4050); ///4050//4050//4050 //#TVAR_afit_pBaseVals[397]													   
    CamWriteCmosSensor(0x0F12, 0x0F0F); ///1514//1514//0F0F //#TVAR_afit_pBaseVals[398]													   
    CamWriteCmosSensor(0x0F12, 0x0440); ///0440//0440//0440 //#TVAR_afit_pBaseVals[399]													   
    CamWriteCmosSensor(0x0F12, 0x0302); ///0302//0302//0302 //#TVAR_afit_pBaseVals[400]													   
    CamWriteCmosSensor(0x0F12, 0x2328); ///3C3C//3C3C//2328 //#TVAR_afit_pBaseVals[401]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[402]													   
    CamWriteCmosSensor(0x0F12, 0x3C02); ///1A01//1A01//3C02 //#TVAR_afit_pBaseVals[403]													   
    CamWriteCmosSensor(0x0F12, 0x1C3C); ///1A14//1A14//1C3C //#TVAR_afit_pBaseVals[404]													   
    CamWriteCmosSensor(0x0F12, 0x281C); ///2818//2818//281C //#TVAR_afit_pBaseVals[405]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[406]													   
    CamWriteCmosSensor(0x0F12, 0x0A03); ///1403//1403//0A03 //#TVAR_afit_pBaseVals[407]													   
    CamWriteCmosSensor(0x0F12, 0x2D0A); ///1906//1906//2D0A //#TVAR_afit_pBaseVals[408]													   
    CamWriteCmosSensor(0x0F12, 0x070A); ///060A//060A//070A //#TVAR_afit_pBaseVals[409]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[410]													   
    CamWriteCmosSensor(0x0F12, 0x5004); ///5004//5004//5004 //#TVAR_afit_pBaseVals[411]													   
    CamWriteCmosSensor(0x0F12, 0x0F40); ///1440//1440//0F40 //#TVAR_afit_pBaseVals[412]													   
    CamWriteCmosSensor(0x0F12, 0x400F); ///4015//4015//400F //#TVAR_afit_pBaseVals[413]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[414]													   
    CamWriteCmosSensor(0x0F12, 0x0003); ///0003//0003//0003 //#TVAR_afit_pBaseVals[415]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[416]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[417]													   
    // CamWriteCmosSensor(0x0F12, 0x0000); ///0019//0019//0019 //#TVAR_afit_pBaseVals[418]	   //yurong
    CamWriteCmosSensor(0x0F12, 0x0005); ///0019//0019//0019 //#TVAR_afit_pBaseVals[418]		

    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[419]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[420]													   
    CamWriteCmosSensor(0x0F12, 0x00C4); ///001E//001E//00C4 //#TVAR_afit_pBaseVals[421]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[422]													   
    CamWriteCmosSensor(0x0F12, 0x009C); ///009C//009C//009C //#TVAR_afit_pBaseVals[423]													   
    CamWriteCmosSensor(0x0F12, 0x017C); ///017C//017C//017C //#TVAR_afit_pBaseVals[424]													   
    CamWriteCmosSensor(0x0F12, 0x03FF); ///03FF//03FF//03FF //#TVAR_afit_pBaseVals[425]													   
    CamWriteCmosSensor(0x0F12, 0x000C); ///000C//000C//000C //#TVAR_afit_pBaseVals[426]													   
    CamWriteCmosSensor(0x0F12, 0x0010); ///0010//0010//0010 //#TVAR_afit_pBaseVals[427]													   
    CamWriteCmosSensor(0x0F12, 0x00C8); ///0000//0000//00C8 //#TVAR_afit_pBaseVals[428]													   
    CamWriteCmosSensor(0x0F12, 0x0320); ///0000//0000//0320 //#TVAR_afit_pBaseVals[429]													   
    CamWriteCmosSensor(0x0F12, 0x0046); ///0046//0046//0046 //#TVAR_afit_pBaseVals[430]													   
    CamWriteCmosSensor(0x0F12, 0x015E); ///0050//0050//015E //#TVAR_afit_pBaseVals[431]													   
    CamWriteCmosSensor(0x0F12, 0x0070); ///0070//0070//0070 //#TVAR_afit_pBaseVals[432]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0004//0004//0000 //#TVAR_afit_pBaseVals[433]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0004//0004//0000 //#TVAR_afit_pBaseVals[434]													   
    CamWriteCmosSensor(0x0F12, 0x01AA); ///01AA//01AA//01AA //#TVAR_afit_pBaseVals[435]													   
    CamWriteCmosSensor(0x0F12, 0x0014); ///0014//0014//0014 //#TVAR_afit_pBaseVals[436]													   
    CamWriteCmosSensor(0x0F12, 0x0014); ///0014//0014//0014 //#TVAR_afit_pBaseVals[437]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[438]													   
    CamWriteCmosSensor(0x0F12, 0x000A); ///000A//000A//000A //#TVAR_afit_pBaseVals[439]													   
    CamWriteCmosSensor(0x0F12, 0x0140); ///002D//002D//0140 //#TVAR_afit_pBaseVals[440]													   
    CamWriteCmosSensor(0x0F12, 0x003C); ///0019//0019//003C //#TVAR_afit_pBaseVals[441]													   
    CamWriteCmosSensor(0x0F12, 0x0032); ///0023//0023//0032 //#TVAR_afit_pBaseVals[442]													   
    CamWriteCmosSensor(0x0F12, 0x0023); ///0023//0023//0023 //#TVAR_afit_pBaseVals[443]													   
    CamWriteCmosSensor(0x0F12, 0x0023); ///0023//0023//0023 //#TVAR_afit_pBaseVals[444]													   
    CamWriteCmosSensor(0x0F12, 0x0032); ///0023//0023//0032 //#TVAR_afit_pBaseVals[445]													   
    CamWriteCmosSensor(0x0F12, 0x0A24); ///0A0F//0A0F//0A24 //#TVAR_afit_pBaseVals[446]													   
    CamWriteCmosSensor(0x0F12, 0x1701); ///1701//1701//1701 //#TVAR_afit_pBaseVals[447]													   
    CamWriteCmosSensor(0x0F12, 0x0229); ///0229//0229//0229 //#TVAR_afit_pBaseVals[448]													   
    CamWriteCmosSensor(0x0F12, 0x1403); ///1403//1403//1403 //#TVAR_afit_pBaseVals[449]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[450]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[451]													   
    CamWriteCmosSensor(0x0F12, 0x0505); ///0606//0606//0505 //#TVAR_afit_pBaseVals[452]													   
    CamWriteCmosSensor(0x0F12, 0x00FF); ///00FF//00FF//00FF //#TVAR_afit_pBaseVals[453]													   
    CamWriteCmosSensor(0x0F12, 0x043B); ///033B//033B//043B //#TVAR_afit_pBaseVals[454]													   
    CamWriteCmosSensor(0x0F12, 0x1414); ///0505//0505//1414 //#TVAR_afit_pBaseVals[455]													   
    CamWriteCmosSensor(0x0F12, 0x0301); ///0301//0301//0301 //#TVAR_afit_pBaseVals[456]													   
    CamWriteCmosSensor(0x0F12, 0xFF07); ///8007//8007//FF07 //#TVAR_afit_pBaseVals[457]													   
    CamWriteCmosSensor(0x0F12, 0x051E); ///051E//051E//051E //#TVAR_afit_pBaseVals[458]													   
    CamWriteCmosSensor(0x0F12, 0x0A1E); ///0A1E//0A1E//0A1E //#TVAR_afit_pBaseVals[459]													   
    CamWriteCmosSensor(0x0F12, 0x0000); ///0000//0000//0000 //#TVAR_afit_pBaseVals[460]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A03//0A03//0A00 //#TVAR_afit_pBaseVals[461]													   
    CamWriteCmosSensor(0x0F12, 0x143C); ///0A46//1E3C//143C //#TVAR_afit_pBaseVals[462]													   
    CamWriteCmosSensor(0x0F12, 0x0532); ///0532//1028//0532 //#TVAR_afit_pBaseVals[463]													   
    CamWriteCmosSensor(0x0F12, 0x0002); ///0002//0002//0002 //#TVAR_afit_pBaseVals[464]													   
    CamWriteCmosSensor(0x0F12, 0x0096); ///00FF//00FF//0096 //#TVAR_afit_pBaseVals[465]													   
    CamWriteCmosSensor(0x0F12, 0x1002); ///1002//1002//1002 //#TVAR_afit_pBaseVals[466]													   
    CamWriteCmosSensor(0x0F12, 0x001E); ///001E//001E//001E //#TVAR_afit_pBaseVals[467]													   
    CamWriteCmosSensor(0x0F12, 0x0900); ///0900//0900//0900 //#TVAR_afit_pBaseVals[468]													   
    CamWriteCmosSensor(0x0F12, 0x0600); ///0600//0600//0600 //#TVAR_afit_pBaseVals[469]													   
    CamWriteCmosSensor(0x0F12, 0x0504); ///0504//0504//0504 //#TVAR_afit_pBaseVals[470]													   
    CamWriteCmosSensor(0x0F12, 0x0305); ///0305//0305//0305 //#TVAR_afit_pBaseVals[471]													   
    CamWriteCmosSensor(0x0F12, 0x6402); ///8002//8002//6402 //#TVAR_afit_pBaseVals[472]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[473]													   
    CamWriteCmosSensor(0x0F12, 0x0180); ///0080//0080//0180 //#TVAR_afit_pBaseVals[474]													   
    CamWriteCmosSensor(0x0F12, 0x0080); ///0080//0080//0080 //#TVAR_afit_pBaseVals[475]													   
    CamWriteCmosSensor(0x0F12, 0x5050); ///4646//4646//5050 //#TVAR_afit_pBaseVals[476]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[477]													   
    CamWriteCmosSensor(0x0F12, 0x1C02); ///1801//1801//1C02 //#TVAR_afit_pBaseVals[478]													   
    CamWriteCmosSensor(0x0F12, 0x191C); ///101C//141C//191C //#TVAR_afit_pBaseVals[479]													   
    CamWriteCmosSensor(0x0F12, 0x2819); ///2810//2812//2819 //#TVAR_afit_pBaseVals[480]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[481]													   
    CamWriteCmosSensor(0x0F12, 0x1E03); ///1003//1003//1E03 //#TVAR_afit_pBaseVals[482]													   
    CamWriteCmosSensor(0x0F12, 0x1E0F); ///1405//1405//1E0F //#TVAR_afit_pBaseVals[483]													   
    CamWriteCmosSensor(0x0F12, 0x0508); ///050C//050C//0508 //#TVAR_afit_pBaseVals[484]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[485]													   
    CamWriteCmosSensor(0x0F12, 0xAA04); ///5C04//5204//AA04 //#TVAR_afit_pBaseVals[486]													   
    CamWriteCmosSensor(0x0F12, 0x1452); ///144A//1440//1452 //#TVAR_afit_pBaseVals[487]													   
    CamWriteCmosSensor(0x0F12, 0x4015); ///4015//4015//4015 //#TVAR_afit_pBaseVals[488]													   
    CamWriteCmosSensor(0x0F12, 0x0604); ///0204//0204//0604 //#TVAR_afit_pBaseVals[489]													   
    CamWriteCmosSensor(0x0F12, 0x5006); ///5003//5003//5006 //#TVAR_afit_pBaseVals[490]													   
    CamWriteCmosSensor(0x0F12, 0x0150); ///0150//0150//0150 //#TVAR_afit_pBaseVals[491]													   
    CamWriteCmosSensor(0x0F12, 0x0201); ///0101//0101//0201 //#TVAR_afit_pBaseVals[492]													   
    CamWriteCmosSensor(0x0F12, 0x1E1E); ///1418//1418//1E1E //#TVAR_afit_pBaseVals[493]													   
    CamWriteCmosSensor(0x0F12, 0x1212); ///1214//1214//1212 //#TVAR_afit_pBaseVals[494]													   
    CamWriteCmosSensor(0x0F12, 0x0028); ///0028//0028//0028 //#TVAR_afit_pBaseVals[495]													   
    CamWriteCmosSensor(0x0F12, 0x030A); ///030A//030A//030A //#TVAR_afit_pBaseVals[496]													   
    CamWriteCmosSensor(0x0F12, 0x0A10); ///0A10//0A10//0A10 //#TVAR_afit_pBaseVals[497]													   
    CamWriteCmosSensor(0x0F12, 0x0819); ///0819//0819//0819 //#TVAR_afit_pBaseVals[498]													   
    CamWriteCmosSensor(0x0F12, 0xFF05); ///FF05//FF05//FF05 //#TVAR_afit_pBaseVals[499]													   
    CamWriteCmosSensor(0x0F12, 0x0432); ///0432//0432//0432 //#TVAR_afit_pBaseVals[500]													   
    CamWriteCmosSensor(0x0F12, 0x4052); ///4052//4052//4052 //#TVAR_afit_pBaseVals[501]													   
    CamWriteCmosSensor(0x0F12, 0x1514); ///1514//1514//1514 //#TVAR_afit_pBaseVals[502]													   
    CamWriteCmosSensor(0x0F12, 0x0440); ///0440//0440//0440 //#TVAR_afit_pBaseVals[503]													   
    CamWriteCmosSensor(0x0F12, 0x0302); ///0302//0302//0302 //#TVAR_afit_pBaseVals[504]													   
    CamWriteCmosSensor(0x0F12, 0x5050); ///5050//5050//5050 //#TVAR_afit_pBaseVals[505]													   
    CamWriteCmosSensor(0x0F12, 0x0101); ///0101//0101//0101 //#TVAR_afit_pBaseVals[506]													   
    CamWriteCmosSensor(0x0F12, 0x1E02); ///1801//1801//1E02 //#TVAR_afit_pBaseVals[507]													   
    CamWriteCmosSensor(0x0F12, 0x121E); ///1414//1414//121E //#TVAR_afit_pBaseVals[508]													   
    CamWriteCmosSensor(0x0F12, 0x2812); ///2812//2812//2812 //#TVAR_afit_pBaseVals[509]													   
    CamWriteCmosSensor(0x0F12, 0x0A00); ///0A00//0A00//0A00 //#TVAR_afit_pBaseVals[510]													   
    CamWriteCmosSensor(0x0F12, 0x1003); ///1003//1003//1003 //#TVAR_afit_pBaseVals[511]													   
    CamWriteCmosSensor(0x0F12, 0x190A); ///190A//190A//190A //#TVAR_afit_pBaseVals[512]													   
    CamWriteCmosSensor(0x0F12, 0x0508); ///0508//0508//0508 //#TVAR_afit_pBaseVals[513]													   
    CamWriteCmosSensor(0x0F12, 0x32FF); ///32FF//32FF//32FF //#TVAR_afit_pBaseVals[514]													   
    CamWriteCmosSensor(0x0F12, 0x5204); ///5204//5204//5204 //#TVAR_afit_pBaseVals[515]													   
    CamWriteCmosSensor(0x0F12, 0x1440); ///1440//1440//1440 //#TVAR_afit_pBaseVals[516]													   
    CamWriteCmosSensor(0x0F12, 0x4015); ///4015//4015//4015 //#TVAR_afit_pBaseVals[517]													   
    CamWriteCmosSensor(0x0F12, 0x0204); ///0204//0204//0204 //#TVAR_afit_pBaseVals[518]													   
    CamWriteCmosSensor(0x0F12, 0x0003); ///0003//0003//0003 //#TVAR_afit_pBaseVals[519]													   
    // AFIT table (Constants)	 ); //																																		
    CamWriteCmosSensor(0x0F12, 0x7F7A); ////#afit_pConstBaseVals[0]																			  
    CamWriteCmosSensor(0x0F12, 0x7FBD); ////#afit_pConstBaseVals[1]																			  
    CamWriteCmosSensor(0x0F12, 0xBEFC); ////#afit_pConstBaseVals[2]																			  
    CamWriteCmosSensor(0x0F12, 0xF7BC); ////#afit_pConstBaseVals[3]																			  
    CamWriteCmosSensor(0x0F12, 0x7E06); ////#afit_pConstBaseVals[4]																			  
    CamWriteCmosSensor(0x0F12, 0x0053); ////#afit_pConstBaseVals[5]																			  
    // Update Changed Registers //																																			
    CamWriteCmosSensor(0x002A, 0x0664); //																															
    CamWriteCmosSensor(0x0F12, 0x013E); ////seti_uContrastCenter 																				
    // Fill RAM with alternative op-codes																																
    // Update T&P tuning parameters																																			
    CamWriteCmosSensor(0x002A, 0x04D6);																																	
    CamWriteCmosSensor(0x0F12, 0x0001);																																	
    CamWriteCmosSensor(0x0028, 0xD000);																																	
    CamWriteCmosSensor(0x002A, 0x1102);																																	
    CamWriteCmosSensor(0x0F12, 0x00C0);																																	
    CamWriteCmosSensor(0x002A, 0x113C);																																	
    CamWriteCmosSensor(0x0F12, 0x267C);																																	
    CamWriteCmosSensor(0x0F12, 0x2680);																																	
    CamWriteCmosSensor(0x002A, 0x1142);																																	
    CamWriteCmosSensor(0x0F12, 0x00C0);																																	
    CamWriteCmosSensor(0x002A, 0x117C);																																	
    CamWriteCmosSensor(0x0F12, 0x2CE8);																																	
    CamWriteCmosSensor(0x0F12, 0x2CEC);																																	
    CamWriteCmosSensor(0x0028, 0x7000);																																	
    CamWriteCmosSensor(0x002A, 0x2CE8);																																	
    CamWriteCmosSensor(0x0F12, 0x0007);																																	
    CamWriteCmosSensor(0x0F12, 0x00e2);																																	
    CamWriteCmosSensor(0x0F12, 0x0005);																																	
    CamWriteCmosSensor(0x0F12, 0x00e2);																																	
    CamWriteCmosSensor(0x002A, 0x337A);																																	
    CamWriteCmosSensor(0x0F12, 0x0006);																																	
    //================================ ================================================================											   
    //#SET PLL	 下面开始是时钟的设置do not modify) 																										
    //================================ ================================================================											   
    //#How to set																																												
    //#1. MCLK																																													
    //hex(CLK you want) * 1000)																																					
    ////#2. System CLK																																									
    //hex((CLK you want) * 1000 / 4) 																																		
    ////#3. PCLK 																																												
    //hex((CLK you want) * 1000 / 4) 																																		
    //  Config the PLL																																									
    //																																																	
    // Input clock (24Mhz), [0x700001C C] 0x5DC0 --> 24000KHz																						  
    // System clock (40MHz),  [0x70000 1F6] 0x2710 * 4 --> 24000KHz																				   
    // Output clock (48MHz),  [0x70000 1F8 ~ 1FA] (0x2ED3 ~ 0x2EEC) * 4 --> 47948KHz ~ 48048KHz													   
    //================================================================																			   
    // Ex. 24Mhz master clock, S5K5CAGAGX_master_clk_freq == 240.																					   
    CamWriteCmosSensor(0x002A, 0x01CC); // Set input CLK // 24MHz																				
    CamWriteCmosSensor(0x0F12, 0x5DC0); // #REG_TC_IPRM_InClockLSBs // 24Mhz 																										   
    CamWriteCmosSensor(0x0F12, 0x0000); // #REG_TC_IPRM_InClockMSBs																													   
    CamWriteCmosSensor(0x002A, 0x01EE);																																										
    CamWriteCmosSensor(0x0F12, 0x0003); //0x0001); //#REG_TC_IPRM_UseNPviClocks //#Number of PLL setting  为了变焦的clock															   
    CamWriteCmosSensor(0x002A, 0x01F6); // Set system CLK																							
    																																																	
    /* Clock0, System clock 58MHz, PVI clock 48Mhz, (previewPreview) */ 																		   
    //  CamWriteCmosSensor(0x0F12, 0x2710); // #REG_TC_IPRM_OpClk4KHz_0	1st 58MHz for 30fps preview 	
    CamWriteCmosSensor(0x0F12, 0x36b0); 
    																																																	
    // Enlarge the pclk range for 26Mhz master clock input.																						
    CamWriteCmosSensor(0x0F12, 0x2E63); //0x2EB0); // #REG_TC_IPRM_MinOutRate4KHz_0	PVI clock 48MHz 							   
    CamWriteCmosSensor(0x0F12, 0x2F5D); //0x2EE0); // #REG_TC_IPRM_MaxOutRate4KHz_0												   
    																																																	
    /* Clock1, System clock 58MHz, PVI clock 40Mhz, (Capture, Backup) */ 																   
    CamWriteCmosSensor(0x0F12, 0x2904); // #REG_TC_IPRM_OpClk4KHz_1	2nd 58MHz for 30fps preview 								   
    CamWriteCmosSensor(0x0F12, 0x157C); // #REG_TC_IPRM_MinOutRate4KHz_1  PVI clock 40MHz										   
    CamWriteCmosSensor(0x0F12, 0x157C); // #REG_TC_IPRM_MaxOutRate4KHz_1 															  
    																																																	
    /* Clock2, System clock 58MHz, PVI clock 36Mhz, (Capture, Default) */																   
    //CamWriteCmosSensor(0x0F12, 0x36B0); // #REG_TC_IPRM_OpClk4KHz_2	3thd 58MHz for 30fps preview								   
    //CamWriteCmosSensor(0x0F12, 0x3A98); //2EE0  // #REG_TC_IPRM_MinOutRate4KHz_0 												   
    //CamWriteCmosSensor(0x0F12, 0x3A98); //2EE0  // #REG_TC_IPRM_MaxOutRate4KHz_0 												   
#ifdef S5K5CAGA_YUV_CAP_PCLK_60Mhz_8fps
    CamWriteCmosSensor(0x0F12, 0x36B0); // #REG_TC_IPRM_OpClk4KHz_2  3thd 58MHz for 30fps preview                                        
    CamWriteCmosSensor(0x0F12, 0x3A98); //2EE0  // #REG_TC_IPRM_MinOutRate4KHz_0                                                         
    CamWriteCmosSensor(0x0F12, 0x3A98); //2EE0  // #REG_TC_IPRM_MaxOutRate4KHz_0                                                         
#elif  (defined(S5K5CAGA_YUV_CAP_PCLK_86Mhz_12fps))
    CamWriteCmosSensor(0x0F12, 0x38A4); // #REG_TC_IPRM_OpClk4KHz_2  3thd 58MHz for 30fps preview                                        
    CamWriteCmosSensor(0x0F12, 0x53fc); //2EE0  // #REG_TC_IPRM_MinOutRate4KHz_0                                                         
    CamWriteCmosSensor(0x0F12, 0x53fc); //2EE0  // #REG_TC_IPRM_MaxOutRate4KHz_0                                                         
#elif  (defined(S5K5CAGA_YUV_CAP_PCLK_96Mhz_14fps))
    CamWriteCmosSensor(0x0F12, 0x3A98); // #REG_TC_IPRM_OpClk4KHz_2  3thd 58MHz for 30fps preview                                        
    CamWriteCmosSensor(0x0F12, 0x6784); //2EE0  // #REG_TC_IPRM_MinOutRate4KHz_0                                                         
    CamWriteCmosSensor(0x0F12, 0x6784); 
#endif

    CamWriteCmosSensor(0x002A, 0x0208);																																
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_IPRM_InitParamsUpdated															  
    																																																	
    //================================================================================================									   
    // SET PREVIEW CONFIGURATION_0																																		
    // # Foramt : YUV422 																																							
    // # Size: 800*600																																								
    // # FPS : 10~20fps for normal mode																																
    //================================================================================================									   
    CamWriteCmosSensor(0x002A, 0x026C);																																
    //CamWriteCmosSensor(0x0F12, 0x0320+10);  //0400 //#REG_0TC_PCFG_usWidth//1024 												   
    //CamWriteCmosSensor(0x0F12, 0x0258+8);   //0300 //#REG_0TC_PCFG_usHeight //768	026E	
    CamWriteCmosSensor(0x0F12, 0x0320);  //0400 //#REG_0TC_PCFG_usWidth//1024 												   
    CamWriteCmosSensor(0x0F12, 0x0258);   //0300 //#REG_0TC_PCFG_usHeight //768	026E	

    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_0TC_PCFG_Format		   0270 														  
    CamWriteCmosSensor(0x0F12, 0x2F5D);	//2EE0	//157C //3AA8 //#REG_0TC_PCFG_usMaxOut4KHzRate	0272							   
    CamWriteCmosSensor(0x0F12, 0x2E63);	//2EE0	//157C //3A88 //#REG_0TC_PCFG_usMinOut4KHzRate	0274							   
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_0TC_PCFG_OutClkPerPix88	  0276													   
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_0TC_PCFG_uMaxBpp88		  027															
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_0TC_PCFG_PVIMask //s0050 = FALSE in MSM6290 : s0052 = TRUE in MSM6800 //reg 027A
    CamWriteCmosSensor(0x0F12, 0x4000);	//#REG_0TC_PCFG_OIFMask 																						
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_0TC_PCFG_usJpegPacketSize 																   
    CamWriteCmosSensor(0x0F12, 0x0320);	//0000 //#REG_0TC_PCFG_usJpegTotalPackets																   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_uClockInd																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_usFrTimeType																				  
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_0TC_PCFG_FrRateQualityType																	   
    CamWriteCmosSensor(0x0F12, 0x03E8);	//03E8 //#REG_0TC_PCFG_usMaxFrTimeMsecMult10 //10fps													   
    CamWriteCmosSensor(0x0F12, 0x014D);	//01C6 //#REG_0TC_PCFG_usMinFrTimeMsecMult10 //15fps													   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_bSmearOutput																				  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_sSaturation 																				  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_sSharpBlur																					  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_sColorTemp																					  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_uDeviceGammaIndex																		   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_uPrevMirror 																				  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_uCaptureMirror																			   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_PCFG_uRotation																						
    																																																				
    ////================================================================================================ 												   
    //// SET PREVIEW CONFIGURATION_1 																																				
    //// # Foramt : YUV422																																									
    //// # Size: 800*600 																																										
    //// # FPS : 5~20fps for night mode																																			
    ////================================================================================================ 												   
    CamWriteCmosSensor(0x002A, 0x029C);																																			
    //CamWriteCmosSensor(0x0F12, 0x0320+10);  //0400 //#REG_1TC_PCFG_usWidth//1024 																   
    //CamWriteCmosSensor(0x0F12, 0x0258+8);   //0300 //#REG_1TC_PCFG_usHeight //768	026E														   

    CamWriteCmosSensor(0x0F12, 0x0320);  //0400 //#REG_1TC_PCFG_usWidth//1024 																   
    CamWriteCmosSensor(0x0F12, 0x0258);   //0300 //#REG_1TC_PCFG_usHeight //768	026E												

    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_1TC_PCFG_Format		   0270 																	   
    CamWriteCmosSensor(0x0F12, 0x2F5D);	//157C //3AA8 //#REG_1TC_PCFG_usMaxOut4KHzRate	0272													   
    CamWriteCmosSensor(0x0F12, 0x2E63);	//157C //3A88 //#REG_1TC_PCFG_usMinOut4KHzRate	0274													   
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_1TC_PCFG_OutClkPerPix88	  0276																	   
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_1TC_PCFG_uMaxBpp88		  027																		  
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_1TC_PCFG_PVIMask //s0050 = FALSE in MSM6290 : s0052 = TRUE in MSM6800 //reg 027A
    CamWriteCmosSensor(0x0F12, 0x4000);	//#REG_1TC_PCFG_OIFMask 																					
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_1TC_PCFG_usJpegPacketSize 														   
    CamWriteCmosSensor(0x0F12, 0x0320);	//0000 //#REG_1TC_PCFG_usJpegTotalPackets														   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_uClockInd																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_usFrTimeType																			
    CamWriteCmosSensor(0x0F12, 0x0001); ///#REG_1TC_PCFG_FrRateQualityType																  
    CamWriteCmosSensor(0x0F12, 0x07D0);	//0535 //03E8 //#REG_1TC_PCFG_usMaxFrTimeMsecMult10 //5fps										   
    CamWriteCmosSensor(0x0F12, 0x014D);	//01C6 //#REG_1TC_PCFG_usMinFrTimeMsecMult10 //22fps											   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_bSmearOutput																			
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_sSaturation 																			
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_sSharpBlur																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_sColorTemp																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_uDeviceGammaIndex																	  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_uPrevMirror 																			
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_uCaptureMirror																		  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_PCFG_uRotation																					
    																																																			
    ////================================================================================================ 										   
    //// SET PREVIEW CONFIGURATION_2 																																			
    //// # Foramt : YUV422																																								
    //// # Size: 800*600 																																									
    //// # FPS : fixed 26fps 																																							
    ////================================================================================================ 										   
    CamWriteCmosSensor(0x002A, 0x02CC);																																		
    CamWriteCmosSensor(0x0F12, 0x0320);  //0400 //#REG_2TC_PCFG_usWidth//1024 														   
    CamWriteCmosSensor(0x0F12, 0x0258);   //0300 //#REG_2TC_PCFG_usHeight //768	026E												   
    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_2TC_PCFG_Format		   0270 																  
    CamWriteCmosSensor(0x0F12, 0x2F5D);	//157C //3AA8 //#REG_2TC_PCFG_usMaxOut4KHzRate	0272											   
    CamWriteCmosSensor(0x0F12, 0x2E63);	//157C //3A88 //#REG_2TC_PCFG_usMinOut4KHzRate	0274											   
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_2TC_PCFG_OutClkPerPix88	  0276															   
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_2TC_PCFG_uMaxBpp88		  027																	
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_2TC_PCFG_PVIMask //s0050 = FALSE in MSM6290 : s0052 = TRUE in MSM6800 //reg 027A
    CamWriteCmosSensor(0x0F12, 0x4000);	//#REG_2TC_PCFG_OIFMask 																				
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_2TC_PCFG_usJpegPacketSize 													   
    CamWriteCmosSensor(0x0F12, 0x0320);	//0000 //#REG_2TC_PCFG_usJpegTotalPackets													   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uClockInd																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_usFrTimeType																		
    CamWriteCmosSensor(0x0F12, 0x0001); //#REG_2TC_PCFG_FrRateQualityType																
    //  CamWriteCmosSensor(0x0F12, 0x014d);	//0535 //03E8 //#REG_2TC_PCFG_usMaxFrTimeMsecMult10 //5fps									   
    // CamWriteCmosSensor(0x0F12, 0x014d);	//01C6 //#REG_2TC_PCFG_usMinFrTimeMsecMult10 //22fps										   
    CamWriteCmosSensor(0x0F12, 0x01f4);	//0535 //03E8 //#REG_2TC_PCFG_usMaxFrTimeMsecMult10 //5fps									   
    CamWriteCmosSensor(0x0F12, 0x01f4);	//01C6 //#REG_2TC_PCFG_usMinFrTimeMsecMult10 //22fps						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_bSmearOutput																		
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sSaturation 																		
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sSharpBlur																			
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sColorTemp																			
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uDeviceGammaIndex																  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uPrevMirror 																		
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uCaptureMirror																	  
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uRotation																				
    //sandy modify start 																																								
    ////================================================================================================									   
    //// SET PREVIEW CONFIGURATION_3 																																		
    //// # Foramt : YUV422																																							
    //// # Size: 800*600 																																								
    //// # FPS : fixed 26fps 																																						
    ////================================================================================================									   
    CamWriteCmosSensor(0x002A, 0x02FC);																																	
    CamWriteCmosSensor(0x0F12, 0x0320);  //0400 //#REG_2TC_PCFG_usWidth//1024 													   
    CamWriteCmosSensor(0x0F12, 0x0258);   //0300 //#REG_2TC_PCFG_usHeight //768	026E											   
    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_2TC_PCFG_Format		   0270 															  
    CamWriteCmosSensor(0x0F12, 0x2F5D);	//157C //3AA8 //#REG_2TC_PCFG_usMaxOut4KHzRate	0272										   
    CamWriteCmosSensor(0x0F12, 0x2E63);	//157C //3A88 //#REG_2TC_PCFG_usMinOut4KHzRate	0274										   
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_2TC_PCFG_OutClkPerPix88	  0276														   
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_2TC_PCFG_uMaxBpp88		  027																
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_2TC_PCFG_PVIMask //s0050 = FALSE in MSM6290 : s0052 = TRUE in MSM6800 //reg 027A
    CamWriteCmosSensor(0x0F12, 0x4000);	//#REG_2TC_PCFG_OIFMask 																																																																																																																																																																																																																											   
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_2TC_PCFG_usJpegPacketSize 																																																																																																																																																																																																																							   
    CamWriteCmosSensor(0x0F12, 0x0320);	//0000 //#REG_2TC_PCFG_usJpegTotalPackets																																																																																																																																																																																																																							   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uClockInd																																																																																																																																																																																																																											   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_usFrTimeType																																																																																																																																																																																																																										   
    CamWriteCmosSensor(0x0F12, 0x0001); //#REG_2TC_PCFG_FrRateQualityType																																																																																																																																																																																																																								   
    CamWriteCmosSensor(0x0F12, 0x029A);	//0535 //03E8 //#REG_2TC_PCFG_usMaxFrTimeMsecMult10 //5fps																																																																																																																																																																																																																			   
    CamWriteCmosSensor(0x0F12, 0x029A);	//01C6 //#REG_2TC_PCFG_usMinFrTimeMsecMult10 //22fps																																																																																																																																																																																																																				   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_bSmearOutput																																																																																																																																																																																																																										   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sSaturation 																																																																																																																																																																																																																										   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sSharpBlur																																																																																																																																																																																																																											   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_sColorTemp																																																																																																																																																																																																																											   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uDeviceGammaIndex																																																																																																																																																																																																																									   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uPrevMirror 																																																																																																																																																																																																																										   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uCaptureMirror																																																																																																																																																																																																																										   
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_2TC_PCFG_uRotation																																																																																																																																																																																																																											   
    //sandy modify end																																																																																																																																																																																																																																								   
    //================================================================================================				
    // APPLY PREVIEW CONFIGURATION & RUN PREVIEW 																															
    //================================================================================================				
    CamWriteCmosSensor(0x002A, 0x023C);																																				
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x0000);	// #REG_TC_GP_ActivePrevConfig // Select preview configuration_0			
    //sandy modify end																																												
    CamWriteCmosSensor(0x002A, 0x0240);																																				
    CamWriteCmosSensor(0x0F12, 0x0002);	// #REG_TC_GP_PrevOpenAfterChange																			
    CamWriteCmosSensor(0x002A, 0x0230);																																				
    CamWriteCmosSensor(0x0F12, 0x0001);	// #REG_TC_GP_NewConfigSync // Update preview configuration 					
    CamWriteCmosSensor(0x002A, 0x023E);																																				
    CamWriteCmosSensor(0x0F12, 0x0001);	// #REG_TC_GP_PrevConfigChanged 																			
    CamWriteCmosSensor(0x002A, 0x0220);																																				
    CamWriteCmosSensor(0x0F12, 0x0001);	// #REG_TC_GP_EnablePreview // Start preview													
    CamWriteCmosSensor(0x0F12, 0x0001);	// #REG_TC_GP_EnablePreviewChanged																		
    																																																					
    //================================================================================================				
    // SET CAPTURE CONFIGURATION_0																																						
    // # Foramt :YUV 																																													
    // # FPS : 10-7fps																																												
    //================================================================================================				
    CamWriteCmosSensor(0x002A, 0x035C);																																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_uCaptureModeJpEG																			
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x0800);	//0800 //#REG_0TC_CCFG_usWidth																				
    CamWriteCmosSensor(0x0F12, 0x0600);	//0600 //#REG_0TC_CCFG_usHeight 																			
    //sandy modify end	

#ifdef   S5K5CAGA_YUV_CAP_PCLK_60Mhz_8fps  
    CamWriteCmosSensor(0x0F12, 0x0005);  //#REG_0TC_CCFG_Format//5:YUV9:JPEG                                               
    CamWriteCmosSensor(0x0F12, 0x3A98);  //2EE0  //157C //3AA8 //#REG_0TC_CCFG_usMaxOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x3A98);  //2EE0  //157C //3A88 //#REG_0TC_CCFG_usMinOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x0100);  //#REG_0TC_CCFG_OutClkPerPix88                                                    
    CamWriteCmosSensor(0x0F12, 0x0800);  //#REG_0TC_CCFG_uMaxBpp88                                                         
    CamWriteCmosSensor(0x0F12, 0x0052);  //0052 //#REG_0TC_CCFG_PVIMask                                                    
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_CCFG_OIFMask                                                           
    CamWriteCmosSensor(0x0F12, 0x03C0);  //01E0 //#REG_0TC_CCFG_usJpegPacketSize                                           
    CamWriteCmosSensor(0x0F12, 0x0320);  //08fc //#REG_0TC_CCFG_usJpegTotalPackets                                         
    CamWriteCmosSensor(0x0F12, 0x0002);  //#REG_0TC_CCFG_uClockInd                                                         
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_CCFG_usFrTimeType                                                      
    CamWriteCmosSensor(0x0F12, 0x0002);  //#REG_0TC_CCFG_FrRateQualityType                                             
    //sandy modify start
    CamWriteCmosSensor(0x0F12, 0x04E2);  //029A //0535 //#REG_0TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps                      
    CamWriteCmosSensor(0x0F12, 0x03E8);  //#REG_0TC_CCFG_usMinFrTimeMsecMult10 //10fps                                     
    //sandy modify end    
#elif  (defined(S5K5CAGA_YUV_CAP_PCLK_86Mhz_12fps))
    CamWriteCmosSensor(0x0F12, 0x0005);  //#REG_0TC_CCFG_Format//5:YUV9:JPEG                                               
    CamWriteCmosSensor(0x0F12, 0x53FC);  //2EE0  //157C //3AA8 //#REG_0TC_CCFG_usMaxOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x53FC);  //2EE0  //157C //3A88 //#REG_0TC_CCFG_usMinOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x0100);  //#REG_0TC_CCFG_OutClkPerPix88                                                    
    CamWriteCmosSensor(0x0F12, 0x0800);  //#REG_0TC_CCFG_uMaxBpp88                                                         
    CamWriteCmosSensor(0x0F12, 0x0052);  //0052 //#REG_0TC_CCFG_PVIMask                                                    
    CamWriteCmosSensor(0x0F12, 0x0010);  //#REG_0TC_CCFG_OIFMask                                                           
    CamWriteCmosSensor(0x0F12, 0x01E0);  //01E0 //#REG_0TC_CCFG_usJpegPacketSize                                           
    CamWriteCmosSensor(0x0F12, 0x0500);  //08fc //#REG_0TC_CCFG_usJpegTotalPackets                                         
    CamWriteCmosSensor(0x0F12, 0x0002);  //#REG_0TC_CCFG_uClockInd                                                         
    CamWriteCmosSensor(0x0F12, 0x0001);  //#REG_0TC_CCFG_usFrTimeType                                                      
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_CCFG_FrRateQualityType                                             
    //sandy modify start
    CamWriteCmosSensor(0x0F12, 0x0341);  //029A //0535 //#REG_0TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps                      
    CamWriteCmosSensor(0x0F12, 0x0341);  //#REG_0TC_CCFG_usMinFrTimeMsecMult10 //10fps                                     
    //sandy modify end  
#elif  (defined(S5K5CAGA_YUV_CAP_PCLK_96Mhz_14fps))
    CamWriteCmosSensor(0x0F12, 0x0005);  //#REG_0TC_CCFG_Format//5:YUV9:JPEG                                               
    CamWriteCmosSensor(0x0F12, 0x6784);  //2EE0  //157C //3AA8 //#REG_0TC_CCFG_usMaxOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x6784);  //2EE0  //157C //3A88 //#REG_0TC_CCFG_usMinOut4KHzRate                            
    CamWriteCmosSensor(0x0F12, 0x0100);  //#REG_0TC_CCFG_OutClkPerPix88                                                    
    CamWriteCmosSensor(0x0F12, 0x0800);  //#REG_0TC_CCFG_uMaxBpp88                                                         
    CamWriteCmosSensor(0x0F12, 0x0052);  //0052 //#REG_0TC_CCFG_PVIMask                                                    
    CamWriteCmosSensor(0x0F12, 0x0010);  //#REG_0TC_CCFG_OIFMask                                                           
    CamWriteCmosSensor(0x0F12, 0x01E0);  //01E0 //#REG_0TC_CCFG_usJpegPacketSize                                           
    CamWriteCmosSensor(0x0F12, 0x0500);  //08fc //#REG_0TC_CCFG_usJpegTotalPackets                                         
    CamWriteCmosSensor(0x0F12, 0x0002);  //#REG_0TC_CCFG_uClockInd                                                         
    CamWriteCmosSensor(0x0F12, 0x0001);  //#REG_0TC_CCFG_usFrTimeType                                                      
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_CCFG_FrRateQualityType                                             
    //sandy modify start
    CamWriteCmosSensor(0x0F12, 0x02CA);  //029A //0535 //#REG_0TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps                      
    CamWriteCmosSensor(0x0F12, 0x02CA);  
#endif

    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_bSmearOutput																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sSaturation 																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sSharpBlur																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sColorTemp																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_uDeviceGammaIndex																			
    																																																					
    //================================================================================================				
    // SET CAPTURE CONFIGURATION_1																																						
    // # Foramt :YUV																																													
    // # Size: 800x600																																												
    // # FPS : 7-5fps																																													
    //================================================================================================				
    CamWriteCmosSensor(0x002A, 0x0388);																																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_uCaptureModeJpEG																			
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x0800);	//0800 //#REG_0TC_CCFG_usWidth																				
    CamWriteCmosSensor(0x0F12, 0x0600);	//0600 //#REG_0TC_CCFG_usHeight 																			
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_0TC_CCFG_Format//5:YUV9:JPEG 																	
    CamWriteCmosSensor(0x0F12, 0x3A98);	//2EE0	//157C //3AA8 //#REG_0TC_CCFG_usMaxOut4KHzRate								
    CamWriteCmosSensor(0x0F12, 0x3A98);	//2EE0	//157C //3A88 //#REG_0TC_CCFG_usMinOut4KHzRate								
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_0TC_CCFG_OutClkPerPix88																				
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_0TC_CCFG_uMaxBpp88																							
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_0TC_CCFG_PVIMask																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_OIFMask 																							
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_0TC_CCFG_usJpegPacketSize 															
    CamWriteCmosSensor(0x0F12, 0x0320);	//08fc //#REG_0TC_CCFG_usJpegTotalPackets															
    CamWriteCmosSensor(0x0F12, 0x0002);	//#REG_0TC_CCFG_uClockInd																							
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_usFrTimeType																					
    CamWriteCmosSensor(0x0F12, 0x0002);  //#REG_0TC_CCFG_FrRateQualityType																		
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x07D0);	//029A //0535 //#REG_0TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps					
    CamWriteCmosSensor(0x0F12, 0x07D0);	//#REG_0TC_CCFG_usMinFrTimeMsecMult10 //10fps													
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_bSmearOutput																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sSaturation 																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sSharpBlur																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_sColorTemp																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_0TC_CCFG_uDeviceGammaIndex																			
    																																																					
    //================================================================================================				
    // SET CAPTURE CONFIGURATION_2																																						
    // # Foramt : yuv																																													
    // # Size:	1600x1200																																											
    // # FPS :	3FPS																																													
    //====================================================================================										
    CamWriteCmosSensor(0x002A, 0x03B4);																																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_uCaptureModeJpEG																			
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x0800);	//0800 //#REG_1TC_CCFG_usWidth																				
    CamWriteCmosSensor(0x0F12, 0x0600);	//0600 //#REG_1TC_CCFG_usHeight 																			
    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_1TC_CCFG_Format//5:YUV9:JPEG 																	
    CamWriteCmosSensor(0x0F12, 0x157C);	//157C //3AA8 //#REG_1TC_CCFG_usMaxOut4KHzRate												
    CamWriteCmosSensor(0x0F12, 0x157C);	//157C //3A88 //#REG_1TC_CCFG_usMinOut4KHzRate												
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_1TC_CCFG_OutClkPerPix88																				
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_1TC_CCFG_uMaxBpp88																							
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_1TC_CCFG_PVIMask																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_OIFMask  edison 																			
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_1TC_CCFG_usJpegPacketSize 															
    CamWriteCmosSensor(0x0F12, 0x0000);	//08fc //#REG_1TC_CCFG_usJpegTotalPackets															
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0001);	//#REG_1TC_CCFG_uClockInd																							
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_usFrTimeType																					
    CamWriteCmosSensor(0x0F12, 0x0002);	//#REG_1TC_CCFG_FrRateQualityType																			
    CamWriteCmosSensor(0x0F12, 0x0D05);	//07D0 //#REG_1TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps									
    CamWriteCmosSensor(0x0F12, 0x0D05);	//#REG_1TC_CCFG_usMinFrTimeMsecMult10 //10fps													
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_bSmearOutput																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sSaturation 																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sSharpBlur																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sColorTemp																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_uDeviceGammaIndex																			
    																																																					
    //================================================================================================				
    // SET CAPTURE CONFIGURATION_3																																						
    // # Foramt : yuv																																													
    // # Size:	1600x1200																																											
    // # FPS :	2FPS																																													
    //====================================================================================										
    CamWriteCmosSensor(0x002A, 0x03E0);																																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_uCaptureModeJpEG																			
    CamWriteCmosSensor(0x0F12, 0x0800);	//0800 //#REG_1TC_CCFG_usWidth																				
    CamWriteCmosSensor(0x0F12, 0x0600);	//0600 //#REG_1TC_CCFG_usHeight 																			
    CamWriteCmosSensor(0x0F12, 0x0005);	//#REG_1TC_CCFG_Format//5:YUV9:JPEG 																	
    //sandy modify start 																																											
    CamWriteCmosSensor(0x0F12, 0x157C);	//157C //3AA8 //#REG_1TC_CCFG_usMaxOut4KHzRate												
    CamWriteCmosSensor(0x0F12, 0x157C);	//157C //3A88 //#REG_1TC_CCFG_usMinOut4KHzRate												
    CamWriteCmosSensor(0x0F12, 0x0100);	//#REG_1TC_CCFG_OutClkPerPix88																				
    CamWriteCmosSensor(0x0F12, 0x0800);	//#REG_1TC_CCFG_uMaxBpp88																							
    CamWriteCmosSensor(0x0F12, 0x0052);	//0052 //#REG_1TC_CCFG_PVIMask																				
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_OIFMask  edison 																			
    CamWriteCmosSensor(0x0F12, 0x03C0);	//01E0 //#REG_1TC_CCFG_usJpegPacketSize 															
    CamWriteCmosSensor(0x0F12, 0x0000);	//08fc //#REG_1TC_CCFG_usJpegTotalPackets															
    CamWriteCmosSensor(0x0F12, 0x0001);	//#REG_1TC_CCFG_uClockInd																							
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_usFrTimeType																					
    CamWriteCmosSensor(0x0F12, 0x0002);	//#REG_1TC_CCFG_FrRateQualityType																			
    CamWriteCmosSensor(0x0F12, 0x1338);	//07D0 //#REG_1TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps									
    CamWriteCmosSensor(0x0F12, 0x1338);	//#REG_1TC_CCFG_usMinFrTimeMsecMult10 //10fps													
    //sandy modify end																																												
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_bSmearOutput																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sSaturation 																					
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sSharpBlur																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_sColorTemp																						
    CamWriteCmosSensor(0x0F12, 0x0000);	//#REG_1TC_CCFG_uDeviceGammaIndex																			
    																																																					
    //================================================================																				
    // ARM Go ... ...																																													
    //================================================================																				
    CamWriteCmosSensor(0x0028, 0xD000);	//Host Interrupt																											
    CamWriteCmosSensor(0x002A, 0x1000);																																				
    CamWriteCmosSensor(0x0F12, 0x0001);																																				
    CamWriteCmosSensor(0x0028, 0x7000);																																				
    kal_sleep_task(4);  // Actually delay 18.46ms , 10ms delay is enough for ARM go
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAGetSensorInfo
*
* DESCRIPTION
*    This function set sensor infomation
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAGetSensorInfo(P_IMAGE_SENSOR_GET_SENSOR_INFO_STRUCT Info)
{
    Info->SensorId = S5K5CAGA_SENSOR_ID;
    Info->SensorIf = IMAGE_SENSOR_IF_PARALLEL;
    Info->PreviewNormalDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewHMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PreviewHVMirrorDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->CaptureDataFormat = IMAGE_SENSOR_DATA_OUT_FORMAT_UYVY;
    Info->PixelClkInv = KAL_FALSE;
    Info->PixelClkPolarity = POLARITY_LOW;
    Info->HsyncPolarity = POLARITY_LOW;
    Info->VsyncPolarity = POLARITY_HIGH;
    Info->PreviewMclkFreq = 24000000;
    Info->CaptureMclkFreq = 24000000;
    Info->VideoMclkFreq = 24000000;
    Info->PreviewWidth = S5K5CAGA_IMAGE_SENSOR_PV_WIDTH_DRV;
    Info->PreviewHeight = S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT_DRV;
    Info->FullWidth = S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH_DRV;
    Info->FullHeight = S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT_DRV;
    
    Info->SensorAfSupport = KAL_FALSE;
    Info->SensorFlashSupport = KAL_TRUE;

    Info->IsSensorDriverCtrlMclk = KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAPowerOn
*
* DESCRIPTION
*    This function reset sensor and read id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint16 S5K5CAGAPowerOn(void)
{
    kal_uint16 i;

    /* 1. Default Setting for the Reset & Power Down pin. */
    CamRstPinCtrl(S5K5CAGASensor.SensorIdx, 0);
    CamPdnPinCtrl(S5K5CAGASensor.SensorIdx, 0);
    kal_sleep_task(1); /* >= 4.615ms */

    /* 2. Enable the power, DVDD->AVDD->DOVDD. */
    CisModulePowerOn(S5K5CAGASensor.SensorIdx, KAL_TRUE);
    CameraSccbOpen(CAMERA_SCCB_SENSOR, S5K5CAGA_WRITE_ID, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 320);
    kal_sleep_task(1); /* > 0ns */

    // 3. Enable the MCLK output.
    ENABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
    kal_sleep_task(1); /* No requirement */

    // 4. Pull the STBYN to high
	CamPdnPinCtrl(S5K5CAGASensor.SensorIdx, 1);
    kal_sleep_task(1); // > 15 usec
    // 5. Pull the Rst pin to high
    CamRstPinCtrl(S5K5CAGASensor.SensorIdx, 1);
    kal_sleep_task(1); // > 100 usec

    // 6. Pull the STBYN
	// TST:0, STBYN is active low, STBYN should be pull high to enable the normal operation mode.
	// TST:1, STBYN is active high, keep, STBYN should be pull low to enable the normal operation mode.
#ifdef S5K5CAGA_TST_PIN_HIGH
	CamPdnPinCtrl(S5K5CAGASensor.SensorIdx, 0);
    kal_sleep_task(1); // > 0 usec
#endif

    CamWriteCmosSensor(0xFCFC, 0x0000);
    kal_sleep_task(1);
    S5K5CAGASensor.SensorId = (CamReadCmosSensor(0x0040));
    if (S5K5CAGASensor.SensorId != S5K5CAGA_SENSOR_ID) /* READ SENSOR ID */
    {
        CameraSccbClose(CAMERA_SCCB_SENSOR);
        CameraSccbInit(CAMERA_SW_SCCB, 1, 1, 0x80);     // 0xA0==>0x80
        CameraSccbOpen(CAMERA_SCCB_SENSOR, S5K5CAGA_WRITE_ID_1, CAMERA_SCCB_16BIT, CAMERA_SCCB_16BIT, 320);

        CamWriteCmosSensor(0xFCFC, 0x0000);
        kal_sleep_task(1);
        S5K5CAGASensor.SensorId = (CamReadCmosSensor(0x0040));
    }

    S5K5CAGA_TRACE("[S5K5CAGA] Write_id=%x, Sensor ID=%x", 0x00, S5K5CAGASensor.SensorId);
    S5K5CAGA_TRACE("Chip Revision=%x", CamReadCmosSensor(0x0042));
    S5K5CAGA_TRACE("FW Version=%x", CamReadCmosSensor(0x0048));
    S5K5CAGA_TRACE("FW Compilation date(0xYMDD)=%x", CamReadCmosSensor(0x004E));

    return S5K5CAGASensor.SensorId;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGADetectSensorId
*
* DESCRIPTION
*    This function detect sensor id
*
* PARAMETERS
*    None
*
* RETURNS
*    sensor id
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_uint32 S5K5CAGADetectSensorId(void)
{
  MM_ERROR_CODE_ENUM S5K5CAGASensorClose(void);
  //kal_uint16 S5K5CAGASensor.SensorId;
  IMAGE_SENSOR_INDEX_ENUM InvIdx;
  kal_int8 i, j;
  
  switch (S5K5CAGASensor.SensorIdx)
  {
  case IMAGE_SENSOR_MAIN:
  case IMAGE_SENSOR_BAK1:
    InvIdx = IMAGE_SENSOR_SUB;
    break;
  default:
    InvIdx = IMAGE_SENSOR_MAIN;
    break;
  }
  for (i = 1; i >= 0; i--)
  {
    for (j = 1; j >= 0; j--)
    {
      CamRstPinCtrl(InvIdx, i);
      CamPdnPinCtrl(InvIdx, j);
      S5K5CAGASensor.SensorId = S5K5CAGAPowerOn();
      S5K5CAGASensorClose();
      if (S5K5CAGA_SENSOR_ID == S5K5CAGASensor.SensorId)
      {
        return S5K5CAGA_SENSOR_ID;
      }
    }
  }
  return MM_ERROR_SENSOR_READ_ID_FAIL;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAStillCaptureSize
*
* DESCRIPTION
*    This function get capture size
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGAStillCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CapSize->IsSupport = KAL_TRUE;
        CapSize->ItemCount = 6;
        CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        CapSize->SupportItem[1] = CAM_IMAGE_SIZE_QVGA;
        CapSize->SupportItem[2] = CAM_IMAGE_SIZE_VGA;
        CapSize->SupportItem[3] = CAM_IMAGE_SIZE_1M;
        CapSize->SupportItem[4] = CAM_IMAGE_SIZE_2M;
        CapSize->SupportItem[5] = CAM_IMAGE_SIZE_3M;
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAZSDCaptureSize
*
* DESCRIPTION
*    This function get ZSD capture size
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGAZSDCaptureSize(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT CapSize = &Out->FeatureInfo.FeatureEnum;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        CapSize->IsSupport = KAL_TRUE;
        CapSize->ItemCount = 5;
        CapSize->SupportItem[0] = CAM_IMAGE_SIZE_WALLPAPER;
        CapSize->SupportItem[1] = CAM_IMAGE_SIZE_VGA;
        CapSize->SupportItem[2] = CAM_IMAGE_SIZE_1M;
        CapSize->SupportItem[3] = CAM_IMAGE_SIZE_2M;
        CapSize->SupportItem[4] = CAM_IMAGE_SIZE_3M;
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGABanding
*
* DESCRIPTION
*    This function get banding setting
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGABanding(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT Banding = &Out->FeatureInfo.FeatureEnum;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        Banding->IsSupport = KAL_TRUE;
        Banding->ItemCount = 2;
        Banding->SupportItem[0] = CAM_BANDING_50HZ;
        Banding->SupportItem[1] = CAM_BANDING_60HZ;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        kal_uint16 temp_reg;

        CamWriteCmosSensor(0x002C, 0x7000);	    // Set page
        CamWriteCmosSensor(0x002E, 0x04D2);

        temp_reg = CamReadCmosSensor(0X0F12);
        S5K5CAGA_TRACE("[Banding] = %d (0-50Hz, 1-60Hz), 0x04D2=%x", In->FeatureSetValue, temp_reg);
    
        switch (In->FeatureSetValue)
        {
        case CAM_BANDING_50HZ:
            CamWriteCmosSensor(0x0028, 0x7000); 	// Set page
            CamWriteCmosSensor(0x002A, 0x04D2); 	// Set address						
            CamWriteCmosSensor(0x0F12, (temp_reg & (~0x0020))); 	// #REG_TC_DBG_AutoAlgEnBits, AA_FLICKER OFF

            CamWriteCmosSensor(0x002A, 0x04BA);	    //REG_SF_USER_FlickerQuant, 0: no AFC, 1: 50Hz, 2: 60Hz
            CamWriteCmosSensor(0x0F12, 0x0001);		//50Hz
            CamWriteCmosSensor(0x0F12, 0x0001);		//Sync F/W
            break;
        case CAM_BANDING_60HZ:
            CamWriteCmosSensor(0x0028, 0x7000); 	// Set page
            CamWriteCmosSensor(0x002A, 0x04D2); 	// Set address						
            CamWriteCmosSensor(0x0F12, (temp_reg & (~0x0020))); 	// #REG_TC_DBG_AutoAlgEnBits, AA_FLICKER OFF

            CamWriteCmosSensor(0x002A, 0x04BA);	    //REG_SF_USER_FlickerQuant, 0: no AFC, 1: 50Hz, 2: 60Hz
            CamWriteCmosSensor(0x0F12, 0x0002);		// 60Hz
            CamWriteCmosSensor(0x0F12, 0x0001);		//Sync F/W
            break;
        default:
            CamWriteCmosSensor(0x0028, 0x7000); 	// Set page
            CamWriteCmosSensor(0x002A, 0x04D2); 	// Set address						
            CamWriteCmosSensor(0x0F12, (temp_reg | 0x0020)); 	// #REG_TC_DBG_AutoAlgEnBits, AA_FLICKER On
            return MM_ERROR_NONE;
        }
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAAeMetering
*
* DESCRIPTION
*    This function get & set the AE metering mode, set to different AE weighting table.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGAAeMetering(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_TYPE_ENUM_STRUCT AeMetering = &Out->FeatureInfo.FeatureEnum;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_VIDEO_SUPPORT;
        //AeMetering->IsSupport = KAL_TRUE;
        AeMetering->IsSupport = KAL_FALSE;
        AeMetering->ItemCount = 4;
        AeMetering->SupportItem[0] = CAM_AE_METER_AUTO;
        AeMetering->SupportItem[1] = CAM_AE_METER_SPOT;
        AeMetering->SupportItem[2] = CAM_AE_METER_CENTRAL;
        AeMetering->SupportItem[3] = CAM_AE_METER_AVERAGE;
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        S5K5CAGA_TRACE("[AE Metering] = %d (0-Auto, 1-Spot, 2-Central, 3-Average)", In->FeatureSetValue);
        
        CamWriteCmosSensor(0x0028, 0x7000); 	// Set page
        switch (In->FeatureSetValue)
        {
        case CAM_AE_METER_AUTO:
            CamWriteCmosSensor(0x002a, 0x0F7E);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0303);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            break;
        case CAM_AE_METER_SPOT:
            CamWriteCmosSensor(0x002A, 0x0F7E);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0201);
            CamWriteCmosSensor(0x0F12, 0x0102);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0201);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0102);
            CamWriteCmosSensor(0x0F12, 0x0201);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0202);
            CamWriteCmosSensor(0x0F12, 0x0102);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            CamWriteCmosSensor(0x0F12, 0x0101);
            break;
        case CAM_AE_METER_CENTRAL:
            CamWriteCmosSensor(0x002A, 0x0F7E);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0f01);
            CamWriteCmosSensor(0x0f12, 0x010f);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0f01);
            CamWriteCmosSensor(0x0f12, 0x010f);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            CamWriteCmosSensor(0x0f12, 0x0000);
            break;
        case CAM_AE_METER_AVERAGE:
            CamWriteCmosSensor(0x002a, 0x0F7E);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            CamWriteCmosSensor(0x0f12, 0x0101);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAISOBiningInfo
*
* DESCRIPTION
*    This function get & set the ISO mode.
*
* PARAMETERS
*    In, Out
*
* RETURNS
*    error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGAISOBiningInfo(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    const P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo=Out->FeatureInfo.FeatureStructured.pBinningInfo;
    kal_uint32 i = 0;

    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        Out->FeatureType=CAL_FEATURE_TYPE_STRUCTURED;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|
            CAL_FEATURE_GET_OPERATION|
            CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_VIDEO_SUPPORT;

        for (i=CAM_ISO_AUTO;i<=CAM_ISO_400;i++)
        {
            pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_3M;
            pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_TRUE;
            pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
        }
        for (;i<=CAM_ISO_1600;i++)
        {
            pBinningInfo->IsoBinningInfo[i].MaxResolution = CAM_IMAGE_SIZE_1M;
            pBinningInfo->IsoBinningInfo[i].IsoSupported = KAL_FALSE;
            pBinningInfo->IsoBinningInfo[i].BinningEnable = KAL_FALSE;
        }
    }
    else if (CAL_FEATURE_SET_OPERATION == In->FeatureCtrlCode)
    {
        S5K5CAGA_TRACE("[ISO] = %d (0-Auto, 1-100, 2-200, 3-400)", In->FeatureSetValue);
        
        CamWriteCmosSensor(0x0028, 0x7000);
        switch (In->FeatureSetValue)
        {
        case CAM_ISO_AUTO:
            CamWriteCmosSensor(0x002A, 0x04B4);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0000);
            CamWriteCmosSensor(0x0F12, 0x0001);
            break;
        case CAM_ISO_100:
            CamWriteCmosSensor(0x002A, 0x04B4);
            CamWriteCmosSensor(0x0F12, 0x0001);
            CamWriteCmosSensor(0x0F12, 0x0100);
            CamWriteCmosSensor(0x0F12, 0x0001);
            break;
        case CAM_ISO_200:
            CamWriteCmosSensor(0x002A, 0x04B4);
            CamWriteCmosSensor(0x0F12, 0x0001);
            CamWriteCmosSensor(0x0F12, 0x0200);
            CamWriteCmosSensor(0x0F12, 0x0001);
            break;
        case CAM_ISO_400:
            CamWriteCmosSensor(0x002A, 0x04B4);
            CamWriteCmosSensor(0x0F12, 0x0001);
            CamWriteCmosSensor(0x0F12, 0x0400);
            CamWriteCmosSensor(0x0F12, 0x0001);
            break;
        default:
            return MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        }
    }
    return MM_ERROR_NONE;
}

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)

/*************************************************************************
* FUNCTION
*    S5K5CAGAGetEvAwbRef
*
* DESCRIPTION
*    This function get sensor Ev/Awb (EV05/EV13) for auto scene detect
*
* PARAMETERS
*    Ref
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void S5K5CAGAGetEvAwbRef(P_SENSOR_AE_AWB_REF_STRUCT Ref)  //???
{	
    Ref->SensorAERef.AeRefLV05Shutter = 9161;   /* 0x8F24/4 */
    Ref->SensorAERef.AeRefLV05Gain =    910;    /* 0x71C/256 = 7.11x */
    Ref->SensorAERef.AeRefLV13Shutter = 246;    /* 0x3DA/4 */
    Ref->SensorAERef.AeRefLV13Gain =    128;    /* 0x100/256 = 1.00x */
    
    Ref->SensorAwbGainRef.AwbRefD65Rgain = 186; /* 0x5D1/1024 =  1.45x */
    Ref->SensorAwbGainRef.AwbRefD65Bgain = 171; /* 0x559/1024 =  1.34x */
    Ref->SensorAwbGainRef.AwbRefCWFRgain = 163; /* 0x51E/1024 =  1.28x */
    Ref->SensorAwbGainRef.AwbRefCWFBgain = 259; /* 0x818/1024 =  2.02x */
}

/*************************************************************************
* FUNCTION
*    S5K5CAGAGetCurAeAwbInfo
*
* DESCRIPTION
*    This function get sensor cur Ae/Awb for auto scene detect
*
* PARAMETERS
*    Info
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
void S5K5CAGAGetCurAeAwbInfo(P_SENSOR_AE_AWB_CUR_STRUCT Info)
{
    kal_uint32 awb_r_gain = 0, awb_b_gain = 0;
    
    CamWriteCmosSensor(0x002C, 0x7000);
    CamWriteCmosSensor(0x002E, 0x23F8);     /* AWB R Gain, , 0x400 - 1x */
    awb_r_gain = CamReadCmosSensor(0x0F12);
    CamWriteCmosSensor(0x002E, 0x23FC);     /* AWB B Gain, , 0x400 - 1x */
    awb_b_gain = CamReadCmosSensor(0x0F12);

    /* (awb_r_gain)  * 128 / 1024 equal to (awb_r_gain) / 8 */
    Info->SensorAwbGainCur.AwbCurRgain = (awb_r_gain) / 8;
    Info->SensorAwbGainCur.AwbCurBgain = (awb_b_gain) / 8;

    Info->SensorAECur.AeCurShutter = S5K5CAGAReadShutter();
    Info->SensorAECur.AeCurGain = S5K5CAGAReadGain();
}

#endif

/*************************************************************************
* FUNCTION
*    S5K5CAGAInitOperationPara
*
* DESCRIPTION
*    This function set sensor operation para
*
* PARAMETERS
*    Para
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAInitOperationPara(P_IMAGE_SENSOR_GET_INIT_OPERATION_PARA_STRUCT Para)
{
    Para->CaptureDelayFrame = 0; /* use WaitStableFrameNum instead of this */
    Para->PreviewDelayFrame = 4;
    Para->PreviewDisplayWaitFrame = 14;

    //Yuv flashlight tuning parameter
    Para->FlashlightPrestrobeFrame=8;
    Para->FlashlightPrestrobeToRedeyeFrame=1;
    Para->FlashlightRedeyeStrobeFrame=2;
    Para->FlashlightMainStrobeDelayFrame =1;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAPreview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    const kal_bool PreMode = S5K5CAGASensor.PvMode;
    kal_uint16 DummyPixel;

    S5K5CAGA_TRACE("[Preview][Size: %d x %d] id=%d, mirror=%d, night=%d", In->ImageTargetWidth, In->ImageTargetHeight, Id, In->ImageMirror, In->NightMode);

    switch (Id)
    {
    case CAL_SCENARIO_VIDEO:
        S5K5CAGASensor.VideoMode = KAL_TRUE;
        S5K5CAGASensor.Fps = In->MaxVideoFrameRate;
        DummyPixel = 0;
        break;
    default:
        S5K5CAGASensor.VideoMode = KAL_FALSE;
        S5K5CAGASensor.Fps = In->NightMode ? S5K5CAGA_FPS(5) : S5K5CAGA_FPS(10);
        DummyPixel = 0;
        break;
    }

    S5K5CAGASetDummy(DummyPixel, 0);
    S5K5CAGANightMode(In->NightMode);

    S5K5CAGASetMirror(In->ImageMirror);

    if (KAL_TRUE == S5K5CAGASensor.OutTestPattern)
    {
        /* 5CA don't support output color bar like test pattern, it can use the DTP function instead. */
        CamWriteCmosSensor(0x0028, 0xD000);
        CamWriteCmosSensor(0x002A, 0xB054);
        CamWriteCmosSensor(0x0F12, 0x0001);
    }

    //S5K5CAGAAeEnable(KAL_TRUE);
    //S5K5CAGAAwbEnable(KAL_TRUE);

    Out->WaitStableFrameNum = 2;
    /* In colorinv, should delay more time to avoid flash as AE working  */
    if (!S5K5CAGASensor.FirstPv && !PreMode && CAM_EFFECT_ENC_COLORINV == In->ImageEffect)
    {
        Out->WaitStableFrameNum = 5;
    }
    S5K5CAGASensor.FirstPv = KAL_FALSE;
    Out->GrabStartX = S5K5CAGA_PV_X_START;
    Out->GrabStartY = S5K5CAGA_PV_Y_START;
    Out->ExposureWindowWidth = S5K5CAGA_IMAGE_SENSOR_PV_WIDTH;
    Out->ExposureWindowHeight = S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGAFullPreview
*
* DESCRIPTION
*    This function set to preview mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGAFullPreview(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    const kal_bool PreMode = S5K5CAGASensor.PvMode;
    kal_uint16 DummyPixel;

    S5K5CAGA_TRACE("[Full Preview][Size: %d x %d] id=%d, mirror=%d", In->ImageTargetWidth, In->ImageTargetHeight, Id, In->ImageMirror);

    S5K5CAGASetMirror(In->ImageMirror);

   
    //================================================================
    //SETPREVIEWCONFIGURATION_0ameraNormal Full Size 3M 11.5~7.5fps
    //================================================================
    CamWriteCmosSensor(0x002A, 0x026C);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    CamWriteCmosSensor(0x0F12, 0x0800);  // 2048
    CamWriteCmosSensor(0x0F12, 0x0600);  // 1536
    CamWriteCmosSensor(0x0F12, 0x0005);  //#REG_0TC_PCFG_Format
    CamWriteCmosSensor(0x0F12, 0x5054);  //0x4228); // #REG_TC_IPRM_MinOutRate4KHz_2	PVI clock 82MHz
    CamWriteCmosSensor(0x0F12, 0x4fd4);  //0x42a8); // #
    CamWriteCmosSensor(0x0F12, 0x0100);  //#REG_0TC_PCFG_OutClkPerPix88    0276                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    CamWriteCmosSensor(0x0F12, 0x0800);  //#REG_0TC_PCFG_uMaxBpp88         027                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    CamWriteCmosSensor(0x0F12, 0x0052);  //0052 //#REG_0TC_PCFG_PVIMask //s0050 = FALSE in MSM6290 : s0052 = TRUE in MSM6800 //reg 027A                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    CamWriteCmosSensor(0x0F12, 0x4000);  //#REG_0TC_PCFG_OIFMask                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    CamWriteCmosSensor(0x0F12, 0x03C0);  //01E0 //#REG_0TC_PCFG_usJpegPacketSize                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    CamWriteCmosSensor(0x0F12, 0x0320);  //0000 //#REG_0TC_PCFG_usJpegTotalPackets                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    CamWriteCmosSensor(0x0F12, 0x0001);
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_usFrTimeType                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    CamWriteCmosSensor(0x0F12, 0x0000);  
    CamWriteCmosSensor(0x0F12, 0x0535);  //#REG_0TC_CCFG_usMaxFrTimeMsecMult10 //7.5fps
    CamWriteCmosSensor(0x0F12, 0x0365);  //#REG_0TC_CCFG_usMinFrTimeMsecMult10 //11.5fps 
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_bSmearOutput                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_sSaturation                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_sSharpBlur                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_sColorTemp                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_uDeviceGammaIndex                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_uPrevMirror                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_uCaptureMirror                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    CamWriteCmosSensor(0x0F12, 0x0000);  //#REG_0TC_PCFG_uRotation      

    //================================================================================================
    // APPLY PREVIEW CONFIGURATION & RUN PREVIEW
    //================================================================================================
    CamWriteCmosSensor(0x002A, 0x023C);
    CamWriteCmosSensor(0x0F12, 0x0000); // #REG_TC_GP_ActivePrevConfig // Select preview configuration_0
    CamWriteCmosSensor(0x002A, 0x0240);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_PrevOpenAfterChange
    CamWriteCmosSensor(0x002A, 0x0230);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_NewConfigSync // Update preview configuration
    CamWriteCmosSensor(0x002A, 0x023E);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_PrevConfigChanged
    CamWriteCmosSensor(0x002A, 0x0220);
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_EnablePreview // Start preview
    CamWriteCmosSensor(0x0F12, 0x0001); // #REG_TC_GP_EnablePreviewChanged

    Out->WaitStableFrameNum = 2;

    Out->GrabStartX = S5K5CAGA_FULL_X_START;
    Out->GrabStartY = S5K5CAGA_FULL_Y_START;
    Out->ExposureWindowWidth = S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH;
    Out->ExposureWindowHeight = S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGACapture
*
* DESCRIPTION
*    This function set to capture mode
*
* PARAMETERS
*    Id, In, Out
*
* RETURNS
*    None
*
* LOCAL AFFECTED
*
*************************************************************************/
static void S5K5CAGACapture(CAL_SCENARIO_ENUM Id, P_IMAGE_SENSOR_SCENARIO_PARA_IN_STRUCT In, P_IMAGE_SENSOR_SCENARIO_PARA_OUT_STRUCT Out)
{
    kal_uint16 DummyPixel;

    S5K5CAGA_TRACE("[Capture][Size: %d x %d] zoom=%d", In->ImageTargetWidth, In->ImageTargetHeight, In->ZoomFactor);

    if ((In->ImageTargetWidth <= 800) && (In->ImageTargetHeight <= 600))        /* QVGA */
    {
        Out->WaitStableFrameNum = 3;    /* 2 is not enough for exposure */

        Out->ExposureWindowWidth = S5K5CAGA_IMAGE_SENSOR_PV_WIDTH;
        Out->ExposureWindowHeight = S5K5CAGA_IMAGE_SENSOR_PV_HEIGHT;
    }
    else                                                                        /* 3M */
    {
        CamWriteCmosSensor(0xFCFC, 0xD000);
        CamWriteCmosSensor(0x0028, 0x7000);
        CamWriteCmosSensor(0x002A, 0x037A);
        if (KAL_TRUE == S5K5CAGASensor.NightMode)
        {
            CamWriteCmosSensor(0x0F12, 0x07D0); //#REG_0TC_CCFG_usMaxFrTimeMsecMult10  5fps     
            CamWriteCmosSensor(0x0F12, 0x0365); //#REG_0TC_CCFG_usMinFrTimeMsecMult10   11fps    
        }
        else
        {
            CamWriteCmosSensor(0x0F12, 0x0535); //#REG_0TC_CCFG_usMaxFrTimeMsecMult10  7.5fps     
            CamWriteCmosSensor(0x0F12, 0x0365); //#REG_0TC_CCFG_usMinFrTimeMsecMult10   11fps    
        }
        
        CamWriteCmosSensor(0x0028, 0x7000);
        CamWriteCmosSensor(0x002A, 0x0224);
        CamWriteCmosSensor(0x0F12, 0x0001);
        CamWriteCmosSensor(0x002A, 0x0244);
        CamWriteCmosSensor(0x0F12, 0x0000);
        CamWriteCmosSensor(0x0F12, 0x0001);
        CamWriteCmosSensor(0x002A, 0x0230);
        CamWriteCmosSensor(0x0F12, 0x0001);
        CamWriteCmosSensor(0x002A, 0x0226);
        CamWriteCmosSensor(0x0F12, 0x0001);

        Out->WaitStableFrameNum = 3;    /* 2 is not enough for exposure */
        Out->ExposureWindowWidth = S5K5CAGA_IMAGE_SENSOR_FULL_WIDTH;
        Out->ExposureWindowHeight = S5K5CAGA_IMAGE_SENSOR_FULL_HEIGHT;
    }
    Out->GrabStartX = S5K5CAGA_FULL_X_START;
    Out->GrabStartY = S5K5CAGA_FULL_Y_START;

}


/*************************************************************************
* FUNCTION
*    S5K5CAGASensorOpen
*
* DESCRIPTION
*    This function read sensor id and init sensor
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGASensorOpen(void)
{
    if (S5K5CAGAPowerOn() != S5K5CAGA_SENSOR_ID)
    {
        return MM_ERROR_SENSOR_READ_ID_FAIL;
    }

    S5K5CAGA_TRACE("[Drv]Start Initialize_Setting: %d", drv_get_current_time());

#ifdef S5K5CAGA_LOAD_FROM_T_FLASH
    if (S5K5CAGA_Initialize_from_T_Flash())			/* For debug use. */
    {
        /* If load from t-flash success, then do nothing. */
    }
    else	/* Failed, load from the image load. */
#endif
	{
        S5K5CAGAInitialSetting();
    }

    S5K5CAGA_TRACE("[Drv]Initialize_Setting Done: %d", drv_get_current_time());

    /* Default setting */
    {
        IMAGE_SENSOR_INDEX_ENUM SensorIdx = S5K5CAGASensor.SensorIdx;
        sensor_data_struct *NvramData = S5K5CAGASensor.NvramData;

        kal_mem_set(&S5K5CAGASensor, 0xFF, sizeof(S5K5CAGASensor));
        S5K5CAGASensor.BypassAe = KAL_FALSE;
        S5K5CAGASensor.BypassAwb = KAL_FALSE;
        S5K5CAGASensor.PvMode = KAL_FALSE;
        S5K5CAGASensor.FirstPv = KAL_TRUE;
        S5K5CAGASensor.OutTestPattern = KAL_FALSE;    /* Default not output test pattern */
        S5K5CAGASensor.SensorIdx = SensorIdx;
        S5K5CAGASensor.NvramData = NvramData;
    }

    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   s5k5cagaFlashMode
*
* DESCRIPTION
*   flash mode
*
* PARAMETERS
*   In, Out
*
* RETURNS
*   Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM s5k5cagaFlashMode(P_CAL_FEATURE_CTRL_STRUCT In, P_CAL_FEATURE_CTRL_STRUCT Out)
{
    if (CAL_FEATURE_QUERY_OPERATION == In->FeatureCtrlCode)
    {
        const P_CAL_FEATURE_TYPE_ENUM_STRUCT FlashMode = &Out->FeatureInfo.FeatureEnum;

        Out->FeatureType = CAL_FEATURE_TYPE_ENUMERATE;
        Out->FeatureOperationSupport = CAL_FEATURE_SET_OPERATION|CAL_FEATURE_QUERY_OPERATION;
        Out->FeatureModeSupport = CAL_FEATURE_CAMERA_SUPPORT;
        // TODO: add supported flash mode enum here
#ifndef LED_FLASHLIGHT_SUPPORT
        FlashMode->IsSupport = KAL_FALSE;
#else
        FlashMode->IsSupport = KAL_TRUE;
        FlashMode->ItemCount = 4;
        FlashMode->SupportItem[0] = CAM_FLASH_OFF;
        FlashMode->SupportItem[1] = CAM_FLASH_ON;
        FlashMode->SupportItem[2] = CAM_FLASH_AUTO;
        FlashMode->SupportItem[3] = CAM_FLASH_REDEYE;
#endif
    }
    return MM_ERROR_NONE;
}


/*************************************************************************
* FUNCTION
*   S5K5CAGAFlashTriggerCheck
*
* DESCRIPTION
*   This function check the average Y and
*     threshhold to determine if need to trigger flashlight
*
* PARAMETERS
*   None
*
* RETURNS
*   Enable: KAL_TRUE: need trigger, KAL_FALSE: do nothing
*
* LOCAL AFFECTED
*
*************************************************************************/
static kal_bool S5K5CAGAFlashTriggerCheck(void)
{
    kal_bool NeedTrigger = KAL_FALSE;
    kal_uint32 Shutter = 0;
    kal_uint32 Gain = 0;
   

    ///TODO: check the average Y and threshhold to determine if need to trigger flashlight
    //1: read shutter
    //2: read gain
    //3: determine if trigger flash
    Shutter = S5K5CAGAReadShutter();
    Gain = S5K5CAGAReadGain();
	
	kal_prompt_trace(MOD_ENG,"Shutter:%x",Shutter);

	kal_prompt_trace(MOD_ENG,"Gain:%x",Gain);
	

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
	#endif

	NeedTrigger = KAL_TRUE;

    return NeedTrigger;
}


/*************************************************************************
* FUNCTION
*    S5K5CAGASensorFeatureCtrl
*
* DESCRIPTION
*    This function set sensor feature mode
*
* PARAMETERS
*    Id: scenario id
*    In: input parameter
*    Out: output parameter
*    OutLen: output parameter length
*    RealOutLen: real output parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGASensorFeatureCtrl(kal_uint32 Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    MM_ERROR_CODE_ENUM ErrCode = MM_ERROR_NONE;
    kal_uint32 i=0;

    if (Id >= CAL_FEATURE_WEBCAM_BEGIN && Id <= CAL_FEATURE_WEBCAM_END)
    {
        return S5K5CAGAWebcamFeatureCtrl(Id, In, Out, OutLen, RealOutLen);
    }
    switch (Id)
    {
        /* query and set series */
    case CAL_FEATURE_CAMERA_BRIGHTNESS:
    case CAL_FEATURE_CAMERA_EV_VALUE:
        ErrCode = S5K5CAGAEv(In, Out);
        break;
    case CAL_FEATURE_CAMERA_CONTRAST:
        ErrCode = S5K5CAGAContrast(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SATURATION:
        ErrCode = S5K5CAGASaturation(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SHARPNESS:
        ErrCode = S5K5CAGASharpness(In, Out);
        break;
    case CAL_FEATURE_CAMERA_HUE:
    case CAL_FEATURE_CAMERA_GAMMA:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    case CAL_FEATURE_CAMERA_WB:
        ErrCode = S5K5CAGAWb(In, Out);
        break;
    case CAL_FEATURE_CAMERA_IMAGE_EFFECT:
        ErrCode = S5K5CAGAEffect(In, Out);
        break;
    case CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE:
        ErrCode = S5K5CAGAStillCaptureSize(In, Out);
        break;
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
    case CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE:
        ErrCode = S5K5CAGAZSDCaptureSize(In, Out);
        break;
#endif
    case CAL_FEATURE_CAMERA_BANDING_FREQ:
        ErrCode = S5K5CAGABanding(In, Out);
        break;
    case CAL_FEATURE_CAMERA_AE_METERING_MODE:
        ErrCode = S5K5CAGAAeMetering(In, Out);
        break;
    case CAL_FEATURE_CAMERA_BINNING_INFO:
        ErrCode = S5K5CAGAISOBiningInfo(In, Out);
        break;
    case CAL_FEATURE_CAMERA_SCENE_MODE:
        ErrCode = S5K5CAGASceneMode(KAL_TRUE, In, Out);
        break;
    case CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE:
        ErrCode = S5K5CAGASceneMode(KAL_FALSE, In, Out);
        break;

        /* get info series */
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_INFO:
        S5K5CAGAGetSensorInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_ID:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = S5K5CAGADetectSensorId();
        break;
    case IMAGE_SENSOR_FEATURE_GET_SENSOR_FRAME_RATE:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = S5K5CAGASensor.Fps;
        break;
    case IMAGE_SENSOR_FEATURE_GET_INIT_OPERATION_PARA:
        S5K5CAGAInitOperationPara(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_HW_DEPENDENT_SETTING:
        CamGetHWInfo(S5K5CAGASensor.SensorIdx, Out);
        break;

        /* set para series */
    case IMAGE_SENSOR_FEATURE_SET_SENSOR_POWER_DOWN:
        CamPdnPinCtrl(S5K5CAGASensor.SensorIdx, 1);
        CamRstPinCtrl(S5K5CAGASensor.SensorIdx, 0);
        break;
    case IMAGE_SENSOR_FEATURE_SET_NVRAM_SENSOR_INFO:
        S5K5CAGASensor.NvramData = &(((nvram_camera_para_struct *)In)->SENSOR);
        break;
    case IMAGE_SENSOR_FEATURE_SET_CAMERA_SOURCE:
        S5K5CAGASensor.SensorIdx = ((P_IMAGE_SENSOR_SET_CAMERA_SOURCE_STRUCT)In)->ImageSensorIdx;
        break;
    case IMAGE_SENSOR_FEATURE_CTRL_NIGHTMODE: /* move to preview */
        break;
    case IMAGE_SENSOR_FEATURE_SET_AE_BYPASS:
        S5K5CAGASensor.BypassAe = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        S5K5CAGAAeEnable(S5K5CAGASensor.BypassAe ? KAL_FALSE : KAL_TRUE);
        break;
    case IMAGE_SENSOR_FEATURE_SET_AWB_BYPASS:
        S5K5CAGASensor.BypassAwb = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        S5K5CAGAAwbEnable(S5K5CAGASensor.BypassAwb ? KAL_FALSE : KAL_TRUE);
        break;

#if defined (__AUTO_SCENE_DETECT_SUPPORT__)
    case IMAGE_SENSOR_FEATURE_GET_EV_AWB_REF:
        S5K5CAGAGetEvAwbRef(Out);
        break;
    case IMAGE_SENSOR_FEATURE_GET_SHUTTER_GAIN_AWB_GAIN:
        S5K5CAGAGetCurAeAwbInfo(Out);
        break;
    case IMAGE_SENSOR_FEATURE_SET_SCENE_ENHANCE:
        {
            CAL_FEATURE_CTRL_STRUCT Para;

            Para.FeatureCtrlCode = CAL_FEATURE_SET_OPERATION;
            Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneContrast;
            S5K5CAGAContrast(&Para,NULL);
            Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSaturation;
            S5K5CAGASaturation(&Para,NULL);
            Para.FeatureSetValue = ((P_SENSOR_SCENE_ENHANCE_STRUCT)In)->SceneSharpness;
            S5K5CAGASharpness(&Para,NULL);
        }
        break;
#endif

        /* YUV flash light support series */
    case CAL_FEATURE_CAMERA_FLASH_MODE:
        ErrCode = s5k5cagaFlashMode(In, Out);
        break;
    case IMAGE_SENSOR_FEATURE_QUERY_YUV_CTRL_FLASHLIGHT_TRIGGER_MODE:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = FLASHLIGHT_CONTINUOUS_MODE;
        break;
    case IMAGE_SENSOR_FEATURE_SET_YUV_CTRL_FLASHLIGHT_TRIGGER_MODE:
        break;
    case IMAGE_SENSOR_FEATURE_CTRL_FLASHLIGHT:
        FlashlightPowerOn(S5K5CAGASensor.SensorIdx, ((P_IMAGE_SENSOR_COMM_CTRL_STRUCT)In)->FeatureEnable);
        break;
    case IMAGE_SENSOR_FEATURE_YUV_CHECK_IF_TRIGGER_FLASHLIGHT:
        ((P_IMAGE_SENSOR_COMM_DATA_STRUCT)Out)->FeatureValue = S5K5CAGAFlashTriggerCheck();
        break;
#if (defined(__CATS_SUPPORT__))
    case CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN:
        S5K5CAGASensor.OutTestPattern = (kal_bool)((P_IMAGE_SENSOR_COMM_DATA_STRUCT)In)->FeatureValue;
        break;
#endif
        /* Webcam Tuning Tool will use it. */
    case IMAGE_SENSOR_FEATURE_SET_REGISTER:
        for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;i++)
        {
            CamWriteCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i],((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegData[i]);
        }
        break;
    case IMAGE_SENSOR_FEATURE_GET_REGISTER:
        ((P_IMAGE_SENSOR_REG_IN_STRUCT)Out)->RegNum = ((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;
        for (i=0;i<((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->RegNum;i++)
        {
            ((P_IMAGE_SENSOR_REG_IN_STRUCT) Out)->pRegAddr[i]=((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i];
            ((P_IMAGE_SENSOR_REG_IN_STRUCT) Out)->pRegData[i]=CamReadCmosSensor(((P_IMAGE_SENSOR_REG_IN_STRUCT)In)->pRegAddr[i]);
        }
        break;
    case IMAGE_SENSOR_FEATURE_GET_DATA_INFO:
        ((P_SENSOR_REG_WIDTH_STRUCT)Out)->AddrWidth = 16;
        ((P_SENSOR_REG_WIDTH_STRUCT)Out)->ParaWidth = 16;
        break;

    default:
        ErrCode = MM_ERROR_SENSOR_FEATURE_NOT_SUPPORT;
        break;
    }

    return ErrCode;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGASensorCtrl
*
* DESCRIPTION
*    This function set sensor scenario mode
*
* PARAMETERS
*    Id: scenario id
*    In/Out: parameter
*    OutLen: Out parameter length
*    RealOutLen: Real out parameter length
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGASensorCtrl(CAL_SCENARIO_ENUM Id, void *In, void *Out, kal_uint32 OutLen, kal_uint32 *RealOutLen)
{
    switch (Id)
    {
    case CAL_SCENARIO_CAMERA_PREVIEW:
    case CAL_SCENARIO_VIDEO:
    case CAL_SCENARIO_WEBCAM_PREVIEW:
    case CAL_SCENARIO_WEBCAM_CAPTURE:
        S5K5CAGAPreview(Id, In, Out);
        break;
    case CAL_SCENARIO_CAMERA_STILL_CAPTURE:
        S5K5CAGACapture(Id, In, Out);
        break;
#ifdef __ZERO_SHUTTER_DELAY_SUPPORT__
    case CAL_SCENARIO_CAMERA_ZSD_PREVIEW:
        S5K5CAGAFullPreview(Id,In,Out);
        break;
#endif
    default:
        break;
    }
    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGASensorClose
*
* DESCRIPTION
*    This function is to turn off sensor module power.
*
* PARAMETERS
*    None
*
* RETURNS
*    Error code
*
* LOCAL AFFECTED
*
*************************************************************************/
static MM_ERROR_CODE_ENUM S5K5CAGASensorClose(void)
{
    /* 1. Pull the standby pin to low (STBYN before RSTN). */
    CamPdnPinCtrl(S5K5CAGASensor.SensorIdx, 0); /* goto standby */
    kal_sleep_task(1);  /* > 0us */

    /* 2. Pull the Reset pin to low. */
    CamRstPinCtrl(S5K5CAGASensor.SensorIdx, 0);
    kal_sleep_task(1);  /* > 50us */

    /* 3. Pull low the MCLK. */
    SET_CMOS_FALLING_EDGE(0);
    DISABLE_CAMERA_TG_PHASE_COUNTER;
    DISABLE_CAMERA_CLOCK_OUTPUT_TO_CMOS;
    kal_sleep_task(1);  /* > 0us */

    /* 4. Power off the DOVDD, AVDD, DVDD. */
    CisModulePowerOn(S5K5CAGASensor.SensorIdx, KAL_FALSE);

    CameraSccbClose(CAMERA_SCCB_SENSOR);

    return MM_ERROR_NONE;
}

/*************************************************************************
* FUNCTION
*    S5K5CAGASensorFunc
*
* DESCRIPTION
*    This function get sensor function pointer
*
* PARAMETERS
*    sensor function pointer
*
* RETURNS
*    Error code
*
* GLOBALS AFFECTED
*
*************************************************************************/
MM_ERROR_CODE_ENUM S5K5CAGASensorFunc(P_IMAGE_SENSOR_FUNCTION_STRUCT *pfSensorFunc)
{
  static IMAGE_SENSOR_FUNCTION_STRUCT ImageSensorFuncS5K5CAGA =
  {
    S5K5CAGASensorOpen,
    S5K5CAGASensorFeatureCtrl,
    S5K5CAGASensorCtrl,
    S5K5CAGASensorClose,
  };
  
  *pfSensorFunc = &ImageSensorFuncS5K5CAGA;
  
  return MM_ERROR_NONE;
}

#ifdef __S5K5CAGA_DEBUG_TRACE__

#include "kbd_table.h"
#include "keypad_sw.h"
#include "stack_ltlcom.h"
#include "dcl.h"
#include "cam_main.h"

// TODO: Can remove after int the ata code.
#include "med_utility.h"

extern kal_bool             kbd_push_assert;
extern kbd_buffer_struct    kbd_buffer;

kal_uint8 CATS_curr_state = 0;		// 0 - Idle
DCL_HANDLE AT_Camera_hdl=NULL;


static void CATS_kbd_push_onekey(kbd_event event,kal_uint8 key)  
{
     ASSERT(kbd_push_assert == KAL_FALSE);
   kbd_push_assert = KAL_TRUE;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = event;
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = key;
   //kbd_push_time_stamp();
   kbd_buffer.kbd_data_buffer_windex++;
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);
   kbd_push_assert = KAL_FALSE;
}


void CATS_press_one_key(kal_uint32 key_code)
{
	ilm_struct 	*Kp_ilm = NULL;

	CATS_kbd_push_onekey(kbd_onekey_press, key_code);
	DRV_BuildPrimitive(Kp_ilm,
						MOD_DRVKBD,
						MOD_UEM,
						MSG_ID_DRVUEM_KEYPAD_IND,
						NULL);
	msg_send_ext_queue(Kp_ilm);

	CATS_kbd_push_onekey(kbd_onekey_release, key_code);
	DRV_BuildPrimitive(Kp_ilm,
						MOD_DRVKBD,
						MOD_UEM,
						MSG_ID_DRVUEM_KEYPAD_IND,
						NULL);
	msg_send_ext_queue(Kp_ilm);
}

void CATS_Callback(void *args)
{
	static kal_uint8 idx = 3;
	SGPT_CTRL_START_T start;

	switch (CATS_curr_state)
	{
		case 0:		// Idle screen state.
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			CATS_press_one_key(DEVICE_KEY_RIGHT);
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			CATS_press_one_key(DEVICE_KEY_DOWN);
			CATS_press_one_key(DEVICE_KEY_SK_LEFT);
			idx = 3;
			CATS_curr_state = 1;
			break;
		case 1:		// Preview state
			CATS_press_one_key(DEVICE_KEY_MENU);
			idx = 3;
			CATS_curr_state = 2;
			break;
		case 2:		// Capture state
			CATS_press_one_key(DEVICE_KEY_END);
			idx = 3;
			CATS_curr_state = 0;
			break;
		case 3:		// Error state
			CATS_press_one_key(DEVICE_KEY_END);
			idx = 5;
			CATS_curr_state = 0;
			break;
			
	}

	start.u2Tick=(idx*100);
	start.pfCallback=CATS_Callback;
	start.vPara=NULL;
	DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start); 	
}

static kal_bool S5K5CAGAAtGetValue(char *Str, kal_uint32 *Data)
{
    extern int isdigit(int c);
    extern int isxdigit(int c);
    extern int tolower(int c);
    char CmdName[15];
    kal_uint8 TmpIdx = 0, Index = 3;
    kal_uint32 Value;

    while (Str[Index] != '=' && Str[Index] != 13)
    {
        CmdName[TmpIdx++] = Str[Index++];
    }
    CmdName[TmpIdx] = '\0';

    if (strcmp(CmdName, "DO"))
    {
        return KAL_FALSE;
    }
    Value = Data[0] = 0;
    while (1)
    {
        TmpIdx = Str[++Index];
        switch (TmpIdx)
        {
        case 13:
        case ',':
            Data[++Data[0]] = Value;
            if (Data[0] == 9 || TmpIdx == 13)
            {
                return KAL_TRUE;
            }
            Value = 0;
            break;
        default:
            if (isdigit(TmpIdx))
            {
                Value = Value * 16 + TmpIdx - '0';
            }
            else if (isxdigit(TmpIdx))
            {
                Value = Value * 16 + tolower(TmpIdx) - 'a' + 10;
            }
            else
            {
                return KAL_TRUE;
            }
            break;
        }
    }
}

kal_bool AtFuncTest(kal_char *Str)
{
    kal_uint32 Data[60];

    if (!S5K5CAGAAtGetValue(Str, Data))
    {
        return KAL_FALSE;
    }
    if (!Data[0])
    {
        return KAL_TRUE;
    }
	
    switch (Data[1])
    {
    case 0x00:
        {
            kal_uint16 AeCurShutter; /* Current Sensor AE Shutter */
            kal_uint16 AeCurGain; /* Current Sensor AE Gain */
            AeCurShutter = S5K5CAGAReadShutter();
            AeCurGain = S5K5CAGAReadGain(); /* 128 base */

            CamWriteCmosSensor(0xFCFC, 0xD000);    
            CamWriteCmosSensor(0x002C, 0x7000);    
            CamWriteCmosSensor(0x002E, 0x23F8); 
            S5K5CAGA_TRACE("AwbCurRgain = %x", CamReadCmosSensor(0x0F12));
            CamWriteCmosSensor(0x002E, 0x23FC); 
            S5K5CAGA_TRACE("AwbCurBgain = %x", CamReadCmosSensor(0x0F12));
        }
        break;
    case 0x02:
        S5K5CAGA_TRACE("Read BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x03:
        DRV_Reg32(Data[2]) = Data[3];
        S5K5CAGA_TRACE("Write BB Reg[%x] = %x", Data[2], DRV_Reg32(Data[2]));
        break;
    case 0x04:
        S5K5CAGA_TRACE("Read Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x05:
        CamWriteCmosSensor(Data[2], Data[3]);
        S5K5CAGA_TRACE("Write Sensor Reg[%x] = %x", Data[2], CamReadCmosSensor(Data[2]));
        break;
    case 0x06:
        CamWriteCmosSensor(Data[2], Data[3]);
        S5K5CAGA_TRACE("Read Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x07:
        CamWriteCmosSensor(Data[2], Data[3]);
        CamWriteCmosSensor(Data[4], Data[5]);
        CamWriteCmosSensor(Data[2], Data[3]);
        S5K5CAGA_TRACE("Write Sensor Reg[%x:%x] = %x", Data[3], Data[4], CamReadCmosSensor(Data[4]));
        break;
    case 0x08:
	{
		SGPT_CTRL_START_T start;
		AT_Camera_hdl = DclSGPT_Open(DCL_GPT_CB,0);
		
		S5K5CAGA_TRACE("CATS start...");

		start.u2Tick=300;
		start.pfCallback=CATS_Callback;
		start.vPara=NULL;
		DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start); 	
		break;
    }
	case 0x09:
	{
		DclSGPT_Control(AT_Camera_hdl,SGPT_CMD_STOP,0);

		DclSGPT_Close(&AT_Camera_hdl);
		AT_Camera_hdl = NULL;
		
		S5K5CAGA_TRACE("CATS stop!!!");
	}
	break;
    case 0x0A:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                S5K5CAGA_TRACE("Read Sensor Reg[%x] = %x", Data[2] + i, CamReadCmosSensor(Data[2] + i));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
    case 0x0B:
        {
            kal_uint32 i;

            for (i = 0; i < Data[3]; i++)
            {
                S5K5CAGA_TRACE("Read BB Reg[%x] = %x", Data[2] + i * 4, DRV_Reg32(Data[2] + i * 4));
                if (!(i % 200))
                {
                    kal_sleep_task(30);
                }
            }
        }
        break;
#if (defined(__CATS_SUPPORT__))
    case 0x0C:                                  /* Get Sensor Id */
        {
            MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
            kal_uint32 sensor_id;
            ret = CATSInit(0);
            if (MM_ERROR_NONE != ret)
            {
                return KAL_FALSE;
            }
            ret = CATSFeatureCtrl(CATS_FEATURE_GET_SENSOR_ID, NULL, &sensor_id);
            CATSDeinit();
        }
        break;
    case 0x0D:                                  /* Get Test Pattern */
        {
            MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
            cats_frame_buff_st test_pattern = {0};
            cats_compare_result_st comp_result = {0};
            ret = CATSInit(0);
            if (MM_ERROR_NONE != ret)
            {
                return KAL_FALSE;
            }

            ret = CATSFeatureCtrl(CATS_FEATURE_GET_PATTERN_FORMAT, NULL, &(test_pattern.color_format));
            test_pattern.frame_width = 320;
            test_pattern.frame_height = 240;

            test_pattern.frame_buffer_size = test_pattern.frame_width * test_pattern.frame_height * 2;
            test_pattern.frame_buffer = (kal_uint32) med_alloc_asm_mem(0, test_pattern.frame_buffer_size);
            if (NULL == test_pattern.frame_buffer)
            {
                CATSDeinit();

                return KAL_FALSE;
            }
                
            ret = CATSFeatureCtrl(CATS_FEATURE_GET_TEST_PATTERN, &test_pattern, NULL);

            if (MM_ERROR_NONE == ret)
            {
                // TODO: need re-write the threshold.
                //if (need_target_compare)
                {
                    /* Error Ratio is represent with percent, and 10 means 10%, range is 0% to 100% */
                    // TODO: need re-write the threshold.
                    test_pattern.err_ratio_threshold = 1;
                    ret = CATSFeatureCtrl(CATS_FEATURE_COMPARE_TEST_PATTERN, &test_pattern, &comp_result);
                    S5K5CAGA_TRACE("[Compare] ret = %d, err_ratio = %d, err_pattern_cnt=%d, pattern_size=%d", \
                            ret, comp_result.err_ratio, comp_result.err_pattern_cnt, comp_result.pattern_size);
                    if (MM_ERROR_NONE == ret)
                    {
                        /* Successeed, the pattern from sensor is same with stored pattern. */
                    }
                    else
                    {
                        /* Compare the test pattern failed. */
                    }
                }
            }
            else
            {
                /* Get the test pattern failed, Do the error handler */
            }
            
            CATSDeinit();

            med_free_asm_mem(0, (void **)&test_pattern.frame_buffer);

            return KAL_TRUE;
        }
        break;
    case 0x0E:                                  /* Capture one jpeg image. */
        {
            MM_ERROR_CODE_ENUM ret = MM_ERROR_NONE;
            cats_frame_buff_st preview_para = {0};
            cats_capture_image_st capture_para = {0};

            ret = CATSInit(0);
            if (MM_ERROR_NONE != ret)
            {
                return KAL_FALSE;
            }

            ret = CATSFeatureCtrl(CATS_FEATURE_GET_PATTERN_FORMAT, NULL, &(preview_para.color_format));
            preview_para.frame_width = 320;
            preview_para.frame_height = 240;

            preview_para.frame_buffer_size = preview_para.frame_width * preview_para.frame_height * 2;
            preview_para.frame_buffer = (kal_uint32) med_alloc_asm_mem(0, preview_para.frame_buffer_size);
            if (NULL == preview_para.frame_buffer)
            {
                CATSDeinit();

                return KAL_FALSE;
            }
                
            ret = CATSFeatureCtrl(CATS_FEATURE_CAMERA_PREVIEW, &preview_para, NULL);

            if (MM_ERROR_NONE == ret)
            {
                /* Free the preview working buffer firstly. */
                med_free_asm_mem(0, (void **)&preview_para.frame_buffer);
                
                capture_para.image_width = 2048;
                capture_para.image_height = 1536;
                capture_para.image_resolution = CAM_IMAGE_SIZE_3M;

                capture_para.image_quality = 3;     /* 3-High, 2-Medium, 1-Low */
                capture_para.capture_mode = CAM_STILL_CAPTURE_NORMAL;

                capture_para.capture_buffer_size = MAX_CAM_CAPTURE_ISP_BUF_SIZE;
                capture_para.capture_buffer_p = (kal_uint32) med_alloc_asm_mem_framebuffer(0, capture_para.capture_buffer_size);
                
                /* Preview successfully, then capture one jpeg image. */
                ret = CATSFeatureCtrl(CATS_FEATURE_CAMERA_CAPTURE, &capture_para, &capture_para);
                if (MM_ERROR_NONE == ret)
                {
                    /* Send the jpeg image to PC or save it in flash then send it to PC. */
                    /* 

                                        while (1)
                                        {
                                            Here is the jpeg buffer need send to PC
                                            
                                            capture_para.jpeg_image_address
                                            capture_para.jpeg_image_size
                                             
                                        }
                                    */
                }
                
                /* Free the capture working buffer. */
                med_free_asm_mem(0, (void **)&capture_para.capture_buffer_p);
            }
            else
            {
                /* Get the test pattern failed, Do the error handler */
                med_free_asm_mem(0, (void **)&preview_para.frame_buffer);
            }
            
            CATSDeinit();

            return KAL_TRUE;
        }
        break;
#endif  /* #if (defined(__CATS_SUPPORT__)) */
    default:
        break;
    }
    return KAL_TRUE;
}

#endif	/* #ifdef __S5K5CAGA_DEBUG_TRACE__ */


