#include <bears/plugins/follow/follow_operations.hpp>

#include <bears/protocol/operation_util_impl.hpp>

namespace bears { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //bears::plugins::follow

BEARS_DEFINE_OPERATION_TYPE( bears::plugins::follow::follow_plugin_operation )
