# 1 "/usr/include/newlib/sys/config.h"



# 12 "/usr/include/newlib/stdlib.h"




# 209 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int size_t;
# 321 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int wchar_t;
# 17 "/usr/include/newlib/stdlib.h"

# 143 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef int ptrdiff_t;
# 350 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int wint_t;
# 25 "/usr/include/newlib/sys/_types.h"


# 1 "/usr/include/newlib/machine/_types.h"






# 41 "/usr/include/newlib/machine/_default_types.h"
typedef signed char __int8_t;

typedef unsigned char __uint8_t;











typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "/usr/include/newlib/machine/_default_types.h"
typedef long int __int32_t;

typedef long unsigned int __uint32_t;
# 103 "/usr/include/newlib/machine/_default_types.h"
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "/usr/include/newlib/machine/_default_types.h"
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "/usr/include/newlib/machine/_default_types.h"
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "/usr/include/newlib/machine/_default_types.h"
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;















typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;











typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 28 "/usr/include/newlib/sys/_types.h"


typedef long __blkcnt_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;



typedef long _off_t;





typedef int __pid_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



typedef __uint32_t __id_t;







typedef unsigned short __ino_t;














typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;














typedef unsigned int __size_t;















typedef signed int _ssize_t;










typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;




typedef void *_iconv_t;






typedef unsigned long __clock_t;






typedef __int_least64_t __time_t;





typedef unsigned long __clockid_t;


typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/usr/include/newlib/sys/reent.h"






typedef unsigned long __ULong;
# 11 "/usr/include/newlib/sys/lock.h"
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
# 35 "/usr/include/newlib/sys/reent.h"
typedef _LOCK_RECURSIVE_T _flock_t;







struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};










struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
# 122 "/usr/include/newlib/sys/reent.h"
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 186 "/usr/include/newlib/sys/reent.h"
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 292 "/usr/include/newlib/sys/reent.h"
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 324 "/usr/include/newlib/sys/reent.h"
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 613 "/usr/include/newlib/sys/reent.h"
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};
# 819 "/usr/include/newlib/sys/reent.h"
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 33 "/usr/include/newlib/stdlib.h"


typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;




typedef int (*__compar_fn_t) (const void *, const void *);







int __locale_mb_cur_max (void);



void abort (void) __attribute__ ((__noreturn__));
int abs (int);





int atexit (void (*__func)(void));
double atof (const char *__nptr);



int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void *__key,
         const void *__base,
         size_t __nmemb,
         size_t __size,
         __compar_fn_t _compar);
void *calloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__))
      __attribute__((__alloc_size__(1, 2))) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((__noreturn__));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);



char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);




long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void *malloc(size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(1))) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);
# 137 "/usr/include/newlib/stdlib.h"
char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void *realloc(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2))) ;













void srand (unsigned __seed);
double strtod (const char *restrict __n, char **restrict __end_PTR);
double _strtod_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR);

float strtof (const char *restrict __n, char **restrict __end_PTR);







long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
















int system (const char *__string);










void _Exit (int __status) __attribute__ ((__noreturn__));




int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);



int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);











char * __itoa (int, char *, int);
char * __utoa (unsigned, char *, int);
# 263 "/usr/include/newlib/stdlib.h"
long long atoll (const char *__nptr);

long long _atoll_r (struct _reent *, const char *__nptr);

long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);

long long _strtoll_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long _strtoull_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);








int _unsetenv_r (struct _reent *, const char *__string);







char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);
# 322 "/usr/include/newlib/stdlib.h"
extern long double _strtold_r (struct _reent *, const char *restrict, char **restrict);

extern long double strtold (const char *restrict, char **restrict);















# 27 "/usr/include/newlib/string.h"


void * memchr (const void *, int, size_t);
int memcmp (const void *, const void *, size_t);
void * memcpy (void *restrict, const void *restrict, size_t);
void * memmove (void *, const void *, size_t);
void * memset (void *, int, size_t);
char *strcat (char *restrict, const char *restrict);
char *strchr (const char *, int);
int strcmp (const char *, const char *);
int strcoll (const char *, const char *);
char *strcpy (char *restrict, const char *restrict);
size_t strcspn (const char *, const char *);
char *strerror (int);
size_t strlen (const char *);
char *strncat (char *restrict, const char *restrict, size_t);
int strncmp (const char *, const char *, size_t);
char *strncpy (char *restrict, const char *restrict, size_t);
char *strpbrk (const char *, const char *);
char *strrchr (const char *, int);
size_t strspn (const char *, const char *);
char *strstr (const char *, const char *);

char *strtok (char *restrict, const char *restrict);

size_t strxfrm (char *restrict, const char *restrict, size_t);
# 86 "/usr/include/newlib/string.h"
char *_strdup_r (struct _reent *, const char *);



char *_strndup_r (struct _reent *, const char *, size_t);
# 112 "/usr/include/newlib/string.h"
char * _strerror_r (struct _reent *, int, int, int *);
# 134 "/usr/include/newlib/string.h"
char *strsignal (int __signo);
# 176 "/usr/include/newlib/string.h"


# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"







# 34 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h"
typedef signed char int8_t;


typedef short int int16_t;


typedef long int int32_t;


typedef long long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef long unsigned int uint32_t;


typedef long long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int int_least32_t;
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef long unsigned int uint_least32_t;
typedef long long unsigned int uint_least64_t;



typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long long unsigned int uint_fast64_t;




typedef int intptr_t;


typedef unsigned int uintptr_t;




typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
# 40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
# 99 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h"
typedef __gnuc_va_list va_list;
# 63 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"

# 45 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/inc/hw_types.h"






typedef void (* FPTR_VOID_VOID_T) (void);
typedef void (* FPTR_VOID_UINT8_T) (uint8_t);
















typedef unsigned int __UINT32;
# 69 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"

# 57 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/debug.h"
extern void __error__(char *pcFilename, uint32_t ui32Line);
# 106 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
extern uint32_t NOROM_CPUcpsid(void);













extern uint32_t NOROM_CPUprimask(void);











extern uint32_t NOROM_CPUcpsie(void);
# 173 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUwfi(void)
{



    __asm("    wfi\n");
}
# 222 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUwfe(void)
{



    __asm("    wfe\n");
}
# 271 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUsev(void)
{



    __asm("    sev\n");
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
# 325 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__ ((naked))
CPUbasepriSet(uint32_t ui32NewBasepri)
{



   __asm("    msr     BASEPRI, r0\n"
         "    bx      lr\n");
}
#pragma GCC diagnostic pop












extern uint32_t NOROM_CPUbasepriGet(void);
















extern void NOROM_CPUdelay(uint32_t ui32Count);
# 382 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void
CPU_WriteBufferDisable( void )
{
    (*((volatile unsigned long *)(((unsigned long)(0xE000E000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0xE000E000 + 0x00000008) & 0x000FFFFF) << 5) | ((1) << 2)))) = 1;
}













static inline void
CPU_WriteBufferEnable( void )
{
    (*((volatile unsigned long *)(((unsigned long)(0xE000E000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0xE000E000 + 0x00000008) & 0x000FFFFF) << 5) | ((1) << 2)))) = 0;
}
# 66 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/rom.h"
typedef uint32_t (* FPTR_CRC32_T) ( uint8_t* ,
                                                     uint32_t ,
                                                     uint32_t );

typedef uint32_t (* FPTR_GETFLSIZE_T) ( void );

typedef uint32_t (* FPTR_GETCHIPID_T) ( void );

typedef uint32_t (* FPTR_RESERVED1_T) ( uint32_t );

typedef uint32_t (* FPTR_RESERVED2_T) ( void );

typedef uint32_t (* FPTR_RESERVED3_T) ( uint8_t* ,
                                                     uint32_t ,
                                                     uint32_t );
typedef void (* FPTR_RESETDEV_T) ( void );

typedef uint32_t (* FPTR_FLETCHER32_T) ( uint16_t* ,
                                                     uint16_t ,
                                                     uint16_t );

typedef uint32_t (* FPTR_MINVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_MAXVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_MEANVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_STDDVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef void (* FPTR_HFSOURCESAFESWITCH_T) ( void );

typedef void (* FPTR_RESERVED4_T) ( uint32_t );

typedef void (* FPTR_RESERVED5_T) ( uint32_t );

typedef void (* FPTR_COMPAIN_T) ( uint8_t );

typedef void (* FPTR_COMPAREF_T) ( uint8_t );

typedef void (* FPTR_ADCCOMPBIN_T) ( uint8_t );

typedef void (* FPTR_COMPBREF_T) ( uint8_t );

extern uint32_t MemBusWrkAroundHapiProgramFlash(uint8_t *pui8DataBuffer,
                                                uint32_t ui32Address,
                                                uint32_t ui32Count);

extern uint32_t MemBusWrkAroundHapiEraseSector(uint32_t ui32Address);




typedef struct
{
    FPTR_CRC32_T Crc32;
    FPTR_GETFLSIZE_T FlashGetSize;
    FPTR_GETCHIPID_T GetChipId;
    FPTR_RESERVED1_T ReservedLocation1;
    FPTR_RESERVED2_T ReservedLocation2;
    FPTR_RESERVED3_T ReservedLocation3;
    FPTR_RESETDEV_T ResetDevice;
    FPTR_FLETCHER32_T Fletcher32;
    FPTR_MINVAL_T MinValue;
    FPTR_MAXVAL_T MaxValue;
    FPTR_MEANVAL_T MeanValue;
    FPTR_STDDVAL_T StandDeviationValue;
    FPTR_RESERVED4_T ReservedLocation4;
    FPTR_RESERVED5_T ReservedLocation5;
    FPTR_HFSOURCESAFESWITCH_T HFSourceSafeSwitch;
    FPTR_COMPAIN_T SelectCompAInput;
    FPTR_COMPAREF_T SelectCompARef;
    FPTR_ADCCOMPBIN_T SelectADCCompBInput;
    FPTR_COMPBREF_T SelectCompBRef;
} HARD_API_T;









extern void SafeHapiVoid( FPTR_VOID_VOID_T fPtr );
extern void SafeHapiAuxAdiSelect( FPTR_VOID_UINT8_T fPtr, uint8_t ut8Signal );
# 136 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline 
# 136 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
               _Bool
IntMasterEnable(void)
{



    return(NOROM_CPUcpsie());
}














static inline 
# 158 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
               _Bool
IntMasterDisable(void)
{



    return(NOROM_CPUcpsid());
}
# 192 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));
# 210 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntUnregister(uint32_t ui32Interrupt);
# 228 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPriorityGroupingSet(uint32_t ui32Bits);











extern uint32_t NOROM_IntPriorityGroupingGet(void);
# 274 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPrioritySet(uint32_t ui32Interrupt, uint8_t ui8Priority);
# 296 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern int32_t NOROM_IntPriorityGet(uint32_t ui32Interrupt);














extern void NOROM_IntEnable(uint32_t ui32Interrupt);














extern void NOROM_IntDisable(uint32_t ui32Interrupt);
# 345 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPendSet(uint32_t ui32Interrupt);
# 366 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern 
# 366 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
      _Bool 
# 366 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
           NOROM_IntPendGet(uint32_t ui32Interrupt);















extern void NOROM_IntPendClear(uint32_t ui32Interrupt);
# 407 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline void
IntPriorityMaskSet(uint32_t ui32PriorityMask)
{
    CPUbasepriSet(ui32PriorityMask);
}
# 433 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline uint32_t
IntPriorityMaskGet(void)
{
    return(NOROM_CPUbasepriGet());
}
# 267 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMInfClockConfigureSet(uint32_t ui32ClkDiv,
                                     uint32_t ui32PowerMode);
# 291 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern uint32_t NOROM_PRCMInfClockConfigureGet(uint32_t ui32PowerMode);













static inline void
PRCMMcuPowerOff(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((2) << 2)))) = 1;
}














