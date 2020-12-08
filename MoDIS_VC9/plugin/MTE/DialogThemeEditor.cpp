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
 * DialogThemeEditor.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Version dialog
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// DialogThemeEditor.cpp : implementation file
//

#include "stdafx.h"
#include <string>
#include "ColourPickerCB.h"
#include "DialogGotoScreen.h"
#include "DialogThemeEditor.h"
#include "DialogFindComponent.h"
#include "DialogThemeSetting.h"
#include "TCColorDialog.h"
#include "DialogTheme.h"
#include "DialogColor.h"
#include "MTE_Util.h"


#define WM_MTE_SHOW_CURRENT_SCREEN (WM_USER + 100)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern CUIDlg dlg;

extern bool g_thecom_cancel;
extern bool g_notsaved_theme;
bool b_exit_flags = false;	//pinksword
extern int g_MMI_height,g_MMI_width;//pinksword

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeEditor dialog
bool g_hidetheme = true;
extern MMI_theme my_theme;
bool g_init = true;
bool g_screen_cb = false;
bool g_onedit = false;
extern COLORREF 	g_Color;
extern int g_Theme_Lan;
static HWND theme_editor_hwnd;
extern char save_modify_flag[MAX_THEME_NUM][MAX_THEME_COM_NUM];
extern char history_modify_flag[MAX_THEME_NUM][MAX_THEME_COM_NUM];

extern WCHAR SearchResultSC[30];// = { 0x641C, 0x5BFB, 0x7ED3, 0x679C, 0xFF1A, 0x0000 } ;
static int g_VisibleGroupMappingTable[128];
extern UINT* g_pMMIIsGoingToPowerOff;
bool DoShowCurrentScreenInActivateTheme = true  ;
// Owen
using namespace MoDIS::MTE;

static const int ANIMATION_CONTROL_IDS[] =
{
    IDC_ANIMATION_IMAGE_PREVIEWER,
    IDC_ANIMATION_IMAGE_ONE,
    IDC_ANIMATION_IMAGE_TWO,
    IDC_ANIMATION_IMAGE_THREE,
    IDC_ANIMATION_IMAGE_FOUR,
    IDC_ANIMATION_IMAGE_FIVE,
    IDC_ANIMATION_IMAGE_ADD,
    IDC_ANIMATION_IMAGE_REMOVE,
    IDC_ANIMATION_IMAGE_LABEL_ONE,
    IDC_ANIMATION_IMAGE_LABEL_TWO,
    IDC_ANIMATION_IMAGE_LABEL_THREE,
    IDC_ANIMATION_IMAGE_LABEL_FOUR,
    IDC_ANIMATION_IMAGE_LABEL_FIVE,
    IDC_ANIMATION_DELAY,
    IDC_ANIMATION_LABEL_DELAY,
    IDC_BUTTON_DELAY_SETTING,
    IDC_ANIMATION_REPEAT,
    IDC_ANIMATION_LABEL_REPEAT
};

static const int NUM_ANIMATION_CONTROLS =
    sizeof(ANIMATION_CONTROL_IDS) / sizeof(ANIMATION_CONTROL_IDS[0]);

static const int IMAGE_BLOCK_CONTROL_IDS[] =
{
    IDC_ANIMATION_IMAGE_ONE,
    IDC_ANIMATION_IMAGE_TWO,
    IDC_ANIMATION_IMAGE_THREE,
    IDC_ANIMATION_IMAGE_FOUR,
    IDC_ANIMATION_IMAGE_FIVE
};

static const int NUM_IMAGE_BLOCKS =
    sizeof(IMAGE_BLOCK_CONTROL_IDS) / sizeof(IMAGE_BLOCK_CONTROL_IDS[0]);

static void OutputBitmapToFile(const char *bitmapBuffer,
                               int bitmapWidth,
                               int bitmapHeight,
                               const CString &outputFilename);

static CString GetTempFilename();

CDialogThemeEditor::CDialogThemeEditor(CWnd* pParent,
                                       MMI_MTE_Callback w32_mmi_mte_api_cb)
    : CDialog(CDialogThemeEditor::IDD, pParent),
      m_IsEditingAnimation(false),
      m_AnimationEditingControlIDs(),
      m_ImageBlocks(),
      m_SelectedImageBlock(),
      m_BitmapViewer(),
      m_AnimationRepeatCount(),
      m_AnimationDelay(),
      m_IsDialogInitialized(false)
{
	m_pDialogTheme = pParent;
	m_pUIDlg = pParent->GetParent();
	ASSERT(NULL != m_pDialogTheme && NULL != m_pUIDlg);

    goto_screen_dlg = NULL;
    w32_mmi_mte_api = w32_mmi_mte_api_cb;

    // Owen
    ImageBlock::w32_mmi_mte_api = w32_mmi_mte_api_cb;

    m_AnimationEditingControlIDs.insert(
        m_AnimationEditingControlIDs.begin(),
        ANIMATION_CONTROL_IDS,
        ANIMATION_CONTROL_IDS + NUM_ANIMATION_CONTROLS);
	m_theint = 0;  
	m_theintTemp = 0;
	m_nDelaytime = 0;
	m_nDelaytimeTemp = 0;
	m_bautoclose = false;

	//Plugin
	m_nMainLCDWidth = m_nMainLCDHeight = 0;
	
}

void CDialogThemeEditor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogThemeEditor)
	DDX_Text(pDX, IDC_SLICE_LEFT, m_nValueLeft);
	DDX_Text(pDX, IDC_SLICE_RIGHT, m_nValueRight);
	DDX_Text(pDX, IDC_SLICE_TOP, m_nValueTop);
		DDX_Control(pDX, IDC_LIST_THEME_EDITOR, m_ListThemeEditor);
		DDX_Control(pDX, IDC_COMBO_COMPONENT_GROUP_EX, m_ComboComGroup);
		DDX_Control(pDX, IDC_SPECIAL_SCREEN_WARNING, m_StaticWarningScreen);
		DDX_Text(pDX, IDC_EDIT_INTEGER, m_theint);
		DDV_MinMaxUInt(pDX, m_theint, 0, 255);		
		DDX_Text(pDX, IDC_ANIMATION_DELAY, m_nDelaytime);
		DDV_MinMaxUInt(pDX, m_nDelaytime, 0, 1000);
		DDX_Control(pDX, IDC_FILLER_IMAGE, m_st1);
		DDX_Control(pDX, IDC_SCROLLBAR2, m_vbar);
		DDX_Control(pDX, IDC_SCROLLBAR1, m_hbar);
        DDX_Control(pDX, IDC_ANIMATION_IMAGE_PREVIEWER, m_BitmapViewer);
        DDX_Control(pDX, IDC_ANIMATION_REPEAT, m_AnimationRepeatCount);
        DDX_Control(pDX, IDC_ANIMATION_DELAY, m_AnimationDelay);
		DDX_Control(pDX, IDC_SLICE_LEFT, m_SliceLeft);
		DDX_Control(pDX, IDC_SLICE_RIGHT, m_SliceRight);
		DDX_Control(pDX, IDC_SLICE_TOP, m_SliceTop);
		DDX_Control(pDX, IDC_SLICE_BOTTOM, m_SliceBottom);
	DDX_Text(pDX, IDC_SLICE_BOTTOM, m_nValueBottom);
		//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogThemeEditor, CDialog)
	//{{AFX_MSG_MAP(CDialogThemeEditor)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_ERASEBKGND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_COMMAND(ID_FIND_COMPONENT, OnFindComponent)
	ON_COMMAND(ID_GOTO_SCREEN, OnGotoScreen)
	ON_COMMAND(ID_MTE_UG, OnMteUg)
	ON_COMMAND(ID_SETTING, OnSetting)
	ON_COMMAND(ID_MENU_ENGLISH, OnEnglish)
	ON_COMMAND(ID_MENU_SIMCHINESE, OnSimchinese)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPONENT_GROUP_EX, OnSelchangeComponentGroup)
	ON_CBN_DROPDOWN(IDC_COMBO_COMPONENT_GROUP_EX, OnDropdownComponentGroup)
	ON_BN_CLICKED(IDC_COLOR, OnColor)
	ON_BN_CLICKED(IDC_FILLER_C, OnFillerc)
	ON_BN_CLICKED(IDC_FILLER_BC, OnFillerbc)
	ON_BN_CLICKED(IDC_FILLER_AC, OnFillerac)
	ON_BN_CLICKED(IDC_FILLER_SC, OnFillersc)
	ON_BN_CLICKED(ID_THEME_SAVE, OnThemeSave)
	ON_BN_CLICKED(ID_THEME_APPLY, OnThemeApply)
	ON_BN_CLICKED(IDC_CHECK_BOARDER, OnCheckBorder)
	ON_BN_CLICKED(IDC_CHECK_FILLER_BORDER, OnCheckFillerBorder)
	ON_WM_TIMER()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_THEME_EDITOR, OnItemchangedListThemeEditor)
	ON_WM_SIZE()
	ON_WM_SIZING()
	ON_BN_CLICKED(IDC_BUTTON_IMAGE, OnButtonImage)
	ON_BN_CLICKED(IDC_CHECK_TRANSPARENT, OnCheckTransparent)
	ON_BN_CLICKED(IDC_BUTTON_UPINT, OnButtonUpint)
	ON_BN_CLICKED(IDC_BUTTON_DELAY_SETTING, OnButtonSetDelayTime)
	ON_COMMAND(ID_REDO, OnReDo)
	ON_COMMAND(ID_UNDO, OnUnDo)
	ON_WM_MOVE()
    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONDBLCLK()
    ON_BN_CLICKED(IDC_ANIMATION_IMAGE_SEQUENCE, OnAnimationImageSequence)
    ON_BN_CLICKED(IDC_ANIMATION_IMAGE_ADD, OnAnimationImageAdd)
    ON_BN_CLICKED(IDC_ANIMATION_IMAGE_REMOVE, OnAnimationImageRemove)
    ON_EN_CHANGE(IDC_ANIMATION_DELAY, OnChangeAnimationDelay)
    ON_CBN_SELCHANGE(IDC_ANIMATION_REPEAT, OnChangeAnimationRepeat)
	ON_BN_CLICKED(IDC_BUTTON_SILCE_SET, OnButtonSilceSet)
	ON_BN_CLICKED(IDC_FILLER_IMAGE, OnFillerSliceImage)
	ON_BN_CLICKED(IDC_RADIO_SETTING_BOTTOM, OnRadioSettingBottom)
	ON_BN_CLICKED(IDC_RADIO_SETTING_RIGHT, OnRadioSettingRight)
	ON_BN_CLICKED(IDC_RADIO_SETTING_TOP, OnRadioSettingTop)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_RADIO_SETTING_LEFT, OnRadioSettingLeft)
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CLICK, IDC_LIST_THEME_EDITOR, &CDialogThemeEditor::OnNMClickListThemeEditor)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_THEME_EDITOR, &CDialogThemeEditor::OnNMRClickListThemeEditor)
	ON_NOTIFY(LVN_BEGINRDRAG, IDC_LIST_THEME_EDITOR, &CDialogThemeEditor::OnLvnBeginrdragListThemeEditor)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_LIST_THEME_EDITOR, &CDialogThemeEditor::OnLvnBegindragListThemeEditor)
END_MESSAGE_MAP()

BEGIN_EASYSIZE_MAP(CDialogThemeEditor)
	
	EASYSIZE(ID_THEME_APPLY,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(ID_THEME_SAVE,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDCANCEL,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)

	EASYSIZE(IDC_LIST_THEME_EDITOR,ES_BORDER,ES_BORDER,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_GROUP_FILLER,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	
	EASYSIZE(IDC_STATIC_COLOR,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_COLOR,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_COLOR,IDC_STATIC_COLOR,0)
	EASYSIZE(IDC_CHECK_BOARDER,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	
	EASYSIZE(IDC_STATIC_FILLER,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_FILLER,ES_BORDER,0)
	EASYSIZE(IDC_CHECK_TRANSPARENT,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_FILLER,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_REC,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_REC,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_REC2,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_REC2,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_REC_WH,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_REC_WH,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_REC_MWH,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_REC_MWH,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON_IMAGE,ES_BORDER,ES_KEEPSIZE,IDC_BUTTON_IMAGE,ES_BORDER,0)

	EASYSIZE(IDC_STATIC_FILLER_IMAGE,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	
	EASYSIZE(IDC_STATIC_TEXT_COLOR,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_FILLER,IDC_STATIC_FILLER,0)
	EASYSIZE(IDC_STATIC_TEXT_BC,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_FILLER,IDC_STATIC_FILLER,0)

	EASYSIZE(IDC_FILLER_C,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_TEXT_COLOR,IDC_STATIC_TEXT_COLOR,0)
	EASYSIZE(IDC_FILLER_BC,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_TEXT_BC,IDC_STATIC_TEXT_BC,0)
	EASYSIZE(IDC_CHECK_FILLER_BORDER,ES_BORDER,ES_KEEPSIZE,IDC_FILLER_BC,IDC_FILLER_BC,0)
	
	//EASYSIZE(IDC_FILLER_IMAGE,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	EASYSIZE(IDC_FILLER_IMAGE,ES_BORDER,ES_KEEPSIZE,IDC_FILLER_IMAGE,ES_BORDER,0)
	EASYSIZE(IDC_SCROLLBAR1,ES_BORDER,ES_KEEPSIZE,IDC_SCROLLBAR1,ES_BORDER,0)
	EASYSIZE(IDC_SCROLLBAR2,ES_BORDER,ES_KEEPSIZE,IDC_SCROLLBAR2,ES_BORDER,0)

	EASYSIZE(IDC_STATIC_IMAGE,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	
	//EASYSIZE(IDC_IMAGE,ES_BORDER,ES_KEEPSIZE,ES_BORDER,ES_BORDER,0)
	
	EASYSIZE(IDC_STATIC_INTEGER,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_INTEGER,ES_BORDER,0)
	EASYSIZE(IDC_EDIT_INTEGER,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_INTEGER,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON_UPINT,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_INTEGER,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_MAXMIN,ES_BORDER,ES_KEEPSIZE,IDC_STATIC_INTEGER,ES_BORDER,0)

    EASYSIZE(IDC_ANIMATION_IMAGE_SEQUENCE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_PREVIEWER,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_ONE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_TWO,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_THREE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_FOUR,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_FIVE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_ADD,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_REMOVE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_LABEL_ONE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_LABEL_TWO,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_LABEL_THREE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_LABEL_FOUR,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_IMAGE_LABEL_FIVE,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_DELAY,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_LABEL_DELAY,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_REPEAT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_BUTTON_DELAY_SETTING,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
    EASYSIZE(IDC_ANIMATION_LABEL_REPEAT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)

	EASYSIZE(IDC_RADIO_SETTING_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_RADIO_SETTING_TOP,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)

	EASYSIZE(IDC_RADIO_SETTING_LEFT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_RADIO_SETTING_RIGHT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_LEFT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_TOP,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_RIGHT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_STATIC_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_SLICE_TOP,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_SLICE_LEFT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_SLICE_RIGHT,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_SLICE_BOTTOM,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)
	EASYSIZE(IDC_BUTTON_SILCE_SET,ES_BORDER,ES_KEEPSIZE,ES_KEEPSIZE,ES_BORDER,0)

END_EASYSIZE_MAP


/////////////////////////////////////////////////////////////////////////////
// CDialogThemeEditor message handlers
int g_idx=0;
/*
void CDialogThemeEditor::OnKillFocusInteger()
{	
	if(m_updateint)
		DrawFlagIcon(g_idx);
	m_updateint = false;
}*/

#define   MINX   620  
#define   MINY   550  
#define   MAXX   1000  
#define   MAXY   1000  
void CDialogThemeEditor::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI)  
{  
     CRect   rectWindow;  
     GetWindowRect(&rectWindow);  
     CRect   rectClient;  
     GetClientRect(&rectClient);  
         //   get   offset   of   toolbars,   scrollbars,   etc.  
     int   nWidthOffset   =   rectWindow.Width()   -   rectClient.Width();  
     int   nHeightOffset   =   rectWindow.Height()   -   rectClient.Height();  
     lpMMI->ptMinTrackSize.x   =   MINX   +   nWidthOffset;  
     lpMMI->ptMinTrackSize.y   =   MINY   +   nHeightOffset;  
     lpMMI->ptMaxTrackSize.x   =   MAXX   +   nWidthOffset;  
     lpMMI->ptMaxTrackSize.y   =   MAXY   +   nHeightOffset;  
}   

void CDialogThemeEditor::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	UPDATE_EASYSIZE;

    if (!m_IsDialogInitialized)
    {
        return;
    }

	if(m_AddImage)
		DrawNonBitmap();
	else
		ShowBMP();
	Invalidate();

    // Owen
    for (int i=0; i<NUM_IMAGE_BLOCKS; i++)
    {
        const CRect imageRect(GetControlRect(IMAGE_BLOCK_CONTROL_IDS[i]));
        const CRect selectionRect(imageRect + CRect(2, 2, 2, 2));

        m_ImageBlocks[i].SetImageRect(imageRect);
        m_ImageBlocks[i].SetSelectionRect(selectionRect);
    }
}

void CDialogThemeEditor::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);
	EASYSIZE_MINSIZE(555,545,fwSide,pRect);
	Invalidate();
}
void CDialogThemeEditor::OnMove(int x, int y) 
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	
	
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	CDialog::OnMove(x, y);
	Invalidate();
}

UI_filled_area *CDialogThemeEditor::GetNewFiller()
{
		
		UI_filled_area *ptr;
		ptr = new UI_filled_area;
		ptr->b =NULL;
		ptr->gc = new gradient_color;
		ptr->gc->c = new color;
		ptr->gc->p = new unsigned char;
		return ptr;
}

void CDialogThemeEditor::OnCheckFillerBorder()
{
 	CButton *pBtn=NULL;
	pBtn = (CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER);
	const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		if (pBtn->GetCheck())
		{
			pBtn->SetCheck(0);
		}
		else
		{
			pBtn->SetCheck(1);
		}
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
       m_pUIDlg->EnableWindow(true);
		return;
	}
	if(pBtn->GetCheck())
	{
		
		
		CString fillerthem;
		GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
		if(fillerthem!="")
		{
				mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
				UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
				//UI_filled_area *mod_filler = new UI_filled_area;
				//memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
				
				UI_filled_area *mod_filler = GetNewFiller();//new UI_filled_area;
				if(*old_filler!=NULL)
					memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));				
				mod_filler->flags =0;
				mod_filler->c.r =GetRValue(m_FillerC);
				mod_filler->c.g = GetGValue(m_FillerC);
				mod_filler->c.b = GetBValue(m_FillerC);
				mod_filler->c.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
				mod_filler->b = NULL;
				*old_filler = mod_filler;
				if( m_AddImage )  
					ActivateTheme((MMI_theme *)&my_theme);
				//flag[m_filler_themeid]=true;
				SetFlag(m_filler_themeid);
				int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
				if(idx!=-1) DrawFlagIcon(idx);
				
				if(m_AddImage)
				{
					GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
					m_AddImage = true;
					DrawNonBitmap();
				}
				DrawThemeComponent();
				
				InsertFillerHistory(m_filler_themeid,mod_filler);
				ComHistroy[m_filler_themeid]++;
				ComIdxHistroy[m_filler_themeid]++;
				g_onedit = true;
				g_screen_cb = true; //Update at next refresh
				if( m_AddImage )  
				{
					UpdateListThemeOnDiffTheme();
				    if (SelectItemByComponentName(componentName))
				    {
				        m_ListThemeEditor.SetFocus();
						DrawGreenFlag (m_filler_themeid);
				    }						
				}
		}
	}
	else
	{
			
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
			
			
            if(!(the_component->filler_flag&MMI_MTE_FILLER_ALLOW_BORDER))
            {
				m_pUIDlg->EnableWindow(false);
                ::MessageShow("This filler cannot use border.");
				m_pUIDlg->EnableWindow(true);
				
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
                Invalidate();

                if (SelectItemByComponentName(componentName))
                {
                    m_ListThemeEditor.SetFocus();
                }
                return;	
            }

			UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			UI_filled_area *mod_filler = GetNewFiller();//new UI_filled_area;
			if(*old_filler!=NULL)
				memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			mod_filler->flags =0|UI_FILLED_AREA_SINGLE_BORDER;
			mod_filler->border_color.r =GetRValue(m_FillerBC);
			mod_filler->border_color.g = GetGValue(m_FillerBC);
			mod_filler->border_color.b = GetBValue(m_FillerBC);
			mod_filler->border_color.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			mod_filler->b = NULL;
			*old_filler = mod_filler;
			ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_filler_themeid]=true;
			SetFlag(m_filler_themeid);
			int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
		    if(idx!=-1) DrawFlagIcon(idx);
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			DrawNonBitmap();
			if(m_AddImage)//m_filler_image_data_buffer!=NULL)
			{
				m_AddImage = true;
				//GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
				//Invalidate();
			}
			DrawThemeComponent();
			InsertFillerHistory(m_filler_themeid,mod_filler);
			ComHistroy[m_filler_themeid]++;
			ComIdxHistroy[m_filler_themeid]++;
			g_onedit = true;
			g_screen_cb = true; //Update at next refresh
			UpdateListThemeOnDiffTheme();
		    if (SelectItemByComponentName(componentName))
		    {
		        m_ListThemeEditor.SetFocus();
				DrawGreenFlag (m_filler_themeid);
		    }			
			//((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);
	}
	
    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::OnCheckBorder()
{
    CButton *checkBox = (CButton *) GetDlgItem(IDC_CHECK_BOARDER);
    ASSERT(checkBox != NULL);

    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		if (checkBox->GetCheck())
		{
			checkBox->SetCheck(0);
		}
		else
		{
			checkBox->SetCheck(1);
		}
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}

	if(!checkBox->GetCheck())
	{
		checkBox->SetCheck(1);
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please uncheck transparent by clicking the color box.");
		m_pUIDlg->EnableWindow(true);
		Invalidate();
		if (SelectItemByComponentName(componentName))
		{
			m_ListThemeEditor.SetFocus(); 	
		}			
		return;
	}
    if (checkBox->GetCheck())
    {
        m_ColRef = RGB(0,0,255);
        DrawThemeComponent();
            
        color **c = static_cast<color **>(GetComponentAddr(&my_theme,
                                                           m_color_themeid));
        *c          = new color;
        (*c)->r     = GetRValue(m_ColRef);
        (*c)->g     = GetGValue(m_ColRef);
        (*c)->b     = GetBValue(m_ColRef);
        (*c)->alpha = GetDlgItemInt(IDC_EDIT_ALPHA);

        ActivateTheme(&my_theme);
        SetFlag(m_color_themeid);

        InsertColorHistory(m_color_themeid, **c);
        ComHistroy[m_color_themeid]++;
        ComIdxHistroy[m_color_themeid]++;

        int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
        if (idx != -1)
        {
            DrawFlagIcon(idx);
        }

        g_onedit = true;
        UpdateListThemeOnDiffTheme();
		g_screen_cb = true; //Update at next refresh
		if (SelectItemByComponentName(componentName))
		{
		    m_ListThemeEditor.SetFocus();
			DrawGreenFlag (m_color_themeid);
		}		
    }
    else
    {
        if (ComIdxHistroy[m_color_themeid] != 0)
        {
            UnDoComponent();
        }
        else
        {
	        GetDlgItem(IDC_COLOR)->EnableWindow(TRUE);
        }
    }

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

typedef	void (*CB_SWITCH_SCREEN)(void);
bool g_showcurrent = false;
void __stdcall switch_screen_cb(void)
{
	if(g_screen_cb) // mean implies CDialogThemeEditor Show 
	{
		OutputDebugString("//////////////Set g_showcurrent = true;/////////////\n");
		g_showcurrent = true;		
	}
}

void CDialogThemeEditor::OnTimer(UINT nIDEvent) 
{
	if (b_exit_flags)
	{
	    KillTimer(101);
		return;
	}
	if(m_test)
	{
		Invalidate();
		m_test = false;
	}
	if(g_showcurrent)
	{
		OutputDebugString("OnTimer\n");
        Sleep(200);
		OutputDebugString("pass1\n");
		if (m_bShowNoEditPop)
		{
			m_bShowNoEditAgain = false; 
		}
		if (b_exit_flags)
		{
	       // KillTimer(101);
			return;
		}

		ShowCurrentScreen();	
		OutputDebugString("pass2\n");
		mmi_mte_return_code_enum erronum = mmi_mte_is_controlarea_in_current_screen();	
		if (MMI_MTE_SUCCESS == erronum)
		{
			if ( m_ComboComGroup.GetCurSel()== 1)
			m_StaticWarningScreen.ShowWindow(SW_SHOW);
		}
		else
		{
			m_StaticWarningScreen.ShowWindow(SW_HIDE);
		}
		g_showcurrent = false;	
	}
}
void CDialogThemeEditor::OnOK() 
{
	CDialog::OnOK();
}
void CDialogThemeEditor::OnThemeApply()
{
	//There will be something wrong if we do this when the component type is FILLER
	if (m_typestr.CompareNoCase("FILLER")!=0)
	{
		ThemeComEdit();
	}
	else
	{
		if(IsEditingAnimation())
		{
			CString str;
			str.Format(_T("%d"), m_nDelaytime);
			m_AnimationDelay.SetWindowText(str);
			m_AnimationRepeatCount.SetCurSel((m_nrepeatCount == 1) ? 0 : 1);
		}
		else
			UpdateData(FALSE);
	}
    const CString componentName(GetSelectedComponentName());

	if (g_onedit)
	{
		g_onedit = false;
		memcpy(((CDialogTheme*)m_pDialogTheme)->m_edit_theme_list[m_theme_idx],&my_theme, sizeof(MMI_theme));
		g_notsaved_theme = true;
		for( int i=0;i<MAX_THEME_COM_NUM;i++)//2 mean temp saving
		{
			if(save_modify_flag[m_theme_idx][i]==2)
			{
				history_modify_flag[m_theme_idx][i]=1;
				save_modify_flag[m_theme_idx][i]=1;
			}
		}
		UpdateListTheme();

		for(int p=0;p<MAX_THEME_COM_NUM;p++)
		{
			
			ComHistroy[p]=0;
			ComIdxHistroy[p]=0;

			first_touch[p] = false;
			map_color[p].clear();
			map_filler[p].clear();
			map_image[p].clear();
		}
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Done");
		m_pUIDlg->EnableWindow(true);
	}

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::ThemeSave()
{
	//There will be something wrong if we do this when the component type is FILLER
	if (m_typestr.CompareNoCase("FILLER")!=0)
		ThemeComEdit();
	else
	{
		if(IsEditingAnimation())  
		{
			CString str;
			str.Format(_T("%d"), m_nDelaytime);
			m_AnimationDelay.SetWindowText(str);
			m_AnimationRepeatCount.SetCurSel((m_nrepeatCount == 1) ? 0 : 1);
		}
	}
	((CDialogTheme*)m_pDialogTheme)->m_ListTheme.EnableWindow(true);
	g_onedit = false;
	memcpy(((CDialogTheme*)m_pDialogTheme)->m_edit_theme_list[m_theme_idx],&my_theme, sizeof(MMI_theme));
	g_notsaved_theme = true;
	for( int i=0;i<MAX_THEME_COM_NUM;i++)//2 mean temp saving
	{
		if(save_modify_flag[m_theme_idx][i]==2)
		{
			history_modify_flag[m_theme_idx][i]=1;
			save_modify_flag[m_theme_idx][i]=1;
		}
	}
	m_pUIDlg->EnableWindow(false);
	::MessageShow("Done");
	m_pUIDlg->EnableWindow(true);
}

void CDialogThemeEditor::OnThemeSave()
{
	ThemeSave();
	OnCancel();
}

CString CDialogThemeEditor::GetSelectedComponentName()
{
    const int selectedIndex =
            m_ListThemeEditor.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
   if (selectedIndex == -1)
   {
	   return "NoSelected";
   }
    return (m_ListThemeEditor.GetItemText(selectedIndex, 1));
}

bool CDialogThemeEditor::SelectItemByComponentName(const CString &name)
{
    const int numItems = m_ListThemeEditor.GetItemCount();

    for (int i=0; i<numItems; i++)
    {
        CString componentName(m_ListThemeEditor.GetItemText(i, 1));

        if (componentName.Compare(name) == 0)
        {
            m_ListThemeEditor.SetItemState(i, LVIS_FOCUSED | LVIS_SELECTED,
                                           LVIS_FOCUSED | LVIS_SELECTED);
            return true;
        }
    }

    return false;
} 

void CDialogThemeEditor::OnButtonImage()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	if (m_typestr.CompareNoCase("FILLER")==0)
	{
		if(m_AddImage)//m_filler_image_data_buffer == NULL)
		{
			OnFillerImage();
			if(m_AddImage == false)
			{
				//mean cancel, so delete 
//				GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(true);
				GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
				m_AddImage = true;
				DrawNonBitmap();
				return ;				
			}
			else
			{
//				GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(false);
				GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
				m_AddImage = false;

				mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
				UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
		
				InsertFillerHistory(m_filler_themeid,*old_filler);
				ComHistroy[m_filler_themeid]++;
				ComIdxHistroy[m_filler_themeid]++;
				g_onedit = true;
			}
		}

		else //delete image buffer
		{

			OnCheckFillerBorder(); //Check Filler Boarder has add the undoredo component
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			m_AddImage = true;
			DrawNonBitmap();
			g_onedit = true;
			/*
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
				UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
		
				map_filler.insert(CstrFillerPair(m_filler_themeid,*old_filler));
				ComHistroy[m_filler_themeid]++;
				ComIdxHistroy[m_filler_themeid]++;*/
		}
		std::map<int, type_9slice>::iterator slice_Iter; 

		char theme_comp_id[24];
		m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);
		

		slice_Iter = map_slice_value.find(atoi(theme_comp_id));
		if (slice_Iter != map_slice_value.end())
		{
			slice_Iter->second.nleft = 0;
			slice_Iter->second.ntop = 0;
			slice_Iter->second.nright = 0;
			slice_Iter->second.nbottom = 0;
			m_nValueTop = 0;
			m_nValueBottom = 0;
			m_nValueRight = 0;
			m_nValueLeft = 0;
			UpdateData(false);
		}
		
		ActivateTheme((MMI_theme *)&my_theme);
		UpdateListThemeOnDiffTheme();
		g_screen_cb = true; //Update at next refresh
	    if (SelectItemByComponentName(componentName))
	    {
	        m_ListThemeEditor.SetFocus();
			DrawGreenFlag(m_filler_themeid);
	    }				
	}
	else if (m_typestr.CompareNoCase("IMAGE")==0)
	{
		if(m_AddImage)//m_image_image_data_buffer == NULL)
		{
			
			OnImage();
			if(m_AddImage == false)
			{
			//	GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(true);
				GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
				m_AddImage = true;
				DrawNonBitmap();
				return ;
			}
			else
			{
//				GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(false);
				GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
				m_AddImage = false;
				
				mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_image_themeid);
				unsigned char **image = (unsigned char **) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
				InsertImageHistory(m_image_themeid,*image);
				ComHistroy[m_image_themeid]++;
				ComIdxHistroy[m_image_themeid]++;
				g_onedit = true;
			}
		}
		else //On press delete image
		{
			//delete m_image_image_data_buffer;
			//m_image_image_data_buffer = NULL;
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_image_themeid);
			unsigned char **image = (unsigned char **) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			*image = NULL;

			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			m_AddImage = true;
			DrawNonBitmap();

			InsertImageHistory(m_image_themeid,*image);
			ComHistroy[m_image_themeid]++;
			ComIdxHistroy[m_image_themeid]++;
			g_onedit = true;
            SetFlag(m_image_themeid);
			std::map<int, type_9slice>::iterator slice_Iter; 

			char theme_comp_id[24];
			m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);

			slice_Iter = map_slice_value.find(atoi(theme_comp_id));
			if (slice_Iter != map_slice_value.end())
			{
				slice_Iter->second.nleft = 0;
				slice_Iter->second.ntop = 0;
				slice_Iter->second.nright = 0;
				slice_Iter->second.nbottom = 0;
				m_nValueTop = 0;
				m_nValueBottom = 0;
				m_nValueRight = 0;
				m_nValueLeft = 0;
				UpdateData(false);
			}
            //int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
            //if (idx != -1)
            //{
            //    DrawFlagIcon(idx);
            //}
		}
		ActivateTheme((MMI_theme *)&my_theme);
		UpdateListThemeOnDiffTheme();
		g_screen_cb = true; //Update at next refresh
	    if (SelectItemByComponentName(componentName))
	    {
	        m_ListThemeEditor.SetFocus();
			DrawGreenFlag(m_image_themeid);
	    }		
	}

}

