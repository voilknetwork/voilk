#pragma once
#include <bears/plugins/tags/tags_plugin.hpp>
#include <bears/plugins/json_rpc/json_rpc_plugin.hpp>

#include <appbase/application.hpp>

#define BEARS_TAGS_API_PLUGIN_NAME "tags_api"


namespace bears { namespace plugins { namespace tags {

using namespace appbase;

class tags_api_plugin : public appbase::plugin< tags_api_plugin >
{
public:
   APPBASE_PLUGIN_REQUIRES(
      (bears::plugins::tags::tags_plugin)
      (bears::plugins::json_rpc::json_rpc_plugin)
   )

   tags_api_plugin();
   virtual ~tags_api_plugin();

   static const std::string& name() { static std::string name = BEARS_TAGS_API_PLUGIN_NAME; return name; }

   virtual void set_program_options( options_description& cli, options_description& cfg ) override;

   virtual void plugin_initialize( const variables_map& options ) override;
   virtual void plugin_startup() override;
   virtual void plugin_shutdown() override;

   std::shared_ptr< class tags_api > api;
};

} } } // bears::plugins::tags
