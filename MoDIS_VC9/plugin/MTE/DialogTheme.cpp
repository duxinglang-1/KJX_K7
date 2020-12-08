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
 * DialogTheme.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// DialogTheme.cpp : implementation file
//

#include "stdafx.h"
#include <string>
#include "DialogTheme.h"
#include "DialogThemeEditor.h"
#include "DialogThemeIndex.h"
#include "DialogProcess.h"
#include "MTE_Util.h"
#include "plugin_mte.h"
#include "plugin_cmd.h"

//#define MODIS_MTE_UNIT_TEST

#ifdef MODIS_MTE_UNIT_TEST
#define UNIT_TEST_DIRECTORY \
    "E:\\home\\mtk02172\\WorkingDirectory\\MTE_UnitTest\\"
#define PREPEND_UNIT_TEST_DIRECTORY(filename) UNIT_TEST_DIRECTORY ## filename

static bool CompareFiles(const CString &filename1, const CString &filename2)
{
    CString command;
    
    command.Format("%s %s%s %s%s",
                   "diff --brief",
                   UNIT_TEST_DIRECTORY, filename1,
                   UNIT_TEST_DIRECTORY, filename2);

    return (::_tsystem(command) == 0);
}
#endif // MODIS_MTE_UNIT_TEST

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern bool g_close_theme_editor;
#define THEME_COM_NUM 200

static const CString END_COLOR("End_Color");
static const CString END_IMAGE("End_Image");
static const CString END_FONT("End_Font");
static const CString END_FILLER("End_Filler");
static const CString END_INTEGER("End_Integer");

CString g_font_str[THEME_COM_NUM];
CString g_color_str[THEME_COM_NUM*2];
CString g_UI_filled_area_str[THEME_COM_NUM];
CString g_UI_image_str[THEME_COM_NUM];
CString g_int_str[THEME_COM_NUM];

int g_MapTheMemtoTheID[THEME_COM_NUM*3];
extern bool g_hidetheme;
extern BOOL g_bMTEOpened;
extern BOOL g_bMSLTOpened;
int g_Theme_Lan; //g_Theme_Lan 0 ENGLISH, 1 Simplified Chinese

///*extern*/ bool b_exit_flags = 0;	//pinksword
int g_MMI_height = 0,g_MMI_width = 0;//pinksword

/////////////////////////////////////////////////////////////////////////////
// CDialogTheme dialog

MMI_theme my_theme;
bool g_notsaved_theme =false;
bool font_msg = true;
char save_modify_flag[MAX_THEME_NUM][MAX_THEME_COM_NUM];
char history_modify_flag[MAX_THEME_NUM][MAX_THEME_COM_NUM];

UINT* g_pMMIIsGoingToPowerOff = NULL;
UINT* g_pMoDISUIClosedByMMI = NULL;
extern bool b_exit_flags;

