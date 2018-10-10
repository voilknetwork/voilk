#pragma once

#include <fc/container/flat.hpp>
#include <bears/protocol/operations.hpp>
#include <bears/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace bears { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const bears::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const bears::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // bears::app
