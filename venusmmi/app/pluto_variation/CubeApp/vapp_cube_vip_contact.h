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
 *  vapp_cube_vip_contact.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  vip contact screen
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_CUBE_VIP_CONTACT_H__
#define __VAPP_CUBE_VIP_CONTACT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_3D_CUBE_APP__

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vdat_include.h"

#include "vapp_cube_scr.h"
#include "HomeScreen\vapp_hs_cp.h"

#include "vapp_cube_vip_contact_list_ctrl.h"



/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef VappHsDndImage VappCubeDndImage;

/***************************************************************************** 
 * helper class : VappCubeButton
 *****************************************************************************/
class VappCubeButton : public VcpButtonInternal
{
// Declaration
public:
    VappCubeButton();

    // the string on button
    void setText(const VfxWString &string);
    void setBgResId(const VfxS32 &resId);
    void setDownResId(const VfxS32 &resId);
    void setUpResId(const VfxS32 &resId);
    
//override
protected:
    virtual void onInit(void);
    
private:
    
    VfxTextFrame  *m_frmText;
    VfxImageFrame *m_frmBg;
};


/***************************************************************************** 
 * helper class : VappCubeAnimateControl
 *****************************************************************************/
class VappCubeAnimateControl : public VfxControl
{
public:
    enum
    {
#ifdef __MMI_MAINLCD_240X320__
        IMG_POS_X = 103,
        IMG_POS_Y = 35,
        TEXT_POS_X = 12,
        TEXT_POS_Y = 80,
        TEXT_WIDTH = 216,
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA */
        IMG_POS_X = 103,
        IMG_POS_Y = 35,
        TEXT_POS_X = 12,
        TEXT_POS_Y = 80,
        TEXT_WIDTH = 216,
#else   /* HVGA, 320 480*/
        IMG_POS_X = 138,
        IMG_POS_Y = 38,
        TEXT_POS_X = 16,
        TEXT_POS_Y = 92,
        TEXT_WIDTH = 288,
#endif
        TEXT_HEIGHT = 26,
        ENUM_TOTAL
    };
// Declaration
public:
    VappCubeAnimateControl();
    VappCubeAnimateControl(const VfxS32 &startResId, const VfxS32 &resCount);
    
    void startAnimate(void);
    void stopAnimate(void);
    void setRes(const VfxS32 &startResId, const VfxS32 &resCount);
    void setDuration(const VfxU16 &mesc);
    
protected:
    virtual void onInit(void);
    
private:
    void onTimerExpire(VfxTimer * source);
    
private:
    VfxImageFrame *m_frmImage;
    VfxTextFrame  *m_frmText;
    VfxTimer      *m_timerTick;
    VfxS32         m_sStartResId;
    VfxS32         m_nCount;
    VfxU16         m_nDuration;
};

/***************************************************************************** 
 * helper Class VappCubeContactDndImage
 *****************************************************************************/
class VappCubeContactDndImage : public VappCubeDndImage
{
public:
    VappCubeContactDndImage();

// Method
public:
    enum{
        DRAG_MOVE_OFFSET_TABLE_SIZE  = 8,
        DRAG_EFFECT_RANDOM_DELAY = 100,
        SHAKE_DURATION = 200,
#ifdef __MMI_MAINLCD_240X320__ /* QVGA*/
        IMAGE_WIDTH = 63,
        IMAGE_HEIGHT = 60,
        IMAGE_POS_X = 8,
        IMAGE_POS_Y = 8,
#elif defined(__MMI_MAINLCD_240X400__) /* WQVGA*/
        IMAGE_WIDTH = 75,
        IMAGE_HEIGHT = 71,
        IMAGE_POS_X = 9,
        IMAGE_POS_Y = 9,        
#else //__MMI_MAINLCD_320X480__   /* HVGA*/
        IMAGE_WIDTH = 89,
        IMAGE_HEIGHT = 87,
        IMAGE_POS_X = 10,
        IMAGE_POS_Y = 8,
#endif
        ENUM_TOTAL
    };
    
