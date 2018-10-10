#pragma once

#include <bears/protocol/bears_required_actions.hpp>

#include <bears/protocol/operation_util.hpp>

namespace bears { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            required_action
         > required_automated_action;

} } // bears::protocol

BEARS_DECLARE_OPERATION_TYPE( bears::protocol::required_automated_action );
FC_REFLECT_TYPENAME( bears::protocol::required_automated_action );
