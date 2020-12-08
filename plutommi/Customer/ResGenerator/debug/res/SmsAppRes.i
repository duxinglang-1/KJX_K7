# 1 "temp/res/SmsAppRes.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SmsAppRes.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/SmsAppRes.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 3 "temp/res/SmsAppRes.c" 2
# 1 "../../framework/gdi/gdiinc/gdi_features.h" 1
# 382 "../../framework/gdi/gdiinc/gdi_features.h"
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_display.h" 1
# 200 "../../../interface/hal/drv_sw_def/drv_sw_features_display.h"
# 1 "../../../hal/drv_def/drv_features_chip_select.h" 1
# 161 "../../../hal/drv_def/drv_features_chip_select.h"
# 1 "../../../hal/drv_def/drv_features_6260.h" 1
# 162 "../../../hal/drv_def/drv_features_chip_select.h" 2
# 201 "../../../interface/hal/drv_sw_def/drv_sw_features_display.h" 2
# 1 "../../../hal/drv_def/drv_features_g2d.h" 1
# 302 "../../../hal/drv_def/drv_features_g2d.h"
# 1 "../../../hal/drv_def/drv_features_mdp.h" 1
# 235 "../../../hal/drv_def/drv_features_mdp.h"
# 1 "../../../custom/common/hal_public/lcd_sw_inc.h" 1
# 67 "../../../custom/common/hal_public/lcd_sw_inc.h"
# 1 "../../../custom/drv/lcd/hexing60a_11b_lcm/lcd_hw.h" 1
# 37 "../../../custom/drv/lcd/hexing60a_11b_lcm/lcd_hw.h"
# 1 "../../../kal/include/kal_general_types.h" 1
# 82 "../../../kal/include/kal_general_types.h"
# 1 "../../../kal/include/clib.h" 1
# 100 "../../../kal/include/clib.h"
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/setjmp.h" 1 3
# 32 "f:/K7_TOUR/CODE/Tools/MinGW/include/setjmp.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/_mingw.h" 1 3
# 33 "f:/K7_TOUR/CODE/Tools/MinGW/include/setjmp.h" 2 3
# 49 "f:/K7_TOUR/CODE/Tools/MinGW/include/setjmp.h" 3
typedef int jmp_buf[16];





 int __attribute__((__cdecl__)) _setjmp (jmp_buf);







 void __attribute__((__cdecl__)) longjmp (jmp_buf, int);
# 101 "../../../kal/include/clib.h" 2

typedef long long mtk_jmpbuf[6];
# 111 "../../../kal/include/clib.h"
char *strtok_r(char *s1, const char *s2, char **ptr);




# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 1 3
# 37 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 220 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 3 4
typedef unsigned int size_t;
# 332 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 3 4
typedef short unsigned int wchar_t;
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 38 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 2 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/sys/types.h" 1 3
# 38 "f:/K7_TOUR/CODE/Tools/MinGW/include/sys/types.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 158 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 39 "f:/K7_TOUR/CODE/Tools/MinGW/include/sys/types.h" 2 3





typedef long time_t;
# 53 "f:/K7_TOUR/CODE/Tools/MinGW/include/sys/types.h" 3
typedef long _off_t;


typedef _off_t off_t;







typedef unsigned int _dev_t;





typedef _dev_t dev_t;






typedef short _ino_t;


typedef _ino_t ino_t;






typedef int _pid_t;


typedef _pid_t pid_t;






typedef unsigned short _mode_t;


typedef _mode_t mode_t;






typedef int _sigset_t;


typedef _sigset_t sigset_t;





typedef long _ssize_t;


typedef _ssize_t ssize_t;
# 44 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 2 3
# 69 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
typedef long clock_t;
# 78 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
struct tm
{
        int tm_sec;
        int tm_min;
        int tm_hour;
        int tm_mday;
        int tm_mon;
        int tm_year;
        int tm_wday;
        int tm_yday;
        int tm_isdst;

};





 clock_t __attribute__((__cdecl__)) clock (void);
 time_t __attribute__((__cdecl__)) time (time_t*);
 double __attribute__((__cdecl__)) difftime (time_t, time_t);
 time_t __attribute__((__cdecl__)) mktime (struct tm*);
# 111 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
 char* __attribute__((__cdecl__)) asctime (const struct tm*);
 char* __attribute__((__cdecl__)) ctime (const time_t*);
 struct tm* __attribute__((__cdecl__)) gmtime (const time_t*);
 struct tm* __attribute__((__cdecl__)) localtime (const time_t*);


 size_t __attribute__((__cdecl__)) strftime (char*, size_t, const char*, const struct tm*);

 size_t __attribute__((__cdecl__)) wcsftime (wchar_t*, size_t, const wchar_t*, const struct tm*);


extern void __attribute__((__cdecl__)) _tzset (void);


extern void __attribute__((__cdecl__)) tzset (void);


 char* __attribute__((__cdecl__)) _strdate(char*);
 char* __attribute__((__cdecl__)) _strtime(char*);
# 142 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
extern int* __attribute__((__cdecl__)) __p__daylight (void);
extern long* __attribute__((__cdecl__)) __p__timezone (void);
extern char** __attribute__((__cdecl__)) __p__tzname (void);

extern __attribute__((dllimport)) int _daylight;
extern __attribute__((dllimport)) long _timezone;
extern __attribute__((dllimport)) char *_tzname[2];
# 180 "f:/K7_TOUR/CODE/Tools/MinGW/include/time.h" 3
extern __attribute__((dllimport)) int daylight;
extern __attribute__((dllimport)) long timezone;
extern __attribute__((dllimport)) char *tzname[2];





 wchar_t* __attribute__((__cdecl__)) _wasctime(const struct tm*);
 wchar_t* __attribute__((__cdecl__)) _wctime(const time_t*);
 wchar_t* __attribute__((__cdecl__)) _wstrdate(wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wstrtime(wchar_t*);
# 117 "../../../kal/include/clib.h" 2
struct tm *localtime_r(const time_t *timer, struct tm *result);
struct tm *gmtime_r(const time_t *timer, struct tm *result);


# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 1 3
# 42 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 361 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 3 4
typedef short unsigned int wint_t;
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 43 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 2 3

# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdarg.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stdarg.h" 1 3 4
# 44 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdarg.h" 2 3
# 45 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 2 3
# 151 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
typedef struct _iobuf
{
        char* _ptr;
        int _cnt;
        char* _base;
        int _flag;
        int _file;
        int _charbuf;
        int _bufsiz;
        char* _tmpfname;
} FILE;
# 176 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
extern __attribute__((dllimport)) FILE _iob[];
# 191 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) fopen (const char*, const char*);
 FILE* __attribute__((__cdecl__)) freopen (const char*, const char*, FILE*);
 int __attribute__((__cdecl__)) fflush (FILE*);
 int __attribute__((__cdecl__)) fclose (FILE*);

 int __attribute__((__cdecl__)) remove (const char*);
 int __attribute__((__cdecl__)) rename (const char*, const char*);
 FILE* __attribute__((__cdecl__)) tmpfile (void);
 char* __attribute__((__cdecl__)) tmpnam (char*);
 char* __attribute__((__cdecl__)) _tempnam (const char*, const char*);


 char* __attribute__((__cdecl__)) tempnam (const char*, const char*);


 int __attribute__((__cdecl__)) setvbuf (FILE*, char*, int, size_t);

 void __attribute__((__cdecl__)) setbuf (FILE*, char*);





 int __attribute__((__cdecl__)) fprintf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) printf (const char*, ...);
 int __attribute__((__cdecl__)) sprintf (char*, const char*, ...);
 int __attribute__((__cdecl__)) _snprintf (char*, size_t, const char*, ...);
 int __attribute__((__cdecl__)) vfprintf (FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) vprintf (const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) vsprintf (char*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) _vsnprintf (char*, size_t, const char*, __gnuc_va_list);


int __attribute__((__cdecl__)) snprintf(char* s, size_t n, const char* format, ...);
extern __inline__ int __attribute__((__cdecl__))
vsnprintf (char* s, size_t n, const char* format, __gnuc_va_list arg)
  { return _vsnprintf ( s, n, format, arg); }
int __attribute__((__cdecl__)) vscanf (const char * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) vfscanf (FILE * __restrict__, const char * __restrict__,
                     __gnuc_va_list);
int __attribute__((__cdecl__)) vsscanf (const char * __restrict__,
                     const char * __restrict__, __gnuc_va_list);






 int __attribute__((__cdecl__)) fscanf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) scanf (const char*, ...);
 int __attribute__((__cdecl__)) sscanf (const char*, const char*, ...);




 int __attribute__((__cdecl__)) fgetc (FILE*);
 char* __attribute__((__cdecl__)) fgets (char*, int, FILE*);
 int __attribute__((__cdecl__)) fputc (int, FILE*);
 int __attribute__((__cdecl__)) fputs (const char*, FILE*);
 int __attribute__((__cdecl__)) getc (FILE*);
 int __attribute__((__cdecl__)) getchar (void);
 char* __attribute__((__cdecl__)) gets (char*);
 int __attribute__((__cdecl__)) putc (int, FILE*);
 int __attribute__((__cdecl__)) putchar (int);
 int __attribute__((__cdecl__)) puts (const char*);
 int __attribute__((__cdecl__)) ungetc (int, FILE*);





 size_t __attribute__((__cdecl__)) fread (void*, size_t, size_t, FILE*);
 size_t __attribute__((__cdecl__)) fwrite (const void*, size_t, size_t, FILE*);





 int __attribute__((__cdecl__)) fseek (FILE*, long, int);
 long __attribute__((__cdecl__)) ftell (FILE*);
 void __attribute__((__cdecl__)) rewind (FILE*);
# 295 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
typedef long long fpos_t;




 int __attribute__((__cdecl__)) fgetpos (FILE*, fpos_t*);
 int __attribute__((__cdecl__)) fsetpos (FILE*, const fpos_t*);





 void __attribute__((__cdecl__)) clearerr (FILE*);
 int __attribute__((__cdecl__)) feof (FILE*);
 int __attribute__((__cdecl__)) ferror (FILE*);
 void __attribute__((__cdecl__)) perror (const char*);






 FILE* __attribute__((__cdecl__)) _popen (const char*, const char*);
 int __attribute__((__cdecl__)) _pclose (FILE*);


 FILE* __attribute__((__cdecl__)) popen (const char*, const char*);
 int __attribute__((__cdecl__)) pclose (FILE*);





 int __attribute__((__cdecl__)) _flushall (void);
 int __attribute__((__cdecl__)) _fgetchar (void);
 int __attribute__((__cdecl__)) _fputchar (int);
 FILE* __attribute__((__cdecl__)) _fdopen (int, const char*);
 int __attribute__((__cdecl__)) _fileno (FILE*);
 int __attribute__((__cdecl__)) _fcloseall(void);

 int __attribute__((__cdecl__)) _getmaxstdio(void);
 int __attribute__((__cdecl__)) _setmaxstdio(int);



 int __attribute__((__cdecl__)) fgetchar (void);
 int __attribute__((__cdecl__)) fputchar (int);
 FILE* __attribute__((__cdecl__)) fdopen (int, const char*);
 int __attribute__((__cdecl__)) fileno (FILE*);
# 352 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
 int __attribute__((__cdecl__)) fwprintf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) wprintf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) swprintf (wchar_t*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) _snwprintf (wchar_t*, size_t, const wchar_t*, ...);
 int __attribute__((__cdecl__)) vfwprintf (FILE*, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) vwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) vswprintf (wchar_t*, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) _vsnwprintf (wchar_t*, size_t, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) fwscanf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) wscanf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) swscanf (const wchar_t*, const wchar_t*, ...);
 wint_t __attribute__((__cdecl__)) fgetwc (FILE*);
 wint_t __attribute__((__cdecl__)) fputwc (wchar_t, FILE*);
 wint_t __attribute__((__cdecl__)) ungetwc (wchar_t, FILE*);


 wchar_t* __attribute__((__cdecl__)) fgetws (wchar_t*, int, FILE*);
 int __attribute__((__cdecl__)) fputws (const wchar_t*, FILE*);
 wint_t __attribute__((__cdecl__)) getwc (FILE*);
 wint_t __attribute__((__cdecl__)) getwchar (void);
 wchar_t* __attribute__((__cdecl__)) _getws (wchar_t*);
 wint_t __attribute__((__cdecl__)) putwc (wint_t, FILE*);
 int __attribute__((__cdecl__)) _putws (const wchar_t*);
 wint_t __attribute__((__cdecl__)) putwchar (wint_t);
 FILE* __attribute__((__cdecl__)) _wfdopen(int, wchar_t *);
 FILE* __attribute__((__cdecl__)) _wfopen (const wchar_t*, const wchar_t*);
 FILE* __attribute__((__cdecl__)) _wfreopen (const wchar_t*, const wchar_t*, FILE*);
 FILE* __attribute__((__cdecl__)) _wfsopen (const wchar_t*, const wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) _wtmpnam (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wtempnam (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) _wrename (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) _wremove (const wchar_t*);
 void __attribute__((__cdecl__)) _wperror (const wchar_t*);
 FILE* __attribute__((__cdecl__)) _wpopen (const wchar_t*, const wchar_t*);



int __attribute__((__cdecl__)) snwprintf (wchar_t* s, size_t n, const wchar_t* format, ...);
extern __inline__ int __attribute__((__cdecl__))
vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, __gnuc_va_list arg)
  { return _vsnwprintf ( s, n, format, arg);}
