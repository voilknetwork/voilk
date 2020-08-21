#include <voilk/app/plugin.hpp>

#include <boost/multi_index/composite_key.hpp>

//
// Plugins should #define their SPACE_ID's so plugins with
// conflicting SPACE_ID assignments can be compiled into the
// same binary (by simply re-assigning some of the conflicting #defined
// SPACE_ID's in a build script).
//
// Assignment of SPACE_ID's cannot be done at run-time because
// various template automagic depends on them being known at compile
// time.
//
#ifndef VOILK_ACCOUNT_STATISTICS_SPACE_ID
#define VOILK_ACCOUNT_STATISTICS_SPACE_ID 10
#endif

#ifndef VOILK_ACCOUNT_STATISTICS_PLUGIN_NAME
#define VOILK_ACCOUNT_STATISTICS_PLUGIN_NAME "account_stats"
#endif

namespace voilk { namespace account_statistics {

using namespace chain;
using app::application;

enum account_statistics_plugin_object_types
{
   account_stats_bucket_object_type    = ( VOILK_ACCOUNT_STATISTICS_SPACE_ID << 8 ),
   account_activity_bucket_object_type = ( VOILK_ACCOUNT_STATISTICS_SPACE_ID << 8 ) + 1
};

struct account_stats_bucket_object : public object< account_stats_bucket_object_type, account_stats_bucket_object >
{
   template< typename Constructor, typename Allocator >
   account_stats_bucket_object( Constructor&& c, allocator< Allocator > a )
   {
      c( *this );
   }

   account_stats_bucket_object() {}

   id_type              id;

   fc::time_point_sec   open;                                     ///< Open time of the bucket
   uint32_t             seconds = 0;                              ///< Seconds accounted for in the bucket
   account_name_type    name;                                     ///< Account name
   uint32_t             transactions = 0;                         ///< Transactions this account signed
   uint32_t             market_bandwidth = 0;                     ///< Charged bandwidth for market transactions
   uint32_t             non_market_bandwidth = 0;                 ///< Charged bandwidth for non-market transactions
   uint32_t             total_ops = 0;                            ///< Ops this account was an authority on
   uint32_t             market_ops = 0;                           ///< Market operations
   uint32_t             forum_ops = 0;                            ///< Forum operations
   uint32_t             root_comments = 0;                        ///< Top level root comments
   uint32_t             root_comment_edits = 0;                   ///< Edits to root comments
   uint32_t             root_comments_deleted = 0;                ///< Root comments deleted
   uint32_t             replies = 0;                              ///< Replies to comments
   uint32_t             reply_edits = 0;                          ///< Edits to replies
   uint32_t             replies_deleted = 0;                      ///< Replies deleted
   uint32_t             new_root_votes = 0;                       ///< New votes on root comments
   uint32_t             changed_root_votes = 0;                   ///< Changed votes for root comments
   uint32_t             new_reply_votes = 0;                      ///< New votes on replies
   uint32_t             changed_reply_votes = 0;                  ///< Changed votes for replies
   uint32_t             author_reward_payouts = 0;                ///< Number of author reward payouts
   share_type           author_rewards_vsd = 0;                   ///< VSD paid for author rewards
   share_type           author_rewards_coins = 0;                 ///< COINS paid for author rewards
   share_type           author_rewards_total_voilk_value = 0;     ///< VOILK Value of author rewards
   share_type           author_rewards_payout_vsd_value = 0;      ///< VSD Value of author rewards at time of payout
   uint32_t             curation_reward_payouts = 0;              ///< Number of curation reward payouts.
   share_type           curation_rewards_coins = 0;               ///< COINS paid for curation rewards
   share_type           curation_rewards_voilk_value = 0;         ///< VOILK Value of curation rewards
   share_type           curation_rewards_payout_vsd_value = 0;    ///< VSD Value of curation rewards at time of payout
   uint32_t             liquidity_reward_payouts = 0;             ///< Number of liquidity reward payouts
   share_type           liquidity_rewards = 0;                    ///< Amount of VOILK paid as liquidity rewards
   uint32_t             transfers_to = 0;                         ///< Account to account transfers to this account
   uint32_t             transfers_from = 0;                       ///< Account to account transfers from this account
   share_type           voilk_sent = 0;                           ///< VOILK sent from this account
   share_type           voilk_received = 0;                       ///< VOILK received by this account
   share_type           vsd_sent = 0;                             ///< VSD sent from this account
   share_type           vsd_received = 0;                         ///< VSD received by this account
   uint32_t             vsd_interest_payments = 0;                ///< Number of times interest was paid to VSD
   share_type           vsd_paid_as_interest = 0;                 ///< Amount of VSD paid as interest
   uint32_t             transfers_to_coining = 0;                 ///< Transfers to coining by this account. Note: Transfer to coining from A to B counts as a transfer from A to B followed by a coining deposit by B.
   share_type           voilk_coined = 0;                         ///< VOILK coined by the account
   share_type           new_coins = 0;                            ///< New COINS by coining transfers
   uint32_t             new_coining_withdrawal_requests = 0;      ///< New coining withdrawal requests
   uint32_t             modified_coining_withdrawal_requests = 0; ///< Changes to coining withdraw requests
   uint32_t             coining_withdrawals_processed = 0;        ///< Coining withdrawals processed for this account
   uint32_t             finished_coining_withdrawals = 0;         ///< Processed coining withdrawals that are now finished
   share_type           coins_withdrawn = 0;                      ///< COINS withdrawn from the account
   share_type           voilk_received_from_withdrawls = 0;       ///< VOILK received from this account's coining withdrawals
   share_type           voilk_received_from_routes = 0;           ///< VOILK received from another account's coining withdrawals
   share_type           coins_received_from_routes = 0;           ///< COINS received from another account's coining withdrawals
   uint32_t             vsd_conversion_requests_created = 0;      ///< VSD conversion requests created
   share_type           vsd_to_be_converted = 0;                  ///< Amount of VSD to be converted
   uint32_t             vsd_conversion_requests_filled = 0;       ///< VSD conversion requests filled
   share_type           voilk_converted = 0;                      ///< Amount of VOILK that was converted
   uint32_t             limit_orders_created = 0;                 ///< Limit orders created by this account
   uint32_t             limit_orders_filled = 0;                  ///< Limit orders filled by this account
   uint32_t             limit_orders_cancelled = 0;               ///< Limit orders cancelled by this account
   share_type           limit_order_voilk_paid = 0;               ///< VOILK paid by limit orders
   share_type           limit_order_voilk_received = 0;           ///< VOILK received from limit orders
   share_type           limit_order_vsd_paid = 0;                 ///< VSD paid by limit orders
   share_type           limit_order_vsd_received = 0;             ///< VSD received by limit orders
   uint32_t             total_pow = 0;                            ///< POW completed
   uint128_t            estimated_hashpower = 0;                  ///< Estimated hashpower
};

typedef account_stats_bucket_object::id_type account_stats_bucket_id_type;

struct account_activity_bucket_object : public object< account_activity_bucket_object_type, account_activity_bucket_object >
{
   template< typename Constructor, typename Allocator >
   account_activity_bucket_object( Constructor&& c, allocator< Allocator > a )
   {
      c( *this );
   }