    // Set background image
    void setImage(
        const VfxS32 &value     // [IN] reource id
        );
    void setCenterImage(const VfxWString &value);
    void setCenterImage(const VfxS32 &value);
    // Get image path
    VfxWString getImageSrc(void) const;
    const VfxS32 getImageResId(void) const;
    // Set Image state, Only at edit mode, 
    // this will capture the pen event
    void setEditmode(
        const VfxBool &bEdit    //[IN] be edit or not
        );

    void setText(const VfxWString &text);

    // return image's hint string
    const VfxWString getText(void) const;

    // shake the anchor point
    void startShake(void);
    
    // stop shaking.
    void stopShake(void);

    // return the pos before shaking
    const VfxPoint &getPrevPos(void) const;
    void setPrevPos(const VfxPoint &point);
    
// Override
protected:
    // On init
    virtual void onInit();

    // On pen input
    // RETURNS: VfxBool
    virtual VfxBool onPenInput(
        VfxPenEvent &event  // [IN] pen event
    );
    
private:
    
    VfxFPointTimeline *m_tlAnchor;
    VfxTextFrame      *m_frmText;
    VfxImageFrame     *m_frmCenterImage;

    VfxPoint m_ptPrevPos; // the position before it start to shake
    VfxS32   m_eState;    // Image state
};


/***************************************************************************** 
 * Class VappContactControl
 *****************************************************************************/
class VappContactControl : public VfxControl
{
// Constructor / Destructor
public:
    VappContactControl();

    typedef void (VappContactControl::*BtnHandler)(void);
    
    typedef struct {
        VfxU16 imgUp;
        VfxU16 imgDown;
        VfxU16 imgBg;
        VfxU16 imgDisable;
        BtnHandler handler;
    }ButtonConfig;
// Method
public:
    enum
    {
#ifdef __MMI_MAINLCD_240X320__
        BTN_TRASH_X = 5,
        BTN_TRASH_Y = 19,
        BTN_CLOSE_X = 176,
        BTN_CLOSE_Y = BTN_TRASH_Y,
        BTN_CALL_X = 14,
        BTN_CALL_Y = 213,
        BTN_SMS_X = 120,
        BTN_SMS_Y = BTN_CALL_Y,
        TXT_TITLE_Y = BTN_TRASH_Y,
        CENTER_IMAGE_X = 16,
        CENTER_IMAGE_Y = 67,
        CENTER_IMAGE_WIDTH = 208,
        CENTER_IMAGE_HEIGHT = 136,
#elif defined(__MMI_MAINLCD_240X400__)
        BTN_TRASH_X = 5,
        BTN_TRASH_Y = 19,
        BTN_CLOSE_X = 176,
        BTN_CLOSE_Y = BTN_TRASH_Y,
        BTN_CALL_X = 14,
        BTN_CALL_Y = 211,
        BTN_SMS_X = 120,
        BTN_SMS_Y = BTN_CALL_Y,
        TXT_TITLE_Y = BTN_TRASH_Y,
        CENTER_IMAGE_X = 16,
        CENTER_IMAGE_Y = 67,
        CENTER_IMAGE_WIDTH = 208,
        CENTER_IMAGE_HEIGHT = 136,
#else // HVGA
        BTN_TRASH_X = 0,
        BTN_TRASH_Y = 2,
        BTN_CLOSE_X = 222,
        BTN_CLOSE_Y = BTN_TRASH_Y,
        BTN_CALL_X = 19,
        BTN_CALL_Y = 264,
        BTN_SMS_X = 161,
        BTN_SMS_Y = BTN_CALL_Y,
        TXT_TITLE_Y = BTN_TRASH_Y,
        CENTER_IMAGE_X = 22,
        CENTER_IMAGE_Y = 76,
        CENTER_IMAGE_WIDTH = 276,
        CENTER_IMAGE_HEIGHT = 181,
#endif
        ENUM_TOTAL
    };
    
