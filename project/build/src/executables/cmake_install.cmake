# Install script for directory: C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/src/executables

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/CppPractices")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/1_BasicDArray/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/2_EfficientDArray/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/3_TemplateDArray/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/4_list_Polynomial/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/5_map_Polynomial/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/86151/Desktop/计算机图形学/USTC_CG_25-main/USTC_CG_25-main/Homeworks/0_cpp_warmup/project/build/src/executables/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
