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
 * msf_mime.h
 *
 * File extension to MIME type conversion.
 *
 */


#ifndef _msf_mime_h
#define _msf_mime_h

#ifndef _msf_def_h
#include "msf_def.h"
#endif
#ifndef _msf_cmmn_h
#include "msf_cmmn.h"
#endif

/************************************************************ 
 * Constants
 ************************************************************/

/*
 * Media types that have a pre-defined integer representation.
 * OMNA "Well-Known Values".
 */
#define MSF_MIME_TYPE_ANY_ANY                                    0x00
#define MSF_MIME_TYPE_TEXT_ANY                                   0x01
#define MSF_MIME_TYPE_TEXT_HTML                                  0x02
#define MSF_MIME_TYPE_TEXT_PLAIN                                 0x03
#define MSF_MIME_TYPE_TEXT_X_HDML                                0x04
#define MSF_MIME_TYPE_TEXT_X_TTML                                0x05
#define MSF_MIME_TYPE_TEXT_X_VCALENDAR                           0x06
#define MSF_MIME_TYPE_TEXT_X_VCARD                               0x07
#define MSF_MIME_TYPE_TEXT_VND_WAP_WML                           0x08
#define MSF_MIME_TYPE_TEXT_VND_WAP_WMLSCRIPT                     0x09
#define MSF_MIME_TYPE_TEXT_VND_WAP_CHANNEL                       0x0a
#define MSF_MIME_TYPE_MULTIPART_ANY                              0x0b
#define MSF_MIME_TYPE_MULTIPART_MIXED                            0x0c
#define MSF_MIME_TYPE_MULTIPART_FORM_DATA                        0x0d
#define MSF_MIME_TYPE_MULTIPART_BYTERANGES                       0x0e
#define MSF_MIME_TYPE_MULTIPART_ALTERNATIVE                      0x0f
#define MSF_MIME_TYPE_APPLICATION_ANY                            0x10
#define MSF_MIME_TYPE_APPLICATION_JAVA_VM                        0x11
#define MSF_MIME_TYPE_APPLICATION_X_WWW_FORM_URLENCODED          0x12
#define MSF_MIME_TYPE_APPLICATION_X_HDMLC                        0x13
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WMLC                   0x14
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WMLSCRIPTC             0x15
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CHANNELC               0x16
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_UAPROF                 0x17
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WTLS_CA_CERTIFICATE    0x18
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WTLS_USER_CERTIFICATE  0x19
#define MSF_MIME_TYPE_APPLICATION_X_X509_CA_CERT                 0x1a
#define MSF_MIME_TYPE_APPLICATION_X_X509_USER_CERT               0x1b
#define MSF_MIME_TYPE_IMAGE_ANY                                  0x1c
#define MSF_MIME_TYPE_IMAGE_GIF                                  0x1d
#define MSF_MIME_TYPE_IMAGE_JPEG                                 0x1e
#define MSF_MIME_TYPE_IMAGE_TIFF                                 0x1f
#define MSF_MIME_TYPE_IMAGE_PNG                                  0x20
#define MSF_MIME_TYPE_IMAGE_VND_WAP_WBMP                         0x21
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_ANY          0x22
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_MIXED        0x23
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_FORM_DATA    0x24
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_BYTERANGES   0x25
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_ALTERNATIVE  0x26
#define MSF_MIME_TYPE_APPLICATION_XML                            0x27
#define MSF_MIME_TYPE_TEXT_XML                                   0x28
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_WBXML                  0x29
#define MSF_MIME_TYPE_APPLICATION_X_X968_CROSS_CERT              0x2a
#define MSF_MIME_TYPE_APPLICATION_X_X968_CA_CERT                 0x2b
#define MSF_MIME_TYPE_APPLICATION_X_X968_USER_CERT               0x2c
#define MSF_MIME_TYPE_TEXT_VND_WAP_SI                            0x2d
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIC                    0x2e
#define MSF_MIME_TYPE_TEXT_VND_WAP_SL                            0x2f
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SLC                    0x30
#define MSF_MIME_TYPE_TEXT_VND_WAP_CO                            0x31
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_COC                    0x32
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MULTIPART_RELATED      0x33
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIA                    0x34
#define MSF_MIME_TYPE_TEXT_VND_WAP_CONNECTIVITY_XML              0x35
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CONNECTIVITY_WBXML     0x36
#define MSF_MIME_TYPE_APPLICATION_PKCS7_MIME                     0x37
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_HASHED_CERTIFICATE     0x38
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_SIGNED_CERTIFICATE     0x39
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_CERT_RESPONSE          0x3a
#define MSF_MIME_TYPE_APPLICATION_XHTML_XML                      0x3b
#define MSF_MIME_TYPE_APPLICATION_WML_XML                        0x3c
#define MSF_MIME_TYPE_TEXT_CSS                                   0x3d
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_MMS_MESSAGE            0x3e
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_ROLLOVER_CERTIFICATE   0x3f
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_LOCC_WBXML             0x40
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_LOC_XML                0x41
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_DM_WBXML            0x42
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_DM_XML              0x43
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_NOTIFICATION        0x44
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_XHTML_XML              0x45
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_CIR                 0x46
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DD_XML                 0x47
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_MESSAGE            0x48
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_CONTENT            0x49
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_XML         0x4a
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RIGHTS_WBXML       0x4b
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_XML                 0x4c
#define MSF_MIME_TYPE_APPLICATION_VND_WV_CSP_WBXML               0x4d
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_DS_NOTIFICATION     0x4e
#define MSF_MIME_TYPE_AUDIO_ANY                                  0x4f
#define MSF_MIME_TYPE_VIDEO_ANY                                  0x50
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DD2_XML                0x51
#define MSF_MIME_TYPE_TEXT_VCARD								 0x52
/*
 * OMNA "Registered Values"
 */
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_CACHEOP_WBXML        0x0201
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_SIGNAL               0x0202
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_ALERT_WBXML          0x0203
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_LIST_WBXML           0x0204
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_LISTCMD_WBXML        0x0205
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_CHANNEL_WBXML        0x0206
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_PROVISIONING_STATUS_URI 0x0207
#define MSF_MIME_TYPE_X_WAP_MULTIPART_VND_UPLANET_HEADER_SET       0x0208
#define MSF_MIME_TYPE_APPLICATION_VND_UPLANET_BEARER_CHOICE_WBXML  0x0209
#define MSF_MIME_TYPE_APPLICATION_VND_PHONECOM_MMC_WBXML           0x020a
#define MSF_MIME_TYPE_APPLICATION_VND_NOKIA_SYNCSET_WBXML          0x020b
#define MSF_MIME_TYPE_IMAGE_X_UP_WPNG                              0x020c

