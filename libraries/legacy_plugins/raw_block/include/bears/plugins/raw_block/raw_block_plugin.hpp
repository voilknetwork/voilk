
#pragma once

#include <bears/app/plugin.hpp>

namespace bears { namespace plugin { namespace raw_block {

using bears::app::application;

class raw_block_plugin : public bears::app::plugin
{
   public:
      raw_block_plugin( application* app );
      virtual ~raw_block_plugin();

      virtual std::string plugin_name()const override;
      virtual void plugin_initialize( const boost::program_options::variables_map& options ) override;
      virtual void plugin_startup() override;
      virtual void plugin_shutdown() override;
};

} } }
