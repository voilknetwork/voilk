#pragma once

#include <bears/chain/util/asset.hpp>
#include <bears/chain/bears_objects.hpp>

#include <bears/protocol/asset.hpp>
#include <bears/protocol/config.hpp>
#include <bears/protocol/types.hpp>
#include <bears/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace bears { namespace chain { namespace util {

using bears::protocol::asset;
using bears::protocol::price;
using bears::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_bsd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_bears;
   price      current_bears_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = BEARS_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return BEARS_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = BEARS_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t bears_payout )
{
   return to_bsd( p, asset( bears_payout, BEARS_SYMBOL ) ) < BEARS_MIN_PAYOUT_BSD;
}

} } } // bears::chain::util

FC_REFLECT( bears::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_bsd)
   (total_reward_shares2)
   (total_reward_fund_bears)
   (current_bears_price)
   (reward_curve)
   (content_constant)
   )
