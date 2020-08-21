#pragma once

#include <voilk/chain/evaluator.hpp>

#include <voilk/private_message/private_message_operations.hpp>
#include <voilk/private_message/private_message_plugin.hpp>

namespace voilk { namespace private_message {

VOILK_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, voilk::private_message::private_message_plugin_operation, private_message )

} }