int __attribute__((__cdecl__)) vwscanf (const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) vfwscanf (FILE * __restrict__,
                       const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) vswscanf (const wchar_t * __restrict__,
                       const wchar_t * __restrict__, __gnuc_va_list);
# 406 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) wpopen (const wchar_t*, const wchar_t*);






 wint_t __attribute__((__cdecl__)) _fgetwchar (void);
 wint_t __attribute__((__cdecl__)) _fputwchar (wint_t);
 int __attribute__((__cdecl__)) _getw (FILE*);
 int __attribute__((__cdecl__)) _putw (int, FILE*);


 wint_t __attribute__((__cdecl__)) fgetwchar (void);
 wint_t __attribute__((__cdecl__)) fputwchar (wint_t);
 int __attribute__((__cdecl__)) getw (FILE*);
 int __attribute__((__cdecl__)) putw (int, FILE*);
# 122 "../../../kal/include/clib.h" 2
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdarg.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stdarg.h" 1 3 4
# 118 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdarg.h" 2 3
# 123 "../../../kal/include/clib.h" 2
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 1 3
# 33 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 1 3
# 36 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 37 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 2 3
# 62 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
 int __attribute__((__cdecl__)) isalnum(int);
 int __attribute__((__cdecl__)) isalpha(int);
 int __attribute__((__cdecl__)) iscntrl(int);
 int __attribute__((__cdecl__)) isdigit(int);
 int __attribute__((__cdecl__)) isgraph(int);
 int __attribute__((__cdecl__)) islower(int);
 int __attribute__((__cdecl__)) isprint(int);
 int __attribute__((__cdecl__)) ispunct(int);
 int __attribute__((__cdecl__)) isspace(int);
 int __attribute__((__cdecl__)) isupper(int);
 int __attribute__((__cdecl__)) isxdigit(int);


 int __attribute__((__cdecl__)) _isctype (int, int);



 int __attribute__((__cdecl__)) tolower(int);
 int __attribute__((__cdecl__)) toupper(int);
# 92 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
 int __attribute__((__cdecl__)) _tolower(int);
 int __attribute__((__cdecl__)) _toupper(int);







   extern __attribute__((dllimport)) int __mb_cur_max;
# 120 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
extern __attribute__((dllimport)) unsigned short _ctype[];

  extern __attribute__((dllimport)) unsigned short* _pctype;
# 187 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
typedef wchar_t wctype_t;



 int __attribute__((__cdecl__)) iswalnum(wint_t);
 int __attribute__((__cdecl__)) iswalpha(wint_t);
 int __attribute__((__cdecl__)) iswascii(wint_t);
 int __attribute__((__cdecl__)) iswcntrl(wint_t);
 int __attribute__((__cdecl__)) iswctype(wint_t, wctype_t);
 int __attribute__((__cdecl__)) is_wctype(wint_t, wctype_t);
 int __attribute__((__cdecl__)) iswdigit(wint_t);
 int __attribute__((__cdecl__)) iswgraph(wint_t);
 int __attribute__((__cdecl__)) iswlower(wint_t);
 int __attribute__((__cdecl__)) iswprint(wint_t);
 int __attribute__((__cdecl__)) iswpunct(wint_t);
 int __attribute__((__cdecl__)) iswspace(wint_t);
 int __attribute__((__cdecl__)) iswupper(wint_t);
 int __attribute__((__cdecl__)) iswxdigit(wint_t);

 wchar_t __attribute__((__cdecl__)) towlower(wchar_t);
 wchar_t __attribute__((__cdecl__)) towupper(wchar_t);

 int __attribute__((__cdecl__)) isleadbyte (int);
# 231 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
int __attribute__((__cdecl__)) __isascii (int);
int __attribute__((__cdecl__)) __toascii (int);
int __attribute__((__cdecl__)) __iscsymf (int);
int __attribute__((__cdecl__)) __iscsym (int);
# 245 "f:/K7_TOUR/CODE/Tools/MinGW/include/ctype.h" 3
int __attribute__((__cdecl__)) isascii (int);
int __attribute__((__cdecl__)) toascii (int);
int __attribute__((__cdecl__)) iscsymf (int);
int __attribute__((__cdecl__)) iscsym (int);
# 34 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 2 3

# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 1 3
# 38 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 39 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 2 3
# 86 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
extern int _argc;
extern char** _argv;




extern int* __attribute__((__cdecl__)) __p___argc(void);
extern char*** __attribute__((__cdecl__)) __p___argv(void);
extern wchar_t*** __attribute__((__cdecl__)) __p___wargv(void);
# 152 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
 int* __attribute__((__cdecl__)) _errno(void);


 int* __attribute__((__cdecl__)) __doserrno(void);







  extern char *** __attribute__((__cdecl__)) __p__environ(void);
  extern wchar_t *** __attribute__((__cdecl__)) __p__wenviron(void);
# 186 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
  extern __attribute__((dllimport)) int _sys_nerr;
# 210 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
extern __attribute__((dllimport)) char* _sys_errlist[];
# 224 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
extern unsigned __attribute__((__cdecl__)) int* __p__osver(void);
extern unsigned __attribute__((__cdecl__)) int* __p__winver(void);
extern unsigned __attribute__((__cdecl__)) int* __p__winmajor(void);
extern unsigned __attribute__((__cdecl__)) int* __p__winminor(void);







extern __attribute__((dllimport)) unsigned int _osver;
extern __attribute__((dllimport)) unsigned int _winver;
extern __attribute__((dllimport)) unsigned int _winmajor;
extern __attribute__((dllimport)) unsigned int _winminor;
# 275 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
 char** __attribute__((__cdecl__)) __p__pgmptr(void);

 wchar_t** __attribute__((__cdecl__)) __p__wpgmptr(void);
# 308 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
extern __attribute__((dllimport)) int _fmode;
# 324 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
 double __attribute__((__cdecl__)) atof (const char*);
 int __attribute__((__cdecl__)) atoi (const char*);
 long __attribute__((__cdecl__)) atol (const char*);
 int __attribute__((__cdecl__)) _wtoi (const wchar_t *);
 long __attribute__((__cdecl__)) _wtol (const wchar_t *);

 double __attribute__((__cdecl__)) strtod (const char*, char**);

extern __inline__ float __attribute__((__cdecl__)) strtof (const char *nptr, char **endptr)
  { return (strtod (nptr, endptr));}
long double __attribute__((__cdecl__)) strtold (const char * __restrict__, char ** __restrict__);


 long __attribute__((__cdecl__)) strtol (const char*, char**, int);
 unsigned long __attribute__((__cdecl__)) strtoul (const char*, char**, int);



 double __attribute__((__cdecl__)) wcstod (const wchar_t*, wchar_t**);

extern __inline__ float __attribute__((__cdecl__)) wcstof( const wchar_t *nptr, wchar_t **endptr)
{ return (wcstod(nptr, endptr)); }
long double __attribute__((__cdecl__)) wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);


 long __attribute__((__cdecl__)) wcstol (const wchar_t*, wchar_t**, int);
 unsigned long __attribute__((__cdecl__)) wcstoul (const wchar_t*, wchar_t**, int);



 size_t __attribute__((__cdecl__)) wcstombs (char*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) wctomb (char*, wchar_t);

 int __attribute__((__cdecl__)) mblen (const char*, size_t);
 size_t __attribute__((__cdecl__)) mbstowcs (wchar_t*, const char*, size_t);
 int __attribute__((__cdecl__)) mbtowc (wchar_t*, const char*, size_t);

 int __attribute__((__cdecl__)) rand (void);
 void __attribute__((__cdecl__)) srand (unsigned int);

 void* __attribute__((__cdecl__)) calloc (size_t, size_t);
 void* __attribute__((__cdecl__)) malloc (size_t);
 void* __attribute__((__cdecl__)) realloc (void*, size_t);
 void __attribute__((__cdecl__)) free (void*);

 void __attribute__((__cdecl__)) abort (void) __attribute__ ((noreturn));
 void __attribute__((__cdecl__)) exit (int) __attribute__ ((noreturn));


int __attribute__((__cdecl__)) atexit (void (*)(void));

 int __attribute__((__cdecl__)) system (const char*);
 char* __attribute__((__cdecl__)) getenv (const char*);


 void* __attribute__((__cdecl__)) bsearch (const void*, const void*, size_t, size_t,
                                 int (*)(const void*, const void*));
 void __attribute__((__cdecl__)) qsort (void*, size_t, size_t,
                                 int (*)(const void*, const void*));

 int __attribute__((__cdecl__)) abs (int);
 long __attribute__((__cdecl__)) labs (long);
# 395 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 div_t __attribute__((__cdecl__)) div (int, int);
 ldiv_t __attribute__((__cdecl__)) ldiv (long, long);







 void __attribute__((__cdecl__)) _beep (unsigned int, unsigned int);
 void __attribute__((__cdecl__)) _seterrormode (int);
 void __attribute__((__cdecl__)) _sleep (unsigned long);

 void __attribute__((__cdecl__)) _exit (int) __attribute__ ((noreturn));



typedef int (* _onexit_t)(void);
_onexit_t __attribute__((__cdecl__)) _onexit( _onexit_t );

 int __attribute__((__cdecl__)) _putenv (const char*);
 void __attribute__((__cdecl__)) _searchenv (const char*, const char*, char*);


 char* __attribute__((__cdecl__)) _ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) _fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) _gcvt (double, int, char*);

 void __attribute__((__cdecl__)) _makepath (char*, const char*, const char*, const char*, const char*);
 void __attribute__((__cdecl__)) _splitpath (const char*, char*, char*, char*, char*);
 char* __attribute__((__cdecl__)) _fullpath (char*, const char*, size_t);

 char* __attribute__((__cdecl__)) _itoa (int, char*, int);
 char* __attribute__((__cdecl__)) _ltoa (long, char*, int);
 char* __attribute__((__cdecl__)) _ultoa(unsigned long, char*, int);
 wchar_t* __attribute__((__cdecl__)) _itow (int, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) _ltow (long, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) _ultow (unsigned long, wchar_t*, int);


 long long __attribute__((__cdecl__)) _atoi64(const char *);
 char* __attribute__((__cdecl__)) _i64toa(long long, char *, int);
 char* __attribute__((__cdecl__)) _ui64toa(unsigned long long, char *, int);
 long long __attribute__((__cdecl__)) _wtoi64(const wchar_t *);
 wchar_t* __attribute__((__cdecl__)) _i64tow(long long, wchar_t *, int);
 wchar_t* __attribute__((__cdecl__)) _ui64tow(unsigned long long, wchar_t *, int);

 wchar_t* __attribute__((__cdecl__)) _wgetenv(const wchar_t*);
 int __attribute__((__cdecl__)) _wputenv(const wchar_t*);
 void __attribute__((__cdecl__)) _wsearchenv(const wchar_t*, const wchar_t*, wchar_t*);
 void __attribute__((__cdecl__)) _wmakepath(wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*);
 void __attribute__((__cdecl__)) _wsplitpath (const wchar_t*, wchar_t*, wchar_t*, wchar_t*, wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wfullpath (wchar_t*, const wchar_t*, size_t);

 unsigned int __attribute__((__cdecl__)) _rotl(unsigned int, int);
 unsigned int __attribute__((__cdecl__)) _rotr(unsigned int, int);
 unsigned long __attribute__((__cdecl__)) _lrotl(unsigned long, int);
 unsigned long __attribute__((__cdecl__)) _lrotr(unsigned long, int);




 int __attribute__((__cdecl__)) putenv (const char*);
 void __attribute__((__cdecl__)) searchenv (const char*, const char*, char*);

 char* __attribute__((__cdecl__)) itoa (int, char*, int);
 char* __attribute__((__cdecl__)) ltoa (long, char*, int);


 char* __attribute__((__cdecl__)) ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) gcvt (double, int, char*);
