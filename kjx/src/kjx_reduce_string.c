/**********************************************************************************
*Filename:     kjx_reduce_string.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/08/26
*
***********************************************************************************/
#if defined(__KJX_FUN__)
#include "kjx_include.h"

#ifndef NULL
 #define NULL   (0)
#endif

char* restring=NULL;
char* dstring1=NULL;
char* dstring2=NULL;
char* dstring3=NULL;
char* outstring=NULL;
char* outstring1=NULL;

/*========================================================
==========================================================
函数名称:char* kjx_check_file_data(char* filename,char* headstr,char*datastr,char* endstr,int index)
实现功能:查找、修改数据
参数:filebuffer  文件内容
            headstr    内容头
            datastr    写入内容
            endstr      内容尾
            index       读写模式   1为读 /2为写
            handle  文件索引
返回:内容、0读写失败、1写入成功
==========================================================
========================================================*/
char* kjx_check_file_data(char*filebuffer,int bufflen,char* headstr,char*datastr,char* endstr,int index,FS_HANDLE handle)
{      
	char* restring=NULL;
	char* strhead=NULL;
	char* strend=NULL;
	char* tem1=NULL;
	char* tem2=NULL;
	char* tem3=NULL;
	int readsize;
	int i=0,j=0,strleng=0,datalen=0,begleng=0,lastleng=0,input=0;

	dstring1=NULL;
	dstring2=NULL;
	dstring3=NULL;

	switch(index)
	{
	case 1://读取
		if(!(strlen((const char *)filebuffer)))
		{
			//无内容
			restring="-1";
			break;
		}

		strhead=(char*)strstr((const char *)filebuffer, (const char *)headstr);
		if(strhead)
		{
			//读到文件头
			strend=(char*)strstr((const char *)filebuffer, (const char *)endstr);
			if(strend)
			{
				//读到文件尾
				datalen=strend-strhead-(strlen((const char *)headstr));//实用数据长度
				if(dstring1==NULL)
				{

					dstring1 = (char*) OslMalloc(datalen+100);
					tem1=dstring1;
				}

				memset(dstring1, 0, strlen((const char *)dstring1));
				memcpy((char*)dstring1, (const char *)strhead+(strlen((const char *)headstr)), datalen);//获取实用数据
				dstring1[datalen]='\0';

				restring=(char*)dstring1;
				if(dstring1!=NULL)
				{
					OslMfree(tem1);
					dstring1=NULL;
					tem1=NULL;
				} 
			}
			else
			{
				//找不到文件尾，数据错误
				restring="-1";
			}
		}
		else
		{
			//没有需要的数据
			restring="-1";
		}
		break;

	case 2://写入
		if(!filebuffer)
		{
			//没有，则直接添加数据
			FS_Write(handle,headstr,strlen((const char *)headstr),(UINT*)&readsize);
			FS_Write(handle,datastr,strlen((const char *)datastr),(UINT*)&readsize);
			FS_Write(handle,endstr,strlen((const char *)endstr),(UINT*)&readsize);

			if(readsize)
				restring="1";
			else
				restring="-1";
			
			break;
		}

		if(!bufflen)
		{
			//无内容
			restring="-1";
			break;
		}

		strhead=(char*)strstr((const char *)filebuffer, (const char *)headstr);
		if(strhead)
		{
			//读到文件头，如有文件头，则替换数据
			strend=(char*)strstr((const char *)filebuffer, (const char *)endstr);
			if(strend)
			{
				//读到文件尾
				begleng=strhead-filebuffer;//替换内容前面数据长度
				if(begleng>0)
				{
					if(dstring2==NULL)
					{    
					dstring2 = (char*) OslMalloc(begleng+100);
					tem2=dstring2;
					}

					memset(dstring2, 0, strlen((const char *)dstring2));
					memcpy((char*)dstring2, (const char *)filebuffer, begleng);//替换内容前面数据
					dstring2[begleng]='\0';

					FS_Write(handle,dstring2,begleng,(UINT*)&readsize);
					if(dstring2!=NULL)
					{
						OslMfree(tem2);
						dstring2=NULL;
						tem2=NULL;
					}

					if(readsize)
						restring="1";
					else
						restring="-1";
				}

				//替换内容后面数据 
				if(dstring3==NULL)
				{
					dstring3 = (char*) OslMalloc(strlen((const char *)strend+(strlen((const char *)endstr)))+100);
					tem3=dstring3;
				}

				memset(dstring3, 0, strlen((const char *)dstring3));
				memcpy((char*)dstring3, (const char *)strend+(strlen((const char *)endstr)), strlen((const char *)strend+(strlen((const char *)endstr))));
				dstring3[strlen((const char *)strend+(strlen((const char *)endstr)))]='\0';

				FS_Write(handle,dstring3,strlen((const char *)strend+(strlen((const char *)endstr))),(UINT*)&readsize);
				if(dstring3!=NULL)
				{
					OslMfree(tem3);
					dstring3=NULL;
					tem3=NULL;
				}
	
				if(readsize)
					restring="1";
				else
					restring="-1";

				FS_Write(handle,headstr,strlen((const char *)headstr),(UINT*)&readsize);
				FS_Write(handle,datastr,strlen((const char *)datastr),(UINT*)&readsize);
				FS_Write(handle,endstr,strlen((const char *)endstr),(UINT*)&readsize);

				if(readsize)
					restring="1";
				else
					restring="-1";

			}
			else
			{//找不到文件尾，数据错误，不能再添加相同文件头数据
				restring="-1";
			}
		}
		else
		{
			//没有，则直接添加数据
			FS_Write(handle,filebuffer,strlen((const char *)filebuffer),(UINT*)&readsize);
			FS_Write(handle,headstr,strlen((const char *)headstr),(UINT*)&readsize);
			FS_Write(handle,datastr,strlen((const char *)datastr),(UINT*)&readsize);
			FS_Write(handle,endstr,strlen((const char *)endstr),(UINT*)&readsize);

			if(readsize)
				restring="1";
			else
				restring="-1";
		}
		break;

	default: 
		restring="-1";
		break;
	}

	return (char*)restring;
}


