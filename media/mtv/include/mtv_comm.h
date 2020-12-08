/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mtv_comm.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_COMM_H
#define _MTV_COMM_H

#ifndef _MED_GLOBAL_H
#include "med_global.h"
#endif

#ifndef _MTV_ERROR_H
#include "mtv_error.h"
#endif

#ifndef _MTV_CUSTOM_H
#include "mtv_custom.h"
#endif

#include "app_ltlcom.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mpl_common.h"

/* common constants */

#define MTV_CONTROL_MOD         MOD_MED
#define MTV_TRANSPORT_MOD       MOD_MED

#if defined(__MED_MTV_MOD__)
    #define MTV_BACKGROUND_MOD      MOD_MTV
#else
    /* ATV did not have background mod */
    #define MTV_BACKGROUND_MOD      MOD_MED
#endif

#define MTV_ASYNC_IO_MOD        MOD_MED_V
#define MTV_ESG_MOD             MOD_ESG

#define MTV_SETTING_PATH        L"z:\\@mtv\\"

/* helper macros */

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

#ifndef UNUSED
#define UNUSED(p) ((void)(p))
#endif

#define OFFSET_OF(s,m) ((int)&(((s*)0)->m))
#define PTHIS(p, parent, member) (parent*)(((int)p) - OFFSET_OF(parent,member))

#define TS_PACKET_BYTES 188
#define LEN_ADTS_HEADER 7

#define ENDIAN_FLIP(v) ( ((v) << 24) + (((v) & 0x0000ff00) << 8) + (((v) & 0x00ff0000) >> 8) + (((v) & 0xff000000) >> 24) )
#define MAKE_FOURCC(a,b,c,d) (((kal_uint32)a)|(((kal_uint32)b)<<8)|(((kal_uint32)c)<<16)|(((kal_uint32)d)<<24))
#define FOURCC_CHARS(fcc) *((char*)&fcc), *(((char*)&fcc) + 1), *(((char*)&fcc) + 2), *(((char*)&fcc) + 3)

#define CONSTRUCT_LOCAL_PARAM(st, name) \
    st* name = (st*) construct_local_para(sizeof(st), TD_CTRL)

/* debugging support */

#define NOT_REACHED(msg) ASSERT(0)
#define NOT_IMPLEMENTED(msg) ASSERT(0)
#define SHOULD_NOT_HAPPEN(msg) ASSERT(0)

//#define _MTV_SLA_LOGGING
#if defined(_MTV_SLA_LOGGING) && defined(__MTK_TARGET__)
    #define SLA_BEGIN(job) SLA_CustomLogging(job, SA_start)
    #define SLA_END(job) SLA_CustomLogging(job, SA_stop)
    #define SLA_LABEL(job) SLA_CustomLogging(job, SA_label)
#else
    #define SLA_BEGIN(job) do {} while (0)
    #define SLA_END(job) do {} while (0)
    #define SLA_LABEL(job) do {} while (0)
#endif

//#define _MTV_DEBUG
#if defined(_MTV_DEBUG)
#define mtv_prompt_trace kal_prompt_trace
#else
#define mtv_prompt_trace 1 ? (void) 0 : kal_prompt_trace
#endif

//#define _MTV_ZAPPING_DEBUG
#if defined(_MTV_ZAPPING_DEBUG)
#define mtv_zapping_trace kal_prompt_trace
#else
#define mtv_zapping_trace 1 ? (void) 0 : kal_prompt_trace
#endif

#define mtv_error_from_fs(fs_error) (fs_error < 0 ? (MTV_IO_E_BASE + (fs_error)) : MTV_S_OK)

#define MTV_TRACE_TIME(msg) mtv_prompt_trace(MOD_MED, "[MTV][TIMING]" msg)

/* common structures */

/**
  * Flags that can be tagged on a packet.
  */
