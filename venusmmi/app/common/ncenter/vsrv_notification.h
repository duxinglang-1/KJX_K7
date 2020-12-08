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
 *  vfx_ncenter.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


#ifdef __MMI_NCENTER_SUPPORT__


#ifndef __VSRV_NOTIFICATION_H__
#define __VSRV_NOTIFICATION_H__

#include "vsrv_ndeclaration.h"
#include "vfx_uc_include.h"
#include "vfx_container.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"



/***************************************************************************** 
 * define
 *****************************************************************************/

class VsrvNGroup;
class VsrvNotification;


/*
 * prototype of intent callback 
 */ 
typedef void (*VsrvNitentFuncptr)(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);

/***************************************************************************** 
 * Class VsrvNotification
 *****************************************************************************/
/*
 * base class of notification
 */ 
class VsrvNotification : public VfxBase
{
// Constructor / Destructor
public:

    // <group DOM_NCenter_VsrvNotification_Constructor/Destructor>    
    // Constructor
    VsrvNotification();
    VsrvNotification(VsrvNGroup* group, VsrvNotificationId id);
    VsrvNotification(VsrvNGroupId gid, VsrvNotificationId id);    

    // <group DOM_NCenter_VsrvNotification_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNotification(){}; // user virtual destructor so derived classes' destructor will be called
   
/* DOM-NOT_FOR_SDK-BEGIN */

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public:
    //internal used
    void _init(VfxObject* objParent);
    void _deinit();

    VfxS32 getSerialNum() { return m_serialNum; }

/* DOM-NOT_FOR_SDK-END */

// Override
public:    
    // <group DOM_NCenter_VsrvNotification_Overridable>
    // Return the notification type
    // RETURNS: VSRV_NOTIFICATION_TYPE_BASE
    virtual VsrvNotificationType getType() { return VSRV_NOTIFICATION_TYPE_BASE; }    
    

    // <group DOM_NCenter_VsrvNotification_Overridable>
    // process intent 
    virtual void processIntent(VsrvNIntent intent);

//Method    
public:
    
    // <group DOM_NCenter_VsrvNotification_Method>
    // notify this notification when all data have been ready
    void notify();

    // <group DOM_NCenter_VsrvNotification_Method>
    // get group of this notification
    // RETURNS: NULL if no group
    VsrvNGroup* getGroup() const{ return m_group; }

    // <group DOM_NCenter_VsrvNotification_Method>
    // get group ID of the group of this notification
    // RETURNS: VSRV_NGROUP_INVALID_ID if no group id
	VsrvNGroupId getGroupId() const { return m_gid; }
    
    // <group DOM_NCenter_VsrvNotification_Method>
    // get noti ID
    // RETURNS: VSRV_NOTIFICATION_INVALID_ID if no id
    VsrvNotificationId getId() const { return m_id; };

    // <group DOM_NCenter_VsrvNotification_Method>
    // set Time Stamp
	void setTimeStamp(VfxDateTime timeStamp) { m_timeStamp = timeStamp; setIsStable(VFX_FALSE);};    

    // <group DOM_NCenter_VsrvNotification_Method>
    // get Time Stamp
    // RETURNS: time stamp 
	VfxDateTime getTimeStamp() const { return m_timeStamp; }

    // <group DOM_NCenter_VsrvNotification_Method>
    // help function to set current time stamp
	void setCurrentTime() { m_timeStamp.setCurrentTime(); };    

    // <group DOM_NCenter_VsrvNotification_Method>
    // set intent callback, this callback is used for you to process intent 
    void setIntentCallback(VsrvNitentFuncptr callback, void *userData = NULL, VfxU32 userDataSize = 0);

    // <group DOM_NCenter_VsrvNotification_Method>
    // get the userdata for your intent callback
    // RETURNS: userata for your intent callback
    void* getUserData() { return m_userData; };

    // <group DOM_NCenter_VsrvNotification_Method>
    // get the userdata size for your intent callback
    // RETURNS: userata size for your intent callback
    VfxU32 getUserDataSize() { return m_userDataSize; };        

    // <group DOM_NCenter_VsrvNotification_Method>
    // help function to set auto close flag
    void setAutoClose(VfxBool autoClose, VfxU32 flag = VSRV_NOTIFICATION_FLAG_AUTO_CLOSE) { setFlag(flag, autoClose); }
    