/*****************************************************************************
* FUNCTION
*  UpdatePosition
* DESCRIPTION
*  when the main window moves, this window should move together.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void CDialogThemeEditor::UpdatePosition()
{
	/* shift the dialog to be align with the main windows */
	RECT rectTheme, rectThemeEditor;
	GetWindowRect(&rectThemeEditor);
	m_pDialogTheme->GetWindowRect(&rectTheme);
	MoveWindow(rectTheme.left, rectTheme.bottom, rectThemeEditor.right - rectThemeEditor.left + 0, rectThemeEditor.bottom - rectThemeEditor.top + 0, TRUE);
} /* end of UpdatePosition */

WCHAR DisplayALLSC[30] = { 0x002D, 0x002D, 0x002D, 0x002D, 0x663E, 0x793A, 0x5168, 0x90E8, 0x002D, 0x002D, 0x002D, 0x002D, 0x0000 } ;
WCHAR ShowCurrentSC[30] = { 0x002D, 0x002D, 0x002D, 0x002D, 0x76EE, 0x524D, 0x753B, 0x9762, 0x002D, 0x002D, 0x002D, 0x002D, 0x0000 } ;

void CDialogThemeEditor::AddGroupFilter()
{
    HWND handleToComboBox = ::GetDlgItem(m_hWnd, IDC_COMBO_COMPONENT_GROUP_EX);

    COMBOBOXEXITEMW comboItem;
    memset(&comboItem, 0, sizeof(comboItem));

	if( g_Theme_Lan == 0 )
	    comboItem.pszText = L"----Display All----";
	else if( g_Theme_Lan == 1 )
		comboItem.pszText = DisplayALLSC;
	
    comboItem.mask    = CBEIF_TEXT;
    comboItem.iItem   = 0;
    ::SendMessage(handleToComboBox, CBEM_INSERTITEMW, -1, (LPARAM) &comboItem);

	if( g_Theme_Lan == 0 )
	    comboItem.pszText = L"----Current Screen----";
	else if( g_Theme_Lan == 1 )
		comboItem.pszText = ShowCurrentSC;
	
    comboItem.iItem   = 1;
    ::SendMessage(handleToComboBox, CBEM_INSERTITEMW, -1, (LPARAM) &comboItem);

    const int numGroups = mmi_mte_get_component_group_num();
    int numVisibleGroups = 0;

    for (int groupID=0; groupID<numGroups; groupID++)
    {
        const int numComponents = mmi_mte_get_theme_component_num();

        for (int componentID=0; componentID<numComponents; componentID++)
        {
            const mmi_mte_theme_component_struct *component =
                        mmi_mte_get_theme_component(componentID);

            if (component->group_id == groupID && component->allow_editing)
            {
                // If there are editable components in the group, we
                //   (1) add the group to the ComboBox, and
                //   (2) record its group ID in g_VisibleGroupMappingTable.

                comboItem.pszText =
                    reinterpret_cast<wchar_t *>(
                        const_cast<char *>(
                            mmi_mte_get_component_group_name(groupID)
                        )
                    );

                comboItem.iItem = numVisibleGroups + 2;
                ::SendMessage(handleToComboBox, CBEM_INSERTITEMW, -1, 
                              (LPARAM) &comboItem);
                
                g_VisibleGroupMappingTable[numVisibleGroups++] = groupID;
                break;
            }
        }
    }

    /*
    for(int jj=0;jj<mmi_mte_get_component_group_num();jj++)
    {
        wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(jj);


        comboItem.pszText=group_uni_str;

        comboItem.iItem=jj+2; 
        ::SendMessage(handleToComboBox,CBEM_INSERTITEMW,-1,(LPARAM)&comboItem); 

    }
    */

    m_ComboComGroup.SetCurSel(0);
}

bool g_close_theme_editor = true;

BOOL CDialogThemeEditor::OnInitDialog() 
{
	CDialog::OnInitDialog();

	/**************Plugin init****************/
	
	
	m_nMainLCDWidth, m_nMainLCDHeight;

	/**************************************/
	
	int i;
    theme_editor_hwnd = GetSafeHwnd();
	g_onedit = false;
	m_AddImage = false;
	m_updateint = false;
	m_bSliceComponent = false;
	((CEdit*)GetDlgItem(IDC_EDIT_INTEGER))->SetLimitText(3);
	list_slice.clear();
	map_slice_value.clear();
	for(int p=0;p<MAX_THEME_COM_NUM;p++)
	{
		defaultnull[p]=false;
		ComHistroy[p]=0;
		ComIdxHistroy[p]=0;
//		flag[p]=false;
		first_touch[p] = false;
		map_color[p].clear();
		map_filler[p].clear();
		map_image[p].clear();
	}
	m_bShowNoEditPop = false;
	m_bShowNoEditAgain = true;
	
	m_ntop = m_nleft = m_nright = m_nbottom = 0;

	m_filler_image_data_buffer = NULL;
	m_image_image_data_buffer = NULL;
	DisableThemeComponent(false,false,false,false);
	m_editing = false;
	m_recommend_width=m_recommend_height=m_max_width=m_max_height=0;
	color_dlg = NULL;
	// TODO: Add extra initialization here
	
	m_drawcolor = false;
	m_drawfiller = false;
	
	SetDlgItemInt(IDC_EDIT_ALPHA,100); //set alpha value equal 100
	
	ListView_SetExtendedListViewStyle(m_ListThemeEditor.m_hWnd,  LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);
	
	m_SmallImg.Create(16,16,ILC_COLOR,2,0);
	m_SmallImg.SetBkColor(RGB(255,255,255));
	HICON   hIcon=AfxGetApp()->LoadIcon(IDI_MTE);   
	HICON   hIcon1=AfxGetApp()->LoadIcon(IDI_MTE2); 
	HICON   hIcon2=AfxGetApp()->LoadIcon(IDI_MTE1);
	m_SmallImg.Add(hIcon);  
	m_SmallImg.Add(hIcon1);
	m_SmallImg.Add(hIcon2);
	m_ListThemeEditor.SetImageList(&m_SmallImg, LVSIL_SMALL); 	

	m_ListThemeEditor.InsertColumn(0, _T("Index"), LVCFMT_LEFT, 50);
	m_ListThemeEditor.InsertColumn(1, _T("Component Name"), LVCFMT_LEFT, 230);
	m_ListThemeEditor.InsertColumn(2, _T("Component Group"), LVCFMT_LEFT, 140);
	m_ListThemeEditor.InsertColumn(3, _T("Type"), LVCFMT_LEFT, 80);
	
	m_ListThemeEditor.InsertColumn(4, _T("Size"), LVCFMT_LEFT, 50);
	m_ListThemeEditor.InsertColumn(5, _T("Description"), LVCFMT_LEFT, 70);
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MENU_THEME));
	m_listhWnd = ::GetDlgItem(m_hWnd,IDC_LIST_THEME_EDITOR);


	
	
	mmi_mte_theme_component_struct *the_component;
	int filter_result_idx =0;
	CString The_Size;
	for(i=0;i<mmi_mte_get_theme_component_num();i++)
	{
		
		the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(i);
		//TRACE("allow_editing = %d \n",the_component->allow_editing);	
		wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(the_component->group_id);
		//CString group_str = CDialogGotoScreen::ConvertBSTRToString(SysAllocString(group_uni_str));//mmi_mte_get_component_group_name(the_component->group_id);		
	
		CString nid;
		nid.Format("%d",i+1);
		if(!g_hidetheme || the_component->allow_editing!=0)
		{
			LVITEM lvItem;
		int nItem;
		LPTSTR lpsz = new TCHAR[nid.GetLength()+1];
		_tcscpy(lpsz, nid); 
		lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvItem.iItem = filter_result_idx;
		lvItem.iSubItem = 0;
		lvItem.pszText = lpsz;
		
		//lvItem.iImage = 0 implies green flag
		//lvItem.iImage = 1 implies N flag not allowable to edit
		//lvItem.iImage = 2 implies implies gray flag
		if(the_component->allow_editing==0)
			lvItem.iImage = 1;
		else
			lvItem.iImage = -1;
	
		if(save_modify_flag[m_theme_idx][the_component->id]==1) lvItem.iImage = 2;

		nItem = m_ListThemeEditor.InsertItem(&lvItem);
		
		CString type_str = GetComponentTypeStr(the_component->type);
		m_ListThemeEditor.SetItemText(nItem,1,the_component->name);
		//m_ListThemeEditor.SetItemText(nItem,2,group_str);
		SetItemTextU(m_listhWnd,nItem,2,group_uni_str);
		
		m_ListThemeEditor.SetItemText(nItem,3,type_str);
			//m_ListThemeEditor.SetItemText(filter_result_idx,4,"0k");
			// 			if(type_str.CompareNoCase("Image")==0)
			// 			{
			// 				The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,true));
			// 				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			// 			}
			// 			else if(type_str.CompareNoCase("Filler")==0)
			// 			{
			// 				The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,false));
			// 				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			// 			}
			float m_floatsize = 0;
			if(type_str.CompareNoCase("Image")==0)
			{
                m_floatsize = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,true);
				The_Size = SizeFloatValueToString(m_floatsize);
				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			}
			else if(type_str.CompareNoCase("Filler")==0)
			{
				m_floatsize = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,false);
				The_Size = SizeFloatValueToString(m_floatsize);
				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			}
			else
			{
				m_ListThemeEditor.SetItemText(nItem,4,"N/A");
			}

			wchar_t* uni_str =(wchar_t*) (the_component->description);
			//CString desc_Str = CDialogGotoScreen::ConvertBSTRToString(SysAllocString(uni_str));
			//m_ListThemeEditor.SetItemText(nItem,5,desc_Str);
			SetItemTextU(m_listhWnd,nItem,5,uni_str);
			delete lpsz;
			lpsz = NULL;
			filter_result_idx ++;
		}
	}
	

	m_group_name ="";
	m_ColRef = RGB( 0, 0, 255 );
	m_FillerC = RGB( 255,0, 0 );
	m_FillerAC = RGB( 0,255, 0 );
	m_FillerBC = RGB( 255,255, 0 );
	m_FillerSC = RGB( 255,0, 255 );
	m_SupportImage = false;
	
	AddGroupFilter();
	
	int theme_idx =  ((CDialogTheme*)m_pDialogTheme)->m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	
	CString editthe_str;
	char theme_str[512];
	((CDialogTheme*)m_pDialogTheme)->m_ListTheme.GetItemText(theme_idx,1,theme_str,512);
//	editthe_str.Format("Theme Name: %s is Selected to Edit", theme_str);
//	GetDlgItem(IDC_STATIC_EDITING2)->SetWindowText(editthe_str);
	editthe_str.Format("MoDIS Theme Editor - %s", theme_str);
	SetWindowText(editthe_str);
	m_color_themeid =0;
	m_filler_themeid =0;
	m_image_themeid =0;
	//Register Call Back mmi_mte_register_switch_screen_callback
	mmi_mte_register_switch_screen_callback((CB_SWITCH_SCREEN)switch_screen_cb);
	SetTimer(101, 100,  NULL);//101 mean timer is, 300 mean 0.3 sec

	CMenu *mmenu = GetMenu();
	CMenu *pMenu = mmenu->GetSubMenu(0);
	if(g_Theme_Lan==0)
	{
	
		pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_CHECKED);
		
	}
	else if(g_Theme_Lan==1)
	{

		pMenu->CheckMenuItem(ID_MENU_SIMCHINESE, MF_CHECKED);
	}
	
	char path[1024],MoDISEXE[1024],tempbuf[1024];
	char *name;
	memset(path, 0, sizeof(tempbuf));
	memset(tempbuf, 0, sizeof(tempbuf));
	memset(MoDISEXE, 0, sizeof(MoDISEXE));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return false;
	strncpy(MoDISEXE, path, strlen(path));
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%snon.bmp", tempbuf);
	m_BMPFile.Format(path);

	INIT_EASYSIZE;
	CClientDC dc(this);
	m_dcMem.CreateCompatibleDC( &dc );
	m_vbar.ShowWindow(false);
	m_hbar.ShowWindow(false);
	UpdatePosition();
	m_test = true;
	
	RECT		window_info;
	GetWindowRect(&window_info);
	m_oldh = window_info.bottom-window_info.top;
	m_oldw = window_info.right-window_info.left;
	
	m_transparent = false;

    // Owen
    for (i=0; i<NUM_IMAGE_BLOCKS; i++)
    {
        CRect imageRect(GetControlRect(IMAGE_BLOCK_CONTROL_IDS[i]));
        CRect selectionRect(imageRect + CRect(2, 2, 2, 2));

        m_ImageBlocks.push_back(ImageBlock(imageRect, selectionRect));
    }

    m_SelectedImageBlock = m_ImageBlocks.begin();

    m_AnimationDelay.SetLimitText(3);
	m_SliceBottom.SetLimitText(3);
	m_SliceTop.SetLimitText(3);
	m_SliceRight.SetLimitText(3);
	m_SliceLeft.SetLimitText(3);
//    m_AnimationDelay.EnableWindow(FALSE);
	m_AnimationDelay.ShowWindow(SW_HIDE);
	GetDlgItem( IDC_ANIMATION_LABEL_DELAY )->ShowWindow( SW_HIDE ) ;
    m_AnimationRepeatCount.InsertString(0, _T("Once"));
    m_AnimationRepeatCount.SetItemData(0, 1);
    m_AnimationRepeatCount.InsertString(1, _T("Forever"));
    m_AnimationRepeatCount.SetItemData(1, 0);

	CButton *pBtn=NULL;
	
	pBtn = (CButton*)GetDlgItem(IDC_RADIO_SETTING_LEFT);
	pBtn->SetCheck(1);
	m_nSetTopLeft = 1;
    m_IsDialogInitialized = true;
	EnableMenuForThemeEditor(0,4,false);
	EnableMenuForThemeEditor(0,5,false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDialogThemeEditor::OnClose() 
{
	// TODO: Add your message handler code here and/or call defaul
	CDialog::OnClose();
}

void CDialogThemeEditor::FreeMem()
{
	if(m_filler_image_data_buffer)
	{
		delete m_filler_image_data_buffer;
		m_filler_image_data_buffer = NULL;
	}
	if(m_image_image_data_buffer)
	{
		delete m_image_image_data_buffer;
		m_image_image_data_buffer = NULL;
	}
}
void CDialogThemeEditor::OnCancel() 
{
	// TODO: Add extra cleanup here
	//memcpy(((CDialogTheme*)m_pDialogTheme)->m_edit_theme_list[m_theme_idx],&my_theme, sizeof(MMI_theme));
	((CDialogTheme*)m_pDialogTheme)->m_ListTheme.EnableWindow(true);
	
	g_screen_cb = false; //for call back function 
	KillTimer(101);
	FreeMem();
	if (g_onedit)
	{
		g_init = true;
		g_close_theme_editor = true;
        m_pUIDlg->EnableWindow(false);
		int ans = ::MessageBox(this->m_hWnd,"Save your changes?","MoDIS_UI", MB_YESNOCANCEL  | MB_DEFBUTTON3);
        m_pUIDlg->EnableWindow(true);
		if(IDYES == ans)
		{
			ThemeSave();
			((CDialogTheme*)m_pDialogTheme)->EnableThemeEditor();
		}
		else if( IDCANCEL == ans )
		{
			return ;
		}
		else
		{
			((CDialogTheme*)m_pDialogTheme)->DisplayTotalSize();
			((CDialogTheme*)m_pDialogTheme)->EnableThemeEditor();
			for( int i=0;i<MAX_THEME_COM_NUM;i++)//2 mean temp saving
			{
				if(save_modify_flag[m_theme_idx][i]==2)
				{
					//save_modify_flag[m_theme_idx][i]=0;
					save_modify_flag[m_theme_idx][i]=history_modify_flag[m_theme_idx][i];
				}
			}
		}
	}
	else
	{
		g_init = true;
		g_close_theme_editor = true;
		((CDialogTheme*)m_pDialogTheme)->EnableThemeEditor();
		((CDialogTheme*)m_pDialogTheme)->DisplayTotalSize();		
	}
	
	((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg = NULL;
	DestroyWindow();

}
CString CDialogThemeEditor::GetRecommendedImageType(
                                mmi_mte_image_enum imageType)
{
    switch (imageType)
    {
        case MMI_MTE_IMAGE_NONE:
            return _T("None");

        case MMI_MTE_IMAGE_GIF:
            return _T("GIF");

        case MMI_MTE_IMAGE_JPG:
            return _T("JPG");

        case MMI_MTE_IMAGE_BMP:
        case MMI_MTE_IMAGE_BMP_TO_ABM:
        case MMI_MTE_IMAGE_BMP_TO_AB2:
            return _T("BMP");

        case MMI_MTE_IMAGE_PNG:
        case MMI_MTE_IMAGE_PNG_TO_ABM:
        case MMI_MTE_IMAGE_PNG_TO_AB2:
	case MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE:
		case MMI_MTE_IMAGE_9SLICE:
            // Standard PNG format (supported after MT6238)
            return _T("PNG");
    }

    return _T("None");
}

CString CDialogThemeEditor::GetSupportedImageTypes(unsigned int imageType)
{
    std::vector<std::string> supportedImageTypes;

    if (imageType & MMI_MTE_IMAGE_GIF)
    {
        supportedImageTypes.push_back("GIF");
    }

    if (imageType & MMI_MTE_IMAGE_JPG)
    {
        supportedImageTypes.push_back("JPG");
    }

    if ((imageType & MMI_MTE_IMAGE_BMP) ||
        (imageType & MMI_MTE_IMAGE_BMP_TO_ABM) ||
        (imageType & MMI_MTE_IMAGE_BMP_TO_AB2))
    {
        supportedImageTypes.push_back("BMP");
    }

    if ((imageType & MMI_MTE_IMAGE_PNG) ||
        (imageType & MMI_MTE_IMAGE_PNG_TO_ABM) ||
		(imageType & MMI_MTE_IMAGE_9SLICE )||
        (imageType & MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE)||
        (imageType & MMI_MTE_IMAGE_PNG_TO_AB2))
    {
        supportedImageTypes.push_back("PNG");
    }
    char theme_comp_id[24];
	            	m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);
     if (m_allowed_image_type & MMI_MTE_IMAGE_9SLICE)
      {
  		            if (!FindTheCompIsSlice(m_old_theme_idx))
					{
						list_slice.push_back(atoi(theme_comp_id));
					}
      }
    return Join(supportedImageTypes, std::string("/")).c_str();
}

void CDialogThemeEditor::GetImageAttrRecommendation(
                                    const CString &componentName)
{
		mmi_mte_theme_component_struct *the_component; //get the theme component struct
		for(int i=0;i<mmi_mte_get_theme_component_num();i++)
		{
			the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(i);
			
			CString name(the_component->name);
			if(name.CompareNoCase(componentName)==0)
			{
				m_recommend_width=m_recommend_height=m_max_width=m_max_height=0;
				mmi_mte_get_theme_component_image_info(the_component, &m_recommend_width, &m_recommend_height, &m_max_width, &m_max_height,&m_allowed_image_type, &m_recommend_image_type);
				
				/*
				if(m_recommend_image_type==MMI_MTE_IMAGE_NONE)
				{
					m_recommend_width=m_recommend_height=m_max_width=m_max_height=0;
				//TRACE("%s recommend_image_type=%d \n",name,recommend_image_type);
				}*/
				if (m_allowed_image_type & MMI_MTE_IMAGE_9SLICE)
				{
					m_bSliceComponent = true;
		
		           
				}

				TRACE("%s (%d,%d);(%d,%d) \n",name,m_recommend_width, m_recommend_height, m_max_width, m_max_height);
		
				break;
			}
		
		}
}

void CDialogThemeEditor::DrawFlagIcon(int theme_idx)
{
		//char theme_info[6][512];
		/*
		for(int i=0;i<6;i++)
			m_ListThemeEditor.GetItemText(theme_idx,i,theme_info[i],512);
		*/
		char theme_info[512];
		char theme_size[512];
//		int new_size=0;
		float new_size=0;
		m_ListThemeEditor.GetItemText(theme_idx,0,theme_info,512);
		m_ListThemeEditor.GetItemText(theme_idx,4,theme_size,512);

		CString The_Size;
		mmi_mte_theme_component_struct *the_component;
		the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(atoi(theme_info)-1);
		TRACE("allow_editing = %d \n",the_component->allow_editing);	
		wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(the_component->group_id);
	
		LVITEM lvItem;
		int nItem;
	
		lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvItem.iItem = theme_idx;
		lvItem.iSubItem = 0;
		lvItem.pszText = theme_info;
		lvItem.iImage = 0;

		nItem = m_ListThemeEditor.InsertItem(&lvItem);
		m_ListThemeEditor.DeleteItem(theme_idx+1);
		CString type_str = GetComponentTypeStr(the_component->type);
		m_ListThemeEditor.SetItemText(nItem,1,the_component->name);
		
		SetItemTextU(m_listhWnd,nItem,2,group_uni_str);
		
		m_ListThemeEditor.SetItemText(nItem,3,type_str);
			
			if(type_str.CompareNoCase("Image")==0)
			{
				new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,true);
				
				The_Size = SizeFloatValueToString(new_size);
			//	The_Size.Format("%d K",new_size);
				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			}
			else if(type_str.CompareNoCase("Filler")==0)
			{
				new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,false);
				The_Size = SizeFloatValueToString(new_size);
			//	The_Size.Format("%d K",new_size);
				m_ListThemeEditor.SetItemText(nItem,4,The_Size);
			}
			else
			{
				m_ListThemeEditor.SetItemText(nItem,4,"N/A");
			}

			wchar_t* uni_str =(wchar_t*) (the_component->description);
			
			SetItemTextU(m_listhWnd,nItem,5,uni_str);
			m_ListThemeEditor.SetItemState(theme_idx,LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);  
//update total theme size
	
	CString themesize_str;
		CString AddImageOrNot ;
		GetDlgItem(IDC_BUTTON_IMAGE)->GetWindowText(AddImageOrNot);
		if( AddImageOrNot == "Delete Image" ) //We will change the string first!
		{
			if( IsEditingAnimation() )
				((CDialogTheme*)m_pDialogTheme)->m_total_system_theme_size = ((CDialogTheme*)m_pDialogTheme)->m_total_system_theme_size + (int)(new_size) - (int)(atof(theme_size)); //Adding Animation
			else
				((CDialogTheme*)m_pDialogTheme)->m_total_system_theme_size += (int)(new_size); //It means we are going to add an image
		}
		else
			((CDialogTheme*)m_pDialogTheme)->m_total_system_theme_size -= (int)(atof(theme_size)-new_size);
	themesize_str.Format("Total size of theme(s): %d KB",((CDialogTheme*)m_pDialogTheme)->m_total_system_theme_size);
	((CDialogTheme*)m_pDialogTheme)->GetDlgItem(IDC_STATIC_SIZE)->SetWindowText(themesize_str);

	/*
		LVITEM lvItem;
		int nItem;
		lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvItem.iItem = theme_idx;
		lvItem.iSubItem = 0;
		lvItem.pszText = theme_info[0];
		lvItem.iImage = 0;
		
		m_ListThemeEditor.DeleteItem(theme_idx);
		
		nItem = m_ListThemeEditor.InsertItem(&lvItem);

		m_ListThemeEditor.SetItemText(nItem,1,theme_info[1]);
		m_ListThemeEditor.SetItemText(nItem,2,theme_info[2]);
		m_ListThemeEditor.SetItemText(nItem,3,theme_info[3]);
		m_ListThemeEditor.SetItemText(nItem,4,theme_info[4]);
		m_ListThemeEditor.SetItemText(nItem,5,theme_info[5]);

		m_ListThemeEditor.SetItemState(theme_idx,LVIS_SELECTED, LVIS_SELECTED | LVIS_FOCUSED);  
*/
 }
