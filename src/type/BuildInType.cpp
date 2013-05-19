#include "BuildInType.h"

namespace{

    typedef struct _TYPE_INFO
    {
        const TCHAR *lpszTypeName;
        U32 arrLength[3];
    }TYPE_INFO;

    static const TYPE_INFO s_arrayInfo[] = 
    {
        {_T("int"), {4, 2, 4}},
        {_T("float"), {4, 4, 4}},
        {_T("double"), {8, 8, 8}},
    };
}


TInteger::TInteger(const SIGN_TYPE emSign, const LONG_TYPE emLong)
    :TBuildInType(s_arrayInfo[0].lpszTypeName, 
        s_arrayInfo[0].arrLength[emLong], emSign, emLong)
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

U32 TInteger::GetRawValue(const stlstring &szIn, const U8 *pBuffer)const
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
    :TBuildInType(s_arrayInfo[1].lpszTypeName, 
        s_arrayInfo[1].arrLength[emLong], type_sign, emLong)
{
}

stlstring TFloat::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    ssTmp << *(F32 *)pData;
    return ssTmp.str();
}

U32 TFloat::GetRawValue(const stlstring &szIn, const U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    ssTmp >> *(F32 *)pBuffer;
    return GetLength();
}




TDouble::TDouble(const LONG_TYPE emLong = type_normal)
    :TBuildInType(s_arrayInfo[2].lpszTypeName, 
        s_arrayInfo[2].arrLength[emLong], type_sign, emLong)
{
}

stlstring TDouble::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FALSE(pData, stlstring());

    stlstrstream ssTmp;
    ssTmp << *(F64 *)pData;
    return ssTmp.str();
}

U32 TDouble::GetRawValue(const stlstring &szIn, const U8 *pBuffer)const
{
    RET_VAR_IF_FALSE(pBuffer, GetLength());

    stlstrstream ssTmp;
    ssTmp << szIn;
    ssTmp >> *(F64 *)pBuffer;
    return GetLength();
}