extern Cplugin_mteApp theApp;
inline void PeekAndPumpMessage()
{
	MSG message;
	if(::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
	{
		::TranslateMessage(&message);
		::DispatchMessage(&message);
	}	
}

CDialogTheme::CDialogTheme(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTheme::IDD, pParent)      
{
	main_dlg = pParent;
	theme_editor_dlg = NULL;

	m_plugin_info.emType = PLUG_IN_TYPE_MMI;
	m_plugin_info.emMsgID = PLUG_IN_MSG_MTE; 
	strcpy_s(m_plugin_info.name,  32, PLUGIN_NAME_MTE);
	m_int_param.uiInt = 7;
	m_int_param.info = m_plugin_info;
	CHAR szModuleName[MAX_PATH];
	GetModuleFileNameA(theApp.m_hInstance, szModuleName, MAX_PATH);
	PathRemoveExtensionA(szModuleName);
	strcpy_s(m_szCurDllName, MAX_PATH, PathFindFileNameA(szModuleName));
	m_bDisabled = FALSE;
	b_exit_flags = false;
}

CDialogTheme::CDialogTheme(CWnd* pParent /*=NULL*/,
						   void       (*(*w32_mmi_mte_api_cb)(int))            (void))
	: CDialog(CDialogTheme::IDD, pParent)
{
	main_dlg = pParent;
	theme_editor_dlg = NULL;
	w32_mmi_mte_api=w32_mmi_mte_api_cb;
	//{{AFX_DATA_INIT(CDialogTheme)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CDialogTheme::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	//{{AFX_DATA_MAP(CDialogTheme)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_LIST_THEME, m_ListTheme);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogTheme, CDialog)
	//{{AFX_MSG_MAP(CDialogTheme)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDEDIT, OnEdit)
	ON_BN_CLICKED(IDCOPYASNEW, OnCopyasnew)
	ON_BN_CLICKED(IDDELETE, OnDelete)
	ON_BN_CLICKED(IDOUTPUT, OnOutput)
	ON_BN_CLICKED(IDLOADTHEME, OnLoadTheme)
//	ON_BN_CLICKED(IDSAVETHEME, OnSavetheme)
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_MESSAGE(PLUGIN_MSG, OnPluginMessage)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogTheme message handlers
void CDialogTheme::EnableAllButtons(bool flag) 
{

	CButton *pBtn=NULL;
	if( this->GetSafeHwnd() != NULL && ::IsWindow( this->GetSafeHwnd() ) )
	{
		pBtn = (CButton*)GetDlgItem(IDEDIT);
		pBtn->EnableWindow(flag);
		pBtn = (CButton*)GetDlgItem(IDCOPYASNEW);
		pBtn->EnableWindow(flag);
		pBtn = (CButton*)GetDlgItem(IDDELETE);
		pBtn->EnableWindow(flag);
		pBtn = (CButton*)GetDlgItem(IDOUTPUT);
		pBtn->EnableWindow(flag);
		pBtn = (CButton*)GetDlgItem(IDLOADTHEME);
		pBtn->EnableWindow(flag);
		pBtn = (CButton*)GetDlgItem(IDSAVETHEME);
		pBtn->EnableWindow(flag);
		
		this->EnableWindow(flag);
		
		if( flag )
		{
			//GetSystemMenu(FALSE)->RemoveMenu(SC_CLOSE, MF_BYCOMMAND );
			GetSystemMenu(FALSE)->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
		}
		else
		{
			GetSystemMenu(FALSE)->EnableMenuItem(SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED );
		}
		
		this->DrawMenuBar();
	}
}

void CDialogTheme::OnEdit() 
{
	if( *g_pMMIIsGoingToPowerOff )
		return ;
	// TODO: Add your control notification handler code here
	int theme_idx =  m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	if(theme_idx<0)
	{
		main_dlg->EnableWindow(false);
		::MessageShow("Please select one theme to edit.");
		main_dlg->EnableWindow(true);
		
		return;
	}
	//DisableAllBtn
	EnableAllButtons(false); 
	
	g_close_theme_editor = false;
	
	memcpy(&my_theme, m_edit_theme_list[theme_idx], sizeof(MMI_theme));
	mmi_mte_activate_theme(&my_theme,theme_idx);

	wchar_t* welcome_W=NULL;
	welcome_W = (wchar_t*)mmi_mte_get_welcome_string(m_edit_theme_list[theme_idx]);
	if(welcome_W!=NULL&&(*welcome_W!=0))
	{
			MessageBoxW(this->m_hWnd,welcome_W,L"Welcome", MB_OK); 
	}	

//	DisplayTotalSize();  
	theme_editor_dlg = new CDialogThemeEditor(this,this->w32_mmi_mte_api);
	theme_editor_dlg->m_theme_idx =theme_idx;
	theme_editor_dlg->Create(IDD_DIALOG_THEME_EDITOR, this);
	theme_editor_dlg->ShowWindow(SW_SHOW);
	
	m_ListTheme.EnableWindow(false);
}
void CDialogTheme::EnableThemeEditor()
{
	EnableAllButtons(true);
	/*
	CButton *pBtn=NULL;
	pBtn = (CButton*)GetDlgItem(IDEDIT);
	pBtn->EnableWindow(true);*/
}
void CDialogTheme::OnCopyasnew() 
{
	if( *g_pMMIIsGoingToPowerOff )
		return ;
	// TODO: Add your control notification handler code here
	if(m_total_edit_theme_num>=MAX_THEME_NUM)
	{
		CString warnmsg;
		warnmsg.Format("Maximum theme index is %d, could not copy again.",MAX_THEME_NUM);
		main_dlg->EnableWindow(false);
		::MessageShow(warnmsg);
		main_dlg->EnableWindow(true);
		return;
	}
	//int theme_idx =  dlg.theme_dlg->m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	int theme_idx =  m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	if(theme_idx==-1)
	{
		//::AfxMessageBox("Please select one theme to copy.");
		main_dlg->EnableWindow(false);
		::MessageShow("Please select one theme to copy.");
		main_dlg->EnableWindow(true);
		return;
	}
	CDialogThemeIndex dlgThemeIdx(this);
	dlgThemeIdx.DoModal();
	/*
	m_edit_theme_list[m_total_edit_theme_num] = new MMI_theme;
	
	int theme_idx =  m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	
	memcpy(m_edit_theme_list[m_total_edit_theme_num], m_edit_theme_list[theme_idx], sizeof(MMI_theme));
	m_total_edit_theme_num ++;
	*/
	DisplayTotalSize();
}

void CDialogTheme::OnDelete() 
{
	if( *g_pMMIIsGoingToPowerOff )
		return ;
#ifdef MODIS_MTE_UNIT_TEST
    int themeIndex = 1;
#else

   int themeIndex =  m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);

    if (themeIndex < 0)
    {
		main_dlg->EnableWindow(false);
        ::MessageShow("Please select one theme to delete.");
		main_dlg->EnableWindow(true);
        return;
    }

    if(m_ListTheme.GetItemCount()==1)
    {
		main_dlg->EnableWindow(false);
        ::MessageShow("Only one theme, you can not delete.");
		main_dlg->EnableWindow(true);
        return;
    }

 

	CString delmsg;
	char theme_str[512];
	m_ListTheme.GetItemText(themeIndex,1,theme_str,512);
	char theme_idx_char[16];
	m_ListTheme.GetItemText(themeIndex,0,theme_idx_char,16);

	delmsg.Format("Are you sure to delete theme index %s?",theme_idx_char);
    main_dlg->EnableWindow(false);
	if (::MessageBox(this->m_hWnd,delmsg,"MoDIS_UI", MB_YESNO | MB_DEFBUTTON2 ) != IDYES)
    {
		main_dlg->EnableWindow(true);
        return;
    }
	main_dlg->EnableWindow(true);
#endif // MODIS_MTE_UNIT_TEST

    const int itemCount = m_ListTheme.GetItemCount();
    int i;

    for (i=themeIndex; i<itemCount; i++)
    {
        CString themeIndexStr;
        themeIndexStr.Format("%d", i);

        m_ListTheme.SetItemText(i, 0, themeIndexStr);
    }

    m_ListTheme.DeleteItem(themeIndex);

    for (i=themeIndex; i<m_total_edit_theme_num; i++)
    {
        if (i+1 <m_total_edit_theme_num)
        {
            memcpy(m_edit_theme_list[i], m_edit_theme_list[i+1],
                   sizeof(MMI_theme));

            m_mtexmlstr[i] = m_mtexmlstr[i+1];
        }
    }

    m_mtexmlstr[m_total_edit_theme_num-1].Empty();
    delete m_edit_theme_list[m_total_edit_theme_num-1];
    m_edit_theme_list[m_total_edit_theme_num-1] = NULL;
    m_total_edit_theme_num--;
			
	DisplayTotalSize();
}


CString CDialogTheme::FillerCheckSameFiller(int theme_idx,int filler_idx)
{

	//record theme number,+ theme component and length
	//return 
	CString ret="";
	UI_filled_area *pat = GetFillerPtr(m_edit_theme_list[theme_idx],g_UI_filled_area_str[filler_idx]);
	if(pat==NULL) return ret;
	for(int i=0;i<=theme_idx;i++)
	{
		{
			for(int k=0;;k++)
			{
				if(k==filler_idx&&i==theme_idx)
					return ret;
				CString filler_para = g_UI_filled_area_str[k];
				if(filler_para.CompareNoCase("End_Filler")==0) break;
				
				UI_filled_area *dest = GetFillerPtr(m_edit_theme_list[i],filler_para);
				if(dest==NULL) continue;
				if(dest->flags==3)//image
				{
					if(CompareFillerorImage((char *)pat->b,(char *)dest->b))//get match
					{
						if(i==0) ret.Format("img_%s_defaultTheme",filler_para);
						else ret.Format("img_%s_default%dTheme",filler_para,i);	
						return ret;
					}
				}
			}
		}
	}
	return ret;
}
CString CDialogTheme::ImageCheckSameFillerandImage(char *image,int theme_idx,CString member)
{
	CString ret="";
	//check all filler
	int i =0;
	for(i=0;i<m_total_edit_theme_num;i++)
	{
		{
			for(int k=0;;k++)
			{
				
				CString filler_para = g_UI_filled_area_str[k];
				if(filler_para.CompareNoCase("End_Filler")==0) break;
				
				UI_filled_area *dest = GetFillerPtr(m_edit_theme_list[i],filler_para);
				if(dest!=NULL&&dest->flags==3)//image
				{
					if(CompareFillerorImage(image,(char *)dest->b))//get match
					{
						CString theme;//last record theme="Theme"
						if(member.CompareNoCase(m_LastOffsetStrinTheme)==0)
							theme="Theme";
						else theme="Theme,";
						if(i==0) 
							ret.Format("(PU8)img_%s_default%s",filler_para,theme);
						else ret.Format("(PU8)img_%s_default%d%s",filler_para,i,theme);	
						return ret;
					}
				}
			}
		}
	}
	//check image
	for(i=0;i<=theme_idx;i++)
	{
		{
		for(int k=0;;k++)
		{
		
			CString image_para = g_UI_image_str[k];
			if(i==theme_idx&&member.CompareNoCase(image_para)==0)
				return ret;
			if(image_para.CompareNoCase("End_Image")==0) break;
			
			char *dest = (char *)GetImagePtr(m_edit_theme_list[i],image_para);
			if(dest!=NULL)//image
			{
				if(CompareFillerorImage(image,dest))//get match
				{
					CString theme;//last record theme="Theme"
					if(member.CompareNoCase(m_LastOffsetStrinTheme)==0)
						theme="Theme";
					else theme="Theme,";

					if(i==0) ret.Format("(PU8)img_%s_default%s",image_para,theme);
					else ret.Format("(PU8)img_%s_default%d%s",image_para,i,theme);	
					return ret;
				}
			}
		}
		}
	}
	return ret;
}
bool CDialogTheme::CompareFillerorImage(char *pat,char *dest)
{
	int len=mmi_mte_get_image_data_length(pat);
	if(len!=mmi_mte_get_image_data_length(dest))
		return false;
	else
	{
		for(int i=0;i<len;i++)
		{
			if(*(pat+i)!=*(dest+i))
				return false;
		}
	}
	return true;
}


CString CDialogTheme::CodeGenMakeFiller(CString theme_name,CString filler_name, MMI_theme theme,int theme_idx,int filler_idx)
{
	CString ret;
	UI_filled_area *tmp = GetFillerPtr(&theme,filler_name);
	CString filler_type;
	CString imagearray="";
	CString imageid_str = "UI_IMAGE_ID_NULL";
	
	if(tmp==NULL) return imagearray;
	//default is UI_FILLED_AREA_TYPE_COLOR
	filler_type.Format("UI_FILLED_AREA_TYPE_COLOR");
	
	if(tmp->flags==3) //mean image
	{
		filler_type.Format("UI_FILLED_AREA_TYPE_BITMAP");
		CString imagestr;
		imagestr.Format("img_%s%s",filler_name,theme_name);
					
		if(tmp->b!=NULL)
		{
			CString samefiller="";
			samefiller = FillerCheckSameFiller(theme_idx,filler_idx);
			if(samefiller!="")
			{
				imageid_str.Format("(U8*)%s",samefiller);
			}
			else
			{
				imagearray = GenImageToArray(tmp->b, imagestr);
				imageid_str.Format("(U8*)%s",imagestr);
			}
		}
	}	
	else if(tmp->flags & UI_FILLED_AREA_SINGLE_BORDER) 
		filler_type.Format("UI_FILLED_AREA_TYPE_COLOR|UI_FILLED_AREA_SINGLE_BORDER");
    
	ret.Format("CONST_HARDWARE UI_filled_area %s%s={\n \
		%s,\n \
		%s,\n \
		NULL,\n \
		{%d,%d,%d,%d},\n \
		{%d,%d,%d,%d},\n \
		{%d,%d,%d,%d},\n \
		{%d,%d,%d,%d},\n \
		%d};\n",filler_name,theme_name,\
		filler_type,\
		imageid_str,\
		tmp->c.r,tmp->c.g,tmp->c.b,tmp->c.alpha, \
		tmp->ac.r,tmp->ac.g,tmp->ac.b,tmp->ac.alpha, \
		tmp->border_color.r,tmp->border_color.g,tmp->border_color.b,tmp->border_color.alpha, \
		tmp->shadow_color.r,tmp->shadow_color.g,tmp->shadow_color.b,tmp->shadow_color.alpha, \
		tmp->transparent_color);
	CString retstr;
	
	if(imagearray!="")
	{	
		retstr.Format("%s%s",imagearray,ret);
	}
	else
	{
		retstr.Format("%s",ret);
	}
	
	return retstr;
}

CString CDialogTheme::CodeGenMakeColor(CString theme_name,CString color_name, MMI_theme theme)
{
	//CONST_HARDWARE color popup_text_color_defaultTheme={0,0,0,100};
	CString ret;
	color *tmp = GetColorPtr(&theme,color_name);
	ret.Format("CONST_HARDWARE color %s%s={%d,%d,%d,%d};\n",
	color_name,theme_name,tmp->r,tmp->g,tmp->b,tmp->alpha);	
	return ret;
}

CString CDialogTheme::GenImageToArray(unsigned char *ptr,CString name)
{
	
	/*
	__align(4) const U8 img_popup_bkg_image_defaultTheme[]={
	0x01,0x01,0x42,0x00,0x00,0x00,0x00,0x00,
0x42,0x4D,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x28,0x00,
0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,
0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x80,0x00,
0x00,0x00
};*/
	CString ret="";
	int len = mmi_mte_get_image_data_length((char *)ptr);

	CString rawstr="";
	for(int i=0;i<len;i++)
	{
		char data[6];
		if((i+1)<len)
			sprintf(data, "0x%X,", *(ptr+i));
		else
			sprintf(data, "0x%X\n", *(ptr+i));
		CString strdat(data);
		rawstr+= strdat;
		
		if(i>0 && i%15==0) //every 16 character next line
			rawstr+="\n";
	}
	ret.Format("__align(4) const U8 %s[]={\n%s\n};\n", name,rawstr);
	return ret;
}

float CDialogTheme::GetThemeComSize(MMI_theme *mmi_theme, CString member,bool type)
//int CDialogTheme::GetThemeComSize(MMI_theme *mmi_theme, CString member,bool type)
{
//	int size =0;
	float size = 0.00;
	if(type)//true mean image
	{
		char *tmp = (char *)GetImagePtr(mmi_theme, member);
		if(tmp!=NULL)
		{
			size =(float)mmi_mte_get_image_data_length(tmp);
		}
	
	}
	else //mean filler
	{
		UI_filled_area *t = GetFillerPtr(mmi_theme,member);
		if(t!=NULL && t->b!=NULL)
		{
			size = (float)mmi_mte_get_image_data_length((char *)t->b);
		}
			
	}
	return size/1000;
}

CString CDialogTheme::GenImageRet(MMI_theme *mmi_theme, CString member,CString themename,CString strTemp,int theme_idx)
{
	unsigned char *ptr;
	
	ptr = GetImagePtr(mmi_theme,member);
	
	
	if(ptr!=NULL)
	{
					
		CString imagestr;
		imagestr.Format("img_%s%s",member,themename);
		if(member.CompareNoCase(m_LastOffsetStrinTheme)==0)
			strTemp.Format("(PU8)%s",imagestr);//Last Record no mark
		else
			strTemp.Format("(PU8)%s,",imagestr);
		
		CString ret = ImageCheckSameFillerandImage((char*)ptr,theme_idx,member);
		if(ret !="")
		{
			strTemp=ret;
			m_retimage[m_image_count]="";
			m_image_count ++;
		}
		else
		{
			m_retimage[m_image_count]=GenImageToArray(ptr,imagestr);
			m_image_count ++;
		}
	}
	return strTemp;
}

void CDialogTheme::OnOutput() 
{
	if( *g_pMMIIsGoingToPowerOff )
	{
		//return FALSE;
		b_output_sucessful = false;
		return;
	}
	EnableMinimizeButton(false);
	EnableAllButtons(false);


    if(!SaveTheme()) 
    {
		EnableMinimizeButton(true);		
		EnableAllButtons(true);	
		b_output_sucessful = false;
   		return;
		//return FALSE;
    }

    char path[1024];
    char *name;

    if(!::SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))
    {    
		EnableMinimizeButton(true);
		EnableAllButtons(true);	
		m_dlgpro.DestroyWindow();
		b_output_sucessful = false;
   		return;
		//        return FALSE;
    }

    char tempbuf[1024];
    char tcfilename[1024], thfilename[1024];
    char ghfilename[1024], gcfilename[1024];

    ::memset(tempbuf, 0, sizeof(tempbuf));
    ::memset(tcfilename, 0, sizeof(tcfilename));
    ::memset(thfilename, 0, sizeof(thfilename));
    ::memset(ghfilename, 0, sizeof(ghfilename));
    ::memset(gcfilename, 0, sizeof(gcfilename));

    ::strncpy(tempbuf, path, strlen(path)-strlen(name));

    ::sprintf(tcfilename, "%sTC.txt", tempbuf);
    ::sprintf(thfilename, "%sTH.txt", tempbuf);

#ifdef MODIS_MTE_UNIT_TEST
    ::sprintf(gcfilename, "%sThemeRes_ut.c", m_savepath);
    ::sprintf(ghfilename, "%sThemeComponents_ut.h", m_savepath);
#else
    ::sprintf(gcfilename, "%sThemeRes.c", m_savepath);
    ::sprintf(ghfilename, "%sThemeComponents.h", m_savepath);
#endif // MODIS_MTE_UNIT_TEST
	
    font_msg = true;

    // Copy file headers
    ::CopyFile(tcfilename, gcfilename, FALSE);
    ::CopyFile(thfilename, ghfilename, FALSE);

    ::SetFileAttributes(gcfilename, FILE_ATTRIBUTE_NORMAL);
    ::SetFileAttributes(ghfilename, FILE_ATTRIBUTE_NORMAL);

	CString themename;
	int i =0;
	char theme_str[512];
		//start code gen ThemeComponents.h

	//Step2
	if((m_fp1 = fopen(_T(ghfilename), "a+")) == NULL)
	{
			::MessageShow("Can't create file.");
			EnableMinimizeButton(true);
			EnableAllButtons(true);			
			m_dlgpro.DestroyWindow();
			b_output_sucessful = false;
   		return;
		//			return FALSE;
	}	
	fprintf(m_fp1,"\n\n");
	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{
		PeekAndPumpMessage();		
		if(i==0) themename.Format("_defaultTheme");
		else themename.Format("_default%dTheme",i);	
		CString tmp;
		int k=0;
		for(k=0;;k++)
		{
			PeekAndPumpMessage();				
			CString filler_para = g_UI_filled_area_str[k];
			if(filler_para.CompareNoCase("End_Filler")==0) break;
			
			tmp = CodeGenMakeFiller(themename,filler_para,*(m_edit_theme_list[i]),i,k);
			fprintf(m_fp1,"%s\n",tmp);
			
		}
		
		for(k=0;;k++)
		{
			PeekAndPumpMessage();				
			CString color_para = g_color_str[k];
			
			if(color_para.CompareNoCase("End_Color")==0) break;
			tmp = CodeGenMakeColor(themename,color_para,*(m_edit_theme_list[i]));
			fprintf(m_fp1,"%s\n",tmp);	
		
		}

        for (k=0; ; k++)
        {
			PeekAndPumpMessage();				        
            if (g_font_str[k].CompareNoCase(END_FONT) == 0)
            {
                break;
            }

            CString fontStr = FindDuplicateFont(i, k);

            if (fontStr.IsEmpty())
            {
                fprintf(m_fp1, "%s\n",
                    GenerateFontStructure(m_edit_theme_list[i], g_font_str[k], themename));
            }
        }
        
	}
	fclose(m_fp1);
	
	//Step3 start to cogen .c
	if((m_fp1 = fopen(_T(gcfilename), "a+")) == NULL)
	{
			::MessageShow("Can't create file.");
			EnableMinimizeButton(true);
			EnableAllButtons(true);		
			m_dlgpro.DestroyWindow();
			b_output_sucessful = false;
   		return;
		//			return FALSE;
	}	

	fprintf(m_fp1,"\n\n#define MAX_MMI_THEMES %d\n",m_total_edit_theme_num);
	
	fprintf(m_fp1,"#if defined(__MMI_THEME_MAX_NUMBER__)\n");
    fprintf(m_fp1,"    #if (MAX_MMI_THEMES > __MMI_THEME_MAX_NUMBER__)\n");
    fprintf(m_fp1,"      #undef MAX_MMI_THEMES\n");
    fprintf(m_fp1,"      #define MAX_MMI_THEMES __MMI_THEME_MAX_NUMBER__\n");
    fprintf(m_fp1,"    #endif\n");
	fprintf(m_fp1,"#endif\n");
	
	
	fprintf(m_fp1,"\nconst S32 mtk_n_themes=MAX_MMI_THEMES;\n");

	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{
		m_dlgpro.m_Progress.SetPos((i+1)*2+m_ListTheme.GetItemCount()*2);
		PeekAndPumpMessage();	
		int j=0;
		memset(theme_str, 0, sizeof(theme_str));
		m_ListTheme.GetItemText(i,1,theme_str,512);
		//theme_str mean real theme name
	  
		CString   strTemp;   
	   
		
		if(i==0) themename.Format("_defaultTheme");
		else themename.Format("_default%dTheme",i);
	
		strTemp.Format("const MMI_theme theme%s={",themename);
		fprintf(m_fp1,strTemp+"\n");

		
		int line_count =0;
		//for(j=0;j<16;j++)
		for(j=0;j<THEME_COM_NUM;j++)
			m_retimage[j]="";
		m_image_count =0;

		//Wayne Update; 071023
		mmi_mte_theme_component_struct *the_component;
		CString mark="";
		
		if(m_loadmte)
		{
			if(m_xmlnode.Load(m_mtexmlstr[i])== NULL )
			{
				::MessageShow(_T("Error."));
				EnableMinimizeButton(true);
				EnableAllButtons(true); 		
				m_dlgpro.DestroyWindow();
				b_output_sucessful = false;
	   		return;
		//			return FALSE;
			}
		}
		for(int theMemOffset=0;theMemOffset<mmi_mte_get_theme_component_num();theMemOffset++)
		{
			PeekAndPumpMessage();				
			the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(g_MapTheMemtoTheID[theMemOffset]);
			//Code gen Mark;
			if(m_LastOffsetStrinTheme.CompareNoCase(the_component->name)==0)
				mark="";
			else
				mark=",";
			strTemp.Format("/*%s*/",the_component->name);
			fprintf(m_fp1,strTemp+"\n");
			
			if(the_component->type==MMI_MTE_THEME_DATA_TYPE_COLOR||the_component->type==MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR)
			{
				color **old_color = (color**) mmi_mte_translate_theme_component_data_pointer(the_component, m_edit_theme_list[i]);
				
				strTemp.Format("(color*)&%s%s%s",the_component->name,themename,mark);
				fprintf(m_fp1,strTemp+"\n");
			}
			else if(the_component->type==MMI_MTE_THEME_DATA_TYPE_FONT)
			{
                for (int fontIndex=0; ; fontIndex++)
                {
					PeekAndPumpMessage();	               
                    ASSERT(g_font_str[fontIndex].CompareNoCase(END_FONT) != 0);

                    if (g_font_str[fontIndex].CompareNoCase(the_component->name) == 0)
                    {
                        CString fontStr = FindDuplicateFont(i, fontIndex);

                        if (fontStr.IsEmpty())
                        {
                            if (i == 0)
                            {
                                fprintf(m_fp1,
                                        "(UI_font_type)&%s_defaultTheme%s\n",
                                        g_font_str[fontIndex], mark);
                            }
                            else
                            {
                                fprintf(m_fp1,
                                        "(UI_font_type)&%s_default%dTheme%s\n",
                                        g_font_str[fontIndex], i, mark);
                            }
                        }
                        else
                        {
                            fprintf(m_fp1, "(UI_font_type)&%s%s\n", fontStr, mark);
                        }
                        break;
                    }
                }
			}
			else if(the_component->type==MMI_MTE_THEME_DATA_TYPE_FILLER)
			{
				UI_filled_area **old_filler = (UI_filled_area**) mmi_mte_translate_theme_component_data_pointer(the_component, m_edit_theme_list[i]);
				if(*old_filler==NULL)
				{
					strTemp.Format("NULL%s",mark);
					fprintf(m_fp1,strTemp+"\n");
				}
				else
				{
					strTemp.Format("(UI_filled_area*)&%s%s%s",the_component->name,themename,mark);
					fprintf(m_fp1,strTemp+"\n");
				}
			}

			else if(the_component->type==MMI_MTE_THEME_DATA_TYPE_IMAGE)
			{
				strTemp.Format("NULL%s",mark);
				unsigned char **image = (unsigned char **) mmi_mte_translate_theme_component_data_pointer(the_component,m_edit_theme_list[i]);
				strTemp = GenImageRet(m_edit_theme_list[i],the_component->name,themename,strTemp,i);
				fprintf(m_fp1,strTemp+"\n");
			}
			else if(the_component->type==MMI_MTE_THEME_DATA_TYPE_INTEGER)
			{
				int *intcom = (int *) mmi_mte_translate_theme_component_data_pointer(the_component,m_edit_theme_list[i]);
				strTemp.Format("%d%s",*intcom,mark);
				fprintf(m_fp1,strTemp+"\n");
			}	
			else if(the_component->type==MMI_MTE_THEME_DATA_TYPE_SYMBOL)
			{
				int *intcom = (int *) mmi_mte_translate_theme_component_data_pointer(the_component,m_edit_theme_list[i]);
				strTemp.Format("%d%s",*intcom,mark);
				fprintf(m_fp1,strTemp+"\n");
			}

			if(m_LastOffsetStrinTheme.CompareNoCase(the_component->name)==0)
			  fprintf(m_fp1,"};");
		}
		fprintf(m_fp1,"\n\n");
	
		
		//The following code is to cogen image aray in themecompoent.h
		FILE *fp2;
		if((fp2 = fopen(_T(ghfilename), "a+")) == NULL)
		{
			::MessageShow("Can't create file.");
			EnableMinimizeButton(true);
			EnableAllButtons(true);		
			m_dlgpro.DestroyWindow();
			b_output_sucessful = false;
	   		return;
		//		return FALSE;
		}	
	//	for(j=0;j<16;j++)
		for(j=0;j<THEME_COM_NUM;j++)
		{
			if(m_retimage[j]!="")
			{
				//cogen ret image in .hfile, becasue .c include retimage;	
				fprintf(fp2,m_retimage[j]);	
			}
		}
		fclose(fp2);
		
		
	
	}
	
	fprintf(m_fp1,"#ifndef __MMI_THEMES_V2_SUPPORT__\n");

	fprintf(m_fp1,"const MMI_theme* const mtk_MMI_themes[MAX_MMI_THEMES]={\n");
	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{
		PeekAndPumpMessage();					
		if(i==0) themename.Format("_defaultTheme");
		else themename.Format("_default%dTheme",i);
		CString optstr;
		optstr.Format("#if (MAX_MMI_THEMES >= %d)\n",i+1);
		fprintf(m_fp1,optstr);
		if((i+1)<m_ListTheme.GetItemCount())
			fprintf(m_fp1,"(MMI_theme *)&theme%s,\n",themename);
		else
			fprintf(m_fp1,"(MMI_theme *)&theme%s\n",themename);
		fprintf(m_fp1,"#endif\n");

	}
	fprintf(m_fp1,"};\n");

	fprintf(m_fp1,"#else\n");

	fprintf(m_fp1,"const theme_details_struct mtk_MMI_themes[MAX_MMI_THEMES]={\n");
	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{
		PeekAndPumpMessage();	
		CString optstr;
		optstr.Format("#if (MAX_MMI_THEMES >= %d)\n",i+1);
		fprintf(m_fp1,optstr);	
		if(i==0) themename.Format("_defaultTheme");
		else themename.Format("_default%dTheme",i);
		fprintf(m_fp1,"{\n");
		fprintf(m_fp1,"(MMI_theme *)&theme%s,\n",themename);
		fprintf(m_fp1,"NULL,\n");
		fprintf(m_fp1,"NULL\n");
		if((i+1)<m_ListTheme.GetItemCount())
			fprintf(m_fp1,"},\n");
		else
			fprintf(m_fp1,"}\n");
		fprintf(m_fp1,"#endif\n");
	}
	fprintf(m_fp1,"};\n");
	fprintf(m_fp1,"#endif\n");

/*    
	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{	
		memset(theme_str, 0, sizeof(theme_str));
		m_ListTheme.GetItemText(i,1,theme_str,512);
		fprintf(m_fp1,"const char theme_%d_name[]=%c%s%c;\n",i,'"',theme_str,'"');
	}

	fprintf(m_fp1,"U8* MMI_theme_names[MAX_MMI_THEMES]={\n");
	
	for(i=0;i<m_ListTheme.GetItemCount();i++)
	{	
		CString optstr;
		optstr.Format("#if (MAX_MMI_THEMES >= %d)\n",i+1);
		fprintf(m_fp1,optstr);

		if((i+1)<m_ListTheme.GetItemCount())
			fprintf(m_fp1,"(U8*)theme_%d_name,\n",i);
		else
			fprintf(m_fp1,"(U8*)theme_%d_name\n",i);
		
		fprintf(m_fp1,"#endif\n");
	}
	fprintf(m_fp1,"};\n");
*/

	fprintf(m_fp1,"const char theme_phone_model[]=%cPluto%c;\n\n",'"','"');

    fprintf(m_fp1, "#ifdef __MTK_TARGET__\n");
    fprintf(m_fp1, "#pragma arm section rodata = \"RESOURCE_1ST_CONTENT\"\n");
    fprintf(m_fp1, "#endif\n\n");
    fprintf(m_fp1, "#ifdef __MMI_THEMES_V2_SUPPORT__\n");
    fprintf(m_fp1, "const CUSTPACK_THEME_HEADER mtk_theme_header =\n");
    fprintf(m_fp1, "{\n");
    fprintf(m_fp1, "    MAX_MMI_THEMES,\n");
    fprintf(m_fp1, "    (theme_details_struct *) mtk_MMI_themes,\n");
    fprintf(m_fp1, "    (char*) theme_phone_model\n");
    fprintf(m_fp1, "};\n");
    fprintf(m_fp1, "#else\n");
    fprintf(m_fp1, "const CUSTPACK_THEME_HEADER mtk_theme_header =\n");
    fprintf(m_fp1, "{\n");
    fprintf(m_fp1, "    MAX_MMI_THEMES,\n");
    fprintf(m_fp1, "    (MMI_theme **) mtk_MMI_themes,\n");
    fprintf(m_fp1, "    (char*) theme_phone_model\n");
    fprintf(m_fp1, "};\n");
    fprintf(m_fp1, "#endif\n\n");
    fprintf(m_fp1, "#ifdef __MTK_TARGET__\n");
    fprintf(m_fp1, "#pragma arm section rodata\n");
    fprintf(m_fp1, "#endif\n");

	fclose(m_fp1);	//Finish CodeGen ThemeRes.c
	

	m_dlgpro.DestroyWindow();

#ifndef MODIS_MTE_UNIT_TEST
	::MessageShow("Code gen and saving done.");
#endif // MODIS_MTE_UNIT_TEST
	
	EnableMinimizeButton(true);
	EnableAllButtons(true); 
	g_notsaved_theme = false;
   		return;
		//	return TRUE;
}

