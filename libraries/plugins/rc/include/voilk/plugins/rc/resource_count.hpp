#pragma once

#include <voilk/protocol/types.hpp>

#include <fc/int_array.hpp>
#include <fc/reflect/reflect.hpp>
#include <vector>

#define VOILK_NUM_RESOURCE_TYPES     5

namespace voilk { namespace protocol {
struct signed_transaction;
} } // voilk::protocol

namespace voilk { namespace plugins { namespace rc {

enum rc_resource_types
{
   resource_history_bytes,
   resource_new_accounts,
   resource_market_bytes,
   resource_state_bytes,
   resource_execution_time
};

typedef fc::int_array< int64_t, VOILK_NUM_RESOURCE_TYPES > resource_count_type;

struct count_resources_result
{
   resource_count_type                            resource_count;
};

void count_resources(
   const voilk::protocol::signed_transaction& tx,
   count_resources_result& result );

} } } // voilk::plugins::rc

FC_REFLECT_ENUM( voilk::plugins::rc::rc_resource_types,
    (resource_history_bytes)
    (resource_new_accounts)
    (resource_market_bytes)
    (resource_state_bytes)
    (resource_execution_time)
   )

FC_REFLECT( voilk::plugins::rc::count_resources_result,
   (resource_count)
)

FC_REFLECT_TYPENAME( voilk::plugins::rc::resource_count_type )
