@echo off
rem 功能：自动将编译好待发布的软件拷贝到服务器项目软件发布目录(包括bin档，database，elf，sym)，
rem             并发送通知邮件给项目相关人员
rem 使用方法：
rem 1.将服务器上的共享目录"\\192.168.2.11\公司共享\量产软件版本\A62"映射为本地驱动器，盘符选"Z"
rem 2.编译好要发布的软件后，在工程根目录下运行该批处理即可
rem 3.该批处理可带一个或者两个运行参数，用法: release.bat [-mail] [pro_name]
rem       -mail 该参数允许在软件发布后发送通知邮件给项目相关人员
rem       pro_name 即项目名称(XXXX_GPRS.mak中的XXXX即为项目名称)
rem 如果不带参数，则默认将最近的一次编译打包拷贝到服务器的项目发布目录
perl release.pl %*
@pause