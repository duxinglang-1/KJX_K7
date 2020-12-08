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
 *  Vcui_imageeditor.h
 *
 * Project:
 * --------
 *  Venus
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __VAPP_PHOEDT_H__
#define __VAPP_PHOEDT_H__

#ifdef __MMI_COSMOS_PHOTOEDITOR__ 
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "Vapp_fmgr_cp.h"

#include "vapp_imgedt_gprot.h"
#include "vapp_imgedt_util.h"
#include "mmi_rp_vapp_imgedt_def.h"

extern "C"
{
#include "FileMgrGProt.h"
#include "ImgEdtSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define IMGEDT_ADD_TEXT_MAX_COUNT   10

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
    
typedef struct
{   
    VfxU8 r;
    VfxU8 g;
    VfxU8 b;

} imgedt_color;

#define __VCP_IMGEDT__

/***************************************************************************** 
 * Class VcpImgEdtPreviewLayer
 *****************************************************************************/
class VcpImgEdtPreviewLayer : public VfxControl
{
public:
    VcpImgEdtPreviewLayer(VfxU8* buf);
    
public:
    void setNeedRedrawPluto();
    void getLayerBuffer(VfxU8** pbuf);

protected:    
    virtual void onInit();    
    virtual void onDeinit();    
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onDraw(VfxDrawContext &dc);
    
private:
    void createGdiLayer();
    void freeGdiLayer();
    void onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);
    
private:
    VfxU32 m_layerHdl;    
    VfxU8 *m_layerBuffer;
    VfxU32 m_layerBufferSize;
};

/***************************************************************************** 
 * Class VappImgEdtIesHdlr
 *****************************************************************************/
class VappImgEdtIesHdlr : public VfxObject
{

public:
    enum IesEdtType
    {
        EDIT_TYPE_NONE,
        EDIT_TYPE_ROTATE,
        EDIT_TYPE_ADJUST,
        EDIT_TYPE_EFFECT,
        EDIT_TYPE_FLIP,
        EDIT_TYPE_ADD_ICON,
        EDIT_TYPE_DOODLE,
        EDIT_TYPE_ADD_FRAME,
        EDIT_TYPE_RENDER,
        EDIT_TYPE_CREATE_META,

        EDIT_TYPE_TOTAL,
    };

    enum AdjustType
    {
        ADJUST_TYPE_BRIGHTNESS,
        ADJUST_TYPE_CONTRAST,
        ADJUST_TYPE_SATURATION,
        ADJUST_TYPE_HUE,
        
        ADJUST_TOTAL
    };

    enum EffectType
    {
        EFFECT_TYPE_NONE,
        EFFECT_TYPE_NEGATIVE,
        EFFECT_TYPE_GRAYSCALE,
        EFFECT_TYPE_MIRROR,
        EFFECT_TYPE_SEPIA,
        EFFECT_TYPE_SHARPNESS,
        EFFECT_TYPE_OILPAINT,

        EFFECT_TOTAL
    };

    class AdjustInfo
    {
    public:        
        AdjustInfo():m_bValid(VFX_FALSE)
        {};
        
        void setValid(VfxBool valid)
        {
            m_bValid = valid;
        };

        void setStrId(VfxResId id)
        {
            m_strId = id;
        }

        void setValue(VfxS32 def, VfxS32 min, VfxS32 max)
        {
            m_defValue = def;
            m_minValue = min;
            m_maxValue = max;
        }

        VfxBool getValid()
        {
            return m_bValid;
        }

        VfxResId getStrId()
        {
            return m_strId;
        }

        VfxS32 getDefValue()
        {
            return m_defValue;
        }

        VfxS32 getMinValue()
        {
            return m_minValue;
        }

        VfxS32 getMaxValue()
        {
            return m_maxValue;
        }

    private:
        VfxBool     m_bValid;
        VfxResId    m_strId;
        VfxS32      m_defValue;
        VfxS32      m_minValue;
        VfxS32      m_maxValue;
    };

    class EffectInfo
    {
    public:
        EffectInfo():m_bValid(VFX_FALSE)
        {};
        
        void setId(VfxS32 id)
        {
            m_id = id;
        };

        void setValid(VfxBool valid)
        {
            m_bValid = valid;
        };

        void setStrId(VfxResId id)
        {
            m_strId = id;
        }

        void setImgId(VfxResId id)
        {
            m_imgId = id;
        }

        VfxS32 getId()
        {
            return m_id;
        }

        VfxBool getValid()
        {
            return m_bValid;
        }

        VfxResId getStrId()
        {
            return m_strId;
        }

        VfxResId getImgId()
        {
            return 0;
        }
        
    private:
        VfxBool     m_bValid;
        VfxS32      m_id;
        VfxResId    m_strId;
        VfxResId    m_imgId;
    };


    VappImgEdtIesHdlr();

public:
    //for internal receive render callback
    static VfxSignal2 <srv_ies_result, void*> m_signalRenderRes;
    //for external caller
    VfxSignal1 <srv_ies_result> m_signalRenderCallback;
    VfxSignal1 <VfxS32> m_signalCreateMetaCallback;
    VfxSignal1 <VfxS32> m_signalRenderProgress;

protected:
    virtual void onDeinit();


public:
    static VappImgEdtIesHdlr* getInstance();
    static VfxS32 reprepareInstance(VfxId app_id, 
                                    void *memBuf,
                                    VfxS32 memSize, 
                                    const VfxWChar *path, 
                                    VfxApp *parent
                                    );
    static VfxS32 createInstance(VfxId app_id,
                                 void *memBuf,
                                 VfxS32 memSize,
                                 const VfxWChar *path,
                                 VfxApp *parent
                                 );
    void closeInstance();
    VfxS32 getImageSize(VfxSize &size);
    VfxS32 updateImageInfo(VfxBool isForced = VFX_FALSE);  
    void cancelAll();
    //preview      
    void getMaxZoomSize(VfxSize &maxSize);    
    VcpImgEdtPreviewLayer *getPreviewInternal();
    VfxS32 createPreviewInternal(VfxU8* buf, VfxSize &previewSize);
    VfxS32 setPreviewParent(VfxObject *parent);
    VfxS32 createPreview(VfxU8* buf, srv_ies_preview_handle *preview,VfxSize size);
    VfxS32 createPreview(VcpImgEdtPreviewLayer *info, srv_ies_preview_handle *preview, VfxSize size);
    VfxS32 destroyPreview(srv_ies_preview_handle preview = NULL);
    VfxS32 renderPreview(srv_ies_preview_handle preview = NULL);
    VfxS32 createMeta(VfxWChar* path, VfxS32 width, VfxS32 height);
    void   onCreateMetaOver(srv_ies_result result);
    VfxS32 destroyMeta();
    VfxS32 cancelMeta();

