#pragma once

#include <bears/protocol/bears_operations.hpp>

#include <bears/chain/evaluator.hpp>

namespace bears { namespace chain {

using namespace bears::protocol;

BEARS_DEFINE_EVALUATOR( account_create )
BEARS_DEFINE_EVALUATOR( account_create_with_delegation )
BEARS_DEFINE_EVALUATOR( account_update )
BEARS_DEFINE_EVALUATOR( transfer )
BEARS_DEFINE_EVALUATOR( transfer_to_coining )
BEARS_DEFINE_EVALUATOR( witness_update )
BEARS_DEFINE_EVALUATOR( account_witness_vote )
BEARS_DEFINE_EVALUATOR( account_witness_proxy )
BEARS_DEFINE_EVALUATOR( withdraw_coining )
BEARS_DEFINE_EVALUATOR( set_withdraw_coining_route )
BEARS_DEFINE_EVALUATOR( comment )
BEARS_DEFINE_EVALUATOR( comment_options )
BEARS_DEFINE_EVALUATOR( delete_comment )
BEARS_DEFINE_EVALUATOR( vote )
BEARS_DEFINE_EVALUATOR( custom )
BEARS_DEFINE_EVALUATOR( custom_json )
BEARS_DEFINE_EVALUATOR( custom_binary )
BEARS_DEFINE_EVALUATOR( pow )
BEARS_DEFINE_EVALUATOR( pow2 )
BEARS_DEFINE_EVALUATOR( feed_publish )
BEARS_DEFINE_EVALUATOR( convert )
BEARS_DEFINE_EVALUATOR( limit_order_create )
BEARS_DEFINE_EVALUATOR( limit_order_cancel )
BEARS_DEFINE_EVALUATOR( report_over_production )
BEARS_DEFINE_EVALUATOR( limit_order_create2 )
BEARS_DEFINE_EVALUATOR( escrow_transfer )
BEARS_DEFINE_EVALUATOR( escrow_approve )
BEARS_DEFINE_EVALUATOR( escrow_dispute )
BEARS_DEFINE_EVALUATOR( escrow_release )
BEARS_DEFINE_EVALUATOR( claim_account )
BEARS_DEFINE_EVALUATOR( create_claimed_account )
BEARS_DEFINE_EVALUATOR( request_account_recovery )
BEARS_DEFINE_EVALUATOR( recover_account )
BEARS_DEFINE_EVALUATOR( change_recovery_account )
BEARS_DEFINE_EVALUATOR( transfer_to_savings )
BEARS_DEFINE_EVALUATOR( transfer_from_savings )
BEARS_DEFINE_EVALUATOR( cancel_transfer_from_savings )
BEARS_DEFINE_EVALUATOR( decline_voting_rights )
BEARS_DEFINE_EVALUATOR( reset_account )
BEARS_DEFINE_EVALUATOR( set_reset_account )
BEARS_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef BEARS_ENABLE_SMT
BEARS_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
BEARS_DEFINE_EVALUATOR( delegate_coining_shares )
BEARS_DEFINE_EVALUATOR( witness_set_properties )
#ifdef BEARS_ENABLE_SMT
BEARS_DEFINE_EVALUATOR( smt_setup )
BEARS_DEFINE_EVALUATOR( smt_cap_reveal )
BEARS_DEFINE_EVALUATOR( smt_refund )
BEARS_DEFINE_EVALUATOR( smt_setup_emissions )
BEARS_DEFINE_EVALUATOR( smt_set_setup_parameters )
BEARS_DEFINE_EVALUATOR( smt_set_runtime_parameters )
BEARS_DEFINE_EVALUATOR( smt_create )
#endif

} } // bears::chain
