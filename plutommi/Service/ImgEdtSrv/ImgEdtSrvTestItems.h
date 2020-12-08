#ifndef __SRV_IES_TEST_ITEMS_H__
#define __SRV_IES_TEST_ITEMS_H__

#include "ImgEdtSrvTest.h"
#include "ImgEdtSrvStruct.h"
#include "scalado_adapt.h"

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // 0

/**************************************************************************
 * Base for testing single file
 **************************************************************************/
class IESTestFile : public IESTestBase
{
protected:
    virtual srv_ies_result selectTestCase(U32 caseID)
    {
        srv_ies_result result;

        result = SRV_IES_OK;

        switch(caseID)
        {
            case IES_TEST_CREATE_META_INFO:
                break;
            case IES_TEST_DECODE_META_INFO:
                break;
            case IES_TEST_RENDER_BUFFER:
                break;
            case IES_TEST_RENDER_PREVIEW:
                result = srv_ies_preview_render(m_hPreview);
                break;
            case IES_TEST_COLOR_ADJUST:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_COLOR_ADJUST);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_set_param_int(m_hCurImg,
                                                      0,
                                                      128);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_set_param_int(m_hCurImg,
                                                      1,
                                                      128);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_NEGATIVE_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_NEGATIVE);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_GRAYSCALE_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_GRAYSCALE);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_MIRROR_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_MIRROR);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_BRIGHTNESS_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_BRIGHTNESS);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_CONTRAST_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_CONTRAST);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_SEPIA_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_SEPIA);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_SHARPNESS_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_SHARPNESS);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            case IES_TEST_OIL_PAINT_EFFECT:
                result = srv_ies_effect_begin_adjust(m_hCurImg,
                                                     SRV_IES_EFFECT_OILPAINT);
                if (SRV_IES_OK != result)
                {
                    return result;
                }

                result = srv_ies_effect_end_adjust(m_hCurImg);
                break;
            default:
                ASSERT(0);
                break;
        }

        return result;
    }

public:
    static const U32 IES_TEST_CREATE_META_INFO  = 0;
    static const U32 IES_TEST_DECODE_META_INFO  = 1;
    static const U32 IES_TEST_RENDER_BUFFER     = 2;
    static const U32 IES_TEST_RENDER_PREVIEW    = 3;
    static const U32 IES_TEST_COLOR_ADJUST      = 4;
    static const U32 IES_TEST_NEGATIVE_EFFECT   = 5;
    static const U32 IES_TEST_GRAYSCALE_EFFECT  = 6;
    static const U32 IES_TEST_MIRROR_EFFECT     = 7;
    static const U32 IES_TEST_BRIGHTNESS_EFFECT = 8;
    static const U32 IES_TEST_CONTRAST_EFFECT   = 9;
    static const U32 IES_TEST_SEPIA_EFFECT      = 10;
    static const U32 IES_TEST_SHARPNESS_EFFECT  = 11;
    static const U32 IES_TEST_OIL_PAINT_EFFECT  = 12;

    static void testbedPressed()
    {
        MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_SET_KEY_HDLR, 1, 0, 0);
    }

    IESTestFile():
        m_hPreview(NULL)
    {
    }

    virtual S32 start(U32 caseID) 
    {
        const U32   PREVIEW_WIDTH     = GDI_LCD_WIDTH;
        const U32   PREVIEW_HEIGHT    = GDI_LCD_HEIGHT;
        const U32   PREVIEW_BPP       = 2;
        const WCHAR *CAPS_VERSION   = (const WCHAR*)caps_getVersion();

        srv_ies_result  result;
        U8              *pBuffer;

        initTestImage();

        pBuffer = (U8*)srv_ies_tst_rt_create_canvas(PREVIEW_WIDTH, PREVIEW_HEIGHT);
        ASSERT(NULL != pBuffer);

        srv_ies_preview_create(m_hCurImg,
                               &m_hPreview,
                               pBuffer,
                               PREVIEW_WIDTH * PREVIEW_HEIGHT * PREVIEW_BPP,
                               PREVIEW_WIDTH,
                               PREVIEW_HEIGHT,
                               PREVIEW_WIDTH * PREVIEW_BPP,
                               SRV_IES_COLORFORMAT_RGB565);

        selectTestCase(caseID);

        result = srv_ies_preview_render_async(m_hPreview,
                                              &onJobFinished,
                                              this,
                                              &m_hCurJob);
        if(SRV_IES_OK != result)
        {
            m_phaseRunning = false;
            fail((WCHAR*)L"srv_ies_preview_render() failed");

            return 0;
        }

        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(testbedPressed, KEY_1, KEY_EVENT_DOWN);

        return 1;
    }
      
    virtual void end() 
    {
        mmi_wcsncat(m_testReport, (WCHAR*)L"Run test case successfully\n ", SRV_IES_TST_LOG_MAX_LENGTH);

        if(NULL != m_hPreview)
        {
            srv_ies_preview_destroy(m_hPreview);
            m_hPreview = NULL;
        }

        IESTestBase::end();
    }