/*========================================================
==========================================================
函数名称:int kjx_get_parameter_number(char* stringbuffer,char* header,char* ender,char* sign,int MaxNum)
实现功能:根据输入字符串和标识符，计算出参数的个数
参数:stringbuffer  字符串
            sign            标识符
            header  内容头
            ender    内容尾
            MaxNum  最大参数个数，可随意设置大于参数个数的值
返回:参数个数
==========================================================
========================================================*/
int kjx_get_parameter_number(char* stringbuffer,char* header,char* ender,char* sign,int MaxNum)
{
	int i;
	char* string=NULL;
	char* instring=NULL;

	//获取指定头和尾的字符串
	instring=(char*)kjx_check_file_data((char*)stringbuffer,NULL,header,NULL,ender,1,NULL);

	for(i=0;i<MaxNum;i++)
	{
		string=(char*)strstr((const char *)instring, (const char *)sign);
		if(!string)
		{
			break;
		}

		instring=string+strlen((const char *)sign);
	}

	//i 为标识符出现的次数，需要+1返回参数的个数
	return i+1;
}

/*========================================================
==========================================================
函数名称:char* kjx_get_parameter_string(char* stringbuffer,char* header,char* ender,char* sign,int index)
实现功能:查找未分解字符串中，指定索引的字符串
参数:stringbuffer  字符串
            sign            标识符,如果没有则填充NULL
            header  内容头
            ender    内容尾
            index  参数索引，从1开始计算
返回:当前索引所指向的参数
==========================================================
========================================================*/
char* kjx_get_parameter_string(char* stringbuffer,char* header,char* ender,char* sign,int index)
{
	int i,strnum,in_total;
	char* string=NULL;
	char* instring=NULL;
	char* temGetstring=NULL;
	S8 prin[100];

	in_total=0;
	//获取指定头和尾的字符串
	instring=(char*)kjx_check_file_data((char*)stringbuffer,NULL,header,NULL,ender,1,NULL);

	if(sign==NULL)
	{
		return (char*)instring;
	}

	for(i=0;i<index;i++)
	{	   
		string=(char*)strstr((const char *)instring, (const char *)sign);
		strnum=string-instring;
		if((!string)||(strnum<0))
		{
			in_total++;
			if(in_total==1)
				return (char *)instring;
			else if(in_total>1)
				return NULL;
		}

		if(restring!=NULL)
		{
			OslMfree(restring);
			restring=NULL;
		}

		if(restring==NULL)
		{
			restring = (char*) OslMalloc(strnum+100);
		}

		memset(restring, 0, strlen((const char *)restring));
		memcpy((char*)restring, (const char *)instring, strnum);
		restring[strnum]='\0';

		instring=string+strlen((const char *)sign);
	}

	return (char*)restring;
}