    VfxS32 setZoomSmart(VfxFloat value);
    VfxS32 setDragSmart(VfxSize &distance);
    VfxS32 getZoomAndPan(VfxFloat *zoom, VfxFloat *panX, VfxFloat *panY);
    VfxS32 setZoomAndPan(VfxFloat zoom, VfxFloat panX, VfxFloat panY);

    VfxS32 zoomAniBegin(VfxS32 origIndx, VfxBool bLarger);
    VfxS32 zoomAniAdjust(VfxS32 index, VfxBool bLarger);
    VfxS32 zoomAniEnd(VfxBool isCancel = VFX_FALSE);
    
    VfxS32 getScrnArea(VfxRect *rect);
    VfxS32 getImageArea(VfxRect *rect);
    VfxS32 setImageArea(const VfxRect &rect);
    VfxS32 getCurrImageRect(VfxRect *pRect);
    VfxS32 getCurrImageSize(VfxSize &size);

    //util
    VfxS32 convtDistanceScrn2Img(VfxS32 distance);
    VfxPoint convtPointScrn2Img(VfxPoint &point);
    VfxPoint convtPointImg2SScrn(VfxPoint &point);

    //clip
    VfxS32 doClip(const VfxRect &rect, 
                  VfxBool needUpdate = VFX_TRUE); 
    
    //Rotate related
    VfxS32 rotateBegin();
    VfxS32 rotateAjust(srv_ies_rot_enum rot, VfxBool auto_render = MMI_TRUE);
    VfxS32 rotateEnd(VfxBool isApply);

    //Flip related
    VfxS32 flipBegin();
    VfxS32 flipAdjust(VfxBool isHorz, VfxBool isVert);
    VfxS32 flipEnd(VfxBool isApply);

    //adjust
    void getAdjustInitValue(VfxS32 type, VfxS32 *def, VfxS32 *min, VfxS32 *max);
    VfxResId getAjdustStrId(VfxS32 type);
    VfxS32 adjustBegin();
    VfxS32 adjustSet(VfxS32 type, VfxS32 value);
    VfxS32 adjustEnd(VfxBool is_apply);

    //effect
    VfxS32 effectBegin();
    VfxS32 effectSet(VfxS32 type);
    VfxS32 effectEnd(VfxBool is_apply);
    VfxResId effectGetImgId(VfxS32 type);
    VfxResId effectGetStrId(VfxS32 type);

    //add frame
    VfxS32 addFrameBegin(VfxResId id);
    VfxS32 addFrameChange(VfxResId id);
    VfxS32 addFrameEnd(VfxBool is_apply);

    //add cion
    VfxS32 addIcon(VfxResId id, VfxRect &rect);
    VfxS32 addText(VfxU8 *buff, VfxRect &rect);

    //doodle
    VfxS32 doodleBegin(VfxU32 width, imgedt_color color);
    VfxS32 doodleDraw(VfxPoint begin, VfxPoint end);
    VfxS32 doodleErase(VfxPoint begin, VfxPoint end, VfxU32 radius);
    VfxS32 doodleEnd(VfxBool is_apply);
    VfxS32 doodleSetColor(imgedt_color color);
    VfxS32 doodleSetWidth(VfxU32 width);
    VfxS32 doodleRenderPreview(VfxBool isUpdate);
    
    //undo/redu
    VfxBool checkUndoValid();
    VfxBool checkRedoValid();
    VfxS32 undo();
    VfxS32 redo();
    VfxBool checkAllEnabled()
    {
        return m_bEnalbeAll;
    }

    VfxBool checkIsLargeFile()
    {
        return m_bLargeFile;
    }
    void setIsLargeFile(VfxBool bLarge)
    {
        m_bLargeFile = bLarge;
    }
    
    VfxS32 save(VfxSize size, const VfxWChar* path);
    VfxS32 cancelSave();
    VfxS32 getRenderProgress();

    VfxS32   getLastError()
    {
        return (VfxS32)m_lastError;
    }
    VfxResId getErrorString(srv_ies_result ies_error_result);
    VfxS32   getCurrState();
    
private:
    VfxS32 getEffectIdByType(EffectType type);
    VfxBool checkEffectValid(EffectType type, EffectInfo &effectInfo);
    VfxS32 loadEffectInfo(VfxS32 index, S32 id);    
    VfxS32 loadAdjustInfo();
    VfxS32 loadStaticInfo();

    void setUndoValid(VfxBool valid);
    void setRedoValid(VfxBool valid);

    void onRenderTimeout(VfxTimer *timer);
public:
    void onRenderOver(srv_ies_result result);

private:
    AdjustInfo  m_adjustItem[ADJUST_TOTAL];
    EffectInfo  m_effectItem[EFFECT_TOTAL];
    VfxS32      m_currEffectIndex;
    
    srv_ies_app_session_handle  m_hApp;
    srv_ies_image_handle        m_hImg;
    srv_ies_meta_handle         m_hMeta;
    srv_ies_preview_handle      m_hPreview;
    srv_ies_doodle_info_handle  m_hDoodle;
    srv_ies_result              m_lastError;
    IesEdtType                  m_currType;

    VcpImgEdtPreviewLayer   *m_layerInfo;
    VfxTimer                *m_renderTimer;

    VfxBool m_bImageReady;
    VfxBool m_bEnalbeAll;
    VfxBool m_bLargeFile;

    VfxBool m_bImgRectChanged;
    //zoom and move
    VfxSize  m_maxSize;
    VfxSize  m_minSize;
    VfxSize  m_scrnSize;
    VfxFloat m_zoomFactor;
    VfxFloat m_zoom;
    VfxFloat m_distancePerPixel;
    VfxFloat m_zoomAnimDst;
    VfxS32   m_zoomAnimCount;
    VfxS32   m_zoomOrigIndx;

    VfxBool m_bVertFlip;
    VfxBool m_bHorzFlip;
    VfxBool m_bUndoValid;
    VfxBool m_bRedoValid;

    // original zoom and pen value
    VfxFloat m_orgZoom;
    VfxFloat m_orgPanX;
    VfxFloat m_orgPanY;

    srv_ies_job_handle m_hJob;
    
