#pragma once
#include "BuildInType.h"
#include "ComposeType.h"

#include <map>



class ProgramBlock
{
public:
    ProgramBlock(void);
    virtual ~ProgramBlock(void);

    virtual void AddBuildInType(TBuildInType *pType)
    {RET_IF_FAIL(pType);m_typeBuildIn[pType->GetTypeName()] = pType;}

    virtual void AddComposeType(TComposeType *pType)
    {RET_IF_FAIL(pType);m_typeCompose[pType->GetTypeName()] = pType;}

    virtual TBuildInType *GetBuildInType(const stlstring &szType)
    {return m_typeBuildIn[szType];}

    virtual TComposeType *GetComposeType(const stlstring &szType)
    {return m_typeCompose[szType];}


public:
    /* @brief  type declare */
    std::map<stlstring, TBuildInType *> m_typeBuildIn;
    std::map<stlstring, TComposeType *> m_typeCompose;

    /* @brief  global var declare */
    std::vector<Variable *> m_globalVariables;

    /* @brief  global function declare */
    ;
};

