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
 *  vapp_bt_send.h
 *
 * Project:
 * --------
 *  Cosmos
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_SEND_H__
#define __VAPP_BT_SEND_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "mmi_features.h"
#include "FileMgrGprot.h"
#include "BtcmSrvGprot.h"
#include "OppSrvGprot.h"
}

#ifdef __MMI_OPP_SUPPORT__

#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "Vfx_datatype.h"
#include "Vapp_bt_send_gprot.h"
#include "Vcp_global_popup.h"
#include "vapp_bt_page.h"
#include "vsrv_ncenter.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
// sending buffer
#ifdef __MMI_OPP_SUPPORT__
#define BUF_LENGTH                          OPPC_MAX_OBEX_PACKET_LENGTH
#else
#define BUF_LENGTH                          (0)
#endif


#define MMIOPP_MASK_CM_NOTIFY               0x00000001
#define MMIOPP_MASK_SDP_FORMAT              0x00000008
#define MMIOPP_MASK_FILE_TYPE               0x00000010
#define MMIOPP_MASK_ABORT_PRESS             0x00000004
#define MMIOPP_MASK_USB_PLUG_IND            0x00000020

#define BTSEND_PROG_UPD_DUR                 300
#define BTSEND_CALCU_SIZE                   1


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef void (*vapp_get_next_obj_callback) (void *);

/*
* app result enum
*/
enum BTSendResultEnum
{
    BTSEND_SUCCESS,
    BTSEND_FAIL,
    BTSEND_NO_INSTANCE,
    BTSEND_CONNECT_FAIL,
    BTSEND_NO_AVAIL_PRO,
    BTSEND_SELECT_DEVICE_FAIL,
    BTSEND_SERV_NOT_AVAILABLE,
    BTSEND_RESULT_DONE,
    BTSEND_RESULT_END
};

/*
* profile id enum
*/
enum BTSendingProfEnum
{
    BTSEND_PROF_OPP = 0x00000001,           // OPP
    BTSEND_PROF_BIP = 0x00000002            // BIP
};

/*
* profile function result event
*/
enum BTSendingProfEvtEnum
{
    BTSEND_PROF_SUCCESS,
    BTSEND_PROF_FORBIDDEN,
    BTSEND_PROF_BEGAIN_READY,
    BTSEND_PROF_SEND_SUCCESS,
    BTSEND_PROF_SEND_FAIL,
    BTSEND_PROF_SEND_END,
    BTSEND_PROF_CONNECT_FAIL,
    BTSEND_PROF_ABNORMAL_DONE,
    BTSEND_PROF_USB_UNAVAILABLE,
    BTSEND_PROF_BAD_OBJECT,
    BTSEND_PROF_DRM_PROHIB,
    BTSEND_PROF_DONE
};

 /***************************************************************************** 
 * Declare VappBTSendingPara class
 *****************************************************************************/
class VappBTSendingPara
{
// Variable
public:

/*---------------------------------------------------------------------------*
 * Function: cloneNameArray()
 * Date:Dec 21/2011
 * Description: alloc a new memory from parent to store the name array.
 *    
 * Parameters
 *    @aParent: the parent for alloc memory. 
 *    @aNameArray: the array to be stored.
 *---------------------------------------------------------------------------*/
	void cloneNameArray(VfxObject* aParent, VfxWChar** aNameArray);

/*---------------------------------------------------------------------------*
 * Function: clearTempFile()
 * Date:Feb/12/2012
 * Description: delete sending file if (m_option == VAPP_BT_SEND_DELETE_FILE)
 *    
 * Parameters
 *    @aOwner: the parent for alloc memory. 
 *---------------------------------------------------------------------------*/
	void clearTempFile(VfxObject* aOwner);

/*---------------------------------------------------------------------------*
 * Function: releaseNameBuf()
 * Date:Feb/12/2012
 * Description: release name buff if(m_nameArray != NULL)
 *    
 *---------------------------------------------------------------------------*/
	void releaseNameBuf();
public:
    VfxU32 m_option;                          // if delete the sending file
    void* m_callback;                         // callback
    VfxU32    m_total;                        // total count of objects to be sent
    VfxWChar** m_nameArray;                   // the array of objects name
    void* m_appData;                          // app data, will be passed to the constructor of
    srv_bt_cm_bt_addr m_addr;                 // the device address
    VfxWChar m_sendFileName[SRV_FMGR_PATH_MAX_LEN + 1];
};