    static VfxApp               *m_curApp;
    static VappImgEdtIesHdlr    *m_iesHdlr;    
};

/***************************************************************************** 
 * class VcpImgEdtToolBar
 *****************************************************************************/
#define IMGEDT_TOOLBAR_MAX_BTNS_COUNT              (4)

class VcpImgEdtToolBar : public VfxPageBar
{
    VFX_DECLARE_CLASS(VcpImgEdtToolBar);

public:
    VfxSignal2 <VfxObject*, VfxId> m_signalBtnTap;

public:

    VcpImgEdtToolBar();

    void setSize(VfxSize size);
    void setBtnHeight(VfxS32 height);
    void show();    
    void addItem(VfxId btn_id, 
                 VfxResId button_icon);
    void setBtnDisabled(VfxId btn_id, VfxBool bDisabled);

private:
    void onBtnClicked(VfxObject *obj, VfxId id);

private:
    VcpImageButton *m_btnArray[IMGEDT_TOOLBAR_MAX_BTNS_COUNT];
    VfxS32          m_btnNum;
    VfxFrame        *m_background;
    VfxSize         m_btnSize;
    VfxSize         m_size;
};


/***************************************************************************** 
 * class VcpImgEdtScrollLayout
 *****************************************************************************/

class VcpImgEdtScrollLayout : public VcpBaseMenuLayout
{
public:
    VcpImgEdtScrollLayout(VcpBaseMenu* menu);

    virtual void onInit();
    virtual ScrollDirEnum getScrollDir();
    virtual VfxS32 getGroupCount();   
    virtual VfxS32 getCellCount(VfxS32 group);
    virtual VfxS32 getContentLength();
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    virtual VfxRect queryCellRect(VcpMenuPos pos);    
    virtual void getPreferFocusMargin(VfxS32 margin[4]);
    VcpMenuPos getCellByPos(VfxPoint pt); 
        
public:
    void setCellCount(VfxS32 count);
    void setStyle(ScrollDirEnum style);
    void setCellSize(VfxSize size);
    void setGaps(VfxS32 gap);
    void setOffset(VfxPoint offset);

private:
    ScrollDirEnum   m_style;
    VfxSize         m_cellSize;
    VfxS32          m_cellCount;
    VfxPoint        m_offset;
    VfxS32          m_gaps;
};


/***************************************************************************** 
 * Class VcpImgEdtScrollBtn
 *****************************************************************************/
class VcpImgEdtScrollBtn :  public VfxControl
{
    VFX_DECLARE_CLASS(VcpImgEdtScrollBtn);

public:   
    VcpImgEdtScrollBtn();
    void setIndex(VfxS32 pos);
    void setDisabled(VfxBool bDisabled);
    VfxBool getDisabled();

public:
    VfxSignal2 <VfxPenEvent &, VfxS32> m_longTapCell;

protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
private:
    VfxS32      m_index;
    VfxBool     m_disabled;
    VfxPoint    m_lastPos;
    //VfxFrame *m_bgFrame;
};


/***************************************************************************** 
 * Class VcpImgEdtScrollPanel
 *****************************************************************************/
enum ScrollPanelEnum
{
    EDIT_ROTATE,
    EDIT_CROP,
    EDIT_ADJUST,
    EDIT_EFFECT,
    EDIT_FLIP,
    EDIT_FRAME,
    EDIT_CLIPART,
    EDIT_TEXT,
    EDIT_DOODLE,
    EDIT_TOTAL
};

class VcpImgEdtScrollPanel : public VcpBaseMenu
{
public:    
    VcpImgEdtScrollPanel(VfxBool bVertMode);
    void setBtnDisabled(ScrollPanelEnum type, VfxBool bDisabled);

public:
    VfxSignal2 <VfxS32, VfxFrame*> m_tapCell;
    VfxSignal3 <VfxBool, VfxS32, VfxFrame*> m_signalHighLight;
    
protected:
    virtual void onInit();
    virtual VcpImgEdtScrollLayout* createLayout();    
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);    
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell);    
    virtual void onTouchCell(VcpMenuPos cellPos,CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell);
    virtual void onDrag(VfxS32 xoffset,VfxS32 yoffset);
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag){};

protected:
    void onLongTapCell(VfxPenEvent &event, VfxS32 pos);
   
private:
    VfxS32              m_focusPos;
    VfxImageFrame       *m_edtBtn[EDIT_TOTAL];
    VfxFrame            *m_bgFrame[EDIT_TOTAL];
    VfxBool             m_disabled[EDIT_TOTAL];
    VfxBool             m_bVertMode;
};

class VcpImgEdtFramePanel : public VcpBaseMenu
{
public:
    VcpImgEdtFramePanel(VfxBool bVertMode);
    VfxSignal2 <VfxS32, VfxFrame*> m_tapCell;

protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    virtual VcpImgEdtScrollLayout* createLayout();    
    virtual void onAfterCreateLayout();
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);    
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell);    
    virtual void onUpdateCell(const VfxRect & rect,VfxS32 group,VfxS32 pos,VfxFrame * cell,VfxU32 flag){};

private:
    VfxS32      m_cellCount;
    VfxFrame    *m_frameCell[EDIT_TOTAL];
    VfxBool     m_bVertMode;
};

/***************************************************************************** 
 * Class VappImgEdtIconPage
 *****************************************************************************/
class IVcpImgEdtMattsCellProvider 
{
public:
    virtual void getImageContent(
            VfxS32 index,
            VfxFrame *frame
            ) = 0;
};

class VcpImgEdtColorCellProvider: public IVcpImgEdtMattsCellProvider 
{
public:
    VcpImgEdtColorCellProvider(){};
    virtual void getImageContent(VfxS32 index, VfxFrame *frame);
};

class VcpImgEdtPenProvider: public IVcpImgEdtMattsCellProvider 
{
public:
    VcpImgEdtPenProvider(){};
    virtual void getImageContent(VfxS32 index, VfxFrame *frame);
};

class VcpImgEdtEraseProvider: public IVcpImgEdtMattsCellProvider 
{
public:
    VcpImgEdtEraseProvider(){};
    virtual void getImageContent(VfxS32 index, VfxFrame *frame);
};

class VcpImgEdtTextProvider: public IVcpImgEdtMattsCellProvider 
{
public:
    VcpImgEdtTextProvider(){};
    virtual void getImageContent(VfxS32 index, VfxFrame *frame);
};


