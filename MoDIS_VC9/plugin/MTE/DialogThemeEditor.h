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
 * DialogThemeEditor.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(AFX_DIALOGTHEMEEDITOR_H__F50C81FA_3F8F_4AE0_A6F5_36FDE980F0AB__INCLUDED_)
#define AFX_DIALOGTHEMEEDITOR_H__F50C81FA_3F8F_4AE0_A6F5_36FDE980F0AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogThemeEditor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeEditor dialog
//#include "DialogGotoScreen.h"

#include "DataTipListCtrl.h"
#include "mtegprot.h"
#include "DialogColor.h"
#include "EasySize.h"
#include "BitmapViewer.h"
#include "DialogGotoScreen.h"
#define MAX_THEME_COM_NUM 1000

#pragma warning(disable:4786)
#include <map>
#include <vector>
#include <list>

using namespace std;
typedef pair <int, color> CstrColorPair;
typedef pair <int, UI_filled_area*> CstrFillerPair;
typedef pair <int, unsigned char*> CstrImagePair;
typedef void (*(*MMI_MTE_Callback)(int))(void);

class type_9slice
{
public:
	int nleft;
	int ntop;
	int nright;
	int nbottom;
};
#define MessageShow(string) MessageBox(this->m_hWnd,string,"MoDIS_UI",MB_OK)
class CDialogThemeEditor : public CDialog
{
	DECLARE_EASYSIZE

//Plugin
protected:
	int m_nMainLCDWidth, m_nMainLCDHeight;
	
// Construction
public:
    CDialogThemeEditor(CWnd* pParent, MMI_MTE_Callback w32_mmi_mte_api_cb);
    MMI_MTE_Callback w32_mmi_mte_api;
	CComboBoxEx  m_ComboComGroup;
	CWnd		*main_dlg;
	CWnd* m_pDialogTheme, *m_pUIDlg;
	CDialogColor *color_dlg;
	virtual void OnGetMinMaxInfo( MINMAXINFO FAR* pMinMaxInfo );
	CDialogGotoScreen *goto_screen_dlg;
	//CDC* pDC;
	//CDC dcMemory;
	CBitmap							bitmap;
	BITMAPINFO						m_filler_bitmap_info;
	BITMAPINFO						m_image_bitmap_info;
	//CListCtrl	m_ListThemeEditor;
	CDataTipListCtrl m_ListThemeEditor;
	CStatic m_StaticWarningScreen;
	HACCEL  m_hAccelTable;
//	void DrawTest(int lcd_width, int lcd_height,unsigned char *new_app_flag); 
	void UpdatePosition();
	CString GetComponentTypeStr(int type_id);
	int m_the_num_group_scr;
	void ShowCurrentScreen();
	void EnableMenuForThemeEditor( int sub_menu_num, int item_num, bool enable );
	BOOL	  m_bCreated;
	void DrawThemeComponent(void);
	void ReUnDoColor();
	COLORREF 	m_ColRef;
	COLORREF 	m_FillerC;
	COLORREF 	m_FillerAC;
	COLORREF 	m_FillerBC;
	COLORREF 	m_FillerSC;
    bool SelectColor(COLORREF &color,
                     bool isTransparentColorAllowed = false);
	CRect GetColorDisplayRect(unsigned int idc);
	int m_theme_idx;
	int Get_Theme_Com_in_Current_Screent(int max_component_number, const mmi_mte_theme_component_struct *theme_component_list[]);
	CString Get_Component_Group_Name(int id);
	CString m_group_name; //If CURRENT_SCREEN_START then cb
	//HANDLE m_hWMutex;
	bool m_SupportImage;
	bool m_bautoclose;
	void ActivateTheme(MMI_theme *ptr);
    unsigned char* OpenDrawRetPtr(unsigned int controlID);
	CString GetRecommendedImageType(mmi_mte_image_enum imageType);
	CString GetSupportedImageTypes(unsigned int imageType);
	int m_recommend_width;
	int m_recommend_height;
	int m_max_width; 
	int m_max_height; 

