#ifndef __OBCONFIG_H
#define __OBCONFIG_H
/****************************************************************************
 *
 * File:          obconfig.h
 *
 * Description:   This file defines the configurable options for the OBEX
 *                add-in component.
 * 
 * Created:       August 7, 1998
 *
 * Version:       MTObex 3.4
 *
 * Copyright 1998-2005 Extended Systems, Inc.  ALL RIGHTS RESERVED.
 *
 * Unpublished Confidential Information of Extended Systems, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of Extended Systems, Inc.
 * 
 * Use of this work is governed by a license granted by Extended Systems,
 * Inc.  This work contains confidential and proprietary information of
 * Extended Systems, Inc. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
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

#include "config.h"

#if BT_STACK == XA_ENABLED
#include "btconfig.h"
#endif

/*---------------------------------------------------------------------------
 *
 * If the IrDA Stack is not included in this build then it is necessary to
 * define IrDA specific options that are used by OBEX.
 */
#if IRDA_STACK == XA_ENABLED
#include "irconfig.h"
#else
#define IR_MULTI_WINDOW   XA_DISABLED
#define IR_LMP_DISCONNECT XA_DISABLED
#endif

#if TCP_STACK == XA_ENABLED
/* No special default configuration options for TCP Stack */
#endif

#if OEM_STACK == XA_ENABLED
/*
 * If necessary add include statement for configuration file for OEM_STACK.
 * Warning! Do not include the OEM_STACK transport structure definition file.
 */
#endif

/*---------------------------------------------------------------------------
 * OBEX Configuration API layer
 *
 *     When the OBEX protocol is ported, tradeoffs can be made between
 *     functionality and code size. The obconfig.h header file contains
 *     the configuration API, which controls these tradeoffs.
 *
 *     The configuration API employs two strategies. First, a set of
 *     conditional compile names allows certain areas of code to be included
 *     or excluded from the stack. Second, a set of types and constants
 *     govern the size of internal tables, buffers, and structures.
 *
 *     All of these #defines, except for those contained in the section
 *     explicitly labeled "non-modifiable constants", may be overridden
 *     in overide.h.
 */


/****************************************************************************
 *
 * Section: Conditional Compile Name Constants
 *
 ****************************************************************************
 *
 *     OBEX code contains certain features surrounded by #ifdef-type
 *     statements. To save code size and customize the stack for a
 *     particular operating environment, these features may be excluded
 *     by disabling certain conditional compile names. These names are
 *     described below.
 *
 ****************************************************************************/

/*----------------------------------------------------------------------------
 * JETTEST constant
 *
 *     When enabled this configuration option allows the raw OBEX data to be
 *     routed directly to the application layer for debugging and/or data 
 *     logging purposes.
 */
#ifndef JETTEST
#define JETTEST XA_DISABLED
#endif

/*----------------------------------------------------------------------------
 * OBEX_ROLE_CLIENT constant
 *
 *     When enabled this configuration option enables support for the OBEX
 *     Client functionality in the OBEX module.
 */
/*
#ifndef OBEX_ROLE_CLIENT
#define OBEX_ROLE_CLIENT     XA_ENABLED
#endif
*/
#if defined(__BT_OPP_PROFILE__) || \
    defined(__BT_FTC_PROFILE__) || \
    defined(__BT_BPP_PROFILE__) || \
    defined(__BT_BIP_PROFILE__) || \
    defined(__BT_MAP_CLIENT__)  || \
    defined(__BT_PBAP_CLIENT__) || \
    defined(__BT_SUPPORT_SYNCML__)

#define OBEX_ROLE_CLIENT     XA_ENABLED

#else
#define OBEX_ROLE_CLIENT     XA_DISABLED
#endif    

/*----------------------------------------------------------------------------
 * OBEX_ROLE_SERVER constant
 *
 *     When enabled this configuration option enables support for the OBEX
 *     Server functionality in the OBEX module.
 */
