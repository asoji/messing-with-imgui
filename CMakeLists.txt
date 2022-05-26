cmake_minimum_required(VERSION 3.16)
project(messing-with-imgui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/fonts/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/fonts/)

#=================== GLFW ===================

set(glfw3_DIR "libs/glfw")
add_subdirectory(${glfw3_DIR})

find_package(OpenGL REQUIRED)

#=================== IMGUI ===================

set(IMGUI_DIR libs/imgui)
add_library(IMGUI STATIC)

target_sources( IMGUI
        PRIVATE
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/imgui.cpp

        PRIVATE
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        )

target_include_directories( IMGUI
        PUBLIC ${IMGUI_DIR}
        PUBLIC ${IMGUI_DIR}/backends
        PUBLIC ${glfw3_DIR}/include
        )

add_executable(${PROJECT_NAME}
        "src/main.cpp"
        "src/main.hpp"
        "src/backend.cpp"
        "src/backend.hpp")

target_link_libraries(${PROJECT_NAME} PRIVATE
        IMGUI
        glfw
        OpenGL::GL
        ${CMAKE_DL_LIBS})
