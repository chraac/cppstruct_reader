#pragma once
#include "MemberVariable.h"
#include "BuildInType.h"


class MemberFunctions
{
public:
    MemberFunctions(void);
    virtual ~MemberFunctions(void);

    virtual MemberVariables &GetParam(){return m_arrParameter;}
    virtual void SetParam(const MemberVariables &param){m_arrParameter = param;}

protected:
    MemberVariables m_arrParameter;
};