/* 
#ifndef OBEX_ROLE_SERVER
#define OBEX_ROLE_SERVER     XA_ENABLED
#endif
*/
#if defined(__BT_OPP_PROFILE__) || \
    defined(__BT_FTS_PROFILE__) || \
    defined(__BT_BIP_PROFILE__) || \
    defined(__BT_PBAP_PROFILE__) || \
    defined(__BT_MAP_CLIENT__)   || \
    defined(__BT_SUPPORT_SYNCML__)

#define OBEX_ROLE_SERVER     XA_ENABLED

#else
#define OBEX_ROLE_SERVER     XA_DISABLED
#endif 

/*---------------------------------------------------------------------------
 * OBEX_PUT_DELETE constant
 *
 *     Some applications of OBEX use the PUT-DELETE behavior which allows
 *     a client to delete an object on the server by sending a PUT operation
 *     without a BODY or END-OF-BODY header. Enabling this define compiles in 
 *     client API support for this operation. If this option is disabled the 
 *     client will not be able to send PUT-DELETEs. The server always handles
 *     the PUT-DELETE case.
 */
#ifndef OBEX_PUT_DELETE
#define OBEX_PUT_DELETE XA_DISABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_TLV_PARSER constant
 *
 *     The OBEX TLV Parser option is enabled to add support for parsing
 *     OBEX ByteSeq headers that contain tag-length-value encoded data. The
 *     following headers fall into this category: APP_PARAMS, AUTH_CHAL and
 *     AUTH_RESP. Enabling authentication automatically enables this option.
 *
 *     Note: In OBEX versions 3.3.6 and earlier, a similar option was known 
 *     as OBEX_BYTE_TAG_PARSER.
 *
 */
#ifndef OBEX_TLV_PARSER
#define OBEX_TLV_PARSER XA_DISABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_DEINIT_FUNCS constant
 *
 *     Some implementations of the OBEX API may allow applications to 
 *     dynamically acquire and release the resources of the OBEX protocol
 *     client and server parsers without shutting down the entire XTNDAccess
 *     Embedded stack. In such cases, OBEX_DEINIT_FUNCS should be enabled to
 *     provide deinitialization routines which allow the application to
 *     release the resources that it previously acquired via the OBEX init
 *     function. Otherwise, the option can be disabled to save code size.
 */
#ifndef OBEX_DEINIT_FUNCS 
#define OBEX_DEINIT_FUNCS XA_ENABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_DYNAMIC_OBJECT_SUPPORT constant
 *
 *     This option enables support for sending objects of unknown size.
 *     Normally, the protocol engine requires the size of the object be known
 *     when it is provided to the protocol. This requirement enables the
 *     protocol to make optimum use of the OBEX packet size and RAM resources.
 *     However, in certain cases, such as with dynamically created objects, it
 *     is difficult to know the exact size of the object in advance. Enabling
 *     this option adds a new object store read function which is permitted to
 *     read variable amounts of data. This function also signals the protocol
 *     when the entire object has been read instead of the protocol counting
 *     down the object size. Note that this option applies to object store
 *     read operations only: Client-PUT and Server-GET.
 *
 *     Refer to the documentation on OBS_ReadFlex() for more information
 *     on how to use this functionality.
 */
#ifndef OBEX_DYNAMIC_OBJECT_SUPPORT
#define OBEX_DYNAMIC_OBJECT_SUPPORT XA_DISABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_PACKET_FLOW_CONTROL constant
 *
 *     This option enables application support for managing the flow of command
 *     and response packets between the client and server. When enabled, the
 *     server will generate OBSE_SEND_RESPONSE events when it is time to send a
 *     response to the client. Similarly, the client will generate OBCE_SEND_
 *     COMMAND events when it is time to send a continuing request to the
 *     server. The application must call the appropriate OBEX continue command
 *     or the exchange will pause. The call may be done in the context of the
 *     callback or it may be deferred until resource constraints or similar
 *     conditions have been relieved. 
 *
 *     Note that when this option is enabled, the protocol server changes how
 *     it processes ABORT requests. This is done to insure that the ABORT
 *     request is delivered to the server application in a timely manner. The
 *     server application must be aware that an OBSE_ABORT_START event may
 *     arrive while it is busy processing an existing request. In such a case it
 *     must stop processing the current request and respond to the remote
 *     device as indicated by OBSE_SEND_RESPONSE events. When the abort
 *     complete an OBSE_ABORTED event will be indicated to the application.
 */
