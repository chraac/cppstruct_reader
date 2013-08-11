#include "BuildInType.h"

namespace{

    typedef struct _TYPE_INFO
    {
        const TCHAR *lpszTypeName;
        U32 arrLength[3];
    }TYPE_INFO;

    static const TYPE_INFO s_arrayInfo[] = 
    {
        {_T("char"), {1, 1, 1}},
        {_T("int"), {4, 2, 4}},
        {_T("float"), {4, 4, 4}},
        {_T("double"), {8, 8, 8}},
    };

    enum 
    {
        typeInfo_char = 0,
        typeInfo_int,
        typeInfo_float,
        typeInfo_double,
    };
}


TChar::TChar(const SIGN_TYPE emSign, const LONG_TYPE emLong)
    :TBuildInType(s_arrayInfo[typeInfo_char].lpszTypeName, 
    s_arrayInfo[typeInfo_char].arrLength[emLong], emSign, emLong)
{
}

stlstring TChar::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    switch (m_emSign)
    {
    case type_sign:
        ssTmp << *(I8 *)pData;
        break;

    case type_unsign:
    default:
        ssTmp << *pData;
        break;
    }
    return ssTmp.str();
}

U32 TChar::GetRawValue(const stlstring &szIn, U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    switch (m_emSign)
    {
    case type_sign:
        {
            I32 nTmp(0);
            ssTmp >> nTmp;
            *(I8 *)pBuffer = (I8)nTmp;
        }
        break;

    case type_unsign:
    default:
        {
            U32 nTmp(0);
            ssTmp >> nTmp;
            *pBuffer = (U8)nTmp;
        }
        break;
    }
    return GetLength();
}



TInteger::TInteger(const SIGN_TYPE emSign, const LONG_TYPE emLong)
    :TBuildInType(s_arrayInfo[typeInfo_int].lpszTypeName, 
        s_arrayInfo[typeInfo_int].arrLength[emLong], emSign, emLong)
{
}

stlstring TInteger::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    switch (m_emLong)
    {
    case type_short:
        if (m_emSign == type_sign)
        {
            ssTmp << *(I16 *)pData;
        } 
        else
        {
            ssTmp << *(U16 *)pData;
        }
        break;

    case type_long:
    case type_normal:
    default:
        if (m_emSign == type_sign)
        {
            ssTmp << *(I32 *)pData;
        } 
        else
        {
            ssTmp << *(U32 *)pData;
        }
        break;
    }
    return ssTmp.str();
}

U32 TInteger::GetRawValue(const stlstring &szIn, U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    switch (m_emLong)
    {
    case type_short:
        if (m_emSign == type_sign)
        {
            ssTmp >> *(I16 *)pBuffer;
        } 
        else
        {
            ssTmp >> *(U16 *)pBuffer;
        }
        break;

    case type_long:
    case type_normal:
    default:
        if (m_emSign == type_sign)
        {
            ssTmp >> *(I32 *)pBuffer;
        } 
        else
        {
            ssTmp >> *(U32 *)pBuffer;
        }
        break;
    }
    return GetLength();
}




TFloat::TFloat(const LONG_TYPE emLong = type_normal)
    :TBuildInType(s_arrayInfo[typeInfo_float].lpszTypeName, 
        s_arrayInfo[typeInfo_float].arrLength[emLong], type_sign, emLong)
{
}

stlstring TFloat::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    ssTmp << *(F32 *)pData;
    return ssTmp.str();
}

U32 TFloat::GetRawValue(const stlstring &szIn, U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    ssTmp >> *(F32 *)pBuffer;
    return GetLength();
}




TDouble::TDouble(const LONG_TYPE emLong = type_normal)
    :TBuildInType(s_arrayInfo[typeInfo_double].lpszTypeName, 
        s_arrayInfo[typeInfo_double].arrLength[emLong], type_sign, emLong)
{
}

stlstring TDouble::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    ssTmp << *(F64 *)pData;
    return ssTmp.str();
}

U32 TDouble::GetRawValue(const stlstring &szIn, U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    ssTmp >> *(F64 *)pBuffer;
    return GetLength();
}