    typedef enum
    {       
        BTN_CALL,   // Make call
        BTN_SMS,    // Send SMS or MMS
        
        // Add new button enum before this enum
        BTN_TRASH,
        BTN_CLOSE,
        BTN_TOTAL
    }Button;

    void setTitle(const VfxWString &title);
    const VfxWString &getTitle(void) const;
    
    void setImage(const VfxS32 &resId);
    void setImage(const VfxWString &src);

    // enable or disable the button
    void enableBtn(
            const VappContactControl::Button &btn, //[IN] button handle
            const VfxBool &bEnable                 //[IN] enable or disable
            );

//Signal
public:
    VfxSignal1<Button >  m_signalAction;
    
// Override
protected:
    virtual void onInit();
    
// Overridable

    // add function button's config
    virtual void configCustomButton(void);
    
private:
    void onBtnTrashDown(void);
    void onBtnCloseDown(void);
    
    void onBtnCall(void);   //Make call
    void onBtnSms(void);    // Send SMS
    void onBtnTrash(void);  // Clear the current contact info
    void onBtnClose(void);  // Close the current screen.
    void onRotateStop(
        VfxBaseTimeline *timeline, //[IN] time line
        VfxBool stop               //[IN]
        );

private:
    VfxTextFrame  *m_frmTitle;  // Contact name or number
    VfxImageFrame *m_frmImage;  // patrait image
    
    VappCubeButton *m_cpBtn[BTN_TOTAL];
    VfxImage  *m_imgBtnUp[BTN_TOTAL];
    VfxImage  *m_imgBtnDown[BTN_TOTAL];

    // button table
    ButtonConfig m_tblBtnConfig[BTN_TOTAL];

    VfxAnimation *m_Animation;
    
    VfxTransformTimeline *m_tlTrans;
    VfxPointTimeline     *m_tlPoint;
};


/***************************************************************************** 
 * Class VappCubeVipContactScr
 *****************************************************************************/
class VappContactNumberFrame : public VfxControl
{
public:
    VappContactNumberFrame();

    enum
    {
#ifdef __MMI_MAINLCD_240X320__
        LIST_ITEM_HEIGHT = 44,
        LEFT_TEXT_MARGIN = 36,
        LEFT_LIST_MARTIN = 5,
        BTN_SWITCH_X = 176,
        BTN_SWITCH_Y = 19,
        FRM_LIST_X = 8,
        FRM_LIST_Y = 80,
        FRM_LIST_WIDTH = 223,
        TITLE_WIDTH = 224,
        TITLE_HEIGHT = 52,
        TITLE_POS_X = 8,
        TITLE_POS_Y = 19,
#elif defined(__MMI_MAINLCD_240X400__)
        LIST_ITEM_HEIGHT = 44,
        LEFT_TEXT_MARGIN = 36,
        LEFT_LIST_MARTIN = 5,
        BTN_SWITCH_X = 176,
        BTN_SWITCH_Y = 19,
        FRM_LIST_X = 8,
        FRM_LIST_Y = 80,
        FRM_LIST_WIDTH = 223,
        TITLE_WIDTH = 224,
        TITLE_HEIGHT = 52,
        TITLE_POS_X = 8,
        TITLE_POS_Y = 19,
#else // HVGA
        LIST_ITEM_HEIGHT = 54,
        LEFT_TEXT_MARGIN = 36,
        LEFT_LIST_MARTIN = 5,
        BTN_SWITCH_X = 222,
        BTN_SWITCH_Y = 2,
        FRM_LIST_X = 11,
        FRM_LIST_Y = 90,
        FRM_LIST_WIDTH = 297,
        TITLE_WIDTH = 297,
        TITLE_HEIGHT = 99,
        TITLE_POS_X = 0,
        TITLE_POS_Y = 2,
#endif
        ENUM_TOTAL
    };
    
public:
    // insert list content
    void insertContent(
        const VfxWString &string,  //[IN]string
        const VfxU32 flag          //[IN]number flag
        );