#ifndef OBEX_PACKET_FLOW_CONTROL
#define OBEX_PACKET_FLOW_CONTROL XA_ENABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_AUTHENTICATION constant
 *
 *     This option enables OBEX layer support for OBEX Authentication Challenge
 *     and Response headers. OBEX Authentication support includes functions 
 *     necessary to build and parse authentication challenge and response
 *     headers. There is also a function for verifying that an authentication
 *     response used the correct password.
 */
#ifndef OBEX_AUTHENTICATION
//#define OBEX_AUTHENTICATION     XA_ENABLED
//According Spec, only OPP does not required OBEX AUTHENTICATION
#if (defined (__BT_BPP_PROFILE__) || \
     defined (__BT_FTC_PROFILE__) || \
     defined (__BT_BIP_PROFILE__) || \
     defined (__BT_PBAP_PROFILE__)) || \
     defined(__BT_PBAP_CLIENT__)
#define OBEX_AUTHENTICATION     XA_ENABLED
#else
#define OBEX_AUTHENTICATION     XA_DISABLED
#endif /* BPP, FTC, BIP */
#endif

#if defined(__BT_PBAP_PROFILE__)
#define OBEX_ALLOW_FIT_ONE_PACKET XA_ENABLED
#else
#define OBEX_ALLOW_FIT_ONE_PACKET XA_DISABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_SESSION_SUPPORT constant
 *
 *     This option indicates whether reliable OBEX Sessions will be supported
 *     in OBEX. OBEX Sessions provide a guaranteed and reliable session
 *     OBEX operations. Such a reliable session can be recovered if an
 *     unexpected transport disconnection should occur, thus allowing OBEX
 *     operations to be resumed. If the reliable session functionality is
 *     not necessary, this option can be disabled to reduce code size.
 */
#ifndef OBEX_SESSION_SUPPORT
#define OBEX_SESSION_SUPPORT    XA_DISABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_ALLOW_SERVER_TP_CONNECT constant
 *
 *     This option indicates whether OBEX Servers are allowed to establish
 *     and disconnect transport connections in OBEX. Notice that this option 
 *     will require an increase in the IR_CONS_SIZE configuration option, 
 *     which represents the number of possible IrLMP/TinyTP connections.  
 *     This increase occurs because OBEX is forced to register an extra 
 *     transport structure to deal with an incoming or outgoing server 
 *     transport connection.  If this functionality is not necessary, this 
 *     option should be disabled to reduce code size.
 */
#ifndef OBEX_ALLOW_SERVER_TP_CONNECT
#if OBEX_ROLE_SERVER == XA_ENABLED
#define OBEX_ALLOW_SERVER_TP_CONNECT    XA_ENABLED
#endif /* OBEX_ROLE_SERVER == XA_ENABLED */
#endif

/*---------------------------------------------------------------------------
 * OBEX_BODYLESS_GET constant
 *
 *     Indicates whether OBEX Servers may respond to a GET request with
 *     no object using OBEX_ServerAcceptNoObject(). Normally a GET command
 *     results in the transfer of an object via Body/End-of-Body headers.
 *     If this option is enabled and OBEX_ServerAcceptNoObject() is used,
 *     the server will respond only with those headers provided using OBEXH_
 *     functions. 
 */
#ifndef OBEX_BODYLESS_GET
/*revise for PBAP: PBAP require BODYLESS_GET */
#define OBEX_BODYLESS_GET    XA_ENABLED /* XA_DISABLED*/ 
#endif

/*---------------------------------------------------------------------------
 * OBEX_ALLOW_SERVER_TP_DISCONNECT constant
 *
 *     This option indicates whether OBEX Servers are allowed to disconnect
 *     client initiated transport connections in OBEX. If this functionality 
 *     is not necessary, this option should be disabled to reduce code size.
 */
#ifndef OBEX_ALLOW_SERVER_TP_DISCONNECT
#if OBEX_ROLE_SERVER == XA_ENABLED
#define OBEX_ALLOW_SERVER_TP_DISCONNECT    XA_ENABLED
#endif /* OBEX_ROLE_SERVER == XA_ENABLED */
#endif /* OBEX_ALLOW_SERVER_TP_DISCONNECT */

