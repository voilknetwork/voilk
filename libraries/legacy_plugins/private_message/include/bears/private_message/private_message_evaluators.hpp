#pragma once

#include <bears/chain/evaluator.hpp>

#include <bears/private_message/private_message_operations.hpp>
#include <bears/private_message/private_message_plugin.hpp>

namespace bears { namespace private_message {

BEARS_DEFINE_PLUGIN_EVALUATOR( private_message_plugin, bears::private_message::private_message_plugin_operation, private_message )

} }
