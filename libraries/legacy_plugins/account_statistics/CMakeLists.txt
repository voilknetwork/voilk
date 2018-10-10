file(GLOB HEADERS "include/bears/account_statistics/*.hpp")

add_library( bears_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( bears_account_statistics bears_chain bears_protocol bears_app )
target_include_directories( bears_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   bears_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)