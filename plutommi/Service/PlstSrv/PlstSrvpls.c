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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  PlstSrvpls.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  palyer list service
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

#include "FileMgrSrvGProt.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "gui_data_types.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Conversions.h"
#include "meta_tag_api.h"
#include "l1audio.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "gdi_datatype.h"
#include "gdi_const.h"
#include "stack_config.h"
#include "string.h"
#include "drm_def.h"
#include "stack_ltlcom.h"
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "kal_public_defs.h"
#include "kal_release.h"
#include "sqlite3.h"
#include "task_main_func.h"
#include "kal_active_module.h"
#include "task_config.h"
#include "hisr_config.h"
#include "syscomp_config.h"
#include "mmi_frm_events_gprot.h"
#ifdef __PLST_SERVICE_DB_SUPPORT__
#include "PlstSrvGprot.h"
#include "PlstSrv.h"
#include "PlstSrvpls.h"
#include "Drm_gprot.h"
#include "RightsMgrGProt.h"

#define PLS_TASK_SLEEP_TIME  10

//#define __PERFORMANCE_TEST_GEN_DB__

extern pls_ps_cntx_struct* g_pls_db_cntx;
extern srv_plst_control_struct* g_srv_plst_control_ptr;
extern U32 g_srv_plst_query_album_id;       //stamp currently artwork id, in order to avoid not sync case.

#ifdef __PERFORMANCE_TEST_GEN_DB__
static kal_uint32 start_tick1 = 0;
static kal_uint32 end_tick1 = 0;
static kal_uint32 start_tick2 = 0;
static kal_uint32 end_tick2 = 0;
static kal_uint32 total_tick = 0;
static kal_uint32 total_tick2 = 0;
static kal_uint32 total_firstn_tick = 0;
static kal_uint32 total_nextn_tick = 0;

#define PTGB_TOTAL_START() total_tick = 0
#define PTGB_START_1() kal_get_time(&start_tick1)
#define PTGB_START_2() kal_get_time(&start_tick2)
#define PTGB_END_1() kal_get_time(&end_tick1); total_tick += end_tick1-start_tick1
#define PTGB_END_2() kal_get_time(&end_tick2); total_tick2 += end_tick2 - start_tick2;

#define PTGB_ROUND_REPORT(i) MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_CURR_ROUND, i, kal_ticks_to_milli_secs(end_tick1-start_tick1));   
#define PTGB_TOTAL_REPORT() MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_TOTAL, kal_ticks_to_milli_secs(total_tick), __LINE__)

#define PTGB_FIRSTN_START() kal_get_time(&start_tick1)
#define PTGB_FIRSTN_END() kal_get_time(&end_tick1); total_firstn_tick += end_tick1-start_tick1
#define PTGB_FIRSTN_REPORT() MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_CURR, kal_ticks_to_milli_secs(end_tick1-start_tick1), kal_ticks_to_milli_secs(total_firstn_tick))

#define PTGB_NEXTN_START() kal_get_time(&start_tick1)
#define PTGB_NEXTN_END() kal_get_time(&end_tick1); total_nextn_tick += end_tick1-start_tick1
#define PTGB_NEXTN_REPORT() MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_CURR, kal_ticks_to_milli_secs(end_tick1-start_tick1), kal_ticks_to_milli_secs(total_nextn_tick))


#define PTGB_COMIT_TOTAL_REPORT() MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_COMIT_TOTAL, kal_ticks_to_milli_secs(total_tick2), __LINE__)


#else

#define PTGB_TOTAL_START()
#define PTGB_START_1()
#define PTGB_START_2()
#define PTGB_END_1()
#define PTGB_END_2()

#define PTGB_ROUND_REPORT(i)
#define PTGB_TOTAL_REPORT()

#define PTGB_FIRSTN_START()
#define PTGB_FIRSTN_END()
#define PTGB_FIRSTN_REPORT()

#define PTGB_NEXTN_START()
#define PTGB_NEXTN_END()
#define PTGB_NEXTN_REPORT()
#define PTGB_COMIT_TOTAL_REPORT()

#endif


const srv_plst_support_format_struct srv_plst_support_format[] = 
{ 
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef WMA_DECODE
    {SRV_PLST_FORMAT_WMA, L"WMA"},
#endif
#ifdef AAC_DECODE
    {SRV_PLST_FORMAT_M4A, L"M4A"},
#endif
#ifdef DAF_DECODE    
    {SRV_PLST_FORMAT_DAF, L"MP3"},
#ifdef MUSICAM_DECODE
    {SRV_PLST_FORMAT_MP2, L"MP2"},
#endif
#endif
#ifdef __APE_DECODE__
    {SRV_PLST_FORMAT_APE,  L"APE"},
#endif
#ifdef AAC_DECODE
    {SRV_PLST_FORMAT_AAC, L"AAC"},
#endif
#ifdef __VORBIS_DECODE__
    {SRV_PLST_FORMAT_OGG, L"OGG"},
#endif
#ifdef __FLAC_DECODE__ 
    {SRV_PLST_FORMAT_FLAC, L"FLAC"},
#endif

#else /* __COSMOS_MMI_PACKAGE__ */

#ifdef DAF_DECODE    
    {SRV_PLST_FORMAT_DAF, L"MP3"},
#ifdef MUSICAM_DECODE
    {SRV_PLST_FORMAT_MP2, L"MP2"},
#endif
#endif
#ifdef __RM_DEC_SUPPORT__
    {SRV_PLST_FORMAT_RA, L"RA"},
#endif /* __RM_DEC_SUPPORT__ */
    {SRV_PLST_FORMAT_AMR, L"AMR"},
#ifdef AAC_DECODE
    {SRV_PLST_FORMAT_AAC, L"AAC"},
#endif
#ifdef AMRWB_DECODE
    {SRV_PLST_FORMAT_AWB, L"AWB"},
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    {SRV_PLST_FORMAT_ODF, L"ODF"},
#endif
    {SRV_PLST_FORMAT_WAV, L"WAV"},
    {SRV_PLST_FORMAT_MID, L"MID"},
    {SRV_PLST_FORMAT_MIDI, L"MIDI"},
    {SRV_PLST_FORMAT_IMY, L"IMY"},
#ifdef AIFF_DECODE
    {SRV_PLST_FORMAT_AIFF, L"AIFF"},
    {SRV_PLST_FORMAT_AIF, L"AIF"},
    {SRV_PLST_FORMAT_AIFC, L"AIFC"},
#endif
#ifdef AU_DECODE
    {SRV_PLST_FORMAT_AU, L"AU"},
#endif
#ifdef SND_DECODE
    {SRV_PLST_FORMAT_SND, L"SND"},
#endif
#ifdef YAMAHA_MA3
    {SRV_PLST_FORMAT_MMF, L"MMF"},
#endif
#ifdef WMA_DECODE
    {SRV_PLST_FORMAT_WMA, L"WMA"},
#endif
#ifdef AAC_DECODE
    {SRV_PLST_FORMAT_M4A, L"M4A"},
#endif
#if (!defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)) 
    {SRV_PLST_FORMAT_3GP_AUDIO, L"3GP"},
    {SRV_PLST_FORMAT_MP4_VIDEO, L"MP4"},
    {SRV_PLST_FORMAT_3G2A, L"3G2"},
#endif
#ifdef __MMI_PURE_AUDIO__
    {SRV_PLST_FORMAT_3GA, L"3GA"},
#endif
#ifdef __APE_DECODE__
    {SRV_PLST_FORMAT_APE,  L"APE"},
#endif
/* OGG decode only support sound recorder result for SLIM version, do not scan into play list */
#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {SRV_PLST_FORMAT_OGG, L"OGG"},
#endif
#ifdef __FLAC_DECODE__ 
    {SRV_PLST_FORMAT_FLAC, L"FLAC"},
#endif
/*video*/
#ifdef MP4_DECODE
    {SRV_PLST_FORMAT_3GP, L"3GP"},
    {SRV_PLST_FORMAT_MP4, L"MP4"},
    {SRV_PLST_FORMAT_MPG, L"MPG"},
    {SRV_PLST_FORMAT_3G2, L"3G2"},
#endif
#ifdef __RM_DEC_SUPPORT__
    {SRV_PLST_FORMAT_RV, L"RV"},
    {SRV_PLST_FORMAT_RM, L"RM"},
    {SRV_PLST_FORMAT_RMVB, L"RMVB"},
#endif  /* __RM_DEC_SUPPORT__ */ 
#ifdef MJPG_DECODE
    {SRV_PLST_FORMAT_AVI, L"AVI"},
#endif
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    {SRV_PLST_FORMAT_FLV, L"FLV"},
    {SRV_PLST_FORMAT_F4V, L"F4V"},
#endif
#ifdef __MMI_VIDEO_STREAM__
    {SRV_PLST_FORMAT_SDP, L"SDP"},
    {SRV_PLST_FORMAT_RAM, L"RAM"},
#endif
#ifdef __MKV_FILE_FORMAT_SUPPORT__
    {SRV_PLST_FORMAT_MKV, L"MKV"},
    {SRV_PLST_FORMAT_WEBM, L"WEBM"},
#ifdef __VIDEO_3D_SIDE_BY_SIDE__
    {SRV_PLST_FORMAT_MK3D, L"MK3D"},
#endif
#endif /* __MKV_FILE_FORMAT_SUPPORT__ */
#ifdef __MOT_SUPPORT__
    {SRV_PLST_FORMAT_MOT, L"MOT"},
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */
};

/* crc */
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);
extern S32 pls_sql_get_artist_media_count(srv_plst_db_context_struct *db, U32 id, U32 *count);
extern S32 pls_sql_get_artwork_parser_path_by_id(srv_plst_db_context_struct *db, U32 id, U32 *data);
/******************************************************************
 * FUNCTION
 *    pls_db_get_sernaria_number
 * DESCRIPTION
 *  get senaria number
 * PARAMETERS
 *  drv_letter       [IN]    U8
 * RETURNS
 *  return number
 ******************************************************************/
static U32 pls_db_get_sernaria_number(U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    UI_character_type drv_path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
       return 1234567890;
    }
    else
    {
        return 1;
    }
#endif
    if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        kal_wsprintf(drv_path, "%c:\\", drv_letter);
        FS_GetDiskInfo(drv_path, &disk_info, FS_DI_BASIC_INFO);
        return disk_info.SerialNumber;
    }
    else
    {
        return 0;
    }
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_get_security_info
 * DESCRIPTION
 *  get target security info
 * PARAMETERS
 *  drv_letter       [IN]    U8
 *  sec
 * RETURNS
 *  MMI_TRUE   support
 *  MMI_FALSE  unsopport
 ******************************************************************/
void pls_db_util_get_security_info(U8 drv_letter, srv_plst_security *sec)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sec->phone_id = pls_db_get_sernaria_number(SRV_FMGR_PUBLIC_DRV);

    if (IS_CARD_EXIST || g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY)
    {
        sec->card_id = pls_db_get_sernaria_number(SRV_FMGR_CARD_DRV);
    }
    else
    {
        sec->card_id = 0;
    }
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_check_format_is_support
 * DESCRIPTION
 *  check the format if support or not
 * PARAMETERS
 *  ext       [IN]    UI_string_type
 * RETURNS
 *  MMI_TRUE   support
 *  MMI_FALSE  unsopport
 ******************************************************************/
static MMI_BOOL pls_db_util_check_format_is_support(UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total;
    U8 i;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    total = sizeof(srv_plst_support_format)/ sizeof(srv_plst_support_format_struct);

    for(i = 0; i < total; i++)
    {
        if (!mmi_ucs2icmp((const CHAR*)ext, (const CHAR*)srv_plst_support_format[i].ext_name))
        {
            ret = MMI_TRUE;
            break;
        }        
    }
    return ret;
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_check_format_is_support
 * DESCRIPTION
 *  check the file if in the phone or not
 * PARAMETERS
 *  path       [IN]    UI_string_type
 * RETURNS
 *  MMI_TRUE   YES
 *  MMI_FALSE   NO
 ******************************************************************/
MMI_BOOL pls_db_util_check_if_in_phone(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv[4];
    UI_character_type path_drv[2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    kal_wsprintf((U16*)&drv,"%c", SRV_FMGR_CARD_DRV);
    path_drv[0] = path[0];
    path_drv[1] = 0;

    if (!mmi_ucs2icmp((const CHAR*)drv, (const CHAR*)path_drv))
    {
        MMI_TRACE(TRACE_GROUP_4,MMI_PLS_PLS_CHECK_IF_IN_PHONE);   
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_get_if_is_video
 * DESCRIPTION
 *  check if video or not
 * PARAMETERS
 *  file_ext       [IN]    UI_string_type
 * RETURNS
 *  MMI_TRUE   YES
 *  MMI_FALSE  NO
 ******************************************************************/
MMI_BOOL pls_db_util_get_if_is_video(UI_string_type file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_group_type_enum   file_grp;
    filetypes_file_type_enum    file_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //bql: MAUI_02953497
    //change check if file is video logic,
    //need to sync with file manager filer
    //which will be nice to add new supported files without revise core code
    file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_extension_str((WCHAR*)file_ext);
    file_grp = srv_fmgr_types_find_group_by_type(file_type);

    if (file_grp == FMGR_GROUP_VIDEO 
#ifdef __MMI_VIDEO_STREAM__
        || file_grp == FMGR_GROUP_STREAM)
#else
        )
#endif
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

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
#ifdef MP4_DECODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __RM_DEC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __RM_DEC_SUPPORT__ */ 
/* under construction !*/
#ifdef MJPG_DECODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_VIDEO_STREAM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#endif
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_get_file_type
 * DESCRIPTION
 *  get file type
 * PARAMETERS
 *  ext       [IN]    UI_string_type
 * RETURNS
 *  file_type
 ******************************************************************/
U32 pls_db_util_get_file_type(UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    total = sizeof(srv_plst_support_format)/ sizeof(srv_plst_support_format_struct);

    for(i = 0; i < total; i++)
    {
        if (!mmi_ucs2icmp((const CHAR*)ext, (const CHAR*)srv_plst_support_format[i].ext_name))
        {            
            return srv_plst_support_format[i].file_type;
        }        
    }
    return 0;
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_check_space_is_enough
 * DESCRIPTION
 *  check  memory enough or not
 * PARAMETERS
 *  drv_letter       [IN]    drive letter
 *  req_size         [IN]    require need size
 *  fs_error         [IN/OUT] fs error code
 * RETURNS
 *  MMI_TRUE   enough
 *  MMI_FALSE  unenough
 ******************************************************************/
MMI_BOOL pls_db_util_check_space_is_enough(U8 drv_letter, S32 req_size, S32 *fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if(fs_error)
    {
        *fs_error = fs_ret;
    }

    if (fs_ret < 0)
    {
        return MMI_FALSE;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_DB_UTIL_CHECK_SPACE_IS_ENOUGH, disk_free_space, req_size, __LINE__);
        if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_check_disk_space_and_get_error
 * DESCRIPTION
 *  check  memory enough or not
 * PARAMETERS
 *  srv_plst_base    [IN]    database info
 *  drv_letter       [IN]    drive letter
 *  req_size         [IN]    require need size
 * RETURNS
 *  result
 ******************************************************************/
S32 pls_db_util_check_disk_space_and_get_error(srv_plst_base_info_struct* srv_plst_base, U8 drv_letter, S32 req_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PLST_OK;
    S32 fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if(!pls_db_util_check_space_is_enough(drv_letter, req_size, &fs_error))
    {
        if(fs_error < FS_NO_ERROR)
        {
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            ret = SRV_PLST_RET_ERR_FS_ERROR;
            srv_plst_base->ture_err_code = fs_error;
        }
        else if (FS_NO_ERROR == FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM))
        {
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            ret = SRV_PLST_RET_ERR_DISK_NOT_ENOUGH;
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            ret = SRV_PLST_RET_ERR_FS_ERROR;
            srv_plst_base->ture_err_code = FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM);
        }
        srv_plst_base->error_code = ret;
    }

    return ret;
}

/******************************************************************
 * FUNCTION
 *    pls_db_util_check_handler_valid
 * DESCRIPTION
 *   handler valid or not
 * PARAMETERS
 *  drv_letter       [IN]    drive letter
 *  base             [IN]    see srv_plst_base_info_struct
 *  sec              [IN]    see srv_plst_security
 * RETURNS
 *  ret error code
 ******************************************************************/
static MMI_BOOL pls_db_util_check_handler_valid(U32 handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for(i = 1; i <= g_srv_plst_control_ptr->number; i ++)
    {
        if(handler == g_srv_plst_control_ptr->service_reg[i] && handler)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/******************************************************************
 * FUNCTION
 *    pls_db_util_check_version_is_ok
 * DESCRIPTION
 *  version is OK or not
 * PARAMETERS
 *  drv_letter       [IN]    drive letter
 *  base             [IN]    see srv_plst_base_info_struct
 *  sec              [IN]    see srv_plst_security
 * RETURNS
 *  ret error code
 ******************************************************************/
static S32 pls_db_util_check_version_is_ok(U8 drv_letter,srv_plst_base_info_struct* base, srv_plst_security* sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifndef __MTK_TARGET__
    return SRV_PLST_OK;
#endif 
    
    if(mmi_ucs2cmp((const CHAR*)sec->ver, (const CHAR*)SRV_PLST_DB_VERSION_NUM))
    {
        ret =  SRV_PLST_VERSION_WRONG;
        MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
        return ret;
    }

    if(sec->ver_int !=  med_crc_calculate((kal_uint8* )sec->ver, mmi_ucs2strlen((const CHAR*)sec->ver) * ENCODING_LENGTH))
    {
        ret =  SRV_PLST_RET_ERR_DB_CRASH;
        MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
        return ret;
    }

    if (drv_letter == SRV_FMGR_PUBLIC_DRV)
    {  
        if(sec->phone_id != pls_db_get_sernaria_number(SRV_FMGR_PUBLIC_DRV))
        {
            ret = SRV_PLST_VERSION_WRONG;
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            return ret;
        }
        if(IS_CARD_EXIST)
        {
            if(sec->card_id != pls_db_get_sernaria_number(SRV_FMGR_CARD_DRV))
            {
                ret = SRV_PLST_VERSION_WRONG;
                MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
                return ret;
            }
        }
    }
    else if (drv_letter == SRV_FMGR_CARD_DRV)
    {
        if(sec->card_id != pls_db_get_sernaria_number(SRV_FMGR_CARD_DRV))
        {
            ret = SRV_PLST_VERSION_WRONG;
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            return ret;
        }
        if(sec->phone_id != pls_db_get_sernaria_number(SRV_FMGR_PUBLIC_DRV))
        {
            ret =  SRV_PLST_VERSION_WRONG;
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            return ret;
        }
    }
    else 
    {
        ret = SRV_PLST_RET_ERR_DB_CRASH;
        MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
        return ret;
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_get_filename_as_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path             [IN]        
 *  out_title           [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
void pls_db_util_get_filename_as_title(const UI_string_type in_path, UI_string_type out_title, U16 title_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    CHAR *filename_ptr = NULL;
    CHAR *ext = NULL;
    UI_character_type title_buff[(SRV_FMGR_PATH_MAX_LEN+1)];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_path == NULL)
    {
        *out_title = 0;
    }
    else
    {
        filename_ptr = mmi_ucs2rchr((const CHAR*)in_path, (WCHAR)(L'\\'));
        if (filename_ptr == NULL)
        {
            *out_title = 0;
        }
        else
        {
            //srv_fmgr_fileinfo_struct   file_info1;
            //srv_fmgr_fs_path_get_fileinfo((WCHAR*)in_path, &file_info1);

            mmi_ucs2ncpy((CHAR*)title_buff, (const CHAR*)(filename_ptr + 2), SRV_PLST_META_INFO_MAX_LEN);
            /* cut off extension name. */
            ext = mmi_ucs2rchr((const CHAR*)title_buff, (U16)L'.');
            if (ext != NULL)
            {
                *(ext + 1) = 0;
                *ext = 0;
            }
            len = mmi_ucs2strlen((const CHAR*)title_buff);
            if (len > (title_len - 1))
            {
                mmi_ucs2ncpy((CHAR*)out_title, (const CHAR*)title_buff, title_len - 1);
            }
            else
            {
                mmi_ucs2ncpy((CHAR*)out_title, (const CHAR*)title_buff, title_len - 1);
            }
        }
    }
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_get_meta_parser_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_letter       [IN]    drive letter
 *  base             [IN]    see srv_plst_base_info_struct
 *  sec              [IN]    see srv_plst_security
 * RETURNS
 *  
 ******************************************************************/
S32 pls_db_util_get_meta_parser_all(srv_plst_base_info_struct * base, UI_string_type path, srv_plst_media_details_struct * details, void* buffer, U32 buffer_size, meta_tag_img_info_struct *image_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_music_info_struct* music_info_p = NULL;
    meta_tag_img_info_struct* image_info_p_temp = NULL;
    meta_tag_audio_info_struct* audio_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    meta_parser_buffer = (PU8)kal_adm_alloc(base->create.mem_ptr, META_TAG_PARSE_MIN_SIZE);
    
    if (meta_parser_buffer == NULL)
    {
        return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {   
            details->artist[0] = 0;
            details->author[0] = 0;
            details->album[0] = 0;
            pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
            details->copyrights[0] = 0;
            details->genre[0] = 0;
            details->description[0] = 0;
            details->year = -1;
            details->track_num = -1;
            details->artwork_type = -1;          
            details->duration = 0;
            ret = SRV_PLST_RET_ERR_META_PAESER;
        }
        else
        {
            /* parse file. */
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)path);

            if (meta_return_value != 0)	/* fill meta data if meta parser pasre file failed.*/
            {
                details->artist[0] = 0;
                details->author[0] = 0;
                details->album[0] = 0;
                pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                details->copyrights[0] = 0;
                details->genre[0] = 0;
                details->description[0] = 0;
                details->year = -1;
                details->track_num = -1;
                details->artwork_type = -1;                
                details->duration = 0;
                ret = SRV_PLST_RET_ERR_META_PAESER;
                srv_fmgr_path_hide_extension((WCHAR*)((CHAR*)details->title));
            }
            else
            {
                ret = SRV_PLST_OK;
                meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);	/* get "music info" struct. */
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0 &&
                       (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->artist, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->artist[(music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->artist[0] = 0;
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size > 0 &&
                        music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size >> 1 <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->author,
                            (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data,
                            META_TAG_FRAME_MAX_LEN);
                        details->author[(music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->author[0] = 0;
                    }

                    if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)                    
                    {
                        mmi_ucs2ncpy((CHAR*)details->album, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->album[(music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->album[0] = 0;
                    }
                    if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->title, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->title[(music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1)] = 0;
                    }
                    else
                    {
                        pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->copyrights, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->copyrights[(music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->copyrights[0] = 0;
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->genre, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_GENRE].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->genre[(music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size >> 1)] = 0;                          
                    }
                    else
                    {
                        details->genre[0] = 0;
                    }

                    if (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->description, 
                              (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->description[(music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->description[0] = 0;
                    }
                    if (music_info_p->year <= 9999 && music_info_p->year >= 0)
                    {      
                        details->year = music_info_p->year;
                    }
                    else
                    {
                        details->year = -1;
                    }

                    if (music_info_p->track_number > 0 && music_info_p->track_number <= 9999)
                    {
                        details->track_num = music_info_p->track_number;
                    }
                    else
                    {
                        details->track_num = -1;
                    }
                    details->duration = music_info_p->duration;
                }
                else
                {
                    details->artist[0] = 0;
                    details->author[0] = 0;
                    details->album[0] = 0;
                    pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                    details->copyrights[0] = 0;
                    details->genre[0] = 0;
                    details->description[0] = 0;
                    details->year = -1;
                    details->track_num = -1;
                }
                srv_fmgr_path_hide_extension((WCHAR*)((CHAR*)details->title));

                /* get audio info */
                meta_return_value = meta_get_audio_info(meta_parser_hdlr, &audio_info_p);

                if(META_TAG_ERR_NONE == meta_return_value)
                {
                    details->channel_num = audio_info_p->channel_number;
                    details->bits_rate = audio_info_p->bits_rate;
                    details->sample_bits = audio_info_p->sample_bits;
                    details->sample_rate = audio_info_p->sample_rate;
                    details->duration = audio_info_p->duration;
                }
                /* get artwork type. get "artwork info" struct.*/
                meta_return_value = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p_temp);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    image_info_p->data_offset = image_info_p_temp->data_offset;
                    image_info_p->mime_type = image_info_p_temp->mime_type;
                    image_info_p->data_size = image_info_p_temp->data_size;
                    image_info_p->frame_location = image_info_p_temp->frame_location;
                    image_info_p->priority = image_info_p_temp->priority;
                    if (image_info_p_temp->data_size > 0)
                    {    
                        details->artwork_type = (S8)image_info_p_temp->mime_type;                        
                        if(buffer != NULL)
                        {
                            if (buffer_size < SRV_PLS_MIN_ARTWORK_SIZE)
                            {
                                buffer = NULL;
                                /* don't parser artwork*/
                            }
                            else
                            {
                                if (buffer_size < image_info_p_temp->data_size)
                                {
                                    meta_parser_release(meta_parser_hdlr);
                                    buffer = NULL;
                                }
                                else if( image_info_p_temp->data_size > 0)
                                {
                                    meta_return_value = meta_get_attach_cover_data(
                                                    meta_parser_hdlr, (kal_uint8*)buffer, buffer_size);
                                    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
                                    {
                                        buffer = NULL;
                                    }
                                }/* end of data_size */
                            }
                        }
                    }
                    else
                    {
                        buffer = NULL;
                        details->artwork_type = -1;
                    }
                }
                else
                {
                    buffer = NULL;
                    details->artwork_type = -1;
                } 
            }
            meta_parser_release(meta_parser_hdlr);
        }
    }
    
    {
        CHAR *filename_ptr = NULL;
 
        filename_ptr = mmi_ucs2rchr((const CHAR*)path, (U16)(L'\\'));
        if (filename_ptr == NULL)
        {
            details->filename[0] = 0;
        }
        else
        {
            //srv_fmgr_fileinfo_struct   file_info1;
            //srv_fmgr_fs_path_get_fileinfo((WCHAR*)path, &file_info1);
            mmi_ucs2ncpy((CHAR*)details->filename, (const CHAR*)(filename_ptr + 2), SRV_PLST_META_INFO_MAX_LEN);
        }       
    }
    srv_fmgr_path_hide_extension((WCHAR*)((CHAR*)details->filename));
    kal_adm_free(base->create.mem_ptr, meta_parser_buffer);
    meta_parser_buffer = NULL;
    return ret;

}

/******************************************************************
 * FUNCTION
 *    pls_db_util_get_meta_parser
 * DESCRIPTION
 *  version is OK or not
 * PARAMETERS
 *  drv_letter       [IN]    drive letter
 *  base             [IN]    see srv_plst_base_info_struct
 *  sec              [IN]    see srv_plst_security
 * RETURNS
 * 
 ******************************************************************/
S32 pls_db_util_get_meta_parser(srv_plst_base_info_struct *base, UI_string_type path, srv_plst_media_details_struct *details)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    WCHAR* file_p;
    meta_tag_music_info_struct* music_info_p = NULL;
    meta_tag_sync_lyc_info_struct* lrc_info_p = NULL;
    meta_tag_img_info_struct* image_info_p_temp = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    meta_parser_buffer = (PU8)kal_adm_alloc(base->create.mem_ptr, META_TAG_PARSE_MIN_SIZE);
    
    if (meta_parser_buffer == NULL)
    {
        return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {   
            details->artist[0] = 0;
            details->author[0] = 0;
            details->album[0] = 0;
            pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
            details->copyrights[0] = 0;
            details->genre[0] = 0;
            details->description[0] = 0;
            details->year = -1;
            details->track_num = -1;
            details->artwork_type = -1;
            details->duration = music_info_p->duration;
            ret = SRV_PLST_RET_ERR_META_PAESER;
        }
        else
        {
            /* parse file. */
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)path);

            if (meta_return_value != 0)	/* fill meta data if meta parser pasre file failed.*/
            {
                details->artist[0] = 0;
                details->author[0] = 0;
                details->album[0] = 0;
                    pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                details->copyrights[0] = 0;
                details->genre[0] = 0;
                details->description[0] = 0;
                details->year = -1;
                details->track_num = -1;
                details->artwork_type = -1;
                details->duration = music_info_p->duration;
                ret = SRV_PLST_RET_ERR_META_PAESER;
            }
            else
            {
                ret = SRV_PLST_OK;
                meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);	/* get "music info" struct. */
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0 &&
                       (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->artist, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->artist[(music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->artist[0] = 0;
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size > 0 &&
                        music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size >> 1 <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->author,
                            (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data,
                            META_TAG_FRAME_MAX_LEN);
                        details->author[(music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->author[0] = 0;
                    }

                    if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)                    
                    {
                        mmi_ucs2ncpy((CHAR*)details->album, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->album[(music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->album[0] = 0;
                    }
                    if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->title, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->title[(music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1)] = 0;
                    }
                    else
                    {
                        pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->copyrights, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->copyrights[(music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->copyrights[0] = 0;
                    }
        
                    if (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->genre, 
                               (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_GENRE].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->genre[(music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size >> 1)] = 0;                          
                    }
                    else
                    {
                        details->genre[0] = 0;
                    }

                    if (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size > 0 &&
                        (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details->description, 
                              (const CHAR*)music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data,
                               META_TAG_FRAME_MAX_LEN);
                        details->description[(music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size >> 1)] = 0;
                    }
                    else
                    {
                        details->description[0] = 0;
                    }
                    if (music_info_p->year <= 9999 && music_info_p->year >= 0)
                    {      
                        details->year = music_info_p->year;
                    }
                    else
                    {
                        details->year = -1;
                    }

                    if (music_info_p->track_number > 0 && music_info_p->track_number <= 9999)
                    {
                        details->track_num = music_info_p->track_number;
                    }
                    else
                    {
                        details->track_num = -1;
                    }
                    details->duration = music_info_p->duration;
                }
                else
                {
                    details->artist[0] = 0;
                    details->author[0] = 0;
                    details->album[0] = 0;
                    pls_db_util_get_filename_as_title(path, details->title, META_TAG_FRAME_MAX_LEN + 1);
                    details->copyrights[0] = 0;
                    details->genre[0] = 0;
                    details->description[0] = 0;
                    details->year = -1;
                    details->track_num = -1;
                    details->duration = 0;
                }
                
                /* get artwork type. get "artwork info" struct.*/
                meta_return_value = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p_temp);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (image_info_p_temp->data_size > 0)
                    {    
                        details->artwork_type = (S8)image_info_p_temp->mime_type;
                    }
                    else
                    {
                        details->artwork_type = -1;
                    }
                }
                else
                {
                    details->artwork_type = -1;
                }                

                /* get lyrics type.get "lyrics info" struct.  */
                meta_return_value = meta_get_sync_lyrics_info(meta_parser_hdlr, &lrc_info_p);

            }
            meta_parser_release(meta_parser_hdlr);
        }
    }
    file_p = srv_fmgr_path_get_filename_ptr((WCHAR*)path);
    mmi_ucs2ncpy((CHAR*)(details->filename), (const CHAR*)file_p, SRV_PLST_META_INFO_MAX_LEN + 1);

    kal_adm_free(base->create.mem_ptr, meta_parser_buffer);
    meta_parser_buffer = NULL;
    return ret;
}


S32 pls_db_util_resize_artwork_by_path(UI_string_type path, void* buffer, U32 buffer_size, void* resized_data, S32 *resized_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, resize_w, resize_h; 
    S32 ret = SRV_PLST_OK;
    gdi_handle src_layer;
    U16 gdi_img_type = GDI_IMAGE_TYPE_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_img_type = gdi_image_get_type_from_file((S8*)path);

    if(gdi_img_type != GDI_IMAGE_TYPE_JPG_FILE  &&
	   gdi_img_type != GDI_IMAGE_TYPE_BMP_FILE  &&
	   gdi_img_type != GDI_IMAGE_TYPE_GIF_FILE  &&
	   gdi_img_type != GDI_IMAGE_TYPE_WBMP_FILE &&
	   gdi_img_type != GDI_IMAGE_TYPE_PNG_FILE)
    {
        return SRV_PLST_RET_ERR_IMG_FORMAT_ERROR;
    }
    ret = gdi_image_get_dimension_file((S8*) path, &w, &h);
    if(ret != GDI_SUCCEED)
    {
        ret = SRV_PLST_RET_ERR_GDI_ERR;
    }  
    gdi_image_util_fit_bbox(SRV_PLST_ARTWORK_RESIZED_WIDTH,SRV_PLST_ARTWORK_RESIZED_HEIGHT,w, h, &x, & y, &resize_w, &resize_h);
    
    if(ret == SRV_PLST_OK)
    {
        gdi_layer_create_using_outside_memory(
            0,
            0,
            SRV_PLST_ARTWORK_RESIZED_WIDTH,
            SRV_PLST_ARTWORK_RESIZED_HEIGHT,
            &src_layer,
            resized_data,
            SRV_PLST_ARTWORK_RESIZED_HEIGHT * SRV_PLST_ARTWORK_RESIZED_HEIGHT* (GDI_MAINLCD_BIT_PER_PIXEL / 8));   
            gdi_layer_push_and_set_active(src_layer);

        ret = gdi_image_draw_resized_file(x, y, resize_w, resize_h, path);
        if (ret == GDI_SUCCEED)
        {
            ret = gdi_image_encode_layer_to_jpeg_in_memory(src_layer, buffer, SRV_PLS_MIN_ARTWORK_SIZE, resized_size);
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_RESIZE_ARTWORK_BY_PATH, ret, *resized_size);
            gdi_layer_free(src_layer);
            gdi_layer_pop_and_restore_active();
            memcpy((S8*)resized_data, (S8*)buffer, *resized_size);
            if (ret == GDI_SUCCEED)
            {
                ret = SRV_PLST_OK;
            }
            else
            {
                ret = SRV_PLST_RET_ERR_GDI_ERR;
            }
        }
        else
        {
            gdi_layer_free(src_layer);
            gdi_layer_pop_and_restore_active();
            ret = SRV_PLST_RET_ERR_GDI_ERR;
        }
    }
    return ret;    
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_resize_artwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]    U8
 *  buffer      [IN]
 *  buffer_size
 * RETURNS
 *  S32 error_code
 ******************************************************************/
S32 pls_db_util_resize_artwork(meta_tag_img_info_struct *image_info_p, void* buffer, U32 buffer_size, void* resized_data, S32 *resized_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, resize_w, resize_h; 
    S32 ret = SRV_PLST_OK;
    gdi_handle src_layer;
    U8 gdi_img_type = GDI_IMAGE_TYPE_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/                    

    /* Check if buffer is enough to decode this image */
    if((image_info_p->data_size == 0) || (image_info_p->data_size > buffer_size))
    {
        return SRV_PLST_RET_ERR_GDI_ERR;
    }

    switch(image_info_p->mime_type)
    {
        case META_TAG_IMG_PNG :    
            gdi_img_type = GDI_IMAGE_TYPE_PNG;
            break;
            
        case META_TAG_IMG_JPG:     
            gdi_img_type = GDI_IMAGE_TYPE_JPG; 
            break;
            
        case META_TAG_IMG_JPEG:   
            gdi_img_type = GDI_IMAGE_TYPE_JPG; 
            break;
            
        case META_TAG_IMG_GIF:  
            gdi_img_type = GDI_IMAGE_TYPE_GIF; 
            break;
            
        case META_TAG_IMG_BMP:  
            gdi_img_type = GDI_IMAGE_TYPE_BMP; 
            break;

        default:             
            break;
    }
    ret = gdi_image_get_dimension_mem(gdi_img_type, buffer, buffer_size, &w, &h);

    if(ret != GDI_SUCCEED)
    {
        ret = SRV_PLST_RET_ERR_GDI_ERR;
    }  
    
    if(w == 0 && h == 0)
    {
        ret = SRV_PLST_RET_ERR_GDI_ERR;
    }

    if(ret == SRV_PLST_OK)
    {
        gdi_layer_create_using_outside_memory(
            0,
            0,
            SRV_PLST_ARTWORK_RESIZED_WIDTH,
            SRV_PLST_ARTWORK_RESIZED_HEIGHT,
            &src_layer,
            resized_data,
            SRV_PLST_ARTWORK_RESIZED_HEIGHT * SRV_PLST_ARTWORK_RESIZED_HEIGHT* (GDI_MAINLCD_BIT_PER_PIXEL / 8));   
        gdi_layer_push_and_set_active(src_layer);
        gdi_push_and_set_alpha_blending_source_layer(src_layer);
        if (w < SRV_PLST_ARTWORK_RESIZED_WIDTH &&
            h < SRV_PLST_ARTWORK_RESIZED_HEIGHT &&
            w > 0 && h > 0)
        {
            /* cache image in layer with original size (RGB565) */
            gdi_layer_resize(w, h);
            ret = gdi_image_draw_mem(0, 0, buffer, gdi_img_type,image_info_p->data_size);
            if (ret == GDI_SUCCEED)
            {
                /* output layer to buffer (JPEG type) */
                ret = gdi_image_encode_layer_to_jpeg_in_memory(src_layer, buffer, SRV_PLS_MIN_ARTWORK_SIZE, resized_size);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_ENCODE_LAYER_TO_JPEG_IN_MEMORY, ret, __LINE__);
            }
            else
            {
                MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
                gdi_layer_free(src_layer);
                gdi_pop_and_restore_alpha_blending_source_layer();
                gdi_layer_pop_and_restore_active();
                ret = SRV_PLST_RET_ERR_GDI_ERR;
                return ret;
            }
            gdi_layer_resize(SRV_PLST_ARTWORK_RESIZED_WIDTH, SRV_PLST_ARTWORK_RESIZED_HEIGHT);
			gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_image_util_fit_bbox(SRV_PLST_ARTWORK_RESIZED_WIDTH,SRV_PLST_ARTWORK_RESIZED_HEIGHT,w, h, &x, & y, &resize_w, &resize_h);
            /* cache image in layer again with resized size (RGB565) */
            ret = gdi_image_draw_resized_mem(x, y, resize_w,resize_h, buffer, GDI_IMAGE_TYPE_JPG, *resized_size);
            if (ret < GDI_SUCCEED)
            {
                /* error handling for JPG cannot support resized draw */
                MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
                gdi_layer_clear(GDI_COLOR_BLACK);
                ret = gdi_image_draw_mem(x, y, buffer,GDI_IMAGE_TYPE_JPG,*resized_size);
            }
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_DRAW_RESIZED_MEM, ret,image_info_p->mime_type, image_info_p->data_size,resize_w,resize_h);
        }
        else
        {
            gdi_image_util_fit_bbox(SRV_PLST_ARTWORK_RESIZED_WIDTH,SRV_PLST_ARTWORK_RESIZED_HEIGHT,w, h, &x, & y, &resize_w, &resize_h);
            ret = gdi_image_draw_resized_mem(x, y, resize_w,resize_h, buffer, gdi_img_type,image_info_p->data_size);
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_DRAW_RESIZED_MEM, ret,image_info_p->mime_type, image_info_p->data_size,resize_w,resize_h);
        }
        if (ret == GDI_SUCCEED)
        {
            ret = gdi_image_encode_layer_to_jpeg_in_memory_with_quality(src_layer, buffer, SRV_PLS_MIN_ARTWORK_SIZE, resized_size, GDI_JPEG_ENCODE_QUALITY_GOOD);
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_ENCODE_LAYER_TO_JPEG, ret, *resized_size);
            gdi_layer_free(src_layer);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_and_restore_active();
            memcpy((S8*)resized_data, (S8*)buffer, *resized_size);
            if (ret == GDI_SUCCEED)
            {
                ret = SRV_PLST_OK;
            }
            else
            {
                ret = SRV_PLST_RET_ERR_GDI_ERR;
            }
        }
        else
        {
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            gdi_layer_free(src_layer);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_and_restore_active();
            ret = SRV_PLST_RET_ERR_GDI_ERR;
        }
    }
    return ret; 
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_get_file_artwork
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]    U8
 *  buffer      [IN]
 *  buffer_size
 * RETURNS
 *  S32 error_code
 ******************************************************************/
S32 pls_db_util_get_file_artwork(UI_string_type path, void* buffer, U32 buffer_size, void* resized_data, S32 *resized_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, resize_w, resize_h; 
    S32 ret = SRV_PLST_OK;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_img_info_struct* image_info_p = NULL;
    gdi_handle src_layer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer_size < SRV_PLS_MIN_ARTWORK_SIZE)
    {
        return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
    }
    
    meta_parser_buffer = buffer;
    
    if (meta_parser_buffer == NULL)
    {
      ret = SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);
    
        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {
            meta_parser_release(meta_parser_hdlr);
            ret = SRV_PLST_RET_ERR_META_PAESER;
        }
        else
        {
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)path);
    
            if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
            {
                meta_parser_release(meta_parser_hdlr);
                ret = SRV_PLST_RET_ERR_META_PAESER;
            }
            else
            {
                meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);
        
                if (buffer_size < image_info_p->data_size)
                {
                    meta_parser_release(meta_parser_hdlr);
                    ret = SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
                }
                else if( image_info_p->data_size > 0)
                {
                    U8 gdi_img_type = GDI_IMAGE_TYPE_INVALID;
                    meta_return_value = meta_get_attach_cover_data(
                                    meta_parser_hdlr, (kal_uint8*)buffer, buffer_size);
                    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
                    {
                        ret = SRV_PLST_RET_ERR_META_PAESER;
                    }
                    
                    switch(image_info_p->mime_type)
                    {
                        case META_TAG_IMG_PNG :    
                            gdi_img_type = GDI_IMAGE_TYPE_PNG; break;
                        case META_TAG_IMG_JPG:     
                            gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
                        case META_TAG_IMG_JPEG:   
                            gdi_img_type = GDI_IMAGE_TYPE_JPG; break;
                        case META_TAG_IMG_GIF:  
                            gdi_img_type = GDI_IMAGE_TYPE_GIF; break;
                        case META_TAG_IMG_BMP:  
                            gdi_img_type = GDI_IMAGE_TYPE_BMP; break;

                        default:             
                            break;
                    }
                    ret = gdi_image_get_dimension_mem(gdi_img_type, buffer, buffer_size, &w, &h);

                    if(ret != GDI_SUCCEED)
                    {
                        ret = SRV_PLST_RET_ERR_GDI_ERR;
                    }  
                    gdi_image_util_fit_bbox(SRV_PLST_ARTWORK_RESIZED_WIDTH,SRV_PLST_ARTWORK_RESIZED_HEIGHT,w, h, &x, & y, &resize_w, &resize_h);
                    
                    if(ret == SRV_PLST_OK)
                    {
                        gdi_layer_create_using_outside_memory(
                            0,
                            0,
                            SRV_PLST_ARTWORK_RESIZED_WIDTH,
                            SRV_PLST_ARTWORK_RESIZED_HEIGHT,
                            &src_layer,
                            resized_data,
                            SRV_PLST_ARTWORK_RESIZED_HEIGHT * SRV_PLST_ARTWORK_RESIZED_HEIGHT* (GDI_MAINLCD_BIT_PER_PIXEL / 8));   
                            gdi_layer_push_and_set_active(src_layer);
         
                        ret = gdi_image_draw_resized_mem(x, y, resize_w,resize_h, buffer, gdi_img_type,image_info_p->data_size);
                        MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_DRAW_RESIZED_MEM, ret,image_info_p->mime_type, image_info_p->data_size,resize_w,resize_h);
                        meta_parser_release(meta_parser_hdlr);
                        if (ret == GDI_SUCCEED)
                        {
                            ret = gdi_image_encode_layer_to_jpeg_in_memory(src_layer, buffer, SRV_PLS_MIN_ARTWORK_SIZE, resized_size);
                            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_UTIL_ENCODE_LAYER_TO_JPEG, ret, *resized_size);
                            gdi_layer_free(src_layer);
                            gdi_layer_pop_and_restore_active();
                            memcpy((S8*)resized_data, (S8*)buffer, *resized_size);
                            if (ret == GDI_SUCCEED)
                            {
                                ret = SRV_PLST_OK;
                            }
                            else
                            {
                                ret = SRV_PLST_RET_ERR_GDI_ERR;
                            }
                        }
                        else
                        {
                            gdi_layer_free(src_layer);
                            gdi_layer_pop_and_restore_active();
                            ret = SRV_PLST_RET_ERR_GDI_ERR;
                        }
                    } /* end of resize pic */   
                    else
                    {
                        meta_parser_release(meta_parser_hdlr);
                    }
                }/* end of data_size */
                else
                {
                    meta_parser_release(meta_parser_hdlr);
                }
            }          
        }/*end if meta_parser_ret  */ 
        meta_parser_buffer = NULL;
    }/* end of meta_parser_buffer */
    return ret; 
}


