/*
 * Copyright (c) 2016 Bearshares, Inc., and contributors.
 */
#pragma once
#include <bears/protocol/hardfork.hpp>

// WARNING!
// Every symbol defined here needs to be handled appropriately in get_config.cpp
// This is checked by get_config_check.sh called from Dockerfile

#ifdef IS_TEST_NET
#define BEARS_BLOCKCHAIN_VERSION              ( version(0, 21, 0) )

#define BEARS_INIT_PRIVATE_KEY                (fc::ecc::private_key::regenerate(fc::sha256::hash(std::string("init_key"))))
#define BEARS_INIT_PUBLIC_KEY_STR             (std::string( bears::protocol::public_key_type(BEARS_INIT_PRIVATE_KEY.get_public_key()) ))
#define BEARS_CHAIN_ID (fc::sha256::hash("testnet"))
#define BEARS_ADDRESS_PREFIX                  "TST"

#define BEARS_GENESIS_TIME                    (fc::time_point_sec(1451606400))
#define BEARS_MINING_TIME                     (fc::time_point_sec(1451606400))
#define BEARS_CASHOUT_WINDOW_SECONDS          (60*60) /// 1 hr
#define BEARS_CASHOUT_WINDOW_SECONDS_PRE_HF12 (BEARS_CASHOUT_WINDOW_SECONDS)
#define BEARS_CASHOUT_WINDOW_SECONDS_PRE_HF17 (BEARS_CASHOUT_WINDOW_SECONDS)
#define BEARS_SECOND_CASHOUT_WINDOW           (60*60*24*3) /// 3 days
#define BEARS_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24) /// 1 day
#define BEARS_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define BEARS_UPVOTE_LOCKOUT_SECONDS          (60*5)    /// 5 minutes
#define BEARS_UPVOTE_LOCKOUT_HF17             (fc::minutes(5))


#define BEARS_MIN_ACCOUNT_CREATION_FEE          0
#define BEARS_MAX_ACCOUNT_CREATION_FEE          int64_t(1000000000)

#define BEARS_OWNER_AUTH_RECOVERY_PERIOD                  fc::seconds(60)
#define BEARS_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::seconds(12)
#define BEARS_OWNER_UPDATE_LIMIT                          fc::seconds(0)
#define BEARS_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 1

#define BEARS_INIT_SUPPLY                     (int64_t( 250 ) * int64_t( 1000000 ) * int64_t( 1000 ))

/// Allows to limit number of total produced blocks.
#define TESTNET_BLOCK_LIMIT                   (3000000)

#else // IS LIVE BEARS NETWORK

#define BEARS_BLOCKCHAIN_VERSION              ( version(0, 20, 5) )

#define BEARS_INIT_PUBLIC_KEY_STR             "SHR7YDq7bh9EG3oufCAPRjf1ZESqCqjdjj55Xp2QXDTnYndVqxBom"
#define BEARS_CHAIN_ID (fc::sha256::hash("I love Pakistan"))
#define BEARS_ADDRESS_PREFIX                  "SHR"

#define BEARS_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define BEARS_MINING_TIME                     (fc::time_point_sec(1458838800))
#define BEARS_CASHOUT_WINDOW_SECONDS_PRE_HF12 (60*60*24*5)    /// 1 day
#define BEARS_CASHOUT_WINDOW_SECONDS_PRE_HF17 (60*60*24*7)    /// 7 Days 
#define BEARS_CASHOUT_WINDOW_SECONDS          (60*60*24*7)  /// 7 days
#define BEARS_SECOND_CASHOUT_WINDOW           (60*60*24*30) /// 30 days
#define BEARS_MAX_CASHOUT_WINDOW_SECONDS      (60*60*24*14) /// 2 weeks
#define BEARS_UPVOTE_LOCKOUT_HF7              (fc::minutes(1))
#define BEARS_UPVOTE_LOCKOUT_SECONDS          (60*60*12)    /// 12 hours
#define BEARS_UPVOTE_LOCKOUT_HF17             (fc::hours(12))