static inline void
PRCMMcuPowerOffCancel(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((2) << 2)))) = 0;
}
# 359 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMMcuUldoConfigure(uint32_t ui32Enable)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Enable;
}
# 397 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMGPTimerClockDivisionSet( uint32_t clkDiv )
{
    ;

    (*((volatile unsigned long *)(0x40082000 + 0x000000CC))) = clkDiv;
}
# 425 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline uint32_t
PRCMGPTimerClockDivisionGet( void )
{
    return ( (*((volatile unsigned long *)(0x40082000 + 0x000000CC))));
}











static inline void
PRCMAudioClockEnable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x000000D0) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
}










static inline void
PRCMAudioClockDisable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x000000D0) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}
# 495 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMAudioClockConfigSet(uint32_t ui32ClkConfig,
                                    uint32_t ui32SampleRate);
# 523 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMAudioClockConfigSetOverride(uint32_t ui32ClkConfig, uint32_t ui32MstDiv,
                        uint32_t ui32BitDiv, uint32_t ui32WordDiv);
# 553 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMLoadSet(void)
{



    (*((volatile unsigned long *)(0x60082000 + 0x00000028))) = 0x00000001;
}












static inline 
# 573 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
               _Bool
PRCMLoadGet(void)
{



    return (((*((volatile unsigned long *)(0x40082000 + 0x00000028))) & 0x00000002) ?
           1 
# 580 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                : 
# 580 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                  0
# 580 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                       );
}
# 603 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMDomainEnable(uint32_t ui32Domains)
{



   
                                            ;




    if(ui32Domains & 0x00000001)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x0000002C))) = 0x00000001;
    }
    if(ui32Domains & 0x00000010)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x00000030))) = 0x00000003;
    }
}
# 646 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMDomainDisable(uint32_t ui32Domains)
{



   
                                            ;




    if(ui32Domains & 0x00000001)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x0000002C))) = 0x0;
    }
    if(ui32Domains & 0x00000010)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x00000030))) = 0x0;
    }
}
# 718 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPowerDomainOn(uint32_t ui32Domains);
# 743 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPowerDomainOff(uint32_t ui32Domains);












static inline void
PRCMRfPowerDownWhenIdle(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x00000130) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x00000130) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}
# 806 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralRunEnable(uint32_t ui32Peripheral);
# 848 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralRunDisable(uint32_t ui32Peripheral);
# 888 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralSleepEnable(uint32_t ui32Peripheral);
# 929 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralSleepDisable(uint32_t ui32Peripheral);
# 969 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralDeepSleepEnable(uint32_t ui32Peripheral);
# 1012 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralDeepSleepDisable(uint32_t ui32Peripheral);
# 1033 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern uint32_t NOROM_PRCMPowerDomainStatus(uint32_t ui32Domains);














static inline 
# 1048 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
               _Bool
PRCMRfReady(void)
{



    return (((*((volatile unsigned long *)(0x40082000 + 0x0000019C))) &
             0x00000001) ? 
# 1055 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                  1 
# 1055 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                       : 
# 1055 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                         0
# 1055 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                              );
}
















static inline void
PRCMSleep(void)
{



    CPUwfi();
}















extern void NOROM_PRCMDeepSleep(void);










static inline void
PRCMCacheRetentionEnable( void )
{
   (*((volatile unsigned long *)(0x40082000 + 0x00000224))) |= 0x00000003;
}










static inline void
PRCMCacheRetentionDisable( void )
{
   (*((volatile unsigned long *)(0x40082000 + 0x00000224))) &= ~0x00000003;
}
# 163 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_readDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000C0))) >> dioNumber ) & 1 );
}
# 197 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_readMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000C0))) & dioMask );
}















static inline void
GPIO_writeDio( uint32_t dioNumber, uint32_t value )
{



    ;
    ;




    (*((volatile unsigned char *)(0x40022000 + dioNumber))) = value;
}
# 261 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_writeMultiDio( uint32_t dioMask, uint32_t bitVectoredValue )
{



    ;

    (*((volatile unsigned long *)(0x40022000 + 0x00000080))) =
        ( (*((volatile unsigned long *)(0x40022000 + 0x00000080))) & ~dioMask ) |
        ( bitVectoredValue & dioMask );
}












static inline void
GPIO_setDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x00000090))) = ( 1 << dioNumber );
}
















static inline void
GPIO_setMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x00000090))) = dioMask;
}












static inline void
GPIO_clearDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000A0))) = ( 1 << dioNumber );
}
















static inline void
GPIO_clearMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000A0))) = dioMask;
}












static inline void
GPIO_toggleDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000B0))) = ( 1 << dioNumber );
}
















static inline void
GPIO_toggleMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000B0))) = dioMask;
}
# 452 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getOutputEnableDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) >> dioNumber ) & 1 );
}
# 486 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getOutputEnableMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) & dioMask );
}
# 517 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_setOutputEnableDio( uint32_t dioNumber, uint32_t outputEnableValue )
{



    ;
   
                                                            ;




    (*((volatile unsigned long *)(((unsigned long)(0x40022000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40022000 + 0x000000D0) & 0x000FFFFF) << 5) | ((dioNumber) << 2)))) = outputEnableValue;
}
# 557 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_setOutputEnableMultiDio( uint32_t dioMask, uint32_t bitVectoredOutputEnable )
{



    ;

    (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) =
        ( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) & ~dioMask ) |
        ( bitVectoredOutputEnable & dioMask );
}














static inline uint32_t
GPIO_getEventDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) >> dioNumber ) & 1 );
}
# 618 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getEventMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) & dioMask );
}












static inline void
GPIO_clearEventDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) = ( 1 << dioNumber );
}
# 673 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_clearEventMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) = dioMask;
}
# 235 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTParityModeSet(uint32_t ui32Base, uint32_t ui32Parity)
{



    ;
   



                                                ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) = (((*((volatile unsigned long *)(ui32Base + 0x0000002C))) &
                                      ~(0x00000080 | 0x00000004 |
                                        0x00000002)) | ui32Parity);
}
# 273 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTParityModeGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(ui32Base + 0x0000002C))) &
           (0x00000080 | 0x00000004 | 0x00000002));
}
# 312 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTFIFOLevelSet(uint32_t ui32Base, uint32_t ui32TxLevel,
                 uint32_t ui32RxLevel)
{



    ;
   



                                            ;
   



                                            ;




    (*((volatile unsigned long *)(ui32Base + 0x00000034))) = ui32TxLevel | ui32RxLevel;
}
# 363 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTFIFOLevelGet(uint32_t ui32Base, uint32_t *pui32TxLevel,
                             uint32_t *pui32RxLevel);
# 401 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTConfigSetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                                uint32_t ui32Baud, uint32_t ui32Config);
# 426 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTConfigGetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                                uint32_t *pui32Baud, uint32_t *pui32Config);













static inline void
UARTEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) |= 0x00000010;




    (*((volatile unsigned long *)(ui32Base + 0x00000030))) |= (0x00000001 | 0x00000100 |
                                     0x00000200);
}













extern void NOROM_UARTDisable(uint32_t ui32Base);












static inline void
UARTFIFOEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) |= 0x00000010;
}












static inline void
UARTFIFODisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) &= ~(0x00000010);
}















static inline 
# 539 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTCharsAvail(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000010) ? 
# 550 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                         0 
# 550 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                               : 
# 550 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                 1
# 550 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                     );
}















static inline 
# 567 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTSpaceAvail(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000020) ? 
# 578 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                         0 
# 578 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                               : 
# 578 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                 1
# 578 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                     );
}
# 600 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern int32_t NOROM_UARTCharGetNonBlocking(uint32_t ui32Base);















extern int32_t NOROM_UARTCharGet(uint32_t ui32Base);
# 635 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern 
# 635 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
      _Bool 
# 635 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
           NOROM_UARTCharPutNonBlocking(uint32_t ui32Base, uint8_t ui8Data);















extern void NOROM_UARTCharPut(uint32_t ui32Base, uint8_t ui8Data);
# 669 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline 
# 669 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTBusy(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000008) ?
           0x00000001 : 0x00000000);
}
















static inline void
UARTBreakCtl(uint32_t ui32Base, 
# 700 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                               _Bool 
# 700 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                    bBreakState)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) =
         (bBreakState ?
         ((*((volatile unsigned long *)(ui32Base + 0x0000002C))) | 0x00000001) :
         ((*((volatile unsigned long *)(ui32Base + 0x0000002C))) & ~(0x00000001)));
}
# 735 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 754 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTIntUnregister(uint32_t ui32Base);
# 779 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000038))) |= ui32IntFlags;
}
# 815 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000038))) &= ~(ui32IntFlags);
}
# 853 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTIntStatus(uint32_t ui32Base, 
# 854 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                _Bool 
# 854 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                     bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(ui32Base + 0x00000040))));
    }
    else
    {
        return((*((volatile unsigned long *)(ui32Base + 0x0000003C))));
    }
}
# 912 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000044))) = ui32IntFlags;
}
# 947 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000048))) |= ui32DMAFlags;
}
# 978 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000048))) &= ~ui32DMAFlags;
}
# 1011 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTRxErrorGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(ui32Base + 0x00000004))) & 0x0000000F);
}















static inline void
UARTRxErrorClear(uint32_t ui32Base)
{



    ;





    (*((volatile unsigned long *)(ui32Base + 0x00000004))) = 0;
}












static inline void
UARTHwFlowControlEnable( uint32_t ui32Base )
{



    ;

    (*((volatile unsigned long *)(ui32Base + 0x00000030))) |= ( 0x00008000 | 0x00004000 );
}












static inline void
UARTHwFlowControlDisable( uint32_t ui32Base )
{



    ;

    (*((volatile unsigned long *)(ui32Base + 0x00000030))) &= ~( 0x00008000 | 0x00004000 );
}
# 196 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CMasterInitExpClk(uint32_t ui32Base, uint32_t ui32I2CClk,
                               _Bool 
# 197 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                    bFast);
# 223 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterControl(uint32_t ui32Base, uint32_t ui32Cmd)
{



    ;
   








                                                                ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = ui32Cmd;





    NOROM_CPUdelay(2);
}
# 272 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterSlaveAddrSet(uint32_t ui32Base, uint8_t ui8SlaveAddr,
                     _Bool 
# 274 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                          bReceive)
{



    ;
    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000800))) = (ui8SlaveAddr << 1) | bReceive;
}












static inline void
I2CMasterEnable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((4) << 2)))) = 1;


    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = 0x00000001;
}












static inline void
I2CMasterDisable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((4) << 2)))) = 0;
}















static inline 
# 350 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterBusy(uint32_t ui32Base)
{



    ;




    if((*((volatile unsigned long *)(0x40002000 + 0x00000804))) & 0x00000001)
    {
        return(
# 363 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              1
# 363 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                  );
    }
    else
    {
        return(
# 367 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              0
# 367 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                   );
    }
}
















static inline 
# 386 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterBusBusy(uint32_t ui32Base)
{



    ;




    if((*((volatile unsigned long *)(0x40002000 + 0x00000804))) & 0x00000040)
    {
        return(
# 399 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              1
# 399 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                  );
    }
    else
    {
        return(
# 403 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              0
# 403 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                   );
    }
}













static inline uint32_t
I2CMasterDataGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000808))));
}













static inline void
I2CMasterDataPut(uint32_t ui32Base, uint8_t ui8Data)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000808))) = ui8Data;
}
# 475 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern uint32_t NOROM_I2CMasterErr(uint32_t ui32Base);












static inline void
I2CMasterIntEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000810))) = 0x00000001;
}












static inline void
I2CMasterIntDisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000810))) = 0;
}
# 555 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterIntClear(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x0000081C))) = 0x00000001;
}
# 587 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline 
# 587 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterIntStatus(uint32_t ui32Base, 
# 588 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                     _Bool 
# 588 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                          bMasked)
{



    ;





    if(bMasked)
    {
        return(((*((volatile unsigned long *)(0x40002000 + 0x00000818)))) ? 
# 601 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                1 
# 601 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                     : 
# 601 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                       0
# 601 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                            );
    }
    else
    {
        return(((*((volatile unsigned long *)(0x40002000 + 0x00000814)))) ? 
# 605 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                1 
# 605 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                     : 
# 605 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                       0
# 605 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                            );
    }
}












static inline void
I2CSlaveEnable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((5) << 2)))) = 1;


    (*((volatile unsigned long *)(0x40002000 + 0x00000004))) = 0x00000001;
}
# 650 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveInit(uint32_t ui32Base, uint8_t ui8SlaveAddr)
{



    ;
    ;




    I2CSlaveEnable(0x40002000);




    (*((volatile unsigned long *)(0x40002000 + 0x00000000))) = ui8SlaveAddr;
}