class VcpImgEdtIconCellProvider: public IVcpImgEdtMattsCellProvider 
{
public:
    VcpImgEdtIconCellProvider(){};
    virtual void getImageContent(VfxS32 index, VfxFrame *frame);
};

class VcpImgEdtMattsLayout : public VcpBaseMenuLayout
{
public:
  
    VcpImgEdtMattsLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}
 
    virtual void onInit();
    virtual ScrollDirEnum getScrollDir();
    virtual VfxS32 getGroupCount();   
    virtual VfxS32 getCellCount(VfxS32 group);
    virtual VfxS32 getContentLength();
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    virtual VfxRect queryCellRect(VcpMenuPos pos);    
    virtual void getPreferFocusMargin(VfxS32 margin[4]);
    VcpMenuPos getCellByPos(VfxPoint pt); 
            
public:
    void setCellCount(VfxS32 count);
    void setCellSize(VfxSize size);
    void setColCount(VfxS32 col);
    void setCellGaps(VfxSize size);
    
private:
    VfxSize         m_cellSize;
    VfxSize         m_cellGapSize;
    VfxS32          m_cellCount;
    VfxS32          m_cellColCount;
    
};

class VcpImgEdtMattsPanel : public VcpBaseMenu
{
public:
    VcpImgEdtMattsPanel(VfxS32 style);
    
    void setContentProvider(
            IVcpImgEdtMattsCellProvider *contentProvider
            );
    void setFocus(VfxS32 index);

    VfxSignal2 <VfxS32, VfxFrame*> m_tapCell;

protected:
    virtual void onInit();
    virtual VcpImgEdtMattsLayout* createLayout();    
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);    
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag);
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell);    
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onTouchCell(VcpMenuPos cellPos,CellTouchTypeEnum touchType,VfxPoint pt,VfxFrame * cell);
    
private:
    IVcpImgEdtMattsCellProvider *m_contentProvider;
    VfxSize         m_cellSize;
    VfxS32          m_focusPos;
    VfxS32          m_style;
};


class VcpImgEdtMattsPopup : public VfxBasePopup
{
public:
    VcpImgEdtMattsPopup(VfxS32 style);

public:
    void setFocus(VfxS32 index);
    void setTitle(const VfxWString &text);
    const VfxWString& getTitle() const;
    void setContentSize(VfxSize size);
    void setContentProvider(
            IVcpImgEdtMattsCellProvider *contentProvider
            );

    VfxSignal1 <VfxS32> m_selectIcon;
    VfxSignal0 m_signalMattsPopupCancel;
    
protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onTapIconCell(VfxS32 pos, VfxFrame* cell);
    void onButtonClick(VfxObject* sender, VfxId id);

protected:
    VfxFrame        *m_backgroundTop;
    VfxFrame        *m_backgroundBottom;
    VfxTextFrame    *m_titleFrame;
    VfxS32          m_style;
    VfxS32          m_upRegionHeight;
    VfxS32          m_bottomRegionHeight;
    VcpImgEdtMattsPanel *m_matts;
    VcpButton       *m_cancelButton;
};

class VcpImgEdtInfoBalloon: public VfxControl
{
public:
    VcpImgEdtInfoBalloon();
    void setInfo(const VfxPoint &arrow, const VfxWString &str);

protected:
    virtual void onInit();
    
private:
    void updateLayout();

private:
    VfxTextFrame    *m_textFrame;
    VfxFrame        *m_backgroundLeft;
    VfxFrame        *m_backgroundCenter;
    VfxFrame        *m_backgroundRight;

    VfxPoint        m_arrowPos;
    
};

class VcpImgEdtSavePopup : public VappFileNameEditorPopup
{
public:
    VcpImgEdtSavePopup(); 
    void setMaxSize(const VfxSize &maxSize);
    VfxSize getCurrSize();

protected:
    virtual void onInit();
    virtual void onUpdate();
    
private:
    VfxSize getMinSize(VfxSize maxSize);
    void onValueChanged(VcpSlider *obj, VfxFloat value);
    void onThumbPressed(VcpSlider *obj, VfxFloat value);
    void onThumbReleased(VcpSlider *obj, VfxFloat value);

private:
    VcpSlider       *m_resizeSlider;
    VfxTextFrame    *m_maxText;
    VfxTextFrame    *m_minText;
    VfxTextFrame    *m_hintTextFrame2;
    VcpImgEdtInfoBalloon *m_hintBalloon; 
    
    VfxSize          m_maxSize;
    VfxSize          m_minSize;
    VfxSize          m_currSize;
    VfxS32           m_totalWidth;
    VfxBool          m_bSimpleMode;
};


#define __VCP_PAGE_SCRN__

/***************************************************************************** 
 * Class VappImgEdtPreviewPage
 *****************************************************************************/
class VcpImgEdtMattsPopup;
class VcpImgEdtIconCellProvider;

class VappImgEdtPreviewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappImgEdtPreviewPage);

    enum ToolBarType
    {
        TOOLBAR_SAVE,
        TOOLBAR_UNDO,
        TOOLBAR_REDO,
        TOOLBAR_CANCEL
    };
public:
    VappImgEdtPreviewPage();
	void onInitStage2();
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    //virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); // The parameter to rotate
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    void onToolBarBtnClicked(VfxObject* obj, VfxId id);
    void onSavePopupBtnClicked(VfxObject*  obj, VcpInputPopupButtonEnum type);
    void onSaveStart();
    void onSaveProgress(VfxS32 progress);
    void onSaveEnd(srv_ies_result result);
    void onSaveCanceled(VfxObject* obj, VfxFloat progress);
	void onSaveEndTimer(VfxTimer *source);
    void updateBottomBar();
    void updateTopBar();
    void saveImage();
    void onTapEdtBtn(VfxS32 pos, VfxFrame* cell);
    void onHighlightChanged(VfxBool is_on, VfxS32 pos, VfxFrame* cell);
    void prepareImageBegin();
    void prepareImageEnd(VfxS32 result);
    void displayOverWritePopup();
    void onCommandClicked(VfxObject *obj, VfxId command);
    void onErrorPopupCallback(VfxObject* sender,VfxId btn_id)
    {
        getMainScr()->popPage();
    }
    void onErrorPopup(VfxResId strId, VfxBool needCallback = VFX_TRUE)
    {
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
        if (needCallback)
        {
            popup->m_signalButtonClicked.connect(this, &VappImgEdtPreviewPage::onErrorPopupCallback);
        }        
        VcpImgEdtPopup::popupError(popup, strId);
    }