#define BEARS_MIN_ACCOUNT_CREATION_FEE           1
#define BEARS_MAX_ACCOUNT_CREATION_FEE           int64_t(1000000000)

#define BEARS_OWNER_AUTH_RECOVERY_PERIOD                  fc::days(30)
#define BEARS_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD  fc::days(1)
#define BEARS_OWNER_UPDATE_LIMIT                          fc::minutes(60)
#define BEARS_OWNER_AUTH_HISTORY_TRACKING_START_BLOCK_NUM 0

#define BEARS_INIT_SUPPLY                     (int64_t( 500 ) * int64_t( 1000000 ) * int64_t( 1000 ))

#endif

#define COINS_SYMBOL  (bears::protocol::asset_symbol_type::from_asset_num( BEARS_ASSET_NUM_COINS ) )
#define BEARS_SYMBOL  (bears::protocol::asset_symbol_type::from_asset_num( BEARS_ASSET_NUM_BEARS ) )
#define BSD_SYMBOL    (bears::protocol::asset_symbol_type::from_asset_num( BEARS_ASSET_NUM_BSD ) )

#define BEARS_BLOCKCHAIN_HARDFORK_VERSION     ( hardfork_version( BEARS_BLOCKCHAIN_VERSION ) )

#define BEARS_BLOCK_INTERVAL                  3
#define BEARS_BLOCKS_PER_YEAR                 (365*24*60*60/BEARS_BLOCK_INTERVAL)
#define BEARS_BLOCKS_PER_DAY                  (24*60*60/BEARS_BLOCK_INTERVAL)
#define BEARS_START_COINING_BLOCK             (BEARS_BLOCKS_PER_DAY * 7)
#define BEARS_INFLATION_NUMBER                0    

#define BEARS_START_MINER_VOTING_BLOCK        (BEARS_BLOCKS_PER_DAY * 30)

#define BEARS_INIT_MINER_NAME                 "bearshare"
#define BEARS_NUM_INIT_MINERS                 1
#define BEARS_INIT_TIME                       (fc::time_point_sec());

#define BEARS_MAX_WITNESSES                   21

#define BEARS_MAX_VOTED_WITNESSES_HF0         19
#define BEARS_MAX_MINER_WITNESSES_HF0         1
#define BEARS_MAX_RUNNER_WITNESSES_HF0        1

#define BEARS_MAX_VOTED_WITNESSES_HF17        20
#define BEARS_MAX_MINER_WITNESSES_HF17        0
#define BEARS_MAX_RUNNER_WITNESSES_HF17       1

#define BEARS_HARDFORK_REQUIRED_WITNESSES     17 // 17 of the 21 dpos witnesses (20 elected and 1 virtual time) required for hardfork. This guarantees 75% participation on all subsequent rounds.
#define BEARS_MAX_TIME_UNTIL_EXPIRATION       (60*60) // seconds,  aka: 1 hour
#define BEARS_MAX_MEMO_SIZE                   2048
#define BEARS_MAX_PROXY_RECURSION_DEPTH       4
#define BEARS_COINING_WITHDRAW_INTERVALS_PRE_HF_16 104
#define BEARS_COINING_WITHDRAW_INTERVALS      13
#define BEARS_COINING_WITHDRAW_INTERVAL_SECONDS (60*60*24*7) /// 1 week per interval
#define BEARS_MAX_WITHDRAW_ROUTES             10
#define BEARS_SAVINGS_WITHDRAW_TIME        	(fc::days(3))
#define BEARS_SAVINGS_WITHDRAW_REQUEST_LIMIT  100
#define BEARS_VOTING_MANA_REGENERATION_SECONDS (5*60*60*24) // 5 day
#define BEARS_MAX_VOTE_CHANGES                5
#define BEARS_REVERSE_AUCTION_WINDOW_SECONDS_HF6 (60*30) /// 30 minutes
#define BEARS_REVERSE_AUCTION_WINDOW_SECONDS_HF20 (60*15) /// 15 minutes
#define BEARS_MIN_VOTE_INTERVAL_SEC           3
#define BEARS_VOTE_DUST_THRESHOLD             (2500)

