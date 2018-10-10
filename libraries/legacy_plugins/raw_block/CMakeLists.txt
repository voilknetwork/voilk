file(GLOB HEADERS "include/bears/plugins/raw_block/*.hpp")

add_library( bears_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( bears_raw_block bears_app bears_chain bears_protocol fc )
target_include_directories( bears_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