CString CDialogTheme::FindDuplicateFont(int themeIndex, int fontIndex)
{
    UI_font_type font = GetFontPtr(m_edit_theme_list[themeIndex],
                                   g_font_str[fontIndex]);

    for (int i=0; i<=themeIndex; i++)
    {
        for (int j=0; ; j++)
        {
			PeekAndPumpMessage();		        
            if (g_font_str[j].CompareNoCase(END_FONT) == 0)
            {
                break;
            }

            if (i == themeIndex && j == fontIndex)
            {
                // Not found
                return CString();
            }

            UI_font_type anotherFont = GetFontPtr(m_edit_theme_list[i],
                                                  g_font_str[j]);

            if (::memcmp(font, anotherFont, sizeof(stFontAttribute)) == 0)
            {
                // Found
                CString str;

                if (i == 0)
                {
                    str.Format("%s_defaultTheme", g_font_str[j]);
                }
                else
                {
                    str.Format("%s_default%dTheme", g_font_str[j], i);
                }

                return str;
            }
        }
    }

    // Not found
    return CString();
}

CString CDialogTheme::GenerateFontStructure(const MMI_theme *theme,
                                            const CString &fontName,
                                            const CString &themeName)
{
    // CONST_HARDWARE stFontAttribute font_name_theme_name =
    // {
    //     bold, italic, underline, size, color, type, oblique, smalleCaps
    // };
    //
    static const CString format("CONST_HARDWARE stFontAttribute %s%s =\n{\n    %u, %u, %u, %u, %u, %u, %u, %u\n};\n");

    CString str;
    UI_font_type font = GetFontPtr(theme, fontName);

    if (font == NULL)
    {
        str.Format(format, fontName, themeName, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    else
    {
        str.Format(format,
                   fontName, themeName,
                   font->bold, font->italic, font->underline, font->size,
                   font->color, font->type, font->oblique, font->smallCaps);
    }

    return str;
}

void CDialogTheme::OnLoadTheme() 
{
	if( *g_pMMIIsGoingToPowerOff )
		return ;
	EnableMinimizeButton(false);
	EnableAllButtons(false);
#ifdef MODIS_MTE_UNIT_TEST
    const CString themeFilename(PREPEND_UNIT_TEST_DIRECTORY("Theme_ut.mte"));
#else

//    if (::MessageShow("It will delete all on going editing theme(s), sure?", MB_YESNO | MB_DEFBUTTON2) != IDYES)
	if (::MessageBox(this->m_hWnd,"It will delete all on going editing theme(s), sure?","MoDIS_UI", MB_YESNO | MB_DEFBUTTON2 ) != IDYES)
    {
    	EnableMinimizeButton(true);
		EnableAllButtons(true);
        return;
    }

    //CFileDialog fileOpenDialog(
    //        TRUE, _T(".mte"), NULL,
    //        OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR,
    //        _T("All files (.mte)|*.mte|"));
    //if (fileOpenDialog.DoModal() != IDOK)
    //{
	    //EnableMinimizeButton(true);
        //return;	
    //}
    //const CString themeFilename(fileOpenDialog.GetPathName());

	//Use GetOpenFileNameW for unicode file name
	OPENFILENAMEW ofn;       
	WCHAR szFile[MAX_PATH]; 
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = L'\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"MTE files (.mte)\0*.mte\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrDefExt	= L".mte";
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
	if ( !GetOpenFileNameW(&ofn) )
	{
		EnableMinimizeButton(true);
		EnableAllButtons(true);
		return;
	}
	USES_CONVERSION ;	
	CString themeFilenameCString( W2A(szFile) );
	std::wstring themeFilenameW( szFile );
#endif // MODIS_MTE_UNIT_TEST

    if (m_xmlallnodes.Load(ReadFileW(themeFilenameW)) == NULL)
    {
        ::MessageShow(_T("Failed to load .mte into XML nodes."));
		EnableMinimizeButton(true);
		EnableAllButtons(true);
        return;
    }
    
    if (!CheckThemeVersion())
    {
        ::MessageShow(_T("Incorrect version information."));
		EnableMinimizeButton(true);
		EnableAllButtons(true);
        return;
    }
    CDialogProcess dlgpro;
    dlgpro.Create(IDD_DIALOG_PROCESS);
    dlgpro.SetWindowText( "Loading...");
    dlgpro.ShowWindow(SW_SHOW);
    dlgpro.m_Progress.SetRange32(0, m_xmlallnodes.GetChildCount()*2);
    dlgpro.m_Progress.SetStep(1);
    dlgpro.m_Progress.SetPos(1);

    /* prompt the warning or error popup to notify the XML branch is different to MTE */
    int xml_major_ver;
    int mte_major_ver, mte_minor_ver;

    mmi_mte_get_theme_schema_version(&mte_major_ver, &mte_minor_ver);
    
    xml_major_ver = XStr2Int(m_xmlallnodes.GetAttrValue(_T("Major")));

    if (xml_major_ver > mte_major_ver)
    {
        ::MessageShow(_T("Cannot load the newer version MTE file."));
		EnableMinimizeButton(true);
		EnableAllButtons(true);
		dlgpro.DestroyWindow();
        return;				
    }

    if (xml_major_ver < mte_major_ver)
    {
        ::MessageShow(_T("Warning: Loading an older version MTE file."));
    }			

    //Bug fix here to while activate editing theme is free, so first activate system theme
	
    mmi_mte_activate_theme((MMI_theme *)m_system_theme_list[0],0);
	
    for(int ii = 0; ii<m_total_edit_theme_num;ii++)
    {	
	    PeekAndPumpMessage();
        if(m_edit_theme_list[ii])
        {
            delete m_edit_theme_list[ii];
            m_edit_theme_list[ii] = NULL;
        }
        for(int pp = 0; pp<MAX_THEME_COM_NUM;pp++)
        {
            save_modify_flag[ii][pp]=0;
            history_modify_flag[ii][pp]=0;
        }
    }

    main_dlg->EnableWindow(false);
    m_ListTheme.DeleteAllItems();


    
    m_total_edit_theme_num =0;
    for( int i=0;i<m_xmlallnodes.GetChildCount();i++)
    {
    	PeekAndPumpMessage();
        m_total_edit_theme_num++;
        dlgpro.m_Progress.SetPos(i*2+1);
        //MMI_theme *load_theme =new MMI_theme;
        m_edit_theme_list[i] =new MMI_theme;

        // Copy default theme settings into the newly created theme
        memcpy(m_edit_theme_list[i], m_system_theme_list[0], sizeof(MMI_theme));

        LPXNode tmp = m_xmlallnodes.GetChild(i);
        CString xmlstrnode = tmp->GetXML();//tmp->GetChildText("Theme");//tmp->GetText();
        m_mtexmlstr[i] = xmlstrnode;
        if(m_xmlnode.Load(xmlstrnode)== NULL )
        {
            ::MessageShow(_T("Error."));
			EnableMinimizeButton(true);
			EnableAllButtons(true);
			dlgpro.DestroyWindow();
            return;
        }
		PeekAndPumpMessage();

        CString modstr = m_xmlnode.GetChildAttrValue(_T("Modified_Flag"),_T("value") );
        if(modstr!="")
        {
            GetModifyFlagComByStr(modstr,i);
        }

        /* set the default theme for later XML loading */
        if (i >= m_total_system_theme_num)
        {	/* too many themes in XML, use the first system theme... */
            // TODO: maybe this behavior is not good?
            m_DefaultSystemTheme = (MMI_theme*)m_system_theme_list[0];
        }				
        else
        {	/* one to one if possible */
            m_DefaultSystemTheme = (MMI_theme*)m_system_theme_list[i];
        }					
        
        LoadThemeComponents(m_edit_theme_list[i]);
    	PeekAndPumpMessage();
    
        //the following is to display all theme list
        CString nid;
        nid.Format("%d",i+1);
        m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, i,nid,0, LVIS_SELECTED,0, 0);

        CString theme_name;
        theme_name = m_xmlnode.GetAttrValue("Name");
    
        m_ListTheme.SetItemText(i,1,GetStrFromThemeNameVal(theme_name));
        dlgpro.m_Progress.SetPos(i*2+2);
    }

    dlgpro.DestroyWindow();

#ifndef MODIS_MTE_UNIT_TEST
    ::MessageShow("Loading done.");
#endif // MODIS_MTE_UNIT_TEST

    EnableAllButtons(true);
	EnableMinimizeButton(true);
    DisplayTotalSize();
	
    mmi_mte_activate_theme(m_edit_theme_list[0],0);
    m_loadmte= true;
}

bool CDialogTheme::SaveTheme() 
{
#ifdef MODIS_MTE_UNIT_TEST
    const CString themeFilename(PREPEND_UNIT_TEST_DIRECTORY("Theme_ut.mte"));
#else
   	//Use GetOpenFileNameW for unicode file name
	OPENFILENAMEW ofn;       
	WCHAR szFile[MAX_PATH]; 
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = L'\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"MTE files (.mte)\0*.mte\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrDefExt	= L".mte";
	ofn.Flags = OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_OVERWRITEPROMPT;
	if ( !GetSaveFileNameW(&ofn) )
	{
		return false;	
	}
	USES_CONVERSION ;	
	CString themeFilenameCString( W2A(szFile) );
	std::wstring themeFilenameW( szFile ) ;
#endif // MODIS_MTE_UNIT_TEST

    if (themeFilenameW.empty())
    {
        return false;
    }

    m_savepath = themeFilenameCString.Left(themeFilenameCString.ReverseFind('\\') + 1);

    FILE *file;

    if ((file = _wfopen( themeFilenameW.c_str(), L"w+")) == NULL)
    {
        ::MessageShow("Cannot create file for writing .mte.");
        return false;
    }	


    m_dlgpro.Create(IDD_DIALOG_PROCESS);
    m_dlgpro.SetWindowText("Saving... Path: " + m_savepath);
    m_dlgpro.ShowWindow(SW_SHOW);
    m_dlgpro.m_Progress.SetRange32(0, m_total_edit_theme_num*4);
    m_dlgpro.m_Progress.SetStep(1);
    m_dlgpro.m_Progress.SetPos(1);
	
    m_image_link =0;

    int majorVersionNum = 0;
    int minorVersionNum = 0;
    const char *branchName;
    branchName= mmi_mte_get_theme_schema_version(&majorVersionNum,
                                                  &minorVersionNum);

    fprintf(file,
            "<ThemeXML Version='%s' Branch_Name='%s' Major='%d' Minor='%d'>\n",
            /*dlg.m_version*/m_strVersion, branchName, majorVersionNum, minorVersionNum);

    for (int i=0; i<m_total_edit_theme_num; i++)
    {
        m_dlgpro.m_Progress.SetPos(i*2 + 1);
		PeekAndPumpMessage();	

        char theme_str[512];
        m_ListTheme.GetItemText(i, 1, theme_str, 512);

        fprintf(file, "%s",
                ConvertThemeToXML(m_edit_theme_list[i], theme_str, i));

        m_dlgpro.m_Progress.SetPos((i+1) * 2);
    }

    fprintf(file, "</ThemeXML>\n");
    fclose(file);
    return true;
}

UINT CDialogTheme::InitPlugin()
{
	mte_data_struct data;

	/*If MTE disabled?*/
	ZeroMemory(&data, sizeof(data));
	RunCmd(GetParent()->GetSafeHwnd(), MTE_CMD_IS_DISABLED, data, (void*)(&m_int_param));
	ASSERT(MTE_CMD_IS_DISABLED == data.cmd);
	if(MTE_CMD_NONE == data.cmd)
		return 1;
	int nIsDisabled = 0;
	int* pIsDisabledData = (int*)(&data.data);
	nIsDisabled = pIsDisabledData[0];
	if(1 == nIsDisabled)
		return 2;

	/*Get mte api*/
	ZeroMemory(&data, sizeof(data));
	RunCmd(GetParent()->GetSafeHwnd(), MTE_CMD_GET_API, data, (void*)(&m_int_param));
	ASSERT(MTE_CMD_GET_API == data.cmd);
	if(MTE_CMD_NONE == data.cmd)
		return 1;
	typedef void(*(*mmi_mte_api)(int))(void);
	int* pAPIData = (int*)(&data.data);
	w32_mmi_mte_api = (mmi_mte_api)pAPIData[0];
	ASSERT(NULL != w32_mmi_mte_api);
	 
	/*Get Main LCD size*/
	ZeroMemory(&data, sizeof(data));
	RunCmd(GetParent()->GetSafeHwnd(), MTE_CMD_GET_LCD_SIZE, data, (void*)(&m_int_param));
	ASSERT(MTE_CMD_GET_LCD_SIZE == data.cmd);
	if(MTE_CMD_NONE == data.cmd)
		return 1;
	int* pLCDSize = (int*)(&data.data);
	g_MMI_width = pLCDSize[0];
	g_MMI_height = pLCDSize[1];

	/*Get MAUI version*/
	ZeroMemory(&data, sizeof(data));
	RunCmd(GetParent()->GetSafeHwnd(), MTE_CMD_GET_MAUI_VERSION, data, (void*)(&m_int_param));
	ASSERT(MTE_CMD_GET_MAUI_VERSION == data.cmd);
	m_strVersion = CString((char*)data.data);

	/*Get MoDIS MMI Close flag*/
	ZeroMemory(&data, sizeof(data));
	RunCmd(GetParent()->GetSafeHwnd(), MTE_CMD_GET_MMI_CLOSE_FLAG, data, (void*)(&m_int_param));
	ASSERT(MTE_CMD_GET_MMI_CLOSE_FLAG == data.cmd);
	if(MTE_CMD_NONE == data.cmd)
		return 1;
	UINT* pData = (UINT*)(&data.data);
	g_pMMIIsGoingToPowerOff = (UINT*)pData[0];
	g_pMoDISUIClosedByMMI = (UINT*)pData[1];

	// set MTE system variables
	mmi_mte_set_value(MMI_MTE_SYSTEM_VALUE_CONVERT_EXE_PATH, get_convert_exe_full_path());	
	mmi_mte_set_value(MMI_MTE_SYSTEM_VALUE_TEMP_PATH, get_temp_path());	

	return 0;
}

BOOL CDialogTheme::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if(get_convert_exe_full_path() == NULL)
	{
		CString copy_notice;
		copy_notice.Format("Cannot find the ImageMagick convert.exe!\r\n\r\nPlease\r\n1. Install ImageMagick-xxxxxxxx-Q16-windows-static.exe from http://www.imagemagick.org/download/binaries/\r\n2. Copy the convert.exe from the ImageMagick install directory to this folder:\r\n%s", get_modis_exe_path());
		::MessageShow(copy_notice);
		SendMessage(WM_CLOSE);
		return FALSE;		
	}

	UINT uiRlt = InitPlugin();
	switch (uiRlt)
	{
	case 1:
		::MessageShow("MoDIS Theme Editor initialization failed.");
		SendMessage(WM_CLOSE);
		return FALSE;
	case 2:
		m_bDisabled = TRUE;
		::MessageShow("Please don't test MoDIS Theme Editor!\nThis is an internal demo project. MoDIS Theme Editor is only for artist.");
		SendMessage(WM_CLOSE);
		return FALSE;
	}

	::SendMessage(GetParent()->GetSafeHwnd(), PLUGIN_MSG, (WPARAM)PM_OPENED, (LPARAM)m_szCurDllName);
	
	m_loadmte = false;
	for(int ii = 0; ii<MAX_THEME_NUM;ii++)
	{	
		m_mtexmlstr[ii]="";
		m_edit_theme_list[ii] = NULL;
		for(int pp = 0; pp<MAX_THEME_COM_NUM;pp++)
		{
			save_modify_flag[ii][pp]=0;
			history_modify_flag[ii][pp]=0;
		}
	}

	mmi_mte_set_state(MMI_MTE_STATE_ACTIVE);
	g_notsaved_theme = false;
	b_output_sucessful = true;
	// TODO: Add extra initialization here
	ListView_SetExtendedListViewStyle(m_ListTheme.m_hWnd, /*LVS_EX_CHECKBOXES|*/ LVS_EX_FULLROWSELECT |LVS_EX_GRIDLINES);
	m_ListTheme.InsertColumn(0, _T("Index"), LVCFMT_LEFT, 50);
	m_ListTheme.InsertColumn(1, _T("Theme"), LVCFMT_LEFT, 260);
	m_total_system_theme_size =0;
	const char *theme_name_list[MAX_THEME_NUM];
	m_total_system_theme_num = mmi_mte_get_system_theme_data(MAX_THEME_NUM, m_system_theme_list, theme_name_list);
	m_total_edit_theme_num = m_total_system_theme_num;
	InitialSpecificTheCom();
	for(int i=0;i<m_total_edit_theme_num;i++)
	{
		//m_ListTheme.SetTextColor(RGB(i*50,i*50,i*50)); 
		m_edit_theme_list[i] = new MMI_theme;
		memcpy(m_edit_theme_list[i], m_system_theme_list[i], sizeof(MMI_theme));
   

		CString nid;
		nid.Format("%d",i+1);
		m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, i,nid,0, LVIS_SELECTED,0, 0);
		
		CString theme_name;
		theme_name.Format("%s",theme_name_list[i]);
		
		if(theme_name.CompareNoCase("(null)")==0)//mean theme_name_list[i] is null
		{
			theme_name.Format("Theme%d",i+1);
		}
		m_ListTheme.SetItemText(i,1,theme_name);
	}
	DisplayTotalSize();
	UpdatePosition();
	
	char path[1024],tempbuf[1024],hide_theme[20],theme_lan[32];
	char *name;
	memset(tempbuf, 0, sizeof(tempbuf));
	memset(hide_theme, 0, sizeof(hide_theme));
	memset(theme_lan, 0, sizeof(theme_lan));
	
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return false;
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);

	//Get Theme hide theme test
	GetPrivateProfileString("INTEGRATE", "HIDE_THEME", "DEFAULT", hide_theme, sizeof(hide_theme), path);
	CString HideTheme(hide_theme);
	if(HideTheme.CompareNoCase("TRUE")==0)
	{
		g_hidetheme = true;
	}
	else
	{
		g_hidetheme = false;	
	}

	//Get Theme Language
	GetPrivateProfileString("INTEGRATE", "THEME_LANGUAGE", "DEFAULT", theme_lan, sizeof(theme_lan), path);
	CString ThemeLan(theme_lan);
	if(ThemeLan.CompareNoCase("English")==0)
	{
		g_Theme_Lan = 0;
	}
	else if(ThemeLan.CompareNoCase("Simplified Chinese")==0)
	{
		g_Theme_Lan = 1;	
	}	
		//Set Language Setting
	//CMenu *mmenu = GetMenu();
	//CMenu *pMenu = mmenu->GetSubMenu(0);
	if(g_Theme_Lan==0)
	{
		mmi_mte_set_language(ENGLISH);
		//pMenu->CheckMenuItem(ID_MENU_ENGLISH, MF_CHECKED);
		
	}
	else if(g_Theme_Lan==1)
	{
		mmi_mte_set_language(SIM_CHINESE);
		//pMenu->CheckMenuItem(ID_MENU_SIMCHINESE, MF_CHECKED);
	}
