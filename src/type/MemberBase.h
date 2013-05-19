#pragma once
#include "baseDefine.h"
#include <vector>

typedef enum _ACCESS_PRIVILEGE
{
    privilege_public = 0,
    privilege_protected,
    privilege_private,
}ACCESS_PRIVILEGE;

template<class _Ty>
class MemberBase
{
public:
    typedef _Ty _TargeType;
    typedef vector<_TargeType> MEMBER_ARRAY;

public:
    MemberBase(ACCESS_PRIVILEGE emPrivilege):m_emPrivilege(emPrivilege){}
    virtual ~MemberBase(void){}

    virtual void AddMember(const _TargeType &member){m_arrayMembers.push_back(member);}
    virtual ACCESS_PRIVILEGE GetPrivilege()const{return m_emPrivilege;}
    virtual const MEMBER_ARRAY &GetMembers()const{return m_arrayMembers;}

protected:
    ACCESS_PRIVILEGE m_emPrivilege;
    MEMBER_ARRAY     m_arrayMembers;
};

