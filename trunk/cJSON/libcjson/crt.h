/*


ע�⣺
1.��������:cJSON.c��print_number������length = sprintf((char*)number_buffer, "%1.15g", d);
  �õ���ֻ��һ��g�����Ǹ�������
  ��ʹ����KeSaveExtendedProcessorState��KeRestoreExtendedProcessorState��Ҳ�����ɡ�
2.cjson���˵�����ֶ��Ǹ������ڲ�����
3.��������������ʹ�ø�����������������
*/


#pragma once


#include "pch.h"


//////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct _JSON_POOL {
    SIZE_T NumberOfBytes;
    BYTE Pool[0];
} JSON_POOL;
typedef JSON_POOL * PJSON_POOL;


//////////////////////////////////////////////////////////////////////////////////////////////////


#if defined _NO_CRT_STDIO_INLINE
#undef _CRT_STDIO_INLINE
#define _CRT_STDIO_INLINE
#elif !defined _CRT_STDIO_INLINE
#define _CRT_STDIO_INLINE __inline
#endif


#define _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS (*__local_stdio_printf_options())
#define _CRT_INTERNAL_LOCAL_SCANF_OPTIONS  (*__local_stdio_scanf_options ())


#if defined _M_IX86 && !defined _M_HYBRID_X86_ARM64
#define __crt_va_start_a(ap, v) ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
#elif defined _M_X64
#define __crt_va_start_a(ap, x) ((void)(__va_start(&ap, x)))
#endif

#define __crt_va_start(ap, x) ((void)(__crt_va_start_a(ap, x)))

#define __crt_va_end(ap)        ((void)(ap = (va_list)0))

#define _CRT_GUARDOVERFLOW
#define _ACRTIMP
#define _CRT_HYBRIDPATCHABLE

#define __crt_va_end(ap)        ((void)(ap = (va_list)0))

#define _CRTALLOCATOR __declspec(allocator)


//////////////////////////////////////////////////////////////////////////////////////////////////
