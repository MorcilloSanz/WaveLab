#include <iostream>

#define GLEW_STATIC
#include "../glew/glew.h"

#include "window/Window.h"

#include "ImguiStyles.h"

#include "opengl/buffer/VertexArray.h"
#include "opengl/buffer/VertexBuffer.h"
#include "opengl/shader/Shader.h"

#include "group/Polytope.h"
#include "group/Group.h"

int main(void) {

    Window window("WaveLab", 600, 600);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

    //ImGui::StyleColorsDark();
    Style();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    const char* glsl_version = "#version 130";
    ImGui_ImplGlfw_InitForOpenGL(window.getGLFWwindow(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    ImVec4 clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.00f);
    bool meshWire = false;



    // Shaders
    Shader vertexShader = Shader::fromFile("../src/opengl/glsl/vertex_shader.glsl", Shader::ShaderType::Vertex);
    Shader fragmentShader = Shader::fromFile("../src/opengl/glsl/fragment_shader.glsl", Shader::ShaderType::Fragment);
    ShaderProgram shaderProgram(vertexShader, fragmentShader);

    // Polytopes
    std::vector<Vec3f> vertices = {
        Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f),
        Vec3f(-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f),
        Vec3f(0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f)
    };
    Polytope polytope(vertices);

    std::vector<Vec3f> vertices2 = {
        Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 2.0f, 1.0f),
        Vec3f(-0.5f, -0.5f, 0.0f,  1.0f, 2.0f, 1.0f),
        Vec3f(0.0f,  0.5f, 0.0f,  0.1f, 2.0f, 1.0f)
    };
    Polytope polytope2(vertices2);

    // Group
    Group group;
    group.add(polytope2);
    group.add(polytope);
    //group.setVisible(false);




    // Enable blending
    glEnable(GL_BLEND | GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Anti aliasing
    glEnable(GL_MULTISAMPLE);

    // Main loop
    while (!window.windowShouldClose()) {

        // Clear
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        // OpenGL rendering
        shaderProgram.useProgram();

        // Draw Polytope 
        //group.draw(GL_TRIANGLES, true);
        if(group.isVisible())
            group.draw(GL_TRIANGLES);
        
        // Update polytope vbo vertices
        static float offset = 0.01f;
        vertices = {
            Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f),
            Vec3f(-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f),
            Vec3f(0.0f + offset,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f)
        };
        polytope.getVertexBuffer()->updateVertices(vertices);
        offset += 0.001;

        // ImGUI
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            // Menu bar
            {
                if (ImGui::BeginMainMenuBar()) {
                    if (ImGui::BeginMenu("Edit")) {
                        if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
                        if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
                        ImGui::Separator();
                        if (ImGui::MenuItem("Cut", "CTRL+X")) {}
                        if (ImGui::MenuItem("Copy", "CTRL+C")) {}
                        if (ImGui::MenuItem("Paste", "CTRL+V")) {}
                        ImGui::EndMenu();
                    }
                    ImGui::EndMainMenuBar();
                }
            }
            // Window
            {
                static float f = 0.0f;
                static int counter = 0;
                ImGui::Begin("Test window");                         
                ImGui::Text("This is some useful text.");              
                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
                ImGui::Checkbox("Mesh wire", &meshWire);            
                ImGui::ColorEdit3("clear color", (float*)&clear_color);
                if (ImGui::Button("Button")) counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            }
            // Render window
            {
                ImGui::Begin("Render");                         
                ImGui::End();
            }
            // Rendering
            ImGui::Render();
            int display_w, display_h;
            glfwGetFramebufferSize(window.getGLFWwindow(), &display_w, &display_h);
            glViewport(0, 0, display_w, display_h);
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            }
        }

        window.update();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    window.terminate();
    return 0;
}