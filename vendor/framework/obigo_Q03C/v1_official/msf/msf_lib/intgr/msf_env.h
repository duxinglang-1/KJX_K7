/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_env.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 * 
 *
 */

#ifndef _msf_env_h
#define _msf_env_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_int_h
#include "msf_int.h"
#endif

/****************************************
 * Messaging
 ****************************************/

MSF_UINT8
gmms_HDIc_signalGetDestination (void* signalData);

MSF_UINT8
gmms_HDIc_signalGetSource (void* signalData);


/**********************************************************************
 * Named Pipes
 **********************************************************************/

void
gmms_HDIc_pipeNotify (MSF_UINT8 modId, int handle, int eventType);


/**********************************************************************
 * Sockets
 **********************************************************************/

void
gmms_HDIc_socketConnectResponse (MSF_UINT8 modId, int socketId, int result);

void
gmms_HDIc_socketNotify (MSF_UINT8 modId, int socketId, int eventType);

void
gmms_HDIc_socketHostByName (MSF_UINT8 modId, int requestId, int result,
                       unsigned char *addr, int addrLen);

/**********************************************************************
 * File
 **********************************************************************/

void
gmms_HDIc_fileNotify (MSF_UINT8 modId, int fileHandle, int eventType);


/**********************************************************************
 * Telephone
 **********************************************************************/

void
gmms_HDIc_telMakeCallResponse (MSF_UINT8 modId, MSF_UINT16 telId, int result);

void
gmms_HDIc_telSendDtmfResponse (MSF_UINT8 modId, MSF_UINT16 telId, int result);


/**********************************************************************
 * Phonebook
 **********************************************************************/

void
gmms_HDIc_pbAddEntryResponse (MSF_UINT8 modId, MSF_UINT16 pbId, int result);

#ifndef Q03C_IND_MOD_ARCH_SUPPORT

/**********************************************************************
 * Widgets
 **********************************************************************/

void
gmms_HDIc_widgetNotify(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfNotificationType notificationType);

void
gmms_HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

void
gmms_HDIc_widgetUserEvent(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfEvent* msfEvent);

void
gmms_HDIc_widgetAccessKey(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 accessKey);

#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/
void 
HDIc_pimOpenResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimCloseResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimAddrLookupResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 numRecordInfos,
                            MsfPimAddrRecordInfo *recordInfos, MSF_UINT16 result);

void 
HDIc_pimAddrLookupNameResponse (MSF_UINT8 modId, MSF_UINT16 requestId, 
                                const char *name, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrGetRecordReponse(MSF_UINT8 modId, MSF_UINT16 requestId, MsfPimField *fields,
                             MSF_UINT16 numFields, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrSetRecordResponse(MSF_UINT8 modId, MSF_UINT16 requestId, 
                              MSF_UINT32 recordId, MSF_UINT16 result);
#endif /*MSF_CONFIG_PIM*/

#else
/**********************************************************************
 * Widgets
 **********************************************************************/

void
HDIc_widgetNotify(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfNotificationType notificationType);

void
HDIc_widgetAction(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 action);

void
HDIc_widgetUserEvent(MSF_UINT8 modId, MSF_UINT32 msfHandle, MsfEvent* msfEvent);

void
HDIc_widgetAccessKey(MSF_UINT8 modId, MSF_UINT32 msfHandle, MSF_UINT32 accessKey, MsfEvent* msfEvent); 

/**********************************************************************
 * File
 **********************************************************************/
void
HDIc_fileNotify (MSF_UINT8 modId, int fileHandle, int eventType);

void
HDIc_pipeNotify (MSF_UINT8 modId, int handle, int eventType);

/**********************************************************************
 * Sockets
 **********************************************************************/

void
HDIc_socketConnectResponse (MSF_UINT8 modId, int socketId, int result);

void
HDIc_socketNotify (MSF_UINT8 modId, int socketId, int eventType);

void
HDIc_socketHostByName (MSF_UINT8 modId, int requestId, int result,
                       unsigned char *addr, int addrLen);


#ifdef MSF_CONFIG_PIM

/**********************************************************************
 * PIM
 **********************************************************************/
void 
HDIc_pimOpenResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimCloseResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 result);

void 
HDIc_pimAddrLookupResponse (MSF_UINT8 modId, MSF_UINT16 requestId, MSF_UINT16 numRecordInfos,
                            MsfPimAddrRecordInfo *recordInfos, MSF_UINT16 result);

void 
HDIc_pimAddrLookupNameResponse (MSF_UINT8 modId, MSF_UINT16 requestId, 
                                const char *name, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrGetRecordReponse(MSF_UINT8 modId, MSF_UINT16 requestId, MsfPimField *fields,
                             MSF_UINT16 numFields, MSF_UINT32 recordId, MSF_UINT16 result);

void 
HDIc_pimAddrSetRecordResponse(MSF_UINT8 modId, MSF_UINT16 requestId, 
                              MSF_UINT32 recordId, MSF_UINT16 result);
#endif /*MSF_CONFIG_PIM*/

#endif

#define HDIc_pipeNotify gmms_HDIc_pipeNotify

#define HDIc_socketConnectResponse gmms_HDIc_socketConnectResponse

#define HDIc_socketNotify gmms_HDIc_socketNotify

#define HDIc_socketHostByName gmms_HDIc_socketHostByName

#define HDIc_fileNotify gmms_HDIc_fileNotify

#define HDIc_telMakeCallResponse gmms_HDIc_telMakeCallResponse

#define HDIc_telSendDtmfResponse gmms_HDIc_telSendDtmfResponse

#define HDIc_pbAddEntryResponse gmms_HDIc_pbAddEntryResponse

#define HDIc_widgetNotify gmms_HDIc_widgetNotify

#define HDIc_widgetAction gmms_HDIc_widgetAction

#define HDIc_widgetUserEvent gmms_HDIc_widgetUserEvent

#define HDIc_widgetAccessKey gmms_HDIc_widgetAccessKey

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifndef MSF_SIGNAL_API_REVISED
#define HDIc_signalGetDestination gmms_HDIc_signalGetDestination

#define HDIc_signalGetSource gmms_HDIc_signalGetSource
#endif

#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/

#endif
