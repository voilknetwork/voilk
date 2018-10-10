#pragma once
#include <bears/protocol/required_automated_actions.hpp>

#include <bears/chain/bears_object_types.hpp>

#include <boost/multi_index/composite_key.hpp>

namespace bears { namespace chain {

using bears::protocol::required_automated_action;

class pending_required_action_object : public object< pending_required_action_object_type, pending_required_action_object >
{
   pending_required_action_object() = delete;

   public:
      template< typename Constructor, typename Allocator >
      pending_required_action_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      id_type           id;

      required_automated_action  action;
};

typedef multi_index_container<
   pending_required_action_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< pending_required_action_object, pending_required_action_id_type, &pending_required_action_object::id > >
   >,
   allocator< pending_required_action_object >
> pending_required_action_index;

} } //bears::chain

FC_REFLECT( bears::chain::pending_required_action_object,
            (id)(action) )
CHAINBASE_SET_INDEX_TYPE( bears::chain::pending_required_action_object, bears::chain::pending_required_action_index )
