
add_library( bears_plugins
   mf_plugins.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/include/bears/manifest/plugins.hpp
)

target_link_libraries( bears_plugins appbase fc

   tags_plugin

   webserver_plugin

   statsd_plugin

   account_history_rocksdb_plugin

   debug_node_plugin

   account_by_key_plugin

   stats_export_plugin

   reputation_plugin

   market_history_plugin

   rc_plugin

   account_history_plugin

   follow_plugin

   witness_plugin

   smt_test_plugin

   block_data_export_plugin

   p2p_plugin

   chain_plugin

   account_history_api_plugin

   account_by_key_api_plugin

   condenser_api_plugin

   follow_api_plugin

   debug_node_api_plugin

   witness_api_plugin

   market_history_api_plugin

   chain_api_plugin

   tags_api_plugin

   reputation_api_plugin

   database_api_plugin

   rc_api_plugin

   block_api_plugin

   network_broadcast_api_plugin

   block_log_info_plugin

)

target_include_directories( bears_plugins
   PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
   )

INSTALL( TARGETS
   bears_plugins

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)