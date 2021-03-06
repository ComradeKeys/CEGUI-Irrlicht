cmake_minimum_required(VERSION 2.8.11)
project(gui)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

# State directories for modules and binaries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#Making the compiler as strict as possible
#set(CMAKE_CXX_FLAGS " -std=c++14 -g -pedantic-errors -Werror -Wextra -Wpedantic -Winit-self -Wmissing-declarations -Wuninitialized -Woverloaded-virtual -Wfatal-errors -O3 -Wno-deprecated-declarations")
#add_definitions(${CMAKE_CXX_FLAGS})

#Location of source files
file(GLOB SOURCE src/*.cpp src/*.hpp)

# Locate and require Irrlicht
find_package(Irrlicht REQUIRED)
find_package(CEGUI REQUIRED)

# Specify include directories
include_directories(
  ${IRRLICHT_INCLUDE_DIR}
  ${CEGUI_INCLUDE_DIR}
  )

# Create the binary
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE})

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
  ${IRRLICHT_LIBRARY}
  ${CEGUI_LIBRARIES}
  )
