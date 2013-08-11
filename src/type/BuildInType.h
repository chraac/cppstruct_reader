#pragma once
#include "TypeBase.h"

typedef enum _SIGN_TYPE
{
    type_sign = 0,
    type_unsign,
}SIGN_TYPE;

typedef enum _LONG_TYPE
{
    type_normal = 0,
    type_short,
    type_long,
}LONG_TYPE;

class TBuildInType : public TTypeBase
{
public:
    TBuildInType(const stlstring &szTypeName, const U32 nLen, 
        const SIGN_TYPE emSign = type_sign, 
        const LONG_TYPE emLong = type_normal)
        :TTypeBase(szTypeName, nLen)
        ,m_emSign(emSign)
        ,m_emLong(emLong)
    {
    }
    virtual ~TBuildInType(void)
    {
    }

    virtual SIGN_TYPE GetSign()const{return m_emSign;}
    virtual LONG_TYPE GetLong()const{return m_emLong;}


protected:
    SIGN_TYPE m_emSign;
    LONG_TYPE m_emLong;
};

class TChar : public TBuildInType
{
public:
    TChar(const SIGN_TYPE emSign = type_sign, 
        const LONG_TYPE emLong = type_normal);

    virtual ~TChar(){}

    virtual stlstring GetStringValue(const U8 *pData)const override;
    virtual U32 GetRawValue(const stlstring &szIn, U8 *pBuffer)const override;
};

class TInteger : public TBuildInType
{
public:
    TInteger(const SIGN_TYPE emSign = type_sign, 
        const LONG_TYPE emLong = type_normal);

    virtual ~TInteger(){}

    virtual stlstring GetStringValue(const U8 *pData)const override;
    virtual U32 GetRawValue(const stlstring &szIn, U8 *pBuffer)const override;
};

class TFloat : public TBuildInType
{
public:
    TFloat(const LONG_TYPE emLong = type_normal);
    virtual ~TFloat(){}

    virtual stlstring GetStringValue(const U8 *pData)const override;
    virtual U32 GetRawValue(const stlstring &szIn, U8 *pBuffer)const override;
};


class TDouble : public TBuildInType
{
public:
    TDouble(const LONG_TYPE emLong = type_normal);
    virtual ~TDouble(){}

    virtual stlstring GetStringValue(const U8 *pData)const override;
    virtual U32 GetRawValue(const stlstring &szIn, U8 *pBuffer)const override;
};
