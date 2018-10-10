#pragma once

#include <bears/protocol/types.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define BEARS_NUM_RESOURCE_TYPES     5

namespace bears { namespace protocol {
struct signed_transaction;
} } // bears::protocol

namespace bears { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, BEARS_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const bears::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // bears::plugins::rc

FC_REFLECT_ENUM( bears::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( bears::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( bears::plugins::rc::resource_count_type )
