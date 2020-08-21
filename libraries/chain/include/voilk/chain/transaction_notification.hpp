#pragma once

#include <voilk/protocol/block.hpp>

namespace voilk { namespace chain {

struct transaction_notification
{
   transaction_notification( const voilk::protocol::signed_transaction& tx ) : transaction(tx)
   {
      transaction_id = tx.id();
   }

   voilk::protocol::transaction_id_type          transaction_id;
   const voilk::protocol::signed_transaction&    transaction;
};

} }