MMI_BOOL pls_db_util_find_artwork_path(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE  fs_hdr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find JPG */
    fs_hdr = FS_GetAttributes(path);
    if(fs_hdr < FS_NO_ERROR) /* not exist */
    {
        CHAR *ext_ptr;
        ext_ptr = mmi_ucs2rchr((const CHAR*)path, (U16)L'.');
        if (ext_ptr != NULL)
        {
            ext_ptr += 2;
        }
        else
        {
            ext_ptr = NULL;
        }
        return MMI_FALSE;
    }
    else 
    {
        S32 w, h;
        GDI_RESULT ret;

        fs_hdr = DRM_open_file((PU16)path, FS_READ_ONLY,DRM_PERMISSION_DISPLAY);
        if (fs_hdr < FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
    #ifdef __DRM_SUPPORT__
        if (DRM_get_object_method(fs_hdr, NULL) != DRM_METHOD_NONE)
        {
            DRM_close_file(fs_hdr);
            return MMI_FALSE;
        }
        DRM_close_file(fs_hdr);
    #endif
        ret = gdi_image_get_dimension_file((S8*)path, &w, &h);
        if (ret < 0)
        {
            return MMI_FALSE;
        }

        return MMI_TRUE;
    }     
}

/******************************************************************
 * FUNCTION
 *    pls_db_util_get_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_cache        [IN]   
 *  index             [IN]
 *  id
 * RETURNS
 *  S32 error_code
 ******************************************************************/
S32 pls_db_util_get_id(srv_plst_list_context_struct *list_cache, S32 index, U32* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PLST_OK;
    U16 i;
    MMI_BOOL find = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_4,MMI_PLS_PLS_UTIL_GET_ID, index,list_cache->cache_num);   
    if(list_cache->cache_num)
    {
        for(i = 0; i < SRV_PLST_VIEW_LIST_CACHE; i ++)
        {
            if(list_cache->cache[i].idx_in_list == index &&list_cache->cache[i].id )
            {
                *id = list_cache->cache[i].id;
                find = MMI_TRUE;
                break;
            }
        }
    }
    else 
    {
        *id = 0;
        ret = SRV_PLST_RET_ERR_UNKOWN_ERR;
    }
    if(!find)
    {
        *id = 0;
        ret = SRV_PLST_RET_ERR_UNKOWN_ERR;
    }   
    return ret;
}

 /*****************************************************************************
 * FUNCTION
 *  pls_send_msg
 * DESCRIPTION
 *  player list service send msg function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
void pls_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(src);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->src_mod_id = src;
    ilm_ptr->dest_mod_id = dst;
    ilm_ptr->sap_id = MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type)msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;
    
    msg_send_ext_queue(ilm_ptr);
}

/*****************************************************************************
* FUNCTION
*  pls_send_db_open_req_msg
* DESCRIPTION
*  send MSG_ID_PLS_LIBRARY_OPEN_REQ message
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void pls_send_db_open_req_msg(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info, U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_library_open_req_struct *local_open_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_open_ptr = (pls_library_open_req_struct*) construct_local_para(sizeof(pls_library_open_req_struct), TD_CTRL);
       
    local_open_ptr->db_handle = (void*)db_info;
    local_open_ptr->drv_letter = drive;
    if(base->is_open_cancel)
    {
        free_local_para((local_para_struct*)local_open_ptr);
    }
    else
    {
        pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIBRARY_OPEN_REQ, local_open_ptr);    
    }

}

/*****************************************************************************
* FUNCTION
*  pls_send_db_open_rsp_msg
* DESCRIPTION
*  send MSG_ID_PLS_LIBRARY_OPEN_RSP message
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void pls_send_db_open_rsp_msg(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_rsp_struct*  rsp_param_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_param_ptr = (pls_db_start_rsp_struct*) construct_local_para(sizeof(pls_db_start_rsp_struct), TD_CTRL);
    rsp_param_ptr->result = ret;
    rsp_param_ptr->callback = base->callback;
    rsp_param_ptr->db_handle = db_info;

    if(base->is_open_cancel)
    {
        free_local_para((local_para_struct*)rsp_param_ptr);
    }
    else
    {
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_OPEN_RSP,rsp_param_ptr);
    }
}

/*****************************************************************************
* FUNCTION
*  pls_send_create_table_req_msg
* DESCRIPTION
*  send MSG_ID_PLS_CREATE_TABLE_REQ message
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
static void pls_send_create_table_req_msg(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info, U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_create_table_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_create_table_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_create_table_ptr->drv_letter = drive;
    local_create_table_ptr->db_handle = db_info;         
    if(base->is_open_cancel)
    {
        free_local_para((local_para_struct*)local_create_table_ptr);
    }
    else
    {
        pls_send_msg(MOD_PLS, MOD_PLS,MSG_ID_PLS_CREATE_TABLE_REQ,local_create_table_ptr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_init
 * DESCRIPTION
 *   play list service db msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_init(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base_info;
    srv_plst_db_context_struct *db_info;
    S32 ret ;
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_start_req_struct*)ilm_ptr->local_para_ptr;
    handle = local_param_ptr->db_handle->srv_hdr;
    base_info = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);
    db_info = local_param_ptr->db_handle;
    ret = pls_sql_init_instance(db_info, base_info->create.db_mem_size);
    base_info->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_INIT);
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_deinit
 * DESCRIPTION
 *   play list service db  msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_deinit(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base_info;
    srv_plst_db_context_struct *db_info;
    S32 ret = SRV_PLST_OK; 
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_start_req_struct*)ilm_ptr->local_para_ptr;

    handle = local_param_ptr->db_handle->srv_hdr;
    base_info = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);
    db_info = local_param_ptr->db_handle;

    // No need to check here. Always deinit
    //if (db_info->db_opened)
    //{
        ret = pls_sql_deinit_instance(db_info);             
    //}
    //else
    //{
    //    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
    //    MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
    //}
    base_info->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_DEINIT);
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_create_table
 * DESCRIPTION
 *  play list service database create msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_create_table(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db_info;
    S32 ret = SRV_PLST_OK;
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*)ilm_ptr->local_para_ptr;
    handle = local_param_ptr->db_handle->srv_hdr;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);
    db_info = local_param_ptr->db_handle;

    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_CREATE_TBL, base->is_open_cancel,local_param_ptr->drv_letter, g_srv_plst_control_ptr->card_state);   
    if(base->is_open_cancel == MMI_TRUE)
    {
        base->error_code = SRV_PLST_OK;
        return ;
    }
    pls_sql_enter_instance(db_info);
    pls_sql_begin_transaction(db_info);
    ret = pls_sql_set_db_parama(db_info);
    ret = pls_sql_create_table(local_param_ptr->drv_letter, db_info);
    pls_sql_exit_instance(db_info);
    if (ret == SRV_PLST_OK)
    {
        pls_sql_enter_instance(db_info);
        ret = pls_sql_commit_transaction(db_info);
        pls_sql_exit_instance(db_info);

        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            base->error_code = SRV_PLST_RET_ERR_SQLITE_ERR;
            db_info->err_code = ret;
            pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_SQLITE_ERR);
            return ; 
        }

    #if defined(__PLST_DUAL_DB_SUPPORT__)
        if (IS_CARD_EXIST && local_param_ptr->drv_letter == SRV_FMGR_PUBLIC_DRV)
        {
            pls_sql_enter_instance(db_info);
            pls_sql_close_db(db_info);
            pls_sql_exit_instance(db_info);
            db_info->is_card_sync = MMI_TRUE;
            db_info->is_phone_sync = MMI_FALSE;

            pls_send_db_open_req_msg(base, db_info, SRV_FMGR_CARD_DRV);
            kal_sleep_task(PLS_TASK_SLEEP_TIME);
        }
        else if (IS_CARD_EXIST && local_param_ptr->drv_letter == SRV_FMGR_CARD_DRV)
        {
            pls_sql_enter_instance(db_info);
            pls_sql_close_db(db_info);
            pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
            ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
            if(ret == SRV_PLST_OK)
            {
                pls_sql_begin_transaction(db_info);
                ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_PUBLIC_DRV, MMI_FALSE);
                pls_sql_commit_transaction(db_info);
            }
            pls_sql_exit_instance(db_info);

            base->error_code = ret;
            pls_send_db_open_rsp_msg(base, db_info, ret);

            return ; 
        }
    #endif /* __PLST_DUAL_DB_SUPPORT__ */
        else
        {
            base->error_code = SRV_PLST_OK;
            pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_OK);

            return ;         
        }
    }
    else
    {
        pls_sql_enter_instance(db_info);
        pls_sql_rollback_transaction(db_info);
        pls_sql_close_db(db_info);
        pls_sql_exit_instance(db_info);

        base->error_code = ret;
        pls_send_db_open_rsp_msg(base, db_info, ret);
        
        return ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_read_version_renew_db
 * DESCRIPTION
 *  Delete database file and create a new database if encounter error in pls_db_read_version()
 * PARAMETERS
 *  base        [IN]    base info
 *  db_info     [IN]    database info
 *  file_path   [IN]    file path for crash db to be deleted
 *  drive       [IN]    driver to create new db
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_read_version_renew_db(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info, U16* file_path, U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_hdr_temp;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pls_sql_enter_instance(db_info);
    pls_sql_close_db(db_info);
    pls_sql_exit_instance(db_info);

    /* Delete corrupt db file */
    fs_hdr_temp = FS_Delete(file_path);
    
    if(fs_hdr_temp < FS_NO_ERROR)
    {
        base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
        base->ture_err_code = fs_hdr_temp;
        pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_FS_ERROR);
        return ;   
    }
    
    ret = pls_db_util_check_disk_space_and_get_error(base, drive, SRV_PLST_MIN_DB_SPACE);
    if(ret != SRV_PLST_OK)
    {
        pls_send_db_open_rsp_msg(base, db_info, ret);
        return ;
    }
    pls_sql_enter_instance(db_info);
    ret = pls_sql_open_db(file_path, db_info);
    pls_sql_exit_instance(db_info);
    if (ret != SRV_PLST_OK)
    {
        base->error_code = SRV_PLST_RET_ERR_SQLITE_ERR; 
        pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_SQLITE_ERR);
        return ;
    }
    else
    {    
        db_info->db_opened = MMI_TRUE;
        pls_send_create_table_req_msg(base, db_info, drive);
        return ;
    }
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_read_version
 * DESCRIPTION
 *  play list service database read version msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_read_version(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_read_ver_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db_info;    
    S32 ret = SRV_PLST_OK;
    U32 handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_read_ver_req_struct*)ilm_ptr->local_para_ptr;
    db_info = local_param_ptr->db_handle;
    handle = local_param_ptr->db_handle->srv_hdr;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);

    if(base->is_open_cancel == MMI_TRUE)
    {
        base->error_code = SRV_PLST_OK;
        return ;
    }
    if ((local_param_ptr->drv_letter == SRV_FMGR_PUBLIC_DRV) ||
        (local_param_ptr->drv_letter == SRV_FMGR_CARD_DRV && g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY))
    {
        pls_sql_enter_instance(db_info);
        ret = pls_sql_read_version(local_param_ptr->drv_letter, db_info, (srv_plst_security*)&local_param_ptr->sec_ver);
        pls_sql_exit_instance(db_info);
        if( ret == SRV_PLST_OK)
        {
            ret = pls_db_util_check_version_is_ok(local_param_ptr->drv_letter, base, (srv_plst_security*)&local_param_ptr->sec_ver);
            if( ret != SRV_PLST_OK)
            {
                /* If dual DB support, try to fix card error */
            #if defined(__PLST_DUAL_DB_SUPPORT__)
                if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
                {                    
                    if(ret == SRV_PLST_VERSION_WRONG)
                    {
                        S32 ret_t;
                        pls_sql_enter_instance(db_info);
                        pls_sql_begin_transaction(db_info);
                        ret_t = pls_sql_media_for_version_wrong(db_info, local_param_ptr->drv_letter, MMI_TRUE);                
                        db_info->is_card_sync = MMI_TRUE;
                        db_info->is_phone_sync = MMI_FALSE;
                        if(ret_t == SRV_PLST_OK)
                        {
                           ret_t = pls_sql_commit_transaction(db_info);
                           if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                           {
                               ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                               db_info->err_code = ret_t;
                           }
                           else 
                           {
                                ret = SRV_PLST_OK;
                           }
                        }
                        else
                        {
                           ret = ret_t;
                           pls_sql_rollback_transaction(db_info);
                        }   
                        pls_sql_exit_instance(db_info);

                        if(IS_CARD_EXIST && ret == SRV_PLST_OK)
                        {
                            pls_sql_enter_instance(db_info);
                            pls_sql_close_db(db_info);
                            pls_sql_exit_instance(db_info);

                            pls_send_db_open_req_msg(base, db_info, SRV_FMGR_CARD_DRV);
                            kal_sleep_task(PLS_TASK_SLEEP_TIME);
                            return ;
                        }
                        else
                        {
                            db_info->is_card_sync = MMI_FALSE;
                            base->error_code = ret;
                            pls_send_db_open_rsp_msg(base, db_info, ret);

                            return ;  
                        }
                    }
                    else if(ret == SRV_PLST_RET_ERR_DB_CRASH || ret == SRV_PLST_RET_ERR_DB_CONRRUPT)
                    {
                        pls_db_read_version_renew_db(base, db_info, (U16*)db_info->db_phone_path, local_param_ptr->drv_letter);
                    }
                    else
                    {
                        if(IS_CARD_EXIST && ret == SRV_PLST_OK)
                        {
                            pls_sql_enter_instance(db_info);
                            pls_sql_close_db(db_info);
                            pls_sql_exit_instance(db_info);

                            pls_send_db_open_req_msg(base, db_info, SRV_FMGR_CARD_DRV);
                            kal_sleep_task(PLS_TASK_SLEEP_TIME);
                            return ;
                        }
                        else
                        {
                            base->error_code = ret;
                            pls_send_db_open_rsp_msg(base, db_info, ret);
                            return ;  
                        }
                    }
                }

                base->error_code = ret;
                pls_send_db_open_rsp_msg(base, db_info, ret);
                return;
            #else /* __PLST_DUAL_DB_SUPPORT__ */
                /* If only signle DB, just delete the file and recreate a new database if version wrong */
                if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
                { 
                    pls_db_read_version_renew_db(base, db_info, (U16*)db_info->db_phone_path, local_param_ptr->drv_letter);
                }
                else
                {
                    base->error_code = SRV_PLST_RET_ERR_DB_CONRRUPT;
                    pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_DB_CONRRUPT);
                }
                return;
            #endif /* __PLST_DUAL_DB_SUPPORT__ */
            }

        #if defined(__PLST_DUAL_DB_SUPPORT__)
            if(IS_CARD_EXIST)
            {
                pls_sql_enter_instance(db_info);
                pls_sql_close_db(db_info);
                pls_sql_exit_instance(db_info);

                pls_send_db_open_req_msg(base, db_info, SRV_FMGR_CARD_DRV);
                kal_sleep_task(PLS_TASK_SLEEP_TIME);
                return ;
            }
            else
        #endif /* __PLST_DUAL_DB_SUPPORT__ */
            {
                base->error_code = SRV_PLST_OK;
                pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_OK);
                return ; 
            }
        }
        else
        {
            if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
            { 
                pls_db_read_version_renew_db(base, db_info, (U16*)db_info->db_phone_path, local_param_ptr->drv_letter);
            }
            else
            {
                base->error_code = SRV_PLST_RET_ERR_DB_CONRRUPT;
                pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_DB_CONRRUPT);
            }
            return ;
        }
    }
#if defined(__PLST_DUAL_DB_SUPPORT__)
    else if(IS_CARD_EXIST && local_param_ptr->drv_letter == SRV_FMGR_CARD_DRV)
    {
        pls_sql_enter_instance(db_info);
        ret = pls_sql_read_version(local_param_ptr->drv_letter, db_info, (srv_plst_security*)&local_param_ptr->sec_ver);
        pls_sql_exit_instance(db_info);
        if( ret == SRV_PLST_OK)
        {
            ret = pls_db_util_check_version_is_ok(local_param_ptr->drv_letter,base, (srv_plst_security*)&local_param_ptr->sec_ver); 
            if(ret != SRV_PLST_OK)
            {
                if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
                {                    
                    if(ret == SRV_PLST_VERSION_WRONG)
                    {
                        S32 ret_t;
                        pls_sql_enter_instance(db_info);
                        pls_sql_begin_transaction(db_info);
                        ret_t = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_CARD_DRV, MMI_TRUE);
                        db_info->is_phone_sync = MMI_TRUE;
                        db_info->is_card_sync = MMI_FALSE;
                        if(ret_t == SRV_PLST_OK)
                        {
                           ret_t = pls_sql_commit_transaction(db_info);
                           if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                           {
                               ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                               db_info->err_code = ret_t;
                           }
                           else 
                           {
                                ret = SRV_PLST_OK;
                           }
                        }
                        else
                        {
                           ret = ret_t;
                           pls_sql_rollback_transaction(db_info);
                        }   

                        pls_sql_close_db(db_info);
                        pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
                        ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);

                        if(ret == SRV_PLST_OK)
                        {
                            pls_sql_begin_transaction(db_info);
                            ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_PUBLIC_DRV, MMI_FALSE);
                            pls_sql_commit_transaction(db_info);
                        }
                        db_info->is_phone_sync = MMI_FALSE;
                        pls_sql_exit_instance(db_info);

                        base->error_code = ret;
                        pls_send_db_open_rsp_msg(base, db_info, ret);
                        return ;  
                        
                    }
                    else if(ret == SRV_PLST_RET_ERR_DB_CRASH || ret == SRV_PLST_RET_ERR_DB_CONRRUPT)
                    {
                        pls_db_read_version_renew_db(base, db_info, (U16*) db_info->db_card_path, SRV_FMGR_CARD_DRV);
                    }
                    else
                    {
                        base->error_code = ret;
                        pls_send_db_open_rsp_msg(base, db_info, ret);
                        return ;  
                    }
                }

                base->error_code = ret;
                pls_send_db_open_rsp_msg(base, db_info, ret);
                return ;                
            }
            else
            {
                pls_sql_enter_instance(db_info);
                pls_sql_close_db(db_info);
                pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
                ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
                if(db_info->is_card_sync)
                {
                    ret = pls_sql_media_for_version_wrong(db_info,SRV_FMGR_CARD_DRV, MMI_FALSE);
                    db_info->is_card_sync = MMI_FALSE;
                }
                pls_sql_exit_instance(db_info);
                
                base->error_code = ret;
                pls_send_db_open_rsp_msg(base, db_info, ret);
                return ; 
            }
        }
        else
        {
            if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
            {                
                pls_db_read_version_renew_db(base, db_info, (U16*) db_info->db_card_path, SRV_FMGR_CARD_DRV);
            }
            else
            {
                base->error_code = SRV_PLST_RET_ERR_DB_CONRRUPT;
                pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_DB_CONRRUPT);
            }
            return ;              
        }
    }
#endif /*__PLST_DUAL_DB_SUPPORT__*/
    else
    {
        base->error_code = SRV_PLST_RET_ERR_UNKOWN_ERR;
        pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_UNKOWN_ERR);
        return ;   
    }
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_close_lib
 * DESCRIPTION
 *  play list service db start msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_close_lib(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_param_ptr;    
    srv_plst_db_context_struct *db_info;
    srv_plst_base_info_struct *base_info;
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*)ilm_ptr->local_para_ptr;
    handle = local_param_ptr->db_handle->srv_hdr;
    base_info = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);
    db_info = local_param_ptr->db_handle;

    pls_sql_enter_instance(db_info);    
    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_CLOSE_LIB,db_info->instance_inited, db_info->in_transaction, db_info->db_opened);   
    pls_sql_close_db(db_info);
    pls_sql_exit_instance(db_info);
    base_info->error_code = SRV_PLST_OK;
     PLS_SET_EVENT(PLS_DB_EVT_CLOSE);
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_stop_open_lib
 * DESCRIPTION
 *  play list service db msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_stop_open_lib(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*)ilm_ptr->local_para_ptr;
    handle = local_param_ptr->db_handle->srv_hdr;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);

    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_STOP_OPEN_LIB,local_param_ptr->db_handle->instance_inited, local_param_ptr->db_handle->in_transaction, local_param_ptr->db_handle->db_opened);   
    base->error_code = SRV_PLST_OK;

    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);

    return ;
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_open_lib_open_new
 * DESCRIPTION
 *  play list open lib, open a new db case, calling by pls_db_open_lib() only
 * PARAMETERS
 *  base          [IN]  : base
 *  db_info       [IN]  : db info
 *  drv_letter    [IN]  : drive
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_open_lib_open_new(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info, U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* file_path;
    FS_HANDLE fs_hdr;
    S32 ret = SRV_PLST_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if((drv_letter == SRV_FMGR_PUBLIC_DRV) ||
       (drv_letter == SRV_FMGR_CARD_DRV && g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY))
    {
        file_path = (U16*)&db_info->db_phone_path;
    }
    else if (drv_letter == SRV_FMGR_CARD_DRV && IS_CARD_EXIST)
    {
        file_path = (U16*)&db_info->db_card_path;
    }
    else
    {
        return;
    }
    
    fs_hdr = FS_Open(file_path, FS_READ_ONLY);
    
    if (fs_hdr < FS_NO_ERROR)
    {
        ret = pls_db_util_check_disk_space_and_get_error(base, drv_letter, SRV_PLST_MIN_DB_SPACE);
        if(ret != SRV_PLST_OK)
        {
            pls_send_db_open_rsp_msg(base, db_info, ret);
            return ;
        }
        pls_sql_enter_instance(db_info);
        ret = pls_sql_open_db(file_path,db_info);
        pls_sql_exit_instance(db_info);
        if (ret != SRV_PLST_OK)
        {
            base->error_code = SRV_PLST_RET_ERR_SQLITE_ERR;
            pls_send_db_open_rsp_msg(base, db_info, SRV_PLST_RET_ERR_SQLITE_ERR);
            return ;
        }
        else
        {    
            db_info->db_opened = MMI_TRUE;
            pls_send_create_table_req_msg(base, db_info, drv_letter);
            
            // TODO:  use in old code, check if still necessary 
            //kal_sleep_task(PLS_TASK_SLEEP_TIME);
            return ;
        }
    }
    else
    {         
        pls_db_read_ver_req_struct *local_read_ptr;
        local_read_ptr = (pls_db_read_ver_req_struct*) construct_local_para(sizeof(pls_db_read_ver_req_struct), TD_CTRL);
    
        FS_Close(fs_hdr);
        pls_sql_enter_instance(db_info);
        ret = pls_sql_open_db(file_path, db_info);
        pls_sql_exit_instance(db_info);
        db_info->db_opened = MMI_TRUE;
        local_read_ptr->db_handle = db_info;
        local_read_ptr->drv_letter = drv_letter;
        if(base->is_open_cancel)
        {
            free_local_para((local_para_struct*)local_read_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_READ_VERSION_REQ,local_read_ptr);
        }
        return ;       
    }

}

