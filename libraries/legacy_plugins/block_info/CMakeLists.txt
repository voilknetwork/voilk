file(GLOB HEADERS "include/voilk/plugins/block_info/*.hpp")

add_library( voilk_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( voilk_block_info voilk_app voilk_chain voilk_protocol fc )
target_include_directories( voilk_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
