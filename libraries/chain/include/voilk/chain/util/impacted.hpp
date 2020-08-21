#pragma once

#include <fc/container/flat.hpp>
#include <voilk/protocol/operations.hpp>
#include <voilk/protocol/transaction.hpp>

#include <fc/string.hpp>

namespace voilk { namespace app {

using namespace fc;

void operation_get_impacted_accounts(
   const voilk::protocol::operation& op,
   fc::flat_set<protocol::account_name_type>& result );

void transaction_get_impacted_accounts(
   const voilk::protocol::transaction& tx,
   fc::flat_set<protocol::account_name_type>& result
   );

} } // voilk::app