#ifdef MODIS_MTE_UNIT_TEST
    RunUnitTest();
#endif // MODIS_MTE_UNIT_TEST
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	
}
void CDialogTheme::DisplayTotalSize()
{
	
	m_total_system_theme_size = CountTotalThemeSize();
	CString themesize_str;
	themesize_str.Format("Total size of theme(s): %d KB",m_total_system_theme_size);
	GetDlgItem(IDC_STATIC_SIZE)->SetWindowText(themesize_str);
	
}
int CDialogTheme::CountTotalThemeSize()
{
	int ret = 0;
	int k=0;
	for(int i=0;i<m_total_edit_theme_num;i++)
	{
		//every theme +2 KB for other theme component
		ret+=2;
		for(k=0;;k++)
		{
			CString filler_para = g_UI_filled_area_str[k];
			if(filler_para.CompareNoCase("End_Filler")==0) break;
			ret += (int)GetThemeComSize(m_edit_theme_list[i],filler_para,false);
		}
		for(k=0;;k++)
		{
			CString image_para = g_UI_image_str[k];
			if(image_para.CompareNoCase("End_Image")==0) break;
			ret += (int)GetThemeComSize(m_edit_theme_list[i],image_para,true);
		}
	}
	return ret;
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
void CDialogTheme::UpdatePosition()
{
	RECT		window_info, dlg_window_info;

	/* shift the dialog to be align with the main windows */
	this->GetWindowRect(&dlg_window_info);
	main_dlg->GetWindowRect(&window_info);
	MoveWindow(window_info.right, window_info.top, dlg_window_info.right - dlg_window_info.left + 0, dlg_window_info.bottom - dlg_window_info.top + 0, TRUE);
	if (NULL != theme_editor_dlg)
	{
		theme_editor_dlg->UpdatePosition();
	}
} /* end of UpdatePosition */

void CDialogTheme::SetParent(CWnd* pParent /*=NULL*/)
{
	main_dlg = pParent;
}

void CDialogTheme::OnClose()
{
	b_exit_flags = true;

	if(!m_bDisabled)
	{
	if(g_notsaved_theme)
	{
		main_dlg->EnableWindow( FALSE );
      	int ans = ::MessageBox(this->m_hWnd,"Output your changed themes?","MoDIS_UI", MB_YESNOCANCEL  | MB_DEFBUTTON3);
		if(IDYES == ans)
		{
			
			main_dlg->EnableWindow( TRUE );
			OnOutput();
			if (!b_output_sucessful)
				return;
		}
		else if( IDCANCEL == ans )
		{
			main_dlg->EnableWindow( TRUE );
			return ;
		}
		main_dlg->EnableWindow( TRUE );
		g_notsaved_theme = false; //whil ui dlg close, never pop up ask to save
	}
	if(theme_editor_dlg!=NULL && ::IsWindow(theme_editor_dlg->GetSafeHwnd()) )
	{
		theme_editor_dlg->CloseAllChildWindowOfMTE();
		theme_editor_dlg->SendMessage(WM_CLOSE);
		//theme_editor_dlg->SendMessage(WM_DESTROY);
		//theme_editor_dlg->EndDialog(1);
		delete theme_editor_dlg;
		theme_editor_dlg = NULL;
	}

	if( !(*g_pMoDISUIClosedByMMI))
		mmi_mte_activate_theme((MMI_theme *)m_system_theme_list[0],0);

	mmi_mte_set_state(MMI_MTE_STATE_INACTIVE);
	}

	CDialog::OnClose();

} /* end of SendWMClose */

CString CDialogTheme::MakeUI_font_typeStr(const CString &name,
                                          const CString &type,
                                          UI_font_type font)
{
    static const CString format("<%s com_type='%s' bold='%d' italic='%d' underline='%d' size='%d' color ='%d' type='%d' oblique='%d' smallCaps='%d'/>");

    CString result;

    if (font == NULL)
    {
        result.Format(format, name, type, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    else
    {
        result.Format(format, name, type,
                      font->bold, font->italic, font->underline, font->size,
                      font->color, font->type, font->oblique, font->smallCaps);
    }

	return result;
}
	
CString CDialogTheme::MakeColorStr(CString structname,CString type,color *ptr)
{
	bool b_nullptr = false;
	if(ptr==NULL)//if NULL ptr assign value to be 0
	{
		ptr = new color ;
		ptr->r = 0;
        ptr->g = 0;
		ptr->b = 0;
		ptr->alpha = 0;
		b_nullptr = true;
	}
	
	//<UI_black_color type='color' r='100' g='200' b='222' alpha='100' />
	CString ret;
	ret.Format("<%s com_type='%s' r='%d' g='%d' b='%d' alpha='%d'/>",structname,type,ptr->r,ptr->g,ptr->b,ptr->alpha);
	
	if(b_nullptr)delete ptr;
	return ret;
}

CString CDialogTheme::MakeOtherStr(MMI_theme mmi_theme,int theme_id)
{
	CString ret;
	CString flagstr;
	CString theme_num="";
	for(int i=0;i<MAX_THEME_COM_NUM;i++)
	{
		if(save_modify_flag[theme_id][i])
		{
			CString numstr;
			numstr.Format("%d,",i);
			theme_num+=numstr;
		}
	}
	flagstr.Format("    <Modified_Flag value='%s'/>",theme_num.Mid(0,theme_num.GetLength()-1));
	ret+=flagstr;
	return ret;
}

CString CDialogTheme::MakeUI_imageStr(CString structname,unsigned char *ptr)
{
	CString ret;
	if(ptr==NULL)
	{
		ret.Format("<%s> Len='0' Data='NULL' </%s>",structname,structname);
	}
	else
	{
		int len = mmi_mte_get_image_data_length((char*)ptr);
		unsigned char data;
			CString Content="";
			for(int i=0;i<len;i++)
			{	
				data= *((ptr)+i);
				CString tmp;
			
				tmp.Format("%d,",data);
			
				Content +=tmp;
			}
		ret.Format("<%s Len='%d' Data='%s'></%s>",structname,len,Content,structname);
	
	}
	return ret;

}

CString CDialogTheme::MakeUI_filled_areaStr(CString structname,CString type,UI_filled_area *ptr)
{
	CString ret;
	color *nullcc= NULL;
	
	if(ptr==NULL)
	{
		ret.Format("<%s com_type='%s' flags='%d' b='%d' gc_type='gradient_color' gc_p='%d' gc_n='%d' %s	%s %s %s %s transparent_color_type='UI_transparent_color_type' transparent_color_value='%d'></%s>",
				structname,type,-1,0,//flag ==-1 mean NULL;
				0,0,
				MakeColorAttrStr("gc_c","color",nullcc),
				MakeColorAttrStr("c","color",nullcc),
				MakeColorAttrStr("ac","color",nullcc),
				MakeColorAttrStr("border_color","color",nullcc),
				MakeColorAttrStr("shadow_color","color",nullcc),
				0,structname);

	}
	else
	{
		
		
		CString image_str;
		CString image_link_ctr;
		image_link_ctr.Format("Image_Link%d",m_image_link);
		
		if(ptr->b!=NULL)
		{
			int len = mmi_mte_get_image_data_length((char*)ptr->b);
			unsigned char data;
			CString Content="";
			for(int i=0;i<len;i++)
			{	
				data= *((ptr->b)+i);
				CString tmp;
			
				tmp.Format("%d,",data);
			
				Content +=tmp;
			}
			image_str.Format("<%s Len='%d' Data='%s'></%s>",image_link_ctr,len,Content,image_link_ctr);

			m_image_link++;
		}
			
		ret.Format("<%s com_type='%s' flags='%d' b='%s' gc_type='gradient_color' gc_p='%d' gc_n='%d' %s	%s %s %s %s transparent_color_type='UI_transparent_color_type' transparent_color_value='%d'></%s>",
				structname,type,ptr->flags,(ptr->b==NULL?"NULL":image_link_ctr),
				(ptr->gc==NULL||ptr->gc->p==NULL)?0:*(ptr->gc->p),(ptr->gc==NULL)?0:ptr->gc->n,
				MakeColorAttrStr("gc_c","color",(ptr->gc==NULL||ptr->gc->c==NULL)?nullcc:ptr->gc->c),
				MakeColorAttrStr("c","color",(color *) &(ptr->c)),
				MakeColorAttrStr("ac","color",(color *) &(ptr->ac)),
				MakeColorAttrStr("border_color","color",(color *) &(ptr->border_color)),
				MakeColorAttrStr("shadow_color","color",(color *) &(ptr->shadow_color)),
				ptr->transparent_color,
				structname);
		CString image_ret;
		image_ret.Format("%s\n    %s",ret,image_str);
		if(ptr->b!=NULL)
		{
			return image_ret;
		}
	
	}
	  return ret;
}

CString CDialogTheme::Make_IntegerStr(const MMI_theme *theme)
{
    CString result;

    for (int i=0; ; i++)
    {
        if (g_int_str[i].CompareNoCase(END_INTEGER) == 0)
        {
            break;
        }
        
        int *value = static_cast<int *>(GetComponentAddr(theme, g_int_str[i]));

        CString str;
        str.Format("    <%s com_type='S32' value='%d'/>\n",
                   g_int_str[i], *value);

        result += str;
    }

    return result;
}

CString CDialogTheme::ConvertThemeToXML(const MMI_theme *theme,
                                        const CString &themeName,
                                        int themeID)
{
    CString fillerStr;
    CString colorStr;
    CString fontStr;
    CString imageStr;
    int i;
	
    for(i=0; ; i++)
    {
		PeekAndPumpMessage();	    
        if (g_UI_filled_area_str[i].CompareNoCase(END_FILLER) == 0)
        {
            break;
        }

        fillerStr += "    ";
        fillerStr += MakeUI_filled_areaStr(
                g_UI_filled_area_str[i], _T("UI_filled_area"),
                GetFillerPtr(theme, g_UI_filled_area_str[i])) + "\r\n";
    }
	
    for(i=0; ; i++)
    {
		PeekAndPumpMessage();		    
        if (g_color_str[i].CompareNoCase(END_COLOR) == 0)
        {
            break;
        }

        colorStr += "    ";
        colorStr += MakeColorStr(
                g_color_str[i], _T("color"),
                GetColorPtr(theme, g_color_str[i])) + "\r\n";
    }
	
    if(m_loadmte)
    {
        if(m_xmlnode.Load(m_mtexmlstr[themeID])== NULL )
        {
            ::MessageShow(_T("Load XML theme error."));
        }
    }

    for(i=0; ; i++)
    {
		PeekAndPumpMessage();		    
        if (g_font_str[i].CompareNoCase(END_FONT) == 0)
        {
            break;
        }

        fontStr += "    ";
        fontStr += MakeUI_font_typeStr(
                g_font_str[i], _T("UI_font_type"),
                GetFontPtr(theme, g_font_str[i])) + "\r\n";
    }

    for(i=0; ; i++)
    {
		PeekAndPumpMessage();	    
        if (g_UI_image_str[i].CompareNoCase(END_IMAGE) == 0)
        {
            break;
        }

        imageStr += "    ";
        imageStr += MakeUI_imageStr(
                g_UI_image_str[i],
                GetImagePtr(theme, g_UI_image_str[i])) + "\r\n";
    }

    CString ret;
    ret.Format("  <Theme Name='%s'>\n%s\n%s\n%s\n%s\n%s\n%s\n  </Theme>\n",
               GetThemeNameVal(themeName),
               fillerStr,
               colorStr,
               fontStr,
               imageStr,
               Make_IntegerStr(theme),
               MakeOtherStr(*theme,themeID));

    return ret;
}

CString CDialogTheme::GetThemeNameVal(CString theme_name)
{
	int size = theme_name.GetLength();
	char *theme_name_val = new char[size];
	strcpy(theme_name_val,theme_name);
	CString ret="";
	for(int i=0;i<size;i++)
	{
		CString val;
		if(i==0)
			val.Format("%d",theme_name_val[i]);
		else
			val.Format(",%d",theme_name_val[i]);
		ret+=val; 
	}
	return ret; 
}

void CDialogTheme::GetModifyFlagComByStr(CString theme_name,int theme_id)
{
   int findmark=0;
   int size=0;
   while(findmark!=-1)
   {
	  findmark = theme_name.Find(',',findmark+1);
      if(findmark!=-1) size++;
   }
  
   int findstart = 0;
   int findend = 0;
   for(int i=0;i<=size;i++)
   {
		findend = theme_name.Find(',',findstart);
		if(findend!=-1) 	
		{
			save_modify_flag[theme_id][atoi(theme_name.Mid(findstart,findend-findstart))] = 1;
			findstart = findend+1; 
		}
		else
		{	
			save_modify_flag[theme_id][atoi(theme_name.Mid(findstart,theme_name.GetLength()-findstart))] = 1;
		}

   }


}

CString CDialogTheme::GetStrFromThemeNameVal(CString theme_name)
{
   int findmark=0;
   int size=0;
   while(findmark!=-1)
   {
	  findmark = theme_name.Find(',',findmark+1);
      if(findmark!=-1) size++;
   }
   char *ret= new char[size+2];
   int findstart = 0;
   int findend = 0;
   for(int i=0;i<=size;i++)
   {
		findend = theme_name.Find(',',findstart);
		if(findend!=-1) 	
		{
			ret[i] = atoi(theme_name.Mid(findstart,findend-findstart));
			findstart = findend+1; 
		}
		else
		{	
			ret[i] = atoi(theme_name.Mid(findstart,theme_name.GetLength()-findstart));
		}

   }

   ret[size+1]='\0';
   
   CString ThemeNameStr;
   ThemeNameStr.Format("%s",ret);
   delete ret;	
   return ThemeNameStr;

}

UI_filled_area *CDialogTheme::GetFillerPtr(const MMI_theme *theme,
                                                   const CString &componentName)
{
    UI_filled_area **filler =
        static_cast<UI_filled_area **>(GetComponentAddr(theme, componentName));

    return *filler;
}

color* CDialogTheme::GetColorPtr(const MMI_theme *theme,
                                 const CString &componentName)
{
    color **c = static_cast<color **>(GetComponentAddr(theme, componentName));

    if (*c == NULL)
    {
        *c = new color;
    }

    return *c;
}

UI_font_type CDialogTheme::GetFontPtr(const MMI_theme *theme,
                                      const CString &componentName)
{
    UI_font_type *font =
        static_cast<UI_font_type *>(GetComponentAddr(theme, componentName));

    return *font;
}

unsigned char *CDialogTheme::GetImagePtr(const MMI_theme *theme,
                                         const CString &componentName)
{
    unsigned char **image=
        static_cast<unsigned char **>(GetComponentAddr(theme, componentName));

    return *image;
}

//
// Iterate over all theme components and try to load each component from
// the .mte file.
//
// If a component cannot be found in the .mte file, it will be copied from
// the default system theme.
//
void CDialogTheme::LoadThemeComponents(MMI_theme *theme)
{
    const int numComponents = mmi_mte_get_theme_component_num();
    const int majorVersion = XStr2Int(m_xmlallnodes.GetAttrValue(_T("Major")));
	
    for (int componentID=0; componentID<numComponents; componentID++)
    {
    	PeekAndPumpMessage();
        const mmi_mte_theme_component_struct *component =
                                    mmi_mte_get_theme_component(componentID);

        char *xmlNodeName=
            mmi_mte_map_theme_component_name_to_old_branch(majorVersion,
                                                           component->name);

        switch (component->type)
        {
            case MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR:
                // FALLTHROUGH -- BORDER_COLOR and COLOR are of the same type.
            case MMI_MTE_THEME_DATA_TYPE_COLOR:
                LoadColor(theme, component, xmlNodeName);
                break;

            case MMI_MTE_THEME_DATA_TYPE_FILLER:
                LoadFiller(theme, component, xmlNodeName);
                break;

            case MMI_MTE_THEME_DATA_TYPE_IMAGE:
                LoadImage(theme, component, xmlNodeName);
                break;

            case MMI_MTE_THEME_DATA_TYPE_FONT:
                LoadFont(theme, component, xmlNodeName);
                break;

            case MMI_MTE_THEME_DATA_TYPE_INTEGER:
                LoadInteger(theme, component, xmlNodeName);
                break;

            case MMI_MTE_THEME_DATA_TYPE_SYMBOL:
                break;

            default:
                ::MessageShow(_T("Unexpected theme data type."));
                break;
        }
    }
}

void CDialogTheme::LoadColor(MMI_theme *theme,
                             const mmi_mte_theme_component_struct *component,
                             const CString &xmlNodeName)
{
	color **c = static_cast<color**>(GetComponentAddr(theme, component));
    ASSERT(c != NULL);

    if (m_xmlnode.GetChildValue(_T(xmlNodeName)) != NULL)
    {
        // The comopent is found in the .mte file, load it from there.
        *c = new color;
        ASSERT(*c != NULL);

        (*c)->r     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("r")));
        (*c)->g     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("g")));
        (*c)->b     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("b")));
        (*c)->alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("alpha")));
    }
    else
    {
        // The component is not found in the .mte file, copy the component
        // from the default system theme.
        color **defaultColor =
            static_cast<color **>(GetComponentAddr(m_DefaultSystemTheme,
                                                   component));
        ASSERT(defaultColor != NULL);

        if (*defaultColor != NULL)
        {
            *c = new color;
            ASSERT(*c != NULL);
            **c = **defaultColor;
        }
        else
        {
            *c = NULL;
        }
    }		
}