void CDialogThemeEditor::ThemeComEdit() 
{
	// TODO: Add your control notification handler code here
	int theme_idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	std::map<int,type_9slice>::iterator slice_Iter;
	if(theme_idx==-1) 
	{
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		return;
	}
	
	
	if(theme_idx==m_old_theme_idx&&m_notedit) 
	{
		if (m_notedit)
		{
			EnableMenuForThemeEditor(0,4,false);
			EnableMenuForThemeEditor(0,5,false);
		}
		return;
	}
	if (theme_idx!=m_old_theme_idx)
	{
		m_bSliceComponent = false;
		if (!FindTheCompIsSlice(theme_idx))
		{
			ShowHideSliceControls(FALSE);
		}	
		else
		{
			/*
			m_SliceLeft.SetWindowText("0"); 
			m_SliceTop.SetWindowText("0");
			m_SliceRight.SetWindowText("0");
			m_SliceBottom.SetWindowText("0");*/
/*
			m_nValueLeft = 0;
			m_nValueTop = 0;
			m_nValueRight = 0;
			m_nValueBottom = 0;
			UpdateData(FALSE);*/
			ShowHideSliceControls(true);
			m_bSliceComponent = true;
			
		}	
			CButton *pBtn=NULL;
		pBtn = (CButton*)GetDlgItem(IDC_RADIO_SETTING_TOP);
		pBtn->SetCheck(0);
		
		pBtn = (CButton*)GetDlgItem(IDC_RADIO_SETTING_RIGHT);
		
		pBtn->SetCheck(0);
		pBtn = (CButton*)GetDlgItem(IDC_RADIO_SETTING_BOTTOM);
		pBtn->SetCheck(0);
		pBtn = (CButton*)GetDlgItem(IDC_RADIO_SETTING_LEFT);
			pBtn->SetCheck(1);
		m_nSetTopLeft = 1;
		
		char theme_comp_id[24];
		m_ListThemeEditor.GetItemText(theme_idx,0,theme_comp_id,24);

		slice_Iter = map_slice_value.find(atoi(theme_comp_id));
		if (slice_Iter != map_slice_value.end())
		{
			m_nValueLeft = slice_Iter->second.nleft;
			m_nValueTop = slice_Iter->second.ntop ;
			m_nValueRight = slice_Iter->second.nright;
			m_nValueBottom = slice_Iter->second.nbottom;
			UpdateData(FALSE);	
			
		}	
	}

	char theme_type_name[64];
	char theme_component_name[256];
	char theme_id[64];
	m_ListThemeEditor.GetItemText(theme_idx,3,theme_type_name,64);
	m_ListThemeEditor.GetItemText(theme_idx,0,theme_id,64);
	
	m_typestr.Format("%s",theme_type_name);
	
	m_old_theme_idx = theme_idx;
	mmi_mte_theme_component_struct *the_component;
	the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(atoi(theme_id)-1);

	if(the_component->allow_editing==0)
	{
		m_notedit = true;
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		DisableThemeComponent(false,false,false,false);//Disapear
		DrawNonBitmap();
		if (!m_bShowNoEditPop && m_bShowNoEditAgain )
		{
			m_bShowNoEditAgain = true;
			m_bShowNoEditPop = true;
			m_pUIDlg->EnableWindow(false);
		::MessageShow("This component is not allowed to be edited.");
		m_pUIDlg->EnableWindow(true);
			m_bShowNoEditPop = false;
		}
		
        m_ListThemeEditor.SetFocus();
		
		return;
	}
	m_notedit = false;;
	m_transparent = false;
	if (!(m_typestr.CompareNoCase("FILLER")==0||m_typestr.CompareNoCase("IMAGE")==0))
	{
		DrawNonBitmap();
	}


	if (m_typestr.CompareNoCase("COLOR")==0 ||m_typestr.CompareNoCase("TEXT_BORDER_COLOR")==0)
	{

		DisableThemeComponent(true,false,false,false);
		m_color_themeid = the_component->id;
		if (ComIdxHistroy[m_color_themeid]==ComHistroy[m_color_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
		if (ComIdxHistroy[m_color_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		else
		{

			EnableMenuForThemeEditor(0,4,false);
		}
		m_ListThemeEditor.GetItemText(theme_idx,1,theme_component_name,256);
		
		GetDlgItem(IDC_STATIC_COLOR)->SetWindowText(theme_component_name);
		
		color **c = (color**) mmi_mte_translate_theme_component_data_pointer(( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(the_component->id), &my_theme);
		if(*c==NULL) return;
		m_ColRef = RGB( (*c)->r, (*c)->g, (*c)->b );
		SetDlgItemInt(IDC_EDIT_ALPHA,(*c)->alpha);
		
		DrawThemeComponent();

		CButton *pBtn = (CButton*) GetDlgItem(IDC_CHECK_BOARDER);
        ASSERT(pBtn != NULL);

        if (m_typestr.CompareNoCase("COLOR") == 0)
        {
            pBtn->EnableWindow(true);
            pBtn->SetCheck(0);
            pBtn->EnableWindow(false);
            pBtn->ShowWindow(SW_HIDE);

            GetDlgItem(IDC_COLOR)->EnableWindow(TRUE);
        }
		else if (m_typestr.CompareNoCase("TEXT_BORDER_COLOR") == 0)
		{
            pBtn->EnableWindow(true);

            if (CDialogColor::is_rgb565_transparent_color(
                                ((*c)->r << 16) + ((*c)->g << 8) + (*c)->b))
            {
                pBtn->SetCheck(1);
//	            GetDlgItem(IDC_COLOR)->EnableWindow(FALSE);
            }
            else
            {
                pBtn->SetCheck(0);
	            GetDlgItem(IDC_COLOR)->EnableWindow(TRUE);
            }
        }

		Invalidate();
		if(!first_touch[m_color_themeid]) //mean first touch
		{
			map_color[m_color_themeid].insert(CstrColorPair(m_color_themeid,**c));
		}
		first_touch[m_color_themeid] = true;
	}
    else if (m_typestr.CompareNoCase("FILLER") == 0)
    {
        DisableThemeComponent(false,true,false,false);
        m_filler_themeid = the_component->id;
        m_ListThemeEditor.GetItemText(theme_idx, 1, theme_component_name, 256);
        GetDlgItem(IDC_STATIC_FILLER)->SetWindowText(theme_component_name);
		if (ComIdxHistroy[m_filler_themeid]==ComHistroy[m_filler_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
	
		if (ComIdxHistroy[m_filler_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		else
		{
	
			EnableMenuForThemeEditor(0,4,false);
		}
		GetImageAttrRecommendation(theme_component_name);

        UI_filled_area **filler =
            static_cast<UI_filled_area **>
                (mmi_mte_translate_theme_component_data_pointer(
                                                the_component, &my_theme));
        ASSERT(filler != NULL);

        if (*filler == NULL) 
        {
            defaultnull[m_filler_themeid] = true;
            m_transparent = true;
            ((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(1);
            ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
            DrawNonBitmap();
            GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
            m_AddImage = true;
            m_FillerC=RGB(0xDC,0xDC,0xDC);
            m_FillerBC=RGB(0xDC,0xDC,0xDC);
            //m_recommend_width =0;
            //m_recommend_height=0;
            //m_max_width=0; 
            //m_max_height=0; 
            m_editing=0;
            //m_allowed_image_type =0 ;
            //m_recommend_image_type =MMI_MTE_IMAGE_NONE;
            DrawThemeComponent();

	    m_SliceLeft.SetWindowText("0"); 
	    m_SliceTop.SetWindowText("0");
			m_SliceRight.SetWindowText("0");
			m_SliceBottom.SetWindowText("0");
			m_nValueLeft=m_nValueRight=m_nValueTop=m_nValueBottom=0;

            ImageRecDisplay();
            DisableFillerTransparent(the_component);

            if(!first_touch[m_filler_themeid]) //mean first edit
            {
                map_filler[m_filler_themeid].insert(CstrFillerPair(m_filler_themeid,*filler));
            }
            first_touch[m_filler_themeid]=true;

            Invalidate();

            GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->EnableWindow(
                        IsAnimationSupported(the_component) ? TRUE : FALSE);

            return;
        }
        else
        {
            ((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(0);
        }

		ImageRecDisplay();

        // Owen
        if (HasAnimation(*filler, the_component))
        {
            DrawNonBitmap();
            GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->EnableWindow(TRUE);
            EnterAnimationEditingMode();
        }
        else
        {
            GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->EnableWindow(
                        IsAnimationSupported(the_component) ? TRUE : FALSE);
		
            DisableFillerTransparent(the_component);
			if (!(the_component->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
            {
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
            }
            else
			{
				((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);
			}
            if ((*filler)->flags == 0)
            {
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
            }
            else if ((*filler)->flags == UI_FILLED_AREA_SINGLE_BORDER)
            {
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);
            }

            /* Disable border according to MMI_MTE_FILLER_ALLOW_BORDER */
            if (!(the_component->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
            {
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
            }
            else
			{
			//	((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);
			}
            m_FillerC = RGB((*filler)->c.r, (*filler)->c.g, (*filler)->c.b);
            m_FillerBC = RGB((*filler)->border_color.r,
                             (*filler)->border_color.g,
                             (*filler)->border_color.b );
            
            SetDlgItemInt(IDC_EDIT_ALPHA,(*filler)->c.alpha);
        
            if((*filler)->b&&(*filler)->flags ==3)
            {
                DisplayImagebyCom(IDC_FILLER_IMAGE,(*filler)->b);
                GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
                m_AddImage = false;
            }
            else
            {
                DrawNonBitmap();
				if (m_bSliceComponent)
             	{
	            	ShowHideSliceControls(true);
	            }

                GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
				m_nValueTop = 0;
				m_nValueBottom = 0;
				m_nValueRight = 0;
				m_nValueLeft = 0;
				UpdateData(false);
                m_AddImage = true;
            }

		    DrawThemeComponent();
        }

		if(!first_touch[m_filler_themeid]) //mean first edit
		{
			map_filler[m_filler_themeid].insert(CstrFillerPair(m_filler_themeid,*filler));
		}
		first_touch[m_filler_themeid]=true;
		Invalidate();
	}

	else if (m_typestr.CompareNoCase("FONT")==0)
	{
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Font is not allowed to be edited.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	else if (m_typestr.CompareNoCase("IMAGE")==0)
	{
		DisableThemeComponent(false,false,true,false);
		m_image_themeid = the_component->id;
		m_ListThemeEditor.GetItemText(theme_idx,1,theme_component_name,256);
		GetDlgItem(IDC_STATIC_IMAGE)->SetWindowText(theme_component_name);
		if (ComIdxHistroy[m_image_themeid]==ComHistroy[m_image_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
		if (ComIdxHistroy[m_image_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		else
		{
		
			EnableMenuForThemeEditor(0,4,false);
		}
		unsigned char **image = (unsigned char **) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
		GetImageAttrRecommendation(theme_component_name); //get m_recommend_image_type
		if(*image)
		{
			DisplayImagebyCom(IDC_IMAGE,*image);
//			m_image_ptr = *image;
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
			m_AddImage = false;
//			GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(false);
			Invalidate();
		}
		else
		{
			DrawNonBitmap();
			if (m_bSliceComponent)
           	{
	           	ShowHideSliceControls(true);
	         }
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			m_nValueTop = 0;
			m_nValueBottom = 0;
			m_nValueRight = 0;
			m_nValueLeft = 0;
			UpdateData(false);
			if(m_bautoclose == false)
			m_AddImage = true;
		}
		GetImageAttrRecommendation(theme_component_name); //get m_recommend_image_type
		ImageRecDisplay();
		
		if(!first_touch[m_image_themeid]) //mean first edit
		{
			map_image[m_image_themeid].insert(CstrImagePair(m_image_themeid,*image));
		}
		first_touch[m_image_themeid]=true;
	}
	else if (m_typestr.CompareNoCase("SYMBOL")==0)
	{
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Symbol is not allowed to be edited.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	else if (m_typestr.CompareNoCase("INTEGER")==0)
	{
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		CString maxmin;
		maxmin.Format("Max(%d),Min(%d)",the_component->max_value,the_component->min_value);
		GetDlgItem(IDC_STATIC_MAXMIN)->SetWindowText(maxmin);
		DisableThemeComponent(false,false,false,true);
		m_integer_themeid = the_component->id;
		m_ListThemeEditor.GetItemText(theme_idx,1,theme_component_name,256);
		GetDlgItem(IDC_STATIC_INTEGER)->SetWindowText(theme_component_name);
		int *i = (int*) mmi_mte_translate_theme_component_data_pointer(( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(the_component->id), &my_theme);
		
		//GetDlgItemInt(IDC_EDIT_INTEGER)
		SetDlgItemInt(IDC_EDIT_INTEGER,*i);
	    m_theintTemp = *i;
		return;
	}

}
void CDialogThemeEditor::ImageRecDisplay()
{
    if (m_allowed_image_type == MMI_MTE_IMAGE_NONE)
    {
        m_SupportImage = false; 
        GetDlgItem(IDC_STATIC_REC_WH)->SetWindowText(_T(""));
        GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(_T(""));
        GetDlgItem(IDC_STATIC_REC2)->SetWindowText(_T(""));
        GetDlgItem(IDC_BUTTON_IMAGE)->EnableWindow(false);
          GetDlgItem(IDC_STATIC_REC)->SetWindowText(_T("Does not support image."));

        return;
    }
	else if (m_recommend_width==0 || m_recommend_height==0)
	{
		if (m_bSliceComponent != true)//if (!FindTheCompIsSlice(m_old_theme_idx))
		{
			m_SupportImage = false; 
			GetDlgItem(IDC_STATIC_REC_WH)->SetWindowText(_T(""));
			GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(_T(""));
			GetDlgItem(IDC_STATIC_REC2)->SetWindowText(_T(""));
			GetDlgItem(IDC_BUTTON_IMAGE)->EnableWindow(false);
			GetDlgItem(IDC_STATIC_REC)->SetWindowText(_T("Does not support image."));

			return;
		}	
		
	}

    m_SupportImage = true; 
	if (m_allowed_image_type == MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE)
		GetDlgItem(IDC_BUTTON_IMAGE)->EnableWindow(false);
   else
    GetDlgItem(IDC_BUTTON_IMAGE)->EnableWindow(true);

    CString str;

	if (m_recommend_width == 0 || m_recommend_height == 0)
	{
		str.Format("Recommended size: None");
	}
	else
    str.Format("Recommended size: (%d, %d)", m_recommend_width, m_recommend_height);
    GetDlgItem(IDC_STATIC_REC_WH)->SetWindowText(str);

	if (/*FindTheCompIsSlice(m_old_theme_idx)*/ m_bSliceComponent && !IsEditingAnimation())
    {
		if (g_MMI_width == m_max_height && g_MMI_height == m_max_width)
		{
			str.Format("Max size: (%d, %d)", m_max_width, m_max_height);
		}
		else
		str.Format("Max size: (%d, %d)",g_MMI_width, g_MMI_height); 
		GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(str);
	}
	else
	{	
    str.Format("Max size: (%d, %d)", m_max_width, m_max_height);
    GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(str);
	}
    GetDlgItem(IDC_STATIC_REC2)->SetWindowText(
        _T("Best type: ") + GetRecommendedImageType(m_recommend_image_type));

    GetDlgItem(IDC_STATIC_REC)->SetWindowText(
        _T("Supported types: ") + GetSupportedImageTypes(m_allowed_image_type));

	if (m_bSliceComponent)
		ShowHideSliceControls(true);
	else
		ShowHideSliceControls(false);

    return;
}
void CDialogThemeEditor::OnFindComponent() 
{
	CDialogFindComponent dlgFindCom(this);
	dlgFindCom.DoModal();
}

void CDialogThemeEditor::OnMteUg()
{
	char tempbuf[1024];
	char path[1024];
	char wordpath[1024];

	
	memset(path, 0, sizeof(path));
	memset(tempbuf, 0, sizeof(tempbuf));

	char *name;
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
        return ;

	strncpy(tempbuf, path, strlen(path)-strlen(name));
	if( !GetOfficeWordPath(L"Word.Application",&wordpath[0],255) )
	{
	m_pUIDlg->EnableWindow(false);
		::MessageShow("Can not get Office path!");
	m_pUIDlg->EnableWindow(true);
		return ;
	}
	
	sprintf(path, "%c%s%c %c%s%s%c",'"',wordpath,'"','"',tempbuf,"themeug.doc",'"');
	
	TRACE("%s\n",path);
	STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

	//if(!CUIDlg::RunProcess(path))
	if(!RunProcess(path))
	{		
		TRACE("%s\n",path);
		m_pUIDlg->EnableWindow(false);
		::MessageShow("No word processor or no artist user guide."); 
		m_pUIDlg->EnableWindow(true);
	}
}

void CDialogThemeEditor::OnGotoScreen() 
{
	/*
	CDialogGotoScreen dlgGotoScr;
	dlgGotoScr.DoModal();
	*/
	if(goto_screen_dlg!=NULL)
		delete goto_screen_dlg;
	goto_screen_dlg = new CDialogGotoScreen(this,this->w32_mmi_mte_api);
	goto_screen_dlg->Create(IDD_DIALOG_GOTO_SCREEN, this);
	goto_screen_dlg->ShowWindow(SW_SHOW);
	g_screen_cb = true ;
	
}
void CDialogThemeEditor::OnSetting() 
{
	CDialogThemeSetting dlgSetting(this);
	dlgSetting.DoModal();
	// hide non-edit theme component
	/*
	if(g_hidetheme)
	{
		::MessageShow("Test hide true");
	}*/


}

void CDialogThemeEditor::OnReDo() 
{
	if( m_ListThemeEditor.GetSelectionMark() == -1 )
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a component to do redo.");
		m_pUIDlg->EnableWindow(true);
		return ;
	}
	if( m_notedit )
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Can not do redo on this component.");
		m_pUIDlg->EnableWindow(true);
		return ;
	}
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a component to do redo.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	ReDoComponent();
	Invalidate();

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::OnUnDo() 
{
	if( m_ListThemeEditor.GetSelectionMark() == -1 )
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a component to do undo.");
		m_pUIDlg->EnableWindow(true);
		return ;
	}
	if( m_notedit )
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Can not do undo on this component.");
		m_pUIDlg->EnableWindow(true);
		return ;
	}
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a component to do undo."); 
		m_pUIDlg->EnableWindow(true);
		return;
	}
	UnDoComponent();
	Invalidate();

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::SetIniLanguage(CString restr)
{

	char path[1024],tempbuf[1024];
	char *name;
	memset(tempbuf, 0, sizeof(tempbuf));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
				return ;
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);
	WritePrivateProfileString("INTEGRATE", "THEME_LANGUAGE", restr, path);
}

void CDialogThemeEditor::OnEnglish()
{
	//CMenu menu;
	CMenu *mmenu = GetMenu();
	CMenu *pMenu = mmenu->GetSubMenu(0);
	// Set Check
	UINT state = pMenu->GetMenuState(ID_MENU_ENGLISH, MF_BYCOMMAND);
	if (state & MF_CHECKED)
	{
		//pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_UNCHECKED);
		
	}
	else
	{
		int sel = m_ComboComGroup.GetCurSel();
		mmi_mte_set_language(ENGLISH);
		pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_CHECKED);
		pMenu->CheckMenuItem(ID_MENU_SIMCHINESE, MF_UNCHECKED);
		
		SetIniLanguage("English");
        g_Theme_Lan = 0;

		SetLanFilter(); //Update Theme component filter
		m_ComboComGroup.SetCurSel(sel); //Set current currsor
		UpdateListTheme();//Update theme component list view

		m_old_theme_idx = -1;
		m_notedit = true;
		DisableThemeComponent(false,false,false,false);
		ShowHideSliceControls(false);
		DrawNonBitmap();
		Invalidate();
	}
}
void CDialogThemeEditor::SetLanFilter()
{
		int selfilter = m_ComboComGroup.GetCurSel();
		int count = m_ComboComGroup.GetCount();
		for(int kk=0;kk<count;kk++)
		{	
			m_ComboComGroup.DeleteString(0);
		}
		AddGroupFilter();
		m_ComboComGroup.SetCurSel(0);//selfilter);
}
void CDialogThemeEditor::OnSimchinese()
{
		//CMenu menu;
	CMenu *mmenu = GetMenu();
	CMenu *pMenu = mmenu->GetSubMenu(0);
	// Set Check
	UINT state = pMenu->GetMenuState(ID_MENU_SIMCHINESE, MF_BYCOMMAND);
	if (state & MF_CHECKED)
	{
		//pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_UNCHECKED);
		
	}
	else
	{
		int sel = m_ComboComGroup.GetCurSel();
		mmi_mte_set_language(SIM_CHINESE);
		
		pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_MENU_SIMCHINESE, MF_CHECKED);
		SetIniLanguage("Simplified Chinese");
        g_Theme_Lan = 1;
		
		SetLanFilter();

		m_ComboComGroup.SetCurSel(sel);
		UpdateListTheme();

		m_old_theme_idx = -1;
		m_notedit = true;
		DisableThemeComponent(false,false,false,false);
 		ShowHideSliceControls(false);
		DrawNonBitmap();
		Invalidate();
	}
}

void CDialogThemeEditor::ReDoComponent()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
	m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
	m_pUIDlg->EnableWindow(true);
		return;
	}
	if (m_typestr.CompareNoCase("COLOR")==0 ||m_typestr.CompareNoCase("TEXT_BORDER_COLOR")==0)
			{
				if(ComIdxHistroy[m_color_themeid]==ComHistroy[m_color_themeid])
				{
					//::MessageShow("No Redo Component");
					return;
				}
				ComIdxHistroy[m_color_themeid]++;//pivot
		if (ComIdxHistroy[m_color_themeid]==ComHistroy[m_color_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
		if (ComIdxHistroy[m_color_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		
				ReUnDoColor();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_color_themeid);		
			    }					
			}
			else if (m_typestr.CompareNoCase("FILLER")==0)
			{
				if(ComIdxHistroy[m_filler_themeid]==ComHistroy[m_filler_themeid])
				{
					//::MessageShow("No Redo Component");
					return;
				}
				ComIdxHistroy[m_filler_themeid]++;//pivot
		if (ComIdxHistroy[m_filler_themeid]==ComHistroy[m_filler_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
		if (ComIdxHistroy[m_filler_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		
				ReUnDoFiller();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_filler_themeid);		
			ThemeComEdit();
			    }					
			}

			else if (m_typestr.CompareNoCase("IMAGE")==0)
			{
				if(ComIdxHistroy[m_image_themeid]==ComHistroy[m_image_themeid])
				{
					//::MessageShow("No Redo Component");
					return ;
				}
				ComIdxHistroy[m_image_themeid]++;//pivot
		if (ComIdxHistroy[m_image_themeid]==ComHistroy[m_image_themeid])
		{
			EnableMenuForThemeEditor(0,5,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
		if (ComIdxHistroy[m_image_themeid]!=0)
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		
				ReUnDoImage();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_image_themeid);		
			    }					
			}

}
void CDialogThemeEditor::UnDoComponent()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	if (m_typestr.CompareNoCase("COLOR")==0 ||m_typestr.CompareNoCase("TEXT_BORDER_COLOR")==0)
			{
				if(ComIdxHistroy[m_color_themeid]==0)
				{
					//::MessageShow("No Undo Component");
					return;
				}
				ComIdxHistroy[m_color_themeid]--;//pivot
		if (ComIdxHistroy[m_color_themeid]==0)
		{
			EnableMenuForThemeEditor(0,4,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		if (ComIdxHistroy[m_color_themeid]!=ComHistroy[m_color_themeid])
		{
			EnableMenuForThemeEditor(0,5,true);
		}
				ReUnDoColor();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_color_themeid);		
			    }					
			}
			else if (m_typestr.CompareNoCase("FILLER")==0)
			{
				if(ComIdxHistroy[m_filler_themeid]==0)
				{
					//::MessageShow("No Undo Component");
					return;
				}
				ComIdxHistroy[m_filler_themeid]--;//pivot
		if (ComIdxHistroy[m_filler_themeid]==0)
		{
			EnableMenuForThemeEditor(0,4,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		
		if (ComIdxHistroy[m_filler_themeid]!=ComHistroy[m_filler_themeid])
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
				ReUnDoFiller();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_filler_themeid);		
			ThemeComEdit();
			    }					
			}
			else if (m_typestr.CompareNoCase("IMAGE")==0)
			{
				if(ComIdxHistroy[m_image_themeid]==0)
				{
					//::MessageShow("No Undo Component");
					return;
				}
				ComIdxHistroy[m_image_themeid]--;//pivot
		if (ComIdxHistroy[m_image_themeid]==0)
		{
			EnableMenuForThemeEditor(0,4,false);
		}
		else
		{
			EnableMenuForThemeEditor(0,4,true);
		}
		
		if (ComIdxHistroy[m_image_themeid]!=ComHistroy[m_image_themeid])
		{
			EnableMenuForThemeEditor(0,5,true);
		}
		
				ReUnDoImage();
			    if (SelectItemByComponentName(componentName))
			    {
			        m_ListThemeEditor.SetFocus();
					DrawGreenFlag(m_image_themeid);		
			    }					
			}

}
BOOL CDialogThemeEditor::PreTranslateMessage(MSG* pMsg) 
{
	UINT  nKeyCode = pMsg->wParam;
	CMenu* mmenu = GetMenu();
	CMenu* submenu = NULL;
	if( mmenu != NULL )
	{		
		submenu = mmenu->GetSubMenu(0); 
	}

	if(pMsg->message==WM_KEYDOWN)
	{
        if(pMsg->wParam==VK_ESCAPE)//disable VK_ESCAPE
                  pMsg->wParam=NULL ;
    
		if ( (nKeyCode == _T('Y') || nKeyCode == _T('y')) && (::GetKeyState(VK_CONTROL) & 0x8000) )
		{
			//ReDoComponent();
			UINT state = -1;
			 if( submenu != NULL )
			 {
		    	 state = submenu->GetMenuState(ID_REDO, MF_BYCOMMAND);
			 }
	         if (state != 0xFFFFFFFF && state == MF_ENABLED)
			OnReDo();
			
		}	
		if ( (nKeyCode == _T('Z') || nKeyCode == _T('z')) && (::GetKeyState(VK_CONTROL) & 0x8000) )
		{
			//UnDoComponent();
			UINT state = -1;
			 if( submenu != NULL )
			 {
		    	 state = submenu->GetMenuState(ID_UNDO, MF_BYCOMMAND);
			 }
	         if (state != 0xFFFFFFFF && state == MF_ENABLED)
			OnUnDo();
		}
		if ( (nKeyCode == _T('G') || nKeyCode == _T('g')) && (::GetKeyState(VK_CONTROL) & 0x8000) )
		{
			OnGotoScreen();
		}
		if ( (nKeyCode == _T('F') || nKeyCode == _T('f')) && (::GetKeyState(VK_CONTROL) & 0x8000) )
		{
			OnFindComponent();
		}
	} 
    if (pMsg->message == WM_MTE_SHOW_CURRENT_SCREEN)
    {
        ShowCurrentScreen();
    }
	if(pMsg->message == WM_KEYUP)
    {
         if(pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN)
         {
             if(pMsg->hwnd == m_ListThemeEditor.m_hWnd)
             {
                NMHDR nm;
                 LRESULT lr; 

                  memset(&nm, 0, sizeof(NMHDR));
                    memset(&lr, 0, sizeof(LRESULT));
    
                   OnNMClickListThemeEditor(&nm, &lr);
              }
         }
	}


	if (m_hAccelTable) {
      if (::TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg)) {
         return(TRUE);
      }
   }

	return CDialog::PreTranslateMessage(pMsg);
}

void CDialogThemeEditor::ReUnDoColor()
{
	color *mod_color = new color;
			
			mod_color->alpha = GetDlgItemInt(IDC_EDIT_ALPHA);

			multimap<int, color>::iterator color_Iter;
			//color_Iter = map_color.find(m_color_themeid);
			int num = 0;
			for ( color_Iter =map_color[m_color_themeid].begin( ); color_Iter !=map_color[m_color_themeid].end( ); color_Iter++ )
			{
				TRACE("data R %d\n",color_Iter->second.r);
				if(color_Iter->first == m_color_themeid)
				{
					if(ComIdxHistroy[m_color_themeid]==num)
					{
						TRACE("match R %d\n",color_Iter->second.r);
						mod_color->r = color_Iter->second.r;
						mod_color->g = color_Iter->second.g;
						mod_color->b = color_Iter->second.b;
						break;
					}
					num ++;
				}
			}
			m_ColRef = RGB(mod_color->r,mod_color->g,mod_color->b);
			//The following code is to use
			DrawThemeComponent();
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_color_themeid);
			color **c = (color**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			*c = mod_color;
			ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_color_themeid]=true;
			SetFlag(m_color_themeid);
			int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
			if(idx!=-1) DrawFlagIcon(idx);

			CButton *pBtn = (CButton*) GetDlgItem(IDC_CHECK_BOARDER);
            ASSERT(pBtn != NULL);
			g_screen_cb = true; //Update at next refresh

			if(m_typestr.CompareNoCase("COLOR")==0)
			{
				pBtn->EnableWindow(true);
				pBtn->SetCheck(0);
				pBtn->EnableWindow(false);
			}
			else if(m_typestr.CompareNoCase("TEXT_BORDER_COLOR")==0)
			{
				pBtn->EnableWindow(true);

				if (CDialogColor::is_rgb565_transparent_color(
                                ((*c)->r << 16) + ((*c)->g << 8) + (*c)->b))
                {
					pBtn->SetCheck(1);
                }
				else
                {
					pBtn->SetCheck(0);
                }
			}
			
}

void CDialogThemeEditor::ReUnDoFiller()
{
	UI_filled_area *mod_filler = NULL;//GetNewFiller();
	multimap<int, UI_filled_area *>::iterator filler_Iter;
			//color_Iter = map_color.find(m_color_themeid);
	
    mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
	int num = 0;
	for ( filler_Iter =map_filler[m_filler_themeid].begin( ); filler_Iter !=map_filler[m_filler_themeid].end( ); filler_Iter++ )
	{
			
		if(filler_Iter->first == m_filler_themeid)
		{
			if(ComIdxHistroy[m_filler_themeid]==num)
			{
			
				if(filler_Iter->second!=NULL)
				{
					mod_filler = GetNewFiller();
					memcpy(mod_filler, filler_Iter->second, sizeof(UI_filled_area));
				}
				break;
			}
			num ++;
		}
	}
	
	if(mod_filler==NULL) 
		{
			m_transparent = true;
			((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(1);
			((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
			DrawNonBitmap();
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");

			std::map<int,type_9slice>::iterator slice_Iter;
			slice_Iter = map_slice_value.find(m_filler_themeid+1);
			if (slice_Iter != map_slice_value.end())
			{
				slice_Iter->second.nleft = 0;
				slice_Iter->second.ntop = 0;
				slice_Iter->second.nright =0;
				slice_Iter->second.nbottom =0;					
			}	

			m_nValueTop = 0;
			m_nValueBottom = 0;
			m_nValueRight = 0;
			m_nValueLeft = 0;
			UpdateData(false);
			m_AddImage = true;
			m_FillerC=RGB(0xDC,0xDC,0xDC);
			m_FillerBC=RGB(0xDC,0xDC,0xDC);
			//m_recommend_width =0;
			//m_recommend_height=0;
			//m_max_width=0; 
			//m_max_height=0; 
			m_editing=0;
			//m_allowed_image_type =0 ;
			//m_recommend_image_type =MMI_MTE_IMAGE_NONE;
			DrawThemeComponent();
			ImageRecDisplay();

            UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
            *old_filler = NULL;
            ActivateTheme((MMI_theme *)&my_theme);
			g_screen_cb = true; //Update at next refresh
			return; // some theme component is NULL
		}
		else
		{
			m_transparent = false;
			((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(0);
		}	
		if(mod_filler->flags ==0)
			((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
		//else if(mod_filler->flags ==UI_FILLED_AREA_SINGLE_BORDER)
		else if(mod_filler->flags & UI_FILLED_AREA_SINGLE_BORDER)
			((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);

        /* disable border according to MMI_MTE_FILLER_ALLOW_BORDER */
        if (!(the_component->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
        {
            ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
        }
		m_FillerC = RGB( mod_filler->c.r, mod_filler->c.g, mod_filler->c.b );
		m_FillerBC = RGB( mod_filler->border_color.r, mod_filler->border_color.g, mod_filler->border_color.b );
		
		//ASSERT(m_FillerC==NULL);
		SetDlgItemInt(IDC_EDIT_ALPHA,mod_filler->c.alpha);
		
	
		if(mod_filler->b&&mod_filler->flags ==3)
		{
            if (!HasAnimation(mod_filler, the_component))
            {
                DisplayImagebyCom(IDC_FILLER_IMAGE,mod_filler->b);
            
                GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
                m_AddImage = false;
            }
		}
		else
		{
			
				DrawNonBitmap();
			
				GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
				std::map<int,type_9slice>::iterator slice_Iter;
				slice_Iter = map_slice_value.find(m_filler_themeid+1);
				if (slice_Iter != map_slice_value.end())
				{
					slice_Iter->second.nleft = 0;
					slice_Iter->second.ntop = 0;
					slice_Iter->second.nright =0;
					slice_Iter->second.nbottom =0;					
				}	
				m_nValueTop = 0;
				m_nValueBottom = 0;
				m_nValueRight = 0;
				m_nValueLeft = 0;
				    UpdateData(false);
				m_AddImage = true;
			
		}
		UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
		*old_filler = mod_filler;
		ActivateTheme((MMI_theme *)&my_theme);
		g_screen_cb = true; //Update at next refresh
    if (HasAnimation(mod_filler, the_component))
    {
        if (IsEditingAnimation())
        {
            ClearImageBlocks();
            LoadAnimationImage();
            SetupBitmapViewer();
        }
        else
        {
            EnterAnimationEditingMode();
        }
    }
    else
    {
        if (IsEditingAnimation())
        {
            LeaveAnimationEditingMode();
        }
    }
}

void CDialogThemeEditor::ReUnDoImage()
{
	

	multimap<int, unsigned char *>::iterator image_Iter;
	
	int num = 0;
	for ( image_Iter =map_image[m_image_themeid].begin( ); image_Iter !=map_image[m_image_themeid].end( ); image_Iter++ )
	{
			
		if(image_Iter->first == m_image_themeid)
		{
			if(ComIdxHistroy[m_image_themeid]==num)
			{
				
				if(image_Iter->second!=NULL)
				{
					DisplayImagebyCom(IDC_IMAGE,image_Iter->second);

					GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
					m_AddImage = false;

					Invalidate();

				}
				else
				{
					DrawNonBitmap();
					GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
					std::map<int,type_9slice>::iterator slice_Iter;
					slice_Iter = map_slice_value.find(m_image_themeid+1);
					if (slice_Iter != map_slice_value.end())
					{
						slice_Iter->second.nleft = 0;
						slice_Iter->second.ntop = 0;
						slice_Iter->second.nright =0;
						slice_Iter->second.nbottom =0;					
					}	
					m_nValueTop = 0;
					m_nValueBottom = 0;
					m_nValueRight = 0;
					m_nValueLeft = 0;
				    UpdateData(false);
					m_AddImage = true;
				}

				mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_image_themeid);
				unsigned char **image = (unsigned char**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
				*image = image_Iter->second;
				ActivateTheme((MMI_theme *)&my_theme);
				g_screen_cb = true; //Update at next refresh
				break;
			}
			num ++;
		}
	}			
}


int CDialogThemeEditor::Get_Theme_Com_in_Current_Screent(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[])
{
	int num=0;
	//WaitForSingleObject(m_hWMutex,3000); //wait 3 seconds at most
	    
	num= mmi_mte_get_theme_components_in_current_screen(max_component_number, theme_component_list);

	//ReleaseMutex(m_hWMutex);
	return num;
}
CString CDialogThemeEditor::Get_Component_Group_Name(int id)
{
	wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(id);
	return ConvertBSTRToString(SysAllocString(group_uni_str));
}

void CDialogThemeEditor::ShowCurrentScreen()
{
	TRACE("================ShowCurrentScreen begin================\n");
	if( *g_pMMIIsGoingToPowerOff )
		return ;
    if (m_group_name.CompareNoCase(START_CURRENT_SCR) != 0)
    {
        return;
    }
  if (b_exit_flags)
	{
		return;
	}
	//Close any OpenFileDialog, because the screen may change to another screen.
	CWnd *cwnd = FromHandle( this->GetSafeHwnd() ) ;	
	if( cwnd != NULL )
	{
		CWnd *cwnd2 ;
		//Open file
		cwnd2 = cwnd->FindWindow( NULL, "Open");		
		if( cwnd2 != NULL )
		{
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);
			m_bautoclose = true;
		}
		cwnd2 = cwnd->FindWindow( NULL, _T("´ò¿ª"));		
		if( cwnd2 != NULL )
		{
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);
			m_bautoclose = true;
		}

		//Color
		cwnd2 = cwnd->FindWindow( NULL, "Color");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);

		//Color Dialog
		cwnd2 = cwnd->FindWindow( NULL, "Color Dialog");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);

		//Color Picker
		cwnd2 = cwnd->FindWindow( NULL, "Color Picker");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);
		
		//
		cwnd2 = cwnd->FindWindow( NULL, "MoDIS_UI");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);

		
	}
    //
    // Force the list control to select "--Current Screen--"
    // (and display so on the edit box), so that we don't confuse our
    // users in some special cases.
    //
    // For example, if the list control is displaying search results,
    // the edit box shows "Search Results." When this function is invoked
    // to update the content of the list control, what the edit box shows
    // won't change (i.e. remains "Search Results") while the list box is
    // being updated to display components on the current screen, which is
    // very confusing.
    //
    m_ComboComGroup.SetCurSel(1);

    m_ListThemeEditor.DeleteAllItems();
	EnableMenuForThemeEditor(0,4,false);
	EnableMenuForThemeEditor(0,5,false);
    const mmi_mte_theme_component_struct *theme_component_list[200];

    m_total_component_num = Get_Theme_Com_in_Current_Screent(200, theme_component_list);

    CString The_Size;
    for (int j = 0; j < m_total_component_num; j++)
    {
        wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(theme_component_list[j]->group_id);
        CString type_str = ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->GetComponentTypeStr(theme_component_list[j]->type);	
            
        CString nid;
        nid.Format("%d",theme_component_list[j]->id+1);
        if(!g_hidetheme || theme_component_list[j]->allow_editing!=0)
        {
            LVITEM lvItem;
            int nItem;
            LPTSTR lpsz = new TCHAR[nid.GetLength()+1];
            _tcscpy(lpsz, nid); 
            lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
            lvItem.iItem = theme_component_list[j]->id;
            lvItem.iSubItem = 0;
            lvItem.pszText = lpsz;
            //lvItem.iImage = -1;
            if(theme_component_list[j]->allow_editing==0)
                lvItem.iImage = 1;
            else
                lvItem.iImage = -1;
            
//				if(flag[theme_component_list[j]->id]) lvItem.iImage = 0;
            if(save_modify_flag[m_theme_idx][theme_component_list[j]->id]==1) lvItem.iImage = 2;
            if(save_modify_flag[m_theme_idx][theme_component_list[j]->id]==2) lvItem.iImage = 0;
            
            
        
            nItem = m_ListThemeEditor.InsertItem(&lvItem);

            m_ListThemeEditor.SetItemText(nItem,1,theme_component_list[j]->name);
            //m_ListThemeEditor.SetItemText(nItem,2,group_str);
            SetItemTextU(m_listhWnd,nItem,2,group_uni_str);
            m_ListThemeEditor.SetItemText(nItem,3,type_str);
            //((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ListThemeEditor.SetItemText(j,4,"0k");
			float new_size = 0;
            if(type_str.CompareNoCase("Image")==0)
            {
				new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,true);
				The_Size = SizeFloatValueToString(new_size);
               // The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,true));
                ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ListThemeEditor.SetItemText(nItem,4,The_Size);
            }
            else if(type_str.CompareNoCase("Filler")==0)
            {
				new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,false);
				The_Size = SizeFloatValueToString(new_size);
             //   The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,false));
                ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ListThemeEditor.SetItemText(nItem,4,The_Size);
            }
            else
            {
                ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ListThemeEditor.SetItemText(nItem,4,"N/A");
            }
            wchar_t* uni_str =(wchar_t*) (theme_component_list[j]->description);
            SetItemTextU(m_listhWnd,nItem,5,uni_str);
            delete lpsz;
            lpsz = NULL;
            /*
            if(uni_str!=L"")
            {
                CString desc_Str = CDialogGotoScreen::ConvertBSTRToString(SysAllocString(uni_str));
                ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ListThemeEditor.SetItemText(nItem,5,desc_Str);
            }*/
        }
    }
    
    if (IsEditingAnimation())
    {
        LeaveAnimationEditingMode();
    }

    m_old_theme_idx = -1;
    m_notedit = true;
    DisableThemeComponent(false,false,false,false);
	ShowHideSliceControls(false);
    DrawNonBitmap();
    Invalidate();
}
CString CDialogThemeEditor::SizeFloatValueToString(float size)
{
	CString m_strsize;
	if (size >= 0.01)
	{
		m_strsize.Format("%.2f K",size);
	}
	else
	{
		m_strsize.Format("%d K",0);
	}
	return m_strsize;
}


void CDialogThemeEditor::UpdateListTheme()
{
	int sel = m_ComboComGroup.GetCurSel();
	
	//Notice must be remodified..........Wayne 070921
	
	m_ComboComGroup.GetLBText(sel,m_group_name);//mmi_mte_get_component_group_name(sel);
	
	CString temp2(SearchResultSC), temp3(L"Search Result:");

	if (!m_group_name.CompareNoCase(temp3) || !m_group_name.CompareNoCase(temp2))
	{
		m_ComboComGroup.DeleteString(sel);
		sel = 0;
		m_ComboComGroup.SetCurSel(0);
	}
	//group_name = m_ComboComGroup.GetItemText(sel);
	if( sel == 0 )
		m_group_name = L"----Display All----";
	else if( sel == 1 )
		m_group_name = L"----Current Screen----";

    // glory
    int current_selected_group_id;

    if (sel >= 2)
    {   // valid component group combo box item
        current_selected_group_id = g_VisibleGroupMappingTable[sel - 2];
    }
    else
    {   // display all or current
        current_selected_group_id = -1;
    }
	
	m_ListThemeEditor.DeleteAllItems();
	EnableMenuForThemeEditor(0,4,false);
	EnableMenuForThemeEditor(0,5,false);
	float new_size =0;
	//Just Display Current Screen Theme component
	if(m_group_name.CompareNoCase(START_CURRENT_SCR)==0)//||group_name.CompareNoCase(END_CURRENT_SCR)==0)
	{
		//::MessageShow("Please Select Component Name");
		//
		g_screen_cb = true;
	//	mmi_mte_register_switch_screen_callback((CB_SWITCH_SCREEN)switch_screen_cb);

		const mmi_mte_theme_component_struct *theme_component_list[200];
		//int total_component_num;
			if (b_exit_flags )
	        	return;

		m_total_component_num = mmi_mte_get_theme_components_in_current_screen(200, theme_component_list);
		CString The_Size;
		for (int j = 0; j < m_total_component_num; j++)
		{
			//printf("Name %s", theme_component_list[j]->name);
				if (b_exit_flags )
            		return;

			wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(theme_component_list[j]->group_id);
	
			CString group_str = ConvertBSTRToString(SysAllocString(group_uni_str));//mmi_mte_get_component_group_name(theme_component_list[j]->group_id);
			CString type_str = GetComponentTypeStr(theme_component_list[j]->type);	
			
			CString nid;
			//nid.Format("%d",j+1);
			nid.Format("%d",theme_component_list[j]->id+1);
			if(!g_hidetheme || theme_component_list[j]->allow_editing!=0)
			{
				LVITEM lvItem;
				int nItem;
				LPTSTR lpsz = new TCHAR[nid.GetLength()+1];
				_tcscpy(lpsz, nid); 
				lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
				lvItem.iItem = theme_component_list[j]->id;
				lvItem.iSubItem = 0;
				lvItem.pszText = lpsz;
				//lvItem.iImage = -1;
				if(theme_component_list[j]->allow_editing==0)
					lvItem.iImage = 1;
				else
					lvItem.iImage = -1;
//				if(flag[theme_component_list[j]->id]) lvItem.iImage = 0;
				if(save_modify_flag[m_theme_idx][theme_component_list[j]->id]==1) lvItem.iImage = 2;
				if(save_modify_flag[m_theme_idx][theme_component_list[j]->id]==2) lvItem.iImage = 0;
				
				nItem = m_ListThemeEditor.InsertItem(&lvItem);

				m_ListThemeEditor.SetItemText(nItem,1,theme_component_list[j]->name);
				//m_ListThemeEditor.SetItemText(nItem,2,group_str);
				SetItemTextU(m_listhWnd,nItem,2,group_uni_str);
				m_ListThemeEditor.SetItemText(nItem,3,type_str);
				//m_ListThemeEditor.SetItemText(j,4,"0k");
				new_size =0;
				if(type_str.CompareNoCase("Image")==0)
				{
					new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,true);
					The_Size = SizeFloatValueToString(new_size);
				//	The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,true));
					m_ListThemeEditor.SetItemText(nItem,4,The_Size);
				}
				else if(type_str.CompareNoCase("Filler")==0)
				{
					new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,false);
					The_Size = SizeFloatValueToString(new_size);
				//	The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, theme_component_list[j]->name,false));
					m_ListThemeEditor.SetItemText(nItem,4,The_Size);
				}
				else
				{
					m_ListThemeEditor.SetItemText(nItem,4,"N/A");
				}
				wchar_t* uni_str =(wchar_t*)( theme_component_list[j]->description);
				SetItemTextU(m_listhWnd,nItem,5,uni_str);
				delete lpsz;
				lpsz = NULL;
				/*
				if(uni_str!=L"")
				{	
					CString desc_Str = CDialogGotoScreen::ConvertBSTRToString(SysAllocString(uni_str));
					m_ListThemeEditor.SetItemText(nItem,5,desc_Str);
				}*/
			}
		}
		Invalidate();
		return;
	}
	if (b_exit_flags )
		return;
	mmi_mte_theme_component_struct *the_component;
	int filter_result_idx =0;
	CString The_Size;
	for(int i=0;i<mmi_mte_get_theme_component_num();i++)
	{
		the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(i);
			
		wchar_t* group_uni_str = (wchar_t*)mmi_mte_get_component_group_name(the_component->group_id);
		CString group_str = ConvertBSTRToString(SysAllocString(group_uni_str));//mmi_mte_get_component_group_name(the_component->group_id);		
		// if(sel==0||group_str.Compare(m_group_name)==0)
        if ((sel == 0) || // display all
            (current_selected_group_id == the_component->group_id))
		{
			CString nid;
			nid.Format("%d",i+1);
			if(!g_hidetheme || the_component->allow_editing!=0)
			{
				LVITEM lvItem;
				int nItem;
				LPTSTR lpsz = new TCHAR[nid.GetLength()+1];
				_tcscpy(lpsz, nid); 
				lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
				lvItem.iItem = filter_result_idx;
				lvItem.iSubItem = 0;
				lvItem.pszText = lpsz;
				//lvItem.iImage = -1;
				if(the_component->allow_editing==0)
					lvItem.iImage = 1;
				else
					lvItem.iImage = -1;
//				if(flag[the_component->id]) lvItem.iImage = 0;
				if(save_modify_flag[m_theme_idx][the_component->id]==1) lvItem.iImage = 2;
				if(save_modify_flag[m_theme_idx][the_component->id]==2) lvItem.iImage = 0;
				nItem = m_ListThemeEditor.InsertItem(&lvItem);
				
				CString type_str = GetComponentTypeStr(the_component->type);
				m_ListThemeEditor.SetItemText(nItem,1,the_component->name);
				//m_ListThemeEditor.SetItemText(nItem,2,group_str);
				SetItemTextU(m_listhWnd,nItem,2,group_uni_str);
				m_ListThemeEditor.SetItemText(nItem,3,type_str);
				//m_ListThemeEditor.SetItemText(filter_result_idx,4,"0k");
				new_size = 0;
				if(type_str.CompareNoCase("Image")==0)
				{
					new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,true);
					The_Size = SizeFloatValueToString(new_size);
				//	The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,true));
					m_ListThemeEditor.SetItemText(nItem,4,The_Size);
				}
				else if(type_str.CompareNoCase("Filler")==0)
				{
					new_size = ((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,false);
					The_Size = SizeFloatValueToString(new_size);
				//	The_Size.Format("%d K",((CDialogTheme*)m_pDialogTheme)->GetThemeComSize((MMI_theme *)&my_theme, the_component->name,false));
					m_ListThemeEditor.SetItemText(nItem,4,The_Size);
				}
				else
				{
					m_ListThemeEditor.SetItemText(nItem,4,"N/A");
				}
			
				wchar_t* uni_str =(wchar_t*) (the_component->description);
				SetItemTextU(m_listhWnd,nItem,5,uni_str);
				
				delete lpsz;
				lpsz = NULL;
				/*
				if(uni_str!=L"")
				{
					CString desc_Str = CDialogGotoScreen::ConvertBSTRToString(SysAllocString(uni_str));
				
					m_ListThemeEditor.SetItemText(nItem,5,desc_Str);
				}*/

				filter_result_idx ++;
			}
		}
	}
	Invalidate();

}
void CDialogThemeEditor::OnSelchangeComponentGroup()
{
	if (m_ComboComGroup.GetCurSel()<0)
	{
		m_ComboComGroup.SetCurSel(0);  
	//	return;
	}
	m_ComboComGroup.EnableWindow(false);
    if (IsEditingAnimation())
    {
        LeaveAnimationEditingMode();
    }

	int sel = m_ComboComGroup.GetCurSel();
	UpdateListTheme();
	
	if(sel>=2)//mean use group filter
	{	
		// glory
		mmi_mte_show_example_screen_by_group(g_VisibleGroupMappingTable[sel - 2]);
		mmi_mte_return_code_enum erronum = mmi_mte_is_controlarea_in_current_screen();	
		if (MMI_MTE_SUCCESS == erronum)
		{
			m_StaticWarningScreen.ShowWindow(SW_SHOW);
		}
		else
		{
			m_StaticWarningScreen.ShowWindow(SW_HIDE);
		}
	}
	if(sel==0)
	{
		m_StaticWarningScreen.ShowWindow(SW_HIDE);
	}
	if (sel == 1)
	{
		mmi_mte_return_code_enum erronum = mmi_mte_is_controlarea_in_current_screen();	
		if (MMI_MTE_SUCCESS == erronum)
		{
			m_StaticWarningScreen.ShowWindow(SW_SHOW);
		}
		else
		{
			m_StaticWarningScreen.ShowWindow(SW_HIDE);
		}
	}
	m_old_theme_idx = -1;
	m_notedit = true;
	DisableThemeComponent(false,false,false,false);
	ShowHideSliceControls(false);
	DrawNonBitmap();
	//Let user not to play m_ComboComGroup as child...
	m_ComboComGroup.EnableWindow(true);
	//m_ComboComGroup.SetCurSel(sel);
	::SetFocus( m_pUIDlg->GetSafeHwnd() ) ;
}
CString CDialogThemeEditor::GetComponentTypeStr(int type_id)
{
	CString type_str;
		switch(type_id){
			case 0:
				type_str = "COLOR";
				break;
			case 1:
				type_str = "TEXT_BORDER_COLOR";
				break;	
			case 2:
				type_str = "FILLER";
				break;
			case 3:
				type_str = "IMAGE";
				break;	
			case 4:
				type_str = "FONT";
				break;
			case 5:
				type_str = "INTEGER";
				break;	
			case 6:
				type_str = "SYMBOL";
				break;
			default:
				type_str = "UNKNOWN";				
		}
	return type_str;
}

void CDialogThemeEditor::OnDropdownComponentGroup()
{
	//Serch before
	int sel = m_ComboComGroup.GetCurSel();
		
	m_ComboComGroup.GetLBText(sel,m_group_name);//mmi_mte_get_component_group_name(sel);
	
	CString temp2(SearchResultSC), temp3(L"Search Result:");

	if (!m_group_name.CompareNoCase(temp3) || !m_group_name.CompareNoCase(temp2))
	{
		m_ComboComGroup.DeleteString(sel);		
	}

	if(m_find == true)
	{
		int count = ((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ComboComGroup.GetCount();
		((CDialogTheme*)m_pDialogTheme)->theme_editor_dlg->m_ComboComGroup.DeleteString(count);
		m_find = false;
	}
}




CRect CDialogThemeEditor::GetColorDisplayRect(unsigned int idc)
{
	CRect Rect;
	CWnd * pWnd = GetDlgItem( idc );
	ASSERT(pWnd);
	pWnd->GetWindowRect( Rect );
	ScreenToClient( Rect );
	Rect.left = Rect.left +1;
	Rect.top = Rect.top +1;
	
	Rect.right = Rect.right -1;
	Rect.bottom = Rect.bottom -1;
	
	return Rect;
}

void CDialogThemeEditor::DrawThemeComponent() 
{	
    if (IsEditingAnimation())
    {
        return;
    }

	CDC *ptmpDC = GetDC();

    if (m_drawcolor)
    {
        ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_COLOR), m_ColRef);
    }

    if (m_drawfiller)
    {
        ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_FILLER_C),m_FillerC);
        //pDC->FillSolidRect(GetColorDisplayRect(IDC_FILLER_AC),m_FillerAC);
        ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_FILLER_BC),m_FillerBC);
        //pDC->FillSolidRect(GetColorDisplayRect(IDC_FILLER_SC),m_FillerSC);
    }

    HPEN hpen = CreatePen(PS_SOLID, 1,
                          RGB(255 - GetRValue(m_FillerBC),
                              255 - GetGValue(m_FillerBC),
                              255 - GetBValue(m_FillerBC)));   

    ptmpDC->SelectObject(hpen);

    if (!m_notedit)
    {
        if (((CButton*) GetDlgItem(IDC_CHECK_FILLER_BORDER))->GetCheck() &&
            m_drawfiller)
        {
            CRect rect(GetColorDisplayRect(IDC_FILLER_BC));

            ptmpDC->MoveTo(rect.left,  rect.top);
            ptmpDC->LineTo(rect.right, rect.bottom);
            ptmpDC->MoveTo(rect.right, rect.top);
            ptmpDC->LineTo(rect.left,  rect.bottom);
        }

        if ((!m_AddImage && m_drawfiller) || m_transparent)	//draw cross lines
        {
            CRect rect(GetColorDisplayRect(IDC_FILLER_BC));

            ptmpDC->MoveTo(rect.left,  rect.top);
            ptmpDC->LineTo(rect.right, rect.bottom);
            ptmpDC->MoveTo(rect.right, rect.top);
            ptmpDC->LineTo(rect.left,  rect.bottom);

            HPEN pen = CreatePen(PS_SOLID, 1,
                                 RGB(255 - GetRValue(m_FillerC),
                                     255 - GetGValue(m_FillerC),
                                     255 - GetBValue(m_FillerC)));   

            rect = GetColorDisplayRect(IDC_FILLER_C);
            ptmpDC->SelectObject(pen);
            ptmpDC->MoveTo(rect.left,  rect.top);
            ptmpDC->LineTo(rect.right, rect.bottom);
            ptmpDC->MoveTo(rect.right, rect.top);
            ptmpDC->LineTo(rect.left,  rect.bottom);
            
            DeleteObject(pen);
            //((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
        }
    }

    DeleteObject(hpen);
    ReleaseDC(ptmpDC);
}

void CDialogThemeEditor::OnColor()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	CString colorthem;
	GetDlgItem(IDC_STATIC_COLOR)->GetWindowText(colorthem);
//	TRACE("%s",colorthem);
	if(colorthem!="")
	{
		CButton *pBtn = (CButton*) GetDlgItem(IDC_CHECK_BOARDER);
        ASSERT(pBtn != NULL);
	
	//	if(pBtn->GetCheck())
		{
		//	::MessageShow("Please uncheck the transparent RGB(0, 0, 255) first!");
		//	return;
		}
		if(SelectColor(m_ColRef)) //Select Color as m_ColRef
		{
		
			DrawThemeComponent();
			color *mod_color = new color;
			mod_color->r = GetRValue(m_ColRef);
			mod_color->g = GetGValue(m_ColRef);
			mod_color->b = GetBValue(m_ColRef);
			mod_color->alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_color_themeid);
			color **c = (color**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			*c = mod_color;
			ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_color_themeid]=true;
			SetFlag(m_color_themeid);
			int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
			
			if(idx!=-1) DrawFlagIcon(idx);
			//map_color.insert(CstrColorPair(m_color_themeid,*mod_color));
			
			InsertColorHistory(m_color_themeid,*mod_color);
			ComHistroy[m_color_themeid]++;
			ComIdxHistroy[m_color_themeid]++;
			g_screen_cb = true; //Update at next refresh
			g_onedit = true;
			
			UpdateListThemeOnDiffTheme();
		    if (SelectItemByComponentName(componentName))
		    {
		        m_ListThemeEditor.SetFocus();
				DrawGreenFlag(m_color_themeid);		
		    }			
		}
	}

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }

}

void CDialogThemeEditor::InsertImageHistory(int id, unsigned char* image)
{
	multimap<int, unsigned char *>::iterator image_Iter;
	multimap<int, unsigned char *>::iterator old_image_Iter;
	multimap<int, unsigned char *>::iterator image_Iter_begin=map_image[id].begin();

	int size = map_image[id].size();
	map_image[id].insert(CstrImagePair(id,image));
			
	if(ComIdxHistroy[id]==ComHistroy[id])
	{
		return;
	}
	int num = 0;
	bool del = false;
	
	int i=0;

	bool start =true;

	for ( image_Iter =image_Iter_begin;i<=size; image_Iter++,i++ )
	{
		TRACE("i=%d\n",i);
		
		if(del)
		{
		
			if(i<size) map_image[id].insert(CstrImagePair(image_Iter->first,image_Iter->second));
			if(!start)	map_image[id].erase(old_image_Iter);
			old_image_Iter = image_Iter;
		
			start = false;
		}

		else
		{
			if(image_Iter->first == id)
			{
				if(ComIdxHistroy[id]==num)
				{
					del = true;	
					TRACE("ID =%d value=%d",id,ComIdxHistroy[id]);
				}
				num ++;
			}
		}
		

	}

}

void CDialogThemeEditor::InsertFillerHistory()
{
    UI_filled_area **filler =
        static_cast<UI_filled_area **>
            (GetComponentAddr(&my_theme, m_filler_themeid));
    ASSERT(filler != NULL);

    InsertFillerHistory(m_filler_themeid, *filler);
    ComHistroy[m_filler_themeid]++;
    ComIdxHistroy[m_filler_themeid]++;
}

void CDialogThemeEditor::InsertFillerHistory(int id, UI_filled_area* f)
{
	multimap<int, UI_filled_area *>::iterator filler_Iter;
	multimap<int, UI_filled_area *>::iterator old_filler_Iter;
	multimap<int, UI_filled_area *>::iterator filler_Iter_begin=map_filler[id].begin();

	int size = map_filler[id].size();
	map_filler[id].insert(CstrFillerPair(id,f));
			
	if(ComIdxHistroy[id]==ComHistroy[id])
	{
		return;
	}
	int num = 0;
	bool del = false;
	
	int i=0;

	bool start =true;

	for ( filler_Iter =filler_Iter_begin;i<=size; filler_Iter++,i++ )
	{
		TRACE("i=%d\n",i);
		
		if(del)
		{
		
			if(i<size) map_filler[id].insert(CstrFillerPair(filler_Iter->first,filler_Iter->second));
			if(!start)	map_filler[id].erase(old_filler_Iter);
			old_filler_Iter = filler_Iter;
		
			start = false;
		}

		else
		{
			if(filler_Iter->first == id)
			{
				if(ComIdxHistroy[id]==num)
				{
					del = true;	
					TRACE("ID =%d value=%d",id,ComIdxHistroy[id]);
				}
				num ++;
			}
		}
		

	}

}

void CDialogThemeEditor::InsertColorHistory(int id, color c)
{
	multimap<int, color>::iterator color_Iter;
	multimap<int, color>::iterator old_color_Iter;
	multimap<int, color>::iterator color_Iter_begin=map_color[id].begin();

	int size = map_color[id].size();
	map_color[id].insert(CstrColorPair(id,c));
			
	for ( color_Iter =map_color[id].begin(); color_Iter !=map_color[id].end(); color_Iter++ )
	{
		TRACE("before %d\n",color_Iter->second.r);
	}

	if(ComIdxHistroy[id]==ComHistroy[id])
	{
		return;
	}
	int num = 0;
	bool del = false;
	
	int i=0;

	bool start =true;

	for ( color_Iter =color_Iter_begin;i<=size; color_Iter++,i++ )
	{
		TRACE("i=%d\n",i);
		
		if(del)
		{
		
			if(i<size) map_color[id].insert(CstrColorPair(color_Iter->first,color_Iter->second));
			if(!start)	map_color[id].erase(old_color_Iter);
			old_color_Iter = color_Iter;
		
			start = false;
		}

		else
		{
			if(color_Iter->first == id)
			{
				if(ComIdxHistroy[id]==num)
				{
					del = true;	
					TRACE("m_color_themeid =%d value=%d",id,ComIdxHistroy[id]);
				}
				num ++;
			}
		}
		

	}

	for ( color_Iter =map_color[id].begin(); color_Iter !=map_color[id].end(); color_Iter++ )
	{
		TRACE("after %d\n",color_Iter->second.r);
	}
}
void CDialogThemeEditor::ActivateTheme(MMI_theme *ptr)
{
	OutputDebugString("ActivateTheme\n");

	g_screen_cb = false;
	//If it's in --Current Screen-- state, we'll do ShowCurrentScreen here
	if (m_group_name.CompareNoCase(START_CURRENT_SCR) == 0)
	{
		if( !IsEditingAnimation() && DoShowCurrentScreenInActivateTheme )  //Do not allow ShowCurrentScreen in Animation Editting
		g_screen_cb = true;
	}


	MMI_theme *pat = mmi_mte_get_current_system_theme();
	
	const mmi_mte_theme_component_struct *theme_component_list[200];
	int total_component_num;		
	int theme_idx =  ((CDialogTheme*)m_pDialogTheme)->m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	
	if(memcmp(pat,ptr,sizeof(MMI_theme))!=0)
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("You activated another theme,update editing themes.");
		m_pUIDlg->EnableWindow(true);
		mmi_mte_activate_theme(ptr,m_theme_idx);
	}	
	else
	{
		total_component_num = mmi_mte_get_theme_components_in_current_screen(200, theme_component_list);
		mmi_mte_activate_theme(ptr,m_theme_idx);  //mmi_mte_activate_theme will CALLBACK switch_screen_cb
		OutputDebugString("mmi_mte_activate_theme(ptr);\n");
		//Wait until the "Loading screen" finish
		int i = 0 ;
		while( total_component_num != mmi_mte_get_theme_components_in_current_screen(200, theme_component_list) )
		{
			::Sleep(5);		
			i++ ;  
			if( i > 100 ) //wait at most .50 sec 
				break ;
		}
	}
	
    //Do ShowCurrentScreen by our own
    if (m_group_name.CompareNoCase(START_CURRENT_SCR) == 0)
    {   
    	//Wait for screen to be stable
		//::EnableWindow( this->GetSafeHwnd(), false );	
		//::Sleep(1000); //Wait for screen stable(for Timer Cout-Down Screen )
		//::EnableWindow( this->GetSafeHwnd(), true);	
		
		OutputDebugString("if( g_showcurrent )");
		if( g_showcurrent ) //if there's going to do ShowCurrentScreen()
		{
			//This ShowCurrentScreen is caused by some cases that the screen
			//will be refresh by timer.
			ShowCurrentScreen (); 
			g_showcurrent = false ;					
		}
		//g_screen_cb = false;
        //return;
    }	
		mmi_mte_return_code_enum erronum = mmi_mte_is_controlarea_in_current_screen();	
		if (MMI_MTE_SUCCESS == erronum)
		{
				if ( m_ComboComGroup.GetCurSel()== 1)
			m_StaticWarningScreen.ShowWindow(SW_SHOW);
		}
		else
		{
			m_StaticWarningScreen.ShowWindow(SW_HIDE);
		}
	DoShowCurrentScreenInActivateTheme = true ;
	g_screen_cb = true;
}

void CDialogThemeEditor::UpdateListThemeOnDiffTheme(void)
{

		if(m_group_name.CompareNoCase(START_CURRENT_SCR)==0) //fix current screen bug
		{
			const mmi_mte_theme_component_struct *theme_component_list[200];
			int total_component_num;
            if (b_exit_flags)
        	{
           		return;
         	}

			total_component_num = mmi_mte_get_theme_components_in_current_screen(200, theme_component_list);
			TRACE("total_component_num=%d,%d", total_component_num,m_total_component_num);
			if(total_component_num!=m_total_component_num) 
				UpdateListTheme();
		}
}
bool CDialogThemeEditor::SelectColor(COLORREF &color,
                                     bool isTransparentColorAllowed /*=false*/)
{

	color_dlg = new CDialogColor(color, isTransparentColorAllowed, this);
	if (color_dlg->DoModal()==IDOK)
	{
		//color = color_dlg->GetColor();
		color = g_Color;
		delete color_dlg;
		color_dlg = NULL;
		if(g_thecom_cancel)
			return true;
		else
			return false;
	}
	
	delete color_dlg;
	color_dlg = NULL;
	return false;

}

void CDialogThemeEditor::OnFillerc()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	CString fillerthem;
	GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
	if(fillerthem!="")
	{
		if(SelectColor(m_FillerC, true)) //Select Color as m_ColRef
		{	/*
			DrawThemeComponent();
			UI_filled_area *mod_filler = new UI_filled_area;
			memcpy(mod_filler, CDialogTheme::GetUI_filled_areaPtr(my_theme,fillerthem), sizeof(UI_filled_area));
			mod_filler->flags =0;
			mod_filler->c.r =GetRValue(m_FillerC);
			mod_filler->c.g = GetGValue(m_FillerC);
			mod_filler->c.b = GetBValue(m_FillerC);
			mod_filler->c.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			
			CDialogTheme::AllocThemeUI_filled_areaPtr((MMI_theme *)&my_theme,fillerthem,mod_filler);
			ActivateTheme((MMI_theme *)&my_theme);
			*/
			//new version for glory
			//mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_color_themeid);
			//color **c = (color**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			DrawThemeComponent();
			
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
			UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
		
			//UI_filled_area *mod_filler = new UI_filled_area;
			//memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			UI_filled_area *mod_filler = GetNewFiller();//new UI_filled_area;
			if(*old_filler!=NULL)
				memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			else
			    mod_filler->flags = 0;
			
			if(mod_filler->flags ==0||mod_filler->flags&UI_FILLED_AREA_SINGLE_BORDER)
			{
			}
			else
                        	mod_filler->flags =0;
			
			
			mod_filler->c.r =GetRValue(m_FillerC);
			mod_filler->c.g = GetGValue(m_FillerC);
			mod_filler->c.b = GetBValue(m_FillerC);
			mod_filler->c.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			mod_filler->b = NULL;
			*old_filler = mod_filler;
			ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_filler_themeid]=true;
			SetFlag(m_filler_themeid);
			int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
			if(idx!=-1) DrawFlagIcon(idx);
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			m_AddImage = true;
			DrawNonBitmap();
			if(mod_filler->flags ==0)// only text 
				((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
			else if(mod_filler->flags&UI_FILLED_AREA_SINGLE_BORDER)
				((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);

            /* disable border according to MMI_MTE_FILLER_ALLOW_BORDER */
            if (!(the_component->filler_flag & MMI_MTE_FILLER_ALLOW_BORDER))
            {
                ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
            }
			InsertFillerHistory(m_filler_themeid,mod_filler);
			ComHistroy[m_filler_themeid]++;
			ComIdxHistroy[m_filler_themeid]++;
			g_onedit = true;
			g_screen_cb = true; //Update at next refresh
			UpdateListThemeOnDiffTheme();
			if (SelectItemByComponentName(componentName))
			{
				m_ListThemeEditor.SetFocus();
				DrawGreenFlag (m_filler_themeid);		
			}

		}
	}

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::OnFillerac()
{
	/*
	CString fillerthem;
	GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
	if(fillerthem!="")
	{
		if(SelectColor(m_FillerAC)) //Select Color as m_ColRef
		{
			DrawThemeComponent();
			UI_filled_area *mod_filler = new UI_filled_area;
			memcpy(mod_filler, CDialogTheme::GetUI_filled_areaPtr(my_theme,fillerthem), sizeof(UI_filled_area));
			mod_filler->flags =0;
			mod_filler->ac.r =GetRValue(m_FillerAC);
			mod_filler->ac.g = GetGValue(m_FillerAC);
			mod_filler->ac.b = GetBValue(m_FillerAC);
			mod_filler->ac.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			
			CDialogTheme::AllocThemeUI_filled_areaPtr((MMI_theme *)&my_theme,fillerthem,mod_filler);
			ActivateTheme((MMI_theme *)&my_theme);
		}
	}*/
}

void CDialogThemeEditor::OnFillerImage()
{
    if (!m_SupportImage)
    {	
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("This filler does not support image."));
		m_pUIDlg->EnableWindow(true);
        return;
    }
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
    CString fillerthem;
    GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
	if(fillerthem!="")
	{
		unsigned char *bmptr = OpenDrawRetPtr(IDC_FILLER_IMAGE);
		if(bmptr!=NULL)
		{
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
			UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
			UI_filled_area *mod_filler = GetNewFiller();//new UI_filled_area;
			if(*old_filler!=NULL)
				memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			mod_filler->flags = 3;
			mod_filler->b = bmptr;
			*old_filler = mod_filler;
			//ActivateTheme((MMI_theme *)&my_theme);
			SetFlag(m_filler_themeid);
			((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
			m_AddImage = true;
			g_screen_cb = true; //Update at next refresh
		}
		else
		{
			m_AddImage = false;
		}
	}
    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();	
    }	
}

void CDialogThemeEditor::OnImage()
{

	CString imagethem;
	GetDlgItem(IDC_STATIC_IMAGE)->GetWindowText(imagethem);
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}	
	//CString image_type;
	//GetDlgItem(IDC_STATIC_REC)->GetWindowText(image_type);
	if(imagethem!="")
	{
		unsigned char *bmptr = OpenDrawRetPtr(IDC_IMAGE);
		if(bmptr!=NULL)
		{
			/*
			CDialogTheme::AllocThemeImagePtr((MMI_theme *)&my_theme,imagethem,bmptr);
			ActivateTheme((MMI_theme *)&my_theme);*/
			mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_image_themeid);
			unsigned char **image = (unsigned char **) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			*image = bmptr;
			//ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_image_themeid]=true;
			SetFlag(m_image_themeid);
			m_AddImage = true;
			g_screen_cb = true; //Update at next refresh
			//UpdateListThemeOnDiffTheme();
		}
		else
		{
			m_AddImage = false;
		}
	}
	
    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();	
    }	
}

void CDialogThemeEditor::OnFillerbc()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	CString fillerthem;
	GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
	mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
		
    if(!(the_component->filler_flag&MMI_MTE_FILLER_ALLOW_BORDER))
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow("This filler cannot use border.");
		m_pUIDlg->EnableWindow(true);
        ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(1);
        Invalidate();

        if (SelectItemByComponentName(componentName))
        {
            m_ListThemeEditor.SetFocus();
        }
        return;	
    }
	
	if(fillerthem!="")
	{
		if(SelectColor(m_FillerBC)) //Select Color as m_ColRef
		{
			CButton *pBtn=NULL;
			pBtn = (CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER);
			pBtn->SetCheck(false);	
			/*
			DrawThemeComponent();
			UI_filled_area *mod_filler = new UI_filled_area;
			memcpy(mod_filler, CDialogTheme::GetUI_filled_areaPtr(my_theme,fillerthem), sizeof(UI_filled_area));
			mod_filler->flags =0|UI_FILLED_AREA_SINGLE_BORDER;
			mod_filler->border_color.r =GetRValue(m_FillerBC);
			mod_filler->border_color.g = GetGValue(m_FillerBC);
			mod_filler->border_color.b = GetBValue(m_FillerBC);
			mod_filler->border_color.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			
			CDialogTheme::AllocThemeUI_filled_areaPtr((MMI_theme *)&my_theme,fillerthem,mod_filler);
			ActivateTheme((MMI_theme *)&my_theme);*/
			DrawThemeComponent();
			//mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
			UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
			//UI_filled_area *mod_filler = new UI_filled_area;
			//memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			
			UI_filled_area *mod_filler = GetNewFiller();//new UI_filled_area;
			if(*old_filler!=NULL)
				memcpy(mod_filler, *old_filler, sizeof(UI_filled_area));
			
			mod_filler->flags =0|UI_FILLED_AREA_SINGLE_BORDER;
			mod_filler->border_color.r =GetRValue(m_FillerBC);
			mod_filler->border_color.g = GetGValue(m_FillerBC);
			mod_filler->border_color.b = GetBValue(m_FillerBC);
			mod_filler->border_color.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			mod_filler->b = NULL;
			*old_filler = mod_filler;
			ActivateTheme((MMI_theme *)&my_theme);
			//flag[m_filler_themeid]=true;
			SetFlag(m_filler_themeid);
			//int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
		    //if(idx!=-1) DrawFlagIcon(idx);
			GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
			m_AddImage = true;
			DrawNonBitmap();
			((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->SetCheck(0);

			InsertFillerHistory(m_filler_themeid,mod_filler);
			ComHistroy[m_filler_themeid]++;
			ComIdxHistroy[m_filler_themeid]++;
			g_onedit = true;
			g_screen_cb = true; //Update at next refresh
			UpdateListThemeOnDiffTheme();
		    if (SelectItemByComponentName(componentName))
		    {
		        m_ListThemeEditor.SetFocus();
				DrawGreenFlag (m_filler_themeid);
		    }			
		}
	}

    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
    }
}

void CDialogThemeEditor::OnFillersc()
{
	/*
	CString fillerthem;
	GetDlgItem(IDC_STATIC_FILLER)->GetWindowText(fillerthem);
	if(fillerthem!="")
	{
		if(SelectColor(m_FillerSC)) //Select Color as m_ColRef
		{
			DrawThemeComponent();
			UI_filled_area *mod_filler = new UI_filled_area;
			memcpy(mod_filler, CDialogTheme::GetUI_filled_areaPtr(my_theme,fillerthem), sizeof(UI_filled_area));
			mod_filler->flags =0;
			mod_filler->shadow_color.r =GetRValue(m_FillerSC);
			mod_filler->shadow_color.g = GetGValue(m_FillerSC);
			mod_filler->shadow_color.b = GetBValue(m_FillerSC);
			mod_filler->shadow_color.alpha = GetDlgItemInt(IDC_EDIT_ALPHA);
			
			CDialogTheme::AllocThemeUI_filled_areaPtr((MMI_theme *)&my_theme,fillerthem,mod_filler);
			ActivateTheme((MMI_theme *)&my_theme);
		}
	}*/
}

bool CDialogThemeEditor::PreprocessImage(const CString &imageFilename,
                                         mmi_mte_image_enum &imageType,
                                         bool &hasEncodedImage,
                                         CString &encodedImageFilename)
{
    if (imageFilename.Right(4).CompareNoCase(".bmp") == 0)
    {
        if ((m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_ABM) ||
            (m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_AB2))
        {
            CString outputFilename;
            mmi_mte_image_enum outputType;

            if (!EncodeBMPIntoAB2(imageFilename, outputFilename, outputType))
            {
                return false;
            }

            imageType = outputType;
            hasEncodedImage = true;
            encodedImageFilename = outputFilename;
        }
        else
        {
            imageType = MMI_MTE_IMAGE_BMP;
        }
    }
    else if (imageFilename.Right(4).CompareNoCase(".png") == 0)
    {
        if ((m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_ABM) ||
			(m_allowed_image_type & MMI_MTE_IMAGE_9SLICE) ||
            (m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_AB2))
        {
            CString outputFilename;
            mmi_mte_image_enum outputType;

            if (!EncodePNGIntoAB2(imageFilename, outputFilename, outputType))
            {
                return false;
            }

            imageType = outputType;
            hasEncodedImage = true;
            encodedImageFilename = outputFilename;
        }
        else
        {
            imageType = MMI_MTE_IMAGE_PNG;
        }
    }
    else if (imageFilename.Right(4).CompareNoCase(".gif") == 0)
    {
        imageType = MMI_MTE_IMAGE_GIF;
        hasEncodedImage = false;
    }
    else if (imageFilename.Right(4).CompareNoCase(".jpg") == 0)
    {
        imageType = MMI_MTE_IMAGE_JPG;
        hasEncodedImage = false;
    }
    else
    {
        return false;
    }

    return true;
}

bool CDialogThemeEditor::EncodeBMPIntoAB2(const CString &inputFilename,
                                          CString &outputFilename,
                                          mmi_mte_image_enum &outputType)
{
    const CString tempFilename = inputFilename + _T(".AB2");
    mmi_mte_abm_encoder_error_enum errorCode;
    int abmOutputSize;

    errorCode = mmi_mte_encode_abm_image(MMI_MTE_ABMENC_MODE_OUTPUT_FILE,
                                         MMI_MTE_IMAGE_BMP_TO_AB2,
                                         (char*)(LPCSTR)inputFilename,
                                         (char*)(LPCSTR)tempFilename,
                                         &abmOutputSize);

    switch (errorCode)
    {
        case MMI_MTE_ABMENC_NO_ERROR:
            outputType = MMI_MTE_IMAGE_BMP_TO_ABM;
            break;
        case MMI_MTE_AB2ENC_NO_ERROR:
            outputType = MMI_MTE_IMAGE_BMP_TO_AB2;
            break;
        default:
            return false;
    }

    outputFilename = tempFilename;
    return true;
}

bool CDialogThemeEditor::EncodePNGIntoAB2(const CString &inputFilename,
                                          CString &outputFilename,
                                          mmi_mte_image_enum &outputType)
{
    const CString tempFilename = inputFilename + _T(".AB2");
    mmi_mte_abm_encoder_error_enum errorCode;
    int ab2OutputSize;

    errorCode = mmi_mte_encode_abm_image(MMI_MTE_ABMENC_MODE_OUTPUT_FILE,
                                         MMI_MTE_IMAGE_PNG_TO_AB2,
                                         (char*)(LPCSTR)inputFilename,
                                         (char*)(LPCSTR)tempFilename,
                                         &ab2OutputSize);

    switch (errorCode)
    {
        case MMI_MTE_ABMENC_NO_ERROR:
            outputType = MMI_MTE_IMAGE_PNG_TO_ABM;
            break;

        case MMI_MTE_AB2ENC_NO_ERROR:
            outputType = MMI_MTE_IMAGE_PNG_TO_AB2;
            break;

        default:
            return false;
    }

    outputFilename = tempFilename;
    return true;
}

bool CDialogThemeEditor::EncodePNGIntoABM(const CString &inputFilename,
                                          CString &outputFilename)
{
    const CString tempFilename = inputFilename + _T(".ABM");
    mmi_mte_abm_encoder_error_enum errorCode;
    int abmOutputSize;

    errorCode = mmi_mte_encode_abm_image(MMI_MTE_ABMENC_MODE_OUTPUT_FILE,
                                         MMI_MTE_IMAGE_PNG_TO_ABM,
                                         (char*)(LPCSTR)inputFilename,
                                         (char*)(LPCSTR)tempFilename,
                                         &abmOutputSize);

    switch (errorCode)
    {
        case MMI_MTE_ABMENC_NO_ERROR:
            break;

        default:
            return false;
    }

    outputFilename = tempFilename;
    return true;
}

bool CDialogThemeEditor::DecodeABMIntoBMP(const char *abmImageBuffer,
                                          int abmImageSize,
                                          int imageWidth,
                                          int imageHeight,
                                          CString &outputFilename)
{
    const int bitmapBufferSize = imageWidth * imageHeight * 4;
    char *bitmapBuffer = new char[bitmapBufferSize];
    ASSERT(bitmapBuffer != NULL);

    mmi_mte_return_code_enum errorCode; 

    errorCode = mmi_mte_start_decode_image(
        MMI_MTE_IMAGE_PNG_TO_ABM,
        const_cast<char *>(abmImageBuffer),
        abmImageSize,
        bitmapBuffer,
        bitmapBufferSize,
        imageWidth,
        imageHeight,
        NULL,
        0
    );

    if (errorCode != MMI_MTE_SUCCESS)
    {
        delete [] bitmapBuffer;
        return false;
    }

    outputFilename = GetTempFilename();

    OutputBitmapToFile(bitmapBuffer,
                       imageWidth,
                       imageHeight,
                       outputFilename);

    delete [] bitmapBuffer;
    return true;
}

void CDialogThemeEditor::SaveBuffertoBitmapFile(unsigned int idc)
{

	char path[1024],MoDISEXE[1024],tempbuf[1024];
	char *name;
	memset(path, 0, sizeof(tempbuf));
	memset(tempbuf, 0, sizeof(tempbuf));
	memset(MoDISEXE, 0, sizeof(MoDISEXE));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return ;
	strncpy(MoDISEXE, path, strlen(path));
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%stmp.bmp", tempbuf);
	m_BMPFile.Format(path);
		//Create a new file for writing

	if(idc==IDC_FILLER_IMAGE)
	{
		FILE *pFile = fopen(path, "wb");
		int width = m_filler_bitmap_info.bmiHeader.biWidth;
		int height = m_filler_bitmap_info.bmiHeader.biHeight;
		
		BITMAPFILEHEADER bmfh;	
		int nBitsOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		LONG lImageSize = width * height * 4;
		LONG lFileSize = nBitsOffset + lImageSize;
		bmfh.bfType = 'B'+('M'<<8);			
		bmfh.bfOffBits = nBitsOffset;		
		bmfh.bfSize = lFileSize;				
		bmfh.bfReserved1 = bmfh.bfReserved2 = 0;
		//Write the bitmap file header
		UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), pFile);
		//And then the bitmap info header
		UINT nWrittenInfoHeaderSize = fwrite(&m_filler_bitmap_info.bmiHeader, 1, sizeof(BITMAPINFOHEADER), pFile);
		//Finally, write the image data itself -- the data represents our drawing
		UINT nWrittenDIBDataSize = fwrite(m_filler_image_data_buffer, 1, width * height * 4, pFile);
		
		fclose(pFile);	
	}
	else if( idc==IDC_IMAGE)
	{
		FILE *pFile = fopen(path, "wb");
		int width = m_image_bitmap_info.bmiHeader.biWidth;
		int height = m_image_bitmap_info.bmiHeader.biHeight;
		
		BITMAPFILEHEADER bmfh;	
		int nBitsOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
		LONG lImageSize = width * height * 4;
		LONG lFileSize = nBitsOffset + lImageSize;
		bmfh.bfType = 'B'+('M'<<8);			
		//bmfh.bfType = 0x4d42;
		bmfh.bfOffBits = nBitsOffset;		
		bmfh.bfSize = lFileSize;				
		bmfh.bfReserved1 = bmfh.bfReserved2 = 0;
		//Write the bitmap file header
		UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), pFile);
		//And then the bitmap info header
		UINT nWrittenInfoHeaderSize = fwrite(&m_image_bitmap_info.bmiHeader, 1, sizeof(BITMAPINFOHEADER), pFile);
		//Finally, write the image data itself -- the data represents our drawing
		UINT nWrittenDIBDataSize = fwrite(m_image_image_data_buffer, 1, width * height * 4, pFile);
		
		fclose(pFile);	
	}
}

CString CDialogThemeEditor::GetImageFileFilter()
{
    std::vector<std::string> fileExtensions;

    if (m_allowed_image_type & MMI_MTE_IMAGE_GIF)
    {
        fileExtensions.push_back("*.gif");
    }

    if (m_allowed_image_type & MMI_MTE_IMAGE_JPG)
    {
        fileExtensions.push_back("*.jpg");
    }

    if ((m_allowed_image_type & MMI_MTE_IMAGE_BMP) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_ABM) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_AB2))
    {
        fileExtensions.push_back("*.bmp");
    }

    if ((m_allowed_image_type & MMI_MTE_IMAGE_PNG) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_ABM) ||
		(m_allowed_image_type & MMI_MTE_IMAGE_9SLICE) ||		
        (m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_AB2))
    {
        fileExtensions.push_back("*.png");
    }

    ASSERT(!fileExtensions.empty());

    std::string filterSetting("All Supported Image Files|");
    filterSetting += Join(fileExtensions, std::string(";"));
    filterSetting += "||";

    return filterSetting.c_str();
}

void CDialogThemeEditor::GetImageFileFilterW( WCHAR *filter)
{
	WCHAR tmp[500];
	int i, size ;
	//example:
	//ofn.lpstrFilter = "Playlists: m3u.\0*.m3u\0Music Files :mp1, mp2, mp3, wav, ogg.\0*.mp1;*.mp2;*.mp3;*.wav;*.ogg\0";
	wcscpy( tmp, L"All Supported Image Files" );
	for( size = 0, i = 0 ; i < (int)wcslen( tmp ) ; ++i )
		filter[ i ] = tmp[ i ] ;
	size += wcslen( tmp );
	filter[ size++ ] = L'\0' ; 

    if (m_allowed_image_type & MMI_MTE_IMAGE_GIF)
    {
		wcscpy( tmp, L"*.gif;" );		
		for( i = 0 ; i < (int)wcslen( tmp ) ; ++i )
			filter[ size + i ] = tmp[ i ] ;
		size += wcslen( tmp );
    }

    if (m_allowed_image_type & MMI_MTE_IMAGE_JPG)
    {
		wcscpy( tmp, L"*.jpg;" );
		for( i = 0 ; i < (int)wcslen( tmp ) ; ++i )
			filter[ size + i ] = tmp[ i ] ;
		size += wcslen( tmp );        
    }

    if ((m_allowed_image_type & MMI_MTE_IMAGE_BMP) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_ABM) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_BMP_TO_AB2))
    {
		wcscpy( tmp, L"*.bmp;" );
		for( i = 0 ; i < (int)wcslen( tmp ) ; ++i )
			filter[ size + i ] = tmp[ i ] ;
		size += wcslen( tmp );        
    }

    if ((m_allowed_image_type & MMI_MTE_IMAGE_PNG) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_ABM) ||
		(m_allowed_image_type & MMI_MTE_IMAGE_9SLICE) ||
        (m_allowed_image_type & MMI_MTE_IMAGE_PNG_TO_AB2))
    {         
		wcscpy( tmp, L"*.png;" );
		for( i = 0 ; i < (int)wcslen( tmp ) ; ++i )
			filter[ size + i ] = tmp[ i ] ;
		size += wcslen( tmp );        
    }
	filter[ size-1 ] = L'\0' ;
	filter[ size++ ] = L'\0' ;

}