    // <group DOM_NCenter_VsrvNotification_Method>
    // help function to get auto close flag status
    // RETURNS: VFX_TRUE if the auto close flag is on
	VfxBool getAutoClose(VfxU32 flag) { return m_flag & flag ? VFX_TRUE : VFX_FALSE; }

    // <group DOM_NCenter_VsrvNotification_Method>
    // help function to set auto launch flag   
    void setAutoLaunch(VfxBool autoLaunch) { setFlag(VSRV_NOTIFICATION_FLAG_AUTO_LAUNCH, autoLaunch); }

    // <group DOM_NCenter_VsrvNotification_Method>
    // help function to get auto launch status
    // RETURNS: VFX_TRUE if the auto launch is on    
    VfxBool getAutoLaunch() { return m_flag & VSRV_NOTIFICATION_FLAG_AUTO_LAUNCH ? VFX_TRUE : VFX_FALSE; }

    // <group DOM_NCenter_VsrvNotification_Method>
    // check the notification is notified or not
    // RETURNS: VFX_TRUE if notified (this->notify())
    VfxBool getIsStable() { return m_flag & VSRV_NOTIFICATION_FLAG_STABLE ? VFX_TRUE : VFX_FALSE;};

    // <group DOM_NCenter_VsrvNotification_Method>
    // set Flags
    void setFlag(VfxU32 flag, VfxBool on);        

    // <group DOM_NCenter_VsrvNotification_Method>
    // get Flags
    // RETURNS: flags of this notification
	VfxU32 getFlag() const { return m_flag; }	

    // <group DOM_NCenter_VsrvNotification_Method>
    // get previous notification in the same group, the order is sorted by timestamp
    // RETURNS: NULL if no suitable notification
    VsrvNotification* getPrevious();

    // <group DOM_NCenter_VsrvNotification_Method>
    // get next notification in the same group, the order is sorted by timestamp
    // RETURNS: NULL if no suitable notification
    VsrvNotification* getNext();

        
// Method
protected:
    void setIsStable(VfxBool isStable);
    void setGroup(VsrvNGroup *group);
    void _setFlag(VfxU32 flag, VfxBool on); //internal used       



// Variable
protected:
    VfxObject *m_parentObj;
    VsrvNGroup *m_group;    
    VfxU32 m_flag;

private:

    VsrvNotificationId m_id;  
    VsrvNGroupId m_gid;  

    VfxDateTime m_timeStamp;


    
    VsrvNitentFuncptr m_callback;
    void *m_userData;
    VfxU32 m_userDataSize;


    VfxBool m_isOnDeinit;    

    VfxS32 m_serialNum;

    friend class VsrvNCenter;
    friend class VsrvNGroup;

};


/***************************************************************************** 
 * Class VsrvNotificationEvent
 *****************************************************************************/
/*
 * Event notification, there are 1 icon and 2 string
 */  
class VsrvNotificationEvent : public VsrvNotification
{
// Constructor / Destructor
public:

    // <group DOM_NCenter_VsrvNotificationEvent_Constructor/Destructor>    
    // Constructor
    VsrvNotificationEvent(){};
    VsrvNotificationEvent(VsrvNGroup* group, VsrvNotificationId id) : VsrvNotification(group, id){};
    VsrvNotificationEvent(VsrvNGroupId gid, VsrvNotificationId id) : VsrvNotification(gid, id){};

    // <group DOM_NCenter_VsrvNotificationEvent_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNotificationEvent(){};

// Override
public:

    // <group DOM_NCenter_VsrvNotificationEvent_Overridable>
    // Return the notification type
    // RETURNS: VSRV_NOTIFICATION_TYPE_EVENT
    virtual VsrvNotificationType getType() { return VSRV_NOTIFICATION_TYPE_EVENT; }

// Method
public:  
    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // set icon
    void setIcon(VfxImageSrc icon) { m_icon = icon; setIsStable(VFX_FALSE); }        

    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // get icon
    // RETURNS: VfxImageSrc of the icon
    VfxImageSrc getIcon() { return m_icon; }            

    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // set main text
    void setMainText(VfxWString main) { m_mainText = main; setIsStable(VFX_FALSE); }        

    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // get main text
    // RETURNS: VfxWString of main text
    VfxWString getMainText() { return m_mainText; }            

    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // set sub text    
    void setSubText(VfxWString sub) { m_subText = sub; setIsStable(VFX_FALSE);}        

