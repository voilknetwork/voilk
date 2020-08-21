#pragma once
#include <voilk/protocol/base.hpp>
#include <voilk/protocol/block_header.hpp>
#include <voilk/protocol/asset.hpp>
#include <voilk/protocol/validation.hpp>
#include <voilk/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace voilk { namespace protocol {

   struct required_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // voilk::protocol

FC_REFLECT( voilk::protocol::required_action, (account) )
