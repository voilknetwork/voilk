file(GLOB HEADERS "include/voilk/plugins/auth_util/*.hpp")

add_library( voilk_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( voilk_auth_util voilk_app voilk_chain voilk_protocol fc )
target_include_directories( voilk_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