    // <group DOM_NCenter_VsrvNotificationEvent_Method>
    // get sub text
    // RETURNS: VfxWString of sub text    
    VfxWString getSubText() { return m_subText; }        

// Variable
private:

    VfxImageSrc m_icon;
    VfxWString m_mainText;
    VfxWString m_subText;      

};


/***************************************************************************** 
 * Class VsrvNotificationOngoing
 *****************************************************************************/
/*
 * Ongoing notification, there are 1 icon and 3 string
 */  
class VsrvNotificationOngoing : public VsrvNotification
{
// Constructor / Destructor
public:
    // <group DOM_NCenter_VsrvNotificationOngoing_Constructor/Destructor>    
    // Constructor
	VsrvNotificationOngoing();
	VsrvNotificationOngoing(VsrvNGroup* group, VsrvNotificationId id);
	VsrvNotificationOngoing(VsrvNGroupId gid, VsrvNotificationId id);

    // <group DOM_NCenter_VsrvNotificationOngoing_Constructor/Destructor>    
    // Destructor    
    virtual ~VsrvNotificationOngoing(){};

// Override
public:

    // <group DOM_NCenter_VsrvNotificationOngoing_Overridable>
    // Return the notification type
    // RETURNS: VSRV_NOTIFICATION_TYPE_ONGOING
    virtual VsrvNotificationType getType() { return VSRV_NOTIFICATION_TYPE_ONGOING; }

// Method
public:   

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // set icon
    void setIcon(VfxImageSrc icon) { m_icon = icon; setIsStable(VFX_FALSE); }        

    
    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // get icon
    // RETURNS: VfxImageSrc of the icon
    VfxImageSrc getIcon() { return m_icon; }            

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // set main text
    void setMainText(VfxWString main) { m_mainText = main; setIsStable(VFX_FALSE); }        


    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // get main text
    // RETURNS: VfxWString of main text    
    VfxWString getMainText() { return m_mainText; }         

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // set sub text        
    void setSubText(VfxWString sub) { m_subText = sub; setIsStable(VFX_FALSE);}        

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // get sub text
    // RETURNS: VfxWString of sub text        
    VfxWString getSubText() { return m_subText; }        

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // set question text for the confirm popup
    void setQuestionText(VfxWString question) { m_questionText = question; setIsStable(VFX_FALSE);}        

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // get question text
    // RETURNS: VfxWString of question text        
    VfxWString getQuestionText() { return m_questionText; }        
  

// Variable
private:

    VfxImageSrc m_icon;
    VfxWString m_mainText;
    VfxWString m_subText;   
    VfxWString m_questionText;     
 

};



/***************************************************************************** 
 * Class VsrvNotificationCustom
 *****************************************************************************/
/*
 * Custom notification, add class info of your custom view
 */  
class VsrvNCell;

class VsrvNotificationCustom : public VsrvNotification
{
// Constructor / Destructor
public:
    // <group DOM_NCenter_VsrvNotificationCustom_Constructor/Destructor>    
    // Constructor
	VsrvNotificationCustom();
	VsrvNotificationCustom(VsrvNGroup* group, VsrvNotificationId id);
	VsrvNotificationCustom(VsrvNGroupId gid, VsrvNotificationId id);

    // <group DOM_NCenter_VsrvNotificationCustom_Constructor/Destructor>    
    // Destructor    
    virtual ~VsrvNotificationCustom(){};

/* DOM-NOT_FOR_SDK-BEGIN */

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

/* DOM-NOT_FOR_SDK-END */
    

public:
    // <group DOM_NCenter_VsrvNotificationCustom_Overridable>
    // Return the notification type
    // RETURNS: VSRV_NOTIFICATION_TYPE_CUSTOM
    virtual VsrvNotificationType getType() { return VSRV_NOTIFICATION_TYPE_CUSTOM; }
    
