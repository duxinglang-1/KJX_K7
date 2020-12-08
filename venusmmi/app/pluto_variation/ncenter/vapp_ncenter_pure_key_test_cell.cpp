/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_ncenter_test_cell.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_ncenter_pure_key_test_cell.h"

#ifdef __VAPP_NCENTER_UNIT_TEST__

extern "C"
{
#include "Unicodexdcl.h"    /* for mmi_ucs2ncpy */
#include "GlobalResDef.h"

}

/***************************************************************************** 
 * Class VsrvNCellTest    
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VsrvNCellTest", VsrvNCellTest, VsrvNCell);

void VsrvNCellTest::onCreateView(void* viewData, VfxU32 viewDataSize)
{
    VsrvNCell::onCreateView(viewData, viewDataSize);    
    setSize(LCD_WIDTH, 200);            
    setBgColor(VFX_COLOR_OLIVE); 

    VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
    m_frame1->setRect(10, 10, 30, 30);    
    VfxColor *color = (VfxColor*) viewData;
    m_frame1->setBgColor(color->value);        

    VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
    m_frame2->setRect(50, 10, 30, 30);    
    m_frame2->setBgColor(VFX_COLOR_RED);        

    VFX_OBJ_CREATE(m_frame3, VfxFrame, this);
    m_frame3->setRect(90, 10, 30, 30);    
    m_frame3->setBgColor(VFX_COLOR_GREEN);       
}

void VsrvNCellTest::onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize)
{
    if (intent.type == VSRV_NINTENT_TYPE_ENTERED)
    {
        VFX_OBJ_CREATE(m_frame4, VfxFrame, this);
        m_frame4->setRect(130, 10, 60, 60);    
        m_frame4->setBgColor(VFX_COLOR_YELLOW);        
    }
    
}


/***************************************************************************** 
 * Class VappNCenterGridCell 
 *****************************************************************************/

VfxBool g_grid_setting[NCENTER_GRID_ITEMS_AMOUNT]={0};

void VappMessageIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
/*   TRACE(("\n=====MessageCallback=======\n"));
     TRACE(("=====Noti Id====== %d\n", noti->getId()));

         
     if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
         TRACE(("=====LAUNCH=====\n"));
     }
     else if (intent.type == VSRV_NINTENT_TYPE_ENTER)
     {
         TRACE(("=====ENTER=====\n"));     
     }
     else if (intent.type == VSRV_NINTENT_TYPE_TAP)
     {        
         TRACE(("=====TAP=====\n"));     
         VappNCenter *nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
         nc->requestLeave(noti);
     }
     else if (intent.type == VSRV_NINTENT_TYPE_AFTER_REQUEST_LEAVE)
     {
         TRACE(("=====REQ LEAVE====\n"));     
         VappMsgLaunchStruct param;
         param.mode = VAPP_MSG_LAUNCH_INBOX;
         vapp_msg_launch(&param, sizeof(param));      
         VSRV_NOTIFICATION_CLOSE(noti);
     } */
}



void VappFMRadioIntentCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
/*   TRACE(("\n=====FMRadioCALLBACK=======\n"));
     if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
     {
         TRACE(("=====TERMINATE=====\n"));
     }  
     else if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
         TRACE(("=====LUANCH=====\n"));
     }
*/
}

void vapp_message_intent_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    
}



VappNCenterGridCell::VappNCenterGridCell()
{};



void VappNCenterGridCell::onInit()
{
    VfxControl::onInit();
    
    setAutoAnimate(VFX_TRUE);

    VfxS32 i;
    for (i = 0; i < NCENTER_GRID_ITEMS_AMOUNT; i++)
    {
        VFX_OBJ_CREATE(m_items[i], VfxFrame, this);
        m_items[i]->setAnchor(0.5f, 0.5f);
        m_items[i]->setAutoAnimate(VFX_TRUE);
    }   

    VfxU16 height = layoutItems(getParentFrame()->getParentFrame()->getSize().width);
    setSize(getParentFrame()->getParentFrame()->getSize().width ,height);    
}