#define MSF_MIME_TYPE_APPLICATION_IOTA_MMC_WBXML                   0x0300
#define MSF_MIME_TYPE_APPLICATION_IOTA_MMC                         0x0301
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_XML                   0x0302
#define MSF_MIME_TYPE_APPLICATION_VND_SYNCML_WBXML                 0x0303
#define MSF_MIME_TYPE_TEXT_EMN_XML                                 0x0304
#define MSF_MIME_TYPE_TEXT_CALENDER                                0x0305
#define MSF_MIME_TYPE_APPLICATION_VND_OMADS_EMAIL_XML              0x0306
#define MSF_MIME_TYPE_APPLICATION_VND_OMADS_FILE_XML               0x0307
#define MSF_MIME_TYPE_APPLICATION_VND_OMADS_FOLDER_XML             0x0308
#define MSF_MIME_TYPE_TEXT_DIRECTORY_PROFILE_VCARD                 0x0309
#define MSF_MIME_TYPE_APPLICATION_VND_WAP_EMN_WBXML                0x030a
#define MSF_MIME_TYPE_APPLICATION_VND_NOKIA_IPDC_PURCHASE_RESPONSE 0x030b
#define MSF_MIME_TYPE_APPLICATION_VND_MOTOROLA_SCREEN3_XML         0x030c
#define MSF_MIME_TYPE_APPLICATION_VND_MOTOROLA_SCREEN3_GZIP        0x030d
#define MSF_MIME_TYPE_APPLICATION_VND_CMCC_SETTING_WBXML           0x030e
#define MSF_MIME_TYPE_APPLICATION_VND_CMCC_BOMBING_WBXML           0x030f
#define MSF_MIME_TYPE_APPLICATION_VND_DOCOMO_PF                    0x0310
#define MSF_MIME_TYPE_APPLICATION_VND_DOCOMO_UB                    0x0311 
#define MSF_MIME_TYPE_APPLICATION_VND_OMALOC_SUPL_INIT             0x0312 
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_GROUP_USAGE_LIST_XML     0x0313 
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DIRECTORY_XML            0x0314 

/*
 * Other media types that have a pre-defined integer representation.
 * These are pre-defined internally by MSF and used to enable the 
 * parser to handle these media types.
 */