private:
    VcpActivityIndicator        *m_waitIcon;
    VcpImgEdtToolBar            *m_bottomBar;
    VappImgEdtIesHdlr           *m_iesHdlr;
    VcpCommandPopup             *m_confirmPopup;
    VcpImgEdtSavePopup          *m_savePopup;
    VcpInputPopup               *m_savePopupSimple;
    VcpImgEdtScrollPanel        *m_menu;    
    VcpIndicatorPopup           *m_saveIndPopup;
    VfxFrame                    *m_topHL;
    VfxS32                      m_createPreviewRes;
    //move related
    VfxPoint                m_lastMovePos;
    VfxBool                 m_bMoving;
    VfxRect                 m_bgRange;
    
    VcpImgEdtIconCellProvider   m_provider;
    VfxSize                     m_scrnSize;
    VfxBool                     m_bHaveErrorPopup;
	VfxBool                     m_isFirstEnter;
	VfxWeakPtr<VcpIndicatorPopup> m_indWeakPtr;
};

class VcpImgEdtHintBtn : public VcpImageButton
{
public:
    VfxSignal1 <VfxBool> m_hintBtnPress;

protected:
    virtual VfxBool onPenInput(VfxPenEvent & event)
    {
        VfxBool ret = VcpImageButton::onPenInput(event);
        switch (event.type)
        {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_hintBtnPress.emit(VFX_TRUE);
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
        case VFX_PEN_EVENT_TYPE_UP:
            m_hintBtnPress.emit(VFX_FALSE);
            break;
        }
        return ret;
    }
};

/***************************************************************************** 
 * Class VappImgEdtBasePage
 *****************************************************************************/
class VappImgEdtBasePage : public VfxPage
{
    VFX_DECLARE_CLASS(VappImgEdtBasePage);

protected:
    enum PageState
    {
        STATE_WITH_PANEL,
        STATE_FULL_SCREEN,
        
        STATE_PREVIEW = STATE_WITH_PANEL,
        STATE_EDIT = STATE_FULL_SCREEN,
        
        STATE_TOTAL
    };

public:
    VappImgEdtBasePage();

protected:    
    //commom virtual function
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    //virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);	
	virtual void onQueryRotateEx(VfxScreenRotateParam &param); // The parameter to rotate
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual VfxBool isAllowMove();

    //virtual function for child classes
    virtual void onStateChange(PageState state);
    virtual void onHintBtnClicked(VfxObject *obj, VfxId id);
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    virtual void onZoomSliderPressed(VcpSlider *sender, VfxFloat val);
    virtual void onZoomSliderMove(VcpSlider *sender, VfxFloat val);
    virtual void onZoomSliderReleased(VcpSlider *sender, VfxFloat val);
    virtual void onZoomStart(){};
    virtual void onZoomEnd(){};
    virtual void onErrorPopupCallback(VfxObject* sender,VfxId btn_id);
    virtual void onErrorPopup(VfxResId strId, VfxBool needCallback = VFX_TRUE);

    //not for override
    void createZoomSlider(VfxObject *parent);
    void deleteZoomSlider();
    void createHindBtn(VfxObject *parent);  

private:
    VfxBool isImageContains(const VfxPenEvent &event);
    VfxBool onCenterKeyInput(VfxKeyEvent & event);
    VfxBool onArrowKeyInput(VfxKeyEvent & event);
    void onZoomNextStep(VfxTimer *timer);
    void stopZoomTimer();
    void startZoomTimer();

protected:
    VcpImgEdtHintBtn        *m_hintBtn;
    VcpSlider               *m_zoomSlider;
    VfxFrame                *m_zoomAdd;
    VfxFrame                *m_zoomDec;
    VappImgEdtIesHdlr       *m_iesHdlr;
    VcpImgEdtBottomBar      *m_bottomBar;
    VfxFrame                *m_markDummy;
    VfxTimer                *m_zoomTimer;

    VfxKeyCodeEnum          m_pressedKey;
    PageState               m_pageState;
    VfxSize                 m_scrnSize;          
    VfxPoint                m_lastMovePos;
    VfxRect                 m_bgRange;
    VfxS32                  m_lastZoomIndx;
    VfxBool                 m_vertMode;
    VfxBool                 m_zoomLarger;
    VfxBool                 m_bMoving;
    VfxS32                  m_keyDownRet;
};

    
/***************************************************************************** 
 * Class VappImgEdtRotatePage
 *****************************************************************************/

class VcpImgEdtDialPanel : public VfxControl
{
    enum rotateMode
    {
        ROTATE_MODE_NONE,
        ROTATE_MODE_FOLLOW,
        ROTATE_MODE_FREE            
    };

public:    
    VcpImgEdtDialPanel();
    void setInitInfo(VfxSize bgSize, VfxS32 radius);
    void setDisabled(VfxBool is_disabled);
    void resetDialBtn();
    VfxSignal2 <VfxFloat &, VfxPenEventTypeEnum &> m_signalDialMove;
    
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
private:
 
    void getAngleInfo(VfxPoint p, VfxFloat *sin, VfxFloat *cos, VfxFloat *radian);
    VfxPoint getPosByPoint(VfxPoint pos);  
    VfxPoint getPosByRadian(VfxFloat radian);

private:
    VfxBool      m_isDisabled;
    VfxPoint     m_stub;
    VfxFloat     m_sin;
    VfxFloat     m_radian;
    VfxFloat     m_cos;
    VfxS32       m_radius;
    VfxFrame    *m_dialBtn;
    rotateMode   m_mode;
    VfxPoint     m_lastPos;
    VfxFrame    *m_btnHL;
};

class VappImgEdtRotatePage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtRotatePage);

    enum ImageResizeTrend
    {
        RESIZE_SMALLER,
        RESIZE_LARGER,
        RESIZE_NOCHANGE
    };
   
public:
    VappImgEdtRotatePage();
    static void enterRotatePage(VappImgEdtBasePage **page, VfxObject* parent, void *param);
    
protected:
    virtual void onInit();
    virtual void onDeinit();    
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual void onBottomBtnClicked(VfxObject* obj, VfxId id);
    
private:
    void prepareRotate();
    void onRotateBtnClick(VfxObject* obj, VfxId id);
    void onRotateFinished(VfxFrame *frame, VfxBool isFinished){};
    void onRotateImage(VfxFloat &radian, VfxPenEventTypeEnum &type);
    void rotateTimeLineFunc(    
	            void *output,
                const void *fromValue,
                const void *toValue,
                VfxTypeIdEnum typeId,
                VfxFloat t, 
                void *data,
                VfxU32 data_size){};
