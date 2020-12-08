/**********************************************************************************
*Filename:     kjx_switch.c
*
*Description:  
*
*Author:        caoweijie
*
*Datetime:    2014/01/07
*
***********************************************************************************/
#if defined(__KJX_FUN__)
typedef unsigned short U16;
typedef char  S8;
typedef unsigned char  U8;
//typedef unsigned char kal_uint8;
typedef unsigned short int kal_uint16;
typedef unsigned int kal_uint32;
//typedef void *kal_hisrid;
typedef signed int              kal_int32;
 
//#define kal_bool kal_uint8
#ifndef NULL
#define NULL   (0)
#endif
     
//#define BKK_SWITCH_DEBUG
    
#include "rtc_sw_new.h"
#include "app_datetime.h"

//V1.0版本    
char* str= "JTdnx7*=-&6wmcSIHRblv5^+:%4ukaQGFPZjt3$?>#2siYOEDNXhr1@<|/_!0qgWMCBLVfpz9),.(8yoeUKA";//{}[]
char stringbuf[][6]={"J","T","d","n","x","7","*","=","-","&","6","w","m","c","S","I","H","R","b","l","v","5","^","+",":","%","4","u","k","a","Q","G","F","P","Z","j","t","3","$","?",">","#","2","s","i","Y","O","E","D","N","X","h","r","1","@","<","|","/","_","!","0","q","g","W","M","C","B","L","V","f","p","z","9",")",",",".","(","8","y","o","e","U","K","A"};//, "{", "}", "[", "]"
 
//extern int string_mode[3][6]; 
//extern void RTC_GetTime(t_rtc *rtctime );
    
char* kjx_switch_string(char* string,int index,char* version)
{
  int leng=0,num=0,maxlen=0,i=0,beg_num=0;
  U16 sec=0;
  t_rtc rtc_time;
  S8 temstr[6];
  S8 numstr[6];
  S8 Bstring[200];
  S8 string1[200];
  U8 restring[200];
  applib_time_struct currTime;

  char* str_buffer=NULL;
  
   memset(&currTime, 0x00, sizeof(currTime));
   applib_dt_get_rtc_time(&currTime);	

   memset(temstr, 0, sizeof(temstr));
   memset(numstr, 0, sizeof(numstr));
   memset(Bstring, 0, sizeof(Bstring));
   memset(string1, 0, sizeof(string1));
   memset(restring, 0, sizeof(restring));

if(!memcmp(version,"V3.3\0", strlen(version)))
{
 switch(index)
 {
    case 1:
    {//加密部分
		     
           leng=strlen((const char *)string);//获取密文长度
	    maxlen=strlen((const char *)str);//获取最大随机值
	    memset(restring, 0, sizeof(restring));
	    memset(Bstring, 0, sizeof(Bstring));
           memcpy((char *)Bstring,(const char *)string,strlen((const char *)string));
		  
	    //RTC_GetTime(&rtc_time);
           //sec=rtc_time.rtc_sec;

	    //获取随机数  
	    srand((unsigned)currTime.nSec);
	    num = rand()%maxlen;

	    for(i=0;i<leng;i++)
	    {
	       memset(temstr, 0, sizeof(temstr));
		memset(string1, 0, sizeof(string1));
		
		memcpy((char *)string1,(const char *)Bstring,strlen((const char *)Bstring));
	       memcpy((char *)temstr,(const char *)string1+i, 1);
             
		str_buffer=(char*)strstr((const char *)str, (const char *)temstr);
		beg_num=str_buffer-str;
    
             if(str_buffer)
             	{

             	  if(beg_num+num+1>=maxlen)
             	  {
             	    strcat((char *)restring,(const char *)stringbuf[beg_num+num+1-maxlen]);
             	  }
		  else
		  {       
		    strcat((char *)restring,(const char *)stringbuf[beg_num+num+1]);
		  }
             	}
		else
		{
		    strcat((char *)restring,(const char *)temstr);
		}
		
	    }

            //添加标示符
		strcat((char *)restring,"xCn");
		
		memset(numstr, 0, sizeof(numstr));
		sprintf(numstr,"%d",num);
		strcat((char *)restring,(const char *)numstr);
				
		break;
    }
	
    case 2:
    {//解密部分
	    int beleng=0;
	    S8 nstring[6];
	    char* bebuffer=NULL;
					
	    memset(Bstring, 0, sizeof(Bstring));
	    memset(string1, 0, sizeof(string1));
           memcpy((char *)Bstring,(const char *)string,strlen((const char *)string));
	    memcpy((char *)string1,(const char *)Bstring,strlen((const char *)Bstring));

           leng=strlen((const char *)string);//获取密文长度
	    maxlen=strlen((const char *)str);//获取最大随机值
	    
	    memset(restring, 0, sizeof(restring));

	    bebuffer = (char *)strstr((const char *)string1, "xCn");//标示符出现的位置

           if(!bebuffer)
           {			  
		 //break;
              return (char*)restring;
	    }
		beleng=bebuffer-string1;

           //获取到随机数
	    memset(nstring, 0, sizeof(nstring));
	    memset(string1, 0, sizeof(string1));
	    memcpy((char *)string1,(const char *)Bstring,strlen((const char *)Bstring));
	    memcpy((char *)nstring,(const char *)string1+beleng + 3, strlen((const char *)string1+beleng + 3));

	    num=atoi((const char *)nstring);

	    for(i=0;i<beleng;i++)
	    {
	       memset(temstr, 0, sizeof(temstr));
		memset(string1, 0, sizeof(string1));

		memcpy((char *)string1,(const char *)Bstring,strlen((const char *)Bstring));
	       memcpy((char *)temstr,(const char *)string1+i, 1);

		str_buffer=(char*)strstr((const char *)str, (const char *)temstr);
		beg_num=str_buffer-str;
		 
            if(str_buffer)
            {
             	  if(beg_num-num-1<0)
             	    strcat((char *)restring,(const char *)stringbuf[beg_num-num+ maxlen - 1]);
		  else
		    strcat((char *)restring,(const char *)stringbuf[beg_num-num-1]);
             	}
		else
		{  
		    strcat((char *)restring,(const char *)temstr);
		}

	    }
		    
		break;
    }
	
   default:
   	break;
 }
}
else
{//未被加密
   return (char*)string;
}
    
    return (char*)restring;
}
#endif