#define MSF_MIME_TYPE_AUDIO_MID                                  0x010000a1
#define MSF_MIME_TYPE_AUDIO_MPEG                                 0x010000a2
#define MSF_MIME_TYPE_AUDIO_X_WAV                                0x010000a3
#define MSF_MIME_TYPE_APPLICATION_X_VND_MMS_TEMPLATE_TEXTS       0x010000a4
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_BROWSER_SETTINGS    0x010000a5
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_BROWSER_BOOKMARKS   0x010000a6
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_SYNCSET_XML         0x010000a7
#define MSF_MIME_TYPE_APPLICATION_X_WAP_PROV_SYNCSET_WBXML       0x010000a8
#define MSF_MIME_TYPE_APPLICATION_SMIL                           0x010000a9
#define MSF_MIME_TYPE_IMAGE_SVG                                  0x010000aa
#define MSF_MIME_TYPE_IMAGE_BMP                                  0x010000ab
#define MSF_MIME_TYPE_VIDEO_MPEG                                 0x010000ac
#define MSF_MIME_TYPE_APPLICATION_VND_SMAF                       0x010000ad
#define MSF_MIME_TYPE_APPLICATION_X_SMAF                         0x010000ae
#define MSF_MIME_TYPE_AUDIO_AMR                                  0x010000af
#define MSF_MIME_TYPE_APPLICATION_X_SHOCKWAVE_FLASH              0x010000b0
#define MSF_MIME_TYPE_APPLICATION_ZIP                            0x010000b1
#define MSF_MIME_TYPE_AUDIO_MIDI                                 0x010000b2
#define MSF_MIME_TYPE_AUDIO_X_MIDI                               0x010000b3
#define MSF_MIME_TYPE_AUDIO_SP_MIDI                              0x010000b4
#define MSF_MIME_TYPE_AUDIO_IMELODY                              0x010000b5
#define MSF_MIME_TYPE_TEXT_X_IMELODY                             0x010000b6
#define MSF_MIME_TYPE_TEXT_DIRECTORY                             0x010000b7
#define MSF_MIME_TYPE_TEXT_X_VMESSAGE                            0x010000b8
#define MSF_MIME_TYPE_TEXT_X_VBOOKMARK                           0x010000b9
#define MSF_MIME_TYPE_TEXT_X_VNOTE                               0x010000ba
#define MSF_MIME_TYPE_APPLICATION_XML_XHTML                      0x010000bb
#define MSF_MIME_TYPE_APPLICATION_WAP_WML_XML                    0x010000bc
#define MSF_MIME_TYPE_AUDIO_X_MID                                0x010000bd
#define MSF_MIME_TYPE_AUDIO_X_MPEG                               0x010000be
#define MSF_MIME_TYPE_IMAGE_SVG_XML                              0x010000bf
#define MSF_MIME_TYPE_IMAGE_SVG_DASH_XML                         0x010000c0
#define MSF_MIME_TYPE_VIDEO_MNG                                  0x010000c1
#define MSF_MIME_TYPE_VIDEO_X_MNG                                0x010000c2
#define MSF_MIME_TYPE_AUDIO_X_AMR                                0x010000c3
#define MSF_MIME_TYPE_AUDIO_XMF0                                 0x010000c4
#define MSF_MIME_TYPE_AUDIO_XMF1                                 0x010000c5
#define MSF_MIME_TYPE_VIDEO_3GPP                                 0x010000c6
#define MSF_MIME_TYPE_AUDIO_3GPP                                 0x010000c7
#define MSF_MIME_TYPE_VIDEO_MP4                                  0x010000c8
#define MSF_MIME_TYPE_AUDIO_MP4                                  0x010000c9
#define MSF_MIME_TYPE_APPLICATION_REALMEDIA                      0x010000ca
#define MSF_MIME_TYPE_APPLICATION_REALAUDIO                      0x010000cb
#define MSF_MIME_TYPE_APPLICATION_SDP                            0x010000cc
#define MSF_MIME_TYPE_TEXT_JAVA_DESCRIPTOR                       0x010000cd
#define MSF_MIME_TYPE_APPLICATION_JAVA                           0x010000ce
#define MSF_MIME_TYPE_APPLICATION_JAVA_ARCHIVE                   0x010000cf
#define MSF_MIME_TYPE_APPLICATION_OCTET_STREAM                   0x010000d0
#define MSF_MIME_TYPE_MULTIPART_RELATED                          0x010000d1
#define MSF_MIME_TYPE_AUDIO_WAV                                  0x010000d2
#define MSF_MIME_TYPE_AUDIO_MPEG_URL                             0x010000d3
#define MSF_MIME_TYPE_X_OBIGO_URL                                0x010000d4
#define MSF_MIME_TYPE_X_OBIGO_TEL                                0x010000d5
#define MSF_MIME_TYPE_X_OBIGO_RTSP                               0x010000d6
#define MSF_MIME_TYPE_X_OBIGO_MAILTO                             0x010000d7
#define MSF_MIME_TYPE_X_OBIGO_ADDRESS                            0x010000d8
#define MSF_MIME_TYPE_X_OBIGO_MSGTO                              0x010000d9
#define MSF_MIME_TYPE_X_OBIGO_MIDLET_ID                          0x010000da
#define MSF_MIME_TYPE_AUDIO_AAC                                  0x010000db
#define MSF_MIME_TYPE_MS_WORD                                    0x010000dc
#define MSF_MIME_TYPE_MS_EXCEL                                   0x010000dd
#define MSF_MIME_TYPE_MS_POWERPOINT                              0x010000de
#define MSF_MIME_TYPE_MESSAGE_RFC822                             0x010000df
#define MSF_MIME_TYPE_AUDIO_M4A                                  0x010000e0
#define MSF_MIME_TYPE_AUDIO_X_M4A                                0x010000e1
#define MSF_MIME_TYPE_VIDEO_MP4V_ES                              0x010000e2
#define MSF_MIME_TYPE_VIDEO_H263_2000                            0x010000e3
#define MSF_MIME_TYPE_AUDIO_QCELP                                0x010000e4
#define MSF_MIME_TYPE_AUDIO_EVRC                                 0x010000e5
#define MSF_MIME_TYPE_AUDIO_VND_QCELP                            0x010000e6
#define MSF_MIME_TYPE_VIDEO_3GPP2                                0x010000e7
#define MSF_MIME_TYPE_AUDIO_3GPP2                                0x010000e8
#define MSF_MIME_TYPE_AUDIO_MP4A_LATM                            0x010000e9
#define MSF_MIME_TYPE_VIDEO_X_MS_WMV                             0x010000ea
#define MSF_MIME_TYPE_AUDIO_XMF                                  0x010000eb
#define MSF_MIME_TYPE_AUDIO_X_AAC                                0x010000ec 
#define MSF_MIME_TYPE_AUDIO_SMAF                                 0x010000ed
#define MSF_MIME_TYPE_AUDIO_X_MS_WMA                             0x010000ee
#define MSF_MIME_TYPE_APPLICATION_X_EXE                          0x010000ef
#define MSF_MIME_TYPE_VIDEO_3GP                                  0x010000f0
#define MSF_MIME_TYPE_AUDIO_3GP                                  0x010000f1


