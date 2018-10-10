file(GLOB HEADERS "include/bears/schema/*.hpp")
add_library( bears_schema schema.cpp ${HEADERS} )
target_link_libraries( bears_schema fc )
target_include_directories( bears_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   bears_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/bears/schema" )
