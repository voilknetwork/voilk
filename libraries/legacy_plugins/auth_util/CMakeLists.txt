file(GLOB HEADERS "include/bears/plugins/auth_util/*.hpp")

add_library( bears_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( bears_auth_util bears_app bears_chain bears_protocol fc )
target_include_directories( bears_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
