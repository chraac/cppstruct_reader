
#ifndef _BASEDEFINE_H
#define _BASEDEFINE_H

#include <string>
#include <sstream>
#include <assert.h>
#include <tchar.h>


typedef char                  I8;
typedef unsigned char         U8;
typedef short                 I16;
typedef unsigned short        U16;
typedef int                   I32;
typedef unsigned int          U32;
typedef __int64               I64;
typedef unsigned __int64      U64;


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
