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
 *  vcui_sms_composer_util.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Qian Zhao
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_util.h"

VfxU32 VcuiSmsComposerUtility::valid_sim = 0;
VfxU32 VcuiSmsComposerUtility::blocked_sim = 0;
VfxU32 VcuiSmsComposerUtility::closed_sim = 0;

VfxS32 VcuiSmsComposerUtility::getMaxRecipientCount(void)
{
    return VCUI_SMS_COMPOSER_MAX_ADDRESS_NUM;
}

VfxS32 VcuiSmsComposerUtility::getMaxContentTextCount(void)
{
    return VCUI_SMS_COMPOSER_MAX_TEXT_BUFFER_SIZE;
}

VfxBool VcuiSmsComposerUtility::checkIsAsciiString(const VfxU8 *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxU8   utf8_str[(VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN + 2) * 3] = {0,};
	VfxS32  utf8_buffer_size = (VCUI_SMS_COMPOSER_MAX_PHONE_NUMBER_LEN + 2) * 3;
	VfxU8*  number = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string(utf8_str, utf8_buffer_size, (U8*)ucs2_str);
	number = utf8_str;
	
    /* If this is an ASCII string, each octet should be an ASCII character. */
    for (; *number != '\0'; ++number)
    {
        if (*number > 0x7F)
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

VfxBool VcuiSmsComposerUtility::checkIsPhoneNum(VfxU8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxChar ucs2_string[(APPLIB_MAX_PHONE_NUM_LEN +1) * ENCODING_LENGTH] = {0,};
	VfxChar acs_string[APPLIB_MAX_PHONE_NUM_LEN + 1] = {0,};
	VfxChar *number = NULL;
	VfxS32 numberlen = 0;
    VfxU8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	numberlen = mmi_ucs2strlen((CHAR *)strNumber);	
    if (numberlen == 0)
    {
        return VFX_FALSE;
    }
    
    if (applib_is_valid_number_unicode((kal_wchar*) strNumber) != APPLIB_INVALID_NUMBER)
    {
		memcpy(ucs2_string, strNumber, APPLIB_MAX_PHONE_NUM_LEN*ENCODING_LENGTH);
		app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) ucs2_string);
		number = acs_string;
        if (acs_string[0] == '+')
        {
            numberlen = numberlen - 1;
            number++;
        }
        
        if (numberlen == 0)
        {
            return VFX_FALSE;
        }
        
        for (i = 0; i < numberlen; i++)
        {
            VfxChar digit = number[i];
        
            if ((digit < '0' || digit > '9') && digit != '*' && digit != '#')
            {
                return VFX_FALSE;
            }
        }
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxU32 VcuiSmsComposerUtility::convertSwitchModeToSmscSim(VfxU32 swith_mode)
{
    switch((srv_mode_switch_type_enum)swith_mode)
    {
        case SRV_MODE_SWITCH_SIM1:
            return MMI_SIM1;
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_MODE_SWITCH_SIM2:
            return MMI_SIM2;
        case SRV_MODE_SWITCH_SIM3:
            return MMI_SIM3;
        case SRV_MODE_SWITCH_SIM4:
            return MMI_SIM4;
#if (MMI_MAX_SIM_NUM == 2)
        case SRV_MODE_SWITCH_SIM_ALL:
            return MMI_SIM1 | MMI_SIM2;
#endif
#if (MMI_MAX_SIM_NUM == 3)
        case SRV_MODE_SWITCH_SIM_ALL:
            return MMI_SIM1 | MMI_SIM2| MMI_SIM3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_MODE_SWITCH_SIM_ALL:
            return MMI_SIM1 | MMI_SIM2| MMI_SIM3|MMI_SIM4;
#endif
#endif
        default:
            return MMI_SIM_NONE;
    }
}

VfxU32 VcuiSmsComposerUtility::getValidSim(void)
{
    return valid_sim;
}

VfxU32 VcuiSmsComposerUtility::getBlockedSim(void)
{
    return blocked_sim;
}

VfxU32 VcuiSmsComposerUtility::getClosedSim(void)
{
    return closed_sim;
}

VfxU32 VcuiSmsComposerUtility::getInvalidSim(void)
{
	VfxU32 result = closed_sim | blocked_sim;
    return result ;
}

mmi_sim_enum VcuiSmsComposerUtility::getValidSimToSend(void)
{
    if(MMI_SIM1 & valid_sim)
    {
        return MMI_SIM1;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if(MMI_SIM2 & valid_sim)
    {
        return MMI_SIM2;        
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if(MMI_SIM3 & valid_sim)
    {
        return MMI_SIM3;        
    }
#if (MMI_MAX_SIM_NUM >= 4)
    else if(MMI_SIM4 & valid_sim)
    {
        return MMI_SIM4;        
    }
#endif
#endif
#endif
    else
    {
        return MMI_SIM1;
    }
}

VfxS32 VcuiSmsComposerUtility::getCurrValidSimCount(void)
{
    VfxS32 count = 0;

    if((valid_sim & ~(getInvalidSim())) & MMI_SIM1)
	{
		count++;
	}
	
    if((valid_sim & ~(getInvalidSim())) & MMI_SIM2)
	{
		count++;
	}
	
    if((valid_sim & ~(getInvalidSim())) & MMI_SIM3)
	{
		count++;
	}
	
    if((valid_sim & ~(getInvalidSim())) & MMI_SIM4)
	{
		count++;
	}
	
	return count;
}

VfxS32 VcuiSmsComposerUtility::getAllSimCount(void)
{
    VfxS32 count = 0;

    if(valid_sim  & MMI_SIM1)
	{
		count++;
	}
    if(valid_sim  & MMI_SIM2)
	{
		count++;
	}
    if(valid_sim & MMI_SIM3)
	{
		count++;
	}
    if(valid_sim  & MMI_SIM4)
	{
		count++;
	}
	return count;
}

mmi_sim_enum VcuiSmsComposerUtility::getCurrSim(void)
{
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_enum settingSim = srv_setting_get_primary_card();
    if((!valid_sim) || (valid_sim & settingSim))
    {
        return settingSim;
    }
#endif
    if(valid_sim & MMI_SIM1)
	{
		return MMI_SIM1;
	}
	else if(valid_sim & MMI_SIM2)
	{
		return MMI_SIM2;
	}
    else if(valid_sim & MMI_SIM3)
	{
		return MMI_SIM3;
	}
    else if(valid_sim & MMI_SIM4)
	{
		return MMI_SIM4;
	}
	return MMI_SIM_NONE;
}

void VcuiSmsComposerUtility::getTitleBarStr(VfxU16* text_buffer, mmi_sim_enum send_sim_id)
{
    mmi_sim_enum sim_setting_primary_card = srv_setting_get_primary_card();
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VCUI_SMSC_WRITE_MSG_ID));
    
#if (MMI_MAX_SIM_NUM >= 3)
    if (getCurrValidSimCount() >= 3 || (sim_setting_primary_card != MMI_SIM_NONE))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (send_sim_id == MMI_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(send_sim_id == MMI_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (send_sim_id == MMI_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (send_sim_id == MMI_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");    
    }
#elif (MMI_MAX_SIM_NUM >= 2)
    if (getValidSim() == (MMI_SIM1 | MMI_SIM2)
		|| (sim_setting_primary_card != MMI_SIM_NONE))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (send_sim_id == MMI_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(send_sim_id == MMI_SIM1)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (sim_setting_primary_card == MMI_SIM2)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
		}
		else	// if (sim_setting_primary_card == MMI_SIM2)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));		
		}
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");
    }
#endif /* MMI_MAX_SIM_NUM */ 
}

VfxBool VcuiSmsComposerUtility::getSimNameStr(mmi_sim_enum sim, WCHAR* text_buffer)
{
    if(sim == MMI_SIM1)
    {
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
    }
    else if (sim == MMI_SIM2)
    {
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
    }
	else if (sim == MMI_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else if (sim == MMI_SIM4)
	{
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
	}
    if(!(vapp_sim_settings_get_sim_name(sim)).isEmpty())
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L" ( ");
        mmi_ucs2cat((PS8) text_buffer, (PS8) ((vapp_sim_settings_get_sim_name(sim)).getBuf())); 
        mmi_ucs2cat((PS8) text_buffer, (PS8) L" )");
    }
    return VFX_TRUE;
}

void VcuiSmsComposerUtility::getSendButtonStr(VfxU16* text_buffer, mmi_sim_enum send_sim_id)
{
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SEND));
    mmi_sim_enum sim_setting_primary_card = srv_setting_get_primary_card();

#if (MMI_MAX_SIM_NUM >= 2)
    if (getCurrValidSimCount() >= 2 || (sim_setting_primary_card != MMI_SIM_NONE))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (send_sim_id == MMI_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(send_sim_id == MMI_SIM1)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (send_sim_id == MMI_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (send_sim_id == MMI_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        else if (sim_setting_primary_card == MMI_SIM2)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
		}
		else if (sim_setting_primary_card == MMI_SIM1)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));		
		}
        else if (sim_setting_primary_card == MMI_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (sim_setting_primary_card == MMI_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");    
    }
#endif /* MMI_MAX_SIM_NUM */ 
}

