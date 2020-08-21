#pragma once
#include <voilk/plugins/witness/witness_plugin.hpp>
#include <voilk/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

#define VOILK_WITNESS_API_PLUGIN_NAME "witness_api"


namespace voilk { namespace plugins { namespace witness {

using namespace appbase;

class witness_api_plugin : public appbase::plugin< witness_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (voilk::plugins::witness::witness_plugin)
      (voilk::plugins::json_rpc::json_rpc_plugin)
   )

   witness_api_plugin();
   virtual ~witness_api_plugin();

   static const std::string& name() { static std::string name = VOILK_WITNESS_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;

   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class witness_api > api;
};

} } } // voilk::plugins::witness
