#pragma once
#include "TypeBase.h"
#include "BuildInType.h"
#include "MemberVariable.h"
#include "MemberFunction.h"

#include <vector>


class TComposeType : public TTypeBase
{
public:
    TComposeType(const stlstring &szTypeName);
    virtual ~TComposeType(void);

    virtual MemberVariables &GetMemberVars(
        ACCESS_PRIVILEGE emPrivilege);
    virtual MemberFunctions &GetMemberFuncs(
        ACCESS_PRIVILEGE emPrivilege);

protected:
    MemberVariables m_cPublicVars;
    MemberVariables m_cProtectedVars;
    MemberVariables m_cPrivateVars;
    
    MemberFunctions m_cPublicFuncs;
    MemberFunctions m_cProtectedFuncs;
    MemberFunctions m_cPrivateFuncs;
};