void VcuiSmsComposerUtility::getSwitchSimStr(VfxU16* text_buffer, mmi_sim_enum send_sim_id)
{
	VfxWString SimTitle = vapp_sim_settings_get_sim_name_with_sim_id(send_sim_id);
	mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VCUI_SMSC_SWITCHED_TO));
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" ");
	mmi_ucs2cat((PS8) text_buffer, (PS8)((SimTitle).getBuf()));
}

void VcuiSmsComposerUtility::getHintTextStr(VfxS32 remain, VfxS32 current, VfxS32 maxSize, VfxChar *text_buffer)
{
    U16 temp_buffer[24] = {0,};
    U16 temp_string_len = 24;
    U16 temp_UCS2_buffer[50] = {0,};

	memset(temp_buffer, 0, temp_string_len);
	sprintf((char*)temp_buffer, " %d", remain);
	mmi_asc_n_to_ucs2((S8*) temp_UCS2_buffer, (S8*) temp_buffer, temp_string_len);
	mmi_ucs2cat((PS8) text_buffer, (PS8) temp_UCS2_buffer);
	
	mmi_ucs2cat((PS8) text_buffer, (CHAR*)L"/");
	
	memset(temp_buffer, 0, temp_string_len);
	sprintf((char*)temp_buffer, "%d ", maxSize);
	mmi_asc_n_to_ucs2((S8*) temp_UCS2_buffer, (S8*) temp_buffer, temp_string_len);
	mmi_ucs2cat((PS8) text_buffer, (PS8) temp_UCS2_buffer); 
	
	if(current > 1)
	{
    	mmi_ucs2cat((PS8) text_buffer, (CHAR*)L"(");
    	memset(temp_buffer, 0, temp_string_len);
    	sprintf((char*)temp_buffer, "%d", current);
    	mmi_asc_n_to_ucs2((S8*) temp_UCS2_buffer, (S8*) temp_buffer, temp_string_len);
    	mmi_ucs2cat((PS8) text_buffer, (PS8) temp_UCS2_buffer);    
    	mmi_ucs2cat((PS8) text_buffer, (CHAR*)L") ");
	}
}

