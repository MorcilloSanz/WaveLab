cmake_minimum_required(VERSION 3.12)

project(WaveLab
        VERSION 0.1
        DESCRIPTION "Wave laboratory"
        LANGUAGES CXX)

set(HEADERS 
        glew/glew.h
        imgui/imgui.h
        imgui/backends/imgui_impl_glfw.h
        imgui/backends/imgui_impl_opengl3.h
        imgui/imgui_internal.h
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        src/window/Window.h
)

set(SOURCES
        glew/glew.cpp
        imgui/imgui.cpp
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        src/WaveLab.cpp
        src/window/Window.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} GL dl X11 glfw)