/*****************************************************************************
 * FUNCTION
 *  pls_db_open_lib
 * DESCRIPTION
 *  play list service db msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_open_lib(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_library_open_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db_info;
    S32 ret = SRV_PLST_OK;
    FS_HANDLE fs_hdr;
    U32 handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_library_open_req_struct*)ilm_ptr->local_para_ptr;
    db_info = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    handle = db_info->srv_hdr;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handle)->base_info);
    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_OPEN_LIB,db_info->open_flag,local_param_ptr->drv_letter, base->error_code);   
    if(base->is_open_cancel == MMI_TRUE)
    {
        base->error_code = SRV_PLST_OK;
        return ;
    }

    /* For reopen case, no need to check version */
    if(db_info->open_flag == SRV_PLST_OPEN_REOPEN)
    {
        pls_sql_enter_instance(db_info);
    #if defined(__PLST_DUAL_DB_SUPPORT__)
        if (local_param_ptr->drv_letter == SRV_FMGR_PUBLIC_DRV)
        {
            ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
            if(ret == SRV_PLST_OK)
            {            
                if(IS_CARD_EXIST)
                {
                    ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
                }
                if(ret != SRV_PLST_OK)
                {
                    pls_sql_close_db(db_info);
                }
            }
        }
    #else /* __PLST_DUAL_DB_SUPPORT__ */
        ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
    #endif /* __PLST_DUAL_DB_SUPPORT__ */
        pls_sql_exit_instance(db_info);
        db_info->is_phone_sync = MMI_TRUE;
        db_info->is_card_sync = MMI_TRUE;
        base->error_code = ret;
        base->db_open_error = ret;
        PLS_SET_EVENT(PLS_DB_EVT_OPEN_ONLY);
        return;
    }
    else if(db_info->open_flag == SRV_PLST_OPEN_ONLY)
    {
        srv_plst_security sec;
        pls_sql_enter_instance(db_info);
        db_info->is_phone_sync = MMI_FALSE;
        db_info->is_card_sync = MMI_FALSE;

    #if defined(__PLST_DUAL_DB_SUPPORT__)
        if (local_param_ptr->drv_letter == SRV_FMGR_PUBLIC_DRV)
        {
            ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
            if(ret == SRV_PLST_OK)
            {            
                ret = pls_sql_read_version(local_param_ptr->drv_letter, db_info, &sec);
                if(ret == SRV_PLST_OK)
                { 
                    ret = pls_db_util_check_version_is_ok(SRV_FMGR_PUBLIC_DRV, base, &sec); 
                    if(ret == SRV_PLST_OK)
                    {
                        if(IS_CARD_EXIST)
                        {
                            pls_sql_close_db(db_info);
                            ret = pls_sql_open_db((U16*)&db_info->db_card_path, db_info);                            
                            if(ret == SRV_PLST_OK)
                            {
                                ret = pls_sql_read_version(SRV_FMGR_CARD_DRV, db_info, &sec);
                                if(ret == SRV_PLST_OK)
                                { 
                                    ret = pls_db_util_check_version_is_ok(SRV_FMGR_CARD_DRV, base, &sec);                                     
                                    if(ret == SRV_PLST_OK)
                                    {                                        
                                        pls_sql_close_db(db_info);                                      
                                        pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                                        ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);                                        
                                    }
                                }                            
                            }                            
                        }/* card exist */
                    }
                }/* end of check version */
                if(ret != SRV_PLST_OK)
                {
                    pls_sql_close_db(db_info);
                }
            }
        }
    #else /* __PLST_DUAL_DB_SUPPORT__ */
        ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
        if(ret == SRV_PLST_OK)
        {            
            ret = pls_sql_read_version(local_param_ptr->drv_letter, db_info, &sec);
            if(ret == SRV_PLST_OK)
            { 
                ret = pls_db_util_check_version_is_ok(local_param_ptr->drv_letter, base, &sec); 
            }

            if(ret != SRV_PLST_OK)
            {
                pls_sql_close_db(db_info);
            }
        }
    #endif /*__PLST_DUAL_DB_SUPPORT__*/

        pls_sql_exit_instance(db_info);
        base->error_code = ret;
        base->db_open_error = ret;
        PLS_SET_EVENT(PLS_DB_EVT_OPEN_ONLY);
        return;
    }
    else if(db_info->open_flag == SRV_PLST_OPEN_AFTER_MEDIA_CHANGE)
    {
    #if defined(__PLST_DUAL_DB_SUPPORT__)
        srv_plst_security  sec;
        
        db_info->is_phone_sync = MMI_FALSE;
        db_info->is_card_sync = MMI_FALSE;
        pls_sql_enter_instance(db_info);
        if(db_info->open_flag)
        {
            FS_HANDLE fs_hdr;
            ret = pls_sql_close_db(db_info);

            fs_hdr = FS_Open((U16*)db_info->db_card_path, FS_READ_ONLY);
            if(fs_hdr < FS_NO_ERROR)
            {
                ret =pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                ret = SRV_PLST_RET_ERR_DB_NOT_FOUND;
                pls_sql_exit_instance(db_info);
                base->error_code = ret;
                db_info->is_phone_sync = MMI_TRUE;
                db_info->is_card_sync = MMI_FALSE;
                PLS_SET_EVENT(PLS_DB_EVT_OPEN_ONLY);
                return;
            }
            else
            {
                FS_Close(fs_hdr);
            }
            
            ret = pls_sql_open_db((U16*)db_info->db_card_path, db_info);
            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_read_version(SRV_FMGR_CARD_DRV, db_info, &sec);
                if(ret == SRV_PLST_OK)
                { 
                    ret = pls_db_util_check_version_is_ok(SRV_FMGR_CARD_DRV, base, &sec); 
                }  
                else
                {
                    ret = SRV_PLST_RET_ERR_DB_CRASH;
                }

                if(ret == SRV_PLST_OK)
                {
                    srv_plst_playing_context_struct *playing_info;
                    ret = pls_sql_close_db(db_info);
                    pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                    ret = pls_sql_read_version(SRV_FMGR_PUBLIC_DRV, db_info, &sec);
                    if(ret == SRV_PLST_OK)
                    { 
                        ret = pls_db_util_check_version_is_ok(SRV_FMGR_PUBLIC_DRV, base, &sec);
                    }  
                    base->error_code = ret;
                    db_info->is_phone_sync = MMI_FALSE;
                    db_info->is_card_sync = MMI_FALSE;   
                    
                    pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
                    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)handle)->playing_info);

                    if(playing_info->is_load && ret == SRV_PLST_OK)
                    {
                        pls_sql_get_active_index_by_id(db_info, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                        pls_sql_get_active_play_count_by_id(db_info, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                        pls_sql_get_default_list_count(db_info,playing_info, &playing_info->total);
                        playing_info->play_info.total_count = playing_info->total;
                        if(playing_info->total == 0)
                        {
                            playing_info->plst_id = 0;
                        }  
                    }
                }
                else
                {
                    //S32 ret_t;
                    pls_sql_close_db(db_info);
                    db_info->is_phone_sync = MMI_TRUE;
                    db_info->is_card_sync = MMI_TRUE;
                    //MAUI_02953478
                    //Error to attach a wrongly version database while MEDIA_CHANGE
                    //should close the database and return error ONLY!
                    /*
                    if(ret == SRV_PLST_VERSION_WRONG)
                    {
                        ret_t = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                        ret =  pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
                        if(ret_t != SRV_PLST_OK)
                        {
                            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_DB_OPEN_LIB);
                        }
                    }*/
                }
            }
            else
            {
                pls_sql_close_db(db_info);
                ret =pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                db_info->is_phone_sync = MMI_TRUE;
                db_info->is_card_sync = MMI_TRUE;
                ret = SRV_PLST_RET_ERR_DB_CRASH;
            }
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }          
        pls_sql_exit_instance(db_info);
    #else
        /* For single DB case, should not enter this media change codition */
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    #endif /*__PLST_DUAL_DB_SUPPORT__*/
        base->error_code = ret;
        PLS_SET_EVENT(PLS_DB_EVT_OPEN_ONLY);
        return;
    }
    else if(db_info->open_flag == SRV_PLST_OPEN_AUTO)
    {
        if(db_info->db_opened) /* change plug in case */
        {
        /* For single DB case, it should not enter this condition, since it should close app when card plug out */
        #if defined(__PLST_DUAL_DB_SUPPORT__)
            if(base->db_open_error == SRV_PLST_VERSION_WRONG)/* keep last result*/
            {
               /*delete the record from card that the media_id in the phone */
                srv_plst_playing_context_struct *playing_info;
                playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)handle)->playing_info);
                
                pls_sql_enter_instance(db_info);
                pls_sql_begin_transaction(db_info);
                ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_PUBLIC_DRV, MMI_FALSE);                
                if(ret == SRV_PLST_OK)
                {
                   ret = pls_sql_commit_transaction(db_info);
                   if(ret > SQLITE_OK && ret < SQLITE_ROW)
                   {
                       db_info->err_code = ret;
                       ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                   }
                   db_info->is_phone_sync = MMI_FALSE;
                }
                else
                {
                   pls_sql_rollback_transaction(db_info);
                }
                if(IS_CARD_EXIST)
                {
                    pls_sql_begin_transaction(db_info);
                    ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_CARD_DRV, MMI_FALSE);
                    if(ret == SRV_PLST_OK)
                    {
                        ret = pls_sql_commit_transaction(db_info);                       
                        if(ret > SQLITE_OK && ret < SQLITE_ROW)
                        {
                            db_info->err_code = ret;
                            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                        }
                        db_info->is_card_sync = MMI_FALSE;
                    }
                    else
                    {
                       pls_sql_rollback_transaction(db_info);
                    }
                }     
                if(playing_info->is_load && ret == SRV_PLST_OK)
                {
                    pls_sql_get_active_index_by_id(db_info, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                    pls_sql_get_active_play_count_by_id(db_info, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                    pls_sql_get_default_list_count(db_info,playing_info, &playing_info->total);
                    playing_info->play_info.total_count = playing_info->total;
                    if(playing_info->total == 0)
                    {
                        playing_info->plst_id = 0;
                    }  
                }
                
                pls_sql_exit_instance(db_info);
                
                base->error_code = ret;
                pls_send_db_open_rsp_msg(base, db_info, ret);

                return ;
            }
            else if(base->db_open_error == SRV_PLST_RET_ERR_DB_CRASH || base->db_open_error == SRV_PLST_RET_ERR_DB_NOT_FOUND)
            {
                /* card db crash */
                FS_Delete((U16*)&db_info->db_card_path);
                ret = pls_db_util_check_disk_space_and_get_error(base, SRV_FMGR_CARD_DRV, SRV_PLST_MIN_DB_SPACE);
                if(ret != SRV_PLST_OK)
                {
                    pls_send_db_open_rsp_msg(base, db_info, ret);
                    return ;
                }
                else /* memory enough*/
                {
                    pls_sql_enter_instance(db_info);
                    ret = pls_sql_close_db(db_info);
                    ret = pls_sql_open_db((U16*)&db_info->db_card_path, db_info);
                    pls_sql_exit_instance(db_info);
                    if(ret == SRV_PLST_OK)
                    {
                        pls_sql_enter_instance(db_info);
                        pls_sql_begin_transaction(db_info);
                        ret = pls_sql_set_db_parama(db_info);
                        ret = pls_sql_create_table(SRV_FMGR_CARD_DRV, db_info);
                        if(ret == SRV_PLST_OK)
                        {
                            ret = pls_sql_commit_transaction(db_info);
                            if(ret > SQLITE_OK && ret < SQLITE_ROW)
                            {
                                db_info->err_code = ret;
                                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                            }
                        }
                        else
                        {
                            pls_sql_rollback_transaction(db_info);
                        }
                        pls_sql_exit_instance(db_info);
                    }
                    if(ret == SRV_PLST_OK)
                    {
                        pls_sql_enter_instance(db_info);
                        pls_sql_close_db(db_info);
                        pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
                        ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
                        if(db_info->is_phone_sync || db_info->is_phone_sync)
                        {
                            pls_sql_begin_transaction(db_info);
                            if(db_info->is_phone_sync)
                            {
                                ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_PUBLIC_DRV, MMI_FALSE);
                            }
                            if(db_info->is_card_sync)
                            {
                                ret = pls_sql_media_for_version_wrong(db_info, SRV_FMGR_CARD_DRV, MMI_FALSE);
                            }
                            pls_sql_commit_transaction(db_info);
                            db_info->is_card_sync = MMI_FALSE;
                            db_info->is_phone_sync = MMI_FALSE;
                        }                        
                        pls_sql_exit_instance(db_info);
                    }
                }

                base->error_code = ret;
                pls_send_db_open_rsp_msg(base, db_info, ret);
                return ;
            }
        #else
            ASSERT(0);
        #endif /*__PLST_DUAL_DB_SUPPORT__ */

        }
        else /* check for first using, no lib was opened */
        {
            pls_db_open_lib_open_new(base, db_info, local_param_ptr->drv_letter);
        }
    }
    else  /*SRV_PLST_OPEN_NEW*/
    {
        pls_db_open_lib_open_new(base, db_info, local_param_ptr->drv_letter);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_reopen_db
 * DESCRIPTION
 *  free instance and reopen db to recover from out of memory case
 * PARAMETERS
 *  base    [IN]    see srv_plst_base_info_struct
 *  db_info [IN]    srv_plst_db_context_struct
 * RETURNS
 *  void
 *****************************************************************************/
static S32 pls_db_reopen_db(srv_plst_base_info_struct *base, srv_plst_db_context_struct *db_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PLST_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_DB_REOPEN_DB, 0);

    /* close db */
    pls_sql_enter_instance(db_info);
    pls_sql_close_db(db_info);
    pls_sql_exit_instance(db_info);

    /* free instance to make sure all memory clear */
    pls_sql_deinit_instance(db_info);

    /* init instance */
    pls_sql_init_instance(db_info, base->create.db_mem_size);

    /* Open db */
    pls_sql_enter_instance(db_info);
#if defined(__PLST_DUAL_DB_SUPPORT__)
    ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);                
    if(ret == SRV_PLST_OK)
    {            
        if(IS_CARD_EXIST)
        {
            ret = pls_sql_attach_db((U16*)&db_info->db_card_path, db_info);
        }
        if(ret != SRV_PLST_OK)
        {
            pls_sql_close_db(db_info);
        }
    }

#else /* __PLST_DUAL_DB_SUPPORT__ */
    ret = pls_sql_open_db((U16*)&db_info->db_phone_path, db_info);
#endif /* __PLST_DUAL_DB_SUPPORT__ */
    pls_sql_exit_instance(db_info);

    MMI_TRACE(TRACE_GROUP_1, MMI_PLS_PLS_DB_REOPEN_DB, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_lib_update_append_file
 * DESCRIPTION
 *  play list service db  add the found file to db
 * PARAMETERS
 *  base    [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 *****************************************************************************/
S32 pls_db_lib_update_append_file(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct *rsp_local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db_info;
    S32 ret = SRV_PLST_OK;
    U8 i;
    MMI_BOOL commit_each_file = MMI_FALSE; /* Flag to handle out of memory case */
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PTGB_START_1();

    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    MMI_TRACE(TRACE_GROUP_4,MMI_PLS_PLS_GEN_DB_APPEND,gen->append);   
    if(!gen->append)
    {
        pls_db_gen_lib_req_struct *local_param_ptr;

        /* to do, IND to caller*/
        gen->append = 0;
        gen->found = 0;
        gen->append_flag = MMI_FALSE;
        memset(&(gen->path), 0 , SRV_PLST_MAX_SLIDE_NUM*sizeof(srv_plst_gen_lib_append_path_cache_struct));
        local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);

        PTGB_END_1();
        PTGB_ROUND_REPORT(0);
        PTGB_TOTAL_REPORT();

        local_param_ptr->db_handle = db_info;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return SRV_PLST_OK;
    } 

    pls_sql_enter_instance(db_info);
    if(!db_info->enable_flag)
    {
        pls_sql_begin_transaction(db_info);
    }

// The retry only handle out of memory case, it will commit transaction for each file in retry phase
// If not retry phase, commit transaction for every 5 files added
ADD_RETRY:
    for (i = 0; i < gen->append; i ++)
    {       
        if(gen->cancel_gen)
        {
            if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
            {
                FS_FindClose(gen->search_handle);
                gen->search_handle = FS_INVALID_FILE_HANDLE;
            }           
            return SRV_PLST_OK;
        }

        // If retry due to out of memory, commit transaction transaction for each add
        if(commit_each_file && !db_info->enable_flag)
        {
            pls_sql_begin_transaction(db_info);
        }

        ret = pls_sql_append_file_to_db(base,gen->path[i].path, gen->path[i].file_ext,gen->path[i].is_short);
        gen->addc++;

        // Handle error case due to out of memory (most case due to add large image)
        if((ret == SRV_PLST_RET_ERR_SQLITE_ERR) && (db_info->err_code == SQLITE_NOMEM))
        {
            MMI_TRACE(TRACE_GROUP_4,MMI_PLS_PLS_GEN_DB_APPEND_ERROR, commit_each_file, __LINE__);   
            pls_sql_rollback_transaction(db_info);
            gen->addc = 0;

            // If add fail due to out of memory, rollback batch add and commit add transaction for each file
            if(!commit_each_file)
            {
                // Try to free memory and try again
                ret = pls_db_reopen_db(base, db_info);
                pls_sql_enter_instance(db_info); /* Instance closed in pls_db_reopen_db(), enter again */
                if(ret == SRV_PLST_OK)
                {
                    commit_each_file = MMI_TRUE;
                    goto ADD_RETRY;
                }
            }
            // Rollback and skip adding this file
            else
            {
                ret = SRV_PLST_OK;
            }
        }

        // If batch add encounter out of memory, commit transaction for each file
        if(commit_each_file)
        {
            ret = pls_sql_commit_transaction(db_info);
            gen->addc = 0;
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }

        if (ret != SRV_PLST_OK && ret != SRV_PLST_RET_CANCEL_ACTION )
        {
            pls_sql_rollback_transaction(db_info);
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db_info);            

            rsp_local_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
            rsp_local_param_ptr->db_handle = db_info;
            rsp_local_param_ptr->result = ret;
            rsp_local_param_ptr->callback = base->callback;
            base->error_code = ret;

            PTGB_END_1();
            PTGB_ROUND_REPORT(i);
            PTGB_TOTAL_REPORT();
            if(gen->cancel_gen)
            {
                if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
                {
                    FS_FindClose(gen->search_handle);
                    gen->search_handle = FS_INVALID_FILE_HANDLE;
                }
                free_local_para((local_para_struct*)rsp_local_param_ptr);
                return SRV_PLST_OK;
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
            }
            return ret;          
        } 
    }
    if(gen->addc >= SRV_PLST_MAX_SLIDE_NUM)
    {
        PTGB_START_2();
        ret = pls_sql_commit_transaction(db_info);
        PTGB_END_2();
        PTGB_COMIT_TOTAL_REPORT();
        gen->addc = 0;
    }
    pls_sql_exit_instance(db_info);
    if(ret > SQLITE_OK && ret < SQLITE_ROW)
    {
        rsp_local_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
        rsp_local_param_ptr->db_handle = db_info;
        if(ret == SQLITE_FULL)
        {
            rsp_local_param_ptr->result = SRV_PLST_RET_ERR_DISK_NOT_ENOUGH;
            base->error_code = SRV_PLST_RET_ERR_DISK_NOT_ENOUGH;
        }
        else
        {
            rsp_local_param_ptr->result = SRV_PLST_RET_ERR_SQLITE_ERR;
            base->error_code = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
        rsp_local_param_ptr->callback = base->callback;
        db_info->err_code = ret;

        pls_sql_enter_instance(db_info);
        pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
        pls_sql_exit_instance(db_info);
        if(gen->cancel_gen)
        {
            if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
            {
                FS_FindClose(gen->search_handle);
                gen->search_handle = FS_INVALID_FILE_HANDLE;
            }
            free_local_para((local_para_struct*)rsp_local_param_ptr);
            return SRV_PLST_OK;
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
        }
        return ret;
    }
    if(base->is_open_cancel == MMI_TRUE)
    {
        base->error_code = SRV_PLST_OK;
        return SRV_PLST_OK;
    }
    if (i == gen->append )
    {
        pls_db_gen_lib_req_struct *local_param_ptr;

        /* to do, IND to caller*/
        gen->append = 0;
        gen->found = 0;
        gen->append_flag = MMI_FALSE;
        memset(&(gen->path), 0 , SRV_PLST_MAX_SLIDE_NUM*sizeof(srv_plst_gen_lib_append_path_cache_struct));
        local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);

        local_param_ptr->db_handle = db_info;

        PTGB_END_1();
        PTGB_ROUND_REPORT(i);
        PTGB_TOTAL_REPORT();
        if(gen->cancel_gen)
        {
            if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
            {
                FS_FindClose(gen->search_handle);
                gen->search_handle = FS_INVALID_FILE_HANDLE;
            }
            free_local_para((local_para_struct*)local_param_ptr);
            return SRV_PLST_OK;
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return SRV_PLST_OK;
    }  
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_lib_update_add_file_to_cache
 * DESCRIPTION
 *  add the finded file to path cache
 * PARAMETERS
 *  base    [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 *****************************************************************************/
S32 pls_db_lib_update_add_file_to_cache(srv_plst_base_info_struct *base, UI_string_type path, UI_string_type file_ext, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_gen_lib_context_struct *gen;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    gen->found ++;

    if (ret != SRV_PLST_RET_ERR_SQLITE_ERR)
    {
        mmi_ucs2ncpy((CHAR*)&gen->path[gen->append].path, (const CHAR*)path, SRV_FMGR_PATH_MAX_LEN);
        mmi_ucs2ncpy((CHAR*)&gen->path[gen->append].file_ext, (const CHAR*)file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        gen->path[gen->append].is_short = is_short;
        gen->append ++;
        return SRV_PLST_OK;
    }
    else 
    {
        return ret;
    }
}


/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_init
 * DESCRIPTION
 *    init update library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_init(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_gen_lib_context_struct* gen;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_reset_exist_flag_for_udpate(db);
    if(ret == SRV_PLST_OK)
    {
        ret = pls_sql_commit_transaction(db);
        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            db->err_code = ret;
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
    }
    else
    {
        pls_sql_rollback_transaction(db);
    }
    pls_sql_exit_instance(db);
    if(ret == SRV_PLST_OK)
    {
        pls_db_gen_lib_req_struct *local_param_ptr;

        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para( sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db;
        gen->phase = SRV_PLST_GEN_PHASE_SET_DRV;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return ;
    }
    else
    {
        pls_db_exec_rsp_struct* rsp_param_ptr;
        rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
        rsp_param_ptr->result = ret;
        rsp_param_ptr->db_handle = db;
        base->error_code = ret;

        pls_sql_enter_instance(db);
        pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
        pls_sql_exit_instance(db);

        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)rsp_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_param_ptr);
        }
    }

}

/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_set_drv
 * DESCRIPTION
 *    update/ add library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_set_drv(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct *local_param_ptr;
    srv_plst_gen_lib_context_struct* gen;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    if (!gen->drv_idx) /* current only support phone and card two storage*/
    {       
        if(g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY)
        {
            kal_wsprintf(gen->path_cache, "%c:\\", SRV_FMGR_CARD_DRV);
        }
        else
        {
            kal_wsprintf(gen->path_cache, "%c:\\", SRV_FMGR_PUBLIC_DRV);
        }
        gen->drv_idx++;
        gen->phase = SRV_PLST_GEN_PHASE_SEARCH_FIRST;
    }    
#if defined(__PLST_DUAL_DB_SUPPORT__)
    else if (gen->drv_idx == 1 && IS_CARD_EXIST)
    {
        if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
        } 
        kal_wsprintf(gen->path_cache, "%c:\\", SRV_FMGR_CARD_DRV);
        gen->drv_idx++;
        gen->phase = SRV_PLST_GEN_PHASE_SEARCH_FIRST;        
    }
#endif /*__PLST_DUAL_DB_SUPPORT__*/
    else
    {
        gen->phase = SRV_PLST_GEN_PHASE_FINISH;
    }
    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para( sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    if(gen->cancel_gen)
    {
        free_local_para((local_para_struct*)local_param_ptr);
    }
    else
    {
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
    }
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_search
 * DESCRIPTION
 *    update/ add library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_search(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct* local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db;
    UI_character_type file_ext[SRV_PLST_MAX_EXT_LEN + 1];
    FS_DOSDirEntry file_info;
    FS_HANDLE ret = FS_NO_ERROR;
    U8 i = 0;
    MMI_BOOL is_shortname = MMI_FALSE;    
#ifdef __DRM_V02__
    UI_character_type odf_path[SRV_PLST_MAX_PATH_LEN];
    UI_character_type ext_in_odf[SRV_PLST_MAX_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    gen->temp_name[0] = 0;
    gen->temp_name[1] = 0;
    gen->temp_path[0] = 0;
    
    mmi_ucs2ncpy((CHAR*)gen->temp_path, (const CHAR*)gen->path_cache, SRV_FMGR_PATH_MAX_LEN);
    mmi_ucs2ncat((CHAR*)gen->temp_path, (const CHAR*)L"*.*", 3);
        
    if (gen->phase == SRV_PLST_GEN_PHASE_SEARCH_FIRST)
    {
        PTGB_FIRSTN_START();
        ret = FS_FindFirstN(
                (PU16)gen->temp_path,
                NULL,
                0,
                FS_ATTR_DIR,    /* only search media files in this phase. */
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)gen->temp_name,
                SRV_PLST_MAX_FILE_LEN * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
        
        PTGB_FIRSTN_END();
        PTGB_FIRSTN_REPORT();

        if (ret >= FS_NO_ERROR)
        {
            gen->search_handle = ret;
            gen->phase = SRV_PLST_GEN_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (gen->stack_index < SRV_PLST_MAX_FOLDER_DEPTH)
            {
                gen->stack[gen->stack_index].level = gen->stack_index;
                gen->stack[gen->stack_index].total_sub_folder = 0;
                gen->stack[gen->stack_index].index = 0;
                gen->stack[gen->stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(gen->stack_index < SRV_PLST_MAX_FOLDER_DEPTH);
            }
        }
        else
        {
            if (gen->stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                    local_param_ptr->db_handle = db;
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                    }
                }
                else
                {
                    pls_db_exec_rsp_struct* rsp_local_param_ptr;

                    gen->last_error_code = ret;
                    rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                    rsp_local_param_ptr->db_handle = db;
                    base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
                    base->ture_err_code = ret;
                    rsp_local_param_ptr->callback = base->callback;
                    rsp_local_param_ptr->result = SRV_PLST_RET_ERR_FS_ERROR;

                    pls_sql_enter_instance(db);
                    pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
                    pls_sql_exit_instance(db);

                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)rsp_local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
                    }
                }
            }
            else
            {
                gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                local_param_ptr->db_handle = db;
                if(gen->cancel_gen)
                {
                    free_local_para((local_para_struct*)local_param_ptr);
                }
                else
                {
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                }
            }
            return;
        }
    }
    else if (gen->phase == SRV_PLST_GEN_PHASE_SEARCH_NEXT)
    {
        PTGB_NEXTN_START();
        ret = FS_FindNextN(
                        gen->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)gen->temp_name,
                        SRV_PLST_MAX_FILE_LEN * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);

        PTGB_NEXTN_END();
        PTGB_NEXTN_REPORT();

        if (ret < FS_NO_ERROR)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
            if (ret == FS_NO_MORE_FILES)
            {
                if (!gen->stack[gen->stack_index].total_sub_folder)
                {
                    gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                    local_param_ptr->db_handle = db ;
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                    }
                }
                else
                {
                    if (gen->stack_index < SRV_PLST_MAX_FOLDER_DEPTH)
                    {
                        gen->phase = SRV_PLST_GEN_PHASE_FORWARDS;
                        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                        local_param_ptr->db_handle = db;
                        if(gen->cancel_gen)
                        {
                            free_local_para((local_para_struct*)local_param_ptr);
                        }
                        else
                        {
                            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                        }
                    }
                    else
                    {
                        gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                        local_param_ptr->db_handle = db;
                        if(gen->cancel_gen)
                        {
                            free_local_para((local_para_struct*)local_param_ptr);
                        }
                        else
                        {
                            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                        }
                    }
                }
            }
            else
            {
                if (gen->stack_index == 0)
                {
                    pls_db_exec_rsp_struct* rsp_local_param_ptr;
                    gen->last_error_code = ret;
                    rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                    rsp_local_param_ptr->db_handle = db;
                    base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
                    base->ture_err_code = ret;
                    rsp_local_param_ptr->callback = base->callback;
                    rsp_local_param_ptr->result = SRV_PLST_RET_ERR_FS_ERROR;

                    pls_sql_enter_instance(db);
                    pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
                    pls_sql_exit_instance(db);
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)rsp_local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
                    }
                }
                else
                {
                    gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                    local_param_ptr->db_handle = db;
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                    }
                }
            }
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(gen->phase == SRV_PLST_GEN_PHASE_SEARCH_NEXT ||
                   gen->phase == SRV_PLST_GEN_PHASE_SEARCH_FIRST);
    }    
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            is_shortname = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
            //is_shortname = ((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] != ' ')
                    {
                        file_ext[j] = (UI_character_type) file_info.Extension[j];
                    }
                    else
                    {
                        break;
                    }
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR *ext = mmi_ucs2rchr((const CHAR*)gen->temp_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (const CHAR*)ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }
            if(pls_db_util_check_format_is_support(file_ext))
            {
            #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((const CHAR*)file_ext, (const CHAR*)L"odf", (U32)mmi_ucs2strlen((const CHAR*)file_ext)))
                {
                    mmi_ucs2ncpy((CHAR*)odf_path, (const CHAR*)gen->path_cache, SRV_FMGR_PATH_MAX_LEN);
                    mmi_ucs2ncat((CHAR*)odf_path, (const CHAR*)gen->temp_name, mmi_ucs2strlen((const CHAR*)gen->temp_name));
                    
                    if (!DRM_is_archive(0, (PU16)odf_path))
                    {
                        ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                        if (ext_name_p != NULL)
                        {
                            mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));
                        }
                        else
                        {
                            file_ext[0] = 0;
                        }
                    }
                    else
                    {
                        gen->phase = SRV_PLST_GEN_PHASE_SEARCH_ODF;
                        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                        local_param_ptr->db_handle = db;
                        if(gen->cancel_gen)
                        {
                            free_local_para((local_para_struct*)local_param_ptr);
                        }
                        else
                        {
                            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                        }
                        return ;
                    }
                }
                else
            #endif  /* __DRM_V02__ */
                {
                    if (mmi_ucs2strlen((const CHAR*)gen->path_cache) + 
                        mmi_ucs2strlen((const CHAR*)gen->temp_name) <= SRV_FMGR_PATH_MAX_LEN)
                    {
                        U32 path_len = 0;
                        U32 filename_len = 0;
                        
                        path_len = mmi_ucs2strlen((const CHAR*)gen->path_cache);
                        filename_len = mmi_ucs2strlen((const CHAR*)gen->temp_name);

                        if (path_len + filename_len <= SRV_FMGR_PATH_MAX_LEN)
                        {
	                        mmi_ucs2ncpy((CHAR*)gen->temp_path, (const CHAR*)gen->path_cache, (SRV_FMGR_PATH_MAX_LEN));
	                        mmi_ucs2ncat((CHAR*)gen->temp_path, (const CHAR*)gen->temp_name, mmi_ucs2strlen((const CHAR*)gen->temp_name));

	                        
	                        {
	                            MMI_BOOL is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
	                            /* add media file data to data file. */  
	                            ret = pls_db_lib_update_add_file_to_cache(base,gen->temp_path, file_ext,is_short);
	                          
	                            if (ret != SRV_PLST_OK)
	                            {
                                    pls_db_exec_rsp_struct* rsp_local_param_ptr;

	                                FS_FindClose(gen->search_handle);
	                                gen->search_handle = FS_INVALID_FILE_HANDLE;

                                    gen->last_error_code = ret;
                                    rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                                    rsp_local_param_ptr->db_handle = db;
                                    base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
                                    base->ture_err_code = ret;
                                    rsp_local_param_ptr->callback = base->callback;
                                    rsp_local_param_ptr->result = SRV_PLST_RET_ERR_FS_ERROR;

                                    pls_sql_enter_instance(db);
                                    pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
                                    pls_sql_exit_instance(db);
                                    if(gen->cancel_gen)
                                    {
                                        free_local_para((local_para_struct*)rsp_local_param_ptr);
                                    }
                                    else
                                    {
                                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
                                    }
                                    return;
                                }
                                else 
                                {
                                    if(gen->append == SRV_PLST_MAX_SLIDE_NUM)
                                    {
                                        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                                        local_param_ptr->db_handle = db;
                                        gen->append_flag = MMI_TRUE;
                                        if(gen->cancel_gen)
                                        {
                                            free_local_para((local_para_struct*)local_param_ptr);
                                        }
                                        else
                                        {
                                            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                                        }
                                        return ;    
                                    }
                                }
                            }
                        }
                        else
                        {
                            /* too long path, skip it! */
                        }
                    }
                }
            }
            /* skip to answer other messages. */
            if ((++i) == SRV_PLST_MAX_SLIDE_NUM)    
            {
                local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                local_param_ptr->db_handle = db;                 
                gen->append_flag = MMI_TRUE;
                if(gen->cancel_gen)
                {
                    free_local_para((local_para_struct*)local_param_ptr);
                }
                else
                {
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                }
                return ;             
            }
        }
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((const CHAR*)gen->temp_name) < 3)
            {
                if (mmi_ucs2cmp((const CHAR*)gen->temp_name, (const CHAR*)L".") &&
                    mmi_ucs2cmp((const CHAR*)gen->temp_name, (const CHAR*)L".."))
                {
                    gen->stack[gen->stack_index].total_sub_folder++;
                }
            }
            else
            {
                gen->stack[gen->stack_index].total_sub_folder++;
            }
            /* skip to answer other messages. */
            if ((++i) == SRV_PLST_MAX_SLIDE_NUM * 2)    
            {
                local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                local_param_ptr->db_handle = db;                
                gen->append_flag = MMI_TRUE;
                if(gen->cancel_gen)
                {
                    free_local_para((local_para_struct*)local_param_ptr);
                }
                else
                {
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                }
                return ;             
            }
        }
        
        PTGB_NEXTN_START();
        ret = FS_FindNextN(
                        gen->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)gen->temp_name,
                        SRV_PLST_MAX_FILE_LEN * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
        PTGB_NEXTN_END();
        PTGB_NEXTN_REPORT();

    } while (ret == FS_NO_ERROR);
    FS_FindClose(gen->search_handle);
    gen->search_handle = FS_INVALID_FILE_HANDLE;
    if (gen->stack_index < SRV_PLST_MAX_FOLDER_DEPTH)
    {
        gen->phase = SRV_PLST_GEN_PHASE_FORWARDS;
    }
    else
    {
        gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
    }
    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    if(gen->cancel_gen)
    {
        free_local_para((local_para_struct*)local_param_ptr);
    }
    else
    {
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
    }
    return ;            
}