	int m_ntop;
	int m_nleft;
	int m_nright;
	int m_nbottom;
   
	int offset_for_slice_x;
	int offset_for_slice_y;
   
	bool m_bSliceComponent;
	int m_nSetTopLeft;
	void ShowHideSliceControls(bool m_flag);
	bool m_editing;
	unsigned int m_allowed_image_type;
	mmi_mte_image_enum m_recommend_image_type;
	void GetImageAttrRecommendation(const CString &componentName);
//	mmi_mte_image_enum GetImageTypeEnum(CString  recommend_image_type);
//

    bool PreprocessImage(const CString &imageFilename,
                         mmi_mte_image_enum &imageType,
                         bool &hasEncodedImage,
                         CString &encodedImageFilename);

    bool EncodeBMPIntoAB2(const CString &inputFilename,
                          CString &outputFilename,
                          mmi_mte_image_enum &outputType);

    bool EncodePNGIntoAB2(const CString &inputFilename,
                          CString &outputFilename,
                          mmi_mte_image_enum &outputType);

    bool EncodePNGIntoABM(const CString &inputFilename,
                          CString &outputFilename);

    bool DecodeABMIntoBMP(const char *abmImageBuffer,
                          int abmImageSize,
                          int imageWidth,
                          int imageHeight,
                          CString &outputFilename);

	char *m_filler_image_data_buffer;
	char *m_image_image_data_buffer;
	bool m_drawcolor;
	bool m_drawfiller;
	int m_color_themeid;
	int	m_filler_themeid;
	int m_image_themeid;
	int m_integer_themeid;
	void ThemeComEdit();
	void DisableThemeComponent(bool c, bool f, bool i, bool in);
	void DisableFillerTransparent(const mmi_mte_theme_component_struct *the_component);
	CImageList m_SmallImg;
	//bool flag[MAX_THEME_COM_NUM];
	bool defaultnull[MAX_THEME_COM_NUM];
	bool first_touch[MAX_THEME_COM_NUM];
	unsigned int  ComHistroy[MAX_THEME_COM_NUM];
	unsigned int  ComIdxHistroy[MAX_THEME_COM_NUM];
	LVITEM m_lvItem;
	int m_total_component_num;
	void UpdateListTheme();
	void DrawFlagIcon(int theme_idx);
	int m_theint;
	int m_theintTemp;
	int m_nDelaytime;
	int m_nDelaytimeTemp;	
	bool m_updateint;
	bool m_find;
	void ImageRecDisplay();
	CString m_typestr;
   CString SizeFloatValueToString(float size);
	void DisplayImagebyCom(unsigned int idc,unsigned char *ptr);
	void SetItemTextU(HWND hwnd, int nItem, int subitem, wchar_t *str);
	bool m_test;
//	unsigned char *m_image_ptr;//delete it while delete image
	int m_old_theme_idx;
	HWND m_listhWnd;
	void SetIniLanguage(CString restr);
	void SaveBuffertoBitmapFile(unsigned int idc);
	CString m_BMPFile;
	//Draw Bitmap
	void ShowBMP();
	CRect rectStaticClient;
	SCROLLINFO horz,vert;
	BOOL	erase;
	int sourcex, sourcey,offsetx,offsety;
	void UpdateListThemeOnDiffTheme(void);
	CStatic	m_st1;
	CScrollBar	m_vbar;
	CScrollBar	m_hbar;
	//HBITMAP GetRotatedBitmap( HBITMAP hBitmap, float radians, COLORREF clrBack );
	void DrawNonBitmap();
	bool m_AddImage;
	int m_oldh;
	int m_oldw;
	void OnFillerImage();
	UI_filled_area *GetNewFiller();
	bool m_transparent;
	void AddGroupFilter();
	void SetLanFilter();
	multimap<int, color> map_color[MAX_THEME_COM_NUM];
	multimap<int, UI_filled_area*> map_filler[MAX_THEME_COM_NUM];
	multimap<int, unsigned char*> map_image[MAX_THEME_COM_NUM];
	
	list<int> list_slice;
	type_9slice slice_value;
	std::map<int, type_9slice> map_slice_value;
	

