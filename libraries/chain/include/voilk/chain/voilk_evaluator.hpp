#pragma once

#include <voilk/protocol/voilk_operations.hpp>

#include <voilk/chain/evaluator.hpp>

namespace voilk { namespace chain {

using namespace voilk::protocol;

VOILK_DEFINE_EVALUATOR( account_create )
VOILK_DEFINE_EVALUATOR( account_create_with_delegation )
VOILK_DEFINE_EVALUATOR( account_update )
VOILK_DEFINE_EVALUATOR( transfer )
VOILK_DEFINE_EVALUATOR( issue_vsd )
VOILK_DEFINE_EVALUATOR( transfer_to_coining )
VOILK_DEFINE_EVALUATOR( witness_update )
VOILK_DEFINE_EVALUATOR( account_witness_vote )
VOILK_DEFINE_EVALUATOR( account_witness_proxy )
VOILK_DEFINE_EVALUATOR( withdraw_coining )
VOILK_DEFINE_EVALUATOR( set_withdraw_coining_route )
VOILK_DEFINE_EVALUATOR( comment )
VOILK_DEFINE_EVALUATOR( comment_options )
VOILK_DEFINE_EVALUATOR( delete_comment )
VOILK_DEFINE_EVALUATOR( vote )
VOILK_DEFINE_EVALUATOR( custom )
VOILK_DEFINE_EVALUATOR( custom_json )
VOILK_DEFINE_EVALUATOR( custom_binary )
VOILK_DEFINE_EVALUATOR( pow )
VOILK_DEFINE_EVALUATOR( pow2 )
VOILK_DEFINE_EVALUATOR( feed_publish )
VOILK_DEFINE_EVALUATOR( convert )
VOILK_DEFINE_EVALUATOR( limit_order_create )
VOILK_DEFINE_EVALUATOR( limit_order_cancel )
VOILK_DEFINE_EVALUATOR( report_over_production )
VOILK_DEFINE_EVALUATOR( limit_order_create2 )
VOILK_DEFINE_EVALUATOR( escrow_transfer )
VOILK_DEFINE_EVALUATOR( escrow_approve )
VOILK_DEFINE_EVALUATOR( escrow_dispute )
VOILK_DEFINE_EVALUATOR( escrow_release )
VOILK_DEFINE_EVALUATOR( claim_account )
VOILK_DEFINE_EVALUATOR( create_claimed_account )
VOILK_DEFINE_EVALUATOR( request_account_recovery )
VOILK_DEFINE_EVALUATOR( recover_account )
VOILK_DEFINE_EVALUATOR( change_recovery_account )
VOILK_DEFINE_EVALUATOR( transfer_to_savings )
VOILK_DEFINE_EVALUATOR( transfer_from_savings )
VOILK_DEFINE_EVALUATOR( cancel_transfer_from_savings )
VOILK_DEFINE_EVALUATOR( decline_voting_rights )
VOILK_DEFINE_EVALUATOR( reset_account )
VOILK_DEFINE_EVALUATOR( set_reset_account )
VOILK_DEFINE_EVALUATOR( claim_reward_balance )
#ifdef VOILK_ENABLE_SMT
VOILK_DEFINE_EVALUATOR( claim_reward_balance2 )
#endif
VOILK_DEFINE_EVALUATOR( delegate_coining_shares )
VOILK_DEFINE_EVALUATOR( witness_set_properties )
#ifdef VOILK_ENABLE_SMT
VOILK_DEFINE_EVALUATOR( smt_setup )
VOILK_DEFINE_EVALUATOR( smt_cap_reveal )
VOILK_DEFINE_EVALUATOR( smt_refund )
VOILK_DEFINE_EVALUATOR( smt_setup_emissions )
VOILK_DEFINE_EVALUATOR( smt_set_setup_parameters )
VOILK_DEFINE_EVALUATOR( smt_set_runtime_parameters )
VOILK_DEFINE_EVALUATOR( smt_create )
#endif

} } // voilk::chain
