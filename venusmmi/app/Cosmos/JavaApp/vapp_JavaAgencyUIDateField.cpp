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
 *  vapp_JavaAgencyUIDateField.cpp
 *
 * Project:
 * --------
 *  Venus
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
#ifdef __J2ME__
#include "MMI_features.h" 
#include "vapp_JavaAgencyUIDateField.h"
#include "mmi_rp_vapp_java_def.h"
#ifdef __AFX_RT_TEST__
#include "vtst_rt_main.h"
#endif
#include "../xml/vfx_xml_loader.h"
#include "MMI_include.h"
#include "vapp_java_adp.h"
#include "vapp_ncenter_gprot.h"

extern "C"
{
    #include "jam_internal.h"
    #include "jui_interface.h"

    #include "JavaAgencyDef.h"
    #include "JavaAgencyUIDateField.h"
}

extern "C" void vapp_java_ui_datefield_hide(void);


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 static VappJavaUIDateFieldSrc *g_mmi_vjava_datafield_ptr = NULL;
static mmi_java_ui_clndr_context_struct *g_mmi_vjava_ui_datefield_date = NULL;
static mmi_java_ui_time_context_struct *g_mmi_vjava_ui_datefield_time = NULL;
//static VappJavaUIDateFieldPage *g_mmi_vjava_ui_datefield_page = NULL;
static VfxBool g_mmi_vjava_ui_datefield_is_date_picker = VFX_TRUE;
//static mmi_id g_mmi_vjava_ui_datefield_gid = GRP_ID_INVALID;

/***************************************************************************** 
 * Function
 *****************************************************************************/
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

void VappJavaUIDateFieldSrc ::setTitle()
{
    if (g_mmi_vjava_ui_datefield_is_date_picker)
    {
    	title->setTitle(STR_GLOBAL_DATE);
    }
    else
    {
    	title->setTitle(STR_GLOBAL_TIME);
    }
}

void VappJavaUIDateFieldSrc ::createPicker()
{
    if (g_mmi_vjava_ui_datefield_is_date_picker)
    {
    	VFX_OBJ_CREATE_EX(datePicker, VcpDatePicker , this , (MMI_JAVA_UI_CLNDR_START_YEAR,MMI_JAVA_UI_CLNDR_END_YEAR));
		picker_height = datePicker->getSize().height;
		datePicker->setPos(0,statusbar_height + title_height);
        datePicker->setSize(scr_width, picker_height);
    	VcpDatePickerStruct date;
    	date.year = g_mmi_vjava_ui_datefield_date->CalTime.nYear;
    	date.month = g_mmi_vjava_ui_datefield_date->CalTime.nMonth;
    	date.day = g_mmi_vjava_ui_datefield_date->CalTime.nDay;
    	datePicker->setDate(date);
    }
    else
    {
    	VFX_OBJ_CREATE(timePicker, VcpTimePicker , this);
		picker_height = timePicker->getSize().height;
		timePicker->setPos(0,statusbar_height + title_height);
        timePicker->setSize(scr_width, picker_height);
    	VcpTimePickerStruct time;
    	time.hour = g_mmi_vjava_ui_datefield_time->hour;
    	time.minute = g_mmi_vjava_ui_datefield_time->minute;
    	timePicker->setTime(time);
    }

}


void VappJavaUIDateFieldSrc ::onInit()
{

    VfxAppCatScr::onInit();
    
    scr_width  = getSize().width; 
    scr_height = getSize().height;
	setBgColor(VFX_COLOR_GREY);

    /* Create StatusBar */
	VFX_OBJ_CREATE(statusIconBar, VcpStatusIconBar, this);
	statusbar_height = statusIconBar->getSize().height;
	statusIconBar->setPos(0, 0);
    statusIconBar->setSize(scr_width, statusbar_height);

    /* Create Title */
	VFX_OBJ_CREATE(title,VcpTitleBar, this);
    title_height = title->getSize().height;
    title->setPos(0,statusbar_height);
    title->setSize(scr_width, title_height);
	setTitle();

    /* Create ToolBar*/
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
	toolbar_height = toolBar->getSize().height;
	toolBar->setPos(0,scr_height - toolbar_height);
    toolBar->setSize(scr_width,toolbar_height);
    toolBar->addItem(JAVA_UI_DATEFIELD_TAB_OK, STR_GLOBAL_OK, VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    toolBar->m_signalButtonTap.connect(this, &VappJavaUIDateFieldSrc::onTBClick);

    /* Create Picker */
    createPicker();

}

void VappJavaUIDateFieldSrc ::onDeinit()
{
    if (g_mmi_vjava_ui_datefield_is_date_picker && g_mmi_vjava_ui_datefield_date)
	{
	    VcpDatePickerStruct date = datePicker->getDate();
		g_mmi_vjava_ui_datefield_date->CalTime.nYear = date.year;
		g_mmi_vjava_ui_datefield_date->CalTime.nMonth = date.month;
		g_mmi_vjava_ui_datefield_date->CalTime.nDay = date.day;
	}
	else if(g_mmi_vjava_ui_datefield_time)
	{
		VcpTimePickerStruct time = timePicker->getTime();
		g_mmi_vjava_ui_datefield_time->hour = time.hour;
		g_mmi_vjava_ui_datefield_time->minute = time.minute;
		g_mmi_vjava_ui_datefield_time->second = 0;
	}
	VfxAppCatScr::onDeinit();
}


void VappJavaUIDateFieldSrc::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case JAVA_UI_DATEFIELD_TAB_OK:
        {
            if (g_mmi_vjava_ui_datefield_is_date_picker)
            {
                VcpDatePickerStruct date = datePicker->getDate();
                g_mmi_vjava_ui_datefield_date->CalTime.nYear = date.year;
                g_mmi_vjava_ui_datefield_date->CalTime.nMonth = date.month;
                g_mmi_vjava_ui_datefield_date->CalTime.nDay = date.day;
				g_mmi_vjava_ui_datefield_date->callback(
                                                        KAL_TRUE,
                                                        (kal_int32) g_mmi_vjava_ui_datefield_date->CalTime.nYear,
                                                        (kal_int32) (g_mmi_vjava_ui_datefield_date->CalTime.nMonth - 1),
                                                        (kal_int32) g_mmi_vjava_ui_datefield_date->CalTime.nDay,
                                                        g_mmi_vjava_ui_datefield_date->vm_id);
				g_mmi_vjava_ui_datefield_date->callback = NULL;

            }
            else
            {
                VcpTimePickerStruct time = timePicker->getTime();
                g_mmi_vjava_ui_datefield_time->hour = time.hour;
                g_mmi_vjava_ui_datefield_time->minute = time.minute;
                g_mmi_vjava_ui_datefield_time->second = 0;
				g_mmi_vjava_ui_datefield_time->callback(
                                                        KAL_TRUE,
                                                        g_mmi_vjava_ui_datefield_time->hour,
                                                        g_mmi_vjava_ui_datefield_time->minute,
                                                        g_mmi_vjava_ui_datefield_time->second,
                                                        g_mmi_vjava_ui_datefield_time->vm_id);
				g_mmi_vjava_ui_datefield_time->callback = NULL;

            }

			vapp_java_ui_datefield_hide();
            break;
        }
    }
}