	bool FindTheCompIsSlice(int idx);
	void ReUnDoFiller();
	void ReUnDoImage();
	void InsertColorHistory(int id, color c);
    void InsertFillerHistory();
	void InsertFillerHistory(int id, UI_filled_area* f);
	void InsertImageHistory(int id, unsigned char* image);
	void UnDoComponent();
	void ReDoComponent();
	void FreeMem();
	CString GetImageFileFilter();
	bool m_notedit;

	bool m_bShowNoEditPop;
	bool m_bShowNoEditAgain;

	void SetFlag(int id);

	BOOL GetOfficeWordPath(LPOLESTR szApp, LPSTR szPath, ULONG cSize);
	void CloseAllChildWindowOfMTE();
	void DrawGreenFlag(int ID);
    bool IsEditingAnimation();
    void EnterAnimationEditingMode();
    void LeaveAnimationEditingMode();

	static char* ConvertBSTRToString(BSTR pSrc);

	// Dialog Data
	//{{AFX_DATA(CDialogThemeEditor)
	enum { IDD = IDD_DIALOG_THEME_EDITOR };
	int		m_nValueLeft;
	int		m_nValueRight;
	int		m_nValueTop;
	int		m_nValueBottom;
	//}}AFX_DATA

	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogThemeEditor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
protected:

	HICON m_hIcon;
	CDC m_dcMem;            // Compatible Memory DC for dialog
	
	HBITMAP m_hBmpOld;    // Handle of old bitmap to save
	HBITMAP m_hBmpNew;    // Handle of new bitmap from file
   
	BITMAP m_bmInfo;        // Bitmap Information structure
	CPoint m_pt;            // Position for upper left corner of bitmap
	CSize m_size; 

	// Generated message map functions
	//{{AFX_MSG(CDialogThemeEditor)
    afx_msg void OnVScroll(UINT code, UINT position, CScrollBar *scrollBar);
    afx_msg void OnHScroll(UINT code, UINT position, CScrollBar *scrollBar);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	virtual void OnCancel();
	afx_msg void OnPaint();
	afx_msg void OnFindComponent();
	afx_msg void OnGotoScreen();	
	afx_msg void OnMteUg();
	afx_msg void OnSetting();
	afx_msg void OnEnglish();
	afx_msg void OnSimchinese();
	afx_msg void OnSelchangeComponentGroup();
	afx_msg void OnDropdownComponentGroup();
	afx_msg void OnColor();
	afx_msg void OnFillerc();
	afx_msg void OnFillerbc();
	afx_msg void OnFillerac();
	afx_msg void OnFillersc();
	afx_msg	void OnThemeSave();
	afx_msg	void OnThemeApply();
	afx_msg	void OnImage();
	afx_msg	void OnCheckBorder();
	afx_msg	void OnCheckFillerBorder();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnItemchangedListThemeEditor(NMHDR* pNMHDR, LRESULT* pResult); 
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnButtonImage();
	afx_msg void OnCheckTransparent();
	afx_msg void OnButtonUpint();
	afx_msg void OnButtonSetDelayTime();
	afx_msg void OnReDo();
	afx_msg void OnUnDo();
	afx_msg void OnMove(int x, int y);
    afx_msg void OnLButtonDown(UINT flags, CPoint point);
    afx_msg void OnLButtonDblClk(UINT flags, CPoint point);
    afx_msg void OnAnimationImageSequence();
    afx_msg void OnAnimationImageAdd();
    afx_msg void OnAnimationImageRemove();
    afx_msg void OnChangeAnimationDelay();
    afx_msg void OnChangeAnimationRepeat();
	afx_msg void OnButtonSilceSet();
	afx_msg void OnFillerSliceImage();
	afx_msg void OnRadioSettingBottom();
	afx_msg void OnRadioSettingRight();
	afx_msg void OnRadioSettingTop();
	afx_msg void OnRadioSettingLeft();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    bool IsAnimationSupported(
            const mmi_mte_theme_component_struct *componentInfo);
    bool HasAnimation(const UI_filled_area *filler,
                      const mmi_mte_theme_component_struct *componentInfo);
    bool IsAnimationType(mmi_mte_image_enum imageType);