static inline void
I2CSlaveAddressSet(uint32_t ui32Base, uint8_t ui8SlaveAddr)
{



    ;
    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000000))) = ui8SlaveAddr;
}












static inline void
I2CSlaveDisable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(0x40002000 + 0x00000004))) = 0x0;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((5) << 2)))) = 0;
}
# 737 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline uint32_t
I2CSlaveStatus(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000004))));
}













static inline uint32_t
I2CSlaveDataGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000008))));
}













static inline void
I2CSlaveDataPut(uint32_t ui32Base, uint8_t ui8Data)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000008))) = ui8Data;
}
# 821 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    uint32_t ui32Val;




    ;
   
                                               ;




    ui32Val = (*((volatile unsigned long *)(0x40002000 + 0x0000000C)));
    ui32Val |= ui32IntFlags;
    (*((volatile unsigned long *)(0x40002000 + 0x0000000C))) = ui32Val;
}
# 859 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    uint32_t ui32Val;




    ;
   
                                               ;




    ui32Val = (*((volatile unsigned long *)(0x40002000 + 0x0000000C)));
    ui32Val &= ~ui32IntFlags;
    (*((volatile unsigned long *)(0x40002000 + 0x0000000C))) = ui32Val;
}
# 912 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000018))) = ui32IntFlags;
}
# 946 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline uint32_t
I2CSlaveIntStatus(uint32_t ui32Base, 
# 947 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                    _Bool 
# 947 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                         bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(0x40002000 + 0x00000014))));
    }
    else
    {
        return((*((volatile unsigned long *)(0x40002000 + 0x00000010))));
    }
}
# 989 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 1007 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CIntUnregister(uint32_t ui32Base);
# 225 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIConfigSetExpClk(uint32_t ui32Base, uint32_t ui32SSIClk,
                               uint32_t ui32Protocol, uint32_t ui32Mode,
                               uint32_t ui32BitRate, uint32_t ui32DataWidth);













static inline void
SSIEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000004))) |= 0x00000002;
}












static inline void
SSIDisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000004))) &= ~(0x00000002);
}
# 298 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIDataPut(uint32_t ui32Base, uint32_t ui32Data);
# 319 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern int32_t NOROM_SSIDataPutNonBlocking(uint32_t ui32Base, uint32_t ui32Data);
# 342 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIDataGet(uint32_t ui32Base, uint32_t *pui32Data);
# 366 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern int32_t NOROM_SSIDataGetNonBlocking(uint32_t ui32Base, uint32_t *pui32Data);
# 384 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline 
# 384 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
               _Bool
SSIBusy(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x0000000C))) & 0x00000010) ? 
# 395 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                      1 
# 395 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                           : 
# 395 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                             0
# 395 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                                  );
}
# 415 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline uint32_t
SSIStatus(uint32_t ui32Base)
{



    ;




    return ((*((volatile unsigned long *)(ui32Base + 0x0000000C))) & 0x0000000F);
}
# 449 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 467 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIIntUnregister(uint32_t ui32Base);
# 487 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000014))) |= ui32IntFlags;
}
# 517 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000014))) &= ~(ui32IntFlags);
}
# 563 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000020))) = ui32IntFlags;
}
# 597 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline uint32_t
SSIIntStatus(uint32_t ui32Base, 
# 598 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                               _Bool 
# 598 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                    bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(ui32Base + 0x0000001C))));
    }
    else
    {
        return((*((volatile unsigned long *)(ui32Base + 0x00000018))));
    }
}
# 638 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000024))) |= ui32DMAFlags;
}
# 668 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000024))) &= ~ui32DMAFlags;
}
# 419 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPortConfigureSet(uint32_t ui32IOId, uint32_t ui32PortId,
                                uint32_t ui32IOConfig);
# 440 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern uint32_t NOROM_IOCPortConfigureGet(uint32_t ui32IOId);
# 460 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOShutdownSet(uint32_t ui32IOId, uint32_t ui32IOShutdown);
# 484 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOModeSet(uint32_t ui32IOId, uint32_t ui32IOMode);
# 508 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOIntSet(uint32_t ui32IOId, uint32_t ui32Int,
                        uint32_t ui32EdgeDet);
# 529 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOPortPullSet(uint32_t ui32IOId, uint32_t ui32Pull);
# 548 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOHystSet(uint32_t ui32IOId, uint32_t ui32Hysteresis);
# 567 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOInputSet(uint32_t ui32IOId, uint32_t ui32Input);
# 586 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOSlewCtrlSet(uint32_t ui32IOId, uint32_t ui32SlewEnable);
# 624 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIODrvStrengthSet(uint32_t ui32IOId, uint32_t ui32IOCurrent,
                                uint32_t ui32DrvStrength);
# 681 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOPortIdSet(uint32_t ui32IOId, uint32_t ui32PortId);
# 701 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
static inline void
IOCIntRegister(void (*pfnHandler)(void))
{



    NOROM_IntRegister(16, pfnHandler);




    ((void (*)(uint32_t ui32Interrupt)) ((uint32_t*) (((uint32_t *) 0x10000180)[12]))[4])(16);
}














static inline void
IOCIntUnregister(void)
{



    ((void (*)(uint32_t ui32Interrupt)) ((uint32_t*) (((uint32_t *) 0x10000180)[12]))[5])(16);




    NOROM_IntUnregister(16);
}














extern void NOROM_IOCIntEnable(uint32_t ui32IOId);
# 773 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIntDisable(uint32_t ui32IOId);
# 806 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
static inline void
IOCIntClear(uint32_t ui32IOId)
{



    ;




    GPIO_clearEventDio(ui32IOId);
}













static inline uint32_t
IOCIntStatus(uint32_t ui32IOId)
{



    ;




    return (GPIO_getEventDio(ui32IOId));
}
# 874 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeGpioInput(uint32_t ui32IOId);
# 903 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeGpioOutput(uint32_t ui32IOId);
# 942 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeUart(uint32_t ui32Base, uint32_t ui32Rx,
                           uint32_t ui32Tx, uint32_t ui32Cts,
                           uint32_t ui32Rts);
# 975 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeSsiMaster(uint32_t ui32Base, uint32_t ui32Rx,
                                uint32_t ui32Tx, uint32_t ui32Fss,
                                uint32_t ui32Clk);
# 1004 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeSsiSlave(uint32_t ui32Base, uint32_t ui32Rx,
                               uint32_t ui32Tx, uint32_t ui32Fss,
                               uint32_t ui32Clk);
# 1027 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeI2c(uint32_t ui32Base, uint32_t ui32Data,
                          uint32_t ui32Clk);
# 1051 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeAux(uint32_t ui32IOId);
# 75 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"







# 71 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"


# 68 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"


# 136 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
AuxAdiDdiSafeWrite(uint32_t nAddr, uint32_t nData, uint32_t nSize)
{

   _Bool 
# 140 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
        bIrqEnabled = !NOROM_CPUcpsid();

    while (!(*((volatile unsigned long *)(0x400C8000 + 0x00000000))));
    switch (nSize) {
    case 1: (*((volatile unsigned char *)(nAddr))) = (uint8_t)nData; break;
    case 2: (*((volatile unsigned short *)(nAddr))) = (uint16_t)nData; break;
    case 4: default: (*((volatile unsigned long *)(nAddr))) = nData; break;
    }
    (*((volatile unsigned long *)(0x400C8000 + 0x00000000))) = 1;

    if (bIrqEnabled) {
        NOROM_CPUcpsie();
    }
}














static inline uint32_t
AuxAdiDdiSafeRead(uint32_t nAddr, uint32_t nSize)
{
    uint32_t nRet;

   _Bool 
# 173 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
        bIrqEnabled = !NOROM_CPUcpsid();

    while (!(*((volatile unsigned long *)(0x400C8000 + 0x00000000))));
    switch (nSize) {
    case 1: nRet = (*((volatile unsigned char *)(nAddr))); break;
    case 2: nRet = (*((volatile unsigned short *)(nAddr))); break;
    case 4: default: nRet = (*((volatile unsigned long *)(nAddr))); break;
    }
    (*((volatile unsigned long *)(0x400C8000 + 0x00000000))) = 1;

    if (bIrqEnabled) {
        NOROM_CPUcpsie();
    }
    return nRet;
}
# 230 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline uint32_t
DDI32RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    return AuxAdiDdiSafeRead(ui32Base + ui32Reg, 4);
}
# 267 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI32BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000040;




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui32Val, 4);
}
# 307 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI32BitsClear(uint32_t ui32Base, uint32_t ui32Reg,
               uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000080;




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui32Val, 4);
}
# 358 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI8SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Byte,
              uint16_t ui16Mask, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000180 + (ui32Reg << 1) + (ui32Byte << 1);




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui16Mask << 8) | ui16Val, 2);
}
# 411 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI16SetValBit(uint32_t ui32Base, uint32_t ui32Reg, 
# 412 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
                                                   _Bool 
# 412 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
                                                        bWriteHigh,
               uint32_t ui32Mask, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000200 + (ui32Reg << 1) + (bWriteHigh ? 4 : 0);




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui32Mask << 16) | ui32Val, 4);
}
# 458 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI32RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val);
# 479 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI16BitWrite(uint32_t ui32Base, uint32_t ui32Reg,
                          uint32_t ui32Mask, uint32_t ui32WrData);
# 502 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI16BitfieldWrite(uint32_t ui32Base, uint32_t ui32Reg,
                               uint32_t ui32Mask, uint32_t ui32Shift,
                               uint16_t ui32Data);















extern uint16_t NOROM_DDI16BitRead(uint32_t ui32Base, uint32_t ui32Reg,
                             uint32_t ui32Mask);
# 541 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern uint16_t NOROM_DDI16BitfieldRead(uint32_t ui32Base, uint32_t ui32Reg,
                                  uint32_t ui32Mask, uint32_t ui32Shift);
# 149 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCXHfPowerModeSet(uint32_t ui32Mode)
{



   
                                         ;




    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32WrData)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[0])(0x400CA000, 0x00000000, 0x00000800,
                  ui32Mode);
}
















static inline void
OSCClockLossEventEnable( void )
{
    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift, uint16_t ui32Data)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[1])( 0x400CA000, 0x00000000,
        0x00000200,
        9, 1 );
}
















static inline void
OSCClockLossEventDisable( void )
{
    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift, uint16_t ui32Data)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[1])( 0x400CA000, 0x00000000,
        0x00000200,
        9, 0 );
}
# 249 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern void NOROM_OSCClockSourceSet(uint32_t ui32SrcClk, uint32_t ui32Osc);
# 272 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern uint32_t NOROM_OSCClockSourceGet(uint32_t ui32SrcClk);
















static inline 
# 289 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
               _Bool