# 480 "f:/K7_TOUR/CODE/Tools/MinGW/include/stdlib.h" 3
void __attribute__((__cdecl__)) _Exit(int) __attribute__ ((noreturn));

extern __inline__ void __attribute__((__cdecl__)) _Exit(int status)
        { _exit(status); }


typedef struct { long long quot, rem; } lldiv_t;

lldiv_t __attribute__((__cdecl__)) lldiv (long long, long long);

extern __inline__ long long __attribute__((__cdecl__)) llabs(long long _j)
  {return (_j >= 0 ? _j : -_j);}

long long __attribute__((__cdecl__)) strtoll (const char* __restrict__, char** __restrict, int);
unsigned long long __attribute__((__cdecl__)) strtoull (const char* __restrict__, char** __restrict__, int);


long long __attribute__((__cdecl__)) atoll (const char *);


long long __attribute__((__cdecl__)) wtoll (const wchar_t *);
char* __attribute__((__cdecl__)) lltoa (long long, char *, int);
char* __attribute__((__cdecl__)) ulltoa (unsigned long long , char *, int);
wchar_t* __attribute__((__cdecl__)) lltow (long long, wchar_t *, int);
wchar_t* __attribute__((__cdecl__)) ulltow (unsigned long long, wchar_t *, int);


extern __inline__ long long __attribute__((__cdecl__)) atoll (const char * _c)
        { return _atoi64 (_c); }
extern __inline__ char* __attribute__((__cdecl__)) lltoa (long long _n, char * _c, int _i)
        { return _i64toa (_n, _c, _i); }
extern __inline__ char* __attribute__((__cdecl__)) ulltoa (unsigned long long _n, char * _c, int _i)
        { return _ui64toa (_n, _c, _i); }
extern __inline__ long long __attribute__((__cdecl__)) wtoll (const wchar_t * _w)
        { return _wtoi64 (_w); }
extern __inline__ wchar_t* __attribute__((__cdecl__)) lltow (long long _n, wchar_t * _w, int _i)
        { return _i64tow (_n, _w, _i); }
extern __inline__ wchar_t* __attribute__((__cdecl__)) ulltow (unsigned long long _n, wchar_t * _w, int _i)
        { return _ui64tow (_n, _w, _i); }
# 36 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 2 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 1 3
# 40 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 3
# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 41 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 2 3
# 52 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 3
 void* __attribute__((__cdecl__)) memchr (const void*, int, size_t);
 int __attribute__((__cdecl__)) memcmp (const void*, const void*, size_t);
 void* __attribute__((__cdecl__)) memcpy (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) memmove (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) memset (void*, int, size_t);
 char* __attribute__((__cdecl__)) strcat (char*, const char*);
 char* __attribute__((__cdecl__)) strchr (const char*, int);
 int __attribute__((__cdecl__)) strcmp (const char*, const char*);
 int __attribute__((__cdecl__)) strcoll (const char*, const char*);
 char* __attribute__((__cdecl__)) strcpy (char*, const char*);
 size_t __attribute__((__cdecl__)) strcspn (const char*, const char*);
 char* __attribute__((__cdecl__)) strerror (int);

 size_t __attribute__((__cdecl__)) strlen (const char*);
 char* __attribute__((__cdecl__)) strncat (char*, const char*, size_t);
 int __attribute__((__cdecl__)) strncmp (const char*, const char*, size_t);
 char* __attribute__((__cdecl__)) strncpy (char*, const char*, size_t);
 char* __attribute__((__cdecl__)) strpbrk (const char*, const char*);
 char* __attribute__((__cdecl__)) strrchr (const char*, int);
 size_t __attribute__((__cdecl__)) strspn (const char*, const char*);
 char* __attribute__((__cdecl__)) strstr (const char*, const char*);
 char* __attribute__((__cdecl__)) strtok (char*, const char*);
 size_t __attribute__((__cdecl__)) strxfrm (char*, const char*, size_t);





 char* __attribute__((__cdecl__)) _strerror (const char *);
 void* __attribute__((__cdecl__)) _memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) _memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) _strdup (const char*);
 int __attribute__((__cdecl__)) _strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) _stricmp (const char*, const char*);
 int __attribute__((__cdecl__)) _stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) _strlwr (char*);
 int __attribute__((__cdecl__)) _strnicmp (const char*, const char*, size_t);
 char* __attribute__((__cdecl__)) _strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) _strrev (char*);
 char* __attribute__((__cdecl__)) _strset (char*, int);
 char* __attribute__((__cdecl__)) _strupr (char*);
 void __attribute__((__cdecl__)) _swab (const char*, char*, size_t);


 int __attribute__((__cdecl__)) _strncoll(const char*, const char*, size_t);
 int __attribute__((__cdecl__)) _strnicoll(const char*, const char*, size_t);







 wchar_t* __attribute__((__cdecl__)) wcscat (wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcschr (const wchar_t*, wchar_t);
 int __attribute__((__cdecl__)) wcscmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) wcscoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcscpy (wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) wcscspn (const wchar_t*, const wchar_t*);

 size_t __attribute__((__cdecl__)) wcslen (const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcsncat (wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) wcsncmp(const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) wcsncpy(wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) wcspbrk(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcsrchr(const wchar_t*, wchar_t);
 size_t __attribute__((__cdecl__)) wcsspn(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcsstr(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcstok(wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) wcsxfrm(wchar_t*, const wchar_t*, size_t);
# 131 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) _wcsdup (const wchar_t*);
 int __attribute__((__cdecl__)) _wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) _wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) _wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) _wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) _wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) _wcsupr (wchar_t*);


 int __attribute__((__cdecl__)) _wcsncoll(const wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) _wcsnicoll(const wchar_t*, const wchar_t*, size_t);
# 159 "f:/K7_TOUR/CODE/Tools/MinGW/include/string.h" 3
 void* __attribute__((__cdecl__)) memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) strdup (const char*);
 int __attribute__((__cdecl__)) strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) stricmp (const char*, const char*);
extern __inline__ int __attribute__((__cdecl__))
strcasecmp (const char * __sz1, const char * __sz2)
  {return _stricmp (__sz1, __sz2);}
 int __attribute__((__cdecl__)) stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) strlwr (char*);
 int __attribute__((__cdecl__)) strnicmp (const char*, const char*, size_t);
extern __inline__ int __attribute__((__cdecl__))
strncasecmp (const char * __sz1, const char * __sz2, size_t __sizeMaxCompare)
  {return _strnicmp (__sz1, __sz2, __sizeMaxCompare);}
 char* __attribute__((__cdecl__)) strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) strrev (char*);
 char* __attribute__((__cdecl__)) strset (char*, int);
 char* __attribute__((__cdecl__)) strupr (char*);

 void __attribute__((__cdecl__)) swab (const char*, char*, size_t);



extern __inline__ int __attribute__((__cdecl__))
wcscmpi (const wchar_t * __ws1, const wchar_t * __ws2)
  {return _wcsicmp (__ws1, __ws2);}
 wchar_t* __attribute__((__cdecl__)) wcsdup (wchar_t*);
 int __attribute__((__cdecl__)) wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) wcsupr (wchar_t*);
# 37 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 2 3







# 1 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 1 3





# 1 "f:/K7_TOUR/CODE/Tools/MinGW/lib/gcc-lib/mingw32/3.3.1/include/stddef.h" 1 3 4
# 7 "f:/K7_TOUR/CODE/Tools/MinGW/include/stddef.h" 2 3
# 45 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 2 3
# 59 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
typedef unsigned long _fsize_t;




struct _wfinddata_t {
        unsigned attrib;
        time_t time_create;
        time_t time_access;
        time_t time_write;
        _fsize_t size;
        wchar_t name[(260)];
};
struct _wfinddatai64_t {
    unsigned attrib;
    time_t time_create;
    time_t time_access;
    time_t time_write;
    long long size;
    wchar_t name[(260)];
};
# 88 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
 int __attribute__((__cdecl__)) _waccess (const wchar_t*, int);
 int __attribute__((__cdecl__)) _wchmod (const wchar_t*, int);
 int __attribute__((__cdecl__)) _wcreat (const wchar_t*, int);
 long __attribute__((__cdecl__)) _wfindfirst (const wchar_t*, struct _wfinddata_t *);
 int __attribute__((__cdecl__)) _wfindnext (long, struct _wfinddata_t *);
 int __attribute__((__cdecl__)) _wunlink (const wchar_t*);
 int __attribute__((__cdecl__)) _wopen (const wchar_t*, int, ...);
 int __attribute__((__cdecl__)) _wsopen (const wchar_t*, int, int, ...);
 wchar_t* __attribute__((__cdecl__)) _wmktemp (wchar_t*);
 long __attribute__((__cdecl__)) _wfindfirsti64 (const wchar_t*, struct _wfinddatai64_t*);
 int __attribute__((__cdecl__)) _wfindnexti64 (long, struct _wfinddatai64_t*);
# 159 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
 int __attribute__((__cdecl__)) _wchdir (const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) _wgetcwd (wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) _wgetdcwd (int, wchar_t*, int);
 int __attribute__((__cdecl__)) _wmkdir (const wchar_t*);
 int __attribute__((__cdecl__)) _wrmdir (const wchar_t*);
# 176 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
struct _stat
{
        _dev_t st_dev;
        _ino_t st_ino;
        _mode_t st_mode;
        short st_nlink;
        short st_uid;
        short st_gid;
        _dev_t st_rdev;
        _off_t st_size;
        time_t st_atime;

        time_t st_mtime;
        time_t st_ctime;
};

struct stat
{
        _dev_t st_dev;
        _ino_t st_ino;
        _mode_t st_mode;
        short st_nlink;
        short st_uid;
        short st_gid;
        _dev_t st_rdev;
        _off_t st_size;
        time_t st_atime;

        time_t st_mtime;
        time_t st_ctime;
};

struct _stati64 {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    long long st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
    };







 int __attribute__((__cdecl__)) _wstat (const wchar_t*, struct _stat*);
 int __attribute__((__cdecl__)) _wstati64 (const wchar_t*, struct _stati64*);
# 247 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
 wchar_t* __attribute__((__cdecl__)) _wsetlocale (int, const wchar_t*);
# 288 "f:/K7_TOUR/CODE/Tools/MinGW/include/wchar.h" 3
typedef int mbstate_t;
typedef wchar_t _Wint_t;

wint_t __attribute__((__cdecl__)) btowc(int);
size_t __attribute__((__cdecl__)) mbrlen(const char *, size_t, mbstate_t *);
size_t __attribute__((__cdecl__)) mbrtowc(wchar_t *, const char *, size_t, mbstate_t *);
size_t __attribute__((__cdecl__)) mbsrtowcs(wchar_t *, const char **, size_t, mbstate_t *);

size_t __attribute__((__cdecl__)) wcrtomb(char *, wchar_t, mbstate_t *);
size_t __attribute__((__cdecl__)) wcsrtombs(char *, const wchar_t **, size_t, mbstate_t *);
int __attribute__((__cdecl__)) wctob(wint_t);


extern __inline__ int __attribute__((__cdecl__)) fwide(FILE* stream, int mode) {return -1;}
extern __inline__ int __attribute__((__cdecl__)) mbsinit(const mbstate_t* ps) {return 1;}
wchar_t* __attribute__((__cdecl__)) wmemset(wchar_t* s, wchar_t c, size_t n);
wchar_t* __attribute__((__cdecl__)) wmemchr(const wchar_t* s, wchar_t c, size_t n);
int wmemcmp(const wchar_t* s1, const wchar_t * s2, size_t n);
wchar_t* __attribute__((__cdecl__)) wmemcpy(wchar_t* __restrict__ s1, const wchar_t* __restrict__ s2,
                 size_t n);