private:
    VcpImageButton          *m_rotateBtn;
    VcpImgEdtDialPanel      *m_dialPanel;
    
    //avatar
    VcpImgEdtPreviewLayer  *m_imageView;
    VfxFrame               *m_avatarFrame;
    srv_ies_preview_handle  m_avatarPreview;
    VfxSize                 m_maxSize;
    VfxSize                 m_minSize;
    GDI_HANDLE              m_gdiHdl;
    ImageResizeTrend        m_resizeTrend;
};


/***************************************************************************** 
 * Class VappImgEdtFlipPage
 *****************************************************************************/

class VcpImgEdtAdjustBar : public VfxFrame
{
public:
    VcpImgEdtAdjustBar();
    void setValue(VfxS32 def, VfxS32 min, VfxS32 max);
    void setId(VfxS32 id);
    void setDescription(const VfxWString& str);
    void setSliderBgImage(VfxResId id);
    void setSliderPos(VfxPoint pos);
    void setTextPos(VfxPoint pos);
    void setSliderLen(VfxS32 len);
    void show();

    VfxSignal2 <VfxS32, VfxFloat> m_signalValueChanged;

protected:
    virtual void onInit();

private:
    void onValueChangedBegin(VcpSlider * obj,VfxFloat value);
    void onValueChanged(VcpSlider *obj, VfxFloat value);
    void onValueChangedEnd(VcpSlider * obj,VfxFloat value);

private:
    VcpSlider       *m_slider;
    VfxTextFrame    *m_text;
    VfxS32          m_id;
    VfxResId        m_sliderBg;
    VfxPoint        m_sliderPos;
    VfxPoint        m_textPos;
    VfxS32          m_sliderLen;
    VfxU32          m_lastAdjustTime;
};


class VappImgEdtAdjustPage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtAdjustPage);

    enum BottomBtnType
    {
        BOTTOM_BTN_SHOW_BCS = VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_EX,
        BOTTOM_BTN_SHOW_HUE
    };

public:
    VappImgEdtAdjustPage();
    static void enterAdjustPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual void onBottomBtnClicked(VfxObject* sender, VfxId id);
    
private:    
    void showAdjustPanel(VfxBool is_hue);
    void onValueChanged(VfxS32 id, VfxFloat value);

private:
    VfxBool             m_BscActived;
    VfxFrame            *m_adjustPanelHue;
    VfxFrame            *m_adjustPanelBcs;
    VcpImgEdtAdjustBar  *m_adjustItem[VappImgEdtIesHdlr::ADJUST_TOTAL];
};


/***************************************************************************** 
 * Class VappImgEdtEffectPage
 *****************************************************************************/
class VcpImgEdtEffectPanel : public VcpBaseMenu
{
    
public:
    VcpImgEdtEffectPanel(VfxBool bVertMode);
    VfxSignal2 <VfxS32, VfxFrame*> m_tapCell;
    
protected:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    virtual VcpImgEdtScrollLayout* createLayout();    
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);    
    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag){};
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell);
    
private:
    VfxS32      m_cellCount;
    VfxFrame    *m_frameCell[VappImgEdtIesHdlr::EFFECT_TOTAL];
    VfxBool     m_bVertMode;
};

class VappImgEdtEffectPage : public VappImgEdtBasePage
{
VFX_DECLARE_CLASS(VappImgEdtEffectPage);
    
public:
    VappImgEdtEffectPage();
    static void enterEffectPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);
   
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onStateChange(PageState state);
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    
private:
    void onTapEdtBtn(VfxS32 pos, VfxFrame* cell);
    
private:
    VcpImgEdtEffectPanel    *m_effectPanel;
    VfxS32                  m_focusIndex;
};



/***************************************************************************** 
 * Class VappImgEdtFlipPage
 *****************************************************************************/
class VappImgEdtFlipPage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtFlipPage);

    enum flipDirect
    {
        FLIP_DIRECT_UP,
        FLIP_DIRECT_DOWN,
        FLIP_DIRECT_LEFT,
        FLIP_DIRECT_RIGHT,

        FLIP_DIRECT_TOTAL
    };

public:
    VappImgEdtFlipPage();
    virtual void onInit();
    virtual void onDeinit();

    static void enterFlipPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);

protected:
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual void onBottomBtnClicked(VfxObject* obj, VfxId id); 
    
private:
    void createFlipPanel();    
    void onFlipBtnClick(VfxObject* obj, VfxId id);
    void onFlipFinished(VfxFrame *frame, VfxBool isFinished);

private:
    srv_ies_preview_handle   m_avatarPreview;
    VcpImgEdtPreviewLayer   *m_imageView;
    VcpImgEdtPreviewLayer   *m_avatarFrame;
    VcpFrameEffect          *m_effectBefore;
    VcpFrameEffect          *m_effectAfter;
    VcpImageButton          *m_flipBtn[4];
    VfxFrame                *m_borderFrame;
};

/***************************************************************************** 
 * Class VappImgEdtFramePage
 *****************************************************************************/
class VappImgEdtFramePage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtFramePage);

public:
    VappImgEdtFramePage();
    static void enterFramePage(VappImgEdtBasePage **page, VfxObject* parent, void *param);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onStateChange(PageState state);
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);

private:
    void onTapEdtBtn(VfxS32 pos, VfxFrame* cell);

private:
    VfxResId            m_firstFrameId;
    VcpImgEdtFramePanel *m_framePanel;
    VfxS32               m_focusIndex;
    VfxBool             m_noFrame;
};

class VcpImgEdtCtrlFrame : public VfxControl
{
    enum BtnCorner
    {
        CORNER_LEFT_UP,
        CORNER_LEFT_DOWN,
        CORNER_RIGHT_UP,
        CORNER_RIGHT_DOWN,

        CORNER_TOTAL 
    };
    enum HideFrameDirect
    {
        DIRECT_UP,
        DIRECT_DOWN,
        DIRECT_LEFT,
        DIRECT_RIGHT,
        
        DIRECT_TOTAL
    };
    enum CtrlStates
    {
        CTRL_STATE_NONE,
        CTRL_STATE_MOVE,
        CTRL_STATE_RESIZE,

