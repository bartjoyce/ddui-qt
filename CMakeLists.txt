cmake_minimum_required(VERSION 2.8)

project(ddui C CXX)

list(APPEND ddui_ASSETS
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/Entypo.ttf
)
set(ddui_ASSETS ${ddui_ASSETS} PARENT_SCOPE)
set(ddui_MACOSX_BUNDLE ${CMAKE_CURRENT_SOURCE_DIR}/assets/MacOSXBundleInfo.plist.in PARENT_SCOPE)

if (UNIX AND NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

# Qt
if (Qt5_DIR)
  set(Qt5Widgets_DIR "${Qt5_DIR}/Qt5Widgets/")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets REQUIRED)

add_subdirectory(src)

add_library(ddui ${ddui_SOURCES})

target_include_directories(ddui PUBLIC
    include
)

target_link_libraries(ddui
    Qt5::Gui
)