wchar_t* __attribute__((__cdecl__)) wmemmove(wchar_t* s1, const wchar_t* s2, size_t n);
long long __attribute__((__cdecl__)) wcstoll(const wchar_t* __restrict__ nptr,
                  wchar_t** __restrict__ endptr, int base);
unsigned long long __attribute__((__cdecl__)) wcstoull(const wchar_t* __restrict__ nptr,
                            wchar_t ** __restrict__ endptr, int base);
# 124 "../../../kal/include/clib.h" 2


#pragma diag_error 1361,2570 





# 1 "../../../kal/include/clib_list.h" 1
# 92 "../../../kal/include/clib_list.h"
void *__alloca(size_t size) __attribute__((deprecated)) ;







void (*signal (int sig, void (* func )(int)))(int) __attribute__((deprecated)) ;
int raise(int sig) __attribute__((deprecated)) ;


int remove(const char * filename) __attribute__((deprecated)) ;
int rename(const char * old, const char * newname) __attribute__((deprecated)) ;
FILE *tmpfile(void) __attribute__((deprecated)) ;
char *tmpnam(char * s) __attribute__((deprecated)) ;
# 172 "../../../kal/include/clib_list.h"
void *calloc(size_t nmemb, size_t size) __attribute__((deprecated));
void free(void * ptr) __attribute__((deprecated));
void *malloc(size_t size) __attribute__((deprecated));
void *realloc(void * ptr, size_t size) __attribute__((deprecated));

int atexit(void (* func)(void)) __attribute__((deprecated));
void exit(int status) __attribute__((deprecated)) ;
void _Exit(int status) __attribute__((deprecated)) ;
char *getenv(const char * name) __attribute__((deprecated));
int system(const char * string) __attribute__((deprecated)) ;


char *strtok(char * __restrict s1, const char * __restrict s2) __attribute__((deprecated)) ;


struct tm;
char *asctime(const struct tm * timeptr) __attribute__((deprecated)) ;
char *ctime(const time_t * timer) __attribute__((deprecated)) ;
struct tm *gmtime(const time_t * timer) __attribute__((deprecated)) ;
struct tm *localtime(const time_t * timer) __attribute__((deprecated)) ;
# 133 "../../../kal/include/clib.h" 2
# 149 "../../../kal/include/clib.h"
void clib_basic_init(void);
void clib_init(void);
# 83 "../../../kal/include/kal_general_types.h" 2






typedef char kal_char;

typedef unsigned short kal_wchar;


typedef unsigned char kal_uint8;

typedef signed char kal_int8;

typedef unsigned short int kal_uint16;

typedef signed short int kal_int16;

typedef unsigned int kal_uint32;

typedef signed int kal_int32;
# 113 "../../../kal/include/kal_general_types.h"
   typedef unsigned long long kal_uint64;

   typedef signed long long kal_int64;



typedef enum
{

    KAL_FALSE,

    KAL_TRUE
} kal_bool;


typedef unsigned short WCHAR;
# 38 "../../../custom/drv/lcd/hexing60a_11b_lcm/lcd_hw.h" 2
# 80 "../../../custom/drv/lcd/hexing60a_11b_lcm/lcd_hw.h"
typedef struct {
        kal_uint8 addr;
        kal_uint8 data;
} lcd_init_setting;
# 68 "../../../custom/common/hal_public/lcd_sw_inc.h" 2
# 236 "../../../hal/drv_def/drv_features_mdp.h" 2
# 1 "../../../custom/drv/camera_common/sensor_capability.h" 1
# 237 "../../../hal/drv_def/drv_features_mdp.h" 2
# 303 "../../../hal/drv_def/drv_features_g2d.h" 2
# 202 "../../../interface/hal/drv_sw_def/drv_sw_features_display.h" 2
# 383 "../../framework/gdi/gdiinc/gdi_features.h" 2
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_g2d.h" 1
# 384 "../../framework/gdi/gdiinc/gdi_features.h" 2
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_jpeg.h" 1
# 75 "../../../interface/hal/drv_sw_def/drv_sw_features_jpeg.h"
# 1 "../../../hal/drv_def/drv_features_jpeg.h" 1
# 76 "../../../interface/hal/drv_sw_def/drv_sw_features_jpeg.h" 2
# 385 "../../framework/gdi/gdiinc/gdi_features.h" 2
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_gif.h" 1
# 78 "../../../interface/hal/drv_sw_def/drv_sw_features_gif.h"
# 1 "../../../hal/drv_def/drv_features_gif.h" 1
# 79 "../../../interface/hal/drv_sw_def/drv_sw_features_gif.h" 2
# 386 "../../framework/gdi/gdiinc/gdi_features.h" 2
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_mdp.h" 1
# 387 "../../framework/gdi/gdiinc/gdi_features.h" 2
# 4 "temp/res/SmsAppRes.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_SMS">
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,mmi_rp_app_unifiedmessage_def.h,mmi_rp_srv_editor_def.h,gui_config.h"/>

    <!---------------------String Resource Area----------------------------------------------------->
    <!---------------------String Resource Area----------------------------------------------------->
    <!-------------String Resource for Voicemail begin---------------------------------------------->

    <STRING id="STR_ID_SMS_VM_VMAIL_MENUENTRY"/>
# 41 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_VM_VOICEMAIL_IND"/>
    <STRING id="STR_ID_SMS_VM_FAX_IND"/>
    <STRING id="STR_ID_SMS_VM_EMAIL_IND"/>
    <STRING id="STR_ID_SMS_VM_NET_OTHER_IND"/>
    <STRING id="STR_ID_SMS_VM_VIDEO_IND"/>

    <STRING id="STR_ID_SMS_VM_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_ID_SMS_VM_FAX_NUM_IND"/>
    <STRING id="STR_ID_SMS_VM_EMAIL_NUM_IND"/>
    <STRING id="STR_ID_SMS_VM_NET_OTHER_NUM_IND"/>
    <STRING id="STR_ID_SMS_VM_VIDEO_NUM_IND"/>

    <STRING id="STR_ID_SMS_VM_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_SMS_VM_FAX_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_SMS_VM_EMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_SMS_VM_NET_OTHER_NUM_IND_PLURAL"/>
    <STRING id="STR_ID_SMS_VM_VIDEO_NUM_IND_PLURAL"/>
# 83 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_VM_VOICE_MAIL_NAME"/>
    <STRING id="STR_ID_SMS_VM_VOICE_MAIL_NUM"/>




    <STRING id="STR_ID_SMS_VM_VOICE_MAIL_NOT_READY_YET"/>

    <STRING id="STR_ID_SMS_VM_SET_VOICEMAIL_QUERY_ID"/>
        <STRING id="STR_ID_SMS_VM_EDIT_VM"/>

    <!-------------String Resource for Voicemail end------------------------------------------------>
    <!-------------String Resource for SMS template begin------------------------------------------->
# 115 "temp/res/SmsAppRes.c"
        <STRING id="STR_ID_SMS_EDIT_PROFILE"/>

    <STRING id="STR_ID_SMS_FDN_FAIL"/>
# 214 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_SCRN_T0_CAPTION"/>
    <STRING id="STR_ID_SMS_TEMPL_OPTIONS_WRITE_MESSAGE"/>
    <STRING id="STR_ID_SMS_SMS_TEMPLATES_MENUENTRY"/>
# 226 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_TEMPLATE_1"/>
    <STRING id="STR_ID_SMS_TEMPLATE_2"/>
    <STRING id="STR_ID_SMS_TEMPLATE_3"/>
    <STRING id="STR_ID_SMS_TEMPLATE_4"/>
    <STRING id="STR_ID_SMS_TEMPLATE_5"/>
    <STRING id="STR_ID_SMS_TEMPLATE_6"/>
    <STRING id="STR_ID_SMS_TEMPLATE_7"/>
    <STRING id="STR_ID_SMS_TEMPLATE_8"/>
    <STRING id="STR_ID_SMS_TEMPLATE_9"/>
    <STRING id="STR_ID_SMS_TEMPLATE_10"/>


    <STRING id="STR_ID_SMS_SCRN_T4_EDIT_TEMPLATE_CAPTION"/>






    <!-------------String Resource for SMS template end---------------------------------------------->
    <!-------------String Resource for SMS setting begin--------------------------------------------->

    <STRING id="STR_ID_SMS_MESSAGESETUP_MENUENTRY"/>


    <STRING id="STR_ID_SMS_MEMSTATUS_PREFIX_SIM"/>
    <STRING id="STR_ID_SMS_MEMSTATUS_PREFIX_PHONE"/>


    <STRING id="STR_ID_SMS_PREFERED_BEARER_MENUENTRY"/>
    <STRING id="STR_ID_SMS_PREFERED_BEARER_TITLEENTRY"/>
    <STRING id="STR_ID_SMS_PREFER_GPRS_BEARER_MENUENTRY"/>
    <STRING id="STR_ID_SMS_PREFER_GSM_BEARER_MENUENTRY"/>
    <STRING id="STR_ID_SMS_GSM_BEARER_MENUENTRY"/>
# 270 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_PROFILE_NAME"/>

    <STRING id="STR_ID_SMS_PROFILE_SC"/>

    <STRING id="STR_ID_SMS_PROFILE_VP"/>


    <STRING id="STR_ID_SMS_PROFILE_MSG_TYPE"/>


    <STRING id="STR_ID_SMS_VP_1HOUR_MENUENTRY"/>
    <STRING id="STR_ID_SMS_VP_6HOUR_MENUENTRY"/>
    <STRING id="STR_ID_SMS_VP_12HOUR_MENUENTRY"/>
    <STRING id="STR_ID_SMS_VP_24HOUR_MENUENTRY"/>
    <STRING id="STR_ID_SMS_VP_3DAY_MENUENTRY"/>
    <STRING id="STR_ID_SMS_VP_1WEEK_MENUENTRY"/>


    <STRING id="STR_ID_SMS_TYPE_FAX_MENUENTRY"/>
    <STRING id="STR_ID_SMS_TYPE_GROUP4_FAX_MENUENTRY"/>
    <STRING id="STR_ID_SMS_TYPE_PAGE_MENUENTRY"/>





    <STRING id="STR_ID_SMS_PROFILE_SETTING_MENUENTRY"/>

    <STRING id="STR_ID_SMS_SET0_MENUENTRY"/>
    <STRING id="STR_ID_SMS_SET1_MENUENTRY"/>
    <STRING id="STR_ID_SMS_SET2_MENUENTRY"/>
    <STRING id="STR_ID_SMS_SET3_MENUENTRY"/>
    <STRING id="STR_ID_SMS_COMMONSETTING_MENUENTRY"/>
# 316 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_REPLY_PATH_MENUENTRY"/>






    <!-------------String Resource for SMS setting end-------------------------------------->

    <!-------------String Resource for SMS List Viewer begin-------------------------------->
# 334 "temp/res/SmsAppRes.c"
    <STRING id="STR_RECEIVED_SMS"/>
# 349 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_MESSAGES"/>






    <STRING id="STR_ID_SMS_REPLY_BY_SMS"/>
    <STRING id="STR_ID_SMS_REPLY_BY_MMS"/>


    <STRING id="STR_ID_SMS_USE_NUM_ADDRESS"/>
    <STRING id="STR_ID_SMS_USE_USSD_ADDRESS"/>

    <STRING id="STR_ID_SMS_SEND_USSD"/>





    <STRING id="STR_ID_SMS_USE_EMAIL_ADDRESS"/>
# 381 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_MARK_AS_READ"/>
    <STRING id="STR_ID_SMS_MARK_AS_UNREAD"/>






    <STRING id="STR_ID_SMS_COPY_ALL"/>
    <STRING id="STR_ID_SMS_MOVE_ALL"/>
