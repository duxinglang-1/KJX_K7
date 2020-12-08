#pragma once

#include <string>

char *get_modis_exe_path();
char *get_convert_exe_full_path();
char *get_temp_path();

#define ENGLISH 0
#define SIM_CHINESE 1
#define START_CURRENT_SCR  "----Current Screen----"

BOOL RunProcess(char* processname);

template <typename ContainerType, typename StringType>
StringType Join(const ContainerType &tokens, const StringType &delimiter)
{
	StringType ret;

	for (ContainerType::const_iterator iter = tokens.begin();
		iter != tokens.end();
		++iter)
	{
		if (iter != tokens.begin())
		{
			ret += delimiter;
		}

		ret += *iter;
	}

	return ret;
}

class MoDISFileDialogW
{
public:
	MoDISFileDialogW( OPENFILENAMEW &ofn );
	MoDISFileDialogW( HWND hwndOwner, LPCWSTR lpstrDefExtW, 
		LPWSTR lpszFileNameW, DWORD Flags, LPCWSTR lpstrFilterW);
	BOOL LoadFile();
	BOOL SaveFile();	
	std::wstring  GetFileNameW();
	std::string GetFileNameA();


private:		
	OPENFILENAMEW ofn ;
	WCHAR szFile[MAX_PATH];
};