unsigned char* CDialogThemeEditor::OpenDrawRetPtr(unsigned int controlID)
{
/*
    CFileDialog openFileDialog(
        TRUE,
        NULL,
        NULL,
        OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR,
        GetImageFileFilter()
    );

    if (openFileDialog.DoModal() != IDOK)
    {
        return NULL;   
    }
    */
 
	WCHAR filter[500];
	int head_len = 0;
	m_bautoclose = false;
	GetImageFileFilterW( filter ); 
 	MoDISFileDialogW openFileDialog( this->GetSafeHwnd(), 
						NULL,NULL,OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR, 
						filter ) ;
    m_pUIDlg->EnableWindow(false);
	if( !openFileDialog.LoadFile() )
	{
	m_pUIDlg->EnableWindow(true);
		return NULL;
	}
		m_pUIDlg->EnableWindow(true);
    mmi_mte_image_enum imageType;
    bool hasEncodedImage;
    CString encodedImageFilename;

    if (!PreprocessImage(//openFileDialog.GetPathName(),
    					 openFileDialog.GetFileNameA().c_str(),
                         imageType,
                         hasEncodedImage,
                         encodedImageFilename))
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow("Failed to process this image.");
		m_pUIDlg->EnableWindow(true);
        return NULL;
    }

    const CString imageFilename = hasEncodedImage ? encodedImageFilename : openFileDialog.GetFileNameA().c_str();
        //hasEncodedImage ? encodedImageFilename : openFileDialog.GetPathName();

    if (!(imageType & m_allowed_image_type))
    {
		if (m_allowed_image_type != MMI_MTE_IMAGE_9SLICE)
		{
			m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("Unsupported image type."));
		m_pUIDlg->EnableWindow(true);
        return NULL;
    }
    }

    CFile file; 

    if (!file.Open(imageFilename, CFile::modeRead))
    {   
		m_pUIDlg->EnableWindow(false);
        ::MessageShow("Failed to open this image.");
		m_pUIDlg->EnableWindow(true);
        return NULL;
    } 

    file.Seek(0,CFile::begin); 
    int len = (int)file.GetLength();
    unsigned char *pbuf= new unsigned char[len];
    UINT nBytesRead = file.Read( pbuf, len );
    file.Close();
    
    //CString imageStr="";
    wchar_t* imageStr=NULL;
    imageStr = (wchar_t*)mmi_mte_get_image_info_string(imageType);
    if(imageStr!=NULL&&(*imageStr!=0))
    {
        //::MessageShow(imageStr);
		m_pUIDlg->EnableWindow(false);
        MessageBoxW(this->m_hWnd,imageStr,L"Image", MB_OK); 
		m_pUIDlg->EnableWindow(true);
    }	

    int width, height;

    if(0!=mmi_mte_get_image_dimension(imageType, (char *)pbuf, &width, &height))
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow("Failed to get dimension of the image file.");
		m_pUIDlg->EnableWindow(true);
        if(hasEncodedImage) DeleteFile(imageFilename);
        {
            Invalidate();
        }
        return NULL;
    }

    if (!FindTheCompIsSlice(m_old_theme_idx))
    if(width >m_max_width || height>m_max_height)
    {
        CString msg;
        msg.Format("The image file (%d x %d) exceeds the maximum size (%d x %d).",
        width, height,
        m_max_width, m_max_height);
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(msg);
		m_pUIDlg->EnableWindow(true);
        if(hasEncodedImage) DeleteFile(imageFilename);
        Invalidate();
        return NULL; 
    }

  if (!FindTheCompIsSlice(m_old_theme_idx))
  if(width!=m_recommend_width||height!=m_recommend_height)
  {
	  CString msg;

	  msg.Format("The image file (%d x %d) does not have recommended size (%d x %d).",
                       width, height,
                       m_recommend_width, m_recommend_height);
	  m_pUIDlg->EnableWindow(false);
      ::MessageShow(msg);
	  m_pUIDlg->EnableWindow(true);
	  if(hasEncodedImage) DeleteFile(imageFilename);	
	  Invalidate();
	  return NULL;

	  //if (IDOK !=::MessageShow(dismatstr, MB_OKCANCEL))
	  //{
		//	  if(hasEncodedImage) DeleteFile(imageFilename);	
		//	  Invalidate();
		//	  return NULL;
	  //}

  }

  if (FindTheCompIsSlice(m_old_theme_idx))
  {
	  int tempwidth,tempheight;

	  	if (g_MMI_width == m_max_height && g_MMI_height == m_max_width)
		{
			tempwidth = m_max_width;
			tempheight =m_max_height ;
		}
		else
		{
			tempwidth = g_MMI_width;
			tempheight = g_MMI_height;
		}
	  if(width >tempwidth || height> tempheight)
	  {
		  CString msg;
		  msg.Format("The image file (%d x %d) exceeds the maximum size (%d x %d).",
			  width, height,
			  tempwidth, tempheight);

		  m_pUIDlg->EnableWindow(false);
		  ::MessageShow(msg);
		  m_pUIDlg->EnableWindow(true);
		  if(hasEncodedImage) DeleteFile(imageFilename);
		  Invalidate();
		  return NULL; 
	  }
  }
  if (FindTheCompIsSlice(m_old_theme_idx))
  {
	 head_len = 20 + 8;
  }
  else
  {
	 head_len = 8;
  }
  char header[28];
  
  int aa = imageType;
  unsigned char *bmptr = new unsigned char[len+head_len];

  for(int ii=0;ii<28;ii++)
  {
	  
	  header[ii] = 0x00;
	 
  }
  if (FindTheCompIsSlice(m_old_theme_idx))
  {
	  m_nValueRight = width - 1 > 0 ? width - 1 : 0;
	  m_nValueBottom  =  height - 1 > 0 ? height - 1 : 0;

	  mmi_mte_get_image_9slice_header(header, imageType,&head_len, width, height,len+20,m_nValueLeft,m_nValueTop,m_nValueRight,m_nValueBottom); 
//	  mmi_mte_get_image_9slice_header(header, MMI_MTE_IMAGE_9SLICE,&head_len, width, height,0,0,0,0);
	  	 header[9]=0&0xFF; 
	  for(int i=0;i<len+head_len;i++)
	  {
		  if(i<head_len)
			  *(bmptr+i) = header[i];
		  else
			  *(bmptr+i) = pbuf[i-head_len];
	  }
/*	  int aa = len;
	  *(bmptr+2) = aa & 0xFF;
	  *(bmptr+3) = (aa >> 8) & 0xFF;
      *(bmptr+4) = (aa >> 16) & 0xFF;*/
//	  *(bmptr+8) =  *(bmptr+0);
//	  *(bmptr+0) = 0x3E;
  }
  else
  {
  mmi_mte_get_image_header(header, imageType, width, height, len);

	
		for(int i=0;i<len+8;i++)
		{
			if(i<8)
				*(bmptr+i) = header[i];
			else
				*(bmptr+i) = pbuf[i-8];
		}
  }
  if(controlID==IDC_FILLER_IMAGE)
  {
	
	if(m_filler_image_data_buffer!=NULL)
	{
		delete m_filler_image_data_buffer;
		m_filler_image_data_buffer = NULL;
	}
	int image_size = width*height* 4;
	char *tmp_buffer = new char[image_size];
	m_filler_image_data_buffer= new char[image_size];
	
	if (FindTheCompIsSlice(m_old_theme_idx))
	{
		if(1==mmi_mte_start_decode_image(MMI_MTE_IMAGE_9SLICE,(char *)(bmptr+8) , len+20, tmp_buffer, width * height * 4, width, height, NULL, 0))
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
			return NULL;
		}

	}
	else
	{
	if(1==mmi_mte_start_decode_image(imageType,(char *)pbuf , len, tmp_buffer, width * height * 4, width, height, NULL, 0))
	{
		m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
		return NULL;
	}

	}
	
	for (int y = height - 1; y >= 0; y--)
	{
		memcpy(m_filler_image_data_buffer + (height - 1 - y) * width * 4, tmp_buffer + y * width * 4, width * 4);
	}
	delete tmp_buffer;
	memset(&m_filler_bitmap_info.bmiHeader, 0, sizeof(BITMAPINFOHEADER));
	m_filler_bitmap_info.bmiHeader.biSize = sizeof(m_filler_bitmap_info.bmiHeader);
	m_filler_bitmap_info.bmiHeader.biWidth = width;
	m_filler_bitmap_info.bmiHeader.biHeight = height;
	m_filler_bitmap_info.bmiHeader.biPlanes = 1;
	m_filler_bitmap_info.bmiHeader.biBitCount = 32;
	m_filler_bitmap_info.bmiHeader.biCompression = BI_RGB;
	m_filler_bitmap_info.bmiHeader.biSizeImage = image_size;
	m_filler_bitmap_info.bmiHeader.biClrUsed = 0;
	m_filler_bitmap_info.bmiHeader.biClrImportant = 0;	
	
	SaveBuffertoBitmapFile(controlID);
	ShowBMP();
	if(m_filler_image_data_buffer!=NULL)
	{
			delete m_filler_image_data_buffer;
			m_filler_image_data_buffer = NULL;
	}
  }
  else if(controlID==IDC_IMAGE)
  {
	if(m_image_image_data_buffer!=NULL)
	{
		delete m_image_image_data_buffer;
		m_image_image_data_buffer = NULL;
	}
	int image_size = width*height* 4;

	m_image_image_data_buffer= new char[image_size];
	char *tmp_buffer = new char[image_size];
	
	if (FindTheCompIsSlice(m_old_theme_idx))
	{
		if(1==mmi_mte_start_decode_image(MMI_MTE_IMAGE_9SLICE,(char *)(bmptr+8) , len+20, tmp_buffer, width * height * 4, width, height, NULL, 0))
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
			return NULL;
		}
		
	}
	else
	{
	if(1==mmi_mte_start_decode_image(imageType,(char *)pbuf , len, tmp_buffer, image_size, width, height, NULL, 0))
	{
		m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
		return NULL;
	}
	}
	
	for (int y = height - 1; y >= 0; y--)
	{
		memcpy(m_image_image_data_buffer + (height - 1 - y) * width * 4, tmp_buffer + y * width * 4, width * 4);
	}
	delete tmp_buffer;
	
	
	memset(&m_image_bitmap_info.bmiHeader, 0, sizeof(BITMAPINFOHEADER));

	m_image_bitmap_info.bmiHeader.biSize = sizeof(m_image_bitmap_info.bmiHeader);
	m_image_bitmap_info.bmiHeader.biWidth = width;
	m_image_bitmap_info.bmiHeader.biHeight = height;
	m_image_bitmap_info.bmiHeader.biPlanes = 1;
	m_image_bitmap_info.bmiHeader.biBitCount = 32;
	m_image_bitmap_info.bmiHeader.biCompression = BI_RGB;
	m_image_bitmap_info.bmiHeader.biSizeImage = image_size;
	m_image_bitmap_info.bmiHeader.biClrUsed = 0;
	m_image_bitmap_info.bmiHeader.biClrImportant = 0;	
	SaveBuffertoBitmapFile(controlID);
	ShowBMP();
	if(m_image_image_data_buffer!=NULL)
	{
		delete m_image_image_data_buffer;
		m_image_image_data_buffer = NULL;
	}
	/*
	SetDIBitsToDevice(pdc->m_hDC, image.left, image.top, width, height,   
	0, 0, 0,  height,  m_image_image_data_buffer,   &m_image_bitmap_info, DIB_RGB_COLORS);
	*/
  }
   if(hasEncodedImage) DeleteFile(imageFilename);
  return bmptr;
}

