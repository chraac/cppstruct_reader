
#include "Variable.h"


stlstring Variable::GetStringValue(const U8 *pData)const
{
    RET_VAR_IF_FAIL(m_pBuildInType || m_pComposeType, stlstring());

    if (m_pBuildInType)
    {
        return m_pBuildInType->GetStringValue(pData);
    } 
    else
    {
        return m_pComposeType->GetStringValue(pData);
    }
}

stlstring Variable::GetTypeName()const
{
    RET_VAR_IF_FAIL(m_pBuildInType || m_pComposeType, stlstring());

    if (m_pBuildInType)
    {
        return m_pBuildInType->GetTypeName();
    } 
    else
    {
        return m_pComposeType->GetTypeName();
    }
}

U32 Variable::GetLength()const
{
    RET_VAR_IF_FAIL(m_pBuildInType || m_pComposeType, 0);

    if (m_pBuildInType)
    {
        return m_pBuildInType->GetLength();
    } 
    else
    {
        return m_pComposeType->GetLength();
    }
}
