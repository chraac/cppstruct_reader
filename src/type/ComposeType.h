#pragma once
#include "TypeBase.h"
#include "BuildInType.h"
#include "MemberVariable.h"
#include "MemberFunction.h"
#include "scope_define.h"

#include <vector>
#include <memory>

class scope_define;

class TComposeType : public TTypeBase
{
public:
    TComposeType(const stlstring &szTypeName, scope_define *pDef);
    virtual ~TComposeType(void);

    virtual MemberVariables &GetMemberVars(
        ACCESS_PRIVILEGE emPrivilege);
    virtual MemberFunctions &GetMemberFuncs(
        ACCESS_PRIVILEGE emPrivilege);

protected:
    std::unique_ptr<scope_define> m_pScope;
};