void CDialogTheme::LoadFiller(MMI_theme *theme,
                              const mmi_mte_theme_component_struct *component,
                              const CString &xmlNodeName)
{
    UI_filled_area **filler =
        static_cast<UI_filled_area **>(GetComponentAddr(theme, component));
    ASSERT(filler != NULL);

    if (m_xmlnode.GetChildValue(_T(xmlNodeName)) != NULL)
    {
        // The comopent is found in the .mte file, load it from there.

        if (XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("flags"))) < 0)
        {
            *filler = NULL;
            return;
        }

        *filler = new UI_filled_area;
        ASSERT(*filler != NULL);

        (*filler)->flags   = XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("flags")));
        (*filler)->c.r     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("c_r")));
        (*filler)->c.g     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("c_g")));
        (*filler)->c.b     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("c_b")));
        (*filler)->c.alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("c_alpha")));
        
        (*filler)->ac.r     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("ac_r")));
        (*filler)->ac.g     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("ac_g")));
        (*filler)->ac.b     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("ac_b")));
        (*filler)->ac.alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("ac_alpha")));
        
        (*filler)->border_color.r     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("border_color_r")));
        (*filler)->border_color.g     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("border_color_g")));
        (*filler)->border_color.b     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("border_color_b")));
        (*filler)->border_color.alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("border_color_alpha")));
        
        (*filler)->shadow_color.r     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("shadow_color_r")));
        (*filler)->shadow_color.g     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("shadow_color_g")));
        (*filler)->shadow_color.b     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("shadow_color_b")));
        (*filler)->shadow_color.alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("shadow_color_alpha")));
    
        LoadFillerMembers(*filler, xmlNodeName);
    }
    else
    {
        // The component is not found in the .mte file, copy the component
        // from the default system theme.
        UI_filled_area **defaultFiller =
            static_cast<UI_filled_area **>(GetComponentAddr(m_DefaultSystemTheme,
                                                            component));
        ASSERT(defaultFiller != NULL); 
        
        if (*defaultFiller == NULL)
        {
            *filler = NULL;
            return;
        }

        *filler = new UI_filled_area;
        ASSERT(*filler != NULL);

        (*filler)->flags             = (*defaultFiller)->flags;
        (*filler)->c                 = (*defaultFiller)->c;
        (*filler)->ac                = (*defaultFiller)->ac;
        (*filler)->border_color      = (*defaultFiller)->border_color;
        (*filler)->shadow_color      = (*defaultFiller)->shadow_color;
        (*filler)->transparent_color = (*defaultFiller)->transparent_color;

        const int imageLength =
            mmi_mte_get_image_data_length(
                    reinterpret_cast<char *>((*defaultFiller)->b));

        // Copy (*filler)->b
        if (imageLength > 0)
        {
            (*filler)->b = new unsigned char[imageLength];
            ASSERT((*filler)->b != NULL);
            ::memcpy((*filler)->b, (*defaultFiller)->b, imageLength);
        }
        else
        {
            (*filler)->b = NULL;
        }

        // Copy (*filler)->gc
        if ((*defaultFiller)->gc != NULL)
        {
            (*filler)->gc = new gradient_color;
            ASSERT((*filler)->gc != NULL);

            // Copy (*filler)->gc->c
            if ((*defaultFiller)->gc->c != NULL)
            {
                (*filler)->gc->c = new color;
                ASSERT((*filler)->gc->c != NULL);
                *((*filler)->gc->c) = *((*defaultFiller)->gc->c);
            }
            else
            {
                (*filler)->gc->c = NULL;
            }

            // Copy (*filler)->gc->p
            if ((*defaultFiller)->gc->p != NULL)
            {
                (*filler)->gc->p = new unsigned char;
                ASSERT((*filler)->gc->p != NULL);
                *((*filler)->gc->p) = *((*defaultFiller)->gc->p);
            }
            else
            {
                (*filler)->gc->p = NULL;
            }

            (*filler)->gc->n = (*defaultFiller)->gc->n;
        }
        else
        {
            (*filler)->gc = NULL;
        }
    }
}

