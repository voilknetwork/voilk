#pragma once

#include <bears/protocol/block.hpp>

namespace bears { namespace chain {

struct transaction_notification
{
   transaction_notification( const bears::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   bears::protocol::transaction_id_type          transaction_id;
   const bears::protocol::signed_transaction&    transaction;
};

} }
