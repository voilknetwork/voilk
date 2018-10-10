#pragma once
#include <bears/protocol/base.hpp>

#include <bears/chain/evaluator.hpp>


namespace bears { namespace plugins { namespace follow {

using namespace std;
using bears::protocol::account_name_type;
using bears::protocol::base_operation;

class follow_plugin;

struct follow_operation : base_operation
{
    account_name_type follower;
    account_name_type following;
    set< string >     what; /// blog, mute

    void validate()const;

    void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( follower ); }
};

struct reblog_operation : base_operation
{
   account_name_type account;
   account_name_type author;
   string            permlink;

   void validate()const;

   void get_required_posting_authorities( flat_set<account_name_type>& a )const { a.insert( account ); }
};

typedef fc::static_variant<
         follow_operation,
         reblog_operation
      > follow_plugin_operation;

BEARS_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, follow );
BEARS_DEFINE_PLUGIN_EVALUATOR( follow_plugin, follow_plugin_operation, reblog );

} } } // bears::plugins::follow

FC_REFLECT( bears::plugins::follow::follow_operation, (follower)(following)(what) )
FC_REFLECT( bears::plugins::follow::reblog_operation, (account)(author)(permlink) )

BEARS_DECLARE_OPERATION_TYPE( bears::plugins::follow::follow_plugin_operation )

FC_REFLECT_TYPENAME( bears::plugins::follow::follow_plugin_operation )