void CDialogTheme::LoadImage(MMI_theme *theme,
                             const mmi_mte_theme_component_struct *component,
                             const CString &xmlNodeName)
{
    unsigned char **image =
        static_cast<unsigned char **>(GetComponentAddr(theme, component));
    ASSERT(image != NULL);

    if (m_xmlnode.GetChildValue(_T(xmlNodeName)) != NULL)
    {
        // The comopent is found in the .mte file, load it from there.

        const int imageLength = XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("Len")));
        const CString imageData(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("Data")));

        if (imageLength <= 0 || imageData.CompareNoCase("NULL") == 0)
        {
            *image = NULL;
            return;
        }

        *image = new unsigned char[imageLength];
        ASSERT(*image != NULL);

        int startIndex=0;

        for (int i=0; i<imageLength; i++)
        {	
            int foundIndex = imageData.Find(_TCHAR(','), startIndex);

            (*image)[i] =
                ::_ttoi(imageData.Mid(startIndex, foundIndex - startIndex));

            startIndex = foundIndex + 1;
        }
    }
    else
    {
        // The component is not found in the .mte file, copy the component
        // from the default system theme.
        unsigned char **defaultImage =
            static_cast<unsigned char **>(GetComponentAddr(m_DefaultSystemTheme,
                                                           component));
        ASSERT(defaultImage != NULL);

        if (*defaultImage == NULL)
        {
            *image = NULL;
            return;
        }

        const int imageLength =
            mmi_mte_get_image_data_length(
                    reinterpret_cast<char *>(*defaultImage));

        if (imageLength > 0)
        {
            *image = new unsigned char[imageLength];
            ASSERT(*image != NULL);
            ::memcpy(*image, *defaultImage, imageLength);
        }
        else
        {
            *image = NULL;
        }
    }
}

