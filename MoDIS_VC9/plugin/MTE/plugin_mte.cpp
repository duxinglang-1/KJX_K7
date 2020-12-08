// plugin_mte.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "plugin_mte.h"
#include "DialogTheme.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// Cplugin_mteApp

BEGIN_MESSAGE_MAP(Cplugin_mteApp, CWinApp)
END_MESSAGE_MAP()


// Cplugin_mteApp construction

Cplugin_mteApp::Cplugin_mteApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	//_CrtSetBreakAlloc(1430);
}


// The one and only Cplugin_mteApp object

Cplugin_mteApp theApp;

// Cplugin_mteApp initialization

BOOL Cplugin_mteApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

CDialogTheme * g_pThemeDlg = NULL;
__declspec(dllexport) void WINAPI OpenPlugin(HWND hParent, HWND* phWnd)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	g_pThemeDlg = new CDialogTheme( CWnd::FromHandle(hParent));
	if(NULL !=  g_pThemeDlg)
	{
		BOOL ret = g_pThemeDlg->Create(IDD_DIALOG_THEME, CWnd::FromHandle(hParent));
		g_pThemeDlg->ShowWindow(SW_SHOW);
		if(NULL != phWnd)
			*phWnd = g_pThemeDlg->GetSafeHwnd();
	}
	return;
}

__declspec(dllexport) void WINAPI ClosePlugin(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if(NULL != g_pThemeDlg && ::IsWindow(g_pThemeDlg->GetSafeHwnd()))
	{
		//g_pThemeDlg->OnDestroy();
		g_pThemeDlg->SendMessage(WM_CLOSE);
		//g_pThemeDlg->SendMessage(WM_DESTROY);
		delete g_pThemeDlg;
		g_pThemeDlg = NULL;
	}
	return;
}

/************************************************************************
 关于PreTranslateMessage有一个常见的问题就是与此有关：
 如果编写了一个MFC DLL并从另外的一个MFC主工程之中调用这个MFC DLL中的Modeless Dialog的话，
 Modeless Dialog的PreTranslateMessage不会被调。
 因为MFC DLL和这个MFC工程拥有不同的AfxModuleThreadState，
 因此在MFC DLL中创建的modeless CDialog对象不在MFC工程的句柄表中
 （CWnd::FromhandlePermanent返回NULL），因此虽然MFC主工程中的CWinApp的Pretranslatemessage会被调
 （注意此时Dialog的消息循环在MFC主工程里面），但是不会调用MFC DLL中创建的那个modeless CDialog
 的PreTranslateMessage函数。因此需要特殊处理。一般有两种方法，
 1. 直接在MFC主工程中的CWinApp::PreTranslatemessage里面调用MFC DLL的CWinApp::PreTranslateMessage
 (可以专门在MFC DLL中export一个专门的函数来做这件事情)
 2. 使用钩子，在钩子消息处理函数之中，判断目标窗口是否是当前具有焦点的窗口，
 如果是，则直接调用目标窗口的PreTranslateMessage函数（前提是你有要保存这个对象的指针）。                                                 
/************************************************************************/
__declspec(dllexport) BOOL WINAPI PluginPreTranslateMessage(MSG* pMsg)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return theApp.PreTranslateMessage(pMsg);
}
