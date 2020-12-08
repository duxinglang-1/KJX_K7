/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  vapp_screen_lock_cosmos_notification_cell.h
 *
 * Project:
 * --------
 *  COSMOS Screen Lock Notification Cell
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SCREEN_LOCK_COSMOS_NOTIFICATION_CELL_H__
#define __VAPP_SCREEN_LOCK_COSMOS_NOTIFICATION_CELL_H__

#include "vfx_uc_include.h"
#include "vcp_button.h"
#include "vcp_image_button.h"
#include "vcp_var_height_menu.h"
#include "vsrv_ncenter.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappScreenLockLiberateNotiPanel;
class VappScreenLockCosmosNotificationList;

// layout
#if defined(__MMI_MAINLCD_320X480__)  //HVGA

    // Event default cell
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH             (320)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT            (45) //real=45-4=41
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X            (10)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_WIDTH        (30)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_HEIGHT       (30)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X       (50)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH   (260)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_SIZE    (17)
    
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_X       (50)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_Y       (3)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_WIDTH   (183)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_SIZE    (14)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_X       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_Y       (6)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH   (73)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_SIZE    (14)

    // OnGoing default cell 
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH             (320)
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT            (45)

    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT             (24)

#elif defined(__MMI_MAINLCD_480X800__)  //WVGA

    // Event default cell
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH            (480)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT            (86)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X            (14)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_WIDTH        (35)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_HEIGHT       (35)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X       (67)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_Y       (7)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH   (399)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_SIZE    (30)
    
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_X       (67)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_Y       (10)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_WIDTH   (231)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_SIZE    (26)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_X       (14)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_Y       (10)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH   (131)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_SIZE    (26)

    // OnGoing default cell
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH             (480)
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT            (86)

    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_FONT_SIZE           VFX_FONT_DESC_VF_SIZE(21)
    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT             (35)    
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

    // Event default cell
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH             (240)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT            (38)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X            (5)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_WIDTH        (24)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_HEIGHT       (24)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X       (34)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH   (201)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_SIZE    (15)
    
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_X       (34)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_WIDTH   (137)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_SIZE    (12)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_X       (0)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_Y       (5)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH   (63)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_SIZE    (12)

    // OnGoing default cell
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH             (240)
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT            (38)

    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(12)
    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT             (20)
#else

    // Event default cell
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_WIDTH             (320)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_HEIGHT            (51)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_X            (10)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_WIDTH        (30)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_ICON_HEIGHT       (30)

    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_X       (50)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_WIDTH   (260)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_MAIN_TEXT_SIZE    (20)
    
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_X       (50)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_WIDTH   (183)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_SUB_TEXT_SIZE    (14)
    
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_X       (10)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_Y       (4)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_WIDTH   (73)
    #define VAPP_SCREEN_LOCK_NOTI_EVENT_CELL_RIGHT_TEXT_SIZE    (14)
    
    // OnGoing default cell
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_WIDTH             (320)
    #define VAPP_SCREEN_LOCK_NOTI_ONGOING_CELL_HEIGHT            (51)

    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_FONT_SIZE          VFX_FONT_DESC_VF_SIZE(12)
    #define VAPP_SCREEN_LOCK_NOTI_CAPTION_HEIGHT             (20)    
#endif

/***************************************************************************** 
 * Struct
 *****************************************************************************/

enum VappScreenLockCosmosNotificationCellType
{
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_HEADER,
    VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT,
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_ONGOING,        
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_CUSTOM,
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_END      				
};

struct VappScreenLockCosmosNotificationCellStruct
{
    VappScreenLockCosmosNotificationCellType type;
    VfxDateTime timeStamp;        
};


struct VappScreenLockCosmosNotificationGroupStruct
{
    VsrvNGroup *group;
    VfxDateTime groupTimeStamp;    
};

/***************************************************************************** 
 * Notification Panel Class
 *****************************************************************************/

class VappScreenLockLiberateNotiPanel : public VfxFrame
{
    // Constructor / Destructor
    public:
        // Default constructor
        VappScreenLockLiberateNotiPanel();

    // Override
    protected:
        virtual void onInit();
        virtual void onDeinit();

    // Method
    private:

        // Create the content of notification.
        void createNotiPanel();

        // Create list cell
        void onCreateContentView(
            VfxFrame* parent        // [IN] The parent frame of var_hight menu.
        );

        // Check if the notification is stable.
        VfxBool checkNotification(VsrvNotification *noti);

        void createCell(VsrvNotification *noti, VfxId refId, VfxBool addBeforeRef = VFX_FALSE);

        void closeCell(VsrvNotification *noti);    

        void onNotificationChanged(VsrvNotification* noti, VsrvNStatusType status);

        VfxBool checkIsTheSameType(VsrvNotification *noti, VappScreenLockCosmosNotificationCellStruct* data);