/*---------------------------------------------------------------------------
 * OBEX_PROVIDE_SDP_RESULTS constant
 *
 *     This option indicates whether OBEX Clients are allowed to pass up SDP
 *     Query result information to the application layer for further SDP 
 *     parsing.  This feature is a Bluetooth specific option.  If this 
 *     functionality is not necessary, this option should be disabled to 
 *     reduce code size.
 */
#if BT_STACK == XA_ENABLED

#ifndef OBEX_PROVIDE_SDP_RESULTS
#define OBEX_PROVIDE_SDP_RESULTS XA_DISABLED
#endif

#endif /* BT_STACK == XA_ENABLED */

/*---------------------------------------------------------------------------
 * OEM_STACK constant
 *     
 *     Enable this option when a custom transport, beyond those provided with
 *     MTObex, is required. This transport should be developed from the
 *     sample structures and stub functions provided in the obxoemstk.c and 
 *     obxoemstk.h files. This transport will seemlessly integrate with 
 *     MTObex once all of the structures and stub functions provided in the
 *     OEM transport files are completed.
 */
#ifndef OEM_STACK
#define OEM_STACK       XA_DISABLED
#endif

/****************************************************************************
 *
 * Section: Size and Performance Configuration Constants
 *
 ****************************************************************************
 *
 *     The following constants control the size of items in the OBEX
 *     protocol. They can be modified to support the specific performance,
 *     memory or efficiency needs of applications developed with OBEX.
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * OBEX_RF_SERVICE_CHANNELS constant
 *
 *     This is the maximum number of RFCOMM service channels returned by SDP
 *     that the Bluetooth transport will store.
 *
 *     Default 2 for Bluetooth.
 */
#if BT_STACK == XA_ENABLED

#ifndef OBEX_RF_SERVICE_CHANNELS
#define OBEX_RF_SERVICE_CHANNELS 2
#endif

#if OBEX_RF_SERVICE_CHANNELS < 1
#error OBEX_RF_SERVICE_CHANNELS must be at least 1
#endif 

#endif /* BT_STACK == XA_ENABLED */

/*---------------------------------------------------------------------------
 * OBEX_NUM_TX_PACKETS constant
 *
 *     Total number of Transmit packets to allocate for both the client and 
 *     server connections. The protocol must have at least 1. This value
 *     should be optimized to allow maximum throughput with a minimum of
 *     packets.
 *
 *     IrDA: The number of transmit packets should be based on the Window size.
 *         Only 1 packet need be allocated for Window Size 1 stack builds. But
 *         as many as 7 packets can be used when running with Window Size of 7
 *         at FIR speeds.
 *
 *     Bluetooth: Transmit packets are typically broken up into smaller
 *         fragments sent over the air interface. Only one packet fragment is
 *         sent at a time. An optimal data rate can be achieved with two
 *         packets. This way there is always one currently in transmit and one
 *         more queued for transmit.
 */
#ifndef OBEX_NUM_TX_PACKETS

/* Use the IrDA packet count as a starting point. */
#if IR_MULTI_WINDOW == XA_ENABLED
#define OBEX_NUM_TX_PACKETS   7
#else
#define OBEX_NUM_TX_PACKETS   1
#endif

/* If Bluetooth is installed, make sure we have 2 or more packets. */
#if (BT_STACK == XA_ENABLED) && (OBEX_NUM_TX_PACKETS < 2)
#undef  OBEX_NUM_TX_PACKETS
#define OBEX_NUM_TX_PACKETS      2
#endif

#endif  /* OBEX_NUM_TX_PACKETS */

#if OBEX_NUM_TX_PACKETS < 1
#error OBEX_NUM_TX_PACKETS must be at least 1
#endif 
#if OBEX_NUM_TX_PACKETS > 7
#error OBEX_NUM_TX_PACKETS must be less than 8
#endif

