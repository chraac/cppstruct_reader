#include "ComposeType.h"
#include "scope_define.h"

#include <algorithm>
using namespace std;
using namespace std::tr1;


TComposeType::TComposeType(const stlstring &szTypeName, scope_define *pDef)
    :TTypeBase(szTypeName, 1)
    ,m_pScope(pDef)
{
}


TComposeType::~TComposeType(void)
{
}

MemberVariables &TComposeType::GetMemberVars(ACCESS_PRIVILEGE emPrivilege)
{
    return m_pScope->get_member_var(emPrivilege);
}

MemberFunctions &TComposeType::GetMemberFuncs(ACCESS_PRIVILEGE emPrivilege)
{
    return m_pScope->get_member_func(emPrivilege);
}
