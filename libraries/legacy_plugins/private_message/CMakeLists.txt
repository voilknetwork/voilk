file(GLOB HEADERS "include/voilk/private_message/*.hpp")

add_library( voilk_private_message
             private_message_plugin.cpp
           )

target_link_libraries( voilk_private_message voilk_chain voilk_protocol voilk_app )
target_include_directories( voilk_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   voilk_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
