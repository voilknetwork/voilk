#pragma once

#include <bears/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace bears { namespace protocol {
struct signed_transaction;
} } // bears::protocol

namespace bears { namespace plugins { namespace rc {

using bears::protocol::account_name_type;
using bears::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // bears::plugins::rc
