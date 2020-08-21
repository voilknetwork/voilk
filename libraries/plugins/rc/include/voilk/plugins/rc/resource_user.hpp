#pragma once

#include <voilk/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace voilk { namespace protocol {
struct signed_transaction;
} } // voilk::protocol

namespace voilk { namespace plugins { namespace rc {

using voilk::protocol::account_name_type;
using voilk::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // voilk::plugins::rc
