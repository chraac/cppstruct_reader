#pragma once
#include "MemberBase.h"
#include "BuildInType.h"
#include "Variable.h"


class MemberVariables : public MemberBase<Variable>
{
public:
    MemberVariables(ACCESS_PRIVILEGE emPrivilege)
        :MemberBase<Variable>(emPrivilege){}
    virtual ~MemberVariables(void){}

    virtual U32 GetLength()const;
};
