
#ifndef _BASEDEFINE_H
#define _BASEDEFINE_H

#include <string>
#include <sstream>
#include <assert.h>
#include <tchar.h>
#include <cstdint>


typedef int8_t                I8;
typedef uint8_t               U8;
typedef int16_t               I16;
typedef uint16_t              U16;
typedef int32_t               I32;
typedef uint32_t              U32;
typedef int64_t               I64;
typedef uint64_t              U64;


typedef float                 F32;
typedef double                F64;


#ifdef _UNICODE
    typedef std::wstring stlstring;
    typedef std::wstringstream stlstrstream;
#else
    typedef std::string stlstring;
    typedef std::stringstream stlstrstream;
#endif

#define RET_IF_FAIL(f)           if (!(f)) {assert(f);return;}
#define RET_VAR_IF_FAIL(f, var)  if (!(f)) {assert(f);return var;}

#define RET_IF_FALSE(f)          if (!(f)) {return;}
#define RET_VAR_IF_FALSE(f, var) if (!(f)) {return var;}


#endif
