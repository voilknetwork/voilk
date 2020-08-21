#include <voilk/plugins/follow/follow_operations.hpp>

#include <voilk/protocol/operation_util_impl.hpp>

namespace voilk { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //voilk::plugins::follow

VOILK_DEFINE_OPERATION_TYPE( voilk::plugins::follow::follow_plugin_operation )