VfxU16 VappNCenterGridCell::layoutItems(VfxU16 width)
{

    VfxU16 cols = NCENTER_GRID_ITEMS_AMOUNT;
    VfxS32 rows = (NCENTER_GRID_ITEMS_AMOUNT + cols - 1) / cols;    
    VfxU16 height = rows * width / NCENTER_GRID_ITEMS_AMOUNT;

    VfxU16 item_w = width / NCENTER_GRID_ITEMS_AMOUNT;
    VfxU16 item_h = width / NCENTER_GRID_ITEMS_AMOUNT;

    VfxPoint firstItemPos;
    firstItemPos.x = item_w / 2;
    firstItemPos.y = item_h / 2;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);


    VfxPoint leftItemPos = firstItemPos;
    VfxS32 i, j;
    for (j = 0; j < rows; j++)
    {
        VfxPoint itemPos = leftItemPos;
        for(i = 0; i < cols; i++)
        {
            VfxS16 index = j * cols + i;
            m_items[index]->setPos(itemPos);
            m_items[index]->setSize(item_w, item_h);
            if(g_grid_setting[index])
                m_items[index]->setBgColor(VFX_COLOR_GREY);
            else
                m_items[index]->setBgColor(VFX_COLOR_SILVER);
            m_items[index]->setBorderColor(VFX_COLOR_BLACK); 
            m_items[index]->setBorderWidth(1);            

            itemPos.x += item_w;
        }
        leftItemPos.y += item_h;
    }
    VfxAutoAnimate::commit();

    return height;
}


VfxS16 VappNCenterGridCell::findHitItem(const VfxPenEvent &event) const
{
    VfxU8 i;
    for(i = 0; i < NCENTER_GRID_ITEMS_AMOUNT; i++)
    {
        if (m_items[i]->containPoint(event.getRelPos(m_items[i])))
        {
            return i;
        }
    }
    return -1;
}



VfxBool VappNCenterGridCell::onPenInput(VfxPenEvent &event)
{

    if(event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxS16 hitIndex = findHitItem(event);
        if (hitIndex >= 0)
        {
            if(g_grid_setting[hitIndex])
            {                
                m_items[hitIndex]->setBgColor(VFX_COLOR_SILVER);
                g_grid_setting[hitIndex] = VFX_FALSE;

                switch(hitIndex)
                {
                    case 0:
                    {         
                        for (VfxS32 i = 1; i < 32; ++i)
                        {
                            VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)0, 1000 + i);
                        }

                        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)0, 3);
                        //VSRV_NGROUP_CLOSE_EX(0);
                        break;
                    }
                    case 1:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (0));
                        group->setTitle(VFX_WSTR("Message")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 0, 1));                       
                        VfxS32 t = 1213465465;
                        noti->setIntentCallback(VappMessageIntentCallback, &t, sizeof(VfxS32));
                        noti->setMainText(VFX_WSTR("Failed to send Failed to send"));
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();
                        dateTime.setTime(2, 1, 1);
                        noti->setTimeStamp(dateTime);
                        noti->notify();                        
                        break;
                    }
                    case 2:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (0));
                        group->setTitle(VFX_WSTR("Message1")); 
                        VsrvNotificationOngoing *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationOngoing, ((VsrvNGroup*) group, 2));                        
                        noti->setMainText(VFX_WSTR("Message Out"));
                        noti->setSubText(VFX_WSTR("Tap to Clean"));
                        noti->notify();
                        break;
                    }
                    case 3:
                    {
                        VsrvNGroup *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroup, (4));                                            
                        VsrvNotificationCustom* ncust;
                        VSRV_NOTIFICATION_CREATE_EX(ncust, VsrvNotificationCustom, ((VsrvNGroup*) group, 0));

                        VfxDateTime dateTime;
                        VfxColor color(VFX_COLOR_BLUE);
                        ncust->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VsrvNCellTest), VSRV_NVIEWER_TYPE_GENERAL, &color, sizeof(VfxColor));
                        ncust->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT);
                        ncust->notify();   
                        
                        break;
                    }
                    case 4:
                    {
                        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)5, 0);
                        break;
                    }
                    case 5:
                    {                        
                        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)1, 0);
                        break;
                    }
                    case 6:
                    {
                        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)2, 0);
                        break;
                    }
                    case 7:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (3));
                        group->setTitle(VFX_WSTR("Email")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 3, 0));
                        noti->setMainText(VFX_WSTR("Failed to refresh 1"));
                        noti->setSubText(VFX_WSTR("Tap to refresh again"));
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();
                        dateTime.setTime(5, 1, 1);
                        noti->setTimeStamp(dateTime);
                        noti->notify();
                        break;
                    }
                    case 8:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (3));
                        group->setTitle(VFX_WSTR("Email")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 3, 1));
                        noti->setMainText(VFX_WSTR("Email Full 2"));
                        noti->setSubText(VFX_WSTR("Tap to clean"));
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();
                        dateTime.setTime(1, 1, 1);
                        noti->setTimeStamp(dateTime);
                        noti->notify();
                        break;
                    }
                    case 9:
                    {
                        
                        break;
                    }

                    default:
                        break;
                }
            }
            else
            {
                m_items[hitIndex]->setBgColor(VFX_COLOR_GREY);
                g_grid_setting[hitIndex] = VFX_TRUE;

                switch(hitIndex)
                {
                    case 0:
                    {
                        for (VfxS32 i = 1; i < 32; ++i)
                        {
                            VsrvNGroupSingleTitle *group = NULL;
                            VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (0));
                            group->setTitle(VFX_WSTR("Message"));                                       
                            VsrvNotificationEvent *noti = NULL;
                            VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*) group, 1000 + i));
                            
                            VfxS32 t = 1000000000;
