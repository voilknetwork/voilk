#pragma once
#include <bears/plugins/json_rpc/utility.hpp>

#include <bears/protocol/types.hpp>

#include <fc/optional.hpp>
#include <fc/variant.hpp>
#include <fc/vector.hpp>

namespace bears { namespace plugins { namespace account_by_key {

namespace detail
{
   class account_by_key_api_impl;
}

struct get_key_references_args
{
   std::vector< bears::protocol::public_key_type > keys;
};

struct get_key_references_return
{
   std::vector< std::vector< bears::protocol::account_name_type > > accounts;
};

class account_by_key_api
{
   public:
      account_by_key_api();
      ~account_by_key_api();

      DECLARE_API( (get_key_references) )

   private:
      std::unique_ptr< detail::account_by_key_api_impl > my;
};

} } } // bears::plugins::account_by_key

FC_REFLECT( bears::plugins::account_by_key::get_key_references_args,
   (keys) )

FC_REFLECT( bears::plugins::account_by_key::get_key_references_return,
   (accounts) )