        IMGEDT_ICON_CTRL_TOTAL
    };

public:
    VcpImgEdtCtrlFrame();
    void setContentFrame(VfxFrame* frame, VfxRect bgRect);
    void setContentFrame(VfxFrame* frame, VfxPoint iconPos, VfxRect bgRect);
    void setResizeEnabled(VfxBool bEnabled);
    VfxRect getIconRect();
    void setDetectRect(VfxRect &rect);
    void setBgMaxRect(VfxRect &maxRect);
    void setHideFrameDisabled(VfxBool isDisabled);

    VfxSignal0  m_signalDetectAreaTouched;

protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

private:
    void updateLayout();
    VfxBool onPenDownCheck(VfxPenEvent &event);
    void onIconMove(VfxPenEvent &event);
    void onIconResize(VfxPenEvent &event);
    VfxBool checkInputValid(VfxPoint pos);
    void resetValidRect();
    void ajustInputPos(VfxPoint &pos);
    void setBtnFocus(VfxBool bFocus);
    void setEdgeFrameFocus(VfxBool bFocus);

private:
    VfxFrame       *m_cornerBtn[CORNER_TOTAL];
    VfxFrame       *m_hideFrame[DIRECT_TOTAL];
    VfxFrame       *m_contentFrame;
    VfxFrame       *m_edgeFrame;
    VfxFrame       *m_btnHL;

    CtrlStates      m_ctrlState;
    VfxS32          m_focusBtnInx;
    VfxPoint        m_movePole;
    VfxSize         m_orgSize;
    VfxRect         m_maxRect;
    VfxRect         m_curRect;
    VfxBool         m_bSupportResize;
    VfxBool         m_resetResizeInfo;
    VfxRect         m_validResizeRect;
    VfxRect         m_detectRect;
};


class VappImgEdtIconPage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtIconPage);
    
    enum BottomBtnType
    {
        BOTTOM_BTN_SHOW_ICON = VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_EX
    };

public:
    VappImgEdtIconPage();
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    static void enterIconPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);
    void setClipArtIcon(VfxResId id);

protected:
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onStateChange(PageState state);
    virtual void onZoomStart();
    virtual void onZoomEnd();

private:
    void createIconSelector();
    void onIconSelected(VfxS32 pos);
    void onMattsPopupCanceled();
    void onMattsPopupStateChange(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void onBottomTouched();

private:
    VcpImgEdtCtrlFrame          *m_iconCtrlFrame;
    VcpImgEdtMattsPopup         *m_iconPopup;
    VcpImgEdtIconCellProvider   m_provider;
    VfxFrame                    *m_iconFrame;
    VfxResId                    m_iconId;
    VfxS32                      m_iconIndex;
    VfxBool                     m_firstEnter;
    VfxBool                     m_exitPage;
};


/***************************************************************************** 
 * Class VappImgEdtTextPage
 *****************************************************************************/
class VappImgEdtTextPage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtTextPage);

private:
    enum BottomBtnType
    {
        BOTTOM_BTN_SHOW_TEXT = VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_EX,
        BOTTOM_BTN_SHOW_COLOR,
        BOTTOM_BTN_TEXT_L1,
        BOTTOM_BTN_TEXT_L2,
        BOTTOM_BTN_TEXT_L3,
        BOTTOM_BTN_TEXT_L4
    };

    enum CtrlObject
    {
        CTRL_OBJ_NONE,
        CTRL_OBJ_TEXT,
        CTRL_OBJ_IMAGE,

        CTRL_OBJ_TOTAL
    };

    enum TextFontSize
    {
        FONT_SIZE_L1,
        FONT_SIZE_L2,
        FONT_SIZE_L3,
        FONT_SIZE_L4,

        FONT_SIZE_TOTAL
    };

public:
    VappImgEdtTextPage();
    static void enterTextPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);
    void setTextContent(VfxWString &str);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onZoomStart();
    virtual void onZoomEnd();
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onStateChange(PageState state);

private:
    void onTextPopupBtnClick(VfxObject* sender, VcpInputPopupButtonEnum type);
    void onTextPopupStateChange(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void updateTextColor();
    void updateTextFrame();
    void prepareTextInfo();
    VfxBool recreateText();
    void redrawText();
    void createColorSelector();
    void onColorPopupState(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    void onColorSelected(VfxS32 pos);
    void onBottomTouched();
    void onPageExitTimeout(VfxTimer *timer);

private:
    VcpInputPopup           *m_textPopup;
    VcpImgEdtCtrlFrame      *m_textCtrlFrame;
    VfxFrame                *m_textFrame;
    VcpImgEdtMattsPopup     *m_colorPopup;
    VfxU8                   *m_buff;    

    GDI_HANDLE               m_gdiHdl;
    VfxSize                  m_strSize;
    VfxSize                  m_imgSize;
    VfxSize                  m_textFrameSize;
    VfxS32                   m_fontIndex;
    VcpImgEdtColorCellProvider m_provider;
    VfxWString               m_string;
    VfxS32                   m_colorIndx;
    VfxS32                   m_fontSize[FONT_SIZE_TOTAL];
    VfxBool                  m_firstEnter;
    VfxBool                  m_exitPage;
};

/***************************************************************************** 
 * Class VappImgEdtDoodlePage
 *****************************************************************************/
class VappImgEdtDoodlePage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtDoodlePage);

protected:
    enum DoodlePenSize
    {
        PEN_SIZE_L1,
        PEN_SIZE_L2,
        PEN_SIZE_L3,
        PEN_SIZE_L4,
        PEN_SIZE_L5,

        PEN_SIZE_TOTAL
    };

    enum DoodleEraseSize
    {
        ERASE_SIZE_L1,
        ERASE_SIZE_L2,
        ERASE_SIZE_L3,
        ERASE_SIZE_L4,
        ERASE_SIZE_L5,

        ERASE_SIZE_TOTAL
    };

    enum BottomBtnType
    {
        BOTTOM_BTN_SHOW_SIZE = VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_EX,
        BOTTOM_BTN_SHOW_COLOR,
        BOTTOM_BTN_SHOW_ERASE,
        BOTTOM_BTN_L2_1,
        BOTTOM_BTN_L2_2,
        BOTTOM_BTN_L2_3,
        BOTTOM_BTN_L2_4,
        BOTTOM_BTN_L2_5,

        BOTTOM_BTN_TOTAL
    };

