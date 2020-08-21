
#pragma once

#include <voilk/schema/abstract_schema.hpp>
#include <voilk/schema/schema_impl.hpp>

#include <voilk/protocol/types.hpp>

namespace voilk { namespace schema { namespace detail {

//////////////////////////////////////////////
// account_name_type                        //
//////////////////////////////////////////////

struct schema_account_name_type_impl
   : public abstract_schema
{
   VOILK_SCHEMA_CLASS_BODY( schema_account_name_type_impl )
};

}

template<>
struct schema_reflect< voilk::protocol::account_name_type >
{
   typedef detail::schema_account_name_type_impl           schema_impl_type;
};

} }

namespace fc {

template<>
struct get_typename< voilk::protocol::account_name_type >
{
   static const char* name()
   {
      return "voilk::protocol::account_name_type";
   }
};

}
