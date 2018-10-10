file(GLOB HEADERS "include/bears/private_message/*.hpp")

add_library( bears_private_message
             private_message_plugin.cpp
           )

target_link_libraries( bears_private_message bears_chain bears_protocol bears_app )
target_include_directories( bears_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   bears_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
