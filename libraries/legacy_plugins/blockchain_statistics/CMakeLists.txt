file(GLOB HEADERS "include/voilk/blockchain_statistics/*.hpp")

add_library( voilk_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( voilk_blockchain_statistics voilk_chain voilk_protocol voilk_app )
target_include_directories( voilk_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   voilk_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)