/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_logger.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Log helper
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

#ifndef __VFX_LOGGER_H__
#define __VFX_LOGGER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For basic types
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"

/***************************************************************************** 
 * Setting
 *****************************************************************************/

#if defined(__COSMOS_MMI__) && !defined(LOW_COST_SUPPORT)
#define VFX_LOGGER_ENABLE
#endif

/***************************************************************************** 
 * Macro
 *****************************************************************************/

#ifdef VFX_LOGGER_ENABLE
#if defined(__MTK_TARGET__)
#define VFX_LOGGER_FUNC_MACRO   __PRETTY_FUNCTION__
#else
#define VFX_LOGGER_FUNC_MACRO   __FUNCTION__
#endif

#define VFX_LOG_FUNC                        VfxFuncLogger _logger((void*)this, VFX_LOGGER_FUNC_MACRO)
#define VFX_LOG_FUNC1(fmt, p1)              VfxFuncLogger _logger((void*)this, VFX_LOGGER_FUNC_MACRO, fmt, p1)
#define VFX_LOG_FUNC2(fmt, p1, p2)          VfxFuncLogger _logger((void*)this, VFX_LOGGER_FUNC_MACRO, fmt, p1, p2)
#define VFX_LOG_STATIC_FUNC                 VfxFuncLogger _logger(NULL, VFX_LOGGER_FUNC_MACRO)
#define VFX_LOG_STATIC_FUNC1(fmt, p1)       VfxFuncLogger _logger(NULL, VFX_LOGGER_FUNC_MACRO, fmt, p1)
#define VFX_LOG_STATIC_FUNC2(fmt, p1, p2)   VfxFuncLogger _logger(NULL, VFX_LOGGER_FUNC_MACRO, fmt, p1, p2)
#else
#define VFX_LOG_FUNC
#define VFX_LOG_FUNC1(fmt, p1)
#define VFX_LOG_FUNC2(fmt, p1, p2)
#define VFX_LOG_STATIC_FUNC
#define VFX_LOG_STATIC_FUNC1(fmt, p1)
#define VFX_LOG_STATIC_FUNC2(fmt, p1, p2)
#endif

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern void vfx_logger_enable_log(VfxBool on);
extern VfxBool vfx_logger_is_enable_log(void);

/***************************************************************************** 
 * VfxLogger
 *****************************************************************************/

#ifdef VFX_LOGGER_ENABLE
class VfxFuncLogger : public VfxBase
{
// Constructor / Destructor
public:
    VfxFuncLogger(void* thisPtr, const VfxChar *namePtr);
    VfxFuncLogger(void* thisPtr, const VfxChar *namePtr, const VfxChar *fmt, ...);
    virtual ~VfxFuncLogger(void);

private:
    void enableChildFunc(void);

private:
    VfxBool         m_hasChildFunc;
};
#endif

#endif /* __VFX_LOGGER_H__ */

