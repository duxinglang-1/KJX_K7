#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SIMEDITOR_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SIMEDITOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SIMEDITOR_EXPORTS
#define SIMEDITOR_API __declspec(dllexport)
#else
#define SIMEDITOR_API __declspec(dllimport)
#endif

typedef struct  
{
	HWND hParent;	//Parent window handle
	BOOL bShowSetDef;		//If show "Set as default SIM Card of a Modis"
	LPCTSTR lpszModisPath;	//Modis(To be set default SIM Card) path, only valid when (bShowSetDef == TRUE)
	INT iMaxSIMCardCurLoadSupport;	//Only valid when (bShowSetDef == TRUE)
	UINT uiMinMSISDNSim;	//Min and Max MSISDN numbers you want to support
	UINT uiMaxMSISDNSim;
	UINT uiMinMSISDNUSim;
	UINT uiMaxMSISDNUSim;
}	SimEditorInitParam;
SIMEDITOR_API BOOL SimEditorInit(SimEditorInitParam);
SIMEDITOR_API BOOL SimEditorUninit(void);
SIMEDITOR_API BOOL SimEditorOpen(void);
SIMEDITOR_API BOOL SimEditorClose(void);
