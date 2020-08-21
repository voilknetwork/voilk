#pragma once

#include <voilk/chain/voilk_object_types.hpp>
#include <voilk/protocol/smt_operations.hpp>

#ifdef VOILK_ENABLE_SMT

namespace voilk { namespace chain {

/**
 * Class responsible for holding regular (i.e. non-reward) balance of SMT for given account.
 * It has not been unified with reward balance object counterpart, due to different number
 * of fields needed to hold balances (2 for regular, 3 for reward).
 */
class account_regular_balance_object : public object< account_regular_balance_object_type, account_regular_balance_object >
{
   account_regular_balance_object() = delete;

public:   
   template <typename Constructor, typename Allocator>
   account_regular_balance_object(Constructor&& c, allocator< Allocator > a)
   {
      c( *this );
   }

   // id_type is actually oid<account_regular_balance_object>
   id_type             id;
   /// Name of the account, the balance is held for.
   account_name_type   owner;
   asset               liquid;   /// 'balance' for VOILK
   asset               coining;  /// 'coining_shares' for COINS

   /** Set of simple methods that allow unification of
    *  regular and rewards balance manipulation code.
    */
   ///@{
   asset_symbol_type get_liquid_symbol() const
   {
      return liquid.symbol;
   }
   void clear_balance( asset_symbol_type liquid_symbol )
   {
      owner = "";
      liquid = asset( 0, liquid_symbol);
      coining = asset( 0, liquid_symbol.get_paired_symbol() );
   }
   void add_coining( const asset& coining_shares, const asset& coining_value )
   {
      // There's no need to store coining value (in liquid SMT variant) in regular balance.
      coining += coining_shares;
   }
   ///@}

   bool validate() const
   { return liquid.symbol == coining.symbol.get_paired_symbol(); }
};

/**
 * Class responsible for holding reward balance of SMT for given account.
 * It has not been unified with regular balance object counterpart, due to different number
 * of fields needed to hold balances (2 for regular, 3 for reward).
 */
class account_rewards_balance_object : public object< account_rewards_balance_object_type, account_rewards_balance_object >
{
   account_rewards_balance_object() = delete;

public:   
   template <typename Constructor, typename Allocator>
   account_rewards_balance_object(Constructor&& c, allocator< Allocator > a)
   {
      c( *this );
   }

   // id_type is actually oid<account_rewards_balance_object>
   id_type             id;
   /// Name of the account, the balance is held for.
   account_name_type   owner;
   asset               pending_liquid;          /// 'reward_voilk_balance' for pending VOILK
   asset               pending_coining_shares;  /// 'reward_coining_balance' for pending COINS
   asset               pending_coining_value;   /// 'reward_coining_voilk' for pending COINS

   /** Set of simple methods that allow unification of
    *  regular and rewards balance manipulation code.
    */
   ///@{
   asset_symbol_type get_liquid_symbol() const
   {
      return pending_liquid.symbol;
   }
   void clear_balance( asset_symbol_type liquid_symbol )
   {
      owner = "";
      pending_liquid = asset( 0, liquid_symbol);
      pending_coining_shares = asset( 0, liquid_symbol.get_paired_symbol() );
      pending_coining_value = asset( 0, liquid_symbol);
   }
   void add_coining( const asset& coining_shares, const asset& coining_value )
   {
      pending_coining_shares += coining_shares;
      pending_coining_value += coining_value;
   }
   ///@}

   bool validate() const
   {
      return pending_liquid.symbol == pending_coining_shares.symbol.get_paired_symbol() &&
             pending_liquid.symbol == pending_coining_value.symbol;
   }
};

struct by_owner_liquid_symbol;

typedef multi_index_container <
   account_regular_balance_object,
   indexed_by <
      ordered_unique< tag< by_id >,
         member< account_regular_balance_object, account_regular_balance_id_type, &account_regular_balance_object::id>
      >,
      ordered_unique<tag<by_owner_liquid_symbol>,
         composite_key<account_regular_balance_object,
            member< account_regular_balance_object, account_name_type, &account_regular_balance_object::owner >,
            const_mem_fun< account_regular_balance_object, asset_symbol_type, &account_regular_balance_object::get_liquid_symbol >
         >
      >
   >,
   allocator< account_regular_balance_object >
> account_regular_balance_index;

typedef multi_index_container <
   account_rewards_balance_object,
   indexed_by <
      ordered_unique< tag< by_id >,
         member< account_rewards_balance_object, account_rewards_balance_id_type, &account_rewards_balance_object::id>
      >,
      ordered_unique<tag<by_owner_liquid_symbol>,
         composite_key<account_rewards_balance_object,
            member< account_rewards_balance_object, account_name_type, &account_rewards_balance_object::owner >,
            const_mem_fun< account_rewards_balance_object, asset_symbol_type, &account_rewards_balance_object::get_liquid_symbol >
         >
      >
   >,
   allocator< account_rewards_balance_object >
> account_rewards_balance_index;

} } // namespace voilk::chain

FC_REFLECT( voilk::chain::account_regular_balance_object,
   (id)
   (owner)
   (liquid)
   (coining)
)

FC_REFLECT( voilk::chain::account_rewards_balance_object,
   (id)
   (owner)
   (pending_liquid)
   (pending_coining_shares)
   (pending_coining_value)
)

CHAINBASE_SET_INDEX_TYPE( voilk::chain::account_regular_balance_object, voilk::chain::account_regular_balance_index )
CHAINBASE_SET_INDEX_TYPE( voilk::chain::account_rewards_balance_object, voilk::chain::account_rewards_balance_index )

#endif
