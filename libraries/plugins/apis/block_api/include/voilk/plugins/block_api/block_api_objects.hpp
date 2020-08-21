#pragma once
#include <voilk/chain/account_object.hpp>
#include <voilk/chain/block_summary_object.hpp>
#include <voilk/chain/comment_object.hpp>
#include <voilk/chain/global_property_object.hpp>
#include <voilk/chain/history_object.hpp>
#include <voilk/chain/voilk_objects.hpp>
#include <voilk/chain/transaction_object.hpp>
#include <voilk/chain/witness_objects.hpp>
#include <voilk/chain/database.hpp>

namespace voilk { namespace plugins { namespace block_api {

using namespace voilk::chain;

struct api_signed_block_object : public signed_block
{
   api_signed_block_object( const signed_block& block ) : signed_block( block )
   {
      block_id = id();
      signing_key = signee();
      transaction_ids.reserve( transactions.size() );
      for( const signed_transaction& tx : transactions )
         transaction_ids.push_back( tx.id() );
   }
   api_signed_block_object() {}

   block_id_type                 block_id;
   public_key_type               signing_key;
   vector< transaction_id_type > transaction_ids;
};

} } } // voilk::plugins::database_api

FC_REFLECT_DERIVED( voilk::plugins::block_api::api_signed_block_object, (voilk::protocol::signed_block),
                     (block_id)
                     (signing_key)
                     (transaction_ids)
                  )