OSCHfSourceReady(void)
{



    return (((uint16_t (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[3])(0x400CA000, 0x00000034,
                              0x00000001,
                              0)) ?
       1 
# 298 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
            : 
# 298 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
              0
# 298 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
                   ;
}
# 319 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCHfSourceSwitch(void)
{



    SafeHapiVoid( ((HARD_API_T*) 0x10000048)->HFSourceSafeSwitch );
}
# 347 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCInterfaceEnable(void)
{
}
# 370 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCInterfaceDisable(void)
{
}














extern uint32_t NOROM_OSCHF_GetStartupTime( uint32_t timeUntilWakeupInMs );












extern void NOROM_OSCHF_TurnOnXosc( void );















extern 
# 417 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
      _Bool 
# 417 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
           NOROM_OSCHF_AttemptToSwitchToXosc( void );












extern void NOROM_OSCHF_SwitchToRcOscTurnOffXosc( void );
# 450 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern uint32_t NOROM_OSCHF_DebugGetCrystalAmplitude( void );
















extern uint32_t NOROM_OSCHF_DebugGetExpectedAverageCrystalAmplitude( void );
# 498 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern int32_t NOROM_OSC_HPOSCRelativeFrequencyOffsetGet( int32_t tempDegC );
# 526 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern int16_t NOROM_OSC_HPOSCRelativeFrequencyOffsetToRFCoreFormatConvert( int32_t HPOSC_RelFreqOffset );
# 74 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"


# 133 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_ioc.h"
static inline void
AONIOCDriveStrengthSet(uint32_t ui32DriveLevel, uint32_t ui32DriveStrength)
{
   

                                                  ;
   






                                                   ;




    (*((volatile unsigned long *)(0x40094000 + ui32DriveLevel))) = ui32DriveStrength;
}
# 182 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_ioc.h"
static inline uint32_t
AONIOCDriveStrengthGet(uint32_t ui32DriveLevel)
{



   

                                                  ;




    return( (*((volatile unsigned long *)(0x40094000 + ui32DriveLevel))) );
}
















static inline void
AONIOCFreezeEnable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x0000000C))) = 0x0;
}















static inline void
AONIOCFreezeDisable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x0000000C))) = 0x00000001;
}














static inline void
AONIOC32kHzOutputDisable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x00000010))) = 0x00000001;
}














static inline void
AONIOC32kHzOutputEnable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x00000010))) = 0x0;
}
# 148 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32Reg))) = ui8Val;
    }
}
# 197 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16RegWrite(uint32_t ui32Base, uint32_t ui32Reg,
              uint16_t ui16Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 247 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 287 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI8RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + ui32Reg, 1);
    } else {
        return((*((volatile unsigned char *)(ui32Base + ui32Reg))));
    }
}
# 330 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI16RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + (ui32Reg & 0xFE), 2);
    } else {
        return((*((volatile unsigned short *)(ui32Base + (ui32Reg & 0xFE)))));
    }
}
# 371 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI32RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + (ui32Reg & 0xFC), 4);
    } else {
        return((*((volatile unsigned long *)(ui32Base + (ui32Reg & 0xFC)))));
    }
}
# 420 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset + ui32Reg))) = ui8Val;
    }
}
# 477 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 534 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 591 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset + ui32Reg))) = ui8Val;
    }
}
# 648 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 705 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 765 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI4SetValBit(uint32_t ui32Base, uint32_t ui32Reg, 
# 766 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
                                                  _Bool 
# 766 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
                                                       bWriteHigh,
              uint8_t ui8Mask, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000040 + (ui32Reg << 1) + (bWriteHigh ? 1 : 0);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui8Mask << 4) | ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset))) = (ui8Mask << 4) | ui8Val;
    }
}
# 823 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Mask,
              uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000060 + (ui32Reg << 1);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui16Mask << 8) | ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset))) = (ui16Mask << 8) | ui16Val;
    }
}
# 882 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask,
               uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000080 + ((ui32Reg << 1) & 0xFC);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui32Mask << 16) | ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset))) = (ui32Mask << 16) | ui32Val;
    }
}
# 161 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
extern void NOROM_PowerCtrlSourceSet(uint32_t ui32PowerConfig);
# 179 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
static inline uint32_t
PowerCtrlSourceGet(void)
{
    uint32_t ui32PowerConfig;




    ui32PowerConfig = (*((volatile unsigned long *)(0x40090000 + 0x00000000)));
    if(ui32PowerConfig & 0x00000004)
    {
        return (0x00000001);
    }
    else
    {
        return (0x00000000);
    }
}
# 221 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
static inline uint32_t
PowerCtrlResetSourceGet(void)
{



    return (( (*((volatile unsigned long *)(0x40090000 + 0x00000004))) &
        0x0000000E ) >>
        1 ) ;
}














static inline void
PowerCtrlIOFreezeEnable(void)
{



    AONIOCFreezeEnable();
    (*((volatile unsigned long *)(0x40090000 + 0x00000008))) = 0;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}















static inline void
PowerCtrlIOFreezeDisable(void)
{



    AONIOCFreezeDisable();
    (*((volatile unsigned long *)(0x40090000 + 0x00000008))) = 1;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 83 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"


# 155 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern void NOROM_AUXWUCClockEnable(uint32_t ui32Clocks);
# 182 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern void NOROM_AUXWUCClockDisable(uint32_t ui32Clocks);
# 209 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern uint32_t NOROM_AUXWUCClockStatus(uint32_t ui32Clocks);
# 231 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
static inline void
AUXWUCClockFreqReq(uint32_t ui32ClockFreq)
{



   
                                                   ;




    (*((volatile unsigned long *)(0x400C6000 + 0x00000010))) = ui32ClockFreq;
}
















extern void NOROM_AUXWUCPowerCtrl(uint32_t ui32PowerMode);
















static inline void
AUXWUCFreezeEnable(void)
{



    (*((volatile unsigned long *)(0x400C6000 + 0x00000054))) = 0x0;
}
# 303 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
static inline void
AUXWUCFreezeDisable(void)
{



    (*((volatile unsigned long *)(0x400C6000 + 0x00000054))) = 0x00000001;
}
# 225 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;




   
                                               ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000000)));
    ui32Reg &= ~0x00000003;
    (*((volatile unsigned long *)(0x40091000 + 0x00000000))) = ui32Reg |
                                             (ui32ClkSrc <<
                                              0);
}
# 264 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuPowerOffConfig(uint32_t ui32Mode)
{

   
                                                ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000008) & 0x000FFFFF) << 5) | ((17) << 2)))) = (ui32Mode != 0);
}
# 293 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuWakeUpConfig(uint32_t ui32WakeUp)
{

   
                                             ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000008) & 0x000FFFFF) << 5) | ((16) << 2)))) = (ui32WakeUp != 0);
}
# 330 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuSRamConfig(uint32_t ui32Retention)
{
    uint32_t ui32Reg;




    ;
    ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000008))) & ~0x0000000F;
    ui32Reg |= ui32Retention;
    (*((volatile unsigned long *)(0x40091000 + 0x00000008))) = ui32Reg;
}
# 370 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline uint32_t
AONWUCAuxClockConfigGet(void)
{



    return (((*((volatile unsigned long *)(0x40091000 + 0x00000004))) &
             0x00000700) >>
             8);
}
# 399 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;




   
                                               ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000004)));
    ui32Reg &= ~0x00001800;
    (*((volatile unsigned long *)(0x40091000 + 0x00000004))) = ui32Reg |
                                             (ui32ClkSrc <<
                                              11);
}
# 440 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxSRamConfig(uint32_t ui32Retention)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x0000000C) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Retention;
}
# 475 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxWakeupEvent(uint32_t ui32Mode)
{

   
                                                ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Mode;
}
















extern void NOROM_AONWUCAuxReset(void);











static inline void
AONWUCAuxImageValid(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((2) << 2)))) = 1;
}











static inline void
AONWUCAuxImageInvalid(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((2) << 2)))) = 0;
}
# 555 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline uint32_t
AONWUCPowerStatusGet(void)
{



    return ((*((volatile unsigned long *)(0x40091000 + 0x00000014))));
}
# 580 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCShutDownEnable(void)
{


    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
    (*((volatile unsigned long *)(0x40091000 + 0x00000018))) = 0x00000001;
}













static inline void
AONWUCDomainPowerDownEnable(void)
{


    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
}












static inline void
AONWUCDomainPowerDownDisable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 1;
}
# 655 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuResetClear(uint32_t ui32Status)
{



   
                                                ;




    (*((volatile unsigned long *)(0x40091000 + 0x00000024))) = ui32Status;
}










static inline uint32_t
AONWUCMcuResetStatusGet(void)
{



    return ((*((volatile unsigned long *)(0x40091000 + 0x00000024))));
}
# 741 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
extern void NOROM_AONWUCRechargeCtrlConfigSet(
# 741 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
                                       _Bool 
# 741 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
                                            bAdaptEnable,
                                        uint32_t ui32AdaptRate,
                                        uint32_t ui32Period,
                                        uint32_t ui32MaxPeriod);










static inline uint32_t
AONWUCRechargeCtrlConfigGet(void)
{



    return((*((volatile unsigned long *)(0x40091000 + 0x00000030))));
}
# 798 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
extern void NOROM_AONWUCOscConfig(uint32_t ui32Period);
















static inline void
AONWUCJtagPowerOff(void)
{



    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;
}
# 87 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"



# 150 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSConfigure(uint32_t ui32Base, 
# 150 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                            _Bool 
# 150 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                                 bRoundRobin,
                         _Bool 
# 151 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                              bPrefetch);
# 207 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSModeSet(uint32_t ui32Base, uint32_t ui32Mode);
# 226 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern uint32_t NOROM_VIMSModeGet(uint32_t ui32Base);
# 280 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSModeSafeSet( uint32_t ui32Base ,
                             uint32_t ui32NewMode ,
                            _Bool 
# 282 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                     blocking );















static inline void
VIMSLineBufDisable(uint32_t ui32Base)
{



    (*((volatile unsigned long *)(ui32Base + 0x00000004))) |= 0x00000020 |
                                        0x00000010;
}















static inline void
VIMSLineBufEnable(uint32_t ui32Base)
{



    (*((volatile unsigned long *)(ui32Base + 0x00000004))) &= ~(0x00000020 |
                                          0x00000010);
}
# 158 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlPowerEverything(void);













static inline uint32_t
SysCtrlClockGet( void )
{



    return( 48000000 );
}















static inline void
SysCtrlAonSync(void)
{



    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 222 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
static inline void
SysCtrlAonUpdate(void)
{




    (*((volatile unsigned long *)(0x40092000 + 0x0000002C))) = 1;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 257 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlSetRechargeBeforePowerDown( uint32_t xoscPowerMode );
# 279 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlAdjustRechargeAfterPowerDown( void );
# 297 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrl_DCDC_VoltageConditionalControl( void );
# 322 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern uint32_t NOROM_SysCtrlResetSourceGet( void );








static inline void
SysCtrlSystemReset( void )
{

   NOROM_CPUcpsid();

   (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((31) << 2)))) = 1;

   while ( 1 ) {

   }
}
# 361 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
static inline void
SysCtrlClockLossResetEnable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((4) << 2)))) = 1;
}














static inline void
SysCtrlClockLossResetDisable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((4) << 2)))) = 0;
}
# 173 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCEnable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
}















static inline void
AONRTCDisable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}










static inline void
AONRTCReset(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((7) << 2)))) = 1;
}










static inline 
# 232 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCActive(void)
{

    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))));
}
















static inline 
# 254 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCChannelActive(uint32_t ui32Channel)
{
    uint32_t uint32Status = 0;

    if(ui32Channel & 0x1)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2))));
    }

    if(ui32Channel & 0x2)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2))));
    }

    if(ui32Channel & 0x4)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2))));
    }

    return(uint32Status);
}
# 307 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCDelayConfig(uint32_t ui32Delay)
{
    uint32_t ui32Cfg;




    ;


    ui32Cfg = (*((volatile unsigned long *)(0x40092000 + 0x00000000)));
    ui32Cfg &= ~(0x00000F00);
    ui32Cfg |= (ui32Delay << 8);

    (*((volatile unsigned long *)(0x40092000 + 0x00000000))) = ui32Cfg;
}
# 344 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCCombinedEventConfig(uint32_t ui32Channels)
{
    uint32_t ui32Cfg;




   
                                               ;

    ui32Cfg = (*((volatile unsigned long *)(0x40092000 + 0x00000000)));
    ui32Cfg &= ~(0x00070000);
    ui32Cfg |= (ui32Channels << 16);

    (*((volatile unsigned long *)(0x40092000 + 0x00000000))) = ui32Cfg;
}
















