file(GLOB HEADERS "include/voilk/account_statistics/*.hpp")

add_library( voilk_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( voilk_account_statistics voilk_chain voilk_protocol voilk_app )
target_include_directories( voilk_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   voilk_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)