/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_forwards
 * DESCRIPTION
 *    update/ add library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_forwards(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;
    FS_HANDLE file_handle;
    S32 return_value = 0;
    FS_DOSDirEntry file_info;
    U16 counter = 0;
    srv_plst_gen_lib_context_struct* gen;
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    gen->temp_path[0] = 0;
    gen->temp_name[0] = 0;
    gen->temp_name[1] = 0;
    MMI_ASSERT(gen->stack_index < SRV_PLST_MAX_FOLDER_DEPTH);
    if (!gen->stack[gen->stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return ;
    }
    else if (gen->stack[gen->stack_index].total_sub_folder == 
                                gen->stack[gen->stack_index].index)
    {
        gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return ;
    }
    else    /* need forwards. */
    {
        mmi_ucs2ncpy((CHAR*)gen->temp_path, (const CHAR*)gen->path_cache, SRV_FMGR_PATH_MAX_LEN);
        mmi_ucs2ncat((CHAR*)gen->temp_path, (const CHAR*)L"*.*", 3);

        PTGB_FIRSTN_START();
        file_handle = FS_FindFirstN(
                        (PU16)gen->temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)gen->temp_name,
                        SRV_PLST_MAX_FILE_LEN * ENCODING_LENGTH,
                        gen->stack[gen->stack_index].fs_index,
                        FS_FIND_DEFAULT);
        PTGB_FIRSTN_END();
        PTGB_FIRSTN_REPORT();
        
        if (file_handle >= FS_NO_ERROR)
        {
            do
            {
                counter++;
                /* test if pass the filter */
                if (file_info.Attributes & FS_ATTR_DIR)
                {
                    FS_FindClose(file_handle);

                    /* check path length. */
                    
                    path_length = mmi_ucs2strlen((const CHAR*)gen->path_cache);
                    sub_folder_length = mmi_ucs2strlen((const CHAR*)gen->temp_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;
                    if (total_length > SRV_FMGR_PATH_MAX_LEN)
                    {
                        gen->stack[gen->stack_index].fs_index += counter;
                        gen->stack[gen->stack_index].index++;
                    }
                    else 
                    {
                        if ((gen->stack_index + 1) < SRV_PLST_MAX_FOLDER_DEPTH)
                        {
                            /* compose next level path. */
                            mmi_ucs2cat((CHAR*)gen->path_cache, (const CHAR*)gen->temp_name);
                            mmi_ucs2cat((CHAR*)gen->path_cache, (const CHAR*)L"\\");

                            /* save level node info. */
                            gen->stack[gen->stack_index].fs_index += counter;
                            gen->stack[gen->stack_index].index++;
                            /* entry next level. */
                            gen->stack_index++;
                            gen->phase = SRV_PLST_GEN_PHASE_SEARCH_FIRST;
                            
                            local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                            local_param_ptr->db_handle = db;
                            if(gen->cancel_gen)
                            {
                                free_local_para((local_para_struct*)local_param_ptr);
                            }
                            else
                            {
                                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                            }
                            return ;
                        }
                        else /* get max depth. */
                        {
                            /* to get next file, even have a sub-directory. */
                            gen->phase = SRV_PLST_GEN_PHASE_SEARCH_NEXT;
                            local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                            local_param_ptr->db_handle = db;
                            if(gen->cancel_gen)
                            {
                                free_local_para((local_para_struct*)local_param_ptr);
                            }
                            else
                            {
                                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                            }
                            return ;
                        }
                    }
                }
                
                PTGB_NEXTN_START();
                return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)gen->temp_name,
                                SRV_PLST_MAX_FILE_LEN * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
                PTGB_NEXTN_END();
                PTGB_NEXTN_REPORT();

            } while (return_value == FS_NO_ERROR);
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
            local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
            local_param_ptr->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
            }
            return ;
        }
        else
        {
            if (gen->stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                    local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                    local_param_ptr->db_handle = db;
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                    }
                    return ;
                }
                else
                {
                    pls_db_exec_rsp_struct* rsp_local_param_ptr;
                    
                    gen->last_error_code = file_handle;
                    base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
                    base->ture_err_code = file_handle;
                    rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                    rsp_local_param_ptr->db_handle = db;
                    rsp_local_param_ptr->callback = base->callback;
                    rsp_local_param_ptr->result = SRV_PLST_RET_ERR_FS_ERROR;

                    pls_sql_enter_instance(db);
                    pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
                    pls_sql_exit_instance(db);
                    if(gen->cancel_gen)
                    {
                        free_local_para((local_para_struct*)rsp_local_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
                    }
                    return ;
                }
            }
            else
            {
                gen->phase = SRV_PLST_GEN_PHASE_BACKWARDS;
                local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
                local_param_ptr->db_handle = db;
                if(gen->cancel_gen)
                {
                    free_local_para((local_para_struct*)local_param_ptr);
                }
                else
                {
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
                }
                return ;
            }        
        }
    }   
}


/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_backwards
 * DESCRIPTION
 *    update/ add library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_backwards(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct* local_param_ptr;
    srv_plst_gen_lib_context_struct* gen;
    srv_plst_db_context_struct *db;
    CHAR *last_backlash = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    if (gen->stack_index > 0)
    {
        memset(&(gen->stack[gen->stack_index]), 0, 
                    sizeof(srv_plst_gen_lib_stack_node_struct));
        /* update path cache. */
        last_backlash = mmi_ucs2rchr((const CHAR*)gen->path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (gen->phase == SRV_PLST_GEN_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((const CHAR*)gen->path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        mmi_ucs2ncat((CHAR*)gen->path_cache, (const CHAR*)L"\\", 1);
        gen->stack_index--;

        gen->phase = SRV_PLST_GEN_PHASE_FORWARDS;
        local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
        }
        return ;
    }
    else
    {
        if (gen->run_type == SRV_PLST_GEN_ADD)
        {
            gen->phase = SRV_PLST_GEN_PHASE_FINISH;
            local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
            local_param_ptr->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
            }
            return ;
        }
        else if (gen->run_type == SRV_PLST_GEN_SYNC_ALL)
        {
            gen->phase = SRV_PLST_GEN_PHASE_SET_DRV;
            local_param_ptr = (pls_db_gen_lib_req_struct*) construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
            local_param_ptr->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr);
            }
            return ;
        }
        else
        {
            pls_db_exec_rsp_struct* rsp_local_param_ptr;
            rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
            rsp_local_param_ptr->db_handle = db;
            rsp_local_param_ptr->result = SRV_PLST_RET_ERR_UNKOWN_ERR;
            rsp_local_param_ptr->callback = base->callback;
            base->error_code = SRV_PLST_RET_ERR_UNKOWN_ERR;

            pls_sql_enter_instance(db);
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db);
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)rsp_local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
            }
            return ;
        }
    }
}


/******************************************************************
 * FUNCTION
 *    pls_db_lib_update_gen_finish
 * DESCRIPTION
 *    update/ add library 
 * PARAMETERS
 *  base             [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_lib_update_gen_finish(srv_plst_base_info_struct * base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* local_param_ptr;
    srv_plst_gen_lib_context_struct* gen;
    srv_plst_db_context_struct* db;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;  
    MMI_BOOL is_exist = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->playing_info);
    local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
    {
        FS_FindClose(gen->search_handle);
        gen->search_handle = FS_INVALID_FILE_HANDLE;
    }

    if(db->enable_flag)
    {
        pls_sql_enter_instance(db);
        ret = pls_sql_commit_transaction(db);
        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            db->err_code = ret; 
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        
            local_param_ptr->result = ret;
            base->error_code = ret;
            local_param_ptr->callback = base->callback;
            local_param_ptr->db_handle = db;

            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);          
            return;  
        }
        else
        {
            ret = SRV_PLST_OK;
        }        
   
    }
    
    if(gen->stack_index)
    {
        local_param_ptr->result = SRV_PLST_RET_ERR_UNKOWN_ERR;
        base->error_code = SRV_PLST_RET_ERR_UNKOWN_ERR;
        local_param_ptr->callback =base->callback;
        local_param_ptr->db_handle = db;

        pls_sql_enter_instance(db);
        pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
        pls_sql_exit_instance(db);
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);
        return;
    } 
    
    if(gen->run_type == SRV_PLST_GEN_ADD)
    {
        pls_sql_enter_instance(db);
        
        if(playing_info->is_load)
        {
            pls_sql_begin_transaction(db);        
            if(ret == SRV_PLST_OK)
            {
                pls_sql_commit_transaction(db);
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
            playing_info->play_info.total_count = playing_info->total;
            if(playing_info->total == 0)
            {
                playing_info->plst_id = 0;            
            }           
        }
        pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
        pls_sql_exit_instance(db);

        local_param_ptr->result = ret;
        base->error_code = ret;
        local_param_ptr->callback = base->callback;
        local_param_ptr->db_handle = db;
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);
        return ; 
    }
    /* delete the unexist media */
    pls_sql_enter_instance(db);
    is_exist = pls_sql_check_if_need_del_unexist_file(db);   
    if(is_exist)
    {
        pls_sql_begin_transaction(db);
        ret = pls_sql_del_unexist_file(db);
        if(gen->cancel_gen)
        {
            pls_sql_rollback_transaction(db); 
            pls_sql_exit_instance(db);
            free_local_para((local_para_struct*)local_param_ptr);
            return;
        }
        if(playing_info->is_load)
        {
            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
            playing_info->play_info.total_count = playing_info->total;
            if(playing_info->total == 0)
            {
                playing_info->plst_id = 0;
            }  
        }
        if(ret == SRV_PLST_RET_CONTINUE)
        {
            pls_db_gen_lib_req_struct *local_param_ptr1;

            pls_sql_commit_transaction(db);
            pls_sql_exit_instance(db);
            free_local_para((local_para_struct*)local_param_ptr);
            local_param_ptr1 = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
            local_param_ptr1->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr1);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP, local_param_ptr1);
            }
            return ;               
        }
        else if(ret == SRV_PLST_RET_DELETE_ACTIVE)
        {
            pls_sql_commit_transaction(db);
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db);
            local_param_ptr->result = ret;
            base->error_code = ret;
            local_param_ptr->callback = base->callback;
            local_param_ptr->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);          
            }
            return;
        }
        else
        {
            if(ret == SRV_PLST_OK)
            {
                pls_sql_commit_transaction(db);
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db);
            local_param_ptr->result = ret;
            base->error_code = ret;
            local_param_ptr->callback = base->callback;
            local_param_ptr->db_handle = db;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);
            }
            return ;
        }        
    }
    else
    {  
        pls_sql_enter_instance(db);
        if(playing_info->is_load)
        {
            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
            playing_info->play_info.total_count = playing_info->total;
            if(playing_info->total == 0)
            {
                playing_info->plst_id = 0;
            }  
        }
        pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
        pls_sql_exit_instance(db);
        local_param_ptr->result = ret;
        base->error_code = ret;
        local_param_ptr->callback = base->callback;
        local_param_ptr->db_handle = db;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, local_param_ptr);
        }
        return ; 
    }
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_lib_update_gen_internal
 * DESCRIPTION
 *  player list service db msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_lib_update_gen_internal(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct *local_param_ptr;
    pls_db_exec_rsp_struct  *rsp_local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct  *db;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    local_param_ptr = (pls_db_gen_lib_req_struct*)ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(db->srv_hdr))->gen);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info);
    
    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GEN_DB_INTERNAL,gen->phase , gen->run_type);   
    if(gen->run_type == SRV_PLST_GEN_NONE)
    {
        return;
    }
    if (gen->pause_gen)
    {
        base->error_code = SRV_PLST_OK;
        return;
    }
    
    if (gen->cancel_gen == 1)
    {
        if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
        }
        return ;
    }

    if (gen->append_flag == MMI_TRUE ||
        (gen->phase == SRV_PLST_GEN_PHASE_FINISH && gen->append != 0))
    {
        pls_db_lib_update_append_file(base);
        return;
    }
    
        /* check file or folder */
    if(gen->phase == SRV_PLST_GEN_PHASE_SEARCH_FIRST && gen->run_type == SRV_PLST_GEN_ADD)
    {
        UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
        MMI_BOOL is_multi_part_odf;
        CHAR *last_backlash = NULL; 
        CHAR *ext ;

         /* check the target whether is a multi_part ODF file. */ 
        #ifdef __DRM_V02__
            if (NULL != (file_ext = mmi_ucs2rchr((const CHAR*)gen->path_cache, (U16)L'.')))
            {
                if (!mmi_ucs2nicmp((const CHAR*)file_ext, 
                        (const CHAR*)L".odf", (U32)mmi_ucs2strlen((const CHAR*)file_ext)))
                {
                    if (DRM_is_archive(0, (PU16)gen->path_cache))
                    {
                        is_multi_part_odf = MMI_TRUE;
                    }
                    else 
                    {
                        is_multi_part_odf = MMI_FALSE;
                    }             
                }
            }
            else
            {
                is_multi_part_odf = MMI_FALSE;
            }
        #else
            is_multi_part_odf = MMI_FALSE;
			ext = mmi_ucs2rchr((const CHAR*)gen->path_cache, (U16)L'.');
			if (ext != NULL)
			{
				ext += 2;
				mmi_ucs2ncpy((CHAR*)file_ext, (const CHAR*)ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
			}
			else
			{
				ext = NULL;
				file_ext[0] = 0;
			}
        #endif  /* __DRM_V02__ */     
        /* check the target whether is a folder. */
        

        last_backlash = mmi_ucs2rchr((const CHAR*)gen->path_cache, (U16)L'\\');

        if (2 > mmi_ucs2strlen((const CHAR*)last_backlash) || is_multi_part_odf)
        {
            /* do the nothing in this loop */
        }
        else /* it's a file append it */
        {
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            ret = pls_sql_append_file_to_db(base,gen->path_cache, file_ext ,gen->is_short);

            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_commit_transaction(db);
                if(ret > SQLITE_OK && ret < SQLITE_ROW)
                {
                    db->err_code = ret;
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                }
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            if(playing_info->is_load)
            {
                pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                playing_info->play_info.total_count = playing_info->total;
                if(playing_info->total == 0)
                {
                    playing_info->plst_id = 0;            
                }           
            }
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db);

            rsp_local_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
            rsp_local_param_ptr->db_handle = db;
            rsp_local_param_ptr->result = ret;
            rsp_local_param_ptr->callback = base->callback;
            base->error_code = ret;
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)rsp_local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
            }
            return;
        }
    }

    
    switch (gen->phase)
    {
        case SRV_PLST_GEN_PHASE_INIT:
            pls_db_lib_update_gen_init(base);
            break;
            
        case SRV_PLST_GEN_PHASE_SET_DRV:
            pls_db_lib_update_gen_set_drv(base);
            break;
            
        case SRV_PLST_GEN_PHASE_SEARCH_FIRST:
            pls_db_lib_update_gen_search(base);
            break;
            
        case SRV_PLST_GEN_PHASE_SEARCH_NEXT:
            pls_db_lib_update_gen_search(base);
            break;
            
        case SRV_PLST_GEN_PHASE_FORWARDS:
            pls_db_lib_update_gen_forwards(base);
            break;
            
        case SRV_PLST_GEN_PHASE_BACKWARDS:
            pls_db_lib_update_gen_backwards(base);
            break;
            
        case SRV_PLST_GEN_PHASE_FINISH:
            pls_db_lib_update_gen_finish(base);
            break;       
            
        case SRV_PLST_GEN_PHASE_SEARCH_ODF:
        #ifdef __DRM_V02__
          /* to do: pls_db_lib_update_gen_search_odf();*/
        #endif  /* __DRM_V02__ */
            break;
        default: 
            pls_sql_enter_instance(db);
            pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
            pls_sql_exit_instance(db);

            rsp_local_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
            rsp_local_param_ptr->db_handle = db;
            rsp_local_param_ptr->callback = base->callback;
            rsp_local_param_ptr->result = SRV_PLST_RET_ERR_FATAL_ERROR;
            base->error_code = SRV_PLST_RET_ERR_FATAL_ERROR;  
            if(gen->cancel_gen)
            {
                free_local_para((local_para_struct*)rsp_local_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIBRARY_UPDATE_RSP, rsp_local_param_ptr);
            }
            return;
          
    }
    return ;
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_lib_update_gen_internal
 * DESCRIPTION
 *  player list service db msg process handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    msg pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_stop_lib_update_gen(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct  *db;
    srv_plst_playing_context_struct *playing_info;
    srv_plst_gen_lib_context_struct *gen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    local_param_ptr = (pls_db_gen_lib_req_struct*)ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;

    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(db->srv_hdr))->gen);

    if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
    {
        FS_FindClose(gen->search_handle);
        gen->search_handle = FS_INVALID_FILE_HANDLE;
    }
 
    base->error_code = SRV_PLST_OK;
    if(db->enable_flag)
    {
        pls_sql_enter_instance(db);
        pls_sql_rollback_transaction(db);
        pls_sql_exit_instance(db);
    } 
    if(playing_info->is_load)
    {
        pls_sql_enter_instance(db);
        pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
        pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
        pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
        playing_info->play_info.total_count = playing_info->total;
        if(playing_info->total == 0)
        {
            playing_info->plst_id = 0;            
        }           
        pls_sql_exit_instance(db);
    }
    if(list_view->current_index == 0 && (list_view->view_type[0] == SRV_PLST_VIEW_AUDIO ||
		list_view->view_type[0]== SRV_PLST_VIEW_VIDEO || list_view->view_type[0] == SRV_PLST_VIEW_ARTIST ||
		list_view->view_type[0] == SRV_PLST_VIEW_ALBUM))
    {
        memset(&(list_view->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[0].last_index = 0;
        list_view->list_cache[0].first_index = 0;
        list_view->list_cache[0].head = 0;
        list_view->list_cache[0].tail = 0;
        list_view->list_cache[0].cache_num = 0;
        list_view->list_cache[0].total = 0; /* Need update again after refresh */
        list_view->query_index = 0;
    }

    pls_sql_enter_instance(db);
    pls_sql_stmt_cache_finalize_all(); /* Clear all prepare cache when refresh procedure end */
    pls_sql_exit_instance(db);

    PLS_SET_EVENT(PLS_DB_EVT_STOP_UPDATE);
    return ;   
}


/******************************************************************
 * FUNCTION
 *    pls_db_util_check_item_if_in_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list_view         [IN]   
 *  index             [IN]
 *  index_o
 * RETURNS
 *  S32 error_code
 ******************************************************************/
S16 pls_db_util_check_item_if_in_cache(srv_plst_list_view_history_struct* list_view, S32 index, S32 *index_o)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_context_struct *list_cache;
    U32 i = 0;
    S16 ret = 0;
    MMI_BOOL ret1 = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cache = &(list_view->list_cache[list_view->current_index]);    
    if(list_cache->cache_num)
    {
        for(i = 0 ; i < SRV_PLST_VIEW_LIST_CACHE; i++)
        {
            if(list_cache->cache[i].idx_in_list == index && list_cache->cache[i].id != 0)
            {
                *index_o = i;
                ret1 = MMI_TRUE;
                break;
            }
        } 
    }
    else 
    {
        if(list_cache->total - index < index && index + 20 > list_cache->total)
        {
            ret = -1;
        }
        else 
        {
            ret = 1;
        }
        //list_view->query_index = index;
        return ret;
    }
    
    if(!ret1)
    {
        S32 head;
        S32 tail;

        head = list_cache->cache[list_cache->head].idx_in_list;

        if(list_cache->tail == 0 )
        {
            tail = list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list;
        }
        else
        {
            tail = list_cache->cache[list_cache->tail - 1].idx_in_list;
        }

        /* Scroll from last item to first item */
        if((tail == list_cache->total - 1) && index == 0 &&
            list_view->total_count - 1 > SRV_PLST_SELECT_SQL_MIN_NUM && 
            (list_view->query_index < index || (list_view->total_count - list_view->query_index > index)))
        {
            ret = 1;
        }
        /* Scroll from first tiem to last item*/
        else if ((head == 0) && 
                 (tail < index) &&  
                 ((index - tail) > SRV_PLST_SELECT_SQL_MIN_NUM) && 
                 ((index - tail) > (list_view->total_count - 1 - index)) && 
                 (index != list_view->query_index + 1))
        {
            ret = -1;
        }
        else if(head > tail && index < head && index > tail && (head - index) < (index - tail))
        {
            ret = -1;
        }        
        else if(list_view->query_index > index)
        {
            ret = -1;
        }
        else 
        {
            ret = 1;
        }
    }
    else
    {
        ret = 0;
    }
    //list_view->query_index = index;
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_get_show_data
 * DESCRIPTION
 *  player list service task msg processe
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_get_show_data(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_req_struct *local_param_ptr;
    pls_db_exec_get_data_struct *local_param_ptr2;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db;
    S32 index = -1;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_list_get_data_req_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info);
    list_cache = &(list_view->list_cache[list_view->current_index]);
    pls_sql_enter_instance(db);
    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,local_param_ptr->get_type,local_param_ptr->index, list_view->current_index, __LINE__);
    if (local_param_ptr->get_type == SRV_PLST_GET_ARTIST_MEDIA_COUNT_BY_ID)
    {
        ret = pls_sql_get_artist_media_count(db, local_param_ptr->id,local_param_ptr->ret_value);
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, *local_param_ptr->ret_value, 0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_COUNT)
    {
        ret = pls_sql_get_view_count(db, local_param_ptr->index,local_param_ptr->ret_value);
        list_view->list_cache[list_view->current_index].total = *local_param_ptr->ret_value;
        list_view->total_count = list_view->list_cache[list_view->current_index].total;
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, list_view->total_count, 0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_HINT_COUNT)
    {
        ret = pls_sql_get_view_hint_count(db, local_param_ptr->index,local_param_ptr->ret_value);      
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, local_param_ptr->ret_value,0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ACTIVE_LIST_COUNT)
    {
        ret = pls_sql_get_default_list_count(db,playing_info,local_param_ptr->ret_value);
        ret = pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
        playing_info->total = *local_param_ptr->ret_value;
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, local_param_ptr->ret_value, 0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_TITLE || local_param_ptr->get_type == SRV_PLST_GET_ITEM_ID ||
        local_param_ptr->get_type == SRV_PLST_GET_PATH || local_param_ptr->get_type == SRV_PLST_GET_MEDIA_ID)
    {       
        S16 ret_value = 0;
        
    #ifdef __PLST_SRV_DEFAULT_LIST__
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_DEFAULT)
        {
            U32 head;
            U32 tail;

            if(list_cache->cache_num && list_cache->tail == 0)
            {
                tail = list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list;
            }
            else
            {
                tail = list_cache->cache[list_cache->tail - 1].idx_in_list;
            }
            head = list_cache->cache[list_cache->head].idx_in_list;

            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);         
            if(ret_value &&  (!(head == 0 && ret_value < 0 && local_param_ptr->index == list_view->total_count - 1) &&
                 !(tail == list_view->total_count - 1 && ret_value > 0 && !local_param_ptr->index)) &&
                 (list_cache->cache_num !=0 &&!(list_cache->cache[0].idx_in_list == 0 && list_cache->cache[0].id && list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list == list_view->total_count - 1) &&
                (((local_param_ptr->index + 20 < head ||local_param_ptr->index > tail + 20)&& head < tail ) ||
                (head > tail && (local_param_ptr->index > head + 20 || local_param_ptr->index + 20 < tail )))))
            {
                memset(&(list_cache->cache[0]), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
                list_cache->last_index = 0;
                list_cache->first_index = 0;
                list_cache->head = 0;
                list_cache->tail = 0;
                list_cache->cache_num = 0;
                list_view->query_index = 0;
                if(local_param_ptr->index <= 20)
                {
                    ret_value = 1;
                }
                else if(local_param_ptr->index + 20 > list_view->total_count - 1)
                {
                    ret_value = -1;
                }
                else if(playing_info->pick_index > local_param_ptr->index) 
                {
                    ret_value = -1;
                }
                else
                {
                    ret_value = 1;
                }
            } 
        }        
        else 
    #endif /* __PLST_SRV_DEFAULT_LIST__ */
        {
            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        }
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            U8 loop_count = 0;            

            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA, ret_value, local_param_ptr->index, 0, __LINE__);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index);

            // For cosmos only now, if list item scroll too far, try to move cache to that position (only loop 5 times to avoid infinite loop)
        #ifdef __COSMOS_MMI_PACKAGE__
            while(ret == SRV_PLST_OK && index < 0 && loop_count < 5)
            {
                MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA, 0, 0, 0, __LINE__);
                ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index);
                loop_count++;
            }
        #endif /* __COSMOS_MMI_PACKAGE__ */
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, index,0, __LINE__);
        } 
        if(ret == SRV_PLST_OK && index >= 0)
        {
            if(local_param_ptr->get_type == SRV_PLST_GET_TITLE)
            {
                ret = pls_sql_get_view_title(db, index,local_param_ptr->ret_value);
            }
            else if(local_param_ptr->get_type == SRV_PLST_GET_ITEM_ID)
            {
                *(local_param_ptr->ret_value) = list_cache->cache[index].id;
                ret = SRV_PLST_OK;
            }
            else if(local_param_ptr->get_type == SRV_PLST_GET_PATH)
            {
                ret = pls_sql_get_media_path_by_index(db, index, local_param_ptr->ret_value);
            }
            else if(local_param_ptr->get_type == SRV_PLST_GET_MEDIA_ID)
            {
                ret = pls_sql_get_media_id_from_cache(db, index, local_param_ptr->ret_value);
            }
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
       /* list_view->bg_loading = MMI_TRUE; */
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ARTWORK && !local_param_ptr->is_nblock)
    {
        S16 ret_value;
    #ifdef __PLST_SRV_DEFAULT_LIST__
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_DEFAULT)
        {
            U32 head;
            U32 tail;

            if(list_cache->cache_num && list_cache->tail == 0)
            {
                tail = list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list;
            }
            else
            {
                tail = list_cache->cache[list_cache->tail - 1].idx_in_list;
            }
            head = list_cache->cache[list_cache->head].idx_in_list;

            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);          

            if(ret_value &&  (!(head == 0 && ret_value < 0 && local_param_ptr->index == list_view->total_count - 1) &&
                 !(tail == list_view->total_count - 1 && ret_value > 0 && !local_param_ptr->index)) &&
                (list_cache->cache_num !=0 &&!(list_cache->cache[0].idx_in_list == 0  &&list_cache->cache[0].id && list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list == list_view->total_count - 1) &&
                (((local_param_ptr->index + 20 < head ||local_param_ptr->index > tail + 20)&& head < tail) ||
                (head > tail && (local_param_ptr->index > head + 20 || local_param_ptr->index + 20 < tail)))))
            {
                memset(&(list_cache->cache[0]), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
                list_cache->last_index = 0;
                list_cache->first_index = 0;
                list_cache->head = 0;
                list_cache->tail = 0;
                list_cache->cache_num = 0;
                list_view->query_index = 0;
                if(local_param_ptr->index <= 20)
                {
                    ret_value = 1;
                }
                else if(local_param_ptr->index + 20 > list_view->total_count - 1)
                {
                    ret_value = -1;
                }
                else if(playing_info->pick_index > local_param_ptr->index) 
                {
                    ret_value = -1;
                }
                else
                {
                    ret_value = 1;
                }
            }
        }        
        else 
    #endif /* __PLST_SRV_DEFAULT_LIST__ */
        {
            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        }
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret_value, local_param_ptr->ret_value,0, __LINE__);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index);   
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, index,0, __LINE__);
        }   
        if(ret == SRV_PLST_OK && index >= 0)
        {
            ret = pls_sql_get_artwork_context(db, index,local_param_ptr->ret_value);       
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
    }  
    else if(local_param_ptr->get_type == SRV_PLST_GET_ARTWORK_BY_ID)
    {
        ret = pls_sql_get_artwork_context_by_id(db, local_param_ptr->id, local_param_ptr->ret_value);
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,local_param_ptr->id, local_param_ptr->ret_value,0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ARTWORK_PARSER_PATH_BY_ID)
    {
        ret = pls_sql_get_artwork_parser_path_by_id(db, local_param_ptr->id, local_param_ptr->ret_value);
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,local_param_ptr->id, local_param_ptr->ret_value,0, __LINE__);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_DETAILS)
    {
        ret = pls_sql_get_view_details(db, local_param_ptr->id,local_param_ptr->ret_value);      
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_DETAILS_BY_FILTER)
    {
        ret = pls_sql_get_view_details_by_filter(db, local_param_ptr->id,local_param_ptr->ret_value);      
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_DETAILS_UPDATE)
    {
        ret = pls_sql_update_view_details(db, local_param_ptr->id,local_param_ptr->ret_value);         
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ARTWORK && local_param_ptr->is_nblock)
    {
        pls_db_exec_rsp_struct* rsp_param_ptr;
        S16 ret_value;
        if(list_view->is_get_data_cancel == MMI_TRUE)
        {
            base->error_code = SRV_PLST_OK;
            return;
        }
    #ifdef __PLST_SRV_DEFAULT_LIST__
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_DEFAULT)
        {
            U32 head;
            U32 tail;

            if(list_cache->cache_num && list_cache->tail == 0)
            {
                tail = list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list;
            }
            else
            {
                tail = list_cache->cache[list_cache->tail - 1].idx_in_list;
            }
            head = list_cache->cache[list_cache->head].idx_in_list;
            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);

            if(ret_value &&  (!(head == 0 && ret_value < 0 && local_param_ptr->index == list_view->total_count - 1) &&
                 !(tail == list_view->total_count - 1 && ret_value > 0 && !local_param_ptr->index)) &&
                (list_cache->cache_num !=0 &&!(list_cache->cache[0].idx_in_list == 0  && list_cache->cache[0].id &&list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list == list_view->total_count - 1) &&
                (((local_param_ptr->index + 20 < head ||local_param_ptr->index > tail + 20)&& head < tail) ||
                (head > tail && (local_param_ptr->index > head + 20 || local_param_ptr->index + 20 < tail)))))
            {
                memset(&(list_cache->cache[0]), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
                list_cache->last_index = 0;
                list_cache->first_index = 0;
                list_cache->head = 0;
                list_cache->tail = 0;
                list_cache->cache_num = 0;
                list_view->query_index = 0;
                if(local_param_ptr->index <= 20)
                {
                    ret_value = 1;
                }
                else if(local_param_ptr->index + 20 > list_view->total_count - 1)
                {
                    ret_value = -1;
                }
                else if(playing_info->pick_index > local_param_ptr->index) 
                {
                    ret_value = -1;
                }
                else
                {
                    ret_value = 1;
                }
            }
        }
        else
    #endif /* __PLST_SRV_DEFAULT_LIST__ */
        {
            ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        }
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret_value, local_param_ptr->ret_value,0, __LINE__);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index); 
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, index,0, __LINE__);
        }   
        if(ret == SRV_PLST_OK && index >= 0)
        {
            ret = pls_sql_get_artwork_context(db, index,local_param_ptr->ret_value);       
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
        
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, 0,0, __LINE__);
        pls_sql_exit_instance(db);
        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
        rsp_param_ptr->db_handle = db;
        rsp_param_ptr->result = ret;
        rsp_param_ptr->index = local_param_ptr->index;
        rsp_param_ptr->id = local_param_ptr->id;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_DB_GET_SHOW_DATA, local_param_ptr->id, __LINE__);
        if(list_view->is_get_data_cancel)
        {
            free_local_para((local_para_struct*)rsp_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_GET_DATA_RSP,  rsp_param_ptr);
        }
        return;
    }    
    else if(local_param_ptr->get_type == SRV_PLST_UPDATE_ARTWORK && local_param_ptr->is_nblock)
    {
        pls_db_exec_rsp_struct* rsp_param_ptr;
        S16 ret_value;

        if(list_view->is_stop_update_artwork == MMI_TRUE)
        {
            base->error_code = SRV_PLST_OK;
            return;
        }
        ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret_value, local_param_ptr->ret_value,0, __LINE__);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index);   
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, index,0, __LINE__);
        }   
        if(ret == SRV_PLST_OK && index >= 0)
        {
            pls_sql_begin_transaction(db);
            ret = pls_sql_update_artwork_context(db, index,local_param_ptr->ret_value);       
            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_commit_transaction(db);
                if(ret > SQLITE_OK && ret < SQLITE_ROW)
                {
                    db->err_code = ret;
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                }
                else
                {
                    ret = SRV_PLST_OK;
                }                
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
        MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, 0,0, __LINE__);
        pls_sql_exit_instance(db);
        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
        rsp_param_ptr->db_handle = db;
        rsp_param_ptr->result = ret;
        rsp_param_ptr->index = local_param_ptr->index;
        if(list_view->is_stop_update_artwork == MMI_TRUE)
        {
            base->error_code = SRV_PLST_OK;
            free_local_para((local_para_struct*)rsp_param_ptr);
            return;
        }
        else
        {
            pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_UPDATE_ARTWORK_RSP,  rsp_param_ptr);
        }
        return;
    }
    else if(local_param_ptr->get_type == SRV_PLST_UPDATE_ARTWORK && !local_param_ptr->is_nblock)
    {
        S16 ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret_value, local_param_ptr->ret_value,0, __LINE__);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index);   
            MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, index,0, __LINE__);
        }   
        if(ret == SRV_PLST_OK && index >= 0)
        {
            pls_sql_begin_transaction(db);
            ret = pls_sql_update_artwork_context(db, index,local_param_ptr->ret_value);       
            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_commit_transaction(db);
                if(ret > SQLITE_OK && ret < SQLITE_ROW)
                {
                    db->err_code = ret;
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                }
                else
                {
                    ret = SRV_PLST_OK;
                }                
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
    }
    pls_sql_exit_instance(db);    
    base->error_code = ret;
    if(list_view->bg_loading) 
    {
        local_param_ptr2 = (pls_db_exec_get_data_struct*) construct_local_para(sizeof(pls_db_exec_get_data_struct), TD_CTRL);
        local_param_ptr2->db_handle = db;
        pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_BG_LOADING_REQ, local_param_ptr2);
        kal_sleep_task(PLS_TASK_SLEEP_TIME);
        return; 
   }
    
    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLS_GET_SHOW_DATA,ret, 0,0, __LINE__);
    PLS_SET_EVENT(PLS_DB_EVT_GET_DATA);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  pls_db_stop_update_artwork
 * DESCRIPTION
 *  player list service task msg processe
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_stop_update_artwork(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_get_data_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_get_data_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
   
    base->error_code = SRV_PLST_OK;    
   
    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return ;  
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_stop_get_show_data
 * DESCRIPTION
 *  player list service task msg processe
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void pls_db_stop_get_show_data(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_stop_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_list_get_data_stop_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    base->error_code = SRV_PLST_OK;
    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return;  
}


static void pls_db_get_cntx_by_id(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_cntx_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    local_param_ptr = (pls_db_get_cntx_req_struct*)ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);    
    ret = pls_sql_get_cntx_by_id(db, local_param_ptr->in_param, local_param_ptr->out_param);
    pls_sql_end_transaction(db);
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_DATA);
    return;
}
/******************************************************************
 * FUNCTION
 *    pls_db_get_plst_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_get_plst_index(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_get_plst_index_by_name(db, local_param_ptr->path, local_param_ptr->ret_value);        
    pls_sql_end_transaction(db);
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_PLST_INDEX);
}


/******************************************************************
 * FUNCTION
 *    pls_db_create_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_create_plst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    srv_plst_list_view_history_struct *list_view;
    S32 ret = SRV_PLST_OK;
    U32 id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_prepare_to_create_plst(db, &id, local_param_ptr->path);

    if(ret == SRV_PLST_OK)
    {       
        ret = pls_sql_create_plst(db, id, local_param_ptr->path);        
        if(ret == SRV_PLST_OK)
        {
            memset(&list_view->list_cache[list_view->current_index], 0 , sizeof(srv_plst_list_context_struct)); 
            ret = pls_sql_commit_transaction(db);
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }
        else
        {
            pls_sql_rollback_transaction(db);
        }
    }
    else
    {
        pls_sql_end_transaction(db);
    }
    pls_sql_exit_instance(db);
    base->error_code = ret;
     PLS_SET_EVENT(PLS_DB_EVT_CREATE_PLST);
}


/******************************************************************
 * FUNCTION
 *    pls_db_rename_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void  pls_db_rename_plst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;
    S16 ret_value;
    S32 index_o = 0;
    U32 id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    /* Rename previous view (play list) */
    if(list_view->current_index > 0 && list_view->view_type[list_view->current_index-1] == SRV_PLST_VIEW_PLST)
    {
        id = list_view->list_cache[1].parent_id;
    }
    else
    {
        /* Rename current view (play list, add to play list) */
        ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index_o);
        list_view->query_index = local_param_ptr->index;
        if(ret_value)
        {
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index_o);  
            pls_sql_end_transaction(db);
            pls_sql_exit_instance(db);
            if(ret != SRV_PLST_OK)
            {
                base->error_code = ret;
                PLS_SET_EVENT(PLS_DB_EVT_RENAME_PLST);
                return;
            }
        } 
        id = list_view->list_cache[list_view->current_index].cache[index_o].id;
    }
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_rename_plst(db, id, local_param_ptr->path);  
    if(ret == SRV_PLST_OK)
    {
        ret = pls_sql_commit_transaction(db);
        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            db->err_code = ret;
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
    }
    else
    {
        pls_sql_rollback_transaction(db);
    }
 
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_RENAME_PLST);
}