    void setTitle(
        const VfxWString &title   //[IN]title
        );
    
    // set current hilite item
    void setCurrSel(
        const VfxU8 &nSel         //[IN]selected index
        );
    
protected:
    virtual void onInit();
    
// signal
public:
    VfxSignal1<void *> m_signalNumSel;
    
private:

    VappListCtrl *m_lstNumber;
    VfxTextFrame *m_frmTitle;
    VappCubeButton    *m_cpBtnSwitch;   // switch back to contact screen
};


/***************************************************************************** 
 * Class VappCubeVipContactScr
 *****************************************************************************/
#define CONTACT_ROTATE_TIME 750
#define INVALID_CONT_INDEX  0xFFFF

class VcpFrameEffect;

class VappCubeVipContactScr : public VappCubeScr
{
    VFX_DECLARE_CLASS(VappCubeVipContactScr);

// Declaration
public:
    
	enum{
		TOTAL_CONTACTS = 6,

        SWAP_THRESHHOLD = 30,   // To judge whether the two image is close enough
        CONT_NUM_LENGTH = 40,
#ifdef __MMI_MAINLCD_240X320__
        LOADING_POS_X = 0,      // Loading frame's position
        LOADING_POS_Y = 48,
        MATRIX_TOP_Y_POS = 27,
        VERT_MARTIN = 3,        // Margin between dnd images
        HORI_MARGIN = 16,
        CONTACT_CONTROL_POS_X = 0,
        CONTACT_CONTROL_POS_Y = 2,
#elif defined(__MMI_MAINLCD_240X400__)
        LOADING_POS_X = 0,
        LOADING_POS_Y = 82,
        MATRIX_TOP_Y_POS = 39,
        VERT_MARTIN = 10,
        HORI_MARGIN = 8,
        CONTACT_CONTROL_POS_X = 0,
        CONTACT_CONTROL_POS_Y = 42,        
#else // HVGA
        LOADING_POS_X = 0,
        LOADING_POS_Y = 115,
        MATRIX_TOP_Y_POS = 46,
        VERT_MARTIN = 17,
        HORI_MARGIN = 14,
        CONTACT_CONTROL_POS_X = 0,
        CONTACT_CONTROL_POS_Y = 43,
#endif
        POS_ENUM_TOTAL
	};
    enum
    {
        STATE_INVALID,
        STATE_IDLE,         // usr can add contact info at this state
        STATE_EDIT,         // At edit state, contact image will be at DnD state.
        STATE_TOTAL
    };

    // When entry phone book to select a contact, 
    //  we need this setting to restore the layout
    struct Setting
    {
        VfxU16 index[TOTAL_CONTACTS]; // vip contact store index
        VfxU8  active;                // the index of active contact
        VfxU8  state;                 // state
    };

    struct ContactNumberInfo
    {
        VfxWString home;
        VfxWString office;
        VfxWString mobile;
        VfxWString fax;
        VfxU32     flag;
    };
    
// Constructor / Destructor
public:
    VappCubeVipContactScr();

// Method
public:
  void onSwitchNotify(void);
  // number list callback
  void onNumberSelect(
        void *user_data         //[IN] the selected item's user data
        );
  
  // update one image contact
  void onUpdateCont(
        const VfxU16 &index     //[IN] the image index
        );
    
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(
        VfxPenEvent &event          //[IN] the pen event
        );

    virtual VfxBool onKeyInput(
        VfxKeyEvent & event
        );
    
// Overidable

    // update the whole content by state
    virtual void updateContent(void);

    //update, may not need update position
    virtual void updatePostion(void);

//Method
private:

    // find the frame index by frame pointer
    const VfxU16 lodateFrameIndex(
        const VappCubeContactDndImage *frame    //[IN] the dragging frame
        );
    
    // find index of the current selected element
    VfxBool findSelect(
        const VfxPoint &point, //[IN]  the hitTest point
        VfxU16 &index          //[OUT] the index of the matrix elem.
        );

    // Zoom in the selected contact image
    void createContactScreen(void);