# 408 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_COPY_TO_SIM"/>
    <STRING id="STR_ID_SMS_MOVE_TO_SIM"/>
    <STRING id="STR_ID_SMS_FROM_SIM"/>
    <STRING id="STR_ID_SMS_FROM_PHONE"/>

    <STRING id="STR_ID_SMS_COPY_TO_PHONE"/>
    <STRING id="STR_ID_SMS_MOVE_TO_PHONE"/>
    <STRING id="STR_ID_SMS_MESSAGE_COPIED"/>
    <STRING id="STR_ID_SMS_MESSAGES_COPIED"/>

    <STRING id="STR_ID_SMS_MESSAGE_MOVED"/>
    <STRING id="STR_ID_SMS_MESSAGES_MOVED"/>



    <STRING id="STR_ID_SMS_NO_MESSAGE_COPIED"/>
    <STRING id="STR_ID_SMS_NO_MESSAGE_MOVED"/>




    <STRING id="STR_ID_SMS_AUTO_FIND_ON"/>
    <STRING id="STR_ID_SMS_AUTO_FIND_OFF"/>
    <STRING id="STR_ID_SMS_USE_OBJECT"/>
    <STRING id="STR_ID_SMS_SAVE_AS_OBJECT"/>






    <!-------------String Resource for SMS List Viewer end---------------------------------->

    <!-------------String Resource for SMS Editor begin------------------------------------->

    <STRING id="STR_ID_SMS_SEND_TO"/>



    <STRING id="STR_ID_SMS_INSERT_NUMBER"/>
    <STRING id="STR_ID_SMS_INSERT_NAME"/>




    <STRING id="STR_ID_SMS_INSERT_TEMPLATE"/>



    <STRING id="STR_ID_SMS_ADD_RECIPIENT"/>
    <STRING id="STR_ID_SMS_EDIT_RECIPIENT"/>
    <STRING id="STR_ID_SMS_REMOVE_RECIPIENT"/>
    <STRING id="STR_ID_SMS_REMOVE_ALL_RECIPIENT"/>
    <STRING id="STR_ID_SMS_REMOVE_RECIPIENT_QUERY"/>
    <STRING id="STR_ID_SMS_REMOVE_ALL_RECIPIENT_QUERY"/>
    <STRING id="STR_ID_SMS_ENTER_NUMBER"/>



    <STRING id="STR_ID_SMS_ADD_FROM_CONTACTS"/>
    <STRING id="STR_ID_SMS_RECIPIENTS_FULL"/>
    <STRING id="STR_ID_SMS_INVLAID_NUMBERS_REMOVED"/>




    <STRING id="STR_ID_SMS_CAN_ONLY_ADD_FIRST"/>
    <STRING id="STR_ID_SMS_CAN_ONLY_SEND_TO_FIRST"/>
    <STRING id="STR_ID_SMS_CONTACT_CONTINUE_QUERY"/>
    <STRING id="STR_ID_SMS_CONTACTS_CONTINUE_QUERY"/>
# 490 "temp/res/SmsAppRes.c"
<STRING id="STR_ID_SMS_FROM_LOWER_CASE"/>





<STRING id="STR_ID_SMS_FAILED_TO_SEND_TO"/>
<STRING id="STR_ID_SMS_SUCCESSFUL_TO_SEND_TO"/>
# 514 "temp/res/SmsAppRes.c"
    <!-------------String Resource for SMS Editor end--------------------------------------->

    <!-------------String Resource for EMS begin-------------------------------------------->

    <STRING id="STR_OPT_INS_OBJECT_MENUENTRY"/>
    <STRING id="STR_EMS_FORMATING_TEXT_ID"/>
    <STRING id="STR_INS_OBJ_MY_PICTURE"/>
    <STRING id="STR_INS_OBJ_PRED_ANIMATION"/>
    <STRING id="STR_INS_OBJ_MY_ANIMATION"/>

    <STRING id="STR_INS_OBJ_MELODY"/>
    <STRING id="STR_INS_OBJ_MY_MELODY"/>

    <STRING id="STR_INS_OBJ_MY_SOUND"/>

    <STRING id="STR_EMS_TEXT_SIZE_ID"/>

    <STRING id="STR_EMS_TEXT_STYLE_ID"/>
    <STRING id="STR_EMS_ALIGNMENT_ID"/>
    <STRING id="STR_EMS_NEW_PARAGRAPH_ID"/>


    <STRING id="STR_EMS_TEXT_SIZE_SMALL_ID"/>

    <STRING id="STR_EMS_TEXT_SIZE_LARGE_ID"/>




    <STRING id="STR_EMS_TEXT_STYLE_BOLD_ID"/>

    <STRING id="STR_EMS_TEXT_STYLE_ITALICS_ID"/>
    <STRING id="STR_EMS_TEXT_STYLE_UNDERLINE_ID"/>
    <STRING id="STR_EMS_TEXT_STYLE_STRIKETHROUGH_ID"/>

    <STRING id="STR_EMS_ALIGNMENT_LEFT_ID"/>
    <STRING id="STR_EMS_ALIGNMENT_CENTER_ID"/>
    <STRING id="STR_EMS_ALIGNMENT_RIGHT_ID"/>

    <STRING id="STR_EMS_NEW_PARAGRAPH_LEFT_ID"/>
    <STRING id="STR_EMS_NEW_PARAGRAPH_CENTER_ID"/>
    <STRING id="STR_EMS_NEW_PARAGRAPH_RIGHT_ID"/>

    <STRING id="STR_EMS_OBJECT_LIST"/>

    <STRING id="STR_EMS_OBJECT_DUPLICATED_NAME_INPUT_AGAIN"/>


    <STRING id="STR_MANUFACTURER_PICTURE_0"/>
    <STRING id="STR_MANUFACTURER_PICTURE_1"/>
    <STRING id="STR_MANUFACTURER_PICTURE_2"/>
    <STRING id="STR_MANUFACTURER_PICTURE_3"/>
    <STRING id="STR_MANUFACTURER_PICTURE_4"/>
    <STRING id="STR_MANUFACTURER_PICTURE_5"/>
    <STRING id="STR_MANUFACTURER_PICTURE_6"/>
    <STRING id="STR_MANUFACTURER_PICTURE_7"/>
    <STRING id="STR_MANUFACTURER_PICTURE_8"/>
    <STRING id="STR_MANUFACTURER_PICTURE_9"/>

    <STRING id="STR_MANUFACTURER_MELODIES_0"/>
    <STRING id="STR_MANUFACTURER_MELODIES_1"/>
    <STRING id="STR_MANUFACTURER_MELODIES_2"/>
    <STRING id="STR_MANUFACTURER_MELODIES_3"/>
    <STRING id="STR_MANUFACTURER_MELODIES_4"/>
    <STRING id="STR_MANUFACTURER_MELODIES_5"/>
    <STRING id="STR_MANUFACTURER_MELODIES_6"/>
    <STRING id="STR_MANUFACTURER_MELODIES_7"/>
    <STRING id="STR_MANUFACTURER_MELODIES_8"/>
    <STRING id="STR_MANUFACTURER_MELODIES_9"/>

    <STRING id="STR_PREDEFINED_ANIMATION_0"/>
    <STRING id="STR_PREDEFINED_ANIMATION_1"/>
    <STRING id="STR_PREDEFINED_ANIMATION_2"/>
    <STRING id="STR_PREDEFINED_ANIMATION_3"/>
    <STRING id="STR_PREDEFINED_ANIMATION_4"/>
    <STRING id="STR_PREDEFINED_ANIMATION_5"/>
    <STRING id="STR_PREDEFINED_ANIMATION_6"/>
    <STRING id="STR_PREDEFINED_ANIMATION_7"/>
    <STRING id="STR_PREDEFINED_ANIMATION_8"/>
    <STRING id="STR_PREDEFINED_ANIMATION_9"/>
    <STRING id="STR_PREDEFINED_ANIMATION_10"/>
    <STRING id="STR_PREDEFINED_ANIMATION_11"/>
    <STRING id="STR_PREDEFINED_ANIMATION_12"/>
    <STRING id="STR_PREDEFINED_ANIMATION_13"/>
    <STRING id="STR_PREDEFINED_ANIMATION_14"/>

    <STRING id="STR_PREDEFINED_SOUND_0"/>
    <STRING id="STR_PREDEFINED_SOUND_1"/>
    <STRING id="STR_PREDEFINED_SOUND_2"/>
    <STRING id="STR_PREDEFINED_SOUND_3"/>
    <STRING id="STR_PREDEFINED_SOUND_4"/>
    <STRING id="STR_PREDEFINED_SOUND_5"/>
    <STRING id="STR_PREDEFINED_SOUND_6"/>
    <STRING id="STR_PREDEFINED_SOUND_7"/>
    <STRING id="STR_PREDEFINED_SOUND_8"/>
    <STRING id="STR_PREDEFINED_SOUND_9"/>

    <STRING id="STR_EMS_OBJECT_SIZE_NOT_ALLOWED_ID"/>
    <STRING id="STR_EMS_OBJECT_NUM_EXCEED"/>


    <!-------------String Resource for EMS------ end--------------------------------------->

    <!-------------String Resource for other------ begin----------------------------------->


    <STRING id="STR_ID_SMS_SET_SC_NUMBER_QUERY"/>




    <STRING id="STR_ID_SMS_SENDING_TO_CAPTION"/>

    <STRING id="STR_SMS_MESSAGE_HEADER_TO"/>





    <STRING id="STR_MMS_MENUENTRY"/>


    <STRING id="STR_ID_SMS_SAVE_SENT_SMS"/>

    <STRING id="STR_SMS_BACKGROUND_CANCELSEND_SMS_ID"/>
    <STRING id="STR_SMS_BACKGROUND_NOT_EXIST_ID"/>
    <STRING id="STR_SMS_BACKGROUND_STATUS_CHANGED_ID"/>

    <STRING id="STR_ID_SMS_BG_NO_DESTIATION_MOVE_TO_DRAFT_QUERY"/>
# 655 "temp/res/SmsAppRes.c"
    <STRING id="STR_SMS_MSG_NOT_READY_YET"/>

    <STRING id="STR_CLASS0_MESSAGE_CAPTION"/>
# 669 "temp/res/SmsAppRes.c"
    <STRING id="STR_NOUSSD_NOTIFICATION"/>
    <STRING id="STR_ID_SMS_CANCELLED"/>
    <STRING id="STR_ID_SMS_MESSAGES_UPDATED"/>







    <STRING id="STR_MESSAGES_ERACE_Q_ID"/>

    <STRING id="STR_SR_DELIVERD_ID"/>
    <STRING id="STR_SR_PENDING_ID"/>
    <STRING id="STR_INBOX_REPORT_ID"/>


    <STRING id="STR_WMESSAGE_MENUENTRY"/>




    <STRING id="STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM"/>

    <STRING id="STR_ID_SMS_SAVE_TO_INBOX"/>

    <STRING id="STR_SCR6024_CAPTION"/>






    <STRING id="STR_USE_EMAIL_ADDRESS_MENUENTRY"/>
    <STRING id="STR_USE_EMAIL_ADDRESS_LIST_CAPTION"/>
    <STRING id="STR_NO_EMAIL_ADDRESS_NOTIFICATION"/>
    <STRING id="STR_ID_SMS_USE_EMAIL_OPT_SEND"/>
# 719 "temp/res/SmsAppRes.c"
    <STRING id="STR_VOICEMAIL_IND"/>
    <STRING id="STR_FAX_IND"/>
    <STRING id="STR_EMAIL_IND"/>
    <STRING id="STR_NET_OTHER_IND"/>
    <STRING id="STR_VOICEMAIL_NUM_IND"/>
    <STRING id="STR_FAX_NUM_IND"/>
    <STRING id="STR_EMAIL_NUM_IND"/>
    <STRING id="STR_NET_OTHER_NUM_IND"/>
    <STRING id="STR_VOICEMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_FAX_NUM_IND_PLURAL"/>
    <STRING id="STR_EMAIL_NUM_IND_PLURAL"/>
    <STRING id="STR_NET_OTHER_NUM_IND_PLURAL"/>


    <STRING id="STR_SUCCESS_CAPTION"/>
    <STRING id="STR_FAILURE_CAPTION"/>




    <STRING id="STR_SCR6042_CAPTION"/>

    <STRING id="STR_SMS_MEMORY_EXCEEDED"/>
    <STRING id="STR_SMS_SIM_MEMORY_EXCEEDED"/>





    <STRING id="STR_SMS_SEND_SUCESS_SAVE_FAILED"/>

    <STRING id="STR_SMS_SEND_SAVE_FAILED"/>



    <STRING id="STR_NEW_MESSAGE_FROM_ID"/>


    <STRING id="STR_READ_SMS_DATA_FAILED"/>
    <STRING id="STR_SMS_OBJECT_EXISTENCE_ERROR"/>



    <STRING id="STR_MESSAGES_UNKNOWN_ERROR"/>

    <STRING id="STR_NO_SPACE_TO_INSERT_OBJECT"/>
    <STRING id="STR_SMS_FAILURE_MSG_LEN_EXCEEDED"/>

    <STRING id="STR_SMS_NUM_LEN_EXCEEDED"/>


    <STRING id="STR_SMS_NAME_CANNOT_BE_EMPTY"/>







    <STRING id="STR_SMS_CALL_SENDER"/>
    <STRING id="STR_SMS_FAILURE_DATA_EMPTY"/>
    <STRING id="STR_SMS_FAILURE_DATA_INVALID"/>
    <STRING id="STR_SMS_FAILURE_DATA_EXCEED"/>
    <STRING id="STR_SMS_FAILURE_SC_NUM_EMPTY"/>







    <STRING id="STR_DELETE_SMS_QUERY_ID"/>
