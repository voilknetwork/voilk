/*
 * Copyright (c) 2016 Voilknetwork, Inc., and contributors.
 */
#pragma once
#include <voilk/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define VOILK_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define VOILK_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define VOILK_INIT_PUBLIC_KEY_STR             (std::string( voilk::protocol::public_key_type(VOILK_INIT_PRIVATE_KEY.get_public_key()) ))
#define VOILK_CHAIN_ID (fc::sha256::hash("testnet"))
#define VOILK_ADDRESS_PREFIX                  "TST"

#define VOILK_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define VOILK_MINING_TIME                     (fc::time_point_sec(1451606400))
#define VOILK_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define VOILK_CASHOUT_WINDOW_SECONDS_PRE_HF12 (VOILK_CASHOUT_WINDOW_SECONDS)
#define VOILK_CASHOUT_WINDOW_SECONDS_PRE_HF17 (VOILK_CASHOUT_WINDOW_SECONDS)
#define VOILK_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define VOILK_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define VOILK_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define VOILK_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define VOILK_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define VOILK_MIN_ACCOUNT_CREATION_FEE          0
#define VOILK_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define VOILK_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define VOILK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define VOILK_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define VOILK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define VOILK_INIT_SUPPLY                     (int64_t( 100 ) * int64_t( 1000000 ) * int64_t( 1000 ))
#define VSD_INIT_SUPPLY                       (int64_t( 100 ) * int64_t( 1000000 ) * int64_t( 1000 ))

// It makes block reward to be about 1.032 VOILK/block which goes down to 0.1 over the period of 20 years
#define VOILK_BLOCK_REWARD_CONSTANT           (int64_t( 111 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE VOILK NETWORK

#define VOILK_BLOCKCHAIN_VERSION              ( version(0, 20, 8) )

#define VOILK_INIT_PUBLIC_KEY_STR             "SHR7YDq7bh9EG3oufCAPRjf1ZESqCqjdjj55Xp2QXDTnYndVqxBom"
#define VOILK_CHAIN_ID (fc::sha256::hash("Success is not final, failure is not fatal. It is the courage to continue that counts."))
#define VOILK_ADDRESS_PREFIX                  "SHR"

#define VOILK_GENESIS_TIME                    (fc::time_point_sec(1598041858))
#define VOILK_MINING_TIME                     (fc::time_point_sec(1598041858))
#define VOILK_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24*5)    /// 5 days
#define VOILK_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*24*7)    /// 7 Days 
#define VOILK_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define VOILK_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define VOILK_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define VOILK_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define VOILK_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
#define VOILK_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define VOILK_MIN_ACCOUNT_CREATION_FEE           1
#define VOILK_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define VOILK_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define VOILK_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define VOILK_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define VOILK_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 0

#define VOILK_INIT_SUPPLY                     (int64_t( 10 ) * int64_t( 1000000 ) * int64_t( 1000 ))
#define VSD_INIT_SUPPLY                       (int64_t( 10 ) * int64_t( 1000000 ) * int64_t( 1000 ))

// It makes block reward to be about 1.032 VOILK/block which goes down to 0.1 over the period of 20 years
#define VOILK_BLOCK_REWARD_CONSTANT           (int64_t( 111 ) * int64_t( 1000000 ) * int64_t( 1000 ))

#endif

#define COINS_SYMBOL  (voilk::protocol::asset_symbol_type::from_asset_num( VOILK_ASSET_NUM_COINS ) )
#define VOILK_SYMBOL  (voilk::protocol::asset_symbol_type::from_asset_num( VOILK_ASSET_NUM_VOILK ) )
#define VSD_SYMBOL    (voilk::protocol::asset_symbol_type::from_asset_num( VOILK_ASSET_NUM_VSD ) )

#define VOILK_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( VOILK_BLOCKCHAIN_VERSION ) )

#define VOILK_BLOCK_INTERVAL                  3
#define VOILK_BLOCKS_PER_YEAR                 (365*24*60*60/VOILK_BLOCK_INTERVAL)
#define VOILK_BLOCKS_PER_DAY                  (24*60*60/VOILK_BLOCK_INTERVAL)
#define VOILK_START_COINING_BLOCK             (VOILK_BLOCKS_PER_DAY * 7)
#define VOILK_INFLATION_NUMBER                0

#define VOILK_START_MINER_VOTING_BLOCK        (VOILK_BLOCKS_PER_YEAR * 5)

#define VOILK_INIT_MINER_NAME                 "voilk"
#define VOILK_NUM_INIT_MINERS                 1
#define VOILK_INIT_TIME                       (fc::time_point_sec());
#define VOILK_FIRST_BLOCK_TIME                (1598041858)

#define VOILK_MAX_WITNESSES                   21
#define VOILK_TIMESHARE_WEIGHT                5
#define VOILK_WITNESS_PAY_NORMALIZATION       25

#define VOILK_MAX_VOTED_WITNESSES_HF0         19
#define VOILK_MAX_MINER_WITNESSES_HF0         1
#define VOILK_MAX_RUNNER_WITNESSES_HF0        1

