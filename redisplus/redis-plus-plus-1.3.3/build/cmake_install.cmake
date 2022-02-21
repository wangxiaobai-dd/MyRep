# Install script for directory: /home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/libredis++.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1.3.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/libredis++.so.1.3.3"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/libredis++.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1.3.3"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/usr/local/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/libredis++.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so"
         OLD_RPATH "/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libredis++.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake"
         "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cmake/redis++/redis++-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/CMakeFiles/Export/share/cmake/redis++/redis++-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/sw/redis++/cmd_formatter.h;/usr/local/include/sw/redis++/command.h;/usr/local/include/sw/redis++/command_args.h;/usr/local/include/sw/redis++/command_options.h;/usr/local/include/sw/redis++/connection.h;/usr/local/include/sw/redis++/connection_pool.h;/usr/local/include/sw/redis++/cxx_utils.h;/usr/local/include/sw/redis++/errors.h;/usr/local/include/sw/redis++/tls.h;/usr/local/include/sw/redis++/pipeline.h;/usr/local/include/sw/redis++/queued_redis.h;/usr/local/include/sw/redis++/queued_redis.hpp;/usr/local/include/sw/redis++/redis++.h;/usr/local/include/sw/redis++/redis.h;/usr/local/include/sw/redis++/redis.hpp;/usr/local/include/sw/redis++/redis_cluster.h;/usr/local/include/sw/redis++/redis_cluster.hpp;/usr/local/include/sw/redis++/reply.h;/usr/local/include/sw/redis++/sentinel.h;/usr/local/include/sw/redis++/shards.h;/usr/local/include/sw/redis++/shards_pool.h;/usr/local/include/sw/redis++/subscriber.h;/usr/local/include/sw/redis++/transaction.h;/usr/local/include/sw/redis++/utils.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include/sw/redis++" TYPE FILE FILES
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/cmd_formatter.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/command.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/command_args.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/command_options.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/connection.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/connection_pool.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/cxx17/cxx_utils.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/errors.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/no_tls/tls.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/pipeline.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/queued_redis.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/queued_redis.hpp"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/redis++.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/redis.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/redis.hpp"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/redis_cluster.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/redis_cluster.hpp"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/reply.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/sentinel.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/shards.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/shards_pool.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/subscriber.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/transaction.h"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/src/sw/redis++/utils.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/redis++" TYPE FILE FILES
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/cmake/redis++-config.cmake"
    "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/cmake/redis++-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/cmake/redis++.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/test/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ubuntu/MyRep/redisplus/redis-plus-plus-1.3.3/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