#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_RO_XML             0x010000f2
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_DCF                0x010000f3
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_ROAP_PDU_XML       0x010000f4
#define MSF_MIME_TYPE_APPLICATION_VND_OMA_DRM_ROAP_TRIGGER_XML   0x010000f5

#define MSF_MIME_TYPE_AUDIO_PMD                          0x010000f6


#define MSF_MIME_TYPE_APPLICATION_OWL_SKIN                       0x01000100         

#define MSF_MIME_TYPE_UNKNOWN                                    0x7fffffff

/************************************************************ 
 * Exported Variables
 ************************************************************/

extern const msf_strtable_info_t gmms_msf_mime_types;

/************************************************************ 
 * Exported functions
 ************************************************************/

/*
 * Returns the corresponding mime type for a file extension 
 */
const char*
gmms_msf_mime_ext_to_mime (const char *ext);

/*
 * Returns the corresponding file extension for a mime type
 */
const char*
gmms_msf_mime_to_ext (const char *mime);

/*
 * Returns the integer representation for the mime type
 */
MSF_INT32 
gmms_msf_mime_to_int (const char *mime);

/*
 * Returns the mime type given an integer representation.
 */
const char *
gmms_msf_int_to_mime (MSF_INT32 known_value);

/*
 * Returns the integer representation for the file extension
 * Note! that it is the integer representation of the mime type
 * corresponding to the extension that is returned.
 */
MSF_INT32 
gmms_msf_mime_ext_to_int (const char *ext);


#define msf_mime_types gmms_msf_mime_types

#define msf_mime_ext_to_mime gmms_msf_mime_ext_to_mime

#define msf_mime_to_ext gmms_msf_mime_to_ext

#define msf_mime_to_int gmms_msf_mime_to_int

#define msf_int_to_mime gmms_msf_int_to_mime

#define msf_mime_ext_to_int gmms_msf_mime_ext_to_int

#endif
