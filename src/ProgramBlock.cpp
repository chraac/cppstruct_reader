#include "ProgramBlock.h"
#include <algorithm>
using namespace std;



ProgramBlock::ProgramBlock(void)
{
    AddBuildInType(new TChar(type_sign, type_normal));
    AddBuildInType(new TChar(type_unsign, type_normal));

    AddBuildInType(new TInteger(type_sign, type_normal));
    AddBuildInType(new TInteger(type_sign, type_short));
    AddBuildInType(new TInteger(type_sign, type_long));
    AddBuildInType(new TInteger(type_unsign, type_normal));
    AddBuildInType(new TInteger(type_unsign, type_short));
    AddBuildInType(new TInteger(type_unsign, type_long));

    AddBuildInType(new TFloat());

    AddBuildInType(new TDouble(type_normal));
    AddBuildInType(new TDouble(type_long));
}


ProgramBlock::~ProgramBlock(void)
{
    for_each(m_typeBuildIn.begin(), m_typeBuildIn.end(), 
        [](TBuildInType *pType){RET_IF_FALSE(pType);delete pType;});

    for_each(m_typeCompose.begin(), m_typeCompose.end(), 
        [](TComposeType *pType){RET_IF_FALSE(pType);delete pType;});

    for_each(m_globalVariables.begin(), m_globalVariables.end(), 
        [](Variable *pVar){RET_IF_FALSE(pVar);delete pVar;});
}