void CDialogThemeEditor::OnItemchangedListThemeEditor(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if (!g_hidetheme)
	{
	  if (::GetKeyState(VK_UP) & 0x8000 ||::GetKeyState(VK_DOWN) & 0x8000 )
			OnNMClickListThemeEditor(pNMHDR, pResult);
		else	
		return;
	}
	else
		OnNMClickListThemeEditor(pNMHDR, pResult);
	// TODO: Add your control notification handler code here
	
//	*pResult = 0;

    // Owen
 /*   if (IsEditingAnimation())
    {
        const int selectedIndex =
                m_ListThemeEditor.GetNextItem(-1, LVNI_ALL| LVNI_SELECTED);

	    if (selectedIndex == m_old_theme_idx)
        {
            return;
        }
        if (selectedIndex!=-1)
        {
        LeaveAnimationEditingMode();
    }

    }

	m_editing = true;
	
	if (!m_bShowNoEditAgain)
	{
		m_bShowNoEditAgain = true; 
		m_ListThemeEditor.SetItemState(-1,0, LVIS_SELECTED);  
		OutputDebugString("m_ListThemeEditor.SetItemState(-1,LVIS_SELECTED, LVIS_SELECTED);");
				
	} 
	else
	ThemeComEdit();
	//Invalidate();
	*/


}
void CDialogThemeEditor::DisableThemeComponent(bool c, bool f, bool i,bool in)
{
	//Note this is not available in 08A
	if(!c&&!f&&!i&&!in) //Calling DisableThemeComponent(false,false,false,galse);
	{
		if( IsEditingAnimation() )
			LeaveAnimationEditingMode();
	}
	
    // Owen
    if (f)
    {
        GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->ShowWindow(SW_SHOW);
    }
    else
    {
        GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->ShowWindow(SW_HIDE);
    }

//GetDlgItem(IDC_STATIC_GROUP_COLOR)->ShowWindow(c);
	//Invalidate();
	GetDlgItem(IDC_STATIC_COLOR)->ShowWindow(c);
	GetDlgItem(IDC_COLOR)->ShowWindow(c);
	GetDlgItem(IDC_CHECK_BOARDER)->ShowWindow(c);

	GetDlgItem(IDC_STATIC_GROUP_FILLER)->ShowWindow(true);
	GetDlgItem(IDC_FILLER_C)->ShowWindow(f);
	GetDlgItem(IDC_FILLER_BC)->ShowWindow(f);
	GetDlgItem(IDC_FILLER_IMAGE)->ShowWindow(f||i);
	GetDlgItem(IDC_STATIC_TEXT_COLOR)->ShowWindow(f);
	GetDlgItem(IDC_STATIC_TEXT_BC)->ShowWindow(f);
//	GetDlgItem(IDC_STATIC_FILLER_IMAGE)->ShowWindow(f);
	GetDlgItem(IDC_STATIC_FILLER)->ShowWindow(f);
	GetDlgItem(IDC_CHECK_FILLER_BORDER)->ShowWindow(f);
	GetDlgItem(IDC_CHECK_TRANSPARENT)->ShowWindow(f);

	//GetDlgItem(IDC_STATIC_GROUP_IMAGE)->ShowWindow(i);
	GetDlgItem(IDC_STATIC_IMAGE)->ShowWindow(i);
//	GetDlgItem(IDC_IMAGE)->ShowWindow(i);
	GetDlgItem(IDC_BUTTON_UPINT)->ShowWindow(in);
	GetDlgItem(IDC_STATIC_INTEGER)->ShowWindow(in);
	GetDlgItem(IDC_EDIT_INTEGER)->ShowWindow(in);
	GetDlgItem(IDC_STATIC_MAXMIN)->ShowWindow(in);
	m_drawcolor=c;
	m_drawfiller=f;
	if(!c)
	{
		m_ColRef=RGB(0xDC,0xDC,0xDC);
		DrawThemeComponent();

	}

	if(!f)
	{
		m_FillerC=RGB(0xDC,0xDC,0xDC);
		m_FillerBC=RGB(0xDC,0xDC,0xDC);
		if(m_filler_image_data_buffer!=NULL)
		{
			delete m_filler_image_data_buffer;
			m_filler_image_data_buffer = NULL;
			
		}
		DrawThemeComponent();
	}

	
	
	if(!i)
	{
		if(m_image_image_data_buffer!=NULL)
		{
			delete m_image_image_data_buffer;
			m_image_image_data_buffer = NULL;
		}
		DrawThemeComponent();
	}

	if(f||i)
	{
		GetDlgItem(IDC_STATIC_REC)->ShowWindow(true);
		GetDlgItem(IDC_STATIC_REC2)->ShowWindow(true);
		GetDlgItem(IDC_STATIC_REC_WH)->ShowWindow(true);
		GetDlgItem(IDC_STATIC_REC_MWH)->ShowWindow(true);
		GetDlgItem(IDC_BUTTON_IMAGE)->ShowWindow(true);
/*
		if(m_filler_image_data_buffer!=NULL)
		{
			delete m_filler_image_data_buffer;
			m_filler_image_data_buffer = NULL;
			Invalidate();
		}

		if(m_image_image_data_buffer!=NULL)
		{
			delete m_image_image_data_buffer;
			m_image_image_data_buffer = NULL;
			Invalidate();
		}*/

	}
	else
	{
		GetDlgItem(IDC_STATIC_REC)->ShowWindow(false);
		GetDlgItem(IDC_STATIC_REC2)->ShowWindow(false);
		GetDlgItem(IDC_STATIC_REC_WH)->ShowWindow(false);
		GetDlgItem(IDC_STATIC_REC_MWH)->ShowWindow(false);
		GetDlgItem(IDC_BUTTON_IMAGE)->ShowWindow(false);
	}
	if(c)
		GetDlgItem(IDC_STATIC_GROUP_FILLER)->SetWindowText("Color");
	if(f)
		GetDlgItem(IDC_STATIC_GROUP_FILLER)->SetWindowText("Highlight");
	if(i)
		GetDlgItem(IDC_STATIC_GROUP_FILLER)->SetWindowText("Image");
	if(in)
		GetDlgItem(IDC_STATIC_GROUP_FILLER)->SetWindowText("Integer");
	
	if(!c&&!f&&!i&&!in)
	{
		GetDlgItem(IDC_STATIC_GROUP_FILLER)->SetWindowText("Please click one theme component to edit");
	
	}
}


