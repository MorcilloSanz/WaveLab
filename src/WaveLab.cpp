#include <iostream>

#define GLEW_STATIC
#include "../glew/glew.h"

#include "window/Window.h"

#include "../imgui/imgui.h"
#include "../imgui/backends/imgui_impl_opengl3.h"
#include "../imgui/backends/imgui_impl_glfw.h"

int main(void) {

    Window window("WaveLab", 600, 600);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

    ImGui::StyleColorsClassic();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    const char* glsl_version = "#version 130";
    ImGui_ImplGlfw_InitForOpenGL(window.getGLFWwindow(), true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Our state
    ImVec4 clear_color = ImVec4(0.3f, 0.3f, 0.3f, 1.00f);

    // Main loop
    while (!window.windowShouldClose()) {

        // Clear
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        // OpenGL rendering

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
            // Window 1
            {
                static float f = 0.0f;
                static int counter = 0;
                ImGui::Begin("Hello, world!");                         
                ImGui::Text("This is some useful text.");              
                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);           
                ImGui::ColorEdit3("clear color", (float*)&clear_color);
                if (ImGui::Button("Button")) counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
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