#define VOILK_MAX_VOTED_WITNESSES_HF17        20
#define VOILK_MAX_MINER_WITNESSES_HF17        0
#define VOILK_MAX_RUNNER_WITNESSES_HF17       1

#define VOILK_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define VOILK_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define VOILK_MAX_MEMO_SIZE                   2048
#define VOILK_MAX_PROXY_RECURSION_DEPTH       4
#define VOILK_COINING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define VOILK_COINING_WITHDRAW_INTERVALS      365
#define VOILK_COINING_WITHDRAW_INTERVAL_SECONDS (60*60*24) /// 1 day per interval
#define VOILK_MAX_WITHDRAW_ROUTES             10
#define VOILK_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define VOILK_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define VOILK_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define VOILK_MAX_VOTE_CHANGES                5
#define VOILK_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define VOILK_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define VOILK_MIN_VOTE_INTERVAL_SEC           3
#define VOILK_VOTE_DUST_THRESHOLD             (2500)

#define VOILK_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define VOILK_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define VOILK_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define VOILK_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define VOILK_POST_WEIGHT_CONSTANT            (uint64_t(4*VOILK_100_PERCENT) * (4*VOILK_100_PERCENT))// (4*VOILK_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define VOILK_MAX_ACCOUNT_WITNESS_VOTES       30

#define VOILK_100_PERCENT                     10000
#define VOILK_1_PERCENT                       (VOILK_100_PERCENT/100)
#define VOILK_DEFAULT_VSD_INTEREST_RATE       (5*VOILK_1_PERCENT) ///< 5% APR
#define VOILK_DISABLE_VSD_TO_VOILK_CONVERTION (1) // true

#define VOILK_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define VOILK_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define VOILK_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define VOILK_CONTENT_REWARD_PERCENT          (85*VOILK_1_PERCENT) //85% of block reward goes to content creators
#define VOILK_COINING_FUND_PERCENT            (0*VOILK_1_PERCENT) //0% staking reward
/// remaining 15% goes to block producers/witnesses

#define VOILK_MINER_PAY_PERCENT               (VOILK_1_PERCENT) // 1%
#define VOILK_MAX_RATION_DECAY_RATE           (1000000)

#define VOILK_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define VOILK_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define VOILK_MAX_COMMENT_DEPTH_PRE_HF17      6
#define VOILK_MAX_COMMENT_DEPTH               0xffff // 64k
#define VOILK_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define VOILK_MAX_RESERVE_RATIO               (20000)

#define VOILK_CREATE_ACCOUNT_WITH_VOILK_MODIFIER 1
#define VOILK_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define VOILK_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define VOILK_MINING_REWARD                   asset( 1000, VOILK_SYMBOL )
#define VOILK_EQUIHASH_N                      140
#define VOILK_EQUIHASH_K                      6

#define VOILK_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define VOILK_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define VOILK_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define VOILK_LIQUIDITY_REWARD_BLOCKS         (VOILK_LIQUIDITY_REWARD_PERIOD_SEC/VOILK_BLOCK_INTERVAL)
#define VOILK_MIN_LIQUIDITY_REWARD            (asset( 1000*VOILK_LIQUIDITY_REWARD_BLOCKS, VOILK_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define VOILK_MIN_CONTENT_REWARD              VOILK_MINING_REWARD
#define VOILK_MIN_CURATE_REWARD               VOILK_MINING_REWARD
#define VOILK_MIN_PRODUCER_REWARD             VOILK_MINING_REWARD
#define VOILK_MIN_POW_REWARD                  VOILK_MINING_REWARD

#define VOILK_ACTIVE_CHALLENGE_FEE            asset( 2000, VOILK_SYMBOL )
#define VOILK_OWNER_CHALLENGE_FEE             asset( 30000, VOILK_SYMBOL )
#define VOILK_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define VOILK_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define VOILK_POST_REWARD_FUND_NAME           ("post")
#define VOILK_COMMENT_REWARD_FUND_NAME        ("comment")
#define VOILK_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define VOILK_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define VOILK_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**VOILK_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for coining
#define VOILK_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that VOILK_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define VOILK_APR_PERCENT_SHIFT_PER_BLOCK             87

#define VOILK_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define VOILK_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**VOILK_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define VOILK_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that VOILK_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define VOILK_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x coining rewards*
#define VOILK_CURATE_APR_PERCENT              3875
#define VOILK_CONTENT_APR_PERCENT             3875
#define VOILK_LIQUIDITY_APR_PERCENT            750
#define VOILK_PRODUCER_APR_PERCENT             750
#define VOILK_POW_APR_PERCENT                  750

#define VOILK_MIN_PAYOUT_VSD                  (asset(20,VSD_SYMBOL))