public:
    VappImgEdtDoodlePage();  
    static void enterDoodlePage(VappImgEdtBasePage **page, VfxObject* parent, void *param);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackwrd);
    virtual void onExit(VfxBool isBackward);
    virtual void onBack();    
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onHintBtnClicked(VfxObject *obj, VfxId id);
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    virtual void onStateChange(PageState state);
    //stroke
    virtual VfxS32 setAjustStateEnd();
    virtual void startStroke();
    virtual void updateStroke();
    virtual void endStroke();
    virtual void getStrokeRect(VfxPenStrokeHandWritingRegion &area);

    virtual VfxS32 doodleCommand(VfxPoint start, VfxPoint end);
    virtual VfxS32 doodleRender(VfxBool forceRender);
    virtual void createBottomBar();
    virtual void setDoodleSize(VfxBool isPen, VfxS32 index);
    virtual void onColorSelected(VfxS32 pos); 
    virtual void onPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state);
    virtual void onHideBtnStateChanged(VfxBool isDown);

private:
    void updateBottomBarL2(VfxBool isPen);
    void createColorSelector();

protected:
    VcpImgEdtMattsPopup     *m_selectPopup;
    VcpImgEdtColorCellProvider m_colorProvider;

    VfxBool                 m_bStrokeMode;
    VfxBool                 m_bAdjustState;    
    VfxPenStrokePoint       m_strokePoint[10];
    BottomBtnType           m_activeBtn;
    VfxPoint                m_lastDoodlePos;
    VfxU32                  m_lastUpdateTick;

    VfxS32                  m_penSizeIndx;
    VfxS32                  m_penSize[PEN_SIZE_TOTAL];
    VfxS32                  m_eraseSizeIndx;
    VfxS32                  m_eraseSize[ERASE_SIZE_TOTAL];
    VfxS32                  m_colorIndx;
    VfxColor                m_color;
};

/***************************************************************************** 
 * Class VappImgEdtDoodlePage2
 *****************************************************************************/
class VappImgEdtDoodlePage2 : public VappImgEdtDoodlePage
{
    VFX_DECLARE_CLASS(VappImgEdtDoodlePage2);

private:
    enum DoodleSelectType
    {
        SELECT_PEN_SIZE,
        SELECT_PEN_COLOR,
        SELECT_ERASE_SIZE,

        SELECT_TOTAL
    };

public:
    VappImgEdtDoodlePage2();  
    static void enterDoodlePage2(VappImgEdtBasePage **page, VfxObject* parent, void *param);

protected:
    virtual void createBottomBar();

private:
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);
    void createSelector(DoodleSelectType type);
    void onPenSelected(VfxS32 pos);
    void onEraseSelected(VfxS32 pos);

private:
    VcpImgEdtPenProvider        m_penProvider;
    VcpImgEdtEraseProvider      m_eraseProvider;
};


/***************************************************************************** 
 * Class VappImgEdtClipPage
 *****************************************************************************/
class VappImgEdtClipPage : public VappImgEdtBasePage
{
    VFX_DECLARE_CLASS(VappImgEdtClipPage);

protected: 
    enum BottomBtnType
    {
        BOTTOM_BTN_SELECT_RATIO = VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_EX,
        BOTTOM_BTN_TOTAL
    };
public:
    enum ClipFrameRatio
    {
        CLIP_RATIO_FREE = 0,
        CLIP_RATIO_ORIGINAL,
        CLIP_RATIO_SCREEN,
        CLIP_RATIO_1_1,
        CLIP_RATIO_3_4,
        CLIP_RATIO_9_16,

        CLIP_RATIO_TOTAL
    };
    
public:
    VappImgEdtClipPage();
    static void enterClipPage(VappImgEdtBasePage **page, VfxObject* parent, void *param);
    void setIsZoom(VfxBool isZoom);
    void setRatioFixed(VfxBool isFixed);
    void setRatio(VfxS32 ratio_w, VfxS32 ratio_h);
    void setRatioSelected(VfxBool is_selected);

protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onZoomEnd();
    virtual void onStateChange(PageState state);
    virtual void onBottomBtnClicked(VfxObject *obj, VfxId id);

protected:
    void showRatioSelPopup();
    void onDragImage(VfxSize &drag);
    void onBottomTouched();
    void onRatioSelectionChanged(VfxObject* sender, VfxU32 index);
    VfxS32 onClip(VfxBool needUpdate = VFX_TRUE);

protected:
    VcpSelectPopup      *m_ratioPopup;
    VcpSlider           *m_slider;
    VcpImgEdtClipWindow *m_clipWd;
    
    VfxRect         m_screenRect;
    VfxRect         m_imgRect;
    ClipFrameRatio  m_ratioMode;
    VfxBool         m_isZoom;
    VfxBool         m_isRatioSelected;
    VfxBool         m_isRatioFixed;

};

/***************************************************************************** 
 * Class VappImgEdtScr
 *****************************************************************************/
class VappImgEdtScr : public VappImgEdtBaseScr
{
    VFX_DECLARE_CLASS(VappImgEdtScr);

public:
    virtual void on1stReady();    
	virtual void on2ndReady();
    void enterEditPage(VfxS32 pos, void *param);

public:
    VappImgEdtPreviewPage   *m_previewPage;
    VappImgEdtBasePage      *m_editPage;
};  

class VappImgEdtApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappImgEdtApp);
    
public:
    VappImgEdtApp();

public:
    VfxU8* getPreviewLayerMem();
    VfxU8* getAvatarLayerMem();
    VfxU8* getTextLayerMem(VfxS32 size);
    void discardLastTextMem();
    
    VfxWString getFileName();
    VfxWString &getNewFilePath(VfxWString &name);
    VfxWString &getNewFilePath();
    VfxScrRotateTypeEnum getRotation();
    VfxWString getSrcFilePath()
    {
        return m_srcFilePath;
    };
    
protected:
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    void prepareMem();
    void unPrepareMem();

private:
    //memory for create GDI layer
    VappImgEdtScr       *m_imgEdtScr;
    void*       m_pMemPool;
    KAL_ADM_ID  m_poolId;
    void*       m_pIesSrvMem;
    void*       m_pPreviewLayerMem;
    void*       m_pAvatarLayerMem;
    void*       m_pTextLayerMem[IMGEDT_ADD_TEXT_MAX_COUNT];
    //naming
    VcpImgEdtNamingHelper   *m_namingHelper;
    VfxWString              m_srcFilePath;
    VfxWString              m_destFilePath;
    //rotataion
    vapp_imgedt_scr_rotate_enum m_rotate;
};

#endif /* __MMI_COSMOS_PHOTOEDITOR__ */
#endif /* __VAPP_PHOEDT_H__ */

