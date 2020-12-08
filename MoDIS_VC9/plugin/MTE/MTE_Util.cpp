#include "StdAfx.h"
#include "MTE_Util.h"

char *get_modis_exe_path()
{
	int i;
	static char modis_exe_path[1024];

	GetModuleFileName(NULL, modis_exe_path, 1024 - 1);

	for (i = strlen(modis_exe_path) - 1; i >= 0; i--)
	{
		if (modis_exe_path[i] == '\\')
		{
			modis_exe_path[i] = 0;
			break;
		}
	}

	return modis_exe_path;
}

char *get_convert_exe_full_path()
{
	char *modis_exe_path;
	static char convert_exe_path[1024];

	WIN32_FIND_DATA fd;	

	modis_exe_path = get_modis_exe_path();

	// search resource generator directory first, and then modis directory    
	sprintf(convert_exe_path, "%s\\..\\..\\..\\plutommi\\Customer\\ResGenerator\\convert.exe", modis_exe_path);
	if (FindFirstFile(convert_exe_path, &fd) == INVALID_HANDLE_VALUE)
	{
		// try modis.exe directory
		sprintf(convert_exe_path, "%s\\convert.exe", modis_exe_path);
		if (FindFirstFile(convert_exe_path, &fd) == INVALID_HANDLE_VALUE)
		{
			return NULL;
		}
	}

	return convert_exe_path;
}	

char *get_temp_path()
{
	static char temp_path[1024];
	temp_path[1024 - 1] = 0;
	GetTempPath(1024 - 1, temp_path);  
	return temp_path;
}

BOOL RunProcess(char* processname)
{
	// Start the child process. 
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	return CreateProcess( NULL, processname, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi); 
}

MoDISFileDialogW::MoDISFileDialogW( HWND hwndOwner, LPCWSTR lpstrDefExtW, 
								   LPWSTR lpszFileNameW, DWORD Flags, LPCWSTR lpstrFilterW)
{
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hwndOwner;
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = L'\0';
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = lpstrFilterW;
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = lpszFileNameW;
	ofn.nMaxFileTitle = sizeof(lpszFileNameW);
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrDefExt	= lpstrDefExtW;
	ofn.Flags = Flags;
}

MoDISFileDialogW::MoDISFileDialogW( OPENFILENAMEW &ofnin )
{
	ofn = ofnin;
}

BOOL MoDISFileDialogW::SaveFile()
{
	return ::GetSaveFileNameW( &ofn ) ;
}

BOOL MoDISFileDialogW::LoadFile()
{
	return ::GetOpenFileNameW( &ofn ) ;
}


std::wstring MoDISFileDialogW::GetFileNameW()
{
	return std::wstring( szFile ) ;
}

std::string MoDISFileDialogW::GetFileNameA()
{
	USES_CONVERSION ;	
	return std::string( W2A(szFile));
}