typedef enum
{
    MTV_PACKET_FROM_CL_TDMB_DEMUX        = 0x0001,   /**< this packet is from CyberLink's demux */
    MTV_PACKET_WITH_ADTS_HEADER          = 0X0002,   /**< this packet contains ADTS header */
    MTV_PACKET_WITH_H264_START_CODE      = 0X0004,   /**< this packet contains H.264 start code */
    MTV_PACKET_WITH_RANDOM_ACCESS_POINT  = 0x0008,   /**< this packet contains random access point of elementary stream */
    MTV_PACKET_IS_CONCEALMENT            = 0x0010,   /**< this packet is an audio/video concealment */
    MTV_PACKET_AGGREGATION               = 0x0020,   /**< this packet contains multiple parts which are prefixed by 16-bit uint size information */
    MTV_PACKET_RECEIVER_SHOULD_FREE      = 0x0040,   /**< indicates that the receiver of this packet should free the buffer */
    MTV_PACKET_IS_LAST_PACKET            = 0x0080,
    MTV_PACKET_WITH_FEC                  = 0x0100
} mtv_packet_flag_t;

/**
  * Generic data packet that is used to pass any data with timestamp.
  */
typedef struct
{
    kal_uint8* data;        /**< data pointer */
    kal_uint32 size;        /**< data size in bytes */
    kal_uint32 timestamp;   /**< the timestamp */
    kal_uint32 flags;       /**< flags to indicate some special packets. @see mtv_packet_flag_t */

} mtv_packet_t;

/**
  * Frequency band.
  */
typedef enum
{
    MTV_FREQ_INVALID_BAND,
    MTV_FREQ_KOREA_BAND,
    MTV_FREQ_BAND_III,
    MTV_FREQ_L_BAND,
    MTV_FREQ_CANADA_BAND,
    MTV_FREQ_CHINESE_BAND,
    MTV_FREQ_BAND_II,
    MTV_FREQ_BAND_IF,

    /* from Analog TV */
    MTV_FREQ_ATV_BEGIN,
    MTV_FREQ_AFGHANISTAN = MTV_FREQ_ATV_BEGIN,
    MTV_FREQ_ARGENTINA,
    MTV_FREQ_AUSTRALIA,
    MTV_FREQ_BRAZIL,
    MTV_FREQ_BURMA,
    MTV_FREQ_CAMBODIA,
    MTV_FREQ_CANADA,
    MTV_FREQ_CHILE,
    MTV_FREQ_CHINA,
    MTV_FREQ_CHINA_HONGKONG,
    MTV_FREQ_CHINA_SHENZHEN,
    MTV_FREQ_EUROPE_EASTERN,
    MTV_FREQ_EUROPE_WESTERN,
    MTV_FREQ_FRANCE,
    MTV_FREQ_FRENCH_COLONIE,
    MTV_FREQ_INDIA,
    MTV_FREQ_INDONESIA,
    MTV_FREQ_IRAN,
    MTV_FREQ_ITALY,
    MTV_FREQ_JAPAN,
    MTV_FREQ_KOREA,
    MTV_FREQ_LAOS,
    MTV_FREQ_MALAYSIA,
    MTV_FREQ_MEXICO,
    MTV_FREQ_NEWZEALAND,
    MTV_FREQ_PAKISTAN,
    MTV_FREQ_PARAGUAY,
    MTV_FREQ_PHILIPPINES,
    MTV_FREQ_PORTUGAL,
    MTV_FREQ_RUSSIA,
    MTV_FREQ_SINGAPORE,
    MTV_FREQ_SOUTHAFRICA,
    MTV_FREQ_SPAIN,
    MTV_FREQ_TAIWAN,
    MTV_FREQ_THAILAND,
    MTV_FREQ_TURKEY,
    MTV_FREQ_UNITED_ARAB_EMIRATES,
    MTV_FREQ_UNITED_KINGDOM,
    MTV_FREQ_USA,
    MTV_FREQ_URUGUAY,
    MTV_FREQ_VENEZUELA,
    MTV_FREQ_VIETNAM,
    MTV_FREQ_IRELAND,
    MTV_FREQ_MOROCCO,
    MTV_FREQ_ATV_END = MTV_FREQ_MOROCCO,

    MTV_FREQ_ANY_BAND       /**< a special value to indicate any supported band */

} mtv_freq_band_t;