/*---------------------------------------------------------------------------
 * OB_INITIAL_CREDITS constant
 *
 *       IrDA Build Only.
 *     
 *     Number of initial Tiny TP credits to advance. This should be enough to
 *     allow either an entire OBEX packet to be sent, or as much data as the
 *     window size will permit, without encountering TTP flow control. Since
 *     we can never know exactly how many packets the peer device is going
 *     to send in its permitted window, we set this value to the window
 *     size the stack advertises. This protects us from inadvertently
 *     restricting flow.
 *
 *     The default value is 1 when using the single window IrDA stack,
 *     otherwise its 7.  These are also the minimum and maximum allowable
 *     values, respectively.
 *
 * Requires: IRDA_STACK == XA_ENABLED.
 */
#if IRDA_STACK == XA_ENABLED
#ifndef OB_INITIAL_CREDITS

#if IR_MULTI_WINDOW == XA_ENABLED
#define OB_INITIAL_CREDITS   7
#else
#define OB_INITIAL_CREDITS   1
#endif
#endif /* OB_INITIAL_CREDITS */

#if OB_INITIAL_CREDITS < 1
#error OB_INITIAL_CREDITS must be at least 1
#endif
#if OB_INITIAL_CREDITS > 7
#error OB_INITIAL_CREDITS must be less than 8
#endif
#endif /* IRDA_STACK == XA_ENABLED */

/*---------------------------------------------------------------------------
 * OBEX_PERFORMANCE_MULTIPLIER constant
 * 
 *     OBEX achieves throughput gains by allowing the data source to send
 *     multiple transport PDU's before having to wait for an acknowledgement.
 *     The number of transport PDU's that can be sent is determined by the OBEX
 *     Packet size. The OBEX packet size is determined by multiplying the TPDU's
 *     size by a factor of one or more. This factor is the
 *     OBEX_PERFORMANCE_MULTIPLIER. The effectiveness of this multiplier is
 *     tied to the underlying transports data rate and technology. Both the
 *     client and server advertise their individual maximum OBEX Packet size.
 *     The values are asymmetric and are not negotiated. This value is used to
 *     calculate our receive size (aka the peer's transmit size). Our transmit
 *     size is determined by the peer device.
 * 
 *     IrDA: This value should be, at a minimum, the window size supported by
 *         the stack. Generally the OBEX packet size should grow proportionately
 *         to the IR data rate.
 *
 *     Bluetooth: This value is largely subjective, a value between 4 & 20 is
 *         recommended. This is based on a default L2CAP packet size of
 *         672 bytes.
 */
#ifndef OBEX_PERFORMANCE_MULTIPLIER
#define OBEX_PERFORMANCE_MULTIPLIER  12

#if defined(OB_INITIAL_CREDITS) && (OBEX_PERFORMANCE_MULTIPLIER < OB_INITIAL_CREDITS)
#undef  OBEX_PERFORMANCE_MULTIPLIER
#define OBEX_PERFORMANCE_MULTIPLIER  OB_INITIAL_CREDITS
#endif
#endif  /* OBEX_PERFORMANCE_MULTIPLIER */

#if OBEX_PERFORMANCE_MULTIPLIER < 1
#error OBEX_PERFORMANCE_MULTIPLIER must be at least 1
#endif 

/*---------------------------------------------------------------------------
 * OBEX_TX_BUFF_SIZE constant
 *
 *     This is the maximum size of the transport's transmit packet data area.
 *     It is used to calculate how much RAM to allocate for transmit packets.
 *     The result equals the largest MTU of all the included transports.
 *
 *     Default size for IrDA is 2045 or 667 for Bluetooth.
 */
#ifndef OBEX_TX_BUFF_SIZE
#define OBEX_TX_BUFF_SIZE     60    /* Minimum OBEX Packet Size */

#if IRDA_STACK == XA_ENABLED
#if OBEX_TX_BUFF_SIZE < 2045
#undef OBEX_TX_BUFF_SIZE
#define OBEX_TX_BUFF_SIZE     2045      /* IrLAP 2048 frame - 3 for LMP+TTP */
#endif
#endif

#if TCP_STACK == XA_ENABLED
#if OBEX_TX_BUFF_SIZE < 1450
#undef OBEX_TX_BUFF_SIZE
#define OBEX_TX_BUFF_SIZE     1450
#endif
#endif