   account_activity_bucket_object() {}

   id_type              id;

   fc::time_point_sec   open;                                  ///< Open time for the bucket
   uint32_t             seconds = 0;                           ///< Seconds accounted for in the bucket
   uint32_t             active_market_accounts = 0;            ///< Active market accounts in the bucket
   uint32_t             active_forum_accounts = 0;             ///< Active forum accounts in the bucket
   uint32_t             active_market_and_forum_accounts = 0;  ///< Active accounts in both the market and the forum
};

typedef account_activity_bucket_object::id_type account_activity_bucket_id_type;

namespace detail
{
   class account_statistics_plugin_impl;
}

class account_statistics_plugin : public voilk::app::plugin
{
   public:
      account_statistics_plugin( application* app );
      virtual ~account_statistics_plugin();

      virtual std::string plugin_name()const override { return VOILK_ACCOUNT_STATISTICS_PLUGIN_NAME; }
      virtual void plugin_set_program_options(
         boost::program_options::options_description& cli,
         boost::program_options::options_description& cfg ) override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;

      const flat_set< uint32_t >& get_tracked_buckets() const;
      uint32_t get_max_history_per_bucket() const;
      const flat_set< std::string >& get_tracked_accounts() const;

   private:
      friend class detail::account_statistics_plugin_impl;
      std::unique_ptr< detail::account_statistics_plugin_impl > _my;
};

} } // voilk::account_statistics

FC_REFLECT( voilk::account_statistics::account_stats_bucket_object,
   (id)
   (open)
   (seconds)
   (name)
   (transactions)
   (market_bandwidth)
   (non_market_bandwidth)
   (total_ops)
   (market_ops)
   (forum_ops)
   (root_comments)
   (root_comment_edits)
   (root_comments_deleted)
   (replies)
   (reply_edits)
   (replies_deleted)
   (new_root_votes)
   (changed_root_votes)
   (new_reply_votes)
   (changed_reply_votes)
   (author_reward_payouts)
   (author_rewards_vsd)
   (author_rewards_coins)
   (author_rewards_total_voilk_value)
   (author_rewards_payout_vsd_value)
   (curation_reward_payouts)
   (curation_rewards_coins)
   (curation_rewards_voilk_value)
   (curation_rewards_payout_vsd_value)
   (liquidity_reward_payouts)
   (liquidity_rewards)
   (transfers_to)
   (transfers_from)
   (voilk_sent)
   (voilk_received)
   (vsd_sent)
   (vsd_received)
   (vsd_interest_payments)
   (vsd_paid_as_interest)
   (transfers_to_coining)
   (voilk_coined)
   (new_coins)
   (new_coining_withdrawal_requests)
   (modified_coining_withdrawal_requests)
   (coining_withdrawals_processed)
   (finished_coining_withdrawals)
   (coins_withdrawn)
   (voilk_received_from_withdrawls)
   (voilk_received_from_routes)
   (coins_received_from_routes)
   (vsd_conversion_requests_created)
   (vsd_to_be_converted)
   (vsd_conversion_requests_filled)
   (voilk_converted)
   (limit_orders_created)
   (limit_orders_filled)
   (limit_orders_cancelled)
   (limit_order_voilk_paid)
   (limit_order_voilk_received)
   (limit_order_vsd_paid)
   (limit_order_vsd_received)
   (total_pow)
   (estimated_hashpower)
)
//SET_INDEX_TYPE( voilk::account_statistics::account_stats_bucket_object,)

FC_REFLECT(
   voilk::account_statistics::account_activity_bucket_object,
   (id)
   (open)
   (seconds)
   (active_market_accounts)
   (active_forum_accounts)
   (active_market_and_forum_accounts)
)
