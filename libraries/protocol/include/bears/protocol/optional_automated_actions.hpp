#pragma once

#include <bears/protocol/bears_optional_actions.hpp>

#include <bears/protocol/operation_util.hpp>

namespace bears { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            optional_action
         > optional_automated_action;

} } // bears::protocol

BEARS_DECLARE_OPERATION_TYPE( bears::protocol::optional_automated_action );
FC_REFLECT_TYPENAME( bears::protocol::optional_automated_action );
