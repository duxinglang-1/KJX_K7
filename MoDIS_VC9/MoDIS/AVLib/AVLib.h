// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the AVLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// AVLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef AVLIB_EXPORTS
#define AVLIB_API __declspec(dllexport)
#else
#define AVLIB_API __declspec(dllimport)
#endif

/*
// This class is exported from the AVLib.dll
class AVLIB_API CAVLib {
public:
	CAVLib(void);
	// TODO: add your methods here.
};

extern AVLIB_API int nAVLib;

AVLIB_API int fnAVLib(void);*/