/***************************************************************************** 
 * Declare VappBTSendPreApp class
 *****************************************************************************/
class VappBTSendPreApp : public VfxCui
{
    VFX_DECLARE_CLASS(VappBTSendPreApp);
// Constructor / Destructor
public:

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    static void onUsbPlugIn();
    static VappBTSendPreApp* m_selfInst;
//Implementation
private:
    void errorHandle(BTSendResultEnum cod);
    VfxBool selectDevice();
    void selectDeviceHdlr(mmi_event_struct *evt);
    void startSendApp(mmi_event_struct *evt);
// Variable
private:
	VappBTSendingPara m_sendingPara;
	VfxBool m_needNotifyPhoneBook;
};

/***************************************************************************** 
 * Declare VappBTSendingProf class
 *****************************************************************************/
class VappBTSendingProf : public VfxObject
{
// Constructor / Destructor
public:

// Method
public:
    // before sending object, call this function
    virtual VfxBool sendBegin(srv_bt_cm_bt_addr *addr){return VFX_TRUE;}
    // send one object
    virtual void sendObject(VfxWChar *aFilePathAndName, VfxWChar* aFileName){}
    // when no more object to be sent or want to stop sending, call this function, and the caller should
    // not dye until receive the event of this function in normal case
    virtual void sendEnd(){}
    // connect indication event from service handler
    virtual void connectIndHandler(void *para){}
    // send indication event from service handler
    virtual void sendIndHandler(void *para){}
    // disconnect indication event from service handler
    virtual void disconnIndHandler(void *para){}
    virtual void getCurrentProgess(srv_opp_obj_info_struct *aObjInfo){}
    VfxU32 objAvailable(VfxU16 * aFile);

// Implementation
public:
    virtual void sendCancel(){}

// Variable
public:
    VfxU8  m_buff[BUF_LENGTH];
    VfxS32  m_srvHd;
    VfxU32 m_flag;
    VfxBool m_disFromCM;
    VfxS32 m_reason;
    VfxSignal1 <VfxU32 /* event id */> m_signal;
};

#ifdef __MMI_OPP_SUPPORT__
/***************************************************************************** 
 * Declare VappBTOPPClient class
 *****************************************************************************/
class VappBTOPPClient : public VappBTSendingProf
{
// Constructor / Destructor
public:
    virtual ~VappBTOPPClient()
    {
        m_inst = NULL;
        srv_opp_close(m_srvHd);
    }
// Method
public:
    // handle the event from OPP service
    static VfxS32 eventHandler(VfxS32 hd, VfxU32 eventId, void *para);
    virtual VfxBool sendBegin(srv_bt_cm_bt_addr *addr);
    virtual void sendObject(VfxWChar *aFilePathAndName, VfxWChar* aFileName);
    virtual void sendEnd();
    virtual void connectIndHandler(void *para);
    virtual void sendIndHandler(void *para);

/*---------------------------------------------------------------------------*
 * Function: getCurrentProgess()
 * Date:Dec 22/2011
 * Description: virtual function from VappBTSendingProf, for supplying sending Progess.
 *    
 * Parameters
 *    @aObjInfo: give the progess information.
 *---------------------------------------------------------------------------*/
    virtual void getCurrentProgess(srv_opp_obj_info_struct *aObjInfo);
    VfxBool isJarFile(VfxU16 *name, VfxU16 *path);
    virtual void sendCancel();

// Variable
public:
    static VappBTOPPClient* m_inst;      //save current object, now VappBTOPPClient only support one object
};

#endif

/***************************************************************************** 
 * Declare VappBTSendApp class
 *****************************************************************************/

/*
 * VappBTSendApp app class of BT sending.
 * EXAMPLE
 * <code>
 *   VfxAppLauncher::launch(
 *       VappBTSendingApp,
 *       VFX_OBJ_CLASS_INFO(VappBTSendingApp),
 *       GRP_ID_ROOT,
 *       para,
 *       sizeof(para)
 *       );
 * </code>
 */
class VappBTSendApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappBTSendApp);

// Method
public:
    // these three functions are for NCnter
    static void stopSending();
    static void onUsbPlugIn();
    static mmi_ret themeChangeHdr(mmi_event_struct *event);
    static void calculateSize();
	void recreateSendingPopup();
