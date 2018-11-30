list(APPEND ddui_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/app.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/app.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/animation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/MainWindow.cpp
)

add_subdirectory(models)
add_subdirectory(views)
add_subdirectory(util)
set(ddui_SOURCES ${ddui_SOURCES} PARENT_SCOPE)