# 822 "temp/res/SmsAppRes.c"
    <STRING id="STR_ID_SMS_INVALID_RECIPIENT"/>
    <STRING id="STR_ID_SMS_TO_RECIPIENT"/>
# 833 "temp/res/SmsAppRes.c"
        <STRING id="STR_ID_SMS_COUNTER_RECEIVED"/>
    <STRING id="STR_ID_SMS_COUNTER_SENT"/>
        <STRING id="STR_ID_SMS_COUNTER"/>
    <STRING id="STR_ID_SMS_RESET_COUNTER_QUERY"/>


    <!-------------String Resource for other------ end-------------------------------------->



    <!-------------Image Resource Area------------------------------------------------------>
    <!-------------Image Resource Area------------------------------------------------------>
    <!-------------Image Resource for Voicemail begin--------------------------------------->



    <IMAGE id="IMG_SMS_VMAIL_MENUENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_VOICE.bmp"</IMAGE>


    <!-------------Image Resource for Voicemail end----------------------------------------->
    <!-------------Image Resource for SMS template begin------------------------------------>







    <!-------------Image Resource for SMS template end-------------------------------------->
    <!-------------Image Resource for SMS setting begin------------------------------------->







    <IMAGE id="IMG_ID_SMS_MSG_SETTINGS_MENUENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_SET.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SMS_PROFILE_NAME">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_PRO.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SMS_PROFILE_SC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_PHONE.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SMS_PROFILE_VP">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_TIME.bmp"</IMAGE>
    <IMAGE id="IMG_ID_SMS_PROFILE_MSG_TYPE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\profile\\\\MP_MODE.bmp"</IMAGE>


    <!-------------Image Resource for SMS setting end--------------------------------------->

    <!-------------Image Resource for SMS List Viewer begin--------------------------------->






    <!-------------Image Resource for SMS List Viewer end----------------------------------->
# 913 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_SMS_COMMON_NOIMAGE">"..\\\\..\\\\Customer\\\\Images""\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_SMS_ENTRY_SCRN_CAPTION">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\TitleBar\\\\TB_MG.PNG"</IMAGE>
# 923 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_SMS_CB_MENUENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_BROAD.bmp"</IMAGE>
    <IMAGE id="IMG_MESSAGE_SMS_MENUENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_sms.bmp"</IMAGE>




    <IMAGE id="IMG_MESSAGE_MMS_MENUENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\SB_mms.bmp"</IMAGE>
# 952 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_NEW_MESSAGE_NOTIFICATION_MSG">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_MAG"".PNG"</IMAGE>
# 965 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_NEW_SMS_PIC_SUBLCD_MSG">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\SUBLCD\\\\Active\\\\SB_SMS.GIF"</IMAGE>
    <IMAGE id="IMG_NEW_VOICEMAIL_PIC_SUBLCD_MSG">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\SUBLCD\\\\Active\\\\SB_VOCM.gif"</IMAGE>
# 983 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_NEW_SMS_SEND">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\Sending\\\\SS_SEND"".PNG"</IMAGE>
# 999 "temp/res/SmsAppRes.c"
       <IMAGE id="IMG_MESSAGE_READ">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_READ.bmp"</IMAGE>
       <IMAGE id="IMG_MESSAGE_UNREAD">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_UREAD.bmp"</IMAGE>



    <IMAGE id="IMG_MESSAGE_SENT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_SENT.bmp"</IMAGE>
    <IMAGE id="IMG_MESSAGE_UNSENT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_FAILTOSENT.bmp"</IMAGE>

    <IMAGE id="IMG_MESSAGE_SS_NCOMP">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\inbox\\\\SS_NCOMP.bmp"</IMAGE>
# 1027 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_EMS01_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS09.BMP"</IMAGE>
    <IMAGE id="IMG_EMS02_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS10.BMP"</IMAGE>
    <IMAGE id="IMG_EMS03_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS11.BMP"</IMAGE>
    <IMAGE id="IMG_EMS04_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS12.BMP"</IMAGE>
    <IMAGE id="IMG_EMS05_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS13.BMP"</IMAGE>
    <IMAGE id="IMG_EMS06_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS14.BMP"</IMAGE>
    <IMAGE id="IMG_EMS07_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS15.BMP"</IMAGE>
    <IMAGE id="IMG_EMS08_PIC">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\PIC\\\\EMS16.BMP"</IMAGE>

    <IMAGE id="IMG_EMS09_PIC">"..\\\\..\\\\Customer\\\\Images""\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_EMS010_PIC">"..\\\\..\\\\Customer\\\\Images""\\\\EmptyImage.bmp"</IMAGE>



    <AUDIO id="AUD_ID_SMS_EMS_IMY1">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\EMS\\\\imy1.imy"</AUDIO>
    <AUDIO id="AUD_ID_SMS_EMS_IMY2">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\EMS\\\\imy2.imy"</AUDIO>
    <AUDIO id="AUD_ID_SMS_EMS_IMY3">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\EMS\\\\imy3.imy"</AUDIO>
    <AUDIO id="AUD_ID_SMS_EMS_IMY4">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\EMS\\\\imy4.imy"</AUDIO>
    <AUDIO id="AUD_ID_SMS_EMS_IMY5">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\EMS\\\\imy5.imy"</AUDIO>



    <IMAGE id="IMG_MESSAGE_SENDING">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_SENDING.bmp"</IMAGE>
    <IMAGE id="IMG_MESSAGE_WAITING">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_WAITING.bmp"</IMAGE>
    <IMAGE id="IMG_MESSAGE_FAILTOSENT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\outbox\\\\SS_FAILTOSENT.bmp"</IMAGE>


    <IMAGE id="IMG_MSG_TB_ICON_VOICEMAIL_L1">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\TB_voicemail_l1.bmp"</IMAGE>
    <IMAGE id="IMG_MSG_TB_ICON_VOICEMAIL_L2">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\TB_voicemail_l2.bmp"</IMAGE>


    <IMAGE id="EMS_BI_ANIMATION_0_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\IRONIC.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_1_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\GLAD.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_2_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\SCEPTIC.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_3_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\SAD.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_4_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\WOW.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_5_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\CRY.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_6_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\WINK.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_7_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\LAUGH.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_8_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\INDIFF.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_9_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\KISS.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_10_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\CONFUSE.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_11_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\TONGUE.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_12_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\ANGRY.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_13_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\GLASS.gif"</IMAGE>
    <IMAGE id="EMS_BI_ANIMATION_14_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\DEVIL.gif"</IMAGE>
    <IMAGE id="EMS_EDITOR_SOUND_OBJECT_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\sound.bmp"</IMAGE>
    <IMAGE id="EMS_EDITOR_MELODY_OBJECT_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\melody.bmp"</IMAGE>
    <IMAGE id="EMS_CAN_INSERT_OBJECT_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\can.bmp"</IMAGE>
    <IMAGE id="EMS_CANNOT_INSERT_OBJECT_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Sms\\\\EMS\\\\cannt.bmp"</IMAGE>
# 1093 "temp/res/SmsAppRes.c"
    <IMAGE id="IMG_SMS_TO_NORMAL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\Editor\\\\To.bmp"</IMAGE>
    <IMAGE id="IMG_SMS_TO_HIGHLIGHT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MMS\\\\Editor\\\\To.bmp"</IMAGE>




    <!--------------Menu Resource Area------------------------------------------------------>
    <!--------------Menu Resource Area------------------------------------------------------>
    <!--------------Menu Resource for Voicemail begin--------------------------------------->

    <MENUITEM id="MENU_ID_SMS_VM_VMAIL_MENUID" str="STR_ID_SMS_VM_VMAIL_MENUENTRY"

        shortcut="ON" shortcut_img="IMG_SMS_VMAIL_MENUENTRY" launch="mmi_sms_vm_launch"

        />

    <MENU id="MENU_ID_SMS_VM_ITEM_VOICE_MAIL_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_VM_ITEM_VM_3_CONNECT_TO_VOICE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VM_ITEM_VM_1_EDIT</MENUITEM_ID>



    </MENU>

    <MENUITEM id="MENU_ID_SMS_VM_ITEM_VM_1_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SMS_VM_ITEM_VM_3_CONNECT_TO_VOICE" str="STR_GLOBAL_DIAL"/>
# 1139 "temp/res/SmsAppRes.c"
    <!--------------Menu Resource for Voicemail end----------------------------------------->
    <!--------------Menu Resource for SMS template begin------------------------------------>

    <MENU id="MENU_ID_SMS_TEMPLATES_OPTIONS_MENUENTRY" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_TEMPLATES_OPTIONS_WRITE_MESSAGE_MENUENTRY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_TEMPLATES_OPTIONS_NEW_MENUENTRY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_TEMPLATES_OPTIONS_EDIT_MENUENTRY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_TEMPLATES_OPTIONS_DELETE_MENUENTRY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_TEMPLATES_OPTIONS_ERASE_MENUENTRY</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_SMS_TEMPLATES_OPTIONS_NEW_MENUENTRY" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_SMS_TEMPLATES_OPTIONS_EDIT_MENUENTRY" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SMS_TEMPLATES_OPTIONS_DELETE_MENUENTRY" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_SMS_TEMPLATES_OPTIONS_ERASE_MENUENTRY" str="STR_GLOBAL_REMOVE"/>
    <MENUITEM id="MENU_ID_SMS_TEMPLATES_OPTIONS_WRITE_MESSAGE_MENUENTRY" str="STR_ID_SMS_TEMPL_OPTIONS_WRITE_MESSAGE"/>

    <MENU id="MENU_ID_SMS_ED_TEMPL_OPTIONS_MENU_ID" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_ED_TEMPL_OPT_DONE_MENU</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_ED_TEMPL_OPT_INPUT_METHODS_MENU</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_SMS_ED_TEMPL_OPT_DONE_MENU" str="STR_GLOBAL_SAVE"/>




    <MENUITEM id="MENU_ID_SMS_ED_TEMPL_OPT_INPUT_METHODS_MENU" str="STR_GLOBAL_INPUT_METHOD"/>
# 1177 "temp/res/SmsAppRes.c"
    <!--------------Menu Resource for SMS template end-------------------------------------->

    <!--------------Menu Resource for SMS setting begin------------------------------------->

    <MENUITEM id="MENU_ID_SMS_PROFILE_SETTING" str="STR_ID_SMS_PROFILE_SETTING_MENUENTRY"/>
    <MENU id="MENU_ID_SMS_PROFILE_SETTING_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_PROFILE_SETTING_OPTION_ACTIVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_PROFILE_SETTING_OPTION_EDIT</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_SMS_PROFILE_SETTING_OPTION_ACTIVE" str="STR_GLOBAL_ACTIVATE"/>
    <MENUITEM id="MENU_ID_SMS_PROFILE_SETTING_OPTION_EDIT" str="STR_GLOBAL_EDIT"/>


    <MENU id="MENU_ID_SMS_PREFERED_BEARER" type="APP_SUB" str="STR_ID_SMS_PREFERED_BEARER_MENUENTRY">
        <MENUITEM_ID>MENU_ID_SMS_PREFERED_BEARER_PREFER_GPRS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_PREFERED_BEARER_PREFER_GSM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_PREFERED_BEARER_GSM</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_SMS_PREFERED_BEARER_PREFER_GSM" str="STR_ID_SMS_PREFER_GSM_BEARER_MENUENTRY"/>
    <MENUITEM id="MENU_ID_SMS_PREFERED_BEARER_PREFER_GPRS" str="STR_ID_SMS_PREFER_GPRS_BEARER_MENUENTRY"/>
    <MENUITEM id="MENU_ID_SMS_PREFERED_BEARER_GSM" str="STR_ID_SMS_GSM_BEARER_MENUENTRY"/>
