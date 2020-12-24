@cd make
@if exist *gprs.mak goto gprs
echo 找不到可用的MAKE文件
goto end
:gprs
@for %%x in (*gprs.mak) do set project=%%x
@cd ..\
@echo off
echo 	------------------------------------
echo 	---输入以上工程名---例如A62;B601...
echo 	------------------------------------
set /p custom=
make %custom% gprs %*