//                            noti->setIntentCallback(VappMessageIntentCallback, &t, sizeof(VfxS32));                    
                            vsrv_ncenter_set_notification_intent_callback(noti, vapp_message_intent_callback, &t, sizeof(VfxS32));



                            noti->setMainText(VFX_WSTR("Unread messages"));
                            noti->setSubText(VFX_WSTR("2 unread messages"));                    
                            noti->setIcon(VfxImageSrc(IMG_GLOBAL_L1));
                            
                            VfxDateTime dateTime;
                            dateTime.setCurrentTime();
                            dateTime.setTime(3, i, i);
                            noti->setTimeStamp(dateTime); 
                            noti->notify();                    

                        }

                        vsrv_ngroup_handle ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, 0);
                        vsrv_notification_handle nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, 3);
                        
                        WCHAR ctext[20];
                        mmi_wcscpy(ctext, (WCHAR *)L"Message");    
                        vsrv_ncenter_set_ngroup_title(ghandle, ctext);
                        
                        mmi_wcscpy(ctext, (WCHAR *)L"C_MAIN_TEXT");
                        vsrv_ncenter_set_notification_maintext(nhandle, ctext);
                        
                        mmi_wcscpy(ctext, (WCHAR *)L"C_SUB_TEXT");
                        vsrv_ncenter_set_notification_subtext(nhandle, ctext);
                        
                        WCHAR cbuffer[20];
                        vsrv_ncenter_get_notification_maintext(nhandle, cbuffer, 20);
                        
                        vsrv_ncenter_notify_notification(nhandle);   
                        
                        break;
                    }
                    case 1:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (0));
                        group->setTitle(VFX_WSTR("Message")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 0, 1));                       
                        VfxS32 t = 1213465465;
                        noti->setIntentCallback(VappMessageIntentCallback, &t, sizeof(VfxS32));
                        noti->setMainText(VFX_WSTR("Failed to send Failed to send"));
                        //noti->setSubText(VFX_WSTR("failed failed failed"));
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();
                        dateTime.setDate(2013,5,1);
                        noti->setTimeStamp(dateTime);
                        noti->notify();

                          
                        
                        break;
                    }
                    case 2:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (0));
                        group->setTitle(VFX_WSTR("Message")); 
                        VsrvNotificationOngoing *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationOngoing, ((VsrvNGroup*) group, 2));                        
                        noti->setMainText(VFX_WSTR("Message Full"));
                        noti->setSubText(VFX_WSTR("Tap to Clean"));
                        noti->setQuestionText(VFX_WSTR("Clean Clean"));
                        noti->notify();
                        break;                        
                    }
                    case 3:
                    {       
                        VsrvNGroup *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroup, (4));                                            
                        VsrvNotificationCustom* ncust;
                        VSRV_NOTIFICATION_CREATE_EX(ncust, VsrvNotificationCustom, ((VsrvNGroup*) group, 0));

                        VfxDateTime dateTime;
                        VfxColor color(VFX_COLOR_BLUE);
                        ncust->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VsrvNCellTest), VSRV_NVIEWER_TYPE_GENERAL, &color, sizeof(VfxColor));
                        ncust->setCategory(VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING);
                        ncust->notify();   
                        break;                        
                    }
                    case 4:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (5));
                        group->setTitle(VFX_WSTR("Music Player"));                         
                        VsrvNotificationCustom* ncust;
                        VSRV_NOTIFICATION_CREATE_EX(ncust, VsrvNotificationCustom, ((VsrvNGroupId) 5, 0));
                        // VSRV_NOTIFICATION_CREATE_EX(ncust, VsrvNotificationCustom, ((VsrvNGroupId) 1, 3)); //ASSERT: recreate but use different class

                        VfxColor color(VFX_COLOR_PURPLE);
                        ncust->addCustomViewInfo(VFX_OBJ_CLASS_INFO(VsrvNCellTest), VSRV_NVIEWER_TYPE_GENERAL, &color, sizeof(VfxColor));
                        ncust->notify();
                        
                        break;
                    }
                    case 5:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (1));
                        group->setTitle(VFX_WSTR("FM Radio"));               
                        VsrvNotificationOngoing *nong= NULL;
                        VSRV_NOTIFICATION_CREATE_EX(nong, VsrvNotificationOngoing, ((VsrvNGroup*) group, 0));
                        nong->setIntentCallback(VappFMRadioIntentCallback);    
                        nong->setMainText(VFX_WSTR("My Favorite"));
                        nong->setSubText(VFX_WSTR("Kiss 99.9"));    
                        nong->setQuestionText(VFX_WSTR("Terminate FM Radio"));
                        nong->notify();                        
                        break;
                    }
                    case 6:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (2));
                        group->setTitle(VFX_WSTR("Download Agent"));
                        VsrvNotificationOngoing *nong= NULL;
                        VSRV_NOTIFICATION_CREATE_EX(nong, VsrvNotificationOngoing, ((VsrvNGroupId) 2, 0));
                        nong->setMainText(VFX_WSTR("Downloading"));
                        nong->setSubText(VFX_WSTR("xcxcxcxcxsadfsdfsd"));   
                        nong->setQuestionText(VFX_WSTR("Terminate Download Agent?"));
                        nong->notify();
                        
                        break;
                    }
                    case 7:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (3));
                        group->setTitle(VFX_WSTR("Email")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 3, 0));
                        noti->setMainText(VFX_WSTR("Failed to refresh"));
                        noti->setSubText(VFX_WSTR("Tap to refresh again")); 
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();                    
                        noti->setTimeStamp(dateTime);                        
                        noti->notify();
                        break;
                    }
                    case 8:
                    {
                        VsrvNGroupSingleTitle *group = NULL;
                        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (3));
                        group->setTitle(VFX_WSTR("Email")); 
                        VsrvNotificationEvent *noti = NULL;
                        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroupId) 3, 1));
                        noti->setMainText(VFX_WSTR("Email Full"));
                        noti->setSubText(VFX_WSTR("Tap to clean")); 
                        VfxDateTime dateTime;
                        dateTime.setCurrentTime();                    
                        noti->setTimeStamp(dateTime);                        
                        noti->notify();
                        break;
                    }
                    case 9:
                    {                           
                        break;
                    }
                  
                    default:                        
                        break;
                }                
            }                              
        }   
    }
    
    return VFX_TRUE;

}

#endif
