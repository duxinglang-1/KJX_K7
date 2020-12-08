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
 * ImgEdtSrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service internal data type definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_SRV_IES__
#include "ImgEdtSrvConfig.h"
#include "ImgEdtSrvStruct.h"

#include "mmi_rp_srv_imgedt_def.h"

/*****************************************************************************
 * REGISTERED EFFECT CLASSES - This table decides all effects
 *****************************************************************************/
typedef struct srv_ies_param_info
{
    S32                         minVal;
    S32                         maxVal;
    S32                         original;
    S32                         current;
    U32                         applied;
    srv_ies_effect_param_enum   infoID;
    MMI_STR_ID                  nameID;
} srv_ies_param_info;


typedef srv_ies_result (*func_caps_begin)(CTSession             session,
                                          srv_ies_param_info    *pParam);
typedef srv_ies_result (*func_caps_adjust)(CTSession            session,
                                           srv_ies_param_info   *pParam,
                                           U32                  paramID,
                                           S32                  value);
typedef srv_ies_result (*func_caps_cancel)(CTSession            session,
                                           srv_ies_param_info   *pParam);
typedef srv_ies_result (*func_caps_end)(CTSession           session,
                                        srv_ies_param_info  *pParam);

typedef struct srv_ies_simple_effect
{
    srv_ies_effect_enum         effectID;
    MMI_STR_ID                  effectName;
    func_caps_begin             capsBegin;
    func_caps_end               capsEnd;
    U32                         paramCount;
    srv_ies_param_info          *pParamInfo;
    func_caps_adjust            capsAdjust;
    func_caps_cancel            capsCancel;
} srv_ies_simple_effect;


typedef srv_ies_result (*func_effect_begin)(srv_ies_effect_interface    *pEffect,
                                            srv_ies_image               *pImage);
typedef srv_ies_result (*func_effect_adjust)(srv_ies_effect_interface   *pEffect,
                                             srv_ies_image              *pImage,
                                             U32                        index,
                                             S32                        value);
typedef srv_ies_result (*func_effect_cancel)(srv_ies_effect_interface   *pEffect,
                                             srv_ies_image              *pImage);
typedef srv_ies_result (*func_effect_end)(srv_ies_effect_interface      *pEffect,
                                          srv_ies_image                 *pImage);
typedef srv_ies_result (*func_effect_delete)(srv_ies_effect_interface *pEffect);

typedef struct srv_ies_effect_interface
{
    func_effect_begin           begin_func;
    func_effect_adjust          adjust_func;
    func_effect_cancel          cancel_func;
    func_effect_end             end_func;
    func_effect_delete          delete_func;
    void                        *pEffectData;
} srv_ies_effect_interface;

extern srv_ies_simple_effect g_srv_ies_simple_effect_table[9];

DECLARE_STATIC_RESERVE_SLOT(srv_ies_effect_interface, 3);

/*****************************************************************************
 * Internal finction for controlling effect
 *****************************************************************************/
 
// Simple effect
static srv_ies_result _srv_ies_effect_simple_begin(srv_ies_effect_interface *pEffect,
                                                   srv_ies_image            *pImage)
{
    srv_ies_simple_effect *pObject;

    ASSERT(pImage->pEffect == pEffect);

    pObject = (srv_ies_simple_effect*)pEffect->pEffectData;

    return pObject->capsBegin(pImage->session,
                              pObject->pParamInfo);
}

static srv_ies_result _srv_ies_effect_simple_adjust(srv_ies_effect_interface    *pEffect,
                                                    srv_ies_image               *pImage,
                                                    U32                         paramID,
                                                    S32                         value)
{
    srv_ies_simple_effect *pObject;

    ASSERT(pImage->pEffect == pEffect);

    pObject = (srv_ies_simple_effect*)pEffect->pEffectData;

    // Check parameter range & count
    if(paramID >= pObject->paramCount)
    {
        ASSERT(MMI_FALSE);
        return SRV_IES_E_INVALID_ARGS;
    }

    // Check value range
    ASSERT((value >= pObject->pParamInfo->minVal) && (value <= pObject->pParamInfo->maxVal));

    return pObject->capsAdjust(pImage->session,
                               pObject->pParamInfo,
                               paramID,
                               value);
}