#if BT_STACK == XA_ENABLED
#if OBEX_TX_BUFF_SIZE < (RF_MAX_FRAME_SIZE)
#undef OBEX_TX_BUFF_SIZE
#define OBEX_TX_BUFF_SIZE     (RF_MAX_FRAME_SIZE) /* Default 667 */
#endif
#endif

#if OEM_STACK == XA_ENABLED
/* Alter the OBEX packet size for the OEM_STACK transport if necessary.
 * The default transport packet default is 1K (1024 bytes). 
 */
#if OBEX_TX_BUFF_SIZE < 1024
#undef OBEX_TX_BUFF_SIZE
#define OBEX_TX_BUFF_SIZE     1024
#endif
#endif

/* Follow the format used above for making sure that the OBEX_TX_BUFF_SIZE
 * value matches the largest usable value. The value does not have to be
 * exact, but the transmit TPDU will be limited to this size.
 */
#endif /* OBEX_TX_BUFF_SIZE */

#if OBEX_TX_BUFF_SIZE < 60
#error OBEX_TX_BUFF_SIZE must be at least 60
#endif


/*---------------------------------------------------------------------------
 * OBEX_SERVER_CONS_SIZE constant
 *
 *     Number of Obex Server connections supported by server application.
 *     This is in addition to the default server connection. It is equal to
 *     the number of Target headers registered by the Server Application.
 *
 *     When the default value of zero is used, the OBEX Server Connection code
 *     is removed from the build.
 */
#define OBEX_SERVER_CONS_SIZE 2

#ifndef OBEX_SERVER_CONS_SIZE
#define OBEX_SERVER_CONS_SIZE 0
#endif    

/*---------------------------------------------------------------------------
 * OBEX_MAX_SERVICE_UUID_SIZE constant
 *
 *     The size of the maximum UUID that can be received in a Target header
 *     or sent in a Who header. Must be equal to the largest Target value 
 *     registered by the Server Application. If OBEX_SERVER_CONS_SIZE == 0
 *     this option is ignored. The limit is based on the minimum OBEX Packet
 *     size.
 */
#ifndef OBEX_MAX_SERVICE_UUID_SIZE
#define OBEX_MAX_SERVICE_UUID_SIZE   16
#endif

#if OBEX_MAX_SERVICE_UUID_SIZE > 244
#error OBEX_MAX_SERVICE_UUID_SIZE must be less than 245
#endif

/*---------------------------------------------------------------------------
 * OBEX_MAX_USERID_LEN constant
 * 
 *     This constant specifies the maximum size User Id that can be received
 *     in an Authentication confirmation. The user id field conveys the user
 *     id for the password which was used to create the request-digest. If
 *     OBEX_AUTHENTICATION is XA_DISABLED this option is ignored.
 */
#ifndef OBEX_MAX_USERID_LEN
#define OBEX_MAX_USERID_LEN     20      /* Range 0 - 20 */
#endif

#if OBEX_MAX_USERID_LEN > 20
#error OBEX_MAX_USERID_LEN must be less than 21
#endif

/*---------------------------------------------------------------------------
 * OBEX_MAX_REALM_LEN constant
 * 
 *     This constant limits the size of the authentication realm that can
 *     be received in an Authentication indication. The realm is sent by
 *     the challenger to convey which user id or password the claimant is
 *     to use. If OBEX_AUTHENTICATION is XA_DISABLED this option is ignored.
 *
 *     Valid range: 0 - 255.
 */
#ifndef OBEX_MAX_REALM_LEN
#define OBEX_MAX_REALM_LEN      20
#endif

#if OBEX_MAX_REALM_LEN > 255
#error OBEX_MAX_REALM_LEN must be less than 256
#endif

/*---------------------------------------------------------------------------
 * OBEX_TRANSPORT_FLOW_CTRL constant
 *
 *     This option enables/disables the API functions for application control
 *     over OBEX data flow. When enabled, the application can control the
 *     flow of data received by the client (during a GET) or the server
 *     (during a PUT).
 */