/* utility functions */

extern kal_wchar* mtv_filename_dup(const kal_wchar* from);
extern kal_wchar* mtv_generate_new_filename(const kal_wchar* dir, const kal_wchar* basename, const kal_wchar* extname);
extern kal_wchar* mtv_str_dup(const kal_wchar* from, kal_uint32 max_len, kal_uint32 usage);
extern kal_wchar* mtv_alloc_filename(void);

typedef kal_bool (*mtv_process_file_callback)(void* param, const kal_wchar* filename);
extern kal_uint32 mtv_process_files(const kal_wchar* dir, const kal_wchar* pattern, mtv_process_file_callback process_file, void* callback_param);

extern kal_int32 mtv_get_service_dump_drive(void);
extern const kal_wchar* mtv_get_setting_dir(void);

extern kal_uint32 mtv_copy_str_with_escape_keyword(kal_wchar* str_dst, kal_wchar* str_src, const kal_wchar* invalid_chars, kal_wchar keyword);

/**
  * To execute specified callback in the context of specified module.
  */
extern void mtv_call_async(module_type src_mod_id, void (*proc)(void* param), void* param);

/**
  * Check whether ther is any pending MTV request messages.
  */
extern kal_bool mtv_check_pending_requests(void);

/* external memory allocation */

extern void* mtv_alloc_ext_mem_impl(kal_int32 size, kal_uint32 fourcc, char* file_p, long line_p);
extern void* mtv_alloc_ext_mem_cache_impl(kal_int32 size, kal_uint32 fourcc, char* file_p, long line_p);
#define mtv_alloc_ext_mem(size, fourcc) mtv_alloc_ext_mem_impl(size, fourcc, __FILE__, __LINE__)
#define mtv_alloc_ext_mem_cache(size, fourcc) mtv_alloc_ext_mem_cache_impl(size, fourcc, __FILE__, __LINE__)

extern void mtv_free_ext_mem_impl(void** p, char* file_p, long line_p);
#define mtv_free_ext_mem(pointer) mtv_free_ext_mem_impl(pointer, __FILE__, __LINE__)

/* timer service: to decouple MTV implementation and platform-depedent timer mechanism */

typedef void (*mtv_timer_callback_t)(void* param);

extern void mtv_start_transport_timer(kal_uint32 init_time, mtv_timer_callback_t callback, void* param);
extern void mtv_stop_transport_timer(void);

extern void mtv_start_timeshift_timer(kal_uint32 init_time, mtv_timer_callback_t callback, void* param);
extern void mtv_stop_timeshift_timer(void);

extern mtv_result_t mpl_media_error_to_mtv_result(media_error_t ret);

/* global EM switches */

extern kal_bool g_mtv_dump_service;
extern kal_bool g_mtv_show_demod_status;
extern kal_bool g_mtv_atv_sim;
extern kal_bool g_mtv_atv_default_chlist;
extern kal_uint32 g_mtv_demod_sim;
extern kal_uint32 g_mtv_fair_reception_threshold;
extern kal_bool g_mtv_dump_esg_xml_file;

extern void mtv_atv_set_channel_scan_mode(kal_bool enable);
extern kal_bool mtv_atv_get_channel_scan_mode(void);

/* CAS: */
extern kal_bool g_mtv_em_set_cat;
extern kal_bool g_mtv_mts_command;
extern kal_uint32 g_mtv_em_emm_service_id;
extern kal_uint32 g_mtv_em_ecm_data_type;
extern kal_uint32 g_mtv_em_emm_data_type;

/* MSVC-specific */

#if defined(_MSC_VER)
#pragma warning(disable:4514 4127)
#endif

#endif /* _MTV_COMM_H */
