#include "MemberVariable.h"
#include <algorithm>
using namespace std;


U32 MemberVariables::GetLength()const
{
    U32 nLen(0);
    for_each(m_arrayMembers.begin(), m_arrayMembers.end(), 
        [&nLen](Variable &var){nLen += var.GetLength();});
    return nLen;
}