    // <group DOM_NCenter_VsrvNotificationCustom_Overridable>
    // process intent    
    virtual void processIntent(VsrvNIntent intent);  

// Method
public:   
    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // set height of your custom view
    void setHeight(VfxS32 height){ m_height = height; setIsStable(VFX_FALSE);}
    
    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // get height of your custom view
    // RETURNS: height of your custom view
    VfxS32 getHeight(){ return m_height; }  

    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // add class info for your custom view
    // RETURNS: VFX_TRUE if add sucessfully
    VfxBool addCustomViewInfo(VfxClassInfo* classInfo, VsrvNViewerType supported, void* viewData = NULL, VfxU32 viewDataSize = 0);

    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // remove class info for your custom view    
    // RETURNS: VFX_TRUE if remove sucessfully
    VfxBool removeCustomViewInfo(VsrvNViewerType supported);

    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // create class view
    // RETURNS: class view from the suitable class info
    VsrvNCell* createView(VsrvNViewerType viewer, VfxObject* objParent);

    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // set category 
    void setCategory(VsrvNotificationCustomCategory category);

    // <group DOM_NCenter_VsrvNotificationCustom_Method>
    // get category
    // RETURNS: category 
    VsrvNotificationCustomCategory getCategory() { return m_category; };    


// Variable
private:       

    struct CustomViewInfo
    {
        VfxClassInfo* classInfo;
        VsrvNViewerType viewers;   
        void* viewData;
        VfxU32 viewDataSize;                
    };

    VfxList <CustomViewInfo> m_infos;
    
    VfxSignal4 <VsrvNotification*, VsrvNIntent, void*, VfxU32> m_signalIntent;
    VsrvNotificationCustomCategory m_category;
    VfxS32 m_height;

};



/***************************************************************************** 
 * Class VsrvNCell
 *****************************************************************************/
/*
 * base class for the custom view
 */  
class VsrvNCell : public VfxFrame
{
    VFX_DECLARE_CLASS(VsrvNCell);       

// Constructor / Destructor
public:
    // <group DOM_NCenter_VsrvNCell_Constructor/Destructor>    
    // Constructor
	VsrvNCell();

    // <group DOM_NCenter_VsrvNCell_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNCell(){};

/* DOM-NOT_FOR_SDK-BEGIN */
// Override
protected:
    virtual void onDeinit(){ onCloseView(); VfxFrame::onDeinit(); }
/* DOM-NOT_FOR_SDK-END */
       

//override
public:

    // <group DOM_NCenter_VsrvNCell_Overridable>
    // create your UI
    virtual void onCreateView(void* viewData, VfxU32 viewDataSize){}

    // <group DOM_NCenter_VsrvNCell_Overridable>
    // close your UI
    virtual void onCloseView(){}    

    // <group DOM_NCenter_VsrvNCell_Overridable>
    // process your intent
    virtual void onProcessIntent(VsrvNotification* noti, VsrvNIntent intent, void* viewData, VfxU32 viewDataSize){}


//Method
public:
    // <group DOM_NCenter_VsrvNCell_method>
    // set notification related to this custom view
    void setNotification(VsrvNotificationCustom* noti);

    // <group DOM_NCenter_VsrvNCell_method>
    // get notification related to this custom view    
    // RETURNS: NULL if no notification 
    VsrvNotificationCustom* getNotification();    

protected:
    VsrvNotificationCustom* m_noti;

};


/***************************************************************************** 
 * Class VsrvNGroup
 *****************************************************************************/
/*
 * base class of notification group
 */
class VsrvNGroup : public VfxBase
{
// Constructor / Destructor
public:
    // <group DOM_NCenter_VsrvNGroup_Constructor/Destructor>    
    // Constructor
	VsrvNGroup();
    VsrvNGroup(VsrvNGroupId id);

    // <group DOM_NCenter_VsrvNGroup_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNGroup(){}; // user virtual destructor so derived classes' destructor will be called


/* DOM-NOT_FOR_SDK-BEGIN */

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public:
    //internal used
    void _init(VfxObject* objParent);
    void _deinit(); 

