#pragma once

#include <map>
#include "TypeBase.h"



class sym_data_t
{
public:
    typedef enum _SYM_TYPE
    {
        symType_Var = 0,
        symType_Fun,
        symType_ConstVar,
        symType_Type,
    }SYM_TYPE;

public:
    sym_data_t(const stlstring &sym_name, const SYM_TYPE sym_type, 
        const TTypeBase *pType)
        :m_szSymName(sym_name)
        ,m_emType(sym_type)
        ,m_pType(pType)
    {
    }

    virtual ~sym_data_t(){}

   sym_data_t &operator=(const sym_data_t &right)
   {
       m_szSymName = right.m_szSymName;
       m_emType    = right.m_emType;
       m_pType     = right.m_pType;
       return *this;
   }

    stlstring  m_szSymName;
    SYM_TYPE   m_emType;
    const TTypeBase *m_pType;
};

class sym_table_t
{
public:
    sym_table_t(void);
    virtual ~sym_table_t(void);

    bool add_sym(const stlstring &sym_name, const sym_data_t &data)
    {
        RET_VAR_IF_FALSE(m_map.find(sym_name) == m_map.end(), false);
        m_map[sym_name] = data;
        return true;
    }

    void remove_sym(const stlstring &sym_name){m_map.erase(m_map.find(sym_name));}
    
    sym_data_t &get_sym(const stlstring &sym_name){return m_map[sym_name];}
    sym_data_t &operator[](const stlstring &sym_name){return get_sym(sym_name);}


protected:
    typedef std::map<stlstring, sym_data_t> sym_map_t;

protected:
    sym_map_t m_map;
};