void VcuiSmsComposerUtility::getSwapSimStr(VfxU16* text_buffer, mmi_sim_enum send_sim_id)
{
	if(send_sim_id == MMI_SIM1)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
	}
	else if(send_sim_id == MMI_SIM2)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
	}
	else if(send_sim_id == MMI_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));
	}
	
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VCUI_SMSC_UNAVAILABLE_TRFR_TO_ID));
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	
	if(getValidSim() & MMI_SIM1)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
	}
	else if(getValidSim() & MMI_SIM2)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
	}
	else if(getValidSim() & MMI_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));
	}
	
	mmi_ucs2cat((PS8) text_buffer, (PS8) L" "); 
	mmi_ucs2cat((PS8) text_buffer, (PS8) L"?"); 
}

VfxId VcuiSmsComposerUtility::getErrorStrId(VcuiSmsComposerResultEnum error)
{
    switch(error)
    {
        case VCUI_SMS_COMPOSER_RESULT_NUM_CANNOT_BE_EMPTY:
            return STR_ID_VCUI_SMSC_NUM_CANNOT_BE_EMPTY_ID;
            
        case VCUI_SMS_COMPOSER_RESULT_INVALID_RECIPIENT:
            return STR_ID_VCUI_SMSC_INVALID_RECIPIENT;
            
        case VCUI_SMS_COMPOSER_RESULT_NUMBER_LENGTH_EXCEED:
            return STR_ID_VCUI_SMSC_NUMBER_LENGTH_EXCEED_ID;
            
        case VCUI_SMS_COMPOSER_RESULT_REACH_MAX_RECIPIENT:
            return STR_ID_VCUI_SMSC_RECIPIENT_NUMBER_EXCEED_ID;

        case VCUI_SMS_COMPOSER_RESULT_INSUFFIENT_MEMORY:
            return STR_GLOBAL_NOT_ENOUGH_MEMORY;
          
        case VCUI_SMS_COMPOSER_RESULT_MEM_FULL:
            return STR_GLOBAL_MEMORY_FULL;
            
        case VCUI_SMS_COMPOSER_RESULT_INVALID_NUMBER:
            return STR_GLOBAL_INVALID_NUMBER;
            
        case VCUI_SMS_COMPOSER_RESULT_MSG_SIZE_EXCEED:
            return STR_ID_VCUI_SMSC_MSG_SIZE_EXCEED_ID;
	            
        default:
            return STR_GLOBAL_ERROR;
    }

}

