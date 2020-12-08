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
 * Jvm_comml.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define constances and enum values
 *   of JAL invocation by virtual com port related routines.
 *
 * Author:
 * -------
 * 
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
#include "jvm_vcomm.h"
#include "FileMgrSrvGProt.h"
#ifdef __JAVA_VIRTUAL_COMM__ 

kal_bool java_vcomm_opened = KAL_FALSE;
static vcomm_context_struct vport[MAX_VIRTUAL_COMM_PORT_SUPPORT];
static const kal_char endChar = '\r';
static const kal_char delimitChar = ':';
static const kal_char defaultResultPath[] = "\\javaTest\\";


static SessionPkg msg;
#define JAVA_VCOMM_MAX_BUFFER_SIZE (256)
/****************************************************************************
 * FUNCTION
 *  java_vcomm_open
 * DESCRIPTION
 *  This function is used to open the virtual com.
 *      
 *
 *  Return KAL_TRUE if success,  otherwise return KAL_FALSE.
 *  
 *
 * PARAMETERS
 * kal_int32  port
 * kal_uint8 *buffer
 * kal_uint16 len
 * RETURNS
 * kal_int32
 *****************************************************************************/

kal_bool 
java_vcomm_open(kal_uint32 port)
{
    if(port >= MAX_VIRTUAL_COMM_PORT_SUPPORT || vport[port].isOpened){/*opened*/
        return KAL_FALSE;
    }
    if(NULL != vport[port].receBuffer){
        jvm_free(vport[port].receBuffer);    
    }
    if(NULL != vport[port].sendBuffer){
        jvm_free(vport[port].sendBuffer);    
    }
    vport[port].port = port;
    vport[port].receBuffer = jvm_malloc(JAVA_VCOMM_MAX_BUFFER_SIZE);
    vport[port].sendBuffer= jvm_malloc(JAVA_VCOMM_MAX_BUFFER_SIZE);
    vport[port].isDataReady = KAL_FALSE;
    vport[port].isReceivedDown = KAL_FALSE;
    vport[port].sessionMode = SESSION_MODE_MESSAGE;
 
    vport[port].isOpened = KAL_TRUE;
    return KAL_TRUE;
}
/****************************************************************************
 * FUNCTION
 *  java_vcomm_read
 * DESCRIPTION
 *  This function is used to read data from virtual com opened by java_vcomm_open(kal_uint32 port).
 *      
 *
 *  Return the number  of data read java_vcomm_read.
 *  
 *
 * PARAMETERS
 * kal_int32  port
 * kal_uint8 *buffer
 * kal_uint16 len
 * RETURNS
 * kal_int32
 *****************************************************************************/
kal_int32 
java_vcomm_read(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len)
{
    kal_int32 length = 0;
    if(port >= MAX_VIRTUAL_COMM_PORT_SUPPORT || KAL_FALSE == vport[port].isOpened){/*no opened*/
        return -1;
    }
    if(vport[port].isDataReady){
        if(vport[port].currSendLen > len){
            length = len;
        }else{
            length = vport[port].currSendLen;

        }
        kal_mem_cpy(buffer,vport[port].sendBuffer,length);
        vport[port].isDataReady = KAL_FALSE;
        return length;
    }else{
        return 0;
    }
   
}
/****************************************************************************
 * FUNCTION
 *  java_l4c_send_at_cmd_req
 * DESCRIPTION
 *  Send the AT command request to L4C by message MSG_ID_TST_INJECT_STRING .
 *  
 * return 0 if no error, else error code
 * PARAMETERS
 * const kal_char  *pInATCmdStr
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
java_l4c_send_at_cmd_req(const kal_char  * pInATCmdStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32     len = 0;
    MYQUEUE    Message;
    java_l4c_inject_at_cmd_struct *ptrAtCmd = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL ==pInATCmdStr){
        return -1;
    }
    len = strlen(pInATCmdStr);
    if((JAVA_COMMAND_AT_MAX_LENGTH<= len)||(0>= len)){
        return -1;
    }
    ptrAtCmd = (java_l4c_inject_at_cmd_struct*) OslConstructDataPtr(sizeof(java_l4c_inject_at_cmd_struct));
    if(NULL == ptrAtCmd){
       return -1;
    }

    /*construct the AT command string */
    strcpy((kal_char*)ptrAtCmd->string, (const kal_char*)pInATCmdStr);

    Message.oslSrcId = MOD_J2ME;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_TST_INJECT_STRING;
    Message.oslDataPtr = (oslParaType*) ptrAtCmd;
    Message.oslPeerBuffPtr = NULL;
     
    OslMsgSendExtQueue(&Message);
    
    return 0;
}
/****************************************************************************
 * FUNCTION
 *  java_take_snapshot_req
 * DESCRIPTION
 *  Send the java command request to MMI by message MSG_ID_TST_INJECT_STRING .
 *  
 * return 0 if no error, else error code
 * PARAMETERS
 * const kal_char  *pInATCmdStr
 * RETURNS
 * kal_int32
 *****************************************************************************/
