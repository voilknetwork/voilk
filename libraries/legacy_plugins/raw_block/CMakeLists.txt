file(GLOB HEADERS "include/voilk/plugins/raw_block/*.hpp")

add_library( voilk_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( voilk_raw_block voilk_app voilk_chain voilk_protocol fc )
target_include_directories( voilk_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