    VsrvNGroup* getParentGroup() { return m_parentGroup; }
/* DOM-NOT_FOR_SDK-END */

public:    
    // <group DOM_NCenter_VsrvNGroup_Overridable>
    // Return the notification group type
    // RETURNS: VSRV_NGROUP_TYPE_BASE
    virtual VsrvNGroupType getType() { return VSRV_NGROUP_TYPE_BASE; }
   
// Method
public:

    // <group DOM_NCenter_VsrvNGroup_Method>
    // Get the head of list of all notificaion in this group
    // RETURNS: Iterator of notificaion
    const VfxList <VsrvNotification*>::It getNotifications() { return m_notis.begin(); }

    // <group DOM_NCenter_VsrvNGroup_Method>
    // Get id of this group
    // RETURNS: id of this group
    VsrvNGroupId getId() const { return m_id; }

    // <group DOM_NCenter_VsrvNGroup_Method>
    // add notification to this group
    // RETURNS: VFX_TRUE if add sucessfully
    VfxBool addNotification(VsrvNotification* noti);
    
    // <group DOM_NCenter_VsrvNGroup_Method>
    // remove notification from this group by its instance
    // RETURNS: VFX_TRUE if add sucessfully
    VfxBool removeNotification(VsrvNotification* noti);

    // <group DOM_NCenter_VsrvNGroup_Method>
    // remove notification from this group by its id
    // RETURNS: VFX_TRUE if add sucessfully
    VfxBool removeNotification(VsrvNotificationId id);        

    // <group DOM_NCenter_VsrvNGroup_Method>
    // query notification from this group by its id
    // RETURNS: NULL if not existing
    VsrvNotification* queryNotification(VsrvNotificationId id);        

    // <group DOM_NCenter_VsrvNGroup_Method>
    // get number of notificaions in this group
    // RETURNS: number of notificaions in this group
    VfxU32 getCount() { return m_notis.size(); }


    // <group DOM_NCenter_VsrvNGroup_Method>
    // set Time Stamp
	void setTimeStamp(VfxDateTime timeStamp) { m_timeStamp = timeStamp;};    

    // <group DOM_NCenter_VsrvNGroup_Method>
    // get Time Stamp
    // RETURNS: time stamp 
	VfxDateTime getTimeStamp() const { return m_timeStamp; }
  

// Variable
private:
    VsrvNGroupId m_id;
    VfxObject *m_parentObj;
    
    VfxDateTime m_timeStamp;
    
    VsrvNGroup *m_parentGroup;

    VfxBool m_isOnDeinit;
//    VsrvNGroup *m_firstChildGroup;
//    VsrvNGroup *m_lastChildGroup; 
//    VsrvNGroup *m_prevGroup;      
//    VsrvNGroup *m_nextGroup;      

    VfxList <VsrvNotification*> m_notis;

    friend class VsrvNCenter;
    friend class VsrvNotification;

};


/***************************************************************************** 
 * Class VsrvNGroupSingleTitle
 *****************************************************************************/
/*
 * notification group with single title
 */
class VsrvNGroupSingleTitle : public VsrvNGroup
{
// Constructor / Destructor
public:
    // <group DOM_NCenter_VsrvNGroupSingleTitle_Constructor/Destructor>    
    // Constructor
	VsrvNGroupSingleTitle() {};
    VsrvNGroupSingleTitle(VsrvNGroupId id) : VsrvNGroup(id) {}

    // <group DOM_NCenter_VsrvNGroupSingleTitle_Constructor/Destructor>    
    // Destructor
    virtual ~VsrvNGroupSingleTitle(){};

// Override
public:
    // <group DOM_NCenter_VsrvNGroup_Overridable>
    // Return the notification group type
    // RETURNS: VSRV_NGROUP_TYPE_SINGLE_TITLE
    virtual VsrvNGroupType getType() { return VSRV_NGROUP_TYPE_SINGLE_TITLE; }

   
// Method
public:
    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // set title
    void setTitle(VfxWString title) { m_title = title; }

    // <group DOM_NCenter_VsrvNotificationOngoing_Method>
    // get title
    // RETURNS: VfxWString of title
    VfxWString getTitle() { return m_title; }

private:
    VfxWString m_title;

};




#endif /* __VSRV_NOTIFICATION_H__ */

#endif /* __MMI_NCENTER_SUPPORT__ */
