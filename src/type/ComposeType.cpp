#include "ComposeType.h"
#include <algorithm>
using namespace std;
using namespace std::tr1;


TComposeType::TComposeType(const stlstring &szTypeName)
    :TTypeBase(szTypeName, 1)
    ,m_cPublicVars(privilege_public)
    ,m_cProtectedVars(privilege_protected)
    ,m_cPrivateVars(privilege_private)
{
//     for_each(m_arrMemberVars.begin(), m_arrMemberVars.end(), 
//         [&s_nLength](BuildInTypeVar &member){s_nLength += member.GetLength();});
}


TComposeType::~TComposeType(void)
{
}

MemberVariables &TComposeType::GetMemberVars(ACCESS_PRIVILEGE emPrivilege)
{
    switch (emPrivilege)
    {
    case privilege_protected:
        return m_cProtectedVars;
        break;

    case privilege_private:
        return m_cPrivateVars;
        break;

    case privilege_public:
    default:
        break;
    }
    return m_cPublicVars;
}

MemberFunctions &TComposeType::GetMemberFuncs(ACCESS_PRIVILEGE emPrivilege)
{
    switch (emPrivilege)
    {
    case privilege_protected:
        return m_cProtectedFuncs;
        break;

    case privilege_private:
        return m_cPrivateFuncs;
        break;

    case privilege_public:
    default:
        break;
    }
    return m_cPublicFuncs;
}