void CDialogThemeEditor::SetItemTextU(HWND hwnd, int nItem, int subitem, wchar_t *str)
{
	LVITEM lvi;
	lvi.iSubItem = subitem;
	lvi.pszText = (LPTSTR) str;
	::SendMessage(hwnd, LVM_SETITEMTEXTW, nItem, (LPARAM)&lvi);
}



void CDialogThemeEditor::DisplayImagebyCom(unsigned int idc,unsigned char *ptr)
{

	char *img_data_ptr;
	mmi_mte_image_enum mte_image_type;
	int width;
	int height; 
	int size;
	
	std::map<int, type_9slice>::iterator slice_Iter;
	
	mmi_mte_get_image_resource_info((char *)ptr, -1, &img_data_ptr, &mte_image_type, &width, &height, &size, NULL, NULL);
 	
 	if (m_allowed_image_type == MMI_MTE_IMAGE_NONE)
    {
		DrawNonBitmap();
        return;
    }
	if (mte_image_type == MMI_MTE_IMAGE_9SLICE)
	{
		m_bSliceComponent = true;
		int result_header_size = 8 + 20;
		char theme_comp_id[24];
		m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);
  	
  		if (!FindTheCompIsSlice(m_old_theme_idx))
		{

 			list_slice.push_back(atoi(theme_comp_id));
		}
		ImageRecDisplay(); // for special case Filler not allow add image
		/* insufficient size */
		if (size < result_header_size)
		{
			return ;
		}
		int repeat = ptr[9];
	
		int left = ptr[4 + 8];
		left += ptr[5 + 8]<<8;
		
		int top = ptr[8 + 8];
		top += ptr[9 + 8]<<8;

		int right = ptr[12 + 8];
		right += ptr[13 + 8]<<8;

		int bottom = ptr[16 + 8]; 
		bottom += ptr[17 + 8]<<8;
		
		m_ntop = top;
		m_nleft = left;
		m_nright = right;
		m_nbottom = bottom;

	//	char theme_comp_id[24];
	//	m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);

		slice_Iter = map_slice_value.find(atoi(theme_comp_id));
	 	if (slice_Iter == map_slice_value.end())
		{
			slice_value.nleft = left;
			slice_value.ntop = top;
			slice_value.nright = right;
			slice_value.nbottom = bottom;
			
			map_slice_value.insert(std::make_pair(atoi(theme_comp_id),slice_value));
		}
		else
		{
			slice_Iter->second.nleft = left;
			slice_Iter->second.ntop = top;
			slice_Iter->second.nright = right;
			slice_Iter->second.nbottom = bottom;
		}
	
		m_nValueLeft = left;
		m_nValueTop = top ;
		m_nValueRight = right;
		m_nValueBottom = bottom;
		UpdateData(FALSE);

		CString str;
/*		str.Format(_T("%d"), left);
		m_SliceLeft.SetWindowText(str);

		str.Format(_T("%d"), top);
		m_SliceTop.SetWindowText(str);

		str.Format(_T("%d"), right);
		m_SliceRight.SetWindowText(str);

		str.Format(_T("%d"), bottom);
		m_SliceBottom.SetWindowText(str);*/
		if (g_MMI_width == m_max_height && g_MMI_height == m_max_width)
		{
			str.Format("Max size: (%d, %d)", m_max_width, m_max_height);
		}
		else
		str.Format("Max size: (%d, %d)", g_MMI_width, g_MMI_height);
		GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(str);

		ShowHideSliceControls(true);
		
	}
	else
	{
		if (!m_bSliceComponent)
		{
			ShowHideSliceControls(false);
		}
		
	}
	
	if(idc==IDC_FILLER_IMAGE)
	{
		if(m_filler_image_data_buffer!=NULL)
		{
			delete m_filler_image_data_buffer;
			m_filler_image_data_buffer = NULL;
		}
//		m_filler_image_data_buffer= new char[width*height* 4];
//		mmi_mte_start_decode_image(mte_image_type,img_data_ptr , size, m_filler_image_data_buffer, width * height * 4, width, height, NULL);
	    int image_size = width*height* 4;
		char *tmp_buffer = new char[image_size];
		m_filler_image_data_buffer= new char[image_size];
		
		if(1==mmi_mte_start_decode_image(mte_image_type,img_data_ptr , size, tmp_buffer, image_size, width, height, NULL, 0))
		{
		    m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
			return ;
		}
		for (int y = height - 1; y >= 0; y--)
		{
			memcpy(m_filler_image_data_buffer + (height - 1 - y) * width * 4, tmp_buffer + y * width * 4, width * 4);
		}
		delete tmp_buffer;
		memset(&m_filler_bitmap_info.bmiHeader, 0, sizeof(BITMAPINFOHEADER));
		m_filler_bitmap_info.bmiHeader.biSize = sizeof(m_filler_bitmap_info.bmiHeader);
		m_filler_bitmap_info.bmiHeader.biWidth = width;
		m_filler_bitmap_info.bmiHeader.biHeight = height;
		m_filler_bitmap_info.bmiHeader.biPlanes = 1;
		m_filler_bitmap_info.bmiHeader.biBitCount = 32;
		m_filler_bitmap_info.bmiHeader.biCompression = BI_RGB;
		m_filler_bitmap_info.bmiHeader.biSizeImage = width * height * 4;
		m_filler_bitmap_info.bmiHeader.biClrUsed = 0;
		m_filler_bitmap_info.bmiHeader.biClrImportant = 0;	
		SaveBuffertoBitmapFile(idc);
		ShowBMP();
		if(m_filler_image_data_buffer!=NULL)
		{
			delete m_filler_image_data_buffer;
			m_filler_image_data_buffer = NULL;
		}
	  }
	  else if(idc==IDC_IMAGE)
	  {
		if(m_image_image_data_buffer!=NULL)
		{
			delete m_image_image_data_buffer;
			m_image_image_data_buffer = NULL;
		}
		//m_image_image_data_buffer= new char[width*height* 4];
		//mmi_mte_start_decode_image(mte_image_type,img_data_ptr , size, m_image_image_data_buffer, width * height * 4, width, height, NULL);
  
		int image_size = width*height* 4;
		char *tmp_buffer = new char[image_size];
		m_image_image_data_buffer= new char[image_size];
		
		if(1==mmi_mte_start_decode_image(mte_image_type,img_data_ptr , size, tmp_buffer, image_size, width, height, NULL, 0))
		{
		   m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to decode the image.");
			m_pUIDlg->EnableWindow(true);
			return ;
		}
		for (int y = height - 1; y >= 0; y--)
		{
			memcpy(m_image_image_data_buffer + (height - 1 - y) * width * 4, tmp_buffer + y * width * 4, width * 4);
		}
		delete tmp_buffer;

		memset(&m_image_bitmap_info.bmiHeader, 0, sizeof(BITMAPINFOHEADER));
		m_image_bitmap_info.bmiHeader.biSize = sizeof(m_image_bitmap_info.bmiHeader);
		m_image_bitmap_info.bmiHeader.biWidth = width;
		m_image_bitmap_info.bmiHeader.biHeight = height;
		m_image_bitmap_info.bmiHeader.biPlanes = 1;
		m_image_bitmap_info.bmiHeader.biBitCount = 32;
		m_image_bitmap_info.bmiHeader.biCompression = BI_RGB;
		m_image_bitmap_info.bmiHeader.biSizeImage = width * height * 4;
		m_image_bitmap_info.bmiHeader.biClrUsed = 0;
		m_image_bitmap_info.bmiHeader.biClrImportant = 0;	
		//wayne
		SaveBuffertoBitmapFile(idc);
		ShowBMP();
		if(m_image_image_data_buffer!=NULL)
		{
			delete m_image_image_data_buffer;
			m_image_image_data_buffer = NULL;
		}
	  }
 }


void CDialogThemeEditor::OnPaint() 
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{	
		RECT		window_info;
		GetWindowRect(&window_info);
		int newh=0,neww=0;
		newh = window_info.bottom-window_info.top;
		neww = window_info.right-window_info.left;
		
		//TRACE("(neww-m_oldw) = %d\n",neww-m_oldw);
		//TRACE("(newh-m_oldh) = %d\n",newh-m_oldh);
		 // beacause neww is size fixed
		
		m_st1.GetClientRect( &rectStaticClient );
		rectStaticClient.NormalizeRect();
	
		m_st1.ClientToScreen( &rectStaticClient );
		ScreenToClient( &rectStaticClient);

		CPaintDC dc(this);

        // Owen
        if (IsEditingAnimation())
        {
            dc.SetStretchBltMode(HALFTONE);
            ::SetBrushOrgEx(dc.GetSafeHdc(), 0, 0, NULL);

            for (ImageBlocks::const_iterator iter = m_ImageBlocks.begin();
                 iter != m_ImageBlocks.end();
                 iter++)
            {
                iter->DrawPreview(dc);
            }

            ASSERT(m_SelectedImageBlock != m_ImageBlocks.end());
            m_SelectedImageBlock->DrawSelection(dc);
			if (m_SelectedImageBlock->HasRawImage())
			{
				GetDlgItem(IDC_ANIMATION_IMAGE_ADD)->SetWindowText(_T("Replace"));
			}
			else
			{
				GetDlgItem(IDC_ANIMATION_IMAGE_ADD)->SetWindowText(_T("Add"));
			}
        }
        else
        {
			offset_for_slice_x = offsetx - rectStaticClient.left;
			offset_for_slice_y = offsety+(newh-m_oldh) - rectStaticClient.top;
            dc.BitBlt(offsetx+0/*(neww-m_oldw)*/,offsety+(newh-m_oldh),m_size.cx,m_size.cy, 
                      &m_dcMem, sourcex, sourcey,SRCCOPY);
        }
        UpdateListThemeOnDiffTheme();
		erase=false;
		DrawThemeComponent();
		/*
		if(color_dlg!=NULL) 
		{
			color_dlg->DrawRGB();
		}*/
		m_oldh = newh;
		m_oldw = neww;
		CDialog::OnPaint();
		
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.

void CDialogThemeEditor::ShowBMP() 
{
	// TODO: Add your control notification handler code here

	if(m_hBmpNew != NULL )
		DeleteObject(m_hBmpNew);
	sourcex=sourcey=0;//
	if(m_BMPFile.IsEmpty())
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Could not detect BMP file.");
		m_pUIDlg->EnableWindow(true);
	}
	else{
		if(m_BMPFile.Right(3)!="bmp")
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("Please select a BMP file.");
			m_pUIDlg->EnableWindow(true);
		}
		else
		{
				//HBITMAP inverse_bmp;
			//inverse_bmp 
			m_hBmpNew	=	 (HBITMAP) LoadImage(
			AfxGetInstanceHandle(),   // handle to instance
			m_BMPFile,  // name or identifier of the image (root is where project is)
			IMAGE_BITMAP,        // image types
			0,     // desired width
			0,     // desired height
			LR_LOADFROMFILE); 
			
			if( m_hBmpNew == NULL ){ 
				m_pUIDlg->EnableWindow(false);
			::MessageShow("Failed to load the image.");
			m_pUIDlg->EnableWindow(true);
			}
	
   // put the HBITMAP info into the CBitmap (but not the bitmap itself)
			else{
				//m_hBmpNew = GetRotatedBitmap( (HBITMAP)inverse_bmp, (float)0, RGB(255,255,255) ); 
				m_st1.GetClientRect( &rectStaticClient );
				rectStaticClient.NormalizeRect();
				m_size.cx=	rectStaticClient.Size().cx;
				m_size.cy=	rectStaticClient.Size().cy;
				m_size.cx = rectStaticClient.Width();    // zero based
				m_size.cy = rectStaticClient.Height();    // zero based

			// Convert to screen coordinates using static as base,
			// then to DIALOG (instead of static) client coords 
			// using dialog as base
				m_st1.ClientToScreen( &rectStaticClient );
				ScreenToClient( &rectStaticClient);
	
		
				m_pt.x = rectStaticClient.left;
				m_pt.y = rectStaticClient.top;

				GetObject( m_hBmpNew , sizeof(BITMAP), &m_bmInfo );
				VERIFY(m_hBmpOld = (HBITMAP)SelectObject(m_dcMem, m_hBmpNew )  );
				if(m_hBmpOld != NULL )
					DeleteObject(m_hBmpOld);
				offsetx= m_pt.x;
				offsety=m_pt.y;
			//	m_vbar.MoveWindow(offsetx+m_size.cx,offsety,18,m_size.cy);
			//	m_hbar.MoveWindow(offsetx,offsety+m_size.cy,m_size.cx,18);
				horz.cbSize = sizeof(SCROLLINFO);
				horz.fMask = SIF_ALL;
				horz.nMin = 0;
				horz.nMax = m_bmInfo.bmWidth-m_size.cx+1;
				horz.nPage =0;
				horz.nPos = 0;
				horz.nTrackPos=0;
				if(m_bmInfo.bmWidth<=m_size.cx)
				{
					if((m_size.cx-m_bmInfo.bmWidth)==0)
						offsetx= m_pt.x;
					else
					offsetx= m_pt.x+((m_size.cx-m_bmInfo.bmWidth)/2);
					//	m_vbar.MoveWindow(offsetx+m_bmInfo.bmWidth,offsety,18,m_size.cy);
					m_hbar.ShowWindow(false);
				}
		else
			m_hbar.ShowWindow(true);
		m_hbar.SetScrollInfo(&horz);
		vert.cbSize = sizeof(SCROLLINFO);
		vert.fMask = SIF_ALL;
		vert.nMin = 0;
		vert.nMax = m_bmInfo.bmHeight-(m_size.cy)+1;
		vert.nPage = 0;
		vert.nTrackPos=0;
		if(m_bmInfo.bmHeight<=m_size.cy)
		{
				if((m_size.cy-m_bmInfo.bmHeight)==0)
					offsety= m_pt.y;
				else
					offsety= m_pt.y+((m_size.cy-m_bmInfo.bmHeight)/2);
			//	m_hbar.MoveWindow(offsetx,offsety+m_bmInfo.bmHeight,m_size.cx,18);
				m_vbar.ShowWindow(false);
		}
			else
			m_vbar.ShowWindow(true);
			m_vbar.SetScrollInfo(&vert);

			InvalidateRect(&rectStaticClient);
			
			}
			}
		}
}

void CDialogThemeEditor::OnVScroll(UINT code,
                                   UINT position,
                                   CScrollBar *scrollBar)
{
    int currentPosition = m_vbar.GetScrollPos();

    switch (code)
    {
        case SB_LINEUP:
            sourcey = max(currentPosition - 6, 0);
            break;

        case SB_LINEDOWN:
            sourcey = min(currentPosition + 6, m_vbar.GetScrollLimit() - 1);
            break;

        case SB_PAGEUP:
            sourcey = max(currentPosition - 15, 0);
            break;

        case SB_PAGEDOWN:
            sourcey = min(currentPosition + 15, m_vbar.GetScrollLimit() - 1);
            break;

        case SB_TOP:
            sourcey = 0;
            break;

        case SB_BOTTOM:
            sourcey = INT_MAX;
            break;

        case SB_THUMBTRACK:
            sourcey = position;
            break;

        default:
            break;
    }

    m_vbar.SetScrollPos(sourcey);
    erase = true;
    InvalidateRect(&rectStaticClient);
    Invalidate();
    CDialog::OnVScroll(code, position, scrollBar);
}

void CDialogThemeEditor::OnHScroll(UINT code,
                                   UINT position,
                                   CScrollBar *scrollBar) 
{
    int currentPosition = m_hbar.GetScrollPos();

    switch (code)
    {
        case SB_LINELEFT:
            sourcex = max(currentPosition - 6, 0);
            break;

        case SB_LINERIGHT:
            sourcex = min(currentPosition + 6, m_hbar.GetScrollLimit() - 1);
            break;

        case SB_PAGELEFT:
            sourcex = max(currentPosition - 15, 0);
            break;

        case SB_PAGERIGHT:
            sourcex = min(currentPosition + 15, m_hbar.GetScrollLimit() - 1);
            break;

        case SB_LEFT:
            sourcex = 0;
            break;

        case SB_RIGHT:
            sourcex = INT_MAX;
            break;

        case SB_THUMBTRACK:
            sourcex= position;
            break;

        default:
            break;
    }	

    m_hbar.SetScrollPos(sourcex);
    erase = true;
    InvalidateRect(&rectStaticClient);
    Invalidate();
    CDialog::OnHScroll(code, position, scrollBar);
}


BOOL CDialogThemeEditor::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	if(erase)
		return false;
	else
	return CDialog::OnEraseBkgnd(pDC);
}


void CDialogThemeEditor::DrawNonBitmap()
{
	char path[1024],MoDISEXE[1024],tempbuf[1024];
	char *name;
	memset(path, 0, sizeof(tempbuf));
	memset(tempbuf, 0, sizeof(tempbuf));
	memset(MoDISEXE, 0, sizeof(MoDISEXE));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return ;
	strncpy(MoDISEXE, path, strlen(path));
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%snon.bmp", tempbuf);
	m_BMPFile.Format(path);
	ShowBMP();
}

