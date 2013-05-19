#pragma once
#include "baseDefine.h"


class TTypeBase
{
public:
    TTypeBase(const stlstring &szTypeName, const U32 nLen)
    {
        m_szTypeName = szTypeName;
        m_nLength    = nLen;
    }
    virtual ~TTypeBase(void){}

    virtual stlstring GetStringValue(const U8 * /*pData*/)const
    {return stlstring();}
    virtual U32 GetRawValue(const stlstring & /*szIn*/, const U8 * /*pBuffer*/)const
    {return 0;}

    virtual stlstring GetTypeName()const{return m_szTypeName;}
    virtual U32 GetLength()const{return m_nLength;}

protected:
    stlstring m_szTypeName;
    U32 m_nLength;
};

