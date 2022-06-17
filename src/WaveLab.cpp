#include <iostream>

#include "engine/window/Window.h"

#include "engine/renderer/Renderer.h"
#include "engine/renderer/TextureRenderer.h"

#include "ImguiStyles.h"

void dockSpace(bool* p_open);
void mouseFun(double xpos, double ypos);

int main(void) {

    Window window("WaveLab", 1080, 720);
    window.setMouseFun(mouseFun);

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
    
    Camera camera = Camera::perspectiveCamera(glm::radians(45.0f), window.getWidth() / window.getHeight(), 0.1, 1000);
    camera.lookAt(glm::vec3(0, 0, -2.5), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
    renderer.setCamera(camera);
    
    std::vector<Vec3f> vertices = {
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f),
        Vec3f( 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f),

        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f),
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f(-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f),

        Vec3f(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f),
        Vec3f(-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f),
        Vec3f(-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f),

        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f),
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f( 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f( 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f),
        Vec3f( 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f),
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f),

        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f),
        Vec3f( 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f( 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f(-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f),
        Vec3f(-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f),

        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f),
        Vec3f( 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f),
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f( 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f),
        Vec3f(-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f),
        Vec3f(-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f)
    };
    Polytope polytope(vertices);

    Group group(GL_TRIANGLES);
    group.add(polytope);
    
    renderer.addGroup(group);

    TextureRenderer textureRenderer(window.getWidth(), window.getHeight());

    // Main loop
    while (!window.windowShouldClose()) {

        // Clear
        renderer.clear();

        // Draw to texture instead of default
        textureRenderer.updateViewPort(window.getWidth(), window.getHeight());
        textureRenderer.renderToTexture();

        // Render
        renderer.render();

        // Go back to default
        textureRenderer.renderToDefault();	

        // Rotate cube
        static float angle = 0.0f;
        group.rotate(angle, glm::vec3(1, 1, 0));
        angle += 0.01f;

        // ImGUI
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            bool p_open = true;
            dockSpace(&p_open);

            // Window
            {
                static float f = 0.0f;
                static int counter = 0;
                ImGui::Begin("Test window");                         
                ImGui::Text("This is some useful text.");              
                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
                ImGui::Separator();
                if (ImGui::Button("Increase")) counter ++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);
                ImGui::Separator();
                ImGui::TextColored(ImColor(200, 150, 255), "Don't waste time reading this :D");
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
            }
            // Another window
            {
                ImGui::Begin("Just another window");       

                ImGui::TextColored(ImColor(200, 150, 255), "This is just a text");
                ImGui::Text("Equations, equations and more equations...");

                ImGui::BulletText("While inputing text:\n");
                ImGui::Indent();
                ImGui::BulletText("CTRL+Left/Right to word jump.");
                ImGui::Unindent();

                ImGui::Separator();
                if (ImGui::Button("Visible")) group.setVisible(!group.isVisible());
                ImGui::SameLine();
                if (ImGui::Button("Show wire")) group.setShowWire(!group.isShowWire());
                ImGui::Separator();

                ImGui::End();
            }
            // Render window
            { 
                ImGui::Begin("Renderer");       
                ImGui::Image((void*)(intptr_t)textureRenderer.getTexture(), ImGui::GetWindowSize());      
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

void dockSpace(bool* p_open) {

    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        const ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if (!opt_padding) ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace", p_open, window_flags);
    if (!opt_padding) ImGui::PopStyleVar();

    if (opt_fullscreen) ImGui::PopStyleVar(2);

    // Submit the DockSpace
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }

    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Options")) {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
            ImGui::MenuItem("Padding", NULL, &opt_padding);
            ImGui::Separator();

            if (ImGui::MenuItem("Flag: NoSplit",                "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
            if (ImGui::MenuItem("Flag: NoResize",               "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))                { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
            if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
            if (ImGui::MenuItem("Flag: AutoHideTabBar",         "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
            if (ImGui::MenuItem("Flag: PassthruCentralNode",    "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
            ImGui::Separator();

            if (ImGui::MenuItem("Close", NULL, false, p_open != NULL))
                *p_open = false;
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }

    ImGui::End();
}

void mouseFun(double xpos, double ypos) {
   
}