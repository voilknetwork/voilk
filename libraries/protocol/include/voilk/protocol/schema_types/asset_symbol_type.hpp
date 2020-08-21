
#pragma once

#include <voilk/schema/abstract_schema.hpp>
#include <voilk/schema/schema_impl.hpp>

#include <voilk/protocol/asset_symbol.hpp>

namespace voilk { namespace schema { namespace detail {

//////////////////////////////////////////////
// asset_symbol_type                        //
//////////////////////////////////////////////

struct schema_asset_symbol_type_impl
   : public abstract_schema
{
   VOILK_SCHEMA_CLASS_BODY( schema_asset_symbol_type_impl )
};

}

template<>
struct schema_reflect< voilk::protocol::asset_symbol_type >
{
   typedef detail::schema_asset_symbol_type_impl           schema_impl_type;
};

} }
