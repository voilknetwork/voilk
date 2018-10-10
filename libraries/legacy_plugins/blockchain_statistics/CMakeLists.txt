file(GLOB HEADERS "include/bears/blockchain_statistics/*.hpp")

add_library( bears_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( bears_blockchain_statistics bears_chain bears_protocol bears_app )
target_include_directories( bears_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   bears_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)