    // If the contact's number is more than one, list all of them
    void createListScreen(void);

    // At edit mode, user can drag and drop any element
    void showEditScreen(void);

    // reponse to the button
    void actionHandler(
        VappContactControl::Button btn  //[IN]  button name
        );

    // indicate the contact frame is rotated done
    void onRotateContFinish(
        VfxFrame *frame,    //[IN] the retotated frame
        VfxBool finish      //[IN] the action is finished
        );
    
    void onTimerExpire(
        VfxTimer *source    //[IN] timer name
        );

    // On edit mode, response to done button
    void onBtnEditDown(void);
    
    // Handle contact image drag event in edit mode
    void onContactDrag(
        VappCubeDndImage *image, //[IN]  the draged frame
        VfxPenEvent &event       //[IN]  pen event
        );
    
    // Handle contact image Move event in edit mode
    void onContactMove(
        VappCubeDndImage *image, //[IN]  the draged frame
        VfxPenEvent &event       //[IN]  pen event
        );
    
    // Handle contact image Drop event in edit mode
    void onContactDrop(
        VappCubeDndImage *image, //[IN]  the draged frame
        VfxPenEvent &event       //[IN]  pen event
        );
    
    // Handle contact image Abort event in edit mode
    void onContactAbort(
        VappCubeDndImage *image, //[IN]  the draged frame
        VfxPenEvent &event       //[IN]  pen event
        );

    // get image text
    const VfxWString getText(const VfxU16 &index);

    // read out contact's number from phonebook
    void loadNumber(const VfxU16 &index);

    void makeCall(const VfxWChar *number, VfxU32 flag);
    void sendSms(const VfxWChar *number);
    void selectContact(VfxU16 index);

    // contact screen time line callback
    void onContactCreateFinish(VfxBaseTimeline *timeline, VfxBool finish);
    
// Variable
private:
    // This block declares the UI component of the App category.
    VappCubeAnimateControl    *m_animLoading;
    VfxAnimation              *m_Animate;
    VfxRectTimeline           *m_tlRect;
    VfxPointTimeline          *m_tlPos;
    VfxTransformTimeline      *m_tlTransform;
    VappContactNumberFrame    *m_frmNumList;
    VappContactControl        *m_frmCurrCont; // current image to show the 
    
    VappCubeContactDndImage   *m_dndImage[TOTAL_CONTACTS];
    VcpFrameEffect            *m_frmEffectCont;
    VcpFrameEffect            *m_frmEffectList;
    VfxTimer                  *m_tmLongPress; // long press timer
    VfxTimer                  *m_tmRefresh;
    
    VappCubeButton      *m_btnEditDone;
    VfxImageFrame       *m_imgBg;
    VfxU8               m_uCurrCont;
    VfxU8               m_eState;

    VfxImageFrame       *m_imgLoading;
    VfxTextFrame        *m_txtLoading;
    
    Setting             *m_pSetting;
    ContactNumberInfo   m_struContactNumber;

    VfxImageFrame       *m_frmHiliteEffect;
    
    VfxBool             m_bLongPress;
    VfxPoint            m_ptPrevPos;

    VfxSize             m_sizeElem;
    VfxU16              m_uOldIdx;

    VfxPoint            m_posArray[TOTAL_CONTACTS]; // the generated position

    VfxBool m_bSwitching;
};

//inline
inline
VfxFloat VfxCubeSqrt(VfxU32 value)
{
    return (VfxFloat)sqrt((VfxFloat)value);
}

// class-in function pointer
typedef void (VappCubeVipContactScr::*SelContFuncptrType)(const VfxU16 &);
typedef void (VappCubeVipContactScr::*MakeCallFuncptrType)(const VfxWChar *);
typedef void (VappCubeVipContactScr::*BtnDownFuncptrType)(const VfxPoint &);

#endif /* __MMI_VUI_3D_CUBE_APP__ */

#endif /* __VAPP_CUBE_VIP_CONTACT_H__ */