#define BEARS_MIN_ROOT_COMMENT_INTERVAL       (fc::seconds(60*5)) // 5 minutes
#define BEARS_MIN_REPLY_INTERVAL              (fc::seconds(20)) // 20 seconds
#define BEARS_MIN_REPLY_INTERVAL_HF20         (fc::seconds(3)) // 3 seconds
#define BEARS_POST_AVERAGE_WINDOW             (60*60*24u) // 1 day
#define BEARS_POST_WEIGHT_CONSTANT            (uint64_t(4*BEARS_100_PERCENT) * (4*BEARS_100_PERCENT))// (4*BEARS_100_PERCENT) -> 2 posts per 1 days, average 1 every 12 hours

#define BEARS_MAX_ACCOUNT_WITNESS_VOTES       30

#define BEARS_100_PERCENT                     10000
#define BEARS_1_PERCENT                       (BEARS_100_PERCENT/100)
#define BEARS_DEFAULT_BSD_INTEREST_RATE       (10*BEARS_1_PERCENT) ///< 10% APR

#define BEARS_INFLATION_RATE_START_PERCENT    (978) // Fixes block 7,000,000 to 9.5%
#define BEARS_INFLATION_RATE_STOP_PERCENT     (95) // 0.95%
#define BEARS_INFLATION_NARROWING_PERIOD      (250000) // Narrow 0.01% every 250k blocks
#define BEARS_CONTENT_REWARD_PERCENT          (75*BEARS_1_PERCENT) //75% of inflation, 7.125% inflation
#define BEARS_COINING_FUND_PERCENT            (15*BEARS_1_PERCENT) //15% of inflation, 1.425% inflation

#define BEARS_MINER_PAY_PERCENT               (BEARS_1_PERCENT) // 1%
#define BEARS_MAX_RATION_DECAY_RATE           (1000000)

#define BEARS_BANDWIDTH_AVERAGE_WINDOW_SECONDS (60*60*24*7) ///< 1 week
#define BEARS_BANDWIDTH_PRECISION             (uint64_t(1000000)) ///< 1 million
#define BEARS_MAX_COMMENT_DEPTH_PRE_HF17      6
#define BEARS_MAX_COMMENT_DEPTH               0xffff // 64k
#define BEARS_SOFT_MAX_COMMENT_DEPTH          0xff // 255

#define BEARS_MAX_RESERVE_RATIO               (20000)

#define BEARS_CREATE_ACCOUNT_WITH_BEARS_MODIFIER 1
#define BEARS_CREATE_ACCOUNT_DELEGATION_RATIO    5
#define BEARS_CREATE_ACCOUNT_DELEGATION_TIME     fc::days(30)

#define BEARS_MINING_REWARD                   asset( 1000, BEARS_SYMBOL )
#define BEARS_EQUIHASH_N                      140
#define BEARS_EQUIHASH_K                      6

#define BEARS_LIQUIDITY_TIMEOUT_SEC           (fc::seconds(60*60*24*7)) // After one week volume is set to 0
#define BEARS_MIN_LIQUIDITY_REWARD_PERIOD_SEC (fc::seconds(60)) // 1 minute required on books to receive volume
#define BEARS_LIQUIDITY_REWARD_PERIOD_SEC     (60*60)
#define BEARS_LIQUIDITY_REWARD_BLOCKS         (BEARS_LIQUIDITY_REWARD_PERIOD_SEC/BEARS_BLOCK_INTERVAL)
#define BEARS_MIN_LIQUIDITY_REWARD            (asset( 1000*BEARS_LIQUIDITY_REWARD_BLOCKS, BEARS_SYMBOL )) // Minumum reward to be paid out to liquidity providers
#define BEARS_MIN_CONTENT_REWARD              BEARS_MINING_REWARD
#define BEARS_MIN_CURATE_REWARD               BEARS_MINING_REWARD
#define BEARS_MIN_PRODUCER_REWARD             BEARS_MINING_REWARD
#define BEARS_MIN_POW_REWARD                  BEARS_MINING_REWARD

