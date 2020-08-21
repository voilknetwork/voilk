file(GLOB HEADERS "include/voilk/delayed_node/*.hpp")

add_library( voilk_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( voilk_delayed_node voilk_chain voilk_protocol voilk_app )
target_include_directories( voilk_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   voilk_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
