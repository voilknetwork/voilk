#pragma once
#include <bears/protocol/base.hpp>
#include <bears/protocol/block_header.hpp>
#include <bears/protocol/asset.hpp>
#include <bears/protocol/validation.hpp>
#include <bears/protocol/legacy_asset.hpp>

#include <fc/crypto/equihash.hpp>

namespace bears { namespace protocol {

   struct optional_action : public base_operation
   {
      account_name_type account;

      void validate()const;
      void get_required_active_authorities( flat_set<account_name_type>& a )const{ a.insert(account); }
   };

} } // bears::protocol

FC_REFLECT( bears::protocol::optional_action, (account) )