#define BEARS_ACTIVE_CHALLENGE_FEE            asset( 2000, BEARS_SYMBOL )
#define BEARS_OWNER_CHALLENGE_FEE             asset( 30000, BEARS_SYMBOL )
#define BEARS_ACTIVE_CHALLENGE_COOLDOWN       fc::days(1)
#define BEARS_OWNER_CHALLENGE_COOLDOWN        fc::days(1)

#define BEARS_POST_REWARD_FUND_NAME           ("post")
#define BEARS_COMMENT_REWARD_FUND_NAME        ("comment")
#define BEARS_RECENT_RSHARES_DECAY_TIME_HF17    (fc::days(30))
#define BEARS_RECENT_RSHARES_DECAY_TIME_HF19    (fc::days(15))
#define BEARS_CONTENT_CONSTANT_HF0            (uint128_t(uint64_t(2000000000000ll)))
// note, if redefining these constants make sure calculate_claims doesn't overflow

// 5ccc e802 de5f
// int(expm1( log1p( 1 ) / BLOCKS_PER_YEAR ) * 2**BEARS_APR_PERCENT_SHIFT_PER_BLOCK / 100000 + 0.5)
// we use 100000 here instead of 10000 because we end up creating an additional 9x for coining
#define BEARS_APR_PERCENT_MULTIPLY_PER_BLOCK          ( (uint64_t( 0x5ccc ) << 0x20) \
                                                        | (uint64_t( 0xe802 ) << 0x10) \
                                                        | (uint64_t( 0xde5f )        ) \
                                                        )
// chosen to be the maximal value such that BEARS_APR_PERCENT_MULTIPLY_PER_BLOCK * 2**64 * 100000 < 2**128
#define BEARS_APR_PERCENT_SHIFT_PER_BLOCK             87

#define BEARS_APR_PERCENT_MULTIPLY_PER_ROUND          ( (uint64_t( 0x79cc ) << 0x20 ) \
                                                        | (uint64_t( 0xf5c7 ) << 0x10 ) \
                                                        | (uint64_t( 0x3480 )         ) \
                                                        )

#define BEARS_APR_PERCENT_SHIFT_PER_ROUND             83

// We have different constants for hourly rewards
// i.e. hex(int(math.expm1( math.log1p( 1 ) / HOURS_PER_YEAR ) * 2**BEARS_APR_PERCENT_SHIFT_PER_HOUR / 100000 + 0.5))
#define BEARS_APR_PERCENT_MULTIPLY_PER_HOUR           ( (uint64_t( 0x6cc1 ) << 0x20) \
                                                        | (uint64_t( 0x39a1 ) << 0x10) \
                                                        | (uint64_t( 0x5cbd )        ) \
                                                        )

// chosen to be the maximal value such that BEARS_APR_PERCENT_MULTIPLY_PER_HOUR * 2**64 * 100000 < 2**128
#define BEARS_APR_PERCENT_SHIFT_PER_HOUR              77

// These constants add up to GRAPHENE_100_PERCENT.  Each GRAPHENE_1_PERCENT is equivalent to 1% per year APY
// *including the corresponding 9x coining rewards*
#define BEARS_CURATE_APR_PERCENT              3875
#define BEARS_CONTENT_APR_PERCENT             3875
#define BEARS_LIQUIDITY_APR_PERCENT            750
#define BEARS_PRODUCER_APR_PERCENT             750
#define BEARS_POW_APR_PERCENT                  750

#define BEARS_MIN_PAYOUT_BSD                  (asset(20,BSD_SYMBOL))

#define BEARS_BSD_STOP_PERCENT_HF14           (5*BEARS_1_PERCENT ) // Stop printing BSD at 5% Market Cap
#define BEARS_BSD_STOP_PERCENT_HF20           (10*BEARS_1_PERCENT ) // Stop printing BSD at 10% Market Cap
#define BEARS_BSD_START_PERCENT_HF14          (2*BEARS_1_PERCENT) // Start reducing printing of BSD at 2% Market Cap
#define BEARS_BSD_START_PERCENT_HF20          (9*BEARS_1_PERCENT) // Start reducing printing of BSD at 9% Market Cap