void CDialogTheme::LoadFont(MMI_theme *theme,
                            const mmi_mte_theme_component_struct *component,
                            const CString &xmlNodeName)
{
    UI_font_type *font =
        static_cast<UI_font_type *>(GetComponentAddr(theme, component));
    ASSERT(font != NULL);

    if (m_xmlnode.GetChildValue(_T(xmlNodeName)) != NULL)
    {
        // The comopent is found in the .mte file, load it from there.
        *font = new stFontAttribute;
        ASSERT(*font != NULL);

        (*font)->bold      = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("bold")));
        (*font)->italic    = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("italic")));
        (*font)->underline = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("underline")));
        (*font)->size      = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("size")));
        (*font)->color     = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("color")));
        (*font)->type      = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("type")));
        (*font)->oblique   = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("oblique")));
        (*font)->smallCaps = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("smallCaps")));
    }
    else
    {
        // The component is not found in the .mte file, copy the component
        // from the default system theme.
        UI_font_type *defaultFont =
            static_cast<UI_font_type *>(GetComponentAddr(m_DefaultSystemTheme,
                                                         component));
        ASSERT(defaultFont != NULL);

        if (*defaultFont != NULL)
        {
            *font = new stFontAttribute;
            ASSERT(*font != NULL);
            **font = **defaultFont;
        }
        else
        {
            *font = NULL;
        }
    }
}

void CDialogTheme::LoadInteger(MMI_theme *theme,
                               const mmi_mte_theme_component_struct *component,
                               const CString &xmlNodeName)
{
    int *value = static_cast<int *>(GetComponentAddr(theme, component));
    ASSERT(value != NULL);

    if (m_xmlnode.GetChildValue(_T(xmlNodeName)) != NULL)
    {
        // The comopent is found in the .mte file, load it from there.
        *value = XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName,
                                                      _T("value")));
    }
    else
    {
        // The component is not found in the .mte file, copy the component
        // from the default system theme.

        int *defaultValue =
            static_cast<int *>(GetComponentAddr(m_DefaultSystemTheme,
                                                component));
        ASSERT(defaultValue != NULL);

        *value = *defaultValue;
    } 
}

void CDialogTheme::LoadFillerMembers(UI_filled_area *filler,
                                     const CString &xmlNodeName)
{
    const CString imageLink(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("b")));

    if (imageLink.CompareNoCase("NULL") == 0)
    {
        filler->b = NULL;
    }
    else
    {
        const int imageLength = XStr2Int(m_xmlnode.GetChildAttrValue(imageLink, _T("Len")));
        const CString imageData(m_xmlnode.GetChildAttrValue(imageLink, _T("Data")));
        int startIndex = 0;

        filler->b = new unsigned char[imageLength];

        for (int i=0; i<imageLength; i++)
        {	
            int foundIndex = imageData.Find(_TCHAR(','), startIndex);

            filler->b[i] =
                ::_ttoi(imageData.Mid(startIndex, foundIndex - startIndex));

            startIndex = foundIndex + 1;
        }
    }

    filler->transparent_color =
        (UI_transparent_color_type)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("transparent_color_value")));
    filler->gc = new gradient_color;
    filler->gc->c = new color;
    filler->gc->c->r = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_c_r") ));
    filler->gc->c->g = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_c_g") ));
    filler->gc->c->b = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_c_b") ));
    filler->gc->c->alpha = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_c_alpha")));
    filler->gc->p = new unsigned char;
    *(filler->gc->p) = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_p")));
    filler->gc->n = (U8)XStr2Int(m_xmlnode.GetChildAttrValue(xmlNodeName, _T("gc_n")));
}

CString CDialogTheme::MakeColorAttrStr(CString structname,CString type,color *ptr)
{
	bool b_nullptr = false;
	if(ptr==NULL)//if NULL ptr assign value to be 0
	{
		ptr = new color ;
		ptr->r = 0;
        ptr->g = 0;
		ptr->b = 0;
		ptr->alpha = 0;
		b_nullptr = true;
	}
	
	//<UI_black_color type='color' r='100' g='200' b='222' alpha='100' />
	CString ret;
	ret.Format("%s_com_type='%s' %s_r='%d' %s_g='%d' %s_b='%d' %s_alpha='%d'",
		structname,type,structname,ptr->r,structname,ptr->g,structname,ptr->b,structname,ptr->alpha);
	
	if(b_nullptr)delete ptr;
	return ret;
}

int CDialogTheme::GetThemeComID(CString member)
{
	mmi_mte_theme_component_struct *the_component;
	
	for(int i=0;i<mmi_mte_get_theme_component_num();i++)
	{
	//	TRACE("mmi_mte_get_theme_component_num = %d",mmi_mte_get_theme_component_num());
		the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(i);
	
		if(member.CompareNoCase(the_component->name)==0)
			break;
	}
	return the_component->id;
}

