add_executable( voilkd main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling voilkd with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( VOILK_STATIC_BUILD )
   target_link_libraries( voilkd PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      voilk_utilities
      voilk_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( VOILK_STATIC_BUILD )
   target_link_libraries( voilkd PRIVATE
      appbase
      voilk_utilities
      voilk_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( VOILK_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      voilkd PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   voilkd

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