/******************************************************************
 * FUNCTION
 *    pls_db_get_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_get_id(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;
    S16 ret_value;
    S32 index_o = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);

    ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index_o);
    list_view->query_index = local_param_ptr->index;
    if(ret_value)
    {
        pls_sql_enter_instance(db);
        pls_sql_begin_transaction(db);
        ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index_o); 
        if(ret == SRV_PLST_OK)
        {
            ret = pls_sql_commit_transaction(db);
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }
        else
        {
            pls_sql_rollback_transaction(db);
        }
        pls_sql_exit_instance(db);
    } 
    if(index_o < 0)
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    else
    {
        *(local_param_ptr->ret_value) = list_view->list_cache[list_view->current_index].cache[index_o].id;
    }
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_ID);
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_create_mark_tbl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_create_mark_tbl(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_create_mark_tbl_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    S32 ret = SRV_PLST_OK;
    MMI_BOOL is_create;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_create_mark_tbl_req_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    is_create = local_param_ptr->is_create;

    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);

    if(is_create)
    {
        ret = pls_sql_create_mark_tbl(db);
    }
    else
    {
        ret = pls_sql_delete_mark_tbl(db);
    }

    if(ret == SRV_PLST_OK)
    {
        ret = pls_sql_commit_transaction(db);
        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            db->err_code = ret;
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
    }
    else
    {
        pls_sql_rollback_transaction(db);
    }
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_CREATE_MARK_TBL);
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_set_mark_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_set_mark_item(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    srv_plst_list_view_history_struct *list_view;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_AUDIO ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_VIDEO ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_MEDIA ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_ARTIST ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_ALBUM ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_GENRE ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE)
    {
        pls_sql_enter_instance(db);
        pls_sql_begin_transaction(db);

        
        if((list_view->is_mark && !list_view->is_mark_all)|| list_view->is_unmark_all)
        {
            ret = pls_sql_set_mark(db, list_view, local_param_ptr->index, local_param_ptr->value);
        }
        else
        {
            ret = pls_sql_set_mark(db, list_view, local_param_ptr->index, 1 - (local_param_ptr->value));
        }
        if(ret == SRV_PLST_OK)
        {
            ret = pls_sql_commit_transaction(db);
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }
        else
        {
            pls_sql_rollback_transaction(db);
        } 
        pls_sql_exit_instance(db);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }    

    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_MARK);
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_get_item_mark_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_get_item_mark_flag(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;    
    srv_plst_base_info_struct  *base;
    srv_plst_db_context_struct *db;
    srv_plst_list_view_history_struct *list_view;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_AUDIO ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_VIDEO ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_MEDIA ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_ARTIST ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_ALBUM ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_GENRE ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST ||
       list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE)
    {
        pls_sql_enter_instance(db);
        ret = pls_sql_get_mark(db, list_view, local_param_ptr->index, local_param_ptr->ret_value);
        if(ret == SRV_PLST_OK)
        {
            if(list_view->is_mark_all)
            {
                *local_param_ptr->ret_value = 1;
            }
            else
            {
                *local_param_ptr->ret_value = 0;
            }
        }
        else if(ret == SRV_PLST_RET_ITEM_EXIST)
        {
            if(list_view->is_mark_all)
            {
                *local_param_ptr->ret_value = 1 - (*local_param_ptr->ret_value);
            }
            ret = SRV_PLST_OK;
        }        
        pls_sql_exit_instance(db);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }    

    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_MARK);
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_stop_add_media_to_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_stop_add_media_to_plst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 

    if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
    {
        memset(&(list_view->list_cache[1].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[1].last_index = 0;
        list_view->list_cache[1].first_index = 0;
        list_view->list_cache[1].head = 0;
        list_view->list_cache[1].tail = 0;
        list_view->list_cache[1].cache_num = 0;
        list_view->query_index = 0;
    }
    base->error_code = SRV_PLST_OK;
    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return ;          
}


/******************************************************************
 * FUNCTION
 *    pls_db_add_media_to_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_add_media_to_plst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    pls_db_exec_rsp_struct* rsp_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    U32 plst_id = 0;
    U32 media_id = 0;
    U16 i;
    S32 ret = SRV_PLST_OK;
    S32 index_o;
    S16 ret_value;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    
    if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ADDTO)
    {
        ret_value = pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index_o);
        list_view->query_index = local_param_ptr->index;
    }
    else
    {
        ret_value = 0;
    }
    
    if(list_view->is_add_cancel)
    {
        base->error_code = SRV_PLST_OK;
        return;
    }
    if(!list_view->current_index)
    {
        ret =  SRV_PLST_RET_ERR_PARAM_ERR;
    }
    if(!((list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_AUDIO ||        
        list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_MEDIA ||
        list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_ALBUM ||
        list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_ARTIST ||
        list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_GENRE  ||
        list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_PREFIX_SEARCH )&&
        list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ADDTO) &&
        !(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA && list_view->view_type[2] != SRV_PLST_VIEW_VIDEO))
    {
        ret =  SRV_PLST_RET_ERR_PARAM_ERR;
    }

    if(ret == SRV_PLST_OK)
    {
        if(ret_value)
        {
            if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ADDTO)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                ret = pls_sql_get_item_to_fill_cache(db,local_param_ptr->index,ret_value,&index_o);  
                pls_sql_end_transaction(db);
                pls_sql_exit_instance(db);
                if(ret != SRV_PLST_OK)
                {
                    base->error_code = ret;
                    rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                    rsp_param_ptr->callback = local_param_ptr->callback;
                    rsp_param_ptr->db_handle = db;
                    rsp_param_ptr->result = ret;
                    base->error_code = ret;
                    if(list_view->is_add_cancel)
                    {
                        free_local_para((local_para_struct*)rsp_param_ptr);
                    }
                    else
                    {
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_ADD_RSP, rsp_param_ptr);
                    }
                    return;
                }
            } 
        } 

        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ADDTO)
        {
            plst_id = list_view->list_cache[list_view->current_index].cache[index_o].id;
            list_cache = &(list_view->list_cache[list_view->current_index - 1]);
        }
        else
        {
            list_cache = &list_view->list_cache[1];
            if(list_view->is_id_used[1])
            {
                plst_id = list_view->id[1];
            }
            else
            {
                plst_id = list_view->list_cache[1].parent_id;
            }
        }
        
        /* get_plstitem_count */
        pls_sql_enter_instance(db);
        base->plstitem_count = 0;
        pls_sql_get_playlist_item_count(db, plst_id, &(base->plstitem_count));
        pls_sql_exit_instance(db);

        if(base->plstitem_count >= SRV_PLST_MAX_PLST_ITEM)
        {
            rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
            rsp_param_ptr->callback = local_param_ptr->callback;
            rsp_param_ptr->db_handle = db;
            rsp_param_ptr->result = SRV_PLST_RET_PLST_FULL;
            base->error_code = ret;
            if(list_view->is_add_cancel)
            {
                free_local_para((local_para_struct*)rsp_param_ptr);
            }
            else
            {
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_ADD_RSP, rsp_param_ptr);  
            }
            return;
        }
        if(!list_view->is_mark)
        {
            media_id = 0;
            for(i = 0; i < SRV_PLST_VIEW_LIST_CACHE; i ++)
            {
                if(list_cache->cache[i].idx_in_list == local_param_ptr->value)
                {
                    media_id = list_cache->cache[i].id;
                    break;
                }
            }
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            
            if(!list_view->mark_count)
            {
                pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
            }
            ret = pls_sql_add_media_to_plst(db, media_id, plst_id);        
            if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_PLST_FULL)
            {
                if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                    #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                    ||playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                    #endif
                    ) && playing_info->plst_id == plst_id)
                {
                    pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                    pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                    pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                    playing_info->play_info.total_count = playing_info->total;
                }
                ret = pls_sql_commit_transaction(db);
                if(ret > SQLITE_OK && ret < SQLITE_ROW)
                {
                    db->err_code = ret;
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                }
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            pls_sql_exit_instance(db);
            base->error_code = ret;

            if(list_view->is_add_cancel)
            {
                return;
            }
        }
        else /* mark serval */
        {
            U8 retry_count = 0; /* Just retry once */

            while(1)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                if(!list_view->mark_count)
                {
                    pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
                }
                ret = pls_sql_add_media_to_plst(db, 0, plst_id);        

                if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_CONTINUE ||ret == SRV_PLST_RET_PLST_FULL)
                {
                    S32 ret_t;

                    if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                        || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                        #endif
                        ) && playing_info->plst_id == plst_id)
                    {
                        pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                        pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                        pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                        playing_info->play_info.total_count = playing_info->total;
                    }
                    ret_t = pls_sql_commit_transaction(db);
                    if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                    {
                        db->err_code = ret_t;
                        ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    }
                    pls_sql_exit_instance(db);
                    if(ret == SRV_PLST_RET_CONTINUE && !list_view->is_add_cancel)
                    {
                        pls_db_exec_single_db_req_struct* local_param_ptr1;
                        local_param_ptr1 = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);

                        local_param_ptr1->db_handle = db;
                        local_param_ptr1->value = local_param_ptr->value;
                        local_param_ptr1->index = local_param_ptr->index;
                        local_param_ptr1->callback = local_param_ptr->callback;
                        pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_ADD_REQ, local_param_ptr1);    
                        return ;
                    }
                    break;
                }
                else
                {
                    pls_sql_rollback_transaction(db);
                    pls_sql_exit_instance(db);

                    /* If out of memory, reopen to free memory and add again */
                    if((db->err_code == SQLITE_NOMEM) && (retry_count == 0))
                    {
                        ret = pls_db_reopen_db(base, db);
                        if(ret == SRV_PLST_OK)
                        {
                            retry_count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    if(!list_view->is_add_cancel)
    {
        rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
        rsp_param_ptr->callback = local_param_ptr->callback;
        rsp_param_ptr->db_handle = db;
        rsp_param_ptr->result = ret;
        base->error_code = ret;
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_ADD_RSP, rsp_param_ptr);
    }
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_stop_delete_media_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_stop_delete_media_item(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    base->error_code = SRV_PLST_OK;
    if(playing_info->is_load)
    {
        pls_sql_enter_instance(db);
        pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
        pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
        pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
        playing_info->play_info.total_count = playing_info->total;
        if(playing_info->total == 0)
        {
            playing_info->plst_id = 0;            
        }           
        pls_sql_exit_instance(db);
    }
    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_delete_media_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_delete_media_item(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    pls_db_exec_rsp_struct* rsp_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_view_type_enum view_type0;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    U32 id = 0;
    S32 ret = SRV_PLST_OK;
    U32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    view_type0 = list_view->view_type[list_view->current_index];
    list_cache = &(list_view->list_cache[list_view->current_index]);
    index = local_param_ptr->index;
   // ret = pls_db_util_get_id(list_cache, (U32)index, &id);
   pls_db_util_get_id(list_cache, (U32)index, &id);
    if(list_view->is_delete_cancel)
    {
        if(list_view->is_mark)
        {
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            ret = pls_sql_delete_mark_tbl(db);
            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_commit_transaction(db);
                if(ret > SQLITE_OK && ret < SQLITE_ROW)
                {
                    db->err_code = ret;
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                }
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            pls_sql_exit_instance(db);
        }
        base->error_code = ret;
        return;
    }  
    if(ret == SRV_PLST_OK)
    {
        if(view_type0 == SRV_PLST_VIEW_PLST && list_view->current_index == 0)
        {
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            if(!list_view->mark_count)
            {
                ret = pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
            }          
            ret  = pls_sql_delete_plst(db, &id);
            if(ret == SRV_PLST_RET_CONTINUE || ret == SRV_PLST_OK)
            {
                S32 ret_t;
                ret_t = pls_sql_commit_transaction(db);                
                if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                {
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    db->err_code = ret_t;
                }
                if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                    || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                #endif
                    ) && playing_info->plst_id == id)
                {
                    pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                    pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                    pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                    playing_info->play_info.total_count = playing_info->total;
                    if(playing_info->total == 0)
                    {
                        playing_info->plst_id = 0;
                    }
                }  
            }
            else
            {
                pls_sql_rollback_transaction(db);
            } 
            pls_sql_exit_instance(db);

            if(list_view->is_delete_cancel)
            {
                return;
            }
            else if(ret == SRV_PLST_RET_CONTINUE && !list_view->is_delete_cancel)
            {
                //pls_db_exec_single_db_req_struct* local_param_ptr1;
                pls_db_act_ar_media_struct* local_param_ptr1;
               // local_param_ptr1 = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
                local_param_ptr1 = (pls_db_act_ar_media_struct*)construct_local_para(sizeof(pls_db_act_ar_media_struct), TD_CTRL);

                local_param_ptr1->db_handle = db;
                local_param_ptr1->value = local_param_ptr->value;
                local_param_ptr1->index = local_param_ptr->index;
                local_param_ptr1->callback = local_param_ptr->callback;
                local_param_ptr1->is_remove = MMI_FALSE;
                
                if(list_view->mark_count)
                {
                    local_param_ptr1->progress = (list_view->prog_count * 100)/ list_view->mark_count;
                }
                else
                {
                    local_param_ptr1->progress = 100;
                }
               
               // pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, local_param_ptr1);    
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_DELETE_ITEM_IND, local_param_ptr1);
               // kal_sleep_task(PLS_TASK_SLEEP_TIME);
                return ;
            }
            else if(ret == SRV_PLST_RET_DELETE_ACTIVE)
            {
                rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                rsp_param_ptr->callback = local_param_ptr->callback;
                rsp_param_ptr->index = local_param_ptr->index;
                rsp_param_ptr->result = ret;
                base->error_code = ret;
                rsp_param_ptr->db_handle = db;
                if(!list_view->is_delete_cancel)
                {
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);           
                }
                else
                {
                    free_local_para((local_para_struct*)rsp_param_ptr);
                }
                return;
            }
        }
        else
        {        
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            if(!list_view->mark_count)
            {
                pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
            }
            ret = pls_sql_delete_media_from_list(db,list_view,local_param_ptr->index);        
            if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_AUDIO || 
                    playing_info->active_type == SRV_PLST_ACTIVE_LIST_AUDIO ||
                    playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                    #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                    || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                    #endif
                    ) && list_view->view_type[0] != SRV_PLST_VIEW_VIDEO
					//bql: MAUI_02942765
					//playing_info->played_count will be set as 0 if pls_sql_get_active_play_count_by_id()
					//error will be trigged if played_count < played_total for shuffling
					//but in the case of SRV_PLST_RET_DELETE_ACTIVE, we should not effect any play info varieble!
					//so need to skip this operation if ret == SRV_PLST_RET_DELETE_ACTIVE
					//side effect to allow operation in current list
                    && ret != SRV_PLST_RET_DELETE_ACTIVE)
            {
                pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                playing_info->play_info.total_count = playing_info->total;
                if(playing_info->total == 0)
                {
                    playing_info->plst_id = 0;
                }  
            }
        #ifdef __PLST_SRV_FEATURE_VIDEO_FIELD__
            else if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_VIDEO 
                #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_VIDEO
                #endif
                ) && list_view->view_type[0] == SRV_PLST_VIEW_VIDEO)
            {
                pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                playing_info->play_info.total_count = playing_info->total;
                if(playing_info->total == 0)
                {
                      playing_info->plst_id = 0;
                } 
            }
        #endif /* __PLST_SRV_FEATURE_VIDEO_FIELD__ */
            if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_CONTINUE)
            {
                S32 ret_t;
                ret_t = pls_sql_commit_transaction(db);
                if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                {
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    db->err_code = ret_t;
                }
                pls_sql_exit_instance(db);
                if(list_view->is_delete_cancel)
                {
                    return ;
                }
                if(ret == SRV_PLST_RET_CONTINUE && !list_view->is_delete_cancel)
                {
                    //pls_db_exec_single_db_req_struct* local_param_ptr1;
                    pls_db_act_ar_media_struct* local_param_ptr1;
                   // local_param_ptr1 = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);

                    local_param_ptr1 = (pls_db_act_ar_media_struct*)construct_local_para(sizeof(pls_db_act_ar_media_struct), TD_CTRL);
                    local_param_ptr1->db_handle = db;
                    local_param_ptr1->value = local_param_ptr->value;
                    local_param_ptr1->index = local_param_ptr->index;
                    local_param_ptr1->callback = local_param_ptr->callback;
                    local_param_ptr1->is_remove = MMI_FALSE;
                    if(list_view->mark_count)
                    {
                        local_param_ptr1->progress = (list_view->prog_count * 100)/list_view->mark_count;
                    }
                    else
                    {
                        local_param_ptr1->progress = 100;
                    }
                   // pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, local_param_ptr1);    
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_DELETE_ITEM_IND, local_param_ptr1);
                   // kal_sleep_task(PLS_TASK_SLEEP_TIME);
                    return ;
                }
            }
            else if(ret == SRV_PLST_RET_DELETE_ACTIVE)
            {
                pls_sql_rollback_transaction(db);
                pls_sql_exit_instance(db);
                if(list_view->is_delete_cancel)
                {
                    return ;
                }
                rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
                rsp_param_ptr->callback = local_param_ptr->callback;
                rsp_param_ptr->index = local_param_ptr->index;
                rsp_param_ptr->result = ret;
                base->error_code = ret;
                rsp_param_ptr->db_handle = db;
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);           
                return;
            }
            else
            {
                pls_sql_rollback_transaction(db);
                pls_sql_exit_instance(db);
            }
        }
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    
    if(!list_view->is_delete_cancel)
    {
        rsp_param_ptr = (pls_db_exec_rsp_struct*) construct_local_para(sizeof(pls_db_exec_rsp_struct), TD_CTRL);
        rsp_param_ptr->callback = local_param_ptr->callback;
        rsp_param_ptr->result = ret;
        base->error_code = ret;
        rsp_param_ptr->db_handle = db;
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
    }
    return ;   
}


/******************************************************************
 * FUNCTION
 *    pls_db_stop_remove_media_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_stop_remove_media_item(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    
    base->error_code = SRV_PLST_OK;
    if(playing_info->is_load && playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST)
    {
        pls_sql_enter_instance(db);
        pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
        pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
        pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
        playing_info->play_info.total_count = playing_info->total;
        if(playing_info->total == 0)
        {
            playing_info->plst_id = 0;            
        }                  
        pls_sql_exit_instance(db);
    }
    PLS_SET_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return ;   
}


/******************************************************************
 * FUNCTION
 *    pls_db_remove_media_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_remove_media_item(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    pls_db_exec_rsp_struct* rsp_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    U32 media_id = 0;
    U32 plst_id;
    S32 ret = SRV_PLST_OK;
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    if(list_view->is_cancel)
    {
        base->error_code = SRV_PLST_OK;
        return;        
    }
    if(list_view->current_index)
    {
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE)/*remove from now playing list*/
        {
            list_cache = &(list_view->list_cache[list_view->current_index ]);
            index = local_param_ptr->index;
            plst_id = playing_info->plst_id;

            if(!list_view->is_mark)
            {
                ret = pls_db_util_get_id(list_cache, (U32)local_param_ptr->index, &media_id);                
            }
            else
            {
                media_id = 0;
            }
            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            if(ret == SRV_PLST_OK)
            {
                ret = pls_sql_remove_item_from_list(db,list_view, plst_id, media_id);
            }
            if(ret == SRV_PLST_OK)
            {
                S32 ret_t;
                ret_t = pls_sql_commit_transaction(db);                   
                if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                {
                    ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    db->err_code = ret_t;
                }
                if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                    || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                #endif
		//bql: MAUI_02933156
		//should not compare plst_id with parent_id but need to with current deleting id.
		//the parent_id in current list can not be consumed as current list id, because no scenario flow used for current list
                    ) && playing_info->plst_id == plst_id)
                {
                    pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                    pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                    pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                    playing_info->play_info.total_count = playing_info->total;
                }
            }
            else
            {
                pls_sql_rollback_transaction(db);
            }
            pls_sql_exit_instance(db);
            if(list_view->is_cancel)
            {
                return;
            }
            if(ret == SRV_PLST_RET_DELETE_ACTIVE)
            {
                rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                rsp_param_ptr->index = local_param_ptr->index;
                base->error_code = ret;
                rsp_param_ptr->db_handle = db;
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);
                return;
            }
            else
            {
                base->error_code = ret;
                list_cache->first_index = 0;
                list_cache->last_index = 0;
                list_cache->head = 0;
                list_cache->tail = 0;
                list_cache->cache_num = 0;
                memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
                rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                rsp_param_ptr->result = ret;
                base->error_code = ret;
                rsp_param_ptr->db_handle = db;
                pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
                return;
            }           
        }
        else if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_MEDIA &&
            list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_PLST)
        {            
            list_cache = &(list_view->list_cache[list_view->current_index - 1]);
            index = local_param_ptr->index;
            plst_id = list_view->list_cache[list_view->current_index].parent_id;

            pls_sql_enter_instance(db);
            pls_sql_begin_transaction(db);
            if(list_view->is_clear) /* clear plst */
            {                   
                if(!list_view->mark_count)
                {
                    ret = pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
                }
                ret = pls_sql_clear_plst(db, plst_id);
                if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_CONTINUE)
                {
                    S32 ret_t;
                    ret_t = pls_sql_commit_transaction(db);
                    if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                    {
                        ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                        db->err_code = ret_t;
                    }
                    if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                        ||playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                        #endif
                        ) && playing_info->plst_id == list_view->list_cache[1].parent_id)
                    {
                        ret_t = pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                        pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                        pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                        playing_info->play_info.total_count = playing_info->total;
                    }                   
                } 
                else
                {
                    pls_sql_rollback_transaction(db);
                }
                pls_sql_exit_instance(db);   

                if(list_view->is_cancel)
                {
                    return;
                }
                if(!list_view->is_cancel && ret == SRV_PLST_RET_CONTINUE)
                {
                   // pls_db_exec_single_db_req_struct* local_param_ptr1;  
                    pls_db_act_ar_media_struct* local_param_ptr1;

                    //local_param_ptr1 = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
                    local_param_ptr1 = (pls_db_act_ar_media_struct*)construct_local_para(sizeof(pls_db_act_ar_media_struct),TD_CTRL);
                    local_param_ptr1->db_handle = local_param_ptr->db_handle;
                    local_param_ptr1->index = local_param_ptr->index;
                    local_param_ptr1->callback = local_param_ptr->callback;
                    local_param_ptr1->value = local_param_ptr->value;
                    local_param_ptr1->is_remove = MMI_TRUE;

                    if(list_view->mark_count)
                    {
                        local_param_ptr1->progress = (list_view->prog_count * 100)/ list_view->mark_count;
                    }
                    else
                    {
                        local_param_ptr1->progress = 100;
                    }
                  //  pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr1);
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_DELETE_ITEM_IND, local_param_ptr1);
                    kal_sleep_task(PLS_TASK_SLEEP_TIME);
                    return;                    
                }
                else if(!list_view->is_cancel)
                {
                    rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                    rsp_param_ptr->result = ret;
                    base->error_code = ret;
                    rsp_param_ptr->db_handle = db;
                    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
                    return;
                }
            }
            else /* remove fix item */
            {
                list_cache = &(list_view->list_cache[list_view->current_index]);

                if(!list_view->is_mark)
                {
                    ret = pls_db_util_get_id(list_cache, (U32)index, &media_id);                
                    if(ret == SRV_PLST_OK)
                    {
                        ret = pls_sql_remove_item_from_list(db,list_view, plst_id, media_id);
                    }
                    if(ret == SRV_PLST_OK)
                    {
                        S32 ret_t;
                        ret_t = pls_sql_commit_transaction(db);                   
                        if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                        {
                            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                            db->err_code = ret_t;
                        }
                        if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                            || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                        #endif
                            ) && playing_info->plst_id == list_view->list_cache[1].parent_id)
                        {
                            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                            playing_info->play_info.total_count = playing_info->total;
                        }
                    }
                    else
                    {
                        pls_sql_rollback_transaction(db);
                    }
                    pls_sql_exit_instance(db);
                    if(list_view->is_cancel)
                    {
                        return;
                    }
                    if(ret == SRV_PLST_RET_DELETE_ACTIVE)
                    {
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->index = local_param_ptr->index;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);
                        return;
                    }
                    else
                    {
                        base->error_code = ret;
                        list_cache->first_index = 0;
                        list_cache->last_index = 0;
                        list_cache->head = 0;
                        list_cache->tail = 0;
                        list_cache->cache_num = 0;
                        memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->result = ret;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
                        return;
                    }
                }
                else
                {
                    if(!list_view->mark_count)
                    {
                        ret = pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
                    }
                    ret = pls_sql_remove_item_from_list(db,list_view, plst_id, 0);
#if 0
/* under construction !*/
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
/* under construction !*/
                        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                    if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_CONTINUE)
                     {
                        S32 ret_t;

                        ret_t = pls_sql_commit_transaction(db);                   
                        if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                        {
                            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                            db->err_code = ret_t;
                        }
                        //bql:MAUI_02456010, only need to update playing info while ret ok or ocontinue
                        if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                            || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                        #endif
                            ) && playing_info->plst_id == list_view->list_cache[1].parent_id)
                        {
                            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                            playing_info->play_info.total_count = playing_info->total;
                        } 
                        pls_sql_exit_instance(db);
                    }
                    else
                    {
                        pls_sql_rollback_transaction(db);
                    }



                    if(list_view->is_cancel)
                    {
                        return;
                    }
                    if(ret == SRV_PLST_RET_DELETE_ACTIVE)
                    {                      
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->index = local_param_ptr->index;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);
                        return;
                    }
                    if(!list_view->is_cancel && ret == SRV_PLST_RET_CONTINUE)
                    {
                       // pls_db_exec_single_db_req_struct* local_param_ptr1; 
                        pls_db_act_ar_media_struct* local_param_ptr1;

                       // local_param_ptr1 = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
                        local_param_ptr1 = (pls_db_act_ar_media_struct*) construct_local_para(sizeof(pls_db_act_ar_media_struct), TD_CTRL);
                        local_param_ptr1->db_handle = local_param_ptr->db_handle;
                        local_param_ptr1->index = local_param_ptr->index;
                        local_param_ptr1->callback = local_param_ptr->callback;
                        local_param_ptr1->value = local_param_ptr->value;
                        local_param_ptr1->is_remove = MMI_TRUE;

                        if(list_view->mark_count)
                        {
                            local_param_ptr1->progress = (list_view->prog_count * 100)/ list_view->mark_count;
                        }
                        else
                        {
                            local_param_ptr1->progress = 100;
                        }
                       // pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr1);
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_DELETE_ITEM_IND, local_param_ptr1);
                        kal_sleep_task(PLS_TASK_SLEEP_TIME);
                        return;                    
                    }
                    else if(!list_view->is_cancel)
                    {
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->result = ret;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
            return; 
                    }
                }
            } 
        }/* view type is OK */
        else if(list_view->current_index == 2 &&
                list_view->view_type[0] == SRV_PLST_VIEW_PLST &&
                list_view->view_type[1] == SRV_PLST_VIEW_MEDIA &&
                list_view->view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH)
        {
            list_cache = &(list_view->list_cache[0]);
            index = local_param_ptr->index;
            plst_id = list_view->list_cache[1].parent_id;
            if(ret == SRV_PLST_OK)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                if(index < 0) /* clear plst */
                {                   
                    if(!list_view->mark_count)
                    {
                        ret = pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
                    }
                    ret = pls_sql_clear_plst(db, plst_id);
                    if(list_view->is_cancel)
                    {
                        pls_sql_rollback_transaction(db);        
                        pls_sql_exit_instance(db);              
                        return ;
                    }
                    if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_CONTINUE)
                    {
                        S32 ret_t;
                        ret_t = pls_sql_commit_transaction(db);
                        if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                        {
                            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                            db->err_code = ret_t;
                        }
                        if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                            #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                            || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                            #endif
                            ) && playing_info->plst_id == list_view->list_cache[1].parent_id)
                        {
                            ret_t = pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                            playing_info->play_info.total_count = playing_info->total;
                        }
                    } 
                    else
                    {
                        pls_sql_rollback_transaction(db);
                    }
                    pls_sql_exit_instance(db);   

                    if(list_view->is_cancel)
                    {
                        return;
                    }
                    if(!list_view->is_cancel && ret == SRV_PLST_RET_CONTINUE)
                    {
                       // pls_db_exec_single_db_req_struct* local_param_ptr1;  
                        pls_db_act_ar_media_struct* local_param_ptr1;

                       // local_param_ptr1 = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
                        local_param_ptr1 = (pls_db_act_ar_media_struct*) construct_local_para(sizeof(pls_db_act_ar_media_struct), TD_CTRL);
                        local_param_ptr1->db_handle = local_param_ptr->db_handle;
                        local_param_ptr1->index = local_param_ptr->index;
                        local_param_ptr1->callback = local_param_ptr->callback;
                        local_param_ptr1->value = local_param_ptr->value;
                        local_param_ptr1->is_remove = MMI_TRUE;
                        if(list_view->mark_count)
                        {
                            local_param_ptr1->progress = (list_view->prog_count * 100)/ list_view->mark_count;
                        }
                        else
                        {
                            local_param_ptr1->progress = 100;
                        }
                       // pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr1);
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_DELETE_ITEM_IND, local_param_ptr1);
                        kal_sleep_task(PLS_TASK_SLEEP_TIME);
                        return;                    
                    }
                    else if(!list_view->is_cancel)
                    {
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->result = ret;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
                        return;
                    }
                }
                else /* remove fix item */
                {
                    list_cache = &(list_view->list_cache[list_view->current_index]);
                    ret = pls_db_util_get_id(list_cache, index, &media_id);                
                    if(!list_view->mark_count)
                    {
                       pls_sql_get_mark_count(db, list_view, local_param_ptr->index, &list_view->mark_count);
                    }
                    if(ret == SRV_PLST_OK)
                    {
                        ret = pls_sql_remove_item_from_list(db, list_view, plst_id, media_id);
                    }
                    if(ret == SRV_PLST_OK)
                    {
                        S32 ret_t;
                        ret_t = pls_sql_commit_transaction(db);                   
                        if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
                        {
                            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                            db->err_code = ret_t;
                        }
                        if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
                        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
                            ||playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
                        #endif
                            ) && playing_info->plst_id == list_view->list_cache[1].parent_id)
                        {
                            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
                            pls_sql_get_active_play_count_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_count);
                            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
                            playing_info->play_info.total_count = playing_info->total;
                        }
                    }
                    else
                    {
                        pls_sql_rollback_transaction(db);
                    }
                    pls_sql_exit_instance(db);
                    if(ret == SRV_PLST_RET_DELETE_ACTIVE)
                    {
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->index = (S32)local_param_ptr->index;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP, rsp_param_ptr);
                        return;
                    }  
                    else                        
                    {
                        base->error_code = ret;
                        list_cache->first_index = 0;
                        list_cache->last_index = 0;
                        list_cache->head = 0;
                        list_cache->tail = 0;
                        list_cache->total = 0;
                        list_cache->cache_num = 0;
                        memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
                        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
                        rsp_param_ptr->result = ret;
                        base->error_code = ret;
                        rsp_param_ptr->db_handle = db;
                        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
                    }

                    return;
                }
            }/* get plst_id OK */  
        }
    }
    else
    {
        rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
        rsp_param_ptr->result = SRV_PLST_RET_ERR_PARAM_ERR;
        base->error_code = SRV_PLST_RET_ERR_PARAM_ERR;
        rsp_param_ptr->db_handle = db;
        pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);
        return;
    }

    rsp_param_ptr = (pls_db_exec_rsp_struct*)construct_local_para(sizeof(pls_db_exec_rsp_struct),TD_CTRL);
    if(ret == SRV_PLST_OK)
    {
        rsp_param_ptr->result = SRV_PLST_OK;
        base->error_code = SRV_PLST_OK;
    }
    else
    {
        rsp_param_ptr->result = ret;
        base->error_code = ret;
    }
    rsp_param_ptr->db_handle = db;
    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_RSP, rsp_param_ptr);        
    return;
}


