#pragma once
#include "baseDefine.h"
#include "BuildInType.h"
#include "ComposeType.h"

typedef enum _VAR_TYPE
{
    varType_Normal = 0,
    varType_Pointer,
    varType_Reference,
}VAR_TYPE;

class Variable
{
public:
    Variable(TBuildInType &buildInType, const VAR_TYPE emType, const stlstring &szName)
    {
        m_pBuildInType = &buildInType;
        m_pComposeType = NULL;
        m_emType       = emType;
        m_szVarName    = szName;
    }

    Variable(TComposeType &composeType, const VAR_TYPE emType, const stlstring &szName)
    {
        m_pBuildInType = NULL;
        m_pComposeType = &composeType;
        m_emType       = emType;
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

    VAR_TYPE  m_emType;
    stlstring m_szVarName;
};

