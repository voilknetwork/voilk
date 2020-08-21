file(GLOB HEADERS "include/voilk/schema/*.hpp")
add_library( voilk_schema schema.cpp ${HEADERS} )
target_link_libraries( voilk_schema fc )
target_include_directories( voilk_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   voilk_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/voilk/schema" )