#ifndef OBEX_TRANSPORT_FLOW_CTRL
#define OBEX_TRANSPORT_FLOW_CTRL XA_ENABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_DISCOVERY_TIMEOUT constant
 * 
 *     This constant specifies the amount of time that the discovery process
 *     will be retried if the media happens to be busy when the transport 
 *     connection is requested.
 */
#ifndef OBEX_DISCOVERY_TIMEOUT
#define OBEX_DISCOVERY_TIMEOUT    5000      /* 5 seconds */
#endif

#if OBEX_DISCOVERY_TIMEOUT < 500
#error OBEX_DISCOVERY_TIMEOUT must be at least 500
#endif

/*---------------------------------------------------------------------------
 * OBEX_TLV_BUFF_SIZE constant
 * 
 *     This constant specifies the amount of memory allocated for reassembly
 *     of TLV buffers. It is only used when OBEX_TLV_PARSER is enabled.
 *     As a memory optimization, this value can be set to the largest expected
 *     TLV that an application must handle.
 *
 *     If a TLV arrives that is smaller than this constant, it will be
 *     reassembled before being provided to the application. If a TLV arrives
 *     that is larger than this constant, it will be provided to the application
 *     in multiple callbacks as the data arrives from the transport.
 *
 *     Note that TLVs larger than this constant may be indicated, if the 
 *     transport happens to provide them in contiguous fashion.
 *
 *     OBEX_TLV_BUFF_SIZE can be set to any value between 0 (to disable 
 *     reassembly of TLVs) or 255, the maximum TLV size (to always reassemble
 *     TLVs for the app).
 */
#ifndef OBEX_TLV_BUFF_SIZE
#define OBEX_TLV_BUFF_SIZE 255
#endif

#if OBEX_TLV_BUFF_SIZE > 255
#error There is no need for OBEX_TLV_BUFF_SIZE to be set above 255
#endif


/****************************************************************************
 *
 * Section: Header Function Configuration Constants
 *
 ****************************************************************************
 *
 *     The following 3 configuration options control which (if any) header
 *     functions are supported by the OBEX protocol.
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * OBEX_HEADER_PARSE constant
 *
 *     This option configures whether header parsing functions are included
 *     in the Header API. The parsing functions are used by the application
 *     to process headers received by the server and the client.  The
 *     default is to include these functions.
 */
#ifndef OBEX_HEADER_PARSE
#define OBEX_HEADER_PARSE XA_ENABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_HEADER_BUILD constant
 *
 *     This option configures whether header building functions are included
 *     in the Header API.  These functions are used by the application to
 *     build headers to send to the remote client or server. The default is
 *     to include these functions.
 */
#ifndef OBEX_HEADER_BUILD
#define OBEX_HEADER_BUILD XA_ENABLED
#endif

/*---------------------------------------------------------------------------
 * OBEX_USE_HEADER_MACROS constant
 *
 *     This option allows the application to compile-in C-macro versions of
 *     the header functions instead of the function versions. In some
 *     situations, this will result in a reduction of code size. However if
 *     it is necessary to preserve a function call style interface between
 *     the application and the OBEX parser this option cannot be enabled.
 *
 *     Only the parse functions offer a macro version.
 */
#ifndef OBEX_USE_HEADER_MACROS
#define OBEX_USE_HEADER_MACROS XA_DISABLED
#endif


/****************************************************************************
 *
 * Section: Non-modifiable Constants
 *
 ****************************************************************************
 *
 *     The following definitions should not be changed or overridden.
 *     They are based on definitions made earlier.
 *
 ****************************************************************************/
/*
#if (OBEX_ROLE_CLIENT == XA_DISABLED) && (OBEX_ROLE_SERVER == XA_DISABLED)
#error "One of OBEX_ROLE_CLIENT and OBEX_ROLE_SERVER options must be enabled."
#endif
*/
#if BT_STACK == XA_ENABLED

#if (OBEX_ROLE_CLIENT == XA_ENABLED) && (SDP_CLIENT_SUPPORT == XA_DISABLED)
#error OBEX Clients require SDP_CLIENT_SUPPORT to be enabled.
#endif

