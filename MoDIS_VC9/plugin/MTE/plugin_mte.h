// plugin_mte.h : main header file for the plugin_mte DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cplugin_mteApp
// See plugin_mte.cpp for the implementation of this class
//

class Cplugin_mteApp : public CWinApp
{
public:
	Cplugin_mteApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

__declspec(dllexport) void WINAPI OpenPlugin(HWND);
__declspec(dllexport) void WINAPI ClosePlugin(void);