void CDialogThemeEditor::OnCheckTransparent()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		if(((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->GetCheck())
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(0);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(1);
		}
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_filler_themeid);
	
	if(!((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->GetCheck())
	{
		((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(1);
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please uncheck transparent by clicking the color box.");
		m_pUIDlg->EnableWindow(true);
		Invalidate();
		if (SelectItemByComponentName(componentName))
		{
		    m_ListThemeEditor.SetFocus();	
		}			
		return;
	}
	
	if(!(the_component->filler_flag&MMI_MTE_FILLER_ALLOW_NULL))
	{
		if(defaultnull[m_filler_themeid]==false)
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("This filler cannot be transparent.");
			m_pUIDlg->EnableWindow(true);
			((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->SetCheck(0);
			Invalidate();
			if (SelectItemByComponentName(componentName))
			{
			    m_ListThemeEditor.SetFocus();	
			}					
			return;
		}
	}
	if(((CButton*)GetDlgItem(IDC_CHECK_TRANSPARENT))->GetCheck())
	{
		
		UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
			
		*old_filler = NULL;
		ActivateTheme((MMI_theme *)&my_theme);
		//flag[m_filler_themeid]=true;
		SetFlag(m_filler_themeid);
		int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
		if(idx!=-1) DrawFlagIcon(idx);
		m_transparent = true;

		InsertFillerHistory(m_filler_themeid,NULL);
		ComHistroy[m_filler_themeid]++;
		ComIdxHistroy[m_filler_themeid]++;
		g_onedit = true;
		UpdateListThemeOnDiffTheme();
		g_screen_cb = true ;
		//Invalidate();
	}
    if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
		DrawGreenFlag (m_filler_themeid);
    }

}
void CDialogThemeEditor::OnButtonUpint()
{
    const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
	g_idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	int i=GetDlgItemInt(IDC_EDIT_INTEGER);
	mmi_mte_theme_component_struct * the_component=( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(m_integer_themeid);
	int *old_i = (int *) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
	
	if(i>the_component->max_value || i<the_component->min_value)
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Invalid integer.");
		m_pUIDlg->EnableWindow(true);
		SetDlgItemInt(IDC_EDIT_INTEGER,m_theintTemp);
		return;
	}
	if(i!=*old_i)
	{
		m_updateint = true;
		*old_i = i;
		ActivateTheme((MMI_theme *)&my_theme);
	}
	m_theintTemp = i;
	SetFlag(m_integer_themeid);
	DrawFlagIcon(g_idx);
	if (SelectItemByComponentName(componentName))
	{
	    m_ListThemeEditor.SetFocus();
		DrawGreenFlag(m_integer_themeid);		
	}		
	g_onedit = true;
	g_screen_cb = true; //Update at next refresh
}
void CDialogThemeEditor::DisableFillerTransparent(const mmi_mte_theme_component_struct *the_component)
{
    if (!(the_component->filler_flag&MMI_MTE_FILLER_ALLOW_NULL))
    {
        if(defaultnull[m_filler_themeid]==false)
        {
            GetDlgItem(IDC_CHECK_TRANSPARENT)->EnableWindow(false);
        }
        else
        {
            GetDlgItem(IDC_CHECK_TRANSPARENT)->EnableWindow(true);
        }
    }
    else
    {
        GetDlgItem(IDC_CHECK_TRANSPARENT)->EnableWindow(true);
    }
}

void CDialogThemeEditor::SetFlag(int id)
{
//	flag[id]=true;
	save_modify_flag[m_theme_idx][id]=2;
}


BOOL CDialogThemeEditor::GetOfficeWordPath(LPOLESTR szApp, LPSTR szPath, ULONG cSize)
{
    CLSID clsid;
    LPOLESTR pwszClsid;
    CHAR  szKey[128];
    CHAR  szCLSID[60];
    HKEY hKey;

    // szPath must be at least 255 char in size
    if (cSize < 255)
	return FALSE;
	
    // Get the CLSID using ProgID
    HRESULT hr = CLSIDFromProgID(szApp, &clsid);
    if (FAILED(hr))
    {
	m_pUIDlg->EnableWindow(false);
	::MessageShow("Could not get CLSID from ProgID. Make sure ProgID is correct.");//, MB_OK, 0);
	m_pUIDlg->EnableWindow(true);        
return FALSE;
    }

    // Convert CLSID to String
    hr = StringFromCLSID(clsid, &pwszClsid);
    if (FAILED(hr))
    {
	m_pUIDlg->EnableWindow(false);
		::MessageShow("Could not convert CLSID to string.");//", MB_OK, 0);
	m_pUIDlg->EnableWindow(true);        
return FALSE;
    }

    // Convert result to ANSI
    WideCharToMultiByte(CP_ACP, 0, pwszClsid, -1, szCLSID, 60, NULL, NULL);

    // Free memory used by StringFromCLSID
    CoTaskMemFree(pwszClsid);

    // Format Registry Key string
    wsprintf(szKey, "CLSID\\%s\\LocalServer32", szCLSID);

    // Open key to find path of application
    LONG lRet = RegOpenKeyEx(HKEY_CLASSES_ROOT, szKey, 0, KEY_READ , &hKey);
    if (lRet != ERROR_SUCCESS) 
    {
	// If LocalServer32 does not work, try with LocalServer
        wsprintf(szKey, "CLSID\\%s\\LocalServer", szCLSID);
        lRet = RegOpenKeyEx(HKEY_CLASSES_ROOT, szKey, 0, KEY_ALL_ACCESS, &hKey);
		if (lRet != ERROR_SUCCESS) 
        {
	m_pUIDlg->EnableWindow(false);
            ::MessageShow("No LocalServer key found!");//", MB_OK, 0);
	m_pUIDlg->EnableWindow(true);           
 return FALSE;
        }
    }

    // Query value of key to get Path and close the key
    lRet = RegQueryValueEx(hKey, NULL, NULL, NULL, (BYTE*)szPath, &cSize);
    RegCloseKey(hKey);
    if (lRet != ERROR_SUCCESS)
    {
	m_pUIDlg->EnableWindow(false);
		::MessageShow("Error trying to query for path.");//", MB_OK, 0);
	m_pUIDlg->EnableWindow(true);       
 return FALSE;
    }

    // Strip off the '/Automation' switch from the path
    char *x = strrchr(szPath, '/');
    if(0!= x) // If no /Automation switch on the path
    {
		int result = x - szPath; 
		szPath[result]  = '\0';  // If switch there, strip it
    }   
    return TRUE;
}

void CDialogThemeEditor::OnLButtonDown(UINT flags, CPoint point)
{
    if (!IsEditingAnimation())
    {
        return;
    }

    const ImageBlocks::const_iterator
            oldSelectedImageBlock(m_SelectedImageBlock);

    for (ImageBlocks::iterator iter = m_ImageBlocks.begin();
         iter != m_ImageBlocks.end();
         iter++)
    {
        if (iter->GetImageRect().PtInRect(point))
        {
            m_SelectedImageBlock = iter;

            if (oldSelectedImageBlock != m_SelectedImageBlock)
            {
                //
                // Erase both old and new selections and let OnPaint() do
                // the drawing
                //
                InvalidateRect(oldSelectedImageBlock->GetSelectionRect());
                InvalidateRect(m_SelectedImageBlock->GetSelectionRect());
            }

            SetupBitmapViewer();
            return;
        }
    }
}

void CDialogThemeEditor::OnLButtonDblClk(UINT flags, CPoint point)
{
    if (!IsEditingAnimation())
    {
        return;
    }

    const ImageBlocks::const_iterator
            oldSelectedImageBlock(m_SelectedImageBlock);

    for (ImageBlocks::iterator iter = m_ImageBlocks.begin();
         iter != m_ImageBlocks.end();
         iter++)
    {
        if (iter->GetImageRect().PtInRect(point))
        {
            OnAnimationImageAdd();
            return;
        }
    }
}

void CDialogThemeEditor::OnAnimationImageSequence()
{
	const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
    if (IsEditingAnimation())
    {
        // Erase the current selection
        InvalidateRect(m_SelectedImageBlock->GetSelectionRect());

        RemoveImageFromFiller(m_filler_themeid);
        
		if (GetNumAnimationFrames()>0)
		{
        InsertFillerHistory();
		}
        LeaveAnimationEditingMode();
		ThemeComEdit();
		//if (!IsComponentModified(m_filler_themeid))
		//{
		SetComponentModified(m_filler_themeid);
		MarkGreenFlagOnSelectedItem();    
		DrawGreenFlag(m_filler_themeid);
		//}
    }
    else
    {
    	DoShowCurrentScreenInActivateTheme = false ;
        RemoveImageFromFiller(m_filler_themeid);
		CString temp;
		GetDlgItem(IDC_BUTTON_IMAGE)->GetWindowText(temp);
		if (temp.CompareNoCase("Add Image"))
		{
        InsertFillerHistory();
		}
		SetComponentModified(m_filler_themeid);
		MarkGreenFlagOnSelectedItem();    
		DrawGreenFlag(m_filler_themeid);

		if (GetNumAnimationFrames() > 0)
		{
			GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(TRUE);
		}
		else
		{
			m_SelectedImageBlock = m_ImageBlocks.begin();
			GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(FALSE);
		}
        EnterAnimationEditingMode();
		
		std::map<int,type_9slice>::iterator slice_Iter;
		slice_Iter = map_slice_value.find(m_filler_themeid+1);
		if (slice_Iter != map_slice_value.end())
		{
			slice_Iter->second.nleft = 0;
			slice_Iter->second.ntop = 0;
			slice_Iter->second.nright =0;
			slice_Iter->second.nbottom =0;					
		}	
		m_nValueTop = 0;
		m_nValueBottom = 0;
		m_nValueRight = 0;
		m_nValueLeft = 0;
		UpdateData(false);
    }

    g_onedit = true;
    m_ListThemeEditor.SetFocus();
}

void CDialogThemeEditor::OnAnimationImageAdd()
{
    //
    // Make sure that images are added in order
    //
	const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
    for (ImageBlocks::const_iterator iter = m_ImageBlocks.begin();
         iter!=m_ImageBlocks.end();
         iter++)
    {
        if (iter == m_SelectedImageBlock)
        {
            break;
        }

        if (!iter->HasRawImage())
        {
			m_pUIDlg->EnableWindow(false);
            ::MessageShow(_T("Please add images in order."));
			m_pUIDlg->EnableWindow(true);
            return;
        }
    }

    CFileDialog openFileDialog(
        TRUE,
        _T(".png"),
        NULL,
        OFN_HIDEREADONLY,
        _T("PNG (*.png)|*.png||"),
        this
    );
/*
 	MoDISFileDialogW openFileDialog( this->GetSafeHwnd(), 
						L".png",
						NULL,
						OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR, 
						L"PNG\0*.png" 
						) ;
	
*/
    if (openFileDialog.DoModal() == IDOK)
    //if( openFileDialog.LoadFile() )
    {
		if (LoadImageBlock(openFileDialog.GetPathName()))
        //if (LoadImageBlock(openFileDialog.GetFileNameA().c_str()))
        {
            MakeAnimationImage();
            SetupBitmapViewer();

            //InsertFillerHistory();
            DrawNonBitmap();

            if (IsComponentModified(m_filler_themeid))
            {
                SetComponentModified(m_filler_themeid);
            }
                MarkGreenFlagOnSelectedItem();    
		DrawGreenFlag(m_filler_themeid);

            g_onedit = true;
			if (SelectItemByComponentName(componentName))
			{
				m_ListThemeEditor.SetFocus();
				ThemeComEdit();
        }
    }

        if (GetNumAnimationFrames() > 0)
		{
			GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(FALSE);
		}
    }
    else
	{
    if (SelectItemByComponentName(componentName))
    {
    m_ListThemeEditor.SetFocus();
		}
    }
}

void CDialogThemeEditor::OnAnimationImageRemove()
{
	const CString componentName(GetSelectedComponentName());
	ImageBlocks::iterator iter;
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
    if (!m_SelectedImageBlock->HasRawImage())
    {
        return;
    }

    for (iter = m_SelectedImageBlock;
         (iter+1) != m_ImageBlocks.end();
         iter++)
    {
        const ImageBlocks::const_iterator nextIter = iter + 1;

        if (!nextIter->HasRawImage())
        {
            break;
        }

        iter->SetRawImage(new RawImage(*nextIter->GetRawImage()));
        InvalidateRect(iter->GetSelectionRect());
    }

    iter->ClearRawImage();
    InvalidateRect(iter->GetSelectionRect());

	if( GetNumAnimationFrames() == 0 )
	{
        // Erase the current selection
        InvalidateRect(m_SelectedImageBlock->GetSelectionRect());

        RemoveImageFromFiller(m_filler_themeid);
        InsertFillerHistory();
        LeaveAnimationEditingMode();
		ThemeComEdit();
	}
	else
	{
	    MakeAnimationImage();	
	    SetupBitmapViewer();
	}
	
    //InsertFillerHistory();
    SetComponentModified(m_filler_themeid);
    MarkGreenFlagOnSelectedItem();    
	DrawGreenFlag(m_filler_themeid);
	
    g_onedit = true;
	if (SelectItemByComponentName(componentName))
    {
    m_ListThemeEditor.SetFocus();
		ThemeComEdit();
    }
    
}

void CDialogThemeEditor::OnChangeAnimationDelay()
{
    m_nDelaytimeTemp = m_nDelaytime;
   // if (GetNumAnimationFrames() > 0)
    {
  //     MakeAnimationImage();
        //InsertFillerHistory();
    }
}
void CDialogThemeEditor::OnButtonSetDelayTime()
{
	const CString componentName(GetSelectedComponentName());
	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		return;
	}
    if (GetNumAnimationFrames() > 0)
    {
	m_nDelaytime = GetAnimationDelay();
	if (m_nDelaytime >= 351 || m_nDelaytime <= 49 )
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Invalid integer. The integer should be between 50 and 350.");
		m_pUIDlg->EnableWindow(true);
		m_nDelaytime = m_nDelaytimeTemp;
		CString str;
		str.Format(_T("%d"), m_nDelaytime);
		m_AnimationDelay.SetWindowText(str);
			//	m_AnimationRepeatCount.SetCurSel((m_nrepeatCount == 1) ? 0 : 1);
		return;
}
	CString str;
	str.Format(_T("%d"), m_nDelaytime);
	m_AnimationDelay.SetWindowText(str);
		m_nrepeatCount = GetAnimationRepeatCount();
        MakeAnimationImage();
        //InsertFillerHistory();
	    if (!IsComponentModified(m_filler_themeid))
	    {
	        SetComponentModified(m_filler_themeid);
	        MarkGreenFlagOnSelectedItem();    
			DrawGreenFlag(m_filler_themeid);
	    }

	    g_onedit = true;
	    m_ListThemeEditor.SetFocus();        
    }
	else
	{ 
		m_pUIDlg->EnableWindow(false);
		::MessageShow("There is no image added for png sequence.\nPlease add image first.");
		m_pUIDlg->EnableWindow(true);
		CString str;
		str.Format(_T("%d"), m_nDelaytime);
		m_AnimationDelay.SetWindowText(str);
		m_AnimationRepeatCount.SetCurSel((m_nrepeatCount == 1) ? 0 : 1);
		return;
	}
	if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
		ThemeComEdit();
    }
}
void CDialogThemeEditor::OnChangeAnimationRepeat()
{
// 	if (GetNumAnimationFrames() > 0)
//     {
//         MakeAnimationImage();
//         //InsertFillerHistory();
// 		if (!IsComponentModified(m_filler_themeid))
// 		{
// 			SetComponentModified(m_filler_themeid);
// 			MarkGreenFlagOnSelectedItem();    
// 			DrawGreenFlag(m_filler_themeid);
// 		}
// 		
// 		g_onedit = true;
// 		m_ListThemeEditor.SetFocus();        
//     }
}

bool CDialogThemeEditor::IsAnimationSupported(
        const mmi_mte_theme_component_struct *componentInfo)
{
    int recommendedWidth, recommendedHight, maxWidth, maxHeight;
    unsigned int allowedImageType;
    mmi_mte_image_enum recommendedImageType;

    mmi_mte_get_theme_component_image_info(
        const_cast<mmi_mte_theme_component_struct *>(componentInfo),
        &recommendedWidth,
        &recommendedHight,
        &maxWidth,
        &maxHeight,
        &allowedImageType,
        &recommendedImageType
    );

    return IsAnimationType(static_cast<mmi_mte_image_enum>(allowedImageType));
}

bool CDialogThemeEditor::HasAnimation(
                    const UI_filled_area *filler,
                    const mmi_mte_theme_component_struct *componentInfo)
{
    if (filler == NULL ||
        filler->b == NULL ||
        !IsAnimationSupported(componentInfo))
    {
        return false;
    }

    char *imageData;
    mmi_mte_image_enum imageType;
    int imageWidth, imageHeight, imageSize;

    mmi_mte_get_image_resource_info(
        reinterpret_cast<char *>(filler->b),
        -1,
        &imageData,
        &imageType,
        &imageWidth,
        &imageHeight,
        &imageSize,
        NULL,
        NULL
    );

    return IsAnimationType(imageType);
}

bool CDialogThemeEditor::IsAnimationType(mmi_mte_image_enum imageType)
{
    //return ((imageType & MMI_MTE_IMAGE_PNG_SEQUENCE) ||
            //(imageType & MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE) ||
            //(imageType & MMI_MTE_IMAGE_PNG_TO_AB2_SEQUENCE));

    return ((imageType & MMI_MTE_IMAGE_BMP_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_JPG_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_PNG_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_BMP_TO_ABM_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_ABM_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_BMP_TO_AB2_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_PNG_TO_AB2_SEQUENCE) ||
            (imageType & MMI_MTE_IMAGE_AB2_SEQUENCE));
}

bool CDialogThemeEditor::IsEditingAnimation()
{
	if (m_IsEditingAnimation)
	{
		ShowHideSliceControls(FALSE);
	}
	
    return m_IsEditingAnimation;
}

void CDialogThemeEditor::EnterAnimationEditingMode()
{
    DrawNonBitmap();
    ImageRecDisplay();
    GetDlgItem(IDC_STATIC_REC)->SetWindowText(_T("Supported type: PNG"));
    GetDlgItem(IDC_STATIC_REC2)->SetWindowText(_T("Best type: PNG"));
    GetDlgItem(IDC_CHECK_TRANSPARENT)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_STATIC_TEXT_COLOR)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_FILLER_C)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_STATIC_TEXT_BC)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_FILLER_BC)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_CHECK_FILLER_BORDER)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_FILLER_IMAGE)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_SCROLLBAR1)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_SCROLLBAR2)->ShowWindow(SW_HIDE);
    GetDlgItem(IDC_BUTTON_IMAGE)->ShowWindow(SW_HIDE);
	if (m_bSliceComponent)
	{
		ShowHideSliceControls(false);
	}
	CString str;
	str.Format("Max size: (%d, %d)", m_max_width, m_max_height);
		GetDlgItem(IDC_STATIC_REC_MWH)->SetWindowText(str);
    m_drawfiller = false;

    GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->SetWindowText(
                                                    _T("Remove PNG Seq."));
    ShowAnimationEditingControls();
    m_IsEditingAnimation = true;

    LoadAnimationImage();
  //  m_SelectedImageBlock = m_ImageBlocks.begin();

	if (GetNumAnimationFrames()>0)
	{
		GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_ANIMATION_IMAGE_REMOVE)->EnableWindow(FALSE);
	}
    InvalidateRect(m_SelectedImageBlock->GetSelectionRect());
    SetupBitmapViewer();
}

void CDialogThemeEditor::LeaveAnimationEditingMode()
{
    ImageRecDisplay();
    GetDlgItem(IDC_CHECK_TRANSPARENT)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_STATIC_TEXT_COLOR)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_FILLER_C)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_STATIC_TEXT_BC)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_FILLER_BC)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_CHECK_FILLER_BORDER)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_FILLER_IMAGE)->ShowWindow(SW_SHOW);
    //GetDlgItem(IDC_SCROLLBAR1)->ShowWindow(SW_SHOW);
    //GetDlgItem(IDC_SCROLLBAR2)->ShowWindow(SW_SHOW);
    GetDlgItem(IDC_BUTTON_IMAGE)->ShowWindow(SW_SHOW);

	if (m_bSliceComponent)
	{
		ShowHideSliceControls(true);
	}
	
	
	
    m_drawfiller = true;

    const mmi_mte_theme_component_struct *componentInfo =
                    mmi_mte_get_theme_component(m_filler_themeid);
    ASSERT(componentInfo != NULL);

    DisableFillerTransparent(componentInfo);

    ClearImageBlocks();
    m_BitmapViewer.ClearBitmap();

    GetDlgItem(IDC_ANIMATION_IMAGE_SEQUENCE)->SetWindowText(
                                                    _T("Edit PNG Seq."));
    HideAnimationEditingControls();
    m_IsEditingAnimation = false;

	//Check if there's picture or not
	UI_filled_area **_filler =
        static_cast<UI_filled_area **> (GetComponentAddr(&my_theme, m_filler_themeid));
    ASSERT(_filler != NULL);
	if( (*_filler)->b == NULL )
	{
		m_AddImage = true ;  //We have deleted the image
		GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Add Image");
	}
	else
	{
		m_AddImage = false ;  //We have deleted the image
		GetDlgItem(IDC_BUTTON_IMAGE)->SetWindowText("Delete Image");
	}
	/////////////////////////////////////
    InvalidateRect(m_SelectedImageBlock->GetSelectionRect());
  //  m_SelectedImageBlock = m_ImageBlocks.begin();
}

void CDialogThemeEditor::ShowAnimationEditingControls()
{
    ControlIDs::const_iterator iter;

    for (iter  = m_AnimationEditingControlIDs.begin();
         iter != m_AnimationEditingControlIDs.end();
         iter++)
    {
        CWnd *control = GetDlgItem(*iter);
        ASSERT(control != NULL);
        control->ShowWindow(SW_SHOW);
    }
}

void CDialogThemeEditor::HideAnimationEditingControls()
{
    ControlIDs::const_iterator iter;

    for (iter  = m_AnimationEditingControlIDs.begin();
         iter != m_AnimationEditingControlIDs.end();
         iter++)
    {
        CWnd *control = GetDlgItem(*iter);
        ASSERT(control != NULL);
        control->ShowWindow(SW_HIDE);
    }
}

static char* ReadFile(const CString &filename, int *fileLength = NULL)
{
    CFile file;
    CFileException exception;

    if (!file.Open(filename, CFile::modeRead, &exception))
    {
        exception.ReportError();
        return NULL;
    }

    int length = (int)file.GetLength();

    if (fileLength != NULL)
    {
        *fileLength = length;
    }

    char *buffer = new char[length];
    ASSERT(buffer != NULL);

    file.Read(buffer, length);
    return buffer;
}

static void WriteFile(const CString &filename,
                      const char *buffer,
                      unsigned int count)
{
    CFile file;
    CFileException exception;

    if (!file.Open(filename, CFile::modeWrite, &exception))
    {
        exception.ReportError();
        return;
    }

    file.Write(buffer, count);
}

// We assume that the input file is a PNG file
bool CDialogThemeEditor::LoadImageBlock(LPCTSTR pngImageFilename)
{
    //if (m_recommend_image_type != MMI_MTE_IMAGE_PNG_TO_AB2)
    //{
        //::MessageShow(CString(_T("Failed to load ")) + pngImageFilename);
        //return false;
    //}

    //
    // Convert to ABM format
    //
    CString abmImageFilename;

    if (!EncodePNGIntoABM(pngImageFilename, abmImageFilename))
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(CString(_T("Failed to decode ")) + pngImageFilename + CString(_T(".")));
		m_pUIDlg->EnableWindow(true);
        return false;
    }

    int abmImageSize;
    char *abmImageBuffer = ReadFile(abmImageFilename, &abmImageSize);

    ::DeleteFile(abmImageFilename);

    //
    // Check image dimension
    //
    int imageWidth, imageHeight;
    int result;

    result = mmi_mte_get_image_dimension(MMI_MTE_IMAGE_PNG_TO_ABM,
                                         abmImageBuffer,
                                         &imageWidth,
                                         &imageHeight);

    if (result != 0)
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("Failed to get the image dimension."));
		m_pUIDlg->EnableWindow(true);
        return false;
    } 

    if ((imageWidth > m_max_width) || (imageHeight > m_max_height))
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("The image size exceeds the maximum size."));
		m_pUIDlg->EnableWindow(true);
        return false;
    }

    if ((imageWidth  != m_recommend_width) ||
        (imageHeight != m_recommend_height))
    {
		CString tmp;

		tmp.Format("The image file (%d x %d) does not have recommended size (%d x %d).",
                    imageWidth, imageHeight, m_recommend_width, m_recommend_height);
	  m_pUIDlg->EnableWindow(false);
        ::MessageShow( tmp );
		m_pUIDlg->EnableWindow(true);
        return false ;
    }

    //
    // Store the ABM image
    //
    m_SelectedImageBlock->SetRawImage(
        new RawImage(abmImageBuffer,
                     MMI_MTE_IMAGE_PNG_TO_ABM,
                     abmImageSize,
                     imageWidth,
                     imageHeight)
    );

    InvalidateRect(m_SelectedImageBlock->GetImageRect());
    return true;
}

void CDialogThemeEditor::SetupBitmapViewer()
{
    if (m_SelectedImageBlock->HasRawImage())
    {
        m_BitmapViewer.SetBitmap(
                new Bitmap(*m_SelectedImageBlock->GetPreviewBitmap()));
    }
    else
    {
        m_BitmapViewer.ClearBitmap();
    }

    m_BitmapViewer.Invalidate();
}

void CDialogThemeEditor::MakeAnimationImage()
{
    int numFrames = GetNumAnimationFrames();

    if (numFrames <= 0)
    {
        UI_filled_area **filler =
            static_cast<UI_filled_area **>
                (GetComponentAddr(&my_theme, m_filler_themeid));
        ASSERT(filler != NULL);

        if (*filler != NULL)
        {
			UI_filled_area *newFiller = new UI_filled_area;
            ASSERT(newFiller != NULL);
			::memcpy(newFiller, *filler, sizeof(UI_filled_area));
		    newFiller->b = NULL;
	        newFiller->flags = UI_FILLED_AREA_TYPE_BITMAP; // FIXME
			*filler = newFiller;

			InsertFillerHistory();
            //(*filler)->b = NULL;
            ActivateTheme(&my_theme);
			g_screen_cb = true; //Update at next refresh
        }

        return;
    }

    int *frameSizes = new int[numFrames];
    int *frameDelays = new int[numFrames];
    int headerSize = 8;
    int animationImageSize = 0;
    int index = 0;
	ImageBlocks::const_iterator iter;

    for (iter = m_ImageBlocks.begin();
         iter != m_ImageBlocks.end();
         iter++)
    {
        if (iter->HasRawImage())
        {
            headerSize += 12;
			int aligned_size;
			if( iter->GetRawImage()->GetSize() % 4 != 0 )			
				aligned_size = ( (int)(iter->GetRawImage()->GetSize()/4) + 1 )*4;
			else
				aligned_size = iter->GetRawImage()->GetSize() ;
			frameSizes[index] = aligned_size ;

 //           frameDelays[index] = GetAnimationDelay();
			frameDelays[index] = m_nDelaytime;
            animationImageSize += frameSizes[index];

            index++;
        }
    }

    animationImageSize += headerSize;

    char *animationImageBuffer = new char[animationImageSize];
    char *header = animationImageBuffer;

    //ASSERT(m_recommend_image_type == MMI_MTE_IMAGE_PNG_TO_AB2);

    // We support only ABM sequences now
    const mmi_mte_image_enum imageType = MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE;
    mmi_mte_return_code_enum ret;

    ret = mmi_mte_get_image_sequence_header(
        header,
        imageType,
        &headerSize,
        m_ImageBlocks.begin()->GetRawImage()->GetWidth(),
        m_ImageBlocks.begin()->GetRawImage()->GetHeight(),
        numFrames,
        m_nrepeatCount,//GetAnimationRepeatCount(),
        frameSizes,
        frameDelays
    );

    if (ret == MMI_MTE_SUCCESS)
    {
		m_AnimationRepeatCount.SetCurSel((m_nrepeatCount == 1) ? 0 : 1);
        char *ptr = animationImageBuffer + headerSize;

        for (iter=m_ImageBlocks.begin(); iter!=m_ImageBlocks.end(); iter++)
        {
            if (iter->HasRawImage())
            {
                const RawImage *png = iter->GetRawImage();
				//need to be aligned?
				if( png->GetSize() % 4 != 0 )
				{
					int aligned_size = ( (int)(png->GetSize()/4) + 1 )*4;					
					char *tmp = new char [ aligned_size ] ;
					::memset( tmp, 0, aligned_size*sizeof(char) ) ;
					::memcpy( tmp, png->GetBuffer(), png->GetSize());
					::memcpy( ptr, tmp, aligned_size*sizeof(char) ) ;
					ptr += aligned_size ;
					delete [] tmp ;
				}
				else
				{
                	::memcpy(ptr, png->GetBuffer(), png->GetSize());
	                ptr += png->GetSize();
				}
            }
        }

        UI_filled_area **oldFiller =
            static_cast<UI_filled_area **>
                (GetComponentAddr(&my_theme, m_filler_themeid));
        ASSERT(oldFiller != NULL);

        UI_filled_area *newFiller = new UI_filled_area;
        ASSERT(newFiller != NULL);

        if (*oldFiller != NULL)
        {
            ::memcpy(newFiller, *oldFiller, sizeof(UI_filled_area));
        }

        newFiller->b = reinterpret_cast<PU8>(animationImageBuffer);
        newFiller->flags = UI_FILLED_AREA_TYPE_BITMAP; // FIXME
        *oldFiller = newFiller;
        ActivateTheme(&my_theme);
		g_screen_cb = true; //Update at next refresh
    }
    else
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("Failed to make animation image."));
		m_pUIDlg->EnableWindow(true);
        delete [] animationImageBuffer;
    }

	InsertFillerHistory();
    delete [] frameSizes;
    delete [] frameDelays;
}

void CDialogThemeEditor::LoadAnimationImage()
{
    const mmi_mte_theme_component_struct *componentInfo = 
                    mmi_mte_get_theme_component(m_filler_themeid);

    UI_filled_area **filler =
        static_cast<UI_filled_area **>(
            mmi_mte_translate_theme_component_data_pointer(
                                            componentInfo, &my_theme));
    ASSERT(filler != NULL);

    if (!HasAnimation(*filler, componentInfo))
    {
        m_AnimationDelay.SetWindowText(_T("175"));
		m_nDelaytime = 175;
		m_nDelaytimeTemp = 175;
        m_AnimationRepeatCount.SetCurSel(0);
		m_nrepeatCount = 1;
        return;
    }

    mmi_mte_return_code_enum result;
    int numFrames;

    result = mmi_mte_get_image_frame_count(
                reinterpret_cast<char *>((*filler)->b), &numFrames);

    if (result != MMI_MTE_SUCCESS)
    {
		m_pUIDlg->EnableWindow(false);
        ::MessageShow(_T("Failed to get frame count."));
		m_pUIDlg->EnableWindow(true);
        return;
    }

    ASSERT(numFrames <= m_ImageBlocks.size());

    for (int i=0; i<numFrames; i++)
    {
        //
        // Get the i'th frame from the animation image
        //
        char *imageData;
        mmi_mte_image_enum imageType;
        int imageWidth, imageHeight, imageSize;
        int delay, repeatCount;

        mmi_mte_get_image_resource_info(
            reinterpret_cast<char *>((*filler)->b),
            i,
            &imageData,
            &imageType,
            &imageWidth,
            &imageHeight,
            &imageSize,
            &delay,
            &repeatCount 
        );

        if (i == 0)
        {
            CString str;
            str.Format(_T("%d"), delay);
            m_nDelaytimeTemp = delay;
			m_nDelaytime = delay;
            m_AnimationDelay.SetWindowText(str);
            m_AnimationRepeatCount.SetCurSel((repeatCount == 1) ? 0 : 1);
			m_nrepeatCount = repeatCount;
        }

        //
        // Store to the corresponding image block
        //

        // We support only ABM sequences now
        if ((imageType == MMI_MTE_IMAGE_PNG_TO_ABM_SEQUENCE) ||
            (imageType == MMI_MTE_IMAGE_ABM_SEQUENCE))
        {
            char *rawImageBuffer = new char[imageSize];
            ASSERT(rawImageBuffer != NULL);
            ::memcpy(rawImageBuffer, imageData, imageSize);

            m_ImageBlocks[i].SetRawImage(
                new RawImage(rawImageBuffer,
                             MMI_MTE_IMAGE_PNG_TO_ABM,
                             imageSize,
                             imageWidth,
                             imageHeight));
        }
        else
        {
            ASSERT(0);
        }
    }
}

int CDialogThemeEditor::GetAnimationDelay()
{
    CString str;
    m_AnimationDelay.GetWindowText(str);

    return str.IsEmpty() ? 0 : _ttoi(str);
}

int CDialogThemeEditor::GetAnimationRepeatCount()
{
    return m_AnimationRepeatCount.GetItemData(
                m_AnimationRepeatCount.GetCurSel());
}

int CDialogThemeEditor::GetNumAnimationFrames()
{
    int numFrames = 0;

    for (ImageBlocks::const_iterator iter = m_ImageBlocks.begin();
         iter != m_ImageBlocks.end();
         iter++)
    {
        if (iter->HasRawImage())
        {
            numFrames++;
        }
    }

    return numFrames;
}

void CDialogThemeEditor::ClearImageBlocks()
{
    for (ImageBlocks::iterator iter = m_ImageBlocks.begin();
         iter != m_ImageBlocks.end();
         iter++)
    {
        iter->ClearRawImage();
    }
}

CRect CDialogThemeEditor::GetControlRect(int controlID)
{
    CWnd *control = GetDlgItem(controlID);
    ASSERT(control != NULL);

    CRect rect;
    control->GetWindowRect(rect);
    ScreenToClient(rect);

    return rect;
}

// Replace the original filler with a filler that has the same attributes as
// the original one, except its image is set to NULL.
void CDialogThemeEditor::RemoveImageFromFiller(int id)
{
    UI_filled_area **oldFiller =
        static_cast<UI_filled_area **> (GetComponentAddr(&my_theme, id));
    ASSERT(oldFiller != NULL);

    UI_filled_area *newFiller = new UI_filled_area;
    ASSERT(newFiller != NULL);

    if (*oldFiller != NULL)
    {
        ::memcpy(newFiller, *oldFiller, sizeof(UI_filled_area));
    }

    newFiller->b = NULL;
    newFiller->flags = UI_FILLED_AREA_TYPE_COLOR ;
	if( ((CButton*)GetDlgItem(IDC_CHECK_FILLER_BORDER))->GetCheck() == BST_UNCHECKED )
		newFiller->flags = newFiller->flags | UI_FILLED_AREA_SINGLE_BORDER ;
    *oldFiller = newFiller;
    ActivateTheme(&my_theme);
	g_screen_cb = true; //Update at next refresh
}

bool CDialogThemeEditor::IsComponentModified(int id) const
{
    return (save_modify_flag[m_theme_idx][m_filler_themeid] == 2);
}

void CDialogThemeEditor::SetComponentModified(int id)
{
    save_modify_flag[m_theme_idx][id] = 2;
}

void CDialogThemeEditor::MarkGreenFlagOnSelectedItem()
{
    const int selectedIndex =
            m_ListThemeEditor.GetNextItem(-1, LVNI_ALL| LVNI_SELECTED);

    m_ListThemeEditor.SetItem(selectedIndex, 0, LVIF_IMAGE, 0, 0, 0, 0, 0);
}

void* CDialogThemeEditor::GetComponentAddr(const MMI_theme *theme,
                                           int componentID)
{
    return mmi_mte_translate_theme_component_data_pointer(
                            mmi_mte_get_theme_component(componentID),
                            const_cast<MMI_theme *>(theme));
}

