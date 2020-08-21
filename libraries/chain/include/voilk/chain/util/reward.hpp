#pragma once

#include <voilk/chain/util/asset.hpp>
#include <voilk/chain/voilk_objects.hpp>

#include <voilk/protocol/asset.hpp>
#include <voilk/protocol/config.hpp>
#include <voilk/protocol/types.hpp>
#include <voilk/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace voilk { namespace chain { namespace util {

using voilk::protocol::asset;
using voilk::protocol::price;
using voilk::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_vsd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_voilk;
   price      current_voilk_price;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = VOILK_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return VOILK_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& content_constant = VOILK_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t voilk_payout )
{
   return to_vsd( p, asset( voilk_payout, VOILK_SYMBOL ) ) < VOILK_MIN_PAYOUT_VSD;
}

} } } // voilk::chain::util

FC_REFLECT( voilk::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_vsd)
   (total_reward_shares2)
   (total_reward_fund_voilk)
   (current_voilk_price)
   (reward_curve)
   (content_constant)
   )
