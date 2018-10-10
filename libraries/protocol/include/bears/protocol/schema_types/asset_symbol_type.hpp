
#pragma once

#include <bears/schema/abstract_schema.hpp>
#include <bears/schema/schema_impl.hpp>

#include <bears/protocol/asset_symbol.hpp>

namespace bears { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   BEARS_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< bears::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