        // Check if the notification sent by spefic app.
        // In this case, the screen lock only shows the notification which sent by below apps
        // CALLLOG,EMAIL,MSG,SNS,MRE
        VfxBool checkAppID(VsrvNotification* noti);

    // Signal
    public:
        VfxSignal0 m_signalNotiChanged;
    
        //
        // The use of notify no notifications on list and therefore,
        // need to hide the notification panel & set the shadow of time area.
        //
        VfxSignal0 m_signalNotiEmpty;
    
    // Variable
    public:

        // To check if the notification panel is showed.
        VfxBool m_isNotiShowed;
            
        // To check if the notification panel is empty.
        VfxBool m_isNotiEmpty;
            
    private: 

        // The notification Panel
        //VfxFrame *m_notiPanel;

        // The list of notifications
        VappScreenLockCosmosNotificationList *m_list;

        // The count of events
        VfxS32 m_eventCount;
};


/***************************************************************************** 
 * Class
 *****************************************************************************/
/*
enum VappScreenLockCosmosNotificationCellType
{
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_HEADER,
    VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_EVENT,
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_ONGOING,        
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_CUSTOM,
	VAPP_SCREEN_LOCK_COSMOS_CELL_TYPE_END      				
};

struct VappScreenLockCosmosNotificationCellStruct
{
    VappScreenLockCosmosNotificationCellType type;
    VfxDateTime timeStamp;        
};


struct VappScreenLockCosmosNotificationGroupStruct
{
    VsrvNGroup *group;
    VfxDateTime groupTimeStamp;    
};*/


/***************************************************************************** 
 * Class VappScreenLockCosmosBaseCell
 *****************************************************************************/
    
class VappScreenLockCosmosBaseCell : public VfxControl
{
    // Constructor / Destructor
public:
    // Default constructor
    VappScreenLockCosmosBaseCell();   


// Override
protected:
    //virtual VfxBool onPenInput(VfxPenEvent & event);

// Method
public:
    void setNotification(VsrvNotification* noti);
    VsrvNotification* getNotification();    
    virtual void updateElements(){};

protected:
    VsrvNotification* m_noti;
    VfxS32 m_maxMoveOffset;
    
};

/***************************************************************************** 
 * Class VappScreenLockCosmosEventCell
 *****************************************************************************/

class VappScreenLockCosmosEventCell : public VappScreenLockCosmosBaseCell
{
    // Constructor / Destructor
public:
    // Default constructor
    VappScreenLockCosmosEventCell();   


// Override
protected:
    virtual void onInit();
   
// Method
public:
    virtual void updateElements();
    void setIcon(
        const VfxImageSrc &imgScr         // [IN] image
        )
    {
        if (m_icon && !imgScr.isNull())
        {
            m_icon->setImgContent(imgScr);
        }
    }
    
    void setMainText(
        const VfxWString &text            // [IN] text
        )
    {
        if (m_mainText)
        {
            m_mainText->setString(text);
        }
    }
    
    VfxWString getMainText() const
    {
        if (m_mainText)
        {
            return m_mainText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setSubText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_subText)
        {
            m_subText->setString(text);
        }
    }
    
    VfxWString getSubText() const
    {
        if (m_subText)
        {
            return m_subText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }

    void setRightText(
        const VfxWString &text          // [IN] text
        )
    {
        if (m_rightText)
        {
            m_rightText->setString(text);
        }
    }
    
    VfxWString getRightText() const
    {
        if (m_subText)
        {
            return m_subText->getString();
        }
        else
        {
            return VFX_WSTR_NULL;
        }
    }    

// Variable 
protected:
    VfxFrame *m_icon;
    VfxTextFrame *m_mainText;
    VfxTextFrame *m_subText;
    VfxTextFrame *m_rightText;
};


class VappScreenLockCosmosNotificationCell : public VcpVarHeightMenuCell
{

    
    // Constructor / Destructor
public:
    // Default constructor
    VappScreenLockCosmosNotificationCell(VcpMenuPos pos, VappScreenLockCosmosNotificationCellType type) : VcpVarHeightMenuCell(pos), m_type(type) {};

// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// method
public:
    void setContent(VfxFrame *);

    
// Variable 
protected:
    VappScreenLockCosmosNotificationCellType m_type;
    VfxWeakPtr <VfxFrame> m_content;    
};


/***************************************************************************** 
 * Class VappScreenLockCosmosNotificationList 
 *****************************************************************************/


class VappScreenLockCosmosNotificationList : public VcpVarHeightMenu 
{

// Constructor / Destructor
public:
    VappScreenLockCosmosNotificationList() : VcpVarHeightMenu(LAYOUT_NORMAL) {};

// Overridable
public:

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
    ) {return VFX_FALSE;}

// Override
public:
    
// Override
protected:

    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
   
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

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
#endif
};
#endif /* __VAPP_SCREEN_LOCK_COSMOS_NOTIFICATION_CELL_H__ */
