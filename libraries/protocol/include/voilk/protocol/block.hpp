#pragma once
#include <voilk/protocol/block_header.hpp>
#include <voilk/protocol/transaction.hpp>

namespace voilk { namespace protocol {

   struct signed_block : public signed_block_header
   {
      checksum_type calculate_merkle_root()const;
      vector<signed_transaction> transactions;
   };

} } // voilk::protocol

FC_REFLECT_DERIVED( voilk::protocol::signed_block, (voilk::protocol::signed_block_header), (transactions) )
