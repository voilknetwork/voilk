file(GLOB HEADERS "include/bears/delayed_node/*.hpp")

add_library( bears_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( bears_delayed_node bears_chain bears_protocol bears_app )
target_include_directories( bears_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   bears_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
