#pragma once
#include <voilk/plugins/json_rpc/json_rpc_plugin.hpp>
#include <voilk/plugins/chain/chain_plugin.hpp>
#include <voilk/plugins/p2p/p2p_plugin.hpp>
#include <voilk/plugins/rc/rc_plugin.hpp>

#include <appbase/application.hpp>

#define VOILK_NETWORK_BROADCAST_API_PLUGIN_NAME "network_broadcast_api"

namespace voilk { namespace plugins { namespace network_broadcast_api {

using namespace appbase;

class network_broadcast_api_plugin : public appbase::plugin< network_broadcast_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (voilk::plugins::json_rpc::json_rpc_plugin)
      (voilk::plugins::rc::rc_plugin)
      (voilk::plugins::chain::chain_plugin)
      (voilk::plugins::p2p::p2p_plugin)
   )

   network_broadcast_api_plugin();
   virtual ~network_broadcast_api_plugin();

   static const std::string& name() { static std::string name = VOILK_NETWORK_BROADCAST_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;
   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class network_broadcast_api > api;
};

} } } // voilk::plugins::network_broadcast_api