protected:
    srv_ies_preview_handle  m_hPreview;
};


/**************************************************************************
 * Base for testing caps engine
 **************************************************************************/
class IESTestCAPs : public IESTestFile
{
protected:
    virtual srv_ies_result selectTestCase(U32 caseID)
    {
        CRESULT         result;
        CTSession       session;
        CTAnimation     *pAnim;
        CTPoint         midPoint;
        CTPoint         stopPoint;
        CAPS_SCRIBBLE   scribble;
        CTColor         colorVal;
        CTPoint         testPoint;
        CTSize          testSize;
        CTColormode     colorMode;
        CTScreen        *screen;

        session = m_hCurImg->session;
        screen  = m_hPreview->screen;
        switch(caseID)
        {
            case CAPS_TEST_BRIGHTNESS_EFFECT:
                result = caps_beginBrightness(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setBrightness(session, 0.7);  // -1~1
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endBrightness(session);
                break;
            case CAPS_TEST_CONTRAST_EFFECT:
                result = caps_beginContrast(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setContrast(session, 0.7);  //-1~1
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endContrast(session);
                break;
            case CAPS_TEST_GRAYSCALE_EFFECT:
                result = caps_applyGrayscale(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_GRAYSCALE_NEG_EFFECT:
                result = caps_applyGrayscaleNegative(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_MIRROR_EFFECT:
                result = caps_applyMirror(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_NEGATIVE_EFFECT:
                result = caps_applyNegative(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_OIL_PAINT_EFFECT:
                result = caps_beginPaint(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setPaint(session, 3);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endPaint(session);
                break;
            case CAPS_TEST_HUE_SATURATION_EFFECT:
                result = caps_beginHueSaturation(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                
                result = caps_setHueSaturation(session, 240, 240);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endHueSaturation(session);
                break;
            case CAPS_TEST_SEPIA_EFFECT:
                result = caps_beginSepia(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setSepia(session,SEPIA_MEDIUM);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endSepia(session);
                break;
            case CAPS_TEST_SHARPNESS_EFFECT:
                result = caps_beginSharpness(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setSharpness(session, SHARPNESS_LEVEL_4);  // 0~7
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endSharpness(session);
                break;
            case CAPS_TEST_IMAGE_ROTATION:
                result = caps_beginRotate(session);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setRotate(session, ROTATE_TO_90);  //-1~1
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endRotate(session);
                break;    
            case CAPS_TEST_SCRIBBLE_OPERATION:
                colorVal.a = 200;
                colorVal.r = 200;
                colorVal.g = 200;
                colorVal.b = 200;

                colorMode = CM_COLOR_1_ALFA;

                result = caps_beginScribble(screen,
                                            0,
                                            &colorMode,
                                            colorVal,
                                            &scribble);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                testPoint.x = 50;
                testPoint.y = 50;

                testSize.w = 100;
                testSize.h = 100;

                result = caps_setRectangleInScribble(scribble,
                                                     testPoint,
                                                     testSize,
                                                     1,
                                                     1);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_endScribble(scribble);
                break;
            case CAPS_TEST_CLIPART_OPERATION:
                break;
            case CAPS_TEST_IMAGE_ZOOM2X:
                result = caps_setZoom(screen, 2.0f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_IMAGE_ZOOM4X:
                result = caps_setZoom(screen, 4.0f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_IMAGE_PAN2X:
                result = caps_setZoom(screen, 2.0f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setPan(screen, -0.3f, 0.4f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_IMAGE_PAN4X:
                result = caps_setZoom(screen, 4.0f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_setPan(screen, -0.3f, 0.4f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                break;
            case CAPS_TEST_ANIMATION_ZOOM:
                result = caps_animationCreate(screen, &pAnim);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                midPoint.x = 200;
                midPoint.y = 200;

                result = caps_animationBeginZoom(pAnim, 2.0f, &midPoint, 0);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }
                
                result = caps_animationUpdateScreen(pAnim, 0.5f, 0.5f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_animationEnd(pAnim, 0);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_animationDestroy(pAnim);
                break;
            case CAPS_TEST_ANIMATION_PAN:
                result = caps_setZoom(screen, 2.0f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_animationCreate(screen, &pAnim);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                stopPoint.x = 100;
                stopPoint.y = 100;

                result = caps_animationBeginPan(pAnim, &stopPoint);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_animationUpdateScreen(pAnim, 0.5f, 0.5f);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                result = caps_animationEnd(pAnim, 0);
                if (CFAILED(result))
                {
                    return SRV_IES_E_UNEXPECTED;
                }

                caps_animationDestroy(pAnim);
                break;
            case CAPS_TEST_CREATE_SPEEDVIEW:
                break;
            default:
                ASSERT(0);
                break;
        }

        return SRV_IES_OK;
    }

public:
    static const U32    CAPS_TEST_BRIGHTNESS_EFFECT     = 0;
    static const U32    CAPS_TEST_CONTRAST_EFFECT       = 1;
    static const U32    CAPS_TEST_GRAYSCALE_EFFECT      = 2;
    static const U32    CAPS_TEST_GRAYSCALE_NEG_EFFECT  = 6;
    static const U32    CAPS_TEST_MIRROR_EFFECT         = 3;
    static const U32    CAPS_TEST_NEGATIVE_EFFECT       = 4;
    static const U32    CAPS_TEST_OIL_PAINT_EFFECT      = 5;
    static const U32    CAPS_TEST_HUE_SATURATION_EFFECT = 7;
    static const U32    CAPS_TEST_SEPIA_EFFECT          = 8;
    static const U32    CAPS_TEST_SHARPNESS_EFFECT      = 9;
    static const U32    CAPS_TEST_IMAGE_ROTATION        = 10;
    static const U32    CAPS_TEST_SCRIBBLE_OPERATION    = 11;
    static const U32    CAPS_TEST_CLIPART_OPERATION     = 12;
    static const U32    CAPS_TEST_IMAGE_ZOOM2X          = 13;
    static const U32    CAPS_TEST_IMAGE_ZOOM4X          = 14;
    static const U32    CAPS_TEST_IMAGE_PAN2X           = 15;
    static const U32    CAPS_TEST_IMAGE_PAN4X           = 16;
    static const U32    CAPS_TEST_ANIMATION_ZOOM        = 17;
    static const U32    CAPS_TEST_ANIMATION_PAN         = 18;
    static const U32    CAPS_TEST_CREATE_SPEEDVIEW      = 19;

    IESTestCAPs()
    {
    }
};

IESTestResultEnum srv_ies_tst_rt_test_caps(U32 caseID);

IESTestResultEnum srv_ies_test_rt_test_render(U32 caseID);

IESTestResultEnum srv_ies_tst_rt_test_effect(U32 caseID);

#endif  // __SRV_IES_TEST_ITEMS_H__