#define VOILK_VSD_STOP_PERCENT_HF14           (5*VOILK_1_PERCENT ) // Stop printing VSD at 5% Market Cap
#define VOILK_VSD_STOP_PERCENT_HF20           (10*VOILK_1_PERCENT ) // Stop printing VSD at 10% Market Cap
#define VOILK_VSD_START_PERCENT_HF14          (2*VOILK_1_PERCENT) // Start reducing printing of VSD at 2% Market Cap
#define VOILK_VSD_START_PERCENT_HF20          (9*VOILK_1_PERCENT) // Start reducing printing of VSD at 9% Market Cap

#define VOILK_MIN_ACCOUNT_NAME_LENGTH          3
#define VOILK_MAX_ACCOUNT_NAME_LENGTH         16

#define VOILK_MIN_PERMLINK_LENGTH             0
#define VOILK_MAX_PERMLINK_LENGTH             256
#define VOILK_MAX_WITNESS_URL_LENGTH          2048

#define VOILK_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define VOILK_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define VOILK_MAX_SIG_CHECK_DEPTH             2
#define VOILK_MAX_SIG_CHECK_ACCOUNTS          125

#define VOILK_MIN_TRANSACTION_SIZE_LIMIT      1024
#define VOILK_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define VOILK_VSD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60) // Pay interest every hour  
#define VOILK_MAX_TRANSACTION_SIZE            (1024*64)
#define VOILK_MIN_BLOCK_SIZE_LIMIT            (VOILK_MAX_TRANSACTION_SIZE)
#define VOILK_MAX_BLOCK_SIZE                  (VOILK_MAX_TRANSACTION_SIZE*VOILK_BLOCK_INTERVAL*2000)
#define VOILK_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define VOILK_MIN_BLOCK_SIZE                  115
#define VOILK_BLOCKS_PER_HOUR                 (60*60/VOILK_BLOCK_INTERVAL)
#define VOILK_FEED_INTERVAL_BLOCKS            (VOILK_BLOCKS_PER_HOUR/12) // Update every 100 blocks 
#define VOILK_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define VOILK_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define VOILK_MAX_FEED_AGE_SECONDS            (60*60*1) // 1 hour
#define VOILK_MIN_FEEDS                       (1)//VOILK_MAX_WITNESSES/7) 1 witness enough to publish feed
#define VOILK_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define VOILK_CONVERSION_DELAY                (fc::hours(VOILK_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define VOILK_MIN_UNDO_HISTORY                10
#define VOILK_MAX_UNDO_HISTORY                10000

#define VOILK_MIN_TRANSACTION_EXPIRATION_LIMIT (VOILK_BLOCK_INTERVAL * 5) // 5 transactions per block
#define VOILK_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define VOILK_BLOCKCHAIN_PRECISION_DIGITS     3
#define VOILK_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define VOILK_MAX_AUTHORITY_MEMBERSHIP        40
#define VOILK_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define VOILK_MAX_URL_LENGTH                  127

#define VOILK_IRREVERSIBLE_THRESHOLD          (75 * VOILK_1_PERCENT)

#define VOILK_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define VOILK_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define VOILK_INITIAL_VOTE_POWER_RATE (10)
#define VOILK_REDUCED_VOTE_POWER_RATE (10)

#define VOILK_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define VOILK_DELEGATION_RETURN_PERIOD_HF0   (VOILK_CASHOUT_WINDOW_SECONDS)
#define VOILK_DELEGATION_RETURN_PERIOD_HF20  (VOILK_VOTING_MANA_REGENERATION_SECONDS)

#define VOILK_RD_MIN_DECAY_BITS               6
#define VOILK_RD_MAX_DECAY_BITS              32
#define VOILK_RD_DECAY_DENOM_SHIFT           36
#define VOILK_RD_MAX_POOL_BITS               64
#define VOILK_RD_MAX_BUDGET_1                ((uint64_t(1) << (VOILK_RD_MAX_POOL_BITS + VOILK_RD_MIN_DECAY_BITS - VOILK_RD_DECAY_DENOM_SHIFT))-1)
#define VOILK_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-VOILK_RD_DECAY_DENOM_SHIFT))-1)
#define VOILK_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define VOILK_RD_MAX_BUDGET                  (int32_t( std::min( { VOILK_RD_MAX_BUDGET_1, VOILK_RD_MAX_BUDGET_2, VOILK_RD_MAX_BUDGET_3 } )) )
#define VOILK_RD_MIN_DECAY                   (uint32_t(1) << VOILK_RD_MIN_DECAY_BITS)
#define VOILK_RD_MIN_BUDGET                  1
#define VOILK_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define VOILK_ACCOUNT_SUBSIDY_PRECISION      (VOILK_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define VOILK_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * VOILK_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define VOILK_WITNESS_SUBSIDY_DECAY_PERCENT  (VOILK_MAX_WITNESSES * VOILK_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define VOILK_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define VOILK_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define VOILK_DECAY_BACKSTOP_PERCENT         (90 * VOILK_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define VOILK_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define VOILK_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define VOILK_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define VOILK_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define VOILK_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef VOILK_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_COINING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// VOILK_ENABLE_SMT