static srv_ies_result _srv_ies_effect_simple_cancel(srv_ies_effect_interface    *pEffect,
                                                    srv_ies_image               *pImage)
{
    srv_ies_simple_effect *pObject;

    ASSERT(pImage->pEffect == pEffect);

    pObject = (srv_ies_simple_effect*)pEffect->pEffectData;

    return pObject->capsCancel(pImage->session,
                               pObject->pParamInfo);
}

static srv_ies_result _srv_ies_effect_simple_end(srv_ies_effect_interface   *pEffect,
                                                 srv_ies_image              *pImage)
{
    srv_ies_simple_effect *pObject;

    ASSERT(pImage->pEffect == pEffect);

    pObject = (srv_ies_simple_effect*)pEffect->pEffectData;

    return pObject->capsEnd(pImage->session,
                            pObject->pParamInfo);
}

static srv_ies_result _srv_ies_effect_simple_delete(srv_ies_effect_interface *pEffect)
{
    pEffect->pEffectData = NULL;

    TYPED_FREE(pEffect, srv_ies_effect_interface);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_simple_effect_factory(srv_ies_effect_enum        effectID,
                                                     srv_ies_effect_interface   **ppOutput)
{
    const int SRV_IES_EFFECT_COUNT = sizeof(g_srv_ies_simple_effect_table) / sizeof(srv_ies_simple_effect);

    srv_ies_effect_interface    *pEffect;
    S32                         index;

    if (NULL == ppOutput)
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    TYPED_ALLOC(pEffect, srv_ies_effect_interface);
    ASSERT(NULL != pEffect);

    pEffect->begin_func     = _srv_ies_effect_simple_begin;
    pEffect->adjust_func    = _srv_ies_effect_simple_adjust;
    pEffect->cancel_func    = _srv_ies_effect_simple_cancel;
    pEffect->end_func       = _srv_ies_effect_simple_end;
    pEffect->delete_func    = _srv_ies_effect_simple_delete;

    for(index = 0; index < SRV_IES_EFFECT_COUNT; ++index)
    {
        if(effectID == g_srv_ies_simple_effect_table[index].effectID)
        {
            pEffect->pEffectData = &g_srv_ies_simple_effect_table[index];
            break;
        }
    }

    if(index >= SRV_IES_EFFECT_COUNT)
    {
        TYPED_FREE(pEffect, srv_ies_effect_interface);
        *ppOutput = NULL;
        return SRV_IES_E_UNEXPECTED;
    }

    *ppOutput = pEffect;

    return SRV_IES_OK;
}


/*****************************************************************************
 * Internal finction for adjusting effect
 *****************************************************************************/

// Color adjust
static srv_ies_result _srv_ies_effect_color_begin(CTSession             session,
                                                  srv_ies_param_info   *pParam)
{
#ifdef __COSMOS_MMI_PACKAGE__
    pParam[0].current = pParam[0].original;  // Brightness
    pParam[1].current = pParam[1].original;  // Contrast
    pParam[2].current = pParam[2].original;  // Saturation
    pParam[3].current = pParam[3].original;  // Hue
#else
    pParam[0].current = pParam[0].original;  // Saturation
    pParam[1].current = pParam[1].original;  // Hue
#endif  // __COSMOS_MMI_PACKAGE__

    pParam->applied = 0;

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_color_adjust(CTSession            session,
                                                   srv_ies_param_info   *pParam,
                                                   U32                  index,
                                                   S32                  value)
{
    CRESULT result;

#ifdef __COSMOS_MMI_PACKAGE__
    float  capsVal;

    if (index >= 4)
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam[index].current = value;

    while(pParam->applied > 0)
    {
        result = caps_undo(session);
        ASSERT(result == CERR_OK);

        pParam->applied--;
    }

    // Set new brightness
    if (pParam[0].current != pParam[0].original)
    {
        capsVal = pParam[0].current * 1.0f / 256.0f;

        result = caps_beginBrightness(session);
        ASSERT(result == CERR_OK);
        result = caps_setBrightness(session, capsVal);
        ASSERT(result == CERR_OK);
        caps_endBrightness(session);
        pParam->applied++;
    }

    // Set new contrast
    if (pParam[1].current != pParam[1].original)
    {
        capsVal = pParam[1].current * 1.0f / 256.0f;

        result = caps_beginContrast(session);
        ASSERT(result == CERR_OK);
        result = caps_setContrast(session, capsVal);
        ASSERT(result == CERR_OK);
        caps_endContrast(session);
        pParam->applied++;
    }

    // Set new saturation
    if (pParam[2].current != pParam[2].original)
    {
        result = caps_beginHueSaturation(session);
        ASSERT(result == CERR_OK);
        result = caps_setHueSaturation(session, 128, pParam[2].current);
        ASSERT(result == CERR_OK);
        caps_endHueSaturation(session);
        pParam->applied++;
    }

    // Set new hue
    if (pParam[3].current != pParam[3].original)
    {
        result = caps_beginHueSaturation(session);
        ASSERT(result == CERR_OK);
        result = caps_setHueSaturation(session, pParam[3].current, 128);
        ASSERT(result == CERR_OK);
        caps_endHueSaturation(session);
        pParam->applied++;
    }
#else
    if (index >= 2)
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam[index].current = value;

    while(pParam->applied > 0)
    {
        result = caps_undo(session);
        ASSERT(result == CERR_OK);

        pParam->applied--;
    }

    // Set new hue
    if (pParam[0].current != pParam[0].original)
    {
        result = caps_beginHueSaturation(session);
        ASSERT(result == CERR_OK);
        result = caps_setHueSaturation(session, pParam[0].current, 128);
        ASSERT(result == CERR_OK);
        caps_endHueSaturation(session);
        pParam->applied++;
    }

    // Set new saturation
    if (pParam[1].current != pParam[1].original)
    {
        result = caps_beginHueSaturation(session);
        ASSERT(result == CERR_OK);
        result = caps_setHueSaturation(session, 128, pParam[1].current);
        ASSERT(result == CERR_OK);
        caps_endHueSaturation(session);
        pParam->applied++;
    }
#endif  // __COSMOS_MMI_PACKAGE__

    return SRV_IES_OK;    
}

static srv_ies_result _srv_ies_effect_color_cancel(CTSession            session,
                                                   srv_ies_param_info   *pParam)
{
    CRESULT result;

    while (pParam->applied > 0)
    {
        result = caps_undo(session);
        ASSERT(result == CERR_OK);
        pParam->applied--;
    }

    return SRV_IES_OK;
}

static CRESULT _srv_ies_effect_color_custom_undo(CTSession session, void *opData)
{
    CRESULT             result;
    srv_ies_param_info  *pParam;

    pParam = (srv_ies_param_info*)opData;

    while (pParam->applied > 0)
    {
        result = caps_undo(session);
        ASSERT(result == CERR_OK);
        pParam->applied--;
    }

    oslmem_free(pParam);

    return CERR_OK;
}

static CRESULT _srv_ies_effect_bcsh_custom_redo(CTSession session, void *opData)
{
    return CERR_OK;
}   


static CRESULT _srv_ies_effect_bcsh_custom_remove(CTSession session, void *opData)
{
    oslmem_free(opData);

    return CERR_OK;
}

static srv_ies_result _srv_ies_effect_color_end(CTSession           session,
                                                srv_ies_param_info  *pParam)
{
    CRESULT             result;
    srv_ies_param_info  *pData;

    if (pParam->applied > 0)
    {
        pData = (srv_ies_param_info*)oslmem_alloc(sizeof(srv_ies_param_info));
        ASSERT(NULL != pData);

        memcpy(pData, pParam, sizeof(srv_ies_param_info));

        result = caps_addCustomUndoOperation(session,                             // Session
                                             _srv_ies_effect_color_custom_undo,   // Undo
                                             _srv_ies_effect_bcsh_custom_redo,    // Redo
                                             _srv_ies_effect_bcsh_custom_remove,  // Remove
                                             pData);                              // Data
        ASSERT(CERR_OK == result);
    }

    return SRV_IES_OK;
}


// Negative effect
static srv_ies_result _srv_ies_effect_negative_begin(CTSession          session,
                                                     srv_ies_param_info *pParam)
{
    CRESULT result;

    result = caps_applyNegative(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_negative_adjust(CTSession            session,
                                                      srv_ies_param_info   *pParam,
                                                      U32                  index,
                                                      S32                  value)
{
    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_negative_cancel(CTSession             session,
                                                      srv_ies_param_info    *pParam)
{
    CRESULT result;

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_negative_end(CTSession            session,
                                                   srv_ies_param_info   *pParam)
{
    return SRV_IES_OK;
}

// Grayscale effect
static srv_ies_result _srv_ies_effect_grayscale_begin(CTSession             session,
                                                      srv_ies_param_info    *pParam)
{
    CRESULT result;

    result = caps_applyGrayscale(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_grayscale_adjust(CTSession            session,
                                                       srv_ies_param_info   *pParam,
                                                       U32                  index,
                                                       S32                  value)
{
    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_grayscale_cancel(CTSession            session,
                                                       srv_ies_param_info   *pParam)
{
    CRESULT result;

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_grayscale_end(CTSession           session,
                                                    srv_ies_param_info  *pParam)
{
    return SRV_IES_OK;
}

// Mirror effect
static srv_ies_result _srv_ies_effect_mirror_begin(CTSession            session,
                                                   srv_ies_param_info   *pParam)
{
    CRESULT result;

    result = caps_applyMirror(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_mirror_adjust(CTSession            session,
                                                    srv_ies_param_info   *pParam,
                                                    U32                  index,
                                                    S32                  value)
{
    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_mirror_cancel(CTSession           session,
                                                    srv_ies_param_info  *pParam)
{
    CRESULT result;

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_mirror_end(CTSession          session,
                                                 srv_ies_param_info *pParam)
{
    return SRV_IES_OK;
}


// Brightness effect
static srv_ies_result _srv_ies_effect_brightness_begin(CTSession            session,
                                                       srv_ies_param_info   *pParam)
{
    CRESULT result;

    result = caps_beginBrightness(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_brightness_adjust(CTSession            session,
                                                        srv_ies_param_info   *pParam,
                                                        U32                  index,
                                                        S32                  value)
{
    CRESULT result;
    float   capsVal;

    capsVal = value * 1.0f / 256.0f;

    result = caps_setBrightness(session, capsVal);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_brightness_cancel(CTSession           session,
                                                        srv_ies_param_info  *pParam)
{
    CRESULT result;

    caps_endBrightness(session);

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_brightness_end(CTSession          session,
                                                     srv_ies_param_info *pParam)
{
    caps_endBrightness(session);

    return SRV_IES_OK;
}


// Contrast effect
static srv_ies_result _srv_ies_effect_contrast_begin(CTSession          session,
                                                     srv_ies_param_info *pParam)
{
    CRESULT result;

    result = caps_beginContrast(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_contrast_adjust(CTSession            session,
                                                      srv_ies_param_info   *pParam,
                                                      U32                  index,
                                                      S32                  value)
{
    CRESULT result;
    float capsVal;

    capsVal = value * 1.0f / 256.0f;

    result = caps_setContrast(session, capsVal);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_contrast_cancel(CTSession             session,
                                                      srv_ies_param_info    *pParam)
{
    CRESULT result;

    caps_endContrast(session);

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_contrast_end(CTSession            session,
                                                   srv_ies_param_info   *pParam)
{
    caps_endContrast(session);

    return SRV_IES_OK;
}


// Sepia effect
static srv_ies_result _srv_ies_effect_sepia_begin(CTSession             session,
                                                  srv_ies_param_info    *pParam)
{
    CRESULT result;

    pParam[0].current = pParam[0].original;

    result = caps_beginSepia(session);
    IES_RET_IF_FAIL(result);

    result = caps_setSepia(session, (CAPS_SEPIA_LEVEL)pParam[0].original);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sepia_adjust(CTSession            session,
                                                   srv_ies_param_info   *pParam,
                                                   U32                  index,
                                                   S32                  value)
{
    CRESULT result;
 
    result = caps_setSepia(session, (CAPS_SEPIA_LEVEL)value);
    IES_RET_IF_FAIL(result);

    pParam[0].current = value;

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sepia_cancel(CTSession            session,
                                                   srv_ies_param_info   *pParam)
{
    CRESULT result;

   caps_endSepia(session);

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sepia_end(CTSession           session,
                                                srv_ies_param_info  *pParam)
{
    caps_endSepia(session);

    return SRV_IES_OK;
}


// Sharpness effect
static srv_ies_result _srv_ies_effect_sharpness_begin(CTSession             session,
                                                      srv_ies_param_info    *pParam)
{
    CRESULT result;

    pParam[0].current = pParam[0].original;

    result = caps_beginSharpness(session);
    IES_RET_IF_FAIL(result);

    result = caps_setSharpness(session, (CAPS_SHARPNESS_LEVEL)pParam[0].original);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sharpness_adjust(CTSession            session,
                                                       srv_ies_param_info   *pParam,
                                                       U32                  index,
                                                       S32                  value)
{
    CRESULT result;

    result = caps_setSharpness(session, (CAPS_SHARPNESS_LEVEL)value);
    IES_RET_IF_FAIL(result);

    pParam[0].current = value;

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sharpness_cancel(CTSession            session,
                                                       srv_ies_param_info   *pParam)
{
    CRESULT result;

    caps_endSharpness(session);

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_sharpness_end(CTSession           session,
                                                    srv_ies_param_info  *pParam)
{
    caps_endSharpness(session);

    return SRV_IES_OK;
}

// Oily effect
static srv_ies_result _srv_ies_effect_oily_begin(CTSession          session,
                                                 srv_ies_param_info *pParam)
{
    CRESULT result;

    pParam[0].current = pParam[0].original;

    result = caps_beginPaint(session);
    IES_RET_IF_FAIL(result);

    result = caps_setPaint(session, pParam[0].original);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_oily_adjust(CTSession            session,
                                                  srv_ies_param_info   *pParam,
                                                  U32                  index,
                                                  S32                  value)
{
    CRESULT result;

    result = caps_setPaint(session, value);
    IES_RET_IF_FAIL(result);

    pParam[0].current = value;

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_oily_cancel(CTSession             session,
                                                  srv_ies_param_info    *pParam)
{
    CRESULT result;

    caps_endPaint(session);

    result = caps_undo(session);
    IES_RET_IF_FAIL(result);

    return SRV_IES_OK;
}

static srv_ies_result _srv_ies_effect_oily_end(CTSession            session,
                                               srv_ies_param_info   *pParam)
{
    caps_endPaint(session);

    return SRV_IES_OK;
}

#ifdef __COSMOS_MMI_PACKAGE__
static srv_ies_param_info g_bcsh_param_info[4] =
{
    // Brightness
    { -256, 256,      0,    0,  0, SRV_IES_EFFECT_PARAM_BRIGHTNESS_STRENGTH,         STR_ID_IES_EFFECT_BRIGHTNESS },
    // Contrast
    { -256, 256,      0,    0,  0,   SRV_IES_EFFECT_PARAM_CONTRAST_STRENGTH,           STR_ID_IES_EFFECT_CONTRAST },
    // Saturation
    {    0, 255,    128,  128,  0, SRV_IES_EFFECT_PARAM_SATURATION_STRENGTH,   STR_ID_IES_EFFECT_PARAM_SATURATION },
    // Hue
    {    0, 255,    128,  128,  0,          SRV_IES_EFFECT_PARAM_HUE_ADJUST,          STR_ID_IES_EFFECT_PARAM_HUE },
};
#else
srv_ies_param_info g_hue_param_info[2] =
{
    // hue
    {    0, 255,    128,  128,  0,          SRV_IES_EFFECT_PARAM_HUE_ADJUST,          STR_ID_IES_EFFECT_PARAM_HUE },
    // saturation
    {    0, 255,    128,  128,  0,  SRV_IES_EFFECT_PARAM_SATURATION_STRENGTH,  STR_ID_IES_EFFECT_PARAM_SATURATION },
};
#endif  // __COSMOS_MMI_PACKAGE__

static srv_ies_param_info g_brightness_param =
{
                 -256,                256,                  0,  0,  0, SRV_IES_EFFECT_PARAM_BRIGHTNESS_STRENGTH,   STR_ID_IES_EFFECT_PARAM_BRIGHTNESS
};

static srv_ies_param_info g_contrast_param = 
{
                 -256,                256,                  0,  0,  0,    SRV_IES_EFFECT_PARAM_CONTRAST_STRENGTH,     STR_ID_IES_EFFECT_PARAM_CONTRAST
};

static srv_ies_param_info g_sepia_param =
{
        SEPIA_MINIMUM,          SEPIA_MAX,      SEPIA_MINIMUM,  0,  0,              SRV_IES_EFFECT_PARAM_INVALID,              STR_ID_IES_EFFECT_SEPIA
};

static srv_ies_param_info g_sharpness_param = 
{
    SHARPNESS_LEVEL_1,  SHARPNESS_LEVEL_7,  SHARPNESS_LEVEL_3,  0,  0,   SRV_IES_EFFECT_PARAM_SHARPNESS_STRENGTH,          STR_ID_IES_EFFECT_SHARPNESS
};

static srv_ies_param_info g_oily_param =
{
                    1,                  4,                  1,  0,  0,              SRV_IES_EFFECT_PARAM_INVALID,           STR_ID_IES_EFFECT_OILPAINT
};

// Global definition of effect information
static srv_ies_simple_effect g_srv_ies_simple_effect_table[9] =
{
#ifdef __COSMOS_MMI_PACKAGE__
    { SRV_IES_EFFECT_COLOR_ADJUST,     STR_ID_IES_EFFECT_BCSH_ADJUST,        _srv_ies_effect_color_begin,         _srv_ies_effect_color_end,    4, &g_bcsh_param_info[0],         _srv_ies_effect_color_adjust,      _srv_ies_effect_color_cancel },
#else
    { SRV_IES_EFFECT_COLOR_ADJUST,  STR_ID_IES_EFFECT_HUE_SATURATION,        _srv_ies_effect_color_begin,         _srv_ies_effect_color_end,    2,  &g_hue_param_info[0],         _srv_ies_effect_color_adjust,      _srv_ies_effect_color_cancel },
#endif

    { SRV_IES_EFFECT_NEGATIVE,            STR_ID_IES_EFFECT_NEGATIVE,     _srv_ies_effect_negative_begin,      _srv_ies_effect_negative_end,    0,                  NULL,      _srv_ies_effect_negative_adjust,   _srv_ies_effect_negative_cancel },
    { SRV_IES_EFFECT_GRAYSCALE,          STR_ID_IES_EFFECT_GRAYSCALE,    _srv_ies_effect_grayscale_begin,     _srv_ies_effect_grayscale_end,    0,                  NULL,     _srv_ies_effect_grayscale_adjust,  _srv_ies_effect_grayscale_cancel },
    { SRV_IES_EFFECT_MIRROR,                STR_ID_IES_EFFECT_MIRROR,       _srv_ies_effect_mirror_begin,        _srv_ies_effect_mirror_end,    0,                  NULL,        _srv_ies_effect_mirror_adjust,     _srv_ies_effect_mirror_cancel },
    { SRV_IES_EFFECT_BRIGHTNESS,        STR_ID_IES_EFFECT_BRIGHTNESS,   _srv_ies_effect_brightness_begin,    _srv_ies_effect_brightness_end,    1,   &g_brightness_param,    _srv_ies_effect_brightness_adjust, _srv_ies_effect_brightness_cancel },
    { SRV_IES_EFFECT_CONTRAST,            STR_ID_IES_EFFECT_CONTRAST,     _srv_ies_effect_contrast_begin,      _srv_ies_effect_contrast_end,    1,     &g_contrast_param,      _srv_ies_effect_contrast_adjust,   _srv_ies_effect_contrast_cancel },

#ifdef __COSMOS_MMI_PACKAGE__
    { SRV_IES_EFFECT_SEPIA,                  STR_ID_IES_EFFECT_SEPIA,        _srv_ies_effect_sepia_begin,         _srv_ies_effect_sepia_end,    1,        &g_sepia_param,         _srv_ies_effect_sepia_adjust,      _srv_ies_effect_sepia_cancel },
    { SRV_IES_EFFECT_SHARPNESS,          STR_ID_IES_EFFECT_SHARPNESS,    _srv_ies_effect_sharpness_begin,     _srv_ies_effect_sharpness_end,    1,    &g_sharpness_param,     _srv_ies_effect_sharpness_adjust,  _srv_ies_effect_sharpness_cancel },
    { SRV_IES_EFFECT_OILPAINT,            STR_ID_IES_EFFECT_OILPAINT,         _srv_ies_effect_oily_begin,          _srv_ies_effect_oily_end,    1,         &g_oily_param,          _srv_ies_effect_oily_adjust,       _srv_ies_effect_oily_cancel },
#else
    { SRV_IES_EFFECT_SEPIA,                  STR_ID_IES_EFFECT_SEPIA,        _srv_ies_effect_sepia_begin,         _srv_ies_effect_sepia_end,    0,        &g_sepia_param,         _srv_ies_effect_sepia_adjust,      _srv_ies_effect_sepia_cancel },
    { SRV_IES_EFFECT_SHARPNESS,          STR_ID_IES_EFFECT_SHARPNESS,    _srv_ies_effect_sharpness_begin,     _srv_ies_effect_sharpness_end,    0,    &g_sharpness_param,     _srv_ies_effect_sharpness_adjust,  _srv_ies_effect_sharpness_cancel },
    { SRV_IES_EFFECT_OILPAINT,            STR_ID_IES_EFFECT_OILPAINT,         _srv_ies_effect_oily_begin,          _srv_ies_effect_oily_end,    0,         &g_oily_param,          _srv_ies_effect_oily_adjust,       _srv_ies_effect_oily_cancel },
#endif
};


/*****************************************************************************
 * Function to check effect status
 *****************************************************************************/
U32 srv_ies_effect_get_available_count(void)
{
    return sizeof(g_srv_ies_simple_effect_table) / sizeof(g_srv_ies_simple_effect_table[0]);
}


srv_ies_effect_enum srv_ies_effect_get_available_id(U32 index)
{
    return g_srv_ies_simple_effect_table[index].effectID;
}


MMI_BOOL srv_ies_effect_is_available(srv_ies_effect_enum effectID)
{
    if (effectID >= SRV_IES_EFFECT_END_OF_ITEM)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * Function to start/end/cancel effect
 *****************************************************************************/
srv_ies_result srv_ies_effect_begin_adjust(srv_ies_image_handle     hImage,
                                           srv_ies_effect_enum      effectID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result              result;
    srv_ies_effect_interface    *pEffect;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_EFFECT_BEGIN_ADJUST, 2, hImage);

    IES_CHECK_IMAGE(hImage);

    // Reserve memory for saving file
#ifdef __COSMOS_MMI_PACKAGE__
    if (oslmem_free_space() <= SRV_IES_SAVE_WORK_BUFFER)
    {
        IES_LOG_END(SRV_IES_E_NOT_ENOUGH_BUFFER);
        return SRV_IES_E_NOT_ENOUGH_BUFFER;
    }
#endif  // __COSMOS_MMI_PACKAGE__

    // Create effect and attach to image
    // after attach, this image cannot apply any other operations
    // except adjust/end/cancel
    _srv_ies_simple_effect_factory(effectID, &pEffect);
    ASSERT(NULL != pEffect);

    hImage->pEffect = pEffect;

    // Call begin() to start the effect
    result = pEffect->begin_func(pEffect, hImage);

    IES_LOG_END(result);
    return result;
}

srv_ies_result srv_ies_effect_set_param_int(srv_ies_image_handle    hImage,
                                            U32                     index,
                                            S32                     value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_EFFECT_SET_PARAM_INT, 3, hImage);

    ASSERT(NULL != hImage->pEffect);  // Must call begin() first

    result = hImage->pEffect->adjust_func(hImage->pEffect,
                                          hImage,
                                          index,
                                          value);

    IES_LOG_END(result);
    return result;
}

srv_ies_result srv_ies_effect_cancel_adjust(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_EFFECT_CANCEL_ADJUST, 1, hImage);

    ASSERT(NULL != hImage->pEffect);  // Must call begin() first

    result = hImage->pEffect->cancel_func(hImage->pEffect, hImage);

    hImage->pEffect->delete_func(hImage->pEffect);
    hImage->pEffect = NULL;

    IES_LOG_END(result);
    return result;
}

srv_ies_result srv_ies_effect_end_adjust(srv_ies_image_handle hImage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_result result;

    IES_LOG_SETUP();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IES_LOG_BEGIN(SRV_IES_EFFECT_END_ADJUST, 1, hImage);

    ASSERT(hImage->pEffect);  // Must call begin() first

    result = hImage->pEffect->end_func(hImage->pEffect, hImage);

    hImage->pEffect->delete_func(hImage->pEffect);
    hImage->pEffect = NULL;

    IES_LOG_END(result);
    return result;
}
 

/*****************************************************************************
 * Function to get effect info
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_effect_name(srv_ies_effect_enum   effectID,
                                              MMI_STR_ID            *pStrID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((effectID >= SRV_IES_EFFECT_END_OF_ITEM) || (NULL == pStrID))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    *pStrID = g_srv_ies_simple_effect_table[effectID].effectName;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_effect_get_param_count(srv_ies_effect_enum   effectID,
                                              U32                   *pCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((effectID >= SRV_IES_EFFECT_END_OF_ITEM) || (NULL == pCount))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    *pCount = g_srv_ies_simple_effect_table[effectID].paramCount;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_effect_get_param_id(srv_ies_effect_enum          effectID,
                                           U32                          index,
                                           srv_ies_effect_param_enum    *pParamID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_param_info  *pParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((effectID >= SRV_IES_EFFECT_END_OF_ITEM) || (NULL == pParamID) ||
        (index >= g_srv_ies_simple_effect_table[effectID].paramCount))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam = g_srv_ies_simple_effect_table[effectID].pParamInfo;

    *pParamID = pParam[index].infoID;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_effect_get_param_name(srv_ies_effect_enum    effectID,
                                             U32                    index,
                                             MMI_STR_ID             *pStrID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_param_info  *pParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((effectID >= SRV_IES_EFFECT_END_OF_ITEM) || (NULL == pStrID) ||
        (index >= g_srv_ies_simple_effect_table[effectID].paramCount))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam = g_srv_ies_simple_effect_table[effectID].pParamInfo;
    
    *pStrID = pParam[index].nameID;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_effect_get_param_default(srv_ies_effect_enum effectID,
                                                U32                 index,
                                                S32                 *pDefault)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_param_info  *pParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((effectID >= SRV_IES_EFFECT_END_OF_ITEM) || (NULL == pDefault) ||
        (index >= g_srv_ies_simple_effect_table[effectID].paramCount))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam = g_srv_ies_simple_effect_table[effectID].pParamInfo;
    
    *pDefault = pParam[index].original;

    return SRV_IES_OK;
}


srv_ies_result srv_ies_effect_get_param_range(srv_ies_effect_enum effectID,
                                              U32                 index,
                                              S32                 *pMinVal,
                                              S32                 *pMaxVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ies_param_info  *pParam;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((effectID >= SRV_IES_EFFECT_END_OF_ITEM) ||
        (NULL == pMinVal) || (NULL == pMaxVal) ||
        (index >= g_srv_ies_simple_effect_table[effectID].paramCount))
    {
        return SRV_IES_E_INVALID_ARGS;
    }

    pParam = g_srv_ies_simple_effect_table[effectID].pParamInfo;
    
    *pMinVal = pParam[index].minVal;
    *pMaxVal = pParam[index].maxVal;

    return SRV_IES_OK;
}

#endif /* __MMI_SRV_IES__ */
