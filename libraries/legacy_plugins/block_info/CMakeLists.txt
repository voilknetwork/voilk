file(GLOB HEADERS "include/bears/plugins/block_info/*.hpp")

add_library( bears_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( bears_block_info bears_app bears_chain bears_protocol fc )
target_include_directories( bears_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