/******************************************************************
 * FUNCTION
 *    pls_db_set_list_as_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_set_list_as_active(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_set_active_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_view_type_enum view_type;
    srv_plst_active_list_enum active_type = SRV_PLST_ACTIVE_LIST_NONE;
    srv_plst_playing_context_struct *play_ptr;
    srv_plst_playing_context_struct playing_ori;
    U32 id;
    S32 index = 0;
    S32 ret = SRV_PLST_OK;
    MMI_BOOL update_db;
    MMI_BOOL use_current_playing_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_list_set_active_req_struct*) ilm_ptr->local_para_ptr;

    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    update_db = local_param_ptr->update_db;
    use_current_playing_list = local_param_ptr->use_current;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    /* Use current playing info to set active to database */
    if(use_current_playing_list)
    {
        pls_sql_enter_instance(db);
        pls_sql_begin_transaction(db);
        ret = pls_sql_set_active(db, play_ptr);
        if(ret == SRV_PLST_OK )
        {
            ret = pls_sql_commit_transaction(db);
            ret = SQLITE_OK;
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }
        else
        {
            pls_sql_rollback_transaction(db);
        }
        pls_sql_exit_instance(db);

        base->error_code = ret;
        PLS_SET_EVENT(PLS_DB_EVT_SET_ACTIVE);
        return ;  
    }

    /* Get playing info by index */
    view_type = list_view->view_type[list_view->current_index]; 
    memcpy(&playing_ori, play_ptr, sizeof(srv_plst_playing_context_struct));
    if(view_type == SRV_PLST_VIEW_PREFIX_SEARCH)
    {
        U8 i;
        if(list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_VIDEO)
        {
            play_ptr->active_type = SRV_PLST_ACTIVE_LIST_VIDEO;
        }
        else if(list_view->view_type[0] == SRV_PLST_VIEW_PLST)
        {
            play_ptr->active_type = SRV_PLST_ACTIVE_LIST_PLST;
        }
        else
        {
            play_ptr->active_type = SRV_PLST_ACTIVE_LIST_AUDIO;
        }
        pls_sql_enter_instance(db);
        pls_sql_begin_transaction(db);
        ret =  pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
        play_ptr->current_picked_id = list_view->list_cache[list_view->current_index].cache[index].id;
        for(i = 0; i < list_view->current_index; i ++)
        {
            play_ptr->play_info.view_type[i] = list_view->view_type[i];
            play_ptr->play_info.id[i] = list_view->list_cache[i+1].parent_id;
        }

        for(i = list_view->current_index; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
        {
            play_ptr->play_info.view_type[i] = SRV_PLST_VIEW_DUMMY;
            play_ptr->play_info.id[i] = 0;
        }
        play_ptr->play_info.current_index = list_view->current_index - 1;           
       
        if(list_view->view_type[list_view->current_index - 1] != SRV_PLST_VIEW_MEDIA &&
           list_view->view_type[list_view->current_index - 1] != SRV_PLST_VIEW_AUDIO &&
           list_view->view_type[list_view->current_index - 1] != SRV_PLST_VIEW_VIDEO)
        {
            play_ptr->plst_id = play_ptr->current_picked_id;
            play_ptr->play_info.id[list_view->current_index - 1] = play_ptr->plst_id;
            //bql: MAUI_02456326
            //sub index always is zero if in prefix search and play all of the album/artist...
            ret = pls_sql_util_get_media_id_by_index(db, list_view, local_param_ptr->index, 0 , &play_ptr->current_picked_id); 
            //ret = pls_sql_util_get_media_id_by_index(db, list_view, local_param_ptr->index, local_param_ptr->index , &play_ptr->current_picked_id); 
            play_ptr->pick_index = 0;
            ret = pls_sql_util_get_hint_count(db, list_view,local_param_ptr->index,&play_ptr->total);             
        }
        else
        {
            play_ptr->total = list_view->list_cache[list_view->current_index - 1].total;
            if(list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_AUDIO ||
                list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_VIDEO)
            {
                play_ptr->plst_id = play_ptr->current_picked_id;
            }
            else
            {
                play_ptr->plst_id = list_view->list_cache[list_view->current_index - 1].parent_id;
            }
            play_ptr->play_info.id[list_view->current_index - 1] = play_ptr->plst_id;
            ret = pls_sql_get_active_index_by_id(db, play_ptr, play_ptr->current_picked_id, &play_ptr->pick_index);
        }
        play_ptr->play_info.total_count = play_ptr->total;       
        play_ptr->play_info.is_mark = list_view->is_mark;
        play_ptr->play_info.is_mark_all = list_view->is_mark_all;
        play_ptr->play_info.is_unmark_all = list_view->is_unmark_all;
        if(ret == SRV_PLST_OK)
        {
            ret = pls_sql_set_active(db, play_ptr);
        }

        if(ret == SRV_PLST_OK)
        {
            play_ptr->pick_count = 1;
            play_ptr->played_count = 1;
            //bql: MAUI_02455633
            play_ptr->is_load = MMI_TRUE;
            ret = pls_sql_commit_transaction(db);
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }        
        }
        else
        {
            pls_sql_rollback_transaction(db);
            memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
        }
        pls_sql_exit_instance(db);
        base->error_code = ret;
        PLS_SET_EVENT(PLS_DB_EVT_SET_ACTIVE);
        return ;

    }
    else if(view_type == SRV_PLST_VIEW_PLST_DEFAULT || view_type == SRV_PLST_VIEW_PLST_ACTIVE)
    {
        if(play_ptr->is_load)
        {
            list_cache = &(list_view->list_cache[list_view->current_index]);
            if(play_ptr->play_info.view_type[0] == SRV_PLST_VIEW_PLST)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
                play_ptr->current_picked_id = list_cache->cache[index].id;
                if(ret == SRV_PLST_OK)
                {
                    ret = pls_sql_set_active(db, play_ptr);
                }
                if(ret == SRV_PLST_OK )
                {
                    play_ptr->total = list_view->total_count;
                    play_ptr->pick_index = local_param_ptr->index;
                    play_ptr->pick_count = 1;
                    play_ptr->played_count = 1;
                    ret = pls_sql_commit_transaction(db);
                    if(ret > SQLITE_OK && ret < SQLITE_ROW)
                    {
                        db->err_code = ret;
                        memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                        ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    }
                }
                else
                {
                    memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                    pls_sql_rollback_transaction(db);
                }
                pls_sql_exit_instance(db); 
                base->error_code = ret;
                PLS_SET_EVENT(PLS_DB_EVT_SET_ACTIVE);
                return ;
            }            
            else
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                ret =  pls_db_util_check_item_if_in_cache(list_view,local_param_ptr->index, &index);
                ret = pls_sql_get_media_id_from_cache(db, index, &play_ptr->current_picked_id);
                if(ret == SRV_PLST_OK)
                {
                    ret = pls_sql_set_active(db, play_ptr);
                }
                if(ret == SRV_PLST_OK )
                {
            	   play_ptr->pick_index = local_param_ptr->index;
                    play_ptr->total = list_view->total_count;
                    play_ptr->pick_count = 1;
                    play_ptr->played_count = 1;
                    ret = pls_sql_commit_transaction(db);
                    if(ret > SQLITE_OK && ret < SQLITE_ROW)
                    {
                        db->err_code = ret;
                        memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                        ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    }
                }
                else
                {
                    pls_sql_rollback_transaction(db);
                    memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                }
                pls_sql_exit_instance(db); 
                base->error_code = ret;
                PLS_SET_EVENT(PLS_DB_EVT_SET_ACTIVE);
                return ;
            }            
        }
        else 
        {
            
            ret = SRV_PLST_RET_ERR_UNKOWN_ERR;
        }
        
    }    
    else if(view_type == SRV_PLST_VIEW_IMAGE_FLOW)
    {
        active_type = SRV_PLST_ACTIVE_LIST_AUDIO;
    }
    else if(view_type == SRV_PLST_VIEW_AUDIO || view_type == SRV_PLST_VIEW_ARTIST ||
       view_type == SRV_PLST_VIEW_ALBUM || view_type == SRV_PLST_VIEW_GENRE)
    {
    #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        if (list_view->is_mark)
        {
            active_type = SRV_PLST_ACTIVE_LIST_TEMP_AUDIO;
        }
        else
    #endif
        {
            active_type = SRV_PLST_ACTIVE_LIST_AUDIO;
        }
    }
    else if(view_type == SRV_PLST_VIEW_PLST)
    {
    #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        if(list_view->is_mark)
        {
            active_type = SRV_PLST_ACTIVE_LIST_TEMP_PLST;
        }
        else
    #endif
        {
            active_type = SRV_PLST_ACTIVE_LIST_PLST;
        }
    }
    else if(view_type == SRV_PLST_VIEW_VIDEO)
    {
    #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        if (list_view->is_mark)
        {
            active_type = SRV_PLST_ACTIVE_LIST_TEMP_VIDEO;
        }
        else
    #endif
        {
            active_type = SRV_PLST_ACTIVE_LIST_VIDEO;
        }
    }
    else if(list_view->current_index)
    {
        srv_plst_view_type_enum view_type_t;
        view_type_t = list_view->view_type[list_view->current_index - 1];
        if(view_type == SRV_PLST_VIEW_MEDIA &&  view_type_t == SRV_PLST_VIEW_PLST)
        {
        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
            if(list_view->is_mark)
            {
                active_type = SRV_PLST_ACTIVE_LIST_TEMP_PLST;
            }
            else
        #endif
            {
                active_type = SRV_PLST_ACTIVE_LIST_PLST;                
            }
        }
        else if(view_type == SRV_PLST_VIEW_MEDIA   && 
               (view_type_t == SRV_PLST_VIEW_ALBUM ||
                view_type_t == SRV_PLST_VIEW_ARTIST||
                view_type_t == SRV_PLST_VIEW_GENRE ||
                view_type_t == SRV_PLST_VIEW_IMAGE_FLOW))
        {
        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
            if(list_view->is_mark)
            {
                active_type = SRV_PLST_ACTIVE_LIST_TEMP_AUDIO;
            }
            else
        #endif
            {
                active_type = SRV_PLST_ACTIVE_LIST_AUDIO;
            }
        }
    }
    else
    {
        active_type = SRV_PLST_ACTIVE_LIST_NONE;
    }

    if(active_type != SRV_PLST_ACTIVE_LIST_NONE)
    {  
        U8 i;

        play_ptr->is_load = MMI_TRUE;
        play_ptr->active_type = active_type;
        play_ptr->pick_count = 0;
        play_ptr->total = list_view->total_count;
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_IMAGE_FLOW)
        {
            play_ptr->play_info.view_type[0] = SRV_PLST_VIEW_ALBUM;
            for (i = 1; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
            {
                play_ptr->play_info.view_type[i] = SRV_PLST_VIEW_DUMMY;
            } 
        }
        else if(list_view->current_index && list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_MEDIA &&
            list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_IMAGE_FLOW)
        {
            play_ptr->play_info.view_type[0] = SRV_PLST_VIEW_ALBUM;
            play_ptr->play_info.view_type[1] = SRV_PLST_VIEW_MEDIA;
            for (i = 2; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
            {
                play_ptr->play_info.view_type[i] = SRV_PLST_VIEW_DUMMY;
            } 
        }
        else
        {
            for (i = 0; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
            {
                play_ptr->play_info.view_type[i] = list_view->view_type[i];
            } 
        }
        list_cache = &(list_view->list_cache[list_view->current_index]);
        if(view_type == SRV_PLST_VIEW_MEDIA || view_type == SRV_PLST_VIEW_AUDIO || view_type == SRV_PLST_VIEW_VIDEO ||
            (list_view->current_index && view_type == SRV_PLST_VIEW_PREFIX_SEARCH &&
            list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_MEDIA))
        {
            play_ptr->pick_index = local_param_ptr->index;
            play_ptr->current_picked_id = list_cache->parent_id;
            play_ptr->plst_id = list_cache->parent_id;
            play_ptr->total = list_view->total_count;
            // MAUI_02456001
            ret = pls_db_util_get_id(list_cache, local_param_ptr->index, &play_ptr->current_picked_id);
            if (ret != SRV_PLST_OK)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                ret = pls_sql_util_get_media_id_by_index(db, list_view, local_param_ptr->index, local_param_ptr->index , &play_ptr->current_picked_id);
                pls_sql_end_transaction(db);
                pls_sql_exit_instance(db); 
            }
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
        }
        else  /* get play id */
        {
            ret = pls_db_util_get_id(list_cache, local_param_ptr->index, &id);
            if(ret == SRV_PLST_OK)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                play_ptr->plst_id = id;
                ret = pls_sql_util_get_media_id_by_index(db,list_view, local_param_ptr->index, 0, &id);

                if(ret == SRV_PLST_OK)
                {
                    play_ptr->current_picked_id = id;
                    play_ptr->pick_index = 0;
                    ret = pls_sql_util_get_hint_count(db, list_view,local_param_ptr->index,&play_ptr->total);                    
                }
                pls_sql_end_transaction(db);
                pls_sql_exit_instance(db);
            }             
        }    

        if(ret == SRV_PLST_OK)
        {
            U8 temp;
            if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_IMAGE_FLOW)
            {
                play_ptr->play_info.view_type[0] = SRV_PLST_VIEW_ALBUM;
                play_ptr->play_info.id[0] = play_ptr->plst_id;
                for(temp = 1; temp < SRV_PLST_VIEW_LIST_DEPTH; temp++)
                {
                    play_ptr->play_info.view_type[temp] = SRV_PLST_VIEW_DUMMY;
                    play_ptr->play_info.id[temp] = list_view->list_cache[temp+1].parent_id;
                }
                play_ptr->play_info.current_index = 0;
            }
            else if(list_view->current_index && list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_MEDIA &&
                list_view->view_type[list_view->current_index - 1] == SRV_PLST_VIEW_IMAGE_FLOW)
            {
                play_ptr->play_info.view_type[0] = SRV_PLST_VIEW_ALBUM;
                play_ptr->play_info.view_type[1] = SRV_PLST_VIEW_MEDIA;
                play_ptr->play_info.id[0] = play_ptr->plst_id;
                for(temp = 2; temp < SRV_PLST_VIEW_LIST_DEPTH; temp++)
                {
                    play_ptr->play_info.view_type[temp] = SRV_PLST_VIEW_DUMMY;
                    play_ptr->play_info.id[temp] = list_view->list_cache[temp+1].parent_id;
                }
                play_ptr->play_info.current_index = 1;
            }
            else
            {
                for(temp = 0; temp < SRV_PLST_VIEW_LIST_DEPTH; temp++)
                {
                    play_ptr->play_info.view_type[temp] = list_view->view_type[temp];
                    play_ptr->play_info.id[temp] = list_view->list_cache[temp+1].parent_id;
                }
                play_ptr->play_info.id[list_view->current_index] = play_ptr->plst_id;
                play_ptr->play_info.view_type[list_view->current_index] = list_view->view_type[list_view->current_index];
                play_ptr->play_info.current_index = list_view->current_index;
            }
            play_ptr->play_info.total_count = play_ptr->total;       
            play_ptr->play_info.is_mark = list_view->is_mark;
            play_ptr->play_info.is_mark_all = list_view->is_mark_all;
            play_ptr->play_info.is_unmark_all = list_view->is_unmark_all;

            /* App will use play id to check if active list loaded, need to assign a value */
            if(play_ptr->plst_id == 0)
            {
                /* Do not use media ID here, it may be the same as default list ID (ex. Favorive 0x8001 same as first media id in phone */
                //play_ptr->plst_id = play_ptr->current_picked_id;
                play_ptr->plst_id = 0xFFFFFFFF;
            }
            play_ptr->ordinal = play_ptr->total; 

            if(update_db)
            {
                pls_sql_enter_instance(db);
                pls_sql_begin_transaction(db);
                ret = pls_sql_set_active(db, play_ptr);
                if(ret == SRV_PLST_OK )
                {
                    play_ptr->pick_count = 1;
                    play_ptr->played_count = 1;
                    ret = pls_sql_commit_transaction(db);
                    if(ret > SQLITE_OK && ret < SQLITE_ROW)
                    {
                        db->err_code = ret;
                        memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                        ret = SRV_PLST_RET_ERR_SQLITE_ERR;
                    }
                }
                else
                {
                    pls_sql_rollback_transaction(db);
                    memcpy(play_ptr, &playing_ori, sizeof(srv_plst_playing_context_struct));
                }
                pls_sql_exit_instance(db);
            }
            else
            {
                play_ptr->pick_count = 1;
                play_ptr->played_count = 1;
            }
        }        
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }

    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_SET_ACTIVE);
    return ;        
}


/******************************************************************
 * FUNCTION
 *    pls_db_list_bg_loading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_list_bg_loading(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_get_data_struct *local_param_ptr;
    pls_db_exec_get_data_struct *local_param_ptr2;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_db_context_struct *db;
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_get_data_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    list_cache = &(list_view->list_cache[list_view->current_index]);

    if(list_view->bg_loading)
    {  
        pls_sql_enter_instance(db);
        if(list_cache->head < list_cache->tail)
        {            
            pls_sql_enter_instance(db);
            pls_sql_get_item_to_fill_cache(db,list_cache->cache[list_cache->tail - 1].idx_in_list, 1,&index);
            pls_sql_exit_instance(db);
        }
        else if(list_cache->head < list_cache->tail)
        {
             pls_sql_enter_instance(db);
             pls_sql_get_item_to_fill_cache(db,list_cache->cache[list_cache->head].idx_in_list,-1,&index);
             pls_sql_exit_instance(db);
        }
        else
        {
            U32 index1, index2, index3,index4;
            index1 = list_cache->cache[list_cache->head].idx_in_list;

            if(!list_cache->tail)
            {
                index2 =  list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list;
            }
            else
            {
                index2 = list_cache->cache[list_cache->tail - 1].idx_in_list;
            }

            if(index1 > list_view->query_index)
            {
                index3 = index1 - list_view->query_index;
            }
            else
            {
                index3 = list_view->query_index - index1;
            }
            
            if(index2 > list_view->query_index)
            {
                index4 = index2 - list_view->query_index;
            }
            else
            {
                index4 = list_view->query_index - index2;
            }

            if(index3 < index4)
            {
                pls_sql_get_item_to_fill_cache(db,index1, 1,&index);
            }
            else
            {
                pls_sql_get_item_to_fill_cache(db,index2, 1,&index);
            }
            pls_sql_exit_instance(db);
        }
        local_param_ptr2 = (pls_db_exec_get_data_struct*)construct_local_para(sizeof(pls_db_exec_get_data_struct), TD_CTRL);
        local_param_ptr2->db_handle = db;
        pls_send_msg(MOD_PLS, MOD_PLS, MSG_ID_PLS_LIST_BG_LOADING_REQ, local_param_ptr2);
        kal_sleep_task(PLS_TASK_SLEEP_TIME);
    }
    return ;
}


/******************************************************************
 * FUNCTION
 *    pls_db_plst_item_reorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_plst_item_reorder(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;    
    srv_plst_playing_context_struct *playing_info;
    srv_plst_list_view_history_struct *list_view;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 

    pls_sql_enter_instance(db);
    if(base->config_reorder == SRV_PLST_PLST_REORDER_CONTINUE)
    {
    if(!db->enable_flag)
    {
        pls_sql_begin_transaction(db);
        db->enable_flag = MMI_TRUE;
    }   
    ret = pls_sql_plst_item_reorder(db, local_param_ptr->index, local_param_ptr->value);
    }
    else
    {
        playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info);
        list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
        pls_sql_begin_transaction(db);
        ret = pls_sql_plst_item_reorder(db, local_param_ptr->index, local_param_ptr->value);
        if(playing_info->is_load && playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST &&
            playing_info->plst_id == list_view->list_cache[1].parent_id)
        {
             pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
        }
        if(ret == SRV_PLST_OK)
        {
            ret = pls_sql_commit_transaction(db);
        }
        else
        {
            pls_sql_rollback_transaction(db);
        }
    }
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_REORDER_PLST);
    return ;     
}


/******************************************************************
 * FUNCTION
 *    pls_db_list_plst_reorder_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_list_plst_reorder_result(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;    
    srv_plst_list_view_history_struct *list_view_history;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    //kal_printf("\pls_db_list_plst_reorder_result \n");
    pls_sql_enter_instance(db);

    if(local_param_ptr->value == 1)
    {
        if( db->enable_flag)
        {
            ret = pls_sql_commit_transaction(db);
            if(ret > SQLITE_OK && ret < SQLITE_ROW)
            {
                db->err_code = ret;
                ret = SRV_PLST_RET_ERR_SQLITE_ERR;
            }
        }
        /* reorder active list, should reset the active index */
        if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
            #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
            || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
            #endif
            ) && (playing_info->plst_id == list_view_history->list_cache[1].parent_id))
        {
            pls_sql_get_active_index_by_id(db, playing_info, playing_info->current_picked_id, &playing_info->pick_index);
            pls_sql_get_default_list_count(db,playing_info, &playing_info->total);
            playing_info->play_info.total_count = playing_info->total;                           
        }
    }
    else if(local_param_ptr->value == 0)
    {
        list_cache = &(list_view_history->list_cache[list_view_history->current_index]);
        list_cache->first_index = 0;
        list_cache->last_index = 0;
        list_cache->head = 0;
        list_cache->tail = 0;
        list_cache->cache_num = 0;
        memset(&(list_cache->cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));

        if (db->enable_flag)
        {
            pls_sql_rollback_transaction(db);
        }
    }
    db->enable_flag = MMI_FALSE;
    pls_sql_exit_instance(db);
   
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_REORDER_RET);
    return ;
}



/******************************************************************
 * FUNCTION
 *    pls_db_load_active_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_load_active_info(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_load_active_info(db, local_param_ptr->ret_value);
    pls_sql_end_transaction(db);
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_LOAD_ACTIVE_INO);
    return;
}


/******************************************************************
 * FUNCTION
 *    pls_db_plst_get_playing_media
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_plst_get_playing_media(ilm_struct* ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_item_get_play_req_struct *local_param_ptr;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db;
    srv_plst_playing_context_struct *playing_info; 
    srv_plst_list_view_history_struct *list_view;
    srv_plst_playing_context_struct playing_ori;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_list_item_get_play_req_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    
    memcpy(&playing_ori, playing_info, sizeof(srv_plst_playing_context_struct));

    MMI_TRACE(TRACE_GROUP_1,MMI_PLS_PLST_GET_PLAYING_INFO,playing_info->is_load,local_param_ptr->get_type, base->shuffle, base->repeat);
    if (db->db_opened == MMI_FALSE)
	{
       ret = SRV_PLST_RET_ERR_PARAM_ERR;
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_ACTIVE);
    return;     
	}
    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    if(local_param_ptr->get_type == SRV_PLST_GET_ACTIVE_CURR)
    {
        ret = pls_sql_get_current_active_id(db, playing_info, &playing_info->current_picked_id);
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ACTIVE_NEXT)
    {
        ret = pls_sql_get_next_active_id(db, playing_info, &playing_info->current_picked_id);        
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ACTIVE_PREV)
    {
        ret = pls_sql_get_prev_active_id(db, playing_info, &playing_info->current_picked_id); 
    }
    else if(local_param_ptr->get_type == SRV_PLST_GET_ACTIVE_AUTO)
    {
        ret = pls_sql_get_auto_active_id(db, playing_info, &playing_info->current_picked_id);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    playing_info->pick_no_played = MMI_FALSE;
    if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_EMPTY)
    {
        S32 ret_t;
// MAUI_02968266
        if (ret == SRV_PLST_OK && 
            local_param_ptr->get_type != SRV_PLST_GET_ACTIVE_CURR &&
            base->config_store_play_info == SRV_PLST_PLAY_INFO_STORE )
        {
            ret_t = pls_sql_udpate_active_info_after_change_index(db, playing_info);
            if (ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
            {
                MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            }
        }
        
        ret_t = pls_sql_commit_transaction(db);
        if(ret_t > SQLITE_OK && ret_t < SQLITE_ROW)
        {
            db->err_code = ret_t;
            memcpy(playing_info, &playing_ori, sizeof(srv_plst_playing_context_struct));        
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
        else
        {
            *(U32*)(local_param_ptr->id) = playing_info->current_picked_id;
        }
    }
    else
    {
        pls_sql_rollback_transaction(db);
        memcpy(playing_info, &playing_ori, sizeof(srv_plst_playing_context_struct));        
    }

    if(ret == SRV_PLST_OK || ret == SRV_PLST_RET_EMPTY)
    {
        S32 ret_t;
        if(local_param_ptr->path)
        {
            ret_t = pls_sql_get_active_media_path_by_id(db, playing_info, playing_info->active_type, playing_info->current_picked_id, (UI_string_type)local_param_ptr->path, ((U32*)(local_param_ptr->id)));        
        }  
        else
        {
            ret_t = pls_sql_get_active_media_path_by_id(db, playing_info, playing_info->active_type, playing_info->current_picked_id, NULL, ((U32*)(local_param_ptr->id)));   
        }
        if(ret_t != SRV_PLST_OK)
        {
             ret = ret_t;
        }
    }

    pls_sql_exit_instance(db);

#ifdef __PLST_SRV_DEFAULT_LIST__
    if(list_view->view_type[0] == SRV_PLST_VIEW_PLST_DEFAULT)
    {
        list_view->first_view_media_id[list_view->current_index] = *(U32*)(local_param_ptr->id);
    }
#endif /* __PLST_SRV_DEFAULT_LIST__ */

    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_GET_ACTIVE);
    return;     
}


/******************************************************************
 * FUNCTION
 *    pls_db_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_list_entry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_entry_list_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_entry_list_req_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 

    base->error_code = SRV_PLST_OK;
    PLS_SET_EVENT(PLS_DB_EVT_ENTRY_LIST);
    return;   
}


/******************************************************************
 * FUNCTION
 *    pls_db_list_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_list_exit(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_exit_list_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_exit_list_req_struct*) ilm_ptr->local_para_ptr;
    db = (srv_plst_db_context_struct*)local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 

    base->error_code = SRV_PLST_OK;
    PLS_SET_EVENT(PLS_DB_EVT_EXIT_LIST);
    return;
}

#ifdef __PLST_SRV_FEATURE_MOST_RECENT_LIST__
/******************************************************************
 * FUNCTION
 *    pls_db_update_media_playing_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_update_media_playing_info(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_update_play_info_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_playing_context_struct *playing_info;
    srv_plst_base_info_struct *base;  
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_update_play_info_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    /*
    if(playing_info->active_type == SRV_PLST_ACTIVE_LIST_VIDEO ||
        playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_VIDEO ||
        playing_info->acitve_type == SRV_PLST_ACTIVE_LIST_NONE)
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    else 
    */
    {
        pls_sql_enter_instance(db);
        pls_sql_begin_transaction(db);
        ret = pls_sql_update_media_playing_info(db, playing_info, local_param_ptr->id); 
        if(ret == SRV_PLST_OK)
        {
            pls_sql_commit_transaction(db);
        }
        else
        {
            pls_sql_rollback_transaction(db);
        }
        pls_sql_exit_instance(db);
    }
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_UPDATE_PLAY_INFO);
    return;
}
#endif /*__PLST_SRV_FEATURE_MOST_RECENT_LIST__*/

/******************************************************************
 * FUNCTION
 *    pls_db_list_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr         [IN]   
 * RETURNS
 *  void
 ******************************************************************/