#define BEARS_MIN_ACCOUNT_NAME_LENGTH          3
#define BEARS_MAX_ACCOUNT_NAME_LENGTH         16

#define BEARS_MIN_PERMLINK_LENGTH             0
#define BEARS_MAX_PERMLINK_LENGTH             256
#define BEARS_MAX_WITNESS_URL_LENGTH          2048

#define BEARS_MAX_SHARE_SUPPLY                int64_t(1000000000000000ll)
#define BEARS_MAX_SATOSHIS                    int64_t(4611686018427387903ll)
#define BEARS_MAX_SIG_CHECK_DEPTH             2
#define BEARS_MAX_SIG_CHECK_ACCOUNTS          125

#define BEARS_MIN_TRANSACTION_SIZE_LIMIT      1024
#define BEARS_SECONDS_PER_YEAR                (uint64_t(60*60*24*365ll))

#define BEARS_BSD_INTEREST_COMPOUND_INTERVAL_SEC  (60*60*24*30)
#define BEARS_MAX_TRANSACTION_SIZE            (1024*64)
#define BEARS_MIN_BLOCK_SIZE_LIMIT            (BEARS_MAX_TRANSACTION_SIZE)
#define BEARS_MAX_BLOCK_SIZE                  (BEARS_MAX_TRANSACTION_SIZE*BEARS_BLOCK_INTERVAL*2000)
#define BEARS_SOFT_MAX_BLOCK_SIZE             (2*1024*1024)
#define BEARS_MIN_BLOCK_SIZE                  115
#define BEARS_BLOCKS_PER_HOUR                 (60*60/BEARS_BLOCK_INTERVAL)
#define BEARS_FEED_INTERVAL_BLOCKS            (BEARS_BLOCKS_PER_HOUR/6) // 200 
#define BEARS_FEED_HISTORY_WINDOW_PRE_HF_16   (24*7) /// 7 days * 24 hours per day
#define BEARS_FEED_HISTORY_WINDOW             (12*7) // 3.5 days
#define BEARS_MAX_FEED_AGE_SECONDS            (60*60*1) // 1 hour
#define BEARS_MIN_FEEDS                       (BEARS_MAX_WITNESSES/3) /// 7 Witnesses to publish feed..  protects the network from conversions before price has been established
#define BEARS_CONVERSION_DELAY_PRE_HF_16      (fc::days(7))
#define BEARS_CONVERSION_DELAY                (fc::hours(BEARS_FEED_HISTORY_WINDOW)) //3.5 day conversion

#define BEARS_MIN_UNDO_HISTORY                10
#define BEARS_MAX_UNDO_HISTORY                10000

#define BEARS_MIN_TRANSACTION_EXPIRATION_LIMIT (BEARS_BLOCK_INTERVAL * 5) // 5 transactions per block
#define BEARS_BLOCKCHAIN_PRECISION            uint64_t( 1000 )

#define BEARS_BLOCKCHAIN_PRECISION_DIGITS     3
#define BEARS_MAX_INSTANCE_ID                 (uint64_t(-1)>>16)
/** NOTE: making this a power of 2 (say 2^15) would greatly accelerate fee calcs */
#define BEARS_MAX_AUTHORITY_MEMBERSHIP        40
#define BEARS_MAX_ASSET_WHITELIST_AUTHORITIES 10
#define BEARS_MAX_URL_LENGTH                  127

#define BEARS_IRREVERSIBLE_THRESHOLD          (75 * BEARS_1_PERCENT)

#define BEARS_VIRTUAL_SCHEDULE_LAP_LENGTH  ( fc::uint128(uint64_t(-1)) )
#define BEARS_VIRTUAL_SCHEDULE_LAP_LENGTH2 ( fc::uint128::max_value() )

