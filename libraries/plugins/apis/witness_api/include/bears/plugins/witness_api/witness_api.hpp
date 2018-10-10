#pragma once
#include <bears/plugins/json_rpc/utility.hpp>
#include <bears/plugins/witness/witness_objects.hpp>

#include <bears/protocol/types.hpp>

#include <fc/optional.hpp>
#include <fc/variant.hpp>
#include <fc/vector.hpp>

namespace bears { namespace plugins { namespace witness {

namespace detail
{
   class witness_api_impl;
}

struct get_account_bandwidth_args
{
   protocol::account_name_type   account;
   bandwidth_type                type;
};

typedef account_bandwidth_object api_account_bandwidth_object;

struct get_account_bandwidth_return
{
   optional< api_account_bandwidth_object > bandwidth;
};

typedef json_rpc::void_type get_reserve_ratio_args;
typedef reserve_ratio_object get_reserve_ratio_return;

class witness_api
{
   public:
      witness_api();
      ~witness_api();

      DECLARE_API(
         (get_account_bandwidth)
         (get_reserve_ratio)
      )

   private:
      std::unique_ptr< detail::witness_api_impl > my;
};

} } } // bears::plugins::witness

FC_REFLECT( bears::plugins::witness::get_account_bandwidth_args,
            (account)(type) )

FC_REFLECT( bears::plugins::witness::get_account_bandwidth_return,
            (bandwidth) )