static void pls_db_list_play_config_reset(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_playing_context_struct *play_ptr;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    pls_sql_enter_instance(db);
    pls_sql_begin_transaction(db);
    ret = pls_sql_play_config_reset(db, play_ptr);
    if(ret == SRV_PLST_OK)
    {
        ret = pls_sql_commit_transaction(db);
        if(ret > SQLITE_OK && ret < SQLITE_ROW)
        {
            db->err_code = ret;
            ret = SRV_PLST_RET_ERR_SQLITE_ERR;
        }
    }
    else
    {
        pls_sql_rollback_transaction(db);
    }
    pls_sql_exit_instance(db);
    base->error_code = ret ;
    PLS_SET_EVENT(PLS_DB_EVT_PLAY_CONFIG_RST);
    return;    
}

static void pls_db_store_active_info(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    pls_db_exec_single_db_req_struct* local_param_ptr1;
    srv_plst_db_context_struct *db;   
    srv_plst_playing_context_struct *play_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_single_db_req_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    pls_sql_enter_instance(db);
    pls_sql_udpate_active_info_after_change_index(db, play_ptr);
    pls_sql_exit_instance(db);
    
    local_param_ptr1 = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr1->db_handle = db;
    
    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_STORE_ACTIVE_INFO_RSP, local_param_ptr1);                
    return;
}


static void pls_db_udpate_active_index(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_active_idx_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_playing_context_struct *play_ptr;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_get_active_idx_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    pls_sql_enter_instance(db);
    if(local_param_ptr->type == SRV_PLST_ACTIVE_MEDIA)
    {
        ret = pls_sql_get_active_index_by_id(db, play_ptr, play_ptr->current_picked_id, local_param_ptr->index);
        play_ptr->pick_index = *(local_param_ptr->index);
    }
    else if(local_param_ptr->type == SRV_PLST_ACTIVE_ALBUM)
    {
        if(play_ptr->active_type != SRV_PLST_ACTIVE_LIST_VIDEO)
        {
            ret = pls_sql_get_active_idx(db, play_ptr, play_ptr->current_picked_id, local_param_ptr->type, local_param_ptr->index);
        }
        else
        {
            ret = 0;
            *(local_param_ptr->index) = 0;
        }
    }
    pls_sql_exit_instance(db);

    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_UPDATE_ACT_INDX);
    return;
}

static void pls_db_check_active_media_in_def_plst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_playing_context_struct *play_ptr;
    S32 ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_act_media_op_plst_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 

    pls_sql_enter_instance(db);
    ret = pls_sql_active_media_check_if_in_defplst(db, play_ptr, local_param_ptr->type);
    pls_sql_exit_instance(db);

    base->error_code = (S32)ret;
    PLS_SET_EVENT(PLS_DB_EVT_CHECK_IN_PLST);
    return;    
}

static void pls_db_active_media_remove_from_defplst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_playing_context_struct *play_ptr;
    S32 ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_act_media_op_plst_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    
    pls_sql_enter_instance(db);
    ret = pls_sql_active_media_add_or_remove_from_defplst(db, play_ptr, MMI_FALSE, local_param_ptr->type);
    pls_sql_exit_instance(db);

    base->error_code = (S32)ret;
    PLS_SET_EVENT(PLS_DB_EVT_ACT_MED_AR_PLST);
    return;    
}


static void pls_db_active_media_add_to_defplst(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_playing_context_struct *play_ptr;
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_act_media_op_plst_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    play_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->playing_info); 
    
    pls_sql_enter_instance(db);
    ret = (MMI_BOOL)pls_sql_active_media_add_or_remove_from_defplst(db, play_ptr, MMI_TRUE, local_param_ptr->type);
    pls_sql_exit_instance(db);

    base->error_code = (S32)ret;
    PLS_SET_EVENT(PLS_DB_EVT_ACT_MED_AR_PLST);
    return;    
}


static void pls_db_check_plst_is_exist(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_check_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_check_plst_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    
    pls_sql_enter_instance(db);
    ret = pls_sql_check_plst_is_exist(db, local_param_ptr->name);
    pls_sql_exit_instance(db);

    base->error_code = (S32)ret;
    PLS_SET_EVENT(PLS_DB_EVT_CHECK_PLST_EXIST);
    return; 
}

#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
static void pls_db_list_jump(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_list_jump_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_list_jump_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 
    
    pls_sql_enter_instance(db);
    ret = (MMI_BOOL)pls_sql_list_jump(db, local_param_ptr->jump_info, local_param_ptr->ret_value);
    pls_sql_exit_instance(db);

    base->error_code = (S32)ret;
    PLS_SET_EVENT(PLS_DB_EVT_LIST_JUMP);
    return; 
}


static void pls_db_list_get_group_data(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_group_data_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_list_view_history_struct *list_view;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_get_group_data_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 

    pls_sql_enter_instance(db);
    ret = pls_sql_get_group_count(db, list_view, local_param_ptr->data);
    pls_sql_exit_instance(db);
    base->error_code = ret;
    PLS_SET_EVENT(PLS_DB_EVT_LIST_GROUP_DATA);
    return;
}
#endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */

static void pls_db_list_search(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_get_data_struct* local_param_ptr;
    pls_db_search_data_struct* local_param_ptr2;
    srv_plst_db_context_struct *db;   
    srv_plst_base_info_struct *base; 
    srv_plst_list_view_history_struct *list_view;
    U32 count = 0;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr =  (pls_db_exec_get_data_struct*) ilm_ptr->local_para_ptr;
    db = local_param_ptr->db_handle;
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->list_view_history);
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)(db->srv_hdr))->base_info); 

    pls_sql_enter_instance(db);
    ret = pls_sql_search_count(db, list_view, &count);
    
    pls_sql_exit_instance(db);
    base->error_code = ret;
    if(ret == SRV_PLST_OK)
    {
        list_view->total_count = count;
        list_view->list_cache[list_view->current_index].total = count;
    }
    local_param_ptr2 = (pls_db_search_data_struct*)construct_local_para(sizeof(pls_db_search_data_struct), TD_CTRL);

    local_param_ptr2->db_handle = db;
    local_param_ptr2->count = count;
    local_param_ptr2->ret = ret;
   
    pls_send_msg(MOD_PLS, MOD_MMI, MSG_ID_PLS_LIST_SEARCH_RSP, local_param_ptr2);                
    return;
}

/*****************************************************************************
 * FUNCTION
 *  pls_db_msg_handler
 * DESCRIPTION
 *  player list service message handler
 * PARAMETERS
 *  *ilm_ptr    [IN]    MSG pointer
 * RETURNS
 *  void
 *****************************************************************************/
void pls_db_msg_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_PLS_DB_INIT_REQ:
            pls_db_init(ilm_ptr); 
            break;
               
        case MSG_ID_PLS_DB_DEINIT_REQ:
            pls_db_deinit(ilm_ptr);
            break;
               
        case MSG_ID_PLS_LIBRARY_OPEN_REQ :
            pls_db_open_lib(ilm_ptr);
            break;
               
        case MSG_ID_PLS_LIBRARY_OPEN_STOP_REQ:
            pls_db_stop_open_lib(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIBRARY_CLOSE_REQ:
            pls_db_close_lib(ilm_ptr);              
            break;
               
        case MSG_ID_PLS_CREATE_TABLE_REQ:
            pls_db_create_table(ilm_ptr); 
            break;
               
        case MSG_ID_PLS_READ_VERSION_REQ:
            pls_db_read_version(ilm_ptr);
            break;
               
        case MSG_ID_PLS_LIBRARY_UPDATE_REQ:
        case MSG_ID_PLS_LIBRARY_UPDATE_RESUME_REQ:
            pls_db_lib_update_gen_internal(ilm_ptr);
            break;               
               
        case MSG_ID_PLS_LIBRARY_STOP_UPDATE_REQ:
            pls_db_stop_lib_update_gen(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_GET_DATA_REQ:
            pls_db_get_show_data(ilm_ptr);
            break;
               
        case MSG_ID_PLS_PLST_CREATE_REQ:  
            pls_db_create_plst(ilm_ptr);
            break;

        case MSG_ID_PLS_PLST_GET_PLST_INDEX_REQ:  
            pls_db_get_plst_index(ilm_ptr);
            break;

        case MSG_ID_PLS_PLST_DELETE_REQ:
            pls_db_delete_media_item(ilm_ptr);
            break;

        case MSG_ID_PLS_PLST_RENAME_REQ:
            pls_db_rename_plst(ilm_ptr);
            break;
            
        case MSG_ID_PLS_CREATE_MARK_TBL_REQ:
            pls_db_create_mark_tbl(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_MARK_REQ:
            pls_db_set_mark_item(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_GET_MARK_REQ:
            pls_db_get_item_mark_flag(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_ITEM_DELETE_REQ:
            pls_db_delete_media_item(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_ITEM_REMOVE_REQ:
            pls_db_remove_media_item(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_ITEM_ADD_REQ:
            pls_db_add_media_to_plst(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_SET_ACTIVE_REQ:
            pls_db_set_list_as_active(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_BG_LOADING_REQ:
            pls_db_list_bg_loading(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_LOAD_ACTIVE_REQ: 
            pls_db_load_active_info(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_GET_ID_REQ:
            pls_db_get_id(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_GET_DETAILS_REQ:            
        case MSG_ID_PLS_LIST_UPDATE_DETAILS_REQ:
            pls_db_get_show_data(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_ORIGANIZATION_REQ:
            pls_db_plst_item_reorder(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_ITEM_GET_PLAY_REQ:
            pls_db_plst_get_playing_media(ilm_ptr);
            break;
            
        case MSG_ID_PLS_ENTRY_LIST_REQ:
            pls_db_list_entry(ilm_ptr);
            break;

        case MSG_ID_PLS_EXIT_LIST_REQ:
            pls_db_list_exit(ilm_ptr);
            break;
            
        case MSG_ID_PLS_PLAY_CONFIG_RESET_REQ:
            pls_db_list_play_config_reset(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_ORIGANIZATION_RESULT_REQ:
            pls_db_list_plst_reorder_result(ilm_ptr);
            break;
       
        case MSG_ID_PLS_LIST_ITEM_DELETE_STOP_REQ:
            pls_db_stop_delete_media_item(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_ITEM_REMOVE_STOP_REQ:
        case MSG_ID_PLS_PLST_DELETE_STOP_REQ:
            pls_db_stop_remove_media_item(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_ITEM_ADD_STOP_REQ:
            pls_db_stop_add_media_to_plst(ilm_ptr);
            break;
            
        case MSG_ID_PLS_LIST_GET_DATA_STOP_REQ:
            pls_db_stop_get_show_data(ilm_ptr);
            break;
        case MSG_ID_PLS_LIST_STOP_UPDATE_ARTWORK_REQ:
            pls_db_stop_update_artwork(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_GET_CNTX_REQ:
            pls_db_get_cntx_by_id(ilm_ptr);
            break;

    #ifdef __PLST_SRV_FEATURE_MOST_RECENT_LIST__
        case MSG_ID_PLS_LIST_UPADTE_PLAYING_INFO_REQ:
            pls_db_update_media_playing_info(ilm_ptr);
            break;
    #endif /*__PLST_SRV_FEATURE_MOST_RECENT_LIST__*/
    
        case MSG_ID_PLS_LIST_UPDATE_ACTIVE_INDEX_REQ:
            pls_db_udpate_active_index(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_STORE_ACTIVE_INFO_REQ:
            pls_db_store_active_info(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_CHECK_ACTIVE_IN_DEFPLST:
            pls_db_check_active_media_in_def_plst(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_ACT_MEDIA_ADD_TO_DEFPLST:
             pls_db_active_media_add_to_defplst(ilm_ptr);
            break;

        case MSG_ID_PLS_LIST_ACT_MEDIA_REMOVE_FROM_DEFPLST:
           pls_db_active_media_remove_from_defplst(ilm_ptr);
            break;
        case MSG_ID_PLS_LIST_CHECK_PLST_EXIST:
            pls_db_check_plst_is_exist(ilm_ptr);
            break;

    #ifdef __PLST_SRV_FEATURE_GROUP_LIST__
        case MSG_ID_PLS_LIST_LIST_JUMP_REQ:
            pls_db_list_jump(ilm_ptr);
            break;
        case MSG_ID_PLS_LIST_GROUP_LIST_COUNT_REQ:
            pls_db_list_get_group_data(ilm_ptr);
            break;
    #endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */

        case MSG_ID_PLS_LIST_SEARCH_REQ:
            pls_db_list_search(ilm_ptr);
            break;
        default:
            break;
    }
}


#define __LIST_SERVICE_MMI_PART__
/******************************************************************
 * FUNCTION
 *  srv_plst_pls_get_data_rsp_hdler
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_get_data_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_get_data_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_GET_DATA_RSP, pls_db_get_data_rsp_ptr->result);   
    
    // In cosmos MMv2, if the heap memory is freed, it will cause error when access it.
    // So check if there's any valid handle before access it
    if(g_srv_plst_control_ptr->number == 0)
    {
        return;
    }
    
    handler = pls_db_get_data_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }       
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(handler != base->srv_handle)
    {
        return;
    }
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);

    if (base->callback != NULL && 
        !list_view->is_get_data_cancel &&
        pls_db_get_data_rsp_ptr->id == g_srv_plst_query_album_id)
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_GET_IMAGE, pls_db_get_data_rsp_ptr->result, pls_db_get_data_rsp_ptr->index);
    }
}

/******************************************************************
 * FUNCTION
 *  srv_plst_pls_update_artwork_rsp_hdler
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_update_artwork_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_get_data_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_GET_DATA_RSP, pls_db_get_data_rsp_ptr->result);   

    handler = pls_db_get_data_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);

    if (base->callback != NULL && !list_view->is_stop_update_artwork)
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_UPDATE_ARTWORK, pls_db_get_data_rsp_ptr->result, pls_db_get_data_rsp_ptr->index);
    }
    list_view->is_stop_update_artwork = MMI_FALSE;
}

/******************************************************************
 * FUNCTION
 *  srv_plst_pls_add_item_plst_rsp_hdler
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_add_item_plst_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_add_item_plst_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_ADD_ITEM_TO_PLST_RSP,  pls_db_add_item_plst_rsp_ptr->result);   

    handler = pls_db_add_item_plst_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);
    if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
    {
        memset(&(list_view->list_cache[1].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[1].last_index = 0;
        list_view->list_cache[1].first_index = 0;
        list_view->list_cache[1].head = 0;
        list_view->list_cache[1].tail = 0;
        list_view->list_cache[1].cache_num = 0;
        list_view->query_index = 0;
    }
    if (base->callback != NULL && !list_view->is_add_cancel)
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_ADD_TO_PLST, pls_db_add_item_plst_rsp_ptr->result, 0);
    }
}


void srv_plst_pls_add_item_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_ar_media_struct* pls_db_add_ind_ptr = (pls_db_act_ar_media_struct*)msg;
    pls_db_exec_single_db_req_struct* local_param_ptr;
    U32 handler;
    srv_plst_base_info_struct *base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_DELETE_ACTIVE_ITEM_RSP, pls_db_delete_ind_ptr->result, __LINE__);      
    handler = pls_db_add_ind_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    if (base->callback != NULL)
    {
       (MMI_BOOL)(base->callback)(base->user_data, SRV_PLST_CB_EVT_ADD_PROGRESS, SRV_PLST_OK, pls_db_add_ind_ptr->progress);
    }
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = pls_db_add_ind_ptr->db_handle;
    local_param_ptr->index = pls_db_add_ind_ptr->index;
    local_param_ptr->value = pls_db_add_ind_ptr->value;
    local_param_ptr->callback = base->callback;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_ADD_REQ, local_param_ptr);
  
}

/******************************************************************
 * FUNCTION
 *  srv_plst_pls_open_lib_rsp_hdler
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_open_lib_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_rsp_struct* pls_db_open_lib_rsp_ptr = (pls_db_start_rsp_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_OPEN_LIB_RSP, pls_db_open_lib_rsp_ptr->result);   

    // In cosmos MMv2, if the heap memory is freed, it will cause error when access it.
    // So check if there's any valid handle before access it
    if(g_srv_plst_control_ptr->number == 0)
    {
        return;
    }

    handler = pls_db_open_lib_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    if(base->is_open_cancel)
    {
        return;
    } 
    if (base->callback != NULL)
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_OPEN, pls_db_open_lib_rsp_ptr->result, 0);
    }
}


/******************************************************************
 * FUNCTION
 *  srv_plst_pls_lib_continue_rsp_hdr
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_lib_continue_rsp_hdr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct *rsp_param_ptr = (pls_db_gen_lib_req_struct*)msg;
    pls_db_gen_lib_req_struct *local_param_ptr1;
    srv_plst_gen_lib_context_struct *gen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    // In cosmos MMv2, if the heap memory is freed, it will cause error when access it.
    // So check if there's any valid handle before access rsp_param_ptr->db_handle->srv_hdr
    if(g_srv_plst_control_ptr->number == 0)
    {
        return;
    }

    if(!pls_db_util_check_handler_valid(rsp_param_ptr->db_handle->srv_hdr))
    {      
        return;
    }    
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(rsp_param_ptr->db_handle->srv_hdr))->gen);
    if(gen->run_type == SRV_PLST_GEN_NONE)
    {
        return;
    }
    local_param_ptr1 = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
    local_param_ptr1->db_handle = rsp_param_ptr->db_handle;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_UPDATE_RESUME_REQ, local_param_ptr1);
    return;
}


/******************************************************************
 * FUNCTION
 *  srv_plst_pls_update_lib_rsp_hdler
 * DESCRIPTION
 *   service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_update_lib_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_exec_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    U32 handler;
    U32 count = 0;
    srv_plst_base_info_struct *base;
    srv_plst_gen_lib_context_struct *gen;
	srv_plst_list_view_history_struct *list_view;
    MMI_BOOL is_continue = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_UPATE_LIB_RSP, pls_db_exec_rsp_ptr->result, count);   
    handler = pls_db_exec_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)handler)->gen);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);

    if(gen->cancel_gen)
    {
        if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
        }
    }
    
    if(pls_db_exec_rsp_ptr->result == SRV_PLST_RET_DELETE_ACTIVE)
    {
        is_continue = (MMI_BOOL)(base->callback)(base->user_data, SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA, SRV_PLST_OK, 0);
    }
    if(is_continue)
    {
        pls_db_gen_lib_req_struct *local_param_ptr1;
        local_param_ptr1 = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);
        local_param_ptr1->db_handle = pls_db_exec_rsp_ptr->db_handle;
        if(gen->cancel_gen)
        {
            free_local_para((local_para_struct*)local_param_ptr1);
        }
        else
        {
            pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_UPDATE_RESUME_REQ, local_param_ptr1);
        }
        return;
    }
    base->is_refresh = MMI_FALSE;

    if(pls_db_exec_rsp_ptr->db_handle->enable_flag)
    {
        pls_sql_enter_instance(pls_db_exec_rsp_ptr->db_handle);
        pls_sql_rollback_transaction(pls_db_exec_rsp_ptr->db_handle);
        pls_sql_exit_instance(pls_db_exec_rsp_ptr->db_handle);
    } 
    if(list_view->current_index == 0 && (list_view->view_type[0] == SRV_PLST_VIEW_AUDIO ||
          list_view->view_type[0]== SRV_PLST_VIEW_VIDEO || list_view->view_type[0] == SRV_PLST_VIEW_ARTIST ||
          list_view->view_type[0] == SRV_PLST_VIEW_ALBUM))
    {
        memset(&(list_view->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[0].last_index = 0;
        list_view->list_cache[0].first_index = 0;
        list_view->list_cache[0].head = 0;
        list_view->list_cache[0].tail = 0;
        list_view->list_cache[0].cache_num = 0;
        list_view->list_cache[0].total = 0;  /* Need update again after refresh */
        list_view->query_index = 0;
    }

    if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
    {
        FS_FindClose(gen->search_handle);
        gen->search_handle = FS_INVALID_FILE_HANDLE;
    }
    count = gen->update_num;
    gen->run_type = SRV_PLST_GEN_NONE;
    if(gen->cancel_gen)
    {
        return;
    }   
        
    if (base->callback != NULL)
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_UPDATE, pls_db_exec_rsp_ptr->result, count);
    }
}


/******************************************************************
 * FUNCTION
 *  srv_plst_pls_delete_item_plst_rsp_hdler
 * DESCRIPTION
 *  service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_delete_item_plst_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_exec_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    U32 handler;
    U32 count = 0;
    S32 ret= SRV_PLST_OK;
    U16 i, j;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_playing_context_struct *play_info;
    srv_plst_list_context_struct *list_cache;
    U32 view_count = 0; /* used for restoring view count before prefix_search */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_DELETE_ITEM_RSP, pls_db_exec_rsp_ptr->result);      
    handler = pls_db_exec_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)handler)->playing_info);

    if(list_view->is_delete_cancel)
    {
        return;
    }

    /* Keep current level count before item deleted */
    if (list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH)
    {
        view_count = list_view->list_cache[list_view->current_index].total;
    }

    /* Get current level item count */
    ret = srv_plst_pls_get_show_data(base, list_view,SRV_PLST_GET_COUNT, 0,&count);

    /* Count parent level count after deleted */
    if (list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH)
    {
        /* Parent level count - (current level count before delete - current level count after delete)*/
        view_count = list_view->list_cache[list_view->current_index - 1].total - (view_count - count);
    }

    if(ret != SRV_PLST_OK)
    {
        count = 0;
    }

    if(count == 0)
    {
        if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
        {
            i = 1;
        }
        else
        {
            i = 0;
        }
    }
    else
    {
        if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
        {
            i = 1;
        }
        else if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH)
        {
            i = list_view->current_index - 1;
        }
        else
        {
            i = list_view->current_index;
        }
    }
    
    for(; i <= list_view->current_index; i++)
    {
        list_cache = &(list_view->list_cache[i]);

    #ifdef __COSMOS_MMI_PACKAGE__
        /* DO NOT clear all cache for prefix search, it can delete one item only at a time, so just delete its cache */
        if((count > 0) && list_view->view_type[i] == SRV_PLST_VIEW_PREFIX_SEARCH)
        {
            /* Find deleted cache item */
            for(j = 0 ; j < SRV_PLST_VIEW_LIST_CACHE ; j++)
            {
                if(list_cache->cache[j].idx_in_list == list_view->query_index)
                {
                    break;
                }
            }

            /* Remove deleted cache item */
            if(j <= list_cache->tail)
            {
                for(; j < list_cache->tail-1 ; j++)
                {
                    list_cache->cache[j] = list_cache->cache[j+1];
                    list_cache->cache[j].idx_in_list--;
                }
                list_cache->cache[j].id = 0;
                list_cache->cache[j].idx_in_list = 0;
            }
            else
            {
                /* From J to END */
                for(; j < SRV_PLST_VIEW_LIST_CACHE - 1 ; j++)
                {
                    list_cache->cache[j] = list_cache->cache[j+1];
                    list_cache->cache[j].idx_in_list--;
                }
                list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1] = list_cache->cache[0];
                list_cache->cache[SRV_PLST_VIEW_LIST_CACHE - 1].idx_in_list--;

                /* From 0 to tail */
                if(list_cache->tail > 0)
                {
                    for(j = 0; j < list_cache->tail-1 ; j++)
                    {
                        list_cache->cache[j] = list_cache->cache[j+1];
                        list_cache->cache[j].idx_in_list--;
                    }
                }

                list_cache->cache[j].id = 0;
                list_cache->cache[j].idx_in_list = 0;
            }

            /* Update count and tail */
            list_view->total_count--;

            list_cache->total--;
            list_cache->cache_num--;

            if(list_cache->tail == 0)
            {
                list_cache->tail = SRV_PLST_VIEW_LIST_CACHE - 1;
            }
            else
            {
                list_cache->tail --;
            }

        }
        else
    #endif /* __COSMOS_MMI_PACKAGE__ */
        {
            list_cache->first_index = 0;
            list_cache->last_index = 0;
            list_cache->head = 0;
            list_cache->tail = 0;
            list_cache->total = 0;
            list_cache->cache_num = 0;
            memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
        }
    }

    if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE &&
        !(play_info->active_type == SRV_PLST_ACTIVE_LIST_PLST && list_view->view_type[0] != SRV_PLST_VIEW_PLST))
    {
        if(list_view->view_type[0] != SRV_PLST_VIEW_PLST)
        {
            i = 0;
        }
        else
        {
            i = 1;
        }
        for(; i < list_view->current_index; i++)
        {
            list_cache = &(list_view->list_cache[i]);
            list_cache->first_index = 0;
            list_cache->last_index = 0;
            list_cache->head = 0;
            list_cache->tail = 0;
            list_cache->total = 0;
            list_cache->cache_num = 0;
            memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
        }        
    }

    /* Set parent level item count back into cache. (It will clear in above section) */
    if (list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH)
    {
        list_view->list_cache[list_view->current_index - 1].total = view_count;
    }

    if (base->callback != NULL )
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_DELETE_LIST, pls_db_exec_rsp_ptr->result, count);
    }
}


/******************************************************************
 * FUNCTION
 *  srv_plst_pls_delete_active_item_plst_rsp_hdler
 * DESCRIPTION
 *  service playlist request response handler
 * PARAMETERS
 *  *msg    [IN]    msg pointer
 * RETURNS
 *  void
 ******************************************************************/
void srv_plst_pls_delete_active_item_plst_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_rsp_struct* pls_db_exec_rsp_ptr = (pls_db_exec_rsp_struct*)msg;
    pls_db_exec_single_db_req_struct* local_param_ptr;
    U32 handler;
    MMI_BOOL is_del_continue = MMI_FALSE;
    srv_plst_base_info_struct *base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_playing_context_struct *play_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_DELETE_ACTIVE_ITEM_RSP, pls_db_exec_rsp_ptr->result, __LINE__);      
    handler = pls_db_exec_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
//bql: MAUI_02999979
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)handler)->playing_info);
    if(base->srv_handle != handler)
    {
        return;
    }
        
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);

    if (base->callback != NULL)
    {
        is_del_continue = (MMI_BOOL)(base->callback)(base->user_data, SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA, SRV_PLST_OK, 0);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_DELETE_ACTIVE_ITEM_RSP, is_del_continue,__LINE__);      

    if(is_del_continue)
    {
        local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
        local_param_ptr->db_handle = pls_db_exec_rsp_ptr->db_handle;
        local_param_ptr->index = pls_db_exec_rsp_ptr->index;
        local_param_ptr->callback = base->callback;
//bql: MAUI_02999979
//Error logic for remove/delete request.
//Add more condition for view_plst_active with list_plst active type
        if ((list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA) ||
			(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE && play_info->active_type == SRV_PLST_ACTIVE_LIST_PLST))
        {
            pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr);
        }
        else
        {
            pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, local_param_ptr);
        }
        SetProtocolEventHandler(srv_plst_pls_delete_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_RSP);
        SetProtocolEventHandler(srv_plst_pls_delete_active_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP);          
    }
    else
    {
        S32 ret = SRV_PLST_OK;
        U32 count = 0;
        U16 i = 0;        
        srv_plst_list_context_struct *list_cache;
        
        list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)handler)->list_view_history);
        play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)handler)->playing_info);
        
        if(list_view->is_delete_cancel)
        {
            return;
        }

        // MAUI_02931688
        //  need always skip to clear cache if forbiden to delete current playing item.
        // MAUI_03100658
        //  if multiple delete and already some item has been deleted, clear cache and reload to avoid data incorrect
        if (!is_del_continue && list_view->prog_count == 0)
        {
            return;
        }

        ret = srv_plst_pls_get_show_data(base, list_view,SRV_PLST_GET_COUNT, 0,&count);
        if(ret != SRV_PLST_OK)
        {
            count = 0;
        }
        
        if(!count)
        {
            if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
            {
                i = 1;
            }
            else
            {
                i = 0;
            }
        }
        else
        {
            if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
            {
                i = 1;
            }
            else if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH)
            {
                i = list_view->current_index - 1;
            }
            else
            {
                i = list_view->current_index;
            }
        }


			for(; i <= list_view->current_index; i++)
			{
				list_cache = &(list_view->list_cache[i]);
				list_cache->first_index = 0;
				list_cache->last_index = 0;
				list_cache->head = 0;
				list_cache->tail = 0;
				list_cache->total = 0;
				list_cache->cache_num = 0;
				memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
			}

        
        
        if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE &&
            !(play_info->active_type == SRV_PLST_ACTIVE_LIST_PLST && list_view->view_type[0] != SRV_PLST_VIEW_PLST))
        {
            if(list_view->view_type[0] != SRV_PLST_VIEW_PLST)
            {
                i = 0;
            }
            else
            {
                i = 1;
            }
            for(; i < list_view->current_index; i++)
            {
                list_cache = &(list_view->list_cache[i]);
                list_cache->first_index = 0;
                list_cache->last_index = 0;
                list_cache->head = 0;
                list_cache->tail = 0;
                list_cache->total = 0;
                list_cache->cache_num = 0;
                memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
            }        
        }
    }
}


void srv_plst_pls_delete_item_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_ar_media_struct* pls_db_delete_ind_ptr = (pls_db_act_ar_media_struct*)msg;
    pls_db_exec_single_db_req_struct* local_param_ptr;
    U32 handler; 
    srv_plst_base_info_struct *base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_DELETE_ACTIVE_ITEM_RSP, pls_db_delete_ind_ptr->result, __LINE__);      
    handler = pls_db_delete_ind_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    if (base->callback != NULL)
    {
       (base->callback)(base->user_data, SRV_PLST_CB_EVT_DELETE_PROGRESS, SRV_PLST_OK, pls_db_delete_ind_ptr->progress);
    }
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = pls_db_delete_ind_ptr->db_handle;
    local_param_ptr->index = pls_db_delete_ind_ptr->index;
    local_param_ptr->callback = base->callback;

    if(pls_db_delete_ind_ptr->is_remove)
    {
        pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr);
    }
    else
    {
        pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, local_param_ptr);
    }
}

void srv_plst_pls_search_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_search_data_struct* pls_db_search_rsp_ptr = (pls_db_search_data_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_ADD_ITEM_TO_PLST_RSP,  pls_db_search_rsp_ptr->ret);   
    MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_SEARCH_RSP_HDLER,pls_db_search_rsp_ptr->ret, pls_db_search_rsp_ptr->count);
    handler = pls_db_search_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    if (base->callback != NULL )
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_SEARCH, pls_db_search_rsp_ptr->ret,pls_db_search_rsp_ptr->count);
    }
}


void srv_plst_pls_store_active_rsp_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* pls_db_store_active_rsp_ptr = (pls_db_exec_single_db_req_struct*)msg;
    U32 handler;
    srv_plst_base_info_struct *base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handler = pls_db_store_active_rsp_ptr->db_handle->srv_hdr;
    if(!pls_db_util_check_handler_valid(handler))
    {
        return;
    }
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)handler)->base_info);
    if(base->srv_handle != handler)
    {
        return;
    }
    if (base->callback != NULL )
    {
        (base->callback)(base->user_data, SRV_PLST_CB_EVT_STORE_ACTIVE, SRV_PLST_OK,0);
    }
}