/*========================================================
==========================================================
函数名称:char* kjx_get_parameter_string_extern(char* stringbuffer,char* header,char* ender,char* subHeader,char* subEnder,int index)
实现功能:查找未分解字符串中，指定索引的字符串
参数:stringbuffer  字符串
            header  内容头
            ender    内容尾
            subHeader  子内容头
            subEnder    子内容尾
            index  参数索引，从1开始计算
返回:当前索引所指向的参数
==========================================================
========================================================*/
char* kjx_get_parameter_string_extern(char* stringbuffer,char* header,char* ender,char* subHeader,char* subEnder,int index)
{
	int i,strnum,in_total;
	char* string=NULL;
	char* instring=NULL;
	char* temGetstring=NULL;

	if(restring!=NULL)
	{
		OslMfree(restring);
		restring=NULL;
	}

	if(restring==NULL)
	{
		restring = (char*) OslMalloc(512);
	}

	in_total=0;
	//获取指定头和尾的字符串
	instring=(char*)kjx_check_file_data((char*)stringbuffer,NULL,header,NULL,ender,1,NULL);

	for(i=0;i<index;i++)
	{	
		string=(char*)strstr((const char *)instring, (const char *)subHeader);
		if(instring)
		{
			instring += strlen((const char *)subHeader);
		}

		string=(char*)strstr((const char *)instring, (const char *)subEnder);
		strnum=string-instring;
		if((!string)||(strnum<0))
		{
			in_total++;
			if(in_total==1)
				return (char *)instring;
			else if(in_total>1)
				return NULL;
		}

		memset(restring, 0, strlen((const char *)restring));
		memcpy((char*)restring, (const char *)instring, strnum);
		restring[strnum]='\0';

		instring=instring+strnum+strlen((const char *)subEnder);
	}

	return (char*)restring;
}
/*========================================================
==========================================================
函数名称:char* kjx_get_parameter_string_only_in_buffer(char* stringbuffer,char* sign,int index)
实现功能:查找未分解字符串中，指定索引的字符串(无文件头、尾)
参数:stringbuffer  字符串
            sign            标识符,如果没有则填充NULL
            index  参数索引，从1开始计算
返回:当前索引所指向的参数
==========================================================
========================================================*/
char* kjx_get_parameter_string_only_in_buffer(char* stringbuffer,char* sign,int index)
{
	int i,strnum,in_total;
	char* string=NULL;
	char* instring=NULL;
	char* temGetstring=NULL;  

	in_total=0;
	instring=stringbuffer;
	if(strlen(sign)==0)
	{
		return (char*)instring;
	}

	for(i=0;i<index;i++)
	{
		U32 len;

		len = strlen((const char *)instring);
		string=NULL;
		string=(char*)strstr((const char *)instring, (const char *)sign);
		strnum=string-instring;
		if((!string)||(strnum<0))
		{
			in_total++;
			if(in_total==1)
			{
				if(outstring1 != NULL)
				{
					media_free_ext_buffer(MOD_MMI, (void**)&outstring1);
					outstring1 = NULL;
				}

				if(outstring1 == NULL)
				{
					media_get_ext_buffer(MOD_MMI, (void **)&outstring1, len+1);
					if(outstring1 == NULL)
						return;
				}
				
				memset(outstring1, 0, len+1);
				strncpy((char*)outstring1, (const char *)instring, len);
				return (char *)outstring1;
			}
			else if(in_total>1)
			{
				return NULL;
			}
		}

		if(outstring1!=NULL)
		{
			media_free_ext_buffer(MOD_MMI, (void**)&outstring1);
			outstring1 = NULL;
		}

		if(outstring1==NULL)
		{   
			media_get_ext_buffer(MOD_MMI, (void **)&outstring1, strnum+1);
			if(outstring1 == NULL)
				return;
		}
		memset(outstring1, 0, strnum+1);
		memcpy((char*)outstring1, (const char *)instring, strnum);
		instring=string+strlen((const char *)sign);
	}

	return (char*)outstring1;
}

char* kjx_get_parameter_string_only_in_buffer_extern(char* stringbuffer,char* sign,int index)
{
	int i=0,strnum=0,in_total=0;
	char* string=NULL;
	char* instring=NULL;

	in_total=0;
	instring=stringbuffer;
	if(strlen(sign)==0)
	{
		return (char*)instring;
	}

	for(i=0;i<index;i++)
	{
		string=NULL;
		string=(char*)strstr((const char *)instring, (const char *)sign);

		strnum=string-instring;
		if((!string)||(strnum<0))
		{ 
			if(i<index-1)
				return NULL;

			in_total++;
			if(in_total==1)
			{
				if(outstring!=NULL)
				{
					OslMfree(outstring);
					outstring=NULL;
				}

				if(outstring==NULL)
				{   
					outstring = (char*) OslMalloc(128);
				}              
				memset(outstring, 0, 128);
				strncpy((char*)outstring, (const char *)instring, strlen((const char *)instring));
				outstring[strlen((const char *)instring)]='\0';
				return (char *)outstring;
			}
			else if(in_total>1)
			{
				return NULL;
			}
		}

		if(outstring!=NULL)
		{
			OslMfree(outstring);
			outstring=NULL;
		}

		if(outstring==NULL)
		{   
			outstring = (char*) OslMalloc(128);
		}

		memset(outstring, 0, 128);
		memcpy((char*)outstring, (const char *)instring, strnum);
		outstring[strnum]='\0';

		instring=string+strlen((const char *)sign);
	}

	return (char*)outstring;
}

#endif
