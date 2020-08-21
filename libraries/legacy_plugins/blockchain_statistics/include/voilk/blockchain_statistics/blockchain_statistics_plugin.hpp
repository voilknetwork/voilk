#pragma once
#include <voilk/app/plugin.hpp>

#include <voilk/chain/voilk_object_types.hpp>

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
#ifndef VOILK_BLOCKCHAIN_STATISTICS_SPACE_ID
#define VOILK_BLOCKCHAIN_STATISTICS_SPACE_ID 9
#endif

#ifndef VOILK_BLOCKCHAIN_STATISTICS_PLUGIN_NAME
#define VOILK_BLOCKCHAIN_STATISTICS_PLUGIN_NAME "chain_stats"
#endif

namespace voilk { namespace blockchain_statistics {

using namespace voilk::chain;
using app::application;

enum blockchain_statistics_object_type
{
   bucket_object_type = ( VOILK_BLOCKCHAIN_STATISTICS_SPACE_ID << 8 )
};

namespace detail
{
   class blockchain_statistics_plugin_impl;
}

class blockchain_statistics_plugin : public voilk::app::plugin
{
   public:
      blockchain_statistics_plugin( application* app );
      virtual ~blockchain_statistics_plugin();

      virtual std::string plugin_name()const override { return VOILK_BLOCKCHAIN_STATISTICS_PLUGIN_NAME; }
      virtual void plugin_set_program_options(
         boost::program_options::options_description& cli,
         boost::program_options::options_description& cfg ) override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;

      const flat_set< uint32_t >& get_tracked_buckets() const;
      uint32_t get_max_history_per_bucket() const;

   private:
      friend class detail::blockchain_statistics_plugin_impl;
      std::unique_ptr< detail::blockchain_statistics_plugin_impl > _my;
};

struct bucket_object : public object< bucket_object_type, bucket_object >
{
   template< typename Constructor, typename Allocator >
   bucket_object( Constructor&& c, allocator< Allocator > a )
   {
      c( *this );
   }

   id_type              id;

   fc::time_point_sec   open;                                        ///< Open time of the bucket
   uint32_t             seconds = 0;                                 ///< Seconds accounted for in the bucket
   uint32_t             blocks = 0;                                  ///< Blocks produced
   uint32_t             bandwidth = 0;                               ///< Bandwidth in bytes
   uint32_t             operations = 0;                              ///< Operations evaluated
   uint32_t             transactions = 0;                            ///< Transactions processed
   uint32_t             transfers = 0;                               ///< Account to account transfers
   share_type           voilk_transferred = 0;                       ///< VOILK transferred from account to account
   share_type           vsd_transferred = 0;                         ///< VSD transferred from account to account
   share_type           vsd_paid_as_interest = 0;                    ///< VSD paid as interest
   uint32_t             paid_accounts_created = 0;                   ///< Accounts created with fee
   uint32_t             mined_accounts_created = 0;                  ///< Accounts mined for free
   uint32_t             root_comments = 0;                           ///< Top level root comments
   uint32_t             root_comment_edits = 0;                      ///< Edits to root comments
   uint32_t             root_comments_deleted = 0;                   ///< Root comments deleted
   uint32_t             replies = 0;                                 ///< Replies to comments
   uint32_t             reply_edits = 0;                             ///< Edits to replies
   uint32_t             replies_deleted = 0;                         ///< Replies deleted
   uint32_t             new_root_votes = 0;                          ///< New votes on root comments
   uint32_t             changed_root_votes = 0;                      ///< Changed votes on root comments
   uint32_t             new_reply_votes = 0;                         ///< New votes on replies
   uint32_t             changed_reply_votes = 0;                     ///< Changed votes on replies
   uint32_t             payouts = 0;                                 ///< Number of comment payouts
   share_type           vsd_paid_to_authors = 0;                     ///< Ammount of VSD paid to authors
   share_type           coins_paid_to_authors = 0;                   ///< Ammount of VESS paid to authors
   share_type           coins_paid_to_curators = 0;                  ///< Ammount of COINS paid to curators
   share_type           liquidity_rewards_paid = 0;                  ///< Ammount of VOILK paid to market makers
   uint32_t             transfers_to_coining = 0;                    ///< Transfers of VOILK into COINS
   share_type           voilk_coined = 0;                            ///< Ammount of VOILK coined
   uint32_t             new_coining_withdrawal_requests = 0;         ///< New coining withdrawal requests
   uint32_t             modified_coining_withdrawal_requests = 0;    ///< Changes to coining withdrawal requests
   share_type           coining_withdraw_rate_delta = 0;
   uint32_t             coining_withdrawals_processed = 0;           ///< Number of coining withdrawals
   uint32_t             finished_coining_withdrawals = 0;            ///< Processed coining withdrawals that are now finished
   share_type           coins_withdrawn = 0;                         ///< Ammount of COINS withdrawn to VOILK
   share_type           coins_transferred = 0;                       ///< Ammount of COINS transferred to another account
   uint32_t             vsd_conversion_requests_created = 0;         ///< VSD conversion requests created
   share_type           vsd_to_be_converted = 0;                     ///< Amount of VSD to be converted
   uint32_t             vsd_conversion_requests_filled = 0;          ///< VSD conversion requests filled
   share_type           voilk_converted = 0;                         ///< Amount of VOILK that was converted
   uint32_t             limit_orders_created = 0;                    ///< Limit orders created
   uint32_t             limit_orders_filled = 0;                     ///< Limit orders filled
   uint32_t             limit_orders_cancelled = 0;                  ///< Limit orders cancelled
   uint32_t             total_pow = 0;                               ///< POW submitted
   uint128_t            estimated_hashpower = 0;                     ///< Estimated average hashpower over interval
};

typedef oid< bucket_object > bucket_id_type;

struct by_id;
struct by_bucket;
typedef multi_index_container<
   bucket_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< bucket_object, bucket_id_type, &bucket_object::id > >,
      ordered_unique< tag< by_bucket >,
         composite_key< bucket_object,
            member< bucket_object, uint32_t, &bucket_object::seconds >,
            member< bucket_object, fc::time_point_sec, &bucket_object::open >
         >
      >
   >,
   allocator< bucket_object >
> bucket_index;

} } // voilk::blockchain_statistics

FC_REFLECT( voilk::blockchain_statistics::bucket_object,
   (id)
   (open)
   (seconds)
   (blocks)
   (bandwidth)
   (operations)
   (transactions)
   (transfers)
   (voilk_transferred)
   (vsd_transferred)
   (vsd_paid_as_interest)
   (paid_accounts_created)
   (mined_accounts_created)
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
   (payouts)
   (vsd_paid_to_authors)
   (coins_paid_to_authors)
   (coins_paid_to_curators)
   (liquidity_rewards_paid)
   (transfers_to_coining)
   (voilk_coined)
   (new_coining_withdrawal_requests)
   (modified_coining_withdrawal_requests)
   (coining_withdraw_rate_delta)
   (coining_withdrawals_processed)
   (finished_coining_withdrawals)
   (coins_withdrawn)
   (coins_transferred)
   (vsd_conversion_requests_created)
   (vsd_to_be_converted)
   (vsd_conversion_requests_filled)
   (voilk_converted)
   (limit_orders_created)
   (limit_orders_filled)
   (limit_orders_cancelled)
   (total_pow)
   (estimated_hashpower)
)
CHAINBASE_SET_INDEX_TYPE( voilk::blockchain_statistics::bucket_object, voilk::blockchain_statistics::bucket_index )