/******************************************************************
 * FUNCTION
 *    srv_plst_init_instance
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  base    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_init_instance(srv_plst_base_info_struct* base, srv_plst_db_context_struct *db_info)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_req_struct *local_param_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!db_info->instance_inited)
    {
        local_param_ptr = (pls_db_start_req_struct*) construct_local_para(sizeof(pls_db_start_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db_info;
        local_param_ptr->db_handle->sqlite_buf = kal_adm_alloc(base->create.mem_ptr, base->create.db_mem_size);
        local_param_ptr->db_handle->srv_hdr = base->srv_handle;

        if (local_param_ptr->db_handle->sqlite_buf == NULL)
        {
            free_local_para((local_para_struct*)local_param_ptr);
            return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
        }
        pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_DB_INIT_REQ, local_param_ptr);        
        PLS_WAIT_EVENT(PLS_DB_EVT_INIT);
        return base->error_code;
    }
    else
    {
        return SRV_PLST_OK;
    }    
}


/******************************************************************
 * FUNCTION
 *    srv_plst_deinit_instance
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_deinit_instance(srv_plst_base_info_struct* base, srv_plst_db_context_struct *db_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_start_req_struct *local_param_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (db_info->instance_inited)
    {
        local_param_ptr = (pls_db_start_req_struct*) construct_local_para(sizeof(pls_db_start_req_struct), TD_CTRL);
        local_param_ptr->db_handle = db_info;
        local_param_ptr->db_handle->srv_hdr = base->srv_handle;

        pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_DB_DEINIT_REQ, local_param_ptr);        
        PLS_WAIT_EVENT(PLS_DB_EVT_DEINIT);
        kal_adm_free(base->create.mem_ptr, db_info->sqlite_buf);
        return base->error_code;
    }
    else
    {
        return SRV_PLST_OK;
    }  
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_open_lib_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 ******************************************************************/
static MMI_BOOL srv_plst_pls_open_lib_create_folder(U16 *path, srv_plst_base_info_struct* base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    FS_HANDLE fs_hdr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_GetAttributes(path);

    //in a very special case: user create a file named "@service_player_internal" instead of folder
    //media player will be no entry but with a popup forever
    if (result >= 0 && !(result & FS_ATTR_DIR))
    {
        FS_Delete(path);
    }
    
    fs_hdr = FS_Open(path, FS_READ_ONLY);
    if (fs_hdr < FS_NO_ERROR)
    {
        fs_hdr = FS_CreateDir(path);
    
        if(fs_hdr < FS_NO_ERROR)
        {  
            base->error_code = SRV_PLST_RET_ERR_FS_ERROR;
            base->ture_err_code = fs_hdr;
            return MMI_FALSE;
        }
        else
        {
            FS_SetAttributes((WCHAR*)path, FS_ATTR_DIR | FS_ATTR_HIDDEN); 
        }
    }
    else
    {
        FS_SetAttributes((WCHAR*)path, FS_ATTR_DIR | FS_ATTR_HIDDEN); 
        FS_Close(fs_hdr);
    }

    return MMI_TRUE;
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_open_lib
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_open_lib(srv_plst_base_info_struct* base, srv_plst_open_flag_enum open_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_library_open_req_struct *local_param_ptr;
    srv_plst_db_context_struct *db_info;
    S32 result = 0;
    FS_HANDLE fs_hdr;
    MMI_BOOL create_res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    local_param_ptr = (pls_library_open_req_struct*) construct_local_para(sizeof(pls_library_open_req_struct), TD_CTRL);

    /* For reopen case, no need to check file correctness */
    if(open_flag != SRV_PLST_OPEN_REOPEN)
    {
    #if defined(__PLST_DUAL_DB_SUPPORT__)
        kal_wsprintf((U16*)&local_param_ptr->path, "%c:\\%w",SRV_FMGR_PUBLIC_DRV,SRV_PLST_DB_DEFAULT_FOLDER);
        if((create_res = srv_plst_pls_open_lib_create_folder((U16*)&local_param_ptr->path, base)) != MMI_TRUE)
        {
            goto create_folder_fail;
        }
    #endif /* __PLST_DUAL_DB_SUPPORT__ */
    
        if (IS_CARD_EXIST || g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY)
        {
            kal_wsprintf((U16*)&local_param_ptr->path, "%c:\\%w",SRV_FMGR_CARD_DRV,SRV_PLST_DB_DEFAULT_FOLDER);
            create_res = srv_plst_pls_open_lib_create_folder((U16*)&local_param_ptr->path, base);
        }

create_folder_fail:
        if(!create_res)
        {
            free_local_para((local_para_struct*)local_param_ptr);
            if(open_flag == SRV_PLST_OPEN_NEW || open_flag == SRV_PLST_OPEN_AUTO)
            {
                pls_db_start_rsp_struct *rsp_param_ptr;
            
                SetProtocolEventHandler(srv_plst_pls_open_lib_rsp_hdler, MSG_ID_PLS_LIBRARY_OPEN_RSP);   
                rsp_param_ptr = (pls_db_start_rsp_struct*) construct_local_para(sizeof(pls_db_start_rsp_struct), TD_CTRL);
            
                rsp_param_ptr->result = SRV_PLST_RET_ERR_FS_ERROR;
                rsp_param_ptr->callback = base->callback;
                rsp_param_ptr->db_handle = db_info;
                pls_send_msg(MOD_MMI, MOD_MMI, MSG_ID_PLS_LIBRARY_OPEN_RSP, rsp_param_ptr);
                return SRV_PLST_ASYNC;
            }
            else if(open_flag == SRV_PLST_OPEN_AFTER_MEDIA_CHANGE || open_flag == SRV_PLST_OPEN_ONLY)
            {
                return base->error_code;
            }
        }

        /* set as unread */
        {
            S32 attr;

            attr = FS_GetAttributes((const WCHAR*) db_info->db_phone_path);
            if (attr & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes((const WCHAR*) db_info->db_phone_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
            }
        #if defined(__PLST_DUAL_DB_SUPPORT__)
            if (IS_CARD_EXIST)
            {  
                attr = FS_GetAttributes((const WCHAR*) db_info->db_card_path);
                if (attr & FS_ATTR_READ_ONLY)
                {
                    FS_SetAttributes((const WCHAR*) db_info->db_card_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
                }
            }
        #endif /* __PLST_DUAL_DB_SUPPORT__ */
        }
    }

    local_param_ptr->db_handle = (void*)db_info;
    if(g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_ONLY)
    {
        local_param_ptr->drv_letter = SRV_FMGR_CARD_DRV;
    }
    else
    {
        local_param_ptr->drv_letter = SRV_FMGR_PUBLIC_DRV;
    }

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_OPEN_REQ, local_param_ptr); 
    if(open_flag == SRV_PLST_OPEN_NEW || open_flag == SRV_PLST_OPEN_AUTO)
    {
        base->is_open_cancel = MMI_FALSE;
        SetProtocolEventHandler(srv_plst_pls_open_lib_rsp_hdler, MSG_ID_PLS_LIBRARY_OPEN_RSP);
        return SRV_PLST_ASYNC;
    }
    else if(open_flag == SRV_PLST_OPEN_AFTER_MEDIA_CHANGE || open_flag == SRV_PLST_OPEN_ONLY || open_flag == SRV_PLST_OPEN_REOPEN)
    {
        base->is_open_cancel = MMI_FALSE;        
        PLS_WAIT_EVENT(PLS_DB_EVT_OPEN_ONLY);
        return base->error_code;
    }   
    else
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_stop_open_lib
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_open_lib(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_param_ptr;
    srv_plst_db_context_struct *db;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    base->is_open_cancel = MMI_TRUE;
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_OPEN_STOP_REQ, local_param_ptr);     
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return base->error_code;   
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_close_lib
 * DESCRIPTION
 *  close library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_close_lib(srv_plst_base_info_struct* base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct *local_param_ptr;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);

    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
   
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_CLOSE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_CLOSE);
    return base->error_code;   
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_pause_update_lib
 * DESCRIPTION
 *  pause library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_pause_update_lib(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct  *local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)base->srv_handle)->gen);

    gen->pause_gen = MMI_TRUE;
    local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);    
    local_param_ptr->db_handle = db;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_UPDATE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_PAUSE);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_resume_update_lib
 * DESCRIPTION
 *  resume library
 * PARAMETERS
 *  open_param    [IN]    open param
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_resume_update_lib(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct  *local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);

    if(!gen->pause_gen)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    gen->pause_gen = MMI_FALSE;
    
    local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);    
    local_param_ptr->db_handle = db;        
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_UPDATE_REQ, local_param_ptr);
    return SRV_PLST_OK; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_update_lib
 * DESCRIPTION
 *   refresh library
 * PARAMETERS
 *  base           [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_update_lib(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct  *local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);
    gen->last_error_code = 0;
    gen->stack_index = 0;
    gen->addc = 0;
    gen->search_handle = FS_INVALID_FILE_HANDLE;
    gen->cancel_gen = MMI_FALSE;
    gen->pause_gen = MMI_FALSE;
    memset(gen->stack, 0, SRV_PLST_MAX_FOLDER_DEPTH *sizeof(srv_plst_gen_lib_stack_node_struct));

    local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);    
    local_param_ptr->db_handle = db;
    db->Ucount = 0;
    if (gen->run_type == SRV_PLST_GEN_ADD)
    {
        gen->phase = SRV_PLST_GEN_PHASE_SEARCH_FIRST;
    }
    else if (gen->run_type == SRV_PLST_GEN_SYNC_ALL)
    {        
        gen->drv_idx = 0;
        gen->phase= SRV_PLST_GEN_PHASE_INIT;
    }
    else 
    {
        free_local_para((local_para_struct*)local_param_ptr);
        return SRV_PLST_RET_ERR_UNKOWN_ERR;
    }    
    base->is_refresh = MMI_TRUE;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_UPDATE_REQ, local_param_ptr);
    SetProtocolEventHandler(srv_plst_pls_update_lib_rsp_hdler, MSG_ID_PLS_LIBRARY_UPDATE_RSP);
    SetProtocolEventHandler(srv_plst_pls_lib_continue_rsp_hdr,MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP);
 
    return SRV_PLST_ASYNC;
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_stop_update_lib
 * DESCRIPTION
 *   stop refresh library
 * PARAMETERS
 *  srv_plst_base    [IN]    see srv_plst_base_info_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_update_lib(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_gen_lib_req_struct  *local_param_ptr;
    srv_plst_gen_lib_context_struct *gen;
    srv_plst_db_context_struct *db;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_PLS_LIBRARY_UPDATE_RSP);
    ClearProtocolEventHandler(MSG_ID_PLS_LIBRARY_UPDATE_CONTINUE_RSP);

    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)(base->srv_handle))->gen);

    gen->cancel_gen = MMI_TRUE;
   
    local_param_ptr = (pls_db_gen_lib_req_struct*)construct_local_para(sizeof(pls_db_gen_lib_req_struct), TD_CTRL);    
    local_param_ptr->db_handle = db;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIBRARY_STOP_UPDATE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_STOP_UPDATE);
    base->is_refresh = MMI_FALSE;
    return base->error_code;    
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_show_data
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  srv_plst_base     [IN]    see srv_plst_base_info_struct
 *  list_view_history [IN]    see srv_plst_list_view_history_struct
 *  index             [IN]    index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag, U32 index, U32* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);

    list_view->is_get_data_cancel = MMI_FALSE;
    
    if(data_flag == SRV_PLST_GET_TITLE || data_flag == SRV_PLST_GET_ARTWORK ||
        data_flag == SRV_PLST_GET_PATH || data_flag == SRV_PLST_GET_MEDIA_ID ||
        data_flag == SRV_PLST_GET_ITEM_ID)
    {
        if(index >= list_view->total_count && list_view->total_count)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }
        else if (index >= list_view->total_count && !list_view->total_count)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }
    }
    local_param_ptr = (pls_list_get_data_req_struct*)construct_local_para(sizeof(pls_list_get_data_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->get_type = data_flag;
    local_param_ptr->ret_value = data;
    if (data_flag == SRV_PLST_GET_COUNT)
    {
        list_view->bg_loading = MMI_FALSE;
        list_view->nb_blocking_artwork = MMI_FALSE;
        local_param_ptr->is_nblock = list_view->nb_blocking_artwork;
    }
    else if(data_flag == SRV_PLST_GET_ARTWORK)
    {
        local_param_ptr->is_nblock = list_view->nb_blocking_artwork;
        local_param_ptr->id        = g_srv_plst_query_album_id;
        
    }
    else if(data_flag == SRV_PLST_GET_ARTWORK_BY_ID ||
            data_flag == SRV_PLST_GET_ARTWORK_PARSER_PATH_BY_ID)
    {
        local_param_ptr->id = index;
    }
    else
    {
        local_param_ptr->is_nblock = MMI_FALSE;
    }
    if( local_param_ptr->get_type == SRV_PLST_GET_DETAILS || 
        local_param_ptr->get_type == SRV_PLST_GET_DETAILS_BY_FILTER || 
        local_param_ptr->get_type == SRV_PLST_GET_DETAILS_UPDATE ||
        local_param_ptr->get_type == SRV_PLST_GET_ARTIST_MEDIA_COUNT_BY_ID)
    {
        local_param_ptr->id = index;  
    }
    else
    {        
        local_param_ptr->index = index;
    }    
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_DATA_REQ, local_param_ptr);
    if(list_view->nb_blocking_artwork == MMI_TRUE)
    {
        SetProtocolEventHandler(srv_plst_pls_get_data_rsp_hdler, MSG_ID_PLS_LIST_GET_DATA_RSP);
        return SRV_PLST_ASYNC;
    }
    else
    {        
        PLS_WAIT_EVENT(PLS_DB_EVT_GET_DATA);
    }
    return base->error_code;        
}

#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
S32 srv_plst_pls_get_group_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_list_group_item_info_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_group_data_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    local_param_ptr = (pls_db_get_group_data_struct*)construct_local_para(sizeof(pls_db_get_group_data_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->data = data;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GROUP_LIST_COUNT_REQ, local_param_ptr);
    PLS_WAIT_EVENT(PLS_DB_EVT_LIST_GROUP_DATA);
    return base->error_code;  
}
#endif /*__PLST_SRV_FEATURE_GROUP_LIST__*/

S32 srv_plst_pls_update_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view, srv_plst_get_data_enum data_flag, U32 index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->list_view_history);

    list_view->is_get_data_cancel = MMI_FALSE;   
    if(index >= list_view->total_count && list_view->total_count)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    else if (index >= list_view->total_count && !list_view->total_count)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    
    local_param_ptr = (pls_list_get_data_req_struct*)construct_local_para(sizeof(pls_list_get_data_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->get_type = data_flag;
    local_param_ptr->is_nblock = list_view->is_nb_update_artwork;
    if(path != NULL)
    {
        local_param_ptr->ret_value =(U32*)path;
    }
    else
    {
        local_param_ptr->ret_value = NULL;
    }    
    local_param_ptr->index = index;    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_DATA_REQ, local_param_ptr);
    if(list_view->is_nb_update_artwork)
    {
        SetProtocolEventHandler(srv_plst_pls_update_artwork_rsp_hdler, MSG_ID_PLS_LIST_UPDATE_ARTWORK_RSP);  
        return SRV_PLST_ASYNC;        
    }
    else
    {
        PLS_WAIT_EVENT(PLS_DB_EVT_GET_DATA);
        return base->error_code;  
    }
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_stop_update_artwork
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  srv_plst_base     [IN]    see srv_plst_base_info_struct
 *  list_view_history [IN]    see srv_plst_list_view_history_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_update_artwork(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_get_data_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->list_view_history);

    list_view->is_stop_update_artwork = MMI_TRUE;

    local_param_ptr = (pls_db_exec_get_data_struct*)construct_local_para(sizeof(pls_db_exec_get_data_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->get_type = data_flag;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_STOP_UPDATE_ARTWORK_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_stop_get_show_data
 * DESCRIPTION
 *  open library
 * PARAMETERS
 *  srv_plst_base     [IN]    see srv_plst_base_info_struct
 *  list_view_history [IN]    see srv_plst_list_view_history_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_get_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_stop_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->list_view_history);

    list_view->is_get_data_cancel = MMI_TRUE;

    local_param_ptr = (pls_list_get_data_stop_struct*)construct_local_para(sizeof(pls_list_get_data_stop_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->get_type = data_flag;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_DATA_STOP_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);

    // Clear message handler
    ClearProtocolEventHandler(MSG_ID_PLS_LIST_GET_DATA_RSP);

    return base->error_code;
}

#ifdef __PLST_SRV_FEATURE_MOST_RECENT_LIST__
/******************************************************************
 * FUNCTION
 *    srv_plst_pls_update_playing_info
 * DESCRIPTION
 *    send msg to pls to update current playing media's playing info
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_update_playing_info(srv_plst_base_info_struct *base, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_update_play_info_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    local_param_ptr = (pls_db_exec_update_play_info_struct*)construct_local_para(sizeof(pls_db_exec_update_play_info_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->id = id;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_UPADTE_PLAYING_INFO_REQ, local_param_ptr); 
    PLS_WAIT_EVENT(PLS_DB_EVT_UPDATE_PLAY_INFO);
    return base->error_code;  
}
#endif /*__PLST_SRV_FEATURE_MOST_RECENT_LIST__*/

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_plst_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_plst_index(srv_plst_base_info_struct *base, UI_string_type name, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->ret_value = index;
    mmi_ucs2ncpy((CHAR*)local_param_ptr->path, (const CHAR*)name, SRV_FMGR_PATH_MAX_LEN);
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLST_GET_PLST_INDEX_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_PLST_INDEX);
    return base->error_code;  
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_create(srv_plst_base_info_struct *base, UI_string_type name, U32 *id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_list_view_history_struct *list_view;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->list_view_history);

    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->ret_value = id_info;
    mmi_ucs2ncpy((CHAR*)local_param_ptr->path, (const CHAR*)name, SRV_FMGR_PATH_MAX_LEN);
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLST_CREATE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_CREATE_PLST);
    if(list_view->current_index == 0 && list_view->view_type[0] == SRV_PLST_VIEW_PLST)
	{
        memset(&(list_view->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[0].last_index = 0;
        list_view->list_cache[0].first_index = 0;
        list_view->list_cache[0].head = 0;
        list_view->list_cache[0].tail = 0;        
        list_view->list_cache[0].cache_num = 0;
        list_view->query_index = 0;
        list_view->total_count +=1;
        list_view->list_cache[0].total = list_view->total_count;
	}    
    return base->error_code;  
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_delete(srv_plst_base_info_struct *base, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct* list_view;
    srv_plst_db_context_struct *db;   
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->playing_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
    playing_info->last_active_id = 0;
    list_view->is_delete_cancel = MMI_FALSE;

    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLST_DELETE_REQ, local_param_ptr);
    SetProtocolEventHandler(srv_plst_pls_delete_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_active_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_item_ind, MSG_ID_PLS_LIST_DELETE_ITEM_IND);
    
    return SRV_PLST_ASYNC; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_stop_delete(srv_plst_base_info_struct *base, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_list_view_history_struct* list_view;
    srv_plst_list_context_struct *list_cache;    
    S32 ret= SRV_PLST_OK;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
     
    list_view->is_delete_cancel = MMI_TRUE;

    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLST_DELETE_STOP_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    ret = srv_plst_pls_get_show_data(base, list_view,SRV_PLST_GET_COUNT, 0,count);
       if(ret != SRV_PLST_OK)
       {
           *count = 0;
       }
    
       if(!*count)
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else
           {
               i = 0;
           }
       }
       else
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else
           {
               i = list_view->current_index;
           }
       }
       
       for(; i <= list_view->current_index; i++)
       {
           list_cache = &(list_view->list_cache[i]);
           list_cache->first_index = 0;
           list_cache->last_index = 0;
           list_cache->head = 0;
           list_cache->tail = 0;
           list_cache->total = 0;
           list_cache->cache_num = 0;
           memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
       }    
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_rename(srv_plst_base_info_struct *base, UI_string_type name, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;   
    srv_plst_list_view_history_struct *list_view;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);

    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    mmi_ucs2ncpy((CHAR*)local_param_ptr->path, (const CHAR*)name, SRV_FMGR_PATH_MAX_LEN);
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLST_RENAME_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_RENAME_PLST);

    /* If list sort by time, no need to reset cache when rename since list order will not change */
    if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && base->config_plst_view != SRV_PLST_LIST_SORT_BY_MODIFY_TIME)
	{
        memset(&(list_view->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view->list_cache[0].last_index = 0;
        list_view->list_cache[0].first_index = 0;
        list_view->list_cache[0].head = 0;
        list_view->list_cache[0].tail = 0;
        list_view->list_cache[0].cache_num = 0;
        list_view->query_index = 0;
	}  

    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_plst_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_plst_id(srv_plst_base_info_struct *base, U32 index, U32* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->ret_value = id;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_ID_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_ID);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_create_mark_tbl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 *  is_create [IN] : TRUE: to create table, FALSE, to drop table
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_create_mark_tbl(srv_plst_base_info_struct *base, MMI_BOOL is_create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_create_mark_tbl_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    local_param_ptr = (pls_create_mark_tbl_req_struct*)construct_local_para(sizeof(pls_create_mark_tbl_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->is_create = is_create;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_CREATE_MARK_TBL_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_CREATE_MARK_TBL);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_multi_select_set_mark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_multi_select_set_mark(srv_plst_base_info_struct *base, U32 index, MMI_BOOL is_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)base->srv_handle)->db_info);
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->value = (U32)is_mark;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_MARK_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_MARK);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_multi_select_get_mark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_multi_select_get_mark(srv_plst_base_info_struct *base, U32 index, MMI_BOOL* is_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->ret_value = (U32*)is_mark;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_MARK_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_MARK);
    return base->error_code; 
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_add_media_to_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_add_media_to_plst(srv_plst_base_info_struct *base, U32 index, U32 plst_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct* list_view;
    srv_plst_db_context_struct *db; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
    list_view->is_add_cancel = MMI_FALSE;

    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->value = index;
    local_param_ptr->index = plst_idx;
    local_param_ptr->callback = base->callback;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_ADD_REQ, local_param_ptr);
    SetProtocolEventHandler(srv_plst_pls_add_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_ADD_RSP);
  //  SetProtocolEventHandler(srv_plst_pls_add_item_ind, MSG_ID_PLS_LIST_ADD_ITEM_IND);
    return SRV_PLST_ASYNC;   
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_add_media_to_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_add_media_to_plst(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct* list_view;
    srv_plst_db_context_struct *db;     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
    list_view->is_add_cancel = MMI_TRUE;
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_ADD_STOP_REQ, local_param_ptr);     
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return base->error_code;  
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_remove(srv_plst_base_info_struct *base, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db; 
    srv_plst_list_view_history_struct *list_view;
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->playing_info);
    playing_info->last_active_id = 0;
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
    list_view->is_cancel = MMI_FALSE;

    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->callback = base->callback;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr);

    SetProtocolEventHandler(srv_plst_pls_delete_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_active_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_item_ind, MSG_ID_PLS_LIST_DELETE_ITEM_IND);
    
    return SRV_PLST_ASYNC;
}



/******************************************************************
 * FUNCTION
 *    srv_plst_pls_stop_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_stop_remove(srv_plst_base_info_struct *base, U32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db; 
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    S32 ret = SRV_PLST_OK;        
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);

    list_view->is_cancel = MMI_TRUE;
    
    local_param_ptr->db_handle = db;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_STOP_REQ, local_param_ptr);
    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);

     ret = srv_plst_pls_get_show_data(base, list_view,SRV_PLST_GET_COUNT, 0,count);
       if(ret != SRV_PLST_OK)
       {
           *count = 0;
       }
    
       if(!*count)
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else
           {
               i = 0;
           }
       }
       else
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH && list_view->current_index)
           {
               i = list_view->current_index - 1;
           }
           else
           {
               i = list_view->current_index;
           }
       }
       
       for(; i <= list_view->current_index; i++)
       {
           list_cache = &(list_view->list_cache[i]);
           list_cache->first_index = 0;
           list_cache->last_index = 0;
           list_cache->head = 0;
           list_cache->tail = 0;
           list_cache->total = 0;
           list_cache->cache_num = 0;
           memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
       }
    return base->error_code;   
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_item_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_item_clear(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db; 
    S32 index = -1;
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->playing_info);
    playing_info->last_active_id = 0;
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
    list_view->is_cancel = MMI_FALSE;
    list_view->is_clear = MMI_TRUE;
    local_param_ptr->db_handle = db;
    local_param_ptr->callback = base->callback;
    local_param_ptr->index = (U32)&index;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_REQ, local_param_ptr);   
    SetProtocolEventHandler(srv_plst_pls_delete_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_active_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP);
    return SRV_PLST_ASYNC; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_item_stop_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_item_stop_clear(srv_plst_base_info_struct *base, U32 *count )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);

    list_view->is_cancel = MMI_TRUE;
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->callback = base->callback;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_REMOVE_STOP_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_list_item_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_list_item_delete(srv_plst_base_info_struct *base, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_db_context_struct *db;    
    srv_plst_playing_context_struct *playing_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->playing_info);
    playing_info->last_active_id = 0;
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);

    list_view->is_delete_cancel = MMI_FALSE;
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->callback = base->callback;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, local_param_ptr);
    SetProtocolEventHandler(srv_plst_pls_delete_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_active_item_plst_rsp_hdler, MSG_ID_PLS_LIST_ITEM_DELETE_ACTIVE_RSP);
    SetProtocolEventHandler(srv_plst_pls_delete_item_ind, MSG_ID_PLS_LIST_DELETE_ITEM_IND);
    return SRV_PLST_ASYNC;
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_list_item_stop_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_list_item_stop_delete(srv_plst_base_info_struct *base, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_db_context_struct *db;        
    S32 ret;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->list_view_history);
   
    list_view->is_delete_cancel = MMI_TRUE; 
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->ret_value = count;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_DELETE_STOP_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACTION_CANCEL);
    ret = srv_plst_pls_get_show_data(base, list_view,SRV_PLST_GET_COUNT, 0,count);
       if(ret != SRV_PLST_OK)
       {
           *count = 0;
       }
    
       if(!*count)
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else
           {
               i = 0;
           }
       }
       else
       {
           if(list_view->view_type[0] == SRV_PLST_VIEW_PLST && list_view->view_type[1] == SRV_PLST_VIEW_MEDIA)
           {
               i = 1;
           }
           else if(list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH && list_view->current_index)
           {
                i = list_view->current_index - 1;
           }
//bql: MAUI_02939511
//need to clear cache for previous screen 
//while delete items in the sub view
		   else if (list_view->view_type[list_view->current_index] == SRV_PLST_VIEW_PLST_ACTIVE)
		   {
		        i = list_view->current_index - 1;
		   }
           else
           {
               i = list_view->current_index;
           }
       }
       
       for(; i <= list_view->current_index; i++)
       {
           MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_CLEAR_VIEW_STACK, i, list_view->view_type[i], __LINE__);
           list_cache = &(list_view->list_cache[i]);
           list_cache->first_index = 0;
           list_cache->last_index = 0;
           list_cache->head = 0;
           list_cache->tail = 0;
           list_cache->total = 0;
           list_cache->cache_num = 0;
           memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
       }

    
    return base->error_code;
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_udpate_active_info_after_change_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_store_active_info(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;          
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    local_param_ptr = (pls_db_exec_single_db_req_struct*) construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_STORE_ACTIVE_INFO_REQ, local_param_ptr);    
    SetProtocolEventHandler(srv_plst_pls_store_active_rsp_hdler, MSG_ID_PLS_LIST_STORE_ACTIVE_INFO_RSP);
    return SRV_PLST_ASYNC;        
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_set_as_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 *  index   [IN]  set which index as active
 *  update_db           [IN]    update database (will have file access)
 *  use_current_list    [IN]    use current active list to update to database
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_set_as_active(srv_plst_base_info_struct *base, U32 index, MMI_BOOL update_db, MMI_BOOL use_current_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_set_active_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;          
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_list_set_active_req_struct*) construct_local_para(sizeof(pls_list_set_active_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->index = index;
    local_param_ptr->update_db = update_db;
    local_param_ptr->use_current = use_current_list; /* use current playing info to update DB */
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_SET_ACTIVE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_SET_ACTIVE);

    return base->error_code;    
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_prefix_search_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_prefix_search_count(srv_plst_base_info_struct *base, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_get_data_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_list_get_data_req_struct*)construct_local_para(sizeof(pls_list_get_data_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->get_type = SRV_PLST_GET_COUNT;
    local_param_ptr->ret_value = count;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_DATA_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_DATA);
    return base->error_code;        
}


S32 srv_plst_pls_search(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_get_data_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_exec_get_data_struct*)construct_local_para(sizeof(pls_db_exec_get_data_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_SEARCH_REQ, local_param_ptr);    
    SetProtocolEventHandler(srv_plst_pls_search_rsp_hdler, MSG_ID_PLS_LIST_SEARCH_RSP);
    
    return SRV_PLST_ASYNC;        
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_item_reorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_item_reorder(srv_plst_base_info_struct* base, U32 index_o,U32 index_d)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index_o;
    local_param_ptr->value = index_d;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ORIGANIZATION_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_REORDER_PLST);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_plst_item_reorder_set_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_plst_item_reorder_set_result(srv_plst_base_info_struct *base, MMI_BOOL save_notice)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->value = save_notice;
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ORIGANIZATION_RESULT_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_REORDER_RET);
    return base->error_code; 
}

/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_playing_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_playing_info(srv_plst_base_info_struct *base, srv_plst_playing_context_struct *playing_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->ret_value = (U32*)playing_info;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_LOAD_ACTIVE_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_LOAD_ACTIVE_INO);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_active_playing_media
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_active_playing_media(srv_plst_base_info_struct *base, srv_plst_playing_context_struct *playing_info,srv_plst_get_data_enum active_type, U32* id, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_list_item_get_play_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_list_item_get_play_req_struct*)construct_local_para(sizeof(pls_list_item_get_play_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;
    local_param_ptr->get_type = active_type;
    if(path != NULL)
    {
        local_param_ptr->path =(U16*)path;
    }
    else
    {
        local_param_ptr->path = NULL;
    }
    local_param_ptr->id = (U32)id;
    if(!(active_type == SRV_PLST_GET_ACTIVE_CURR || active_type == SRV_PLST_GET_ACTIVE_PREV || 
        active_type == SRV_PLST_GET_ACTIVE_NEXT || active_type == SRV_PLST_GET_ACTIVE_AUTO))    
    {
        base->error_code = SRV_PLST_RET_ERR_PARAM_ERR;
        free_local_para((local_para_struct*)local_param_ptr);
        return base->error_code;
    }
    
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ITEM_GET_PLAY_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_ACTIVE);
    return base->error_code;  
}



/******************************************************************
 * FUNCTION
 *    srv_plst_pls_entry_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_entry_list(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_entry_list_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_entry_list_req_struct*)construct_local_para(sizeof(pls_entry_list_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_ENTRY_LIST_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ENTRY_LIST);
    return base->error_code;      
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_exit_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_exit_list(srv_plst_base_info_struct * base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_exit_list_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_exit_list_req_struct*)construct_local_para(sizeof(pls_exit_list_req_struct), TD_CTRL);
    local_param_ptr->db_handle = (void*)db;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_EXIT_LIST_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_EXIT_LIST);
    return base->error_code;  
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_play_config_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_play_config_reset(srv_plst_base_info_struct *base)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_exec_single_db_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_exec_single_db_req_struct*)construct_local_para(sizeof(pls_db_exec_single_db_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_PLAY_CONFIG_RESET_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_PLAY_CONFIG_RST);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_cntx_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_cntx_by_id(srv_plst_base_info_struct *base, srv_plst_get_cntx_param_struct *in_param, srv_plst_get_context_struct *out_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_cntx_req_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_get_cntx_req_struct*)construct_local_para(sizeof(pls_db_get_cntx_req_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->in_param = in_param;
    local_param_ptr->out_param = out_param;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_GET_CNTX_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_GET_DATA);
    return base->error_code; 
}


/******************************************************************
 * FUNCTION
 *    srv_plst_pls_get_active_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  base    [IN]    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 ******************************************************************/
S32 srv_plst_pls_get_active_index(srv_plst_base_info_struct *base,  srv_plst_active_type_enum type, U32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_get_active_idx_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_get_active_idx_struct*)construct_local_para(sizeof(pls_db_get_active_idx_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->index = index;
    local_param_ptr->type = type;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_UPDATE_ACTIVE_INDEX_REQ, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_UPDATE_ACT_INDX);
    return base->error_code;
}


MMI_BOOL srv_plst_pls_check_plst_is_exist(srv_plst_base_info_struct *base, UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_check_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_check_plst_struct*)construct_local_para(sizeof(pls_db_check_plst_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->name = name;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_CHECK_PLST_EXIST, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_CHECK_PLST_EXIST);
    return (MMI_BOOL)base->error_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_pls_check_active_media_is_in_plst
 * DESCRIPTION
 *  check if active media in default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  MMI_BOOL 
 *                     MMI_TRUE   in
 *                     MMI_FALSE  not in
 *****************************************************************************/ 
MMI_BOOL srv_plst_pls_check_active_media_is_in_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_act_media_op_plst_struct*)construct_local_para(sizeof(pls_db_act_media_op_plst_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->type = type;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_CHECK_ACTIVE_IN_DEFPLST, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_CHECK_IN_PLST);
    return (MMI_BOOL)base->error_code;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_pls_active_media_remove_from_plst
 * DESCRIPTION
 *  remove active media from default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_pls_active_media_remove_from_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_act_media_op_plst_struct*)construct_local_para(sizeof(pls_db_act_media_op_plst_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->type = type;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ACT_MEDIA_REMOVE_FROM_DEFPLST, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACT_MED_AR_PLST);
    return base->error_code;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_pls_active_media_add_to_plst
 * DESCRIPTION
 *  add active media to default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_pls_active_media_add_to_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_act_media_op_plst_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);
    
    local_param_ptr = (pls_db_act_media_op_plst_struct*)construct_local_para(sizeof(pls_db_act_media_op_plst_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->type = type;
    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_ACT_MEDIA_ADD_TO_DEFPLST, local_param_ptr);    
    PLS_WAIT_EVENT(PLS_DB_EVT_ACT_MED_AR_PLST);
    return base->error_code;
}

#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
S32 srv_plst_pls_list_item_jumpto(srv_plst_base_info_struct *base, U32 jump_to_info, U32 *index)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pls_db_list_jump_struct* local_param_ptr;
    srv_plst_db_context_struct *db;       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)(base->srv_handle))->db_info);

    local_param_ptr = (pls_db_list_jump_struct*)construct_local_para(sizeof(pls_db_list_jump_struct), TD_CTRL);
    local_param_ptr->db_handle = db;
    local_param_ptr->jump_info = jump_to_info;
    local_param_ptr->ret_value = index;

    pls_send_msg(MOD_MMI, MOD_PLS, MSG_ID_PLS_LIST_LIST_JUMP_REQ, local_param_ptr);
    PLS_WAIT_EVENT(PLS_DB_EVT_LIST_JUMP);
    return base->error_code;
}
#endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */

#else
/******************************************************************
 * FUNCTION
 *    pls_create
 * DESCRIPTION
 *  player list service  task create function, avoid build error
 * PARAMETERS
 *  *handle    [IN]    task handle
 * RETURNS
 *  KAL_TRUE    create OK
 ******************************************************************/
kal_bool pls_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   return KAL_FALSE;
}

#endif


