@ECHO OFF
REM createMSLT.bat [dst path]

set dst=%1

IF NOT "%dst%"==""   GOTO CHECK_MODIS
ECHO createMSLT.bat [dst path]
GOTO END

:CHECK_MODIS
IF EXIST .\MoDIS\Release\MoDIS.exe  GOTO RELEASE
IF EXIST .\MoDIS\Debug\MoDIS.exe    GOTO DEBUG
ECHO Do not build MoDIS.exe
GOTO END

:RELEASE
set mode=Release
GOTO START

:DEBUG
set mode=Debug
GOTO START

:START
IF NOT EXIST .\MoDIS\%mode%\MODIS_UI_MSLT.dll   GOTO NO_MSLT
IF NOT EXIST .\MoDIS\MSLT_INFO                  GOTO NO_MSLTINFO

IF EXIST %dst% RD /S /Q %dst%

IF "%mode%"=="Release"  (perl modisReleaseL1.pl -release %dst%)
IF "%mode%"=="Debug"    (perl modisReleaseL1.pl -debug %dst%)

REM MKDIR %dst%\MoDIS_VC9\MoDIS\MSLT_INFO
REM COPY /Y .\MoDIS\MSLT_INFO\*.* %dst%\MoDIS_VC9\MoDIS\MSLT_INFO\*.*
REM IF EXIST %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_ALL.dll del /Q %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_ALL.dll
REM IF EXIST %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_ALL.lib del /Q %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_ALL.lib
MOVE /Y %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_MSLT.dll %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI.dll
MOVE /Y %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI_MSLT.lib %dst%\MoDIS_VC9\MoDIS\%mode%\MODIS_UI.lib

GOTO END

:NO_MSLT
ECHO Do not build MoDIS String Length Tool
GOTO END

:NO_MSLTINFO
ECHO No MSLT_INFO
ECHO Please ResGen first
GOTO END

:END