    void ShowAnimationEditingControls();
    void HideAnimationEditingControls();
    bool LoadImageBlock(LPCTSTR pngImageFilename);
    void SetupBitmapViewer();
    void MakeAnimationImage();
    void LoadAnimationImage();
    int GetAnimationDelay();
    int GetAnimationRepeatCount();
    int GetNumAnimationFrames();
    void ClearImageBlocks();
    CRect GetControlRect(int controlID);

    void RemoveImageFromFiller(int id);
    bool IsComponentModified(int id) const;
    void SetComponentModified(int id);
    void MarkGreenFlagOnSelectedItem();
    CString GetSelectedComponentName();
    bool SelectItemByComponentName(const CString &name);
    void* GetComponentAddr(const MMI_theme *theme, int componentID);
    void* GetComponentAddr(const MMI_theme *theme,
                           const mmi_mte_theme_component_struct *component);
	void GetImageFileFilterW( WCHAR *filter);
	void ThemeSave();
private:
    // Inner class definition
 
    class RawImage
    {
    public:
        RawImage(char *rawBuffer,
                 mmi_mte_image_enum type,
                 int size,
                 int width,
                 int height);
        RawImage(const RawImage &rhs);
        ~RawImage();

    private:
        RawImage& operator=(const RawImage &);

    public:
        const char* GetBuffer() const;
        mmi_mte_image_enum GetType() const;
        int GetSize() const;
        int GetWidth() const;
        int GetHeight() const;

    private:
        char *m_Buffer;
        mmi_mte_image_enum m_Type;
        int m_Size;
        int m_Width;
        int m_Height;
    };

    class ImageBlock
    {
    public:
        ImageBlock(const CRect &imageRect,
                   const CRect &selectionRect);
        ~ImageBlock();

    public:
        CRect GetImageRect() const
            { return m_ImageRect; }

        void SetImageRect(const CRect &imageRect)
            { m_ImageRect = imageRect; }

        CRect GetSelectionRect() const
            { return m_SelectionRect; }

        void SetSelectionRect(const CRect &selectionRect)
            { m_SelectionRect = selectionRect; }

        const MoDIS::MTE::Bitmap* GetPreviewBitmap() const
            { return m_PreviewBitmap; }

        bool HasRawImage() const
            { return (m_RawImage != NULL); }

        void SetRawImage(RawImage *rawImage);
        const RawImage* GetRawImage() const { return m_RawImage; }
        void ClearRawImage();

        void DrawSelection(CDC &dc) const;
        void DrawPreview(CDC &dc) const;

    private:
        MoDIS::MTE::Bitmap* CreatePreviewBitmap() const;

    public:
        static MMI_MTE_Callback w32_mmi_mte_api;

    private:
        CRect m_ImageRect;
        CRect m_SelectionRect;

        RawImage *m_RawImage;
        mutable MoDIS::MTE::Bitmap *m_PreviewBitmap;
    };

private:
    typedef std::vector<int>        ControlIDs;
    typedef std::vector<ImageBlock> ImageBlocks;

    bool m_IsEditingAnimation;
    ControlIDs m_AnimationEditingControlIDs;
    ImageBlocks m_ImageBlocks;
    ImageBlocks::iterator m_SelectedImageBlock;

    MoDIS::MTE::BitmapViewer m_BitmapViewer;
    CComboBox m_AnimationRepeatCount;
    CEdit m_AnimationDelay;

	CEdit m_SliceLeft;
	CEdit m_SliceTop;
	CEdit m_SliceRight;
	CEdit m_SliceBottom;

    bool m_IsDialogInitialized;
	int m_nrepeatCount;
public:
	afx_msg void OnNMClickListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMRClickListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnBeginrdragListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnBegindragListThemeEditor(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	virtual void PostNcDestroy();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTHEMEEDITOR_H__F50C81FA_3F8F_4AE0_A6F5_36FDE980F0AB__INCLUDED_)