extern "C" void vapp_java_ui_datefield_date_launch(mmi_java_ui_clndr_context_struct* datefield)
{
    g_mmi_vjava_ui_datefield_date = datefield;

    g_mmi_vjava_ui_datefield_is_date_picker = VFX_TRUE;
	
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#else
	// initalize app category
    VfxAppCatScr::initalizeWithScrAsmSize(80*1024);

    VFX_OBJ_CREATE(
        g_mmi_vjava_datafield_ptr,
        VappJavaUIDateFieldSrc, 
        VfxAppCatScr::getContext());
	#endif
}


extern "C" void vapp_java_ui_datefield_time_launch(mmi_java_ui_time_context_struct* datefield)
{
    g_mmi_vjava_ui_datefield_time = datefield;

    g_mmi_vjava_ui_datefield_is_date_picker = VFX_FALSE;
	
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    // initalize app category
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    VfxAppCatScr::initalizeWithScrAsmSize(80*1024);
#else
		VfxAppCatScr::initalize();
#endif

    
    VFX_OBJ_CREATE(
    	g_mmi_vjava_datafield_ptr,
    	VappJavaUIDateFieldSrc, 
    	VfxAppCatScr::getContext());

#endif
}


extern "C" void vapp_java_ui_datefield_hide(void)
{
    //if (g_mmi_vjava_ui_datefield_gid != GRP_ID_INVALID)
    //{
        if (g_mmi_vjava_ui_datefield_is_date_picker && g_mmi_vjava_ui_datefield_date)
        {
            if (g_mmi_vjava_ui_datefield_date->callback != NULL)
            {
                g_mmi_vjava_ui_datefield_date->callback(
                                                   KAL_FALSE,
                                                   (kal_int32) g_mmi_vjava_ui_datefield_date->CalTime.nYear,
                                                   (kal_int32) (g_mmi_vjava_ui_datefield_date->CalTime.nMonth - 1),
                                                   (kal_int32) g_mmi_vjava_ui_datefield_date->CalTime.nDay,
                                                   (kal_int32) g_mmi_vjava_ui_datefield_date->vm_id);
            }

			mmi_java_ui_datefield_exit_screen(SCR_ID_JAVA_UI_DATEFIELD_DATE);
        }
        else if (g_mmi_vjava_ui_datefield_time)
        {
            if (g_mmi_vjava_ui_datefield_time->callback != NULL)
            {
                g_mmi_vjava_ui_datefield_time->callback(
                                                   KAL_FALSE,
                                                   g_mmi_vjava_ui_datefield_time->hour,
                                                   g_mmi_vjava_ui_datefield_time->minute,
                                                   g_mmi_vjava_ui_datefield_time->second,
                                                   g_mmi_vjava_ui_datefield_time->vm_id);
            }
		
			mmi_java_ui_datefield_exit_screen(SCR_ID_JAVA_UI_DATEFIELD_TIME);
    }
		
        
    //}
}


/*extern "C" kal_bool vapp_java_ui_is_datefield_active(void)
{
    if (g_mmi_vjava_ui_datefield_page)
    {
        return (kal_bool)g_mmi_vjava_ui_datefield_page->isActive();
    }

    return KAL_FALSE;
}*/

extern "C" void vapp_java_ui_datefield_exit()
{
	VFX_OBJ_CLOSE(g_mmi_vjava_datafield_ptr);
    
    VfxAppCatScr::deinitalize();

	g_mmi_vjava_ui_datefield_date = NULL;
    g_mmi_vjava_ui_datefield_time = NULL;

}

#endif /*__J2ME__*/

