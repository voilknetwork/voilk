#pragma once

#include <voilk/protocol/voilk_required_actions.hpp>

#include <voilk/protocol/operation_util.hpp>

namespace voilk { namespace protocol {

   /** NOTE: do not change the order of any actions or it will trigger a hardfork.
    */
   typedef fc::static_variant<
            required_action
         > required_automated_action;

} } // voilk::protocol

VOILK_DECLARE_OPERATION_TYPE( voilk::protocol::required_automated_action );
FC_REFLECT_TYPENAME( voilk::protocol::required_automated_action );