VfxBool VcuiSmsComposerUtility::checkIsFlightMode(void)
{
    if( srv_mode_switch_is_network_service_available() == MMI_TRUE )
    {
        return VFX_FALSE;
    }
    else

    {
        return VFX_TRUE;
    }
}


#ifdef __cplusplus
extern "C"
{
#endif

// extern API
mmi_ret vcuiSmsComposerSimStatusInfoHdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == evt)
        return MMI_RET_OK;
        
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
        {
            mmi_sim_enum sim_id = MMI_SIM_NONE;
            srv_sim_ctrl_availability_changed_evt_struct *sim_status = 
                (srv_sim_ctrl_availability_changed_evt_struct*)evt;
            mmi_sim_enum sim = sim_status->sim;
            sim_id = sim;
            if(sim_id != MMI_SIM_NONE)
            {
                VcuiSmsComposerUtility::valid_sim &= ~sim_id;
				srv_mode_switch_type_enum curr_mode = srv_mode_switch_get_current_mode();
                if(sim & curr_mode)
                {
                    if(srv_sim_ctrl_is_available(sim) ||
                        (srv_sim_ctrl_is_inserted(sim) && srv_sim_ctrl_chv1_is_blocked(sim)))
                    {
                        VcuiSmsComposerUtility::valid_sim |= sim_id;
                    }
                    
					if((srv_sim_ctrl_is_inserted(sim) && srv_sim_ctrl_chv1_is_blocked(sim)))
					{
						VcuiSmsComposerUtility::blocked_sim |= sim_id;
					}

                }

                if(VcuiSmsComposerUtility::convertSwitchModeToSmscSim(curr_mode == sim_id))
                {
                    VcuiSmsComposerUtility::valid_sim &= sim_id;
                }
            }            

            break;
        }

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
			mmi_sim_enum sim_id = MMI_SIM_NONE;
			mmi_sim_enum sim = MMI_SIM1;
			U32 max_sim_num = 1 ;
			srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;
			U32 mode = (U32)mode_status->gsm_select_mode;

			while(max_sim_num <= MMI_MAX_SIM_NUM)
			{
				sim_id = sim;
				
				if(mode & sim)
				{
                    if(srv_sim_ctrl_is_available(sim) || (srv_sim_ctrl_is_inserted(sim) && 
                        srv_sim_ctrl_chv1_is_blocked(sim)))
					{
						VcuiSmsComposerUtility::valid_sim |= sim_id;
						VcuiSmsComposerUtility::closed_sim &= ~sim_id ;
					}
				}
				else if(srv_sim_ctrl_is_inserted(sim))
				{
					VcuiSmsComposerUtility::valid_sim |= sim_id;
					VcuiSmsComposerUtility::closed_sim |=sim_id ;
				}
				sim = (mmi_sim_enum)(sim << 1);
				max_sim_num++ ;
			}
	    }

        default:
            break;
    }

    VFX_LOG(VFX_FUNC3, TRC_VCUI_SMSC_UTIL_EVENT_HDLR, evt->evt_id, VcuiSmsComposerUtility::valid_sim,
        VcuiSmsComposerUtility::blocked_sim, VcuiSmsComposerUtility::closed_sim);
   
    return MMI_RET_OK;
}


#ifdef __cplusplus
}
#endif

#endif /* __MMI_SMS_COMPOSER__ */