static inline void
AONRTCEventClear(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00000001;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00000100;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00010000;
    }
}
# 418 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline 
# 418 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCEventGet(uint32_t ui32Channel)
{
    uint32_t uint32Event = 0;


   

                                        ;

    if(ui32Channel & 0x1)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((0) << 2))));
    }

    if(ui32Channel & 0x2)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((8) << 2))));
    }

    if(ui32Channel & 0x4)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((16) << 2))));
    }

    return(uint32Event);
}
# 466 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCSecGet(void)
{




    return((*((volatile unsigned long *)(0x40092000 + 0x00000008))));
}
# 496 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCFractionGet(void)
{








    return((*((volatile unsigned long *)(0x40092000 + 0x0000000C))));
}
# 528 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCSubSecIncrGet(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000010))));
}
# 554 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCModeCh1Set(uint32_t ui32Mode)
{

   
                                                  ;

    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((9) << 2)))) = ui32Mode;
}
















static inline uint32_t
AONRTCModeCh1Get(void)
{
    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((9) << 2)))));
}
# 608 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCModeCh2Set(uint32_t ui32Mode)
{

   
                                                        ;

    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((18) << 2)))) = ui32Mode;
}
# 636 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCModeCh2Get(void)
{
    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((18) << 2)))));
}
# 661 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCChannelEnable(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2)))) = 1;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2)))) = 1;
    }
}
# 704 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCChannelDisable(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2)))) = 0;
    }
}
# 751 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCCompareValueSet(uint32_t ui32Channel, uint32_t ui32CompValue)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000018))) = ui32CompValue;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x0000001C))) = ui32CompValue;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000020))) = ui32CompValue;
    }
}
















static inline uint32_t
AONRTCCompareValueGet(uint32_t ui32Channel)
{
    uint32_t ui32Value = 0;


   

                                        ;

    if(ui32Channel & 0x1)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x00000018)));
    }

    if(ui32Channel & 0x2)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x0000001C)));
    }

    if(ui32Channel & 0x4)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x00000020)));
    }

    return(ui32Value);
}
# 837 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
extern uint32_t NOROM_AONRTCCurrentCompareValueGet(void);













extern uint64_t NOROM_AONRTCCurrent64BitValueGet(void);
# 869 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCIncValueCh2Set(uint32_t ui32IncValue)
{
    (*((volatile unsigned long *)(0x40092000 + 0x00000024))) = ui32IncValue;
}
# 891 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCIncValueCh2Get(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000024))));
}













static inline uint32_t
AONRTCCaptureValueCh1Get(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000028))));
}
# 218 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventMcuWakeUpSet(uint32_t ui32MCUWUEvent,
                                 uint32_t ui32EventSrc);
# 267 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventMcuWakeUpGet(uint32_t ui32MCUWUEvent);
# 318 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventAuxWakeUpSet(uint32_t ui32AUXWUEvent,
                                 uint32_t ui32EventSrc);
# 366 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventAuxWakeUpGet(uint32_t ui32AUXWUEvent);
# 421 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventMcuSet(uint32_t ui32MCUEvent, uint32_t ui32EventSrc);
# 469 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventMcuGet(uint32_t ui32MCUEvent);
# 512 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
static inline void
AONEventRtcSet(uint32_t ui32EventSrc)
{
    uint32_t ui32Ctrl;




    ;

    ui32Ctrl = (*((volatile unsigned long *)(0x40093000 + 0x0000000C)));
    ui32Ctrl &= ~(0x0000003F);
    ui32Ctrl |= (ui32EventSrc & 0x3f) << 0;

    (*((volatile unsigned long *)(0x40093000 + 0x0000000C))) = ui32Ctrl;
}
# 568 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
static inline uint32_t
AONEventRtcGet(void)
{
    uint32_t ui32EventSrc;




    ui32EventSrc = (*((volatile unsigned long *)(0x40093000 + 0x0000000C)));

    return ((ui32EventSrc & 0x0000003F) >>
            0);
}
# 122 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline void
AONBatMonEnable(void)
{



    (*((volatile unsigned long *)(0x40095000 + 0x00000000))) =
        0x00000002 |
        0x00000001;
}











static inline void
AONBatMonDisable(void)
{



    (*((volatile unsigned long *)(0x40095000 + 0x00000000))) = 0;
}
# 170 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
extern int32_t NOROM_AONBatMonTemperatureGetDegC( void );
# 190 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline uint32_t
AONBatMonBatteryVoltageGet(void)
{
    uint32_t ui32CurrentBattery;

    ui32CurrentBattery = (*((volatile unsigned long *)(0x40095000 + 0x00000028)));




    return (ui32CurrentBattery >> 0);
}
# 223 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline 
# 223 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
               _Bool
AONBatMonNewBatteryMeasureReady(void)
{
   _Bool 
# 226 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
        bStatus;




    bStatus = (*((volatile unsigned long *)(0x40095000 + 0x0000002C))) &
              0x00000001 ? 
# 232 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                      1 
# 232 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                           : 
# 232 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                             0
# 232 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                                  ;




    if(bStatus)
    {
        (*((volatile unsigned long *)(0x40095000 + 0x0000002C))) = 1;
    }




    return (bStatus);
}
# 268 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline 
# 268 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
               _Bool
AONBatMonNewTempMeasureReady(void)
{
   _Bool 
# 271 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
        bStatus;




    bStatus = (*((volatile unsigned long *)(0x40095000 + 0x00000034))) &
              0x00000001 ? 
# 277 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                       1 
# 277 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                            : 
# 277 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                              0
# 277 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                                   ;




    if(bStatus)
    {
        (*((volatile unsigned long *)(0x40095000 + 0x00000034))) = 1;
    }




    return (bStatus);
}
# 68 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"

# 181 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCDisable(void);
# 214 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCEnableAsync(uint32_t refSource, uint32_t trigger);
# 263 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCEnableSync(uint32_t refSource, uint32_t sampleTime, uint32_t trigger);
















extern void NOROM_AUXADCDisableInputScaling(void);










extern void NOROM_AUXADCFlushFifo(void);









static inline void
AUXADCGenManualTrigger(void)
{
    (*((volatile unsigned long *)(0x400C9000 + 0x0000001C))) = 0;
}
# 323 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
static inline uint32_t
AUXADCGetFifoStatus(void)
{
    return (*((volatile unsigned long *)(0x400C9000 + 0x00000014)));
}















extern uint32_t NOROM_AUXADCReadFifo(void);













extern uint32_t NOROM_AUXADCPopFifo(void);
# 380 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
static inline void
AUXADCSelectInput(uint32_t input)
{
    SafeHapiAuxAdiSelect( ((HARD_API_T*) 0x10000048)->SelectADCCompBInput, input );
}
# 404 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCGetAdjustmentGain(uint32_t refSource);
# 425 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCGetAdjustmentOffset(uint32_t refSource);
# 446 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCValueToMicrovolts(int32_t fixedRefVoltage, int32_t adcValue);
# 467 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCMicrovoltsToValue(int32_t fixedRefVoltage, int32_t microvolts);
# 487 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCAdjustValueForGainAndOffset(int32_t adcValue, int32_t gain, int32_t offset);
# 509 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCUnadjustValueForGainAndOffset(int32_t adcValue, int32_t gain, int32_t offset);
# 28 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
# 57 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop
# 80 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 132 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 156 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 228 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : "sp");
}
# 252 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 282 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : "sp");
}
# 306 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 336 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 363 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri" : "=r" (result) );
  return(result);
}
# 415 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 440 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  __asm volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 481 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 735 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}








__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}








__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}








__attribute__((always_inline)) static inline int32_t __REVSH(int32_t value)
{

  return (short)__builtin_bswap16(value);






}









__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 845 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




   __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );












  return(result);
}
# 888 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint8_t) result);
}








__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint16_t) result);
}








__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}






__attribute__((always_inline)) static inline void __CLREX(void)
{
  __asm volatile ("clrex" ::: "memory");
}
# 1047 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}








__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint8_t) result);
}








__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint16_t) result);
}








__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *ptr)
{
    uint32_t result;

   __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
   return(result);
}








__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
   __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}








__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
   __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}








__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
   __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
#pragma GCC diagnostic pop
# 32 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"






typedef uint8_t Boolean;
typedef uint16_t word;
typedef int32_t sint;
typedef int16_t wint;
typedef int32_t lint;
typedef uint8_t byte;
typedef uint32_t lword;
typedef uint32_t aword;
typedef word *address;



typedef struct {

 byte pdmode:1,
  evntpn:1,
  fstblk:1,
  ledblk:1,
  ledsts:4;

 byte ledblc,

  reqpdm,
  effpdm;

 lword ondmns;

} systat_t;

extern volatile systat_t __pi_systat;

extern char *__bss_start__, *__bss_end__;
# 121 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"
void __pi_release () __attribute__ ((noreturn));
# 116 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"
void tci_run_delay_timer ();
void tci_run_auxiliary_timer ();
word tci_update_delay_ticks (Boolean);
# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/uart_def.h"







# 137 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"






typedef struct {
 uint32_t base;
 word rate;
 volatile byte flags;
} uart_t;





extern uart_t __pi_uart [];







word __pi_uart_getrate (const uart_t*);

Boolean __pi_uart_setrate (word, uart_t*);
# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/pins.h"







# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"












# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/analog_sensor.h"







# 11 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/sensors_sys.h"
typedef struct {

 lword W [3];

} i_sensdesc_t;

typedef struct {

 byte tp,
  dummy;
 word nsamples;
 word adcpars [4];

} a_sensdesc_t;

typedef struct {

 byte tp, num, dummy [2];
 void (*fun_val) (word, const byte*, address);
 void (*fun_ini) ();

} d_sensdesc_t;
# 74 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/sensors_sys.h"
void __pi_batmon (word, const byte*, address);
# 12 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/sensors.h"

void read_sensor (word, sint, address);



void wait_sensor (sint, word);
# 9 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/analog_sensor.h"



void analog_sensor_read (word, const a_sensdesc_t*, address);
# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/pin_sensor.h"














void pin_sensor_init ();
void pin_sensor_read (word, const byte*, address);
# 86 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"
Boolean __pi_pin_available (word);
Boolean __pi_pin_adc_available (word);
word __pi_pin_ivalue (word);
word __pi_pin_ovalue (word);
Boolean __pi_pin_adc (word);
Boolean __pi_pin_output (word);
void __pi_pin_set (word);
void __pi_pin_clear (word);
void __pi_pin_set_input (word);
void __pi_pin_set_output (word);
void __pi_pin_set_adc (word);
# 145 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"
typedef struct {

 byte pnum:7,
  edge:1;

} piniod_t;





extern const piniod_t __input_pins [];
void __pinlist_setirq (int);
# 9 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/pins.h"


# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/buttons.h"







# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/buttons_sys.h"





extern const word __button_list [];
# 29 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/buttons_sys.h"
void __buttons_setirq (int);
# 9 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/buttons.h"



void buttons_action (void (*action)(word));
# 193 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"
extern void __pi_ondomain (lword), __pi_offdomain (lword);

extern lword system_event_count;
# 364 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void root (word state);

typedef void (*fsmcode)(word);

void __pi_wait (aword, word);
void __pi_trigger (aword), __pi_ptrigger (aword, aword);
aword __pi_fork (fsmcode func, aword data);
aword __pi_join (aword, word);
void reset (void) __attribute__ ((noreturn)) ;
void halt (void) __attribute__ ((noreturn)) ;

int __pi_strlen (const char*);
void __pi_strcpy (char*, const char*);
void __pi_strncpy (char*, const char*, int);
void __pi_strcat (char*, const char*);
void __pi_strncat (char*, const char*, int);
void __pi_memcpy (char *dest, const char *src, int);
void __pi_memset (char *dest, char c, int);

extern const char __pi_hex_enc_table [];


extern const lword host_id;



aword *__pi_malloc (word);
void __pi_free (aword*);
void __pi_waitmem (word);


word __pi_memfree (address);
word __pi_maxfree (address);
# 423 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
word __pi_stackfree (void);