static kal_int32
java_take_snapshot_req(const kal_char  * pCmdStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32     len = 0;
    MYQUEUE    Message;
    tst_mmi_java_cmd_req_struct *ptrCmd = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL ==pCmdStr){
        return -1;
    }
    len = strlen(pCmdStr);
    if((JAVA_COMMAND_AT_MAX_LENGTH<= len)||(0>= len)){
        return -1;
    }
    ptrCmd = (tst_mmi_java_cmd_req_struct*) OslConstructDataPtr(sizeof(tst_mmi_java_cmd_req_struct));
    if(NULL == ptrCmd){
       return -1;
    }

    /*construct the AT command string */
    strcpy((kal_char*)ptrCmd->string, (const kal_char*)pCmdStr);

    Message.oslSrcId = MOD_J2ME;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_TST_MMI_JAVA_CMD_REQ;
    Message.oslDataPtr = (oslParaType*) ptrCmd;
    Message.oslPeerBuffPtr = NULL;
     
    OslMsgSendExtQueue(&Message);
    
    return 0;
}

extern kal_bool jvm_IsBackLightOn(void);
extern kal_bool jvm_is_vibrate(void);
/****************************************************************************
 * FUNCTION
 *  java_get_vibrate_status
 * DESCRIPTION
 *  Check the current status of vibrater and save the result in buffer.
 *      
 *
 *  Return KAL_TRUE if ON or KAL_FALSE if OFF.
 *  
 *
 * PARAMETERS
 * kal_char* buffer,
 * kal_int32 len
 *
 * RETURNS
 * kal_bool
 *****************************************************************************/

static kal_bool java_get_vibrate_status(kal_char* buffer,kal_int32 len)
{
    kal_bool retval = KAL_FALSE;
    kal_char *STR_FALSE = "FALSE";
    kal_char *STR_TRUE = "TRUE";
    kal_char *result = NULL;
    if(msg.serviceType!=SEV_TYPE_GET_VIBRATOR){
        return KAL_FALSE;
    }
    kal_mem_set(buffer,0,len);
    
    retval = jvm_is_vibrate();
    if(retval){
        result = STR_TRUE;
    }else{
        result = STR_FALSE;
    }
    sprintf(buffer,"%d:%d:%s\r",PKG_TYPE_RSP,SEV_TYPE_GET_VIBRATOR,result);
    return KAL_TRUE;
}
/****************************************************************************
 * FUNCTION
 *  java_get_backlight_status
 * DESCRIPTION
 *  Check the current status of backlight and save the result in buffer.
 *      
 *
 *  Return KAL_TRUE if ON or KAL_FALSE if OFF.
 *  
 *
 * PARAMETERS
 * kal_char* buffer,
 * kal_int32 len
 *
 * RETURNS
 * kal_bool
 *****************************************************************************/

static kal_bool 
java_get_backlight_status(kal_char* buffer,kal_int32 len)
{
    kal_bool retval = KAL_FALSE;
    kal_char *STR_FALSE = "FALSE";
    kal_char *STR_TRUE = "TRUE";
    kal_char *result = NULL;
    if(msg.serviceType!=SEV_TYPE_GET_BACKLIGHT){
        return KAL_FALSE;
    }
    kal_mem_set(buffer,0,len);
    
    retval = jvm_IsBackLightOn();
    if(retval){
        result = STR_TRUE;
    }else{
        result = STR_FALSE;
    }
    sprintf(buffer,"%d:%d:%s\r",PKG_TYPE_RSP,SEV_TYPE_GET_BACKLIGHT,result);
    return KAL_TRUE;
}
/****************************************************************************
 * FUNCTION
 *  java_vcomm_data_process
 * DESCRIPTION
 *  This function is used to process the request from java layer and respond the result.
 *      
 *
 *  Return KAL_TRUE on no error or KAL_FALSE on error.
 *  
 *
 * PARAMETERS
 * kal_int32  port
 *
 * RETURNS
 * kal_bool
 *****************************************************************************/