void CDialogTheme::InitialSpecificTheCom()
{
	for(int q=0;q<THEME_COM_NUM*3;q++)
		g_MapTheMemtoTheID[q]=0;

	mmi_mte_theme_component_struct *the_component;

	int max_offset =0,max_themeid=0;
	for(int i=0;i<mmi_mte_get_theme_component_num();i++)
	{
	//	TRACE("mmi_mte_get_theme_component_num = %d",mmi_mte_get_theme_component_num());
		the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(i);
		g_MapTheMemtoTheID[the_component->internal_data.mmi_theme_offset/4]=i;
		//Compute Last Record in MMI theme
		if((int)the_component->internal_data.mmi_theme_offset/4>max_offset)
		{
			max_offset =the_component->internal_data.mmi_theme_offset/4;
			max_themeid = i;
		}	
	}
	the_component = ( mmi_mte_theme_component_struct *)mmi_mte_get_theme_component(max_themeid);
	m_LastOffsetStrinTheme = CString(the_component->name);
	InitialTheComArray();

}

void CDialogTheme::InitialTheComArray()
{
    mmi_mte_theme_component_struct *themeComponent;
    int numColors   = 0;
    int numFillers  = 0;
    int numImages   = 0;
    int numFonts    = 0;
    int numIntegers = 0;

    for(int i=0; i<mmi_mte_get_theme_component_num(); i++)
    {
        // TRACE("mmi_mte_get_theme_component_num = %d",
        //      mmi_mte_get_theme_component_num());
        themeComponent = (mmi_mte_theme_component_struct *)
            mmi_mte_get_theme_component(g_MapTheMemtoTheID[i]);

        switch (themeComponent->type)
        {
            case MMI_MTE_THEME_DATA_TYPE_TEXT_BORDER_COLOR:
                // FALLTHROUGH -- BORDER_COLORs are stored with COLORs
            case MMI_MTE_THEME_DATA_TYPE_COLOR:
                g_color_str[numColors++] = themeComponent->name;
                break;

            case MMI_MTE_THEME_DATA_TYPE_FILLER:
                g_UI_filled_area_str[numFillers++] = themeComponent->name;
                break;

            case MMI_MTE_THEME_DATA_TYPE_IMAGE:
                g_UI_image_str[numImages++] = themeComponent->name;
                break;

            case MMI_MTE_THEME_DATA_TYPE_FONT:
                g_font_str[numFonts++] = themeComponent->name;
                break;

            case MMI_MTE_THEME_DATA_TYPE_INTEGER:
                g_int_str[numIntegers++] = themeComponent->name;
                break;

            case MMI_MTE_THEME_DATA_TYPE_SYMBOL:
                break;

            default:
                ::MessageShow(_T("Unexpected theme data type."));
                break;
        }
    }

    g_color_str[numColors] = END_COLOR;
    g_UI_filled_area_str[numFillers] = END_FILLER;
    g_UI_image_str[numImages] = END_IMAGE;
    g_font_str[numFonts] = END_FONT;
    g_int_str[numIntegers] = END_INTEGER;
}

BOOL CDialogTheme::PreTranslateMessage(MSG* pMsg) 
{

	if(pMsg->message==WM_KEYDOWN)
		{
              if(pMsg->wParam==VK_ESCAPE)//disable VK_ESCAPE
                  pMsg->wParam=NULL ;
          } 
	return CDialog::PreTranslateMessage(pMsg);
}

void* CDialogTheme::GetComponentAddr(const MMI_theme *theme,
                            const mmi_mte_theme_component_struct *component)
{
    return mmi_mte_translate_theme_component_data_pointer(
                            component, const_cast<MMI_theme *>(theme));
}

void* CDialogTheme::GetComponentAddr(const MMI_theme *theme,
                                     const CString &componentName)
{
    return mmi_mte_translate_theme_component_data_pointer(
                mmi_mte_get_theme_component(GetThemeComID(componentName)),
                const_cast<MMI_theme *>(theme));
}

CString CDialogTheme::ReadFile(const CString &filename)
{
    CStdioFile file;
    CString result, str;

    file.Open(filename, CFile::modeRead, NULL);

    while(file.ReadString(str))
    {   
        result += (str + "\r\n");
    }   

    file.Close(); 
    return result;
}

CString CDialogTheme::ReadFileW(const std::wstring &filename)
{
    FILE *file;
    if ((file = _wfopen( filename.c_str(), L"r")) == NULL)
    {
		return "";
    }
	//at most 50000 chars per line
	char tmp[ 50000 ];
	CString result, str;
	while( fgets( tmp, 50000, file ) != NULL )
	{
		str = tmp ;
		result += (str);
	//	result += (str + "\r\n");  
	}
	fclose( file ) ;
	return result ;
}
bool CDialogTheme::CheckThemeVersion()
{
    CString themeVersion = m_xmlallnodes.GetAttrValue(_T("Version"));

    if (themeVersion.IsEmpty())
    {
        return false;
    }

    // Compare hardware versions
    CString hardwareVersion = themeVersion.Left(themeVersion.Find(" "));
    CString modisHardwareVersion = /*dlg.m_version*/m_strVersion.Left(/*dlg.m_version*/m_strVersion.Find(" "));

	if( hardwareVersion.CompareNoCase(modisHardwareVersion) != 0 )
		return false ;


    CString ThemeBranchVersion = m_xmlallnodes.GetAttrValue(_T("Branch_Name"));

    if (ThemeBranchVersion.IsEmpty())
    {
        return false;
    }

	//Check Branch Version
	ThemeBranchVersion = ThemeBranchVersion.Right( ThemeBranchVersion.GetLength() - (ThemeBranchVersion.Find(_T('.'))+1));
	ThemeBranchVersion = ThemeBranchVersion.Left( ThemeBranchVersion.Find(_T('.')));
	//Get 08B
	CString project_ver_right = /*dlg.m_version*/m_strVersion.Right( /*dlg.m_version*/m_strVersion.GetLength() - (/*dlg.m_version*/m_strVersion.Find(_T('.'))+1));
	project_ver_right = project_ver_right.Left( project_ver_right.Find(_T('.')));

	if( ThemeBranchVersion != project_ver_right )
		return false ;		

	return true;
}

void CDialogTheme::EnableMinimizeButton(bool bEnable)
{
	
	if (bEnable) 
	{
		
		HWND hwnd = ::FindWindow( NULL, "MediaTek Console");
		//if (!g_bMSLTOpened)
		{
		if( ::IsWindow( hwnd ) ) 
			::ShowWindow( hwnd, SW_SHOW ) ;
		}
		
		//Pinksword
		//dlg.RestoreAllDialog();
		
		//if (!g_bMSLTOpened)
		{
		main_dlg->EnableWindow( TRUE );
		main_dlg->ShowWindow(SW_RESTORE);
		main_dlg->ShowWindow(SW_SHOW);
		//dlg.ShowWindow( SW_RESTORE );
		//dlg.ShowWindow( SW_SHOW );
		this->ShowWindow( SW_RESTORE );	
		this->ShowWindow( SW_SHOW );
		}
		PeekAndPumpMessage ();	
		main_dlg->ModifyStyle(0, WS_MINIMIZEBOX, 0);
	}
	else
	{	
		//Pinksword
		//dlg.HideAllDialog();	
		main_dlg->EnableWindow(false);
		main_dlg->ShowWindow(SW_HIDE);
		//::ShowWindow( dlg.GetSafeHwnd(), SW_HIDE );	
		PeekAndPumpMessage ();	
				
		::ShowWindow( this->GetSafeHwnd(), SW_HIDE );			
		PeekAndPumpMessage ();
		
		HWND hwnd = ::FindWindow( NULL, "MediaTek Console");
		if( ::IsWindow( hwnd ) ) 
			::ShowWindow( hwnd, SW_HIDE ) ;

		main_dlg->ModifyStyle( WS_MINIMIZEBOX, 0, 0);
	}
	
	//::DrawMenuBar( dlg.GetSafeHwnd() );
	::DrawMenuBar( main_dlg->GetSafeHwnd() );
}
#ifdef MODIS_MTE_UNIT_TEST
void CDialogTheme::RunUnitTest()
{
    // Reference output files:
    //      [Theme_orig.mte] [ThemeComponents_orig.h] [ThemeRes_orig.c]
    //
    // Step 1: Output [Theme_ut.mte], [ThemeComponents_ut.h], [ThemeRes_ut.c]
    // Step 2: Compare results with reference output files
    //         [Theme_ut.mte]         <=> [Theme_orig.mte]
    //         [ThemeComponents_ut.h] <=> [ThemeComponents_orig.h]
    //         [ThemeRes_ut.c]        <=> [ThemeRes_orig.c]
    // Step 3: Load [Theme_ut.mte]
    // Step 4: Repeat step 1 and step 2
 
    // Step 1
    OnOutput();

    // Step 2
    ASSERT(CompareFiles("Theme_ut.mte",         "Theme_orig.mte"));
    ASSERT(CompareFiles("ThemeComponents_ut.h", "ThemeComponents_orig.h"));
    ASSERT(CompareFiles("ThemeRes_ut.c",        "ThemeRes_orig.c"));

    // Step 3
    OnLoadTheme();

    // Step 4
    OnOutput();
    ASSERT(CompareFiles("Theme_ut.mte",         "Theme_orig.mte"));
    ASSERT(CompareFiles("ThemeComponents_ut.h", "ThemeComponents_orig.h"));
    ASSERT(CompareFiles("ThemeRes_ut.c",        "ThemeRes_orig.c"));

    // Reference output files:
    //      [Theme_orig2.mte] [ThemeComponents_orig2.h] [ThemeRes_orig2.c]
    //
    // Step 1: Delete Theme2 (hardcoded in OnDelete())
    // Step 2: Output [Theme_ut.mte], [ThemeComponents_ut.h], [ThemeRes_ut.c]
    // Step 3: Compare results with reference output files
    //         [Theme_ut.mte]         <=> [Theme_orig2.mte]
    //         [ThemeComponents_ut.h] <=> [ThemeComponents_orig2.h]
    //         [ThemeRes_ut.c]        <=> [ThemeRes_orig2.c]
    // Step 4: Load [Theme_ut.mte]
    // Step 5: Repeat step 2 and step 3

    // Step 1
    OnDelete();

    // Step 2
    OnOutput();

    // Step 3
    ASSERT(CompareFiles("Theme_ut.mte",         "Theme_orig2.mte"));
    ASSERT(CompareFiles("ThemeComponents_ut.h", "ThemeComponents_orig2.h"));
    ASSERT(CompareFiles("ThemeRes_ut.c",        "ThemeRes_orig2.c"));

    // Step 4
    OnLoadTheme();

    // Step 5
    OnOutput();
    ASSERT(CompareFiles("Theme_ut.mte",         "Theme_orig2.mte"));
    ASSERT(CompareFiles("ThemeComponents_ut.h", "ThemeComponents_orig2.h"));
    ASSERT(CompareFiles("ThemeRes_ut.c",        "ThemeRes_orig2.c"));

    MessageBox("Unit test passed");
}
#endif // MODIS_MTE_UNIT_TEST

void CDialogTheme::OnCancel()
{
	::SendMessage(GetParent()->GetSafeHwnd(), PLUGIN_MSG, (WPARAM)PM_CLOSED, (LPARAM)m_szCurDllName);
	DestroyWindow();
	//CDialog::OnCancel();
}

void CDialogTheme::PostNcDestroy()
{
	//free edit theme
	for(int i = 0; i<m_total_edit_theme_num;i++)
	{	
		if(m_edit_theme_list[i])
		{
			delete m_edit_theme_list[i];
			m_edit_theme_list[i] = NULL;
		}
	}

	CDialog::PostNcDestroy();
	delete this;
}

void CDialogTheme::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnLButtonDown(nFlags, point);
}

void CDialogTheme::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

LRESULT CDialogTheme::OnPluginMessage(WPARAM wParam, LPARAM lParam)
{
	USES_CONVERSION;
	if(PM_MOVE == (PLUGIN_MSG_ID)wParam)
	{
		UpdatePosition();
	}
	return 0;
}