void __pi_syserror (word, const char*) __attribute__ ((noreturn)) ;
# 547 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void diag (const char *, ...);







lword lrnd (void);
# 575 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
sint io (word, word, word, char*, word);








void unwait (void);


void delay (word, word);
word dleft (aword);





void kill (aword);

void killall (fsmcode);






aword running (fsmcode);
word crunning (fsmcode);

fsmcode getcode (aword);

void proceed (word);

void setpowermode (word);



void utimer_add (address), utimer_delete (address);


void __pi_utimer_set (address, word);






void udelay (word);
void mdelay (word);
# 667 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void __pi_badstate (void);
# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/VNetI/tcv_defs.h"







typedef struct {






 word head,
  tail;
} tcvadp_t;




typedef struct {
 int (*tcv_ope) (int, int, va_list);
 int (*tcv_clo) (int, int);
 int (*tcv_rcv) (int, address, int, int*, tcvadp_t*);
 int (*tcv_frm) (address, tcvadp_t*);
 int (*tcv_out) (address);
 int (*tcv_xmt) (address);
 int (*tcv_tmt) (address);
 int tcv_info;
} tcvplug_t;




struct __tcv_qitem_s {
 struct __tcv_qitem_s *next,
    *prev;
};

typedef struct __tcv_qitem_s __tcv_qitem_t;
typedef struct __tcv_qitem_s __tcv_qhead_t;




struct __tcv_titem_s {

 struct __tcv_titem_s *next,
    *prev;
 word value;
};

typedef struct __tcv_titem_s __tcv_titem_t;

typedef struct {
 __tcv_titem_t *next,
    *prev;
} __tcv_thead_t;

typedef union {
 word value;
 struct {
  word queued:1,
   outgoing:1,
   urgent:1,
   session:7,
   plugin:3,
   phys:3;
 } b;
} __tcv_battr_t;




struct __tcv_hblock_s {



    union {
 __tcv_qitem_t bqueue;
 tcvadp_t pointers;





    } u;










 word length;




 __tcv_battr_t attributes;












};



typedef struct __tcv_hblock_s __tcv_hblock_t;

typedef struct {



 __tcv_qhead_t rqueue;



 __tcv_battr_t attpattern;














} __tcv_sesdesc_t;
# 168 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/VNetI/tcv_defs.h"
int tcv_plug (int, const tcvplug_t*);
int tcv_open (word, int, int, ...);
int tcv_close (word, int);
address tcv_rnp (word, int);
address tcv_wnps (word, int, int, Boolean);
int tcv_qsize (int, int);
int tcv_erase (int, int);
int tcv_read (address, byte*, int);
int tcv_write (address, const byte*, int);
void tcv_endp (address);
void tcv_drop (address);
int tcv_control (int, int, address);
# 728 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
extern lword entropy;
# 771 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/sysio.h"
typedef struct {



 word State;
 aword Event;
} __pi_event_t;

struct __pi_pcb_s {








 word Status;
 word Timer;
 fsmcode code;
 aword data;
 __pi_event_t Events [4];
 struct __pi_pcb_s *Next;
};

typedef struct __pi_pcb_s __pi_pcb_t;

extern __pi_pcb_t *__pi_curr;
# 12 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/ser.h"
int ser_out (word, const char*);
int ser_in (word, char*, int);
int ser_outb (word, const char*);
# 1 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/serf.h"







# 11 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/form.h"
word __pi_vfparse (char*, word, const char*, va_list);
char *vform (char*, const char*, va_list);
int vscan (const char*, const char*, va_list);
char *form (char*, const char*, ...);
word fsize (const char*, ...);
int scan (const char*, const char*, ...);
# 9 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/serf.h"



int ser_outf (word, const char*, ...);
int ser_inf (word, const char*, ...);
# 16 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/kernel/kernel.h"


void __pi_set_release (void);
void update_n_wake (word, Boolean);


void __pi_init_sensors (void);






extern word __pi_mintk;
extern volatile word __pi_old, __pi_new;

extern void tcv_init (void);

extern __pi_pcb_t *__PCB;
# 67 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/kernel/kernel.h"
typedef void (*devinitfun_t)(int param);
typedef int (*devreqfun_t)(int, char*, int);

typedef struct {



 devinitfun_t init;
 int param;
} devinit_t;

void adddevfunc (devreqfun_t, int);
# 10 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/CC13XX/phys_cc1350.h"
void phys_cc1350 (int, int);
# 12 "/home/stephen/Desktop/OLSONET/PICOS/PicOS/VLibs/PlugNull/plug_null.h"
extern const tcvplug_t plug_null;
# 25 "./header.hpp"
enum MessageType {
 DISCOVERY_REQUEST,
 DISCOVERY_RESPONSE,
 CREATE_RECORD,
 DELETE_RECORD,
 RETRIEVE_RECORD,
 RESPONSE
};

enum Status {
 OTHER_ERROR,
 SUCCESS,
 DB_FULL,
 DELETE_ERROR,
 RETRIEVE_ERROR
};



struct record{
 uint8_t owner_id;
 char data_entry[20];
 unsigned long timestamp;
};


struct data{
 struct record item_array[40];
 uint8_t item_count;
};





struct Node {
 uint8_t id;
 uint16_t gid;
 struct data data_base;
 uint8_t nnodes[25];
 uint8_t index;
};

struct DiscoveryRequestMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
};

struct DiscoveryResponseMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
};

struct CreateRecordMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
 char record[20];
};

struct DeleteRecordMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
 uint8_t record_index;
 uint8_t padding;
};


struct RetrieveRecordMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
 uint8_t record_index;
 uint8_t padding;
};





struct ResponseMessage{
 uint16_t gid;
 uint8_t tpe;
 uint8_t request_number;
 uint8_t sender_id;
 uint8_t receiver_id;
 uint8_t status;
 uint8_t padding;
 char record[20];
 uint8_t record_index;
};


_Bool 
# 131 "./header.hpp"
    init_node(struct Node *node);
_Bool 
# 132 "./header.hpp"
    set_node_id(struct Node *node, uint8_t id);
_Bool 
# 133 "./header.hpp"
    set_node_gid(struct Node *node, uint16_t gid);
_Bool 
# 134 "./header.hpp"
    set_node_db_entry_count(struct Node *node, uint8_t count);
_Bool 
# 135 "./header.hpp"
    clear_node_neighbour_array(struct Node *node);
_Bool 
# 136 "./header.hpp"
    insert_record(struct Node *node, char* new_entry, uint8_t owner_id);
_Bool 
# 137 "./header.hpp"
    delete_record(struct Node *node, uint8_t index);
_Bool 
# 138 "./header.hpp"
    delete_all(struct Node *node);
struct record retrieve_record(struct Node *node, uint8_t index);
void reset_array(struct Node *node);
uint8_t generate_request_num(void);
# 2 "app.cc"

char CHOICE;
char reason[50];
int sfd = -1;


int response_checker[2];
int discovery_wait_flag = 0;
char user_provided_record[20];
uint8_t user_provided_index;
uint8_t us_pr_in;
uint8_t get_id;
uint8_t beg_for_index;
uint8_t user_provided_receiver_id;
word response_flag=0;

struct Node *node_db;




_Bool 
# 23 "app.cc"
    init_node(struct Node* node){
    node->id = 0;
    node->gid = 0;
    node->index = 0;
    node->data_base;
    node->data_base.item_count = 0;

 reset_array(node);




    if ((!node->id) && (!node->gid) && (!node->index) && (sizeof(node->data_base) == 0)){
        return 
# 36 "app.cc"
              1
# 36 "app.cc"
                  ;
    }
    diag("Error initializing node...\n");
    return 
# 39 "app.cc"
          0
# 39 "app.cc"
               ;
};

_Bool 
# 42 "app.cc"
    set_node_id(struct Node* node, uint8_t id){
    node->id = id;
    return node->id == id;
};

_Bool 
# 47 "app.cc"
    set_node_gid(struct Node* node, uint16_t gid){
    node->gid = gid;
    return node->gid == gid;
};


_Bool 
# 53 "app.cc"
    set_node_db_entry_count(struct Node* node, uint8_t count){
    node->index = count;
    return node->index == count;
};



void reset_array(struct Node *node) {
 for (int i=0; i<25; i++) {
  node->nnodes[i] = 0;
 }
}


uint8_t generate_request_num(void){
    return (uint8_t) (rand() % 255);
}


_Bool 
# 72 "app.cc"
    insert_record(struct Node *node, char* new_entry, uint8_t owner_id){


    int num;


    if (node->data_base.item_count == 40){
        return 
# 79 "app.cc"
              0
# 79 "app.cc"
                   ;
    } else {


        for (int i = 0; i < 40; i++){
            if (node->data_base.item_array[i].data_entry == 
# 84 "app.cc"
                                                           ((void *)0)
# 84 "app.cc"
                                                               ){
             num = i;
                __pi_strncpy (node->data_base.item_array[i].data_entry, new_entry, sizeof(new_entry));
                node->data_base.item_array[i].owner_id = owner_id;

                node->data_base.item_array[i].timestamp = AONRTCSecGet ();
                node->data_base.item_count += 1;
                break;
            };
        };
    };


    if(node->data_base.item_array[num].data_entry == 
# 97 "app.cc"
                                                    ((void *)0)
# 97 "app.cc"
                                                        ){
     return 
# 98 "app.cc"
           0
# 98 "app.cc"
                ;
    }
    return 
# 100 "app.cc"
          1
# 100 "app.cc"
              ;
};


_Bool 
# 104 "app.cc"
    clear_node_neighbour_array(struct Node *node){

    if (!sizeof(node->nnodes)){
        return 
# 107 "app.cc"
              1
# 107 "app.cc"
                  ;
    } else{
        for (int i = 0; i < 25; i++){
            node->nnodes[i] = 0;
        };
        return 
# 112 "app.cc"
              1
# 112 "app.cc"
                  ;
    };

    return 
# 115 "app.cc"
          0
# 115 "app.cc"
               ;

};


_Bool 
# 120 "app.cc"
    delete_record(struct Node *node, uint8_t index){


    if (node->data_base.item_count == 0 || node->data_base.item_array[index].data_entry == 
# 123 "app.cc"
                                                                                          ((void *)0)
# 123 "app.cc"
                                                                                              ){
        return 
# 124 "app.cc"
              0
# 124 "app.cc"
                   ;
    } else{

        node->data_base.item_array[index].data_entry[0] = '\0';
        node->data_base.item_array[index].timestamp = 0;
        node->data_base.item_count -= 1;
    };


    if(node->data_base.item_array[index].data_entry != 
# 133 "app.cc"
                                                      ((void *)0)
# 133 "app.cc"
                                                          ){
     return 
# 134 "app.cc"
           0
# 134 "app.cc"
                ;
    }
    return 
# 136 "app.cc"
          1
# 136 "app.cc"
              ;
};


struct record retrieve_record(struct Node *node, uint8_t index){


    return node->data_base.item_array[index];

};


_Bool 
# 148 "app.cc"
    delete_all(struct Node *node){


    if (node->data_base.item_count == 0 || node->data_base.item_array[0].data_entry == 
# 151 "app.cc"
                                                                                      ((void *)0)
# 151 "app.cc"
                                                                                          ){
        return 
# 152 "app.cc"
              1
# 152 "app.cc"
                  ;
    } else{
        for(int i = 0; i <= node->data_base.item_count; i++){
            node->data_base.item_array[i].data_entry[0] = '\0';
            node->data_base.item_array[i].timestamp = 0;
        }
    };
    node->data_base.item_count = 0;

    if(node->data_base.item_array[0].data_entry != 
# 161 "app.cc"
                                                  ((void *)0)
# 161 "app.cc"
                                                      ){
     return 
# 162 "app.cc"
           0
# 162 "app.cc"
                ;
    }
    return 
# 164 "app.cc"
          1
# 164 "app.cc"
              ;
}

