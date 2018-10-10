
#pragma once

#include <bears/schema/abstract_schema.hpp>
#include <bears/schema/schema_impl.hpp>

#include <bears/protocol/types.hpp>

namespace bears { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   BEARS_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< bears::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< bears::protocol::account_name_type >
{
   static const char* name()
   {
      return "bears::protocol::account_name_type";
   }
};

}