#if (OBEX_ROLE_SERVER == XA_ENABLED) && (SDP_SERVER_SUPPORT == XA_DISABLED)
#error OBEX Servers require SDP_SERVER_SUPPORT to be enabled.
#endif

#if (OBEX_ROLE_CLIENT == XA_ENABLED) && (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
#if SDP_SERVER_SUPPORT == XA_DISABLED
#error OBEX Clients that allow server transport connections require SDP_SERVER_SUPPORT.
#endif
#endif /* (OBEX_ROLE_CLIENT == XA_ENABLED) && (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#if (OBEX_ROLE_SERVER == XA_ENABLED) && (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
#if SDP_CLIENT_SUPPORT == XA_DISABLED
#error OBEX Servers that allow server transport connections require SDP_CLIENT_SUPPORT.
#endif
#endif /* (OBEX_ROLE_SERVER == XA_ENABLED) && (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#endif

/*---------------------------------------------------------------------------
 * OBEX_TLV_PARSER constant
 *
 *     The Authentication and Session code relies on the OBEX Byte Tag parser.
 */
#if (OBEX_AUTHENTICATION == XA_ENABLED) || (OBEX_SESSION_SUPPORT == XA_ENABLED)
#undef OBEX_TLV_PARSER
#define OBEX_TLV_PARSER XA_ENABLED

/* Make sure that there are at least 16 bytes available to handle the maximum
 * size session/authentication tags
 */
#if OBEX_TLV_BUFF_SIZE < 16
#undef OBEX_TLV_BUFF_SIZE
#define OBEX_TLV_BUFF_SIZE 16
#endif /* OBEX_TLV_BUFF_SIZE < 16 */

#endif /* (OBEX_AUTHENTICATION == XA_ENABLED) || (OBEX_SESSION_SUPPORT == XA_ENABLED) */

/*---------------------------------------------------------------------------
 * OBEX_ALLOW_SERVER_TP_DISCONNECT constant
 *
 *     If a Server is allowed to create a transport connection, it will be
 *     automatically allowed to disconnect transport connections.
 */
#if OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED
#undef OBEX_ALLOW_SERVER_TP_DISCONNECT
#define OBEX_ALLOW_SERVER_TP_DISCONNECT XA_ENABLED
#endif /* OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED */


/* OBEX support tx timer */
#ifndef OBEX_SUPPORT_TIMEOUT
#if (OBEX_ROLE_CLIENT == XA_ENABLED || OBEX_ROLE_SERVER == XA_ENABLED)
#define OBEX_SUPPORT_TIMEOUT  XA_ENABLED
#endif
#endif /* OBEX_SUPPORT_TIMEOUT */

/* OBEX_GET_USE_END_OF_BODY for server:
 * Server can use END_OF_BODY header in the last data packet or not.
 */
#ifndef OBEX_GET_USE_END_OF_BODY
#define OBEX_GET_USE_END_OF_BODY  XA_ENABLED
#endif


/****************************************************************************
 *
 * Obsolete Constants
 *
 ****************************************************************************
 *
 *     The following definitions are no longer used in the OBEX add-in.
 *
 ****************************************************************************/

#ifdef OBEX_IRMC_EXTENSIONS
#error OBEX_IRMC_EXTENSIONS is an unused configuration constant
#endif

#ifdef OBEX_NUM_SESSIONS
#error OBEX_NUM_SESSIONS is an unused configuration constant
#endif

#ifdef OBEX_MULTIPLE_CONS
#error OBEX_MULTIPLE_CONS is an unused configuration constant
#endif

#ifdef OBEX_ULTRA_LOW_TX_LIMIT
#error OBEX_ULTRA_LOW_TX_LIMIT is an unused configuration constant
#endif

#ifdef OB_TX_ULTRA_BUFF_SIZE
#error OB_TX_ULTRA_BUFF_SIZE is an unused configuration constant
#endif

#ifdef OBEX_ULTRA_PACKET_SIZE
#error OBEX_ULTRA_PACKET_SIZE is an unused configuration constant
#endif

#ifdef OBEX_IAS_DEFAULTS
#error OBEX_IAS_DEFAULTS is an unused configuration constant
#endif

#endif /* __OBCONFIG_H */