struct ResponseMessage *assemble_response_message(uint16_t gid, uint8_t request_number, uint8_t sender_id, uint8_t receiver_id, uint8_t status, uint8_t padding, char rec[20]){
 struct ResponseMessage *response_message = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));

 response_message->gid = gid;
 response_message->tpe = RESPONSE;
 response_message->request_number = request_number;
 response_message->sender_id = sender_id;
 response_message->receiver_id = receiver_id;
 response_message->status = status;
 if (!padding){
  response_message->padding = padding;
 };
 if (rec != 
# 179 "app.cc"
           ((void *)0)
# 179 "app.cc"
               ){
  __pi_strncpy (response_message->record, rec, 20);
 };

 return response_message;

};



#define sending 0
#define CONFIRM_message 1
# 188 "app.cc"
void sender (word __pi_st) { struct ResponseMessage * message = (struct ResponseMessage *)(__pi_curr->data); switch (__pi_st) { 
# 188 "app.cc"

 static address packet;

 static int packet_size=sizeof (struct ResponseMessage );

 case sending : __stlab_sending: {
  packet = tcv_wnps (sending, sfd, 4 + packet_size, 0);
  packet[0] = 0;
  packet[1] = message->gid;
  char * p = (char *)(packet+2);

  diag("SENDING PROCEDURE");
  diag("I am th message GID %d", message->receiver_id);


  *p = message->tpe;p++;
  *p = message->request_number;p++;
  *p = message->sender_id;p++;
  *p = message->receiver_id;p++;

  switch(message->tpe) {

   case CREATE_RECORD:


    __pi_strncpy (p, message->record, sizeof(message->record));
    break;


   case DELETE_RECORD:
   case RETRIEVE_RECORD:

    *p = message->record_index;p++;
    *p = message->padding;
    break;


   case RESPONSE:

    *p = message->status;p++;
    *p = message->padding;p++;

    __pi_strncpy (p, message->record, sizeof(message->record));
    break;


   default:

    break;
  }

  tcv_endp(packet);

 } case CONFIRM_message : __stlab_CONFIRM_message: {

  ser_out(CONFIRM_message, "Message sent\r\n");

  kill (0);
break; } default: __pi_badstate (); } }
#undef sending
#undef CONFIRM_message

#define receiving 0
#define ok 1
#define done_case 2
#define response_1_create 3
#define response_1_delete 4
#define response_1_retrieve 5
#define response_2 6
#define response_3 7
#define response_4 8
#define error 9
# 249 "app.cc"
void receiver (word __pi_st) { struct Node * node_db = (struct Node *)(__pi_curr->data); switch (__pi_st) { 
# 249 "app.cc"

 static struct ResponseMessage *response_message_5;

 static address incoming_packet;
 static char array[20];

 case receiving : __stlab_receiving: {

  incoming_packet = tcv_rnp(receiving, sfd);
 } case ok : __stlab_ok: {


  response_message_5 = (struct ResponseMessage *)(incoming_packet+1);
  diag("\r\nTPE: %d", response_message_5->tpe);





  switch (response_message_5->tpe){













   case DISCOVERY_REQUEST: ;

    struct ResponseMessage *response_message_0 = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));

    struct DiscoveryRequestMessage *discovery_request_message = (struct DiscoveryRequestMessage*)(incoming_packet+1);











    if (discovery_request_message->gid == node_db->gid){
     diag("\r\nSending to sender");
     response_message_0->gid = discovery_request_message->gid;
     response_message_0->tpe = DISCOVERY_RESPONSE;
     response_message_0->request_number = discovery_request_message->request_number;
     response_message_0->sender_id = node_db->id;
     response_message_0->receiver_id = discovery_request_message->sender_id;


     diag("\r\nSending to sender");
     do { if (__pi_join (__pi_fork (sender, (aword)(response_message_0 )), done_case )) __pi_release (); } while (0);
    }

    break;









   case DISCOVERY_RESPONSE: ;

    struct DiscoveryResponseMessage* response_message_1 = (struct DiscoveryResponseMessage*)(incoming_packet+1);









    node_db->nnodes[node_db->index] = node_db->gid == response_message_1->gid && response_message_1->sender_id < 25 && response_message_1->sender_id > 0 ? response_message_1->sender_id : node_db->nnodes[node_db->index];

    if (node_db->nnodes[node_db->index] == response_message_1->sender_id){
     node_db->index+=1;
    };

    break;




   case CREATE_RECORD: ;
    struct ResponseMessage *response_message_2 = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));
    struct CreateRecordMessage* create_record_message = (struct CreateRecordMessage*)(incoming_packet+1);
   _Bool 
# 347 "app.cc"
        neighbour_check = 
# 347 "app.cc"
                          0
# 347 "app.cc"
                               ;
    uint8_t status;











    if (create_record_message->receiver_id != node_db->id || create_record_message->gid != node_db->gid){
     diag("\r\nCreate rec we broke");
     break;
    };


    diag("\r\nCreate rec inbetween if: Size of rec = %d", sizeof(create_record_message->record));
    if (sizeof(create_record_message->record) <= 20 && sizeof(create_record_message->record) > 0) {

     diag("\r\nCreate rec second if");
     if (insert_record(node_db, create_record_message->record, create_record_message->sender_id)){
      diag("\r\nCreate rec third if");
      status = (uint8_t) SUCCESS;
     } else{
      diag("\r\nCreate rec third else");
      status = (uint8_t) DB_FULL;
     };
     diag("\r\nCreate rec out if");
     response_message_2 = assemble_response_message(node_db->gid, create_record_message->request_number, node_db->id, create_record_message->receiver_id, status, 0, array);
     diag("\r\nCreate rec sending to sender");
     do { if (__pi_join (__pi_fork (sender, (aword)(response_message_2 )), done_case )) __pi_release (); } while (0);

    };

    break;

   case DELETE_RECORD: ;
    struct ResponseMessage *response_message_3 = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));
    struct DeleteRecordMessage *delete_record_message = (struct DeleteRecordMessage*)(incoming_packet+1);

    diag("\r\nDelete rec");








    diag("delete record gid %d\nnode_db gid %d\n delete record receiver id %d\n, node db id %d", delete_record_message->gid, node_db->gid, delete_record_message->receiver_id, node_db->id);
    if (delete_record_message->gid != node_db->gid || delete_record_message->receiver_id != node_db->id){
     diag("\r\nDelete rec first if");
     break;
    };


    if (delete_record_message->record_index >=0 && delete_record_message->record_index <= 40){
     diag("\r\nDelete rec second if");

     if (delete_record(node_db, delete_record_message->record_index)){
      status = (uint8_t) SUCCESS;
      diag("\r\nDelete rec third if");
     } else{
      status = (uint8_t) DELETE_ERROR;
      diag("\r\nDelete rec fourth if");
     };

     diag("\r\nDelete assemble le response");
     response_message_3 = assemble_response_message(node_db->gid, delete_record_message->request_number, node_db->id, delete_record_message->receiver_id, status, 0, array);
     do { if (__pi_join (__pi_fork (sender, (aword)(response_message_3 )), done_case )) __pi_release (); } while (0);

    };

    break;


   case RETRIEVE_RECORD: ;
    struct ResponseMessage *response_message_4 = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));
    struct RetrieveRecordMessage *retreive_record_message = (struct RetrieveRecordMessage*)(incoming_packet+1);
    struct record retrieved_record;

    diag("\r\nretrieve rec");


    if (delete_record_message->gid != node_db->gid || delete_record_message->receiver_id != node_db->id){
     break;
    };


    if (retreive_record_message->record_index >=0 && retreive_record_message->record_index <= 40){
     retrieved_record = retrieve_record(node_db, retreive_record_message->record_index);
     if (retrieved_record.data_entry == 
# 441 "app.cc"
                                       ((void *)0)
# 441 "app.cc"
                                           ){
      status = (uint8_t) RETRIEVE_ERROR;
      response_message_4 = assemble_response_message(node_db->gid, retreive_record_message->request_number, node_db->id, retreive_record_message->receiver_id, status, 0, retrieved_record.data_entry);

     } else {
      status = (uint8_t) SUCCESS;
      response_message_4 = assemble_response_message(node_db->gid, retreive_record_message->request_number, node_db->id, retreive_record_message->receiver_id, status, 0, retrieved_record.data_entry);

     };
     do { if (__pi_join (__pi_fork (sender, (aword)(response_message_4 )), done_case )) __pi_release (); } while (0);
    };

    break;

   case RESPONSE: ;
    response_message_5 = (struct ResponseMessage*)(incoming_packet+1);

    diag("\r\nResponse");

    if (response_message_5->gid != node_db->gid || response_message_5->receiver_id != node_db->id){
     break;
    };

    if(!response_flag){
     response_flag=1;
     __pi_trigger ((aword)(&response_flag));
    }

    switch(response_message_5->status){

     case OTHER_ERROR:
      break;
     case SUCCESS:
      if (response_checker[0] == response_message_5->request_number){
       switch(response_checker[1]){
        case CREATE_RECORD:
         proceed (response_1_create);
         break;
        case DELETE_RECORD:
         proceed (response_1_delete);
         break;
        case RETRIEVE_RECORD:
         proceed (response_1_retrieve);
         break;
        default:
         break;
       }
      }
      break;
     case DB_FULL:
      proceed (response_2);
      break;
     case DELETE_ERROR:
      proceed (response_3);
      break;
     case RETRIEVE_ERROR:
      proceed (response_4);
      break;
     default:
      break;

    };

    break;


   default:
    diag("ERROR: received type [%d] is not legal packet type", response_message_5->tpe);
    break;

  };
 } case done_case : __stlab_done_case: {
  tcv_endp(incoming_packet);
  proceed (receiving);


 } case response_1_create : __stlab_response_1_create: {
  ser_out(response_1_create, "\r\nData Saved");
  proceed (receiving);
 } case response_1_delete : __stlab_response_1_delete: {
  ser_out(response_1_delete, "\r\nRecord Deleted");
  proceed (receiving);
 } case response_1_retrieve : __stlab_response_1_retrieve: {
  ser_outf(response_1_retrieve, "\r\nRecord Received from %d: %s", response_message_5->sender_id, response_message_5->record);
  proceed (receiving);


 } case response_2 : __stlab_response_2: {
  ser_outf(response_2, "\r\nThe record can't be saved on node %d", response_message_5->sender_id);
  proceed (receiving);
 } case response_3 : __stlab_response_3: {
  ser_outf(response_3, "\r\nThe record does not exists on node %d", response_message_5->sender_id);
  proceed (receiving);
 } case response_4 : __stlab_response_4: {
  ser_outf(response_4, "\r\nThe record does not exist on node %d", response_message_5->sender_id);
  proceed (receiving);


 } case error : __stlab_error: {
  diag("ERROR: someting went wrong when receiving the packet");


  proceed (receiving);

break; } default: __pi_badstate (); } }
#undef receiving
#undef ok
#undef done_case
#undef response_1_create
#undef response_1_delete
#undef response_1_retrieve
#undef response_2
#undef response_3
#undef response_4
#undef error
# 545 "app.cc"