# 1233 "temp/res/SmsAppRes.c"
    <!--------------Menu Resource for SMS setting end--------------------------------------->

    <!--------------Menu Resource for SMS List Viewer begin--------------------------------->
    <MENU id="MENU_ID_SMS_DEFAULT_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_CALL_SENDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
# 1249 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>




    </MENU>

    <MENU id="MENU_ID_SMS_INBOX_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_REPLY</MENUITEM_ID>





        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_CALL_SENDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_SAVE_CONTACT</MENUITEM_ID>
# 1282 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>


        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_MARK_AS_READ</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD</MENUITEM_ID>







    </MENU>

    <MENU id="MENU_ID_SMS_SENT_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_VIEW</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
# 1313 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>







    </MENU>


    <MENU id="MENU_ID_SMS_DRAFTS_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_VIEW</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_UM_MS_OPT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_MS_DELETE_OPT</MENUITEM_ID>







    </MENU>
# 1433 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_VIEW" str="STR_GLOBAL_VIEW"/>





    <MENUITEM id="MENU_ID_SMS_LIST_OPT_REPLY" str="STR_ID_SMS_REPLY_BY_SMS"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_REPLY_BY_MMS" str="STR_ID_SMS_REPLY_BY_MMS"/>



    <MENUITEM id="MENU_ID_SMS_LIST_OPT_CALL_SENDER" str="STR_SMS_CALL_SENDER"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_SEND" str="STR_GLOBAL_SEND"/>
# 1462 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_FORWARD" str="STR_GLOBAL_FORWARD"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_SAVE_CONTACT" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>







    <MENUITEM id="MENU_ID_SMS_LIST_OPT_MARK_AS_READ" str="STR_ID_SMS_MARK_AS_READ"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_MARK_AS_UNREAD" str="STR_ID_SMS_MARK_AS_UNREAD"/>
# 1497 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_PHONE" str="STR_ID_SMS_COPY_TO_PHONE"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_PHONE" str="STR_ID_SMS_MOVE_TO_PHONE"/>






    <MENU id="MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL" type="OPTION" str="STR_ID_SMS_COPY_ALL">

        <MENUITEM_ID>MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE</MENUITEM_ID>
# 1518 "temp/res/SmsAppRes.c"
    </MENU>
    <MENU id="MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL" type="OPTION" str="STR_ID_SMS_MOVE_ALL">

        <MENUITEM_ID>MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE</MENUITEM_ID>
# 1532 "temp/res/SmsAppRes.c"
    </MENU>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_COPY_TO_SIM" str="STR_ID_SMS_COPY_TO_SIM"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_MOVE_TO_SIM" str="STR_ID_SMS_MOVE_TO_SIM"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_SIM" str="STR_ID_SMS_FROM_SIM"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_COPY_ALL_FROM_PHONE" str="STR_ID_SMS_FROM_PHONE"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_SIM" str="STR_ID_SMS_FROM_SIM"/>
    <MENUITEM id="MENU_ID_SMS_LIST_ADV_OPT_MOVE_ALL_FROM_PHONE" str="STR_ID_SMS_FROM_PHONE"/>
# 1561 "temp/res/SmsAppRes.c"
    <MENU id="MENU_ID_SMS_UNSENT_LIST_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_BG_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_BG_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_LIST_OPT_BG_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_UM_DEL_ALL_OPT</MENUITEM_ID>
# 1577 "temp/res/SmsAppRes.c"
    </MENU>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_BG_SEND" str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_BG_CALCEL_SEND" str="STR_SMS_BACKGROUND_CANCELSEND_SMS_ID"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_BG_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SMS_LIST_OPT_BG_DELETE" str="STR_GLOBAL_DELETE"/>


    <MENU id="MENU_ID_SMS_DEFAULT_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_CALL_SENDER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_DELETE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SMS_INBOX_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_REPLY</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_REPLY_BY_MMS</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_CALL_SENDER</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_DELETE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_SEND_USSD_OPT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_SAVE_OBJECTS_OPT</MENUITEM_ID>
# 1622 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_ADVANCED</MENUITEM_ID>






    </MENU>

    <MENU id="MENU_ID_SMS_SENT_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_FORWARD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_DELETE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_SEND_USSD_OPT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_SAVE_OBJECTS_OPT</MENUITEM_ID>





        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_ADVANCED</MENUITEM_ID>






    </MENU>

    <MENU id="MENU_ID_SMS_DRAFTS_VIEWER_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">



        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_DELETE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_SEND_USSD_OPT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_SAVE_OBJECTS_OPT</MENUITEM_ID>


        <MENUITEM_ID>MENU_ID_SMS_VIEWER_OPT_ADVANCED</MENUITEM_ID>






    </MENU>
# 1755 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_REPLY" str="STR_ID_SMS_REPLY_BY_SMS"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_REPLY_BY_MMS" str="STR_ID_SMS_REPLY_BY_MMS"/>
# 1765 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_CALL_SENDER" str="STR_SMS_CALL_SENDER"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_SEND" str="STR_GLOBAL_SEND"/>
# 1785 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_FORWARD" str="STR_GLOBAL_FORWARD"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
# 1796 "temp/res/SmsAppRes.c"
    <MENU id="MENU_ID_SMS_USE_NUMBER_OPT" type="OPTION" str="STR_ID_SMS_USE_NUM_ADDRESS">
        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT_DIAL_NUM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT_SAVE_TO_PB</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT_SEND_SMS</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT_SEND_MMS</MENUITEM_ID>

    </MENU>


    <MENU id="MENU_ID_SMS_USE_EMAIL_OPT" type="OPTION" str="STR_ID_SMS_USE_EMAIL_ADDRESS">

        <MENUITEM_ID>MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL</MENUITEM_ID>




    </MENU>

    <MENUITEM id="MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>
# 1827 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_SEND_USSD_OPT" str="STR_ID_SMS_SEND_USSD"/>

    <MENUITEM id="MENU_ID_SMS_SAVE_OBJECTS_OPT" str="STR_ID_SMS_SAVE_AS_OBJECT"/>

    <MENU id="MENU_ID_SMS_USE_USSD_OPT" type="OPTION" str="STR_ID_SMS_USE_USSD_ADDRESS">
        <MENUITEM_ID>MENU_ID_SMS_SEND_USSD_OPT</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SMS_USE_OBJECT_OPT" type="OPTION" str="STR_ID_SMS_USE_OBJECT">
        <MENUITEM_ID>MENU_ID_SMS_SAVE_OBJECTS_OPT</MENUITEM_ID>
    </MENU>







    <MENU id="MENU_ID_SMS_VIEWER_OPT_ADVANCED" type="OPTION" str="STR_GLOBAL_ADVANCED">
# 1857 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM2</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM2</MENUITEM_ID>
# 1882 "temp/res/SmsAppRes.c"
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF</MENUITEM_ID>

    </MENU>
# 1918 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_PHONE" str="STR_ID_SMS_COPY_TO_PHONE"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_PHONE" str="STR_ID_SMS_MOVE_TO_PHONE"/>
# 1933 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_COPY_TO_SIM" str="STR_ID_SMS_COPY_TO_SIM"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_MOVE_TO_SIM" str="STR_ID_SMS_MOVE_TO_SIM"/>
# 1944 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_ON" str="STR_ID_SMS_AUTO_FIND_ON"/>
    <MENUITEM id="MENU_ID_SMS_VIEWER_ADV_OPT_AUTO_FIND_OFF" str="STR_ID_SMS_AUTO_FIND_OFF"/>
# 1956 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_USE_NUMBER_OPT_DIAL_NUM" str="STR_GLOBAL_DIAL"/>
    <MENUITEM id="MENU_ID_SMS_USE_NUMBER_OPT_SAVE_TO_PB" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>
    <MENUITEM id="MENU_ID_SMS_USE_NUMBER_OPT_SEND_SMS" str="STR_GLOBAL_SEND_TEXT_MESSAGE"/>

    <MENUITEM id="MENU_ID_SMS_USE_NUMBER_OPT_SEND_MMS" str="STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE"/>
# 1987 "temp/res/SmsAppRes.c"
    <!--------------Menu Resource for SMS List Viewer end----------------------------------->

    <!--------------Menu Resource for SMS Editor begin-------------------------------------->


    <MENU id="MENU_ID_SMS_EDITOR_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_SEND_TO</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_ADD_RECIPIENT</MENUITEM_ID>




        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>

        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_INSERT_TEMPLATE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_ADVANCED</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS</MENUITEM_ID>
    </MENU>




    <MENUITEM id="MENU_ID_SMS_ED_OPT_SEND_TO" str="STR_GLOBAL_SEND"/>
    <MENUITEM id="MENU_ID_SMS_ED_OPT_ADD_RECIPIENT" str="STR_ID_SMS_ADD_RECIPIENT"/>





    <MENUITEM id="MENU_ID_SMS_ED_OPT_INSERT_TEMPLATE" str="STR_ID_SMS_INSERT_TEMPLATE"/>

    <MENU id="MENU_ID_SMS_ED_OPT_ADVANCED" type="OPTION" str="STR_GLOBAL_ADVANCED">

        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_INSERT_OBJECT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_INSERT_NUMBER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_INSERT_NAME</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_ED_OPT_TEXT_FORMAT</MENUITEM_ID>

    </MENU>
# 2053 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_ED_OPT_SAVE_TO_DRAFTS"

        str="STR_GLOBAL_SAVE"/>






    <MENU id="MENU_ID_SMS_ED_OPT_INSERT_OBJECT" type="OPTION" str="STR_OPT_INS_OBJECT_MENUENTRY">
        <MENUITEM_ID>MENU_ID_SMS_EMS_PICTURE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_MY_PICTURE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_PREDEF_ANIMATION</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_MY_ANIMATION</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_EMS_MELODY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_MY_MELODY</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_EMS_PREDEF_SOUND</MENUITEM_ID>
    </MENU>
    <MENU id="MENU_ID_SMS_ED_OPT_TEXT_FORMAT" type="OPTION" str="STR_EMS_FORMATING_TEXT_ID">

        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_SIZE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_STYLE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_ALIGNMENT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_NEW_PARAGRAPH</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_SMS_ED_OPT_INSERT_NUMBER" str="STR_ID_SMS_INSERT_NUMBER"/>
    <MENUITEM id="MENU_ID_SMS_ED_OPT_INSERT_NAME" str="STR_ID_SMS_INSERT_NAME"/>





    <MENU id="MENU_ID_SMS_RECIPIENT_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SMS_RECIPIENT_OPT_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_RECIPIENT_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_RECIPIENT_OPT_REMOVE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_RECIPIENT_OPT_REMOVE_ALL</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS</MENUITEM_ID>

    </MENU>







    <MENUITEM id="MENU_ID_SMS_RECIPIENT_OPT_SEND" str="STR_GLOBAL_SEND"/>
# 2139 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_RECIPIENT_OPT_SAVE_TO_DRAFTS"

        str="STR_GLOBAL_SAVE"/>






    <MENUITEM id="MENU_ID_SMS_RECIPIENT_OPT_EDIT" str="STR_ID_SMS_EDIT_RECIPIENT"/>
    <MENUITEM id="MENU_ID_SMS_RECIPIENT_OPT_REMOVE" str="STR_ID_SMS_REMOVE_RECIPIENT"/>
    <MENUITEM id="MENU_ID_SMS_RECIPIENT_OPT_REMOVE_ALL" str="STR_ID_SMS_REMOVE_ALL_RECIPIENT"/>