/*---------------------------------------------------------------------------*
 * Function: handleUpdateTimerEvent()
 * Date:Dec 23/2011
 * Description: update the progress bar, every second. 
 *    
 *---------------------------------------------------------------------------*/
	static void handleUpdateTimerEvent();

/*---------------------------------------------------------------------------*
 * Function: notifyOngoingCallback()
 * Date:Mar/22/2012
 * Description: NCenter2.0 cell clicked callback function.
 *    
 * Parameters
 *    @noti: 
 *    @intent: 
 *    @userData: 
 *    @userDataSize: 
 *---------------------------------------------------------------------------*/
	static void notifyOngoingCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize);

// override
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    void updateProgress(VfxBool aForceUpdate);
	using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
public:
	VfxWString m_fileName;                                      // the sending file name
	VfxWString m_persentStr;
    static VappBTSendApp *m_selfInst;
	
// Implementation
private:
	enum
	{
		VAPP_OPP_SENDING_OBJ,
		VAPP_OPP_SENDING_VCARD
	};
	
	enum
	{
		VAPP_OPP_UPDATE_FILE_NAME = 0x1,
		VAPP_OPP_UPDATE_PROCESSING = 0x2,
		VAPP_OPP_UPDATE_ALL = 0x3
	};
    // init app
    void initApp();
    // handle event from screen
    void scrSigHandler();
    // handle event from profile
    void profSigHandler(VfxU32 evt);
    // sending contral
    inline void sendObj();


/*---------------------------------------------------------------------------*
 * Function: paraseFileName()
 * Date:Dec 23/2011
 * Description: get the file name from full path name
 *    
 * Parameters
 *    @aFilePathAndName: the string of full path
 *    @return: the string of file name
 *---------------------------------------------------------------------------*/
	VfxWChar* paraseFileName(VfxWChar *aFilePathAndName);


/*---------------------------------------------------------------------------*
 * Function: notifyOngoingCell()
 * Date:Mar/21/2012
 * Description: notify sending process cell in NCenter2.0.
 *    
 *---------------------------------------------------------------------------*/
	void notifyOngoingCell();
	
/*---------------------------------------------------------------------------*
 * Function: updateOngoingCell()
 * Date:Mar/21/2012
 * Description: update the sending cell in NCenter.
 *    
 * Parameters
 *    @aUpdateType: VAPP_OPP_UPDATE_FILE_NAME: update name, 
 					    VAPP_OPP_UPDATE_PROCESSING: update process.
 					    VAPP_OPP_UPDATE_ALL: update name and process.
 *---------------------------------------------------------------------------*/
	void updateOngoingCell(VfxU32 aUpdateType);
	
/*---------------------------------------------------------------------------*
 * Function: removeOngoingCell()
 * Date:Mar/21/2012
 * Description: remove the sending cell from NCenter.
 *    
 *---------------------------------------------------------------------------*/
	static void removeOngoingCell();

    void sendCancel(VfxObject* obj, VfxFloat percent);
    void errorHandle(BTSendResultEnum cod);
    void composeStr();
    void showSendingPopup();
    void showConnPopup();
// Variable
public:
	VfxS32 m_currentPersent;
private:
	VfxS32 m_sendObjType; //VAPP_OPP_SENDING_OBJ if sending normal obj files, VAPP_OPP_SENDING_VCARD if sending vCards.
    VappBTSmallScr *m_mainScr;

	VappBTSendingPara m_sendingPara;
	VfxS32 m_sendFileCount;
	VfxS32 m_successSendCount;
	VfxS32 m_currentFileIndex;
	VfxS32 m_remainCaculCount;
	VfxU32 m_calculSize;
	VfxU32 m_sendedFilesSize;
	VfxU32 m_totalFileSize;
	VfxWChar * m_filePathAndName;

    VappBTSendingProf *m_profInst;
    VcpIndicatorPopup *m_indPopup;
    VcpIndicatorPopup *m_waitPopup;
    VfxBool  m_connectFail;
    VfxU32 m_sendTransFileBegin;
    VfxBool m_sendOOMExitFlag;
	VsrvNotificationOngoing* m_notify;
};

#endif // __MMI_OPP_SUPPORT__
#endif // __VAPP_BT_SEND_H__

