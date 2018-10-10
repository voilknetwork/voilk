#pragma once
#include <bears/protocol/block_header.hpp>
#include <bears/protocol/transaction.hpp>

namespace bears { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // bears::protocol

FC_REFLECT_DERIVED( bears::protocol::signed_block, (bears::protocol::signed_block_header), (transactions) )
