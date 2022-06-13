#include <iostream>

#include "window/Window.h"

#include "ImguiStyles.h"

#include "renderer/Renderer.h"

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

    // Renderer
    Renderer renderer;
    
    // Polytopes
    std::vector<Vec3f> vertices = {
        Vec3f(0.5f,  0.5f, 0.0f , 1.0f, 0.0f, 0.0f),  // top right
        Vec3f( 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f),  // bottom right
        Vec3f(-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f),  // bottom left
        Vec3f(-0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 1.0f)   // top left 
    };
    std::vector<unsigned int> indices = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    Polytope polytope(vertices, indices);

    std::vector<Vec3f> vertices2 = {
        Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.2f, 1.0f),
        Vec3f(-0.5f, -0.5f, 0.0f,  1.0f, 0.2f, 1.0f),
        Vec3f(0.0f,  0.5f, 0.0f,  1.0f, 0.2f, 1.0f)
    };
    Polytope polytope2(vertices2);

    // Group
    Group group(GL_TRIANGLES);
    group.add(polytope);
    group.add(polytope2);
    group.rotate(45, glm::vec3(0, 0, 1));
    
    renderer.addGroup(group);

    // Main loop
    while (!window.windowShouldClose()) {

        // Clear
        renderer.clear();

        // Render
        renderer.render();
        
        // Update polytope vbo vertices
        static float offset = 0.01f;
        vertices = {
            Vec3f(0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f),
            Vec3f(-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f),
            Vec3f(0.0f + offset,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f)
        };
        polytope2.updateVertices(vertices);
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