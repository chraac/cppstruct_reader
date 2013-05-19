#pragma once
#include "baseDefine.h"
#include "BuildInType.h"
#include "ComposeType.h"


class Variable
{
public:
    Variable(TBuildInType &buildInType, const stlstring &szName)
    {
        m_pBuildInType = &buildInType;
        m_pComposeType = NULL;
        m_szVarName    = szName;
    }

    Variable(TComposeType &composeType, const stlstring &szName)
    {
        m_pBuildInType = NULL;
        m_pComposeType = &composeType;
        m_szVarName    = szName;
    }

    virtual ~Variable(void){}

    TBuildInType *GetBuildInType()const{return m_pBuildInType;}
    TComposeType *GetComposeType()const{return m_pComposeType;}
    stlstring GetVarName()const{return m_szVarName;}

    virtual stlstring GetStringValue(const U8 *pData)const;
    virtual stlstring GetTypeName()const;
    virtual U32 GetLength()const;

protected:
    TBuildInType *m_pBuildInType;
    TComposeType *m_pComposeType;

    stlstring m_szVarName;
};

