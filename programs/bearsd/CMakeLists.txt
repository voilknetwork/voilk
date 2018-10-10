add_executable( bearsd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling bearsd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( BEARS_STATIC_BUILD )
   target_link_libraries( bearsd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      bears_utilities
      bears_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( BEARS_STATIC_BUILD )
   target_link_libraries( bearsd PRIVATE
      appbase
      bears_utilities
      bears_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( BEARS_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      bearsd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   bearsd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