# 2183 "temp/res/SmsAppRes.c"
    <!--------------Menu Resource for SMS Editor end---------------------------------------->


    <!--------------Menu Resource for EMS begin--------------------------------------------->

    <MENUITEM id="MENU_ID_SMS_EMS_PICTURE" str="STR_GLOBAL_PICTURE"/>
    <MENUITEM id="MENU_ID_SMS_EMS_MY_PICTURE" str="STR_INS_OBJ_MY_PICTURE"/>
    <MENUITEM id="MENU_ID_SMS_EMS_PREDEF_ANIMATION" str="STR_INS_OBJ_PRED_ANIMATION"/>
    <MENUITEM id="MENU_ID_SMS_EMS_MY_ANIMATION" str="STR_INS_OBJ_MY_ANIMATION"/>


    <MENUITEM id="MENU_ID_SMS_EMS_MELODY" str="STR_INS_OBJ_MELODY"/>
    <MENUITEM id="MENU_ID_SMS_EMS_MY_MELODY" str="STR_INS_OBJ_MY_MELODY"/>

    <MENUITEM id="MENU_ID_SMS_EMS_PREDEF_SOUND" str="STR_INS_OBJ_MY_SOUND"/>


    <MENU id="MENU_ID_SMS_EMS_TEXT_SIZE" type="OPTION" str="STR_EMS_TEXT_SIZE_ID">
        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_SIZE_SMALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_SIZE_NORMAL</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_SIZE_LARGE</MENUITEM_ID>

    </MENU>


    <MENU id="MENU_ID_SMS_EMS_TEXT_STYLE" type="OPTION" str="STR_EMS_TEXT_STYLE_ID">

        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_STYLE_BOLD</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_STYLE_ITALICS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_STYLE_UNDERLINE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_TEXT_STYLE_STRIKETHROUGH</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SMS_EMS_ALIGNMENT" type="OPTION" str="STR_EMS_ALIGNMENT_ID">
        <MENUITEM_ID>MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_ALIGNMENT_LEFT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_ALIGNMENT_CENTER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_ALIGNMENT_RIGHT</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_SMS_EMS_NEW_PARAGRAPH" type="OPTION" str="STR_EMS_NEW_PARAGRAPH_ID">
        <MENUITEM_ID>MENU_ID_SMS_EMS_NEW_PARAGRAPH_AUTOMATIC</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_NEW_PARAGRAPH_LEFT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_NEW_PARAGRAPH_CENTER</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SMS_EMS_NEW_PARAGRAPH_RIGHT</MENUITEM_ID>
    </MENU>


    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_SIZE_SMALL" str="STR_EMS_TEXT_SIZE_SMALL_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_SIZE_NORMAL" str="STR_GLOBAL_MEDIUM"/>

    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_SIZE_LARGE" str="STR_EMS_TEXT_SIZE_LARGE_ID"/>




    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_STYLE_BOLD" str="STR_EMS_TEXT_STYLE_BOLD_ID"/>

    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_STYLE_ITALICS" str="STR_EMS_TEXT_STYLE_ITALICS_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_STYLE_UNDERLINE" str="STR_EMS_TEXT_STYLE_UNDERLINE_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_TEXT_STYLE_STRIKETHROUGH" str="STR_EMS_TEXT_STYLE_STRIKETHROUGH_ID"/>

    <MENUITEM id="MENU_ID_SMS_EMS_ALIGNMENT_AUTOMATIC" str="STR_GLOBAL_AUTOMATIC"/>
    <MENUITEM id="MENU_ID_SMS_EMS_ALIGNMENT_LEFT" str="STR_EMS_ALIGNMENT_LEFT_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_ALIGNMENT_CENTER" str="STR_EMS_ALIGNMENT_CENTER_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_ALIGNMENT_RIGHT" str="STR_EMS_ALIGNMENT_RIGHT_ID"/>

    <MENUITEM id="MENU_ID_SMS_EMS_NEW_PARAGRAPH_AUTOMATIC" str="STR_GLOBAL_AUTOMATIC"/>
    <MENUITEM id="MENU_ID_SMS_EMS_NEW_PARAGRAPH_LEFT" str="STR_EMS_NEW_PARAGRAPH_LEFT_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_NEW_PARAGRAPH_CENTER" str="STR_EMS_NEW_PARAGRAPH_CENTER_ID"/>
    <MENUITEM id="MENU_ID_SMS_EMS_NEW_PARAGRAPH_RIGHT" str="STR_EMS_NEW_PARAGRAPH_RIGHT_ID"/>

    <MENUITEM id="MENU_ID_SMS_FMGR_FWD_EMS" str="STR_GLOBAL_AS_TEXT_MESSAGE"/>


    <!--------------Menu Resource for EMS end----------------------------------------------->
    <!--------------Menu Resource for others begin----------------------------------------------->

    <MENU id="SMS_CLASS0_OPT_MENUID" type="OPTION" str="STR_GLOBAL_OPTIONS">

        <MENUITEM_ID>MENU_ID_SMS_USE_NUMBER_OPT</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_SMS_USE_EMAIL_OPT_SAVE_TO_EMAIL</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_SMS_SEND_USSD_OPT</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_SMS_SAVE_OBJECTS_OPT</MENUITEM_ID>







        <MENUITEM_ID>MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX</MENUITEM_ID>







        <MENUITEM_ID>SMS_CLSASS0_OPT_AUTO_FIND_ON</MENUITEM_ID>
        <MENUITEM_ID>SMS_CLSASS0_OPT_AUTO_FIND_OFF</MENUITEM_ID>

    </MENU>





    <MENUITEM id="SMS_CLSASS0_OPT_USE_NUMBER_MENUID" str="STR_ID_SMS_USE_NUM_ADDRESS"/>
# 2313 "temp/res/SmsAppRes.c"
    <MENUITEM id="SMS_CLSASS0_OPT_USE_EMAIL_OPT_SAVE_TO_EMAIL" str="STR_GLOBAL_SAVE_TO_PHONEBOOK"/>

    <MENUITEM id="SMS_CLSASS0_OPT_SEND_USSD_OPT" str="STR_ID_SMS_SEND_USSD"/>
    <MENUITEM id="SMS_CLSASS0_OPT_SAVE_OBJECTS_OPT" str="STR_ID_SMS_SAVE_AS_OBJECT"/>



    <MENUITEM id="SMS_CLSASS0_OPT_AUTO_FIND_ON" str="STR_ID_SMS_AUTO_FIND_ON"/>
    <MENUITEM id="SMS_CLSASS0_OPT_AUTO_FIND_OFF" str="STR_ID_SMS_AUTO_FIND_OFF"/>
# 2338 "temp/res/SmsAppRes.c"
    <MENUITEM id="MENU_ID_SMS_CLSASS0_OPT_SAVE_TO_INBOX" str="STR_ID_SMS_SAVE_TO_INBOX"/>



    <MENU id="SMS_INBOX_OPT_SAVE_OBJECT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>SMS_INBOX_OPT_SAVE_OPTION_DONE</MENUITEM_ID>
        <MENUITEM_ID>SMS_INBOX_OPT_SAVE_OPTION_INPUT_METHOD</MENUITEM_ID>
    </MENU>
    <MENUITEM id="SMS_INBOX_OPT_SAVE_OPTION_DONE" str="STR_GLOBAL_DONE"/>
    <MENUITEM id="SMS_INBOX_OPT_SAVE_OPTION_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD"/>
# 2369 "temp/res/SmsAppRes.c"
    <!--------------Other Resource---------------------------------------------------------->







    <SCREEN id="SCR_ID_MSG_DELIVER_REPORT"/>
    <SCREEN id="SCR_ID_MSG_CLASS0_MSG"/>

    <SCREEN id="SCR_ID_MSG_CLASS0_OPTION"/>

    <SCREEN id="SCR_ID_MSG_MSG_WAITING_IND"/>
    <SCREEN id="SCR_ID_MSG_EXCEED_IND"/>




    <SCREEN id="SCR_ID_MSG_USE_USSD_EDIT"/>

    <SCREEN id="SCR_ID_MSG_SAVE_OBJECT_LIST"/>
    <SCREEN id="SCR_ID_MSG_SAVE_OBJECT_NAME"/>


    <SCREEN id="SCR_ID_MSG_EMS_INSERT_OBJECT"/>
    <SCREEN id="SCR_ID_MSG_EMS_OBJECT_LIST"/>
    <SCREEN id="SCR_ID_MSG_EMS_PREVIEW_OBJECT"/>
# 2419 "temp/res/SmsAppRes.c"
    <SCREEN id="SCR_ID_SMS_VIEWER"/>



    <SCREEN id="SCR_ID_SMS_USE_ADDRESS"/>

    <SCREEN id="SCR_ID_SMS_EDITOR"/>


    <SCREEN id="SCR_ID_SMS_ADD_RECIPIENT"/>



    <SCREEN id="SCR_ID_SMS_SC_NUMBER"/>
    <SCREEN id="SCR_ID_SMS_EMAIL_SC_NUMBER"/>
    <SCREEN id="SCR_ID_SMS_PROCESSING"/>
    <SCREEN id="SCR_ID_SMS_SENDING"/>
    <SCREEN id="SCR_ID_SMS_ABORT_SENDING"/>
    <SCREEN id="SCR_ID_SMS_EDIT_RECIPIENT"/>
    <SCREEN id="SCR_ID_SMS_ENTER_NUMBER"/>

    <SCREEN id="SCR_ID_SMS_DUMMY"/>





    <SCREEN id="SCR_ID_SMS_TEMPLATE_LIST"/>






    <SCREEN id="SCR_ID_SMS_MEMORY_STATUS"/>
    <SCREEN id="SCR_ID_SMS_PREFERRED_STORAGE"/>


    <SCREEN id="SCR_ID_SMS_PROFILE_LIST"/>







    <SCREEN id="SCR_ID_SMS_VM_VOICE_MAIL_LIST"/>

    <SCREEN id="SCR_ID_SMS_VM_VOICE_MAIL_EDIT"/>
# 2480 "temp/res/SmsAppRes.c"
    <SCREEN id="SCR_ID_SMS_OPTION_DETAILS"/>

    <SCREEN id="SCR_ID_SMS_COUNTER_STATUS"/>


    <SCREEN id="SCR_ID_SMS_SCR_BACKUP_RESTORE_PROVIDER_LIST"/>

    <SCREEN id="SCR_ID_SMS_SCR_BACKUP_RESTORE_PROCESSING"/>
    <!--------------Other Resource for SMS template----------------------------------------->
    <!--------------Other Resource for SMS setting------------------------------------------>


    <!-----------------SMS Service Events--------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_sms_handle_ready_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG" proc="mmi_sms_handle_new_msg_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG_WAITING" proc="mmi_sms_handle_msg_waiting_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_STATUS_REPORT" proc="mmi_sms_handle_deliver_report_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_SIM_REFRESH" proc="mmi_sms_handle_ind_dumy_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_AT_CMD_IND" proc="mmi_sms_handle_ind_dumy_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_EXCEED" proc="mmi_sms_handle_mem_exceed_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_FULL" proc="mmi_sms_handle_mem_full_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_MEM_AVAILABLE" proc="mmi_sms_handle_mem_avail_ind"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_sms_handle_msg_del_event"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_sms_handle_msg_update_event"/>
    <RECEIVER id="EVT_ID_SRV_SMS_API_SEND_MSG" proc="mmi_sms_api_send_msg_ind"/>

    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="mmi_sms_handle_sms_update_unsent_msg_status"/>

    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_SENDING_ICON" proc="mmi_sms_handle_sms_update_sending_icon_ind"/>



    <RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="mmi_sms_handle_um_enter_folder"/>



    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sms_sim_ctrl_availability_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_sms_mode_switch_finish_evt_hdlr"/>

    <!---------------------------SMS UM SAP EVENT----------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_sms_um_ready_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_NEW_MSG" proc="mmi_sms_um_new_msg_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_sms_um_msg_common_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_sms_um_msg_common_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_sms_um_msg_common_event_proc"/>

    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS" proc="mmi_sms_um_msg_common_event_proc"/>


    <RECEIVER id="EVT_ID_SRV_SMS_ADD_REPORT" proc="mmi_sms_um_msg_common_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_REPORT" proc="mmi_sms_um_msg_common_event_proc"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_REPORT" proc="mmi_sms_um_msg_common_event_proc"/>





    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_sms_shutdown_deinit_proc"/>




    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_COUNTER" proc="mmi_sms_update_sms_counter"/>
# 2556 "temp/res/SmsAppRes.c"
    <TIMER id="MESSAGES_SUBLCD_TIMER_ID"/>
    <TIMER id="MESSAGES_INPROGRESS_TIMER_ID"/>
    <TIMER id="MESSAGES_EMS_OBJECT_PLAY_TIMER_ID"/>

</APP>



<FILE_TYPES>
    <FILE_OPTION_HDLR option = "MENU_ID_SMS_FMGR_FWD_EMS" enabler = "mmi_ems_fmgr_send_by_ems_enabler" handler="mmi_ems_fmgr_send_by_ems_hdlr"/>
</FILE_TYPES>
