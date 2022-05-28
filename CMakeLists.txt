cmake_minimum_required(VERSION 3.12)

project(WaveLab
        VERSION 0.1
        DESCRIPTION "Wave laboratory"
        LANGUAGES CXX)

set(HEADERS 
        glew/glew.h
        # ImGui
        imgui/imgui.h
        imgui/backends/imgui_impl_glfw.h
        imgui/backends/imgui_impl_opengl3.h
        imgui/imgui_internal.h
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        # Source
        src/window/Window.h
        src/opengl/buffer/Buffer.h
        src/opengl/buffer/VertexArray.h
        src/opengl/buffer/VertexBuffer.h
        src/opengl/shader/Shader.h
        src/group/Polytope.h
        src/group/Group.h
        src/renderer/Renderer.h
        src/renderer/Camera.h
)

set(SOURCES
        glew/glew.cpp
        # ImGui
        imgui/imgui.cpp
        imgui/backends/imgui_impl_glfw.cpp
        imgui/backends/imgui_impl_opengl3.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        # Source
        src/WaveLab.cpp
        src/window/Window.cpp
        src/opengl/buffer/VertexArray.cpp
        src/opengl/buffer/VertexBuffer.cpp
        src/opengl/shader/Shader.cpp
        src/group/Polytope.cpp
        src/group/Group.cpp
        src/renderer/Renderer.cpp
        src/renderer/Camera.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} GL dl X11 glfw)