#define BEARS_INITIAL_VOTE_POWER_RATE (40)
#define BEARS_REDUCED_VOTE_POWER_RATE (10)

#define BEARS_MAX_LIMIT_ORDER_EXPIRATION     (60*60*24*28) // 28 days
#define BEARS_DELEGATION_RETURN_PERIOD_HF0   (BEARS_CASHOUT_WINDOW_SECONDS)
#define BEARS_DELEGATION_RETURN_PERIOD_HF20  (BEARS_VOTING_MANA_REGENERATION_SECONDS)

#define BEARS_RD_MIN_DECAY_BITS               6
#define BEARS_RD_MAX_DECAY_BITS              32
#define BEARS_RD_DECAY_DENOM_SHIFT           36
#define BEARS_RD_MAX_POOL_BITS               64
#define BEARS_RD_MAX_BUDGET_1                ((uint64_t(1) << (BEARS_RD_MAX_POOL_BITS + BEARS_RD_MIN_DECAY_BITS - BEARS_RD_DECAY_DENOM_SHIFT))-1)
#define BEARS_RD_MAX_BUDGET_2                ((uint64_t(1) << (64-BEARS_RD_DECAY_DENOM_SHIFT))-1)
#define BEARS_RD_MAX_BUDGET_3                (uint64_t( std::numeric_limits<int32_t>::max() ))
#define BEARS_RD_MAX_BUDGET                  (int32_t( std::min( { BEARS_RD_MAX_BUDGET_1, BEARS_RD_MAX_BUDGET_2, BEARS_RD_MAX_BUDGET_3 } )) )
#define BEARS_RD_MIN_DECAY                   (uint32_t(1) << BEARS_RD_MIN_DECAY_BITS)
#define BEARS_RD_MIN_BUDGET                  1
#define BEARS_RD_MAX_DECAY                   (uint32_t(0xFFFFFFFF))

#define BEARS_ACCOUNT_SUBSIDY_PRECISION      (BEARS_100_PERCENT)

// We want the global subsidy to run out first in normal (Poisson)
// conditions, so we boost the per-witness subsidy a little.
#define BEARS_WITNESS_SUBSIDY_BUDGET_PERCENT (125 * BEARS_1_PERCENT)

// Since witness decay only procs once per round, multiplying the decay
// constant by the number of witnesses means the per-witness pools have
// the same effective decay rate in real-time terms.
#define BEARS_WITNESS_SUBSIDY_DECAY_PERCENT  (BEARS_MAX_WITNESSES * BEARS_100_PERCENT)

// 347321 corresponds to a 5-day halflife
#define BEARS_DEFAULT_ACCOUNT_SUBSIDY_DECAY  (347321)
// Default rate is 0.5 accounts per block
#define BEARS_DEFAULT_ACCOUNT_SUBSIDY_BUDGET (797)
#define BEARS_DECAY_BACKSTOP_PERCENT         (90 * BEARS_1_PERCENT)

/**
 *  Reserved Account IDs with special meaning
 */
///@{
/// Represents the current witnesses
#define BEARS_MINER_ACCOUNT                   "miners"
/// Represents the canonical account with NO authority (nobody can access funds in null account)
#define BEARS_NULL_ACCOUNT                    "null"
/// Represents the canonical account with WILDCARD authority (anybody can access funds in temp account)
#define BEARS_TEMP_ACCOUNT                    "temp"
/// Represents the canonical account for specifying you will vote for directly (as opposed to a proxy)
#define BEARS_PROXY_TO_SELF_ACCOUNT           ""
/// Represents the canonical root post parent account
#define BEARS_ROOT_POST_PARENT                (account_name_type())
///@}

#ifdef BEARS_ENABLE_SMT

#define SMT_MAX_VOTABLE_ASSETS 2
#define SMT_COINING_WITHDRAW_INTERVAL_SECONDS   (60*60*24*7) /// 1 week per interval
#define SMT_UPVOTE_LOCKOUT                      (60*60*12)  /// 12 hours

#endif /// BEARS_ENABLE_SMT