void* CDialogThemeEditor::GetComponentAddr(const MMI_theme *theme,
                            const mmi_mte_theme_component_struct *component)
{
    return mmi_mte_translate_theme_component_data_pointer(
                            component, const_cast<MMI_theme *>(theme));
}

//
// ImageBlock implementation
//
MMI_MTE_Callback CDialogThemeEditor::ImageBlock::w32_mmi_mte_api = NULL;

CDialogThemeEditor::ImageBlock::ImageBlock(const CRect &imageRect,
                                           const CRect &selectionRect)
    : m_ImageRect(imageRect),
      m_SelectionRect(selectionRect),
      m_RawImage(NULL),
      m_PreviewBitmap(NULL)
{
    ASSERT(w32_mmi_mte_api != NULL);
}

CDialogThemeEditor::ImageBlock::~ImageBlock()
{
    ClearRawImage();
}

void CDialogThemeEditor::ImageBlock::SetRawImage(RawImage *rawImage)
{
    ClearRawImage();

    m_RawImage      = rawImage;
    m_PreviewBitmap = CreatePreviewBitmap();
}

void CDialogThemeEditor::ImageBlock::ClearRawImage()
{
    //
    // The preview bitmap is associated with the raw image, so we delete both 
    // of them
    //
    if (m_RawImage != NULL)
    {
        delete m_RawImage;
        m_RawImage = NULL;
    }

    if (m_PreviewBitmap != NULL)
    {
        delete m_PreviewBitmap;
        m_PreviewBitmap = NULL;
    }
}

void CDialogThemeEditor::ImageBlock::DrawSelection(CDC &dc) const
{
    CBrush brush;
    brush.CreateSolidBrush(RGB(0, 0, 255));

    dc.FrameRect(m_SelectionRect, &brush);
	DeleteObject(brush);
}

void CDialogThemeEditor::ImageBlock::DrawPreview(CDC &dc) const
{
    if (m_PreviewBitmap == NULL)
    {
        return;
    }

    const int maxDestWidth  = m_ImageRect.Width();
    const int maxDestHeight = m_ImageRect.Height() / 3;

    const float previewBitmapAspectRatio =
            (float) m_PreviewBitmap->GetHeight() / m_PreviewBitmap->GetWidth();
    const float displayAreaAspectRatio = (float) maxDestHeight / maxDestWidth;

    int destWidth;
    int destHeight;
    int destX;
    int destY;

    if (previewBitmapAspectRatio > displayAreaAspectRatio)
    {
        destHeight = maxDestHeight;
        destWidth  = m_PreviewBitmap->GetWidth() *
                     destHeight / m_PreviewBitmap->GetHeight();
    }
    else
    {
        destWidth  = maxDestWidth;
        destHeight = m_PreviewBitmap->GetHeight() *
                     destWidth / m_PreviewBitmap->GetWidth();
    }

    destX = m_ImageRect.TopLeft().x + (m_ImageRect.Width() - destWidth) / 2;
    destY = m_ImageRect.TopLeft().y + (m_ImageRect.Height() - destHeight) / 2;

    ::StretchDIBits(
        dc.GetSafeHdc(),
        destX,
        destY,
        destWidth,
        destHeight,
        0,
        0,
        m_PreviewBitmap->GetWidth(),
        m_PreviewBitmap->GetHeight(),
        m_PreviewBitmap->GetBuffer(),
        reinterpret_cast<BITMAPINFO *>(&m_PreviewBitmap->GetInfoHeader()),
        DIB_RGB_COLORS,
        SRCCOPY
    );
}

Bitmap* CDialogThemeEditor::ImageBlock::CreatePreviewBitmap() const
{
    const int bitmapBufferSize =
            m_RawImage->GetWidth() * m_RawImage->GetHeight() * 4;

    char *bitmapBuffer = new char[bitmapBufferSize];
    ASSERT(bitmapBuffer != NULL);

    int result = mmi_mte_start_decode_image(
        m_RawImage->GetType(),
        const_cast<char *>(m_RawImage->GetBuffer()),
        m_RawImage->GetSize(),
        bitmapBuffer,
        bitmapBufferSize,
        m_RawImage->GetWidth(),
        m_RawImage->GetHeight(),
        NULL,
        0
    );

    if (result != 0)
    {
		//GetParent()->m_pUIDlg->EnableWindow(false);
		//::MessageBox(dlg.m_hWnd,_T("Failed to create preview bitmap."),"MoDIS_UI",MB_OK);
		//GetParent()->m_pUIDlg->EnableWindow(true);
        delete [] bitmapBuffer;
        return false;
    }

    BITMAPINFOHEADER bitmapInfoHeader;
    ::memset(&bitmapInfoHeader, 0, sizeof(bitmapInfoHeader));
    bitmapInfoHeader.biSize        = sizeof(bitmapInfoHeader);
    bitmapInfoHeader.biWidth       = m_RawImage->GetWidth();
    bitmapInfoHeader.biHeight      = -m_RawImage->GetHeight();
    bitmapInfoHeader.biPlanes      = 1;
    bitmapInfoHeader.biBitCount    = 32;
    bitmapInfoHeader.biCompression = BI_RGB;
    bitmapInfoHeader.biSizeImage   = m_RawImage->GetWidth() *
                                     m_RawImage->GetHeight() * 4;

    Bitmap *bitmap = new Bitmap(bitmapBuffer, bitmapInfoHeader);
    ASSERT(bitmap != NULL);

    return bitmap;
}


//
// RawImage implementation
//
CDialogThemeEditor::RawImage::RawImage(char *rawBuffer,
                                       mmi_mte_image_enum type,
                                       int size,
                                       int width,
                                       int height)
    : m_Buffer(rawBuffer),
      m_Type(type),
      m_Size(size),
      m_Width(width),
      m_Height(height)
{
}

CDialogThemeEditor::RawImage::RawImage(const RawImage &rhs)
    : m_Buffer(NULL),
      m_Type(rhs.GetType()),
      m_Size(rhs.GetSize()),
      m_Width(rhs.GetWidth()),
      m_Height(rhs.GetHeight())
{
    m_Buffer = new char[rhs.GetSize()];
    ASSERT(m_Buffer != NULL);

    ::memcpy(m_Buffer, rhs.GetBuffer(), rhs.GetSize());
}

CDialogThemeEditor::RawImage::~RawImage()
{
    if (m_Buffer != NULL)
    {
        delete [] m_Buffer;
    }
}

const char* CDialogThemeEditor::RawImage::GetBuffer() const
{
    return m_Buffer;
}

mmi_mte_image_enum CDialogThemeEditor::RawImage::GetType() const
{
    return m_Type;
}

int CDialogThemeEditor::RawImage::GetSize() const
{
    return m_Size;
}

int CDialogThemeEditor::RawImage::GetWidth() const
{
    return m_Width;
}

int CDialogThemeEditor::RawImage::GetHeight() const
{
    return m_Height;
}

// Assume 32 bits per pixel
static void OutputBitmapToFile(const char *bitmapBuffer,
                               int bitmapWidth,
                               int bitmapHeight,
                               const CString &outputFilename)
{
    const int bitmapBufferSize = bitmapWidth * bitmapHeight * 4;

    BITMAPFILEHEADER bitmapFileHdr;
    bitmapFileHdr.bfType = 0x4d42;
    bitmapFileHdr.bfReserved1 = 0;
    bitmapFileHdr.bfReserved2 = 0;
    bitmapFileHdr.bfOffBits = sizeof(BITMAPFILEHEADER) +
                              sizeof(BITMAPINFOHEADER);
    bitmapFileHdr.bfSize = bitmapFileHdr.bfOffBits + bitmapBufferSize;

    BITMAPINFO bitmapInfo;
    bitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapInfo.bmiHeader.biWidth = bitmapWidth;
    bitmapInfo.bmiHeader.biHeight = bitmapHeight;
    bitmapInfo.bmiHeader.biPlanes = 1;
    bitmapInfo.bmiHeader.biBitCount = 32;
    bitmapInfo.bmiHeader.biCompression = BI_RGB;
    bitmapInfo.bmiHeader.biSizeImage = bitmapBufferSize;
    bitmapInfo.bmiHeader.biXPelsPerMeter = 0;
    bitmapInfo.bmiHeader.biYPelsPerMeter = 0;
    bitmapInfo.bmiHeader.biClrUsed = 0;
    bitmapInfo.bmiHeader.biClrImportant = 0;

    CFile file(outputFilename, CFile::modeCreate | CFile::modeWrite);

    file.Write(&bitmapFileHdr, sizeof(BITMAPFILEHEADER));
    file.Write(&bitmapInfo, sizeof(BITMAPINFOHEADER));
    file.Write(bitmapBuffer, bitmapBufferSize);
    file.Close();
}

static CString GetTempFilename()
{
    char tempPathname[512];
    ::GetTempPath(sizeof(tempPathname) / sizeof(tempPathname[0]),
                  tempPathname);

    char tempFilename[1024];
    ::GetTempFileName(tempPathname, NULL, 0, tempFilename);

    return CString(tempFilename);
}

void CDialogThemeEditor::CloseAllChildWindowOfMTE()
{
	//Close any OpenFileDialog, because the screen may change to another screen.
	CWnd *cwnd = FromHandle( this->GetSafeHwnd() ) ;	
	if( cwnd != NULL )
	{
		CWnd *cwnd2 ;
		//Open file
		cwnd2 = cwnd->FindWindow( NULL, "Open");		
		if( cwnd2 != NULL )
		{
			//bug?!
			cwnd2->ShowWindow( SW_HIDE ) ;
			//cwnd2->PostMessage(WM_CLOSE, NULL, NULL);
		}
		//Color Dialog
		cwnd2 = cwnd->FindWindow( NULL, "Color Dialog");		
		if( cwnd2 != NULL )
			cwnd2->PostMessage(WM_CLOSE, NULL, NULL);
		//Color
		cwnd2 = cwnd->FindWindow( NULL, "Color");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);
		//Color Picker
		cwnd2 = cwnd->FindWindow( NULL, "Color Picker");		
		if( cwnd2 != NULL )
			cwnd2->SendMessage(WM_CLOSE, NULL, NULL);		
	}
}

void CDialogThemeEditor::DrawGreenFlag(int ID)
{
	SetFlag(ID);
	int idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	if(idx!=-1)
	{
		DrawFlagIcon(idx);	
		//Set item to be selected and focused
		/*
		m_ListThemeEditor.SetFocus();
		m_ListThemeEditor.SetSelectionMark(idx);
		m_ListThemeEditor.SetItemState(idx,LVIS_SELECTED, LVIS_SELECTED);
		m_ListThemeEditor.EnsureVisible(idx, FALSE);	
		*/
		int nCurIndex;
		CSize siz;
		CRect rc;

		nCurIndex = m_ListThemeEditor.GetTopIndex();
		m_ListThemeEditor.GetItemRect(0, rc, LVIR_BOUNDS);

		siz.cx = 0;
		siz.cy = (idx - nCurIndex )*rc.Height();

		m_ListThemeEditor.Scroll(siz);		
		
		//Redraw the editing component
		if( !IsEditingAnimation() )
		{
			m_editing = true;
			ThemeComEdit();
		}
	}
}
void CDialogThemeEditor::EnableMenuForThemeEditor( int sub_menu_num, int item_num, bool enable )
{
	CMenu* mmenu = GetMenu();
	if( mmenu != NULL )
	{		
		CMenu* submenu = mmenu->GetSubMenu(sub_menu_num); 
		if( submenu != NULL )
		{
			if( enable ) //enable
				submenu->EnableMenuItem(item_num, MF_BYPOSITION | MF_ENABLED );
			else
				submenu->EnableMenuItem(item_num, MF_BYPOSITION | MF_DISABLED | MF_GRAYED );
		}		
	}
}

void CDialogThemeEditor::OnButtonSilceSet() 
{
	// TODO: Add your control notification handler code here
	const CString componentName(GetSelectedComponentName());
	std::map<int, type_9slice>::iterator slice_Iter;
	CString str;
	int left = 0, top = 0, right = 0, bottom = 0;

	if(componentName == "NoSelected")
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("Please select a valid item first.");
		m_pUIDlg->EnableWindow(true);
		UpdateData(FALSE);
		return;
	}

	int theme_idx =  m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	if(theme_idx==-1) 
	{
		EnableMenuForThemeEditor(0,4,false);
		EnableMenuForThemeEditor(0,5,false);
		UpdateData(FALSE);
		return;
	}
	

	
//	char theme_type_name[64];
//	char theme_component_name[256];
	char theme_id[64];
	mmi_mte_theme_component_struct *the_component;
	m_ListThemeEditor.GetItemText(theme_idx,0,theme_id,64);
	


    // if image delete should be return;
    m_SliceLeft.GetWindowText(str);
    left = str.IsEmpty() ? 0 : _ttoi(str);

	m_SliceTop.GetWindowText(str);
    top = str.IsEmpty() ? 0 : _ttoi(str);

	m_SliceRight.GetWindowText(str);
    right = str.IsEmpty() ? 0 : _ttoi(str);

	m_SliceBottom.GetWindowText(str);
    bottom = str.IsEmpty() ? 0 : _ttoi(str);
 
	if (m_typestr.CompareNoCase("FILLER") != 0 && m_typestr.CompareNoCase("IMAGE") != 0 )
	{
		UpdateData(FALSE);
		return ;
	}
	the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(atoi(theme_id)-1);

	if (m_typestr.CompareNoCase("FILLER") == 0 )
	{
	UI_filled_area **filler =
		static_cast<UI_filled_area **>
		(mmi_mte_translate_theme_component_data_pointer(
		the_component, &my_theme));
        ASSERT(filler != NULL);

    if(*filler == NULL)
	{
		UpdateData(FALSE);
		return;
	}	
	
	if ((*filler)->b == NULL)
	{
		m_pUIDlg->EnableWindow(false);
		::MessageShow("There is no image data.");
		m_pUIDlg->EnableWindow(true);
		UpdateData(FALSE);
		return;
	}

	if(m_ntop == top &&	m_nleft == left && m_nright == right && m_nbottom == bottom)
	{
		m_pUIDlg->EnableWindow(false);
			::MessageShow("There is no value different from the settings."); 
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			return;
		}
/*	if (top + bottom >= m_bmInfo.bmHeight || right + left >= m_bmInfo.bmWidth)
		{
			str.Format("The settings should be: Top + Bottom < Height (%d) and Left + Right < Width (%d)."
				,m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			m_pUIDlg->EnableWindow(false);
			::MessageShow(str);
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			//	::MessageShow("The setting of topleft and bottomright is wrong.\nShould be: right >= left and bottom >= top.");
		return;
	}
	if(  abs(top) + abs(bottom)  != 0)
	{
		  if(top + bottom + 1 != m_bmInfo.bmHeight)
			  if( right + left + 1 != m_bmInfo.bmWidth && abs(right)+abs(left)!=0)
			  {
				  str.Format("The settings should include at least one of the below situations:\n1. Top + Bottom + 1 = Height(%d); \n2. Left + Right + 1 = Width(%d).\n3. top=bottom=0,left+right<=Width\n4. left=right=0, top+bottom<=height",m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			      m_pUIDlg->EnableWindow(false);
			     ::MessageShow(str);
		    	 m_pUIDlg->EnableWindow(true);
		         UpdateData(FALSE);
				 return;
			  }

	}
	*/

		if (top + bottom >= m_bmInfo.bmHeight || right + left >= m_bmInfo.bmWidth || (top + bottom + 1 != m_bmInfo.bmHeight && right + left + 1 != m_bmInfo.bmWidth))
	{
		{
			str.Format("The settings should be: Top + Bottom < Height (%d) and Left + Right < Width (%d).\n\nAnd the settings should include at least one of the below situations:\n1. Top + Bottom + 1 = Height; \n2. Left + Right + 1 = Width."
				,m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			m_pUIDlg->EnableWindow(false);
			::MessageShow(str);
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			//	::MessageShow("The setting of topleft and bottomright is wrong.\nShould be: right >= left and bottom >= top.");
		return;
	}
	}
  //orginal limition not include 3 slcie ,just 9 slice

	/*
	if (top > bottom || right < left)
	{ 
		::MessageShow("The setting of topleft and bottomright is wrong.\nShould be: right >= left and bottom >= top.");
		return;
	}
	*/
		char theme_comp_id[24];
		m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);
		slice_Iter = map_slice_value.find(atoi(theme_comp_id));
		if (slice_Iter == map_slice_value.end())
		{
			slice_value.nleft = left;
			slice_value.ntop = top;
			slice_value.nright = right;
			slice_value.nbottom = bottom;
	
			map_slice_value.insert(std::make_pair(atoi(theme_comp_id),slice_value));
		}
		else
		{
			slice_Iter->second.nleft = left;
			slice_Iter->second.ntop = top;
			slice_Iter->second.nright = right;
			slice_Iter->second.nbottom = bottom;
		}
    int width;
	int height; 
	int size;
	char *img_data_ptr;
	mmi_mte_image_enum mte_image_type;
	char *temp = (char *)(*filler)->b;
	mmi_mte_get_image_resource_info((char *)(*filler)->b, -1, &img_data_ptr, &mte_image_type, &width, &height, &size, NULL, NULL);
 	
	char *animationImageBuffer = new char[size + 20 + 8];
    ::memcpy( animationImageBuffer, temp, (size + 20 + 8)*sizeof(char) ) ;
	
    char *header = animationImageBuffer;

	header[8 + 1] = 0 & 0xFF;
	header[8 + 4] = left & 0xFF;
	header[8 + 5] = (left >> 8) & 0xFF;
	
    header[8 + 8] = top & 0xFF;
	header[8 + 9] = (top >> 8) & 0xFF;
	
	header[8 + 12] = right & 0xFF;
	header[8 + 13] = (right >> 8) & 0xFF;
	
	header[8 + 16] = bottom & 0xFF;
	header[8 + 17] = (bottom >> 8) & 0xFF;

	UI_filled_area **oldFiller =
		static_cast<UI_filled_area **>
		(GetComponentAddr(&my_theme, m_filler_themeid));
	ASSERT(oldFiller != NULL);
	
	UI_filled_area *newFiller = new UI_filled_area;
	ASSERT(newFiller != NULL);
	
	if (*oldFiller != NULL)
	{
		::memcpy(newFiller, *oldFiller, sizeof(UI_filled_area));
	}
	
	newFiller->b = reinterpret_cast<PU8>(animationImageBuffer);
//	newFiller->flags = UI_FILLED_AREA_TYPE_BITMAP; // FIXME
 	*oldFiller = newFiller;
	SetFlag(m_filler_themeid);
	ActivateTheme(&my_theme);
	g_screen_cb = true; //Update at next refresh
	InsertFillerHistory();	
		g_onedit = true;
	}	
	else if (m_typestr.CompareNoCase("IMAGE") == 0)
	{
		unsigned char **image = (unsigned char**) mmi_mte_translate_theme_component_data_pointer(the_component, &my_theme);
		if ((*image) == NULL)
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("There is no image data."); 
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			return;
		}
		
		if(m_ntop == top &&	m_nleft == left && m_nright == right && m_nbottom == bottom)
		{
			m_pUIDlg->EnableWindow(false);
			::MessageShow("There is no value different from the settings."); 
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			return;
		}

	/*	if (top + bottom >= m_bmInfo.bmHeight || right + left >= m_bmInfo.bmWidth)
		{
			str.Format("The settings should be: Top + Bottom < Height (%d) and Left + Right < Width (%d)."
				,m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			m_pUIDlg->EnableWindow(false);
			::MessageShow(str);
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			//	::MessageShow("The setting of topleft and bottomright is wrong.\nShould be: right >= left and bottom >= top.");
		return;
	}
	if(  abs(top) + abs(bottom)  != 0)
	{
		  if(top + bottom + 1 != m_bmInfo.bmHeight)
			  if( right + left + 1 != m_bmInfo.bmWidth && abs(right)+abs(left)!=0)
			  {
				  str.Format("The settings should include at least one of the below situations:\n1. Top + Bottom + 1 = Height(%d); \n2. Left + Right + 1 = Width(%d).\n3. top=bottom=0,left+right<=Width\n4. left=right=0, top+bottom<=height",m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			      m_pUIDlg->EnableWindow(false);
			     ::MessageShow(str);
		    	 m_pUIDlg->EnableWindow(true);
		         UpdateData(FALSE);
				 return;
			  }

	}
	*/
		if (top + bottom >= m_bmInfo.bmHeight || right + left >= m_bmInfo.bmWidth || (top + bottom + 1 != m_bmInfo.bmHeight && right + left + 1 != m_bmInfo.bmWidth))
		{
		//	if(top != 0 && bottom != 0 && left != 0 && right != 0)
		{
			str.Format("The settings should be: Top + Bottom < Height (%d) and Left + Right < Width (%d).\n\nAnd the settings should include at least one of the below situations:\n1. Top + Bottom + 1 = Height; \n2. Left + Right + 1 = Width."
				,m_bmInfo.bmHeight,m_bmInfo.bmWidth);
			m_pUIDlg->EnableWindow(false);
			::MessageShow(str);
			m_pUIDlg->EnableWindow(true);
			UpdateData(FALSE);
			//	::MessageShow("The setting of topleft and bottomright is wrong.\nShould be: right >= left and bottom >= top.");
			return;
		}
		}
		

		char theme_comp_id[24];
		m_ListThemeEditor.GetItemText(m_old_theme_idx,0,theme_comp_id,24);
		slice_Iter = map_slice_value.find(atoi(theme_comp_id));
		if (slice_Iter == map_slice_value.end())
		{
			slice_value.nleft = left;
			slice_value.ntop = top;
			slice_value.nright = right;
			slice_value.nbottom = bottom;
			
			map_slice_value.insert(std::make_pair(atoi(theme_comp_id),slice_value));
		}
		else
		{
			slice_Iter->second.nleft = left;
			slice_Iter->second.ntop = top;
			slice_Iter->second.nright = right;
			slice_Iter->second.nbottom = bottom;
		}
		int width;
		int height; 
		int size;
		char *img_data_ptr;
		mmi_mte_image_enum mte_image_type;
	//	char *temp = (char *)(*filler)->b;
		mmi_mte_get_image_resource_info((char *)(*image), -1, &img_data_ptr, &mte_image_type, &width, &height, &size, NULL, NULL);
		
	//	char *animationImageBuffer = new char[size + 20 + 8];
		unsigned char *header =  new unsigned char[size + 20 + 8];
		::memcpy( header, (*image), (size + 20 + 8)*sizeof(char) ) ;
		
	//	char *header = animationImageBuffer;
		
		header[8 + 1] = 0 & 0xFF;
		header[8 + 4] = left & 0xFF;
		header[8 + 5] = (left >> 8) & 0xFF;
		
		header[8 + 8] = top & 0xFF;
		header[8 + 9] = (top >> 8) & 0xFF;
		
		header[8 + 12] = right & 0xFF;
		header[8 + 13] = (right >> 8) & 0xFF;
		
		header[8 + 16] = bottom & 0xFF;
		header[8 + 17] = (bottom >> 8) & 0xFF; 
		
	
		*image = header;
		InsertImageHistory(m_image_themeid,*image);
		ComHistroy[m_image_themeid]++;
			ComIdxHistroy[m_image_themeid]++;
		SetFlag(m_image_themeid);
		ActivateTheme(&my_theme);
		g_screen_cb = true; //Update at next refresh
	
		g_onedit = true;
	}
//	delete [] animationImageBuffer;
	/*
	if ((*filler)->b)
	{
		const mmi_mte_image_enum imageType = mte_image_type;
		mmi_mte_return_code_enum ret;
		int headerSize = 8 + 20;
		ret = mmi_mte_get_image_9slice_header(
			header,
			imageType,
			&headerSize,
			width,
			height,
			left,
			top,//GetAnimationRepeatCount(),
			right,
			bottom
		);
	}*/
		
	
	m_nValueLeft = left;
	m_nValueTop = top ;
	m_nValueRight = right;
	m_nValueBottom = bottom;


	if (SelectItemByComponentName(componentName))
    {
        m_ListThemeEditor.SetFocus();
		DrawGreenFlag(the_component->id);
    }
}

void CDialogThemeEditor::OnFillerSliceImage() 
{
	// TODO: Add your control notification handler code here
	CRect rectImage;
	GetDlgItem(IDC_FILLER_IMAGE)->GetWindowRect(&rectImage);
	ScreenToClient(&rectImage);

	CPoint Cursor ,point;
	::GetCursorPos(&Cursor);
	CRect	rect,rect_flag;
	GetDlgItem(IDC_FILLER_IMAGE)->GetWindowRect(rect);
    point.x = Cursor.x - rect.TopLeft().x - offset_for_slice_x;
	point.y = Cursor.y - rect.TopLeft().y - offset_for_slice_y;
/*
 	if (rectImage.PtInRect(point))
	{
		int aa = offsetx;
		int bb = offsety;
		int cc = sourcex;
		int dd = sourcey;
		int ee = m_size.cx;
		int ed = m_size.cy;
		
	}*/
	CRect rect1(0,0,m_size.cx - offset_for_slice_x * 2, m_size.cy - offset_for_slice_y * 2);
	if (!rect1.PtInRect(point))
	{
		return;
	}
	
	CString str;
	if (m_nSetTopLeft == 1)
	{
		str.Format(_T("%d"), point.x + sourcex);

		m_SliceLeft.SetWindowText(str);

	}
	else if (2 == m_nSetTopLeft)
	{
	//	m_nValueTop = point.y + sourcey ;		
		str.Format(_T("%d"), point.y + sourcey);
 		m_SliceTop.SetWindowText(str);
	//	UpdateData(FALSE);
	}
	else if (3 == m_nSetTopLeft)
	{
		
		if (m_bmInfo.bmWidth > 0)
		{
			str.Format(_T("%d"), m_bmInfo.bmWidth -(point.x + sourcex));
			m_SliceRight.SetWindowText(str);
		}

	}
	else if (4 == m_nSetTopLeft)
	{
		if (m_bmInfo.bmHeight > 0)
		{
			str.Format(_T("%d"), m_bmInfo.bmHeight - (point.y + sourcey));
 			m_SliceBottom.SetWindowText(str);
		}

	//	UpdateData(FALSE);
	}
}
bool CDialogThemeEditor::FindTheCompIsSlice(int idx)
{
	char theme_comp_id[24];
	m_ListThemeEditor.GetItemText(idx,0,theme_comp_id,24);

	idx = atoi(theme_comp_id);

	list<int>::iterator iter = list_slice.begin();
	if (list_slice.empty())
	{
		return false;
	}
	for(;iter!= list_slice.end();iter++)
	{
		if (*iter == idx)
		{
			return true;
		}
		
	}

	return false;
}

void CDialogThemeEditor::ShowHideSliceControls(bool m_flag)
{
	if(m_flag)
	{
		m_SliceBottom.ShowWindow(SW_SHOW);
		m_SliceRight.ShowWindow(SW_SHOW);
		m_SliceTop.ShowWindow(SW_SHOW);
		m_SliceLeft.ShowWindow(SW_SHOW);
		/*
		GetDlgItem(IDC_STATIC_LEFT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_TOP)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_RIGHT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_BOTTOM)->ShowWindow(SW_SHOW);*/
		GetDlgItem(IDC_BUTTON_SILCE_SET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_SETTING_LEFT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_SETTING_RIGHT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_SETTING_TOP)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIO_SETTING_BOTTOM)->ShowWindow(SW_SHOW);
	}
	else
	{
		m_SliceBottom.ShowWindow(SW_HIDE);
		m_SliceRight.ShowWindow(SW_HIDE);
		m_SliceTop.ShowWindow(SW_HIDE);
		m_SliceLeft.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LEFT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_TOP)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_RIGHT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_BOTTOM)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SILCE_SET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_SETTING_LEFT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_SETTING_RIGHT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_SETTING_TOP)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIO_SETTING_BOTTOM)->ShowWindow(SW_HIDE);
	}
}

void CDialogThemeEditor::OnRadioSettingBottom() 
{
	// TODO: Add your control notification handler code here
	m_nSetTopLeft = 4;
}

void CDialogThemeEditor::OnRadioSettingRight() 
{
	// TODO: Add your control notification handler code here
	m_nSetTopLeft = 3;
}

void CDialogThemeEditor::OnRadioSettingTop() 
{
	// TODO: Add your control notification handler code here
	m_nSetTopLeft = 2;
}

void CDialogThemeEditor::OnRadioSettingLeft() 
{
	// TODO: Add your control notification handler code here
	m_nSetTopLeft = 1;
}


void CDialogThemeEditor::OnNMClickListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;

    // Owen
    if (IsEditingAnimation())
    {
        const int selectedIndex =
                m_ListThemeEditor.GetNextItem(-1, LVNI_ALL| LVNI_SELECTED);

	    if (selectedIndex == m_old_theme_idx)
        {
            return;
        }
        if (selectedIndex!=-1)
        {
        LeaveAnimationEditingMode();
    }

    }

	m_editing = true;
	
	if (!m_bShowNoEditAgain)
	{
		m_bShowNoEditAgain = true; 
		m_ListThemeEditor.SetItemState(-1,0, LVIS_SELECTED);  
		OutputDebugString("m_ListThemeEditor.SetItemState(-1,LVIS_SELECTED, LVIS_SELECTED);");
				
	} 
	else
	{
	ThemeComEdit();
//		::MessageShow("This component is not allowed to be edited.");
	}
	// m_ListThemeEditor.SetFocus();
	
}

void CDialogThemeEditor::OnNMRClickListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult)
{
	OnNMClickListThemeEditor(pNMHDR, pResult);
	//LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<NMITEMACTIVATE>(pNMHDR);
	// TODO: Add your control notification handler code here
    // *pResult = 0;
}

void CDialogThemeEditor::OnLvnBeginrdragListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult)
{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
   OnNMClickListThemeEditor(pNMHDR, pResult);
	// TODO: Add your control notification handler code here
//	*pResult = 0;
}

void CDialogThemeEditor::OnLvnBegindragListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult)
{
	 OnNMClickListThemeEditor(pNMHDR, pResult);
	//LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	//*pResult = 0;
}

char* CDialogThemeEditor::ConvertBSTRToString(BSTR pSrc)
{
	if(!pSrc) return NULL;

	//convert even embeded NULL
	DWORD cb,cwch = ::SysStringLen(pSrc);

	char *szOut = NULL;

	if(cb = ::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, NULL, 0, 0, 0))
	{
		szOut = new char[cb];
		if(szOut)
		{
			szOut[cb - 1]  = '\0';
			if(!::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, szOut, cb, 0, 0))
			{
				delete []szOut;//clean up if failed;
				szOut = NULL;
			}
		}
	}

	return szOut;
}

void CDialogThemeEditor::PostNcDestroy()
{
	CDialog::PostNcDestroy();
	delete this;
}