#define initialize_node 0
#define menu 1
#define get_choice 2
#define get_new_group_id 3
#define new_group_id 4
#define get_new_node_id 5
#define new_node_id 6
#define invalid_node_id 7
#define clear_neighbour_array 8
#define find_proto_start 9
#define wait_discovery 10
#define display_neighbour_nodes 11
#define create_proto_start 12
#define get_id_for_create 13
#define ask_for_record_to_create 14
#define get_record_to_create 15
#define init_create_record_message 16
#define start_delete_proto 17
#define get_id_for_delete 18
#define ask_for_record_index 19
#define get_index_for_delete 20
#define init_delete_record_message 21
#define start_retrieve_proto 22
#define get_id_for_retrieve 23
#define ask_for_record_retrieve_index 24
#define get_index_for_retrieve 25
#define retrieve_proto 26
#define display_db 27
#define loop_through_data 28
#define del_local 29
#define wait 30
#define timeout 31
#define error 32
# 547 "app.cc"
void root (word __pi_st) { switch (__pi_st) { 
# 547 "app.cc"









 case initialize_node : __stlab_initialize_node: {


  node_db = (struct Node *)((address)__pi_malloc (sizeof(struct Node)));


  init_node(node_db);

  phys_cc1350(0, 250);













  tcv_plug (0, &plug_null);
















  sfd = tcv_open (((word)(-1)), 0, 0);

  if (sfd < 0) {
   diag("Cannot open tcv interface");
   halt();
  };







  tcv_control(sfd, 4, 
# 608 "app.cc"
                              ((void *)0)
# 608 "app.cc"
                                  );

  __pi_fork (receiver, (aword)(node_db ));

 } case menu : __stlab_menu: {
  ser_outf(menu, "\r\nGroup %d Device #%d (%d/%d records)\r\n(G)roup ID\r\n(N)ew device ID\r\n(F)ind neighbors\r\n(C)reate record on neighbor\r\n(D)elete record on neighbor\r\n(R)etrieve record from neighbor\r\n(S)how local records\r\nR(e)set local storage\r\n\r\nSelection: ", node_db->gid, node_db->id, node_db->index, 40);

 } case get_choice : __stlab_get_choice: {
  ser_inf(get_choice, "%c", &CHOICE);
  switch(CHOICE) {
   case 'g':
   case 'G':
    proceed (get_new_group_id);
    break;
   case 'n':
   case 'N':
    proceed (get_new_node_id);
    break;
   case 'f':
   case 'F':
    proceed (clear_neighbour_array);
    break;
   case 'c':
   case 'C':
    proceed (create_proto_start);
    break;

   case 'd':
   case 'D':
    proceed (start_delete_proto);
    break;
   case 'r':
   case 'R':
    proceed (start_retrieve_proto);
    break;
   case 's':
   case 'S':
    proceed (display_db);
    break;
   case 'e':
   case 'E':
    proceed (del_local);
    break;
   default:
    proceed (menu);
    break;
  }

 } case get_new_group_id : __stlab_get_new_group_id: {
  ser_out(get_new_group_id, "Please provide a new group ID#: ");


 } case new_group_id : __stlab_new_group_id: {
  uint16_t NEW_NODE_GID;
  ser_inf(new_group_id, "%u", &NEW_NODE_GID);

  diag("setting node group ID");

  if (!set_node_gid(node_db, NEW_NODE_GID)){
   diag("setting node group ID failed");
   __pi_strncpy (reason, "Error setting node ID", 50);
   proceed (invalid_node_id);
  };

  proceed (menu);

 } case get_new_node_id : __stlab_get_new_node_id: {
  ser_out(get_new_node_id, "\r\nPlease provide a new node ID# (1-25 inclusive): ");

 } case new_node_id : __stlab_new_node_id: {
  uint8_t NEW_NODE_ID;
  ser_inf(new_node_id, "%u", &NEW_NODE_ID);


  if (!set_node_id(node_db, NEW_NODE_ID)) {
   __pi_strncpy (reason, "Error setting node ID", 50);
   proceed (invalid_node_id);
  };


  if((node_db->id < 1) || (node_db->id > 25)){
   __pi_strncpy (reason, "Out of Range", 50);
   proceed (invalid_node_id);
  };


  for(int i = 0; i < node_db->index; i++){
   if(node_db->id == node_db->nnodes[i]){
    __pi_strncpy (reason, "ID is already in use", 50);
    proceed (invalid_node_id);
   };
  };

  proceed (menu);


 } case invalid_node_id : __stlab_invalid_node_id: {

  ser_outf(invalid_node_id, "\r\nID#: %u, is an invalid choice. Reason: %s.", node_db->id, reason);
  proceed (get_new_node_id);












 } case clear_neighbour_array : __stlab_clear_neighbour_array: {
  if (!clear_node_neighbour_array(node_db)){
   __pi_strncpy (reason, "Error Clearing Node Array", 50);
   proceed (error);
  };

 } case find_proto_start : __stlab_find_proto_start: {

  struct ResponseMessage *request_packet;
  request_packet = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));

  request_packet->gid = node_db->gid;
  request_packet->tpe = DISCOVERY_REQUEST;
  request_packet->request_number = generate_request_num();
  request_packet->sender_id = node_db->id;
  request_packet->receiver_id=0;

  do { if (__pi_join (__pi_fork (sender, (aword)(request_packet )), wait_discovery )) __pi_release (); } while (0);

 } case wait_discovery : __stlab_wait_discovery: {
  if (discovery_wait_flag == 0){
   discovery_wait_flag=1;
   delay(3000, find_proto_start);
   __pi_release ();
  }
  if (discovery_wait_flag == 1){
   discovery_wait_flag=0;
   delay(3000, display_neighbour_nodes);
   __pi_release ();
  }

 } case display_neighbour_nodes : __stlab_display_neighbour_nodes: {
  if(node_db->index == 0){
   proceed (menu);
  }
  for (int i=0; i<node_db->index; i++) {
   if(i == 0){
    ser_out(display_neighbour_nodes, "\r\nNeighbors: ");
   }
   ser_outf(display_neighbour_nodes, "%u, ", node_db->nnodes[i]);
  }
  proceed (menu);











 } case create_proto_start : __stlab_create_proto_start: {
  ser_out(create_proto_start, "Please provide a node ID (0-25): ");

 } case get_id_for_create : __stlab_get_id_for_create: {
  ser_inf(get_id_for_create, "%d", &user_provided_receiver_id);

  if ((user_provided_receiver_id < 1) || (user_provided_receiver_id > 25)){
   __pi_strncpy (reason, "Error: improper ID", 50);
   proceed (error);
  };

 } case ask_for_record_to_create : __stlab_ask_for_record_to_create: {
  ser_out(ask_for_record_to_create, "Please provide a record (length <= 20): ");

 } case get_record_to_create : __stlab_get_record_to_create: {
  ser_in(get_record_to_create, user_provided_record, 20);

 } case init_create_record_message : __stlab_init_create_record_message: {

  struct ResponseMessage *create_message;
  create_message = (struct ResponseMessage*)((address)__pi_malloc (sizeof(struct ResponseMessage)));
  create_message->gid = node_db->gid;
  create_message->tpe = CREATE_RECORD;
  create_message->request_number = generate_request_num();
  create_message->sender_id = node_db->id;
  create_message->receiver_id = user_provided_receiver_id;
  __pi_strncpy (create_message->record, user_provided_record, 20);


  response_checker[0] = create_message->request_number;
  response_checker[1] = create_message->tpe;

  do { if (__pi_join (__pi_fork (sender, (aword)(create_message )), wait )) __pi_release (); } while (0);










 } case start_delete_proto : __stlab_start_delete_proto: {
  ser_out(start_delete_proto, "Please provide a node ID (0-25): ");

 } case get_id_for_delete : __stlab_get_id_for_delete: {
  ser_inf(get_id_for_delete, "%d", &user_provided_receiver_id);

  if ((user_provided_receiver_id < 1) || (user_provided_receiver_id > 25)){
   __pi_strncpy (reason, "Error: improper node ID", 50);
   proceed (error);
  };

 } case ask_for_record_index : __stlab_ask_for_record_index: {
  ser_out(ask_for_record_index, "Please provide the record index (0-40): ");

 } case get_index_for_delete : __stlab_get_index_for_delete: {
  ser_inf(get_index_for_delete, "%d", &us_pr_in);

  if (us_pr_in < 0 || us_pr_in > 40){
   __pi_strncpy (reason, "Error: invalid index", 50);
   proceed (error);
  };

 } case init_delete_record_message : __stlab_init_delete_record_message: {

  struct ResponseMessage *delete_record;
  delete_record = (struct ResponseMessage *)((address)__pi_malloc (sizeof(struct ResponseMessage)));
  delete_record->gid = node_db->gid;
  delete_record->tpe = DELETE_RECORD;
  delete_record->request_number = generate_request_num();
  delete_record->sender_id = node_db->id;
  delete_record->receiver_id = user_provided_receiver_id;
  delete_record->record_index = us_pr_in;



  response_checker[0] = delete_record->request_number;
  response_checker[1] = delete_record->tpe;

  do { if (__pi_join (__pi_fork (sender, (aword)(delete_record )), wait )) __pi_release (); } while (0);










 } case start_retrieve_proto : __stlab_start_retrieve_proto: {
  ser_out(start_retrieve_proto, "Please provide a node ID (0-25): ");

 } case get_id_for_retrieve : __stlab_get_id_for_retrieve: {
  ser_inf(get_id_for_retrieve, "%d", &get_id);

  if (get_id < 1 || get_id > 25){
   __pi_strncpy (reason, "Error: improper node ID", 50);
   proceed (error);
  };

 } case ask_for_record_retrieve_index : __stlab_ask_for_record_retrieve_index: {
  ser_out(ask_for_record_retrieve_index, "Please provide the record index (0-40): ");

 } case get_index_for_retrieve : __stlab_get_index_for_retrieve: {
  ser_inf(get_index_for_retrieve, "%u", &beg_for_index);

  if (beg_for_index < 0 || beg_for_index > 40){
   __pi_strncpy (reason, "Error: invalid index", 50);
   proceed (error);
  };

 } case retrieve_proto : __stlab_retrieve_proto: {

  diag("\r\nret ID: %d", get_id);

  struct ResponseMessage *retrieve_record;
  retrieve_record = (struct ResponseMessage *)((address)__pi_malloc (sizeof(struct ResponseMessage)));
  retrieve_record->gid = node_db->gid;
  retrieve_record->tpe = RETRIEVE_RECORD;
  retrieve_record->request_number = generate_request_num();
  retrieve_record->sender_id = node_db->id;
  retrieve_record->receiver_id = get_id;
  retrieve_record->record_index = beg_for_index;

  diag("\r\nret ID: %d", get_id);

  response_checker[0] = retrieve_record->request_number;
  response_checker[1] = retrieve_record->tpe;
  diag("\r\nret ID: %d", retrieve_record->receiver_id);

  do { if (__pi_join (__pi_fork (sender, (aword)(retrieve_record )), wait )) __pi_release (); } while (0);

 } case display_db : __stlab_display_db: {
  ser_out(display_db, "\r\nIndex\tTime Stamp\t\tOwner ID\tRecord Data");

 } case loop_through_data : __stlab_loop_through_data: {
  if(node_db->data_base.item_count != 0){
   for(int i = 0; i <= node_db->data_base.item_count; i++){
    ser_outf(loop_through_data, "\r\n%d\t%u\t\t\t%u\t%s", i, node_db->data_base.item_array[i].timestamp, node_db->data_base.item_array[i].owner_id, node_db->data_base.item_array[i].data_entry);
   }
  }
  ser_out(loop_through_data, "\r\n");
  proceed (menu);

 } case del_local : __stlab_del_local: {
  delete_all(node_db);
  proceed (menu);

 } case wait : __stlab_wait: {
  delay(3000, timeout);
  __pi_wait ((aword)(&response_flag),menu);
  __pi_release ();

 } case timeout : __stlab_timeout: {
  ser_out(timeout, "\r\nFailed to reach the destination");
  proceed (menu);


 } case error : __stlab_error: {
  ser_outf(invalid_node_id, "\r\nError: %s", reason);
  proceed (menu);
break; } default: __pi_badstate (); } }
#undef initialize_node
#undef menu
#undef get_choice
#undef get_new_group_id
#undef new_group_id
#undef get_new_node_id
#undef new_node_id
#undef invalid_node_id
#undef clear_neighbour_array
#undef find_proto_start
#undef wait_discovery
#undef display_neighbour_nodes
#undef create_proto_start
#undef get_id_for_create
#undef ask_for_record_to_create
#undef get_record_to_create
#undef init_create_record_message
#undef start_delete_proto
#undef get_id_for_delete
#undef ask_for_record_index
#undef get_index_for_delete
#undef init_delete_record_message
#undef start_retrieve_proto
#undef get_id_for_retrieve
#undef ask_for_record_retrieve_index
#undef get_index_for_retrieve
#undef retrieve_proto
#undef display_db
#undef loop_through_data
#undef del_local
#undef wait
#undef timeout
#undef error
# 937 "app.cc"

