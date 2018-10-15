#include <appbase/application.hpp>
#include <boost/preprocessor/seq/for_each.hpp>

#include <bears/manifest/plugins.hpp>


#include <bears/plugins/tags/tags_plugin.hpp>

#include <bears/plugins/webserver/webserver_plugin.hpp>

#include <bears/plugins/statsd/statsd_plugin.hpp>

#include <bears/plugins/account_history_rocksdb/account_history_rocksdb_plugin.hpp>

#include <bears/plugins/debug_node/debug_node_plugin.hpp>

#include <bears/plugins/account_by_key/account_by_key_plugin.hpp>

#include <bears/plugins/stats_export/stats_export_plugin.hpp>

#include <bears/plugins/reputation/reputation_plugin.hpp>

#include <bears/plugins/market_history/market_history_plugin.hpp>

#include <bears/plugins/rc/rc_plugin.hpp>

#include <bears/plugins/account_history/account_history_plugin.hpp>

#include <bears/plugins/follow/follow_plugin.hpp>

#include <bears/plugins/witness/witness_plugin.hpp>

#include <bears/plugins/smt_test/smt_test_plugin.hpp>

#include <bears/plugins/block_data_export/block_data_export_plugin.hpp>

#include <bears/plugins/p2p/p2p_plugin.hpp>

#include <bears/plugins/chain/chain_plugin.hpp>

#include <bears/plugins/account_history_api/account_history_api_plugin.hpp>

#include <bears/plugins/account_by_key_api/account_by_key_api_plugin.hpp>

#include <bears/plugins/condenser_api/condenser_api_plugin.hpp>

#include <bears/plugins/follow_api/follow_api_plugin.hpp>

#include <bears/plugins/debug_node_api/debug_node_api_plugin.hpp>

#include <bears/plugins/witness_api/witness_api_plugin.hpp>

#include <bears/plugins/market_history_api/market_history_api_plugin.hpp>

#include <bears/plugins/chain_api/chain_api_plugin.hpp>

#include <bears/plugins/tags_api/tags_api_plugin.hpp>

#include <bears/plugins/reputation_api/reputation_api_plugin.hpp>

#include <bears/plugins/database_api/database_api_plugin.hpp>

#include <bears/plugins/rc_api/rc_api_plugin.hpp>

#include <bears/plugins/block_api/block_api_plugin.hpp>

#include <bears/plugins/network_broadcast_api/network_broadcast_api_plugin.hpp>

#include <bears/plugins/block_log_info/block_log_info_plugin.hpp>


namespace bears { namespace plugins {

void register_plugins()
{
   
   appbase::app().register_plugin< bears::plugins::tags::tags_plugin >();
   
   appbase::app().register_plugin< bears::plugins::webserver::webserver_plugin >();
   
   appbase::app().register_plugin< bears::plugins::statsd::statsd_plugin >();
   
   appbase::app().register_plugin< bears::plugins::account_history_rocksdb::account_history_rocksdb_plugin >();
   
   appbase::app().register_plugin< bears::plugins::debug_node::debug_node_plugin >();
   
   appbase::app().register_plugin< bears::plugins::account_by_key::account_by_key_plugin >();
   
   appbase::app().register_plugin< bears::plugins::stats_export::stats_export_plugin >();
   
   appbase::app().register_plugin< bears::plugins::reputation::reputation_plugin >();
   
   appbase::app().register_plugin< bears::plugins::market_history::market_history_plugin >();
   
   appbase::app().register_plugin< bears::plugins::rc::rc_plugin >();
   
   appbase::app().register_plugin< bears::plugins::account_history::account_history_plugin >();
   
   appbase::app().register_plugin< bears::plugins::follow::follow_plugin >();
   
   appbase::app().register_plugin< bears::plugins::witness::witness_plugin >();
   
   appbase::app().register_plugin< bears::plugins::smt_test::smt_test_plugin >();
   
   appbase::app().register_plugin< bears::plugins::block_data_export::block_data_export_plugin >();
   
   appbase::app().register_plugin< bears::plugins::p2p::p2p_plugin >();
   
   appbase::app().register_plugin< bears::plugins::chain::chain_plugin >();
   
   appbase::app().register_plugin< bears::plugins::account_history::account_history_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::account_by_key::account_by_key_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::condenser_api::condenser_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::follow::follow_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::debug_node::debug_node_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::witness::witness_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::market_history::market_history_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::chain::chain_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::tags::tags_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::reputation::reputation_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::database_api::database_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::rc::rc_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::block_api::block_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::network_broadcast_api::network_broadcast_api_plugin >();
   
   appbase::app().register_plugin< bears::plugins::block_log_info::block_log_info_plugin >();
   
}

} }