static kal_bool
java_vcomm_data_process(kal_uint32 port)
{
    kal_int16 drv = 0;
    kal_char temp[50]={0};
    kal_int32 len = 0;
    kal_char* ptr = NULL;
    kal_char* ptrFile = NULL;
    kal_char* buffer = vport[port].receBuffer;
   /************parse data**********/ 
    ptr = strchr((const char *)buffer,delimitChar);
    if(ptr==NULL)return KAL_FALSE;
    len = ptr - buffer;
    strncpy(temp,(const char *)buffer,len);
    msg.sessionType = atoi(temp);
    kal_mem_set(temp,0, sizeof(temp));
    ptr = strchr((const char *)ptr+1,delimitChar);
    if(ptr==NULL)return KAL_FALSE;
    len = ptr - buffer-len-1;
    strncpy(temp,(const char *)ptr-len,len);
    msg.serviceType = atoi(temp);
    msg.pdata = ptr+1;
    /************process data*******/
    switch(msg.serviceType){
        case SEV_TYPE_SEND_KEYS :
            java_l4c_send_at_cmd_req(msg.pdata);
            break;
        case SEV_TYPE_SAVE_TO_FILE :
            {                 
                kal_uint32 len = 0;
                kal_wchar* wfilepath = NULL;
                ptr = strchr((const char *)msg.pdata,delimitChar);
                if(ptr==NULL)return KAL_FALSE;
                len = ptr - msg.pdata;
                strncpy(temp,(const char *)msg.pdata,len);
                vport[port].flieLen =atoi(temp);
                if(vport[port].flieLen<=0)return KAL_FALSE;
                ptrFile = jvm_malloc(JAVA_VCOMM_MAX_BUFFER_SIZE);
                if(NULL == ptrFile) return KAL_FALSE;
                kal_mem_set(ptrFile,0,JAVA_VCOMM_MAX_BUFFER_SIZE);
                drv = SRV_FMGR_PUBLIC_DRV;
                if(drv < 0 && NULL != (ptr+1)){
                    jvm_free(ptrFile);
                    return KAL_FALSE;
                }
                sprintf(ptrFile,"%c:%s%s",(kal_char)drv,defaultResultPath,ptr+1);
        
                len = strlen(ptrFile)+1;
                if (NULL == (wfilepath = (kal_wchar*)jvm_malloc(len<<1))) {
                    return KAL_FALSE;
                }
                kal_mem_set(wfilepath,0,len<<1);
                mmi_asc_to_ucs2((S8 *)wfilepath, (S8 *) ptrFile);
                jvm_free(ptrFile);
                if(0 < vport[port].fileHandler){
                    FS_Close(vport[port].fileHandler);
                    vport[port].fileHandler = 0;
                }
                vport[port].fileHandler = FS_Open((const WCHAR*)wfilepath, FS_CREATE | FS_READ_WRITE);
                jvm_free(wfilepath);
                if(0 >= vport[port].fileHandler){
                    return KAL_FALSE;
                }
                /* seek to end of the current file if exist*/
                if(0>FS_Seek(vport[port].fileHandler, 0, FS_FILE_END)){
                    return KAL_FALSE;
                }
                vport[port].sessionMode = SESSION_MODE_FILE_TRANS;
            }
            break;
        case SEV_TYPE_GET_VIBRATOR :
            if(java_get_vibrate_status(vport[port].sendBuffer,JAVA_VCOMM_MAX_BUFFER_SIZE)==KAL_TRUE){
                vport[port].isDataReady = KAL_TRUE;    
                vport[port].currSendLen = strlen(vport[port].sendBuffer);
            }
            break;
        case SEV_TYPE_GET_BACKLIGHT :
            if(java_get_backlight_status(vport[port].sendBuffer,JAVA_VCOMM_MAX_BUFFER_SIZE)==KAL_TRUE){
                vport[port].isDataReady = KAL_TRUE;  
                vport[port].currSendLen = strlen(vport[port].sendBuffer);
            }
            break;
        case SEV_TYPE_SNAPSHOT:
            java_take_snapshot_req(msg.pdata);
            break;
        default:
           break; 
    }
    return KAL_TRUE;
}
/****************************************************************************
 * FUNCTION
 *  java_vcomm_write
 * DESCRIPTION
 *  This function is used to write data to virtual com opened by java_vcomm_open(kal_uint32 port).
 *      
 *
 *  Return the number  of data writtenjava_vcomm_write.
 *  
 *
 * PARAMETERS
 * kal_int32  port
 * kal_uint8 *buffer
 * kal_uint16 len
 * RETURNS
 * kal_int32
 *****************************************************************************/
kal_int32 
java_vcomm_write(kal_uint32 port, kal_uint8 *buffer, kal_uint16 len)
{
    if(port >= MAX_VIRTUAL_COMM_PORT_SUPPORT || KAL_FALSE == vport[port].isOpened){/*no opened*/
        return -1;
    }
    if(vport[port].sessionMode == SESSION_MODE_FILE_TRANS){
        kal_int32 retVal=0;
        kal_uint32 writtenLen=0;
        kal_int32 offset = 0;
        if(vport[port].fileHandler <= 0)return -1;
        while(offset < len){
            retVal = FS_Write(vport[port].fileHandler,buffer+offset,len-offset,&writtenLen);
            offset += writtenLen;
        }
        vport[port].fliePos += len;
        if(vport[port].fliePos==vport[port].flieLen){
            retVal = FS_Close(vport[port].fileHandler);
            vport[port].fileHandler = 0;
            vport[port].sessionMode = SESSION_MODE_MESSAGE;
        }
        
    }
    else if((vport[port].sessionMode == SESSION_MODE_MESSAGE)
        &&(vport[port].isReceivedDown== KAL_FALSE)
        && (vport[port].currReceLen + len < JAVA_VCOMM_MAX_BUFFER_SIZE))
    {
        kal_mem_cpy(vport[port].receBuffer +vport[port].currReceLen,(const kal_char*)buffer,len);
        vport[port].currReceLen+=len;
        if(*(vport[port].receBuffer+vport[port].currReceLen -1) == endChar){
/*message end*/
            /*process message gotten by virtual port   | */
            vport[port].receBuffer[vport[port].currReceLen -1]='\0';
            vport[port].isReceivedDown = KAL_TRUE;
            if(KAL_FALSE == java_vcomm_data_process(port))return -1;
            kal_mem_set(vport[port].receBuffer,0,JAVA_VCOMM_MAX_BUFFER_SIZE);
            vport[port].isReceivedDown = KAL_FALSE;
            vport[port].currReceLen = 0;
        }
    }
    return len;
}
/****************************************************************************
 * FUNCTION
 *  java_vcomm_close
 * DESCRIPTION
 * 
 *  This function is used to close virtual com opened by java_vcomm_open(kal_uint32 port).
 *     
 *
 *  Return KAL_TRUE on no error or KAL_FALSE on error.
 *  
 *
 * PARAMETERS
 * kal_int32  port
 * 
 * RETURNS
 * kal_bool
 *****************************************************************************/
kal_bool
java_vcomm_close(kal_uint32 port)
{
    if(port >= MAX_VIRTUAL_COMM_PORT_SUPPORT || KAL_FALSE == vport[port].isOpened){/*no opened*/
        return KAL_FALSE;
    }
    if(NULL != vport[port].receBuffer){
        jvm_free(vport[port].receBuffer);
        vport[port].receBuffer = NULL;
        vport[port].currReceLen = 0;
    }
    if(NULL != vport[port].sendBuffer){
        jvm_free(vport[port].sendBuffer);
        vport[port].sendBuffer = NULL;
        vport[port].currSendLen = 0;
    }
    if(0 < vport[port].fileHandler){
        FS_Close(vport[port].fileHandler);
        vport[port].fileHandler = 0;
    }
    vport[port].isOpened = KAL_FALSE;
    return KAL_TRUE;
}
#endif




